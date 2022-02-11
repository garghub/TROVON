static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) . V_3 = V_4 ;
F_2 ( V_2 ) . V_5 = V_6 ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
if ( F_5 ( V_2 ) -> V_7 )
F_6 ( F_7 ( V_2 ) , V_8 ,
V_9 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) . V_10 = F_9 ( V_11 ) ;
F_2 ( V_2 ) . V_12 =
F_10 ( F_2 ( V_2 ) . V_13 ) ;
if ( F_5 ( V_2 ) -> V_14 )
F_2 ( V_2 ) . V_15 = 1 ;
else
F_2 ( V_2 ) . V_15 =
F_10 ( F_2 ( V_2 ) . V_16 ) ;
F_1 ( V_2 ) ;
F_2 ( V_2 ) . V_17 = & V_18 ;
}
