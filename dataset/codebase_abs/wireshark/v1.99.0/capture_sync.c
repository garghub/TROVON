void
F_1 ( T_1 * V_1 , void * V_2 )
{
V_1 -> V_2 = V_2 ;
V_1 -> V_3 = - 1 ;
#ifdef F_2
V_1 -> V_4 = - 1 ;
#endif
V_1 -> V_5 = V_6 ;
#ifndef F_2
V_1 -> V_7 = F_3 () ;
V_1 -> V_8 = F_4 () ;
#endif
V_1 -> V_9 = FALSE ;
}
static char * *
F_5 ( char * * args , int * V_10 , const char * V_11 )
{
args = ( char * * ) F_6 ( ( V_12 ) args , ( * V_10 + 2 ) * sizeof ( char * ) ) ;
args [ * V_10 ] = F_7 ( V_11 ) ;
( * V_10 ) ++ ;
args [ * V_10 ] = NULL ;
return args ;
}
static T_2 *
F_8 ( const T_2 * V_13 )
{
T_2 * V_14 ;
const T_2 * V_15 = V_13 ;
T_2 * V_16 ;
T_3 V_17 = 0 ;
T_4 V_18 = FALSE ;
while ( * V_15 ) {
if ( * V_15 == ' ' || * V_15 == '\t' )
V_18 = TRUE ;
else if ( * V_15 == '"' )
V_17 ++ ;
else if ( * V_15 == '\\' ) {
const T_2 * V_19 = V_15 ;
while ( * V_19 && * V_19 == '\\' )
V_19 ++ ;
if ( * V_19 == '"' )
V_17 ++ ;
}
V_17 ++ ;
V_15 ++ ;
}
V_16 = V_14 = F_9 ( V_17 + V_18 * 2 + 1 ) ;
V_15 = V_13 ;
if ( V_18 )
* V_16 ++ = '"' ;
while ( * V_15 ) {
if ( * V_15 == '"' )
* V_16 ++ = '\\' ;
else if ( * V_15 == '\\' ) {
const T_2 * V_19 = V_15 ;
while ( * V_19 && * V_19 == '\\' )
V_19 ++ ;
if ( * V_19 == '"' )
* V_16 ++ = '\\' ;
}
* V_16 ++ = * V_15 ;
V_15 ++ ;
}
if ( V_18 )
* V_16 ++ = '"' ;
* V_16 ++ = '\0' ;
return V_14 ;
}
static const char *
F_10 ( T_5 error )
{
static char V_20 [ V_21 + 1 ] ;
T_6 V_22 ;
char * V_15 ;
F_11 ( V_23 | V_24 ,
NULL , error , 0 , V_20 , V_21 , NULL ) ;
V_22 = strlen ( V_20 ) ;
if ( V_22 >= 2 ) {
V_20 [ V_22 - 1 ] = '\0' ;
V_20 [ V_22 - 2 ] = '\0' ;
}
V_15 = strchr ( V_20 , '\0' ) ;
F_12 ( V_15 , ( V_25 ) ( sizeof V_20 - ( V_15 - V_20 ) ) , L_1 , error ) ;
return V_20 ;
}
static const char *
F_13 ( T_5 V_26 )
{
static char V_20 [ V_21 + 1 ] ;
static const struct V_27 {
int V_28 ;
char * V_29 ;
} V_30 [] = {
{ V_31 , L_2 } ,
{ V_32 , L_3 } ,
{ V_33 , L_4 } ,
{ V_34 , L_5 } ,
{ V_35 , L_6 } ,
{ V_36 , L_7 } ,
{ V_37 , L_8 } ,
{ V_38 , L_9 } ,
{ V_39 , L_10 } ,
{ V_40 , L_11 } ,
{ V_41 , L_12 } ,
{ V_42 , L_13 } ,
{ V_43 , L_14 } ,
{ V_44 , L_15 } ,
{ V_45 , L_16 } ,
{ V_46 , L_17 } ,
{ V_47 , L_18 } ,
{ V_48 , L_19 } ,
{ V_49 , L_20 } ,
{ V_50 , L_21 } ,
{ V_51 , L_22 } ,
{ V_52 , L_23 } ,
{ 0 , NULL }
} ;
#define F_14 (sizeof exceptions / sizeof exceptions[0])
int V_53 ;
for ( V_53 = 0 ; V_53 < F_14 ; V_53 ++ ) {
if ( V_30 [ V_53 ] . V_28 == V_26 )
return V_30 [ V_53 ] . V_29 ;
}
F_12 ( V_20 , ( V_25 ) sizeof V_20 , L_24 , V_26 ) ;
return V_20 ;
}
static char * *
F_15 ( int * V_10 ) {
char * * V_13 ;
const char * V_54 ;
char * V_55 ;
V_54 = F_16 () ;
if ( V_54 == NULL ) {
return NULL ;
}
* V_10 = 0 ;
V_13 = ( char * * ) F_9 ( sizeof ( char * ) ) ;
* V_13 = NULL ;
V_55 = F_17 ( L_25 V_56 L_26 , V_54 ) ;
V_13 = F_5 ( V_13 , V_10 , V_55 ) ;
F_18 ( V_55 ) ;
return V_13 ;
}
T_4
F_19 ( T_7 * V_57 , T_1 * V_1 , void (* F_20)( void ) )
{
char V_58 [ V_59 ] ;
char V_60 [ V_59 ] ;
char V_61 [ V_59 ] ;
char V_62 [ V_59 ] ;
char V_63 [ V_59 ] ;
char V_64 [ V_59 ] ;
char V_65 [ V_59 ] ;
char V_66 [ V_59 ] ;
#ifdef F_21
char V_67 [ 256 ] ;
#endif
#ifdef F_22
char V_68 [ V_59 ] ;
#endif
#if F_23 ( F_2 ) || F_23 ( V_69 )
char V_70 [ V_59 ] ;
#endif
#ifdef F_2
T_8 V_71 ;
T_8 V_72 ;
T_8 V_73 ;
T_9 * args = F_24 ( 200 ) ;
T_2 * V_74 ;
T_10 V_75 ;
T_11 V_76 ;
T_12 V_77 ;
char V_78 [ V_59 ] ;
T_2 * V_79 ;
#else
char V_80 [ 1024 + 1 ] ;
int V_81 [ 2 ] ;
enum T_13 { V_82 , V_83 };
#endif
int V_84 ;
int V_10 ;
char * * V_13 ;
int V_53 ;
T_14 V_85 ;
T_15 V_86 ;
if ( V_57 -> V_87 -> V_17 > 1 )
V_57 -> V_88 = TRUE ;
F_25 ( V_89 , V_90 , L_27 ) ;
F_26 ( V_89 , V_90 , V_57 ) ;
V_1 -> V_3 = - 1 ;
#ifdef F_27
if ( ! F_28 ( V_57 ) ) {
F_29 ( L_28 ) ;
return FALSE ;
}
#endif
V_13 = F_15 ( & V_10 ) ;
if ( ! V_13 ) {
F_29 ( L_29 ) ;
return FALSE ;
}
if ( V_57 -> V_87 -> V_17 > 1 )
V_13 = F_5 ( V_13 , & V_10 , L_30 ) ;
if ( V_57 -> V_88 )
V_13 = F_5 ( V_13 , & V_10 , L_31 ) ;
else
V_13 = F_5 ( V_13 , & V_10 , L_32 ) ;
if ( V_57 -> V_91 ) {
V_13 = F_5 ( V_13 , & V_10 , L_33 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_57 -> V_91 ) ;
}
if ( V_57 -> V_92 ) {
if ( V_57 -> V_93 ) {
V_13 = F_5 ( V_13 , & V_10 , L_34 ) ;
F_12 ( V_61 , V_59 , L_35 , V_57 -> V_94 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_61 ) ;
}
if ( V_57 -> V_95 ) {
V_13 = F_5 ( V_13 , & V_10 , L_34 ) ;
F_12 ( V_62 , V_59 , L_36 , V_57 -> V_96 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_62 ) ;
}
if ( V_57 -> V_97 ) {
V_13 = F_5 ( V_13 , & V_10 , L_34 ) ;
F_12 ( V_63 , V_59 , L_37 , V_57 -> V_98 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_63 ) ;
}
if ( V_57 -> V_99 ) {
V_13 = F_5 ( V_13 , & V_10 , L_38 ) ;
F_12 ( V_64 , V_59 , L_37 , V_57 -> V_100 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_64 ) ;
}
} else {
if ( V_57 -> V_93 ) {
V_13 = F_5 ( V_13 , & V_10 , L_38 ) ;
F_12 ( V_65 , V_59 , L_35 , V_57 -> V_94 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_65 ) ;
}
}
if ( V_57 -> V_101 ) {
V_13 = F_5 ( V_13 , & V_10 , L_39 ) ;
F_12 ( V_60 , V_59 , L_40 , V_57 -> V_102 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_60 ) ;
}
if ( V_57 -> V_103 ) {
V_13 = F_5 ( V_13 , & V_10 , L_38 ) ;
F_12 ( V_66 , V_59 , L_36 , V_57 -> V_104 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_66 ) ;
}
if ( V_57 -> V_105 ) {
V_13 = F_5 ( V_13 , & V_10 , L_41 ) ;
}
for ( V_85 = 0 ; V_85 < V_57 -> V_87 -> V_17 ; V_85 ++ ) {
V_86 = F_30 ( V_57 -> V_87 , T_15 , V_85 ) ;
V_13 = F_5 ( V_13 , & V_10 , L_42 ) ;
#ifdef F_27
if ( V_86 . V_106 != NULL )
V_13 = F_5 ( V_13 , & V_10 , V_86 . V_106 ) ;
else
#endif
V_13 = F_5 ( V_13 , & V_10 , V_86 . V_107 ) ;
if ( V_86 . V_108 != NULL && strlen ( V_86 . V_108 ) != 0 ) {
V_13 = F_5 ( V_13 , & V_10 , L_43 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_86 . V_108 ) ;
}
if ( V_86 . V_109 != V_110 ) {
V_13 = F_5 ( V_13 , & V_10 , L_44 ) ;
F_12 ( V_58 , V_59 , L_40 , V_86 . V_109 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_58 ) ;
}
if ( V_86 . V_111 != - 1 ) {
const char * V_111 = F_31 ( V_86 . V_111 ) ;
if ( V_111 != NULL )
{
V_13 = F_5 ( V_13 , & V_10 , L_45 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_111 ) ;
}
}
if ( ! V_86 . V_112 ) {
V_13 = F_5 ( V_13 , & V_10 , L_46 ) ;
}
#if F_23 ( F_2 ) || F_23 ( V_69 )
if ( V_86 . V_70 != V_113 ) {
V_13 = F_5 ( V_13 , & V_10 , L_47 ) ;
if( V_86 . V_70 == 0x00 )
V_86 . V_70 = V_113 ;
F_12 ( V_70 , V_59 , L_40 , V_86 . V_70 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_70 ) ;
}
#endif
#ifdef V_69
if ( V_86 . V_114 ) {
V_13 = F_5 ( V_13 , & V_10 , L_48 ) ;
}
#endif
#ifdef F_21
if ( V_86 . V_115 )
V_13 = F_5 ( V_13 , & V_10 , L_49 ) ;
if ( ! V_86 . V_116 )
V_13 = F_5 ( V_13 , & V_10 , L_50 ) ;
if ( V_86 . V_117 == V_118 ) {
V_13 = F_5 ( V_13 , & V_10 , L_51 ) ;
F_12 ( V_67 , sizeof( V_67 ) , L_52 ,
V_86 . V_119 ,
V_86 . V_120 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_67 ) ;
}
#endif
#ifdef F_22
if ( V_86 . V_121 != V_122 ) {
V_13 = F_5 ( V_13 , & V_10 , L_53 ) ;
F_12 ( V_68 , V_59 , L_54 ,
V_86 . V_121 == V_123 ? L_55 :
V_86 . V_121 == V_124 ? L_56 :
L_57 ,
V_86 . V_125 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_68 ) ;
}
#endif
}
#ifndef F_32
V_13 = F_5 ( V_13 , & V_10 , L_58 ) ;
#ifdef F_2
F_12 ( V_78 , V_59 , L_40 , F_33 () ) ;
V_13 = F_5 ( V_13 , & V_10 , V_78 ) ;
#else
V_13 = F_5 ( V_13 , & V_10 , V_126 ) ;
#endif
#endif
if ( V_57 -> V_127 ) {
V_13 = F_5 ( V_13 , & V_10 , L_59 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_57 -> V_127 ) ;
}
for ( V_53 = 0 ; V_53 < V_10 ; V_53 ++ ) {
F_25 ( V_89 , V_90 , L_60 , V_53 , V_13 [ V_53 ] ) ;
}
#ifdef F_2
V_75 . V_128 = sizeof( T_10 ) ;
V_75 . V_129 = TRUE ;
V_75 . V_130 = NULL ;
if ( ! F_34 ( & V_71 , & V_72 , & V_75 , 5120 ) ) {
F_29 ( L_61 ,
F_10 ( F_35 () ) ) ;
for ( V_53 = 0 ; V_53 < V_10 ; V_53 ++ ) {
F_18 ( ( V_12 ) V_13 [ V_53 ] ) ;
}
F_18 ( ( V_12 ) V_13 ) ;
return FALSE ;
}
V_79 = F_17 ( V_131 , V_78 ) ;
V_73 = F_36 ( F_37 ( V_79 ) ,
V_132 , V_133 , 1 , 65535 , 65535 , 0 , NULL ) ;
F_18 ( V_79 ) ;
if ( V_73 == V_134 ) {
F_29 ( L_62 ,
F_10 ( F_35 () ) ) ;
for ( V_53 = 0 ; V_53 < V_10 ; V_53 ++ ) {
F_18 ( ( V_12 ) V_13 [ V_53 ] ) ;
}
F_18 ( ( V_12 ) V_13 ) ;
return FALSE ;
}
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
V_76 . V_135 = sizeof( V_76 ) ;
#ifdef F_32
V_76 . V_136 = V_137 ;
V_76 . V_138 = V_139 ;
#else
V_76 . V_136 = V_140 | V_137 ;
V_76 . V_138 = V_141 ;
#if F_23 ( F_2 )
if( V_86 . V_106 != NULL )
{
if( strncmp ( V_86 . V_106 , L_63 , 9 ) == 0 )
{
V_76 . V_142 = F_38 () ;
}
}
else
#endif
V_76 . V_142 = F_39 ( V_143 ) ;
V_76 . V_144 = F_39 ( V_145 ) ;
V_76 . V_146 = V_72 ;
#endif
for( V_53 = 0 ; V_13 [ V_53 ] != 0 ; V_53 ++ ) {
if( V_53 != 0 ) F_40 ( args , ' ' ) ;
V_74 = F_8 ( V_13 [ V_53 ] ) ;
F_41 ( args , V_74 ) ;
F_18 ( V_74 ) ;
}
if( ! F_42 ( NULL , F_37 ( args -> V_147 ) , NULL , NULL , TRUE ,
V_148 , NULL , NULL , & V_76 , & V_77 ) ) {
F_29 ( L_64 ,
args -> V_147 , F_10 ( F_35 () ) ) ;
F_43 ( V_71 ) ;
F_43 ( V_72 ) ;
for ( V_53 = 0 ; V_53 < V_10 ; V_53 ++ ) {
F_18 ( ( V_12 ) V_13 [ V_53 ] ) ;
}
F_18 ( ( V_12 ) V_13 ) ;
return FALSE ;
}
V_1 -> V_3 = ( int ) V_77 . V_149 ;
F_44 ( args , TRUE ) ;
V_84 = F_45 ( ( long ) V_71 , V_150 ) ;
V_1 -> V_4 = F_45 ( ( long ) V_73 , V_150 ) ;
#else
if ( F_46 ( V_81 ) < 0 ) {
F_29 ( L_61 , F_47 ( V_151 ) ) ;
for ( V_53 = 0 ; V_53 < V_10 ; V_53 ++ ) {
F_18 ( ( V_12 ) V_13 [ V_53 ] ) ;
}
F_18 ( V_13 ) ;
return FALSE ;
}
if ( ( V_1 -> V_3 = F_48 () ) == 0 ) {
F_49 ( V_81 [ V_83 ] , 2 ) ;
F_50 ( V_81 [ V_82 ] ) ;
F_51 ( V_13 [ 0 ] , V_13 ) ;
F_12 ( V_80 , sizeof V_80 , L_64 ,
V_13 [ 0 ] , F_47 ( V_151 ) ) ;
F_52 ( 2 , V_80 , L_65 ) ;
F_53 ( 1 ) ;
}
if ( V_152 && V_1 -> V_3 > 0 )
V_152 ( V_1 -> V_3 ) ;
V_84 = V_81 [ V_82 ] ;
#endif
for ( V_53 = 0 ; V_53 < V_10 ; V_53 ++ ) {
F_18 ( ( V_12 ) V_13 [ V_53 ] ) ;
}
F_18 ( ( V_12 ) V_13 ) ;
#ifdef F_2
F_43 ( V_72 ) ;
#else
F_50 ( V_81 [ V_83 ] ) ;
#endif
if ( V_1 -> V_3 == - 1 ) {
F_29 ( L_66 , F_47 ( V_151 ) ) ;
F_50 ( V_84 ) ;
#ifdef F_2
F_50 ( V_1 -> V_4 ) ;
#endif
return FALSE ;
}
V_1 -> V_153 = 0 ;
V_1 -> V_57 = V_57 ;
if ( F_20 ) F_20 () ;
F_54 ( V_84 , ( V_12 ) V_1 ,
& V_1 -> V_3 , V_154 ) ;
return TRUE ;
}
static int
F_55 ( char * * V_13 , int * V_155 ,
int * V_156 , int * V_3 , T_2 * * V_29 , void (* F_20)( void ) )
{
enum T_13 { V_82 , V_83 };
#ifdef F_2
T_8 V_81 [ 2 ] ;
T_8 V_157 [ 2 ] ;
T_9 * args = F_24 ( 200 ) ;
T_2 * V_74 ;
T_10 V_75 ;
T_11 V_76 ;
T_12 V_77 ;
#else
char V_80 [ 1024 + 1 ] ;
int V_81 [ 2 ] ;
int V_157 [ 2 ] ;
#endif
int V_53 ;
* V_3 = - 1 ;
* V_155 = - 1 ;
* V_156 = - 1 ;
F_25 ( V_89 , V_90 , L_67 ) ;
if ( ! V_29 ) {
#ifdef F_2
F_44 ( args , TRUE ) ;
#endif
return - 1 ;
}
#ifdef F_2
V_75 . V_128 = sizeof( T_10 ) ;
V_75 . V_129 = TRUE ;
V_75 . V_130 = NULL ;
if ( ! F_34 ( & V_81 [ V_82 ] , & V_81 [ V_83 ] , & V_75 , 5120 ) ) {
* V_29 = F_17 ( L_61 ,
F_10 ( F_35 () ) ) ;
for ( V_53 = 0 ; V_13 [ V_53 ] != NULL ; V_53 ++ ) {
F_18 ( ( V_12 ) V_13 [ V_53 ] ) ;
}
F_18 ( ( V_12 ) V_13 ) ;
return - 1 ;
}
if ( ! F_34 ( & V_157 [ V_82 ] , & V_157 [ V_83 ] , & V_75 , 5120 ) ) {
* V_29 = F_17 ( L_68 ,
F_10 ( F_35 () ) ) ;
F_43 ( V_81 [ V_82 ] ) ;
F_43 ( V_81 [ V_83 ] ) ;
for ( V_53 = 0 ; V_13 [ V_53 ] != NULL ; V_53 ++ ) {
F_18 ( ( V_12 ) V_13 [ V_53 ] ) ;
}
F_18 ( ( V_12 ) V_13 ) ;
return - 1 ;
}
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
V_76 . V_135 = sizeof( V_76 ) ;
#ifdef F_32
V_76 . V_136 = V_137 ;
V_76 . V_138 = V_139 ;
#else
V_76 . V_136 = V_140 | V_137 ;
V_76 . V_138 = V_141 ;
V_76 . V_142 = NULL ;
V_76 . V_144 = V_157 [ V_83 ] ;
V_76 . V_146 = V_81 [ V_83 ] ;
#endif
for( V_53 = 0 ; V_13 [ V_53 ] != 0 ; V_53 ++ ) {
if( V_53 != 0 ) F_40 ( args , ' ' ) ;
V_74 = F_8 ( V_13 [ V_53 ] ) ;
F_41 ( args , V_74 ) ;
F_18 ( V_74 ) ;
}
if( ! F_42 ( NULL , F_37 ( args -> V_147 ) , NULL , NULL , TRUE ,
V_148 , NULL , NULL , & V_76 , & V_77 ) ) {
* V_29 = F_17 ( L_64 ,
args -> V_147 , F_10 ( F_35 () ) ) ;
F_43 ( V_157 [ V_82 ] ) ;
F_43 ( V_157 [ V_83 ] ) ;
F_43 ( V_81 [ V_82 ] ) ;
F_43 ( V_81 [ V_83 ] ) ;
for ( V_53 = 0 ; V_13 [ V_53 ] != NULL ; V_53 ++ ) {
F_18 ( ( V_12 ) V_13 [ V_53 ] ) ;
}
F_18 ( ( V_12 ) V_13 ) ;
return - 1 ;
}
* V_3 = ( int ) V_77 . V_149 ;
F_44 ( args , TRUE ) ;
* V_155 = F_45 ( ( long ) V_157 [ V_82 ] , V_150 ) ;
* V_156 = F_45 ( ( long ) V_81 [ V_82 ] , V_150 ) ;
#else
if ( F_46 ( V_81 ) < 0 ) {
* V_29 = F_17 ( L_61 , F_47 ( V_151 ) ) ;
for ( V_53 = 0 ; V_13 [ V_53 ] != NULL ; V_53 ++ ) {
F_18 ( ( V_12 ) V_13 [ V_53 ] ) ;
}
F_18 ( V_13 ) ;
return - 1 ;
}
if ( F_46 ( V_157 ) < 0 ) {
* V_29 = F_17 ( L_68 , F_47 ( V_151 ) ) ;
F_50 ( V_81 [ V_82 ] ) ;
F_50 ( V_81 [ V_83 ] ) ;
for ( V_53 = 0 ; V_13 [ V_53 ] != NULL ; V_53 ++ ) {
F_18 ( ( V_12 ) V_13 [ V_53 ] ) ;
}
F_18 ( V_13 ) ;
return - 1 ;
}
if ( ( * V_3 = F_48 () ) == 0 ) {
F_49 ( V_157 [ V_83 ] , 1 ) ;
F_50 ( V_157 [ V_82 ] ) ;
F_50 ( V_157 [ V_83 ] ) ;
F_49 ( V_81 [ V_83 ] , 2 ) ;
F_50 ( V_81 [ V_82 ] ) ;
F_50 ( V_81 [ V_83 ] ) ;
F_51 ( V_13 [ 0 ] , V_13 ) ;
F_12 ( V_80 , sizeof V_80 , L_64 ,
V_13 [ 0 ] , F_47 ( V_151 ) ) ;
F_52 ( 2 , V_80 , L_65 ) ;
F_53 ( 1 ) ;
}
if ( V_152 && * V_3 > 0 )
V_152 ( * V_3 ) ;
* V_155 = V_157 [ V_82 ] ;
* V_156 = V_81 [ V_82 ] ;
#endif
for ( V_53 = 0 ; V_13 [ V_53 ] != NULL ; V_53 ++ ) {
F_18 ( ( V_12 ) V_13 [ V_53 ] ) ;
}
F_18 ( ( V_12 ) V_13 ) ;
#ifdef F_2
F_43 ( V_157 [ V_83 ] ) ;
F_43 ( V_81 [ V_83 ] ) ;
#else
F_50 ( V_157 [ V_83 ] ) ;
F_50 ( V_81 [ V_83 ] ) ;
#endif
if ( * V_3 == - 1 ) {
* V_29 = F_17 ( L_66 , F_47 ( V_151 ) ) ;
F_50 ( * V_155 ) ;
F_50 ( * V_156 ) ;
return - 1 ;
}
if ( F_20 ) F_20 () ;
return 0 ;
}
static int
F_56 ( int * V_155 , int * V_156 ,
int * V_3 , T_2 * * V_158 )
{
F_50 ( * V_155 ) ;
if ( V_156 != NULL )
F_50 ( * V_156 ) ;
#ifdef F_2
F_57 ( * V_3 ) ;
#endif
return F_58 ( * V_3 , V_158 ) ;
}
static int
F_59 ( char * * V_13 , T_2 * * V_159 , T_2 * * V_160 ,
T_2 * * V_161 , void (* F_20)( void ) )
{
T_2 * V_29 ;
int V_162 , V_84 , V_3 , V_163 ;
char * V_164 ;
T_2 V_165 [ V_166 + 1 ] = { 0 } ;
T_16 V_167 ;
char V_168 ;
int V_169 ;
char * V_170 ;
int V_171 ;
char * V_172 ;
char * V_173 ;
T_9 * V_174 = NULL ;
T_16 V_175 ;
V_163 = F_55 ( V_13 , & V_162 , & V_84 ,
& V_3 , & V_29 , F_20 ) ;
if ( V_163 == - 1 ) {
* V_160 = V_29 ;
* V_161 = NULL ;
* V_159 = NULL ;
return - 1 ;
}
V_167 = F_60 ( V_84 , & V_168 , V_176 ,
V_165 , V_160 ) ;
if( V_167 <= 0 ) {
V_163 = F_58 ( V_3 , & V_164 ) ;
if( V_167 == 0 ) {
if ( V_163 == - 1 )
* V_160 = V_164 ;
else
* V_160 = F_7 ( L_69 ) ;
} else {
if ( V_163 == - 1 ) {
V_173 = F_17 ( L_70 , * V_160 , V_164 ) ;
F_18 ( * V_160 ) ;
F_18 ( V_164 ) ;
* V_160 = V_173 ;
}
}
* V_161 = NULL ;
return - 1 ;
}
switch( V_168 ) {
case V_177 :
F_61 ( ( V_178 * ) V_165 , 4 , & V_168 , & V_169 ) ;
V_170 = V_165 + 4 ;
F_61 ( ( V_178 * ) V_170 + V_169 , 4 , & V_168 ,
& V_171 ) ;
V_172 = V_170 + V_169 + 4 ;
V_163 = F_56 ( & V_162 , & V_84 ,
& V_3 , & V_29 ) ;
if ( V_163 == - 1 ) {
* V_160 = V_29 ;
* V_161 = NULL ;
} else {
* V_160 = F_7 ( V_170 ) ;
* V_161 = F_7 ( V_172 ) ;
V_163 = - 1 ;
}
* V_159 = NULL ;
break;
case V_179 :
V_174 = F_62 ( L_65 ) ;
while ( ( V_175 = F_63 ( V_162 , V_165 , V_166 ) ) > 0 ) {
V_165 [ V_175 ] = '\0' ;
F_41 ( V_174 , V_165 ) ;
}
V_163 = F_56 ( & V_162 , & V_84 ,
& V_3 , & V_29 ) ;
if ( V_163 == - 1 ) {
* V_160 = V_29 ;
* V_161 = NULL ;
F_44 ( V_174 , TRUE ) ;
* V_159 = NULL ;
} else {
* V_160 = NULL ;
* V_161 = NULL ;
* V_159 = V_174 -> V_147 ;
F_44 ( V_174 , FALSE ) ;
}
break;
default:
V_163 = F_56 ( & V_162 , & V_84 ,
& V_3 , & V_29 ) ;
if ( V_163 == - 1 ) {
* V_160 = V_29 ;
* V_161 = NULL ;
} else {
* V_160 = F_17 ( L_71 ,
V_168 ) ;
* V_161 = NULL ;
V_163 = - 1 ;
}
* V_159 = NULL ;
break;
}
return V_163 ;
}
static int
F_64 ( char * * V_13 , T_2 * * V_159 , T_2 * * V_160 ,
T_2 * * V_161 , void (* F_20)( void ) )
{
int V_163 , V_53 ;
T_17 V_180 ;
T_17 V_181 ;
float V_182 ;
int V_183 ;
V_183 = ( ( V_90 | V_184 ) & V_185 & V_186 . V_187 ) ;
if( V_183 ) {
F_65 ( & V_180 ) ;
F_25 ( V_89 , V_184 , L_72 ) ;
for( V_53 = 0 ; V_13 [ V_53 ] != 0 ; V_53 ++ ) {
F_25 ( V_89 , V_90 , L_73 , V_53 , V_13 [ V_53 ] ) ;
}
}
V_163 = F_59 ( V_13 , V_159 , V_160 , V_161 , F_20 ) ;
if( V_183 ) {
F_65 ( & V_181 ) ;
V_182 = ( float ) ( ( V_181 . V_188 - V_180 . V_188 ) +
( ( V_181 . V_189 - V_180 . V_189 ) / 1e6 ) ) ;
F_25 ( V_89 , V_184 , L_74 , V_182 , V_163 ) ;
}
return V_163 ;
}
int
F_66 ( const T_2 * V_190 , const char * V_191 , const T_2 * type ,
T_2 * * V_159 , T_2 * * V_160 ,
T_2 * * V_161 , void (* F_20)( void ) )
{
int V_10 , V_163 ;
char * * V_13 ;
T_2 * V_192 ;
V_13 = F_15 ( & V_10 ) ;
if ( ! V_13 ) {
* V_160 = F_7 ( L_29 ) ;
* V_161 = NULL ;
* V_159 = NULL ;
return - 1 ;
}
V_13 = F_5 ( V_13 , & V_10 , L_42 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_190 ) ;
if ( type )
V_192 = F_17 ( L_75 , V_191 , type ) ;
else
V_192 = F_17 ( L_25 , V_191 ) ;
if ( ! V_192 ) {
* V_160 = F_7 ( L_76 ) ;
* V_161 = NULL ;
* V_159 = NULL ;
return - 1 ;
}
V_13 = F_5 ( V_13 , & V_10 , L_77 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_192 ) ;
#ifndef F_32
V_13 = F_5 ( V_13 , & V_10 , L_58 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_126 ) ;
#endif
V_163 = F_64 ( V_13 , V_159 , V_160 , V_161 , F_20 ) ;
F_18 ( V_192 ) ;
return V_163 ;
}
int
F_67 ( T_2 * * V_159 , T_2 * * V_160 ,
T_2 * * V_161 , void (* F_20)( void ) )
{
int V_10 ;
char * * V_13 ;
F_25 ( V_89 , V_90 , L_78 ) ;
V_13 = F_15 ( & V_10 ) ;
if ( ! V_13 ) {
* V_160 = F_7 ( L_79 ) ;
* V_161 = NULL ;
* V_159 = NULL ;
return - 1 ;
}
V_13 = F_5 ( V_13 , & V_10 , L_80 ) ;
#ifndef F_32
V_13 = F_5 ( V_13 , & V_10 , L_58 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_126 ) ;
#endif
return F_64 ( V_13 , V_159 , V_160 , V_161 , F_20 ) ;
}
int
F_68 ( const T_2 * V_193 , T_4 V_114 ,
T_2 * * V_159 , T_2 * * V_160 ,
T_2 * * V_161 , void (* F_20)( void ) )
{
int V_10 ;
char * * V_13 ;
F_25 ( V_89 , V_90 , L_81 ) ;
V_13 = F_15 ( & V_10 ) ;
if ( ! V_13 ) {
* V_160 = F_7 ( L_29 ) ;
* V_161 = NULL ;
* V_159 = NULL ;
return - 1 ;
}
V_13 = F_5 ( V_13 , & V_10 , L_42 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_193 ) ;
V_13 = F_5 ( V_13 , & V_10 , L_82 ) ;
if ( V_114 )
V_13 = F_5 ( V_13 , & V_10 , L_48 ) ;
#ifndef F_32
V_13 = F_5 ( V_13 , & V_10 , L_58 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_126 ) ;
#endif
return F_64 ( V_13 , V_159 , V_160 , V_161 , F_20 ) ;
}
int
F_69 ( int * V_155 , int * V_3 , T_2 * * V_29 , void (* F_20)( void ) )
{
int V_10 ;
char * * V_13 ;
int V_156 , V_163 ;
char * V_164 ;
T_2 V_165 [ V_166 + 1 ] = { 0 } ;
T_16 V_167 ;
char V_168 ;
int V_169 ;
char * V_170 ;
int V_171 ;
char * V_173 ;
F_25 ( V_89 , V_90 , L_83 ) ;
V_13 = F_15 ( & V_10 ) ;
if ( ! V_13 ) {
* V_29 = F_7 ( L_29 ) ;
return - 1 ;
}
V_13 = F_5 ( V_13 , & V_10 , L_84 ) ;
#ifndef F_32
V_13 = F_5 ( V_13 , & V_10 , L_58 ) ;
#ifdef F_2
F_70 () ;
V_13 = F_5 ( V_13 , & V_10 , V_194 ) ;
#else
V_13 = F_5 ( V_13 , & V_10 , V_126 ) ;
#endif
#endif
V_163 = F_55 ( V_13 , V_155 , & V_156 ,
V_3 , V_29 , F_20 ) ;
if ( V_163 == - 1 )
return - 1 ;
V_167 = F_60 ( V_156 , & V_168 , V_176 ,
V_165 , V_29 ) ;
if( V_167 <= 0 ) {
V_163 = F_58 ( * V_3 , & V_164 ) ;
if( V_167 == 0 ) {
if ( V_163 == - 1 )
* V_29 = V_164 ;
else
* V_29 = F_7 ( L_69 ) ;
} else {
if ( V_163 == - 1 ) {
V_173 = F_17 ( L_70 , * V_29 , V_164 ) ;
F_18 ( * V_29 ) ;
F_18 ( V_164 ) ;
* V_29 = V_173 ;
}
}
return - 1 ;
}
switch( V_168 ) {
case V_177 :
F_61 ( ( V_178 * ) V_165 , 4 , & V_168 , & V_169 ) ;
V_170 = V_165 + 4 ;
F_61 ( ( V_178 * ) V_170 + V_169 , 4 , & V_168 ,
& V_171 ) ;
V_163 = F_56 ( V_155 , & V_156 ,
V_3 , V_29 ) ;
if ( V_163 == - 1 ) {
} else {
* V_29 = F_7 ( V_170 ) ;
V_163 = - 1 ;
}
break;
case V_179 :
F_50 ( V_156 ) ;
break;
default:
V_163 = F_56 ( V_155 , & V_156 ,
V_3 , V_29 ) ;
if ( V_163 == - 1 ) {
} else {
* V_29 = F_17 ( L_71 ,
V_168 ) ;
V_163 = - 1 ;
}
break;
}
return V_163 ;
}
int
F_71 ( int * V_195 , int * V_3 , T_2 * * V_29 )
{
#ifndef F_2
F_57 ( * V_3 ) ;
#endif
return F_56 ( V_195 , NULL , V_3 , V_29 ) ;
}
static T_16
F_72 ( int V_196 , char * V_197 , int V_198 , char * * V_29 )
{
T_16 V_199 ;
T_16 V_200 = 0 ;
int error ;
while( V_198 ) {
V_199 = F_73 ( V_196 , & V_197 [ V_200 ] , V_198 ) ;
if ( V_199 == 0 ) {
F_25 ( V_89 , V_90 ,
L_85 , V_196 ) ;
* V_29 = 0 ;
return V_200 ;
}
if ( V_199 < 0 ) {
error = V_151 ;
F_25 ( V_89 , V_90 ,
L_86 , V_196 , error ,
F_47 ( error ) ) ;
* V_29 = F_17 ( L_87 ,
F_47 ( error ) ) ;
return V_199 ;
}
V_198 -= ( int ) V_199 ;
V_200 += V_199 ;
}
* V_29 = NULL ;
return V_200 ;
}
static T_4 F_74 ( int V_196 ) {
#ifdef F_2
T_8 V_201 = ( T_8 ) F_75 ( V_196 ) ;
T_5 V_202 ;
if ( V_201 == V_134 )
return FALSE ;
if ( ! F_76 ( V_201 , NULL , 0 , NULL , & V_202 , NULL ) )
return FALSE ;
if ( V_202 > 0 )
return TRUE ;
return FALSE ;
#else
T_18 V_203 ;
struct V_204 V_205 ;
F_77 ( & V_203 ) ;
F_78 ( V_196 , & V_203 ) ;
V_205 . V_188 = 0 ;
V_205 . V_189 = 0 ;
if ( F_79 ( V_196 + 1 , & V_203 , NULL , NULL , & V_205 ) > 0 )
return TRUE ;
return FALSE ;
#endif
}
int
F_80 ( int V_196 , char * V_197 , int V_206 ) {
T_16 V_199 ;
int V_200 = - 1 ;
while( V_200 < V_206 - 1 ) {
V_200 ++ ;
if ( ! F_74 ( V_196 ) )
break;
V_199 = F_73 ( V_196 , & V_197 [ V_200 ] , 1 ) ;
if ( V_199 == 0 ) {
break;
} else if ( V_199 == - 1 ) {
F_25 ( V_89 , V_90 ,
L_86 , V_196 , V_151 , F_47 ( V_151 ) ) ;
return - 1 ;
} else if ( V_197 [ V_200 ] == '\n' ) {
break;
}
}
if ( V_200 >= 0 )
V_197 [ V_200 ] = '\0' ;
return V_200 ;
}
static void
F_61 ( const V_178 * V_207 , int V_208 , char * V_168 , int * V_209 ) {
F_81 ( V_208 == 4 ) ;
* V_168 = V_207 [ 0 ] ;
* V_209 = ( V_207 [ 1 ] & 0xFF ) << 16 | ( V_207 [ 2 ] & 0xFF ) << 8 | ( V_207 [ 3 ] & 0xFF ) ;
}
static T_16
F_60 ( int V_196 , char * V_168 , int V_17 , char * V_29 ,
char * * V_210 )
{
int V_198 ;
T_16 V_199 ;
T_2 V_207 [ 4 ] ;
V_199 = F_72 ( V_196 , V_207 , 4 , V_210 ) ;
if( V_199 != 4 ) {
if ( V_199 == 0 ) {
F_25 ( V_89 , V_90 ,
L_88 , V_196 ) ;
return 0 ;
}
F_25 ( V_89 , V_90 ,
L_89 , V_196 , ( long ) V_199 ) ;
if ( V_199 != - 1 ) {
* V_210 = F_17 ( L_90 ,
( long ) V_199 ) ;
}
return - 1 ;
}
F_61 ( ( V_178 * ) V_207 , 4 , V_168 , & V_198 ) ;
if( V_198 == 0 ) {
F_25 ( V_89 , V_90 ,
L_91 , V_196 , * V_168 ) ;
return 4 ;
}
if( V_198 > V_17 ) {
F_25 ( V_89 , V_90 ,
L_92 ,
V_196 , V_198 , V_17 ,
V_207 [ 0 ] , V_207 [ 1 ] , V_207 [ 2 ] , V_207 [ 3 ] ) ;
memcpy ( V_29 , V_207 , sizeof( V_207 ) ) ;
V_199 = F_73 ( V_196 , & V_29 [ sizeof( V_207 ) ] , V_17 - sizeof( V_207 ) ) ;
if ( V_199 < 0 ) {
F_25 ( V_89 , V_90 ,
L_86 , V_196 , V_151 , F_47 ( V_151 ) ) ;
}
* V_210 = F_17 ( L_93 ,
V_29 ) ;
return - 1 ;
}
V_17 = V_198 ;
V_199 = F_72 ( V_196 , V_29 , V_198 , V_210 ) ;
if( V_199 != V_198 ) {
if ( V_199 != - 1 ) {
* V_210 = F_17 ( L_93 ,
V_29 ) ;
}
return - 1 ;
}
F_25 ( V_89 , V_90 ,
L_94 , V_196 , * V_168 ,
V_17 , V_29 ) ;
* V_210 = NULL ;
return V_199 + 4 ;
}
static T_4
V_154 ( T_3 V_211 , V_12 V_212 )
{
T_1 * V_1 = ( T_1 * ) V_212 ;
int V_163 ;
char V_165 [ V_176 + 1 ] = { 0 } ;
T_16 V_167 ;
char V_168 ;
int V_213 ;
char * V_160 ;
int V_214 ;
char * V_161 ;
char * V_164 , * V_173 ;
int V_215 ;
V_167 = F_60 ( V_211 , & V_168 , V_176 , V_165 ,
& V_160 ) ;
if( V_167 <= 0 ) {
V_163 = F_58 ( V_1 -> V_3 , & V_164 ) ;
if( V_167 == 0 ) {
if ( V_163 == - 1 )
V_160 = V_164 ;
} else {
if ( V_163 == - 1 ) {
V_173 = F_17 ( L_70 , V_160 , V_164 ) ;
F_18 ( V_160 ) ;
F_18 ( V_164 ) ;
V_160 = V_173 ;
}
}
V_1 -> V_3 = - 1 ;
V_1 -> V_153 = V_163 ;
#ifdef F_2
F_50 ( V_1 -> V_4 ) ;
#endif
#ifdef F_27
F_25 ( V_89 , V_90 , L_95 ) ;
F_82 ( V_1 -> V_57 ) ;
#endif
F_83 ( V_1 , V_160 ) ;
F_18 ( V_160 ) ;
return FALSE ;
}
switch( V_168 ) {
case V_216 :
if( ! F_84 ( V_1 , V_165 ) ) {
F_25 ( V_89 , V_90 , L_96 ) ;
F_50 ( V_211 ) ;
F_85 ( V_1 ) ;
F_83 ( V_1 , NULL ) ;
return FALSE ;
}
break;
case V_217 :
V_215 = atoi ( V_165 ) ;
F_25 ( V_89 , V_90 , L_97 , V_215 ) ;
F_86 ( V_1 , V_215 ) ;
break;
case V_177 :
F_61 ( ( V_178 * ) V_165 , 4 , & V_168 , & V_213 ) ;
V_160 = V_165 + 4 ;
F_61 ( ( V_178 * ) V_160 + V_213 , 4 , & V_168 , & V_214 ) ;
V_161 = V_160 + V_213 + 4 ;
F_87 ( V_1 , V_160 , V_161 ) ;
break;
case V_218 : {
char * V_219 = NULL ;
int V_220 = 0 ;
V_219 = strtok ( V_165 , L_98 ) ;
if ( V_219 ) {
V_220 = ( int ) strtol ( V_219 , NULL , 10 ) ;
V_219 = strtok ( NULL , L_98 ) ;
}
F_88 ( V_1 , V_220 , V_219 ) ;
break;
}
case V_221 :
F_89 ( V_1 , ( V_222 ) strtoul ( V_165 , NULL , 10 ) ) ;
break;
default:
F_90 () ;
}
return TRUE ;
}
static int
F_58 ( int V_3 , T_2 * * V_158 )
{
int V_153 ;
int V_163 ;
T_17 V_180 ;
T_17 V_181 ;
float V_182 ;
F_65 ( & V_180 ) ;
F_25 ( V_89 , V_90 , L_99 ) ;
F_81 ( V_3 != - 1 ) ;
* V_158 = NULL ;
#ifdef F_2
if ( F_91 ( & V_153 , V_3 , V_223 ) == - 1 ) {
* V_158 = F_17 ( L_100 , F_47 ( V_151 ) ) ;
V_163 = - 1 ;
} else {
V_163 = V_153 ;
if ( ( V_153 & 0xC0000000 ) == V_224 ) {
* V_158 = F_17 ( L_101 ,
F_13 ( V_153 ) ) ;
V_163 = - 1 ;
}
}
#else
if ( F_92 ( V_3 , & V_153 , 0 ) != - 1 ) {
if ( F_93 ( V_153 ) ) {
V_163 = F_94 ( V_153 ) ;
} else if ( F_95 ( V_153 ) ) {
* V_158 = F_17 ( L_102 ,
F_96 ( F_97 ( V_153 ) ) ) ;
V_163 = - 1 ;
} else if ( F_98 ( V_153 ) ) {
* V_158 = F_17 ( L_103 ,
F_96 ( F_99 ( V_153 ) ) ,
F_100 ( V_153 ) ? L_104 : L_65 ) ;
V_163 = - 1 ;
} else {
* V_158 = F_17 ( L_105 ,
V_153 ) ;
V_163 = - 1 ;
}
} else if ( V_151 != V_225 ) {
* V_158 = F_17 ( L_106 , F_47 ( V_151 ) ) ;
V_163 = - 1 ;
} else {
V_163 = V_152 ? 0 : - 1 ;
}
#endif
F_65 ( & V_181 ) ;
V_182 = ( float ) ( ( V_181 . V_188 - V_180 . V_188 ) +
( ( V_181 . V_189 - V_180 . V_189 ) / 1e6 ) ) ;
F_25 ( V_89 , V_90 , L_107 , V_182 ) ;
return V_163 ;
}
static const char *
F_96 ( int V_226 )
{
const char * V_227 ;
static char V_228 [ 6 + 1 + 3 + 1 ] ;
switch ( V_226 ) {
case V_229 :
V_227 = L_108 ;
break;
case V_230 :
V_227 = L_109 ;
break;
case V_231 :
V_227 = L_110 ;
break;
case V_232 :
V_227 = L_14 ;
break;
case V_233 :
V_227 = L_111 ;
break;
case V_234 :
V_227 = L_112 ;
break;
case V_235 :
V_227 = L_113 ;
break;
case V_236 :
V_227 = L_114 ;
break;
case V_237 :
V_227 = L_115 ;
break;
case V_238 :
V_227 = L_116 ;
break;
#ifdef F_101
case F_101 :
V_227 = L_117 ;
break;
#endif
case V_239 :
V_227 = L_118 ;
break;
case V_240 :
V_227 = L_119 ;
break;
case V_241 :
V_227 = L_120 ;
break;
default:
F_12 ( V_228 , sizeof V_228 , L_121 , V_226 ) ;
V_227 = V_228 ;
break;
}
return V_227 ;
}
static void F_70 () {
T_2 * V_242 ;
if ( V_243 != NULL ) return;
if ( ! V_194 ) {
V_194 = F_17 ( L_122 , F_33 () ) ;
}
V_242 = F_17 ( V_131 , V_194 ) ;
V_243 = F_36 ( F_37 ( V_242 ) ,
V_132 , V_133 , 1 , 65535 , 65535 , 0 , NULL ) ;
F_18 ( V_242 ) ;
}
static void
F_102 ( T_1 * V_1 )
{
const char V_244 [] = L_123 ;
int V_163 ;
F_25 ( V_89 , V_90 , L_124 ) ;
V_163 = F_103 ( V_1 -> V_4 , V_244 , sizeof V_244 ) ;
if( V_163 == - 1 ) {
F_25 ( V_245 , V_246 ,
L_125 , V_1 -> V_4 , F_47 ( V_151 ) ) ;
}
}
void
F_85 ( T_1 * V_1 )
{
#ifdef F_2
int V_175 ;
T_5 V_247 ;
T_4 V_248 = TRUE ;
#endif
if ( V_1 -> V_3 != - 1 ) {
#ifndef F_2
int V_249 = F_104 ( V_1 -> V_3 , V_230 ) ;
if ( V_249 != 0 ) {
F_25 ( V_245 , V_246 ,
L_126 , F_47 ( V_151 ) ) ;
}
#else
#define F_105 500
#define F_106 50
F_102 ( V_1 ) ;
for ( V_175 = 0 ; V_175 < F_105 / F_106 ; V_175 ++ ) {
if ( F_107 ( ( T_8 ) V_1 -> V_3 , & V_247 ) &&
V_247 != V_250 ) {
V_248 = FALSE ;
break;
}
F_108 ( F_106 ) ;
}
if ( V_248 ) {
F_25 ( V_245 , V_246 ,
L_127 ) ;
F_57 ( V_1 -> V_3 ) ;
}
#endif
}
}
void
F_57 ( int V_3 )
{
if ( V_3 != - 1 ) {
#ifndef F_2
int V_249 = F_104 ( V_3 , V_241 ) ;
if ( V_249 != 0 ) {
F_25 ( V_245 , V_246 ,
L_128 , F_47 ( V_151 ) ) ;
}
#else
F_109 ( ( T_8 ) ( V_3 ) , 0 ) ;
#endif
}
}
void F_110 ( void (* V_135)( int V_251 ) ) {
V_152 = V_135 ;
}
