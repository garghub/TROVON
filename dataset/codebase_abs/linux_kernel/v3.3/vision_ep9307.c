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
static int F_16 ( struct V_19 * V_3 ,
T_2 (* F_17)( int , void * ) , void * V_20 )
{
int V_4 ;
V_4 = F_18 ( V_21 ,
F_4 ( V_21 ) ) ;
if ( V_4 )
return V_4 ;
V_4 = F_19 ( V_22 , 1 ) ;
if ( V_4 )
goto V_23;
V_4 = F_20 ( F_21 ( V_22 ) , F_17 ,
V_24 , L_1 , V_20 ) ;
if ( V_4 )
goto V_23;
return 0 ;
V_23:
F_22 ( V_21 , F_4 ( V_21 ) ) ;
return V_4 ;
}
static void F_23 ( struct V_19 * V_3 , void * V_20 )
{
F_24 ( F_21 ( V_22 ) , V_20 ) ;
F_22 ( V_21 , F_4 ( V_21 ) ) ;
}
static int F_25 ( struct V_19 * V_3 )
{
return ! ! F_26 ( V_25 ) ;
}
static int F_27 ( struct V_19 * V_3 )
{
return ! F_26 ( V_22 ) ;
}
static int F_28 ( struct V_14 * V_15 )
{
return F_6 ( V_26 , V_6 ,
V_15 -> V_17 ) ;
}
static void F_29 ( struct V_14 * V_15 )
{
F_10 ( V_26 ) ;
}
static void F_30 ( struct V_14 * V_15 , int V_18 )
{
F_12 ( V_26 , V_18 ) ;
}
static void T_1 F_31 ( void )
{
F_32 () ;
F_33 ( 2 , V_27 , V_28 ) ;
F_34 ( & V_29 , 1 ) ;
F_35 ( & V_30 ) ;
F_36 ( 1 , 0 ) ;
if ( F_6 ( F_37 ( 7 ) , V_31 ,
L_2 ) )
F_38 ( L_3 ) ;
V_32 [ 1 ] . V_33 = F_21 ( F_37 ( 7 ) ) ;
F_39 ( & V_34 , V_32 ,
F_4 ( V_32 ) ) ;
F_40 ( & V_35 , V_36 ,
F_4 ( V_36 ) ) ;
}
