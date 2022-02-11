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
static int F_11 ( struct V_2 * V_3 , T_1 V_4 , T_1 V_23 ,
struct V_24 * * V_25 , unsigned long * V_26 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 = (struct V_1 * ) * V_26 ;
struct V_24 * V_27 [ V_28 + 1 ] ;
T_1 V_29 , V_30 , V_15 ;
int V_31 , V_32 ;
if ( V_25 [ V_33 ] == NULL ) {
F_12 ( L_2 ) ;
return - V_34 ;
}
V_32 = F_13 ( V_27 , V_28 , V_25 [ V_33 ] , V_35 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_27 [ V_36 ] ) {
V_29 = F_14 ( V_27 [ V_36 ] ) ;
if ( ! V_29 || V_29 > ( 1UL << V_37 ) ) {
F_12 ( L_3 , V_29 ) ;
return - V_34 ;
}
} else
V_29 = 1 ;
V_15 = V_22 / V_29 ;
V_29 = V_22 / V_15 ;
if ( V_6 -> V_38 + V_29 > V_39 ) {
F_12 ( L_4 ,
V_29 , V_6 -> V_38 ) ;
return - V_34 ;
}
if ( V_27 [ V_40 ] ) {
V_30 = F_14 ( V_27 [ V_40 ] ) ;
if ( ! V_30 || V_30 > ( 1UL << V_41 ) ) {
F_12 ( L_5 , V_30 ) ;
return - V_34 ;
}
} else
V_30 = 1UL << V_41 ;
if ( V_11 != NULL ) {
if ( V_25 [ V_42 ] ) {
V_32 = F_15 ( & V_11 -> V_43 , & V_11 -> V_44 ,
F_16 ( V_3 ) ,
V_25 [ V_42 ] ) ;
if ( V_32 )
return V_32 ;
}
F_17 ( V_3 ) ;
if ( V_27 [ V_36 ] ) {
V_6 -> V_38 = V_29 - V_22 / V_11 -> V_15 ;
V_11 -> V_15 = V_15 ;
}
F_18 ( V_3 ) ;
return 0 ;
}
V_11 = F_19 ( sizeof( struct V_1 ) , V_45 ) ;
if ( V_11 == NULL )
return - V_46 ;
V_11 -> V_47 = 1 ;
V_11 -> V_10 . V_4 = V_4 ;
V_11 -> V_30 = V_30 ;
V_11 -> V_15 = V_15 ;
V_31 = F_8 ( V_11 -> V_15 , V_11 -> V_30 ) ;
V_11 -> V_48 = & V_6 -> V_49 [ V_31 ] ;
V_6 -> V_38 += V_29 ;
V_11 -> V_13 = F_20 ( V_3 -> V_50 ,
& V_51 , V_4 ) ;
if ( V_11 -> V_13 == NULL )
V_11 -> V_13 = & V_52 ;
if ( V_25 [ V_42 ] ) {
V_32 = F_21 ( & V_11 -> V_43 , & V_11 -> V_44 ,
F_16 ( V_3 ) ,
V_25 [ V_42 ] ) ;
if ( V_32 ) {
F_22 ( V_11 -> V_13 ) ;
F_23 ( V_11 ) ;
return V_32 ;
}
}
F_17 ( V_3 ) ;
F_24 ( & V_6 -> V_9 , & V_11 -> V_10 ) ;
F_18 ( V_3 ) ;
F_25 ( V_3 , & V_6 -> V_9 ) ;
* V_26 = ( unsigned long ) V_11 ;
return 0 ;
}
static void F_26 ( struct V_2 * V_3 , struct V_1 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
if ( V_11 -> V_15 ) {
V_6 -> V_38 -= V_22 / V_11 -> V_15 ;
V_11 -> V_15 = 0 ;
}
F_27 ( & V_11 -> V_43 , & V_11 -> V_44 ) ;
F_22 ( V_11 -> V_13 ) ;
F_23 ( V_11 ) ;
}
static int F_28 ( struct V_2 * V_3 , unsigned long V_26 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 = (struct V_1 * ) V_26 ;
if ( V_11 -> V_53 > 0 )
return - V_54 ;
F_17 ( V_3 ) ;
F_5 ( V_11 ) ;
F_29 ( & V_6 -> V_9 , & V_11 -> V_10 ) ;
F_30 ( -- V_11 -> V_47 == 0 ) ;
F_18 ( V_3 ) ;
return 0 ;
}
static unsigned long F_31 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_11 = F_1 ( V_3 , V_4 ) ;
if ( V_11 != NULL )
V_11 -> V_47 ++ ;
return ( unsigned long ) V_11 ;
}
static void F_32 ( struct V_2 * V_3 , unsigned long V_26 )
{
struct V_1 * V_11 = (struct V_1 * ) V_26 ;
if ( -- V_11 -> V_47 == 0 )
F_26 ( V_3 , V_11 ) ;
}
static struct V_55 * * F_33 ( struct V_2 * V_3 , unsigned long V_11 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
if ( V_11 )
return NULL ;
return & V_6 -> V_56 ;
}
static unsigned long F_34 ( struct V_2 * V_3 , unsigned long V_57 ,
T_1 V_4 )
{
struct V_1 * V_11 = F_1 ( V_3 , V_4 ) ;
if ( V_11 != NULL )
V_11 -> V_53 ++ ;
return ( unsigned long ) V_11 ;
}
static void F_35 ( struct V_2 * V_3 , unsigned long V_26 )
{
struct V_1 * V_11 = (struct V_1 * ) V_26 ;
V_11 -> V_53 -- ;
}
static int F_36 ( struct V_2 * V_3 , unsigned long V_26 ,
struct V_2 * V_58 , struct V_2 * * V_59 )
{
struct V_1 * V_11 = (struct V_1 * ) V_26 ;
if ( V_58 == NULL ) {
V_58 = F_20 ( V_3 -> V_50 ,
& V_51 , V_11 -> V_10 . V_4 ) ;
if ( V_58 == NULL )
V_58 = & V_52 ;
}
F_17 ( V_3 ) ;
F_5 ( V_11 ) ;
* V_59 = V_11 -> V_13 ;
V_11 -> V_13 = V_58 ;
F_18 ( V_3 ) ;
return 0 ;
}
static struct V_2 * F_37 ( struct V_2 * V_3 , unsigned long V_26 )
{
struct V_1 * V_11 = (struct V_1 * ) V_26 ;
return V_11 -> V_13 ;
}
static int F_38 ( struct V_2 * V_3 , unsigned long V_26 ,
struct V_60 * V_61 , struct V_62 * V_63 )
{
struct V_1 * V_11 = (struct V_1 * ) V_26 ;
struct V_24 * V_64 ;
V_63 -> V_65 = V_66 ;
V_63 -> V_67 = V_11 -> V_10 . V_4 ;
V_63 -> V_68 = V_11 -> V_13 -> V_69 ;
V_64 = F_39 ( V_61 , V_33 ) ;
if ( V_64 == NULL )
goto V_70;
F_40 ( V_61 , V_36 , V_22 / V_11 -> V_15 ) ;
F_40 ( V_61 , V_40 , V_11 -> V_30 ) ;
return F_41 ( V_61 , V_64 ) ;
V_70:
F_42 ( V_61 , V_64 ) ;
return - V_71 ;
}
static int F_43 ( struct V_2 * V_3 , unsigned long V_26 ,
struct V_72 * V_73 )
{
struct V_1 * V_11 = (struct V_1 * ) V_26 ;
struct V_74 V_75 ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_11 -> V_13 -> V_76 . V_14 = V_11 -> V_13 -> V_6 . V_14 ;
V_75 . V_29 = V_22 / V_11 -> V_15 ;
V_75 . V_30 = V_11 -> V_30 ;
if ( F_44 ( V_73 , & V_11 -> V_43 ) < 0 ||
F_45 ( V_73 , & V_11 -> V_43 , & V_11 -> V_44 ) < 0 ||
F_46 ( V_73 , & V_11 -> V_13 -> V_76 ) < 0 )
return - 1 ;
return F_47 ( V_73 , & V_75 , sizeof( V_75 ) ) ;
}
static void F_48 ( struct V_2 * V_3 , struct V_77 * V_26 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_78 * V_79 ;
unsigned int V_31 ;
if ( V_26 -> V_80 )
return;
for ( V_31 = 0 ; V_31 < V_6 -> V_9 . V_81 ; V_31 ++ ) {
F_49 (cl, n, &q->clhash.hash[i], common.hnode) {
if ( V_26 -> V_82 < V_26 -> V_83 ) {
V_26 -> V_82 ++ ;
continue;
}
if ( V_26 -> V_84 ( V_3 , ( unsigned long ) V_11 , V_26 ) < 0 ) {
V_26 -> V_80 = 1 ;
return;
}
V_26 -> V_82 ++ ;
}
}
}
static struct V_1 * F_50 ( struct V_60 * V_61 , struct V_2 * V_3 ,
int * V_85 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_86 V_87 ;
int V_88 ;
if ( F_51 ( V_61 -> V_89 ^ V_3 -> V_69 ) == 0 ) {
F_10 ( L_6 , V_61 -> V_89 ) ;
V_11 = F_1 ( V_3 , V_61 -> V_89 ) ;
if ( V_11 != NULL )
return V_11 ;
}
* V_85 = V_90 | V_91 ;
V_88 = F_52 ( V_61 , V_6 -> V_56 , & V_87 ) ;
if ( V_88 >= 0 ) {
#ifdef F_53
switch ( V_88 ) {
case V_92 :
case V_93 :
* V_85 = V_90 | V_94 ;
case V_95 :
return NULL ;
}
#endif
V_11 = (struct V_1 * ) V_87 . V_96 ;
if ( V_11 == NULL )
V_11 = F_1 ( V_3 , V_87 . V_4 ) ;
return V_11 ;
}
return NULL ;
}
static inline int F_54 ( T_2 V_97 , T_2 V_98 )
{
return ( V_99 ) ( V_97 - V_98 ) > 0 ;
}
static inline T_2 F_55 ( T_2 V_100 , unsigned int V_101 )
{
return V_100 & ~ ( ( 1ULL << V_101 ) - 1 ) ;
}
static inline struct V_102 * F_56 ( struct V_5 * V_6 ,
unsigned long V_103 )
{
int V_19 = F_57 ( V_103 ) ;
return & V_6 -> V_49 [ V_19 ] ;
}
static inline unsigned long F_58 ( unsigned long V_103 , int V_104 )
{
return V_103 & ~ ( ( 1UL << V_104 ) - 1 ) ;
}
static int F_59 ( struct V_5 * V_6 , const struct V_102 * V_48 )
{
unsigned int V_105 = F_54 ( V_48 -> V_106 , V_6 -> V_107 ) ;
unsigned long V_108 = F_58 ( V_6 -> V_109 [ V_110 ] , V_48 -> V_19 ) ;
struct V_102 * V_111 ;
if ( V_108 ) {
V_111 = F_56 ( V_6 , V_108 ) ;
if ( F_54 ( V_48 -> V_112 , V_111 -> V_112 ) )
V_105 |= V_113 ;
}
return V_105 ;
}
static inline void F_60 ( struct V_5 * V_6 , unsigned long V_108 ,
int V_114 , int V_115 )
{
V_6 -> V_109 [ V_115 ] |= V_6 -> V_109 [ V_114 ] & V_108 ;
V_6 -> V_109 [ V_114 ] &= ~ V_108 ;
}
static void F_61 ( struct V_5 * V_6 , int V_19 , T_2 V_116 )
{
unsigned long V_108 = F_58 ( V_6 -> V_109 [ V_110 ] , V_19 + 1 ) ;
struct V_102 * V_111 ;
if ( V_108 ) {
V_111 = F_56 ( V_6 , V_108 ) ;
if ( ! F_54 ( V_111 -> V_112 , V_116 ) )
return;
}
V_108 = ( 1UL << V_19 ) - 1 ;
F_60 ( V_6 , V_108 , V_113 , V_110 ) ;
F_60 ( V_6 , V_108 , V_117 , V_118 ) ;
}
static void F_62 ( struct V_5 * V_6 , T_2 V_119 )
{
unsigned long V_120 = V_6 -> V_107 >> V_20 ;
unsigned long V_121 = V_119 >> V_20 ;
if ( V_120 != V_121 ) {
unsigned long V_108 = ( 1UL << F_63 ( V_120 ^ V_121 ) ) - 1 ;
F_60 ( V_6 , V_108 , V_118 , V_110 ) ;
F_60 ( V_6 , V_108 , V_117 , V_113 ) ;
}
}
static void F_64 ( struct V_102 * V_48 , struct V_1 * V_11 ,
T_2 V_122 )
{
T_2 V_123 = ( V_122 - V_48 -> V_106 ) >> V_48 -> V_124 ;
unsigned int V_31 = ( V_48 -> V_125 + V_123 ) % V_126 ;
F_65 ( & V_11 -> V_111 , & V_48 -> V_127 [ V_31 ] ) ;
F_66 ( V_123 , & V_48 -> V_128 ) ;
}
static struct V_1 * F_67 ( struct V_102 * V_48 )
{
return F_68 ( V_48 -> V_127 [ V_48 -> V_125 ] . V_129 ,
struct V_1 , V_111 ) ;
}
static void F_69 ( struct V_102 * V_48 )
{
struct V_1 * V_11 = F_67 ( V_48 ) ;
F_30 ( ! V_11 ) ;
F_70 ( & V_11 -> V_111 ) ;
if ( F_71 ( & V_48 -> V_127 [ V_48 -> V_125 ] ) )
F_72 ( 0 , & V_48 -> V_128 ) ;
}
static struct V_1 * F_73 ( struct V_102 * V_48 )
{
unsigned int V_31 ;
F_10 ( L_7 ,
V_48 -> V_19 , V_48 -> V_128 ) ;
if ( V_48 -> V_128 == 0 )
return NULL ;
V_31 = F_57 ( V_48 -> V_128 ) ;
if ( V_31 > 0 ) {
V_48 -> V_125 = ( V_48 -> V_125 + V_31 ) % V_126 ;
V_48 -> V_128 >>= V_31 ;
}
return F_67 ( V_48 ) ;
}
static void F_74 ( struct V_102 * V_48 , T_2 V_122 )
{
unsigned int V_31 = ( V_48 -> V_106 - V_122 ) >> V_48 -> V_124 ;
V_48 -> V_128 <<= V_31 ;
V_48 -> V_125 = ( V_48 -> V_125 - V_31 ) % V_126 ;
}
static void F_75 ( struct V_5 * V_6 , T_2 V_119 )
{
struct V_102 * V_48 ;
unsigned long V_130 ;
V_130 = V_6 -> V_109 [ V_118 ] | V_6 -> V_109 [ V_117 ] ;
if ( V_130 ) {
if ( ! V_6 -> V_109 [ V_110 ] ) {
V_48 = F_56 ( V_6 , V_130 ) ;
if ( F_54 ( V_48 -> V_106 , V_6 -> V_107 ) )
V_6 -> V_107 = V_48 -> V_106 ;
}
F_62 ( V_6 , V_119 ) ;
}
}
static unsigned int F_76 ( struct V_2 * V_3 )
{
struct V_60 * V_61 ;
V_61 = V_3 -> V_131 -> V_132 ( V_3 ) ;
return V_61 ? F_77 ( V_61 ) : 0 ;
}
static bool F_78 ( struct V_102 * V_48 , struct V_1 * V_11 )
{
unsigned int V_12 = F_76 ( V_11 -> V_13 ) ;
V_11 -> V_106 = V_11 -> V_112 ;
if ( ! V_12 )
F_69 ( V_48 ) ;
else {
T_2 V_122 ;
V_11 -> V_112 = V_11 -> V_106 + ( T_2 ) V_12 * V_11 -> V_15 ;
V_122 = F_55 ( V_11 -> V_106 , V_48 -> V_124 ) ;
if ( V_122 == V_48 -> V_106 )
return false ;
F_69 ( V_48 ) ;
F_64 ( V_48 , V_11 , V_122 ) ;
}
return true ;
}
static struct V_60 * F_79 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_102 * V_48 ;
struct V_1 * V_11 ;
struct V_60 * V_61 ;
unsigned int V_12 ;
T_2 V_119 ;
if ( ! V_6 -> V_109 [ V_110 ] )
return NULL ;
V_48 = F_56 ( V_6 , V_6 -> V_109 [ V_110 ] ) ;
V_11 = F_67 ( V_48 ) ;
V_61 = F_80 ( V_11 -> V_13 ) ;
if ( ! V_61 ) {
F_81 ( 1 , L_8 ) ;
return NULL ;
}
V_3 -> V_6 . V_14 -- ;
F_82 ( V_3 , V_61 ) ;
V_119 = V_6 -> V_107 ;
V_12 = F_77 ( V_61 ) ;
V_6 -> V_107 += ( T_2 ) V_12 * V_133 ;
F_10 ( L_9 ,
V_12 , ( unsigned long long ) V_11 -> V_112 , ( unsigned long long ) V_6 -> V_107 ) ;
if ( F_78 ( V_48 , V_11 ) ) {
T_2 V_116 = V_48 -> V_112 ;
V_11 = F_73 ( V_48 ) ;
if ( ! V_11 )
F_72 ( V_48 -> V_19 , & V_6 -> V_109 [ V_110 ] ) ;
else {
T_2 V_122 = F_55 ( V_11 -> V_106 , V_48 -> V_124 ) ;
unsigned int V_134 ;
if ( V_48 -> V_106 == V_122 )
goto V_135;
V_48 -> V_106 = V_122 ;
V_48 -> V_112 = V_122 + ( 2ULL << V_48 -> V_124 ) ;
F_72 ( V_48 -> V_19 , & V_6 -> V_109 [ V_110 ] ) ;
V_134 = F_59 ( V_6 , V_48 ) ;
F_66 ( V_48 -> V_19 , & V_6 -> V_109 [ V_134 ] ) ;
}
F_61 ( V_6 , V_48 -> V_19 , V_116 ) ;
}
V_135:
F_75 ( V_6 , V_119 ) ;
return V_61 ;
}
static void F_83 ( struct V_5 * V_6 , struct V_1 * V_11 )
{
unsigned long V_108 ;
T_2 V_136 , V_137 ;
int V_124 = V_11 -> V_48 -> V_124 ;
V_137 = F_55 ( V_11 -> V_112 , V_124 ) ;
V_136 = F_55 ( V_6 -> V_107 , V_124 ) + ( 1ULL << V_124 ) ;
if ( ! F_54 ( V_11 -> V_112 , V_6 -> V_107 ) || F_54 ( V_137 , V_136 ) ) {
V_108 = F_58 ( V_6 -> V_109 [ V_110 ] , V_11 -> V_48 -> V_19 ) ;
if ( V_108 ) {
struct V_102 * V_111 = F_56 ( V_6 , V_108 ) ;
if ( F_54 ( V_137 , V_111 -> V_112 ) ) {
V_11 -> V_106 = V_111 -> V_112 ;
return;
}
}
V_11 -> V_106 = V_6 -> V_107 ;
} else
V_11 -> V_106 = V_11 -> V_112 ;
}
static int F_84 ( struct V_60 * V_61 , struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_102 * V_48 ;
struct V_1 * V_11 ;
int V_32 ;
T_2 V_122 ;
int V_134 ;
V_11 = F_50 ( V_61 , V_3 , & V_32 ) ;
if ( V_11 == NULL ) {
if ( V_32 & V_91 )
V_3 -> V_76 . V_138 ++ ;
F_85 ( V_61 ) ;
return V_32 ;
}
F_10 ( L_10 , V_11 -> V_10 . V_4 ) ;
V_32 = F_86 ( V_61 , V_11 -> V_13 ) ;
if ( F_87 ( V_32 != V_90 ) ) {
F_10 ( L_11 , V_32 ) ;
if ( F_88 ( V_32 ) ) {
V_11 -> V_76 . V_138 ++ ;
V_3 -> V_76 . V_138 ++ ;
}
return V_32 ;
}
F_89 ( & V_11 -> V_43 , V_61 ) ;
++ V_3 -> V_6 . V_14 ;
if ( V_11 -> V_13 -> V_6 . V_14 != 1 )
return V_32 ;
V_48 = V_11 -> V_48 ;
F_83 ( V_6 , V_11 ) ;
V_11 -> V_112 = V_11 -> V_106 + ( T_2 ) F_77 ( V_61 ) * V_11 -> V_15 ;
V_122 = F_55 ( V_11 -> V_106 , V_48 -> V_124 ) ;
if ( V_48 -> V_128 ) {
if ( ! F_54 ( V_48 -> V_106 , V_11 -> V_106 ) )
goto V_139;
F_74 ( V_48 , V_122 ) ;
F_72 ( V_48 -> V_19 , & V_6 -> V_109 [ V_118 ] ) ;
F_72 ( V_48 -> V_19 , & V_6 -> V_109 [ V_117 ] ) ;
} else if ( ! V_6 -> V_109 [ V_110 ] && F_54 ( V_122 , V_6 -> V_107 ) )
V_6 -> V_107 = V_122 ;
V_48 -> V_106 = V_122 ;
V_48 -> V_112 = V_122 + ( 2ULL << V_48 -> V_124 ) ;
V_134 = F_59 ( V_6 , V_48 ) ;
F_66 ( V_48 -> V_19 , & V_6 -> V_109 [ V_134 ] ) ;
F_10 ( L_12 ,
V_134 , V_6 -> V_109 [ V_134 ] ,
( unsigned long long ) V_11 -> V_106 ,
( unsigned long long ) V_11 -> V_112 ,
( unsigned long long ) V_6 -> V_107 ) ;
V_139:
F_64 ( V_48 , V_11 , V_122 ) ;
return V_32 ;
}
static void F_90 ( struct V_5 * V_6 , struct V_102 * V_48 ,
struct V_1 * V_11 )
{
unsigned int V_31 , V_140 ;
T_2 V_122 ;
V_122 = F_55 ( V_11 -> V_106 , V_48 -> V_124 ) ;
V_140 = ( V_122 - V_48 -> V_106 ) >> V_48 -> V_124 ;
V_31 = ( V_48 -> V_125 + V_140 ) % V_126 ;
F_70 ( & V_11 -> V_111 ) ;
if ( F_71 ( & V_48 -> V_127 [ V_31 ] ) )
F_72 ( V_140 , & V_48 -> V_128 ) ;
}
static void F_91 ( struct V_5 * V_6 , struct V_1 * V_11 )
{
struct V_102 * V_48 = V_11 -> V_48 ;
unsigned long V_108 ;
T_2 V_122 ;
int V_134 ;
V_11 -> V_112 = V_11 -> V_106 ;
F_90 ( V_6 , V_48 , V_11 ) ;
if ( ! V_48 -> V_128 ) {
F_72 ( V_48 -> V_19 , & V_6 -> V_109 [ V_118 ] ) ;
F_72 ( V_48 -> V_19 , & V_6 -> V_109 [ V_113 ] ) ;
F_72 ( V_48 -> V_19 , & V_6 -> V_109 [ V_117 ] ) ;
if ( F_92 ( V_48 -> V_19 , & V_6 -> V_109 [ V_110 ] ) &&
! ( V_6 -> V_109 [ V_110 ] & ~ ( ( 1UL << V_48 -> V_19 ) - 1 ) ) ) {
V_108 = V_6 -> V_109 [ V_110 ] & ( ( 1UL << V_48 -> V_19 ) - 1 ) ;
if ( V_108 )
V_108 = ~ ( ( 1UL << F_9 ( V_108 ) ) - 1 ) ;
else
V_108 = ~ 0UL ;
F_60 ( V_6 , V_108 , V_113 , V_110 ) ;
F_60 ( V_6 , V_108 , V_117 , V_118 ) ;
}
F_72 ( V_48 -> V_19 , & V_6 -> V_109 [ V_110 ] ) ;
} else if ( F_71 ( & V_48 -> V_127 [ V_48 -> V_125 ] ) ) {
V_11 = F_73 ( V_48 ) ;
V_122 = F_55 ( V_11 -> V_106 , V_48 -> V_124 ) ;
if ( V_48 -> V_106 != V_122 ) {
F_72 ( V_48 -> V_19 , & V_6 -> V_109 [ V_110 ] ) ;
F_72 ( V_48 -> V_19 , & V_6 -> V_109 [ V_118 ] ) ;
F_72 ( V_48 -> V_19 , & V_6 -> V_109 [ V_113 ] ) ;
F_72 ( V_48 -> V_19 , & V_6 -> V_109 [ V_117 ] ) ;
V_48 -> V_106 = V_122 ;
V_48 -> V_112 = V_122 + ( 2ULL << V_48 -> V_124 ) ;
V_134 = F_59 ( V_6 , V_48 ) ;
F_66 ( V_48 -> V_19 , & V_6 -> V_109 [ V_134 ] ) ;
}
}
F_75 ( V_6 , V_6 -> V_107 ) ;
}
static void F_93 ( struct V_2 * V_3 , unsigned long V_26 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 = (struct V_1 * ) V_26 ;
if ( V_11 -> V_13 -> V_6 . V_14 == 0 )
F_91 ( V_6 , V_11 ) ;
}
static unsigned int F_94 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_102 * V_48 ;
unsigned int V_31 , V_141 , V_12 ;
for ( V_31 = 0 ; V_31 <= V_142 ; V_31 ++ ) {
V_48 = & V_6 -> V_49 [ V_31 ] ;
for ( V_141 = 0 ; V_141 < V_126 ; V_141 ++ ) {
struct V_1 * V_11 ;
struct V_78 * V_79 ;
F_49 (cl, n, &grp->slots[j], next) {
if ( ! V_11 -> V_13 -> V_131 -> V_143 )
continue;
V_12 = V_11 -> V_13 -> V_131 -> V_143 ( V_11 -> V_13 ) ;
if ( V_12 > 0 ) {
V_3 -> V_6 . V_14 -- ;
if ( ! V_11 -> V_13 -> V_6 . V_14 )
F_91 ( V_6 , V_11 ) ;
return V_12 ;
}
}
}
}
return 0 ;
}
static int F_95 ( struct V_2 * V_3 , struct V_24 * V_144 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_102 * V_48 ;
int V_31 , V_141 , V_32 ;
V_32 = F_96 ( & V_6 -> V_9 ) ;
if ( V_32 < 0 )
return V_32 ;
for ( V_31 = 0 ; V_31 <= V_142 ; V_31 ++ ) {
V_48 = & V_6 -> V_49 [ V_31 ] ;
V_48 -> V_19 = V_31 ;
V_48 -> V_124 = V_41 + V_145
- ( V_142 - V_31 ) ;
for ( V_141 = 0 ; V_141 < V_126 ; V_141 ++ )
F_97 ( & V_48 -> V_127 [ V_141 ] ) ;
}
return 0 ;
}
static void F_98 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_102 * V_48 ;
struct V_1 * V_11 ;
struct V_78 * V_79 , * V_146 ;
unsigned int V_31 , V_141 ;
for ( V_31 = 0 ; V_31 <= V_142 ; V_31 ++ ) {
V_48 = & V_6 -> V_49 [ V_31 ] ;
for ( V_141 = 0 ; V_141 < V_126 ; V_141 ++ ) {
F_99 (cl, n, tmp,
&grp->slots[j], next) {
F_91 ( V_6 , V_11 ) ;
}
}
}
for ( V_31 = 0 ; V_31 < V_6 -> V_9 . V_81 ; V_31 ++ ) {
F_49 (cl, n, &q->clhash.hash[i], common.hnode)
F_6 ( V_11 -> V_13 ) ;
}
V_3 -> V_6 . V_14 = 0 ;
}
static void F_100 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_78 * V_79 , * V_111 ;
unsigned int V_31 ;
F_101 ( & V_6 -> V_56 ) ;
for ( V_31 = 0 ; V_31 < V_6 -> V_9 . V_81 ; V_31 ++ ) {
F_99 (cl, n, next, &q->clhash.hash[i],
common.hnode) {
F_26 ( V_3 , V_11 ) ;
}
}
F_102 ( & V_6 -> V_9 ) ;
}
static int T_3 F_103 ( void )
{
return F_104 ( & V_147 ) ;
}
static void T_4 F_105 ( void )
{
F_106 ( & V_147 ) ;
}
