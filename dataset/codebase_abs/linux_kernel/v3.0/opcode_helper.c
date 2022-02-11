unsigned int F_1 ( unsigned int V_1 )
{
switch ( ( V_1 & 0xf00f ) ) {
case 0x0000 :
case 0x0001 :
case 0x3001 :
return 4 ;
}
switch ( ( V_1 & 0xf08f ) ) {
case 0x3009 :
return 4 ;
}
return 2 ;
}
