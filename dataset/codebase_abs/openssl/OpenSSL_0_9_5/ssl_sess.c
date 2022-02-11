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
V_11 ++ ;
return ( F_6 ( V_11 - 1 ,
& V_12 ,
V_6 , V_7 , V_8 , V_9 , V_10 ) ) ;
}
int F_7 ( T_1 * V_13 , int V_14 , void * V_15 )
{
return ( F_8 ( & V_13 -> V_16 , V_14 , V_15 ) ) ;
}
void * F_9 ( T_1 * V_13 , int V_14 )
{
return ( F_10 ( & V_13 -> V_16 , V_14 ) ) ;
}
T_1 * F_11 ( void )
{
T_1 * V_17 ;
V_17 = ( T_1 * ) Malloc ( sizeof( T_1 ) ) ;
if ( V_17 == NULL )
{
F_12 ( V_18 , V_19 ) ;
return ( 0 ) ;
}
memset ( V_17 , 0 , sizeof( T_1 ) ) ;
V_17 -> V_20 = 1 ;
V_17 -> V_5 = 1 ;
V_17 -> V_21 = 60 * 5 + 4 ;
V_17 -> time = time ( NULL ) ;
V_17 -> V_22 = NULL ;
V_17 -> V_23 = NULL ;
V_17 -> V_24 = 0 ;
F_13 ( V_12 , V_17 , & V_17 -> V_16 ) ;
return ( V_17 ) ;
}
int F_14 ( T_2 * V_13 , int V_2 )
{
T_1 * V_17 = NULL ;
if ( ( V_17 = F_11 () ) == NULL ) return ( 0 ) ;
if ( V_13 -> V_25 -> V_26 == 0 )
V_17 -> V_21 = F_15 ( V_13 ) ;
else
V_17 -> V_21 = V_13 -> V_25 -> V_26 ;
if ( V_13 -> V_2 != NULL )
{
F_16 ( V_13 -> V_2 ) ;
V_13 -> V_2 = NULL ;
}
if ( V_2 )
{
if ( V_13 -> V_27 == V_28 )
{
V_17 -> V_29 = V_28 ;
V_17 -> V_30 = V_31 ;
}
else if ( V_13 -> V_27 == V_32 )
{
V_17 -> V_29 = V_32 ;
V_17 -> V_30 = V_33 ;
}
else if ( V_13 -> V_27 == V_34 )
{
V_17 -> V_29 = V_34 ;
V_17 -> V_30 = V_33 ;
}
else
{
F_12 ( V_35 , V_36 ) ;
F_16 ( V_17 ) ;
return ( 0 ) ;
}
for (; ; )
{
T_1 * V_37 ;
F_17 ( V_17 -> V_38 , V_17 -> V_30 ) ;
F_3 ( V_39 ) ;
V_37 = ( T_1 * ) F_18 ( V_13 -> V_25 -> V_40 , V_17 ) ;
F_4 ( V_39 ) ;
if ( V_37 == NULL ) break;
}
}
else
{
V_17 -> V_30 = 0 ;
}
memcpy ( V_17 -> V_41 , V_13 -> V_41 , V_13 -> V_42 ) ;
V_17 -> V_42 = V_13 -> V_42 ;
V_13 -> V_2 = V_17 ;
V_17 -> V_29 = V_13 -> V_27 ;
V_17 -> V_20 = V_43 ;
return ( 1 ) ;
}
int F_19 ( T_2 * V_13 , unsigned char * V_38 , int V_44 )
{
T_1 * V_45 = NULL , V_46 ;
int V_47 = 0 ;
V_46 . V_29 = V_13 -> V_27 ;
V_46 . V_30 = V_44 ;
if ( V_44 > V_48 )
goto V_49;
memcpy ( V_46 . V_38 , V_38 , V_44 ) ;
if ( ! ( V_13 -> V_25 -> V_50 & V_51 ) )
{
F_3 ( V_39 ) ;
V_45 = ( T_1 * ) F_18 ( V_13 -> V_25 -> V_40 , & V_46 ) ;
if ( V_45 != NULL )
F_20 ( & V_45 -> V_5 , 1 , V_4 ) ;
F_4 ( V_39 ) ;
}
if ( V_45 == NULL )
{
int V_52 = 1 ;
V_13 -> V_25 -> V_53 . V_54 ++ ;
V_45 = NULL ;
if ( V_13 -> V_25 -> V_55 != NULL
&& ( V_45 = V_13 -> V_25 -> V_55 ( V_13 , V_38 , V_44 , & V_52 ) )
!= NULL )
{
V_13 -> V_25 -> V_53 . V_56 ++ ;
if ( V_52 )
F_20 ( & V_45 -> V_5 , 1 , V_4 ) ;
F_21 ( V_13 -> V_25 , V_45 ) ;
}
if ( V_45 == NULL )
goto V_49;
}
if( ( V_13 -> V_57 & V_58 )
&& ( ! V_13 -> V_42 || V_45 -> V_42 != V_13 -> V_42
|| memcmp ( V_45 -> V_41 , V_13 -> V_41 , V_45 -> V_42 ) ) )
{
if ( V_13 -> V_42 == 0 )
{
F_12 ( V_59 , V_60 ) ;
V_47 = 1 ;
goto V_49;
}
else
{
#if 0
SSLerr(SSL_F_SSL_GET_PREV_SESSION,SSL_R_ATTEMPT_TO_REUSE_SESSION_IN_DIFFERENT_CONTEXT);
#endif
goto V_49;
}
}
if ( V_45 -> V_61 == NULL )
{
unsigned char V_62 [ 5 ] , * V_63 ;
unsigned long V_64 ;
V_63 = V_62 ;
V_64 = V_45 -> V_65 ;
F_22 ( V_64 , V_63 ) ;
if ( ( V_45 -> V_29 >> 8 ) == V_66 )
V_45 -> V_61 = F_23 ( V_13 , & ( V_62 [ 2 ] ) ) ;
else
V_45 -> V_61 = F_23 ( V_13 , & ( V_62 [ 1 ] ) ) ;
if ( V_45 -> V_61 == NULL )
goto V_49;
}
#if 0
CRYPTO_add(&ret->references,1,CRYPTO_LOCK_SSL_SESSION);
#endif
if ( ( long ) ( V_45 -> time + V_45 -> V_21 ) < ( long ) time ( NULL ) )
{
V_13 -> V_25 -> V_53 . V_67 ++ ;
F_24 ( V_13 -> V_25 , V_45 ) ;
goto V_49;
}
V_13 -> V_25 -> V_53 . V_68 ++ ;
if ( V_13 -> V_2 != NULL )
F_16 ( V_13 -> V_2 ) ;
V_13 -> V_2 = V_45 ;
V_13 -> V_20 = V_13 -> V_2 -> V_20 ;
return ( 1 ) ;
V_49:
if ( V_45 != NULL )
F_16 ( V_45 ) ;
if ( V_47 )
return - 1 ;
else
return 0 ;
}
int F_21 ( T_6 * V_25 , T_1 * V_69 )
{
int V_45 = 0 ;
T_1 * V_13 ;
F_20 ( & V_69 -> V_5 , 1 , V_4 ) ;
F_25 ( V_39 ) ;
V_13 = ( T_1 * ) F_26 ( V_25 -> V_40 , V_69 ) ;
if ( V_13 != NULL && V_13 != V_69 )
{
F_27 ( V_25 , V_13 ) ;
F_16 ( V_13 ) ;
V_13 = NULL ;
}
if ( V_13 == NULL )
F_28 ( V_25 , V_69 ) ;
if ( V_13 != NULL )
{
F_16 ( V_13 ) ;
V_45 = 0 ;
}
else
{
V_45 = 1 ;
if ( F_29 ( V_25 ) > 0 )
{
while ( F_30 ( V_25 ) >
F_29 ( V_25 ) )
{
if ( ! F_31 ( V_25 ,
V_25 -> V_70 , 0 ) )
break;
else
V_25 -> V_53 . V_71 ++ ;
}
}
}
F_32 ( V_39 ) ;
return ( V_45 ) ;
}
int F_24 ( T_6 * V_25 , T_1 * V_69 )
{
return F_31 ( V_25 , V_69 , 1 ) ;
}
static int F_31 ( T_6 * V_25 , T_1 * V_69 , int V_72 )
{
T_1 * V_37 ;
int V_45 = 0 ;
if ( ( V_69 != NULL ) && ( V_69 -> V_30 != 0 ) )
{
if( V_72 ) F_25 ( V_39 ) ;
V_37 = ( T_1 * ) F_33 ( V_25 -> V_40 , V_69 ) ;
if ( V_37 != NULL )
{
V_45 = 1 ;
F_27 ( V_25 , V_69 ) ;
}
if( V_72 ) F_32 ( V_39 ) ;
if ( V_45 )
{
V_37 -> V_73 = 1 ;
if ( V_25 -> V_74 != NULL )
V_25 -> V_74 ( V_25 , V_37 ) ;
F_16 ( V_37 ) ;
}
}
else
V_45 = 0 ;
return ( V_45 ) ;
}
void F_16 ( T_1 * V_17 )
{
int V_75 ;
if( V_17 == NULL )
return;
V_75 = F_20 ( & V_17 -> V_5 , - 1 , V_4 ) ;
#ifdef F_34
F_34 ( L_1 , V_17 ) ;
#endif
if ( V_75 > 0 ) return;
#ifdef F_35
if ( V_75 < 0 )
{
fprintf ( V_76 , L_2 ) ;
abort () ;
}
#endif
F_36 ( V_12 , V_17 , & V_17 -> V_16 ) ;
memset ( V_17 -> V_77 , 0 , V_78 ) ;
memset ( V_17 -> V_79 , 0 , V_80 ) ;
memset ( V_17 -> V_38 , 0 , V_48 ) ;
if ( V_17 -> V_81 != NULL ) F_37 ( V_17 -> V_81 ) ;
if ( V_17 -> V_82 != NULL ) F_38 ( V_17 -> V_82 ) ;
if ( V_17 -> V_83 != NULL ) F_39 ( V_17 -> V_83 ) ;
memset ( V_17 , 0 , sizeof( * V_17 ) ) ;
Free ( V_17 ) ;
}
int F_40 ( T_2 * V_13 , T_1 * V_2 )
{
int V_45 = 0 ;
T_7 * V_84 ;
if ( V_2 != NULL )
{
V_84 = V_13 -> V_25 -> V_85 -> V_86 ( V_2 -> V_29 ) ;
if ( V_84 == NULL )
V_84 = V_13 -> V_85 -> V_86 ( V_2 -> V_29 ) ;
if ( V_84 == NULL )
{
F_12 ( V_87 , V_88 ) ;
return ( 0 ) ;
}
if ( V_84 != V_13 -> V_85 )
{
if ( ! F_41 ( V_13 , V_84 ) )
return ( 0 ) ;
if ( V_13 -> V_25 -> V_26 == 0 )
V_2 -> V_21 = F_15 ( V_13 ) ;
else
V_2 -> V_21 = V_13 -> V_25 -> V_26 ;
}
F_20 ( & V_2 -> V_5 , 1 , V_4 ) ;
if ( V_13 -> V_2 != NULL )
F_16 ( V_13 -> V_2 ) ;
V_13 -> V_2 = V_2 ;
V_45 = 1 ;
}
else
{
if ( V_13 -> V_2 != NULL )
{
F_16 ( V_13 -> V_2 ) ;
V_13 -> V_2 = NULL ;
}
V_84 = V_13 -> V_25 -> V_85 ;
if ( V_84 != V_13 -> V_85 )
{
if ( ! F_41 ( V_13 , V_84 ) )
return ( 0 ) ;
}
V_45 = 1 ;
}
return ( V_45 ) ;
}
long F_42 ( T_1 * V_13 , long V_89 )
{
if ( V_13 == NULL ) return ( 0 ) ;
V_13 -> V_21 = V_89 ;
return ( 1 ) ;
}
long F_43 ( T_1 * V_13 )
{
if ( V_13 == NULL ) return ( 0 ) ;
return ( V_13 -> V_21 ) ;
}
long F_44 ( T_1 * V_13 )
{
if ( V_13 == NULL ) return ( 0 ) ;
return ( V_13 -> time ) ;
}
long F_45 ( T_1 * V_13 , long V_89 )
{
if ( V_13 == NULL ) return ( 0 ) ;
V_13 -> time = V_89 ;
return ( V_89 ) ;
}
long F_46 ( T_6 * V_13 , long V_89 )
{
long V_64 ;
if ( V_13 == NULL ) return ( 0 ) ;
V_64 = V_13 -> V_26 ;
V_13 -> V_26 = V_89 ;
return ( V_64 ) ;
}
long F_47 ( T_6 * V_13 )
{
if ( V_13 == NULL ) return ( 0 ) ;
return ( V_13 -> V_26 ) ;
}
static void V_21 ( T_1 * V_13 , T_8 * V_63 )
{
if ( ( V_63 -> time == 0 ) || ( V_63 -> time > ( V_13 -> time + V_13 -> V_21 ) ) )
{
F_33 ( V_63 -> V_90 , V_13 ) ;
F_27 ( V_63 -> V_25 , V_13 ) ;
V_13 -> V_73 = 1 ;
if ( V_63 -> V_25 -> V_74 != NULL )
V_63 -> V_25 -> V_74 ( V_63 -> V_25 , V_13 ) ;
F_16 ( V_13 ) ;
}
}
void F_48 ( T_6 * V_13 , long V_89 )
{
unsigned long V_75 ;
T_8 V_91 ;
V_91 . V_25 = V_13 ;
V_91 . V_90 = V_13 -> V_40 ;
if ( V_91 . V_90 == NULL ) return;
V_91 . time = V_89 ;
F_25 ( V_39 ) ;
V_75 = V_91 . V_90 -> V_92 ;
V_91 . V_90 -> V_92 = 0 ;
F_49 ( V_91 . V_90 , ( void ( * ) () ) V_21 , & V_91 ) ;
V_91 . V_90 -> V_92 = V_75 ;
F_32 ( V_39 ) ;
}
int F_50 ( T_2 * V_13 )
{
if ( ( V_13 -> V_2 != NULL ) &&
! ( V_13 -> V_93 & V_94 ) &&
! ( F_51 ( V_13 ) || F_52 ( V_13 ) ) )
{
F_24 ( V_13 -> V_25 , V_13 -> V_2 ) ;
return ( 1 ) ;
}
else
return ( 0 ) ;
}
static void F_27 ( T_6 * V_25 , T_1 * V_13 )
{
if ( ( V_13 -> V_23 == NULL ) || ( V_13 -> V_22 == NULL ) ) return;
if ( V_13 -> V_23 == ( T_1 * ) & ( V_25 -> V_70 ) )
{
if ( V_13 -> V_22 == ( T_1 * ) & ( V_25 -> V_95 ) )
{
V_25 -> V_95 = NULL ;
V_25 -> V_70 = NULL ;
}
else
{
V_25 -> V_70 = V_13 -> V_22 ;
V_13 -> V_22 -> V_23 = ( T_1 * ) & ( V_25 -> V_70 ) ;
}
}
else
{
if ( V_13 -> V_22 == ( T_1 * ) & ( V_25 -> V_95 ) )
{
V_25 -> V_95 = V_13 -> V_23 ;
V_13 -> V_23 -> V_22 = ( T_1 * ) & ( V_25 -> V_95 ) ;
}
else
{
V_13 -> V_23 -> V_22 = V_13 -> V_22 ;
V_13 -> V_22 -> V_23 = V_13 -> V_23 ;
}
}
V_13 -> V_22 = V_13 -> V_23 = NULL ;
}
static void F_28 ( T_6 * V_25 , T_1 * V_13 )
{
if ( ( V_13 -> V_23 != NULL ) && ( V_13 -> V_22 != NULL ) )
F_27 ( V_25 , V_13 ) ;
if ( V_25 -> V_95 == NULL )
{
V_25 -> V_95 = V_13 ;
V_25 -> V_70 = V_13 ;
V_13 -> V_22 = ( T_1 * ) & ( V_25 -> V_95 ) ;
V_13 -> V_23 = ( T_1 * ) & ( V_25 -> V_70 ) ;
}
else
{
V_13 -> V_23 = V_25 -> V_95 ;
V_13 -> V_23 -> V_22 = V_13 ;
V_13 -> V_22 = ( T_1 * ) & ( V_25 -> V_95 ) ;
V_25 -> V_95 = V_13 ;
}
}
