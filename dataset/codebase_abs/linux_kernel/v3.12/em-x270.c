static void T_1 F_1 ( void )
{
V_1 . V_2 |= V_3 ;
F_2 ( & V_4 ) ;
}
static inline void F_1 ( void ) {}
static void T_1 F_3 ( void )
{
F_2 ( & V_5 ) ;
}
static inline void F_3 ( void ) {}
static inline void F_4 ( void )
{
F_5 ( V_6 , 0 ) ;
}
static void F_6 ( void )
{
F_7 () ;
F_5 ( V_6 , 1 ) ;
}
static void F_8 ( struct V_7 * V_8 , int V_9 ,
unsigned int V_10 )
{
struct V_11 * V_12 = V_8 -> V_13 ;
unsigned long V_14 = ( unsigned long ) V_12 -> V_15 ;
F_7 () ;
if ( V_10 & V_16 ) {
if ( V_10 & V_17 )
V_14 |= ( 1 << 3 ) ;
else
V_14 &= ~ ( 1 << 3 ) ;
if ( V_10 & V_18 )
V_14 |= ( 1 << 2 ) ;
else
V_14 &= ~ ( 1 << 2 ) ;
if ( V_10 & V_19 )
F_4 () ;
else
F_6 () ;
}
F_7 () ;
V_12 -> V_15 = ( void V_20 * ) V_14 ;
if ( V_9 != V_21 )
F_9 ( V_9 , V_12 -> V_15 ) ;
F_7 () ;
}
static int F_10 ( struct V_7 * V_8 )
{
F_7 () ;
return F_11 ( V_22 ) ;
}
static void T_1 F_12 ( void )
{
int V_23 ;
V_23 = F_13 ( V_6 , L_1 ) ;
if ( V_23 ) {
F_14 ( L_2 ) ;
return;
}
F_15 ( V_6 , 1 ) ;
V_23 = F_13 ( V_22 , L_3 ) ;
if ( V_23 ) {
F_14 ( L_4 ) ;
F_16 ( V_6 ) ;
return;
}
F_17 ( V_22 ) ;
F_2 ( & V_24 ) ;
}
static inline void F_12 ( void ) {}
static void T_1 F_18 ( void )
{
F_2 ( & V_25 ) ;
}
static inline void F_18 ( void ) {}
static int F_19 ( void )
{
int V_23 ;
V_26 = F_20 ( NULL , L_5 ) ;
if ( F_21 ( V_26 ) )
return F_22 ( V_26 ) ;
V_23 = F_13 ( V_27 , L_6 ) ;
if ( V_23 )
goto V_28;
V_23 = F_13 ( V_29 , L_7 ) ;
if ( V_23 )
goto V_30;
F_15 ( V_29 , 1 ) ;
F_15 ( V_27 , 0 ) ;
V_23 = F_23 ( V_26 ) ;
if ( V_23 )
goto V_31;
F_5 ( V_29 , 0 ) ;
F_5 ( V_29 , 1 ) ;
F_24 ( V_26 ) ;
V_23 = F_23 ( V_26 ) ;
if ( V_23 )
goto V_31;
F_5 ( V_29 , 0 ) ;
F_5 ( V_27 , 1 ) ;
return 0 ;
V_31:
F_16 ( V_29 ) ;
V_30:
F_16 ( V_27 ) ;
V_28:
F_25 ( V_26 ) ;
return V_23 ;
}
static int F_26 ( struct V_32 * V_33 )
{
int V_23 ;
V_23 = F_19 () ;
if ( V_23 )
F_27 ( L_8 , V_23 ) ;
V_34 = V_35 | V_36 ;
return 0 ;
}
static void F_28 ( struct V_32 * V_33 )
{
F_16 ( V_29 ) ;
F_16 ( V_27 ) ;
if ( ! F_21 ( V_26 ) ) {
if ( F_29 ( V_26 ) )
F_24 ( V_26 ) ;
F_25 ( V_26 ) ;
}
}
static void T_1 F_30 ( void )
{
F_31 ( & V_37 ) ;
}
static inline void F_30 ( void ) {}
static int F_32 ( struct V_32 * V_33 ,
T_2 V_38 ,
void * V_39 )
{
int V_23 ;
V_40 = F_20 ( V_33 , L_9 ) ;
if ( F_21 ( V_40 ) ) {
F_33 ( V_33 , L_10 ,
F_22 ( V_40 ) ) ;
return F_22 ( V_40 ) ;
}
V_23 = F_34 ( F_35 ( V_41 ) , V_38 ,
V_42 | V_43 |
V_44 ,
L_11 , V_39 ) ;
if ( V_23 ) {
F_33 ( V_33 , L_12 , V_23 ) ;
goto V_45;
}
if ( F_36 () ) {
V_23 = F_13 ( V_46 , L_13 ) ;
if ( V_23 ) {
F_33 ( V_33 , L_14 ,
V_23 ) ;
goto V_47;
}
F_17 ( V_46 ) ;
} else {
V_23 = F_13 ( V_48 , L_15 ) ;
if ( V_23 ) {
F_33 ( V_33 , L_16 ,
V_23 ) ;
goto V_47;
}
F_15 ( V_48 , 1 ) ;
}
return 0 ;
V_47:
F_37 ( F_35 ( V_41 ) , V_39 ) ;
V_45:
F_25 ( V_40 ) ;
return V_23 ;
}
static int F_38 ( struct V_32 * V_33 , unsigned int V_49 )
{
struct V_50 * V_51 = V_33 -> V_52 ;
if ( ( 1 << V_49 ) & V_51 -> V_53 ) {
int V_54 = ( 2000 + ( V_49 - F_39 ( V_55 ) ) * 100 ) * 1000 ;
F_40 ( V_40 , V_54 , V_54 ) ;
return F_23 ( V_40 ) ;
} else {
F_24 ( V_40 ) ;
}
return 0 ;
}
static void F_41 ( struct V_32 * V_33 , void * V_39 )
{
F_37 ( F_35 ( V_41 ) , V_39 ) ;
F_25 ( V_40 ) ;
if ( F_36 () )
F_16 ( V_46 ) ;
else
F_16 ( V_48 ) ;
}
static int F_42 ( struct V_32 * V_33 )
{
return F_11 ( V_46 ) ;
}
static void T_1 F_43 ( void )
{
if ( F_36 () )
V_56 . V_57 = F_42 ;
F_44 ( & V_56 ) ;
}
static inline void F_43 ( void ) {}
static void T_1 F_45 ( void )
{
F_46 ( NULL , & V_58 ) ;
}
static inline void F_45 ( void ) {}
static int F_47 ( struct V_59 * V_60 )
{
int V_23 = F_13 ( V_61 , L_17 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_13 ( V_62 , L_18 ) ;
if ( V_23 )
goto V_63;
if ( F_48 () ) {
V_23 = F_13 ( V_64 , L_19 ) ;
if ( V_23 )
goto V_65;
F_15 ( V_64 , 1 ) ;
F_49 ( 100 ) ;
}
F_15 ( V_62 , 1 ) ;
F_49 ( 100 ) ;
F_50 ( F_51 ( V_66 ) ) ;
F_15 ( V_61 , 0 ) ;
F_49 ( 100 ) ;
F_5 ( V_61 , 1 ) ;
F_49 ( 100 ) ;
V_60 -> V_67 = 16 ;
F_52 ( V_60 ) ;
return 0 ;
V_65:
F_16 ( V_62 ) ;
V_63:
F_16 ( V_61 ) ;
return V_23 ;
}
static int F_53 ( struct V_59 * V_60 )
{
F_5 ( V_61 , 0 ) ;
F_16 ( V_61 ) ;
F_16 ( V_62 ) ;
if ( F_48 () ) {
F_5 ( V_64 , 0 ) ;
F_16 ( V_64 ) ;
}
return 0 ;
}
static void T_1 F_54 ( void )
{
F_55 ( 1 , & V_68 ) ;
F_55 ( 2 , & V_69 ) ;
F_56 ( F_51 ( V_70 ) ) ;
}
static inline void F_54 ( void ) {}
static void T_1 F_57 ( void )
{
F_58 ( & V_71 ) ;
}
static inline void F_57 ( void ) {}
static void T_1 F_59 ( void )
{
if ( F_36 () )
F_60 ( & V_72 ) ;
else
F_60 ( & V_73 ) ;
}
static inline void F_59 ( void ) {}
static void T_1 F_61 ( void )
{
F_2 ( & V_74 ) ;
}
static inline void F_61 ( void ) {}
static int F_62 ( void )
{
int V_75 ;
V_75 = F_13 ( V_76 , L_20 ) ;
if ( V_75 )
return V_75 ;
F_15 ( V_76 , 0 ) ;
V_77 = F_20 ( NULL , L_21 ) ;
if ( V_77 == NULL ) {
F_16 ( V_76 ) ;
return - V_78 ;
}
V_75 = F_23 ( V_77 ) ;
if ( V_75 ) {
F_25 ( V_77 ) ;
F_16 ( V_76 ) ;
return V_75 ;
}
F_5 ( V_76 , 1 ) ;
return 0 ;
}
static int F_63 ( struct V_32 * V_33 , int V_79 )
{
int V_75 ;
int V_80 = F_29 ( V_77 ) ;
if ( V_79 == V_80 )
return 0 ;
F_5 ( V_76 , ! V_79 ) ;
if ( V_79 )
V_75 = F_23 ( V_77 ) ;
else
V_75 = F_24 ( V_77 ) ;
if ( V_75 )
return V_75 ;
F_5 ( V_76 , V_79 ) ;
return 0 ;
}
static void T_1 F_64 ( void )
{
if ( F_62 () == 0 ) {
F_65 ( & V_81 ) ;
F_2 ( & V_82 ) ;
}
}
static inline void F_64 ( void ) {}
static void T_1 F_66 ( void )
{
F_67 ( F_51 ( V_83 ) ) ;
}
static void F_68 ( void )
{
#if F_69 ( V_84 )
F_70 ( V_85 ) ;
#endif
}
static void F_71 ( void )
{
#if F_69 ( V_84 )
F_70 ( V_86 ) ;
#endif
}
static void T_1 F_72 ( void )
{
F_73 ( & V_87 ) ;
F_74 ( 1 , & V_88 , 1 ) ;
}
static void T_1 F_75 ( void )
{
F_76 ( & V_89 ) ;
if ( F_48 () )
F_74 ( 0 , F_51 ( V_90 ) ) ;
}
static void T_1 F_77 ( void )
{
F_50 ( F_51 ( V_91 ) ) ;
V_41 = V_92 ;
V_22 = V_93 ;
V_3 = V_94 ;
V_76 = V_95 ;
V_29 = V_96 ;
}
static void T_1 F_78 ( void )
{
F_50 ( F_51 ( V_97 ) ) ;
V_41 = V_98 ;
V_22 = V_99 ;
V_3 = V_100 ;
V_76 = V_101 ;
V_29 = V_102 ;
}
static void T_1 F_79 ( void )
{
F_50 ( F_51 ( V_103 ) ) ;
F_80 ( NULL ) ;
F_81 ( NULL ) ;
F_82 ( NULL ) ;
#ifdef F_83
F_84 ( V_104 ) ;
#endif
if ( F_36 () )
F_77 () ;
else if ( F_48 () )
F_78 () ;
else
F_85 ( L_22 , V_105 ) ;
F_72 () ;
F_1 () ;
F_3 () ;
F_12 () ;
F_18 () ;
F_45 () ;
F_43 () ;
F_30 () ;
F_59 () ;
F_61 () ;
F_57 () ;
F_54 () ;
F_75 () ;
F_64 () ;
F_66 () ;
}
