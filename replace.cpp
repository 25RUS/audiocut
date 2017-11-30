QString replace(QString, bool); //замена букв

QString replace(QString str, bool p)
{
    QString str0;
    for(int i=0; i<str.size(); i++)
    {
        if(str[i]=="А")
            str0+='A';
        else if(str[i]=="а")
            str0+='a';
        else if(str[i]=="Б")
            str0+='B';
        else if(str[i]=="б")
            str0+='b';
        else if(str[i]=="В")
            str0+='V';
        else if(str[i]=="в")
            str0+='v';
        else if(str[i]=="Г")
            str0+='G';
        else if(str[i]=="г")
            str0+='g';
        else if(str[i]=="Д")
            str0+='D';
        else if(str[i]=="д")
            str0+='d';
        else if(str[i]=="Е")
            str0+='E';
        else if(str[i]=="е")
            str0+='e';
        else if(str[i]=="Ё")
        {
             str0+='Y';
             str0+='o';
        }
        else if(str[i]=="ё")
        {
             str0+='y';
             str0+='o';
        }
        else if(str[i]=="Ж")
        {
             str0+='Z';
             str0+='h';
        }
        else if(str[i]=="ж")
        {
             str0+='z';
             str0+='h';
        }
        else if(str[i]=="З")
            str0+='Z';
        else if(str[i]=="з")
            str0+='z';
        else if(str[i]=="И")
            str0+='I';
        else if(str[i]=="и")
            str0+='i';
        else if(str[i]=="Й")
            str0+='J';
        else if(str[i]=="й")
            str0+='j';
        else if(str[i]=="К")
            str0+='K';
        else if(str[i]=="к")
            str0+='k';
        else if(str[i]=="Л")
            str0+='L';
        else if(str[i]=="л")
            str0+='l';
        else if(str[i]=="М")
            str0+='M';
        else if(str[i]=="м")
            str0+='m';
        else if(str[i]=="Н")
            str0+='N';
        else if(str[i]=="н")
            str0+='n';
        else if(str[i]=="О")
            str0+='O';
        else if(str[i]=="о")
            str0+='o';
        else if(str[i]=="П")
            str0+='P';
        else if(str[i]=="п")
            str0+='p';
        else if(str[i]=="Р")
            str0+='R';
        else if(str[i]=="р")
            str0+='r';
        else if(str[i]=="С")
            str0+='S';
        else if(str[i]=="с")
            str0+='s';
        else if(str[i]=="Т")
            str0+='T';
        else if(str[i]=="т")
            str0+='t';
        else if(str[i]=="У")
            str0+='U';
        else if(str[i]=="у")
            str0+='u';
        else if(str[i]=="Ф")
            str0+='F';
        else if(str[i]=="ф")
            str0+='f';
        else if(str[i]=="Х")
            str0+='H';
        else if(str[i]=="х")
            str0+='h';
        else if(str[i]=="Ц")
            str0+='C';
        else if(str[i]=="ц")
            str0+='c';
        else if(str[i]=="Ч")
        {
             str0+='C';
             str0+='h';
        }
        else if(str[i]=="ч")
        {
             str0+='c';
             str0+='h';
        }
        else if(str[i]=="Ш")
        {
             str0+='S';
             str0+='h';
        }
        else if(str[i]=="ш")
        {
             str0+='s';
             str0+='h';
        }
        else if(str[i]=="Щ")
        {
             str0+='S';
             str0+='h';
        }
        else if(str[i]=="щ")
        {
             str0+='s';
             str0+='h';
        }
        else if(str[i]=="Ъ")
            /*str0+=""*/;
        else if(str[i]=="ъ")
            /*str0+=""*/;
        else if(str[i]=="Ы")
            str0+='I';
        else if(str[i]=="ы")
            str0+='i';
        else if(str[i]=="Ь")
            /*str0+=""*/;
        else if(str[i]=="ь")
            /*str0+=""*/;
        else if(str[i]=="Э")
            str0+='E';
        else if(str[i]=="э")
            str0+='e';
        else if(str[i]=="Ю")
            str0+='U';
        else if(str[i]=="ю")
            str0+='u';
        else if(str[i]=="Я")
        {
             str0+='Y';
             str0+='a';
        }
        else if(str[i]=="я")
        {
             str0+='y';
             str0+='a';
       }
       else if(str[i]==" ")
        {
            if(p==0)
                str0+=str[i];
            else if(p==1)
                str0+="_";
        }
        else
           str0+=str[i];
    }
    return str0;
}
