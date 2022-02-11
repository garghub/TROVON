static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_2 -> V_2 . V_4 = F_2 ( & V_2 -> V_5 -> V_5 ,
V_6 , & V_3 , V_7 ) ;
if ( ! V_2 -> V_2 . V_4 ) {
F_3 ( V_8 L_1 ) ;
return - V_9 ;
}
V_2 -> V_2 . V_10 . V_11 = V_3 ;
V_2 -> V_2 . V_10 . V_12 = V_6 ;
V_2 -> V_13 = & V_14 ;
if ( F_4 ( V_15 , L_2 ) )
F_3 ( V_8 L_3 ,
V_15 ) ;
else if ( F_5 ( V_15 , 1 ) )
F_3 ( V_8 L_4 ,
V_15 ) ;
if ( F_4 ( V_16 , L_5 ) )
F_3 ( V_8 L_3 ,
V_16 ) ;
else if ( F_5 ( V_16 , 1 ) )
F_3 ( V_8 L_4 ,
V_16 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
return F_7 ( & V_2 -> V_5 -> V_5 , V_18 ,
V_2 -> V_2 . V_4 , V_2 -> V_2 . V_10 . V_11 ,
V_2 -> V_2 . V_10 . V_12 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_9 ( & V_2 -> V_5 -> V_5 , V_2 -> V_2 . V_10 . V_12 ,
V_2 -> V_2 . V_4 , V_2 -> V_2 . V_10 . V_11 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_11 ( V_16 , 0 ) ;
F_11 ( V_15 , 0 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_11 ( V_16 , 1 ) ;
F_11 ( V_15 , 1 ) ;
}
static int F_13 ( const struct V_19 * V_20 )
{
return V_20 -> V_21 ;
}
static void F_14 ( const struct V_19 * V_20 , int V_22 )
{
}
static int F_15 ( struct V_23 * V_5 , struct V_24 * V_25 )
{
if ( V_25 -> V_26 == V_27 )
F_11 ( V_28 , 0 ) ;
else
F_11 ( V_28 , 1 ) ;
return 0 ;
}
static void T_2 F_16 ( void )
{
T_3 V_29 ;
V_29 = F_17 ( V_30 ) &
~ ( V_31 |
V_32 ) ;
V_29 |= V_33 ;
F_18 ( V_29 , V_30 ) ;
F_19 () ;
F_18 ( V_34 |
V_35 ,
V_36 ) ;
F_20 ( NULL , V_37 ,
V_38 , NULL ) ;
}
