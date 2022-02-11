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
V_3 &= ~ ( V_8 | V_9 ) ;
V_4 &= ~ V_10 ;
if ( V_3 | V_4 )
return 1 ;
return 0 ;
}
static void F_4 ( void )
{
T_1 V_11 ;
struct V_12 V_13 , V_14 , V_15 ;
F_5 ( V_16 ) ;
F_6 ( 0xffffffff , V_5 , V_17 ) ;
F_6 ( 0xffffffff , V_5 , V_18 ) ;
F_6 ( 0xffffffff , V_19 , V_20 ) ;
F_7 ( V_21 , V_22 ) ;
F_8 ( V_21 , V_22 ) ;
V_11 = F_9 ( V_23 ) | V_24 ;
F_10 ( V_11 , V_23 ) ;
F_11 ( 0 ) ;
if ( V_25 ) {
F_12 ( & V_13 ) ;
}
if ( F_13 () )
goto V_26;
if ( ! F_1 () )
if ( ! F_14 () )
goto V_26;
F_15 ( 0 ) ;
F_15 ( 1 ) ;
F_15 ( 2 ) ;
F_16 ( F_17 ( V_27 ) ,
F_18 ( V_27 ) ,
F_18 ( V_28 ) ) ;
F_19 ( 2 ) ;
F_19 ( 1 ) ;
F_19 ( 0 ) ;
if ( ! F_1 () )
F_20 () ;
V_26:
if ( V_25 ) {
unsigned long long V_29 ;
F_12 ( & V_14 ) ;
V_15 = F_21 ( V_14 , V_13 ) ;
V_29 = F_22 ( & V_15 ) * V_30 ;
}
F_23 () ;
F_24 ( V_16 ) ;
F_6 ( 0xffffffff , V_5 , V_17 ) ;
F_6 ( 0xffffffff , V_5 , V_18 ) ;
F_25 ( 0x4 | 0x1 , V_19 , V_20 ) ;
V_11 = F_26 ( V_31 , V_32 ) ;
if ( V_11 & 0x01 )
F_6 ( 0x01 , V_31 ,
V_32 ) ;
if ( V_11 & 0x20 )
F_6 ( 0x20 , V_31 ,
V_32 ) ;
F_6 ( 0x0 , V_31 , V_32 ) ;
}
static int F_27 ( void )
{
T_1 V_11 ;
V_11 = F_3 ( V_5 , V_6 ) ;
return V_11 & ( V_33 | V_34 ) ;
}
static int F_28 ( void )
{
T_1 V_11 ;
V_11 = F_3 ( V_5 , V_6 ) ;
if ( V_11 & ( V_35 | V_9 |
V_8 | V_36 |
V_37 | V_38 ) )
return 0 ;
V_11 = F_3 ( V_5 , V_7 ) ;
if ( V_11 & V_10 )
return 0 ;
if ( V_39 )
return 0 ;
return 1 ;
}
static void F_29 ( void )
{
int V_40 = 0 ;
struct V_12 V_13 , V_14 , V_15 ;
if ( F_27 () )
return;
if ( F_28 () ) {
F_6 ( 0xffffffff , V_5 , V_17 ) ;
F_6 ( 0xffffffff , V_5 , V_18 ) ;
F_6 ( 0xffffffff , V_19 , V_20 ) ;
F_6 ( ( 0x01 << V_41 ) |
V_42 ,
V_43 , V_44 ) ;
} else {
F_6 ( V_42 , V_43 ,
V_44 ) ;
V_40 = 1 ;
}
if ( V_25 ) {
F_12 ( & V_13 ) ;
}
F_30 () ;
if ( V_25 ) {
unsigned long long V_29 ;
F_12 ( & V_14 ) ;
V_15 = F_21 ( V_14 , V_13 ) ;
V_29 = F_22 ( & V_15 ) * V_30 ;
}
}
static int F_31 ( void )
{
if ( F_2 () )
return 0 ;
if ( ! F_32 () )
return 0 ;
if ( V_16 -> V_45 > 1 )
return 0 ;
if ( F_33 () )
return 0 ;
return 1 ;
}
static void F_34 ( void )
{
F_35 () ;
F_36 () ;
if ( ! F_31 () ) {
if ( F_13 () )
goto V_46;
F_29 () ;
goto V_46;
}
if ( F_13 () )
goto V_46;
F_4 () ;
V_46:
F_37 () ;
F_38 () ;
}
static int F_39 ( T_2 V_47 )
{
F_40 () ;
V_1 = V_47 ;
return 0 ;
}
static int F_41 ( void )
{
T_1 V_48 , V_49 ;
V_48 = F_26 ( V_19 , V_50 ) ;
V_48 &= ~ V_51 ;
F_6 ( V_48 , V_19 , V_50 ) ;
V_49 = F_42 ( 0x480fe0a4 ) ;
F_43 ( 1 << 5 , 0x480fe0ac ) ;
F_44 () ;
F_4 () ;
F_43 ( V_49 , 0x480fe0a4 ) ;
F_6 ( V_48 , V_19 , V_50 ) ;
return 0 ;
}
static int F_45 ( T_2 V_47 )
{
int V_52 = 0 ;
switch ( V_47 ) {
case V_53 :
case V_54 :
V_52 = F_41 () ;
break;
default:
V_52 = - V_55 ;
}
return V_52 ;
}
static void F_46 ( void )
{
V_1 = V_2 ;
F_47 () ;
}
static int T_3 F_48 ( struct V_56 * V_57 , void * V_58 )
{
if ( V_57 -> V_59 & V_60 )
F_49 ( V_57 ) ;
else if ( V_57 -> V_59 & V_61 &&
F_50 ( & V_57 -> V_45 ) == 0 )
F_51 ( V_57 ) ;
return 0 ;
}
static void T_3 F_52 ( void )
{
int V_62 , V_63 ;
struct V_64 * V_65 ;
F_6 ( V_66 , V_31 ,
V_67 ) ;
V_63 = F_53 ( V_68 ) ;
for ( V_62 = 0 ; V_62 < V_63 ; V_62 ++ )
F_54 ( V_68 , V_62 , V_22 ) ;
F_8 ( V_68 , V_22 ) ;
F_7 ( V_21 , V_22 ) ;
F_8 ( V_21 , V_22 ) ;
V_65 = F_55 ( V_69 ) ;
F_8 ( V_65 , V_70 ) ;
F_51 ( V_69 ) ;
V_65 = F_55 ( V_71 ) ;
F_8 ( V_65 , V_70 ) ;
F_51 ( V_71 ) ;
F_56 ( F_48 , NULL ) ;
F_57 ( V_72 , V_73 ) ;
F_6 ( 15 << V_74 , V_75 ,
V_76 ) ;
F_6 ( 2 << V_74 , V_75 ,
V_77 ) ;
F_6 ( V_78 |
( 0x1 << V_79 ) |
V_80 |
( 0x1 << V_81 ) |
( 0x0 << V_82 ) ,
V_75 , V_83 ) ;
F_6 ( V_84 | V_51 ,
V_19 , V_50 ) ;
}
static int T_3 F_58 ( void )
{
T_1 V_11 ;
if ( ! F_59 () )
return - V_85 ;
F_60 ( V_86 L_1 ) ;
V_11 = F_26 ( V_31 , V_87 ) ;
F_60 ( V_86 L_2 , ( V_11 >> 4 ) & 0x0f , V_11 & 0x0f ) ;
V_21 = F_61 ( L_3 ) ;
if ( ! V_21 )
F_62 ( L_4 ) ;
V_68 = F_61 ( L_5 ) ;
if ( ! V_68 )
F_62 ( L_6 ) ;
V_72 = F_63 ( L_7 ) ;
if ( ! V_72 )
F_62 ( L_8 ) ;
V_73 = F_63 ( L_9 ) ;
if ( ! V_73 )
F_62 ( L_10 ) ;
V_69 = F_63 ( L_11 ) ;
if ( ! V_69 )
F_62 ( L_12 ) ;
V_71 = F_63 ( L_13 ) ;
if ( ! V_71 )
F_62 ( L_14 ) ;
V_16 = F_64 ( NULL , L_15 ) ;
if ( F_65 ( V_16 ) ) {
F_60 ( V_88 L_16 ) ;
return - V_85 ;
}
if ( F_66 () ) {
V_89 = F_64 ( NULL , L_17 ) ;
if ( F_65 ( V_89 ) ) {
F_60 ( V_88 L_18 ) ;
F_67 ( V_16 ) ;
return - V_85 ;
}
}
F_52 () ;
{
const struct V_90 * V_91 ;
V_91 = F_68 ( V_92 ,
struct V_90 ) ;
if ( V_91 != NULL && V_91 -> V_93 )
V_39 = 1 ;
}
if ( F_59 () ) {
F_30 = F_69 ( V_94 ,
V_95 ) ;
F_16 = F_69 ( V_96 ,
V_97 ) ;
}
F_70 ( & V_98 ) ;
V_99 = F_34 ;
return 0 ;
}
