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
}
static inline void F_23 ( void ) {}
static void T_1 F_25 ( void )
{
F_26 ( & V_29 ) ;
}
static inline void F_25 ( void ) {}
static void T_1 F_27 ( void )
{
if ( ! F_1 ( V_30 ) )
return;
F_5 ( F_6 ( V_31 ) ) ;
F_28 ( & V_32 ) ;
}
static inline void F_27 ( void ) {}
static void T_1 F_29 ( void )
{
F_5 ( F_6 ( V_33 ) ) ;
F_8 ( & V_34 ) ;
F_8 ( & V_35 ) ;
}
static inline void F_29 ( void ) {}
static void F_30 ( struct V_36 * V_37 )
{
int V_38 = ( V_37 -> V_39 - F_31 ( 0 ) ) ;
V_40 &= ~ ( 1 << V_38 ) ;
F_32 ( ~ V_40 , V_41 ) ;
}
static void F_33 ( struct V_36 * V_37 )
{
int V_38 = ( V_37 -> V_39 - F_31 ( 0 ) ) ;
V_40 |= ( 1 << V_38 ) ;
F_32 ( ~ V_40 , V_41 ) ;
}
static void F_34 ( unsigned int V_39 , struct V_42 * V_43 )
{
unsigned long V_44 = F_35 ( V_41 ) &
V_40 ;
do {
if ( V_43 -> V_36 . V_45 -> V_46 ) {
struct V_36 * V_37 ;
V_37 = F_36 ( V_47 ) ;
V_43 -> V_36 . V_45 -> V_46 ( V_37 ) ;
}
while ( V_44 ) {
V_39 = F_31 ( 0 ) + F_37 ( V_44 ) ;
F_38 ( V_39 ) ;
V_44 &= V_44 - 1 ;
}
V_44 = F_35 ( V_41 ) &
V_40 ;
} while ( V_44 );
}
static void T_1 F_39 ( void )
{
int V_39 ;
F_40 () ;
for ( V_39 = F_31 ( 0 ) ; V_39 <= F_31 ( 7 ) ; V_39 ++ ) {
F_41 ( V_39 , & V_48 ,
V_49 ) ;
F_42 ( V_39 , V_50 | V_51 ) ;
}
F_43 ( V_47 , F_34 ) ;
F_44 ( V_47 , V_52 ) ;
F_45 ( L_4
L_5 , V_53 , V_47 ) ;
}
static void T_1 F_46 ( void )
{
F_47 ( NULL ) ;
F_48 ( 0 , F_6 ( V_54 ) ) ;
}
static inline void F_46 ( void ) {}
static void F_49 ( struct V_55 * V_56 , int V_22 , unsigned int V_57 )
{
struct V_58 * V_59 = V_56 -> V_60 ;
T_2 V_61 = 0 , V_62 = 0 ;
if ( V_57 & V_63 ) {
if ( V_57 & V_64 )
V_61 |= V_65 ;
else
V_62 |= V_65 ;
if ( V_57 & V_66 )
V_61 |= V_67 ;
else
V_62 |= V_67 ;
if ( V_62 )
F_32 ( V_62 ,
V_68 ) ;
if ( V_61 )
F_32 ( V_61 ,
V_68 +
V_69 ) ;
}
if ( V_22 != V_70 )
F_50 ( V_22 , V_59 -> V_71 ) ;
}
static void F_51 ( struct V_55 * V_56 , int V_45 )
{
if ( V_45 < 0 || V_45 > 3 )
return;
F_52 (
V_72 | V_73 |
V_74 | V_75 ,
V_68 + V_69 ) ;
F_52 ( V_72 << V_45 ,
V_68 ) ;
}
static int F_53 ( struct V_55 * V_56 )
{
return F_35 ( V_76 ) & V_77 ;
}
static int F_54 ( struct V_78 * V_79 )
{
T_3 V_80 ;
int V_13 ;
F_52 ( V_81 ,
V_82 + V_69 ) ;
V_80 = F_55 ( V_83 ) ;
if ( V_80 < 0x4f08 )
F_56 ( L_6
L_7 , V_80 ) ;
V_13 = F_14 ( V_84 , L_8 ) ;
if ( V_13 )
goto V_85;
V_13 = F_16 ( V_84 , 1 ) ;
if ( V_13 )
goto V_17;
F_12 ( V_84 , 1 ) ;
F_32 (
V_72 | V_73 |
V_74 | V_75 |
V_86 ,
V_68 + V_69 ) ;
return 0 ;
V_17:
F_18 ( V_84 ) ;
V_85:
return V_13 ;
}
static void F_57 ( struct V_78 * V_79 )
{
F_12 ( V_84 , 0 ) ;
F_18 ( V_84 ) ;
}
static void T_1 F_58 ( void )
{
F_8 ( & V_87 ) ;
}
static inline void F_58 ( void ) {}
static void T_1 F_59 ( void )
{
F_60 ( NULL ) ;
F_48 ( 1 , F_6 ( V_88 ) ) ;
}
static inline void F_59 ( void ) {}
static void T_1 F_61 ( void )
{
V_89 = V_90 | 0x234 ;
F_5 ( F_6 ( V_91 ) ) ;
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
F_67 ( V_92 , F_68 ( V_92 ) ) ;
}
