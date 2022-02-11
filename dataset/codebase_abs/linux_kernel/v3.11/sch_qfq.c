static struct V_1 * F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_7 * V_8 ;
V_8 = F_3 ( & V_6 -> V_9 , V_4 ) ;
if ( V_8 == NULL )
return NULL ;
return F_4 ( V_8 , struct V_1 , V_10 ) ;
}
static void F_5 ( struct V_1 * V_11 )
{
unsigned int V_12 = V_11 -> V_13 -> V_6 . V_14 ;
F_6 ( V_11 -> V_13 ) ;
F_7 ( V_11 -> V_13 , V_12 ) ;
}
static int F_8 ( T_1 V_15 , unsigned int V_16 , T_1 V_17 )
{
T_2 V_18 = ( T_2 ) V_16 * V_15 ;
unsigned long V_19 ;
int V_20 = 0 ;
V_19 = V_18 >> V_17 ;
if ( ! V_19 )
goto V_21;
V_20 = F_9 ( V_19 ) + 1 ;
V_20 -= ! ( V_18 - ( 1ULL << ( V_20 + V_17 - 1 ) ) ) ;
if ( V_20 < 0 )
V_20 = 0 ;
V_21:
F_10 ( L_1 ,
( unsigned long ) V_22 / V_15 , V_16 , V_20 ) ;
return V_20 ;
}
static void F_11 ( struct V_5 * V_6 , struct V_23 * V_24 ,
T_1 V_25 , T_1 V_26 )
{
F_12 ( & V_24 -> V_27 ) ;
F_13 ( & V_24 -> V_28 , & V_6 -> V_29 ) ;
V_24 -> V_25 = V_25 ;
V_24 -> V_30 = V_26 ;
}
static struct V_23 * F_14 ( struct V_5 * V_6 ,
T_1 V_25 , T_1 V_26 )
{
struct V_23 * V_24 ;
F_15 (agg, &q->nonfull_aggs, nonfull_next)
if ( V_24 -> V_25 == V_25 && V_24 -> V_30 == V_26 )
return V_24 ;
return NULL ;
}
static void F_16 ( struct V_5 * V_6 , struct V_23 * V_24 ,
int V_31 )
{
T_1 V_32 ;
if ( V_31 == V_6 -> V_33 )
F_17 ( & V_24 -> V_28 ) ;
if ( V_24 -> V_34 > V_31 &&
V_31 == V_6 -> V_33 - 1 )
F_13 ( & V_24 -> V_28 , & V_6 -> V_29 ) ;
V_24 -> V_35 = V_31 * V_24 -> V_25 ;
V_32 = V_24 -> V_30 * V_31 ;
V_24 -> V_15 = V_22 / V_32 ;
if ( V_24 -> V_36 == NULL ) {
int V_37 = F_8 ( V_24 -> V_15 , V_24 -> V_35 ,
V_6 -> V_17 ) ;
V_24 -> V_36 = & V_6 -> V_38 [ V_37 ] ;
}
V_6 -> V_39 +=
( int ) V_24 -> V_30 * ( V_31 - V_24 -> V_34 ) ;
V_6 -> V_40 = V_22 / V_6 -> V_39 ;
V_24 -> V_34 = V_31 ;
}
static void F_18 ( struct V_5 * V_6 ,
struct V_23 * V_24 ,
struct V_1 * V_11 )
{
V_11 -> V_24 = V_24 ;
F_16 ( V_6 , V_24 , V_24 -> V_34 + 1 ) ;
if ( V_11 -> V_13 -> V_6 . V_14 > 0 ) {
F_19 ( & V_11 -> V_41 , & V_24 -> V_27 ) ;
if ( F_20 ( & V_24 -> V_27 , struct V_1 , V_41 ) ==
V_11 && V_6 -> V_42 != V_24 )
F_21 ( V_6 , V_24 , V_43 ) ;
}
}
static void F_22 ( struct V_5 * V_6 , struct V_23 * V_24 )
{
if ( ! F_23 ( & V_24 -> V_28 ) )
F_17 ( & V_24 -> V_28 ) ;
V_6 -> V_39 -= V_24 -> V_30 ;
if ( V_6 -> V_39 != 0 )
V_6 -> V_40 = V_22 / V_6 -> V_39 ;
if ( V_6 -> V_42 == V_24 )
V_6 -> V_42 = F_24 ( V_6 ) ;
F_25 ( V_24 ) ;
}
static void F_26 ( struct V_5 * V_6 , struct V_1 * V_11 )
{
struct V_23 * V_24 = V_11 -> V_24 ;
F_27 ( & V_11 -> V_41 ) ;
if ( F_28 ( & V_24 -> V_27 ) )
F_29 ( V_6 , V_24 ) ;
}
static void F_30 ( struct V_5 * V_6 , struct V_1 * V_11 )
{
struct V_23 * V_24 = V_11 -> V_24 ;
V_11 -> V_24 = NULL ;
if ( V_24 -> V_34 == 1 ) {
F_22 ( V_6 , V_24 ) ;
return;
}
F_16 ( V_6 , V_24 , V_24 -> V_34 - 1 ) ;
}
static void F_31 ( struct V_5 * V_6 , struct V_1 * V_11 )
{
if ( V_11 -> V_13 -> V_6 . V_14 > 0 )
F_26 ( V_6 , V_11 ) ;
F_30 ( V_6 , V_11 ) ;
}
static int F_32 ( struct V_2 * V_3 , struct V_1 * V_11 , T_1 V_26 ,
T_1 V_25 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_23 * V_44 = F_14 ( V_6 , V_25 , V_26 ) ;
if ( V_44 == NULL ) {
V_44 = F_33 ( sizeof( * V_44 ) , V_45 ) ;
if ( V_44 == NULL )
return - V_46 ;
F_11 ( V_6 , V_44 , V_25 , V_26 ) ;
}
F_31 ( V_6 , V_11 ) ;
F_18 ( V_6 , V_44 , V_11 ) ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 , T_1 V_4 , T_1 V_47 ,
struct V_48 * * V_49 , unsigned long * V_50 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 = (struct V_1 * ) * V_50 ;
bool V_51 = false ;
struct V_48 * V_52 [ V_53 + 1 ] ;
struct V_23 * V_44 = NULL ;
T_1 V_26 , V_25 , V_15 ;
int V_54 ;
int V_55 ;
if ( V_49 [ V_56 ] == NULL ) {
F_35 ( L_2 ) ;
return - V_57 ;
}
V_54 = F_36 ( V_52 , V_53 , V_49 [ V_56 ] , V_58 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( V_52 [ V_59 ] ) {
V_26 = F_37 ( V_52 [ V_59 ] ) ;
if ( ! V_26 || V_26 > ( 1UL << V_60 ) ) {
F_35 ( L_3 , V_26 ) ;
return - V_57 ;
}
} else
V_26 = 1 ;
if ( V_52 [ V_61 ] ) {
V_25 = F_37 ( V_52 [ V_61 ] ) ;
if ( V_25 < V_62 || V_25 > ( 1UL << V_63 ) ) {
F_35 ( L_4 , V_25 ) ;
return - V_57 ;
}
} else
V_25 = F_38 ( F_39 ( V_3 ) ) ;
V_15 = V_22 / V_26 ;
V_26 = V_22 / V_15 ;
if ( V_11 != NULL &&
V_25 == V_11 -> V_24 -> V_25 &&
V_26 == V_11 -> V_24 -> V_30 )
return 0 ;
V_55 = V_26 - ( V_11 ? V_11 -> V_24 -> V_30 : 0 ) ;
if ( V_6 -> V_39 + V_55 > V_64 ) {
F_35 ( L_5 ,
V_55 , V_6 -> V_39 ) ;
return - V_57 ;
}
if ( V_11 != NULL ) {
if ( V_49 [ V_65 ] ) {
V_54 = F_40 ( & V_11 -> V_66 , & V_11 -> V_67 ,
F_41 ( V_3 ) ,
V_49 [ V_65 ] ) ;
if ( V_54 )
return V_54 ;
}
V_51 = true ;
goto V_68;
}
V_11 = F_33 ( sizeof( struct V_1 ) , V_69 ) ;
if ( V_11 == NULL )
return - V_46 ;
V_11 -> V_70 = 1 ;
V_11 -> V_10 . V_4 = V_4 ;
V_11 -> V_71 = V_25 ;
V_11 -> V_13 = F_42 ( V_3 -> V_72 ,
& V_73 , V_4 ) ;
if ( V_11 -> V_13 == NULL )
V_11 -> V_13 = & V_74 ;
if ( V_49 [ V_65 ] ) {
V_54 = F_43 ( & V_11 -> V_66 , & V_11 -> V_67 ,
F_41 ( V_3 ) ,
V_49 [ V_65 ] ) ;
if ( V_54 )
goto V_75;
}
F_44 ( V_3 ) ;
F_45 ( & V_6 -> V_9 , & V_11 -> V_10 ) ;
F_46 ( V_3 ) ;
F_47 ( V_3 , & V_6 -> V_9 ) ;
V_68:
F_44 ( V_3 ) ;
V_44 = F_14 ( V_6 , V_25 , V_26 ) ;
if ( V_44 == NULL ) {
F_46 ( V_3 ) ;
V_44 = F_33 ( sizeof( * V_44 ) , V_69 ) ;
if ( V_44 == NULL ) {
V_54 = - V_46 ;
F_48 ( & V_11 -> V_66 , & V_11 -> V_67 ) ;
goto V_75;
}
F_44 ( V_3 ) ;
F_11 ( V_6 , V_44 , V_25 , V_26 ) ;
}
if ( V_51 )
F_31 ( V_6 , V_11 ) ;
F_18 ( V_6 , V_44 , V_11 ) ;
F_46 ( V_3 ) ;
* V_50 = ( unsigned long ) V_11 ;
return 0 ;
V_75:
F_49 ( V_11 -> V_13 ) ;
F_25 ( V_11 ) ;
return V_54 ;
}
static void F_50 ( struct V_2 * V_3 , struct V_1 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
F_30 ( V_6 , V_11 ) ;
F_48 ( & V_11 -> V_66 , & V_11 -> V_67 ) ;
F_49 ( V_11 -> V_13 ) ;
F_25 ( V_11 ) ;
}
static int F_51 ( struct V_2 * V_3 , unsigned long V_50 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 = (struct V_1 * ) V_50 ;
if ( V_11 -> V_76 > 0 )
return - V_77 ;
F_44 ( V_3 ) ;
F_5 ( V_11 ) ;
F_52 ( & V_6 -> V_9 , & V_11 -> V_10 ) ;
F_53 ( -- V_11 -> V_70 == 0 ) ;
F_46 ( V_3 ) ;
return 0 ;
}
static unsigned long F_54 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_11 = F_1 ( V_3 , V_4 ) ;
if ( V_11 != NULL )
V_11 -> V_70 ++ ;
return ( unsigned long ) V_11 ;
}
static void F_55 ( struct V_2 * V_3 , unsigned long V_50 )
{
struct V_1 * V_11 = (struct V_1 * ) V_50 ;
if ( -- V_11 -> V_70 == 0 )
F_50 ( V_3 , V_11 ) ;
}
static struct V_78 * * F_56 ( struct V_2 * V_3 , unsigned long V_11 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
if ( V_11 )
return NULL ;
return & V_6 -> V_79 ;
}
static unsigned long F_57 ( struct V_2 * V_3 , unsigned long V_80 ,
T_1 V_4 )
{
struct V_1 * V_11 = F_1 ( V_3 , V_4 ) ;
if ( V_11 != NULL )
V_11 -> V_76 ++ ;
return ( unsigned long ) V_11 ;
}
static void F_58 ( struct V_2 * V_3 , unsigned long V_50 )
{
struct V_1 * V_11 = (struct V_1 * ) V_50 ;
V_11 -> V_76 -- ;
}
static int F_59 ( struct V_2 * V_3 , unsigned long V_50 ,
struct V_2 * V_81 , struct V_2 * * V_82 )
{
struct V_1 * V_11 = (struct V_1 * ) V_50 ;
if ( V_81 == NULL ) {
V_81 = F_42 ( V_3 -> V_72 ,
& V_73 , V_11 -> V_10 . V_4 ) ;
if ( V_81 == NULL )
V_81 = & V_74 ;
}
F_44 ( V_3 ) ;
F_5 ( V_11 ) ;
* V_82 = V_11 -> V_13 ;
V_11 -> V_13 = V_81 ;
F_46 ( V_3 ) ;
return 0 ;
}
static struct V_2 * F_60 ( struct V_2 * V_3 , unsigned long V_50 )
{
struct V_1 * V_11 = (struct V_1 * ) V_50 ;
return V_11 -> V_13 ;
}
static int F_61 ( struct V_2 * V_3 , unsigned long V_50 ,
struct V_83 * V_84 , struct V_85 * V_86 )
{
struct V_1 * V_11 = (struct V_1 * ) V_50 ;
struct V_48 * V_87 ;
V_86 -> V_88 = V_89 ;
V_86 -> V_90 = V_11 -> V_10 . V_4 ;
V_86 -> V_91 = V_11 -> V_13 -> V_92 ;
V_87 = F_62 ( V_84 , V_56 ) ;
if ( V_87 == NULL )
goto V_93;
if ( F_63 ( V_84 , V_59 , V_11 -> V_24 -> V_30 ) ||
F_63 ( V_84 , V_61 , V_11 -> V_24 -> V_25 ) )
goto V_93;
return F_64 ( V_84 , V_87 ) ;
V_93:
F_65 ( V_84 , V_87 ) ;
return - V_94 ;
}
static int F_66 ( struct V_2 * V_3 , unsigned long V_50 ,
struct V_95 * V_96 )
{
struct V_1 * V_11 = (struct V_1 * ) V_50 ;
struct V_97 V_98 ;
memset ( & V_98 , 0 , sizeof( V_98 ) ) ;
V_11 -> V_13 -> V_99 . V_14 = V_11 -> V_13 -> V_6 . V_14 ;
V_98 . V_26 = V_11 -> V_24 -> V_30 ;
V_98 . V_25 = V_11 -> V_24 -> V_25 ;
if ( F_67 ( V_96 , & V_11 -> V_66 ) < 0 ||
F_68 ( V_96 , & V_11 -> V_66 , & V_11 -> V_67 ) < 0 ||
F_69 ( V_96 , & V_11 -> V_13 -> V_99 ) < 0 )
return - 1 ;
return F_70 ( V_96 , & V_98 , sizeof( V_98 ) ) ;
}
static void F_71 ( struct V_2 * V_3 , struct V_100 * V_50 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
unsigned int V_37 ;
if ( V_50 -> V_101 )
return;
for ( V_37 = 0 ; V_37 < V_6 -> V_9 . V_102 ; V_37 ++ ) {
F_15 (cl, &q->clhash.hash[i], common.hnode) {
if ( V_50 -> V_103 < V_50 -> V_104 ) {
V_50 -> V_103 ++ ;
continue;
}
if ( V_50 -> V_105 ( V_3 , ( unsigned long ) V_11 , V_50 ) < 0 ) {
V_50 -> V_101 = 1 ;
return;
}
V_50 -> V_103 ++ ;
}
}
}
static struct V_1 * F_72 ( struct V_83 * V_84 , struct V_2 * V_3 ,
int * V_106 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_107 V_108 ;
int V_109 ;
if ( F_73 ( V_84 -> V_110 ^ V_3 -> V_92 ) == 0 ) {
F_10 ( L_6 , V_84 -> V_110 ) ;
V_11 = F_1 ( V_3 , V_84 -> V_110 ) ;
if ( V_11 != NULL )
return V_11 ;
}
* V_106 = V_111 | V_112 ;
V_109 = F_74 ( V_84 , V_6 -> V_79 , & V_108 ) ;
if ( V_109 >= 0 ) {
#ifdef F_75
switch ( V_109 ) {
case V_113 :
case V_114 :
* V_106 = V_111 | V_115 ;
case V_116 :
return NULL ;
}
#endif
V_11 = (struct V_1 * ) V_108 . V_117 ;
if ( V_11 == NULL )
V_11 = F_1 ( V_3 , V_108 . V_4 ) ;
return V_11 ;
}
return NULL ;
}
static inline int F_76 ( T_2 V_118 , T_2 V_119 )
{
return ( V_120 ) ( V_118 - V_119 ) > 0 ;
}
static inline T_2 F_77 ( T_2 V_121 , unsigned int V_122 )
{
return V_121 & ~ ( ( 1ULL << V_122 ) - 1 ) ;
}
static inline struct V_123 * F_78 ( struct V_5 * V_6 ,
unsigned long V_124 )
{
int V_20 = F_79 ( V_124 ) ;
return & V_6 -> V_38 [ V_20 ] ;
}
static inline unsigned long F_80 ( unsigned long V_124 , int V_125 )
{
return V_124 & ~ ( ( 1UL << V_125 ) - 1 ) ;
}
static int F_81 ( struct V_5 * V_6 , const struct V_123 * V_36 )
{
unsigned int V_126 = F_76 ( V_36 -> V_127 , V_6 -> V_128 ) ;
unsigned long V_129 = F_80 ( V_6 -> V_130 [ V_131 ] , V_36 -> V_20 ) ;
struct V_123 * V_132 ;
if ( V_129 ) {
V_132 = F_78 ( V_6 , V_129 ) ;
if ( F_76 ( V_36 -> V_133 , V_132 -> V_133 ) )
V_126 |= V_134 ;
}
return V_126 ;
}
static inline void F_82 ( struct V_5 * V_6 , unsigned long V_129 ,
int V_135 , int V_136 )
{
V_6 -> V_130 [ V_136 ] |= V_6 -> V_130 [ V_135 ] & V_129 ;
V_6 -> V_130 [ V_135 ] &= ~ V_129 ;
}
static void F_83 ( struct V_5 * V_6 , int V_20 , T_2 V_137 )
{
unsigned long V_129 = F_80 ( V_6 -> V_130 [ V_131 ] , V_20 + 1 ) ;
struct V_123 * V_132 ;
if ( V_129 ) {
V_132 = F_78 ( V_6 , V_129 ) ;
if ( ! F_76 ( V_132 -> V_133 , V_137 ) )
return;
}
V_129 = ( 1UL << V_20 ) - 1 ;
F_82 ( V_6 , V_129 , V_134 , V_131 ) ;
F_82 ( V_6 , V_129 , V_138 , V_139 ) ;
}
static void F_84 ( struct V_5 * V_6 )
{
unsigned long V_140 = V_6 -> V_128 >> V_6 -> V_17 ;
unsigned long V_141 = V_6 -> V_142 >> V_6 -> V_17 ;
if ( V_140 != V_141 ) {
unsigned long V_129 ;
int V_143 = F_85 ( V_140 ^ V_141 ) ;
if ( V_143 > 31 )
V_129 = ~ 0UL ;
else
V_129 = ( 1UL << V_143 ) - 1 ;
F_82 ( V_6 , V_129 , V_139 , V_131 ) ;
F_82 ( V_6 , V_129 , V_138 , V_134 ) ;
}
}
static void F_86 ( struct V_123 * V_36 , struct V_23 * V_24 ,
T_2 V_144 )
{
T_2 V_145 = ( V_144 - V_36 -> V_127 ) >> V_36 -> V_146 ;
unsigned int V_37 ;
if ( F_87 ( V_145 > V_147 - 2 ) ) {
T_2 V_148 = V_144 - V_36 -> V_127 -
( ( T_2 ) ( V_147 - 2 ) << V_36 -> V_146 ) ;
V_24 -> V_127 -= V_148 ;
V_24 -> V_133 -= V_148 ;
V_145 = V_147 - 2 ;
}
V_37 = ( V_36 -> V_149 + V_145 ) % V_147 ;
F_13 ( & V_24 -> V_132 , & V_36 -> V_150 [ V_37 ] ) ;
F_88 ( V_145 , & V_36 -> V_151 ) ;
}
static struct V_23 * F_89 ( struct V_123 * V_36 )
{
return F_90 ( V_36 -> V_150 [ V_36 -> V_149 ] . V_152 ,
struct V_23 , V_132 ) ;
}
static void F_91 ( struct V_123 * V_36 )
{
struct V_23 * V_24 = F_89 ( V_36 ) ;
F_53 ( ! V_24 ) ;
F_92 ( & V_24 -> V_132 ) ;
if ( F_93 ( & V_36 -> V_150 [ V_36 -> V_149 ] ) )
F_94 ( 0 , & V_36 -> V_151 ) ;
}
static struct V_23 * F_95 ( struct V_123 * V_36 )
{
unsigned int V_37 ;
F_10 ( L_7 ,
V_36 -> V_20 , V_36 -> V_151 ) ;
if ( V_36 -> V_151 == 0 )
return NULL ;
V_37 = F_79 ( V_36 -> V_151 ) ;
if ( V_37 > 0 ) {
V_36 -> V_149 = ( V_36 -> V_149 + V_37 ) % V_147 ;
V_36 -> V_151 >>= V_37 ;
}
return F_89 ( V_36 ) ;
}
static void F_96 ( struct V_123 * V_36 , T_2 V_144 )
{
unsigned int V_37 = ( V_36 -> V_127 - V_144 ) >> V_36 -> V_146 ;
V_36 -> V_151 <<= V_37 ;
V_36 -> V_149 = ( V_36 -> V_149 - V_37 ) % V_147 ;
}
static void F_97 ( struct V_5 * V_6 )
{
struct V_123 * V_36 ;
unsigned long V_153 ;
V_153 = V_6 -> V_130 [ V_139 ] | V_6 -> V_130 [ V_138 ] ;
if ( V_153 ) {
if ( ! V_6 -> V_130 [ V_131 ] ) {
V_36 = F_78 ( V_6 , V_153 ) ;
if ( F_76 ( V_36 -> V_127 , V_6 -> V_128 ) )
V_6 -> V_128 = V_36 -> V_127 ;
}
F_84 ( V_6 ) ;
}
}
static void F_98 ( struct V_23 * V_24 ,
struct V_1 * V_11 , unsigned int V_12 )
{
F_99 ( V_11 -> V_13 ) ;
V_11 -> V_71 -= ( int ) V_12 ;
if ( V_11 -> V_13 -> V_6 . V_14 == 0 )
F_27 ( & V_11 -> V_41 ) ;
else if ( V_11 -> V_71 < F_100 ( V_11 -> V_13 -> V_154 -> V_155 ( V_11 -> V_13 ) ) ) {
V_11 -> V_71 += V_24 -> V_25 ;
F_101 ( & V_11 -> V_41 , & V_24 -> V_27 ) ;
}
}
static inline struct V_83 * F_102 ( struct V_23 * V_24 ,
struct V_1 * * V_11 ,
unsigned int * V_12 )
{
struct V_83 * V_84 ;
* V_11 = F_20 ( & V_24 -> V_27 , struct V_1 , V_41 ) ;
V_84 = ( * V_11 ) -> V_13 -> V_154 -> V_155 ( ( * V_11 ) -> V_13 ) ;
if ( V_84 == NULL )
F_103 ( 1 , L_8 ) ;
else
* V_12 = F_100 ( V_84 ) ;
return V_84 ;
}
static inline void F_104 ( struct V_23 * V_24 )
{
T_1 V_156 = F_105 ( V_24 -> V_35 ,
V_24 -> V_157 - V_24 -> V_158 ) ;
V_24 -> V_133 = V_24 -> V_127 + ( T_2 ) V_156 * V_24 -> V_15 ;
}
static void F_106 ( struct V_5 * V_6 , struct V_23 * V_24 )
{
unsigned long V_129 ;
T_2 V_159 , V_160 ;
int V_146 = V_24 -> V_36 -> V_146 ;
V_160 = F_77 ( V_24 -> V_133 , V_146 ) ;
V_159 = F_77 ( V_6 -> V_128 , V_146 ) + ( 1ULL << V_146 ) ;
if ( ! F_76 ( V_24 -> V_133 , V_6 -> V_128 ) || F_76 ( V_160 , V_159 ) ) {
V_129 = F_80 ( V_6 -> V_130 [ V_131 ] , V_24 -> V_36 -> V_20 ) ;
if ( V_129 ) {
struct V_123 * V_132 = F_78 ( V_6 , V_129 ) ;
if ( F_76 ( V_160 , V_132 -> V_133 ) ) {
if ( F_76 ( V_159 , V_132 -> V_133 ) )
V_24 -> V_127 = V_132 -> V_133 ;
else
V_24 -> V_127 = V_159 ;
return;
}
}
V_24 -> V_127 = V_6 -> V_128 ;
} else
V_24 -> V_127 = V_24 -> V_133 ;
}
static inline void
F_107 ( struct V_5 * V_6 ,
struct V_23 * V_24 , enum V_161 V_162 )
{
if ( V_162 != V_163 )
F_106 ( V_6 , V_24 ) ;
else
V_24 -> V_127 = V_24 -> V_133 ;
V_24 -> V_133 = V_24 -> V_127 + ( T_2 ) V_24 -> V_35 * V_24 -> V_15 ;
}
static struct V_83 * F_108 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_23 * V_42 = V_6 -> V_42 ;
struct V_1 * V_11 ;
struct V_83 * V_84 = NULL ;
unsigned int V_12 = 0 ;
if ( V_42 == NULL )
return NULL ;
if ( ! F_28 ( & V_42 -> V_27 ) )
V_84 = F_102 ( V_42 , & V_11 , & V_12 ) ;
if ( V_12 == 0 || V_42 -> V_158 < V_12 ) {
F_104 ( V_42 ) ;
V_42 -> V_157 = V_42 -> V_158 =
V_42 -> V_35 ;
if ( ! F_28 ( & V_42 -> V_27 ) ) {
F_107 ( V_6 , V_42 , V_163 ) ;
F_109 ( V_6 , V_42 ) ;
} else if ( V_3 -> V_6 . V_14 == 0 ) {
V_6 -> V_42 = NULL ;
return NULL ;
}
V_42 = V_6 -> V_42 = F_24 ( V_6 ) ;
V_84 = F_102 ( V_42 , & V_11 , & V_12 ) ;
}
if ( ! V_84 )
return NULL ;
V_3 -> V_6 . V_14 -- ;
F_110 ( V_3 , V_84 ) ;
F_98 ( V_42 , V_11 , V_12 ) ;
if ( F_87 ( V_42 -> V_158 < V_12 ) )
V_42 -> V_158 = 0 ;
else
V_42 -> V_158 -= V_12 ;
V_6 -> V_128 += ( T_2 ) V_12 * V_6 -> V_40 ;
F_10 ( L_9 ,
V_12 , ( unsigned long long ) V_42 -> V_133 ,
( unsigned long long ) V_6 -> V_128 ) ;
return V_84 ;
}
static struct V_23 * F_24 ( struct V_5 * V_6 )
{
struct V_123 * V_36 ;
struct V_23 * V_24 , * V_164 ;
T_2 V_137 ;
F_97 ( V_6 ) ;
V_6 -> V_142 = V_6 -> V_128 ;
if ( ! V_6 -> V_130 [ V_131 ] )
return NULL ;
V_36 = F_78 ( V_6 , V_6 -> V_130 [ V_131 ] ) ;
V_137 = V_36 -> V_133 ;
V_24 = F_89 ( V_36 ) ;
F_91 ( V_36 ) ;
V_164 = F_95 ( V_36 ) ;
if ( V_164 == NULL )
F_94 ( V_36 -> V_20 , & V_6 -> V_130 [ V_131 ] ) ;
else {
T_2 V_144 = F_77 ( V_164 -> V_127 ,
V_36 -> V_146 ) ;
unsigned int V_165 ;
if ( V_36 -> V_127 == V_144 )
return V_24 ;
V_36 -> V_127 = V_144 ;
V_36 -> V_133 = V_144 + ( 2ULL << V_36 -> V_146 ) ;
F_94 ( V_36 -> V_20 , & V_6 -> V_130 [ V_131 ] ) ;
V_165 = F_81 ( V_6 , V_36 ) ;
F_88 ( V_36 -> V_20 , & V_6 -> V_130 [ V_165 ] ) ;
}
F_83 ( V_6 , V_36 -> V_20 , V_137 ) ;
return V_24 ;
}
static int F_111 ( struct V_83 * V_84 , struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_23 * V_24 ;
int V_54 = 0 ;
V_11 = F_72 ( V_84 , V_3 , & V_54 ) ;
if ( V_11 == NULL ) {
if ( V_54 & V_112 )
V_3 -> V_99 . V_166 ++ ;
F_112 ( V_84 ) ;
return V_54 ;
}
F_10 ( L_10 , V_11 -> V_10 . V_4 ) ;
if ( F_87 ( V_11 -> V_24 -> V_25 < F_100 ( V_84 ) ) ) {
F_10 ( L_11 ,
V_11 -> V_24 -> V_25 , F_100 ( V_84 ) , V_11 -> V_10 . V_4 ) ;
V_54 = F_32 ( V_3 , V_11 , V_11 -> V_24 -> V_30 ,
F_100 ( V_84 ) ) ;
if ( V_54 )
return V_54 ;
}
V_54 = F_113 ( V_84 , V_11 -> V_13 ) ;
if ( F_87 ( V_54 != V_111 ) ) {
F_10 ( L_12 , V_54 ) ;
if ( F_114 ( V_54 ) ) {
V_11 -> V_99 . V_166 ++ ;
V_3 -> V_99 . V_166 ++ ;
}
return V_54 ;
}
F_115 ( & V_11 -> V_66 , V_84 ) ;
++ V_3 -> V_6 . V_14 ;
V_24 = V_11 -> V_24 ;
if ( V_11 -> V_13 -> V_6 . V_14 != 1 ) {
if ( F_87 ( V_84 == V_11 -> V_13 -> V_154 -> V_155 ( V_11 -> V_13 ) ) &&
F_20 ( & V_24 -> V_27 , struct V_1 , V_41 )
== V_11 && V_11 -> V_71 < F_100 ( V_84 ) )
F_101 ( & V_11 -> V_41 , & V_24 -> V_27 ) ;
return V_54 ;
}
V_11 -> V_71 = V_24 -> V_25 ;
F_19 ( & V_11 -> V_41 , & V_24 -> V_27 ) ;
if ( F_20 ( & V_24 -> V_27 , struct V_1 , V_41 ) != V_11 ||
V_6 -> V_42 == V_24 )
return V_54 ;
F_21 ( V_6 , V_24 , V_43 ) ;
return V_54 ;
}
static void F_109 ( struct V_5 * V_6 , struct V_23 * V_24 )
{
struct V_123 * V_36 = V_24 -> V_36 ;
T_2 V_144 ;
int V_165 ;
V_144 = F_77 ( V_24 -> V_127 , V_36 -> V_146 ) ;
if ( V_36 -> V_151 ) {
if ( ! F_76 ( V_36 -> V_127 , V_24 -> V_127 ) )
goto V_167;
F_96 ( V_36 , V_144 ) ;
F_94 ( V_36 -> V_20 , & V_6 -> V_130 [ V_139 ] ) ;
F_94 ( V_36 -> V_20 , & V_6 -> V_130 [ V_138 ] ) ;
} else if ( ! V_6 -> V_130 [ V_131 ] && F_76 ( V_144 , V_6 -> V_128 ) &&
V_6 -> V_42 == NULL )
V_6 -> V_128 = V_144 ;
V_36 -> V_127 = V_144 ;
V_36 -> V_133 = V_144 + ( 2ULL << V_36 -> V_146 ) ;
V_165 = F_81 ( V_6 , V_36 ) ;
F_88 ( V_36 -> V_20 , & V_6 -> V_130 [ V_165 ] ) ;
F_10 ( L_13 ,
V_165 , V_6 -> V_130 [ V_165 ] ,
( unsigned long long ) V_24 -> V_127 ,
( unsigned long long ) V_24 -> V_133 ,
( unsigned long long ) V_6 -> V_128 ) ;
V_167:
F_86 ( V_36 , V_24 , V_144 ) ;
}
static void F_21 ( struct V_5 * V_6 , struct V_23 * V_24 ,
enum V_161 V_162 )
{
V_24 -> V_157 = V_24 -> V_158 = V_24 -> V_35 ;
F_107 ( V_6 , V_24 , V_162 ) ;
if ( V_6 -> V_42 == NULL ) {
V_6 -> V_42 = V_24 ;
V_6 -> V_142 = V_6 -> V_128 = V_24 -> V_127 ;
} else if ( V_24 != V_6 -> V_42 )
F_109 ( V_6 , V_24 ) ;
}
static void F_116 ( struct V_5 * V_6 , struct V_123 * V_36 ,
struct V_23 * V_24 )
{
unsigned int V_37 , V_168 ;
T_2 V_144 ;
V_144 = F_77 ( V_24 -> V_127 , V_36 -> V_146 ) ;
V_168 = ( V_144 - V_36 -> V_127 ) >> V_36 -> V_146 ;
V_37 = ( V_36 -> V_149 + V_168 ) % V_147 ;
F_92 ( & V_24 -> V_132 ) ;
if ( F_93 ( & V_36 -> V_150 [ V_37 ] ) )
F_94 ( V_168 , & V_36 -> V_151 ) ;
}
static void F_29 ( struct V_5 * V_6 , struct V_23 * V_24 )
{
struct V_123 * V_36 = V_24 -> V_36 ;
unsigned long V_129 ;
T_2 V_144 ;
int V_165 ;
if ( V_24 == V_6 -> V_42 ) {
F_104 ( V_24 ) ;
V_6 -> V_42 = F_24 ( V_6 ) ;
return;
}
V_24 -> V_133 = V_24 -> V_127 ;
F_116 ( V_6 , V_36 , V_24 ) ;
if ( ! V_36 -> V_151 ) {
F_94 ( V_36 -> V_20 , & V_6 -> V_130 [ V_139 ] ) ;
F_94 ( V_36 -> V_20 , & V_6 -> V_130 [ V_134 ] ) ;
F_94 ( V_36 -> V_20 , & V_6 -> V_130 [ V_138 ] ) ;
if ( F_117 ( V_36 -> V_20 , & V_6 -> V_130 [ V_131 ] ) &&
! ( V_6 -> V_130 [ V_131 ] & ~ ( ( 1UL << V_36 -> V_20 ) - 1 ) ) ) {
V_129 = V_6 -> V_130 [ V_131 ] & ( ( 1UL << V_36 -> V_20 ) - 1 ) ;
if ( V_129 )
V_129 = ~ ( ( 1UL << F_9 ( V_129 ) ) - 1 ) ;
else
V_129 = ~ 0UL ;
F_82 ( V_6 , V_129 , V_134 , V_131 ) ;
F_82 ( V_6 , V_129 , V_138 , V_139 ) ;
}
F_94 ( V_36 -> V_20 , & V_6 -> V_130 [ V_131 ] ) ;
} else if ( F_93 ( & V_36 -> V_150 [ V_36 -> V_149 ] ) ) {
V_24 = F_95 ( V_36 ) ;
V_144 = F_77 ( V_24 -> V_127 , V_36 -> V_146 ) ;
if ( V_36 -> V_127 != V_144 ) {
F_94 ( V_36 -> V_20 , & V_6 -> V_130 [ V_131 ] ) ;
F_94 ( V_36 -> V_20 , & V_6 -> V_130 [ V_139 ] ) ;
F_94 ( V_36 -> V_20 , & V_6 -> V_130 [ V_134 ] ) ;
F_94 ( V_36 -> V_20 , & V_6 -> V_130 [ V_138 ] ) ;
V_36 -> V_127 = V_144 ;
V_36 -> V_133 = V_144 + ( 2ULL << V_36 -> V_146 ) ;
V_165 = F_81 ( V_6 , V_36 ) ;
F_88 ( V_36 -> V_20 , & V_6 -> V_130 [ V_165 ] ) ;
}
}
}
static void F_118 ( struct V_2 * V_3 , unsigned long V_50 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 = (struct V_1 * ) V_50 ;
if ( V_11 -> V_13 -> V_6 . V_14 == 0 )
F_26 ( V_6 , V_11 ) ;
}
static unsigned int F_119 ( struct V_5 * V_6 ,
struct V_169 * V_145 )
{
struct V_23 * V_24 ;
struct V_1 * V_11 ;
unsigned int V_12 ;
F_15 (agg, slot, next) {
F_120 (cl, &agg->active, alist) {
if ( ! V_11 -> V_13 -> V_154 -> V_170 )
continue;
V_12 = V_11 -> V_13 -> V_154 -> V_170 ( V_11 -> V_13 ) ;
if ( V_12 > 0 ) {
if ( V_11 -> V_13 -> V_6 . V_14 == 0 )
F_26 ( V_6 , V_11 ) ;
return V_12 ;
}
}
}
return 0 ;
}
static unsigned int F_121 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_123 * V_36 ;
unsigned int V_37 , V_171 , V_12 ;
for ( V_37 = 0 ; V_37 <= V_172 ; V_37 ++ ) {
V_36 = & V_6 -> V_38 [ V_37 ] ;
for ( V_171 = 0 ; V_171 < V_147 ; V_171 ++ ) {
V_12 = F_119 ( V_6 , & V_36 -> V_150 [ V_171 ] ) ;
if ( V_12 > 0 ) {
V_3 -> V_6 . V_14 -- ;
return V_12 ;
}
}
}
return 0 ;
}
static int F_122 ( struct V_2 * V_3 , struct V_48 * V_173 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_123 * V_36 ;
int V_37 , V_171 , V_54 ;
T_1 V_174 , V_175 , V_176 ;
V_54 = F_123 ( & V_6 -> V_9 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( F_39 ( V_3 ) -> V_177 + 1 > V_178 )
V_176 = V_178 ;
else
V_176 = F_39 ( V_3 ) -> V_177 + 1 ;
V_174 = F_9 ( V_176 ) ;
V_6 -> V_33 = 1 << V_174 ;
V_175 = V_63 + V_174 ;
V_6 -> V_17 = V_179 + V_175 - V_172 ;
for ( V_37 = 0 ; V_37 <= V_172 ; V_37 ++ ) {
V_36 = & V_6 -> V_38 [ V_37 ] ;
V_36 -> V_20 = V_37 ;
V_36 -> V_146 = V_6 -> V_17 + V_37 ;
for ( V_171 = 0 ; V_171 < V_147 ; V_171 ++ )
F_124 ( & V_36 -> V_150 [ V_171 ] ) ;
}
F_124 ( & V_6 -> V_29 ) ;
return 0 ;
}
static void F_125 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
unsigned int V_37 ;
for ( V_37 = 0 ; V_37 < V_6 -> V_9 . V_102 ; V_37 ++ ) {
F_15 (cl, &q->clhash.hash[i], common.hnode) {
if ( V_11 -> V_13 -> V_6 . V_14 > 0 )
F_26 ( V_6 , V_11 ) ;
F_6 ( V_11 -> V_13 ) ;
}
}
V_3 -> V_6 . V_14 = 0 ;
}
static void F_126 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_180 * V_132 ;
unsigned int V_37 ;
F_127 ( & V_6 -> V_79 ) ;
for ( V_37 = 0 ; V_37 < V_6 -> V_9 . V_102 ; V_37 ++ ) {
F_128 (cl, next, &q->clhash.hash[i],
common.hnode) {
F_50 ( V_3 , V_11 ) ;
}
}
F_129 ( & V_6 -> V_9 ) ;
}
static int T_3 F_130 ( void )
{
return F_131 ( & V_181 ) ;
}
static void T_4 F_132 ( void )
{
F_133 ( & V_181 ) ;
}
