#include <iostream>
#include "../src/duckx.hpp"
using namespace std;
using namespace duckx; 

int main() {
    duckx::Document doc("my_test.docx");
    doc.open();
    Paragraph last = doc.paragraphs();
    while(last.has_next()) last = last.next();

    doc.add_paragraph("You can insert text in ");
    doc.add_run("italic, ", Run::Italic);
    doc.add_run("bold, ", Run::Bold);
    doc.add_run("underline, ", Run::Underline);
    doc.add_run("strikethrough, ", Run::Strikethrough);
    doc.add_run("superscript", Run::Superscript);
    doc.add_run(" or ");
    doc.add_run("subscript, ", Run::Subscript);
    doc.add_run("small caps, ", Run::SmallCaps);
    doc.add_run("and shadows, ", Run::Shadow);
    doc.add_run("and of course ");
    doc.add_run("combine them.", Run::Bold | Run::Italic | duckx::Run::Underline | Run::SmallCaps);
    
    doc.save();

    return 0;
}
