static struct V_1 * F_1 ( struct V_2 * V_3 ,
enum V_4 V_5 ,
enum V_6 type )
{
if ( ! V_3 )
return NULL ;
if ( V_5 == V_7 )
return & V_3 -> V_8 ;
return & V_3 -> V_9 [ V_5 ] [ type ] ;
}
static inline struct V_2 * F_2 ( struct V_10 * V_11 )
{
return V_11 ? F_3 ( V_11 , struct V_2 , V_11 ) : NULL ;
}
static inline struct V_12 * F_4 ( struct V_2 * V_3 )
{
return F_5 ( & V_3 -> V_11 ) ;
}
static void F_6 ( struct V_13 * V_14 )
{
unsigned long long V_15 ;
if ( ! F_7 ( V_14 ) )
return;
V_15 = F_8 () ;
if ( F_9 ( V_15 , V_14 -> V_16 ) )
F_10 ( & V_14 -> V_17 ,
V_15 - V_14 -> V_16 ) ;
F_11 ( V_14 ) ;
}
static void F_12 ( struct V_2 * V_3 ,
struct V_2 * V_18 )
{
struct V_13 * V_14 = & V_3 -> V_14 ;
if ( F_7 ( V_14 ) )
return;
if ( V_3 == V_18 )
return;
V_14 -> V_16 = F_8 () ;
F_13 ( V_14 ) ;
}
static void F_14 ( struct V_13 * V_14 )
{
unsigned long long V_15 ;
if ( ! F_15 ( V_14 ) )
return;
V_15 = F_8 () ;
if ( F_9 ( V_15 , V_14 -> V_19 ) )
F_10 ( & V_14 -> V_20 ,
V_15 - V_14 -> V_19 ) ;
F_16 ( V_14 ) ;
}
static void F_17 ( struct V_2 * V_3 )
{
F_10 ( & V_3 -> V_14 . V_21 , 1 ) ;
}
static void F_18 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = & V_3 -> V_14 ;
if ( F_19 ( & V_14 -> V_22 ) )
return;
if ( F_15 ( V_14 ) )
return;
V_14 -> V_19 = F_8 () ;
F_20 ( V_14 ) ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = & V_3 -> V_14 ;
if ( F_22 ( V_14 ) ) {
unsigned long long V_15 = F_8 () ;
if ( F_9 ( V_15 , V_14 -> V_23 ) )
F_10 ( & V_14 -> V_24 ,
V_15 - V_14 -> V_23 ) ;
F_23 ( V_14 ) ;
}
}
static void F_24 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = & V_3 -> V_14 ;
F_25 ( F_22 ( V_14 ) ) ;
V_14 -> V_23 = F_8 () ;
F_26 ( V_14 ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = & V_3 -> V_14 ;
F_10 ( & V_14 -> V_25 ,
F_19 ( & V_14 -> V_22 ) ) ;
F_10 ( & V_14 -> V_26 , 1 ) ;
F_6 ( V_14 ) ;
}
static inline void F_12 ( struct V_2 * V_3 , struct V_2 * V_18 ) { }
static inline void F_14 ( struct V_13 * V_14 ) { }
static inline void F_17 ( struct V_2 * V_3 ) { }
static inline void F_18 ( struct V_2 * V_3 ) { }
static inline void F_21 ( struct V_2 * V_3 ) { }
static inline void F_24 ( struct V_2 * V_3 ) { }
static inline void F_27 ( struct V_2 * V_3 ) { }
static inline struct V_2 * F_28 ( struct V_12 * V_27 )
{
return F_2 ( F_29 ( V_27 , & V_28 ) ) ;
}
static inline void F_30 ( struct V_2 * V_3 )
{
return F_31 ( F_4 ( V_3 ) ) ;
}
static inline void F_32 ( struct V_2 * V_3 )
{
return F_33 ( F_4 ( V_3 ) ) ;
}
static inline void F_34 ( struct V_2 * V_3 ,
struct V_2 * V_18 , int V_29 )
{
F_35 ( & V_3 -> V_14 . V_22 , V_29 , 1 ) ;
F_14 ( & V_3 -> V_14 ) ;
F_12 ( V_3 , V_18 ) ;
}
static inline void F_36 ( struct V_2 * V_3 ,
unsigned long time , unsigned long V_30 )
{
F_10 ( & V_3 -> V_14 . time , time ) ;
#ifdef F_37
F_10 ( & V_3 -> V_14 . V_30 , V_30 ) ;
#endif
}
static inline void F_38 ( struct V_2 * V_3 , int V_29 )
{
F_35 ( & V_3 -> V_14 . V_22 , V_29 , - 1 ) ;
}
static inline void F_39 ( struct V_2 * V_3 , int V_29 )
{
F_35 ( & V_3 -> V_14 . V_31 , V_29 , 1 ) ;
}
static inline void F_40 ( struct V_2 * V_3 ,
T_1 V_32 , int V_29 )
{
F_10 ( & V_3 -> V_14 . V_33 , V_32 >> 9 ) ;
F_35 ( & V_3 -> V_14 . V_34 , V_29 , 1 ) ;
F_35 ( & V_3 -> V_14 . V_35 , V_29 , V_32 ) ;
}
static inline void F_41 ( struct V_2 * V_3 ,
T_1 V_36 , T_1 V_37 , int V_29 )
{
struct V_13 * V_14 = & V_3 -> V_14 ;
unsigned long long V_15 = F_8 () ;
if ( F_9 ( V_15 , V_37 ) )
F_35 ( & V_14 -> V_38 , V_29 , V_15 - V_37 ) ;
if ( F_9 ( V_37 , V_36 ) )
F_35 ( & V_14 -> V_39 , V_29 ,
V_37 - V_36 ) ;
}
static void F_42 ( struct V_12 * V_27 )
{
struct V_2 * V_3 = F_28 ( V_27 ) ;
struct V_13 * V_14 = & V_3 -> V_14 ;
F_43 ( & V_14 -> V_35 ) ;
F_43 ( & V_14 -> V_34 ) ;
F_43 ( & V_14 -> V_31 ) ;
F_43 ( & V_14 -> V_38 ) ;
F_43 ( & V_14 -> V_39 ) ;
F_44 ( & V_14 -> time ) ;
#ifdef F_37
F_44 ( & V_14 -> V_30 ) ;
F_44 ( & V_14 -> V_25 ) ;
F_44 ( & V_14 -> V_26 ) ;
F_44 ( & V_14 -> V_21 ) ;
F_44 ( & V_14 -> V_17 ) ;
F_44 ( & V_14 -> V_24 ) ;
F_44 ( & V_14 -> V_20 ) ;
#endif
}
static inline void F_30 ( struct V_2 * V_3 ) { }
static inline void F_32 ( struct V_2 * V_3 ) { }
static inline void F_34 ( struct V_2 * V_3 ,
struct V_2 * V_18 , int V_29 ) { }
static inline void F_36 ( struct V_2 * V_3 ,
unsigned long time , unsigned long V_30 ) { }
static inline void F_38 ( struct V_2 * V_3 , int V_29 ) { }
static inline void F_39 ( struct V_2 * V_3 , int V_29 ) { }
static inline void F_40 ( struct V_2 * V_3 ,
T_1 V_32 , int V_29 ) { }
static inline void F_41 ( struct V_2 * V_3 ,
T_1 V_36 , T_1 V_37 , int V_29 ) { }
static inline bool F_45 ( struct V_40 * V_41 )
{
if ( ! V_41 -> V_42 && V_41 -> V_43 )
return true ;
else
return false ;
}
static inline enum V_4 F_46 ( struct V_44 * V_45 )
{
if ( F_47 ( V_45 ) )
return V_7 ;
if ( F_48 ( V_45 ) )
return V_46 ;
return V_47 ;
}
static enum V_6 F_49 ( struct V_44 * V_45 )
{
if ( ! F_50 ( V_45 ) )
return V_48 ;
if ( ! F_51 ( V_45 ) )
return V_49 ;
return V_50 ;
}
static inline int F_52 ( enum V_4 V_51 ,
struct V_40 * V_41 ,
struct V_2 * V_3 )
{
if ( V_51 == V_7 )
return V_3 -> V_8 . V_52 ;
return V_3 -> V_9 [ V_51 ] [ V_48 ] . V_52
+ V_3 -> V_9 [ V_51 ] [ V_49 ] . V_52
+ V_3 -> V_9 [ V_51 ] [ V_50 ] . V_52 ;
}
static inline int F_53 ( struct V_40 * V_41 ,
struct V_2 * V_3 )
{
return V_3 -> V_9 [ V_46 ] [ V_48 ] . V_52
+ V_3 -> V_9 [ V_47 ] [ V_48 ] . V_52 ;
}
static inline struct V_53 * F_54 ( struct V_54 * V_55 )
{
return F_3 ( V_55 , struct V_53 , V_55 ) ;
}
static inline struct V_53 * F_55 ( struct V_40 * V_41 ,
struct V_56 * V_57 )
{
if ( V_57 )
return F_54 ( F_56 ( V_57 , V_41 -> V_58 ) ) ;
return NULL ;
}
static inline struct V_44 * F_57 ( struct V_53 * V_59 , bool V_60 )
{
return V_59 -> V_45 [ V_60 ] ;
}
static inline void F_58 ( struct V_53 * V_59 , struct V_44 * V_45 ,
bool V_60 )
{
V_59 -> V_45 [ V_60 ] = V_45 ;
}
static inline struct V_40 * F_59 ( struct V_53 * V_59 )
{
return V_59 -> V_55 . V_61 -> V_62 -> V_63 ;
}
static inline bool F_60 ( struct V_64 * V_64 )
{
return F_61 ( V_64 ) == V_65 || ( V_64 -> V_66 & V_67 ) ;
}
static inline void F_62 ( struct V_40 * V_41 )
{
if ( V_41 -> V_68 ) {
F_63 ( V_41 , L_1 ) ;
F_64 ( V_41 -> V_58 , & V_41 -> V_69 ) ;
}
}
static inline int F_65 ( struct V_40 * V_41 , bool V_70 ,
unsigned short V_5 )
{
const int V_71 = V_41 -> V_72 [ V_70 ] ;
F_66 ( V_5 >= V_73 ) ;
return V_71 + ( V_71 / V_74 * ( 4 - V_5 ) ) ;
}
static inline int
F_67 ( struct V_40 * V_41 , struct V_44 * V_45 )
{
return F_65 ( V_41 , F_50 ( V_45 ) , V_45 -> V_75 ) ;
}
static inline T_2 F_68 ( unsigned long V_76 , struct V_2 * V_3 )
{
T_2 V_77 = V_76 << V_78 ;
V_77 = V_77 * V_79 ;
F_69 ( V_77 , V_3 -> V_80 ) ;
return V_77 ;
}
static inline T_2 F_70 ( T_2 V_81 , T_2 V_82 )
{
T_3 V_76 = ( T_3 ) ( V_82 - V_81 ) ;
if ( V_76 > 0 )
V_81 = V_82 ;
return V_81 ;
}
static inline T_2 V_81 ( T_2 V_81 , T_2 V_82 )
{
T_3 V_76 = ( T_3 ) ( V_82 - V_81 ) ;
if ( V_76 < 0 )
V_81 = V_82 ;
return V_81 ;
}
static void F_71 ( struct V_1 * V_83 )
{
struct V_2 * V_3 ;
if ( V_83 -> V_84 ) {
V_3 = F_72 ( V_83 -> V_84 ) ;
V_83 -> V_81 = F_70 ( V_83 -> V_81 ,
V_3 -> V_82 ) ;
}
}
static inline unsigned F_73 ( struct V_40 * V_41 ,
struct V_2 * V_3 , bool V_85 )
{
unsigned V_86 , V_87 ;
unsigned V_88 = V_89 - 1 ;
unsigned V_90 = V_89 / 2 ;
unsigned V_91 = F_52 ( V_85 , V_41 , V_3 ) ;
V_86 = F_74 ( V_3 -> V_92 [ V_85 ] , V_91 ) ;
V_87 = F_75 ( V_3 -> V_92 [ V_85 ] , V_91 ) ;
V_3 -> V_92 [ V_85 ] = ( V_88 * V_87 + V_86 + V_90 ) /
V_89 ;
return V_3 -> V_92 [ V_85 ] ;
}
static inline unsigned
F_76 ( struct V_40 * V_41 , struct V_2 * V_3 )
{
struct V_1 * V_83 = & V_41 -> V_93 ;
return V_41 -> V_94 * V_3 -> V_80 / V_83 -> V_95 ;
}
static inline unsigned
F_77 ( struct V_40 * V_41 , struct V_44 * V_45 )
{
unsigned V_96 = F_67 ( V_41 , V_45 ) ;
if ( V_41 -> V_97 ) {
unsigned V_98 = F_73 ( V_41 , V_45 -> V_3 ,
F_48 ( V_45 ) ) ;
unsigned V_99 = V_41 -> V_72 [ 1 ] ;
unsigned V_100 = V_99 * V_98 ;
unsigned V_101 = F_76 ( V_41 , V_45 -> V_3 ) ;
if ( V_100 > V_101 ) {
unsigned V_102 = 2 * V_41 -> V_42 ;
unsigned V_103 =
F_74 ( V_96 , V_102 * V_96 / V_99 ) ;
V_96 = F_75 ( V_96 * V_101 / V_100 ,
V_103 ) ;
}
}
return V_96 ;
}
static inline void
F_78 ( struct V_40 * V_41 , struct V_44 * V_45 )
{
unsigned V_96 = F_77 ( V_41 , V_45 ) ;
V_45 -> V_104 = V_105 ;
V_45 -> V_106 = V_105 + V_96 ;
V_45 -> V_107 = V_96 ;
F_79 ( V_41 , V_45 , L_2 , V_45 -> V_106 - V_105 ) ;
}
static inline bool F_80 ( struct V_44 * V_45 )
{
if ( F_81 ( V_45 ) )
return false ;
if ( F_82 ( V_105 , V_45 -> V_106 ) )
return false ;
return true ;
}
static struct V_108 *
F_83 ( struct V_40 * V_41 , struct V_108 * V_109 , struct V_108 * V_110 , T_4 V_111 )
{
T_4 V_112 , V_113 , V_114 = 0 , V_115 = 0 ;
unsigned long V_116 ;
#define F_84 0x01
#define F_85 0x02
unsigned V_117 = 0 ;
if ( V_109 == NULL || V_109 == V_110 )
return V_110 ;
if ( V_110 == NULL )
return V_109 ;
if ( F_86 ( V_109 ) != F_86 ( V_110 ) )
return F_86 ( V_109 ) ? V_109 : V_110 ;
if ( ( V_109 -> V_118 ^ V_110 -> V_118 ) & V_119 )
return V_109 -> V_118 & V_119 ? V_109 : V_110 ;
V_112 = F_87 ( V_109 ) ;
V_113 = F_87 ( V_110 ) ;
V_116 = V_41 -> V_120 * 2 ;
if ( V_112 >= V_111 )
V_114 = V_112 - V_111 ;
else if ( V_112 + V_116 >= V_111 )
V_114 = ( V_111 - V_112 ) * V_41 -> V_121 ;
else
V_117 |= F_84 ;
if ( V_113 >= V_111 )
V_115 = V_113 - V_111 ;
else if ( V_113 + V_116 >= V_111 )
V_115 = ( V_111 - V_113 ) * V_41 -> V_121 ;
else
V_117 |= F_85 ;
switch ( V_117 ) {
case 0 :
if ( V_114 < V_115 )
return V_109 ;
else if ( V_115 < V_114 )
return V_110 ;
else {
if ( V_112 >= V_113 )
return V_109 ;
else
return V_110 ;
}
case F_85 :
return V_109 ;
case F_84 :
return V_110 ;
case ( F_84 | F_85 ) :
default:
if ( V_112 <= V_113 )
return V_109 ;
else
return V_110 ;
}
}
static struct V_44 * F_88 ( struct V_1 * V_122 )
{
if ( ! V_122 -> V_52 )
return NULL ;
if ( ! V_122 -> V_84 )
V_122 -> V_84 = F_89 ( & V_122 -> V_123 ) ;
if ( V_122 -> V_84 )
return F_90 ( V_122 -> V_84 , struct V_44 , V_124 ) ;
return NULL ;
}
static struct V_2 * F_91 ( struct V_1 * V_122 )
{
if ( ! V_122 -> V_84 )
V_122 -> V_84 = F_89 ( & V_122 -> V_123 ) ;
if ( V_122 -> V_84 )
return F_72 ( V_122 -> V_84 ) ;
return NULL ;
}
static void F_92 ( struct V_124 * V_125 , struct V_126 * V_122 )
{
F_93 ( V_125 , V_122 ) ;
F_94 ( V_125 ) ;
}
static void F_95 ( struct V_124 * V_125 , struct V_1 * V_122 )
{
if ( V_122 -> V_84 == V_125 )
V_122 -> V_84 = NULL ;
F_92 ( V_125 , & V_122 -> V_123 ) ;
-- V_122 -> V_52 ;
}
static struct V_108 *
F_96 ( struct V_40 * V_41 , struct V_44 * V_45 ,
struct V_108 * V_111 )
{
struct V_124 * V_127 = F_97 ( & V_111 -> V_124 ) ;
struct V_124 * V_128 = F_98 ( & V_111 -> V_124 ) ;
struct V_108 * V_129 = NULL , * V_130 = NULL ;
F_25 ( F_99 ( & V_111 -> V_124 ) ) ;
if ( V_128 )
V_130 = F_100 ( V_128 ) ;
if ( V_127 )
V_129 = F_100 ( V_127 ) ;
else {
V_127 = F_89 ( & V_45 -> V_131 ) ;
if ( V_127 && V_127 != & V_111 -> V_124 )
V_129 = F_100 ( V_127 ) ;
}
return F_83 ( V_41 , V_129 , V_130 , F_87 ( V_111 ) ) ;
}
static unsigned long F_101 ( struct V_40 * V_41 ,
struct V_44 * V_45 )
{
return ( V_45 -> V_3 -> V_132 - 1 ) * ( F_65 ( V_41 , 1 , 0 ) -
F_65 ( V_41 , F_50 ( V_45 ) , V_45 -> V_75 ) ) ;
}
static inline T_3
F_102 ( struct V_1 * V_83 , struct V_2 * V_3 )
{
return V_3 -> V_82 - V_83 -> V_81 ;
}
static void
F_103 ( struct V_1 * V_83 , struct V_2 * V_3 )
{
struct V_124 * * V_133 = & V_83 -> V_123 . V_124 ;
struct V_124 * V_134 = NULL ;
struct V_2 * V_135 ;
T_3 V_136 = F_102 ( V_83 , V_3 ) ;
int V_84 = 1 ;
while ( * V_133 != NULL ) {
V_134 = * V_133 ;
V_135 = F_72 ( V_134 ) ;
if ( V_136 < F_102 ( V_83 , V_135 ) )
V_133 = & V_134 -> V_137 ;
else {
V_133 = & V_134 -> V_138 ;
V_84 = 0 ;
}
}
if ( V_84 )
V_83 -> V_84 = & V_3 -> V_124 ;
F_104 ( & V_3 -> V_124 , V_134 , V_133 ) ;
F_105 ( & V_3 -> V_124 , & V_83 -> V_123 ) ;
}
static void
F_106 ( struct V_2 * V_3 )
{
F_25 ( ! F_99 ( & V_3 -> V_124 ) ) ;
if ( V_3 -> V_139 ) {
V_3 -> V_80 = V_3 -> V_139 ;
V_3 -> V_139 = 0 ;
}
}
static void
F_107 ( struct V_1 * V_83 , struct V_2 * V_3 )
{
F_25 ( ! F_99 ( & V_3 -> V_124 ) ) ;
F_106 ( V_3 ) ;
F_103 ( V_83 , V_3 ) ;
V_83 -> V_95 += V_3 -> V_80 ;
}
static void
F_108 ( struct V_40 * V_41 , struct V_2 * V_3 )
{
struct V_1 * V_83 = & V_41 -> V_93 ;
struct V_2 * V_135 ;
struct V_124 * V_125 ;
V_3 -> V_132 ++ ;
if ( ! F_99 ( & V_3 -> V_124 ) )
return;
V_125 = F_109 ( & V_83 -> V_123 ) ;
if ( V_125 ) {
V_135 = F_72 ( V_125 ) ;
V_3 -> V_82 = V_135 -> V_82 + V_140 ;
} else
V_3 -> V_82 = V_83 -> V_81 ;
F_107 ( V_83 , V_3 ) ;
}
static void
F_110 ( struct V_1 * V_83 , struct V_2 * V_3 )
{
V_83 -> V_95 -= V_3 -> V_80 ;
if ( ! F_99 ( & V_3 -> V_124 ) )
F_95 ( & V_3 -> V_124 , V_83 ) ;
}
static void
F_111 ( struct V_40 * V_41 , struct V_2 * V_3 )
{
struct V_1 * V_83 = & V_41 -> V_93 ;
F_25 ( V_3 -> V_132 < 1 ) ;
V_3 -> V_132 -- ;
if ( V_3 -> V_132 )
return;
F_112 ( V_41 , V_3 , L_3 ) ;
F_110 ( V_83 , V_3 ) ;
V_3 -> V_141 = 0 ;
F_17 ( V_3 ) ;
}
static inline unsigned int F_113 ( struct V_44 * V_45 ,
unsigned int * V_30 )
{
unsigned int V_142 ;
if ( ! V_45 -> V_104 || V_45 -> V_104 == V_105 ) {
V_142 = F_114 ( unsigned , ( V_105 - V_45 -> V_143 ) ,
1 ) ;
} else {
V_142 = V_105 - V_45 -> V_104 ;
if ( V_142 > V_45 -> V_107 ) {
* V_30 = V_142 - V_45 -> V_107 ;
V_142 = V_45 -> V_107 ;
}
if ( F_115 ( V_45 -> V_104 , V_45 -> V_143 ) )
* V_30 += V_45 -> V_104 -
V_45 -> V_143 ;
}
return V_142 ;
}
static void F_116 ( struct V_40 * V_41 , struct V_2 * V_3 ,
struct V_44 * V_45 )
{
struct V_1 * V_83 = & V_41 -> V_93 ;
unsigned int V_144 , V_145 , V_146 = 0 ;
int V_147 = V_3 -> V_132 - F_53 ( V_41 , V_3 )
- V_3 -> V_8 . V_52 ;
F_25 ( V_147 < 0 ) ;
V_144 = V_145 = F_113 ( V_45 , & V_146 ) ;
if ( F_45 ( V_41 ) )
V_145 = V_45 -> V_148 ;
else if ( ! F_50 ( V_45 ) && ! V_147 )
V_145 = V_45 -> V_107 ;
F_110 ( V_83 , V_3 ) ;
V_3 -> V_82 += F_68 ( V_145 , V_3 ) ;
F_107 ( V_83 , V_3 ) ;
if ( F_115 ( V_41 -> V_149 , V_105 ) ) {
V_3 -> V_141 = V_41 -> V_149
- V_105 ;
V_3 -> V_150 = V_41 -> V_151 ;
V_3 -> V_152 = V_41 -> V_153 ;
} else
V_3 -> V_141 = 0 ;
F_112 ( V_41 , V_3 , L_4 , V_3 -> V_82 ,
V_83 -> V_81 ) ;
F_79 ( V_45 -> V_41 , V_45 ,
L_5 ,
V_144 , V_45 -> V_148 , V_145 ,
F_45 ( V_41 ) , V_45 -> V_154 ) ;
F_36 ( V_3 , V_144 , V_146 ) ;
F_18 ( V_3 ) ;
}
static void F_117 ( struct V_2 * V_3 )
{
struct V_1 * V_83 ;
int V_155 , V_156 ;
F_118 ( V_3 , V_155 , V_156 , V_83 )
* V_83 = V_157 ;
F_94 ( & V_3 -> V_124 ) ;
V_3 -> V_158 . V_159 = V_105 ;
}
static void F_119 ( struct V_12 * V_27 )
{
struct V_2 * V_3 = F_28 ( V_27 ) ;
F_117 ( V_3 ) ;
V_3 -> V_80 = V_27 -> V_160 -> V_161 ;
}
static struct V_2 * F_120 ( struct V_40 * V_41 ,
struct V_160 * V_160 )
{
struct V_162 * V_61 = V_41 -> V_58 ;
struct V_2 * V_3 = NULL ;
if ( V_160 == & V_163 ) {
V_3 = V_41 -> V_164 ;
} else {
struct V_12 * V_27 ;
V_27 = F_121 ( V_160 , V_61 ) ;
if ( ! F_122 ( V_27 ) )
V_3 = F_28 ( V_27 ) ;
}
return V_3 ;
}
static void F_123 ( struct V_44 * V_45 , struct V_2 * V_3 )
{
if ( ! F_50 ( V_45 ) )
V_3 = V_45 -> V_41 -> V_164 ;
V_45 -> V_3 = V_3 ;
F_30 ( V_3 ) ;
}
static T_2 F_124 ( struct V_165 * V_166 ,
struct V_10 * V_11 , int V_167 )
{
struct V_2 * V_3 = F_2 ( V_11 ) ;
if ( ! V_3 -> V_168 )
return 0 ;
return F_125 ( V_166 , V_11 , V_3 -> V_168 ) ;
}
static int F_126 ( struct V_169 * V_170 , struct V_171 * V_172 ,
struct V_165 * V_166 )
{
F_127 ( V_166 , F_128 ( V_170 ) ,
F_124 , & V_28 , 0 ,
false ) ;
return 0 ;
}
static int F_129 ( struct V_169 * V_170 , struct V_171 * V_172 ,
struct V_165 * V_166 )
{
F_130 ( V_166 , L_6 , F_128 ( V_170 ) -> V_161 ) ;
return 0 ;
}
static int F_131 ( struct V_169 * V_170 , struct V_171 * V_172 ,
const char * V_173 )
{
struct V_160 * V_160 = F_128 ( V_170 ) ;
struct V_174 V_175 ;
struct V_2 * V_3 ;
int V_176 ;
V_176 = F_132 ( V_160 , & V_28 , V_173 , & V_175 ) ;
if ( V_176 )
return V_176 ;
V_176 = - V_177 ;
V_3 = F_28 ( V_175 . V_27 ) ;
if ( ! V_175 . V_178 || ( V_175 . V_178 >= V_179 && V_175 . V_178 <= V_180 ) ) {
V_3 -> V_168 = V_175 . V_178 ;
V_3 -> V_139 = V_3 -> V_168 ? : V_160 -> V_161 ;
V_176 = 0 ;
}
F_133 ( & V_175 ) ;
return V_176 ;
}
static int F_134 ( struct V_169 * V_170 , struct V_171 * V_172 , T_2 V_181 )
{
struct V_160 * V_160 = F_128 ( V_170 ) ;
struct V_12 * V_27 ;
struct V_182 * V_125 ;
if ( V_181 < V_179 || V_181 > V_180 )
return - V_177 ;
F_135 ( & V_160 -> V_183 ) ;
V_160 -> V_161 = ( unsigned int ) V_181 ;
F_136 (blkg, n, &blkcg->blkg_list, blkcg_node) {
struct V_2 * V_3 = F_28 ( V_27 ) ;
if ( V_3 && ! V_3 -> V_168 )
V_3 -> V_139 = V_160 -> V_161 ;
}
F_137 ( & V_160 -> V_183 ) ;
return 0 ;
}
static int F_138 ( struct V_169 * V_170 , struct V_171 * V_172 ,
struct V_165 * V_166 )
{
struct V_160 * V_160 = F_128 ( V_170 ) ;
F_127 ( V_166 , V_160 , V_184 , & V_28 ,
V_172 -> V_185 , false ) ;
return 0 ;
}
static int F_139 ( struct V_169 * V_170 , struct V_171 * V_172 ,
struct V_165 * V_166 )
{
struct V_160 * V_160 = F_128 ( V_170 ) ;
F_127 ( V_166 , V_160 , V_186 , & V_28 ,
V_172 -> V_185 , true ) ;
return 0 ;
}
static T_2 F_140 ( struct V_165 * V_166 ,
struct V_10 * V_11 , int V_167 )
{
struct V_2 * V_3 = F_2 ( V_11 ) ;
T_2 V_187 = F_141 ( & V_3 -> V_14 . V_26 ) ;
T_2 V_178 = 0 ;
if ( V_187 ) {
V_178 = F_141 ( & V_3 -> V_14 . V_25 ) ;
F_69 ( V_178 , V_187 ) ;
}
F_125 ( V_166 , V_11 , V_178 ) ;
return 0 ;
}
static int F_142 ( struct V_169 * V_170 , struct V_171 * V_172 ,
struct V_165 * V_166 )
{
struct V_160 * V_160 = F_128 ( V_170 ) ;
F_127 ( V_166 , V_160 , F_140 ,
& V_28 , 0 , false ) ;
return 0 ;
}
static struct V_2 * F_120 ( struct V_40 * V_41 ,
struct V_160 * V_160 )
{
return V_41 -> V_164 ;
}
static inline void
F_123 ( struct V_44 * V_45 , struct V_2 * V_3 ) {
V_45 -> V_3 = V_3 ;
}
static void F_143 ( struct V_40 * V_41 , struct V_44 * V_45 ,
bool V_188 )
{
struct V_124 * * V_189 , * V_134 ;
struct V_44 * V_190 ;
unsigned long V_191 ;
struct V_1 * V_192 ;
int V_84 ;
int V_193 = 1 ;
V_192 = F_1 ( V_45 -> V_3 , F_46 ( V_45 ) ,
F_49 ( V_45 ) ) ;
if ( F_47 ( V_45 ) ) {
V_191 = V_140 ;
V_134 = F_109 ( & V_192 -> V_123 ) ;
if ( V_134 && V_134 != & V_45 -> V_124 ) {
V_190 = F_90 ( V_134 , struct V_44 , V_124 ) ;
V_191 += V_190 -> V_191 ;
} else
V_191 += V_105 ;
} else if ( ! V_188 ) {
V_191 = F_101 ( V_41 , V_45 ) + V_105 ;
V_191 -= V_45 -> V_194 ;
V_45 -> V_194 = 0 ;
} else {
V_191 = - V_195 ;
V_190 = F_88 ( V_192 ) ;
V_191 += V_190 ? V_190 -> V_191 : V_105 ;
}
if ( ! F_99 ( & V_45 -> V_124 ) ) {
V_193 = 0 ;
if ( V_191 == V_45 -> V_191 &&
V_45 -> V_192 == V_192 )
return;
F_95 ( & V_45 -> V_124 , V_45 -> V_192 ) ;
V_45 -> V_192 = NULL ;
}
V_84 = 1 ;
V_134 = NULL ;
V_45 -> V_192 = V_192 ;
V_189 = & V_192 -> V_123 . V_124 ;
while ( * V_189 ) {
struct V_124 * * V_125 ;
V_134 = * V_189 ;
V_190 = F_90 ( V_134 , struct V_44 , V_124 ) ;
if ( F_82 ( V_191 , V_190 -> V_191 ) )
V_125 = & ( * V_189 ) -> V_137 ;
else {
V_125 = & ( * V_189 ) -> V_138 ;
V_84 = 0 ;
}
V_189 = V_125 ;
}
if ( V_84 )
V_192 -> V_84 = & V_45 -> V_124 ;
V_45 -> V_191 = V_191 ;
F_104 ( & V_45 -> V_124 , V_134 , V_189 ) ;
F_105 ( & V_45 -> V_124 , & V_192 -> V_123 ) ;
V_192 -> V_52 ++ ;
if ( V_188 || ! V_193 )
return;
F_108 ( V_41 , V_45 -> V_3 ) ;
}
static struct V_44 *
F_144 ( struct V_40 * V_41 , struct V_126 * V_122 ,
T_4 V_196 , struct V_124 * * V_197 ,
struct V_124 * * * V_198 )
{
struct V_124 * * V_189 , * V_134 ;
struct V_44 * V_45 = NULL ;
V_134 = NULL ;
V_189 = & V_122 -> V_124 ;
while ( * V_189 ) {
struct V_124 * * V_125 ;
V_134 = * V_189 ;
V_45 = F_90 ( V_134 , struct V_44 , V_199 ) ;
if ( V_196 > F_87 ( V_45 -> V_200 ) )
V_125 = & ( * V_189 ) -> V_138 ;
else if ( V_196 < F_87 ( V_45 -> V_200 ) )
V_125 = & ( * V_189 ) -> V_137 ;
else
break;
V_189 = V_125 ;
V_45 = NULL ;
}
* V_197 = V_134 ;
if ( V_198 )
* V_198 = V_189 ;
return V_45 ;
}
static void F_145 ( struct V_40 * V_41 , struct V_44 * V_45 )
{
struct V_124 * * V_189 , * V_134 ;
struct V_44 * V_190 ;
if ( V_45 -> V_201 ) {
F_93 ( & V_45 -> V_199 , V_45 -> V_201 ) ;
V_45 -> V_201 = NULL ;
}
if ( F_47 ( V_45 ) )
return;
if ( ! V_45 -> V_200 )
return;
V_45 -> V_201 = & V_41 -> V_202 [ V_45 -> V_203 ] ;
V_190 = F_144 ( V_41 , V_45 -> V_201 ,
F_87 ( V_45 -> V_200 ) , & V_134 , & V_189 ) ;
if ( ! V_190 ) {
F_104 ( & V_45 -> V_199 , V_134 , V_189 ) ;
F_105 ( & V_45 -> V_199 , V_45 -> V_201 ) ;
} else
V_45 -> V_201 = NULL ;
}
static void F_146 ( struct V_40 * V_41 , struct V_44 * V_45 )
{
if ( F_147 ( V_45 ) ) {
F_143 ( V_41 , V_45 , 0 ) ;
F_145 ( V_41 , V_45 ) ;
}
}
static void F_148 ( struct V_40 * V_41 , struct V_44 * V_45 )
{
F_79 ( V_41 , V_45 , L_7 ) ;
F_25 ( F_147 ( V_45 ) ) ;
F_149 ( V_45 ) ;
V_41 -> V_68 ++ ;
if ( F_50 ( V_45 ) )
V_41 -> V_204 ++ ;
F_146 ( V_41 , V_45 ) ;
}
static void F_150 ( struct V_40 * V_41 , struct V_44 * V_45 )
{
F_79 ( V_41 , V_45 , L_8 ) ;
F_25 ( ! F_147 ( V_45 ) ) ;
F_151 ( V_45 ) ;
if ( ! F_99 ( & V_45 -> V_124 ) ) {
F_95 ( & V_45 -> V_124 , V_45 -> V_192 ) ;
V_45 -> V_192 = NULL ;
}
if ( V_45 -> V_201 ) {
F_93 ( & V_45 -> V_199 , V_45 -> V_201 ) ;
V_45 -> V_201 = NULL ;
}
F_111 ( V_41 , V_45 -> V_3 ) ;
F_25 ( ! V_41 -> V_68 ) ;
V_41 -> V_68 -- ;
if ( F_50 ( V_45 ) )
V_41 -> V_204 -- ;
}
static void F_152 ( struct V_108 * V_205 )
{
struct V_44 * V_45 = F_153 ( V_205 ) ;
const int V_70 = F_86 ( V_205 ) ;
F_25 ( ! V_45 -> V_22 [ V_70 ] ) ;
V_45 -> V_22 [ V_70 ] -- ;
F_154 ( & V_45 -> V_131 , V_205 ) ;
if ( F_147 ( V_45 ) && F_155 ( & V_45 -> V_131 ) ) {
if ( V_45 -> V_201 ) {
F_93 ( & V_45 -> V_199 , V_45 -> V_201 ) ;
V_45 -> V_201 = NULL ;
}
}
}
static void F_156 ( struct V_108 * V_205 )
{
struct V_44 * V_45 = F_153 ( V_205 ) ;
struct V_40 * V_41 = V_45 -> V_41 ;
struct V_108 * V_130 ;
V_45 -> V_22 [ F_86 ( V_205 ) ] ++ ;
F_157 ( & V_45 -> V_131 , V_205 ) ;
if ( ! F_147 ( V_45 ) )
F_148 ( V_41 , V_45 ) ;
V_130 = V_45 -> V_200 ;
V_45 -> V_200 = F_83 ( V_41 , V_45 -> V_200 , V_205 , V_41 -> V_206 ) ;
if ( V_130 != V_45 -> V_200 )
F_145 ( V_41 , V_45 ) ;
F_25 ( ! V_45 -> V_200 ) ;
}
static void F_158 ( struct V_44 * V_45 , struct V_108 * V_205 )
{
F_154 ( & V_45 -> V_131 , V_205 ) ;
V_45 -> V_22 [ F_86 ( V_205 ) ] -- ;
F_38 ( F_159 ( V_205 ) , V_205 -> V_118 ) ;
F_156 ( V_205 ) ;
F_34 ( F_159 ( V_205 ) , V_45 -> V_41 -> V_207 ,
V_205 -> V_118 ) ;
}
static struct V_108 *
F_160 ( struct V_40 * V_41 , struct V_64 * V_64 )
{
struct V_208 * V_209 = V_210 ;
struct V_53 * V_59 ;
struct V_44 * V_45 ;
V_59 = F_55 ( V_41 , V_209 -> V_56 ) ;
if ( ! V_59 )
return NULL ;
V_45 = F_57 ( V_59 , F_60 ( V_64 ) ) ;
if ( V_45 ) {
T_4 V_196 = V_64 -> V_211 + F_161 ( V_64 ) ;
return F_162 ( & V_45 -> V_131 , V_196 ) ;
}
return NULL ;
}
static void F_163 ( struct V_162 * V_61 , struct V_108 * V_205 )
{
struct V_40 * V_41 = V_61 -> V_62 -> V_63 ;
V_41 -> V_212 ++ ;
F_79 ( V_41 , F_153 ( V_205 ) , L_9 ,
V_41 -> V_212 ) ;
V_41 -> V_206 = F_87 ( V_205 ) + F_164 ( V_205 ) ;
}
static void F_165 ( struct V_162 * V_61 , struct V_108 * V_205 )
{
struct V_40 * V_41 = V_61 -> V_62 -> V_63 ;
F_66 ( ! V_41 -> V_212 ) ;
V_41 -> V_212 -- ;
F_79 ( V_41 , F_153 ( V_205 ) , L_10 ,
V_41 -> V_212 ) ;
}
static void F_166 ( struct V_108 * V_205 )
{
struct V_44 * V_45 = F_153 ( V_205 ) ;
if ( V_45 -> V_200 == V_205 )
V_45 -> V_200 = F_96 ( V_45 -> V_41 , V_45 , V_205 ) ;
F_167 ( & V_205 -> V_213 ) ;
F_152 ( V_205 ) ;
V_45 -> V_41 -> V_214 -- ;
F_38 ( F_159 ( V_205 ) , V_205 -> V_118 ) ;
if ( V_205 -> V_118 & V_119 ) {
F_66 ( ! V_45 -> V_215 ) ;
V_45 -> V_215 -- ;
}
}
static int F_168 ( struct V_162 * V_61 , struct V_108 * * V_216 ,
struct V_64 * V_64 )
{
struct V_40 * V_41 = V_61 -> V_62 -> V_63 ;
struct V_108 * V_217 ;
V_217 = F_160 ( V_41 , V_64 ) ;
if ( V_217 && F_169 ( V_217 , V_64 ) ) {
* V_216 = V_217 ;
return V_218 ;
}
return V_219 ;
}
static void F_170 ( struct V_162 * V_61 , struct V_108 * V_216 ,
int type )
{
if ( type == V_218 ) {
struct V_44 * V_45 = F_153 ( V_216 ) ;
F_158 ( V_45 , V_216 ) ;
}
}
static void F_171 ( struct V_162 * V_61 , struct V_108 * V_216 ,
struct V_64 * V_64 )
{
F_39 ( F_159 ( V_216 ) , V_64 -> V_66 ) ;
}
static void
F_172 ( struct V_162 * V_61 , struct V_108 * V_205 ,
struct V_108 * V_129 )
{
struct V_44 * V_45 = F_153 ( V_205 ) ;
struct V_40 * V_41 = V_61 -> V_62 -> V_63 ;
if ( ! F_173 ( & V_205 -> V_213 ) && ! F_173 ( & V_129 -> V_213 ) &&
F_82 ( F_174 ( V_129 ) , F_174 ( V_205 ) ) &&
V_45 == F_153 ( V_129 ) ) {
F_175 ( & V_205 -> V_213 , & V_129 -> V_213 ) ;
F_176 ( V_205 , F_174 ( V_129 ) ) ;
}
if ( V_45 -> V_200 == V_129 )
V_45 -> V_200 = V_205 ;
F_166 ( V_129 ) ;
F_39 ( F_159 ( V_205 ) , V_129 -> V_118 ) ;
V_45 = F_153 ( V_129 ) ;
if ( F_147 ( V_45 ) && F_155 ( & V_45 -> V_131 ) &&
V_45 != V_41 -> V_220 )
F_150 ( V_41 , V_45 ) ;
}
static int F_177 ( struct V_162 * V_61 , struct V_108 * V_205 ,
struct V_64 * V_64 )
{
struct V_40 * V_41 = V_61 -> V_62 -> V_63 ;
struct V_53 * V_59 ;
struct V_44 * V_45 ;
if ( F_60 ( V_64 ) && ! F_86 ( V_205 ) )
return false ;
V_59 = F_55 ( V_41 , V_210 -> V_56 ) ;
if ( ! V_59 )
return false ;
V_45 = F_57 ( V_59 , F_60 ( V_64 ) ) ;
return V_45 == F_153 ( V_205 ) ;
}
static inline void F_178 ( struct V_40 * V_41 , struct V_44 * V_45 )
{
F_179 ( & V_41 -> V_221 ) ;
F_21 ( V_45 -> V_3 ) ;
}
static void F_180 ( struct V_40 * V_41 ,
struct V_44 * V_45 )
{
if ( V_45 ) {
F_79 ( V_41 , V_45 , L_11 ,
V_41 -> V_153 , V_41 -> V_151 ) ;
F_27 ( V_45 -> V_3 ) ;
V_45 -> V_104 = 0 ;
V_45 -> V_143 = V_105 ;
V_45 -> V_107 = 0 ;
V_45 -> V_106 = 0 ;
V_45 -> V_148 = 0 ;
V_45 -> V_154 = 0 ;
F_181 ( V_45 ) ;
F_182 ( V_45 ) ;
F_183 ( V_45 ) ;
F_184 ( V_45 ) ;
F_185 ( V_45 ) ;
F_178 ( V_41 , V_45 ) ;
}
V_41 -> V_220 = V_45 ;
}
static void
F_186 ( struct V_40 * V_41 , struct V_44 * V_45 ,
bool V_222 )
{
F_79 ( V_41 , V_45 , L_12 , V_222 ) ;
if ( F_187 ( V_45 ) )
F_178 ( V_41 , V_45 ) ;
F_181 ( V_45 ) ;
F_188 ( V_45 ) ;
if ( F_189 ( V_45 ) && F_190 ( V_45 ) )
F_191 ( V_45 ) ;
if ( V_222 ) {
if ( F_81 ( V_45 ) )
V_45 -> V_194 = F_77 ( V_41 , V_45 ) ;
else
V_45 -> V_194 = V_45 -> V_106 - V_105 ;
F_79 ( V_41 , V_45 , L_13 , V_45 -> V_194 ) ;
}
F_116 ( V_41 , V_45 -> V_3 , V_45 ) ;
if ( F_147 ( V_45 ) && F_155 ( & V_45 -> V_131 ) )
F_150 ( V_41 , V_45 ) ;
F_146 ( V_41 , V_45 ) ;
if ( V_45 == V_41 -> V_220 )
V_41 -> V_220 = NULL ;
if ( V_41 -> V_223 ) {
F_192 ( V_41 -> V_223 -> V_55 . V_57 ) ;
V_41 -> V_223 = NULL ;
}
}
static inline void F_193 ( struct V_40 * V_41 , bool V_222 )
{
struct V_44 * V_45 = V_41 -> V_220 ;
if ( V_45 )
F_186 ( V_41 , V_45 , V_222 ) ;
}
static struct V_44 * F_194 ( struct V_40 * V_41 )
{
struct V_1 * V_192 =
F_1 ( V_41 -> V_207 , V_41 -> V_153 ,
V_41 -> V_151 ) ;
if ( ! V_41 -> V_214 )
return NULL ;
if ( ! V_192 )
return NULL ;
if ( F_155 ( & V_192 -> V_123 ) )
return NULL ;
return F_88 ( V_192 ) ;
}
static struct V_44 * F_195 ( struct V_40 * V_41 )
{
struct V_2 * V_3 ;
struct V_44 * V_45 ;
int V_155 , V_156 ;
struct V_1 * V_83 ;
if ( ! V_41 -> V_214 )
return NULL ;
V_3 = F_196 ( V_41 ) ;
if ( ! V_3 )
return NULL ;
F_118 (cfqg, i, j, st)
if ( ( V_45 = F_88 ( V_83 ) ) != NULL )
return V_45 ;
return NULL ;
}
static struct V_44 * F_197 ( struct V_40 * V_41 ,
struct V_44 * V_45 )
{
if ( ! V_45 )
V_45 = F_194 ( V_41 ) ;
F_180 ( V_41 , V_45 ) ;
return V_45 ;
}
static inline T_4 F_198 ( struct V_40 * V_41 ,
struct V_108 * V_205 )
{
if ( F_87 ( V_205 ) >= V_41 -> V_206 )
return F_87 ( V_205 ) - V_41 -> V_206 ;
else
return V_41 -> V_206 - F_87 ( V_205 ) ;
}
static inline int F_199 ( struct V_40 * V_41 , struct V_44 * V_45 ,
struct V_108 * V_205 )
{
return F_198 ( V_41 , V_205 ) <= V_224 ;
}
static struct V_44 * F_200 ( struct V_40 * V_41 ,
struct V_44 * V_225 )
{
struct V_126 * V_122 = & V_41 -> V_202 [ V_225 -> V_203 ] ;
struct V_124 * V_134 , * V_133 ;
struct V_44 * V_190 ;
T_4 V_196 = V_41 -> V_206 ;
if ( F_155 ( V_122 ) )
return NULL ;
V_190 = F_144 ( V_41 , V_122 , V_196 , & V_134 , NULL ) ;
if ( V_190 )
return V_190 ;
V_190 = F_90 ( V_134 , struct V_44 , V_199 ) ;
if ( F_199 ( V_41 , V_225 , V_190 -> V_200 ) )
return V_190 ;
if ( F_87 ( V_190 -> V_200 ) < V_196 )
V_133 = F_97 ( & V_190 -> V_199 ) ;
else
V_133 = F_98 ( & V_190 -> V_199 ) ;
if ( ! V_133 )
return NULL ;
V_190 = F_90 ( V_133 , struct V_44 , V_199 ) ;
if ( F_199 ( V_41 , V_225 , V_190 -> V_200 ) )
return V_190 ;
return NULL ;
}
static struct V_44 * F_201 ( struct V_40 * V_41 ,
struct V_44 * V_225 )
{
struct V_44 * V_45 ;
if ( F_47 ( V_225 ) )
return NULL ;
if ( ! F_50 ( V_225 ) )
return NULL ;
if ( F_190 ( V_225 ) )
return NULL ;
if ( V_225 -> V_3 -> V_132 == 1 )
return NULL ;
V_45 = F_200 ( V_41 , V_225 ) ;
if ( ! V_45 )
return NULL ;
if ( V_225 -> V_3 != V_45 -> V_3 )
return NULL ;
if ( ! F_50 ( V_45 ) )
return NULL ;
if ( F_190 ( V_45 ) )
return NULL ;
if ( F_48 ( V_45 ) != F_48 ( V_225 ) )
return NULL ;
return V_45 ;
}
static bool F_202 ( struct V_40 * V_41 , struct V_44 * V_45 )
{
enum V_4 V_5 = F_46 ( V_45 ) ;
struct V_1 * V_192 = V_45 -> V_192 ;
F_25 ( ! V_192 ) ;
F_25 ( ! V_192 -> V_52 ) ;
if ( ! V_41 -> V_42 )
return false ;
if ( V_5 == V_7 )
return false ;
if ( F_51 ( V_45 ) &&
! ( F_203 ( V_41 -> V_58 ) && V_41 -> V_43 ) )
return true ;
if ( V_192 -> V_52 == 1 && F_50 ( V_45 ) &&
! F_204 ( V_41 , & V_192 -> V_158 , false ) )
return true ;
F_79 ( V_41 , V_45 , L_14 ,
V_192 -> V_52 ) ;
return false ;
}
static void F_205 ( struct V_40 * V_41 )
{
struct V_44 * V_45 = V_41 -> V_220 ;
struct V_53 * V_59 ;
unsigned long V_226 , V_227 = 0 ;
if ( F_203 ( V_41 -> V_58 ) && V_41 -> V_43 )
return;
F_66 ( ! F_155 ( & V_45 -> V_131 ) ) ;
F_66 ( F_81 ( V_45 ) ) ;
if ( ! F_202 ( V_41 , V_45 ) ) {
if ( V_41 -> V_228 )
V_227 = V_41 -> V_228 ;
else
return;
}
if ( V_45 -> V_229 )
return;
V_59 = V_41 -> V_223 ;
if ( ! V_59 || ! F_206 ( & V_59 -> V_55 . V_57 -> V_230 ) )
return;
if ( F_207 ( V_59 -> V_158 . V_231 ) &&
( V_45 -> V_106 - V_105 < V_59 -> V_158 . V_232 ) ) {
F_79 ( V_41 , V_45 , L_15 ,
V_59 -> V_158 . V_232 ) ;
return;
}
if ( V_227 && V_45 -> V_3 -> V_132 > 1 )
return;
F_208 ( V_45 ) ;
if ( V_227 )
V_226 = V_41 -> V_228 ;
else
V_226 = V_41 -> V_42 ;
F_209 ( & V_41 -> V_221 , V_105 + V_226 ) ;
F_24 ( V_45 -> V_3 ) ;
F_79 ( V_41 , V_45 , L_16 , V_226 ,
V_227 ? 1 : 0 ) ;
}
static void F_210 ( struct V_162 * V_61 , struct V_108 * V_205 )
{
struct V_40 * V_41 = V_61 -> V_62 -> V_63 ;
struct V_44 * V_45 = F_153 ( V_205 ) ;
F_79 ( V_41 , V_45 , L_17 ) ;
V_45 -> V_200 = F_96 ( V_41 , V_45 , V_205 ) ;
F_166 ( V_205 ) ;
V_45 -> V_229 ++ ;
( F_159 ( V_205 ) ) -> V_229 ++ ;
F_211 ( V_61 , V_205 ) ;
V_41 -> V_233 [ F_50 ( V_45 ) ] ++ ;
V_45 -> V_154 += F_164 ( V_205 ) ;
F_40 ( V_45 -> V_3 , F_212 ( V_205 ) , V_205 -> V_118 ) ;
}
static struct V_108 * F_213 ( struct V_44 * V_45 )
{
struct V_108 * V_205 = NULL ;
if ( F_214 ( V_45 ) )
return NULL ;
F_215 ( V_45 ) ;
if ( F_173 ( & V_45 -> V_234 ) )
return NULL ;
V_205 = F_216 ( V_45 -> V_234 . V_129 ) ;
if ( F_82 ( V_105 , F_174 ( V_205 ) ) )
V_205 = NULL ;
F_79 ( V_45 -> V_41 , V_45 , L_18 , V_205 ) ;
return V_205 ;
}
static inline int
F_217 ( struct V_40 * V_41 , struct V_44 * V_45 )
{
const int V_235 = V_41 -> V_236 ;
F_66 ( V_45 -> V_75 >= V_73 ) ;
return 2 * V_235 * ( V_73 - V_45 -> V_75 ) ;
}
static int F_218 ( struct V_44 * V_45 )
{
int V_237 , V_238 ;
V_238 = V_45 -> V_239 [ V_65 ] + V_45 -> V_239 [ V_240 ] ;
V_237 = V_45 -> V_241 - V_238 ;
F_25 ( V_237 < 0 ) ;
return V_237 ;
}
static void F_219 ( struct V_44 * V_45 , struct V_44 * V_193 )
{
int V_237 , V_242 ;
struct V_44 * V_190 ;
if ( ! F_218 ( V_193 ) )
return;
while ( ( V_190 = V_193 -> V_193 ) ) {
if ( V_190 == V_45 )
return;
V_193 = V_190 ;
}
V_237 = F_218 ( V_45 ) ;
V_242 = F_218 ( V_193 ) ;
if ( V_237 == 0 || V_242 == 0 )
return;
if ( V_242 >= V_237 ) {
V_45 -> V_193 = V_193 ;
V_193 -> V_241 += V_237 ;
} else {
V_193 -> V_193 = V_45 ;
V_45 -> V_241 += V_242 ;
}
}
static enum V_6 F_220 ( struct V_40 * V_41 ,
struct V_2 * V_3 , enum V_4 V_5 )
{
struct V_44 * V_58 ;
int V_155 ;
bool V_243 = false ;
unsigned long V_244 = 0 ;
enum V_6 V_245 = V_49 ;
for ( V_155 = 0 ; V_155 <= V_50 ; ++ V_155 ) {
V_58 = F_88 ( F_1 ( V_3 , V_5 , V_155 ) ) ;
if ( V_58 &&
( ! V_243 || F_82 ( V_58 -> V_191 , V_244 ) ) ) {
V_244 = V_58 -> V_191 ;
V_245 = V_155 ;
V_243 = true ;
}
}
return V_245 ;
}
static void F_221 ( struct V_40 * V_41 , struct V_2 * V_3 )
{
unsigned V_96 ;
unsigned V_52 ;
struct V_1 * V_83 ;
unsigned V_101 ;
enum V_4 V_246 = V_41 -> V_153 ;
if ( F_52 ( V_46 , V_41 , V_3 ) )
V_41 -> V_153 = V_46 ;
else if ( F_52 ( V_47 , V_41 , V_3 ) )
V_41 -> V_153 = V_47 ;
else {
V_41 -> V_153 = V_7 ;
V_41 -> V_149 = V_105 + 1 ;
return;
}
if ( V_246 != V_41 -> V_153 )
goto V_247;
V_83 = F_1 ( V_3 , V_41 -> V_153 , V_41 -> V_151 ) ;
V_52 = V_83 -> V_52 ;
if ( V_52 && ! F_115 ( V_105 , V_41 -> V_149 ) )
return;
V_247:
V_41 -> V_151 =
F_220 ( V_41 , V_3 , V_41 -> V_153 ) ;
V_83 = F_1 ( V_3 , V_41 -> V_153 , V_41 -> V_151 ) ;
V_52 = V_83 -> V_52 ;
V_101 = F_76 ( V_41 , V_3 ) ;
V_96 = V_101 * V_52 /
F_114 ( unsigned , V_3 -> V_92 [ V_41 -> V_153 ] ,
F_52 ( V_41 -> V_153 , V_41 , V_3 ) ) ;
if ( V_41 -> V_151 == V_48 ) {
unsigned int V_248 ;
V_248 = V_41 -> V_94 *
F_53 ( V_41 , V_3 ) ;
V_248 = V_248 / V_41 -> V_68 ;
V_96 = F_222 ( unsigned , V_96 , V_248 ) ;
V_96 = V_96 * V_41 -> V_72 [ 0 ] / V_41 -> V_72 [ 1 ] ;
} else
V_96 = F_75 ( V_96 , 2 * V_41 -> V_42 ) ;
V_96 = F_114 ( unsigned , V_96 , V_249 ) ;
F_63 ( V_41 , L_19 , V_96 ) ;
V_41 -> V_149 = V_105 + V_96 ;
}
static struct V_2 * F_196 ( struct V_40 * V_41 )
{
struct V_1 * V_83 = & V_41 -> V_93 ;
struct V_2 * V_3 ;
if ( F_155 ( & V_83 -> V_123 ) )
return NULL ;
V_3 = F_91 ( V_83 ) ;
F_71 ( V_83 ) ;
return V_3 ;
}
static void F_223 ( struct V_40 * V_41 )
{
struct V_2 * V_3 = F_196 ( V_41 ) ;
V_41 -> V_207 = V_3 ;
if ( V_3 -> V_141 ) {
V_41 -> V_149 = V_105 + V_3 -> V_141 ;
V_41 -> V_151 = V_3 -> V_150 ;
V_41 -> V_153 = V_3 -> V_152 ;
} else
V_41 -> V_149 = V_105 - 1 ;
F_221 ( V_41 , V_3 ) ;
}
static struct V_44 * F_224 ( struct V_40 * V_41 )
{
struct V_44 * V_45 , * V_193 = NULL ;
V_45 = V_41 -> V_220 ;
if ( ! V_45 )
goto V_250;
if ( ! V_41 -> V_214 )
return NULL ;
if ( F_225 ( V_45 ) && ! F_155 ( & V_45 -> V_131 ) )
goto V_251;
if ( F_80 ( V_45 ) && ! F_226 ( V_45 ) ) {
if ( V_45 -> V_3 -> V_132 == 1 && F_155 ( & V_45 -> V_131 )
&& V_45 -> V_229 && F_202 ( V_41 , V_45 ) ) {
V_45 = NULL ;
goto V_252;
} else
goto V_253;
}
if ( ! F_155 ( & V_45 -> V_131 ) )
goto V_252;
V_193 = F_201 ( V_41 , V_45 ) ;
if ( V_193 ) {
if ( ! V_45 -> V_193 )
F_219 ( V_45 , V_193 ) ;
goto V_251;
}
if ( F_227 ( & V_41 -> V_221 ) ) {
V_45 = NULL ;
goto V_252;
}
if ( F_190 ( V_45 ) && F_51 ( V_45 ) &&
( F_81 ( V_45 ) ||
( V_45 -> V_106 - V_105 > V_105 - V_45 -> V_104 ) ) ) {
F_228 ( V_45 ) ;
F_229 ( V_45 ) ;
}
if ( V_45 -> V_229 && F_202 ( V_41 , V_45 ) ) {
V_45 = NULL ;
goto V_252;
}
V_253:
if ( V_41 -> V_228 && V_45 -> V_3 -> V_132 == 1 &&
V_45 -> V_3 -> V_229 &&
! F_204 ( V_41 , & V_45 -> V_3 -> V_158 , true ) ) {
V_45 = NULL ;
goto V_252;
}
V_251:
F_193 ( V_41 , 0 ) ;
V_250:
if ( ! V_193 )
F_223 ( V_41 ) ;
V_45 = F_197 ( V_41 , V_193 ) ;
V_252:
return V_45 ;
}
static int F_230 ( struct V_44 * V_45 )
{
int V_229 = 0 ;
while ( V_45 -> V_200 ) {
F_210 ( V_45 -> V_41 -> V_58 , V_45 -> V_200 ) ;
V_229 ++ ;
}
F_25 ( ! F_173 ( & V_45 -> V_234 ) ) ;
F_186 ( V_45 -> V_41 , V_45 , 0 ) ;
return V_229 ;
}
static int F_231 ( struct V_40 * V_41 )
{
struct V_44 * V_45 ;
int V_229 = 0 ;
F_193 ( V_41 , 0 ) ;
while ( ( V_45 = F_195 ( V_41 ) ) != NULL ) {
F_180 ( V_41 , V_45 ) ;
V_229 += F_230 ( V_45 ) ;
}
F_25 ( V_41 -> V_68 ) ;
F_63 ( V_41 , L_20 , V_229 ) ;
return V_229 ;
}
static inline bool F_232 ( struct V_40 * V_41 ,
struct V_44 * V_45 )
{
if ( F_81 ( V_45 ) )
return true ;
if ( F_115 ( V_105 + V_41 -> V_42 * V_45 -> V_229 ,
V_45 -> V_106 ) )
return true ;
return false ;
}
static bool F_233 ( struct V_40 * V_41 , struct V_44 * V_45 )
{
unsigned int V_254 ;
if ( F_202 ( V_41 , V_45 ) && V_41 -> V_233 [ V_255 ] )
return false ;
if ( V_41 -> V_233 [ V_256 ] && ! F_50 ( V_45 ) )
return false ;
V_254 = F_114 (unsigned int, cfqd->cfq_quantum / 2 , 1 ) ;
if ( F_47 ( V_45 ) )
V_254 = 1 ;
if ( V_45 -> V_229 >= V_254 ) {
bool V_257 = false ;
if ( F_47 ( V_45 ) )
return false ;
if ( F_50 ( V_45 ) && V_41 -> V_204 == 1 )
V_257 = true ;
if ( V_41 -> V_68 > 1 && F_232 ( V_41 , V_45 ) &&
! V_257 )
return false ;
if ( V_41 -> V_68 == 1 || V_257 )
V_254 = - 1 ;
else
V_254 = V_41 -> V_258 ;
}
if ( ! F_50 ( V_45 ) && V_41 -> V_97 ) {
unsigned long V_259 = V_105 - V_41 -> V_260 ;
unsigned int V_261 ;
V_261 = V_259 / V_41 -> V_72 [ 1 ] ;
if ( ! V_261 && ! V_45 -> V_229 )
V_261 = 1 ;
if ( V_261 < V_254 )
V_254 = V_261 ;
}
return V_45 -> V_229 < V_254 ;
}
static bool F_234 ( struct V_40 * V_41 , struct V_44 * V_45 )
{
struct V_108 * V_205 ;
F_25 ( F_155 ( & V_45 -> V_131 ) ) ;
if ( ! F_233 ( V_41 , V_45 ) )
return false ;
V_205 = F_213 ( V_45 ) ;
if ( ! V_205 )
V_205 = V_45 -> V_200 ;
F_210 ( V_41 -> V_58 , V_205 ) ;
if ( ! V_41 -> V_223 ) {
struct V_53 * V_59 = F_235 ( V_205 ) ;
F_236 ( & V_59 -> V_55 . V_57 -> V_262 ) ;
V_41 -> V_223 = V_59 ;
}
return true ;
}
static int F_237 ( struct V_162 * V_61 , int V_263 )
{
struct V_40 * V_41 = V_61 -> V_62 -> V_63 ;
struct V_44 * V_45 ;
if ( ! V_41 -> V_68 )
return 0 ;
if ( F_238 ( V_263 ) )
return F_231 ( V_41 ) ;
V_45 = F_224 ( V_41 ) ;
if ( ! V_45 )
return 0 ;
if ( ! F_234 ( V_41 , V_45 ) )
return 0 ;
V_45 -> V_148 ++ ;
F_182 ( V_45 ) ;
if ( V_41 -> V_68 > 1 && ( ( ! F_50 ( V_45 ) &&
V_45 -> V_148 >= F_217 ( V_41 , V_45 ) ) ||
F_47 ( V_45 ) ) ) {
V_45 -> V_106 = V_105 + 1 ;
F_193 ( V_41 , 0 ) ;
}
F_79 ( V_41 , V_45 , L_21 ) ;
return 1 ;
}
static void F_239 ( struct V_44 * V_45 )
{
struct V_40 * V_41 = V_45 -> V_41 ;
struct V_2 * V_3 ;
F_25 ( V_45 -> V_241 <= 0 ) ;
V_45 -> V_241 -- ;
if ( V_45 -> V_241 )
return;
F_79 ( V_41 , V_45 , L_22 ) ;
F_25 ( F_89 ( & V_45 -> V_131 ) ) ;
F_25 ( V_45 -> V_239 [ V_65 ] + V_45 -> V_239 [ V_240 ] ) ;
V_3 = V_45 -> V_3 ;
if ( F_238 ( V_41 -> V_220 == V_45 ) ) {
F_186 ( V_41 , V_45 , 0 ) ;
F_62 ( V_41 ) ;
}
F_25 ( F_147 ( V_45 ) ) ;
F_240 ( V_264 , V_45 ) ;
F_32 ( V_3 ) ;
}
static void F_241 ( struct V_44 * V_45 )
{
struct V_44 * V_190 , * V_129 ;
V_190 = V_45 -> V_193 ;
while ( V_190 ) {
if ( V_190 == V_45 ) {
F_242 ( 1 , L_23 ) ;
break;
}
V_129 = V_190 -> V_193 ;
F_239 ( V_190 ) ;
V_190 = V_129 ;
}
}
static void F_243 ( struct V_40 * V_41 , struct V_44 * V_45 )
{
if ( F_238 ( V_45 == V_41 -> V_220 ) ) {
F_186 ( V_41 , V_45 , 0 ) ;
F_62 ( V_41 ) ;
}
F_241 ( V_45 ) ;
F_239 ( V_45 ) ;
}
static void F_244 ( struct V_54 * V_55 )
{
struct V_53 * V_59 = F_54 ( V_55 ) ;
V_59 -> V_158 . V_159 = V_105 ;
}
static void F_245 ( struct V_54 * V_55 )
{
struct V_53 * V_59 = F_54 ( V_55 ) ;
struct V_40 * V_41 = F_59 ( V_59 ) ;
if ( V_59 -> V_45 [ V_255 ] ) {
F_243 ( V_41 , V_59 -> V_45 [ V_255 ] ) ;
V_59 -> V_45 [ V_255 ] = NULL ;
}
if ( V_59 -> V_45 [ V_256 ] ) {
F_243 ( V_41 , V_59 -> V_45 [ V_256 ] ) ;
V_59 -> V_45 [ V_256 ] = NULL ;
}
}
static void F_246 ( struct V_44 * V_45 , struct V_53 * V_59 )
{
struct V_208 * V_209 = V_210 ;
int V_265 ;
if ( ! F_247 ( V_45 ) )
return;
V_265 = F_248 ( V_59 -> V_75 ) ;
switch ( V_265 ) {
default:
F_249 ( V_266 L_24 , V_265 ) ;
case V_267 :
V_45 -> V_75 = F_250 ( V_209 ) ;
V_45 -> V_265 = F_251 ( V_209 ) ;
break;
case V_268 :
V_45 -> V_75 = F_252 ( V_59 -> V_75 ) ;
V_45 -> V_265 = V_268 ;
break;
case V_269 :
V_45 -> V_75 = F_252 ( V_59 -> V_75 ) ;
V_45 -> V_265 = V_269 ;
break;
case V_270 :
V_45 -> V_265 = V_270 ;
V_45 -> V_75 = 7 ;
F_229 ( V_45 ) ;
break;
}
V_45 -> V_203 = V_45 -> V_75 ;
F_253 ( V_45 ) ;
}
static void F_254 ( struct V_53 * V_59 , struct V_64 * V_64 )
{
int V_75 = V_59 -> V_55 . V_57 -> V_75 ;
struct V_40 * V_41 = F_59 ( V_59 ) ;
struct V_44 * V_45 ;
if ( F_238 ( ! V_41 ) || F_255 ( V_59 -> V_75 == V_75 ) )
return;
V_45 = V_59 -> V_45 [ V_255 ] ;
if ( V_45 ) {
struct V_44 * V_193 ;
V_193 = F_256 ( V_41 , V_255 , V_59 , V_64 ,
V_271 ) ;
if ( V_193 ) {
V_59 -> V_45 [ V_255 ] = V_193 ;
F_239 ( V_45 ) ;
}
}
V_45 = V_59 -> V_45 [ V_256 ] ;
if ( V_45 )
F_257 ( V_45 ) ;
V_59 -> V_75 = V_75 ;
}
static void F_258 ( struct V_40 * V_41 , struct V_44 * V_45 ,
T_5 V_272 , bool V_60 )
{
F_94 ( & V_45 -> V_124 ) ;
F_94 ( & V_45 -> V_199 ) ;
F_259 ( & V_45 -> V_234 ) ;
V_45 -> V_241 = 0 ;
V_45 -> V_41 = V_41 ;
F_257 ( V_45 ) ;
if ( V_60 ) {
if ( ! F_47 ( V_45 ) )
F_260 ( V_45 ) ;
F_261 ( V_45 ) ;
}
V_45 -> V_272 = V_272 ;
}
static void F_262 ( struct V_53 * V_59 , struct V_64 * V_64 )
{
struct V_40 * V_41 = F_59 ( V_59 ) ;
struct V_44 * V_273 ;
T_1 V_274 ;
F_263 () ;
V_274 = F_264 ( V_64 ) -> V_274 ;
F_265 () ;
if ( F_238 ( ! V_41 ) || F_255 ( V_59 -> V_275 == V_274 ) )
return;
V_273 = F_57 ( V_59 , 1 ) ;
if ( V_273 ) {
F_79 ( V_41 , V_273 , L_25 ) ;
F_58 ( V_59 , NULL , 1 ) ;
F_239 ( V_273 ) ;
}
V_59 -> V_275 = V_274 ;
}
static inline void F_262 ( struct V_53 * V_59 , struct V_64 * V_64 ) { }
static struct V_44 *
F_266 ( struct V_40 * V_41 , bool V_60 , struct V_53 * V_59 ,
struct V_64 * V_64 , T_6 V_276 )
{
struct V_160 * V_160 ;
struct V_44 * V_45 , * V_193 = NULL ;
struct V_2 * V_3 ;
V_277:
F_263 () ;
V_160 = F_264 ( V_64 ) ;
V_3 = F_120 ( V_41 , V_160 ) ;
V_45 = F_57 ( V_59 , V_60 ) ;
if ( ! V_45 || V_45 == & V_41 -> V_278 ) {
V_45 = NULL ;
if ( V_193 ) {
V_45 = V_193 ;
V_193 = NULL ;
} else if ( V_276 & V_279 ) {
F_265 () ;
F_137 ( V_41 -> V_58 -> V_280 ) ;
V_193 = F_267 ( V_264 ,
V_276 | V_281 ,
V_41 -> V_58 -> V_133 ) ;
F_135 ( V_41 -> V_58 -> V_280 ) ;
if ( V_193 )
goto V_277;
} else {
V_45 = F_267 ( V_264 ,
V_276 | V_281 ,
V_41 -> V_58 -> V_133 ) ;
}
if ( V_45 ) {
F_258 ( V_41 , V_45 , V_210 -> V_272 , V_60 ) ;
F_246 ( V_45 , V_59 ) ;
F_123 ( V_45 , V_3 ) ;
F_79 ( V_41 , V_45 , L_26 ) ;
} else
V_45 = & V_41 -> V_278 ;
}
if ( V_193 )
F_240 ( V_264 , V_193 ) ;
F_265 () ;
return V_45 ;
}
static struct V_44 * *
F_268 ( struct V_40 * V_41 , int V_265 , int V_75 )
{
switch ( V_265 ) {
case V_268 :
return & V_41 -> V_282 [ 0 ] [ V_75 ] ;
case V_267 :
V_75 = V_283 ;
case V_269 :
return & V_41 -> V_282 [ 1 ] [ V_75 ] ;
case V_270 :
return & V_41 -> V_284 ;
default:
F_269 () ;
}
}
static struct V_44 *
F_256 ( struct V_40 * V_41 , bool V_60 , struct V_53 * V_59 ,
struct V_64 * V_64 , T_6 V_276 )
{
const int V_265 = F_248 ( V_59 -> V_75 ) ;
const int V_75 = F_252 ( V_59 -> V_75 ) ;
struct V_44 * * V_282 = NULL ;
struct V_44 * V_45 = NULL ;
if ( ! V_60 ) {
V_282 = F_268 ( V_41 , V_265 , V_75 ) ;
V_45 = * V_282 ;
}
if ( ! V_45 )
V_45 = F_266 ( V_41 , V_60 , V_59 , V_64 , V_276 ) ;
if ( ! V_60 && ! ( * V_282 ) ) {
V_45 -> V_241 ++ ;
* V_282 = V_45 ;
}
V_45 -> V_241 ++ ;
return V_45 ;
}
static void
F_270 ( struct V_285 * V_158 , unsigned long V_286 )
{
unsigned long V_287 = V_105 - V_158 -> V_159 ;
V_287 = F_74 ( V_287 , 2UL * V_286 ) ;
V_158 -> V_231 = ( 7 * V_158 -> V_231 + 256 ) / 8 ;
V_158 -> V_288 = ( 7 * V_158 -> V_288 + 256 * V_287 ) / 8 ;
V_158 -> V_232 = ( V_158 -> V_288 + 128 ) / V_158 -> V_231 ;
}
static void
F_271 ( struct V_40 * V_41 , struct V_44 * V_45 ,
struct V_53 * V_59 )
{
if ( F_50 ( V_45 ) ) {
F_270 ( & V_59 -> V_158 , V_41 -> V_42 ) ;
F_270 ( & V_45 -> V_192 -> V_158 ,
V_41 -> V_42 ) ;
}
#ifdef F_272
F_270 ( & V_45 -> V_3 -> V_158 , V_41 -> V_228 ) ;
#endif
}
static void
F_273 ( struct V_40 * V_41 , struct V_44 * V_45 ,
struct V_108 * V_205 )
{
T_4 V_289 = 0 ;
T_4 V_290 = F_164 ( V_205 ) ;
if ( V_45 -> V_291 ) {
if ( V_45 -> V_291 < F_87 ( V_205 ) )
V_289 = F_87 ( V_205 ) - V_45 -> V_291 ;
else
V_289 = V_45 -> V_291 - F_87 ( V_205 ) ;
}
V_45 -> V_292 <<= 1 ;
if ( F_203 ( V_41 -> V_58 ) )
V_45 -> V_292 |= ( V_290 < V_293 ) ;
else
V_45 -> V_292 |= ( V_289 > V_294 ) ;
}
static void
F_274 ( struct V_40 * V_41 , struct V_44 * V_45 ,
struct V_53 * V_59 )
{
int V_295 , V_296 ;
if ( ! F_50 ( V_45 ) || F_47 ( V_45 ) )
return;
V_296 = V_295 = F_51 ( V_45 ) ;
if ( V_45 -> V_22 [ 0 ] + V_45 -> V_22 [ 1 ] >= 4 )
F_275 ( V_45 ) ;
if ( V_45 -> V_200 && ( V_45 -> V_200 -> V_118 & V_297 ) )
V_296 = 0 ;
else if ( ! F_206 ( & V_59 -> V_55 . V_57 -> V_230 ) ||
! V_41 -> V_42 ||
( ! F_276 ( V_45 ) && F_190 ( V_45 ) ) )
V_296 = 0 ;
else if ( F_207 ( V_59 -> V_158 . V_231 ) ) {
if ( V_59 -> V_158 . V_232 > V_41 -> V_42 )
V_296 = 0 ;
else
V_296 = 1 ;
}
if ( V_295 != V_296 ) {
F_79 ( V_41 , V_45 , L_27 , V_296 ) ;
if ( V_296 )
F_260 ( V_45 ) ;
else
F_229 ( V_45 ) ;
}
}
static bool
F_277 ( struct V_40 * V_41 , struct V_44 * V_193 ,
struct V_108 * V_205 )
{
struct V_44 * V_45 ;
V_45 = V_41 -> V_220 ;
if ( ! V_45 )
return false ;
if ( F_47 ( V_193 ) )
return false ;
if ( F_47 ( V_45 ) )
return true ;
if ( F_48 ( V_45 ) && ! F_48 ( V_193 ) )
return false ;
if ( F_86 ( V_205 ) && ! F_50 ( V_45 ) )
return true ;
if ( V_193 -> V_3 != V_45 -> V_3 )
return false ;
if ( F_80 ( V_45 ) )
return true ;
if ( V_41 -> V_151 == V_49 &&
F_49 ( V_193 ) == V_49 &&
V_193 -> V_192 -> V_52 == 2 &&
F_155 ( & V_45 -> V_131 ) )
return true ;
if ( ( V_205 -> V_118 & V_119 ) && ! V_45 -> V_215 )
return true ;
if ( F_48 ( V_193 ) && ! F_48 ( V_45 ) )
return true ;
if ( F_155 ( & V_45 -> V_131 ) && ! F_202 ( V_41 , V_45 ) )
return true ;
if ( ! V_41 -> V_223 || ! F_187 ( V_45 ) )
return false ;
if ( F_199 ( V_41 , V_45 , V_205 ) )
return true ;
return false ;
}
static void F_278 ( struct V_40 * V_41 , struct V_44 * V_45 )
{
enum V_6 V_298 = F_49 ( V_41 -> V_220 ) ;
F_79 ( V_41 , V_45 , L_28 ) ;
F_193 ( V_41 , 1 ) ;
if ( V_298 != F_49 ( V_45 ) )
V_45 -> V_3 -> V_141 = 0 ;
F_25 ( ! F_147 ( V_45 ) ) ;
F_143 ( V_41 , V_45 , 1 ) ;
V_45 -> V_106 = 0 ;
F_185 ( V_45 ) ;
}
static void
F_279 ( struct V_40 * V_41 , struct V_44 * V_45 ,
struct V_108 * V_205 )
{
struct V_53 * V_59 = F_235 ( V_205 ) ;
V_41 -> V_214 ++ ;
if ( V_205 -> V_118 & V_119 )
V_45 -> V_215 ++ ;
F_271 ( V_41 , V_45 , V_59 ) ;
F_273 ( V_41 , V_45 , V_205 ) ;
F_274 ( V_41 , V_45 , V_59 ) ;
V_45 -> V_291 = F_87 ( V_205 ) + F_164 ( V_205 ) ;
if ( V_45 == V_41 -> V_220 ) {
if ( F_187 ( V_45 ) ) {
if ( F_212 ( V_205 ) > V_299 ||
V_41 -> V_68 > 1 ) {
F_178 ( V_41 , V_45 ) ;
F_181 ( V_45 ) ;
F_280 ( V_41 -> V_58 ) ;
} else {
F_21 ( V_45 -> V_3 ) ;
F_281 ( V_45 ) ;
}
}
} else if ( F_277 ( V_41 , V_45 , V_205 ) ) {
F_278 ( V_41 , V_45 ) ;
F_280 ( V_41 -> V_58 ) ;
}
}
static void F_282 ( struct V_162 * V_61 , struct V_108 * V_205 )
{
struct V_40 * V_41 = V_61 -> V_62 -> V_63 ;
struct V_44 * V_45 = F_153 ( V_205 ) ;
F_79 ( V_41 , V_45 , L_29 ) ;
F_246 ( V_45 , F_235 ( V_205 ) ) ;
F_176 ( V_205 , V_105 + V_41 -> V_300 [ F_86 ( V_205 ) ] ) ;
F_283 ( & V_205 -> V_213 , & V_45 -> V_234 ) ;
F_156 ( V_205 ) ;
F_34 ( F_159 ( V_205 ) , V_41 -> V_207 ,
V_205 -> V_118 ) ;
F_279 ( V_41 , V_45 , V_205 ) ;
}
static void F_284 ( struct V_40 * V_41 )
{
struct V_44 * V_45 = V_41 -> V_220 ;
if ( V_41 -> V_212 > V_41 -> V_301 )
V_41 -> V_301 = V_41 -> V_212 ;
if ( V_41 -> V_43 == 1 )
return;
if ( V_41 -> V_214 <= V_302 &&
V_41 -> V_212 <= V_302 )
return;
if ( V_45 && F_51 ( V_45 ) &&
V_45 -> V_229 + V_45 -> V_22 [ 0 ] + V_45 -> V_22 [ 1 ] <
V_302 && V_41 -> V_212 < V_302 )
return;
if ( V_41 -> V_303 ++ < 50 )
return;
if ( V_41 -> V_301 >= V_302 )
V_41 -> V_43 = 1 ;
else
V_41 -> V_43 = 0 ;
}
static bool F_285 ( struct V_40 * V_41 , struct V_44 * V_45 )
{
struct V_53 * V_59 = V_41 -> V_223 ;
if ( ! F_155 ( & V_45 -> V_131 ) )
return false ;
if ( V_45 -> V_3 -> V_132 > 1 )
return false ;
if ( F_204 ( V_41 , & V_45 -> V_3 -> V_158 , true ) )
return false ;
if ( F_80 ( V_45 ) )
return true ;
if ( V_59 && F_207 ( V_59 -> V_158 . V_231 )
&& ( V_45 -> V_106 - V_105 < V_59 -> V_158 . V_232 ) )
return true ;
if ( V_45 -> V_106 - V_105 == 1 )
return true ;
return false ;
}
static void F_286 ( struct V_162 * V_61 , struct V_108 * V_205 )
{
struct V_44 * V_45 = F_153 ( V_205 ) ;
struct V_40 * V_41 = V_45 -> V_41 ;
const int V_70 = F_86 ( V_205 ) ;
unsigned long V_15 ;
V_15 = V_105 ;
F_79 ( V_41 , V_45 , L_30 ,
! ! ( V_205 -> V_118 & V_297 ) ) ;
F_284 ( V_41 ) ;
F_66 ( ! V_41 -> V_212 ) ;
F_66 ( ! V_45 -> V_229 ) ;
V_41 -> V_212 -- ;
V_45 -> V_229 -- ;
( F_159 ( V_205 ) ) -> V_229 -- ;
F_41 ( V_45 -> V_3 , F_287 ( V_205 ) ,
F_288 ( V_205 ) , V_205 -> V_118 ) ;
V_41 -> V_233 [ F_50 ( V_45 ) ] -- ;
if ( V_70 ) {
struct V_1 * V_192 ;
F_235 ( V_205 ) -> V_158 . V_159 = V_15 ;
if ( F_147 ( V_45 ) )
V_192 = V_45 -> V_192 ;
else
V_192 = F_1 ( V_45 -> V_3 ,
F_46 ( V_45 ) , F_49 ( V_45 ) ) ;
V_192 -> V_158 . V_159 = V_15 ;
if ( ! F_115 ( V_205 -> V_36 + V_41 -> V_300 [ 1 ] , V_15 ) )
V_41 -> V_260 = V_15 ;
}
#ifdef F_272
V_45 -> V_3 -> V_158 . V_159 = V_15 ;
#endif
if ( V_41 -> V_220 == V_45 ) {
const bool V_304 = F_155 ( & V_45 -> V_131 ) ;
if ( F_81 ( V_45 ) ) {
F_78 ( V_41 , V_45 ) ;
F_289 ( V_45 ) ;
}
if ( F_285 ( V_41 , V_45 ) ) {
unsigned long V_305 = V_41 -> V_42 ;
if ( ! V_41 -> V_42 )
V_305 = V_41 -> V_228 ;
V_45 -> V_106 = V_105 + V_305 ;
F_290 ( V_45 ) ;
F_79 ( V_41 , V_45 , L_31 ) ;
}
if ( F_80 ( V_45 ) || F_47 ( V_45 ) )
F_193 ( V_41 , 1 ) ;
else if ( V_70 && V_304 &&
! F_201 ( V_41 , V_45 ) ) {
F_205 ( V_41 ) ;
}
}
if ( ! V_41 -> V_212 )
F_62 ( V_41 ) ;
}
static inline int F_291 ( struct V_44 * V_45 )
{
if ( F_187 ( V_45 ) && ! F_292 ( V_45 ) ) {
F_293 ( V_45 ) ;
return V_306 ;
}
return V_307 ;
}
static int F_294 ( struct V_162 * V_61 , int V_29 )
{
struct V_40 * V_41 = V_61 -> V_62 -> V_63 ;
struct V_208 * V_209 = V_210 ;
struct V_53 * V_59 ;
struct V_44 * V_45 ;
V_59 = F_55 ( V_41 , V_209 -> V_56 ) ;
if ( ! V_59 )
return V_307 ;
V_45 = F_57 ( V_59 , F_295 ( V_29 ) ) ;
if ( V_45 ) {
F_246 ( V_45 , V_59 ) ;
return F_291 ( V_45 ) ;
}
return V_307 ;
}
static void F_296 ( struct V_108 * V_205 )
{
struct V_44 * V_45 = F_153 ( V_205 ) ;
if ( V_45 ) {
const int V_29 = F_297 ( V_205 ) ;
F_25 ( ! V_45 -> V_239 [ V_29 ] ) ;
V_45 -> V_239 [ V_29 ] -- ;
F_32 ( F_159 ( V_205 ) ) ;
V_205 -> V_308 . V_309 [ 0 ] = NULL ;
V_205 -> V_308 . V_309 [ 1 ] = NULL ;
F_239 ( V_45 ) ;
}
}
static struct V_44 *
F_298 ( struct V_40 * V_41 , struct V_53 * V_59 ,
struct V_44 * V_45 )
{
F_79 ( V_41 , V_45 , L_32 , V_45 -> V_193 ) ;
F_58 ( V_59 , V_45 -> V_193 , 1 ) ;
F_299 ( V_45 -> V_193 ) ;
F_239 ( V_45 ) ;
return F_57 ( V_59 , 1 ) ;
}
static struct V_44 *
F_300 ( struct V_53 * V_59 , struct V_44 * V_45 )
{
if ( F_218 ( V_45 ) == 1 ) {
V_45 -> V_272 = V_210 -> V_272 ;
F_301 ( V_45 ) ;
F_302 ( V_45 ) ;
return V_45 ;
}
F_58 ( V_59 , NULL , 1 ) ;
F_241 ( V_45 ) ;
F_239 ( V_45 ) ;
return NULL ;
}
static int
F_303 ( struct V_162 * V_61 , struct V_108 * V_205 , struct V_64 * V_64 ,
T_6 V_276 )
{
struct V_40 * V_41 = V_61 -> V_62 -> V_63 ;
struct V_53 * V_59 = F_54 ( V_205 -> V_308 . V_55 ) ;
const int V_29 = F_297 ( V_205 ) ;
const bool V_60 = F_86 ( V_205 ) ;
struct V_44 * V_45 ;
F_304 ( V_276 & V_279 ) ;
F_135 ( V_61 -> V_280 ) ;
F_254 ( V_59 , V_64 ) ;
F_262 ( V_59 , V_64 ) ;
V_250:
V_45 = F_57 ( V_59 , V_60 ) ;
if ( ! V_45 || V_45 == & V_41 -> V_278 ) {
V_45 = F_256 ( V_41 , V_60 , V_59 , V_64 , V_276 ) ;
F_58 ( V_59 , V_45 , V_60 ) ;
} else {
if ( F_189 ( V_45 ) && F_305 ( V_45 ) ) {
F_79 ( V_41 , V_45 , L_33 ) ;
V_45 = F_300 ( V_59 , V_45 ) ;
if ( ! V_45 )
goto V_250;
}
if ( V_45 -> V_193 )
V_45 = F_298 ( V_41 , V_59 , V_45 ) ;
}
V_45 -> V_239 [ V_29 ] ++ ;
V_45 -> V_241 ++ ;
F_30 ( V_45 -> V_3 ) ;
V_205 -> V_308 . V_309 [ 0 ] = V_45 ;
V_205 -> V_308 . V_309 [ 1 ] = V_45 -> V_3 ;
F_137 ( V_61 -> V_280 ) ;
return 0 ;
}
static void F_306 ( struct V_310 * V_311 )
{
struct V_40 * V_41 =
F_3 ( V_311 , struct V_40 , V_69 ) ;
struct V_162 * V_61 = V_41 -> V_58 ;
F_135 ( V_61 -> V_280 ) ;
F_280 ( V_41 -> V_58 ) ;
F_137 ( V_61 -> V_280 ) ;
}
static void F_307 ( unsigned long V_312 )
{
struct V_40 * V_41 = (struct V_40 * ) V_312 ;
struct V_44 * V_45 ;
unsigned long V_313 ;
int V_222 = 1 ;
F_63 ( V_41 , L_34 ) ;
F_308 ( V_41 -> V_58 -> V_280 , V_313 ) ;
V_45 = V_41 -> V_220 ;
if ( V_45 ) {
V_222 = 0 ;
if ( F_226 ( V_45 ) )
goto V_314;
if ( F_80 ( V_45 ) )
goto V_251;
if ( ! V_41 -> V_68 )
goto V_315;
if ( ! F_155 ( & V_45 -> V_131 ) )
goto V_314;
F_228 ( V_45 ) ;
}
V_251:
F_193 ( V_41 , V_222 ) ;
V_314:
F_62 ( V_41 ) ;
V_315:
F_309 ( V_41 -> V_58 -> V_280 , V_313 ) ;
}
static void F_310 ( struct V_40 * V_41 )
{
F_311 ( & V_41 -> V_221 ) ;
F_312 ( & V_41 -> V_69 ) ;
}
static void F_313 ( struct V_40 * V_41 )
{
int V_155 ;
for ( V_155 = 0 ; V_155 < V_73 ; V_155 ++ ) {
if ( V_41 -> V_282 [ 0 ] [ V_155 ] )
F_239 ( V_41 -> V_282 [ 0 ] [ V_155 ] ) ;
if ( V_41 -> V_282 [ 1 ] [ V_155 ] )
F_239 ( V_41 -> V_282 [ 1 ] [ V_155 ] ) ;
}
if ( V_41 -> V_284 )
F_239 ( V_41 -> V_284 ) ;
}
static void F_314 ( struct V_316 * V_317 )
{
struct V_40 * V_41 = V_317 -> V_63 ;
struct V_162 * V_61 = V_41 -> V_58 ;
F_310 ( V_41 ) ;
F_135 ( V_61 -> V_280 ) ;
if ( V_41 -> V_220 )
F_186 ( V_41 , V_41 -> V_220 , 0 ) ;
F_313 ( V_41 ) ;
F_137 ( V_61 -> V_280 ) ;
F_310 ( V_41 ) ;
#ifdef F_272
F_315 ( V_61 , & V_28 ) ;
#else
F_316 ( V_41 -> V_164 ) ;
#endif
F_316 ( V_41 ) ;
}
static int F_317 ( struct V_162 * V_61 )
{
struct V_40 * V_41 ;
struct V_12 * V_27 V_318 ;
int V_155 , V_176 ;
V_41 = F_318 ( sizeof( * V_41 ) , V_319 | V_281 , V_61 -> V_133 ) ;
if ( ! V_41 )
return - V_320 ;
V_41 -> V_58 = V_61 ;
V_61 -> V_62 -> V_63 = V_41 ;
V_41 -> V_93 = V_157 ;
#ifdef F_272
V_176 = F_319 ( V_61 , & V_28 ) ;
if ( V_176 )
goto V_321;
V_41 -> V_164 = F_28 ( V_61 -> V_322 ) ;
#else
V_176 = - V_320 ;
V_41 -> V_164 = F_320 ( sizeof( * V_41 -> V_164 ) ,
V_319 , V_41 -> V_58 -> V_133 ) ;
if ( ! V_41 -> V_164 )
goto V_321;
F_117 ( V_41 -> V_164 ) ;
#endif
V_41 -> V_164 -> V_80 = 2 * V_79 ;
for ( V_155 = 0 ; V_155 < V_323 ; V_155 ++ )
V_41 -> V_202 [ V_155 ] = V_324 ;
F_258 ( V_41 , & V_41 -> V_278 , 1 , 0 ) ;
V_41 -> V_278 . V_241 ++ ;
F_135 ( V_61 -> V_280 ) ;
F_123 ( & V_41 -> V_278 , V_41 -> V_164 ) ;
F_32 ( V_41 -> V_164 ) ;
F_137 ( V_61 -> V_280 ) ;
F_321 ( & V_41 -> V_221 ) ;
V_41 -> V_221 . V_325 = F_307 ;
V_41 -> V_221 . V_312 = ( unsigned long ) V_41 ;
F_322 ( & V_41 -> V_69 , F_306 ) ;
V_41 -> V_258 = V_258 ;
V_41 -> V_300 [ 0 ] = V_300 [ 0 ] ;
V_41 -> V_300 [ 1 ] = V_300 [ 1 ] ;
V_41 -> V_120 = V_120 ;
V_41 -> V_121 = V_121 ;
V_41 -> V_72 [ 0 ] = V_326 ;
V_41 -> V_72 [ 1 ] = V_327 ;
V_41 -> V_94 = V_94 ;
V_41 -> V_236 = V_236 ;
V_41 -> V_42 = V_42 ;
V_41 -> V_228 = V_228 ;
V_41 -> V_97 = 1 ;
V_41 -> V_43 = - 1 ;
V_41 -> V_260 = V_105 - V_195 ;
return 0 ;
V_321:
F_316 ( V_41 ) ;
return V_176 ;
}
static T_7
F_323 ( unsigned int V_328 , char * V_329 )
{
return sprintf ( V_329 , L_35 , V_328 ) ;
}
static T_7
F_324 ( unsigned int * V_328 , const char * V_329 , T_8 V_52 )
{
char * V_189 = ( char * ) V_329 ;
* V_328 = F_325 ( V_189 , & V_189 , 10 ) ;
return V_52 ;
}
static int T_9 F_326 ( void )
{
int V_176 ;
if ( ! V_326 )
V_326 = 1 ;
if ( ! V_42 )
V_42 = 1 ;
#ifdef F_272
if ( ! V_228 )
V_228 = 1 ;
V_176 = F_327 ( & V_28 ) ;
if ( V_176 )
return V_176 ;
#else
V_228 = 0 ;
#endif
V_176 = - V_320 ;
V_264 = F_328 ( V_44 , 0 ) ;
if ( ! V_264 )
goto V_330;
V_176 = F_329 ( & V_331 ) ;
if ( V_176 )
goto V_332;
return 0 ;
V_332:
F_330 ( V_264 ) ;
V_330:
#ifdef F_272
F_331 ( & V_28 ) ;
#endif
return V_176 ;
}
static void T_10 F_332 ( void )
{
#ifdef F_272
F_331 ( & V_28 ) ;
#endif
F_333 ( & V_331 ) ;
F_330 ( V_264 ) ;
}
