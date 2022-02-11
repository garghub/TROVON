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
void F_3 ( void )
{
#ifdef F_6
if ( V_10 )
{
V_10 = 0 ;
F_7 () ;
F_8 () ;
}
#endif
}
int F_9 ( void )
{
#ifdef F_6
if ( ! V_10 )
{
int V_11 ;
#ifdef F_10
signal ( F_10 , ( void ( * ) ( int ) ) F_3 ) ;
#endif
V_10 = 1 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
if ( F_11 ( 0x0101 , & V_12 ) != 0 )
{
V_11 = F_12 () ;
F_13 ( V_13 , L_1 , V_11 ) ;
return ( 0 ) ;
}
#ifdef F_14
F_15 ( F_16 () , F_5 , 0L ) ;
V_9 = ( V_14 ) F_17 ( V_5 , V_8 ) ;
V_15 = F_18 ( ( V_14 ) F_1 , V_16 ) ;
F_2 ( V_5 , V_8 , ( LONG ) V_15 ) ;
#endif
}
#endif
return ( 1 ) ;
}
int F_19 ( int * V_17 , char * V_18 , int V_19 )
{
unsigned char V_20 [ 4 ] ;
short V_21 = 0 ;
if ( ! F_20 ( V_18 , & ( V_20 [ 0 ] ) ) )
{
return ( 0 ) ;
}
if ( V_21 != 0 ) V_19 = V_21 ;
return ( F_21 ( V_17 , V_20 , V_19 ) ) ;
}
int F_21 ( int * V_17 , unsigned char V_20 [ 4 ] , int V_19 )
{
unsigned long V_22 ;
struct V_23 V_24 ;
int V_25 , V_26 ;
if ( ! F_9 () ) return ( 0 ) ;
memset ( ( char * ) & V_24 , 0 , sizeof( V_24 ) ) ;
V_24 . V_27 = V_28 ;
V_24 . V_29 = F_22 ( ( unsigned short ) V_19 ) ;
V_22 = ( unsigned long )
( ( unsigned long ) V_20 [ 0 ] << 24L ) |
( ( unsigned long ) V_20 [ 1 ] << 16L ) |
( ( unsigned long ) V_20 [ 2 ] << 8L ) |
( ( unsigned long ) V_20 [ 3 ] ) ;
V_24 . V_30 . V_31 = F_23 ( V_22 ) ;
V_25 = F_24 ( V_28 , V_32 , V_33 ) ;
if ( V_25 == V_34 ) { perror ( L_2 ) ; return ( 0 ) ; }
V_26 = 0 ;
V_26 = F_25 ( V_25 , V_35 , V_36 , ( char * ) & V_26 , sizeof( V_26 ) ) ;
if ( V_26 < 0 ) { perror ( L_3 ) ; return ( 0 ) ; }
if ( F_26 ( V_25 , (struct V_37 * ) & V_24 , sizeof( V_24 ) ) == - 1 )
{ F_27 ( V_25 ) ; perror ( L_4 ) ; return ( 0 ) ; }
* V_17 = V_25 ;
return ( 1 ) ;
}
int F_28 ( int V_17 )
{
int V_38 , V_26 ;
int V_39 ;
V_39 = sizeof( int ) ;
V_26 = F_29 ( V_17 , V_35 , V_40 , ( char * ) & V_38 , ( void * ) & V_39 ) ;
if ( V_26 < 0 )
return ( 1 ) ;
else
return ( V_38 ) ;
}
int F_30 ( int * V_17 , unsigned char V_20 [ 4 ] , int V_19 )
{
unsigned long V_22 ;
struct V_23 V_24 ;
int V_25 , V_26 ;
if ( ! F_9 () ) return ( 0 ) ;
memset ( ( char * ) & V_24 , 0 , sizeof( V_24 ) ) ;
V_24 . V_27 = V_28 ;
V_24 . V_29 = F_22 ( ( unsigned short ) V_19 ) ;
V_22 = ( unsigned long )
( ( unsigned long ) V_20 [ 0 ] << 24L ) |
( ( unsigned long ) V_20 [ 1 ] << 16L ) |
( ( unsigned long ) V_20 [ 2 ] << 8L ) |
( ( unsigned long ) V_20 [ 3 ] ) ;
V_24 . V_30 . V_31 = F_23 ( V_22 ) ;
if ( * V_17 <= 0 )
{
#ifdef F_31
unsigned long V_41 = 1 ;
#endif
V_25 = F_24 ( V_28 , V_32 , V_33 ) ;
if ( V_25 == V_34 ) { perror ( L_2 ) ; return ( 0 ) ; }
V_26 = 0 ;
V_26 = F_25 ( V_25 , V_35 , V_36 , ( char * ) & V_26 , sizeof( V_26 ) ) ;
if ( V_26 < 0 ) { perror ( L_3 ) ; return ( 0 ) ; }
* V_17 = V_25 ;
#ifdef F_31
F_32 ( V_25 , F_31 , & V_41 ) ;
#endif
}
else
V_25 = * V_17 ;
V_26 = F_26 ( V_25 , (struct V_37 * ) & V_24 , sizeof( V_24 ) ) ;
if ( V_26 == V_34 )
{
if ( F_33 ( V_26 ) )
return ( - 1 ) ;
else
return ( 0 ) ;
}
else
return ( 1 ) ;
}
int F_34 ( int V_19 , int * V_42 , int (* F_35)() , char * V_43 )
{
int V_17 ;
char * V_44 ;
int V_45 ;
int V_26 ;
if ( ! F_36 ( & V_45 , V_19 ) ) return ( 0 ) ;
if ( V_42 != NULL )
{
* V_42 = V_45 ;
}
for (; ; )
{
if ( F_37 ( V_45 , & V_17 , & V_44 ) == 0 )
{
F_38 ( V_45 ) ;
return ( 0 ) ;
}
V_26 = (* F_35)( V_44 , V_17 , V_43 ) ;
if ( V_44 != NULL ) Free ( V_44 ) ;
F_39 ( V_17 ) ;
if ( V_26 < 0 )
{
F_39 ( V_45 ) ;
return ( V_26 ) ;
}
}
}
int F_40 ( int * V_17 , int V_19 , char * V_20 )
{
int V_42 = 0 ;
struct V_23 V_46 ;
int V_25 = - 1 , V_26 ;
if ( ! F_9 () ) return ( 0 ) ;
memset ( ( char * ) & V_46 , 0 , sizeof( V_46 ) ) ;
V_46 . V_27 = V_28 ;
V_46 . V_29 = F_22 ( ( unsigned short ) V_19 ) ;
if ( V_20 == NULL )
V_46 . V_30 . V_31 = V_47 ;
else
#ifndef F_41
memcpy ( & V_46 . V_30 . V_31 , V_20 , 4 ) ;
#else
memcpy ( & V_46 . V_30 , V_20 , 4 ) ;
#endif
V_25 = F_24 ( V_28 , V_32 , V_33 ) ;
if ( V_25 == V_34 ) goto V_11;
#if V_48 V_35 && V_48 V_49
{
int V_38 = 1 ;
F_25 ( V_25 , V_35 , V_49 ,
( void * ) & V_38 , sizeof V_38 ) ;
}
#endif
if ( F_42 ( V_25 , (struct V_37 * ) & V_46 , sizeof( V_46 ) ) == - 1 )
{
#ifndef F_6
perror ( L_5 ) ;
#endif
goto V_11;
}
if ( F_43 ( V_25 , 128 ) == - 1 ) goto V_11;
V_26 = 0 ;
* V_17 = V_25 ;
V_42 = 1 ;
V_11:
if ( ( V_42 == 0 ) && ( V_25 != - 1 ) )
{
F_38 ( V_25 ) ;
}
return ( V_42 ) ;
}
int F_36 ( int * V_17 , int V_19 )
{
return ( F_40 ( V_17 , V_19 , NULL ) ) ;
}
int F_37 ( int V_50 , int * V_17 , char * * V_18 )
{
int V_42 , V_26 ;
struct V_51 * V_52 , * V_53 ;
static struct V_23 V_54 ;
int V_55 ;
if ( ! F_9 () ) return ( 0 ) ;
#ifndef F_6
V_56:
#endif
memset ( ( char * ) & V_54 , 0 , sizeof( V_54 ) ) ;
V_55 = sizeof( V_54 ) ;
V_42 = F_44 ( V_50 , (struct V_37 * ) & V_54 , ( void * ) & V_55 ) ;
if ( V_42 == V_34 )
{
#ifdef F_6
V_26 = F_12 () ;
F_13 ( V_13 , L_6 , V_26 ) ;
#else
if ( V_57 == V_58 )
{
goto V_56;
}
fprintf ( V_59 , L_7 , V_57 ) ;
perror ( L_8 ) ;
#endif
return ( 0 ) ;
}
if ( V_18 == NULL ) goto V_60;
#ifndef F_41
V_52 = F_45 ( ( char * ) & V_54 . V_30 . V_31 ,
sizeof( V_54 . V_30 . V_31 ) , V_28 ) ;
#else
V_52 = F_45 ( ( char * ) & V_54 . V_30 ,
sizeof( struct V_61 ) , V_28 ) ;
#endif
if ( V_52 == NULL )
{
F_13 ( V_13 , L_9 ) ;
* V_18 = NULL ;
}
else
{
if ( ( * V_18 = ( char * ) Malloc ( strlen ( V_52 -> V_62 ) + 1 ) ) == NULL )
{
perror ( L_10 ) ;
return ( 0 ) ;
}
strcpy ( * V_18 , V_52 -> V_62 ) ;
V_53 = F_46 ( * V_18 ) ;
if ( V_53 == NULL )
{
F_13 ( V_13 , L_11 ) ;
return ( 0 ) ;
}
V_26 = 0 ;
if ( V_53 -> V_63 != V_28 )
{
F_13 ( V_13 , L_12 ) ;
return ( 0 ) ;
}
}
V_60:
* V_17 = V_42 ;
return ( 1 ) ;
}
int F_47 ( char * V_64 , char * * V_65 , unsigned char * V_20 ,
short * V_66 )
{
char * V_67 , * V_21 ;
V_67 = V_64 ;
V_21 = strchr ( V_64 , ':' ) ;
if ( V_21 == NULL )
{
F_13 ( V_13 , L_13 ) ;
return ( 0 ) ;
}
* ( V_21 ++ ) = '\0' ;
if ( ( V_20 != NULL ) && ! F_20 ( V_64 , V_20 ) )
goto V_11;
if ( V_65 != NULL ) * V_65 = V_67 ;
if ( ! F_48 ( V_21 , V_66 ) )
goto V_11;
return ( 1 ) ;
V_11:
return ( 0 ) ;
}
int F_20 ( char * V_64 , unsigned char V_20 [ 4 ] )
{
unsigned int V_68 [ 4 ] ;
int V_26 ;
if ( sscanf ( V_64 , L_14 , & ( V_68 [ 0 ] ) , & ( V_68 [ 1 ] ) , & ( V_68 [ 2 ] ) , & ( V_68 [ 3 ] ) ) == 4 )
{
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ )
if ( V_68 [ V_26 ] > 255 )
{
F_13 ( V_13 , L_15 ) ;
goto V_11;
}
V_20 [ 0 ] = V_68 [ 0 ] ;
V_20 [ 1 ] = V_68 [ 1 ] ;
V_20 [ 2 ] = V_68 [ 2 ] ;
V_20 [ 3 ] = V_68 [ 3 ] ;
}
else
{
struct V_51 * V_69 ;
if ( ! F_9 () ) return ( 0 ) ;
V_69 = F_46 ( V_64 ) ;
if ( V_69 == NULL )
{
F_13 ( V_13 , L_11 ) ;
goto V_11;
}
if ( ( short ) V_69 -> V_63 != V_28 )
{
F_13 ( V_13 , L_12 ) ;
return ( 0 ) ;
}
V_20 [ 0 ] = V_69 -> V_70 [ 0 ] [ 0 ] ;
V_20 [ 1 ] = V_69 -> V_70 [ 0 ] [ 1 ] ;
V_20 [ 2 ] = V_69 -> V_70 [ 0 ] [ 2 ] ;
V_20 [ 3 ] = V_69 -> V_70 [ 0 ] [ 3 ] ;
}
return ( 1 ) ;
V_11:
return ( 0 ) ;
}
int F_48 ( char * V_64 , short * V_66 )
{
int V_26 ;
struct V_71 * V_25 ;
V_26 = atoi ( V_64 ) ;
if ( V_26 != 0 )
* V_66 = ( unsigned short ) V_26 ;
else
{
V_25 = F_49 ( V_64 , L_16 ) ;
if ( V_25 == NULL )
{
F_13 ( V_13 , L_17 , V_64 ) ;
return ( 0 ) ;
}
* V_66 = F_50 ( ( unsigned short ) V_25 -> V_72 ) ;
}
return ( 1 ) ;
}
static struct V_51 * F_46 ( char * V_44 )
{
struct V_51 * V_42 ;
int V_26 , V_73 = 0 ;
unsigned long V_74 = ( unsigned long ) - 1 ;
for ( V_26 = 0 ; V_26 < V_75 ; V_26 ++ )
{
if ( V_74 > V_76 [ V_26 ] . V_77 )
{
V_74 = V_76 [ V_26 ] . V_77 ;
V_73 = V_26 ;
}
if ( V_76 [ V_26 ] . V_77 > 0 )
{
if ( strncmp ( V_44 , V_76 [ V_26 ] . V_44 , 128 ) == 0 )
break;
}
}
if ( V_26 == V_75 )
{
V_78 ++ ;
V_42 = F_51 ( V_44 ) ;
if ( V_42 == NULL ) return ( NULL ) ;
strncpy ( V_76 [ V_73 ] . V_44 , V_44 , 128 ) ;
memcpy ( ( char * ) & ( V_76 [ V_73 ] . V_79 ) , V_42 , sizeof( struct V_51 ) ) ;
V_76 [ V_73 ] . V_77 = V_78 + V_80 ;
return ( V_42 ) ;
}
else
{
V_80 ++ ;
V_42 = & ( V_76 [ V_26 ] . V_79 ) ;
V_76 [ V_26 ] . V_77 = V_78 + V_80 ;
return ( V_42 ) ;
}
}
int F_52 ( int V_81 , char * * V_82 , int * V_68 , int * V_83 )
{
int V_84 ;
#define F_53 p1[0]
#define F_54 p2[1]
#define F_55 p2[0]
#define F_56 p1[1]
int V_85 [ 2 ] , V_86 [ 2 ] ;
if ( ( F_57 ( V_85 ) < 0 ) || ( F_57 ( V_86 ) < 0 ) ) return ( - 1 ) ;
#ifdef F_58
if ( ( V_84 = F_59 () ) == 0 )
#else
if ( ( V_84 = F_60 () ) == 0 )
#endif
{
if ( F_61 ( F_54 , fileno ( stdout ) ) < 0 )
perror ( L_18 ) ;
if ( F_61 ( F_54 , fileno ( V_59 ) ) < 0 )
perror ( L_18 ) ;
if ( F_61 ( F_53 , fileno ( V_87 ) ) < 0 )
perror ( L_18 ) ;
F_27 ( F_53 ) ;
F_27 ( F_54 ) ;
F_27 ( F_55 ) ;
F_27 ( F_56 ) ;
F_62 ( V_82 [ 0 ] , V_82 ) ;
perror ( L_19 ) ;
exit ( 1 ) ;
}
* V_68 = F_55 ;
* V_83 = F_56 ;
F_27 ( F_53 ) ;
F_27 ( F_54 ) ;
return ( V_84 ) ;
}
