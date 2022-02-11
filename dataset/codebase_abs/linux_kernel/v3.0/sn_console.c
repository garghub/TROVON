static int F_1 ( void )
{
int V_1 ;
F_2 ( & V_1 ) ;
return V_1 ;
}
static int F_3 ( void )
{
int V_2 , V_3 ;
V_2 = F_4 ( & V_3 ) ;
return ! V_2 && V_3 ;
}
static int F_5 ( void )
{
return F_6 () ;
}
static int F_7 ( void )
{
return F_8 () & V_4 ;
}
static int F_9 ( const char * V_5 , int V_6 )
{
return F_10 ( V_5 , V_6 ) ;
}
static int F_11 ( const char * V_5 , int V_6 )
{
return F_12 ( ( char * ) V_5 , V_6 ) ;
}
static const char * F_13 ( struct V_7 * V_8 )
{
return ( L_1 ) ;
}
static unsigned int F_14 ( struct V_7 * V_8 )
{
return 1 ;
}
static void F_15 ( struct V_7 * V_8 )
{
}
static void F_16 ( struct V_7 * V_8 )
{
}
static void F_17 ( struct V_7 * V_8 )
{
}
static void F_18 ( struct V_7 * V_8 )
{
}
static void F_19 ( struct V_7 * V_8 , unsigned int V_9 )
{
}
static unsigned int F_20 ( struct V_7 * V_8 )
{
return V_10 | V_11 | V_12 | V_13 ;
}
static void F_21 ( struct V_7 * V_8 )
{
}
static void F_22 ( struct V_7 * V_8 )
{
if ( V_14 . V_15 -> V_16 )
V_14 . V_15 -> V_16 ( & V_14 ,
V_17 ) ;
}
static void F_23 ( struct V_7 * V_8 , int V_18 )
{
}
static int F_24 ( struct V_7 * V_8 )
{
return 0 ;
}
static void
F_25 ( struct V_7 * V_8 , struct V_19 * V_20 ,
struct V_19 * V_21 )
{
}
static int F_26 ( struct V_7 * V_8 )
{
return 0 ;
}
static void F_27 ( struct V_7 * V_8 , int V_22 )
{
}
static int F_28 ( const char * V_23 , ... )
{
static char V_24 [ 1024 ] ;
int V_25 ;
T_1 args ;
va_start ( args , V_23 ) ;
V_25 = vsnprintf ( V_24 , sizeof( V_24 ) , V_23 , args ) ;
if ( ! V_14 . V_15 ) {
V_14 . V_15 = & V_26 ;
F_29 () ;
}
V_14 . V_15 -> V_27 ( V_24 , V_25 ) ;
va_end ( args ) ;
return V_25 ;
}
static void
F_30 ( struct V_28 * V_8 , unsigned long V_22 )
{
int V_1 ;
struct V_29 * V_30 ;
if ( ! V_8 ) {
F_31 ( V_31 L_2 ) ;
return;
}
if ( ! V_8 -> V_15 ) {
F_31 ( V_31 L_3 ) ;
return;
}
if ( V_8 -> V_32 . V_33 ) {
V_30 = V_8 -> V_32 . V_33 -> V_8 . V_30 ;
}
else {
V_30 = NULL ;
}
while ( V_8 -> V_15 -> V_34 () ) {
V_1 = V_8 -> V_15 -> V_35 () ;
if ( V_1 < 0 ) {
F_31 ( V_31 L_4
L_5 , V_1 ) ;
break;
}
#ifdef F_32
if ( V_36 ) {
unsigned long V_37 = V_36 + V_38 * 5 ;
V_36 = 0 ;
if ( V_1 && F_33 ( V_39 , V_37 ) ) {
F_34 ( & V_8 -> V_32 . V_40 , V_22 ) ;
F_35 ( V_1 ) ;
F_36 ( & V_8 -> V_32 . V_40 , V_22 ) ;
continue;
}
}
if ( V_1 == * V_41 ) {
if ( ! ( * ++ V_41 ) ) {
V_36 = V_39 ;
V_41 = V_42 ;
}
if ( V_1 != '\e' )
continue;
}
else
V_41 = V_42 ;
#endif
if ( V_30 ) {
if( F_37 ( V_30 , V_1 , V_43 ) == 0 )
break;
}
V_8 -> V_32 . V_44 . V_45 ++ ;
}
if ( V_30 )
F_38 ( V_30 ) ;
}
static void F_39 ( struct V_28 * V_8 , int V_46 )
{
int V_47 , V_48 , V_49 , V_50 , V_51 ;
int V_52 ;
char * V_53 ;
struct V_54 * V_55 ;
if ( ! V_8 )
return;
F_40 ( ! V_8 -> V_56 ) ;
if ( V_8 -> V_32 . V_33 ) {
V_55 = & V_8 -> V_32 . V_33 -> V_55 ;
} else {
return;
}
if ( F_41 ( V_55 ) || F_42 ( & V_8 -> V_32 ) ) {
F_43 ( V_57 ) ;
return;
}
V_49 = V_55 -> V_49 ;
V_48 = V_55 -> V_48 ;
V_53 = & V_55 -> V_58 [ V_48 ] ;
V_50 = ( V_49 < V_48 ) ? 2 : 1 ;
for ( V_51 = 0 ; V_51 < V_50 ; V_51 ++ ) {
V_47 = ( V_49 < V_48 ) ?
( V_59 - V_48 ) : ( V_49 - V_48 ) ;
if ( V_47 > 0 ) {
if ( V_46 == V_60 )
V_52 =
V_8 -> V_15 -> V_27 ( V_53 ,
V_47 ) ;
else
V_52 =
V_8 -> V_15 -> V_61 ( V_53 , V_47 ) ;
#ifdef F_44
if ( ! V_52 )
F_45 ( L_6 ) ;
#endif
if ( V_52 > 0 ) {
V_47 -= V_52 ;
V_8 -> V_32 . V_44 . V_62 += V_52 ;
V_48 += V_52 ;
V_48 &= V_59 - 1 ;
V_55 -> V_48 = V_48 ;
V_53 = & V_55 -> V_58 [ V_48 ] ;
}
}
}
if ( F_46 ( V_55 ) < V_63 )
F_47 ( & V_8 -> V_32 ) ;
if ( F_41 ( V_55 ) )
F_15 ( & V_8 -> V_32 ) ;
}
static T_2 F_48 ( int V_64 , void * V_65 )
{
struct V_28 * V_8 = (struct V_28 * ) V_65 ;
unsigned long V_22 ;
int V_2 = F_8 () ;
if ( ! V_8 )
return V_66 ;
F_36 ( & V_8 -> V_32 . V_40 , V_22 ) ;
if ( V_2 & V_4 ) {
F_30 ( V_8 , V_22 ) ;
}
if ( V_2 & V_57 ) {
F_39 ( V_8 , V_17 ) ;
}
F_34 ( & V_8 -> V_32 . V_40 , V_22 ) ;
return V_67 ;
}
static void F_49 ( unsigned long V_68 )
{
struct V_28 * V_8 = (struct V_28 * ) V_68 ;
unsigned long V_22 ;
if ( ! V_8 )
return;
if ( ! V_8 -> V_32 . V_64 ) {
F_36 ( & V_8 -> V_32 . V_40 , V_22 ) ;
if ( V_69 )
F_30 ( V_8 , V_22 ) ;
F_39 ( V_8 , V_60 ) ;
F_34 ( & V_8 -> V_32 . V_40 , V_22 ) ;
F_50 ( & V_8 -> V_70 ,
V_39 + V_8 -> V_71 ) ;
}
}
static void T_3 F_51 ( struct V_28 * V_8 )
{
unsigned long V_22 ;
if ( ! V_8 )
return;
F_45 ( L_7 ) ;
F_36 ( & V_8 -> V_32 . V_40 , V_22 ) ;
if ( ! V_8 -> V_15 )
V_8 -> V_15 = & V_26 ;
F_52 ( & V_8 -> V_70 ) ;
V_8 -> V_70 . V_72 = F_49 ;
V_8 -> V_70 . V_68 = ( unsigned long ) V_8 ;
if ( F_53 () )
V_8 -> V_71 = 6 ;
else {
V_8 -> V_71 =
V_38 * V_73 / V_74 ;
}
F_50 ( & V_8 -> V_70 , V_39 + V_8 -> V_71 ) ;
V_8 -> V_56 = 1 ;
F_34 ( & V_8 -> V_32 . V_40 , V_22 ) ;
}
static void T_3 F_54 ( struct V_28 * V_8 )
{
unsigned long V_22 ;
if ( V_8 ) {
F_45 ( L_8 ) ;
if ( F_55 ( V_75 , F_48 ,
V_76 | V_77 ,
L_9 , V_8 ) >= 0 ) {
F_36 ( & V_8 -> V_32 . V_40 , V_22 ) ;
V_8 -> V_32 . V_64 = V_75 ;
V_8 -> V_15 = & V_78 ;
F_56 ( V_4 ) ;
F_34 ( & V_8 -> V_32 . V_40 , V_22 ) ;
}
else {
F_31 ( V_79
L_10 ) ;
}
}
}
static int T_3 F_57 ( void )
{
int V_80 ;
if ( ! F_58 ( L_11 ) )
return 0 ;
F_31 ( V_79 L_12 ) ;
if ( V_81 == 1 ) {
V_82 . V_83 = V_84 ;
V_82 . V_85 = V_86 ;
V_80 = F_59 ( & V_82 ) ;
if ( V_80 != 0 ) {
F_31 ( V_87 L_13
L_14 ) ;
return - V_88 ;
}
V_89 . V_90 = V_91 ;
V_89 . V_83 = V_82 . V_83 ;
} else {
V_89 . V_90 = V_92 ;
V_89 . V_83 = V_93 ;
}
if ( F_60 ( & V_89 ) < 0 ) {
F_31
( L_15 ,
__LINE__ ) ;
return - V_88 ;
}
F_61 ( & V_14 . V_32 . V_40 ) ;
V_14 . V_32 . V_94 = ( char * ) 1 ;
V_14 . V_32 . type = V_95 ;
V_14 . V_32 . V_96 = V_97 ;
V_14 . V_32 . V_98 = & V_99 ;
V_14 . V_32 . line = 0 ;
if ( F_62 ( & V_89 , & V_14 . V_32 ) < 0 ) {
F_31 ( V_31 L_16 , V_100 ) ;
}
if ( ! V_14 . V_56 ) {
F_51 ( & V_14 ) ;
}
if ( ! F_53 () ) {
F_54 ( & V_14 ) ;
}
V_69 = 1 ;
return 0 ;
}
static void T_4 F_63 ( void )
{
F_64 ( & V_14 . V_70 ) ;
F_65 ( & V_89 , & V_14 . V_32 ) ;
F_66 ( & V_89 ) ;
F_67 ( & V_82 ) ;
}
static void F_68 ( int (* F_69) ( const char * V_5 , int V_6 ) ,
const char * V_5 , int V_101 )
{
const char * V_102 ;
while ( ( V_102 = memchr ( V_5 , '\n' , V_101 ) ) != NULL ) {
F_69 ( V_5 , V_102 - V_5 ) ;
F_69 ( L_17 , 2 ) ;
V_101 -= V_102 + 1 - V_5 ;
V_5 = V_102 + 1 ;
}
F_69 ( V_5 , V_101 ) ;
}
static void
F_70 ( struct V_103 * V_104 , const char * V_5 , unsigned V_101 )
{
unsigned long V_22 = 0 ;
struct V_28 * V_8 = & V_14 ;
static int V_105 = 0 ;
F_40 ( ! V_8 -> V_56 ) ;
if ( ! V_8 -> V_32 . V_33 ) {
F_68 ( V_8 -> V_15 -> V_27 , V_5 , V_101 ) ;
return;
}
if ( F_71 ( & V_8 -> V_32 . V_40 ) ) {
int V_106 = V_8 -> V_32 . V_33 -> V_55 . V_49 ;
int V_107 = V_8 -> V_32 . V_33 -> V_55 . V_48 ;
int V_108 , V_109 = 0 ;
for ( V_108 = 0 ; V_108 < 150 ; F_72 ( 125 ) , V_108 ++ ) {
if ( ! F_71 ( & V_8 -> V_32 . V_40 )
|| V_105 ) {
if ( ! V_105 ) {
F_36 ( & V_8 -> V_32 . V_40 ,
V_22 ) ;
V_109 = 1 ;
}
break;
} else {
if ( ( V_106 != V_8 -> V_32 . V_33 -> V_55 . V_49 )
|| ( V_107 !=
V_8 -> V_32 . V_33 -> V_55 . V_48 ) ) {
V_106 =
V_8 -> V_32 . V_33 -> V_55 . V_49 ;
V_107 =
V_8 -> V_32 . V_33 -> V_55 . V_48 ;
V_108 = 0 ;
}
}
}
F_39 ( V_8 , 1 ) ;
if ( V_109 ) {
F_34 ( & V_8 -> V_32 . V_40 , V_22 ) ;
V_105 = 0 ;
} else {
V_105 = 1 ;
}
F_68 ( V_8 -> V_15 -> V_27 , V_5 , V_101 ) ;
} else {
V_105 = 0 ;
F_36 ( & V_8 -> V_32 . V_40 , V_22 ) ;
F_39 ( V_8 , 1 ) ;
F_34 ( & V_8 -> V_32 . V_40 , V_22 ) ;
F_68 ( V_8 -> V_15 -> V_27 , V_5 , V_101 ) ;
}
}
static int F_73 ( struct V_103 * V_104 , char * V_110 )
{
return 0 ;
}
static void T_3
F_74 ( struct V_103 * V_104 , const char * V_5 , unsigned V_101 )
{
F_68 ( V_14 . V_15 -> V_27 , V_5 , V_101 ) ;
}
int T_3 F_75 ( void )
{
if ( ! F_58 ( L_11 ) )
return - 1 ;
V_14 . V_15 = & V_26 ;
F_61 ( & V_14 . V_32 . V_40 ) ;
F_29 () ;
F_76 ( & V_111 ) ;
return 0 ;
}
static int T_3 F_77 ( void )
{
if ( F_58 ( L_11 ) ) {
F_51 ( & V_14 ) ;
F_45 ( L_18 ) ;
F_76 ( & V_112 ) ;
F_78 ( & V_111 ) ;
}
return 0 ;
}
