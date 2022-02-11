static int F_1 ( void )
{
T_1 V_1 , V_2 ;
V_1 = F_2 ( V_3 , V_4 ) ;
V_2 = F_2 ( V_3 , V_5 ) ;
return ( V_1 | V_2 ) ? 1 : 0 ;
}
static int F_3 ( void )
{
T_1 V_6 ;
F_4 ( V_7 ) ;
F_5 ( 0xffffffff , V_3 , V_8 ) ;
F_5 ( 0xffffffff , V_3 , V_9 ) ;
F_5 ( 0xffffffff , V_10 , V_11 ) ;
F_6 ( V_12 , V_13 ) ;
F_7 ( V_12 , V_13 ) ;
V_6 = F_8 ( V_14 ) | V_15 ;
F_9 ( V_6 , V_14 ) ;
F_10 ( 0 ) ;
if ( F_11 () )
goto V_16;
F_12 ( F_13 ( V_17 ) ,
F_14 ( V_17 ) ,
F_14 ( V_18 ) ) ;
V_16:
F_15 () ;
F_16 ( V_7 ) ;
F_5 ( 0xffffffff , V_3 , V_8 ) ;
F_5 ( 0xffffffff , V_3 , V_9 ) ;
F_17 ( 0x4 | 0x1 , V_10 , V_11 ) ;
V_6 = F_18 ( V_19 , V_20 ) ;
if ( V_6 & 0x01 )
F_5 ( 0x01 , V_19 ,
V_20 ) ;
if ( V_6 & 0x20 )
F_5 ( 0x20 , V_19 ,
V_20 ) ;
F_5 ( 0x0 , V_19 , V_20 ) ;
return 0 ;
}
static int F_19 ( void )
{
T_1 V_6 ;
V_6 = F_2 ( V_3 , V_4 ) ;
return V_6 & ( V_21 | V_22 ) ;
}
static int F_20 ( void )
{
T_1 V_6 ;
V_6 = F_2 ( V_3 , V_4 ) ;
if ( V_6 & ( V_23 | V_24 |
V_25 | V_26 |
V_27 | V_28 ) )
return 0 ;
V_6 = F_2 ( V_3 , V_5 ) ;
if ( V_6 & V_29 )
return 0 ;
if ( V_30 )
return 0 ;
return 1 ;
}
static void F_21 ( void )
{
int V_31 = 0 ;
if ( F_19 () )
return;
if ( F_20 () ) {
F_5 ( 0xffffffff , V_3 , V_8 ) ;
F_5 ( 0xffffffff , V_3 , V_9 ) ;
F_5 ( 0xffffffff , V_10 , V_11 ) ;
F_5 ( ( 0x01 << V_32 ) |
V_33 ,
V_34 , V_35 ) ;
} else {
F_5 ( V_33 , V_34 ,
V_35 ) ;
V_31 = 1 ;
}
F_22 () ;
}
static int F_23 ( void )
{
if ( F_1 () )
return 0 ;
if ( V_7 -> V_36 > 1 )
return 0 ;
if ( F_24 () )
return 0 ;
return 1 ;
}
static void F_25 ( void )
{
F_26 () ;
if ( ! F_23 () ) {
if ( F_11 () )
goto V_37;
F_21 () ;
goto V_37;
}
if ( F_11 () )
goto V_37;
F_3 () ;
V_37:
F_27 () ;
}
static void T_2 F_28 ( void )
{
int V_38 , V_39 ;
struct V_40 * V_41 ;
F_5 ( V_42 , V_19 ,
V_43 ) ;
V_39 = F_29 ( V_44 ) ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ )
F_30 ( V_44 , V_38 , V_13 ) ;
F_7 ( V_44 , V_13 ) ;
F_6 ( V_12 , V_13 ) ;
F_7 ( V_12 , V_13 ) ;
V_41 = F_31 ( V_45 ) ;
F_7 ( V_41 , V_46 ) ;
F_32 ( V_45 ) ;
V_41 = F_31 ( V_47 ) ;
F_7 ( V_41 , V_46 ) ;
F_32 ( V_47 ) ;
F_33 ( V_48 , NULL ) ;
F_34 ( V_49 , V_50 ) ;
#ifdef F_35
V_51 = F_3 ;
#endif
F_5 ( 15 << V_52 , V_53 ,
V_54 ) ;
F_5 ( 2 << V_52 , V_53 ,
V_55 ) ;
F_5 ( V_56 |
( 0x1 << V_57 ) |
V_58 |
( 0x1 << V_59 ) |
( 0x0 << V_60 ) ,
V_53 , V_61 ) ;
F_5 ( V_62 | V_63 ,
V_10 , V_64 ) ;
}
static int T_2 F_36 ( void )
{
T_1 V_6 ;
if ( ! F_37 () )
return - V_65 ;
F_38 ( V_66 L_1 ) ;
V_6 = F_18 ( V_19 , V_67 ) ;
F_38 ( V_66 L_2 , ( V_6 >> 4 ) & 0x0f , V_6 & 0x0f ) ;
V_12 = F_39 ( L_3 ) ;
if ( ! V_12 )
F_40 ( L_4 ) ;
V_44 = F_39 ( L_5 ) ;
if ( ! V_44 )
F_40 ( L_6 ) ;
V_49 = F_41 ( L_7 ) ;
if ( ! V_49 )
F_40 ( L_8 ) ;
V_50 = F_41 ( L_9 ) ;
if ( ! V_50 )
F_40 ( L_10 ) ;
V_45 = F_41 ( L_11 ) ;
if ( ! V_45 )
F_40 ( L_12 ) ;
V_47 = F_41 ( L_13 ) ;
if ( ! V_47 )
F_40 ( L_14 ) ;
V_7 = F_42 ( NULL , L_15 ) ;
if ( F_43 ( V_7 ) ) {
F_38 ( V_68 L_16 ) ;
return - V_65 ;
}
if ( F_44 () ) {
V_69 = F_42 ( NULL , L_17 ) ;
if ( F_43 ( V_69 ) ) {
F_38 ( V_68 L_18 ) ;
F_45 ( V_7 ) ;
return - V_65 ;
}
}
F_28 () ;
{
const struct V_70 * V_71 ;
V_71 = F_46 ( V_72 ,
struct V_70 ) ;
if ( V_71 != NULL && V_71 -> V_73 )
V_30 = 1 ;
}
if ( F_37 () ) {
F_22 = F_47 ( V_74 ,
V_75 ) ;
F_12 = F_47 ( V_76 ,
V_77 ) ;
}
V_78 = F_25 ;
return 0 ;
}
