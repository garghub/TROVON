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
V_16 -> time = time ( NULL ) ;
V_16 -> V_21 = NULL ;
V_16 -> V_22 = NULL ;
V_16 -> V_23 = 0 ;
F_14 ( V_11 , V_16 , & V_16 -> V_15 ) ;
return ( V_16 ) ;
}
const unsigned char * F_15 ( const T_1 * V_12 , unsigned int * V_24 )
{
if( V_24 )
* V_24 = V_12 -> V_25 ;
return V_12 -> V_26 ;
}
static int F_16 ( const T_2 * V_1 , unsigned char * V_27 ,
unsigned int * V_28 )
{
unsigned int V_29 = 0 ;
do
if ( F_17 ( V_27 , * V_28 ) <= 0 )
return 0 ;
while( F_18 ( V_1 , V_27 , * V_28 ) &&
( ++ V_29 < V_30 ) );
if( V_29 < V_30 )
return 1 ;
return 0 ;
}
int F_19 ( T_2 * V_12 , int V_2 )
{
unsigned int V_31 ;
T_1 * V_16 = NULL ;
T_6 V_32 = F_16 ;
if ( ( V_16 = F_11 () ) == NULL ) return ( 0 ) ;
if ( V_12 -> V_33 -> V_34 == 0 )
V_16 -> V_20 = F_20 ( V_12 ) ;
else
V_16 -> V_20 = V_12 -> V_33 -> V_34 ;
if ( V_12 -> V_2 != NULL )
{
F_21 ( V_12 -> V_2 ) ;
V_12 -> V_2 = NULL ;
}
if ( V_2 )
{
if ( V_12 -> V_35 == V_36 )
{
V_16 -> V_37 = V_36 ;
V_16 -> V_25 = V_38 ;
}
else if ( V_12 -> V_35 == V_39 )
{
V_16 -> V_37 = V_39 ;
V_16 -> V_25 = V_40 ;
}
else if ( V_12 -> V_35 == V_41 )
{
V_16 -> V_37 = V_41 ;
V_16 -> V_25 = V_40 ;
}
else if ( V_12 -> V_35 == V_42 )
{
V_16 -> V_37 = V_42 ;
V_16 -> V_25 = V_40 ;
}
else
{
F_13 ( V_43 , V_44 ) ;
F_21 ( V_16 ) ;
return ( 0 ) ;
}
F_22 ( V_45 ) ;
if( V_12 -> V_46 )
V_32 = V_12 -> V_46 ;
else if( V_12 -> V_33 -> V_46 )
V_32 = V_12 -> V_33 -> V_46 ;
F_23 ( V_45 ) ;
V_31 = V_16 -> V_25 ;
if( ! V_32 ( V_12 , V_16 -> V_26 , & V_31 ) )
{
F_13 ( V_43 ,
V_47 ) ;
F_21 ( V_16 ) ;
return ( 0 ) ;
}
if( ! V_31 || ( V_31 > V_16 -> V_25 ) )
{
F_13 ( V_43 ,
V_48 ) ;
F_21 ( V_16 ) ;
return ( 0 ) ;
}
if( ( V_31 < V_16 -> V_25 ) && ( V_12 -> V_35 == V_36 ) )
memset ( V_16 -> V_26 + V_31 , 0 , V_16 -> V_25 - V_31 ) ;
else
V_16 -> V_25 = V_31 ;
if( F_18 ( V_12 , V_16 -> V_26 ,
V_16 -> V_25 ) )
{
F_13 ( V_43 ,
V_49 ) ;
F_21 ( V_16 ) ;
return ( 0 ) ;
}
}
else
{
V_16 -> V_25 = 0 ;
}
if ( V_12 -> V_50 > sizeof V_16 -> V_51 )
{
F_13 ( V_43 , V_52 ) ;
F_21 ( V_16 ) ;
return 0 ;
}
memcpy ( V_16 -> V_51 , V_12 -> V_51 , V_12 -> V_50 ) ;
V_16 -> V_50 = V_12 -> V_50 ;
V_12 -> V_2 = V_16 ;
V_16 -> V_37 = V_12 -> V_35 ;
V_16 -> V_19 = V_53 ;
return ( 1 ) ;
}
int F_24 ( T_2 * V_12 , unsigned char * V_26 , int V_24 )
{
T_1 * V_54 = NULL , V_55 ;
int V_56 = 0 ;
V_55 . V_37 = V_12 -> V_35 ;
V_55 . V_25 = V_24 ;
if ( V_24 > V_57 )
goto V_58;
memcpy ( V_55 . V_26 , V_26 , V_24 ) ;
if ( ! ( V_12 -> V_33 -> V_59 & V_60 ) )
{
F_22 ( V_45 ) ;
V_54 = ( T_1 * ) F_25 ( V_12 -> V_33 -> V_61 , & V_55 ) ;
if ( V_54 != NULL )
F_26 ( & V_54 -> V_5 , 1 , V_4 ) ;
F_23 ( V_45 ) ;
}
if ( V_54 == NULL )
{
int V_62 = 1 ;
V_12 -> V_33 -> V_63 . V_64 ++ ;
V_54 = NULL ;
if ( V_12 -> V_33 -> V_65 != NULL
&& ( V_54 = V_12 -> V_33 -> V_65 ( V_12 , V_26 , V_24 , & V_62 ) )
!= NULL )
{
V_12 -> V_33 -> V_63 . V_66 ++ ;
if ( V_62 )
F_26 ( & V_54 -> V_5 , 1 , V_4 ) ;
if( ! ( V_12 -> V_33 -> V_59 & V_67 ) )
F_27 ( V_12 -> V_33 , V_54 ) ;
}
if ( V_54 == NULL )
goto V_58;
}
if( ( V_12 -> V_68 & V_69 )
&& ( ! V_12 -> V_50 || V_54 -> V_50 != V_12 -> V_50
|| memcmp ( V_54 -> V_51 , V_12 -> V_51 , V_54 -> V_50 ) ) )
{
if ( V_12 -> V_50 == 0 )
{
F_13 ( V_70 , V_71 ) ;
V_56 = 1 ;
goto V_58;
}
else
{
#if 0
SSLerr(SSL_F_SSL_GET_PREV_SESSION,SSL_R_ATTEMPT_TO_REUSE_SESSION_IN_DIFFERENT_CONTEXT);
#endif
goto V_58;
}
}
if ( V_54 -> V_72 == NULL )
{
unsigned char V_73 [ 5 ] , * V_74 ;
unsigned long V_75 ;
V_74 = V_73 ;
V_75 = V_54 -> V_76 ;
F_28 ( V_75 , V_74 ) ;
if ( ( V_54 -> V_37 >> 8 ) == V_77 )
V_54 -> V_72 = F_29 ( V_12 , & ( V_73 [ 2 ] ) ) ;
else
V_54 -> V_72 = F_29 ( V_12 , & ( V_73 [ 1 ] ) ) ;
if ( V_54 -> V_72 == NULL )
goto V_58;
}
#if 0
CRYPTO_add(&ret->references,1,CRYPTO_LOCK_SSL_SESSION);
#endif
if ( ( long ) ( V_54 -> time + V_54 -> V_20 ) < ( long ) time ( NULL ) )
{
V_12 -> V_33 -> V_63 . V_78 ++ ;
F_30 ( V_12 -> V_33 , V_54 ) ;
goto V_58;
}
V_12 -> V_33 -> V_63 . V_79 ++ ;
if ( V_12 -> V_2 != NULL )
F_21 ( V_12 -> V_2 ) ;
V_12 -> V_2 = V_54 ;
V_12 -> V_19 = V_12 -> V_2 -> V_19 ;
return ( 1 ) ;
V_58:
if ( V_54 != NULL )
F_21 ( V_54 ) ;
if ( V_56 )
return - 1 ;
else
return 0 ;
}
int F_27 ( T_7 * V_33 , T_1 * V_80 )
{
int V_54 = 0 ;
T_1 * V_12 ;
F_26 ( & V_80 -> V_5 , 1 , V_4 ) ;
F_3 ( V_45 ) ;
V_12 = ( T_1 * ) F_31 ( V_33 -> V_61 , V_80 ) ;
if ( V_12 != NULL && V_12 != V_80 )
{
F_32 ( V_33 , V_12 ) ;
F_21 ( V_12 ) ;
V_12 = NULL ;
}
if ( V_12 == NULL )
F_33 ( V_33 , V_80 ) ;
if ( V_12 != NULL )
{
F_21 ( V_12 ) ;
V_54 = 0 ;
}
else
{
V_54 = 1 ;
if ( F_34 ( V_33 ) > 0 )
{
while ( F_35 ( V_33 ) >
F_34 ( V_33 ) )
{
if ( ! F_36 ( V_33 ,
V_33 -> V_81 , 0 ) )
break;
else
V_33 -> V_63 . V_82 ++ ;
}
}
}
F_4 ( V_45 ) ;
return ( V_54 ) ;
}
int F_30 ( T_7 * V_33 , T_1 * V_80 )
{
return F_36 ( V_33 , V_80 , 1 ) ;
}
static int F_36 ( T_7 * V_33 , T_1 * V_80 , int V_83 )
{
T_1 * V_84 ;
int V_54 = 0 ;
if ( ( V_80 != NULL ) && ( V_80 -> V_25 != 0 ) )
{
if( V_83 ) F_3 ( V_45 ) ;
if ( ( V_84 = ( T_1 * ) F_25 ( V_33 -> V_61 , V_80 ) ) == V_80 )
{
V_54 = 1 ;
V_84 = ( T_1 * ) F_37 ( V_33 -> V_61 , V_80 ) ;
F_32 ( V_33 , V_80 ) ;
}
if( V_83 ) F_4 ( V_45 ) ;
if ( V_54 )
{
V_84 -> V_85 = 1 ;
if ( V_33 -> V_86 != NULL )
V_33 -> V_86 ( V_33 , V_84 ) ;
F_21 ( V_84 ) ;
}
}
else
V_54 = 0 ;
return ( V_54 ) ;
}
void F_21 ( T_1 * V_16 )
{
int V_87 ;
if( V_16 == NULL )
return;
V_87 = F_26 ( & V_16 -> V_5 , - 1 , V_4 ) ;
#ifdef F_38
F_38 ( L_1 , V_16 ) ;
#endif
if ( V_87 > 0 ) return;
#ifdef F_39
if ( V_87 < 0 )
{
fprintf ( V_88 , L_2 ) ;
abort () ;
}
#endif
F_40 ( V_11 , V_16 , & V_16 -> V_15 ) ;
F_41 ( V_16 -> V_89 , sizeof V_16 -> V_89 ) ;
F_41 ( V_16 -> V_90 , sizeof V_16 -> V_90 ) ;
F_41 ( V_16 -> V_26 , sizeof V_16 -> V_26 ) ;
if ( V_16 -> V_91 != NULL ) F_42 ( V_16 -> V_91 ) ;
if ( V_16 -> V_92 != NULL ) F_43 ( V_16 -> V_92 ) ;
if ( V_16 -> V_93 != NULL ) F_44 ( V_16 -> V_93 ) ;
F_41 ( V_16 , sizeof( * V_16 ) ) ;
F_45 ( V_16 ) ;
}
int F_46 ( T_2 * V_12 , T_1 * V_2 )
{
int V_54 = 0 ;
T_8 * V_94 ;
if ( V_2 != NULL )
{
V_94 = V_12 -> V_33 -> V_95 -> V_96 ( V_2 -> V_37 ) ;
if ( V_94 == NULL )
V_94 = V_12 -> V_95 -> V_96 ( V_2 -> V_37 ) ;
if ( V_94 == NULL )
{
F_13 ( V_97 , V_98 ) ;
return ( 0 ) ;
}
if ( V_94 != V_12 -> V_95 )
{
if ( ! F_47 ( V_12 , V_94 ) )
return ( 0 ) ;
if ( V_12 -> V_33 -> V_34 == 0 )
V_2 -> V_20 = F_20 ( V_12 ) ;
else
V_2 -> V_20 = V_12 -> V_33 -> V_34 ;
}
#ifndef F_48
if ( V_12 -> V_99 && ! V_12 -> V_99 -> V_100 &&
V_2 -> V_101 > 0 )
{
V_12 -> V_99 -> V_100 = ( char * ) malloc ( V_2 -> V_101 + 1 ) ;
memcpy ( V_12 -> V_99 -> V_100 , V_2 -> V_102 ,
V_2 -> V_101 ) ;
V_12 -> V_99 -> V_100 [ V_2 -> V_101 ] = '\0' ;
}
#endif
F_26 ( & V_2 -> V_5 , 1 , V_4 ) ;
if ( V_12 -> V_2 != NULL )
F_21 ( V_12 -> V_2 ) ;
V_12 -> V_2 = V_2 ;
V_12 -> V_19 = V_12 -> V_2 -> V_19 ;
V_54 = 1 ;
}
else
{
if ( V_12 -> V_2 != NULL )
{
F_21 ( V_12 -> V_2 ) ;
V_12 -> V_2 = NULL ;
}
V_94 = V_12 -> V_33 -> V_95 ;
if ( V_94 != V_12 -> V_95 )
{
if ( ! F_47 ( V_12 , V_94 ) )
return ( 0 ) ;
}
V_54 = 1 ;
}
return ( V_54 ) ;
}
long F_49 ( T_1 * V_12 , long V_103 )
{
if ( V_12 == NULL ) return ( 0 ) ;
V_12 -> V_20 = V_103 ;
return ( 1 ) ;
}
long F_50 ( const T_1 * V_12 )
{
if ( V_12 == NULL ) return ( 0 ) ;
return ( V_12 -> V_20 ) ;
}
long F_51 ( const T_1 * V_12 )
{
if ( V_12 == NULL ) return ( 0 ) ;
return ( V_12 -> time ) ;
}
long F_52 ( T_1 * V_12 , long V_103 )
{
if ( V_12 == NULL ) return ( 0 ) ;
V_12 -> time = V_103 ;
return ( V_103 ) ;
}
long F_53 ( T_7 * V_12 , long V_103 )
{
long V_75 ;
if ( V_12 == NULL ) return ( 0 ) ;
V_75 = V_12 -> V_34 ;
V_12 -> V_34 = V_103 ;
return ( V_75 ) ;
}
long F_54 ( const T_7 * V_12 )
{
if ( V_12 == NULL ) return ( 0 ) ;
return ( V_12 -> V_34 ) ;
}
static void V_20 ( T_1 * V_12 , T_9 * V_74 )
{
if ( ( V_74 -> time == 0 ) || ( V_74 -> time > ( V_12 -> time + V_12 -> V_20 ) ) )
{
F_37 ( V_74 -> V_104 , V_12 ) ;
F_32 ( V_74 -> V_33 , V_12 ) ;
V_12 -> V_85 = 1 ;
if ( V_74 -> V_33 -> V_86 != NULL )
V_74 -> V_33 -> V_86 ( V_74 -> V_33 , V_12 ) ;
F_21 ( V_12 ) ;
}
}
static void F_32 ( T_7 * V_33 , T_1 * V_12 )
{
if ( ( V_12 -> V_22 == NULL ) || ( V_12 -> V_21 == NULL ) ) return;
if ( V_12 -> V_22 == ( T_1 * ) & ( V_33 -> V_81 ) )
{
if ( V_12 -> V_21 == ( T_1 * ) & ( V_33 -> V_105 ) )
{
V_33 -> V_105 = NULL ;
V_33 -> V_81 = NULL ;
}
else
{
V_33 -> V_81 = V_12 -> V_21 ;
V_12 -> V_21 -> V_22 = ( T_1 * ) & ( V_33 -> V_81 ) ;
}
}
else
{
if ( V_12 -> V_21 == ( T_1 * ) & ( V_33 -> V_105 ) )
{
V_33 -> V_105 = V_12 -> V_22 ;
V_12 -> V_22 -> V_21 = ( T_1 * ) & ( V_33 -> V_105 ) ;
}
else
{
V_12 -> V_22 -> V_21 = V_12 -> V_21 ;
V_12 -> V_21 -> V_22 = V_12 -> V_22 ;
}
}
V_12 -> V_21 = V_12 -> V_22 = NULL ;
}
static void F_33 ( T_7 * V_33 , T_1 * V_12 )
{
if ( ( V_12 -> V_22 != NULL ) && ( V_12 -> V_21 != NULL ) )
F_32 ( V_33 , V_12 ) ;
if ( V_33 -> V_105 == NULL )
{
V_33 -> V_105 = V_12 ;
V_33 -> V_81 = V_12 ;
V_12 -> V_21 = ( T_1 * ) & ( V_33 -> V_105 ) ;
V_12 -> V_22 = ( T_1 * ) & ( V_33 -> V_81 ) ;
}
else
{
V_12 -> V_22 = V_33 -> V_105 ;
V_12 -> V_22 -> V_21 = V_12 ;
V_12 -> V_21 = ( T_1 * ) & ( V_33 -> V_105 ) ;
V_33 -> V_105 = V_12 ;
}
}
