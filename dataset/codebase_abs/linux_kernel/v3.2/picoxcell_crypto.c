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
struct V_115 * V_116 = ( void * ) V_23 ;
struct V_117 * V_118 ;
unsigned int V_119 , V_120 ;
int V_121 = - V_107 ;
if ( ! F_38 ( V_116 , V_114 ) )
goto V_122;
if ( V_116 -> V_123 != V_124 )
goto V_122;
if ( F_39 ( V_116 ) < sizeof( * V_118 ) )
goto V_122;
V_118 = F_40 ( V_116 ) ;
V_120 = F_41 ( V_118 -> V_120 ) ;
V_23 += F_42 ( V_116 -> V_125 ) ;
V_114 -= F_42 ( V_116 -> V_125 ) ;
if ( V_114 < V_120 )
goto V_122;
V_119 = V_114 - V_120 ;
if ( V_120 > V_126 )
goto V_122;
if ( ( V_3 -> V_127 & V_128 ) ==
V_129 )
V_121 = F_34 ( V_91 , V_23 + V_119 , V_120 ) ;
else
V_121 = F_29 ( V_91 , V_23 + V_119 , V_120 ) ;
if ( V_121 )
goto V_122;
memcpy ( V_11 -> V_130 , V_23 , V_119 ) ;
V_11 -> V_131 = V_119 ;
return 0 ;
V_122:
F_43 ( V_91 , V_132 ) ;
return - V_107 ;
}
static int F_44 ( struct V_98 * V_91 ,
unsigned int V_133 )
{
struct V_101 * V_11 = F_26 ( F_30 ( V_91 ) ) ;
V_11 -> V_134 = V_133 ;
return 0 ;
}
static int F_45 ( struct V_67 * V_68 )
{
struct V_70 * V_135 ;
struct V_100 * V_91 = V_68 -> V_68 -> V_91 ;
struct V_2 * V_3 = V_68 -> V_68 -> V_91 -> V_92 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_101 * V_11 = F_26 ( V_91 ) ;
V_135 = F_2 ( V_68 -> V_68 , struct V_70 , V_72 ) ;
if ( ( V_1 -> V_127 & V_128 ) ==
V_129 &&
V_11 -> V_109 != V_110 &&
V_11 -> V_109 != V_111 )
return 1 ;
return 0 ;
}
static int F_46 ( struct V_70 * V_68 , unsigned V_136 ,
bool V_90 )
{
struct V_100 * V_137 = F_30 ( F_22 ( V_68 ) ) ;
struct V_101 * V_11 = F_26 ( V_137 ) ;
int V_121 ;
if ( V_11 -> V_112 ) {
F_47 ( V_68 , V_11 -> V_112 ) ;
V_121 = V_90 ? F_48 ( V_68 ) :
F_49 ( V_68 ) ;
F_47 ( V_68 , F_50 ( V_137 ) ) ;
} else
V_121 = - V_107 ;
return V_121 ;
}
static void F_51 ( struct V_67 * V_68 )
{
F_25 ( V_68 ) ;
V_68 -> V_68 -> V_138 ( V_68 -> V_68 , V_68 -> V_139 ) ;
}
static int F_52 ( struct V_67 * V_68 )
{
struct V_100 * V_91 = V_68 -> V_68 -> V_91 ;
struct V_101 * V_11 = F_26 ( V_91 ) ;
struct V_2 * V_3 = V_68 -> V_68 -> V_91 -> V_92 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_11 -> V_95 . V_5 ;
T_1 V_140 , V_141 , V_142 ;
struct V_70 * V_135 =
F_2 ( V_68 -> V_68 , struct V_70 , V_72 ) ;
V_68 -> V_139 = - V_143 ;
V_68 -> V_144 = F_9 ( & V_11 -> V_95 , V_11 -> V_108 ,
V_11 -> V_109 , V_135 -> V_25 , V_3 -> V_96 . V_75 ,
V_11 -> V_130 , V_11 -> V_131 ) ;
F_7 ( V_68 -> V_81 , V_5 -> V_7 + V_145 ) ;
F_7 ( V_68 -> V_83 , V_5 -> V_7 + V_146 ) ;
F_7 ( 0 , V_5 -> V_7 + V_147 ) ;
V_142 = V_135 -> V_85 ;
V_141 = V_135 -> V_76 + V_142 ;
if ( ! V_68 -> V_69 ) {
V_142 += F_21 ( F_22 ( V_135 ) ) ;
V_141 += F_21 ( F_22 ( V_135 ) ) ;
} else
V_141 += V_68 -> V_148 ;
if ( ! V_68 -> V_90 )
V_141 -= V_11 -> V_134 ;
F_7 ( V_141 , V_5 -> V_7 + V_149 ) ;
F_7 ( V_142 , V_5 -> V_7 + V_150 ) ;
F_7 ( V_11 -> V_134 , V_5 -> V_7 + V_151 ) ;
F_7 ( 0 , V_5 -> V_7 + V_152 ) ;
F_7 ( 0 , V_5 -> V_7 + V_153 ) ;
V_140 = V_1 -> V_127 | ( V_68 -> V_144 << V_154 ) |
( 1 << V_155 ) ;
if ( V_68 -> V_90 )
V_140 |= ( 1 << V_156 ) | ( 1 << V_157 ) ;
else
V_140 |= ( 1 << V_158 ) ;
F_53 ( & V_5 -> V_159 , V_160 + V_161 ) ;
F_7 ( V_140 , V_5 -> V_7 + V_162 ) ;
return - V_143 ;
}
static void F_54 ( struct V_4 * V_5 )
{
struct V_67 * V_68 ;
while ( ! F_55 ( & V_5 -> V_163 ) &&
V_5 -> V_164 + 1 <= V_5 -> V_39 ) {
++ V_5 -> V_164 ;
V_68 = F_56 ( & V_5 -> V_163 , struct V_67 ,
V_165 ) ;
F_57 ( & V_68 -> V_165 , & V_5 -> V_166 ) ;
V_68 -> V_139 = F_58 ( V_68 ) ;
}
}
static int F_59 ( struct V_70 * V_68 , T_3 * V_69 ,
unsigned V_136 , bool V_90 )
{
struct V_2 * V_3 = V_68 -> V_72 . V_91 -> V_92 ;
struct V_4 * V_5 = F_1 ( V_3 ) -> V_5 ;
struct V_67 * V_167 = F_60 ( V_68 ) ;
int V_121 = - V_143 ;
unsigned long V_168 ;
unsigned V_75 = F_21 ( F_22 ( V_68 ) ) ;
V_167 -> V_69 = V_69 ;
V_167 -> V_148 = V_75 ;
V_167 -> V_68 = & V_68 -> V_72 ;
V_167 -> V_90 = V_90 ;
V_167 -> V_139 = - V_169 ;
V_167 -> V_5 = V_5 ;
V_167 -> V_138 = F_51 ;
if ( F_31 ( F_45 ( V_167 ) ) )
return F_46 ( V_68 , V_136 , V_90 ) ;
F_20 ( V_167 , V_167 -> V_69 ) ;
V_121 = - V_143 ;
F_61 ( & V_5 -> V_170 , V_168 ) ;
if ( F_31 ( F_3 ( V_5 ) ) ||
V_5 -> V_164 + 1 > V_5 -> V_39 ) {
if ( ! ( V_68 -> V_72 . V_168 & V_171 ) ) {
V_121 = - V_169 ;
F_62 ( & V_5 -> V_170 , V_168 ) ;
goto V_172;
}
F_63 ( & V_167 -> V_165 , & V_5 -> V_163 ) ;
} else {
F_63 ( & V_167 -> V_165 , & V_5 -> V_163 ) ;
F_54 ( V_5 ) ;
}
F_62 ( & V_5 -> V_170 , V_168 ) ;
goto V_64;
V_172:
F_25 ( V_167 ) ;
V_64:
return V_121 ;
}
static int F_64 ( struct V_70 * V_68 )
{
struct V_98 * V_99 = F_22 ( V_68 ) ;
struct V_100 * V_91 = F_30 ( V_99 ) ;
struct V_1 * V_3 = F_1 ( V_91 -> V_92 ) ;
return F_59 ( V_68 , NULL , V_3 -> type , 1 ) ;
}
static int F_65 ( struct V_173 * V_68 )
{
struct V_98 * V_91 = F_66 ( V_68 ) ;
struct V_101 * V_11 = F_37 ( V_91 ) ;
T_4 V_75 = F_21 ( V_91 ) ;
struct V_1 * V_3 = F_1 ( V_91 -> V_72 . V_92 ) ;
unsigned V_52 ;
T_6 V_174 ;
memcpy ( V_68 -> V_71 . V_25 , V_11 -> V_175 , V_75 ) ;
V_52 = V_75 ;
if ( V_75 > sizeof( V_176 ) ) {
memset ( V_68 -> V_69 , 0 , V_75 - sizeof( V_176 ) ) ;
V_52 = sizeof( V_176 ) ;
}
V_174 = F_67 ( V_68 -> V_174 ) ;
memcpy ( V_68 -> V_69 + V_75 - V_52 , & V_174 , V_52 ) ;
return F_59 ( & V_68 -> V_71 , V_68 -> V_69 , V_3 -> type , 1 ) ;
}
static int F_68 ( struct V_70 * V_68 )
{
struct V_98 * V_99 = F_22 ( V_68 ) ;
struct V_100 * V_91 = F_30 ( V_99 ) ;
struct V_1 * V_3 = F_1 ( V_91 -> V_92 ) ;
return F_59 ( V_68 , NULL , V_3 -> type , 0 ) ;
}
static int F_69 ( struct V_100 * V_91 )
{
struct V_101 * V_11 = F_26 ( V_91 ) ;
struct V_2 * V_3 = V_91 -> V_92 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_1 -> V_5 ;
V_11 -> V_95 . V_168 = V_1 -> type ;
V_11 -> V_95 . V_5 = V_5 ;
V_11 -> V_112 = F_70 ( V_3 -> V_177 , 0 ,
V_178 |
V_179 ) ;
if ( F_71 ( V_11 -> V_112 ) ) {
F_72 ( V_5 -> V_62 , L_1 ,
V_3 -> V_177 ) ;
V_11 -> V_112 = NULL ;
}
V_11 -> V_95 . V_28 = V_1 -> V_28 ;
V_11 -> V_95 . V_30 = V_1 -> V_30 ;
F_73 ( V_11 -> V_175 , sizeof( V_11 -> V_175 ) ) ;
V_91 -> V_180 . V_181 = sizeof( struct V_67 ) ;
return 0 ;
}
static void F_74 ( struct V_100 * V_91 )
{
struct V_101 * V_11 = F_26 ( V_91 ) ;
if ( V_11 -> V_112 )
F_75 ( V_11 -> V_112 ) ;
V_11 -> V_112 = NULL ;
}
static int F_76 ( struct V_182 * V_183 , const T_3 * V_23 ,
unsigned int V_52 )
{
struct V_100 * V_91 = F_77 ( V_183 ) ;
struct V_93 * V_11 = F_26 ( V_91 ) ;
T_1 V_102 [ V_103 ] ;
if ( V_52 > V_184 ) {
F_78 ( V_183 , V_132 ) ;
return - V_107 ;
}
if ( F_31 ( ! F_32 ( V_102 , V_23 ) ) &&
( F_79 ( V_183 ) & V_104 ) ) {
V_91 -> V_105 |= V_106 ;
return - V_107 ;
}
memcpy ( V_11 -> V_23 , V_23 , V_52 ) ;
V_11 -> V_24 = V_52 ;
return 0 ;
}
static int F_80 ( struct V_182 * V_183 , const T_3 * V_23 ,
unsigned int V_52 )
{
struct V_100 * V_91 = F_77 ( V_183 ) ;
struct V_93 * V_11 = F_26 ( V_91 ) ;
int V_121 = 0 ;
if ( V_52 > V_126 ) {
F_78 ( V_183 , V_132 ) ;
return - V_107 ;
}
if ( ( V_52 != V_110 || V_52 != V_111 ) &&
V_11 -> V_112 ) {
V_11 -> V_112 -> V_72 . V_105 &= ~ V_113 ;
V_11 -> V_112 -> V_72 . V_105 |=
V_183 -> V_72 . V_105 & V_113 ;
V_121 = F_81 ( V_11 -> V_112 , V_23 , V_52 ) ;
if ( V_121 )
goto V_185;
} else if ( ( V_52 != V_110 || V_52 != V_111 ) &&
! V_11 -> V_112 )
V_121 = - V_107 ;
memcpy ( V_11 -> V_23 , V_23 , V_52 ) ;
V_11 -> V_24 = V_52 ;
V_185:
if ( V_121 && V_11 -> V_112 ) {
V_91 -> V_105 &= ~ V_186 ;
V_91 -> V_105 |=
V_11 -> V_112 -> V_72 . V_105 & V_186 ;
}
return V_121 ;
}
static int F_82 ( struct V_182 * V_183 ,
const T_3 * V_23 , unsigned int V_52 )
{
struct V_100 * V_91 = F_77 ( V_183 ) ;
struct V_93 * V_11 = F_26 ( V_91 ) ;
int V_121 = 0 ;
if ( V_52 > V_126 ) {
F_78 ( V_183 , V_132 ) ;
V_121 = - V_107 ;
goto V_64;
}
memcpy ( V_11 -> V_23 , V_23 , V_52 ) ;
V_11 -> V_24 = V_52 ;
V_64:
return V_121 ;
}
static int F_83 ( struct V_67 * V_68 )
{
struct V_93 * V_11 ;
struct V_100 * V_91 = V_68 -> V_68 -> V_91 ;
struct V_2 * V_3 = V_68 -> V_68 -> V_91 -> V_92 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
V_11 = F_26 ( V_91 ) ;
return ( V_1 -> V_127 & V_128 ) ==
V_129 &&
V_11 -> V_24 != V_110 &&
V_11 -> V_24 != V_111 ;
}
static void F_84 ( struct V_67 * V_68 )
{
struct V_187 * V_188 =
F_2 ( V_68 -> V_68 , struct V_187 , V_72 ) ;
if ( V_188 -> V_19 != V_188 -> V_18 ) {
F_28 ( V_68 , V_68 -> V_73 , V_68 -> V_81 , V_188 -> V_19 ,
V_188 -> V_45 , V_86 ) ;
F_28 ( V_68 , V_68 -> V_74 , V_68 -> V_83 , V_188 -> V_18 ,
V_188 -> V_45 , V_87 ) ;
} else
F_28 ( V_68 , V_68 -> V_74 , V_68 -> V_83 , V_188 -> V_18 ,
V_188 -> V_45 , V_88 ) ;
V_68 -> V_68 -> V_138 ( V_68 -> V_68 , V_68 -> V_139 ) ;
}
static int F_85 ( struct V_67 * V_68 )
{
struct V_100 * V_91 = V_68 -> V_68 -> V_91 ;
struct V_93 * V_11 = F_26 ( V_91 ) ;
struct V_187 * V_188 = F_86 ( V_68 -> V_68 ) ;
struct V_2 * V_3 = V_68 -> V_68 -> V_91 -> V_92 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_11 -> V_95 . V_5 ;
T_1 V_140 ;
V_68 -> V_144 = F_9 ( & V_11 -> V_95 , V_11 -> V_23 ,
V_11 -> V_24 , V_188 -> V_189 , V_3 -> V_190 . V_75 ,
NULL , 0 ) ;
F_7 ( V_68 -> V_81 , V_5 -> V_7 + V_145 ) ;
F_7 ( V_68 -> V_83 , V_5 -> V_7 + V_146 ) ;
F_7 ( 0 , V_5 -> V_7 + V_147 ) ;
F_7 ( V_188 -> V_45 , V_5 -> V_7 + V_149 ) ;
F_7 ( 0 , V_5 -> V_7 + V_152 ) ;
F_7 ( 0 , V_5 -> V_7 + V_153 ) ;
F_7 ( 0 , V_5 -> V_7 + V_150 ) ;
V_140 = V_1 -> V_127 | ( V_68 -> V_144 << V_154 ) |
( V_68 -> V_90 ? ( 1 << V_156 ) :
( 1 << V_158 ) ) ;
F_53 ( & V_5 -> V_159 , V_160 + V_161 ) ;
F_7 ( V_140 , V_5 -> V_7 + V_162 ) ;
return - V_143 ;
}
static int F_87 ( struct V_187 * V_68 ,
unsigned V_136 , bool V_90 )
{
struct V_100 * V_137 =
F_77 ( F_88 ( V_68 ) ) ;
struct V_93 * V_11 = F_26 ( V_137 ) ;
int V_121 ;
if ( ! V_11 -> V_112 )
return - V_107 ;
F_89 ( V_68 , V_11 -> V_112 ) ;
V_121 = V_90 ? F_90 ( V_68 ) :
F_91 ( V_68 ) ;
F_89 ( V_68 , F_92 ( V_137 ) ) ;
return V_121 ;
}
static int F_93 ( struct V_187 * V_68 , unsigned V_136 ,
bool V_90 )
{
struct V_2 * V_3 = V_68 -> V_72 . V_91 -> V_92 ;
struct V_4 * V_5 = F_1 ( V_3 ) -> V_5 ;
struct V_67 * V_167 = F_94 ( V_68 ) ;
unsigned long V_168 ;
int V_121 = - V_82 ;
V_167 -> V_68 = & V_68 -> V_72 ;
V_167 -> V_90 = V_90 ;
V_167 -> V_5 = V_5 ;
V_167 -> V_138 = F_84 ;
V_167 -> V_139 = - V_143 ;
if ( F_31 ( F_83 ( V_167 ) ) )
return F_87 ( V_68 , V_136 , V_90 ) ;
if ( V_68 -> V_19 != V_68 -> V_18 ) {
V_167 -> V_73 = F_13 ( V_5 , V_68 -> V_19 ,
V_68 -> V_45 , V_86 , & V_167 -> V_81 ) ;
if ( ! V_167 -> V_73 )
goto V_64;
V_167 -> V_74 = F_13 ( V_5 , V_68 -> V_18 ,
V_68 -> V_45 , V_87 , & V_167 -> V_83 ) ;
if ( ! V_167 -> V_74 )
goto V_191;
} else {
V_167 -> V_74 = F_13 ( V_5 , V_68 -> V_18 ,
V_68 -> V_45 , V_88 , & V_167 -> V_83 ) ;
if ( ! V_167 -> V_74 )
goto V_64;
V_167 -> V_73 = NULL ;
V_167 -> V_81 = V_167 -> V_83 ;
}
V_121 = - V_143 ;
F_61 ( & V_5 -> V_170 , V_168 ) ;
if ( F_31 ( F_3 ( V_5 ) ) ||
V_5 -> V_164 + 1 > V_5 -> V_39 ) {
if ( ! ( V_68 -> V_72 . V_168 & V_171 ) ) {
V_121 = - V_169 ;
F_62 ( & V_5 -> V_170 , V_168 ) ;
goto V_172;
}
F_63 ( & V_167 -> V_165 , & V_5 -> V_163 ) ;
} else {
F_63 ( & V_167 -> V_165 , & V_5 -> V_163 ) ;
F_54 ( V_5 ) ;
}
F_62 ( & V_5 -> V_170 , V_168 ) ;
goto V_64;
V_172:
F_28 ( V_167 , V_167 -> V_74 , V_167 -> V_83 , V_68 -> V_18 ,
V_68 -> V_45 , V_68 -> V_19 == V_68 -> V_18 ?
V_88 : V_87 ) ;
V_191:
if ( V_68 -> V_19 != V_68 -> V_18 )
F_28 ( V_167 , V_167 -> V_73 , V_167 -> V_81 ,
V_68 -> V_19 , V_68 -> V_45 , V_86 ) ;
V_64:
return V_121 ;
}
static int F_95 ( struct V_100 * V_91 )
{
struct V_93 * V_11 = F_26 ( V_91 ) ;
struct V_2 * V_3 = V_91 -> V_92 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_1 -> V_5 ;
V_11 -> V_95 . V_168 = V_1 -> type ;
V_11 -> V_95 . V_5 = V_5 ;
if ( V_3 -> V_192 & V_179 ) {
V_11 -> V_112 = F_96 ( V_3 -> V_177 , 0 ,
V_178 | V_179 ) ;
if ( F_71 ( V_11 -> V_112 ) ) {
F_72 ( V_5 -> V_62 , L_1 ,
V_3 -> V_177 ) ;
V_11 -> V_112 = NULL ;
}
}
V_11 -> V_95 . V_28 = V_1 -> V_28 ;
V_11 -> V_95 . V_30 = V_1 -> V_30 ;
V_91 -> V_193 . V_181 = sizeof( struct V_67 ) ;
return 0 ;
}
static void F_97 ( struct V_100 * V_91 )
{
struct V_93 * V_11 = F_26 ( V_91 ) ;
if ( V_11 -> V_112 )
F_98 ( V_11 -> V_112 ) ;
V_11 -> V_112 = NULL ;
}
static int F_99 ( struct V_187 * V_68 )
{
struct V_182 * V_183 = F_88 ( V_68 ) ;
struct V_100 * V_91 = F_77 ( V_183 ) ;
struct V_1 * V_3 = F_1 ( V_91 -> V_92 ) ;
return F_93 ( V_68 , V_3 -> type , 1 ) ;
}
static int F_100 ( struct V_187 * V_68 )
{
struct V_182 * V_183 = F_88 ( V_68 ) ;
struct V_100 * V_91 = F_77 ( V_183 ) ;
struct V_1 * V_3 = F_1 ( V_91 -> V_92 ) ;
return F_93 ( V_68 , V_3 -> type , 0 ) ;
}
static inline int F_101 ( struct V_4 * V_5 )
{
return F_4 ( V_5 -> V_7 + V_8 ) &
V_194 ;
}
static void F_102 ( struct V_4 * V_5 )
{
struct V_67 * V_68 ;
unsigned long V_168 ;
F_61 ( & V_5 -> V_170 , V_168 ) ;
while ( ! F_101 ( V_5 ) ) {
V_68 = F_56 ( & V_5 -> V_166 , struct V_67 ,
V_165 ) ;
F_57 ( & V_68 -> V_165 , & V_5 -> V_195 ) ;
-- V_5 -> V_164 ;
F_7 ( ~ 0 , V_5 -> V_7 + V_196 ) ;
V_68 -> V_139 = ( F_4 ( V_5 -> V_7 + V_197 ) &
V_198 ) >> V_199 ;
if ( F_31 ( V_68 -> V_139 ) ) {
switch ( V_68 -> V_139 ) {
case V_200 :
V_68 -> V_139 = - V_201 ;
break;
case V_202 :
F_72 ( V_5 -> V_62 ,
L_2 ) ;
V_68 -> V_139 = - V_203 ;
break;
case V_204 :
F_72 ( V_5 -> V_62 ,
L_3 ) ;
V_68 -> V_139 = - V_205 ;
break;
}
}
}
F_103 ( & V_5 -> V_138 ) ;
F_62 ( & V_5 -> V_170 , V_168 ) ;
}
static T_7 F_104 ( int V_206 , void * V_62 )
{
struct V_4 * V_5 = (struct V_4 * ) V_62 ;
T_1 V_207 = F_4 ( V_5 -> V_7 + V_208 ) ;
F_7 ( V_207 , V_5 -> V_7 + V_208 ) ;
F_102 ( V_5 ) ;
return V_209 ;
}
static void F_105 ( unsigned long V_210 )
{
struct V_4 * V_5 = (struct V_4 * ) V_210 ;
F_102 ( V_5 ) ;
}
static int F_58 ( struct V_67 * V_68 )
{
struct V_2 * V_3 = V_68 -> V_68 -> V_91 -> V_92 ;
if ( V_211 == ( V_212 & V_3 -> V_192 ) )
return F_52 ( V_68 ) ;
else
return F_85 ( V_68 ) ;
}
static void F_106 ( unsigned long V_210 )
{
struct V_4 * V_5 = (struct V_4 * ) V_210 ;
struct V_67 * V_68 , * V_102 ;
unsigned long V_168 ;
F_107 ( V_195 ) ;
F_61 ( & V_5 -> V_170 , V_168 ) ;
F_108 ( & V_5 -> V_195 , & V_195 ) ;
F_54 ( V_5 ) ;
if ( V_5 -> V_164 )
F_53 ( & V_5 -> V_159 , V_160 + V_161 ) ;
F_62 ( & V_5 -> V_170 , V_168 ) ;
F_109 (req, tmp, &completed, list) {
F_110 ( & V_68 -> V_165 ) ;
V_68 -> V_138 ( V_68 ) ;
}
}
static int F_111 ( struct V_213 * V_62 )
{
struct V_214 * V_215 = F_112 ( V_62 ) ;
struct V_4 * V_5 = F_113 ( V_215 ) ;
F_114 ( V_5 -> V_216 ) ;
return 0 ;
}
static int F_115 ( struct V_213 * V_62 )
{
struct V_214 * V_215 = F_112 ( V_62 ) ;
struct V_4 * V_5 = F_113 ( V_215 ) ;
return F_116 ( V_5 -> V_216 ) ;
}
static inline struct V_4 * F_117 ( struct V_213 * V_62 )
{
return V_62 ? F_113 ( F_112 ( V_62 ) ) : NULL ;
}
static T_8 F_118 ( struct V_213 * V_62 ,
struct V_217 * V_218 ,
char * V_219 )
{
struct V_4 * V_5 = F_117 ( V_62 ) ;
return snprintf ( V_219 , V_220 , L_4 , V_5 -> V_221 ) ;
}
static T_8 F_119 ( struct V_213 * V_62 ,
struct V_217 * V_218 ,
const char * V_219 , T_4 V_52 )
{
struct V_4 * V_5 = F_117 ( V_62 ) ;
unsigned long V_222 ;
if ( F_120 ( V_219 , 0 , & V_222 ) )
return - V_107 ;
V_222 = F_121 ( V_222 , 1UL , V_5 -> V_39 - 1 ) ;
V_5 -> V_221 = V_222 ;
F_7 ( V_5 -> V_221 << V_223 ,
V_5 -> V_7 + V_224 ) ;
return V_52 ;
}
static bool F_122 ( struct V_214 * V_215 ,
const char * V_225 )
{
const struct V_226 * V_227 = F_123 ( V_215 ) ;
if ( V_227 && ! strcmp ( V_227 -> V_228 , V_225 ) )
return true ;
#ifdef F_124
if ( F_125 ( V_215 -> V_62 . V_229 , V_225 ) )
return true ;
#endif
return false ;
}
static int T_9 F_126 ( struct V_214 * V_215 )
{
int V_61 , V_121 , V_230 = - V_107 ;
struct V_231 * V_232 , * V_206 ;
struct V_4 * V_5 = F_127 ( & V_215 -> V_62 , sizeof( * V_5 ) ,
V_233 ) ;
if ( ! V_5 )
return - V_82 ;
if ( F_122 ( V_215 , L_5 ) ) {
V_5 -> V_234 = V_235 ;
V_5 -> V_15 = V_236 ;
V_5 -> V_17 = V_237 ;
V_5 -> V_39 = V_238 ;
V_5 -> V_239 = V_240 ;
V_5 -> V_241 = F_128 ( V_240 ) ;
} else if ( F_122 ( V_215 , L_6 ) ) {
V_5 -> V_234 = V_242 ;
V_5 -> V_15 = V_243 ;
V_5 -> V_17 = V_244 ;
V_5 -> V_39 = V_245 ;
V_5 -> V_239 = V_246 ;
V_5 -> V_241 = F_128 ( V_246 ) ;
} else {
return - V_107 ;
}
V_5 -> V_228 = F_129 ( & V_215 -> V_62 ) ;
V_232 = F_130 ( V_215 , V_247 , 0 ) ;
V_206 = F_130 ( V_215 , V_248 , 0 ) ;
if ( ! V_232 || ! V_206 ) {
F_131 ( & V_215 -> V_62 , L_7 ) ;
return - V_249 ;
}
if ( ! F_132 ( & V_215 -> V_62 , V_232 -> V_250 , F_133 ( V_232 ) ,
V_5 -> V_228 ) )
return - V_82 ;
V_5 -> V_7 = F_134 ( & V_215 -> V_62 , V_232 -> V_250 , F_133 ( V_232 ) ) ;
if ( ! V_5 -> V_7 ) {
F_131 ( & V_215 -> V_62 , L_8 ) ;
return - V_82 ;
}
if ( F_135 ( & V_215 -> V_62 , V_206 -> V_250 , F_104 , 0 ,
V_5 -> V_228 , V_5 ) ) {
F_131 ( V_5 -> V_62 , L_9 ) ;
return - V_169 ;
}
V_5 -> V_62 = & V_215 -> V_62 ;
V_5 -> V_14 = V_5 -> V_7 + V_251 ;
V_5 -> V_16 = V_5 -> V_7 + V_252 ;
V_5 -> V_65 = F_136 ( V_5 -> V_228 , V_5 -> V_62 ,
V_63 * sizeof( struct V_49 ) , 8 , V_253 ) ;
if ( ! V_5 -> V_65 )
return - V_82 ;
F_137 ( & V_5 -> V_170 ) ;
V_5 -> V_216 = F_138 ( & V_215 -> V_62 , L_10 ) ;
if ( F_71 ( V_5 -> V_216 ) ) {
F_139 ( & V_215 -> V_62 , L_11 ) ;
F_140 ( & V_215 -> V_62 , & V_254 ) ;
return F_141 ( V_5 -> V_216 ) ;
}
if ( F_116 ( V_5 -> V_216 ) ) {
F_139 ( & V_215 -> V_62 , L_12 ) ;
F_142 ( V_5 -> V_216 ) ;
return - V_205 ;
}
V_121 = F_143 ( & V_215 -> V_62 , & V_254 ) ;
if ( V_121 ) {
F_114 ( V_5 -> V_216 ) ;
F_142 ( V_5 -> V_216 ) ;
return V_121 ;
}
V_5 -> V_221 = ( V_5 -> V_39 / 2 ) ;
F_7 ( V_5 -> V_221 << V_223 ,
V_5 -> V_7 + V_224 ) ;
F_7 ( V_255 | V_256 ,
V_5 -> V_7 + V_257 ) ;
F_144 ( & V_5 -> V_159 , F_105 ,
( unsigned long ) V_5 ) ;
F_145 ( & V_5 -> V_163 ) ;
F_145 ( & V_5 -> V_195 ) ;
F_145 ( & V_5 -> V_166 ) ;
V_5 -> V_164 = 0 ;
F_146 ( & V_5 -> V_138 , F_106 ,
( unsigned long ) V_5 ) ;
F_147 ( V_215 , V_5 ) ;
F_145 ( & V_5 -> V_258 ) ;
for ( V_61 = 0 ; V_61 < V_5 -> V_241 ; ++ V_61 ) {
V_5 -> V_239 [ V_61 ] . V_5 = V_5 ;
V_121 = F_148 ( & V_5 -> V_239 [ V_61 ] . V_3 ) ;
if ( ! V_121 ) {
F_63 ( & V_5 -> V_239 [ V_61 ] . V_259 ,
& V_5 -> V_258 ) ;
V_230 = 0 ;
}
if ( V_121 )
F_131 ( V_5 -> V_62 , L_13 ,
V_5 -> V_239 [ V_61 ] . V_3 . V_177 ) ;
else
F_149 ( V_5 -> V_62 , L_14 ,
V_5 -> V_239 [ V_61 ] . V_3 . V_177 ) ;
}
return V_230 ;
}
static int T_10 F_150 ( struct V_214 * V_215 )
{
struct V_1 * V_3 , * V_260 ;
struct V_4 * V_5 = F_113 ( V_215 ) ;
F_151 ( & V_5 -> V_159 ) ;
F_140 ( & V_215 -> V_62 , & V_254 ) ;
F_109 (alg, next, &engine->registered_algs, entry) {
F_110 ( & V_3 -> V_259 ) ;
F_152 ( & V_3 -> V_3 ) ;
}
F_114 ( V_5 -> V_216 ) ;
F_142 ( V_5 -> V_216 ) ;
return 0 ;
}
static int T_11 F_153 ( void )
{
return F_154 ( & V_261 ) ;
}
static void T_12 F_155 ( void )
{
F_156 ( & V_261 ) ;
}
