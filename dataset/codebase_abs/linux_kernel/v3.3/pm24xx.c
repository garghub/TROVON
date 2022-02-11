static inline bool F_1 ( void )
{
return ( V_1 != V_2 ) ;
}
static inline bool F_1 ( void )
{
return false ;
}
static int F_2 ( void )
{
T_1 V_3 , V_4 ;
V_3 = F_3 ( V_5 , V_6 ) ;
V_4 = F_3 ( V_5 , V_7 ) ;
return ( V_3 | V_4 ) ? 1 : 0 ;
}
static void F_4 ( void )
{
T_1 V_8 ;
F_5 ( V_9 ) ;
F_6 ( 0xffffffff , V_5 , V_10 ) ;
F_6 ( 0xffffffff , V_5 , V_11 ) ;
F_6 ( 0xffffffff , V_12 , V_13 ) ;
F_7 ( V_14 , V_15 ) ;
F_8 ( V_14 , V_15 ) ;
V_8 = F_9 ( V_16 ) | V_17 ;
F_10 ( V_8 , V_16 ) ;
F_11 ( 0 ) ;
if ( F_12 () )
goto V_18;
F_13 ( F_14 ( V_19 ) ,
F_15 ( V_19 ) ,
F_15 ( V_20 ) ) ;
V_18:
F_16 () ;
F_17 ( V_9 ) ;
F_6 ( 0xffffffff , V_5 , V_10 ) ;
F_6 ( 0xffffffff , V_5 , V_11 ) ;
F_18 ( 0x4 | 0x1 , V_12 , V_13 ) ;
V_8 = F_19 ( V_21 , V_22 ) ;
if ( V_8 & 0x01 )
F_6 ( 0x01 , V_21 ,
V_22 ) ;
if ( V_8 & 0x20 )
F_6 ( 0x20 , V_21 ,
V_22 ) ;
F_6 ( 0x0 , V_21 , V_22 ) ;
}
static int F_20 ( void )
{
T_1 V_8 ;
V_8 = F_3 ( V_5 , V_6 ) ;
return V_8 & ( V_23 | V_24 ) ;
}
static int F_21 ( void )
{
T_1 V_8 ;
V_8 = F_3 ( V_5 , V_6 ) ;
if ( V_8 & ( V_25 | V_26 |
V_27 | V_28 |
V_29 | V_30 ) )
return 0 ;
V_8 = F_3 ( V_5 , V_7 ) ;
if ( V_8 & V_31 )
return 0 ;
if ( V_32 )
return 0 ;
return 1 ;
}
static void F_22 ( void )
{
int V_33 = 0 ;
if ( F_20 () )
return;
if ( F_21 () ) {
F_6 ( 0xffffffff , V_5 , V_10 ) ;
F_6 ( 0xffffffff , V_5 , V_11 ) ;
F_6 ( 0xffffffff , V_12 , V_13 ) ;
F_6 ( ( 0x01 << V_34 ) |
V_35 ,
V_36 , V_37 ) ;
} else {
F_6 ( V_35 , V_36 ,
V_37 ) ;
V_33 = 1 ;
}
F_23 () ;
}
static int F_24 ( void )
{
if ( F_2 () )
return 0 ;
if ( V_9 -> V_38 > 1 )
return 0 ;
if ( F_25 () )
return 0 ;
return 1 ;
}
static void F_26 ( void )
{
F_27 () ;
F_28 () ;
if ( ! F_24 () ) {
if ( F_12 () )
goto V_39;
F_22 () ;
goto V_39;
}
if ( F_12 () )
goto V_39;
F_4 () ;
V_39:
F_29 () ;
F_30 () ;
}
static int F_31 ( T_2 V_40 )
{
F_32 () ;
V_1 = V_40 ;
return 0 ;
}
static int F_33 ( void )
{
T_1 V_41 , V_42 ;
V_41 = F_19 ( V_12 , V_43 ) ;
V_41 &= ~ V_44 ;
F_6 ( V_41 , V_12 , V_43 ) ;
V_42 = F_34 ( 0x480fe0a4 ) ;
F_35 ( 1 << 5 , 0x480fe0ac ) ;
F_4 () ;
F_35 ( V_42 , 0x480fe0a4 ) ;
F_6 ( V_41 , V_12 , V_43 ) ;
return 0 ;
}
static int F_36 ( T_2 V_40 )
{
int V_45 = 0 ;
switch ( V_40 ) {
case V_46 :
case V_47 :
V_45 = F_33 () ;
break;
default:
V_45 = - V_48 ;
}
return V_45 ;
}
static void F_37 ( void )
{
V_1 = V_2 ;
F_38 () ;
}
static int T_3 F_39 ( struct V_49 * V_50 , void * V_51 )
{
if ( V_50 -> V_52 & V_53 )
F_40 ( V_50 ) ;
else if ( V_50 -> V_52 & V_54 &&
F_41 ( & V_50 -> V_38 ) == 0 )
F_42 ( V_50 ) ;
return 0 ;
}
static void T_3 F_43 ( void )
{
int V_55 , V_56 ;
struct V_57 * V_58 ;
F_6 ( V_59 , V_21 ,
V_60 ) ;
V_56 = F_44 ( V_61 ) ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ )
F_45 ( V_61 , V_55 , V_15 ) ;
F_8 ( V_61 , V_15 ) ;
F_7 ( V_14 , V_15 ) ;
F_8 ( V_14 , V_15 ) ;
V_58 = F_46 ( V_62 ) ;
F_8 ( V_58 , V_63 ) ;
F_42 ( V_62 ) ;
V_58 = F_46 ( V_64 ) ;
F_8 ( V_58 , V_63 ) ;
F_42 ( V_64 ) ;
F_47 ( F_39 , NULL ) ;
F_48 ( V_65 , V_66 ) ;
F_6 ( 15 << V_67 , V_68 ,
V_69 ) ;
F_6 ( 2 << V_67 , V_68 ,
V_70 ) ;
F_6 ( V_71 |
( 0x1 << V_72 ) |
V_73 |
( 0x1 << V_74 ) |
( 0x0 << V_75 ) ,
V_68 , V_76 ) ;
F_6 ( V_77 | V_44 ,
V_12 , V_43 ) ;
}
static int T_3 F_49 ( void )
{
T_1 V_8 ;
if ( ! F_50 () )
return - V_78 ;
F_51 ( V_79 L_1 ) ;
V_8 = F_19 ( V_21 , V_80 ) ;
F_51 ( V_79 L_2 , ( V_8 >> 4 ) & 0x0f , V_8 & 0x0f ) ;
V_14 = F_52 ( L_3 ) ;
if ( ! V_14 )
F_53 ( L_4 ) ;
V_61 = F_52 ( L_5 ) ;
if ( ! V_61 )
F_53 ( L_6 ) ;
V_65 = F_54 ( L_7 ) ;
if ( ! V_65 )
F_53 ( L_8 ) ;
V_66 = F_54 ( L_9 ) ;
if ( ! V_66 )
F_53 ( L_10 ) ;
V_62 = F_54 ( L_11 ) ;
if ( ! V_62 )
F_53 ( L_12 ) ;
V_64 = F_54 ( L_13 ) ;
if ( ! V_64 )
F_53 ( L_14 ) ;
V_9 = F_55 ( NULL , L_15 ) ;
if ( F_56 ( V_9 ) ) {
F_51 ( V_81 L_16 ) ;
return - V_78 ;
}
if ( F_57 () ) {
V_82 = F_55 ( NULL , L_17 ) ;
if ( F_56 ( V_82 ) ) {
F_51 ( V_81 L_18 ) ;
F_58 ( V_9 ) ;
return - V_78 ;
}
}
F_43 () ;
{
const struct V_83 * V_84 ;
V_84 = F_59 ( V_85 ,
struct V_83 ) ;
if ( V_84 != NULL && V_84 -> V_86 )
V_32 = 1 ;
}
if ( F_50 () ) {
F_23 = F_60 ( V_87 ,
V_88 ) ;
F_13 = F_60 ( V_89 ,
V_90 ) ;
}
F_61 ( & V_91 ) ;
V_92 = F_26 ;
return 0 ;
}
