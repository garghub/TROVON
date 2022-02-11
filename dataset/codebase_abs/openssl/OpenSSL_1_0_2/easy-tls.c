static void
F_1 ( int V_1 , char * V_2 , T_1 V_3 , void * V_4 )
{
fputs ( V_2 , V_5 ) ;
}
struct V_6 F_2 ( void )
{
struct V_6 V_7 ;
V_7 . V_8 = - 1 ;
V_7 . V_9 = - 1 ;
V_7 . V_10 = NULL ;
V_7 . V_11 = NULL ;
V_7 . V_12 = NULL ;
return V_7 ;
}
int F_3 ( struct V_6 V_13 , void * V_4 )
{
int V_14 [ 2 ] = { - 1 , - 1 } ;
int V_15 [ 2 ] = { - 1 , - 1 } ;
int V_16 , V_17 , V_18 ;
int V_7 ;
F_4 ( L_1 , V_13 . V_8 ) ;
F_4 ( L_2 , V_13 . V_9 ) ;
if ( V_13 . V_8 == - 1 || V_13 . V_9 == - 1 || V_13 . V_10 == NULL )
return 1 ;
if ( V_13 . V_11 != NULL ) {
* V_13 . V_11 = 0 ;
}
if ( V_13 . V_12 != NULL ) {
* V_13 . V_12 = - 1 ;
}
V_16 = F_5 ( V_19 , V_20 , 0 , V_14 ) ;
if ( V_16 == - 1 )
return - 1 ;
if ( V_13 . V_8 >= V_21 || V_14 [ 0 ] >= V_21 ) {
V_7 = 2 ;
goto V_22;
}
if ( V_13 . V_12 != NULL ) {
V_16 = F_6 ( V_15 ) ;
if ( V_16 == - 1 ) {
V_7 = - 3 ;
goto V_22;
}
}
V_16 = F_7 () ;
if ( V_16 == - 1 ) {
V_7 = - 4 ;
goto V_22;
}
if ( V_16 == 0 ) {
F_8 ( L_3 ) ;
V_23 = 1 ;
V_24 = V_4 ;
F_9 ( V_14 [ 1 ] ) ;
if ( V_15 [ 0 ] != - 1 )
F_9 ( V_15 [ 0 ] ) ;
F_10 ( V_13 . V_8 , V_13 . V_9 , V_4 ) ;
F_8 ( L_4 ) ;
F_11 ( V_14 [ 0 ] , V_13 . V_8 , V_15 [ 1 ] , V_13 . V_10 , V_13 . V_9 ) ;
exit ( 0 ) ;
}
if ( V_13 . V_11 != NULL )
* V_13 . V_11 = V_16 ;
if ( V_15 [ 1 ] != - 1 ) {
F_9 ( V_15 [ 1 ] ) ;
V_15 [ 1 ] = - 1 ;
}
F_9 ( V_14 [ 0 ] ) ;
V_14 [ 0 ] = - 1 ;
V_17 = F_12 ( V_13 . V_8 , V_25 ) ;
V_18 = F_12 ( V_13 . V_8 , V_26 ) ;
V_16 = F_13 ( V_14 [ 1 ] , V_13 . V_8 ) ;
F_9 ( V_14 [ 1 ] ) ;
V_14 [ 1 ] = - 1 ;
if ( V_16 == - 1 ) {
V_7 = - 5 ;
goto V_22;
}
if ( V_17 != 1 )
F_12 ( V_13 . V_8 , V_27 , V_17 ) ;
if ( V_18 & V_28 )
( void ) F_14 ( V_13 . V_8 ) ;
if ( V_13 . V_12 != NULL )
* V_13 . V_12 = V_15 [ 0 ] ;
return 0 ;
V_22:
if ( V_14 [ 0 ] != - 1 )
F_9 ( V_14 [ 0 ] ) ;
if ( V_14 [ 1 ] != - 1 )
F_9 ( V_14 [ 1 ] ) ;
if ( V_15 [ 0 ] != - 1 )
F_9 ( V_15 [ 0 ] ) ;
if ( V_15 [ 1 ] != - 1 )
F_9 ( V_15 [ 1 ] ) ;
return V_7 ;
}
static void F_15 ( void * V_4 )
{
if ( V_29 == 0 )
return;
assert ( V_29 < sizeof V_2 ) ;
assert ( V_2 [ V_29 ] == 0 ) ;
if ( V_29 == sizeof V_2 - 1 ) {
V_2 [ V_29 - 1 ] = '\n' ;
}
F_16 ( V_23 , V_2 , V_29 , V_4 ) ;
V_29 = 0 ;
}
static void F_17 ( int V_30 , void * V_4 , const char * V_31 , ... )
{
T_2 args ;
int V_16 ;
if ( V_29 < sizeof V_2 - 1 ) {
T_1 V_32 ;
va_start ( args , V_31 ) ;
V_32 = ( sizeof V_2 ) - V_29 ;
V_16 = vsnprintf ( V_2 + V_29 , V_32 , V_31 , args ) ;
if ( V_16 >= V_32 )
V_16 = V_32 - 1 ;
if ( V_16 >= 0 ) {
V_29 += V_16 ;
} else {
V_29 = sizeof V_2 - 1 ;
V_2 [ V_29 ] = '\0' ;
}
assert ( V_29 < sizeof V_2 ) ;
assert ( V_2 [ V_29 ] == 0 ) ;
}
#ifndef F_18
F_15 ( V_4 ) ;
#else
if ( V_30 )
F_15 ( V_4 ) ;
#endif
}
static char * F_19 ( const char * V_33 ,
const char * V_34 ,
const char * V_35 , void * V_4 )
{
static char V_36 [ 255 ] ;
T_1 V_37 ;
unsigned long V_22 ;
const char * V_38 ;
int line ;
const char * V_39 ;
int V_40 ;
char * V_41 ;
int V_42 = 0 ;
V_37 = 0 ;
assert ( V_33 != NULL ) ;
assert ( V_34 != NULL ) ;
if ( V_35 == NULL )
V_35 = L_5 L_5 L_5 ;
while ( ( V_22 = F_20 ( & V_38 , & line , & V_39 , & V_40 ) ) != 0 ) {
if ( V_37 < sizeof V_36 ) {
T_1 V_32 ;
int V_16 ;
V_32 = ( sizeof V_36 ) - V_37 ;
V_16 = snprintf ( V_36 + V_37 , V_32 , L_6 ,
( V_37 > 0 ? L_7 : L_8 ) ,
F_21 ( V_22 ) ) ;
if ( V_16 >= V_32 )
V_16 = V_32 - 1 ;
if ( V_16 >= 0 ) {
V_37 += V_16 ;
} else {
V_37 = sizeof V_36 ;
}
assert ( V_37 <= sizeof V_36 ) ;
}
V_41 = F_22 ( V_22 , NULL ) ;
assert ( V_41 != NULL ) ;
F_17 ( 0 , V_4 , L_9 ,
V_33 , V_34 , V_41 , V_38 , line ,
( V_40 & V_43 ) ? V_39 : L_8 ) ;
V_42 = 1 ;
}
if ( ! V_42 ) {
assert ( V_37 == 0 ) ;
snprintf ( V_36 , sizeof V_36 , L_10 , V_35 ) ;
F_17 ( 0 , V_4 , L_11 , V_33 ,
V_34 , V_35 ) ;
}
#ifdef F_18
F_15 ( V_4 ) ;
#endif
assert ( V_29 == 0 ) ;
return V_36 ;
}
static int F_23 ( void * V_4 )
{
if ( V_44 )
return 0 ;
F_24 () ;
if ( ! F_25 () ) {
F_17 ( 1 , V_4 , L_12 ) ;
return - 1 ;
}
V_44 = 1 ;
F_26 () ;
return 0 ;
}
static void F_27 ( void )
{
struct {
T_3 V_11 ;
T_4 time ;
void * V_45 ;
} V_39 ;
V_39 . V_11 = F_28 () ;
V_39 . time = time ( NULL ) ;
V_39 . V_45 = ( void * ) & V_39 ;
F_29 ( ( const void * ) & V_39 , sizeof V_39 ) ;
}
void F_26 ( void )
{
struct {
struct V_46 V_47 ;
int V_48 ;
int V_49 ;
T_5 V_50 ;
T_5 V_51 ;
T_6 V_52 ;
T_6 V_53 ;
} V_39 ;
V_39 . V_48 = V_47 ( & V_39 . V_47 ) ;
V_39 . V_49 = V_54 ;
V_39 . V_50 = F_30 () ;
V_39 . V_51 = F_31 () ;
V_39 . V_52 = F_32 () ;
V_39 . V_53 = F_33 () ;
F_29 ( ( const void * ) & V_39 , sizeof V_39 ) ;
F_27 () ;
}
int F_34 ( const char * V_55 , T_1 V_32 , void * V_4 )
{
int V_16 ;
if ( F_23 ( V_4 ) == - 1 )
return - 1 ;
F_26 () ;
V_16 = F_35 ( V_55 ,
( V_32 > 0 && V_32 < V_56 ) ? ( long ) V_32 : V_56 ) ;
assert ( 1 < V_57 ) ;
if ( V_32 == 0 )
V_32 = V_57 ;
if ( V_16 < V_32 ) {
F_17 ( 1 , V_4 ,
L_13 ,
V_32 , V_55 ) ;
return - 1 ;
} else {
V_58 = 1 ;
return 0 ;
}
}
void F_36 ( const void * V_59 , T_1 V_32 )
{
T_1 V_60 = 0 ;
while ( V_60 < V_32 ) {
T_1 V_61 = V_32 - V_60 ;
int V_62 = V_61 < V_63 ? ( int ) V_61 : V_63 ;
F_29 ( ( const char * ) V_59 + V_60 , V_62 ) ;
V_60 += V_62 ;
}
V_58 = 1 ;
}
static void
F_37 ( T_7 * V_64 ,
struct V_65 * V_66 )
{
T_8 * V_67 ;
if ( V_64 == NULL ) {
V_66 -> V_68 [ 0 ] = '\0' ;
return;
}
V_67 = F_38 ( V_64 ) ;
assert ( sizeof V_66 -> V_68 >= 4 ) ;
if ( V_67 == NULL ) {
V_66 -> V_68 [ 0 ] = '?' ;
V_66 -> V_68 [ 1 ] = 0 ;
} else {
T_1 V_69 ;
F_39 ( V_67 , V_66 -> V_68 , sizeof V_66 -> V_68 ) ;
V_69 = strlen ( V_66 -> V_68 ) ;
assert ( V_66 -> V_68 [ V_69 ] == 0 ) ;
assert ( V_69 < sizeof V_66 -> V_68 ) ;
if ( V_69 + 1 == sizeof V_66 -> V_68 ) {
assert ( V_66 -> V_68 [ V_69 ] == 0 ) ;
V_66 -> V_68 [ -- V_69 ] = '.' ;
V_66 -> V_68 [ -- V_69 ] = '.' ;
V_66 -> V_68 [ -- V_69 ] = '.' ;
}
}
}
static int F_40 ( char * V_59 , int V_3 , int V_70 , void * V_71 )
{
return - 1 ;
}
void F_41 ( int V_60 , void * V_4 )
{
T_9 * V_72 ;
T_10 * V_73 ;
const char * V_74 [] = { L_14 ,
L_14 ,
L_15 ,
L_14 ,
L_16 ,
} ;
unsigned char V_75 [ 20 ] ;
F_23 ( V_4 ) ;
if ( V_60 >= 0 ) {
V_60 %= sizeof V_74 / sizeof V_74 [ 0 ] ;
assert ( strlen ( V_74 [ V_60 ] ) == 20 ) ;
memcpy ( V_75 , V_74 [ V_60 ] , 20 ) ;
V_72 =
F_42 ( 1024 , V_75 , 20 , NULL , NULL , 0 , NULL ) ;
} else {
V_72 =
F_42 ( 1024 , NULL , 0 , NULL , NULL , 0 , NULL ) ;
}
if ( V_72 == NULL ) {
F_19 ( L_8 , L_8 , NULL , V_4 ) ;
return;
}
V_73 = F_43 ( V_72 ) ;
F_44 ( V_72 ) ;
if ( V_73 == NULL ) {
F_19 ( L_8 , L_8 , NULL , V_4 ) ;
return;
}
if ( V_76 != NULL )
F_45 ( V_76 ) ;
V_76 = V_73 ;
}
struct V_77 F_46 ( void )
{
struct V_77 V_7 ;
V_7 . V_9 = 0 ;
V_7 . V_78 = NULL ;
V_7 . V_79 = NULL ;
V_7 . V_80 = NULL ;
V_7 . V_81 = - 1 ;
V_7 . V_82 = 0 ;
V_7 . V_83 = 0 ;
return V_7 ;
}
T_11 * F_47 ( struct V_77 V_13 , void * V_4 )
{
int V_16 ;
static long V_84 = 0 ;
T_11 * V_7 ;
const char * V_85 = L_8 , * V_86 = L_8 ;
if ( F_23 ( V_4 ) == - 1 )
return NULL ;
V_7 =
F_48 ( ( V_13 . V_9 ? V_87 :
V_88 ) ( ) ) ;
if ( V_7 == NULL )
goto V_22;
F_49 ( V_7 , F_40 ) ;
F_50 ( V_7 , V_89 ) ;
if ( ( V_13 . V_78 != NULL ) || ( V_13 . V_79 != NULL ) ) {
if ( V_13 . V_79 == NULL ) {
F_17 ( 1 , V_4 , L_17 ) ;
goto V_90;
}
if ( V_13 . V_78 == NULL ) {
F_17 ( 1 , V_4 , L_18 ) ;
goto V_90;
}
if ( ! F_51 ( V_7 , V_13 . V_79 , V_91 ) )
goto V_22;
if ( ! V_58 ) {
if ( F_34 ( V_13 . V_79 , 0 , V_4 ) == - 1 )
goto V_90;
}
if ( ! F_52 ( V_7 , V_13 . V_78 ) )
goto V_22;
if ( ! F_53 ( V_7 ) ) {
F_17 ( 1 , V_4 ,
L_19 ,
V_13 . V_79 , V_13 . V_78 ) ;
goto V_92;
}
}
if ( ( V_13 . V_80 != NULL ) || ( V_13 . V_81 > 0 ) ) {
V_84 ++ ;
V_16 = F_54 ( V_7 , ( const void * ) & V_84 ,
( unsigned int ) sizeof V_84 ) ;
if ( ! V_16 )
goto V_22;
F_55 ( V_7 ,
V_93 | ( V_13 . V_82 ?
V_94
: 0 ) , 0 ) ;
if ( ! V_13 . V_82 )
F_56 ( V_7 , V_95 , NULL ) ;
if ( V_13 . V_81 > 0 )
F_57 ( V_7 , V_13 . V_81 ) ;
if ( V_13 . V_80 != NULL ) {
V_16 = F_58 ( V_7 , V_13 . V_80 , NULL ) ;
if ( ! V_16 ) {
V_85 = L_20 ;
V_86 = V_13 . V_80 ;
goto V_22;
}
if ( ! V_13 . V_9 ) {
F_59 ( V_7 ,
F_60
( V_13 . V_80 ) ) ;
if ( F_61 ( V_7 ) == NULL ) {
F_17 ( 1 , V_4 ,
L_21 ,
V_13 . V_80 ) ;
goto V_92;
}
}
}
}
if ( ! V_13 . V_9 ) {
if ( V_76 == NULL ) {
int V_60 ;
F_62 ( ( unsigned char * ) & V_60 , sizeof V_60 ) ;
if ( V_60 < 0 )
V_60 = - V_60 ;
if ( V_60 < 0 )
V_60 = 0 ;
F_41 ( V_60 , V_4 ) ;
if ( V_76 == NULL )
goto V_90;
}
if ( ! F_63 ( V_7 , V_76 ) )
goto V_22;
F_64 ( V_7 , V_96 ) ;
}
#ifndef F_65
if ( ! V_13 . V_9 && V_13 . V_83 ) {
T_12 * V_97 ;
V_97 = F_66 ( 512 , V_98 , 0 , NULL ) ;
if ( V_97 == NULL )
goto V_22;
if ( ! F_67 ( V_7 , V_97 ) ) {
F_68 ( V_97 ) ;
goto V_22;
}
F_68 ( V_97 ) ;
}
#endif
return V_7 ;
V_92:
if ( ! F_69 () )
goto V_90;
V_22:
F_19 ( V_85 , V_86 , NULL , V_4 ) ;
V_90:
if ( V_7 != NULL )
F_70 ( V_7 ) ;
return NULL ;
}
static int F_14 ( int V_8 )
{
int V_99 , V_16 ;
V_99 = F_12 ( V_8 , V_26 , 0 ) ;
if ( V_99 == - 1 ) {
if ( V_54 == V_100 )
return 0 ;
return - 1 ;
}
V_16 = F_12 ( V_8 , V_101 , V_99 | V_28 ) ;
if ( V_16 == - 1 ) {
if ( V_54 == V_100 )
return 0 ;
return - 1 ;
}
return 0 ;
}
static int F_71 ( int V_13 , int V_102 )
{
return V_13 > V_102 ? V_13 : V_102 ;
}
static void
F_72 ( int V_103 , int V_104 , int V_105 ,
int V_106 , int V_107 )
{
int V_108 , V_32 ;
T_13 V_109 , V_110 ;
struct V_111 V_112 ;
struct V_111 * V_113 ;
assert ( V_103 >= - 1 && V_104 >= - 1 && V_105 >= - 1
&& V_106 >= - 1 ) ;
assert ( V_103 < V_21 && V_104 < V_21 - 1
&& V_105 < V_21 - 1
&& V_106 < V_21 - 1 ) ;
V_108 =
F_71 ( F_71 ( V_103 , V_104 ) ,
F_71 ( V_105 , V_106 ) ) ;
assert ( V_108 >= 0 ) ;
F_73 ( & V_109 ) ;
F_73 ( & V_110 ) ;
for ( V_32 = 0 ; V_32 < 4 ; ++ V_32 ) {
int V_60 = V_32 % 2 ;
int V_70 = V_32 >= 2 ;
int V_8 ;
if ( V_60 == 0 && V_70 == 0 )
V_8 = V_103 ;
else if ( V_60 == 1 && V_70 == 0 )
V_8 = V_104 ;
else if ( V_60 == 0 && V_70 == 1 )
V_8 = V_105 ;
else {
assert ( V_60 == 1 && V_70 == 1 ) ;
V_8 = V_106 ;
}
if ( V_8 >= 0 ) {
if ( V_70 == 0 )
F_74 ( V_8 , & V_109 ) ;
else
F_74 ( V_8 , & V_110 ) ;
}
}
if ( V_107 >= 0 ) {
V_112 . V_114 = V_107 ;
V_112 . V_115 = 0 ;
V_113 = & V_112 ;
} else
V_113 = NULL ;
F_4 ( L_22 , ++ V_116 ) ;
F_75 ( V_108 + 1 , & V_109 , & V_110 , ( T_13 * ) NULL , V_113 ) ;
F_8 ( L_23 ) ;
}
static void F_76 ( T_14 * V_117 , int * V_118 )
{
if ( * V_118 != - 1 ) {
long V_99 ;
int V_119 ;
struct V_65 V_120 ;
char V_121 [ V_122 ] ;
int V_16 ;
F_8 ( L_24 ) ;
V_99 = F_77 ( V_117 ) ;
V_119 = ( V_99 == V_123 ) ? 'A' : 'E' ;
{
T_7 * V_124 ;
V_124 = F_78 ( V_117 ) ;
F_37 ( V_124 , & V_120 ) ;
if ( V_124 != NULL )
F_79 ( V_124 ) ;
}
if ( V_120 . V_68 [ 0 ] == '\0' )
V_119 = '0' ;
else if ( strchr ( V_120 . V_68 , '\n' ) ) {
* strchr ( V_120 . V_68 , '\n' ) = '\0' ;
}
V_16 = snprintf ( V_121 , sizeof V_121 , L_25 , V_119 ,
F_80 ( V_99 ) , V_120 . V_68 ) ;
F_4 ( L_26 , V_16 ) ;
if ( V_16 == - 1 || V_16 >= sizeof V_121 )
V_16 = sizeof V_121 - 1 ;
F_81 ( * V_118 , V_121 , V_16 ) ;
F_9 ( * V_118 ) ;
* V_118 = - 1 ;
}
}
static void
F_11 ( int V_125 , int V_126 , int V_118 , T_11 * V_10 , int V_9 )
{
struct V_127 V_128 , V_129 ;
T_14 * V_117 ;
T_15 * V_130 , * V_131 ;
int V_132 , V_133 ;
const char * V_85 = L_8 , * V_86 = L_8 ;
const char * V_134 = NULL ;
assert ( V_125 != - 1 ) ;
assert ( V_126 != - 1 ) ;
assert ( V_125 < V_21 ) ;
assert ( V_126 < V_21 ) ;
assert ( V_10 != NULL ) ;
F_27 () ;
F_14 ( V_125 ) ;
F_4 ( L_27 , V_125 ) ;
F_14 ( V_126 ) ;
F_4 ( L_28 , V_126 ) ;
V_117 = F_82 ( V_10 ) ;
if ( V_117 == NULL )
goto V_22;
F_8 ( L_29 ) ;
if ( ! F_83 ( V_117 , V_126 ) )
goto V_22;
V_130 = F_84 ( V_117 ) ;
V_131 = F_85 ( V_117 ) ;
assert ( V_130 != NULL ) ;
assert ( V_131 != NULL ) ;
if ( V_9 )
F_86 ( V_117 ) ;
else
F_87 ( V_117 ) ;
V_132 = 0 ;
V_133 = 1 ;
V_129 . V_69 = 0 ;
V_129 . V_135 = 0 ;
V_128 . V_69 = 0 ;
V_128 . V_135 = 0 ;
V_134 = L_30 ;
do {
int V_136 = 0 , V_137 = 0 ,
V_138 = 0 , V_139 = 0 , V_140 = 0 ;
int V_16 ;
unsigned long V_141 = F_88 ( V_130 ) ,
V_142 = F_89 ( V_131 ) ;
F_4 ( L_31 , ++ V_143 ) ;
if ( V_133 ) {
F_8 ( L_32 ) ;
if ( V_9 )
V_16 = F_90 ( V_117 , & V_139 ,
& V_138 , & V_132 , & V_140 ,
& V_85 ) ;
else
V_16 = F_91 ( V_117 , & V_139 ,
& V_138 , & V_132 , & V_140 ,
& V_85 ) ;
if ( V_16 != 0 ) {
F_76 ( V_117 , & V_118 ) ;
goto V_22;
}
if ( V_132 )
goto V_90;
if ( ! F_92 ( V_117 ) ) {
V_133 = 0 ;
F_76 ( V_117 , & V_118 ) ;
}
}
if ( V_128 . V_69 != 0 && ! V_133 ) {
assert ( ! V_132 ) ;
V_16 = F_93 ( V_117 , & V_128 , & V_139 ,
& V_138 , & V_132 , & V_140 ,
& V_85 ) ;
if ( V_16 != 0 )
goto V_22;
if ( V_132 ) {
assert ( V_140 ) ;
V_129 . V_135 = 0 ;
V_129 . V_69 = 0 ;
}
}
if ( V_129 . V_69 != 0 ) {
assert ( ! V_132 ) ;
V_16 = F_94 ( V_125 , & V_129 , & V_137 ,
& V_132 , & V_140 ) ;
if ( V_16 != 0 )
goto V_90;
if ( V_132 ) {
assert ( V_140 ) ;
V_128 . V_135 = 0 ;
V_128 . V_69 = 0 ;
}
}
if ( ! V_132 ) {
if ( V_128 . V_135 + V_128 . V_69 <
sizeof V_128 . V_59 ) {
V_16 = F_95 ( V_125 , & V_128 , & V_136 ,
& V_132 , & V_140 ) ;
if ( V_16 != 0 )
goto V_90;
if ( V_132 ) {
V_16 = F_96 ( V_117 ) ;
F_4 ( L_33 , V_16 ) ;
}
}
}
if ( ! V_132 && ! V_133 ) {
if ( V_129 . V_135 + V_129 . V_69 <
sizeof V_129 . V_59 ) {
V_16 = F_97 ( V_117 , & V_129 , & V_139 ,
& V_138 , & V_132 , & V_140 ,
& V_85 ) ;
if ( V_16 != 0 )
goto V_22;
if ( V_132 ) {
V_16 = F_96 ( V_117 ) ;
F_4 ( L_33 , V_16 ) ;
}
}
}
if ( ! V_140 ) {
F_8 ( L_34 ) ;
if ( V_141 != F_88 ( V_130 )
|| V_142 != F_89 ( V_131 ) )
V_140 = 1 ;
if ( ! V_140 ) {
F_8 ( L_35 ) ;
assert ( V_136 || V_138
|| V_137 || V_139 ) ;
F_72 ( V_136 ? V_125 : - 1 ,
V_138 ? V_126 : - 1 ,
V_137 ? V_125 : - 1 ,
V_139 ? V_126 : - 1 , - 1 ) ;
}
}
} while ( ! V_132 );
return;
V_22:
F_19 ( V_85 , V_86 , V_134 , V_24 ) ;
V_90:
return;
}
static int
F_98 ( T_14 * V_117 , int V_16 , int * V_144 , int * V_145 ,
int * V_132 , int * V_140 )
{
int V_22 = F_99 ( V_117 , V_16 ) ;
if ( V_22 == V_146 ) {
assert ( V_16 > 0 ) ;
* V_140 = 1 ;
return 0 ;
}
assert ( V_16 <= 0 ) ;
switch ( V_22 ) {
case V_147 :
assert ( V_16 == 0 ) ;
* V_132 = 1 ;
* V_140 = 1 ;
return 0 ;
case V_148 :
* V_144 = 1 ;
return 0 ;
case V_149 :
* V_145 = 1 ;
return 0 ;
}
return - 1 ;
}
static int
F_90 ( T_14 * V_117 , int * V_144 , int * V_145 ,
int * V_132 , int * V_140 , const char * * V_150 )
{
int V_32 , V_16 ;
F_8 ( L_36 ) ;
V_32 = F_100 ( V_117 ) ;
F_4 ( L_37 , V_32 ) ;
V_16 = F_98 ( V_117 , V_32 , V_144 , V_145 , V_132 , V_140 ) ;
if ( V_16 == - 1 )
* V_150 = L_38 ;
return V_16 ;
}
static int
F_91 ( T_14 * V_117 , int * V_144 , int * V_145 , int * V_132 ,
int * V_140 , const char * * V_150 )
{
int V_32 , V_16 ;
F_8 ( L_39 ) ;
V_32 = F_101 ( V_117 ) ;
F_4 ( L_40 , V_32 ) ;
V_16 = F_98 ( V_117 , V_32 , V_144 , V_145 , V_132 , V_140 ) ;
if ( V_16 == - 1 )
* V_150 = L_41 ;
return V_16 ;
}
static int
F_93 ( T_14 * V_117 , struct V_127 * V_59 , int * V_144 ,
int * V_145 , int * V_132 , int * V_140 ,
const char * * V_150 )
{
int V_32 , V_16 ;
F_8 ( L_42 ) ;
V_32 = F_102 ( V_117 , V_59 -> V_59 + V_59 -> V_135 , V_59 -> V_69 ) ;
F_4 ( L_43 , V_32 ) ;
V_16 = F_98 ( V_117 , V_32 , V_144 , V_145 , V_132 , V_140 ) ;
if ( V_32 > 0 ) {
V_59 -> V_69 -= V_32 ;
assert ( V_59 -> V_69 >= 0 ) ;
if ( V_59 -> V_69 == 0 )
V_59 -> V_135 = 0 ;
else
V_59 -> V_135 += V_32 ;
}
if ( V_16 == - 1 )
* V_150 = L_44 ;
return V_16 ;
}
static int
F_97 ( T_14 * V_117 , struct V_127 * V_59 , int * V_144 ,
int * V_145 , int * V_132 , int * V_140 ,
const char * * V_150 )
{
int V_32 , V_16 ;
T_1 V_151 ;
F_8 ( L_45 ) ;
V_151 = V_59 -> V_135 + V_59 -> V_69 ;
assert ( V_151 < sizeof V_59 -> V_59 ) ;
V_32 = F_103 ( V_117 , V_59 -> V_59 + V_151 , ( sizeof V_59 -> V_59 ) - V_151 ) ;
F_4 ( L_46 , V_32 ) ;
V_16 = F_98 ( V_117 , V_32 , V_144 , V_145 , V_132 , V_140 ) ;
if ( V_32 > 0 ) {
V_59 -> V_69 += V_32 ;
assert ( V_59 -> V_135 + V_59 -> V_69 <= sizeof V_59 -> V_59 ) ;
}
if ( V_16 == - 1 )
* V_150 = L_47 ;
return V_16 ;
}
static int F_104 ( int V_16 , int * F_75 , int * V_132 , int * V_140 )
{
if ( V_16 >= 0 ) {
* V_140 = 1 ;
if ( V_16 == 0 )
* V_132 = 1 ;
return 0 ;
} else {
assert ( V_16 == - 1 ) ;
if ( V_54 == V_152 || V_54 == V_153 ) {
* F_75 = 1 ;
return 0 ;
} else if ( V_54 == V_154 ) {
* V_140 = 1 ;
* V_132 = 1 ;
return 0 ;
} else
return - 1 ;
}
}
static int F_94 ( int V_8 , struct V_127 * V_59 , int * F_75 ,
int * V_132 , int * V_140 )
{
int V_32 , V_16 ;
F_8 ( L_48 ) ;
V_32 = F_81 ( V_8 , V_59 -> V_59 + V_59 -> V_135 , V_59 -> V_69 ) ;
F_4 ( L_49 , V_32 ) ;
V_16 = F_104 ( V_32 , F_75 , V_132 , V_140 ) ;
if ( V_32 > 0 ) {
V_59 -> V_69 -= V_32 ;
assert ( V_59 -> V_69 >= 0 ) ;
if ( V_59 -> V_69 == 0 )
V_59 -> V_135 = 0 ;
else
V_59 -> V_135 += V_32 ;
}
if ( V_16 == - 1 )
F_17 ( 1 , V_24 , L_50 ,
strerror ( V_54 ) ) ;
return V_16 ;
}
static int
F_95 ( int V_8 , struct V_127 * V_59 , int * F_75 , int * V_132 ,
int * V_140 )
{
int V_32 , V_16 ;
T_1 V_151 ;
F_8 ( L_51 ) ;
V_151 = V_59 -> V_135 + V_59 -> V_69 ;
assert ( V_151 < sizeof V_59 -> V_59 ) ;
V_32 = F_105 ( V_8 , V_59 -> V_59 + V_151 , ( sizeof V_59 -> V_59 ) - V_151 ) ;
F_4 ( L_52 , V_32 ) ;
V_16 = F_104 ( V_32 , F_75 , V_132 , V_140 ) ;
if ( V_32 > 0 ) {
V_59 -> V_69 += V_32 ;
assert ( V_59 -> V_135 + V_59 -> V_69 <= sizeof V_59 -> V_59 ) ;
}
if ( V_16 == - 1 )
F_17 ( 1 , V_24 , L_53 ,
strerror ( V_54 ) ) ;
return V_16 ;
}
