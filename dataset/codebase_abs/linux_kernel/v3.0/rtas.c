static unsigned long F_1 ( void )
{
unsigned long V_1 ;
F_2 ( V_1 ) ;
F_3 () ;
F_4 ( & V_2 . V_3 , V_1 ) ;
return V_1 ;
}
static void F_5 ( unsigned long V_1 )
{
F_6 ( & V_2 . V_3 ) ;
F_7 ( V_1 ) ;
F_8 () ;
}
static void F_9 ( char V_4 )
{
struct V_5 * args = & V_2 . args ;
unsigned long V_6 ;
if ( ! V_2 . V_7 )
return;
V_6 = F_1 () ;
args -> V_8 = 10 ;
args -> V_9 = 1 ;
args -> V_10 = 1 ;
args -> V_11 = ( V_12 * ) & ( args -> args [ 1 ] ) ;
args -> args [ 0 ] = ( unsigned char ) V_4 ;
F_10 ( F_11 ( args ) ) ;
F_5 ( V_6 ) ;
}
static void F_12 ( char V_4 )
{
static int V_13 = 0 ;
static int V_14 = 16 ;
if ( V_4 == '\n' ) {
while ( V_14 -- > 0 )
F_9 ( ' ' ) ;
V_14 = 16 ;
F_13 ( 500 ) ;
V_13 = 1 ;
} else {
if ( V_13 ) {
F_9 ( '\r' ) ;
F_9 ( '\n' ) ;
}
V_13 = 0 ;
if ( V_14 -- ) {
F_9 ( V_4 ) ;
F_14 ( 10000 ) ;
}
}
}
void T_1 F_15 ( void )
{
V_15 = F_12 ;
}
static void F_16 ( char V_4 )
{
int V_16 ;
if ( ! V_2 . V_7 )
return;
if ( V_4 == '\n' )
F_16 ( '\r' ) ;
for ( V_16 = 0 ; V_16 < 16 ; V_16 ++ ) {
if ( F_17 ( V_17 , 1 , 1 , NULL , V_4 ) == 0 )
break;
F_14 ( 1000 ) ;
}
}
static int F_18 ( void )
{
int V_4 ;
if ( ! V_2 . V_7 )
return - 1 ;
if ( F_17 ( V_18 , 0 , 2 , & V_4 ) )
return - 1 ;
return V_4 ;
}
static int F_19 ( void )
{
int V_4 ;
while ( ( V_4 = F_18 () ) == - 1 )
;
return V_4 ;
}
void T_1 F_20 ( void )
{
V_15 = F_16 ;
V_19 = F_19 ;
V_20 = F_18 ;
}
void F_21 ( char * V_6 , unsigned short V_21 )
{
struct V_22 * V_23 ;
int V_14 ;
const int * V_24 ;
char * V_25 ;
static int V_26 , V_27 ;
static int V_28 , V_29 , V_30 ;
static const int * V_31 ;
static F_22 ( V_32 ) ;
static int V_33 ;
static int V_13 = 0 ;
if ( ! V_2 . V_7 )
return;
if ( V_28 == 0 ) {
V_28 = 0x10 ;
if ( ( V_23 = F_23 ( L_1 ) ) ) {
if ( ( V_24 = F_24 ( V_23 ,
L_2 , NULL ) ) )
V_28 = * V_24 ;
if ( ( V_24 = F_24 ( V_23 ,
L_3 , NULL ) ) )
V_30 = * V_24 ;
if ( ( V_24 = F_24 ( V_23 ,
L_4 , NULL ) ) )
V_29 = * V_24 ;
V_31 = F_24 ( V_23 ,
L_5 , NULL ) ;
F_25 ( V_23 ) ;
}
V_26 = F_26 ( L_6 ) ;
V_27 = F_26 ( L_7 ) ;
}
if ( V_26 == V_34 ) {
if ( V_27 != V_34 )
F_17 ( V_27 , 3 , 1 , NULL , 6 , 0 , V_21 ) ;
return;
}
F_27 ( & V_32 ) ;
if ( V_13 ) {
F_17 ( V_26 , 1 , 1 , NULL , '\r' ) ;
F_17 ( V_26 , 1 , 1 , NULL , '\n' ) ;
V_13 = 0 ;
} else {
V_33 = 0 ;
if ( V_30 )
F_17 ( V_26 , 1 , 1 , NULL ,
( char ) V_30 ) ;
else
F_17 ( V_26 , 1 , 1 , NULL , '\r' ) ;
}
if ( V_31 )
V_14 = V_31 [ V_33 ] ;
else
V_14 = V_28 ;
V_25 = V_6 ;
while ( * V_25 ) {
if ( * V_25 == '\n' || * V_25 == '\r' ) {
if ( * V_25 == '\n' && ! V_25 [ 1 ] ) {
V_13 = 1 ;
V_33 ++ ;
if ( V_33 > V_29 - 1 )
V_33 = V_29 - 1 ;
F_28 ( & V_32 ) ;
return;
}
if ( * V_25 == '\n' ) {
F_17 ( V_26 , 1 , 1 , NULL , '\r' ) ;
F_17 ( V_26 , 1 , 1 , NULL , '\n' ) ;
} else {
F_17 ( V_26 , 1 , 1 , NULL , * V_25 ) ;
}
if ( V_31 )
V_14 = V_31 [ V_33 ] ;
else
V_14 = V_28 ;
} else {
V_14 -- ;
F_17 ( V_26 , 1 , 1 , NULL , * V_25 ) ;
}
V_25 ++ ;
if ( V_14 <= 0 )
while ( ( * V_25 != 0 ) && ( * V_25 != '\n' ) && ( * V_25 != '\r' ) )
V_25 ++ ;
}
F_28 ( & V_32 ) ;
}
int F_26 ( const char * V_35 )
{
const int * V_36 ;
if ( V_2 . V_37 == NULL )
return V_34 ;
V_36 = F_24 ( V_2 . V_37 , V_35 , NULL ) ;
return V_36 ? * V_36 : V_34 ;
}
int F_29 ( const char * V_35 )
{
return F_26 ( V_35 ) != V_34 ;
}
int F_30 ( void )
{
static int V_38 ;
if ( V_38 )
return V_38 ;
V_38 = F_26 ( L_8 ) ;
if ( ( V_38 == V_34 ) ||
( V_38 > V_39 ) ) {
F_31 ( V_40 L_9 ,
V_38 ) ;
V_38 = V_39 ;
}
return V_38 ;
}
static char * F_32 ( char * V_41 )
{
struct V_5 V_42 , V_43 ;
T_2 V_44 ;
char * V_45 = NULL ;
if ( V_46 == - 1 )
return NULL ;
V_44 = F_30 () ;
V_42 . V_8 = V_46 ;
V_42 . V_9 = 2 ;
V_42 . V_10 = 1 ;
V_42 . args [ 0 ] = ( V_12 ) F_11 ( V_47 ) ;
V_42 . args [ 1 ] = V_44 ;
V_42 . args [ 2 ] = 0 ;
V_43 = V_2 . args ;
V_2 . args = V_42 ;
F_10 ( F_11 ( & V_2 . args ) ) ;
V_42 = V_2 . args ;
V_2 . args = V_43 ;
if ( F_33 ( V_42 . args [ 2 ] == 0 ) ) {
if ( V_41 ) {
V_45 = V_41 ;
} else {
V_45 = V_47 ;
if ( V_48 )
V_45 = F_34 ( V_39 , V_49 ) ;
}
if ( V_45 )
memcpy ( V_45 , V_47 , V_39 ) ;
}
return V_45 ;
}
int F_17 ( int V_8 , int V_9 , int V_10 , int * V_50 , ... )
{
T_3 V_51 ;
int V_52 ;
unsigned long V_6 ;
struct V_5 * V_5 ;
char * V_53 = NULL ;
int V_54 ;
if ( ! V_2 . V_55 || V_8 == V_34 )
return - 1 ;
V_6 = F_1 () ;
V_5 = & V_2 . args ;
V_5 -> V_8 = V_8 ;
V_5 -> V_9 = V_9 ;
V_5 -> V_10 = V_10 ;
V_5 -> V_11 = ( V_12 * ) & ( V_5 -> args [ V_9 ] ) ;
va_start ( V_51 , V_50 ) ;
for ( V_52 = 0 ; V_52 < V_9 ; ++ V_52 )
V_5 -> args [ V_52 ] = va_arg ( V_51 , V_12 ) ;
va_end ( V_51 ) ;
for ( V_52 = 0 ; V_52 < V_10 ; ++ V_52 )
V_5 -> V_11 [ V_52 ] = 0 ;
F_10 ( F_11 ( V_5 ) ) ;
if ( V_5 -> V_11 [ 0 ] == - 1 )
V_53 = F_32 ( NULL ) ;
if ( V_10 > 1 && V_50 != NULL )
for ( V_52 = 0 ; V_52 < V_10 - 1 ; ++ V_52 )
V_50 [ V_52 ] = V_5 -> V_11 [ V_52 + 1 ] ;
V_54 = ( V_10 > 0 ) ? V_5 -> V_11 [ 0 ] : 0 ;
F_5 ( V_6 ) ;
if ( V_53 ) {
F_35 ( V_53 , V_56 , 0 ) ;
if ( V_48 )
F_36 ( V_53 ) ;
}
return V_54 ;
}
unsigned int F_37 ( int V_57 )
{
int V_58 ;
unsigned int V_59 = 0 ;
if ( V_57 == V_60 ) {
V_59 = 1 ;
} else if ( V_57 >= 9900 && V_57 <= 9905 ) {
V_58 = V_57 - 9900 ;
for ( V_59 = 1 ; V_58 > 0 ; V_58 -- )
V_59 *= 10 ;
}
return V_59 ;
}
unsigned int F_38 ( int V_57 )
{
unsigned int V_59 ;
F_39 () ;
V_59 = F_37 ( V_57 ) ;
if ( V_59 && F_40 () )
F_41 ( V_59 ) ;
return V_59 ;
}
static int F_42 ( int V_61 )
{
int V_62 ;
switch ( V_61 ) {
case - 1 :
V_62 = - V_63 ;
break;
case - 3 :
V_62 = - V_64 ;
break;
case - 9000 :
V_62 = - V_65 ;
break;
case - 9001 :
V_62 = - V_66 ;
break;
case - 9002 :
V_62 = - V_67 ;
break;
default:
F_31 ( V_68 L_10 ,
V_69 , V_61 ) ;
V_62 = - V_70 ;
break;
}
return V_62 ;
}
int F_43 ( int V_71 , int * V_72 )
{
int V_8 = F_26 ( L_11 ) ;
int V_62 ;
if ( V_8 == V_34 )
return - V_73 ;
while ( ( V_62 = F_17 ( V_8 , 1 , 2 , V_72 , V_71 ) ) == V_60 )
F_14 ( 1 ) ;
if ( V_62 < 0 )
return F_42 ( V_62 ) ;
return V_62 ;
}
int F_44 ( int V_71 , int V_72 , int * V_74 )
{
int V_8 = F_26 ( L_12 ) ;
int V_62 ;
if ( V_8 == V_34 )
return - V_73 ;
do {
V_62 = F_17 ( V_8 , 2 , 2 , V_74 , V_71 , V_72 ) ;
} while ( F_38 ( V_62 ) );
if ( V_62 < 0 )
return F_42 ( V_62 ) ;
return V_62 ;
}
int F_45 ( int V_75 , int V_76 , int * V_77 )
{
int V_8 = F_26 ( L_13 ) ;
int V_62 ;
if ( V_8 == V_34 )
return - V_73 ;
do {
V_62 = F_17 ( V_8 , 2 , 2 , V_77 , V_75 , V_76 ) ;
} while ( F_38 ( V_62 ) );
if ( V_62 < 0 )
return F_42 ( V_62 ) ;
return V_62 ;
}
bool F_46 ( int V_8 , int * V_78 )
{
int V_79 , V_80 , V_52 ;
const struct V_81 {
T_2 V_8 ;
T_2 V_78 ;
} * V_82 ;
V_82 = F_24 ( V_2 . V_37 , L_14 , & V_79 ) ;
if ( ! V_82 )
return false ;
V_80 = V_79 / sizeof( struct V_81 ) ;
for ( V_52 = 0 ; V_52 < V_80 ; V_52 ++ ) {
if ( V_82 [ V_52 ] . V_8 != V_8 )
continue;
if ( V_78 )
* V_78 = V_82 [ V_52 ] . V_78 ;
return true ;
}
return false ;
}
int F_47 ( int V_83 , int V_76 , int V_84 )
{
int V_8 = F_26 ( L_7 ) ;
int V_62 ;
if ( V_8 == V_34 )
return - V_73 ;
do {
V_62 = F_17 ( V_8 , 3 , 1 , NULL , V_83 , V_76 , V_84 ) ;
} while ( F_38 ( V_62 ) );
if ( V_62 < 0 )
return F_42 ( V_62 ) ;
return V_62 ;
}
int F_48 ( int V_83 , int V_76 , int V_84 )
{
int V_62 ;
int V_8 = F_26 ( L_7 ) ;
if ( V_8 == V_34 )
return - V_73 ;
V_62 = F_17 ( V_8 , 3 , 1 , NULL , V_83 , V_76 , V_84 ) ;
F_49 ( V_62 == - 2 || ( V_62 >= 9900 && V_62 <= 9905 ) ) ;
if ( V_62 < 0 )
return F_42 ( V_62 ) ;
return V_62 ;
}
void F_50 ( char * V_85 )
{
if ( V_86 )
V_86 ( V_87 ) ;
F_31 ( L_15 ,
F_17 ( F_26 ( L_16 ) , 0 , 1 , NULL ) ) ;
for (; ; ) ;
}
void F_51 ( void )
{
if ( V_86 )
V_86 ( V_88 ) ;
F_31 ( L_17 ,
F_17 ( F_26 ( L_18 ) , 2 , 1 , NULL , - 1 , - 1 ) ) ;
for (; ; ) ;
}
void F_52 ( void )
{
if ( V_86 )
V_86 ( V_89 ) ;
F_31 ( L_17 ,
F_17 ( F_26 ( L_18 ) , 2 , 1 , NULL , - 1 , - 1 ) ) ;
for (; ; ) ;
}
void F_53 ( char * V_90 )
{
int V_57 ;
if ( V_34 == F_26 ( L_19 ) ||
V_34 == F_26 ( L_20 ) )
return;
snprintf ( V_91 , 2048 , L_21 , V_90 ) ;
do {
V_57 = F_17 ( F_26 ( L_19 ) , 1 , 1 , NULL ,
F_11 ( V_91 ) ) ;
} while ( F_38 ( V_57 ) );
if ( V_57 != 0 )
F_31 ( V_92 L_22 , V_57 ) ;
}
static int F_54 ( struct V_93 * V_94 , int V_95 )
{
T_4 V_96 = V_97 ;
int V_62 = V_98 ;
int V_99 ;
F_55 ( V_100 ) ;
F_56 () ;
F_31 ( V_101 L_23 , F_57 () ) ;
while ( V_62 == V_98 && ! F_58 ( & V_94 -> V_102 ) &&
! F_58 ( & V_94 -> error ) )
V_62 = F_17 ( V_94 -> V_8 , 0 , 1 , NULL ) ;
if ( V_62 || F_58 ( & V_94 -> error ) ) {
F_31 ( V_101 L_24 , V_62 ) ;
F_55 ( V_96 ) ;
}
if ( F_58 ( & V_94 -> error ) )
V_62 = F_58 ( & V_94 -> error ) ;
F_59 ( & V_94 -> error , V_62 ) ;
F_60 () ;
F_61 () ;
if ( V_95 ) {
F_59 ( & V_94 -> V_102 , 1 ) ;
F_62 (cpu)
F_63 ( V_103 , F_64 ( V_99 ) ) ;
}
if ( F_65 ( & V_94 -> V_104 ) == 0 )
F_66 ( V_94 -> F_66 ) ;
return V_62 ;
}
int F_67 ( struct V_93 * V_94 )
{
F_68 ( & V_94 -> V_104 ) ;
return F_54 ( V_94 , 0 ) ;
}
static int F_69 ( struct V_93 * V_94 , int V_95 )
{
long V_62 = V_105 ;
unsigned long V_106 ;
int V_99 ;
F_68 ( & V_94 -> V_104 ) ;
V_106 = F_70 () ;
F_71 ( V_106 & ~ ( V_107 ) ) ;
while ( V_62 == V_105 && ! F_58 ( & V_94 -> V_102 ) && ! F_58 ( & V_94 -> error ) )
V_62 = F_63 ( V_108 ) ;
F_71 ( V_106 ) ;
if ( V_62 == V_105 ) {
goto V_109;
} else if ( V_62 == V_110 ) {
return F_54 ( V_94 , V_95 ) ;
} else {
F_31 ( V_68 L_25 ,
F_57 () , V_62 ) ;
F_59 ( & V_94 -> error , V_62 ) ;
}
if ( V_95 ) {
F_59 ( & V_94 -> V_102 , 1 ) ;
F_62 (cpu)
F_63 ( V_103 , F_64 ( V_99 ) ) ;
}
V_109:
if ( F_65 ( & V_94 -> V_104 ) == 0 )
F_66 ( V_94 -> F_66 ) ;
return V_62 ;
}
int F_72 ( struct V_93 * V_94 )
{
return F_69 ( V_94 , 0 ) ;
}
static void F_73 ( void * V_111 )
{
F_69 ( (struct V_93 * ) V_111 , 1 ) ;
}
int F_74 ( struct V_5 * args )
{
long V_77 ;
long V_62 ;
unsigned long V_112 [ V_113 ] ;
struct V_93 V_94 ;
F_75 ( V_102 ) ;
if ( ! F_29 ( L_26 ) )
return - V_114 ;
V_62 = F_76 ( V_115 , V_112 ,
( ( V_116 ) args -> args [ 0 ] << 32 ) | args -> args [ 1 ] ) ;
V_77 = V_112 [ 0 ] ;
if ( V_62 ) {
F_31 ( V_68 L_27 , V_62 ) ;
return V_62 ;
} else if ( V_77 == V_117 ) {
args -> args [ args -> V_9 ] = V_118 ;
return 0 ;
} else if ( V_77 != V_119 ) {
F_31 ( V_68 L_28 ,
V_77 ) ;
args -> args [ args -> V_9 ] = - 1 ;
return 0 ;
}
F_59 ( & V_94 . V_104 , 0 ) ;
F_59 ( & V_94 . V_102 , 0 ) ;
F_59 ( & V_94 . error , 0 ) ;
V_94 . V_8 = F_26 ( L_26 ) ;
V_94 . F_66 = & V_102 ;
if ( F_77 ( F_73 , & V_94 , 0 ) )
F_59 ( & V_94 . error , - V_64 ) ;
F_78 ( & V_102 ) ;
if ( F_58 ( & V_94 . error ) != 0 )
F_31 ( V_68 L_29 ) ;
return F_58 ( & V_94 . error ) ;
}
int F_74 ( struct V_5 * args )
{
return - V_114 ;
}
T_5 int F_79 ( struct V_5 T_6 * V_120 )
{
struct V_5 args ;
unsigned long V_1 ;
char * V_53 , * V_121 = NULL ;
int V_9 ;
int V_62 ;
if ( ! F_80 ( V_122 ) )
return - V_123 ;
if ( F_81 ( & args , V_120 , 3 * sizeof( T_2 ) ) != 0 )
return - V_65 ;
V_9 = args . V_9 ;
if ( V_9 > F_82 ( args . args )
|| args . V_10 > F_82 ( args . args )
|| V_9 + args . V_10 > F_82 ( args . args ) )
return - V_64 ;
if ( F_81 ( args . args , V_120 -> args ,
V_9 * sizeof( V_12 ) ) != 0 )
return - V_65 ;
if ( args . V_8 == V_34 )
return - V_64 ;
args . V_11 = & args . args [ V_9 ] ;
memset ( args . V_11 , 0 , args . V_10 * sizeof( V_12 ) ) ;
if ( args . V_8 == V_124 ) {
V_62 = F_74 ( & args ) ;
if ( V_62 )
return V_62 ;
goto V_125;
}
V_53 = F_83 () ;
V_1 = F_1 () ;
V_2 . args = args ;
F_10 ( F_11 ( & V_2 . args ) ) ;
args = V_2 . args ;
if ( args . V_11 [ 0 ] == - 1 )
V_121 = F_32 ( V_53 ) ;
F_5 ( V_1 ) ;
if ( V_53 ) {
if ( V_121 )
F_35 ( V_121 , V_56 , 0 ) ;
F_36 ( V_53 ) ;
}
V_125:
if ( F_84 ( V_120 -> args + V_9 ,
args . args + V_9 ,
args . V_10 * sizeof( V_12 ) ) != 0 )
return - V_65 ;
return 0 ;
}
void T_1 F_85 ( void )
{
unsigned long V_126 = V_127 ;
V_2 . V_37 = F_86 ( NULL , L_30 ) ;
if ( V_2 . V_37 ) {
const T_2 * V_128 , * V_129 , * V_130 ;
V_128 = F_24 ( V_2 . V_37 , L_31 , NULL ) ;
V_130 = F_24 ( V_2 . V_37 , L_32 , NULL ) ;
if ( V_128 != NULL && V_130 != NULL ) {
V_2 . V_7 = * V_128 ;
V_2 . V_131 = * V_130 ;
V_129 = F_24 ( V_2 . V_37 ,
L_33 , NULL ) ;
if ( V_129 == NULL )
V_2 . V_55 = V_2 . V_7 ;
else
V_2 . V_55 = * V_129 ;
} else
V_2 . V_37 = NULL ;
}
if ( ! V_2 . V_37 )
return;
#ifdef F_87
if ( F_88 ( V_132 ) && F_89 ( V_133 ) ) {
V_126 = F_90 ( V_134 , V_127 ) ;
V_124 = F_26 ( L_26 ) ;
}
#endif
V_135 = F_91 ( V_136 , V_137 , V_126 ) ;
#ifdef F_92
V_46 = F_26 ( L_34 ) ;
#endif
}
int T_1 F_93 ( unsigned long V_138 ,
const char * V_139 , int V_140 , void * V_94 )
{
T_2 * V_128 , * V_129 , * V_130 ;
if ( V_140 != 1 || strcmp ( V_139 , L_30 ) != 0 )
return 0 ;
V_128 = F_94 ( V_138 , L_31 , NULL ) ;
V_129 = F_94 ( V_138 , L_33 , NULL ) ;
V_130 = F_94 ( V_138 , L_32 , NULL ) ;
if ( V_128 && V_129 && V_130 ) {
V_2 . V_7 = * V_128 ;
V_2 . V_55 = * V_129 ;
V_2 . V_131 = * V_130 ;
}
#ifdef F_95
V_128 = F_94 ( V_138 , L_35 , NULL ) ;
if ( V_128 )
V_17 = * V_128 ;
V_128 = F_94 ( V_138 , L_36 , NULL ) ;
if ( V_128 )
V_18 = * V_128 ;
if ( V_17 != V_34 &&
V_18 != V_34 )
F_20 () ;
#endif
return 1 ;
}
void T_7 F_96 ( void )
{
unsigned long V_1 ;
F_2 ( V_1 ) ;
F_97 () ;
F_98 ( & V_141 ) ;
F_17 ( F_26 ( L_37 ) , 0 , 1 , NULL ) ;
V_142 = F_99 () ;
F_6 ( & V_141 ) ;
while ( V_142 )
F_100 () ;
F_17 ( F_26 ( L_38 ) , 0 , 1 , NULL ) ;
F_7 ( V_1 ) ;
}
void T_7 F_101 ( void )
{
while ( ! V_142 )
F_100 () ;
F_98 ( & V_141 ) ;
F_102 ( V_142 >> 32 , V_142 & 0xffffffff ) ;
V_142 = 0 ;
F_6 ( & V_141 ) ;
}
