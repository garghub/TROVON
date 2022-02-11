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
F_17 ( V_13 ) ;
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
#if V_34
else if ( V_6 -> V_37 . V_31 . V_44 == V_46 )
V_43 = sizeof( V_6 -> V_37 . V_36 ) ;
#endif
#if F_12 ( V_47 ) && F_12 ( V_48 )
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
static long F_31 ( T_2 * V_13 , int V_49 , long V_8 , void * V_9 )
{
long V_4 = 1 ;
int * V_50 ;
struct V_30 * V_51 = NULL ;
T_3 * V_6 = NULL ;
#if F_12 ( V_52 ) || F_12 ( V_53 )
long V_54 = 0 ;
unsigned int V_55 = 0 ;
#endif
#ifdef F_32
T_5 V_56 ;
union {
struct V_30 V_31 ;
struct V_32 V_57 ;
#if V_34
struct V_35 V_58 ;
#endif
} V_59 ;
#endif
V_6 = ( T_3 * ) V_13 -> V_9 ;
switch ( V_49 )
{
case V_60 :
V_8 = 0 ;
case V_61 :
V_4 = 0 ;
break;
case V_62 :
case V_63 :
V_4 = 0 ;
break;
case V_64 :
F_8 ( V_13 ) ;
V_13 -> V_8 = * ( ( int * ) V_9 ) ;
V_13 -> V_12 = ( int ) V_8 ;
V_13 -> V_7 = 1 ;
break;
case V_65 :
if ( V_13 -> V_7 )
{
V_50 = ( int * ) V_9 ;
if ( V_50 != NULL ) * V_50 = V_13 -> V_8 ;
V_4 = V_13 -> V_8 ;
}
else
V_4 = - 1 ;
break;
case V_66 :
V_4 = V_13 -> V_12 ;
break;
case V_67 :
V_13 -> V_12 = ( int ) V_8 ;
break;
case V_68 :
case V_69 :
V_4 = 0 ;
break;
case V_70 :
case V_71 :
V_4 = 1 ;
break;
case V_72 :
V_51 = (struct V_30 * ) V_9 ;
#if 0
if (connect(b->num, to, sizeof(struct sockaddr)) < 0)
{ perror("connect"); ret = 0; }
else
{
#endif
switch ( V_51 -> V_44 )
{
case V_45 :
memcpy ( & V_6 -> V_37 , V_51 , sizeof( V_6 -> V_37 . V_33 ) ) ;
break;
#if V_34
case V_46 :
memcpy ( & V_6 -> V_37 , V_51 , sizeof( V_6 -> V_37 . V_36 ) ) ;
break;
#endif
default:
memcpy ( & V_6 -> V_37 , V_51 , sizeof( V_6 -> V_37 . V_31 ) ) ;
break;
}
#if 0
}
#endif
break;
case V_73 :
#ifdef F_32
V_56 = ( T_5 ) sizeof( V_59 ) ;
memset ( ( void * ) & V_59 , 0 , sizeof( V_59 ) ) ;
if ( F_33 ( V_13 -> V_8 , & V_59 . V_31 , & V_56 ) < 0 )
{
V_4 = 0 ;
break;
}
V_55 = sizeof( V_54 ) ;
switch ( V_59 . V_31 . V_44 )
{
case V_45 :
V_54 = V_74 ;
if ( ( V_4 = F_16 ( V_13 -> V_8 , V_75 , V_52 ,
& V_54 , sizeof( V_54 ) ) ) < 0 )
perror ( L_2 ) ;
break;
#if V_34 && F_12 ( V_76 )
case V_46 :
V_54 = V_77 ;
if ( ( V_4 = F_16 ( V_13 -> V_8 , V_78 , V_76 ,
& V_54 , sizeof( V_54 ) ) ) < 0 )
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
case V_79 :
#ifdef F_32
V_56 = ( T_5 ) sizeof( V_59 ) ;
memset ( ( void * ) & V_59 , 0 , sizeof( V_59 ) ) ;
if ( F_33 ( V_13 -> V_8 , & V_59 . V_31 , & V_56 ) < 0 )
{
V_4 = 0 ;
break;
}
V_55 = sizeof( V_54 ) ;
switch ( V_59 . V_31 . V_44 )
{
case V_45 :
if ( ( V_4 = F_14 ( V_13 -> V_8 , V_75 , V_53 , ( void * ) & V_54 ,
& V_55 ) ) < 0 || V_54 < 0 )
{
V_4 = 0 ;
}
else
{
V_6 -> V_80 = V_54 - 8 - 20 ;
V_4 = V_6 -> V_80 ;
}
break;
#if V_34 && F_12 ( V_81 )
case V_46 :
if ( ( V_4 = F_14 ( V_13 -> V_8 , V_78 , V_81 , ( void * ) & V_54 ,
& V_55 ) ) < 0 || V_54 < 0 )
{
V_4 = 0 ;
}
else
{
V_6 -> V_80 = V_54 - 8 - 40 ;
V_4 = V_6 -> V_80 ;
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
case V_82 :
switch ( V_6 -> V_37 . V_31 . V_44 )
{
case V_45 :
V_4 = 576 - 20 - 8 ;
break;
#if V_34
case V_46 :
#ifdef F_34
if ( F_34 ( & V_6 -> V_37 . V_36 . V_83 ) )
V_4 = 576 - 20 - 8 ;
else
#endif
V_4 = 1280 - 40 - 8 ;
break;
#endif
default:
V_4 = 576 - 20 - 8 ;
break;
}
break;
case V_84 :
return V_6 -> V_80 ;
break;
case V_85 :
V_6 -> V_80 = V_8 ;
V_4 = V_8 ;
break;
case V_86 :
V_51 = (struct V_30 * ) V_9 ;
if ( V_51 != NULL )
{
V_6 -> V_38 = 1 ;
switch ( V_51 -> V_44 )
{
case V_45 :
memcpy ( & V_6 -> V_37 , V_51 , sizeof( V_6 -> V_37 . V_33 ) ) ;
break;
#if V_34
case V_46 :
memcpy ( & V_6 -> V_37 , V_51 , sizeof( V_6 -> V_37 . V_36 ) ) ;
break;
#endif
default:
memcpy ( & V_6 -> V_37 , V_51 , sizeof( V_6 -> V_37 . V_31 ) ) ;
break;
}
}
else
{
V_6 -> V_38 = 0 ;
memset ( & ( V_6 -> V_37 ) , 0x00 , sizeof( V_6 -> V_37 ) ) ;
}
break;
case V_87 :
switch ( V_6 -> V_37 . V_31 . V_44 )
{
case V_45 :
V_4 = sizeof( V_6 -> V_37 . V_33 ) ;
break;
#if V_34
case V_46 :
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
V_51 = (struct V_30 * ) V_9 ;
switch ( V_51 -> V_44 )
{
case V_45 :
memcpy ( & V_6 -> V_37 , V_51 , sizeof( V_6 -> V_37 . V_33 ) ) ;
break;
#if V_34
case V_46 :
memcpy ( & V_6 -> V_37 , V_51 , sizeof( V_6 -> V_37 . V_36 ) ) ;
break;
#endif
default:
memcpy ( & V_6 -> V_37 , V_51 , sizeof( V_6 -> V_37 . V_31 ) ) ;
break;
}
break;
case V_88 :
memcpy ( & ( V_6 -> V_16 ) , V_9 , sizeof( struct V_19 ) ) ;
break;
#if F_12 ( V_14 )
case V_89 :
#ifdef F_13
{
struct V_19 * V_90 = (struct V_19 * ) V_9 ;
int V_22 = V_90 -> V_17 * 1000 + V_90 -> V_18 / 1000 ;
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
case V_91 :
#ifdef F_13
{
int V_22 , V_15 = sizeof( V_22 ) ;
struct V_19 * V_90 = (struct V_19 * ) V_9 ;
if ( F_14 ( V_13 -> V_8 , V_23 , V_14 ,
( void * ) & V_22 , & V_15 ) < 0 )
{ perror ( L_1 ) ; V_4 = - 1 ; }
else
{
V_90 -> V_17 = V_22 / 1000 ;
V_90 -> V_18 = ( V_22 % 1000 ) * 1000 ;
V_4 = sizeof( * V_90 ) ;
}
}
#else
if ( F_14 ( V_13 -> V_8 , V_23 , V_14 ,
V_9 , ( void * ) & V_4 ) < 0 )
{ perror ( L_1 ) ; V_4 = - 1 ; }
#endif
break;
#endif
#if F_12 ( V_92 )
case V_93 :
#ifdef F_13
{
struct V_19 * V_90 = (struct V_19 * ) V_9 ;
int V_22 = V_90 -> V_17 * 1000 + V_90 -> V_18 / 1000 ;
if ( F_16 ( V_13 -> V_8 , V_23 , V_92 ,
( void * ) & V_22 , sizeof( V_22 ) ) < 0 )
{ perror ( L_2 ) ; V_4 = - 1 ; }
}
#else
if ( F_16 ( V_13 -> V_8 , V_23 , V_92 , V_9 ,
sizeof( struct V_19 ) ) < 0 )
{ perror ( L_2 ) ; V_4 = - 1 ; }
#endif
break;
case V_94 :
#ifdef F_13
{
int V_22 , V_15 = sizeof( V_22 ) ;
struct V_19 * V_90 = (struct V_19 * ) V_9 ;
if ( F_14 ( V_13 -> V_8 , V_23 , V_92 ,
( void * ) & V_22 , & V_15 ) < 0 )
{ perror ( L_1 ) ; V_4 = - 1 ; }
else
{
V_90 -> V_17 = V_22 / 1000 ;
V_90 -> V_18 = ( V_22 % 1000 ) * 1000 ;
V_4 = sizeof( * V_90 ) ;
}
}
#else
if ( F_14 ( V_13 -> V_8 , V_23 , V_92 ,
V_9 , ( void * ) & V_4 ) < 0 )
{ perror ( L_1 ) ; V_4 = - 1 ; }
#endif
break;
#endif
case V_95 :
case V_96 :
#ifdef F_13
if ( V_6 -> V_40 == V_97 )
#else
if ( V_6 -> V_40 == V_98 )
#endif
{
V_4 = 1 ;
V_6 -> V_40 = 0 ;
}
else
V_4 = 0 ;
break;
#ifdef F_35
case V_99 :
if ( V_6 -> V_40 == F_35 )
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
static int F_36 ( T_2 * V_100 , const char * V_101 )
{
int V_102 , V_4 ;
V_102 = strlen ( V_101 ) ;
V_4 = F_27 ( V_100 , V_101 , V_102 ) ;
return ( V_4 ) ;
}
T_1 * F_37 ( void )
{
return ( & V_103 ) ;
}
T_2 * F_38 ( int V_2 , int V_3 )
{
T_2 * V_104 ;
int V_4 , V_105 = 20000 ;
int V_106 = 0 , V_107 = 0 ;
unsigned char * V_108 ;
struct V_109 V_110 ;
struct V_111 * V_112 ;
T_5 V_55 ;
#ifdef F_39
#ifdef F_40
struct V_113 V_114 ;
#else
struct V_115 V_114 ;
#endif
#endif
V_104 = F_3 ( F_37 () ) ;
if ( V_104 == NULL ) return ( NULL ) ;
F_4 ( V_104 , V_2 , V_3 ) ;
V_110 . V_116 = V_117 ;
V_4 = F_16 ( V_2 , V_118 , V_119 , & V_110 , sizeof( struct V_109 ) ) ;
F_21 ( V_4 >= 0 ) ;
V_110 . V_116 = V_120 ;
V_4 = F_16 ( V_2 , V_118 , V_119 , & V_110 , sizeof( struct V_109 ) ) ;
F_21 ( V_4 >= 0 ) ;
V_55 = ( T_5 ) ( sizeof( V_121 ) + 256 * sizeof( V_122 ) ) ;
V_112 = F_6 ( V_55 ) ;
memset ( V_112 , 0 , sizeof( V_55 ) ) ;
V_4 = F_14 ( V_2 , V_118 , V_123 , V_112 , & V_55 ) ;
F_21 ( V_4 >= 0 ) ;
for ( V_108 = ( unsigned char * ) V_112 + sizeof( V_121 ) ;
V_108 < ( unsigned char * ) V_112 + V_55 ;
V_108 += sizeof( V_122 ) )
{
if ( * V_108 == V_117 ) V_106 = 1 ;
if ( * V_108 == V_120 ) V_107 = 1 ;
}
F_9 ( V_112 ) ;
F_21 ( V_106 ) ;
F_21 ( V_107 ) ;
#ifdef F_39
#ifdef F_40
memset ( & V_114 , 0 , sizeof( struct V_113 ) ) ;
V_114 . V_124 = 0 ;
V_114 . V_125 = F_39 ;
V_114 . V_126 = 1 ;
V_4 = F_16 ( V_2 , V_118 , F_40 , & V_114 , sizeof( struct V_113 ) ) ;
F_21 ( V_4 >= 0 ) ;
#else
V_55 = ( T_5 ) sizeof( struct V_115 ) ;
V_4 = F_14 ( V_2 , V_118 , V_127 , & V_114 , & V_55 ) ;
F_21 ( V_4 >= 0 ) ;
V_114 . V_128 = 1 ;
V_4 = F_16 ( V_2 , V_118 , V_127 , & V_114 , sizeof( struct V_115 ) ) ;
F_21 ( V_4 >= 0 ) ;
#endif
#endif
V_4 = F_16 ( V_2 , V_118 , V_129 , & V_105 , sizeof( V_105 ) ) ;
F_21 ( V_4 >= 0 ) ;
return ( V_104 ) ;
}
int F_41 ( T_2 * V_104 )
{
return ( F_42 ( V_104 ) == V_130 ) ;
}
static int F_43 ( T_2 * V_5 )
{
T_6 * V_6 = NULL ;
V_5 -> V_7 = 0 ;
V_5 -> V_8 = 0 ;
V_6 = F_6 ( sizeof( T_6 ) ) ;
if ( V_6 == NULL )
return 0 ;
memset ( V_6 , 0x00 , sizeof( T_6 ) ) ;
#ifdef F_44
V_6 -> V_131 . V_132 = F_44 ;
#endif
V_5 -> V_9 = V_6 ;
V_5 -> V_10 = 0 ;
return ( 1 ) ;
}
static int F_45 ( T_2 * V_11 )
{
T_6 * V_6 ;
if ( V_11 == NULL ) return ( 0 ) ;
if ( ! F_8 ( V_11 ) )
return 0 ;
V_6 = ( T_6 * ) V_11 -> V_9 ;
if( V_6 != NULL ) F_9 ( V_6 ) ;
return ( 1 ) ;
}
void F_46 ( T_2 * V_13 , union V_133 * V_134 )
{
unsigned int V_55 = 0 ;
int V_4 ;
struct V_135 * V_136 = & V_134 -> V_137 ;
if ( V_136 -> V_138 == V_139 )
{
struct V_140 V_141 ;
V_141 . V_142 = V_136 -> V_143 ;
V_55 = sizeof( struct V_140 ) ;
V_4 = F_16 ( V_13 -> V_8 , V_118 , V_144 ,
& V_141 , V_55 ) ;
}
}
static int F_47 ( T_2 * V_13 , char * V_25 , int V_26 )
{
int V_4 = 0 , V_102 = 0 , V_28 , V_105 ;
T_5 V_145 ;
T_6 * V_6 = ( T_6 * ) V_13 -> V_9 ;
union V_133 * V_134 ;
struct V_146 V_147 ;
struct V_148 V_149 ;
struct V_150 * V_151 ;
char V_152 [ 512 ] ;
if ( V_25 != NULL )
{
F_19 () ;
do
{
memset ( & V_6 -> V_153 , 0x00 , sizeof( struct V_154 ) ) ;
V_149 . V_155 = V_25 ;
V_149 . V_156 = V_26 ;
V_147 . V_157 = NULL ;
V_147 . V_158 = 0 ;
V_147 . V_159 = & V_149 ;
V_147 . V_160 = 1 ;
V_147 . V_161 = V_152 ;
V_147 . V_162 = 512 ;
V_147 . V_163 = 0 ;
V_102 = F_48 ( V_13 -> V_8 , & V_147 , 0 ) ;
if ( V_147 . V_162 > 0 )
{
for ( V_151 = F_49 ( & V_147 ) ; V_151 ; V_151 = F_50 ( & V_147 , V_151 ) )
{
if ( V_151 -> V_164 != V_118 )
continue;
#ifdef F_51
if ( V_151 -> V_165 == F_51 )
{
struct V_166 * V_153 ;
V_153 = (struct V_166 * ) F_52 ( V_151 ) ;
V_6 -> V_153 . V_167 = V_153 -> V_167 ;
V_6 -> V_153 . V_168 = V_153 -> V_168 ;
V_6 -> V_153 . V_169 = V_153 -> V_169 ;
V_6 -> V_153 . V_170 = V_153 -> V_170 ;
V_6 -> V_153 . V_171 = V_153 -> V_171 ;
V_6 -> V_153 . V_172 = V_153 -> V_172 ;
V_6 -> V_153 . V_173 = V_153 -> V_173 ;
}
#endif
#ifdef F_53
if ( V_151 -> V_165 == F_53 )
{
struct V_174 * V_175 ;
V_175 = (struct V_174 * ) F_52 ( V_151 ) ;
V_6 -> V_153 . V_167 = V_175 -> V_176 ;
V_6 -> V_153 . V_168 = V_175 -> V_177 ;
V_6 -> V_153 . V_169 = V_175 -> V_178 ;
V_6 -> V_153 . V_170 = V_175 -> V_179 ;
V_6 -> V_153 . V_171 = V_175 -> V_180 ;
V_6 -> V_153 . V_172 = V_175 -> V_181 ;
V_6 -> V_153 . V_173 = V_175 -> V_182 ;
}
#endif
}
}
if ( V_102 <= 0 )
{
if ( V_102 < 0 )
V_4 = V_102 ;
break;
}
if ( V_147 . V_163 & V_183 )
{
V_134 = (union V_133 * ) V_25 ;
if ( V_134 -> V_184 . V_185 == V_186 )
{
#ifdef F_40
struct V_113 V_114 ;
#else
struct V_115 V_114 ;
T_5 V_187 ;
#endif
if ( V_6 -> V_188 . V_189 > 0 )
{
F_54 ( V_6 -> V_188 . V_104 , V_6 -> V_188 . V_6 ,
V_6 -> V_188 . V_189 ) ;
F_9 ( V_6 -> V_188 . V_6 ) ;
V_6 -> V_188 . V_189 = 0 ;
}
#ifdef F_40
memset ( & V_114 , 0 , sizeof( struct V_113 ) ) ;
V_114 . V_124 = 0 ;
V_114 . V_125 = V_186 ;
V_114 . V_126 = 0 ;
V_28 = F_16 ( V_13 -> V_8 , V_118 , F_40 , & V_114 , sizeof( struct V_113 ) ) ;
F_21 ( V_28 >= 0 ) ;
#else
V_187 = sizeof( struct V_115 ) ;
V_28 = F_14 ( V_13 -> V_8 , V_118 , V_127 , & V_114 , & V_187 ) ;
F_21 ( V_28 >= 0 ) ;
V_114 . V_190 = 0 ;
V_28 = F_16 ( V_13 -> V_8 , V_118 , V_127 , & V_114 , sizeof( struct V_115 ) ) ;
F_21 ( V_28 >= 0 ) ;
#endif
}
#ifdef F_39
if ( V_134 -> V_184 . V_185 == F_39 )
F_46 ( V_13 , V_134 ) ;
#endif
if ( V_6 -> V_191 != NULL )
V_6 -> V_191 ( V_13 , V_6 -> V_192 , ( void * ) V_25 ) ;
memset ( V_25 , 0 , V_26 ) ;
}
else
V_4 += V_102 ;
}
while ( ( V_147 . V_163 & V_183 ) && ( V_147 . V_163 & V_193 ) && ( V_4 < V_26 ) );
if ( V_4 > 0 && ! ( V_147 . V_163 & V_193 ) )
{
if ( V_4 == V_26 )
return - 1 ;
V_145 = ( T_5 ) sizeof( int ) ;
V_4 = F_14 ( V_13 -> V_8 , V_23 , V_194 , & V_105 , & V_145 ) ;
F_21 ( V_4 >= 0 ) ;
F_21 ( V_105 >= 18445 ) ;
V_145 = ( T_5 ) sizeof( int ) ;
V_4 = F_14 ( V_13 -> V_8 , V_118 , V_129 ,
& V_105 , & V_145 ) ;
F_21 ( V_4 >= 0 ) ;
F_21 ( V_105 >= 18445 ) ;
F_21 ( ! ( V_147 . V_163 & V_183 ) ) ;
memset ( V_25 , 0 , V_26 ) ;
F_25 ( V_13 ) ;
return - 1 ;
}
F_23 ( V_13 ) ;
if ( V_4 < 0 )
{
if ( F_24 ( V_4 ) )
{
F_25 ( V_13 ) ;
V_6 -> V_40 = F_26 () ;
}
}
if ( ! V_6 -> V_195 )
{
int V_196 , V_106 = 0 , V_107 = 0 ;
unsigned char * V_108 ;
struct V_111 * V_112 ;
V_145 = ( T_5 ) ( sizeof( V_121 ) + 256 * sizeof( V_122 ) ) ;
V_112 = F_6 ( V_145 ) ;
memset ( V_112 , 0 , sizeof( V_145 ) ) ;
V_196 = F_14 ( V_13 -> V_8 , V_118 , V_197 , V_112 , & V_145 ) ;
F_21 ( V_196 >= 0 ) ;
for ( V_108 = ( unsigned char * ) V_112 + sizeof( V_121 ) ;
V_108 < ( unsigned char * ) V_112 + V_145 ;
V_108 += sizeof( V_122 ) )
{
if ( * V_108 == V_117 ) V_106 = 1 ;
if ( * V_108 == V_120 ) V_107 = 1 ;
}
F_9 ( V_112 ) ;
if ( ! V_106 || ! V_107 )
{
F_55 ( V_198 , V_199 ) ;
return - 1 ;
}
V_6 -> V_195 = 1 ;
}
}
return ( V_4 ) ;
}
static int F_54 ( T_2 * V_13 , const char * V_41 , int V_42 )
{
int V_4 ;
T_6 * V_6 = ( T_6 * ) V_13 -> V_9 ;
struct V_200 * V_201 = & ( V_6 -> V_202 ) ;
struct V_203 * V_204 = & ( V_6 -> V_131 ) ;
struct V_200 V_205 ;
struct V_148 V_149 [ 1 ] ;
struct V_146 V_147 ;
struct V_150 * V_151 ;
#if F_12 ( V_206 ) && F_12 ( V_207 )
char V_152 [ F_56 ( sizeof( struct V_208 ) ) + F_56 ( sizeof( struct V_209 ) ) ] ;
struct V_208 * V_202 ;
struct V_209 * V_131 ;
#else
char V_152 [ F_56 ( sizeof( struct V_174 ) ) ] ;
struct V_174 * V_175 ;
#endif
F_19 () ;
if ( V_41 [ 0 ] != 23 ) {
memset ( & V_205 , 0x00 , sizeof( struct V_200 ) ) ;
#ifdef F_57
V_205 . V_210 = F_57 ;
#endif
V_201 = & V_205 ;
}
if ( V_6 -> V_211 && ! F_58 ( V_13 ) )
{
V_6 -> V_188 . V_104 = V_13 ;
V_6 -> V_188 . V_189 = V_42 ;
V_6 -> V_188 . V_6 = F_6 ( V_42 ) ;
memcpy ( V_6 -> V_188 . V_6 , V_41 , V_42 ) ;
return V_42 ;
}
V_149 [ 0 ] . V_155 = ( char * ) V_41 ;
V_149 [ 0 ] . V_156 = V_42 ;
V_147 . V_157 = NULL ;
V_147 . V_158 = 0 ;
V_147 . V_159 = V_149 ;
V_147 . V_160 = 1 ;
V_147 . V_161 = ( V_212 ) V_152 ;
V_147 . V_162 = 0 ;
V_147 . V_163 = 0 ;
#if F_12 ( V_206 ) && F_12 ( V_207 )
V_151 = (struct V_150 * ) V_152 ;
V_151 -> V_164 = V_118 ;
V_151 -> V_165 = V_206 ;
V_151 -> V_213 = F_59 ( sizeof( struct V_208 ) ) ;
V_202 = (struct V_208 * ) F_52 ( V_151 ) ;
memset ( V_202 , 0 , sizeof( struct V_208 ) ) ;
V_202 -> V_214 = V_201 -> V_214 ;
V_202 -> V_210 = V_201 -> V_210 ;
V_202 -> V_215 = V_201 -> V_215 ;
V_202 -> V_216 = V_201 -> V_216 ;
V_147 . V_162 += F_56 ( sizeof( struct V_208 ) ) ;
V_151 = (struct V_150 * ) & V_152 [ F_56 ( sizeof( struct V_208 ) ) ] ;
V_151 -> V_164 = V_118 ;
V_151 -> V_165 = V_207 ;
V_151 -> V_213 = F_59 ( sizeof( struct V_209 ) ) ;
V_131 = (struct V_209 * ) F_52 ( V_151 ) ;
memset ( V_131 , 0 , sizeof( struct V_209 ) ) ;
V_131 -> V_132 = V_204 -> V_132 ;
V_131 -> V_217 = V_204 -> V_217 ;
V_147 . V_162 += F_56 ( sizeof( struct V_209 ) ) ;
#else
V_151 = (struct V_150 * ) V_152 ;
V_151 -> V_164 = V_118 ;
V_151 -> V_165 = F_53 ;
V_151 -> V_213 = F_59 ( sizeof( struct V_174 ) ) ;
V_175 = (struct V_174 * ) F_52 ( V_151 ) ;
memset ( V_175 , 0 , sizeof( struct V_174 ) ) ;
V_175 -> V_176 = V_201 -> V_214 ;
V_175 -> V_178 = V_201 -> V_210 ;
#ifdef F_60
V_175 -> V_178 |= V_204 -> V_132 ;
#endif
V_175 -> V_179 = V_201 -> V_215 ;
V_175 -> V_182 = V_201 -> V_216 ;
V_175 -> V_218 = V_204 -> V_217 ;
V_147 . V_162 += F_56 ( sizeof( struct V_174 ) ) ;
#endif
V_4 = F_61 ( V_13 -> V_8 , & V_147 , 0 ) ;
F_23 ( V_13 ) ;
if ( V_4 <= 0 )
{
if ( F_24 ( V_4 ) )
{
F_30 ( V_13 ) ;
V_6 -> V_40 = F_26 () ;
}
}
return ( V_4 ) ;
}
static long F_62 ( T_2 * V_13 , int V_49 , long V_8 , void * V_9 )
{
long V_4 = 1 ;
T_6 * V_6 = NULL ;
unsigned int V_55 = 0 ;
struct V_140 V_141 ;
struct V_219 * V_220 ;
V_6 = ( T_6 * ) V_13 -> V_9 ;
switch ( V_49 )
{
case V_79 :
V_6 -> V_80 = 16384 ;
V_4 = V_6 -> V_80 ;
break;
case V_85 :
V_6 -> V_80 = 16384 ;
V_4 = V_6 -> V_80 ;
break;
case V_86 :
case V_72 :
V_4 = - 1 ;
break;
case V_88 :
break;
case V_221 :
if ( V_8 > 0 )
V_6 -> V_222 = 1 ;
else
V_6 -> V_222 = 0 ;
V_4 = F_16 ( V_13 -> V_8 , V_118 , V_223 , & V_6 -> V_222 , sizeof( int ) ) ;
break;
case V_224 :
V_55 = sizeof( struct V_140 ) ;
V_4 = F_14 ( V_13 -> V_8 , V_118 , V_225 , & V_141 , & V_55 ) ;
if ( V_4 < 0 ) break;
V_55 = sizeof( struct V_219 ) + 64 * sizeof( V_122 ) ;
V_220 = F_6 ( V_55 ) ;
memset ( V_220 , 0x00 , V_55 ) ;
V_220 -> V_226 = V_141 . V_142 + 1 ;
#ifndef F_60
V_220 -> V_227 = 64 ;
#endif
memcpy ( & V_220 -> V_228 [ 0 ] , V_9 , 64 * sizeof( V_122 ) ) ;
V_4 = F_16 ( V_13 -> V_8 , V_118 , V_229 , V_220 , V_55 ) ;
if ( V_4 < 0 ) break;
V_4 = F_16 ( V_13 -> V_8 , V_118 , V_225 ,
& V_141 , sizeof( struct V_140 ) ) ;
if ( V_4 < 0 ) break;
break;
case V_230 :
V_55 = sizeof( struct V_140 ) ;
V_4 = F_14 ( V_13 -> V_8 , V_118 , V_225 , & V_141 , & V_55 ) ;
if ( V_4 < 0 ) break;
V_141 . V_142 = V_141 . V_142 + 1 ;
V_4 = F_16 ( V_13 -> V_8 , V_118 , V_225 ,
& V_141 , sizeof( struct V_140 ) ) ;
if ( V_4 < 0 ) break;
V_6 -> V_231 = 1 ;
case V_232 :
if ( V_49 == V_232 )
V_6 -> V_233 = 1 ;
if ( V_6 -> V_233 == 1 && V_6 -> V_231 == 1 )
{
V_55 = sizeof( struct V_140 ) ;
V_4 = F_14 ( V_13 -> V_8 , V_118 , V_225 , & V_141 , & V_55 ) ;
if ( V_4 < 0 ) break;
V_141 . V_142 = V_141 . V_142 - 1 ;
#ifdef F_63
V_55 = sizeof( struct V_140 ) ;
V_4 = F_16 ( V_13 -> V_8 , V_118 , F_63 ,
& V_141 , V_55 ) ;
if ( V_4 < 0 ) break;
#endif
#ifndef F_39
if ( V_141 . V_142 > 0 )
{
V_141 . V_142 = V_141 . V_142 - 1 ;
V_4 = F_16 ( V_13 -> V_8 , V_118 , V_144 ,
& V_141 , sizeof( struct V_140 ) ) ;
if ( V_4 < 0 ) break;
}
#endif
V_6 -> V_233 = 0 ;
V_6 -> V_231 = 0 ;
}
break;
case V_234 :
if ( V_8 > ( long ) sizeof( struct V_200 ) )
V_8 = sizeof( struct V_200 ) ;
memcpy ( V_9 , & ( V_6 -> V_202 ) , V_8 ) ;
V_4 = V_8 ;
break;
case V_235 :
if ( V_8 > ( long ) sizeof( struct V_200 ) )
V_8 = sizeof( struct V_200 ) ;
memcpy ( & ( V_6 -> V_202 ) , V_9 , V_8 ) ;
break;
case V_236 :
if ( V_8 > ( long ) sizeof( struct V_154 ) )
V_8 = sizeof( struct V_154 ) ;
memcpy ( V_9 , & V_6 -> V_153 , V_8 ) ;
V_4 = V_8 ;
break;
case V_237 :
if ( V_8 > ( long ) sizeof( struct V_154 ) )
V_8 = sizeof( struct V_154 ) ;
memcpy ( & ( V_6 -> V_153 ) , V_9 , V_8 ) ;
break;
case V_238 :
if ( V_8 > ( long ) sizeof( struct V_203 ) )
V_8 = sizeof( struct V_203 ) ;
memcpy ( V_9 , & ( V_6 -> V_131 ) , V_8 ) ;
V_4 = V_8 ;
break;
case V_239 :
if ( V_8 > ( long ) sizeof( struct V_203 ) )
V_8 = sizeof( struct V_203 ) ;
memcpy ( & ( V_6 -> V_131 ) , V_9 , V_8 ) ;
break;
case V_240 :
if ( V_8 > 0 )
V_6 -> V_211 = 1 ;
else
V_6 -> V_211 = 0 ;
break;
default:
V_4 = F_31 ( V_13 , V_49 , V_8 , V_9 ) ;
break;
}
return ( V_4 ) ;
}
int F_64 ( T_2 * V_13 ,
void (* V_191)( T_2 * V_104 , void * V_241 , void * V_242 ) ,
void * V_241 )
{
T_6 * V_6 = ( T_6 * ) V_13 -> V_9 ;
if ( V_191 != NULL )
{
V_6 -> V_191 = V_191 ;
V_6 -> V_192 = V_241 ;
}
else
return - 1 ;
return 0 ;
}
int F_58 ( T_2 * V_13 )
{
int V_243 = 0 ;
int V_102 , V_244 , V_4 ;
union V_133 V_134 ;
struct V_146 V_147 ;
struct V_148 V_149 ;
#ifdef F_40
struct V_113 V_114 ;
#else
struct V_115 V_114 ;
T_5 V_187 ;
#endif
T_6 * V_6 = ( T_6 * ) V_13 -> V_9 ;
#ifdef F_40
memset ( & V_114 , 0 , sizeof( struct V_113 ) ) ;
V_114 . V_124 = 0 ;
V_114 . V_125 = V_186 ;
V_114 . V_126 = 1 ;
V_4 = F_16 ( V_13 -> V_8 , V_118 , F_40 , & V_114 , sizeof( struct V_113 ) ) ;
#else
V_187 = sizeof( struct V_115 ) ;
V_4 = F_14 ( V_13 -> V_8 , V_118 , V_127 , & V_114 , & V_187 ) ;
if ( V_4 < 0 )
return - 1 ;
V_114 . V_190 = 1 ;
V_4 = F_16 ( V_13 -> V_8 , V_118 , V_127 , & V_114 , sizeof( struct V_115 ) ) ;
#endif
if ( V_4 < 0 )
return - 1 ;
memset ( & V_134 , 0x00 , sizeof( union V_133 ) ) ;
V_149 . V_155 = ( char * ) & V_134 ;
V_149 . V_156 = sizeof( union V_133 ) ;
V_147 . V_157 = NULL ;
V_147 . V_158 = 0 ;
V_147 . V_159 = & V_149 ;
V_147 . V_160 = 1 ;
V_147 . V_161 = NULL ;
V_147 . V_162 = 0 ;
V_147 . V_163 = 0 ;
V_102 = F_48 ( V_13 -> V_8 , & V_147 , V_245 ) ;
if ( V_102 <= 0 )
{
if ( ( V_102 < 0 ) && ( F_26 () != V_98 ) && ( F_26 () != V_246 ) )
return - 1 ;
else
return 0 ;
}
while ( V_147 . V_163 & V_183 )
{
memset ( & V_134 , 0x00 , sizeof( union V_133 ) ) ;
V_149 . V_155 = ( char * ) & V_134 ;
V_149 . V_156 = sizeof( union V_133 ) ;
V_147 . V_157 = NULL ;
V_147 . V_158 = 0 ;
V_147 . V_159 = & V_149 ;
V_147 . V_160 = 1 ;
V_147 . V_161 = NULL ;
V_147 . V_162 = 0 ;
V_147 . V_163 = 0 ;
V_102 = F_48 ( V_13 -> V_8 , & V_147 , 0 ) ;
if ( V_102 <= 0 )
{
if ( ( V_102 < 0 ) && ( F_26 () != V_98 ) && ( F_26 () != V_246 ) )
return - 1 ;
else
return V_243 ;
}
if ( V_134 . V_184 . V_185 == V_186 )
{
V_243 = 1 ;
#ifdef F_40
memset ( & V_114 , 0 , sizeof( struct V_113 ) ) ;
V_114 . V_124 = 0 ;
V_114 . V_125 = V_186 ;
V_114 . V_126 = 0 ;
V_4 = F_16 ( V_13 -> V_8 , V_118 , F_40 , & V_114 , sizeof( struct V_113 ) ) ;
#else
V_187 = ( T_5 ) sizeof( struct V_115 ) ;
V_4 = F_14 ( V_13 -> V_8 , V_118 , V_127 , & V_114 , & V_187 ) ;
if ( V_4 < 0 )
return - 1 ;
V_114 . V_190 = 0 ;
V_4 = F_16 ( V_13 -> V_8 , V_118 , V_127 , & V_114 , sizeof( struct V_115 ) ) ;
#endif
if ( V_4 < 0 )
return - 1 ;
}
#ifdef F_39
if ( V_134 . V_184 . V_185 == F_39 )
F_46 ( V_13 , & V_134 ) ;
#endif
if ( V_6 -> V_191 != NULL )
V_6 -> V_191 ( V_13 , V_6 -> V_192 , ( void * ) & V_134 ) ;
memset ( & V_134 , 0x00 , sizeof( union V_133 ) ) ;
V_149 . V_155 = ( char * ) & V_134 ;
V_149 . V_156 = sizeof( union V_133 ) ;
V_147 . V_157 = NULL ;
V_147 . V_158 = 0 ;
V_147 . V_159 = & V_149 ;
V_147 . V_160 = 1 ;
V_147 . V_161 = NULL ;
V_147 . V_162 = 0 ;
V_147 . V_163 = 0 ;
if ( V_243 )
{
V_244 = F_65 ( V_13 -> V_8 , V_247 , 0 ) ;
F_65 ( V_13 -> V_8 , V_248 , V_249 ) ;
}
V_102 = F_48 ( V_13 -> V_8 , & V_147 , V_245 ) ;
if ( V_243 )
{
F_65 ( V_13 -> V_8 , V_248 , V_244 ) ;
}
if ( V_102 <= 0 )
{
if ( ( V_102 < 0 ) && ( F_26 () != V_98 ) && ( F_26 () != V_246 ) )
return - 1 ;
else
return V_243 ;
}
}
return V_243 ;
}
int F_66 ( T_2 * V_13 )
{
int V_102 , V_244 ;
union V_133 V_134 ;
struct V_146 V_147 ;
struct V_148 V_149 ;
T_6 * V_6 = ( T_6 * ) V_13 -> V_9 ;
do
{
memset ( & V_134 , 0x00 , sizeof( union V_133 ) ) ;
V_149 . V_155 = ( char * ) & V_134 ;
V_149 . V_156 = sizeof( union V_133 ) ;
V_147 . V_157 = NULL ;
V_147 . V_158 = 0 ;
V_147 . V_159 = & V_149 ;
V_147 . V_160 = 1 ;
V_147 . V_161 = NULL ;
V_147 . V_162 = 0 ;
V_147 . V_163 = 0 ;
V_244 = F_65 ( V_13 -> V_8 , V_247 , 0 ) ;
F_65 ( V_13 -> V_8 , V_248 , V_249 ) ;
V_102 = F_48 ( V_13 -> V_8 , & V_147 , V_245 ) ;
F_65 ( V_13 -> V_8 , V_248 , V_244 ) ;
if ( V_102 > 0 && ( V_147 . V_163 & V_183 ) )
{
#ifdef F_39
if ( V_134 . V_184 . V_185 == F_39 )
F_46 ( V_13 , & V_134 ) ;
#endif
memset ( & V_134 , 0x00 , sizeof( union V_133 ) ) ;
V_149 . V_155 = ( char * ) & V_134 ;
V_149 . V_156 = sizeof( union V_133 ) ;
V_147 . V_157 = NULL ;
V_147 . V_158 = 0 ;
V_147 . V_159 = & V_149 ;
V_147 . V_160 = 1 ;
V_147 . V_161 = NULL ;
V_147 . V_162 = 0 ;
V_147 . V_163 = 0 ;
V_102 = F_48 ( V_13 -> V_8 , & V_147 , 0 ) ;
if ( V_6 -> V_191 != NULL )
V_6 -> V_191 ( V_13 , V_6 -> V_192 , ( void * ) & V_134 ) ;
}
} while ( V_102 > 0 && ( V_147 . V_163 & V_183 ) );
if ( V_102 > 0 )
return 1 ;
else
return 0 ;
}
static int F_67 ( T_2 * V_100 , const char * V_101 )
{
int V_102 , V_4 ;
V_102 = strlen ( V_101 ) ;
V_4 = F_54 ( V_100 , V_101 , V_102 ) ;
return ( V_4 ) ;
}
static int F_24 ( int V_28 )
{
int V_250 ;
if ( ( V_28 == 0 ) || ( V_28 == - 1 ) )
{
V_250 = F_26 () ;
#if F_12 ( F_13 )
#endif
return ( F_68 ( V_250 ) ) ;
}
return ( 0 ) ;
}
int F_68 ( int V_250 )
{
switch ( V_250 )
{
#if F_12 ( F_13 )
# if F_12 ( V_251 )
case V_251 :
# endif
# if 0
# if F_12 ( V_252 )
case WSAENOTCONN:
# endif
# endif
#endif
#ifdef V_246
# ifdef V_251
# if V_251 != V_246
case V_246 :
# endif
# else
case V_246 :
# endif
#endif
#ifdef F_69
case F_69 :
#endif
#ifdef V_98
#if V_246 != V_98
case V_98 :
# endif
#endif
#ifdef F_70
case F_70 :
#endif
#ifdef F_71
case F_71 :
#endif
#ifdef F_72
case F_72 :
#endif
return ( 1 ) ;
default:
break;
}
return ( 0 ) ;
}
static void F_15 ( struct V_19 * V_253 )
{
#ifdef F_73
struct V_254 V_255 ;
F_74 ( & V_255 ) ;
V_253 -> V_17 = ( long ) V_255 . time ;
V_253 -> V_18 = ( long ) V_255 . V_256 * 1000 ;
#elif F_12 ( V_257 )
struct V_258 V_255 ;
F_75 ( & V_255 ) ;
V_253 -> V_17 = ( long ) V_255 . time ;
V_253 -> V_18 = ( long ) V_255 . V_256 * 1000 ;
#else
F_76 ( V_253 , NULL ) ;
#endif
}
