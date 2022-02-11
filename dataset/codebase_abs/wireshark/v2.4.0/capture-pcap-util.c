static void
F_1 ( T_1 * V_1 , const char * V_2 ,
const char * T_2 V_3 )
{
T_3 V_4 ;
T_4 V_5 ;
T_5 V_6 ;
T_5 V_7 ;
T_6 V_8 ;
T_3 V_9 ;
T_3 V_10 ;
T_3 V_11 ;
V_5 = F_2 () ;
if ( V_5 == NULL ) {
return;
}
V_4 = F_3 ( V_12 ,
V_2 , V_13 ) ;
if ( V_4 == NULL ) {
F_4 ( V_5 ) ;
return;
}
V_6 = F_5 ( V_5 ) ;
for ( V_7 = 0 ; V_7 < V_6 ; V_7 ++ ) {
V_8 = ( T_6 ) F_6 ( V_5 , V_7 ) ;
V_9 = F_7 ( V_8 ) ;
if ( V_9 == NULL ) {
continue;
}
if ( F_8 ( V_4 , V_9 , 0 ) == 0 ) {
V_10 = F_9 ( V_8 ) ;
if ( V_10 != NULL )
V_1 -> V_14 = F_10 ( V_10 ) ;
V_11 = F_11 ( V_8 ) ;
if ( F_8 ( V_11 ,
V_15 , 0 ) == V_16 )
V_1 -> type = V_17 ;
else if ( F_8 ( V_11 ,
V_18 , 0 ) == V_16 )
V_1 -> type = V_19 ;
else if ( F_8 ( V_11 ,
V_20 , 0 ) == V_16 )
V_1 -> type = V_21 ;
else if ( F_8 ( V_11 ,
V_22 , 0 ) == V_16 )
V_1 -> type = V_21 ;
else if ( F_8 ( V_11 ,
V_23 , 0 ) == V_16 )
V_1 -> type = V_21 ;
else
V_1 -> type = V_24 ;
break;
}
}
F_4 ( V_5 ) ;
F_4 ( V_4 ) ;
}
static void
F_1 ( T_1 * V_1 , const char * V_2 ,
const char * T_2 V_3 )
{
char * V_25 ;
T_7 V_26 ;
V_25 = F_12 ( L_1 , V_2 ) ;
if ( V_25 != NULL ) {
if ( F_13 ( V_25 , & V_26 ) == 0 )
V_1 -> type = V_17 ;
F_14 ( V_25 ) ;
}
if ( V_1 -> type == V_24 ) {
if ( strstr ( V_2 , L_2 ) != NULL ) {
V_1 -> type = V_19 ;
} else if ( strstr ( V_2 , L_3 ) != NULL )
V_1 -> type = V_27 ;
}
}
void
F_1 ( T_1 * V_1 , const char * V_2 V_3 ,
const char * T_2 )
{
V_1 -> V_14 = F_15 ( T_2 ) ;
}
T_1 *
F_16 ( const char * V_2 , const char * T_2 , T_8 V_28 )
{
T_1 * V_1 ;
#ifdef F_17
const char * V_29 ;
T_9 V_30 ;
#endif
V_1 = ( T_1 * ) F_18 ( sizeof ( T_1 ) ) ;
V_1 -> V_2 = F_15 ( V_2 ) ;
V_1 -> V_14 = NULL ;
V_1 -> V_31 = NULL ;
V_1 -> type = V_24 ;
#ifdef F_19
V_1 -> V_32 = F_15 ( L_4 ) ;
#endif
#ifdef F_17
if ( T_2 && ( strstr ( T_2 , L_5 ) != NULL ||
strstr ( T_2 , L_6 ) != NULL ) ) {
V_1 -> type = V_21 ;
} else if ( T_2 && ( strstr ( T_2 , L_7 ) != NULL ||
strstr ( T_2 , L_8 ) != NULL ) ) {
V_1 -> type = V_17 ;
} else if ( T_2 && strstr ( T_2 , L_9 ) != NULL ||
strstr ( V_2 , L_10 ) != NULL ) {
V_1 -> type = V_33 ;
} else if ( T_2 && strstr ( T_2 , L_11 ) != NULL ) {
V_1 -> type = V_19 ;
} else if ( T_2 && strstr ( T_2 , L_12 ) != NULL ) {
V_1 -> type = V_34 ;
}
if ( strncmp ( L_13 , V_2 , 12 ) == 0 )
V_29 = V_2 + 12 ;
else
V_29 = V_2 ;
if ( F_20 ( V_29 , & V_30 ) ) {
V_1 -> V_14 = F_21 ( & V_30 ) ;
V_1 -> V_31 = F_15 ( T_2 ) ;
} else {
V_1 -> V_14 = F_15 ( T_2 ) ;
V_1 -> V_31 = NULL ;
}
#else
F_1 ( V_1 , V_2 , T_2 ) ;
if ( V_1 -> type == V_24 ) {
if ( F_22 ( V_2 , L_14 , 5 ) == 0 )
V_1 -> type = V_34 ;
else if ( F_22 ( V_2 , L_15 , 6 ) == 0 )
V_1 -> type = V_34 ;
}
if ( V_1 -> V_14 == NULL ) {
if ( V_28 )
V_1 -> V_14 = F_15 ( L_16 ) ;
}
V_1 -> V_31 = NULL ;
#endif
V_1 -> V_28 = V_28 ;
V_1 -> V_35 = NULL ;
return V_1 ;
}
void
F_23 ( T_1 * V_1 , struct V_36 * V_37 )
{
T_10 * V_38 ;
struct V_39 * V_40 ;
struct V_41 * V_42 ;
switch ( V_37 -> V_43 ) {
case V_44 :
V_40 = (struct V_39 * ) ( void * ) V_37 ;
V_38 = ( T_10 * ) F_18 ( sizeof( * V_38 ) ) ;
V_38 -> V_45 = V_46 ;
V_38 -> V_37 . V_47 =
* ( ( V_48 * ) & ( V_40 -> V_49 . V_50 ) ) ;
V_1 -> V_35 = F_24 ( V_1 -> V_35 , V_38 ) ;
break;
case V_51 :
V_42 = (struct V_41 * ) ( void * ) V_37 ;
V_38 = ( T_10 * ) F_18 ( sizeof( * V_38 ) ) ;
V_38 -> V_45 = V_52 ;
memcpy ( ( void * ) & V_38 -> V_37 . V_53 ,
( void * ) & V_42 -> V_54 . V_55 ,
sizeof V_38 -> V_37 . V_53 ) ;
V_1 -> V_35 = F_24 ( V_1 -> V_35 , V_38 ) ;
break;
}
}
static void
F_25 ( T_1 * V_1 , T_11 * V_56 )
{
T_12 * V_57 ;
for ( V_57 = V_56 -> V_58 ; V_57 != NULL ; V_57 = V_57 -> V_59 ) {
if ( V_57 -> V_37 != NULL )
F_23 ( V_1 , V_57 -> V_37 ) ;
}
if( V_1 -> V_35 ) {
V_1 -> V_35 = F_26 ( V_1 -> V_35 ) ;
}
}
T_13 *
F_27 ( const char * V_60 ,
struct V_61 * V_62 ,
int * V_63 , char * * V_64 )
{
T_13 * V_65 = NULL ;
T_11 * V_66 , * V_67 ;
T_1 * V_1 ;
char V_68 [ V_69 * 4 ] ;
if ( F_28 ( ( char * ) V_60 , V_62 , & V_66 , V_68 ) == - 1 ) {
* V_63 = V_70 ;
if ( V_64 != NULL )
* V_64 = F_29 ( V_68 ) ;
return NULL ;
}
if ( V_66 == NULL ) {
* V_63 = 0 ;
if ( V_64 != NULL )
* V_64 = NULL ;
return NULL ;
}
for ( V_67 = V_66 ; V_67 != NULL ; V_67 = V_67 -> V_59 ) {
V_1 = F_16 ( V_67 -> V_2 , V_67 -> T_2 ,
( V_67 -> V_71 & V_72 ) ? TRUE : FALSE ) ;
V_65 = F_30 ( V_65 , V_1 ) ;
F_25 ( V_1 , V_67 ) ;
}
F_31 ( V_66 ) ;
return V_65 ;
}
T_13 *
F_32 ( int * V_63 , char * * V_64 )
{
T_13 * V_65 = NULL ;
T_11 * V_66 , * V_67 ;
T_1 * V_1 ;
char V_68 [ V_69 ] ;
if ( F_33 ( & V_66 , V_68 ) == - 1 ) {
* V_63 = V_70 ;
if ( V_64 != NULL )
* V_64 = F_29 ( V_68 ) ;
return NULL ;
}
if ( V_66 == NULL ) {
* V_63 = 0 ;
if ( V_64 != NULL )
* V_64 = NULL ;
return NULL ;
}
for ( V_67 = V_66 ; V_67 != NULL ; V_67 = V_67 -> V_59 ) {
V_1 = F_16 ( V_67 -> V_2 , V_67 -> T_2 ,
( V_67 -> V_71 & V_72 ) ? TRUE : FALSE ) ;
V_65 = F_30 ( V_65 , V_1 ) ;
F_25 ( V_1 , V_67 ) ;
}
F_31 ( V_66 ) ;
return V_65 ;
}
static void
F_34 ( T_14 V_37 , T_14 T_15 V_3 )
{
F_14 ( V_37 ) ;
}
static void
F_35 ( T_14 V_73 , T_14 T_15 V_3 )
{
T_1 * V_1 = ( T_1 * ) V_73 ;
F_14 ( V_1 -> V_2 ) ;
F_14 ( V_1 -> V_14 ) ;
F_14 ( V_1 -> V_31 ) ;
#ifdef F_19
F_14 ( V_1 -> V_32 ) ;
#endif
F_36 ( V_1 -> V_35 , F_34 , NULL ) ;
F_37 ( V_1 -> V_35 ) ;
F_14 ( V_1 ) ;
}
void
F_38 ( T_13 * V_74 )
{
F_39 ( V_74 , F_35 , NULL ) ;
F_40 ( V_74 ) ;
}
static int
F_41 ( const char * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_75 [ V_7 ] . V_2 != NULL ; V_7 ++ ) {
if ( F_42 ( V_75 [ V_7 ] . V_2 + sizeof( L_17 ) - 1 ,
V_2 ) == 0 )
return ( V_75 [ V_7 ] . V_76 ) ;
}
return ( - 1 ) ;
}
static const char *
F_43 ( int V_76 )
{
int V_7 ;
for ( V_7 = 0 ; V_75 [ V_7 ] . V_2 != NULL ; V_7 ++ ) {
if ( V_75 [ V_7 ] . V_76 == V_76 )
return ( V_75 [ V_7 ] . V_2 + sizeof( L_17 ) - 1 ) ;
}
return ( NULL ) ;
}
const char *
F_44 ( int V_76 )
{
int V_7 ;
for ( V_7 = 0 ; V_75 [ V_7 ] . V_2 != NULL ; V_7 ++ ) {
if ( V_75 [ V_7 ] . V_76 == V_76 )
return ( V_75 [ V_7 ] . T_2 ) ;
}
return ( NULL ) ;
}
static void
F_45 ( T_14 V_73 , T_14 T_15 V_3 )
{
T_16 * V_77 = ( T_16 * ) V_73 ;
F_14 ( V_77 -> V_2 ) ;
F_14 ( V_77 -> T_2 ) ;
F_14 ( V_77 ) ;
}
void
F_46 ( T_17 * V_78 )
{
F_39 ( V_78 -> V_79 , F_45 , NULL ) ;
F_40 ( V_78 -> V_79 ) ;
F_14 ( V_78 ) ;
}
const char *
F_47 ( int V_76 )
{
return F_43 ( V_76 ) ;
}
int
F_48 ( const char * V_80 )
{
return F_41 ( V_80 ) ;
}
int
F_49 ( T_18 * V_81 , const char * T_19
#ifndef F_50
V_3 )
T_8
F_51 ( T_18 * V_82 , int V_83 , char * V_2 ,
char * V_84 , T_20 V_85 ,
char * V_86 , T_20 V_87 )
{
char * V_88 ;
if ( V_83 == - 1 )
return TRUE ;
#ifdef F_52
if ( F_53 ( V_82 , V_83 ) == 0 )
return TRUE ;
V_88 = F_54 ( V_82 ) ;
#else
if ( F_49 ( V_82 , V_2 ) == V_83 )
return TRUE ;
V_88 =
L_18 ;
#endif
F_55 ( V_84 , ( V_89 ) V_85 , L_19 ,
V_2 , V_88 ) ;
if ( strstr ( V_88 , L_20 ) == NULL )
F_55 ( V_86 , ( V_89 ) V_87 , V_90 ) ;
else
V_86 [ 0 ] = '\0' ;
return FALSE ;
}
static T_16 *
F_56 ( int V_76 )
{
T_16 * V_91 ;
const char * V_92 ;
V_91 = ( T_16 * ) F_18 ( sizeof ( T_16 ) ) ;
V_91 -> V_76 = V_76 ;
V_92 = F_43 ( V_76 ) ;
if ( V_92 != NULL )
V_91 -> V_2 = F_15 ( V_92 ) ;
else
V_91 -> V_2 = F_12 ( L_21 , V_76 ) ;
V_92 = F_44 ( V_76 ) ;
if ( V_92 != NULL )
V_91 -> T_2 = F_15 ( V_92 ) ;
else
V_91 -> T_2 = NULL ;
return V_91 ;
}
static T_13 *
F_57 ( T_18 * V_81 , T_21 * V_93 ,
char * * V_64 )
{
T_13 * V_79 ;
int V_94 ;
#ifdef F_58
int * V_95 ;
int V_7 , V_96 ;
#endif
T_16 * V_91 ;
V_94 = F_49 ( V_81 , V_93 -> V_2 ) ;
#ifdef F_58
V_96 = F_59 ( V_81 , & V_95 ) ;
if ( V_96 < 0 ) {
if ( V_64 != NULL ) {
#ifdef F_60
if ( V_96 == V_97 )
* V_64 = F_12 ( L_22 ,
F_54 ( V_81 ) ) ;
else
* V_64 = F_15 ( F_61 ( V_96 ) ) ;
#else
* V_64 = F_12 ( L_22 ,
F_54 ( V_81 ) ) ;
#endif
}
return NULL ;
}
V_79 = NULL ;
for ( V_7 = 0 ; V_7 < V_96 ; V_7 ++ ) {
V_91 = F_56 ( V_95 [ V_7 ] ) ;
if ( V_95 [ V_7 ] == V_94 )
V_79 = F_62 ( V_79 ,
V_91 ) ;
else
V_79 = F_30 ( V_79 ,
V_91 ) ;
}
#ifdef F_63
F_64 ( V_95 ) ;
#else
#ifndef F_17
#define F_65 free
F_65 ( V_95 ) ;
#endif
#endif
#else
V_91 = F_56 ( V_94 ) ;
V_79 = F_30 ( V_79 , V_91 ) ;
#endif
if ( V_64 != NULL )
* V_64 = NULL ;
return V_79 ;
}
static T_8
F_66 ( const char * V_98 )
{
int V_99 ;
struct V_100 V_101 ;
T_22 V_102 ;
V_99 = F_67 ( V_103 , V_104 , 0 ) ;
if ( V_99 == - 1 )
return FALSE ;
memset ( & V_101 , 0 , sizeof V_101 ) ;
F_68 ( V_101 . V_105 , V_98 , sizeof V_101 . V_105 ) ;
memset ( & V_102 , 0 , sizeof V_102 ) ;
V_101 . V_106 = ( V_107 ) & V_102 ;
#if F_69 ( V_108 )
if ( F_70 ( V_99 , V_108 , & V_101 ) == 0 ) {
F_71 ( V_99 ) ;
return TRUE ;
}
#else
if ( F_70 ( V_99 , V_109 , & V_101 ) == 0 ) {
F_71 ( V_99 ) ;
return TRUE ;
}
#endif
F_71 ( V_99 ) ;
return FALSE ;
}
static T_8
F_66 ( const char * V_98 V_3 )
{
return FALSE ;
}
T_17 *
F_72 ( T_21 * V_93 ,
char * * V_64 )
{
T_17 * V_78 ;
char V_68 [ V_69 ] ;
T_18 * V_81 ;
int V_110 ;
V_81 = F_73 ( V_93 -> V_2 , V_68 ) ;
if ( V_81 == NULL ) {
if ( V_64 != NULL )
* V_64 = F_15 ( V_68 ) ;
return NULL ;
}
if ( F_66 ( V_93 -> V_2 ) ) {
V_110 = 0 ;
} else {
V_110 = F_74 ( V_81 ) ;
}
if ( V_110 < 0 ) {
if ( V_110 == V_97 )
* V_64 = F_12 ( L_23 ,
F_54 ( V_81 ) ) ;
else
* V_64 = F_15 ( F_61 ( V_110 ) ) ;
F_75 ( V_81 ) ;
return NULL ;
}
V_78 = ( T_17 * ) F_18 ( sizeof *V_78 ) ;
if ( V_110 == 0 )
V_78 -> V_111 = FALSE ;
else if ( V_110 == 1 ) {
V_78 -> V_111 = TRUE ;
if ( V_93 -> V_112 )
F_76 ( V_81 , 1 ) ;
} else {
if ( V_64 != NULL ) {
* V_64 = F_12 ( L_24 ,
V_110 ) ;
}
F_75 ( V_81 ) ;
F_14 ( V_78 ) ;
return NULL ;
}
V_110 = F_77 ( V_81 ) ;
if ( V_110 < 0 ) {
if ( V_64 != NULL ) {
if ( V_110 == V_97 )
* V_64 = F_12 ( L_25 ,
F_54 ( V_81 ) ) ;
else
* V_64 = F_15 ( F_61 ( V_110 ) ) ;
}
F_75 ( V_81 ) ;
F_14 ( V_78 ) ;
return NULL ;
}
V_78 -> V_79 = F_57 ( V_81 , V_93 ,
V_64 ) ;
if ( V_78 -> V_79 == NULL ) {
F_75 ( V_81 ) ;
F_14 ( V_78 ) ;
return NULL ;
}
F_75 ( V_81 ) ;
if ( V_64 != NULL )
* V_64 = NULL ;
return V_78 ;
}
T_17 *
F_78 ( T_21 * V_93 ,
char * * V_64 )
{
T_17 * V_78 ;
char V_68 [ V_69 ] ;
T_18 * V_81 ;
V_81 = F_79 ( V_93 -> V_2 , V_113 , 0 , 0 ,
V_68 ) ;
if ( V_81 == NULL ) {
if ( V_64 != NULL )
* V_64 = F_15 ( V_68 [ 0 ] == '\0' ? L_26 : V_68 ) ;
return NULL ;
}
V_78 = ( T_17 * ) F_18 ( sizeof *V_78 ) ;
V_78 -> V_111 = FALSE ;
V_78 -> V_79 = F_57 ( V_81 , V_93 ,
V_64 ) ;
if ( V_78 -> V_79 == NULL ) {
F_75 ( V_81 ) ;
F_14 ( V_78 ) ;
return NULL ;
}
F_75 ( V_81 ) ;
if ( V_64 != NULL )
* V_64 = NULL ;
return V_78 ;
}
T_17 *
F_80 ( T_21 * V_93 , char * * V_64 )
{
#if F_69 ( V_114 ) && F_69 ( V_115 )
T_17 * V_78 ;
char V_68 [ V_69 ] ;
T_18 * V_81 ;
int V_94 ;
T_16 * V_91 ;
if ( strncmp ( V_93 -> V_2 , L_27 , 8 ) == 0 ) {
struct V_61 V_62 ;
V_62 . type = V_93 -> V_116 == V_117 ?
V_118 : V_119 ;
V_62 . V_120 = V_93 -> V_121 ;
V_62 . V_122 = V_93 -> V_123 ;
V_68 [ 0 ] = '\0' ;
V_81 = F_81 ( V_93 -> V_2 , V_113 , 0 , 0 , & V_62 ,
V_68 ) ;
if ( V_81 == NULL ) {
if ( V_64 != NULL )
* V_64 = F_15 ( V_68 [ 0 ] == '\0' ? L_26 : V_68 ) ;
return NULL ;
}
V_78 = ( T_17 * ) F_18 ( sizeof *V_78 ) ;
V_78 -> V_111 = FALSE ;
V_78 -> V_79 = NULL ;
V_94 = F_49 ( V_81 , V_93 -> V_2 ) ;
V_91 = F_56 ( V_94 ) ;
V_78 -> V_79 = F_30 ( V_78 -> V_79 ,
V_91 ) ;
F_75 ( V_81 ) ;
if ( V_64 != NULL )
* V_64 = NULL ;
return V_78 ;
}
#endif
return F_82 ( V_93 , V_64 ) ;
}
