int
F_1 ( struct V_1 * V_2 , struct V_3 * * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 . V_6 ;
T_1 V_8 = F_2 ( V_6 , 0x001218 ) ;
T_1 V_9 = ( F_2 ( V_6 , 0x10020c ) & 0xff000000 ) ;
T_1 V_10 = F_2 ( V_6 , 0x100320 ) ;
enum V_11 type = V_12 ;
int V_13 ;
switch ( V_8 & 0x00000300 ) {
case 0x00000000 : type = V_14 ; break;
case 0x00000100 : type = V_15 ; break;
case 0x00000200 : type = V_16 ; break;
case 0x00000300 : type = V_17 ; break;
}
V_13 = F_3 ( & V_18 , V_2 , type , V_9 , V_10 , V_4 ) ;
if ( V_13 )
return V_13 ;
( * V_4 ) -> V_19 = ( F_2 ( V_6 , 0x100200 ) & 0x00000003 ) + 1 ;
return 0 ;
}
