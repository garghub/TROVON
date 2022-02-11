static const char * *
F_1 ( const char * * args , int * V_1 , const char * V_2 )
{
args = F_2 ( ( V_3 ) args , ( * V_1 + 2 ) * sizeof ( char * ) ) ;
args [ * V_1 ] = F_3 ( V_2 ) ;
( * V_1 ) ++ ;
args [ * V_1 ] = NULL ;
return args ;
}
static T_1 *
F_4 ( const T_1 * V_4 )
{
T_1 * V_5 ;
const T_1 * V_6 = V_4 ;
T_1 * V_7 ;
T_2 V_8 = 0 ;
T_3 V_9 = FALSE ;
while ( * V_6 ) {
if ( * V_6 == ' ' || * V_6 == '\t' )
V_9 = TRUE ;
else if ( * V_6 == '"' )
V_8 ++ ;
else if ( * V_6 == '\\' ) {
const T_1 * V_10 = V_6 ;
while ( * V_10 && * V_10 == '\\' )
V_10 ++ ;
if ( * V_10 == '"' )
V_8 ++ ;
}
V_8 ++ ;
V_6 ++ ;
}
V_7 = V_5 = F_5 ( V_8 + V_9 * 2 + 1 ) ;
V_6 = V_4 ;
if ( V_9 )
* V_7 ++ = '"' ;
while ( * V_6 ) {
if ( * V_6 == '"' )
* V_7 ++ = '\\' ;
else if ( * V_6 == '\\' ) {
const T_1 * V_10 = V_6 ;
while ( * V_10 && * V_10 == '\\' )
V_10 ++ ;
if ( * V_10 == '"' )
* V_7 ++ = '\\' ;
}
* V_7 ++ = * V_6 ;
V_6 ++ ;
}
if ( V_9 )
* V_7 ++ = '"' ;
* V_7 ++ = '\0' ;
return V_5 ;
}
static const char *
F_6 ( T_4 error )
{
static char V_11 [ V_12 + 1 ] ;
T_5 V_13 ;
char * V_6 ;
F_7 ( V_14 | V_15 ,
NULL , error , 0 , V_11 , V_12 , NULL ) ;
V_13 = strlen ( V_11 ) ;
if ( V_13 >= 2 ) {
V_11 [ V_13 - 1 ] = '\0' ;
V_11 [ V_13 - 2 ] = '\0' ;
}
V_6 = strchr ( V_11 , '\0' ) ;
F_8 ( V_6 , ( V_16 ) ( sizeof V_11 - ( V_6 - V_11 ) ) , L_1 , error ) ;
return V_11 ;
}
static const char *
F_9 ( T_4 V_17 )
{
static char V_11 [ V_12 + 1 ] ;
static const struct V_18 {
int V_19 ;
char * V_20 ;
} V_21 [] = {
{ V_22 , L_2 } ,
{ V_23 , L_3 } ,
{ V_24 , L_4 } ,
{ V_25 , L_5 } ,
{ V_26 , L_6 } ,
{ V_27 , L_7 } ,
{ V_28 , L_8 } ,
{ V_29 , L_9 } ,
{ V_30 , L_10 } ,
{ V_31 , L_11 } ,
{ V_32 , L_12 } ,
{ V_33 , L_13 } ,
{ V_34 , L_14 } ,
{ V_35 , L_15 } ,
{ V_36 , L_16 } ,
{ V_37 , L_17 } ,
{ V_38 , L_18 } ,
{ V_39 , L_19 } ,
{ V_40 , L_20 } ,
{ V_41 , L_21 } ,
{ V_42 , L_22 } ,
{ V_43 , L_23 } ,
{ 0 , NULL }
} ;
#define F_10 (sizeof exceptions / sizeof exceptions[0])
int V_44 ;
for ( V_44 = 0 ; V_44 < F_10 ; V_44 ++ ) {
if ( V_21 [ V_44 ] . V_19 == V_17 )
return V_21 [ V_44 ] . V_20 ;
}
F_8 ( V_11 , ( V_16 ) sizeof V_11 , L_24 , V_17 ) ;
return V_11 ;
}
static const char * *
F_11 ( int * V_1 ) {
const char * * V_4 ;
const char * V_45 ;
char * V_46 ;
V_45 = F_12 () ;
if ( V_45 == NULL ) {
return NULL ;
}
* V_1 = 0 ;
V_4 = F_5 ( sizeof ( char * ) ) ;
* V_4 = NULL ;
V_46 = F_13 ( L_25 V_47 L_26 , V_45 ) ;
V_4 = F_1 ( V_4 , V_1 , V_46 ) ;
F_14 ( V_46 ) ;
return V_4 ;
}
T_3
F_15 ( T_6 * V_48 ) {
char V_49 [ V_50 ] ;
char V_51 [ V_50 ] ;
char V_52 [ V_50 ] ;
char V_53 [ V_50 ] ;
char V_54 [ V_50 ] ;
char V_55 [ V_50 ] ;
char V_56 [ V_50 ] ;
char V_57 [ V_50 ] ;
char V_58 [ V_50 ] ;
#ifdef F_16
char V_59 [ 256 ] ;
#endif
#ifdef F_17
char V_60 [ V_50 ] ;
#endif
#if F_18 ( V_61 ) || F_18 ( V_62 )
char V_63 [ V_50 ] ;
#endif
#ifdef V_61
T_7 V_64 ;
T_7 V_65 ;
T_7 V_66 ;
T_8 * args = F_19 ( 200 ) ;
T_1 * V_67 ;
T_9 V_68 ;
T_10 V_69 ;
T_11 V_70 ;
char V_71 [ V_50 ] ;
T_1 * V_72 ;
#else
char V_73 [ 1024 + 1 ] ;
int V_74 [ 2 ] ;
enum T_12 { V_75 , V_76 };
#endif
int V_77 ;
int V_1 ;
const char * * V_4 ;
int V_44 ;
T_13 V_78 ;
T_14 V_79 ;
if ( V_48 -> V_80 -> V_8 > 1 )
V_48 -> V_81 = TRUE ;
F_20 ( V_82 , V_83 , L_27 ) ;
F_21 ( V_82 , V_83 , V_48 ) ;
V_48 -> V_84 = - 1 ;
V_4 = F_11 ( & V_1 ) ;
if ( ! V_4 ) {
F_22 ( L_28 ) ;
return FALSE ;
}
if ( V_48 -> V_80 -> V_8 > 1 )
V_4 = F_1 ( V_4 , & V_1 , L_29 ) ;
if ( V_48 -> V_81 )
V_4 = F_1 ( V_4 , & V_1 , L_30 ) ;
else
V_4 = F_1 ( V_4 , & V_1 , L_31 ) ;
if ( V_48 -> V_85 ) {
if ( V_48 -> V_86 ) {
V_4 = F_1 ( V_4 , & V_1 , L_32 ) ;
F_8 ( V_53 , V_50 , L_33 , V_48 -> V_87 ) ;
V_4 = F_1 ( V_4 , & V_1 , V_53 ) ;
}
if ( V_48 -> V_88 ) {
V_4 = F_1 ( V_4 , & V_1 , L_32 ) ;
F_8 ( V_54 , V_50 , L_34 , V_48 -> V_89 ) ;
V_4 = F_1 ( V_4 , & V_1 , V_54 ) ;
}
if ( V_48 -> V_90 ) {
V_4 = F_1 ( V_4 , & V_1 , L_32 ) ;
F_8 ( V_55 , V_50 , L_35 , V_48 -> V_91 ) ;
V_4 = F_1 ( V_4 , & V_1 , V_55 ) ;
}
if ( V_48 -> V_92 ) {
V_4 = F_1 ( V_4 , & V_1 , L_36 ) ;
F_8 ( V_56 , V_50 , L_35 , V_48 -> V_93 ) ;
V_4 = F_1 ( V_4 , & V_1 , V_56 ) ;
}
} else {
if ( V_48 -> V_86 ) {
V_4 = F_1 ( V_4 , & V_1 , L_36 ) ;
F_8 ( V_57 , V_50 , L_33 , V_48 -> V_87 ) ;
V_4 = F_1 ( V_4 , & V_1 , V_57 ) ;
}
}
if ( V_48 -> V_94 ) {
V_4 = F_1 ( V_4 , & V_1 , L_37 ) ;
F_8 ( V_52 , V_50 , L_38 , V_48 -> V_95 ) ;
V_4 = F_1 ( V_4 , & V_1 , V_52 ) ;
}
if ( V_48 -> V_96 ) {
V_4 = F_1 ( V_4 , & V_1 , L_36 ) ;
F_8 ( V_58 , V_50 , L_34 , V_48 -> V_97 ) ;
V_4 = F_1 ( V_4 , & V_1 , V_58 ) ;
}
for ( V_78 = 0 ; V_78 < V_48 -> V_80 -> V_8 ; V_78 ++ ) {
V_79 = F_23 ( V_48 -> V_80 , T_14 , V_78 ) ;
V_4 = F_1 ( V_4 , & V_1 , L_39 ) ;
V_4 = F_1 ( V_4 , & V_1 , V_79 . V_98 ) ;
if ( V_79 . V_99 != NULL && strlen ( V_79 . V_99 ) != 0 ) {
V_4 = F_1 ( V_4 , & V_1 , L_40 ) ;
V_4 = F_1 ( V_4 , & V_1 , V_79 . V_99 ) ;
}
if ( V_79 . V_100 != V_101 ) {
V_4 = F_1 ( V_4 , & V_1 , L_41 ) ;
F_8 ( V_49 , V_50 , L_38 , V_79 . V_100 ) ;
V_4 = F_1 ( V_4 , & V_1 , V_49 ) ;
}
if ( V_79 . V_102 != - 1 ) {
V_4 = F_1 ( V_4 , & V_1 , L_42 ) ;
F_8 ( V_51 , V_50 , L_25 , F_24 ( V_79 . V_102 ) ) ;
V_4 = F_1 ( V_4 , & V_1 , V_51 ) ;
}
if ( ! V_79 . V_103 ) {
V_4 = F_1 ( V_4 , & V_1 , L_43 ) ;
}
#if F_18 ( V_61 ) || F_18 ( V_62 )
if ( V_79 . V_63 != 1 ) {
V_4 = F_1 ( V_4 , & V_1 , L_44 ) ;
F_8 ( V_63 , V_50 , L_38 , V_79 . V_63 ) ;
V_4 = F_1 ( V_4 , & V_1 , V_63 ) ;
}
#endif
#ifdef V_62
if ( V_79 . V_104 ) {
V_4 = F_1 ( V_4 , & V_1 , L_45 ) ;
}
#endif
#ifdef F_16
if ( V_79 . V_105 )
V_4 = F_1 ( V_4 , & V_1 , L_46 ) ;
if ( ! V_79 . V_106 )
V_4 = F_1 ( V_4 , & V_1 , L_47 ) ;
if ( V_79 . V_107 == V_108 ) {
V_4 = F_1 ( V_4 , & V_1 , L_48 ) ;
F_8 ( V_59 , sizeof( V_59 ) , L_49 ,
V_79 . V_109 ,
V_79 . V_110 ) ;
V_4 = F_1 ( V_4 , & V_1 , V_59 ) ;
}
#endif
#ifdef F_17
if ( V_79 . V_111 != V_112 ) {
V_4 = F_1 ( V_4 , & V_1 , L_50 ) ;
F_8 ( V_60 , V_50 , L_51 ,
V_79 . V_111 == V_113 ? L_52 :
V_79 . V_111 == V_114 ? L_53 :
L_54 ,
V_79 . V_115 ) ;
V_4 = F_1 ( V_4 , & V_1 , V_60 ) ;
}
#endif
}
#ifndef F_25
V_4 = F_1 ( V_4 , & V_1 , L_55 ) ;
#ifdef V_61
F_8 ( V_71 , V_50 , L_38 , F_26 () ) ;
V_4 = F_1 ( V_4 , & V_1 , V_71 ) ;
#else
V_4 = F_1 ( V_4 , & V_1 , V_116 ) ;
#endif
#endif
if ( V_48 -> V_117 ) {
V_4 = F_1 ( V_4 , & V_1 , L_56 ) ;
V_4 = F_1 ( V_4 , & V_1 , V_48 -> V_117 ) ;
}
for ( V_44 = 0 ; V_44 < V_1 ; V_44 ++ ) {
F_20 ( V_82 , V_83 , L_57 , V_44 , V_4 [ V_44 ] ) ;
}
#ifdef V_61
V_68 . V_118 = sizeof( T_9 ) ;
V_68 . V_119 = TRUE ;
V_68 . V_120 = NULL ;
if ( ! F_27 ( & V_64 , & V_65 , & V_68 , 5120 ) ) {
F_22 ( L_58 ,
F_6 ( F_28 () ) ) ;
for ( V_44 = 0 ; V_44 < V_1 ; V_44 ++ ) {
F_14 ( ( V_3 ) V_4 [ V_44 ] ) ;
}
F_14 ( ( V_3 ) V_4 ) ;
return FALSE ;
}
V_72 = F_13 ( V_121 , V_71 ) ;
V_66 = F_29 ( F_30 ( V_72 ) ,
V_122 , V_123 , 1 , 65535 , 65535 , 0 , NULL ) ;
F_14 ( V_72 ) ;
if ( V_66 == V_124 ) {
F_22 ( L_59 ,
F_6 ( F_28 () ) ) ;
for ( V_44 = 0 ; V_44 < V_1 ; V_44 ++ ) {
F_14 ( ( V_3 ) V_4 [ V_44 ] ) ;
}
F_14 ( ( V_3 ) V_4 ) ;
return FALSE ;
}
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
V_69 . V_125 = sizeof( V_69 ) ;
#ifdef F_25
V_69 . V_126 = V_127 ;
V_69 . V_128 = V_129 ;
#else
V_69 . V_126 = V_130 | V_127 ;
V_69 . V_128 = V_131 ;
V_69 . V_132 = F_31 ( V_133 ) ;
V_69 . V_134 = F_31 ( V_135 ) ;
V_69 . V_136 = V_65 ;
#endif
for( V_44 = 0 ; V_4 [ V_44 ] != 0 ; V_44 ++ ) {
if( V_44 != 0 ) F_32 ( args , ' ' ) ;
V_67 = F_4 ( V_4 [ V_44 ] ) ;
F_33 ( args , V_67 ) ;
F_14 ( V_67 ) ;
}
if( ! F_34 ( NULL , F_30 ( args -> V_137 ) , NULL , NULL , TRUE ,
V_138 , NULL , NULL , & V_69 , & V_70 ) ) {
F_22 ( L_60 ,
args -> V_137 , F_6 ( F_28 () ) ) ;
F_35 ( V_64 ) ;
F_35 ( V_65 ) ;
for ( V_44 = 0 ; V_44 < V_1 ; V_44 ++ ) {
F_14 ( ( V_3 ) V_4 [ V_44 ] ) ;
}
F_14 ( ( V_3 ) V_4 ) ;
return FALSE ;
}
V_48 -> V_84 = ( int ) V_70 . V_139 ;
F_36 ( args , TRUE ) ;
V_77 = F_37 ( ( long ) V_64 , V_140 ) ;
V_48 -> V_141 = F_37 ( ( long ) V_66 , V_140 ) ;
#else
if ( F_38 ( V_74 ) < 0 ) {
F_22 ( L_58 , F_39 ( V_142 ) ) ;
for ( V_44 = 0 ; V_44 < V_1 ; V_44 ++ ) {
F_14 ( ( V_3 ) V_4 [ V_44 ] ) ;
}
F_14 ( V_4 ) ;
return FALSE ;
}
if ( ( V_48 -> V_84 = F_40 () ) == 0 ) {
F_41 ( V_74 [ V_76 ] , 2 ) ;
F_42 ( V_74 [ V_75 ] ) ;
F_43 ( V_4 [ 0 ] , ( V_3 ) V_4 ) ;
F_8 ( V_73 , sizeof V_73 , L_60 ,
V_4 [ 0 ] , F_39 ( V_142 ) ) ;
F_44 ( 2 , V_73 , L_61 ) ;
F_45 ( 1 ) ;
}
V_77 = V_74 [ V_75 ] ;
#endif
for ( V_44 = 0 ; V_44 < V_1 ; V_44 ++ ) {
F_14 ( ( V_3 ) V_4 [ V_44 ] ) ;
}
F_14 ( ( V_3 ) V_4 ) ;
#ifdef V_61
F_35 ( V_65 ) ;
#else
F_42 ( V_74 [ V_76 ] ) ;
#endif
if ( V_48 -> V_84 == - 1 ) {
F_22 ( L_62 , F_39 ( V_142 ) ) ;
F_42 ( V_77 ) ;
#ifdef V_61
F_42 ( V_48 -> V_141 ) ;
#endif
return FALSE ;
}
V_48 -> V_143 = 0 ;
F_46 () ;
F_47 ( V_77 , ( V_3 ) V_48 ,
& V_48 -> V_84 , V_144 ) ;
return TRUE ;
}
static int
F_48 ( const char * * V_4 , int * V_145 ,
int * V_146 , int * V_84 , T_1 * * V_20 )
{
enum T_12 { V_75 , V_76 };
#ifdef V_61
T_7 V_74 [ 2 ] ;
T_7 V_147 [ 2 ] ;
T_8 * args = F_19 ( 200 ) ;
T_1 * V_67 ;
T_9 V_68 ;
T_10 V_69 ;
T_11 V_70 ;
#else
char V_73 [ 1024 + 1 ] ;
int V_74 [ 2 ] ;
int V_147 [ 2 ] ;
#endif
int V_44 ;
* V_84 = - 1 ;
* V_145 = - 1 ;
* V_146 = - 1 ;
F_20 ( V_82 , V_83 , L_63 ) ;
if ( ! V_20 ) {
#ifdef V_61
F_36 ( args , TRUE ) ;
#endif
return - 1 ;
}
#ifdef V_61
V_68 . V_118 = sizeof( T_9 ) ;
V_68 . V_119 = TRUE ;
V_68 . V_120 = NULL ;
if ( ! F_27 ( & V_74 [ V_75 ] , & V_74 [ V_76 ] , & V_68 , 5120 ) ) {
* V_20 = F_13 ( L_58 ,
F_6 ( F_28 () ) ) ;
for ( V_44 = 0 ; V_4 [ V_44 ] != NULL ; V_44 ++ ) {
F_14 ( ( V_3 ) V_4 [ V_44 ] ) ;
}
F_14 ( ( V_3 ) V_4 ) ;
return - 1 ;
}
if ( ! F_27 ( & V_147 [ V_75 ] , & V_147 [ V_76 ] , & V_68 , 5120 ) ) {
* V_20 = F_13 ( L_64 ,
F_6 ( F_28 () ) ) ;
F_35 ( V_74 [ V_75 ] ) ;
F_35 ( V_74 [ V_76 ] ) ;
for ( V_44 = 0 ; V_4 [ V_44 ] != NULL ; V_44 ++ ) {
F_14 ( ( V_3 ) V_4 [ V_44 ] ) ;
}
F_14 ( ( V_3 ) V_4 ) ;
return - 1 ;
}
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
V_69 . V_125 = sizeof( V_69 ) ;
#ifdef F_25
V_69 . V_126 = V_127 ;
V_69 . V_128 = V_129 ;
#else
V_69 . V_126 = V_130 | V_127 ;
V_69 . V_128 = V_131 ;
V_69 . V_132 = NULL ;
V_69 . V_134 = V_147 [ V_76 ] ;
V_69 . V_136 = V_74 [ V_76 ] ;
#endif
for( V_44 = 0 ; V_4 [ V_44 ] != 0 ; V_44 ++ ) {
if( V_44 != 0 ) F_32 ( args , ' ' ) ;
V_67 = F_4 ( V_4 [ V_44 ] ) ;
F_33 ( args , V_67 ) ;
F_14 ( V_67 ) ;
}
if( ! F_34 ( NULL , F_30 ( args -> V_137 ) , NULL , NULL , TRUE ,
V_138 , NULL , NULL , & V_69 , & V_70 ) ) {
* V_20 = F_13 ( L_60 ,
args -> V_137 , F_6 ( F_28 () ) ) ;
F_35 ( V_147 [ V_75 ] ) ;
F_35 ( V_147 [ V_76 ] ) ;
F_35 ( V_74 [ V_75 ] ) ;
F_35 ( V_74 [ V_76 ] ) ;
for ( V_44 = 0 ; V_4 [ V_44 ] != NULL ; V_44 ++ ) {
F_14 ( ( V_3 ) V_4 [ V_44 ] ) ;
}
F_14 ( ( V_3 ) V_4 ) ;
return - 1 ;
}
* V_84 = ( int ) V_70 . V_139 ;
F_36 ( args , TRUE ) ;
* V_145 = F_37 ( ( long ) V_147 [ V_75 ] , V_140 ) ;
* V_146 = F_37 ( ( long ) V_74 [ V_75 ] , V_140 ) ;
#else
if ( F_38 ( V_74 ) < 0 ) {
* V_20 = F_13 ( L_58 , F_39 ( V_142 ) ) ;
for ( V_44 = 0 ; V_4 [ V_44 ] != NULL ; V_44 ++ ) {
F_14 ( ( V_3 ) V_4 [ V_44 ] ) ;
}
F_14 ( V_4 ) ;
return - 1 ;
}
if ( F_38 ( V_147 ) < 0 ) {
* V_20 = F_13 ( L_64 , F_39 ( V_142 ) ) ;
F_42 ( V_74 [ V_75 ] ) ;
F_42 ( V_74 [ V_76 ] ) ;
for ( V_44 = 0 ; V_4 [ V_44 ] != NULL ; V_44 ++ ) {
F_14 ( ( V_3 ) V_4 [ V_44 ] ) ;
}
F_14 ( V_4 ) ;
return - 1 ;
}
if ( ( * V_84 = F_40 () ) == 0 ) {
F_41 ( V_147 [ V_76 ] , 1 ) ;
F_42 ( V_147 [ V_75 ] ) ;
F_42 ( V_147 [ V_76 ] ) ;
F_41 ( V_74 [ V_76 ] , 2 ) ;
F_42 ( V_74 [ V_75 ] ) ;
F_42 ( V_74 [ V_76 ] ) ;
F_43 ( V_4 [ 0 ] , ( V_3 ) V_4 ) ;
F_8 ( V_73 , sizeof V_73 , L_60 ,
V_4 [ 0 ] , F_39 ( V_142 ) ) ;
F_44 ( 2 , V_73 , L_61 ) ;
F_45 ( 1 ) ;
}
* V_145 = V_147 [ V_75 ] ;
* V_146 = V_74 [ V_75 ] ;
#endif
for ( V_44 = 0 ; V_4 [ V_44 ] != NULL ; V_44 ++ ) {
F_14 ( ( V_3 ) V_4 [ V_44 ] ) ;
}
F_14 ( ( V_3 ) V_4 ) ;
#ifdef V_61
F_35 ( V_147 [ V_76 ] ) ;
F_35 ( V_74 [ V_76 ] ) ;
#else
F_42 ( V_147 [ V_76 ] ) ;
F_42 ( V_74 [ V_76 ] ) ;
#endif
if ( * V_84 == - 1 ) {
* V_20 = F_13 ( L_62 , F_39 ( V_142 ) ) ;
F_42 ( * V_145 ) ;
F_42 ( * V_146 ) ;
return - 1 ;
}
F_46 () ;
return 0 ;
}
static int
F_49 ( int * V_145 , int * V_146 ,
int * V_84 , T_1 * * V_148 )
{
F_42 ( * V_145 ) ;
if ( V_146 != NULL )
F_42 ( * V_146 ) ;
#ifdef V_61
F_50 ( * V_84 ) ;
#endif
return F_51 ( * V_84 , V_148 ) ;
}
static int
F_52 ( const char * * V_4 , T_1 * * V_149 , T_1 * * V_150 ,
T_1 * * V_151 )
{
T_1 * V_20 ;
int V_152 , V_77 , V_84 , V_153 ;
char * V_154 ;
T_1 V_155 [ V_156 + 1 ] ;
int V_157 ;
char V_158 ;
int V_159 ;
char * V_160 ;
int V_161 ;
char * V_162 ;
char * V_163 ;
T_8 * V_164 = NULL ;
int V_165 ;
V_153 = F_48 ( V_4 , & V_152 , & V_77 ,
& V_84 , & V_20 ) ;
if ( V_153 == - 1 ) {
* V_150 = V_20 ;
* V_151 = NULL ;
* V_149 = NULL ;
return - 1 ;
}
V_157 = F_53 ( V_77 , & V_158 , V_166 ,
V_155 , V_150 ) ;
if( V_157 <= 0 ) {
V_153 = F_51 ( V_84 , & V_154 ) ;
if( V_157 == 0 ) {
if ( V_153 == - 1 )
* V_150 = V_154 ;
else
* V_150 = F_3 ( L_65 ) ;
} else {
if ( V_153 == - 1 ) {
V_163 = F_13 ( L_66 , * V_150 , V_154 ) ;
F_14 ( * V_150 ) ;
F_14 ( V_154 ) ;
* V_150 = V_163 ;
}
}
* V_151 = NULL ;
return - 1 ;
}
switch( V_158 ) {
case V_167 :
F_54 ( V_155 , 4 , & V_158 , & V_159 ) ;
V_160 = V_155 + 4 ;
F_54 ( V_160 + V_159 , 4 , & V_158 ,
& V_161 ) ;
V_162 = V_160 + V_159 + 4 ;
V_153 = F_49 ( & V_152 , & V_77 ,
& V_84 , & V_20 ) ;
if ( V_153 == - 1 ) {
* V_150 = V_20 ;
* V_151 = NULL ;
} else {
* V_150 = F_3 ( V_160 ) ;
* V_151 = F_3 ( V_162 ) ;
V_153 = - 1 ;
}
* V_149 = NULL ;
break;
case V_168 :
V_164 = F_55 ( L_61 ) ;
while ( ( V_165 = F_56 ( V_152 , V_155 , V_156 ) ) > 0 ) {
V_155 [ V_165 ] = '\0' ;
F_33 ( V_164 , V_155 ) ;
}
V_153 = F_49 ( & V_152 , & V_77 ,
& V_84 , & V_20 ) ;
if ( V_153 == - 1 ) {
* V_150 = V_20 ;
* V_151 = NULL ;
F_36 ( V_164 , TRUE ) ;
* V_149 = NULL ;
} else {
* V_150 = NULL ;
* V_151 = NULL ;
* V_149 = V_164 -> V_137 ;
F_36 ( V_164 , FALSE ) ;
}
break;
default:
V_153 = F_49 ( & V_152 , & V_77 ,
& V_84 , & V_20 ) ;
if ( V_153 == - 1 ) {
* V_150 = V_20 ;
* V_151 = NULL ;
} else {
* V_150 = F_13 ( L_67 ,
V_158 ) ;
* V_151 = NULL ;
V_153 = - 1 ;
}
* V_149 = NULL ;
break;
}
return V_153 ;
}
int
F_57 ( T_1 * * V_149 , T_1 * * V_150 ,
T_1 * * V_151 )
{
int V_1 ;
const char * * V_4 ;
F_20 ( V_82 , V_83 , L_68 ) ;
V_4 = F_11 ( & V_1 ) ;
if ( ! V_4 ) {
* V_150 = F_3 ( L_28 ) ;
* V_151 = NULL ;
* V_149 = NULL ;
return - 1 ;
}
V_4 = F_1 ( V_4 , & V_1 , L_69 ) ;
#ifndef F_25
V_4 = F_1 ( V_4 , & V_1 , L_55 ) ;
V_4 = F_1 ( V_4 , & V_1 , V_116 ) ;
#endif
return F_52 ( V_4 , V_149 , V_150 , V_151 ) ;
}
int
F_58 ( const T_1 * V_169 , T_3 V_104 ,
T_1 * * V_149 , T_1 * * V_150 ,
T_1 * * V_151 )
{
int V_1 ;
const char * * V_4 ;
F_20 ( V_82 , V_83 , L_70 ) ;
V_4 = F_11 ( & V_1 ) ;
if ( ! V_4 ) {
* V_150 = F_3 ( L_28 ) ;
* V_151 = NULL ;
* V_149 = NULL ;
return - 1 ;
}
V_4 = F_1 ( V_4 , & V_1 , L_39 ) ;
V_4 = F_1 ( V_4 , & V_1 , V_169 ) ;
V_4 = F_1 ( V_4 , & V_1 , L_71 ) ;
if ( V_104 )
V_4 = F_1 ( V_4 , & V_1 , L_45 ) ;
#ifndef F_25
V_4 = F_1 ( V_4 , & V_1 , L_55 ) ;
V_4 = F_1 ( V_4 , & V_1 , V_116 ) ;
#endif
return F_52 ( V_4 , V_149 , V_150 , V_151 ) ;
}
int
F_59 ( int * V_145 , int * V_84 , T_1 * * V_20 )
{
int V_1 ;
const char * * V_4 ;
int V_146 , V_153 ;
char * V_154 ;
T_1 V_155 [ V_156 + 1 ] ;
int V_157 ;
char V_158 ;
int V_159 ;
char * V_160 ;
int V_161 ;
char * V_163 ;
F_20 ( V_82 , V_83 , L_72 ) ;
V_4 = F_11 ( & V_1 ) ;
if ( ! V_4 ) {
* V_20 = F_3 ( L_28 ) ;
return - 1 ;
}
V_4 = F_1 ( V_4 , & V_1 , L_73 ) ;
#ifndef F_25
V_4 = F_1 ( V_4 , & V_1 , L_55 ) ;
V_4 = F_1 ( V_4 , & V_1 , V_116 ) ;
#endif
V_153 = F_48 ( V_4 , V_145 , & V_146 ,
V_84 , V_20 ) ;
if ( V_153 == - 1 )
return - 1 ;
V_157 = F_53 ( V_146 , & V_158 , V_166 ,
V_155 , V_20 ) ;
if( V_157 <= 0 ) {
V_153 = F_51 ( * V_84 , & V_154 ) ;
if( V_157 == 0 ) {
if ( V_153 == - 1 )
* V_20 = V_154 ;
else
* V_20 = F_3 ( L_65 ) ;
} else {
if ( V_153 == - 1 ) {
V_163 = F_13 ( L_66 , * V_20 , V_154 ) ;
F_14 ( * V_20 ) ;
F_14 ( V_154 ) ;
* V_20 = V_163 ;
}
}
return - 1 ;
}
switch( V_158 ) {
case V_167 :
F_54 ( V_155 , 4 , & V_158 , & V_159 ) ;
V_160 = V_155 + 4 ;
F_54 ( V_160 + V_159 , 4 , & V_158 ,
& V_161 ) ;
V_153 = F_49 ( V_145 , & V_146 ,
V_84 , V_20 ) ;
if ( V_153 == - 1 ) {
} else {
* V_20 = F_3 ( V_160 ) ;
V_153 = - 1 ;
}
break;
case V_168 :
F_42 ( V_146 ) ;
break;
default:
V_153 = F_49 ( V_145 , & V_146 ,
V_84 , V_20 ) ;
if ( V_153 == - 1 ) {
} else {
* V_20 = F_13 ( L_67 ,
V_158 ) ;
V_153 = - 1 ;
}
break;
}
return V_153 ;
}
int
F_60 ( int * V_170 , int * V_84 , T_1 * * V_20 )
{
return F_49 ( V_170 , NULL , V_84 , V_20 ) ;
}
static int
F_61 ( int V_171 , char * V_172 , int V_173 , char * * V_20 )
{
int V_174 ;
int V_175 = 0 ;
int error ;
while( V_173 ) {
V_174 = F_62 ( V_171 , & V_172 [ V_175 ] , V_173 ) ;
if ( V_174 == 0 ) {
F_20 ( V_82 , V_83 ,
L_74 , V_171 ) ;
* V_20 = 0 ;
return V_175 ;
}
if ( V_174 < 0 ) {
error = V_142 ;
F_20 ( V_82 , V_83 ,
L_75 , V_171 , error ,
F_39 ( error ) ) ;
* V_20 = F_13 ( L_76 ,
F_39 ( error ) ) ;
return V_174 ;
}
V_173 -= V_174 ;
V_175 += V_174 ;
}
* V_20 = NULL ;
return V_175 ;
}
static T_3 F_63 ( int V_171 ) {
#ifdef V_61
T_7 V_176 = ( T_7 ) F_64 ( V_171 ) ;
T_4 V_177 ;
if ( V_176 == V_124 )
return FALSE ;
if ( ! F_65 ( V_176 , NULL , 0 , NULL , & V_177 , NULL ) )
return FALSE ;
if ( V_177 > 0 )
return TRUE ;
return FALSE ;
#else
T_15 V_178 ;
struct V_179 V_180 ;
F_66 ( & V_178 ) ;
F_67 ( V_171 , & V_178 ) ;
V_180 . V_181 = 0 ;
V_180 . V_182 = 0 ;
if ( F_68 ( V_171 + 1 , & V_178 , NULL , NULL , & V_180 ) > 0 )
return TRUE ;
return FALSE ;
#endif
}
int
F_69 ( int V_171 , char * V_172 , int V_183 ) {
int V_174 ;
int V_175 = - 1 ;
while( V_175 < V_183 - 1 ) {
V_175 ++ ;
if ( ! F_63 ( V_171 ) )
break;
V_174 = F_62 ( V_171 , & V_172 [ V_175 ] , 1 ) ;
if ( V_174 == 0 ) {
break;
} else if ( V_174 < 0 ) {
F_20 ( V_82 , V_83 ,
L_75 , V_171 , V_142 , F_39 ( V_142 ) ) ;
return V_174 ;
} else if ( V_172 [ V_175 ] == '\n' ) {
break;
}
}
if ( V_175 >= 0 )
V_172 [ V_175 ] = '\0' ;
return V_175 ;
}
static void
F_54 ( const T_16 * V_184 , int V_185 , char * V_158 , int * V_186 ) {
F_70 ( V_185 == 4 ) ;
* V_158 = V_184 [ 0 ] ;
* V_186 = V_184 [ 1 ] << 16 | V_184 [ 2 ] << 8 | V_184 [ 3 ] ;
}
static int
F_53 ( int V_171 , char * V_158 , int V_8 , char * V_20 ,
char * * V_187 )
{
int V_173 ;
int V_174 ;
T_16 V_184 [ 4 ] ;
V_174 = F_61 ( V_171 , V_184 , 4 , V_187 ) ;
if( V_174 != 4 ) {
if ( V_174 == 0 ) {
F_20 ( V_82 , V_83 ,
L_77 , V_171 ) ;
return 0 ;
}
F_20 ( V_82 , V_83 ,
L_78 , V_171 , V_174 ) ;
if ( V_174 != - 1 ) {
* V_187 = F_13 ( L_79 ,
V_174 ) ;
}
return - 1 ;
}
F_54 ( V_184 , 4 , V_158 , & V_173 ) ;
if( V_173 == 0 ) {
F_20 ( V_82 , V_83 ,
L_80 , V_171 , * V_158 ) ;
return 4 ;
}
if( V_173 > V_8 ) {
F_20 ( V_82 , V_83 ,
L_81 ,
V_171 , V_173 , V_8 ,
V_184 [ 0 ] , V_184 [ 1 ] , V_184 [ 2 ] , V_184 [ 3 ] ) ;
memcpy ( V_20 , V_184 , sizeof( V_184 ) ) ;
V_174 = F_62 ( V_171 , & V_20 [ sizeof( V_184 ) ] , V_8 - sizeof( V_184 ) ) ;
* V_187 = F_13 ( L_82 ,
V_20 ) ;
return - 1 ;
}
V_8 = V_173 ;
V_174 = F_61 ( V_171 , V_20 , V_173 , V_187 ) ;
if( V_174 != V_173 ) {
if ( V_174 != - 1 ) {
* V_187 = F_13 ( L_82 ,
V_20 ) ;
}
return - 1 ;
}
F_20 ( V_82 , V_83 ,
L_83 , V_171 , * V_158 ,
V_8 , V_20 ) ;
* V_187 = NULL ;
return V_174 + 4 ;
}
static T_3
V_144 ( T_2 V_188 , V_3 V_189 )
{
T_6 * V_48 = ( T_6 * ) V_189 ;
int V_153 ;
char V_155 [ V_166 + 1 ] ;
int V_157 ;
char V_158 ;
int V_190 ;
char * V_150 ;
int V_191 ;
char * V_151 ;
char * V_154 , * V_163 ;
V_157 = F_53 ( V_188 , & V_158 , V_166 , V_155 ,
& V_150 ) ;
if( V_157 <= 0 ) {
V_153 = F_51 ( V_48 -> V_84 , & V_154 ) ;
if( V_157 == 0 ) {
if ( V_153 == - 1 )
V_150 = V_154 ;
} else {
if ( V_153 == - 1 ) {
V_163 = F_13 ( L_66 , V_150 , V_154 ) ;
F_14 ( V_150 ) ;
F_14 ( V_154 ) ;
V_150 = V_163 ;
}
}
V_48 -> V_84 = - 1 ;
V_48 -> V_143 = V_153 ;
#ifdef V_61
F_42 ( V_48 -> V_141 ) ;
#endif
F_71 ( V_48 , V_150 ) ;
F_14 ( V_150 ) ;
return FALSE ;
}
switch( V_158 ) {
case V_192 :
if( ! F_72 ( V_48 , V_155 ) ) {
F_20 ( V_82 , V_83 , L_84 ) ;
F_42 ( V_188 ) ;
F_73 ( V_48 ) ;
F_71 ( V_48 , NULL ) ;
return FALSE ;
}
break;
case V_193 :
V_157 = atoi ( V_155 ) ;
F_20 ( V_82 , V_83 , L_85 , V_157 ) ;
F_74 ( V_48 , V_157 ) ;
break;
case V_167 :
F_54 ( V_155 , 4 , & V_158 , & V_190 ) ;
V_150 = V_155 + 4 ;
F_54 ( V_150 + V_190 , 4 , & V_158 , & V_191 ) ;
V_151 = V_150 + V_190 + 4 ;
F_75 ( V_48 , V_150 , V_151 ) ;
break;
case V_194 : {
char * V_195 ;
int V_196 ;
V_195 = strtok ( V_155 , L_86 ) ;
V_196 = ( int ) strtol ( V_195 , NULL , 10 ) ;
V_195 = strtok ( NULL , L_86 ) ;
F_76 ( V_48 , V_196 , V_195 ) ;
break;
}
case V_197 :
F_77 ( V_48 , ( V_198 ) strtoul ( V_155 , NULL , 10 ) ) ;
break;
default:
F_78 () ;
}
return TRUE ;
}
static int
F_51 ( int V_84 , T_1 * * V_148 )
{
int V_143 ;
int V_153 ;
F_20 ( V_82 , V_83 , L_87 ) ;
F_70 ( V_84 != - 1 ) ;
* V_148 = NULL ;
#ifdef V_61
if ( F_79 ( & V_143 , V_84 , V_199 ) == - 1 ) {
* V_148 = F_13 ( L_88 , F_39 ( V_142 ) ) ;
V_153 = - 1 ;
} else {
V_153 = V_143 ;
if ( ( V_143 & 0xC0000000 ) == V_200 ) {
* V_148 = F_13 ( L_89 ,
F_9 ( V_143 ) ) ;
V_153 = - 1 ;
}
}
#else
if ( F_80 ( V_84 , & V_143 , 0 ) != - 1 ) {
if ( F_81 ( V_143 ) ) {
V_153 = F_82 ( V_143 ) ;
} else if ( F_83 ( V_143 ) ) {
* V_148 = F_13 ( L_90 ,
F_84 ( F_85 ( V_143 ) ) ) ;
V_153 = - 1 ;
} else if ( F_86 ( V_143 ) ) {
* V_148 = F_13 ( L_91 ,
F_84 ( F_87 ( V_143 ) ) ,
F_88 ( V_143 ) ? L_92 : L_61 ) ;
V_153 = - 1 ;
} else {
* V_148 = F_13 ( L_93 ,
V_143 ) ;
V_153 = - 1 ;
}
} else {
* V_148 = F_13 ( L_94 , F_39 ( V_142 ) ) ;
V_153 = - 1 ;
}
#endif
F_20 ( V_82 , V_83 , L_95 ) ;
return V_153 ;
}
static const char *
F_84 ( int V_201 )
{
const char * V_202 ;
static char V_203 [ 6 + 1 + 3 + 1 ] ;
switch ( V_201 ) {
case V_204 :
V_202 = L_96 ;
break;
case V_205 :
V_202 = L_97 ;
break;
case V_206 :
V_202 = L_98 ;
break;
case V_207 :
V_202 = L_14 ;
break;
case V_208 :
V_202 = L_99 ;
break;
case V_209 :
V_202 = L_100 ;
break;
case V_210 :
V_202 = L_101 ;
break;
case V_211 :
V_202 = L_102 ;
break;
case V_212 :
V_202 = L_103 ;
break;
case V_213 :
V_202 = L_104 ;
break;
#ifdef F_89
case F_89 :
V_202 = L_105 ;
break;
#endif
case V_214 :
V_202 = L_106 ;
break;
case V_215 :
V_202 = L_107 ;
break;
case V_216 :
V_202 = L_108 ;
break;
default:
F_8 ( V_203 , sizeof V_203 , L_109 , V_201 ) ;
V_202 = V_203 ;
break;
}
return V_202 ;
}
static void
F_90 ( T_6 * V_48 )
{
const char V_217 [] = L_110 ;
int V_153 ;
F_20 ( V_82 , V_83 , L_111 ) ;
V_153 = F_91 ( V_48 -> V_141 , V_217 , sizeof V_217 ) ;
if( V_153 == - 1 ) {
F_20 ( V_218 , V_219 ,
L_112 , V_48 -> V_141 , F_39 ( V_142 ) ) ;
}
}
void
F_73 ( T_6 * V_48 )
{
#ifdef V_61
int V_165 ;
T_4 V_220 ;
T_3 V_221 = TRUE ;
#endif
if ( V_48 -> V_84 != - 1 ) {
#ifndef V_61
int V_222 = F_92 ( V_48 -> V_84 , V_205 ) ;
if ( V_222 != 0 ) {
F_20 ( V_218 , V_219 ,
L_113 , F_39 ( V_142 ) ) ;
}
#else
#define F_93 500
#define F_94 50
F_90 ( V_48 ) ;
for ( V_165 = 0 ; V_165 < F_93 / F_94 ; V_165 ++ ) {
if ( F_95 ( ( T_7 ) V_48 -> V_84 , & V_220 ) &&
V_220 != V_223 ) {
V_221 = FALSE ;
break;
}
F_96 ( F_94 ) ;
}
if ( V_221 ) {
F_20 ( V_218 , V_219 ,
L_114 ) ;
F_50 ( V_48 -> V_84 ) ;
}
#endif
}
}
void
F_50 ( int V_84 )
{
if ( V_84 != - 1 ) {
#ifndef V_61
int V_222 = F_92 ( V_84 , V_216 ) ;
if ( V_222 != 0 ) {
F_20 ( V_218 , V_219 ,
L_115 , F_39 ( V_142 ) ) ;
}
#else
F_97 ( ( T_7 ) ( V_84 ) , 0 ) ;
#endif
}
}
