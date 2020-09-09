#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   writeIntoXml();
   readFromXml();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::writeIntoXml()
{
    //Writing Into Xml;

   QFile file("example.xml");

   //opening file in write mode and checking for error
   if(!file.open(QFile::WriteOnly))
   {
       qDebug()<<"example.xml not open in write mode";
   }

   QDomDocument document; //We will create virtual xml document in this QDomDocument.
   QDomElement rootNode=document.createElement("root"); //Creating root node of QDomDocument.
   document.appendChild(rootNode); //Appending root node to QDomDocument.

   QStringList list={"vinay","vijaya","tejas","rahul","ritesh","amit"}; //Name for the tags
   QStringList list1={"one","two","three","four","five","six","seven","eight","nine","ten"};

   for(int i=0; i<list.size(); i++ )
   {
       QDomElement ele= document.createElement(list[i]); //Element tag created

       for(int j=0; j<list1.size(); j++)
       {
           QDomElement ele1=document.createElement(list1[j]); //child of element tag
           ele1.setAttribute("value",i);    //setting attribute for ele1 tag
           ele.appendChild(ele1);   //Appending ele1 as child of ele
       }
       rootNode.appendChild(ele);   //appending ele as child of root (ele1 was already becomes child of ele)
   }
   QTextStream out(&file);  //It will help to write into file.
   out<<document.toString();    //It will convert QDomDocument to string and will write into file.
   file.close();
}

void MainWindow::readFromXml()
{
    //Reading  From XMl;
    QFile file("example.xml");

    if(!file.open(QFile::ReadOnly))
    {
        qDebug()<<"Failed to open file in read mode";
    }

    QDomDocument readingDocument;

    if(!readingDocument.setContent(&file))
    {
        qDebug()<<"Failed to set content of file into readinDocument file";
    }

    file.close();

    QDomElement rootNode=readingDocument.firstChildElement();

    while(!rootNode.isNull())
    {
        qDebug()<<"<"<<rootNode.tagName()<<">";
        QDomElement ele=rootNode.firstChildElement();

        while(!ele.isNull())
        {
            qDebug()<<"<"<<ele.tagName()<<">";
            QDomElement ele1=ele.firstChildElement();

            while(!ele1.isNull())
            {
                qDebug()<<ele1.tagName()<<"<"<<ele1.attribute("value")<<">";
                ele1=ele1.nextSiblingElement();
            }
            ele=ele.nextSiblingElement();
        }
        rootNode=rootNode.nextSiblingElement();
    }

}

