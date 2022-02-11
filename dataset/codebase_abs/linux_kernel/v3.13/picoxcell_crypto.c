static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 ? F_2 ( V_3 , struct V_1 , V_3 ) : NULL ;
}
static inline int F_3 ( struct V_4 * V_5 )
{
T_1 V_6 = F_4 ( V_5 -> V_7 + V_8 ) ;
return V_6 & V_9 ;
}
static inline void T_2 * F_5 ( struct V_10 * V_11 ,
unsigned V_12 ,
bool V_13 )
{
return V_13 ? V_11 -> V_5 -> V_14 +
( V_12 * V_11 -> V_5 -> V_15 ) :
V_11 -> V_5 -> V_16 + ( V_12 * V_11 -> V_5 -> V_17 ) ;
}
static inline void F_6 ( T_1 T_2 * V_18 , const void * V_19 ,
unsigned V_20 )
{
const T_1 * V_21 = ( const T_1 * ) V_19 ;
while ( V_20 -- )
F_7 ( * V_21 ++ , V_18 ++ ) ;
}
static void F_8 ( struct V_10 * V_11 ,
void T_2 * V_22 , const T_3 * V_23 ,
T_4 V_24 , const T_3 * V_25 , T_4 V_26 )
{
void T_2 * V_27 = V_22 + V_11 -> V_28 ;
void T_2 * V_29 = V_22 + V_11 -> V_30 ;
F_6 ( V_27 , V_23 , V_24 / 4 ) ;
F_6 ( V_29 , V_25 , V_26 / 4 ) ;
}
static unsigned F_9 ( struct V_10 * V_11 ,
const T_3 * V_31 , T_4 V_32 ,
const T_3 * V_25 , T_4 V_33 , const T_3 * V_34 ,
T_4 V_35 )
{
unsigned V_12 = V_11 -> V_5 -> V_36 ++ ;
void T_2 * V_37 , * V_38 ;
V_37 = F_5 ( V_11 , V_12 , 1 ) ;
V_38 = F_5 ( V_11 , V_12 , 0 ) ;
V_11 -> V_5 -> V_36 &= V_11 -> V_5 -> V_39 - 1 ;
F_8 ( V_11 , V_37 , V_31 , V_32 , V_25 ,
V_33 ) ;
F_7 ( V_32 | ( V_12 << V_40 ) |
( 1 << V_41 ) ,
V_11 -> V_5 -> V_7 + V_42 ) ;
if ( V_34 ) {
F_6 ( V_38 , V_34 , V_35 / 4 ) ;
F_7 ( V_35 | ( V_12 << V_40 ) ,
V_11 -> V_5 -> V_7 + V_42 ) ;
}
return V_12 ;
}
static int F_10 ( struct V_43 * V_44 , int V_45 )
{
struct V_43 * V_46 = V_44 ;
int V_47 = 0 ;
while ( V_45 > 0 ) {
++ V_47 ;
V_45 -= V_46 -> V_48 ;
V_46 = F_11 ( V_46 ) ;
}
return V_47 ;
}
static inline void F_12 ( struct V_49 * V_50 , T_5 V_51 , T_4 V_52 )
{
V_50 -> V_53 = V_51 ;
V_50 -> V_52 = V_52 ;
}
static struct V_49 * F_13 ( struct V_4 * V_5 ,
struct V_43 * V_54 ,
unsigned V_45 ,
enum V_55 V_56 ,
T_5 * V_57 )
{
unsigned V_58 , V_59 ;
struct V_43 * V_60 ;
struct V_49 * V_50 ;
int V_61 ;
V_58 = F_10 ( V_54 , V_45 ) ;
V_59 = F_14 ( V_5 -> V_62 , V_54 , V_58 , V_56 ) ;
if ( V_59 + 1 > V_63 )
goto V_64;
V_50 = F_15 ( V_5 -> V_65 , V_66 , V_57 ) ;
if ( ! V_50 )
goto V_64;
F_16 (payload, cur, mapped_ents, i)
F_12 ( & V_50 [ V_61 ] , F_17 ( V_60 ) , F_18 ( V_60 ) ) ;
F_12 ( & V_50 [ V_59 ] , 0 , 0 ) ;
return V_50 ;
V_64:
F_19 ( V_5 -> V_62 , V_54 , V_58 , V_56 ) ;
return NULL ;
}
static int F_20 ( struct V_67 * V_68 , T_3 * V_69 )
{
struct V_70 * V_71 = F_2 ( V_68 -> V_68 , struct V_70 ,
V_72 ) ;
struct V_4 * V_5 = V_68 -> V_5 ;
struct V_49 * V_73 , * V_74 ;
unsigned V_75 = F_21 ( F_22 ( V_71 ) ) ;
unsigned V_58 = F_10 ( V_71 -> V_19 , V_71 -> V_76 ) ;
T_5 V_77 ;
struct V_43 * V_60 ;
int V_61 , V_78 , V_79 , V_80 ;
T_3 * V_25 = V_69 ? V_69 : V_71 -> V_25 ;
V_73 = F_15 ( V_5 -> V_65 , V_66 , & V_68 -> V_81 ) ;
if ( ! V_73 )
return - V_82 ;
V_74 = F_15 ( V_5 -> V_65 , V_66 , & V_68 -> V_83 ) ;
if ( ! V_74 ) {
F_23 ( V_5 -> V_65 , V_73 , V_68 -> V_81 ) ;
return - V_82 ;
}
V_68 -> V_73 = V_73 ;
V_68 -> V_74 = V_74 ;
V_80 = F_14 ( V_5 -> V_62 , V_71 -> V_84 ,
F_10 ( V_71 -> V_84 , V_71 -> V_85 ) , V_86 ) ;
if ( V_71 -> V_19 != V_71 -> V_18 ) {
V_79 = F_14 ( V_5 -> V_62 , V_71 -> V_19 , V_58 ,
V_86 ) ;
V_78 = F_14 ( V_5 -> V_62 , V_71 -> V_18 , V_58 ,
V_87 ) ;
} else {
V_79 = F_14 ( V_5 -> V_62 , V_71 -> V_19 , V_58 ,
V_88 ) ;
V_78 = 0 ;
}
V_77 = F_24 ( V_5 -> V_62 , V_25 , V_75 ,
V_69 ? V_88 : V_86 ) ;
V_68 -> V_89 = V_77 ;
F_16 (areq->assoc, cur, assoc_ents, i) {
F_12 ( V_73 ++ , F_17 ( V_60 ) , F_18 ( V_60 ) ) ;
if ( V_68 -> V_90 )
F_12 ( V_74 ++ , F_17 ( V_60 ) ,
F_18 ( V_60 ) ) ;
}
F_12 ( V_73 ++ , V_77 , V_75 ) ;
if ( V_69 || V_68 -> V_90 )
F_12 ( V_74 ++ , V_77 , V_75 ) ;
F_16 (areq->src, cur, src_ents, i) {
F_12 ( V_73 ++ , F_17 ( V_60 ) , F_18 ( V_60 ) ) ;
if ( V_71 -> V_19 == V_71 -> V_18 )
F_12 ( V_74 ++ , F_17 ( V_60 ) ,
F_18 ( V_60 ) ) ;
}
F_16 (areq->dst, cur, dst_ents, i)
F_12 ( V_74 ++ , F_17 ( V_60 ) ,
F_18 ( V_60 ) ) ;
F_12 ( V_73 , 0 , 0 ) ;
F_12 ( V_74 , 0 , 0 ) ;
return 0 ;
}
static void F_25 ( struct V_67 * V_68 )
{
struct V_70 * V_71 = F_2 ( V_68 -> V_68 , struct V_70 ,
V_72 ) ;
struct V_1 * V_3 = F_1 ( V_68 -> V_68 -> V_91 -> V_92 ) ;
struct V_93 * V_94 = F_26 ( V_68 -> V_68 -> V_91 ) ;
struct V_4 * V_5 = V_94 -> V_95 . V_5 ;
unsigned V_75 = V_3 -> V_3 . V_96 . V_75 ;
unsigned V_58 = F_10 ( V_71 -> V_19 , V_71 -> V_76 ) ;
if ( V_71 -> V_19 != V_71 -> V_18 ) {
F_19 ( V_5 -> V_62 , V_71 -> V_19 , V_58 , V_86 ) ;
F_19 ( V_5 -> V_62 , V_71 -> V_18 ,
F_10 ( V_71 -> V_18 , V_71 -> V_76 ) ,
V_87 ) ;
} else
F_19 ( V_5 -> V_62 , V_71 -> V_19 , V_58 , V_88 ) ;
F_19 ( V_5 -> V_62 , V_71 -> V_84 ,
F_10 ( V_71 -> V_84 , V_71 -> V_85 ) , V_86 ) ;
F_27 ( V_5 -> V_62 , V_68 -> V_89 , V_75 , V_88 ) ;
F_23 ( V_5 -> V_65 , V_68 -> V_73 , V_68 -> V_81 ) ;
F_23 ( V_5 -> V_65 , V_68 -> V_74 , V_68 -> V_83 ) ;
}
static void F_28 ( struct V_67 * V_68 , struct V_49 * V_50 ,
T_5 V_97 , struct V_43 * V_54 ,
unsigned V_45 , enum V_55 V_56 )
{
unsigned V_58 = F_10 ( V_54 , V_45 ) ;
F_19 ( V_68 -> V_5 -> V_62 , V_54 , V_58 , V_56 ) ;
F_23 ( V_68 -> V_5 -> V_65 , V_50 , V_97 ) ;
}
static int F_29 ( struct V_98 * V_99 , const T_3 * V_23 ,
unsigned int V_52 )
{
struct V_100 * V_91 = F_30 ( V_99 ) ;
struct V_101 * V_11 = F_26 ( V_91 ) ;
T_1 V_102 [ V_103 ] ;
if ( F_31 ( ! F_32 ( V_102 , V_23 ) ) &&
( F_33 ( V_99 ) ) & V_104 ) {
V_91 -> V_105 |= V_106 ;
return - V_107 ;
}
memcpy ( V_11 -> V_108 , V_23 , V_52 ) ;
V_11 -> V_109 = V_52 ;
return 0 ;
}
static int F_34 ( struct V_98 * V_99 , const T_3 * V_23 ,
unsigned int V_52 )
{
struct V_100 * V_91 = F_30 ( V_99 ) ;
struct V_101 * V_11 = F_26 ( V_91 ) ;
if ( V_52 != V_110 && V_52 != V_111 ) {
V_11 -> V_112 -> V_72 . V_105 &= ~ V_113 ;
V_11 -> V_112 -> V_72 . V_105 |=
V_91 -> V_105 & V_113 ;
return F_35 ( V_11 -> V_112 , V_23 , V_52 ) ;
}
memcpy ( V_11 -> V_108 , V_23 , V_52 ) ;
V_11 -> V_109 = V_52 ;
return 0 ;
}
static int F_36 ( struct V_98 * V_91 , const T_3 * V_23 ,
unsigned int V_114 )
{
struct V_101 * V_11 = F_37 ( V_91 ) ;
struct V_1 * V_3 = F_1 ( V_91 -> V_72 . V_92 ) ;
struct V_115 V_116 ;
int V_117 = - V_107 ;
if ( F_38 ( & V_116 , V_23 , V_114 ) != 0 )
goto V_118;
if ( V_116 . V_119 > V_120 )
goto V_118;
if ( V_116 . V_121 > sizeof( V_11 -> V_122 ) )
goto V_118;
if ( ( V_3 -> V_123 & V_124 ) ==
V_125 )
V_117 = F_34 ( V_91 , V_116 . V_126 , V_116 . V_119 ) ;
else
V_117 = F_29 ( V_91 , V_116 . V_126 , V_116 . V_119 ) ;
if ( V_117 )
goto V_118;
memcpy ( V_11 -> V_122 , V_116 . V_127 , V_116 . V_121 ) ;
V_11 -> V_128 = V_116 . V_121 ;
return 0 ;
V_118:
F_39 ( V_91 , V_129 ) ;
return - V_107 ;
}
static int F_40 ( struct V_98 * V_91 ,
unsigned int V_130 )
{
struct V_101 * V_11 = F_26 ( F_30 ( V_91 ) ) ;
V_11 -> V_131 = V_130 ;
return 0 ;
}
static int F_41 ( struct V_67 * V_68 )
{
struct V_70 * V_132 ;
struct V_100 * V_91 = V_68 -> V_68 -> V_91 ;
struct V_2 * V_3 = V_68 -> V_68 -> V_91 -> V_92 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_101 * V_11 = F_26 ( V_91 ) ;
V_132 = F_2 ( V_68 -> V_68 , struct V_70 , V_72 ) ;
if ( ( V_1 -> V_123 & V_124 ) ==
V_125 &&
V_11 -> V_109 != V_110 &&
V_11 -> V_109 != V_111 )
return 1 ;
return 0 ;
}
static int F_42 ( struct V_70 * V_68 , unsigned V_133 ,
bool V_90 )
{
struct V_100 * V_134 = F_30 ( F_22 ( V_68 ) ) ;
struct V_101 * V_11 = F_26 ( V_134 ) ;
int V_117 ;
if ( V_11 -> V_112 ) {
F_43 ( V_68 , V_11 -> V_112 ) ;
V_117 = V_90 ? F_44 ( V_68 ) :
F_45 ( V_68 ) ;
F_43 ( V_68 , F_46 ( V_134 ) ) ;
} else
V_117 = - V_107 ;
return V_117 ;
}
static void F_47 ( struct V_67 * V_68 )
{
F_25 ( V_68 ) ;
V_68 -> V_68 -> V_135 ( V_68 -> V_68 , V_68 -> V_136 ) ;
}
static int F_48 ( struct V_67 * V_68 )
{
struct V_100 * V_91 = V_68 -> V_68 -> V_91 ;
struct V_101 * V_11 = F_26 ( V_91 ) ;
struct V_2 * V_3 = V_68 -> V_68 -> V_91 -> V_92 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_11 -> V_95 . V_5 ;
T_1 V_137 , V_138 , V_139 ;
struct V_70 * V_132 =
F_2 ( V_68 -> V_68 , struct V_70 , V_72 ) ;
V_68 -> V_136 = - V_140 ;
V_68 -> V_141 = F_9 ( & V_11 -> V_95 , V_11 -> V_108 ,
V_11 -> V_109 , V_132 -> V_25 , V_3 -> V_96 . V_75 ,
V_11 -> V_122 , V_11 -> V_128 ) ;
F_7 ( V_68 -> V_81 , V_5 -> V_7 + V_142 ) ;
F_7 ( V_68 -> V_83 , V_5 -> V_7 + V_143 ) ;
F_7 ( 0 , V_5 -> V_7 + V_144 ) ;
V_139 = V_132 -> V_85 ;
V_138 = V_132 -> V_76 + V_139 ;
if ( ! V_68 -> V_69 ) {
V_139 += F_21 ( F_22 ( V_132 ) ) ;
V_138 += F_21 ( F_22 ( V_132 ) ) ;
} else
V_138 += V_68 -> V_145 ;
if ( ! V_68 -> V_90 )
V_138 -= V_11 -> V_131 ;
F_7 ( V_138 , V_5 -> V_7 + V_146 ) ;
F_7 ( V_139 , V_5 -> V_7 + V_147 ) ;
F_7 ( V_11 -> V_131 , V_5 -> V_7 + V_148 ) ;
F_7 ( 0 , V_5 -> V_7 + V_149 ) ;
F_7 ( 0 , V_5 -> V_7 + V_150 ) ;
V_137 = V_1 -> V_123 | ( V_68 -> V_141 << V_151 ) |
( 1 << V_152 ) ;
if ( V_68 -> V_90 )
V_137 |= ( 1 << V_153 ) | ( 1 << V_154 ) ;
else
V_137 |= ( 1 << V_155 ) ;
F_49 ( & V_5 -> V_156 , V_157 + V_158 ) ;
F_7 ( V_137 , V_5 -> V_7 + V_159 ) ;
return - V_140 ;
}
static void F_50 ( struct V_4 * V_5 )
{
struct V_67 * V_68 ;
while ( ! F_51 ( & V_5 -> V_160 ) &&
V_5 -> V_161 + 1 <= V_5 -> V_39 ) {
++ V_5 -> V_161 ;
V_68 = F_52 ( & V_5 -> V_160 , struct V_67 ,
V_162 ) ;
F_53 ( & V_68 -> V_162 , & V_5 -> V_163 ) ;
V_68 -> V_136 = F_54 ( V_68 ) ;
}
}
static int F_55 ( struct V_70 * V_68 , T_3 * V_69 ,
unsigned V_133 , bool V_90 )
{
struct V_2 * V_3 = V_68 -> V_72 . V_91 -> V_92 ;
struct V_4 * V_5 = F_1 ( V_3 ) -> V_5 ;
struct V_67 * V_164 = F_56 ( V_68 ) ;
int V_117 = - V_140 ;
unsigned long V_165 ;
unsigned V_75 = F_21 ( F_22 ( V_68 ) ) ;
V_164 -> V_69 = V_69 ;
V_164 -> V_145 = V_75 ;
V_164 -> V_68 = & V_68 -> V_72 ;
V_164 -> V_90 = V_90 ;
V_164 -> V_136 = - V_166 ;
V_164 -> V_5 = V_5 ;
V_164 -> V_135 = F_47 ;
if ( F_31 ( F_41 ( V_164 ) ) )
return F_42 ( V_68 , V_133 , V_90 ) ;
F_20 ( V_164 , V_164 -> V_69 ) ;
V_117 = - V_140 ;
F_57 ( & V_5 -> V_167 , V_165 ) ;
if ( F_31 ( F_3 ( V_5 ) ) ||
V_5 -> V_161 + 1 > V_5 -> V_39 ) {
if ( ! ( V_68 -> V_72 . V_165 & V_168 ) ) {
V_117 = - V_166 ;
F_58 ( & V_5 -> V_167 , V_165 ) ;
goto V_169;
}
F_59 ( & V_164 -> V_162 , & V_5 -> V_160 ) ;
} else {
F_59 ( & V_164 -> V_162 , & V_5 -> V_160 ) ;
F_50 ( V_5 ) ;
}
F_58 ( & V_5 -> V_167 , V_165 ) ;
goto V_64;
V_169:
F_25 ( V_164 ) ;
V_64:
return V_117 ;
}
static int F_60 ( struct V_70 * V_68 )
{
struct V_98 * V_99 = F_22 ( V_68 ) ;
struct V_100 * V_91 = F_30 ( V_99 ) ;
struct V_1 * V_3 = F_1 ( V_91 -> V_92 ) ;
return F_55 ( V_68 , NULL , V_3 -> type , 1 ) ;
}
static int F_61 ( struct V_170 * V_68 )
{
struct V_98 * V_91 = F_62 ( V_68 ) ;
struct V_101 * V_11 = F_37 ( V_91 ) ;
T_4 V_75 = F_21 ( V_91 ) ;
struct V_1 * V_3 = F_1 ( V_91 -> V_72 . V_92 ) ;
unsigned V_52 ;
T_6 V_171 ;
memcpy ( V_68 -> V_71 . V_25 , V_11 -> V_172 , V_75 ) ;
V_52 = V_75 ;
if ( V_75 > sizeof( V_173 ) ) {
memset ( V_68 -> V_69 , 0 , V_75 - sizeof( V_173 ) ) ;
V_52 = sizeof( V_173 ) ;
}
V_171 = F_63 ( V_68 -> V_171 ) ;
memcpy ( V_68 -> V_69 + V_75 - V_52 , & V_171 , V_52 ) ;
return F_55 ( & V_68 -> V_71 , V_68 -> V_69 , V_3 -> type , 1 ) ;
}
static int F_64 ( struct V_70 * V_68 )
{
struct V_98 * V_99 = F_22 ( V_68 ) ;
struct V_100 * V_91 = F_30 ( V_99 ) ;
struct V_1 * V_3 = F_1 ( V_91 -> V_92 ) ;
return F_55 ( V_68 , NULL , V_3 -> type , 0 ) ;
}
static int F_65 ( struct V_100 * V_91 )
{
struct V_101 * V_11 = F_26 ( V_91 ) ;
struct V_2 * V_3 = V_91 -> V_92 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_1 -> V_5 ;
V_11 -> V_95 . V_165 = V_1 -> type ;
V_11 -> V_95 . V_5 = V_5 ;
V_11 -> V_112 = F_66 ( V_3 -> V_174 , 0 ,
V_175 |
V_176 ) ;
if ( F_67 ( V_11 -> V_112 ) ) {
F_68 ( V_5 -> V_62 , L_1 ,
V_3 -> V_174 ) ;
V_11 -> V_112 = NULL ;
}
V_11 -> V_95 . V_28 = V_1 -> V_28 ;
V_11 -> V_95 . V_30 = V_1 -> V_30 ;
F_69 ( V_11 -> V_172 , sizeof( V_11 -> V_172 ) ) ;
V_91 -> V_177 . V_178 = sizeof( struct V_67 ) ;
return 0 ;
}
static void F_70 ( struct V_100 * V_91 )
{
struct V_101 * V_11 = F_26 ( V_91 ) ;
if ( V_11 -> V_112 )
F_71 ( V_11 -> V_112 ) ;
V_11 -> V_112 = NULL ;
}
static int F_72 ( struct V_179 * V_180 , const T_3 * V_23 ,
unsigned int V_52 )
{
struct V_100 * V_91 = F_73 ( V_180 ) ;
struct V_93 * V_11 = F_26 ( V_91 ) ;
T_1 V_102 [ V_103 ] ;
if ( V_52 > V_181 ) {
F_74 ( V_180 , V_129 ) ;
return - V_107 ;
}
if ( F_31 ( ! F_32 ( V_102 , V_23 ) ) &&
( F_75 ( V_180 ) & V_104 ) ) {
V_91 -> V_105 |= V_106 ;
return - V_107 ;
}
memcpy ( V_11 -> V_23 , V_23 , V_52 ) ;
V_11 -> V_24 = V_52 ;
return 0 ;
}
static int F_76 ( struct V_179 * V_180 , const T_3 * V_23 ,
unsigned int V_52 )
{
struct V_100 * V_91 = F_73 ( V_180 ) ;
struct V_93 * V_11 = F_26 ( V_91 ) ;
int V_117 = 0 ;
if ( V_52 > V_120 ) {
F_74 ( V_180 , V_129 ) ;
return - V_107 ;
}
if ( V_52 != V_110 && V_52 != V_111 &&
V_11 -> V_112 ) {
V_11 -> V_112 -> V_72 . V_105 &= ~ V_113 ;
V_11 -> V_112 -> V_72 . V_105 |=
V_180 -> V_72 . V_105 & V_113 ;
V_117 = F_77 ( V_11 -> V_112 , V_23 , V_52 ) ;
if ( V_117 )
goto V_182;
} else if ( V_52 != V_110 && V_52 != V_111 &&
! V_11 -> V_112 )
V_117 = - V_107 ;
memcpy ( V_11 -> V_23 , V_23 , V_52 ) ;
V_11 -> V_24 = V_52 ;
V_182:
if ( V_117 && V_11 -> V_112 ) {
V_91 -> V_105 &= ~ V_183 ;
V_91 -> V_105 |=
V_11 -> V_112 -> V_72 . V_105 & V_183 ;
}
return V_117 ;
}
static int F_78 ( struct V_179 * V_180 ,
const T_3 * V_23 , unsigned int V_52 )
{
struct V_100 * V_91 = F_73 ( V_180 ) ;
struct V_93 * V_11 = F_26 ( V_91 ) ;
int V_117 = 0 ;
if ( V_52 > V_120 ) {
F_74 ( V_180 , V_129 ) ;
V_117 = - V_107 ;
goto V_64;
}
memcpy ( V_11 -> V_23 , V_23 , V_52 ) ;
V_11 -> V_24 = V_52 ;
V_64:
return V_117 ;
}
static int F_79 ( struct V_67 * V_68 )
{
struct V_93 * V_11 ;
struct V_100 * V_91 = V_68 -> V_68 -> V_91 ;
struct V_2 * V_3 = V_68 -> V_68 -> V_91 -> V_92 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
V_11 = F_26 ( V_91 ) ;
return ( V_1 -> V_123 & V_124 ) ==
V_125 &&
V_11 -> V_24 != V_110 &&
V_11 -> V_24 != V_111 ;
}
static void F_80 ( struct V_67 * V_68 )
{
struct V_184 * V_185 =
F_2 ( V_68 -> V_68 , struct V_184 , V_72 ) ;
if ( V_185 -> V_19 != V_185 -> V_18 ) {
F_28 ( V_68 , V_68 -> V_73 , V_68 -> V_81 , V_185 -> V_19 ,
V_185 -> V_45 , V_86 ) ;
F_28 ( V_68 , V_68 -> V_74 , V_68 -> V_83 , V_185 -> V_18 ,
V_185 -> V_45 , V_87 ) ;
} else
F_28 ( V_68 , V_68 -> V_74 , V_68 -> V_83 , V_185 -> V_18 ,
V_185 -> V_45 , V_88 ) ;
V_68 -> V_68 -> V_135 ( V_68 -> V_68 , V_68 -> V_136 ) ;
}
static int F_81 ( struct V_67 * V_68 )
{
struct V_100 * V_91 = V_68 -> V_68 -> V_91 ;
struct V_93 * V_11 = F_26 ( V_91 ) ;
struct V_184 * V_185 = F_82 ( V_68 -> V_68 ) ;
struct V_2 * V_3 = V_68 -> V_68 -> V_91 -> V_92 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_11 -> V_95 . V_5 ;
T_1 V_137 ;
V_68 -> V_141 = F_9 ( & V_11 -> V_95 , V_11 -> V_23 ,
V_11 -> V_24 , V_185 -> V_186 , V_3 -> V_187 . V_75 ,
NULL , 0 ) ;
F_7 ( V_68 -> V_81 , V_5 -> V_7 + V_142 ) ;
F_7 ( V_68 -> V_83 , V_5 -> V_7 + V_143 ) ;
F_7 ( 0 , V_5 -> V_7 + V_144 ) ;
F_7 ( V_185 -> V_45 , V_5 -> V_7 + V_146 ) ;
F_7 ( 0 , V_5 -> V_7 + V_149 ) ;
F_7 ( 0 , V_5 -> V_7 + V_150 ) ;
F_7 ( 0 , V_5 -> V_7 + V_147 ) ;
V_137 = V_1 -> V_123 | ( V_68 -> V_141 << V_151 ) |
( V_68 -> V_90 ? ( 1 << V_153 ) :
( 1 << V_155 ) ) ;
F_49 ( & V_5 -> V_156 , V_157 + V_158 ) ;
F_7 ( V_137 , V_5 -> V_7 + V_159 ) ;
return - V_140 ;
}
static int F_83 ( struct V_184 * V_68 ,
unsigned V_133 , bool V_90 )
{
struct V_100 * V_134 =
F_73 ( F_84 ( V_68 ) ) ;
struct V_93 * V_11 = F_26 ( V_134 ) ;
int V_117 ;
if ( ! V_11 -> V_112 )
return - V_107 ;
F_85 ( V_68 , V_11 -> V_112 ) ;
V_117 = V_90 ? F_86 ( V_68 ) :
F_87 ( V_68 ) ;
F_85 ( V_68 , F_88 ( V_134 ) ) ;
return V_117 ;
}
static int F_89 ( struct V_184 * V_68 , unsigned V_133 ,
bool V_90 )
{
struct V_2 * V_3 = V_68 -> V_72 . V_91 -> V_92 ;
struct V_4 * V_5 = F_1 ( V_3 ) -> V_5 ;
struct V_67 * V_164 = F_90 ( V_68 ) ;
unsigned long V_165 ;
int V_117 = - V_82 ;
V_164 -> V_68 = & V_68 -> V_72 ;
V_164 -> V_90 = V_90 ;
V_164 -> V_5 = V_5 ;
V_164 -> V_135 = F_80 ;
V_164 -> V_136 = - V_140 ;
if ( F_31 ( F_79 ( V_164 ) ) )
return F_83 ( V_68 , V_133 , V_90 ) ;
if ( V_68 -> V_19 != V_68 -> V_18 ) {
V_164 -> V_73 = F_13 ( V_5 , V_68 -> V_19 ,
V_68 -> V_45 , V_86 , & V_164 -> V_81 ) ;
if ( ! V_164 -> V_73 )
goto V_64;
V_164 -> V_74 = F_13 ( V_5 , V_68 -> V_18 ,
V_68 -> V_45 , V_87 , & V_164 -> V_83 ) ;
if ( ! V_164 -> V_74 )
goto V_188;
} else {
V_164 -> V_74 = F_13 ( V_5 , V_68 -> V_18 ,
V_68 -> V_45 , V_88 , & V_164 -> V_83 ) ;
if ( ! V_164 -> V_74 )
goto V_64;
V_164 -> V_73 = NULL ;
V_164 -> V_81 = V_164 -> V_83 ;
}
V_117 = - V_140 ;
F_57 ( & V_5 -> V_167 , V_165 ) ;
if ( F_31 ( F_3 ( V_5 ) ) ||
V_5 -> V_161 + 1 > V_5 -> V_39 ) {
if ( ! ( V_68 -> V_72 . V_165 & V_168 ) ) {
V_117 = - V_166 ;
F_58 ( & V_5 -> V_167 , V_165 ) ;
goto V_169;
}
F_59 ( & V_164 -> V_162 , & V_5 -> V_160 ) ;
} else {
F_59 ( & V_164 -> V_162 , & V_5 -> V_160 ) ;
F_50 ( V_5 ) ;
}
F_58 ( & V_5 -> V_167 , V_165 ) ;
goto V_64;
V_169:
F_28 ( V_164 , V_164 -> V_74 , V_164 -> V_83 , V_68 -> V_18 ,
V_68 -> V_45 , V_68 -> V_19 == V_68 -> V_18 ?
V_88 : V_87 ) ;
V_188:
if ( V_68 -> V_19 != V_68 -> V_18 )
F_28 ( V_164 , V_164 -> V_73 , V_164 -> V_81 ,
V_68 -> V_19 , V_68 -> V_45 , V_86 ) ;
V_64:
return V_117 ;
}
static int F_91 ( struct V_100 * V_91 )
{
struct V_93 * V_11 = F_26 ( V_91 ) ;
struct V_2 * V_3 = V_91 -> V_92 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_1 -> V_5 ;
V_11 -> V_95 . V_165 = V_1 -> type ;
V_11 -> V_95 . V_5 = V_5 ;
if ( V_3 -> V_189 & V_176 ) {
V_11 -> V_112 = F_92 ( V_3 -> V_174 , 0 ,
V_175 | V_176 ) ;
if ( F_67 ( V_11 -> V_112 ) ) {
F_68 ( V_5 -> V_62 , L_1 ,
V_3 -> V_174 ) ;
V_11 -> V_112 = NULL ;
}
}
V_11 -> V_95 . V_28 = V_1 -> V_28 ;
V_11 -> V_95 . V_30 = V_1 -> V_30 ;
V_91 -> V_190 . V_178 = sizeof( struct V_67 ) ;
return 0 ;
}
static void F_93 ( struct V_100 * V_91 )
{
struct V_93 * V_11 = F_26 ( V_91 ) ;
if ( V_11 -> V_112 )
F_94 ( V_11 -> V_112 ) ;
V_11 -> V_112 = NULL ;
}
static int F_95 ( struct V_184 * V_68 )
{
struct V_179 * V_180 = F_84 ( V_68 ) ;
struct V_100 * V_91 = F_73 ( V_180 ) ;
struct V_1 * V_3 = F_1 ( V_91 -> V_92 ) ;
return F_89 ( V_68 , V_3 -> type , 1 ) ;
}
static int F_96 ( struct V_184 * V_68 )
{
struct V_179 * V_180 = F_84 ( V_68 ) ;
struct V_100 * V_91 = F_73 ( V_180 ) ;
struct V_1 * V_3 = F_1 ( V_91 -> V_92 ) ;
return F_89 ( V_68 , V_3 -> type , 0 ) ;
}
static inline int F_97 ( struct V_4 * V_5 )
{
return F_4 ( V_5 -> V_7 + V_8 ) &
V_191 ;
}
static void F_98 ( struct V_4 * V_5 )
{
struct V_67 * V_68 ;
unsigned long V_165 ;
F_57 ( & V_5 -> V_167 , V_165 ) ;
while ( ! F_97 ( V_5 ) ) {
V_68 = F_52 ( & V_5 -> V_163 , struct V_67 ,
V_162 ) ;
F_53 ( & V_68 -> V_162 , & V_5 -> V_192 ) ;
-- V_5 -> V_161 ;
F_7 ( ~ 0 , V_5 -> V_7 + V_193 ) ;
V_68 -> V_136 = ( F_4 ( V_5 -> V_7 + V_194 ) &
V_195 ) >> V_196 ;
if ( F_31 ( V_68 -> V_136 ) ) {
switch ( V_68 -> V_136 ) {
case V_197 :
V_68 -> V_136 = - V_198 ;
break;
case V_199 :
F_68 ( V_5 -> V_62 ,
L_2 ) ;
V_68 -> V_136 = - V_200 ;
break;
case V_201 :
F_68 ( V_5 -> V_62 ,
L_3 ) ;
V_68 -> V_136 = - V_202 ;
break;
}
}
}
F_99 ( & V_5 -> V_135 ) ;
F_58 ( & V_5 -> V_167 , V_165 ) ;
}
static T_7 F_100 ( int V_203 , void * V_62 )
{
struct V_4 * V_5 = (struct V_4 * ) V_62 ;
T_1 V_204 = F_4 ( V_5 -> V_7 + V_205 ) ;
F_7 ( V_204 , V_5 -> V_7 + V_205 ) ;
F_98 ( V_5 ) ;
return V_206 ;
}
static void F_101 ( unsigned long V_207 )
{
struct V_4 * V_5 = (struct V_4 * ) V_207 ;
F_98 ( V_5 ) ;
}
static int F_54 ( struct V_67 * V_68 )
{
struct V_2 * V_3 = V_68 -> V_68 -> V_91 -> V_92 ;
if ( V_208 == ( V_209 & V_3 -> V_189 ) )
return F_48 ( V_68 ) ;
else
return F_81 ( V_68 ) ;
}
static void F_102 ( unsigned long V_207 )
{
struct V_4 * V_5 = (struct V_4 * ) V_207 ;
struct V_67 * V_68 , * V_102 ;
unsigned long V_165 ;
F_103 ( V_192 ) ;
F_57 ( & V_5 -> V_167 , V_165 ) ;
F_104 ( & V_5 -> V_192 , & V_192 ) ;
F_50 ( V_5 ) ;
if ( V_5 -> V_161 )
F_49 ( & V_5 -> V_156 , V_157 + V_158 ) ;
F_58 ( & V_5 -> V_167 , V_165 ) ;
F_105 (req, tmp, &completed, list) {
F_106 ( & V_68 -> V_162 ) ;
V_68 -> V_135 ( V_68 ) ;
}
}
static int F_107 ( struct V_210 * V_62 )
{
struct V_211 * V_212 = F_108 ( V_62 ) ;
struct V_4 * V_5 = F_109 ( V_212 ) ;
F_110 ( V_5 -> V_213 ) ;
return 0 ;
}
static int F_111 ( struct V_210 * V_62 )
{
struct V_211 * V_212 = F_108 ( V_62 ) ;
struct V_4 * V_5 = F_109 ( V_212 ) ;
return F_112 ( V_5 -> V_213 ) ;
}
static inline struct V_4 * F_113 ( struct V_210 * V_62 )
{
return V_62 ? F_109 ( F_108 ( V_62 ) ) : NULL ;
}
static T_8 F_114 ( struct V_210 * V_62 ,
struct V_214 * V_215 ,
char * V_216 )
{
struct V_4 * V_5 = F_113 ( V_62 ) ;
return snprintf ( V_216 , V_217 , L_4 , V_5 -> V_218 ) ;
}
static T_8 F_115 ( struct V_210 * V_62 ,
struct V_214 * V_215 ,
const char * V_216 , T_4 V_52 )
{
struct V_4 * V_5 = F_113 ( V_62 ) ;
unsigned long V_219 ;
if ( F_116 ( V_216 , 0 , & V_219 ) )
return - V_107 ;
V_219 = F_117 ( V_219 , 1UL , V_5 -> V_39 - 1 ) ;
V_5 -> V_218 = V_219 ;
F_7 ( V_5 -> V_218 << V_220 ,
V_5 -> V_7 + V_221 ) ;
return V_52 ;
}
static bool F_118 ( struct V_211 * V_212 ,
const char * V_222 )
{
const struct V_223 * V_224 = F_119 ( V_212 ) ;
if ( V_224 && ! strcmp ( V_224 -> V_225 , V_222 ) )
return true ;
#ifdef F_120
if ( F_121 ( V_212 -> V_62 . V_226 , V_222 ) )
return true ;
#endif
return false ;
}
static int F_122 ( struct V_211 * V_212 )
{
int V_61 , V_117 , V_227 = - V_107 ;
struct V_228 * V_229 , * V_203 ;
struct V_4 * V_5 = F_123 ( & V_212 -> V_62 , sizeof( * V_5 ) ,
V_230 ) ;
if ( ! V_5 )
return - V_82 ;
if ( F_118 ( V_212 , L_5 ) ) {
V_5 -> V_231 = V_232 ;
V_5 -> V_15 = V_233 ;
V_5 -> V_17 = V_234 ;
V_5 -> V_39 = V_235 ;
V_5 -> V_236 = V_237 ;
V_5 -> V_238 = F_124 ( V_237 ) ;
} else if ( F_118 ( V_212 , L_6 ) ) {
V_5 -> V_231 = V_239 ;
V_5 -> V_15 = V_240 ;
V_5 -> V_17 = V_241 ;
V_5 -> V_39 = V_242 ;
V_5 -> V_236 = V_243 ;
V_5 -> V_238 = F_124 ( V_243 ) ;
} else {
return - V_107 ;
}
V_5 -> V_225 = F_125 ( & V_212 -> V_62 ) ;
V_229 = F_126 ( V_212 , V_244 , 0 ) ;
V_203 = F_126 ( V_212 , V_245 , 0 ) ;
if ( ! V_229 || ! V_203 ) {
F_127 ( & V_212 -> V_62 , L_7 ) ;
return - V_246 ;
}
if ( ! F_128 ( & V_212 -> V_62 , V_229 -> V_247 , F_129 ( V_229 ) ,
V_5 -> V_225 ) )
return - V_82 ;
V_5 -> V_7 = F_130 ( & V_212 -> V_62 , V_229 -> V_247 , F_129 ( V_229 ) ) ;
if ( ! V_5 -> V_7 ) {
F_127 ( & V_212 -> V_62 , L_8 ) ;
return - V_82 ;
}
if ( F_131 ( & V_212 -> V_62 , V_203 -> V_247 , F_100 , 0 ,
V_5 -> V_225 , V_5 ) ) {
F_127 ( V_5 -> V_62 , L_9 ) ;
return - V_166 ;
}
V_5 -> V_62 = & V_212 -> V_62 ;
V_5 -> V_14 = V_5 -> V_7 + V_248 ;
V_5 -> V_16 = V_5 -> V_7 + V_249 ;
V_5 -> V_65 = F_132 ( V_5 -> V_225 , V_5 -> V_62 ,
V_63 * sizeof( struct V_49 ) , 8 , V_250 ) ;
if ( ! V_5 -> V_65 )
return - V_82 ;
F_133 ( & V_5 -> V_167 ) ;
V_5 -> V_213 = F_134 ( & V_212 -> V_62 , L_10 ) ;
if ( F_67 ( V_5 -> V_213 ) ) {
F_135 ( & V_212 -> V_62 , L_11 ) ;
F_136 ( & V_212 -> V_62 , & V_251 ) ;
return F_137 ( V_5 -> V_213 ) ;
}
if ( F_112 ( V_5 -> V_213 ) ) {
F_135 ( & V_212 -> V_62 , L_12 ) ;
F_138 ( V_5 -> V_213 ) ;
return - V_202 ;
}
V_117 = F_139 ( & V_212 -> V_62 , & V_251 ) ;
if ( V_117 ) {
F_110 ( V_5 -> V_213 ) ;
F_138 ( V_5 -> V_213 ) ;
return V_117 ;
}
V_5 -> V_218 = ( V_5 -> V_39 / 2 ) ;
F_7 ( V_5 -> V_218 << V_220 ,
V_5 -> V_7 + V_221 ) ;
F_7 ( V_252 | V_253 ,
V_5 -> V_7 + V_254 ) ;
F_140 ( & V_5 -> V_156 , F_101 ,
( unsigned long ) V_5 ) ;
F_141 ( & V_5 -> V_160 ) ;
F_141 ( & V_5 -> V_192 ) ;
F_141 ( & V_5 -> V_163 ) ;
V_5 -> V_161 = 0 ;
F_142 ( & V_5 -> V_135 , F_102 ,
( unsigned long ) V_5 ) ;
F_143 ( V_212 , V_5 ) ;
F_141 ( & V_5 -> V_255 ) ;
for ( V_61 = 0 ; V_61 < V_5 -> V_238 ; ++ V_61 ) {
V_5 -> V_236 [ V_61 ] . V_5 = V_5 ;
V_117 = F_144 ( & V_5 -> V_236 [ V_61 ] . V_3 ) ;
if ( ! V_117 ) {
F_59 ( & V_5 -> V_236 [ V_61 ] . V_256 ,
& V_5 -> V_255 ) ;
V_227 = 0 ;
}
if ( V_117 )
F_127 ( V_5 -> V_62 , L_13 ,
V_5 -> V_236 [ V_61 ] . V_3 . V_174 ) ;
else
F_145 ( V_5 -> V_62 , L_14 ,
V_5 -> V_236 [ V_61 ] . V_3 . V_174 ) ;
}
return V_227 ;
}
static int F_146 ( struct V_211 * V_212 )
{
struct V_1 * V_3 , * V_257 ;
struct V_4 * V_5 = F_109 ( V_212 ) ;
F_147 ( & V_5 -> V_156 ) ;
F_136 ( & V_212 -> V_62 , & V_251 ) ;
F_105 (alg, next, &engine->registered_algs, entry) {
F_106 ( & V_3 -> V_256 ) ;
F_148 ( & V_3 -> V_3 ) ;
}
F_110 ( V_5 -> V_213 ) ;
F_138 ( V_5 -> V_213 ) ;
return 0 ;
}
