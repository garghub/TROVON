int F_1 ( const char * V_1 , unsigned char * V_2 )
{
int V_3 ;
struct V_4 * V_5 ;
V_3 = F_2 ( V_1 , V_2 ) ;
if ( V_3 > 0 ) return ( 1 ) ;
if ( V_3 < 0 )
{
F_3 ( V_6 , V_7 ) ;
F_4 ( 2 , L_1 , V_1 ) ;
return ( 0 ) ;
}
else
{
if ( ! F_5 () ) return ( 0 ) ;
V_5 = F_6 ( V_1 ) ;
if ( V_5 == NULL )
{
F_3 ( V_6 , V_8 ) ;
F_4 ( 2 , L_1 , V_1 ) ;
return ( 0 ) ;
}
if ( ( short ) V_5 -> V_9 != V_10 )
{
F_3 ( V_6 , V_11 ) ;
F_4 ( 2 , L_1 , V_1 ) ;
return ( 0 ) ;
}
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ )
V_2 [ V_3 ] = V_5 -> V_12 [ 0 ] [ V_3 ] ;
}
return ( 1 ) ;
}
int F_7 ( const char * V_1 , unsigned short * V_13 )
{
int V_3 ;
struct V_14 * V_15 ;
if ( V_1 == NULL )
{
F_3 ( V_16 , V_17 ) ;
return ( 0 ) ;
}
V_3 = atoi ( V_1 ) ;
if ( V_3 != 0 )
* V_13 = ( unsigned short ) V_3 ;
else
{
F_8 ( V_18 ) ;
V_15 = F_9 ( V_1 , L_2 ) ;
if( V_15 != NULL )
* V_13 = F_10 ( ( unsigned short ) V_15 -> V_19 ) ;
F_11 ( V_18 ) ;
if( V_15 == NULL )
{
if ( strcmp ( V_1 , L_3 ) == 0 )
* V_13 = 80 ;
else if ( strcmp ( V_1 , L_4 ) == 0 )
* V_13 = 23 ;
else if ( strcmp ( V_1 , L_5 ) == 0 )
* V_13 = 1080 ;
else if ( strcmp ( V_1 , L_6 ) == 0 )
* V_13 = 443 ;
else if ( strcmp ( V_1 , L_7 ) == 0 )
* V_13 = 443 ;
else if ( strcmp ( V_1 , L_8 ) == 0 )
* V_13 = 21 ;
else if ( strcmp ( V_1 , L_9 ) == 0 )
* V_13 = 70 ;
#if 0
else if (strcmp(str,"wais") == 0)
*port_ptr=21;
#endif
else
{
F_12 ( V_20 , F_13 () ) ;
F_4 ( 3 , L_10 , V_1 , L_11 ) ;
return ( 0 ) ;
}
}
}
return ( 1 ) ;
}
int F_14 ( int V_21 )
{
int V_22 , V_3 ;
int V_23 ;
V_23 = sizeof( int ) ;
V_3 = F_15 ( V_21 , V_24 , V_25 , ( void * ) & V_22 , ( void * ) & V_23 ) ;
if ( V_3 < 0 )
return ( 1 ) ;
else
return ( V_22 ) ;
}
long F_16 ( int V_26 , int V_27 , char * V_28 )
{
int V_3 ;
char * * V_29 ;
switch ( V_26 )
{
case V_30 :
return ( V_31 ) ;
case V_32 :
return ( V_33 ) ;
case V_34 :
return ( V_35 ) ;
case V_36 :
if ( ( V_27 >= 0 ) && ( V_27 < V_35 ) &&
( V_37 [ V_27 ] . V_38 > 0 ) )
{
V_29 = ( char * * ) V_28 ;
if ( V_29 == NULL ) return ( 0 ) ;
* V_29 = V_37 [ V_27 ] . V_39 ;
V_37 [ V_27 ] . V_39 [ 128 ] = '\0' ;
return ( 1 ) ;
}
return ( 0 ) ;
case V_40 :
for ( V_3 = 0 ; V_3 < V_35 ; V_3 ++ )
V_37 [ V_3 ] . V_38 = 0 ;
break;
default:
return ( 0 ) ;
}
return ( 1 ) ;
}
static struct V_4 * F_17 ( struct V_4 * V_41 )
{
struct V_4 * V_42 ;
int V_3 , V_22 ;
F_18 () ;
V_42 = (struct V_4 * ) Malloc ( sizeof( struct V_4 ) ) ;
if ( V_42 == NULL ) return ( NULL ) ;
memset ( V_42 , 0 , sizeof( struct V_4 ) ) ;
for ( V_3 = 0 ; V_41 -> V_43 [ V_3 ] != NULL ; V_3 ++ )
;
V_3 ++ ;
V_42 -> V_43 = ( char * * ) Malloc ( V_3 * sizeof( char * ) ) ;
if ( V_42 -> V_43 == NULL )
goto V_44;
memset ( V_42 -> V_43 , 0 , V_3 * sizeof( char * ) ) ;
for ( V_3 = 0 ; V_41 -> V_12 [ V_3 ] != NULL ; V_3 ++ )
;
V_3 ++ ;
V_42 -> V_12 = ( char * * ) Malloc ( V_3 * sizeof( char * ) ) ;
if ( V_42 -> V_12 == NULL )
goto V_44;
memset ( V_42 -> V_12 , 0 , V_3 * sizeof( char * ) ) ;
V_22 = strlen ( V_41 -> V_45 ) + 1 ;
if ( ( V_42 -> V_45 = Malloc ( V_22 ) ) == NULL ) goto V_44;
memcpy ( ( char * ) V_42 -> V_45 , V_41 -> V_45 , V_22 + 1 ) ;
for ( V_3 = 0 ; V_41 -> V_43 [ V_3 ] != NULL ; V_3 ++ )
{
V_22 = strlen ( V_41 -> V_43 [ V_3 ] ) + 1 ;
if ( ( V_42 -> V_43 [ V_3 ] = Malloc ( V_22 ) ) == NULL ) goto V_44;
memcpy ( V_42 -> V_43 [ V_3 ] , V_41 -> V_43 [ V_3 ] , V_22 + 1 ) ;
}
V_42 -> V_46 = V_41 -> V_46 ;
V_42 -> V_9 = V_41 -> V_9 ;
for ( V_3 = 0 ; V_41 -> V_12 [ V_3 ] != NULL ; V_3 ++ )
{
if ( ( V_42 -> V_12 [ V_3 ] = Malloc ( V_41 -> V_46 ) ) == NULL )
goto V_44;
memcpy ( V_42 -> V_12 [ V_3 ] , V_41 -> V_12 [ V_3 ] , V_41 -> V_46 ) ;
}
if ( 0 )
{
V_44:
if ( V_42 != NULL )
F_19 ( V_42 ) ;
V_42 = NULL ;
}
F_20 () ;
return ( V_42 ) ;
}
static void F_19 ( struct V_4 * V_41 )
{
int V_3 ;
if( V_41 == NULL )
return;
if ( V_41 -> V_43 != NULL )
{
for ( V_3 = 0 ; V_41 -> V_43 [ V_3 ] != NULL ; V_3 ++ )
Free ( V_41 -> V_43 [ V_3 ] ) ;
Free ( V_41 -> V_43 ) ;
}
if ( V_41 -> V_12 != NULL )
{
for ( V_3 = 0 ; V_41 -> V_12 [ V_3 ] != NULL ; V_3 ++ )
Free ( V_41 -> V_12 [ V_3 ] ) ;
Free ( V_41 -> V_12 ) ;
}
if ( V_41 -> V_45 != NULL ) Free ( ( char * ) V_41 -> V_45 ) ;
Free ( V_41 ) ;
}
struct V_4 * F_6 ( const char * V_39 )
{
struct V_4 * V_42 ;
int V_3 , V_47 = 0 , V_22 ;
unsigned long V_48 = ( unsigned long ) - 1 ;
F_8 ( V_49 ) ;
V_22 = strlen ( V_39 ) ;
if ( V_22 < 128 )
{
for ( V_3 = 0 ; V_3 < V_35 ; V_3 ++ )
{
if ( V_48 > V_37 [ V_3 ] . V_38 )
{
V_48 = V_37 [ V_3 ] . V_38 ;
V_47 = V_3 ;
}
if ( V_37 [ V_3 ] . V_38 > 0 )
{
if ( strncmp ( V_39 , V_37 [ V_3 ] . V_39 , 128 ) == 0 )
break;
}
}
}
else
V_3 = V_35 ;
if ( V_3 == V_35 )
{
V_33 ++ ;
V_42 = F_21 ( V_39 ) ;
if ( V_42 == NULL )
goto V_50;
if ( V_22 > 128 )
{
V_42 = NULL ;
goto V_50;
}
if ( V_37 [ V_47 ] . V_51 != NULL )
F_19 ( V_37 [ V_47 ] . V_51 ) ;
V_37 [ V_47 ] . V_39 [ 0 ] = '\0' ;
if( ( V_42 = V_37 [ V_47 ] . V_51 = F_17 ( V_42 ) ) == NULL )
{
F_3 ( V_52 , V_53 ) ;
goto V_50;
}
strncpy ( V_37 [ V_47 ] . V_39 , V_39 , 128 ) ;
V_37 [ V_47 ] . V_38 = V_33 + V_31 ;
}
else
{
V_31 ++ ;
V_42 = V_37 [ V_3 ] . V_51 ;
V_37 [ V_3 ] . V_38 = V_33 + V_31 ;
}
V_50:
F_11 ( V_49 ) ;
return ( V_42 ) ;
}
int F_5 ( void )
{
#ifdef F_22
static struct V_54 V_55 ;
if ( ! V_56 )
{
int V_44 ;
#ifdef F_23
signal ( F_23 , ( void ( * ) ( int ) ) V_57 ) ;
#endif
V_56 = 1 ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
if ( F_24 ( 0x0101 , & V_55 ) != 0 )
{
V_44 = F_25 () ;
F_12 ( V_58 , V_44 ) ;
F_3 ( V_59 , V_60 ) ;
return ( - 1 ) ;
}
}
#endif
return ( 1 ) ;
}
void V_57 ( void )
{
#ifdef F_22
if ( V_56 )
{
V_56 = 0 ;
F_26 () ;
F_27 () ;
}
#endif
}
int F_28 ( int V_61 , long type , unsigned long * V_62 )
{
int V_3 ;
V_3 = F_29 ( V_61 , type , V_62 ) ;
if ( V_3 < 0 )
F_12 ( V_63 , F_13 () ) ;
return ( V_3 ) ;
}
static int F_2 ( const char * V_1 , unsigned char V_2 [ 4 ] )
{
unsigned int V_64 [ 4 ] ;
int V_65 = 0 , V_66 , V_67 = 0 ;
V_64 [ 0 ] = V_64 [ 1 ] = V_64 [ 2 ] = V_64 [ 3 ] = 0 ;
for (; ; )
{
V_66 = * ( V_1 ++ ) ;
if ( ( V_66 >= '0' ) && ( V_66 <= '9' ) )
{
V_67 = 1 ;
V_64 [ V_65 ] = V_64 [ V_65 ] * 10 + V_66 - '0' ;
if ( V_64 [ V_65 ] > 255 ) return ( - 1 ) ;
}
else if ( V_66 == '.' )
{
if ( ! V_67 ) return ( - 1 ) ;
if ( V_65 == 3 ) break;
V_65 ++ ;
V_67 = 0 ;
}
else if ( ( V_65 == 3 ) && V_67 )
break;
else
return ( 0 ) ;
}
V_2 [ 0 ] = V_64 [ 0 ] ;
V_2 [ 1 ] = V_64 [ 1 ] ;
V_2 [ 2 ] = V_64 [ 2 ] ;
V_2 [ 3 ] = V_64 [ 3 ] ;
return ( 1 ) ;
}
int F_30 ( char * V_68 , int V_69 )
{
int V_42 = 0 ;
struct V_70 V_71 , V_72 ;
int V_15 = - 1 , V_73 ;
unsigned char V_2 [ 4 ] ;
unsigned short V_74 ;
char * V_1 , * V_75 ;
const char * V_76 , * V_29 ;
unsigned long V_77 ;
int V_78 ;
if ( ! F_5 () ) return ( V_79 ) ;
if ( ( V_1 = F_31 ( V_68 ) ) == NULL ) return ( V_79 ) ;
V_76 = V_29 = NULL ;
V_76 = V_1 ;
for ( V_75 = V_1 ; * V_75 ; V_75 ++ )
{
if ( * V_75 == ':' )
{
V_29 = & ( V_75 [ 1 ] ) ;
* V_75 = '\0' ;
}
else if ( * V_75 == '/' )
{
* V_75 = '\0' ;
break;
}
}
if ( V_29 == NULL )
{
V_29 = V_76 ;
V_76 = L_12 ;
}
if ( ! F_7 ( V_29 , & V_74 ) ) return ( V_79 ) ;
memset ( ( char * ) & V_71 , 0 , sizeof( V_71 ) ) ;
V_71 . V_80 = V_10 ;
V_71 . V_81 = F_32 ( V_74 ) ;
if ( strcmp ( V_76 , L_12 ) == 0 )
V_71 . V_82 . V_83 = V_84 ;
else
{
if ( ! F_1 ( V_76 , & ( V_2 [ 0 ] ) ) ) return ( V_79 ) ;
V_77 = ( unsigned long )
( ( unsigned long ) V_2 [ 0 ] << 24L ) |
( ( unsigned long ) V_2 [ 1 ] << 16L ) |
( ( unsigned long ) V_2 [ 2 ] << 8L ) |
( ( unsigned long ) V_2 [ 3 ] ) ;
V_71 . V_82 . V_83 = F_33 ( V_77 ) ;
}
V_85:
V_15 = F_34 ( V_10 , V_86 , V_87 ) ;
if ( V_15 == V_79 )
{
F_12 ( V_88 , F_13 () ) ;
F_4 ( 3 , L_13 , V_68 , L_11 ) ;
F_3 ( V_89 , V_90 ) ;
goto V_44;
}
#ifdef F_35
if ( V_69 == V_91 )
{
int V_3 = 1 ;
V_42 = F_36 ( V_15 , V_24 , F_35 , ( char * ) & V_3 , sizeof( V_3 ) ) ;
V_69 = V_92 ;
}
#endif
if ( F_37 ( V_15 , (struct V_93 * ) & V_71 , sizeof( V_71 ) ) == - 1 )
{
#ifdef F_35
V_78 = F_13 () ;
if ( ( V_69 == V_94 ) &&
( V_78 == V_95 ) )
{
memcpy ( ( char * ) & V_72 , ( char * ) & V_71 , sizeof( V_71 ) ) ;
if ( strcmp ( V_76 , L_12 ) == 0 )
V_72 . V_82 . V_83 = F_33 ( 0x7F000001 ) ;
V_73 = F_34 ( V_10 , V_86 , V_87 ) ;
if ( V_73 != V_79 )
{
int V_96 ;
V_96 = F_38 ( V_73 , (struct V_93 * ) & V_72 ,
sizeof( V_72 ) ) ;
F_39 ( V_73 ) ;
if ( V_96 == V_79 )
{
V_69 = V_91 ;
F_39 ( V_15 ) ;
goto V_85;
}
}
}
#endif
F_12 ( V_97 , V_78 ) ;
F_4 ( 3 , L_13 , V_68 , L_11 ) ;
F_3 ( V_89 , V_98 ) ;
goto V_44;
}
if ( F_40 ( V_15 , V_99 ) == - 1 )
{
F_12 ( V_97 , F_13 () ) ;
F_4 ( 3 , L_13 , V_68 , L_11 ) ;
F_3 ( V_89 , V_100 ) ;
goto V_44;
}
V_42 = 1 ;
V_44:
if ( V_1 != NULL ) Free ( V_1 ) ;
if ( ( V_42 == 0 ) && ( V_15 != V_79 ) )
{
F_39 ( V_15 ) ;
V_15 = V_79 ;
}
return ( V_15 ) ;
}
int F_41 ( int V_21 , char * * V_101 )
{
int V_42 = V_79 ;
static struct V_70 V_102 ;
unsigned long V_77 ;
unsigned short V_74 ;
int V_103 ;
char * V_29 ;
memset ( ( char * ) & V_102 , 0 , sizeof( V_102 ) ) ;
V_103 = sizeof( V_102 ) ;
V_42 = F_42 ( V_21 , (struct V_93 * ) & V_102 , ( void * ) & V_103 ) ;
if ( V_42 == V_79 )
{
F_12 ( V_104 , F_13 () ) ;
F_3 ( V_105 , V_106 ) ;
goto V_50;
}
if ( V_101 == NULL ) goto V_50;
V_77 = F_43 ( V_102 . V_82 . V_83 ) ;
V_74 = F_10 ( V_102 . V_81 ) ;
if ( * V_101 == NULL )
{
if ( ( V_29 = Malloc ( 24 ) ) == NULL )
{
F_3 ( V_105 , V_53 ) ;
goto V_50;
}
* V_101 = V_29 ;
}
sprintf ( * V_101 , L_14 ,
( unsigned char ) ( V_77 >> 24L ) & 0xff ,
( unsigned char ) ( V_77 >> 16L ) & 0xff ,
( unsigned char ) ( V_77 >> 8L ) & 0xff ,
( unsigned char ) ( V_77 ) & 0xff ,
V_74 ) ;
V_50:
return ( V_42 ) ;
}
int F_44 ( int V_15 , int V_107 )
{
int V_42 = 0 ;
#if F_45 ( V_108 ) && ( F_45 ( V_109 ) || F_45 ( V_110 ) )
int V_111 ;
#ifdef V_110
V_111 = V_110 ;
#else
#ifdef V_109
V_111 = V_109 ;
#endif
#endif
V_42 = F_36 ( V_15 , V_111 , V_108 , ( char * ) & V_107 , sizeof( V_107 ) ) ;
#endif
return ( V_42 == 0 ) ;
}
int F_46 ( int V_15 , int V_112 )
{
int V_42 = - 1 ;
unsigned long V_77 ;
V_77 = V_112 ;
#ifdef F_47
V_42 = F_28 ( V_15 , F_47 , & V_77 ) ;
#endif
return ( V_42 == 0 ) ;
}
