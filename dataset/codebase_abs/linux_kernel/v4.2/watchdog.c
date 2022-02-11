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
static int F_9 ( void )
{
return V_8 * 2 ;
}
static unsigned long F_10 ( void )
{
return F_11 () >> 30LL ;
}
static void F_12 ( void )
{
V_9 = F_9 () * ( ( V_10 ) V_11 / 5 ) ;
}
static void F_13 ( void )
{
F_14 ( V_12 , F_10 () ) ;
}
void F_15 ( void )
{
F_16 ( V_12 , 0 ) ;
}
void F_17 ( void )
{
int V_13 ;
F_18 (cpu)
F_19 ( V_12 , V_13 ) = 0 ;
}
void F_20 ( void )
{
F_16 ( V_14 , true ) ;
F_15 () ;
}
void F_21 ( void )
{
F_14 ( V_15 , true ) ;
F_14 ( V_12 , 0 ) ;
}
static int F_22 ( void )
{
unsigned long V_16 = F_23 ( V_17 ) ;
if ( F_23 ( V_18 ) == V_16 )
return 1 ;
F_14 ( V_18 , V_16 ) ;
return 0 ;
}
static int F_24 ( unsigned long V_19 )
{
unsigned long V_20 = F_10 () ;
if ( V_1 & V_6 ) {
if ( F_25 ( V_20 , V_19 + F_9 () ) )
return V_20 - V_19 ;
}
return 0 ;
}
static void F_26 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
struct V_25 * V_26 )
{
V_22 -> V_27 . V_28 = 0 ;
if ( F_23 ( V_14 ) == true ) {
F_14 ( V_14 , false ) ;
return;
}
if ( F_22 () ) {
int V_29 = F_27 () ;
if ( F_23 ( V_30 ) == true )
return;
if ( V_4 )
F_28 ( L_5 ,
V_29 ) ;
else
F_29 ( 1 , L_5 ,
V_29 ) ;
F_14 ( V_30 , true ) ;
return;
}
F_14 ( V_30 , false ) ;
return;
}
static void F_30 ( void )
{
F_31 ( V_17 ) ;
}
static enum V_31 F_32 ( struct V_32 * V_32 )
{
unsigned long V_19 = F_23 ( V_12 ) ;
struct V_25 * V_26 = F_33 () ;
int V_33 ;
int V_34 = V_7 ;
F_30 () ;
F_34 ( F_23 ( V_35 ) ) ;
F_35 ( V_32 , F_36 ( V_9 ) ) ;
if ( V_19 == 0 ) {
if ( F_37 ( F_23 ( V_15 ) ) ) {
F_14 ( V_15 , false ) ;
F_38 () ;
}
F_39 () ;
F_13 () ;
return V_36 ;
}
V_33 = F_24 ( V_19 ) ;
if ( F_37 ( V_33 ) ) {
if ( F_39 () )
return V_36 ;
if ( F_23 ( V_37 ) == true ) {
if ( F_23 ( V_38 ) !=
V_39 ) {
F_14 ( V_37 , false ) ;
F_13 () ;
}
return V_36 ;
}
if ( V_34 ) {
if ( F_40 ( 0 , & V_40 ) ) {
F_14 ( V_37 , true ) ;
return V_36 ;
}
}
F_41 ( L_6 ,
F_27 () , V_33 ,
V_39 -> V_41 , F_42 ( V_39 ) ) ;
F_14 ( V_38 , V_39 ) ;
F_43 () ;
F_44 ( V_39 ) ;
if ( V_26 )
F_45 ( V_26 ) ;
else
F_46 () ;
if ( V_34 ) {
F_47 () ;
F_48 ( 0 , & V_40 ) ;
F_49 () ;
}
F_50 ( V_42 , V_43 ) ;
if ( V_5 )
F_28 ( L_7 ) ;
F_14 ( V_37 , true ) ;
} else
F_14 ( V_37 , false ) ;
return V_36 ;
}
static void F_51 ( unsigned int V_44 , unsigned int V_45 )
{
struct V_46 V_47 = { . V_48 = V_45 } ;
F_52 ( V_39 , V_44 , & V_47 ) ;
}
static void F_53 ( unsigned int V_13 )
{
struct V_32 * V_32 = F_54 ( & V_49 ) ;
F_55 ( V_32 , V_50 , V_51 ) ;
V_32 -> V_52 = F_32 ;
F_56 ( V_13 ) ;
F_57 ( V_32 , F_36 ( V_9 ) ,
V_53 ) ;
F_51 ( V_54 , V_55 - 1 ) ;
F_13 () ;
}
static void F_58 ( unsigned int V_13 )
{
struct V_32 * V_32 = F_54 ( & V_49 ) ;
F_51 ( V_56 , 0 ) ;
F_59 ( V_32 ) ;
F_60 ( V_13 ) ;
}
static void F_61 ( unsigned int V_13 , bool V_57 )
{
F_58 ( V_13 ) ;
}
static int F_62 ( unsigned int V_13 )
{
return F_23 ( V_17 ) !=
F_23 ( V_58 ) ;
}
static void F_63 ( unsigned int V_13 )
{
F_14 ( V_58 ,
F_23 ( V_17 ) ) ;
F_13 () ;
if ( ! ( V_1 & V_2 ) )
F_60 ( V_13 ) ;
}
static int F_56 ( unsigned int V_13 )
{
struct V_59 * V_60 ;
struct V_21 * V_22 = F_19 ( V_61 , V_13 ) ;
if ( ! ( V_1 & V_2 ) )
goto V_62;
if ( V_22 && V_22 -> V_63 > V_64 )
goto V_62;
if ( V_22 != NULL )
goto V_65;
V_60 = & V_66 ;
V_60 -> V_9 = F_64 ( V_8 ) ;
V_22 = F_65 ( V_60 , V_13 , NULL , F_26 , NULL ) ;
if ( V_13 == 0 && F_66 ( V_22 ) )
V_67 = F_67 ( V_22 ) ;
if ( ! F_66 ( V_22 ) ) {
if ( V_13 == 0 || V_67 )
F_68 ( L_8 ) ;
goto V_68;
}
F_69 () ;
F_48 ( V_69 , & V_1 ) ;
F_49 () ;
if ( V_13 > 0 && ( F_67 ( V_22 ) == V_67 ) )
return F_67 ( V_22 ) ;
if ( F_67 ( V_22 ) == - V_70 )
F_68 ( L_9 , V_13 ) ;
else if ( F_67 ( V_22 ) == - V_71 )
F_70 ( L_10 ,
V_13 ) ;
else
F_71 ( L_11 ,
V_13 , F_67 ( V_22 ) ) ;
F_68 ( L_12 ) ;
return F_67 ( V_22 ) ;
V_68:
F_19 ( V_61 , V_13 ) = V_22 ;
V_65:
F_72 ( F_19 ( V_61 , V_13 ) ) ;
V_62:
return 0 ;
}
static void F_60 ( unsigned int V_13 )
{
struct V_21 * V_22 = F_19 ( V_61 , V_13 ) ;
if ( V_22 ) {
F_73 ( V_22 ) ;
F_19 ( V_61 , V_13 ) = NULL ;
F_74 ( V_22 ) ;
}
if ( V_13 == 0 ) {
V_67 = 0 ;
}
}
void F_75 ( void )
{
int V_13 ;
F_76 ( & V_72 ) ;
if ( ! ( V_1 & V_2 ) )
goto V_73;
F_77 () ;
F_18 (cpu)
F_56 ( V_13 ) ;
F_78 () ;
V_73:
F_79 ( & V_72 ) ;
}
void F_80 ( void )
{
int V_13 ;
F_76 ( & V_72 ) ;
if ( ! V_74 )
goto V_73;
F_77 () ;
F_18 (cpu)
F_60 ( V_13 ) ;
F_78 () ;
V_73:
F_79 ( & V_72 ) ;
}
static int F_56 ( unsigned int V_13 ) { return 0 ; }
static void F_60 ( unsigned int V_13 ) { return; }
void F_75 ( void ) {}
void F_80 ( void ) {}
static void F_81 ( void * V_75 )
{
struct V_32 * V_32 = F_54 ( & V_49 ) ;
int V_76 ;
V_76 = F_82 ( V_32 ) ;
if ( V_76 == 1 )
F_57 ( V_32 , F_36 ( V_9 ) ,
V_53 ) ;
}
static void F_83 ( int V_13 )
{
F_60 ( V_13 ) ;
F_84 ( V_13 , F_81 , NULL , 1 ) ;
F_56 ( V_13 ) ;
}
static void F_85 ( void )
{
int V_13 ;
F_77 () ;
F_18 (cpu)
F_83 ( V_13 ) ;
F_78 () ;
}
static int F_86 ( void )
{
int V_77 = 0 ;
if ( ! V_74 ) {
V_77 = F_87 ( & V_78 ) ;
if ( V_77 )
F_71 ( L_13 ) ;
else {
if ( F_88 (
& V_78 , & V_79 ) )
F_71 ( L_14 ) ;
V_74 = 1 ;
}
} else {
F_85 () ;
}
return V_77 ;
}
static void F_89 ( void )
{
if ( V_74 ) {
V_74 = 0 ;
F_90 ( & V_78 ) ;
}
}
static int F_91 ( void )
{
int V_77 = 0 ;
if ( V_1 && V_8 )
V_77 = F_86 () ;
else
F_89 () ;
return V_77 ;
}
static int F_92 ( int V_80 , struct V_81 * V_82 , int V_83 ,
void T_2 * V_84 , T_3 * V_85 , T_4 * V_86 )
{
int V_77 , V_87 , V_88 ;
int * V_89 = ( int * ) V_82 -> V_24 ;
F_76 ( & V_72 ) ;
if ( ! V_83 ) {
* V_89 = ( V_1 & V_80 ) != 0 ;
V_77 = F_93 ( V_82 , V_83 , V_84 , V_85 , V_86 ) ;
} else {
V_77 = F_93 ( V_82 , V_83 , V_84 , V_85 , V_86 ) ;
if ( V_77 )
goto V_62;
do {
V_87 = V_1 ;
if ( * V_89 )
V_88 = V_87 | V_80 ;
else
V_88 = V_87 & ~ V_80 ;
} while ( F_94 ( & V_1 , V_87 , V_88 ) != V_87 );
V_77 = F_91 () ;
if ( V_77 )
V_1 = V_87 ;
}
V_62:
F_79 ( & V_72 ) ;
return V_77 ;
}
int F_95 ( struct V_81 * V_82 , int V_83 ,
void T_2 * V_84 , T_3 * V_85 , T_4 * V_86 )
{
return F_92 ( V_2 | V_6 ,
V_82 , V_83 , V_84 , V_85 , V_86 ) ;
}
int F_96 ( struct V_81 * V_82 , int V_83 ,
void T_2 * V_84 , T_3 * V_85 , T_4 * V_86 )
{
return F_92 ( V_2 ,
V_82 , V_83 , V_84 , V_85 , V_86 ) ;
}
int F_97 ( struct V_81 * V_82 , int V_83 ,
void T_2 * V_84 , T_3 * V_85 , T_4 * V_86 )
{
return F_92 ( V_6 ,
V_82 , V_83 , V_84 , V_85 , V_86 ) ;
}
int F_98 ( struct V_81 * V_82 , int V_83 ,
void T_2 * V_84 , T_3 * V_85 , T_4 * V_86 )
{
int V_77 , V_87 ;
F_76 ( & V_72 ) ;
V_87 = F_99 ( V_8 ) ;
V_77 = F_93 ( V_82 , V_83 , V_84 , V_85 , V_86 ) ;
if ( V_77 || ! V_83 )
goto V_62;
F_12 () ;
V_77 = F_91 () ;
if ( V_77 )
V_8 = V_87 ;
V_62:
F_79 ( & V_72 ) ;
return V_77 ;
}
int F_100 ( struct V_81 * V_82 , int V_83 ,
void T_2 * V_84 , T_3 * V_85 , T_4 * V_86 )
{
int V_77 ;
F_76 ( & V_72 ) ;
V_77 = F_101 ( V_82 , V_83 , V_84 , V_85 , V_86 ) ;
if ( ! V_77 && V_83 ) {
F_102 ( & V_79 , & V_79 ,
V_90 ) ;
if ( V_74 ) {
if ( F_88 (
& V_78 , & V_79 ) != 0 )
F_71 ( L_15 ) ;
}
}
F_79 ( & V_72 ) ;
return V_77 ;
}
void T_1 F_103 ( void )
{
F_12 () ;
#ifdef F_104
if ( F_105 () ) {
if ( ! F_106 ( V_91 ) )
F_68 ( L_16 ) ;
F_107 ( & V_79 , V_90 ,
V_91 ) ;
} else
F_108 ( & V_79 , V_90 ) ;
#else
F_108 ( & V_79 , V_90 ) ;
#endif
if ( V_1 )
F_86 () ;
}
