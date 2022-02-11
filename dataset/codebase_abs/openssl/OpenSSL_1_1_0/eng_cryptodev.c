void F_1 ( void )
{
return;
}
static int F_2 ( void )
{
static int V_1 = - 1 ;
if ( V_1 == - 1 ) {
if ( ( V_1 = F_3 ( L_1 , V_2 , 0 ) ) == - 1 )
return ( - 1 ) ;
if ( F_4 ( V_1 , V_3 , 1 ) == - 1 ) {
F_5 ( V_1 ) ;
V_1 = - 1 ;
return ( - 1 ) ;
}
}
return ( V_1 ) ;
}
static int F_6 ( void )
{
int V_1 , V_4 ;
if ( ( V_1 = F_2 () ) == - 1 )
return ( - 1 ) ;
# ifndef F_7
if ( F_8 ( V_1 , V_5 , & V_4 ) == - 1 )
return ( - 1 ) ;
if ( F_4 ( V_4 , V_3 , 1 ) == - 1 ) {
F_5 ( V_4 ) ;
return ( - 1 ) ;
}
# else
V_4 = V_1 ;
# endif
return ( V_4 ) ;
}
static void F_9 ( int V_1 )
{
# ifndef F_7
F_5 ( V_1 ) ;
# endif
}
static int F_10 ( void )
{
static int V_1 = - 1 ;
if ( V_1 == - 1 )
V_1 = F_6 () ;
return V_1 ;
}
static int F_11 ( const int * * V_6 )
{
static int V_7 [ V_8 ] ;
struct V_9 V_10 ;
int V_1 , V_11 , V_12 = 0 ;
if ( ( V_1 = F_6 () ) < 0 ) {
* V_6 = NULL ;
return ( 0 ) ;
}
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . V_13 = ( V_14 ) L_2 ;
for ( V_11 = 0 ; V_15 [ V_11 ] . V_16 && V_12 < V_8 ; V_11 ++ ) {
if ( V_15 [ V_11 ] . V_17 == V_18 )
continue;
V_10 . V_19 = V_15 [ V_11 ] . V_16 ;
V_10 . V_20 = V_15 [ V_11 ] . V_20 ;
V_10 . V_21 = 0 ;
if ( F_8 ( V_1 , V_22 , & V_10 ) != - 1 &&
F_8 ( V_1 , V_23 , & V_10 . V_24 ) != - 1 )
V_7 [ V_12 ++ ] = V_15 [ V_11 ] . V_17 ;
}
F_9 ( V_1 ) ;
if ( V_12 > 0 )
* V_6 = V_7 ;
else
* V_6 = NULL ;
return ( V_12 ) ;
}
static int F_12 ( const int * * V_6 )
{
static int V_7 [ V_8 ] ;
struct V_9 V_10 ;
int V_1 , V_11 , V_12 = 0 ;
if ( ( V_1 = F_6 () ) < 0 ) {
* V_6 = NULL ;
return ( 0 ) ;
}
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . V_25 = ( V_14 ) L_2 ;
for ( V_11 = 0 ; V_26 [ V_11 ] . V_16 && V_12 < V_8 ; V_11 ++ ) {
if ( V_26 [ V_11 ] . V_17 == V_18 )
continue;
V_10 . V_21 = V_26 [ V_11 ] . V_16 ;
V_10 . V_27 = V_26 [ V_11 ] . V_20 ;
V_10 . V_19 = 0 ;
if ( F_8 ( V_1 , V_22 , & V_10 ) != - 1 &&
F_8 ( V_1 , V_23 , & V_10 . V_24 ) != - 1 )
V_7 [ V_12 ++ ] = V_26 [ V_11 ] . V_17 ;
}
F_9 ( V_1 ) ;
if ( V_12 > 0 )
* V_6 = V_7 ;
else
* V_6 = NULL ;
return ( V_12 ) ;
}
static int F_13 ( const int * * V_7 )
{
return ( F_11 ( V_7 ) ) ;
}
static int F_14 ( const int * * V_7 )
{
# ifdef F_15
return ( F_12 ( V_7 ) ) ;
# else
* V_7 = NULL ;
return ( 0 ) ;
# endif
}
static int
F_16 ( T_1 * V_28 , unsigned char * V_29 ,
const unsigned char * V_30 , T_2 V_31 )
{
struct V_32 V_33 ;
struct V_34 * V_35 = F_17 ( V_28 ) ;
struct V_9 * V_10 = & V_35 -> V_36 ;
const void * V_37 ;
unsigned char V_38 [ V_39 ] ;
if ( V_35 -> V_40 < 0 )
return ( 0 ) ;
if ( ! V_31 )
return ( 1 ) ;
if ( ( V_31 % F_18 ( V_28 ) ) != 0 )
return ( 0 ) ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_24 = V_10 -> V_24 ;
V_33 . V_41 = 0 ;
V_33 . V_42 = V_31 ;
V_33 . V_43 = ( V_14 ) V_30 ;
V_33 . V_44 = ( V_14 ) V_29 ;
V_33 . V_21 = 0 ;
V_33 . V_45 = F_19 ( V_28 ) ? V_46 : V_47 ;
if ( F_20 ( V_28 ) > 0 ) {
V_33 . V_48 = ( V_14 ) F_21 ( V_28 ) ;
if ( ! F_19 ( V_28 ) ) {
V_37 = V_30 + V_31 - F_20 ( V_28 ) ;
memcpy ( V_38 , V_37 , F_20 ( V_28 ) ) ;
}
} else
V_33 . V_48 = NULL ;
if ( F_8 ( V_35 -> V_40 , V_49 , & V_33 ) == - 1 ) {
return ( 0 ) ;
}
if ( F_20 ( V_28 ) > 0 ) {
if ( F_19 ( V_28 ) )
V_37 = V_29 + V_31 - F_20 ( V_28 ) ;
else
V_37 = V_38 ;
memcpy ( F_22 ( V_28 ) , V_37 ,
F_20 ( V_28 ) ) ;
}
return ( 1 ) ;
}
static int
F_23 ( T_1 * V_28 , const unsigned char * V_13 ,
const unsigned char * V_48 , int V_50 )
{
struct V_34 * V_35 = F_17 ( V_28 ) ;
struct V_9 * V_10 = & V_35 -> V_36 ;
int V_19 = - 1 , V_11 ;
for ( V_11 = 0 ; V_15 [ V_11 ] . V_16 ; V_11 ++ )
if ( F_24 ( V_28 ) == V_15 [ V_11 ] . V_17 &&
F_20 ( V_28 ) <= V_15 [ V_11 ] . V_51 &&
F_25 ( V_28 ) == V_15 [ V_11 ] . V_20 ) {
V_19 = V_15 [ V_11 ] . V_16 ;
break;
}
if ( ! V_15 [ V_11 ] . V_16 ) {
V_35 -> V_40 = - 1 ;
return ( 0 ) ;
}
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
if ( ( V_35 -> V_40 = F_6 () ) < 0 )
return ( 0 ) ;
V_10 -> V_13 = ( V_14 ) V_13 ;
V_10 -> V_20 = F_25 ( V_28 ) ;
V_10 -> V_19 = V_19 ;
if ( F_8 ( V_35 -> V_40 , V_22 , V_10 ) == - 1 ) {
F_9 ( V_35 -> V_40 ) ;
V_35 -> V_40 = - 1 ;
return ( 0 ) ;
}
return ( 1 ) ;
}
static int F_26 ( T_1 * V_28 )
{
int V_52 = 0 ;
struct V_34 * V_35 = F_17 ( V_28 ) ;
struct V_9 * V_10 = & V_35 -> V_36 ;
if ( V_35 -> V_40 < 0 )
return ( 0 ) ;
if ( F_8 ( V_35 -> V_40 , V_23 , & V_10 -> V_24 ) == - 1 ) {
V_52 = 0 ;
} else {
V_52 = 1 ;
}
F_9 ( V_35 -> V_40 ) ;
V_35 -> V_40 = - 1 ;
return ( V_52 ) ;
}
static const T_3 * F_27 ( void )
{
if ( V_53 == NULL ) {
T_3 * V_19 ;
if ( ( V_19 = F_28 ( V_54 , 1 , 16 ) ) == NULL
|| ! F_29 ( V_19 , 0 )
|| ! F_30 ( V_19 , V_55 )
|| ! F_31 ( V_19 , F_23 )
|| ! F_32 ( V_19 , F_16 )
|| ! F_33 ( V_19 , F_26 )
|| ! F_34 ( V_19 , sizeof( struct V_34 ) ) ) {
F_35 ( V_19 ) ;
V_19 = NULL ;
}
V_53 = V_19 ;
}
return V_53 ;
}
static const T_3 * F_36 ( void )
{
if ( V_56 == NULL ) {
T_3 * V_19 ;
if ( ( V_19 = F_28 ( V_57 , 8 , 8 ) ) == NULL
|| ! F_29 ( V_19 , 8 )
|| ! F_30 ( V_19 , V_58 )
|| ! F_31 ( V_19 , F_23 )
|| ! F_32 ( V_19 , F_16 )
|| ! F_33 ( V_19 , F_26 )
|| ! F_34 ( V_19 , sizeof( struct V_34 ) )
|| ! F_37 ( V_19 , V_59 )
|| ! F_38 ( V_19 , V_60 ) ) {
F_35 ( V_19 ) ;
V_19 = NULL ;
}
V_56 = V_19 ;
}
return V_56 ;
}
static const T_3 * F_39 ( void )
{
if ( V_61 == NULL ) {
T_3 * V_19 ;
if ( ( V_19 = F_28 ( V_62 , 8 , 24 ) ) == NULL
|| ! F_29 ( V_19 , 8 )
|| ! F_30 ( V_19 , V_58 )
|| ! F_31 ( V_19 , F_23 )
|| ! F_32 ( V_19 , F_16 )
|| ! F_33 ( V_19 , F_26 )
|| ! F_34 ( V_19 , sizeof( struct V_34 ) )
|| ! F_37 ( V_19 , V_59 )
|| ! F_38 ( V_19 , V_60 ) ) {
F_35 ( V_19 ) ;
V_19 = NULL ;
}
V_61 = V_19 ;
}
return V_61 ;
}
static const T_3 * F_40 ( void )
{
if ( V_63 == NULL ) {
T_3 * V_19 ;
if ( ( V_19 = F_28 ( V_64 , 8 , 16 ) ) == NULL
|| ! F_29 ( V_19 , 8 )
|| ! F_30 ( V_19 , V_58 )
|| ! F_31 ( V_19 , F_23 )
|| ! F_32 ( V_19 , F_16 )
|| ! F_33 ( V_19 , F_26 )
|| ! F_34 ( V_19 , sizeof( struct V_34 ) )
|| ! F_37 ( V_19 , V_59 )
|| ! F_38 ( V_19 , V_60 ) ) {
F_35 ( V_19 ) ;
V_19 = NULL ;
}
V_63 = V_19 ;
}
return V_63 ;
}
static const T_3 * F_41 ( void )
{
if ( V_65 == NULL ) {
T_3 * V_19 ;
if ( ( V_19 = F_28 ( V_66 , 8 , 16 ) ) == NULL
|| ! F_29 ( V_19 , 8 )
|| ! F_30 ( V_19 , V_58 )
|| ! F_31 ( V_19 , F_23 )
|| ! F_32 ( V_19 , F_16 )
|| ! F_33 ( V_19 , F_26 )
|| ! F_34 ( V_19 , sizeof( struct V_34 ) )
|| ! F_37 ( V_19 , V_59 )
|| ! F_38 ( V_19 , V_60 ) ) {
F_35 ( V_19 ) ;
V_19 = NULL ;
}
V_65 = V_19 ;
}
return V_65 ;
}
static const T_3 * F_42 ( void )
{
if ( V_67 == NULL ) {
T_3 * V_19 ;
if ( ( V_19 = F_28 ( V_68 , 16 , 16 ) ) == NULL
|| ! F_29 ( V_19 , 16 )
|| ! F_30 ( V_19 , V_58 )
|| ! F_31 ( V_19 , F_23 )
|| ! F_32 ( V_19 , F_16 )
|| ! F_33 ( V_19 , F_26 )
|| ! F_34 ( V_19 , sizeof( struct V_34 ) )
|| ! F_37 ( V_19 , V_59 )
|| ! F_38 ( V_19 , V_60 ) ) {
F_35 ( V_19 ) ;
V_19 = NULL ;
}
V_67 = V_19 ;
}
return V_67 ;
}
static const T_3 * F_43 ( void )
{
if ( V_69 == NULL ) {
T_3 * V_19 ;
if ( ( V_19 = F_28 ( V_70 , 16 , 24 ) ) == NULL
|| ! F_29 ( V_19 , 16 )
|| ! F_30 ( V_19 , V_58 )
|| ! F_31 ( V_19 , F_23 )
|| ! F_32 ( V_19 , F_16 )
|| ! F_33 ( V_19 , F_26 )
|| ! F_34 ( V_19 , sizeof( struct V_34 ) )
|| ! F_37 ( V_19 , V_59 )
|| ! F_38 ( V_19 , V_60 ) ) {
F_35 ( V_19 ) ;
V_19 = NULL ;
}
V_69 = V_19 ;
}
return V_69 ;
}
static const T_3 * F_44 ( void )
{
if ( V_71 == NULL ) {
T_3 * V_19 ;
if ( ( V_19 = F_28 ( V_72 , 16 , 32 ) ) == NULL
|| ! F_29 ( V_19 , 16 )
|| ! F_30 ( V_19 , V_58 )
|| ! F_31 ( V_19 , F_23 )
|| ! F_32 ( V_19 , F_16 )
|| ! F_33 ( V_19 , F_26 )
|| ! F_34 ( V_19 , sizeof( struct V_34 ) )
|| ! F_37 ( V_19 , V_59 )
|| ! F_38 ( V_19 , V_60 ) ) {
F_35 ( V_19 ) ;
V_19 = NULL ;
}
V_71 = V_19 ;
}
return V_71 ;
}
static const T_3 * F_45 ( void )
{
if ( V_73 == NULL ) {
T_3 * V_19 ;
if ( ( V_19 = F_28 ( V_74 , 16 , 16 ) ) == NULL
|| ! F_29 ( V_19 , 14 )
|| ! F_30 ( V_19 , V_75 )
|| ! F_31 ( V_19 , F_23 )
|| ! F_32 ( V_19 , F_16 )
|| ! F_33 ( V_19 , F_26 )
|| ! F_34 ( V_19 , sizeof( struct V_34 ) )
|| ! F_37 ( V_19 , V_59 )
|| ! F_38 ( V_19 , V_60 ) ) {
F_35 ( V_19 ) ;
V_19 = NULL ;
}
V_73 = V_19 ;
}
return V_73 ;
}
static const T_3 * F_46 ( void )
{
if ( V_76 == NULL ) {
T_3 * V_19 ;
if ( ( V_19 = F_28 ( V_77 , 16 , 24 ) ) == NULL
|| ! F_29 ( V_19 , 14 )
|| ! F_30 ( V_19 , V_75 )
|| ! F_31 ( V_19 , F_23 )
|| ! F_32 ( V_19 , F_16 )
|| ! F_33 ( V_19 , F_26 )
|| ! F_34 ( V_19 , sizeof( struct V_34 ) )
|| ! F_37 ( V_19 , V_59 )
|| ! F_38 ( V_19 , V_60 ) ) {
F_35 ( V_19 ) ;
V_19 = NULL ;
}
V_76 = V_19 ;
}
return V_76 ;
}
static const T_3 * F_47 ( void )
{
if ( V_78 == NULL ) {
T_3 * V_19 ;
if ( ( V_19 = F_28 ( V_79 , 16 , 32 ) ) == NULL
|| ! F_29 ( V_19 , 14 )
|| ! F_30 ( V_19 , V_75 )
|| ! F_31 ( V_19 , F_23 )
|| ! F_32 ( V_19 , F_16 )
|| ! F_33 ( V_19 , F_26 )
|| ! F_34 ( V_19 , sizeof( struct V_34 ) )
|| ! F_37 ( V_19 , V_59 )
|| ! F_38 ( V_19 , V_60 ) ) {
F_35 ( V_19 ) ;
V_19 = NULL ;
}
V_78 = V_19 ;
}
return V_78 ;
}
static int
F_48 ( T_4 * V_80 , const T_3 * * V_19 ,
const int * * V_7 , int V_17 )
{
if ( ! V_19 )
return ( F_13 ( V_7 ) ) ;
switch ( V_17 ) {
case V_54 :
* V_19 = F_27 () ;
break;
case V_62 :
* V_19 = F_39 () ;
break;
case V_57 :
* V_19 = F_36 () ;
break;
case V_64 :
* V_19 = F_40 () ;
break;
case V_66 :
* V_19 = F_41 () ;
break;
case V_68 :
* V_19 = F_42 () ;
break;
case V_70 :
* V_19 = F_43 () ;
break;
case V_72 :
* V_19 = F_44 () ;
break;
# ifdef F_49
case V_74 :
* V_19 = F_45 () ;
break;
case V_77 :
* V_19 = F_50 () ;
break;
case V_79 :
* V_19 = F_51 () ;
break;
# endif
default:
* V_19 = NULL ;
break;
}
return ( * V_19 != NULL ) ;
}
static int F_52 ( int V_17 )
{
int V_11 ;
for ( V_11 = 0 ; V_26 [ V_11 ] . V_16 ; V_11 ++ )
if ( V_26 [ V_11 ] . V_17 == V_17 )
return ( V_26 [ V_11 ] . V_16 ) ;
return ( 0 ) ;
}
static int F_53 ( int V_17 )
{
int V_11 ;
for ( V_11 = 0 ; V_26 [ V_11 ] . V_16 ; V_11 ++ )
if ( V_26 [ V_11 ] . V_17 == V_17 )
return V_26 [ V_11 ] . V_20 ;
return ( 0 ) ;
}
static int F_54 ( T_5 * V_28 )
{
struct V_34 * V_35 = F_55 ( V_28 ) ;
struct V_9 * V_10 = & V_35 -> V_36 ;
int V_81 ;
if ( ( V_81 = F_52 ( F_56 ( V_28 ) ) ) == V_18 ) {
printf ( L_3 ) ;
return ( 0 ) ;
}
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
if ( ( V_35 -> V_40 = F_6 () ) < 0 ) {
printf ( L_4 ) ;
return ( 0 ) ;
}
V_10 -> V_25 = V_35 -> V_82 ;
V_10 -> V_27 = F_53 ( F_56 ( V_28 ) ) ;
V_10 -> V_21 = V_81 ;
if ( F_8 ( V_35 -> V_40 , V_22 , V_10 ) < 0 ) {
F_9 ( V_35 -> V_40 ) ;
V_35 -> V_40 = - 1 ;
printf ( L_5 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
static int F_57 ( T_5 * V_28 , const void * V_83 ,
T_2 V_12 )
{
struct V_32 V_33 ;
struct V_34 * V_35 = F_55 ( V_28 ) ;
struct V_9 * V_10 = & V_35 -> V_36 ;
char * V_84 ;
if ( ! V_83 || V_35 -> V_40 < 0 ) {
printf ( L_6 ) ;
return ( 0 ) ;
}
if ( ! V_12 ) {
return ( 0 ) ;
}
if ( ! F_58 ( V_28 , V_85 ) ) {
V_84 =
F_59 ( V_35 -> V_86 , V_35 -> V_87 + V_12 ) ;
if ( ! V_84 ) {
printf ( L_7 ) ;
return ( 0 ) ;
}
V_35 -> V_86 = V_84 ;
memcpy ( V_35 -> V_86 + V_35 -> V_87 , V_83 , V_12 ) ;
V_35 -> V_87 += V_12 ;
return ( 1 ) ;
}
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_24 = V_10 -> V_24 ;
V_33 . V_41 = 0 ;
V_33 . V_42 = V_12 ;
V_33 . V_43 = ( V_14 ) V_83 ;
V_33 . V_44 = NULL ;
V_33 . V_21 = ( V_14 ) V_35 -> V_88 ;
if ( F_8 ( V_35 -> V_40 , V_49 , & V_33 ) < 0 ) {
printf ( L_8 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
static int F_60 ( T_5 * V_28 , unsigned char * V_89 )
{
struct V_32 V_33 ;
struct V_34 * V_35 = F_55 ( V_28 ) ;
struct V_9 * V_10 = & V_35 -> V_36 ;
int V_52 = 1 ;
if ( ! V_89 || V_35 -> V_40 < 0 ) {
printf ( L_9 ) ;
return ( 0 ) ;
}
if ( ! F_58 ( V_28 , V_85 ) ) {
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_24 = V_10 -> V_24 ;
V_33 . V_41 = 0 ;
V_33 . V_42 = V_35 -> V_87 ;
V_33 . V_43 = V_35 -> V_86 ;
V_33 . V_44 = NULL ;
V_33 . V_21 = ( V_14 ) V_89 ;
if ( F_8 ( V_35 -> V_40 , V_49 , & V_33 ) < 0 ) {
printf ( L_10 ) ;
return ( 0 ) ;
}
return 1 ;
}
memcpy ( V_89 , V_35 -> V_88 , F_61 ( V_28 ) ) ;
return ( V_52 ) ;
}
static int F_62 ( T_5 * V_28 )
{
int V_52 = 1 ;
struct V_34 * V_35 = F_55 ( V_28 ) ;
struct V_9 * V_10 = & V_35 -> V_36 ;
if ( V_35 == NULL )
return 0 ;
if ( V_35 -> V_40 < 0 ) {
printf ( L_11 ) ;
return ( 0 ) ;
}
F_63 ( V_35 -> V_86 ) ;
V_35 -> V_86 = NULL ;
V_35 -> V_87 = 0 ;
if ( F_8 ( V_35 -> V_40 , V_23 , & V_10 -> V_24 ) < 0 ) {
printf ( L_12 ) ;
V_52 = 0 ;
} else {
V_52 = 1 ;
}
F_9 ( V_35 -> V_40 ) ;
V_35 -> V_40 = - 1 ;
return ( V_52 ) ;
}
static int F_64 ( T_5 * V_90 , const T_5 * V_91 )
{
struct V_34 * V_92 = F_55 ( V_91 ) ;
struct V_34 * V_93 = F_55 ( V_90 ) ;
struct V_9 * V_10 ;
int V_81 ;
if ( V_93 == NULL || V_92 == NULL )
return 1 ;
memcpy ( V_93 , V_92 , sizeof( struct V_34 ) ) ;
V_10 = & V_93 -> V_36 ;
V_81 = F_52 ( F_56 ( V_90 ) ) ;
V_10 -> V_25 = V_93 -> V_82 ;
V_10 -> V_27 = F_53 ( F_56 ( V_90 ) ) ;
V_10 -> V_21 = V_81 ;
V_93 -> V_40 = F_6 () ;
if ( F_8 ( V_93 -> V_40 , V_22 , V_10 ) < 0 ) {
F_9 ( V_93 -> V_40 ) ;
V_93 -> V_40 = - 1 ;
printf ( L_13 ) ;
return ( 0 ) ;
}
if ( V_92 -> V_87 != 0 ) {
if ( V_92 -> V_86 != NULL ) {
V_93 -> V_86 = F_65 ( V_92 -> V_87 ) ;
if ( V_93 -> V_86 == NULL ) {
printf ( L_14 ) ;
return ( 0 ) ;
}
memcpy ( V_93 -> V_86 , V_92 -> V_86 , V_92 -> V_87 ) ;
V_93 -> V_87 = V_92 -> V_87 ;
}
}
return 1 ;
}
static const T_6 * F_66 ( void )
{
if ( V_94 == NULL ) {
T_6 * V_89 ;
if ( ( V_89 = F_67 ( V_95 , V_18 ) ) == NULL
|| ! F_68 ( V_89 , V_96 )
|| ! F_69 ( V_89 , V_97 )
|| ! F_70 ( V_89 , V_98 )
|| ! F_71 ( V_89 ,
sizeof( struct V_34 ) )
|| ! F_72 ( V_89 , F_54 )
|| ! F_73 ( V_89 , F_57 )
|| ! F_74 ( V_89 , F_60 )
|| ! F_75 ( V_89 , F_64 )
|| ! F_76 ( V_89 , F_62 ) ) {
F_77 ( V_89 ) ;
V_89 = NULL ;
}
V_94 = V_89 ;
}
return V_94 ;
}
static const T_6 * F_78 ( void )
{
if ( V_99 == NULL ) {
T_6 * V_89 ;
if ( ( V_89 = F_67 ( V_100 , V_18 ) ) == NULL
|| ! F_68 ( V_89 , 16 )
|| ! F_69 ( V_89 , V_97 )
|| ! F_70 ( V_89 , 64 )
|| ! F_71 ( V_89 ,
sizeof( struct V_34 ) )
|| ! F_72 ( V_89 , F_54 )
|| ! F_73 ( V_89 , F_57 )
|| ! F_74 ( V_89 , F_60 )
|| ! F_75 ( V_89 , F_64 )
|| ! F_76 ( V_89 , F_62 ) ) {
F_77 ( V_89 ) ;
V_89 = NULL ;
}
V_99 = V_89 ;
}
return V_99 ;
}
static int
F_79 ( T_4 * V_80 , const T_6 * * V_81 ,
const int * * V_7 , int V_17 )
{
if ( ! V_81 )
return ( F_14 ( V_7 ) ) ;
switch ( V_17 ) {
# ifdef F_15
case V_100 :
* V_81 = F_78 () ;
break;
case V_95 :
* V_81 = F_66 () ;
break;
default:
# endif
* V_81 = NULL ;
break;
}
return ( * V_81 != NULL ) ;
}
static int F_80 ( T_4 * V_80 )
{
F_35 ( V_53 ) ;
V_53 = NULL ;
F_35 ( V_56 ) ;
V_56 = NULL ;
F_35 ( V_61 ) ;
V_61 = NULL ;
F_35 ( V_63 ) ;
V_63 = NULL ;
F_35 ( V_65 ) ;
V_65 = NULL ;
F_35 ( V_67 ) ;
V_67 = NULL ;
F_35 ( V_69 ) ;
V_69 = NULL ;
F_35 ( V_71 ) ;
V_71 = NULL ;
# ifdef F_49
F_35 ( V_73 ) ;
V_73 = NULL ;
F_35 ( V_76 ) ;
V_76 = NULL ;
F_35 ( V_78 ) ;
V_78 = NULL ;
# endif
# ifdef F_15
F_77 ( V_94 ) ;
V_94 = NULL ;
F_77 ( V_99 ) ;
V_99 = NULL ;
# endif
F_81 ( V_101 ) ;
V_101 = NULL ;
#ifndef F_82
F_83 ( V_102 ) ;
V_102 = NULL ;
#endif
#ifndef F_84
F_85 ( V_103 ) ;
V_103 = NULL ;
#endif
return 1 ;
}
static int F_86 ( const T_7 * V_104 , struct V_105 * V_106 )
{
T_8 V_107 , V_108 ;
T_9 * V_109 ;
V_106 -> V_110 = NULL ;
V_106 -> V_111 = 0 ;
V_108 = F_87 ( V_104 ) ;
V_107 = F_88 ( V_104 ) ;
V_109 = F_89 ( V_107 ) ;
if ( V_109 == NULL )
return ( 1 ) ;
V_106 -> V_110 = ( V_14 ) V_109 ;
V_106 -> V_111 = V_108 ;
F_90 ( V_104 , V_109 ) ;
return ( 0 ) ;
}
static int F_91 ( struct V_105 * V_106 , T_7 * V_104 )
{
T_10 * V_112 ;
int V_11 , V_107 ;
V_107 = ( V_106 -> V_111 + 7 ) / 8 ;
if ( V_107 == 0 )
return ( - 1 ) ;
if ( ( V_112 = F_65 ( V_107 ) ) == NULL )
return ( - 1 ) ;
for ( V_11 = 0 ; V_11 < V_107 ; V_11 ++ )
V_112 [ V_11 ] = V_106 -> V_110 [ V_107 - V_11 - 1 ] ;
F_92 ( V_112 , V_107 , V_104 ) ;
free ( V_112 ) ;
return ( 0 ) ;
}
static void F_93 ( struct V_113 * V_114 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_114 -> V_115 + V_114 -> V_116 ; V_11 ++ ) {
F_63 ( V_114 -> V_117 [ V_11 ] . V_110 ) ;
V_114 -> V_117 [ V_11 ] . V_110 = NULL ;
V_114 -> V_117 [ V_11 ] . V_111 = 0 ;
}
}
static int
F_94 ( struct V_113 * V_114 , int V_118 , T_7 * V_119 , int V_120 ,
T_7 * V_121 )
{
int V_1 , V_52 = - 1 ;
if ( ( V_1 = F_10 () ) < 0 )
return V_52 ;
if ( V_119 ) {
V_114 -> V_117 [ V_114 -> V_115 ] . V_110 = F_89 ( V_118 ) ;
if ( V_114 -> V_117 [ V_114 -> V_115 ] . V_110 == NULL )
return V_52 ;
V_114 -> V_117 [ V_114 -> V_115 ] . V_111 = V_118 * 8 ;
V_114 -> V_116 ++ ;
}
if ( V_121 ) {
V_114 -> V_117 [ V_114 -> V_115 + 1 ] . V_110 =
F_89 ( V_120 ) ;
if ( V_114 -> V_117 [ V_114 -> V_115 + 1 ] . V_110 == NULL )
return V_52 ;
V_114 -> V_117 [ V_114 -> V_115 + 1 ] . V_111 = V_120 * 8 ;
V_114 -> V_116 ++ ;
}
if ( F_8 ( V_1 , V_122 , V_114 ) == 0 ) {
if ( V_119 )
F_91 ( & V_114 -> V_117 [ V_114 -> V_115 ] , V_119 ) ;
if ( V_121 )
F_91 ( & V_114 -> V_117 [ V_114 -> V_115 + 1 ] , V_121 ) ;
V_52 = 0 ;
}
return V_52 ;
}
static int
F_95 ( T_7 * V_119 , const T_7 * V_104 , const T_7 * V_123 ,
const T_7 * V_124 , T_11 * V_28 , T_12 * V_125 )
{
struct V_113 V_114 ;
int V_52 = 1 ;
if ( V_126 == 0 ) {
V_52 = F_96 ( V_119 , V_104 , V_123 , V_124 , V_28 ) ;
return ( V_52 ) ;
}
memset ( & V_114 , 0 , sizeof( V_114 ) ) ;
V_114 . V_127 = V_128 ;
if ( F_86 ( V_104 , & V_114 . V_117 [ 0 ] ) )
goto V_129;
if ( F_86 ( V_123 , & V_114 . V_117 [ 1 ] ) )
goto V_129;
if ( F_86 ( V_124 , & V_114 . V_117 [ 2 ] ) )
goto V_129;
V_114 . V_115 = 3 ;
if ( F_94 ( & V_114 , F_88 ( V_124 ) , V_119 , 0 , NULL ) ) {
const T_13 * V_130 = F_97 () ;
printf ( L_15 ) ;
V_52 = F_98 ( V_130 ) ( V_119 , V_104 , V_123 , V_124 , V_28 , V_125 ) ;
} else if ( V_131 == V_114 . V_132 ) {
const T_13 * V_130 = F_97 () ;
printf ( L_16 ) ;
V_52 = F_98 ( V_130 ) ( V_119 , V_104 , V_123 , V_124 , V_28 , V_125 ) ;
}
V_129:
F_93 ( & V_114 ) ;
return ( V_52 ) ;
}
static int
F_99 ( T_7 * V_133 , const T_7 * V_134 , T_14 * V_135 ,
T_11 * V_28 )
{
int V_119 ;
const T_7 * V_136 = NULL ;
const T_7 * V_137 = NULL ;
V_28 = F_100 () ;
F_101 ( V_135 , & V_136 , NULL , & V_137 ) ;
V_119 = F_95 ( V_133 , V_134 , V_137 , V_136 , V_28 , NULL ) ;
F_102 ( V_28 ) ;
return ( V_119 ) ;
}
static int
F_103 ( T_7 * V_133 , const T_7 * V_134 , T_14 * V_135 , T_11 * V_28 )
{
struct V_113 V_114 ;
int V_52 = 1 ;
const T_7 * V_123 = NULL ;
const T_7 * V_138 = NULL ;
const T_7 * V_139 = NULL ;
const T_7 * V_140 = NULL ;
const T_7 * V_141 = NULL ;
const T_7 * V_136 = NULL ;
F_104 ( V_135 , & V_123 , & V_138 ) ;
F_105 ( V_135 , & V_139 , & V_140 , & V_141 ) ;
F_101 ( V_135 , & V_136 , NULL , NULL ) ;
if ( ! V_123 || ! V_138 || ! V_139 || ! V_140 || ! V_141 ) {
return ( 0 ) ;
}
memset ( & V_114 , 0 , sizeof( V_114 ) ) ;
V_114 . V_127 = V_142 ;
if ( F_86 ( V_123 , & V_114 . V_117 [ 0 ] ) )
goto V_129;
if ( F_86 ( V_138 , & V_114 . V_117 [ 1 ] ) )
goto V_129;
if ( F_86 ( V_134 , & V_114 . V_117 [ 2 ] ) )
goto V_129;
if ( F_86 ( V_139 , & V_114 . V_117 [ 3 ] ) )
goto V_129;
if ( F_86 ( V_140 , & V_114 . V_117 [ 4 ] ) )
goto V_129;
if ( F_86 ( V_141 , & V_114 . V_117 [ 5 ] ) )
goto V_129;
V_114 . V_115 = 6 ;
if ( F_94 ( & V_114 , F_88 ( V_136 ) , V_133 , 0 , NULL ) ) {
const T_13 * V_130 = F_97 () ;
printf ( L_17 ) ;
V_52 = F_106 ( V_130 ) ( V_133 , V_134 , V_135 , V_28 ) ;
} else if ( V_131 == V_114 . V_132 ) {
const T_13 * V_130 = F_97 () ;
printf ( L_16 ) ;
V_52 = F_106 ( V_130 ) ( V_133 , V_134 , V_135 , V_28 ) ;
}
V_129:
F_93 ( & V_114 ) ;
return ( V_52 ) ;
}
static int
F_107 ( T_15 * V_143 , T_7 * V_119 , const T_7 * V_104 , const T_7 * V_123 ,
const T_7 * V_124 , T_11 * V_28 , T_12 * V_144 )
{
return F_95 ( V_119 , V_104 , V_123 , V_124 , V_28 , V_144 ) ;
}
static int
F_108 ( T_15 * V_143 , T_7 * V_145 , const T_7 * V_146 ,
const T_7 * V_147 , const T_7 * V_148 ,
const T_7 * V_149 , const T_7 * V_123 , T_11 * V_28 ,
T_12 * V_150 )
{
const T_7 * V_151 , * V_152 , * V_153 ;
T_7 * V_154 ;
int V_52 = 0 ;
const T_16 * V_130 ;
int (* F_109)( T_15 * , T_7 * , const T_7 * , const T_7 * , const T_7 * ,
T_11 * , T_12 * );
V_154 = F_110 () ;
if ( V_154 == NULL )
goto V_129;
V_52 = 0 ;
F_111 ( V_143 , & V_152 , NULL , & V_151 ) ;
F_112 ( V_143 , & V_153 , NULL ) ;
V_130 = F_113 ( V_143 ) ;
if ( V_130 == NULL )
goto V_129;
F_109 = F_114 ( V_130 ) ;
if ( F_109 == NULL )
goto V_129;
if ( ! F_109 ( V_143 , V_145 , V_151 , V_147 , V_152 , V_28 , V_150 ) )
goto V_129;
if ( ! F_109 ( V_143 , V_154 , V_153 , V_149 , V_152 , V_28 , V_150 ) )
goto V_129;
if ( ! F_115 ( V_145 , V_145 , V_154 , V_152 , V_28 ) )
goto V_129;
V_52 = 1 ;
V_129:
F_116 ( V_154 ) ;
return ( V_52 ) ;
}
static T_17 * F_117 ( const unsigned char * V_155 , int V_156 ,
T_15 * V_143 )
{
struct V_113 V_114 ;
T_7 * V_119 , * V_121 ;
const T_7 * V_152 = NULL , * V_157 = NULL , * V_151 = NULL ;
const T_7 * V_158 = NULL ;
T_17 * V_159 , * V_160 = NULL ;
V_159 = F_118 () ;
if ( V_159 == NULL )
goto V_129;
memset ( & V_114 , 0 , sizeof( V_114 ) ) ;
V_114 . V_127 = V_161 ;
V_114 . V_117 [ 0 ] . V_110 = ( V_14 ) V_155 ;
V_114 . V_117 [ 0 ] . V_111 = V_156 * 8 ;
F_111 ( V_143 , & V_152 , & V_157 , & V_151 ) ;
F_112 ( V_143 , NULL , & V_158 ) ;
if ( F_86 ( V_152 , & V_114 . V_117 [ 1 ] ) )
goto V_129;
if ( F_86 ( V_157 , & V_114 . V_117 [ 2 ] ) )
goto V_129;
if ( F_86 ( V_151 , & V_114 . V_117 [ 3 ] ) )
goto V_129;
if ( F_86 ( V_158 , & V_114 . V_117 [ 4 ] ) )
goto V_129;
V_114 . V_115 = 5 ;
V_119 = F_110 () ;
if ( V_119 == NULL )
goto V_129;
V_121 = F_110 () ;
if ( V_121 == NULL )
goto V_129;
if ( F_94 ( & V_114 , F_88 ( V_157 ) , V_119 ,
F_88 ( V_157 ) , V_121 ) == 0 ) {
F_119 ( V_159 , V_119 , V_121 ) ;
V_160 = V_159 ;
} else {
V_160 = F_120 ( F_121 () ) ( V_155 , V_156 , V_143 ) ;
}
V_129:
if ( V_160 != V_159 )
F_122 ( V_159 ) ;
V_114 . V_117 [ 0 ] . V_110 = NULL ;
F_93 ( & V_114 ) ;
return V_160 ;
}
static int
F_123 ( const unsigned char * V_155 , int V_156 ,
T_17 * V_162 , T_15 * V_143 )
{
struct V_113 V_114 ;
int V_160 = 1 ;
const T_7 * V_163 , * V_164 , * V_123 = NULL , * V_138 = NULL , * V_146 = NULL , * V_148 = NULL ;
memset ( & V_114 , 0 , sizeof( V_114 ) ) ;
V_114 . V_127 = V_165 ;
V_114 . V_117 [ 0 ] . V_110 = ( V_14 ) V_155 ;
V_114 . V_117 [ 0 ] . V_111 = V_156 * 8 ;
F_111 ( V_143 , & V_123 , & V_138 , & V_146 ) ;
if ( F_86 ( V_123 , & V_114 . V_117 [ 1 ] ) )
goto V_129;
if ( F_86 ( V_138 , & V_114 . V_117 [ 2 ] ) )
goto V_129;
if ( F_86 ( V_146 , & V_114 . V_117 [ 3 ] ) )
goto V_129;
F_112 ( V_143 , & V_148 , NULL ) ;
if ( F_86 ( V_148 , & V_114 . V_117 [ 4 ] ) )
goto V_129;
F_124 ( V_162 , & V_163 , & V_164 ) ;
if ( F_86 ( V_163 , & V_114 . V_117 [ 5 ] ) )
goto V_129;
if ( F_86 ( V_164 , & V_114 . V_117 [ 6 ] ) )
goto V_129;
V_114 . V_115 = 7 ;
if ( F_94 ( & V_114 , 0 , NULL , 0 , NULL ) == 0 ) {
if ( 0 != V_114 . V_132 )
V_160 = 0 ;
} else {
V_160 = F_125 ( F_121 () ) ( V_155 , V_156 , V_162 , V_143 ) ;
}
V_129:
V_114 . V_117 [ 0 ] . V_110 = NULL ;
F_93 ( & V_114 ) ;
return ( V_160 ) ;
}
static int
F_126 ( const T_18 * V_166 , T_7 * V_119 , const T_7 * V_104 ,
const T_7 * V_123 , const T_7 * V_124 , T_11 * V_28 ,
T_12 * V_144 )
{
return ( F_95 ( V_119 , V_104 , V_123 , V_124 , V_28 , V_144 ) ) ;
}
static int
F_127 ( unsigned char * V_13 , const T_7 * V_148 , T_18 * V_166 )
{
struct V_113 V_114 ;
int V_167 = 1 ;
int V_1 , V_20 ;
const T_7 * V_123 = NULL ;
const T_7 * V_158 = NULL ;
if ( ( V_1 = F_10 () ) < 0 ) {
const T_19 * V_130 = F_128 () ;
return F_129 ( V_130 ) ( V_13 , V_148 , V_166 ) ;
}
F_130 ( V_166 , & V_123 , NULL , NULL ) ;
F_131 ( V_166 , NULL , & V_158 ) ;
V_20 = F_87 ( V_123 ) ;
memset ( & V_114 , 0 , sizeof( V_114 ) ) ;
V_114 . V_127 = V_168 ;
if ( F_86 ( V_158 , & V_114 . V_117 [ 0 ] ) )
goto V_129;
if ( F_86 ( V_148 , & V_114 . V_117 [ 1 ] ) )
goto V_129;
if ( F_86 ( V_123 , & V_114 . V_117 [ 2 ] ) )
goto V_129;
V_114 . V_115 = 3 ;
V_114 . V_117 [ 3 ] . V_110 = ( V_14 ) V_13 ;
V_114 . V_117 [ 3 ] . V_111 = V_20 * 8 ;
V_114 . V_116 = 1 ;
if ( F_8 ( V_1 , V_122 , & V_114 ) == - 1 ) {
const T_19 * V_130 = F_128 () ;
V_167 = F_129 ( V_130 ) ( V_13 , V_148 , V_166 ) ;
}
V_129:
V_114 . V_117 [ 3 ] . V_110 = NULL ;
F_93 ( & V_114 ) ;
return ( V_167 ) ;
}
static int
F_132 ( T_4 * V_80 , int V_169 , long V_11 , void * V_123 , void (* F_133) ( void ) )
{
# ifdef F_134
struct V_170 V_171 = V_172 ;
# endif
switch ( V_169 ) {
default:
# ifdef F_134
F_135 ( V_173 , & V_171 , L_18 , V_169 ) ;
# else
F_136 ( V_173 , L_18 , V_169 ) ;
# endif
break;
}
return ( 1 ) ;
}
void F_1 ( void )
{
T_4 * V_174 = F_137 () ;
int V_1 ;
if ( V_174 == NULL )
return;
if ( ( V_1 = F_6 () ) < 0 ) {
F_138 ( V_174 ) ;
return;
}
if ( F_8 ( V_1 , V_175 , & V_126 ) == - 1 ) {
F_9 ( V_1 ) ;
F_138 ( V_174 ) ;
return;
}
F_9 ( V_1 ) ;
if ( ! F_139 ( V_174 , L_19 ) ||
! F_140 ( V_174 , L_20 ) ||
! F_141 ( V_174 , F_80 ) ||
! F_142 ( V_174 , F_48 ) ||
! F_143 ( V_174 , F_79 ) ||
! F_144 ( V_174 , F_132 ) ||
! F_145 ( V_174 , V_176 ) ) {
F_138 ( V_174 ) ;
return;
}
V_101 = F_146 ( F_97 () ) ;
if ( V_101 != NULL ) {
F_147 ( V_101 , L_21 ) ;
F_148 ( V_101 , 0 ) ;
if ( F_149 ( V_174 , V_101 ) ) {
if ( V_126 & V_177 ) {
F_150 ( V_101 , F_95 ) ;
if ( V_126 & V_178 )
F_151 ( V_101 , F_103 ) ;
else
F_151 ( V_101 ,
F_99 ) ;
}
}
} else {
F_138 ( V_174 ) ;
return;
}
#ifndef F_82
V_102 = F_152 ( F_121 () ) ;
if ( V_102 != NULL ) {
F_153 ( V_102 , L_22 ) ;
F_154 ( V_102 , 0 ) ;
if ( F_155 ( V_174 , V_102 ) ) {
if ( V_126 & V_179 )
F_156 ( V_102 , F_117 ) ;
if ( V_126 & V_177 ) {
F_157 ( V_102 ,
F_107 ) ;
F_158 ( V_102 , F_108 ) ;
}
if ( V_126 & V_180 )
F_159 ( V_102 , F_123 ) ;
}
} else {
F_138 ( V_174 ) ;
return;
}
#endif
#ifndef F_84
V_103 = F_160 ( F_128 () ) ;
if ( V_103 != NULL ) {
F_161 ( V_103 , L_23 ) ;
F_162 ( V_103 , 0 ) ;
if ( F_163 ( V_174 , V_103 ) ) {
if ( V_126 & V_177 ) {
F_164 ( V_103 , F_126 ) ;
if ( V_126 & V_181 )
F_165 ( V_103 ,
F_127 ) ;
}
}
} else {
F_138 ( V_174 ) ;
return;
}
#endif
F_166 ( V_174 ) ;
F_138 ( V_174 ) ;
F_167 () ;
}
