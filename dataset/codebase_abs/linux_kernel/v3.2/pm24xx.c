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
F_5 ( V_12 ) ;
F_6 ( 0xffffffff , V_5 , V_13 ) ;
F_6 ( 0xffffffff , V_5 , V_14 ) ;
F_6 ( 0xffffffff , V_15 , V_16 ) ;
F_7 ( V_17 , V_18 ) ;
F_8 ( V_17 , V_18 ) ;
V_11 = F_9 ( V_19 ) | V_20 ;
F_10 ( V_11 , V_19 ) ;
F_11 ( 0 ) ;
if ( F_12 () )
goto V_21;
if ( ! F_1 () )
if ( ! F_13 () )
goto V_21;
F_14 ( 0 ) ;
F_14 ( 1 ) ;
F_14 ( 2 ) ;
F_15 ( F_16 ( V_22 ) ,
F_17 ( V_22 ) ,
F_17 ( V_23 ) ) ;
F_18 ( 2 ) ;
F_18 ( 1 ) ;
F_18 ( 0 ) ;
if ( ! F_1 () )
F_19 () ;
V_21:
F_20 () ;
F_21 ( V_12 ) ;
F_6 ( 0xffffffff , V_5 , V_13 ) ;
F_6 ( 0xffffffff , V_5 , V_14 ) ;
F_22 ( 0x4 | 0x1 , V_15 , V_16 ) ;
V_11 = F_23 ( V_24 , V_25 ) ;
if ( V_11 & 0x01 )
F_6 ( 0x01 , V_24 ,
V_25 ) ;
if ( V_11 & 0x20 )
F_6 ( 0x20 , V_24 ,
V_25 ) ;
F_6 ( 0x0 , V_24 , V_25 ) ;
}
static int F_24 ( void )
{
T_1 V_11 ;
V_11 = F_3 ( V_5 , V_6 ) ;
return V_11 & ( V_26 | V_27 ) ;
}
static int F_25 ( void )
{
T_1 V_11 ;
V_11 = F_3 ( V_5 , V_6 ) ;
if ( V_11 & ( V_28 | V_9 |
V_8 | V_29 |
V_30 | V_31 ) )
return 0 ;
V_11 = F_3 ( V_5 , V_7 ) ;
if ( V_11 & V_10 )
return 0 ;
if ( V_32 )
return 0 ;
return 1 ;
}
static void F_26 ( void )
{
int V_33 = 0 ;
if ( F_24 () )
return;
if ( F_25 () ) {
F_6 ( 0xffffffff , V_5 , V_13 ) ;
F_6 ( 0xffffffff , V_5 , V_14 ) ;
F_6 ( 0xffffffff , V_15 , V_16 ) ;
F_6 ( ( 0x01 << V_34 ) |
V_35 ,
V_36 , V_37 ) ;
} else {
F_6 ( V_35 , V_36 ,
V_37 ) ;
V_33 = 1 ;
}
F_27 () ;
}
static int F_28 ( void )
{
if ( F_2 () )
return 0 ;
if ( ! F_29 () )
return 0 ;
if ( V_12 -> V_38 > 1 )
return 0 ;
if ( F_30 () )
return 0 ;
return 1 ;
}
static void F_31 ( void )
{
F_32 () ;
F_33 () ;
if ( ! F_28 () ) {
if ( F_12 () )
goto V_39;
F_26 () ;
goto V_39;
}
if ( F_12 () )
goto V_39;
F_4 () ;
V_39:
F_34 () ;
F_35 () ;
}
static int F_36 ( T_2 V_40 )
{
F_37 () ;
V_1 = V_40 ;
return 0 ;
}
static int F_38 ( void )
{
T_1 V_41 , V_42 ;
V_41 = F_23 ( V_15 , V_43 ) ;
V_41 &= ~ V_44 ;
F_6 ( V_41 , V_15 , V_43 ) ;
V_42 = F_39 ( 0x480fe0a4 ) ;
F_40 ( 1 << 5 , 0x480fe0ac ) ;
F_41 () ;
F_4 () ;
F_40 ( V_42 , 0x480fe0a4 ) ;
F_6 ( V_41 , V_15 , V_43 ) ;
return 0 ;
}
static int F_42 ( T_2 V_40 )
{
int V_45 = 0 ;
switch ( V_40 ) {
case V_46 :
case V_47 :
V_45 = F_38 () ;
break;
default:
V_45 = - V_48 ;
}
return V_45 ;
}
static void F_43 ( void )
{
V_1 = V_2 ;
F_44 () ;
}
static int T_3 F_45 ( struct V_49 * V_50 , void * V_51 )
{
if ( V_50 -> V_52 & V_53 )
F_46 ( V_50 ) ;
else if ( V_50 -> V_52 & V_54 &&
F_47 ( & V_50 -> V_38 ) == 0 )
F_48 ( V_50 ) ;
return 0 ;
}
static void T_3 F_49 ( void )
{
int V_55 , V_56 ;
struct V_57 * V_58 ;
F_6 ( V_59 , V_24 ,
V_60 ) ;
V_56 = F_50 ( V_61 ) ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ )
F_51 ( V_61 , V_55 , V_18 ) ;
F_8 ( V_61 , V_18 ) ;
F_7 ( V_17 , V_18 ) ;
F_8 ( V_17 , V_18 ) ;
V_58 = F_52 ( V_62 ) ;
F_8 ( V_58 , V_63 ) ;
F_48 ( V_62 ) ;
V_58 = F_52 ( V_64 ) ;
F_8 ( V_58 , V_63 ) ;
F_48 ( V_64 ) ;
F_53 ( F_45 , NULL ) ;
F_54 ( V_65 , V_66 ) ;
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
V_15 , V_43 ) ;
}
static int T_3 F_55 ( void )
{
T_1 V_11 ;
if ( ! F_56 () )
return - V_78 ;
F_57 ( V_79 L_1 ) ;
V_11 = F_23 ( V_24 , V_80 ) ;
F_57 ( V_79 L_2 , ( V_11 >> 4 ) & 0x0f , V_11 & 0x0f ) ;
V_17 = F_58 ( L_3 ) ;
if ( ! V_17 )
F_59 ( L_4 ) ;
V_61 = F_58 ( L_5 ) ;
if ( ! V_61 )
F_59 ( L_6 ) ;
V_65 = F_60 ( L_7 ) ;
if ( ! V_65 )
F_59 ( L_8 ) ;
V_66 = F_60 ( L_9 ) ;
if ( ! V_66 )
F_59 ( L_10 ) ;
V_62 = F_60 ( L_11 ) ;
if ( ! V_62 )
F_59 ( L_12 ) ;
V_64 = F_60 ( L_13 ) ;
if ( ! V_64 )
F_59 ( L_14 ) ;
V_12 = F_61 ( NULL , L_15 ) ;
if ( F_62 ( V_12 ) ) {
F_57 ( V_81 L_16 ) ;
return - V_78 ;
}
if ( F_63 () ) {
V_82 = F_61 ( NULL , L_17 ) ;
if ( F_62 ( V_82 ) ) {
F_57 ( V_81 L_18 ) ;
F_64 ( V_12 ) ;
return - V_78 ;
}
}
F_49 () ;
{
const struct V_83 * V_84 ;
V_84 = F_65 ( V_85 ,
struct V_83 ) ;
if ( V_84 != NULL && V_84 -> V_86 )
V_32 = 1 ;
}
if ( F_56 () ) {
F_27 = F_66 ( V_87 ,
V_88 ) ;
F_15 = F_66 ( V_89 ,
V_90 ) ;
}
F_67 ( & V_91 ) ;
V_92 = F_31 ;
return 0 ;
}
