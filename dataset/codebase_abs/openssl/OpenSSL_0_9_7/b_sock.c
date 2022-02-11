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
struct V_6 * F_6 ( const char * V_29 )
{
#if 1
return F_17 ( V_29 ) ;
#else
struct V_6 * V_30 ;
int V_3 , V_31 = 0 , V_25 ;
unsigned long V_32 = ( unsigned long ) - 1 ;
# if 0
CRYPTO_w_lock(CRYPTO_LOCK_GETHOSTBYNAME);
# endif
V_25 = strlen ( V_29 ) ;
if ( V_25 < 128 )
{
for ( V_3 = 0 ; V_3 < V_33 ; V_3 ++ )
{
if ( V_32 > V_34 [ V_3 ] . V_35 )
{
V_32 = V_34 [ V_3 ] . V_35 ;
V_31 = V_3 ;
}
if ( V_34 [ V_3 ] . V_35 > 0 )
{
if ( strncmp ( V_29 , V_34 [ V_3 ] . V_29 , 128 ) == 0 )
break;
}
}
}
else
V_3 = V_33 ;
if ( V_3 == V_33 )
{
V_36 ++ ;
V_30 = F_17 (
# ifndef F_11
( char * )
# endif
V_29 ) ;
if ( V_30 == NULL )
goto V_37;
if ( V_25 > 128 )
{
# if 0
ret = NULL;
# endif
goto V_37;
}
if ( V_34 [ V_31 ] . V_38 != NULL )
F_18 ( V_34 [ V_31 ] . V_38 ) ;
V_34 [ V_31 ] . V_29 [ 0 ] = '\0' ;
if( ( V_30 = V_34 [ V_31 ] . V_38 = F_19 ( V_30 ) ) == NULL )
{
F_3 ( V_39 , V_40 ) ;
goto V_37;
}
strncpy ( V_34 [ V_31 ] . V_29 , V_29 , 128 ) ;
V_34 [ V_31 ] . V_35 = V_36 + V_41 ;
}
else
{
V_41 ++ ;
V_30 = V_34 [ V_3 ] . V_38 ;
V_34 [ V_3 ] . V_35 = V_36 + V_41 ;
}
V_37:
# if 0
CRYPTO_w_unlock(CRYPTO_LOCK_GETHOSTBYNAME);
# endif
return ( V_30 ) ;
#endif
}
int F_4 ( void )
{
#ifdef F_20
static struct V_42 V_43 ;
if ( ! V_44 )
{
int V_4 ;
#ifdef F_21
signal ( F_21 , ( void ( * ) ( int ) ) V_45 ) ;
#endif
V_44 = 1 ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
if ( F_22 ( 0x0101 , & V_43 ) != 0 )
{
V_4 = F_23 () ;
F_13 ( V_46 , V_4 ) ;
F_3 ( V_47 , V_48 ) ;
return ( - 1 ) ;
}
}
#endif
#ifdef F_24
extern int V_49 ;
V_49 = 0 ;
if ( F_25 () )
return ( - 1 ) ;
#endif
return ( 1 ) ;
}
void V_45 ( void )
{
#ifdef F_20
if ( V_44 )
{
V_44 = 0 ;
#ifndef F_26
F_27 () ;
#endif
F_28 () ;
}
#endif
}
int F_29 ( int V_50 , long type , unsigned long * V_51 )
{
int V_3 ;
#ifdef F_30
V_3 = F_31 ( V_50 , type , ( char * ) V_51 ) ;
#else
V_3 = F_31 ( V_50 , type , V_51 ) ;
#endif
if ( V_3 < 0 )
F_13 ( V_52 , F_14 () ) ;
return ( V_3 ) ;
}
static int F_2 ( const char * V_1 , unsigned char V_2 [ 4 ] )
{
unsigned int V_53 [ 4 ] ;
int V_54 = 0 , V_55 , V_56 = 0 ;
V_53 [ 0 ] = V_53 [ 1 ] = V_53 [ 2 ] = V_53 [ 3 ] = 0 ;
for (; ; )
{
V_55 = * ( V_1 ++ ) ;
if ( ( V_55 >= '0' ) && ( V_55 <= '9' ) )
{
V_56 = 1 ;
V_53 [ V_54 ] = V_53 [ V_54 ] * 10 + V_55 - '0' ;
if ( V_53 [ V_54 ] > 255 ) return ( 0 ) ;
}
else if ( V_55 == '.' )
{
if ( ! V_56 ) return ( - 1 ) ;
if ( V_54 == 3 ) return ( 0 ) ;
V_54 ++ ;
V_56 = 0 ;
}
else if ( V_55 == '\0' && ( V_54 == 3 ) && V_56 )
break;
else
return ( 0 ) ;
}
V_2 [ 0 ] = V_53 [ 0 ] ;
V_2 [ 1 ] = V_53 [ 1 ] ;
V_2 [ 2 ] = V_53 [ 2 ] ;
V_2 [ 3 ] = V_53 [ 3 ] ;
return ( 1 ) ;
}
int F_32 ( char * V_57 , int V_58 )
{
int V_30 = 0 ;
struct V_59 V_60 , V_61 ;
int V_18 = V_62 , V_63 ;
unsigned char V_2 [ 4 ] ;
unsigned short V_64 ;
char * V_1 = NULL , * V_65 ;
const char * V_66 , * V_67 ;
unsigned long V_68 ;
int V_69 ;
if ( F_4 () != 1 ) return ( V_62 ) ;
if ( ( V_1 = F_33 ( V_57 ) ) == NULL ) return ( V_62 ) ;
V_66 = V_67 = NULL ;
V_66 = V_1 ;
for ( V_65 = V_1 ; * V_65 ; V_65 ++ )
{
if ( * V_65 == ':' )
{
V_67 = & ( V_65 [ 1 ] ) ;
* V_65 = '\0' ;
}
else if ( * V_65 == '/' )
{
* V_65 = '\0' ;
break;
}
}
if ( V_67 == NULL )
{
V_67 = V_66 ;
V_66 = L_12 ;
}
if ( ! F_9 ( V_67 , & V_64 ) ) goto V_4;
memset ( ( char * ) & V_60 , 0 , sizeof( V_60 ) ) ;
V_60 . V_70 = V_13 ;
V_60 . V_71 = F_34 ( V_64 ) ;
if ( strcmp ( V_66 , L_12 ) == 0 )
V_60 . V_72 . V_73 = V_74 ;
else
{
if ( ! F_1 ( V_66 , & ( V_2 [ 0 ] ) ) ) goto V_4;
V_68 = ( unsigned long )
( ( unsigned long ) V_2 [ 0 ] << 24L ) |
( ( unsigned long ) V_2 [ 1 ] << 16L ) |
( ( unsigned long ) V_2 [ 2 ] << 8L ) |
( ( unsigned long ) V_2 [ 3 ] ) ;
V_60 . V_72 . V_73 = F_35 ( V_68 ) ;
}
V_75:
V_18 = F_36 ( V_13 , V_76 , V_77 ) ;
if ( V_18 == V_62 )
{
F_13 ( V_78 , F_14 () ) ;
F_8 ( 3 , L_13 , V_57 , L_11 ) ;
F_3 ( V_79 , V_80 ) ;
goto V_4;
}
#ifdef F_37
if ( V_58 == V_81 )
{
int V_3 = 1 ;
V_30 = F_38 ( V_18 , V_27 , F_37 , ( char * ) & V_3 , sizeof( V_3 ) ) ;
V_58 = V_82 ;
}
#endif
if ( F_39 ( V_18 , (struct V_83 * ) & V_60 , sizeof( V_60 ) ) == - 1 )
{
#ifdef F_37
V_69 = F_14 () ;
if ( ( V_58 == V_84 ) &&
( V_69 == V_85 ) )
{
memcpy ( ( char * ) & V_61 , ( char * ) & V_60 , sizeof( V_60 ) ) ;
if ( strcmp ( V_66 , L_12 ) == 0 )
V_61 . V_72 . V_73 = F_35 ( 0x7F000001 ) ;
V_63 = F_36 ( V_13 , V_76 , V_77 ) ;
if ( V_63 != V_62 )
{
int V_86 ;
V_86 = F_40 ( V_63 , (struct V_83 * ) & V_61 ,
sizeof( V_61 ) ) ;
F_41 ( V_63 ) ;
if ( V_86 == V_62 )
{
V_58 = V_81 ;
F_41 ( V_18 ) ;
goto V_75;
}
}
}
#endif
F_13 ( V_87 , V_69 ) ;
F_8 ( 3 , L_13 , V_57 , L_11 ) ;
F_3 ( V_79 , V_88 ) ;
goto V_4;
}
if ( F_42 ( V_18 , V_89 ) == - 1 )
{
F_13 ( V_87 , F_14 () ) ;
F_8 ( 3 , L_13 , V_57 , L_11 ) ;
F_3 ( V_79 , V_90 ) ;
goto V_4;
}
V_30 = 1 ;
V_4:
if ( V_1 != NULL ) F_43 ( V_1 ) ;
if ( ( V_30 == 0 ) && ( V_18 != V_62 ) )
{
F_41 ( V_18 ) ;
V_18 = V_62 ;
}
return ( V_18 ) ;
}
int F_44 ( int V_24 , char * * V_91 )
{
int V_30 = V_62 ;
static struct V_59 V_92 ;
unsigned long V_68 ;
unsigned short V_64 ;
int V_93 ;
char * V_67 ;
memset ( ( char * ) & V_92 , 0 , sizeof( V_92 ) ) ;
V_93 = sizeof( V_92 ) ;
V_30 = F_45 ( V_24 , (struct V_83 * ) & V_92 , ( void * ) & V_93 ) ;
if ( V_30 == V_62 )
{
if( F_46 ( V_30 ) ) return - 2 ;
F_13 ( V_94 , F_14 () ) ;
F_3 ( V_95 , V_96 ) ;
goto V_37;
}
if ( V_91 == NULL ) goto V_37;
V_68 = F_47 ( V_92 . V_72 . V_73 ) ;
V_64 = F_12 ( V_92 . V_71 ) ;
if ( * V_91 == NULL )
{
if ( ( V_67 = F_48 ( 24 ) ) == NULL )
{
F_3 ( V_95 , V_40 ) ;
goto V_37;
}
* V_91 = V_67 ;
}
sprintf ( * V_91 , L_14 ,
( unsigned char ) ( V_68 >> 24L ) & 0xff ,
( unsigned char ) ( V_68 >> 16L ) & 0xff ,
( unsigned char ) ( V_68 >> 8L ) & 0xff ,
( unsigned char ) ( V_68 ) & 0xff ,
V_64 ) ;
V_37:
return ( V_30 ) ;
}
int F_49 ( int V_18 , int V_97 )
{
int V_30 = 0 ;
#if F_50 ( V_98 ) && ( F_50 ( V_99 ) || F_50 ( V_100 ) )
int V_101 ;
#ifdef V_100
V_101 = V_100 ;
#else
#ifdef V_99
V_101 = V_99 ;
#endif
#endif
V_30 = F_38 ( V_18 , V_101 , V_98 , ( char * ) & V_97 , sizeof( V_97 ) ) ;
#endif
return ( V_30 == 0 ) ;
}
int F_51 ( int V_18 , int V_102 )
{
int V_30 = - 1 ;
unsigned long V_68 ;
V_68 = V_102 ;
#ifdef F_52
V_30 = F_29 ( V_18 , F_52 , & V_68 ) ;
#endif
return ( V_30 == 0 ) ;
}
