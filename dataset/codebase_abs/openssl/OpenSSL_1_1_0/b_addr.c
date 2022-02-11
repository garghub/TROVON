T_1 * F_1 ( void )
{
T_1 * V_1 = F_2 ( sizeof( * V_1 ) ) ;
if ( V_1 == NULL ) {
F_3 ( V_2 , V_3 ) ;
return NULL ;
}
V_1 -> V_4 . V_5 = V_6 ;
return V_1 ;
}
void F_4 ( T_1 * V_7 )
{
F_5 ( V_7 ) ;
}
void F_6 ( T_1 * V_7 )
{
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
V_7 -> V_4 . V_5 = V_6 ;
}
int F_7 ( T_1 * V_7 , const struct V_8 * V_4 )
{
if ( V_4 -> V_5 == V_9 ) {
V_7 -> V_10 = * ( const struct V_11 * ) V_4 ;
return 1 ;
}
#ifdef F_8
if ( V_4 -> V_5 == F_8 ) {
V_7 -> V_12 = * ( const struct V_13 * ) V_4 ;
return 1 ;
}
#endif
#ifdef F_9
if ( V_7 -> V_4 . V_5 == F_9 ) {
V_7 -> V_14 = * ( const struct V_15 * ) V_4 ;
return 1 ;
}
#endif
return 0 ;
}
int F_10 ( T_1 * V_7 , int V_16 ,
const void * V_17 , T_2 V_18 ,
unsigned short V_19 )
{
#ifdef F_9
if ( V_16 == F_9 ) {
if ( V_18 + 1 > sizeof( V_7 -> V_14 . V_20 ) )
return 0 ;
memset ( & V_7 -> V_14 , 0 , sizeof( V_7 -> V_14 ) ) ;
V_7 -> V_14 . V_21 = V_16 ;
strncpy ( V_7 -> V_14 . V_20 , V_17 , sizeof( V_7 -> V_14 . V_20 ) - 1 ) ;
return 1 ;
}
#endif
if ( V_16 == V_9 ) {
if ( V_18 != sizeof( struct V_22 ) )
return 0 ;
memset ( & V_7 -> V_10 , 0 , sizeof( V_7 -> V_10 ) ) ;
V_7 -> V_10 . V_23 = V_16 ;
V_7 -> V_10 . V_24 = V_19 ;
V_7 -> V_10 . V_25 = * (struct V_22 * ) V_17 ;
return 1 ;
}
#ifdef F_8
if ( V_16 == F_8 ) {
if ( V_18 != sizeof( struct V_26 ) )
return 0 ;
memset ( & V_7 -> V_12 , 0 , sizeof( V_7 -> V_12 ) ) ;
V_7 -> V_12 . V_27 = V_16 ;
V_7 -> V_12 . V_28 = V_19 ;
V_7 -> V_12 . V_29 = * (struct V_26 * ) V_17 ;
return 1 ;
}
#endif
return 0 ;
}
int F_11 ( const T_1 * V_7 )
{
return V_7 -> V_4 . V_5 ;
}
int F_12 ( const T_1 * V_7 , void * V_30 , T_2 * V_31 )
{
T_2 V_32 = 0 ;
const void * V_33 = NULL ;
if ( V_7 -> V_4 . V_5 == V_9 ) {
V_32 = sizeof( V_7 -> V_10 . V_25 ) ;
V_33 = & V_7 -> V_10 . V_25 ;
}
#ifdef F_8
else if ( V_7 -> V_4 . V_5 == F_8 ) {
V_32 = sizeof( V_7 -> V_12 . V_29 ) ;
V_33 = & V_7 -> V_12 . V_29 ;
}
#endif
#ifdef F_9
else if ( V_7 -> V_4 . V_5 == F_9 ) {
V_32 = strlen ( V_7 -> V_14 . V_20 ) ;
V_33 = & V_7 -> V_14 . V_20 ;
}
#endif
if ( V_33 == NULL )
return 0 ;
if ( V_30 != NULL ) {
memcpy ( V_30 , V_33 , V_32 ) ;
}
if ( V_31 != NULL )
* V_31 = V_32 ;
return 1 ;
}
unsigned short F_13 ( const T_1 * V_7 )
{
if ( V_7 -> V_4 . V_5 == V_9 )
return V_7 -> V_10 . V_24 ;
#ifdef F_8
if ( V_7 -> V_4 . V_5 == F_8 )
return V_7 -> V_12 . V_28 ;
#endif
return 0 ;
}
static int F_14 ( const T_1 * V_7 , int V_34 ,
char * * V_35 , char * * V_36 )
{
if ( F_15 () != 1 )
return 0 ;
if ( 1 ) {
#ifdef F_16
int V_1 = 0 ;
char V_37 [ V_38 ] = L_1 , V_39 [ V_40 ] = L_1 ;
int V_41 = 0 ;
if ( V_34 )
V_41 |= V_42 | V_43 ;
if ( ( V_1 = F_17 ( F_18 ( V_7 ) ,
F_19 ( V_7 ) ,
V_37 , sizeof( V_37 ) , V_39 , sizeof( V_39 ) ,
V_41 ) ) != 0 ) {
# ifdef F_20
if ( V_1 == F_20 ) {
F_21 ( V_44 , F_22 () ) ;
F_3 ( V_45 , V_46 ) ;
} else
# endif
{
F_3 ( V_45 , V_46 ) ;
F_23 ( 1 , F_24 ( V_1 ) ) ;
}
return 0 ;
}
if ( V_39 [ 0 ] == '\0' ) {
F_25 ( V_39 , sizeof( V_39 ) , L_2 ,
F_26 ( F_13 ( V_7 ) ) ) ;
}
if ( V_35 != NULL )
* V_35 = F_27 ( V_37 ) ;
if ( V_36 != NULL )
* V_36 = F_27 ( V_39 ) ;
} else {
#endif
if ( V_35 != NULL )
* V_35 = F_27 ( F_28 ( V_7 -> V_10 . V_25 ) ) ;
if ( V_36 != NULL ) {
char V_39 [ 6 ] ;
F_25 ( V_39 , sizeof( V_39 ) , L_2 , F_26 ( V_7 -> V_10 . V_24 ) ) ;
* V_36 = F_27 ( V_39 ) ;
}
}
if ( ( V_35 != NULL && * V_35 == NULL )
|| ( V_36 != NULL && * V_36 == NULL ) ) {
if ( V_35 != NULL ) {
F_5 ( * V_35 ) ;
* V_35 = NULL ;
}
if ( V_36 != NULL ) {
F_5 ( * V_36 ) ;
* V_36 = NULL ;
}
F_3 ( V_45 , V_3 ) ;
return 0 ;
}
return 1 ;
}
char * F_29 ( const T_1 * V_7 , int V_34 )
{
char * V_35 = NULL ;
if ( F_14 ( V_7 , V_34 , & V_35 , NULL ) )
return V_35 ;
return NULL ;
}
char * F_30 ( const T_1 * V_7 , int V_34 )
{
char * V_36 = NULL ;
if ( F_14 ( V_7 , V_34 , NULL , & V_36 ) )
return V_36 ;
return NULL ;
}
char * F_31 ( const T_1 * V_7 )
{
#ifdef F_9
if ( V_7 -> V_4 . V_5 == F_9 )
return F_27 ( V_7 -> V_14 . V_20 ) ;
#endif
return NULL ;
}
const struct V_8 * F_18 ( const T_1 * V_7 )
{
return & ( V_7 -> V_4 ) ;
}
struct V_8 * F_32 ( T_1 * V_7 )
{
return & ( V_7 -> V_4 ) ;
}
T_3 F_19 ( const T_1 * V_7 )
{
if ( V_7 -> V_4 . V_5 == V_9 )
return sizeof( V_7 -> V_10 ) ;
#ifdef F_8
if ( V_7 -> V_4 . V_5 == F_8 )
return sizeof( V_7 -> V_12 ) ;
#endif
#ifdef F_9
if ( V_7 -> V_4 . V_5 == F_9 )
return sizeof( V_7 -> V_14 ) ;
#endif
return sizeof( * V_7 ) ;
}
const T_4 * F_33 ( const T_4 * V_47 )
{
if ( V_47 != NULL )
return V_47 -> V_48 ;
return NULL ;
}
int F_34 ( const T_4 * V_47 )
{
if ( V_47 != NULL )
return V_47 -> V_49 ;
return 0 ;
}
int F_35 ( const T_4 * V_47 )
{
if ( V_47 != NULL )
return V_47 -> V_50 ;
return 0 ;
}
int F_36 ( const T_4 * V_47 )
{
if ( V_47 != NULL ) {
if ( V_47 -> V_51 != 0 )
return V_47 -> V_51 ;
#ifdef F_9
if ( V_47 -> V_49 == F_9 )
return 0 ;
#endif
switch ( V_47 -> V_50 ) {
case V_52 :
return V_53 ;
case V_54 :
return V_55 ;
default:
break;
}
}
return 0 ;
}
T_3 F_37 ( const T_4 * V_47 )
{
if ( V_47 != NULL )
return V_47 -> V_56 ;
return 0 ;
}
const struct V_8 * F_38 ( const T_4 * V_47 )
{
if ( V_47 != NULL )
return V_47 -> V_57 ;
return NULL ;
}
const T_1 * F_39 ( const T_4 * V_47 )
{
if ( V_47 != NULL )
return ( T_1 * ) V_47 -> V_57 ;
return NULL ;
}
void F_40 ( T_4 * V_47 )
{
if ( V_47 == NULL )
return;
#ifdef F_16
# ifdef F_9
# define F_41 bai->bai_family != AF_UNIX
# else
# define F_41 1
# endif
if ( F_41 ) {
F_42 ( V_47 ) ;
return;
}
#endif
while ( V_47 != NULL ) {
T_4 * V_58 = V_47 -> V_48 ;
F_5 ( V_47 -> V_57 ) ;
F_5 ( V_47 ) ;
V_47 = V_58 ;
}
}
int F_43 ( const char * V_59 , char * * V_37 , char * * V_36 ,
enum V_60 V_61 )
{
const char * V_62 = NULL ; T_2 V_63 = 0 ;
const char * V_30 = NULL ; T_2 V_64 = 0 ;
if ( * V_59 == '[' ) {
if ( ( V_30 = strchr ( V_59 , ']' ) ) == NULL )
goto V_65;
V_62 = V_59 + 1 ;
V_63 = V_30 - V_62 ;
V_30 ++ ;
if ( * V_30 == '\0' )
V_30 = NULL ;
else if ( * V_30 != ':' )
goto V_65;
else {
V_30 ++ ;
V_64 = strlen ( V_30 ) ;
}
} else {
const char * V_66 = strrchr ( V_59 , ':' ) ;
V_30 = strchr ( V_59 , ':' ) ;
if ( V_30 != V_66 )
goto V_67;
if ( V_30 != NULL ) {
V_62 = V_59 ;
V_63 = V_30 - V_62 ;
V_30 ++ ;
V_64 = strlen ( V_30 ) ;
} else if ( V_61 == V_68 ) {
V_62 = V_59 ;
V_63 = strlen ( V_62 ) ;
} else {
V_30 = V_59 ;
V_64 = strlen ( V_30 ) ;
}
}
if ( V_30 != NULL && strchr ( V_30 , ':' ) )
goto V_65;
if ( V_62 != NULL && V_37 != NULL ) {
if ( V_63 == 0
|| ( V_63 == 1 && V_62 [ 0 ] == '*' ) ) {
* V_37 = NULL ;
} else {
* V_37 = F_44 ( V_62 , V_63 ) ;
if ( * V_37 == NULL )
goto V_69;
}
}
if ( V_30 != NULL && V_36 != NULL ) {
if ( V_64 == 0
|| ( V_64 == 1 && V_30 [ 0 ] == '*' ) ) {
* V_36 = NULL ;
} else {
* V_36 = F_44 ( V_30 , V_64 ) ;
if ( * V_36 == NULL )
goto V_69;
}
}
return 1 ;
V_67:
F_3 ( V_70 , V_71 ) ;
return 0 ;
V_65:
F_3 ( V_70 , V_72 ) ;
return 0 ;
V_69:
F_3 ( V_70 , V_3 ) ;
return 0 ;
}
static int F_45 ( int V_16 , int V_73 ,
const void * V_17 , T_2 V_18 ,
unsigned short V_19 ,
T_4 * * V_47 )
{
F_46 ( V_47 != NULL ) ;
* V_47 = F_2 ( sizeof( * * V_47 ) ) ;
if ( * V_47 == NULL )
return 0 ;
( * V_47 ) -> V_49 = V_16 ;
( * V_47 ) -> V_50 = V_73 ;
if ( V_73 == V_52 )
( * V_47 ) -> V_51 = V_53 ;
if ( V_73 == V_54 )
( * V_47 ) -> V_51 = V_55 ;
#ifdef F_9
if ( V_16 == F_9 )
( * V_47 ) -> V_51 = 0 ;
#endif
{
T_1 * V_74 = F_1 () ;
if ( V_74 != NULL ) {
F_10 ( V_74 , V_16 , V_17 , V_18 , V_19 ) ;
( * V_47 ) -> V_57 = F_32 ( V_74 ) ;
}
}
( * V_47 ) -> V_48 = NULL ;
if ( ( * V_47 ) -> V_57 == NULL ) {
F_40 ( * V_47 ) ;
* V_47 = NULL ;
return 0 ;
}
return 1 ;
}
int F_47 ( const char * V_37 , const char * V_36 ,
enum V_75 V_76 ,
int V_16 , int V_73 , T_4 * * V_77 )
{
int V_1 = 0 ;
switch( V_16 ) {
case V_9 :
#ifdef F_8
case F_8 :
#endif
#ifdef F_9
case F_9 :
#endif
#ifdef V_6
case V_6 :
#endif
break;
default:
F_3 ( V_78 , V_79 ) ;
return 0 ;
}
#ifdef F_9
if ( V_16 == F_9 ) {
if ( F_45 ( V_16 , V_73 , V_37 , strlen ( V_37 ) , 0 , V_77 ) )
return 1 ;
else
F_3 ( V_78 , V_3 ) ;
return 0 ;
}
#endif
if ( F_15 () != 1 )
return 0 ;
if ( 1 ) {
int V_80 = 0 ;
#ifdef F_16
struct V_81 V_82 ;
memset ( & V_82 , 0 , sizeof V_82 ) ;
V_82 . V_83 = V_16 ;
V_82 . V_84 = V_73 ;
if ( V_76 == V_85 )
V_82 . V_86 |= F_16 ;
switch ( ( V_80 = F_48 ( V_37 , V_36 , & V_82 , V_77 ) ) ) {
# ifdef F_20
case F_20 :
F_21 ( V_87 , F_22 () ) ;
F_3 ( V_78 , V_46 ) ;
break;
# endif
case 0 :
V_1 = 1 ;
break;
default:
F_3 ( V_78 , V_46 ) ;
F_23 ( 1 , F_24 ( V_80 ) ) ;
break;
}
} else {
#endif
const struct V_88 * V_89 ;
#if F_49 ( V_90 ) && F_49 ( V_91 )
# pragma V_92 V_93
# pragma V_92 V_94
#endif
#ifdef F_50
static T_5 V_95 ;
static const char * V_96 [] =
{ ( char * ) & V_95 , NULL } ;
#else
static T_6 V_95 ;
static const char * V_96 [] =
{ ( char * ) & V_95 , NULL } ;
#endif
static const struct V_88 V_97 =
{ NULL , NULL , V_9 , sizeof( V_95 ) ,
( char * * ) & V_96 } ;
#if F_49 ( V_90 ) && F_49 ( V_91 )
# pragma V_92 V_98
#endif
struct V_99 * V_100 ;
#ifdef F_51
struct V_99 V_101 = { NULL , NULL , NULL , 0 } ;
#else
struct V_99 V_101 = { NULL , NULL , 0 , NULL } ;
#endif
if ( ! F_52 ( & V_102 , V_103 ) ) {
F_3 ( V_78 , V_3 ) ;
V_1 = 0 ;
goto V_104;
}
F_53 ( V_105 ) ;
V_95 = V_106 ;
if ( V_37 == NULL ) {
V_89 = & V_97 ;
switch( V_76 ) {
case V_107 :
V_95 = V_108 ;
break;
case V_85 :
V_95 = V_106 ;
break;
default:
F_46 ( ( L_3 == 0 ) ) ;
break;
}
} else {
V_89 = F_54 ( V_37 ) ;
if ( V_89 == NULL ) {
#ifndef F_50
F_3 ( V_78 , V_46 ) ;
F_23 ( 1 , F_55 ( V_109 ) ) ;
#else
F_21 ( V_110 , F_56 () ) ;
#endif
V_1 = 0 ;
goto V_104;
}
}
if ( V_36 == NULL ) {
V_101 . V_111 = 0 ;
V_101 . V_112 = NULL ;
V_100 = & V_101 ;
} else {
char * V_113 = NULL ;
long V_114 = strtol ( V_36 , & V_113 , 10 ) ;
#if F_49 ( V_90 ) && F_49 ( V_91 )
# pragma V_92 V_93
# pragma V_92 V_94
#endif
char * V_115 = NULL ;
#if F_49 ( V_90 ) && F_49 ( V_91 )
# pragma V_92 V_98
#endif
switch ( V_73 ) {
case V_52 :
V_115 = L_4 ;
break;
case V_54 :
V_115 = L_5 ;
break;
}
if ( V_113 != V_36 && * V_113 == '\0'
&& V_114 > 0 && V_114 < 65536 ) {
V_101 . V_111 = F_57 ( V_114 ) ;
V_101 . V_112 = V_115 ;
V_100 = & V_101 ;
} else if ( V_113 == V_36 ) {
V_100 = F_58 ( V_36 , V_115 ) ;
if ( V_100 == NULL ) {
#ifndef F_50
F_3 ( V_78 , V_46 ) ;
F_23 ( 1 , F_55 ( V_109 ) ) ;
#else
F_21 ( V_116 , F_56 () ) ;
#endif
goto V_104;
}
} else {
F_3 ( V_78 , V_72 ) ;
goto V_104;
}
}
* V_77 = NULL ;
{
#if F_49 ( V_90 ) && F_49 ( V_91 )
# pragma V_92 V_93
# pragma V_92 V_94
#endif
char * * V_117 ;
#if F_49 ( V_90 ) && F_49 ( V_91 )
# pragma V_92 V_98
#endif
T_2 V_118 ;
T_4 * V_119 = NULL ;
for( V_117 = V_89 -> V_120 ; * V_117 != NULL ;
V_117 ++ )
;
for( V_118 = V_117 - V_89 -> V_120 ;
V_117 -- , V_118 -- > 0 ; ) {
if ( ! F_45 ( V_89 -> V_121 , V_73 ,
* V_117 , V_89 -> V_122 ,
V_100 -> V_111 , & V_119 ) )
goto V_123;
V_119 -> V_48 = * V_77 ;
* V_77 = V_119 ;
continue;
V_123:
F_40 ( * V_77 ) ;
* V_77 = NULL ;
F_3 ( V_78 , V_3 ) ;
V_1 = 0 ;
goto V_104;
}
V_1 = 1 ;
}
V_104:
F_59 ( V_105 ) ;
}
return V_1 ;
}
