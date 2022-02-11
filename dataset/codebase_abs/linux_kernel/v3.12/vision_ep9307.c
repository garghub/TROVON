static void T_1 F_1 ( void )
{
F_2 () ;
F_3 ( V_1 , F_4 ( V_1 ) ) ;
}
static int F_5 ( struct V_2 * V_3 )
{
int V_4 ;
V_4 = F_6 ( V_5 , V_6 ,
F_7 ( & V_3 -> V_7 ) ) ;
if ( V_4 )
return V_4 ;
F_8 ( V_8 |
V_9 |
V_10 ) ;
return 0 ;
}
static void F_9 ( struct V_2 * V_3 )
{
F_10 ( V_5 ) ;
}
static void F_11 ( int V_11 , struct V_12 * V_13 )
{
if ( V_11 )
F_12 ( V_5 , 0 ) ;
else
F_12 ( V_5 , 1 ) ;
}
static int F_13 ( struct V_14 * V_15 )
{
return F_6 ( V_16 , V_6 ,
V_15 -> V_17 ) ;
}
static void F_14 ( struct V_14 * V_15 )
{
F_10 ( V_16 ) ;
}
static void F_15 ( struct V_14 * V_15 , int V_18 )
{
F_12 ( V_16 , V_18 ) ;
}
static int F_16 ( struct V_14 * V_15 )
{
return F_6 ( V_19 , V_6 ,
V_15 -> V_17 ) ;
}
static void F_17 ( struct V_14 * V_15 )
{
F_10 ( V_19 ) ;
}
static void F_18 ( struct V_14 * V_15 , int V_18 )
{
F_12 ( V_19 , V_18 ) ;
}
static void T_1 F_19 ( void )
{
F_20 () ;
F_21 ( 2 , V_20 , V_21 ) ;
F_22 ( & V_22 , 1 ) ;
F_23 ( & V_23 ) ;
F_24 ( 1 , 0 ) ;
if ( F_6 ( F_25 ( 7 ) , V_24 ,
L_1 ) )
F_26 ( L_2 ) ;
V_25 [ 1 ] . V_26 = F_27 ( F_25 ( 7 ) ) ;
F_28 ( & V_27 , V_25 ,
F_4 ( V_25 ) ) ;
F_29 ( & V_28 , V_29 ,
F_4 ( V_29 ) ) ;
}
