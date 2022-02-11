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
static int F_14 ( struct V_2 * V_3 , T_1 V_4 , T_1 V_33 ,
struct V_34 * * V_35 , unsigned long * V_36 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 = (struct V_1 * ) * V_36 ;
struct V_34 * V_37 [ V_38 + 1 ] ;
T_1 V_39 , V_27 , V_15 ;
int V_29 , V_40 ;
int V_28 ;
if ( V_35 [ V_41 ] == NULL ) {
F_15 ( L_2 ) ;
return - V_42 ;
}
V_40 = F_16 ( V_37 , V_38 , V_35 [ V_41 ] , V_43 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( V_37 [ V_44 ] ) {
V_39 = F_17 ( V_37 [ V_44 ] ) ;
if ( ! V_39 || V_39 > ( 1UL << V_45 ) ) {
F_15 ( L_3 , V_39 ) ;
return - V_42 ;
}
} else
V_39 = 1 ;
V_15 = V_22 / V_39 ;
V_39 = V_22 / V_15 ;
V_28 = V_39 - ( V_11 ? V_22 / V_11 -> V_15 : 0 ) ;
if ( V_6 -> V_32 + V_28 > V_46 ) {
F_15 ( L_4 ,
V_28 , V_6 -> V_32 ) ;
return - V_42 ;
}
if ( V_37 [ V_47 ] ) {
V_27 = F_17 ( V_37 [ V_47 ] ) ;
if ( ! V_27 || V_27 > ( 1UL << V_48 ) ) {
F_15 ( L_5 , V_27 ) ;
return - V_42 ;
}
} else
V_27 = 1UL << V_48 ;
if ( V_11 != NULL ) {
bool V_49 = false ;
if ( V_35 [ V_50 ] ) {
V_40 = F_18 ( & V_11 -> V_51 , & V_11 -> V_52 ,
F_19 ( V_3 ) ,
V_35 [ V_50 ] ) ;
if ( V_40 )
return V_40 ;
}
if ( V_27 == V_11 -> V_27 && V_15 == V_11 -> V_15 )
return 0 ;
V_29 = F_8 ( V_15 , V_27 ) ;
F_20 ( V_3 ) ;
if ( & V_6 -> V_31 [ V_29 ] != V_11 -> V_30 && V_11 -> V_13 -> V_6 . V_14 > 0 ) {
V_11 -> V_53 = V_11 -> V_54 ;
F_21 ( V_6 , V_11 ) ;
V_49 = true ;
}
F_13 ( V_6 , V_11 , V_27 , V_15 , V_28 ) ;
if ( V_49 )
F_22 ( V_6 , V_11 , F_11 ( V_11 -> V_13 ) ) ;
F_23 ( V_3 ) ;
return 0 ;
}
V_11 = F_24 ( sizeof( struct V_1 ) , V_55 ) ;
if ( V_11 == NULL )
return - V_56 ;
V_11 -> V_57 = 1 ;
V_11 -> V_10 . V_4 = V_4 ;
F_13 ( V_6 , V_11 , V_27 , V_15 , V_28 ) ;
V_11 -> V_13 = F_25 ( V_3 -> V_58 ,
& V_59 , V_4 ) ;
if ( V_11 -> V_13 == NULL )
V_11 -> V_13 = & V_60 ;
if ( V_35 [ V_50 ] ) {
V_40 = F_26 ( & V_11 -> V_51 , & V_11 -> V_52 ,
F_19 ( V_3 ) ,
V_35 [ V_50 ] ) ;
if ( V_40 ) {
F_27 ( V_11 -> V_13 ) ;
F_28 ( V_11 ) ;
return V_40 ;
}
}
F_20 ( V_3 ) ;
F_29 ( & V_6 -> V_9 , & V_11 -> V_10 ) ;
F_23 ( V_3 ) ;
F_30 ( V_3 , & V_6 -> V_9 ) ;
* V_36 = ( unsigned long ) V_11 ;
return 0 ;
}
static void F_31 ( struct V_2 * V_3 , struct V_1 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
if ( V_11 -> V_15 ) {
V_6 -> V_32 -= V_22 / V_11 -> V_15 ;
V_11 -> V_15 = 0 ;
}
F_32 ( & V_11 -> V_51 , & V_11 -> V_52 ) ;
F_27 ( V_11 -> V_13 ) ;
F_28 ( V_11 ) ;
}
static int F_33 ( struct V_2 * V_3 , unsigned long V_36 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 = (struct V_1 * ) V_36 ;
if ( V_11 -> V_61 > 0 )
return - V_62 ;
F_20 ( V_3 ) ;
F_5 ( V_11 ) ;
F_34 ( & V_6 -> V_9 , & V_11 -> V_10 ) ;
F_35 ( -- V_11 -> V_57 == 0 ) ;
F_23 ( V_3 ) ;
return 0 ;
}
static unsigned long F_36 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_11 = F_1 ( V_3 , V_4 ) ;
if ( V_11 != NULL )
V_11 -> V_57 ++ ;
return ( unsigned long ) V_11 ;
}
static void F_37 ( struct V_2 * V_3 , unsigned long V_36 )
{
struct V_1 * V_11 = (struct V_1 * ) V_36 ;
if ( -- V_11 -> V_57 == 0 )
F_31 ( V_3 , V_11 ) ;
}
static struct V_63 * * F_38 ( struct V_2 * V_3 , unsigned long V_11 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
if ( V_11 )
return NULL ;
return & V_6 -> V_64 ;
}
static unsigned long F_39 ( struct V_2 * V_3 , unsigned long V_65 ,
T_1 V_4 )
{
struct V_1 * V_11 = F_1 ( V_3 , V_4 ) ;
if ( V_11 != NULL )
V_11 -> V_61 ++ ;
return ( unsigned long ) V_11 ;
}
static void F_40 ( struct V_2 * V_3 , unsigned long V_36 )
{
struct V_1 * V_11 = (struct V_1 * ) V_36 ;
V_11 -> V_61 -- ;
}
static int F_41 ( struct V_2 * V_3 , unsigned long V_36 ,
struct V_2 * V_66 , struct V_2 * * V_67 )
{
struct V_1 * V_11 = (struct V_1 * ) V_36 ;
if ( V_66 == NULL ) {
V_66 = F_25 ( V_3 -> V_58 ,
& V_59 , V_11 -> V_10 . V_4 ) ;
if ( V_66 == NULL )
V_66 = & V_60 ;
}
F_20 ( V_3 ) ;
F_5 ( V_11 ) ;
* V_67 = V_11 -> V_13 ;
V_11 -> V_13 = V_66 ;
F_23 ( V_3 ) ;
return 0 ;
}
static struct V_2 * F_42 ( struct V_2 * V_3 , unsigned long V_36 )
{
struct V_1 * V_11 = (struct V_1 * ) V_36 ;
return V_11 -> V_13 ;
}
static int F_43 ( struct V_2 * V_3 , unsigned long V_36 ,
struct V_23 * V_24 , struct V_68 * V_69 )
{
struct V_1 * V_11 = (struct V_1 * ) V_36 ;
struct V_34 * V_70 ;
V_69 -> V_71 = V_72 ;
V_69 -> V_73 = V_11 -> V_10 . V_4 ;
V_69 -> V_74 = V_11 -> V_13 -> V_75 ;
V_70 = F_44 ( V_24 , V_41 ) ;
if ( V_70 == NULL )
goto V_76;
if ( F_45 ( V_24 , V_44 , V_22 / V_11 -> V_15 ) ||
F_45 ( V_24 , V_47 , V_11 -> V_27 ) )
goto V_76;
return F_46 ( V_24 , V_70 ) ;
V_76:
F_47 ( V_24 , V_70 ) ;
return - V_77 ;
}
static int F_48 ( struct V_2 * V_3 , unsigned long V_36 ,
struct V_78 * V_79 )
{
struct V_1 * V_11 = (struct V_1 * ) V_36 ;
struct V_80 V_81 ;
memset ( & V_81 , 0 , sizeof( V_81 ) ) ;
V_11 -> V_13 -> V_82 . V_14 = V_11 -> V_13 -> V_6 . V_14 ;
V_81 . V_39 = V_22 / V_11 -> V_15 ;
V_81 . V_27 = V_11 -> V_27 ;
if ( F_49 ( V_79 , & V_11 -> V_51 ) < 0 ||
F_50 ( V_79 , & V_11 -> V_51 , & V_11 -> V_52 ) < 0 ||
F_51 ( V_79 , & V_11 -> V_13 -> V_82 ) < 0 )
return - 1 ;
return F_52 ( V_79 , & V_81 , sizeof( V_81 ) ) ;
}
static void F_53 ( struct V_2 * V_3 , struct V_83 * V_36 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_84 * V_85 ;
unsigned int V_29 ;
if ( V_36 -> V_86 )
return;
for ( V_29 = 0 ; V_29 < V_6 -> V_9 . V_87 ; V_29 ++ ) {
F_54 (cl, n, &q->clhash.hash[i], common.hnode) {
if ( V_36 -> V_88 < V_36 -> V_89 ) {
V_36 -> V_88 ++ ;
continue;
}
if ( V_36 -> V_90 ( V_3 , ( unsigned long ) V_11 , V_36 ) < 0 ) {
V_36 -> V_86 = 1 ;
return;
}
V_36 -> V_88 ++ ;
}
}
}
static struct V_1 * F_55 ( struct V_23 * V_24 , struct V_2 * V_3 ,
int * V_91 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_92 V_93 ;
int V_94 ;
if ( F_56 ( V_24 -> V_95 ^ V_3 -> V_75 ) == 0 ) {
F_10 ( L_6 , V_24 -> V_95 ) ;
V_11 = F_1 ( V_3 , V_24 -> V_95 ) ;
if ( V_11 != NULL )
return V_11 ;
}
* V_91 = V_96 | V_97 ;
V_94 = F_57 ( V_24 , V_6 -> V_64 , & V_93 ) ;
if ( V_94 >= 0 ) {
#ifdef F_58
switch ( V_94 ) {
case V_98 :
case V_99 :
* V_91 = V_96 | V_100 ;
case V_101 :
return NULL ;
}
#endif
V_11 = (struct V_1 * ) V_93 . V_102 ;
if ( V_11 == NULL )
V_11 = F_1 ( V_3 , V_93 . V_4 ) ;
return V_11 ;
}
return NULL ;
}
static inline int F_59 ( T_2 V_103 , T_2 V_104 )
{
return ( V_105 ) ( V_103 - V_104 ) > 0 ;
}
static inline T_2 F_60 ( T_2 V_106 , unsigned int V_107 )
{
return V_106 & ~ ( ( 1ULL << V_107 ) - 1 ) ;
}
static inline struct V_108 * F_61 ( struct V_5 * V_6 ,
unsigned long V_109 )
{
int V_19 = F_62 ( V_109 ) ;
return & V_6 -> V_31 [ V_19 ] ;
}
static inline unsigned long F_63 ( unsigned long V_109 , int V_110 )
{
return V_109 & ~ ( ( 1UL << V_110 ) - 1 ) ;
}
static int F_64 ( struct V_5 * V_6 , const struct V_108 * V_30 )
{
unsigned int V_111 = F_59 ( V_30 -> V_54 , V_6 -> V_112 ) ;
unsigned long V_113 = F_63 ( V_6 -> V_114 [ V_115 ] , V_30 -> V_19 ) ;
struct V_108 * V_116 ;
if ( V_113 ) {
V_116 = F_61 ( V_6 , V_113 ) ;
if ( F_59 ( V_30 -> V_53 , V_116 -> V_53 ) )
V_111 |= V_117 ;
}
return V_111 ;
}
static inline void F_65 ( struct V_5 * V_6 , unsigned long V_113 ,
int V_118 , int V_119 )
{
V_6 -> V_114 [ V_119 ] |= V_6 -> V_114 [ V_118 ] & V_113 ;
V_6 -> V_114 [ V_118 ] &= ~ V_113 ;
}
static void F_66 ( struct V_5 * V_6 , int V_19 , T_2 V_120 )
{
unsigned long V_113 = F_63 ( V_6 -> V_114 [ V_115 ] , V_19 + 1 ) ;
struct V_108 * V_116 ;
if ( V_113 ) {
V_116 = F_61 ( V_6 , V_113 ) ;
if ( ! F_59 ( V_116 -> V_53 , V_120 ) )
return;
}
V_113 = ( 1UL << V_19 ) - 1 ;
F_65 ( V_6 , V_113 , V_117 , V_115 ) ;
F_65 ( V_6 , V_113 , V_121 , V_122 ) ;
}
static void F_67 ( struct V_5 * V_6 , T_2 V_123 )
{
unsigned long V_124 = V_6 -> V_112 >> V_20 ;
unsigned long V_125 = V_123 >> V_20 ;
if ( V_124 != V_125 ) {
unsigned long V_113 = ( 1UL << F_68 ( V_124 ^ V_125 ) ) - 1 ;
F_65 ( V_6 , V_113 , V_122 , V_115 ) ;
F_65 ( V_6 , V_113 , V_121 , V_117 ) ;
}
}
static void F_69 ( struct V_108 * V_30 , struct V_1 * V_11 ,
T_2 V_126 )
{
T_2 V_127 = ( V_126 - V_30 -> V_54 ) >> V_30 -> V_128 ;
unsigned int V_29 = ( V_30 -> V_129 + V_127 ) % V_130 ;
F_70 ( & V_11 -> V_116 , & V_30 -> V_131 [ V_29 ] ) ;
F_71 ( V_127 , & V_30 -> V_132 ) ;
}
static struct V_1 * F_72 ( struct V_108 * V_30 )
{
return F_73 ( V_30 -> V_131 [ V_30 -> V_129 ] . V_133 ,
struct V_1 , V_116 ) ;
}
static void F_74 ( struct V_108 * V_30 )
{
struct V_1 * V_11 = F_72 ( V_30 ) ;
F_35 ( ! V_11 ) ;
F_75 ( & V_11 -> V_116 ) ;
if ( F_76 ( & V_30 -> V_131 [ V_30 -> V_129 ] ) )
F_77 ( 0 , & V_30 -> V_132 ) ;
}
static struct V_1 * F_78 ( struct V_108 * V_30 )
{
unsigned int V_29 ;
F_10 ( L_7 ,
V_30 -> V_19 , V_30 -> V_132 ) ;
if ( V_30 -> V_132 == 0 )
return NULL ;
V_29 = F_62 ( V_30 -> V_132 ) ;
if ( V_29 > 0 ) {
V_30 -> V_129 = ( V_30 -> V_129 + V_29 ) % V_130 ;
V_30 -> V_132 >>= V_29 ;
}
return F_72 ( V_30 ) ;
}
static void F_79 ( struct V_108 * V_30 , T_2 V_126 )
{
unsigned int V_29 = ( V_30 -> V_54 - V_126 ) >> V_30 -> V_128 ;
V_30 -> V_132 <<= V_29 ;
V_30 -> V_129 = ( V_30 -> V_129 - V_29 ) % V_130 ;
}
static void F_80 ( struct V_5 * V_6 , T_2 V_123 )
{
struct V_108 * V_30 ;
unsigned long V_134 ;
V_134 = V_6 -> V_114 [ V_122 ] | V_6 -> V_114 [ V_121 ] ;
if ( V_134 ) {
if ( ! V_6 -> V_114 [ V_115 ] ) {
V_30 = F_61 ( V_6 , V_134 ) ;
if ( F_59 ( V_30 -> V_54 , V_6 -> V_112 ) )
V_6 -> V_112 = V_30 -> V_54 ;
}
F_67 ( V_6 , V_123 ) ;
}
}
static bool F_81 ( struct V_108 * V_30 , struct V_1 * V_11 )
{
unsigned int V_12 = F_11 ( V_11 -> V_13 ) ;
V_11 -> V_54 = V_11 -> V_53 ;
if ( ! V_12 )
F_74 ( V_30 ) ;
else {
T_2 V_126 ;
V_11 -> V_53 = V_11 -> V_54 + ( T_2 ) V_12 * V_11 -> V_15 ;
V_126 = F_60 ( V_11 -> V_54 , V_30 -> V_128 ) ;
if ( V_126 == V_30 -> V_54 )
return false ;
F_74 ( V_30 ) ;
F_69 ( V_30 , V_11 , V_126 ) ;
}
return true ;
}
static struct V_23 * F_82 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_108 * V_30 ;
struct V_1 * V_11 ;
struct V_23 * V_24 ;
unsigned int V_12 ;
T_2 V_123 ;
if ( ! V_6 -> V_114 [ V_115 ] )
return NULL ;
V_30 = F_61 ( V_6 , V_6 -> V_114 [ V_115 ] ) ;
V_11 = F_72 ( V_30 ) ;
V_24 = F_83 ( V_11 -> V_13 ) ;
if ( ! V_24 ) {
F_84 ( 1 , L_8 ) ;
return NULL ;
}
V_3 -> V_6 . V_14 -- ;
F_85 ( V_3 , V_24 ) ;
V_123 = V_6 -> V_112 ;
V_12 = F_12 ( V_24 ) ;
V_6 -> V_112 += ( T_2 ) V_12 * V_135 ;
F_10 ( L_9 ,
V_12 , ( unsigned long long ) V_11 -> V_53 , ( unsigned long long ) V_6 -> V_112 ) ;
if ( F_81 ( V_30 , V_11 ) ) {
T_2 V_120 = V_30 -> V_53 ;
V_11 = F_78 ( V_30 ) ;
if ( ! V_11 )
F_77 ( V_30 -> V_19 , & V_6 -> V_114 [ V_115 ] ) ;
else {
T_2 V_126 = F_60 ( V_11 -> V_54 , V_30 -> V_128 ) ;
unsigned int V_136 ;
if ( V_30 -> V_54 == V_126 )
goto V_137;
V_30 -> V_54 = V_126 ;
V_30 -> V_53 = V_126 + ( 2ULL << V_30 -> V_128 ) ;
F_77 ( V_30 -> V_19 , & V_6 -> V_114 [ V_115 ] ) ;
V_136 = F_64 ( V_6 , V_30 ) ;
F_71 ( V_30 -> V_19 , & V_6 -> V_114 [ V_136 ] ) ;
}
F_66 ( V_6 , V_30 -> V_19 , V_120 ) ;
}
V_137:
F_80 ( V_6 , V_123 ) ;
return V_24 ;
}
static void F_86 ( struct V_5 * V_6 , struct V_1 * V_11 )
{
unsigned long V_113 ;
T_2 V_138 , V_139 ;
int V_128 = V_11 -> V_30 -> V_128 ;
V_139 = F_60 ( V_11 -> V_53 , V_128 ) ;
V_138 = F_60 ( V_6 -> V_112 , V_128 ) + ( 1ULL << V_128 ) ;
if ( ! F_59 ( V_11 -> V_53 , V_6 -> V_112 ) || F_59 ( V_139 , V_138 ) ) {
V_113 = F_63 ( V_6 -> V_114 [ V_115 ] , V_11 -> V_30 -> V_19 ) ;
if ( V_113 ) {
struct V_108 * V_116 = F_61 ( V_6 , V_113 ) ;
if ( F_59 ( V_139 , V_116 -> V_53 ) ) {
if ( F_59 ( V_138 , V_116 -> V_53 ) )
V_11 -> V_54 = V_116 -> V_53 ;
else
V_11 -> V_54 = V_138 ;
return;
}
}
V_11 -> V_54 = V_6 -> V_112 ;
} else
V_11 -> V_54 = V_11 -> V_53 ;
}
static int F_87 ( struct V_23 * V_24 , struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
int V_40 ;
V_11 = F_55 ( V_24 , V_3 , & V_40 ) ;
if ( V_11 == NULL ) {
if ( V_40 & V_97 )
V_3 -> V_82 . V_140 ++ ;
F_88 ( V_24 ) ;
return V_40 ;
}
F_10 ( L_10 , V_11 -> V_10 . V_4 ) ;
V_40 = F_89 ( V_24 , V_11 -> V_13 ) ;
if ( F_90 ( V_40 != V_96 ) ) {
F_10 ( L_11 , V_40 ) ;
if ( F_91 ( V_40 ) ) {
V_11 -> V_82 . V_140 ++ ;
V_3 -> V_82 . V_140 ++ ;
}
return V_40 ;
}
F_92 ( & V_11 -> V_51 , V_24 ) ;
++ V_3 -> V_6 . V_14 ;
if ( V_11 -> V_13 -> V_6 . V_14 != 1 )
return V_40 ;
F_22 ( V_6 , V_11 , F_12 ( V_24 ) ) ;
return V_40 ;
}
static void F_22 ( struct V_5 * V_6 , struct V_1 * V_11 ,
unsigned int V_141 )
{
struct V_108 * V_30 = V_11 -> V_30 ;
T_2 V_126 ;
int V_136 ;
F_86 ( V_6 , V_11 ) ;
V_11 -> V_53 = V_11 -> V_54 + ( T_2 ) V_141 * V_11 -> V_15 ;
V_126 = F_60 ( V_11 -> V_54 , V_30 -> V_128 ) ;
if ( V_30 -> V_132 ) {
if ( ! F_59 ( V_30 -> V_54 , V_11 -> V_54 ) )
goto V_142;
F_79 ( V_30 , V_126 ) ;
F_77 ( V_30 -> V_19 , & V_6 -> V_114 [ V_122 ] ) ;
F_77 ( V_30 -> V_19 , & V_6 -> V_114 [ V_121 ] ) ;
} else if ( ! V_6 -> V_114 [ V_115 ] && F_59 ( V_126 , V_6 -> V_112 ) )
V_6 -> V_112 = V_126 ;
V_30 -> V_54 = V_126 ;
V_30 -> V_53 = V_126 + ( 2ULL << V_30 -> V_128 ) ;
V_136 = F_64 ( V_6 , V_30 ) ;
F_71 ( V_30 -> V_19 , & V_6 -> V_114 [ V_136 ] ) ;
F_10 ( L_12 ,
V_136 , V_6 -> V_114 [ V_136 ] ,
( unsigned long long ) V_11 -> V_54 ,
( unsigned long long ) V_11 -> V_53 ,
( unsigned long long ) V_6 -> V_112 ) ;
V_142:
F_69 ( V_30 , V_11 , V_126 ) ;
}
static void F_93 ( struct V_5 * V_6 , struct V_108 * V_30 ,
struct V_1 * V_11 )
{
unsigned int V_29 , V_143 ;
T_2 V_126 ;
V_126 = F_60 ( V_11 -> V_54 , V_30 -> V_128 ) ;
V_143 = ( V_126 - V_30 -> V_54 ) >> V_30 -> V_128 ;
V_29 = ( V_30 -> V_129 + V_143 ) % V_130 ;
F_75 ( & V_11 -> V_116 ) ;
if ( F_76 ( & V_30 -> V_131 [ V_29 ] ) )
F_77 ( V_143 , & V_30 -> V_132 ) ;
}
static void F_21 ( struct V_5 * V_6 , struct V_1 * V_11 )
{
struct V_108 * V_30 = V_11 -> V_30 ;
unsigned long V_113 ;
T_2 V_126 ;
int V_136 ;
V_11 -> V_53 = V_11 -> V_54 ;
F_93 ( V_6 , V_30 , V_11 ) ;
if ( ! V_30 -> V_132 ) {
F_77 ( V_30 -> V_19 , & V_6 -> V_114 [ V_122 ] ) ;
F_77 ( V_30 -> V_19 , & V_6 -> V_114 [ V_117 ] ) ;
F_77 ( V_30 -> V_19 , & V_6 -> V_114 [ V_121 ] ) ;
if ( F_94 ( V_30 -> V_19 , & V_6 -> V_114 [ V_115 ] ) &&
! ( V_6 -> V_114 [ V_115 ] & ~ ( ( 1UL << V_30 -> V_19 ) - 1 ) ) ) {
V_113 = V_6 -> V_114 [ V_115 ] & ( ( 1UL << V_30 -> V_19 ) - 1 ) ;
if ( V_113 )
V_113 = ~ ( ( 1UL << F_9 ( V_113 ) ) - 1 ) ;
else
V_113 = ~ 0UL ;
F_65 ( V_6 , V_113 , V_117 , V_115 ) ;
F_65 ( V_6 , V_113 , V_121 , V_122 ) ;
}
F_77 ( V_30 -> V_19 , & V_6 -> V_114 [ V_115 ] ) ;
} else if ( F_76 ( & V_30 -> V_131 [ V_30 -> V_129 ] ) ) {
V_11 = F_78 ( V_30 ) ;
V_126 = F_60 ( V_11 -> V_54 , V_30 -> V_128 ) ;
if ( V_30 -> V_54 != V_126 ) {
F_77 ( V_30 -> V_19 , & V_6 -> V_114 [ V_115 ] ) ;
F_77 ( V_30 -> V_19 , & V_6 -> V_114 [ V_122 ] ) ;
F_77 ( V_30 -> V_19 , & V_6 -> V_114 [ V_117 ] ) ;
F_77 ( V_30 -> V_19 , & V_6 -> V_114 [ V_121 ] ) ;
V_30 -> V_54 = V_126 ;
V_30 -> V_53 = V_126 + ( 2ULL << V_30 -> V_128 ) ;
V_136 = F_64 ( V_6 , V_30 ) ;
F_71 ( V_30 -> V_19 , & V_6 -> V_114 [ V_136 ] ) ;
}
}
F_80 ( V_6 , V_6 -> V_112 ) ;
}
static void F_95 ( struct V_2 * V_3 , unsigned long V_36 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 = (struct V_1 * ) V_36 ;
if ( V_11 -> V_13 -> V_6 . V_14 == 0 )
F_21 ( V_6 , V_11 ) ;
}
static unsigned int F_96 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_108 * V_30 ;
unsigned int V_29 , V_144 , V_12 ;
for ( V_29 = 0 ; V_29 <= V_145 ; V_29 ++ ) {
V_30 = & V_6 -> V_31 [ V_29 ] ;
for ( V_144 = 0 ; V_144 < V_130 ; V_144 ++ ) {
struct V_1 * V_11 ;
struct V_84 * V_85 ;
F_54 (cl, n, &grp->slots[j], next) {
if ( ! V_11 -> V_13 -> V_25 -> V_146 )
continue;
V_12 = V_11 -> V_13 -> V_25 -> V_146 ( V_11 -> V_13 ) ;
if ( V_12 > 0 ) {
V_3 -> V_6 . V_14 -- ;
if ( ! V_11 -> V_13 -> V_6 . V_14 )
F_21 ( V_6 , V_11 ) ;
return V_12 ;
}
}
}
}
return 0 ;
}
static int F_97 ( struct V_2 * V_3 , struct V_34 * V_147 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_108 * V_30 ;
int V_29 , V_144 , V_40 ;
V_40 = F_98 ( & V_6 -> V_9 ) ;
if ( V_40 < 0 )
return V_40 ;
for ( V_29 = 0 ; V_29 <= V_145 ; V_29 ++ ) {
V_30 = & V_6 -> V_31 [ V_29 ] ;
V_30 -> V_19 = V_29 ;
V_30 -> V_128 = V_48 + V_148
- ( V_145 - V_29 ) ;
for ( V_144 = 0 ; V_144 < V_130 ; V_144 ++ )
F_99 ( & V_30 -> V_131 [ V_144 ] ) ;
}
return 0 ;
}
static void F_100 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_108 * V_30 ;
struct V_1 * V_11 ;
struct V_84 * V_85 , * V_149 ;
unsigned int V_29 , V_144 ;
for ( V_29 = 0 ; V_29 <= V_145 ; V_29 ++ ) {
V_30 = & V_6 -> V_31 [ V_29 ] ;
for ( V_144 = 0 ; V_144 < V_130 ; V_144 ++ ) {
F_101 (cl, n, tmp,
&grp->slots[j], next) {
F_21 ( V_6 , V_11 ) ;
}
}
}
for ( V_29 = 0 ; V_29 < V_6 -> V_9 . V_87 ; V_29 ++ ) {
F_54 (cl, n, &q->clhash.hash[i], common.hnode)
F_6 ( V_11 -> V_13 ) ;
}
V_3 -> V_6 . V_14 = 0 ;
}
static void F_102 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_84 * V_85 , * V_116 ;
unsigned int V_29 ;
F_103 ( & V_6 -> V_64 ) ;
for ( V_29 = 0 ; V_29 < V_6 -> V_9 . V_87 ; V_29 ++ ) {
F_101 (cl, n, next, &q->clhash.hash[i],
common.hnode) {
F_31 ( V_3 , V_11 ) ;
}
}
F_104 ( & V_6 -> V_9 ) ;
}
static int T_3 F_105 ( void )
{
return F_106 ( & V_150 ) ;
}
static void T_4 F_107 ( void )
{
F_108 ( & V_150 ) ;
}
