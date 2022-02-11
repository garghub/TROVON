void T_1 F_1 ( void )
{
V_1 = 0 ;
}
static int T_1 F_2 ( char * V_2 )
{
if ( ! strncmp ( V_2 , L_1 , 5 ) )
V_3 = 1 ;
else if ( ! strncmp ( V_2 , L_2 , 7 ) )
V_3 = 0 ;
else if ( ! strncmp ( V_2 , L_3 , 1 ) )
V_1 = 0 ;
else if ( ! strncmp ( V_2 , L_4 , 1 ) )
V_1 = 1 ;
return 1 ;
}
static int T_1 F_3 ( char * V_2 )
{
V_4 = ! ! F_4 ( V_2 , NULL , 0 ) ;
return 1 ;
}
int __weak F_5 ( unsigned int V_5 )
{
F_6 () ;
return 0 ;
}
void __weak F_7 ( unsigned int V_5 )
{
F_8 () ;
}
int __weak T_1 F_9 ( void )
{
return F_10 () ;
}
void __weak F_11 ( void ) { }
void __weak F_12 ( void ) { }
static void F_13 ( void )
{
V_6 = 0 ;
if ( ! V_7 )
return;
if ( V_8 && V_1 )
V_6 |= V_9 ;
if ( V_10 )
V_6 |= V_11 ;
}
static int T_1 F_14 ( char * V_2 )
{
V_12 = F_15 ( V_2 , NULL , 0 ) ;
return 1 ;
}
static int T_1 F_16 ( char * V_2 )
{
V_7 = 0 ;
return 1 ;
}
static int T_1 F_17 ( char * V_2 )
{
V_10 = 0 ;
return 1 ;
}
static int T_1 F_18 ( char * V_2 )
{
V_13 = ! ! F_4 ( V_2 , NULL , 0 ) ;
return 1 ;
}
static int F_19 ( void )
{
return V_14 * 2 ;
}
static unsigned long F_20 ( void )
{
return F_21 () >> 30LL ;
}
static void F_22 ( void )
{
V_15 = F_19 () * ( ( V_16 ) V_17 / 5 ) ;
F_23 ( V_15 ) ;
}
static void F_24 ( void )
{
F_25 ( V_18 , F_20 () ) ;
}
void F_26 ( void )
{
F_27 ( V_18 , 0 ) ;
}
void F_28 ( void )
{
F_26 () ;
F_29 ( F_30 () ) ;
}
void F_31 ( void )
{
int V_5 ;
F_32 (cpu, &watchdog_allowed_mask)
F_33 ( V_18 , V_5 ) = 0 ;
F_29 ( - 1 ) ;
}
void F_34 ( void )
{
F_25 ( V_19 , true ) ;
F_25 ( V_18 , 0 ) ;
}
static int F_35 ( unsigned long V_20 )
{
unsigned long V_21 = F_20 () ;
if ( ( V_6 & V_11 ) && V_14 ) {
if ( F_36 ( V_21 , V_20 + F_19 () ) )
return V_21 - V_20 ;
}
return 0 ;
}
bool F_37 ( void )
{
unsigned long V_22 = F_38 ( V_23 ) ;
if ( F_38 ( V_24 ) == V_22 )
return true ;
F_25 ( V_24 , V_22 ) ;
return false ;
}
static void F_39 ( void )
{
F_40 ( V_23 ) ;
}
static enum V_25 F_41 ( struct V_26 * V_26 )
{
unsigned long V_20 = F_38 ( V_18 ) ;
struct V_27 * V_28 = F_42 () ;
int V_29 ;
int V_30 = V_13 ;
if ( ! V_6 )
return V_31 ;
F_39 () ;
F_43 ( F_38 ( V_32 ) ) ;
F_44 ( V_26 , F_45 ( V_15 ) ) ;
if ( V_20 == 0 ) {
if ( F_46 ( F_38 ( V_19 ) ) ) {
F_25 ( V_19 , false ) ;
F_47 () ;
}
F_48 () ;
F_24 () ;
return V_33 ;
}
V_29 = F_35 ( V_20 ) ;
if ( F_46 ( V_29 ) ) {
if ( F_48 () )
return V_33 ;
if ( F_38 ( V_34 ) == true ) {
if ( F_38 ( V_35 ) !=
V_36 ) {
F_25 ( V_34 , false ) ;
F_24 () ;
}
return V_33 ;
}
if ( V_30 ) {
if ( F_49 ( 0 , & V_37 ) ) {
F_25 ( V_34 , true ) ;
return V_33 ;
}
}
F_50 ( L_5 ,
F_51 () , V_29 ,
V_36 -> V_38 , F_52 ( V_36 ) ) ;
F_25 ( V_35 , V_36 ) ;
F_53 () ;
F_54 ( V_36 ) ;
if ( V_28 )
F_55 ( V_28 ) ;
else
F_56 () ;
if ( V_30 ) {
F_57 () ;
F_58 ( 0 , & V_37 ) ;
F_59 () ;
}
F_60 ( V_39 , V_40 ) ;
if ( V_12 )
F_61 ( L_6 ) ;
F_25 ( V_34 , true ) ;
} else
F_25 ( V_34 , false ) ;
return V_33 ;
}
static void F_62 ( unsigned int V_41 , unsigned int V_42 )
{
struct V_43 V_44 = { . V_45 = V_42 } ;
F_63 ( V_36 , V_41 , & V_44 ) ;
}
static void F_64 ( unsigned int V_5 )
{
struct V_26 * V_26 = F_65 ( & V_46 ) ;
F_66 ( V_26 , V_47 , V_48 ) ;
V_26 -> V_49 = F_41 ;
F_67 ( V_26 , F_45 ( V_15 ) ,
V_50 ) ;
F_24 () ;
if ( V_6 & V_9 )
F_5 ( V_5 ) ;
F_62 ( V_51 , V_52 - 1 ) ;
}
static void F_68 ( unsigned int V_5 )
{
struct V_26 * V_26 = F_65 ( & V_46 ) ;
F_62 ( V_53 , 0 ) ;
F_7 ( V_5 ) ;
F_69 ( V_26 ) ;
}
static void F_70 ( unsigned int V_5 , bool V_54 )
{
F_68 ( V_5 ) ;
}
static int F_71 ( unsigned int V_5 )
{
return F_38 ( V_23 ) !=
F_38 ( V_55 ) ;
}
static void F_72 ( unsigned int V_5 )
{
F_25 ( V_55 ,
F_38 ( V_23 ) ) ;
F_24 () ;
}
static void F_73 ( void )
{
F_74 ( & V_56 ) ;
if ( ! V_57 )
return;
F_75 ( & V_58 ,
& V_59 ) ;
}
static void F_76 ( void )
{
F_77 ( & V_59 ) ;
F_73 () ;
}
static void F_78 ( void )
{
F_79 ( & V_59 , & V_60 ) ;
F_73 () ;
}
static void F_80 ( void )
{
F_81 () ;
F_11 () ;
F_76 () ;
F_22 () ;
F_13 () ;
if ( V_6 && V_14 )
F_78 () ;
F_12 () ;
F_82 () ;
F_83 () ;
}
static T_1 void F_84 ( void )
{
int V_61 ;
F_13 () ;
if ( ! F_85 ( V_62 ) &&
! ( V_6 && V_14 ) )
return;
V_61 = F_86 ( & V_58 ,
& V_59 ) ;
if ( V_61 ) {
F_87 ( L_7 ) ;
return;
}
F_88 ( & V_56 ) ;
V_57 = true ;
F_80 () ;
F_89 ( & V_56 ) ;
}
static inline int F_90 ( void ) { return 0 ; }
static inline void F_91 ( void ) { }
static inline int F_92 ( void ) { return 0 ; }
static inline void F_93 ( void ) { }
static void F_80 ( void )
{
F_81 () ;
F_11 () ;
F_13 () ;
F_12 () ;
F_82 () ;
}
static inline void F_84 ( void )
{
F_80 () ;
}
static void F_83 ( void )
{
F_74 ( & V_56 ) ;
F_94 () ;
}
void F_95 ( void )
{
F_88 ( & V_56 ) ;
F_83 () ;
F_89 ( & V_56 ) ;
}
void F_96 ( void )
{
V_6 = 0 ;
}
static void F_97 ( void )
{
F_98 ( & V_60 , & V_60 , V_63 ) ;
F_80 () ;
}
static int F_99 ( int V_64 , struct V_65 * V_66 , int V_67 ,
void T_2 * V_68 , T_3 * V_69 , T_4 * V_70 )
{
int V_71 , V_72 , * V_44 = V_66 -> V_73 ;
F_88 ( & V_56 ) ;
if ( ! V_67 ) {
* V_44 = ( V_6 & V_64 ) != 0 ;
V_71 = F_100 ( V_66 , V_67 , V_68 , V_69 , V_70 ) ;
} else {
V_72 = F_101 ( * V_44 ) ;
V_71 = F_100 ( V_66 , V_67 , V_68 , V_69 , V_70 ) ;
if ( ! V_71 && V_72 != F_101 ( * V_44 ) )
F_97 () ;
}
F_89 ( & V_56 ) ;
return V_71 ;
}
int F_102 ( struct V_65 * V_66 , int V_67 ,
void T_2 * V_68 , T_3 * V_69 , T_4 * V_70 )
{
return F_99 ( V_9 | V_11 ,
V_66 , V_67 , V_68 , V_69 , V_70 ) ;
}
int F_103 ( struct V_65 * V_66 , int V_67 ,
void T_2 * V_68 , T_3 * V_69 , T_4 * V_70 )
{
if ( ! V_8 && V_67 )
return - V_74 ;
return F_99 ( V_9 ,
V_66 , V_67 , V_68 , V_69 , V_70 ) ;
}
int F_104 ( struct V_65 * V_66 , int V_67 ,
void T_2 * V_68 , T_3 * V_69 , T_4 * V_70 )
{
return F_99 ( V_11 ,
V_66 , V_67 , V_68 , V_69 , V_70 ) ;
}
int F_105 ( struct V_65 * V_66 , int V_67 ,
void T_2 * V_68 , T_3 * V_69 , T_4 * V_70 )
{
int V_71 , V_72 ;
F_88 ( & V_56 ) ;
V_72 = F_101 ( V_14 ) ;
V_71 = F_100 ( V_66 , V_67 , V_68 , V_69 , V_70 ) ;
if ( ! V_71 && V_67 && V_72 != F_101 ( V_14 ) )
F_97 () ;
F_89 ( & V_56 ) ;
return V_71 ;
}
int F_106 ( struct V_65 * V_66 , int V_67 ,
void T_2 * V_68 , T_3 * V_69 , T_4 * V_70 )
{
int V_71 ;
F_88 ( & V_56 ) ;
V_71 = F_107 ( V_66 , V_67 , V_68 , V_69 , V_70 ) ;
if ( ! V_71 && V_67 )
F_97 () ;
F_89 ( & V_56 ) ;
return V_71 ;
}
void T_1 F_108 ( void )
{
#ifdef F_109
if ( F_110 () ) {
F_111 ( L_8 ) ;
F_79 ( & V_60 , V_75 ) ;
} else
F_79 ( & V_60 , V_63 ) ;
#else
F_79 ( & V_60 , V_63 ) ;
#endif
if ( ! F_9 () )
V_8 = true ;
F_84 () ;
}
