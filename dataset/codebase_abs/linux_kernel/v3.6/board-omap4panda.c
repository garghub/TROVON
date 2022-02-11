static void T_1 F_1 ( void )
{
int V_1 ;
struct V_2 * V_3 ;
V_3 = F_2 ( NULL , L_1 ) ;
if ( F_3 ( V_3 ) ) {
F_4 ( L_2 ) ;
return;
}
F_5 ( V_3 , 19200000 ) ;
F_6 ( V_3 ) ;
V_1 = F_7 ( V_4 ,
F_8 ( V_4 ) ) ;
if ( V_1 ) {
F_4 ( L_3 ) ;
return;
}
F_9 ( V_5 , 0 ) ;
F_9 ( V_6 , 0 ) ;
F_10 ( V_6 , 1 ) ;
F_11 ( & V_7 ) ;
F_10 ( V_5 , 1 ) ;
}
static int T_1 F_12 ( void )
{
F_13 ( & V_8 , V_9 ,
V_10 |
V_11 |
V_12 |
V_13 |
V_14 |
V_15 |
V_16 |
V_17 |
V_18 |
V_19 |
V_20 ) ;
F_14 ( L_4 , & V_8 ,
& V_21 , V_22 ) ;
F_15 ( 2 , 400 , NULL , 0 ) ;
F_15 ( 3 , 100 , V_23 ,
F_8 ( V_23 ) ) ;
F_15 ( 4 , 400 , NULL , 0 ) ;
return 0 ;
}
static int F_16 ( struct V_24 * V_25 )
{
int V_26 ;
V_26 = F_7 ( V_27 ,
F_8 ( V_27 ) ) ;
if ( V_26 )
F_4 ( L_5 ) ;
return V_26 ;
}
static void F_17 ( struct V_24 * V_25 )
{
F_18 ( V_27 , F_8 ( V_27 ) ) ;
}
static void T_1 F_19 ( void )
{
F_20 ( & V_28 ) ;
if ( F_21 () || F_22 () > V_29 )
F_23 ( V_30 ) ;
else
F_23 ( 0 ) ;
F_24 ( V_31 , V_32 ) ;
F_24 ( V_33 , V_32 ) ;
F_24 ( V_34 , V_35 ) ;
}
static void F_25 ( void )
{
if ( F_26 () ) {
V_36 . V_37 = L_6 ;
V_36 . V_38 = 1 ;
} else {
V_36 . V_37 = L_7 ;
}
}
static void T_1 F_27 ( void )
{
int V_39 = V_40 ;
int V_1 ;
if ( F_22 () == V_41 )
V_39 = V_42 ;
F_28 ( V_43 , NULL , V_39 ) ;
V_44 . V_45 = F_29 ( V_46 ) ;
V_1 = F_30 ( & V_44 ) ;
if ( V_1 )
F_4 ( L_8 , V_1 ) ;
F_25 () ;
F_12 () ;
F_31 ( V_47 , F_8 ( V_47 ) ) ;
F_32 ( & V_48 ) ;
F_33 () ;
F_34 ( NULL , NULL ) ;
F_35 ( V_49 ) ;
F_1 () ;
F_36 ( & V_50 ) ;
F_19 () ;
}
