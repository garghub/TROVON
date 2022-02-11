static inline int T_1
F_1 ( struct V_1 * V_2 )
{
if( V_2 -> V_3 > 0x1ff &&
F_2 ( V_2 -> V_3 , V_4 , V_2 -> V_5 ) &&
F_3 ( V_2 , V_2 -> V_3 , V_2 -> V_6 ) )
return 0 ;
else {
F_4 ( V_7 L_1
L_2 , V_2 -> V_3 ) ;
return - V_8 ;
}
}
static void T_1 F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
V_2 -> V_9 = & V_10 ;
}
int T_1 F_7 ( int V_11 )
{
struct V_1 * V_2 ;
static unsigned T_2 V_12 = 0 ;
int V_13 ;
V_2 = F_8 ( sizeof( struct V_14 ) , L_3 , F_5 ) ;
if ( ! V_2 )
return - V_15 ;
V_2 -> V_9 = & V_10 ;
sprintf ( V_2 -> V_5 , L_4 , V_11 ) ;
F_9 ( V_2 ) ;
V_13 = F_10 ( V_2 ) ;
if ( V_13 ) {
F_11 ( V_2 ) ;
return V_13 ;
}
V_13 = F_12 ( V_2 ) ;
if ( V_13 ) {
F_13 ( V_2 -> V_3 , V_4 ) ;
F_11 ( V_2 ) ;
return V_13 ;
}
if( T_2 ++ == 0 )
F_4 ( V_16 L_5 , V_17 ) ;
return 0 ;
}
static int T_1 F_10 ( struct V_1 * V_2 )
{
int V_18 ;
if( V_2 -> V_3 )
return F_1 ( V_2 ) ;
if( V_19 [ V_20 ] != - 1 )
V_2 -> V_3 = V_19 [ V_20 ] ,
V_2 -> V_6 = V_6 [ V_20 ] ;
else if( V_21 || V_19 [ 0 ] != - 1 )
return - V_8 ;
if( V_2 -> V_3 )
return F_1 ( V_2 ) ;
if( ! V_22 && ! F_14 ( V_2 ) )
return 0 ;
if( V_19 [ V_20 ] == - 1 ) {
V_21 = 1 ;
if( V_20 > 0 )
return - V_8 ;
}
for( V_18 = 0 ; V_23 [ V_18 ] ; ++ V_18 ) {
int V_24 = V_23 [ V_18 ] ;
if( F_2 ( V_24 , V_4 , V_2 -> V_5 ) &&
F_3 ( V_2 , V_24 , 0 ) )
return 0 ;
}
return - V_8 ;
}
static int T_1
F_14 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = NULL ;
while( ( V_26 = F_15 ( V_27 << 8 , V_26 ) )
!= NULL ) {
int V_28 ;
unsigned long V_29 ;
T_3 V_30 ;
if( V_26 -> V_31 != V_32 &&
V_26 -> V_33 != V_34 )
continue;
V_29 = F_16 ( V_26 , 0 ) ;
V_28 = V_26 -> V_6 ;
if( ! F_2 ( V_29 , V_4 , V_2 -> V_5 ) ) {
F_17 ( V_26 , V_35 , & V_30 ) ;
if ( V_30 != 2 )
continue;
if ( ! F_2 ( V_29 += 4 , V_4 ,
V_2 -> V_5 ) )
continue;
}
if ( V_28 <= 0 || V_28 >= V_36 )
F_4 ( V_37
L_6
L_7 ,
V_28 ) ;
if( ( V_29 & 7 ) == 0 && F_18 ( V_26 ) ) {
F_13 ( V_29 , V_4 ) ;
F_19 ( V_26 ) ;
return - V_38 ;
}
if( F_3 ( V_2 , V_29 , V_28 ) ) {
F_20 ( V_2 , & V_26 -> V_2 ) ;
F_19 ( V_26 ) ;
return 0 ;
}
}
return - V_8 ;
}
static struct V_1 * T_1
F_3 ( struct V_1 * V_2 , unsigned long V_24 , int V_6 )
{
struct V_14 * V_39 ;
if( F_21 ( V_24 ) ) {
F_13 ( V_24 , V_4 ) ;
return NULL ;
}
F_22 ( 0 , V_24 + V_40 ) ;
if( V_6 < 2 ) {
unsigned long V_41 ;
V_41 = F_23 () ;
F_22 ( V_42 | V_43 , V_24 + V_40 ) ;
F_22 ( V_44 , V_24 + V_45 ) ;
F_24 ( 50 ) ;
V_6 = F_25 ( V_41 ) ;
F_22 ( 0 , V_24 + V_40 ) ;
if( ! V_6 ) {
F_4 ( V_7 L_8 ,
V_2 -> V_5 ) ;
F_13 ( V_24 , V_4 ) ;
return NULL ;
}
} else if( V_6 == 2 )
V_6 = 9 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_3 = V_24 ;
V_39 = F_26 ( V_2 ) ;
if( ! V_39 ) {
F_4 ( V_7 L_9 , V_2 -> V_5 ) ;
F_13 ( V_24 , V_4 ) ;
return NULL ;
}
memset ( V_39 , 0 , sizeof( struct V_14 ) ) ;
F_27 ( & V_39 -> V_46 ) ;
* ( V_47 * ) V_2 -> V_48 = F_28 ( 0x00ff ) ;
* ( V_49 * ) ( V_2 -> V_48 + 2 ) = F_29 ( 0x01000000 |
( ( V_50 [ V_20 ] ?
V_50 [ V_20 ] :
( V_51 ) ( ( long ) F_26 ( V_2 ) ) ) & 0x00ffffff ) ) ;
V_39 -> V_52 = V_53 ;
V_39 -> V_54 . V_55 = V_56 [ V_20 ] ;
if( ( V_39 -> V_57 = V_58 [ V_20 ] ) == - 1 )
V_39 -> V_57 = V_59 ,
V_39 -> V_60 = V_61 ;
else
V_39 -> V_60 = 0 ;
V_39 -> V_54 . V_58 = V_62 [ V_39 -> V_57 ] ;
if( F_30 ( V_24 + V_40 ) & 0x01 )
V_39 -> V_63 |= V_64 ;
F_4 ( V_65 L_10
L_11 ,
V_2 -> V_5 , V_2 -> V_3 , V_2 -> V_6 ,
( ( V_66 * ) V_2 -> V_48 ) [ 3 ] ,
( ( V_66 * ) V_2 -> V_48 ) [ 4 ] ,
( ( V_66 * ) V_2 -> V_48 ) [ 5 ] ) ;
F_4 ( V_65 L_12 , V_2 -> V_5 ,
( ( V_39 -> V_63 & V_64 ) ? 500000 : 2000000 )
/ ( 1 << V_39 -> V_54 . V_55 ) ) ;
if( V_39 -> V_60 == 0 )
F_4 ( L_13 , V_39 -> V_57 ) ;
else
F_4 ( L_14 ) ;
#ifdef F_31
V_39 -> V_67 = V_2 ;
V_39 -> V_68 = NULL ;
#endif
V_69 [ V_20 ++ ] = V_2 ;
return V_2 ;
}
static T_4
F_32 ( struct V_70 * V_71 , struct V_1 * V_2 )
{
struct V_1 * V_72 ;
F_33 ( V_2 ) ;
for( V_72 = V_2 ; V_72 ; ) {
struct V_14 * V_39 = F_26 ( V_72 ) ;
F_34 ( & V_39 -> V_46 ) ;
if( V_39 -> V_73 || ( V_39 -> V_63 & V_74 ) ) {
V_72 = V_39 -> V_68 ;
F_35 ( & V_39 -> V_46 ) ;
} else {
F_36 ( V_71 , V_72 ) ;
F_35 ( & V_39 -> V_46 ) ;
F_37 ( V_2 ) ;
return V_75 ;
}
}
return V_76 ;
}
static T_4
F_32 ( struct V_70 * V_71 , struct V_1 * V_2 )
{
struct V_14 * V_39 = F_26 ( V_2 ) ;
F_33 ( V_2 ) ;
F_34 ( & V_39 -> V_46 ) ;
F_36 ( V_71 , V_2 ) ;
F_35 ( & V_39 -> V_46 ) ;
return V_75 ;
}
static T_5
F_38 ( int V_6 , void * V_77 )
{
struct V_1 * V_2 = V_77 ;
struct V_14 * V_39 = F_26 ( V_2 ) ;
int V_78 ;
F_34 ( & V_39 -> V_46 ) ;
if( V_39 -> V_79 )
F_34 ( & F_39 ( V_39 -> V_79 ) ) ;
do {
V_78 = 0 ;
if( F_30 ( V_2 -> V_3 + V_40 ) & ( V_80 | V_81 ) )
F_40 ( V_2 ) ,
V_78 = 1 ;
if( V_39 -> V_79 &&
( F_30 ( V_39 -> V_79 -> V_3 + V_40 ) & ( V_80 | V_81 ) ) )
F_40 ( V_39 -> V_79 ) ,
V_78 = 1 ;
} while( V_78 );
if( V_39 -> V_79 )
F_35 ( & F_39 ( V_39 -> V_79 ) ) ;
F_35 ( & V_39 -> V_46 ) ;
return V_82 ;
}
static void
F_40 ( struct V_1 * V_2 )
{
struct V_14 * V_39 = F_26 ( V_2 ) ;
unsigned long V_24 = V_2 -> V_3 ;
int V_83 ;
unsigned char V_84 ;
#ifdef F_31
if( V_39 -> V_63 & V_85 )
F_34 ( & F_39 ( V_39 -> V_67 ) ) ;
#endif
F_22 ( ( F_30 ( V_24 + V_40 ) & ~ V_42 ) | V_43 , V_24 + V_40 ) ;
V_39 -> V_86 = V_87 ;
for(; ; ) {
V_84 = F_30 ( V_24 + V_40 ) ;
if( ( V_84 & ( V_80 | V_81 ) ) == 0 )
break;
V_83 = ! ( V_39 -> V_63 & V_88 ) ;
if( V_84 & V_80 )
V_83 = F_41 ( V_2 ) ;
V_84 = F_30 ( V_24 + V_40 ) ;
if( ! ( V_84 & V_81 ) || ( V_84 & V_80 ) )
F_4 ( V_7 L_15 , V_2 -> V_5 ) ;
if( V_83 || V_39 -> V_89 != 0 )
F_42 ( V_2 ) ;
else
F_22 ( F_30 ( V_24 + V_40 ) & ~ V_43 , V_24 + V_40 ) ;
}
F_22 ( F_30 ( V_24 + V_40 ) | V_42 , V_24 + V_40 ) ;
#ifdef F_31
if( V_39 -> V_63 & V_85 )
F_35 ( & F_39 ( V_39 -> V_67 ) ) ;
#endif
}
static int
F_41 ( struct V_1 * V_2 )
{
struct V_14 * V_39 = F_26 ( V_2 ) ;
unsigned long V_24 = V_2 -> V_3 ;
V_51 V_90 = V_91 ;
unsigned V_92 = 0 , V_93 , V_94 ;
unsigned V_95 , V_96 = 0 ;
if( F_43 ( V_24 , & V_92 , & V_93 , & V_94 , & V_95 , & V_90 ) ) {
V_96 = V_92 > 4
? F_44 ( V_2 , V_92 , V_93 , V_95 , V_90 )
: F_45 ( V_24 , V_92 , V_90 ) ;
if( V_96 )
F_46 ( V_2 , V_94 ) ;
}
F_22 ( F_30 ( V_24 + V_40 ) ^ V_97 , V_24 + V_40 ) ;
if( V_96 ) {
V_39 -> V_63 |= V_88 ;
if( V_92 > 4 )
V_39 -> V_98 . V_99 ++ ;
} else
V_39 -> V_63 &= ~ V_88 ,
F_47 ( V_2 ) ,
V_39 -> V_98 . V_99 ++ ,
V_39 -> V_98 . V_100 ++ ;
return ! V_96 || V_92 > 4 ;
}
static void
F_42 ( struct V_1 * V_2 )
{
struct V_14 * V_39 = F_26 ( V_2 ) ;
V_51 V_90 = V_91 ;
if( V_39 -> V_63 & V_101 ) {
if( V_39 -> V_102 ) {
-- V_39 -> V_102 ;
if( V_39 -> V_92 != 0 )
V_39 -> V_98 . V_103 ++ ;
} else {
#ifdef F_31
if( ( V_39 -> V_63 & V_85 ) || V_39 -> V_68 )
#endif
V_39 -> V_63 |= V_74 ;
F_48 ( V_2 ) ;
goto V_104;
}
} else
V_39 -> V_102 = V_105 ;
F_49 ( V_2 , & V_90 ) ;
V_39 -> V_63 |= V_101 ;
if( V_39 -> V_92 ) {
F_50 ( V_2 , & V_90 ) ;
V_39 -> V_98 . V_106 ++ ;
V_39 -> V_63 |= V_107 ;
}
F_51 ( V_2 -> V_3 + V_108 , ( V_66 * ) & V_90 , sizeof V_90 ) ;
V_104:
F_22 ( F_30 ( V_2 -> V_3 + V_40 ) & ~ V_43 , V_2 -> V_3 + V_40 ) ;
if( V_39 -> V_89 )
F_22 ( F_30 ( V_2 -> V_3 + V_40 ) | V_43 ,
V_2 -> V_3 + V_40 ) ;
}
static void
F_50 ( struct V_1 * V_2 , V_51 * V_109 )
{
struct V_14 * V_39 = F_26 ( V_2 ) ;
struct V_70 * V_71 = V_39 -> V_73 ;
unsigned V_110 = F_52 (unsigned int, skb->len - nl->outpos, nl->framelen) ;
F_51 ( V_2 -> V_3 + V_108 , V_71 -> V_111 + V_39 -> V_112 , V_110 ) ;
* V_109 = F_53 ( * V_109 , V_71 -> V_111 + V_39 -> V_112 , V_110 ) ;
for( V_110 = V_39 -> V_92 - V_110 ; V_110 -- ; )
F_22 ( 0 , V_2 -> V_3 + V_108 ) ,
* V_109 = F_54 ( 0 , * V_109 ) ;
}
static int
F_44 ( struct V_1 * V_2 , unsigned V_92 , unsigned V_93 ,
unsigned V_95 , V_51 V_90 )
{
struct V_14 * V_39 = F_26 ( V_2 ) ;
int V_96 ;
if( V_95 )
V_39 -> V_113 = V_93 ,
V_39 -> V_114 = 0 ;
if( V_39 -> V_113 == V_93 ) {
if( V_39 -> V_114 + V_92 <= V_115 )
V_96 = F_55 ( V_2 , V_92 , V_90 ) ;
else if( ( V_96 = F_45 ( V_2 -> V_3 , V_92 , V_90 ) )
!= 0 )
V_39 -> V_113 = 0 ,
V_39 -> V_114 = 0 ,
#ifdef F_31
V_39 -> V_67 -> V_116 . V_117 ++ ,
V_39 -> V_67 -> V_116 . V_118 ++ ;
#else
V_2 -> V_116 . V_117 ++ ,
V_2 -> V_116 . V_118 ++ ;
#endif
} else
V_96 = F_45 ( V_2 -> V_3 , V_92 , V_90 ) ;
if( V_95 && ! V_96 )
V_39 -> V_113 = 0 ,
#ifdef F_31
V_39 -> V_67 -> V_116 . V_117 ++ ,
V_39 -> V_67 -> V_116 . V_119 ++ ;
#else
V_2 -> V_116 . V_117 ++ ,
V_2 -> V_116 . V_119 ++ ;
#endif
return V_96 ;
}
static inline void
F_56 ( struct V_1 * V_2 )
{
struct V_14 * V_39 = F_26 ( V_2 ) ;
#ifdef F_31
V_39 -> V_67 -> V_116 . V_120 ++ ;
V_39 -> V_67 -> V_116 . V_121 += V_39 -> V_73 -> V_110 ;
#else
V_2 -> V_116 . V_120 ++ ;
V_2 -> V_116 . V_121 += V_39 -> V_73 -> V_110 ;
#endif
F_57 ( V_39 -> V_73 ) ;
V_39 -> V_73 = NULL ;
V_39 -> V_112 = 0 ;
V_39 -> V_63 &= ~ ( V_107 | V_101 ) ;
V_39 -> V_92 = 0 ;
}
static void
F_46 ( struct V_1 * V_2 , unsigned V_94 )
{
struct V_14 * V_39 = F_26 ( V_2 ) ;
if( V_94 == V_122 ) {
V_39 -> V_63 &= ~ V_101 ;
if( V_39 -> V_63 & V_107 ) {
V_39 -> V_112 += V_39 -> V_92 ;
if( -- V_39 -> V_89 )
V_39 -> V_92 = F_52 (unsigned int,
nl->maxframe,
nl->tx_buf_p->len - nl->outpos) ;
else
F_56 ( V_2 ) ,
#ifdef F_31
F_58 ( V_39 -> V_67 ) ;
#else
F_58 ( V_2 ) ;
#endif
}
}
V_39 -> V_63 &= ~ V_107 ;
}
static int
F_55 ( struct V_1 * V_2 , unsigned V_92 , V_51 V_90 )
{
struct V_14 * V_39 = F_26 ( V_2 ) ;
V_66 * V_72 ;
if( V_39 -> V_114 + V_92 > V_115 )
return 0 ;
if( ! V_39 -> V_123 && ! ( V_39 -> V_123 = F_59 ( V_2 ) ) )
return 0 ;
V_72 = V_39 -> V_123 -> V_111 + V_39 -> V_114 ;
F_60 ( V_2 -> V_3 + V_108 , V_72 , V_92 ) ;
if( F_53 ( V_90 , V_72 , V_92 ) != V_124 )
return 0 ;
V_39 -> V_114 += V_92 - 4 ;
if( -- V_39 -> V_113 == 0 )
F_61 ( V_2 ) ;
return 1 ;
}
static void
F_36 ( struct V_70 * V_71 , struct V_1 * V_2 )
{
struct V_14 * V_39 = F_26 ( V_2 ) ;
unsigned int V_110 ;
if( V_39 -> V_73 )
F_4 ( V_7 L_16 , V_2 -> V_5 ) ;
V_39 -> V_112 = 0 ;
V_39 -> V_63 &= ~ ( V_107 | V_101 ) ;
V_110 = V_71 -> V_110 ;
if( V_110 < V_125 )
V_110 = V_125 ;
V_39 -> V_73 = V_71 ;
V_39 -> V_89 = F_62 ( V_110 , V_39 -> V_52 ) ;
V_39 -> V_92 = V_110 < V_39 -> V_52 ? V_110 : V_39 -> V_52 ;
F_22 ( F_30 ( V_2 -> V_3 + V_40 ) | V_43 , V_2 -> V_3 + V_40 ) ;
#ifdef F_31
V_39 -> V_67 -> V_126 = V_127 ;
#else
V_2 -> V_126 = V_127 ;
#endif
}
static void
F_48 ( struct V_1 * V_2 )
{
struct V_14 * V_39 = F_26 ( V_2 ) ;
if( V_39 -> V_73 )
F_63 ( V_39 -> V_73 ) ,
V_39 -> V_73 = NULL ,
#ifdef F_31
V_39 -> V_67 -> V_116 . V_128 ++ ,
V_39 -> V_67 -> V_116 . V_129 ++ ;
#else
V_2 -> V_116 . V_128 ++ ,
V_2 -> V_116 . V_129 ++ ;
#endif
V_39 -> V_89 = 0 ;
V_39 -> V_92 = 0 ;
V_39 -> V_112 = 0 ;
V_39 -> V_63 &= ~ ( V_107 | V_101 ) ;
#ifdef F_31
F_37 ( V_39 -> V_67 ) ;
V_39 -> V_67 -> V_126 = V_127 ;
#else
F_37 ( V_2 ) ;
V_2 -> V_126 = V_127 ;
#endif
}
static void
F_49 ( struct V_1 * V_2 , V_51 * V_109 )
{
struct V_14 * V_39 = F_26 ( V_2 ) ;
V_51 V_90 = * V_109 ;
V_51 V_130 = V_39 -> V_92 + 6 ;
V_66 V_131 ;
if( V_39 -> V_63 & V_101 )
V_130 |= V_132 ;
if( V_39 -> V_112 == 0 )
V_130 |= V_133 ;
V_130 |= ( V_39 -> V_63 & V_88 ) ? V_122 : V_134 ;
F_22 ( V_135 , V_2 -> V_3 + V_108 ) ;
V_131 = ( V_66 ) V_130 ;
F_22 ( V_131 , V_2 -> V_3 + V_108 ) ;
V_90 = F_54 ( V_131 , V_90 ) ;
V_131 = ( V_66 ) ( V_130 >> 8 ) ;
F_22 ( V_131 , V_2 -> V_3 + V_108 ) ;
V_90 = F_54 ( V_131 , V_90 ) ;
F_22 ( V_39 -> V_89 , V_2 -> V_3 + V_108 ) ;
V_90 = F_54 ( V_39 -> V_89 , V_90 ) ;
F_22 ( 0 , V_2 -> V_3 + V_108 ) ;
V_90 = F_54 ( 0 , V_90 ) ;
* V_109 = V_90 ;
}
static int
F_45 ( unsigned int V_24 , unsigned int V_136 , V_51 V_90 )
{
while( V_136 -- )
V_90 = F_54 ( F_30 ( V_24 + V_108 ) , V_90 ) ;
return V_90 == V_124 ;
}
static int
F_43 ( V_51 V_24 , V_51 * V_92 , V_51 * V_93 , V_51 * V_94 ,
V_51 * V_95 , V_51 * V_109 )
{
V_51 V_90 = * V_109 ;
V_66 V_131 ;
if( F_30 ( V_24 + V_108 ) != V_135 )
return 0 ;
V_131 = F_30 ( V_24 + V_108 ) ;
* V_92 = ( V_51 ) V_131 ;
V_90 = F_54 ( V_131 , V_90 ) ;
V_131 = F_30 ( V_24 + V_108 ) ;
* V_92 |= ( ( V_51 ) V_131 ) << 8 ;
V_90 = F_54 ( V_131 , V_90 ) ;
* V_94 = * V_92 & V_137 ;
* V_95 = ( * V_92 & V_133 ) != 0 ;
if( ( * V_92 &= V_138 ) < 6 ||
* V_92 > V_139 - 3 )
return 0 ;
V_131 = F_30 ( V_24 + V_108 ) ;
* V_93 = ( V_51 ) V_131 ;
V_90 = F_54 ( V_131 , V_90 ) ;
V_90 = F_54 ( F_30 ( V_24 + V_108 ) , V_90 ) ;
* V_92 -= 2 ;
* V_109 = V_90 ;
return 1 ;
}
static struct V_70 *
F_59 ( struct V_1 * V_2 )
{
struct V_70 * V_71 = F_64 ( V_115 + 2 ) ;
if( ! V_71 )
return NULL ;
F_65 ( V_71 , 2 ) ;
return V_71 ;
}
static void
F_61 ( struct V_1 * V_2 )
{
struct V_14 * V_39 = F_26 ( V_2 ) ;
struct V_70 * V_71 = V_39 -> V_123 ;
F_66 ( V_71 , V_39 -> V_114 ) ;
#ifdef F_31
V_71 -> V_140 = F_67 ( V_71 , V_39 -> V_67 ) ;
F_68 ( V_71 ) ;
++ V_39 -> V_67 -> V_116 . V_141 ;
V_39 -> V_67 -> V_116 . V_142 += V_39 -> V_114 ;
#else
V_71 -> V_140 = F_67 ( V_71 , V_2 ) ;
F_68 ( V_71 ) ;
++ V_2 -> V_116 . V_141 ;
V_2 -> V_116 . V_142 += V_39 -> V_114 ;
#endif
V_39 -> V_123 = NULL ;
}
static void
F_69 ( unsigned long V_143 )
{
struct V_1 * V_2 = (struct V_1 * ) V_143 ;
struct V_14 * V_39 = F_26 ( V_2 ) ;
struct V_144 * V_145 = & V_39 -> V_146 ;
unsigned long V_147 ;
unsigned char V_84 ;
F_70 ( & V_39 -> V_46 , V_147 ) ;
V_84 = F_30 ( V_2 -> V_3 + V_40 ) ;
if( V_84 & V_148 ) {
if( V_39 -> V_86 ) {
if( V_84 & ( V_80 | V_149 ) )
V_39 -> V_86 -- ;
} else {
V_39 -> V_98 . V_150 ++ ;
if( V_39 -> V_60 )
F_71 ( V_2 ) ;
F_22 ( * ( V_151 * ) & V_39 -> V_54 | V_44 ,
V_2 -> V_3 + V_45 ) ;
V_84 = F_30 ( V_2 -> V_3 + V_40 ) ;
}
} else
V_39 -> V_63 &= ~ V_74 ;
F_22 ( V_84 | V_148 , V_2 -> V_3 + V_40 ) ;
F_72 ( V_145 ) ;
V_145 -> V_152 = V_127 + V_153 ;
V_145 -> V_111 = V_143 ;
V_145 -> V_154 = F_69 ;
F_73 ( V_145 ) ;
F_74 ( & V_39 -> V_46 , V_147 ) ;
}
static void
F_75 ( struct V_1 * V_2 )
{
struct V_14 * V_39 = F_26 ( V_2 ) ;
V_39 -> V_86 = V_87 ;
V_39 -> V_63 &= ~ ( V_107 | V_101 ) ;
V_39 -> V_63 |= V_88 ;
V_39 -> V_114 = V_39 -> V_112 = 0 ;
V_39 -> V_113 = 0 ;
V_39 -> V_89 = 0 ;
V_39 -> V_92 = 0 ;
F_22 ( * ( V_151 * ) & V_39 -> V_54 | V_44 , V_2 -> V_3 + V_45 ) ;
F_22 ( V_42 , V_2 -> V_3 + V_40 ) ;
}
static void
F_47 ( struct V_1 * V_2 )
{
struct V_14 * V_39 = F_26 ( V_2 ) ;
if( V_39 -> V_60 == 0 )
return;
if( V_39 -> V_57 == 0 )
V_39 -> V_60 = 1 ;
else if( V_39 -> V_57 == 15 )
V_39 -> V_60 = - 1 ;
else if( V_39 -> V_155 < V_39 -> V_156 )
V_39 -> V_60 = - V_39 -> V_60 ;
V_39 -> V_54 . V_58 = V_62 [ V_39 -> V_57 += V_39 -> V_60 ] ;
F_30 ( V_2 -> V_3 + V_40 ) ;
F_22 ( * ( V_66 * ) & V_39 -> V_54 , V_2 -> V_3 + V_45 ) ;
V_39 -> V_156 = V_39 -> V_155 ;
V_39 -> V_155 = 0 ;
}
static void
F_71 ( struct V_1 * V_2 )
{
struct V_14 * V_39 = F_26 ( V_2 ) ;
V_39 -> V_57 = V_157 [ V_39 -> V_158 ] ;
if( ++ V_39 -> V_158 >= 4 )
V_39 -> V_158 = 0 ;
V_39 -> V_54 . V_58 = V_62 [ V_39 -> V_57 ] ;
F_30 ( V_2 -> V_3 + V_40 ) ;
F_22 ( * ( unsigned char * ) & V_39 -> V_54 , V_2 -> V_3 + V_45 ) ;
V_39 -> V_156 = V_39 -> V_155 ;
V_39 -> V_155 = 0 ;
}
static int
F_76 ( struct V_1 * V_2 )
{
struct V_14 * V_39 = F_26 ( V_2 ) ;
struct V_144 * V_145 = & V_39 -> V_146 ;
if( V_2 -> V_3 < 0x400 ) {
struct V_1 * * V_72 = V_69 ;
for( ; * V_72 && V_72 < V_69 + V_159 ; ++ V_72 )
if( ( * V_72 ) -> V_6 == V_2 -> V_6 &&
( ( * V_72 ) -> V_3 == V_2 -> V_3 + 4 ||
( * V_72 ) -> V_3 == V_2 -> V_3 - 4 ) &&
( * V_72 ) -> V_147 & V_160 ) {
( (struct V_14 * ) ( F_26 ( * V_72 ) ) )
-> V_79 = V_2 ;
F_4 ( V_65 L_17
L_18 , V_2 -> V_5 , ( * V_72 ) -> V_5 ) ;
V_39 -> V_63 |= V_161 ;
goto V_162;
}
}
if( F_77 ( V_2 -> V_6 , F_38 , V_163 , V_2 -> V_5 , V_2 ) ) {
F_4 ( V_7 L_19 ,
V_2 -> V_5 , V_2 -> V_6 ) ;
return - V_164 ;
}
V_162:
F_34 ( & V_39 -> V_46 ) ;
memset ( & V_2 -> V_116 , 0 , sizeof( struct V_165 ) ) ;
memset ( & V_39 -> V_98 , 0 , sizeof( struct V_166 ) ) ;
F_75 ( V_2 ) ;
F_37 ( V_2 ) ;
F_72 ( V_145 ) ;
V_145 -> V_152 = V_127 + V_153 ;
V_145 -> V_111 = ( unsigned long ) V_2 ;
V_145 -> V_154 = F_69 ;
F_73 ( V_145 ) ;
F_35 ( & V_39 -> V_46 ) ;
return 0 ;
}
static int
F_78 ( struct V_1 * V_2 )
{
struct V_14 * V_39 = F_26 ( V_2 ) ;
if( V_39 -> V_79 && V_39 -> V_79 -> V_147 & V_160 ) {
F_4 ( V_65 L_20 ,
V_39 -> V_79 -> V_5 ) ;
return - V_167 ;
}
#ifdef F_31
if( V_39 -> V_63 & V_85 )
F_79 ( V_2 ) ;
else
while( V_39 -> V_68 )
F_79 ( V_39 -> V_68 ) ;
#endif
F_34 ( & V_39 -> V_46 ) ;
V_39 -> V_79 = NULL ;
F_48 ( V_2 ) ;
F_33 ( V_2 ) ;
F_80 ( & V_39 -> V_146 ) ;
F_22 ( 0 , V_2 -> V_3 + V_40 ) ;
if( ! ( V_39 -> V_63 & V_161 ) )
F_81 ( V_2 -> V_6 , V_2 ) ;
V_39 -> V_63 &= V_161 ;
F_35 ( & V_39 -> V_46 ) ;
return 0 ;
}
static int
F_21 ( unsigned long V_24 )
{
unsigned char V_84 ;
V_84 = F_30 ( V_24 + V_40 ) ;
if( V_84 != 0xff && V_84 != 0x00 ) {
V_84 &= ~ V_42 ;
if( V_84 & V_149 )
V_84 |= V_42 ;
if( V_168 & ( 1 << ( V_84 >> 4 ) ) )
return 0 ;
}
return - V_8 ;
}
static int
F_82 ( struct V_1 * V_2 , struct V_169 * V_170 , int V_171 )
{
struct V_14 * V_39 = F_26 ( V_2 ) ;
struct V_172 V_147 ;
int error = 0 ;
#ifdef F_31
struct V_1 * V_173 ;
char V_174 [ 8 ] ;
#endif
switch( V_171 ) {
case V_175 :
if ( F_83 ( V_170 -> V_176 , & V_39 -> V_98 ,
sizeof( struct V_166 ) ) )
error = - V_177 ;
break;
case V_178 :
if ( ! F_84 ( V_179 ) )
return - V_180 ;
memset ( & V_39 -> V_98 , 0 , sizeof( struct V_166 ) ) ;
break;
case V_181 :
V_147 . V_182 = * ( V_51 * ) ( V_2 -> V_48 + 3 ) ;
V_147 . V_55 = V_39 -> V_54 . V_55 ;
V_147 . V_183 = ( V_39 -> V_63 & V_64 ) != 0 ;
V_147 . V_58 = V_39 -> V_57 ;
V_147 . V_184 = V_39 -> V_60 == 0 ;
if ( F_83 ( V_170 -> V_176 , & V_147 , sizeof V_147 ) )
error = - V_177 ;
break;
case V_185 :
if ( ! F_84 ( V_179 ) )
return - V_180 ;
F_34 ( & V_39 -> V_46 ) ;
V_147 = * (struct V_172 * ) & V_170 -> V_186 ;
if( V_147 . V_184 )
V_39 -> V_60 = 0 ,
V_39 -> V_57 = V_147 . V_58 ;
else
V_39 -> V_60 = V_61 ,
V_39 -> V_57 = V_59 ;
V_39 -> V_54 . V_58 = V_62 [ V_39 -> V_57 ] ;
V_39 -> V_54 . V_55 = V_147 . V_55 ;
F_22 ( * ( V_66 * ) & V_39 -> V_54 | V_44 , V_2 -> V_3 + V_45 ) ;
F_35 ( & V_39 -> V_46 ) ;
break;
#ifdef F_31
case V_187 :
if ( ! F_84 ( V_179 ) )
return - V_180 ;
if ( F_85 ( V_174 , V_170 -> V_176 , sizeof V_174 ) )
return - V_177 ;
V_173 = F_86 ( & V_188 , V_174 ) ;
if( ! V_173 || ! ( V_173 -> V_147 & V_160 ) ) {
F_4 ( V_7 L_21
L_22 , V_2 -> V_5 , V_174 ) ;
return - V_180 ;
}
return F_87 ( V_2 , V_173 ) ;
case V_189 :
if ( ! F_84 ( V_179 ) )
return - V_180 ;
return F_79 ( V_2 ) ;
#endif
default :
return - V_190 ;
}
return error ;
}
static int
F_87 ( struct V_1 * V_2 , struct V_1 * V_173 )
{
struct V_14 * V_39 = F_26 ( V_2 ) ;
struct V_14 * V_191 = F_26 ( V_173 ) ;
if( V_39 -> V_63 & V_85 )
return - V_167 ;
if( V_191 -> V_63 & V_85 )
return - V_167 ;
F_34 ( & V_39 -> V_46 ) ;
F_34 ( & V_191 -> V_46 ) ;
V_191 -> V_68 = V_39 -> V_68 ;
V_39 -> V_68 = V_173 ;
V_191 -> V_67 = V_2 ;
V_191 -> V_63 |= V_85 ;
memset ( & V_173 -> V_116 , 0 , sizeof( struct V_165 ) ) ;
F_33 ( V_173 ) ;
F_58 ( V_2 ) ;
F_35 ( & V_191 -> V_46 ) ;
F_35 ( & V_39 -> V_46 ) ;
F_4 ( V_65 L_23 ,
V_2 -> V_5 , V_173 -> V_5 ) ;
return 0 ;
}
static int
F_79 ( struct V_1 * V_2 )
{
struct V_14 * V_191 = F_26 ( V_2 ) ;
struct V_1 * V_72 = V_191 -> V_67 ;
struct V_14 * V_39 = F_26 ( V_72 ) ;
if( ! ( V_191 -> V_63 & V_85 ) )
return - V_192 ;
F_34 ( & V_39 -> V_46 ) ;
F_34 ( & V_191 -> V_46 ) ;
F_48 ( V_2 ) ;
for(; ; ) {
struct V_14 * V_193 = F_26 ( V_72 ) ;
if( V_193 -> V_68 == V_2 ) {
V_193 -> V_68 = V_191 -> V_68 ;
break;
}
V_72 = V_193 -> V_68 ;
}
V_191 -> V_68 = NULL ;
V_191 -> V_67 = V_2 ;
V_191 -> V_63 &= ~ V_85 ;
F_37 ( V_2 ) ;
F_35 ( & V_191 -> V_46 ) ;
F_35 ( & V_39 -> V_46 ) ;
F_88 ( V_2 ) ;
return 0 ;
}
static void
F_89 ( struct V_1 * V_2 )
{
return;
}
int T_1 F_90 ( void )
{
struct V_1 * V_2 ;
int V_13 ;
while( V_20 < V_159 ) {
V_2 = F_8 ( sizeof( struct V_14 ) ,
L_4 , F_5 ) ;
if( ! V_2 )
break;
sprintf ( V_2 -> V_5 , L_4 , V_20 ) ;
V_13 = F_10 ( V_2 ) ;
if ( V_13 ) {
F_11 ( V_2 ) ;
break;
}
if( F_12 ( V_2 ) ) {
F_13 ( V_2 -> V_3 , V_4 ) ;
F_11 ( V_2 ) ;
break;
}
}
return * V_69 ? 0 : - V_8 ;
}
void
F_91 ( void )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_159 ; ++ V_18 ) {
struct V_1 * V_2 = V_69 [ V_18 ] ;
if ( V_2 != NULL ) {
F_92 ( V_2 ) ;
F_13 ( V_2 -> V_3 , V_4 ) ;
F_11 ( V_2 ) ;
}
}
}
static int T_1
F_93 ( char * V_72 )
{
int V_194 , V_195 ;
if( * V_72 ++ != '(' )
goto V_196;
for( V_194 = 0 , V_195 = 0 ; * V_72 && V_194 < 8 ; ) {
( * V_197 [ V_195 ] ) [ V_194 ] = F_94 ( V_72 , & V_72 , 0 ) ;
if( ! * V_72 || * V_72 == ')' )
return 1 ;
if( * V_72 == ';' )
++ V_72 , ++ V_194 , V_195 = 0 ;
else if( * V_72 ++ != ',' )
break;
else
if( ++ V_195 >= 5 )
break;
}
V_196:
F_4 ( V_7 L_24 ) ;
return 0 ;
}
static V_51
F_53 ( V_51 V_90 , V_66 * V_72 , V_51 V_110 )
{
register V_51 V_198 ;
V_198 = V_90 ;
__asm__ __volatile__ (
"xorl %%ebx, %%ebx\n"
"movl %2, %%esi\n"
"movl %3, %%ecx\n"
"movl $crc32tab, %%edi\n"
"shrl $2, %%ecx\n"
"jz 1f\n"
".align 4\n"
"0:\n"
"movb %%al, %%bl\n"
"movl (%%esi), %%edx\n"
"shrl $8, %%eax\n"
"xorb %%dl, %%bl\n"
"shrl $8, %%edx\n"
"xorl (%%edi,%%ebx,4), %%eax\n"
"movb %%al, %%bl\n"
"shrl $8, %%eax\n"
"xorb %%dl, %%bl\n"
"shrl $8, %%edx\n"
"xorl (%%edi,%%ebx,4), %%eax\n"
"movb %%al, %%bl\n"
"shrl $8, %%eax\n"
"xorb %%dl, %%bl\n"
"movb %%dh, %%dl\n"
"xorl (%%edi,%%ebx,4), %%eax\n"
"movb %%al, %%bl\n"
"shrl $8, %%eax\n"
"xorb %%dl, %%bl\n"
"addl $4, %%esi\n"
"xorl (%%edi,%%ebx,4), %%eax\n"
"decl %%ecx\n"
"jnz 0b\n"
"1:\n"
"movl %3, %%ecx\n"
"andl $3, %%ecx\n"
"jz 2f\n"
"movb %%al, %%bl\n"
"shrl $8, %%eax\n"
"xorb (%%esi), %%bl\n"
"xorl (%%edi,%%ebx,4), %%eax\n"
"decl %%ecx\n"
"jz 2f\n"
"movb %%al, %%bl\n"
"shrl $8, %%eax\n"
"xorb 1(%%esi), %%bl\n"
"xorl (%%edi,%%ebx,4), %%eax\n"
"decl %%ecx\n"
"jz 2f\n"
"movb %%al, %%bl\n"
"shrl $8, %%eax\n"
"xorb 2(%%esi), %%bl\n"
"xorl (%%edi,%%ebx,4), %%eax\n"
"2:\n"
: "=a" (_crc)
: "0" (_crc), "g" (p), "g" (len)
: "bx", "cx", "dx", "si", "di"
);
return V_198 ;
}
static V_51
F_53 ( V_51 V_90 , V_66 * V_72 , V_51 V_110 )
{
while( V_110 -- )
V_90 = F_54 ( * V_72 ++ , V_90 ) ;
return V_90 ;
}
