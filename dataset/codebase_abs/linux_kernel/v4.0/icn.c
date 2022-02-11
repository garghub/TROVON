static void
F_1 ( T_1 * V_1 , int V_2 )
{
struct V_3 * V_4 = & V_1 -> V_5 [ V_2 ] ;
struct V_6 * V_7 ;
F_2 ( V_4 ) ;
V_1 -> V_8 [ V_2 ] = 0 ;
V_1 -> V_9 [ V_2 ] = 0 ;
if ( ( V_7 = V_1 -> V_10 [ V_2 ] ) ) {
V_1 -> V_10 [ V_2 ] = NULL ;
F_3 ( V_7 ) ;
}
}
static inline void
F_4 ( unsigned short V_11 ,
unsigned long V_12 ,
int V_13 ,
int V_14 )
{
register T_2 V_15 ;
register T_2 V_16 ;
for ( V_15 = V_13 , V_16 = V_14 ; V_16 > 0 ; V_15 -- , V_16 -- )
F_5 ( ( T_2 ) ( ( V_12 >> V_15 ) & 1 ) ? 0xff : 0 , V_11 ) ;
}
static inline void
F_6 ( T_1 * V_1 )
{
F_5 ( 0 , V_17 ) ;
}
static inline void
F_7 ( T_1 * V_1 )
{
F_5 ( 0xff , V_17 ) ;
}
static inline void
F_8 ( T_1 * V_1 , int V_2 )
{
#ifdef F_9
F_10 ( V_18 L_1 , V_19 . V_2 , V_2 ) ;
#endif
if ( ( V_2 == V_19 . V_2 ) && ( V_1 == V_19 . V_20 ) )
return;
if ( V_19 . V_20 )
F_6 ( V_19 . V_20 ) ;
F_4 ( V_21 , V_22 [ V_2 ] , 3 , 4 ) ;
F_7 ( V_1 ) ;
V_19 . V_20 = V_1 ;
V_19 . V_2 = V_2 ;
#ifdef F_9
F_10 ( V_18 L_2 ) ;
#endif
}
static inline int
F_11 ( T_1 * V_1 , int V_2 )
{
register int V_23 ;
#ifdef F_9
F_10 ( V_18 L_3 , V_2 ) ;
#endif
if ( ( V_19 . V_2 == V_2 ) && ( V_1 == V_19 . V_20 ) ) {
V_19 . V_24 ++ ;
V_23 = 1 ;
#ifdef F_9
F_10 ( V_18 L_4 , V_2 ) ;
#endif
} else {
V_23 = 0 ;
#ifdef F_9
F_10 ( V_18 L_5 , V_2 , V_19 . V_2 ) ;
#endif
}
return V_23 ;
}
static inline void
F_12 ( void )
{
#ifdef F_9
F_10 ( V_18 L_6 , V_19 . V_24 ) ;
#endif
if ( V_19 . V_24 > 0 )
V_19 . V_24 -- ;
}
static inline void
F_13 ( void )
{
T_3 V_25 ;
F_14 ( & V_19 . V_26 , V_25 ) ;
F_12 () ;
F_15 ( & V_19 . V_26 , V_25 ) ;
}
static inline int
F_16 ( T_1 * V_1 , int V_2 )
{
T_3 V_25 ;
#ifdef F_9
F_10 ( V_18 L_7 , V_2 , V_19 . V_2 ,
V_19 . V_24 ) ;
#endif
F_14 ( & V_19 . V_26 , V_25 ) ;
if ( ( ! V_19 . V_24 ) ||
( ( V_19 . V_2 == V_2 ) && ( V_19 . V_20 == V_1 ) ) ) {
V_19 . V_24 ++ ;
F_8 ( V_1 , V_2 ) ;
F_15 ( & V_19 . V_26 , V_25 ) ;
#ifdef F_9
F_10 ( V_18 L_8 , V_2 ) ;
#endif
return 1 ;
}
F_15 ( & V_19 . V_26 , V_25 ) ;
#ifdef F_9
F_10 ( V_18 L_9 , V_2 ) ;
#endif
return 0 ;
}
static inline void
F_17 ( T_1 * V_1 , int V_2 )
{
T_3 V_25 ;
#ifdef F_9
F_10 ( V_18 L_10 , V_2 , V_19 . V_24 ) ;
#endif
F_14 ( & V_19 . V_26 , V_25 ) ;
if ( V_19 . V_24 > 0 )
V_19 . V_24 -- ;
if ( ! V_19 . V_24 )
F_8 ( V_1 , V_2 ) ;
F_15 ( & V_19 . V_26 , V_25 ) ;
}
static void
F_18 ( int V_2 , T_1 * V_1 )
{
int V_27 = V_2 + ( ( V_1 -> V_28 ) ? 2 : 0 ) ;
int V_29 ;
int V_30 ;
struct V_6 * V_7 ;
if ( F_16 ( V_1 , V_27 ) ) {
while ( V_31 ) {
V_30 = F_19 ( & V_32 ) ;
if ( ( V_1 -> V_33 [ V_2 ] + V_30 ) > 4000 ) {
F_10 ( V_34
L_11 ,
V_35 ,
V_2 + 1 ) ;
V_1 -> V_33 [ V_2 ] = 0 ;
V_29 = 0 ;
} else {
F_20 ( & V_1 -> V_36 [ V_2 ] [ V_1 -> V_33 [ V_2 ] ] ,
& V_37 , V_30 ) ;
V_1 -> V_33 [ V_2 ] += V_30 ;
V_29 = F_19 ( & V_38 ) ;
}
V_39 ;
F_17 ( V_1 , V_27 & 2 ) ;
if ( ! V_29 ) {
if ( ( V_30 = V_1 -> V_33 [ V_2 ] ) ) {
if ( ! ( V_7 = F_21 ( V_30 ) ) ) {
F_10 ( V_34 L_12 ) ;
break;
}
memcpy ( F_22 ( V_7 , V_30 ) , V_1 -> V_36 [ V_2 ] , V_30 ) ;
V_1 -> V_33 [ V_2 ] = 0 ;
V_1 -> V_40 . V_41 ( V_1 -> V_42 , V_2 , V_7 ) ;
}
}
if ( ! F_16 ( V_1 , V_27 ) )
break;
}
F_17 ( V_1 , V_27 & 2 ) ;
}
}
static void
F_23 ( int V_2 , T_1 * V_1 )
{
int V_27 = V_2 + ( ( V_1 -> V_28 ) ? 2 : 0 ) ;
int V_30 ;
unsigned long V_25 ;
struct V_6 * V_7 ;
T_4 V_43 ;
if ( ! ( V_1 -> V_9 [ V_2 ] || V_1 -> V_10 [ V_2 ] ||
! F_24 ( & V_1 -> V_5 [ V_2 ] ) ) )
return;
if ( F_16 ( V_1 , V_27 ) ) {
while ( V_44 &&
( V_1 -> V_9 [ V_2 ] ||
! F_24 ( & V_1 -> V_5 [ V_2 ] ) ||
V_1 -> V_10 [ V_2 ] ) ) {
F_14 ( & V_1 -> V_45 , V_25 ) ;
if ( V_1 -> V_46 [ V_2 ] ) {
F_15 ( & V_1 -> V_45 , V_25 ) ;
break;
}
V_1 -> V_46 [ V_2 ] ++ ;
F_15 ( & V_1 -> V_45 , V_25 ) ;
V_7 = V_1 -> V_10 [ V_2 ] ;
if ( ! V_7 ) {
V_7 = F_25 ( & V_1 -> V_5 [ V_2 ] ) ;
if ( V_7 ) {
if ( * ( F_26 ( V_7 , 1 ) ) )
V_1 -> V_8 [ V_2 ] = V_7 -> V_47 ;
else
V_1 -> V_8 [ V_2 ] = 0 ;
}
}
if ( ! V_7 )
break;
if ( V_7 -> V_47 > V_48 ) {
F_27 ( 0xff , & V_49 ) ;
V_30 = V_48 ;
} else {
F_27 ( 0x0 , & V_49 ) ;
V_30 = V_7 -> V_47 ;
}
F_27 ( V_30 , & V_50 ) ;
F_28 ( & V_51 , V_7 -> V_52 , V_30 ) ;
F_26 ( V_7 , V_30 ) ;
V_53 ;
F_17 ( V_1 , V_27 & 2 ) ;
F_14 ( & V_1 -> V_45 , V_25 ) ;
V_1 -> V_9 [ V_2 ] -= V_30 ;
if ( ! V_7 -> V_47 ) {
if ( V_1 -> V_10 [ V_2 ] )
V_1 -> V_10 [ V_2 ] = NULL ;
V_1 -> V_46 [ V_2 ] = 0 ;
F_15 ( & V_1 -> V_45 , V_25 ) ;
F_3 ( V_7 ) ;
if ( V_1 -> V_8 [ V_2 ] ) {
V_43 . V_54 = V_55 ;
V_43 . V_56 = V_1 -> V_42 ;
V_43 . V_57 = V_2 ;
V_43 . V_58 . V_59 = V_1 -> V_8 [ V_2 ] ;
V_1 -> V_40 . V_60 ( & V_43 ) ;
}
} else {
V_1 -> V_10 [ V_2 ] = V_7 ;
V_1 -> V_46 [ V_2 ] = 0 ;
F_15 ( & V_1 -> V_45 , V_25 ) ;
}
if ( ! F_16 ( V_1 , V_27 ) )
break;
}
F_17 ( V_1 , V_27 & 2 ) ;
}
}
static void
F_29 ( unsigned long V_52 )
{
T_1 * V_1 = ( T_1 * ) V_52 ;
unsigned long V_25 ;
if ( V_1 -> V_25 & V_61 ) {
F_18 ( 0 , V_1 ) ;
F_23 ( 0 , V_1 ) ;
}
if ( V_1 -> V_25 & V_62 ) {
F_18 ( 1 , V_1 ) ;
F_23 ( 1 , V_1 ) ;
}
if ( V_1 -> V_25 & ( V_61 | V_62 ) ) {
F_14 ( & V_1 -> V_45 , V_25 ) ;
F_30 ( & V_1 -> V_63 , V_64 + V_65 ) ;
V_1 -> V_25 |= V_66 ;
F_15 ( & V_1 -> V_45 , V_25 ) ;
} else
V_1 -> V_25 &= ~ V_66 ;
}
static void
F_31 ( T_2 * V_67 , int V_2 , T_1 * V_1 )
{
T_5 * V_15 = V_68 ;
int V_69 = - 1 ;
unsigned long V_25 ;
T_4 V_43 ;
while ( V_15 -> V_70 ) {
if ( ! strncmp ( V_67 , V_15 -> V_70 , strlen ( V_15 -> V_70 ) ) ) {
V_43 . V_54 = V_15 -> V_54 ;
V_69 = V_15 -> V_69 ;
break;
}
V_15 ++ ;
}
if ( V_69 == - 1 )
return;
V_43 . V_56 = V_1 -> V_42 ;
V_43 . V_57 = V_2 ;
switch ( V_69 ) {
case 11 :
F_14 ( & V_1 -> V_45 , V_25 ) ;
F_1 ( V_1 , V_2 ) ;
V_1 -> V_33 [ V_2 ] = 0 ;
if ( V_1 -> V_25 &
( ( V_2 ) ? V_62 : V_61 ) ) {
T_4 V_71 ;
V_1 -> V_25 &= ~ ( ( V_2 ) ?
V_62 : V_61 ) ;
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
V_71 . V_56 = V_1 -> V_42 ;
V_71 . V_57 = V_2 ;
V_71 . V_54 = V_72 ;
F_15 ( & V_1 -> V_45 , V_25 ) ;
V_1 -> V_40 . V_60 ( & V_43 ) ;
} else
F_15 ( & V_1 -> V_45 , V_25 ) ;
break;
case 1 :
F_14 ( & V_1 -> V_45 , V_25 ) ;
F_1 ( V_1 , V_2 ) ;
V_1 -> V_25 |= ( V_2 ) ?
V_62 : V_61 ;
F_15 ( & V_1 -> V_45 , V_25 ) ;
break;
case 2 :
F_14 ( & V_1 -> V_45 , V_25 ) ;
V_1 -> V_25 &= ~ ( ( V_2 ) ?
V_62 : V_61 ) ;
F_1 ( V_1 , V_2 ) ;
V_1 -> V_33 [ V_2 ] = 0 ;
F_15 ( & V_1 -> V_45 , V_25 ) ;
break;
case 3 :
{
char * V_73 = V_67 + 6 ;
char * V_15 = strchr ( V_73 , ',' ) ;
* V_15 ++ = '\0' ;
F_32 ( V_43 . V_58 . V_74 . V_75 , V_73 ,
sizeof( V_43 . V_58 . V_74 . V_75 ) ) ;
V_15 = strchr ( V_73 = V_15 , ',' ) ;
* V_15 ++ = '\0' ;
if ( ! strlen ( V_73 ) )
V_43 . V_58 . V_74 . V_76 = 0 ;
else
V_43 . V_58 . V_74 . V_76 =
F_33 ( V_73 , NULL , 10 ) ;
V_15 = strchr ( V_73 = V_15 , ',' ) ;
* V_15 ++ = '\0' ;
if ( ! strlen ( V_73 ) )
V_43 . V_58 . V_74 . V_77 = 0 ;
else
V_43 . V_58 . V_74 . V_77 =
F_33 ( V_73 , NULL , 10 ) ;
F_32 ( V_43 . V_58 . V_74 . V_78 , V_15 ,
sizeof( V_43 . V_58 . V_74 . V_78 ) ) ;
}
V_43 . V_58 . V_74 . V_79 = 0 ;
V_43 . V_58 . V_74 . V_80 = 0 ;
break;
case 4 :
sprintf ( V_43 . V_58 . V_74 . V_75 , L_13 , V_1 -> V_42 ) ;
sprintf ( V_43 . V_58 . V_74 . V_78 , L_14 , V_2 + 1 ) ;
V_43 . V_58 . V_74 . V_76 = 7 ;
V_43 . V_58 . V_74 . V_77 = 0 ;
V_43 . V_58 . V_74 . V_79 = 0 ;
V_43 . V_58 . V_74 . V_80 = 0 ;
break;
case 5 :
F_32 ( V_43 . V_58 . V_81 , V_67 + 3 , sizeof( V_43 . V_58 . V_81 ) ) ;
break;
case 6 :
snprintf ( V_43 . V_58 . V_81 , sizeof( V_43 . V_58 . V_81 ) , L_14 ,
( int ) F_33 ( V_67 + 7 , NULL , 16 ) ) ;
break;
case 7 :
V_67 += 3 ;
if ( strlen ( V_67 ) == 4 )
snprintf ( V_43 . V_58 . V_81 , sizeof( V_43 . V_58 . V_81 ) , L_15 ,
V_67 + 2 , * V_67 , * ( V_67 + 1 ) ) ;
else
F_32 ( V_43 . V_58 . V_81 , V_67 + 1 , sizeof( V_43 . V_58 . V_81 ) ) ;
break;
case 8 :
F_14 ( & V_1 -> V_45 , V_25 ) ;
V_1 -> V_25 &= ~ V_61 ;
F_1 ( V_1 , 0 ) ;
V_1 -> V_33 [ 0 ] = 0 ;
F_15 ( & V_1 -> V_45 , V_25 ) ;
V_43 . V_57 = 0 ;
V_43 . V_56 = V_1 -> V_42 ;
V_1 -> V_40 . V_60 ( & V_43 ) ;
V_43 . V_54 = V_82 ;
V_43 . V_57 = 0 ;
V_43 . V_56 = V_1 -> V_42 ;
V_1 -> V_40 . V_60 ( & V_43 ) ;
V_43 . V_54 = V_72 ;
F_14 ( & V_1 -> V_45 , V_25 ) ;
V_1 -> V_25 &= ~ V_62 ;
F_1 ( V_1 , 1 ) ;
V_1 -> V_33 [ 1 ] = 0 ;
F_15 ( & V_1 -> V_45 , V_25 ) ;
V_43 . V_57 = 1 ;
V_43 . V_56 = V_1 -> V_42 ;
V_1 -> V_40 . V_60 ( & V_43 ) ;
V_43 . V_54 = V_82 ;
V_43 . V_57 = 1 ;
V_43 . V_56 = V_1 -> V_42 ;
break;
}
V_1 -> V_40 . V_60 ( & V_43 ) ;
return;
}
static void
F_34 ( T_1 * V_1 , unsigned char V_16 )
{
T_3 V_25 ;
F_14 ( & V_1 -> V_45 , V_25 ) ;
* V_1 -> V_83 ++ = ( V_16 == 0xff ) ? '\n' : V_16 ;
if ( V_1 -> V_83 == V_1 -> V_84 ) {
if ( ++ V_1 -> V_84 > V_1 -> V_85 )
V_1 -> V_84 = V_1 -> V_86 ;
}
if ( V_1 -> V_83 > V_1 -> V_85 )
V_1 -> V_83 = V_1 -> V_86 ;
F_15 ( & V_1 -> V_45 , V_25 ) ;
}
static void
F_35 ( unsigned long V_52 )
{
T_1 * V_1 = ( T_1 * ) V_52 ;
int V_27 = V_1 -> V_28 ? 2 : 0 ;
int V_87 = 0 ;
int V_88 ;
T_2 V_16 ;
int V_89 ;
unsigned long V_25 ;
int V_90 ;
T_2 * V_91 ;
T_4 V_43 ;
if ( F_16 ( V_1 , V_27 ) ) {
V_87 = V_92 ;
for ( V_88 = V_87 , V_90 = F_19 ( & V_93 ) ; V_88 > 0 ; V_90 ++ , V_88 -- ) {
V_16 = F_19 ( & V_19 . V_94 -> V_95 . V_96 [ V_90 & 0xff ] ) ;
F_34 ( V_1 , V_16 ) ;
if ( V_16 == 0xff ) {
V_1 -> V_97 [ V_1 -> V_98 ] = 0 ;
V_1 -> V_98 = 0 ;
if ( V_1 -> V_97 [ 0 ] == '0' && V_1 -> V_97 [ 1 ] >= '0' &&
V_1 -> V_97 [ 1 ] <= '2' && V_1 -> V_97 [ 2 ] == ';' ) {
V_89 = ( V_1 -> V_97 [ 1 ] - '0' ) - 1 ;
V_91 = & V_1 -> V_97 [ 3 ] ;
F_31 ( V_91 , V_89 , V_1 ) ;
} else {
V_91 = V_1 -> V_97 ;
if ( ! strncmp ( V_91 , L_16 , 5 ) ) {
T_2 V_99 [ 10 ] ;
T_2 * V_100 = V_99 ;
F_10 ( V_101 L_17 , V_35 , V_91 ) ;
if ( ! strncmp ( V_91 + 7 , L_18 , 2 ) ) {
V_1 -> V_102 = V_103 ;
V_1 -> V_40 . V_104 |= V_105 ;
F_10 ( V_101
L_19 , V_35 ) ;
}
if ( ! strncmp ( V_91 + 7 , L_20 , 2 ) ) {
V_1 -> V_102 = V_106 ;
V_1 -> V_40 . V_104 |= V_107 ;
F_10 ( V_101
L_21 , V_35 ) ;
}
V_91 = strstr ( V_1 -> V_97 , L_22 ) + 3 ;
while ( * V_91 ) {
if ( * V_91 >= '0' && * V_91 <= '9' )
* V_100 ++ = * V_91 ;
V_91 ++ ;
}
* V_100 = '\0' ;
strcat ( V_99 , L_23 ) ;
V_99 [ 3 ] = '\0' ;
V_1 -> V_108 = ( int ) F_33 ( V_99 , NULL , 10 ) ;
continue;
}
}
} else {
V_1 -> V_97 [ V_1 -> V_98 ] = V_16 ;
if ( V_1 -> V_98 < 59 )
V_1 -> V_98 ++ ;
}
}
F_27 ( ( F_19 ( & V_93 ) + V_87 ) & 0xff , & V_93 ) ;
F_13 () ;
}
if ( V_87 ) {
V_43 . V_54 = V_109 ;
V_43 . V_56 = V_1 -> V_42 ;
V_43 . V_57 = V_87 ;
V_1 -> V_40 . V_60 ( & V_43 ) ;
}
F_14 ( & V_1 -> V_45 , V_25 ) ;
if ( V_1 -> V_25 & ( V_61 | V_62 ) )
if ( ! ( V_1 -> V_25 & V_66 ) ) {
V_1 -> V_25 |= V_66 ;
F_36 ( & V_1 -> V_63 ) ;
V_1 -> V_63 . V_110 = F_29 ;
V_1 -> V_63 . V_52 = ( unsigned long ) V_1 ;
V_1 -> V_63 . V_111 = V_64 + V_65 ;
F_37 ( & V_1 -> V_63 ) ;
}
F_30 ( & V_1 -> V_112 , V_64 + V_113 ) ;
F_15 ( & V_1 -> V_45 , V_25 ) ;
}
static int
F_38 ( int V_2 , int V_114 , struct V_6 * V_7 , T_1 * V_1 )
{
int V_47 = V_7 -> V_47 ;
unsigned long V_25 ;
struct V_6 * V_115 ;
if ( V_47 > 4000 ) {
F_10 ( V_34
L_24 ) ;
return - V_116 ;
}
if ( V_47 ) {
if ( ! ( V_1 -> V_25 & ( V_2 ) ? V_62 : V_61 ) )
return 0 ;
if ( V_1 -> V_9 [ V_2 ] > V_117 )
return 0 ;
#warning TODO test headroom or use skb->nb to flag ACK
V_115 = F_39 ( V_7 , V_118 ) ;
if ( V_115 ) {
* ( F_40 ( V_115 , 1 ) ) = V_114 ? 1 : 0 ;
F_41 ( & V_1 -> V_5 [ V_2 ] , V_115 ) ;
F_3 ( V_7 ) ;
} else
V_47 = 0 ;
F_14 ( & V_1 -> V_45 , V_25 ) ;
V_1 -> V_9 [ V_2 ] += V_47 ;
F_15 ( & V_1 -> V_45 , V_25 ) ;
}
return V_47 ;
}
static int
F_42 ( int V_119 )
{
int V_120 = 0 ;
while ( 1 ) {
#ifdef F_43
F_10 ( V_18 L_25 , V_119 ) ;
#endif
if ( F_19 ( & V_19 . V_94 -> V_121 . V_122 ) ||
F_19 ( & V_19 . V_94 -> V_121 . V_123 ) ) {
if ( V_120 ++ > 5 ) {
F_10 ( V_34
L_26 ,
V_119 ) ;
F_13 () ;
return - V_124 ;
}
#ifdef F_43
F_10 ( V_18 L_27 , V_119 ) ;
#endif
F_44 ( V_125 ) ;
} else {
#ifdef F_43
F_10 ( V_18 L_28 , V_119 ) ;
#endif
F_13 () ;
return 0 ;
}
}
}
static int
F_45 ( T_2 T_6 * V_126 , T_1 * V_1 )
{
int V_127 ;
T_2 * V_128 ;
unsigned long V_25 ;
#ifdef F_43
F_10 ( V_18 L_29 , ( T_3 ) V_126 ) ;
#endif
if ( ! ( V_128 = F_46 ( V_129 , V_130 ) ) ) {
F_10 ( V_34 L_30 ) ;
V_127 = - V_131 ;
goto V_132;
}
if ( F_47 ( V_128 , V_126 , V_129 ) ) {
V_127 = - V_133 ;
goto V_134;
}
if ( ! V_1 -> V_135 ) {
if ( ! F_48 ( V_1 -> V_11 , V_136 , V_1 -> V_137 ) ) {
F_10 ( V_34
L_31 ,
V_35 ,
V_1 -> V_11 ,
V_1 -> V_11 + V_136 ) ;
V_127 = - V_138 ;
goto V_134;
}
V_1 -> V_135 = 1 ;
if ( V_1 -> V_139 )
V_1 -> V_140 -> V_135 = 1 ;
}
if ( ! V_19 . V_141 ) {
if ( ! F_49 ( V_19 . V_142 , 0x4000 , L_32 ) ) {
F_10 ( V_34
L_33 , V_19 . V_142 ) ;
V_127 = - V_138 ;
goto V_134;
}
V_19 . V_94 = F_50 ( V_19 . V_142 , 0x4000 ) ;
V_19 . V_141 = 1 ;
}
F_5 ( 0 , V_143 ) ;
F_5 ( 0 , V_17 ) ;
F_4 ( V_144 , 0x0f , 3 , 4 ) ;
F_4 ( V_144 , V_19 . V_142 , 23 , 10 ) ;
#ifdef F_43
F_10 ( V_18 L_34 , V_19 . V_142 ) ;
#endif
F_51 ( 1 ) ;
#ifdef F_43
F_10 ( V_18 L_35 ) ;
#endif
F_14 ( & V_19 . V_26 , V_25 ) ;
F_8 ( V_1 , 0 ) ;
F_11 ( V_1 , 0 ) ;
F_15 ( & V_19 . V_26 , V_25 ) ;
F_51 ( 1 ) ;
F_28 ( V_19 . V_94 , V_128 , V_129 ) ;
#ifdef F_43
F_10 ( V_18 L_36 ) ;
#endif
if ( V_1 -> V_139 ) {
F_51 ( 1 ) ;
#ifdef F_43
F_10 ( V_18 L_37 ) ;
#endif
F_14 ( & V_19 . V_26 , V_25 ) ;
F_12 () ;
F_8 ( V_1 , 2 ) ;
F_11 ( V_1 , 2 ) ;
F_15 ( & V_19 . V_26 , V_25 ) ;
F_51 ( 1 ) ;
F_28 ( V_19 . V_94 , V_128 , V_129 ) ;
#ifdef F_43
F_10 ( V_18 L_36 ) ;
#endif
}
F_51 ( 1 ) ;
F_5 ( 0xff , V_143 ) ;
if ( ( V_127 = F_42 ( V_1 -> V_139 ? 2 : 1 ) ) ) {
goto V_134;
}
if ( ! V_1 -> V_139 ) {
V_127 = 0 ;
goto V_134;
}
#ifdef F_43
F_10 ( V_18 L_35 ) ;
#endif
F_14 ( & V_19 . V_26 , V_25 ) ;
F_8 ( V_1 , 0 ) ;
F_11 ( V_1 , 0 ) ;
F_15 ( & V_19 . V_26 , V_25 ) ;
F_51 ( 1 ) ;
V_127 = ( F_42 ( 1 ) ) ;
V_134:
F_52 ( V_128 ) ;
V_132:
return V_127 ;
}
static int
F_53 ( T_2 T_6 * V_126 , T_1 * V_1 )
{
register T_2 T_6 * V_91 = V_126 ;
T_2 V_128 [ 256 ] ;
T_7 V_88 = V_145 ;
T_7 V_30 ;
int V_120 ;
unsigned long V_25 ;
#ifdef F_43
F_10 ( V_18 L_38 ) ;
#endif
if ( ! F_54 ( V_146 , V_126 , V_145 ) )
return - V_133 ;
V_120 = 0 ;
F_14 ( & V_19 . V_26 , V_25 ) ;
if ( V_1 -> V_28 ) {
F_8 ( V_1 , 2 ) ;
F_11 ( V_1 , 2 ) ;
} else {
F_8 ( V_1 , 0 ) ;
F_11 ( V_1 , 0 ) ;
}
F_15 ( & V_19 . V_26 , V_25 ) ;
while ( V_88 ) {
if ( V_44 ) {
V_30 = V_88 ;
if ( V_30 > 256 )
V_30 = 256 ;
if ( F_47 ( V_128 , V_91 , V_30 ) ) {
F_17 ( V_1 , 0 ) ;
return - V_133 ;
}
F_28 ( & V_50 , V_128 , V_30 ) ;
V_53 ;
V_91 += V_30 ;
V_88 -= V_30 ;
V_120 = 0 ;
} else {
#ifdef F_43
F_10 ( V_18 L_39 ) ;
#endif
if ( V_120 ++ > 5 ) {
F_17 ( V_1 , 0 ) ;
return - V_124 ;
}
F_55 ( 10 ) ;
}
}
F_27 ( 0x20 , & V_147 ) ;
V_120 = 0 ;
while ( 1 ) {
if ( F_19 ( & V_148 ) || F_19 ( & V_149 ) ) {
#ifdef F_43
F_10 ( V_18 L_40 ) ;
#endif
if ( V_120 ++ > 5 ) {
F_10 ( V_34
L_41 ,
V_35 ) ;
#ifdef F_43
F_10 ( V_18 L_42 ) ;
#endif
F_17 ( V_1 , 0 ) ;
return - V_124 ;
}
#ifdef F_43
F_10 ( V_18 L_43 ) ;
#endif
F_44 ( V_125 ) ;
} else {
if ( ( V_1 -> V_28 ) || ( ! V_1 -> V_139 ) ) {
#ifdef F_43
F_10 ( V_18 L_44 ,
V_1 -> V_28 ) ;
#endif
F_14 ( & V_1 -> V_45 , V_25 ) ;
F_56 ( & V_1 -> V_112 ) ;
V_1 -> V_112 . V_111 = V_64 + V_113 ;
V_1 -> V_112 . V_110 = F_35 ;
V_1 -> V_112 . V_52 = ( unsigned long ) V_1 ;
F_37 ( & V_1 -> V_112 ) ;
V_1 -> V_25 |= V_150 ;
if ( V_1 -> V_139 ) {
F_56 ( & V_1 -> V_140 -> V_112 ) ;
V_1 -> V_140 -> V_112 . V_111 = V_64 + V_113 ;
V_1 -> V_140 -> V_112 . V_110 = F_35 ;
V_1 -> V_140 -> V_112 . V_52 = ( unsigned long ) V_1 -> V_140 ;
F_37 ( & V_1 -> V_140 -> V_112 ) ;
V_1 -> V_140 -> V_25 |= V_150 ;
}
F_15 ( & V_1 -> V_45 , V_25 ) ;
}
F_17 ( V_1 , 0 ) ;
return 0 ;
}
}
}
static int
F_57 ( T_2 T_6 * V_151 , int V_47 , T_1 * V_1 )
{
int V_152 ;
T_2 T_6 * V_91 ;
for ( V_91 = V_151 , V_152 = 0 ; V_152 < V_47 ; V_91 ++ , V_152 ++ ) {
if ( V_1 -> V_84 == V_1 -> V_83 )
return V_152 ;
if ( F_58 ( * V_1 -> V_84 ++ , V_91 ) )
return - V_133 ;
if ( V_1 -> V_84 > V_1 -> V_85 )
V_1 -> V_84 = V_1 -> V_86 ;
}
return V_152 ;
}
static int
F_59 ( const T_2 * V_151 , int V_47 , int V_153 , T_1 * V_1 )
{
int V_27 = V_1 -> V_28 ? 2 : 0 ;
int V_154 ;
int V_90 ;
int V_152 ;
int V_155 ;
int V_156 ;
int V_157 ;
unsigned long V_25 ;
int V_158 ;
struct T_1 * V_159 ;
T_2 * V_91 ;
T_4 V_43 ;
T_2 V_160 [ 0x100 ] ;
V_156 = 1 ;
V_155 = V_157 = 0 ;
while ( V_47 ) {
V_152 = V_161 ;
if ( V_152 > V_47 )
V_152 = V_47 ;
if ( V_153 ) {
if ( F_47 ( V_160 , V_151 , V_152 ) )
return - V_133 ;
} else
memcpy ( V_160 , V_151 , V_152 ) ;
F_14 ( & V_19 . V_26 , V_25 ) ;
V_159 = V_19 . V_20 ;
V_158 = V_19 . V_2 ;
F_8 ( V_1 , V_27 ) ;
F_34 ( V_1 , '>' ) ;
for ( V_91 = V_160 , V_154 = F_19 ( & V_149 ) , V_90 = V_152 ; V_90 > 0 ; V_90 -- , V_91 ++ , V_154
++ ) {
F_27 ( ( * V_91 == '\n' ) ? 0xff : * V_91 ,
& V_19 . V_94 -> V_95 . V_162 [ V_154 & 0xff ] ) ;
V_47 -- ;
V_155 ++ ;
F_34 ( V_1 , * V_91 ) ;
if ( ( * V_91 == '\n' ) && ( V_90 > 1 ) ) {
F_34 ( V_1 , '>' ) ;
V_156 ++ ;
}
V_156 ++ ;
}
F_27 ( ( F_19 ( & V_149 ) + V_152 ) & 0xff , & V_149 ) ;
if ( V_159 )
F_8 ( V_159 , V_158 ) ;
F_15 ( & V_19 . V_26 , V_25 ) ;
if ( V_47 ) {
F_60 ( 1 ) ;
if ( V_157 ++ > 20 )
break;
} else
break;
}
if ( V_47 && ( ! V_153 ) )
F_10 ( V_34 L_45 ) ;
V_43 . V_54 = V_109 ;
V_43 . V_56 = V_1 -> V_42 ;
V_43 . V_57 = V_156 ;
V_1 -> V_40 . V_60 ( & V_43 ) ;
return V_155 ;
}
static void
F_61 ( T_1 * V_1 )
{
unsigned long V_25 ;
T_4 V_43 ;
F_14 ( & V_1 -> V_45 , V_25 ) ;
if ( V_1 -> V_25 & V_150 ) {
V_1 -> V_25 &= ~ V_150 ;
F_36 ( & V_1 -> V_112 ) ;
F_36 ( & V_1 -> V_63 ) ;
F_15 ( & V_1 -> V_45 , V_25 ) ;
V_43 . V_54 = V_163 ;
V_43 . V_56 = V_1 -> V_42 ;
V_1 -> V_40 . V_60 ( & V_43 ) ;
if ( V_1 -> V_139 )
F_61 ( V_1 -> V_140 ) ;
} else
F_15 ( & V_1 -> V_45 , V_25 ) ;
}
static void
F_62 ( void )
{
T_1 * V_91 = V_164 ;
while ( V_91 ) {
F_61 ( V_91 ) ;
V_91 = V_91 -> V_165 ;
}
}
static void
F_63 ( void )
{
T_1 * V_1 = V_164 ;
while ( V_1 ) {
if ( ! F_48 ( V_1 -> V_11 , V_136 , L_46 ) ) {
F_10 ( V_34
L_31 ,
V_35 ,
V_1 -> V_11 ,
V_1 -> V_11 + V_136 ) ;
} else {
F_5 ( 0 , V_143 ) ;
F_5 ( 0 , V_17 ) ;
F_64 ( V_1 -> V_11 , V_136 ) ;
}
V_1 = V_1 -> V_165 ;
}
}
static int
F_65 ( T_4 * V_16 , T_1 * V_1 )
{
T_3 V_166 ;
T_3 V_25 ;
int V_90 ;
char V_167 [ 80 ] ;
T_4 V_43 ;
T_8 V_168 ;
char T_6 * V_57 ;
switch ( V_16 -> V_54 ) {
case V_169 :
memcpy ( & V_166 , V_16 -> V_58 . V_81 , sizeof( T_3 ) ) ;
V_57 = ( char T_6 * ) V_166 ;
switch ( V_16 -> V_57 ) {
case V_170 :
if ( V_19 . V_142 != ( V_166 & 0x0ffc000 ) ) {
if ( ! F_49 ( V_166 & 0x0ffc000 , 0x4000 , L_32 ) ) {
F_10 ( V_34
L_33 ,
V_166 & 0x0ffc000 ) ;
return - V_116 ;
}
F_66 ( V_166 & 0x0ffc000 , 0x4000 ) ;
F_62 () ;
F_14 ( & V_1 -> V_45 , V_25 ) ;
if ( V_19 . V_141 ) {
F_67 ( V_19 . V_94 ) ;
F_66 ( V_19 . V_142 , 0x4000 ) ;
}
V_19 . V_141 = 0 ;
V_19 . V_142 = V_166 & 0x0ffc000 ;
F_15 ( & V_1 -> V_45 , V_25 ) ;
F_10 ( V_101
L_47 ,
V_35 ,
V_19 . V_142 ) ;
}
break;
case V_171 :
return ( long ) V_19 . V_142 ;
case V_172 :
if ( V_166 == 0x300 || V_166 == 0x310 || V_166 == 0x320 || V_166 == 0x330
|| V_166 == 0x340 || V_166 == 0x350 || V_166 == 0x360 ||
V_166 == 0x308 || V_166 == 0x318 || V_166 == 0x328 || V_166 == 0x338
|| V_166 == 0x348 || V_166 == 0x358 || V_166 == 0x368 ) {
if ( V_1 -> V_11 != ( unsigned short ) V_166 ) {
if ( ! F_48 ( ( unsigned short ) V_166 , V_136 , L_46 ) ) {
F_10 ( V_34
L_31 ,
V_35 , ( int ) V_166 , ( int ) V_166 + V_136 ) ;
return - V_116 ;
}
F_64 ( ( unsigned short ) V_166 , V_136 ) ;
F_61 ( V_1 ) ;
F_14 ( & V_1 -> V_45 , V_25 ) ;
if ( V_1 -> V_135 )
F_64 ( V_1 -> V_11 , V_136 ) ;
V_1 -> V_11 = ( unsigned short ) V_166 ;
V_1 -> V_135 = 0 ;
if ( V_1 -> V_139 ) {
V_1 -> V_140 -> V_11 = ( unsigned short ) V_166 ;
V_1 -> V_140 -> V_135 = 0 ;
}
F_15 ( & V_1 -> V_45 , V_25 ) ;
F_10 ( V_101
L_48 ,
V_35 , V_1 -> V_11 ) ;
}
} else
return - V_116 ;
break;
case V_173 :
return ( int ) V_1 -> V_11 ;
case V_174 :
return ( int ) V_1 -> V_139 ;
case V_175 :
if ( F_68 ( V_57 ,
& V_1 ,
sizeof( T_3 ) ) )
return - V_133 ;
V_166 += sizeof( T_3 ) ;
{
T_3 V_176 = ( T_3 ) & V_19 ;
if ( F_68 ( V_57 ,
& V_176 ,
sizeof( T_3 ) ) )
return - V_133 ;
}
return 0 ;
case V_177 :
if ( V_19 . V_178 ) {
F_63 () ;
V_19 . V_178 = 0 ;
}
F_61 ( V_1 ) ;
return ( F_45 ( V_57 , V_1 ) ) ;
case V_179 :
F_61 ( V_1 ) ;
if ( ( V_90 = ( F_53 ( V_57 , V_1 ) ) ) )
return V_90 ;
if ( V_1 -> V_139 )
V_90 = F_53 ( V_57 + V_145 , V_1 -> V_140 ) ;
return V_90 ;
break;
case V_180 :
if ( ! V_19 . V_178 )
return - V_138 ;
if ( F_47 ( & V_168 ,
V_57 ,
sizeof( V_168 ) ) )
return - V_133 ;
return ( F_69 ( V_168 . V_11 , V_168 . V_181 , V_168 . V_182 ) ) ;
break;
case V_183 :
if ( V_166 ) {
if ( ! V_1 -> V_184 ) {
V_1 -> V_184 = 1 ;
while ( V_1 -> V_102 == V_185 ) {
F_44 ( V_125 ) ;
}
F_44 ( V_125 ) ;
sprintf ( V_167 , L_49 ,
( V_166 & 1 ) ? '1' : 'C' , ( V_166 & 2 ) ? '2' : 'C' ) ;
V_90 = F_59 ( V_167 , strlen ( V_167 ) , 0 , V_1 ) ;
F_10 ( V_101
L_50 ,
V_35 ) ;
V_43 . V_54 = V_186 ;
V_43 . V_56 = V_1 -> V_42 ;
V_43 . V_57 = 0 ;
V_1 -> V_40 . V_60 ( & V_43 ) ;
}
} else {
if ( V_1 -> V_184 ) {
V_1 -> V_184 = 0 ;
sprintf ( V_167 , L_51 ) ;
V_90 = F_59 ( V_167 , strlen ( V_167 ) , 0 , V_1 ) ;
F_10 ( V_101
L_52 ,
V_35 ) ;
V_43 . V_54 = V_186 ;
V_43 . V_56 = V_1 -> V_42 ;
V_43 . V_57 = 0 ;
V_1 -> V_40 . V_60 ( & V_43 ) ;
}
}
return 0 ;
default:
return - V_116 ;
}
break;
case V_187 :
if ( ! ( V_1 -> V_25 & V_150 ) )
return - V_188 ;
if ( V_1 -> V_184 )
break;
if ( ( V_16 -> V_57 & 255 ) < V_189 ) {
char * V_91 ;
char V_190 [ 4 ] ;
V_166 = V_16 -> V_57 ;
V_91 = V_16 -> V_58 . V_74 . V_75 ;
if ( * V_91 == 's' || * V_91 == 'S' ) {
V_91 ++ ;
strcpy ( V_190 , L_53 ) ;
} else
strcpy ( V_190 , L_54 ) ;
snprintf ( V_167 , sizeof( V_167 ) ,
L_55 , ( int ) ( V_166 + 1 ) ,
V_190 , V_91 , V_16 -> V_58 . V_74 . V_76 ,
V_16 -> V_58 . V_74 . V_77 , V_16 -> V_58 . V_74 . V_78 ) ;
V_90 = F_59 ( V_167 , strlen ( V_167 ) , 0 , V_1 ) ;
}
break;
case V_191 :
if ( ! ( V_1 -> V_25 & V_150 ) )
return - V_188 ;
if ( V_16 -> V_57 < V_189 ) {
V_166 = V_16 -> V_57 + 1 ;
if ( V_1 -> V_108 >= 300 ) {
switch ( V_1 -> V_192 [ V_166 - 1 ] ) {
case V_193 :
sprintf ( V_167 , L_56 , ( int ) V_166 ) ;
break;
case V_194 :
sprintf ( V_167 , L_57 , ( int ) V_166 ) ;
break;
}
V_90 = F_59 ( V_167 , strlen ( V_167 ) , 0 , V_1 ) ;
}
sprintf ( V_167 , L_58 , ( int ) V_166 ) ;
V_90 = F_59 ( V_167 , strlen ( V_167 ) , 0 , V_1 ) ;
}
break;
case V_195 :
if ( ! ( V_1 -> V_25 & V_150 ) )
return - V_188 ;
if ( V_16 -> V_57 < V_189 ) {
V_166 = V_16 -> V_57 + 1 ;
if ( V_1 -> V_108 >= 300 )
switch ( V_1 -> V_192 [ V_166 - 1 ] ) {
case V_193 :
sprintf ( V_167 , L_59 , ( int ) V_166 ) ;
break;
case V_194 :
sprintf ( V_167 , L_60 , ( int ) V_166 ) ;
break;
} else
sprintf ( V_167 , L_61 , ( int ) V_166 ) ;
V_90 = F_59 ( V_167 , strlen ( V_167 ) , 0 , V_1 ) ;
}
break;
case V_196 :
if ( ! ( V_1 -> V_25 & V_150 ) )
return - V_188 ;
if ( V_16 -> V_57 < V_189 ) {
V_166 = V_16 -> V_57 + 1 ;
sprintf ( V_167 , L_62 , ( int ) V_166 , ( int ) V_166 ) ;
V_90 = F_59 ( V_167 , strlen ( V_167 ) , 0 , V_1 ) ;
}
break;
case V_197 :
if ( ! ( V_1 -> V_25 & V_150 ) )
return - V_188 ;
if ( V_1 -> V_184 )
break;
if ( V_16 -> V_57 < V_189 ) {
V_166 = V_16 -> V_57 + 1 ;
if ( V_1 -> V_102 == V_106 ) {
sprintf ( V_167 , L_63 , ( int ) V_166 ,
V_16 -> V_58 . V_81 [ 0 ] ? L_64 : L_65 , V_16 -> V_58 . V_81 ) ;
} else
sprintf ( V_167 , L_66 , ( int ) V_166 ,
V_16 -> V_58 . V_81 [ 0 ] ? ( char * ) ( V_16 -> V_58 . V_81 ) : L_67 ) ;
V_90 = F_59 ( V_167 , strlen ( V_167 ) , 0 , V_1 ) ;
}
break;
case V_198 :
if ( ! ( V_1 -> V_25 & V_150 ) )
return - V_188 ;
if ( V_1 -> V_184 )
break;
if ( V_16 -> V_57 < V_189 ) {
V_166 = V_16 -> V_57 + 1 ;
if ( V_1 -> V_102 == V_106 )
sprintf ( V_167 , L_68 , ( int ) V_166 ) ;
else
sprintf ( V_167 , L_69 , ( int ) V_166 ) ;
V_90 = F_59 ( V_167 , strlen ( V_167 ) , 0 , V_1 ) ;
}
break;
case V_199 :
if ( ! ( V_1 -> V_25 & V_150 ) )
return - V_188 ;
if ( ( V_16 -> V_57 & 255 ) < V_189 ) {
V_166 = V_16 -> V_57 ;
switch ( V_166 >> 8 ) {
case V_193 :
sprintf ( V_167 , L_56 , ( int ) ( V_166 & 255 ) + 1 ) ;
break;
case V_194 :
sprintf ( V_167 , L_57 , ( int ) ( V_166 & 255 ) + 1 ) ;
break;
default:
return - V_116 ;
}
V_90 = F_59 ( V_167 , strlen ( V_167 ) , 0 , V_1 ) ;
V_1 -> V_192 [ V_166 & 255 ] = ( V_166 >> 8 ) ;
}
break;
case V_200 :
if ( ! ( V_1 -> V_25 & V_150 ) )
return - V_188 ;
return 0 ;
default:
return - V_116 ;
}
return 0 ;
}
static inline T_1 *
F_70 ( int V_201 )
{
T_1 * V_91 = V_164 ;
while ( V_91 ) {
if ( V_91 -> V_42 == V_201 )
return V_91 ;
V_91 = V_91 -> V_165 ;
}
return ( T_1 * ) 0 ;
}
static int
F_71 ( T_4 * V_16 )
{
T_1 * V_1 = F_70 ( V_16 -> V_56 ) ;
if ( V_1 )
return ( F_65 ( V_16 , V_1 ) ) ;
F_10 ( V_202
L_70 ,
V_16 -> V_54 , V_16 -> V_56 ) ;
return - V_188 ;
}
static int
F_72 ( const T_2 T_6 * V_151 , int V_47 , int V_203 , int V_2 )
{
T_1 * V_1 = F_70 ( V_203 ) ;
if ( V_1 ) {
if ( ! ( V_1 -> V_25 & V_150 ) )
return - V_188 ;
return ( F_59 ( V_151 , V_47 , 1 , V_1 ) ) ;
}
F_10 ( V_202
L_71 ) ;
return - V_188 ;
}
static int
F_73 ( T_2 T_6 * V_151 , int V_47 , int V_203 , int V_2 )
{
T_1 * V_1 = F_70 ( V_203 ) ;
if ( V_1 ) {
if ( ! ( V_1 -> V_25 & V_150 ) )
return - V_188 ;
return ( F_57 ( V_151 , V_47 , V_1 ) ) ;
}
F_10 ( V_202
L_72 ) ;
return - V_188 ;
}
static int
F_74 ( int V_203 , int V_2 , int V_114 , struct V_6 * V_7 )
{
T_1 * V_1 = F_70 ( V_203 ) ;
if ( V_1 ) {
if ( ! ( V_1 -> V_25 & V_150 ) )
return - V_188 ;
return ( F_38 ( V_2 , V_114 , V_7 , V_1 ) ) ;
}
F_10 ( V_202
L_73 ) ;
return - V_188 ;
}
static T_1 *
F_75 ( int V_11 , char * V_203 )
{
T_1 * V_1 ;
int V_90 ;
if ( ! ( V_1 = F_76 ( sizeof( T_1 ) , V_130 ) ) ) {
F_10 ( V_34
L_74 , V_203 ) ;
return ( T_1 * ) 0 ;
}
F_77 ( & V_1 -> V_45 ) ;
V_1 -> V_11 = V_11 ;
V_1 -> V_40 . V_204 = V_205 ;
V_1 -> V_40 . V_206 = 1 ;
V_1 -> V_40 . V_207 = V_189 ;
V_1 -> V_40 . V_208 = 4000 ;
V_1 -> V_40 . V_54 = F_71 ;
V_1 -> V_40 . V_209 = F_74 ;
V_1 -> V_40 . V_210 = F_72 ;
V_1 -> V_40 . V_211 = F_73 ;
V_1 -> V_40 . V_104 = V_212 |
V_213 |
V_214 |
V_215 ;
V_1 -> V_102 = V_185 ;
F_32 ( V_1 -> V_40 . V_203 , V_203 , sizeof( V_1 -> V_40 . V_203 ) ) ;
V_1 -> V_83 = V_1 -> V_86 ;
V_1 -> V_84 = V_1 -> V_86 ;
V_1 -> V_85 = & V_1 -> V_86 [ sizeof( V_1 -> V_86 ) - 1 ] ;
for ( V_90 = 0 ; V_90 < V_189 ; V_90 ++ ) {
V_1 -> V_192 [ V_90 ] = V_193 ;
F_78 ( & V_1 -> V_5 [ V_90 ] ) ;
}
V_1 -> V_165 = V_164 ;
V_164 = V_1 ;
if ( ! F_79 ( & V_1 -> V_40 ) ) {
V_164 = V_164 -> V_165 ;
F_10 ( V_34
L_75 , V_203 ) ;
F_52 ( V_1 ) ;
return ( T_1 * ) 0 ;
}
V_1 -> V_42 = V_1 -> V_40 . V_207 ;
sprintf ( V_1 -> V_137 , L_76 , V_1 -> V_40 . V_203 ) ;
return V_1 ;
}
static int
F_69 ( int V_11 , char * V_181 , char * V_182 )
{
T_1 * V_1 ;
T_1 * V_216 ;
if ( ! ( V_1 = F_75 ( V_11 , V_181 ) ) ) {
return - V_124 ;
}
if ( ! strlen ( V_182 ) ) {
F_10 ( V_101
L_77 ,
V_1 -> V_40 . V_203 , V_11 ) ;
return 0 ;
}
if ( ! ( V_216 = F_75 ( V_11 , V_182 ) ) ) {
F_10 ( V_101
L_78 , V_182 , V_11 ) ;
return 0 ;
}
V_1 -> V_139 = 1 ;
V_1 -> V_28 = 0 ;
V_1 -> V_140 = V_216 ;
V_216 -> V_139 = 1 ;
V_216 -> V_28 = 1 ;
V_216 -> V_140 = V_1 ;
F_10 ( V_101
L_79 ,
V_1 -> V_40 . V_203 , V_216 -> V_40 . V_203 , V_11 ) ;
return 0 ;
}
static int T_9
F_80 ( char * line )
{
char * V_91 , * V_217 ;
int V_218 [ 3 ] ;
static char V_219 [ 20 ] ;
static char V_220 [ 20 ] ;
V_217 = F_81 ( line , 2 , V_218 ) ;
if ( V_218 [ 0 ] )
V_221 = V_218 [ 1 ] ;
if ( V_218 [ 0 ] > 1 )
V_222 = ( unsigned long ) V_218 [ 2 ] ;
if ( V_217 && * V_217 ) {
F_32 ( V_219 , V_217 , sizeof( V_219 ) ) ;
V_223 = V_219 ;
if ( ( V_91 = strchr ( V_219 , ',' ) ) ) {
* V_91 ++ = 0 ;
strcpy ( V_220 , V_91 ) ;
V_224 = V_220 ;
}
}
return ( 1 ) ;
}
static int T_9 F_82 ( void )
{
char * V_91 ;
char V_225 [ 21 ] ;
memset ( & V_19 , 0 , sizeof( V_226 ) ) ;
V_19 . V_142 = ( V_222 & 0x0ffc000 ) ;
V_19 . V_2 = - 1 ;
V_19 . V_20 = NULL ;
V_19 . V_178 = 1 ;
F_77 ( & V_19 . V_26 ) ;
if ( ( V_91 = strchr ( V_227 , ':' ) ) ) {
strncpy ( V_225 , V_91 + 1 , 20 ) ;
V_225 [ 20 ] = '\0' ;
V_91 = strchr ( V_225 , '$' ) ;
if ( V_91 )
* V_91 = 0 ;
} else
strcpy ( V_225 , L_80 ) ;
F_10 ( V_228 L_81 , V_225 ,
V_19 . V_142 ) ;
return ( F_69 ( V_221 , V_223 , V_224 ) ) ;
}
static void T_10 F_83 ( void )
{
T_4 V_43 ;
T_1 * V_1 = V_164 ;
T_1 * V_229 , * V_230 ;
int V_90 ;
unsigned long V_25 ;
F_62 () ;
while ( V_1 ) {
V_43 . V_54 = V_231 ;
V_43 . V_56 = V_1 -> V_42 ;
V_1 -> V_40 . V_60 ( & V_43 ) ;
F_14 ( & V_1 -> V_45 , V_25 ) ;
if ( V_1 -> V_135 ) {
F_5 ( 0 , V_143 ) ;
F_5 ( 0 , V_17 ) ;
if ( V_1 -> V_28 || ( ! V_1 -> V_139 ) ) {
F_64 ( V_1 -> V_11 , V_136 ) ;
V_1 -> V_135 = 0 ;
}
for ( V_90 = 0 ; V_90 < V_189 ; V_90 ++ )
F_1 ( V_1 , V_90 ) ;
}
V_230 = V_1 -> V_165 ;
F_15 ( & V_1 -> V_45 , V_25 ) ;
V_1 = V_230 ;
}
V_1 = V_164 ;
V_164 = NULL ;
while ( V_1 ) {
V_229 = V_1 ;
V_1 = V_1 -> V_165 ;
F_52 ( V_229 ) ;
}
if ( V_19 . V_141 ) {
F_67 ( V_19 . V_94 ) ;
F_66 ( V_19 . V_142 , 0x4000 ) ;
}
F_10 ( V_228 L_82 ) ;
}
