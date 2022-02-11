int F_1 ( const char * V_1 , unsigned char * V_2 )
{
int V_3 ;
int V_4 = 1 ;
int V_5 = 0 ;
struct V_6 * V_7 ;
V_3 = F_2 ( V_1 , V_2 ) ;
if ( V_3 < 0 )
{
F_3 ( V_8 , V_9 ) ;
goto V_4;
}
if ( ! F_4 () )
return ( 0 ) ;
if ( V_3 > 0 ) return ( 1 ) ;
F_5 ( V_10 ) ;
V_5 = 1 ;
V_7 = F_6 ( V_1 ) ;
if ( V_7 == NULL )
{
F_3 ( V_8 , V_11 ) ;
goto V_4;
}
if ( ( short ) V_7 -> V_12 != V_13 )
{
F_3 ( V_8 , V_14 ) ;
goto V_4;
}
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ )
V_2 [ V_3 ] = V_7 -> V_15 [ 0 ] [ V_3 ] ;
V_4 = 0 ;
V_4:
if ( V_5 )
F_7 ( V_10 ) ;
if ( V_4 )
{
F_8 ( 2 , L_1 , V_1 ) ;
return 0 ;
}
else
return 1 ;
}
int F_9 ( const char * V_1 , unsigned short * V_16 )
{
int V_3 ;
struct V_17 * V_18 ;
if ( V_1 == NULL )
{
F_3 ( V_19 , V_20 ) ;
return ( 0 ) ;
}
V_3 = atoi ( V_1 ) ;
if ( V_3 != 0 )
* V_16 = ( unsigned short ) V_3 ;
else
{
F_5 ( V_21 ) ;
V_18 = F_10 (
#ifndef F_11
( char * )
#endif
V_1 , L_2 ) ;
if( V_18 != NULL )
* V_16 = F_12 ( ( unsigned short ) V_18 -> V_22 ) ;
F_7 ( V_21 ) ;
if( V_18 == NULL )
{
if ( strcmp ( V_1 , L_3 ) == 0 )
* V_16 = 80 ;
else if ( strcmp ( V_1 , L_4 ) == 0 )
* V_16 = 23 ;
else if ( strcmp ( V_1 , L_5 ) == 0 )
* V_16 = 1080 ;
else if ( strcmp ( V_1 , L_6 ) == 0 )
* V_16 = 443 ;
else if ( strcmp ( V_1 , L_7 ) == 0 )
* V_16 = 443 ;
else if ( strcmp ( V_1 , L_8 ) == 0 )
* V_16 = 21 ;
else if ( strcmp ( V_1 , L_9 ) == 0 )
* V_16 = 70 ;
#if 0
else if (strcmp(str,"wais") == 0)
*port_ptr=21;
#endif
else
{
F_13 ( V_23 , F_14 () ) ;
F_8 ( 3 , L_10 , V_1 , L_11 ) ;
return ( 0 ) ;
}
}
}
return ( 1 ) ;
}
int F_15 ( int V_24 )
{
int V_25 , V_3 ;
int V_26 ;
V_26 = sizeof( int ) ;
V_3 = F_16 ( V_24 , V_27 , V_28 , ( void * ) & V_25 , ( void * ) & V_26 ) ;
if ( V_3 < 0 )
return ( 1 ) ;
else
return ( V_25 ) ;
}
long F_17 ( int V_29 , int V_30 , char * V_31 )
{
int V_3 ;
char * * V_32 ;
switch ( V_29 )
{
case V_33 :
return ( V_34 ) ;
case V_35 :
return ( V_36 ) ;
case V_37 :
return ( V_38 ) ;
case V_39 :
if ( ( V_30 >= 0 ) && ( V_30 < V_38 ) &&
( V_40 [ V_30 ] . V_41 > 0 ) )
{
V_32 = ( char * * ) V_31 ;
if ( V_32 == NULL ) return ( 0 ) ;
* V_32 = V_40 [ V_30 ] . V_42 ;
V_40 [ V_30 ] . V_42 [ 128 ] = '\0' ;
return ( 1 ) ;
}
return ( 0 ) ;
case V_43 :
for ( V_3 = 0 ; V_3 < V_38 ; V_3 ++ )
V_40 [ V_3 ] . V_41 = 0 ;
break;
default:
return ( 0 ) ;
}
return ( 1 ) ;
}
static struct V_6 * F_18 ( struct V_6 * V_44 )
{
struct V_6 * V_45 ;
int V_3 , V_25 ;
F_19 () ;
V_45 = (struct V_6 * ) F_20 ( sizeof( struct V_6 ) ) ;
if ( V_45 == NULL ) return ( NULL ) ;
memset ( V_45 , 0 , sizeof( struct V_6 ) ) ;
for ( V_3 = 0 ; V_44 -> V_46 [ V_3 ] != NULL ; V_3 ++ )
;
V_3 ++ ;
V_45 -> V_46 = ( char * * ) F_20 ( V_3 * sizeof( char * ) ) ;
if ( V_45 -> V_46 == NULL )
goto V_4;
memset ( V_45 -> V_46 , 0 , V_3 * sizeof( char * ) ) ;
for ( V_3 = 0 ; V_44 -> V_15 [ V_3 ] != NULL ; V_3 ++ )
;
V_3 ++ ;
V_45 -> V_15 = ( char * * ) F_20 ( V_3 * sizeof( char * ) ) ;
if ( V_45 -> V_15 == NULL )
goto V_4;
memset ( V_45 -> V_15 , 0 , V_3 * sizeof( char * ) ) ;
V_25 = strlen ( V_44 -> V_47 ) + 1 ;
if ( ( V_45 -> V_47 = F_20 ( V_25 ) ) == NULL ) goto V_4;
memcpy ( ( char * ) V_45 -> V_47 , V_44 -> V_47 , V_25 ) ;
for ( V_3 = 0 ; V_44 -> V_46 [ V_3 ] != NULL ; V_3 ++ )
{
V_25 = strlen ( V_44 -> V_46 [ V_3 ] ) + 1 ;
if ( ( V_45 -> V_46 [ V_3 ] = F_20 ( V_25 ) ) == NULL ) goto V_4;
memcpy ( V_45 -> V_46 [ V_3 ] , V_44 -> V_46 [ V_3 ] , V_25 ) ;
}
V_45 -> V_48 = V_44 -> V_48 ;
V_45 -> V_12 = V_44 -> V_12 ;
for ( V_3 = 0 ; V_44 -> V_15 [ V_3 ] != NULL ; V_3 ++ )
{
if ( ( V_45 -> V_15 [ V_3 ] = F_20 ( V_44 -> V_48 ) ) == NULL )
goto V_4;
memcpy ( V_45 -> V_15 [ V_3 ] , V_44 -> V_15 [ V_3 ] , V_44 -> V_48 ) ;
}
if ( 0 )
{
V_4:
if ( V_45 != NULL )
F_21 ( V_45 ) ;
V_45 = NULL ;
}
F_22 () ;
return ( V_45 ) ;
}
static void F_21 ( struct V_6 * V_44 )
{
int V_3 ;
if( V_44 == NULL )
return;
if ( V_44 -> V_46 != NULL )
{
for ( V_3 = 0 ; V_44 -> V_46 [ V_3 ] != NULL ; V_3 ++ )
F_23 ( V_44 -> V_46 [ V_3 ] ) ;
F_23 ( V_44 -> V_46 ) ;
}
if ( V_44 -> V_15 != NULL )
{
for ( V_3 = 0 ; V_44 -> V_15 [ V_3 ] != NULL ; V_3 ++ )
F_23 ( V_44 -> V_15 [ V_3 ] ) ;
F_23 ( V_44 -> V_15 ) ;
}
if ( V_44 -> V_47 != NULL ) F_23 ( V_44 -> V_47 ) ;
F_23 ( V_44 ) ;
}
struct V_6 * F_6 ( const char * V_42 )
{
struct V_6 * V_45 ;
int V_3 , V_49 = 0 , V_25 ;
unsigned long V_50 = ( unsigned long ) - 1 ;
#if 0
CRYPTO_w_lock(CRYPTO_LOCK_GETHOSTBYNAME);
#endif
V_25 = strlen ( V_42 ) ;
if ( V_25 < 128 )
{
for ( V_3 = 0 ; V_3 < V_38 ; V_3 ++ )
{
if ( V_50 > V_40 [ V_3 ] . V_41 )
{
V_50 = V_40 [ V_3 ] . V_41 ;
V_49 = V_3 ;
}
if ( V_40 [ V_3 ] . V_41 > 0 )
{
if ( strncmp ( V_42 , V_40 [ V_3 ] . V_42 , 128 ) == 0 )
break;
}
}
}
else
V_3 = V_38 ;
if ( V_3 == V_38 )
{
V_36 ++ ;
V_45 = F_24 (
#ifndef F_11
( char * )
#endif
V_42 ) ;
if ( V_45 == NULL )
goto V_51;
if ( V_25 > 128 )
{
#if 0
ret = NULL;
#endif
goto V_51;
}
if ( V_40 [ V_49 ] . V_52 != NULL )
F_21 ( V_40 [ V_49 ] . V_52 ) ;
V_40 [ V_49 ] . V_42 [ 0 ] = '\0' ;
if( ( V_45 = V_40 [ V_49 ] . V_52 = F_18 ( V_45 ) ) == NULL )
{
F_3 ( V_53 , V_54 ) ;
goto V_51;
}
strncpy ( V_40 [ V_49 ] . V_42 , V_42 , 128 ) ;
V_40 [ V_49 ] . V_41 = V_36 + V_34 ;
}
else
{
V_34 ++ ;
V_45 = V_40 [ V_3 ] . V_52 ;
V_40 [ V_3 ] . V_41 = V_36 + V_34 ;
}
V_51:
#if 0
CRYPTO_w_unlock(CRYPTO_LOCK_GETHOSTBYNAME);
#endif
return ( V_45 ) ;
}
int F_4 ( void )
{
#ifdef F_25
static struct V_55 V_56 ;
if ( ! V_57 )
{
int V_4 ;
#ifdef F_26
signal ( F_26 , ( void ( * ) ( int ) ) V_58 ) ;
#endif
V_57 = 1 ;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
if ( F_27 ( 0x0101 , & V_56 ) != 0 )
{
V_4 = F_28 () ;
F_13 ( V_59 , V_4 ) ;
F_3 ( V_60 , V_61 ) ;
return ( - 1 ) ;
}
}
#endif
return ( 1 ) ;
}
void V_58 ( void )
{
#ifdef F_25
if ( V_57 )
{
V_57 = 0 ;
F_29 () ;
F_30 () ;
}
#endif
}
int F_31 ( int V_62 , long type , unsigned long * V_63 )
{
int V_3 ;
V_3 = F_32 ( V_62 , type , V_63 ) ;
if ( V_3 < 0 )
F_13 ( V_64 , F_14 () ) ;
return ( V_3 ) ;
}
static int F_2 ( const char * V_1 , unsigned char V_2 [ 4 ] )
{
unsigned int V_65 [ 4 ] ;
int V_66 = 0 , V_67 , V_68 = 0 ;
V_65 [ 0 ] = V_65 [ 1 ] = V_65 [ 2 ] = V_65 [ 3 ] = 0 ;
for (; ; )
{
V_67 = * ( V_1 ++ ) ;
if ( ( V_67 >= '0' ) && ( V_67 <= '9' ) )
{
V_68 = 1 ;
V_65 [ V_66 ] = V_65 [ V_66 ] * 10 + V_67 - '0' ;
if ( V_65 [ V_66 ] > 255 ) return ( - 1 ) ;
}
else if ( V_67 == '.' )
{
if ( ! V_68 ) return ( - 1 ) ;
if ( V_66 == 3 ) break;
V_66 ++ ;
V_68 = 0 ;
}
else if ( ( V_66 == 3 ) && V_68 )
break;
else
return ( 0 ) ;
}
V_2 [ 0 ] = V_65 [ 0 ] ;
V_2 [ 1 ] = V_65 [ 1 ] ;
V_2 [ 2 ] = V_65 [ 2 ] ;
V_2 [ 3 ] = V_65 [ 3 ] ;
return ( 1 ) ;
}
int F_33 ( char * V_69 , int V_70 )
{
int V_45 = 0 ;
struct V_71 V_72 , V_73 ;
int V_18 = - 1 , V_74 ;
unsigned char V_2 [ 4 ] ;
unsigned short V_75 ;
char * V_1 , * V_76 ;
const char * V_77 , * V_32 ;
unsigned long V_78 ;
int V_79 ;
if ( ! F_4 () ) return ( V_80 ) ;
if ( ( V_1 = F_34 ( V_69 ) ) == NULL ) return ( V_80 ) ;
V_77 = V_32 = NULL ;
V_77 = V_1 ;
for ( V_76 = V_1 ; * V_76 ; V_76 ++ )
{
if ( * V_76 == ':' )
{
V_32 = & ( V_76 [ 1 ] ) ;
* V_76 = '\0' ;
}
else if ( * V_76 == '/' )
{
* V_76 = '\0' ;
break;
}
}
if ( V_32 == NULL )
{
V_32 = V_77 ;
V_77 = L_12 ;
}
if ( ! F_9 ( V_32 , & V_75 ) ) return ( V_80 ) ;
memset ( ( char * ) & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . V_81 = V_13 ;
V_72 . V_82 = F_35 ( V_75 ) ;
if ( strcmp ( V_77 , L_12 ) == 0 )
V_72 . V_83 . V_84 = V_85 ;
else
{
if ( ! F_1 ( V_77 , & ( V_2 [ 0 ] ) ) ) return ( V_80 ) ;
V_78 = ( unsigned long )
( ( unsigned long ) V_2 [ 0 ] << 24L ) |
( ( unsigned long ) V_2 [ 1 ] << 16L ) |
( ( unsigned long ) V_2 [ 2 ] << 8L ) |
( ( unsigned long ) V_2 [ 3 ] ) ;
V_72 . V_83 . V_84 = F_36 ( V_78 ) ;
}
V_86:
V_18 = F_37 ( V_13 , V_87 , V_88 ) ;
if ( V_18 == V_80 )
{
F_13 ( V_89 , F_14 () ) ;
F_8 ( 3 , L_13 , V_69 , L_11 ) ;
F_3 ( V_90 , V_91 ) ;
goto V_4;
}
#ifdef F_38
if ( V_70 == V_92 )
{
int V_3 = 1 ;
V_45 = F_39 ( V_18 , V_27 , F_38 , ( char * ) & V_3 , sizeof( V_3 ) ) ;
V_70 = V_93 ;
}
#endif
if ( F_40 ( V_18 , (struct V_94 * ) & V_72 , sizeof( V_72 ) ) == - 1 )
{
#ifdef F_38
V_79 = F_14 () ;
if ( ( V_70 == V_95 ) &&
( V_79 == V_96 ) )
{
memcpy ( ( char * ) & V_73 , ( char * ) & V_72 , sizeof( V_72 ) ) ;
if ( strcmp ( V_77 , L_12 ) == 0 )
V_73 . V_83 . V_84 = F_36 ( 0x7F000001 ) ;
V_74 = F_37 ( V_13 , V_87 , V_88 ) ;
if ( V_74 != V_80 )
{
int V_97 ;
V_97 = F_41 ( V_74 , (struct V_94 * ) & V_73 ,
sizeof( V_73 ) ) ;
F_42 ( V_74 ) ;
if ( V_97 == V_80 )
{
V_70 = V_92 ;
F_42 ( V_18 ) ;
goto V_86;
}
}
}
#endif
F_13 ( V_98 , V_79 ) ;
F_8 ( 3 , L_13 , V_69 , L_11 ) ;
F_3 ( V_90 , V_99 ) ;
goto V_4;
}
if ( F_43 ( V_18 , V_100 ) == - 1 )
{
F_13 ( V_98 , F_14 () ) ;
F_8 ( 3 , L_13 , V_69 , L_11 ) ;
F_3 ( V_90 , V_101 ) ;
goto V_4;
}
V_45 = 1 ;
V_4:
if ( V_1 != NULL ) F_23 ( V_1 ) ;
if ( ( V_45 == 0 ) && ( V_18 != V_80 ) )
{
F_42 ( V_18 ) ;
V_18 = V_80 ;
}
return ( V_18 ) ;
}
int F_44 ( int V_24 , char * * V_102 )
{
int V_45 = V_80 ;
static struct V_71 V_103 ;
unsigned long V_78 ;
unsigned short V_75 ;
int V_104 ;
char * V_32 ;
memset ( ( char * ) & V_103 , 0 , sizeof( V_103 ) ) ;
V_104 = sizeof( V_103 ) ;
V_45 = F_45 ( V_24 , (struct V_94 * ) & V_103 , ( void * ) & V_104 ) ;
if ( V_45 == V_80 )
{
F_13 ( V_105 , F_14 () ) ;
F_3 ( V_106 , V_107 ) ;
goto V_51;
}
if ( V_102 == NULL ) goto V_51;
V_78 = F_46 ( V_103 . V_83 . V_84 ) ;
V_75 = F_12 ( V_103 . V_82 ) ;
if ( * V_102 == NULL )
{
if ( ( V_32 = F_20 ( 24 ) ) == NULL )
{
F_3 ( V_106 , V_54 ) ;
goto V_51;
}
* V_102 = V_32 ;
}
sprintf ( * V_102 , L_14 ,
( unsigned char ) ( V_78 >> 24L ) & 0xff ,
( unsigned char ) ( V_78 >> 16L ) & 0xff ,
( unsigned char ) ( V_78 >> 8L ) & 0xff ,
( unsigned char ) ( V_78 ) & 0xff ,
V_75 ) ;
V_51:
return ( V_45 ) ;
}
int F_47 ( int V_18 , int V_108 )
{
int V_45 = 0 ;
#if F_48 ( V_109 ) && ( F_48 ( V_110 ) || F_48 ( V_111 ) )
int V_112 ;
#ifdef V_111
V_112 = V_111 ;
#else
#ifdef V_110
V_112 = V_110 ;
#endif
#endif
V_45 = F_39 ( V_18 , V_112 , V_109 , ( char * ) & V_108 , sizeof( V_108 ) ) ;
#endif
return ( V_45 == 0 ) ;
}
int F_49 ( int V_18 , int V_113 )
{
int V_45 = - 1 ;
unsigned long V_78 ;
V_78 = V_113 ;
#ifdef F_50
V_45 = F_31 ( V_18 , F_50 , & V_78 ) ;
#endif
return ( V_45 == 0 ) ;
}
