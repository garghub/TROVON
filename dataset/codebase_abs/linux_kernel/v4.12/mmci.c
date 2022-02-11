static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 ;
int V_6 = 0 ;
F_3 ( & V_4 -> V_7 , V_5 ) ;
if ( F_4 ( V_4 -> V_8 + V_9 ) & V_4 -> V_10 -> V_11 )
V_6 = 1 ;
F_5 ( & V_4 -> V_7 , V_5 ) ;
return V_6 ;
}
static int F_6 ( struct V_3 * V_4 ,
struct V_12 * V_13 )
{
if ( ! V_13 )
return 0 ;
if ( ! F_7 ( V_13 -> V_14 ) ) {
F_8 ( F_9 ( V_4 -> V_2 ) ,
L_1 , V_13 -> V_14 ) ;
return - V_15 ;
}
return 0 ;
}
static void F_10 ( struct V_3 * V_4 )
{
if ( V_4 -> V_16 < 25000000 )
F_11 ( 30 ) ;
else
F_12 ( 120 ) ;
}
static void F_13 ( struct V_3 * V_4 , T_1 V_17 )
{
if ( V_4 -> V_18 != V_17 ) {
V_4 -> V_18 = V_17 ;
F_14 ( V_17 , V_4 -> V_8 + V_19 ) ;
}
}
static void F_15 ( struct V_3 * V_4 , T_1 V_20 )
{
if ( V_4 -> V_21 != V_20 ) {
V_4 -> V_21 = V_20 ;
F_14 ( V_20 , V_4 -> V_8 + V_22 ) ;
}
}
static void F_16 ( struct V_3 * V_4 , T_1 V_23 )
{
V_23 |= V_4 -> V_24 & V_4 -> V_10 -> V_25 ;
if ( V_4 -> V_24 != V_23 ) {
V_4 -> V_24 = V_23 ;
F_14 ( V_23 , V_4 -> V_8 + V_26 ) ;
}
}
static void F_17 ( struct V_3 * V_4 , unsigned int V_27 )
{
struct V_28 * V_10 = V_4 -> V_10 ;
T_1 V_17 = V_10 -> V_29 ;
V_4 -> V_16 = 0 ;
if ( V_27 ) {
if ( V_10 -> V_30 ) {
V_4 -> V_16 = V_4 -> V_31 ;
} else if ( V_27 >= V_4 -> V_31 ) {
V_17 = V_32 ;
if ( V_10 -> V_33 )
V_17 |= V_34 ;
V_4 -> V_16 = V_4 -> V_31 ;
} else if ( V_10 -> V_33 ) {
V_17 = F_18 ( V_4 -> V_31 , V_27 ) - 2 ;
if ( V_17 >= 256 )
V_17 = 255 ;
V_4 -> V_16 = V_4 -> V_31 / ( V_17 + 2 ) ;
} else {
V_17 = V_4 -> V_31 / ( 2 * V_27 ) - 1 ;
if ( V_17 >= 256 )
V_17 = 255 ;
V_4 -> V_16 = V_4 -> V_31 / ( 2 * ( V_17 + 1 ) ) ;
}
V_17 |= V_10 -> V_35 ;
V_17 |= V_36 ;
}
V_4 -> V_2 -> V_37 = V_4 -> V_16 ;
if ( V_4 -> V_2 -> V_38 . V_39 == V_40 )
V_17 |= V_41 ;
if ( V_4 -> V_2 -> V_38 . V_39 == V_42 )
V_17 |= V_10 -> V_43 ;
if ( V_4 -> V_2 -> V_38 . V_44 == V_45 ||
V_4 -> V_2 -> V_38 . V_44 == V_46 )
V_17 |= V_10 -> V_47 ;
F_13 ( V_4 , V_17 ) ;
}
static void
F_19 ( struct V_3 * V_4 , struct V_48 * V_49 )
{
F_14 ( 0 , V_4 -> V_8 + V_50 ) ;
F_20 ( V_4 -> V_13 ) ;
V_4 -> V_49 = NULL ;
V_4 -> V_51 = NULL ;
F_21 ( V_4 -> V_2 , V_49 ) ;
}
static void F_22 ( struct V_3 * V_4 , unsigned int V_52 )
{
void T_2 * V_8 = V_4 -> V_8 ;
if ( V_4 -> V_53 ) {
unsigned int V_54 = F_4 ( V_8 + V_55 ) ;
V_54 &= ~ V_56 ;
V_54 |= V_52 ;
F_14 ( V_54 , V_8 + V_55 ) ;
}
F_14 ( V_52 , V_8 + V_57 ) ;
}
static void F_23 ( struct V_3 * V_4 )
{
F_16 ( V_4 , 0 ) ;
F_22 ( V_4 , 0 ) ;
V_4 -> V_13 = NULL ;
}
static void F_24 ( struct V_3 * V_4 , struct V_12 * V_13 )
{
unsigned int V_5 = V_58 ;
if ( V_13 -> V_5 & V_59 )
V_5 |= V_60 ;
else
V_5 |= V_61 ;
F_25 ( & V_4 -> V_62 , V_13 -> V_63 , V_13 -> V_64 , V_5 ) ;
}
static void F_26 ( struct V_3 * V_4 )
{
const char * V_65 , * V_66 ;
struct V_28 * V_10 = V_4 -> V_10 ;
V_4 -> V_67 = F_27 ( F_9 ( V_4 -> V_2 ) , L_2 ) ;
V_4 -> V_68 = F_27 ( F_9 ( V_4 -> V_2 ) , L_3 ) ;
V_4 -> V_69 . V_70 = 1 ;
if ( V_4 -> V_67 && ! V_4 -> V_68 )
V_4 -> V_68 = V_4 -> V_67 ;
if ( V_4 -> V_67 )
V_65 = F_28 ( V_4 -> V_67 ) ;
else
V_65 = L_4 ;
if ( V_4 -> V_68 )
V_66 = F_28 ( V_4 -> V_68 ) ;
else
V_66 = L_4 ;
F_29 ( F_9 ( V_4 -> V_2 ) , L_5 ,
V_65 , V_66 ) ;
if ( V_4 -> V_68 ) {
struct V_71 * V_72 = V_4 -> V_68 -> V_71 -> V_72 ;
unsigned int V_73 = F_30 ( V_72 ) ;
if ( V_73 < V_4 -> V_2 -> V_73 )
V_4 -> V_2 -> V_73 = V_73 ;
}
if ( V_4 -> V_67 ) {
struct V_71 * V_72 = V_4 -> V_67 -> V_71 -> V_72 ;
unsigned int V_73 = F_30 ( V_72 ) ;
if ( V_73 < V_4 -> V_2 -> V_73 )
V_4 -> V_2 -> V_73 = V_73 ;
}
if ( V_10 -> V_74 && V_4 -> V_67 && V_4 -> V_68 )
if ( F_31 ( V_4 , V_4 -> V_2 -> V_75 -> V_76 ) )
V_10 -> V_74 = false ;
}
static inline void F_32 ( struct V_3 * V_4 )
{
if ( V_4 -> V_67 )
F_33 ( V_4 -> V_67 ) ;
if ( V_4 -> V_68 )
F_33 ( V_4 -> V_68 ) ;
V_4 -> V_67 = V_4 -> V_68 = NULL ;
}
static void F_34 ( struct V_3 * V_4 )
{
F_8 ( F_9 ( V_4 -> V_2 ) , L_6 ) ;
F_35 ( V_4 -> V_77 ) ;
V_4 -> V_78 = false ;
V_4 -> V_77 = NULL ;
V_4 -> V_79 = NULL ;
V_4 -> V_13 -> V_80 = 0 ;
}
static void F_36 ( struct V_3 * V_4 , struct V_12 * V_13 )
{
struct V_81 * V_82 ;
if ( V_13 -> V_5 & V_59 )
V_82 = V_4 -> V_67 ;
else
V_82 = V_4 -> V_68 ;
F_37 ( V_82 -> V_71 -> V_72 , V_13 -> V_63 , V_13 -> V_64 ,
F_38 ( V_13 ) ) ;
}
static void F_39 ( struct V_3 * V_4 , struct V_12 * V_13 )
{
T_1 V_83 ;
int V_84 ;
for ( V_84 = 0 ; ; V_84 ++ ) {
V_83 = F_4 ( V_4 -> V_8 + V_9 ) ;
if ( ! ( V_83 & V_85 ) || V_84 >= 100 )
break;
F_11 ( 10 ) ;
}
if ( V_83 & V_85 ) {
F_34 ( V_4 ) ;
if ( ! V_13 -> error )
V_13 -> error = - V_86 ;
}
if ( ! V_13 -> V_80 )
F_36 ( V_4 , V_13 ) ;
if ( V_83 & V_85 ) {
F_8 ( F_9 ( V_4 -> V_2 ) , L_7 ) ;
F_32 ( V_4 ) ;
}
V_4 -> V_78 = false ;
V_4 -> V_77 = NULL ;
V_4 -> V_79 = NULL ;
}
static int F_40 ( struct V_3 * V_4 , struct V_12 * V_13 ,
struct V_81 * * V_81 ,
struct V_87 * * V_88 )
{
struct V_28 * V_10 = V_4 -> V_10 ;
struct V_89 V_90 = {
. V_91 = V_4 -> V_92 + V_93 ,
. V_94 = V_4 -> V_92 + V_93 ,
. V_95 = V_96 ,
. V_97 = V_96 ,
. V_98 = V_10 -> V_99 >> 2 ,
. V_100 = V_10 -> V_99 >> 2 ,
. V_101 = false ,
} ;
struct V_81 * V_82 ;
struct V_102 * V_71 ;
struct V_87 * V_103 ;
int V_104 ;
unsigned long V_5 = V_105 ;
if ( V_13 -> V_5 & V_59 ) {
V_90 . V_106 = V_107 ;
V_82 = V_4 -> V_67 ;
} else {
V_90 . V_106 = V_108 ;
V_82 = V_4 -> V_68 ;
}
if ( ! V_82 )
return - V_15 ;
if ( V_13 -> V_14 * V_13 -> V_109 <= V_10 -> V_110 )
return - V_15 ;
V_71 = V_82 -> V_71 ;
V_104 = F_41 ( V_71 -> V_72 , V_13 -> V_63 , V_13 -> V_64 ,
F_38 ( V_13 ) ) ;
if ( V_104 == 0 )
return - V_15 ;
if ( V_4 -> V_10 -> V_74 )
V_5 |= V_111 ;
F_42 ( V_82 , & V_90 ) ;
V_103 = F_43 ( V_82 , V_13 -> V_63 , V_104 ,
V_90 . V_106 , V_5 ) ;
if ( ! V_103 )
goto V_112;
* V_81 = V_82 ;
* V_88 = V_103 ;
return 0 ;
V_112:
F_37 ( V_71 -> V_72 , V_13 -> V_63 , V_13 -> V_64 ,
F_38 ( V_13 ) ) ;
return - V_113 ;
}
static inline int F_44 ( struct V_3 * V_4 ,
struct V_12 * V_13 )
{
if ( V_4 -> V_77 && V_4 -> V_79 )
return 0 ;
return F_40 ( V_4 , V_13 , & V_4 -> V_77 ,
& V_4 -> V_79 ) ;
}
static inline int F_45 ( struct V_3 * V_4 ,
struct V_12 * V_13 )
{
struct V_114 * V_115 = & V_4 -> V_69 ;
return F_40 ( V_4 , V_13 , & V_115 -> V_81 , & V_115 -> V_88 ) ;
}
static int F_46 ( struct V_3 * V_4 , unsigned int V_23 )
{
int V_116 ;
struct V_12 * V_13 = V_4 -> V_13 ;
V_116 = F_44 ( V_4 , V_4 -> V_13 ) ;
if ( V_116 )
return V_116 ;
F_47 ( F_9 ( V_4 -> V_2 ) ,
L_8 ,
V_13 -> V_64 , V_13 -> V_14 , V_13 -> V_109 , V_13 -> V_5 ) ;
V_4 -> V_78 = true ;
F_48 ( V_4 -> V_79 ) ;
F_49 ( V_4 -> V_77 ) ;
if ( V_4 -> V_10 -> V_74 )
F_50 ( V_4 , V_13 ) ;
V_23 |= V_117 ;
F_16 ( V_4 , V_23 ) ;
F_14 ( F_4 ( V_4 -> V_8 + V_55 ) | V_118 ,
V_4 -> V_8 + V_55 ) ;
return 0 ;
}
static void F_51 ( struct V_3 * V_4 , struct V_12 * V_13 )
{
struct V_114 * V_119 = & V_4 -> V_69 ;
F_52 ( V_13 -> V_80 && V_13 -> V_80 != V_119 -> V_70 ) ;
F_52 ( ! V_13 -> V_80 && ( V_119 -> V_88 || V_119 -> V_81 ) ) ;
V_4 -> V_79 = V_119 -> V_88 ;
V_4 -> V_77 = V_119 -> V_81 ;
V_119 -> V_88 = NULL ;
V_119 -> V_81 = NULL ;
}
static void F_53 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_12 * V_13 = V_49 -> V_13 ;
struct V_114 * V_115 = & V_4 -> V_69 ;
if ( ! V_13 )
return;
F_20 ( V_13 -> V_80 ) ;
if ( F_6 ( V_4 , V_13 ) )
return;
if ( ! F_45 ( V_4 , V_13 ) )
V_13 -> V_80 = ++ V_115 -> V_70 < 0 ? 1 : V_115 -> V_70 ;
}
static void F_54 ( struct V_1 * V_2 , struct V_48 * V_49 ,
int V_120 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_12 * V_13 = V_49 -> V_13 ;
if ( ! V_13 || ! V_13 -> V_80 )
return;
F_36 ( V_4 , V_13 ) ;
if ( V_120 ) {
struct V_114 * V_119 = & V_4 -> V_69 ;
struct V_81 * V_82 ;
if ( V_13 -> V_5 & V_59 )
V_82 = V_4 -> V_67 ;
else
V_82 = V_4 -> V_68 ;
F_35 ( V_82 ) ;
if ( V_4 -> V_79 == V_119 -> V_88 )
V_4 -> V_79 = NULL ;
if ( V_4 -> V_77 == V_119 -> V_81 ) {
V_4 -> V_78 = false ;
V_4 -> V_77 = NULL ;
}
V_119 -> V_88 = NULL ;
V_119 -> V_81 = NULL ;
V_13 -> V_80 = 0 ;
}
}
static void F_51 ( struct V_3 * V_4 , struct V_12 * V_13 )
{
}
static inline void F_26 ( struct V_3 * V_4 )
{
}
static inline void F_32 ( struct V_3 * V_4 )
{
}
static inline void F_36 ( struct V_3 * V_4 , struct V_12 * V_13 )
{
}
static inline void F_39 ( struct V_3 * V_4 ,
struct V_12 * V_13 )
{
}
static inline void F_34 ( struct V_3 * V_4 )
{
}
static inline int F_46 ( struct V_3 * V_4 , unsigned int V_23 )
{
return - V_121 ;
}
static void F_55 ( struct V_3 * V_4 , struct V_12 * V_13 )
{
struct V_28 * V_10 = V_4 -> V_10 ;
unsigned int V_23 , V_122 , V_123 ;
unsigned long long V_124 ;
void T_2 * V_8 ;
int V_125 ;
F_56 ( F_9 ( V_4 -> V_2 ) , L_9 ,
V_13 -> V_14 , V_13 -> V_109 , V_13 -> V_5 ) ;
V_4 -> V_13 = V_13 ;
V_4 -> V_126 = V_13 -> V_14 * V_13 -> V_109 ;
V_13 -> V_127 = 0 ;
V_124 = ( unsigned long long ) V_13 -> V_128 * V_4 -> V_16 ;
F_57 ( V_124 , V_129 ) ;
V_122 = V_13 -> V_130 + ( unsigned int ) V_124 ;
V_8 = V_4 -> V_8 ;
F_14 ( V_122 , V_8 + V_131 ) ;
F_14 ( V_4 -> V_126 , V_8 + V_132 ) ;
V_125 = F_58 ( V_13 -> V_14 ) - 1 ;
F_20 ( 1 << V_125 != V_13 -> V_14 ) ;
if ( V_10 -> V_133 )
V_23 = V_134 | ( V_13 -> V_14 << 16 ) ;
else if ( V_10 -> V_135 )
V_23 = V_134 | ( V_13 -> V_14 << 4 ) ;
else
V_23 = V_134 | V_125 << 4 ;
if ( V_13 -> V_5 & V_59 )
V_23 |= V_136 ;
if ( V_4 -> V_2 -> V_137 && F_59 ( V_4 -> V_2 -> V_137 ) ) {
T_1 V_17 ;
V_23 |= V_10 -> V_138 ;
if ( V_10 -> V_139 && V_13 -> V_5 & V_140 &&
( V_4 -> V_126 < 8 ||
( V_4 -> V_126 <= 8 && V_4 -> V_31 > 50000000 ) ) )
V_17 = V_4 -> V_18 & ~ V_10 -> V_35 ;
else
V_17 = V_4 -> V_18 | V_10 -> V_35 ;
F_13 ( V_4 , V_17 ) ;
}
if ( V_4 -> V_2 -> V_38 . V_44 == V_45 ||
V_4 -> V_2 -> V_38 . V_44 == V_46 )
V_23 |= V_10 -> V_141 ;
if ( ! F_46 ( V_4 , V_23 ) )
return;
F_24 ( V_4 , V_13 ) ;
if ( V_13 -> V_5 & V_59 ) {
V_123 = V_142 ;
if ( V_4 -> V_126 < V_10 -> V_99 )
V_123 |= V_85 ;
} else {
V_123 = V_143 ;
}
F_16 ( V_4 , V_23 ) ;
F_14 ( F_4 ( V_8 + V_55 ) & ~ V_118 , V_8 + V_55 ) ;
F_22 ( V_4 , V_123 ) ;
}
static void
F_60 ( struct V_3 * V_4 , struct V_144 * V_51 , T_1 V_145 )
{
void T_2 * V_8 = V_4 -> V_8 ;
F_56 ( F_9 ( V_4 -> V_2 ) , L_10 ,
V_51 -> V_146 , V_51 -> V_147 , V_51 -> V_5 ) ;
if ( F_4 ( V_8 + V_50 ) & V_148 ) {
F_14 ( 0 , V_8 + V_50 ) ;
F_10 ( V_4 ) ;
}
V_145 |= V_51 -> V_146 | V_148 ;
if ( V_51 -> V_5 & V_149 ) {
if ( V_51 -> V_5 & V_150 )
V_145 |= V_151 ;
V_145 |= V_152 ;
}
if ( 0 )
V_145 |= V_153 ;
if ( F_61 ( V_51 ) == V_154 )
V_145 |= V_4 -> V_10 -> V_155 ;
V_4 -> V_51 = V_51 ;
F_14 ( V_51 -> V_147 , V_8 + V_156 ) ;
F_14 ( V_145 , V_8 + V_50 ) ;
}
static void
F_62 ( struct V_3 * V_4 , struct V_12 * V_13 ,
unsigned int V_83 )
{
if ( ! V_13 )
return;
if ( V_83 & ( V_157 | V_158 | V_159 |
V_160 | V_161 ) ) {
T_1 V_162 , V_163 ;
if ( F_63 ( V_4 ) ) {
F_34 ( V_4 ) ;
F_36 ( V_4 , V_13 ) ;
}
V_162 = F_4 ( V_4 -> V_8 + V_164 ) ;
V_163 = V_13 -> V_14 * V_13 -> V_109 - V_162 ;
F_56 ( F_9 ( V_4 -> V_2 ) , L_11 ,
V_83 , V_163 ) ;
if ( V_83 & V_157 ) {
V_163 -= 1 ;
V_13 -> error = - V_165 ;
} else if ( V_83 & V_158 ) {
V_13 -> error = - V_166 ;
} else if ( V_83 & V_159 ) {
V_13 -> error = - V_167 ;
} else if ( V_83 & V_160 ) {
V_13 -> error = - V_86 ;
} else if ( V_83 & V_161 ) {
if ( V_163 > V_4 -> V_10 -> V_110 )
V_163 -= V_4 -> V_10 -> V_110 ;
else
V_163 = 0 ;
V_13 -> error = - V_86 ;
}
V_13 -> V_127 = F_64 ( V_163 , V_13 -> V_14 ) ;
}
if ( V_83 & V_168 )
F_8 ( F_9 ( V_4 -> V_2 ) , L_12 ) ;
if ( V_83 & V_169 || V_13 -> error ) {
if ( F_63 ( V_4 ) )
F_39 ( V_4 , V_13 ) ;
F_23 ( V_4 ) ;
if ( ! V_13 -> error )
V_13 -> V_127 = V_13 -> V_14 * V_13 -> V_109 ;
if ( ! V_13 -> V_170 || V_4 -> V_49 -> V_171 ) {
F_19 ( V_4 , V_13 -> V_49 ) ;
} else {
F_60 ( V_4 , V_13 -> V_170 , 0 ) ;
}
}
}
static void
F_65 ( struct V_3 * V_4 , struct V_144 * V_51 ,
unsigned int V_83 )
{
void T_2 * V_8 = V_4 -> V_8 ;
bool V_171 ;
if ( ! V_51 )
return;
V_171 = ( V_51 == V_4 -> V_49 -> V_171 ) ;
if ( ! ( ( V_83 | V_4 -> V_172 ) &
( V_173 | V_174 | V_175 | V_176 ) ) )
return;
if ( V_4 -> V_10 -> V_177 ) {
bool V_178 = ! ! ( V_51 -> V_5 & V_179 ) ;
if ( V_4 -> V_172 &&
( V_83 & V_4 -> V_10 -> V_11 ) )
return;
if ( ! V_4 -> V_172 && V_178 &&
! ( V_83 & ( V_173 | V_174 ) ) &&
( F_4 ( V_8 + V_9 ) & V_4 -> V_10 -> V_11 ) ) {
F_14 ( V_4 -> V_10 -> V_180 ,
V_4 -> V_8 + V_181 ) ;
F_14 ( F_4 ( V_8 + V_55 ) |
V_4 -> V_10 -> V_180 ,
V_8 + V_55 ) ;
V_4 -> V_172 =
V_83 & ( V_175 | V_176 ) ;
return;
}
if ( V_4 -> V_172 ) {
F_14 ( V_4 -> V_10 -> V_180 ,
V_4 -> V_8 + V_181 ) ;
F_14 ( F_4 ( V_8 + V_55 ) &
~ V_4 -> V_10 -> V_180 ,
V_8 + V_55 ) ;
V_4 -> V_172 = 0 ;
}
}
V_4 -> V_51 = NULL ;
if ( V_83 & V_174 ) {
V_51 -> error = - V_166 ;
} else if ( V_83 & V_173 && V_51 -> V_5 & V_182 ) {
V_51 -> error = - V_165 ;
} else {
V_51 -> V_183 [ 0 ] = F_4 ( V_8 + V_184 ) ;
V_51 -> V_183 [ 1 ] = F_4 ( V_8 + V_185 ) ;
V_51 -> V_183 [ 2 ] = F_4 ( V_8 + V_186 ) ;
V_51 -> V_183 [ 3 ] = F_4 ( V_8 + V_187 ) ;
}
if ( ( ! V_171 && ! V_51 -> V_13 ) || V_51 -> error ) {
if ( V_4 -> V_13 ) {
if ( F_63 ( V_4 ) ) {
F_34 ( V_4 ) ;
F_36 ( V_4 , V_4 -> V_13 ) ;
}
F_23 ( V_4 ) ;
}
F_19 ( V_4 , V_4 -> V_49 ) ;
} else if ( V_171 ) {
F_60 ( V_4 , V_4 -> V_49 -> V_51 , 0 ) ;
} else if ( ! ( V_51 -> V_13 -> V_5 & V_59 ) ) {
F_55 ( V_4 , V_51 -> V_13 ) ;
}
}
static int F_66 ( struct V_3 * V_4 , T_1 V_83 , int V_162 )
{
return V_162 - ( F_4 ( V_4 -> V_8 + V_188 ) << 2 ) ;
}
static int F_67 ( struct V_3 * V_4 , T_1 V_83 , int V_189 )
{
if ( V_83 & V_190 )
return V_4 -> V_10 -> V_99 ;
else if ( V_83 & V_191 )
return 4 ;
return 0 ;
}
static int F_68 ( struct V_3 * V_4 , char * V_192 , unsigned int V_162 )
{
void T_2 * V_8 = V_4 -> V_8 ;
char * V_193 = V_192 ;
T_1 V_83 = F_4 ( V_4 -> V_8 + V_9 ) ;
int V_194 = V_4 -> V_126 ;
do {
int V_195 = V_4 -> V_196 ( V_4 , V_83 , V_194 ) ;
if ( V_195 > V_162 )
V_195 = V_162 ;
if ( V_195 <= 0 )
break;
if ( F_69 ( V_195 & 0x3 ) ) {
if ( V_195 < 4 ) {
unsigned char V_197 [ 4 ] ;
F_70 ( V_8 + V_93 , V_197 , 1 ) ;
memcpy ( V_193 , V_197 , V_195 ) ;
} else {
F_70 ( V_8 + V_93 , V_193 , V_195 >> 2 ) ;
V_195 &= ~ 0x3 ;
}
} else {
F_70 ( V_8 + V_93 , V_193 , V_195 >> 2 ) ;
}
V_193 += V_195 ;
V_162 -= V_195 ;
V_194 -= V_195 ;
if ( V_162 == 0 )
break;
V_83 = F_4 ( V_8 + V_9 ) ;
} while ( V_83 & V_191 );
return V_193 - V_192 ;
}
static int F_71 ( struct V_3 * V_4 , char * V_192 , unsigned int V_162 , T_1 V_83 )
{
struct V_28 * V_10 = V_4 -> V_10 ;
void T_2 * V_8 = V_4 -> V_8 ;
char * V_193 = V_192 ;
do {
unsigned int V_195 , V_198 ;
V_198 = V_83 & V_199 ?
V_10 -> V_110 : V_10 -> V_99 ;
V_195 = F_72 ( V_162 , V_198 ) ;
F_73 ( V_8 + V_93 , V_193 , ( V_195 + 3 ) >> 2 ) ;
V_193 += V_195 ;
V_162 -= V_195 ;
if ( V_162 == 0 )
break;
V_83 = F_4 ( V_8 + V_9 ) ;
} while ( V_83 & V_200 );
return V_193 - V_192 ;
}
static T_3 F_74 ( int V_201 , void * V_202 )
{
struct V_3 * V_4 = V_202 ;
struct V_203 * V_62 = & V_4 -> V_62 ;
struct V_28 * V_10 = V_4 -> V_10 ;
void T_2 * V_8 = V_4 -> V_8 ;
unsigned long V_5 ;
T_1 V_83 ;
V_83 = F_4 ( V_8 + V_9 ) ;
F_56 ( F_9 ( V_4 -> V_2 ) , L_13 , V_83 ) ;
F_75 ( V_5 ) ;
do {
unsigned int V_162 , V_204 ;
char * V_192 ;
if ( ! ( V_83 & ( V_200 | V_191 ) ) )
break;
if ( ! F_76 ( V_62 ) )
break;
V_192 = V_62 -> V_205 ;
V_162 = V_62 -> V_206 ;
V_204 = 0 ;
if ( V_83 & V_207 )
V_204 = F_68 ( V_4 , V_192 , V_162 ) ;
if ( V_83 & V_208 )
V_204 = F_71 ( V_4 , V_192 , V_162 , V_83 ) ;
V_62 -> V_209 = V_204 ;
V_4 -> V_126 -= V_204 ;
V_162 -= V_204 ;
if ( V_162 )
break;
V_83 = F_4 ( V_8 + V_9 ) ;
} while ( 1 );
F_77 ( V_62 ) ;
F_78 ( V_5 ) ;
if ( V_83 & V_207 && V_4 -> V_126 < V_10 -> V_99 )
F_22 ( V_4 , V_85 ) ;
if ( V_4 -> V_126 == 0 ) {
F_22 ( V_4 , 0 ) ;
F_14 ( F_4 ( V_8 + V_55 ) | V_118 , V_8 + V_55 ) ;
}
return V_210 ;
}
static T_3 F_79 ( int V_201 , void * V_202 )
{
struct V_3 * V_4 = V_202 ;
T_1 V_83 ;
int V_116 = 0 ;
F_80 ( & V_4 -> V_7 ) ;
do {
V_83 = F_4 ( V_4 -> V_8 + V_9 ) ;
if ( V_4 -> V_53 ) {
if ( V_83 & F_4 ( V_4 -> V_8 + V_57 ) )
F_74 ( V_201 , V_202 ) ;
V_83 &= ~ V_56 ;
}
V_83 &= F_4 ( V_4 -> V_8 + V_55 ) ;
if ( V_4 -> V_10 -> V_177 )
F_14 ( V_83 & ~ V_4 -> V_10 -> V_180 ,
V_4 -> V_8 + V_181 ) ;
else
F_14 ( V_83 , V_4 -> V_8 + V_181 ) ;
F_56 ( F_9 ( V_4 -> V_2 ) , L_14 , V_83 ) ;
if ( V_4 -> V_10 -> V_211 ) {
F_62 ( V_4 , V_4 -> V_13 , V_83 ) ;
F_65 ( V_4 , V_4 -> V_51 , V_83 ) ;
} else {
F_65 ( V_4 , V_4 -> V_51 , V_83 ) ;
F_62 ( V_4 , V_4 -> V_13 , V_83 ) ;
}
if ( V_4 -> V_10 -> V_177 && V_4 -> V_172 )
V_83 &= ~ V_4 -> V_10 -> V_11 ;
V_116 = 1 ;
} while ( V_83 );
F_81 ( & V_4 -> V_7 ) ;
return F_82 ( V_116 ) ;
}
static void F_83 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 ;
F_52 ( V_4 -> V_49 != NULL ) ;
V_49 -> V_51 -> error = F_6 ( V_4 , V_49 -> V_13 ) ;
if ( V_49 -> V_51 -> error ) {
F_21 ( V_2 , V_49 ) ;
return;
}
F_3 ( & V_4 -> V_7 , V_5 ) ;
V_4 -> V_49 = V_49 ;
if ( V_49 -> V_13 )
F_51 ( V_4 , V_49 -> V_13 ) ;
if ( V_49 -> V_13 && V_49 -> V_13 -> V_5 & V_59 )
F_55 ( V_4 , V_49 -> V_13 ) ;
if ( V_49 -> V_171 )
F_60 ( V_4 , V_49 -> V_171 , 0 ) ;
else
F_60 ( V_4 , V_49 -> V_51 , 0 ) ;
F_5 ( & V_4 -> V_7 , V_5 ) ;
}
static void F_84 ( struct V_1 * V_2 , struct V_212 * V_38 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_28 * V_10 = V_4 -> V_10 ;
T_1 V_20 = 0 ;
unsigned long V_5 ;
int V_116 ;
if ( V_4 -> V_213 -> V_214 &&
V_4 -> V_213 -> V_214 ( F_9 ( V_2 ) , V_38 ) )
F_8 ( F_9 ( V_2 ) , L_15 ) ;
switch ( V_38 -> V_215 ) {
case V_216 :
if ( ! F_85 ( V_2 -> V_217 . V_218 ) )
F_86 ( V_2 , V_2 -> V_217 . V_218 , 0 ) ;
if ( ! F_85 ( V_2 -> V_217 . V_219 ) && V_4 -> V_220 ) {
F_87 ( V_2 -> V_217 . V_219 ) ;
V_4 -> V_220 = false ;
}
break;
case V_221 :
if ( ! F_85 ( V_2 -> V_217 . V_218 ) )
F_86 ( V_2 , V_2 -> V_217 . V_218 , V_38 -> V_222 ) ;
V_20 |= V_10 -> V_223 ;
break;
case V_224 :
if ( ! F_85 ( V_2 -> V_217 . V_219 ) && ! V_4 -> V_220 ) {
V_116 = F_88 ( V_2 -> V_217 . V_219 ) ;
if ( V_116 < 0 )
F_8 ( F_9 ( V_2 ) ,
L_16 ) ;
else
V_4 -> V_220 = true ;
}
V_20 |= V_225 ;
break;
}
if ( V_10 -> V_226 && V_38 -> V_215 != V_216 ) {
V_20 |= V_4 -> V_227 ;
if ( V_38 -> V_39 == V_40 )
V_20 &= ~ V_228 ;
else if ( V_38 -> V_39 == V_229 )
V_20 &= ( ~ V_228 &
~ V_230 &
~ V_231 ) ;
}
if ( V_38 -> V_232 == V_233 ) {
if ( V_4 -> V_234 != V_235 )
V_20 |= V_236 ;
else {
V_20 |= V_237 ;
}
}
if ( ! V_38 -> clock && V_10 -> V_238 )
V_20 &= ~ V_225 ;
if ( V_4 -> V_10 -> V_30 &&
V_38 -> clock != V_4 -> V_239 ) {
V_116 = F_89 ( V_4 -> V_17 , V_38 -> clock ) ;
if ( V_116 < 0 )
F_8 ( F_9 ( V_4 -> V_2 ) ,
L_17 , V_116 ) ;
else
V_4 -> V_31 = F_90 ( V_4 -> V_17 ) ;
}
V_4 -> V_239 = V_38 -> clock ;
F_3 ( & V_4 -> V_7 , V_5 ) ;
F_17 ( V_4 , V_38 -> clock ) ;
F_15 ( V_4 , V_20 ) ;
F_10 ( V_4 ) ;
F_5 ( & V_4 -> V_7 , V_5 ) ;
}
static int F_91 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_240 * V_213 = V_4 -> V_213 ;
unsigned int V_83 = F_92 ( V_2 ) ;
if ( V_83 == - V_121 ) {
if ( ! V_213 -> V_83 )
return 1 ;
V_83 = V_213 -> V_83 ( F_9 ( V_4 -> V_2 ) ) ;
}
return V_83 ;
}
static int F_93 ( struct V_1 * V_2 , struct V_212 * V_38 )
{
int V_116 = 0 ;
if ( ! F_85 ( V_2 -> V_217 . V_219 ) ) {
switch ( V_38 -> V_241 ) {
case V_242 :
V_116 = F_94 ( V_2 -> V_217 . V_219 ,
2700000 , 3600000 ) ;
break;
case V_243 :
V_116 = F_94 ( V_2 -> V_217 . V_219 ,
1700000 , 1950000 ) ;
break;
case V_244 :
V_116 = F_94 ( V_2 -> V_217 . V_219 ,
1100000 , 1300000 ) ;
break;
}
if ( V_116 )
F_95 ( F_9 ( V_2 ) , L_18 ) ;
}
return V_116 ;
}
static int F_96 ( struct V_245 * V_246 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_116 = F_97 ( V_2 ) ;
if ( V_116 )
return V_116 ;
if ( F_98 ( V_246 , L_19 , NULL ) )
V_4 -> V_227 |= V_247 ;
if ( F_98 ( V_246 , L_20 , NULL ) )
V_4 -> V_227 |= V_231 ;
if ( F_98 ( V_246 , L_21 , NULL ) )
V_4 -> V_227 |= V_230 ;
if ( F_98 ( V_246 , L_22 , NULL ) )
V_4 -> V_227 |= V_228 ;
if ( F_98 ( V_246 , L_23 , NULL ) )
V_4 -> V_227 |= V_248 ;
if ( F_98 ( V_246 , L_24 , NULL ) )
V_4 -> V_227 |= V_249 ;
if ( F_98 ( V_246 , L_25 , NULL ) )
V_2 -> V_250 |= V_251 ;
if ( F_98 ( V_246 , L_26 , NULL ) )
V_2 -> V_250 |= V_252 ;
return 0 ;
}
static int F_99 ( struct V_253 * V_72 ,
const struct V_254 * V_255 )
{
struct V_240 * V_213 = V_72 -> V_72 . V_256 ;
struct V_245 * V_246 = V_72 -> V_72 . V_76 ;
struct V_28 * V_10 = V_255 -> V_13 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_116 ;
if ( ! V_213 && ! V_246 ) {
F_8 ( & V_72 -> V_72 , L_27 ) ;
return - V_15 ;
}
if ( ! V_213 ) {
V_213 = F_100 ( & V_72 -> V_72 , sizeof( * V_213 ) , V_257 ) ;
if ( ! V_213 )
return - V_113 ;
}
V_2 = F_101 ( sizeof( struct V_3 ) , & V_72 -> V_72 ) ;
if ( ! V_2 )
return - V_113 ;
V_116 = F_96 ( V_246 , V_2 ) ;
if ( V_116 )
goto V_258;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_234 = F_102 ( V_72 ) ;
V_4 -> V_259 = F_103 ( V_72 ) ;
F_56 ( F_9 ( V_2 ) , L_28 , V_4 -> V_234 ) ;
F_56 ( F_9 ( V_2 ) , L_29 , V_4 -> V_259 ) ;
V_4 -> V_17 = F_104 ( & V_72 -> V_72 , NULL ) ;
if ( F_85 ( V_4 -> V_17 ) ) {
V_116 = F_105 ( V_4 -> V_17 ) ;
goto V_258;
}
V_116 = F_106 ( V_4 -> V_17 ) ;
if ( V_116 )
goto V_258;
if ( V_10 -> V_260 )
V_4 -> V_196 = F_67 ;
else
V_4 -> V_196 = F_66 ;
V_4 -> V_213 = V_213 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_31 = F_90 ( V_4 -> V_17 ) ;
if ( V_4 -> V_31 > V_10 -> V_261 ) {
V_116 = F_89 ( V_4 -> V_17 , V_10 -> V_261 ) ;
if ( V_116 < 0 )
goto V_262;
V_4 -> V_31 = F_90 ( V_4 -> V_17 ) ;
F_56 ( F_9 ( V_2 ) , L_30 ,
V_4 -> V_31 ) ;
}
V_4 -> V_92 = V_72 -> V_263 . V_264 ;
V_4 -> V_8 = F_107 ( & V_72 -> V_72 , & V_72 -> V_263 ) ;
if ( F_85 ( V_4 -> V_8 ) ) {
V_116 = F_105 ( V_4 -> V_8 ) ;
goto V_262;
}
if ( V_10 -> V_33 )
V_2 -> V_265 = F_18 ( V_4 -> V_31 , 257 ) ;
else if ( V_10 -> V_30 )
V_2 -> V_265 = F_108 ( V_4 -> V_17 , 100000 ) ;
else
V_2 -> V_265 = F_18 ( V_4 -> V_31 , 512 ) ;
if ( V_2 -> V_261 )
V_2 -> V_261 = V_10 -> V_30 ?
F_72 ( V_10 -> V_261 , V_2 -> V_261 ) :
F_72 ( V_4 -> V_31 , V_2 -> V_261 ) ;
else
V_2 -> V_261 = V_10 -> V_30 ?
V_266 : F_72 ( V_4 -> V_31 , V_266 ) ;
F_56 ( F_9 ( V_2 ) , L_31 , V_2 -> V_261 ) ;
V_116 = F_109 ( V_2 ) ;
if ( V_116 == - V_267 )
goto V_262;
if ( ! V_2 -> V_268 )
V_2 -> V_268 = V_213 -> V_269 ;
else if ( V_213 -> V_269 )
F_95 ( F_9 ( V_2 ) , L_32 ) ;
if ( ! V_246 ) {
if ( ! V_213 -> V_270 )
V_2 -> V_271 |= V_272 ;
V_2 -> V_271 |= V_273 ;
}
V_2 -> V_250 |= V_274 ;
if ( V_10 -> V_177 ) {
V_275 . V_276 = F_1 ;
if ( V_10 -> V_25 )
F_16 ( V_4 ,
V_4 -> V_10 -> V_25 ) ;
V_2 -> V_250 |= V_277 ;
V_2 -> V_278 = 0 ;
}
V_2 -> V_279 = & V_275 ;
V_2 -> V_280 |= V_281 ;
V_2 -> V_282 = V_283 ;
V_2 -> V_284 = ( 1 << V_10 -> V_285 ) - 1 ;
V_2 -> V_73 = V_2 -> V_284 ;
V_2 -> V_286 = 1 << 11 ;
V_2 -> V_287 = V_2 -> V_284 >> 11 ;
F_110 ( & V_4 -> V_7 ) ;
F_14 ( 0 , V_4 -> V_8 + V_55 ) ;
F_14 ( 0 , V_4 -> V_8 + V_57 ) ;
F_14 ( 0xfff , V_4 -> V_8 + V_181 ) ;
if ( ! V_246 ) {
V_116 = F_111 ( V_2 , L_33 , 0 , false , 0 , NULL ) ;
if ( V_116 < 0 ) {
if ( V_116 == - V_267 )
goto V_262;
else if ( F_112 ( V_213 -> V_288 ) ) {
V_116 = F_113 ( V_2 , V_213 -> V_288 , 0 ) ;
if ( V_116 )
goto V_262;
}
}
V_116 = F_114 ( V_2 , L_34 , 0 , false , 0 , NULL ) ;
if ( V_116 < 0 ) {
if ( V_116 == - V_267 )
goto V_262;
else if ( F_112 ( V_213 -> V_289 ) ) {
V_116 = F_115 ( V_2 , V_213 -> V_289 ) ;
if ( V_116 )
goto V_262;
}
}
}
V_116 = F_116 ( & V_72 -> V_72 , V_72 -> V_201 [ 0 ] , F_79 , V_290 ,
V_291 L_35 , V_4 ) ;
if ( V_116 )
goto V_262;
if ( ! V_72 -> V_201 [ 1 ] )
V_4 -> V_53 = true ;
else {
V_116 = F_116 ( & V_72 -> V_72 , V_72 -> V_201 [ 1 ] , F_74 ,
V_290 , V_291 L_36 , V_4 ) ;
if ( V_116 )
goto V_262;
}
F_14 ( V_292 , V_4 -> V_8 + V_55 ) ;
F_117 ( V_72 , V_2 ) ;
F_29 ( & V_72 -> V_72 , L_37 ,
F_118 ( V_2 ) , F_119 ( V_72 ) , F_102 ( V_72 ) ,
F_103 ( V_72 ) , ( unsigned long long ) V_72 -> V_263 . V_264 ,
V_72 -> V_201 [ 0 ] , V_72 -> V_201 [ 1 ] ) ;
F_26 ( V_4 ) ;
F_120 ( & V_72 -> V_72 , 50 ) ;
F_121 ( & V_72 -> V_72 ) ;
F_122 ( V_2 ) ;
F_123 ( & V_72 -> V_72 ) ;
return 0 ;
V_262:
F_124 ( V_4 -> V_17 ) ;
V_258:
F_125 ( V_2 ) ;
return V_116 ;
}
static int F_126 ( struct V_253 * V_72 )
{
struct V_1 * V_2 = F_127 ( V_72 ) ;
if ( V_2 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_128 ( & V_72 -> V_72 ) ;
F_129 ( V_2 ) ;
F_14 ( 0 , V_4 -> V_8 + V_55 ) ;
F_14 ( 0 , V_4 -> V_8 + V_57 ) ;
F_14 ( 0 , V_4 -> V_8 + V_50 ) ;
F_14 ( 0 , V_4 -> V_8 + V_26 ) ;
F_32 ( V_4 ) ;
F_124 ( V_4 -> V_17 ) ;
F_125 ( V_2 ) ;
}
return 0 ;
}
static void F_130 ( struct V_3 * V_4 )
{
unsigned long V_5 ;
F_3 ( & V_4 -> V_7 , V_5 ) ;
F_14 ( 0 , V_4 -> V_8 + V_55 ) ;
if ( V_4 -> V_10 -> V_293 ) {
F_14 ( 0 , V_4 -> V_8 + V_26 ) ;
F_14 ( 0 , V_4 -> V_8 + V_22 ) ;
F_14 ( 0 , V_4 -> V_8 + V_19 ) ;
}
F_10 ( V_4 ) ;
F_5 ( & V_4 -> V_7 , V_5 ) ;
}
static void F_131 ( struct V_3 * V_4 )
{
unsigned long V_5 ;
F_3 ( & V_4 -> V_7 , V_5 ) ;
if ( V_4 -> V_10 -> V_293 ) {
F_14 ( V_4 -> V_18 , V_4 -> V_8 + V_19 ) ;
F_14 ( V_4 -> V_24 , V_4 -> V_8 + V_26 ) ;
F_14 ( V_4 -> V_21 , V_4 -> V_8 + V_22 ) ;
}
F_14 ( V_292 , V_4 -> V_8 + V_55 ) ;
F_10 ( V_4 ) ;
F_5 ( & V_4 -> V_7 , V_5 ) ;
}
static int F_132 ( struct V_71 * V_72 )
{
struct V_253 * V_294 = F_133 ( V_72 ) ;
struct V_1 * V_2 = F_127 ( V_294 ) ;
if ( V_2 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_134 ( V_72 ) ;
F_130 ( V_4 ) ;
F_124 ( V_4 -> V_17 ) ;
}
return 0 ;
}
static int F_135 ( struct V_71 * V_72 )
{
struct V_253 * V_294 = F_133 ( V_72 ) ;
struct V_1 * V_2 = F_127 ( V_294 ) ;
if ( V_2 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_106 ( V_4 -> V_17 ) ;
F_131 ( V_4 ) ;
F_136 ( V_72 ) ;
}
return 0 ;
}
