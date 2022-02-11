T_1 * F_1 ( T_2 * V_1 )
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
void * F_9 ( T_1 * V_12 , int V_13 )
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
V_16 -> time = time ( NULL ) ;
V_16 -> V_21 = NULL ;
V_16 -> V_22 = NULL ;
V_16 -> V_23 = 0 ;
F_14 ( V_11 , V_16 , & V_16 -> V_15 ) ;
return ( V_16 ) ;
}
static int F_15 ( const T_2 * V_1 , unsigned char * V_24 ,
unsigned int * V_25 )
{
unsigned int V_26 = 0 ;
do
F_16 ( V_24 , * V_25 ) ;
while( F_17 ( V_1 , V_24 , * V_25 ) &&
( ++ V_26 < V_27 ) );
if( V_26 < V_27 )
return 1 ;
return 0 ;
}
int F_18 ( T_2 * V_12 , int V_2 )
{
unsigned int V_28 ;
T_1 * V_16 = NULL ;
T_6 V_29 = F_15 ;
if ( ( V_16 = F_11 () ) == NULL ) return ( 0 ) ;
if ( V_12 -> V_30 -> V_31 == 0 )
V_16 -> V_20 = F_19 ( V_12 ) ;
else
V_16 -> V_20 = V_12 -> V_30 -> V_31 ;
if ( V_12 -> V_2 != NULL )
{
F_20 ( V_12 -> V_2 ) ;
V_12 -> V_2 = NULL ;
}
if ( V_2 )
{
if ( V_12 -> V_32 == V_33 )
{
V_16 -> V_34 = V_33 ;
V_16 -> V_35 = V_36 ;
}
else if ( V_12 -> V_32 == V_37 )
{
V_16 -> V_34 = V_37 ;
V_16 -> V_35 = V_38 ;
}
else if ( V_12 -> V_32 == V_39 )
{
V_16 -> V_34 = V_39 ;
V_16 -> V_35 = V_38 ;
}
else
{
F_13 ( V_40 , V_41 ) ;
F_20 ( V_16 ) ;
return ( 0 ) ;
}
F_3 ( V_42 ) ;
if( V_12 -> V_43 )
V_29 = V_12 -> V_43 ;
else if( V_12 -> V_30 -> V_43 )
V_29 = V_12 -> V_30 -> V_43 ;
F_4 ( V_42 ) ;
V_28 = V_16 -> V_35 ;
if( ! V_29 ( V_12 , V_16 -> V_44 , & V_28 ) )
{
F_13 ( V_40 ,
V_45 ) ;
F_20 ( V_16 ) ;
return ( 0 ) ;
}
if( ! V_28 || ( V_28 > V_16 -> V_35 ) )
{
F_13 ( V_40 ,
V_46 ) ;
F_20 ( V_16 ) ;
return ( 0 ) ;
}
if( ( V_28 < V_16 -> V_35 ) && ( V_12 -> V_32 == V_33 ) )
memset ( V_16 -> V_44 + V_28 , 0 , V_16 -> V_35 - V_28 ) ;
else
V_16 -> V_35 = V_28 ;
if( F_17 ( V_12 , V_16 -> V_44 ,
V_16 -> V_35 ) )
{
F_13 ( V_40 ,
V_47 ) ;
F_20 ( V_16 ) ;
return ( 0 ) ;
}
}
else
{
V_16 -> V_35 = 0 ;
}
if ( V_12 -> V_48 > sizeof V_16 -> V_49 )
{
F_13 ( V_40 , V_50 ) ;
F_20 ( V_16 ) ;
return 0 ;
}
memcpy ( V_16 -> V_49 , V_12 -> V_49 , V_12 -> V_48 ) ;
V_16 -> V_48 = V_12 -> V_48 ;
V_12 -> V_2 = V_16 ;
V_16 -> V_34 = V_12 -> V_32 ;
V_16 -> V_19 = V_51 ;
return ( 1 ) ;
}
int F_21 ( T_2 * V_12 , unsigned char * V_44 , int V_52 )
{
T_1 * V_53 = NULL , V_54 ;
int V_55 = 0 ;
V_54 . V_34 = V_12 -> V_32 ;
V_54 . V_35 = V_52 ;
if ( V_52 > V_56 )
goto V_57;
memcpy ( V_54 . V_44 , V_44 , V_52 ) ;
if ( ! ( V_12 -> V_30 -> V_58 & V_59 ) )
{
F_3 ( V_42 ) ;
V_53 = ( T_1 * ) F_22 ( V_12 -> V_30 -> V_60 , & V_54 ) ;
if ( V_53 != NULL )
F_23 ( & V_53 -> V_5 , 1 , V_4 ) ;
F_4 ( V_42 ) ;
}
if ( V_53 == NULL )
{
int V_61 = 1 ;
V_12 -> V_30 -> V_62 . V_63 ++ ;
V_53 = NULL ;
if ( V_12 -> V_30 -> V_64 != NULL
&& ( V_53 = V_12 -> V_30 -> V_64 ( V_12 , V_44 , V_52 , & V_61 ) )
!= NULL )
{
V_12 -> V_30 -> V_62 . V_65 ++ ;
if ( V_61 )
F_23 ( & V_53 -> V_5 , 1 , V_4 ) ;
if( ! ( V_12 -> V_30 -> V_58 & V_66 ) )
F_24 ( V_12 -> V_30 , V_53 ) ;
}
if ( V_53 == NULL )
goto V_57;
}
if( ( V_12 -> V_67 & V_68 )
&& ( ! V_12 -> V_48 || V_53 -> V_48 != V_12 -> V_48
|| memcmp ( V_53 -> V_49 , V_12 -> V_49 , V_53 -> V_48 ) ) )
{
if ( V_12 -> V_48 == 0 )
{
F_13 ( V_69 , V_70 ) ;
V_55 = 1 ;
goto V_57;
}
else
{
#if 0
SSLerr(SSL_F_SSL_GET_PREV_SESSION,SSL_R_ATTEMPT_TO_REUSE_SESSION_IN_DIFFERENT_CONTEXT);
#endif
goto V_57;
}
}
if ( V_53 -> V_71 == NULL )
{
unsigned char V_72 [ 5 ] , * V_73 ;
unsigned long V_74 ;
V_73 = V_72 ;
V_74 = V_53 -> V_75 ;
F_25 ( V_74 , V_73 ) ;
if ( ( V_53 -> V_34 >> 8 ) == V_76 )
V_53 -> V_71 = F_26 ( V_12 , & ( V_72 [ 2 ] ) ) ;
else
V_53 -> V_71 = F_26 ( V_12 , & ( V_72 [ 1 ] ) ) ;
if ( V_53 -> V_71 == NULL )
goto V_57;
}
#if 0
CRYPTO_add(&ret->references,1,CRYPTO_LOCK_SSL_SESSION);
#endif
if ( ( long ) ( V_53 -> time + V_53 -> V_20 ) < ( long ) time ( NULL ) )
{
V_12 -> V_30 -> V_62 . V_77 ++ ;
F_27 ( V_12 -> V_30 , V_53 ) ;
goto V_57;
}
V_12 -> V_30 -> V_62 . V_78 ++ ;
if ( V_12 -> V_2 != NULL )
F_20 ( V_12 -> V_2 ) ;
V_12 -> V_2 = V_53 ;
V_12 -> V_19 = V_12 -> V_2 -> V_19 ;
return ( 1 ) ;
V_57:
if ( V_53 != NULL )
F_20 ( V_53 ) ;
if ( V_55 )
return - 1 ;
else
return 0 ;
}
int F_24 ( T_7 * V_30 , T_1 * V_79 )
{
int V_53 = 0 ;
T_1 * V_12 ;
F_23 ( & V_79 -> V_5 , 1 , V_4 ) ;
F_28 ( V_42 ) ;
V_12 = ( T_1 * ) F_29 ( V_30 -> V_60 , V_79 ) ;
if ( V_12 != NULL && V_12 != V_79 )
{
F_30 ( V_30 , V_12 ) ;
F_20 ( V_12 ) ;
V_12 = NULL ;
}
if ( V_12 == NULL )
F_31 ( V_30 , V_79 ) ;
if ( V_12 != NULL )
{
F_20 ( V_12 ) ;
V_53 = 0 ;
}
else
{
V_53 = 1 ;
if ( F_32 ( V_30 ) > 0 )
{
while ( F_33 ( V_30 ) >
F_32 ( V_30 ) )
{
if ( ! F_34 ( V_30 ,
V_30 -> V_80 , 0 ) )
break;
else
V_30 -> V_62 . V_81 ++ ;
}
}
}
F_35 ( V_42 ) ;
return ( V_53 ) ;
}
int F_27 ( T_7 * V_30 , T_1 * V_79 )
{
return F_34 ( V_30 , V_79 , 1 ) ;
}
static int F_34 ( T_7 * V_30 , T_1 * V_79 , int V_82 )
{
T_1 * V_83 ;
int V_53 = 0 ;
if ( ( V_79 != NULL ) && ( V_79 -> V_35 != 0 ) )
{
if( V_82 ) F_28 ( V_42 ) ;
if ( ( V_83 = ( T_1 * ) F_22 ( V_30 -> V_60 , V_79 ) ) == V_79 )
{
V_53 = 1 ;
V_83 = ( T_1 * ) F_36 ( V_30 -> V_60 , V_79 ) ;
F_30 ( V_30 , V_79 ) ;
}
if( V_82 ) F_35 ( V_42 ) ;
if ( V_53 )
{
V_83 -> V_84 = 1 ;
if ( V_30 -> V_85 != NULL )
V_30 -> V_85 ( V_30 , V_83 ) ;
F_20 ( V_83 ) ;
}
}
else
V_53 = 0 ;
return ( V_53 ) ;
}
void F_20 ( T_1 * V_16 )
{
int V_86 ;
if( V_16 == NULL )
return;
V_86 = F_23 ( & V_16 -> V_5 , - 1 , V_4 ) ;
#ifdef F_37
F_37 ( L_1 , V_16 ) ;
#endif
if ( V_86 > 0 ) return;
#ifdef F_38
if ( V_86 < 0 )
{
fprintf ( V_87 , L_2 ) ;
abort () ;
}
#endif
F_39 ( V_11 , V_16 , & V_16 -> V_15 ) ;
F_40 ( V_16 -> V_88 , sizeof V_16 -> V_88 ) ;
F_40 ( V_16 -> V_89 , sizeof V_16 -> V_89 ) ;
F_40 ( V_16 -> V_44 , sizeof V_16 -> V_44 ) ;
if ( V_16 -> V_90 != NULL ) F_41 ( V_16 -> V_90 ) ;
if ( V_16 -> V_91 != NULL ) F_42 ( V_16 -> V_91 ) ;
if ( V_16 -> V_92 != NULL ) F_43 ( V_16 -> V_92 ) ;
F_40 ( V_16 , sizeof( * V_16 ) ) ;
F_44 ( V_16 ) ;
}
int F_45 ( T_2 * V_12 , T_1 * V_2 )
{
int V_53 = 0 ;
T_8 * V_93 ;
if ( V_2 != NULL )
{
V_93 = V_12 -> V_30 -> V_94 -> V_95 ( V_2 -> V_34 ) ;
if ( V_93 == NULL )
V_93 = V_12 -> V_94 -> V_95 ( V_2 -> V_34 ) ;
if ( V_93 == NULL )
{
F_13 ( V_96 , V_97 ) ;
return ( 0 ) ;
}
if ( V_93 != V_12 -> V_94 )
{
if ( ! F_46 ( V_12 , V_93 ) )
return ( 0 ) ;
if ( V_12 -> V_30 -> V_31 == 0 )
V_2 -> V_20 = F_19 ( V_12 ) ;
else
V_2 -> V_20 = V_12 -> V_30 -> V_31 ;
}
#ifndef F_47
if ( V_12 -> V_98 && ! V_12 -> V_98 -> V_99 &&
V_2 -> V_100 > 0 )
{
V_12 -> V_98 -> V_99 = ( char * ) malloc ( V_2 -> V_100 + 1 ) ;
memcpy ( V_12 -> V_98 -> V_99 , V_2 -> V_101 ,
V_2 -> V_100 ) ;
V_12 -> V_98 -> V_99 [ V_2 -> V_100 ] = '\0' ;
}
#endif
F_23 ( & V_2 -> V_5 , 1 , V_4 ) ;
if ( V_12 -> V_2 != NULL )
F_20 ( V_12 -> V_2 ) ;
V_12 -> V_2 = V_2 ;
V_12 -> V_19 = V_12 -> V_2 -> V_19 ;
V_53 = 1 ;
}
else
{
if ( V_12 -> V_2 != NULL )
{
F_20 ( V_12 -> V_2 ) ;
V_12 -> V_2 = NULL ;
}
V_93 = V_12 -> V_30 -> V_94 ;
if ( V_93 != V_12 -> V_94 )
{
if ( ! F_46 ( V_12 , V_93 ) )
return ( 0 ) ;
}
V_53 = 1 ;
}
return ( V_53 ) ;
}
long F_48 ( T_1 * V_12 , long V_102 )
{
if ( V_12 == NULL ) return ( 0 ) ;
V_12 -> V_20 = V_102 ;
return ( 1 ) ;
}
long F_49 ( T_1 * V_12 )
{
if ( V_12 == NULL ) return ( 0 ) ;
return ( V_12 -> V_20 ) ;
}
long F_50 ( T_1 * V_12 )
{
if ( V_12 == NULL ) return ( 0 ) ;
return ( V_12 -> time ) ;
}
long F_51 ( T_1 * V_12 , long V_102 )
{
if ( V_12 == NULL ) return ( 0 ) ;
V_12 -> time = V_102 ;
return ( V_102 ) ;
}
long F_52 ( T_7 * V_12 , long V_102 )
{
long V_74 ;
if ( V_12 == NULL ) return ( 0 ) ;
V_74 = V_12 -> V_31 ;
V_12 -> V_31 = V_102 ;
return ( V_74 ) ;
}
long F_53 ( T_7 * V_12 )
{
if ( V_12 == NULL ) return ( 0 ) ;
return ( V_12 -> V_31 ) ;
}
static void V_20 ( T_1 * V_12 , T_9 * V_73 )
{
if ( ( V_73 -> time == 0 ) || ( V_73 -> time > ( V_12 -> time + V_12 -> V_20 ) ) )
{
F_36 ( V_73 -> V_103 , V_12 ) ;
F_30 ( V_73 -> V_30 , V_12 ) ;
V_12 -> V_84 = 1 ;
if ( V_73 -> V_30 -> V_85 != NULL )
V_73 -> V_30 -> V_85 ( V_73 -> V_30 , V_12 ) ;
F_20 ( V_12 ) ;
}
}
static void F_30 ( T_7 * V_30 , T_1 * V_12 )
{
if ( ( V_12 -> V_22 == NULL ) || ( V_12 -> V_21 == NULL ) ) return;
if ( V_12 -> V_22 == ( T_1 * ) & ( V_30 -> V_80 ) )
{
if ( V_12 -> V_21 == ( T_1 * ) & ( V_30 -> V_104 ) )
{
V_30 -> V_104 = NULL ;
V_30 -> V_80 = NULL ;
}
else
{
V_30 -> V_80 = V_12 -> V_21 ;
V_12 -> V_21 -> V_22 = ( T_1 * ) & ( V_30 -> V_80 ) ;
}
}
else
{
if ( V_12 -> V_21 == ( T_1 * ) & ( V_30 -> V_104 ) )
{
V_30 -> V_104 = V_12 -> V_22 ;
V_12 -> V_22 -> V_21 = ( T_1 * ) & ( V_30 -> V_104 ) ;
}
else
{
V_12 -> V_22 -> V_21 = V_12 -> V_21 ;
V_12 -> V_21 -> V_22 = V_12 -> V_22 ;
}
}
V_12 -> V_21 = V_12 -> V_22 = NULL ;
}
static void F_31 ( T_7 * V_30 , T_1 * V_12 )
{
if ( ( V_12 -> V_22 != NULL ) && ( V_12 -> V_21 != NULL ) )
F_30 ( V_30 , V_12 ) ;
if ( V_30 -> V_104 == NULL )
{
V_30 -> V_104 = V_12 ;
V_30 -> V_80 = V_12 ;
V_12 -> V_21 = ( T_1 * ) & ( V_30 -> V_104 ) ;
V_12 -> V_22 = ( T_1 * ) & ( V_30 -> V_80 ) ;
}
else
{
V_12 -> V_22 = V_30 -> V_104 ;
V_12 -> V_22 -> V_21 = V_12 ;
V_12 -> V_21 = ( T_1 * ) & ( V_30 -> V_104 ) ;
V_30 -> V_104 = V_12 ;
}
}
