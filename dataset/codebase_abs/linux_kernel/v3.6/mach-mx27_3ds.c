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
V_15 = true ;
else if ( ! strcmp ( V_14 , L_5 ) )
V_15 = false ;
else
F_15 ( L_6
L_7 ) ;
return 1 ;
}
static int F_16 ( struct V_1 * V_2 , int V_16 )
{
F_17 ( L_8 , V_17 , V_16 ? L_9 : L_10 ) ;
F_11 ( V_18 , V_16 ? 0 : 1 ) ;
if ( ! V_16 )
goto V_19;
F_11 ( V_20 , 0 ) ;
F_18 ( 20 ) ;
F_11 ( V_20 , 1 ) ;
F_18 ( 100 ) ;
V_19:
return 0 ;
}
static void T_2 F_19 ( void )
{
int V_21 ;
F_20 () ;
F_21 ( V_22 , F_22 ( V_22 ) ,
L_11 ) ;
F_6 () ;
F_23 ( & V_23 ) ;
F_24 ( NULL ) ;
F_25 ( & V_24 ) ;
F_26 ( 0 , & V_25 ) ;
F_27 () ;
F_9 () ;
if ( V_15 ) {
V_26 . V_27 = F_28 ( V_28 |
V_29 ) ;
if ( V_26 . V_27 )
F_29 ( & V_26 ) ;
}
if ( ! V_15 )
F_30 ( & V_30 ) ;
F_31 ( & V_31 ) ;
F_32 ( & V_32 ) ;
V_33 [ 0 ] . V_34 = F_3 ( V_35 ) ;
F_33 ( V_33 ,
F_22 ( V_33 ) ) ;
if ( F_34 ( V_36 , F_35 ( 3 , 28 ) ) )
F_36 ( L_12 ) ;
F_37 ( 0 , & V_37 ) ;
F_38 ( V_38 , F_22 ( V_38 ) ) ;
F_39 ( & V_39 ) ;
V_21 = F_40 ( V_40 ,
F_22 ( V_40 ) ) ;
if ( V_21 ) {
F_41 ( L_13 ) ;
V_41 . V_42 = NULL ;
}
F_42 ( & V_43 ) ;
}
static void T_2 F_43 ( void )
{
F_44 ( 26000000 ) ;
}
