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
V_56 = F_35 ( V_54 , V_55 , V_51 [ V_58 ] , V_60 ) ;
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
V_11 -> V_72 = 1 ;
V_11 -> V_10 . V_4 = V_4 ;
V_11 -> V_73 = V_27 ;
V_11 -> V_13 = F_41 ( V_3 -> V_74 ,
& V_75 , V_4 ) ;
if ( V_11 -> V_13 == NULL )
V_11 -> V_13 = & V_76 ;
if ( V_51 [ V_67 ] ) {
V_56 = F_42 ( & V_11 -> V_68 , NULL ,
& V_11 -> V_69 ,
F_40 ( V_3 ) ,
V_51 [ V_67 ] ) ;
if ( V_56 )
goto V_77;
}
F_43 ( V_3 ) ;
F_44 ( & V_6 -> V_9 , & V_11 -> V_10 ) ;
F_45 ( V_3 ) ;
F_46 ( V_3 , & V_6 -> V_9 ) ;
V_70:
F_43 ( V_3 ) ;
V_46 = F_14 ( V_6 , V_27 , V_28 ) ;
if ( V_46 == NULL ) {
F_45 ( V_3 ) ;
V_46 = F_32 ( sizeof( * V_46 ) , V_71 ) ;
if ( V_46 == NULL ) {
V_56 = - V_48 ;
F_47 ( & V_11 -> V_68 , & V_11 -> V_69 ) ;
goto V_77;
}
F_43 ( V_3 ) ;
F_11 ( V_6 , V_46 , V_27 , V_28 ) ;
}
if ( V_53 )
F_30 ( V_6 , V_11 ) ;
F_18 ( V_6 , V_46 , V_11 ) ;
F_45 ( V_3 ) ;
* V_52 = ( unsigned long ) V_11 ;
return 0 ;
V_77:
F_48 ( V_11 -> V_13 ) ;
F_24 ( V_11 ) ;
return V_56 ;
}
static void F_49 ( struct V_2 * V_3 , struct V_1 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
F_29 ( V_6 , V_11 ) ;
F_47 ( & V_11 -> V_68 , & V_11 -> V_69 ) ;
F_48 ( V_11 -> V_13 ) ;
F_24 ( V_11 ) ;
}
static int F_50 ( struct V_2 * V_3 , unsigned long V_52 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 = (struct V_1 * ) V_52 ;
if ( V_11 -> V_78 > 0 )
return - V_79 ;
F_43 ( V_3 ) ;
F_5 ( V_11 ) ;
F_51 ( & V_6 -> V_9 , & V_11 -> V_10 ) ;
F_52 ( -- V_11 -> V_72 == 0 ) ;
F_45 ( V_3 ) ;
return 0 ;
}
static unsigned long F_53 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_11 = F_1 ( V_3 , V_4 ) ;
if ( V_11 != NULL )
V_11 -> V_72 ++ ;
return ( unsigned long ) V_11 ;
}
static void F_54 ( struct V_2 * V_3 , unsigned long V_52 )
{
struct V_1 * V_11 = (struct V_1 * ) V_52 ;
if ( -- V_11 -> V_72 == 0 )
F_49 ( V_3 , V_11 ) ;
}
static struct V_80 T_3 * * F_55 ( struct V_2 * V_3 ,
unsigned long V_11 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
if ( V_11 )
return NULL ;
return & V_6 -> V_81 ;
}
static unsigned long F_56 ( struct V_2 * V_3 , unsigned long V_82 ,
T_1 V_4 )
{
struct V_1 * V_11 = F_1 ( V_3 , V_4 ) ;
if ( V_11 != NULL )
V_11 -> V_78 ++ ;
return ( unsigned long ) V_11 ;
}
static void F_57 ( struct V_2 * V_3 , unsigned long V_52 )
{
struct V_1 * V_11 = (struct V_1 * ) V_52 ;
V_11 -> V_78 -- ;
}
static int F_58 ( struct V_2 * V_3 , unsigned long V_52 ,
struct V_2 * V_83 , struct V_2 * * V_84 )
{
struct V_1 * V_11 = (struct V_1 * ) V_52 ;
if ( V_83 == NULL ) {
V_83 = F_41 ( V_3 -> V_74 ,
& V_75 , V_11 -> V_10 . V_4 ) ;
if ( V_83 == NULL )
V_83 = & V_76 ;
}
* V_84 = F_59 ( V_3 , V_83 , & V_11 -> V_13 ) ;
return 0 ;
}
static struct V_2 * F_60 ( struct V_2 * V_3 , unsigned long V_52 )
{
struct V_1 * V_11 = (struct V_1 * ) V_52 ;
return V_11 -> V_13 ;
}
static int F_61 ( struct V_2 * V_3 , unsigned long V_52 ,
struct V_85 * V_86 , struct V_87 * V_88 )
{
struct V_1 * V_11 = (struct V_1 * ) V_52 ;
struct V_50 * V_89 ;
V_88 -> V_90 = V_91 ;
V_88 -> V_92 = V_11 -> V_10 . V_4 ;
V_88 -> V_93 = V_11 -> V_13 -> V_94 ;
V_89 = F_62 ( V_86 , V_58 ) ;
if ( V_89 == NULL )
goto V_95;
if ( F_63 ( V_86 , V_61 , V_11 -> V_26 -> V_32 ) ||
F_63 ( V_86 , V_63 , V_11 -> V_26 -> V_27 ) )
goto V_95;
return F_64 ( V_86 , V_89 ) ;
V_95:
F_65 ( V_86 , V_89 ) ;
return - V_96 ;
}
static int F_66 ( struct V_2 * V_3 , unsigned long V_52 ,
struct V_97 * V_98 )
{
struct V_1 * V_11 = (struct V_1 * ) V_52 ;
struct V_99 V_100 ;
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
V_100 . V_28 = V_11 -> V_26 -> V_32 ;
V_100 . V_27 = V_11 -> V_26 -> V_27 ;
if ( F_67 ( V_98 , NULL , & V_11 -> V_68 ) < 0 ||
F_68 ( V_98 , & V_11 -> V_68 , & V_11 -> V_69 ) < 0 ||
F_69 ( V_98 , NULL ,
& V_11 -> V_13 -> V_16 , V_11 -> V_13 -> V_6 . V_14 ) < 0 )
return - 1 ;
return F_70 ( V_98 , & V_100 , sizeof( V_100 ) ) ;
}
static void F_71 ( struct V_2 * V_3 , struct V_101 * V_52 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
unsigned int V_39 ;
if ( V_52 -> V_102 )
return;
for ( V_39 = 0 ; V_39 < V_6 -> V_9 . V_103 ; V_39 ++ ) {
F_15 (cl, &q->clhash.hash[i], common.hnode) {
if ( V_52 -> V_104 < V_52 -> V_105 ) {
V_52 -> V_104 ++ ;
continue;
}
if ( V_52 -> V_106 ( V_3 , ( unsigned long ) V_11 , V_52 ) < 0 ) {
V_52 -> V_102 = 1 ;
return;
}
V_52 -> V_104 ++ ;
}
}
}
static struct V_1 * F_72 ( struct V_85 * V_86 , struct V_2 * V_3 ,
int * V_107 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_108 V_109 ;
struct V_80 * V_110 ;
int V_111 ;
if ( F_73 ( V_86 -> V_112 ^ V_3 -> V_94 ) == 0 ) {
F_10 ( L_6 , V_86 -> V_112 ) ;
V_11 = F_1 ( V_3 , V_86 -> V_112 ) ;
if ( V_11 != NULL )
return V_11 ;
}
* V_107 = V_113 | V_114 ;
V_110 = F_74 ( V_6 -> V_81 ) ;
V_111 = F_75 ( V_86 , V_110 , & V_109 , false ) ;
if ( V_111 >= 0 ) {
#ifdef F_76
switch ( V_111 ) {
case V_115 :
case V_116 :
* V_107 = V_113 | V_117 ;
case V_118 :
return NULL ;
}
#endif
V_11 = (struct V_1 * ) V_109 . V_119 ;
if ( V_11 == NULL )
V_11 = F_1 ( V_3 , V_109 . V_4 ) ;
return V_11 ;
}
return NULL ;
}
static inline int F_77 ( T_2 V_120 , T_2 V_121 )
{
return ( V_122 ) ( V_120 - V_121 ) > 0 ;
}
static inline T_2 F_78 ( T_2 V_123 , unsigned int V_124 )
{
return V_123 & ~ ( ( 1ULL << V_124 ) - 1 ) ;
}
static inline struct V_125 * F_79 ( struct V_5 * V_6 ,
unsigned long V_126 )
{
int V_22 = F_80 ( V_126 ) ;
return & V_6 -> V_40 [ V_22 ] ;
}
static inline unsigned long F_81 ( unsigned long V_126 , int V_127 )
{
return V_126 & ~ ( ( 1UL << V_127 ) - 1 ) ;
}
static int F_82 ( struct V_5 * V_6 , const struct V_125 * V_38 )
{
unsigned int V_128 = F_77 ( V_38 -> V_129 , V_6 -> V_130 ) ;
unsigned long V_131 = F_81 ( V_6 -> V_132 [ V_133 ] , V_38 -> V_22 ) ;
struct V_125 * V_134 ;
if ( V_131 ) {
V_134 = F_79 ( V_6 , V_131 ) ;
if ( F_77 ( V_38 -> V_135 , V_134 -> V_135 ) )
V_128 |= V_136 ;
}
return V_128 ;
}
static inline void F_83 ( struct V_5 * V_6 , unsigned long V_131 ,
int V_137 , int V_138 )
{
V_6 -> V_132 [ V_138 ] |= V_6 -> V_132 [ V_137 ] & V_131 ;
V_6 -> V_132 [ V_137 ] &= ~ V_131 ;
}
static void F_84 ( struct V_5 * V_6 , int V_22 , T_2 V_139 )
{
unsigned long V_131 = F_81 ( V_6 -> V_132 [ V_133 ] , V_22 + 1 ) ;
struct V_125 * V_134 ;
if ( V_131 ) {
V_134 = F_79 ( V_6 , V_131 ) ;
if ( ! F_77 ( V_134 -> V_135 , V_139 ) )
return;
}
V_131 = ( 1UL << V_22 ) - 1 ;
F_83 ( V_6 , V_131 , V_136 , V_133 ) ;
F_83 ( V_6 , V_131 , V_140 , V_141 ) ;
}
static void F_85 ( struct V_5 * V_6 )
{
unsigned long V_142 = V_6 -> V_130 >> V_6 -> V_19 ;
unsigned long V_143 = V_6 -> V_144 >> V_6 -> V_19 ;
if ( V_142 != V_143 ) {
unsigned long V_131 ;
int V_145 = F_86 ( V_142 ^ V_143 ) ;
if ( V_145 > 31 )
V_131 = ~ 0UL ;
else
V_131 = ( 1UL << V_145 ) - 1 ;
F_83 ( V_6 , V_131 , V_141 , V_133 ) ;
F_83 ( V_6 , V_131 , V_140 , V_136 ) ;
}
}
static void F_87 ( struct V_125 * V_38 , struct V_25 * V_26 ,
T_2 V_146 )
{
T_2 V_147 = ( V_146 - V_38 -> V_129 ) >> V_38 -> V_148 ;
unsigned int V_39 ;
if ( F_88 ( V_147 > V_149 - 2 ) ) {
T_2 V_150 = V_146 - V_38 -> V_129 -
( ( T_2 ) ( V_149 - 2 ) << V_38 -> V_148 ) ;
V_26 -> V_129 -= V_150 ;
V_26 -> V_135 -= V_150 ;
V_147 = V_149 - 2 ;
}
V_39 = ( V_38 -> V_151 + V_147 ) % V_149 ;
F_13 ( & V_26 -> V_134 , & V_38 -> V_152 [ V_39 ] ) ;
F_89 ( V_147 , & V_38 -> V_153 ) ;
}
static struct V_25 * F_90 ( struct V_125 * V_38 )
{
return F_91 ( V_38 -> V_152 [ V_38 -> V_151 ] . V_154 ,
struct V_25 , V_134 ) ;
}
static void F_92 ( struct V_125 * V_38 )
{
struct V_25 * V_26 = F_90 ( V_38 ) ;
F_52 ( ! V_26 ) ;
F_93 ( & V_26 -> V_134 ) ;
if ( F_94 ( & V_38 -> V_152 [ V_38 -> V_151 ] ) )
F_95 ( 0 , & V_38 -> V_153 ) ;
}
static struct V_25 * F_96 ( struct V_125 * V_38 )
{
unsigned int V_39 ;
F_10 ( L_7 ,
V_38 -> V_22 , V_38 -> V_153 ) ;
if ( V_38 -> V_153 == 0 )
return NULL ;
V_39 = F_80 ( V_38 -> V_153 ) ;
if ( V_39 > 0 ) {
V_38 -> V_151 = ( V_38 -> V_151 + V_39 ) % V_149 ;
V_38 -> V_153 >>= V_39 ;
}
return F_90 ( V_38 ) ;
}
static void F_97 ( struct V_125 * V_38 , T_2 V_146 )
{
unsigned int V_39 = ( V_38 -> V_129 - V_146 ) >> V_38 -> V_148 ;
V_38 -> V_153 <<= V_39 ;
V_38 -> V_151 = ( V_38 -> V_151 - V_39 ) % V_149 ;
}
static void F_98 ( struct V_5 * V_6 )
{
struct V_125 * V_38 ;
unsigned long V_155 ;
V_155 = V_6 -> V_132 [ V_141 ] | V_6 -> V_132 [ V_140 ] ;
if ( V_155 ) {
if ( ! V_6 -> V_132 [ V_133 ] ) {
V_38 = F_79 ( V_6 , V_155 ) ;
if ( F_77 ( V_38 -> V_129 , V_6 -> V_130 ) )
V_6 -> V_130 = V_38 -> V_129 ;
}
F_85 ( V_6 ) ;
}
}
static void F_99 ( struct V_25 * V_26 ,
struct V_1 * V_11 , unsigned int V_12 )
{
F_100 ( V_11 -> V_13 ) ;
V_11 -> V_73 -= ( int ) V_12 ;
if ( V_11 -> V_13 -> V_6 . V_14 == 0 )
F_26 ( & V_11 -> V_43 ) ;
else if ( V_11 -> V_73 < F_101 ( V_11 -> V_13 -> V_156 -> V_157 ( V_11 -> V_13 ) ) ) {
V_11 -> V_73 += V_26 -> V_27 ;
F_102 ( & V_11 -> V_43 , & V_26 -> V_29 ) ;
}
}
static inline struct V_85 * F_103 ( struct V_25 * V_26 ,
struct V_1 * * V_11 ,
unsigned int * V_12 )
{
struct V_85 * V_86 ;
* V_11 = F_20 ( & V_26 -> V_29 , struct V_1 , V_43 ) ;
V_86 = ( * V_11 ) -> V_13 -> V_156 -> V_157 ( ( * V_11 ) -> V_13 ) ;
if ( V_86 == NULL )
F_104 ( 1 , L_8 ) ;
else
* V_12 = F_101 ( V_86 ) ;
return V_86 ;
}
static inline void F_105 ( struct V_25 * V_26 )
{
T_1 V_158 = F_106 ( V_26 -> V_37 ,
V_26 -> V_159 - V_26 -> V_160 ) ;
V_26 -> V_135 = V_26 -> V_129 + ( T_2 ) V_158 * V_26 -> V_17 ;
}
static void F_107 ( struct V_5 * V_6 , struct V_25 * V_26 )
{
unsigned long V_131 ;
T_2 V_161 , V_162 ;
int V_148 = V_26 -> V_38 -> V_148 ;
V_162 = F_78 ( V_26 -> V_135 , V_148 ) ;
V_161 = F_78 ( V_6 -> V_130 , V_148 ) + ( 1ULL << V_148 ) ;
if ( ! F_77 ( V_26 -> V_135 , V_6 -> V_130 ) || F_77 ( V_162 , V_161 ) ) {
V_131 = F_81 ( V_6 -> V_132 [ V_133 ] , V_26 -> V_38 -> V_22 ) ;
if ( V_131 ) {
struct V_125 * V_134 = F_79 ( V_6 , V_131 ) ;
if ( F_77 ( V_162 , V_134 -> V_135 ) ) {
if ( F_77 ( V_161 , V_134 -> V_135 ) )
V_26 -> V_129 = V_134 -> V_135 ;
else
V_26 -> V_129 = V_161 ;
return;
}
}
V_26 -> V_129 = V_6 -> V_130 ;
} else
V_26 -> V_129 = V_26 -> V_135 ;
}
static inline void
F_108 ( struct V_5 * V_6 ,
struct V_25 * V_26 , enum V_163 V_164 )
{
if ( V_164 != V_165 )
F_107 ( V_6 , V_26 ) ;
else
V_26 -> V_129 = V_26 -> V_135 ;
V_26 -> V_135 = V_26 -> V_129 + ( T_2 ) V_26 -> V_37 * V_26 -> V_17 ;
}
static struct V_85 * F_109 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_25 * V_44 = V_6 -> V_44 ;
struct V_1 * V_11 ;
struct V_85 * V_86 = NULL ;
unsigned int V_12 = 0 ;
if ( V_44 == NULL )
return NULL ;
if ( ! F_27 ( & V_44 -> V_29 ) )
V_86 = F_103 ( V_44 , & V_11 , & V_12 ) ;
if ( V_12 == 0 || V_44 -> V_160 < V_12 ) {
F_105 ( V_44 ) ;
V_44 -> V_159 = V_44 -> V_160 =
V_44 -> V_37 ;
if ( ! F_27 ( & V_44 -> V_29 ) ) {
F_108 ( V_6 , V_44 , V_165 ) ;
F_110 ( V_6 , V_44 ) ;
} else if ( V_3 -> V_6 . V_14 == 0 ) {
V_6 -> V_44 = NULL ;
return NULL ;
}
V_44 = V_6 -> V_44 = F_23 ( V_6 ) ;
V_86 = F_103 ( V_44 , & V_11 , & V_12 ) ;
}
if ( ! V_86 )
return NULL ;
V_3 -> V_6 . V_14 -- ;
F_111 ( V_3 , V_86 ) ;
F_99 ( V_44 , V_11 , V_12 ) ;
if ( F_88 ( V_44 -> V_160 < V_12 ) )
V_44 -> V_160 = 0 ;
else
V_44 -> V_160 -= V_12 ;
V_6 -> V_130 += ( T_2 ) V_12 * V_6 -> V_42 ;
F_10 ( L_9 ,
V_12 , ( unsigned long long ) V_44 -> V_135 ,
( unsigned long long ) V_6 -> V_130 ) ;
return V_86 ;
}
static struct V_25 * F_23 ( struct V_5 * V_6 )
{
struct V_125 * V_38 ;
struct V_25 * V_26 , * V_166 ;
T_2 V_139 ;
F_98 ( V_6 ) ;
V_6 -> V_144 = V_6 -> V_130 ;
if ( ! V_6 -> V_132 [ V_133 ] )
return NULL ;
V_38 = F_79 ( V_6 , V_6 -> V_132 [ V_133 ] ) ;
V_139 = V_38 -> V_135 ;
V_26 = F_90 ( V_38 ) ;
F_92 ( V_38 ) ;
V_166 = F_96 ( V_38 ) ;
if ( V_166 == NULL )
F_95 ( V_38 -> V_22 , & V_6 -> V_132 [ V_133 ] ) ;
else {
T_2 V_146 = F_78 ( V_166 -> V_129 ,
V_38 -> V_148 ) ;
unsigned int V_167 ;
if ( V_38 -> V_129 == V_146 )
return V_26 ;
V_38 -> V_129 = V_146 ;
V_38 -> V_135 = V_146 + ( 2ULL << V_38 -> V_148 ) ;
F_95 ( V_38 -> V_22 , & V_6 -> V_132 [ V_133 ] ) ;
V_167 = F_82 ( V_6 , V_38 ) ;
F_89 ( V_38 -> V_22 , & V_6 -> V_132 [ V_167 ] ) ;
}
F_84 ( V_6 , V_38 -> V_22 , V_139 ) ;
return V_26 ;
}
static int F_112 ( struct V_85 * V_86 , struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_25 * V_26 ;
int V_56 = 0 ;
V_11 = F_72 ( V_86 , V_3 , & V_56 ) ;
if ( V_11 == NULL ) {
if ( V_56 & V_114 )
F_113 ( V_3 ) ;
F_114 ( V_86 ) ;
return V_56 ;
}
F_10 ( L_10 , V_11 -> V_10 . V_4 ) ;
if ( F_88 ( V_11 -> V_26 -> V_27 < F_101 ( V_86 ) ) ) {
F_10 ( L_11 ,
V_11 -> V_26 -> V_27 , F_101 ( V_86 ) , V_11 -> V_10 . V_4 ) ;
V_56 = F_31 ( V_3 , V_11 , V_11 -> V_26 -> V_32 ,
F_101 ( V_86 ) ) ;
if ( V_56 )
return V_56 ;
}
V_56 = F_115 ( V_86 , V_11 -> V_13 ) ;
if ( F_88 ( V_56 != V_113 ) ) {
F_10 ( L_12 , V_56 ) ;
if ( F_116 ( V_56 ) ) {
V_11 -> V_16 . V_168 ++ ;
F_113 ( V_3 ) ;
}
return V_56 ;
}
F_117 ( & V_11 -> V_68 , V_86 ) ;
++ V_3 -> V_6 . V_14 ;
V_26 = V_11 -> V_26 ;
if ( V_11 -> V_13 -> V_6 . V_14 != 1 ) {
if ( F_88 ( V_86 == V_11 -> V_13 -> V_156 -> V_157 ( V_11 -> V_13 ) ) &&
F_20 ( & V_26 -> V_29 , struct V_1 , V_43 )
== V_11 && V_11 -> V_73 < F_101 ( V_86 ) )
F_102 ( & V_11 -> V_43 , & V_26 -> V_29 ) ;
return V_56 ;
}
V_11 -> V_73 = V_26 -> V_27 ;
F_19 ( & V_11 -> V_43 , & V_26 -> V_29 ) ;
if ( F_20 ( & V_26 -> V_29 , struct V_1 , V_43 ) != V_11 ||
V_6 -> V_44 == V_26 )
return V_56 ;
F_21 ( V_6 , V_26 , V_45 ) ;
return V_56 ;
}
static void F_110 ( struct V_5 * V_6 , struct V_25 * V_26 )
{
struct V_125 * V_38 = V_26 -> V_38 ;
T_2 V_146 ;
int V_167 ;
V_146 = F_78 ( V_26 -> V_129 , V_38 -> V_148 ) ;
if ( V_38 -> V_153 ) {
if ( ! F_77 ( V_38 -> V_129 , V_26 -> V_129 ) )
goto V_169;
F_97 ( V_38 , V_146 ) ;
F_95 ( V_38 -> V_22 , & V_6 -> V_132 [ V_141 ] ) ;
F_95 ( V_38 -> V_22 , & V_6 -> V_132 [ V_140 ] ) ;
} else if ( ! V_6 -> V_132 [ V_133 ] && F_77 ( V_146 , V_6 -> V_130 ) &&
V_6 -> V_44 == NULL )
V_6 -> V_130 = V_146 ;
V_38 -> V_129 = V_146 ;
V_38 -> V_135 = V_146 + ( 2ULL << V_38 -> V_148 ) ;
V_167 = F_82 ( V_6 , V_38 ) ;
F_89 ( V_38 -> V_22 , & V_6 -> V_132 [ V_167 ] ) ;
F_10 ( L_13 ,
V_167 , V_6 -> V_132 [ V_167 ] ,
( unsigned long long ) V_26 -> V_129 ,
( unsigned long long ) V_26 -> V_135 ,
( unsigned long long ) V_6 -> V_130 ) ;
V_169:
F_87 ( V_38 , V_26 , V_146 ) ;
}
static void F_21 ( struct V_5 * V_6 , struct V_25 * V_26 ,
enum V_163 V_164 )
{
V_26 -> V_159 = V_26 -> V_160 = V_26 -> V_37 ;
F_108 ( V_6 , V_26 , V_164 ) ;
if ( V_6 -> V_44 == NULL ) {
V_6 -> V_44 = V_26 ;
V_6 -> V_144 = V_6 -> V_130 = V_26 -> V_129 ;
} else if ( V_26 != V_6 -> V_44 )
F_110 ( V_6 , V_26 ) ;
}
static void F_118 ( struct V_5 * V_6 , struct V_125 * V_38 ,
struct V_25 * V_26 )
{
unsigned int V_39 , V_170 ;
T_2 V_146 ;
V_146 = F_78 ( V_26 -> V_129 , V_38 -> V_148 ) ;
V_170 = ( V_146 - V_38 -> V_129 ) >> V_38 -> V_148 ;
V_39 = ( V_38 -> V_151 + V_170 ) % V_149 ;
F_93 ( & V_26 -> V_134 ) ;
if ( F_94 ( & V_38 -> V_152 [ V_39 ] ) )
F_95 ( V_170 , & V_38 -> V_153 ) ;
}
static void F_28 ( struct V_5 * V_6 , struct V_25 * V_26 )
{
struct V_125 * V_38 = V_26 -> V_38 ;
unsigned long V_131 ;
T_2 V_146 ;
int V_167 ;
if ( V_26 == V_6 -> V_44 ) {
F_105 ( V_26 ) ;
V_6 -> V_44 = F_23 ( V_6 ) ;
return;
}
V_26 -> V_135 = V_26 -> V_129 ;
F_118 ( V_6 , V_38 , V_26 ) ;
if ( ! V_38 -> V_153 ) {
F_95 ( V_38 -> V_22 , & V_6 -> V_132 [ V_141 ] ) ;
F_95 ( V_38 -> V_22 , & V_6 -> V_132 [ V_136 ] ) ;
F_95 ( V_38 -> V_22 , & V_6 -> V_132 [ V_140 ] ) ;
if ( F_119 ( V_38 -> V_22 , & V_6 -> V_132 [ V_133 ] ) &&
! ( V_6 -> V_132 [ V_133 ] & ~ ( ( 1UL << V_38 -> V_22 ) - 1 ) ) ) {
V_131 = V_6 -> V_132 [ V_133 ] & ( ( 1UL << V_38 -> V_22 ) - 1 ) ;
if ( V_131 )
V_131 = ~ ( ( 1UL << F_9 ( V_131 ) ) - 1 ) ;
else
V_131 = ~ 0UL ;
F_83 ( V_6 , V_131 , V_136 , V_133 ) ;
F_83 ( V_6 , V_131 , V_140 , V_141 ) ;
}
F_95 ( V_38 -> V_22 , & V_6 -> V_132 [ V_133 ] ) ;
} else if ( F_94 ( & V_38 -> V_152 [ V_38 -> V_151 ] ) ) {
V_26 = F_96 ( V_38 ) ;
V_146 = F_78 ( V_26 -> V_129 , V_38 -> V_148 ) ;
if ( V_38 -> V_129 != V_146 ) {
F_95 ( V_38 -> V_22 , & V_6 -> V_132 [ V_133 ] ) ;
F_95 ( V_38 -> V_22 , & V_6 -> V_132 [ V_141 ] ) ;
F_95 ( V_38 -> V_22 , & V_6 -> V_132 [ V_136 ] ) ;
F_95 ( V_38 -> V_22 , & V_6 -> V_132 [ V_140 ] ) ;
V_38 -> V_129 = V_146 ;
V_38 -> V_135 = V_146 + ( 2ULL << V_38 -> V_148 ) ;
V_167 = F_82 ( V_6 , V_38 ) ;
F_89 ( V_38 -> V_22 , & V_6 -> V_132 [ V_167 ] ) ;
}
}
}
static void F_120 ( struct V_2 * V_3 , unsigned long V_52 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 = (struct V_1 * ) V_52 ;
if ( V_11 -> V_13 -> V_6 . V_14 == 0 )
F_25 ( V_6 , V_11 ) ;
}
static unsigned int F_121 ( struct V_5 * V_6 ,
struct V_171 * V_147 )
{
struct V_25 * V_26 ;
struct V_1 * V_11 ;
unsigned int V_12 ;
F_15 (agg, slot, next) {
F_122 (cl, &agg->active, alist) {
if ( ! V_11 -> V_13 -> V_156 -> V_172 )
continue;
V_12 = V_11 -> V_13 -> V_156 -> V_172 ( V_11 -> V_13 ) ;
if ( V_12 > 0 ) {
if ( V_11 -> V_13 -> V_6 . V_14 == 0 )
F_25 ( V_6 , V_11 ) ;
return V_12 ;
}
}
}
return 0 ;
}
static unsigned int F_123 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_125 * V_38 ;
unsigned int V_39 , V_173 , V_12 ;
for ( V_39 = 0 ; V_39 <= V_174 ; V_39 ++ ) {
V_38 = & V_6 -> V_40 [ V_39 ] ;
for ( V_173 = 0 ; V_173 < V_149 ; V_173 ++ ) {
V_12 = F_121 ( V_6 , & V_38 -> V_152 [ V_173 ] ) ;
if ( V_12 > 0 ) {
V_3 -> V_6 . V_14 -- ;
return V_12 ;
}
}
}
return 0 ;
}
static int F_124 ( struct V_2 * V_3 , struct V_50 * V_175 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_125 * V_38 ;
int V_39 , V_173 , V_56 ;
T_1 V_176 , V_177 , V_178 ;
V_56 = F_125 ( & V_6 -> V_9 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( F_38 ( V_3 ) -> V_179 + 1 > V_180 )
V_178 = V_180 ;
else
V_178 = F_38 ( V_3 ) -> V_179 + 1 ;
V_176 = F_9 ( V_178 ) ;
V_6 -> V_35 = 1 << V_176 ;
V_177 = V_65 + V_176 ;
V_6 -> V_19 = V_181 + V_177 - V_174 ;
for ( V_39 = 0 ; V_39 <= V_174 ; V_39 ++ ) {
V_38 = & V_6 -> V_40 [ V_39 ] ;
V_38 -> V_22 = V_39 ;
V_38 -> V_148 = V_6 -> V_19 + V_39 ;
for ( V_173 = 0 ; V_173 < V_149 ; V_173 ++ )
F_126 ( & V_38 -> V_152 [ V_173 ] ) ;
}
F_126 ( & V_6 -> V_31 ) ;
return 0 ;
}
static void F_127 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
unsigned int V_39 ;
for ( V_39 = 0 ; V_39 < V_6 -> V_9 . V_103 ; V_39 ++ ) {
F_15 (cl, &q->clhash.hash[i], common.hnode) {
if ( V_11 -> V_13 -> V_6 . V_14 > 0 )
F_25 ( V_6 , V_11 ) ;
F_6 ( V_11 -> V_13 ) ;
}
}
V_3 -> V_6 . V_14 = 0 ;
}
static void F_128 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_182 * V_134 ;
unsigned int V_39 ;
F_129 ( & V_6 -> V_81 ) ;
for ( V_39 = 0 ; V_39 < V_6 -> V_9 . V_103 ; V_39 ++ ) {
F_130 (cl, next, &q->clhash.hash[i],
common.hnode) {
F_49 ( V_3 , V_11 ) ;
}
}
F_131 ( & V_6 -> V_9 ) ;
}
static int T_4 F_132 ( void )
{
return F_133 ( & V_183 ) ;
}
static void T_5 F_134 ( void )
{
F_135 ( & V_183 ) ;
}
