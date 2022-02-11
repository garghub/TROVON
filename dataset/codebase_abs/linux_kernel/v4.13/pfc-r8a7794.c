static int F_1 ( struct V_1 * V_2 , unsigned int V_3 , T_1 * V_4 )
{
* V_4 = 0xe606006c ;
switch ( V_3 & 0x1f ) {
case 6 : return 23 ;
case 7 : return 16 ;
case 14 : return 15 ;
case 15 : return 8 ;
case 0 ... 5 :
case 8 ... 13 :
return 22 - ( V_3 & 0x1f ) ;
case 16 ... 23 :
return 47 - ( V_3 & 0x1f ) ;
}
return - V_5 ;
}
