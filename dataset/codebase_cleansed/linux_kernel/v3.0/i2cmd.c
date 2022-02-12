static cmdSyntaxPtr
i2cmdBaudDef(int which, unsigned short rate)
{
cmdSyntaxPtr pCM;
switch(which)
{
case 1:
pCM = (cmdSyntaxPtr) ct54;
break;
default:
case 2:
pCM = (cmdSyntaxPtr) ct55;
break;
}
pCM->cmd[1] = (unsigned char) rate;
pCM->cmd[2] = (unsigned char) (rate >> 8);
return pCM;
}
