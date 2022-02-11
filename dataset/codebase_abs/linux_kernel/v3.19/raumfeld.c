static void F_1 ( int V_1 )
{
F_2 ( V_2 , V_1 ) ;
F_3 ( 100 ) ;
}
static void T_1 F_4 ( void )
{
int V_3 = F_5 ( V_2 ,
L_1 ) ;
if ( V_3 < 0 )
F_6 ( L_2 ) ;
else
F_7 ( V_2 , 0 ) ;
F_8 ( & V_4 ) ;
}
static void T_1 F_9 ( void )
{
int V_3 ;
V_3 = F_5 ( V_5 , L_3 ) ;
if ( V_3 < 0 )
F_6 ( L_4 ) ;
else
F_7 ( V_5 , 1 ) ;
F_3 ( 100 ) ;
V_3 = F_5 ( V_6 , L_5 ) ;
if ( V_3 < 0 )
F_6 ( L_6 ) ;
else
F_7 ( V_6 , 1 ) ;
if ( ( V_7 & 0xff ) == 2 ) {
F_8 ( & V_8 ) ;
} else {
T_2 V_9 = V_10 ;
F_10 ( & V_9 , 1 ) ;
F_8 ( & V_11 ) ;
}
F_11 ( NULL , & V_12 ) ;
F_8 ( & V_13 ) ;
}
static int F_12 ( struct V_14 * V_15 , T_3 V_16 , void * V_17 )
{
F_2 ( V_18 , 1 ) ;
F_2 ( V_19 , 1 ) ;
return 0 ;
}
static void F_13 ( struct V_14 * V_15 , void * V_17 )
{
F_2 ( V_18 , 0 ) ;
F_2 ( V_19 , 0 ) ;
}
static int F_14 ( struct V_14 * V_15 )
{
return 0 ;
}
static void F_15 ( struct V_14 * V_15 )
{
}
static int F_16 ( void )
{
return ! F_17 ( V_20 ) ;
}
static int F_18 ( void )
{
return 0 ;
}
static void F_19 ( void )
{
struct V_21 * V_22 =
F_20 ( V_23 [ 0 ] ) ;
if ( V_22 )
F_21 ( V_22 ) ;
}
static int F_22 ( void )
{
if ( ! F_17 ( V_24 ) )
F_19 () ;
return 0 ;
}
static T_4 F_23 ( int V_25 , void * V_26 )
{
F_19 () ;
return V_27 ;
}
static void T_1 F_24 ( void )
{
int V_3 ;
V_3 = F_5 ( V_28 , L_7 ) ;
if ( V_3 < 0 )
F_6 ( L_8 ) ;
else
F_7 ( V_28 , 1 ) ;
V_3 = F_5 ( V_20 , L_9 ) ;
if ( V_3 < 0 )
F_6 ( L_10 ) ;
V_3 = F_5 ( V_29 , L_11 ) ;
if ( V_3 < 0 )
F_6 ( L_12 ) ;
else
F_7 ( V_29 , 0 ) ;
V_30 [ 0 ] . V_31 = F_25 ( V_20 ) ;
V_30 [ 0 ] . V_32 = F_25 ( V_20 ) ;
V_3 = F_26 ( F_25 ( V_24 ) ,
& F_23 , V_33 ,
L_13 , NULL ) ;
if ( V_3 < 0 )
F_27 ( V_34 L_14 , V_35 ,
V_24 ) ;
else
F_8 ( & V_36 ) ;
}
static void T_1 F_28 ( void )
{
int V_3 ;
V_3 = F_5 ( V_37 , L_15 ) ;
if ( V_3 < 0 )
F_6 ( L_16 ) ;
else
F_7 ( V_37 , 1 ) ;
V_3 = F_5 ( V_38 , L_17 ) ;
if ( V_3 < 0 )
F_6 ( L_18 ) ;
else
F_7 ( V_38 , 1 ) ;
V_3 = F_5 ( V_39 , L_19 ) ;
if ( V_3 < 0 )
F_6 ( L_20 ) ;
else
F_7 ( V_39 , 1 ) ;
F_29 ( F_30 ( V_40 ) ) ;
}
static void T_1 F_31 ( void )
{
int V_3 ;
if ( ( V_7 & 0xff ) > 1 ) {
int V_41 ;
for ( V_41 = 0 ; V_41 < F_32 ( V_42 ) ; V_41 ++ )
if ( ! strcmp ( V_42 [ V_41 ] . V_43 , L_21 ) )
V_42 [ V_41 ] . V_44 = 1 ;
}
F_33 ( V_45 ) ;
F_34 ( & V_46 ) ;
F_35 ( NULL ) ;
F_36 ( & V_47 ) ;
F_37 ( & V_48 ) ;
F_38 ( NULL ) ;
F_39 ( NULL ) ;
V_3 = F_5 ( V_18 , L_22 ) ;
if ( V_3 < 0 )
F_6 ( L_23 ) ;
else
F_7 ( V_18 , 0 ) ;
V_3 = F_5 ( V_19 , L_24 ) ;
if ( V_3 < 0 )
F_6 ( L_25 ) ;
else
F_7 ( V_19 , 0 ) ;
V_3 = F_5 ( V_49 , L_26 ) ;
if ( V_3 < 0 )
F_6 ( L_27 ) ;
else
F_7 ( V_49 , 0 ) ;
F_29 ( F_30 ( V_50 ) ) ;
F_40 ( 1 , & V_51 , 1 ) ;
}
static void T_1 F_41 ( void )
{
int V_3 ;
F_10 ( F_30 ( V_52 ) ) ;
F_8 ( & V_53 ) ;
F_42 ( F_30 ( V_54 ) ) ;
F_40 ( 0 , & V_55 , 1 ) ;
V_3 = F_5 ( V_56 , L_28 ) ;
if ( V_3 < 0 )
F_6 ( L_29 ) ;
else
F_7 ( V_56 , 0 ) ;
F_31 () ;
F_24 () ;
F_9 () ;
F_4 () ;
}
static void T_1 F_43 ( void )
{
F_10 ( F_30 ( V_57 ) ) ;
F_42 ( F_30 ( V_58 ) ) ;
F_40 ( 0 , & V_59 , 1 ) ;
F_8 ( & V_60 ) ;
F_28 () ;
F_31 () ;
}
static void T_1 F_44 ( void )
{
F_10 ( F_30 ( V_61 ) ) ;
F_42 ( F_30 ( V_62 ) ) ;
F_40 ( 0 , & V_59 , 1 ) ;
F_8 ( & V_60 ) ;
F_8 ( & V_53 ) ;
F_28 () ;
F_31 () ;
}
