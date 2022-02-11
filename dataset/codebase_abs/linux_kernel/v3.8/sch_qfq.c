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
struct V_31 * V_32 ;
F_15 (agg, n, &q->nonfull_aggs, nonfull_next)
if ( V_24 -> V_25 == V_25 && V_24 -> V_30 == V_26 )
return V_24 ;
return NULL ;
}
static void F_16 ( struct V_5 * V_6 , struct V_23 * V_24 ,
int V_33 )
{
T_1 V_34 ;
if ( V_33 == V_6 -> V_35 )
F_17 ( & V_24 -> V_28 ) ;
if ( V_24 -> V_36 > V_33 &&
V_33 == V_6 -> V_35 - 1 )
F_13 ( & V_24 -> V_28 , & V_6 -> V_29 ) ;
V_24 -> V_37 = V_33 * V_24 -> V_25 ;
V_34 = V_24 -> V_30 * V_33 ;
V_24 -> V_15 = V_22 / V_34 ;
if ( V_24 -> V_38 == NULL ) {
int V_39 = F_8 ( V_24 -> V_15 , V_24 -> V_37 ,
V_6 -> V_17 ) ;
V_24 -> V_38 = & V_6 -> V_40 [ V_39 ] ;
}
V_6 -> V_41 +=
( int ) V_24 -> V_30 * ( V_33 - V_24 -> V_36 ) ;
V_24 -> V_36 = V_33 ;
}
static void F_18 ( struct V_5 * V_6 ,
struct V_23 * V_24 ,
struct V_1 * V_11 )
{
V_11 -> V_24 = V_24 ;
F_16 ( V_6 , V_24 , V_24 -> V_36 + 1 ) ;
if ( V_11 -> V_13 -> V_6 . V_14 > 0 ) {
F_19 ( & V_11 -> V_42 , & V_24 -> V_27 ) ;
if ( F_20 ( & V_24 -> V_27 , struct V_1 , V_42 ) ==
V_11 && V_6 -> V_43 != V_24 )
F_21 ( V_6 , V_24 , V_44 ) ;
}
}
static void F_22 ( struct V_5 * V_6 , struct V_23 * V_24 )
{
if ( ! F_23 ( & V_24 -> V_28 ) )
F_17 ( & V_24 -> V_28 ) ;
if ( V_6 -> V_43 == V_24 )
V_6 -> V_43 = F_24 ( V_6 ) ;
F_25 ( V_24 ) ;
}
static void F_26 ( struct V_5 * V_6 , struct V_1 * V_11 )
{
struct V_23 * V_24 = V_11 -> V_24 ;
F_27 ( & V_11 -> V_42 ) ;
if ( F_28 ( & V_24 -> V_27 ) )
F_29 ( V_6 , V_24 ) ;
}
static void F_30 ( struct V_5 * V_6 , struct V_1 * V_11 )
{
struct V_23 * V_24 = V_11 -> V_24 ;
V_11 -> V_24 = NULL ;
if ( V_24 -> V_36 == 1 ) {
F_22 ( V_6 , V_24 ) ;
return;
}
F_16 ( V_6 , V_24 , V_24 -> V_36 - 1 ) ;
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
struct V_23 * V_45 = F_14 ( V_6 , V_25 , V_26 ) ;
if ( V_45 == NULL ) {
V_45 = F_33 ( sizeof( * V_45 ) , V_46 ) ;
if ( V_45 == NULL )
return - V_47 ;
F_11 ( V_6 , V_45 , V_25 , V_26 ) ;
}
F_31 ( V_6 , V_11 ) ;
F_18 ( V_6 , V_45 , V_11 ) ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 , T_1 V_4 , T_1 V_48 ,
struct V_49 * * V_50 , unsigned long * V_51 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 = (struct V_1 * ) * V_51 ;
bool V_52 = false ;
struct V_49 * V_53 [ V_54 + 1 ] ;
struct V_23 * V_45 = NULL ;
T_1 V_26 , V_25 , V_15 ;
int V_55 ;
int V_56 ;
if ( V_50 [ V_57 ] == NULL ) {
F_35 ( L_2 ) ;
return - V_58 ;
}
V_55 = F_36 ( V_53 , V_54 , V_50 [ V_57 ] , V_59 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( V_53 [ V_60 ] ) {
V_26 = F_37 ( V_53 [ V_60 ] ) ;
if ( ! V_26 || V_26 > ( 1UL << V_61 ) ) {
F_35 ( L_3 , V_26 ) ;
return - V_58 ;
}
} else
V_26 = 1 ;
if ( V_53 [ V_62 ] ) {
V_25 = F_37 ( V_53 [ V_62 ] ) ;
if ( V_25 < V_63 || V_25 > ( 1UL << V_64 ) ) {
F_35 ( L_4 , V_25 ) ;
return - V_58 ;
}
} else
V_25 = F_38 ( F_39 ( V_3 ) ) ;
V_15 = V_22 / V_26 ;
V_26 = V_22 / V_15 ;
if ( V_11 != NULL &&
V_25 == V_11 -> V_24 -> V_25 &&
V_26 == V_11 -> V_24 -> V_30 )
return 0 ;
V_56 = V_26 - ( V_11 ? V_11 -> V_24 -> V_30 : 0 ) ;
if ( V_6 -> V_41 + V_56 > V_65 ) {
F_35 ( L_5 ,
V_56 , V_6 -> V_41 ) ;
return - V_58 ;
}
if ( V_11 != NULL ) {
if ( V_50 [ V_66 ] ) {
V_55 = F_40 ( & V_11 -> V_67 , & V_11 -> V_68 ,
F_41 ( V_3 ) ,
V_50 [ V_66 ] ) ;
if ( V_55 )
return V_55 ;
}
V_52 = true ;
goto V_69;
}
V_11 = F_33 ( sizeof( struct V_1 ) , V_70 ) ;
if ( V_11 == NULL )
return - V_47 ;
V_11 -> V_71 = 1 ;
V_11 -> V_10 . V_4 = V_4 ;
V_11 -> V_72 = V_25 ;
V_11 -> V_13 = F_42 ( V_3 -> V_73 ,
& V_74 , V_4 ) ;
if ( V_11 -> V_13 == NULL )
V_11 -> V_13 = & V_75 ;
if ( V_50 [ V_66 ] ) {
V_55 = F_43 ( & V_11 -> V_67 , & V_11 -> V_68 ,
F_41 ( V_3 ) ,
V_50 [ V_66 ] ) ;
if ( V_55 )
goto V_76;
}
F_44 ( V_3 ) ;
F_45 ( & V_6 -> V_9 , & V_11 -> V_10 ) ;
F_46 ( V_3 ) ;
F_47 ( V_3 , & V_6 -> V_9 ) ;
V_69:
F_44 ( V_3 ) ;
V_45 = F_14 ( V_6 , V_25 , V_26 ) ;
if ( V_45 == NULL ) {
F_46 ( V_3 ) ;
V_45 = F_33 ( sizeof( * V_45 ) , V_70 ) ;
if ( V_45 == NULL ) {
V_55 = - V_47 ;
F_48 ( & V_11 -> V_67 , & V_11 -> V_68 ) ;
goto V_76;
}
F_44 ( V_3 ) ;
F_11 ( V_6 , V_45 , V_25 , V_26 ) ;
}
if ( V_52 )
F_31 ( V_6 , V_11 ) ;
F_18 ( V_6 , V_45 , V_11 ) ;
F_46 ( V_3 ) ;
* V_51 = ( unsigned long ) V_11 ;
return 0 ;
V_76:
F_49 ( V_11 -> V_13 ) ;
F_25 ( V_11 ) ;
return V_55 ;
}
static void F_50 ( struct V_2 * V_3 , struct V_1 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
F_30 ( V_6 , V_11 ) ;
F_48 ( & V_11 -> V_67 , & V_11 -> V_68 ) ;
F_49 ( V_11 -> V_13 ) ;
F_25 ( V_11 ) ;
}
static int F_51 ( struct V_2 * V_3 , unsigned long V_51 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 = (struct V_1 * ) V_51 ;
if ( V_11 -> V_77 > 0 )
return - V_78 ;
F_44 ( V_3 ) ;
F_5 ( V_11 ) ;
F_52 ( & V_6 -> V_9 , & V_11 -> V_10 ) ;
F_53 ( -- V_11 -> V_71 == 0 ) ;
F_46 ( V_3 ) ;
return 0 ;
}
static unsigned long F_54 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_11 = F_1 ( V_3 , V_4 ) ;
if ( V_11 != NULL )
V_11 -> V_71 ++ ;
return ( unsigned long ) V_11 ;
}
static void F_55 ( struct V_2 * V_3 , unsigned long V_51 )
{
struct V_1 * V_11 = (struct V_1 * ) V_51 ;
if ( -- V_11 -> V_71 == 0 )
F_50 ( V_3 , V_11 ) ;
}
static struct V_79 * * F_56 ( struct V_2 * V_3 , unsigned long V_11 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
if ( V_11 )
return NULL ;
return & V_6 -> V_80 ;
}
static unsigned long F_57 ( struct V_2 * V_3 , unsigned long V_81 ,
T_1 V_4 )
{
struct V_1 * V_11 = F_1 ( V_3 , V_4 ) ;
if ( V_11 != NULL )
V_11 -> V_77 ++ ;
return ( unsigned long ) V_11 ;
}
static void F_58 ( struct V_2 * V_3 , unsigned long V_51 )
{
struct V_1 * V_11 = (struct V_1 * ) V_51 ;
V_11 -> V_77 -- ;
}
static int F_59 ( struct V_2 * V_3 , unsigned long V_51 ,
struct V_2 * V_82 , struct V_2 * * V_83 )
{
struct V_1 * V_11 = (struct V_1 * ) V_51 ;
if ( V_82 == NULL ) {
V_82 = F_42 ( V_3 -> V_73 ,
& V_74 , V_11 -> V_10 . V_4 ) ;
if ( V_82 == NULL )
V_82 = & V_75 ;
}
F_44 ( V_3 ) ;
F_5 ( V_11 ) ;
* V_83 = V_11 -> V_13 ;
V_11 -> V_13 = V_82 ;
F_46 ( V_3 ) ;
return 0 ;
}
static struct V_2 * F_60 ( struct V_2 * V_3 , unsigned long V_51 )
{
struct V_1 * V_11 = (struct V_1 * ) V_51 ;
return V_11 -> V_13 ;
}
static int F_61 ( struct V_2 * V_3 , unsigned long V_51 ,
struct V_84 * V_85 , struct V_86 * V_87 )
{
struct V_1 * V_11 = (struct V_1 * ) V_51 ;
struct V_49 * V_88 ;
V_87 -> V_89 = V_90 ;
V_87 -> V_91 = V_11 -> V_10 . V_4 ;
V_87 -> V_92 = V_11 -> V_13 -> V_93 ;
V_88 = F_62 ( V_85 , V_57 ) ;
if ( V_88 == NULL )
goto V_94;
if ( F_63 ( V_85 , V_60 , V_11 -> V_24 -> V_30 ) ||
F_63 ( V_85 , V_62 , V_11 -> V_24 -> V_25 ) )
goto V_94;
return F_64 ( V_85 , V_88 ) ;
V_94:
F_65 ( V_85 , V_88 ) ;
return - V_95 ;
}
static int F_66 ( struct V_2 * V_3 , unsigned long V_51 ,
struct V_96 * V_97 )
{
struct V_1 * V_11 = (struct V_1 * ) V_51 ;
struct V_98 V_99 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
V_11 -> V_13 -> V_100 . V_14 = V_11 -> V_13 -> V_6 . V_14 ;
V_99 . V_26 = V_11 -> V_24 -> V_30 ;
V_99 . V_25 = V_11 -> V_24 -> V_25 ;
if ( F_67 ( V_97 , & V_11 -> V_67 ) < 0 ||
F_68 ( V_97 , & V_11 -> V_67 , & V_11 -> V_68 ) < 0 ||
F_69 ( V_97 , & V_11 -> V_13 -> V_100 ) < 0 )
return - 1 ;
return F_70 ( V_97 , & V_99 , sizeof( V_99 ) ) ;
}
static void F_71 ( struct V_2 * V_3 , struct V_101 * V_51 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_31 * V_32 ;
unsigned int V_39 ;
if ( V_51 -> V_102 )
return;
for ( V_39 = 0 ; V_39 < V_6 -> V_9 . V_103 ; V_39 ++ ) {
F_15 (cl, n, &q->clhash.hash[i], common.hnode) {
if ( V_51 -> V_104 < V_51 -> V_105 ) {
V_51 -> V_104 ++ ;
continue;
}
if ( V_51 -> V_106 ( V_3 , ( unsigned long ) V_11 , V_51 ) < 0 ) {
V_51 -> V_102 = 1 ;
return;
}
V_51 -> V_104 ++ ;
}
}
}
static struct V_1 * F_72 ( struct V_84 * V_85 , struct V_2 * V_3 ,
int * V_107 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_108 V_109 ;
int V_110 ;
if ( F_73 ( V_85 -> V_111 ^ V_3 -> V_93 ) == 0 ) {
F_10 ( L_6 , V_85 -> V_111 ) ;
V_11 = F_1 ( V_3 , V_85 -> V_111 ) ;
if ( V_11 != NULL )
return V_11 ;
}
* V_107 = V_112 | V_113 ;
V_110 = F_74 ( V_85 , V_6 -> V_80 , & V_109 ) ;
if ( V_110 >= 0 ) {
#ifdef F_75
switch ( V_110 ) {
case V_114 :
case V_115 :
* V_107 = V_112 | V_116 ;
case V_117 :
return NULL ;
}
#endif
V_11 = (struct V_1 * ) V_109 . V_118 ;
if ( V_11 == NULL )
V_11 = F_1 ( V_3 , V_109 . V_4 ) ;
return V_11 ;
}
return NULL ;
}
static inline int F_76 ( T_2 V_119 , T_2 V_120 )
{
return ( V_121 ) ( V_119 - V_120 ) > 0 ;
}
static inline T_2 F_77 ( T_2 V_122 , unsigned int V_123 )
{
return V_122 & ~ ( ( 1ULL << V_123 ) - 1 ) ;
}
static inline struct V_124 * F_78 ( struct V_5 * V_6 ,
unsigned long V_125 )
{
int V_20 = F_79 ( V_125 ) ;
return & V_6 -> V_40 [ V_20 ] ;
}
static inline unsigned long F_80 ( unsigned long V_125 , int V_126 )
{
return V_125 & ~ ( ( 1UL << V_126 ) - 1 ) ;
}
static int F_81 ( struct V_5 * V_6 , const struct V_124 * V_38 )
{
unsigned int V_127 = F_76 ( V_38 -> V_128 , V_6 -> V_129 ) ;
unsigned long V_130 = F_80 ( V_6 -> V_131 [ V_132 ] , V_38 -> V_20 ) ;
struct V_124 * V_133 ;
if ( V_130 ) {
V_133 = F_78 ( V_6 , V_130 ) ;
if ( F_76 ( V_38 -> V_134 , V_133 -> V_134 ) )
V_127 |= V_135 ;
}
return V_127 ;
}
static inline void F_82 ( struct V_5 * V_6 , unsigned long V_130 ,
int V_136 , int V_137 )
{
V_6 -> V_131 [ V_137 ] |= V_6 -> V_131 [ V_136 ] & V_130 ;
V_6 -> V_131 [ V_136 ] &= ~ V_130 ;
}
static void F_83 ( struct V_5 * V_6 , int V_20 , T_2 V_138 )
{
unsigned long V_130 = F_80 ( V_6 -> V_131 [ V_132 ] , V_20 + 1 ) ;
struct V_124 * V_133 ;
if ( V_130 ) {
V_133 = F_78 ( V_6 , V_130 ) ;
if ( ! F_76 ( V_133 -> V_134 , V_138 ) )
return;
}
V_130 = ( 1UL << V_20 ) - 1 ;
F_82 ( V_6 , V_130 , V_135 , V_132 ) ;
F_82 ( V_6 , V_130 , V_139 , V_140 ) ;
}
static void F_84 ( struct V_5 * V_6 )
{
unsigned long V_141 = V_6 -> V_129 >> V_6 -> V_17 ;
unsigned long V_142 = V_6 -> V_143 >> V_6 -> V_17 ;
if ( V_141 != V_142 ) {
unsigned long V_130 = ( 1UL << F_85 ( V_141 ^ V_142 ) ) - 1 ;
F_82 ( V_6 , V_130 , V_140 , V_132 ) ;
F_82 ( V_6 , V_130 , V_139 , V_135 ) ;
}
}
static void F_86 ( struct V_124 * V_38 , struct V_23 * V_24 ,
T_2 V_144 )
{
T_2 V_145 = ( V_144 - V_38 -> V_128 ) >> V_38 -> V_146 ;
unsigned int V_39 ;
if ( F_87 ( V_145 > V_147 - 2 ) ) {
T_2 V_148 = V_144 - V_38 -> V_128 -
( ( T_2 ) ( V_147 - 2 ) << V_38 -> V_146 ) ;
V_24 -> V_128 -= V_148 ;
V_24 -> V_134 -= V_148 ;
V_145 = V_147 - 2 ;
}
V_39 = ( V_38 -> V_149 + V_145 ) % V_147 ;
F_13 ( & V_24 -> V_133 , & V_38 -> V_150 [ V_39 ] ) ;
F_88 ( V_145 , & V_38 -> V_151 ) ;
}
static struct V_23 * F_89 ( struct V_124 * V_38 )
{
return F_90 ( V_38 -> V_150 [ V_38 -> V_149 ] . V_152 ,
struct V_23 , V_133 ) ;
}
static void F_91 ( struct V_124 * V_38 )
{
struct V_23 * V_24 = F_89 ( V_38 ) ;
F_53 ( ! V_24 ) ;
F_92 ( & V_24 -> V_133 ) ;
if ( F_93 ( & V_38 -> V_150 [ V_38 -> V_149 ] ) )
F_94 ( 0 , & V_38 -> V_151 ) ;
}
static struct V_23 * F_95 ( struct V_124 * V_38 )
{
unsigned int V_39 ;
F_10 ( L_7 ,
V_38 -> V_20 , V_38 -> V_151 ) ;
if ( V_38 -> V_151 == 0 )
return NULL ;
V_39 = F_79 ( V_38 -> V_151 ) ;
if ( V_39 > 0 ) {
V_38 -> V_149 = ( V_38 -> V_149 + V_39 ) % V_147 ;
V_38 -> V_151 >>= V_39 ;
}
return F_89 ( V_38 ) ;
}
static void F_96 ( struct V_124 * V_38 , T_2 V_144 )
{
unsigned int V_39 = ( V_38 -> V_128 - V_144 ) >> V_38 -> V_146 ;
V_38 -> V_151 <<= V_39 ;
V_38 -> V_149 = ( V_38 -> V_149 - V_39 ) % V_147 ;
}
static void F_97 ( struct V_5 * V_6 )
{
struct V_124 * V_38 ;
unsigned long V_153 ;
V_153 = V_6 -> V_131 [ V_140 ] | V_6 -> V_131 [ V_139 ] ;
if ( V_153 ) {
if ( ! V_6 -> V_131 [ V_132 ] ) {
V_38 = F_78 ( V_6 , V_153 ) ;
if ( F_76 ( V_38 -> V_128 , V_6 -> V_129 ) )
V_6 -> V_129 = V_38 -> V_128 ;
}
F_84 ( V_6 ) ;
}
}
static void F_98 ( struct V_23 * V_24 ,
struct V_1 * V_11 , unsigned int V_12 )
{
F_99 ( V_11 -> V_13 ) ;
V_11 -> V_72 -= ( int ) V_12 ;
if ( V_11 -> V_13 -> V_6 . V_14 == 0 )
F_27 ( & V_11 -> V_42 ) ;
else if ( V_11 -> V_72 < F_100 ( V_11 -> V_13 -> V_154 -> V_155 ( V_11 -> V_13 ) ) ) {
V_11 -> V_72 += V_24 -> V_25 ;
F_101 ( & V_11 -> V_42 , & V_24 -> V_27 ) ;
}
}
static inline struct V_84 * F_102 ( struct V_23 * V_24 ,
struct V_1 * * V_11 ,
unsigned int * V_12 )
{
struct V_84 * V_85 ;
* V_11 = F_20 ( & V_24 -> V_27 , struct V_1 , V_42 ) ;
V_85 = ( * V_11 ) -> V_13 -> V_154 -> V_155 ( ( * V_11 ) -> V_13 ) ;
if ( V_85 == NULL )
F_103 ( 1 , L_8 ) ;
else
* V_12 = F_100 ( V_85 ) ;
return V_85 ;
}
static inline void F_104 ( struct V_23 * V_24 )
{
T_1 V_156 = V_24 -> V_157 - V_24 -> V_158 ;
V_24 -> V_134 = V_24 -> V_128 + ( T_2 ) V_156 * V_24 -> V_15 ;
}
static struct V_84 * F_105 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_23 * V_43 = V_6 -> V_43 ;
struct V_1 * V_11 ;
struct V_84 * V_85 = NULL ;
unsigned int V_12 = 0 ;
if ( V_43 == NULL )
return NULL ;
if ( ! F_28 ( & V_43 -> V_27 ) )
V_85 = F_102 ( V_43 , & V_11 , & V_12 ) ;
if ( V_12 == 0 || V_43 -> V_158 < V_12 ) {
F_104 ( V_43 ) ;
V_43 -> V_157 = V_43 -> V_158 =
V_43 -> V_37 ;
if ( ! F_28 ( & V_43 -> V_27 ) )
F_21 ( V_6 , V_43 , V_159 ) ;
else if ( V_3 -> V_6 . V_14 == 0 ) {
V_6 -> V_43 = NULL ;
return NULL ;
}
V_43 = V_6 -> V_43 = F_24 ( V_6 ) ;
V_85 = F_102 ( V_43 , & V_11 , & V_12 ) ;
}
if ( ! V_85 )
return NULL ;
V_3 -> V_6 . V_14 -- ;
F_106 ( V_3 , V_85 ) ;
F_98 ( V_43 , V_11 , V_12 ) ;
V_43 -> V_158 -= V_12 ;
V_6 -> V_129 += ( T_2 ) V_12 * V_160 ;
F_10 ( L_9 ,
V_12 , ( unsigned long long ) V_43 -> V_134 ,
( unsigned long long ) V_6 -> V_129 ) ;
return V_85 ;
}
static struct V_23 * F_24 ( struct V_5 * V_6 )
{
struct V_124 * V_38 ;
struct V_23 * V_24 , * V_161 ;
T_2 V_138 ;
F_97 ( V_6 ) ;
V_6 -> V_143 = V_6 -> V_129 ;
if ( ! V_6 -> V_131 [ V_132 ] )
return NULL ;
V_38 = F_78 ( V_6 , V_6 -> V_131 [ V_132 ] ) ;
V_138 = V_38 -> V_134 ;
V_24 = F_89 ( V_38 ) ;
F_91 ( V_38 ) ;
V_161 = F_95 ( V_38 ) ;
if ( V_161 == NULL )
F_94 ( V_38 -> V_20 , & V_6 -> V_131 [ V_132 ] ) ;
else {
T_2 V_144 = F_77 ( V_161 -> V_128 ,
V_38 -> V_146 ) ;
unsigned int V_162 ;
if ( V_38 -> V_128 == V_144 )
return V_24 ;
V_38 -> V_128 = V_144 ;
V_38 -> V_134 = V_144 + ( 2ULL << V_38 -> V_146 ) ;
F_94 ( V_38 -> V_20 , & V_6 -> V_131 [ V_132 ] ) ;
V_162 = F_81 ( V_6 , V_38 ) ;
F_88 ( V_38 -> V_20 , & V_6 -> V_131 [ V_162 ] ) ;
}
F_83 ( V_6 , V_38 -> V_20 , V_138 ) ;
return V_24 ;
}
static void F_107 ( struct V_5 * V_6 , struct V_23 * V_24 )
{
unsigned long V_130 ;
T_2 V_163 , V_164 ;
int V_146 = V_24 -> V_38 -> V_146 ;
V_164 = F_77 ( V_24 -> V_134 , V_146 ) ;
V_163 = F_77 ( V_6 -> V_129 , V_146 ) + ( 1ULL << V_146 ) ;
if ( ! F_76 ( V_24 -> V_134 , V_6 -> V_129 ) || F_76 ( V_164 , V_163 ) ) {
V_130 = F_80 ( V_6 -> V_131 [ V_132 ] , V_24 -> V_38 -> V_20 ) ;
if ( V_130 ) {
struct V_124 * V_133 = F_78 ( V_6 , V_130 ) ;
if ( F_76 ( V_164 , V_133 -> V_134 ) ) {
if ( F_76 ( V_163 , V_133 -> V_134 ) )
V_24 -> V_128 = V_133 -> V_134 ;
else
V_24 -> V_128 = V_163 ;
return;
}
}
V_24 -> V_128 = V_6 -> V_129 ;
} else
V_24 -> V_128 = V_24 -> V_134 ;
}
static inline void
F_108 ( struct V_5 * V_6 ,
struct V_23 * V_24 , enum V_165 V_166 )
{
if ( V_166 != V_159 )
F_107 ( V_6 , V_24 ) ;
else
V_24 -> V_128 = V_24 -> V_134 ;
V_24 -> V_134 = V_24 -> V_128 + ( T_2 ) V_24 -> V_37 * V_24 -> V_15 ;
}
static int F_109 ( struct V_84 * V_85 , struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_23 * V_24 ;
int V_55 = 0 ;
V_11 = F_72 ( V_85 , V_3 , & V_55 ) ;
if ( V_11 == NULL ) {
if ( V_55 & V_113 )
V_3 -> V_100 . V_167 ++ ;
F_110 ( V_85 ) ;
return V_55 ;
}
F_10 ( L_10 , V_11 -> V_10 . V_4 ) ;
if ( F_87 ( V_11 -> V_24 -> V_25 < F_100 ( V_85 ) ) ) {
F_10 ( L_11 ,
V_11 -> V_24 -> V_25 , F_100 ( V_85 ) , V_11 -> V_10 . V_4 ) ;
V_55 = F_32 ( V_3 , V_11 , V_11 -> V_24 -> V_30 ,
F_100 ( V_85 ) ) ;
if ( V_55 )
return V_55 ;
}
V_55 = F_111 ( V_85 , V_11 -> V_13 ) ;
if ( F_87 ( V_55 != V_112 ) ) {
F_10 ( L_12 , V_55 ) ;
if ( F_112 ( V_55 ) ) {
V_11 -> V_100 . V_167 ++ ;
V_3 -> V_100 . V_167 ++ ;
}
return V_55 ;
}
F_113 ( & V_11 -> V_67 , V_85 ) ;
++ V_3 -> V_6 . V_14 ;
V_24 = V_11 -> V_24 ;
if ( V_11 -> V_13 -> V_6 . V_14 != 1 ) {
if ( F_87 ( V_85 == V_11 -> V_13 -> V_154 -> V_155 ( V_11 -> V_13 ) ) &&
F_20 ( & V_24 -> V_27 , struct V_1 , V_42 )
== V_11 && V_11 -> V_72 < F_100 ( V_85 ) )
F_101 ( & V_11 -> V_42 , & V_24 -> V_27 ) ;
return V_55 ;
}
V_11 -> V_72 = V_24 -> V_25 ;
F_19 ( & V_11 -> V_42 , & V_24 -> V_27 ) ;
if ( F_20 ( & V_24 -> V_27 , struct V_1 , V_42 ) != V_11 )
return V_55 ;
V_24 -> V_157 = V_24 -> V_158 = V_24 -> V_37 ;
F_108 ( V_6 , V_24 , V_44 ) ;
if ( V_6 -> V_43 == NULL )
V_6 -> V_43 = V_24 ;
else if ( V_24 != V_6 -> V_43 )
F_114 ( V_6 , V_24 ) ;
return V_55 ;
}
static void F_114 ( struct V_5 * V_6 , struct V_23 * V_24 )
{
struct V_124 * V_38 = V_24 -> V_38 ;
T_2 V_144 ;
int V_162 ;
V_144 = F_77 ( V_24 -> V_128 , V_38 -> V_146 ) ;
if ( V_38 -> V_151 ) {
if ( ! F_76 ( V_38 -> V_128 , V_24 -> V_128 ) )
goto V_168;
F_96 ( V_38 , V_144 ) ;
F_94 ( V_38 -> V_20 , & V_6 -> V_131 [ V_140 ] ) ;
F_94 ( V_38 -> V_20 , & V_6 -> V_131 [ V_139 ] ) ;
} else if ( ! V_6 -> V_131 [ V_132 ] && F_76 ( V_144 , V_6 -> V_129 ) )
V_6 -> V_129 = V_144 ;
V_38 -> V_128 = V_144 ;
V_38 -> V_134 = V_144 + ( 2ULL << V_38 -> V_146 ) ;
V_162 = F_81 ( V_6 , V_38 ) ;
F_88 ( V_38 -> V_20 , & V_6 -> V_131 [ V_162 ] ) ;
F_10 ( L_13 ,
V_162 , V_6 -> V_131 [ V_162 ] ,
( unsigned long long ) V_24 -> V_128 ,
( unsigned long long ) V_24 -> V_134 ,
( unsigned long long ) V_6 -> V_129 ) ;
V_168:
F_86 ( V_38 , V_24 , V_144 ) ;
}
static void F_21 ( struct V_5 * V_6 , struct V_23 * V_24 ,
enum V_165 V_166 )
{
F_108 ( V_6 , V_24 , V_166 ) ;
F_114 ( V_6 , V_24 ) ;
}
static void F_115 ( struct V_5 * V_6 , struct V_124 * V_38 ,
struct V_23 * V_24 )
{
unsigned int V_39 , V_169 ;
T_2 V_144 ;
V_144 = F_77 ( V_24 -> V_128 , V_38 -> V_146 ) ;
V_169 = ( V_144 - V_38 -> V_128 ) >> V_38 -> V_146 ;
V_39 = ( V_38 -> V_149 + V_169 ) % V_147 ;
F_92 ( & V_24 -> V_133 ) ;
if ( F_93 ( & V_38 -> V_150 [ V_39 ] ) )
F_94 ( V_169 , & V_38 -> V_151 ) ;
}
static void F_29 ( struct V_5 * V_6 , struct V_23 * V_24 )
{
struct V_124 * V_38 = V_24 -> V_38 ;
unsigned long V_130 ;
T_2 V_144 ;
int V_162 ;
if ( V_24 == V_6 -> V_43 ) {
F_104 ( V_24 ) ;
V_6 -> V_43 = F_24 ( V_6 ) ;
return;
}
V_24 -> V_134 = V_24 -> V_128 ;
F_115 ( V_6 , V_38 , V_24 ) ;
if ( ! V_38 -> V_151 ) {
F_94 ( V_38 -> V_20 , & V_6 -> V_131 [ V_140 ] ) ;
F_94 ( V_38 -> V_20 , & V_6 -> V_131 [ V_135 ] ) ;
F_94 ( V_38 -> V_20 , & V_6 -> V_131 [ V_139 ] ) ;
if ( F_116 ( V_38 -> V_20 , & V_6 -> V_131 [ V_132 ] ) &&
! ( V_6 -> V_131 [ V_132 ] & ~ ( ( 1UL << V_38 -> V_20 ) - 1 ) ) ) {
V_130 = V_6 -> V_131 [ V_132 ] & ( ( 1UL << V_38 -> V_20 ) - 1 ) ;
if ( V_130 )
V_130 = ~ ( ( 1UL << F_9 ( V_130 ) ) - 1 ) ;
else
V_130 = ~ 0UL ;
F_82 ( V_6 , V_130 , V_135 , V_132 ) ;
F_82 ( V_6 , V_130 , V_139 , V_140 ) ;
}
F_94 ( V_38 -> V_20 , & V_6 -> V_131 [ V_132 ] ) ;
} else if ( F_93 ( & V_38 -> V_150 [ V_38 -> V_149 ] ) ) {
V_24 = F_95 ( V_38 ) ;
V_144 = F_77 ( V_24 -> V_128 , V_38 -> V_146 ) ;
if ( V_38 -> V_128 != V_144 ) {
F_94 ( V_38 -> V_20 , & V_6 -> V_131 [ V_132 ] ) ;
F_94 ( V_38 -> V_20 , & V_6 -> V_131 [ V_140 ] ) ;
F_94 ( V_38 -> V_20 , & V_6 -> V_131 [ V_135 ] ) ;
F_94 ( V_38 -> V_20 , & V_6 -> V_131 [ V_139 ] ) ;
V_38 -> V_128 = V_144 ;
V_38 -> V_134 = V_144 + ( 2ULL << V_38 -> V_146 ) ;
V_162 = F_81 ( V_6 , V_38 ) ;
F_88 ( V_38 -> V_20 , & V_6 -> V_131 [ V_162 ] ) ;
}
}
F_97 ( V_6 ) ;
}
static void F_117 ( struct V_2 * V_3 , unsigned long V_51 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 = (struct V_1 * ) V_51 ;
if ( V_11 -> V_13 -> V_6 . V_14 == 0 )
F_26 ( V_6 , V_11 ) ;
}
static unsigned int F_118 ( struct V_5 * V_6 ,
struct V_170 * V_145 )
{
struct V_23 * V_24 ;
struct V_31 * V_32 ;
struct V_1 * V_11 ;
unsigned int V_12 ;
F_15 (agg, n, slot, next) {
F_119 (cl, &agg->active, alist) {
if ( ! V_11 -> V_13 -> V_154 -> V_171 )
continue;
V_12 = V_11 -> V_13 -> V_154 -> V_171 ( V_11 -> V_13 ) ;
if ( V_12 > 0 ) {
if ( V_11 -> V_13 -> V_6 . V_14 == 0 )
F_26 ( V_6 , V_11 ) ;
return V_12 ;
}
}
}
return 0 ;
}
static unsigned int F_120 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_124 * V_38 ;
unsigned int V_39 , V_172 , V_12 ;
for ( V_39 = 0 ; V_39 <= V_173 ; V_39 ++ ) {
V_38 = & V_6 -> V_40 [ V_39 ] ;
for ( V_172 = 0 ; V_172 < V_147 ; V_172 ++ ) {
V_12 = F_118 ( V_6 , & V_38 -> V_150 [ V_172 ] ) ;
if ( V_12 > 0 ) {
V_3 -> V_6 . V_14 -- ;
return V_12 ;
}
}
}
return 0 ;
}
static int F_121 ( struct V_2 * V_3 , struct V_49 * V_174 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_124 * V_38 ;
int V_39 , V_172 , V_55 ;
T_1 V_175 , V_176 , V_177 ;
V_55 = F_122 ( & V_6 -> V_9 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( F_39 ( V_3 ) -> V_178 + 1 > V_179 )
V_177 = V_179 ;
else
V_177 = F_39 ( V_3 ) -> V_178 + 1 ;
V_175 = F_9 ( V_177 ) ;
V_6 -> V_35 = 1 << V_175 ;
V_176 = V_64 + V_175 ;
V_6 -> V_17 = V_180 + V_176 - V_173 ;
for ( V_39 = 0 ; V_39 <= V_173 ; V_39 ++ ) {
V_38 = & V_6 -> V_40 [ V_39 ] ;
V_38 -> V_20 = V_39 ;
V_38 -> V_146 = V_6 -> V_17 + V_39 ;
for ( V_172 = 0 ; V_172 < V_147 ; V_172 ++ )
F_123 ( & V_38 -> V_150 [ V_172 ] ) ;
}
F_123 ( & V_6 -> V_29 ) ;
return 0 ;
}
static void F_124 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_31 * V_32 ;
unsigned int V_39 ;
for ( V_39 = 0 ; V_39 < V_6 -> V_9 . V_103 ; V_39 ++ ) {
F_15 (cl, n, &q->clhash.hash[i], common.hnode) {
if ( V_11 -> V_13 -> V_6 . V_14 > 0 )
F_26 ( V_6 , V_11 ) ;
F_6 ( V_11 -> V_13 ) ;
}
}
V_3 -> V_6 . V_14 = 0 ;
}
static void F_125 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_31 * V_32 , * V_133 ;
unsigned int V_39 ;
F_126 ( & V_6 -> V_80 ) ;
for ( V_39 = 0 ; V_39 < V_6 -> V_9 . V_103 ; V_39 ++ ) {
F_127 (cl, n, next, &q->clhash.hash[i],
common.hnode) {
F_50 ( V_3 , V_11 ) ;
}
}
F_128 ( & V_6 -> V_9 ) ;
}
static int T_3 F_129 ( void )
{
return F_130 ( & V_181 ) ;
}
static void T_4 F_131 ( void )
{
F_132 ( & V_181 ) ;
}
