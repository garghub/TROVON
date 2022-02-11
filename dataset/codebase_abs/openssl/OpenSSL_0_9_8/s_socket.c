static LONG T_1 T_2 F_1 ( T_3 V_1 , T_4 V_2 , T_5 V_3 ,
T_6 V_4 )
{
if ( V_1 == V_5 )
{
switch( V_2 )
{
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
if ( V_10 )
{
V_10 = 0 ;
#ifndef F_6
F_7 () ;
#endif
F_8 () ;
}
}
static void F_9 ( void )
{
if ( V_10 )
{
V_10 = 0 ;
F_8 () ;
}
}
static int F_10 ( void )
{
#ifdef F_11
extern int V_11 ;
V_11 = 0 ;
if ( F_12 () )
return ( 0 ) ;
#elif F_13 ( V_12 )
if ( ! V_10 )
{
int V_13 ;
#ifdef F_14
signal ( F_14 , ( void ( * ) ( int ) ) F_3 ) ;
#endif
V_10 = 1 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
if ( F_15 ( 0x0101 , & V_14 ) != 0 )
{
V_13 = F_16 () ;
F_17 ( V_15 , L_1 , V_13 ) ;
return ( 0 ) ;
}
#ifdef F_18
F_19 ( F_20 () , F_5 , 0L ) ;
V_9 = ( V_16 ) F_21 ( V_5 , V_8 ) ;
V_17 = F_22 ( ( V_16 ) F_1 , V_18 ) ;
F_2 ( V_5 , V_8 , ( LONG ) V_17 ) ;
#endif
}
#elif F_13 ( V_19 ) && ! F_13 ( V_20 )
T_8 V_21 ;
T_9 V_22 ;
int V_13 ;
if ( ! V_10 )
{
# ifdef F_14
signal ( F_14 , ( void ( * ) ( int ) ) F_9 ) ;
# endif
V_10 = 1 ;
V_21 = F_23 ( 2 , 0 ) ;
V_13 = F_15 ( V_21 , & V_22 ) ;
if ( V_13 != 0 )
{
F_17 ( V_15 , L_2 , V_13 ) ;
return ( 0 ) ;
}
}
#endif
return ( 1 ) ;
}
int F_24 ( int * V_23 , char * V_24 , int V_25 , int type )
{
unsigned char V_26 [ 4 ] ;
short V_27 = 0 ;
if ( ! F_25 ( V_24 , & ( V_26 [ 0 ] ) ) )
{
return ( 0 ) ;
}
if ( V_27 != 0 ) V_25 = V_27 ;
return ( F_26 ( V_23 , V_26 , V_25 , type ) ) ;
}
static int F_26 ( int * V_23 , unsigned char V_26 [ 4 ] , int V_25 , int type )
{
unsigned long V_28 ;
struct V_29 V_30 ;
int V_31 , V_32 ;
if ( ! F_10 () ) return ( 0 ) ;
memset ( ( char * ) & V_30 , 0 , sizeof( V_30 ) ) ;
V_30 . V_33 = V_34 ;
V_30 . V_35 = F_27 ( ( unsigned short ) V_25 ) ;
V_28 = ( unsigned long )
( ( unsigned long ) V_26 [ 0 ] << 24L ) |
( ( unsigned long ) V_26 [ 1 ] << 16L ) |
( ( unsigned long ) V_26 [ 2 ] << 8L ) |
( ( unsigned long ) V_26 [ 3 ] ) ;
V_30 . V_36 . V_37 = F_28 ( V_28 ) ;
if ( type == V_38 )
V_31 = F_29 ( V_34 , V_38 , V_39 ) ;
else
V_31 = F_29 ( V_34 , V_40 , V_41 ) ;
if ( V_31 == V_42 ) { perror ( L_3 ) ; return ( 0 ) ; }
#ifndef F_30
if ( type == V_38 )
{
V_32 = 0 ;
V_32 = F_31 ( V_31 , V_43 , V_44 , ( char * ) & V_32 , sizeof( V_32 ) ) ;
if ( V_32 < 0 ) { perror ( L_4 ) ; return ( 0 ) ; }
}
#endif
if ( F_32 ( V_31 , (struct V_45 * ) & V_30 , sizeof( V_30 ) ) == - 1 )
{ F_33 ( V_31 ) ; perror ( L_5 ) ; return ( 0 ) ; }
* V_23 = V_31 ;
return ( 1 ) ;
}
int F_34 ( int V_25 , int type , int * V_46 , int (* F_35)( char * V_47 , int V_31 , unsigned char * V_48 ) , unsigned char * V_48 )
{
int V_23 ;
char * V_49 = NULL ;
int V_50 ;
int V_32 ;
if ( ! F_36 ( & V_50 , V_25 , type ) ) return ( 0 ) ;
if ( V_46 != NULL )
{
* V_46 = V_50 ;
}
for (; ; )
{
if ( type == V_38 )
{
if ( F_37 ( V_50 , & V_23 , & V_49 ) == 0 )
{
F_38 ( V_50 ) ;
return ( 0 ) ;
}
}
else
V_23 = V_50 ;
V_32 = (* F_35)( V_49 , V_23 , V_48 ) ;
if ( V_49 != NULL ) F_39 ( V_49 ) ;
if ( type == V_38 )
F_40 ( V_23 ) ;
if ( V_32 < 0 )
{
F_40 ( V_50 ) ;
return ( V_32 ) ;
}
}
}
static int F_41 ( int * V_23 , int V_25 , char * V_26 , int type )
{
int V_46 = 0 ;
struct V_29 V_51 ;
int V_31 = - 1 , V_32 ;
if ( ! F_10 () ) return ( 0 ) ;
memset ( ( char * ) & V_51 , 0 , sizeof( V_51 ) ) ;
V_51 . V_33 = V_34 ;
V_51 . V_35 = F_27 ( ( unsigned short ) V_25 ) ;
if ( V_26 == NULL )
V_51 . V_36 . V_37 = V_52 ;
else
#ifndef F_42
memcpy ( & V_51 . V_36 . V_37 , V_26 , 4 ) ;
#else
memcpy ( & V_51 . V_36 , V_26 , 4 ) ;
#endif
if ( type == V_38 )
V_31 = F_29 ( V_34 , V_38 , V_39 ) ;
else
V_31 = F_29 ( V_34 , V_40 , V_41 ) ;
if ( V_31 == V_42 ) goto V_13;
#if F_13 V_43 && F_13 V_53
{
int V_54 = 1 ;
F_31 ( V_31 , V_43 , V_53 ,
( void * ) & V_54 , sizeof V_54 ) ;
}
#endif
if ( F_43 ( V_31 , (struct V_45 * ) & V_51 , sizeof( V_51 ) ) == - 1 )
{
#ifndef V_12
perror ( L_6 ) ;
#endif
goto V_13;
}
if ( type == V_38 && F_44 ( V_31 , 128 ) == - 1 ) goto V_13;
V_32 = 0 ;
* V_23 = V_31 ;
V_46 = 1 ;
V_13:
if ( ( V_46 == 0 ) && ( V_31 != - 1 ) )
{
F_38 ( V_31 ) ;
}
return ( V_46 ) ;
}
static int F_36 ( int * V_23 , int V_25 , int type )
{
return ( F_41 ( V_23 , V_25 , NULL , type ) ) ;
}
static int F_37 ( int V_55 , int * V_23 , char * * V_24 )
{
int V_46 , V_32 ;
struct V_56 * V_57 , * V_58 ;
static struct V_29 V_59 ;
int V_60 ;
if ( ! F_10 () ) return ( 0 ) ;
#ifndef V_12
V_61:
#endif
memset ( ( char * ) & V_59 , 0 , sizeof( V_59 ) ) ;
V_60 = sizeof( V_59 ) ;
V_46 = F_45 ( V_55 , (struct V_45 * ) & V_59 , ( void * ) & V_60 ) ;
if ( V_46 == V_42 )
{
#if F_13 ( V_12 ) || ( F_13 ( V_19 ) && ! F_13 ( V_20 ) )
V_32 = F_16 () ;
F_17 ( V_15 , L_7 , V_32 ) ;
#else
if ( V_62 == V_63 )
{
goto V_61;
}
fprintf ( V_64 , L_8 , V_62 ) ;
perror ( L_9 ) ;
#endif
return ( 0 ) ;
}
if ( V_24 == NULL ) goto V_65;
#ifndef F_42
V_57 = F_46 ( ( char * ) & V_59 . V_36 . V_37 ,
sizeof( V_59 . V_36 . V_37 ) , V_34 ) ;
#else
V_57 = F_46 ( ( char * ) & V_59 . V_36 ,
sizeof( struct V_66 ) , V_34 ) ;
#endif
if ( V_57 == NULL )
{
F_17 ( V_15 , L_10 ) ;
* V_24 = NULL ;
}
else
{
if ( ( * V_24 = ( char * ) F_47 ( strlen ( V_57 -> V_67 ) + 1 ) ) == NULL )
{
perror ( L_11 ) ;
return ( 0 ) ;
}
F_48 ( * V_24 , V_57 -> V_67 , strlen ( V_57 -> V_67 ) + 1 ) ;
V_58 = F_49 ( * V_24 ) ;
if ( V_58 == NULL )
{
F_17 ( V_15 , L_12 ) ;
return ( 0 ) ;
}
V_32 = 0 ;
if ( V_58 -> V_68 != V_34 )
{
F_17 ( V_15 , L_13 ) ;
return ( 0 ) ;
}
}
V_65:
* V_23 = V_46 ;
return ( 1 ) ;
}
int F_50 ( char * V_69 , char * * V_70 , unsigned char * V_26 ,
short * V_71 )
{
char * V_72 , * V_27 ;
V_72 = V_69 ;
V_27 = strchr ( V_69 , ':' ) ;
if ( V_27 == NULL )
{
F_17 ( V_15 , L_14 ) ;
return ( 0 ) ;
}
* ( V_27 ++ ) = '\0' ;
if ( ( V_26 != NULL ) && ! F_25 ( V_69 , V_26 ) )
goto V_13;
if ( V_70 != NULL ) * V_70 = V_72 ;
if ( ! F_51 ( V_27 , V_71 ) )
goto V_13;
return ( 1 ) ;
V_13:
return ( 0 ) ;
}
static int F_25 ( char * V_69 , unsigned char V_26 [ 4 ] )
{
unsigned int V_73 [ 4 ] ;
int V_32 ;
if ( sscanf ( V_69 , L_15 , & ( V_73 [ 0 ] ) , & ( V_73 [ 1 ] ) , & ( V_73 [ 2 ] ) , & ( V_73 [ 3 ] ) ) == 4 )
{
for ( V_32 = 0 ; V_32 < 4 ; V_32 ++ )
if ( V_73 [ V_32 ] > 255 )
{
F_17 ( V_15 , L_16 ) ;
goto V_13;
}
V_26 [ 0 ] = V_73 [ 0 ] ;
V_26 [ 1 ] = V_73 [ 1 ] ;
V_26 [ 2 ] = V_73 [ 2 ] ;
V_26 [ 3 ] = V_73 [ 3 ] ;
}
else
{
struct V_56 * V_74 ;
if ( ! F_10 () ) return ( 0 ) ;
V_74 = F_49 ( V_69 ) ;
if ( V_74 == NULL )
{
F_17 ( V_15 , L_12 ) ;
goto V_13;
}
if ( ( short ) V_74 -> V_68 != V_34 )
{
F_17 ( V_15 , L_13 ) ;
return ( 0 ) ;
}
V_26 [ 0 ] = V_74 -> V_75 [ 0 ] [ 0 ] ;
V_26 [ 1 ] = V_74 -> V_75 [ 0 ] [ 1 ] ;
V_26 [ 2 ] = V_74 -> V_75 [ 0 ] [ 2 ] ;
V_26 [ 3 ] = V_74 -> V_75 [ 0 ] [ 3 ] ;
}
return ( 1 ) ;
V_13:
return ( 0 ) ;
}
int F_51 ( char * V_69 , short * V_71 )
{
int V_32 ;
struct V_76 * V_31 ;
V_32 = atoi ( V_69 ) ;
if ( V_32 != 0 )
* V_71 = ( unsigned short ) V_32 ;
else
{
V_31 = F_52 ( V_69 , L_17 ) ;
if ( V_31 == NULL )
{
F_17 ( V_15 , L_18 , V_69 ) ;
return ( 0 ) ;
}
* V_71 = F_53 ( ( unsigned short ) V_31 -> V_77 ) ;
}
return ( 1 ) ;
}
static struct V_56 * F_49 ( char * V_49 )
{
struct V_56 * V_46 ;
int V_32 , V_78 = 0 ;
unsigned long V_79 = ( unsigned long ) - 1 ;
for ( V_32 = 0 ; V_32 < V_80 ; V_32 ++ )
{
if ( V_79 > V_81 [ V_32 ] . V_82 )
{
V_79 = V_81 [ V_32 ] . V_82 ;
V_78 = V_32 ;
}
if ( V_81 [ V_32 ] . V_82 > 0 )
{
if ( strncmp ( V_49 , V_81 [ V_32 ] . V_49 , 128 ) == 0 )
break;
}
}
if ( V_32 == V_80 )
{
V_83 ++ ;
V_46 = F_54 ( V_49 ) ;
if ( V_46 == NULL ) return ( NULL ) ;
if( strlen ( V_49 ) < sizeof V_81 [ 0 ] . V_49 )
{
strcpy ( V_81 [ V_78 ] . V_49 , V_49 ) ;
memcpy ( ( char * ) & ( V_81 [ V_78 ] . V_84 ) , V_46 , sizeof( struct V_56 ) ) ;
V_81 [ V_78 ] . V_82 = V_83 + V_85 ;
}
return ( V_46 ) ;
}
else
{
V_85 ++ ;
V_46 = & ( V_81 [ V_32 ] . V_84 ) ;
V_81 [ V_32 ] . V_82 = V_83 + V_85 ;
return ( V_46 ) ;
}
}
