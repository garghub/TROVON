static void F_1 ( void )
{
F_2 ( V_1 , 1 ) ;
F_2 ( V_2 , 0 ) ;
F_2 ( V_3 , 0 ) ;
F_2 ( V_4 , 0 ) ;
F_2 ( V_5 , 0 ) ;
F_3 ( 10 ) ;
F_2 ( V_6 , 0 ) ;
F_2 ( V_2 , 0 ) ;
F_3 ( 20 ) ;
F_2 ( V_2 , 1 ) ;
F_3 ( 5 ) ;
F_2 ( V_3 , 1 ) ;
F_3 ( 5 ) ;
F_2 ( V_4 , 1 ) ;
F_3 ( 10 ) ;
F_2 ( V_5 , 1 ) ;
F_3 ( 10 ) ;
F_2 ( V_6 , 1 ) ;
F_3 ( 10 ) ;
F_2 ( V_7 , 1 ) ;
}
static void F_4 ( void )
{
F_2 ( V_6 , 0 ) ;
F_2 ( V_5 , 0 ) ;
F_3 ( 10 ) ;
F_2 ( V_7 , 0 ) ;
F_3 ( 10 ) ;
F_2 ( V_3 , 0 ) ;
F_3 ( 10 ) ;
F_2 ( V_2 , 0 ) ;
}
static void F_5 ( struct V_8 * V_9 )
{
F_4 () ;
}
static void F_6 ( struct V_8 * V_9 )
{
F_1 () ;
}
static void F_7 ( struct V_10 * V_11 , unsigned int V_12 )
{
if ( V_12 )
F_1 () ;
else
F_4 () ;
}
static int F_8 ( struct V_13 * V_14 )
{
return F_9 ( V_15 , L_1 ) ;
}
static int F_10 ( void )
{
return ! F_11 ( V_15 ) ;
}
static void F_12 ( struct V_13 * V_14 )
{
F_13 ( V_15 ) ;
}
static void F_14 ( struct V_16 * V_17 , int V_18 )
{
F_2 ( V_19 , V_18 ) ;
}
static void T_1 F_15 ( void )
{
int V_20 ;
V_21 = V_22 | V_23 ;
F_16 ( F_17 ( V_24 ) ) ;
F_18 ( V_25 , 1 ) ;
V_20 = F_19 ( F_17 ( V_26 ) ) ;
if ( V_20 )
F_20 ( L_2 ) ;
F_21 ( NULL ) ;
F_22 ( NULL ) ;
F_23 ( NULL ) ;
F_24 ( V_27 , F_25 ( V_27 ) ) ;
F_26 ( V_28 , F_25 ( V_28 ) ) ;
F_27 ( & V_29 ) ;
F_28 ( NULL ) ;
F_29 ( NULL ) ;
F_30 ( 0 , F_17 ( V_30 ) ) ;
F_30 ( 1 , F_17 ( V_31 ) ) ;
F_31 ( 2 , & V_32 ) ;
F_32 ( F_17 ( V_33 ) ) ;
F_2 ( V_34 , 0 ) ;
F_3 ( 10 ) ;
F_2 ( V_34 , 1 ) ;
F_3 ( 10 ) ;
}
