int F_1 ( enum V_1 V_2 )
{
return ( V_3 & ( 1 << V_2 ) ) ? 1 : 0 ;
}
int T_1 F_2 ( char * V_4 )
{
if ( ! V_4 )
return 0 ;
return F_3 ( V_4 , 0 , & V_3 ) ;
}
static void T_1 F_4 ( void )
{
if ( ! F_1 ( V_5 ) )
return;
F_5 ( F_6 ( V_6 ) ) ;
}
static inline void F_4 ( void ) {}
static void T_1 F_7 ( void )
{
F_8 ( & V_7 ) ;
}
static inline void F_7 ( void ) {}
static void T_1 F_9 ( void )
{
if ( ! F_1 ( V_8 ) )
return;
F_5 ( F_6 ( V_9 ) ) ;
F_10 ( NULL ) ;
F_8 ( & V_10 ) ;
}
static inline void F_9 ( void ) {}
static void F_11 ( int V_11 )
{
F_12 ( V_12 , V_11 ) ;
}
static void T_1 F_13 ( void )
{
int V_13 ;
if ( ! F_1 ( V_14 ) )
return;
F_5 ( F_6 ( V_15 ) ) ;
V_13 = F_14 ( V_12 , L_1 ) ;
if ( V_13 ) {
F_15 ( L_2 ) ;
goto V_16;
}
V_13 = F_16 ( V_12 , 1 ) ;
if ( V_13 ) {
F_15 ( L_3 ) ;
goto V_17;
}
V_18 . V_19 = F_11 ;
F_17 ( NULL , & V_18 ) ;
return;
V_17:
F_18 ( V_12 ) ;
V_16:
return;
}
static inline void F_13 ( void ) {}
static void T_1 F_19 ( void )
{
F_5 ( F_6 ( V_20 ) ) ;
F_20 ( & V_21 ) ;
}
static inline void F_19 ( void ) {}
static void F_21 ( int V_22 )
{
if ( V_22 == V_23 )
V_24 |= V_25 | V_26 ;
else if ( V_22 == V_27 )
V_24 &= ~ V_25 ;
}
static int F_22 ( void )
{
return 1 ;
}
static void T_1 F_23 ( void )
{
F_24 ( & V_28 ) ;
F_8 ( & V_29 ) ;
}
static inline void F_23 ( void ) {}
static void T_1 F_25 ( void )
{
F_26 ( & V_30 ) ;
}
static inline void F_25 ( void ) {}
static void T_1 F_27 ( void )
{
if ( ! F_1 ( V_31 ) )
return;
F_5 ( F_6 ( V_32 ) ) ;
F_28 ( & V_33 ) ;
}
static inline void F_27 ( void ) {}
static void T_1 F_29 ( void )
{
F_5 ( F_6 ( V_34 ) ) ;
F_8 ( & V_35 ) ;
F_8 ( & V_36 ) ;
}
static inline void F_29 ( void ) {}
static void F_30 ( struct V_37 * V_38 )
{
int V_39 = ( V_38 -> V_40 - F_31 ( 0 ) ) ;
V_41 &= ~ ( 1 << V_39 ) ;
F_32 ( ~ V_41 , V_42 ) ;
}
static void F_33 ( struct V_37 * V_38 )
{
int V_39 = ( V_38 -> V_40 - F_31 ( 0 ) ) ;
V_41 |= ( 1 << V_39 ) ;
F_32 ( ~ V_41 , V_42 ) ;
}
static void F_34 ( unsigned int V_40 , struct V_43 * V_44 )
{
unsigned long V_45 = F_35 ( V_42 ) &
V_41 ;
do {
if ( V_44 -> V_37 . V_46 -> V_47 ) {
struct V_37 * V_38 ;
V_38 = F_36 ( V_48 ) ;
V_44 -> V_37 . V_46 -> V_47 ( V_38 ) ;
}
while ( V_45 ) {
V_40 = F_31 ( 0 ) + F_37 ( V_45 ) ;
F_38 ( V_40 ) ;
V_45 &= V_45 - 1 ;
}
V_45 = F_35 ( V_42 ) &
V_41 ;
} while ( V_45 );
}
static void T_1 F_39 ( void )
{
int V_40 ;
F_40 () ;
for ( V_40 = F_31 ( 0 ) ; V_40 <= F_31 ( 7 ) ; V_40 ++ ) {
F_41 ( V_40 , & V_49 ,
V_50 ) ;
F_42 ( V_40 , V_51 | V_52 ) ;
}
F_43 ( V_48 , F_34 ) ;
F_44 ( V_48 , V_53 ) ;
F_45 ( L_4
L_5 , V_54 , V_48 ) ;
}
static void T_1 F_46 ( void )
{
F_47 ( NULL ) ;
F_48 ( 0 , F_6 ( V_55 ) ) ;
}
static inline void F_46 ( void ) {}
static void F_49 ( struct V_56 * V_57 , int V_22 , unsigned int V_58 )
{
struct V_59 * V_60 = V_57 -> V_61 ;
T_2 V_62 = 0 , V_63 = 0 ;
if ( V_58 & V_64 ) {
if ( V_58 & V_65 )
V_62 |= V_66 ;
else
V_63 |= V_66 ;
if ( V_58 & V_67 )
V_62 |= V_68 ;
else
V_63 |= V_68 ;
if ( V_63 )
F_32 ( V_63 ,
V_69 ) ;
if ( V_62 )
F_32 ( V_62 ,
V_69 |
V_70 ) ;
}
if ( V_22 != V_71 )
F_50 ( V_22 , V_60 -> V_72 ) ;
}
static void F_51 ( struct V_56 * V_57 , int V_46 )
{
if ( V_46 < 0 || V_46 > 3 )
return;
F_52 (
V_73 | V_74 |
V_75 | V_76 ,
V_69 | V_70 ) ;
F_52 ( V_73 << V_46 ,
V_69 ) ;
}
static int F_53 ( struct V_56 * V_57 )
{
return F_35 ( V_77 ) & V_78 ;
}
static int F_54 ( struct V_79 * V_80 )
{
T_3 V_81 ;
int V_13 ;
F_52 ( V_82 ,
V_83 | V_70 ) ;
V_81 = F_55 ( V_84 ) ;
if ( V_81 < 0x4f08 )
F_56 ( L_6
L_7 , V_81 ) ;
V_13 = F_14 ( V_85 , L_8 ) ;
if ( V_13 )
goto V_86;
V_13 = F_16 ( V_85 , 1 ) ;
if ( V_13 )
goto V_17;
F_12 ( V_85 , 1 ) ;
F_32 (
V_73 | V_74 |
V_75 | V_76 |
V_87 ,
V_69 | V_70 ) ;
return 0 ;
V_17:
F_18 ( V_85 ) ;
V_86:
return V_13 ;
}
static void F_57 ( struct V_79 * V_80 )
{
F_12 ( V_85 , 0 ) ;
F_18 ( V_85 ) ;
}
static void T_1 F_58 ( void )
{
F_8 ( & V_88 ) ;
}
static inline void F_58 ( void ) {}
static void T_1 F_59 ( void )
{
F_60 ( NULL ) ;
F_48 ( 1 , F_6 ( V_89 ) ) ;
}
static inline void F_59 ( void ) {}
static void T_1 F_61 ( void )
{
V_90 = V_91 | 0x234 ;
F_5 ( F_6 ( V_92 ) ) ;
F_62 ( NULL ) ;
F_63 ( NULL ) ;
F_64 ( NULL ) ;
F_46 () ;
F_25 () ;
F_13 () ;
F_29 () ;
F_19 () ;
F_58 () ;
F_7 () ;
F_59 () ;
F_9 () ;
F_23 () ;
F_27 () ;
F_4 () ;
}
static void T_1 F_65 ( void )
{
F_66 () ;
F_67 ( V_93 , F_68 ( V_93 ) ) ;
}
