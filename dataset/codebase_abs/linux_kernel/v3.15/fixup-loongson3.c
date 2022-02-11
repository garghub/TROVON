static void F_1 ( const struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 , L_1 ,
V_2 -> V_4 , V_2 -> V_5 , V_2 -> V_6 ) ;
}
int T_1 F_3 ( const struct V_1 * V_3 , T_2 V_7 , T_2 V_8 )
{
F_1 ( V_3 ) ;
return V_3 -> V_6 ;
}
static void F_4 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 [ V_10 ] . V_11 )
return;
if ( ! V_12 . V_13 )
return;
V_2 -> V_9 [ V_10 ] . V_11 =
V_12 . V_13 ;
V_2 -> V_9 [ V_10 ] . V_14 =
V_12 . V_13 + 256 * 1024 - 1 ;
V_2 -> V_9 [ V_10 ] . V_15 |= V_16 ;
F_2 ( & V_2 -> V_3 , L_2 ,
V_10 , & V_2 -> V_9 [ V_10 ] ) ;
}
int F_5 ( struct V_1 * V_3 )
{
return 0 ;
}
