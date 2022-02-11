static int
F_1 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_4 * V_5 , void * V_6 , T_1 V_7 ,
struct V_1 * * V_8 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_11 * V_12 ;
T_1 V_13 = F_2 ( V_10 , 0x001218 ) ;
int V_14 ;
V_14 = F_3 ( V_2 , V_3 , V_5 , & V_12 ) ;
* V_8 = F_4 ( V_12 ) ;
if ( V_14 )
return V_14 ;
switch ( V_13 & 0x00000300 ) {
case 0x00000000 : V_12 -> type = V_15 ; break;
case 0x00000100 : V_12 -> type = V_16 ; break;
case 0x00000200 : V_12 -> type = V_17 ; break;
case 0x00000300 : V_12 -> type = V_18 ; break;
}
V_12 -> V_7 = F_2 ( V_10 , 0x10020c ) & 0xff000000 ;
V_12 -> V_19 = ( F_2 ( V_10 , 0x100200 ) & 0x00000003 ) + 1 ;
V_12 -> V_20 = F_2 ( V_10 , 0x100320 ) ;
return 0 ;
}
