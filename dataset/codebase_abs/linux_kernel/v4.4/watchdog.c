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
int V_14 ;
F_19 (cpu)
F_20 ( V_13 , V_14 ) = 0 ;
}
void F_21 ( void )
{
F_17 ( V_15 , true ) ;
F_16 () ;
}
void F_22 ( void )
{
F_15 ( V_16 , true ) ;
F_15 ( V_13 , 0 ) ;
}
static bool F_23 ( void )
{
unsigned long V_17 = F_24 ( V_18 ) ;
if ( F_24 ( V_19 ) == V_17 )
return true ;
F_15 ( V_19 , V_17 ) ;
return false ;
}
static int F_25 ( unsigned long V_20 )
{
unsigned long V_21 = F_11 () ;
if ( ( V_1 & V_6 ) && V_9 ) {
if ( F_26 ( V_21 , V_20 + F_10 () ) )
return V_21 - V_20 ;
}
return 0 ;
}
static void F_27 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
struct V_26 * V_27 )
{
V_23 -> V_28 . V_29 = 0 ;
if ( F_24 ( V_15 ) == true ) {
F_15 ( V_15 , false ) ;
return;
}
if ( F_23 () ) {
int V_30 = F_28 () ;
struct V_26 * V_27 = F_29 () ;
if ( F_24 ( V_31 ) == true )
return;
F_30 ( L_5 , V_30 ) ;
F_31 () ;
F_32 ( V_32 ) ;
if ( V_27 )
F_33 ( V_27 ) ;
else
F_34 () ;
if ( V_8 &&
! F_35 ( 0 , & V_33 ) )
F_36 () ;
if ( V_4 )
F_37 ( L_6 ) ;
F_15 ( V_31 , true ) ;
return;
}
F_15 ( V_31 , false ) ;
return;
}
static void F_38 ( void )
{
F_39 ( V_18 ) ;
}
static enum V_34 F_40 ( struct V_35 * V_35 )
{
unsigned long V_20 = F_24 ( V_13 ) ;
struct V_26 * V_27 = F_29 () ;
int V_36 ;
int V_37 = V_7 ;
F_38 () ;
F_41 ( F_24 ( V_38 ) ) ;
F_42 ( V_35 , F_43 ( V_10 ) ) ;
if ( V_20 == 0 ) {
if ( F_44 ( F_24 ( V_16 ) ) ) {
F_15 ( V_16 , false ) ;
F_45 () ;
}
F_46 () ;
F_14 () ;
return V_39 ;
}
V_36 = F_25 ( V_20 ) ;
if ( F_44 ( V_36 ) ) {
if ( F_46 () )
return V_39 ;
if ( F_24 ( V_40 ) == true ) {
if ( F_24 ( V_41 ) !=
V_32 ) {
F_15 ( V_40 , false ) ;
F_14 () ;
}
return V_39 ;
}
if ( V_37 ) {
if ( F_35 ( 0 , & V_42 ) ) {
F_15 ( V_40 , true ) ;
return V_39 ;
}
}
F_30 ( L_7 ,
F_28 () , V_36 ,
V_32 -> V_43 , F_47 ( V_32 ) ) ;
F_15 ( V_41 , V_32 ) ;
F_31 () ;
F_32 ( V_32 ) ;
if ( V_27 )
F_33 ( V_27 ) ;
else
F_34 () ;
if ( V_37 ) {
F_36 () ;
F_48 ( 0 , & V_42 ) ;
F_49 () ;
}
F_50 ( V_44 , V_45 ) ;
if ( V_5 )
F_37 ( L_8 ) ;
F_15 ( V_40 , true ) ;
} else
F_15 ( V_40 , false ) ;
return V_39 ;
}
static void F_51 ( unsigned int V_46 , unsigned int V_47 )
{
struct V_48 V_49 = { . V_50 = V_47 } ;
F_52 ( V_32 , V_46 , & V_49 ) ;
}
static void F_53 ( unsigned int V_14 )
{
struct V_35 * V_35 = F_54 ( & V_51 ) ;
F_55 ( V_35 , V_52 , V_53 ) ;
V_35 -> V_54 = F_40 ;
F_56 ( V_14 ) ;
F_57 ( V_35 , F_43 ( V_10 ) ,
V_55 ) ;
F_51 ( V_56 , V_57 - 1 ) ;
F_14 () ;
}
static void F_58 ( unsigned int V_14 )
{
struct V_35 * V_35 = F_54 ( & V_51 ) ;
F_51 ( V_58 , 0 ) ;
F_59 ( V_35 ) ;
F_60 ( V_14 ) ;
}
static void F_61 ( unsigned int V_14 , bool V_59 )
{
F_58 ( V_14 ) ;
}
static int F_62 ( unsigned int V_14 )
{
return F_24 ( V_18 ) !=
F_24 ( V_60 ) ;
}
static void F_63 ( unsigned int V_14 )
{
F_15 ( V_60 ,
F_24 ( V_18 ) ) ;
F_14 () ;
if ( ! ( V_1 & V_2 ) )
F_60 ( V_14 ) ;
}
static int F_56 ( unsigned int V_14 )
{
struct V_61 * V_62 ;
struct V_22 * V_23 = F_20 ( V_63 , V_14 ) ;
if ( ! ( V_1 & V_2 ) )
goto V_64;
if ( V_23 && V_23 -> V_65 > V_66 )
goto V_64;
if ( V_23 != NULL )
goto V_67;
V_62 = & V_68 ;
V_62 -> V_10 = F_64 ( V_9 ) ;
V_23 = F_65 ( V_62 , V_14 , NULL , F_27 , NULL ) ;
if ( V_14 == 0 && F_66 ( V_23 ) )
V_69 = F_67 ( V_23 ) ;
if ( ! F_66 ( V_23 ) ) {
if ( V_14 == 0 || V_69 )
F_68 ( L_9 ) ;
goto V_70;
}
F_69 () ;
F_48 ( V_71 , & V_1 ) ;
F_49 () ;
if ( V_14 > 0 && ( F_67 ( V_23 ) == V_69 ) )
return F_67 ( V_23 ) ;
if ( F_67 ( V_23 ) == - V_72 )
F_68 ( L_10 , V_14 ) ;
else if ( F_67 ( V_23 ) == - V_73 )
F_70 ( L_11 ,
V_14 ) ;
else
F_71 ( L_12 ,
V_14 , F_67 ( V_23 ) ) ;
F_68 ( L_13 ) ;
return F_67 ( V_23 ) ;
V_70:
F_20 ( V_63 , V_14 ) = V_23 ;
V_67:
F_72 ( F_20 ( V_63 , V_14 ) ) ;
V_64:
return 0 ;
}
static void F_60 ( unsigned int V_14 )
{
struct V_22 * V_23 = F_20 ( V_63 , V_14 ) ;
if ( V_23 ) {
F_73 ( V_23 ) ;
F_20 ( V_63 , V_14 ) = NULL ;
F_74 ( V_23 ) ;
}
if ( V_14 == 0 ) {
V_69 = 0 ;
}
}
static int F_56 ( unsigned int V_14 ) { return 0 ; }
static void F_60 ( unsigned int V_14 ) { return; }
static int F_75 ( void )
{
int V_14 , V_74 = 0 ;
F_19 (cpu) {
V_74 = F_76 ( F_20 ( V_38 , V_14 ) ) ;
if ( V_74 )
break;
}
return V_74 ;
}
static void F_77 ( void )
{
int V_14 ;
F_19 (cpu)
F_78 ( F_20 ( V_38 , V_14 ) ) ;
}
int F_79 ( void )
{
int V_74 = 0 ;
F_80 () ;
F_81 ( & V_75 ) ;
if ( V_76 && ! V_77 )
V_74 = F_75 () ;
if ( V_74 == 0 )
V_77 ++ ;
else {
F_82 () ;
F_71 ( L_14 ) ;
V_1 = 0 ;
}
F_83 ( & V_75 ) ;
return V_74 ;
}
void F_84 ( void )
{
F_81 ( & V_75 ) ;
V_77 -- ;
if ( V_76 && ! V_77 )
F_77 () ;
F_83 ( & V_75 ) ;
F_85 () ;
}
static int F_86 ( void )
{
int V_74 ;
V_74 = F_75 () ;
if ( V_74 )
return V_74 ;
F_77 () ;
return 0 ;
}
static int F_87 ( void )
{
int V_78 = 0 ;
if ( ! V_76 ) {
V_78 = F_88 ( & V_79 ,
& V_80 ) ;
if ( V_78 )
F_71 ( L_15 ) ;
else
V_76 = 1 ;
} else {
V_78 = F_86 () ;
if ( V_78 ) {
F_82 () ;
F_71 ( L_16 ) ;
}
}
if ( V_78 )
V_1 = 0 ;
return V_78 ;
}
static void F_82 ( void )
{
if ( V_76 ) {
V_76 = 0 ;
F_89 ( & V_79 ) ;
}
}
static int F_90 ( void )
{
int V_78 = 0 ;
if ( V_1 && V_9 )
V_78 = F_87 () ;
else
F_82 () ;
return V_78 ;
}
static int F_91 ( int V_81 , struct V_82 * V_83 , int V_84 ,
void T_2 * V_85 , T_3 * V_86 , T_4 * V_87 )
{
int V_78 , V_88 , V_89 ;
int * V_90 = ( int * ) V_83 -> V_25 ;
F_80 () ;
F_81 ( & V_75 ) ;
if ( V_77 ) {
V_78 = - V_91 ;
goto V_64;
}
if ( ! V_84 ) {
* V_90 = ( V_1 & V_81 ) != 0 ;
V_78 = F_92 ( V_83 , V_84 , V_85 , V_86 , V_87 ) ;
} else {
V_78 = F_92 ( V_83 , V_84 , V_85 , V_86 , V_87 ) ;
if ( V_78 )
goto V_64;
do {
V_88 = V_1 ;
if ( * V_90 )
V_89 = V_88 | V_81 ;
else
V_89 = V_88 & ~ V_81 ;
} while ( F_93 ( & V_1 , V_88 , V_89 ) != V_88 );
V_78 = F_90 () ;
}
V_64:
F_83 ( & V_75 ) ;
F_85 () ;
return V_78 ;
}
int F_94 ( struct V_82 * V_83 , int V_84 ,
void T_2 * V_85 , T_3 * V_86 , T_4 * V_87 )
{
return F_91 ( V_2 | V_6 ,
V_83 , V_84 , V_85 , V_86 , V_87 ) ;
}
int F_95 ( struct V_82 * V_83 , int V_84 ,
void T_2 * V_85 , T_3 * V_86 , T_4 * V_87 )
{
return F_91 ( V_2 ,
V_83 , V_84 , V_85 , V_86 , V_87 ) ;
}
int F_96 ( struct V_82 * V_83 , int V_84 ,
void T_2 * V_85 , T_3 * V_86 , T_4 * V_87 )
{
return F_91 ( V_6 ,
V_83 , V_84 , V_85 , V_86 , V_87 ) ;
}
int F_97 ( struct V_82 * V_83 , int V_84 ,
void T_2 * V_85 , T_3 * V_86 , T_4 * V_87 )
{
int V_78 , V_88 ;
F_80 () ;
F_81 ( & V_75 ) ;
if ( V_77 ) {
V_78 = - V_91 ;
goto V_64;
}
V_88 = F_98 ( V_9 ) ;
V_78 = F_92 ( V_83 , V_84 , V_85 , V_86 , V_87 ) ;
if ( V_78 || ! V_84 )
goto V_64;
F_13 () ;
V_78 = F_90 () ;
if ( V_78 ) {
V_9 = V_88 ;
F_13 () ;
}
V_64:
F_83 ( & V_75 ) ;
F_85 () ;
return V_78 ;
}
int F_99 ( struct V_82 * V_83 , int V_84 ,
void T_2 * V_85 , T_3 * V_86 , T_4 * V_87 )
{
int V_78 ;
F_80 () ;
F_81 ( & V_75 ) ;
if ( V_77 ) {
V_78 = - V_91 ;
goto V_64;
}
V_78 = F_100 ( V_83 , V_84 , V_85 , V_86 , V_87 ) ;
if ( ! V_78 && V_84 ) {
F_101 ( & V_80 , & V_80 ,
V_92 ) ;
if ( V_76 ) {
if ( F_102 (
& V_79 , & V_80 ) != 0 )
F_71 ( L_17 ) ;
}
}
V_64:
F_83 ( & V_75 ) ;
F_85 () ;
return V_78 ;
}
void T_1 F_103 ( void )
{
F_13 () ;
#ifdef F_104
if ( F_105 () ) {
F_68 ( L_18 ) ;
F_106 ( & V_80 , V_93 ) ;
} else
F_106 ( & V_80 , V_92 ) ;
#else
F_106 ( & V_80 , V_92 ) ;
#endif
if ( V_1 )
F_87 () ;
}
