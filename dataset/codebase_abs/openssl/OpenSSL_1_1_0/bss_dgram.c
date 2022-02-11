const T_1 * F_1 ( void )
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
T_3 * V_6 = F_6 ( sizeof( * V_6 ) ) ;
if ( V_6 == NULL )
return 0 ;
V_5 -> V_7 = V_6 ;
return ( 1 ) ;
}
static int F_7 ( T_2 * V_8 )
{
T_3 * V_6 ;
if ( V_8 == NULL )
return ( 0 ) ;
if ( ! F_8 ( V_8 ) )
return 0 ;
V_6 = ( T_3 * ) V_8 -> V_7 ;
F_9 ( V_6 ) ;
return ( 1 ) ;
}
static int F_8 ( T_2 * V_8 )
{
if ( V_8 == NULL )
return ( 0 ) ;
if ( V_8 -> V_9 ) {
if ( V_8 -> V_10 ) {
F_10 ( V_8 -> V_11 ) ;
}
V_8 -> V_10 = 0 ;
V_8 -> V_12 = 0 ;
}
return ( 1 ) ;
}
static void F_11 ( T_2 * V_13 )
{
# if F_12 ( V_14 )
T_3 * V_6 = ( T_3 * ) V_13 -> V_7 ;
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
if ( F_14 ( V_13 -> V_11 , V_25 , V_14 ,
( void * ) & V_24 , & V_17 . V_16 ) < 0 ) {
perror ( L_1 ) ;
} else {
V_6 -> V_26 . V_19 = V_24 / 1000 ;
V_6 -> V_26 . V_20 = ( V_24 % 1000 ) * 1000 ;
}
# else
V_17 . V_16 = sizeof( V_6 -> V_26 ) ;
if ( F_14 ( V_13 -> V_11 , V_25 , V_14 ,
& ( V_6 -> V_26 ) , ( void * ) & V_17 ) < 0 ) {
perror ( L_1 ) ;
} else if ( sizeof( V_17 . V_15 ) != sizeof( V_17 . V_16 ) && V_17 . V_16 == 0 )
F_15 ( V_17 . V_15 <= sizeof( V_6 -> V_26 ) ) ;
# endif
F_16 ( & V_22 ) ;
memcpy ( & V_23 , & ( V_6 -> V_18 ) , sizeof( struct V_21 ) ) ;
if ( V_23 . V_20 < V_22 . V_20 ) {
V_23 . V_20 = 1000000 - V_22 . V_20 + V_23 . V_20 ;
V_23 . V_19 -- ;
} else {
V_23 . V_20 -= V_22 . V_20 ;
}
if ( V_23 . V_19 < V_22 . V_19 ) {
V_23 . V_19 = 0 ;
V_23 . V_20 = 1 ;
} else {
V_23 . V_19 -= V_22 . V_19 ;
}
if ( ( V_6 -> V_26 . V_19 == 0
&& V_6 -> V_26 . V_20 == 0 )
|| ( V_6 -> V_26 . V_19 > V_23 . V_19 )
|| ( V_6 -> V_26 . V_19 == V_23 . V_19
&& V_6 -> V_26 . V_20 >= V_23 . V_20 ) ) {
# ifdef F_13
V_24 = V_23 . V_19 * 1000 + V_23 . V_20 / 1000 ;
if ( F_17 ( V_13 -> V_11 , V_25 , V_14 ,
( void * ) & V_24 , sizeof( V_24 ) ) < 0 ) {
perror ( L_2 ) ;
}
# else
if ( F_17 ( V_13 -> V_11 , V_25 , V_14 , & V_23 ,
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
T_3 * V_6 = ( T_3 * ) V_13 -> V_7 ;
if ( V_6 -> V_18 . V_19 > 0 || V_6 -> V_18 . V_20 > 0 ) {
# ifdef F_13
int V_24 = V_6 -> V_26 . V_19 * 1000 +
V_6 -> V_26 . V_20 / 1000 ;
if ( F_17 ( V_13 -> V_11 , V_25 , V_14 ,
( void * ) & V_24 , sizeof( V_24 ) ) < 0 ) {
perror ( L_2 ) ;
}
# else
if ( F_17
( V_13 -> V_11 , V_25 , V_14 , & ( V_6 -> V_26 ) ,
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
T_3 * V_6 = ( T_3 * ) V_13 -> V_7 ;
int V_12 = 0 ;
T_5 V_29 ;
T_6 V_30 = sizeof( V_29 ) ;
if ( V_27 != NULL ) {
F_20 () ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
F_11 ( V_13 ) ;
if ( V_6 -> V_31 )
V_12 = V_32 ;
V_4 = F_21 ( V_13 -> V_11 , V_27 , V_28 , V_12 ,
F_22 ( & V_29 ) , & V_30 ) ;
if ( ! V_6 -> V_33 && V_4 >= 0 )
F_23 ( V_13 , V_34 , 0 , & V_29 ) ;
F_24 ( V_13 ) ;
if ( V_4 < 0 ) {
if ( F_25 ( V_4 ) ) {
F_26 ( V_13 ) ;
V_6 -> V_35 = F_27 () ;
}
}
F_18 ( V_13 ) ;
}
return ( V_4 ) ;
}
static int F_28 ( T_2 * V_13 , const char * V_36 , int V_37 )
{
int V_4 ;
T_3 * V_6 = ( T_3 * ) V_13 -> V_7 ;
F_20 () ;
if ( V_6 -> V_33 )
V_4 = F_29 ( V_13 -> V_11 , V_36 , V_37 ) ;
else {
int V_38 = F_30 ( & V_6 -> V_29 ) ;
# if F_12 ( V_39 ) && F_12 ( V_40 )
V_4 = F_31 ( V_13 -> V_11 , ( char * ) V_36 , V_37 , 0 ,
F_32 ( & V_6 -> V_29 ) , V_38 ) ;
# else
V_4 = F_31 ( V_13 -> V_11 , V_36 , V_37 , 0 ,
F_32 ( & V_6 -> V_29 ) , V_38 ) ;
# endif
}
F_24 ( V_13 ) ;
if ( V_4 <= 0 ) {
if ( F_25 ( V_4 ) ) {
F_33 ( V_13 ) ;
V_6 -> V_35 = F_27 () ;
}
}
return ( V_4 ) ;
}
static long F_34 ( T_3 * V_6 )
{
long V_4 ;
switch ( F_35 ( & V_6 -> V_29 ) ) {
case V_41 :
V_4 = 28 ;
break;
# ifdef F_36
case F_36 :
{
# ifdef F_37
struct V_42 V_43 ;
if ( F_38 ( & V_6 -> V_29 , & V_43 , NULL )
&& F_37 ( & V_43 ) )
V_4 = 28 ;
else
# endif
V_4 = 48 ;
}
break;
# endif
default:
V_4 = 28 ;
break;
}
return V_4 ;
}
static long F_39 ( T_2 * V_13 , int V_44 , long V_11 , void * V_7 )
{
long V_4 = 1 ;
int * V_45 ;
T_3 * V_6 = NULL ;
int V_46 = 0 ;
int V_47 ;
# if F_12 ( V_48 ) && ( F_12 ( V_49 ) || F_12 ( V_50 ) )
T_6 V_51 ;
T_6 V_52 ;
T_5 V_53 ;
# endif
V_6 = ( T_3 * ) V_13 -> V_7 ;
switch ( V_44 ) {
case V_54 :
V_11 = 0 ;
V_4 = 0 ;
break;
case V_55 :
V_4 = 0 ;
break;
case V_56 :
F_8 ( V_13 ) ;
V_13 -> V_11 = * ( ( int * ) V_7 ) ;
V_13 -> V_9 = ( int ) V_11 ;
V_13 -> V_10 = 1 ;
break;
case V_57 :
if ( V_13 -> V_10 ) {
V_45 = ( int * ) V_7 ;
if ( V_45 != NULL )
* V_45 = V_13 -> V_11 ;
V_4 = V_13 -> V_11 ;
} else
V_4 = - 1 ;
break;
case V_58 :
V_4 = V_13 -> V_9 ;
break;
case V_59 :
V_13 -> V_9 = ( int ) V_11 ;
break;
case V_60 :
case V_61 :
V_4 = 0 ;
break;
case V_62 :
case V_63 :
V_4 = 1 ;
break;
case V_64 :
F_40 ( & V_6 -> V_29 , F_32 ( ( T_5 * ) V_7 ) ) ;
break;
case V_65 :
# if F_12 ( V_48 ) && F_12 ( V_49 ) && F_12 ( V_66 )
V_52 = ( T_6 ) sizeof( V_53 ) ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
if ( F_41 ( V_13 -> V_11 , & V_53 . V_67 , & V_52 ) < 0 ) {
V_4 = 0 ;
break;
}
switch ( V_53 . V_67 . V_68 ) {
case V_41 :
V_46 = V_66 ;
if ( ( V_4 = F_17 ( V_13 -> V_11 , V_69 , V_49 ,
& V_46 , sizeof( V_46 ) ) ) < 0 )
perror ( L_2 ) ;
break;
# if V_70 && F_12 ( V_71 ) && F_12 ( V_72 )
case F_36 :
V_46 = V_72 ;
if ( ( V_4 = F_17 ( V_13 -> V_11 , V_73 , V_71 ,
& V_46 , sizeof( V_46 ) ) ) < 0 )
perror ( L_2 ) ;
break;
# endif
default:
V_4 = - 1 ;
break;
}
# else
V_4 = - 1 ;
# endif
break;
case V_74 :
# if F_12 ( V_48 ) && F_12 ( V_50 )
V_52 = ( T_6 ) sizeof( V_53 ) ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
if ( F_41 ( V_13 -> V_11 , & V_53 . V_67 , & V_52 ) < 0 ) {
V_4 = 0 ;
break;
}
V_51 = sizeof( V_46 ) ;
switch ( V_53 . V_67 . V_68 ) {
case V_41 :
if ( ( V_4 =
F_14 ( V_13 -> V_11 , V_69 , V_50 , ( void * ) & V_46 ,
& V_51 ) ) < 0 || V_46 < 0 ) {
V_4 = 0 ;
} else {
V_6 -> V_75 = V_46 - 8 - 20 ;
V_4 = V_6 -> V_75 ;
}
break;
# if V_70 && F_12 ( V_76 )
case F_36 :
if ( ( V_4 =
F_14 ( V_13 -> V_11 , V_73 , V_76 ,
( void * ) & V_46 , & V_51 ) ) < 0
|| V_46 < 0 ) {
V_4 = 0 ;
} else {
V_6 -> V_75 = V_46 - 8 - 40 ;
V_4 = V_6 -> V_75 ;
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
case V_77 :
V_4 = - F_34 ( V_6 ) ;
switch ( F_35 ( & V_6 -> V_29 ) ) {
case V_41 :
V_4 += 576 ;
break;
# if V_70
case F_36 :
{
# ifdef F_37
struct V_42 V_43 ;
if ( F_38 ( & V_6 -> V_29 , & V_43 , NULL )
&& F_37 ( & V_43 ) )
V_4 += 576 ;
else
# endif
V_4 += 1280 ;
}
break;
# endif
default:
V_4 += 576 ;
break;
}
break;
case V_78 :
return V_6 -> V_75 ;
case V_79 :
V_6 -> V_75 = V_11 ;
V_4 = V_11 ;
break;
case V_80 :
if ( V_7 != NULL ) {
V_6 -> V_33 = 1 ;
F_40 ( & V_6 -> V_29 , F_32 ( ( T_5 * ) V_7 ) ) ;
} else {
V_6 -> V_33 = 0 ;
memset ( & V_6 -> V_29 , 0 , sizeof( V_6 -> V_29 ) ) ;
}
break;
case V_81 :
V_4 = F_30 ( & V_6 -> V_29 ) ;
if ( V_11 == 0 || V_11 > V_4 )
V_11 = V_4 ;
memcpy ( V_7 , & V_6 -> V_29 , ( V_4 = V_11 ) ) ;
break;
case V_34 :
F_40 ( & V_6 -> V_29 , F_32 ( ( T_5 * ) V_7 ) ) ;
break;
case V_82 :
memcpy ( & ( V_6 -> V_18 ) , V_7 , sizeof( struct V_21 ) ) ;
break;
# if F_12 ( V_14 )
case V_83 :
# ifdef F_13
{
struct V_21 * V_84 = (struct V_21 * ) V_7 ;
int V_24 = V_84 -> V_19 * 1000 + V_84 -> V_20 / 1000 ;
if ( F_17 ( V_13 -> V_11 , V_25 , V_14 ,
( void * ) & V_24 , sizeof( V_24 ) ) < 0 ) {
perror ( L_2 ) ;
V_4 = - 1 ;
}
}
# else
if ( F_17 ( V_13 -> V_11 , V_25 , V_14 , V_7 ,
sizeof( struct V_21 ) ) < 0 ) {
perror ( L_2 ) ;
V_4 = - 1 ;
}
# endif
break;
case V_85 :
{
union {
T_4 V_15 ;
int V_16 ;
} V_17 = {
0
} ;
# ifdef F_13
int V_24 ;
struct V_21 * V_84 = (struct V_21 * ) V_7 ;
V_17 . V_16 = sizeof( V_24 ) ;
if ( F_14 ( V_13 -> V_11 , V_25 , V_14 ,
( void * ) & V_24 , & V_17 . V_16 ) < 0 ) {
perror ( L_1 ) ;
V_4 = - 1 ;
} else {
V_84 -> V_19 = V_24 / 1000 ;
V_84 -> V_20 = ( V_24 % 1000 ) * 1000 ;
V_4 = sizeof( * V_84 ) ;
}
# else
V_17 . V_16 = sizeof( struct V_21 ) ;
if ( F_14 ( V_13 -> V_11 , V_25 , V_14 ,
V_7 , ( void * ) & V_17 ) < 0 ) {
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
# if F_12 ( V_86 )
case V_87 :
# ifdef F_13
{
struct V_21 * V_84 = (struct V_21 * ) V_7 ;
int V_24 = V_84 -> V_19 * 1000 + V_84 -> V_20 / 1000 ;
if ( F_17 ( V_13 -> V_11 , V_25 , V_86 ,
( void * ) & V_24 , sizeof( V_24 ) ) < 0 ) {
perror ( L_2 ) ;
V_4 = - 1 ;
}
}
# else
if ( F_17 ( V_13 -> V_11 , V_25 , V_86 , V_7 ,
sizeof( struct V_21 ) ) < 0 ) {
perror ( L_2 ) ;
V_4 = - 1 ;
}
# endif
break;
case V_88 :
{
union {
T_4 V_15 ;
int V_16 ;
} V_17 = {
0
} ;
# ifdef F_13
int V_24 ;
struct V_21 * V_84 = (struct V_21 * ) V_7 ;
V_17 . V_16 = sizeof( V_24 ) ;
if ( F_14 ( V_13 -> V_11 , V_25 , V_86 ,
( void * ) & V_24 , & V_17 . V_16 ) < 0 ) {
perror ( L_1 ) ;
V_4 = - 1 ;
} else {
V_84 -> V_19 = V_24 / 1000 ;
V_84 -> V_20 = ( V_24 % 1000 ) * 1000 ;
V_4 = sizeof( * V_84 ) ;
}
# else
V_17 . V_16 = sizeof( struct V_21 ) ;
if ( F_14 ( V_13 -> V_11 , V_25 , V_86 ,
V_7 , ( void * ) & V_17 ) < 0 ) {
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
case V_89 :
case V_90 :
# ifdef F_13
V_47 = ( V_6 -> V_35 == V_91 ) ;
# else
V_47 = ( V_6 -> V_35 == V_92 ) ;
# endif
if ( V_47 ) {
V_4 = 1 ;
V_6 -> V_35 = 0 ;
} else
V_4 = 0 ;
break;
# ifdef F_42
case V_93 :
if ( V_6 -> V_35 == F_42 ) {
V_4 = 1 ;
V_6 -> V_35 = 0 ;
} else
V_4 = 0 ;
break;
# endif
case V_94 :
V_46 = V_11 ? 1 : 0 ;
switch ( V_6 -> V_29 . V_67 . V_68 ) {
case V_41 :
# if F_12 ( V_95 )
if ( ( V_4 = F_17 ( V_13 -> V_11 , V_69 , V_95 ,
& V_46 , sizeof( V_46 ) ) ) < 0 ) {
perror ( L_2 ) ;
V_4 = - 1 ;
}
# elif F_12 ( V_48 ) && F_12 ( V_49 ) && F_12 ( V_96 )
if ( ( V_46 = V_11 ? V_96 : V_97 ) ,
( V_4 = F_17 ( V_13 -> V_11 , V_69 , V_49 ,
& V_46 , sizeof( V_46 ) ) ) < 0 ) {
perror ( L_2 ) ;
V_4 = - 1 ;
}
# elif F_12 ( F_13 ) && F_12 ( V_98 )
if ( ( V_4 = F_17 ( V_13 -> V_11 , V_69 , V_98 ,
( const char * ) & V_46 ,
sizeof( V_46 ) ) ) < 0 ) {
perror ( L_2 ) ;
V_4 = - 1 ;
}
# else
V_4 = - 1 ;
# endif
break;
# if V_70
case F_36 :
# if F_12 ( V_99 )
if ( ( V_4 = F_17 ( V_13 -> V_11 , V_73 , V_99 ,
( const void * ) & V_46 ,
sizeof( V_46 ) ) ) < 0 ) {
perror ( L_2 ) ;
V_4 = - 1 ;
}
# elif F_12 ( V_48 ) && F_12 ( V_100 )
if ( ( V_46 = V_11 ? V_96 : V_97 ) ,
( V_4 = F_17 ( V_13 -> V_11 , V_73 , V_71 ,
& V_46 , sizeof( V_46 ) ) ) < 0 ) {
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
case V_101 :
V_4 = F_34 ( V_6 ) ;
break;
case V_102 :
V_6 -> V_31 = ( unsigned int ) V_11 ;
break;
default:
V_4 = 0 ;
break;
}
return ( V_4 ) ;
}
static int F_43 ( T_2 * V_103 , const char * V_104 )
{
int V_105 , V_4 ;
V_105 = strlen ( V_104 ) ;
V_4 = F_28 ( V_103 , V_104 , V_105 ) ;
return ( V_4 ) ;
}
const T_1 * F_44 ( void )
{
return ( & V_106 ) ;
}
T_2 * F_45 ( int V_2 , int V_3 )
{
T_2 * V_107 ;
int V_4 , V_108 = 20000 ;
int V_109 = 0 , V_110 = 0 ;
unsigned char * V_111 ;
struct V_112 V_113 ;
struct V_114 * V_115 ;
T_6 V_51 ;
# ifdef F_46
# ifdef F_47
struct V_116 V_117 ;
# else
struct V_118 V_117 ;
# endif
# endif
V_107 = F_3 ( F_44 () ) ;
if ( V_107 == NULL )
return ( NULL ) ;
F_4 ( V_107 , V_2 , V_3 ) ;
V_113 . V_119 = V_120 ;
V_4 =
F_17 ( V_2 , V_121 , V_122 , & V_113 ,
sizeof( struct V_112 ) ) ;
if ( V_4 < 0 ) {
F_48 ( V_107 ) ;
return ( NULL ) ;
}
V_113 . V_119 = V_123 ;
V_4 =
F_17 ( V_2 , V_121 , V_122 , & V_113 ,
sizeof( struct V_112 ) ) ;
if ( V_4 < 0 ) {
F_48 ( V_107 ) ;
return ( NULL ) ;
}
V_51 = ( T_6 ) ( sizeof( V_124 ) + 256 * sizeof( V_125 ) ) ;
V_115 = F_6 ( V_51 ) ;
if ( V_115 == NULL ) {
F_48 ( V_107 ) ;
return ( NULL ) ;
}
V_4 = F_14 ( V_2 , V_121 , V_126 , V_115 ,
& V_51 ) ;
if ( V_4 < 0 ) {
F_9 ( V_115 ) ;
F_48 ( V_107 ) ;
return ( NULL ) ;
}
for ( V_111 = ( unsigned char * ) V_115 -> V_127 ;
V_111 < ( unsigned char * ) V_115 + V_51 ;
V_111 += sizeof( V_125 ) ) {
if ( * V_111 == V_120 )
V_109 = 1 ;
if ( * V_111 == V_123 )
V_110 = 1 ;
}
F_9 ( V_115 ) ;
F_15 ( V_109 ) ;
F_15 ( V_110 ) ;
# ifdef F_46
# ifdef F_47
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
V_117 . V_128 = 0 ;
V_117 . V_129 = F_46 ;
V_117 . V_130 = 1 ;
V_4 =
F_17 ( V_2 , V_121 , F_47 , & V_117 ,
sizeof( struct V_116 ) ) ;
if ( V_4 < 0 ) {
F_48 ( V_107 ) ;
return ( NULL ) ;
}
# else
V_51 = ( T_6 ) sizeof( struct V_118 ) ;
V_4 = F_14 ( V_2 , V_121 , V_131 , & V_117 , & V_51 ) ;
if ( V_4 < 0 ) {
F_48 ( V_107 ) ;
return ( NULL ) ;
}
V_117 . V_132 = 1 ;
V_4 =
F_17 ( V_2 , V_121 , V_131 , & V_117 ,
sizeof( struct V_118 ) ) ;
if ( V_4 < 0 ) {
F_48 ( V_107 ) ;
return ( NULL ) ;
}
# endif
# endif
V_4 =
F_17 ( V_2 , V_121 , V_133 , & V_108 ,
sizeof( V_108 ) ) ;
if ( V_4 < 0 ) {
F_48 ( V_107 ) ;
return ( NULL ) ;
}
return ( V_107 ) ;
}
int F_49 ( T_2 * V_107 )
{
return ( F_50 ( V_107 ) == V_134 ) ;
}
static int F_51 ( T_2 * V_5 )
{
T_7 * V_6 = NULL ;
V_5 -> V_10 = 0 ;
V_5 -> V_11 = 0 ;
V_6 = F_6 ( sizeof( * V_6 ) ) ;
if ( V_6 == NULL )
return 0 ;
# ifdef F_52
V_6 -> V_135 . V_136 = F_52 ;
# endif
V_5 -> V_7 = V_6 ;
V_5 -> V_12 = 0 ;
return ( 1 ) ;
}
static int F_53 ( T_2 * V_8 )
{
T_7 * V_6 ;
if ( V_8 == NULL )
return ( 0 ) ;
if ( ! F_8 ( V_8 ) )
return 0 ;
V_6 = ( T_7 * ) V_8 -> V_7 ;
if ( V_6 != NULL ) {
F_9 ( V_6 -> V_137 . V_6 ) ;
F_9 ( V_6 ) ;
}
return ( 1 ) ;
}
void F_54 ( T_2 * V_13 ,
union V_138 * V_139 )
{
int V_4 ;
struct V_140 * V_141 = & V_139 -> V_142 ;
if ( V_141 -> V_143 == V_144 ) {
struct V_145 V_146 ;
V_146 . V_147 = V_141 -> V_148 ;
V_4 = F_17 ( V_13 -> V_11 , V_121 , V_149 ,
& V_146 , sizeof( struct V_145 ) ) ;
}
}
static int F_55 ( T_2 * V_13 , char * V_27 , int V_28 )
{
int V_4 = 0 , V_105 = 0 , V_16 , V_108 ;
T_6 V_150 ;
T_7 * V_6 = ( T_7 * ) V_13 -> V_7 ;
union V_138 * V_139 ;
struct V_151 V_152 ;
struct V_153 V_154 ;
struct V_155 * V_156 ;
char V_157 [ 512 ] ;
if ( V_27 != NULL ) {
F_20 () ;
do {
memset ( & V_6 -> V_158 , 0 , sizeof( V_6 -> V_158 ) ) ;
V_154 . V_159 = V_27 ;
V_154 . V_160 = V_28 ;
V_152 . V_161 = NULL ;
V_152 . V_162 = 0 ;
V_152 . V_163 = & V_154 ;
V_152 . V_164 = 1 ;
V_152 . V_165 = V_157 ;
V_152 . V_166 = 512 ;
V_152 . V_167 = 0 ;
V_105 = F_56 ( V_13 -> V_11 , & V_152 , 0 ) ;
if ( V_105 <= 0 ) {
if ( V_105 < 0 )
V_4 = V_105 ;
break;
}
if ( V_152 . V_166 > 0 ) {
for ( V_156 = F_57 ( & V_152 ) ; V_156 ;
V_156 = F_58 ( & V_152 , V_156 ) ) {
if ( V_156 -> V_168 != V_121 )
continue;
# ifdef F_59
if ( V_156 -> V_169 == F_59 ) {
struct V_170 * V_158 ;
V_158 = (struct V_170 * ) F_60 ( V_156 ) ;
V_6 -> V_158 . V_171 = V_158 -> V_171 ;
V_6 -> V_158 . V_172 = V_158 -> V_172 ;
V_6 -> V_158 . V_173 = V_158 -> V_173 ;
V_6 -> V_158 . V_174 = V_158 -> V_174 ;
V_6 -> V_158 . V_175 = V_158 -> V_175 ;
V_6 -> V_158 . V_176 = V_158 -> V_176 ;
V_6 -> V_158 . V_177 = V_158 -> V_177 ;
}
# endif
# ifdef F_61
if ( V_156 -> V_169 == F_61 ) {
struct V_178 * V_179 ;
V_179 =
(struct V_178 * ) F_60 ( V_156 ) ;
V_6 -> V_158 . V_171 = V_179 -> V_180 ;
V_6 -> V_158 . V_172 = V_179 -> V_181 ;
V_6 -> V_158 . V_173 = V_179 -> V_182 ;
V_6 -> V_158 . V_174 = V_179 -> V_183 ;
V_6 -> V_158 . V_175 = V_179 -> V_184 ;
V_6 -> V_158 . V_176 = V_179 -> V_185 ;
V_6 -> V_158 . V_177 = V_179 -> V_186 ;
}
# endif
}
}
if ( V_152 . V_167 & V_187 ) {
V_139 = (union V_138 * ) V_27 ;
if ( V_139 -> V_188 . V_189 == V_190 ) {
# ifdef F_47
struct V_116 V_117 ;
# else
struct V_118 V_117 ;
T_6 V_191 ;
# endif
if ( V_6 -> V_137 . V_192 > 0 ) {
V_16 = F_62 ( V_6 -> V_137 . V_107 ,
V_6 -> V_137 . V_6 ,
V_6 -> V_137 . V_192 ) ;
if ( V_16 < 0 ) {
V_4 = V_16 ;
break;
}
F_9 ( V_6 -> V_137 . V_6 ) ;
V_6 -> V_137 . V_6 = NULL ;
V_6 -> V_137 . V_192 = 0 ;
}
# ifdef F_47
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
V_117 . V_128 = 0 ;
V_117 . V_129 = V_190 ;
V_117 . V_130 = 0 ;
V_16 = F_17 ( V_13 -> V_11 , V_121 , F_47 , & V_117 ,
sizeof( struct V_116 ) ) ;
if ( V_16 < 0 ) {
V_4 = V_16 ;
break;
}
# else
V_191 = sizeof( struct V_118 ) ;
V_16 = F_14 ( V_13 -> V_11 , V_121 , V_131 , & V_117 ,
& V_191 ) ;
if ( V_16 < 0 ) {
V_4 = V_16 ;
break;
}
V_117 . V_193 = 0 ;
V_16 = F_17 ( V_13 -> V_11 , V_121 , V_131 , & V_117 ,
sizeof( struct V_118 ) ) ;
if ( V_16 < 0 ) {
V_4 = V_16 ;
break;
}
# endif
}
# ifdef F_46
if ( V_139 -> V_188 . V_189 == F_46 )
F_54 ( V_13 , V_139 ) ;
# endif
if ( V_6 -> V_194 != NULL )
V_6 -> V_194 ( V_13 , V_6 -> V_195 ,
( void * ) V_27 ) ;
memset ( V_27 , 0 , V_28 ) ;
} else
V_4 += V_105 ;
}
while ( ( V_152 . V_167 & V_187 ) && ( V_152 . V_167 & V_196 )
&& ( V_4 < V_28 ) );
if ( V_4 > 0 && ! ( V_152 . V_167 & V_196 ) ) {
if ( V_4 == V_28 )
return - 1 ;
V_150 = ( T_6 ) sizeof( int ) ;
V_4 = F_14 ( V_13 -> V_11 , V_25 , V_197 , & V_108 , & V_150 ) ;
if ( V_4 >= 0 )
F_15 ( V_108 >= 18445 ) ;
V_150 = ( T_6 ) sizeof( int ) ;
V_4 =
F_14 ( V_13 -> V_11 , V_121 , V_133 ,
& V_108 , & V_150 ) ;
if ( V_4 >= 0 )
F_15 ( V_108 >= 18445 ) ;
F_15 ( ! ( V_152 . V_167 & V_187 ) ) ;
memset ( V_27 , 0 , V_28 ) ;
F_26 ( V_13 ) ;
return - 1 ;
}
F_24 ( V_13 ) ;
if ( V_4 < 0 ) {
if ( F_25 ( V_4 ) ) {
F_26 ( V_13 ) ;
V_6 -> V_35 = F_27 () ;
}
}
if ( ! V_6 -> V_198 ) {
int V_199 , V_109 = 0 , V_110 = 0 ;
unsigned char * V_111 ;
struct V_114 * V_115 ;
V_150 =
( T_6 ) ( sizeof( V_124 ) + 256 * sizeof( V_125 ) ) ;
V_115 = F_63 ( V_150 ) ;
if ( V_115 == NULL ) {
F_64 ( V_200 , V_201 ) ;
return - 1 ;
}
memset ( V_115 , 0 , V_150 ) ;
V_199 = F_14 ( V_13 -> V_11 , V_121 , V_202 ,
V_115 , & V_150 ) ;
if ( V_199 >= 0 )
for ( V_111 = ( unsigned char * ) V_115 -> V_127 ;
V_111 < ( unsigned char * ) V_115 + V_150 ;
V_111 += sizeof( V_125 ) ) {
if ( * V_111 == V_120 )
V_109 = 1 ;
if ( * V_111 == V_123 )
V_110 = 1 ;
}
F_9 ( V_115 ) ;
if ( ! V_109 || ! V_110 ) {
F_64 ( V_200 , V_203 ) ;
return - 1 ;
}
V_6 -> V_198 = 1 ;
}
}
return ( V_4 ) ;
}
static int F_62 ( T_2 * V_13 , const char * V_36 , int V_37 )
{
int V_4 ;
T_7 * V_6 = ( T_7 * ) V_13 -> V_7 ;
struct V_204 * V_205 = & ( V_6 -> V_206 ) ;
struct V_207 * V_208 = & ( V_6 -> V_135 ) ;
struct V_204 V_209 ;
struct V_153 V_154 [ 1 ] ;
struct V_151 V_152 ;
struct V_155 * V_156 ;
# if F_12 ( V_210 ) && F_12 ( V_211 )
char V_157 [ F_65 ( sizeof( struct V_212 ) ) +
F_65 ( sizeof( struct V_213 ) ) ] ;
struct V_212 * V_206 ;
struct V_213 * V_135 ;
# else
char V_157 [ F_65 ( sizeof( struct V_178 ) ) ] ;
struct V_178 * V_179 ;
# endif
F_20 () ;
if ( V_36 [ 0 ] != 23 ) {
memset ( & V_209 , 0 , sizeof( V_209 ) ) ;
# ifdef F_66
V_209 . V_214 = F_66 ;
# endif
V_205 = & V_209 ;
}
if ( V_6 -> V_215 ) {
V_4 = F_67 ( V_13 ) ;
if ( V_4 < 0 ) {
return - 1 ;
}
if ( V_4 == 0 ) {
char * V_216 ;
V_6 -> V_137 . V_107 = V_13 ;
if ( ( V_216 = F_63 ( V_37 ) ) == NULL ) {
F_64 ( V_217 , V_201 ) ;
return - 1 ;
}
F_9 ( V_6 -> V_137 . V_6 ) ;
V_6 -> V_137 . V_6 = V_216 ;
memcpy ( V_6 -> V_137 . V_6 , V_36 , V_37 ) ;
V_6 -> V_137 . V_192 = V_37 ;
return V_37 ;
}
}
V_154 [ 0 ] . V_159 = ( char * ) V_36 ;
V_154 [ 0 ] . V_160 = V_37 ;
V_152 . V_161 = NULL ;
V_152 . V_162 = 0 ;
V_152 . V_163 = V_154 ;
V_152 . V_164 = 1 ;
V_152 . V_165 = ( V_218 ) V_157 ;
V_152 . V_166 = 0 ;
V_152 . V_167 = 0 ;
# if F_12 ( V_210 ) && F_12 ( V_211 )
V_156 = (struct V_155 * ) V_157 ;
V_156 -> V_168 = V_121 ;
V_156 -> V_169 = V_210 ;
V_156 -> V_219 = F_68 ( sizeof( struct V_212 ) ) ;
V_206 = (struct V_212 * ) F_60 ( V_156 ) ;
memset ( V_206 , 0 , sizeof( * V_206 ) ) ;
V_206 -> V_220 = V_205 -> V_220 ;
V_206 -> V_214 = V_205 -> V_214 ;
V_206 -> V_221 = V_205 -> V_221 ;
V_206 -> V_222 = V_205 -> V_222 ;
V_152 . V_166 += F_65 ( sizeof( struct V_212 ) ) ;
V_156 =
(struct V_155 * ) & V_157 [ F_65 ( sizeof( struct V_212 ) ) ] ;
V_156 -> V_168 = V_121 ;
V_156 -> V_169 = V_211 ;
V_156 -> V_219 = F_68 ( sizeof( struct V_213 ) ) ;
V_135 = (struct V_213 * ) F_60 ( V_156 ) ;
memset ( V_135 , 0 , sizeof( * V_135 ) ) ;
V_135 -> V_136 = V_208 -> V_136 ;
V_135 -> V_223 = V_208 -> V_223 ;
V_152 . V_166 += F_65 ( sizeof( struct V_213 ) ) ;
# else
V_156 = (struct V_155 * ) V_157 ;
V_156 -> V_168 = V_121 ;
V_156 -> V_169 = F_61 ;
V_156 -> V_219 = F_68 ( sizeof( struct V_178 ) ) ;
V_179 = (struct V_178 * ) F_60 ( V_156 ) ;
memset ( V_179 , 0 , sizeof( * V_179 ) ) ;
V_179 -> V_180 = V_205 -> V_220 ;
V_179 -> V_182 = V_205 -> V_214 ;
# ifdef F_69
V_179 -> V_182 |= V_208 -> V_136 ;
# endif
V_179 -> V_183 = V_205 -> V_221 ;
V_179 -> V_186 = V_205 -> V_222 ;
V_179 -> V_224 = V_208 -> V_223 ;
V_152 . V_166 += F_65 ( sizeof( struct V_178 ) ) ;
# endif
V_4 = F_70 ( V_13 -> V_11 , & V_152 , 0 ) ;
F_24 ( V_13 ) ;
if ( V_4 <= 0 ) {
if ( F_25 ( V_4 ) ) {
F_33 ( V_13 ) ;
V_6 -> V_35 = F_27 () ;
}
}
return ( V_4 ) ;
}
static long F_71 ( T_2 * V_13 , int V_44 , long V_11 , void * V_7 )
{
long V_4 = 1 ;
T_7 * V_6 = NULL ;
T_6 V_51 = 0 ;
struct V_145 V_146 ;
struct V_225 * V_226 = NULL ;
V_6 = ( T_7 * ) V_13 -> V_7 ;
switch ( V_44 ) {
case V_74 :
V_6 -> V_75 = 16384 ;
V_4 = V_6 -> V_75 ;
break;
case V_79 :
V_6 -> V_75 = 16384 ;
V_4 = V_6 -> V_75 ;
break;
case V_80 :
case V_64 :
V_4 = - 1 ;
break;
case V_82 :
break;
case V_101 :
V_4 = 0 ;
break;
case V_227 :
if ( V_11 > 0 )
V_6 -> V_228 = 1 ;
else
V_6 -> V_228 = 0 ;
V_4 =
F_17 ( V_13 -> V_11 , V_121 , V_229 ,
& V_6 -> V_228 , sizeof( int ) ) ;
break;
case V_230 :
V_51 = sizeof( struct V_145 ) ;
V_4 =
F_14 ( V_13 -> V_11 , V_121 , V_231 , & V_146 ,
& V_51 ) ;
if ( V_4 < 0 )
break;
V_51 = sizeof( struct V_225 ) + 64 * sizeof( V_125 ) ;
V_226 = F_63 ( V_51 ) ;
if ( V_226 == NULL ) {
V_4 = - 1 ;
break;
}
memset ( V_226 , 0 , V_51 ) ;
V_226 -> V_232 = V_146 . V_147 + 1 ;
# ifndef F_69
V_226 -> V_233 = 64 ;
# endif
memcpy ( & V_226 -> V_234 [ 0 ] , V_7 , 64 * sizeof( V_125 ) ) ;
V_4 =
F_17 ( V_13 -> V_11 , V_121 , V_235 , V_226 ,
V_51 ) ;
F_9 ( V_226 ) ;
V_226 = NULL ;
if ( V_4 < 0 )
break;
V_4 = F_17 ( V_13 -> V_11 , V_121 , V_231 ,
& V_146 , sizeof( struct V_145 ) ) ;
if ( V_4 < 0 )
break;
break;
case V_236 :
V_51 = sizeof( struct V_145 ) ;
V_4 =
F_14 ( V_13 -> V_11 , V_121 , V_231 , & V_146 ,
& V_51 ) ;
if ( V_4 < 0 )
break;
V_146 . V_147 = V_146 . V_147 + 1 ;
V_4 = F_17 ( V_13 -> V_11 , V_121 , V_231 ,
& V_146 , sizeof( struct V_145 ) ) ;
if ( V_4 < 0 )
break;
V_6 -> V_237 = 1 ;
case V_238 :
if ( V_44 == V_238 )
V_6 -> V_239 = 1 ;
if ( V_6 -> V_239 == 1 && V_6 -> V_237 == 1 ) {
V_51 = sizeof( struct V_145 ) ;
V_4 =
F_14 ( V_13 -> V_11 , V_121 , V_231 ,
& V_146 , & V_51 ) ;
if ( V_4 < 0 )
break;
V_146 . V_147 = V_146 . V_147 - 1 ;
# ifdef F_72
V_51 = sizeof( struct V_145 ) ;
V_4 = F_17 ( V_13 -> V_11 , V_121 , F_72 ,
& V_146 , V_51 ) ;
if ( V_4 < 0 )
break;
# endif
# ifndef F_46
if ( V_146 . V_147 > 0 ) {
V_146 . V_147 = V_146 . V_147 - 1 ;
V_4 = F_17 ( V_13 -> V_11 , V_121 , V_149 ,
& V_146 , sizeof( struct V_145 ) ) ;
if ( V_4 < 0 )
break;
}
# endif
V_6 -> V_239 = 0 ;
V_6 -> V_237 = 0 ;
}
break;
case V_240 :
if ( V_11 > ( long ) sizeof( struct V_204 ) )
V_11 = sizeof( struct V_204 ) ;
memcpy ( V_7 , & ( V_6 -> V_206 ) , V_11 ) ;
V_4 = V_11 ;
break;
case V_241 :
if ( V_11 > ( long ) sizeof( struct V_204 ) )
V_11 = sizeof( struct V_204 ) ;
memcpy ( & ( V_6 -> V_206 ) , V_7 , V_11 ) ;
break;
case V_242 :
if ( V_11 > ( long ) sizeof( struct V_243 ) )
V_11 = sizeof( struct V_243 ) ;
memcpy ( V_7 , & V_6 -> V_158 , V_11 ) ;
V_4 = V_11 ;
break;
case V_244 :
if ( V_11 > ( long ) sizeof( struct V_243 ) )
V_11 = sizeof( struct V_243 ) ;
memcpy ( & ( V_6 -> V_158 ) , V_7 , V_11 ) ;
break;
case V_245 :
if ( V_11 > ( long ) sizeof( struct V_207 ) )
V_11 = sizeof( struct V_207 ) ;
memcpy ( V_7 , & ( V_6 -> V_135 ) , V_11 ) ;
V_4 = V_11 ;
break;
case V_246 :
if ( V_11 > ( long ) sizeof( struct V_207 ) )
V_11 = sizeof( struct V_207 ) ;
memcpy ( & ( V_6 -> V_135 ) , V_7 , V_11 ) ;
break;
case V_247 :
if ( V_11 > 0 )
V_6 -> V_215 = 1 ;
else
V_6 -> V_215 = 0 ;
break;
default:
V_4 = F_39 ( V_13 , V_44 , V_11 , V_7 ) ;
break;
}
return ( V_4 ) ;
}
int F_73 ( T_2 * V_13 ,
void (* V_194) ( T_2 * V_107 ,
void
* V_248 ,
void * V_249 ) ,
void * V_248 )
{
T_7 * V_6 = ( T_7 * ) V_13 -> V_7 ;
if ( V_194 != NULL ) {
V_6 -> V_194 = V_194 ;
V_6 -> V_195 = V_248 ;
} else
return - 1 ;
return 0 ;
}
int F_67 ( T_2 * V_13 )
{
int V_250 = 0 ;
int V_251 = 0 ;
int V_105 , V_4 ;
union V_138 V_139 ;
struct V_151 V_152 ;
struct V_153 V_154 ;
# ifdef F_47
struct V_116 V_117 ;
# else
struct V_118 V_117 ;
T_6 V_191 ;
# endif
T_7 * V_6 = ( T_7 * ) V_13 -> V_7 ;
# ifdef F_47
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
V_117 . V_128 = 0 ;
V_117 . V_129 = V_190 ;
V_117 . V_130 = 1 ;
V_4 =
F_17 ( V_13 -> V_11 , V_121 , F_47 , & V_117 ,
sizeof( struct V_116 ) ) ;
# else
V_191 = sizeof( struct V_118 ) ;
V_4 = F_14 ( V_13 -> V_11 , V_121 , V_131 , & V_117 , & V_191 ) ;
if ( V_4 < 0 )
return - 1 ;
V_117 . V_193 = 1 ;
V_4 =
F_17 ( V_13 -> V_11 , V_121 , V_131 , & V_117 ,
sizeof( struct V_118 ) ) ;
# endif
if ( V_4 < 0 )
return - 1 ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_154 . V_159 = ( char * ) & V_139 ;
V_154 . V_160 = sizeof( union V_138 ) ;
V_152 . V_161 = NULL ;
V_152 . V_162 = 0 ;
V_152 . V_163 = & V_154 ;
V_152 . V_164 = 1 ;
V_152 . V_165 = NULL ;
V_152 . V_166 = 0 ;
V_152 . V_167 = 0 ;
V_105 = F_56 ( V_13 -> V_11 , & V_152 , V_32 ) ;
if ( V_105 <= 0 ) {
if ( ( V_105 < 0 ) && ( F_27 () != V_92 )
&& ( F_27 () != V_252 ) )
return - 1 ;
else
return 0 ;
}
while ( V_152 . V_167 & V_187 ) {
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_154 . V_159 = ( char * ) & V_139 ;
V_154 . V_160 = sizeof( union V_138 ) ;
V_152 . V_161 = NULL ;
V_152 . V_162 = 0 ;
V_152 . V_163 = & V_154 ;
V_152 . V_164 = 1 ;
V_152 . V_165 = NULL ;
V_152 . V_166 = 0 ;
V_152 . V_167 = 0 ;
V_105 = F_56 ( V_13 -> V_11 , & V_152 , 0 ) ;
if ( V_105 <= 0 ) {
if ( ( V_105 < 0 ) && ( F_27 () != V_92 )
&& ( F_27 () != V_252 ) )
return - 1 ;
else
return V_250 ;
}
if ( V_139 . V_188 . V_189 == V_190 ) {
V_250 = 1 ;
# ifdef F_47
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
V_117 . V_128 = 0 ;
V_117 . V_129 = V_190 ;
V_117 . V_130 = 0 ;
V_4 =
F_17 ( V_13 -> V_11 , V_121 , F_47 , & V_117 ,
sizeof( struct V_116 ) ) ;
# else
V_191 = ( T_6 ) sizeof( struct V_118 ) ;
V_4 =
F_14 ( V_13 -> V_11 , V_121 , V_131 , & V_117 ,
& V_191 ) ;
if ( V_4 < 0 )
return - 1 ;
V_117 . V_193 = 0 ;
V_4 =
F_17 ( V_13 -> V_11 , V_121 , V_131 , & V_117 ,
sizeof( struct V_118 ) ) ;
# endif
if ( V_4 < 0 )
return - 1 ;
}
# ifdef F_46
if ( V_139 . V_188 . V_189 == F_46 )
F_54 ( V_13 , & V_139 ) ;
# endif
if ( V_6 -> V_194 != NULL )
V_6 -> V_194 ( V_13 , V_6 -> V_195 ,
( void * ) & V_139 ) ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_154 . V_159 = ( char * ) & V_139 ;
V_154 . V_160 = sizeof( union V_138 ) ;
V_152 . V_161 = NULL ;
V_152 . V_162 = 0 ;
V_152 . V_163 = & V_154 ;
V_152 . V_164 = 1 ;
V_152 . V_165 = NULL ;
V_152 . V_166 = 0 ;
V_152 . V_167 = 0 ;
if ( V_250 ) {
V_251 = F_74 ( V_13 -> V_11 , V_253 , 0 ) ;
F_74 ( V_13 -> V_11 , V_254 , V_255 ) ;
}
V_105 = F_56 ( V_13 -> V_11 , & V_152 , V_32 ) ;
if ( V_250 ) {
F_74 ( V_13 -> V_11 , V_254 , V_251 ) ;
}
if ( V_105 <= 0 ) {
if ( ( V_105 < 0 ) && ( F_27 () != V_92 )
&& ( F_27 () != V_252 ) )
return - 1 ;
else
return V_250 ;
}
}
return V_250 ;
}
int F_75 ( T_2 * V_13 )
{
int V_105 , V_251 ;
union V_138 V_139 ;
struct V_151 V_152 ;
struct V_153 V_154 ;
T_7 * V_6 = ( T_7 * ) V_13 -> V_7 ;
do {
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_154 . V_159 = ( char * ) & V_139 ;
V_154 . V_160 = sizeof( union V_138 ) ;
V_152 . V_161 = NULL ;
V_152 . V_162 = 0 ;
V_152 . V_163 = & V_154 ;
V_152 . V_164 = 1 ;
V_152 . V_165 = NULL ;
V_152 . V_166 = 0 ;
V_152 . V_167 = 0 ;
V_251 = F_74 ( V_13 -> V_11 , V_253 , 0 ) ;
F_74 ( V_13 -> V_11 , V_254 , V_255 ) ;
V_105 = F_56 ( V_13 -> V_11 , & V_152 , V_32 ) ;
F_74 ( V_13 -> V_11 , V_254 , V_251 ) ;
if ( V_105 > 0 && ( V_152 . V_167 & V_187 ) ) {
# ifdef F_46
if ( V_139 . V_188 . V_189 == F_46 )
F_54 ( V_13 , & V_139 ) ;
# endif
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_154 . V_159 = ( char * ) & V_139 ;
V_154 . V_160 = sizeof( union V_138 ) ;
V_152 . V_161 = NULL ;
V_152 . V_162 = 0 ;
V_152 . V_163 = & V_154 ;
V_152 . V_164 = 1 ;
V_152 . V_165 = NULL ;
V_152 . V_166 = 0 ;
V_152 . V_167 = 0 ;
V_105 = F_56 ( V_13 -> V_11 , & V_152 , 0 ) ;
if ( V_6 -> V_194 != NULL )
V_6 -> V_194 ( V_13 , V_6 -> V_195 ,
( void * ) & V_139 ) ;
}
} while ( V_105 > 0 && ( V_152 . V_167 & V_187 ) );
if ( V_105 > 0 )
return 1 ;
else
return 0 ;
}
static int F_76 ( T_2 * V_103 , const char * V_104 )
{
int V_105 , V_4 ;
V_105 = strlen ( V_104 ) ;
V_4 = F_62 ( V_103 , V_104 , V_105 ) ;
return ( V_4 ) ;
}
static int F_25 ( int V_16 )
{
int V_256 ;
if ( ( V_16 == 0 ) || ( V_16 == - 1 ) ) {
V_256 = F_27 () ;
# if F_12 ( F_13 )
# endif
return ( F_77 ( V_256 ) ) ;
}
return ( 0 ) ;
}
int F_77 ( int V_256 )
{
switch ( V_256 ) {
# if F_12 ( F_13 )
# if F_12 ( V_257 )
case V_257 :
# endif
# endif
# ifdef V_252
# ifdef V_257
# if V_257 != V_252
case V_252 :
# endif
# else
case V_252 :
# endif
# endif
# ifdef F_78
case F_78 :
# endif
# ifdef V_92
# if V_252 != V_92
case V_92 :
# endif
# endif
# ifdef F_79
case F_79 :
# endif
# ifdef F_80
case F_80 :
# endif
# ifdef F_81
case F_81 :
# endif
return ( 1 ) ;
default:
break;
}
return ( 0 ) ;
}
static void F_16 ( struct V_21 * V_258 )
{
# if F_12 ( V_259 )
T_8 V_260 ;
union {
unsigned T_9 V_261 ;
T_10 V_262 ;
} V_263 ;
F_82 ( & V_260 ) ;
F_83 ( & V_260 , & V_263 . V_262 ) ;
# ifdef F_84
V_263 . V_261 -= 116444736000000000ULL ;
# else
V_263 . V_261 -= 116444736000000000UI64 ;
# endif
V_258 -> V_19 = ( long ) ( V_263 . V_261 / 10000000 ) ;
V_258 -> V_20 = ( ( int ) ( V_263 . V_261 % 10000000 ) ) / 10 ;
# elif F_12 ( V_264 )
struct V_265 V_266 ;
F_85 ( & V_266 ) ;
V_258 -> V_19 = ( long ) V_266 . time ;
V_258 -> V_20 = ( long ) V_266 . V_267 * 1000 ;
# else
F_86 ( V_258 , NULL ) ;
# endif
}
