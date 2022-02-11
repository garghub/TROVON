static LONG T_1 T_2 F_1 ( T_3 V_1 , T_4 V_2 , T_5 V_3 ,
T_6 V_4 )
{
if ( V_1 == V_5 ) {
switch ( V_2 ) {
case V_6 :
case V_7 :
F_2 ( V_5 , V_8 , ( LONG ) V_9 ) ;
F_3 () ;
break;
}
}
return F_4 ( V_9 , V_1 , V_2 , V_3 , V_4 ) ;
}
static BOOL T_7 F_5 ( T_3 V_1 , T_6 V_4 )
{
V_5 = V_1 ;
return ( FALSE ) ;
}
static void F_3 ( void )
{
if ( V_10 ) {
V_10 = 0 ;
# ifndef F_6
F_7 () ;
# endif
F_8 () ;
}
}
static void F_9 ( void )
{
if ( V_10 ) {
V_10 = 0 ;
F_8 () ;
}
}
static int F_10 ( void )
{
# ifdef F_11
extern int V_11 ;
V_11 = 0 ;
if ( F_12 () )
return ( 0 ) ;
# elif F_13 ( V_12 )
if ( ! V_10 ) {
int V_13 ;
# ifdef F_14
signal ( F_14 , ( void ( * ) ( int ) ) F_3 ) ;
# endif
V_10 = 1 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
if ( F_15 ( 0x0101 , & V_14 ) != 0 ) {
V_13 = F_16 () ;
F_17 ( V_15 , L_1 ,
V_13 ) ;
return ( 0 ) ;
}
# ifdef F_18
F_19 ( F_20 () , F_5 , 0L ) ;
V_9 = ( V_16 ) F_21 ( V_5 , V_8 ) ;
V_17 = F_22 ( ( V_16 ) F_1 , V_18 ) ;
F_2 ( V_5 , V_8 , ( LONG ) V_17 ) ;
# endif
}
# elif F_13 ( V_19 ) && ! F_13 ( V_20 )
T_8 V_21 ;
T_9 V_22 ;
int V_13 ;
if ( ! V_10 ) {
# ifdef F_14
signal ( F_14 , ( void ( * ) ( int ) ) F_9 ) ;
# endif
V_10 = 1 ;
V_21 = F_23 ( 2 , 0 ) ;
V_13 = F_15 ( V_21 , & V_22 ) ;
if ( V_13 != 0 ) {
F_17 ( V_15 , L_2 ,
V_13 ) ;
return ( 0 ) ;
}
}
# endif
return ( 1 ) ;
}
int F_24 ( int * V_23 , char * V_24 , int V_25 , int type )
{
unsigned char V_26 [ 4 ] ;
memset ( V_26 , '\0' , sizeof V_26 ) ;
if ( ! F_25 ( V_24 , & ( V_26 [ 0 ] ) ) )
return 0 ;
return F_26 ( V_23 , V_26 , V_25 , type ) ;
}
static int F_26 ( int * V_23 , unsigned char V_26 [ 4 ] , int V_25 , int type )
{
unsigned long V_27 ;
struct V_28 V_29 ;
int V_30 , V_31 ;
if ( ! F_10 () )
return ( 0 ) ;
memset ( ( char * ) & V_29 , 0 , sizeof( V_29 ) ) ;
V_29 . V_32 = V_33 ;
V_29 . V_34 = F_27 ( ( unsigned short ) V_25 ) ;
V_27 = ( unsigned long )
( ( unsigned long ) V_26 [ 0 ] << 24L ) |
( ( unsigned long ) V_26 [ 1 ] << 16L ) |
( ( unsigned long ) V_26 [ 2 ] << 8L ) | ( ( unsigned long ) V_26 [ 3 ] ) ;
V_29 . V_35 . V_36 = F_28 ( V_27 ) ;
if ( type == V_37 )
V_30 = F_29 ( V_33 , V_37 , V_38 ) ;
else
V_30 = F_29 ( V_33 , V_39 , V_40 ) ;
if ( V_30 == V_41 ) {
perror ( L_3 ) ;
return ( 0 ) ;
}
# if F_13 ( V_42 ) && ! F_13 ( V_43 )
if ( type == V_37 ) {
V_31 = 0 ;
V_31 = F_30 ( V_30 , V_44 , V_42 , ( char * ) & V_31 , sizeof( V_31 ) ) ;
if ( V_31 < 0 ) {
F_31 ( V_30 ) ;
perror ( L_4 ) ;
return ( 0 ) ;
}
}
# endif
if ( F_32 ( V_30 , (struct V_45 * ) & V_29 , sizeof( V_29 ) ) == - 1 ) {
F_31 ( V_30 ) ;
perror ( L_5 ) ;
return ( 0 ) ;
}
* V_23 = V_30 ;
return ( 1 ) ;
}
int F_33 ( int V_25 , int type , int * V_46 ,
int (* F_34) ( char * V_47 , int V_30 , int V_48 ,
unsigned char * V_49 ) , unsigned char * V_49 ,
int V_50 )
{
int V_23 ;
char * V_51 = NULL ;
int V_52 = 0 ;
int V_31 ;
if ( ! F_35 ( & V_52 , V_25 , type ) )
return ( 0 ) ;
if ( V_46 != NULL ) {
* V_46 = V_52 ;
}
for (; ; ) {
if ( type == V_37 ) {
if ( F_36 ( V_52 , & V_23 , & V_51 ) == 0 ) {
F_37 ( V_52 ) ;
return ( 0 ) ;
}
} else
V_23 = V_52 ;
V_31 = (* F_34) ( V_51 , V_23 , type , V_49 ) ;
if ( V_51 != NULL )
F_38 ( V_51 ) ;
if ( type == V_37 )
F_39 ( V_23 ) ;
if ( V_50 != - 1 )
V_50 -- ;
if ( V_31 < 0 || V_50 == 0 ) {
F_39 ( V_52 ) ;
return ( V_31 ) ;
}
}
}
static int F_40 ( int * V_23 , int V_25 , char * V_26 , int type )
{
int V_46 = 0 ;
struct V_28 V_53 ;
int V_30 = - 1 ;
if ( ! F_10 () )
return ( 0 ) ;
memset ( ( char * ) & V_53 , 0 , sizeof( V_53 ) ) ;
V_53 . V_32 = V_33 ;
V_53 . V_34 = F_27 ( ( unsigned short ) V_25 ) ;
if ( V_26 == NULL )
V_53 . V_35 . V_36 = V_54 ;
else
# ifndef F_41
memcpy ( & V_53 . V_35 . V_36 , V_26 , 4 ) ;
# else
memcpy ( & V_53 . V_35 , V_26 , 4 ) ;
# endif
if ( type == V_37 )
V_30 = F_29 ( V_33 , V_37 , V_38 ) ;
else
V_30 = F_29 ( V_33 , V_39 , V_40 ) ;
if ( V_30 == V_41 )
goto V_13;
# if F_13 V_44 && F_13 V_55
{
int V_56 = 1 ;
F_30 ( V_30 , V_44 , V_55 , ( void * ) & V_56 , sizeof V_56 ) ;
}
# endif
if ( F_42 ( V_30 , (struct V_45 * ) & V_53 , sizeof( V_53 ) ) == - 1 ) {
# ifndef V_12
perror ( L_6 ) ;
# endif
goto V_13;
}
if ( type == V_37 && F_43 ( V_30 , 128 ) == - 1 )
goto V_13;
* V_23 = V_30 ;
V_46 = 1 ;
V_13:
if ( ( V_46 == 0 ) && ( V_30 != - 1 ) ) {
F_37 ( V_30 ) ;
}
return ( V_46 ) ;
}
static int F_35 ( int * V_23 , int V_25 , int type )
{
return ( F_40 ( V_23 , V_25 , NULL , type ) ) ;
}
static int F_36 ( int V_57 , int * V_23 , char * * V_24 )
{
int V_46 ;
struct V_58 * V_59 , * V_60 ;
static struct V_28 V_61 ;
int V_62 ;
if ( ! F_10 () )
return ( 0 ) ;
# ifndef V_12
V_63:
# endif
memset ( ( char * ) & V_61 , 0 , sizeof( V_61 ) ) ;
V_62 = sizeof( V_61 ) ;
V_46 = F_44 ( V_57 , (struct V_45 * ) & V_61 , ( void * ) & V_62 ) ;
if ( V_46 == V_41 ) {
# if F_13 ( V_12 ) || ( F_13 ( V_19 ) && ! F_13 ( V_20 ) )
int V_31 ;
V_31 = F_16 () ;
F_17 ( V_15 , L_7 , V_31 ) ;
# else
if ( V_64 == V_65 ) {
goto V_63;
}
fprintf ( V_66 , L_8 , V_64 ) ;
perror ( L_9 ) ;
# endif
return ( 0 ) ;
}
if ( V_24 == NULL )
goto V_67;
# ifndef F_41
V_59 = F_45 ( ( char * ) & V_61 . V_35 . V_36 ,
sizeof( V_61 . V_35 . V_36 ) , V_33 ) ;
# else
V_59 = F_45 ( ( char * ) & V_61 . V_35 ,
sizeof( struct V_68 ) , V_33 ) ;
# endif
if ( V_59 == NULL ) {
F_17 ( V_15 , L_10 ) ;
* V_24 = NULL ;
} else {
if ( ( * V_24 = ( char * ) F_46 ( strlen ( V_59 -> V_69 ) + 1 ) ) == NULL ) {
perror ( L_11 ) ;
F_31 ( V_46 ) ;
return ( 0 ) ;
}
F_47 ( * V_24 , V_59 -> V_69 , strlen ( V_59 -> V_69 ) + 1 ) ;
V_60 = F_48 ( * V_24 ) ;
if ( V_60 == NULL ) {
F_17 ( V_15 , L_12 ) ;
F_31 ( V_46 ) ;
return ( 0 ) ;
}
if ( V_60 -> V_70 != V_33 ) {
F_17 ( V_15 , L_13 ) ;
F_31 ( V_46 ) ;
return ( 0 ) ;
}
}
V_67:
* V_23 = V_46 ;
return ( 1 ) ;
}
int F_49 ( char * V_71 , char * * V_72 , unsigned char * V_26 ,
short * V_73 )
{
char * V_74 , * V_75 ;
V_74 = V_71 ;
V_75 = strchr ( V_71 , ':' ) ;
if ( V_75 == NULL ) {
F_17 ( V_15 , L_14 ) ;
return ( 0 ) ;
}
* ( V_75 ++ ) = '\0' ;
if ( ( V_26 != NULL ) && ! F_25 ( V_71 , V_26 ) )
goto V_13;
if ( V_72 != NULL )
* V_72 = V_74 ;
if ( ! F_50 ( V_75 , V_73 ) )
goto V_13;
return ( 1 ) ;
V_13:
return ( 0 ) ;
}
static int F_25 ( char * V_71 , unsigned char V_26 [ 4 ] )
{
unsigned int V_76 [ 4 ] ;
int V_31 ;
if ( sscanf ( V_71 , L_15 , & ( V_76 [ 0 ] ) , & ( V_76 [ 1 ] ) , & ( V_76 [ 2 ] ) , & ( V_76 [ 3 ] ) ) ==
4 ) {
for ( V_31 = 0 ; V_31 < 4 ; V_31 ++ )
if ( V_76 [ V_31 ] > 255 ) {
F_17 ( V_15 , L_16 ) ;
goto V_13;
}
V_26 [ 0 ] = V_76 [ 0 ] ;
V_26 [ 1 ] = V_76 [ 1 ] ;
V_26 [ 2 ] = V_76 [ 2 ] ;
V_26 [ 3 ] = V_76 [ 3 ] ;
} else {
struct V_58 * V_77 ;
if ( ! F_10 () )
return ( 0 ) ;
V_77 = F_48 ( V_71 ) ;
if ( V_77 == NULL ) {
F_17 ( V_15 , L_12 ) ;
goto V_13;
}
if ( ( short ) V_77 -> V_70 != V_33 ) {
F_17 ( V_15 , L_13 ) ;
return ( 0 ) ;
}
V_26 [ 0 ] = V_77 -> V_78 [ 0 ] [ 0 ] ;
V_26 [ 1 ] = V_77 -> V_78 [ 0 ] [ 1 ] ;
V_26 [ 2 ] = V_77 -> V_78 [ 0 ] [ 2 ] ;
V_26 [ 3 ] = V_77 -> V_78 [ 0 ] [ 3 ] ;
}
return ( 1 ) ;
V_13:
return ( 0 ) ;
}
int F_50 ( char * V_71 , short * V_73 )
{
int V_31 ;
struct V_79 * V_30 ;
V_31 = atoi ( V_71 ) ;
if ( V_31 != 0 )
* V_73 = ( unsigned short ) V_31 ;
else {
V_30 = F_51 ( V_71 , L_17 ) ;
if ( V_30 == NULL ) {
F_17 ( V_15 , L_18 , V_71 ) ;
return ( 0 ) ;
}
* V_73 = F_52 ( ( unsigned short ) V_30 -> V_80 ) ;
}
return ( 1 ) ;
}
static struct V_58 * F_48 ( char * V_51 )
{
struct V_58 * V_46 ;
int V_31 , V_81 = 0 ;
unsigned long V_82 = ( unsigned long ) - 1 ;
for ( V_31 = 0 ; V_31 < V_83 ; V_31 ++ ) {
if ( V_82 > V_84 [ V_31 ] . V_85 ) {
V_82 = V_84 [ V_31 ] . V_85 ;
V_81 = V_31 ;
}
if ( V_84 [ V_31 ] . V_85 > 0 ) {
if ( strncmp ( V_51 , V_84 [ V_31 ] . V_51 , 128 ) == 0 )
break;
}
}
if ( V_31 == V_83 ) {
V_86 ++ ;
V_46 = F_53 ( V_51 ) ;
if ( V_46 == NULL )
return ( NULL ) ;
if ( strlen ( V_51 ) < sizeof V_84 [ 0 ] . V_51 ) {
strcpy ( V_84 [ V_81 ] . V_51 , V_51 ) ;
memcpy ( ( char * ) & ( V_84 [ V_81 ] . V_87 ) , V_46 ,
sizeof( struct V_58 ) ) ;
V_84 [ V_81 ] . V_85 = V_86 + V_88 ;
}
return ( V_46 ) ;
} else {
V_88 ++ ;
V_46 = & ( V_84 [ V_31 ] . V_87 ) ;
V_84 [ V_31 ] . V_85 = V_86 + V_88 ;
return ( V_46 ) ;
}
}
