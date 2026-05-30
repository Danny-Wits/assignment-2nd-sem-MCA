const http = require('http');
const qs = require('querystring');
const fs = require('fs');

http.createServer((req, res) => {
    if (req.method === 'GET') {
        res.end(fs.readFileSync(__dirname + '/practical8_client.html'));
    } else {
        let body = '';
        req.on('data', d => body += d);
        req.on('end', () => {
            const p = qs.parse(body);
            const sum = +p.m1 + +p.m2 + +p.m3 + +p.m4;
            res.writeHead(200, { 'Content-Type': 'text/html' });
            res.end('<html><body><h2>Result</h2><p>Roll No: ' + p.rno + '</p><p>Name: ' + p.name + '</p><p>Marks: ' + p.m1 + ', ' + p.m2 + ', ' + p.m3 + ', ' + p.m4 + '</p><p><b>Sum: ' + sum + '</b></p><a href="/">Back</a></body></html>');
        });
    }
}).listen(3000, () => console.log('http://localhost:3000'));
