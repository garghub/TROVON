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
V_24 -> V_34 = V_31 ;
}
static void F_18 ( struct V_5 * V_6 ,
struct V_23 * V_24 ,
struct V_1 * V_11 )
{
V_11 -> V_24 = V_24 ;
F_16 ( V_6 , V_24 , V_24 -> V_34 + 1 ) ;
if ( V_11 -> V_13 -> V_6 . V_14 > 0 ) {
F_19 ( & V_11 -> V_40 , & V_24 -> V_27 ) ;
if ( F_20 ( & V_24 -> V_27 , struct V_1 , V_40 ) ==
V_11 && V_6 -> V_41 != V_24 )
F_21 ( V_6 , V_24 , V_42 ) ;
}
}
static void F_22 ( struct V_5 * V_6 , struct V_23 * V_24 )
{
if ( ! F_23 ( & V_24 -> V_28 ) )
F_17 ( & V_24 -> V_28 ) ;
if ( V_6 -> V_41 == V_24 )
V_6 -> V_41 = F_24 ( V_6 ) ;
F_25 ( V_24 ) ;
}
static void F_26 ( struct V_5 * V_6 , struct V_1 * V_11 )
{
struct V_23 * V_24 = V_11 -> V_24 ;
F_27 ( & V_11 -> V_40 ) ;
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
struct V_23 * V_43 = F_14 ( V_6 , V_25 , V_26 ) ;
if ( V_43 == NULL ) {
V_43 = F_33 ( sizeof( * V_43 ) , V_44 ) ;
if ( V_43 == NULL )
return - V_45 ;
F_11 ( V_6 , V_43 , V_25 , V_26 ) ;
}
F_31 ( V_6 , V_11 ) ;
F_18 ( V_6 , V_43 , V_11 ) ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 , T_1 V_4 , T_1 V_46 ,
struct V_47 * * V_48 , unsigned long * V_49 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 = (struct V_1 * ) * V_49 ;
bool V_50 = false ;
struct V_47 * V_51 [ V_52 + 1 ] ;
struct V_23 * V_43 = NULL ;
T_1 V_26 , V_25 , V_15 ;
int V_53 ;
int V_54 ;
if ( V_48 [ V_55 ] == NULL ) {
F_35 ( L_2 ) ;
return - V_56 ;
}
V_53 = F_36 ( V_51 , V_52 , V_48 [ V_55 ] , V_57 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_51 [ V_58 ] ) {
V_26 = F_37 ( V_51 [ V_58 ] ) ;
if ( ! V_26 || V_26 > ( 1UL << V_59 ) ) {
F_35 ( L_3 , V_26 ) ;
return - V_56 ;
}
} else
V_26 = 1 ;
if ( V_51 [ V_60 ] ) {
V_25 = F_37 ( V_51 [ V_60 ] ) ;
if ( V_25 < V_61 || V_25 > ( 1UL << V_62 ) ) {
F_35 ( L_4 , V_25 ) ;
return - V_56 ;
}
} else
V_25 = F_38 ( F_39 ( V_3 ) ) ;
V_15 = V_22 / V_26 ;
V_26 = V_22 / V_15 ;
if ( V_11 != NULL &&
V_25 == V_11 -> V_24 -> V_25 &&
V_26 == V_11 -> V_24 -> V_30 )
return 0 ;
V_54 = V_26 - ( V_11 ? V_11 -> V_24 -> V_30 : 0 ) ;
if ( V_6 -> V_39 + V_54 > V_63 ) {
F_35 ( L_5 ,
V_54 , V_6 -> V_39 ) ;
return - V_56 ;
}
if ( V_11 != NULL ) {
if ( V_48 [ V_64 ] ) {
V_53 = F_40 ( & V_11 -> V_65 , & V_11 -> V_66 ,
F_41 ( V_3 ) ,
V_48 [ V_64 ] ) ;
if ( V_53 )
return V_53 ;
}
V_50 = true ;
goto V_67;
}
V_11 = F_33 ( sizeof( struct V_1 ) , V_68 ) ;
if ( V_11 == NULL )
return - V_45 ;
V_11 -> V_69 = 1 ;
V_11 -> V_10 . V_4 = V_4 ;
V_11 -> V_70 = V_25 ;
V_11 -> V_13 = F_42 ( V_3 -> V_71 ,
& V_72 , V_4 ) ;
if ( V_11 -> V_13 == NULL )
V_11 -> V_13 = & V_73 ;
if ( V_48 [ V_64 ] ) {
V_53 = F_43 ( & V_11 -> V_65 , & V_11 -> V_66 ,
F_41 ( V_3 ) ,
V_48 [ V_64 ] ) ;
if ( V_53 )
goto V_74;
}
F_44 ( V_3 ) ;
F_45 ( & V_6 -> V_9 , & V_11 -> V_10 ) ;
F_46 ( V_3 ) ;
F_47 ( V_3 , & V_6 -> V_9 ) ;
V_67:
F_44 ( V_3 ) ;
V_43 = F_14 ( V_6 , V_25 , V_26 ) ;
if ( V_43 == NULL ) {
F_46 ( V_3 ) ;
V_43 = F_33 ( sizeof( * V_43 ) , V_68 ) ;
if ( V_43 == NULL ) {
V_53 = - V_45 ;
F_48 ( & V_11 -> V_65 , & V_11 -> V_66 ) ;
goto V_74;
}
F_44 ( V_3 ) ;
F_11 ( V_6 , V_43 , V_25 , V_26 ) ;
}
if ( V_50 )
F_31 ( V_6 , V_11 ) ;
F_18 ( V_6 , V_43 , V_11 ) ;
F_46 ( V_3 ) ;
* V_49 = ( unsigned long ) V_11 ;
return 0 ;
V_74:
F_49 ( V_11 -> V_13 ) ;
F_25 ( V_11 ) ;
return V_53 ;
}
static void F_50 ( struct V_2 * V_3 , struct V_1 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
F_30 ( V_6 , V_11 ) ;
F_48 ( & V_11 -> V_65 , & V_11 -> V_66 ) ;
F_49 ( V_11 -> V_13 ) ;
F_25 ( V_11 ) ;
}
static int F_51 ( struct V_2 * V_3 , unsigned long V_49 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 = (struct V_1 * ) V_49 ;
if ( V_11 -> V_75 > 0 )
return - V_76 ;
F_44 ( V_3 ) ;
F_5 ( V_11 ) ;
F_52 ( & V_6 -> V_9 , & V_11 -> V_10 ) ;
F_53 ( -- V_11 -> V_69 == 0 ) ;
F_46 ( V_3 ) ;
return 0 ;
}
static unsigned long F_54 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_11 = F_1 ( V_3 , V_4 ) ;
if ( V_11 != NULL )
V_11 -> V_69 ++ ;
return ( unsigned long ) V_11 ;
}
static void F_55 ( struct V_2 * V_3 , unsigned long V_49 )
{
struct V_1 * V_11 = (struct V_1 * ) V_49 ;
if ( -- V_11 -> V_69 == 0 )
F_50 ( V_3 , V_11 ) ;
}
static struct V_77 * * F_56 ( struct V_2 * V_3 , unsigned long V_11 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
if ( V_11 )
return NULL ;
return & V_6 -> V_78 ;
}
static unsigned long F_57 ( struct V_2 * V_3 , unsigned long V_79 ,
T_1 V_4 )
{
struct V_1 * V_11 = F_1 ( V_3 , V_4 ) ;
if ( V_11 != NULL )
V_11 -> V_75 ++ ;
return ( unsigned long ) V_11 ;
}
static void F_58 ( struct V_2 * V_3 , unsigned long V_49 )
{
struct V_1 * V_11 = (struct V_1 * ) V_49 ;
V_11 -> V_75 -- ;
}
static int F_59 ( struct V_2 * V_3 , unsigned long V_49 ,
struct V_2 * V_80 , struct V_2 * * V_81 )
{
struct V_1 * V_11 = (struct V_1 * ) V_49 ;
if ( V_80 == NULL ) {
V_80 = F_42 ( V_3 -> V_71 ,
& V_72 , V_11 -> V_10 . V_4 ) ;
if ( V_80 == NULL )
V_80 = & V_73 ;
}
F_44 ( V_3 ) ;
F_5 ( V_11 ) ;
* V_81 = V_11 -> V_13 ;
V_11 -> V_13 = V_80 ;
F_46 ( V_3 ) ;
return 0 ;
}
static struct V_2 * F_60 ( struct V_2 * V_3 , unsigned long V_49 )
{
struct V_1 * V_11 = (struct V_1 * ) V_49 ;
return V_11 -> V_13 ;
}
static int F_61 ( struct V_2 * V_3 , unsigned long V_49 ,
struct V_82 * V_83 , struct V_84 * V_85 )
{
struct V_1 * V_11 = (struct V_1 * ) V_49 ;
struct V_47 * V_86 ;
V_85 -> V_87 = V_88 ;
V_85 -> V_89 = V_11 -> V_10 . V_4 ;
V_85 -> V_90 = V_11 -> V_13 -> V_91 ;
V_86 = F_62 ( V_83 , V_55 ) ;
if ( V_86 == NULL )
goto V_92;
if ( F_63 ( V_83 , V_58 , V_11 -> V_24 -> V_30 ) ||
F_63 ( V_83 , V_60 , V_11 -> V_24 -> V_25 ) )
goto V_92;
return F_64 ( V_83 , V_86 ) ;
V_92:
F_65 ( V_83 , V_86 ) ;
return - V_93 ;
}
static int F_66 ( struct V_2 * V_3 , unsigned long V_49 ,
struct V_94 * V_95 )
{
struct V_1 * V_11 = (struct V_1 * ) V_49 ;
struct V_96 V_97 ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
V_11 -> V_13 -> V_98 . V_14 = V_11 -> V_13 -> V_6 . V_14 ;
V_97 . V_26 = V_11 -> V_24 -> V_30 ;
V_97 . V_25 = V_11 -> V_24 -> V_25 ;
if ( F_67 ( V_95 , & V_11 -> V_65 ) < 0 ||
F_68 ( V_95 , & V_11 -> V_65 , & V_11 -> V_66 ) < 0 ||
F_69 ( V_95 , & V_11 -> V_13 -> V_98 ) < 0 )
return - 1 ;
return F_70 ( V_95 , & V_97 , sizeof( V_97 ) ) ;
}
static void F_71 ( struct V_2 * V_3 , struct V_99 * V_49 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
unsigned int V_37 ;
if ( V_49 -> V_100 )
return;
for ( V_37 = 0 ; V_37 < V_6 -> V_9 . V_101 ; V_37 ++ ) {
F_15 (cl, &q->clhash.hash[i], common.hnode) {
if ( V_49 -> V_102 < V_49 -> V_103 ) {
V_49 -> V_102 ++ ;
continue;
}
if ( V_49 -> V_104 ( V_3 , ( unsigned long ) V_11 , V_49 ) < 0 ) {
V_49 -> V_100 = 1 ;
return;
}
V_49 -> V_102 ++ ;
}
}
}
static struct V_1 * F_72 ( struct V_82 * V_83 , struct V_2 * V_3 ,
int * V_105 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_106 V_107 ;
int V_108 ;
if ( F_73 ( V_83 -> V_109 ^ V_3 -> V_91 ) == 0 ) {
F_10 ( L_6 , V_83 -> V_109 ) ;
V_11 = F_1 ( V_3 , V_83 -> V_109 ) ;
if ( V_11 != NULL )
return V_11 ;
}
* V_105 = V_110 | V_111 ;
V_108 = F_74 ( V_83 , V_6 -> V_78 , & V_107 ) ;
if ( V_108 >= 0 ) {
#ifdef F_75
switch ( V_108 ) {
case V_112 :
case V_113 :
* V_105 = V_110 | V_114 ;
case V_115 :
return NULL ;
}
#endif
V_11 = (struct V_1 * ) V_107 . V_116 ;
if ( V_11 == NULL )
V_11 = F_1 ( V_3 , V_107 . V_4 ) ;
return V_11 ;
}
return NULL ;
}
static inline int F_76 ( T_2 V_117 , T_2 V_118 )
{
return ( V_119 ) ( V_117 - V_118 ) > 0 ;
}
static inline T_2 F_77 ( T_2 V_120 , unsigned int V_121 )
{
return V_120 & ~ ( ( 1ULL << V_121 ) - 1 ) ;
}
static inline struct V_122 * F_78 ( struct V_5 * V_6 ,
unsigned long V_123 )
{
int V_20 = F_79 ( V_123 ) ;
return & V_6 -> V_38 [ V_20 ] ;
}
static inline unsigned long F_80 ( unsigned long V_123 , int V_124 )
{
return V_123 & ~ ( ( 1UL << V_124 ) - 1 ) ;
}
static int F_81 ( struct V_5 * V_6 , const struct V_122 * V_36 )
{
unsigned int V_125 = F_76 ( V_36 -> V_126 , V_6 -> V_127 ) ;
unsigned long V_128 = F_80 ( V_6 -> V_129 [ V_130 ] , V_36 -> V_20 ) ;
struct V_122 * V_131 ;
if ( V_128 ) {
V_131 = F_78 ( V_6 , V_128 ) ;
if ( F_76 ( V_36 -> V_132 , V_131 -> V_132 ) )
V_125 |= V_133 ;
}
return V_125 ;
}
static inline void F_82 ( struct V_5 * V_6 , unsigned long V_128 ,
int V_134 , int V_135 )
{
V_6 -> V_129 [ V_135 ] |= V_6 -> V_129 [ V_134 ] & V_128 ;
V_6 -> V_129 [ V_134 ] &= ~ V_128 ;
}
static void F_83 ( struct V_5 * V_6 , int V_20 , T_2 V_136 )
{
unsigned long V_128 = F_80 ( V_6 -> V_129 [ V_130 ] , V_20 + 1 ) ;
struct V_122 * V_131 ;
if ( V_128 ) {
V_131 = F_78 ( V_6 , V_128 ) ;
if ( ! F_76 ( V_131 -> V_132 , V_136 ) )
return;
}
V_128 = ( 1UL << V_20 ) - 1 ;
F_82 ( V_6 , V_128 , V_133 , V_130 ) ;
F_82 ( V_6 , V_128 , V_137 , V_138 ) ;
}
static void F_84 ( struct V_5 * V_6 )
{
unsigned long V_139 = V_6 -> V_127 >> V_6 -> V_17 ;
unsigned long V_140 = V_6 -> V_141 >> V_6 -> V_17 ;
if ( V_139 != V_140 ) {
unsigned long V_128 = ( 1ULL << F_85 ( V_139 ^ V_140 ) ) - 1 ;
F_82 ( V_6 , V_128 , V_138 , V_130 ) ;
F_82 ( V_6 , V_128 , V_137 , V_133 ) ;
}
}
static void F_86 ( struct V_122 * V_36 , struct V_23 * V_24 ,
T_2 V_142 )
{
T_2 V_143 = ( V_142 - V_36 -> V_126 ) >> V_36 -> V_144 ;
unsigned int V_37 ;
if ( F_87 ( V_143 > V_145 - 2 ) ) {
T_2 V_146 = V_142 - V_36 -> V_126 -
( ( T_2 ) ( V_145 - 2 ) << V_36 -> V_144 ) ;
V_24 -> V_126 -= V_146 ;
V_24 -> V_132 -= V_146 ;
V_143 = V_145 - 2 ;
}
V_37 = ( V_36 -> V_147 + V_143 ) % V_145 ;
F_13 ( & V_24 -> V_131 , & V_36 -> V_148 [ V_37 ] ) ;
F_88 ( V_143 , & V_36 -> V_149 ) ;
}
static struct V_23 * F_89 ( struct V_122 * V_36 )
{
return F_90 ( V_36 -> V_148 [ V_36 -> V_147 ] . V_150 ,
struct V_23 , V_131 ) ;
}
static void F_91 ( struct V_122 * V_36 )
{
struct V_23 * V_24 = F_89 ( V_36 ) ;
F_53 ( ! V_24 ) ;
F_92 ( & V_24 -> V_131 ) ;
if ( F_93 ( & V_36 -> V_148 [ V_36 -> V_147 ] ) )
F_94 ( 0 , & V_36 -> V_149 ) ;
}
static struct V_23 * F_95 ( struct V_122 * V_36 )
{
unsigned int V_37 ;
F_10 ( L_7 ,
V_36 -> V_20 , V_36 -> V_149 ) ;
if ( V_36 -> V_149 == 0 )
return NULL ;
V_37 = F_79 ( V_36 -> V_149 ) ;
if ( V_37 > 0 ) {
V_36 -> V_147 = ( V_36 -> V_147 + V_37 ) % V_145 ;
V_36 -> V_149 >>= V_37 ;
}
return F_89 ( V_36 ) ;
}
static void F_96 ( struct V_122 * V_36 , T_2 V_142 )
{
unsigned int V_37 = ( V_36 -> V_126 - V_142 ) >> V_36 -> V_144 ;
V_36 -> V_149 <<= V_37 ;
V_36 -> V_147 = ( V_36 -> V_147 - V_37 ) % V_145 ;
}
static void F_97 ( struct V_5 * V_6 )
{
struct V_122 * V_36 ;
unsigned long V_151 ;
V_151 = V_6 -> V_129 [ V_138 ] | V_6 -> V_129 [ V_137 ] ;
if ( V_151 ) {
if ( ! V_6 -> V_129 [ V_130 ] ) {
V_36 = F_78 ( V_6 , V_151 ) ;
if ( F_76 ( V_36 -> V_126 , V_6 -> V_127 ) )
V_6 -> V_127 = V_36 -> V_126 ;
}
F_84 ( V_6 ) ;
}
}
static void F_98 ( struct V_23 * V_24 ,
struct V_1 * V_11 , unsigned int V_12 )
{
F_99 ( V_11 -> V_13 ) ;
V_11 -> V_70 -= ( int ) V_12 ;
if ( V_11 -> V_13 -> V_6 . V_14 == 0 )
F_27 ( & V_11 -> V_40 ) ;
else if ( V_11 -> V_70 < F_100 ( V_11 -> V_13 -> V_152 -> V_153 ( V_11 -> V_13 ) ) ) {
V_11 -> V_70 += V_24 -> V_25 ;
F_101 ( & V_11 -> V_40 , & V_24 -> V_27 ) ;
}
}
static inline struct V_82 * F_102 ( struct V_23 * V_24 ,
struct V_1 * * V_11 ,
unsigned int * V_12 )
{
struct V_82 * V_83 ;
* V_11 = F_20 ( & V_24 -> V_27 , struct V_1 , V_40 ) ;
V_83 = ( * V_11 ) -> V_13 -> V_152 -> V_153 ( ( * V_11 ) -> V_13 ) ;
if ( V_83 == NULL )
F_103 ( 1 , L_8 ) ;
else
* V_12 = F_100 ( V_83 ) ;
return V_83 ;
}
static inline void F_104 ( struct V_23 * V_24 )
{
T_1 V_154 = F_105 ( V_24 -> V_35 ,
V_24 -> V_155 - V_24 -> V_156 ) ;
V_24 -> V_132 = V_24 -> V_126 + ( T_2 ) V_154 * V_24 -> V_15 ;
}
static struct V_82 * F_106 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_23 * V_41 = V_6 -> V_41 ;
struct V_1 * V_11 ;
struct V_82 * V_83 = NULL ;
unsigned int V_12 = 0 ;
if ( V_41 == NULL )
return NULL ;
if ( ! F_28 ( & V_41 -> V_27 ) )
V_83 = F_102 ( V_41 , & V_11 , & V_12 ) ;
if ( V_12 == 0 || V_41 -> V_156 < V_12 ) {
F_104 ( V_41 ) ;
V_41 -> V_155 = V_41 -> V_156 =
V_41 -> V_35 ;
if ( ! F_28 ( & V_41 -> V_27 ) ) {
F_107 ( V_6 , V_41 , V_157 ) ;
F_108 ( V_6 , V_41 ) ;
} else if ( V_3 -> V_6 . V_14 == 0 ) {
V_6 -> V_41 = NULL ;
return NULL ;
}
V_41 = V_6 -> V_41 = F_24 ( V_6 ) ;
V_83 = F_102 ( V_41 , & V_11 , & V_12 ) ;
}
if ( ! V_83 )
return NULL ;
V_3 -> V_6 . V_14 -- ;
F_109 ( V_3 , V_83 ) ;
F_98 ( V_41 , V_11 , V_12 ) ;
if ( F_87 ( V_41 -> V_156 < V_12 ) )
V_41 -> V_156 = 0 ;
else
V_41 -> V_156 -= V_12 ;
V_6 -> V_127 += ( T_2 ) V_12 * V_158 ;
F_10 ( L_9 ,
V_12 , ( unsigned long long ) V_41 -> V_132 ,
( unsigned long long ) V_6 -> V_127 ) ;
return V_83 ;
}
static struct V_23 * F_24 ( struct V_5 * V_6 )
{
struct V_122 * V_36 ;
struct V_23 * V_24 , * V_159 ;
T_2 V_136 ;
F_97 ( V_6 ) ;
V_6 -> V_141 = V_6 -> V_127 ;
if ( ! V_6 -> V_129 [ V_130 ] )
return NULL ;
V_36 = F_78 ( V_6 , V_6 -> V_129 [ V_130 ] ) ;
V_136 = V_36 -> V_132 ;
V_24 = F_89 ( V_36 ) ;
F_91 ( V_36 ) ;
V_159 = F_95 ( V_36 ) ;
if ( V_159 == NULL )
F_94 ( V_36 -> V_20 , & V_6 -> V_129 [ V_130 ] ) ;
else {
T_2 V_142 = F_77 ( V_159 -> V_126 ,
V_36 -> V_144 ) ;
unsigned int V_160 ;
if ( V_36 -> V_126 == V_142 )
return V_24 ;
V_36 -> V_126 = V_142 ;
V_36 -> V_132 = V_142 + ( 2ULL << V_36 -> V_144 ) ;
F_94 ( V_36 -> V_20 , & V_6 -> V_129 [ V_130 ] ) ;
V_160 = F_81 ( V_6 , V_36 ) ;
F_88 ( V_36 -> V_20 , & V_6 -> V_129 [ V_160 ] ) ;
}
F_83 ( V_6 , V_36 -> V_20 , V_136 ) ;
return V_24 ;
}
static void F_110 ( struct V_5 * V_6 , struct V_23 * V_24 )
{
unsigned long V_128 ;
T_2 V_161 , V_162 ;
int V_144 = V_24 -> V_36 -> V_144 ;
V_162 = F_77 ( V_24 -> V_132 , V_144 ) ;
V_161 = F_77 ( V_6 -> V_127 , V_144 ) + ( 1ULL << V_144 ) ;
if ( ! F_76 ( V_24 -> V_132 , V_6 -> V_127 ) || F_76 ( V_162 , V_161 ) ) {
V_128 = F_80 ( V_6 -> V_129 [ V_130 ] , V_24 -> V_36 -> V_20 ) ;
if ( V_128 ) {
struct V_122 * V_131 = F_78 ( V_6 , V_128 ) ;
if ( F_76 ( V_162 , V_131 -> V_132 ) ) {
if ( F_76 ( V_161 , V_131 -> V_132 ) )
V_24 -> V_126 = V_131 -> V_132 ;
else
V_24 -> V_126 = V_161 ;
return;
}
}
V_24 -> V_126 = V_6 -> V_127 ;
} else
V_24 -> V_126 = V_24 -> V_132 ;
}
static inline void
F_107 ( struct V_5 * V_6 ,
struct V_23 * V_24 , enum V_163 V_164 )
{
if ( V_164 != V_157 )
F_110 ( V_6 , V_24 ) ;
else
V_24 -> V_126 = V_24 -> V_132 ;
V_24 -> V_132 = V_24 -> V_126 + ( T_2 ) V_24 -> V_35 * V_24 -> V_15 ;
}
static int F_111 ( struct V_82 * V_83 , struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_23 * V_24 ;
int V_53 = 0 ;
V_11 = F_72 ( V_83 , V_3 , & V_53 ) ;
if ( V_11 == NULL ) {
if ( V_53 & V_111 )
V_3 -> V_98 . V_165 ++ ;
F_112 ( V_83 ) ;
return V_53 ;
}
F_10 ( L_10 , V_11 -> V_10 . V_4 ) ;
if ( F_87 ( V_11 -> V_24 -> V_25 < F_100 ( V_83 ) ) ) {
F_10 ( L_11 ,
V_11 -> V_24 -> V_25 , F_100 ( V_83 ) , V_11 -> V_10 . V_4 ) ;
V_53 = F_32 ( V_3 , V_11 , V_11 -> V_24 -> V_30 ,
F_100 ( V_83 ) ) ;
if ( V_53 )
return V_53 ;
}
V_53 = F_113 ( V_83 , V_11 -> V_13 ) ;
if ( F_87 ( V_53 != V_110 ) ) {
F_10 ( L_12 , V_53 ) ;
if ( F_114 ( V_53 ) ) {
V_11 -> V_98 . V_165 ++ ;
V_3 -> V_98 . V_165 ++ ;
}
return V_53 ;
}
F_115 ( & V_11 -> V_65 , V_83 ) ;
++ V_3 -> V_6 . V_14 ;
V_24 = V_11 -> V_24 ;
if ( V_11 -> V_13 -> V_6 . V_14 != 1 ) {
if ( F_87 ( V_83 == V_11 -> V_13 -> V_152 -> V_153 ( V_11 -> V_13 ) ) &&
F_20 ( & V_24 -> V_27 , struct V_1 , V_40 )
== V_11 && V_11 -> V_70 < F_100 ( V_83 ) )
F_101 ( & V_11 -> V_40 , & V_24 -> V_27 ) ;
return V_53 ;
}
V_11 -> V_70 = V_24 -> V_25 ;
F_19 ( & V_11 -> V_40 , & V_24 -> V_27 ) ;
if ( F_20 ( & V_24 -> V_27 , struct V_1 , V_40 ) != V_11 ||
V_6 -> V_41 == V_24 )
return V_53 ;
F_21 ( V_6 , V_24 , V_42 ) ;
return V_53 ;
}
static void F_108 ( struct V_5 * V_6 , struct V_23 * V_24 )
{
struct V_122 * V_36 = V_24 -> V_36 ;
T_2 V_142 ;
int V_160 ;
V_142 = F_77 ( V_24 -> V_126 , V_36 -> V_144 ) ;
if ( V_36 -> V_149 ) {
if ( ! F_76 ( V_36 -> V_126 , V_24 -> V_126 ) )
goto V_166;
F_96 ( V_36 , V_142 ) ;
F_94 ( V_36 -> V_20 , & V_6 -> V_129 [ V_138 ] ) ;
F_94 ( V_36 -> V_20 , & V_6 -> V_129 [ V_137 ] ) ;
} else if ( ! V_6 -> V_129 [ V_130 ] && F_76 ( V_142 , V_6 -> V_127 ) &&
V_6 -> V_41 == NULL )
V_6 -> V_127 = V_142 ;
V_36 -> V_126 = V_142 ;
V_36 -> V_132 = V_142 + ( 2ULL << V_36 -> V_144 ) ;
V_160 = F_81 ( V_6 , V_36 ) ;
F_88 ( V_36 -> V_20 , & V_6 -> V_129 [ V_160 ] ) ;
F_10 ( L_13 ,
V_160 , V_6 -> V_129 [ V_160 ] ,
( unsigned long long ) V_24 -> V_126 ,
( unsigned long long ) V_24 -> V_132 ,
( unsigned long long ) V_6 -> V_127 ) ;
V_166:
F_86 ( V_36 , V_24 , V_142 ) ;
}
static void F_21 ( struct V_5 * V_6 , struct V_23 * V_24 ,
enum V_163 V_164 )
{
V_24 -> V_155 = V_24 -> V_156 = V_24 -> V_35 ;
F_107 ( V_6 , V_24 , V_164 ) ;
if ( V_6 -> V_41 == NULL ) {
V_6 -> V_41 = V_24 ;
V_6 -> V_141 = V_6 -> V_127 = V_24 -> V_126 ;
} else if ( V_24 != V_6 -> V_41 )
F_108 ( V_6 , V_24 ) ;
}
static void F_116 ( struct V_5 * V_6 , struct V_122 * V_36 ,
struct V_23 * V_24 )
{
unsigned int V_37 , V_167 ;
T_2 V_142 ;
V_142 = F_77 ( V_24 -> V_126 , V_36 -> V_144 ) ;
V_167 = ( V_142 - V_36 -> V_126 ) >> V_36 -> V_144 ;
V_37 = ( V_36 -> V_147 + V_167 ) % V_145 ;
F_92 ( & V_24 -> V_131 ) ;
if ( F_93 ( & V_36 -> V_148 [ V_37 ] ) )
F_94 ( V_167 , & V_36 -> V_149 ) ;
}
static void F_29 ( struct V_5 * V_6 , struct V_23 * V_24 )
{
struct V_122 * V_36 = V_24 -> V_36 ;
unsigned long V_128 ;
T_2 V_142 ;
int V_160 ;
if ( V_24 == V_6 -> V_41 ) {
F_104 ( V_24 ) ;
V_6 -> V_41 = F_24 ( V_6 ) ;
return;
}
V_24 -> V_132 = V_24 -> V_126 ;
F_116 ( V_6 , V_36 , V_24 ) ;
if ( ! V_36 -> V_149 ) {
F_94 ( V_36 -> V_20 , & V_6 -> V_129 [ V_138 ] ) ;
F_94 ( V_36 -> V_20 , & V_6 -> V_129 [ V_133 ] ) ;
F_94 ( V_36 -> V_20 , & V_6 -> V_129 [ V_137 ] ) ;
if ( F_117 ( V_36 -> V_20 , & V_6 -> V_129 [ V_130 ] ) &&
! ( V_6 -> V_129 [ V_130 ] & ~ ( ( 1UL << V_36 -> V_20 ) - 1 ) ) ) {
V_128 = V_6 -> V_129 [ V_130 ] & ( ( 1UL << V_36 -> V_20 ) - 1 ) ;
if ( V_128 )
V_128 = ~ ( ( 1UL << F_9 ( V_128 ) ) - 1 ) ;
else
V_128 = ~ 0UL ;
F_82 ( V_6 , V_128 , V_133 , V_130 ) ;
F_82 ( V_6 , V_128 , V_137 , V_138 ) ;
}
F_94 ( V_36 -> V_20 , & V_6 -> V_129 [ V_130 ] ) ;
} else if ( F_93 ( & V_36 -> V_148 [ V_36 -> V_147 ] ) ) {
V_24 = F_95 ( V_36 ) ;
V_142 = F_77 ( V_24 -> V_126 , V_36 -> V_144 ) ;
if ( V_36 -> V_126 != V_142 ) {
F_94 ( V_36 -> V_20 , & V_6 -> V_129 [ V_130 ] ) ;
F_94 ( V_36 -> V_20 , & V_6 -> V_129 [ V_138 ] ) ;
F_94 ( V_36 -> V_20 , & V_6 -> V_129 [ V_133 ] ) ;
F_94 ( V_36 -> V_20 , & V_6 -> V_129 [ V_137 ] ) ;
V_36 -> V_126 = V_142 ;
V_36 -> V_132 = V_142 + ( 2ULL << V_36 -> V_144 ) ;
V_160 = F_81 ( V_6 , V_36 ) ;
F_88 ( V_36 -> V_20 , & V_6 -> V_129 [ V_160 ] ) ;
}
}
}
static void F_118 ( struct V_2 * V_3 , unsigned long V_49 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 = (struct V_1 * ) V_49 ;
if ( V_11 -> V_13 -> V_6 . V_14 == 0 )
F_26 ( V_6 , V_11 ) ;
}
static unsigned int F_119 ( struct V_5 * V_6 ,
struct V_168 * V_143 )
{
struct V_23 * V_24 ;
struct V_1 * V_11 ;
unsigned int V_12 ;
F_15 (agg, slot, next) {
F_120 (cl, &agg->active, alist) {
if ( ! V_11 -> V_13 -> V_152 -> V_169 )
continue;
V_12 = V_11 -> V_13 -> V_152 -> V_169 ( V_11 -> V_13 ) ;
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
struct V_122 * V_36 ;
unsigned int V_37 , V_170 , V_12 ;
for ( V_37 = 0 ; V_37 <= V_171 ; V_37 ++ ) {
V_36 = & V_6 -> V_38 [ V_37 ] ;
for ( V_170 = 0 ; V_170 < V_145 ; V_170 ++ ) {
V_12 = F_119 ( V_6 , & V_36 -> V_148 [ V_170 ] ) ;
if ( V_12 > 0 ) {
V_3 -> V_6 . V_14 -- ;
return V_12 ;
}
}
}
return 0 ;
}
static int F_122 ( struct V_2 * V_3 , struct V_47 * V_172 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_122 * V_36 ;
int V_37 , V_170 , V_53 ;
T_1 V_173 , V_174 , V_175 ;
V_53 = F_123 ( & V_6 -> V_9 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( F_39 ( V_3 ) -> V_176 + 1 > V_177 )
V_175 = V_177 ;
else
V_175 = F_39 ( V_3 ) -> V_176 + 1 ;
V_173 = F_9 ( V_175 ) ;
V_6 -> V_33 = 1 << V_173 ;
V_174 = V_62 + V_173 ;
V_6 -> V_17 = V_178 + V_174 - V_171 ;
for ( V_37 = 0 ; V_37 <= V_171 ; V_37 ++ ) {
V_36 = & V_6 -> V_38 [ V_37 ] ;
V_36 -> V_20 = V_37 ;
V_36 -> V_144 = V_6 -> V_17 + V_37 ;
for ( V_170 = 0 ; V_170 < V_145 ; V_170 ++ )
F_124 ( & V_36 -> V_148 [ V_170 ] ) ;
}
F_124 ( & V_6 -> V_29 ) ;
return 0 ;
}
static void F_125 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
unsigned int V_37 ;
for ( V_37 = 0 ; V_37 < V_6 -> V_9 . V_101 ; V_37 ++ ) {
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
struct V_179 * V_131 ;
unsigned int V_37 ;
F_127 ( & V_6 -> V_78 ) ;
for ( V_37 = 0 ; V_37 < V_6 -> V_9 . V_101 ; V_37 ++ ) {
F_128 (cl, next, &q->clhash.hash[i],
common.hnode) {
F_50 ( V_3 , V_11 ) ;
}
}
F_129 ( & V_6 -> V_9 ) ;
}
static int T_3 F_130 ( void )
{
return F_131 ( & V_180 ) ;
}
static void T_4 F_132 ( void )
{
F_133 ( & V_180 ) ;
}
