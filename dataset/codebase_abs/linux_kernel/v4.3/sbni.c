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
V_2 = F_8 ( sizeof( struct V_12 ) , L_2 ,
V_13 , F_5 ) ;
if ( ! V_2 )
return - V_14 ;
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
F_14 ( L_4 , V_15 ) ;
return 0 ;
}
static int T_1 F_10 ( struct V_1 * V_2 )
{
int V_16 ;
if( V_2 -> V_3 )
return F_1 ( V_2 ) ;
if( V_17 [ V_18 ] != - 1 )
V_2 -> V_3 = V_17 [ V_18 ] ,
V_2 -> V_6 = V_6 [ V_18 ] ;
else if( V_19 || V_17 [ 0 ] != - 1 )
return - V_7 ;
if( V_2 -> V_3 )
return F_1 ( V_2 ) ;
if( ! V_20 && ! F_15 ( V_2 ) )
return 0 ;
if( V_17 [ V_18 ] == - 1 ) {
V_19 = 1 ;
if( V_18 > 0 )
return - V_7 ;
}
for( V_16 = 0 ; V_21 [ V_16 ] ; ++ V_16 ) {
int V_22 = V_21 [ V_16 ] ;
if( F_2 ( V_22 , V_4 , V_2 -> V_5 ) &&
F_3 ( V_2 , V_22 , 0 ) )
return 0 ;
}
return - V_7 ;
}
static int T_1
F_15 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = NULL ;
while( ( V_24 = F_16 ( V_25 << 8 , V_24 ) )
!= NULL ) {
int V_26 ;
unsigned long V_27 ;
if( V_24 -> V_28 != V_29 &&
V_24 -> V_30 != V_31 )
continue;
V_27 = F_17 ( V_24 , 0 ) ;
V_26 = V_24 -> V_6 ;
if( ! F_2 ( V_27 , V_4 , V_2 -> V_5 ) ) {
if ( V_24 -> V_32 != 2 )
continue;
if ( ! F_2 ( V_27 += 4 , V_4 ,
V_2 -> V_5 ) )
continue;
}
if ( V_26 <= 0 || V_26 >= V_33 )
F_18 (
L_5
L_6 ,
V_26 ) ;
if( ( V_27 & 7 ) == 0 && F_19 ( V_24 ) ) {
F_13 ( V_27 , V_4 ) ;
F_20 ( V_24 ) ;
return - V_34 ;
}
if( F_3 ( V_2 , V_27 , V_26 ) ) {
F_21 ( V_2 , & V_24 -> V_2 ) ;
F_20 ( V_24 ) ;
return 0 ;
}
}
return - V_7 ;
}
static struct V_1 * T_1
F_3 ( struct V_1 * V_2 , unsigned long V_22 , int V_6 )
{
struct V_12 * V_35 ;
if( F_22 ( V_22 ) ) {
F_13 ( V_22 , V_4 ) ;
return NULL ;
}
F_23 ( 0 , V_22 + V_36 ) ;
if( V_6 < 2 ) {
unsigned long V_37 ;
V_37 = F_24 () ;
F_23 ( V_38 | V_39 , V_22 + V_36 ) ;
F_23 ( V_40 , V_22 + V_41 ) ;
F_25 ( 50 ) ;
V_6 = F_26 ( V_37 ) ;
F_23 ( 0 , V_22 + V_36 ) ;
if( ! V_6 ) {
F_4 ( L_7 , V_2 -> V_5 ) ;
F_13 ( V_22 , V_4 ) ;
return NULL ;
}
} else if( V_6 == 2 )
V_6 = 9 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_3 = V_22 ;
V_35 = F_27 ( V_2 ) ;
if( ! V_35 ) {
F_4 ( L_8 , V_2 -> V_5 ) ;
F_13 ( V_22 , V_4 ) ;
return NULL ;
}
memset ( V_35 , 0 , sizeof( struct V_12 ) ) ;
F_28 ( & V_35 -> V_42 ) ;
* ( V_43 * ) V_2 -> V_44 = F_29 ( 0x00ff ) ;
* ( V_45 * ) ( V_2 -> V_44 + 2 ) = F_30 ( 0x01000000 |
( ( V_46 [ V_18 ] ?
V_46 [ V_18 ] :
( V_47 ) ( ( long ) F_27 ( V_2 ) ) ) & 0x00ffffff ) ) ;
V_35 -> V_48 = V_49 ;
V_35 -> V_50 . V_51 = V_52 [ V_18 ] ;
if( ( V_35 -> V_53 = V_54 [ V_18 ] ) == - 1 )
V_35 -> V_53 = V_55 ,
V_35 -> V_56 = V_57 ;
else
V_35 -> V_56 = 0 ;
V_35 -> V_50 . V_54 = V_58 [ V_35 -> V_53 ] ;
if( F_31 ( V_22 + V_36 ) & 0x01 )
V_35 -> V_59 |= V_60 ;
F_32 ( L_9 ,
V_2 -> V_5 , V_2 -> V_3 , V_2 -> V_6 ,
( ( V_61 * ) V_2 -> V_44 ) [ 3 ] ,
( ( V_61 * ) V_2 -> V_44 ) [ 4 ] ,
( ( V_61 * ) V_2 -> V_44 ) [ 5 ] ) ;
F_32 ( L_10 ,
V_2 -> V_5 ,
( ( V_35 -> V_59 & V_60 ) ? 500000 : 2000000 )
/ ( 1 << V_35 -> V_50 . V_51 ) ) ;
if( V_35 -> V_56 == 0 )
F_33 ( L_11 , V_35 -> V_53 ) ;
else
F_33 ( L_12 ) ;
#ifdef F_34
V_35 -> V_62 = V_2 ;
V_35 -> V_63 = NULL ;
#endif
V_64 [ V_18 ++ ] = V_2 ;
return V_2 ;
}
static T_2
F_35 ( struct V_65 * V_66 , struct V_1 * V_2 )
{
struct V_1 * V_67 ;
F_36 ( V_2 ) ;
for( V_67 = V_2 ; V_67 ; ) {
struct V_12 * V_35 = F_27 ( V_67 ) ;
F_37 ( & V_35 -> V_42 ) ;
if( V_35 -> V_68 || ( V_35 -> V_59 & V_69 ) ) {
V_67 = V_35 -> V_63 ;
F_38 ( & V_35 -> V_42 ) ;
} else {
F_39 ( V_66 , V_67 ) ;
F_38 ( & V_35 -> V_42 ) ;
F_40 ( V_2 ) ;
return V_70 ;
}
}
return V_71 ;
}
static T_2
F_35 ( struct V_65 * V_66 , struct V_1 * V_2 )
{
struct V_12 * V_35 = F_27 ( V_2 ) ;
F_36 ( V_2 ) ;
F_37 ( & V_35 -> V_42 ) ;
F_39 ( V_66 , V_2 ) ;
F_38 ( & V_35 -> V_42 ) ;
return V_70 ;
}
static T_3
F_41 ( int V_6 , void * V_72 )
{
struct V_1 * V_2 = V_72 ;
struct V_12 * V_35 = F_27 ( V_2 ) ;
int V_73 ;
F_37 ( & V_35 -> V_42 ) ;
if( V_35 -> V_74 )
F_37 ( & F_42 ( V_35 -> V_74 ) ) ;
do {
V_73 = 0 ;
if( F_31 ( V_2 -> V_3 + V_36 ) & ( V_75 | V_76 ) )
F_43 ( V_2 ) ,
V_73 = 1 ;
if( V_35 -> V_74 &&
( F_31 ( V_35 -> V_74 -> V_3 + V_36 ) & ( V_75 | V_76 ) ) )
F_43 ( V_35 -> V_74 ) ,
V_73 = 1 ;
} while( V_73 );
if( V_35 -> V_74 )
F_38 ( & F_42 ( V_35 -> V_74 ) ) ;
F_38 ( & V_35 -> V_42 ) ;
return V_77 ;
}
static void
F_43 ( struct V_1 * V_2 )
{
struct V_12 * V_35 = F_27 ( V_2 ) ;
unsigned long V_22 = V_2 -> V_3 ;
int V_78 ;
unsigned char V_79 ;
#ifdef F_34
if( V_35 -> V_59 & V_80 )
F_37 ( & F_42 ( V_35 -> V_62 ) ) ;
#endif
F_23 ( ( F_31 ( V_22 + V_36 ) & ~ V_38 ) | V_39 , V_22 + V_36 ) ;
V_35 -> V_81 = V_82 ;
for(; ; ) {
V_79 = F_31 ( V_22 + V_36 ) ;
if( ( V_79 & ( V_75 | V_76 ) ) == 0 )
break;
V_78 = ! ( V_35 -> V_59 & V_83 ) ;
if( V_79 & V_75 )
V_78 = F_44 ( V_2 ) ;
V_79 = F_31 ( V_22 + V_36 ) ;
if( ! ( V_79 & V_76 ) || ( V_79 & V_75 ) )
F_45 ( V_2 , L_13 ) ;
if( V_78 || V_35 -> V_84 != 0 )
F_46 ( V_2 ) ;
else
F_23 ( F_31 ( V_22 + V_36 ) & ~ V_39 , V_22 + V_36 ) ;
}
F_23 ( F_31 ( V_22 + V_36 ) | V_38 , V_22 + V_36 ) ;
#ifdef F_34
if( V_35 -> V_59 & V_80 )
F_38 ( & F_42 ( V_35 -> V_62 ) ) ;
#endif
}
static int
F_44 ( struct V_1 * V_2 )
{
struct V_12 * V_35 = F_27 ( V_2 ) ;
unsigned long V_22 = V_2 -> V_3 ;
V_47 V_85 = V_86 ;
unsigned V_87 = 0 , V_88 , V_89 ;
unsigned V_90 , V_91 = 0 ;
if( F_47 ( V_22 , & V_87 , & V_88 , & V_89 , & V_90 , & V_85 ) ) {
V_91 = V_87 > 4
? F_48 ( V_2 , V_87 , V_88 , V_90 , V_85 )
: F_49 ( V_22 , V_87 , V_85 ) ;
if( V_91 )
F_50 ( V_2 , V_89 ) ;
}
F_23 ( F_31 ( V_22 + V_36 ) ^ V_92 , V_22 + V_36 ) ;
if( V_91 ) {
V_35 -> V_59 |= V_83 ;
if( V_87 > 4 )
V_35 -> V_93 . V_94 ++ ;
} else
V_35 -> V_59 &= ~ V_83 ,
F_51 ( V_2 ) ,
V_35 -> V_93 . V_94 ++ ,
V_35 -> V_93 . V_95 ++ ;
return ! V_91 || V_87 > 4 ;
}
static void
F_46 ( struct V_1 * V_2 )
{
struct V_12 * V_35 = F_27 ( V_2 ) ;
V_47 V_85 = V_86 ;
if( V_35 -> V_59 & V_96 ) {
if( V_35 -> V_97 ) {
-- V_35 -> V_97 ;
if( V_35 -> V_87 != 0 )
V_35 -> V_93 . V_98 ++ ;
} else {
#ifdef F_34
if( ( V_35 -> V_59 & V_80 ) || V_35 -> V_63 )
#endif
V_35 -> V_59 |= V_69 ;
F_52 ( V_2 ) ;
goto V_99;
}
} else
V_35 -> V_97 = V_100 ;
F_53 ( V_2 , & V_85 ) ;
V_35 -> V_59 |= V_96 ;
if( V_35 -> V_87 ) {
F_54 ( V_2 , & V_85 ) ;
V_35 -> V_93 . V_101 ++ ;
V_35 -> V_59 |= V_102 ;
}
F_55 ( V_2 -> V_3 + V_103 , ( V_61 * ) & V_85 , sizeof V_85 ) ;
V_99:
F_23 ( F_31 ( V_2 -> V_3 + V_36 ) & ~ V_39 , V_2 -> V_3 + V_36 ) ;
if( V_35 -> V_84 )
F_23 ( F_31 ( V_2 -> V_3 + V_36 ) | V_39 ,
V_2 -> V_3 + V_36 ) ;
}
static void
F_54 ( struct V_1 * V_2 , V_47 * V_104 )
{
struct V_12 * V_35 = F_27 ( V_2 ) ;
struct V_65 * V_66 = V_35 -> V_68 ;
unsigned V_105 = F_56 (unsigned int, skb->len - nl->outpos, nl->framelen) ;
F_55 ( V_2 -> V_3 + V_103 , V_66 -> V_106 + V_35 -> V_107 , V_105 ) ;
* V_104 = F_57 ( * V_104 , V_66 -> V_106 + V_35 -> V_107 , V_105 ) ;
for( V_105 = V_35 -> V_87 - V_105 ; V_105 -- ; )
F_23 ( 0 , V_2 -> V_3 + V_103 ) ,
* V_104 = F_58 ( 0 , * V_104 ) ;
}
static int
F_48 ( struct V_1 * V_2 , unsigned V_87 , unsigned V_88 ,
unsigned V_90 , V_47 V_85 )
{
struct V_12 * V_35 = F_27 ( V_2 ) ;
int V_91 ;
if( V_90 )
V_35 -> V_108 = V_88 ,
V_35 -> V_109 = 0 ;
if( V_35 -> V_108 == V_88 ) {
if( V_35 -> V_109 + V_87 <= V_110 )
V_91 = F_59 ( V_2 , V_87 , V_85 ) ;
else if( ( V_91 = F_49 ( V_2 -> V_3 , V_87 , V_85 ) )
!= 0 )
V_35 -> V_108 = 0 ,
V_35 -> V_109 = 0 ,
#ifdef F_34
V_35 -> V_62 -> V_111 . V_112 ++ ,
V_35 -> V_62 -> V_111 . V_113 ++ ;
#else
V_2 -> V_111 . V_112 ++ ,
V_2 -> V_111 . V_113 ++ ;
#endif
} else
V_91 = F_49 ( V_2 -> V_3 , V_87 , V_85 ) ;
if( V_90 && ! V_91 )
V_35 -> V_108 = 0 ,
#ifdef F_34
V_35 -> V_62 -> V_111 . V_112 ++ ,
V_35 -> V_62 -> V_111 . V_114 ++ ;
#else
V_2 -> V_111 . V_112 ++ ,
V_2 -> V_111 . V_114 ++ ;
#endif
return V_91 ;
}
static inline void
F_60 ( struct V_1 * V_2 )
{
struct V_12 * V_35 = F_27 ( V_2 ) ;
#ifdef F_34
V_35 -> V_62 -> V_111 . V_115 ++ ;
V_35 -> V_62 -> V_111 . V_116 += V_35 -> V_68 -> V_105 ;
#else
V_2 -> V_111 . V_115 ++ ;
V_2 -> V_111 . V_116 += V_35 -> V_68 -> V_105 ;
#endif
F_61 ( V_35 -> V_68 ) ;
V_35 -> V_68 = NULL ;
V_35 -> V_107 = 0 ;
V_35 -> V_59 &= ~ ( V_102 | V_96 ) ;
V_35 -> V_87 = 0 ;
}
static void
F_50 ( struct V_1 * V_2 , unsigned V_89 )
{
struct V_12 * V_35 = F_27 ( V_2 ) ;
if( V_89 == V_117 ) {
V_35 -> V_59 &= ~ V_96 ;
if( V_35 -> V_59 & V_102 ) {
V_35 -> V_107 += V_35 -> V_87 ;
if( -- V_35 -> V_84 )
V_35 -> V_87 = F_56 (unsigned int,
nl->maxframe,
nl->tx_buf_p->len - nl->outpos) ;
else
F_60 ( V_2 ) ,
#ifdef F_34
F_62 ( V_35 -> V_62 ) ;
#else
F_62 ( V_2 ) ;
#endif
}
}
V_35 -> V_59 &= ~ V_102 ;
}
static int
F_59 ( struct V_1 * V_2 , unsigned V_87 , V_47 V_85 )
{
struct V_12 * V_35 = F_27 ( V_2 ) ;
V_61 * V_67 ;
if( V_35 -> V_109 + V_87 > V_110 )
return 0 ;
if( ! V_35 -> V_118 && ! ( V_35 -> V_118 = F_63 ( V_2 ) ) )
return 0 ;
V_67 = V_35 -> V_118 -> V_106 + V_35 -> V_109 ;
F_64 ( V_2 -> V_3 + V_103 , V_67 , V_87 ) ;
if( F_57 ( V_85 , V_67 , V_87 ) != V_119 )
return 0 ;
V_35 -> V_109 += V_87 - 4 ;
if( -- V_35 -> V_108 == 0 )
F_65 ( V_2 ) ;
return 1 ;
}
static void
F_39 ( struct V_65 * V_66 , struct V_1 * V_2 )
{
struct V_12 * V_35 = F_27 ( V_2 ) ;
unsigned int V_105 ;
if( V_35 -> V_68 )
F_45 ( V_2 , L_14 ) ;
V_35 -> V_107 = 0 ;
V_35 -> V_59 &= ~ ( V_102 | V_96 ) ;
V_105 = V_66 -> V_105 ;
if( V_105 < V_120 )
V_105 = V_120 ;
V_35 -> V_68 = V_66 ;
V_35 -> V_84 = F_66 ( V_105 , V_35 -> V_48 ) ;
V_35 -> V_87 = V_105 < V_35 -> V_48 ? V_105 : V_35 -> V_48 ;
F_23 ( F_31 ( V_2 -> V_3 + V_36 ) | V_39 , V_2 -> V_3 + V_36 ) ;
#ifdef F_34
V_35 -> V_62 -> V_121 = V_122 ;
#else
V_2 -> V_121 = V_122 ;
#endif
}
static void
F_52 ( struct V_1 * V_2 )
{
struct V_12 * V_35 = F_27 ( V_2 ) ;
if( V_35 -> V_68 )
F_67 ( V_35 -> V_68 ) ,
V_35 -> V_68 = NULL ,
#ifdef F_34
V_35 -> V_62 -> V_111 . V_123 ++ ,
V_35 -> V_62 -> V_111 . V_124 ++ ;
#else
V_2 -> V_111 . V_123 ++ ,
V_2 -> V_111 . V_124 ++ ;
#endif
V_35 -> V_84 = 0 ;
V_35 -> V_87 = 0 ;
V_35 -> V_107 = 0 ;
V_35 -> V_59 &= ~ ( V_102 | V_96 ) ;
#ifdef F_34
F_40 ( V_35 -> V_62 ) ;
V_35 -> V_62 -> V_121 = V_122 ;
#else
F_40 ( V_2 ) ;
V_2 -> V_121 = V_122 ;
#endif
}
static void
F_53 ( struct V_1 * V_2 , V_47 * V_104 )
{
struct V_12 * V_35 = F_27 ( V_2 ) ;
V_47 V_85 = * V_104 ;
V_47 V_125 = V_35 -> V_87 + 6 ;
V_61 V_126 ;
if( V_35 -> V_59 & V_96 )
V_125 |= V_127 ;
if( V_35 -> V_107 == 0 )
V_125 |= V_128 ;
V_125 |= ( V_35 -> V_59 & V_83 ) ? V_117 : V_129 ;
F_23 ( V_130 , V_2 -> V_3 + V_103 ) ;
V_126 = ( V_61 ) V_125 ;
F_23 ( V_126 , V_2 -> V_3 + V_103 ) ;
V_85 = F_58 ( V_126 , V_85 ) ;
V_126 = ( V_61 ) ( V_125 >> 8 ) ;
F_23 ( V_126 , V_2 -> V_3 + V_103 ) ;
V_85 = F_58 ( V_126 , V_85 ) ;
F_23 ( V_35 -> V_84 , V_2 -> V_3 + V_103 ) ;
V_85 = F_58 ( V_35 -> V_84 , V_85 ) ;
F_23 ( 0 , V_2 -> V_3 + V_103 ) ;
V_85 = F_58 ( 0 , V_85 ) ;
* V_104 = V_85 ;
}
static int
F_49 ( unsigned int V_22 , unsigned int V_131 , V_47 V_85 )
{
while( V_131 -- )
V_85 = F_58 ( F_31 ( V_22 + V_103 ) , V_85 ) ;
return V_85 == V_119 ;
}
static int
F_47 ( V_47 V_22 , V_47 * V_87 , V_47 * V_88 , V_47 * V_89 ,
V_47 * V_90 , V_47 * V_104 )
{
V_47 V_85 = * V_104 ;
V_61 V_126 ;
if( F_31 ( V_22 + V_103 ) != V_130 )
return 0 ;
V_126 = F_31 ( V_22 + V_103 ) ;
* V_87 = ( V_47 ) V_126 ;
V_85 = F_58 ( V_126 , V_85 ) ;
V_126 = F_31 ( V_22 + V_103 ) ;
* V_87 |= ( ( V_47 ) V_126 ) << 8 ;
V_85 = F_58 ( V_126 , V_85 ) ;
* V_89 = * V_87 & V_132 ;
* V_90 = ( * V_87 & V_128 ) != 0 ;
if( ( * V_87 &= V_133 ) < 6 ||
* V_87 > V_134 - 3 )
return 0 ;
V_126 = F_31 ( V_22 + V_103 ) ;
* V_88 = ( V_47 ) V_126 ;
V_85 = F_58 ( V_126 , V_85 ) ;
V_85 = F_58 ( F_31 ( V_22 + V_103 ) , V_85 ) ;
* V_87 -= 2 ;
* V_104 = V_85 ;
return 1 ;
}
static struct V_65 *
F_63 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = F_68 ( V_110 + 2 ) ;
if( ! V_66 )
return NULL ;
F_69 ( V_66 , 2 ) ;
return V_66 ;
}
static void
F_65 ( struct V_1 * V_2 )
{
struct V_12 * V_35 = F_27 ( V_2 ) ;
struct V_65 * V_66 = V_35 -> V_118 ;
F_70 ( V_66 , V_35 -> V_109 ) ;
#ifdef F_34
V_66 -> V_135 = F_71 ( V_66 , V_35 -> V_62 ) ;
F_72 ( V_66 ) ;
++ V_35 -> V_62 -> V_111 . V_136 ;
V_35 -> V_62 -> V_111 . V_137 += V_35 -> V_109 ;
#else
V_66 -> V_135 = F_71 ( V_66 , V_2 ) ;
F_72 ( V_66 ) ;
++ V_2 -> V_111 . V_136 ;
V_2 -> V_111 . V_137 += V_35 -> V_109 ;
#endif
V_35 -> V_118 = NULL ;
}
static void
F_73 ( unsigned long V_138 )
{
struct V_1 * V_2 = (struct V_1 * ) V_138 ;
struct V_12 * V_35 = F_27 ( V_2 ) ;
struct V_139 * V_140 = & V_35 -> V_141 ;
unsigned long V_142 ;
unsigned char V_79 ;
F_74 ( & V_35 -> V_42 , V_142 ) ;
V_79 = F_31 ( V_2 -> V_3 + V_36 ) ;
if( V_79 & V_143 ) {
if( V_35 -> V_81 ) {
if( V_79 & ( V_75 | V_144 ) )
V_35 -> V_81 -- ;
} else {
V_35 -> V_93 . V_145 ++ ;
if( V_35 -> V_56 )
F_75 ( V_2 ) ;
F_23 ( * ( V_146 * ) & V_35 -> V_50 | V_40 ,
V_2 -> V_3 + V_41 ) ;
V_79 = F_31 ( V_2 -> V_3 + V_36 ) ;
}
} else
V_35 -> V_59 &= ~ V_69 ;
F_23 ( V_79 | V_143 , V_2 -> V_3 + V_36 ) ;
F_76 ( V_140 ) ;
V_140 -> V_147 = V_122 + V_148 ;
V_140 -> V_106 = V_138 ;
V_140 -> V_149 = F_73 ;
F_77 ( V_140 ) ;
F_78 ( & V_35 -> V_42 , V_142 ) ;
}
static void
F_79 ( struct V_1 * V_2 )
{
struct V_12 * V_35 = F_27 ( V_2 ) ;
V_35 -> V_81 = V_82 ;
V_35 -> V_59 &= ~ ( V_102 | V_96 ) ;
V_35 -> V_59 |= V_83 ;
V_35 -> V_109 = V_35 -> V_107 = 0 ;
V_35 -> V_108 = 0 ;
V_35 -> V_84 = 0 ;
V_35 -> V_87 = 0 ;
F_23 ( * ( V_146 * ) & V_35 -> V_50 | V_40 , V_2 -> V_3 + V_41 ) ;
F_23 ( V_38 , V_2 -> V_3 + V_36 ) ;
}
static void
F_51 ( struct V_1 * V_2 )
{
struct V_12 * V_35 = F_27 ( V_2 ) ;
if( V_35 -> V_56 == 0 )
return;
if( V_35 -> V_53 == 0 )
V_35 -> V_56 = 1 ;
else if( V_35 -> V_53 == 15 )
V_35 -> V_56 = - 1 ;
else if( V_35 -> V_150 < V_35 -> V_151 )
V_35 -> V_56 = - V_35 -> V_56 ;
V_35 -> V_50 . V_54 = V_58 [ V_35 -> V_53 += V_35 -> V_56 ] ;
F_31 ( V_2 -> V_3 + V_36 ) ;
F_23 ( * ( V_61 * ) & V_35 -> V_50 , V_2 -> V_3 + V_41 ) ;
V_35 -> V_151 = V_35 -> V_150 ;
V_35 -> V_150 = 0 ;
}
static void
F_75 ( struct V_1 * V_2 )
{
struct V_12 * V_35 = F_27 ( V_2 ) ;
V_35 -> V_53 = V_152 [ V_35 -> V_153 ] ;
if( ++ V_35 -> V_153 >= 4 )
V_35 -> V_153 = 0 ;
V_35 -> V_50 . V_54 = V_58 [ V_35 -> V_53 ] ;
F_31 ( V_2 -> V_3 + V_36 ) ;
F_23 ( * ( unsigned char * ) & V_35 -> V_50 , V_2 -> V_3 + V_41 ) ;
V_35 -> V_151 = V_35 -> V_150 ;
V_35 -> V_150 = 0 ;
}
static int
F_80 ( struct V_1 * V_2 )
{
struct V_12 * V_35 = F_27 ( V_2 ) ;
struct V_139 * V_140 = & V_35 -> V_141 ;
if( V_2 -> V_3 < 0x400 ) {
struct V_1 * * V_67 = V_64 ;
for( ; * V_67 && V_67 < V_64 + V_154 ; ++ V_67 )
if( ( * V_67 ) -> V_6 == V_2 -> V_6 &&
( ( * V_67 ) -> V_3 == V_2 -> V_3 + 4 ||
( * V_67 ) -> V_3 == V_2 -> V_3 - 4 ) &&
( * V_67 ) -> V_142 & V_155 ) {
( (struct V_12 * ) ( F_27 ( * V_67 ) ) )
-> V_74 = V_2 ;
F_81 ( V_2 , L_15 ,
( * V_67 ) -> V_5 ) ;
V_35 -> V_59 |= V_156 ;
goto V_157;
}
}
if( F_82 ( V_2 -> V_6 , F_41 , V_158 , V_2 -> V_5 , V_2 ) ) {
F_45 ( V_2 , L_16 , V_2 -> V_6 ) ;
return - V_159 ;
}
V_157:
F_37 ( & V_35 -> V_42 ) ;
memset ( & V_2 -> V_111 , 0 , sizeof( struct V_160 ) ) ;
memset ( & V_35 -> V_93 , 0 , sizeof( struct V_161 ) ) ;
F_79 ( V_2 ) ;
F_40 ( V_2 ) ;
F_76 ( V_140 ) ;
V_140 -> V_147 = V_122 + V_148 ;
V_140 -> V_106 = ( unsigned long ) V_2 ;
V_140 -> V_149 = F_73 ;
F_77 ( V_140 ) ;
F_38 ( & V_35 -> V_42 ) ;
return 0 ;
}
static int
F_83 ( struct V_1 * V_2 )
{
struct V_12 * V_35 = F_27 ( V_2 ) ;
if( V_35 -> V_74 && V_35 -> V_74 -> V_142 & V_155 ) {
F_81 ( V_2 , L_17 ,
V_35 -> V_74 -> V_5 ) ;
return - V_162 ;
}
#ifdef F_34
if( V_35 -> V_59 & V_80 )
F_84 ( V_2 ) ;
else
while( V_35 -> V_63 )
F_84 ( V_35 -> V_63 ) ;
#endif
F_37 ( & V_35 -> V_42 ) ;
V_35 -> V_74 = NULL ;
F_52 ( V_2 ) ;
F_36 ( V_2 ) ;
F_85 ( & V_35 -> V_141 ) ;
F_23 ( 0 , V_2 -> V_3 + V_36 ) ;
if( ! ( V_35 -> V_59 & V_156 ) )
F_86 ( V_2 -> V_6 , V_2 ) ;
V_35 -> V_59 &= V_156 ;
F_38 ( & V_35 -> V_42 ) ;
return 0 ;
}
static int
F_22 ( unsigned long V_22 )
{
unsigned char V_79 ;
V_79 = F_31 ( V_22 + V_36 ) ;
if( V_79 != 0xff && V_79 != 0x00 ) {
V_79 &= ~ V_38 ;
if( V_79 & V_144 )
V_79 |= V_38 ;
if( V_163 & ( 1 << ( V_79 >> 4 ) ) )
return 0 ;
}
return - V_7 ;
}
static int
F_87 ( struct V_1 * V_2 , struct V_164 * V_165 , int V_166 )
{
struct V_12 * V_35 = F_27 ( V_2 ) ;
struct V_167 V_142 ;
int error = 0 ;
#ifdef F_34
struct V_1 * V_168 ;
char V_169 [ 8 ] ;
#endif
switch( V_166 ) {
case V_170 :
if ( F_88 ( V_165 -> V_171 , & V_35 -> V_93 ,
sizeof( struct V_161 ) ) )
error = - V_172 ;
break;
case V_173 :
if ( ! F_89 ( V_174 ) )
return - V_175 ;
memset ( & V_35 -> V_93 , 0 , sizeof( struct V_161 ) ) ;
break;
case V_176 :
V_142 . V_177 = * ( V_47 * ) ( V_2 -> V_44 + 3 ) ;
V_142 . V_51 = V_35 -> V_50 . V_51 ;
V_142 . V_178 = ( V_35 -> V_59 & V_60 ) != 0 ;
V_142 . V_54 = V_35 -> V_53 ;
V_142 . V_179 = V_35 -> V_56 == 0 ;
if ( F_88 ( V_165 -> V_171 , & V_142 , sizeof V_142 ) )
error = - V_172 ;
break;
case V_180 :
if ( ! F_89 ( V_174 ) )
return - V_175 ;
F_37 ( & V_35 -> V_42 ) ;
V_142 = * (struct V_167 * ) & V_165 -> V_181 ;
if( V_142 . V_179 )
V_35 -> V_56 = 0 ,
V_35 -> V_53 = V_142 . V_54 ;
else
V_35 -> V_56 = V_57 ,
V_35 -> V_53 = V_55 ;
V_35 -> V_50 . V_54 = V_58 [ V_35 -> V_53 ] ;
V_35 -> V_50 . V_51 = V_142 . V_51 ;
F_23 ( * ( V_61 * ) & V_35 -> V_50 | V_40 , V_2 -> V_3 + V_41 ) ;
F_38 ( & V_35 -> V_42 ) ;
break;
#ifdef F_34
case V_182 :
if ( ! F_89 ( V_174 ) )
return - V_175 ;
if ( F_90 ( V_169 , V_165 -> V_171 , sizeof V_169 ) )
return - V_172 ;
V_168 = F_91 ( & V_183 , V_169 ) ;
if( ! V_168 || ! ( V_168 -> V_142 & V_155 ) ) {
F_45 ( V_2 , L_18 ,
V_169 ) ;
if ( V_168 )
F_92 ( V_168 ) ;
return - V_175 ;
}
return F_93 ( V_2 , V_168 ) ;
case V_184 :
if ( ! F_89 ( V_174 ) )
return - V_175 ;
return F_84 ( V_2 ) ;
#endif
default :
return - V_185 ;
}
return error ;
}
static int
F_93 ( struct V_1 * V_2 , struct V_1 * V_168 )
{
struct V_12 * V_35 = F_27 ( V_2 ) ;
struct V_12 * V_186 = F_27 ( V_168 ) ;
if( V_35 -> V_59 & V_80 )
return - V_162 ;
if( V_186 -> V_59 & V_80 )
return - V_162 ;
F_37 ( & V_35 -> V_42 ) ;
F_37 ( & V_186 -> V_42 ) ;
V_186 -> V_63 = V_35 -> V_63 ;
V_35 -> V_63 = V_168 ;
V_186 -> V_62 = V_2 ;
V_186 -> V_59 |= V_80 ;
memset ( & V_168 -> V_111 , 0 , sizeof( struct V_160 ) ) ;
F_36 ( V_168 ) ;
F_62 ( V_2 ) ;
F_38 ( & V_186 -> V_42 ) ;
F_38 ( & V_35 -> V_42 ) ;
F_81 ( V_2 , L_19 , V_168 -> V_5 ) ;
return 0 ;
}
static int
F_84 ( struct V_1 * V_2 )
{
struct V_12 * V_186 = F_27 ( V_2 ) ;
struct V_1 * V_67 = V_186 -> V_62 ;
struct V_12 * V_35 = F_27 ( V_67 ) ;
if( ! ( V_186 -> V_59 & V_80 ) )
return - V_187 ;
F_37 ( & V_35 -> V_42 ) ;
F_37 ( & V_186 -> V_42 ) ;
F_52 ( V_2 ) ;
for(; ; ) {
struct V_12 * V_188 = F_27 ( V_67 ) ;
if( V_188 -> V_63 == V_2 ) {
V_188 -> V_63 = V_186 -> V_63 ;
break;
}
V_67 = V_188 -> V_63 ;
}
V_186 -> V_63 = NULL ;
V_186 -> V_62 = V_2 ;
V_186 -> V_59 &= ~ V_80 ;
F_40 ( V_2 ) ;
F_38 ( & V_186 -> V_42 ) ;
F_38 ( & V_35 -> V_42 ) ;
F_92 ( V_2 ) ;
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
while( V_18 < V_154 ) {
V_2 = F_8 ( sizeof( struct V_12 ) , L_3 ,
V_13 , F_5 ) ;
if( ! V_2 )
break;
sprintf ( V_2 -> V_5 , L_3 , V_18 ) ;
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
return * V_64 ? 0 : - V_7 ;
}
void
F_96 ( void )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_154 ; ++ V_16 ) {
struct V_1 * V_2 = V_64 [ V_16 ] ;
if ( V_2 != NULL ) {
F_97 ( V_2 ) ;
F_13 ( V_2 -> V_3 , V_4 ) ;
F_11 ( V_2 ) ;
}
}
}
static int T_1
F_98 ( char * V_67 )
{
int V_189 , V_190 ;
if( * V_67 ++ != '(' )
goto V_191;
for( V_189 = 0 , V_190 = 0 ; * V_67 && V_189 < 8 ; ) {
( * V_192 [ V_190 ] ) [ V_189 ] = F_99 ( V_67 , & V_67 , 0 ) ;
if( ! * V_67 || * V_67 == ')' )
return 1 ;
if( * V_67 == ';' )
++ V_67 , ++ V_189 , V_190 = 0 ;
else if( * V_67 ++ != ',' )
break;
else
if( ++ V_190 >= 5 )
break;
}
V_191:
F_4 ( L_20 ) ;
return 0 ;
}
static V_47
F_57 ( V_47 V_85 , V_61 * V_67 , V_47 V_105 )
{
while( V_105 -- )
V_85 = F_58 ( * V_67 ++ , V_85 ) ;
return V_85 ;
}
