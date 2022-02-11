T_1 * F_1 ( const T_2 * V_1 )
{
return ( V_1 -> V_2 ) ;
}
T_1 * F_2 ( T_2 * V_1 )
{
T_1 * V_3 ;
F_3 ( V_4 ) ;
V_3 = V_1 -> V_2 ;
if( V_3 )
V_3 -> V_5 ++ ;
F_4 ( V_4 ) ;
return ( V_3 ) ;
}
int F_5 ( long V_6 , void * V_7 , T_3 * V_8 ,
T_4 * V_9 , T_5 * V_10 )
{
return F_6 ( V_11 , V_6 , V_7 ,
V_8 , V_9 , V_10 ) ;
}
int F_7 ( T_1 * V_12 , int V_13 , void * V_14 )
{
return ( F_8 ( & V_12 -> V_15 , V_13 , V_14 ) ) ;
}
void * F_9 ( const T_1 * V_12 , int V_13 )
{
return ( F_10 ( & V_12 -> V_15 , V_13 ) ) ;
}
T_1 * F_11 ( void )
{
T_1 * V_16 ;
V_16 = ( T_1 * ) F_12 ( sizeof( T_1 ) ) ;
if ( V_16 == NULL )
{
F_13 ( V_17 , V_18 ) ;
return ( 0 ) ;
}
memset ( V_16 , 0 , sizeof( T_1 ) ) ;
V_16 -> V_19 = 1 ;
V_16 -> V_5 = 1 ;
V_16 -> V_20 = 60 * 5 + 4 ;
V_16 -> time = ( unsigned long ) time ( NULL ) ;
V_16 -> V_21 = NULL ;
V_16 -> V_22 = NULL ;
V_16 -> V_23 = 0 ;
#ifndef F_14
V_16 -> V_24 = NULL ;
#ifndef F_15
V_16 -> V_25 = 0 ;
V_16 -> V_26 = NULL ;
V_16 -> V_27 = 0 ;
V_16 -> V_28 = NULL ;
#endif
#endif
F_16 ( V_11 , V_16 , & V_16 -> V_15 ) ;
#ifndef F_17
V_16 -> V_29 = NULL ;
V_16 -> V_30 = NULL ;
#endif
return ( V_16 ) ;
}
const unsigned char * F_18 ( const T_1 * V_12 , unsigned int * V_31 )
{
if( V_31 )
* V_31 = V_12 -> V_32 ;
return V_12 -> V_33 ;
}
static int F_19 ( const T_2 * V_1 , unsigned char * V_34 ,
unsigned int * V_35 )
{
unsigned int V_36 = 0 ;
do
if ( F_20 ( V_34 , * V_35 ) <= 0 )
return 0 ;
while( F_21 ( V_1 , V_34 , * V_35 ) &&
( ++ V_36 < V_37 ) );
if( V_36 < V_37 )
return 1 ;
return 0 ;
}
int F_22 ( T_2 * V_12 , int V_2 )
{
unsigned int V_38 ;
T_1 * V_16 = NULL ;
T_6 V_39 = F_19 ;
if ( ( V_16 = F_11 () ) == NULL ) return ( 0 ) ;
if ( V_12 -> V_40 -> V_41 == 0 )
V_16 -> V_20 = F_23 ( V_12 ) ;
else
V_16 -> V_20 = V_12 -> V_40 -> V_41 ;
if ( V_12 -> V_2 != NULL )
{
F_24 ( V_12 -> V_2 ) ;
V_12 -> V_2 = NULL ;
}
if ( V_2 )
{
if ( V_12 -> V_42 == V_43 )
{
V_16 -> V_44 = V_43 ;
V_16 -> V_32 = V_45 ;
}
else if ( V_12 -> V_42 == V_46 )
{
V_16 -> V_44 = V_46 ;
V_16 -> V_32 = V_47 ;
}
else if ( V_12 -> V_42 == V_48 )
{
V_16 -> V_44 = V_48 ;
V_16 -> V_32 = V_47 ;
}
else if ( V_12 -> V_42 == V_49 )
{
V_16 -> V_44 = V_49 ;
V_16 -> V_32 = V_47 ;
}
else if ( V_12 -> V_42 == V_50 )
{
V_16 -> V_44 = V_50 ;
V_16 -> V_32 = V_47 ;
}
else
{
F_13 ( V_51 , V_52 ) ;
F_24 ( V_16 ) ;
return ( 0 ) ;
}
#ifndef F_14
if ( V_12 -> V_53 )
{
V_16 -> V_32 = 0 ;
goto V_54;
}
#endif
F_25 ( V_55 ) ;
if( V_12 -> V_56 )
V_39 = V_12 -> V_56 ;
else if( V_12 -> V_40 -> V_56 )
V_39 = V_12 -> V_40 -> V_56 ;
F_26 ( V_55 ) ;
V_38 = V_16 -> V_32 ;
if( ! V_39 ( V_12 , V_16 -> V_33 , & V_38 ) )
{
F_13 ( V_51 ,
V_57 ) ;
F_24 ( V_16 ) ;
return ( 0 ) ;
}
if( ! V_38 || ( V_38 > V_16 -> V_32 ) )
{
F_13 ( V_51 ,
V_58 ) ;
F_24 ( V_16 ) ;
return ( 0 ) ;
}
if( ( V_38 < V_16 -> V_32 ) && ( V_12 -> V_42 == V_43 ) )
memset ( V_16 -> V_33 + V_38 , 0 , V_16 -> V_32 - V_38 ) ;
else
V_16 -> V_32 = V_38 ;
if( F_21 ( V_12 , V_16 -> V_33 ,
V_16 -> V_32 ) )
{
F_13 ( V_51 ,
V_59 ) ;
F_24 ( V_16 ) ;
return ( 0 ) ;
}
#ifndef F_14
V_54:
if ( V_12 -> V_24 ) {
V_16 -> V_24 = F_27 ( V_12 -> V_24 ) ;
if ( V_16 -> V_24 == NULL ) {
F_13 ( V_51 , V_60 ) ;
F_24 ( V_16 ) ;
return 0 ;
}
}
#ifndef F_15
if ( V_12 -> V_26 )
{
if ( V_16 -> V_26 != NULL ) F_28 ( V_16 -> V_26 ) ;
if ( ( V_16 -> V_26 = F_12 ( V_12 -> V_25 ) ) == NULL )
{
F_13 ( V_51 , V_18 ) ;
F_24 ( V_16 ) ;
return 0 ;
}
V_16 -> V_25 = V_12 -> V_25 ;
memcpy ( V_16 -> V_26 , V_12 -> V_26 , V_12 -> V_25 ) ;
}
if ( V_12 -> V_28 )
{
if ( V_16 -> V_28 != NULL ) F_28 ( V_16 -> V_28 ) ;
if ( ( V_16 -> V_28 = F_12 ( V_12 -> V_27 ) ) == NULL )
{
F_13 ( V_51 , V_18 ) ;
F_24 ( V_16 ) ;
return 0 ;
}
V_16 -> V_27 = V_12 -> V_27 ;
memcpy ( V_16 -> V_28 , V_12 -> V_28 , V_12 -> V_27 ) ;
}
#endif
#endif
}
else
{
V_16 -> V_32 = 0 ;
}
if ( V_12 -> V_61 > sizeof V_16 -> V_62 )
{
F_13 ( V_51 , V_60 ) ;
F_24 ( V_16 ) ;
return 0 ;
}
memcpy ( V_16 -> V_62 , V_12 -> V_62 , V_12 -> V_61 ) ;
V_16 -> V_61 = V_12 -> V_61 ;
V_12 -> V_2 = V_16 ;
V_16 -> V_44 = V_12 -> V_42 ;
V_16 -> V_19 = V_63 ;
return ( 1 ) ;
}
int F_29 ( T_2 * V_12 , unsigned char * V_33 , int V_31 ,
const unsigned char * V_64 )
{
T_1 * V_65 = NULL ;
int V_66 = 0 ;
#ifndef F_14
int V_67 ;
#endif
if ( V_31 > V_68 )
goto V_69;
#ifndef F_14
V_67 = F_30 ( V_12 , V_33 , V_31 , V_64 , & V_65 ) ;
if ( V_67 == - 1 )
{
V_66 = 1 ;
goto V_69;
}
else if ( V_67 == 0 || ( ! V_65 && ! V_31 ) )
goto V_69;
else if ( ! V_65 && ! ( V_12 -> V_40 -> V_70 & V_71 ) )
#else
if ( V_31 == 0 )
goto V_69;
if ( ! ( V_12 -> V_40 -> V_70 & V_71 ) )
#endif
{
T_1 V_72 ;
V_72 . V_44 = V_12 -> V_42 ;
V_72 . V_32 = V_31 ;
if ( V_31 == 0 )
return 0 ;
memcpy ( V_72 . V_33 , V_33 , V_31 ) ;
F_25 ( V_55 ) ;
V_65 = F_31 ( V_12 -> V_40 -> V_73 , & V_72 ) ;
if ( V_65 != NULL )
F_32 ( & V_65 -> V_5 , 1 , V_4 ) ;
F_26 ( V_55 ) ;
}
if ( V_65 == NULL )
{
int V_74 = 1 ;
V_12 -> V_40 -> V_75 . V_76 ++ ;
V_65 = NULL ;
if ( V_12 -> V_40 -> V_77 != NULL
&& ( V_65 = V_12 -> V_40 -> V_77 ( V_12 , V_33 , V_31 , & V_74 ) )
!= NULL )
{
V_12 -> V_40 -> V_75 . V_78 ++ ;
if ( V_74 )
F_32 ( & V_65 -> V_5 , 1 , V_4 ) ;
if( ! ( V_12 -> V_40 -> V_70 & V_79 ) )
F_33 ( V_12 -> V_40 , V_65 ) ;
}
if ( V_65 == NULL )
goto V_69;
}
if ( V_65 -> V_61 != V_12 -> V_61
|| memcmp ( V_65 -> V_62 , V_12 -> V_62 , V_65 -> V_61 ) )
{
#if 0
SSLerr(SSL_F_SSL_GET_PREV_SESSION,SSL_R_ATTEMPT_TO_REUSE_SESSION_IN_DIFFERENT_CONTEXT);
#endif
goto V_69;
}
if( ( V_12 -> V_80 & V_81 ) && V_12 -> V_61 == 0 )
{
F_13 ( V_82 , V_83 ) ;
V_66 = 1 ;
goto V_69;
}
if ( V_65 -> V_84 == NULL )
{
unsigned char V_85 [ 5 ] , * V_86 ;
unsigned long V_87 ;
V_86 = V_85 ;
V_87 = V_65 -> V_88 ;
F_34 ( V_87 , V_86 ) ;
if ( ( V_65 -> V_44 >> 8 ) >= V_89 )
V_65 -> V_84 = F_35 ( V_12 , & ( V_85 [ 2 ] ) ) ;
else
V_65 -> V_84 = F_35 ( V_12 , & ( V_85 [ 1 ] ) ) ;
if ( V_65 -> V_84 == NULL )
goto V_69;
}
#if 0
CRYPTO_add(&ret->references,1,CRYPTO_LOCK_SSL_SESSION);
#endif
if ( V_65 -> V_20 < ( long ) ( time ( NULL ) - V_65 -> time ) )
{
V_12 -> V_40 -> V_75 . V_90 ++ ;
F_36 ( V_12 -> V_40 , V_65 ) ;
goto V_69;
}
V_12 -> V_40 -> V_75 . V_91 ++ ;
if ( V_12 -> V_2 != NULL )
F_24 ( V_12 -> V_2 ) ;
V_12 -> V_2 = V_65 ;
V_12 -> V_19 = V_12 -> V_2 -> V_19 ;
return ( 1 ) ;
V_69:
if ( V_65 != NULL )
F_24 ( V_65 ) ;
if ( V_66 )
return - 1 ;
else
return 0 ;
}
int F_33 ( T_7 * V_92 , T_1 * V_93 )
{
int V_65 = 0 ;
T_1 * V_12 ;
F_32 ( & V_93 -> V_5 , 1 , V_4 ) ;
F_3 ( V_55 ) ;
V_12 = F_37 ( V_92 -> V_73 , V_93 ) ;
if ( V_12 != NULL && V_12 != V_93 )
{
F_38 ( V_92 , V_12 ) ;
F_24 ( V_12 ) ;
V_12 = NULL ;
}
if ( V_12 == NULL )
F_39 ( V_92 , V_93 ) ;
if ( V_12 != NULL )
{
F_24 ( V_12 ) ;
V_65 = 0 ;
}
else
{
V_65 = 1 ;
if ( F_40 ( V_92 ) > 0 )
{
while ( F_41 ( V_92 ) >
F_40 ( V_92 ) )
{
if ( ! F_42 ( V_92 ,
V_92 -> V_94 , 0 ) )
break;
else
V_92 -> V_75 . V_95 ++ ;
}
}
}
F_4 ( V_55 ) ;
return ( V_65 ) ;
}
int F_36 ( T_7 * V_92 , T_1 * V_93 )
{
return F_42 ( V_92 , V_93 , 1 ) ;
}
static int F_42 ( T_7 * V_92 , T_1 * V_93 , int V_96 )
{
T_1 * V_67 ;
int V_65 = 0 ;
if ( ( V_93 != NULL ) && ( V_93 -> V_32 != 0 ) )
{
if( V_96 ) F_3 ( V_55 ) ;
if ( ( V_67 = F_31 ( V_92 -> V_73 , V_93 ) ) == V_93 )
{
V_65 = 1 ;
V_67 = F_43 ( V_92 -> V_73 , V_93 ) ;
F_38 ( V_92 , V_93 ) ;
}
if( V_96 ) F_4 ( V_55 ) ;
if ( V_65 )
{
V_67 -> V_97 = 1 ;
if ( V_92 -> V_98 != NULL )
V_92 -> V_98 ( V_92 , V_67 ) ;
F_24 ( V_67 ) ;
}
}
else
V_65 = 0 ;
return ( V_65 ) ;
}
void F_24 ( T_1 * V_16 )
{
int V_99 ;
if( V_16 == NULL )
return;
V_99 = F_32 ( & V_16 -> V_5 , - 1 , V_4 ) ;
#ifdef F_44
F_44 ( L_1 , V_16 ) ;
#endif
if ( V_99 > 0 ) return;
#ifdef F_45
if ( V_99 < 0 )
{
fprintf ( V_100 , L_2 ) ;
abort () ;
}
#endif
F_46 ( V_11 , V_16 , & V_16 -> V_15 ) ;
F_47 ( V_16 -> V_101 , sizeof V_16 -> V_101 ) ;
F_47 ( V_16 -> V_102 , sizeof V_16 -> V_102 ) ;
F_47 ( V_16 -> V_33 , sizeof V_16 -> V_33 ) ;
if ( V_16 -> V_103 != NULL ) F_48 ( V_16 -> V_103 ) ;
if ( V_16 -> V_104 != NULL ) F_49 ( V_16 -> V_104 ) ;
if ( V_16 -> V_105 != NULL ) F_50 ( V_16 -> V_105 ) ;
#ifndef F_14
if ( V_16 -> V_24 != NULL ) F_28 ( V_16 -> V_24 ) ;
if ( V_16 -> V_106 != NULL ) F_28 ( V_16 -> V_106 ) ;
#ifndef F_15
V_16 -> V_25 = 0 ;
if ( V_16 -> V_26 != NULL ) F_28 ( V_16 -> V_26 ) ;
V_16 -> V_27 = 0 ;
if ( V_16 -> V_28 != NULL ) F_28 ( V_16 -> V_28 ) ;
#endif
#endif
#ifndef F_17
if ( V_16 -> V_29 != NULL )
F_28 ( V_16 -> V_29 ) ;
if ( V_16 -> V_30 != NULL )
F_28 ( V_16 -> V_30 ) ;
#endif
F_47 ( V_16 , sizeof( * V_16 ) ) ;
F_28 ( V_16 ) ;
}
int F_51 ( T_2 * V_12 , T_1 * V_2 )
{
int V_65 = 0 ;
const T_8 * V_107 ;
if ( V_2 != NULL )
{
V_107 = V_12 -> V_92 -> V_108 -> V_109 ( V_2 -> V_44 ) ;
if ( V_107 == NULL )
V_107 = V_12 -> V_108 -> V_109 ( V_2 -> V_44 ) ;
if ( V_107 == NULL )
{
F_13 ( V_110 , V_111 ) ;
return ( 0 ) ;
}
if ( V_107 != V_12 -> V_108 )
{
if ( ! F_52 ( V_12 , V_107 ) )
return ( 0 ) ;
if ( V_12 -> V_92 -> V_41 == 0 )
V_2 -> V_20 = F_23 ( V_12 ) ;
else
V_2 -> V_20 = V_12 -> V_92 -> V_41 ;
}
#ifndef F_53
if ( V_12 -> V_112 && ! V_12 -> V_112 -> V_113 &&
V_2 -> V_114 > 0 )
{
V_12 -> V_112 -> V_113 = ( char * ) F_12 ( V_2 -> V_114 + 1 ) ;
memcpy ( V_12 -> V_112 -> V_113 , V_2 -> V_115 ,
V_2 -> V_114 ) ;
V_12 -> V_112 -> V_113 [ V_2 -> V_114 ] = '\0' ;
}
#endif
F_32 ( & V_2 -> V_5 , 1 , V_4 ) ;
if ( V_12 -> V_2 != NULL )
F_24 ( V_12 -> V_2 ) ;
V_12 -> V_2 = V_2 ;
V_12 -> V_19 = V_12 -> V_2 -> V_19 ;
V_65 = 1 ;
}
else
{
if ( V_12 -> V_2 != NULL )
{
F_24 ( V_12 -> V_2 ) ;
V_12 -> V_2 = NULL ;
}
V_107 = V_12 -> V_92 -> V_108 ;
if ( V_107 != V_12 -> V_108 )
{
if ( ! F_52 ( V_12 , V_107 ) )
return ( 0 ) ;
}
V_65 = 1 ;
}
return ( V_65 ) ;
}
long F_54 ( T_1 * V_12 , long V_116 )
{
if ( V_12 == NULL ) return ( 0 ) ;
V_12 -> V_20 = V_116 ;
return ( 1 ) ;
}
long F_55 ( const T_1 * V_12 )
{
if ( V_12 == NULL ) return ( 0 ) ;
return ( V_12 -> V_20 ) ;
}
long F_56 ( const T_1 * V_12 )
{
if ( V_12 == NULL ) return ( 0 ) ;
return ( V_12 -> time ) ;
}
long F_57 ( T_1 * V_12 , long V_116 )
{
if ( V_12 == NULL ) return ( 0 ) ;
V_12 -> time = V_116 ;
return ( V_116 ) ;
}
long F_58 ( T_7 * V_12 , long V_116 )
{
long V_87 ;
if ( V_12 == NULL ) return ( 0 ) ;
V_87 = V_12 -> V_41 ;
V_12 -> V_41 = V_116 ;
return ( V_87 ) ;
}
long F_59 ( const T_7 * V_12 )
{
if ( V_12 == NULL ) return ( 0 ) ;
return ( V_12 -> V_41 ) ;
}
int F_60 ( T_2 * V_12 , T_9 V_39 ,
void * V_14 )
{
if ( V_12 == NULL ) return ( 0 ) ;
V_12 -> V_117 = V_39 ;
V_12 -> V_118 = V_14 ;
return ( 1 ) ;
}
int F_61 ( T_2 * V_12 , void * V_119 , int V_120 )
{
if ( V_12 -> V_42 >= V_48 )
{
if ( V_12 -> V_121 )
{
F_28 ( V_12 -> V_121 ) ;
V_12 -> V_121 = NULL ;
}
V_12 -> V_121 = F_12 ( sizeof( V_122 ) + V_120 ) ;
if ( ! V_12 -> V_121 )
{
F_13 ( V_123 , V_18 ) ;
return 0 ;
}
if ( V_119 )
{
V_12 -> V_121 -> V_124 = V_120 ;
V_12 -> V_121 -> V_72 = V_12 -> V_121 + 1 ;
memcpy ( V_12 -> V_121 -> V_72 , V_119 , V_120 ) ;
}
else
{
V_12 -> V_121 -> V_124 = 0 ;
V_12 -> V_121 -> V_72 = NULL ;
}
return 1 ;
}
return 0 ;
}
static void F_62 ( T_1 * V_12 , T_10 * V_86 )
{
if ( ( V_86 -> time == 0 ) || ( V_86 -> time > ( V_12 -> time + V_12 -> V_20 ) ) )
{
( void ) F_43 ( V_86 -> V_125 , V_12 ) ;
F_38 ( V_86 -> V_92 , V_12 ) ;
V_12 -> V_97 = 1 ;
if ( V_86 -> V_92 -> V_98 != NULL )
V_86 -> V_92 -> V_98 ( V_86 -> V_92 , V_12 ) ;
F_24 ( V_12 ) ;
}
}
static void F_38 ( T_7 * V_92 , T_1 * V_12 )
{
if ( ( V_12 -> V_22 == NULL ) || ( V_12 -> V_21 == NULL ) ) return;
if ( V_12 -> V_22 == ( T_1 * ) & ( V_92 -> V_94 ) )
{
if ( V_12 -> V_21 == ( T_1 * ) & ( V_92 -> V_126 ) )
{
V_92 -> V_126 = NULL ;
V_92 -> V_94 = NULL ;
}
else
{
V_92 -> V_94 = V_12 -> V_21 ;
V_12 -> V_21 -> V_22 = ( T_1 * ) & ( V_92 -> V_94 ) ;
}
}
else
{
if ( V_12 -> V_21 == ( T_1 * ) & ( V_92 -> V_126 ) )
{
V_92 -> V_126 = V_12 -> V_22 ;
V_12 -> V_22 -> V_21 = ( T_1 * ) & ( V_92 -> V_126 ) ;
}
else
{
V_12 -> V_22 -> V_21 = V_12 -> V_21 ;
V_12 -> V_21 -> V_22 = V_12 -> V_22 ;
}
}
V_12 -> V_21 = V_12 -> V_22 = NULL ;
}
static void F_39 ( T_7 * V_92 , T_1 * V_12 )
{
if ( ( V_12 -> V_22 != NULL ) && ( V_12 -> V_21 != NULL ) )
F_38 ( V_92 , V_12 ) ;
if ( V_92 -> V_126 == NULL )
{
V_92 -> V_126 = V_12 ;
V_92 -> V_94 = V_12 ;
V_12 -> V_21 = ( T_1 * ) & ( V_92 -> V_126 ) ;
V_12 -> V_22 = ( T_1 * ) & ( V_92 -> V_94 ) ;
}
else
{
V_12 -> V_22 = V_92 -> V_126 ;
V_12 -> V_22 -> V_21 = V_12 ;
V_12 -> V_21 = ( T_1 * ) & ( V_92 -> V_126 ) ;
V_92 -> V_126 = V_12 ;
}
}
void F_63 ( T_7 * V_92 ,
int (* V_39)( struct V_127 * V_1 , T_1 * V_3 ) )
{
V_92 -> V_128 = V_39 ;
}
void F_64 ( T_7 * V_92 ,
void (* V_39)( T_7 * V_92 , T_1 * V_3 ) )
{
V_92 -> V_98 = V_39 ;
}
void F_65 ( T_7 * V_92 ,
T_1 * (* V_39)( struct V_127 * V_1 ,
unsigned char * V_72 , int V_31 , int * V_74 ) )
{
V_92 -> V_77 = V_39 ;
}
void F_66 ( T_7 * V_92 ,
void (* V_39)( const T_2 * V_1 , int type , int V_129 ) )
{
V_92 -> V_130 = V_39 ;
}
void F_67 ( T_7 * V_92 ,
int (* V_39)( T_2 * V_1 , T_11 * * V_131 , T_12 * * V_132 ) )
{
V_92 -> V_133 = V_39 ;
}
int F_68 ( T_7 * V_92 , T_13 * V_134 )
{
if ( ! F_69 ( V_134 ) )
{
F_13 ( V_135 , V_136 ) ;
return 0 ;
}
if( ! F_70 ( V_134 ) )
{
F_13 ( V_135 , V_137 ) ;
F_71 ( V_134 ) ;
return 0 ;
}
V_92 -> V_138 = V_134 ;
return 1 ;
}
void F_72 ( T_7 * V_92 ,
int (* V_39)( T_2 * V_1 , unsigned char * V_139 , unsigned int * V_140 ) )
{
V_92 -> V_141 = V_39 ;
}
void F_73 ( T_7 * V_92 ,
int (* V_39)( T_2 * V_1 , unsigned char * V_139 , unsigned int V_140 ) )
{
V_92 -> V_142 = V_39 ;
}
