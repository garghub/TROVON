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
if ( F_4 () != 1 )
return 0 ;
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
#ifndef F_10
V_18 = F_11 ( ( char * ) V_1 , L_2 ) ;
#else
V_18 = F_11 ( V_1 , L_2 ) ;
#endif
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
#if F_16 ( V_27 )
return 0 ;
#endif
V_26 = sizeof( int ) ;
V_3 = F_17 ( V_24 , V_28 , V_29 , ( void * ) & V_25 , ( void * ) & V_26 ) ;
if ( V_3 < 0 )
return ( 1 ) ;
else
return ( V_25 ) ;
}
struct V_6 * F_6 ( const char * V_30 )
{
#if 1
#if ( F_16 ( V_31 ) && ! F_16 ( V_32 ) )
return F_18 ( ( char * ) V_30 ) ;
#else
return F_18 ( V_30 ) ;
#endif
#else
struct V_6 * V_33 ;
int V_3 , V_34 = 0 , V_25 ;
unsigned long V_35 = ( unsigned long ) - 1 ;
# if 0
CRYPTO_w_lock(CRYPTO_LOCK_GETHOSTBYNAME);
# endif
V_25 = strlen ( V_30 ) ;
if ( V_25 < 128 )
{
for ( V_3 = 0 ; V_3 < V_36 ; V_3 ++ )
{
if ( V_35 > V_37 [ V_3 ] . V_38 )
{
V_35 = V_37 [ V_3 ] . V_38 ;
V_34 = V_3 ;
}
if ( V_37 [ V_3 ] . V_38 > 0 )
{
if ( strncmp ( V_30 , V_37 [ V_3 ] . V_30 , 128 ) == 0 )
break;
}
}
}
else
V_3 = V_36 ;
if ( V_3 == V_36 )
{
V_39 ++ ;
# ifndef F_10
V_33 = F_18 ( ( char * ) V_30 ) ;
# else
V_33 = F_18 ( V_30 ) ;
# endif
if ( V_33 == NULL )
goto V_40;
if ( V_25 > 128 )
{
# if 0
ret = NULL;
# endif
goto V_40;
}
if ( V_37 [ V_34 ] . V_41 != NULL )
F_19 ( V_37 [ V_34 ] . V_41 ) ;
V_37 [ V_34 ] . V_30 [ 0 ] = '\0' ;
if( ( V_33 = V_37 [ V_34 ] . V_41 = F_20 ( V_33 ) ) == NULL )
{
F_3 ( V_42 , V_43 ) ;
goto V_40;
}
strncpy ( V_37 [ V_34 ] . V_30 , V_30 , 128 ) ;
V_37 [ V_34 ] . V_38 = V_39 + V_44 ;
}
else
{
V_44 ++ ;
V_33 = V_37 [ V_3 ] . V_41 ;
V_37 [ V_3 ] . V_38 = V_39 + V_44 ;
}
V_40:
# if 0
CRYPTO_w_unlock(CRYPTO_LOCK_GETHOSTBYNAME);
# endif
return ( V_33 ) ;
#endif
}
int F_4 ( void )
{
#ifdef F_21
static struct V_45 V_46 ;
if ( ! V_47 )
{
int V_4 ;
V_47 = 1 ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
if ( F_22 ( 0x0202 , & V_46 ) != 0 )
{
V_4 = F_23 () ;
F_13 ( V_48 , V_4 ) ;
F_3 ( V_49 , V_50 ) ;
return ( - 1 ) ;
}
}
#endif
#ifdef F_24
extern int V_51 ;
V_51 = 0 ;
if ( F_25 () )
return ( - 1 ) ;
#endif
#if F_16 ( V_52 ) && ! F_16 ( V_31 )
T_1 V_53 ;
T_2 V_54 ;
int V_4 ;
if ( ! V_47 )
{
V_47 = 1 ;
V_53 = F_26 ( 2 , 0 ) ;
V_4 = F_22 ( V_53 , & V_54 ) ;
if ( V_4 != 0 )
{
F_13 ( V_48 , V_4 ) ;
F_3 ( V_49 , V_50 ) ;
return ( - 1 ) ;
}
}
#endif
return ( 1 ) ;
}
void F_27 ( void )
{
#ifdef F_21
if ( V_47 )
{
V_47 = 0 ;
#if 0
WSACancelBlockingCall();
#endif
F_28 () ;
}
#elif F_16 ( V_52 ) && ! F_16 ( V_31 )
if ( V_47 )
{
V_47 = 0 ;
F_28 () ;
}
#endif
}
int F_29 ( int V_55 , long type , void * V_56 )
{
int V_3 ;
#ifdef F_30
V_3 = F_31 ( V_55 , type , ( char * ) V_56 ) ;
#else
V_3 = F_31 ( V_55 , type , V_56 ) ;
#endif
if ( V_3 < 0 )
F_13 ( V_57 , F_14 () ) ;
return ( V_3 ) ;
}
static int F_2 ( const char * V_1 , unsigned char V_2 [ 4 ] )
{
unsigned int V_58 [ 4 ] ;
int V_59 = 0 , V_60 , V_61 = 0 ;
V_58 [ 0 ] = V_58 [ 1 ] = V_58 [ 2 ] = V_58 [ 3 ] = 0 ;
for (; ; )
{
V_60 = * ( V_1 ++ ) ;
if ( ( V_60 >= '0' ) && ( V_60 <= '9' ) )
{
V_61 = 1 ;
V_58 [ V_59 ] = V_58 [ V_59 ] * 10 + V_60 - '0' ;
if ( V_58 [ V_59 ] > 255 ) return ( 0 ) ;
}
else if ( V_60 == '.' )
{
if ( ! V_61 ) return ( - 1 ) ;
if ( V_59 == 3 ) return ( 0 ) ;
V_59 ++ ;
V_61 = 0 ;
}
else if ( V_60 == '\0' && ( V_59 == 3 ) && V_61 )
break;
else
return ( 0 ) ;
}
V_2 [ 0 ] = V_58 [ 0 ] ;
V_2 [ 1 ] = V_58 [ 1 ] ;
V_2 [ 2 ] = V_58 [ 2 ] ;
V_2 [ 3 ] = V_58 [ 3 ] ;
return ( 1 ) ;
}
int F_32 ( char * V_62 , int V_63 )
{
int V_33 = 0 ;
union {
struct V_64 V_65 ;
struct V_66 V_67 ;
#if V_68
struct V_69 V_70 ;
#endif
} V_71 , V_72 ;
int V_18 = V_73 , V_74 , V_75 ;
unsigned char V_2 [ 4 ] ;
unsigned short V_76 ;
char * V_1 = NULL , * V_77 ;
char * V_78 , * V_79 ;
unsigned long V_80 ;
int V_81 ;
if ( F_4 () != 1 ) return ( V_73 ) ;
if ( ( V_1 = F_33 ( V_62 ) ) == NULL ) return ( V_73 ) ;
V_78 = V_79 = NULL ;
V_78 = V_1 ;
for ( V_77 = V_1 ; * V_77 ; V_77 ++ )
{
if ( * V_77 == ':' )
{
V_79 = V_77 ;
}
else if ( * V_77 == '/' )
{
* V_77 = '\0' ;
break;
}
}
if ( V_79 ) * V_79 ++ = '\0' ;
else V_79 = V_78 , V_78 = NULL ;
#ifdef F_34
do {
static union { void * V_79 ;
int (F_35 * F_36)( const char * , const char * ,
const struct V_82 * ,
struct V_82 * * );
} V_83 = { NULL } ;
static union { void * V_79 ;
void (F_35 * F_36)( struct V_82 * );
} V_84 = { NULL } ;
struct V_82 * V_85 , V_86 ;
if ( V_83 . V_79 == NULL )
{
if ( ( V_83 . V_79 = F_37 ( L_12 ) ) == NULL ||
( V_84 . V_79 = F_37 ( L_13 ) ) == NULL )
V_83 . V_79 = ( void * ) - 1 ;
}
if ( V_83 . V_79 == ( void * ) - 1 ) break;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
if ( V_78 )
{
if ( strchr ( V_78 , ':' ) )
{
if ( V_78 [ 1 ] == '\0' ) V_78 = NULL ;
#if V_68
V_86 . V_87 = V_88 ;
#else
V_78 = NULL ;
#endif
}
else if ( V_78 [ 0 ] == '*' && V_78 [ 1 ] == '\0' )
V_78 = NULL ;
}
if ( (* V_83 . F_36 )( V_78 , V_79 , & V_86 , & V_85 ) ) break;
V_75 = V_85 -> V_89 <= sizeof( V_71 ) ?
V_85 -> V_89 :
sizeof( V_71 ) ;
memcpy ( & V_71 , V_85 -> V_90 , V_75 ) ;
(* V_84 . F_36 )( V_85 ) ;
goto V_91;
} while ( 0 );
#endif
if ( ! F_9 ( V_79 , & V_76 ) ) goto V_4;
memset ( ( char * ) & V_71 , 0 , sizeof( V_71 ) ) ;
V_71 . V_67 . V_92 = V_13 ;
V_71 . V_67 . V_93 = F_38 ( V_76 ) ;
V_75 = sizeof( V_71 . V_67 ) ;
if ( V_78 == NULL || strcmp ( V_78 , L_14 ) == 0 )
V_71 . V_67 . V_94 . V_95 = V_96 ;
else
{
if ( ! F_1 ( V_78 , & ( V_2 [ 0 ] ) ) ) goto V_4;
V_80 = ( unsigned long )
( ( unsigned long ) V_2 [ 0 ] << 24L ) |
( ( unsigned long ) V_2 [ 1 ] << 16L ) |
( ( unsigned long ) V_2 [ 2 ] << 8L ) |
( ( unsigned long ) V_2 [ 3 ] ) ;
V_71 . V_67 . V_94 . V_95 = F_39 ( V_80 ) ;
}
V_91:
V_18 = F_40 ( V_71 . V_65 . V_97 , V_98 , V_99 ) ;
if ( V_18 == V_73 )
{
F_13 ( V_100 , F_14 () ) ;
F_8 ( 3 , L_15 , V_62 , L_11 ) ;
F_3 ( V_101 , V_102 ) ;
goto V_4;
}
#ifdef F_41
if ( V_63 == V_103 )
{
int V_3 = 1 ;
V_33 = F_42 ( V_18 , V_28 , F_41 , ( char * ) & V_3 , sizeof( V_3 ) ) ;
V_63 = V_104 ;
}
#endif
if ( F_43 ( V_18 , & V_71 . V_65 , V_75 ) == - 1 )
{
#ifdef F_41
V_81 = F_14 () ;
if ( ( V_63 == V_105 ) &&
( V_81 == V_106 ) )
{
V_72 = V_71 ;
if ( V_78 == NULL || strcmp ( V_78 , L_14 ) == 0 )
{
#if V_68
if ( V_72 . V_65 . V_97 == V_88 )
{
memset ( & V_72 . V_70 . V_107 , 0 , sizeof( V_72 . V_70 . V_107 ) ) ;
V_72 . V_70 . V_107 . V_108 [ 15 ] = 1 ;
}
else
#endif
if ( V_72 . V_65 . V_97 == V_13 )
{
V_72 . V_67 . V_94 . V_95 = F_39 ( 0x7F000001 ) ;
}
else goto V_4;
}
V_74 = F_40 ( V_72 . V_65 . V_97 , V_98 , V_99 ) ;
if ( V_74 != V_73 )
{
int V_109 ;
V_109 = F_44 ( V_74 , & V_72 . V_65 , V_75 ) ;
F_45 ( V_74 ) ;
if ( V_109 == V_73 )
{
V_63 = V_103 ;
F_45 ( V_18 ) ;
goto V_91;
}
}
}
#endif
F_13 ( V_110 , V_81 ) ;
F_8 ( 3 , L_15 , V_62 , L_11 ) ;
F_3 ( V_101 , V_111 ) ;
goto V_4;
}
if ( F_46 ( V_18 , V_112 ) == - 1 )
{
F_13 ( V_110 , F_14 () ) ;
F_8 ( 3 , L_15 , V_62 , L_11 ) ;
F_3 ( V_101 , V_113 ) ;
goto V_4;
}
V_33 = 1 ;
V_4:
if ( V_1 != NULL ) F_47 ( V_1 ) ;
if ( ( V_33 == 0 ) && ( V_18 != V_73 ) )
{
F_45 ( V_18 ) ;
V_18 = V_73 ;
}
return ( V_18 ) ;
}
int F_48 ( int V_24 , char * * V_114 )
{
int V_33 = V_73 ;
unsigned long V_80 ;
unsigned short V_76 ;
char * V_79 ;
struct {
union { T_3 V_18 ; int V_3 ; } V_115 ;
union {
struct V_64 V_65 ;
struct V_66 V_67 ;
#if V_68
struct V_69 V_70 ;
#endif
} V_116 ;
} V_65 ;
V_65 . V_115 . V_18 = 0 ;
V_65 . V_115 . V_3 = sizeof( V_65 . V_116 ) ;
memset ( & V_65 . V_116 , 0 , sizeof( V_65 . V_116 ) ) ;
V_33 = F_49 ( V_24 , & V_65 . V_116 . V_65 , ( void * ) & V_65 . V_115 ) ;
if ( sizeof( V_65 . V_115 . V_3 ) != sizeof( V_65 . V_115 . V_18 ) && V_65 . V_115 . V_3 == 0 )
{
F_50 ( V_65 . V_115 . V_18 <= sizeof( V_65 . V_116 ) ) ;
V_65 . V_115 . V_3 = ( int ) V_65 . V_115 . V_18 ;
}
if ( V_33 == V_73 )
{
if( F_51 ( V_33 ) ) return - 2 ;
F_13 ( V_117 , F_14 () ) ;
F_3 ( V_118 , V_119 ) ;
goto V_40;
}
if ( V_114 == NULL ) goto V_40;
#ifdef F_34
do {
char V_78 [ V_120 ] , V_18 [ V_121 ] ;
T_3 V_122 ;
static union { void * V_79 ;
int (F_35 * F_36)( const struct V_64 * , T_3 ,
char * , T_3 , char * , T_3 , int );
} V_123 = { NULL } ;
if ( V_123 . V_79 == NULL )
{
if ( ( V_123 . V_79 = F_37 ( L_16 ) ) == NULL )
V_123 . V_79 = ( void * ) - 1 ;
}
if ( V_123 . V_79 == ( void * ) - 1 ) break;
if ( (* V_123 . F_36 )( & V_65 . V_116 . V_65 , V_65 . V_115 . V_3 , V_78 , sizeof( V_78 ) , V_18 , sizeof( V_18 ) ,
V_124 | V_125 ) ) break;
V_122 = strlen ( V_78 ) + strlen ( V_18 ) + 2 ;
V_79 = * V_114 ;
if ( V_79 ) { * V_79 = '\0' ; V_79 = F_52 ( V_79 , V_122 ) ; }
else { V_79 = F_53 ( V_122 ) ; }
if ( V_79 == NULL )
{
F_3 ( V_118 , V_43 ) ;
goto V_40;
}
* V_114 = V_79 ;
F_54 ( * V_114 , V_122 , L_17 , V_78 , V_18 ) ;
goto V_40;
} while( 0 );
#endif
if ( V_65 . V_116 . V_65 . V_97 != V_13 ) goto V_40;
V_80 = F_55 ( V_65 . V_116 . V_67 . V_94 . V_95 ) ;
V_76 = F_12 ( V_65 . V_116 . V_67 . V_93 ) ;
if ( * V_114 == NULL )
{
if ( ( V_79 = F_53 ( 24 ) ) == NULL )
{
F_3 ( V_118 , V_43 ) ;
goto V_40;
}
* V_114 = V_79 ;
}
F_54 ( * V_114 , 24 , L_18 ,
( unsigned char ) ( V_80 >> 24L ) & 0xff ,
( unsigned char ) ( V_80 >> 16L ) & 0xff ,
( unsigned char ) ( V_80 >> 8L ) & 0xff ,
( unsigned char ) ( V_80 ) & 0xff ,
V_76 ) ;
V_40:
return ( V_33 ) ;
}
int F_56 ( int V_18 , int V_126 )
{
int V_33 = 0 ;
#if F_16 ( V_127 ) && ( F_16 ( V_128 ) || F_16 ( V_129 ) )
int V_130 ;
#ifdef V_129
V_130 = V_129 ;
#else
#ifdef V_128
V_130 = V_128 ;
#endif
#endif
V_33 = F_42 ( V_18 , V_130 , V_127 , ( char * ) & V_126 , sizeof( V_126 ) ) ;
#endif
return ( V_33 == 0 ) ;
}
int F_57 ( int V_18 , int V_131 )
{
int V_33 = - 1 ;
int V_80 ;
V_80 = V_131 ;
#ifdef F_58
V_33 = F_29 ( V_18 , F_58 , & V_80 ) ;
#endif
return ( V_33 == 0 ) ;
}
