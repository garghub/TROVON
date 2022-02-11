static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_2 -> V_2 . V_4 = F_2 ( & V_2 -> V_5 -> V_5 , V_6 , & V_3 ,
V_7 ) ;
if ( ! V_2 -> V_2 . V_4 ) {
F_3 ( V_8 L_1 ) ;
return - V_9 ;
}
V_2 -> V_2 . V_10 . V_11 = V_3 ;
V_2 -> V_2 . V_10 . V_12 = V_6 ;
V_2 -> V_13 = & V_14 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
return F_5 ( & V_2 -> V_5 -> V_5 , V_16 , V_2 -> V_2 . V_4 ,
V_2 -> V_2 . V_10 . V_11 , V_2 -> V_2 . V_10 . V_12 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_5 -> V_5 , V_2 -> V_2 . V_10 . V_12 , V_2 -> V_2 . V_4 ,
V_2 -> V_2 . V_10 . V_11 ) ;
}
static int F_8 ( const struct V_17 * V_18 )
{
return V_18 -> V_19 ;
}
static void F_9 ( const struct V_17 * V_18 , int V_20 )
{
}
static void T_2 F_10 ( void )
{
T_3 V_21 ;
V_21 = F_11 ( V_22 ) &
~ ( V_23 |
V_24 ) ;
V_21 |= V_25 ;
F_12 ( V_21 , V_22 ) ;
F_13 () ;
F_12 ( V_26 |
V_27 ,
V_28 ) ;
F_14 ( NULL , V_29 , NULL ) ;
}
