void F_1 ( void )
{
V_1 &= ~ V_2 ;
}
static int T_1 F_2 ( char * V_3 )
{
if ( ! strncmp ( V_3 , L_1 , 5 ) )
V_4 = 1 ;
else if ( ! strncmp ( V_3 , L_2 , 7 ) )
V_4 = 0 ;
else if ( ! strncmp ( V_3 , L_3 , 1 ) )
V_1 &= ~ V_2 ;
else if ( ! strncmp ( V_3 , L_4 , 1 ) )
V_1 |= V_2 ;
return 1 ;
}
static int T_1 F_3 ( char * V_3 )
{
V_5 = F_4 ( V_3 , NULL , 0 ) ;
return 1 ;
}
static int T_1 F_5 ( char * V_3 )
{
V_1 = 0 ;
return 1 ;
}
static int T_1 F_6 ( char * V_3 )
{
V_1 &= ~ V_6 ;
return 1 ;
}
static int T_1 F_7 ( char * V_3 )
{
V_7 =
! ! F_8 ( V_3 , NULL , 0 ) ;
return 1 ;
}
static int T_1 F_9 ( char * V_3 )
{
V_8 =
! ! F_8 ( V_3 , NULL , 0 ) ;
return 1 ;
}
static int F_10 ( void )
{
return V_9 * 2 ;
}
static unsigned long F_11 ( void )
{
return F_12 () >> 30LL ;
}
static void F_13 ( void )
{
V_10 = F_10 () * ( ( V_11 ) V_12 / 5 ) ;
}
static void F_14 ( void )
{
F_15 ( V_13 , F_11 () ) ;
}
void F_16 ( void )
{
F_17 ( V_13 , 0 ) ;
}
void F_18 ( void )
{
F_16 () ;
F_19 ( F_20 () ) ;
}
void F_21 ( void )
{
int V_14 ;
F_22 (cpu)
F_23 ( V_13 , V_14 ) = 0 ;
F_19 ( - 1 ) ;
}
void F_24 ( void )
{
F_17 ( V_15 , true ) ;
F_18 () ;
}
void F_25 ( void )
{
F_15 ( V_16 , true ) ;
F_15 ( V_13 , 0 ) ;
}
static bool F_26 ( void )
{
unsigned long V_17 = F_27 ( V_18 ) ;
if ( F_27 ( V_19 ) == V_17 )
return true ;
F_15 ( V_19 , V_17 ) ;
return false ;
}
static int F_28 ( unsigned long V_20 )
{
unsigned long V_21 = F_11 () ;
if ( ( V_1 & V_6 ) && V_9 ) {
if ( F_29 ( V_21 , V_20 + F_10 () ) )
return V_21 - V_20 ;
}
return 0 ;
}
static void F_30 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
struct V_26 * V_27 )
{
V_23 -> V_28 . V_29 = 0 ;
if ( F_27 ( V_15 ) == true ) {
F_15 ( V_15 , false ) ;
return;
}
if ( F_26 () ) {
int V_30 = F_31 () ;
struct V_26 * V_27 = F_32 () ;
if ( F_27 ( V_31 ) == true )
return;
F_33 ( L_5 , V_30 ) ;
F_34 () ;
F_35 ( V_32 ) ;
if ( V_27 )
F_36 ( V_27 ) ;
else
F_37 () ;
if ( V_8 &&
! F_38 ( 0 , & V_33 ) )
F_39 () ;
if ( V_4 )
F_40 ( V_27 , L_6 ) ;
F_15 ( V_31 , true ) ;
return;
}
F_15 ( V_31 , false ) ;
return;
}
static void F_41 ( void )
{
F_42 ( V_18 ) ;
}
static enum V_34 F_43 ( struct V_35 * V_35 )
{
unsigned long V_20 = F_27 ( V_13 ) ;
struct V_26 * V_27 = F_32 () ;
int V_36 ;
int V_37 = V_7 ;
F_41 () ;
F_44 ( F_27 ( V_38 ) ) ;
F_45 ( V_35 , F_46 ( V_10 ) ) ;
if ( V_20 == 0 ) {
if ( F_47 ( F_27 ( V_16 ) ) ) {
F_15 ( V_16 , false ) ;
F_48 () ;
}
F_49 () ;
F_14 () ;
return V_39 ;
}
V_36 = F_28 ( V_20 ) ;
if ( F_47 ( V_36 ) ) {
if ( F_49 () )
return V_39 ;
if ( F_27 ( V_40 ) == true ) {
if ( F_27 ( V_41 ) !=
V_32 ) {
F_15 ( V_40 , false ) ;
F_14 () ;
}
return V_39 ;
}
if ( V_37 ) {
if ( F_38 ( 0 , & V_42 ) ) {
F_15 ( V_40 , true ) ;
return V_39 ;
}
}
F_33 ( L_7 ,
F_31 () , V_36 ,
V_32 -> V_43 , F_50 ( V_32 ) ) ;
F_15 ( V_41 , V_32 ) ;
F_34 () ;
F_35 ( V_32 ) ;
if ( V_27 )
F_36 ( V_27 ) ;
else
F_37 () ;
if ( V_37 ) {
F_39 () ;
F_51 ( 0 , & V_42 ) ;
F_52 () ;
}
F_53 ( V_44 , V_45 ) ;
if ( V_5 )
F_54 ( L_8 ) ;
F_15 ( V_40 , true ) ;
} else
F_15 ( V_40 , false ) ;
return V_39 ;
}
static void F_55 ( unsigned int V_46 , unsigned int V_47 )
{
struct V_48 V_49 = { . V_50 = V_47 } ;
F_56 ( V_32 , V_46 , & V_49 ) ;
}
static void F_57 ( unsigned int V_14 )
{
struct V_35 * V_35 = F_58 ( & V_51 ) ;
F_59 ( V_35 , V_52 , V_53 ) ;
V_35 -> V_54 = F_43 ;
F_60 ( V_14 ) ;
F_61 ( V_35 , F_46 ( V_10 ) ,
V_55 ) ;
F_55 ( V_56 , V_57 - 1 ) ;
F_14 () ;
}
static void F_62 ( unsigned int V_14 )
{
struct V_35 * V_35 = F_58 ( & V_51 ) ;
F_55 ( V_58 , 0 ) ;
F_63 ( V_35 ) ;
F_64 ( V_14 ) ;
}
static void F_65 ( unsigned int V_14 , bool V_59 )
{
F_62 ( V_14 ) ;
}
static int F_66 ( unsigned int V_14 )
{
return F_27 ( V_18 ) !=
F_27 ( V_60 ) ;
}
static void F_67 ( unsigned int V_14 )
{
F_15 ( V_60 ,
F_27 ( V_18 ) ) ;
F_14 () ;
if ( ! ( V_1 & V_2 ) )
F_64 ( V_14 ) ;
}
static int F_60 ( unsigned int V_14 )
{
struct V_61 * V_62 ;
struct V_22 * V_23 = F_23 ( V_63 , V_14 ) ;
if ( ! ( V_1 & V_2 ) )
goto V_64;
if ( V_23 && V_23 -> V_65 > V_66 )
goto V_64;
if ( V_23 != NULL )
goto V_67;
V_62 = & V_68 ;
V_62 -> V_10 = F_68 ( V_9 ) ;
V_23 = F_69 ( V_62 , V_14 , NULL , F_30 , NULL ) ;
if ( V_14 == 0 && F_70 ( V_23 ) )
V_69 = F_71 ( V_23 ) ;
if ( ! F_70 ( V_23 ) ) {
if ( V_14 == 0 || V_69 )
F_72 ( L_9 ) ;
goto V_70;
}
F_73 () ;
F_51 ( V_71 , & V_1 ) ;
F_52 () ;
if ( V_14 > 0 && ( F_71 ( V_23 ) == V_69 ) )
return F_71 ( V_23 ) ;
if ( F_71 ( V_23 ) == - V_72 )
F_72 ( L_10 , V_14 ) ;
else if ( F_71 ( V_23 ) == - V_73 )
F_74 ( L_11 ,
V_14 ) ;
else
F_75 ( L_12 ,
V_14 , F_71 ( V_23 ) ) ;
F_72 ( L_13 ) ;
return F_71 ( V_23 ) ;
V_70:
F_23 ( V_63 , V_14 ) = V_23 ;
V_67:
F_76 ( F_23 ( V_63 , V_14 ) ) ;
V_64:
return 0 ;
}
static void F_64 ( unsigned int V_14 )
{
struct V_22 * V_23 = F_23 ( V_63 , V_14 ) ;
if ( V_23 ) {
F_77 ( V_23 ) ;
F_23 ( V_63 , V_14 ) = NULL ;
F_78 ( V_23 ) ;
}
if ( V_14 == 0 ) {
V_69 = 0 ;
}
}
static int F_60 ( unsigned int V_14 ) { return 0 ; }
static void F_64 ( unsigned int V_14 ) { return; }
static int F_79 ( void )
{
int V_14 , V_74 = 0 ;
F_22 (cpu) {
V_74 = F_80 ( F_23 ( V_38 , V_14 ) ) ;
if ( V_74 )
break;
}
return V_74 ;
}
static void F_81 ( void )
{
int V_14 ;
F_22 (cpu)
F_82 ( F_23 ( V_38 , V_14 ) ) ;
}
int F_83 ( void )
{
int V_74 = 0 ;
F_84 () ;
F_85 ( & V_75 ) ;
if ( V_76 && ! V_77 )
V_74 = F_79 () ;
if ( V_74 == 0 )
V_77 ++ ;
else {
F_86 () ;
F_75 ( L_14 ) ;
V_1 = 0 ;
}
F_87 ( & V_75 ) ;
return V_74 ;
}
void F_88 ( void )
{
F_85 ( & V_75 ) ;
V_77 -- ;
if ( V_76 && ! V_77 )
F_81 () ;
F_87 ( & V_75 ) ;
F_89 () ;
}
static int F_90 ( void )
{
int V_74 ;
V_74 = F_79 () ;
if ( V_74 )
return V_74 ;
F_81 () ;
return 0 ;
}
static int F_91 ( void )
{
int V_78 = 0 ;
if ( ! V_76 ) {
V_78 = F_92 ( & V_79 ,
& V_80 ) ;
if ( V_78 )
F_75 ( L_15 ) ;
else
V_76 = 1 ;
} else {
V_78 = F_90 () ;
if ( V_78 ) {
F_86 () ;
F_75 ( L_16 ) ;
}
}
if ( V_78 )
V_1 = 0 ;
return V_78 ;
}
static void F_86 ( void )
{
if ( V_76 ) {
V_76 = 0 ;
F_93 ( & V_79 ) ;
}
}
static int F_94 ( void )
{
int V_78 = 0 ;
if ( V_1 && V_9 )
V_78 = F_91 () ;
else
F_86 () ;
return V_78 ;
}
static int F_95 ( int V_81 , struct V_82 * V_83 , int V_84 ,
void T_2 * V_85 , T_3 * V_86 , T_4 * V_87 )
{
int V_78 , V_88 , V_89 ;
int * V_90 = ( int * ) V_83 -> V_25 ;
F_84 () ;
F_85 ( & V_75 ) ;
if ( V_77 ) {
V_78 = - V_91 ;
goto V_64;
}
if ( ! V_84 ) {
* V_90 = ( V_1 & V_81 ) != 0 ;
V_78 = F_96 ( V_83 , V_84 , V_85 , V_86 , V_87 ) ;
} else {
V_78 = F_96 ( V_83 , V_84 , V_85 , V_86 , V_87 ) ;
if ( V_78 )
goto V_64;
do {
V_88 = V_1 ;
if ( * V_90 )
V_89 = V_88 | V_81 ;
else
V_89 = V_88 & ~ V_81 ;
} while ( F_97 ( & V_1 , V_88 , V_89 ) != V_88 );
V_78 = F_94 () ;
}
V_64:
F_87 ( & V_75 ) ;
F_89 () ;
return V_78 ;
}
int F_98 ( struct V_82 * V_83 , int V_84 ,
void T_2 * V_85 , T_3 * V_86 , T_4 * V_87 )
{
return F_95 ( V_2 | V_6 ,
V_83 , V_84 , V_85 , V_86 , V_87 ) ;
}
int F_99 ( struct V_82 * V_83 , int V_84 ,
void T_2 * V_85 , T_3 * V_86 , T_4 * V_87 )
{
return F_95 ( V_2 ,
V_83 , V_84 , V_85 , V_86 , V_87 ) ;
}
int F_100 ( struct V_82 * V_83 , int V_84 ,
void T_2 * V_85 , T_3 * V_86 , T_4 * V_87 )
{
return F_95 ( V_6 ,
V_83 , V_84 , V_85 , V_86 , V_87 ) ;
}
int F_101 ( struct V_82 * V_83 , int V_84 ,
void T_2 * V_85 , T_3 * V_86 , T_4 * V_87 )
{
int V_78 , V_88 ;
F_84 () ;
F_85 ( & V_75 ) ;
if ( V_77 ) {
V_78 = - V_91 ;
goto V_64;
}
V_88 = F_102 ( V_9 ) ;
V_78 = F_96 ( V_83 , V_84 , V_85 , V_86 , V_87 ) ;
if ( V_78 || ! V_84 )
goto V_64;
F_13 () ;
V_78 = F_94 () ;
if ( V_78 ) {
V_9 = V_88 ;
F_13 () ;
}
V_64:
F_87 ( & V_75 ) ;
F_89 () ;
return V_78 ;
}
int F_103 ( struct V_82 * V_83 , int V_84 ,
void T_2 * V_85 , T_3 * V_86 , T_4 * V_87 )
{
int V_78 ;
F_84 () ;
F_85 ( & V_75 ) ;
if ( V_77 ) {
V_78 = - V_91 ;
goto V_64;
}
V_78 = F_104 ( V_83 , V_84 , V_85 , V_86 , V_87 ) ;
if ( ! V_78 && V_84 ) {
F_105 ( & V_80 , & V_80 ,
V_92 ) ;
if ( V_76 ) {
if ( F_106 (
& V_79 , & V_80 ) != 0 )
F_75 ( L_17 ) ;
}
}
V_64:
F_87 ( & V_75 ) ;
F_89 () ;
return V_78 ;
}
void T_1 F_107 ( void )
{
F_13 () ;
#ifdef F_108
if ( F_109 () ) {
F_72 ( L_18 ) ;
F_110 ( & V_80 , V_93 ) ;
} else
F_110 ( & V_80 , V_92 ) ;
#else
F_110 ( & V_80 , V_92 ) ;
#endif
if ( V_1 )
F_91 () ;
}
