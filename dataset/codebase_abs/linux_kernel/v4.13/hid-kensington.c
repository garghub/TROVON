static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_7 * V_8 ,
unsigned long * * V_9 , int * V_10 )
{
if ( ( V_8 -> V_11 & V_12 ) != V_13 )
return 0 ;
switch ( V_8 -> V_11 & V_14 ) {
case 0x01 : F_2 ( V_15 ) ; break;
case 0x02 : F_2 ( V_16 ) ; break;
default:
return 0 ;
}
return 1 ;
}
