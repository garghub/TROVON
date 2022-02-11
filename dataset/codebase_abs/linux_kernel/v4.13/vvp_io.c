static struct V_1 * F_1 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_1 * V_6 ;
V_6 = F_2 ( V_5 , struct V_1 , V_7 ) ;
F_3 ( V_6 == F_4 ( V_3 ) ) ;
return V_6 ;
}
static bool F_5 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_10 * V_10 )
{
struct V_11 * V_12 = F_6 ( V_10 ) ;
struct V_1 * V_6 = F_4 ( V_3 ) ;
bool V_13 = true ;
switch ( V_9 -> V_14 ) {
case V_15 :
case V_16 :
if ( F_7 ( V_12 ) != V_6 -> V_17 ||
F_8 ( V_18 , 0 ) ) {
V_9 -> V_19 = 1 ;
V_9 -> V_20 = 0 ;
V_13 = false ;
}
case V_21 :
default:
break;
}
return V_13 ;
}
static void F_9 ( struct V_22 * V_23 )
{
struct V_10 * V_10 = F_10 ( V_23 ) ;
F_11 ( V_10 ) ;
F_12 ( V_23 ) ;
}
static void F_13 ( struct V_22 * V_23 )
{
struct V_10 * V_10 = F_10 ( V_23 ) ;
F_14 ( V_23 ) ;
F_15 ( V_10 ) ;
}
static int F_16 ( const struct V_2 * V_3 , struct V_22 * V_23 ,
struct V_8 * V_9 , T_1 V_24 , T_2 V_25 ,
int * V_26 )
{
struct V_27 * V_28 = F_17 ( V_3 ) ;
struct V_10 * V_10 = F_10 ( V_23 ) ;
T_1 V_29 = V_24 + V_25 - 1 ;
T_1 V_30 ;
int V_31 ;
F_9 ( V_23 ) ;
V_31 = F_18 ( V_3 , V_23 , V_28 ) ;
if ( V_31 == 0 ) {
V_30 = V_28 -> V_32 ;
if ( V_29 > V_30 ) {
F_13 ( V_23 ) ;
V_31 = F_19 ( V_3 , V_9 , V_10 , V_23 , 0 ) ;
if ( V_31 == 0 && V_26 ) {
T_1 V_33 = F_20 ( V_10 ) ;
T_1 V_34 = V_24 >> V_35 ;
T_1 V_36 = ( V_33 - 1 ) >> V_35 ;
if ( ( V_33 == 0 && V_34 != 0 ) ||
V_36 < V_34 )
* V_26 = 1 ;
}
return V_31 ;
}
if ( F_20 ( V_10 ) < V_30 ) {
F_21 ( V_10 , V_30 ) ;
F_22 ( V_37 , V_38 L_1 ,
F_23 ( F_24 ( & V_23 -> V_39 ) ) ,
( V_40 ) F_20 ( V_10 ) ) ;
}
}
F_13 ( V_23 ) ;
return V_31 ;
}
static int F_25 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
T_3 V_41 , enum V_42 V_43 ,
T_4 V_24 , T_4 V_44 )
{
struct V_1 * V_6 = F_4 ( V_3 ) ;
struct V_45 * V_46 = & V_6 -> V_47 . V_48 ;
struct V_22 * V_23 = V_9 -> V_49 ;
F_26 ( V_3 , V_23 , F_27 ( V_23 ) ) ;
F_22 ( V_37 , L_2 , V_43 , V_24 , V_44 ) ;
memset ( & V_6 -> V_47 , 0 , sizeof( V_6 -> V_47 ) ) ;
if ( V_6 -> V_50 && ( V_6 -> V_50 -> V_51 & V_52 ) ) {
V_46 -> V_53 = V_54 ;
V_46 -> V_55 = V_6 -> V_50 -> V_56 . V_57 ;
V_41 |= V_58 ;
} else {
V_46 -> V_53 = V_43 ;
}
V_46 -> V_59 = V_23 ;
V_46 -> V_60 = V_24 ;
V_46 -> V_61 = V_44 ;
V_46 -> V_62 = V_41 ;
F_28 ( V_3 , V_9 , & V_6 -> V_47 ) ;
return 0 ;
}
static int F_29 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
T_3 V_41 , enum V_42 V_43 ,
T_1 V_24 , T_1 V_44 )
{
struct V_22 * V_23 = V_9 -> V_49 ;
return F_25 ( V_3 , V_9 , V_41 , V_43 ,
F_30 ( V_23 , V_24 ) , F_30 ( V_23 , V_44 ) ) ;
}
static int F_31 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
struct V_1 * V_6 = F_1 ( V_3 , V_63 ) ;
F_32 ( & V_6 -> V_64 . V_65 . V_66 ) ;
V_6 -> V_64 . V_65 . V_67 = 0 ;
V_6 -> V_64 . V_65 . V_68 = 0 ;
V_6 -> V_64 . V_65 . V_69 = V_70 ;
return 0 ;
}
static void F_33 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
struct V_1 * V_6 = F_1 ( V_3 , V_63 ) ;
F_3 ( V_6 -> V_64 . V_65 . V_66 . V_71 == 0 ) ;
}
static int F_34 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
struct V_1 * V_6 = F_1 ( V_3 , V_63 ) ;
struct V_10 * V_10 = F_10 ( V_63 -> V_72 ) ;
F_3 ( V_10 == F_35 ( V_6 -> V_50 -> V_73 ) ) ;
V_6 -> V_64 . V_74 . V_75 = V_10 -> V_76 . V_77 ;
return 0 ;
}
static void F_36 ( const struct V_2 * V_3 , const struct V_4 * V_63 )
{
struct V_8 * V_9 = V_63 -> V_78 ;
struct V_22 * V_23 = V_9 -> V_49 ;
struct V_1 * V_6 = F_1 ( V_3 , V_63 ) ;
struct V_10 * V_10 = F_10 ( V_23 ) ;
F_26 ( V_3 , V_23 , F_27 ( V_23 ) ) ;
F_22 ( V_37 , V_38
L_3 ,
F_23 ( F_24 ( & V_23 -> V_39 ) ) ,
V_9 -> V_79 , V_9 -> V_80 ,
V_6 -> V_17 , V_9 -> V_81 ) ;
if ( V_9 -> V_81 ) {
int V_13 ;
V_13 = F_37 ( V_10 , 0 , V_82 ) ;
if ( V_13 == 0 ) {
V_9 -> V_81 = 0 ;
V_9 -> V_19 = 1 ;
V_9 -> V_80 = 1 ;
} else {
V_9 -> V_81 = 1 ;
V_9 -> V_19 = 0 ;
V_9 -> V_80 = 0 ;
V_9 -> V_83 = V_13 ;
}
}
if ( ! V_9 -> V_79 && V_9 -> V_80 ) {
T_3 V_84 = 0 ;
F_38 ( V_10 , & V_84 ) ;
V_9 -> V_19 = V_6 -> V_17 != V_84 ;
if ( V_9 -> V_19 ) {
F_22 ( V_37 ,
V_38 L_4 ,
F_23 ( F_24 ( & V_23 -> V_39 ) ) ,
V_6 -> V_17 , V_84 ) ;
F_39 ( V_85 ,
& F_6 ( V_10 ) -> V_86 ) ;
}
}
}
static void F_40 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
struct V_8 * V_9 = V_63 -> V_78 ;
struct V_87 * V_88 = V_9 -> V_64 . V_89 . V_90 ;
F_26 ( V_3 , V_9 -> V_49 , F_27 ( V_9 -> V_49 ) ) ;
if ( V_88 ) {
F_41 ( & V_88 -> V_91 , L_5 , V_9 ) ;
F_42 ( V_3 , V_88 ) ;
V_9 -> V_64 . V_89 . V_90 = NULL ;
}
F_36 ( V_3 , V_63 ) ;
}
static enum V_42 F_43 ( struct V_92 * V_93 )
{
if ( ( V_93 -> V_94 & V_95 ) && ( V_93 -> V_94 & V_96 ) )
return V_97 ;
return V_98 ;
}
static int F_44 ( const struct V_2 * V_3 ,
struct V_1 * V_6 , struct V_8 * V_9 )
{
struct V_99 * V_100 = F_45 ( V_3 ) ;
struct V_101 * V_102 = V_103 -> V_102 ;
struct V_92 * V_93 ;
struct V_45 * V_46 = & V_100 -> V_104 ;
union V_105 V_106 ;
unsigned long V_107 ;
T_5 V_25 ;
int V_31 = 0 ;
struct V_108 V_109 ;
struct V_110 V_111 ;
F_3 ( V_9 -> V_14 == V_15 || V_9 -> V_14 == V_16 ) ;
if ( ! V_6 -> V_112 )
return 0 ;
if ( ! V_102 )
return 0 ;
F_46 (iov, i, *vio->vui_iter) {
V_107 = ( unsigned long ) V_111 . V_113 ;
V_25 = V_111 . V_114 ;
if ( V_25 == 0 )
continue;
V_25 += V_107 & ( ~ V_115 ) ;
V_107 &= V_115 ;
F_47 ( & V_102 -> V_116 ) ;
while ( ( V_93 = F_48 ( V_102 , V_107 , V_25 ) ) != NULL ) {
struct V_10 * V_10 = F_35 ( V_93 -> V_117 ) ;
int V_118 = V_119 ;
if ( F_49 ( V_93 -> V_117 ) ) {
V_31 = - V_120 ;
break;
}
F_50 ( & V_106 , V_93 , V_107 , V_25 ) ;
V_46 -> V_53 = F_43 ( V_93 ) ;
V_46 -> V_59 = F_6 ( V_10 ) -> V_121 ;
V_46 -> V_60 = F_30 ( V_46 -> V_59 ,
V_106 . V_122 . V_24 ) ;
V_46 -> V_61 = F_30 ( V_46 -> V_59 ,
V_106 . V_122 . V_44 ) ;
V_46 -> V_62 = V_118 ;
V_31 = F_51 ( V_3 , V_9 , V_46 ) ;
F_22 ( V_37 , L_6 ,
V_46 -> V_53 , V_46 -> V_60 ,
V_46 -> V_61 ) ;
if ( V_31 < 0 )
break;
if ( V_93 -> V_123 - V_107 >= V_25 )
break;
V_25 -= V_93 -> V_123 - V_107 ;
V_107 = V_93 -> V_123 ;
}
F_52 ( & V_102 -> V_116 ) ;
if ( V_31 < 0 )
break;
}
return V_31 ;
}
static void F_53 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 ,
T_2 V_124 )
{
struct V_22 * V_23 = V_63 -> V_78 -> V_49 ;
struct V_1 * V_6 = F_1 ( V_3 , V_63 ) ;
F_26 ( V_3 , V_23 , F_27 ( V_23 ) ) ;
V_6 -> V_125 -= V_124 ;
F_54 ( V_6 -> V_112 , V_6 -> V_125 ) ;
}
static void F_55 ( const struct V_2 * V_3 ,
struct V_1 * V_6 , struct V_8 * V_9 )
{
T_2 V_33 = V_9 -> V_64 . V_126 . V_127 ;
if ( ! V_6 -> V_112 )
return;
F_56 ( V_6 -> V_112 , V_33 ) ;
}
static int F_57 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
enum V_42 V_43 , T_1 V_24 , T_1 V_44 )
{
struct V_1 * V_6 = F_4 ( V_3 ) ;
int V_31 ;
int V_128 = 0 ;
F_3 ( V_9 -> V_14 == V_15 || V_9 -> V_14 == V_16 ) ;
F_55 ( V_3 , V_6 , V_9 ) ;
if ( V_9 -> V_64 . V_126 . V_129 )
V_128 |= V_130 ;
V_31 = F_44 ( V_3 , V_6 , V_9 ) ;
if ( V_31 == 0 )
V_31 = F_29 ( V_3 , V_9 , V_128 , V_43 , V_24 , V_44 ) ;
return V_31 ;
}
static int F_58 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
struct V_8 * V_9 = V_63 -> V_78 ;
struct V_131 * V_132 = & V_9 -> V_64 . V_133 . V_132 ;
int V_31 ;
V_31 = F_57 ( V_3 , V_9 , V_98 , V_132 -> V_134 ,
V_132 -> V_134 + V_132 -> V_127 - 1 ) ;
return V_31 ;
}
static int F_59 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
struct V_8 * V_9 = V_63 -> V_78 ;
struct V_1 * V_6 = F_1 ( V_3 , V_63 ) ;
return F_25 ( V_3 ,
V_9 , 0 ,
F_43 ( V_6 -> V_64 . V_74 . V_135 ) ,
V_9 -> V_64 . V_89 . V_136 ,
V_9 -> V_64 . V_89 . V_136 ) ;
}
static int F_60 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
struct V_8 * V_9 = V_63 -> V_78 ;
T_1 V_24 ;
T_1 V_44 ;
if ( V_9 -> V_64 . V_137 . V_138 ) {
V_24 = 0 ;
V_44 = V_82 ;
} else {
V_24 = V_9 -> V_64 . V_137 . V_139 . V_134 ;
V_44 = V_24 + V_9 -> V_64 . V_137 . V_139 . V_127 - 1 ;
}
return F_57 ( V_3 , V_9 , V_97 , V_24 , V_44 ) ;
}
static int F_61 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
return 0 ;
}
static int F_62 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
struct V_8 * V_9 = V_63 -> V_78 ;
V_40 V_140 ;
T_3 V_41 = 0 ;
if ( F_63 ( V_9 ) ) {
V_140 = V_9 -> V_64 . V_141 . V_142 . V_143 ;
if ( V_140 == 0 )
V_41 = V_144 ;
} else {
unsigned int V_145 = V_9 -> V_64 . V_141 . V_146 ;
if ( ! ( V_145 & V_147 ) )
return 0 ;
if ( ( ! ( V_145 & V_148 ) ||
V_9 -> V_64 . V_141 . V_142 . V_149 >=
V_9 -> V_64 . V_141 . V_142 . V_150 ) &&
( ! ( V_145 & V_151 ) ||
V_9 -> V_64 . V_141 . V_142 . V_152 >=
V_9 -> V_64 . V_141 . V_142 . V_150 ) )
return 0 ;
V_140 = 0 ;
}
return F_29 ( V_3 , V_9 , V_41 , V_97 ,
V_140 , V_82 ) ;
}
static int F_64 ( struct V_10 * V_10 , T_2 V_33 )
{
int V_31 ;
F_11 ( V_10 ) ;
V_31 = F_65 ( V_10 , V_33 ) ;
if ( V_31 < 0 ) {
F_15 ( V_10 ) ;
return V_31 ;
}
F_66 ( V_10 , V_33 ) ;
F_15 ( V_10 ) ;
return V_31 ;
}
static int F_67 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
struct V_8 * V_9 = V_63 -> V_78 ;
struct V_22 * V_23 = V_9 -> V_49 ;
struct V_27 * V_28 = F_17 ( V_3 ) ;
int V_31 ;
unsigned V_145 = V_153 ;
F_12 ( V_23 ) ;
V_28 -> V_154 = V_9 -> V_64 . V_141 . V_142 . V_150 ;
if ( V_9 -> V_64 . V_141 . V_146 & V_155 ) {
V_28 -> V_156 = V_9 -> V_64 . V_141 . V_142 . V_152 ;
V_145 |= V_157 ;
}
if ( V_9 -> V_64 . V_141 . V_146 & V_158 ) {
V_28 -> V_159 = V_9 -> V_64 . V_141 . V_142 . V_149 ;
V_145 |= V_160 ;
}
V_31 = F_68 ( V_3 , V_23 , V_28 , V_145 ) ;
F_14 ( V_23 ) ;
return V_31 ;
}
static int F_69 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
struct V_8 * V_9 = V_63 -> V_78 ;
struct V_10 * V_10 = F_10 ( V_9 -> V_49 ) ;
struct V_11 * V_12 = F_6 ( V_10 ) ;
if ( F_63 ( V_9 ) ) {
F_70 ( & V_12 -> V_161 ) ;
F_71 ( V_10 ) ;
F_72 ( V_10 ) ;
} else {
F_71 ( V_10 ) ;
}
if ( V_9 -> V_64 . V_141 . V_146 & V_147 )
return F_67 ( V_3 , V_63 ) ;
return 0 ;
}
static void F_73 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
struct V_8 * V_9 = V_63 -> V_78 ;
struct V_10 * V_10 = F_10 ( V_9 -> V_49 ) ;
struct V_11 * V_12 = F_6 ( V_10 ) ;
if ( F_63 ( V_9 ) ) {
F_64 ( V_10 , V_9 -> V_64 . V_141 . V_142 . V_143 ) ;
F_74 ( V_10 ) ;
F_75 ( & V_12 -> V_161 ) ;
} else {
F_74 ( V_10 ) ;
}
}
static void F_76 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
bool V_162 = V_63 -> V_78 -> V_81 ;
struct V_10 * V_10 = F_10 ( V_63 -> V_72 ) ;
F_36 ( V_3 , V_63 ) ;
if ( V_162 && ! V_63 -> V_78 -> V_81 ) {
F_77 ( V_163 , & ( F_6 ( V_10 ) ) -> V_86 ) ;
}
}
static int F_78 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
struct V_1 * V_6 = F_1 ( V_3 , V_63 ) ;
struct V_8 * V_9 = V_63 -> V_78 ;
struct V_22 * V_23 = V_9 -> V_49 ;
struct V_10 * V_10 = F_10 ( V_23 ) ;
struct V_11 * V_12 = F_6 ( V_10 ) ;
struct V_164 * V_164 = V_6 -> V_50 -> V_73 ;
int V_31 ;
T_1 V_29 = V_9 -> V_64 . V_133 . V_132 . V_134 ;
long V_165 = V_9 -> V_64 . V_133 . V_132 . V_127 ;
long V_166 = V_6 -> V_125 ;
int V_26 = 0 ;
F_26 ( V_3 , V_23 , F_27 ( V_23 ) ) ;
F_22 ( V_37 , L_7 , V_29 , V_29 + V_165 ) ;
F_47 ( & V_12 -> V_161 ) ;
if ( ! F_5 ( V_3 , V_9 , V_10 ) )
return 0 ;
V_31 = F_16 ( V_3 , V_23 , V_9 , V_29 , V_166 , & V_26 ) ;
if ( V_31 != 0 )
return V_31 ;
else if ( V_26 != 0 )
goto V_167;
F_79 ( V_168 , V_3 , & V_23 -> V_39 ,
L_8 ,
V_10 -> V_169 , V_165 , V_29 , F_20 ( V_10 ) ) ;
V_6 -> V_50 -> V_73 -> V_170 . V_171 = 0 ;
if ( ! V_6 -> V_172 ) {
V_6 -> V_172 = true ;
V_6 -> V_173 = F_30 ( V_23 , V_29 ) ;
V_6 -> V_174 = F_30 ( V_23 , V_166 + V_70 - 1 ) ;
F_80 ( V_164 ) ;
}
F_81 ( V_164 ) ;
F_3 ( V_6 -> V_175 -> V_176 == V_29 ) ;
V_31 = F_82 ( V_6 -> V_175 , V_6 -> V_112 ) ;
V_167:
if ( V_31 >= 0 ) {
if ( V_31 < V_165 )
V_9 -> V_20 = 0 ;
V_9 -> V_177 += V_31 ;
F_83 ( F_84 ( V_10 ) , V_103 -> V_178 ,
V_6 -> V_50 , V_29 , V_31 , V_179 ) ;
V_31 = 0 ;
}
return V_31 ;
}
static int F_85 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_180 * V_181 , int V_182 , int V_183 )
{
struct V_184 * V_185 = & V_9 -> V_186 ;
struct V_87 * V_88 ;
unsigned int V_187 = 0 ;
int V_13 = 0 ;
if ( V_181 -> V_71 == 0 )
return 0 ;
if ( V_182 > 0 || V_183 != V_70 ) {
V_88 = F_86 ( V_181 ) ;
if ( V_181 -> V_71 == 1 ) {
F_87 ( V_3 , V_88 , V_182 , V_183 ) ;
} else {
if ( V_182 > 0 )
F_87 ( V_3 , V_88 , V_182 , V_70 ) ;
if ( V_183 != V_70 ) {
V_88 = F_88 ( V_181 ) ;
F_87 ( V_3 , V_88 , 0 , V_183 ) ;
}
}
}
F_89 ( V_185 ) ;
F_90 ( V_181 , & V_185 -> V_188 ) ;
V_13 = F_91 ( V_3 , V_9 , V_189 , V_185 , 0 ) ;
F_90 ( & V_185 -> V_188 , V_181 ) ;
F_90 ( & V_185 -> V_190 , V_181 ) ;
F_92 ( V_3 , V_185 ) ;
if ( V_13 == 0 ) {
V_187 = V_181 -> V_71 << V_35 ;
V_187 -= V_182 + V_70 - V_183 ;
while ( V_181 -> V_71 > 0 ) {
V_88 = F_86 ( V_181 ) ;
F_93 ( V_3 , V_181 , V_88 ) ;
F_87 ( V_3 , V_88 , 0 , V_70 ) ;
F_94 ( F_95 ( V_88 ) ) ;
F_96 ( V_3 , V_9 , V_88 ) ;
F_41 ( & V_88 -> V_91 , L_9 , V_9 ) ;
F_42 ( V_3 , V_88 ) ;
}
}
return V_187 > 0 ? V_187 : V_13 ;
}
static void F_97 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_87 * V_88 )
{
struct V_88 * V_191 = V_88 -> V_192 ;
F_94 ( V_191 ) ;
F_98 ( V_191 ) ;
F_96 ( V_3 , V_9 , V_88 ) ;
F_41 ( & V_88 -> V_91 , L_9 , F_99 ( V_9 ) ) ;
F_42 ( V_3 , V_88 ) ;
}
static bool F_100 ( struct V_22 * V_23 ,
struct V_180 * V_181 )
{
struct V_87 * V_88 ;
T_4 V_193 = V_194 ;
F_101 (page, plist) {
struct V_195 * V_196 = F_102 ( V_23 , V_88 ) ;
if ( V_193 == V_194 ) {
V_193 = F_103 ( V_196 ) ;
continue;
}
++ V_193 ;
if ( V_193 == F_103 ( V_196 ) )
continue;
return false ;
}
return true ;
}
int F_104 ( const struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_22 * V_23 = V_9 -> V_49 ;
struct V_10 * V_10 = F_10 ( V_23 ) ;
struct V_1 * V_6 = F_4 ( V_3 ) ;
struct V_180 * V_185 = & V_6 -> V_64 . V_65 . V_66 ;
struct V_87 * V_88 ;
int V_13 = 0 ;
int V_187 = 0 ;
unsigned int V_197 = V_6 -> V_64 . V_65 . V_66 . V_71 ;
if ( V_197 == 0 )
return 0 ;
F_22 ( V_37 , L_10 ,
V_197 , V_6 -> V_64 . V_65 . V_68 , V_6 -> V_64 . V_65 . V_69 ) ;
F_3 ( F_100 ( V_23 , V_185 ) ) ;
V_13 = F_105 ( V_3 , V_9 , V_185 ,
V_6 -> V_64 . V_65 . V_68 , V_6 -> V_64 . V_65 . V_69 ,
F_97 ) ;
V_197 -= V_185 -> V_71 ;
if ( V_197 > 0 ) {
V_187 = V_197 << V_35 ;
V_187 -= V_6 -> V_64 . V_65 . V_68 ;
if ( V_185 -> V_71 == 0 )
V_187 -= V_70 - V_6 -> V_64 . V_65 . V_69 ;
F_106 ( V_187 > 0 , L_11 , V_187 , V_197 ) ;
V_6 -> V_64 . V_65 . V_67 += V_187 ;
F_22 ( V_37 , L_12 ,
V_197 , V_187 , V_6 -> V_64 . V_65 . V_67 ) ;
V_6 -> V_64 . V_65 . V_68 = 0 ;
}
F_3 ( F_100 ( V_23 , V_185 ) ) ;
F_3 ( F_107 ( V_13 == 0 , V_185 -> V_71 == 0 ) ) ;
if ( V_13 == - V_198 && ! F_108 ( V_9 ) ) {
V_13 = F_85 ( V_3 , V_9 , V_185 ,
V_6 -> V_64 . V_65 . V_68 ,
V_6 -> V_64 . V_65 . V_69 ) ;
if ( V_13 > 0 ) {
V_6 -> V_64 . V_65 . V_67 += V_13 ;
V_13 = 0 ;
}
}
F_109 ( V_3 , V_10 ) ;
while ( V_185 -> V_71 > 0 ) {
V_88 = F_86 ( V_185 ) ;
F_93 ( V_3 , V_185 , V_88 ) ;
if ( ! F_110 ( F_95 ( V_88 ) ) )
F_111 ( V_3 , V_9 , V_88 ) ;
F_96 ( V_3 , V_9 , V_88 ) ;
F_41 ( & V_88 -> V_91 , L_9 , V_9 ) ;
F_42 ( V_3 , V_88 ) ;
}
F_112 ( V_3 , V_185 ) ;
return V_13 ;
}
static int F_113 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
struct V_1 * V_6 = F_1 ( V_3 , V_63 ) ;
struct V_8 * V_9 = V_63 -> V_78 ;
struct V_22 * V_23 = V_9 -> V_49 ;
struct V_10 * V_10 = F_10 ( V_23 ) ;
struct V_11 * V_12 = F_6 ( V_10 ) ;
T_5 V_31 = 0 ;
T_1 V_29 = V_9 -> V_64 . V_137 . V_139 . V_134 ;
T_2 V_165 = V_9 -> V_64 . V_137 . V_139 . V_127 ;
F_47 ( & V_12 -> V_161 ) ;
if ( ! F_5 ( V_3 , V_9 , V_10 ) )
return 0 ;
if ( F_114 ( V_9 ) ) {
F_109 ( V_3 , V_10 ) ;
V_29 = F_20 ( V_10 ) ;
V_9 -> V_64 . V_137 . V_139 . V_134 = V_29 ;
V_6 -> V_175 -> V_176 = V_29 ;
} else {
F_3 ( V_6 -> V_175 -> V_176 == V_29 ) ;
}
F_22 ( V_37 , L_13 , V_29 , V_29 + ( long long ) V_165 ) ;
if ( V_29 + V_165 > F_115 ( V_10 ) ) {
F_22 ( V_168 ,
L_14 V_38 L_15 ,
F_116 ( V_10 -> V_199 , NULL , 0 ) ,
F_23 ( F_117 ( V_10 ) ) , V_29 + V_165 ,
F_115 ( V_10 ) ) ;
return - V_200 ;
}
if ( ! V_6 -> V_112 ) {
V_31 = 0 ;
} else {
bool V_201 = ! F_118 ( V_10 ) ;
if ( V_201 )
F_71 ( V_10 ) ;
V_31 = F_119 ( V_6 -> V_175 ,
V_6 -> V_112 ) ;
if ( V_201 )
F_74 ( V_10 ) ;
if ( V_31 > 0 || V_31 == - V_202 )
V_31 = F_120 ( V_6 -> V_175 , V_31 ) ;
}
if ( V_31 > 0 ) {
V_31 = F_104 ( V_3 , V_9 ) ;
if ( V_6 -> V_64 . V_65 . V_67 > 0 ) {
V_31 = V_6 -> V_64 . V_65 . V_67 ;
V_9 -> V_177 += V_31 ;
F_22 ( V_37 , L_16 ,
V_9 -> V_177 , V_31 ) ;
}
}
if ( V_31 > 0 ) {
F_77 ( V_163 , & ( F_6 ( V_10 ) ) -> V_86 ) ;
if ( V_31 < V_165 )
V_9 -> V_20 = 0 ;
F_83 ( F_84 ( V_10 ) , V_103 -> V_178 ,
V_6 -> V_50 , V_29 , V_31 , V_203 ) ;
V_31 = 0 ;
}
return V_31 ;
}
static void F_121 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
struct V_10 * V_10 = F_10 ( V_63 -> V_72 ) ;
struct V_11 * V_12 = F_6 ( V_10 ) ;
F_52 ( & V_12 -> V_161 ) ;
}
static int F_122 ( struct V_204 * V_205 )
{
struct V_206 * V_207 = V_205 -> V_208 ;
V_205 -> V_209 = F_123 ( V_207 ) ;
V_205 -> V_210 = 1 ;
if ( V_207 -> V_88 ) {
F_22 ( V_211 ,
L_17 ,
V_207 -> V_88 , V_207 -> V_88 -> V_212 , V_207 -> V_88 -> V_193 ,
( long ) V_207 -> V_88 -> V_118 , F_124 ( V_207 -> V_88 ) ,
F_125 ( V_207 -> V_88 ) , ( void * ) V_207 -> V_213 ) ;
if ( F_126 ( ! ( V_205 -> V_209 & V_214 ) ) ) {
F_127 ( V_207 -> V_88 ) ;
V_205 -> V_209 |= V_214 ;
}
V_205 -> V_215 = V_207 -> V_88 ;
return 0 ;
}
if ( V_205 -> V_209 & ( V_216 | V_217 ) ) {
F_22 ( V_211 , L_18 , ( void * ) V_207 -> V_213 ) ;
return - V_218 ;
}
if ( V_205 -> V_209 & V_219 ) {
F_22 ( V_211 , L_19 , ( void * ) V_207 -> V_213 ) ;
return - V_220 ;
}
if ( V_205 -> V_209 & V_221 )
return - V_222 ;
F_128 ( L_20 , V_205 -> V_209 ) ;
return - V_120 ;
}
static void F_129 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_87 * V_88 )
{
F_98 ( V_88 -> V_192 ) ;
}
static int F_130 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
struct V_1 * V_6 = F_1 ( V_3 , V_63 ) ;
struct V_8 * V_9 = V_63 -> V_78 ;
struct V_22 * V_23 = V_9 -> V_49 ;
struct V_10 * V_10 = F_10 ( V_23 ) ;
struct V_11 * V_12 = F_6 ( V_10 ) ;
struct V_223 * V_224 = & V_9 -> V_64 . V_89 ;
struct V_204 * V_205 = & V_6 -> V_64 . V_74 ;
T_1 V_225 ;
int V_31 = 0 ;
struct V_88 * V_191 = NULL ;
struct V_87 * V_88 ;
T_1 V_33 ;
T_4 V_226 ;
F_47 ( & V_12 -> V_161 ) ;
V_225 = F_131 ( V_23 , V_224 -> V_136 + 1 ) - 1 ;
F_3 ( F_30 ( V_23 , V_225 ) == V_224 -> V_136 ) ;
V_31 = F_16 ( V_3 , V_23 , V_9 , 0 , V_225 + 1 , NULL ) ;
if ( V_31 != 0 )
return V_31 ;
if ( V_224 -> V_227 ) {
F_3 ( V_205 -> V_215 ) ;
F_127 ( V_205 -> V_215 ) ;
} else {
V_31 = F_122 ( V_205 ) ;
if ( V_31 != 0 )
return V_31 ;
}
V_191 = V_205 -> V_215 ;
F_3 ( F_132 ( V_191 ) ) ;
if ( F_133 ( V_228 ) )
F_134 ( V_191 ) ;
V_33 = F_20 ( V_10 ) ;
if ( F_126 ( ( V_191 -> V_212 != V_10 -> V_229 ) ||
( F_135 ( V_191 ) > V_33 ) ) ) {
F_22 ( V_211 , L_21 ) ;
V_31 = 1 ;
goto V_167;
}
V_226 = F_30 ( V_23 , V_33 - 1 ) ;
if ( V_224 -> V_227 ) {
if ( V_226 < V_224 -> V_136 ) {
F_22 ( V_211 ,
L_22 ,
V_191 -> V_212 , V_224 -> V_136 , V_226 ) ;
V_31 = - V_230 ;
goto V_167;
}
}
V_88 = F_136 ( V_3 , V_23 , V_224 -> V_136 , V_191 , V_231 ) ;
if ( F_137 ( V_88 ) ) {
V_31 = F_138 ( V_88 ) ;
goto V_167;
}
if ( V_224 -> V_227 ) {
F_139 ( V_191 ) ;
if ( ! F_110 ( V_191 ) ) {
struct V_180 * V_181 = & V_9 -> V_186 . V_188 ;
struct V_195 * V_196 = F_102 ( V_23 , V_88 ) ;
int V_183 = V_70 ;
F_140 ( V_3 , V_9 , V_88 ) ;
F_32 ( V_181 ) ;
F_141 ( V_181 , V_88 ) ;
if ( V_226 == F_103 ( V_196 ) )
V_183 = V_33 & ~ V_115 ;
V_31 = F_105 ( V_3 , V_9 , V_181 , 0 , V_183 ,
F_129 ) ;
F_3 ( F_142 ( V_88 , V_9 ) ) ;
F_112 ( V_3 , V_181 ) ;
V_191 = NULL ;
if ( V_31 < 0 ) {
F_111 ( V_3 , V_9 , V_88 ) ;
F_96 ( V_3 , V_9 , V_88 ) ;
F_42 ( V_3 , V_88 ) ;
if ( V_31 == - V_198 )
V_31 = - V_232 ;
goto V_167;
} else {
F_96 ( V_3 , V_9 , V_88 ) ;
}
}
}
F_3 ( ! V_224 -> V_227 || V_224 -> V_136 <= V_226 ) ;
if ( V_224 -> V_136 == V_226 )
V_224 -> V_233 = V_33 - F_131 ( V_23 , V_224 -> V_136 ) ;
else
V_224 -> V_233 = F_143 ( V_23 ) ;
F_144 ( & V_88 -> V_91 , L_5 , V_9 ) ;
V_224 -> V_90 = V_88 ;
V_167:
if ( V_191 )
F_145 ( V_191 ) ;
V_205 -> V_209 &= ~ V_214 ;
return V_31 ;
}
static void F_146 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
struct V_10 * V_10 = F_10 ( V_63 -> V_72 ) ;
struct V_11 * V_12 = F_6 ( V_10 ) ;
F_26 ( V_3 , V_63 -> V_78 -> V_49 ,
F_27 ( V_63 -> V_78 -> V_49 ) ) ;
F_52 ( & V_12 -> V_161 ) ;
}
static int F_147 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
return 0 ;
}
static int F_148 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 ,
T_4 V_24 , struct V_234 * V_235 )
{
int V_31 = 0 ;
if ( V_63 -> V_78 -> V_14 == V_15 ||
V_63 -> V_78 -> V_14 == V_21 ) {
struct V_1 * V_6 = F_1 ( V_3 , V_63 ) ;
if ( F_126 ( V_6 -> V_50 -> V_51 & V_52 ) ) {
V_235 -> V_236 = V_194 ;
V_31 = 1 ;
}
}
return V_31 ;
}
int F_149 ( const struct V_2 * V_3 , struct V_22 * V_23 ,
struct V_8 * V_9 )
{
struct V_1 * V_6 = F_4 ( V_3 ) ;
struct V_10 * V_10 = F_10 ( V_23 ) ;
int V_31 ;
F_26 ( V_3 , V_23 , F_27 ( V_23 ) ) ;
F_22 ( V_37 , V_38
L_3 ,
F_23 ( F_24 ( & V_23 -> V_39 ) ) ,
V_9 -> V_79 , V_9 -> V_80 ,
V_6 -> V_17 , V_9 -> V_81 ) ;
F_150 ( V_6 , V_7 ) ;
F_151 ( V_9 , & V_6 -> V_7 , V_23 , & V_237 ) ;
V_6 -> V_172 = false ;
V_31 = 0 ;
if ( V_9 -> V_14 == V_15 || V_9 -> V_14 == V_16 ) {
T_2 V_25 ;
struct V_11 * V_12 = F_6 ( V_10 ) ;
V_25 = V_9 -> V_64 . V_126 . V_127 ;
if ( V_25 == 0 )
V_31 = 1 ;
else
V_6 -> V_125 = V_25 ;
F_152 ( V_12 -> V_238 ) ;
} else if ( V_9 -> V_14 == V_239 ) {
if ( ! F_63 ( V_9 ) )
V_9 -> V_240 = V_241 ;
}
if ( V_31 == 0 && ! V_9 -> V_79 ) {
V_31 = F_38 ( V_10 , & V_6 -> V_17 ) ;
if ( V_31 == - V_242 )
V_31 = 0 ;
if ( V_31 < 0 )
F_128 ( L_23 V_38 L_24 ,
F_116 ( V_10 -> V_199 , NULL , 0 ) ,
F_23 ( F_24 ( & V_23 -> V_39 ) ) , V_31 ) ;
}
return V_31 ;
}
