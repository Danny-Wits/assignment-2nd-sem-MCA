const fs = require('fs');
const path = require('path');
const PizZip = require('pizzip');
const { DOMParser } = require('@xmldom/xmldom');

function inspectDocx(filePath) {
    console.log('=== Inspecting file:', filePath, '===');
    try {
        const content = fs.readFileSync(filePath);
        const zip = new PizZip(content);
        const docXmlStr = zip.files['word/document.xml'].asText();
        const parser = new DOMParser();
        const doc = parser.parseFromString(docXmlStr, 'application/xml');
        
        // Let's print out the first few paragraphs or look for headings / text
        const paragraphs = doc.getElementsByTagName('w:p');
        console.log('Total paragraphs:', paragraphs.length);
        
        let count = 0;
        for (let i = 0; i < paragraphs.length; i++) {
            const p = paragraphs[i];
            const text = getParagraphText(p);
            if (text.trim().length > 0) {
                // If it looks like a heading or index entry
                if (text.toLowerCase().includes('practical') || text.toLowerCase().includes('index') || text.toLowerCase().includes('program') || text.toLowerCase().includes('write a') || count < 50) {
                    console.log(`[P ${i}]:`, text);
                    count++;
                }
            }
        }
    } catch (err) {
        console.error('Error inspecting:', err.message);
    }
}

function getParagraphText(p) {
    const rElements = p.getElementsByTagName('w:t');
    let text = '';
    for (let i = 0; i < rElements.length; i++) {
        text += rElements[i].textContent || '';
    }
    return text;
}

const dir = 'c:\\Users\\danny\\OneDrive\\Desktop\\MCA\\assignment-2nd-sem-MCA';
inspectDocx(path.join(dir, 'MCA PRACTICAL FILE(DS+JS).docx'));
inspectDocx(path.join(dir, 'MCA PRACTICAL FILE.docx'));
