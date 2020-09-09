# Writing-into-XML-and-Reading-from-XMl-in-c-using-Qt
#In this repository you will find my code I used to read and write into xml file using c++ Qt framework
First of all you need to add xml in your pro file of Qt, So that you can allow your project to access QDomDocument (this module is used to perform various operatoins with xml file in Qt).

Do this using
```QT       += core gui xml```

Now just include the needed headers into your header files, which are
``` 
#include "QtXml/QDomDocument"
#include "QFile"
#include "QTextStream"
#include "QDebug"

```
I have created two sepearate functions for writing and then reading from the same file which we have created using write code.
You can see the code into the files I have provided in this repository.

After calling the write function of xml, You can see that the file ```example.xml ``` is created into your build folder.0

I have created a root node with having one child node and this child node also have one child node which also have one attribute named "Value".

Don't worry if the above sentence didn't make any sense to you, I will elaborate that for you
The created xml file will have one root tag, names as "root", between the opening and ending tag of this "root" tag you can see various elements.
this root node contains five child tags or you can say five child nodes, which are 
``` {"vinay","vijaya","tejas","rahul","ritesh","amit"} ```

You can see each of this tag have ten child tag as well which are
``` {"one","two","three","four","five","six","seven","eight","nine","ten"} ```
Each of this tag has one attribute which is "value".

The main important files of this code has been available in this repository, If you want mode broaded explaination what I have created you can go to my youtube channel to see my video where I have explained them very well.

My youtube channel is: Vinay k shukla.
