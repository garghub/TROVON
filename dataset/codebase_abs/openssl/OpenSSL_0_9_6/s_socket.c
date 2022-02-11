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
F_6 () ;
F_7 () ;
}
}
static int F_8 ( void )
{
#ifdef F_9
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
static int F_21 ( int * V_17 , unsigned char V_20 [ 4 ] , int V_19 )
{
unsigned long V_22 ;
struct V_23 V_24 ;
int V_25 , V_26 ;
if ( ! F_8 () ) return ( 0 ) ;
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
#ifndef F_25
V_26 = 0 ;
V_26 = F_26 ( V_25 , V_35 , V_36 , ( char * ) & V_26 , sizeof( V_26 ) ) ;
if ( V_26 < 0 ) { perror ( L_3 ) ; return ( 0 ) ; }
#endif
if ( F_27 ( V_25 , (struct V_37 * ) & V_24 , sizeof( V_24 ) ) == - 1 )
{ F_28 ( V_25 ) ; perror ( L_4 ) ; return ( 0 ) ; }
* V_17 = V_25 ;
return ( 1 ) ;
}
int F_29 ( int V_19 , int * V_38 , int (* F_30)() , char * V_39 )
{
int V_17 ;
char * V_40 ;
int V_41 ;
int V_26 ;
if ( ! F_31 ( & V_41 , V_19 ) ) return ( 0 ) ;
if ( V_38 != NULL )
{
* V_38 = V_41 ;
}
for (; ; )
{
if ( F_32 ( V_41 , & V_17 , & V_40 ) == 0 )
{
F_33 ( V_41 ) ;
return ( 0 ) ;
}
V_26 = (* F_30)( V_40 , V_17 , V_39 ) ;
if ( V_40 != NULL ) F_34 ( V_40 ) ;
F_35 ( V_17 ) ;
if ( V_26 < 0 )
{
F_35 ( V_41 ) ;
return ( V_26 ) ;
}
}
}
static int F_36 ( int * V_17 , int V_19 , char * V_20 )
{
int V_38 = 0 ;
struct V_23 V_42 ;
int V_25 = - 1 , V_26 ;
if ( ! F_8 () ) return ( 0 ) ;
memset ( ( char * ) & V_42 , 0 , sizeof( V_42 ) ) ;
V_42 . V_27 = V_28 ;
V_42 . V_29 = F_22 ( ( unsigned short ) V_19 ) ;
if ( V_20 == NULL )
V_42 . V_30 . V_31 = V_43 ;
else
#ifndef F_37
memcpy ( & V_42 . V_30 . V_31 , V_20 , 4 ) ;
#else
memcpy ( & V_42 . V_30 , V_20 , 4 ) ;
#endif
V_25 = F_24 ( V_28 , V_32 , V_33 ) ;
if ( V_25 == V_34 ) goto V_11;
#if V_44 V_35 && V_44 V_45
{
int V_46 = 1 ;
F_26 ( V_25 , V_35 , V_45 ,
( void * ) & V_46 , sizeof V_46 ) ;
}
#endif
if ( F_38 ( V_25 , (struct V_37 * ) & V_42 , sizeof( V_42 ) ) == - 1 )
{
#ifndef F_9
perror ( L_5 ) ;
#endif
goto V_11;
}
if ( F_39 ( V_25 , 128 ) == - 1 ) goto V_11;
V_26 = 0 ;
* V_17 = V_25 ;
V_38 = 1 ;
V_11:
if ( ( V_38 == 0 ) && ( V_25 != - 1 ) )
{
F_33 ( V_25 ) ;
}
return ( V_38 ) ;
}
static int F_31 ( int * V_17 , int V_19 )
{
return ( F_36 ( V_17 , V_19 , NULL ) ) ;
}
static int F_32 ( int V_47 , int * V_17 , char * * V_18 )
{
int V_38 , V_26 ;
struct V_48 * V_49 , * V_50 ;
static struct V_23 V_51 ;
int V_52 ;
if ( ! F_8 () ) return ( 0 ) ;
#ifndef F_9
V_53:
#endif
memset ( ( char * ) & V_51 , 0 , sizeof( V_51 ) ) ;
V_52 = sizeof( V_51 ) ;
V_38 = F_40 ( V_47 , (struct V_37 * ) & V_51 , ( void * ) & V_52 ) ;
if ( V_38 == V_34 )
{
#ifdef F_9
V_26 = F_12 () ;
F_13 ( V_13 , L_6 , V_26 ) ;
#else
if ( V_54 == V_55 )
{
goto V_53;
}
fprintf ( V_56 , L_7 , V_54 ) ;
perror ( L_8 ) ;
#endif
return ( 0 ) ;
}
if ( V_18 == NULL ) goto V_57;
#ifndef F_37
V_49 = F_41 ( ( char * ) & V_51 . V_30 . V_31 ,
sizeof( V_51 . V_30 . V_31 ) , V_28 ) ;
#else
V_49 = F_41 ( ( char * ) & V_51 . V_30 ,
sizeof( struct V_58 ) , V_28 ) ;
#endif
if ( V_49 == NULL )
{
F_13 ( V_13 , L_9 ) ;
* V_18 = NULL ;
}
else
{
if ( ( * V_18 = ( char * ) F_42 ( strlen ( V_49 -> V_59 ) + 1 ) ) == NULL )
{
perror ( L_10 ) ;
return ( 0 ) ;
}
strcpy ( * V_18 , V_49 -> V_59 ) ;
V_50 = F_43 ( * V_18 ) ;
if ( V_50 == NULL )
{
F_13 ( V_13 , L_11 ) ;
return ( 0 ) ;
}
V_26 = 0 ;
if ( V_50 -> V_60 != V_28 )
{
F_13 ( V_13 , L_12 ) ;
return ( 0 ) ;
}
}
V_57:
* V_17 = V_38 ;
return ( 1 ) ;
}
int F_44 ( char * V_61 , char * * V_62 , unsigned char * V_20 ,
short * V_63 )
{
char * V_64 , * V_21 ;
V_64 = V_61 ;
V_21 = strchr ( V_61 , ':' ) ;
if ( V_21 == NULL )
{
F_13 ( V_13 , L_13 ) ;
return ( 0 ) ;
}
* ( V_21 ++ ) = '\0' ;
if ( ( V_20 != NULL ) && ! F_20 ( V_61 , V_20 ) )
goto V_11;
if ( V_62 != NULL ) * V_62 = V_64 ;
if ( ! F_45 ( V_21 , V_63 ) )
goto V_11;
return ( 1 ) ;
V_11:
return ( 0 ) ;
}
static int F_20 ( char * V_61 , unsigned char V_20 [ 4 ] )
{
unsigned int V_65 [ 4 ] ;
int V_26 ;
if ( sscanf ( V_61 , L_14 , & ( V_65 [ 0 ] ) , & ( V_65 [ 1 ] ) , & ( V_65 [ 2 ] ) , & ( V_65 [ 3 ] ) ) == 4 )
{
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ )
if ( V_65 [ V_26 ] > 255 )
{
F_13 ( V_13 , L_15 ) ;
goto V_11;
}
V_20 [ 0 ] = V_65 [ 0 ] ;
V_20 [ 1 ] = V_65 [ 1 ] ;
V_20 [ 2 ] = V_65 [ 2 ] ;
V_20 [ 3 ] = V_65 [ 3 ] ;
}
else
{
struct V_48 * V_66 ;
if ( ! F_8 () ) return ( 0 ) ;
V_66 = F_43 ( V_61 ) ;
if ( V_66 == NULL )
{
F_13 ( V_13 , L_11 ) ;
goto V_11;
}
if ( ( short ) V_66 -> V_60 != V_28 )
{
F_13 ( V_13 , L_12 ) ;
return ( 0 ) ;
}
V_20 [ 0 ] = V_66 -> V_67 [ 0 ] [ 0 ] ;
V_20 [ 1 ] = V_66 -> V_67 [ 0 ] [ 1 ] ;
V_20 [ 2 ] = V_66 -> V_67 [ 0 ] [ 2 ] ;
V_20 [ 3 ] = V_66 -> V_67 [ 0 ] [ 3 ] ;
}
return ( 1 ) ;
V_11:
return ( 0 ) ;
}
int F_45 ( char * V_61 , short * V_63 )
{
int V_26 ;
struct V_68 * V_25 ;
V_26 = atoi ( V_61 ) ;
if ( V_26 != 0 )
* V_63 = ( unsigned short ) V_26 ;
else
{
V_25 = F_46 ( V_61 , L_16 ) ;
if ( V_25 == NULL )
{
F_13 ( V_13 , L_17 , V_61 ) ;
return ( 0 ) ;
}
* V_63 = F_47 ( ( unsigned short ) V_25 -> V_69 ) ;
}
return ( 1 ) ;
}
static struct V_48 * F_43 ( char * V_40 )
{
struct V_48 * V_38 ;
int V_26 , V_70 = 0 ;
unsigned long V_71 = ( unsigned long ) - 1 ;
for ( V_26 = 0 ; V_26 < V_72 ; V_26 ++ )
{
if ( V_71 > V_73 [ V_26 ] . V_74 )
{
V_71 = V_73 [ V_26 ] . V_74 ;
V_70 = V_26 ;
}
if ( V_73 [ V_26 ] . V_74 > 0 )
{
if ( strncmp ( V_40 , V_73 [ V_26 ] . V_40 , 128 ) == 0 )
break;
}
}
if ( V_26 == V_72 )
{
V_75 ++ ;
V_38 = F_48 ( V_40 ) ;
if ( V_38 == NULL ) return ( NULL ) ;
strncpy ( V_73 [ V_70 ] . V_40 , V_40 , 128 ) ;
memcpy ( ( char * ) & ( V_73 [ V_70 ] . V_76 ) , V_38 , sizeof( struct V_48 ) ) ;
V_73 [ V_70 ] . V_74 = V_75 + V_77 ;
return ( V_38 ) ;
}
else
{
V_77 ++ ;
V_38 = & ( V_73 [ V_26 ] . V_76 ) ;
V_73 [ V_26 ] . V_74 = V_75 + V_77 ;
return ( V_38 ) ;
}
}
