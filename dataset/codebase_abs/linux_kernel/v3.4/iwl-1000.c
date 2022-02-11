static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) . V_3 = V_4 ;
F_2 ( V_2 ) . V_5 = V_6 ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( F_5 ( V_2 ) , V_7 ,
V_8 |
V_9 ) ;
F_6 ( F_5 ( V_2 ) , V_10 ,
V_11 ,
~ V_12 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) . V_13 = F_8 ( V_14 ) ;
F_2 ( V_2 ) . V_15 =
F_9 ( F_2 ( V_2 ) . V_16 ) ;
if ( F_10 ( V_2 ) -> V_17 )
F_2 ( V_2 ) . V_18 = 1 ;
else
F_2 ( V_2 ) . V_18 =
F_9 ( F_2 ( V_2 ) . V_19 ) ;
F_1 ( V_2 ) ;
F_2 ( V_2 ) . V_20 = & V_21 ;
}
