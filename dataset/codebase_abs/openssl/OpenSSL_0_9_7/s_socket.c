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
static int F_9 ( void )
{
#ifdef F_10
extern int V_11 ;
V_11 = 0 ;
F_11 () ;
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
#endif
return ( 1 ) ;
}
int F_23 ( int * V_19 , char * V_20 , int V_21 )
{
unsigned char V_22 [ 4 ] ;
short V_23 = 0 ;
if ( ! F_24 ( V_20 , & ( V_22 [ 0 ] ) ) )
{
return ( 0 ) ;
}
if ( V_23 != 0 ) V_21 = V_23 ;
return ( F_25 ( V_19 , V_22 , V_21 ) ) ;
}
static int F_25 ( int * V_19 , unsigned char V_22 [ 4 ] , int V_21 )
{
unsigned long V_24 ;
struct V_25 V_26 ;
int V_27 , V_28 ;
if ( ! F_9 () ) return ( 0 ) ;
memset ( ( char * ) & V_26 , 0 , sizeof( V_26 ) ) ;
V_26 . V_29 = V_30 ;
V_26 . V_31 = F_26 ( ( unsigned short ) V_21 ) ;
V_24 = ( unsigned long )
( ( unsigned long ) V_22 [ 0 ] << 24L ) |
( ( unsigned long ) V_22 [ 1 ] << 16L ) |
( ( unsigned long ) V_22 [ 2 ] << 8L ) |
( ( unsigned long ) V_22 [ 3 ] ) ;
V_26 . V_32 . V_33 = F_27 ( V_24 ) ;
V_27 = F_28 ( V_30 , V_34 , V_35 ) ;
if ( V_27 == V_36 ) { perror ( L_2 ) ; return ( 0 ) ; }
#ifndef F_29
V_28 = 0 ;
V_28 = F_30 ( V_27 , V_37 , V_38 , ( char * ) & V_28 , sizeof( V_28 ) ) ;
if ( V_28 < 0 ) { perror ( L_3 ) ; return ( 0 ) ; }
#endif
if ( F_31 ( V_27 , (struct V_39 * ) & V_26 , sizeof( V_26 ) ) == - 1 )
{ F_32 ( V_27 ) ; perror ( L_4 ) ; return ( 0 ) ; }
* V_19 = V_27 ;
return ( 1 ) ;
}
int F_33 ( int V_21 , int * V_40 , int (* F_34)() , char * V_41 )
{
int V_19 ;
char * V_42 ;
int V_43 ;
int V_28 ;
if ( ! F_35 ( & V_43 , V_21 ) ) return ( 0 ) ;
if ( V_40 != NULL )
{
* V_40 = V_43 ;
}
for (; ; )
{
if ( F_36 ( V_43 , & V_19 , & V_42 ) == 0 )
{
F_37 ( V_43 ) ;
return ( 0 ) ;
}
V_28 = (* F_34)( V_42 , V_19 , V_41 ) ;
if ( V_42 != NULL ) F_38 ( V_42 ) ;
F_39 ( V_19 ) ;
if ( V_28 < 0 )
{
F_39 ( V_43 ) ;
return ( V_28 ) ;
}
}
}
static int F_40 ( int * V_19 , int V_21 , char * V_22 )
{
int V_40 = 0 ;
struct V_25 V_44 ;
int V_27 = - 1 , V_28 ;
if ( ! F_9 () ) return ( 0 ) ;
memset ( ( char * ) & V_44 , 0 , sizeof( V_44 ) ) ;
V_44 . V_29 = V_30 ;
V_44 . V_31 = F_26 ( ( unsigned short ) V_21 ) ;
if ( V_22 == NULL )
V_44 . V_32 . V_33 = V_45 ;
else
#ifndef F_41
memcpy ( & V_44 . V_32 . V_33 , V_22 , 4 ) ;
#else
memcpy ( & V_44 . V_32 , V_22 , 4 ) ;
#endif
V_27 = F_28 ( V_30 , V_34 , V_35 ) ;
if ( V_27 == V_36 ) goto V_13;
#if F_13 V_37 && F_13 V_46
{
int V_47 = 1 ;
F_30 ( V_27 , V_37 , V_46 ,
( void * ) & V_47 , sizeof V_47 ) ;
}
#endif
if ( F_42 ( V_27 , (struct V_39 * ) & V_44 , sizeof( V_44 ) ) == - 1 )
{
#ifndef V_12
perror ( L_5 ) ;
#endif
goto V_13;
}
if ( F_43 ( V_27 , 128 ) == - 1 ) goto V_13;
V_28 = 0 ;
* V_19 = V_27 ;
V_40 = 1 ;
V_13:
if ( ( V_40 == 0 ) && ( V_27 != - 1 ) )
{
F_37 ( V_27 ) ;
}
return ( V_40 ) ;
}
static int F_35 ( int * V_19 , int V_21 )
{
return ( F_40 ( V_19 , V_21 , NULL ) ) ;
}
static int F_36 ( int V_48 , int * V_19 , char * * V_20 )
{
int V_40 , V_28 ;
struct V_49 * V_50 , * V_51 ;
static struct V_25 V_52 ;
int V_53 ;
if ( ! F_9 () ) return ( 0 ) ;
#ifndef V_12
V_54:
#endif
memset ( ( char * ) & V_52 , 0 , sizeof( V_52 ) ) ;
V_53 = sizeof( V_52 ) ;
V_40 = F_44 ( V_48 , (struct V_39 * ) & V_52 , ( void * ) & V_53 ) ;
if ( V_40 == V_36 )
{
#ifdef V_12
V_28 = F_16 () ;
F_17 ( V_15 , L_6 , V_28 ) ;
#else
if ( V_55 == V_56 )
{
goto V_54;
}
fprintf ( V_57 , L_7 , V_55 ) ;
perror ( L_8 ) ;
#endif
return ( 0 ) ;
}
if ( V_20 == NULL ) goto V_58;
#ifndef F_41
V_50 = F_45 ( ( char * ) & V_52 . V_32 . V_33 ,
sizeof( V_52 . V_32 . V_33 ) , V_30 ) ;
#else
V_50 = F_45 ( ( char * ) & V_52 . V_32 ,
sizeof( struct V_59 ) , V_30 ) ;
#endif
if ( V_50 == NULL )
{
F_17 ( V_15 , L_9 ) ;
* V_20 = NULL ;
}
else
{
if ( ( * V_20 = ( char * ) F_46 ( strlen ( V_50 -> V_60 ) + 1 ) ) == NULL )
{
perror ( L_10 ) ;
return ( 0 ) ;
}
strcpy ( * V_20 , V_50 -> V_60 ) ;
V_51 = F_47 ( * V_20 ) ;
if ( V_51 == NULL )
{
F_17 ( V_15 , L_11 ) ;
return ( 0 ) ;
}
V_28 = 0 ;
if ( V_51 -> V_61 != V_30 )
{
F_17 ( V_15 , L_12 ) ;
return ( 0 ) ;
}
}
V_58:
* V_19 = V_40 ;
return ( 1 ) ;
}
int F_48 ( char * V_62 , char * * V_63 , unsigned char * V_22 ,
short * V_64 )
{
char * V_65 , * V_23 ;
V_65 = V_62 ;
V_23 = strchr ( V_62 , ':' ) ;
if ( V_23 == NULL )
{
F_17 ( V_15 , L_13 ) ;
return ( 0 ) ;
}
* ( V_23 ++ ) = '\0' ;
if ( ( V_22 != NULL ) && ! F_24 ( V_62 , V_22 ) )
goto V_13;
if ( V_63 != NULL ) * V_63 = V_65 ;
if ( ! F_49 ( V_23 , V_64 ) )
goto V_13;
return ( 1 ) ;
V_13:
return ( 0 ) ;
}
static int F_24 ( char * V_62 , unsigned char V_22 [ 4 ] )
{
unsigned int V_66 [ 4 ] ;
int V_28 ;
if ( sscanf ( V_62 , L_14 , & ( V_66 [ 0 ] ) , & ( V_66 [ 1 ] ) , & ( V_66 [ 2 ] ) , & ( V_66 [ 3 ] ) ) == 4 )
{
for ( V_28 = 0 ; V_28 < 4 ; V_28 ++ )
if ( V_66 [ V_28 ] > 255 )
{
F_17 ( V_15 , L_15 ) ;
goto V_13;
}
V_22 [ 0 ] = V_66 [ 0 ] ;
V_22 [ 1 ] = V_66 [ 1 ] ;
V_22 [ 2 ] = V_66 [ 2 ] ;
V_22 [ 3 ] = V_66 [ 3 ] ;
}
else
{
struct V_49 * V_67 ;
if ( ! F_9 () ) return ( 0 ) ;
V_67 = F_47 ( V_62 ) ;
if ( V_67 == NULL )
{
F_17 ( V_15 , L_11 ) ;
goto V_13;
}
if ( ( short ) V_67 -> V_61 != V_30 )
{
F_17 ( V_15 , L_12 ) ;
return ( 0 ) ;
}
V_22 [ 0 ] = V_67 -> V_68 [ 0 ] [ 0 ] ;
V_22 [ 1 ] = V_67 -> V_68 [ 0 ] [ 1 ] ;
V_22 [ 2 ] = V_67 -> V_68 [ 0 ] [ 2 ] ;
V_22 [ 3 ] = V_67 -> V_68 [ 0 ] [ 3 ] ;
}
return ( 1 ) ;
V_13:
return ( 0 ) ;
}
int F_49 ( char * V_62 , short * V_64 )
{
int V_28 ;
struct V_69 * V_27 ;
V_28 = atoi ( V_62 ) ;
if ( V_28 != 0 )
* V_64 = ( unsigned short ) V_28 ;
else
{
V_27 = F_50 ( V_62 , L_16 ) ;
if ( V_27 == NULL )
{
F_17 ( V_15 , L_17 , V_62 ) ;
return ( 0 ) ;
}
* V_64 = F_51 ( ( unsigned short ) V_27 -> V_70 ) ;
}
return ( 1 ) ;
}
static struct V_49 * F_47 ( char * V_42 )
{
struct V_49 * V_40 ;
int V_28 , V_71 = 0 ;
unsigned long V_72 = ( unsigned long ) - 1 ;
for ( V_28 = 0 ; V_28 < V_73 ; V_28 ++ )
{
if ( V_72 > V_74 [ V_28 ] . V_75 )
{
V_72 = V_74 [ V_28 ] . V_75 ;
V_71 = V_28 ;
}
if ( V_74 [ V_28 ] . V_75 > 0 )
{
if ( strncmp ( V_42 , V_74 [ V_28 ] . V_42 , 128 ) == 0 )
break;
}
}
if ( V_28 == V_73 )
{
V_76 ++ ;
V_40 = F_52 ( V_42 ) ;
if ( V_40 == NULL ) return ( NULL ) ;
if( strlen ( V_42 ) < sizeof V_74 [ 0 ] . V_42 )
{
strcpy ( V_74 [ V_71 ] . V_42 , V_42 ) ;
memcpy ( ( char * ) & ( V_74 [ V_71 ] . V_77 ) , V_40 , sizeof( struct V_49 ) ) ;
V_74 [ V_71 ] . V_75 = V_76 + V_78 ;
}
return ( V_40 ) ;
}
else
{
V_78 ++ ;
V_40 = & ( V_74 [ V_28 ] . V_77 ) ;
V_74 [ V_28 ] . V_75 = V_76 + V_78 ;
return ( V_40 ) ;
}
}
