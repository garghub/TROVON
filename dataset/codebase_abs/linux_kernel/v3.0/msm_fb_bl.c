static int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 ;
}
static int F_2 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
T_1 V_7 ;
V_7 = V_2 -> V_3 . V_4 ;
V_7 = V_6 -> V_8 -> V_9 [ V_7 ] ;
F_4 ( V_6 , V_7 , 1 ) ;
return 0 ;
}
void F_5 ( struct V_5 * V_6 )
{
struct V_10 * V_11 ;
struct V_1 * V_2 ;
struct V_12 * V_8 ;
char V_13 [ 16 ] ;
V_8 = V_6 -> V_8 ;
V_11 = (struct V_10 * ) V_6 -> V_14 -> V_15 . V_16 ;
if ( ( V_11 ) && ( V_11 -> V_17 ) ) {
snprintf ( V_13 , sizeof( V_13 ) , L_1 , V_6 -> V_18 ) ;
V_2 =
F_6 ( V_13 , V_8 -> V_15 , V_6 ,
& V_19 ) ;
if ( ! F_7 ( V_2 ) ) {
V_8 -> V_20 = V_2 ;
F_8 ( V_8 ,
0 ,
V_6 -> V_21 . V_22 ,
V_6 -> V_21 . V_23 ) ;
V_2 -> V_3 . V_24 = V_25 - 1 ;
V_2 -> V_3 . V_4 = V_25 - 1 ;
F_9 ( V_2 ) ;
} else {
V_8 -> V_20 = NULL ;
F_10 ( V_26 L_2 ) ;
}
}
}
