static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 V_7 ;
struct V_8 V_9 ;
F_2 ( V_10 L_1 , F_3 ( V_2 ) ) ;
switch ( V_2 -> V_11 ) {
case V_12 :
V_2 -> V_6 [ 1 ] . V_13 = V_4 -> V_14 [ 0 ] . V_13 + 0x100 ;
V_2 -> V_6 [ 1 ] . V_15 = V_2 -> V_6 [ 1 ] . V_13 + 0x200 - 1 ;
V_2 -> V_6 [ 1 ] . V_16 |= V_17 ;
V_7 . V_13 = V_18 ;
V_7 . V_15 = V_18 + V_19 - 1 ;
V_7 . V_16 = V_20 ;
F_4 ( V_2 -> V_21 , & V_9 , & V_7 ) ;
F_5 ( F_6 ( & V_2 -> V_2 ,
V_7 . V_13 ,
V_9 . V_13 ,
F_7 ( & V_7 ) ,
V_22 ) ) ;
break;
default:
F_2 ( L_2 ) ;
}
}
int F_8 ( const struct V_1 * V_2 , T_1 V_23 , T_1 V_24 )
{
return V_25 ;
}
