static int T_1 F_1 ( char * V_1 )
{
V_2 = F_2 ( V_1 , NULL , 0 ) ;
return 1 ;
}
static int T_1 F_3 ( char * V_1 )
{
V_3 = 0 ;
return 1 ;
}
static int T_1 F_4 ( char * V_1 )
{
V_3 &= ~ V_4 ;
return 1 ;
}
static int T_1 F_5 ( char * V_1 )
{
V_5 =
! ! F_6 ( V_1 , NULL , 0 ) ;
return 1 ;
}
static int T_1 F_7 ( char * V_1 )
{
V_6 =
! ! F_6 ( V_1 , NULL , 0 ) ;
return 1 ;
}
static int F_8 ( void )
{
return V_7 * 2 ;
}
static unsigned long F_9 ( void )
{
return F_10 () >> 30LL ;
}
static void F_11 ( void )
{
V_8 = F_8 () * ( ( V_9 ) V_10 / 5 ) ;
}
static void F_12 ( void )
{
F_13 ( V_11 , F_9 () ) ;
}
void F_14 ( void )
{
F_15 ( V_11 , 0 ) ;
}
void F_16 ( void )
{
F_14 () ;
F_17 ( F_18 () ) ;
}
void F_19 ( void )
{
int V_12 ;
F_20 (cpu)
F_21 ( V_11 , V_12 ) = 0 ;
F_17 ( - 1 ) ;
}
void F_22 ( void )
{
F_13 ( V_13 , true ) ;
F_13 ( V_11 , 0 ) ;
}
bool F_23 ( void )
{
unsigned long V_14 = F_24 ( V_15 ) ;
if ( F_24 ( V_16 ) == V_14 )
return true ;
F_13 ( V_16 , V_14 ) ;
return false ;
}
static int F_25 ( unsigned long V_17 )
{
unsigned long V_18 = F_9 () ;
if ( ( V_3 & V_4 ) && V_7 ) {
if ( F_26 ( V_18 , V_17 + F_8 () ) )
return V_18 - V_17 ;
}
return 0 ;
}
static void F_27 ( void )
{
F_28 ( V_15 ) ;
}
int __weak F_29 ( unsigned int V_12 )
{
return 0 ;
}
void __weak F_30 ( unsigned int V_12 )
{
}
static enum V_19 F_31 ( struct V_20 * V_20 )
{
unsigned long V_17 = F_24 ( V_11 ) ;
struct V_21 * V_22 = F_32 () ;
int V_23 ;
int V_24 = V_5 ;
if ( F_33 ( & V_25 ) != 0 )
return V_26 ;
F_27 () ;
F_34 ( F_24 ( V_27 ) ) ;
F_35 ( V_20 , F_36 ( V_8 ) ) ;
if ( V_17 == 0 ) {
if ( F_37 ( F_24 ( V_13 ) ) ) {
F_13 ( V_13 , false ) ;
F_38 () ;
}
F_39 () ;
F_12 () ;
return V_28 ;
}
V_23 = F_25 ( V_17 ) ;
if ( F_37 ( V_23 ) ) {
if ( F_39 () )
return V_28 ;
if ( F_24 ( V_29 ) == true ) {
if ( F_24 ( V_30 ) !=
V_31 ) {
F_13 ( V_29 , false ) ;
F_12 () ;
}
return V_28 ;
}
if ( V_24 ) {
if ( F_40 ( 0 , & V_32 ) ) {
F_13 ( V_29 , true ) ;
return V_28 ;
}
}
F_41 ( L_1 ,
F_42 () , V_23 ,
V_31 -> V_33 , F_43 ( V_31 ) ) ;
F_13 ( V_30 , V_31 ) ;
F_44 () ;
F_45 ( V_31 ) ;
if ( V_22 )
F_46 ( V_22 ) ;
else
F_47 () ;
if ( V_24 ) {
F_48 () ;
F_49 ( 0 , & V_32 ) ;
F_50 () ;
}
F_51 ( V_34 , V_35 ) ;
if ( V_2 )
F_52 ( L_2 ) ;
F_13 ( V_29 , true ) ;
} else
F_13 ( V_29 , false ) ;
return V_28 ;
}
static void F_53 ( unsigned int V_36 , unsigned int V_37 )
{
struct V_38 V_39 = { . V_40 = V_37 } ;
F_54 ( V_31 , V_36 , & V_39 ) ;
}
static void F_55 ( unsigned int V_12 )
{
struct V_20 * V_20 = F_56 ( & V_41 ) ;
F_57 ( V_20 , V_42 , V_43 ) ;
V_20 -> V_44 = F_31 ;
F_29 ( V_12 ) ;
F_58 ( V_20 , F_36 ( V_8 ) ,
V_45 ) ;
F_53 ( V_46 , V_47 - 1 ) ;
F_12 () ;
}
static void F_59 ( unsigned int V_12 )
{
struct V_20 * V_20 = F_56 ( & V_41 ) ;
F_53 ( V_48 , 0 ) ;
F_60 ( V_20 ) ;
F_30 ( V_12 ) ;
}
static void F_61 ( unsigned int V_12 , bool V_49 )
{
F_59 ( V_12 ) ;
}
static int F_62 ( unsigned int V_12 )
{
return F_24 ( V_15 ) !=
F_24 ( V_50 ) ;
}
static void F_63 ( unsigned int V_12 )
{
F_13 ( V_50 ,
F_24 ( V_15 ) ) ;
F_12 () ;
if ( ! ( V_3 & V_51 ) )
F_30 ( V_12 ) ;
}
static int F_64 ( void )
{
int V_12 , V_52 = 0 ;
F_65 ( & V_25 , 1 ) ;
F_20 (cpu) {
V_52 = F_66 ( F_21 ( V_27 , V_12 ) ) ;
if ( V_52 )
break;
}
F_65 ( & V_25 , 0 ) ;
return V_52 ;
}
static void F_67 ( void )
{
int V_12 ;
F_20 (cpu)
F_68 ( F_21 ( V_27 , V_12 ) ) ;
}
int F_69 ( void )
{
int V_52 = 0 ;
F_70 () ;
F_71 ( & V_53 ) ;
if ( V_54 && ! V_55 )
V_52 = F_64 () ;
if ( V_52 == 0 )
V_55 ++ ;
else {
F_72 () ;
F_73 ( L_3 ) ;
V_3 = 0 ;
}
F_74 ( & V_53 ) ;
return V_52 ;
}
void F_75 ( void )
{
F_71 ( & V_53 ) ;
V_55 -- ;
if ( V_54 && ! V_55 )
F_67 () ;
F_74 ( & V_53 ) ;
F_76 () ;
}
static int F_77 ( void )
{
int V_52 ;
V_52 = F_64 () ;
if ( V_52 )
return V_52 ;
F_67 () ;
return 0 ;
}
static int F_78 ( void )
{
int V_56 = 0 ;
if ( ! V_54 ) {
V_56 = F_79 ( & V_57 ,
& V_58 ) ;
if ( V_56 )
F_73 ( L_4 ) ;
else
V_54 = 1 ;
} else {
V_56 = F_77 () ;
if ( V_56 ) {
F_72 () ;
F_73 ( L_5 ) ;
}
}
if ( V_56 )
V_3 = 0 ;
return V_56 ;
}
static void F_72 ( void )
{
if ( V_54 ) {
V_54 = 0 ;
F_80 ( & V_57 ) ;
}
}
static int F_81 ( void )
{
int V_56 = 0 ;
if ( V_3 && V_7 )
V_56 = F_78 () ;
else
F_72 () ;
return V_56 ;
}
static int F_82 ( int V_59 , struct V_60 * V_61 , int V_62 ,
void T_2 * V_63 , T_3 * V_64 , T_4 * V_65 )
{
int V_56 , V_66 , V_67 ;
int * V_68 = ( int * ) V_61 -> V_69 ;
F_70 () ;
F_71 ( & V_53 ) ;
if ( V_55 ) {
V_56 = - V_70 ;
goto V_71;
}
if ( ! V_62 ) {
* V_68 = ( V_3 & V_59 ) != 0 ;
V_56 = F_83 ( V_61 , V_62 , V_63 , V_64 , V_65 ) ;
} else {
V_56 = F_83 ( V_61 , V_62 , V_63 , V_64 , V_65 ) ;
if ( V_56 )
goto V_71;
do {
V_66 = V_3 ;
if ( * V_68 )
V_67 = V_66 | V_59 ;
else
V_67 = V_66 & ~ V_59 ;
} while ( F_84 ( & V_3 , V_66 , V_67 ) != V_66 );
if ( V_66 == V_67 )
goto V_71;
V_56 = F_81 () ;
}
V_71:
F_74 ( & V_53 ) ;
F_76 () ;
return V_56 ;
}
int F_85 ( struct V_60 * V_61 , int V_62 ,
void T_2 * V_63 , T_3 * V_64 , T_4 * V_65 )
{
return F_82 ( V_51 | V_4 ,
V_61 , V_62 , V_63 , V_64 , V_65 ) ;
}
int F_86 ( struct V_60 * V_61 , int V_62 ,
void T_2 * V_63 , T_3 * V_64 , T_4 * V_65 )
{
return F_82 ( V_51 ,
V_61 , V_62 , V_63 , V_64 , V_65 ) ;
}
int F_87 ( struct V_60 * V_61 , int V_62 ,
void T_2 * V_63 , T_3 * V_64 , T_4 * V_65 )
{
return F_82 ( V_4 ,
V_61 , V_62 , V_63 , V_64 , V_65 ) ;
}
int F_88 ( struct V_60 * V_61 , int V_62 ,
void T_2 * V_63 , T_3 * V_64 , T_4 * V_65 )
{
int V_56 , V_66 , V_67 ;
F_70 () ;
F_71 ( & V_53 ) ;
if ( V_55 ) {
V_56 = - V_70 ;
goto V_71;
}
V_66 = F_89 ( V_7 ) ;
V_56 = F_83 ( V_61 , V_62 , V_63 , V_64 , V_65 ) ;
if ( V_56 || ! V_62 )
goto V_71;
V_67 = F_89 ( V_7 ) ;
if ( V_66 == V_67 )
goto V_71;
F_11 () ;
V_56 = F_81 () ;
if ( V_56 ) {
V_7 = V_66 ;
F_11 () ;
}
V_71:
F_74 ( & V_53 ) ;
F_76 () ;
return V_56 ;
}
int F_90 ( struct V_60 * V_61 , int V_62 ,
void T_2 * V_63 , T_3 * V_64 , T_4 * V_65 )
{
int V_56 ;
F_70 () ;
F_71 ( & V_53 ) ;
if ( V_55 ) {
V_56 = - V_70 ;
goto V_71;
}
V_56 = F_91 ( V_61 , V_62 , V_63 , V_64 , V_65 ) ;
if ( ! V_56 && V_62 ) {
F_92 ( & V_58 , & V_58 ,
V_72 ) ;
if ( V_54 ) {
if ( F_93 (
& V_57 , & V_58 ) != 0 )
F_73 ( L_6 ) ;
}
}
V_71:
F_74 ( & V_53 ) ;
F_76 () ;
return V_56 ;
}
void T_1 F_94 ( void )
{
F_11 () ;
#ifdef F_95
if ( F_96 () ) {
F_97 ( L_7 ) ;
F_98 ( & V_58 , V_73 ) ;
} else
F_98 ( & V_58 , V_72 ) ;
#else
F_98 ( & V_58 , V_72 ) ;
#endif
if ( V_3 )
F_78 () ;
}
