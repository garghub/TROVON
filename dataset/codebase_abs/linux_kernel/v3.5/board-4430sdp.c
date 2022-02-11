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
F_10 ( L_2 , & V_6 ,
& V_19 , V_20 ) ;
F_11 ( 2 , 400 , NULL , 0 ) ;
F_11 ( 3 , 400 , V_21 ,
F_6 ( V_21 ) ) ;
F_11 ( 4 , 400 , V_22 ,
F_6 ( V_22 ) ) ;
return 0 ;
}
static void T_1 F_12 ( void )
{
int error ;
error = F_13 ( V_3 ,
V_23 , L_3 ) ;
if ( error < 0 )
F_7 ( L_4 ,
V_24 , V_3 , error ) ;
}
static int F_14 ( struct V_25 * V_26 )
{
int V_4 ;
V_4 = F_5 ( V_27 ,
F_6 ( V_27 ) ) ;
if ( V_4 )
F_7 ( L_5 , V_24 ) ;
return V_4 ;
}
static void F_15 ( struct V_25 * V_26 )
{
F_16 ( V_27 , F_6 ( V_27 ) ) ;
}
static void F_17 ( void )
{
int V_28 ;
const struct V_29 V_30 [] = {
{ V_31 , V_23 ,
L_6 } ,
{ V_32 . V_33 , V_34 ,
L_7 } ,
{ V_32 . V_35 , V_23 ,
L_8 } ,
} ;
V_28 = F_5 ( V_30 , F_6 ( V_30 ) ) ;
if ( V_28 )
F_7 ( L_9 , V_28 ) ;
}
static int F_18 ( struct V_25 * V_26 )
{
F_2 ( V_36 , 0 ) ;
F_2 ( V_31 , 1 ) ;
return 0 ;
}
static void F_19 ( struct V_25 * V_26 )
{
F_2 ( V_31 , 0 ) ;
F_2 ( V_36 , 1 ) ;
}
static void T_1 F_20 ( void )
{
int V_28 ;
V_28 = F_13 ( V_36 , V_37 ,
L_10 ) ;
if ( V_28 )
F_7 ( L_11 , V_24 ) ;
F_17 () ;
F_21 ( & V_38 ) ;
if ( F_22 () || F_23 () > V_39 )
F_24 ( V_40 ) ;
else
F_24 ( 0 ) ;
F_25 ( V_41 , V_42 ) ;
F_25 ( V_43 , V_42 ) ;
F_25 ( V_44 , V_45 ) ;
}
static void T_1 F_26 ( void )
{
F_25 ( V_46 , V_47 |
V_48 ) ;
F_25 ( V_49 , V_42 ) ;
F_27 ( L_12 ,
V_50 | V_51 ) ;
F_27 ( L_13 ,
V_50 | V_51 ) ;
F_27 ( L_14 ,
V_50 | V_51 ) ;
F_27 ( L_15 ,
V_50 | V_51 ) ;
F_27 ( L_16 ,
V_50 | V_51 ) ;
F_27 ( L_17 ,
V_50 | V_51 ) ;
}
static void T_1 F_28 ( void )
{
int V_52 ;
F_26 () ;
V_53 . V_54 = F_29 ( V_46 ) ;
V_52 = F_30 ( & V_53 ) ;
if ( V_52 )
F_7 ( L_18 , V_52 ) ;
V_52 = F_31 ( & V_55 ) ;
if ( V_52 )
F_7 ( L_19 , V_52 ) ;
}
static void T_1 F_32 ( void )
{
int V_4 ;
int V_56 = V_57 ;
if ( F_23 () == V_58 )
V_56 = V_59 ;
F_33 ( V_60 , NULL , V_56 ) ;
F_8 () ;
F_12 () ;
F_34 ( V_61 , F_6 ( V_61 ) ) ;
F_35 () ;
F_36 ( NULL , NULL ) ;
F_28 () ;
F_37 ( V_62 ) ;
F_38 ( & V_63 ) ;
V_4 = F_4 () ;
if ( V_4 ) {
F_7 ( L_20 , V_4 ) ;
} else {
V_64 [ 0 ] . V_54 = F_29 ( V_65 ) ;
F_39 ( V_64 ,
F_6 ( V_64 ) ) ;
}
V_4 = F_40 ( & V_66 , & V_67 ) ;
if ( V_4 )
F_7 ( L_21 , V_4 ) ;
F_20 () ;
}
