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
static void F_14 ( void )
{
int V_24 ;
const struct V_25 V_26 [] = {
{ V_27 , V_22 ,
L_5 } ,
{ V_28 . V_29 , V_30 ,
L_6 } ,
{ V_28 . V_31 , V_22 ,
L_7 } ,
} ;
V_24 = F_5 ( V_26 , F_6 ( V_26 ) ) ;
if ( V_24 )
F_7 ( L_8 , V_24 ) ;
}
static int F_15 ( struct V_32 * V_33 )
{
F_2 ( V_34 , 0 ) ;
F_2 ( V_27 , 1 ) ;
return 0 ;
}
static void F_16 ( struct V_32 * V_33 )
{
F_2 ( V_27 , 0 ) ;
F_2 ( V_34 , 1 ) ;
}
static void T_1 F_17 ( void )
{
int V_24 ;
V_24 = F_13 ( V_34 , V_35 ,
L_9 ) ;
if ( V_24 )
F_7 ( L_10 , V_23 ) ;
F_14 () ;
F_18 ( & V_36 ) ;
if ( F_19 () || F_20 () > V_37 )
F_21 ( V_38 ) ;
else
F_21 ( 0 ) ;
F_22 ( V_39 , V_40 ) ;
F_22 ( V_41 , V_40 ) ;
F_22 ( V_42 , V_43 ) ;
}
static void T_1 F_23 ( void )
{
F_22 ( V_44 , V_45 |
V_46 ) ;
F_22 ( V_47 , V_40 ) ;
F_24 ( L_11 ,
V_48 | V_49 ) ;
F_24 ( L_12 ,
V_48 | V_49 ) ;
F_24 ( L_13 ,
V_48 | V_49 ) ;
F_24 ( L_14 ,
V_48 | V_49 ) ;
F_24 ( L_15 ,
V_48 | V_49 ) ;
F_24 ( L_16 ,
V_48 | V_49 ) ;
}
static void T_1 F_25 ( void )
{
int V_50 ;
F_23 () ;
V_51 . V_52 = F_26 ( V_44 ) ;
V_50 = F_27 ( & V_51 ) ;
if ( V_50 )
F_7 ( L_17 , V_50 ) ;
V_50 = F_28 ( & V_53 ) ;
if ( V_50 )
F_7 ( L_18 , V_50 ) ;
}
static void T_1 F_29 ( void )
{
int V_4 ;
int V_54 = V_55 ;
if ( F_20 () == V_56 )
V_54 = V_57 ;
F_30 ( V_58 , NULL , V_54 ) ;
F_8 () ;
F_12 () ;
F_31 ( V_59 , F_6 ( V_59 ) ) ;
F_32 () ;
F_33 ( NULL , NULL ) ;
F_25 () ;
F_34 ( V_60 ) ;
F_35 ( & V_61 ) ;
V_4 = F_4 () ;
if ( V_4 ) {
F_7 ( L_19 , V_4 ) ;
} else {
V_62 [ 0 ] . V_52 = F_26 ( V_63 ) ;
F_36 ( V_62 ,
F_6 ( V_62 ) ) ;
}
V_4 = F_37 ( & V_64 , & V_65 ) ;
if ( V_4 )
F_7 ( L_20 , V_4 ) ;
F_17 () ;
}
