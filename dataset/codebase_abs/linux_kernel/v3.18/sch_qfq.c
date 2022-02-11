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
V_54 = F_40 ( & V_11 -> V_66 , NULL ,
& V_11 -> V_67 ,
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
V_54 = F_43 ( & V_11 -> V_66 , NULL ,
& V_11 -> V_67 ,
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
static struct V_78 T_3 * * F_56 ( struct V_2 * V_3 ,
unsigned long V_11 )
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
V_98 . V_26 = V_11 -> V_24 -> V_30 ;
V_98 . V_25 = V_11 -> V_24 -> V_25 ;
if ( F_67 ( V_96 , NULL , & V_11 -> V_66 ) < 0 ||
F_68 ( V_96 , & V_11 -> V_66 , & V_11 -> V_67 ) < 0 ||
F_69 ( V_96 , NULL ,
& V_11 -> V_13 -> V_99 , V_11 -> V_13 -> V_6 . V_14 ) < 0 )
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
struct V_78 * V_109 ;
int V_110 ;
if ( F_73 ( V_84 -> V_111 ^ V_3 -> V_92 ) == 0 ) {
F_10 ( L_6 , V_84 -> V_111 ) ;
V_11 = F_1 ( V_3 , V_84 -> V_111 ) ;
if ( V_11 != NULL )
return V_11 ;
}
* V_106 = V_112 | V_113 ;
V_109 = F_74 ( V_6 -> V_79 ) ;
V_110 = F_75 ( V_84 , V_109 , & V_108 ) ;
if ( V_110 >= 0 ) {
#ifdef F_76
switch ( V_110 ) {
case V_114 :
case V_115 :
* V_106 = V_112 | V_116 ;
case V_117 :
return NULL ;
}
#endif
V_11 = (struct V_1 * ) V_108 . V_118 ;
if ( V_11 == NULL )
V_11 = F_1 ( V_3 , V_108 . V_4 ) ;
return V_11 ;
}
return NULL ;
}
static inline int F_77 ( T_2 V_119 , T_2 V_120 )
{
return ( V_121 ) ( V_119 - V_120 ) > 0 ;
}
static inline T_2 F_78 ( T_2 V_122 , unsigned int V_123 )
{
return V_122 & ~ ( ( 1ULL << V_123 ) - 1 ) ;
}
static inline struct V_124 * F_79 ( struct V_5 * V_6 ,
unsigned long V_125 )
{
int V_20 = F_80 ( V_125 ) ;
return & V_6 -> V_38 [ V_20 ] ;
}
static inline unsigned long F_81 ( unsigned long V_125 , int V_126 )
{
return V_125 & ~ ( ( 1UL << V_126 ) - 1 ) ;
}
static int F_82 ( struct V_5 * V_6 , const struct V_124 * V_36 )
{
unsigned int V_127 = F_77 ( V_36 -> V_128 , V_6 -> V_129 ) ;
unsigned long V_130 = F_81 ( V_6 -> V_131 [ V_132 ] , V_36 -> V_20 ) ;
struct V_124 * V_133 ;
if ( V_130 ) {
V_133 = F_79 ( V_6 , V_130 ) ;
if ( F_77 ( V_36 -> V_134 , V_133 -> V_134 ) )
V_127 |= V_135 ;
}
return V_127 ;
}
static inline void F_83 ( struct V_5 * V_6 , unsigned long V_130 ,
int V_136 , int V_137 )
{
V_6 -> V_131 [ V_137 ] |= V_6 -> V_131 [ V_136 ] & V_130 ;
V_6 -> V_131 [ V_136 ] &= ~ V_130 ;
}
static void F_84 ( struct V_5 * V_6 , int V_20 , T_2 V_138 )
{
unsigned long V_130 = F_81 ( V_6 -> V_131 [ V_132 ] , V_20 + 1 ) ;
struct V_124 * V_133 ;
if ( V_130 ) {
V_133 = F_79 ( V_6 , V_130 ) ;
if ( ! F_77 ( V_133 -> V_134 , V_138 ) )
return;
}
V_130 = ( 1UL << V_20 ) - 1 ;
F_83 ( V_6 , V_130 , V_135 , V_132 ) ;
F_83 ( V_6 , V_130 , V_139 , V_140 ) ;
}
static void F_85 ( struct V_5 * V_6 )
{
unsigned long V_141 = V_6 -> V_129 >> V_6 -> V_17 ;
unsigned long V_142 = V_6 -> V_143 >> V_6 -> V_17 ;
if ( V_141 != V_142 ) {
unsigned long V_130 ;
int V_144 = F_86 ( V_141 ^ V_142 ) ;
if ( V_144 > 31 )
V_130 = ~ 0UL ;
else
V_130 = ( 1UL << V_144 ) - 1 ;
F_83 ( V_6 , V_130 , V_140 , V_132 ) ;
F_83 ( V_6 , V_130 , V_139 , V_135 ) ;
}
}
static void F_87 ( struct V_124 * V_36 , struct V_23 * V_24 ,
T_2 V_145 )
{
T_2 V_146 = ( V_145 - V_36 -> V_128 ) >> V_36 -> V_147 ;
unsigned int V_37 ;
if ( F_88 ( V_146 > V_148 - 2 ) ) {
T_2 V_149 = V_145 - V_36 -> V_128 -
( ( T_2 ) ( V_148 - 2 ) << V_36 -> V_147 ) ;
V_24 -> V_128 -= V_149 ;
V_24 -> V_134 -= V_149 ;
V_146 = V_148 - 2 ;
}
V_37 = ( V_36 -> V_150 + V_146 ) % V_148 ;
F_13 ( & V_24 -> V_133 , & V_36 -> V_151 [ V_37 ] ) ;
F_89 ( V_146 , & V_36 -> V_152 ) ;
}
static struct V_23 * F_90 ( struct V_124 * V_36 )
{
return F_91 ( V_36 -> V_151 [ V_36 -> V_150 ] . V_153 ,
struct V_23 , V_133 ) ;
}
static void F_92 ( struct V_124 * V_36 )
{
struct V_23 * V_24 = F_90 ( V_36 ) ;
F_53 ( ! V_24 ) ;
F_93 ( & V_24 -> V_133 ) ;
if ( F_94 ( & V_36 -> V_151 [ V_36 -> V_150 ] ) )
F_95 ( 0 , & V_36 -> V_152 ) ;
}
static struct V_23 * F_96 ( struct V_124 * V_36 )
{
unsigned int V_37 ;
F_10 ( L_7 ,
V_36 -> V_20 , V_36 -> V_152 ) ;
if ( V_36 -> V_152 == 0 )
return NULL ;
V_37 = F_80 ( V_36 -> V_152 ) ;
if ( V_37 > 0 ) {
V_36 -> V_150 = ( V_36 -> V_150 + V_37 ) % V_148 ;
V_36 -> V_152 >>= V_37 ;
}
return F_90 ( V_36 ) ;
}
static void F_97 ( struct V_124 * V_36 , T_2 V_145 )
{
unsigned int V_37 = ( V_36 -> V_128 - V_145 ) >> V_36 -> V_147 ;
V_36 -> V_152 <<= V_37 ;
V_36 -> V_150 = ( V_36 -> V_150 - V_37 ) % V_148 ;
}
static void F_98 ( struct V_5 * V_6 )
{
struct V_124 * V_36 ;
unsigned long V_154 ;
V_154 = V_6 -> V_131 [ V_140 ] | V_6 -> V_131 [ V_139 ] ;
if ( V_154 ) {
if ( ! V_6 -> V_131 [ V_132 ] ) {
V_36 = F_79 ( V_6 , V_154 ) ;
if ( F_77 ( V_36 -> V_128 , V_6 -> V_129 ) )
V_6 -> V_129 = V_36 -> V_128 ;
}
F_85 ( V_6 ) ;
}
}
static void F_99 ( struct V_23 * V_24 ,
struct V_1 * V_11 , unsigned int V_12 )
{
F_100 ( V_11 -> V_13 ) ;
V_11 -> V_71 -= ( int ) V_12 ;
if ( V_11 -> V_13 -> V_6 . V_14 == 0 )
F_27 ( & V_11 -> V_41 ) ;
else if ( V_11 -> V_71 < F_101 ( V_11 -> V_13 -> V_155 -> V_156 ( V_11 -> V_13 ) ) ) {
V_11 -> V_71 += V_24 -> V_25 ;
F_102 ( & V_11 -> V_41 , & V_24 -> V_27 ) ;
}
}
static inline struct V_83 * F_103 ( struct V_23 * V_24 ,
struct V_1 * * V_11 ,
unsigned int * V_12 )
{
struct V_83 * V_84 ;
* V_11 = F_20 ( & V_24 -> V_27 , struct V_1 , V_41 ) ;
V_84 = ( * V_11 ) -> V_13 -> V_155 -> V_156 ( ( * V_11 ) -> V_13 ) ;
if ( V_84 == NULL )
F_104 ( 1 , L_8 ) ;
else
* V_12 = F_101 ( V_84 ) ;
return V_84 ;
}
static inline void F_105 ( struct V_23 * V_24 )
{
T_1 V_157 = F_106 ( V_24 -> V_35 ,
V_24 -> V_158 - V_24 -> V_159 ) ;
V_24 -> V_134 = V_24 -> V_128 + ( T_2 ) V_157 * V_24 -> V_15 ;
}
static void F_107 ( struct V_5 * V_6 , struct V_23 * V_24 )
{
unsigned long V_130 ;
T_2 V_160 , V_161 ;
int V_147 = V_24 -> V_36 -> V_147 ;
V_161 = F_78 ( V_24 -> V_134 , V_147 ) ;
V_160 = F_78 ( V_6 -> V_129 , V_147 ) + ( 1ULL << V_147 ) ;
if ( ! F_77 ( V_24 -> V_134 , V_6 -> V_129 ) || F_77 ( V_161 , V_160 ) ) {
V_130 = F_81 ( V_6 -> V_131 [ V_132 ] , V_24 -> V_36 -> V_20 ) ;
if ( V_130 ) {
struct V_124 * V_133 = F_79 ( V_6 , V_130 ) ;
if ( F_77 ( V_161 , V_133 -> V_134 ) ) {
if ( F_77 ( V_160 , V_133 -> V_134 ) )
V_24 -> V_128 = V_133 -> V_134 ;
else
V_24 -> V_128 = V_160 ;
return;
}
}
V_24 -> V_128 = V_6 -> V_129 ;
} else
V_24 -> V_128 = V_24 -> V_134 ;
}
static inline void
F_108 ( struct V_5 * V_6 ,
struct V_23 * V_24 , enum V_162 V_163 )
{
if ( V_163 != V_164 )
F_107 ( V_6 , V_24 ) ;
else
V_24 -> V_128 = V_24 -> V_134 ;
V_24 -> V_134 = V_24 -> V_128 + ( T_2 ) V_24 -> V_35 * V_24 -> V_15 ;
}
static struct V_83 * F_109 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_23 * V_42 = V_6 -> V_42 ;
struct V_1 * V_11 ;
struct V_83 * V_84 = NULL ;
unsigned int V_12 = 0 ;
if ( V_42 == NULL )
return NULL ;
if ( ! F_28 ( & V_42 -> V_27 ) )
V_84 = F_103 ( V_42 , & V_11 , & V_12 ) ;
if ( V_12 == 0 || V_42 -> V_159 < V_12 ) {
F_105 ( V_42 ) ;
V_42 -> V_158 = V_42 -> V_159 =
V_42 -> V_35 ;
if ( ! F_28 ( & V_42 -> V_27 ) ) {
F_108 ( V_6 , V_42 , V_164 ) ;
F_110 ( V_6 , V_42 ) ;
} else if ( V_3 -> V_6 . V_14 == 0 ) {
V_6 -> V_42 = NULL ;
return NULL ;
}
V_42 = V_6 -> V_42 = F_24 ( V_6 ) ;
V_84 = F_103 ( V_42 , & V_11 , & V_12 ) ;
}
if ( ! V_84 )
return NULL ;
V_3 -> V_6 . V_14 -- ;
F_111 ( V_3 , V_84 ) ;
F_99 ( V_42 , V_11 , V_12 ) ;
if ( F_88 ( V_42 -> V_159 < V_12 ) )
V_42 -> V_159 = 0 ;
else
V_42 -> V_159 -= V_12 ;
V_6 -> V_129 += ( T_2 ) V_12 * V_6 -> V_40 ;
F_10 ( L_9 ,
V_12 , ( unsigned long long ) V_42 -> V_134 ,
( unsigned long long ) V_6 -> V_129 ) ;
return V_84 ;
}
static struct V_23 * F_24 ( struct V_5 * V_6 )
{
struct V_124 * V_36 ;
struct V_23 * V_24 , * V_165 ;
T_2 V_138 ;
F_98 ( V_6 ) ;
V_6 -> V_143 = V_6 -> V_129 ;
if ( ! V_6 -> V_131 [ V_132 ] )
return NULL ;
V_36 = F_79 ( V_6 , V_6 -> V_131 [ V_132 ] ) ;
V_138 = V_36 -> V_134 ;
V_24 = F_90 ( V_36 ) ;
F_92 ( V_36 ) ;
V_165 = F_96 ( V_36 ) ;
if ( V_165 == NULL )
F_95 ( V_36 -> V_20 , & V_6 -> V_131 [ V_132 ] ) ;
else {
T_2 V_145 = F_78 ( V_165 -> V_128 ,
V_36 -> V_147 ) ;
unsigned int V_166 ;
if ( V_36 -> V_128 == V_145 )
return V_24 ;
V_36 -> V_128 = V_145 ;
V_36 -> V_134 = V_145 + ( 2ULL << V_36 -> V_147 ) ;
F_95 ( V_36 -> V_20 , & V_6 -> V_131 [ V_132 ] ) ;
V_166 = F_82 ( V_6 , V_36 ) ;
F_89 ( V_36 -> V_20 , & V_6 -> V_131 [ V_166 ] ) ;
}
F_84 ( V_6 , V_36 -> V_20 , V_138 ) ;
return V_24 ;
}
static int F_112 ( struct V_83 * V_84 , struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_23 * V_24 ;
int V_54 = 0 ;
V_11 = F_72 ( V_84 , V_3 , & V_54 ) ;
if ( V_11 == NULL ) {
if ( V_54 & V_113 )
F_113 ( V_3 ) ;
F_114 ( V_84 ) ;
return V_54 ;
}
F_10 ( L_10 , V_11 -> V_10 . V_4 ) ;
if ( F_88 ( V_11 -> V_24 -> V_25 < F_101 ( V_84 ) ) ) {
F_10 ( L_11 ,
V_11 -> V_24 -> V_25 , F_101 ( V_84 ) , V_11 -> V_10 . V_4 ) ;
V_54 = F_32 ( V_3 , V_11 , V_11 -> V_24 -> V_30 ,
F_101 ( V_84 ) ) ;
if ( V_54 )
return V_54 ;
}
V_54 = F_115 ( V_84 , V_11 -> V_13 ) ;
if ( F_88 ( V_54 != V_112 ) ) {
F_10 ( L_12 , V_54 ) ;
if ( F_116 ( V_54 ) ) {
V_11 -> V_99 . V_167 ++ ;
F_113 ( V_3 ) ;
}
return V_54 ;
}
F_117 ( & V_11 -> V_66 , V_84 ) ;
++ V_3 -> V_6 . V_14 ;
V_24 = V_11 -> V_24 ;
if ( V_11 -> V_13 -> V_6 . V_14 != 1 ) {
if ( F_88 ( V_84 == V_11 -> V_13 -> V_155 -> V_156 ( V_11 -> V_13 ) ) &&
F_20 ( & V_24 -> V_27 , struct V_1 , V_41 )
== V_11 && V_11 -> V_71 < F_101 ( V_84 ) )
F_102 ( & V_11 -> V_41 , & V_24 -> V_27 ) ;
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
static void F_110 ( struct V_5 * V_6 , struct V_23 * V_24 )
{
struct V_124 * V_36 = V_24 -> V_36 ;
T_2 V_145 ;
int V_166 ;
V_145 = F_78 ( V_24 -> V_128 , V_36 -> V_147 ) ;
if ( V_36 -> V_152 ) {
if ( ! F_77 ( V_36 -> V_128 , V_24 -> V_128 ) )
goto V_168;
F_97 ( V_36 , V_145 ) ;
F_95 ( V_36 -> V_20 , & V_6 -> V_131 [ V_140 ] ) ;
F_95 ( V_36 -> V_20 , & V_6 -> V_131 [ V_139 ] ) ;
} else if ( ! V_6 -> V_131 [ V_132 ] && F_77 ( V_145 , V_6 -> V_129 ) &&
V_6 -> V_42 == NULL )
V_6 -> V_129 = V_145 ;
V_36 -> V_128 = V_145 ;
V_36 -> V_134 = V_145 + ( 2ULL << V_36 -> V_147 ) ;
V_166 = F_82 ( V_6 , V_36 ) ;
F_89 ( V_36 -> V_20 , & V_6 -> V_131 [ V_166 ] ) ;
F_10 ( L_13 ,
V_166 , V_6 -> V_131 [ V_166 ] ,
( unsigned long long ) V_24 -> V_128 ,
( unsigned long long ) V_24 -> V_134 ,
( unsigned long long ) V_6 -> V_129 ) ;
V_168:
F_87 ( V_36 , V_24 , V_145 ) ;
}
static void F_21 ( struct V_5 * V_6 , struct V_23 * V_24 ,
enum V_162 V_163 )
{
V_24 -> V_158 = V_24 -> V_159 = V_24 -> V_35 ;
F_108 ( V_6 , V_24 , V_163 ) ;
if ( V_6 -> V_42 == NULL ) {
V_6 -> V_42 = V_24 ;
V_6 -> V_143 = V_6 -> V_129 = V_24 -> V_128 ;
} else if ( V_24 != V_6 -> V_42 )
F_110 ( V_6 , V_24 ) ;
}
static void F_118 ( struct V_5 * V_6 , struct V_124 * V_36 ,
struct V_23 * V_24 )
{
unsigned int V_37 , V_169 ;
T_2 V_145 ;
V_145 = F_78 ( V_24 -> V_128 , V_36 -> V_147 ) ;
V_169 = ( V_145 - V_36 -> V_128 ) >> V_36 -> V_147 ;
V_37 = ( V_36 -> V_150 + V_169 ) % V_148 ;
F_93 ( & V_24 -> V_133 ) ;
if ( F_94 ( & V_36 -> V_151 [ V_37 ] ) )
F_95 ( V_169 , & V_36 -> V_152 ) ;
}
static void F_29 ( struct V_5 * V_6 , struct V_23 * V_24 )
{
struct V_124 * V_36 = V_24 -> V_36 ;
unsigned long V_130 ;
T_2 V_145 ;
int V_166 ;
if ( V_24 == V_6 -> V_42 ) {
F_105 ( V_24 ) ;
V_6 -> V_42 = F_24 ( V_6 ) ;
return;
}
V_24 -> V_134 = V_24 -> V_128 ;
F_118 ( V_6 , V_36 , V_24 ) ;
if ( ! V_36 -> V_152 ) {
F_95 ( V_36 -> V_20 , & V_6 -> V_131 [ V_140 ] ) ;
F_95 ( V_36 -> V_20 , & V_6 -> V_131 [ V_135 ] ) ;
F_95 ( V_36 -> V_20 , & V_6 -> V_131 [ V_139 ] ) ;
if ( F_119 ( V_36 -> V_20 , & V_6 -> V_131 [ V_132 ] ) &&
! ( V_6 -> V_131 [ V_132 ] & ~ ( ( 1UL << V_36 -> V_20 ) - 1 ) ) ) {
V_130 = V_6 -> V_131 [ V_132 ] & ( ( 1UL << V_36 -> V_20 ) - 1 ) ;
if ( V_130 )
V_130 = ~ ( ( 1UL << F_9 ( V_130 ) ) - 1 ) ;
else
V_130 = ~ 0UL ;
F_83 ( V_6 , V_130 , V_135 , V_132 ) ;
F_83 ( V_6 , V_130 , V_139 , V_140 ) ;
}
F_95 ( V_36 -> V_20 , & V_6 -> V_131 [ V_132 ] ) ;
} else if ( F_94 ( & V_36 -> V_151 [ V_36 -> V_150 ] ) ) {
V_24 = F_96 ( V_36 ) ;
V_145 = F_78 ( V_24 -> V_128 , V_36 -> V_147 ) ;
if ( V_36 -> V_128 != V_145 ) {
F_95 ( V_36 -> V_20 , & V_6 -> V_131 [ V_132 ] ) ;
F_95 ( V_36 -> V_20 , & V_6 -> V_131 [ V_140 ] ) ;
F_95 ( V_36 -> V_20 , & V_6 -> V_131 [ V_135 ] ) ;
F_95 ( V_36 -> V_20 , & V_6 -> V_131 [ V_139 ] ) ;
V_36 -> V_128 = V_145 ;
V_36 -> V_134 = V_145 + ( 2ULL << V_36 -> V_147 ) ;
V_166 = F_82 ( V_6 , V_36 ) ;
F_89 ( V_36 -> V_20 , & V_6 -> V_131 [ V_166 ] ) ;
}
}
}
static void F_120 ( struct V_2 * V_3 , unsigned long V_50 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 = (struct V_1 * ) V_50 ;
if ( V_11 -> V_13 -> V_6 . V_14 == 0 )
F_26 ( V_6 , V_11 ) ;
}
static unsigned int F_121 ( struct V_5 * V_6 ,
struct V_170 * V_146 )
{
struct V_23 * V_24 ;
struct V_1 * V_11 ;
unsigned int V_12 ;
F_15 (agg, slot, next) {
F_122 (cl, &agg->active, alist) {
if ( ! V_11 -> V_13 -> V_155 -> V_171 )
continue;
V_12 = V_11 -> V_13 -> V_155 -> V_171 ( V_11 -> V_13 ) ;
if ( V_12 > 0 ) {
if ( V_11 -> V_13 -> V_6 . V_14 == 0 )
F_26 ( V_6 , V_11 ) ;
return V_12 ;
}
}
}
return 0 ;
}
static unsigned int F_123 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_124 * V_36 ;
unsigned int V_37 , V_172 , V_12 ;
for ( V_37 = 0 ; V_37 <= V_173 ; V_37 ++ ) {
V_36 = & V_6 -> V_38 [ V_37 ] ;
for ( V_172 = 0 ; V_172 < V_148 ; V_172 ++ ) {
V_12 = F_121 ( V_6 , & V_36 -> V_151 [ V_172 ] ) ;
if ( V_12 > 0 ) {
V_3 -> V_6 . V_14 -- ;
return V_12 ;
}
}
}
return 0 ;
}
static int F_124 ( struct V_2 * V_3 , struct V_48 * V_174 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_124 * V_36 ;
int V_37 , V_172 , V_54 ;
T_1 V_175 , V_176 , V_177 ;
V_54 = F_125 ( & V_6 -> V_9 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( F_39 ( V_3 ) -> V_178 + 1 > V_179 )
V_177 = V_179 ;
else
V_177 = F_39 ( V_3 ) -> V_178 + 1 ;
V_175 = F_9 ( V_177 ) ;
V_6 -> V_33 = 1 << V_175 ;
V_176 = V_63 + V_175 ;
V_6 -> V_17 = V_180 + V_176 - V_173 ;
for ( V_37 = 0 ; V_37 <= V_173 ; V_37 ++ ) {
V_36 = & V_6 -> V_38 [ V_37 ] ;
V_36 -> V_20 = V_37 ;
V_36 -> V_147 = V_6 -> V_17 + V_37 ;
for ( V_172 = 0 ; V_172 < V_148 ; V_172 ++ )
F_126 ( & V_36 -> V_151 [ V_172 ] ) ;
}
F_126 ( & V_6 -> V_29 ) ;
return 0 ;
}
static void F_127 ( struct V_2 * V_3 )
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
static void F_128 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_181 * V_133 ;
unsigned int V_37 ;
F_129 ( & V_6 -> V_79 ) ;
for ( V_37 = 0 ; V_37 < V_6 -> V_9 . V_102 ; V_37 ++ ) {
F_130 (cl, next, &q->clhash.hash[i],
common.hnode) {
F_50 ( V_3 , V_11 ) ;
}
}
F_131 ( & V_6 -> V_9 ) ;
}
static int T_4 F_132 ( void )
{
return F_133 ( & V_182 ) ;
}
static void T_5 F_134 ( void )
{
F_135 ( & V_182 ) ;
}
