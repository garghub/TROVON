static T_1
F_1 ( const char * V_1 )
{
if ( V_1 != NULL )
{
if ( V_2 != NULL )
{
if ( F_2 ( V_2 ) > 0 )
{
if ( F_3 ( V_2 , ( const V_3 * ) V_1 ) != NULL )
{
return TRUE ;
}
}
}
}
return FALSE ;
}
static T_1
F_4 ( const char * V_1 , const char * V_4 )
{
V_3 * V_5 = NULL ;
if ( F_1 ( V_1 ) )
{
if ( ( V_5 = ( V_3 * ) F_3 ( V_2 , ( const V_3 * ) V_1 ) ) != NULL )
{
if ( strcmp ( V_5 , V_4 ) == 0 )
return TRUE ;
}
}
return FALSE ;
}
static V_3 *
F_5 ( const char * V_1 )
{
if ( F_1 ( V_1 ) )
return ( V_3 * ) F_3 ( V_2 , ( const V_3 * ) V_1 ) ;
return ( V_3 * ) NULL ;
}
static void
F_6 ( void )
{
if ( V_2 == NULL )
V_2 = F_7 ( V_6 , V_7 ) ;
F_8 ( V_2 ) ;
}
static void
F_9 ( V_3 * V_1 , V_3 * V_4 )
{
if ( F_3 ( V_2 , V_1 ) == NULL )
F_10 ( V_2 , V_1 , V_4 ) ;
}
static void F_11 ( T_2 V_8 , V_3 * * args , T_3 V_9 ,
void * V_10 , char * * V_11 , const char * V_1 V_12 ) {
const char * V_13 = F_12 () ;
T_4 * V_14 ;
const V_3 * V_15 ;
T_1 V_16 ;
V_3 * * V_17 ;
#ifdef F_13
V_3 * * V_18 ;
V_3 * V_19 ;
#endif
V_16 = TRUE ;
V_17 = ( V_3 * * ) F_14 ( sizeof( V_3 * ) * ( V_8 + 2 ) ) ;
#ifdef F_13
V_18 = F_15 () ;
V_19 = F_16 ( L_1 , F_17 () , F_18 ( V_18 , L_2 ) ) ;
V_18 = F_19 ( V_18 , L_2 , V_19 , TRUE ) ;
F_20 ( V_19 ) ;
#endif
if ( ( V_14 = F_21 ( V_13 , 0 , NULL ) ) != NULL ) {
#ifdef F_13
V_13 = F_22 ( V_13 , NULL ) ;
#endif
while ( V_16 && ( V_15 = F_23 ( V_14 ) ) != NULL ) {
T_5 * V_20 = NULL ;
V_3 * V_4 = NULL ;
V_3 * V_21 = NULL ;
T_1 V_22 = FALSE ;
T_2 V_23 ;
T_2 V_24 = 0 ;
T_6 * error = NULL ;
V_3 * * V_25 = NULL ;
V_20 = F_24 ( L_3 ) ;
#ifdef F_13
F_25 ( V_20 , L_4 , V_13 , V_15 ) ;
V_4 = F_26 ( V_20 , FALSE ) ;
V_25 = V_18 ;
#else
F_25 ( V_20 , L_5 , V_13 , V_15 ) ;
V_4 = F_26 ( V_20 , FALSE ) ;
#endif
if ( F_1 ( V_1 ) && ! F_4 ( V_1 , V_4 ) )
continue;
V_17 [ 0 ] = V_4 ;
for ( V_23 = 0 ; V_23 < V_8 ; ++ V_23 )
V_17 [ V_23 + 1 ] = args [ V_23 ] ;
V_17 [ V_8 + 1 ] = NULL ;
V_22 = F_27 ( V_13 , V_17 , V_25 ,
( V_26 ) 0 , NULL , NULL ,
& V_21 , NULL , & V_24 , & error ) ;
if ( V_22 && V_24 == 0 )
V_16 = V_9 ( V_4 , V_21 , V_10 , V_11 ) ;
F_20 ( V_4 ) ;
F_20 ( V_21 ) ;
}
F_28 ( V_14 ) ;
}
#ifdef F_13
F_29 ( V_18 ) ;
#endif
F_20 ( V_17 ) ;
}
static T_1 F_30 ( const V_3 * V_4 V_12 , V_3 * V_27 , void * V_28 ,
char * * V_11 ) {
T_7 * V_29 ;
T_8 * V_30 , * V_31 , * V_32 ;
T_9 * V_33 ;
T_10 * V_34 = NULL ;
T_11 * V_35 ;
V_29 = F_31 ( V_27 ) ;
F_32 ( V_29 , & V_30 ) ;
F_33 ( V_29 ) ;
F_34 ( V_36 , V_37 , L_6 , V_4 ) ;
V_33 = ( T_9 * ) F_35 ( sizeof *V_33 ) ;
V_33 -> V_38 = FALSE ;
V_31 = V_30 ;
while ( V_31 != NULL ) {
F_34 ( V_36 , V_37 ,
L_7 , V_31 -> V_39 ,
V_31 -> V_40 , V_31 -> V_41 ) ;
V_35 = F_36 ( T_11 , 1 ) ;
V_35 -> V_42 = V_31 -> V_39 ;
V_35 -> V_40 = F_37 ( V_31 -> V_40 ) ;
V_35 -> V_43 = F_37 ( V_31 -> V_41 ) ;
V_34 = F_38 ( V_34 , V_35 ) ;
V_31 = V_31 -> V_44 ;
}
if ( V_34 != NULL && V_28 != NULL ) {
V_33 -> V_45 = V_34 ;
* ( T_9 * * ) V_28 = V_33 ;
} else {
if ( V_11 ) {
F_34 ( V_36 , V_37 , L_8 ) ;
* V_11 = F_37 ( L_9 ) ;
}
F_20 ( V_33 ) ;
}
V_31 = V_30 ;
while ( V_31 != NULL ) {
V_32 = V_31 -> V_44 ;
F_39 ( V_31 ) ;
V_31 = V_32 ;
}
return FALSE ;
}
T_9 *
F_40 ( const V_3 * V_1 , char * * V_11 ) {
V_3 * V_17 [ 3 ] ;
T_2 V_23 ;
T_9 * V_33 = NULL ;
if ( V_1 != NULL && V_11 != NULL )
* V_11 = NULL ;
if ( F_1 ( V_1 ) )
{
V_17 [ 0 ] = F_37 ( V_46 ) ;
V_17 [ 1 ] = F_37 ( V_47 ) ;
V_17 [ 2 ] = F_37 ( V_1 ) ;
if ( V_11 )
* V_11 = NULL ;
F_11 ( 3 , V_17 , F_30 , & V_33 , V_11 , V_1 ) ;
for ( V_23 = 0 ; V_23 < 3 ; ++ V_23 )
F_20 ( V_17 [ V_23 ] ) ;
}
return V_33 ;
}
static T_1 F_41 ( const V_3 * V_4 , V_3 * V_27 , void * V_28 ,
char * * V_11 V_12 ) {
T_10 * * V_48 = ( T_10 * * ) V_28 ;
T_7 * V_29 ;
T_12 * V_49 , * V_50 ;
T_13 * V_51 ;
V_29 = F_31 ( V_27 ) ;
F_42 ( V_29 , & V_49 ) ;
F_33 ( V_29 ) ;
F_34 ( V_36 , V_37 , L_6 , V_4 ) ;
V_50 = V_49 ;
while ( V_50 != NULL ) {
if ( F_1 ( V_50 -> V_52 ) )
{
F_34 ( V_36 , V_53 , L_10 ,
V_50 -> V_52 , ( V_3 * ) F_5 ( V_50 -> V_52 ) ) ;
V_50 = V_50 -> V_54 ;
continue;
}
F_34 ( V_36 , V_37 , L_11 ,
V_50 -> V_52 , V_50 -> V_41 ) ;
V_51 = F_43 ( T_13 , 1 ) ;
V_51 -> V_40 = F_37 ( V_50 -> V_52 ) ;
V_51 -> V_55 = F_37 ( V_50 -> V_41 ) ;
V_51 -> type = V_56 ;
V_51 -> V_4 = F_37 ( V_4 ) ;
* V_48 = F_38 ( * V_48 , V_51 ) ;
F_9 ( F_37 ( V_50 -> V_52 ) , F_37 ( V_4 ) ) ;
V_50 = V_50 -> V_54 ;
}
return TRUE ;
}
T_10 *
F_44 ( char * * V_11 ) {
V_3 * V_17 ;
T_10 * V_57 = NULL ;
if ( V_11 != NULL )
* V_11 = NULL ;
F_6 () ;
V_17 = F_37 ( V_58 ) ;
if ( V_11 )
* V_11 = NULL ;
F_11 ( 1 , & V_17 , F_41 , & V_57 , V_11 , NULL ) ;
F_20 ( V_17 ) ;
return V_57 ;
}
static void F_45 ( T_14 V_28 , T_14 T_15 V_12 )
{
F_20 ( V_28 ) ;
}
static void F_46 ( T_10 * V_59 )
{
T_10 * V_60 ;
for ( V_60 = F_47 ( V_59 ) ; V_60 ; V_60 = V_60 -> V_32 )
{
T_10 * V_61 ;
if ( V_60 -> V_28 == NULL )
{
continue;
}
V_61 = F_47 ( ( T_10 * ) V_60 -> V_28 ) ;
F_48 ( V_61 , F_45 , NULL ) ;
F_49 ( V_61 ) ;
}
F_49 ( V_59 ) ;
}
static T_1 F_50 ( const V_3 * V_4 V_12 , V_3 * V_27 , void * V_28 ,
char * * V_11 V_12 ) {
T_7 * V_29 = NULL ;
T_10 * V_62 = NULL ;
T_10 * * V_48 = ( T_10 * * ) V_28 ;
V_29 = F_31 ( V_27 ) ;
V_62 = F_51 ( V_29 ) ;
F_33 ( V_29 ) ;
#if V_63
F_52 ( V_62 ) ;
#endif
* V_48 = F_38 ( * V_48 , V_62 ) ;
return TRUE ;
}
T_10 *
F_53 ( const char * V_1 ) {
V_3 * V_17 [ 4 ] ;
T_10 * V_57 = NULL ;
V_3 * * V_11 = NULL ;
if ( F_1 ( V_1 ) )
{
F_34 ( V_36 , V_37 , L_12 ,
F_12 () ) ;
V_17 [ 0 ] = F_37 ( V_64 ) ;
V_17 [ 1 ] = F_37 ( V_47 ) ;
V_17 [ 2 ] = F_37 ( V_1 ) ;
V_17 [ 3 ] = NULL ;
F_11 ( 4 , V_17 , F_50 , & V_57 , V_11 , V_1 ) ;
}
return V_57 ;
}
T_1
F_54 ( const char * V_1 ) {
T_10 * V_62 = 0 ;
T_10 * V_65 = 0 , * V_66 = 0 ;
T_1 V_67 = FALSE ;
V_62 = F_53 ( ( const char * ) ( V_1 ) ) ;
V_65 = F_47 ( V_62 ) ;
while ( V_65 != NULL && ! V_67 )
{
V_66 = F_47 ( ( T_10 * ) ( V_65 -> V_28 ) ) ;
while ( V_66 != NULL && ! V_67 )
{
if ( ( V_68 * ) ( V_66 -> V_28 ) != NULL )
V_67 = TRUE ;
V_66 = V_66 -> V_32 ;
}
V_65 = V_65 -> V_32 ;
}
return V_67 ;
}
void F_55 ( T_16 * V_69 ) {
T_17 V_70 ;
T_18 V_71 = 0 ;
for ( V_71 = 0 ; V_71 < V_69 -> V_2 -> V_72 ; V_71 ++ ) {
V_70 = F_56 ( V_69 -> V_2 , T_17 ,
V_71 ) ;
if ( V_70 . V_73 != V_56 )
continue;
F_34 ( V_36 , V_37 ,
L_13 , V_70 . V_40 ,
V_70 . V_74 , V_70 . V_75 ) ;
#ifdef F_13
if ( V_76 )
{
F_34 ( V_36 , V_37 ,
L_14 , V_70 . V_40 ) ;
F_57 ( V_76 ) ;
F_58 ( V_76 ) ;
F_59 ( V_76 ) ;
}
#else
if ( V_70 . V_74 != NULL && F_60 ( V_70 . V_74 ) )
{
F_61 ( V_70 . V_74 ) ;
V_70 . V_74 = NULL ;
}
#endif
F_34 ( V_36 , V_37 ,
L_15 , V_70 . V_40 ,
V_70 . V_75 ) ;
if ( V_70 . V_77 > 0 )
{
F_62 ( V_70 . V_77 ) ;
V_70 . V_77 = 0 ;
}
if ( V_70 . V_75 != V_78 )
{
#ifdef F_13
F_63 ( V_70 . V_75 , 0 ) ;
#endif
F_64 ( V_70 . V_75 ) ;
V_70 . V_75 = V_78 ;
}
V_69 -> V_2 = F_65 ( V_69 -> V_2 , V_71 ) ;
F_66 ( V_69 -> V_2 , V_71 , V_70 ) ;
}
}
static void
F_67 ( T_14 V_79 , T_14 V_80 , T_14 V_28 ) {
T_19 * args = ( T_19 * ) V_28 ;
if ( V_79 != NULL )
{
F_68 ( args , F_37 ( ( const V_3 * ) V_79 ) ) ;
if ( V_80 != NULL )
F_68 ( args , F_37 ( ( const V_3 * ) V_80 ) ) ;
}
}
static void F_69 ( T_20 V_81 , T_2 V_22 V_12 , T_14 T_15 )
{
T_18 V_23 ;
T_17 V_70 ;
T_16 * V_69 = ( T_16 * ) T_15 ;
F_64 ( V_81 ) ;
for ( V_23 = 0 ; V_23 < V_69 -> V_2 -> V_72 ; V_23 ++ )
{
V_70 = F_56 ( V_69 -> V_2 , T_17 , V_23 ) ;
if ( V_70 . V_75 == V_81 )
{
V_70 . V_75 = V_78 ;
V_70 . V_77 = 0 ;
V_69 -> V_2 = F_65 ( V_69 -> V_2 , V_23 ) ;
F_66 ( V_69 -> V_2 , V_23 , V_70 ) ;
break;
}
}
}
T_1
F_70 ( T_16 * V_69 )
{
T_18 V_23 ;
T_17 V_70 ;
for ( V_23 = 0 ; V_23 < V_69 -> V_2 -> V_72 ; V_23 ++ )
{
T_19 * args = NULL ;
T_20 V_81 = V_78 ;
V_3 * * V_82 ;
int V_83 ;
V_70 = F_56 ( V_69 -> V_2 , T_17 , V_23 ) ;
if ( V_70 . V_73 != V_56 )
continue;
if ( ! F_71 ( & V_70 . V_74 ) )
return FALSE ;
args = F_72 () ;
#define F_73 ( T_21 ) g_ptr_array_add(args, g_strdup(X))
F_73 ( V_70 . V_4 ) ;
F_73 ( V_84 ) ;
F_73 ( V_47 ) ;
F_73 ( V_70 . V_40 ) ;
if ( V_70 . V_85 && strlen ( V_70 . V_85 ) > 0 ) {
F_73 ( V_86 ) ;
F_73 ( V_70 . V_85 ) ;
}
F_73 ( V_87 ) ;
F_73 ( V_70 . V_74 ) ;
if ( V_70 . V_88 == NULL )
{
T_10 * V_89 ;
T_10 * V_60 ;
V_89 = F_53 ( V_70 . V_40 ) ;
for ( V_60 = F_47 ( V_89 ) ; V_60 ; V_60 = V_60 -> V_32 )
{
T_10 * V_61 ;
V_68 * V_90 ;
if ( V_60 -> V_28 == NULL )
{
continue;
}
V_61 = F_47 ( ( T_10 * ) V_60 -> V_28 ) ;
while ( V_61 != NULL )
{
V_90 = ( V_68 * ) ( V_61 -> V_28 ) ;
if ( V_90 -> V_91 == V_92 )
{
if ( V_90 -> V_93 != NULL
&& F_74 ( V_90 -> V_93 ) )
{
F_73 ( V_90 -> V_52 ) ;
}
}
V_61 = V_61 -> V_32 ;
}
}
F_46 ( V_89 ) ;
}
else
{
F_75 ( V_70 . V_88 , F_67 , args ) ;
}
F_73 ( NULL ) ;
#undef F_73
for ( V_82 = ( V_3 * * ) args -> V_94 , V_83 = 0 ; * V_82 && * * V_82 ; ++ V_83 , ++ V_82 )
{
F_34 ( V_36 , V_37 , L_16 , V_83 , * V_82 ) ;
}
F_76 ( NULL , ( V_3 * * ) args -> V_94 , NULL ,
( V_26 ) V_95 , NULL , NULL ,
& V_81 , NULL ) ;
F_77 ( args , ( V_96 ) F_20 , NULL ) ;
F_78 ( args , TRUE ) ;
V_70 . V_75 = V_81 ;
V_70 . V_77 =
F_79 ( V_81 , F_69 , ( T_14 ) V_69 ) ;
V_69 -> V_2 = F_65 ( V_69 -> V_2 , V_23 ) ;
F_66 ( V_69 -> V_2 , V_23 , V_70 ) ;
#ifdef F_13
if ( V_81 != V_78 )
{
T_22 V_97 ;
T_23 V_98 [ 2 ] ;
T_24 V_99 ;
V_99 . V_100 = 0 ;
V_99 . V_101 = F_80 ( NULL , TRUE , FALSE , NULL ) ;
F_81 ( V_76 , & V_99 ) ;
V_98 [ 0 ] = V_99 . V_101 ;
V_98 [ 1 ] = V_81 ;
if ( F_82 () == V_102 )
{
F_34 ( V_36 , V_37 , L_17 ) ;
}
else
{
V_97 = F_83 ( 2 , V_98 , FALSE , 30000 ) ;
if ( V_97 == V_103 )
{
T_22 V_104 ;
V_104 = F_82 () ;
if ( V_104 == V_105 )
{
T_22 V_106 ;
if ( ! F_84 ( V_99 . V_101 , & V_99 , & V_106 , TRUE ) )
{
V_104 = F_82 () ;
}
else
{
V_104 = V_107 ;
}
}
F_34 ( V_36 , V_37 , L_18 , V_104 ) ;
}
else if ( V_97 == ( V_103 + 1 ) )
{
F_34 ( V_36 , V_37 , L_19 ) ;
}
else if ( V_97 == V_108 )
{
F_34 ( V_36 , V_37 , L_20 ) ;
}
else
{
F_34 ( V_36 , V_37 , L_21 , V_97 , F_82 () ) ;
}
}
F_59 ( V_99 . V_101 ) ;
}
#endif
}
return TRUE ;
}
T_23
F_85 ()
{
return V_76 ;
}
T_1 F_71 ( char * * V_109 )
{
#ifdef F_13
V_3 V_110 [ 14 + 1 ] ;
T_25 V_111 ;
V_3 * V_112 = NULL ;
T_26 V_113 ;
V_111 = time ( NULL ) ;
strftime ( V_110 , sizeof( V_110 ) , L_22 , localtime ( & V_111 ) ) ;
V_112 = F_86 ( L_23 , V_114 , L_24 , V_110 , NULL ) ;
memset ( & V_113 , 0 , sizeof( T_26 ) ) ;
V_113 . V_115 = sizeof( T_26 ) ;
V_113 . V_116 = TRUE ;
V_113 . V_117 = NULL ;
V_76 = F_87 (
F_88 ( V_112 ) ,
V_118 | V_119 ,
V_120 | V_121 | V_122 ,
5 , 65536 , 65536 ,
300 ,
& V_113 ) ;
if ( V_76 == V_123 )
{
F_34 ( V_36 , V_37 , L_25 , F_82 () ) ;
return FALSE ;
}
else
{
F_34 ( V_36 , V_37 , L_26 , V_112 ) ;
* V_109 = F_37 ( V_112 ) ;
}
#else
V_3 * V_124 = NULL ;
int V_125 = 0 ;
if ( ( V_125 = F_89 ( & V_124 , V_114 ) ) < 0 )
return FALSE ;
F_90 ( V_125 ) ;
F_34 ( V_36 , V_37 ,
L_27 , V_124 ) ;
if ( F_60 ( V_124 ) )
F_61 ( V_124 ) ;
if ( F_91 ( V_124 , 0600 ) == 0 )
* V_109 = F_37 ( V_124 ) ;
#endif
return TRUE ;
}
void F_52 ( V_68 * V_90 )
{
T_27 * V_126 = NULL ;
T_10 * V_65 = NULL ;
printf ( L_28 ) ;
while ( V_90 != NULL ) {
printf ( L_29 , V_90 -> V_127 , V_90 -> V_52 , V_90 -> V_41 ) ;
switch ( V_90 -> V_91 ) {
case V_128 :
printf ( L_30 ) ;
break;
case V_129 :
printf ( L_31 ) ;
break;
case V_130 :
printf ( L_32 ) ;
break;
case V_131 :
printf ( L_33 ) ;
break;
case V_132 :
printf ( L_34 ) ;
break;
case V_133 :
printf ( L_35 ) ;
break;
case V_134 :
printf ( L_36 ) ;
break;
case V_135 :
printf ( L_37 ) ;
break;
case V_136 :
printf ( L_38 ) ;
break;
case V_137 :
printf ( L_39 ) ;
break;
case V_138 :
printf ( L_39 ) ;
break;
}
if ( V_90 -> V_139 != NULL && V_90 -> V_140 != NULL ) {
printf ( L_40 ) ;
F_92 ( V_90 -> V_139 ) ;
printf ( L_41 ) ;
F_92 ( V_90 -> V_140 ) ;
printf ( L_42 ) ;
}
for ( V_65 = F_47 ( V_90 -> V_141 ) ; V_65 ; V_65 = V_65 -> V_32 )
{
V_126 = ( T_27 * ) V_65 -> V_28 ;
if ( V_126 -> V_142 == TRUE )
printf ( L_43 ) ;
printf ( L_44 , V_126 -> V_52 , V_126 -> V_41 ) ;
printf ( L_45 , V_126 -> V_52 , V_126 -> V_41 ) ;
}
V_90 = V_90 -> V_143 ;
}
}
