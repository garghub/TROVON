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
static int F_8 ( T_1 V_15 , unsigned int V_16 )
{
T_2 V_17 = ( T_2 ) V_16 * V_15 ;
unsigned long V_18 ;
int V_19 = 0 ;
V_18 = V_17 >> V_20 ;
if ( ! V_18 )
goto V_21;
V_19 = F_9 ( V_18 ) + 1 ;
V_19 -= ! ( V_17 - ( 1ULL << ( V_19 + V_20 - 1 ) ) ) ;
if ( V_19 < 0 )
V_19 = 0 ;
V_21:
F_10 ( L_1 ,
( unsigned long ) V_22 / V_15 , V_16 , V_19 ) ;
return V_19 ;
}
static unsigned int F_11 ( struct V_2 * V_3 )
{
struct V_23 * V_24 ;
V_24 = V_3 -> V_25 -> V_26 ( V_3 ) ;
return V_24 ? F_12 ( V_24 ) : 0 ;
}
static void F_13 ( struct V_5 * V_6 , struct V_1 * V_11 ,
T_1 V_27 , T_1 V_15 , int V_28 )
{
int V_29 ;
V_11 -> V_27 = V_27 ;
V_11 -> V_15 = V_15 ;
V_29 = F_8 ( V_11 -> V_15 , V_11 -> V_27 ) ;
V_11 -> V_30 = & V_6 -> V_31 [ V_29 ] ;
V_6 -> V_32 += V_28 ;
}
static void F_14 ( struct V_5 * V_6 ,
struct V_1 * V_11 ,
T_1 V_15 , T_1 V_27 , int V_28 )
{
bool V_33 = false ;
int V_29 = F_8 ( V_15 , V_27 ) ;
if ( & V_6 -> V_31 [ V_29 ] != V_11 -> V_30 && V_11 -> V_13 -> V_6 . V_14 > 0 ) {
V_11 -> V_34 = V_11 -> V_35 ;
F_15 ( V_6 , V_11 ) ;
V_33 = true ;
}
F_13 ( V_6 , V_11 , V_27 , V_15 , V_28 ) ;
if ( V_33 )
F_16 ( V_6 , V_11 , F_11 ( V_11 -> V_13 ) ) ;
}
static int F_17 ( struct V_2 * V_3 , T_1 V_4 , T_1 V_36 ,
struct V_37 * * V_38 , unsigned long * V_39 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 = (struct V_1 * ) * V_39 ;
struct V_37 * V_40 [ V_41 + 1 ] ;
T_1 V_42 , V_27 , V_15 ;
int V_43 ;
int V_28 ;
if ( V_38 [ V_44 ] == NULL ) {
F_18 ( L_2 ) ;
return - V_45 ;
}
V_43 = F_19 ( V_40 , V_41 , V_38 [ V_44 ] , V_46 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_40 [ V_47 ] ) {
V_42 = F_20 ( V_40 [ V_47 ] ) ;
if ( ! V_42 || V_42 > ( 1UL << V_48 ) ) {
F_18 ( L_3 , V_42 ) ;
return - V_45 ;
}
} else
V_42 = 1 ;
V_15 = V_22 / V_42 ;
V_42 = V_22 / V_15 ;
V_28 = V_42 - ( V_11 ? V_22 / V_11 -> V_15 : 0 ) ;
if ( V_6 -> V_32 + V_28 > V_49 ) {
F_18 ( L_4 ,
V_28 , V_6 -> V_32 ) ;
return - V_45 ;
}
if ( V_40 [ V_50 ] ) {
V_27 = F_20 ( V_40 [ V_50 ] ) ;
if ( V_27 < V_51 || V_27 > ( 1UL << V_52 ) ) {
F_18 ( L_5 , V_27 ) ;
return - V_45 ;
}
} else
V_27 = F_21 ( F_22 ( V_3 ) ) ;
if ( V_11 != NULL ) {
if ( V_38 [ V_53 ] ) {
V_43 = F_23 ( & V_11 -> V_54 , & V_11 -> V_55 ,
F_24 ( V_3 ) ,
V_38 [ V_53 ] ) ;
if ( V_43 )
return V_43 ;
}
if ( V_27 == V_11 -> V_27 && V_15 == V_11 -> V_15 )
return 0 ;
F_25 ( V_3 ) ;
F_14 ( V_6 , V_11 , V_15 , V_27 , V_28 ) ;
F_26 ( V_3 ) ;
return 0 ;
}
V_11 = F_27 ( sizeof( struct V_1 ) , V_56 ) ;
if ( V_11 == NULL )
return - V_57 ;
V_11 -> V_58 = 1 ;
V_11 -> V_10 . V_4 = V_4 ;
F_13 ( V_6 , V_11 , V_27 , V_15 , V_28 ) ;
V_11 -> V_13 = F_28 ( V_3 -> V_59 ,
& V_60 , V_4 ) ;
if ( V_11 -> V_13 == NULL )
V_11 -> V_13 = & V_61 ;
if ( V_38 [ V_53 ] ) {
V_43 = F_29 ( & V_11 -> V_54 , & V_11 -> V_55 ,
F_24 ( V_3 ) ,
V_38 [ V_53 ] ) ;
if ( V_43 ) {
F_30 ( V_11 -> V_13 ) ;
F_31 ( V_11 ) ;
return V_43 ;
}
}
F_25 ( V_3 ) ;
F_32 ( & V_6 -> V_9 , & V_11 -> V_10 ) ;
F_26 ( V_3 ) ;
F_33 ( V_3 , & V_6 -> V_9 ) ;
* V_39 = ( unsigned long ) V_11 ;
return 0 ;
}
static void F_34 ( struct V_2 * V_3 , struct V_1 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
if ( V_11 -> V_15 ) {
V_6 -> V_32 -= V_22 / V_11 -> V_15 ;
V_11 -> V_15 = 0 ;
}
F_35 ( & V_11 -> V_54 , & V_11 -> V_55 ) ;
F_30 ( V_11 -> V_13 ) ;
F_31 ( V_11 ) ;
}
static int F_36 ( struct V_2 * V_3 , unsigned long V_39 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 = (struct V_1 * ) V_39 ;
if ( V_11 -> V_62 > 0 )
return - V_63 ;
F_25 ( V_3 ) ;
F_5 ( V_11 ) ;
F_37 ( & V_6 -> V_9 , & V_11 -> V_10 ) ;
F_38 ( -- V_11 -> V_58 == 0 ) ;
F_26 ( V_3 ) ;
return 0 ;
}
static unsigned long F_39 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_11 = F_1 ( V_3 , V_4 ) ;
if ( V_11 != NULL )
V_11 -> V_58 ++ ;
return ( unsigned long ) V_11 ;
}
static void F_40 ( struct V_2 * V_3 , unsigned long V_39 )
{
struct V_1 * V_11 = (struct V_1 * ) V_39 ;
if ( -- V_11 -> V_58 == 0 )
F_34 ( V_3 , V_11 ) ;
}
static struct V_64 * * F_41 ( struct V_2 * V_3 , unsigned long V_11 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
if ( V_11 )
return NULL ;
return & V_6 -> V_65 ;
}
static unsigned long F_42 ( struct V_2 * V_3 , unsigned long V_66 ,
T_1 V_4 )
{
struct V_1 * V_11 = F_1 ( V_3 , V_4 ) ;
if ( V_11 != NULL )
V_11 -> V_62 ++ ;
return ( unsigned long ) V_11 ;
}
static void F_43 ( struct V_2 * V_3 , unsigned long V_39 )
{
struct V_1 * V_11 = (struct V_1 * ) V_39 ;
V_11 -> V_62 -- ;
}
static int F_44 ( struct V_2 * V_3 , unsigned long V_39 ,
struct V_2 * V_67 , struct V_2 * * V_68 )
{
struct V_1 * V_11 = (struct V_1 * ) V_39 ;
if ( V_67 == NULL ) {
V_67 = F_28 ( V_3 -> V_59 ,
& V_60 , V_11 -> V_10 . V_4 ) ;
if ( V_67 == NULL )
V_67 = & V_61 ;
}
F_25 ( V_3 ) ;
F_5 ( V_11 ) ;
* V_68 = V_11 -> V_13 ;
V_11 -> V_13 = V_67 ;
F_26 ( V_3 ) ;
return 0 ;
}
static struct V_2 * F_45 ( struct V_2 * V_3 , unsigned long V_39 )
{
struct V_1 * V_11 = (struct V_1 * ) V_39 ;
return V_11 -> V_13 ;
}
static int F_46 ( struct V_2 * V_3 , unsigned long V_39 ,
struct V_23 * V_24 , struct V_69 * V_70 )
{
struct V_1 * V_11 = (struct V_1 * ) V_39 ;
struct V_37 * V_71 ;
V_70 -> V_72 = V_73 ;
V_70 -> V_74 = V_11 -> V_10 . V_4 ;
V_70 -> V_75 = V_11 -> V_13 -> V_76 ;
V_71 = F_47 ( V_24 , V_44 ) ;
if ( V_71 == NULL )
goto V_77;
if ( F_48 ( V_24 , V_47 , V_22 / V_11 -> V_15 ) ||
F_48 ( V_24 , V_50 , V_11 -> V_27 ) )
goto V_77;
return F_49 ( V_24 , V_71 ) ;
V_77:
F_50 ( V_24 , V_71 ) ;
return - V_78 ;
}
static int F_51 ( struct V_2 * V_3 , unsigned long V_39 ,
struct V_79 * V_80 )
{
struct V_1 * V_11 = (struct V_1 * ) V_39 ;
struct V_81 V_82 ;
memset ( & V_82 , 0 , sizeof( V_82 ) ) ;
V_11 -> V_13 -> V_83 . V_14 = V_11 -> V_13 -> V_6 . V_14 ;
V_82 . V_42 = V_22 / V_11 -> V_15 ;
V_82 . V_27 = V_11 -> V_27 ;
if ( F_52 ( V_80 , & V_11 -> V_54 ) < 0 ||
F_53 ( V_80 , & V_11 -> V_54 , & V_11 -> V_55 ) < 0 ||
F_54 ( V_80 , & V_11 -> V_13 -> V_83 ) < 0 )
return - 1 ;
return F_55 ( V_80 , & V_82 , sizeof( V_82 ) ) ;
}
static void F_56 ( struct V_2 * V_3 , struct V_84 * V_39 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_85 * V_86 ;
unsigned int V_29 ;
if ( V_39 -> V_87 )
return;
for ( V_29 = 0 ; V_29 < V_6 -> V_9 . V_88 ; V_29 ++ ) {
F_57 (cl, n, &q->clhash.hash[i], common.hnode) {
if ( V_39 -> V_89 < V_39 -> V_90 ) {
V_39 -> V_89 ++ ;
continue;
}
if ( V_39 -> V_91 ( V_3 , ( unsigned long ) V_11 , V_39 ) < 0 ) {
V_39 -> V_87 = 1 ;
return;
}
V_39 -> V_89 ++ ;
}
}
}
static struct V_1 * F_58 ( struct V_23 * V_24 , struct V_2 * V_3 ,
int * V_92 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_93 V_94 ;
int V_95 ;
if ( F_59 ( V_24 -> V_96 ^ V_3 -> V_76 ) == 0 ) {
F_10 ( L_6 , V_24 -> V_96 ) ;
V_11 = F_1 ( V_3 , V_24 -> V_96 ) ;
if ( V_11 != NULL )
return V_11 ;
}
* V_92 = V_97 | V_98 ;
V_95 = F_60 ( V_24 , V_6 -> V_65 , & V_94 ) ;
if ( V_95 >= 0 ) {
#ifdef F_61
switch ( V_95 ) {
case V_99 :
case V_100 :
* V_92 = V_97 | V_101 ;
case V_102 :
return NULL ;
}
#endif
V_11 = (struct V_1 * ) V_94 . V_103 ;
if ( V_11 == NULL )
V_11 = F_1 ( V_3 , V_94 . V_4 ) ;
return V_11 ;
}
return NULL ;
}
static inline int F_62 ( T_2 V_104 , T_2 V_105 )
{
return ( V_106 ) ( V_104 - V_105 ) > 0 ;
}
static inline T_2 F_63 ( T_2 V_107 , unsigned int V_108 )
{
return V_107 & ~ ( ( 1ULL << V_108 ) - 1 ) ;
}
static inline struct V_109 * F_64 ( struct V_5 * V_6 ,
unsigned long V_110 )
{
int V_19 = F_65 ( V_110 ) ;
return & V_6 -> V_31 [ V_19 ] ;
}
static inline unsigned long F_66 ( unsigned long V_110 , int V_111 )
{
return V_110 & ~ ( ( 1UL << V_111 ) - 1 ) ;
}
static int F_67 ( struct V_5 * V_6 , const struct V_109 * V_30 )
{
unsigned int V_112 = F_62 ( V_30 -> V_35 , V_6 -> V_113 ) ;
unsigned long V_114 = F_66 ( V_6 -> V_115 [ V_116 ] , V_30 -> V_19 ) ;
struct V_109 * V_117 ;
if ( V_114 ) {
V_117 = F_64 ( V_6 , V_114 ) ;
if ( F_62 ( V_30 -> V_34 , V_117 -> V_34 ) )
V_112 |= V_118 ;
}
return V_112 ;
}
static inline void F_68 ( struct V_5 * V_6 , unsigned long V_114 ,
int V_119 , int V_120 )
{
V_6 -> V_115 [ V_120 ] |= V_6 -> V_115 [ V_119 ] & V_114 ;
V_6 -> V_115 [ V_119 ] &= ~ V_114 ;
}
static void F_69 ( struct V_5 * V_6 , int V_19 , T_2 V_121 )
{
unsigned long V_114 = F_66 ( V_6 -> V_115 [ V_116 ] , V_19 + 1 ) ;
struct V_109 * V_117 ;
if ( V_114 ) {
V_117 = F_64 ( V_6 , V_114 ) ;
if ( ! F_62 ( V_117 -> V_34 , V_121 ) )
return;
}
V_114 = ( 1UL << V_19 ) - 1 ;
F_68 ( V_6 , V_114 , V_118 , V_116 ) ;
F_68 ( V_6 , V_114 , V_122 , V_123 ) ;
}
static void F_70 ( struct V_5 * V_6 , T_2 V_124 )
{
unsigned long V_125 = V_6 -> V_113 >> V_20 ;
unsigned long V_126 = V_124 >> V_20 ;
if ( V_125 != V_126 ) {
unsigned long V_114 = ( 1UL << F_71 ( V_125 ^ V_126 ) ) - 1 ;
F_68 ( V_6 , V_114 , V_123 , V_116 ) ;
F_68 ( V_6 , V_114 , V_122 , V_118 ) ;
}
}
static void F_72 ( struct V_109 * V_30 , struct V_1 * V_11 ,
T_2 V_127 )
{
T_2 V_128 = ( V_127 - V_30 -> V_35 ) >> V_30 -> V_129 ;
unsigned int V_29 ;
if ( F_73 ( V_128 > V_130 - 2 ) ) {
T_2 V_131 = V_127 - V_30 -> V_35 -
( ( T_2 ) ( V_130 - 2 ) << V_30 -> V_129 ) ;
V_11 -> V_35 -= V_131 ;
V_11 -> V_34 -= V_131 ;
V_128 = V_130 - 2 ;
}
V_29 = ( V_30 -> V_132 + V_128 ) % V_130 ;
F_74 ( & V_11 -> V_117 , & V_30 -> V_133 [ V_29 ] ) ;
F_75 ( V_128 , & V_30 -> V_134 ) ;
}
static struct V_1 * F_76 ( struct V_109 * V_30 )
{
return F_77 ( V_30 -> V_133 [ V_30 -> V_132 ] . V_135 ,
struct V_1 , V_117 ) ;
}
static void F_78 ( struct V_109 * V_30 )
{
struct V_1 * V_11 = F_76 ( V_30 ) ;
F_38 ( ! V_11 ) ;
F_79 ( & V_11 -> V_117 ) ;
if ( F_80 ( & V_30 -> V_133 [ V_30 -> V_132 ] ) )
F_81 ( 0 , & V_30 -> V_134 ) ;
}
static struct V_1 * F_82 ( struct V_109 * V_30 )
{
unsigned int V_29 ;
F_10 ( L_7 ,
V_30 -> V_19 , V_30 -> V_134 ) ;
if ( V_30 -> V_134 == 0 )
return NULL ;
V_29 = F_65 ( V_30 -> V_134 ) ;
if ( V_29 > 0 ) {
V_30 -> V_132 = ( V_30 -> V_132 + V_29 ) % V_130 ;
V_30 -> V_134 >>= V_29 ;
}
return F_76 ( V_30 ) ;
}
static void F_83 ( struct V_109 * V_30 , T_2 V_127 )
{
unsigned int V_29 = ( V_30 -> V_35 - V_127 ) >> V_30 -> V_129 ;
V_30 -> V_134 <<= V_29 ;
V_30 -> V_132 = ( V_30 -> V_132 - V_29 ) % V_130 ;
}
static void F_84 ( struct V_5 * V_6 , T_2 V_124 )
{
struct V_109 * V_30 ;
unsigned long V_136 ;
V_136 = V_6 -> V_115 [ V_123 ] | V_6 -> V_115 [ V_122 ] ;
if ( V_136 ) {
if ( ! V_6 -> V_115 [ V_116 ] ) {
V_30 = F_64 ( V_6 , V_136 ) ;
if ( F_62 ( V_30 -> V_35 , V_6 -> V_113 ) )
V_6 -> V_113 = V_30 -> V_35 ;
}
F_70 ( V_6 , V_124 ) ;
}
}
static bool F_85 ( struct V_109 * V_30 , struct V_1 * V_11 )
{
unsigned int V_12 = F_11 ( V_11 -> V_13 ) ;
V_11 -> V_35 = V_11 -> V_34 ;
if ( ! V_12 )
F_78 ( V_30 ) ;
else {
T_2 V_127 ;
V_11 -> V_34 = V_11 -> V_35 + ( T_2 ) V_12 * V_11 -> V_15 ;
V_127 = F_63 ( V_11 -> V_35 , V_30 -> V_129 ) ;
if ( V_127 == V_30 -> V_35 )
return false ;
F_78 ( V_30 ) ;
F_72 ( V_30 , V_11 , V_127 ) ;
}
return true ;
}
static struct V_23 * F_86 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_109 * V_30 ;
struct V_1 * V_11 ;
struct V_23 * V_24 ;
unsigned int V_12 ;
T_2 V_124 ;
if ( ! V_6 -> V_115 [ V_116 ] )
return NULL ;
V_30 = F_64 ( V_6 , V_6 -> V_115 [ V_116 ] ) ;
V_11 = F_76 ( V_30 ) ;
V_24 = F_87 ( V_11 -> V_13 ) ;
if ( ! V_24 ) {
F_88 ( 1 , L_8 ) ;
return NULL ;
}
V_3 -> V_6 . V_14 -- ;
F_89 ( V_3 , V_24 ) ;
V_124 = V_6 -> V_113 ;
V_12 = F_12 ( V_24 ) ;
V_6 -> V_113 += ( T_2 ) V_12 * V_137 ;
F_10 ( L_9 ,
V_12 , ( unsigned long long ) V_11 -> V_34 , ( unsigned long long ) V_6 -> V_113 ) ;
if ( F_85 ( V_30 , V_11 ) ) {
T_2 V_121 = V_30 -> V_34 ;
V_11 = F_82 ( V_30 ) ;
if ( ! V_11 )
F_81 ( V_30 -> V_19 , & V_6 -> V_115 [ V_116 ] ) ;
else {
T_2 V_127 = F_63 ( V_11 -> V_35 , V_30 -> V_129 ) ;
unsigned int V_138 ;
if ( V_30 -> V_35 == V_127 )
goto V_139;
V_30 -> V_35 = V_127 ;
V_30 -> V_34 = V_127 + ( 2ULL << V_30 -> V_129 ) ;
F_81 ( V_30 -> V_19 , & V_6 -> V_115 [ V_116 ] ) ;
V_138 = F_67 ( V_6 , V_30 ) ;
F_75 ( V_30 -> V_19 , & V_6 -> V_115 [ V_138 ] ) ;
}
F_69 ( V_6 , V_30 -> V_19 , V_121 ) ;
}
V_139:
F_84 ( V_6 , V_124 ) ;
return V_24 ;
}
static void F_90 ( struct V_5 * V_6 , struct V_1 * V_11 )
{
unsigned long V_114 ;
T_2 V_140 , V_141 ;
int V_129 = V_11 -> V_30 -> V_129 ;
V_141 = F_63 ( V_11 -> V_34 , V_129 ) ;
V_140 = F_63 ( V_6 -> V_113 , V_129 ) + ( 1ULL << V_129 ) ;
if ( ! F_62 ( V_11 -> V_34 , V_6 -> V_113 ) || F_62 ( V_141 , V_140 ) ) {
V_114 = F_66 ( V_6 -> V_115 [ V_116 ] , V_11 -> V_30 -> V_19 ) ;
if ( V_114 ) {
struct V_109 * V_117 = F_64 ( V_6 , V_114 ) ;
if ( F_62 ( V_141 , V_117 -> V_34 ) ) {
if ( F_62 ( V_140 , V_117 -> V_34 ) )
V_11 -> V_35 = V_117 -> V_34 ;
else
V_11 -> V_35 = V_140 ;
return;
}
}
V_11 -> V_35 = V_6 -> V_113 ;
} else
V_11 -> V_35 = V_11 -> V_34 ;
}
static int F_91 ( struct V_23 * V_24 , struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
int V_43 = 0 ;
V_11 = F_58 ( V_24 , V_3 , & V_43 ) ;
if ( V_11 == NULL ) {
if ( V_43 & V_98 )
V_3 -> V_83 . V_142 ++ ;
F_92 ( V_24 ) ;
return V_43 ;
}
F_10 ( L_10 , V_11 -> V_10 . V_4 ) ;
if ( F_73 ( V_11 -> V_27 < F_12 ( V_24 ) ) ) {
F_10 ( L_11 ,
V_11 -> V_27 , F_12 ( V_24 ) , V_11 -> V_10 . V_4 ) ;
F_14 ( V_6 , V_11 , V_11 -> V_15 ,
F_12 ( V_24 ) , 0 ) ;
}
V_43 = F_93 ( V_24 , V_11 -> V_13 ) ;
if ( F_73 ( V_43 != V_97 ) ) {
F_10 ( L_12 , V_43 ) ;
if ( F_94 ( V_43 ) ) {
V_11 -> V_83 . V_142 ++ ;
V_3 -> V_83 . V_142 ++ ;
}
return V_43 ;
}
F_95 ( & V_11 -> V_54 , V_24 ) ;
++ V_3 -> V_6 . V_14 ;
if ( V_11 -> V_13 -> V_6 . V_14 != 1 )
return V_43 ;
F_16 ( V_6 , V_11 , F_12 ( V_24 ) ) ;
return V_43 ;
}
static void F_16 ( struct V_5 * V_6 , struct V_1 * V_11 ,
unsigned int V_143 )
{
struct V_109 * V_30 = V_11 -> V_30 ;
T_2 V_127 ;
int V_138 ;
F_90 ( V_6 , V_11 ) ;
V_11 -> V_34 = V_11 -> V_35 + ( T_2 ) V_143 * V_11 -> V_15 ;
V_127 = F_63 ( V_11 -> V_35 , V_30 -> V_129 ) ;
if ( V_30 -> V_134 ) {
if ( ! F_62 ( V_30 -> V_35 , V_11 -> V_35 ) )
goto V_144;
F_83 ( V_30 , V_127 ) ;
F_81 ( V_30 -> V_19 , & V_6 -> V_115 [ V_123 ] ) ;
F_81 ( V_30 -> V_19 , & V_6 -> V_115 [ V_122 ] ) ;
} else if ( ! V_6 -> V_115 [ V_116 ] && F_62 ( V_127 , V_6 -> V_113 ) )
V_6 -> V_113 = V_127 ;
V_30 -> V_35 = V_127 ;
V_30 -> V_34 = V_127 + ( 2ULL << V_30 -> V_129 ) ;
V_138 = F_67 ( V_6 , V_30 ) ;
F_75 ( V_30 -> V_19 , & V_6 -> V_115 [ V_138 ] ) ;
F_10 ( L_13 ,
V_138 , V_6 -> V_115 [ V_138 ] ,
( unsigned long long ) V_11 -> V_35 ,
( unsigned long long ) V_11 -> V_34 ,
( unsigned long long ) V_6 -> V_113 ) ;
V_144:
F_72 ( V_30 , V_11 , V_127 ) ;
}
static void F_96 ( struct V_5 * V_6 , struct V_109 * V_30 ,
struct V_1 * V_11 )
{
unsigned int V_29 , V_145 ;
T_2 V_127 ;
V_127 = F_63 ( V_11 -> V_35 , V_30 -> V_129 ) ;
V_145 = ( V_127 - V_30 -> V_35 ) >> V_30 -> V_129 ;
V_29 = ( V_30 -> V_132 + V_145 ) % V_130 ;
F_79 ( & V_11 -> V_117 ) ;
if ( F_80 ( & V_30 -> V_133 [ V_29 ] ) )
F_81 ( V_145 , & V_30 -> V_134 ) ;
}
static void F_15 ( struct V_5 * V_6 , struct V_1 * V_11 )
{
struct V_109 * V_30 = V_11 -> V_30 ;
unsigned long V_114 ;
T_2 V_127 ;
int V_138 ;
V_11 -> V_34 = V_11 -> V_35 ;
F_96 ( V_6 , V_30 , V_11 ) ;
if ( ! V_30 -> V_134 ) {
F_81 ( V_30 -> V_19 , & V_6 -> V_115 [ V_123 ] ) ;
F_81 ( V_30 -> V_19 , & V_6 -> V_115 [ V_118 ] ) ;
F_81 ( V_30 -> V_19 , & V_6 -> V_115 [ V_122 ] ) ;
if ( F_97 ( V_30 -> V_19 , & V_6 -> V_115 [ V_116 ] ) &&
! ( V_6 -> V_115 [ V_116 ] & ~ ( ( 1UL << V_30 -> V_19 ) - 1 ) ) ) {
V_114 = V_6 -> V_115 [ V_116 ] & ( ( 1UL << V_30 -> V_19 ) - 1 ) ;
if ( V_114 )
V_114 = ~ ( ( 1UL << F_9 ( V_114 ) ) - 1 ) ;
else
V_114 = ~ 0UL ;
F_68 ( V_6 , V_114 , V_118 , V_116 ) ;
F_68 ( V_6 , V_114 , V_122 , V_123 ) ;
}
F_81 ( V_30 -> V_19 , & V_6 -> V_115 [ V_116 ] ) ;
} else if ( F_80 ( & V_30 -> V_133 [ V_30 -> V_132 ] ) ) {
V_11 = F_82 ( V_30 ) ;
V_127 = F_63 ( V_11 -> V_35 , V_30 -> V_129 ) ;
if ( V_30 -> V_35 != V_127 ) {
F_81 ( V_30 -> V_19 , & V_6 -> V_115 [ V_116 ] ) ;
F_81 ( V_30 -> V_19 , & V_6 -> V_115 [ V_123 ] ) ;
F_81 ( V_30 -> V_19 , & V_6 -> V_115 [ V_118 ] ) ;
F_81 ( V_30 -> V_19 , & V_6 -> V_115 [ V_122 ] ) ;
V_30 -> V_35 = V_127 ;
V_30 -> V_34 = V_127 + ( 2ULL << V_30 -> V_129 ) ;
V_138 = F_67 ( V_6 , V_30 ) ;
F_75 ( V_30 -> V_19 , & V_6 -> V_115 [ V_138 ] ) ;
}
}
F_84 ( V_6 , V_6 -> V_113 ) ;
}
static void F_98 ( struct V_2 * V_3 , unsigned long V_39 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 = (struct V_1 * ) V_39 ;
if ( V_11 -> V_13 -> V_6 . V_14 == 0 )
F_15 ( V_6 , V_11 ) ;
}
static unsigned int F_99 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_109 * V_30 ;
unsigned int V_29 , V_146 , V_12 ;
for ( V_29 = 0 ; V_29 <= V_147 ; V_29 ++ ) {
V_30 = & V_6 -> V_31 [ V_29 ] ;
for ( V_146 = 0 ; V_146 < V_130 ; V_146 ++ ) {
struct V_1 * V_11 ;
struct V_85 * V_86 ;
F_57 (cl, n, &grp->slots[j], next) {
if ( ! V_11 -> V_13 -> V_25 -> V_148 )
continue;
V_12 = V_11 -> V_13 -> V_25 -> V_148 ( V_11 -> V_13 ) ;
if ( V_12 > 0 ) {
V_3 -> V_6 . V_14 -- ;
if ( ! V_11 -> V_13 -> V_6 . V_14 )
F_15 ( V_6 , V_11 ) ;
return V_12 ;
}
}
}
}
return 0 ;
}
static int F_100 ( struct V_2 * V_3 , struct V_37 * V_149 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_109 * V_30 ;
int V_29 , V_146 , V_43 ;
V_43 = F_101 ( & V_6 -> V_9 ) ;
if ( V_43 < 0 )
return V_43 ;
for ( V_29 = 0 ; V_29 <= V_147 ; V_29 ++ ) {
V_30 = & V_6 -> V_31 [ V_29 ] ;
V_30 -> V_19 = V_29 ;
V_30 -> V_129 = V_52 + V_150
- ( V_147 - V_29 ) ;
for ( V_146 = 0 ; V_146 < V_130 ; V_146 ++ )
F_102 ( & V_30 -> V_133 [ V_146 ] ) ;
}
return 0 ;
}
static void F_103 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_109 * V_30 ;
struct V_1 * V_11 ;
struct V_85 * V_86 , * V_151 ;
unsigned int V_29 , V_146 ;
for ( V_29 = 0 ; V_29 <= V_147 ; V_29 ++ ) {
V_30 = & V_6 -> V_31 [ V_29 ] ;
for ( V_146 = 0 ; V_146 < V_130 ; V_146 ++ ) {
F_104 (cl, n, tmp,
&grp->slots[j], next) {
F_15 ( V_6 , V_11 ) ;
}
}
}
for ( V_29 = 0 ; V_29 < V_6 -> V_9 . V_88 ; V_29 ++ ) {
F_57 (cl, n, &q->clhash.hash[i], common.hnode)
F_6 ( V_11 -> V_13 ) ;
}
V_3 -> V_6 . V_14 = 0 ;
}
static void F_105 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_85 * V_86 , * V_117 ;
unsigned int V_29 ;
F_106 ( & V_6 -> V_65 ) ;
for ( V_29 = 0 ; V_29 < V_6 -> V_9 . V_88 ; V_29 ++ ) {
F_104 (cl, n, next, &q->clhash.hash[i],
common.hnode) {
F_34 ( V_3 , V_11 ) ;
}
}
F_107 ( & V_6 -> V_9 ) ;
}
static int T_3 F_108 ( void )
{
return F_109 ( & V_152 ) ;
}
static void T_4 F_110 ( void )
{
F_111 ( & V_152 ) ;
}
