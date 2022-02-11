static inline int T_1
F_1 ( struct V_1 * V_2 )
{
if( V_2 -> V_3 > 0x1ff &&
F_2 ( V_2 -> V_3 , V_4 , V_2 -> V_5 ) &&
F_3 ( V_2 , V_2 -> V_3 , V_2 -> V_6 ) )
return 0 ;
else {
F_4 ( L_1 ,
V_2 -> V_3 ) ;
return - V_7 ;
}
}
static void T_1 F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
V_2 -> V_8 = & V_9 ;
}
int T_1 F_7 ( int V_10 )
{
struct V_1 * V_2 ;
int V_11 ;
V_2 = F_8 ( sizeof( struct V_12 ) , L_2 , F_5 ) ;
if ( ! V_2 )
return - V_13 ;
V_2 -> V_8 = & V_9 ;
sprintf ( V_2 -> V_5 , L_3 , V_10 ) ;
F_9 ( V_2 ) ;
V_11 = F_10 ( V_2 ) ;
if ( V_11 ) {
F_11 ( V_2 ) ;
return V_11 ;
}
V_11 = F_12 ( V_2 ) ;
if ( V_11 ) {
F_13 ( V_2 -> V_3 , V_4 ) ;
F_11 ( V_2 ) ;
return V_11 ;
}
F_14 ( L_4 , V_14 ) ;
return 0 ;
}
static int T_1 F_10 ( struct V_1 * V_2 )
{
int V_15 ;
if( V_2 -> V_3 )
return F_1 ( V_2 ) ;
if( V_16 [ V_17 ] != - 1 )
V_2 -> V_3 = V_16 [ V_17 ] ,
V_2 -> V_6 = V_6 [ V_17 ] ;
else if( V_18 || V_16 [ 0 ] != - 1 )
return - V_7 ;
if( V_2 -> V_3 )
return F_1 ( V_2 ) ;
if( ! V_19 && ! F_15 ( V_2 ) )
return 0 ;
if( V_16 [ V_17 ] == - 1 ) {
V_18 = 1 ;
if( V_17 > 0 )
return - V_7 ;
}
for( V_15 = 0 ; V_20 [ V_15 ] ; ++ V_15 ) {
int V_21 = V_20 [ V_15 ] ;
if( F_2 ( V_21 , V_4 , V_2 -> V_5 ) &&
F_3 ( V_2 , V_21 , 0 ) )
return 0 ;
}
return - V_7 ;
}
static int T_1
F_15 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = NULL ;
while( ( V_23 = F_16 ( V_24 << 8 , V_23 ) )
!= NULL ) {
int V_25 ;
unsigned long V_26 ;
if( V_23 -> V_27 != V_28 &&
V_23 -> V_29 != V_30 )
continue;
V_26 = F_17 ( V_23 , 0 ) ;
V_25 = V_23 -> V_6 ;
if( ! F_2 ( V_26 , V_4 , V_2 -> V_5 ) ) {
if ( V_23 -> V_31 != 2 )
continue;
if ( ! F_2 ( V_26 += 4 , V_4 ,
V_2 -> V_5 ) )
continue;
}
if ( V_25 <= 0 || V_25 >= V_32 )
F_18 (
L_5
L_6 ,
V_25 ) ;
if( ( V_26 & 7 ) == 0 && F_19 ( V_23 ) ) {
F_13 ( V_26 , V_4 ) ;
F_20 ( V_23 ) ;
return - V_33 ;
}
if( F_3 ( V_2 , V_26 , V_25 ) ) {
F_21 ( V_2 , & V_23 -> V_2 ) ;
F_20 ( V_23 ) ;
return 0 ;
}
}
return - V_7 ;
}
static struct V_1 * T_1
F_3 ( struct V_1 * V_2 , unsigned long V_21 , int V_6 )
{
struct V_12 * V_34 ;
if( F_22 ( V_21 ) ) {
F_13 ( V_21 , V_4 ) ;
return NULL ;
}
F_23 ( 0 , V_21 + V_35 ) ;
if( V_6 < 2 ) {
unsigned long V_36 ;
V_36 = F_24 () ;
F_23 ( V_37 | V_38 , V_21 + V_35 ) ;
F_23 ( V_39 , V_21 + V_40 ) ;
F_25 ( 50 ) ;
V_6 = F_26 ( V_36 ) ;
F_23 ( 0 , V_21 + V_35 ) ;
if( ! V_6 ) {
F_4 ( L_7 , V_2 -> V_5 ) ;
F_13 ( V_21 , V_4 ) ;
return NULL ;
}
} else if( V_6 == 2 )
V_6 = 9 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_3 = V_21 ;
V_34 = F_27 ( V_2 ) ;
if( ! V_34 ) {
F_4 ( L_8 , V_2 -> V_5 ) ;
F_13 ( V_21 , V_4 ) ;
return NULL ;
}
memset ( V_34 , 0 , sizeof( struct V_12 ) ) ;
F_28 ( & V_34 -> V_41 ) ;
* ( V_42 * ) V_2 -> V_43 = F_29 ( 0x00ff ) ;
* ( V_44 * ) ( V_2 -> V_43 + 2 ) = F_30 ( 0x01000000 |
( ( V_45 [ V_17 ] ?
V_45 [ V_17 ] :
( V_46 ) ( ( long ) F_27 ( V_2 ) ) ) & 0x00ffffff ) ) ;
V_34 -> V_47 = V_48 ;
V_34 -> V_49 . V_50 = V_51 [ V_17 ] ;
if( ( V_34 -> V_52 = V_53 [ V_17 ] ) == - 1 )
V_34 -> V_52 = V_54 ,
V_34 -> V_55 = V_56 ;
else
V_34 -> V_55 = 0 ;
V_34 -> V_49 . V_53 = V_57 [ V_34 -> V_52 ] ;
if( F_31 ( V_21 + V_35 ) & 0x01 )
V_34 -> V_58 |= V_59 ;
F_32 ( L_9 ,
V_2 -> V_5 , V_2 -> V_3 , V_2 -> V_6 ,
( ( V_60 * ) V_2 -> V_43 ) [ 3 ] ,
( ( V_60 * ) V_2 -> V_43 ) [ 4 ] ,
( ( V_60 * ) V_2 -> V_43 ) [ 5 ] ) ;
F_32 ( L_10 ,
V_2 -> V_5 ,
( ( V_34 -> V_58 & V_59 ) ? 500000 : 2000000 )
/ ( 1 << V_34 -> V_49 . V_50 ) ) ;
if( V_34 -> V_55 == 0 )
F_33 ( L_11 , V_34 -> V_52 ) ;
else
F_33 ( L_12 ) ;
#ifdef F_34
V_34 -> V_61 = V_2 ;
V_34 -> V_62 = NULL ;
#endif
V_63 [ V_17 ++ ] = V_2 ;
return V_2 ;
}
static T_2
F_35 ( struct V_64 * V_65 , struct V_1 * V_2 )
{
struct V_1 * V_66 ;
F_36 ( V_2 ) ;
for( V_66 = V_2 ; V_66 ; ) {
struct V_12 * V_34 = F_27 ( V_66 ) ;
F_37 ( & V_34 -> V_41 ) ;
if( V_34 -> V_67 || ( V_34 -> V_58 & V_68 ) ) {
V_66 = V_34 -> V_62 ;
F_38 ( & V_34 -> V_41 ) ;
} else {
F_39 ( V_65 , V_66 ) ;
F_38 ( & V_34 -> V_41 ) ;
F_40 ( V_2 ) ;
return V_69 ;
}
}
return V_70 ;
}
static T_2
F_35 ( struct V_64 * V_65 , struct V_1 * V_2 )
{
struct V_12 * V_34 = F_27 ( V_2 ) ;
F_36 ( V_2 ) ;
F_37 ( & V_34 -> V_41 ) ;
F_39 ( V_65 , V_2 ) ;
F_38 ( & V_34 -> V_41 ) ;
return V_69 ;
}
static T_3
F_41 ( int V_6 , void * V_71 )
{
struct V_1 * V_2 = V_71 ;
struct V_12 * V_34 = F_27 ( V_2 ) ;
int V_72 ;
F_37 ( & V_34 -> V_41 ) ;
if( V_34 -> V_73 )
F_37 ( & F_42 ( V_34 -> V_73 ) ) ;
do {
V_72 = 0 ;
if( F_31 ( V_2 -> V_3 + V_35 ) & ( V_74 | V_75 ) )
F_43 ( V_2 ) ,
V_72 = 1 ;
if( V_34 -> V_73 &&
( F_31 ( V_34 -> V_73 -> V_3 + V_35 ) & ( V_74 | V_75 ) ) )
F_43 ( V_34 -> V_73 ) ,
V_72 = 1 ;
} while( V_72 );
if( V_34 -> V_73 )
F_38 ( & F_42 ( V_34 -> V_73 ) ) ;
F_38 ( & V_34 -> V_41 ) ;
return V_76 ;
}
static void
F_43 ( struct V_1 * V_2 )
{
struct V_12 * V_34 = F_27 ( V_2 ) ;
unsigned long V_21 = V_2 -> V_3 ;
int V_77 ;
unsigned char V_78 ;
#ifdef F_34
if( V_34 -> V_58 & V_79 )
F_37 ( & F_42 ( V_34 -> V_61 ) ) ;
#endif
F_23 ( ( F_31 ( V_21 + V_35 ) & ~ V_37 ) | V_38 , V_21 + V_35 ) ;
V_34 -> V_80 = V_81 ;
for(; ; ) {
V_78 = F_31 ( V_21 + V_35 ) ;
if( ( V_78 & ( V_74 | V_75 ) ) == 0 )
break;
V_77 = ! ( V_34 -> V_58 & V_82 ) ;
if( V_78 & V_74 )
V_77 = F_44 ( V_2 ) ;
V_78 = F_31 ( V_21 + V_35 ) ;
if( ! ( V_78 & V_75 ) || ( V_78 & V_74 ) )
F_45 ( V_2 , L_13 ) ;
if( V_77 || V_34 -> V_83 != 0 )
F_46 ( V_2 ) ;
else
F_23 ( F_31 ( V_21 + V_35 ) & ~ V_38 , V_21 + V_35 ) ;
}
F_23 ( F_31 ( V_21 + V_35 ) | V_37 , V_21 + V_35 ) ;
#ifdef F_34
if( V_34 -> V_58 & V_79 )
F_38 ( & F_42 ( V_34 -> V_61 ) ) ;
#endif
}
static int
F_44 ( struct V_1 * V_2 )
{
struct V_12 * V_34 = F_27 ( V_2 ) ;
unsigned long V_21 = V_2 -> V_3 ;
V_46 V_84 = V_85 ;
unsigned V_86 = 0 , V_87 , V_88 ;
unsigned V_89 , V_90 = 0 ;
if( F_47 ( V_21 , & V_86 , & V_87 , & V_88 , & V_89 , & V_84 ) ) {
V_90 = V_86 > 4
? F_48 ( V_2 , V_86 , V_87 , V_89 , V_84 )
: F_49 ( V_21 , V_86 , V_84 ) ;
if( V_90 )
F_50 ( V_2 , V_88 ) ;
}
F_23 ( F_31 ( V_21 + V_35 ) ^ V_91 , V_21 + V_35 ) ;
if( V_90 ) {
V_34 -> V_58 |= V_82 ;
if( V_86 > 4 )
V_34 -> V_92 . V_93 ++ ;
} else
V_34 -> V_58 &= ~ V_82 ,
F_51 ( V_2 ) ,
V_34 -> V_92 . V_93 ++ ,
V_34 -> V_92 . V_94 ++ ;
return ! V_90 || V_86 > 4 ;
}
static void
F_46 ( struct V_1 * V_2 )
{
struct V_12 * V_34 = F_27 ( V_2 ) ;
V_46 V_84 = V_85 ;
if( V_34 -> V_58 & V_95 ) {
if( V_34 -> V_96 ) {
-- V_34 -> V_96 ;
if( V_34 -> V_86 != 0 )
V_34 -> V_92 . V_97 ++ ;
} else {
#ifdef F_34
if( ( V_34 -> V_58 & V_79 ) || V_34 -> V_62 )
#endif
V_34 -> V_58 |= V_68 ;
F_52 ( V_2 ) ;
goto V_98;
}
} else
V_34 -> V_96 = V_99 ;
F_53 ( V_2 , & V_84 ) ;
V_34 -> V_58 |= V_95 ;
if( V_34 -> V_86 ) {
F_54 ( V_2 , & V_84 ) ;
V_34 -> V_92 . V_100 ++ ;
V_34 -> V_58 |= V_101 ;
}
F_55 ( V_2 -> V_3 + V_102 , ( V_60 * ) & V_84 , sizeof V_84 ) ;
V_98:
F_23 ( F_31 ( V_2 -> V_3 + V_35 ) & ~ V_38 , V_2 -> V_3 + V_35 ) ;
if( V_34 -> V_83 )
F_23 ( F_31 ( V_2 -> V_3 + V_35 ) | V_38 ,
V_2 -> V_3 + V_35 ) ;
}
static void
F_54 ( struct V_1 * V_2 , V_46 * V_103 )
{
struct V_12 * V_34 = F_27 ( V_2 ) ;
struct V_64 * V_65 = V_34 -> V_67 ;
unsigned V_104 = F_56 (unsigned int, skb->len - nl->outpos, nl->framelen) ;
F_55 ( V_2 -> V_3 + V_102 , V_65 -> V_105 + V_34 -> V_106 , V_104 ) ;
* V_103 = F_57 ( * V_103 , V_65 -> V_105 + V_34 -> V_106 , V_104 ) ;
for( V_104 = V_34 -> V_86 - V_104 ; V_104 -- ; )
F_23 ( 0 , V_2 -> V_3 + V_102 ) ,
* V_103 = F_58 ( 0 , * V_103 ) ;
}
static int
F_48 ( struct V_1 * V_2 , unsigned V_86 , unsigned V_87 ,
unsigned V_89 , V_46 V_84 )
{
struct V_12 * V_34 = F_27 ( V_2 ) ;
int V_90 ;
if( V_89 )
V_34 -> V_107 = V_87 ,
V_34 -> V_108 = 0 ;
if( V_34 -> V_107 == V_87 ) {
if( V_34 -> V_108 + V_86 <= V_109 )
V_90 = F_59 ( V_2 , V_86 , V_84 ) ;
else if( ( V_90 = F_49 ( V_2 -> V_3 , V_86 , V_84 ) )
!= 0 )
V_34 -> V_107 = 0 ,
V_34 -> V_108 = 0 ,
#ifdef F_34
V_34 -> V_61 -> V_110 . V_111 ++ ,
V_34 -> V_61 -> V_110 . V_112 ++ ;
#else
V_2 -> V_110 . V_111 ++ ,
V_2 -> V_110 . V_112 ++ ;
#endif
} else
V_90 = F_49 ( V_2 -> V_3 , V_86 , V_84 ) ;
if( V_89 && ! V_90 )
V_34 -> V_107 = 0 ,
#ifdef F_34
V_34 -> V_61 -> V_110 . V_111 ++ ,
V_34 -> V_61 -> V_110 . V_113 ++ ;
#else
V_2 -> V_110 . V_111 ++ ,
V_2 -> V_110 . V_113 ++ ;
#endif
return V_90 ;
}
static inline void
F_60 ( struct V_1 * V_2 )
{
struct V_12 * V_34 = F_27 ( V_2 ) ;
#ifdef F_34
V_34 -> V_61 -> V_110 . V_114 ++ ;
V_34 -> V_61 -> V_110 . V_115 += V_34 -> V_67 -> V_104 ;
#else
V_2 -> V_110 . V_114 ++ ;
V_2 -> V_110 . V_115 += V_34 -> V_67 -> V_104 ;
#endif
F_61 ( V_34 -> V_67 ) ;
V_34 -> V_67 = NULL ;
V_34 -> V_106 = 0 ;
V_34 -> V_58 &= ~ ( V_101 | V_95 ) ;
V_34 -> V_86 = 0 ;
}
static void
F_50 ( struct V_1 * V_2 , unsigned V_88 )
{
struct V_12 * V_34 = F_27 ( V_2 ) ;
if( V_88 == V_116 ) {
V_34 -> V_58 &= ~ V_95 ;
if( V_34 -> V_58 & V_101 ) {
V_34 -> V_106 += V_34 -> V_86 ;
if( -- V_34 -> V_83 )
V_34 -> V_86 = F_56 (unsigned int,
nl->maxframe,
nl->tx_buf_p->len - nl->outpos) ;
else
F_60 ( V_2 ) ,
#ifdef F_34
F_62 ( V_34 -> V_61 ) ;
#else
F_62 ( V_2 ) ;
#endif
}
}
V_34 -> V_58 &= ~ V_101 ;
}
static int
F_59 ( struct V_1 * V_2 , unsigned V_86 , V_46 V_84 )
{
struct V_12 * V_34 = F_27 ( V_2 ) ;
V_60 * V_66 ;
if( V_34 -> V_108 + V_86 > V_109 )
return 0 ;
if( ! V_34 -> V_117 && ! ( V_34 -> V_117 = F_63 ( V_2 ) ) )
return 0 ;
V_66 = V_34 -> V_117 -> V_105 + V_34 -> V_108 ;
F_64 ( V_2 -> V_3 + V_102 , V_66 , V_86 ) ;
if( F_57 ( V_84 , V_66 , V_86 ) != V_118 )
return 0 ;
V_34 -> V_108 += V_86 - 4 ;
if( -- V_34 -> V_107 == 0 )
F_65 ( V_2 ) ;
return 1 ;
}
static void
F_39 ( struct V_64 * V_65 , struct V_1 * V_2 )
{
struct V_12 * V_34 = F_27 ( V_2 ) ;
unsigned int V_104 ;
if( V_34 -> V_67 )
F_45 ( V_2 , L_14 ) ;
V_34 -> V_106 = 0 ;
V_34 -> V_58 &= ~ ( V_101 | V_95 ) ;
V_104 = V_65 -> V_104 ;
if( V_104 < V_119 )
V_104 = V_119 ;
V_34 -> V_67 = V_65 ;
V_34 -> V_83 = F_66 ( V_104 , V_34 -> V_47 ) ;
V_34 -> V_86 = V_104 < V_34 -> V_47 ? V_104 : V_34 -> V_47 ;
F_23 ( F_31 ( V_2 -> V_3 + V_35 ) | V_38 , V_2 -> V_3 + V_35 ) ;
#ifdef F_34
V_34 -> V_61 -> V_120 = V_121 ;
#else
V_2 -> V_120 = V_121 ;
#endif
}
static void
F_52 ( struct V_1 * V_2 )
{
struct V_12 * V_34 = F_27 ( V_2 ) ;
if( V_34 -> V_67 )
F_67 ( V_34 -> V_67 ) ,
V_34 -> V_67 = NULL ,
#ifdef F_34
V_34 -> V_61 -> V_110 . V_122 ++ ,
V_34 -> V_61 -> V_110 . V_123 ++ ;
#else
V_2 -> V_110 . V_122 ++ ,
V_2 -> V_110 . V_123 ++ ;
#endif
V_34 -> V_83 = 0 ;
V_34 -> V_86 = 0 ;
V_34 -> V_106 = 0 ;
V_34 -> V_58 &= ~ ( V_101 | V_95 ) ;
#ifdef F_34
F_40 ( V_34 -> V_61 ) ;
V_34 -> V_61 -> V_120 = V_121 ;
#else
F_40 ( V_2 ) ;
V_2 -> V_120 = V_121 ;
#endif
}
static void
F_53 ( struct V_1 * V_2 , V_46 * V_103 )
{
struct V_12 * V_34 = F_27 ( V_2 ) ;
V_46 V_84 = * V_103 ;
V_46 V_124 = V_34 -> V_86 + 6 ;
V_60 V_125 ;
if( V_34 -> V_58 & V_95 )
V_124 |= V_126 ;
if( V_34 -> V_106 == 0 )
V_124 |= V_127 ;
V_124 |= ( V_34 -> V_58 & V_82 ) ? V_116 : V_128 ;
F_23 ( V_129 , V_2 -> V_3 + V_102 ) ;
V_125 = ( V_60 ) V_124 ;
F_23 ( V_125 , V_2 -> V_3 + V_102 ) ;
V_84 = F_58 ( V_125 , V_84 ) ;
V_125 = ( V_60 ) ( V_124 >> 8 ) ;
F_23 ( V_125 , V_2 -> V_3 + V_102 ) ;
V_84 = F_58 ( V_125 , V_84 ) ;
F_23 ( V_34 -> V_83 , V_2 -> V_3 + V_102 ) ;
V_84 = F_58 ( V_34 -> V_83 , V_84 ) ;
F_23 ( 0 , V_2 -> V_3 + V_102 ) ;
V_84 = F_58 ( 0 , V_84 ) ;
* V_103 = V_84 ;
}
static int
F_49 ( unsigned int V_21 , unsigned int V_130 , V_46 V_84 )
{
while( V_130 -- )
V_84 = F_58 ( F_31 ( V_21 + V_102 ) , V_84 ) ;
return V_84 == V_118 ;
}
static int
F_47 ( V_46 V_21 , V_46 * V_86 , V_46 * V_87 , V_46 * V_88 ,
V_46 * V_89 , V_46 * V_103 )
{
V_46 V_84 = * V_103 ;
V_60 V_125 ;
if( F_31 ( V_21 + V_102 ) != V_129 )
return 0 ;
V_125 = F_31 ( V_21 + V_102 ) ;
* V_86 = ( V_46 ) V_125 ;
V_84 = F_58 ( V_125 , V_84 ) ;
V_125 = F_31 ( V_21 + V_102 ) ;
* V_86 |= ( ( V_46 ) V_125 ) << 8 ;
V_84 = F_58 ( V_125 , V_84 ) ;
* V_88 = * V_86 & V_131 ;
* V_89 = ( * V_86 & V_127 ) != 0 ;
if( ( * V_86 &= V_132 ) < 6 ||
* V_86 > V_133 - 3 )
return 0 ;
V_125 = F_31 ( V_21 + V_102 ) ;
* V_87 = ( V_46 ) V_125 ;
V_84 = F_58 ( V_125 , V_84 ) ;
V_84 = F_58 ( F_31 ( V_21 + V_102 ) , V_84 ) ;
* V_86 -= 2 ;
* V_103 = V_84 ;
return 1 ;
}
static struct V_64 *
F_63 ( struct V_1 * V_2 )
{
struct V_64 * V_65 = F_68 ( V_109 + 2 ) ;
if( ! V_65 )
return NULL ;
F_69 ( V_65 , 2 ) ;
return V_65 ;
}
static void
F_65 ( struct V_1 * V_2 )
{
struct V_12 * V_34 = F_27 ( V_2 ) ;
struct V_64 * V_65 = V_34 -> V_117 ;
F_70 ( V_65 , V_34 -> V_108 ) ;
#ifdef F_34
V_65 -> V_134 = F_71 ( V_65 , V_34 -> V_61 ) ;
F_72 ( V_65 ) ;
++ V_34 -> V_61 -> V_110 . V_135 ;
V_34 -> V_61 -> V_110 . V_136 += V_34 -> V_108 ;
#else
V_65 -> V_134 = F_71 ( V_65 , V_2 ) ;
F_72 ( V_65 ) ;
++ V_2 -> V_110 . V_135 ;
V_2 -> V_110 . V_136 += V_34 -> V_108 ;
#endif
V_34 -> V_117 = NULL ;
}
static void
F_73 ( unsigned long V_137 )
{
struct V_1 * V_2 = (struct V_1 * ) V_137 ;
struct V_12 * V_34 = F_27 ( V_2 ) ;
struct V_138 * V_139 = & V_34 -> V_140 ;
unsigned long V_141 ;
unsigned char V_78 ;
F_74 ( & V_34 -> V_41 , V_141 ) ;
V_78 = F_31 ( V_2 -> V_3 + V_35 ) ;
if( V_78 & V_142 ) {
if( V_34 -> V_80 ) {
if( V_78 & ( V_74 | V_143 ) )
V_34 -> V_80 -- ;
} else {
V_34 -> V_92 . V_144 ++ ;
if( V_34 -> V_55 )
F_75 ( V_2 ) ;
F_23 ( * ( V_145 * ) & V_34 -> V_49 | V_39 ,
V_2 -> V_3 + V_40 ) ;
V_78 = F_31 ( V_2 -> V_3 + V_35 ) ;
}
} else
V_34 -> V_58 &= ~ V_68 ;
F_23 ( V_78 | V_142 , V_2 -> V_3 + V_35 ) ;
F_76 ( V_139 ) ;
V_139 -> V_146 = V_121 + V_147 ;
V_139 -> V_105 = V_137 ;
V_139 -> V_148 = F_73 ;
F_77 ( V_139 ) ;
F_78 ( & V_34 -> V_41 , V_141 ) ;
}
static void
F_79 ( struct V_1 * V_2 )
{
struct V_12 * V_34 = F_27 ( V_2 ) ;
V_34 -> V_80 = V_81 ;
V_34 -> V_58 &= ~ ( V_101 | V_95 ) ;
V_34 -> V_58 |= V_82 ;
V_34 -> V_108 = V_34 -> V_106 = 0 ;
V_34 -> V_107 = 0 ;
V_34 -> V_83 = 0 ;
V_34 -> V_86 = 0 ;
F_23 ( * ( V_145 * ) & V_34 -> V_49 | V_39 , V_2 -> V_3 + V_40 ) ;
F_23 ( V_37 , V_2 -> V_3 + V_35 ) ;
}
static void
F_51 ( struct V_1 * V_2 )
{
struct V_12 * V_34 = F_27 ( V_2 ) ;
if( V_34 -> V_55 == 0 )
return;
if( V_34 -> V_52 == 0 )
V_34 -> V_55 = 1 ;
else if( V_34 -> V_52 == 15 )
V_34 -> V_55 = - 1 ;
else if( V_34 -> V_149 < V_34 -> V_150 )
V_34 -> V_55 = - V_34 -> V_55 ;
V_34 -> V_49 . V_53 = V_57 [ V_34 -> V_52 += V_34 -> V_55 ] ;
F_31 ( V_2 -> V_3 + V_35 ) ;
F_23 ( * ( V_60 * ) & V_34 -> V_49 , V_2 -> V_3 + V_40 ) ;
V_34 -> V_150 = V_34 -> V_149 ;
V_34 -> V_149 = 0 ;
}
static void
F_75 ( struct V_1 * V_2 )
{
struct V_12 * V_34 = F_27 ( V_2 ) ;
V_34 -> V_52 = V_151 [ V_34 -> V_152 ] ;
if( ++ V_34 -> V_152 >= 4 )
V_34 -> V_152 = 0 ;
V_34 -> V_49 . V_53 = V_57 [ V_34 -> V_52 ] ;
F_31 ( V_2 -> V_3 + V_35 ) ;
F_23 ( * ( unsigned char * ) & V_34 -> V_49 , V_2 -> V_3 + V_40 ) ;
V_34 -> V_150 = V_34 -> V_149 ;
V_34 -> V_149 = 0 ;
}
static int
F_80 ( struct V_1 * V_2 )
{
struct V_12 * V_34 = F_27 ( V_2 ) ;
struct V_138 * V_139 = & V_34 -> V_140 ;
if( V_2 -> V_3 < 0x400 ) {
struct V_1 * * V_66 = V_63 ;
for( ; * V_66 && V_66 < V_63 + V_153 ; ++ V_66 )
if( ( * V_66 ) -> V_6 == V_2 -> V_6 &&
( ( * V_66 ) -> V_3 == V_2 -> V_3 + 4 ||
( * V_66 ) -> V_3 == V_2 -> V_3 - 4 ) &&
( * V_66 ) -> V_141 & V_154 ) {
( (struct V_12 * ) ( F_27 ( * V_66 ) ) )
-> V_73 = V_2 ;
F_81 ( V_2 , L_15 ,
( * V_66 ) -> V_5 ) ;
V_34 -> V_58 |= V_155 ;
goto V_156;
}
}
if( F_82 ( V_2 -> V_6 , F_41 , V_157 , V_2 -> V_5 , V_2 ) ) {
F_45 ( V_2 , L_16 , V_2 -> V_6 ) ;
return - V_158 ;
}
V_156:
F_37 ( & V_34 -> V_41 ) ;
memset ( & V_2 -> V_110 , 0 , sizeof( struct V_159 ) ) ;
memset ( & V_34 -> V_92 , 0 , sizeof( struct V_160 ) ) ;
F_79 ( V_2 ) ;
F_40 ( V_2 ) ;
F_76 ( V_139 ) ;
V_139 -> V_146 = V_121 + V_147 ;
V_139 -> V_105 = ( unsigned long ) V_2 ;
V_139 -> V_148 = F_73 ;
F_77 ( V_139 ) ;
F_38 ( & V_34 -> V_41 ) ;
return 0 ;
}
static int
F_83 ( struct V_1 * V_2 )
{
struct V_12 * V_34 = F_27 ( V_2 ) ;
if( V_34 -> V_73 && V_34 -> V_73 -> V_141 & V_154 ) {
F_81 ( V_2 , L_17 ,
V_34 -> V_73 -> V_5 ) ;
return - V_161 ;
}
#ifdef F_34
if( V_34 -> V_58 & V_79 )
F_84 ( V_2 ) ;
else
while( V_34 -> V_62 )
F_84 ( V_34 -> V_62 ) ;
#endif
F_37 ( & V_34 -> V_41 ) ;
V_34 -> V_73 = NULL ;
F_52 ( V_2 ) ;
F_36 ( V_2 ) ;
F_85 ( & V_34 -> V_140 ) ;
F_23 ( 0 , V_2 -> V_3 + V_35 ) ;
if( ! ( V_34 -> V_58 & V_155 ) )
F_86 ( V_2 -> V_6 , V_2 ) ;
V_34 -> V_58 &= V_155 ;
F_38 ( & V_34 -> V_41 ) ;
return 0 ;
}
static int
F_22 ( unsigned long V_21 )
{
unsigned char V_78 ;
V_78 = F_31 ( V_21 + V_35 ) ;
if( V_78 != 0xff && V_78 != 0x00 ) {
V_78 &= ~ V_37 ;
if( V_78 & V_143 )
V_78 |= V_37 ;
if( V_162 & ( 1 << ( V_78 >> 4 ) ) )
return 0 ;
}
return - V_7 ;
}
static int
F_87 ( struct V_1 * V_2 , struct V_163 * V_164 , int V_165 )
{
struct V_12 * V_34 = F_27 ( V_2 ) ;
struct V_166 V_141 ;
int error = 0 ;
#ifdef F_34
struct V_1 * V_167 ;
char V_168 [ 8 ] ;
#endif
switch( V_165 ) {
case V_169 :
if ( F_88 ( V_164 -> V_170 , & V_34 -> V_92 ,
sizeof( struct V_160 ) ) )
error = - V_171 ;
break;
case V_172 :
if ( ! F_89 ( V_173 ) )
return - V_174 ;
memset ( & V_34 -> V_92 , 0 , sizeof( struct V_160 ) ) ;
break;
case V_175 :
V_141 . V_176 = * ( V_46 * ) ( V_2 -> V_43 + 3 ) ;
V_141 . V_50 = V_34 -> V_49 . V_50 ;
V_141 . V_177 = ( V_34 -> V_58 & V_59 ) != 0 ;
V_141 . V_53 = V_34 -> V_52 ;
V_141 . V_178 = V_34 -> V_55 == 0 ;
if ( F_88 ( V_164 -> V_170 , & V_141 , sizeof V_141 ) )
error = - V_171 ;
break;
case V_179 :
if ( ! F_89 ( V_173 ) )
return - V_174 ;
F_37 ( & V_34 -> V_41 ) ;
V_141 = * (struct V_166 * ) & V_164 -> V_180 ;
if( V_141 . V_178 )
V_34 -> V_55 = 0 ,
V_34 -> V_52 = V_141 . V_53 ;
else
V_34 -> V_55 = V_56 ,
V_34 -> V_52 = V_54 ;
V_34 -> V_49 . V_53 = V_57 [ V_34 -> V_52 ] ;
V_34 -> V_49 . V_50 = V_141 . V_50 ;
F_23 ( * ( V_60 * ) & V_34 -> V_49 | V_39 , V_2 -> V_3 + V_40 ) ;
F_38 ( & V_34 -> V_41 ) ;
break;
#ifdef F_34
case V_181 :
if ( ! F_89 ( V_173 ) )
return - V_174 ;
if ( F_90 ( V_168 , V_164 -> V_170 , sizeof V_168 ) )
return - V_171 ;
V_167 = F_91 ( & V_182 , V_168 ) ;
if( ! V_167 || ! ( V_167 -> V_141 & V_154 ) ) {
F_45 ( V_2 , L_18 ,
V_168 ) ;
return - V_174 ;
}
return F_92 ( V_2 , V_167 ) ;
case V_183 :
if ( ! F_89 ( V_173 ) )
return - V_174 ;
return F_84 ( V_2 ) ;
#endif
default :
return - V_184 ;
}
return error ;
}
static int
F_92 ( struct V_1 * V_2 , struct V_1 * V_167 )
{
struct V_12 * V_34 = F_27 ( V_2 ) ;
struct V_12 * V_185 = F_27 ( V_167 ) ;
if( V_34 -> V_58 & V_79 )
return - V_161 ;
if( V_185 -> V_58 & V_79 )
return - V_161 ;
F_37 ( & V_34 -> V_41 ) ;
F_37 ( & V_185 -> V_41 ) ;
V_185 -> V_62 = V_34 -> V_62 ;
V_34 -> V_62 = V_167 ;
V_185 -> V_61 = V_2 ;
V_185 -> V_58 |= V_79 ;
memset ( & V_167 -> V_110 , 0 , sizeof( struct V_159 ) ) ;
F_36 ( V_167 ) ;
F_62 ( V_2 ) ;
F_38 ( & V_185 -> V_41 ) ;
F_38 ( & V_34 -> V_41 ) ;
F_81 ( V_2 , L_19 , V_167 -> V_5 ) ;
return 0 ;
}
static int
F_84 ( struct V_1 * V_2 )
{
struct V_12 * V_185 = F_27 ( V_2 ) ;
struct V_1 * V_66 = V_185 -> V_61 ;
struct V_12 * V_34 = F_27 ( V_66 ) ;
if( ! ( V_185 -> V_58 & V_79 ) )
return - V_186 ;
F_37 ( & V_34 -> V_41 ) ;
F_37 ( & V_185 -> V_41 ) ;
F_52 ( V_2 ) ;
for(; ; ) {
struct V_12 * V_187 = F_27 ( V_66 ) ;
if( V_187 -> V_62 == V_2 ) {
V_187 -> V_62 = V_185 -> V_62 ;
break;
}
V_66 = V_187 -> V_62 ;
}
V_185 -> V_62 = NULL ;
V_185 -> V_61 = V_2 ;
V_185 -> V_58 &= ~ V_79 ;
F_40 ( V_2 ) ;
F_38 ( & V_185 -> V_41 ) ;
F_38 ( & V_34 -> V_41 ) ;
F_93 ( V_2 ) ;
return 0 ;
}
static void
F_94 ( struct V_1 * V_2 )
{
return;
}
int T_1 F_95 ( void )
{
struct V_1 * V_2 ;
int V_11 ;
while( V_17 < V_153 ) {
V_2 = F_8 ( sizeof( struct V_12 ) ,
L_3 , F_5 ) ;
if( ! V_2 )
break;
sprintf ( V_2 -> V_5 , L_3 , V_17 ) ;
V_11 = F_10 ( V_2 ) ;
if ( V_11 ) {
F_11 ( V_2 ) ;
break;
}
if( F_12 ( V_2 ) ) {
F_13 ( V_2 -> V_3 , V_4 ) ;
F_11 ( V_2 ) ;
break;
}
}
return * V_63 ? 0 : - V_7 ;
}
void
F_96 ( void )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_153 ; ++ V_15 ) {
struct V_1 * V_2 = V_63 [ V_15 ] ;
if ( V_2 != NULL ) {
F_97 ( V_2 ) ;
F_13 ( V_2 -> V_3 , V_4 ) ;
F_11 ( V_2 ) ;
}
}
}
static int T_1
F_98 ( char * V_66 )
{
int V_188 , V_189 ;
if( * V_66 ++ != '(' )
goto V_190;
for( V_188 = 0 , V_189 = 0 ; * V_66 && V_188 < 8 ; ) {
( * V_191 [ V_189 ] ) [ V_188 ] = F_99 ( V_66 , & V_66 , 0 ) ;
if( ! * V_66 || * V_66 == ')' )
return 1 ;
if( * V_66 == ';' )
++ V_66 , ++ V_188 , V_189 = 0 ;
else if( * V_66 ++ != ',' )
break;
else
if( ++ V_189 >= 5 )
break;
}
V_190:
F_4 ( L_20 ) ;
return 0 ;
}
static V_46
F_57 ( V_46 V_84 , V_60 * V_66 , V_46 V_104 )
{
while( V_104 -- )
V_84 = F_58 ( * V_66 ++ , V_84 ) ;
return V_84 ;
}
