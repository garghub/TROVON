static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , 1 ) ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_2 ( V_3 , 0 ) ;
}
static int T_1 F_4 ( void )
{
int V_4 ;
V_4 = F_5 ( V_5 ,
F_6 ( V_5 ) ) ;
if ( V_4 )
F_7 ( L_1 ) ;
return V_4 ;
}
static int T_1 F_8 ( void )
{
F_9 ( & V_6 , V_7 ,
V_8 |
V_9 |
V_10 |
V_11 |
V_12 |
V_13 |
V_14 |
V_15 |
V_16 |
V_17 |
V_18 ) ;
F_10 ( L_2 , & V_6 , V_19 ,
F_6 ( V_19 ) ) ;
F_11 ( 2 , 400 , NULL , 0 ) ;
F_11 ( 3 , 400 , V_20 ,
F_6 ( V_20 ) ) ;
F_11 ( 4 , 400 , V_21 ,
F_6 ( V_21 ) ) ;
return 0 ;
}
static void T_1 F_12 ( void )
{
int error ;
error = F_13 ( V_3 ,
V_22 , L_3 ) ;
if ( error < 0 )
F_7 ( L_4 ,
V_23 , V_3 , error ) ;
}
static void T_1 F_14 ( void )
{
F_15 ( V_24 , V_25 |
V_26 ) ;
F_15 ( V_27 , V_28 ) ;
F_16 ( L_5 ,
V_29 | V_30 ) ;
F_16 ( L_6 ,
V_29 | V_30 ) ;
F_16 ( L_7 ,
V_29 | V_30 ) ;
F_16 ( L_8 ,
V_29 | V_30 ) ;
F_16 ( L_9 ,
V_29 | V_30 ) ;
F_16 ( L_10 ,
V_29 | V_30 ) ;
}
static void T_1 F_17 ( void )
{
int V_31 ;
F_14 () ;
V_32 . V_33 = F_18 ( V_24 ) ;
V_31 = F_19 ( & V_32 ) ;
if ( V_31 )
F_7 ( L_11 , V_31 ) ;
V_31 = F_20 ( & V_34 ) ;
if ( V_31 )
F_7 ( L_12 , V_31 ) ;
}
static void T_1 F_21 ( void )
{
int V_4 ;
int V_35 = V_36 ;
if ( F_22 () == V_37 )
V_35 = V_38 ;
F_23 ( V_39 , NULL , V_35 ) ;
F_8 () ;
F_12 () ;
F_24 ( V_40 , F_6 ( V_40 ) ) ;
F_25 () ;
F_26 ( NULL , NULL ) ;
F_17 () ;
F_27 ( V_41 ) ;
F_28 ( & V_42 ) ;
V_4 = F_4 () ;
if ( V_4 ) {
F_7 ( L_13 , V_4 ) ;
} else {
V_43 [ 0 ] . V_33 = F_18 ( V_44 ) ;
F_29 ( V_43 ,
F_6 ( V_43 ) ) ;
}
V_4 = F_30 ( & V_45 , & V_46 ) ;
if ( V_4 )
F_7 ( L_14 , V_4 ) ;
F_31 () ;
}
