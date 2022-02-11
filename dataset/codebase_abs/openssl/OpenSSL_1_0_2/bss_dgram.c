T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
T_2 * F_2 ( int V_2 , int V_3 )
{
T_2 * V_4 ;
V_4 = F_3 ( F_1 () ) ;
if ( V_4 == NULL )
return ( NULL ) ;
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
if ( V_11 == NULL )
return ( 0 ) ;
if ( ! F_8 ( V_11 ) )
return 0 ;
V_6 = ( T_3 * ) V_11 -> V_9 ;
if ( V_6 != NULL )
F_9 ( V_6 ) ;
return ( 1 ) ;
}
static int F_8 ( T_2 * V_11 )
{
if ( V_11 == NULL )
return ( 0 ) ;
if ( V_11 -> V_12 ) {
if ( V_11 -> V_7 ) {
F_10 ( V_11 -> V_8 ) ;
}
V_11 -> V_7 = 0 ;
V_11 -> V_10 = 0 ;
}
return ( 1 ) ;
}
static void F_11 ( T_2 * V_13 )
{
# if F_12 ( V_14 )
T_3 * V_6 = ( T_3 * ) V_13 -> V_9 ;
union {
T_4 V_15 ;
int V_16 ;
} V_17 = {
0
} ;
if ( V_6 -> V_18 . V_19 > 0 || V_6 -> V_18 . V_20 > 0 ) {
struct V_21 V_22 , V_23 ;
# ifdef F_13
int V_24 ;
V_17 . V_16 = sizeof( V_24 ) ;
if ( F_14 ( V_13 -> V_8 , V_25 , V_14 ,
( void * ) & V_24 , & V_17 . V_16 ) < 0 ) {
perror ( L_1 ) ;
} else {
V_6 -> V_26 . V_19 = V_24 / 1000 ;
V_6 -> V_26 . V_20 = ( V_24 % 1000 ) * 1000 ;
}
# else
V_17 . V_16 = sizeof( V_6 -> V_26 ) ;
if ( F_14 ( V_13 -> V_8 , V_25 , V_14 ,
& ( V_6 -> V_26 ) , ( void * ) & V_17 ) < 0 ) {
perror ( L_1 ) ;
} else if ( sizeof( V_17 . V_15 ) != sizeof( V_17 . V_16 ) && V_17 . V_16 == 0 )
F_15 ( V_17 . V_15 <= sizeof( V_6 -> V_26 ) ) ;
# endif
F_16 ( & V_22 ) ;
memcpy ( & V_23 , & ( V_6 -> V_18 ) , sizeof( struct V_21 ) ) ;
V_23 . V_19 -= V_22 . V_19 ;
V_23 . V_20 -= V_22 . V_20 ;
if ( V_23 . V_20 < 0 ) {
V_23 . V_19 -- ;
V_23 . V_20 += 1000000 ;
}
if ( V_23 . V_19 < 0 ) {
V_23 . V_19 = 0 ;
V_23 . V_20 = 1 ;
}
if ( ( V_6 -> V_26 . V_19 == 0
&& V_6 -> V_26 . V_20 == 0 )
|| ( V_6 -> V_26 . V_19 > V_23 . V_19 )
|| ( V_6 -> V_26 . V_19 == V_23 . V_19
&& V_6 -> V_26 . V_20 >= V_23 . V_20 ) ) {
# ifdef F_13
V_24 = V_23 . V_19 * 1000 + V_23 . V_20 / 1000 ;
if ( F_17 ( V_13 -> V_8 , V_25 , V_14 ,
( void * ) & V_24 , sizeof( V_24 ) ) < 0 ) {
perror ( L_2 ) ;
}
# else
if ( F_17 ( V_13 -> V_8 , V_25 , V_14 , & V_23 ,
sizeof( struct V_21 ) ) < 0 ) {
perror ( L_2 ) ;
}
# endif
}
}
# endif
}
static void F_18 ( T_2 * V_13 )
{
# if F_12 ( V_14 )
T_3 * V_6 = ( T_3 * ) V_13 -> V_9 ;
if ( V_6 -> V_18 . V_19 > 0 || V_6 -> V_18 . V_20 > 0 ) {
# ifdef F_13
int V_24 = V_6 -> V_26 . V_19 * 1000 +
V_6 -> V_26 . V_20 / 1000 ;
if ( F_17 ( V_13 -> V_8 , V_25 , V_14 ,
( void * ) & V_24 , sizeof( V_24 ) ) < 0 ) {
perror ( L_2 ) ;
}
# else
if ( F_17
( V_13 -> V_8 , V_25 , V_14 , & ( V_6 -> V_26 ) ,
sizeof( struct V_21 ) ) < 0 ) {
perror ( L_2 ) ;
}
# endif
}
# endif
}
static int F_19 ( T_2 * V_13 , char * V_27 , int V_28 )
{
int V_4 = 0 ;
T_3 * V_6 = ( T_3 * ) V_13 -> V_9 ;
struct {
union {
T_4 V_15 ;
int V_16 ;
} V_29 ;
union {
struct V_30 V_31 ;
struct V_32 V_33 ;
# if V_34
struct V_35 V_36 ;
# endif
} V_37 ;
} V_31 ;
V_31 . V_29 . V_15 = 0 ;
V_31 . V_29 . V_16 = sizeof( V_31 . V_37 ) ;
if ( V_27 != NULL ) {
F_20 () ;
memset ( & V_31 . V_37 , 0x00 , sizeof( V_31 . V_37 ) ) ;
F_11 ( V_13 ) ;
V_4 = F_21 ( V_13 -> V_8 , V_27 , V_28 , 0 , & V_31 . V_37 . V_31 , ( void * ) & V_31 . V_29 ) ;
if ( sizeof( V_31 . V_29 . V_16 ) != sizeof( V_31 . V_29 . V_15 ) && V_31 . V_29 . V_16 == 0 ) {
F_15 ( V_31 . V_29 . V_15 <= sizeof( V_31 . V_37 ) ) ;
V_31 . V_29 . V_16 = ( int ) V_31 . V_29 . V_15 ;
}
if ( ! V_6 -> V_38 && V_4 >= 0 )
F_22 ( V_13 , V_39 , 0 , & V_31 . V_37 ) ;
F_23 ( V_13 ) ;
if ( V_4 < 0 ) {
if ( F_24 ( V_4 ) ) {
F_25 ( V_13 ) ;
V_6 -> V_40 = F_26 () ;
}
}
F_18 ( V_13 ) ;
}
return ( V_4 ) ;
}
static int F_27 ( T_2 * V_13 , const char * V_41 , int V_42 )
{
int V_4 ;
T_3 * V_6 = ( T_3 * ) V_13 -> V_9 ;
F_20 () ;
if ( V_6 -> V_38 )
V_4 = F_28 ( V_13 -> V_8 , V_41 , V_42 ) ;
else {
int V_43 = sizeof( V_6 -> V_37 ) ;
if ( V_6 -> V_37 . V_31 . V_44 == V_45 )
V_43 = sizeof( V_6 -> V_37 . V_33 ) ;
# if V_34
else if ( V_6 -> V_37 . V_31 . V_44 == V_46 )
V_43 = sizeof( V_6 -> V_37 . V_36 ) ;
# endif
# if F_12 ( V_47 ) && F_12 ( V_48 )
V_4 = F_29 ( V_13 -> V_8 , ( char * ) V_41 , V_42 , 0 , & V_6 -> V_37 . V_31 , V_43 ) ;
# else
V_4 = F_29 ( V_13 -> V_8 , V_41 , V_42 , 0 , & V_6 -> V_37 . V_31 , V_43 ) ;
# endif
}
F_23 ( V_13 ) ;
if ( V_4 <= 0 ) {
if ( F_24 ( V_4 ) ) {
F_30 ( V_13 ) ;
V_6 -> V_40 = F_26 () ;
# if 0
if (data->_errno == EMSGSIZE)
BIO_ctrl(b, BIO_CTRL_DGRAM_QUERY_MTU, 0, NULL);
# endif
}
}
return ( V_4 ) ;
}
static long F_31 ( T_3 * V_6 )
{
long V_4 ;
switch ( V_6 -> V_37 . V_31 . V_44 ) {
case V_45 :
V_4 = 28 ;
break;
# if V_34
case V_46 :
# ifdef F_32
if ( F_32 ( & V_6 -> V_37 . V_36 . V_49 ) )
V_4 = 28 ;
else
# endif
V_4 = 48 ;
break;
# endif
default:
V_4 = 28 ;
break;
}
return V_4 ;
}
static long F_33 ( T_2 * V_13 , int V_50 , long V_8 , void * V_9 )
{
long V_4 = 1 ;
int * V_51 ;
struct V_30 * V_52 = NULL ;
T_3 * V_6 = NULL ;
int V_53 = 0 ;
# if F_12 ( V_54 ) && ( F_12 ( V_55 ) || F_12 ( V_56 ) )
T_5 V_57 ;
T_5 V_58 ;
union {
struct V_30 V_31 ;
struct V_32 V_59 ;
# if V_34
struct V_35 V_60 ;
# endif
} V_61 ;
# endif
V_6 = ( T_3 * ) V_13 -> V_9 ;
switch ( V_50 ) {
case V_62 :
V_8 = 0 ;
case V_63 :
V_4 = 0 ;
break;
case V_64 :
case V_65 :
V_4 = 0 ;
break;
case V_66 :
F_8 ( V_13 ) ;
V_13 -> V_8 = * ( ( int * ) V_9 ) ;
V_13 -> V_12 = ( int ) V_8 ;
V_13 -> V_7 = 1 ;
break;
case V_67 :
if ( V_13 -> V_7 ) {
V_51 = ( int * ) V_9 ;
if ( V_51 != NULL )
* V_51 = V_13 -> V_8 ;
V_4 = V_13 -> V_8 ;
} else
V_4 = - 1 ;
break;
case V_68 :
V_4 = V_13 -> V_12 ;
break;
case V_69 :
V_13 -> V_12 = ( int ) V_8 ;
break;
case V_70 :
case V_71 :
V_4 = 0 ;
break;
case V_72 :
case V_73 :
V_4 = 1 ;
break;
case V_74 :
V_52 = (struct V_30 * ) V_9 ;
# if 0
if (connect(b->num, to, sizeof(struct sockaddr)) < 0) {
perror("connect");
ret = 0;
} else {
# endif
switch ( V_52 -> V_44 ) {
case V_45 :
memcpy ( & V_6 -> V_37 , V_52 , sizeof( V_6 -> V_37 . V_33 ) ) ;
break;
# if V_34
case V_46 :
memcpy ( & V_6 -> V_37 , V_52 , sizeof( V_6 -> V_37 . V_36 ) ) ;
break;
# endif
default:
memcpy ( & V_6 -> V_37 , V_52 , sizeof( V_6 -> V_37 . V_31 ) ) ;
break;
}
# if 0
}
# endif
break;
case V_75 :
# if F_12 ( V_54 ) && F_12 ( V_55 ) && F_12 ( V_76 )
V_58 = ( T_5 ) sizeof( V_61 ) ;
memset ( ( void * ) & V_61 , 0 , sizeof( V_61 ) ) ;
if ( F_34 ( V_13 -> V_8 , & V_61 . V_31 , & V_58 ) < 0 ) {
V_4 = 0 ;
break;
}
switch ( V_61 . V_31 . V_44 ) {
case V_45 :
V_53 = V_76 ;
if ( ( V_4 = F_17 ( V_13 -> V_8 , V_77 , V_55 ,
& V_53 , sizeof( V_53 ) ) ) < 0 )
perror ( L_2 ) ;
break;
# if V_34 && F_12 ( V_78 ) && F_12 ( V_79 )
case V_46 :
V_53 = V_79 ;
if ( ( V_4 = F_17 ( V_13 -> V_8 , V_80 , V_78 ,
& V_53 , sizeof( V_53 ) ) ) < 0 )
perror ( L_2 ) ;
break;
# endif
default:
V_4 = - 1 ;
break;
}
V_4 = - 1 ;
# else
break;
# endif
case V_81 :
# if F_12 ( V_54 ) && F_12 ( V_56 )
V_58 = ( T_5 ) sizeof( V_61 ) ;
memset ( ( void * ) & V_61 , 0 , sizeof( V_61 ) ) ;
if ( F_34 ( V_13 -> V_8 , & V_61 . V_31 , & V_58 ) < 0 ) {
V_4 = 0 ;
break;
}
V_57 = sizeof( V_53 ) ;
switch ( V_61 . V_31 . V_44 ) {
case V_45 :
if ( ( V_4 =
F_14 ( V_13 -> V_8 , V_77 , V_56 , ( void * ) & V_53 ,
& V_57 ) ) < 0 || V_53 < 0 ) {
V_4 = 0 ;
} else {
V_6 -> V_82 = V_53 - 8 - 20 ;
V_4 = V_6 -> V_82 ;
}
break;
# if V_34 && F_12 ( V_83 )
case V_46 :
if ( ( V_4 =
F_14 ( V_13 -> V_8 , V_80 , V_83 ,
( void * ) & V_53 , & V_57 ) ) < 0
|| V_53 < 0 ) {
V_4 = 0 ;
} else {
V_6 -> V_82 = V_53 - 8 - 40 ;
V_4 = V_6 -> V_82 ;
}
break;
# endif
default:
V_4 = 0 ;
break;
}
# else
V_4 = 0 ;
# endif
break;
case V_84 :
V_4 = - F_31 ( V_6 ) ;
switch ( V_6 -> V_37 . V_31 . V_44 ) {
case V_45 :
V_4 += 576 ;
break;
# if V_34
case V_46 :
# ifdef F_32
if ( F_32 ( & V_6 -> V_37 . V_36 . V_49 ) )
V_4 += 576 ;
else
# endif
V_4 += 1280 ;
break;
# endif
default:
V_4 += 576 ;
break;
}
break;
case V_85 :
return V_6 -> V_82 ;
break;
case V_86 :
V_6 -> V_82 = V_8 ;
V_4 = V_8 ;
break;
case V_87 :
V_52 = (struct V_30 * ) V_9 ;
if ( V_52 != NULL ) {
V_6 -> V_38 = 1 ;
switch ( V_52 -> V_44 ) {
case V_45 :
memcpy ( & V_6 -> V_37 , V_52 , sizeof( V_6 -> V_37 . V_33 ) ) ;
break;
# if V_34
case V_46 :
memcpy ( & V_6 -> V_37 , V_52 , sizeof( V_6 -> V_37 . V_36 ) ) ;
break;
# endif
default:
memcpy ( & V_6 -> V_37 , V_52 , sizeof( V_6 -> V_37 . V_31 ) ) ;
break;
}
} else {
V_6 -> V_38 = 0 ;
memset ( & ( V_6 -> V_37 ) , 0x00 , sizeof( V_6 -> V_37 ) ) ;
}
break;
case V_88 :
switch ( V_6 -> V_37 . V_31 . V_44 ) {
case V_45 :
V_4 = sizeof( V_6 -> V_37 . V_33 ) ;
break;
# if V_34
case V_46 :
V_4 = sizeof( V_6 -> V_37 . V_36 ) ;
break;
# endif
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
switch ( V_52 -> V_44 ) {
case V_45 :
memcpy ( & V_6 -> V_37 , V_52 , sizeof( V_6 -> V_37 . V_33 ) ) ;
break;
# if V_34
case V_46 :
memcpy ( & V_6 -> V_37 , V_52 , sizeof( V_6 -> V_37 . V_36 ) ) ;
break;
# endif
default:
memcpy ( & V_6 -> V_37 , V_52 , sizeof( V_6 -> V_37 . V_31 ) ) ;
break;
}
break;
case V_89 :
memcpy ( & ( V_6 -> V_18 ) , V_9 , sizeof( struct V_21 ) ) ;
break;
# if F_12 ( V_14 )
case V_90 :
# ifdef F_13
{
struct V_21 * V_91 = (struct V_21 * ) V_9 ;
int V_24 = V_91 -> V_19 * 1000 + V_91 -> V_20 / 1000 ;
if ( F_17 ( V_13 -> V_8 , V_25 , V_14 ,
( void * ) & V_24 , sizeof( V_24 ) ) < 0 ) {
perror ( L_2 ) ;
V_4 = - 1 ;
}
}
# else
if ( F_17 ( V_13 -> V_8 , V_25 , V_14 , V_9 ,
sizeof( struct V_21 ) ) < 0 ) {
perror ( L_2 ) ;
V_4 = - 1 ;
}
# endif
break;
case V_92 :
{
union {
T_4 V_15 ;
int V_16 ;
} V_17 = {
0
} ;
# ifdef F_13
int V_24 ;
struct V_21 * V_91 = (struct V_21 * ) V_9 ;
V_17 . V_16 = sizeof( V_24 ) ;
if ( F_14 ( V_13 -> V_8 , V_25 , V_14 ,
( void * ) & V_24 , & V_17 . V_16 ) < 0 ) {
perror ( L_1 ) ;
V_4 = - 1 ;
} else {
V_91 -> V_19 = V_24 / 1000 ;
V_91 -> V_20 = ( V_24 % 1000 ) * 1000 ;
V_4 = sizeof( * V_91 ) ;
}
# else
V_17 . V_16 = sizeof( struct V_21 ) ;
if ( F_14 ( V_13 -> V_8 , V_25 , V_14 ,
V_9 , ( void * ) & V_17 ) < 0 ) {
perror ( L_1 ) ;
V_4 = - 1 ;
} else if ( sizeof( V_17 . V_15 ) != sizeof( V_17 . V_16 ) && V_17 . V_16 == 0 ) {
F_15 ( V_17 . V_15 <= sizeof( struct V_21 ) ) ;
V_4 = ( int ) V_17 . V_15 ;
} else
V_4 = V_17 . V_16 ;
# endif
}
break;
# endif
# if F_12 ( V_93 )
case V_94 :
# ifdef F_13
{
struct V_21 * V_91 = (struct V_21 * ) V_9 ;
int V_24 = V_91 -> V_19 * 1000 + V_91 -> V_20 / 1000 ;
if ( F_17 ( V_13 -> V_8 , V_25 , V_93 ,
( void * ) & V_24 , sizeof( V_24 ) ) < 0 ) {
perror ( L_2 ) ;
V_4 = - 1 ;
}
}
# else
if ( F_17 ( V_13 -> V_8 , V_25 , V_93 , V_9 ,
sizeof( struct V_21 ) ) < 0 ) {
perror ( L_2 ) ;
V_4 = - 1 ;
}
# endif
break;
case V_95 :
{
union {
T_4 V_15 ;
int V_16 ;
} V_17 = {
0
} ;
# ifdef F_13
int V_24 ;
struct V_21 * V_91 = (struct V_21 * ) V_9 ;
V_17 . V_16 = sizeof( V_24 ) ;
if ( F_14 ( V_13 -> V_8 , V_25 , V_93 ,
( void * ) & V_24 , & V_17 . V_16 ) < 0 ) {
perror ( L_1 ) ;
V_4 = - 1 ;
} else {
V_91 -> V_19 = V_24 / 1000 ;
V_91 -> V_20 = ( V_24 % 1000 ) * 1000 ;
V_4 = sizeof( * V_91 ) ;
}
# else
V_17 . V_16 = sizeof( struct V_21 ) ;
if ( F_14 ( V_13 -> V_8 , V_25 , V_93 ,
V_9 , ( void * ) & V_17 ) < 0 ) {
perror ( L_1 ) ;
V_4 = - 1 ;
} else if ( sizeof( V_17 . V_15 ) != sizeof( V_17 . V_16 ) && V_17 . V_16 == 0 ) {
F_15 ( V_17 . V_15 <= sizeof( struct V_21 ) ) ;
V_4 = ( int ) V_17 . V_15 ;
} else
V_4 = V_17 . V_16 ;
# endif
}
break;
# endif
case V_96 :
case V_97 :
# ifdef F_13
if ( V_6 -> V_40 == V_98 )
# else
if ( V_6 -> V_40 == V_99 )
# endif
{
V_4 = 1 ;
V_6 -> V_40 = 0 ;
} else
V_4 = 0 ;
break;
# ifdef F_35
case V_100 :
if ( V_6 -> V_40 == F_35 ) {
V_4 = 1 ;
V_6 -> V_40 = 0 ;
} else
V_4 = 0 ;
break;
# endif
case V_101 :
V_53 = V_8 ? 1 : 0 ;
switch ( V_6 -> V_37 . V_31 . V_44 ) {
case V_45 :
# if F_12 ( V_102 )
if ( ( V_4 = F_17 ( V_13 -> V_8 , V_77 , V_102 ,
& V_53 , sizeof( V_53 ) ) ) < 0 ) {
perror ( L_2 ) ;
V_4 = - 1 ;
}
# elif F_12 ( V_54 ) && F_12 ( V_103 )
if ( ( V_53 = V_8 ? V_104 : V_105 ) ,
( V_4 = F_17 ( V_13 -> V_8 , V_77 , V_55 ,
& V_53 , sizeof( V_53 ) ) ) < 0 ) {
perror ( L_2 ) ;
V_4 = - 1 ;
}
# elif F_12 ( F_13 ) && F_12 ( V_106 )
if ( ( V_4 = F_17 ( V_13 -> V_8 , V_77 , V_106 ,
( const char * ) & V_53 ,
sizeof( V_53 ) ) ) < 0 ) {
perror ( L_2 ) ;
V_4 = - 1 ;
}
# else
V_4 = - 1 ;
# endif
break;
# if V_34
case V_46 :
# if F_12 ( V_107 )
if ( ( V_4 = F_17 ( V_13 -> V_8 , V_80 , V_107 ,
( const void * ) & V_53 ,
sizeof( V_53 ) ) ) < 0 ) {
perror ( L_2 ) ;
V_4 = - 1 ;
}
# elif F_12 ( V_54 ) && F_12 ( V_108 )
if ( ( V_53 = V_8 ? V_104 : V_105 ) ,
( V_4 = F_17 ( V_13 -> V_8 , V_80 , V_78 ,
& V_53 , sizeof( V_53 ) ) ) < 0 ) {
perror ( L_2 ) ;
V_4 = - 1 ;
}
# else
V_4 = - 1 ;
# endif
break;
# endif
default:
V_4 = - 1 ;
break;
}
break;
case V_109 :
V_4 = F_31 ( V_6 ) ;
break;
default:
V_4 = 0 ;
break;
}
return ( V_4 ) ;
}
static int F_36 ( T_2 * V_110 , const char * V_111 )
{
int V_112 , V_4 ;
V_112 = strlen ( V_111 ) ;
V_4 = F_27 ( V_110 , V_111 , V_112 ) ;
return ( V_4 ) ;
}
T_1 * F_37 ( void )
{
return ( & V_113 ) ;
}
T_2 * F_38 ( int V_2 , int V_3 )
{
T_2 * V_114 ;
int V_4 , V_115 = 20000 ;
int V_116 = 0 , V_117 = 0 ;
unsigned char * V_118 ;
struct V_119 V_120 ;
struct V_121 * V_122 ;
T_5 V_57 ;
# ifdef F_39
# ifdef F_40
struct V_123 V_124 ;
# else
struct V_125 V_124 ;
# endif
# endif
V_114 = F_3 ( F_37 () ) ;
if ( V_114 == NULL )
return ( NULL ) ;
F_4 ( V_114 , V_2 , V_3 ) ;
V_120 . V_126 = V_127 ;
V_4 =
F_17 ( V_2 , V_128 , V_129 , & V_120 ,
sizeof( struct V_119 ) ) ;
if ( V_4 < 0 ) {
F_41 ( V_114 ) ;
return ( NULL ) ;
}
V_120 . V_126 = V_130 ;
V_4 =
F_17 ( V_2 , V_128 , V_129 , & V_120 ,
sizeof( struct V_119 ) ) ;
if ( V_4 < 0 ) {
F_41 ( V_114 ) ;
return ( NULL ) ;
}
V_57 = ( T_5 ) ( sizeof( V_131 ) + 256 * sizeof( V_132 ) ) ;
V_122 = F_6 ( V_57 ) ;
memset ( V_122 , 0 , sizeof( V_57 ) ) ;
V_4 =
F_14 ( V_2 , V_128 , V_133 , V_122 ,
& V_57 ) ;
if ( V_4 < 0 ) {
F_9 ( V_122 ) ;
F_41 ( V_114 ) ;
return ( NULL ) ;
}
for ( V_118 = ( unsigned char * ) V_122 -> V_134 ;
V_118 < ( unsigned char * ) V_122 + V_57 ;
V_118 += sizeof( V_132 ) ) {
if ( * V_118 == V_127 )
V_116 = 1 ;
if ( * V_118 == V_130 )
V_117 = 1 ;
}
F_9 ( V_122 ) ;
F_15 ( V_116 ) ;
F_15 ( V_117 ) ;
# ifdef F_39
# ifdef F_40
memset ( & V_124 , 0 , sizeof( struct V_123 ) ) ;
V_124 . V_135 = 0 ;
V_124 . V_136 = F_39 ;
V_124 . V_137 = 1 ;
V_4 =
F_17 ( V_2 , V_128 , F_40 , & V_124 ,
sizeof( struct V_123 ) ) ;
if ( V_4 < 0 ) {
F_41 ( V_114 ) ;
return ( NULL ) ;
}
# else
V_57 = ( T_5 ) sizeof( struct V_125 ) ;
V_4 = F_14 ( V_2 , V_128 , V_138 , & V_124 , & V_57 ) ;
if ( V_4 < 0 ) {
F_41 ( V_114 ) ;
return ( NULL ) ;
}
V_124 . V_139 = 1 ;
V_4 =
F_17 ( V_2 , V_128 , V_138 , & V_124 ,
sizeof( struct V_125 ) ) ;
if ( V_4 < 0 ) {
F_41 ( V_114 ) ;
return ( NULL ) ;
}
# endif
# endif
V_4 =
F_17 ( V_2 , V_128 , V_140 , & V_115 ,
sizeof( V_115 ) ) ;
if ( V_4 < 0 ) {
F_41 ( V_114 ) ;
return ( NULL ) ;
}
return ( V_114 ) ;
}
int F_42 ( T_2 * V_114 )
{
return ( F_43 ( V_114 ) == V_141 ) ;
}
static int F_44 ( T_2 * V_5 )
{
T_6 * V_6 = NULL ;
V_5 -> V_7 = 0 ;
V_5 -> V_8 = 0 ;
V_6 = F_6 ( sizeof( T_6 ) ) ;
if ( V_6 == NULL )
return 0 ;
memset ( V_6 , 0x00 , sizeof( T_6 ) ) ;
# ifdef F_45
V_6 -> V_142 . V_143 = F_45 ;
# endif
V_5 -> V_9 = V_6 ;
V_5 -> V_10 = 0 ;
return ( 1 ) ;
}
static int F_46 ( T_2 * V_11 )
{
T_6 * V_6 ;
if ( V_11 == NULL )
return ( 0 ) ;
if ( ! F_8 ( V_11 ) )
return 0 ;
V_6 = ( T_6 * ) V_11 -> V_9 ;
if ( V_6 != NULL ) {
if ( V_6 -> V_144 . V_6 != NULL )
F_9 ( V_6 -> V_144 . V_6 ) ;
F_9 ( V_6 ) ;
}
return ( 1 ) ;
}
void F_47 ( T_2 * V_13 ,
union V_145 * V_146 )
{
int V_4 ;
struct V_147 * V_148 = & V_146 -> V_149 ;
if ( V_148 -> V_150 == V_151 ) {
struct V_152 V_153 ;
V_153 . V_154 = V_148 -> V_155 ;
V_4 = F_17 ( V_13 -> V_8 , V_128 , V_156 ,
& V_153 , sizeof( struct V_152 ) ) ;
}
}
static int F_48 ( T_2 * V_13 , char * V_27 , int V_28 )
{
int V_4 = 0 , V_112 = 0 , V_16 , V_115 ;
T_5 V_157 ;
T_6 * V_6 = ( T_6 * ) V_13 -> V_9 ;
union V_145 * V_146 ;
struct V_158 V_159 ;
struct V_160 V_161 ;
struct V_162 * V_163 ;
char V_164 [ 512 ] ;
if ( V_27 != NULL ) {
F_20 () ;
do {
memset ( & V_6 -> V_165 , 0x00 ,
sizeof( struct V_166 ) ) ;
V_161 . V_167 = V_27 ;
V_161 . V_168 = V_28 ;
V_159 . V_169 = NULL ;
V_159 . V_170 = 0 ;
V_159 . V_171 = & V_161 ;
V_159 . V_172 = 1 ;
V_159 . V_173 = V_164 ;
V_159 . V_174 = 512 ;
V_159 . V_175 = 0 ;
V_112 = F_49 ( V_13 -> V_8 , & V_159 , 0 ) ;
if ( V_112 <= 0 ) {
if ( V_112 < 0 )
V_4 = V_112 ;
break;
}
if ( V_159 . V_174 > 0 ) {
for ( V_163 = F_50 ( & V_159 ) ; V_163 ;
V_163 = F_51 ( & V_159 , V_163 ) ) {
if ( V_163 -> V_176 != V_128 )
continue;
# ifdef F_52
if ( V_163 -> V_177 == F_52 ) {
struct V_178 * V_165 ;
V_165 = (struct V_178 * ) F_53 ( V_163 ) ;
V_6 -> V_165 . V_179 = V_165 -> V_179 ;
V_6 -> V_165 . V_180 = V_165 -> V_180 ;
V_6 -> V_165 . V_181 = V_165 -> V_181 ;
V_6 -> V_165 . V_182 = V_165 -> V_182 ;
V_6 -> V_165 . V_183 = V_165 -> V_183 ;
V_6 -> V_165 . V_184 = V_165 -> V_184 ;
V_6 -> V_165 . V_185 = V_165 -> V_185 ;
}
# endif
# ifdef F_54
if ( V_163 -> V_177 == F_54 ) {
struct V_186 * V_187 ;
V_187 =
(struct V_186 * ) F_53 ( V_163 ) ;
V_6 -> V_165 . V_179 = V_187 -> V_188 ;
V_6 -> V_165 . V_180 = V_187 -> V_189 ;
V_6 -> V_165 . V_181 = V_187 -> V_190 ;
V_6 -> V_165 . V_182 = V_187 -> V_191 ;
V_6 -> V_165 . V_183 = V_187 -> V_192 ;
V_6 -> V_165 . V_184 = V_187 -> V_193 ;
V_6 -> V_165 . V_185 = V_187 -> V_194 ;
}
# endif
}
}
if ( V_159 . V_175 & V_195 ) {
V_146 = (union V_145 * ) V_27 ;
if ( V_146 -> V_196 . V_197 == V_198 ) {
# ifdef F_40
struct V_123 V_124 ;
# else
struct V_125 V_124 ;
T_5 V_199 ;
# endif
if ( V_6 -> V_144 . V_200 > 0 ) {
F_55 ( V_6 -> V_144 . V_114 ,
V_6 -> V_144 . V_6 ,
V_6 -> V_144 . V_200 ) ;
F_9 ( V_6 -> V_144 . V_6 ) ;
V_6 -> V_144 . V_6 = NULL ;
V_6 -> V_144 . V_200 = 0 ;
}
# ifdef F_40
memset ( & V_124 , 0 , sizeof( struct V_123 ) ) ;
V_124 . V_135 = 0 ;
V_124 . V_136 = V_198 ;
V_124 . V_137 = 0 ;
V_16 = F_17 ( V_13 -> V_8 , V_128 , F_40 , & V_124 ,
sizeof( struct V_123 ) ) ;
if ( V_16 < 0 ) {
V_4 = V_16 ;
break;
}
# else
V_199 = sizeof( struct V_125 ) ;
V_16 = F_14 ( V_13 -> V_8 , V_128 , V_138 , & V_124 ,
& V_199 ) ;
if ( V_16 < 0 ) {
V_4 = V_16 ;
break;
}
V_124 . V_201 = 0 ;
V_16 = F_17 ( V_13 -> V_8 , V_128 , V_138 , & V_124 ,
sizeof( struct V_125 ) ) ;
if ( V_16 < 0 ) {
V_4 = V_16 ;
break;
}
# endif
}
# ifdef F_39
if ( V_146 -> V_196 . V_197 == F_39 )
F_47 ( V_13 , V_146 ) ;
# endif
if ( V_6 -> V_202 != NULL )
V_6 -> V_202 ( V_13 , V_6 -> V_203 ,
( void * ) V_27 ) ;
memset ( V_27 , 0 , V_28 ) ;
} else
V_4 += V_112 ;
}
while ( ( V_159 . V_175 & V_195 ) && ( V_159 . V_175 & V_204 )
&& ( V_4 < V_28 ) );
if ( V_4 > 0 && ! ( V_159 . V_175 & V_204 ) ) {
if ( V_4 == V_28 )
return - 1 ;
V_157 = ( T_5 ) sizeof( int ) ;
V_4 = F_14 ( V_13 -> V_8 , V_25 , V_205 , & V_115 , & V_157 ) ;
if ( V_4 >= 0 )
F_15 ( V_115 >= 18445 ) ;
V_157 = ( T_5 ) sizeof( int ) ;
V_4 =
F_14 ( V_13 -> V_8 , V_128 , V_140 ,
& V_115 , & V_157 ) ;
if ( V_4 >= 0 )
F_15 ( V_115 >= 18445 ) ;
F_15 ( ! ( V_159 . V_175 & V_195 ) ) ;
memset ( V_27 , 0 , V_28 ) ;
F_25 ( V_13 ) ;
return - 1 ;
}
F_23 ( V_13 ) ;
if ( V_4 < 0 ) {
if ( F_24 ( V_4 ) ) {
F_25 ( V_13 ) ;
V_6 -> V_40 = F_26 () ;
}
}
if ( ! V_6 -> V_206 ) {
int V_207 , V_116 = 0 , V_117 = 0 ;
unsigned char * V_118 ;
struct V_121 * V_122 ;
V_157 =
( T_5 ) ( sizeof( V_131 ) + 256 * sizeof( V_132 ) ) ;
V_122 = F_6 ( V_157 ) ;
memset ( V_122 , 0 , sizeof( V_157 ) ) ;
V_207 = F_14 ( V_13 -> V_8 , V_128 , V_208 ,
V_122 , & V_157 ) ;
if ( V_207 >= 0 )
for ( V_118 = ( unsigned char * ) V_122 -> V_134 ;
V_118 < ( unsigned char * ) V_122 + V_157 ;
V_118 += sizeof( V_132 ) ) {
if ( * V_118 == V_127 )
V_116 = 1 ;
if ( * V_118 == V_130 )
V_117 = 1 ;
}
F_9 ( V_122 ) ;
if ( ! V_116 || ! V_117 ) {
F_56 ( V_209 , V_210 ) ;
return - 1 ;
}
V_6 -> V_206 = 1 ;
}
}
return ( V_4 ) ;
}
static int F_55 ( T_2 * V_13 , const char * V_41 , int V_42 )
{
int V_4 ;
T_6 * V_6 = ( T_6 * ) V_13 -> V_9 ;
struct V_211 * V_212 = & ( V_6 -> V_213 ) ;
struct V_214 * V_215 = & ( V_6 -> V_142 ) ;
struct V_211 V_216 ;
struct V_160 V_161 [ 1 ] ;
struct V_158 V_159 ;
struct V_162 * V_163 ;
# if F_12 ( V_217 ) && F_12 ( V_218 )
char V_164 [ F_57 ( sizeof( struct V_219 ) ) +
F_57 ( sizeof( struct V_220 ) ) ] ;
struct V_219 * V_213 ;
struct V_220 * V_142 ;
# else
char V_164 [ F_57 ( sizeof( struct V_186 ) ) ] ;
struct V_186 * V_187 ;
# endif
F_20 () ;
if ( V_41 [ 0 ] != 23 ) {
memset ( & V_216 , 0x00 , sizeof( struct V_211 ) ) ;
# ifdef F_58
V_216 . V_221 = F_58 ;
# endif
V_212 = & V_216 ;
}
if ( V_6 -> V_222 && ! F_59 ( V_13 ) ) {
V_6 -> V_144 . V_114 = V_13 ;
if ( V_6 -> V_144 . V_6 )
F_9 ( V_6 -> V_144 . V_6 ) ;
V_6 -> V_144 . V_6 = F_6 ( V_42 ) ;
memcpy ( V_6 -> V_144 . V_6 , V_41 , V_42 ) ;
V_6 -> V_144 . V_200 = V_42 ;
return V_42 ;
}
V_161 [ 0 ] . V_167 = ( char * ) V_41 ;
V_161 [ 0 ] . V_168 = V_42 ;
V_159 . V_169 = NULL ;
V_159 . V_170 = 0 ;
V_159 . V_171 = V_161 ;
V_159 . V_172 = 1 ;
V_159 . V_173 = ( V_223 ) V_164 ;
V_159 . V_174 = 0 ;
V_159 . V_175 = 0 ;
# if F_12 ( V_217 ) && F_12 ( V_218 )
V_163 = (struct V_162 * ) V_164 ;
V_163 -> V_176 = V_128 ;
V_163 -> V_177 = V_217 ;
V_163 -> V_224 = F_60 ( sizeof( struct V_219 ) ) ;
V_213 = (struct V_219 * ) F_53 ( V_163 ) ;
memset ( V_213 , 0 , sizeof( struct V_219 ) ) ;
V_213 -> V_225 = V_212 -> V_225 ;
V_213 -> V_221 = V_212 -> V_221 ;
V_213 -> V_226 = V_212 -> V_226 ;
V_213 -> V_227 = V_212 -> V_227 ;
V_159 . V_174 += F_57 ( sizeof( struct V_219 ) ) ;
V_163 =
(struct V_162 * ) & V_164 [ F_57 ( sizeof( struct V_219 ) ) ] ;
V_163 -> V_176 = V_128 ;
V_163 -> V_177 = V_218 ;
V_163 -> V_224 = F_60 ( sizeof( struct V_220 ) ) ;
V_142 = (struct V_220 * ) F_53 ( V_163 ) ;
memset ( V_142 , 0 , sizeof( struct V_220 ) ) ;
V_142 -> V_143 = V_215 -> V_143 ;
V_142 -> V_228 = V_215 -> V_228 ;
V_159 . V_174 += F_57 ( sizeof( struct V_220 ) ) ;
# else
V_163 = (struct V_162 * ) V_164 ;
V_163 -> V_176 = V_128 ;
V_163 -> V_177 = F_54 ;
V_163 -> V_224 = F_60 ( sizeof( struct V_186 ) ) ;
V_187 = (struct V_186 * ) F_53 ( V_163 ) ;
memset ( V_187 , 0 , sizeof( struct V_186 ) ) ;
V_187 -> V_188 = V_212 -> V_225 ;
V_187 -> V_190 = V_212 -> V_221 ;
# ifdef F_61
V_187 -> V_190 |= V_215 -> V_143 ;
# endif
V_187 -> V_191 = V_212 -> V_226 ;
V_187 -> V_194 = V_212 -> V_227 ;
V_187 -> V_229 = V_215 -> V_228 ;
V_159 . V_174 += F_57 ( sizeof( struct V_186 ) ) ;
# endif
V_4 = F_62 ( V_13 -> V_8 , & V_159 , 0 ) ;
F_23 ( V_13 ) ;
if ( V_4 <= 0 ) {
if ( F_24 ( V_4 ) ) {
F_30 ( V_13 ) ;
V_6 -> V_40 = F_26 () ;
}
}
return ( V_4 ) ;
}
static long F_63 ( T_2 * V_13 , int V_50 , long V_8 , void * V_9 )
{
long V_4 = 1 ;
T_6 * V_6 = NULL ;
T_5 V_57 = 0 ;
struct V_152 V_153 ;
struct V_230 * V_231 = NULL ;
V_6 = ( T_6 * ) V_13 -> V_9 ;
switch ( V_50 ) {
case V_81 :
V_6 -> V_82 = 16384 ;
V_4 = V_6 -> V_82 ;
break;
case V_86 :
V_6 -> V_82 = 16384 ;
V_4 = V_6 -> V_82 ;
break;
case V_87 :
case V_74 :
V_4 = - 1 ;
break;
case V_89 :
break;
case V_109 :
V_4 = 0 ;
break;
case V_232 :
if ( V_8 > 0 )
V_6 -> V_233 = 1 ;
else
V_6 -> V_233 = 0 ;
V_4 =
F_17 ( V_13 -> V_8 , V_128 , V_234 ,
& V_6 -> V_233 , sizeof( int ) ) ;
break;
case V_235 :
V_57 = sizeof( struct V_152 ) ;
V_4 =
F_14 ( V_13 -> V_8 , V_128 , V_236 , & V_153 ,
& V_57 ) ;
if ( V_4 < 0 )
break;
V_57 = sizeof( struct V_230 ) + 64 * sizeof( V_132 ) ;
V_231 = F_6 ( V_57 ) ;
if ( V_231 == NULL ) {
V_4 = - 1 ;
break;
}
memset ( V_231 , 0x00 , V_57 ) ;
V_231 -> V_237 = V_153 . V_154 + 1 ;
# ifndef F_61
V_231 -> V_238 = 64 ;
# endif
memcpy ( & V_231 -> V_239 [ 0 ] , V_9 , 64 * sizeof( V_132 ) ) ;
V_4 =
F_17 ( V_13 -> V_8 , V_128 , V_240 , V_231 ,
V_57 ) ;
F_9 ( V_231 ) ;
V_231 = NULL ;
if ( V_4 < 0 )
break;
V_4 = F_17 ( V_13 -> V_8 , V_128 , V_236 ,
& V_153 , sizeof( struct V_152 ) ) ;
if ( V_4 < 0 )
break;
break;
case V_241 :
V_57 = sizeof( struct V_152 ) ;
V_4 =
F_14 ( V_13 -> V_8 , V_128 , V_236 , & V_153 ,
& V_57 ) ;
if ( V_4 < 0 )
break;
V_153 . V_154 = V_153 . V_154 + 1 ;
V_4 = F_17 ( V_13 -> V_8 , V_128 , V_236 ,
& V_153 , sizeof( struct V_152 ) ) ;
if ( V_4 < 0 )
break;
V_6 -> V_242 = 1 ;
case V_243 :
if ( V_50 == V_243 )
V_6 -> V_244 = 1 ;
if ( V_6 -> V_244 == 1 && V_6 -> V_242 == 1 ) {
V_57 = sizeof( struct V_152 ) ;
V_4 =
F_14 ( V_13 -> V_8 , V_128 , V_236 ,
& V_153 , & V_57 ) ;
if ( V_4 < 0 )
break;
V_153 . V_154 = V_153 . V_154 - 1 ;
# ifdef F_64
V_57 = sizeof( struct V_152 ) ;
V_4 = F_17 ( V_13 -> V_8 , V_128 , F_64 ,
& V_153 , V_57 ) ;
if ( V_4 < 0 )
break;
# endif
# ifndef F_39
if ( V_153 . V_154 > 0 ) {
V_153 . V_154 = V_153 . V_154 - 1 ;
V_4 = F_17 ( V_13 -> V_8 , V_128 , V_156 ,
& V_153 , sizeof( struct V_152 ) ) ;
if ( V_4 < 0 )
break;
}
# endif
V_6 -> V_244 = 0 ;
V_6 -> V_242 = 0 ;
}
break;
case V_245 :
if ( V_8 > ( long ) sizeof( struct V_211 ) )
V_8 = sizeof( struct V_211 ) ;
memcpy ( V_9 , & ( V_6 -> V_213 ) , V_8 ) ;
V_4 = V_8 ;
break;
case V_246 :
if ( V_8 > ( long ) sizeof( struct V_211 ) )
V_8 = sizeof( struct V_211 ) ;
memcpy ( & ( V_6 -> V_213 ) , V_9 , V_8 ) ;
break;
case V_247 :
if ( V_8 > ( long ) sizeof( struct V_166 ) )
V_8 = sizeof( struct V_166 ) ;
memcpy ( V_9 , & V_6 -> V_165 , V_8 ) ;
V_4 = V_8 ;
break;
case V_248 :
if ( V_8 > ( long ) sizeof( struct V_166 ) )
V_8 = sizeof( struct V_166 ) ;
memcpy ( & ( V_6 -> V_165 ) , V_9 , V_8 ) ;
break;
case V_249 :
if ( V_8 > ( long ) sizeof( struct V_214 ) )
V_8 = sizeof( struct V_214 ) ;
memcpy ( V_9 , & ( V_6 -> V_142 ) , V_8 ) ;
V_4 = V_8 ;
break;
case V_250 :
if ( V_8 > ( long ) sizeof( struct V_214 ) )
V_8 = sizeof( struct V_214 ) ;
memcpy ( & ( V_6 -> V_142 ) , V_9 , V_8 ) ;
break;
case V_251 :
if ( V_8 > 0 )
V_6 -> V_222 = 1 ;
else
V_6 -> V_222 = 0 ;
break;
default:
V_4 = F_33 ( V_13 , V_50 , V_8 , V_9 ) ;
break;
}
return ( V_4 ) ;
}
int F_65 ( T_2 * V_13 ,
void (* V_202) ( T_2 * V_114 ,
void
* V_252 ,
void * V_253 ) ,
void * V_252 )
{
T_6 * V_6 = ( T_6 * ) V_13 -> V_9 ;
if ( V_202 != NULL ) {
V_6 -> V_202 = V_202 ;
V_6 -> V_203 = V_252 ;
} else
return - 1 ;
return 0 ;
}
int F_59 ( T_2 * V_13 )
{
int V_254 = 0 ;
int V_112 , V_255 , V_4 ;
union V_145 V_146 ;
struct V_158 V_159 ;
struct V_160 V_161 ;
# ifdef F_40
struct V_123 V_124 ;
# else
struct V_125 V_124 ;
T_5 V_199 ;
# endif
T_6 * V_6 = ( T_6 * ) V_13 -> V_9 ;
# ifdef F_40
memset ( & V_124 , 0 , sizeof( struct V_123 ) ) ;
V_124 . V_135 = 0 ;
V_124 . V_136 = V_198 ;
V_124 . V_137 = 1 ;
V_4 =
F_17 ( V_13 -> V_8 , V_128 , F_40 , & V_124 ,
sizeof( struct V_123 ) ) ;
# else
V_199 = sizeof( struct V_125 ) ;
V_4 = F_14 ( V_13 -> V_8 , V_128 , V_138 , & V_124 , & V_199 ) ;
if ( V_4 < 0 )
return - 1 ;
V_124 . V_201 = 1 ;
V_4 =
F_17 ( V_13 -> V_8 , V_128 , V_138 , & V_124 ,
sizeof( struct V_125 ) ) ;
# endif
if ( V_4 < 0 )
return - 1 ;
memset ( & V_146 , 0x00 , sizeof( union V_145 ) ) ;
V_161 . V_167 = ( char * ) & V_146 ;
V_161 . V_168 = sizeof( union V_145 ) ;
V_159 . V_169 = NULL ;
V_159 . V_170 = 0 ;
V_159 . V_171 = & V_161 ;
V_159 . V_172 = 1 ;
V_159 . V_173 = NULL ;
V_159 . V_174 = 0 ;
V_159 . V_175 = 0 ;
V_112 = F_49 ( V_13 -> V_8 , & V_159 , V_256 ) ;
if ( V_112 <= 0 ) {
if ( ( V_112 < 0 ) && ( F_26 () != V_99 )
&& ( F_26 () != V_257 ) )
return - 1 ;
else
return 0 ;
}
while ( V_159 . V_175 & V_195 ) {
memset ( & V_146 , 0x00 , sizeof( union V_145 ) ) ;
V_161 . V_167 = ( char * ) & V_146 ;
V_161 . V_168 = sizeof( union V_145 ) ;
V_159 . V_169 = NULL ;
V_159 . V_170 = 0 ;
V_159 . V_171 = & V_161 ;
V_159 . V_172 = 1 ;
V_159 . V_173 = NULL ;
V_159 . V_174 = 0 ;
V_159 . V_175 = 0 ;
V_112 = F_49 ( V_13 -> V_8 , & V_159 , 0 ) ;
if ( V_112 <= 0 ) {
if ( ( V_112 < 0 ) && ( F_26 () != V_99 )
&& ( F_26 () != V_257 ) )
return - 1 ;
else
return V_254 ;
}
if ( V_146 . V_196 . V_197 == V_198 ) {
V_254 = 1 ;
# ifdef F_40
memset ( & V_124 , 0 , sizeof( struct V_123 ) ) ;
V_124 . V_135 = 0 ;
V_124 . V_136 = V_198 ;
V_124 . V_137 = 0 ;
V_4 =
F_17 ( V_13 -> V_8 , V_128 , F_40 , & V_124 ,
sizeof( struct V_123 ) ) ;
# else
V_199 = ( T_5 ) sizeof( struct V_125 ) ;
V_4 =
F_14 ( V_13 -> V_8 , V_128 , V_138 , & V_124 ,
& V_199 ) ;
if ( V_4 < 0 )
return - 1 ;
V_124 . V_201 = 0 ;
V_4 =
F_17 ( V_13 -> V_8 , V_128 , V_138 , & V_124 ,
sizeof( struct V_125 ) ) ;
# endif
if ( V_4 < 0 )
return - 1 ;
}
# ifdef F_39
if ( V_146 . V_196 . V_197 == F_39 )
F_47 ( V_13 , & V_146 ) ;
# endif
if ( V_6 -> V_202 != NULL )
V_6 -> V_202 ( V_13 , V_6 -> V_203 ,
( void * ) & V_146 ) ;
memset ( & V_146 , 0x00 , sizeof( union V_145 ) ) ;
V_161 . V_167 = ( char * ) & V_146 ;
V_161 . V_168 = sizeof( union V_145 ) ;
V_159 . V_169 = NULL ;
V_159 . V_170 = 0 ;
V_159 . V_171 = & V_161 ;
V_159 . V_172 = 1 ;
V_159 . V_173 = NULL ;
V_159 . V_174 = 0 ;
V_159 . V_175 = 0 ;
if ( V_254 ) {
V_255 = F_66 ( V_13 -> V_8 , V_258 , 0 ) ;
F_66 ( V_13 -> V_8 , V_259 , V_260 ) ;
}
V_112 = F_49 ( V_13 -> V_8 , & V_159 , V_256 ) ;
if ( V_254 ) {
F_66 ( V_13 -> V_8 , V_259 , V_255 ) ;
}
if ( V_112 <= 0 ) {
if ( ( V_112 < 0 ) && ( F_26 () != V_99 )
&& ( F_26 () != V_257 ) )
return - 1 ;
else
return V_254 ;
}
}
return V_254 ;
}
int F_67 ( T_2 * V_13 )
{
int V_112 , V_255 ;
union V_145 V_146 ;
struct V_158 V_159 ;
struct V_160 V_161 ;
T_6 * V_6 = ( T_6 * ) V_13 -> V_9 ;
do {
memset ( & V_146 , 0x00 , sizeof( union V_145 ) ) ;
V_161 . V_167 = ( char * ) & V_146 ;
V_161 . V_168 = sizeof( union V_145 ) ;
V_159 . V_169 = NULL ;
V_159 . V_170 = 0 ;
V_159 . V_171 = & V_161 ;
V_159 . V_172 = 1 ;
V_159 . V_173 = NULL ;
V_159 . V_174 = 0 ;
V_159 . V_175 = 0 ;
V_255 = F_66 ( V_13 -> V_8 , V_258 , 0 ) ;
F_66 ( V_13 -> V_8 , V_259 , V_260 ) ;
V_112 = F_49 ( V_13 -> V_8 , & V_159 , V_256 ) ;
F_66 ( V_13 -> V_8 , V_259 , V_255 ) ;
if ( V_112 > 0 && ( V_159 . V_175 & V_195 ) ) {
# ifdef F_39
if ( V_146 . V_196 . V_197 == F_39 )
F_47 ( V_13 , & V_146 ) ;
# endif
memset ( & V_146 , 0x00 , sizeof( union V_145 ) ) ;
V_161 . V_167 = ( char * ) & V_146 ;
V_161 . V_168 = sizeof( union V_145 ) ;
V_159 . V_169 = NULL ;
V_159 . V_170 = 0 ;
V_159 . V_171 = & V_161 ;
V_159 . V_172 = 1 ;
V_159 . V_173 = NULL ;
V_159 . V_174 = 0 ;
V_159 . V_175 = 0 ;
V_112 = F_49 ( V_13 -> V_8 , & V_159 , 0 ) ;
if ( V_6 -> V_202 != NULL )
V_6 -> V_202 ( V_13 , V_6 -> V_203 ,
( void * ) & V_146 ) ;
}
} while ( V_112 > 0 && ( V_159 . V_175 & V_195 ) );
if ( V_112 > 0 )
return 1 ;
else
return 0 ;
}
static int F_68 ( T_2 * V_110 , const char * V_111 )
{
int V_112 , V_4 ;
V_112 = strlen ( V_111 ) ;
V_4 = F_55 ( V_110 , V_111 , V_112 ) ;
return ( V_4 ) ;
}
static int F_24 ( int V_16 )
{
int V_261 ;
if ( ( V_16 == 0 ) || ( V_16 == - 1 ) ) {
V_261 = F_26 () ;
# if F_12 ( F_13 )
# endif
return ( F_69 ( V_261 ) ) ;
}
return ( 0 ) ;
}
int F_69 ( int V_261 )
{
switch ( V_261 ) {
# if F_12 ( F_13 )
# if F_12 ( V_262 )
case V_262 :
# endif
# if 0
# if F_12 ( V_263 )
case WSAENOTCONN:
# endif
# endif
# endif
# ifdef V_257
# ifdef V_262
# if V_262 != V_257
case V_257 :
# endif
# else
case V_257 :
# endif
# endif
# ifdef F_70
case F_70 :
# endif
# ifdef V_99
# if V_257 != V_99
case V_99 :
# endif
# endif
# ifdef F_71
case F_71 :
# endif
# ifdef F_72
case F_72 :
# endif
# ifdef F_73
case F_73 :
# endif
return ( 1 ) ;
default:
break;
}
return ( 0 ) ;
}
static void F_16 ( struct V_21 * V_264 )
{
# if F_12 ( V_265 )
T_7 V_266 ;
union {
unsigned T_8 V_267 ;
T_9 V_268 ;
} V_269 ;
F_74 ( & V_266 ) ;
F_75 ( & V_266 , & V_269 . V_268 ) ;
# ifdef F_76
V_269 . V_267 -= 116444736000000000ULL ;
# else
V_269 . V_267 -= 116444736000000000UI64 ;
# endif
V_264 -> V_19 = ( long ) ( V_269 . V_267 / 10000000 ) ;
V_264 -> V_20 = ( ( int ) ( V_269 . V_267 % 10000000 ) ) / 10 ;
# elif F_12 ( V_270 )
struct V_271 V_272 ;
F_77 ( & V_272 ) ;
V_264 -> V_19 = ( long ) V_272 . time ;
V_264 -> V_20 = ( long ) V_272 . V_273 * 1000 ;
# else
F_78 ( V_264 , NULL ) ;
# endif
}
