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
int __weak F_3 ( unsigned int V_5 )
{
return 0 ;
}
void __weak F_4 ( unsigned int V_5 )
{
}
void __weak F_5 ( void )
{
}
static int T_1 F_6 ( char * V_3 )
{
V_6 = F_7 ( V_3 , NULL , 0 ) ;
return 1 ;
}
static int T_1 F_8 ( char * V_3 )
{
V_1 = 0 ;
return 1 ;
}
static int T_1 F_9 ( char * V_3 )
{
V_1 &= ~ V_7 ;
return 1 ;
}
static int T_1 F_10 ( char * V_3 )
{
V_8 =
! ! F_11 ( V_3 , NULL , 0 ) ;
return 1 ;
}
static int T_1 F_12 ( char * V_3 )
{
V_9 =
! ! F_11 ( V_3 , NULL , 0 ) ;
return 1 ;
}
static int F_13 ( void )
{
return V_10 * 2 ;
}
static unsigned long F_14 ( void )
{
return F_15 () >> 30LL ;
}
static void F_16 ( void )
{
V_11 = F_13 () * ( ( V_12 ) V_13 / 5 ) ;
F_17 ( V_11 ) ;
}
static void F_18 ( void )
{
F_19 ( V_14 , F_14 () ) ;
}
void F_20 ( void )
{
F_21 ( V_14 , 0 ) ;
}
void F_22 ( void )
{
F_20 () ;
F_23 ( F_24 () ) ;
}
void F_25 ( void )
{
int V_5 ;
F_26 (cpu)
F_27 ( V_14 , V_5 ) = 0 ;
F_23 ( - 1 ) ;
}
void F_28 ( void )
{
F_19 ( V_15 , true ) ;
F_19 ( V_14 , 0 ) ;
}
static int F_29 ( unsigned long V_16 )
{
unsigned long V_17 = F_14 () ;
if ( ( V_1 & V_7 ) && V_10 ) {
if ( F_30 ( V_17 , V_16 + F_13 () ) )
return V_17 - V_16 ;
}
return 0 ;
}
bool F_31 ( void )
{
unsigned long V_18 = F_32 ( V_19 ) ;
if ( F_32 ( V_20 ) == V_18 )
return true ;
F_19 ( V_20 , V_18 ) ;
return false ;
}
static void F_33 ( void )
{
F_34 ( V_19 ) ;
}
static enum V_21 F_35 ( struct V_22 * V_22 )
{
unsigned long V_16 = F_32 ( V_14 ) ;
struct V_23 * V_24 = F_36 () ;
int V_25 ;
int V_26 = V_8 ;
if ( F_37 ( & V_27 ) != 0 )
return V_28 ;
F_33 () ;
F_38 ( F_32 ( V_29 ) ) ;
F_39 ( V_22 , F_40 ( V_11 ) ) ;
if ( V_16 == 0 ) {
if ( F_41 ( F_32 ( V_15 ) ) ) {
F_19 ( V_15 , false ) ;
F_42 () ;
}
F_43 () ;
F_18 () ;
return V_30 ;
}
V_25 = F_29 ( V_16 ) ;
if ( F_41 ( V_25 ) ) {
if ( F_43 () )
return V_30 ;
if ( F_32 ( V_31 ) == true ) {
if ( F_32 ( V_32 ) !=
V_33 ) {
F_19 ( V_31 , false ) ;
F_18 () ;
}
return V_30 ;
}
if ( V_26 ) {
if ( F_44 ( 0 , & V_34 ) ) {
F_19 ( V_31 , true ) ;
return V_30 ;
}
}
F_45 ( L_5 ,
F_46 () , V_25 ,
V_33 -> V_35 , F_47 ( V_33 ) ) ;
F_19 ( V_32 , V_33 ) ;
F_48 () ;
F_49 ( V_33 ) ;
if ( V_24 )
F_50 ( V_24 ) ;
else
F_51 () ;
if ( V_26 ) {
F_52 () ;
F_53 ( 0 , & V_34 ) ;
F_54 () ;
}
F_55 ( V_36 , V_37 ) ;
if ( V_6 )
F_56 ( L_6 ) ;
F_19 ( V_31 , true ) ;
} else
F_19 ( V_31 , false ) ;
return V_30 ;
}
static void F_57 ( unsigned int V_38 , unsigned int V_39 )
{
struct V_40 V_41 = { . V_42 = V_39 } ;
F_58 ( V_33 , V_38 , & V_41 ) ;
}
static void F_59 ( unsigned int V_5 )
{
struct V_22 * V_22 = F_60 ( & V_43 ) ;
F_61 ( V_22 , V_44 , V_45 ) ;
V_22 -> V_46 = F_35 ;
F_3 ( V_5 ) ;
F_62 ( V_22 , F_40 ( V_11 ) ,
V_47 ) ;
F_57 ( V_48 , V_49 - 1 ) ;
F_18 () ;
}
static void F_63 ( unsigned int V_5 )
{
struct V_22 * V_22 = F_60 ( & V_43 ) ;
F_57 ( V_50 , 0 ) ;
F_64 ( V_22 ) ;
F_4 ( V_5 ) ;
}
static void F_65 ( unsigned int V_5 , bool V_51 )
{
F_63 ( V_5 ) ;
}
static int F_66 ( unsigned int V_5 )
{
return F_32 ( V_19 ) !=
F_32 ( V_52 ) ;
}
static void F_67 ( unsigned int V_5 )
{
F_19 ( V_52 ,
F_32 ( V_19 ) ) ;
F_18 () ;
if ( ! ( V_1 & V_2 ) )
F_4 ( V_5 ) ;
}
static int F_68 ( void )
{
int V_5 , V_53 = 0 ;
F_69 ( & V_27 , 1 ) ;
F_26 (cpu) {
V_53 = F_70 ( F_27 ( V_29 , V_5 ) ) ;
if ( V_53 )
break;
}
F_69 ( & V_27 , 0 ) ;
return V_53 ;
}
static void F_71 ( void )
{
int V_5 ;
F_26 (cpu)
F_72 ( F_27 ( V_29 , V_5 ) ) ;
}
static int F_73 ( void )
{
int V_53 ;
V_53 = F_68 () ;
if ( V_53 )
return V_53 ;
F_71 () ;
return 0 ;
}
static int F_74 ( void )
{
int V_54 = 0 ;
if ( ! V_55 ) {
V_54 = F_75 ( & V_56 ,
& V_57 ) ;
if ( V_54 )
F_76 ( L_7 ) ;
else
V_55 = 1 ;
} else {
V_54 = F_73 () ;
if ( V_54 ) {
F_77 () ;
F_76 ( L_8 ) ;
}
}
if ( V_54 )
V_1 = 0 ;
return V_54 ;
}
static void F_77 ( void )
{
if ( V_55 ) {
V_55 = 0 ;
F_78 ( & V_56 ) ;
}
}
static int F_79 ( void )
{
return F_80 (
& V_56 , & V_57 ) ;
}
static int F_68 ( void )
{
return 0 ;
}
static void F_71 ( void )
{
}
static int F_74 ( void )
{
return 0 ;
}
static void F_77 ( void )
{
}
static int F_79 ( void )
{
return 0 ;
}
static void F_16 ( void )
{
}
int F_81 ( void )
{
int V_53 = 0 ;
F_82 () ;
F_83 ( & V_58 ) ;
if ( V_55 && ! V_59 )
V_53 = F_68 () ;
if ( V_53 == 0 )
V_59 ++ ;
else {
F_77 () ;
F_76 ( L_9 ) ;
V_1 = 0 ;
}
F_5 () ;
F_84 ( & V_58 ) ;
return V_53 ;
}
void F_85 ( void )
{
F_83 ( & V_58 ) ;
V_59 -- ;
if ( V_55 && ! V_59 )
F_71 () ;
F_5 () ;
F_84 ( & V_58 ) ;
F_86 () ;
}
static int F_87 ( void )
{
int V_54 = 0 ;
if ( V_1 && V_10 )
V_54 = F_74 () ;
else
F_77 () ;
F_5 () ;
return V_54 ;
}
static int F_88 ( int V_60 , struct V_61 * V_62 , int V_63 ,
void T_2 * V_64 , T_3 * V_65 , T_4 * V_66 )
{
int V_54 , V_67 , V_68 ;
int * V_69 = ( int * ) V_62 -> V_70 ;
F_82 () ;
F_83 ( & V_58 ) ;
if ( V_59 ) {
V_54 = - V_71 ;
goto V_72;
}
if ( ! V_63 ) {
* V_69 = ( V_1 & V_60 ) != 0 ;
V_54 = F_89 ( V_62 , V_63 , V_64 , V_65 , V_66 ) ;
} else {
V_54 = F_89 ( V_62 , V_63 , V_64 , V_65 , V_66 ) ;
if ( V_54 )
goto V_72;
do {
V_67 = V_1 ;
if ( * V_69 )
V_68 = V_67 | V_60 ;
else
V_68 = V_67 & ~ V_60 ;
} while ( F_90 ( & V_1 , V_67 , V_68 ) != V_67 );
if ( V_67 == V_68 )
goto V_72;
V_54 = F_87 () ;
}
V_72:
F_84 ( & V_58 ) ;
F_86 () ;
return V_54 ;
}
int F_91 ( struct V_61 * V_62 , int V_63 ,
void T_2 * V_64 , T_3 * V_65 , T_4 * V_66 )
{
return F_88 ( V_2 | V_7 ,
V_62 , V_63 , V_64 , V_65 , V_66 ) ;
}
int F_92 ( struct V_61 * V_62 , int V_63 ,
void T_2 * V_64 , T_3 * V_65 , T_4 * V_66 )
{
return F_88 ( V_2 ,
V_62 , V_63 , V_64 , V_65 , V_66 ) ;
}
int F_93 ( struct V_61 * V_62 , int V_63 ,
void T_2 * V_64 , T_3 * V_65 , T_4 * V_66 )
{
return F_88 ( V_7 ,
V_62 , V_63 , V_64 , V_65 , V_66 ) ;
}
int F_94 ( struct V_61 * V_62 , int V_63 ,
void T_2 * V_64 , T_3 * V_65 , T_4 * V_66 )
{
int V_54 , V_67 , V_68 ;
F_82 () ;
F_83 ( & V_58 ) ;
if ( V_59 ) {
V_54 = - V_71 ;
goto V_72;
}
V_67 = F_95 ( V_10 ) ;
V_54 = F_89 ( V_62 , V_63 , V_64 , V_65 , V_66 ) ;
if ( V_54 || ! V_63 )
goto V_72;
V_68 = F_95 ( V_10 ) ;
if ( V_67 == V_68 )
goto V_72;
F_16 () ;
V_54 = F_87 () ;
if ( V_54 ) {
V_10 = V_67 ;
F_16 () ;
}
V_72:
F_84 ( & V_58 ) ;
F_86 () ;
return V_54 ;
}
int F_96 ( struct V_61 * V_62 , int V_63 ,
void T_2 * V_64 , T_3 * V_65 , T_4 * V_66 )
{
int V_54 ;
F_82 () ;
F_83 ( & V_58 ) ;
if ( V_59 ) {
V_54 = - V_71 ;
goto V_72;
}
V_54 = F_97 ( V_62 , V_63 , V_64 , V_65 , V_66 ) ;
if ( ! V_54 && V_63 ) {
F_98 ( & V_57 , & V_57 ,
V_73 ) ;
if ( V_55 ) {
if ( F_79 () != 0 )
F_76 ( L_10 ) ;
}
F_5 () ;
}
V_72:
F_84 ( & V_58 ) ;
F_86 () ;
return V_54 ;
}
void T_1 F_99 ( void )
{
F_16 () ;
#ifdef F_100
if ( F_101 () ) {
F_102 ( L_11 ) ;
F_103 ( & V_57 , V_74 ) ;
} else
F_103 ( & V_57 , V_73 ) ;
#else
F_103 ( & V_57 , V_73 ) ;
#endif
if ( V_1 )
F_74 () ;
}
