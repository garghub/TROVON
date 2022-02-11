static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_4 )
{
return F_2 ( F_3 ( 26 ) , V_3 , V_5 |
V_6 , L_1 , V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 , void * V_4 )
{
F_5 ( F_3 ( 26 ) , V_4 ) ;
}
static void F_6 ( void )
{
F_7 ( V_7 , L_2 ) ;
F_8 ( V_7 , 1 ) ;
}
static int F_9 ( void )
{
F_7 ( V_8 , L_3 ) ;
F_8 ( V_8 , 0 ) ;
F_10 ( 1 ) ;
F_11 ( V_8 , 1 ) ;
return 0 ;
}
static int F_12 ( struct V_9 * V_10 )
{
return F_13 ( V_10 -> V_11 , V_12 ) ;
}
static int T_2 F_14 ( char * V_13 )
{
if ( ! strcmp ( V_13 , L_4 ) )
V_14 = 1 ;
else if ( ! strcmp ( V_13 , L_5 ) )
V_14 = 0 ;
else
F_15 ( L_6
L_7 ) ;
return 0 ;
}
static void T_2 F_16 ( void )
{
F_17 ( V_15 , F_18 ( V_15 ) ,
L_8 ) ;
F_6 () ;
F_19 ( & V_16 ) ;
F_20 ( NULL ) ;
F_21 ( & V_17 ) ;
F_22 ( 0 , & V_18 ) ;
F_23 ( NULL ) ;
F_9 () ;
if ( V_14 ) {
V_19 . V_20 = F_24 ( V_21 |
V_22 ) ;
if ( V_19 . V_20 )
F_25 ( & V_19 ) ;
}
if ( ! V_14 )
F_26 ( & V_23 ) ;
F_27 ( & V_24 ) ;
F_28 ( V_25 ,
F_18 ( V_25 ) ) ;
if ( F_29 ( V_26 , V_27 ) )
F_30 ( L_9 ) ;
F_31 ( 0 , & V_28 ) ;
}
static void T_2 F_32 ( void )
{
F_33 ( 26000000 ) ;
}
