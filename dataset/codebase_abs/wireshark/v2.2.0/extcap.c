static T_1
F_1 ( const T_2 * V_1 )
{
if ( ! V_1 || ! V_2 )
return FALSE ;
if ( F_2 ( V_2 , V_1 ) )
return TRUE ;
return FALSE ;
}
static T_1
F_3 ( const T_2 * V_1 , const T_2 * V_3 )
{
T_2 * V_4 = ( T_2 * ) F_2 ( V_2 , V_1 ) ;
if ( V_4 && strcmp ( V_4 , V_3 ) == 0 )
return TRUE ;
return FALSE ;
}
static T_2 *
F_4 ( const T_2 * V_1 )
{
return ( T_2 * ) F_2 ( V_2 , V_1 ) ;
}
static void
F_5 ( const T_2 * V_1 , const T_2 * V_3 )
{
if ( ! F_2 ( V_2 , V_1 ) )
F_6 ( V_2 , F_7 ( V_1 ) , F_7 ( V_3 ) ) ;
}
static void
F_8 ( T_3 V_5 ) {
T_4 * V_6 = ( T_4 * ) V_5 ;
F_9 ( V_6 -> V_7 ) ;
F_9 ( V_6 -> V_8 ) ;
F_9 ( V_6 -> V_9 ) ;
F_9 ( V_6 ) ;
}
static void
F_10 ( const T_2 * V_3 , const T_5 * V_10 )
{
char * V_11 ;
if ( ! V_3 || ! V_10 )
return;
V_11 = F_11 ( V_3 ) ;
if ( ! F_2 ( V_12 , V_11 ) ) {
T_4 * V_13 = ( T_4 * ) F_12 ( T_4 , 1 ) ;
V_13 -> V_9 = F_7 ( V_10 -> V_9 ) ;
V_13 -> V_8 = F_7 ( V_3 ) ;
V_13 -> V_7 = F_7 ( V_11 ) ;
F_6 ( V_12 , F_7 ( V_11 ) , V_13 ) ;
}
F_9 ( V_11 ) ;
}
static void F_13 ( T_6 V_14 , T_2 * * args , T_7 V_15 ,
void * V_16 , char * * V_17 , const char * V_1 V_18 ) {
const char * V_19 = F_14 () ;
T_8 * V_20 ;
const T_2 * V_21 ;
T_1 V_22 ;
V_22 = TRUE ;
if ( ( V_20 = F_15 ( V_19 , 0 , NULL ) ) != NULL ) {
T_9 * V_23 = NULL ;
V_23 = F_16 ( L_1 ) ;
while ( V_22 && ( V_21 = F_17 ( V_20 ) ) != NULL ) {
T_2 * V_24 = NULL ;
#ifdef F_18
F_19 ( V_23 , L_2 , V_19 , V_21 ) ;
#else
F_19 ( V_23 , L_3 , V_19 , V_21 ) ;
#endif
if ( F_1 ( V_1 ) && ! F_3 ( V_1 , V_23 -> V_25 ) )
continue;
if ( F_20 ( ( T_2 * ) V_19 , V_23 -> V_25 , V_14 , args , & V_24 ) )
V_22 = V_15 ( V_23 -> V_25 , V_1 , V_24 , V_16 , V_17 ) ;
F_9 ( V_24 ) ;
}
F_21 ( V_20 ) ;
F_22 ( V_23 , TRUE ) ;
}
}
static T_1 F_23 ( const T_2 * V_3 V_18 , const T_2 * V_1 V_18 , T_2 * V_26 , void * V_5 ,
char * * V_17 ) {
T_10 * V_27 ;
T_11 * V_28 , * V_29 , * V_30 ;
T_12 * V_31 ;
T_13 * V_32 = NULL ;
T_14 * V_33 ;
V_27 = F_24 ( V_26 ) ;
F_25 ( V_27 , & V_28 ) ;
F_26 ( V_27 ) ;
F_27 ( V_34 , V_35 , L_4 , V_3 ) ;
V_31 = ( T_12 * ) F_28 ( sizeof *V_31 ) ;
V_31 -> V_36 = FALSE ;
V_29 = V_28 ;
while ( V_29 != NULL ) {
F_27 ( V_34 , V_35 ,
L_5 , V_29 -> V_37 ,
V_29 -> V_38 , V_29 -> V_39 ) ;
V_33 = F_29 ( T_14 , 1 ) ;
V_33 -> V_40 = V_29 -> V_37 ;
V_33 -> V_38 = F_7 ( V_29 -> V_38 ) ;
V_33 -> V_41 = F_7 ( V_29 -> V_39 ) ;
V_32 = F_30 ( V_32 , V_33 ) ;
V_29 = V_29 -> V_42 ;
}
if ( V_32 != NULL && V_5 != NULL ) {
V_31 -> V_43 = V_32 ;
* ( T_12 * * ) V_5 = V_31 ;
} else {
if ( V_17 ) {
F_27 ( V_34 , V_35 , L_6 ) ;
* V_17 = F_7 ( L_7 ) ;
}
F_9 ( V_31 ) ;
}
V_29 = V_28 ;
while ( V_29 != NULL ) {
V_30 = V_29 -> V_42 ;
F_31 ( V_29 ) ;
V_29 = V_30 ;
}
return FALSE ;
}
T_12 *
F_32 ( const T_2 * V_1 , char * * V_17 ) {
T_2 * V_44 [ 3 ] ;
T_6 V_45 ;
T_12 * V_31 = NULL ;
if ( V_17 != NULL )
* V_17 = NULL ;
if ( F_1 ( V_1 ) )
{
V_44 [ 0 ] = F_7 ( V_46 ) ;
V_44 [ 1 ] = F_7 ( V_47 ) ;
V_44 [ 2 ] = F_7 ( V_1 ) ;
F_13 ( 3 , V_44 , F_23 , & V_31 , V_17 , V_1 ) ;
for ( V_45 = 0 ; V_45 < 3 ; ++ V_45 )
F_9 ( V_44 [ V_45 ] ) ;
}
return V_31 ;
}
static T_1 F_33 ( const T_2 * V_3 , const T_2 * V_1 V_18 , T_2 * V_26 , void * V_5 ,
char * * V_17 V_18 ) {
T_13 * * V_48 = ( T_13 * * ) V_5 ;
T_10 * V_27 ;
T_5 * V_49 , * V_50 ;
T_15 * V_51 ;
V_27 = F_24 ( V_26 ) ;
F_34 ( V_27 , & V_49 ) ;
F_26 ( V_27 ) ;
F_27 ( V_34 , V_35 , L_4 , V_3 ) ;
V_50 = V_49 ;
while ( V_50 != NULL ) {
if ( V_50 -> V_52 == V_53 && F_1 ( V_50 -> V_54 ) )
{
F_27 ( V_34 , V_55 , L_8 ,
V_50 -> V_54 , ( T_2 * ) F_4 ( V_50 -> V_54 ) ) ;
V_50 = V_50 -> V_56 ;
continue;
}
if ( V_50 -> V_52 == V_53 )
F_27 ( V_34 , V_35 , L_9 ,
V_50 -> V_54 , V_50 -> V_39 ) ;
else if ( V_50 -> V_52 == V_57 )
F_27 ( V_34 , V_35 , L_10 , V_50 -> V_54 ) ;
if ( V_50 -> V_52 == V_53 ) {
if ( V_48 != NULL ) {
V_51 = F_12 ( T_15 , 1 ) ;
V_51 -> V_38 = F_7 ( V_50 -> V_54 ) ;
V_51 -> V_58 = F_7 ( V_50 -> V_39 ) ;
V_51 -> type = V_59 ;
V_51 -> V_3 = F_7 ( V_3 ) ;
* V_48 = F_30 ( * V_48 , V_51 ) ;
}
F_5 ( V_50 -> V_54 , V_3 ) ;
}
F_10 ( V_3 , V_50 ) ;
V_50 = V_50 -> V_56 ;
}
F_35 ( V_49 ) ;
return TRUE ;
}
static T_6
F_36 ( T_16 V_60 , T_16 V_61 )
{
T_6 V_62 = 0 ;
const T_15 * V_63 = ( const T_15 * ) V_60 ;
const T_15 * V_64 = ( const T_15 * ) V_61 ;
if ( ( V_62 = F_37 ( V_63 -> V_38 , V_64 -> V_38 ) ) == 0 )
return F_37 ( V_63 -> V_58 , V_64 -> V_58 ) ;
return V_62 ;
}
static void
F_38 ( T_13 * * V_65 , char * * V_17 ) {
T_2 * V_44 ;
if ( V_17 != NULL )
* V_17 = NULL ;
if ( V_2 == NULL )
V_2 = F_39 ( V_66 , V_67 , F_9 , F_9 ) ;
else
F_40 ( V_2 ) ;
if ( V_12 == NULL )
V_12 = F_39 ( V_66 , V_67 , F_9 , F_8 ) ;
else
F_40 ( V_12 ) ;
V_44 = F_7 ( V_68 ) ;
F_13 ( 1 , & V_44 , F_33 , V_65 , V_17 , NULL ) ;
F_9 ( V_44 ) ;
}
T_17 *
F_41 ( void ) {
if ( V_12 == NULL || F_42 ( V_12 ) == 0 )
F_38 ( NULL , NULL ) ;
return V_12 ;
}
T_13 *
F_43 ( T_13 * V_69 , char * * V_17 ) {
T_13 * V_70 = NULL ;
T_13 * V_4 ;
void * V_5 ;
F_38 ( & V_70 , V_17 ) ;
V_70 = F_44 ( V_70 , F_36 ) ;
while ( V_70 != NULL ) {
V_4 = F_45 ( V_70 ) ;
V_5 = V_4 -> V_5 ;
V_70 = F_46 ( V_70 , V_4 ) ;
V_69 = F_30 ( V_69 , V_5 ) ;
}
return V_69 ;
}
static void F_47 ( T_3 V_5 , T_3 T_18 V_18 ) {
F_48 ( ( V_71 * ) V_5 ) ;
F_9 ( V_5 ) ;
}
void F_49 ( void )
{
T_13 * V_49 = NULL ;
T_19 * V_72 = F_50 ( L_11 ) ;
if ( ! V_72 )
return;
if ( ! V_2 || F_42 ( V_2 ) == 0 )
F_38 ( NULL , NULL ) ;
V_49 = F_51 ( V_2 ) ;
while ( V_49 ) {
F_52 ( ( T_2 * ) V_49 -> V_5 ) ;
V_49 = F_53 ( V_49 ) ;
}
}
void F_54 ( void )
{
if ( V_73 ) {
F_55 ( V_73 ) ;
}
}
void F_56 ( V_71 * V_74 , const char * V_75 )
{
if ( V_74 && V_74 -> V_76 != NULL )
{
memset ( V_74 -> V_76 , 0 , V_77 * sizeof( char ) ) ;
if ( V_75 )
F_57 ( V_74 -> V_76 , V_77 , L_12 , V_75 ) ;
}
}
static T_2 * F_58 ( const char * V_38 )
{
T_2 * V_78 ;
if ( ! V_73 ) {
V_73 = F_39 ( V_66 , V_67 ,
F_9 , F_9 ) ;
}
V_78 = ( T_2 * ) F_2 ( V_73 , V_38 ) ;
if ( ! V_78 ) {
V_78 = F_12 ( T_2 , V_77 ) ;
F_6 ( V_73 , F_7 ( V_38 ) , V_78 ) ;
}
return V_78 ;
}
static void F_59 ( T_13 * V_69 )
{
T_13 * V_79 , * V_80 ;
for ( V_79 = F_45 ( V_69 ) ; V_79 ; V_79 = V_79 -> V_30 )
{
if ( V_79 -> V_5 != NULL ) {
V_80 = F_45 ( ( T_13 * ) V_79 -> V_5 ) ;
F_60 ( V_80 , ( V_81 ) F_47 , NULL ) ;
F_61 ( V_80 ) ;
}
}
F_61 ( V_69 ) ;
}
struct V_82 *
F_62 ( const T_2 * V_1 , struct V_83 * V_74 ) {
struct V_82 * V_84 = NULL ;
T_20 * V_85 = F_63 ( L_13 , ( V_86 ) 0 , ( V_87 ) 0 , NULL ) ;
T_20 * V_88 = F_63 ( L_14 , ( V_86 ) 0 , ( V_87 ) 0 , NULL ) ;
if ( V_85 && V_88 ) {
if ( F_50 ( L_11 ) ) {
T_2 * V_89 = F_64 ( V_85 , V_74 -> V_54 , strlen ( V_74 -> V_54 ) , 0 , L_1 , ( V_87 ) 0 , NULL ) ;
T_2 * V_90 = F_64 ( V_88 , V_1 , strlen ( V_1 ) , 0 , L_15 , ( V_87 ) 0 , NULL ) ;
T_2 * V_91 = F_65 ( V_90 , - 1 ) ;
T_2 * V_92 = F_66 ( V_91 , L_16 , V_89 , NULL ) ;
V_84 = F_67 ( F_50 ( L_11 ) , V_92 ) ;
F_9 ( V_89 ) ;
F_9 ( V_90 ) ;
F_9 ( V_91 ) ;
F_9 ( V_92 ) ;
}
}
if ( V_85 ) {
F_68 ( V_85 ) ;
}
if ( V_88 ) {
F_68 ( V_88 ) ;
}
return V_84 ;
}
static T_1 F_69 ( const T_2 * V_3 V_18 , const T_2 * V_1 V_18 , T_2 * V_26 , void * V_5 ,
char * * V_17 V_18 ) {
T_10 * V_27 = NULL ;
T_13 * V_93 = NULL ;
T_13 * * V_48 = ( T_13 * * ) V_5 ;
T_19 * V_72 = NULL ;
V_27 = F_24 ( V_26 ) ;
V_93 = F_70 ( V_27 ) ;
F_26 ( V_27 ) ;
#if V_94
F_71 ( V_93 ) ;
#endif
V_72 = F_50 ( L_11 ) ;
if ( V_72 ) {
T_13 * V_95 = V_93 ;
T_20 * V_85 = F_63 ( L_13 , ( V_86 ) 0 , ( V_87 ) 0 , NULL ) ;
T_20 * V_88 = F_63 ( L_14 , ( V_86 ) 0 , ( V_87 ) 0 , NULL ) ;
if ( V_85 && V_88 ) {
while ( V_95 != NULL ) {
V_71 * V_74 = ( V_71 * ) V_95 -> V_5 ;
V_74 -> V_96 = F_7 ( V_1 ) ;
if ( V_74 -> V_97 ) {
struct V_82 * V_84 = NULL ;
T_2 * V_89 = F_64 ( V_85 , V_74 -> V_54 , strlen ( V_74 -> V_54 ) , 0 , L_1 , ( V_87 ) 0 , NULL ) ;
T_2 * V_90 = F_64 ( V_88 , V_1 , strlen ( V_1 ) , 0 , L_15 , ( V_87 ) 0 , NULL ) ;
T_2 * V_91 = F_65 ( V_90 , - 1 ) ;
T_2 * V_92 = F_66 ( V_91 , L_16 , V_89 , NULL ) ;
if ( ( V_84 = F_67 ( V_72 , V_92 ) ) == NULL ) {
if ( ! V_74 -> V_76 && V_74 -> V_98 )
{
V_74 -> V_76 = F_58 ( V_92 ) ;
F_57 ( V_74 -> V_76 , V_77 , L_12 , V_74 -> V_98 -> V_99 ) ;
}
F_72 ( V_72 , F_7 ( V_92 ) ,
V_74 -> V_39 , V_74 -> V_39 , ( const T_2 * * ) & ( V_74 -> V_76 ) ) ;
} else {
if ( ! V_74 -> V_76 && V_84 -> V_100 . string )
{
V_74 -> V_76 = F_58 ( V_92 ) ;
F_57 ( V_74 -> V_76 , V_77 , L_12 , * ( V_84 -> V_100 . string ) ) ;
}
}
F_9 ( V_89 ) ;
F_9 ( V_90 ) ;
F_9 ( V_91 ) ;
F_9 ( V_92 ) ;
}
V_95 = F_53 ( V_95 ) ;
}
}
if ( V_85 ) {
F_68 ( V_85 ) ;
}
if ( V_88 ) {
F_68 ( V_88 ) ;
}
}
* V_48 = F_30 ( * V_48 , V_93 ) ;
return TRUE ;
}
T_13 *
F_52 ( const char * V_1 ) {
T_2 * V_44 [ 3 ] ;
T_13 * V_70 = NULL ;
T_2 * * V_17 = NULL ;
int V_45 ;
if ( F_1 ( V_1 ) )
{
F_27 ( V_34 , V_35 , L_17 ,
F_14 () ) ;
V_44 [ 0 ] = F_7 ( V_101 ) ;
V_44 [ 1 ] = F_7 ( V_47 ) ;
V_44 [ 2 ] = F_7 ( V_1 ) ;
F_13 ( 3 , V_44 , F_69 , & V_70 , V_17 , V_1 ) ;
for ( V_45 = 0 ; V_45 < 3 ; V_45 ++ )
F_9 ( V_44 [ V_45 ] ) ;
}
return V_70 ;
}
T_1
F_73 ( const char * V_1 , T_1 V_102 ) {
T_13 * V_93 = 0 ;
T_13 * V_95 = 0 , * V_103 = 0 ;
T_1 V_104 = FALSE ;
V_93 = F_52 ( ( const char * ) ( V_1 ) ) ;
V_95 = F_45 ( V_93 ) ;
while ( V_95 != NULL && ! V_104 ) {
V_103 = F_45 ( ( T_13 * ) ( V_95 -> V_5 ) ) ;
while ( V_103 != NULL && ! V_104 ) {
if ( ( V_71 * ) ( V_103 -> V_5 ) != NULL ) {
V_71 * V_74 = ( V_71 * ) ( V_103 -> V_5 ) ;
if ( ! V_102 )
V_104 = TRUE ;
else if ( V_74 -> V_102 ) {
T_2 * V_105 = NULL ;
T_2 * V_106 = NULL ;
if ( V_74 -> V_76 != NULL )
V_105 = V_74 -> V_76 ;
if ( V_74 -> V_98 != NULL && V_74 -> V_98 -> V_99 != NULL )
V_106 = V_74 -> V_98 -> V_99 ;
if ( V_74 -> V_102 ) {
if ( V_106 && V_105 && F_37 ( V_105 , V_106 ) == 0 )
V_104 = TRUE ;
else if ( ! V_106 && ( ! V_105 || strlen ( F_74 ( V_105 ) ) <= ( V_107 ) 0 ) )
V_104 = TRUE ;
}
if ( V_74 -> V_108 == V_109 ) {
if ( V_74 -> V_110 && ! ( F_75 ( V_106 ) || F_75 ( V_105 ) ) )
V_104 = TRUE ;
}
}
}
V_103 = V_103 -> V_30 ;
}
V_95 = V_95 -> V_30 ;
}
F_59 ( V_93 ) ;
return V_104 ;
}
static T_1 F_76 ( int V_111 ) {
#ifdef F_18
T_21 V_112 = ( T_21 ) F_77 ( V_111 ) ;
T_22 V_113 ;
if ( V_112 == V_114 )
return FALSE ;
if ( ! F_78 ( V_112 , NULL , 0 , NULL , & V_113 , NULL ) )
return FALSE ;
if ( V_113 > 0 )
return TRUE ;
return FALSE ;
#else
T_23 V_115 ;
struct V_116 V_117 ;
F_79 ( & V_115 ) ;
F_80 ( V_111 , & V_115 ) ;
V_117 . V_118 = 0 ;
V_117 . V_119 = 0 ;
if ( F_81 ( V_111 + 1 , & V_115 , NULL , NULL , & V_117 ) > 0 )
return TRUE ;
return FALSE ;
#endif
}
void F_82 ( T_24 * V_120 , T_2 * * V_121 ) {
T_25 V_122 ;
T_26 * V_123 ;
T_27 V_124 = 0 ;
T_1 V_125 ;
T_2 * V_126 ;
#define F_83 1024
for ( V_124 = 0 ; V_124 < V_120 -> V_2 -> V_127 ; V_124 ++ ) {
V_122 = F_84 ( V_120 -> V_2 , T_25 ,
V_124 ) ;
if ( V_122 . V_52 != V_59 )
continue;
V_125 = FALSE ;
F_27 ( V_34 , V_35 ,
L_18 , V_122 . V_38 ,
V_122 . V_128 , V_122 . V_129 ) ;
#ifdef F_18
if ( V_130 )
{
F_27 ( V_34 , V_35 ,
L_19 , V_122 . V_38 ) ;
F_85 ( V_130 ) ;
F_86 ( V_130 ) ;
F_87 ( V_130 ) ;
}
#else
if ( V_122 . V_128 != NULL && F_75 ( V_122 . V_128 ) )
{
F_88 ( V_122 . V_128 ) ;
V_122 . V_128 = NULL ;
}
#endif
F_27 ( V_34 , V_35 ,
L_20 , V_122 . V_38 ,
V_122 . V_129 ) ;
V_123 = ( T_26 * ) V_122 . T_26 ;
if ( V_123 )
{
if ( V_123 -> V_131 > 0 && F_76 ( V_123 -> V_131 ) )
{
V_126 = ( T_2 * ) F_89 ( sizeof( T_2 ) * F_83 + 1 ) ;
#ifdef F_18
F_90 ( ( T_21 ) F_77 ( V_123 -> V_131 ) , F_83 , V_126 ) ;
#else
if ( F_91 ( V_123 -> V_131 , V_126 , sizeof( T_2 ) * F_83 ) <= 0 )
V_126 [ 0 ] = '\0' ;
#endif
if ( strlen ( V_126 ) > 0 )
{
V_123 -> V_132 = F_92 ( L_12 , V_126 ) ;
V_123 -> V_133 = 1 ;
}
F_9 ( V_126 ) ;
}
#ifndef F_18
if ( V_122 . V_134 != 0 )
{
F_93 ( V_123 -> V_135 , 0 , V_120 ) ;
V_122 = F_84 ( V_120 -> V_2 , T_25 ,
V_124 ) ;
}
#endif
if ( V_123 -> V_132 != NULL )
V_125 = TRUE ;
if ( V_125 || V_123 -> V_133 != 0 )
{
if ( V_123 -> V_132 != 0 )
{
if ( * V_121 == NULL )
* V_121 = F_92 ( L_21 , V_123 -> V_132 ) ;
else
{
T_2 * V_136 = F_66 ( * V_121 , L_22 , V_123 -> V_132 , NULL ) ;
F_9 ( * V_121 ) ;
* V_121 = V_136 ;
}
F_9 ( V_123 -> V_132 ) ;
}
V_123 -> V_132 = NULL ;
V_123 -> V_133 = 0 ;
}
}
if ( V_122 . V_134 > 0 )
{
F_94 ( V_122 . V_134 ) ;
V_122 . V_134 = 0 ;
}
if ( V_122 . V_129 != V_137 )
{
#ifdef F_18
F_95 ( V_122 . V_129 , 0 ) ;
#endif
F_96 ( V_122 . V_129 ) ;
V_122 . V_129 = V_137 ;
F_9 ( V_122 . T_26 ) ;
V_122 . T_26 = NULL ;
}
V_120 -> V_2 = F_97 ( V_120 -> V_2 , V_124 ) ;
F_98 ( V_120 -> V_2 , V_124 , V_122 ) ;
}
}
static T_1
F_99 ( T_3 V_138 , T_3 V_139 , T_3 V_5 ) {
T_28 * args = ( T_28 * ) V_5 ;
if ( V_138 != NULL )
{
F_100 ( args , F_7 ( ( const T_2 * ) V_138 ) ) ;
if ( V_139 != NULL )
F_100 ( args , F_7 ( ( const T_2 * ) V_139 ) ) ;
return TRUE ;
}
return FALSE ;
}
void F_93 ( T_29 V_135 , T_6 T_30 V_18 , T_3 T_18 )
{
T_27 V_45 ;
T_25 V_122 ;
T_26 * V_123 = NULL ;
T_24 * V_120 = ( T_24 * ) ( T_18 ) ;
if ( V_120 == NULL || V_120 -> V_2 == NULL || V_120 -> V_2 -> V_127 == 0 )
return;
F_96 ( V_135 ) ;
for ( V_45 = 0 ; V_45 < V_120 -> V_2 -> V_127 ; V_45 ++ )
{
V_122 = F_84 ( V_120 -> V_2 , T_25 , V_45 ) ;
if ( V_122 . V_129 == V_135 )
{
V_123 = ( T_26 * ) V_122 . T_26 ;
if ( V_123 != NULL )
{
V_122 . V_129 = V_137 ;
V_123 -> V_133 = 0 ;
#ifndef F_18
if ( F_101 ( T_30 ) )
{
if ( F_102 ( T_30 ) != 0 )
V_123 -> V_133 = F_102 ( T_30 ) ;
}
else
V_123 -> V_133 = V_140 ;
#else
if ( T_30 != 0 )
V_123 -> V_133 = T_30 ;
#endif
if ( T_30 == 0 && V_123 -> V_132 != NULL )
V_123 -> V_133 = 1 ;
}
F_94 ( V_122 . V_134 ) ;
V_122 . V_134 = 0 ;
V_120 -> V_2 = F_97 ( V_120 -> V_2 , V_45 ) ;
F_98 ( V_120 -> V_2 , V_45 , V_122 ) ;
break;
}
}
}
static
T_28 * F_103 ( T_25 V_122 )
{
T_28 * V_141 = NULL ;
#if V_94
T_2 * * V_142 ;
int V_143 ;
#endif
if ( V_122 . V_52 == V_59 )
{
V_141 = F_104 () ;
#define F_105 ( T_31 ) g_ptr_array_add(result, g_strdup(X))
F_105 ( V_122 . V_3 ) ;
F_105 ( V_144 ) ;
F_105 ( V_47 ) ;
F_105 ( V_122 . V_38 ) ;
if ( V_122 . V_145 && strlen ( V_122 . V_145 ) > 0 ) {
F_105 ( V_146 ) ;
F_105 ( V_122 . V_145 ) ;
}
F_105 ( V_147 ) ;
F_105 ( V_122 . V_128 ) ;
if ( V_122 . V_148 == NULL || F_42 ( V_122 . V_148 ) == 0 )
{
T_13 * V_149 ;
T_13 * V_79 ;
V_149 = F_52 ( V_122 . V_38 ) ;
for ( V_79 = F_45 ( V_149 ) ; V_79 ; V_79 = V_79 -> V_30 )
{
T_13 * V_150 ;
V_71 * V_151 ;
if ( V_79 -> V_5 == NULL )
{
continue;
}
V_150 = F_45 ( ( T_13 * ) V_79 -> V_5 ) ;
while ( V_150 != NULL ) {
T_2 * V_105 = NULL , * V_106 = NULL ;
V_151 = ( V_71 * ) ( V_150 -> V_5 ) ;
if ( V_151 -> V_76 != NULL )
V_105 = V_151 -> V_76 ;
if ( V_151 -> V_98 != NULL && V_151 -> V_98 -> V_99 != NULL )
V_106 = V_151 -> V_98 -> V_99 ;
if ( F_37 ( V_105 , V_106 ) != 0 ) {
if ( V_151 -> V_108 == V_152 ) {
if ( F_37 ( V_105 , L_23 ) == 0 )
F_105 ( V_151 -> V_54 ) ;
} else {
T_2 * V_54 = F_66 ( V_151 -> V_54 , L_24 , V_105 , NULL ) ;
F_105 ( V_54 ) ;
F_9 ( V_54 ) ;
}
} else if ( V_151 -> V_108 == V_152 ) {
if ( F_106 ( V_151 -> V_98 ) )
F_105 ( V_151 -> V_54 ) ;
}
V_150 = V_150 -> V_30 ;
}
}
F_59 ( V_149 ) ;
}
else
{
F_107 ( V_122 . V_148 , F_99 , V_141 ) ;
}
F_105 ( NULL ) ;
#undef F_105
#if V_94
for ( V_142 = ( T_2 * * ) V_141 -> V_153 , V_143 = 0 ; * V_142 && * * V_142 ; ++ V_143 , ++ V_142 )
{
F_27 ( V_34 , V_35 , L_25 , V_143 , * V_142 ) ;
}
#endif
}
return V_141 ;
}
T_1
F_108 ( T_24 * V_120 )
{
T_27 V_45 ;
T_25 V_122 ;
T_26 * V_123 ;
for ( V_45 = 0 ; V_45 < V_120 -> V_2 -> V_127 ; V_45 ++ )
{
T_28 * args = NULL ;
T_29 V_135 = V_137 ;
V_122 = F_84 ( V_120 -> V_2 , T_25 , V_45 ) ;
if ( V_122 . V_52 != V_59 )
continue;
if ( ! F_109 ( & V_122 . V_128 ) )
return FALSE ;
args = F_103 ( V_122 ) ;
V_123 = F_12 ( T_26 , 1 ) ;
V_135 = F_110 ( V_123 , args ) ;
F_111 ( args , ( V_81 ) F_9 , NULL ) ;
F_112 ( args , TRUE ) ;
if ( V_135 == V_137 )
{
F_9 ( V_123 ) ;
continue;
}
V_122 . V_129 = V_135 ;
V_122 . V_134 =
F_113 ( V_135 , F_93 , ( T_3 ) V_120 ) ;
#ifdef F_18
if ( V_135 != V_137 )
{
F_114 ( V_130 , V_135 ) ;
}
#endif
V_122 . T_26 = ( T_3 ) V_123 ;
V_120 -> V_2 = F_97 ( V_120 -> V_2 , V_45 ) ;
F_98 ( V_120 -> V_2 , V_45 , V_122 ) ;
}
return TRUE ;
}
T_21
F_115 ()
{
return V_130 ;
}
T_1 F_109 ( char * * V_154 )
{
#ifdef F_18
T_2 V_155 [ 14 + 1 ] ;
T_32 V_156 ;
T_2 * V_157 = NULL ;
T_33 V_158 ;
V_156 = time ( NULL ) ;
strftime ( V_155 , sizeof( V_155 ) , L_26 , localtime ( & V_156 ) ) ;
V_157 = F_66 ( L_27 , V_159 , L_15 , V_155 , NULL ) ;
memset ( & V_158 , 0 , sizeof( T_33 ) ) ;
V_158 . V_160 = sizeof( T_33 ) ;
V_158 . V_161 = TRUE ;
V_158 . V_162 = NULL ;
V_130 = F_116 (
F_117 ( V_157 ) ,
V_163 | V_164 ,
V_165 | V_166 | V_167 ,
5 , 65536 , 65536 ,
300 ,
& V_158 ) ;
if ( V_130 == V_114 )
{
F_27 ( V_34 , V_35 , L_28 , F_118 () ) ;
return FALSE ;
}
else
{
F_27 ( V_34 , V_35 , L_29 , V_157 ) ;
* V_154 = F_7 ( V_157 ) ;
}
#else
T_2 * V_168 = NULL ;
int V_169 = 0 ;
if ( ( V_169 = F_119 ( & V_168 , V_159 , NULL ) ) < 0 )
return FALSE ;
F_120 ( V_169 ) ;
F_27 ( V_34 , V_35 ,
L_30 , V_168 ) ;
if ( F_75 ( V_168 ) )
F_88 ( V_168 ) ;
if ( F_121 ( V_168 , 0600 ) == 0 )
* V_154 = F_7 ( V_168 ) ;
#endif
return TRUE ;
}
void F_71 ( V_71 * V_151 )
{
T_34 * V_170 = NULL ;
T_13 * V_95 = NULL ;
printf ( L_31 ) ;
while ( V_151 != NULL ) {
printf ( L_32 , V_151 -> V_171 , V_151 -> V_54 , V_151 -> V_39 ) ;
switch ( V_151 -> V_108 ) {
case V_172 :
printf ( L_33 ) ;
break;
case V_173 :
printf ( L_34 ) ;
break;
case V_174 :
printf ( L_35 ) ;
break;
case V_175 :
printf ( L_36 ) ;
break;
case V_176 :
printf ( L_37 ) ;
break;
case V_177 :
printf ( L_38 ) ;
break;
case V_178 :
printf ( L_39 ) ;
break;
case V_179 :
printf ( L_40 ) ;
break;
case V_180 :
printf ( L_41 ) ;
break;
case V_181 :
printf ( L_42 ) ;
break;
case V_182 :
printf ( L_43 ) ;
break;
case V_183 :
printf ( L_43 ) ;
break;
}
if ( V_151 -> V_184 != NULL && V_151 -> V_185 != NULL ) {
printf ( L_44 ) ;
F_122 ( V_151 -> V_184 ) ;
printf ( L_45 ) ;
F_122 ( V_151 -> V_185 ) ;
printf ( L_46 ) ;
}
for ( V_95 = F_45 ( V_151 -> V_186 ) ; V_95 ; V_95 = V_95 -> V_30 )
{
V_170 = ( T_34 * ) V_95 -> V_5 ;
if ( V_170 -> V_187 )
printf ( L_47 ) ;
printf ( L_48 , V_170 -> V_54 , V_170 -> V_39 ) ;
printf ( L_49 , V_170 -> V_54 , V_170 -> V_39 ) ;
}
V_151 = V_151 -> V_188 ;
}
}
