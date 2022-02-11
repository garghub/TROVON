static int
F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 , 0x100914 ) ;
switch ( V_3 & 0x00000003 ) {
case 0x00000000 : V_2 -> V_4 . type = V_5 ; break;
case 0x00000001 : V_2 -> V_4 . type = V_6 ; break;
case 0x00000002 : V_2 -> V_4 . type = V_7 ; break;
case 0x00000003 : break;
}
V_2 -> V_4 . V_8 = F_2 ( V_2 , 0x10020c ) & 0xff000000 ;
V_2 -> V_4 . V_9 = ( F_2 ( V_2 , 0x100200 ) & 0x00000003 ) + 1 ;
return F_2 ( V_2 , 0x100320 ) ;
}
static int
F_3 ( struct V_10 * V_11 , struct V_10 * V_12 ,
struct V_13 * V_14 , void * V_15 , T_1 V_8 ,
struct V_10 * * V_16 )
{
struct V_17 * V_18 ;
int V_19 ;
V_19 = F_4 ( V_11 , V_12 , V_14 , & V_18 ) ;
* V_16 = F_5 ( V_18 ) ;
if ( V_19 )
return V_19 ;
V_18 -> V_20 . V_21 = V_22 ;
V_18 -> V_20 . V_4 . V_23 = F_1 ;
V_18 -> V_20 . V_24 . V_25 = 15 ;
V_18 -> V_20 . V_24 . V_23 = V_26 ;
V_18 -> V_20 . V_24 . V_27 = V_28 ;
V_18 -> V_20 . V_24 . V_29 = V_30 ;
V_18 -> V_20 . V_24 . V_31 = V_32 ;
return F_6 ( & V_18 -> V_20 ) ;
}
