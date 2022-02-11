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
static void F_2 ( struct V_10 * V_11 )
{
unsigned long long V_12 ;
if ( ! F_3 ( V_11 ) )
return;
V_12 = F_4 () ;
if ( F_5 ( V_12 , V_11 -> V_13 ) )
F_6 ( & V_11 -> V_14 ,
V_12 - V_11 -> V_13 ) ;
F_7 ( V_11 ) ;
}
static void F_8 ( struct V_2 * V_3 ,
struct V_2 * V_15 )
{
struct V_10 * V_11 = & V_3 -> V_11 ;
if ( F_3 ( V_11 ) )
return;
if ( V_3 == V_15 )
return;
V_11 -> V_13 = F_4 () ;
F_9 ( V_11 ) ;
}
static void F_10 ( struct V_10 * V_11 )
{
unsigned long long V_12 ;
if ( ! F_11 ( V_11 ) )
return;
V_12 = F_4 () ;
if ( F_5 ( V_12 , V_11 -> V_16 ) )
F_6 ( & V_11 -> V_17 ,
V_12 - V_11 -> V_16 ) ;
F_12 ( V_11 ) ;
}
static void F_13 ( struct V_2 * V_3 )
{
F_6 ( & V_3 -> V_11 . V_18 , 1 ) ;
}
static void F_14 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = & V_3 -> V_11 ;
if ( F_15 ( & V_11 -> V_19 ) )
return;
if ( F_11 ( V_11 ) )
return;
V_11 -> V_16 = F_4 () ;
F_16 ( V_11 ) ;
}
static void F_17 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = & V_3 -> V_11 ;
if ( F_18 ( V_11 ) ) {
unsigned long long V_12 = F_4 () ;
if ( F_5 ( V_12 , V_11 -> V_20 ) )
F_6 ( & V_11 -> V_21 ,
V_12 - V_11 -> V_20 ) ;
F_19 ( V_11 ) ;
}
}
static void F_20 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = & V_3 -> V_11 ;
F_21 ( F_18 ( V_11 ) ) ;
V_11 -> V_20 = F_4 () ;
F_22 ( V_11 ) ;
}
static void F_23 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = & V_3 -> V_11 ;
F_6 ( & V_11 -> V_22 ,
F_15 ( & V_11 -> V_19 ) ) ;
F_6 ( & V_11 -> V_23 , 1 ) ;
F_2 ( V_11 ) ;
}
static inline void F_8 ( struct V_2 * V_3 , struct V_2 * V_15 ) { }
static inline void F_10 ( struct V_10 * V_11 ) { }
static inline void F_13 ( struct V_2 * V_3 ) { }
static inline void F_14 ( struct V_2 * V_3 ) { }
static inline void F_17 ( struct V_2 * V_3 ) { }
static inline void F_20 ( struct V_2 * V_3 ) { }
static inline void F_23 ( struct V_2 * V_3 ) { }
static inline struct V_2 * F_24 ( struct V_24 * V_25 )
{
return V_25 ? F_25 ( V_25 , struct V_2 , V_25 ) : NULL ;
}
static struct V_26
* F_26 ( struct V_27 * V_28 )
{
return V_28 ? F_25 ( V_28 , struct V_26 , V_28 ) : NULL ;
}
static inline struct V_29 * F_27 ( struct V_2 * V_3 )
{
return F_28 ( & V_3 -> V_25 ) ;
}
static inline struct V_2 * F_29 ( struct V_29 * V_30 )
{
return F_24 ( F_30 ( V_30 , & V_31 ) ) ;
}
static struct V_26 * F_31 ( struct V_32 * V_32 )
{
return F_26 ( F_32 ( V_32 , & V_31 ) ) ;
}
static inline struct V_2 * F_33 ( struct V_2 * V_3 )
{
struct V_29 * V_33 = F_27 ( V_3 ) -> V_34 ;
return V_33 ? F_29 ( V_33 ) : NULL ;
}
static inline bool F_34 ( struct V_2 * V_3 ,
struct V_2 * V_35 )
{
return F_35 ( F_27 ( V_3 ) -> V_32 -> V_36 . V_37 ,
F_27 ( V_35 ) -> V_32 -> V_36 . V_37 ) ;
}
static inline void F_36 ( struct V_2 * V_3 )
{
return F_37 ( F_27 ( V_3 ) ) ;
}
static inline void F_38 ( struct V_2 * V_3 )
{
return F_39 ( F_27 ( V_3 ) ) ;
}
static inline void F_40 ( struct V_2 * V_3 ,
struct V_2 * V_15 , int V_38 ,
int V_39 )
{
F_41 ( & V_3 -> V_11 . V_19 , V_38 , V_39 , 1 ) ;
F_10 ( & V_3 -> V_11 ) ;
F_8 ( V_3 , V_15 ) ;
}
static inline void F_42 ( struct V_2 * V_3 ,
T_1 time , unsigned long V_40 )
{
F_6 ( & V_3 -> V_11 . time , time ) ;
#ifdef F_43
F_6 ( & V_3 -> V_11 . V_40 , V_40 ) ;
#endif
}
static inline void F_44 ( struct V_2 * V_3 , int V_38 ,
int V_39 )
{
F_41 ( & V_3 -> V_11 . V_19 , V_38 , V_39 , - 1 ) ;
}
static inline void F_45 ( struct V_2 * V_3 , int V_38 ,
int V_39 )
{
F_41 ( & V_3 -> V_11 . V_41 , V_38 , V_39 , 1 ) ;
}
static inline void F_46 ( struct V_2 * V_3 ,
T_1 V_42 , T_1 V_43 , int V_38 ,
int V_39 )
{
struct V_10 * V_11 = & V_3 -> V_11 ;
unsigned long long V_12 = F_4 () ;
if ( F_5 ( V_12 , V_43 ) )
F_41 ( & V_11 -> V_44 , V_38 , V_39 ,
V_12 - V_43 ) ;
if ( F_5 ( V_43 , V_42 ) )
F_41 ( & V_11 -> V_45 , V_38 , V_39 ,
V_43 - V_42 ) ;
}
static void F_47 ( struct V_10 * V_11 )
{
F_48 ( & V_11 -> V_41 ) ;
F_48 ( & V_11 -> V_44 ) ;
F_48 ( & V_11 -> V_45 ) ;
F_49 ( & V_11 -> time ) ;
#ifdef F_43
F_49 ( & V_11 -> V_40 ) ;
F_49 ( & V_11 -> V_22 ) ;
F_49 ( & V_11 -> V_23 ) ;
F_49 ( & V_11 -> V_18 ) ;
F_49 ( & V_11 -> V_14 ) ;
F_49 ( & V_11 -> V_21 ) ;
F_49 ( & V_11 -> V_17 ) ;
#endif
}
static void F_50 ( struct V_10 * V_46 , struct V_10 * V_47 )
{
F_51 ( & V_46 -> V_41 , & V_47 -> V_41 ) ;
F_51 ( & V_46 -> V_44 , & V_47 -> V_44 ) ;
F_51 ( & V_46 -> V_45 , & V_47 -> V_45 ) ;
F_52 ( & V_47 -> time , & V_47 -> time ) ;
#ifdef F_43
F_52 ( & V_46 -> V_40 , & V_47 -> V_40 ) ;
F_52 ( & V_46 -> V_22 , & V_47 -> V_22 ) ;
F_52 ( & V_46 -> V_23 , & V_47 -> V_23 ) ;
F_52 ( & V_46 -> V_18 , & V_47 -> V_18 ) ;
F_52 ( & V_46 -> V_14 , & V_47 -> V_14 ) ;
F_52 ( & V_46 -> V_21 , & V_47 -> V_21 ) ;
F_52 ( & V_46 -> V_17 , & V_47 -> V_17 ) ;
#endif
}
static void F_53 ( struct V_2 * V_3 )
{
struct V_2 * V_34 = F_33 ( V_3 ) ;
F_54 ( F_27 ( V_3 ) -> V_48 -> V_49 ) ;
if ( F_55 ( ! V_34 ) )
return;
F_50 ( & V_34 -> V_11 , & V_3 -> V_11 ) ;
F_47 ( & V_3 -> V_11 ) ;
}
static inline struct V_2 * F_33 ( struct V_2 * V_3 ) { return NULL ; }
static inline bool F_34 ( struct V_2 * V_3 ,
struct V_2 * V_35 )
{
return true ;
}
static inline void F_36 ( struct V_2 * V_3 ) { }
static inline void F_38 ( struct V_2 * V_3 ) { }
static inline void F_40 ( struct V_2 * V_3 ,
struct V_2 * V_15 , int V_38 , int V_39 ) { }
static inline void F_42 ( struct V_2 * V_3 ,
T_1 time , unsigned long V_40 ) { }
static inline void F_44 ( struct V_2 * V_3 , int V_38 ,
int V_39 ) { }
static inline void F_45 ( struct V_2 * V_3 , int V_38 ,
int V_39 ) { }
static inline void F_46 ( struct V_2 * V_3 ,
T_1 V_42 , T_1 V_43 , int V_38 ,
int V_39 ) { }
static inline bool F_56 ( struct V_50 * V_51 )
{
if ( ! V_51 -> V_52 && V_51 -> V_53 )
return true ;
else
return false ;
}
static inline enum V_4 F_57 ( struct V_54 * V_55 )
{
if ( F_58 ( V_55 ) )
return V_7 ;
if ( F_59 ( V_55 ) )
return V_56 ;
return V_57 ;
}
static enum V_6 F_60 ( struct V_54 * V_55 )
{
if ( ! F_61 ( V_55 ) )
return V_58 ;
if ( ! F_62 ( V_55 ) )
return V_59 ;
return V_60 ;
}
static inline int F_63 ( enum V_4 V_61 ,
struct V_50 * V_51 ,
struct V_2 * V_3 )
{
if ( V_61 == V_7 )
return V_3 -> V_8 . V_62 ;
return V_3 -> V_9 [ V_61 ] [ V_58 ] . V_62 +
V_3 -> V_9 [ V_61 ] [ V_59 ] . V_62 +
V_3 -> V_9 [ V_61 ] [ V_60 ] . V_62 ;
}
static inline int F_64 ( struct V_50 * V_51 ,
struct V_2 * V_3 )
{
return V_3 -> V_9 [ V_56 ] [ V_58 ] . V_62 +
V_3 -> V_9 [ V_57 ] [ V_58 ] . V_62 ;
}
static inline struct V_63 * F_65 ( struct V_64 * V_65 )
{
return F_25 ( V_65 , struct V_63 , V_65 ) ;
}
static inline struct V_63 * F_66 ( struct V_50 * V_51 ,
struct V_66 * V_67 )
{
if ( V_67 )
return F_65 ( F_67 ( V_67 , V_51 -> V_68 ) ) ;
return NULL ;
}
static inline struct V_54 * F_68 ( struct V_63 * V_69 , bool V_70 )
{
return V_69 -> V_55 [ V_70 ] ;
}
static inline void F_69 ( struct V_63 * V_69 , struct V_54 * V_55 ,
bool V_70 )
{
V_69 -> V_55 [ V_70 ] = V_55 ;
}
static inline struct V_50 * F_70 ( struct V_63 * V_69 )
{
return V_69 -> V_65 . V_48 -> V_71 -> V_72 ;
}
static inline bool F_71 ( struct V_73 * V_73 )
{
return F_72 ( V_73 ) == V_74 || ( V_73 -> V_75 & V_76 ) ;
}
static inline void F_73 ( struct V_50 * V_51 )
{
if ( V_51 -> V_77 ) {
F_74 ( V_51 , L_1 ) ;
F_75 ( & V_51 -> V_78 ) ;
}
}
static inline T_2 F_76 ( struct V_50 * V_51 , bool V_79 ,
unsigned short V_80 )
{
T_2 V_81 = V_51 -> V_82 [ V_79 ] ;
T_2 V_83 = F_77 ( V_81 , V_84 ) ;
F_78 ( V_80 >= V_85 ) ;
return V_81 + ( V_83 * ( 4 - V_80 ) ) ;
}
static inline T_2
F_79 ( struct V_50 * V_51 , struct V_54 * V_55 )
{
return F_76 ( V_51 , F_61 ( V_55 ) , V_55 -> V_86 ) ;
}
static inline T_2 F_80 ( T_2 V_87 ,
unsigned int V_88 )
{
T_2 V_89 = V_87 << V_90 ;
V_89 <<= V_90 ;
return F_77 ( V_89 , V_88 ) ;
}
static inline T_2 F_81 ( T_2 V_91 , T_2 V_92 )
{
T_3 V_93 = ( T_3 ) ( V_92 - V_91 ) ;
if ( V_93 > 0 )
V_91 = V_92 ;
return V_91 ;
}
static inline T_2 V_91 ( T_2 V_91 , T_2 V_92 )
{
T_3 V_93 = ( T_3 ) ( V_92 - V_91 ) ;
if ( V_93 < 0 )
V_91 = V_92 ;
return V_91 ;
}
static void F_82 ( struct V_1 * V_94 )
{
struct V_2 * V_3 ;
if ( V_94 -> V_95 ) {
V_3 = F_83 ( V_94 -> V_95 ) ;
V_94 -> V_91 = F_81 ( V_94 -> V_91 ,
V_3 -> V_92 ) ;
}
}
static inline unsigned F_84 ( struct V_50 * V_51 ,
struct V_2 * V_3 , bool V_96 )
{
unsigned V_97 , V_98 ;
unsigned V_99 = V_100 - 1 ;
unsigned V_101 = V_100 / 2 ;
unsigned V_102 = F_63 ( V_96 , V_51 , V_3 ) ;
V_97 = F_85 ( V_3 -> V_103 [ V_96 ] , V_102 ) ;
V_98 = F_86 ( V_3 -> V_103 [ V_96 ] , V_102 ) ;
V_3 -> V_103 [ V_96 ] = ( V_99 * V_98 + V_97 + V_101 ) /
V_100 ;
return V_3 -> V_103 [ V_96 ] ;
}
static inline T_2
F_87 ( struct V_50 * V_51 , struct V_2 * V_3 )
{
return V_51 -> V_104 * V_3 -> V_88 >> V_90 ;
}
static inline T_2
F_88 ( struct V_50 * V_51 , struct V_54 * V_55 )
{
T_2 V_83 = F_79 ( V_51 , V_55 ) ;
if ( V_51 -> V_105 ) {
unsigned V_106 = F_84 ( V_51 , V_55 -> V_3 ,
F_59 ( V_55 ) ) ;
T_2 V_107 = V_51 -> V_82 [ 1 ] ;
T_2 V_108 = V_107 * V_106 ;
T_2 V_109 = F_87 ( V_51 , V_55 -> V_3 ) ;
if ( V_108 > V_109 ) {
T_2 V_110 = 2 * V_51 -> V_52 ;
T_2 V_111 ;
V_111 = F_89 ( V_110 * V_83 , V_107 ) ;
V_111 = F_85 ( V_83 , V_111 ) ;
V_83 = F_89 ( V_83 * V_109 , V_108 ) ;
V_83 = F_86 ( V_83 , V_111 ) ;
}
}
return V_83 ;
}
static inline void
F_90 ( struct V_50 * V_51 , struct V_54 * V_55 )
{
T_2 V_83 = F_88 ( V_51 , V_55 ) ;
T_2 V_12 = F_91 () ;
V_55 -> V_112 = V_12 ;
V_55 -> V_113 = V_12 + V_83 ;
V_55 -> V_114 = V_83 ;
F_92 ( V_51 , V_55 , L_2 , V_55 -> V_113 - V_12 ) ;
}
static inline bool F_93 ( struct V_54 * V_55 )
{
if ( F_94 ( V_55 ) )
return false ;
if ( F_91 () < V_55 -> V_113 )
return false ;
return true ;
}
static struct V_115 *
F_95 ( struct V_50 * V_51 , struct V_115 * V_116 , struct V_115 * V_117 , T_4 V_118 )
{
T_4 V_119 , V_120 , V_121 = 0 , V_122 = 0 ;
unsigned long V_123 ;
#define F_96 0x01
#define F_97 0x02
unsigned V_124 = 0 ;
if ( V_116 == NULL || V_116 == V_117 )
return V_117 ;
if ( V_117 == NULL )
return V_116 ;
if ( F_98 ( V_116 ) != F_98 ( V_117 ) )
return F_98 ( V_116 ) ? V_116 : V_117 ;
if ( ( V_116 -> V_125 ^ V_117 -> V_125 ) & V_126 )
return V_116 -> V_125 & V_126 ? V_116 : V_117 ;
V_119 = F_99 ( V_116 ) ;
V_120 = F_99 ( V_117 ) ;
V_123 = V_51 -> V_127 * 2 ;
if ( V_119 >= V_118 )
V_121 = V_119 - V_118 ;
else if ( V_119 + V_123 >= V_118 )
V_121 = ( V_118 - V_119 ) * V_51 -> V_128 ;
else
V_124 |= F_96 ;
if ( V_120 >= V_118 )
V_122 = V_120 - V_118 ;
else if ( V_120 + V_123 >= V_118 )
V_122 = ( V_118 - V_120 ) * V_51 -> V_128 ;
else
V_124 |= F_97 ;
switch ( V_124 ) {
case 0 :
if ( V_121 < V_122 )
return V_116 ;
else if ( V_122 < V_121 )
return V_117 ;
else {
if ( V_119 >= V_120 )
return V_116 ;
else
return V_117 ;
}
case F_97 :
return V_116 ;
case F_96 :
return V_117 ;
case ( F_96 | F_97 ) :
default:
if ( V_119 <= V_120 )
return V_116 ;
else
return V_117 ;
}
}
static struct V_54 * F_100 ( struct V_1 * V_129 )
{
if ( ! V_129 -> V_62 )
return NULL ;
if ( ! V_129 -> V_95 )
V_129 -> V_95 = F_101 ( & V_129 -> V_130 ) ;
if ( V_129 -> V_95 )
return F_102 ( V_129 -> V_95 , struct V_54 , V_131 ) ;
return NULL ;
}
static struct V_2 * F_103 ( struct V_1 * V_129 )
{
if ( ! V_129 -> V_95 )
V_129 -> V_95 = F_101 ( & V_129 -> V_130 ) ;
if ( V_129 -> V_95 )
return F_83 ( V_129 -> V_95 ) ;
return NULL ;
}
static void F_104 ( struct V_131 * V_132 , struct V_133 * V_129 )
{
F_105 ( V_132 , V_129 ) ;
F_106 ( V_132 ) ;
}
static void F_107 ( struct V_131 * V_132 , struct V_1 * V_129 )
{
if ( V_129 -> V_95 == V_132 )
V_129 -> V_95 = NULL ;
F_104 ( V_132 , & V_129 -> V_130 ) ;
-- V_129 -> V_62 ;
}
static struct V_115 *
F_108 ( struct V_50 * V_51 , struct V_54 * V_55 ,
struct V_115 * V_118 )
{
struct V_131 * V_134 = F_109 ( & V_118 -> V_131 ) ;
struct V_131 * V_135 = F_110 ( & V_118 -> V_131 ) ;
struct V_115 * V_136 = NULL , * V_137 = NULL ;
F_21 ( F_111 ( & V_118 -> V_131 ) ) ;
if ( V_135 )
V_137 = F_112 ( V_135 ) ;
if ( V_134 )
V_136 = F_112 ( V_134 ) ;
else {
V_134 = F_101 ( & V_55 -> V_138 ) ;
if ( V_134 && V_134 != & V_118 -> V_131 )
V_136 = F_112 ( V_134 ) ;
}
return F_95 ( V_51 , V_136 , V_137 , F_99 ( V_118 ) ) ;
}
static T_2 F_113 ( struct V_50 * V_51 ,
struct V_54 * V_55 )
{
return ( V_55 -> V_3 -> V_139 - 1 ) * ( F_76 ( V_51 , 1 , 0 ) -
F_76 ( V_51 , F_61 ( V_55 ) , V_55 -> V_86 ) ) ;
}
static inline T_3
F_114 ( struct V_1 * V_94 , struct V_2 * V_3 )
{
return V_3 -> V_92 - V_94 -> V_91 ;
}
static void
F_115 ( struct V_1 * V_94 , struct V_2 * V_3 )
{
struct V_131 * * V_140 = & V_94 -> V_130 . V_131 ;
struct V_131 * V_34 = NULL ;
struct V_2 * V_141 ;
T_3 V_142 = F_114 ( V_94 , V_3 ) ;
int V_95 = 1 ;
while ( * V_140 != NULL ) {
V_34 = * V_140 ;
V_141 = F_83 ( V_34 ) ;
if ( V_142 < F_114 ( V_94 , V_141 ) )
V_140 = & V_34 -> V_143 ;
else {
V_140 = & V_34 -> V_144 ;
V_95 = 0 ;
}
}
if ( V_95 )
V_94 -> V_95 = & V_3 -> V_131 ;
F_116 ( & V_3 -> V_131 , V_34 , V_140 ) ;
F_117 ( & V_3 -> V_131 , & V_94 -> V_130 ) ;
}
static void
F_118 ( struct V_2 * V_3 )
{
if ( V_3 -> V_145 ) {
V_3 -> V_146 = V_3 -> V_145 ;
V_3 -> V_145 = 0 ;
}
}
static void
F_119 ( struct V_2 * V_3 )
{
F_21 ( ! F_111 ( & V_3 -> V_131 ) ) ;
if ( V_3 -> V_147 ) {
V_3 -> V_148 = V_3 -> V_147 ;
V_3 -> V_147 = 0 ;
}
}
static void
F_120 ( struct V_1 * V_94 , struct V_2 * V_3 )
{
unsigned int V_149 = 1 << V_90 ;
struct V_2 * V_150 = V_3 ;
struct V_2 * V_34 ;
bool V_151 ;
F_21 ( ! F_111 ( & V_3 -> V_131 ) ) ;
F_119 ( V_3 ) ;
F_115 ( V_94 , V_3 ) ;
V_151 = ! V_150 -> V_152 ++ ;
V_150 -> V_153 += V_150 -> V_148 ;
V_149 = V_149 * V_150 -> V_148 / V_150 -> V_153 ;
while ( ( V_34 = F_33 ( V_150 ) ) ) {
if ( V_151 ) {
F_118 ( V_150 ) ;
V_151 = ! V_34 -> V_152 ++ ;
V_34 -> V_153 += V_150 -> V_146 ;
}
V_149 = V_149 * V_150 -> V_146 / V_34 -> V_153 ;
V_150 = V_34 ;
}
V_3 -> V_88 = F_121 ( unsigned , V_149 , 1 ) ;
}
static void
F_122 ( struct V_50 * V_51 , struct V_2 * V_3 )
{
struct V_1 * V_94 = & V_51 -> V_154 ;
struct V_2 * V_141 ;
struct V_131 * V_132 ;
V_3 -> V_139 ++ ;
if ( ! F_111 ( & V_3 -> V_131 ) )
return;
V_132 = F_123 ( & V_94 -> V_130 ) ;
if ( V_132 ) {
V_141 = F_83 ( V_132 ) ;
V_3 -> V_92 = V_141 -> V_92 + V_155 ;
} else
V_3 -> V_92 = V_94 -> V_91 ;
F_120 ( V_94 , V_3 ) ;
}
static void
F_124 ( struct V_1 * V_94 , struct V_2 * V_3 )
{
struct V_2 * V_150 = V_3 ;
bool V_151 ;
V_151 = ! -- V_150 -> V_152 ;
V_150 -> V_153 -= V_150 -> V_148 ;
while ( V_151 ) {
struct V_2 * V_34 = F_33 ( V_150 ) ;
F_125 ( V_150 -> V_153 ) ;
V_150 -> V_88 = 0 ;
if ( ! V_34 )
break;
V_151 = ! -- V_34 -> V_152 ;
V_34 -> V_153 -= V_150 -> V_146 ;
V_150 = V_34 ;
}
if ( ! F_111 ( & V_3 -> V_131 ) )
F_107 ( & V_3 -> V_131 , V_94 ) ;
}
static void
F_126 ( struct V_50 * V_51 , struct V_2 * V_3 )
{
struct V_1 * V_94 = & V_51 -> V_154 ;
F_21 ( V_3 -> V_139 < 1 ) ;
V_3 -> V_139 -- ;
if ( V_3 -> V_139 )
return;
F_127 ( V_51 , V_3 , L_3 ) ;
F_124 ( V_94 , V_3 ) ;
V_3 -> V_156 = 0 ;
F_13 ( V_3 ) ;
}
static inline T_2 F_128 ( struct V_54 * V_55 ,
T_2 * V_40 )
{
T_2 V_157 ;
T_2 V_12 = F_91 () ;
if ( ! V_55 -> V_112 || V_55 -> V_112 == V_12 ) {
V_157 = F_121 ( T_2 , ( V_12 - V_55 -> V_158 ) ,
F_129 ( 1 ) ) ;
} else {
V_157 = V_12 - V_55 -> V_112 ;
if ( V_157 > V_55 -> V_114 ) {
* V_40 = V_157 - V_55 -> V_114 ;
V_157 = V_55 -> V_114 ;
}
if ( V_55 -> V_112 > V_55 -> V_158 )
* V_40 += V_55 -> V_112 -
V_55 -> V_158 ;
}
return V_157 ;
}
static void F_130 ( struct V_50 * V_51 , struct V_2 * V_3 ,
struct V_54 * V_55 )
{
struct V_1 * V_94 = & V_51 -> V_154 ;
T_2 V_159 , V_87 , V_160 = 0 ;
int V_161 = V_3 -> V_139 - F_64 ( V_51 , V_3 )
- V_3 -> V_8 . V_62 ;
unsigned int V_149 ;
T_2 V_12 = F_91 () ;
F_21 ( V_161 < 0 ) ;
V_159 = V_87 = F_128 ( V_55 , & V_160 ) ;
if ( F_56 ( V_51 ) )
V_87 = V_55 -> V_162 ;
else if ( ! F_61 ( V_55 ) && ! V_161 )
V_87 = V_55 -> V_114 ;
V_149 = V_3 -> V_88 ;
F_124 ( V_94 , V_3 ) ;
V_3 -> V_92 += F_80 ( V_87 , V_149 ) ;
F_120 ( V_94 , V_3 ) ;
if ( V_51 -> V_163 > V_12 ) {
V_3 -> V_156 = V_51 -> V_163 - V_12 ;
V_3 -> V_164 = V_51 -> V_165 ;
V_3 -> V_166 = V_51 -> V_167 ;
} else
V_3 -> V_156 = 0 ;
F_127 ( V_51 , V_3 , L_4 , V_3 -> V_92 ,
V_94 -> V_91 ) ;
F_92 ( V_55 -> V_51 , V_55 ,
L_5 ,
V_159 , V_55 -> V_162 , V_87 ,
F_56 ( V_51 ) , V_55 -> V_168 ) ;
F_42 ( V_3 , V_159 , V_160 ) ;
F_14 ( V_3 ) ;
}
static void F_131 ( struct V_2 * V_3 )
{
struct V_1 * V_94 ;
int V_169 , V_170 ;
F_132 ( V_3 , V_169 , V_170 , V_94 )
* V_94 = V_171 ;
F_106 ( & V_3 -> V_131 ) ;
V_3 -> V_172 . V_173 = F_91 () ;
}
static void F_133 ( struct V_10 * V_11 )
{
F_134 ( & V_11 -> V_41 ) ;
F_134 ( & V_11 -> V_44 ) ;
F_134 ( & V_11 -> V_45 ) ;
F_134 ( & V_11 -> V_19 ) ;
F_135 ( & V_11 -> time ) ;
#ifdef F_43
F_135 ( & V_11 -> V_40 ) ;
F_135 ( & V_11 -> V_22 ) ;
F_135 ( & V_11 -> V_23 ) ;
F_135 ( & V_11 -> V_18 ) ;
F_135 ( & V_11 -> V_14 ) ;
F_135 ( & V_11 -> V_21 ) ;
F_135 ( & V_11 -> V_17 ) ;
#endif
}
static int F_136 ( struct V_10 * V_11 , T_5 V_174 )
{
if ( F_137 ( & V_11 -> V_41 , V_174 ) ||
F_137 ( & V_11 -> V_44 , V_174 ) ||
F_137 ( & V_11 -> V_45 , V_174 ) ||
F_137 ( & V_11 -> V_19 , V_174 ) ||
F_138 ( & V_11 -> time , V_174 ) )
goto V_175;
#ifdef F_43
if ( F_138 ( & V_11 -> V_40 , V_174 ) ||
F_138 ( & V_11 -> V_22 , V_174 ) ||
F_138 ( & V_11 -> V_23 , V_174 ) ||
F_138 ( & V_11 -> V_18 , V_174 ) ||
F_138 ( & V_11 -> V_14 , V_174 ) ||
F_138 ( & V_11 -> V_21 , V_174 ) ||
F_138 ( & V_11 -> V_17 , V_174 ) )
goto V_175;
#endif
return 0 ;
V_175:
F_133 ( V_11 ) ;
return - V_176 ;
}
static struct V_27 * F_139 ( T_5 V_174 )
{
struct V_26 * V_177 ;
V_177 = F_140 ( sizeof( * V_177 ) , V_178 ) ;
if ( ! V_177 )
return NULL ;
return & V_177 -> V_28 ;
}
static void F_141 ( struct V_27 * V_28 )
{
struct V_26 * V_177 = F_26 ( V_28 ) ;
unsigned int V_146 = F_142 ( V_179 ) ?
V_180 : V_181 ;
if ( F_143 ( V_28 ) == & V_182 )
V_146 *= 2 ;
V_177 -> V_146 = V_146 ;
V_177 -> V_148 = V_146 ;
}
static void F_144 ( struct V_27 * V_28 )
{
F_145 ( F_26 ( V_28 ) ) ;
}
static void F_146 ( struct V_27 * V_28 )
{
struct V_32 * V_32 = F_143 ( V_28 ) ;
bool V_183 = F_142 ( V_179 ) ;
unsigned int V_146 = V_183 ? V_180 : V_181 ;
if ( V_32 == & V_182 )
V_146 *= 2 ;
F_125 ( F_147 ( & V_32 -> V_36 , V_146 , V_183 , true , false ) ) ;
F_125 ( F_147 ( & V_32 -> V_36 , V_146 , V_183 , true , true ) ) ;
}
static struct V_24 * F_148 ( T_5 V_174 , int V_140 )
{
struct V_2 * V_3 ;
V_3 = F_149 ( sizeof( * V_3 ) , V_174 , V_140 ) ;
if ( ! V_3 )
return NULL ;
F_131 ( V_3 ) ;
if ( F_136 ( & V_3 -> V_11 , V_174 ) ) {
F_145 ( V_3 ) ;
return NULL ;
}
return & V_3 -> V_25 ;
}
static void F_150 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
struct V_26 * V_177 = F_31 ( V_25 -> V_30 -> V_32 ) ;
V_3 -> V_146 = V_177 -> V_146 ;
V_3 -> V_148 = V_177 -> V_148 ;
}
static void F_151 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
int V_169 ;
for ( V_169 = 0 ; V_169 < V_85 ; V_169 ++ ) {
if ( V_3 -> V_184 [ 0 ] [ V_169 ] )
F_152 ( V_3 -> V_184 [ 0 ] [ V_169 ] ) ;
if ( V_3 -> V_184 [ 1 ] [ V_169 ] )
F_152 ( V_3 -> V_184 [ 1 ] [ V_169 ] ) ;
}
if ( V_3 -> V_185 )
F_152 ( V_3 -> V_185 ) ;
F_53 ( V_3 ) ;
}
static void F_153 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
F_133 ( & V_3 -> V_11 ) ;
return F_145 ( V_3 ) ;
}
static void F_154 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
F_47 ( & V_3 -> V_11 ) ;
}
static struct V_2 * F_155 ( struct V_50 * V_51 ,
struct V_32 * V_32 )
{
struct V_29 * V_30 ;
V_30 = F_156 ( V_32 , V_51 -> V_68 ) ;
if ( F_157 ( V_30 ) )
return F_29 ( V_30 ) ;
return NULL ;
}
static void F_158 ( struct V_54 * V_55 , struct V_2 * V_3 )
{
V_55 -> V_3 = V_3 ;
F_36 ( V_3 ) ;
}
static T_2 F_159 ( struct V_186 * V_187 ,
struct V_24 * V_25 , int V_188 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
if ( ! V_3 -> V_189 )
return 0 ;
return F_160 ( V_187 , V_25 , V_3 -> V_189 ) ;
}
static int F_161 ( struct V_186 * V_187 , void * V_190 )
{
F_162 ( V_187 , F_163 ( F_164 ( V_187 ) ) ,
F_159 , & V_31 ,
0 , false ) ;
return 0 ;
}
static T_2 F_165 ( struct V_186 * V_187 ,
struct V_24 * V_25 , int V_188 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
if ( ! V_3 -> V_191 )
return 0 ;
return F_160 ( V_187 , V_25 , V_3 -> V_191 ) ;
}
static int F_166 ( struct V_186 * V_187 , void * V_190 )
{
F_162 ( V_187 , F_163 ( F_164 ( V_187 ) ) ,
F_165 , & V_31 ,
0 , false ) ;
return 0 ;
}
static int F_167 ( struct V_186 * V_187 , void * V_190 )
{
struct V_32 * V_32 = F_163 ( F_164 ( V_187 ) ) ;
struct V_26 * V_177 = F_31 ( V_32 ) ;
unsigned int V_192 = 0 ;
if ( V_177 )
V_192 = V_177 -> V_146 ;
F_168 ( V_187 , L_6 , V_192 ) ;
return 0 ;
}
static int F_169 ( struct V_186 * V_187 , void * V_190 )
{
struct V_32 * V_32 = F_163 ( F_164 ( V_187 ) ) ;
struct V_26 * V_177 = F_31 ( V_32 ) ;
unsigned int V_192 = 0 ;
if ( V_177 )
V_192 = V_177 -> V_148 ;
F_168 ( V_187 , L_6 , V_192 ) ;
return 0 ;
}
static T_6 F_170 ( struct V_193 * V_194 ,
char * V_195 , T_7 V_196 , T_8 V_188 ,
bool V_183 , bool V_197 )
{
unsigned int F_85 = V_183 ? V_198 : V_199 ;
unsigned int F_86 = V_183 ? V_200 : V_201 ;
struct V_32 * V_32 = F_163 ( F_171 ( V_194 ) ) ;
struct V_202 V_203 ;
struct V_2 * V_3 ;
struct V_26 * V_204 ;
int V_205 ;
T_2 V_190 ;
V_205 = F_172 ( V_32 , & V_31 , V_195 , & V_203 ) ;
if ( V_205 )
return V_205 ;
if ( sscanf ( V_203 . V_206 , L_7 , & V_190 ) == 1 ) {
V_205 = - V_207 ;
if ( ! V_190 && V_183 )
goto V_208;
} else if ( ! strcmp ( F_173 ( V_203 . V_206 ) , L_8 ) ) {
V_190 = 0 ;
} else {
V_205 = - V_209 ;
goto V_208;
}
V_3 = F_29 ( V_203 . V_30 ) ;
V_204 = F_31 ( V_32 ) ;
V_205 = - V_207 ;
if ( ! V_190 || ( V_190 >= F_85 && V_190 <= F_86 ) ) {
if ( ! V_197 ) {
V_3 -> V_189 = V_190 ;
V_3 -> V_145 = V_190 ? : V_204 -> V_146 ;
} else {
V_3 -> V_191 = V_190 ;
V_3 -> V_147 = V_190 ? : V_204 -> V_148 ;
}
V_205 = 0 ;
}
V_208:
F_174 ( & V_203 ) ;
return V_205 ? : V_196 ;
}
static T_6 F_175 ( struct V_193 * V_194 ,
char * V_195 , T_7 V_196 , T_8 V_188 )
{
return F_170 ( V_194 , V_195 , V_196 , V_188 , false , false ) ;
}
static T_6 F_176 ( struct V_193 * V_194 ,
char * V_195 , T_7 V_196 , T_8 V_188 )
{
return F_170 ( V_194 , V_195 , V_196 , V_188 , false , true ) ;
}
static int F_147 ( struct V_210 * V_36 , T_2 V_192 ,
bool V_183 , bool V_211 , bool V_197 )
{
unsigned int F_85 = V_183 ? V_198 : V_199 ;
unsigned int F_86 = V_183 ? V_200 : V_201 ;
struct V_32 * V_32 = F_163 ( V_36 ) ;
struct V_29 * V_30 ;
struct V_26 * V_204 ;
int V_205 = 0 ;
if ( V_192 < F_85 || V_192 > F_86 )
return - V_207 ;
F_177 ( & V_32 -> V_212 ) ;
V_204 = F_31 ( V_32 ) ;
if ( ! V_204 ) {
V_205 = - V_209 ;
goto V_213;
}
if ( ! V_197 )
V_204 -> V_146 = V_192 ;
else
V_204 -> V_148 = V_192 ;
F_178 (blkg, &blkcg->blkg_list, blkcg_node) {
struct V_2 * V_3 = F_29 ( V_30 ) ;
if ( ! V_3 )
continue;
if ( ! V_197 ) {
if ( V_211 )
V_3 -> V_189 = 0 ;
if ( ! V_3 -> V_189 )
V_3 -> V_145 = V_204 -> V_146 ;
} else {
if ( V_211 )
V_3 -> V_191 = 0 ;
if ( ! V_3 -> V_191 )
V_3 -> V_147 = V_204 -> V_148 ;
}
}
V_213:
F_179 ( & V_32 -> V_212 ) ;
return V_205 ;
}
static int F_180 ( struct V_210 * V_36 , struct V_214 * V_215 ,
T_2 V_192 )
{
return F_147 ( V_36 , V_192 , false , false , false ) ;
}
static int F_181 ( struct V_210 * V_36 ,
struct V_214 * V_215 , T_2 V_192 )
{
return F_147 ( V_36 , V_192 , false , false , true ) ;
}
static int F_182 ( struct V_186 * V_187 , void * V_190 )
{
F_162 ( V_187 , F_163 ( F_164 ( V_187 ) ) , V_216 ,
& V_31 , F_183 ( V_187 ) -> V_217 , false ) ;
return 0 ;
}
static int F_184 ( struct V_186 * V_187 , void * V_190 )
{
F_162 ( V_187 , F_163 ( F_164 ( V_187 ) ) , V_218 ,
& V_31 , F_183 ( V_187 ) -> V_217 , true ) ;
return 0 ;
}
static T_2 F_185 ( struct V_186 * V_187 ,
struct V_24 * V_25 , int V_188 )
{
T_2 V_219 = F_186 ( F_28 ( V_25 ) ,
& V_31 , V_188 ) ;
return F_160 ( V_187 , V_25 , V_219 ) ;
}
static T_2 F_187 ( struct V_186 * V_187 ,
struct V_24 * V_25 , int V_188 )
{
struct V_220 V_219 = F_188 ( F_28 ( V_25 ) ,
& V_31 , V_188 ) ;
return F_189 ( V_187 , V_25 , & V_219 ) ;
}
static int F_190 ( struct V_186 * V_187 , void * V_190 )
{
F_162 ( V_187 , F_163 ( F_164 ( V_187 ) ) ,
F_185 , & V_31 ,
F_183 ( V_187 ) -> V_217 , false ) ;
return 0 ;
}
static int F_191 ( struct V_186 * V_187 , void * V_190 )
{
F_162 ( V_187 , F_163 ( F_164 ( V_187 ) ) ,
F_187 , & V_31 ,
F_183 ( V_187 ) -> V_217 , true ) ;
return 0 ;
}
static T_2 F_192 ( struct V_186 * V_187 , struct V_24 * V_25 ,
int V_188 )
{
T_2 V_219 = F_15 ( & V_25 -> V_30 -> V_221 ) ;
return F_160 ( V_187 , V_25 , V_219 >> 9 ) ;
}
static int F_193 ( struct V_186 * V_187 , void * V_190 )
{
F_162 ( V_187 , F_163 ( F_164 ( V_187 ) ) ,
F_192 , & V_31 , 0 , false ) ;
return 0 ;
}
static T_2 F_194 ( struct V_186 * V_187 ,
struct V_24 * V_25 , int V_188 )
{
struct V_220 V_222 = F_188 ( V_25 -> V_30 , NULL ,
F_195 ( struct V_29 , V_221 ) ) ;
T_2 V_219 = F_196 ( & V_222 . V_223 [ V_224 ] ) +
F_196 ( & V_222 . V_223 [ V_225 ] ) ;
return F_160 ( V_187 , V_25 , V_219 >> 9 ) ;
}
static int F_197 ( struct V_186 * V_187 , void * V_190 )
{
F_162 ( V_187 , F_163 ( F_164 ( V_187 ) ) ,
F_194 , & V_31 , 0 ,
false ) ;
return 0 ;
}
static T_2 F_198 ( struct V_186 * V_187 ,
struct V_24 * V_25 , int V_188 )
{
struct V_2 * V_3 = F_24 ( V_25 ) ;
T_2 V_226 = F_199 ( & V_3 -> V_11 . V_23 ) ;
T_2 V_190 = 0 ;
if ( V_226 ) {
V_190 = F_199 ( & V_3 -> V_11 . V_22 ) ;
V_190 = F_89 ( V_190 , V_226 ) ;
}
F_160 ( V_187 , V_25 , V_190 ) ;
return 0 ;
}
static int F_200 ( struct V_186 * V_187 , void * V_190 )
{
F_162 ( V_187 , F_163 ( F_164 ( V_187 ) ) ,
F_198 , & V_31 ,
0 , false ) ;
return 0 ;
}
static int F_201 ( struct V_186 * V_187 , void * V_190 )
{
struct V_32 * V_32 = F_163 ( F_164 ( V_187 ) ) ;
struct V_26 * V_177 = F_31 ( V_32 ) ;
F_168 ( V_187 , L_9 , V_177 -> V_146 ) ;
F_162 ( V_187 , V_32 , F_159 ,
& V_31 , 0 , false ) ;
return 0 ;
}
static T_6 F_202 ( struct V_193 * V_194 ,
char * V_195 , T_7 V_196 , T_8 V_188 )
{
char * V_227 ;
int V_205 ;
T_2 V_190 ;
V_195 = F_173 ( V_195 ) ;
V_190 = F_203 ( V_195 , & V_227 , 0 ) ;
if ( * V_227 == '\0' || sscanf ( V_195 , L_10 , & V_190 ) == 1 ) {
V_205 = F_147 ( F_171 ( V_194 ) , V_190 , true , false , false ) ;
return V_205 ? : V_196 ;
}
return F_170 ( V_194 , V_195 , V_196 , V_188 , true , false ) ;
}
static struct V_2 * F_155 ( struct V_50 * V_51 ,
struct V_32 * V_32 )
{
return V_51 -> V_228 ;
}
static inline void
F_158 ( struct V_54 * V_55 , struct V_2 * V_3 ) {
V_55 -> V_3 = V_3 ;
}
static void F_204 ( struct V_50 * V_51 , struct V_54 * V_55 ,
bool V_229 )
{
struct V_131 * * V_230 , * V_34 ;
struct V_54 * V_231 ;
T_2 V_232 ;
struct V_1 * V_94 ;
int V_95 ;
int V_233 = 1 ;
T_2 V_12 = F_91 () ;
V_94 = F_1 ( V_55 -> V_3 , F_57 ( V_55 ) , F_60 ( V_55 ) ) ;
if ( F_58 ( V_55 ) ) {
V_232 = V_155 ;
V_34 = F_123 ( & V_94 -> V_130 ) ;
if ( V_34 && V_34 != & V_55 -> V_131 ) {
V_231 = F_102 ( V_34 , struct V_54 , V_131 ) ;
V_232 += V_231 -> V_232 ;
} else
V_232 += V_12 ;
} else if ( ! V_229 ) {
V_232 = F_113 ( V_51 , V_55 ) + V_12 ;
V_232 -= V_55 -> V_234 ;
V_55 -> V_234 = 0 ;
} else {
V_232 = - V_235 ;
V_231 = F_100 ( V_94 ) ;
V_232 += V_231 ? V_231 -> V_232 : V_12 ;
}
if ( ! F_111 ( & V_55 -> V_131 ) ) {
V_233 = 0 ;
if ( V_232 == V_55 -> V_232 && V_55 -> V_236 == V_94 )
return;
F_107 ( & V_55 -> V_131 , V_55 -> V_236 ) ;
V_55 -> V_236 = NULL ;
}
V_95 = 1 ;
V_34 = NULL ;
V_55 -> V_236 = V_94 ;
V_230 = & V_94 -> V_130 . V_131 ;
while ( * V_230 ) {
V_34 = * V_230 ;
V_231 = F_102 ( V_34 , struct V_54 , V_131 ) ;
if ( V_232 < V_231 -> V_232 )
V_230 = & V_34 -> V_143 ;
else {
V_230 = & V_34 -> V_144 ;
V_95 = 0 ;
}
}
if ( V_95 )
V_94 -> V_95 = & V_55 -> V_131 ;
V_55 -> V_232 = V_232 ;
F_116 ( & V_55 -> V_131 , V_34 , V_230 ) ;
F_117 ( & V_55 -> V_131 , & V_94 -> V_130 ) ;
V_94 -> V_62 ++ ;
if ( V_229 || ! V_233 )
return;
F_122 ( V_51 , V_55 -> V_3 ) ;
}
static struct V_54 *
F_205 ( struct V_50 * V_51 , struct V_133 * V_129 ,
T_4 V_237 , struct V_131 * * V_238 ,
struct V_131 * * * V_239 )
{
struct V_131 * * V_230 , * V_34 ;
struct V_54 * V_55 = NULL ;
V_34 = NULL ;
V_230 = & V_129 -> V_131 ;
while ( * V_230 ) {
struct V_131 * * V_132 ;
V_34 = * V_230 ;
V_55 = F_102 ( V_34 , struct V_54 , V_240 ) ;
if ( V_237 > F_99 ( V_55 -> V_241 ) )
V_132 = & ( * V_230 ) -> V_144 ;
else if ( V_237 < F_99 ( V_55 -> V_241 ) )
V_132 = & ( * V_230 ) -> V_143 ;
else
break;
V_230 = V_132 ;
V_55 = NULL ;
}
* V_238 = V_34 ;
if ( V_239 )
* V_239 = V_230 ;
return V_55 ;
}
static void F_206 ( struct V_50 * V_51 , struct V_54 * V_55 )
{
struct V_131 * * V_230 , * V_34 ;
struct V_54 * V_231 ;
if ( V_55 -> V_242 ) {
F_105 ( & V_55 -> V_240 , V_55 -> V_242 ) ;
V_55 -> V_242 = NULL ;
}
if ( F_58 ( V_55 ) )
return;
if ( ! V_55 -> V_241 )
return;
V_55 -> V_242 = & V_51 -> V_243 [ V_55 -> V_244 ] ;
V_231 = F_205 ( V_51 , V_55 -> V_242 ,
F_99 ( V_55 -> V_241 ) , & V_34 , & V_230 ) ;
if ( ! V_231 ) {
F_116 ( & V_55 -> V_240 , V_34 , V_230 ) ;
F_117 ( & V_55 -> V_240 , V_55 -> V_242 ) ;
} else
V_55 -> V_242 = NULL ;
}
static void F_207 ( struct V_50 * V_51 , struct V_54 * V_55 )
{
if ( F_208 ( V_55 ) ) {
F_204 ( V_51 , V_55 , 0 ) ;
F_206 ( V_51 , V_55 ) ;
}
}
static void F_209 ( struct V_50 * V_51 , struct V_54 * V_55 )
{
F_92 ( V_51 , V_55 , L_11 ) ;
F_21 ( F_208 ( V_55 ) ) ;
F_210 ( V_55 ) ;
V_51 -> V_77 ++ ;
if ( F_61 ( V_55 ) )
V_51 -> V_245 ++ ;
F_207 ( V_51 , V_55 ) ;
}
static void F_211 ( struct V_50 * V_51 , struct V_54 * V_55 )
{
F_92 ( V_51 , V_55 , L_12 ) ;
F_21 ( ! F_208 ( V_55 ) ) ;
F_212 ( V_55 ) ;
if ( ! F_111 ( & V_55 -> V_131 ) ) {
F_107 ( & V_55 -> V_131 , V_55 -> V_236 ) ;
V_55 -> V_236 = NULL ;
}
if ( V_55 -> V_242 ) {
F_105 ( & V_55 -> V_240 , V_55 -> V_242 ) ;
V_55 -> V_242 = NULL ;
}
F_126 ( V_51 , V_55 -> V_3 ) ;
F_21 ( ! V_51 -> V_77 ) ;
V_51 -> V_77 -- ;
if ( F_61 ( V_55 ) )
V_51 -> V_245 -- ;
}
static void F_213 ( struct V_115 * V_246 )
{
struct V_54 * V_55 = F_214 ( V_246 ) ;
const int V_79 = F_98 ( V_246 ) ;
F_21 ( ! V_55 -> V_19 [ V_79 ] ) ;
V_55 -> V_19 [ V_79 ] -- ;
F_215 ( & V_55 -> V_138 , V_246 ) ;
if ( F_208 ( V_55 ) && F_216 ( & V_55 -> V_138 ) ) {
if ( V_55 -> V_242 ) {
F_105 ( & V_55 -> V_240 , V_55 -> V_242 ) ;
V_55 -> V_242 = NULL ;
}
}
}
static void F_217 ( struct V_115 * V_246 )
{
struct V_54 * V_55 = F_214 ( V_246 ) ;
struct V_50 * V_51 = V_55 -> V_51 ;
struct V_115 * V_137 ;
V_55 -> V_19 [ F_98 ( V_246 ) ] ++ ;
F_218 ( & V_55 -> V_138 , V_246 ) ;
if ( ! F_208 ( V_55 ) )
F_209 ( V_51 , V_55 ) ;
V_137 = V_55 -> V_241 ;
V_55 -> V_241 = F_95 ( V_51 , V_55 -> V_241 , V_246 , V_51 -> V_247 ) ;
if ( V_137 != V_55 -> V_241 )
F_206 ( V_51 , V_55 ) ;
F_21 ( ! V_55 -> V_241 ) ;
}
static void F_219 ( struct V_54 * V_55 , struct V_115 * V_246 )
{
F_215 ( & V_55 -> V_138 , V_246 ) ;
V_55 -> V_19 [ F_98 ( V_246 ) ] -- ;
F_44 ( F_220 ( V_246 ) , F_221 ( V_246 ) , V_246 -> V_125 ) ;
F_217 ( V_246 ) ;
F_40 ( F_220 ( V_246 ) , V_55 -> V_51 -> V_248 ,
F_221 ( V_246 ) , V_246 -> V_125 ) ;
}
static struct V_115 *
F_222 ( struct V_50 * V_51 , struct V_73 * V_73 )
{
struct V_249 * V_250 = V_251 ;
struct V_63 * V_69 ;
struct V_54 * V_55 ;
V_69 = F_66 ( V_51 , V_250 -> V_66 ) ;
if ( ! V_69 )
return NULL ;
V_55 = F_68 ( V_69 , F_71 ( V_73 ) ) ;
if ( V_55 )
return F_223 ( & V_55 -> V_138 , F_224 ( V_73 ) ) ;
return NULL ;
}
static void F_225 ( struct V_252 * V_48 , struct V_115 * V_246 )
{
struct V_50 * V_51 = V_48 -> V_71 -> V_72 ;
V_51 -> V_253 ++ ;
F_92 ( V_51 , F_214 ( V_246 ) , L_13 ,
V_51 -> V_253 ) ;
V_51 -> V_247 = F_99 ( V_246 ) + F_226 ( V_246 ) ;
}
static void F_227 ( struct V_252 * V_48 , struct V_115 * V_246 )
{
struct V_50 * V_51 = V_48 -> V_71 -> V_72 ;
F_78 ( ! V_51 -> V_253 ) ;
V_51 -> V_253 -- ;
F_92 ( V_51 , F_214 ( V_246 ) , L_14 ,
V_51 -> V_253 ) ;
}
static void F_228 ( struct V_115 * V_246 )
{
struct V_54 * V_55 = F_214 ( V_246 ) ;
if ( V_55 -> V_241 == V_246 )
V_55 -> V_241 = F_108 ( V_55 -> V_51 , V_55 , V_246 ) ;
F_229 ( & V_246 -> V_254 ) ;
F_213 ( V_246 ) ;
V_55 -> V_51 -> V_255 -- ;
F_44 ( F_220 ( V_246 ) , F_221 ( V_246 ) , V_246 -> V_125 ) ;
if ( V_246 -> V_125 & V_126 ) {
F_78 ( ! V_55 -> V_256 ) ;
V_55 -> V_256 -- ;
}
}
static int F_230 ( struct V_252 * V_48 , struct V_115 * * V_257 ,
struct V_73 * V_73 )
{
struct V_50 * V_51 = V_48 -> V_71 -> V_72 ;
struct V_115 * V_258 ;
V_258 = F_222 ( V_51 , V_73 ) ;
if ( V_258 && F_231 ( V_258 , V_73 ) ) {
* V_257 = V_258 ;
return V_259 ;
}
return V_260 ;
}
static void F_232 ( struct V_252 * V_48 , struct V_115 * V_257 ,
int type )
{
if ( type == V_259 ) {
struct V_54 * V_55 = F_214 ( V_257 ) ;
F_219 ( V_55 , V_257 ) ;
}
}
static void F_233 ( struct V_252 * V_48 , struct V_115 * V_257 ,
struct V_73 * V_73 )
{
F_45 ( F_220 ( V_257 ) , F_234 ( V_73 ) , V_73 -> V_75 ) ;
}
static void
F_235 ( struct V_252 * V_48 , struct V_115 * V_246 ,
struct V_115 * V_136 )
{
struct V_54 * V_55 = F_214 ( V_246 ) ;
struct V_50 * V_51 = V_48 -> V_71 -> V_72 ;
if ( ! F_236 ( & V_246 -> V_254 ) && ! F_236 ( & V_136 -> V_254 ) &&
V_136 -> V_261 < V_246 -> V_261 &&
V_55 == F_214 ( V_136 ) ) {
F_237 ( & V_246 -> V_254 , & V_136 -> V_254 ) ;
V_246 -> V_261 = V_136 -> V_261 ;
}
if ( V_55 -> V_241 == V_136 )
V_55 -> V_241 = V_246 ;
F_228 ( V_136 ) ;
F_45 ( F_220 ( V_246 ) , F_221 ( V_136 ) , V_136 -> V_125 ) ;
V_55 = F_214 ( V_136 ) ;
if ( F_208 ( V_55 ) && F_216 ( & V_55 -> V_138 ) &&
V_55 != V_51 -> V_262 )
F_211 ( V_51 , V_55 ) ;
}
static int F_238 ( struct V_252 * V_48 , struct V_115 * V_246 ,
struct V_73 * V_73 )
{
struct V_50 * V_51 = V_48 -> V_71 -> V_72 ;
struct V_63 * V_69 ;
struct V_54 * V_55 ;
if ( F_71 ( V_73 ) && ! F_98 ( V_246 ) )
return false ;
V_69 = F_66 ( V_51 , V_251 -> V_66 ) ;
if ( ! V_69 )
return false ;
V_55 = F_68 ( V_69 , F_71 ( V_73 ) ) ;
return V_55 == F_214 ( V_246 ) ;
}
static int F_239 ( struct V_252 * V_48 , struct V_115 * V_246 ,
struct V_115 * V_136 )
{
return F_214 ( V_246 ) == F_214 ( V_136 ) ;
}
static inline void F_240 ( struct V_50 * V_51 , struct V_54 * V_55 )
{
F_241 ( & V_51 -> V_263 ) ;
F_17 ( V_55 -> V_3 ) ;
}
static void F_242 ( struct V_50 * V_51 ,
struct V_54 * V_55 )
{
if ( V_55 ) {
F_92 ( V_51 , V_55 , L_15 ,
V_51 -> V_167 , V_51 -> V_165 ) ;
F_23 ( V_55 -> V_3 ) ;
V_55 -> V_112 = 0 ;
V_55 -> V_158 = F_91 () ;
V_55 -> V_114 = 0 ;
V_55 -> V_113 = 0 ;
V_55 -> V_162 = 0 ;
V_55 -> V_168 = 0 ;
F_243 ( V_55 ) ;
F_244 ( V_55 ) ;
F_245 ( V_55 ) ;
F_246 ( V_55 ) ;
F_247 ( V_55 ) ;
F_240 ( V_51 , V_55 ) ;
}
V_51 -> V_262 = V_55 ;
}
static void
F_248 ( struct V_50 * V_51 , struct V_54 * V_55 ,
bool V_264 )
{
F_92 ( V_51 , V_55 , L_16 , V_264 ) ;
if ( F_249 ( V_55 ) )
F_240 ( V_51 , V_55 ) ;
F_243 ( V_55 ) ;
F_250 ( V_55 ) ;
if ( F_251 ( V_55 ) && F_252 ( V_55 ) )
F_253 ( V_55 ) ;
if ( V_264 ) {
if ( F_94 ( V_55 ) )
V_55 -> V_234 = F_88 ( V_51 , V_55 ) ;
else
V_55 -> V_234 = V_55 -> V_113 - F_91 () ;
F_92 ( V_51 , V_55 , L_17 , V_55 -> V_234 ) ;
}
F_130 ( V_51 , V_55 -> V_3 , V_55 ) ;
if ( F_208 ( V_55 ) && F_216 ( & V_55 -> V_138 ) )
F_211 ( V_51 , V_55 ) ;
F_207 ( V_51 , V_55 ) ;
if ( V_55 == V_51 -> V_262 )
V_51 -> V_262 = NULL ;
if ( V_51 -> V_265 ) {
F_254 ( V_51 -> V_265 -> V_65 . V_67 ) ;
V_51 -> V_265 = NULL ;
}
}
static inline void F_255 ( struct V_50 * V_51 , bool V_264 )
{
struct V_54 * V_55 = V_51 -> V_262 ;
if ( V_55 )
F_248 ( V_51 , V_55 , V_264 ) ;
}
static struct V_54 * F_256 ( struct V_50 * V_51 )
{
struct V_1 * V_94 = F_1 ( V_51 -> V_248 ,
V_51 -> V_167 , V_51 -> V_165 ) ;
if ( ! V_51 -> V_255 )
return NULL ;
if ( ! V_94 )
return NULL ;
if ( F_216 ( & V_94 -> V_130 ) )
return NULL ;
return F_100 ( V_94 ) ;
}
static struct V_54 * F_257 ( struct V_50 * V_51 )
{
struct V_2 * V_3 ;
struct V_54 * V_55 ;
int V_169 , V_170 ;
struct V_1 * V_94 ;
if ( ! V_51 -> V_255 )
return NULL ;
V_3 = F_258 ( V_51 ) ;
if ( ! V_3 )
return NULL ;
F_132 (cfqg, i, j, st)
if ( ( V_55 = F_100 ( V_94 ) ) != NULL )
return V_55 ;
return NULL ;
}
static struct V_54 * F_259 ( struct V_50 * V_51 ,
struct V_54 * V_55 )
{
if ( ! V_55 )
V_55 = F_256 ( V_51 ) ;
F_242 ( V_51 , V_55 ) ;
return V_55 ;
}
static inline T_4 F_260 ( struct V_50 * V_51 ,
struct V_115 * V_246 )
{
if ( F_99 ( V_246 ) >= V_51 -> V_247 )
return F_99 ( V_246 ) - V_51 -> V_247 ;
else
return V_51 -> V_247 - F_99 ( V_246 ) ;
}
static inline int F_261 ( struct V_50 * V_51 , struct V_54 * V_55 ,
struct V_115 * V_246 )
{
return F_260 ( V_51 , V_246 ) <= V_266 ;
}
static struct V_54 * F_262 ( struct V_50 * V_51 ,
struct V_54 * V_267 )
{
struct V_133 * V_129 = & V_51 -> V_243 [ V_267 -> V_244 ] ;
struct V_131 * V_34 , * V_140 ;
struct V_54 * V_231 ;
T_4 V_237 = V_51 -> V_247 ;
if ( F_216 ( V_129 ) )
return NULL ;
V_231 = F_205 ( V_51 , V_129 , V_237 , & V_34 , NULL ) ;
if ( V_231 )
return V_231 ;
V_231 = F_102 ( V_34 , struct V_54 , V_240 ) ;
if ( F_261 ( V_51 , V_267 , V_231 -> V_241 ) )
return V_231 ;
if ( F_99 ( V_231 -> V_241 ) < V_237 )
V_140 = F_109 ( & V_231 -> V_240 ) ;
else
V_140 = F_110 ( & V_231 -> V_240 ) ;
if ( ! V_140 )
return NULL ;
V_231 = F_102 ( V_140 , struct V_54 , V_240 ) ;
if ( F_261 ( V_51 , V_267 , V_231 -> V_241 ) )
return V_231 ;
return NULL ;
}
static struct V_54 * F_263 ( struct V_50 * V_51 ,
struct V_54 * V_267 )
{
struct V_54 * V_55 ;
if ( F_58 ( V_267 ) )
return NULL ;
if ( ! F_61 ( V_267 ) )
return NULL ;
if ( F_252 ( V_267 ) )
return NULL ;
if ( V_267 -> V_3 -> V_139 == 1 )
return NULL ;
V_55 = F_262 ( V_51 , V_267 ) ;
if ( ! V_55 )
return NULL ;
if ( V_267 -> V_3 != V_55 -> V_3 )
return NULL ;
if ( ! F_61 ( V_55 ) )
return NULL ;
if ( F_252 ( V_55 ) )
return NULL ;
if ( F_59 ( V_55 ) != F_59 ( V_267 ) )
return NULL ;
return V_55 ;
}
static bool F_264 ( struct V_50 * V_51 , struct V_54 * V_55 )
{
enum V_4 V_61 = F_57 ( V_55 ) ;
struct V_1 * V_94 = V_55 -> V_236 ;
F_21 ( ! V_94 ) ;
F_21 ( ! V_94 -> V_62 ) ;
if ( ! V_51 -> V_52 )
return false ;
if ( V_61 == V_7 )
return false ;
if ( F_62 ( V_55 ) &&
! ( F_265 ( V_51 -> V_68 ) && V_51 -> V_53 ) )
return true ;
if ( V_94 -> V_62 == 1 && F_61 ( V_55 ) &&
! F_266 ( V_51 , & V_94 -> V_172 , false ) )
return true ;
F_92 ( V_51 , V_55 , L_18 , V_94 -> V_62 ) ;
return false ;
}
static void F_267 ( struct V_50 * V_51 )
{
struct V_54 * V_55 = V_51 -> V_262 ;
struct V_1 * V_94 = V_55 -> V_236 ;
struct V_63 * V_69 ;
T_2 V_268 , V_269 = 0 ;
T_2 V_12 = F_91 () ;
if ( F_265 ( V_51 -> V_68 ) && V_51 -> V_53 )
return;
F_78 ( ! F_216 ( & V_55 -> V_138 ) ) ;
F_78 ( F_94 ( V_55 ) ) ;
if ( ! F_264 ( V_51 , V_55 ) ) {
if ( V_51 -> V_270 )
V_269 = V_51 -> V_270 ;
else
return;
}
if ( V_55 -> V_271 )
return;
V_69 = V_51 -> V_265 ;
if ( ! V_69 || ! F_268 ( & V_69 -> V_65 . V_67 -> V_272 ) )
return;
if ( F_269 ( V_69 -> V_172 . V_273 ) &&
( V_55 -> V_113 - V_12 < V_69 -> V_172 . V_274 ) ) {
F_92 ( V_51 , V_55 , L_19 ,
V_69 -> V_172 . V_274 ) ;
return;
}
if ( V_269 &&
( V_55 -> V_3 -> V_139 > 1 ||
F_266 ( V_51 , & V_94 -> V_172 , true ) ) )
return;
F_270 ( V_55 ) ;
if ( V_269 )
V_268 = V_51 -> V_270 ;
else
V_268 = V_51 -> V_52 ;
F_271 ( & V_51 -> V_263 , F_272 ( V_268 ) ,
V_275 ) ;
F_20 ( V_55 -> V_3 ) ;
F_92 ( V_51 , V_55 , L_20 , V_268 ,
V_269 ? 1 : 0 ) ;
}
static void F_273 ( struct V_252 * V_48 , struct V_115 * V_246 )
{
struct V_50 * V_51 = V_48 -> V_71 -> V_72 ;
struct V_54 * V_55 = F_214 ( V_246 ) ;
F_92 ( V_51 , V_55 , L_21 ) ;
V_55 -> V_241 = F_108 ( V_51 , V_55 , V_246 ) ;
F_228 ( V_246 ) ;
V_55 -> V_271 ++ ;
( F_220 ( V_246 ) ) -> V_271 ++ ;
F_274 ( V_48 , V_246 ) ;
V_51 -> V_276 [ F_61 ( V_55 ) ] ++ ;
V_55 -> V_168 += F_226 ( V_246 ) ;
}
static struct V_115 * F_275 ( struct V_54 * V_55 )
{
struct V_115 * V_246 = NULL ;
if ( F_276 ( V_55 ) )
return NULL ;
F_277 ( V_55 ) ;
if ( F_236 ( & V_55 -> V_277 ) )
return NULL ;
V_246 = F_278 ( V_55 -> V_277 . V_136 ) ;
if ( F_91 () < V_246 -> V_261 )
V_246 = NULL ;
return V_246 ;
}
static inline int
F_279 ( struct V_50 * V_51 , struct V_54 * V_55 )
{
const int V_278 = V_51 -> V_279 ;
F_78 ( V_55 -> V_86 >= V_85 ) ;
return 2 * V_278 * ( V_85 - V_55 -> V_86 ) ;
}
static int F_280 ( struct V_54 * V_55 )
{
int V_280 , V_281 ;
V_281 = V_55 -> V_282 [ V_74 ] + V_55 -> V_282 [ V_283 ] ;
V_280 = V_55 -> V_284 - V_281 ;
F_21 ( V_280 < 0 ) ;
return V_280 ;
}
static void F_281 ( struct V_54 * V_55 , struct V_54 * V_233 )
{
int V_280 , V_285 ;
struct V_54 * V_231 ;
if ( ! F_280 ( V_233 ) )
return;
while ( ( V_231 = V_233 -> V_233 ) ) {
if ( V_231 == V_55 )
return;
V_233 = V_231 ;
}
V_280 = F_280 ( V_55 ) ;
V_285 = F_280 ( V_233 ) ;
if ( V_280 == 0 || V_285 == 0 )
return;
if ( V_285 >= V_280 ) {
V_55 -> V_233 = V_233 ;
V_233 -> V_284 += V_280 ;
} else {
V_233 -> V_233 = V_55 ;
V_55 -> V_284 += V_285 ;
}
}
static enum V_6 F_282 ( struct V_50 * V_51 ,
struct V_2 * V_3 , enum V_4 V_61 )
{
struct V_54 * V_68 ;
int V_169 ;
bool V_286 = false ;
T_2 V_287 = 0 ;
enum V_6 V_288 = V_59 ;
for ( V_169 = 0 ; V_169 <= V_60 ; ++ V_169 ) {
V_68 = F_100 ( F_1 ( V_3 , V_61 , V_169 ) ) ;
if ( V_68 &&
( ! V_286 || V_68 -> V_232 < V_287 ) ) {
V_287 = V_68 -> V_232 ;
V_288 = V_169 ;
V_286 = true ;
}
}
return V_288 ;
}
static void
F_283 ( struct V_50 * V_51 , struct V_2 * V_3 )
{
T_2 V_83 ;
unsigned V_62 ;
struct V_1 * V_94 ;
T_2 V_109 ;
enum V_4 V_289 = V_51 -> V_167 ;
T_2 V_12 = F_91 () ;
if ( F_63 ( V_56 , V_51 , V_3 ) )
V_51 -> V_167 = V_56 ;
else if ( F_63 ( V_57 , V_51 , V_3 ) )
V_51 -> V_167 = V_57 ;
else {
V_51 -> V_167 = V_7 ;
V_51 -> V_163 = V_12 + F_129 ( 1 ) ;
return;
}
if ( V_289 != V_51 -> V_167 )
goto V_290;
V_94 = F_1 ( V_3 , V_51 -> V_167 , V_51 -> V_165 ) ;
V_62 = V_94 -> V_62 ;
if ( V_62 && ! ( V_12 > V_51 -> V_163 ) )
return;
V_290:
V_51 -> V_165 = F_282 ( V_51 , V_3 ,
V_51 -> V_167 ) ;
V_94 = F_1 ( V_3 , V_51 -> V_167 , V_51 -> V_165 ) ;
V_62 = V_94 -> V_62 ;
V_109 = F_87 ( V_51 , V_3 ) ;
V_83 = F_77 ( V_109 * V_62 ,
F_121 ( unsigned , V_3 -> V_103 [ V_51 -> V_167 ] ,
F_63 ( V_51 -> V_167 , V_51 ,
V_3 ) ) ) ;
if ( V_51 -> V_165 == V_58 ) {
T_2 V_222 ;
V_222 = V_51 -> V_104 *
F_64 ( V_51 , V_3 ) ;
V_222 = F_77 ( V_222 , V_51 -> V_77 ) ;
V_83 = F_284 ( T_2 , V_83 , V_222 ) ;
V_83 = F_89 ( V_83 * V_51 -> V_82 [ 0 ] , V_51 -> V_82 [ 1 ] ) ;
} else
V_83 = F_86 ( V_83 , 2 * V_51 -> V_52 ) ;
V_83 = F_121 ( T_2 , V_83 , V_291 ) ;
F_74 ( V_51 , L_22 , V_83 ) ;
V_51 -> V_163 = V_12 + V_83 ;
}
static struct V_2 * F_258 ( struct V_50 * V_51 )
{
struct V_1 * V_94 = & V_51 -> V_154 ;
struct V_2 * V_3 ;
if ( F_216 ( & V_94 -> V_130 ) )
return NULL ;
V_3 = F_103 ( V_94 ) ;
F_82 ( V_94 ) ;
return V_3 ;
}
static void F_285 ( struct V_50 * V_51 )
{
struct V_2 * V_3 = F_258 ( V_51 ) ;
T_2 V_12 = F_91 () ;
V_51 -> V_248 = V_3 ;
if ( V_3 -> V_156 ) {
V_51 -> V_163 = V_12 + V_3 -> V_156 ;
V_51 -> V_165 = V_3 -> V_164 ;
V_51 -> V_167 = V_3 -> V_166 ;
} else
V_51 -> V_163 = V_12 - 1 ;
F_283 ( V_51 , V_3 ) ;
}
static struct V_54 * F_286 ( struct V_50 * V_51 )
{
struct V_54 * V_55 , * V_233 = NULL ;
T_2 V_12 = F_91 () ;
V_55 = V_51 -> V_262 ;
if ( ! V_55 )
goto V_292;
if ( ! V_51 -> V_255 )
return NULL ;
if ( F_287 ( V_55 ) && ! F_216 ( & V_55 -> V_138 ) )
goto V_293;
if ( F_93 ( V_55 ) && ! F_288 ( V_55 ) ) {
if ( V_55 -> V_3 -> V_139 == 1 && F_216 ( & V_55 -> V_138 )
&& V_55 -> V_271 && F_264 ( V_51 , V_55 ) ) {
V_55 = NULL ;
goto V_294;
} else
goto V_295;
}
if ( ! F_216 ( & V_55 -> V_138 ) )
goto V_294;
V_233 = F_263 ( V_51 , V_55 ) ;
if ( V_233 ) {
if ( ! V_55 -> V_233 )
F_281 ( V_55 , V_233 ) ;
goto V_293;
}
if ( F_289 ( & V_51 -> V_263 ) ) {
V_55 = NULL ;
goto V_294;
}
if ( F_252 ( V_55 ) && F_62 ( V_55 ) &&
( F_94 ( V_55 ) ||
( V_55 -> V_113 - V_12 > V_12 - V_55 -> V_112 ) ) ) {
F_290 ( V_55 ) ;
F_291 ( V_55 ) ;
}
if ( V_55 -> V_271 && F_264 ( V_51 , V_55 ) ) {
V_55 = NULL ;
goto V_294;
}
V_295:
if ( V_51 -> V_270 && V_55 -> V_3 -> V_139 == 1 &&
V_55 -> V_3 -> V_271 &&
! F_266 ( V_51 , & V_55 -> V_3 -> V_172 , true ) ) {
V_55 = NULL ;
goto V_294;
}
V_293:
F_255 ( V_51 , 0 ) ;
V_292:
if ( ! V_233 )
F_285 ( V_51 ) ;
V_55 = F_259 ( V_51 , V_233 ) ;
V_294:
return V_55 ;
}
static int F_292 ( struct V_54 * V_55 )
{
int V_271 = 0 ;
while ( V_55 -> V_241 ) {
F_273 ( V_55 -> V_51 -> V_68 , V_55 -> V_241 ) ;
V_271 ++ ;
}
F_21 ( ! F_236 ( & V_55 -> V_277 ) ) ;
F_248 ( V_55 -> V_51 , V_55 , 0 ) ;
return V_271 ;
}
static int F_293 ( struct V_50 * V_51 )
{
struct V_54 * V_55 ;
int V_271 = 0 ;
F_255 ( V_51 , 0 ) ;
while ( ( V_55 = F_257 ( V_51 ) ) != NULL ) {
F_242 ( V_51 , V_55 ) ;
V_271 += F_292 ( V_55 ) ;
}
F_21 ( V_51 -> V_77 ) ;
F_74 ( V_51 , L_23 , V_271 ) ;
return V_271 ;
}
static inline bool F_294 ( struct V_50 * V_51 ,
struct V_54 * V_55 )
{
T_2 V_12 = F_91 () ;
if ( F_94 ( V_55 ) )
return true ;
if ( V_12 + V_51 -> V_52 * V_55 -> V_271 > V_55 -> V_113 )
return true ;
return false ;
}
static bool F_295 ( struct V_50 * V_51 , struct V_54 * V_55 )
{
unsigned int V_296 ;
if ( F_288 ( V_55 ) )
return true ;
if ( F_264 ( V_51 , V_55 ) && V_51 -> V_276 [ V_297 ] )
return false ;
if ( V_51 -> V_276 [ V_298 ] && ! F_61 ( V_55 ) )
return false ;
V_296 = F_121 (unsigned int, cfqd->cfq_quantum / 2 , 1 ) ;
if ( F_58 ( V_55 ) )
V_296 = 1 ;
if ( V_55 -> V_271 >= V_296 ) {
bool V_299 = false ;
if ( F_58 ( V_55 ) )
return false ;
if ( F_61 ( V_55 ) && V_51 -> V_245 == 1 )
V_299 = true ;
if ( V_51 -> V_77 > 1 && F_294 ( V_51 , V_55 ) &&
! V_299 )
return false ;
if ( V_51 -> V_77 == 1 || V_299 )
V_296 = - 1 ;
else
V_296 = V_51 -> V_300 ;
}
if ( ! F_61 ( V_55 ) && V_51 -> V_105 ) {
T_2 V_301 = F_91 () - V_51 -> V_302 ;
unsigned int V_303 ;
V_303 = F_89 ( V_301 , V_51 -> V_82 [ 1 ] ) ;
if ( ! V_303 && ! V_55 -> V_271 )
V_303 = 1 ;
if ( V_303 < V_296 )
V_296 = V_303 ;
}
return V_55 -> V_271 < V_296 ;
}
static bool F_296 ( struct V_50 * V_51 , struct V_54 * V_55 )
{
struct V_115 * V_246 ;
F_21 ( F_216 ( & V_55 -> V_138 ) ) ;
V_246 = F_275 ( V_55 ) ;
if ( V_246 )
F_297 ( V_55 ) ;
if ( ! F_295 ( V_51 , V_55 ) )
return false ;
if ( ! V_246 )
V_246 = V_55 -> V_241 ;
else
F_92 ( V_55 -> V_51 , V_55 , L_24 , V_246 ) ;
F_273 ( V_51 -> V_68 , V_246 ) ;
if ( ! V_51 -> V_265 ) {
struct V_63 * V_69 = F_298 ( V_246 ) ;
F_299 ( & V_69 -> V_65 . V_67 -> V_304 ) ;
V_51 -> V_265 = V_69 ;
}
return true ;
}
static int F_300 ( struct V_252 * V_48 , int V_305 )
{
struct V_50 * V_51 = V_48 -> V_71 -> V_72 ;
struct V_54 * V_55 ;
if ( ! V_51 -> V_77 )
return 0 ;
if ( F_55 ( V_305 ) )
return F_293 ( V_51 ) ;
V_55 = F_286 ( V_51 ) ;
if ( ! V_55 )
return 0 ;
if ( ! F_296 ( V_51 , V_55 ) )
return 0 ;
V_55 -> V_162 ++ ;
F_244 ( V_55 ) ;
if ( V_51 -> V_77 > 1 && ( ( ! F_61 ( V_55 ) &&
V_55 -> V_162 >= F_279 ( V_51 , V_55 ) ) ||
F_58 ( V_55 ) ) ) {
V_55 -> V_113 = F_91 () + 1 ;
F_255 ( V_51 , 0 ) ;
}
F_92 ( V_51 , V_55 , L_25 ) ;
return 1 ;
}
static void F_152 ( struct V_54 * V_55 )
{
struct V_50 * V_51 = V_55 -> V_51 ;
struct V_2 * V_3 ;
F_21 ( V_55 -> V_284 <= 0 ) ;
V_55 -> V_284 -- ;
if ( V_55 -> V_284 )
return;
F_92 ( V_51 , V_55 , L_26 ) ;
F_21 ( F_101 ( & V_55 -> V_138 ) ) ;
F_21 ( V_55 -> V_282 [ V_74 ] + V_55 -> V_282 [ V_283 ] ) ;
V_3 = V_55 -> V_3 ;
if ( F_55 ( V_51 -> V_262 == V_55 ) ) {
F_248 ( V_51 , V_55 , 0 ) ;
F_73 ( V_51 ) ;
}
F_21 ( F_208 ( V_55 ) ) ;
F_301 ( V_306 , V_55 ) ;
F_38 ( V_3 ) ;
}
static void F_302 ( struct V_54 * V_55 )
{
struct V_54 * V_231 , * V_136 ;
V_231 = V_55 -> V_233 ;
while ( V_231 ) {
if ( V_231 == V_55 ) {
F_303 ( 1 , L_27 ) ;
break;
}
V_136 = V_231 -> V_233 ;
F_152 ( V_231 ) ;
V_231 = V_136 ;
}
}
static void F_304 ( struct V_50 * V_51 , struct V_54 * V_55 )
{
if ( F_55 ( V_55 == V_51 -> V_262 ) ) {
F_248 ( V_51 , V_55 , 0 ) ;
F_73 ( V_51 ) ;
}
F_302 ( V_55 ) ;
F_152 ( V_55 ) ;
}
static void F_305 ( struct V_64 * V_65 )
{
struct V_63 * V_69 = F_65 ( V_65 ) ;
V_69 -> V_172 . V_173 = F_91 () ;
}
static void F_306 ( struct V_64 * V_65 )
{
struct V_63 * V_69 = F_65 ( V_65 ) ;
struct V_50 * V_51 = F_70 ( V_69 ) ;
if ( F_68 ( V_69 , false ) ) {
F_304 ( V_51 , F_68 ( V_69 , false ) ) ;
F_69 ( V_69 , NULL , false ) ;
}
if ( F_68 ( V_69 , true ) ) {
F_304 ( V_51 , F_68 ( V_69 , true ) ) ;
F_69 ( V_69 , NULL , true ) ;
}
}
static void F_307 ( struct V_54 * V_55 , struct V_63 * V_69 )
{
struct V_249 * V_250 = V_251 ;
int V_307 ;
if ( ! F_308 ( V_55 ) )
return;
V_307 = F_309 ( V_69 -> V_86 ) ;
switch ( V_307 ) {
default:
F_310 ( V_308 L_28 , V_307 ) ;
case V_309 :
V_55 -> V_86 = F_311 ( V_250 ) ;
V_55 -> V_307 = F_312 ( V_250 ) ;
break;
case V_310 :
V_55 -> V_86 = F_313 ( V_69 -> V_86 ) ;
V_55 -> V_307 = V_310 ;
break;
case V_311 :
V_55 -> V_86 = F_313 ( V_69 -> V_86 ) ;
V_55 -> V_307 = V_311 ;
break;
case V_312 :
V_55 -> V_307 = V_312 ;
V_55 -> V_86 = 7 ;
F_291 ( V_55 ) ;
break;
}
V_55 -> V_244 = V_55 -> V_86 ;
V_55 -> V_313 = V_55 -> V_307 ;
F_314 ( V_55 ) ;
}
static void F_315 ( struct V_63 * V_69 , struct V_73 * V_73 )
{
int V_86 = V_69 -> V_65 . V_67 -> V_86 ;
struct V_50 * V_51 = F_70 ( V_69 ) ;
struct V_54 * V_55 ;
if ( F_55 ( ! V_51 ) || F_157 ( V_69 -> V_86 == V_86 ) )
return;
V_55 = F_68 ( V_69 , false ) ;
if ( V_55 ) {
F_152 ( V_55 ) ;
V_55 = F_316 ( V_51 , V_297 , V_69 , V_73 ) ;
F_69 ( V_69 , V_55 , false ) ;
}
V_55 = F_68 ( V_69 , true ) ;
if ( V_55 )
F_317 ( V_55 ) ;
V_69 -> V_86 = V_86 ;
}
static void F_318 ( struct V_50 * V_51 , struct V_54 * V_55 ,
T_9 V_314 , bool V_70 )
{
F_106 ( & V_55 -> V_131 ) ;
F_106 ( & V_55 -> V_240 ) ;
F_319 ( & V_55 -> V_277 ) ;
V_55 -> V_284 = 0 ;
V_55 -> V_51 = V_51 ;
F_317 ( V_55 ) ;
if ( V_70 ) {
if ( ! F_58 ( V_55 ) )
F_320 ( V_55 ) ;
F_321 ( V_55 ) ;
}
V_55 -> V_314 = V_314 ;
}
static void F_322 ( struct V_63 * V_69 , struct V_73 * V_73 )
{
struct V_50 * V_51 = F_70 ( V_69 ) ;
struct V_54 * V_55 ;
T_1 V_315 ;
F_323 () ;
V_315 = F_324 ( V_73 ) -> V_36 . V_315 ;
F_325 () ;
if ( F_55 ( ! V_51 ) || F_157 ( V_69 -> V_316 == V_315 ) )
return;
V_55 = F_68 ( V_69 , false ) ;
if ( V_55 ) {
F_92 ( V_51 , V_55 , L_29 ) ;
F_69 ( V_69 , NULL , false ) ;
F_152 ( V_55 ) ;
}
V_55 = F_68 ( V_69 , true ) ;
if ( V_55 ) {
F_92 ( V_51 , V_55 , L_29 ) ;
F_69 ( V_69 , NULL , true ) ;
F_152 ( V_55 ) ;
}
V_69 -> V_316 = V_315 ;
}
static inline void F_322 ( struct V_63 * V_69 , struct V_73 * V_73 ) { }
static struct V_54 * *
F_326 ( struct V_2 * V_3 , int V_307 , int V_86 )
{
switch ( V_307 ) {
case V_310 :
return & V_3 -> V_184 [ 0 ] [ V_86 ] ;
case V_309 :
V_86 = V_317 ;
case V_311 :
return & V_3 -> V_184 [ 1 ] [ V_86 ] ;
case V_312 :
return & V_3 -> V_185 ;
default:
F_327 () ;
}
}
static struct V_54 *
F_316 ( struct V_50 * V_51 , bool V_70 , struct V_63 * V_69 ,
struct V_73 * V_73 )
{
int V_307 = F_309 ( V_69 -> V_86 ) ;
int V_86 = F_313 ( V_69 -> V_86 ) ;
struct V_54 * * V_184 = NULL ;
struct V_54 * V_55 ;
struct V_2 * V_3 ;
F_323 () ;
V_3 = F_155 ( V_51 , F_324 ( V_73 ) ) ;
if ( ! V_3 ) {
V_55 = & V_51 -> V_318 ;
goto V_213;
}
if ( ! V_70 ) {
if ( ! F_328 ( V_69 -> V_86 ) ) {
struct V_249 * V_250 = V_251 ;
V_86 = F_311 ( V_250 ) ;
V_307 = F_312 ( V_250 ) ;
}
V_184 = F_326 ( V_3 , V_307 , V_86 ) ;
V_55 = * V_184 ;
if ( V_55 )
goto V_213;
}
V_55 = F_329 ( V_306 , V_319 | V_320 ,
V_51 -> V_68 -> V_140 ) ;
if ( ! V_55 ) {
V_55 = & V_51 -> V_318 ;
goto V_213;
}
F_318 ( V_51 , V_55 , V_251 -> V_314 , V_70 ) ;
F_307 ( V_55 , V_69 ) ;
F_158 ( V_55 , V_3 ) ;
F_92 ( V_51 , V_55 , L_30 ) ;
if ( V_184 ) {
V_55 -> V_284 ++ ;
* V_184 = V_55 ;
}
V_213:
V_55 -> V_284 ++ ;
F_325 () ;
return V_55 ;
}
static void
F_330 ( struct V_321 * V_172 , T_2 V_322 )
{
T_2 V_323 = F_91 () - V_172 -> V_173 ;
V_323 = F_85 ( V_323 , 2UL * V_322 ) ;
V_172 -> V_273 = ( 7 * V_172 -> V_273 + 256 ) / 8 ;
V_172 -> V_324 = F_77 ( 7 * V_172 -> V_324 + 256 * V_323 , 8 ) ;
V_172 -> V_274 = F_331 ( V_172 -> V_324 + 128 ,
V_172 -> V_273 ) ;
}
static void
F_332 ( struct V_50 * V_51 , struct V_54 * V_55 ,
struct V_63 * V_69 )
{
if ( F_61 ( V_55 ) ) {
F_330 ( & V_69 -> V_172 , V_51 -> V_52 ) ;
F_330 ( & V_55 -> V_236 -> V_172 ,
V_51 -> V_52 ) ;
}
#ifdef F_333
F_330 ( & V_55 -> V_3 -> V_172 , V_51 -> V_270 ) ;
#endif
}
static void
F_334 ( struct V_50 * V_51 , struct V_54 * V_55 ,
struct V_115 * V_246 )
{
T_4 V_325 = 0 ;
T_4 V_326 = F_226 ( V_246 ) ;
if ( V_55 -> V_327 ) {
if ( V_55 -> V_327 < F_99 ( V_246 ) )
V_325 = F_99 ( V_246 ) - V_55 -> V_327 ;
else
V_325 = V_55 -> V_327 - F_99 ( V_246 ) ;
}
V_55 -> V_328 <<= 1 ;
if ( F_265 ( V_51 -> V_68 ) )
V_55 -> V_328 |= ( V_326 < V_329 ) ;
else
V_55 -> V_328 |= ( V_325 > V_330 ) ;
}
static void
F_335 ( struct V_50 * V_51 , struct V_54 * V_55 ,
struct V_63 * V_69 )
{
int V_331 , V_332 ;
if ( ! F_61 ( V_55 ) || F_58 ( V_55 ) )
return;
V_332 = V_331 = F_62 ( V_55 ) ;
if ( V_55 -> V_19 [ 0 ] + V_55 -> V_19 [ 1 ] >= 4 )
F_336 ( V_55 ) ;
if ( V_55 -> V_241 && ( V_55 -> V_241 -> V_125 & V_333 ) )
V_332 = 0 ;
else if ( ! F_268 ( & V_69 -> V_65 . V_67 -> V_272 ) ||
! V_51 -> V_52 ||
( ! F_337 ( V_55 ) && F_252 ( V_55 ) ) )
V_332 = 0 ;
else if ( F_269 ( V_69 -> V_172 . V_273 ) ) {
if ( V_69 -> V_172 . V_274 > V_51 -> V_52 )
V_332 = 0 ;
else
V_332 = 1 ;
}
if ( V_331 != V_332 ) {
F_92 ( V_51 , V_55 , L_31 , V_332 ) ;
if ( V_332 )
F_320 ( V_55 ) ;
else
F_291 ( V_55 ) ;
}
}
static bool
F_338 ( struct V_50 * V_51 , struct V_54 * V_233 ,
struct V_115 * V_246 )
{
struct V_54 * V_55 ;
V_55 = V_51 -> V_262 ;
if ( ! V_55 )
return false ;
if ( F_58 ( V_233 ) )
return false ;
if ( F_58 ( V_55 ) )
return true ;
if ( F_59 ( V_55 ) && ! F_59 ( V_233 ) )
return false ;
if ( F_98 ( V_246 ) && ! F_61 ( V_55 ) && ! F_288 ( V_55 ) )
return true ;
if ( ! F_34 ( V_55 -> V_3 , V_233 -> V_3 ) )
return false ;
if ( F_93 ( V_55 ) )
return true ;
if ( F_59 ( V_233 ) && ! F_59 ( V_55 ) )
return true ;
F_125 ( V_55 -> V_307 != V_233 -> V_307 ) ;
if ( V_51 -> V_165 == V_59 &&
F_60 ( V_233 ) == V_59 &&
F_216 ( & V_55 -> V_138 ) )
return true ;
if ( ( V_246 -> V_125 & V_126 ) && ! V_55 -> V_256 )
return true ;
if ( F_216 ( & V_55 -> V_138 ) && ! F_264 ( V_51 , V_55 ) )
return true ;
if ( ! V_51 -> V_265 || ! F_249 ( V_55 ) )
return false ;
if ( F_261 ( V_51 , V_55 , V_246 ) )
return true ;
return false ;
}
static void F_339 ( struct V_50 * V_51 , struct V_54 * V_55 )
{
enum V_6 V_334 = F_60 ( V_51 -> V_262 ) ;
F_92 ( V_51 , V_55 , L_32 ) ;
F_255 ( V_51 , 1 ) ;
if ( V_334 != F_60 ( V_55 ) )
V_55 -> V_3 -> V_156 = 0 ;
F_21 ( ! F_208 ( V_55 ) ) ;
F_204 ( V_51 , V_55 , 1 ) ;
V_55 -> V_113 = 0 ;
F_247 ( V_55 ) ;
}
static void
F_340 ( struct V_50 * V_51 , struct V_54 * V_55 ,
struct V_115 * V_246 )
{
struct V_63 * V_69 = F_298 ( V_246 ) ;
V_51 -> V_255 ++ ;
if ( V_246 -> V_125 & V_126 )
V_55 -> V_256 ++ ;
F_332 ( V_51 , V_55 , V_69 ) ;
F_334 ( V_51 , V_55 , V_246 ) ;
F_335 ( V_51 , V_55 , V_69 ) ;
V_55 -> V_327 = F_99 ( V_246 ) + F_226 ( V_246 ) ;
if ( V_55 == V_51 -> V_262 ) {
if ( F_249 ( V_55 ) ) {
if ( F_341 ( V_246 ) > V_335 ||
V_51 -> V_77 > 1 ) {
F_240 ( V_51 , V_55 ) ;
F_243 ( V_55 ) ;
F_342 ( V_51 -> V_68 ) ;
} else {
F_17 ( V_55 -> V_3 ) ;
F_297 ( V_55 ) ;
}
}
} else if ( F_338 ( V_51 , V_55 , V_246 ) ) {
F_339 ( V_51 , V_55 ) ;
F_342 ( V_51 -> V_68 ) ;
}
}
static void F_343 ( struct V_252 * V_48 , struct V_115 * V_246 )
{
struct V_50 * V_51 = V_48 -> V_71 -> V_72 ;
struct V_54 * V_55 = F_214 ( V_246 ) ;
F_92 ( V_51 , V_55 , L_33 ) ;
F_307 ( V_55 , F_298 ( V_246 ) ) ;
V_246 -> V_261 = F_91 () + V_51 -> V_336 [ F_98 ( V_246 ) ] ;
F_344 ( & V_246 -> V_254 , & V_55 -> V_277 ) ;
F_217 ( V_246 ) ;
F_40 ( F_220 ( V_246 ) , V_51 -> V_248 , F_221 ( V_246 ) ,
V_246 -> V_125 ) ;
F_340 ( V_51 , V_55 , V_246 ) ;
}
static void F_345 ( struct V_50 * V_51 )
{
struct V_54 * V_55 = V_51 -> V_262 ;
if ( V_51 -> V_253 > V_51 -> V_337 )
V_51 -> V_337 = V_51 -> V_253 ;
if ( V_51 -> V_53 == 1 )
return;
if ( V_51 -> V_255 <= V_338 &&
V_51 -> V_253 <= V_338 )
return;
if ( V_55 && F_62 ( V_55 ) &&
V_55 -> V_271 + V_55 -> V_19 [ 0 ] + V_55 -> V_19 [ 1 ] <
V_338 && V_51 -> V_253 < V_338 )
return;
if ( V_51 -> V_339 ++ < 50 )
return;
if ( V_51 -> V_337 >= V_338 )
V_51 -> V_53 = 1 ;
else
V_51 -> V_53 = 0 ;
}
static bool F_346 ( struct V_50 * V_51 , struct V_54 * V_55 )
{
struct V_63 * V_69 = V_51 -> V_265 ;
T_2 V_12 = F_91 () ;
if ( ! F_216 ( & V_55 -> V_138 ) )
return false ;
if ( V_55 -> V_3 -> V_139 > 1 )
return false ;
if ( F_266 ( V_51 , & V_55 -> V_3 -> V_172 , true ) )
return false ;
if ( F_93 ( V_55 ) )
return true ;
if ( V_69 && F_269 ( V_69 -> V_172 . V_273 )
&& ( V_55 -> V_113 - V_12 < V_69 -> V_172 . V_274 ) )
return true ;
if ( V_55 -> V_113 - V_12 <= F_129 ( 1 ) )
return true ;
return false ;
}
static void F_347 ( struct V_252 * V_48 , struct V_115 * V_246 )
{
struct V_54 * V_55 = F_214 ( V_246 ) ;
struct V_50 * V_51 = V_55 -> V_51 ;
const int V_79 = F_98 ( V_246 ) ;
T_2 V_12 = F_91 () ;
F_92 ( V_51 , V_55 , L_34 ,
! ! ( V_246 -> V_125 & V_333 ) ) ;
F_345 ( V_51 ) ;
F_78 ( ! V_51 -> V_253 ) ;
F_78 ( ! V_55 -> V_271 ) ;
V_51 -> V_253 -- ;
V_55 -> V_271 -- ;
( F_220 ( V_246 ) ) -> V_271 -- ;
F_46 ( V_55 -> V_3 , F_348 ( V_246 ) ,
F_349 ( V_246 ) , F_221 ( V_246 ) ,
V_246 -> V_125 ) ;
V_51 -> V_276 [ F_61 ( V_55 ) ] -- ;
if ( V_79 ) {
struct V_1 * V_94 ;
F_298 ( V_246 ) -> V_172 . V_173 = V_12 ;
if ( F_208 ( V_55 ) )
V_94 = V_55 -> V_236 ;
else
V_94 = F_1 ( V_55 -> V_3 , F_57 ( V_55 ) ,
F_60 ( V_55 ) ) ;
V_94 -> V_172 . V_173 = V_12 ;
if ( ! F_350 ( V_246 -> V_42 +
F_351 ( V_51 -> V_336 [ 1 ] ) ,
V_340 ) )
V_51 -> V_302 = V_12 ;
}
#ifdef F_333
V_55 -> V_3 -> V_172 . V_173 = V_12 ;
#endif
if ( V_51 -> V_262 == V_55 ) {
const bool V_341 = F_216 ( & V_55 -> V_138 ) ;
if ( F_94 ( V_55 ) ) {
F_90 ( V_51 , V_55 ) ;
F_352 ( V_55 ) ;
}
if ( F_346 ( V_51 , V_55 ) ) {
T_2 V_342 = V_51 -> V_52 ;
if ( ! V_51 -> V_52 )
V_342 = V_51 -> V_270 ;
V_55 -> V_113 = V_12 + V_342 ;
F_353 ( V_55 ) ;
F_92 ( V_51 , V_55 , L_35 ) ;
}
if ( F_93 ( V_55 ) || F_58 ( V_55 ) )
F_255 ( V_51 , 1 ) ;
else if ( V_79 && V_341 &&
! F_263 ( V_51 , V_55 ) ) {
F_267 ( V_51 ) ;
}
}
if ( ! V_51 -> V_253 )
F_73 ( V_51 ) ;
}
static void F_354 ( struct V_54 * V_55 , int V_39 )
{
if ( ! ( V_39 & V_126 ) ) {
V_55 -> V_307 = V_55 -> V_313 ;
V_55 -> V_86 = V_55 -> V_244 ;
} else {
if ( F_58 ( V_55 ) )
V_55 -> V_307 = V_311 ;
if ( V_55 -> V_86 > V_317 )
V_55 -> V_86 = V_317 ;
}
}
static inline int F_355 ( struct V_54 * V_55 )
{
if ( F_249 ( V_55 ) && ! F_356 ( V_55 ) ) {
F_357 ( V_55 ) ;
return V_343 ;
}
return V_344 ;
}
static int F_358 ( struct V_252 * V_48 , int V_38 , int V_39 )
{
struct V_50 * V_51 = V_48 -> V_71 -> V_72 ;
struct V_249 * V_250 = V_251 ;
struct V_63 * V_69 ;
struct V_54 * V_55 ;
V_69 = F_66 ( V_51 , V_250 -> V_66 ) ;
if ( ! V_69 )
return V_344 ;
V_55 = F_68 ( V_69 , F_359 ( V_38 , V_39 ) ) ;
if ( V_55 ) {
F_307 ( V_55 , V_69 ) ;
F_354 ( V_55 , V_39 ) ;
return F_355 ( V_55 ) ;
}
return V_344 ;
}
static void F_360 ( struct V_115 * V_246 )
{
struct V_54 * V_55 = F_214 ( V_246 ) ;
if ( V_55 ) {
const int V_345 = F_361 ( V_246 ) ;
F_21 ( ! V_55 -> V_282 [ V_345 ] ) ;
V_55 -> V_282 [ V_345 ] -- ;
F_38 ( F_220 ( V_246 ) ) ;
V_246 -> V_346 . V_347 [ 0 ] = NULL ;
V_246 -> V_346 . V_347 [ 1 ] = NULL ;
F_152 ( V_55 ) ;
}
}
static struct V_54 *
F_362 ( struct V_50 * V_51 , struct V_63 * V_69 ,
struct V_54 * V_55 )
{
F_92 ( V_51 , V_55 , L_36 , V_55 -> V_233 ) ;
F_69 ( V_69 , V_55 -> V_233 , 1 ) ;
F_363 ( V_55 -> V_233 ) ;
F_152 ( V_55 ) ;
return F_68 ( V_69 , 1 ) ;
}
static struct V_54 *
F_364 ( struct V_63 * V_69 , struct V_54 * V_55 )
{
if ( F_280 ( V_55 ) == 1 ) {
V_55 -> V_314 = V_251 -> V_314 ;
F_365 ( V_55 ) ;
F_366 ( V_55 ) ;
return V_55 ;
}
F_69 ( V_69 , NULL , 1 ) ;
F_302 ( V_55 ) ;
F_152 ( V_55 ) ;
return NULL ;
}
static int
F_367 ( struct V_252 * V_48 , struct V_115 * V_246 , struct V_73 * V_73 ,
T_5 V_348 )
{
struct V_50 * V_51 = V_48 -> V_71 -> V_72 ;
struct V_63 * V_69 = F_65 ( V_246 -> V_346 . V_65 ) ;
const int V_345 = F_361 ( V_246 ) ;
const bool V_70 = F_98 ( V_246 ) ;
struct V_54 * V_55 ;
F_177 ( V_48 -> V_49 ) ;
F_315 ( V_69 , V_73 ) ;
F_322 ( V_69 , V_73 ) ;
V_292:
V_55 = F_68 ( V_69 , V_70 ) ;
if ( ! V_55 || V_55 == & V_51 -> V_318 ) {
if ( V_55 )
F_152 ( V_55 ) ;
V_55 = F_316 ( V_51 , V_70 , V_69 , V_73 ) ;
F_69 ( V_69 , V_55 , V_70 ) ;
} else {
if ( F_251 ( V_55 ) && F_368 ( V_55 ) ) {
F_92 ( V_51 , V_55 , L_37 ) ;
V_55 = F_364 ( V_69 , V_55 ) ;
if ( ! V_55 )
goto V_292;
}
if ( V_55 -> V_233 )
V_55 = F_362 ( V_51 , V_69 , V_55 ) ;
}
V_55 -> V_282 [ V_345 ] ++ ;
V_55 -> V_284 ++ ;
F_36 ( V_55 -> V_3 ) ;
V_246 -> V_346 . V_347 [ 0 ] = V_55 ;
V_246 -> V_346 . V_347 [ 1 ] = V_55 -> V_3 ;
F_179 ( V_48 -> V_49 ) ;
return 0 ;
}
static void F_369 ( struct V_349 * V_350 )
{
struct V_50 * V_51 =
F_25 ( V_350 , struct V_50 , V_78 ) ;
struct V_252 * V_48 = V_51 -> V_68 ;
F_177 ( V_48 -> V_49 ) ;
F_342 ( V_51 -> V_68 ) ;
F_179 ( V_48 -> V_49 ) ;
}
static enum V_351 F_370 ( struct V_352 * V_353 )
{
struct V_50 * V_51 = F_25 ( V_353 , struct V_50 ,
V_263 ) ;
struct V_54 * V_55 ;
unsigned long V_354 ;
int V_264 = 1 ;
F_74 ( V_51 , L_38 ) ;
F_371 ( V_51 -> V_68 -> V_49 , V_354 ) ;
V_55 = V_51 -> V_262 ;
if ( V_55 ) {
V_264 = 0 ;
if ( F_288 ( V_55 ) )
goto V_355;
if ( F_93 ( V_55 ) )
goto V_293;
if ( ! V_51 -> V_77 )
goto V_356;
if ( ! F_216 ( & V_55 -> V_138 ) )
goto V_355;
F_290 ( V_55 ) ;
}
V_293:
F_255 ( V_51 , V_264 ) ;
V_355:
F_73 ( V_51 ) ;
V_356:
F_372 ( V_51 -> V_68 -> V_49 , V_354 ) ;
return V_357 ;
}
static void F_373 ( struct V_50 * V_51 )
{
F_374 ( & V_51 -> V_263 ) ;
F_375 ( & V_51 -> V_78 ) ;
}
static void F_376 ( struct V_358 * V_359 )
{
struct V_50 * V_51 = V_359 -> V_72 ;
struct V_252 * V_48 = V_51 -> V_68 ;
F_373 ( V_51 ) ;
F_177 ( V_48 -> V_49 ) ;
if ( V_51 -> V_262 )
F_248 ( V_51 , V_51 -> V_262 , 0 ) ;
F_179 ( V_48 -> V_49 ) ;
F_373 ( V_51 ) ;
#ifdef F_333
F_377 ( V_48 , & V_31 ) ;
#else
F_145 ( V_51 -> V_228 ) ;
#endif
F_145 ( V_51 ) ;
}
static int F_378 ( struct V_252 * V_48 , struct V_360 * V_359 )
{
struct V_50 * V_51 ;
struct V_29 * V_30 V_361 ;
int V_169 , V_205 ;
struct V_358 * V_362 ;
V_362 = F_379 ( V_48 , V_359 ) ;
if ( ! V_362 )
return - V_176 ;
V_51 = F_149 ( sizeof( * V_51 ) , V_178 , V_48 -> V_140 ) ;
if ( ! V_51 ) {
F_380 ( & V_362 -> V_363 ) ;
return - V_176 ;
}
V_362 -> V_72 = V_51 ;
V_51 -> V_68 = V_48 ;
F_177 ( V_48 -> V_49 ) ;
V_48 -> V_71 = V_362 ;
F_179 ( V_48 -> V_49 ) ;
V_51 -> V_154 = V_171 ;
#ifdef F_333
V_205 = F_381 ( V_48 , & V_31 ) ;
if ( V_205 )
goto V_364;
V_51 -> V_228 = F_29 ( V_48 -> V_365 ) ;
#else
V_205 = - V_176 ;
V_51 -> V_228 = F_149 ( sizeof( * V_51 -> V_228 ) ,
V_178 , V_51 -> V_68 -> V_140 ) ;
if ( ! V_51 -> V_228 )
goto V_364;
F_131 ( V_51 -> V_228 ) ;
V_51 -> V_228 -> V_146 = 2 * V_181 ;
V_51 -> V_228 -> V_148 = 2 * V_181 ;
#endif
for ( V_169 = 0 ; V_169 < V_366 ; V_169 ++ )
V_51 -> V_243 [ V_169 ] = V_367 ;
F_318 ( V_51 , & V_51 -> V_318 , 1 , 0 ) ;
V_51 -> V_318 . V_284 ++ ;
F_177 ( V_48 -> V_49 ) ;
F_158 ( & V_51 -> V_318 , V_51 -> V_228 ) ;
F_38 ( V_51 -> V_228 ) ;
F_179 ( V_48 -> V_49 ) ;
F_382 ( & V_51 -> V_263 , V_368 ,
V_275 ) ;
V_51 -> V_263 . V_369 = F_370 ;
F_383 ( & V_51 -> V_78 , F_369 ) ;
V_51 -> V_300 = V_300 ;
V_51 -> V_336 [ 0 ] = V_336 [ 0 ] ;
V_51 -> V_336 [ 1 ] = V_336 [ 1 ] ;
V_51 -> V_127 = V_127 ;
V_51 -> V_128 = V_128 ;
V_51 -> V_82 [ 0 ] = V_370 ;
V_51 -> V_82 [ 1 ] = V_371 ;
V_51 -> V_104 = V_104 ;
V_51 -> V_279 = V_279 ;
V_51 -> V_52 = V_52 ;
V_51 -> V_270 = V_270 ;
V_51 -> V_105 = 1 ;
V_51 -> V_53 = - 1 ;
V_51 -> V_302 = F_91 () - V_235 ;
return 0 ;
V_364:
F_145 ( V_51 ) ;
F_380 ( & V_362 -> V_363 ) ;
return V_205 ;
}
static void F_384 ( struct V_252 * V_48 )
{
struct V_358 * V_359 = V_48 -> V_71 ;
struct V_50 * V_51 = V_359 -> V_72 ;
if ( F_265 ( V_48 ) )
V_51 -> V_52 = 0 ;
}
static T_6
F_385 ( unsigned int V_372 , char * V_373 )
{
return sprintf ( V_373 , L_6 , V_372 ) ;
}
static T_6
F_386 ( unsigned int * V_372 , const char * V_373 , T_7 V_62 )
{
char * V_230 = ( char * ) V_373 ;
* V_372 = F_387 ( V_230 , & V_230 , 10 ) ;
return V_62 ;
}
static int T_10 F_388 ( void )
{
int V_205 ;
#ifdef F_333
V_205 = F_389 ( & V_31 ) ;
if ( V_205 )
return V_205 ;
#else
V_270 = 0 ;
#endif
V_205 = - V_176 ;
V_306 = F_390 ( V_54 , 0 ) ;
if ( ! V_306 )
goto V_374;
V_205 = F_391 ( & V_375 ) ;
if ( V_205 )
goto V_376;
return 0 ;
V_376:
F_392 ( V_306 ) ;
V_374:
#ifdef F_333
F_393 ( & V_31 ) ;
#endif
return V_205 ;
}
static void T_11 F_394 ( void )
{
#ifdef F_333
F_393 ( & V_31 ) ;
#endif
F_395 ( & V_375 ) ;
F_392 ( V_306 ) ;
}
