int F_1 ( const char * V_1 , unsigned char * V_2 )
{
int V_3 ;
int V_4 = 1 ;
int V_5 = 0 ;
struct V_6 * V_7 ;
V_3 = F_2 ( V_1 , V_2 ) ;
if ( V_3 < 0 ) {
F_3 ( V_8 , V_9 ) ;
goto V_4;
}
if ( F_4 () != 1 )
return 0 ;
if ( V_3 > 0 )
return ( 1 ) ;
F_5 ( V_10 ) ;
V_5 = 1 ;
V_7 = F_6 ( V_1 ) ;
if ( V_7 == NULL ) {
F_3 ( V_8 , V_11 ) ;
goto V_4;
}
if ( ( short ) V_7 -> V_12 != V_13 ) {
F_3 ( V_8 ,
V_14 ) ;
goto V_4;
}
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ )
V_2 [ V_3 ] = V_7 -> V_15 [ 0 ] [ V_3 ] ;
V_4 = 0 ;
V_4:
if ( V_5 )
F_7 ( V_10 ) ;
if ( V_4 ) {
F_8 ( 2 , L_1 , V_1 ) ;
return 0 ;
} else
return 1 ;
}
int F_9 ( const char * V_1 , unsigned short * V_16 )
{
int V_3 ;
struct V_17 * V_18 ;
if ( V_1 == NULL ) {
F_3 ( V_19 , V_20 ) ;
return ( 0 ) ;
}
V_3 = atoi ( V_1 ) ;
if ( V_3 != 0 )
* V_16 = ( unsigned short ) V_3 ;
else {
F_5 ( V_21 ) ;
# ifndef F_10
V_18 = F_11 ( ( char * ) V_1 , L_2 ) ;
# else
V_18 = F_11 ( V_1 , L_2 ) ;
# endif
if ( V_18 != NULL )
* V_16 = F_12 ( ( unsigned short ) V_18 -> V_22 ) ;
F_7 ( V_21 ) ;
if ( V_18 == NULL ) {
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
# if 0
else if (strcmp(str, "wais") == 0)
*port_ptr = 21;
# endif
else {
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
union {
T_1 V_18 ;
int V_3 ;
} V_26 ;
# if F_16 ( V_27 )
return 0 ;
# endif
V_26 . V_18 = 0 , V_26 . V_3 = sizeof( V_25 ) ;
V_3 = F_17 ( V_24 , V_28 , V_29 , ( void * ) & V_25 , ( void * ) & V_26 ) ;
if ( V_3 < 0 )
return ( 1 ) ;
else
return ( V_25 ) ;
}
struct V_6 * F_6 ( const char * V_30 )
{
# if 1
# if ( F_16 ( V_31 ) && ! F_16 ( V_32 ) )
return F_18 ( ( char * ) V_30 ) ;
# else
return F_18 ( V_30 ) ;
# endif
# else
struct V_6 * V_33 ;
int V_3 , V_34 = 0 , V_25 ;
unsigned long V_35 = ( unsigned long ) - 1 ;
# if 0
CRYPTO_w_lock(CRYPTO_LOCK_GETHOSTBYNAME);
# endif
V_25 = strlen ( V_30 ) ;
if ( V_25 < 128 ) {
for ( V_3 = 0 ; V_3 < V_36 ; V_3 ++ ) {
if ( V_35 > V_37 [ V_3 ] . V_38 ) {
V_35 = V_37 [ V_3 ] . V_38 ;
V_34 = V_3 ;
}
if ( V_37 [ V_3 ] . V_38 > 0 ) {
if ( strncmp ( V_30 , V_37 [ V_3 ] . V_30 , 128 ) == 0 )
break;
}
}
} else
V_3 = V_36 ;
if ( V_3 == V_36 ) {
V_39 ++ ;
# ifndef F_10
V_33 = F_18 ( ( char * ) V_30 ) ;
# else
V_33 = F_18 ( V_30 ) ;
# endif
if ( V_33 == NULL )
goto V_40;
if ( V_25 > 128 ) {
# if 0
ret = NULL;
# endif
goto V_40;
}
if ( V_37 [ V_34 ] . V_41 != NULL )
F_19 ( V_37 [ V_34 ] . V_41 ) ;
V_37 [ V_34 ] . V_30 [ 0 ] = '\0' ;
if ( ( V_33 = V_37 [ V_34 ] . V_41 = F_20 ( V_33 ) ) == NULL ) {
F_3 ( V_42 , V_43 ) ;
goto V_40;
}
strncpy ( V_37 [ V_34 ] . V_30 , V_30 , 128 ) ;
V_37 [ V_34 ] . V_38 = V_39 + V_44 ;
} else {
V_44 ++ ;
V_33 = V_37 [ V_3 ] . V_41 ;
V_37 [ V_3 ] . V_38 = V_39 + V_44 ;
}
V_40:
# if 0
CRYPTO_w_unlock(CRYPTO_LOCK_GETHOSTBYNAME);
# endif
return ( V_33 ) ;
# endif
}
int F_4 ( void )
{
# ifdef F_21
static struct V_45 V_46 ;
if ( ! V_47 ) {
int V_4 ;
V_47 = 1 ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
if ( F_22 ( 0x0202 , & V_46 ) != 0 ) {
V_4 = F_23 () ;
F_13 ( V_48 , V_4 ) ;
F_3 ( V_49 , V_50 ) ;
return ( - 1 ) ;
}
}
# endif
# ifdef F_24
extern int V_51 ;
V_51 = 0 ;
if ( F_25 () )
return ( - 1 ) ;
# endif
# if F_16 ( V_52 ) && ! F_16 ( V_31 )
T_2 V_53 ;
T_3 V_54 ;
int V_4 ;
if ( ! V_47 ) {
V_47 = 1 ;
V_53 = F_26 ( 2 , 0 ) ;
V_4 = F_22 ( V_53 , & V_54 ) ;
if ( V_4 != 0 ) {
F_13 ( V_48 , V_4 ) ;
F_3 ( V_49 , V_50 ) ;
return ( - 1 ) ;
}
}
# endif
return ( 1 ) ;
}
void F_27 ( void )
{
# ifdef F_21
if ( V_47 ) {
V_47 = 0 ;
# if 0
WSACancelBlockingCall();
# endif
F_28 () ;
}
# elif F_16 ( V_52 ) && ! F_16 ( V_31 )
if ( V_47 ) {
V_47 = 0 ;
F_28 () ;
}
# endif
}
int F_29 ( int V_55 , long type , void * V_56 )
{
int V_3 ;
# ifdef F_30
V_3 = F_31 ( V_55 , type , ( char * ) V_56 ) ;
# else
# if F_16 ( V_57 )
# if V_58 == 64
# define F_32 arg_32p
# pragma V_59 V_60
# pragma V_59 V_61
unsigned long V_62 ;
unsigned long * V_63 ;
# pragma V_59 V_64
V_63 = & V_62 ;
V_62 = * ( ( unsigned long * ) V_56 ) ;
# else
# define F_32 arg
# endif
# else
# define F_32 arg
# endif
V_3 = F_31 ( V_55 , type , F_32 ) ;
# endif
if ( V_3 < 0 )
F_13 ( V_65 , F_14 () ) ;
return ( V_3 ) ;
}
static int F_2 ( const char * V_1 , unsigned char V_2 [ 4 ] )
{
unsigned int V_66 [ 4 ] ;
int V_67 = 0 , V_68 , V_69 = 0 ;
V_66 [ 0 ] = V_66 [ 1 ] = V_66 [ 2 ] = V_66 [ 3 ] = 0 ;
for (; ; ) {
V_68 = * ( V_1 ++ ) ;
if ( ( V_68 >= '0' ) && ( V_68 <= '9' ) ) {
V_69 = 1 ;
V_66 [ V_67 ] = V_66 [ V_67 ] * 10 + V_68 - '0' ;
if ( V_66 [ V_67 ] > 255 )
return ( 0 ) ;
} else if ( V_68 == '.' ) {
if ( ! V_69 )
return ( - 1 ) ;
if ( V_67 == 3 )
return ( 0 ) ;
V_67 ++ ;
V_69 = 0 ;
} else if ( V_68 == '\0' && ( V_67 == 3 ) && V_69 )
break;
else
return ( 0 ) ;
}
V_2 [ 0 ] = V_66 [ 0 ] ;
V_2 [ 1 ] = V_66 [ 1 ] ;
V_2 [ 2 ] = V_66 [ 2 ] ;
V_2 [ 3 ] = V_66 [ 3 ] ;
return ( 1 ) ;
}
int F_33 ( char * V_70 , int V_71 )
{
int V_33 = 0 ;
union {
struct V_72 V_73 ;
struct V_74 V_75 ;
# if V_76
struct V_77 V_78 ;
# endif
} V_79 , V_80 ;
int V_18 = V_81 , V_82 , V_83 ;
unsigned char V_2 [ 4 ] ;
unsigned short V_84 ;
char * V_1 = NULL , * V_85 ;
char * V_86 , * V_87 ;
unsigned long V_88 ;
int V_89 ;
if ( F_4 () != 1 )
return ( V_81 ) ;
if ( ( V_1 = F_34 ( V_70 ) ) == NULL )
return ( V_81 ) ;
V_86 = V_87 = NULL ;
V_86 = V_1 ;
for ( V_85 = V_1 ; * V_85 ; V_85 ++ ) {
if ( * V_85 == ':' ) {
V_87 = V_85 ;
} else if ( * V_85 == '/' ) {
* V_85 = '\0' ;
break;
}
}
if ( V_87 )
* V_87 ++ = '\0' ;
else
V_87 = V_86 , V_86 = NULL ;
# ifdef F_35
do {
static union {
void * V_87 ;
int (F_36 * F_37) ( const char * , const char * ,
const struct V_90 * , struct V_90 * * );
} V_91 = {
NULL
} ;
static union {
void * V_87 ;
void (F_36 * F_37) ( struct V_90 * );
} V_92 = {
NULL
} ;
struct V_90 * V_93 , V_94 ;
if ( V_91 . V_87 == NULL ) {
if ( ( V_91 . V_87 = F_38 ( L_12 ) ) == NULL
|| ( V_92 . V_87 =
F_38 ( L_13 ) ) == NULL )
V_91 . V_87 = ( void * ) - 1 ;
}
if ( V_91 . V_87 == ( void * ) - 1 )
break;
memset ( & V_94 , 0 , sizeof( V_94 ) ) ;
V_94 . V_95 = V_96 ;
if ( V_86 ) {
if ( strchr ( V_86 , ':' ) ) {
if ( V_86 [ 1 ] == '\0' )
V_86 = NULL ;
# if V_76
V_94 . V_97 = V_98 ;
# else
V_86 = NULL ;
# endif
} else if ( V_86 [ 0 ] == '*' && V_86 [ 1 ] == '\0' ) {
V_94 . V_97 = V_13 ;
V_86 = NULL ;
}
}
if ( (* V_91 . F_37 ) ( V_86 , V_87 , & V_94 , & V_93 ) )
break;
V_83 = V_93 -> V_99 <= sizeof( V_79 ) ?
V_93 -> V_99 : sizeof( V_79 ) ;
memcpy ( & V_79 , V_93 -> V_100 , V_83 ) ;
(* V_92 . F_37 ) ( V_93 ) ;
goto V_101;
} while ( 0 );
# endif
if ( ! F_9 ( V_87 , & V_84 ) )
goto V_4;
memset ( ( char * ) & V_79 , 0 , sizeof( V_79 ) ) ;
V_79 . V_75 . V_102 = V_13 ;
V_79 . V_75 . V_103 = F_39 ( V_84 ) ;
V_83 = sizeof( V_79 . V_75 ) ;
if ( V_86 == NULL || strcmp ( V_86 , L_14 ) == 0 )
V_79 . V_75 . V_104 . V_105 = V_106 ;
else {
if ( ! F_1 ( V_86 , & ( V_2 [ 0 ] ) ) )
goto V_4;
V_88 = ( unsigned long )
( ( unsigned long ) V_2 [ 0 ] << 24L ) |
( ( unsigned long ) V_2 [ 1 ] << 16L ) |
( ( unsigned long ) V_2 [ 2 ] << 8L ) | ( ( unsigned long ) V_2 [ 3 ] ) ;
V_79 . V_75 . V_104 . V_105 = F_40 ( V_88 ) ;
}
V_101:
V_18 = F_41 ( V_79 . V_73 . V_107 , V_108 , V_109 ) ;
if ( V_18 == V_81 ) {
F_13 ( V_110 , F_14 () ) ;
F_8 ( 3 , L_15 , V_70 , L_11 ) ;
F_3 ( V_111 , V_112 ) ;
goto V_4;
}
# ifdef F_42
if ( V_71 == V_113 ) {
int V_3 = 1 ;
V_33 = F_43 ( V_18 , V_28 , F_42 , ( char * ) & V_3 , sizeof( V_3 ) ) ;
V_71 = V_114 ;
}
# endif
if ( F_44 ( V_18 , & V_79 . V_73 , V_83 ) == - 1 ) {
# ifdef F_42
V_89 = F_14 () ;
if ( ( V_71 == V_115 ) &&
# ifdef F_21
( V_89 == V_116 ) )
# else
( V_89 == V_117 ) )
# endif
{
V_80 = V_79 ;
if ( V_86 == NULL || strcmp ( V_86 , L_14 ) == 0 ) {
# if V_76
if ( V_80 . V_73 . V_107 == V_98 ) {
memset ( & V_80 . V_78 . V_118 , 0 ,
sizeof( V_80 . V_78 . V_118 ) ) ;
V_80 . V_78 . V_118 . V_119 [ 15 ] = 1 ;
} else
# endif
if ( V_80 . V_73 . V_107 == V_13 ) {
V_80 . V_75 . V_104 . V_105 = F_40 ( 0x7F000001 ) ;
} else
goto V_4;
}
V_82 = F_41 ( V_80 . V_73 . V_107 , V_108 , V_109 ) ;
if ( V_82 != V_81 ) {
int V_120 ;
V_120 = F_45 ( V_82 , & V_80 . V_73 , V_83 ) ;
F_46 ( V_82 ) ;
if ( V_120 == V_81 ) {
V_71 = V_113 ;
F_46 ( V_18 ) ;
goto V_101;
}
}
}
# endif
F_13 ( V_121 , V_89 ) ;
F_8 ( 3 , L_15 , V_70 , L_11 ) ;
F_3 ( V_111 , V_122 ) ;
goto V_4;
}
int F_47 ( int V_18 , int V_123 )
{
int V_33 = 0 ;
# if F_16 ( V_124 ) && ( F_16 ( V_125 ) || F_16 ( V_126 ) )
int V_127 ;
# ifdef V_126
V_127 = V_126 ;
# else
# ifdef V_125
V_127 = V_125 ;
# endif
# endif
V_33 = F_43 ( V_18 , V_127 , V_124 , ( char * ) & V_123 , sizeof( V_123 ) ) ;
# endif
return ( V_33 == 0 ) ;
}
int F_48 ( int V_18 , int V_128 )
{
int V_33 = - 1 ;
int V_88 ;
V_88 = V_128 ;
# ifdef F_49
V_33 = F_29 ( V_18 , F_49 , & V_88 ) ;
# endif
return ( V_33 == 0 ) ;
}
