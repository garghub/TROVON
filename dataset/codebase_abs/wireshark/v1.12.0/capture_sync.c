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
V_13 = F_15 ( & V_10 ) ;
if ( ! V_13 ) {
F_27 ( L_28 ) ;
return FALSE ;
}
if ( V_57 -> V_87 -> V_17 > 1 )
V_13 = F_5 ( V_13 , & V_10 , L_29 ) ;
if ( V_57 -> V_88 )
V_13 = F_5 ( V_13 , & V_10 , L_30 ) ;
else
V_13 = F_5 ( V_13 , & V_10 , L_31 ) ;
if ( V_57 -> V_91 ) {
V_13 = F_5 ( V_13 , & V_10 , L_32 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_57 -> V_91 ) ;
}
if ( V_57 -> V_92 ) {
if ( V_57 -> V_93 ) {
V_13 = F_5 ( V_13 , & V_10 , L_33 ) ;
F_12 ( V_61 , V_59 , L_34 , V_57 -> V_94 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_61 ) ;
}
if ( V_57 -> V_95 ) {
V_13 = F_5 ( V_13 , & V_10 , L_33 ) ;
F_12 ( V_62 , V_59 , L_35 , V_57 -> V_96 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_62 ) ;
}
if ( V_57 -> V_97 ) {
V_13 = F_5 ( V_13 , & V_10 , L_33 ) ;
F_12 ( V_63 , V_59 , L_36 , V_57 -> V_98 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_63 ) ;
}
if ( V_57 -> V_99 ) {
V_13 = F_5 ( V_13 , & V_10 , L_37 ) ;
F_12 ( V_64 , V_59 , L_36 , V_57 -> V_100 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_64 ) ;
}
} else {
if ( V_57 -> V_93 ) {
V_13 = F_5 ( V_13 , & V_10 , L_37 ) ;
F_12 ( V_65 , V_59 , L_34 , V_57 -> V_94 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_65 ) ;
}
}
if ( V_57 -> V_101 ) {
V_13 = F_5 ( V_13 , & V_10 , L_38 ) ;
F_12 ( V_60 , V_59 , L_39 , V_57 -> V_102 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_60 ) ;
}
if ( V_57 -> V_103 ) {
V_13 = F_5 ( V_13 , & V_10 , L_37 ) ;
F_12 ( V_66 , V_59 , L_35 , V_57 -> V_104 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_66 ) ;
}
if ( V_57 -> V_105 ) {
V_13 = F_5 ( V_13 , & V_10 , L_40 ) ;
}
for ( V_85 = 0 ; V_85 < V_57 -> V_87 -> V_17 ; V_85 ++ ) {
V_86 = F_28 ( V_57 -> V_87 , T_15 , V_85 ) ;
V_13 = F_5 ( V_13 , & V_10 , L_41 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_86 . V_106 ) ;
if ( V_86 . V_107 != NULL && strlen ( V_86 . V_107 ) != 0 ) {
V_13 = F_5 ( V_13 , & V_10 , L_42 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_86 . V_107 ) ;
}
if ( V_86 . V_108 != V_109 ) {
V_13 = F_5 ( V_13 , & V_10 , L_43 ) ;
F_12 ( V_58 , V_59 , L_39 , V_86 . V_108 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_58 ) ;
}
if ( V_86 . V_110 != - 1 ) {
V_13 = F_5 ( V_13 , & V_10 , L_44 ) ;
V_13 = F_5 ( V_13 , & V_10 , F_29 ( V_86 . V_110 ) ) ;
}
if ( ! V_86 . V_111 ) {
V_13 = F_5 ( V_13 , & V_10 , L_45 ) ;
}
#if F_23 ( F_2 ) || F_23 ( V_69 )
if ( V_86 . V_70 != V_112 ) {
V_13 = F_5 ( V_13 , & V_10 , L_46 ) ;
F_12 ( V_70 , V_59 , L_39 , V_86 . V_70 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_70 ) ;
}
#endif
#ifdef V_69
if ( V_86 . V_113 ) {
V_13 = F_5 ( V_13 , & V_10 , L_47 ) ;
}
#endif
#ifdef F_21
if ( V_86 . V_114 )
V_13 = F_5 ( V_13 , & V_10 , L_48 ) ;
if ( ! V_86 . V_115 )
V_13 = F_5 ( V_13 , & V_10 , L_49 ) ;
if ( V_86 . V_116 == V_117 ) {
V_13 = F_5 ( V_13 , & V_10 , L_50 ) ;
F_12 ( V_67 , sizeof( V_67 ) , L_51 ,
V_86 . V_118 ,
V_86 . V_119 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_67 ) ;
}
#endif
#ifdef F_22
if ( V_86 . V_120 != V_121 ) {
V_13 = F_5 ( V_13 , & V_10 , L_52 ) ;
F_12 ( V_68 , V_59 , L_53 ,
V_86 . V_120 == V_122 ? L_54 :
V_86 . V_120 == V_123 ? L_55 :
L_56 ,
V_86 . V_124 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_68 ) ;
}
#endif
}
#ifndef F_30
V_13 = F_5 ( V_13 , & V_10 , L_57 ) ;
#ifdef F_2
F_12 ( V_78 , V_59 , L_39 , F_31 () ) ;
V_13 = F_5 ( V_13 , & V_10 , V_78 ) ;
#else
V_13 = F_5 ( V_13 , & V_10 , V_125 ) ;
#endif
#endif
if ( V_57 -> V_126 ) {
V_13 = F_5 ( V_13 , & V_10 , L_58 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_57 -> V_126 ) ;
}
for ( V_53 = 0 ; V_53 < V_10 ; V_53 ++ ) {
F_25 ( V_89 , V_90 , L_59 , V_53 , V_13 [ V_53 ] ) ;
}
#ifdef F_2
V_75 . V_127 = sizeof( T_10 ) ;
V_75 . V_128 = TRUE ;
V_75 . V_129 = NULL ;
if ( ! F_32 ( & V_71 , & V_72 , & V_75 , 5120 ) ) {
F_27 ( L_60 ,
F_10 ( F_33 () ) ) ;
for ( V_53 = 0 ; V_53 < V_10 ; V_53 ++ ) {
F_18 ( ( V_12 ) V_13 [ V_53 ] ) ;
}
F_18 ( ( V_12 ) V_13 ) ;
return FALSE ;
}
V_79 = F_17 ( V_130 , V_78 ) ;
V_73 = F_34 ( F_35 ( V_79 ) ,
V_131 , V_132 , 1 , 65535 , 65535 , 0 , NULL ) ;
F_18 ( V_79 ) ;
if ( V_73 == V_133 ) {
F_27 ( L_61 ,
F_10 ( F_33 () ) ) ;
for ( V_53 = 0 ; V_53 < V_10 ; V_53 ++ ) {
F_18 ( ( V_12 ) V_13 [ V_53 ] ) ;
}
F_18 ( ( V_12 ) V_13 ) ;
return FALSE ;
}
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
V_76 . V_134 = sizeof( V_76 ) ;
#ifdef F_30
V_76 . V_135 = V_136 ;
V_76 . V_137 = V_138 ;
#else
V_76 . V_135 = V_139 | V_136 ;
V_76 . V_137 = V_140 ;
V_76 . V_141 = F_36 ( V_142 ) ;
V_76 . V_143 = F_36 ( V_144 ) ;
V_76 . V_145 = V_72 ;
#endif
for( V_53 = 0 ; V_13 [ V_53 ] != 0 ; V_53 ++ ) {
if( V_53 != 0 ) F_37 ( args , ' ' ) ;
V_74 = F_8 ( V_13 [ V_53 ] ) ;
F_38 ( args , V_74 ) ;
F_18 ( V_74 ) ;
}
if( ! F_39 ( NULL , F_35 ( args -> V_146 ) , NULL , NULL , TRUE ,
V_147 , NULL , NULL , & V_76 , & V_77 ) ) {
F_27 ( L_62 ,
args -> V_146 , F_10 ( F_33 () ) ) ;
F_40 ( V_71 ) ;
F_40 ( V_72 ) ;
for ( V_53 = 0 ; V_53 < V_10 ; V_53 ++ ) {
F_18 ( ( V_12 ) V_13 [ V_53 ] ) ;
}
F_18 ( ( V_12 ) V_13 ) ;
return FALSE ;
}
V_1 -> V_3 = ( int ) V_77 . V_148 ;
F_41 ( args , TRUE ) ;
V_84 = F_42 ( ( long ) V_71 , V_149 ) ;
V_1 -> V_4 = F_42 ( ( long ) V_73 , V_149 ) ;
#else
if ( F_43 ( V_81 ) < 0 ) {
F_27 ( L_60 , F_44 ( V_150 ) ) ;
for ( V_53 = 0 ; V_53 < V_10 ; V_53 ++ ) {
F_18 ( ( V_12 ) V_13 [ V_53 ] ) ;
}
F_18 ( V_13 ) ;
return FALSE ;
}
if ( ( V_1 -> V_3 = F_45 () ) == 0 ) {
F_46 ( V_81 [ V_83 ] , 2 ) ;
F_47 ( V_81 [ V_82 ] ) ;
F_48 ( V_13 [ 0 ] , V_13 ) ;
F_12 ( V_80 , sizeof V_80 , L_62 ,
V_13 [ 0 ] , F_44 ( V_150 ) ) ;
F_49 ( 2 , V_80 , L_63 ) ;
F_50 ( 1 ) ;
}
if ( V_151 && V_1 -> V_3 > 0 )
V_151 ( V_1 -> V_3 ) ;
V_84 = V_81 [ V_82 ] ;
#endif
for ( V_53 = 0 ; V_53 < V_10 ; V_53 ++ ) {
F_18 ( ( V_12 ) V_13 [ V_53 ] ) ;
}
F_18 ( ( V_12 ) V_13 ) ;
#ifdef F_2
F_40 ( V_72 ) ;
#else
F_47 ( V_81 [ V_83 ] ) ;
#endif
if ( V_1 -> V_3 == - 1 ) {
F_27 ( L_64 , F_44 ( V_150 ) ) ;
F_47 ( V_84 ) ;
#ifdef F_2
F_47 ( V_1 -> V_4 ) ;
#endif
return FALSE ;
}
V_1 -> V_152 = 0 ;
V_1 -> V_57 = V_57 ;
if ( F_20 ) F_20 () ;
F_51 ( V_84 , ( V_12 ) V_1 ,
& V_1 -> V_3 , V_153 ) ;
return TRUE ;
}
static int
F_52 ( char * * V_13 , int * V_154 ,
int * V_155 , int * V_3 , T_2 * * V_29 , void (* F_20)( void ) )
{
enum T_13 { V_82 , V_83 };
#ifdef F_2
T_8 V_81 [ 2 ] ;
T_8 V_156 [ 2 ] ;
T_9 * args = F_24 ( 200 ) ;
T_2 * V_74 ;
T_10 V_75 ;
T_11 V_76 ;
T_12 V_77 ;
#else
char V_80 [ 1024 + 1 ] ;
int V_81 [ 2 ] ;
int V_156 [ 2 ] ;
#endif
int V_53 ;
* V_3 = - 1 ;
* V_154 = - 1 ;
* V_155 = - 1 ;
F_25 ( V_89 , V_90 , L_65 ) ;
if ( ! V_29 ) {
#ifdef F_2
F_41 ( args , TRUE ) ;
#endif
return - 1 ;
}
#ifdef F_2
V_75 . V_127 = sizeof( T_10 ) ;
V_75 . V_128 = TRUE ;
V_75 . V_129 = NULL ;
if ( ! F_32 ( & V_81 [ V_82 ] , & V_81 [ V_83 ] , & V_75 , 5120 ) ) {
* V_29 = F_17 ( L_60 ,
F_10 ( F_33 () ) ) ;
for ( V_53 = 0 ; V_13 [ V_53 ] != NULL ; V_53 ++ ) {
F_18 ( ( V_12 ) V_13 [ V_53 ] ) ;
}
F_18 ( ( V_12 ) V_13 ) ;
return - 1 ;
}
if ( ! F_32 ( & V_156 [ V_82 ] , & V_156 [ V_83 ] , & V_75 , 5120 ) ) {
* V_29 = F_17 ( L_66 ,
F_10 ( F_33 () ) ) ;
F_40 ( V_81 [ V_82 ] ) ;
F_40 ( V_81 [ V_83 ] ) ;
for ( V_53 = 0 ; V_13 [ V_53 ] != NULL ; V_53 ++ ) {
F_18 ( ( V_12 ) V_13 [ V_53 ] ) ;
}
F_18 ( ( V_12 ) V_13 ) ;
return - 1 ;
}
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
V_76 . V_134 = sizeof( V_76 ) ;
#ifdef F_30
V_76 . V_135 = V_136 ;
V_76 . V_137 = V_138 ;
#else
V_76 . V_135 = V_139 | V_136 ;
V_76 . V_137 = V_140 ;
V_76 . V_141 = NULL ;
V_76 . V_143 = V_156 [ V_83 ] ;
V_76 . V_145 = V_81 [ V_83 ] ;
#endif
for( V_53 = 0 ; V_13 [ V_53 ] != 0 ; V_53 ++ ) {
if( V_53 != 0 ) F_37 ( args , ' ' ) ;
V_74 = F_8 ( V_13 [ V_53 ] ) ;
F_38 ( args , V_74 ) ;
F_18 ( V_74 ) ;
}
if( ! F_39 ( NULL , F_35 ( args -> V_146 ) , NULL , NULL , TRUE ,
V_147 , NULL , NULL , & V_76 , & V_77 ) ) {
* V_29 = F_17 ( L_62 ,
args -> V_146 , F_10 ( F_33 () ) ) ;
F_40 ( V_156 [ V_82 ] ) ;
F_40 ( V_156 [ V_83 ] ) ;
F_40 ( V_81 [ V_82 ] ) ;
F_40 ( V_81 [ V_83 ] ) ;
for ( V_53 = 0 ; V_13 [ V_53 ] != NULL ; V_53 ++ ) {
F_18 ( ( V_12 ) V_13 [ V_53 ] ) ;
}
F_18 ( ( V_12 ) V_13 ) ;
return - 1 ;
}
* V_3 = ( int ) V_77 . V_148 ;
F_41 ( args , TRUE ) ;
* V_154 = F_42 ( ( long ) V_156 [ V_82 ] , V_149 ) ;
* V_155 = F_42 ( ( long ) V_81 [ V_82 ] , V_149 ) ;
#else
if ( F_43 ( V_81 ) < 0 ) {
* V_29 = F_17 ( L_60 , F_44 ( V_150 ) ) ;
for ( V_53 = 0 ; V_13 [ V_53 ] != NULL ; V_53 ++ ) {
F_18 ( ( V_12 ) V_13 [ V_53 ] ) ;
}
F_18 ( V_13 ) ;
return - 1 ;
}
if ( F_43 ( V_156 ) < 0 ) {
* V_29 = F_17 ( L_66 , F_44 ( V_150 ) ) ;
F_47 ( V_81 [ V_82 ] ) ;
F_47 ( V_81 [ V_83 ] ) ;
for ( V_53 = 0 ; V_13 [ V_53 ] != NULL ; V_53 ++ ) {
F_18 ( ( V_12 ) V_13 [ V_53 ] ) ;
}
F_18 ( V_13 ) ;
return - 1 ;
}
if ( ( * V_3 = F_45 () ) == 0 ) {
F_46 ( V_156 [ V_83 ] , 1 ) ;
F_47 ( V_156 [ V_82 ] ) ;
F_47 ( V_156 [ V_83 ] ) ;
F_46 ( V_81 [ V_83 ] , 2 ) ;
F_47 ( V_81 [ V_82 ] ) ;
F_47 ( V_81 [ V_83 ] ) ;
F_48 ( V_13 [ 0 ] , V_13 ) ;
F_12 ( V_80 , sizeof V_80 , L_62 ,
V_13 [ 0 ] , F_44 ( V_150 ) ) ;
F_49 ( 2 , V_80 , L_63 ) ;
F_50 ( 1 ) ;
}
if ( V_151 && * V_3 > 0 )
V_151 ( * V_3 ) ;
* V_154 = V_156 [ V_82 ] ;
* V_155 = V_81 [ V_82 ] ;
#endif
for ( V_53 = 0 ; V_13 [ V_53 ] != NULL ; V_53 ++ ) {
F_18 ( ( V_12 ) V_13 [ V_53 ] ) ;
}
F_18 ( ( V_12 ) V_13 ) ;
#ifdef F_2
F_40 ( V_156 [ V_83 ] ) ;
F_40 ( V_81 [ V_83 ] ) ;
#else
F_47 ( V_156 [ V_83 ] ) ;
F_47 ( V_81 [ V_83 ] ) ;
#endif
if ( * V_3 == - 1 ) {
* V_29 = F_17 ( L_64 , F_44 ( V_150 ) ) ;
F_47 ( * V_154 ) ;
F_47 ( * V_155 ) ;
return - 1 ;
}
if ( F_20 ) F_20 () ;
return 0 ;
}
static int
F_53 ( int * V_154 , int * V_155 ,
int * V_3 , T_2 * * V_157 )
{
F_47 ( * V_154 ) ;
if ( V_155 != NULL )
F_47 ( * V_155 ) ;
#ifdef F_2
F_54 ( * V_3 ) ;
#endif
return F_55 ( * V_3 , V_157 ) ;
}
static int
F_56 ( char * * V_13 , T_2 * * V_158 , T_2 * * V_159 ,
T_2 * * V_160 , void (* F_20)( void ) )
{
T_2 * V_29 ;
int V_161 , V_84 , V_3 , V_162 ;
char * V_163 ;
T_2 V_164 [ V_165 + 1 ] = { 0 } ;
T_16 V_166 ;
char V_167 ;
int V_168 ;
char * V_169 ;
int V_170 ;
char * V_171 ;
char * V_172 ;
T_9 * V_173 = NULL ;
T_16 V_174 ;
V_162 = F_52 ( V_13 , & V_161 , & V_84 ,
& V_3 , & V_29 , F_20 ) ;
if ( V_162 == - 1 ) {
* V_159 = V_29 ;
* V_160 = NULL ;
* V_158 = NULL ;
return - 1 ;
}
V_166 = F_57 ( V_84 , & V_167 , V_175 ,
V_164 , V_159 ) ;
if( V_166 <= 0 ) {
V_162 = F_55 ( V_3 , & V_163 ) ;
if( V_166 == 0 ) {
if ( V_162 == - 1 )
* V_159 = V_163 ;
else
* V_159 = F_7 ( L_67 ) ;
} else {
if ( V_162 == - 1 ) {
V_172 = F_17 ( L_68 , * V_159 , V_163 ) ;
F_18 ( * V_159 ) ;
F_18 ( V_163 ) ;
* V_159 = V_172 ;
}
}
* V_160 = NULL ;
return - 1 ;
}
switch( V_167 ) {
case V_176 :
F_58 ( ( V_177 * ) V_164 , 4 , & V_167 , & V_168 ) ;
V_169 = V_164 + 4 ;
F_58 ( ( V_177 * ) V_169 + V_168 , 4 , & V_167 ,
& V_170 ) ;
V_171 = V_169 + V_168 + 4 ;
V_162 = F_53 ( & V_161 , & V_84 ,
& V_3 , & V_29 ) ;
if ( V_162 == - 1 ) {
* V_159 = V_29 ;
* V_160 = NULL ;
} else {
* V_159 = F_7 ( V_169 ) ;
* V_160 = F_7 ( V_171 ) ;
V_162 = - 1 ;
}
* V_158 = NULL ;
break;
case V_178 :
V_173 = F_59 ( L_63 ) ;
while ( ( V_174 = F_60 ( V_161 , V_164 , V_165 ) ) > 0 ) {
V_164 [ V_174 ] = '\0' ;
F_38 ( V_173 , V_164 ) ;
}
V_162 = F_53 ( & V_161 , & V_84 ,
& V_3 , & V_29 ) ;
if ( V_162 == - 1 ) {
* V_159 = V_29 ;
* V_160 = NULL ;
F_41 ( V_173 , TRUE ) ;
* V_158 = NULL ;
} else {
* V_159 = NULL ;
* V_160 = NULL ;
* V_158 = V_173 -> V_146 ;
F_41 ( V_173 , FALSE ) ;
}
break;
default:
V_162 = F_53 ( & V_161 , & V_84 ,
& V_3 , & V_29 ) ;
if ( V_162 == - 1 ) {
* V_159 = V_29 ;
* V_160 = NULL ;
} else {
* V_159 = F_17 ( L_69 ,
V_167 ) ;
* V_160 = NULL ;
V_162 = - 1 ;
}
* V_158 = NULL ;
break;
}
return V_162 ;
}
static int
F_61 ( char * * V_13 , T_2 * * V_158 , T_2 * * V_159 ,
T_2 * * V_160 , void (* F_20)( void ) )
{
int V_162 , V_53 ;
T_17 V_179 ;
T_17 V_180 ;
float V_181 ;
int V_182 ;
V_182 = ( ( V_90 | V_183 ) & V_184 & V_185 . V_186 ) ;
if( V_182 ) {
F_62 ( & V_179 ) ;
F_25 ( V_89 , V_183 , L_70 ) ;
for( V_53 = 0 ; V_13 [ V_53 ] != 0 ; V_53 ++ ) {
F_25 ( V_89 , V_90 , L_71 , V_53 , V_13 [ V_53 ] ) ;
}
}
V_162 = F_56 ( V_13 , V_158 , V_159 , V_160 , F_20 ) ;
if( V_182 ) {
F_62 ( & V_180 ) ;
V_181 = ( float ) ( ( V_180 . V_187 - V_179 . V_187 ) +
( ( V_180 . V_188 - V_179 . V_188 ) / 1e6 ) ) ;
F_25 ( V_89 , V_183 , L_72 , V_181 , V_162 ) ;
}
return V_162 ;
}
int
F_63 ( const T_2 * V_189 , const char * V_190 , const T_2 * type ,
T_2 * * V_158 , T_2 * * V_159 ,
T_2 * * V_160 , void (* F_20)( void ) )
{
int V_10 , V_162 ;
char * * V_13 ;
T_2 * V_191 ;
V_13 = F_15 ( & V_10 ) ;
if ( ! V_13 ) {
* V_159 = F_7 ( L_28 ) ;
* V_160 = NULL ;
* V_158 = NULL ;
return - 1 ;
}
V_13 = F_5 ( V_13 , & V_10 , L_41 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_189 ) ;
if ( type )
V_191 = F_17 ( L_73 , V_190 , type ) ;
else
V_191 = F_17 ( L_25 , V_190 ) ;
if ( ! V_191 ) {
* V_159 = F_7 ( L_74 ) ;
* V_160 = NULL ;
* V_158 = NULL ;
return - 1 ;
}
V_13 = F_5 ( V_13 , & V_10 , L_75 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_191 ) ;
#ifndef F_30
V_13 = F_5 ( V_13 , & V_10 , L_57 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_125 ) ;
#endif
V_162 = F_61 ( V_13 , V_158 , V_159 , V_160 , F_20 ) ;
F_18 ( V_191 ) ;
return V_162 ;
}
int
F_64 ( T_2 * * V_158 , T_2 * * V_159 ,
T_2 * * V_160 , void (* F_20)( void ) )
{
int V_10 ;
char * * V_13 ;
F_25 ( V_89 , V_90 , L_76 ) ;
V_13 = F_15 ( & V_10 ) ;
if ( ! V_13 ) {
* V_159 = F_7 ( L_77 ) ;
* V_160 = NULL ;
* V_158 = NULL ;
return - 1 ;
}
V_13 = F_5 ( V_13 , & V_10 , L_78 ) ;
#ifndef F_30
V_13 = F_5 ( V_13 , & V_10 , L_57 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_125 ) ;
#endif
return F_61 ( V_13 , V_158 , V_159 , V_160 , F_20 ) ;
}
int
F_65 ( const T_2 * V_192 , T_4 V_113 ,
T_2 * * V_158 , T_2 * * V_159 ,
T_2 * * V_160 , void (* F_20)( void ) )
{
int V_10 ;
char * * V_13 ;
F_25 ( V_89 , V_90 , L_79 ) ;
V_13 = F_15 ( & V_10 ) ;
if ( ! V_13 ) {
* V_159 = F_7 ( L_28 ) ;
* V_160 = NULL ;
* V_158 = NULL ;
return - 1 ;
}
V_13 = F_5 ( V_13 , & V_10 , L_41 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_192 ) ;
V_13 = F_5 ( V_13 , & V_10 , L_80 ) ;
if ( V_113 )
V_13 = F_5 ( V_13 , & V_10 , L_47 ) ;
#ifndef F_30
V_13 = F_5 ( V_13 , & V_10 , L_57 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_125 ) ;
#endif
return F_61 ( V_13 , V_158 , V_159 , V_160 , F_20 ) ;
}
int
F_66 ( int * V_154 , int * V_3 , T_2 * * V_29 , void (* F_20)( void ) )
{
int V_10 ;
char * * V_13 ;
int V_155 , V_162 ;
char * V_163 ;
T_2 V_164 [ V_165 + 1 ] = { 0 } ;
T_16 V_166 ;
char V_167 ;
int V_168 ;
char * V_169 ;
int V_170 ;
char * V_172 ;
F_25 ( V_89 , V_90 , L_81 ) ;
V_13 = F_15 ( & V_10 ) ;
if ( ! V_13 ) {
* V_29 = F_7 ( L_28 ) ;
return - 1 ;
}
V_13 = F_5 ( V_13 , & V_10 , L_82 ) ;
#ifndef F_30
V_13 = F_5 ( V_13 , & V_10 , L_57 ) ;
#ifdef F_2
F_67 () ;
V_13 = F_5 ( V_13 , & V_10 , V_193 ) ;
#else
V_13 = F_5 ( V_13 , & V_10 , V_125 ) ;
#endif
#endif
V_162 = F_52 ( V_13 , V_154 , & V_155 ,
V_3 , V_29 , F_20 ) ;
if ( V_162 == - 1 )
return - 1 ;
V_166 = F_57 ( V_155 , & V_167 , V_175 ,
V_164 , V_29 ) ;
if( V_166 <= 0 ) {
V_162 = F_55 ( * V_3 , & V_163 ) ;
if( V_166 == 0 ) {
if ( V_162 == - 1 )
* V_29 = V_163 ;
else
* V_29 = F_7 ( L_67 ) ;
} else {
if ( V_162 == - 1 ) {
V_172 = F_17 ( L_68 , * V_29 , V_163 ) ;
F_18 ( * V_29 ) ;
F_18 ( V_163 ) ;
* V_29 = V_172 ;
}
}
return - 1 ;
}
switch( V_167 ) {
case V_176 :
F_58 ( ( V_177 * ) V_164 , 4 , & V_167 , & V_168 ) ;
V_169 = V_164 + 4 ;
F_58 ( ( V_177 * ) V_169 + V_168 , 4 , & V_167 ,
& V_170 ) ;
V_162 = F_53 ( V_154 , & V_155 ,
V_3 , V_29 ) ;
if ( V_162 == - 1 ) {
} else {
* V_29 = F_7 ( V_169 ) ;
V_162 = - 1 ;
}
break;
case V_178 :
F_47 ( V_155 ) ;
break;
default:
V_162 = F_53 ( V_154 , & V_155 ,
V_3 , V_29 ) ;
if ( V_162 == - 1 ) {
} else {
* V_29 = F_17 ( L_69 ,
V_167 ) ;
V_162 = - 1 ;
}
break;
}
return V_162 ;
}
int
F_68 ( int * V_194 , int * V_3 , T_2 * * V_29 )
{
#ifndef F_2
F_54 ( * V_3 ) ;
#endif
return F_53 ( V_194 , NULL , V_3 , V_29 ) ;
}
static T_16
F_69 ( int V_195 , char * V_196 , int V_197 , char * * V_29 )
{
T_16 V_198 ;
T_16 V_199 = 0 ;
int error ;
while( V_197 ) {
V_198 = F_70 ( V_195 , & V_196 [ V_199 ] , V_197 ) ;
if ( V_198 == 0 ) {
F_25 ( V_89 , V_90 ,
L_83 , V_195 ) ;
* V_29 = 0 ;
return V_199 ;
}
if ( V_198 < 0 ) {
error = V_150 ;
F_25 ( V_89 , V_90 ,
L_84 , V_195 , error ,
F_44 ( error ) ) ;
* V_29 = F_17 ( L_85 ,
F_44 ( error ) ) ;
return V_198 ;
}
V_197 -= ( int ) V_198 ;
V_199 += V_198 ;
}
* V_29 = NULL ;
return V_199 ;
}
static T_4 F_71 ( int V_195 ) {
#ifdef F_2
T_8 V_200 = ( T_8 ) F_72 ( V_195 ) ;
T_5 V_201 ;
if ( V_200 == V_133 )
return FALSE ;
if ( ! F_73 ( V_200 , NULL , 0 , NULL , & V_201 , NULL ) )
return FALSE ;
if ( V_201 > 0 )
return TRUE ;
return FALSE ;
#else
T_18 V_202 ;
struct V_203 V_204 ;
F_74 ( & V_202 ) ;
F_75 ( V_195 , & V_202 ) ;
V_204 . V_187 = 0 ;
V_204 . V_188 = 0 ;
if ( F_76 ( V_195 + 1 , & V_202 , NULL , NULL , & V_204 ) > 0 )
return TRUE ;
return FALSE ;
#endif
}
int
F_77 ( int V_195 , char * V_196 , int V_205 ) {
T_16 V_198 ;
int V_199 = - 1 ;
while( V_199 < V_205 - 1 ) {
V_199 ++ ;
if ( ! F_71 ( V_195 ) )
break;
V_198 = F_70 ( V_195 , & V_196 [ V_199 ] , 1 ) ;
if ( V_198 == 0 ) {
break;
} else if ( V_198 == - 1 ) {
F_25 ( V_89 , V_90 ,
L_84 , V_195 , V_150 , F_44 ( V_150 ) ) ;
return - 1 ;
} else if ( V_196 [ V_199 ] == '\n' ) {
break;
}
}
if ( V_199 >= 0 )
V_196 [ V_199 ] = '\0' ;
return V_199 ;
}
static void
F_58 ( const V_177 * V_206 , int V_207 , char * V_167 , int * V_208 ) {
F_78 ( V_207 == 4 ) ;
* V_167 = V_206 [ 0 ] ;
* V_208 = ( V_206 [ 1 ] & 0xFF ) << 16 | ( V_206 [ 2 ] & 0xFF ) << 8 | ( V_206 [ 3 ] & 0xFF ) ;
}
static T_16
F_57 ( int V_195 , char * V_167 , int V_17 , char * V_29 ,
char * * V_209 )
{
int V_197 ;
T_16 V_198 ;
T_2 V_206 [ 4 ] ;
V_198 = F_69 ( V_195 , V_206 , 4 , V_209 ) ;
if( V_198 != 4 ) {
if ( V_198 == 0 ) {
F_25 ( V_89 , V_90 ,
L_86 , V_195 ) ;
return 0 ;
}
F_25 ( V_89 , V_90 ,
L_87 , V_195 , ( long ) V_198 ) ;
if ( V_198 != - 1 ) {
* V_209 = F_17 ( L_88 ,
( long ) V_198 ) ;
}
return - 1 ;
}
F_58 ( ( V_177 * ) V_206 , 4 , V_167 , & V_197 ) ;
if( V_197 == 0 ) {
F_25 ( V_89 , V_90 ,
L_89 , V_195 , * V_167 ) ;
return 4 ;
}
if( V_197 > V_17 ) {
F_25 ( V_89 , V_90 ,
L_90 ,
V_195 , V_197 , V_17 ,
V_206 [ 0 ] , V_206 [ 1 ] , V_206 [ 2 ] , V_206 [ 3 ] ) ;
memcpy ( V_29 , V_206 , sizeof( V_206 ) ) ;
V_198 = F_70 ( V_195 , & V_29 [ sizeof( V_206 ) ] , V_17 - sizeof( V_206 ) ) ;
if ( V_198 < 0 ) {
F_25 ( V_89 , V_90 ,
L_84 , V_195 , V_150 , F_44 ( V_150 ) ) ;
}
* V_209 = F_17 ( L_91 ,
V_29 ) ;
return - 1 ;
}
V_17 = V_197 ;
V_198 = F_69 ( V_195 , V_29 , V_197 , V_209 ) ;
if( V_198 != V_197 ) {
if ( V_198 != - 1 ) {
* V_209 = F_17 ( L_91 ,
V_29 ) ;
}
return - 1 ;
}
F_25 ( V_89 , V_90 ,
L_92 , V_195 , * V_167 ,
V_17 , V_29 ) ;
* V_209 = NULL ;
return V_198 + 4 ;
}
static T_4
V_153 ( T_3 V_210 , V_12 V_211 )
{
T_1 * V_1 = ( T_1 * ) V_211 ;
int V_162 ;
char V_164 [ V_175 + 1 ] = { 0 } ;
T_16 V_166 ;
char V_167 ;
int V_212 ;
char * V_159 ;
int V_213 ;
char * V_160 ;
char * V_163 , * V_172 ;
int V_214 ;
V_166 = F_57 ( V_210 , & V_167 , V_175 , V_164 ,
& V_159 ) ;
if( V_166 <= 0 ) {
V_162 = F_55 ( V_1 -> V_3 , & V_163 ) ;
if( V_166 == 0 ) {
if ( V_162 == - 1 )
V_159 = V_163 ;
} else {
if ( V_162 == - 1 ) {
V_172 = F_17 ( L_68 , V_159 , V_163 ) ;
F_18 ( V_159 ) ;
F_18 ( V_163 ) ;
V_159 = V_172 ;
}
}
V_1 -> V_3 = - 1 ;
V_1 -> V_152 = V_162 ;
#ifdef F_2
F_47 ( V_1 -> V_4 ) ;
#endif
F_79 ( V_1 , V_159 ) ;
F_18 ( V_159 ) ;
return FALSE ;
}
switch( V_167 ) {
case V_215 :
if( ! F_80 ( V_1 , V_164 ) ) {
F_25 ( V_89 , V_90 , L_93 ) ;
F_47 ( V_210 ) ;
F_81 ( V_1 ) ;
F_79 ( V_1 , NULL ) ;
return FALSE ;
}
break;
case V_216 :
V_214 = atoi ( V_164 ) ;
F_25 ( V_89 , V_90 , L_94 , V_214 ) ;
F_82 ( V_1 , V_214 ) ;
break;
case V_176 :
F_58 ( ( V_177 * ) V_164 , 4 , & V_167 , & V_212 ) ;
V_159 = V_164 + 4 ;
F_58 ( ( V_177 * ) V_159 + V_212 , 4 , & V_167 , & V_213 ) ;
V_160 = V_159 + V_212 + 4 ;
F_83 ( V_1 , V_159 , V_160 ) ;
break;
case V_217 : {
char * V_218 = NULL ;
int V_219 = 0 ;
V_218 = strtok ( V_164 , L_95 ) ;
if ( V_218 ) {
V_219 = ( int ) strtol ( V_218 , NULL , 10 ) ;
V_218 = strtok ( NULL , L_95 ) ;
}
F_84 ( V_1 , V_219 , V_218 ) ;
break;
}
case V_220 :
F_85 ( V_1 , ( V_221 ) strtoul ( V_164 , NULL , 10 ) ) ;
break;
default:
F_86 () ;
}
return TRUE ;
}
static int
F_55 ( int V_3 , T_2 * * V_157 )
{
int V_152 ;
int V_162 ;
T_17 V_179 ;
T_17 V_180 ;
float V_181 ;
F_62 ( & V_179 ) ;
F_25 ( V_89 , V_90 , L_96 ) ;
F_78 ( V_3 != - 1 ) ;
* V_157 = NULL ;
#ifdef F_2
if ( F_87 ( & V_152 , V_3 , V_222 ) == - 1 ) {
* V_157 = F_17 ( L_97 , F_44 ( V_150 ) ) ;
V_162 = - 1 ;
} else {
V_162 = V_152 ;
if ( ( V_152 & 0xC0000000 ) == V_223 ) {
* V_157 = F_17 ( L_98 ,
F_13 ( V_152 ) ) ;
V_162 = - 1 ;
}
}
#else
if ( F_88 ( V_3 , & V_152 , 0 ) != - 1 ) {
if ( F_89 ( V_152 ) ) {
V_162 = F_90 ( V_152 ) ;
} else if ( F_91 ( V_152 ) ) {
* V_157 = F_17 ( L_99 ,
F_92 ( F_93 ( V_152 ) ) ) ;
V_162 = - 1 ;
} else if ( F_94 ( V_152 ) ) {
* V_157 = F_17 ( L_100 ,
F_92 ( F_95 ( V_152 ) ) ,
F_96 ( V_152 ) ? L_101 : L_63 ) ;
V_162 = - 1 ;
} else {
* V_157 = F_17 ( L_102 ,
V_152 ) ;
V_162 = - 1 ;
}
} else if ( V_150 != V_224 ) {
* V_157 = F_17 ( L_103 , F_44 ( V_150 ) ) ;
V_162 = - 1 ;
} else {
V_162 = V_151 ? 0 : - 1 ;
}
#endif
F_62 ( & V_180 ) ;
V_181 = ( float ) ( ( V_180 . V_187 - V_179 . V_187 ) +
( ( V_180 . V_188 - V_179 . V_188 ) / 1e6 ) ) ;
F_25 ( V_89 , V_90 , L_104 , V_181 ) ;
return V_162 ;
}
static const char *
F_92 ( int V_225 )
{
const char * V_226 ;
static char V_227 [ 6 + 1 + 3 + 1 ] ;
switch ( V_225 ) {
case V_228 :
V_226 = L_105 ;
break;
case V_229 :
V_226 = L_106 ;
break;
case V_230 :
V_226 = L_107 ;
break;
case V_231 :
V_226 = L_14 ;
break;
case V_232 :
V_226 = L_108 ;
break;
case V_233 :
V_226 = L_109 ;
break;
case V_234 :
V_226 = L_110 ;
break;
case V_235 :
V_226 = L_111 ;
break;
case V_236 :
V_226 = L_112 ;
break;
case V_237 :
V_226 = L_113 ;
break;
#ifdef F_97
case F_97 :
V_226 = L_114 ;
break;
#endif
case V_238 :
V_226 = L_115 ;
break;
case V_239 :
V_226 = L_116 ;
break;
case V_240 :
V_226 = L_117 ;
break;
default:
F_12 ( V_227 , sizeof V_227 , L_118 , V_225 ) ;
V_226 = V_227 ;
break;
}
return V_226 ;
}
static void F_67 () {
T_2 * V_241 ;
if ( V_242 != NULL ) return;
if ( ! V_193 ) {
V_193 = F_17 ( L_119 , F_31 () ) ;
}
V_241 = F_17 ( V_130 , V_193 ) ;
V_242 = F_34 ( F_35 ( V_241 ) ,
V_131 , V_132 , 1 , 65535 , 65535 , 0 , NULL ) ;
F_18 ( V_241 ) ;
}
static void
F_98 ( T_1 * V_1 )
{
const char V_243 [] = L_120 ;
int V_162 ;
F_25 ( V_89 , V_90 , L_121 ) ;
V_162 = F_99 ( V_1 -> V_4 , V_243 , sizeof V_243 ) ;
if( V_162 == - 1 ) {
F_25 ( V_244 , V_245 ,
L_122 , V_1 -> V_4 , F_44 ( V_150 ) ) ;
}
}
void
F_81 ( T_1 * V_1 )
{
#ifdef F_2
int V_174 ;
T_5 V_246 ;
T_4 V_247 = TRUE ;
#endif
if ( V_1 -> V_3 != - 1 ) {
#ifndef F_2
int V_248 = F_100 ( V_1 -> V_3 , V_229 ) ;
if ( V_248 != 0 ) {
F_25 ( V_244 , V_245 ,
L_123 , F_44 ( V_150 ) ) ;
}
#else
#define F_101 500
#define F_102 50
F_98 ( V_1 ) ;
for ( V_174 = 0 ; V_174 < F_101 / F_102 ; V_174 ++ ) {
if ( F_103 ( ( T_8 ) V_1 -> V_3 , & V_246 ) &&
V_246 != V_249 ) {
V_247 = FALSE ;
break;
}
F_104 ( F_102 ) ;
}
if ( V_247 ) {
F_25 ( V_244 , V_245 ,
L_124 ) ;
F_54 ( V_1 -> V_3 ) ;
}
#endif
}
}
void
F_54 ( int V_3 )
{
if ( V_3 != - 1 ) {
#ifndef F_2
int V_248 = F_100 ( V_3 , V_240 ) ;
if ( V_248 != 0 ) {
F_25 ( V_244 , V_245 ,
L_125 , F_44 ( V_150 ) ) ;
}
#else
F_105 ( ( T_8 ) ( V_3 ) , 0 ) ;
#endif
}
}
void F_106 ( void (* V_134)( int V_250 ) ) {
V_151 = V_134 ;
}
