static const T_1 * F_1 ( void )
{
return V_1 ;
}
static void F_2 ( void )
{
F_3 ( V_1 ) ;
V_1 = NULL ;
}
static int F_4 ( const int * * V_2 )
{
static int V_3 [ 2 ] = { 0 , 0 } ;
static int V_4 = 0 ;
static int V_5 = 0 ;
if ( ! V_5 ) {
const T_1 * V_6 ;
if ( ( V_6 = F_1 () ) != NULL )
V_3 [ V_4 ++ ] = F_5 ( V_6 ) ;
V_3 [ V_4 ] = 0 ;
V_5 = 1 ;
}
* V_2 = V_3 ;
return V_4 ;
}
static const T_2 * F_6 ( void )
{
return V_7 ;
}
static const T_2 * F_7 ( void )
{
return V_8 ;
}
static void F_8 ( void )
{
F_9 ( V_7 ) ;
F_9 ( V_8 ) ;
V_7 = NULL ;
V_8 = NULL ;
}
static int F_10 ( T_3 * V_9 )
{
if ( ( V_10 = F_11 ( L_1 , 0 ) ) == NULL
|| F_12 ( V_10 , V_11 ) == 0
|| F_13 ( V_10 , V_12 ) == 0
|| F_14 ( V_10 , V_13 ) == 0
|| F_15 ( V_10 , V_14 ) == 0
|| F_16 ( V_10 , V_15 ) == 0
|| F_17 ( V_10 , V_16 ) == 0
|| F_18 ( V_10 , V_17 ) == 0
|| F_19 ( V_10 , V_18 ) == 0 ) {
F_20 ( V_19 , V_20 ) ;
return 0 ;
}
F_21 () ;
if ( ! F_22 ( V_9 , V_21 )
|| ! F_23 ( V_9 , V_22 )
|| ! F_24 ( V_9 , V_10 )
|| ! F_25 ( V_9 , V_23 )
|| ! F_26 ( V_9 , V_24 )
|| ! F_27 ( V_9 , V_25 )
|| ! F_28 ( V_9 , V_26 )
|| ! F_29 ( V_9 , V_27 ) ) {
F_20 ( V_19 , V_20 ) ;
return 0 ;
}
V_1 = F_30 ( V_28 , V_29 ) ;
if ( V_1 == NULL
|| ! F_31 ( V_1 , V_30 )
|| ! F_32 ( V_1 , V_31 )
|| ! F_33 ( V_1 ,
sizeof( T_1 * ) + sizeof( V_32 ) )
|| ! F_34 ( V_1 , V_33 )
|| ! F_35 ( V_1 , V_34 )
|| ! F_36 ( V_1 , V_35 )
|| ! F_37 ( V_1 , V_36 ) ) {
F_3 ( V_1 ) ;
V_1 = NULL ;
}
V_7 = F_38 ( V_37 ,
16 ,
16 ) ;
if ( V_7 == NULL
|| ! F_39 ( V_7 , 16 )
|| ! F_40 ( V_7 ,
V_38
| V_39
| V_40 )
|| ! F_41 ( V_7 ,
V_41 )
|| ! F_42 ( V_7 ,
V_42 )
|| ! F_43 ( V_7 ,
V_43 )
|| ! F_44 ( V_7 ,
V_44 )
|| ! F_45 ( V_7 ,
sizeof( struct V_45 ) ) ) {
F_9 ( V_7 ) ;
V_7 = NULL ;
}
V_8 = F_38 (
V_46 ,
16 ,
16 ) ;
if ( V_8 == NULL
|| ! F_39 ( V_8 , 16 )
|| ! F_40 ( V_8 ,
V_39
| V_38
| V_47
| V_40 )
|| ! F_41 ( V_8 ,
V_48 )
|| ! F_42 ( V_8 ,
V_49 )
|| ! F_43 ( V_8 ,
V_50 )
|| ! F_44 ( V_8 ,
V_51 )
|| ! F_45 ( V_8 ,
sizeof( struct V_45 ) ) ) {
F_9 ( V_8 ) ;
V_8 = NULL ;
}
return 1 ;
}
static int F_46 ( T_3 * V_9 , const char * V_52 )
{
if ( V_52 && ( strcmp ( V_52 , V_21 ) != 0 ) )
return 0 ;
if ( ! F_10 ( V_9 ) )
return 0 ;
return 1 ;
}
static T_3 * F_47 ( void )
{
T_3 * V_53 = F_48 () ;
if ( ! V_53 )
return NULL ;
if ( ! F_10 ( V_53 ) ) {
F_49 ( V_53 ) ;
return NULL ;
}
return V_53 ;
}
void F_50 ( void )
{
T_3 * V_54 = F_47 () ;
if ( ! V_54 )
return;
F_51 ( V_54 ) ;
F_49 ( V_54 ) ;
F_52 () ;
}
static int V_26 ( T_3 * V_9 )
{
return 1 ;
}
static int V_27 ( T_3 * V_9 )
{
return 1 ;
}
static int V_25 ( T_3 * V_9 )
{
F_2 () ;
F_8 () ;
F_53 ( V_10 ) ;
F_54 () ;
return 1 ;
}
static int V_23 ( T_3 * V_9 , const T_1 * * V_55 ,
const int * * V_2 , int V_56 )
{
int V_57 = 1 ;
if ( ! V_55 ) {
return F_4 ( V_2 ) ;
}
switch ( V_56 ) {
case V_28 :
* V_55 = F_1 () ;
break;
default:
V_57 = 0 ;
* V_55 = NULL ;
break;
}
return V_57 ;
}
static int V_24 ( T_3 * V_9 , const T_2 * * V_58 ,
const int * * V_2 , int V_56 )
{
int V_57 = 1 ;
if ( V_58 == NULL ) {
* V_2 = V_59 ;
return ( sizeof( V_59 ) -
1 ) / sizeof( V_59 [ 0 ] ) ;
}
switch ( V_56 ) {
case V_37 :
* V_58 = F_6 () ;
break;
case V_46 :
* V_58 = F_7 () ;
break;
default:
V_57 = 0 ;
* V_58 = NULL ;
break;
}
return V_57 ;
}
static void F_55 ( T_4 * V_60 , const void * V_61 ,
T_5 V_62 , void * V_63 )
{
T_5 * V_64 = ( T_5 * ) V_63 ;
#if F_56 ( V_65 )
F_57 ( V_62 ) ;
F_57 ( * V_64 ) ;
#elif F_56 ( V_66 )
F_58 ( V_62 ) ;
F_58 ( * V_64 ) ;
#endif
F_59 ( V_64 ) ;
}
static void F_60 ( void ) {
T_6 * V_67 ;
T_4 * V_68 ;
T_5 V_69 [ 2 ] = { 0 , 0 } ;
T_5 * V_70 ;
#if F_56 ( V_65 )
T_7 V_71 , V_72 ;
char V_73 = V_74 ;
#elif F_56 ( V_66 )
char V_73 = V_74 ;
#endif
if ( ( V_67 = F_61 () ) == NULL )
return;
V_68 = F_62 ( V_67 ) ;
if ( F_63 ( V_68 , V_21 , & V_69 [ 0 ] ,
( void * * ) & V_70 ) ) {
V_69 [ 1 ] = * V_70 ;
} else {
V_70 = F_64 ( sizeof( * V_70 ) ) ;
if ( V_70 == NULL )
return;
#if F_56 ( V_65 )
if ( F_65 ( & V_69 [ 0 ] , & V_69 [ 1 ] , NULL , 256 ) == 0 ) {
F_59 ( V_70 ) ;
return;
}
#elif F_56 ( V_66 )
if ( F_66 ( V_69 ) != 0 ) {
F_59 ( V_70 ) ;
return;
}
#endif
* V_70 = V_69 [ 1 ] ;
if( ! F_67 ( V_68 , V_21 , V_69 [ 0 ] ,
V_70 , F_55 ) ) {
F_55 ( V_68 , V_21 , V_69 [ 0 ] , V_70 ) ;
return;
}
}
#if F_56 ( V_65 )
F_68 ( V_69 [ 1 ] , & V_73 , 1 , & V_71 , NULL ) ;
#elif F_56 ( V_66 )
if ( F_69 ( V_69 [ 1 ] , & V_73 , 1 ) < 0 )
return;
#endif
F_70 () ;
#if F_56 ( V_65 )
F_71 ( V_69 [ 0 ] , & V_73 , 1 , & V_72 , NULL ) ;
#elif F_56 ( V_66 )
if ( F_72 ( V_69 [ 0 ] , & V_73 , 1 ) < 0 )
return;
#endif
}
static int V_34 ( T_8 * V_60 )
{
F_60 () ;
return F_73 ( F_74 ( V_60 ) ) ;
}
static int V_35 ( T_8 * V_60 , const void * F_74 ,
T_9 V_75 )
{
F_60 () ;
return F_75 ( F_74 ( V_60 ) , F_74 , ( T_9 ) V_75 ) ;
}
static int V_36 ( T_8 * V_60 , unsigned char * V_6 )
{
F_60 () ;
return F_76 ( V_6 , F_74 ( V_60 ) ) ;
}
static int V_11 ( int V_76 , const unsigned char * V_77 ,
unsigned char * V_78 , T_10 * V_79 , int V_80 ) {
F_60 () ;
return F_77 ( F_78 () )
( V_76 , V_77 , V_78 , V_79 , V_80 ) ;
}
static int V_12 ( int V_76 , const unsigned char * V_77 ,
unsigned char * V_78 , T_10 * V_79 , int V_80 ) {
F_60 () ;
return F_79 ( F_78 () )
( V_76 , V_77 , V_78 , V_79 , V_80 ) ;
}
static int V_13 ( int V_76 , const unsigned char * V_77 ,
unsigned char * V_78 , T_10 * V_79 , int V_80 )
{
F_60 () ;
return F_80 ( F_78 () )
( V_76 , V_77 , V_78 , V_79 , V_80 ) ;
}
static int V_14 ( int V_76 , const unsigned char * V_77 ,
unsigned char * V_78 , T_10 * V_79 , int V_80 )
{
F_60 () ;
return F_81 ( F_78 () )
( V_76 , V_77 , V_78 , V_79 , V_80 ) ;
}
static int V_15 ( T_11 * V_81 , const T_11 * V_82 , T_10 * V_79 , T_12 * V_60 )
{
F_60 () ;
return F_82 ( F_78 () ) ( V_81 , V_82 , V_79 , V_60 ) ;
}
static int V_17 ( T_10 * V_79 )
{
return F_83 ( F_78 () ) ( V_79 ) ;
}
static int V_18 ( T_10 * V_79 )
{
return F_84 ( F_78 () ) ( V_79 ) ;
}
static int F_85 ( T_13 * V_60 , int type , int V_83 ,
void * V_84 , int V_85 )
{
int V_53 ;
struct V_45 * V_86 =
(struct V_45 * ) F_86 ( V_60 ) ;
if ( V_86 == NULL )
return 0 ;
switch ( type ) {
case V_87 :
V_86 -> V_88 = V_83 ;
V_86 -> V_89 = ( unsigned char * * ) V_84 ;
break;
case V_90 :
V_86 -> V_88 = V_83 ;
V_86 -> V_91 = ( unsigned char * * ) V_84 ;
break;
case V_92 :
V_86 -> V_88 = V_83 ;
V_86 -> V_93 = ( T_9 * ) V_84 ;
break;
case V_94 :
if ( ! V_85 )
return - 1 ;
F_87 ( V_60 , V_86 -> V_95 ) ;
V_53 = F_88 ( F_89 () )
( V_60 , type , V_83 , V_84 ) ;
F_87 ( V_60 , V_86 ) ;
return V_53 ;
case V_96 :
{
unsigned char * V_97 = V_84 ;
unsigned int V_98 ;
if ( ! V_85 || V_83 != V_99 )
return - 1 ;
if ( V_86 -> V_100 >= V_101 )
return - 1 ;
memcpy ( V_86 -> V_102 [ V_86 -> V_100 ] , V_84 ,
V_99 ) ;
V_86 -> V_100 ++ ;
V_98 = V_97 [ V_83 - 2 ] << 8 | V_97 [ V_83 - 1 ] ;
if ( V_86 -> V_103 ) {
if ( ( V_97 [ V_83 - 4 ] << 8 | V_97 [ V_83 - 3 ] ) >= V_104 ) {
V_98 -= V_105 ;
}
return ( ( V_98 + V_30 + V_105 )
& - V_105 ) - V_98 ;
} else {
return V_30 ;
}
}
default:
return 0 ;
}
return 1 ;
}
static int F_90 ( T_13 * V_60 ,
const unsigned char * V_61 ,
const unsigned char * V_106 , int V_103 ,
const T_2 * V_58 )
{
int V_53 ;
struct V_45 * V_86 =
(struct V_45 * ) F_86 ( V_60 ) ;
if ( V_86 -> V_95 == NULL
&& F_91 ( V_58 ) != 0 ) {
V_86 -> V_95 = F_92 (
F_91 ( V_58 ) ) ;
if ( V_86 -> V_95 == NULL ) {
F_20 ( V_107 ,
V_108 ) ;
return 0 ;
}
}
V_86 -> V_88 = 0 ;
V_86 -> V_100 = 0 ;
F_87 ( V_60 , V_86 -> V_95 ) ;
V_53 = F_93 ( V_58 ) ( V_60 , V_61 , V_106 , V_103 ) ;
F_87 ( V_60 , V_86 ) ;
return V_53 ;
}
static int F_94 ( T_13 * V_60 , unsigned char * V_109 ,
const unsigned char * V_110 , T_9 V_111 ,
const T_2 * V_58 )
{
int V_53 = 1 ;
unsigned int V_112 , V_113 ;
struct V_45 * V_86 =
(struct V_45 * ) F_86 ( V_60 ) ;
V_113 = V_86 -> V_88 ;
F_87 ( V_60 , V_86 -> V_95 ) ;
if ( V_113 == 0 ) {
if ( V_86 -> V_100 != 0 ) {
if ( V_86 -> V_100 != 1 )
return - 1 ;
F_88 (V_58)
( V_60 , V_96 ,
V_99 ,
V_86 -> V_102 [ 0 ] );
}
V_53 = F_95 ( V_58 )
( V_60 , V_109 , V_110 , V_111 ) ;
} else {
if ( V_86 -> V_100 > 0 && V_86 -> V_100 != V_113 )
return - 1 ;
for ( V_112 = 0 ; V_112 < V_113 ; V_112 ++ ) {
if ( V_86 -> V_100 > 0 ) {
F_88 (V_58)
( V_60 , V_96 ,
V_99 ,
V_86 -> V_102 [ V_112 ] );
}
V_53 = V_53 && F_95 ( V_58 )
( V_60 , V_86 -> V_89 [ V_112 ] , V_86 -> V_91 [ V_112 ] ,
V_86 -> V_93 [ V_112 ] ) ;
}
V_86 -> V_88 = 0 ;
}
V_86 -> V_100 = 0 ;
F_87 ( V_60 , V_86 ) ;
return V_53 ;
}
static int F_96 ( T_13 * V_60 ,
const T_2 * V_58 )
{
struct V_45 * V_86 =
(struct V_45 * ) F_86 ( V_60 ) ;
F_97 ( V_86 -> V_95 ,
F_91 ( V_58 ) ) ;
return 1 ;
}
static int V_44 ( T_13 * V_60 , int type , int V_83 ,
void * V_84 )
{
return F_85 ( V_60 , type , V_83 , V_84 , 0 ) ;
}
static int V_41 ( T_13 * V_60 , const unsigned char * V_61 ,
const unsigned char * V_106 , int V_103 )
{
return F_90 ( V_60 , V_61 , V_106 , V_103 , F_98 () ) ;
}
static int V_42 ( T_13 * V_60 , unsigned char * V_109 ,
const unsigned char * V_110 , T_9 V_111 )
{
return F_94 ( V_60 , V_109 , V_110 , V_111 , F_98 () ) ;
}
static int V_43 ( T_13 * V_60 )
{
return F_96 ( V_60 , F_98 () ) ;
}
static int V_51 ( T_13 * V_60 , int type ,
int V_83 , void * V_84 )
{
return F_85 ( V_60 , type , V_83 , V_84 , 1 ) ;
}
static int V_48 ( T_13 * V_60 ,
const unsigned char * V_61 ,
const unsigned char * V_106 ,
int V_103 )
{
return F_90 ( V_60 , V_61 , V_106 , V_103 ,
F_89 () ) ;
}
static int V_49 ( T_13 * V_60 ,
unsigned char * V_109 ,
const unsigned char * V_110 ,
T_9 V_111 )
{
return F_94 ( V_60 , V_109 , V_110 , V_111 , F_89 () ) ;
}
static int V_50 ( T_13 * V_60 )
{
return F_96 ( V_60 , F_89 () ) ;
}
