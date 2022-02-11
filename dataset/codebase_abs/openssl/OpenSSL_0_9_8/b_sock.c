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
#if F_26 ( V_50 ) && ! F_26 ( V_51 )
T_1 V_52 ;
T_2 V_53 ;
int V_4 ;
if ( ! V_44 )
{
# ifdef F_21
signal ( F_21 , ( void ( * ) ( int ) ) V_45 ) ;
# endif
V_44 = 1 ;
V_52 = F_27 ( 2 , 0 ) ;
V_4 = F_22 ( V_52 , & V_53 ) ;
if ( V_4 != 0 )
{
F_13 ( V_46 , V_4 ) ;
F_3 ( V_47 , V_48 ) ;
return ( - 1 ) ;
}
}
#endif
return ( 1 ) ;
}
void V_45 ( void )
{
#ifdef F_20
if ( V_44 )
{
V_44 = 0 ;
#ifndef F_28
F_29 () ;
#endif
F_30 () ;
}
#elif F_26 ( V_50 ) && ! F_26 ( V_51 )
if ( V_44 )
{
V_44 = 0 ;
F_30 () ;
}
#endif
}
int F_31 ( int V_54 , long type , void * V_55 )
{
int V_3 ;
#ifdef F_32
V_3 = F_33 ( V_54 , type , ( char * ) V_55 ) ;
#else
V_3 = F_33 ( V_54 , type , V_55 ) ;
#endif
if ( V_3 < 0 )
F_13 ( V_56 , F_14 () ) ;
return ( V_3 ) ;
}
static int F_2 ( const char * V_1 , unsigned char V_2 [ 4 ] )
{
unsigned int V_57 [ 4 ] ;
int V_58 = 0 , V_59 , V_60 = 0 ;
V_57 [ 0 ] = V_57 [ 1 ] = V_57 [ 2 ] = V_57 [ 3 ] = 0 ;
for (; ; )
{
V_59 = * ( V_1 ++ ) ;
if ( ( V_59 >= '0' ) && ( V_59 <= '9' ) )
{
V_60 = 1 ;
V_57 [ V_58 ] = V_57 [ V_58 ] * 10 + V_59 - '0' ;
if ( V_57 [ V_58 ] > 255 ) return ( 0 ) ;
}
else if ( V_59 == '.' )
{
if ( ! V_60 ) return ( - 1 ) ;
if ( V_58 == 3 ) return ( 0 ) ;
V_58 ++ ;
V_60 = 0 ;
}
else if ( V_59 == '\0' && ( V_58 == 3 ) && V_60 )
break;
else
return ( 0 ) ;
}
V_2 [ 0 ] = V_57 [ 0 ] ;
V_2 [ 1 ] = V_57 [ 1 ] ;
V_2 [ 2 ] = V_57 [ 2 ] ;
V_2 [ 3 ] = V_57 [ 3 ] ;
return ( 1 ) ;
}
int F_34 ( char * V_61 , int V_62 )
{
int V_30 = 0 ;
struct V_63 V_64 , V_65 ;
int V_18 = V_66 , V_67 ;
unsigned char V_2 [ 4 ] ;
unsigned short V_68 ;
char * V_1 = NULL , * V_69 ;
const char * V_70 , * V_71 ;
unsigned long V_72 ;
int V_73 ;
if ( F_4 () != 1 ) return ( V_66 ) ;
if ( ( V_1 = F_35 ( V_61 ) ) == NULL ) return ( V_66 ) ;
V_70 = V_71 = NULL ;
V_70 = V_1 ;
for ( V_69 = V_1 ; * V_69 ; V_69 ++ )
{
if ( * V_69 == ':' )
{
V_71 = & ( V_69 [ 1 ] ) ;
* V_69 = '\0' ;
}
else if ( * V_69 == '/' )
{
* V_69 = '\0' ;
break;
}
}
if ( V_71 == NULL )
{
V_71 = V_70 ;
V_70 = L_12 ;
}
if ( ! F_9 ( V_71 , & V_68 ) ) goto V_4;
memset ( ( char * ) & V_64 , 0 , sizeof( V_64 ) ) ;
V_64 . V_74 = V_13 ;
V_64 . V_75 = F_36 ( V_68 ) ;
if ( strcmp ( V_70 , L_12 ) == 0 )
V_64 . V_76 . V_77 = V_78 ;
else
{
if ( ! F_1 ( V_70 , & ( V_2 [ 0 ] ) ) ) goto V_4;
V_72 = ( unsigned long )
( ( unsigned long ) V_2 [ 0 ] << 24L ) |
( ( unsigned long ) V_2 [ 1 ] << 16L ) |
( ( unsigned long ) V_2 [ 2 ] << 8L ) |
( ( unsigned long ) V_2 [ 3 ] ) ;
V_64 . V_76 . V_77 = F_37 ( V_72 ) ;
}
V_79:
V_18 = F_38 ( V_13 , V_80 , V_81 ) ;
if ( V_18 == V_66 )
{
F_13 ( V_82 , F_14 () ) ;
F_8 ( 3 , L_13 , V_61 , L_11 ) ;
F_3 ( V_83 , V_84 ) ;
goto V_4;
}
#ifdef F_39
if ( V_62 == V_85 )
{
int V_3 = 1 ;
V_30 = F_40 ( V_18 , V_27 , F_39 , ( char * ) & V_3 , sizeof( V_3 ) ) ;
V_62 = V_86 ;
}
#endif
if ( F_41 ( V_18 , (struct V_87 * ) & V_64 , sizeof( V_64 ) ) == - 1 )
{
#ifdef F_39
V_73 = F_14 () ;
if ( ( V_62 == V_88 ) &&
( V_73 == V_89 ) )
{
memcpy ( ( char * ) & V_65 , ( char * ) & V_64 , sizeof( V_64 ) ) ;
if ( strcmp ( V_70 , L_12 ) == 0 )
V_65 . V_76 . V_77 = F_37 ( 0x7F000001 ) ;
V_67 = F_38 ( V_13 , V_80 , V_81 ) ;
if ( V_67 != V_66 )
{
int V_90 ;
V_90 = F_42 ( V_67 , (struct V_87 * ) & V_65 ,
sizeof( V_65 ) ) ;
F_43 ( V_67 ) ;
if ( V_90 == V_66 )
{
V_62 = V_85 ;
F_43 ( V_18 ) ;
goto V_79;
}
}
}
#endif
F_13 ( V_91 , V_73 ) ;
F_8 ( 3 , L_13 , V_61 , L_11 ) ;
F_3 ( V_83 , V_92 ) ;
goto V_4;
}
if ( F_44 ( V_18 , V_93 ) == - 1 )
{
F_13 ( V_91 , F_14 () ) ;
F_8 ( 3 , L_13 , V_61 , L_11 ) ;
F_3 ( V_83 , V_94 ) ;
goto V_4;
}
V_30 = 1 ;
V_4:
if ( V_1 != NULL ) F_45 ( V_1 ) ;
if ( ( V_30 == 0 ) && ( V_18 != V_66 ) )
{
F_43 ( V_18 ) ;
V_18 = V_66 ;
}
return ( V_18 ) ;
}
int F_46 ( int V_24 , char * * V_95 )
{
int V_30 = V_66 ;
static struct V_63 V_96 ;
unsigned long V_72 ;
unsigned short V_68 ;
int V_97 ;
char * V_71 ;
memset ( ( char * ) & V_96 , 0 , sizeof( V_96 ) ) ;
V_97 = sizeof( V_96 ) ;
V_30 = F_47 ( V_24 , (struct V_87 * ) & V_96 , ( void * ) & V_97 ) ;
if ( V_30 == V_66 )
{
if( F_48 ( V_30 ) ) return - 2 ;
F_13 ( V_98 , F_14 () ) ;
F_3 ( V_99 , V_100 ) ;
goto V_37;
}
if ( V_95 == NULL ) goto V_37;
V_72 = F_49 ( V_96 . V_76 . V_77 ) ;
V_68 = F_12 ( V_96 . V_75 ) ;
if ( * V_95 == NULL )
{
if ( ( V_71 = F_50 ( 24 ) ) == NULL )
{
F_3 ( V_99 , V_40 ) ;
goto V_37;
}
* V_95 = V_71 ;
}
F_51 ( * V_95 , 24 , L_14 ,
( unsigned char ) ( V_72 >> 24L ) & 0xff ,
( unsigned char ) ( V_72 >> 16L ) & 0xff ,
( unsigned char ) ( V_72 >> 8L ) & 0xff ,
( unsigned char ) ( V_72 ) & 0xff ,
V_68 ) ;
V_37:
return ( V_30 ) ;
}
int F_52 ( int V_18 , int V_101 )
{
int V_30 = 0 ;
#if F_26 ( V_102 ) && ( F_26 ( V_103 ) || F_26 ( V_104 ) )
int V_105 ;
#ifdef V_104
V_105 = V_104 ;
#else
#ifdef V_103
V_105 = V_103 ;
#endif
#endif
V_30 = F_40 ( V_18 , V_105 , V_102 , ( char * ) & V_101 , sizeof( V_101 ) ) ;
#endif
return ( V_30 == 0 ) ;
}
int F_53 ( int V_18 , int V_106 )
{
int V_30 = - 1 ;
int V_72 ;
V_72 = V_106 ;
#ifdef F_54
V_30 = F_31 ( V_18 , F_54 , & V_72 ) ;
#endif
return ( V_30 == 0 ) ;
}
