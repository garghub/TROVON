static int F_1 ( unsigned int V_1 ,
unsigned int V_2 )
{
switch ( V_2 ) {
case 120 ... 127 :
return 0 ;
case 128 ... 132 :
case 134 ... 135 :
return 14 ;
default:
return 15 ;
}
}
static int F_2 ( struct V_3 * V_4 )
{
return F_3 ( V_4 , & V_5 ) ;
}
