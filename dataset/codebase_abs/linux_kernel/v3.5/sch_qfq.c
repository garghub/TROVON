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
int V_33 ;
if ( V_25 [ V_34 ] == NULL ) {
F_12 ( L_2 ) ;
return - V_35 ;
}
V_32 = F_13 ( V_27 , V_28 , V_25 [ V_34 ] , V_36 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_27 [ V_37 ] ) {
V_29 = F_14 ( V_27 [ V_37 ] ) ;
if ( ! V_29 || V_29 > ( 1UL << V_38 ) ) {
F_12 ( L_3 , V_29 ) ;
return - V_35 ;
}
} else
V_29 = 1 ;
V_15 = V_22 / V_29 ;
V_29 = V_22 / V_15 ;
V_33 = V_29 - ( V_11 ? V_22 / V_11 -> V_15 : 0 ) ;
if ( V_6 -> V_39 + V_33 > V_40 ) {
F_12 ( L_4 ,
V_33 , V_6 -> V_39 ) ;
return - V_35 ;
}
if ( V_27 [ V_41 ] ) {
V_30 = F_14 ( V_27 [ V_41 ] ) ;
if ( ! V_30 || V_30 > ( 1UL << V_42 ) ) {
F_12 ( L_5 , V_30 ) ;
return - V_35 ;
}
} else
V_30 = 1UL << V_42 ;
if ( V_11 != NULL ) {
if ( V_25 [ V_43 ] ) {
V_32 = F_15 ( & V_11 -> V_44 , & V_11 -> V_45 ,
F_16 ( V_3 ) ,
V_25 [ V_43 ] ) ;
if ( V_32 )
return V_32 ;
}
if ( V_15 != V_11 -> V_15 ) {
F_17 ( V_3 ) ;
V_6 -> V_39 += V_33 ;
V_11 -> V_15 = V_15 ;
F_18 ( V_3 ) ;
}
return 0 ;
}
V_11 = F_19 ( sizeof( struct V_1 ) , V_46 ) ;
if ( V_11 == NULL )
return - V_47 ;
V_11 -> V_48 = 1 ;
V_11 -> V_10 . V_4 = V_4 ;
V_11 -> V_30 = V_30 ;
V_11 -> V_15 = V_15 ;
V_31 = F_8 ( V_11 -> V_15 , V_11 -> V_30 ) ;
V_11 -> V_49 = & V_6 -> V_50 [ V_31 ] ;
V_11 -> V_13 = F_20 ( V_3 -> V_51 ,
& V_52 , V_4 ) ;
if ( V_11 -> V_13 == NULL )
V_11 -> V_13 = & V_53 ;
if ( V_25 [ V_43 ] ) {
V_32 = F_21 ( & V_11 -> V_44 , & V_11 -> V_45 ,
F_16 ( V_3 ) ,
V_25 [ V_43 ] ) ;
if ( V_32 ) {
F_22 ( V_11 -> V_13 ) ;
F_23 ( V_11 ) ;
return V_32 ;
}
}
V_6 -> V_39 += V_29 ;
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
V_6 -> V_39 -= V_22 / V_11 -> V_15 ;
V_11 -> V_15 = 0 ;
}
F_27 ( & V_11 -> V_44 , & V_11 -> V_45 ) ;
F_22 ( V_11 -> V_13 ) ;
F_23 ( V_11 ) ;
}
static int F_28 ( struct V_2 * V_3 , unsigned long V_26 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 = (struct V_1 * ) V_26 ;
if ( V_11 -> V_54 > 0 )
return - V_55 ;
F_17 ( V_3 ) ;
F_5 ( V_11 ) ;
F_29 ( & V_6 -> V_9 , & V_11 -> V_10 ) ;
F_30 ( -- V_11 -> V_48 == 0 ) ;
F_18 ( V_3 ) ;
return 0 ;
}
static unsigned long F_31 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_11 = F_1 ( V_3 , V_4 ) ;
if ( V_11 != NULL )
V_11 -> V_48 ++ ;
return ( unsigned long ) V_11 ;
}
static void F_32 ( struct V_2 * V_3 , unsigned long V_26 )
{
struct V_1 * V_11 = (struct V_1 * ) V_26 ;
if ( -- V_11 -> V_48 == 0 )
F_26 ( V_3 , V_11 ) ;
}
static struct V_56 * * F_33 ( struct V_2 * V_3 , unsigned long V_11 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
if ( V_11 )
return NULL ;
return & V_6 -> V_57 ;
}
static unsigned long F_34 ( struct V_2 * V_3 , unsigned long V_58 ,
T_1 V_4 )
{
struct V_1 * V_11 = F_1 ( V_3 , V_4 ) ;
if ( V_11 != NULL )
V_11 -> V_54 ++ ;
return ( unsigned long ) V_11 ;
}
static void F_35 ( struct V_2 * V_3 , unsigned long V_26 )
{
struct V_1 * V_11 = (struct V_1 * ) V_26 ;
V_11 -> V_54 -- ;
}
static int F_36 ( struct V_2 * V_3 , unsigned long V_26 ,
struct V_2 * V_59 , struct V_2 * * V_60 )
{
struct V_1 * V_11 = (struct V_1 * ) V_26 ;
if ( V_59 == NULL ) {
V_59 = F_20 ( V_3 -> V_51 ,
& V_52 , V_11 -> V_10 . V_4 ) ;
if ( V_59 == NULL )
V_59 = & V_53 ;
}
F_17 ( V_3 ) ;
F_5 ( V_11 ) ;
* V_60 = V_11 -> V_13 ;
V_11 -> V_13 = V_59 ;
F_18 ( V_3 ) ;
return 0 ;
}
static struct V_2 * F_37 ( struct V_2 * V_3 , unsigned long V_26 )
{
struct V_1 * V_11 = (struct V_1 * ) V_26 ;
return V_11 -> V_13 ;
}
static int F_38 ( struct V_2 * V_3 , unsigned long V_26 ,
struct V_61 * V_62 , struct V_63 * V_64 )
{
struct V_1 * V_11 = (struct V_1 * ) V_26 ;
struct V_24 * V_65 ;
V_64 -> V_66 = V_67 ;
V_64 -> V_68 = V_11 -> V_10 . V_4 ;
V_64 -> V_69 = V_11 -> V_13 -> V_70 ;
V_65 = F_39 ( V_62 , V_34 ) ;
if ( V_65 == NULL )
goto V_71;
if ( F_40 ( V_62 , V_37 , V_22 / V_11 -> V_15 ) ||
F_40 ( V_62 , V_41 , V_11 -> V_30 ) )
goto V_71;
return F_41 ( V_62 , V_65 ) ;
V_71:
F_42 ( V_62 , V_65 ) ;
return - V_72 ;
}
static int F_43 ( struct V_2 * V_3 , unsigned long V_26 ,
struct V_73 * V_74 )
{
struct V_1 * V_11 = (struct V_1 * ) V_26 ;
struct V_75 V_76 ;
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
V_11 -> V_13 -> V_77 . V_14 = V_11 -> V_13 -> V_6 . V_14 ;
V_76 . V_29 = V_22 / V_11 -> V_15 ;
V_76 . V_30 = V_11 -> V_30 ;
if ( F_44 ( V_74 , & V_11 -> V_44 ) < 0 ||
F_45 ( V_74 , & V_11 -> V_44 , & V_11 -> V_45 ) < 0 ||
F_46 ( V_74 , & V_11 -> V_13 -> V_77 ) < 0 )
return - 1 ;
return F_47 ( V_74 , & V_76 , sizeof( V_76 ) ) ;
}
static void F_48 ( struct V_2 * V_3 , struct V_78 * V_26 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_79 * V_80 ;
unsigned int V_31 ;
if ( V_26 -> V_81 )
return;
for ( V_31 = 0 ; V_31 < V_6 -> V_9 . V_82 ; V_31 ++ ) {
F_49 (cl, n, &q->clhash.hash[i], common.hnode) {
if ( V_26 -> V_83 < V_26 -> V_84 ) {
V_26 -> V_83 ++ ;
continue;
}
if ( V_26 -> V_85 ( V_3 , ( unsigned long ) V_11 , V_26 ) < 0 ) {
V_26 -> V_81 = 1 ;
return;
}
V_26 -> V_83 ++ ;
}
}
}
static struct V_1 * F_50 ( struct V_61 * V_62 , struct V_2 * V_3 ,
int * V_86 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_87 V_88 ;
int V_89 ;
if ( F_51 ( V_62 -> V_90 ^ V_3 -> V_70 ) == 0 ) {
F_10 ( L_6 , V_62 -> V_90 ) ;
V_11 = F_1 ( V_3 , V_62 -> V_90 ) ;
if ( V_11 != NULL )
return V_11 ;
}
* V_86 = V_91 | V_92 ;
V_89 = F_52 ( V_62 , V_6 -> V_57 , & V_88 ) ;
if ( V_89 >= 0 ) {
#ifdef F_53
switch ( V_89 ) {
case V_93 :
case V_94 :
* V_86 = V_91 | V_95 ;
case V_96 :
return NULL ;
}
#endif
V_11 = (struct V_1 * ) V_88 . V_97 ;
if ( V_11 == NULL )
V_11 = F_1 ( V_3 , V_88 . V_4 ) ;
return V_11 ;
}
return NULL ;
}
static inline int F_54 ( T_2 V_98 , T_2 V_99 )
{
return ( V_100 ) ( V_98 - V_99 ) > 0 ;
}
static inline T_2 F_55 ( T_2 V_101 , unsigned int V_102 )
{
return V_101 & ~ ( ( 1ULL << V_102 ) - 1 ) ;
}
static inline struct V_103 * F_56 ( struct V_5 * V_6 ,
unsigned long V_104 )
{
int V_19 = F_57 ( V_104 ) ;
return & V_6 -> V_50 [ V_19 ] ;
}
static inline unsigned long F_58 ( unsigned long V_104 , int V_105 )
{
return V_104 & ~ ( ( 1UL << V_105 ) - 1 ) ;
}
static int F_59 ( struct V_5 * V_6 , const struct V_103 * V_49 )
{
unsigned int V_106 = F_54 ( V_49 -> V_107 , V_6 -> V_108 ) ;
unsigned long V_109 = F_58 ( V_6 -> V_110 [ V_111 ] , V_49 -> V_19 ) ;
struct V_103 * V_112 ;
if ( V_109 ) {
V_112 = F_56 ( V_6 , V_109 ) ;
if ( F_54 ( V_49 -> V_113 , V_112 -> V_113 ) )
V_106 |= V_114 ;
}
return V_106 ;
}
static inline void F_60 ( struct V_5 * V_6 , unsigned long V_109 ,
int V_115 , int V_116 )
{
V_6 -> V_110 [ V_116 ] |= V_6 -> V_110 [ V_115 ] & V_109 ;
V_6 -> V_110 [ V_115 ] &= ~ V_109 ;
}
static void F_61 ( struct V_5 * V_6 , int V_19 , T_2 V_117 )
{
unsigned long V_109 = F_58 ( V_6 -> V_110 [ V_111 ] , V_19 + 1 ) ;
struct V_103 * V_112 ;
if ( V_109 ) {
V_112 = F_56 ( V_6 , V_109 ) ;
if ( ! F_54 ( V_112 -> V_113 , V_117 ) )
return;
}
V_109 = ( 1UL << V_19 ) - 1 ;
F_60 ( V_6 , V_109 , V_114 , V_111 ) ;
F_60 ( V_6 , V_109 , V_118 , V_119 ) ;
}
static void F_62 ( struct V_5 * V_6 , T_2 V_120 )
{
unsigned long V_121 = V_6 -> V_108 >> V_20 ;
unsigned long V_122 = V_120 >> V_20 ;
if ( V_121 != V_122 ) {
unsigned long V_109 = ( 1UL << F_63 ( V_121 ^ V_122 ) ) - 1 ;
F_60 ( V_6 , V_109 , V_119 , V_111 ) ;
F_60 ( V_6 , V_109 , V_118 , V_114 ) ;
}
}
static void F_64 ( struct V_103 * V_49 , struct V_1 * V_11 ,
T_2 V_123 )
{
T_2 V_124 = ( V_123 - V_49 -> V_107 ) >> V_49 -> V_125 ;
unsigned int V_31 = ( V_49 -> V_126 + V_124 ) % V_127 ;
F_65 ( & V_11 -> V_112 , & V_49 -> V_128 [ V_31 ] ) ;
F_66 ( V_124 , & V_49 -> V_129 ) ;
}
static struct V_1 * F_67 ( struct V_103 * V_49 )
{
return F_68 ( V_49 -> V_128 [ V_49 -> V_126 ] . V_130 ,
struct V_1 , V_112 ) ;
}
static void F_69 ( struct V_103 * V_49 )
{
struct V_1 * V_11 = F_67 ( V_49 ) ;
F_30 ( ! V_11 ) ;
F_70 ( & V_11 -> V_112 ) ;
if ( F_71 ( & V_49 -> V_128 [ V_49 -> V_126 ] ) )
F_72 ( 0 , & V_49 -> V_129 ) ;
}
static struct V_1 * F_73 ( struct V_103 * V_49 )
{
unsigned int V_31 ;
F_10 ( L_7 ,
V_49 -> V_19 , V_49 -> V_129 ) ;
if ( V_49 -> V_129 == 0 )
return NULL ;
V_31 = F_57 ( V_49 -> V_129 ) ;
if ( V_31 > 0 ) {
V_49 -> V_126 = ( V_49 -> V_126 + V_31 ) % V_127 ;
V_49 -> V_129 >>= V_31 ;
}
return F_67 ( V_49 ) ;
}
static void F_74 ( struct V_103 * V_49 , T_2 V_123 )
{
unsigned int V_31 = ( V_49 -> V_107 - V_123 ) >> V_49 -> V_125 ;
V_49 -> V_129 <<= V_31 ;
V_49 -> V_126 = ( V_49 -> V_126 - V_31 ) % V_127 ;
}
static void F_75 ( struct V_5 * V_6 , T_2 V_120 )
{
struct V_103 * V_49 ;
unsigned long V_131 ;
V_131 = V_6 -> V_110 [ V_119 ] | V_6 -> V_110 [ V_118 ] ;
if ( V_131 ) {
if ( ! V_6 -> V_110 [ V_111 ] ) {
V_49 = F_56 ( V_6 , V_131 ) ;
if ( F_54 ( V_49 -> V_107 , V_6 -> V_108 ) )
V_6 -> V_108 = V_49 -> V_107 ;
}
F_62 ( V_6 , V_120 ) ;
}
}
static unsigned int F_76 ( struct V_2 * V_3 )
{
struct V_61 * V_62 ;
V_62 = V_3 -> V_132 -> V_133 ( V_3 ) ;
return V_62 ? F_77 ( V_62 ) : 0 ;
}
static bool F_78 ( struct V_103 * V_49 , struct V_1 * V_11 )
{
unsigned int V_12 = F_76 ( V_11 -> V_13 ) ;
V_11 -> V_107 = V_11 -> V_113 ;
if ( ! V_12 )
F_69 ( V_49 ) ;
else {
T_2 V_123 ;
V_11 -> V_113 = V_11 -> V_107 + ( T_2 ) V_12 * V_11 -> V_15 ;
V_123 = F_55 ( V_11 -> V_107 , V_49 -> V_125 ) ;
if ( V_123 == V_49 -> V_107 )
return false ;
F_69 ( V_49 ) ;
F_64 ( V_49 , V_11 , V_123 ) ;
}
return true ;
}
static struct V_61 * F_79 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_103 * V_49 ;
struct V_1 * V_11 ;
struct V_61 * V_62 ;
unsigned int V_12 ;
T_2 V_120 ;
if ( ! V_6 -> V_110 [ V_111 ] )
return NULL ;
V_49 = F_56 ( V_6 , V_6 -> V_110 [ V_111 ] ) ;
V_11 = F_67 ( V_49 ) ;
V_62 = F_80 ( V_11 -> V_13 ) ;
if ( ! V_62 ) {
F_81 ( 1 , L_8 ) ;
return NULL ;
}
V_3 -> V_6 . V_14 -- ;
F_82 ( V_3 , V_62 ) ;
V_120 = V_6 -> V_108 ;
V_12 = F_77 ( V_62 ) ;
V_6 -> V_108 += ( T_2 ) V_12 * V_134 ;
F_10 ( L_9 ,
V_12 , ( unsigned long long ) V_11 -> V_113 , ( unsigned long long ) V_6 -> V_108 ) ;
if ( F_78 ( V_49 , V_11 ) ) {
T_2 V_117 = V_49 -> V_113 ;
V_11 = F_73 ( V_49 ) ;
if ( ! V_11 )
F_72 ( V_49 -> V_19 , & V_6 -> V_110 [ V_111 ] ) ;
else {
T_2 V_123 = F_55 ( V_11 -> V_107 , V_49 -> V_125 ) ;
unsigned int V_135 ;
if ( V_49 -> V_107 == V_123 )
goto V_136;
V_49 -> V_107 = V_123 ;
V_49 -> V_113 = V_123 + ( 2ULL << V_49 -> V_125 ) ;
F_72 ( V_49 -> V_19 , & V_6 -> V_110 [ V_111 ] ) ;
V_135 = F_59 ( V_6 , V_49 ) ;
F_66 ( V_49 -> V_19 , & V_6 -> V_110 [ V_135 ] ) ;
}
F_61 ( V_6 , V_49 -> V_19 , V_117 ) ;
}
V_136:
F_75 ( V_6 , V_120 ) ;
return V_62 ;
}
static void F_83 ( struct V_5 * V_6 , struct V_1 * V_11 )
{
unsigned long V_109 ;
T_2 V_137 , V_138 ;
int V_125 = V_11 -> V_49 -> V_125 ;
V_138 = F_55 ( V_11 -> V_113 , V_125 ) ;
V_137 = F_55 ( V_6 -> V_108 , V_125 ) + ( 1ULL << V_125 ) ;
if ( ! F_54 ( V_11 -> V_113 , V_6 -> V_108 ) || F_54 ( V_138 , V_137 ) ) {
V_109 = F_58 ( V_6 -> V_110 [ V_111 ] , V_11 -> V_49 -> V_19 ) ;
if ( V_109 ) {
struct V_103 * V_112 = F_56 ( V_6 , V_109 ) ;
if ( F_54 ( V_138 , V_112 -> V_113 ) ) {
V_11 -> V_107 = V_112 -> V_113 ;
return;
}
}
V_11 -> V_107 = V_6 -> V_108 ;
} else
V_11 -> V_107 = V_11 -> V_113 ;
}
static int F_84 ( struct V_61 * V_62 , struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_103 * V_49 ;
struct V_1 * V_11 ;
int V_32 ;
T_2 V_123 ;
int V_135 ;
V_11 = F_50 ( V_62 , V_3 , & V_32 ) ;
if ( V_11 == NULL ) {
if ( V_32 & V_92 )
V_3 -> V_77 . V_139 ++ ;
F_85 ( V_62 ) ;
return V_32 ;
}
F_10 ( L_10 , V_11 -> V_10 . V_4 ) ;
V_32 = F_86 ( V_62 , V_11 -> V_13 ) ;
if ( F_87 ( V_32 != V_91 ) ) {
F_10 ( L_11 , V_32 ) ;
if ( F_88 ( V_32 ) ) {
V_11 -> V_77 . V_139 ++ ;
V_3 -> V_77 . V_139 ++ ;
}
return V_32 ;
}
F_89 ( & V_11 -> V_44 , V_62 ) ;
++ V_3 -> V_6 . V_14 ;
if ( V_11 -> V_13 -> V_6 . V_14 != 1 )
return V_32 ;
V_49 = V_11 -> V_49 ;
F_83 ( V_6 , V_11 ) ;
V_11 -> V_113 = V_11 -> V_107 + ( T_2 ) F_77 ( V_62 ) * V_11 -> V_15 ;
V_123 = F_55 ( V_11 -> V_107 , V_49 -> V_125 ) ;
if ( V_49 -> V_129 ) {
if ( ! F_54 ( V_49 -> V_107 , V_11 -> V_107 ) )
goto V_140;
F_74 ( V_49 , V_123 ) ;
F_72 ( V_49 -> V_19 , & V_6 -> V_110 [ V_119 ] ) ;
F_72 ( V_49 -> V_19 , & V_6 -> V_110 [ V_118 ] ) ;
} else if ( ! V_6 -> V_110 [ V_111 ] && F_54 ( V_123 , V_6 -> V_108 ) )
V_6 -> V_108 = V_123 ;
V_49 -> V_107 = V_123 ;
V_49 -> V_113 = V_123 + ( 2ULL << V_49 -> V_125 ) ;
V_135 = F_59 ( V_6 , V_49 ) ;
F_66 ( V_49 -> V_19 , & V_6 -> V_110 [ V_135 ] ) ;
F_10 ( L_12 ,
V_135 , V_6 -> V_110 [ V_135 ] ,
( unsigned long long ) V_11 -> V_107 ,
( unsigned long long ) V_11 -> V_113 ,
( unsigned long long ) V_6 -> V_108 ) ;
V_140:
F_64 ( V_49 , V_11 , V_123 ) ;
return V_32 ;
}
static void F_90 ( struct V_5 * V_6 , struct V_103 * V_49 ,
struct V_1 * V_11 )
{
unsigned int V_31 , V_141 ;
T_2 V_123 ;
V_123 = F_55 ( V_11 -> V_107 , V_49 -> V_125 ) ;
V_141 = ( V_123 - V_49 -> V_107 ) >> V_49 -> V_125 ;
V_31 = ( V_49 -> V_126 + V_141 ) % V_127 ;
F_70 ( & V_11 -> V_112 ) ;
if ( F_71 ( & V_49 -> V_128 [ V_31 ] ) )
F_72 ( V_141 , & V_49 -> V_129 ) ;
}
static void F_91 ( struct V_5 * V_6 , struct V_1 * V_11 )
{
struct V_103 * V_49 = V_11 -> V_49 ;
unsigned long V_109 ;
T_2 V_123 ;
int V_135 ;
V_11 -> V_113 = V_11 -> V_107 ;
F_90 ( V_6 , V_49 , V_11 ) ;
if ( ! V_49 -> V_129 ) {
F_72 ( V_49 -> V_19 , & V_6 -> V_110 [ V_119 ] ) ;
F_72 ( V_49 -> V_19 , & V_6 -> V_110 [ V_114 ] ) ;
F_72 ( V_49 -> V_19 , & V_6 -> V_110 [ V_118 ] ) ;
if ( F_92 ( V_49 -> V_19 , & V_6 -> V_110 [ V_111 ] ) &&
! ( V_6 -> V_110 [ V_111 ] & ~ ( ( 1UL << V_49 -> V_19 ) - 1 ) ) ) {
V_109 = V_6 -> V_110 [ V_111 ] & ( ( 1UL << V_49 -> V_19 ) - 1 ) ;
if ( V_109 )
V_109 = ~ ( ( 1UL << F_9 ( V_109 ) ) - 1 ) ;
else
V_109 = ~ 0UL ;
F_60 ( V_6 , V_109 , V_114 , V_111 ) ;
F_60 ( V_6 , V_109 , V_118 , V_119 ) ;
}
F_72 ( V_49 -> V_19 , & V_6 -> V_110 [ V_111 ] ) ;
} else if ( F_71 ( & V_49 -> V_128 [ V_49 -> V_126 ] ) ) {
V_11 = F_73 ( V_49 ) ;
V_123 = F_55 ( V_11 -> V_107 , V_49 -> V_125 ) ;
if ( V_49 -> V_107 != V_123 ) {
F_72 ( V_49 -> V_19 , & V_6 -> V_110 [ V_111 ] ) ;
F_72 ( V_49 -> V_19 , & V_6 -> V_110 [ V_119 ] ) ;
F_72 ( V_49 -> V_19 , & V_6 -> V_110 [ V_114 ] ) ;
F_72 ( V_49 -> V_19 , & V_6 -> V_110 [ V_118 ] ) ;
V_49 -> V_107 = V_123 ;
V_49 -> V_113 = V_123 + ( 2ULL << V_49 -> V_125 ) ;
V_135 = F_59 ( V_6 , V_49 ) ;
F_66 ( V_49 -> V_19 , & V_6 -> V_110 [ V_135 ] ) ;
}
}
F_75 ( V_6 , V_6 -> V_108 ) ;
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
struct V_103 * V_49 ;
unsigned int V_31 , V_142 , V_12 ;
for ( V_31 = 0 ; V_31 <= V_143 ; V_31 ++ ) {
V_49 = & V_6 -> V_50 [ V_31 ] ;
for ( V_142 = 0 ; V_142 < V_127 ; V_142 ++ ) {
struct V_1 * V_11 ;
struct V_79 * V_80 ;
F_49 (cl, n, &grp->slots[j], next) {
if ( ! V_11 -> V_13 -> V_132 -> V_144 )
continue;
V_12 = V_11 -> V_13 -> V_132 -> V_144 ( V_11 -> V_13 ) ;
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
static int F_95 ( struct V_2 * V_3 , struct V_24 * V_145 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_103 * V_49 ;
int V_31 , V_142 , V_32 ;
V_32 = F_96 ( & V_6 -> V_9 ) ;
if ( V_32 < 0 )
return V_32 ;
for ( V_31 = 0 ; V_31 <= V_143 ; V_31 ++ ) {
V_49 = & V_6 -> V_50 [ V_31 ] ;
V_49 -> V_19 = V_31 ;
V_49 -> V_125 = V_42 + V_146
- ( V_143 - V_31 ) ;
for ( V_142 = 0 ; V_142 < V_127 ; V_142 ++ )
F_97 ( & V_49 -> V_128 [ V_142 ] ) ;
}
return 0 ;
}
static void F_98 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_103 * V_49 ;
struct V_1 * V_11 ;
struct V_79 * V_80 , * V_147 ;
unsigned int V_31 , V_142 ;
for ( V_31 = 0 ; V_31 <= V_143 ; V_31 ++ ) {
V_49 = & V_6 -> V_50 [ V_31 ] ;
for ( V_142 = 0 ; V_142 < V_127 ; V_142 ++ ) {
F_99 (cl, n, tmp,
&grp->slots[j], next) {
F_91 ( V_6 , V_11 ) ;
}
}
}
for ( V_31 = 0 ; V_31 < V_6 -> V_9 . V_82 ; V_31 ++ ) {
F_49 (cl, n, &q->clhash.hash[i], common.hnode)
F_6 ( V_11 -> V_13 ) ;
}
V_3 -> V_6 . V_14 = 0 ;
}
static void F_100 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_79 * V_80 , * V_112 ;
unsigned int V_31 ;
F_101 ( & V_6 -> V_57 ) ;
for ( V_31 = 0 ; V_31 < V_6 -> V_9 . V_82 ; V_31 ++ ) {
F_99 (cl, n, next, &q->clhash.hash[i],
common.hnode) {
F_26 ( V_3 , V_11 ) ;
}
}
F_102 ( & V_6 -> V_9 ) ;
}
static int T_3 F_103 ( void )
{
return F_104 ( & V_148 ) ;
}
static void T_4 F_105 ( void )
{
F_106 ( & V_148 ) ;
}
