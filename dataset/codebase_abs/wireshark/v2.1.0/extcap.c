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
T_6 V_23 ;
T_2 * * V_24 ;
#ifdef F_15
T_2 * * V_25 ;
T_2 * V_26 ;
#endif
V_22 = TRUE ;
V_24 = ( T_2 * * ) F_16 ( sizeof( T_2 * ) * ( V_14 + 2 ) ) ;
#ifdef F_15
V_25 = F_17 () ;
V_26 = F_18 ( L_1 , F_19 () , F_20 ( V_25 , L_2 ) ) ;
V_25 = F_21 ( V_25 , L_2 , V_26 , TRUE ) ;
F_9 ( V_26 ) ;
#endif
if ( ( V_20 = F_22 ( V_19 , 0 , NULL ) ) != NULL ) {
T_9 * V_27 = NULL ;
V_27 = F_23 ( L_3 ) ;
while ( V_22 && ( V_21 = F_24 ( V_20 ) ) != NULL ) {
T_2 * V_28 = NULL ;
T_1 V_29 = FALSE ;
T_6 V_30 = 0 ;
T_2 * * V_31 = NULL ;
#ifdef F_15
F_25 ( V_27 , L_4 , V_19 , V_21 ) ;
V_31 = V_25 ;
#else
F_25 ( V_27 , L_5 , V_19 , V_21 ) ;
#endif
if ( F_1 ( V_1 ) && ! F_3 ( V_1 , V_27 -> V_32 ) )
continue;
#ifdef F_15
V_24 [ 0 ] = F_26 ( V_27 -> V_32 , NULL ) ;
#else
V_24 [ 0 ] = F_7 ( V_27 -> V_32 ) ;
#endif
for ( V_23 = 0 ; V_23 < V_14 ; ++ V_23 )
V_24 [ V_23 + 1 ] = args [ V_23 ] ;
V_24 [ V_14 + 1 ] = NULL ;
V_29 = F_27 ( V_19 , V_24 , V_31 ,
( V_33 ) 0 , NULL , NULL ,
& V_28 , NULL , & V_30 , NULL ) ;
if ( V_29 && V_30 == 0 )
V_22 = V_15 ( V_27 -> V_32 , V_1 , V_28 , V_16 , V_17 ) ;
F_9 ( V_24 [ 0 ] ) ;
F_9 ( V_28 ) ;
}
F_28 ( V_20 ) ;
F_29 ( V_27 , TRUE ) ;
}
#ifdef F_15
F_30 ( V_25 ) ;
#endif
F_9 ( V_24 ) ;
}
static T_1 F_31 ( const T_2 * V_3 V_18 , const T_2 * V_1 V_18 , T_2 * V_34 , void * V_5 ,
char * * V_17 ) {
T_10 * V_35 ;
T_11 * V_36 , * V_37 , * V_38 ;
T_12 * V_39 ;
T_13 * V_40 = NULL ;
T_14 * V_41 ;
V_35 = F_32 ( V_34 ) ;
F_33 ( V_35 , & V_36 ) ;
F_34 ( V_35 ) ;
F_35 ( V_42 , V_43 , L_6 , V_3 ) ;
V_39 = ( T_12 * ) F_36 ( sizeof *V_39 ) ;
V_39 -> V_44 = FALSE ;
V_37 = V_36 ;
while ( V_37 != NULL ) {
F_35 ( V_42 , V_43 ,
L_7 , V_37 -> V_45 ,
V_37 -> V_46 , V_37 -> V_47 ) ;
V_41 = F_37 ( T_14 , 1 ) ;
V_41 -> V_48 = V_37 -> V_45 ;
V_41 -> V_46 = F_7 ( V_37 -> V_46 ) ;
V_41 -> V_49 = F_7 ( V_37 -> V_47 ) ;
V_40 = F_38 ( V_40 , V_41 ) ;
V_37 = V_37 -> V_50 ;
}
if ( V_40 != NULL && V_5 != NULL ) {
V_39 -> V_51 = V_40 ;
* ( T_12 * * ) V_5 = V_39 ;
} else {
if ( V_17 ) {
F_35 ( V_42 , V_43 , L_8 ) ;
* V_17 = F_7 ( L_9 ) ;
}
F_9 ( V_39 ) ;
}
V_37 = V_36 ;
while ( V_37 != NULL ) {
V_38 = V_37 -> V_50 ;
F_39 ( V_37 ) ;
V_37 = V_38 ;
}
return FALSE ;
}
T_12 *
F_40 ( const T_2 * V_1 , char * * V_17 ) {
T_2 * V_24 [ 3 ] ;
T_6 V_23 ;
T_12 * V_39 = NULL ;
if ( V_17 != NULL )
* V_17 = NULL ;
if ( F_1 ( V_1 ) )
{
V_24 [ 0 ] = F_7 ( V_52 ) ;
V_24 [ 1 ] = F_7 ( V_53 ) ;
V_24 [ 2 ] = F_7 ( V_1 ) ;
F_13 ( 3 , V_24 , F_31 , & V_39 , V_17 , V_1 ) ;
for ( V_23 = 0 ; V_23 < 3 ; ++ V_23 )
F_9 ( V_24 [ V_23 ] ) ;
}
return V_39 ;
}
static T_1 F_41 ( const T_2 * V_3 , const T_2 * V_1 V_18 , T_2 * V_34 , void * V_5 ,
char * * V_17 V_18 ) {
T_13 * * V_54 = ( T_13 * * ) V_5 ;
T_10 * V_35 ;
T_5 * V_55 , * V_56 ;
T_15 * V_57 ;
V_35 = F_32 ( V_34 ) ;
F_42 ( V_35 , & V_55 ) ;
F_34 ( V_35 ) ;
F_35 ( V_42 , V_43 , L_6 , V_3 ) ;
V_56 = V_55 ;
while ( V_56 != NULL ) {
if ( V_56 -> V_58 == V_59 && F_1 ( V_56 -> V_60 ) )
{
F_35 ( V_42 , V_61 , L_10 ,
V_56 -> V_60 , ( T_2 * ) F_4 ( V_56 -> V_60 ) ) ;
V_56 = V_56 -> V_62 ;
continue;
}
if ( V_56 -> V_58 == V_59 )
F_35 ( V_42 , V_43 , L_11 ,
V_56 -> V_60 , V_56 -> V_47 ) ;
else if ( V_56 -> V_58 == V_63 )
F_35 ( V_42 , V_43 , L_12 , V_56 -> V_60 ) ;
if ( V_56 -> V_58 == V_59 ) {
if ( V_54 != NULL ) {
V_57 = F_12 ( T_15 , 1 ) ;
V_57 -> V_46 = F_7 ( V_56 -> V_60 ) ;
V_57 -> V_64 = F_7 ( V_56 -> V_47 ) ;
V_57 -> type = V_65 ;
V_57 -> V_3 = F_7 ( V_3 ) ;
* V_54 = F_38 ( * V_54 , V_57 ) ;
}
F_5 ( V_56 -> V_60 , V_3 ) ;
}
F_10 ( V_3 , V_56 ) ;
V_56 = V_56 -> V_62 ;
}
F_43 ( V_55 ) ;
return TRUE ;
}
static T_6
F_44 ( T_16 V_66 , T_16 V_67 )
{
T_6 V_68 = 0 ;
const T_15 * V_69 = ( const T_15 * ) V_66 ;
const T_15 * V_70 = ( const T_15 * ) V_67 ;
if ( ( V_68 = F_45 ( V_69 -> V_46 , V_70 -> V_46 ) ) == 0 )
return F_45 ( V_69 -> V_64 , V_70 -> V_64 ) ;
return V_68 ;
}
static void
F_46 ( T_13 * * V_71 , char * * V_17 ) {
T_2 * V_24 ;
if ( V_17 != NULL )
* V_17 = NULL ;
if ( V_2 == NULL )
V_2 = F_47 ( V_72 , V_73 , F_9 , F_9 ) ;
else
F_48 ( V_2 ) ;
if ( V_12 == NULL )
V_12 = F_47 ( V_72 , V_73 , F_9 , F_8 ) ;
else
F_48 ( V_12 ) ;
V_24 = F_7 ( V_74 ) ;
F_13 ( 1 , & V_24 , F_41 , V_71 , V_17 , NULL ) ;
F_9 ( V_24 ) ;
}
T_17 *
F_49 ( void ) {
if ( V_12 == NULL || F_50 ( V_12 ) == 0 )
F_46 ( NULL , NULL ) ;
return V_12 ;
}
T_13 *
F_51 ( T_13 * V_75 , char * * V_17 ) {
T_13 * V_76 = NULL ;
T_13 * V_4 ;
void * V_5 ;
F_46 ( & V_76 , V_17 ) ;
V_76 = F_52 ( V_76 , F_44 ) ;
while ( V_76 != NULL ) {
V_4 = F_53 ( V_76 ) ;
V_5 = V_4 -> V_5 ;
V_76 = F_54 ( V_76 , V_4 ) ;
V_75 = F_38 ( V_75 , V_5 ) ;
}
return V_75 ;
}
static void F_55 ( T_3 V_5 , T_3 T_18 V_18 ) {
F_56 ( ( V_77 * ) V_5 ) ;
F_9 ( V_5 ) ;
}
void F_57 ( void )
{
T_13 * V_55 = NULL ;
T_19 * V_78 = F_58 ( L_13 ) ;
if ( ! V_78 )
return;
if ( ! V_2 || F_50 ( V_2 ) == 0 )
F_46 ( NULL , NULL ) ;
V_55 = F_59 ( V_2 ) ;
while ( V_55 ) {
F_60 ( ( T_2 * ) V_55 -> V_5 ) ;
V_55 = F_61 ( V_55 ) ;
}
}
static void F_62 ( T_13 * V_75 )
{
T_13 * V_79 , * V_80 ;
for ( V_79 = F_53 ( V_75 ) ; V_79 ; V_79 = V_79 -> V_38 )
{
if ( V_79 -> V_5 != NULL ) {
V_80 = F_53 ( ( T_13 * ) V_79 -> V_5 ) ;
F_63 ( V_80 , ( V_81 ) F_55 , NULL ) ;
F_64 ( V_80 ) ;
}
}
F_64 ( V_75 ) ;
}
T_2 * F_65 ( const T_2 * V_1 , const T_2 * V_82 )
{
T_2 * V_83 ;
T_2 * V_84 ;
T_2 * V_85 ;
T_2 * V_86 ;
T_20 * V_87 = F_66 ( L_14 , ( V_88 ) 0 , ( V_89 ) 0 , NULL ) ;
if ( ! V_87 )
return NULL ;
V_83 =
F_67 ( V_87 , V_82 , strlen ( V_82 ) , 0 ,
L_3 , ( V_89 ) 0 , NULL ) ;
V_84 =
F_67 ( V_87 , V_1 , strlen ( V_1 ) , 0 ,
L_15 , ( V_89 ) 0 , NULL ) ;
V_85 = F_68 ( V_84 , - 1 ) ;
V_86 = F_69 ( V_85 , L_16 , V_83 , NULL ) ;
F_9 ( V_83 ) ;
F_9 ( V_84 ) ;
F_9 ( V_85 ) ;
F_70 ( V_87 ) ;
return V_86 ;
}
static T_1 F_71 ( const T_2 * V_3 V_18 , const T_2 * V_1 V_18 , T_2 * V_34 , void * V_5 ,
char * * V_17 V_18 ) {
T_10 * V_35 = NULL ;
T_13 * V_90 = NULL ;
T_13 * * V_54 = ( T_13 * * ) V_5 ;
T_19 * V_78 = NULL ;
V_35 = F_32 ( V_34 ) ;
V_90 = F_72 ( V_35 ) ;
F_34 ( V_35 ) ;
#if V_91
F_73 ( V_90 ) ;
#endif
V_78 = F_58 ( L_13 ) ;
if ( V_78 ) {
T_13 * V_92 = V_90 ;
while ( V_92 != NULL ) {
V_77 * V_93 = ( V_77 * ) V_92 -> V_5 ;
if ( V_93 -> V_94 ) {
struct V_95 * V_96 = NULL ;
T_2 * V_97 = F_65 ( V_1 , V_93 -> V_60 ) ;
if ( ( V_96 = F_74 ( V_78 , V_97 ) ) == NULL ) {
if ( ! V_93 -> V_98 && V_93 -> V_99 )
V_93 -> V_98 = F_7 ( V_93 -> V_99 -> V_100 ) ;
F_75 ( V_78 , F_7 ( V_97 ) ,
V_93 -> V_47 , V_93 -> V_47 , ( const T_2 * * ) ( void * ) ( & V_93 -> V_98 ) ) ;
} else {
if ( ! V_93 -> V_98 && V_96 -> V_101 . string )
V_93 -> V_98 = F_7 ( * ( V_96 -> V_101 . string ) ) ;
}
F_9 ( V_97 ) ;
}
V_92 = F_61 ( V_92 ) ;
}
}
* V_54 = F_38 ( * V_54 , V_90 ) ;
return TRUE ;
}
T_13 *
F_60 ( const char * V_1 ) {
T_2 * V_24 [ 3 ] ;
T_13 * V_76 = NULL ;
T_2 * * V_17 = NULL ;
int V_23 ;
if ( F_1 ( V_1 ) )
{
F_35 ( V_42 , V_43 , L_17 ,
F_14 () ) ;
V_24 [ 0 ] = F_7 ( V_102 ) ;
V_24 [ 1 ] = F_7 ( V_53 ) ;
V_24 [ 2 ] = F_7 ( V_1 ) ;
F_13 ( 3 , V_24 , F_71 , & V_76 , V_17 , V_1 ) ;
for ( V_23 = 0 ; V_23 < 3 ; V_23 ++ )
F_9 ( V_24 [ V_23 ] ) ;
}
return V_76 ;
}
T_1
F_76 ( const char * V_1 , T_1 V_103 ) {
T_13 * V_90 = 0 ;
T_13 * V_92 = 0 , * V_104 = 0 ;
T_1 V_105 = FALSE ;
V_90 = F_60 ( ( const char * ) ( V_1 ) ) ;
V_92 = F_53 ( V_90 ) ;
while ( V_92 != NULL && ! V_105 ) {
V_104 = F_53 ( ( T_13 * ) ( V_92 -> V_5 ) ) ;
while ( V_104 != NULL && ! V_105 ) {
if ( ( V_77 * ) ( V_104 -> V_5 ) != NULL ) {
V_77 * V_93 = ( V_77 * ) ( V_104 -> V_5 ) ;
if ( ! V_103 )
V_105 = TRUE ;
else if ( V_93 -> V_103 ) {
T_2 * V_106 = NULL ;
T_2 * V_107 = NULL ;
if ( V_93 -> V_98 != NULL )
V_106 = V_93 -> V_98 ;
if ( V_93 -> V_99 != NULL && V_93 -> V_99 -> V_100 != NULL )
V_107 = V_93 -> V_99 -> V_100 ;
if ( V_93 -> V_103 ) {
if ( V_107 && V_106 && F_45 ( V_106 , V_107 ) == 0 )
V_105 = TRUE ;
else if ( ! V_107 && ( ! V_106 || strlen ( F_77 ( V_106 ) ) <= ( V_108 ) 0 ) )
V_105 = TRUE ;
}
if ( V_93 -> V_109 == V_110 ) {
if ( V_93 -> V_111 && ! ( F_78 ( V_107 ) || F_78 ( V_106 ) ) )
V_105 = TRUE ;
}
}
}
V_104 = V_104 -> V_38 ;
}
V_92 = V_92 -> V_38 ;
}
F_62 ( V_90 ) ;
return V_105 ;
}
void F_79 ( T_21 * V_112 ) {
T_22 V_113 ;
T_23 V_114 = 0 ;
for ( V_114 = 0 ; V_114 < V_112 -> V_2 -> V_115 ; V_114 ++ ) {
V_113 = F_80 ( V_112 -> V_2 , T_22 ,
V_114 ) ;
if ( V_113 . V_58 != V_65 )
continue;
F_35 ( V_42 , V_43 ,
L_18 , V_113 . V_46 ,
V_113 . V_116 , V_113 . V_117 ) ;
#ifdef F_15
if ( V_118 )
{
F_35 ( V_42 , V_43 ,
L_19 , V_113 . V_46 ) ;
F_81 ( V_118 ) ;
F_82 ( V_118 ) ;
F_83 ( V_118 ) ;
}
#else
if ( V_113 . V_116 != NULL && F_78 ( V_113 . V_116 ) )
{
F_84 ( V_113 . V_116 ) ;
V_113 . V_116 = NULL ;
}
#endif
F_35 ( V_42 , V_43 ,
L_20 , V_113 . V_46 ,
V_113 . V_117 ) ;
if ( V_113 . V_117 != V_119 )
{
#ifdef F_15
F_85 ( V_113 . V_117 , 0 ) ;
#endif
F_86 ( V_113 . V_117 ) ;
V_113 . V_117 = V_119 ;
}
V_112 -> V_2 = F_87 ( V_112 -> V_2 , V_114 ) ;
F_88 ( V_112 -> V_2 , V_114 , V_113 ) ;
}
}
static T_1
F_89 ( T_3 V_86 , T_3 V_120 , T_3 V_5 ) {
T_24 * args = ( T_24 * ) V_5 ;
if ( V_86 != NULL )
{
F_90 ( args , F_7 ( ( const T_2 * ) V_86 ) ) ;
if ( V_120 != NULL )
F_90 ( args , F_7 ( ( const T_2 * ) V_120 ) ) ;
return TRUE ;
}
return FALSE ;
}
static void F_91 ( T_25 V_121 , T_6 V_29 V_18 , T_3 T_18 )
{
T_23 V_23 ;
T_22 V_113 ;
T_21 * V_112 = ( T_21 * ) T_18 ;
F_86 ( V_121 ) ;
for ( V_23 = 0 ; V_23 < V_112 -> V_2 -> V_115 ; V_23 ++ )
{
V_113 = F_80 ( V_112 -> V_2 , T_22 , V_23 ) ;
if ( V_113 . V_117 == V_121 )
{
V_113 . V_117 = V_119 ;
F_92 ( V_113 . V_122 ) ;
V_113 . V_122 = 0 ;
V_112 -> V_2 = F_87 ( V_112 -> V_2 , V_23 ) ;
F_88 ( V_112 -> V_2 , V_23 , V_113 ) ;
break;
}
}
}
T_1
F_93 ( T_21 * V_112 )
{
T_23 V_23 ;
T_22 V_113 ;
for ( V_23 = 0 ; V_23 < V_112 -> V_2 -> V_115 ; V_23 ++ )
{
T_24 * args = NULL ;
T_25 V_121 = V_119 ;
T_2 * * V_123 ;
int V_124 ;
V_113 = F_80 ( V_112 -> V_2 , T_22 , V_23 ) ;
if ( V_113 . V_58 != V_65 )
continue;
if ( ! F_94 ( & V_113 . V_116 ) )
return FALSE ;
args = F_95 () ;
#define F_96 ( T_26 ) g_ptr_array_add(args, g_strdup(X))
F_96 ( V_113 . V_3 ) ;
F_96 ( V_125 ) ;
F_96 ( V_53 ) ;
F_96 ( V_113 . V_46 ) ;
if ( V_113 . V_126 && strlen ( V_113 . V_126 ) > 0 ) {
F_96 ( V_127 ) ;
F_96 ( V_113 . V_126 ) ;
}
F_96 ( V_128 ) ;
F_96 ( V_113 . V_116 ) ;
if ( V_113 . V_129 == NULL || F_50 ( V_113 . V_129 ) == 0 )
{
T_13 * V_130 ;
T_13 * V_79 ;
V_130 = F_60 ( V_113 . V_46 ) ;
for ( V_79 = F_53 ( V_130 ) ; V_79 ; V_79 = V_79 -> V_38 )
{
T_13 * V_131 ;
V_77 * V_132 ;
if ( V_79 -> V_5 == NULL )
{
continue;
}
V_131 = F_53 ( ( T_13 * ) V_79 -> V_5 ) ;
while ( V_131 != NULL ) {
T_2 * V_106 = NULL , * V_107 = NULL ;
V_132 = ( V_77 * ) ( V_131 -> V_5 ) ;
if ( V_132 -> V_98 != NULL )
V_106 = V_132 -> V_98 ;
if ( V_132 -> V_99 != NULL && V_132 -> V_99 -> V_100 != NULL )
V_107 = V_132 -> V_99 -> V_100 ;
if ( F_45 ( V_106 , V_107 ) != 0 ) {
if ( V_132 -> V_109 == V_133 ) {
if ( F_45 ( V_106 , L_21 ) == 0 )
F_96 ( V_132 -> V_60 ) ;
} else {
T_2 * V_60 = F_69 ( V_132 -> V_60 , L_22 , V_106 , NULL ) ;
F_96 ( V_60 ) ;
F_9 ( V_60 ) ;
}
} else if ( V_132 -> V_109 == V_133 ) {
if ( F_97 ( V_132 -> V_99 ) )
F_96 ( V_132 -> V_60 ) ;
}
V_131 = V_131 -> V_38 ;
}
}
F_62 ( V_130 ) ;
}
else
{
F_98 ( V_113 . V_129 , F_89 , args ) ;
}
F_96 ( NULL ) ;
#undef F_96
for ( V_123 = ( T_2 * * ) args -> V_134 , V_124 = 0 ; * V_123 && * * V_123 ; ++ V_124 , ++ V_123 )
{
F_35 ( V_42 , V_43 , L_23 , V_124 , * V_123 ) ;
}
F_99 ( NULL , ( T_2 * * ) args -> V_134 , NULL ,
( V_33 ) V_135 , NULL , NULL ,
& V_121 , NULL ) ;
F_100 ( args , ( V_81 ) F_9 , NULL ) ;
F_101 ( args , TRUE ) ;
V_113 . V_117 = V_121 ;
V_113 . V_122 =
F_102 ( V_121 , F_91 , ( T_3 ) V_112 ) ;
V_112 -> V_2 = F_87 ( V_112 -> V_2 , V_23 ) ;
F_88 ( V_112 -> V_2 , V_23 , V_113 ) ;
#ifdef F_15
if ( V_121 != V_119 )
{
T_27 V_136 ;
T_28 V_137 [ 2 ] ;
T_29 V_138 ;
V_138 . V_139 = 0 ;
V_138 . V_140 = F_103 ( NULL , TRUE , FALSE , NULL ) ;
F_104 ( V_118 , & V_138 ) ;
V_137 [ 0 ] = V_138 . V_140 ;
V_137 [ 1 ] = V_121 ;
if ( F_105 () == V_141 )
{
F_35 ( V_42 , V_43 , L_24 ) ;
}
else
{
V_136 = F_106 ( 2 , V_137 , FALSE , 30000 ) ;
if ( V_136 == V_142 )
{
T_27 V_143 ;
V_143 = F_105 () ;
if ( V_143 == V_144 )
{
T_27 V_145 ;
if ( ! F_107 ( V_138 . V_140 , & V_138 , & V_145 , TRUE ) )
{
V_143 = F_105 () ;
}
else
{
V_143 = V_146 ;
}
}
F_35 ( V_42 , V_43 , L_25 , V_143 ) ;
}
else if ( V_136 == ( V_142 + 1 ) )
{
F_35 ( V_42 , V_43 , L_26 ) ;
}
else if ( V_136 == V_147 )
{
F_35 ( V_42 , V_43 , L_27 ) ;
}
else
{
F_35 ( V_42 , V_43 , L_28 , V_136 , F_105 () ) ;
}
}
F_83 ( V_138 . V_140 ) ;
}
#endif
}
return TRUE ;
}
T_28
F_108 ()
{
return V_118 ;
}
T_1 F_94 ( char * * V_148 )
{
#ifdef F_15
T_2 V_149 [ 14 + 1 ] ;
T_30 V_150 ;
T_2 * V_151 = NULL ;
T_31 V_152 ;
V_150 = time ( NULL ) ;
strftime ( V_149 , sizeof( V_149 ) , L_29 , localtime ( & V_150 ) ) ;
V_151 = F_69 ( L_30 , V_153 , L_15 , V_149 , NULL ) ;
memset ( & V_152 , 0 , sizeof( T_31 ) ) ;
V_152 . V_154 = sizeof( T_31 ) ;
V_152 . V_155 = TRUE ;
V_152 . V_156 = NULL ;
V_118 = F_109 (
F_110 ( V_151 ) ,
V_157 | V_158 ,
V_159 | V_160 | V_161 ,
5 , 65536 , 65536 ,
300 ,
& V_152 ) ;
if ( V_118 == V_162 )
{
F_35 ( V_42 , V_43 , L_31 , F_105 () ) ;
return FALSE ;
}
else
{
F_35 ( V_42 , V_43 , L_32 , V_151 ) ;
* V_148 = F_7 ( V_151 ) ;
}
#else
T_2 * V_163 = NULL ;
int V_164 = 0 ;
if ( ( V_164 = F_111 ( & V_163 , V_153 , NULL ) ) < 0 )
return FALSE ;
F_112 ( V_164 ) ;
F_35 ( V_42 , V_43 ,
L_33 , V_163 ) ;
if ( F_78 ( V_163 ) )
F_84 ( V_163 ) ;
if ( F_113 ( V_163 , 0600 ) == 0 )
* V_148 = F_7 ( V_163 ) ;
#endif
return TRUE ;
}
void F_73 ( V_77 * V_132 )
{
T_32 * V_165 = NULL ;
T_13 * V_92 = NULL ;
printf ( L_34 ) ;
while ( V_132 != NULL ) {
printf ( L_35 , V_132 -> V_166 , V_132 -> V_60 , V_132 -> V_47 ) ;
switch ( V_132 -> V_109 ) {
case V_167 :
printf ( L_36 ) ;
break;
case V_168 :
printf ( L_37 ) ;
break;
case V_169 :
printf ( L_38 ) ;
break;
case V_170 :
printf ( L_39 ) ;
break;
case V_171 :
printf ( L_40 ) ;
break;
case V_172 :
printf ( L_41 ) ;
break;
case V_173 :
printf ( L_42 ) ;
break;
case V_174 :
printf ( L_43 ) ;
break;
case V_175 :
printf ( L_44 ) ;
break;
case V_176 :
printf ( L_45 ) ;
break;
case V_177 :
printf ( L_46 ) ;
break;
case V_178 :
printf ( L_46 ) ;
break;
}
if ( V_132 -> V_179 != NULL && V_132 -> V_180 != NULL ) {
printf ( L_47 ) ;
F_114 ( V_132 -> V_179 ) ;
printf ( L_48 ) ;
F_114 ( V_132 -> V_180 ) ;
printf ( L_49 ) ;
}
for ( V_92 = F_53 ( V_132 -> V_181 ) ; V_92 ; V_92 = V_92 -> V_38 )
{
V_165 = ( T_32 * ) V_92 -> V_5 ;
if ( V_165 -> V_182 )
printf ( L_50 ) ;
printf ( L_51 , V_165 -> V_60 , V_165 -> V_47 ) ;
printf ( L_52 , V_165 -> V_60 , V_165 -> V_47 ) ;
}
V_132 = V_132 -> V_183 ;
}
}
