T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
T_2 * F_2 ( int V_2 , int V_3 )
{
T_2 * V_4 ;
V_4 = F_3 ( F_1 () ) ;
if ( V_4 == NULL ) return ( NULL ) ;
F_4 ( V_4 , V_2 , V_3 ) ;
return ( V_4 ) ;
}
static int F_5 ( T_2 * V_5 )
{
T_3 * V_6 = NULL ;
V_5 -> V_7 = 0 ;
V_5 -> V_8 = 0 ;
V_6 = F_6 ( sizeof( T_3 ) ) ;
if ( V_6 == NULL )
return 0 ;
memset ( V_6 , 0x00 , sizeof( T_3 ) ) ;
V_5 -> V_9 = V_6 ;
V_5 -> V_10 = 0 ;
return ( 1 ) ;
}
static int F_7 ( T_2 * V_11 )
{
T_3 * V_6 ;
if ( V_11 == NULL ) return ( 0 ) ;
if ( ! F_8 ( V_11 ) )
return 0 ;
V_6 = ( T_3 * ) V_11 -> V_9 ;
if( V_6 != NULL ) F_9 ( V_6 ) ;
return ( 1 ) ;
}
static int F_8 ( T_2 * V_11 )
{
if ( V_11 == NULL ) return ( 0 ) ;
if ( V_11 -> V_12 )
{
if ( V_11 -> V_7 )
{
F_10 ( V_11 -> V_8 ) ;
}
V_11 -> V_7 = 0 ;
V_11 -> V_10 = 0 ;
}
return ( 1 ) ;
}
static void F_11 ( T_2 * V_13 )
{
#if F_12 ( V_14 )
T_3 * V_6 = ( T_3 * ) V_13 -> V_9 ;
int V_15 = sizeof( int ) ;
if ( V_6 -> V_16 . V_17 > 0 || V_6 -> V_16 . V_18 > 0 )
{
struct V_19 V_20 , V_21 ;
#ifdef F_13
int V_22 ;
if ( F_14 ( V_13 -> V_8 , V_23 , V_14 ,
( void * ) & V_22 , & V_15 ) < 0 )
{ perror ( L_1 ) ; }
else
{
V_6 -> V_24 . V_17 = V_22 / 1000 ;
V_6 -> V_24 . V_18 = ( V_22 % 1000 ) * 1000 ;
}
#else
if ( F_14 ( V_13 -> V_8 , V_23 , V_14 ,
& ( V_6 -> V_24 ) , ( void * ) & V_15 ) < 0 )
{ perror ( L_1 ) ; }
#endif
F_15 ( & V_20 ) ;
memcpy ( & V_21 , & ( V_6 -> V_16 ) , sizeof( struct V_19 ) ) ;
V_21 . V_17 -= V_20 . V_17 ;
V_21 . V_18 -= V_20 . V_18 ;
if ( V_21 . V_18 < 0 )
{
V_21 . V_17 -- ;
V_21 . V_18 += 1000000 ;
}
if ( V_21 . V_17 < 0 )
{
V_21 . V_17 = 0 ;
V_21 . V_18 = 1 ;
}
if ( ( V_6 -> V_24 . V_17 == 0 && V_6 -> V_24 . V_18 == 0 ) ||
( V_6 -> V_24 . V_17 > V_21 . V_17 ) ||
( V_6 -> V_24 . V_17 == V_21 . V_17 &&
V_6 -> V_24 . V_18 >= V_21 . V_18 ) )
{
#ifdef F_13
V_22 = V_21 . V_17 * 1000 + V_21 . V_18 / 1000 ;
if ( F_16 ( V_13 -> V_8 , V_23 , V_14 ,
( void * ) & V_22 , sizeof( V_22 ) ) < 0 )
{ perror ( L_2 ) ; }
#else
if ( F_16 ( V_13 -> V_8 , V_23 , V_14 , & V_21 ,
sizeof( struct V_19 ) ) < 0 )
{ perror ( L_2 ) ; }
#endif
}
}
#endif
}
static void F_17 ( T_2 * V_13 )
{
#if F_12 ( V_14 )
T_3 * V_6 = ( T_3 * ) V_13 -> V_9 ;
if ( V_6 -> V_16 . V_17 > 0 || V_6 -> V_16 . V_18 > 0 )
{
#ifdef F_13
int V_22 = V_6 -> V_24 . V_17 * 1000 +
V_6 -> V_24 . V_18 / 1000 ;
if ( F_16 ( V_13 -> V_8 , V_23 , V_14 ,
( void * ) & V_22 , sizeof( V_22 ) ) < 0 )
{ perror ( L_2 ) ; }
#else
if ( F_16 ( V_13 -> V_8 , V_23 , V_14 , & ( V_6 -> V_24 ) ,
sizeof( struct V_19 ) ) < 0 )
{ perror ( L_2 ) ; }
#endif
}
#endif
}
static int F_18 ( T_2 * V_13 , char * V_25 , int V_26 )
{
int V_4 = 0 ;
T_3 * V_6 = ( T_3 * ) V_13 -> V_9 ;
struct {
union { T_4 V_27 ; int V_28 ; } V_29 ;
union {
struct V_30 V_31 ;
struct V_32 V_33 ;
#if V_34
struct V_35 V_36 ;
#endif
} V_37 ;
} V_31 ;
V_31 . V_29 . V_27 = 0 ;
V_31 . V_29 . V_28 = sizeof( V_31 . V_37 ) ;
if ( V_25 != NULL )
{
F_19 () ;
memset ( & V_31 . V_37 , 0x00 , sizeof( V_31 . V_37 ) ) ;
F_11 ( V_13 ) ;
V_4 = F_20 ( V_13 -> V_8 , V_25 , V_26 , 0 , & V_31 . V_37 . V_31 , ( void * ) & V_31 . V_29 ) ;
if ( sizeof( V_31 . V_29 . V_28 ) != sizeof( V_31 . V_29 . V_27 ) && V_31 . V_29 . V_28 == 0 )
{
F_21 ( V_31 . V_29 . V_27 <= sizeof( V_31 . V_37 ) ) ;
V_31 . V_29 . V_28 = ( int ) V_31 . V_29 . V_27 ;
}
F_17 ( V_13 ) ;
if ( ! V_6 -> V_38 && V_4 >= 0 )
F_22 ( V_13 , V_39 , 0 , & V_31 . V_37 ) ;
F_23 ( V_13 ) ;
if ( V_4 < 0 )
{
if ( F_24 ( V_4 ) )
{
F_25 ( V_13 ) ;
V_6 -> V_40 = F_26 () ;
}
}
}
return ( V_4 ) ;
}
static int F_27 ( T_2 * V_13 , const char * V_41 , int V_42 )
{
int V_4 ;
T_3 * V_6 = ( T_3 * ) V_13 -> V_9 ;
F_19 () ;
if ( V_6 -> V_38 )
V_4 = F_28 ( V_13 -> V_8 , V_41 , V_42 ) ;
else
{
int V_43 = sizeof( V_6 -> V_37 ) ;
if ( V_6 -> V_37 . V_31 . V_44 == V_45 )
V_43 = sizeof( V_6 -> V_37 . V_33 ) ;
#if V_46
else if ( V_6 -> V_37 . V_31 . V_44 == V_47 )
V_43 = sizeof( V_6 -> V_37 . V_36 ) ;
#endif
#if F_12 ( V_48 ) && F_12 ( V_49 )
V_4 = F_29 ( V_13 -> V_8 , ( char * ) V_41 , V_42 , 0 , & V_6 -> V_37 . V_31 , V_43 ) ;
#else
V_4 = F_29 ( V_13 -> V_8 , V_41 , V_42 , 0 , & V_6 -> V_37 . V_31 , V_43 ) ;
#endif
}
F_23 ( V_13 ) ;
if ( V_4 <= 0 )
{
if ( F_24 ( V_4 ) )
{
F_30 ( V_13 ) ;
V_6 -> V_40 = F_26 () ;
#if 0
if ( data->_errno == EMSGSIZE)
BIO_ctrl(b, BIO_CTRL_DGRAM_QUERY_MTU, 0, NULL);
#endif
}
}
return ( V_4 ) ;
}
static long F_31 ( T_2 * V_13 , int V_50 , long V_8 , void * V_9 )
{
long V_4 = 1 ;
int * V_51 ;
struct V_30 * V_52 = NULL ;
T_3 * V_6 = NULL ;
#if F_12 ( V_53 ) || F_12 ( V_54 )
long V_55 = 0 ;
unsigned int V_56 = 0 ;
#endif
#ifdef F_32
T_5 V_57 ;
union {
struct V_30 V_31 ;
struct V_32 V_58 ;
#if V_34
struct V_35 V_59 ;
#endif
} V_60 ;
#endif
V_6 = ( T_3 * ) V_13 -> V_9 ;
switch ( V_50 )
{
case V_61 :
V_8 = 0 ;
case V_62 :
V_4 = 0 ;
break;
case V_63 :
case V_64 :
V_4 = 0 ;
break;
case V_65 :
F_8 ( V_13 ) ;
V_13 -> V_8 = * ( ( int * ) V_9 ) ;
V_13 -> V_12 = ( int ) V_8 ;
V_13 -> V_7 = 1 ;
break;
case V_66 :
if ( V_13 -> V_7 )
{
V_51 = ( int * ) V_9 ;
if ( V_51 != NULL ) * V_51 = V_13 -> V_8 ;
V_4 = V_13 -> V_8 ;
}
else
V_4 = - 1 ;
break;
case V_67 :
V_4 = V_13 -> V_12 ;
break;
case V_68 :
V_13 -> V_12 = ( int ) V_8 ;
break;
case V_69 :
case V_70 :
V_4 = 0 ;
break;
case V_71 :
case V_72 :
V_4 = 1 ;
break;
case V_73 :
V_52 = (struct V_30 * ) V_9 ;
#if 0
if (connect(b->num, to, sizeof(struct sockaddr)) < 0)
{ perror("connect"); ret = 0; }
else
{
#endif
switch ( V_52 -> V_44 )
{
case V_45 :
memcpy ( & V_6 -> V_37 , V_52 , sizeof( V_6 -> V_37 . V_33 ) ) ;
break;
#if V_34
case V_47 :
memcpy ( & V_6 -> V_37 , V_52 , sizeof( V_6 -> V_37 . V_36 ) ) ;
break;
#endif
default:
memcpy ( & V_6 -> V_37 , V_52 , sizeof( V_6 -> V_37 . V_31 ) ) ;
break;
}
#if 0
}
#endif
break;
case V_74 :
#ifdef F_32
V_57 = ( T_5 ) sizeof( V_60 ) ;
memset ( ( void * ) & V_60 , 0 , sizeof( V_60 ) ) ;
if ( F_33 ( V_13 -> V_8 , & V_60 . V_31 , & V_57 ) < 0 )
{
V_4 = 0 ;
break;
}
V_56 = sizeof( V_55 ) ;
switch ( V_60 . V_31 . V_44 )
{
case V_45 :
V_55 = V_75 ;
if ( ( V_4 = F_16 ( V_13 -> V_8 , V_76 , V_53 ,
& V_55 , sizeof( V_55 ) ) ) < 0 )
perror ( L_2 ) ;
break;
#if V_34 && F_12 ( V_77 )
case V_47 :
V_55 = V_78 ;
if ( ( V_4 = F_16 ( V_13 -> V_8 , V_79 , V_77 ,
& V_55 , sizeof( V_55 ) ) ) < 0 )
perror ( L_2 ) ;
break;
#endif
default:
V_4 = - 1 ;
break;
}
V_4 = - 1 ;
#else
break;
#endif
case V_80 :
#ifdef F_32
V_57 = ( T_5 ) sizeof( V_60 ) ;
memset ( ( void * ) & V_60 , 0 , sizeof( V_60 ) ) ;
if ( F_33 ( V_13 -> V_8 , & V_60 . V_31 , & V_57 ) < 0 )
{
V_4 = 0 ;
break;
}
V_56 = sizeof( V_55 ) ;
switch ( V_60 . V_31 . V_44 )
{
case V_45 :
if ( ( V_4 = F_14 ( V_13 -> V_8 , V_76 , V_54 , ( void * ) & V_55 ,
& V_56 ) ) < 0 || V_55 < 0 )
{
V_4 = 0 ;
}
else
{
V_6 -> V_81 = V_55 - 8 - 20 ;
V_4 = V_6 -> V_81 ;
}
break;
#if V_34 && F_12 ( V_82 )
case V_47 :
if ( ( V_4 = F_14 ( V_13 -> V_8 , V_79 , V_82 , ( void * ) & V_55 ,
& V_56 ) ) < 0 || V_55 < 0 )
{
V_4 = 0 ;
}
else
{
V_6 -> V_81 = V_55 - 8 - 40 ;
V_4 = V_6 -> V_81 ;
}
break;
#endif
default:
V_4 = 0 ;
break;
}
#else
V_4 = 0 ;
#endif
break;
case V_83 :
return V_6 -> V_81 ;
break;
case V_84 :
V_6 -> V_81 = V_8 ;
V_4 = V_8 ;
break;
case V_85 :
V_52 = (struct V_30 * ) V_9 ;
if ( V_52 != NULL )
{
V_6 -> V_38 = 1 ;
switch ( V_52 -> V_44 )
{
case V_45 :
memcpy ( & V_6 -> V_37 , V_52 , sizeof( V_6 -> V_37 . V_33 ) ) ;
break;
#if V_34
case V_47 :
memcpy ( & V_6 -> V_37 , V_52 , sizeof( V_6 -> V_37 . V_36 ) ) ;
break;
#endif
default:
memcpy ( & V_6 -> V_37 , V_52 , sizeof( V_6 -> V_37 . V_31 ) ) ;
break;
}
}
else
{
V_6 -> V_38 = 0 ;
memset ( & ( V_6 -> V_37 ) , 0x00 , sizeof( V_6 -> V_37 ) ) ;
}
break;
case V_86 :
switch ( V_6 -> V_37 . V_31 . V_44 )
{
case V_45 :
V_4 = sizeof( V_6 -> V_37 . V_33 ) ;
break;
#if V_34
case V_47 :
V_4 = sizeof( V_6 -> V_37 . V_36 ) ;
break;
#endif
default:
V_4 = sizeof( V_6 -> V_37 . V_31 ) ;
break;
}
if ( V_8 == 0 || V_8 > V_4 )
V_8 = V_4 ;
memcpy ( V_9 , & V_6 -> V_37 , ( V_4 = V_8 ) ) ;
break;
case V_39 :
V_52 = (struct V_30 * ) V_9 ;
switch ( V_52 -> V_44 )
{
case V_45 :
memcpy ( & V_6 -> V_37 , V_52 , sizeof( V_6 -> V_37 . V_33 ) ) ;
break;
#if V_34
case V_47 :
memcpy ( & V_6 -> V_37 , V_52 , sizeof( V_6 -> V_37 . V_36 ) ) ;
break;
#endif
default:
memcpy ( & V_6 -> V_37 , V_52 , sizeof( V_6 -> V_37 . V_31 ) ) ;
break;
}
break;
case V_87 :
memcpy ( & ( V_6 -> V_16 ) , V_9 , sizeof( struct V_19 ) ) ;
break;
#if F_12 ( V_14 )
case V_88 :
#ifdef F_13
{
struct V_19 * V_89 = (struct V_19 * ) V_9 ;
int V_22 = V_89 -> V_17 * 1000 + V_89 -> V_18 / 1000 ;
if ( F_16 ( V_13 -> V_8 , V_23 , V_14 ,
( void * ) & V_22 , sizeof( V_22 ) ) < 0 )
{ perror ( L_2 ) ; V_4 = - 1 ; }
}
#else
if ( F_16 ( V_13 -> V_8 , V_23 , V_14 , V_9 ,
sizeof( struct V_19 ) ) < 0 )
{ perror ( L_2 ) ; V_4 = - 1 ; }
#endif
break;
case V_90 :
#ifdef F_13
{
int V_22 , V_15 = sizeof( V_22 ) ;
struct V_19 * V_89 = (struct V_19 * ) V_9 ;
if ( F_14 ( V_13 -> V_8 , V_23 , V_14 ,
( void * ) & V_22 , & V_15 ) < 0 )
{ perror ( L_1 ) ; V_4 = - 1 ; }
else
{
V_89 -> V_17 = V_22 / 1000 ;
V_89 -> V_18 = ( V_22 % 1000 ) * 1000 ;
V_4 = sizeof( * V_89 ) ;
}
}
#else
if ( F_14 ( V_13 -> V_8 , V_23 , V_14 ,
V_9 , ( void * ) & V_4 ) < 0 )
{ perror ( L_1 ) ; V_4 = - 1 ; }
#endif
break;
#endif
#if F_12 ( V_91 )
case V_92 :
#ifdef F_13
{
struct V_19 * V_89 = (struct V_19 * ) V_9 ;
int V_22 = V_89 -> V_17 * 1000 + V_89 -> V_18 / 1000 ;
if ( F_16 ( V_13 -> V_8 , V_23 , V_91 ,
( void * ) & V_22 , sizeof( V_22 ) ) < 0 )
{ perror ( L_2 ) ; V_4 = - 1 ; }
}
#else
if ( F_16 ( V_13 -> V_8 , V_23 , V_91 , V_9 ,
sizeof( struct V_19 ) ) < 0 )
{ perror ( L_2 ) ; V_4 = - 1 ; }
#endif
break;
case V_93 :
#ifdef F_13
{
int V_22 , V_15 = sizeof( V_22 ) ;
struct V_19 * V_89 = (struct V_19 * ) V_9 ;
if ( F_14 ( V_13 -> V_8 , V_23 , V_91 ,
( void * ) & V_22 , & V_15 ) < 0 )
{ perror ( L_1 ) ; V_4 = - 1 ; }
else
{
V_89 -> V_17 = V_22 / 1000 ;
V_89 -> V_18 = ( V_22 % 1000 ) * 1000 ;
V_4 = sizeof( * V_89 ) ;
}
}
#else
if ( F_14 ( V_13 -> V_8 , V_23 , V_91 ,
V_9 , ( void * ) & V_4 ) < 0 )
{ perror ( L_1 ) ; V_4 = - 1 ; }
#endif
break;
#endif
case V_94 :
case V_95 :
#ifdef F_13
if ( V_6 -> V_40 == V_96 )
#else
if ( V_6 -> V_40 == V_97 )
#endif
{
V_4 = 1 ;
V_6 -> V_40 = 0 ;
}
else
V_4 = 0 ;
break;
#ifdef F_34
case V_98 :
if ( V_6 -> V_40 == F_34 )
{
V_4 = 1 ;
V_6 -> V_40 = 0 ;
}
else
V_4 = 0 ;
break;
#endif
default:
V_4 = 0 ;
break;
}
return ( V_4 ) ;
}
static int F_35 ( T_2 * V_99 , const char * V_100 )
{
int V_101 , V_4 ;
V_101 = strlen ( V_100 ) ;
V_4 = F_27 ( V_99 , V_100 , V_101 ) ;
return ( V_4 ) ;
}
static int F_24 ( int V_28 )
{
int V_102 ;
if ( ( V_28 == 0 ) || ( V_28 == - 1 ) )
{
V_102 = F_26 () ;
#if F_12 ( F_13 ) && 0
if ( ( V_28 == - 1 ) && ( V_102 == 0 ) )
return ( 1 ) ;
#endif
return ( F_36 ( V_102 ) ) ;
}
return ( 0 ) ;
}
int F_36 ( int V_102 )
{
switch ( V_102 )
{
#if F_12 ( F_13 )
# if F_12 ( V_103 )
case V_103 :
# endif
# if 0
# if F_12 ( V_104 )
case WSAENOTCONN:
# endif
# endif
#endif
#ifdef F_37
# ifdef V_103
# if V_103 != F_37
case F_37 :
# endif
# else
case F_37 :
# endif
#endif
#ifdef F_38
case F_38 :
#endif
#ifdef V_97
#if F_37 != V_97
case V_97 :
# endif
#endif
#ifdef F_39
case F_39 :
#endif
#ifdef F_40
case F_40 :
#endif
#ifdef F_41
case F_41 :
#endif
return ( 1 ) ;
default:
break;
}
return ( 0 ) ;
}
static void F_15 ( struct V_19 * V_105 )
{
#ifdef F_42
struct V_106 V_107 ;
F_43 ( & V_107 ) ;
V_105 -> V_17 = ( long ) V_107 . time ;
V_105 -> V_18 = ( long ) V_107 . V_108 * 1000 ;
#elif F_12 ( V_109 )
struct V_110 V_107 ;
F_44 ( & V_107 ) ;
V_105 -> V_17 = ( long ) V_107 . time ;
V_105 -> V_18 = ( long ) V_107 . V_108 * 1000 ;
#else
F_45 ( V_105 , NULL ) ;
#endif
}
