T_1 * F_1 ( T_2 * V_1 )
{
return ( V_1 -> V_2 ) ;
}
int F_2 ( long V_3 , char * V_4 , int (* F_3)() ,
int (* F_4)() , void (* F_5)() )
{
V_5 ++ ;
return ( F_6 ( V_5 - 1 ,
& V_6 ,
V_3 , V_4 , F_3 , F_4 , F_5 ) ) ;
}
int F_7 ( T_1 * V_7 , int V_8 , void * V_9 )
{
return ( F_8 ( & V_7 -> V_10 , V_8 , V_9 ) ) ;
}
void * F_9 ( T_1 * V_7 , int V_8 )
{
return ( F_10 ( & V_7 -> V_10 , V_8 ) ) ;
}
T_1 * F_11 ( void )
{
T_1 * V_11 ;
V_11 = ( T_1 * ) Malloc ( sizeof( T_1 ) ) ;
if ( V_11 == NULL )
{
F_12 ( V_12 , V_13 ) ;
return ( 0 ) ;
}
memset ( V_11 , 0 , sizeof( T_1 ) ) ;
V_11 -> V_14 = 1 ;
V_11 -> V_15 = 60 * 5 + 4 ;
V_11 -> time = time ( NULL ) ;
V_11 -> V_16 = NULL ;
V_11 -> V_17 = NULL ;
V_11 -> V_18 = 0 ;
F_13 ( V_6 , ( char * ) V_11 , & V_11 -> V_10 ) ;
return ( V_11 ) ;
}
int F_14 ( T_2 * V_7 , int V_2 )
{
T_1 * V_11 = NULL ;
if ( ( V_11 = F_11 () ) == NULL ) return ( 0 ) ;
if ( V_7 -> V_19 -> V_20 == 0 )
V_11 -> V_15 = F_15 ( V_7 ) ;
else
V_11 -> V_15 = V_7 -> V_19 -> V_20 ;
if ( V_7 -> V_2 != NULL )
{
F_16 ( V_7 -> V_2 ) ;
V_7 -> V_2 = NULL ;
}
if ( V_2 )
{
if ( V_7 -> V_21 == V_22 )
{
V_11 -> V_23 = V_22 ;
V_11 -> V_24 = V_25 ;
}
else if ( V_7 -> V_21 == V_26 )
{
V_11 -> V_23 = V_26 ;
V_11 -> V_24 = V_27 ;
}
else if ( V_7 -> V_21 == V_28 )
{
V_11 -> V_23 = V_28 ;
V_11 -> V_24 = V_27 ;
}
else
{
F_12 ( V_29 , V_30 ) ;
F_16 ( V_11 ) ;
return ( 0 ) ;
}
for (; ; )
{
T_1 * V_31 ;
F_17 ( V_11 -> V_32 , V_11 -> V_24 ) ;
F_18 ( V_33 ) ;
V_31 = ( T_1 * ) F_19 ( V_7 -> V_19 -> V_34 ,
( char * ) V_11 ) ;
F_20 ( V_33 ) ;
if ( V_31 == NULL ) break;
}
}
else
{
V_11 -> V_24 = 0 ;
}
memcpy ( V_11 -> V_35 , V_7 -> V_35 , V_7 -> V_36 ) ;
V_11 -> V_36 = V_7 -> V_36 ;
V_7 -> V_2 = V_11 ;
V_11 -> V_23 = V_7 -> V_21 ;
return ( 1 ) ;
}
int F_21 ( T_2 * V_7 , unsigned char * V_32 , int V_37 )
{
T_1 * V_38 = NULL , V_39 ;
int V_40 = 0 ;
V_39 . V_23 = V_7 -> V_21 ;
V_39 . V_24 = V_37 ;
if ( V_37 > V_41 )
goto V_42;
memcpy ( V_39 . V_32 , V_32 , V_37 ) ;
if ( ! ( V_7 -> V_19 -> V_43 & V_44 ) )
{
F_18 ( V_33 ) ;
V_38 = ( T_1 * ) F_19 ( V_7 -> V_19 -> V_34 , ( char * ) & V_39 ) ;
if ( V_38 != NULL )
F_22 ( & V_38 -> V_14 , 1 , V_45 ) ;
F_20 ( V_33 ) ;
}
if ( V_38 == NULL )
{
int V_46 = 1 ;
V_7 -> V_19 -> V_47 . V_48 ++ ;
V_38 = NULL ;
if ( V_7 -> V_19 -> V_49 != NULL
&& ( V_38 = V_7 -> V_19 -> V_49 ( V_7 , V_32 , V_37 , & V_46 ) )
!= NULL )
{
V_7 -> V_19 -> V_47 . V_50 ++ ;
if ( V_46 )
F_22 ( & V_38 -> V_14 , 1 , V_45 ) ;
F_23 ( V_7 -> V_19 , V_38 ) ;
}
if ( V_38 == NULL )
goto V_42;
}
if( ( V_7 -> V_51 & V_52 )
&& ( ! V_7 -> V_36 || V_38 -> V_36 != V_7 -> V_36
|| memcmp ( V_38 -> V_35 , V_7 -> V_35 , V_38 -> V_36 ) ) )
{
if ( V_7 -> V_36 == 0 )
{
F_12 ( V_53 , V_54 ) ;
V_40 = 1 ;
goto V_42;
}
else
{
#if 0
SSLerr(SSL_F_SSL_GET_PREV_SESSION,SSL_R_ATTEMPT_TO_REUSE_SESSION_IN_DIFFERENT_CONTEXT);
#endif
goto V_42;
}
}
if ( V_38 -> V_55 == NULL )
{
unsigned char V_56 [ 5 ] , * V_57 ;
unsigned long V_58 ;
V_57 = V_56 ;
V_58 = V_38 -> V_59 ;
F_24 ( V_58 , V_57 ) ;
if ( ( V_38 -> V_23 >> 8 ) == V_60 )
V_38 -> V_55 = F_25 ( V_7 , & ( V_56 [ 2 ] ) ) ;
else
V_38 -> V_55 = F_25 ( V_7 , & ( V_56 [ 1 ] ) ) ;
if ( V_38 -> V_55 == NULL )
goto V_42;
}
#if 0
CRYPTO_add(&ret->references,1,CRYPTO_LOCK_SSL_SESSION);
#endif
if ( ( long ) ( V_38 -> time + V_38 -> V_15 ) < ( long ) time ( NULL ) )
{
V_7 -> V_19 -> V_47 . V_61 ++ ;
F_26 ( V_7 -> V_19 , V_38 ) ;
goto V_42;
}
V_7 -> V_19 -> V_47 . V_62 ++ ;
if ( V_7 -> V_2 != NULL )
F_16 ( V_7 -> V_2 ) ;
V_7 -> V_2 = V_38 ;
return ( 1 ) ;
V_42:
if ( V_38 != NULL )
F_16 ( V_38 ) ;
if ( V_40 )
return - 1 ;
else
return 0 ;
}
int F_23 ( T_3 * V_19 , T_1 * V_63 )
{
int V_38 = 0 ;
T_1 * V_7 ;
F_22 ( & V_63 -> V_14 , 1 , V_45 ) ;
F_27 ( V_33 ) ;
V_7 = ( T_1 * ) F_28 ( V_19 -> V_34 , ( char * ) V_63 ) ;
if ( V_7 == NULL )
F_29 ( V_19 , V_63 ) ;
if ( V_7 != NULL )
{
F_16 ( V_7 ) ;
V_38 = 0 ;
}
else
{
V_38 = 1 ;
if ( F_30 ( V_19 ) > 0 )
{
while ( F_31 ( V_19 ) >
F_30 ( V_19 ) )
{
if ( ! F_32 ( V_19 ,
V_19 -> V_64 , 0 ) )
break;
else
V_19 -> V_47 . V_65 ++ ;
}
}
}
F_33 ( V_33 ) ;
return ( V_38 ) ;
}
int F_26 ( T_3 * V_19 , T_1 * V_63 )
{
return F_32 ( V_19 , V_63 , 1 ) ;
}
static int F_32 ( T_3 * V_19 , T_1 * V_63 , int V_66 )
{
T_1 * V_31 ;
int V_38 = 0 ;
if ( ( V_63 != NULL ) && ( V_63 -> V_24 != 0 ) )
{
if( V_66 ) F_27 ( V_33 ) ;
V_31 = ( T_1 * ) F_34 ( V_19 -> V_34 , ( char * ) V_63 ) ;
if ( V_31 != NULL )
{
V_38 = 1 ;
F_35 ( V_19 , V_63 ) ;
}
if( V_66 ) F_33 ( V_33 ) ;
if ( V_38 )
{
V_31 -> V_67 = 1 ;
if ( V_19 -> V_68 != NULL )
V_19 -> V_68 ( V_19 , V_31 ) ;
F_16 ( V_31 ) ;
}
}
else
V_38 = 0 ;
return ( V_38 ) ;
}
void F_16 ( T_1 * V_11 )
{
int V_69 ;
if( V_11 == NULL )
return;
V_69 = F_22 ( & V_11 -> V_14 , - 1 , V_45 ) ;
#ifdef F_36
F_36 ( L_1 , V_11 ) ;
#endif
if ( V_69 > 0 ) return;
#ifdef F_37
if ( V_69 < 0 )
{
fprintf ( V_70 , L_2 ) ;
abort () ;
}
#endif
F_38 ( V_6 , ( char * ) V_11 , & V_11 -> V_10 ) ;
memset ( V_11 -> V_71 , 0 , V_72 ) ;
memset ( V_11 -> V_73 , 0 , V_74 ) ;
memset ( V_11 -> V_32 , 0 , V_41 ) ;
if ( V_11 -> V_75 != NULL ) F_39 ( V_11 -> V_75 ) ;
if ( V_11 -> V_76 != NULL ) F_40 ( V_11 -> V_76 ) ;
if ( V_11 -> V_77 != NULL ) F_41 ( V_11 -> V_77 ) ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
Free ( V_11 ) ;
}
int F_42 ( T_2 * V_7 , T_1 * V_2 )
{
int V_38 = 0 ;
T_4 * V_78 ;
if ( V_2 != NULL )
{
V_78 = V_7 -> V_19 -> V_79 -> V_80 ( V_2 -> V_23 ) ;
if ( V_78 == NULL )
V_78 = V_7 -> V_79 -> V_80 ( V_2 -> V_23 ) ;
if ( V_78 == NULL )
{
F_12 ( V_81 , V_82 ) ;
return ( 0 ) ;
}
if ( V_78 != V_7 -> V_79 )
{
if ( ! F_43 ( V_7 , V_78 ) )
return ( 0 ) ;
if ( V_7 -> V_19 -> V_20 == 0 )
V_2 -> V_15 = F_15 ( V_7 ) ;
else
V_2 -> V_15 = V_7 -> V_19 -> V_20 ;
}
F_22 ( & V_2 -> V_14 , 1 , V_45 ) ;
if ( V_7 -> V_2 != NULL )
F_16 ( V_7 -> V_2 ) ;
V_7 -> V_2 = V_2 ;
V_38 = 1 ;
}
else
{
if ( V_7 -> V_2 != NULL )
{
F_16 ( V_7 -> V_2 ) ;
V_7 -> V_2 = NULL ;
}
V_78 = V_7 -> V_19 -> V_79 ;
if ( V_78 != V_7 -> V_79 )
{
if ( ! F_43 ( V_7 , V_78 ) )
return ( 0 ) ;
}
V_38 = 1 ;
}
return ( V_38 ) ;
}
long F_44 ( T_1 * V_7 , long V_83 )
{
if ( V_7 == NULL ) return ( 0 ) ;
V_7 -> V_15 = V_83 ;
return ( 1 ) ;
}
long F_45 ( T_1 * V_7 )
{
if ( V_7 == NULL ) return ( 0 ) ;
return ( V_7 -> V_15 ) ;
}
long F_46 ( T_1 * V_7 )
{
if ( V_7 == NULL ) return ( 0 ) ;
return ( V_7 -> time ) ;
}
long F_47 ( T_1 * V_7 , long V_83 )
{
if ( V_7 == NULL ) return ( 0 ) ;
V_7 -> time = V_83 ;
return ( V_83 ) ;
}
long F_48 ( T_3 * V_7 , long V_83 )
{
long V_58 ;
if ( V_7 == NULL ) return ( 0 ) ;
V_58 = V_7 -> V_20 ;
V_7 -> V_20 = V_83 ;
return ( V_58 ) ;
}
long F_49 ( T_3 * V_7 )
{
if ( V_7 == NULL ) return ( 0 ) ;
return ( V_7 -> V_20 ) ;
}
static void V_15 ( T_1 * V_7 , T_5 * V_57 )
{
if ( ( V_57 -> time == 0 ) || ( V_57 -> time > ( V_7 -> time + V_7 -> V_15 ) ) )
{
F_34 ( V_57 -> V_84 , ( char * ) V_7 ) ;
F_35 ( V_57 -> V_19 , V_7 ) ;
V_7 -> V_67 = 1 ;
if ( V_57 -> V_19 -> V_68 != NULL )
V_57 -> V_19 -> V_68 ( V_57 -> V_19 , V_7 ) ;
F_16 ( V_7 ) ;
}
}
void F_50 ( T_3 * V_7 , long V_83 )
{
unsigned long V_69 ;
T_5 V_85 ;
V_85 . V_19 = V_7 ;
V_85 . V_84 = V_7 -> V_34 ;
if ( V_85 . V_84 == NULL ) return;
V_85 . time = V_83 ;
F_27 ( V_33 ) ;
V_69 = V_85 . V_84 -> V_86 ;
V_85 . V_84 -> V_86 = 0 ;
F_51 ( V_85 . V_84 , ( void ( * ) () ) V_15 , ( char * ) & V_85 ) ;
V_85 . V_84 -> V_86 = V_69 ;
F_33 ( V_33 ) ;
}
int F_52 ( T_2 * V_7 )
{
if ( ( V_7 -> V_2 != NULL ) &&
! ( V_7 -> V_87 & V_88 ) &&
! ( F_53 ( V_7 ) || F_54 ( V_7 ) ) )
{
F_26 ( V_7 -> V_19 , V_7 -> V_2 ) ;
return ( 1 ) ;
}
else
return ( 0 ) ;
}
static void F_35 ( T_3 * V_19 , T_1 * V_7 )
{
if ( ( V_7 -> V_17 == NULL ) || ( V_7 -> V_16 == NULL ) ) return;
if ( V_7 -> V_17 == ( T_1 * ) & ( V_19 -> V_64 ) )
{
if ( V_7 -> V_16 == ( T_1 * ) & ( V_19 -> V_89 ) )
{
V_19 -> V_89 = NULL ;
V_19 -> V_64 = NULL ;
}
else
{
V_19 -> V_64 = V_7 -> V_16 ;
V_7 -> V_16 -> V_17 = ( T_1 * ) & ( V_19 -> V_64 ) ;
}
}
else
{
if ( V_7 -> V_16 == ( T_1 * ) & ( V_19 -> V_89 ) )
{
V_19 -> V_89 = V_7 -> V_17 ;
V_7 -> V_17 -> V_16 = ( T_1 * ) & ( V_19 -> V_89 ) ;
}
else
{
V_7 -> V_17 -> V_16 = V_7 -> V_16 ;
V_7 -> V_16 -> V_17 = V_7 -> V_17 ;
}
}
V_7 -> V_16 = V_7 -> V_17 = NULL ;
}
static void F_29 ( T_3 * V_19 , T_1 * V_7 )
{
if ( ( V_7 -> V_17 != NULL ) && ( V_7 -> V_16 != NULL ) )
F_35 ( V_19 , V_7 ) ;
if ( V_19 -> V_89 == NULL )
{
V_19 -> V_89 = V_7 ;
V_19 -> V_64 = V_7 ;
V_7 -> V_16 = ( T_1 * ) & ( V_19 -> V_89 ) ;
V_7 -> V_17 = ( T_1 * ) & ( V_19 -> V_64 ) ;
}
else
{
V_7 -> V_17 = V_19 -> V_89 ;
V_7 -> V_17 -> V_16 = V_7 ;
V_7 -> V_16 = ( T_1 * ) & ( V_19 -> V_89 ) ;
V_19 -> V_89 = V_7 ;
}
}
