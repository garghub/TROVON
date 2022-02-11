void
F_1 ( T_1 * V_1 , struct V_2 * V_3 )
{
V_1 -> V_3 = V_3 ;
V_1 -> V_4 = V_5 ;
#ifdef F_2
V_1 -> V_6 = - 1 ;
#endif
V_1 -> V_7 = V_8 ;
#ifndef F_2
V_1 -> V_9 = F_3 () ;
V_1 -> V_10 = F_4 () ;
#endif
V_1 -> V_11 = 0 ;
V_1 -> V_12 = FALSE ;
}
static char * *
F_5 ( char * * args , int * V_13 , const char * V_14 )
{
args = ( char * * ) F_6 ( ( V_15 ) args , ( * V_13 + 2 ) * sizeof ( char * ) ) ;
args [ * V_13 ] = F_7 ( V_14 ) ;
( * V_13 ) ++ ;
args [ * V_13 ] = NULL ;
return args ;
}
static T_2 *
F_8 ( const T_2 * V_16 )
{
T_2 * V_17 ;
const T_2 * V_18 = V_16 ;
T_2 * V_19 ;
T_3 V_20 = 0 ;
T_4 V_21 = FALSE ;
while ( * V_18 ) {
if ( * V_18 == ' ' || * V_18 == '\t' )
V_21 = TRUE ;
else if ( * V_18 == '"' )
V_20 ++ ;
else if ( * V_18 == '\\' ) {
const T_2 * V_22 = V_18 ;
while ( * V_22 && * V_22 == '\\' )
V_22 ++ ;
if ( * V_22 == '"' )
V_20 ++ ;
}
V_20 ++ ;
V_18 ++ ;
}
V_19 = V_17 = F_9 ( V_20 + V_21 * 2 + 1 ) ;
V_18 = V_16 ;
if ( V_21 )
* V_19 ++ = '"' ;
while ( * V_18 ) {
if ( * V_18 == '"' )
* V_19 ++ = '\\' ;
else if ( * V_18 == '\\' ) {
const T_2 * V_22 = V_18 ;
while ( * V_22 && * V_22 == '\\' )
V_22 ++ ;
if ( * V_22 == '"' )
* V_19 ++ = '\\' ;
}
* V_19 ++ = * V_18 ;
V_18 ++ ;
}
if ( V_21 )
* V_19 ++ = '"' ;
* V_19 ++ = '\0' ;
return V_17 ;
}
static const char *
F_10 ( T_5 error )
{
static char V_23 [ V_24 + 1 ] ;
T_6 V_25 ;
char * V_18 ;
F_11 ( V_26 | V_27 ,
NULL , error , 0 , V_23 , V_24 , NULL ) ;
V_25 = strlen ( V_23 ) ;
if ( V_25 >= 2 ) {
V_23 [ V_25 - 1 ] = '\0' ;
V_23 [ V_25 - 2 ] = '\0' ;
}
V_18 = strchr ( V_23 , '\0' ) ;
F_12 ( V_18 , ( V_28 ) ( sizeof V_23 - ( V_18 - V_23 ) ) , L_1 , error ) ;
return V_23 ;
}
static const char *
F_13 ( T_5 V_29 )
{
static char V_23 [ V_24 + 1 ] ;
static const struct V_30 {
int V_31 ;
char * V_32 ;
} V_33 [] = {
{ V_34 , L_2 } ,
{ V_35 , L_3 } ,
{ V_36 , L_4 } ,
{ V_37 , L_5 } ,
{ V_38 , L_6 } ,
{ V_39 , L_7 } ,
{ V_40 , L_8 } ,
{ V_41 , L_9 } ,
{ V_42 , L_10 } ,
{ V_43 , L_11 } ,
{ V_44 , L_12 } ,
{ V_45 , L_13 } ,
{ V_46 , L_14 } ,
{ V_47 , L_15 } ,
{ V_48 , L_16 } ,
{ V_49 , L_17 } ,
{ V_50 , L_18 } ,
{ V_51 , L_19 } ,
{ V_52 , L_20 } ,
{ V_53 , L_21 } ,
{ V_54 , L_22 } ,
{ V_55 , L_23 } ,
{ 0 , NULL }
} ;
#define F_14 (sizeof exceptions / sizeof exceptions[0])
int V_56 ;
for ( V_56 = 0 ; V_56 < F_14 ; V_56 ++ ) {
if ( V_33 [ V_56 ] . V_31 == V_29 )
return V_33 [ V_56 ] . V_32 ;
}
F_12 ( V_23 , ( V_28 ) sizeof V_23 , L_24 , V_29 ) ;
return V_23 ;
}
static char * *
F_15 ( int * V_13 ) {
char * * V_16 ;
const char * V_57 ;
char * V_58 ;
V_57 = F_16 () ;
if ( V_57 == NULL ) {
return NULL ;
}
* V_13 = 0 ;
V_16 = ( char * * ) F_9 ( sizeof ( char * ) ) ;
* V_16 = NULL ;
#ifdef F_2
V_58 = F_17 ( L_25 , V_57 ) ;
#else
V_58 = F_17 ( L_26 , V_57 ) ;
#endif
V_16 = F_5 ( V_16 , V_13 , V_58 ) ;
F_18 ( V_58 ) ;
return V_16 ;
}
T_4
F_19 ( T_7 * V_59 , T_1 * V_1 , T_8 * V_60 , void (* F_20)( void ) )
{
char V_61 [ V_62 ] ;
char V_63 [ V_62 ] ;
char V_64 [ V_62 ] ;
char V_65 [ V_62 ] ;
char V_66 [ V_62 ] ;
char V_67 [ V_62 ] ;
char V_68 [ V_62 ] ;
char V_69 [ V_62 ] ;
#ifdef F_21
char V_70 [ 256 ] ;
#endif
#ifdef F_22
char V_71 [ V_62 ] ;
#endif
#ifdef F_23
char V_72 [ V_62 ] ;
#endif
#ifdef F_2
T_9 V_73 ;
T_9 V_74 ;
int V_6 ;
T_9 V_75 ;
T_10 * args = F_24 ( 200 ) ;
T_2 * V_76 ;
T_11 * V_77 ;
T_12 V_78 ;
T_13 V_79 ;
T_14 V_80 ;
char V_81 [ V_62 ] ;
T_2 * V_82 ;
#else
char V_83 [ 1024 + 1 ] ;
int V_84 [ 2 ] ;
enum T_15 { V_85 , V_86 };
#endif
int V_87 ;
int V_13 ;
char * * V_16 ;
int V_56 ;
T_16 V_88 ;
T_17 V_89 ;
if ( V_59 -> V_90 -> V_20 > 1 )
V_59 -> V_91 = TRUE ;
F_25 ( V_92 , V_93 , L_27 ) ;
F_26 ( V_92 , V_93 , V_59 ) ;
V_1 -> V_4 = V_5 ;
#ifdef F_27
if ( ! F_28 ( V_59 ) ) {
F_29 ( L_28 ) ;
return FALSE ;
}
#endif
V_16 = F_15 ( & V_13 ) ;
if ( ! V_16 ) {
F_29 ( L_29 ) ;
return FALSE ;
}
if ( V_59 -> V_90 -> V_20 > 1 )
V_16 = F_5 ( V_16 , & V_13 , L_30 ) ;
if ( V_59 -> V_91 )
V_16 = F_5 ( V_16 , & V_13 , L_31 ) ;
else
V_16 = F_5 ( V_16 , & V_13 , L_32 ) ;
if ( V_59 -> V_94 ) {
V_16 = F_5 ( V_16 , & V_13 , L_33 ) ;
V_16 = F_5 ( V_16 , & V_13 , V_59 -> V_94 ) ;
}
if ( V_59 -> V_95 ) {
if ( V_59 -> V_96 ) {
V_16 = F_5 ( V_16 , & V_13 , L_34 ) ;
F_12 ( V_64 , V_62 , L_35 , V_59 -> V_97 ) ;
V_16 = F_5 ( V_16 , & V_13 , V_64 ) ;
}
if ( V_59 -> V_98 ) {
V_16 = F_5 ( V_16 , & V_13 , L_34 ) ;
F_12 ( V_65 , V_62 , L_36 , V_59 -> V_99 ) ;
V_16 = F_5 ( V_16 , & V_13 , V_65 ) ;
}
if ( V_59 -> V_100 ) {
V_16 = F_5 ( V_16 , & V_13 , L_34 ) ;
F_12 ( V_66 , V_62 , L_37 , V_59 -> V_101 ) ;
V_16 = F_5 ( V_16 , & V_13 , V_66 ) ;
}
if ( V_59 -> V_102 ) {
V_16 = F_5 ( V_16 , & V_13 , L_38 ) ;
F_12 ( V_67 , V_62 , L_37 , V_59 -> V_103 ) ;
V_16 = F_5 ( V_16 , & V_13 , V_67 ) ;
}
} else {
if ( V_59 -> V_96 ) {
V_16 = F_5 ( V_16 , & V_13 , L_38 ) ;
F_12 ( V_68 , V_62 , L_35 , V_59 -> V_97 ) ;
V_16 = F_5 ( V_16 , & V_13 , V_68 ) ;
}
}
if ( V_59 -> V_104 ) {
V_16 = F_5 ( V_16 , & V_13 , L_39 ) ;
F_12 ( V_63 , V_62 , L_40 , V_59 -> V_105 ) ;
V_16 = F_5 ( V_16 , & V_13 , V_63 ) ;
}
if ( V_59 -> V_106 ) {
V_16 = F_5 ( V_16 , & V_13 , L_38 ) ;
F_12 ( V_69 , V_62 , L_36 , V_59 -> V_107 ) ;
V_16 = F_5 ( V_16 , & V_13 , V_69 ) ;
}
if ( V_59 -> V_108 ) {
V_16 = F_5 ( V_16 , & V_13 , L_41 ) ;
}
for ( V_88 = 0 ; V_88 < V_59 -> V_90 -> V_20 ; V_88 ++ ) {
V_89 = F_30 ( V_59 -> V_90 , T_17 , V_88 ) ;
V_16 = F_5 ( V_16 , & V_13 , L_42 ) ;
#ifdef F_27
if ( V_89 . V_109 != NULL )
V_16 = F_5 ( V_16 , & V_13 , V_89 . V_109 ) ;
else
#endif
V_16 = F_5 ( V_16 , & V_13 , V_89 . V_110 ) ;
if ( V_89 . V_111 != NULL && strlen ( V_89 . V_111 ) != 0 ) {
V_16 = F_5 ( V_16 , & V_13 , L_43 ) ;
V_16 = F_5 ( V_16 , & V_13 , V_89 . V_111 ) ;
}
if ( V_89 . V_112 != V_113 ) {
V_16 = F_5 ( V_16 , & V_13 , L_44 ) ;
F_12 ( V_61 , V_62 , L_40 , V_89 . V_112 ) ;
V_16 = F_5 ( V_16 , & V_13 , V_61 ) ;
}
if ( V_89 . V_114 != - 1 ) {
const char * V_114 = F_31 ( V_89 . V_114 ) ;
if ( V_114 != NULL )
{
V_16 = F_5 ( V_16 , & V_13 , L_45 ) ;
V_16 = F_5 ( V_16 , & V_13 , V_114 ) ;
}
}
if ( ! V_89 . V_115 ) {
V_16 = F_5 ( V_16 , & V_13 , L_46 ) ;
}
#ifdef F_23
if ( V_89 . V_72 != V_116 ) {
V_16 = F_5 ( V_16 , & V_13 , L_47 ) ;
if( V_89 . V_72 == 0x00 )
V_89 . V_72 = V_116 ;
F_12 ( V_72 , V_62 , L_40 , V_89 . V_72 ) ;
V_16 = F_5 ( V_16 , & V_13 , V_72 ) ;
}
#endif
#ifdef F_32
if ( V_89 . V_117 ) {
V_16 = F_5 ( V_16 , & V_13 , L_48 ) ;
}
#endif
#ifdef F_21
if ( V_89 . V_118 )
V_16 = F_5 ( V_16 , & V_13 , L_49 ) ;
if ( ! V_89 . V_119 )
V_16 = F_5 ( V_16 , & V_13 , L_50 ) ;
if ( V_89 . V_120 == V_121 ) {
V_16 = F_5 ( V_16 , & V_13 , L_51 ) ;
F_12 ( V_70 , sizeof( V_70 ) , L_52 ,
V_89 . V_122 ,
V_89 . V_123 ) ;
V_16 = F_5 ( V_16 , & V_13 , V_70 ) ;
}
#endif
#ifdef F_22
if ( V_89 . V_124 != V_125 ) {
V_16 = F_5 ( V_16 , & V_13 , L_53 ) ;
F_12 ( V_71 , V_62 , L_54 ,
V_89 . V_124 == V_126 ? L_55 :
V_89 . V_124 == V_127 ? L_56 :
L_57 ,
V_89 . V_128 ) ;
V_16 = F_5 ( V_16 , & V_13 , V_71 ) ;
}
#endif
}
#ifndef F_33
V_16 = F_5 ( V_16 , & V_13 , L_58 ) ;
#ifdef F_2
F_12 ( V_81 , V_62 , L_40 , F_34 () ) ;
V_16 = F_5 ( V_16 , & V_13 , V_81 ) ;
#else
V_16 = F_5 ( V_16 , & V_13 , V_129 ) ;
#endif
#endif
if ( V_59 -> V_130 ) {
V_16 = F_5 ( V_16 , & V_13 , L_59 ) ;
V_16 = F_5 ( V_16 , & V_13 , V_59 -> V_130 ) ;
}
for ( V_56 = 0 ; V_56 < V_13 ; V_56 ++ ) {
F_25 ( V_92 , V_93 , L_60 , V_56 , V_16 [ V_56 ] ) ;
}
#ifdef F_2
V_78 . V_131 = sizeof( T_12 ) ;
V_78 . V_132 = TRUE ;
V_78 . V_133 = NULL ;
if ( ! F_35 ( & V_73 , & V_74 , & V_78 , 5120 ) ) {
F_29 ( L_61 ,
F_10 ( F_36 () ) ) ;
for ( V_56 = 0 ; V_56 < V_13 ; V_56 ++ ) {
F_18 ( ( V_15 ) V_16 [ V_56 ] ) ;
}
F_18 ( ( V_15 ) V_16 ) ;
return FALSE ;
}
V_87 = F_37 ( ( V_134 ) V_73 , V_135 ) ;
if ( V_87 == - 1 ) {
F_29 ( L_62 , F_38 ( V_136 ) ) ;
F_39 ( V_73 ) ;
F_39 ( V_74 ) ;
for ( V_56 = 0 ; V_56 < V_13 ; V_56 ++ ) {
F_18 ( ( V_15 ) V_16 [ V_56 ] ) ;
}
F_18 ( V_16 ) ;
return FALSE ;
}
V_82 = F_17 ( V_137 , V_81 ) ;
V_75 = F_40 ( F_41 ( V_82 ) ,
V_138 , V_139 , 1 , 65535 , 65535 , 0 , NULL ) ;
F_18 ( V_82 ) ;
if ( V_75 == V_140 ) {
F_29 ( L_63 ,
F_10 ( F_36 () ) ) ;
F_42 ( V_87 ) ;
F_39 ( V_74 ) ;
for ( V_56 = 0 ; V_56 < V_13 ; V_56 ++ ) {
F_18 ( ( V_15 ) V_16 [ V_56 ] ) ;
}
F_18 ( ( V_15 ) V_16 ) ;
return FALSE ;
}
V_6 = F_37 ( ( V_134 ) V_75 , V_135 ) ;
if ( V_87 == - 1 ) {
F_29 ( L_62 , F_38 ( V_136 ) ) ;
F_42 ( V_87 ) ;
F_39 ( V_74 ) ;
F_39 ( V_75 ) ;
for ( V_56 = 0 ; V_56 < V_13 ; V_56 ++ ) {
F_18 ( ( V_15 ) V_16 [ V_56 ] ) ;
}
F_18 ( V_16 ) ;
return FALSE ;
}
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_79 . V_141 = sizeof( V_79 ) ;
memset ( & V_80 , 0 , sizeof( V_80 ) ) ;
#ifdef F_33
V_79 . V_142 = V_143 ;
V_79 . V_144 = V_145 ;
#else
V_79 . V_142 = V_146 | V_143 ;
V_79 . V_144 = V_147 ;
#if F_43 ( F_2 )
if( V_89 . V_109 != NULL )
{
if( strncmp ( V_89 . V_109 , L_64 , 9 ) == 0 )
{
V_79 . V_148 = F_44 () ;
}
}
else
#endif
V_79 . V_148 = F_45 ( V_149 ) ;
V_79 . V_150 = F_45 ( V_151 ) ;
V_79 . V_152 = V_74 ;
#endif
for( V_56 = 0 ; V_16 [ V_56 ] != 0 ; V_56 ++ ) {
if( V_56 != 0 ) F_46 ( args , ' ' ) ;
V_76 = F_8 ( V_16 [ V_56 ] ) ;
F_47 ( args , V_76 ) ;
F_18 ( V_76 ) ;
}
V_77 = F_48 ( args -> V_153 , ( V_154 ) args -> V_20 , NULL , NULL , NULL ) ;
if( ! F_49 ( F_41 ( V_16 [ 0 ] ) , V_77 , NULL , NULL , TRUE ,
V_155 , NULL , NULL , & V_79 , & V_80 ) ) {
F_29 ( L_65 ,
args -> V_153 , F_10 ( F_36 () ) ) ;
F_42 ( V_87 ) ;
F_39 ( V_74 ) ;
F_39 ( V_75 ) ;
for ( V_56 = 0 ; V_56 < V_13 ; V_56 ++ ) {
F_18 ( ( V_15 ) V_16 [ V_56 ] ) ;
}
F_18 ( ( V_15 ) V_16 ) ;
F_50 ( args , TRUE ) ;
F_18 ( V_77 ) ;
return FALSE ;
}
V_1 -> V_4 = V_80 . V_156 ;
F_39 ( V_80 . V_157 ) ;
F_50 ( args , TRUE ) ;
F_18 ( V_77 ) ;
V_1 -> V_6 = V_6 ;
#else
if ( F_51 ( V_84 ) < 0 ) {
F_29 ( L_61 , F_38 ( V_136 ) ) ;
for ( V_56 = 0 ; V_56 < V_13 ; V_56 ++ ) {
F_18 ( ( V_15 ) V_16 [ V_56 ] ) ;
}
F_18 ( V_16 ) ;
return FALSE ;
}
if ( ( V_1 -> V_4 = F_52 () ) == 0 ) {
F_53 ( V_84 [ V_86 ] , 2 ) ;
F_42 ( V_84 [ V_85 ] ) ;
F_54 ( V_16 [ 0 ] , V_16 ) ;
F_12 ( V_83 , sizeof V_83 , L_65 ,
V_16 [ 0 ] , F_38 ( V_136 ) ) ;
F_55 ( 2 , V_83 , L_66 ) ;
F_56 ( 1 ) ;
}
if ( V_158 && V_1 -> V_4 > 0 )
V_158 ( V_1 -> V_4 ) ;
V_87 = V_84 [ V_85 ] ;
#endif
for ( V_56 = 0 ; V_56 < V_13 ; V_56 ++ ) {
F_18 ( ( V_15 ) V_16 [ V_56 ] ) ;
}
F_18 ( ( V_15 ) V_16 ) ;
#ifdef F_2
F_39 ( V_74 ) ;
#else
F_42 ( V_84 [ V_86 ] ) ;
#endif
if ( V_1 -> V_4 == V_5 ) {
F_29 ( L_67 , F_38 ( V_136 ) ) ;
F_42 ( V_87 ) ;
#ifdef F_2
F_42 ( V_1 -> V_6 ) ;
#endif
return FALSE ;
}
V_1 -> V_159 = 0 ;
V_1 -> V_59 = V_59 ;
V_1 -> V_160 = V_60 ;
if ( F_20 ) F_20 () ;
F_57 ( V_87 , ( V_15 ) V_1 ,
& V_1 -> V_4 , V_161 ) ;
return TRUE ;
}
static int
F_58 ( char * * V_16 , int * V_162 ,
int * V_163 , T_18 * V_4 , T_2 * * V_32 , void (* F_20)( void ) )
{
enum T_15 { V_85 , V_86 };
#ifdef F_2
T_9 V_84 [ 2 ] ;
T_9 V_164 [ 2 ] ;
T_10 * args = F_24 ( 200 ) ;
T_2 * V_76 ;
T_11 * V_77 ;
T_12 V_78 ;
T_13 V_79 ;
T_14 V_80 ;
#else
char V_83 [ 1024 + 1 ] ;
int V_84 [ 2 ] ;
int V_164 [ 2 ] ;
#endif
int V_56 ;
* V_4 = V_5 ;
* V_162 = - 1 ;
* V_163 = - 1 ;
F_25 ( V_92 , V_93 , L_68 ) ;
if ( ! V_32 ) {
#ifdef F_2
F_50 ( args , TRUE ) ;
#endif
return - 1 ;
}
#ifdef F_2
V_78 . V_131 = sizeof( T_12 ) ;
V_78 . V_132 = TRUE ;
V_78 . V_133 = NULL ;
if ( ! F_35 ( & V_84 [ V_85 ] , & V_84 [ V_86 ] , & V_78 , 5120 ) ) {
* V_32 = F_17 ( L_61 ,
F_10 ( F_36 () ) ) ;
for ( V_56 = 0 ; V_16 [ V_56 ] != NULL ; V_56 ++ ) {
F_18 ( ( V_15 ) V_16 [ V_56 ] ) ;
}
F_18 ( ( V_15 ) V_16 ) ;
return - 1 ;
}
* V_163 = F_37 ( ( V_134 ) V_84 [ V_85 ] , V_135 ) ;
if ( * V_163 == - 1 ) {
* V_32 = F_17 ( L_69 , F_38 ( V_136 ) ) ;
F_39 ( V_84 [ V_85 ] ) ;
F_39 ( V_84 [ V_86 ] ) ;
for ( V_56 = 0 ; V_16 [ V_56 ] != NULL ; V_56 ++ ) {
F_18 ( ( V_15 ) V_16 [ V_56 ] ) ;
}
F_18 ( ( V_15 ) V_16 ) ;
return - 1 ;
}
if ( ! F_35 ( & V_164 [ V_85 ] , & V_164 [ V_86 ] , & V_78 , 5120 ) ) {
* V_32 = F_17 ( L_70 ,
F_10 ( F_36 () ) ) ;
F_42 ( * V_163 ) ;
F_39 ( V_84 [ V_86 ] ) ;
for ( V_56 = 0 ; V_16 [ V_56 ] != NULL ; V_56 ++ ) {
F_18 ( ( V_15 ) V_16 [ V_56 ] ) ;
}
F_18 ( ( V_15 ) V_16 ) ;
return - 1 ;
}
* V_162 = F_37 ( ( V_134 ) V_164 [ V_85 ] , V_135 ) ;
if ( * V_162 == - 1 ) {
* V_32 = F_17 ( L_71 , F_38 ( V_136 ) ) ;
F_39 ( V_164 [ V_85 ] ) ;
F_39 ( V_164 [ V_86 ] ) ;
F_42 ( * V_163 ) ;
F_39 ( V_84 [ V_86 ] ) ;
for ( V_56 = 0 ; V_16 [ V_56 ] != NULL ; V_56 ++ ) {
F_18 ( ( V_15 ) V_16 [ V_56 ] ) ;
}
F_18 ( ( V_15 ) V_16 ) ;
return - 1 ;
}
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_79 . V_141 = sizeof( V_79 ) ;
memset ( & V_80 , 0 , sizeof( V_80 ) ) ;
#ifdef F_33
V_79 . V_142 = V_143 ;
V_79 . V_144 = V_145 ;
#else
V_79 . V_142 = V_146 | V_143 ;
V_79 . V_144 = V_147 ;
V_79 . V_148 = NULL ;
V_79 . V_150 = V_164 [ V_86 ] ;
V_79 . V_152 = V_84 [ V_86 ] ;
#endif
for( V_56 = 0 ; V_16 [ V_56 ] != 0 ; V_56 ++ ) {
if( V_56 != 0 ) F_46 ( args , ' ' ) ;
V_76 = F_8 ( V_16 [ V_56 ] ) ;
F_47 ( args , V_76 ) ;
F_18 ( V_76 ) ;
}
V_77 = F_48 ( args -> V_153 , ( V_154 ) args -> V_20 , NULL , NULL , NULL ) ;
if( ! F_49 ( F_41 ( V_16 [ 0 ] ) , V_77 , NULL , NULL , TRUE ,
V_155 , NULL , NULL , & V_79 , & V_80 ) ) {
* V_32 = F_17 ( L_65 ,
args -> V_153 , F_10 ( F_36 () ) ) ;
F_42 ( * V_162 ) ;
F_39 ( V_164 [ V_86 ] ) ;
F_42 ( * V_163 ) ;
F_39 ( V_84 [ V_86 ] ) ;
for ( V_56 = 0 ; V_16 [ V_56 ] != NULL ; V_56 ++ ) {
F_18 ( ( V_15 ) V_16 [ V_56 ] ) ;
}
F_18 ( ( V_15 ) V_16 ) ;
F_50 ( args , TRUE ) ;
F_18 ( V_77 ) ;
return - 1 ;
}
* V_4 = V_80 . V_156 ;
F_39 ( V_80 . V_157 ) ;
F_50 ( args , TRUE ) ;
F_18 ( V_77 ) ;
#else
if ( F_51 ( V_84 ) < 0 ) {
* V_32 = F_17 ( L_61 , F_38 ( V_136 ) ) ;
for ( V_56 = 0 ; V_16 [ V_56 ] != NULL ; V_56 ++ ) {
F_18 ( ( V_15 ) V_16 [ V_56 ] ) ;
}
F_18 ( V_16 ) ;
return - 1 ;
}
if ( F_51 ( V_164 ) < 0 ) {
* V_32 = F_17 ( L_70 , F_38 ( V_136 ) ) ;
F_42 ( V_84 [ V_85 ] ) ;
F_42 ( V_84 [ V_86 ] ) ;
for ( V_56 = 0 ; V_16 [ V_56 ] != NULL ; V_56 ++ ) {
F_18 ( ( V_15 ) V_16 [ V_56 ] ) ;
}
F_18 ( V_16 ) ;
return - 1 ;
}
if ( ( * V_4 = F_52 () ) == 0 ) {
F_53 ( V_164 [ V_86 ] , 1 ) ;
F_42 ( V_164 [ V_85 ] ) ;
F_42 ( V_164 [ V_86 ] ) ;
F_53 ( V_84 [ V_86 ] , 2 ) ;
F_42 ( V_84 [ V_85 ] ) ;
F_42 ( V_84 [ V_86 ] ) ;
F_54 ( V_16 [ 0 ] , V_16 ) ;
F_12 ( V_83 , sizeof V_83 , L_65 ,
V_16 [ 0 ] , F_38 ( V_136 ) ) ;
F_55 ( 2 , V_83 , L_66 ) ;
F_56 ( 1 ) ;
}
if ( V_158 && * V_4 > 0 )
V_158 ( * V_4 ) ;
* V_162 = V_164 [ V_85 ] ;
* V_163 = V_84 [ V_85 ] ;
#endif
for ( V_56 = 0 ; V_16 [ V_56 ] != NULL ; V_56 ++ ) {
F_18 ( ( V_15 ) V_16 [ V_56 ] ) ;
}
F_18 ( ( V_15 ) V_16 ) ;
#ifdef F_2
F_39 ( V_164 [ V_86 ] ) ;
F_39 ( V_84 [ V_86 ] ) ;
#else
F_42 ( V_164 [ V_86 ] ) ;
F_42 ( V_84 [ V_86 ] ) ;
#endif
if ( * V_4 == V_5 ) {
* V_32 = F_17 ( L_67 , F_38 ( V_136 ) ) ;
F_42 ( * V_162 ) ;
F_42 ( * V_163 ) ;
return - 1 ;
}
if ( F_20 ) F_20 () ;
return 0 ;
}
static int
F_59 ( int * V_162 , int * V_163 ,
T_18 * V_4 , T_2 * * V_165 )
{
F_42 ( * V_162 ) ;
if ( V_163 != NULL )
F_42 ( * V_163 ) ;
#ifdef F_2
F_60 ( * V_4 ) ;
#endif
return F_61 ( * V_4 , V_165 ) ;
}
static int
F_62 ( char * * V_16 , T_2 * * V_166 , T_2 * * V_167 ,
T_2 * * V_168 , void (* F_20)( void ) )
{
T_2 * V_32 ;
int V_169 , V_87 , V_170 ;
T_18 V_4 ;
char * V_171 ;
T_2 V_172 [ V_173 + 1 ] = { 0 } ;
T_19 V_174 ;
char V_175 ;
int V_176 ;
char * V_177 ;
int V_178 ;
char * V_179 ;
char * V_180 ;
T_10 * V_181 = NULL ;
T_19 V_11 ;
V_170 = F_58 ( V_16 , & V_169 , & V_87 ,
& V_4 , & V_32 , F_20 ) ;
if ( V_170 == - 1 ) {
* V_167 = V_32 ;
* V_168 = NULL ;
* V_166 = NULL ;
return - 1 ;
}
V_174 = F_63 ( V_87 , & V_175 , V_182 ,
V_172 , V_167 ) ;
if( V_174 <= 0 ) {
V_170 = F_61 ( V_4 , & V_171 ) ;
if( V_174 == 0 ) {
if ( V_170 == - 1 )
* V_167 = V_171 ;
else
* V_167 = F_7 ( L_72 ) ;
} else {
if ( V_170 == - 1 ) {
V_180 = F_17 ( L_73 , * V_167 , V_171 ) ;
F_18 ( * V_167 ) ;
F_18 ( V_171 ) ;
* V_167 = V_180 ;
}
}
* V_168 = NULL ;
* V_166 = NULL ;
return - 1 ;
}
switch( V_175 ) {
case V_183 :
F_64 ( ( V_184 * ) V_172 , 4 , & V_175 , & V_176 ) ;
V_177 = V_172 + 4 ;
F_64 ( ( V_184 * ) V_177 + V_176 , 4 , & V_175 ,
& V_178 ) ;
V_179 = V_177 + V_176 + 4 ;
V_170 = F_59 ( & V_169 , & V_87 ,
& V_4 , & V_32 ) ;
if ( V_170 == - 1 ) {
* V_167 = V_32 ;
* V_168 = NULL ;
} else {
* V_167 = F_7 ( V_177 ) ;
* V_168 = F_7 ( V_179 ) ;
V_170 = - 1 ;
}
* V_166 = NULL ;
break;
case V_185 :
V_181 = F_65 ( L_66 ) ;
while ( ( V_11 = F_66 ( V_169 , V_172 , V_173 ) ) > 0 ) {
V_172 [ V_11 ] = '\0' ;
F_47 ( V_181 , V_172 ) ;
}
V_170 = F_59 ( & V_169 , & V_87 ,
& V_4 , & V_32 ) ;
if ( V_170 == - 1 ) {
* V_167 = V_32 ;
* V_168 = NULL ;
F_50 ( V_181 , TRUE ) ;
* V_166 = NULL ;
} else {
* V_167 = NULL ;
* V_168 = NULL ;
* V_166 = F_50 ( V_181 , FALSE ) ;
}
break;
default:
V_170 = F_59 ( & V_169 , & V_87 ,
& V_4 , & V_32 ) ;
if ( V_170 == - 1 ) {
* V_167 = V_32 ;
* V_168 = NULL ;
} else {
* V_167 = F_17 ( L_74 ,
V_175 ) ;
* V_168 = NULL ;
V_170 = - 1 ;
}
* V_166 = NULL ;
break;
}
return V_170 ;
}
static int
F_67 ( char * * V_16 , T_2 * * V_166 , T_2 * * V_167 ,
T_2 * * V_168 , void (* F_20)( void ) )
{
int V_170 , V_56 ;
T_20 V_186 ;
T_20 V_187 ;
float V_188 ;
int V_189 ;
V_189 = ( ( V_93 | V_190 ) & V_191 & V_192 . V_193 ) ;
if( V_189 ) {
F_68 ( & V_186 ) ;
F_25 ( V_92 , V_190 , L_75 ) ;
for( V_56 = 0 ; V_16 [ V_56 ] != 0 ; V_56 ++ ) {
F_25 ( V_92 , V_93 , L_76 , V_56 , V_16 [ V_56 ] ) ;
}
}
V_170 = F_62 ( V_16 , V_166 , V_167 , V_168 , F_20 ) ;
if( V_189 ) {
F_68 ( & V_187 ) ;
V_188 = ( float ) ( ( V_187 . V_194 - V_186 . V_194 ) +
( ( V_187 . V_195 - V_186 . V_195 ) / 1e6 ) ) ;
F_25 ( V_92 , V_190 , L_77 , V_188 , V_170 ) ;
}
return V_170 ;
}
int
F_69 ( const T_2 * V_196 , const char * V_197 , const T_2 * type ,
const T_2 * V_198 , const T_2 * V_199 ,
T_2 * * V_166 , T_2 * * V_167 ,
T_2 * * V_168 , void (* F_20)( void ) )
{
int V_13 , V_170 ;
char * * V_16 ;
T_2 * V_200 ;
V_16 = F_15 ( & V_13 ) ;
if ( ! V_16 ) {
* V_167 = F_7 ( L_29 ) ;
* V_168 = NULL ;
* V_166 = NULL ;
return - 1 ;
}
V_16 = F_5 ( V_16 , & V_13 , L_42 ) ;
V_16 = F_5 ( V_16 , & V_13 , V_196 ) ;
if ( type )
V_200 = F_17 ( L_78 , V_197 , type , V_198 , V_199 ) ;
else
V_200 = F_7 ( V_197 ) ;
if ( ! V_200 ) {
* V_167 = F_7 ( L_79 ) ;
* V_168 = NULL ;
* V_166 = NULL ;
return - 1 ;
}
V_16 = F_5 ( V_16 , & V_13 , L_80 ) ;
V_16 = F_5 ( V_16 , & V_13 , V_200 ) ;
#ifndef F_33
V_16 = F_5 ( V_16 , & V_13 , L_58 ) ;
V_16 = F_5 ( V_16 , & V_13 , V_129 ) ;
#endif
V_170 = F_67 ( V_16 , V_166 , V_167 , V_168 , F_20 ) ;
F_18 ( V_200 ) ;
return V_170 ;
}
int
F_70 ( T_2 * * V_166 , T_2 * * V_167 ,
T_2 * * V_168 , void (* F_20)( void ) )
{
int V_13 ;
char * * V_16 ;
F_25 ( V_92 , V_93 , L_81 ) ;
V_16 = F_15 ( & V_13 ) ;
if ( ! V_16 ) {
* V_167 = F_7 ( L_82 ) ;
* V_168 = NULL ;
* V_166 = NULL ;
return - 1 ;
}
V_16 = F_5 ( V_16 , & V_13 , L_83 ) ;
#ifndef F_33
V_16 = F_5 ( V_16 , & V_13 , L_58 ) ;
V_16 = F_5 ( V_16 , & V_13 , V_129 ) ;
#endif
return F_67 ( V_16 , V_166 , V_167 , V_168 , F_20 ) ;
}
int
F_71 ( const T_2 * V_201 , T_4 V_117 , const T_2 * V_202 ,
T_2 * * V_166 , T_2 * * V_167 ,
T_2 * * V_168 , void (* F_20)( void ) )
{
int V_13 ;
char * * V_16 ;
F_25 ( V_92 , V_93 , L_84 ) ;
V_16 = F_15 ( & V_13 ) ;
if ( ! V_16 ) {
* V_167 = F_7 ( L_29 ) ;
* V_168 = NULL ;
* V_166 = NULL ;
return - 1 ;
}
V_16 = F_5 ( V_16 , & V_13 , L_42 ) ;
V_16 = F_5 ( V_16 , & V_13 , V_201 ) ;
V_16 = F_5 ( V_16 , & V_13 , L_85 ) ;
if ( V_117 )
V_16 = F_5 ( V_16 , & V_13 , L_48 ) ;
if ( V_202 ) {
V_16 = F_5 ( V_16 , & V_13 , L_51 ) ;
V_16 = F_5 ( V_16 , & V_13 , V_202 ) ;
}
#ifndef F_33
V_16 = F_5 ( V_16 , & V_13 , L_58 ) ;
V_16 = F_5 ( V_16 , & V_13 , V_129 ) ;
#endif
return F_67 ( V_16 , V_166 , V_167 , V_168 , F_20 ) ;
}
int
F_72 ( int * V_162 , T_18 * V_4 , T_2 * * V_32 , void (* F_20)( void ) )
{
int V_13 ;
char * * V_16 ;
int V_163 , V_170 ;
char * V_171 ;
T_2 V_172 [ V_173 + 1 ] = { 0 } ;
T_19 V_174 ;
char V_175 ;
int V_176 ;
char * V_177 ;
int V_178 ;
char * V_180 ;
F_25 ( V_92 , V_93 , L_86 ) ;
V_16 = F_15 ( & V_13 ) ;
if ( ! V_16 ) {
* V_32 = F_7 ( L_29 ) ;
return - 1 ;
}
V_16 = F_5 ( V_16 , & V_13 , L_87 ) ;
#ifndef F_33
V_16 = F_5 ( V_16 , & V_13 , L_58 ) ;
#ifdef F_2
F_73 () ;
V_16 = F_5 ( V_16 , & V_13 , V_203 ) ;
#else
V_16 = F_5 ( V_16 , & V_13 , V_129 ) ;
#endif
#endif
V_170 = F_58 ( V_16 , V_162 , & V_163 ,
V_4 , V_32 , F_20 ) ;
if ( V_170 == - 1 )
return - 1 ;
V_174 = F_63 ( V_163 , & V_175 , V_182 ,
V_172 , V_32 ) ;
if( V_174 <= 0 ) {
V_170 = F_61 ( * V_4 , & V_171 ) ;
F_42 ( V_163 ) ;
F_42 ( * V_162 ) ;
if( V_174 == 0 ) {
if ( V_170 == - 1 )
* V_32 = V_171 ;
else
* V_32 = F_7 ( L_72 ) ;
} else {
if ( V_170 == - 1 ) {
V_180 = F_17 ( L_73 , * V_32 , V_171 ) ;
F_18 ( * V_32 ) ;
F_18 ( V_171 ) ;
* V_32 = V_180 ;
}
}
return - 1 ;
}
switch( V_175 ) {
case V_183 :
F_64 ( ( V_184 * ) V_172 , 4 , & V_175 , & V_176 ) ;
V_177 = V_172 + 4 ;
F_64 ( ( V_184 * ) V_177 + V_176 , 4 , & V_175 ,
& V_178 ) ;
V_170 = F_59 ( V_162 , & V_163 ,
V_4 , V_32 ) ;
if ( V_170 == - 1 ) {
} else {
* V_32 = F_7 ( V_177 ) ;
V_170 = - 1 ;
}
break;
case V_185 :
F_42 ( V_163 ) ;
break;
default:
V_170 = F_59 ( V_162 , & V_163 ,
V_4 , V_32 ) ;
if ( V_170 == - 1 ) {
} else {
* V_32 = F_17 ( L_74 ,
V_175 ) ;
V_170 = - 1 ;
}
break;
}
return V_170 ;
}
int
F_74 ( int * V_204 , T_18 * V_4 , T_2 * * V_32 )
{
#ifndef F_2
F_60 ( * V_4 ) ;
#endif
return F_59 ( V_204 , NULL , V_4 , V_32 ) ;
}
static T_19
F_75 ( int V_205 , char * V_206 , int V_207 , char * * V_32 )
{
T_19 V_208 ;
T_19 V_209 = 0 ;
int error ;
while( V_207 ) {
V_208 = F_66 ( V_205 , & V_206 [ V_209 ] , V_207 ) ;
if ( V_208 == 0 ) {
F_25 ( V_92 , V_93 ,
L_88 , V_205 ) ;
* V_32 = 0 ;
return V_209 ;
}
if ( V_208 < 0 ) {
error = V_136 ;
F_25 ( V_92 , V_93 ,
L_89 , V_205 , error ,
F_38 ( error ) ) ;
* V_32 = F_17 ( L_90 ,
F_38 ( error ) ) ;
return V_208 ;
}
V_207 -= ( int ) V_208 ;
V_209 += V_208 ;
}
* V_32 = NULL ;
return V_209 ;
}
static T_4 F_76 ( int V_205 ) {
#ifdef F_2
T_9 V_210 = ( T_9 ) F_77 ( V_205 ) ;
T_5 V_211 ;
if ( V_210 == V_140 )
return FALSE ;
if ( ! F_78 ( V_210 , NULL , 0 , NULL , & V_211 , NULL ) )
return FALSE ;
if ( V_211 > 0 )
return TRUE ;
return FALSE ;
#else
T_21 V_212 ;
struct V_213 V_214 ;
F_79 ( & V_212 ) ;
F_80 ( V_205 , & V_212 ) ;
V_214 . V_194 = 0 ;
V_214 . V_195 = 0 ;
if ( F_81 ( V_205 + 1 , & V_212 , NULL , NULL , & V_214 ) > 0 )
return TRUE ;
return FALSE ;
#endif
}
int
F_82 ( int V_205 , char * V_206 , int V_215 ) {
T_19 V_208 ;
int V_209 = - 1 ;
while( V_209 < V_215 - 1 ) {
V_209 ++ ;
if ( ! F_76 ( V_205 ) )
break;
V_208 = F_66 ( V_205 , & V_206 [ V_209 ] , 1 ) ;
if ( V_208 == 0 ) {
break;
} else if ( V_208 == - 1 ) {
F_25 ( V_92 , V_93 ,
L_89 , V_205 , V_136 , F_38 ( V_136 ) ) ;
return - 1 ;
} else if ( V_206 [ V_209 ] == '\n' ) {
break;
}
}
if ( V_209 >= 0 )
V_206 [ V_209 ] = '\0' ;
return V_209 ;
}
static void
F_64 ( const V_184 * V_216 , int V_217 , char * V_175 , int * V_218 ) {
F_83 ( V_217 == 4 ) ;
* V_175 = V_216 [ 0 ] ;
* V_218 = ( V_216 [ 1 ] & 0xFF ) << 16 | ( V_216 [ 2 ] & 0xFF ) << 8 | ( V_216 [ 3 ] & 0xFF ) ;
}
static T_19
F_63 ( int V_205 , char * V_175 , int V_20 , char * V_32 ,
char * * V_219 )
{
int V_207 ;
T_19 V_208 ;
T_2 V_216 [ 4 ] ;
V_208 = F_75 ( V_205 , V_216 , 4 , V_219 ) ;
if( V_208 != 4 ) {
if ( V_208 == 0 ) {
F_25 ( V_92 , V_93 ,
L_91 , V_205 ) ;
return 0 ;
}
F_25 ( V_92 , V_93 ,
L_92 , V_205 , ( long ) V_208 ) ;
if ( V_208 != - 1 ) {
* V_219 = F_17 ( L_93 ,
( long ) V_208 ) ;
}
return - 1 ;
}
F_64 ( ( V_184 * ) V_216 , 4 , V_175 , & V_207 ) ;
if( V_207 == 0 ) {
F_25 ( V_92 , V_93 ,
L_94 , V_205 , * V_175 ) ;
return 4 ;
}
if( V_207 > V_20 ) {
F_25 ( V_92 , V_93 ,
L_95 ,
V_205 , V_207 , V_20 ,
V_216 [ 0 ] , V_216 [ 1 ] , V_216 [ 2 ] , V_216 [ 3 ] ) ;
memcpy ( V_32 , V_216 , sizeof( V_216 ) ) ;
V_208 = F_66 ( V_205 , & V_32 [ sizeof( V_216 ) ] , V_20 - sizeof( V_216 ) ) ;
if ( V_208 < 0 ) {
F_25 ( V_92 , V_93 ,
L_89 , V_205 , V_136 , F_38 ( V_136 ) ) ;
}
* V_219 = F_17 ( L_96 ,
V_32 ) ;
return - 1 ;
}
V_20 = V_207 ;
V_208 = F_75 ( V_205 , V_32 , V_207 , V_219 ) ;
if( V_208 != V_207 ) {
if ( V_208 != - 1 ) {
* V_219 = F_17 ( L_96 ,
V_32 ) ;
}
return - 1 ;
}
F_25 ( V_92 , V_93 ,
L_97 , V_205 , * V_175 ,
V_20 , V_32 ) ;
* V_219 = NULL ;
return V_208 + 4 ;
}
static T_4
V_161 ( T_3 V_220 , V_15 V_221 )
{
T_1 * V_1 = ( T_1 * ) V_221 ;
int V_170 ;
char V_172 [ V_182 + 1 ] = { 0 } ;
T_19 V_174 ;
char V_175 ;
int V_222 ;
char * V_167 ;
int V_223 ;
char * V_168 ;
char * V_171 , * V_180 ;
int V_224 ;
V_174 = F_63 ( V_220 , & V_175 , V_182 , V_172 ,
& V_167 ) ;
if( V_174 <= 0 ) {
V_170 = F_61 ( V_1 -> V_4 , & V_171 ) ;
if( V_174 == 0 ) {
if ( V_170 == - 1 )
V_167 = V_171 ;
} else {
if ( V_170 == - 1 ) {
V_180 = F_17 ( L_73 , V_167 , V_171 ) ;
F_18 ( V_167 ) ;
F_18 ( V_171 ) ;
V_167 = V_180 ;
}
}
V_1 -> V_4 = V_5 ;
V_1 -> V_159 = V_170 ;
#ifdef F_2
F_42 ( V_1 -> V_6 ) ;
#endif
#ifdef F_27
F_25 ( V_92 , V_93 , L_98 ) ;
F_84 ( V_1 -> V_59 ) ;
#endif
F_85 ( V_1 , V_167 ) ;
F_18 ( V_167 ) ;
return FALSE ;
}
switch( V_175 ) {
case V_225 :
if( ! F_86 ( V_1 , V_172 ) ) {
F_25 ( V_92 , V_93 , L_99 ) ;
F_42 ( V_220 ) ;
F_87 ( V_1 ) ;
F_85 ( V_1 , NULL ) ;
return FALSE ;
}
break;
case V_226 :
V_224 = atoi ( V_172 ) ;
F_25 ( V_92 , V_93 , L_100 , V_224 ) ;
V_1 -> V_11 += V_224 ;
F_88 ( V_1 , V_224 ) ;
break;
case V_183 :
F_64 ( ( V_184 * ) V_172 , 4 , & V_175 , & V_222 ) ;
V_167 = V_172 + 4 ;
F_64 ( ( V_184 * ) V_167 + V_222 , 4 , & V_175 , & V_223 ) ;
V_168 = V_167 + V_222 + 4 ;
F_89 ( V_1 , V_167 , V_168 ) ;
break;
case V_227 : {
char * V_228 = NULL ;
int V_229 = 0 ;
V_228 = strtok ( V_172 , L_101 ) ;
if ( V_228 ) {
V_229 = ( int ) strtol ( V_228 , NULL , 10 ) ;
V_228 = strtok ( NULL , L_101 ) ;
}
F_90 ( V_1 , V_229 , V_228 ) ;
break;
}
case V_230 :
F_91 ( V_1 , ( V_231 ) strtoul ( V_172 , NULL , 10 ) ) ;
break;
default:
F_92 () ;
}
return TRUE ;
}
static int
F_61 ( T_18 V_4 , T_2 * * V_165 )
{
int V_159 ;
#ifndef F_2
int V_232 = 3 ;
#endif
int V_170 = - 1 ;
T_20 V_186 ;
T_20 V_187 ;
float V_188 ;
F_68 ( & V_186 ) ;
F_25 ( V_92 , V_93 , L_102 ) ;
F_83 ( V_4 != V_5 ) ;
* V_165 = NULL ;
#ifdef F_2
if ( F_93 ( & V_159 , ( V_134 ) V_4 , V_233 ) == - 1 ) {
* V_165 = F_17 ( L_103 , F_38 ( V_136 ) ) ;
V_170 = - 1 ;
} else {
V_170 = V_159 ;
if ( ( V_159 & 0xC0000000 ) == V_234 ) {
* V_165 = F_17 ( L_104 ,
F_13 ( V_159 ) ) ;
V_170 = - 1 ;
}
}
#else
while ( -- V_232 >= 0 ) {
if ( F_94 ( V_4 , & V_159 , 0 ) != - 1 ) {
if ( F_95 ( V_159 ) ) {
V_170 = F_96 ( V_159 ) ;
} else if ( F_97 ( V_159 ) ) {
* V_165 = F_17 ( L_105 ,
F_98 ( F_99 ( V_159 ) ) ) ;
V_170 = - 1 ;
} else if ( F_100 ( V_159 ) ) {
* V_165 = F_17 ( L_106 ,
F_98 ( F_101 ( V_159 ) ) ,
F_102 ( V_159 ) ? L_107 : L_66 ) ;
V_170 = - 1 ;
} else {
* V_165 = F_17 ( L_108 ,
V_159 ) ;
V_170 = - 1 ;
}
} else {
if ( V_136 == V_235 ) {
F_25 ( V_92 , V_236 , L_109 ) ;
continue;
} else if ( V_136 == V_237 ) {
V_170 = V_158 ? 0 : - 1 ;
} else {
* V_165 = F_17 ( L_110 , F_38 ( V_136 ) ) ;
V_170 = - 1 ;
}
}
break;
}
#endif
F_68 ( & V_187 ) ;
V_188 = ( float ) ( ( V_187 . V_194 - V_186 . V_194 ) +
( ( V_187 . V_195 - V_186 . V_195 ) / 1e6 ) ) ;
F_25 ( V_92 , V_93 , L_111 , V_188 ) ;
return V_170 ;
}
static const char *
F_98 ( int V_238 )
{
const char * V_239 ;
static char V_240 [ 6 + 1 + 3 + 1 ] ;
switch ( V_238 ) {
case V_241 :
V_239 = L_112 ;
break;
case V_242 :
V_239 = L_113 ;
break;
case V_243 :
V_239 = L_114 ;
break;
case V_244 :
V_239 = L_14 ;
break;
case V_245 :
V_239 = L_115 ;
break;
case V_246 :
V_239 = L_116 ;
break;
case V_247 :
V_239 = L_117 ;
break;
case V_248 :
V_239 = L_118 ;
break;
case V_249 :
V_239 = L_119 ;
break;
case V_250 :
V_239 = L_120 ;
break;
#ifdef F_103
case F_103 :
V_239 = L_121 ;
break;
#endif
case V_251 :
V_239 = L_122 ;
break;
case V_252 :
V_239 = L_123 ;
break;
case V_253 :
V_239 = L_124 ;
break;
default:
F_12 ( V_240 , sizeof V_240 , L_125 , V_238 ) ;
V_239 = V_240 ;
break;
}
return V_239 ;
}
static void F_73 () {
T_2 * V_254 ;
if ( V_255 != NULL ) return;
if ( ! V_203 ) {
V_203 = F_17 ( L_126 , F_34 () ) ;
}
V_254 = F_17 ( V_137 , V_203 ) ;
V_255 = F_40 ( F_41 ( V_254 ) ,
V_138 , V_139 , 1 , 65535 , 65535 , 0 , NULL ) ;
F_18 ( V_254 ) ;
}
static void
F_104 ( T_1 * V_1 )
{
const char V_256 [] = L_127 ;
int V_170 ;
F_25 ( V_92 , V_93 , L_128 ) ;
V_170 = F_105 ( V_1 -> V_6 , V_256 , sizeof V_256 ) ;
if( V_170 == - 1 ) {
F_25 ( V_257 , V_236 ,
L_129 , V_1 -> V_6 , F_38 ( V_136 ) ) ;
}
}
void
F_87 ( T_1 * V_1 )
{
#ifdef F_2
int V_11 ;
T_5 V_258 ;
T_4 V_259 = TRUE ;
#endif
if ( V_1 -> V_4 != V_5 ) {
#ifndef F_2
int V_260 = F_106 ( V_1 -> V_4 , V_242 ) ;
if ( V_260 != 0 ) {
F_25 ( V_257 , V_236 ,
L_130 , F_38 ( V_136 ) ) ;
}
#else
#define F_107 500
#define F_108 50
F_104 ( V_1 ) ;
for ( V_11 = 0 ; V_11 < F_107 / F_108 ; V_11 ++ ) {
if ( F_109 ( ( T_9 ) V_1 -> V_4 , & V_258 ) &&
V_258 != V_261 ) {
V_259 = FALSE ;
break;
}
F_110 ( F_108 ) ;
}
if ( V_259 ) {
F_25 ( V_257 , V_236 ,
L_131 ) ;
F_60 ( V_1 -> V_4 ) ;
}
#endif
}
}
void
F_60 ( T_18 V_4 )
{
if ( V_4 != V_5 ) {
#ifndef F_2
int V_260 = F_106 ( V_4 , V_253 ) ;
if ( V_260 != 0 ) {
F_25 ( V_257 , V_236 ,
L_132 , F_38 ( V_136 ) ) ;
}
#else
F_111 ( ( T_9 ) ( V_4 ) , 0 ) ;
#endif
}
}
void F_112 ( void (* V_141)( T_18 V_262 ) ) {
V_158 = V_141 ;
}
