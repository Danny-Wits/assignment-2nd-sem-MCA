// Main JavaScript file for the MCA Department website
// Using vanilla JS and Supabase REST API

(function () {
  "use strict";

  // Supabase setup
  var SUPABASE_URL = "https://tabzzytdehkcwpcnjefl.supabase.co";
  var SUPABASE_KEY =
    "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6InRhYnp6eXRkZWhrY3dwY25qZWZsIiwicm9sZSI6ImFub24iLCJpYXQiOjE3NzY3ODY0MDcsImV4cCI6MjA5MjM2MjQwN30.-aQ_PprETXNWMBC07l6tNqdAvd4aNHQjxTzf7_CCw5M";

  // Helper functions

  function headers(extra) {
    var h = {
      apikey: SUPABASE_KEY,
      Authorization: "Bearer " + SUPABASE_KEY,
      "Content-Type": "application/json",
    };
    if (extra) {
      for (var k in extra) h[k] = extra[k];
    }
    return h;
  }

  function show_toast(message, type) {
    var toast = document.getElementById("toast");
    if (!toast) return;
    toast.innerHTML = message;
    toast.className = "toast_box px-4 py-2 rounded text-white fw-semibold";
    if (type === "error") toast.style.background = "#dc3545";
    if (type === "success") toast.style.background = "#198754";
    toast.classList.add("toast_box--visible");
    clearTimeout(toast._timer);
    toast._timer = setTimeout(function () {
      toast.classList.remove("toast_box--visible");
    }, 3200);
  }

  function escape_html(str) {
    var div = document.createElement("div");
    div.appendChild(document.createTextNode(str));
    return div.innerHTML;
  }

  // Handle registration form on registration.html
  var form = document.getElementById("registration_form");
  if (form) {
    form.addEventListener("submit", async function (e) {
      e.preventDefault();

      var name_val = document.getElementById("student_name").value.trim();
      var email_val = document.getElementById("email").value.trim();
      var phone_val = document.getElementById("phone").value.trim();
      var degree_val = document.getElementById("previous_degree").value;

      if (!name_val || !email_val || !phone_val || !degree_val) {
        show_toast("Please fill in all fields.", "error");
        return;
      }

      var btn = document.getElementById("submit_btn");
      btn.disabled = true;
      btn.innerHTML = '<i class="ph ph-circle-notch"></i> Submitting...';

      var payload = {
        student_name: name_val,
        email: email_val,
        phone: phone_val,
        previous_degree: degree_val,
      };

      try {
        const res = await fetch(SUPABASE_URL + "/rest/v1/students", {
          method: "POST",
          headers: headers({ Prefer: "return=minimal" }),
          body: JSON.stringify(payload),
        });

        if (!res.ok) {
          const err = await res.json();
          throw new Error(err.message || "Registration failed.");
        }

        show_toast("Registration successful!", "success");
        form.reset();
      } catch (err) {
        show_toast(err.message || "Something went wrong.", "error");
      } finally {
        btn.disabled = false;
        btn.innerHTML =
          '<i class="ph ph-paper-plane-tilt"></i> Submit Application';
      }
    });
  }

  // Handling the student list display on students.html
  var student_list = document.getElementById("student_list");
  var loading = document.getElementById("loading_indicator");

  if (student_list) {
    (async function () {
      try {
        const res = await fetch(
          SUPABASE_URL +
            "/rest/v1/students?select=student_name,previous_degree&order=created_at.desc",
          {
            method: "GET",
            headers: headers(),
          },
        );

        if (!res.ok) throw new Error("Failed to fetch students.");

        const data = await res.json();

        if (loading) loading.style.display = "none";

        if (!data || data.length === 0) {
          student_list.innerHTML =
            '<div class="text-center text-muted py-5">' +
            '<i class="ph ph-user-list" style="font-size:2.5rem;"></i>' +
            '<p class="mt-2">No students registered yet.</p>' +
            "</div>";
          return;
        }

        var html = '<div class="list-group">';
        for (var i = 0; i < data.length; i++) {
          var s = data[i];
          var initials = s.student_name
            .split(" ")
            .map(function (w) {
              return w.charAt(0).toUpperCase();
            })
            .slice(0, 2)
            .join("");

          html +=
            '<div class="list-group-item d-flex align-items-center gap-3">' +
            '<span class="student_avatar rounded">' +
            initials +
            "</span>" +
            "<div>" +
            '<div class="fw-semibold">' +
            escape_html(s.student_name) +
            "</div>" +
            '<small class="text-muted">' +
            escape_html(s.previous_degree) +
            "</small>" +
            "</div>" +
            "</div>";
        }
        html += "</div>";
        student_list.innerHTML = html;
      } catch (err) {
        if (loading) loading.style.display = "none";
        student_list.innerHTML =
          '<div class="alert alert-danger text-center">' +
          '<i class="ph ph-warning-circle"></i> ' +
          escape_html(err.message) +
          "</div>";
      }
    })();
  }
})();
