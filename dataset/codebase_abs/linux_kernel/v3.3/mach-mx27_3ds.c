static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_4 )
{
return F_2 ( F_3 ( V_5 ) , V_3 ,
V_6 | V_7 , L_1 , V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 , void * V_4 )
{
F_5 ( F_3 ( V_5 ) , V_4 ) ;
}
static void F_6 ( void )
{
F_7 ( V_8 , L_2 ) ;
F_8 ( V_8 , 1 ) ;
}
static int F_9 ( void )
{
F_7 ( V_9 , L_3 ) ;
F_8 ( V_9 , 0 ) ;
F_10 ( 1 ) ;
F_11 ( V_9 , 1 ) ;
return 0 ;
}
static int F_12 ( struct V_10 * V_11 )
{
return F_13 ( V_11 -> V_12 , V_13 ) ;
}
static int T_2 F_14 ( char * V_14 )
{
if ( ! strcmp ( V_14 , L_4 ) )
V_15 = 1 ;
else if ( ! strcmp ( V_14 , L_5 ) )
V_15 = 0 ;
else
F_15 ( L_6
L_7 ) ;
return 0 ;
}
static void T_2 F_16 ( void )
{
F_17 () ;
F_18 ( V_16 , F_19 ( V_16 ) ,
L_8 ) ;
F_6 () ;
F_20 ( & V_17 ) ;
F_21 ( NULL ) ;
F_22 ( & V_18 ) ;
F_23 ( 0 , & V_19 ) ;
F_24 ( NULL ) ;
F_9 () ;
if ( V_15 ) {
V_20 . V_21 = F_25 ( V_22 |
V_23 ) ;
if ( V_20 . V_21 )
F_26 ( & V_20 ) ;
}
if ( ! V_15 )
F_27 ( & V_24 ) ;
F_28 ( & V_25 ) ;
F_29 ( & V_26 ) ;
F_30 ( V_27 ,
F_19 ( V_27 ) ) ;
if ( F_31 ( V_28 , V_29 ) )
F_32 ( L_9 ) ;
F_33 ( 0 , & V_30 ) ;
F_34 ( & V_31 ) ;
}
static void T_2 F_35 ( void )
{
F_36 ( 26000000 ) ;
}
