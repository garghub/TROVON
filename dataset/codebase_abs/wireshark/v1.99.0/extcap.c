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
V_16 = TRUE ;
V_17 = ( V_3 * * ) F_13 ( sizeof( V_3 * ) * ( V_8 + 2 ) ) ;
if ( ( V_14 = F_14 ( V_13 , 0 , NULL ) ) != NULL ) {
#ifdef F_15
V_13 = F_16 ( V_13 , NULL ) ;
#endif
while ( V_16 && ( V_15 = F_17 ( V_14 ) ) != NULL ) {
T_5 * V_18 = NULL ;
V_3 * V_4 = NULL ;
V_3 * V_19 = NULL ;
T_1 V_20 = FALSE ;
T_2 V_21 ;
T_2 V_22 = 0 ;
T_6 * error = NULL ;
V_18 = F_18 ( L_1 ) ;
#ifdef F_15
F_19 ( V_18 , L_2 , V_13 , V_15 ) ;
V_4 = F_20 ( V_18 , FALSE ) ;
#else
F_19 ( V_18 , L_3 , V_13 , V_15 ) ;
V_4 = F_20 ( V_18 , FALSE ) ;
#endif
if ( F_1 ( V_1 ) && ! F_4 ( V_1 , V_4 ) )
continue;
V_17 [ 0 ] = V_4 ;
for ( V_21 = 0 ; V_21 < V_8 ; ++ V_21 )
V_17 [ V_21 + 1 ] = args [ V_21 ] ;
V_17 [ V_8 + 1 ] = NULL ;
V_20 = F_21 ( V_13 , V_17 , NULL ,
( V_23 ) 0 , NULL , NULL ,
& V_19 , NULL , & V_22 , & error ) ;
if ( V_20 && V_22 == 0 )
V_16 = V_9 ( V_4 , V_19 , V_10 , V_11 ) ;
F_22 ( V_4 ) ;
F_22 ( V_19 ) ;
}
F_23 ( V_14 ) ;
}
F_22 ( V_17 ) ;
}
static T_1 F_24 ( const V_3 * V_4 V_12 , V_3 * V_24 , void * V_25 ,
char * * V_11 ) {
T_7 * V_26 ;
T_8 * V_27 , * V_28 , * V_29 ;
T_9 * V_30 ;
T_10 * V_31 = NULL ;
T_11 * V_32 ;
V_26 = F_25 ( V_24 ) ;
F_26 ( V_26 , & V_27 ) ;
F_27 ( V_26 ) ;
F_28 ( V_33 , V_34 , L_4 , V_4 ) ;
V_30 = ( T_9 * ) F_29 ( sizeof *V_30 ) ;
V_30 -> V_35 = FALSE ;
V_28 = V_27 ;
while ( V_28 != NULL ) {
F_28 ( V_33 , V_34 ,
L_5 , V_28 -> V_36 ,
V_28 -> V_37 , V_28 -> V_38 ) ;
V_32 = F_30 ( T_11 , 1 ) ;
V_32 -> V_39 = V_28 -> V_36 ;
V_32 -> V_37 = F_31 ( V_28 -> V_37 ) ;
V_32 -> V_40 = F_31 ( V_28 -> V_38 ) ;
V_31 = F_32 ( V_31 , V_32 ) ;
V_28 = V_28 -> V_41 ;
}
if ( V_31 != NULL && V_25 != NULL ) {
V_30 -> V_42 = V_31 ;
* ( T_9 * * ) V_25 = V_30 ;
} else {
if ( V_11 ) {
F_28 ( V_33 , V_34 , L_6 ) ;
* V_11 = F_31 ( L_7 ) ;
}
F_22 ( V_30 ) ;
}
V_28 = V_27 ;
while ( V_28 != NULL ) {
V_29 = V_28 -> V_41 ;
F_33 ( V_28 ) ;
V_28 = V_29 ;
}
return FALSE ;
}
T_9 *
F_34 ( const V_3 * V_1 , char * * V_11 ) {
V_3 * V_17 [ 3 ] ;
T_2 V_21 ;
T_9 * V_30 = NULL ;
F_28 ( V_33 , V_34 , L_6 ) ;
if ( V_1 != NULL && V_11 != NULL )
* V_11 = NULL ;
if ( F_1 ( V_1 ) )
{
V_17 [ 0 ] = F_31 ( V_43 ) ;
V_17 [ 1 ] = F_31 ( V_44 ) ;
V_17 [ 2 ] = F_31 ( V_1 ) ;
if ( V_11 )
* V_11 = NULL ;
F_11 ( 3 , V_17 , F_24 , & V_30 , V_11 , V_1 ) ;
for ( V_21 = 0 ; V_21 < 3 ; ++ V_21 )
F_22 ( V_17 [ V_21 ] ) ;
}
return V_30 ;
}
static T_1 F_35 ( const V_3 * V_4 , V_3 * V_24 , void * V_25 ,
char * * V_11 V_12 ) {
T_10 * * V_45 = ( T_10 * * ) V_25 ;
T_7 * V_26 ;
T_12 * V_46 , * V_47 ;
T_13 * V_48 ;
V_26 = F_25 ( V_24 ) ;
F_36 ( V_26 , & V_46 ) ;
F_27 ( V_26 ) ;
F_28 ( V_33 , V_34 , L_4 , V_4 ) ;
V_47 = V_46 ;
while ( V_47 != NULL ) {
if ( F_1 ( V_47 -> V_49 ) )
{
F_28 ( V_33 , V_50 , L_8 ,
V_47 -> V_49 , ( V_3 * ) F_5 ( V_47 -> V_49 ) ) ;
V_47 = V_47 -> V_51 ;
continue;
}
F_28 ( V_33 , V_34 , L_9 ,
V_47 -> V_49 , V_47 -> V_38 ) ;
V_48 = F_37 ( T_13 , 1 ) ;
V_48 -> V_37 = F_31 ( V_47 -> V_49 ) ;
V_48 -> V_52 = F_31 ( V_47 -> V_38 ) ;
V_48 -> type = V_53 ;
V_48 -> V_4 = F_31 ( V_4 ) ;
* V_45 = F_32 ( * V_45 , V_48 ) ;
F_9 ( F_31 ( V_47 -> V_49 ) , F_31 ( V_4 ) ) ;
V_47 = V_47 -> V_51 ;
}
return TRUE ;
}
T_10 *
F_38 ( char * * V_11 ) {
V_3 * V_17 ;
T_10 * V_54 = NULL ;
if ( V_11 != NULL )
* V_11 = NULL ;
F_6 () ;
V_17 = F_31 ( V_55 ) ;
if ( V_11 )
* V_11 = NULL ;
F_11 ( 1 , & V_17 , F_35 , & V_54 , V_11 , NULL ) ;
F_22 ( V_17 ) ;
return V_54 ;
}
static T_1 F_39 ( const V_3 * V_4 V_12 , V_3 * V_24 , void * V_25 ,
char * * V_11 V_12 ) {
T_7 * V_26 = NULL ;
T_10 * V_56 = NULL ;
T_10 * * V_45 = ( T_10 * * ) V_25 ;
V_26 = F_25 ( V_24 ) ;
V_56 = F_40 ( V_26 ) ;
F_27 ( V_26 ) ;
#if V_57
F_41 ( V_56 ) ;
#endif
* V_45 = F_32 ( * V_45 , V_56 ) ;
return TRUE ;
}
T_10 *
F_42 ( const char * V_1 ) {
V_3 * V_17 [ 4 ] ;
T_10 * V_54 = NULL ;
V_3 * * V_11 = NULL ;
if ( F_1 ( V_1 ) )
{
F_28 ( V_33 , V_34 , L_10 ,
F_12 () ) ;
if ( V_11 != NULL )
* V_11 = NULL ;
V_17 [ 0 ] = F_31 ( V_58 ) ;
V_17 [ 1 ] = F_31 ( V_44 ) ;
V_17 [ 2 ] = F_31 ( V_1 ) ;
V_17 [ 3 ] = NULL ;
F_11 ( 4 , V_17 , F_39 , & V_54 , V_11 , V_1 ) ;
}
return V_54 ;
}
void F_43 ( T_14 * V_59 ) {
T_15 V_60 ;
T_16 V_61 = 0 ;
for ( V_61 = 0 ; V_61 < V_59 -> V_2 -> V_62 ; V_61 ++ ) {
V_60 = F_44 ( V_59 -> V_2 , T_15 ,
V_61 ) ;
if ( V_60 . V_63 != V_53 )
continue;
F_28 ( V_33 , V_34 ,
L_11 , V_60 . V_37 ,
V_60 . V_64 , V_60 . V_65 ) ;
#ifdef F_15
if ( V_66 )
{
F_28 ( V_33 , V_34 ,
L_12 , V_60 . V_37 ) ;
F_45 ( V_66 ) ;
F_46 ( V_66 ) ;
F_47 ( V_66 ) ;
}
#else
if ( V_60 . V_64 != NULL && F_48 ( V_60 . V_64 ) )
{
F_49 ( V_60 . V_64 ) ;
V_60 . V_64 = NULL ;
}
#endif
F_28 ( V_33 , V_34 ,
L_13 , V_60 . V_37 ,
V_60 . V_65 ) ;
if ( V_60 . V_67 > 0 )
{
F_50 ( V_60 . V_67 ) ;
V_60 . V_67 = 0 ;
}
if ( V_60 . V_65 != V_68 )
{
#ifdef F_15
F_51 ( V_60 . V_65 , 0 ) ;
#endif
F_52 ( V_60 . V_65 ) ;
V_60 . V_65 = V_68 ;
}
V_59 -> V_2 = F_53 ( V_59 -> V_2 , V_61 ) ;
F_54 ( V_59 -> V_2 , V_61 , V_60 ) ;
}
}
static void
F_55 ( T_17 V_69 , T_17 V_70 , T_17 V_25 ) {
T_18 * args = ( T_18 * ) V_25 ;
if ( V_69 != NULL )
{
F_56 ( args , V_69 ) ;
if ( V_70 != NULL )
F_56 ( args , V_70 ) ;
}
}
static void F_57 ( T_19 V_71 , T_2 V_20 V_12 , T_17 V_72 )
{
T_16 V_21 ;
T_15 V_60 ;
T_14 * V_59 = ( T_14 * ) V_72 ;
F_52 ( V_71 ) ;
for ( V_21 = 0 ; V_21 < V_59 -> V_2 -> V_62 ; V_21 ++ )
{
V_60 = F_44 ( V_59 -> V_2 , T_15 , V_21 ) ;
if ( V_60 . V_65 == V_71 )
{
V_60 . V_65 = V_68 ;
V_60 . V_67 = 0 ;
V_59 -> V_2 = F_53 ( V_59 -> V_2 , V_21 ) ;
F_54 ( V_59 -> V_2 , V_21 , V_60 ) ;
break;
}
}
}
T_1
F_58 ( T_14 * V_59 )
{
T_16 V_21 ;
T_15 V_60 ;
for ( V_21 = 0 ; V_21 < V_59 -> V_2 -> V_62 ; V_21 ++ )
{
T_18 * args = NULL ;
T_19 V_71 = V_68 ;
V_3 * * V_73 ;
int V_74 ;
V_60 = F_44 ( V_59 -> V_2 , T_15 , V_21 ) ;
if ( V_60 . V_63 != V_53 )
continue;
if ( ! F_59 ( & V_60 . V_64 ) )
return FALSE ;
args = F_60 () ;
#define F_61 ( T_20 ) g_ptr_array_add(args, g_strdup(X))
F_61 ( V_60 . V_4 ) ;
F_61 ( V_75 ) ;
F_61 ( V_44 ) ;
F_61 ( V_60 . V_37 ) ;
F_61 ( V_76 ) ;
F_61 ( V_60 . V_64 ) ;
if ( V_60 . V_77 != NULL )
F_62 ( V_60 . V_77 , F_55 , args ) ;
F_61 ( NULL ) ;
#undef F_61
for ( V_73 = ( V_3 * * ) args -> V_78 , V_74 = 0 ; * V_73 && * * V_73 ; ++ V_74 , ++ V_73 )
{
F_28 ( V_33 , V_34 , L_14 , V_74 , * V_73 ) ;
}
F_63 ( NULL , ( V_3 * * ) args -> V_78 , NULL ,
( V_23 ) V_79 , NULL , NULL ,
& V_71 , NULL ) ;
F_64 ( args , ( V_80 ) F_22 , NULL ) ;
F_65 ( args , TRUE ) ;
V_60 . V_65 = V_71 ;
V_60 . V_67 =
F_66 ( V_71 , F_57 , ( T_17 ) V_59 ) ;
V_59 -> V_2 = F_53 ( V_59 -> V_2 , V_21 ) ;
F_54 ( V_59 -> V_2 , V_21 , V_60 ) ;
#ifdef F_15
if ( V_71 != V_68 )
{
T_21 V_81 ;
T_22 V_82 [ 2 ] ;
T_23 V_83 ;
V_83 . V_84 = 0 ;
V_83 . V_85 = F_67 ( NULL , TRUE , FALSE , NULL ) ;
F_68 ( V_66 , & V_83 ) ;
V_82 [ 0 ] = V_83 . V_85 ;
V_82 [ 1 ] = V_71 ;
if ( F_69 () == V_86 )
{
F_28 ( V_33 , V_34 , L_15 ) ;
}
else
{
V_81 = F_70 ( 2 , V_82 , FALSE , 30000 ) ;
if ( V_81 == V_87 )
{
T_21 V_88 ;
V_88 = F_69 () ;
if ( V_88 == V_89 )
{
T_21 V_90 ;
if ( ! F_71 ( V_83 . V_85 , & V_83 , & V_90 , TRUE ) )
{
V_88 = F_69 () ;
}
else
{
V_88 = V_91 ;
}
}
F_28 ( V_33 , V_34 , L_16 , V_88 ) ;
}
else if ( V_81 == ( V_87 + 1 ) )
{
F_28 ( V_33 , V_34 , L_17 ) ;
}
else if ( V_81 == V_92 )
{
F_28 ( V_33 , V_34 , L_18 ) ;
}
else
{
F_28 ( V_33 , V_34 , L_19 , V_81 , F_69 () ) ;
}
}
F_47 ( V_83 . V_85 ) ;
}
#endif
}
return TRUE ;
}
T_22
F_72 ()
{
return V_66 ;
}
T_1 F_59 ( char * * V_93 )
{
#ifdef F_15
V_3 V_94 [ 14 + 1 ] ;
T_24 V_95 ;
V_3 * V_96 = NULL ;
T_25 V_97 ;
V_95 = time ( NULL ) ;
strftime ( V_94 , sizeof( V_94 ) , L_20 , localtime ( & V_95 ) ) ;
V_96 = F_73 ( L_21 , V_98 , L_22 , V_94 , NULL ) ;
memset ( & V_97 , 0 , sizeof( T_25 ) ) ;
V_97 . V_99 = sizeof( T_25 ) ;
V_97 . V_100 = TRUE ;
V_97 . V_101 = NULL ;
V_66 = F_74 (
F_75 ( V_96 ) ,
V_102 | V_103 ,
V_104 | V_105 | V_106 ,
5 , 65536 , 65536 ,
300 ,
& V_97 ) ;
if ( V_66 == V_107 )
{
F_28 ( V_33 , V_34 , L_23 , F_69 () ) ;
return FALSE ;
}
else
{
F_28 ( V_33 , V_34 , L_24 , V_96 ) ;
* V_93 = F_31 ( V_96 ) ;
}
#else
V_3 * V_108 = NULL ;
int V_109 = 0 ;
if ( ( V_109 = F_76 ( & V_108 , V_98 ) ) == 0 )
return FALSE ;
F_77 ( V_109 ) ;
F_28 ( V_33 , V_34 ,
L_25 , V_108 ) ;
if ( F_48 ( V_108 ) )
F_49 ( V_108 ) ;
if ( F_78 ( V_108 , 0600 ) == 0 )
* V_93 = F_31 ( V_108 ) ;
#endif
return TRUE ;
}
void F_41 ( T_26 * V_110 )
{
T_27 * V_111 = NULL ;
T_10 * V_112 = NULL ;
printf ( L_26 ) ;
while ( V_110 != NULL ) {
printf ( L_27 , V_110 -> V_113 , V_110 -> V_49 , V_110 -> V_38 ) ;
switch ( V_110 -> V_114 ) {
case V_115 :
printf ( L_28 ) ;
break;
case V_116 :
printf ( L_29 ) ;
break;
case V_117 :
printf ( L_30 ) ;
break;
case V_118 :
printf ( L_31 ) ;
break;
case V_119 :
printf ( L_32 ) ;
break;
case V_120 :
printf ( L_33 ) ;
break;
case V_121 :
printf ( L_34 ) ;
break;
case V_122 :
printf ( L_35 ) ;
break;
case V_123 :
printf ( L_36 ) ;
break;
case V_124 :
printf ( L_37 ) ;
break;
case V_125 :
printf ( L_37 ) ;
break;
}
if ( V_110 -> V_126 != NULL && V_110 -> V_127 != NULL ) {
printf ( L_38 ) ;
F_79 ( V_110 -> V_126 ) ;
printf ( L_39 ) ;
F_79 ( V_110 -> V_127 ) ;
printf ( L_40 ) ;
}
for ( V_112 = F_80 ( V_110 -> V_128 ) ; V_112 ; V_112 = V_112 -> V_29 )
{
V_111 = ( T_27 * ) V_112 -> V_25 ;
if ( V_111 -> V_129 == TRUE )
printf ( L_41 ) ;
printf ( L_42 , V_111 -> V_49 , V_111 -> V_38 ) ;
printf ( L_43 , V_111 -> V_49 , V_111 -> V_38 ) ;
}
V_110 = V_110 -> V_130 ;
}
}
