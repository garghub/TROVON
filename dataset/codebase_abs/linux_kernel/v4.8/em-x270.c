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
struct V_11 * V_12 = F_9 ( V_8 ) ;
unsigned long V_13 = ( unsigned long ) V_12 -> V_14 ;
F_7 () ;
if ( V_10 & V_15 ) {
if ( V_10 & V_16 )
V_13 |= ( 1 << 3 ) ;
else
V_13 &= ~ ( 1 << 3 ) ;
if ( V_10 & V_17 )
V_13 |= ( 1 << 2 ) ;
else
V_13 &= ~ ( 1 << 2 ) ;
if ( V_10 & V_18 )
F_4 () ;
else
F_6 () ;
}
F_7 () ;
V_12 -> V_14 = ( void V_19 * ) V_13 ;
if ( V_9 != V_20 )
F_10 ( V_9 , V_12 -> V_14 ) ;
F_7 () ;
}
static int F_11 ( struct V_7 * V_8 )
{
F_7 () ;
return F_12 ( V_21 ) ;
}
static void T_1 F_13 ( void )
{
int V_22 ;
V_22 = F_14 ( V_6 , L_1 ) ;
if ( V_22 ) {
F_15 ( L_2 ) ;
return;
}
F_16 ( V_6 , 1 ) ;
V_22 = F_14 ( V_21 , L_3 ) ;
if ( V_22 ) {
F_15 ( L_4 ) ;
F_17 ( V_6 ) ;
return;
}
F_18 ( V_21 ) ;
F_2 ( & V_23 ) ;
}
static inline void F_13 ( void ) {}
static void T_1 F_19 ( void )
{
F_2 ( & V_24 ) ;
}
static inline void F_19 ( void ) {}
static int F_20 ( void )
{
int V_22 ;
V_25 = F_21 ( NULL , L_5 ) ;
if ( F_22 ( V_25 ) )
return F_23 ( V_25 ) ;
V_22 = F_14 ( V_26 , L_6 ) ;
if ( V_22 )
goto V_27;
V_22 = F_14 ( V_28 , L_7 ) ;
if ( V_22 )
goto V_29;
F_16 ( V_28 , 1 ) ;
F_16 ( V_26 , 0 ) ;
V_22 = F_24 ( V_25 ) ;
if ( V_22 )
goto V_30;
F_5 ( V_28 , 0 ) ;
F_5 ( V_28 , 1 ) ;
F_25 ( V_25 ) ;
V_22 = F_24 ( V_25 ) ;
if ( V_22 )
goto V_30;
F_5 ( V_28 , 0 ) ;
F_5 ( V_26 , 1 ) ;
return 0 ;
V_30:
F_17 ( V_28 ) ;
V_29:
F_17 ( V_26 ) ;
V_27:
F_26 ( V_25 ) ;
return V_22 ;
}
static int F_27 ( struct V_31 * V_32 )
{
int V_22 ;
V_22 = F_20 () ;
if ( V_22 )
F_28 ( L_8 , V_22 ) ;
V_33 = V_34 | V_35 ;
return 0 ;
}
static void F_29 ( struct V_31 * V_32 )
{
F_17 ( V_28 ) ;
F_17 ( V_26 ) ;
if ( ! F_22 ( V_25 ) ) {
if ( F_30 ( V_25 ) )
F_25 ( V_25 ) ;
F_26 ( V_25 ) ;
}
}
static void T_1 F_31 ( void )
{
F_32 ( & V_36 ) ;
}
static inline void F_31 ( void ) {}
static int F_33 ( struct V_31 * V_32 ,
T_2 V_37 ,
void * V_38 )
{
int V_22 ;
V_39 = F_21 ( V_32 , L_9 ) ;
if ( F_22 ( V_39 ) ) {
F_34 ( V_32 , L_10 ,
F_23 ( V_39 ) ) ;
return F_23 ( V_39 ) ;
}
V_22 = F_35 ( F_36 ( V_40 ) , V_37 ,
V_41 | V_42 ,
L_11 , V_38 ) ;
if ( V_22 ) {
F_34 ( V_32 , L_12 , V_22 ) ;
goto V_43;
}
if ( F_37 () ) {
V_22 = F_14 ( V_44 , L_13 ) ;
if ( V_22 ) {
F_34 ( V_32 , L_14 ,
V_22 ) ;
goto V_45;
}
F_18 ( V_44 ) ;
} else {
V_22 = F_14 ( V_46 , L_15 ) ;
if ( V_22 ) {
F_34 ( V_32 , L_16 ,
V_22 ) ;
goto V_45;
}
F_16 ( V_46 , 1 ) ;
}
return 0 ;
V_45:
F_38 ( F_36 ( V_40 ) , V_38 ) ;
V_43:
F_26 ( V_39 ) ;
return V_22 ;
}
static int F_39 ( struct V_31 * V_32 , unsigned int V_47 )
{
struct V_48 * V_49 = V_32 -> V_50 ;
if ( ( 1 << V_47 ) & V_49 -> V_51 ) {
int V_52 = ( 2000 + ( V_47 - F_40 ( V_53 ) ) * 100 ) * 1000 ;
F_41 ( V_39 , V_52 , V_52 ) ;
return F_24 ( V_39 ) ;
} else {
F_25 ( V_39 ) ;
}
return 0 ;
}
static void F_42 ( struct V_31 * V_32 , void * V_38 )
{
F_38 ( F_36 ( V_40 ) , V_38 ) ;
F_26 ( V_39 ) ;
if ( F_37 () )
F_17 ( V_44 ) ;
else
F_17 ( V_46 ) ;
}
static int F_43 ( struct V_31 * V_32 )
{
return F_12 ( V_44 ) ;
}
static void T_1 F_44 ( void )
{
if ( F_37 () )
V_54 . V_55 = F_43 ;
F_45 ( & V_54 ) ;
}
static inline void F_44 ( void ) {}
static void T_1 F_46 ( void )
{
F_47 ( NULL , & V_56 ) ;
}
static inline void F_46 ( void ) {}
static int F_48 ( struct V_57 * V_58 )
{
int V_22 = F_14 ( V_59 , L_17 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_14 ( V_60 , L_18 ) ;
if ( V_22 )
goto V_61;
if ( F_49 () ) {
V_22 = F_14 ( V_62 , L_19 ) ;
if ( V_22 )
goto V_63;
F_16 ( V_62 , 1 ) ;
F_50 ( 100 ) ;
}
F_16 ( V_60 , 1 ) ;
F_50 ( 100 ) ;
F_51 ( F_52 ( V_64 ) ) ;
F_16 ( V_59 , 0 ) ;
F_50 ( 100 ) ;
F_5 ( V_59 , 1 ) ;
F_50 ( 100 ) ;
V_58 -> V_65 = 16 ;
F_53 ( V_58 ) ;
return 0 ;
V_63:
F_17 ( V_60 ) ;
V_61:
F_17 ( V_59 ) ;
return V_22 ;
}
static int F_54 ( struct V_57 * V_58 )
{
F_5 ( V_59 , 0 ) ;
F_17 ( V_59 ) ;
F_17 ( V_60 ) ;
if ( F_49 () ) {
F_5 ( V_62 , 0 ) ;
F_17 ( V_62 ) ;
}
return 0 ;
}
static void T_1 F_55 ( void )
{
F_56 ( 1 , & V_66 ) ;
F_56 ( 2 , & V_67 ) ;
F_57 ( F_52 ( V_68 ) ) ;
}
static inline void F_55 ( void ) {}
static void T_1 F_58 ( void )
{
F_59 ( & V_69 ) ;
}
static inline void F_58 ( void ) {}
static void T_1 F_60 ( void )
{
if ( F_37 () )
F_61 ( & V_70 ) ;
else
F_61 ( & V_71 ) ;
}
static inline void F_60 ( void ) {}
static void T_1 F_62 ( void )
{
F_2 ( & V_72 ) ;
}
static inline void F_62 ( void ) {}
static int F_63 ( void )
{
int V_73 ;
V_73 = F_14 ( V_74 , L_20 ) ;
if ( V_73 )
return V_73 ;
F_16 ( V_74 , 0 ) ;
V_75 = F_21 ( NULL , L_21 ) ;
if ( V_75 == NULL ) {
F_17 ( V_74 ) ;
return - V_76 ;
}
V_73 = F_24 ( V_75 ) ;
if ( V_73 ) {
F_26 ( V_75 ) ;
F_17 ( V_74 ) ;
return V_73 ;
}
F_5 ( V_74 , 1 ) ;
return 0 ;
}
static int F_64 ( struct V_31 * V_32 , int V_77 )
{
int V_73 ;
int V_78 = F_30 ( V_75 ) ;
if ( V_77 == V_78 )
return 0 ;
F_5 ( V_74 , ! V_77 ) ;
if ( V_77 )
V_73 = F_24 ( V_75 ) ;
else
V_73 = F_25 ( V_75 ) ;
if ( V_73 )
return V_73 ;
F_5 ( V_74 , V_77 ) ;
return 0 ;
}
static void T_1 F_65 ( void )
{
if ( F_63 () == 0 ) {
F_66 ( & V_79 ) ;
F_2 ( & V_80 ) ;
}
}
static inline void F_65 ( void ) {}
static void T_1 F_67 ( void )
{
F_68 ( F_52 ( V_81 ) ) ;
}
static void F_69 ( void )
{
#if F_70 ( V_82 )
F_71 ( V_83 ) ;
#endif
}
static void F_72 ( void )
{
#if F_70 ( V_82 )
F_71 ( V_84 ) ;
#endif
}
static void T_1 F_73 ( void )
{
F_74 ( & V_85 ) ;
F_75 ( 1 , & V_86 , 1 ) ;
}
static void T_1 F_76 ( void )
{
F_77 ( & V_87 ) ;
if ( F_49 () )
F_75 ( 0 , F_52 ( V_88 ) ) ;
}
static void T_1 F_78 ( void )
{
F_51 ( F_52 ( V_89 ) ) ;
V_40 = V_90 ;
V_21 = V_91 ;
V_3 = V_92 ;
V_74 = V_93 ;
V_28 = V_94 ;
}
static void T_1 F_79 ( void )
{
F_51 ( F_52 ( V_95 ) ) ;
V_40 = V_96 ;
V_21 = V_97 ;
V_3 = V_98 ;
V_74 = V_99 ;
V_28 = V_100 ;
}
static void T_1 F_80 ( void )
{
F_51 ( F_52 ( V_101 ) ) ;
F_81 ( NULL ) ;
F_82 ( NULL ) ;
F_83 ( NULL ) ;
#ifdef F_84
F_85 ( V_102 ) ;
#endif
if ( F_37 () )
F_78 () ;
else if ( F_49 () )
F_79 () ;
else
F_86 ( L_22 , V_103 ) ;
F_73 () ;
F_1 () ;
F_3 () ;
F_13 () ;
F_19 () ;
F_46 () ;
F_44 () ;
F_31 () ;
F_60 () ;
F_62 () ;
F_58 () ;
F_55 () ;
F_76 () ;
F_65 () ;
F_67 () ;
F_87 () ;
}
