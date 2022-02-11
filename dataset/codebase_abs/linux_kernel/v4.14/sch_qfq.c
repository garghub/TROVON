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
unsigned int V_15 = V_11 -> V_13 -> V_16 . V_15 ;
F_6 ( V_11 -> V_13 ) ;
F_7 ( V_11 -> V_13 , V_12 , V_15 ) ;
}
static int F_8 ( T_1 V_17 , unsigned int V_18 , T_1 V_19 )
{
T_2 V_20 = ( T_2 ) V_18 * V_17 ;
unsigned long V_21 ;
int V_22 = 0 ;
V_21 = V_20 >> V_19 ;
if ( ! V_21 )
goto V_23;
V_22 = F_9 ( V_21 ) + 1 ;
V_22 -= ! ( V_20 - ( 1ULL << ( V_22 + V_19 - 1 ) ) ) ;
if ( V_22 < 0 )
V_22 = 0 ;
V_23:
F_10 ( L_1 ,
( unsigned long ) V_24 / V_17 , V_18 , V_22 ) ;
return V_22 ;
}
static void F_11 ( struct V_5 * V_6 , struct V_25 * V_26 ,
T_1 V_27 , T_1 V_28 )
{
F_12 ( & V_26 -> V_29 ) ;
F_13 ( & V_26 -> V_30 , & V_6 -> V_31 ) ;
V_26 -> V_27 = V_27 ;
V_26 -> V_32 = V_28 ;
}
static struct V_25 * F_14 ( struct V_5 * V_6 ,
T_1 V_27 , T_1 V_28 )
{
struct V_25 * V_26 ;
F_15 (agg, &q->nonfull_aggs, nonfull_next)
if ( V_26 -> V_27 == V_27 && V_26 -> V_32 == V_28 )
return V_26 ;
return NULL ;
}
static void F_16 ( struct V_5 * V_6 , struct V_25 * V_26 ,
int V_33 )
{
T_1 V_34 ;
if ( V_33 == V_6 -> V_35 )
F_17 ( & V_26 -> V_30 ) ;
if ( V_26 -> V_36 > V_33 &&
V_33 == V_6 -> V_35 - 1 )
F_13 ( & V_26 -> V_30 , & V_6 -> V_31 ) ;
V_26 -> V_37 = V_33 * V_26 -> V_27 ;
V_34 = V_26 -> V_32 * V_33 ;
V_26 -> V_17 = V_24 / V_34 ;
if ( V_26 -> V_38 == NULL ) {
int V_39 = F_8 ( V_26 -> V_17 , V_26 -> V_37 ,
V_6 -> V_19 ) ;
V_26 -> V_38 = & V_6 -> V_40 [ V_39 ] ;
}
V_6 -> V_41 +=
( int ) V_26 -> V_32 * ( V_33 - V_26 -> V_36 ) ;
V_6 -> V_42 = V_24 / V_6 -> V_41 ;
V_26 -> V_36 = V_33 ;
}
static void F_18 ( struct V_5 * V_6 ,
struct V_25 * V_26 ,
struct V_1 * V_11 )
{
V_11 -> V_26 = V_26 ;
F_16 ( V_6 , V_26 , V_26 -> V_36 + 1 ) ;
if ( V_11 -> V_13 -> V_6 . V_14 > 0 ) {
F_19 ( & V_11 -> V_43 , & V_26 -> V_29 ) ;
if ( F_20 ( & V_26 -> V_29 , struct V_1 , V_43 ) ==
V_11 && V_6 -> V_44 != V_26 )
F_21 ( V_6 , V_26 , V_45 ) ;
}
}
static void F_22 ( struct V_5 * V_6 , struct V_25 * V_26 )
{
F_17 ( & V_26 -> V_30 ) ;
V_6 -> V_41 -= V_26 -> V_32 ;
if ( V_6 -> V_41 != 0 )
V_6 -> V_42 = V_24 / V_6 -> V_41 ;
if ( V_6 -> V_44 == V_26 )
V_6 -> V_44 = F_23 ( V_6 ) ;
F_24 ( V_26 ) ;
}
static void F_25 ( struct V_5 * V_6 , struct V_1 * V_11 )
{
struct V_25 * V_26 = V_11 -> V_26 ;
F_26 ( & V_11 -> V_43 ) ;
if ( F_27 ( & V_26 -> V_29 ) )
F_28 ( V_6 , V_26 ) ;
}
static void F_29 ( struct V_5 * V_6 , struct V_1 * V_11 )
{
struct V_25 * V_26 = V_11 -> V_26 ;
V_11 -> V_26 = NULL ;
if ( V_26 -> V_36 == 1 ) {
F_22 ( V_6 , V_26 ) ;
return;
}
F_16 ( V_6 , V_26 , V_26 -> V_36 - 1 ) ;
}
static void F_30 ( struct V_5 * V_6 , struct V_1 * V_11 )
{
if ( V_11 -> V_13 -> V_6 . V_14 > 0 )
F_25 ( V_6 , V_11 ) ;
F_29 ( V_6 , V_11 ) ;
}
static int F_31 ( struct V_2 * V_3 , struct V_1 * V_11 , T_1 V_28 ,
T_1 V_27 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_25 * V_46 = F_14 ( V_6 , V_27 , V_28 ) ;
if ( V_46 == NULL ) {
V_46 = F_32 ( sizeof( * V_46 ) , V_47 ) ;
if ( V_46 == NULL )
return - V_48 ;
F_11 ( V_6 , V_46 , V_27 , V_28 ) ;
}
F_30 ( V_6 , V_11 ) ;
F_18 ( V_6 , V_46 , V_11 ) ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 , T_1 V_4 , T_1 V_49 ,
struct V_50 * * V_51 , unsigned long * V_52 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 = (struct V_1 * ) * V_52 ;
bool V_53 = false ;
struct V_50 * V_54 [ V_55 + 1 ] ;
struct V_25 * V_46 = NULL ;
T_1 V_28 , V_27 , V_17 ;
int V_56 ;
int V_57 ;
if ( V_51 [ V_58 ] == NULL ) {
F_34 ( L_2 ) ;
return - V_59 ;
}
V_56 = F_35 ( V_54 , V_55 , V_51 [ V_58 ] , V_60 ,
NULL ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_54 [ V_61 ] ) {
V_28 = F_36 ( V_54 [ V_61 ] ) ;
if ( ! V_28 || V_28 > ( 1UL << V_62 ) ) {
F_34 ( L_3 , V_28 ) ;
return - V_59 ;
}
} else
V_28 = 1 ;
if ( V_54 [ V_63 ] ) {
V_27 = F_36 ( V_54 [ V_63 ] ) ;
if ( V_27 < V_64 || V_27 > ( 1UL << V_65 ) ) {
F_34 ( L_4 , V_27 ) ;
return - V_59 ;
}
} else
V_27 = F_37 ( F_38 ( V_3 ) ) ;
V_17 = V_24 / V_28 ;
V_28 = V_24 / V_17 ;
if ( V_11 != NULL &&
V_27 == V_11 -> V_26 -> V_27 &&
V_28 == V_11 -> V_26 -> V_32 )
return 0 ;
V_57 = V_28 - ( V_11 ? V_11 -> V_26 -> V_32 : 0 ) ;
if ( V_6 -> V_41 + V_57 > V_66 ) {
F_34 ( L_5 ,
V_57 , V_6 -> V_41 ) ;
return - V_59 ;
}
if ( V_11 != NULL ) {
if ( V_51 [ V_67 ] ) {
V_56 = F_39 ( & V_11 -> V_68 , NULL ,
& V_11 -> V_69 ,
NULL ,
F_40 ( V_3 ) ,
V_51 [ V_67 ] ) ;
if ( V_56 )
return V_56 ;
}
V_53 = true ;
goto V_70;
}
V_11 = F_32 ( sizeof( struct V_1 ) , V_71 ) ;
if ( V_11 == NULL )
return - V_48 ;
V_11 -> V_10 . V_4 = V_4 ;
V_11 -> V_72 = V_27 ;
V_11 -> V_13 = F_41 ( V_3 -> V_73 ,
& V_74 , V_4 ) ;
if ( V_11 -> V_13 == NULL )
V_11 -> V_13 = & V_75 ;
if ( V_51 [ V_67 ] ) {
V_56 = F_42 ( & V_11 -> V_68 , NULL ,
& V_11 -> V_69 ,
NULL ,
F_40 ( V_3 ) ,
V_51 [ V_67 ] ) ;
if ( V_56 )
goto V_76;
}
if ( V_11 -> V_13 != & V_75 )
F_43 ( V_11 -> V_13 , true ) ;
F_44 ( V_3 ) ;
F_45 ( & V_6 -> V_9 , & V_11 -> V_10 ) ;
F_46 ( V_3 ) ;
F_47 ( V_3 , & V_6 -> V_9 ) ;
V_70:
F_44 ( V_3 ) ;
V_46 = F_14 ( V_6 , V_27 , V_28 ) ;
if ( V_46 == NULL ) {
F_46 ( V_3 ) ;
V_46 = F_32 ( sizeof( * V_46 ) , V_71 ) ;
if ( V_46 == NULL ) {
V_56 = - V_48 ;
F_48 ( & V_11 -> V_69 ) ;
goto V_76;
}
F_44 ( V_3 ) ;
F_11 ( V_6 , V_46 , V_27 , V_28 ) ;
}
if ( V_53 )
F_30 ( V_6 , V_11 ) ;
F_18 ( V_6 , V_46 , V_11 ) ;
F_46 ( V_3 ) ;
* V_52 = ( unsigned long ) V_11 ;
return 0 ;
V_76:
F_49 ( V_11 -> V_13 ) ;
F_24 ( V_11 ) ;
return V_56 ;
}
static void F_50 ( struct V_2 * V_3 , struct V_1 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
F_29 ( V_6 , V_11 ) ;
F_48 ( & V_11 -> V_69 ) ;
F_49 ( V_11 -> V_13 ) ;
F_24 ( V_11 ) ;
}
static int F_51 ( struct V_2 * V_3 , unsigned long V_52 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 = (struct V_1 * ) V_52 ;
if ( V_11 -> V_77 > 0 )
return - V_78 ;
F_44 ( V_3 ) ;
F_5 ( V_11 ) ;
F_52 ( & V_6 -> V_9 , & V_11 -> V_10 ) ;
F_46 ( V_3 ) ;
F_50 ( V_3 , V_11 ) ;
return 0 ;
}
static unsigned long F_53 ( struct V_2 * V_3 , T_1 V_4 )
{
return ( unsigned long ) F_1 ( V_3 , V_4 ) ;
}
static struct V_79 * F_54 ( struct V_2 * V_3 , unsigned long V_11 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
if ( V_11 )
return NULL ;
return V_6 -> V_80 ;
}
static unsigned long F_55 ( struct V_2 * V_3 , unsigned long V_81 ,
T_1 V_4 )
{
struct V_1 * V_11 = F_1 ( V_3 , V_4 ) ;
if ( V_11 != NULL )
V_11 -> V_77 ++ ;
return ( unsigned long ) V_11 ;
}
static void F_56 ( struct V_2 * V_3 , unsigned long V_52 )
{
struct V_1 * V_11 = (struct V_1 * ) V_52 ;
V_11 -> V_77 -- ;
}
static int F_57 ( struct V_2 * V_3 , unsigned long V_52 ,
struct V_2 * V_82 , struct V_2 * * V_83 )
{
struct V_1 * V_11 = (struct V_1 * ) V_52 ;
if ( V_82 == NULL ) {
V_82 = F_41 ( V_3 -> V_73 ,
& V_74 , V_11 -> V_10 . V_4 ) ;
if ( V_82 == NULL )
V_82 = & V_75 ;
}
* V_83 = F_58 ( V_3 , V_82 , & V_11 -> V_13 ) ;
return 0 ;
}
static struct V_2 * F_59 ( struct V_2 * V_3 , unsigned long V_52 )
{
struct V_1 * V_11 = (struct V_1 * ) V_52 ;
return V_11 -> V_13 ;
}
static int F_60 ( struct V_2 * V_3 , unsigned long V_52 ,
struct V_84 * V_85 , struct V_86 * V_87 )
{
struct V_1 * V_11 = (struct V_1 * ) V_52 ;
struct V_50 * V_88 ;
V_87 -> V_89 = V_90 ;
V_87 -> V_91 = V_11 -> V_10 . V_4 ;
V_87 -> V_92 = V_11 -> V_13 -> V_93 ;
V_88 = F_61 ( V_85 , V_58 ) ;
if ( V_88 == NULL )
goto V_94;
if ( F_62 ( V_85 , V_61 , V_11 -> V_26 -> V_32 ) ||
F_62 ( V_85 , V_63 , V_11 -> V_26 -> V_27 ) )
goto V_94;
return F_63 ( V_85 , V_88 ) ;
V_94:
F_64 ( V_85 , V_88 ) ;
return - V_95 ;
}
static int F_65 ( struct V_2 * V_3 , unsigned long V_52 ,
struct V_96 * V_97 )
{
struct V_1 * V_11 = (struct V_1 * ) V_52 ;
struct V_98 V_99 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
V_99 . V_28 = V_11 -> V_26 -> V_32 ;
V_99 . V_27 = V_11 -> V_26 -> V_27 ;
if ( F_66 ( F_40 ( V_3 ) ,
V_97 , NULL , & V_11 -> V_68 ) < 0 ||
F_67 ( V_97 , & V_11 -> V_69 ) < 0 ||
F_68 ( V_97 , NULL ,
& V_11 -> V_13 -> V_16 , V_11 -> V_13 -> V_6 . V_14 ) < 0 )
return - 1 ;
return F_69 ( V_97 , & V_99 , sizeof( V_99 ) ) ;
}
static void F_70 ( struct V_2 * V_3 , struct V_100 * V_52 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
unsigned int V_39 ;
if ( V_52 -> V_101 )
return;
for ( V_39 = 0 ; V_39 < V_6 -> V_9 . V_102 ; V_39 ++ ) {
F_15 (cl, &q->clhash.hash[i], common.hnode) {
if ( V_52 -> V_103 < V_52 -> V_104 ) {
V_52 -> V_103 ++ ;
continue;
}
if ( V_52 -> V_105 ( V_3 , ( unsigned long ) V_11 , V_52 ) < 0 ) {
V_52 -> V_101 = 1 ;
return;
}
V_52 -> V_103 ++ ;
}
}
}
static struct V_1 * F_71 ( struct V_84 * V_85 , struct V_2 * V_3 ,
int * V_106 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_107 V_108 ;
struct V_109 * V_110 ;
int V_111 ;
if ( F_72 ( V_85 -> V_112 ^ V_3 -> V_93 ) == 0 ) {
F_10 ( L_6 , V_85 -> V_112 ) ;
V_11 = F_1 ( V_3 , V_85 -> V_112 ) ;
if ( V_11 != NULL )
return V_11 ;
}
* V_106 = V_113 | V_114 ;
V_110 = F_73 ( V_6 -> V_115 ) ;
V_111 = F_74 ( V_85 , V_110 , & V_108 , false ) ;
if ( V_111 >= 0 ) {
#ifdef F_75
switch ( V_111 ) {
case V_116 :
case V_117 :
case V_118 :
* V_106 = V_113 | V_119 ;
case V_120 :
return NULL ;
}
#endif
V_11 = (struct V_1 * ) V_108 . V_121 ;
if ( V_11 == NULL )
V_11 = F_1 ( V_3 , V_108 . V_4 ) ;
return V_11 ;
}
return NULL ;
}
static inline int F_76 ( T_2 V_122 , T_2 V_123 )
{
return ( V_124 ) ( V_122 - V_123 ) > 0 ;
}
static inline T_2 F_77 ( T_2 V_125 , unsigned int V_126 )
{
return V_125 & ~ ( ( 1ULL << V_126 ) - 1 ) ;
}
static inline struct V_127 * F_78 ( struct V_5 * V_6 ,
unsigned long V_128 )
{
int V_22 = F_79 ( V_128 ) ;
return & V_6 -> V_40 [ V_22 ] ;
}
static inline unsigned long F_80 ( unsigned long V_128 , int V_129 )
{
return V_128 & ~ ( ( 1UL << V_129 ) - 1 ) ;
}
static int F_81 ( struct V_5 * V_6 , const struct V_127 * V_38 )
{
unsigned int V_130 = F_76 ( V_38 -> V_131 , V_6 -> V_132 ) ;
unsigned long V_133 = F_80 ( V_6 -> V_134 [ V_135 ] , V_38 -> V_22 ) ;
struct V_127 * V_136 ;
if ( V_133 ) {
V_136 = F_78 ( V_6 , V_133 ) ;
if ( F_76 ( V_38 -> V_137 , V_136 -> V_137 ) )
V_130 |= V_138 ;
}
return V_130 ;
}
static inline void F_82 ( struct V_5 * V_6 , unsigned long V_133 ,
int V_139 , int V_140 )
{
V_6 -> V_134 [ V_140 ] |= V_6 -> V_134 [ V_139 ] & V_133 ;
V_6 -> V_134 [ V_139 ] &= ~ V_133 ;
}
static void F_83 ( struct V_5 * V_6 , int V_22 , T_2 V_141 )
{
unsigned long V_133 = F_80 ( V_6 -> V_134 [ V_135 ] , V_22 + 1 ) ;
struct V_127 * V_136 ;
if ( V_133 ) {
V_136 = F_78 ( V_6 , V_133 ) ;
if ( ! F_76 ( V_136 -> V_137 , V_141 ) )
return;
}
V_133 = ( 1UL << V_22 ) - 1 ;
F_82 ( V_6 , V_133 , V_138 , V_135 ) ;
F_82 ( V_6 , V_133 , V_142 , V_143 ) ;
}
static void F_84 ( struct V_5 * V_6 )
{
unsigned long V_144 = V_6 -> V_132 >> V_6 -> V_19 ;
unsigned long V_145 = V_6 -> V_146 >> V_6 -> V_19 ;
if ( V_144 != V_145 ) {
unsigned long V_133 ;
int V_147 = F_85 ( V_144 ^ V_145 ) ;
if ( V_147 > 31 )
V_133 = ~ 0UL ;
else
V_133 = ( 1UL << V_147 ) - 1 ;
F_82 ( V_6 , V_133 , V_143 , V_135 ) ;
F_82 ( V_6 , V_133 , V_142 , V_138 ) ;
}
}
static void F_86 ( struct V_127 * V_38 , struct V_25 * V_26 ,
T_2 V_148 )
{
T_2 V_149 = ( V_148 - V_38 -> V_131 ) >> V_38 -> V_150 ;
unsigned int V_39 ;
if ( F_87 ( V_149 > V_151 - 2 ) ) {
T_2 V_152 = V_148 - V_38 -> V_131 -
( ( T_2 ) ( V_151 - 2 ) << V_38 -> V_150 ) ;
V_26 -> V_131 -= V_152 ;
V_26 -> V_137 -= V_152 ;
V_149 = V_151 - 2 ;
}
V_39 = ( V_38 -> V_153 + V_149 ) % V_151 ;
F_13 ( & V_26 -> V_136 , & V_38 -> V_154 [ V_39 ] ) ;
F_88 ( V_149 , & V_38 -> V_155 ) ;
}
static struct V_25 * F_89 ( struct V_127 * V_38 )
{
return F_90 ( V_38 -> V_154 [ V_38 -> V_153 ] . V_156 ,
struct V_25 , V_136 ) ;
}
static void F_91 ( struct V_127 * V_38 )
{
struct V_25 * V_26 = F_89 ( V_38 ) ;
F_92 ( ! V_26 ) ;
F_93 ( & V_26 -> V_136 ) ;
if ( F_94 ( & V_38 -> V_154 [ V_38 -> V_153 ] ) )
F_95 ( 0 , & V_38 -> V_155 ) ;
}
static struct V_25 * F_96 ( struct V_127 * V_38 )
{
unsigned int V_39 ;
F_10 ( L_7 ,
V_38 -> V_22 , V_38 -> V_155 ) ;
if ( V_38 -> V_155 == 0 )
return NULL ;
V_39 = F_79 ( V_38 -> V_155 ) ;
if ( V_39 > 0 ) {
V_38 -> V_153 = ( V_38 -> V_153 + V_39 ) % V_151 ;
V_38 -> V_155 >>= V_39 ;
}
return F_89 ( V_38 ) ;
}
static void F_97 ( struct V_127 * V_38 , T_2 V_148 )
{
unsigned int V_39 = ( V_38 -> V_131 - V_148 ) >> V_38 -> V_150 ;
V_38 -> V_155 <<= V_39 ;
V_38 -> V_153 = ( V_38 -> V_153 - V_39 ) % V_151 ;
}
static void F_98 ( struct V_5 * V_6 )
{
struct V_127 * V_38 ;
unsigned long V_157 ;
V_157 = V_6 -> V_134 [ V_143 ] | V_6 -> V_134 [ V_142 ] ;
if ( V_157 ) {
if ( ! V_6 -> V_134 [ V_135 ] ) {
V_38 = F_78 ( V_6 , V_157 ) ;
if ( F_76 ( V_38 -> V_131 , V_6 -> V_132 ) )
V_6 -> V_132 = V_38 -> V_131 ;
}
F_84 ( V_6 ) ;
}
}
static void F_99 ( struct V_25 * V_26 ,
struct V_1 * V_11 , unsigned int V_12 )
{
F_100 ( V_11 -> V_13 ) ;
V_11 -> V_72 -= ( int ) V_12 ;
if ( V_11 -> V_13 -> V_6 . V_14 == 0 )
F_26 ( & V_11 -> V_43 ) ;
else if ( V_11 -> V_72 < F_101 ( V_11 -> V_13 -> V_158 -> V_159 ( V_11 -> V_13 ) ) ) {
V_11 -> V_72 += V_26 -> V_27 ;
F_102 ( & V_11 -> V_43 , & V_26 -> V_29 ) ;
}
}
static inline struct V_84 * F_103 ( struct V_25 * V_26 ,
struct V_1 * * V_11 ,
unsigned int * V_12 )
{
struct V_84 * V_85 ;
* V_11 = F_20 ( & V_26 -> V_29 , struct V_1 , V_43 ) ;
V_85 = ( * V_11 ) -> V_13 -> V_158 -> V_159 ( ( * V_11 ) -> V_13 ) ;
if ( V_85 == NULL )
F_104 ( 1 , L_8 ) ;
else
* V_12 = F_101 ( V_85 ) ;
return V_85 ;
}
static inline void F_105 ( struct V_25 * V_26 )
{
T_1 V_160 = F_106 ( V_26 -> V_37 ,
V_26 -> V_161 - V_26 -> V_162 ) ;
V_26 -> V_137 = V_26 -> V_131 + ( T_2 ) V_160 * V_26 -> V_17 ;
}
static void F_107 ( struct V_5 * V_6 , struct V_25 * V_26 )
{
unsigned long V_133 ;
T_2 V_163 , V_164 ;
int V_150 = V_26 -> V_38 -> V_150 ;
V_164 = F_77 ( V_26 -> V_137 , V_150 ) ;
V_163 = F_77 ( V_6 -> V_132 , V_150 ) + ( 1ULL << V_150 ) ;
if ( ! F_76 ( V_26 -> V_137 , V_6 -> V_132 ) || F_76 ( V_164 , V_163 ) ) {
V_133 = F_80 ( V_6 -> V_134 [ V_135 ] , V_26 -> V_38 -> V_22 ) ;
if ( V_133 ) {
struct V_127 * V_136 = F_78 ( V_6 , V_133 ) ;
if ( F_76 ( V_164 , V_136 -> V_137 ) ) {
if ( F_76 ( V_163 , V_136 -> V_137 ) )
V_26 -> V_131 = V_136 -> V_137 ;
else
V_26 -> V_131 = V_163 ;
return;
}
}
V_26 -> V_131 = V_6 -> V_132 ;
} else
V_26 -> V_131 = V_26 -> V_137 ;
}
static inline void
F_108 ( struct V_5 * V_6 ,
struct V_25 * V_26 , enum V_165 V_166 )
{
if ( V_166 != V_167 )
F_107 ( V_6 , V_26 ) ;
else
V_26 -> V_131 = V_26 -> V_137 ;
V_26 -> V_137 = V_26 -> V_131 + ( T_2 ) V_26 -> V_37 * V_26 -> V_17 ;
}
static struct V_84 * F_109 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_25 * V_44 = V_6 -> V_44 ;
struct V_1 * V_11 ;
struct V_84 * V_85 = NULL ;
unsigned int V_12 = 0 ;
if ( V_44 == NULL )
return NULL ;
if ( ! F_27 ( & V_44 -> V_29 ) )
V_85 = F_103 ( V_44 , & V_11 , & V_12 ) ;
if ( V_12 == 0 || V_44 -> V_162 < V_12 ) {
F_105 ( V_44 ) ;
V_44 -> V_161 = V_44 -> V_162 =
V_44 -> V_37 ;
if ( ! F_27 ( & V_44 -> V_29 ) ) {
F_108 ( V_6 , V_44 , V_167 ) ;
F_110 ( V_6 , V_44 ) ;
} else if ( V_3 -> V_6 . V_14 == 0 ) {
V_6 -> V_44 = NULL ;
return NULL ;
}
V_44 = V_6 -> V_44 = F_23 ( V_6 ) ;
V_85 = F_103 ( V_44 , & V_11 , & V_12 ) ;
}
if ( ! V_85 )
return NULL ;
F_111 ( V_3 , V_85 ) ;
V_3 -> V_6 . V_14 -- ;
F_112 ( V_3 , V_85 ) ;
F_99 ( V_44 , V_11 , V_12 ) ;
if ( F_87 ( V_44 -> V_162 < V_12 ) )
V_44 -> V_162 = 0 ;
else
V_44 -> V_162 -= V_12 ;
V_6 -> V_132 += ( T_2 ) V_12 * V_6 -> V_42 ;
F_10 ( L_9 ,
V_12 , ( unsigned long long ) V_44 -> V_137 ,
( unsigned long long ) V_6 -> V_132 ) ;
return V_85 ;
}
static struct V_25 * F_23 ( struct V_5 * V_6 )
{
struct V_127 * V_38 ;
struct V_25 * V_26 , * V_168 ;
T_2 V_141 ;
F_98 ( V_6 ) ;
V_6 -> V_146 = V_6 -> V_132 ;
if ( ! V_6 -> V_134 [ V_135 ] )
return NULL ;
V_38 = F_78 ( V_6 , V_6 -> V_134 [ V_135 ] ) ;
V_141 = V_38 -> V_137 ;
V_26 = F_89 ( V_38 ) ;
F_91 ( V_38 ) ;
V_168 = F_96 ( V_38 ) ;
if ( V_168 == NULL )
F_95 ( V_38 -> V_22 , & V_6 -> V_134 [ V_135 ] ) ;
else {
T_2 V_148 = F_77 ( V_168 -> V_131 ,
V_38 -> V_150 ) ;
unsigned int V_169 ;
if ( V_38 -> V_131 == V_148 )
return V_26 ;
V_38 -> V_131 = V_148 ;
V_38 -> V_137 = V_148 + ( 2ULL << V_38 -> V_150 ) ;
F_95 ( V_38 -> V_22 , & V_6 -> V_134 [ V_135 ] ) ;
V_169 = F_81 ( V_6 , V_38 ) ;
F_88 ( V_38 -> V_22 , & V_6 -> V_134 [ V_169 ] ) ;
}
F_83 ( V_6 , V_38 -> V_22 , V_141 ) ;
return V_26 ;
}
static int F_113 ( struct V_84 * V_85 , struct V_2 * V_3 ,
struct V_84 * * V_170 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_25 * V_26 ;
int V_56 = 0 ;
V_11 = F_71 ( V_85 , V_3 , & V_56 ) ;
if ( V_11 == NULL ) {
if ( V_56 & V_114 )
F_114 ( V_3 ) ;
F_115 ( V_85 , V_170 ) ;
return V_56 ;
}
F_10 ( L_10 , V_11 -> V_10 . V_4 ) ;
if ( F_87 ( V_11 -> V_26 -> V_27 < F_101 ( V_85 ) ) ) {
F_10 ( L_11 ,
V_11 -> V_26 -> V_27 , F_101 ( V_85 ) , V_11 -> V_10 . V_4 ) ;
V_56 = F_31 ( V_3 , V_11 , V_11 -> V_26 -> V_32 ,
F_101 ( V_85 ) ) ;
if ( V_56 ) {
V_11 -> V_16 . V_171 ++ ;
return F_116 ( V_85 , V_3 , V_170 ) ;
}
}
V_56 = F_117 ( V_85 , V_11 -> V_13 , V_170 ) ;
if ( F_87 ( V_56 != V_113 ) ) {
F_10 ( L_12 , V_56 ) ;
if ( F_118 ( V_56 ) ) {
V_11 -> V_16 . V_171 ++ ;
F_114 ( V_3 ) ;
}
return V_56 ;
}
F_119 ( & V_11 -> V_68 , V_85 ) ;
F_120 ( V_3 , V_85 ) ;
++ V_3 -> V_6 . V_14 ;
V_26 = V_11 -> V_26 ;
if ( V_11 -> V_13 -> V_6 . V_14 != 1 ) {
if ( F_87 ( V_85 == V_11 -> V_13 -> V_158 -> V_159 ( V_11 -> V_13 ) ) &&
F_20 ( & V_26 -> V_29 , struct V_1 , V_43 )
== V_11 && V_11 -> V_72 < F_101 ( V_85 ) )
F_102 ( & V_11 -> V_43 , & V_26 -> V_29 ) ;
return V_56 ;
}
V_11 -> V_72 = V_26 -> V_27 ;
F_19 ( & V_11 -> V_43 , & V_26 -> V_29 ) ;
if ( F_20 ( & V_26 -> V_29 , struct V_1 , V_43 ) != V_11 ||
V_6 -> V_44 == V_26 )
return V_56 ;
F_21 ( V_6 , V_26 , V_45 ) ;
return V_56 ;
}
static void F_110 ( struct V_5 * V_6 , struct V_25 * V_26 )
{
struct V_127 * V_38 = V_26 -> V_38 ;
T_2 V_148 ;
int V_169 ;
V_148 = F_77 ( V_26 -> V_131 , V_38 -> V_150 ) ;
if ( V_38 -> V_155 ) {
if ( ! F_76 ( V_38 -> V_131 , V_26 -> V_131 ) )
goto V_172;
F_97 ( V_38 , V_148 ) ;
F_95 ( V_38 -> V_22 , & V_6 -> V_134 [ V_143 ] ) ;
F_95 ( V_38 -> V_22 , & V_6 -> V_134 [ V_142 ] ) ;
} else if ( ! V_6 -> V_134 [ V_135 ] && F_76 ( V_148 , V_6 -> V_132 ) &&
V_6 -> V_44 == NULL )
V_6 -> V_132 = V_148 ;
V_38 -> V_131 = V_148 ;
V_38 -> V_137 = V_148 + ( 2ULL << V_38 -> V_150 ) ;
V_169 = F_81 ( V_6 , V_38 ) ;
F_88 ( V_38 -> V_22 , & V_6 -> V_134 [ V_169 ] ) ;
F_10 ( L_13 ,
V_169 , V_6 -> V_134 [ V_169 ] ,
( unsigned long long ) V_26 -> V_131 ,
( unsigned long long ) V_26 -> V_137 ,
( unsigned long long ) V_6 -> V_132 ) ;
V_172:
F_86 ( V_38 , V_26 , V_148 ) ;
}
static void F_21 ( struct V_5 * V_6 , struct V_25 * V_26 ,
enum V_165 V_166 )
{
V_26 -> V_161 = V_26 -> V_162 = V_26 -> V_37 ;
F_108 ( V_6 , V_26 , V_166 ) ;
if ( V_6 -> V_44 == NULL ) {
V_6 -> V_44 = V_26 ;
V_6 -> V_146 = V_6 -> V_132 = V_26 -> V_131 ;
} else if ( V_26 != V_6 -> V_44 )
F_110 ( V_6 , V_26 ) ;
}
static void F_121 ( struct V_5 * V_6 , struct V_127 * V_38 ,
struct V_25 * V_26 )
{
unsigned int V_39 , V_173 ;
T_2 V_148 ;
V_148 = F_77 ( V_26 -> V_131 , V_38 -> V_150 ) ;
V_173 = ( V_148 - V_38 -> V_131 ) >> V_38 -> V_150 ;
V_39 = ( V_38 -> V_153 + V_173 ) % V_151 ;
F_93 ( & V_26 -> V_136 ) ;
if ( F_94 ( & V_38 -> V_154 [ V_39 ] ) )
F_95 ( V_173 , & V_38 -> V_155 ) ;
}
static void F_28 ( struct V_5 * V_6 , struct V_25 * V_26 )
{
struct V_127 * V_38 = V_26 -> V_38 ;
unsigned long V_133 ;
T_2 V_148 ;
int V_169 ;
if ( V_26 == V_6 -> V_44 ) {
F_105 ( V_26 ) ;
V_6 -> V_44 = F_23 ( V_6 ) ;
return;
}
V_26 -> V_137 = V_26 -> V_131 ;
F_121 ( V_6 , V_38 , V_26 ) ;
if ( ! V_38 -> V_155 ) {
F_95 ( V_38 -> V_22 , & V_6 -> V_134 [ V_143 ] ) ;
F_95 ( V_38 -> V_22 , & V_6 -> V_134 [ V_138 ] ) ;
F_95 ( V_38 -> V_22 , & V_6 -> V_134 [ V_142 ] ) ;
if ( F_122 ( V_38 -> V_22 , & V_6 -> V_134 [ V_135 ] ) &&
! ( V_6 -> V_134 [ V_135 ] & ~ ( ( 1UL << V_38 -> V_22 ) - 1 ) ) ) {
V_133 = V_6 -> V_134 [ V_135 ] & ( ( 1UL << V_38 -> V_22 ) - 1 ) ;
if ( V_133 )
V_133 = ~ ( ( 1UL << F_9 ( V_133 ) ) - 1 ) ;
else
V_133 = ~ 0UL ;
F_82 ( V_6 , V_133 , V_138 , V_135 ) ;
F_82 ( V_6 , V_133 , V_142 , V_143 ) ;
}
F_95 ( V_38 -> V_22 , & V_6 -> V_134 [ V_135 ] ) ;
} else if ( F_94 ( & V_38 -> V_154 [ V_38 -> V_153 ] ) ) {
V_26 = F_96 ( V_38 ) ;
V_148 = F_77 ( V_26 -> V_131 , V_38 -> V_150 ) ;
if ( V_38 -> V_131 != V_148 ) {
F_95 ( V_38 -> V_22 , & V_6 -> V_134 [ V_135 ] ) ;
F_95 ( V_38 -> V_22 , & V_6 -> V_134 [ V_143 ] ) ;
F_95 ( V_38 -> V_22 , & V_6 -> V_134 [ V_138 ] ) ;
F_95 ( V_38 -> V_22 , & V_6 -> V_134 [ V_142 ] ) ;
V_38 -> V_131 = V_148 ;
V_38 -> V_137 = V_148 + ( 2ULL << V_38 -> V_150 ) ;
V_169 = F_81 ( V_6 , V_38 ) ;
F_88 ( V_38 -> V_22 , & V_6 -> V_134 [ V_169 ] ) ;
}
}
}
static void F_123 ( struct V_2 * V_3 , unsigned long V_52 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 = (struct V_1 * ) V_52 ;
F_25 ( V_6 , V_11 ) ;
}
static int F_124 ( struct V_2 * V_3 , struct V_50 * V_174 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_127 * V_38 ;
int V_39 , V_175 , V_56 ;
T_1 V_176 , V_177 , V_178 ;
V_56 = F_125 ( & V_6 -> V_80 , & V_6 -> V_115 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_126 ( & V_6 -> V_9 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( F_38 ( V_3 ) -> V_179 + 1 > V_180 )
V_178 = V_180 ;
else
V_178 = F_38 ( V_3 ) -> V_179 + 1 ;
V_176 = F_9 ( V_178 ) ;
V_6 -> V_35 = 1 << V_176 ;
V_177 = V_65 + V_176 ;
V_6 -> V_19 = V_181 + V_177 - V_182 ;
for ( V_39 = 0 ; V_39 <= V_182 ; V_39 ++ ) {
V_38 = & V_6 -> V_40 [ V_39 ] ;
V_38 -> V_22 = V_39 ;
V_38 -> V_150 = V_6 -> V_19 + V_39 ;
for ( V_175 = 0 ; V_175 < V_151 ; V_175 ++ )
F_127 ( & V_38 -> V_154 [ V_175 ] ) ;
}
F_127 ( & V_6 -> V_31 ) ;
return 0 ;
}
static void F_128 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
unsigned int V_39 ;
for ( V_39 = 0 ; V_39 < V_6 -> V_9 . V_102 ; V_39 ++ ) {
F_15 (cl, &q->clhash.hash[i], common.hnode) {
if ( V_11 -> V_13 -> V_6 . V_14 > 0 )
F_25 ( V_6 , V_11 ) ;
F_6 ( V_11 -> V_13 ) ;
}
}
V_3 -> V_16 . V_15 = 0 ;
V_3 -> V_6 . V_14 = 0 ;
}
static void F_129 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_183 * V_136 ;
unsigned int V_39 ;
F_130 ( V_6 -> V_80 ) ;
for ( V_39 = 0 ; V_39 < V_6 -> V_9 . V_102 ; V_39 ++ ) {
F_131 (cl, next, &q->clhash.hash[i],
common.hnode) {
F_50 ( V_3 , V_11 ) ;
}
}
F_132 ( & V_6 -> V_9 ) ;
}
static int T_3 F_133 ( void )
{
return F_134 ( & V_184 ) ;
}
static void T_4 F_135 ( void )
{
F_136 ( & V_184 ) ;
}
