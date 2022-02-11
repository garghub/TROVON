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
F_19 ( T_7 * V_57 , T_1 * V_1 )
{
char V_58 [ V_59 ] ;
char V_60 [ V_59 ] ;
char V_61 [ V_59 ] ;
char V_62 [ V_59 ] ;
char V_63 [ V_59 ] ;
char V_64 [ V_59 ] ;
char V_65 [ V_59 ] ;
char V_66 [ V_59 ] ;
#ifdef F_20
char V_67 [ 256 ] ;
#endif
#ifdef F_21
char V_68 [ V_59 ] ;
#endif
#if F_22 ( F_2 ) || F_22 ( V_69 )
char V_70 [ V_59 ] ;
#endif
#ifdef F_2
T_8 V_71 ;
T_8 V_72 ;
T_8 V_73 ;
T_9 * args = F_23 ( 200 ) ;
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
F_24 ( V_89 , V_90 , L_27 ) ;
F_25 ( V_89 , V_90 , V_57 ) ;
V_1 -> V_3 = - 1 ;
V_13 = F_15 ( & V_10 ) ;
if ( ! V_13 ) {
F_26 ( L_28 ) ;
return FALSE ;
}
if ( V_57 -> V_87 -> V_17 > 1 )
V_13 = F_5 ( V_13 , & V_10 , L_29 ) ;
if ( V_57 -> V_88 )
V_13 = F_5 ( V_13 , & V_10 , L_30 ) ;
else
V_13 = F_5 ( V_13 , & V_10 , L_31 ) ;
if ( V_57 -> V_91 ) {
if ( V_57 -> V_92 ) {
V_13 = F_5 ( V_13 , & V_10 , L_32 ) ;
F_12 ( V_61 , V_59 , L_33 , V_57 -> V_93 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_61 ) ;
}
if ( V_57 -> V_94 ) {
V_13 = F_5 ( V_13 , & V_10 , L_32 ) ;
F_12 ( V_62 , V_59 , L_34 , V_57 -> V_95 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_62 ) ;
}
if ( V_57 -> V_96 ) {
V_13 = F_5 ( V_13 , & V_10 , L_32 ) ;
F_12 ( V_63 , V_59 , L_35 , V_57 -> V_97 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_63 ) ;
}
if ( V_57 -> V_98 ) {
V_13 = F_5 ( V_13 , & V_10 , L_36 ) ;
F_12 ( V_64 , V_59 , L_35 , V_57 -> V_99 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_64 ) ;
}
} else {
if ( V_57 -> V_92 ) {
V_13 = F_5 ( V_13 , & V_10 , L_36 ) ;
F_12 ( V_65 , V_59 , L_33 , V_57 -> V_93 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_65 ) ;
}
}
if ( V_57 -> V_100 ) {
V_13 = F_5 ( V_13 , & V_10 , L_37 ) ;
F_12 ( V_60 , V_59 , L_38 , V_57 -> V_101 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_60 ) ;
}
if ( V_57 -> V_102 ) {
V_13 = F_5 ( V_13 , & V_10 , L_36 ) ;
F_12 ( V_66 , V_59 , L_34 , V_57 -> V_103 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_66 ) ;
}
if ( V_57 -> V_104 ) {
V_13 = F_5 ( V_13 , & V_10 , L_39 ) ;
}
for ( V_85 = 0 ; V_85 < V_57 -> V_87 -> V_17 ; V_85 ++ ) {
V_86 = F_27 ( V_57 -> V_87 , T_15 , V_85 ) ;
V_13 = F_5 ( V_13 , & V_10 , L_40 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_86 . V_105 ) ;
if ( V_86 . V_106 != NULL && strlen ( V_86 . V_106 ) != 0 ) {
V_13 = F_5 ( V_13 , & V_10 , L_41 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_86 . V_106 ) ;
}
if ( V_86 . V_107 != V_108 ) {
V_13 = F_5 ( V_13 , & V_10 , L_42 ) ;
F_12 ( V_58 , V_59 , L_38 , V_86 . V_107 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_58 ) ;
}
if ( V_86 . V_109 != - 1 ) {
V_13 = F_5 ( V_13 , & V_10 , L_43 ) ;
V_13 = F_5 ( V_13 , & V_10 , F_28 ( V_86 . V_109 ) ) ;
}
if ( ! V_86 . V_110 ) {
V_13 = F_5 ( V_13 , & V_10 , L_44 ) ;
}
#if F_22 ( F_2 ) || F_22 ( V_69 )
if ( V_86 . V_70 != V_111 ) {
V_13 = F_5 ( V_13 , & V_10 , L_45 ) ;
F_12 ( V_70 , V_59 , L_38 , V_86 . V_70 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_70 ) ;
}
#endif
#ifdef V_69
if ( V_86 . V_112 ) {
V_13 = F_5 ( V_13 , & V_10 , L_46 ) ;
}
#endif
#ifdef F_20
if ( V_86 . V_113 )
V_13 = F_5 ( V_13 , & V_10 , L_47 ) ;
if ( ! V_86 . V_114 )
V_13 = F_5 ( V_13 , & V_10 , L_48 ) ;
if ( V_86 . V_115 == V_116 ) {
V_13 = F_5 ( V_13 , & V_10 , L_49 ) ;
F_12 ( V_67 , sizeof( V_67 ) , L_50 ,
V_86 . V_117 ,
V_86 . V_118 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_67 ) ;
}
#endif
#ifdef F_21
if ( V_86 . V_119 != V_120 ) {
V_13 = F_5 ( V_13 , & V_10 , L_51 ) ;
F_12 ( V_68 , V_59 , L_52 ,
V_86 . V_119 == V_121 ? L_53 :
V_86 . V_119 == V_122 ? L_54 :
L_55 ,
V_86 . V_123 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_68 ) ;
}
#endif
}
#ifndef F_29
V_13 = F_5 ( V_13 , & V_10 , L_56 ) ;
#ifdef F_2
F_12 ( V_78 , V_59 , L_38 , F_30 () ) ;
V_13 = F_5 ( V_13 , & V_10 , V_78 ) ;
#else
V_13 = F_5 ( V_13 , & V_10 , V_124 ) ;
#endif
#endif
if ( V_57 -> V_125 ) {
V_13 = F_5 ( V_13 , & V_10 , L_57 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_57 -> V_125 ) ;
}
for ( V_53 = 0 ; V_53 < V_10 ; V_53 ++ ) {
F_24 ( V_89 , V_90 , L_58 , V_53 , V_13 [ V_53 ] ) ;
}
#ifdef F_2
V_75 . V_126 = sizeof( T_10 ) ;
V_75 . V_127 = TRUE ;
V_75 . V_128 = NULL ;
if ( ! F_31 ( & V_71 , & V_72 , & V_75 , 5120 ) ) {
F_26 ( L_59 ,
F_10 ( F_32 () ) ) ;
for ( V_53 = 0 ; V_53 < V_10 ; V_53 ++ ) {
F_18 ( ( V_12 ) V_13 [ V_53 ] ) ;
}
F_18 ( ( V_12 ) V_13 ) ;
return FALSE ;
}
V_79 = F_17 ( V_129 , V_78 ) ;
V_73 = F_33 ( F_34 ( V_79 ) ,
V_130 , V_131 , 1 , 65535 , 65535 , 0 , NULL ) ;
F_18 ( V_79 ) ;
if ( V_73 == V_132 ) {
F_26 ( L_60 ,
F_10 ( F_32 () ) ) ;
for ( V_53 = 0 ; V_53 < V_10 ; V_53 ++ ) {
F_18 ( ( V_12 ) V_13 [ V_53 ] ) ;
}
F_18 ( ( V_12 ) V_13 ) ;
return FALSE ;
}
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
V_76 . V_133 = sizeof( V_76 ) ;
#ifdef F_29
V_76 . V_134 = V_135 ;
V_76 . V_136 = V_137 ;
#else
V_76 . V_134 = V_138 | V_135 ;
V_76 . V_136 = V_139 ;
V_76 . V_140 = F_35 ( V_141 ) ;
V_76 . V_142 = F_35 ( V_143 ) ;
V_76 . V_144 = V_72 ;
#endif
for( V_53 = 0 ; V_13 [ V_53 ] != 0 ; V_53 ++ ) {
if( V_53 != 0 ) F_36 ( args , ' ' ) ;
V_74 = F_8 ( V_13 [ V_53 ] ) ;
F_37 ( args , V_74 ) ;
F_18 ( V_74 ) ;
}
if( ! F_38 ( NULL , F_34 ( args -> V_145 ) , NULL , NULL , TRUE ,
V_146 , NULL , NULL , & V_76 , & V_77 ) ) {
F_26 ( L_61 ,
args -> V_145 , F_10 ( F_32 () ) ) ;
F_39 ( V_71 ) ;
F_39 ( V_72 ) ;
for ( V_53 = 0 ; V_53 < V_10 ; V_53 ++ ) {
F_18 ( ( V_12 ) V_13 [ V_53 ] ) ;
}
F_18 ( ( V_12 ) V_13 ) ;
return FALSE ;
}
V_1 -> V_3 = ( int ) V_77 . V_147 ;
F_40 ( args , TRUE ) ;
V_84 = F_41 ( ( long ) V_71 , V_148 ) ;
V_1 -> V_4 = F_41 ( ( long ) V_73 , V_148 ) ;
#else
if ( F_42 ( V_81 ) < 0 ) {
F_26 ( L_59 , F_43 ( V_149 ) ) ;
for ( V_53 = 0 ; V_53 < V_10 ; V_53 ++ ) {
F_18 ( ( V_12 ) V_13 [ V_53 ] ) ;
}
F_18 ( V_13 ) ;
return FALSE ;
}
if ( ( V_1 -> V_3 = F_44 () ) == 0 ) {
F_45 ( V_81 [ V_83 ] , 2 ) ;
F_46 ( V_81 [ V_82 ] ) ;
F_47 ( V_13 [ 0 ] , V_13 ) ;
F_12 ( V_80 , sizeof V_80 , L_61 ,
V_13 [ 0 ] , F_43 ( V_149 ) ) ;
F_48 ( 2 , V_80 , L_62 ) ;
F_49 ( 1 ) ;
}
V_84 = V_81 [ V_82 ] ;
#endif
for ( V_53 = 0 ; V_53 < V_10 ; V_53 ++ ) {
F_18 ( ( V_12 ) V_13 [ V_53 ] ) ;
}
F_18 ( ( V_12 ) V_13 ) ;
#ifdef F_2
F_39 ( V_72 ) ;
#else
F_46 ( V_81 [ V_83 ] ) ;
#endif
if ( V_1 -> V_3 == - 1 ) {
F_26 ( L_63 , F_43 ( V_149 ) ) ;
F_46 ( V_84 ) ;
#ifdef F_2
F_46 ( V_1 -> V_4 ) ;
#endif
return FALSE ;
}
V_1 -> V_150 = 0 ;
V_1 -> V_57 = V_57 ;
F_50 () ;
F_51 ( V_84 , ( V_12 ) V_1 ,
& V_1 -> V_3 , V_151 ) ;
return TRUE ;
}
static int
F_52 ( char * * V_13 , int * V_152 ,
int * V_153 , int * V_3 , T_2 * * V_29 )
{
enum T_13 { V_82 , V_83 };
#ifdef F_2
T_8 V_81 [ 2 ] ;
T_8 V_154 [ 2 ] ;
T_9 * args = F_23 ( 200 ) ;
T_2 * V_74 ;
T_10 V_75 ;
T_11 V_76 ;
T_12 V_77 ;
#else
char V_80 [ 1024 + 1 ] ;
int V_81 [ 2 ] ;
int V_154 [ 2 ] ;
#endif
int V_53 ;
* V_3 = - 1 ;
* V_152 = - 1 ;
* V_153 = - 1 ;
F_24 ( V_89 , V_90 , L_64 ) ;
if ( ! V_29 ) {
#ifdef F_2
F_40 ( args , TRUE ) ;
#endif
return - 1 ;
}
#ifdef F_2
V_75 . V_126 = sizeof( T_10 ) ;
V_75 . V_127 = TRUE ;
V_75 . V_128 = NULL ;
if ( ! F_31 ( & V_81 [ V_82 ] , & V_81 [ V_83 ] , & V_75 , 5120 ) ) {
* V_29 = F_17 ( L_59 ,
F_10 ( F_32 () ) ) ;
for ( V_53 = 0 ; V_13 [ V_53 ] != NULL ; V_53 ++ ) {
F_18 ( ( V_12 ) V_13 [ V_53 ] ) ;
}
F_18 ( ( V_12 ) V_13 ) ;
return - 1 ;
}
if ( ! F_31 ( & V_154 [ V_82 ] , & V_154 [ V_83 ] , & V_75 , 5120 ) ) {
* V_29 = F_17 ( L_65 ,
F_10 ( F_32 () ) ) ;
F_39 ( V_81 [ V_82 ] ) ;
F_39 ( V_81 [ V_83 ] ) ;
for ( V_53 = 0 ; V_13 [ V_53 ] != NULL ; V_53 ++ ) {
F_18 ( ( V_12 ) V_13 [ V_53 ] ) ;
}
F_18 ( ( V_12 ) V_13 ) ;
return - 1 ;
}
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
V_76 . V_133 = sizeof( V_76 ) ;
#ifdef F_29
V_76 . V_134 = V_135 ;
V_76 . V_136 = V_137 ;
#else
V_76 . V_134 = V_138 | V_135 ;
V_76 . V_136 = V_139 ;
V_76 . V_140 = NULL ;
V_76 . V_142 = V_154 [ V_83 ] ;
V_76 . V_144 = V_81 [ V_83 ] ;
#endif
for( V_53 = 0 ; V_13 [ V_53 ] != 0 ; V_53 ++ ) {
if( V_53 != 0 ) F_36 ( args , ' ' ) ;
V_74 = F_8 ( V_13 [ V_53 ] ) ;
F_37 ( args , V_74 ) ;
F_18 ( V_74 ) ;
}
if( ! F_38 ( NULL , F_34 ( args -> V_145 ) , NULL , NULL , TRUE ,
V_146 , NULL , NULL , & V_76 , & V_77 ) ) {
* V_29 = F_17 ( L_61 ,
args -> V_145 , F_10 ( F_32 () ) ) ;
F_39 ( V_154 [ V_82 ] ) ;
F_39 ( V_154 [ V_83 ] ) ;
F_39 ( V_81 [ V_82 ] ) ;
F_39 ( V_81 [ V_83 ] ) ;
for ( V_53 = 0 ; V_13 [ V_53 ] != NULL ; V_53 ++ ) {
F_18 ( ( V_12 ) V_13 [ V_53 ] ) ;
}
F_18 ( ( V_12 ) V_13 ) ;
return - 1 ;
}
* V_3 = ( int ) V_77 . V_147 ;
F_40 ( args , TRUE ) ;
* V_152 = F_41 ( ( long ) V_154 [ V_82 ] , V_148 ) ;
* V_153 = F_41 ( ( long ) V_81 [ V_82 ] , V_148 ) ;
#else
if ( F_42 ( V_81 ) < 0 ) {
* V_29 = F_17 ( L_59 , F_43 ( V_149 ) ) ;
for ( V_53 = 0 ; V_13 [ V_53 ] != NULL ; V_53 ++ ) {
F_18 ( ( V_12 ) V_13 [ V_53 ] ) ;
}
F_18 ( V_13 ) ;
return - 1 ;
}
if ( F_42 ( V_154 ) < 0 ) {
* V_29 = F_17 ( L_65 , F_43 ( V_149 ) ) ;
F_46 ( V_81 [ V_82 ] ) ;
F_46 ( V_81 [ V_83 ] ) ;
for ( V_53 = 0 ; V_13 [ V_53 ] != NULL ; V_53 ++ ) {
F_18 ( ( V_12 ) V_13 [ V_53 ] ) ;
}
F_18 ( V_13 ) ;
return - 1 ;
}
if ( ( * V_3 = F_44 () ) == 0 ) {
F_45 ( V_154 [ V_83 ] , 1 ) ;
F_46 ( V_154 [ V_82 ] ) ;
F_46 ( V_154 [ V_83 ] ) ;
F_45 ( V_81 [ V_83 ] , 2 ) ;
F_46 ( V_81 [ V_82 ] ) ;
F_46 ( V_81 [ V_83 ] ) ;
F_47 ( V_13 [ 0 ] , V_13 ) ;
F_12 ( V_80 , sizeof V_80 , L_61 ,
V_13 [ 0 ] , F_43 ( V_149 ) ) ;
F_48 ( 2 , V_80 , L_62 ) ;
F_49 ( 1 ) ;
}
* V_152 = V_154 [ V_82 ] ;
* V_153 = V_81 [ V_82 ] ;
#endif
for ( V_53 = 0 ; V_13 [ V_53 ] != NULL ; V_53 ++ ) {
F_18 ( ( V_12 ) V_13 [ V_53 ] ) ;
}
F_18 ( ( V_12 ) V_13 ) ;
#ifdef F_2
F_39 ( V_154 [ V_83 ] ) ;
F_39 ( V_81 [ V_83 ] ) ;
#else
F_46 ( V_154 [ V_83 ] ) ;
F_46 ( V_81 [ V_83 ] ) ;
#endif
if ( * V_3 == - 1 ) {
* V_29 = F_17 ( L_63 , F_43 ( V_149 ) ) ;
F_46 ( * V_152 ) ;
F_46 ( * V_153 ) ;
return - 1 ;
}
F_50 () ;
return 0 ;
}
static int
F_53 ( int * V_152 , int * V_153 ,
int * V_3 , T_2 * * V_155 )
{
F_46 ( * V_152 ) ;
if ( V_153 != NULL )
F_46 ( * V_153 ) ;
#ifdef F_2
F_54 ( * V_3 ) ;
#endif
return F_55 ( * V_3 , V_155 ) ;
}
static int
F_56 ( char * * V_13 , T_2 * * V_156 , T_2 * * V_157 ,
T_2 * * V_158 )
{
T_2 * V_29 ;
int V_159 , V_84 , V_3 , V_160 ;
char * V_161 ;
T_2 V_162 [ V_163 + 1 ] ;
T_16 V_164 ;
char V_165 ;
int V_166 ;
char * V_167 ;
int V_168 ;
char * V_169 ;
char * V_170 ;
T_9 * V_171 = NULL ;
T_16 V_172 ;
V_160 = F_52 ( V_13 , & V_159 , & V_84 ,
& V_3 , & V_29 ) ;
if ( V_160 == - 1 ) {
* V_157 = V_29 ;
* V_158 = NULL ;
* V_156 = NULL ;
return - 1 ;
}
V_164 = F_57 ( V_84 , & V_165 , V_173 ,
V_162 , V_157 ) ;
if( V_164 <= 0 ) {
V_160 = F_55 ( V_3 , & V_161 ) ;
if( V_164 == 0 ) {
if ( V_160 == - 1 )
* V_157 = V_161 ;
else
* V_157 = F_7 ( L_66 ) ;
} else {
if ( V_160 == - 1 ) {
V_170 = F_17 ( L_67 , * V_157 , V_161 ) ;
F_18 ( * V_157 ) ;
F_18 ( V_161 ) ;
* V_157 = V_170 ;
}
}
* V_158 = NULL ;
return - 1 ;
}
switch( V_165 ) {
case V_174 :
F_58 ( ( V_175 * ) V_162 , 4 , & V_165 , & V_166 ) ;
V_167 = V_162 + 4 ;
F_58 ( ( V_175 * ) V_167 + V_166 , 4 , & V_165 ,
& V_168 ) ;
V_169 = V_167 + V_166 + 4 ;
V_160 = F_53 ( & V_159 , & V_84 ,
& V_3 , & V_29 ) ;
if ( V_160 == - 1 ) {
* V_157 = V_29 ;
* V_158 = NULL ;
} else {
* V_157 = F_7 ( V_167 ) ;
* V_158 = F_7 ( V_169 ) ;
V_160 = - 1 ;
}
* V_156 = NULL ;
break;
case V_176 :
V_171 = F_59 ( L_62 ) ;
while ( ( V_172 = F_60 ( V_159 , V_162 , V_163 ) ) > 0 ) {
V_162 [ V_172 ] = '\0' ;
F_37 ( V_171 , V_162 ) ;
}
V_160 = F_53 ( & V_159 , & V_84 ,
& V_3 , & V_29 ) ;
if ( V_160 == - 1 ) {
* V_157 = V_29 ;
* V_158 = NULL ;
F_40 ( V_171 , TRUE ) ;
* V_156 = NULL ;
} else {
* V_157 = NULL ;
* V_158 = NULL ;
* V_156 = V_171 -> V_145 ;
F_40 ( V_171 , FALSE ) ;
}
break;
default:
V_160 = F_53 ( & V_159 , & V_84 ,
& V_3 , & V_29 ) ;
if ( V_160 == - 1 ) {
* V_157 = V_29 ;
* V_158 = NULL ;
} else {
* V_157 = F_17 ( L_68 ,
V_165 ) ;
* V_158 = NULL ;
V_160 = - 1 ;
}
* V_156 = NULL ;
break;
}
return V_160 ;
}
static int
F_61 ( char * * V_13 , T_2 * * V_156 , T_2 * * V_157 ,
T_2 * * V_158 )
{
int V_160 , V_53 ;
T_17 V_177 ;
T_17 V_178 ;
float V_179 ;
int V_180 ;
V_180 = ( ( V_90 | V_181 ) & V_182 & V_183 . V_184 ) ;
if( V_180 ) {
F_62 ( & V_177 ) ;
F_24 ( V_89 , V_181 , L_69 ) ;
for( V_53 = 0 ; V_13 [ V_53 ] != 0 ; V_53 ++ ) {
F_24 ( V_89 , V_90 , L_70 , V_53 , V_13 [ V_53 ] ) ;
}
}
V_160 = F_56 ( V_13 , V_156 , V_157 , V_158 ) ;
if( V_180 ) {
F_62 ( & V_178 ) ;
V_179 = ( float ) ( ( V_178 . V_185 - V_177 . V_185 ) +
( ( V_178 . V_186 - V_177 . V_186 ) / 1e6 ) ) ;
F_24 ( V_89 , V_181 , L_71 , V_179 , V_160 ) ;
}
return V_160 ;
}
int
F_63 ( const T_2 * V_187 , const char * V_188 , const T_2 * type ,
T_2 * * V_156 , T_2 * * V_157 ,
T_2 * * V_158 )
{
int V_10 , V_160 ;
char * * V_13 ;
T_2 * V_189 ;
V_13 = F_15 ( & V_10 ) ;
if ( ! V_13 ) {
* V_157 = F_7 ( L_28 ) ;
* V_158 = NULL ;
* V_156 = NULL ;
return - 1 ;
}
V_13 = F_5 ( V_13 , & V_10 , L_40 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_187 ) ;
if ( type )
V_189 = F_17 ( L_72 , V_188 , type ) ;
else
V_189 = F_17 ( L_25 , V_188 ) ;
if ( ! V_189 ) {
* V_157 = F_7 ( L_73 ) ;
* V_158 = NULL ;
* V_156 = NULL ;
return - 1 ;
}
V_13 = F_5 ( V_13 , & V_10 , L_74 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_189 ) ;
#ifndef F_29
V_13 = F_5 ( V_13 , & V_10 , L_56 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_124 ) ;
#endif
V_160 = F_61 ( V_13 , V_156 , V_157 , V_158 ) ;
F_18 ( V_189 ) ;
return V_160 ;
}
int
F_64 ( T_2 * * V_156 , T_2 * * V_157 ,
T_2 * * V_158 )
{
int V_10 ;
char * * V_13 ;
F_24 ( V_89 , V_90 , L_75 ) ;
V_13 = F_15 ( & V_10 ) ;
if ( ! V_13 ) {
* V_157 = F_7 ( L_28 ) ;
* V_158 = NULL ;
* V_156 = NULL ;
return - 1 ;
}
V_13 = F_5 ( V_13 , & V_10 , L_76 ) ;
#ifndef F_29
V_13 = F_5 ( V_13 , & V_10 , L_56 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_124 ) ;
#endif
return F_61 ( V_13 , V_156 , V_157 , V_158 ) ;
}
int
F_65 ( const T_2 * V_190 , T_4 V_112 ,
T_2 * * V_156 , T_2 * * V_157 ,
T_2 * * V_158 )
{
int V_10 ;
char * * V_13 ;
F_24 ( V_89 , V_90 , L_77 ) ;
V_13 = F_15 ( & V_10 ) ;
if ( ! V_13 ) {
* V_157 = F_7 ( L_28 ) ;
* V_158 = NULL ;
* V_156 = NULL ;
return - 1 ;
}
V_13 = F_5 ( V_13 , & V_10 , L_40 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_190 ) ;
V_13 = F_5 ( V_13 , & V_10 , L_78 ) ;
if ( V_112 )
V_13 = F_5 ( V_13 , & V_10 , L_46 ) ;
#ifndef F_29
V_13 = F_5 ( V_13 , & V_10 , L_56 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_124 ) ;
#endif
return F_61 ( V_13 , V_156 , V_157 , V_158 ) ;
}
int
F_66 ( int * V_152 , int * V_3 , T_2 * * V_29 )
{
int V_10 ;
char * * V_13 ;
int V_153 , V_160 ;
char * V_161 ;
T_2 V_162 [ V_163 + 1 ] ;
T_16 V_164 ;
char V_165 ;
int V_166 ;
char * V_167 ;
int V_168 ;
char * V_170 ;
F_24 ( V_89 , V_90 , L_79 ) ;
V_13 = F_15 ( & V_10 ) ;
if ( ! V_13 ) {
* V_29 = F_7 ( L_28 ) ;
return - 1 ;
}
V_13 = F_5 ( V_13 , & V_10 , L_80 ) ;
#ifndef F_29
V_13 = F_5 ( V_13 , & V_10 , L_56 ) ;
V_13 = F_5 ( V_13 , & V_10 , V_124 ) ;
#endif
V_160 = F_52 ( V_13 , V_152 , & V_153 ,
V_3 , V_29 ) ;
if ( V_160 == - 1 )
return - 1 ;
V_164 = F_57 ( V_153 , & V_165 , V_173 ,
V_162 , V_29 ) ;
if( V_164 <= 0 ) {
V_160 = F_55 ( * V_3 , & V_161 ) ;
if( V_164 == 0 ) {
if ( V_160 == - 1 )
* V_29 = V_161 ;
else
* V_29 = F_7 ( L_66 ) ;
} else {
if ( V_160 == - 1 ) {
V_170 = F_17 ( L_67 , * V_29 , V_161 ) ;
F_18 ( * V_29 ) ;
F_18 ( V_161 ) ;
* V_29 = V_170 ;
}
}
return - 1 ;
}
switch( V_165 ) {
case V_174 :
F_58 ( ( V_175 * ) V_162 , 4 , & V_165 , & V_166 ) ;
V_167 = V_162 + 4 ;
F_58 ( ( V_175 * ) V_167 + V_166 , 4 , & V_165 ,
& V_168 ) ;
V_160 = F_53 ( V_152 , & V_153 ,
V_3 , V_29 ) ;
if ( V_160 == - 1 ) {
} else {
* V_29 = F_7 ( V_167 ) ;
V_160 = - 1 ;
}
break;
case V_176 :
F_46 ( V_153 ) ;
break;
default:
V_160 = F_53 ( V_152 , & V_153 ,
V_3 , V_29 ) ;
if ( V_160 == - 1 ) {
} else {
* V_29 = F_17 ( L_68 ,
V_165 ) ;
V_160 = - 1 ;
}
break;
}
return V_160 ;
}
int
F_67 ( int * V_191 , int * V_3 , T_2 * * V_29 )
{
#ifndef F_2
F_54 ( * V_3 ) ;
#endif
return F_53 ( V_191 , NULL , V_3 , V_29 ) ;
}
static T_16
F_68 ( int V_192 , char * V_193 , int V_194 , char * * V_29 )
{
T_16 V_195 ;
T_16 V_196 = 0 ;
int error ;
while( V_194 ) {
V_195 = F_69 ( V_192 , & V_193 [ V_196 ] , V_194 ) ;
if ( V_195 == 0 ) {
F_24 ( V_89 , V_90 ,
L_81 , V_192 ) ;
* V_29 = 0 ;
return V_196 ;
}
if ( V_195 < 0 ) {
error = V_149 ;
F_24 ( V_89 , V_90 ,
L_82 , V_192 , error ,
F_43 ( error ) ) ;
* V_29 = F_17 ( L_83 ,
F_43 ( error ) ) ;
return V_195 ;
}
V_194 -= ( int ) V_195 ;
V_196 += V_195 ;
}
* V_29 = NULL ;
return V_196 ;
}
static T_4 F_70 ( int V_192 ) {
#ifdef F_2
T_8 V_197 = ( T_8 ) F_71 ( V_192 ) ;
T_5 V_198 ;
if ( V_197 == V_132 )
return FALSE ;
if ( ! F_72 ( V_197 , NULL , 0 , NULL , & V_198 , NULL ) )
return FALSE ;
if ( V_198 > 0 )
return TRUE ;
return FALSE ;
#else
T_18 V_199 ;
struct V_200 V_201 ;
F_73 ( & V_199 ) ;
F_74 ( V_192 , & V_199 ) ;
V_201 . V_185 = 0 ;
V_201 . V_186 = 0 ;
if ( F_75 ( V_192 + 1 , & V_199 , NULL , NULL , & V_201 ) > 0 )
return TRUE ;
return FALSE ;
#endif
}
int
F_76 ( int V_192 , char * V_193 , int V_202 ) {
T_16 V_195 ;
int V_196 = - 1 ;
while( V_196 < V_202 - 1 ) {
V_196 ++ ;
if ( ! F_70 ( V_192 ) )
break;
V_195 = F_69 ( V_192 , & V_193 [ V_196 ] , 1 ) ;
if ( V_195 == 0 ) {
break;
} else if ( V_195 == - 1 ) {
F_24 ( V_89 , V_90 ,
L_82 , V_192 , V_149 , F_43 ( V_149 ) ) ;
return - 1 ;
} else if ( V_193 [ V_196 ] == '\n' ) {
break;
}
}
if ( V_196 >= 0 )
V_193 [ V_196 ] = '\0' ;
return V_196 ;
}
static void
F_58 ( const V_175 * V_203 , int V_204 , char * V_165 , int * V_205 ) {
F_77 ( V_204 == 4 ) ;
* V_165 = V_203 [ 0 ] ;
* V_205 = ( V_203 [ 1 ] & 0xFF ) << 16 | ( V_203 [ 2 ] & 0xFF ) << 8 | ( V_203 [ 3 ] & 0xFF ) ;
}
static T_16
F_57 ( int V_192 , char * V_165 , int V_17 , char * V_29 ,
char * * V_206 )
{
int V_194 ;
T_16 V_195 ;
T_2 V_203 [ 4 ] ;
V_195 = F_68 ( V_192 , V_203 , 4 , V_206 ) ;
if( V_195 != 4 ) {
if ( V_195 == 0 ) {
F_24 ( V_89 , V_90 ,
L_84 , V_192 ) ;
return 0 ;
}
F_24 ( V_89 , V_90 ,
L_85 , V_192 , ( long ) V_195 ) ;
if ( V_195 != - 1 ) {
* V_206 = F_17 ( L_86 ,
( long ) V_195 ) ;
}
return - 1 ;
}
F_58 ( ( V_175 * ) V_203 , 4 , V_165 , & V_194 ) ;
if( V_194 == 0 ) {
F_24 ( V_89 , V_90 ,
L_87 , V_192 , * V_165 ) ;
return 4 ;
}
if( V_194 > V_17 ) {
F_24 ( V_89 , V_90 ,
L_88 ,
V_192 , V_194 , V_17 ,
V_203 [ 0 ] , V_203 [ 1 ] , V_203 [ 2 ] , V_203 [ 3 ] ) ;
memcpy ( V_29 , V_203 , sizeof( V_203 ) ) ;
V_195 = F_69 ( V_192 , & V_29 [ sizeof( V_203 ) ] , V_17 - sizeof( V_203 ) ) ;
if ( V_195 < 0 ) {
F_24 ( V_89 , V_90 ,
L_82 , V_192 , V_149 , F_43 ( V_149 ) ) ;
}
* V_206 = F_17 ( L_89 ,
V_29 ) ;
return - 1 ;
}
V_17 = V_194 ;
V_195 = F_68 ( V_192 , V_29 , V_194 , V_206 ) ;
if( V_195 != V_194 ) {
if ( V_195 != - 1 ) {
* V_206 = F_17 ( L_89 ,
V_29 ) ;
}
return - 1 ;
}
F_24 ( V_89 , V_90 ,
L_90 , V_192 , * V_165 ,
V_17 , V_29 ) ;
* V_206 = NULL ;
return V_195 + 4 ;
}
static T_4
V_151 ( T_3 V_207 , V_12 V_208 )
{
T_1 * V_1 = ( T_1 * ) V_208 ;
int V_160 ;
char V_162 [ V_173 + 1 ] ;
T_16 V_164 ;
char V_165 ;
int V_209 ;
char * V_157 ;
int V_210 ;
char * V_158 ;
char * V_161 , * V_170 ;
int V_211 ;
V_164 = F_57 ( V_207 , & V_165 , V_173 , V_162 ,
& V_157 ) ;
if( V_164 <= 0 ) {
V_160 = F_55 ( V_1 -> V_3 , & V_161 ) ;
if( V_164 == 0 ) {
if ( V_160 == - 1 )
V_157 = V_161 ;
} else {
if ( V_160 == - 1 ) {
V_170 = F_17 ( L_67 , V_157 , V_161 ) ;
F_18 ( V_157 ) ;
F_18 ( V_161 ) ;
V_157 = V_170 ;
}
}
V_1 -> V_3 = - 1 ;
V_1 -> V_150 = V_160 ;
#ifdef F_2
F_46 ( V_1 -> V_4 ) ;
#endif
F_78 ( V_1 , V_157 ) ;
F_18 ( V_157 ) ;
return FALSE ;
}
switch( V_165 ) {
case V_212 :
if( ! F_79 ( V_1 , V_162 ) ) {
F_24 ( V_89 , V_90 , L_91 ) ;
F_46 ( V_207 ) ;
F_80 ( V_1 ) ;
F_78 ( V_1 , NULL ) ;
return FALSE ;
}
break;
case V_213 :
V_211 = atoi ( V_162 ) ;
F_24 ( V_89 , V_90 , L_92 , V_211 ) ;
F_81 ( V_1 , V_211 ) ;
break;
case V_174 :
F_58 ( ( V_175 * ) V_162 , 4 , & V_165 , & V_209 ) ;
V_157 = V_162 + 4 ;
F_58 ( ( V_175 * ) V_157 + V_209 , 4 , & V_165 , & V_210 ) ;
V_158 = V_157 + V_209 + 4 ;
F_82 ( V_1 , V_157 , V_158 ) ;
break;
case V_214 : {
char * V_215 ;
int V_216 ;
V_215 = strtok ( V_162 , L_93 ) ;
V_216 = ( int ) strtol ( V_215 , NULL , 10 ) ;
V_215 = strtok ( NULL , L_93 ) ;
F_83 ( V_1 , V_216 , V_215 ) ;
break;
}
case V_217 :
F_84 ( V_1 , ( V_218 ) strtoul ( V_162 , NULL , 10 ) ) ;
break;
default:
F_85 () ;
}
return TRUE ;
}
static int
F_55 ( int V_3 , T_2 * * V_155 )
{
int V_150 ;
int V_160 ;
T_17 V_177 ;
T_17 V_178 ;
float V_179 ;
F_62 ( & V_177 ) ;
F_24 ( V_89 , V_90 , L_94 ) ;
F_77 ( V_3 != - 1 ) ;
* V_155 = NULL ;
#ifdef F_2
if ( F_86 ( & V_150 , V_3 , V_219 ) == - 1 ) {
* V_155 = F_17 ( L_95 , F_43 ( V_149 ) ) ;
V_160 = - 1 ;
} else {
V_160 = V_150 ;
if ( ( V_150 & 0xC0000000 ) == V_220 ) {
* V_155 = F_17 ( L_96 ,
F_13 ( V_150 ) ) ;
V_160 = - 1 ;
}
}
#else
if ( F_87 ( V_3 , & V_150 , 0 ) != - 1 ) {
if ( F_88 ( V_150 ) ) {
V_160 = F_89 ( V_150 ) ;
} else if ( F_90 ( V_150 ) ) {
* V_155 = F_17 ( L_97 ,
F_91 ( F_92 ( V_150 ) ) ) ;
V_160 = - 1 ;
} else if ( F_93 ( V_150 ) ) {
* V_155 = F_17 ( L_98 ,
F_91 ( F_94 ( V_150 ) ) ,
F_95 ( V_150 ) ? L_99 : L_62 ) ;
V_160 = - 1 ;
} else {
* V_155 = F_17 ( L_100 ,
V_150 ) ;
V_160 = - 1 ;
}
} else {
* V_155 = F_17 ( L_101 , F_43 ( V_149 ) ) ;
V_160 = - 1 ;
}
#endif
F_62 ( & V_178 ) ;
V_179 = ( float ) ( ( V_178 . V_185 - V_177 . V_185 ) +
( ( V_178 . V_186 - V_177 . V_186 ) / 1e6 ) ) ;
F_24 ( V_89 , V_90 , L_102 , V_179 ) ;
return V_160 ;
}
static const char *
F_91 ( int V_221 )
{
const char * V_222 ;
static char V_223 [ 6 + 1 + 3 + 1 ] ;
switch ( V_221 ) {
case V_224 :
V_222 = L_103 ;
break;
case V_225 :
V_222 = L_104 ;
break;
case V_226 :
V_222 = L_105 ;
break;
case V_227 :
V_222 = L_14 ;
break;
case V_228 :
V_222 = L_106 ;
break;
case V_229 :
V_222 = L_107 ;
break;
case V_230 :
V_222 = L_108 ;
break;
case V_231 :
V_222 = L_109 ;
break;
case V_232 :
V_222 = L_110 ;
break;
case V_233 :
V_222 = L_111 ;
break;
#ifdef F_96
case F_96 :
V_222 = L_112 ;
break;
#endif
case V_234 :
V_222 = L_113 ;
break;
case V_235 :
V_222 = L_114 ;
break;
case V_236 :
V_222 = L_115 ;
break;
default:
F_12 ( V_223 , sizeof V_223 , L_116 , V_221 ) ;
V_222 = V_223 ;
break;
}
return V_222 ;
}
static void
F_97 ( T_1 * V_1 )
{
const char V_237 [] = L_117 ;
int V_160 ;
F_24 ( V_89 , V_90 , L_118 ) ;
V_160 = F_98 ( V_1 -> V_4 , V_237 , sizeof V_237 ) ;
if( V_160 == - 1 ) {
F_24 ( V_238 , V_239 ,
L_119 , V_1 -> V_4 , F_43 ( V_149 ) ) ;
}
}
void
F_80 ( T_1 * V_1 )
{
#ifdef F_2
int V_172 ;
T_5 V_240 ;
T_4 V_241 = TRUE ;
#endif
if ( V_1 -> V_3 != - 1 ) {
#ifndef F_2
int V_242 = F_99 ( V_1 -> V_3 , V_225 ) ;
if ( V_242 != 0 ) {
F_24 ( V_238 , V_239 ,
L_120 , F_43 ( V_149 ) ) ;
}
#else
#define F_100 500
#define F_101 50
F_97 ( V_1 ) ;
for ( V_172 = 0 ; V_172 < F_100 / F_101 ; V_172 ++ ) {
if ( F_102 ( ( T_8 ) V_1 -> V_3 , & V_240 ) &&
V_240 != V_243 ) {
V_241 = FALSE ;
break;
}
F_103 ( F_101 ) ;
}
if ( V_241 ) {
F_24 ( V_238 , V_239 ,
L_121 ) ;
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
int V_242 = F_99 ( V_3 , V_236 ) ;
if ( V_242 != 0 ) {
F_24 ( V_238 , V_239 ,
L_122 , F_43 ( V_149 ) ) ;
}
#else
F_104 ( ( T_8 ) ( V_3 ) , 0 ) ;
#endif
}
}
