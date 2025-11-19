#include "searchdialog.h"
#include "ui_searchdialog.h"

SearchDialog::SearchDialog(QWidget *parent,QPlainTextEdit * textEdit)
    : QDialog(parent)
    , ui(new Ui::SearchDialog)
{
    ui->setupUi(this);

    pTextEdit = textEdit;
}

SearchDialog::~SearchDialog()
{
    delete ui;
}

void SearchDialog::on_btFindNext_clicked()
{
    QString target = ui->searchText->text();

    QString text = pTextEdit->toPlainText();
    QTextCursor c=pTextEdit->textCursor();
    int index = -1;

    index = text.indexOf(target,c.position());
    if(index >=0){
        c.setPosition(index);
        c.setPosition(index +target.length(),QTextCursor::KeepAnchor);

        pTextEdit->setTextCursor(c);
    }


}


void SearchDialog::on_btCancel_clicked()
{
    accept();
}

