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
} else {
V_46 -> V_53 = V_43 ;
}
V_46 -> V_58 = V_23 ;
V_46 -> V_59 = V_24 ;
V_46 -> V_60 = V_44 ;
V_46 -> V_61 = V_41 ;
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
const struct V_4 * V_62 )
{
struct V_1 * V_6 = F_1 ( V_3 , V_62 ) ;
F_32 ( & V_6 -> V_63 . V_64 . V_65 ) ;
V_6 -> V_63 . V_64 . V_66 = 0 ;
V_6 -> V_63 . V_64 . V_67 = 0 ;
V_6 -> V_63 . V_64 . V_68 = V_69 ;
return 0 ;
}
static void F_33 ( const struct V_2 * V_3 ,
const struct V_4 * V_62 )
{
struct V_1 * V_6 = F_1 ( V_3 , V_62 ) ;
F_3 ( V_6 -> V_63 . V_64 . V_65 . V_70 == 0 ) ;
}
static int F_34 ( const struct V_2 * V_3 ,
const struct V_4 * V_62 )
{
struct V_1 * V_6 = F_1 ( V_3 , V_62 ) ;
struct V_10 * V_10 = F_10 ( V_62 -> V_71 ) ;
F_3 ( V_10 == F_35 ( V_6 -> V_50 -> V_72 ) ) ;
V_6 -> V_63 . V_73 . V_74 = V_10 -> V_75 . V_76 ;
return 0 ;
}
static void F_36 ( const struct V_2 * V_3 , const struct V_4 * V_62 )
{
struct V_8 * V_9 = V_62 -> V_77 ;
struct V_22 * V_23 = V_9 -> V_49 ;
struct V_1 * V_6 = F_1 ( V_3 , V_62 ) ;
struct V_10 * V_10 = F_10 ( V_23 ) ;
F_26 ( V_3 , V_23 , F_27 ( V_23 ) ) ;
F_22 ( V_37 , V_38
L_3 ,
F_23 ( F_24 ( & V_23 -> V_39 ) ) ,
V_9 -> V_78 , V_9 -> V_79 ,
V_6 -> V_17 , V_9 -> V_80 ) ;
if ( V_9 -> V_80 == 1 ) {
int V_13 ;
V_13 = F_37 ( V_10 , 0 , V_81 ) ;
if ( V_13 == 0 ) {
V_9 -> V_80 = 0 ;
V_9 -> V_19 = 1 ;
V_9 -> V_79 = 1 ;
} else {
V_9 -> V_80 = 1 ;
V_9 -> V_19 = 0 ;
V_9 -> V_79 = 0 ;
V_9 -> V_82 = V_13 ;
}
}
if ( ! V_9 -> V_78 && V_9 -> V_79 ) {
T_3 V_83 = 0 ;
F_38 ( V_10 , & V_83 ) ;
V_9 -> V_19 = V_6 -> V_17 != V_83 ;
if ( V_9 -> V_19 ) {
F_22 ( V_37 ,
V_38 L_4 ,
F_23 ( F_24 ( & V_23 -> V_39 ) ) ,
V_6 -> V_17 , V_83 ) ;
F_39 ( V_84 ,
& F_6 ( V_10 ) -> V_85 ) ;
}
}
}
static void F_40 ( const struct V_2 * V_3 ,
const struct V_4 * V_62 )
{
struct V_8 * V_9 = V_62 -> V_77 ;
struct V_86 * V_87 = V_9 -> V_63 . V_88 . V_89 ;
F_26 ( V_3 , V_9 -> V_49 , F_27 ( V_9 -> V_49 ) ) ;
if ( V_87 ) {
F_41 ( & V_87 -> V_90 , L_5 , V_9 ) ;
F_42 ( V_3 , V_87 ) ;
V_9 -> V_63 . V_88 . V_89 = NULL ;
}
F_36 ( V_3 , V_62 ) ;
}
static enum V_42 F_43 ( struct V_91 * V_92 )
{
if ( ( V_92 -> V_93 & V_94 ) && ( V_92 -> V_93 & V_95 ) )
return V_96 ;
return V_97 ;
}
static int F_44 ( const struct V_2 * V_3 ,
struct V_1 * V_6 , struct V_8 * V_9 )
{
struct V_98 * V_99 = F_45 ( V_3 ) ;
struct V_100 * V_101 = V_102 -> V_101 ;
struct V_91 * V_92 ;
struct V_45 * V_46 = & V_99 -> V_103 ;
union V_104 V_105 ;
unsigned long V_106 ;
T_5 V_25 ;
int V_31 = 0 ;
struct V_107 V_108 ;
struct V_109 V_110 ;
F_3 ( V_9 -> V_14 == V_15 || V_9 -> V_14 == V_16 ) ;
if ( ! V_6 -> V_111 )
return 0 ;
if ( ! V_101 )
return 0 ;
F_46 (iov, i, *vio->vui_iter) {
V_106 = ( unsigned long ) V_110 . V_112 ;
V_25 = V_110 . V_113 ;
if ( V_25 == 0 )
continue;
V_25 += V_106 & ( ~ V_114 ) ;
V_106 &= V_114 ;
F_47 ( & V_101 -> V_115 ) ;
while ( ( V_92 = F_48 ( V_101 , V_106 , V_25 ) ) != NULL ) {
struct V_10 * V_10 = F_35 ( V_92 -> V_116 ) ;
int V_117 = V_118 ;
if ( F_49 ( V_92 -> V_116 ) ) {
V_31 = - V_119 ;
break;
}
F_50 ( & V_105 , V_92 , V_106 , V_25 ) ;
V_46 -> V_53 = F_43 ( V_92 ) ;
V_46 -> V_58 = F_6 ( V_10 ) -> V_120 ;
V_46 -> V_59 = F_30 ( V_46 -> V_58 ,
V_105 . V_121 . V_24 ) ;
V_46 -> V_60 = F_30 ( V_46 -> V_58 ,
V_105 . V_121 . V_44 ) ;
V_46 -> V_61 = V_117 ;
V_31 = F_51 ( V_3 , V_9 , V_46 ) ;
F_22 ( V_37 , L_6 ,
V_46 -> V_53 , V_46 -> V_59 ,
V_46 -> V_60 ) ;
if ( V_31 < 0 )
break;
if ( V_92 -> V_122 - V_106 >= V_25 )
break;
V_25 -= V_92 -> V_122 - V_106 ;
V_106 = V_92 -> V_122 ;
}
F_52 ( & V_101 -> V_115 ) ;
if ( V_31 < 0 )
break;
}
return V_31 ;
}
static void F_53 ( const struct V_2 * V_3 ,
const struct V_4 * V_62 ,
T_2 V_123 )
{
struct V_22 * V_23 = V_62 -> V_77 -> V_49 ;
struct V_1 * V_6 = F_1 ( V_3 , V_62 ) ;
F_26 ( V_3 , V_23 , F_27 ( V_23 ) ) ;
V_6 -> V_124 -= V_123 ;
F_54 ( V_6 -> V_111 , V_6 -> V_124 ) ;
}
static void F_55 ( const struct V_2 * V_3 ,
struct V_1 * V_6 , struct V_8 * V_9 )
{
T_2 V_33 = V_9 -> V_63 . V_125 . V_126 ;
if ( ! V_6 -> V_111 )
return;
F_56 ( V_6 -> V_111 , V_33 ) ;
}
static int F_57 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
enum V_42 V_43 , T_1 V_24 , T_1 V_44 )
{
struct V_1 * V_6 = F_4 ( V_3 ) ;
int V_31 ;
int V_127 = 0 ;
F_3 ( V_9 -> V_14 == V_15 || V_9 -> V_14 == V_16 ) ;
F_55 ( V_3 , V_6 , V_9 ) ;
if ( V_9 -> V_63 . V_125 . V_128 )
V_127 |= V_129 ;
V_31 = F_44 ( V_3 , V_6 , V_9 ) ;
if ( V_31 == 0 )
V_31 = F_29 ( V_3 , V_9 , V_127 , V_43 , V_24 , V_44 ) ;
return V_31 ;
}
static int F_58 ( const struct V_2 * V_3 ,
const struct V_4 * V_62 )
{
struct V_8 * V_9 = V_62 -> V_77 ;
struct V_130 * V_131 = & V_9 -> V_63 . V_132 . V_131 ;
int V_31 ;
V_31 = F_57 ( V_3 , V_9 , V_97 , V_131 -> V_133 ,
V_131 -> V_133 + V_131 -> V_126 - 1 ) ;
return V_31 ;
}
static int F_59 ( const struct V_2 * V_3 ,
const struct V_4 * V_62 )
{
struct V_8 * V_9 = V_62 -> V_77 ;
struct V_1 * V_6 = F_1 ( V_3 , V_62 ) ;
return F_25 ( V_3 ,
V_9 , 0 ,
F_43 ( V_6 -> V_63 . V_73 . V_134 ) ,
V_9 -> V_63 . V_88 . V_135 ,
V_9 -> V_63 . V_88 . V_135 ) ;
}
static int F_60 ( const struct V_2 * V_3 ,
const struct V_4 * V_62 )
{
struct V_8 * V_9 = V_62 -> V_77 ;
T_1 V_24 ;
T_1 V_44 ;
if ( V_9 -> V_63 . V_136 . V_137 ) {
V_24 = 0 ;
V_44 = V_81 ;
} else {
V_24 = V_9 -> V_63 . V_136 . V_138 . V_133 ;
V_44 = V_24 + V_9 -> V_63 . V_136 . V_138 . V_126 - 1 ;
}
return F_57 ( V_3 , V_9 , V_96 , V_24 , V_44 ) ;
}
static int F_61 ( const struct V_2 * V_3 ,
const struct V_4 * V_62 )
{
return 0 ;
}
static int F_62 ( const struct V_2 * V_3 ,
const struct V_4 * V_62 )
{
struct V_8 * V_9 = V_62 -> V_77 ;
V_40 V_139 ;
T_3 V_41 = 0 ;
if ( F_63 ( V_9 ) ) {
V_139 = V_9 -> V_63 . V_140 . V_141 . V_142 ;
if ( V_139 == 0 )
V_41 = V_143 ;
} else {
unsigned int V_144 = V_9 -> V_63 . V_140 . V_145 ;
if ( ! ( V_144 & V_146 ) )
return 0 ;
if ( ( ! ( V_144 & V_147 ) ||
V_9 -> V_63 . V_140 . V_141 . V_148 >=
V_9 -> V_63 . V_140 . V_141 . V_149 ) &&
( ! ( V_144 & V_150 ) ||
V_9 -> V_63 . V_140 . V_141 . V_151 >=
V_9 -> V_63 . V_140 . V_141 . V_149 ) )
return 0 ;
V_139 = 0 ;
}
return F_29 ( V_3 , V_9 , V_41 , V_96 ,
V_139 , V_81 ) ;
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
const struct V_4 * V_62 )
{
struct V_8 * V_9 = V_62 -> V_77 ;
struct V_22 * V_23 = V_9 -> V_49 ;
struct V_27 * V_28 = F_17 ( V_3 ) ;
int V_31 ;
unsigned V_144 = V_152 ;
F_12 ( V_23 ) ;
V_28 -> V_153 = V_9 -> V_63 . V_140 . V_141 . V_149 ;
if ( V_9 -> V_63 . V_140 . V_145 & V_154 ) {
V_28 -> V_155 = V_9 -> V_63 . V_140 . V_141 . V_151 ;
V_144 |= V_156 ;
}
if ( V_9 -> V_63 . V_140 . V_145 & V_157 ) {
V_28 -> V_158 = V_9 -> V_63 . V_140 . V_141 . V_148 ;
V_144 |= V_159 ;
}
V_31 = F_68 ( V_3 , V_23 , V_28 , V_144 ) ;
F_14 ( V_23 ) ;
return V_31 ;
}
static int F_69 ( const struct V_2 * V_3 ,
const struct V_4 * V_62 )
{
struct V_8 * V_9 = V_62 -> V_77 ;
struct V_10 * V_10 = F_10 ( V_9 -> V_49 ) ;
struct V_11 * V_12 = F_6 ( V_10 ) ;
if ( F_63 ( V_9 ) ) {
F_70 ( & V_12 -> V_160 ) ;
F_71 ( V_10 ) ;
F_72 ( V_10 ) ;
} else {
F_71 ( V_10 ) ;
}
if ( V_9 -> V_63 . V_140 . V_145 & V_146 )
return F_67 ( V_3 , V_62 ) ;
return 0 ;
}
static void F_73 ( const struct V_2 * V_3 ,
const struct V_4 * V_62 )
{
struct V_8 * V_9 = V_62 -> V_77 ;
struct V_10 * V_10 = F_10 ( V_9 -> V_49 ) ;
struct V_11 * V_12 = F_6 ( V_10 ) ;
if ( F_63 ( V_9 ) ) {
F_64 ( V_10 , V_9 -> V_63 . V_140 . V_141 . V_142 ) ;
F_74 ( V_10 ) ;
F_75 ( & V_12 -> V_160 ) ;
} else {
F_74 ( V_10 ) ;
}
}
static void F_76 ( const struct V_2 * V_3 ,
const struct V_4 * V_62 )
{
F_36 ( V_3 , V_62 ) ;
}
static int F_77 ( const struct V_2 * V_3 ,
const struct V_4 * V_62 )
{
struct V_1 * V_6 = F_1 ( V_3 , V_62 ) ;
struct V_8 * V_9 = V_62 -> V_77 ;
struct V_22 * V_23 = V_9 -> V_49 ;
struct V_10 * V_10 = F_10 ( V_23 ) ;
struct V_11 * V_12 = F_6 ( V_10 ) ;
struct V_161 * V_161 = V_6 -> V_50 -> V_72 ;
int V_31 ;
T_1 V_29 = V_9 -> V_63 . V_132 . V_131 . V_133 ;
long V_162 = V_9 -> V_63 . V_132 . V_131 . V_126 ;
long V_163 = V_6 -> V_124 ;
int V_26 = 0 ;
F_26 ( V_3 , V_23 , F_27 ( V_23 ) ) ;
F_22 ( V_37 , L_7 , V_29 , V_29 + V_162 ) ;
F_47 ( & V_12 -> V_160 ) ;
if ( ! F_5 ( V_3 , V_9 , V_10 ) )
return 0 ;
V_31 = F_16 ( V_3 , V_23 , V_9 , V_29 , V_163 , & V_26 ) ;
if ( V_31 != 0 )
return V_31 ;
else if ( V_26 != 0 )
goto V_164;
F_78 ( V_165 , V_3 , & V_23 -> V_39 ,
L_8 ,
V_10 -> V_166 , V_162 , V_29 , F_20 ( V_10 ) ) ;
V_6 -> V_50 -> V_72 -> V_167 . V_168 = 0 ;
if ( ! V_6 -> V_169 ) {
V_6 -> V_169 = true ;
V_6 -> V_170 = F_30 ( V_23 , V_29 ) ;
V_6 -> V_171 = F_30 ( V_23 , V_163 + V_69 - 1 ) ;
F_79 ( V_161 ) ;
}
F_80 ( V_161 ) ;
F_3 ( V_6 -> V_172 -> V_173 == V_29 ) ;
V_31 = F_81 ( V_6 -> V_172 , V_6 -> V_111 ) ;
V_164:
if ( V_31 >= 0 ) {
if ( V_31 < V_162 )
V_9 -> V_20 = 0 ;
V_9 -> V_174 += V_31 ;
F_82 ( F_83 ( V_10 ) , V_102 -> V_175 ,
V_6 -> V_50 , V_29 , V_31 , V_176 ) ;
V_31 = 0 ;
}
return V_31 ;
}
static int F_84 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_177 * V_178 , int V_179 , int V_180 )
{
struct V_181 * V_182 = & V_9 -> V_183 ;
struct V_86 * V_87 ;
unsigned int V_184 = 0 ;
int V_13 = 0 ;
if ( V_178 -> V_70 == 0 )
return 0 ;
if ( V_179 > 0 || V_180 != V_69 ) {
V_87 = F_85 ( V_178 ) ;
if ( V_178 -> V_70 == 1 ) {
F_86 ( V_3 , V_87 , V_179 , V_180 ) ;
} else {
if ( V_179 > 0 )
F_86 ( V_3 , V_87 , V_179 , V_69 ) ;
if ( V_180 != V_69 ) {
V_87 = F_87 ( V_178 ) ;
F_86 ( V_3 , V_87 , 0 , V_180 ) ;
}
}
}
F_88 ( V_182 ) ;
F_89 ( V_178 , & V_182 -> V_185 ) ;
V_13 = F_90 ( V_3 , V_9 , V_186 , V_182 , 0 ) ;
F_89 ( & V_182 -> V_185 , V_178 ) ;
F_89 ( & V_182 -> V_187 , V_178 ) ;
F_91 ( V_3 , V_182 ) ;
if ( V_13 == 0 ) {
V_184 = V_178 -> V_70 << V_35 ;
V_184 -= V_179 + V_69 - V_180 ;
while ( V_178 -> V_70 > 0 ) {
V_87 = F_85 ( V_178 ) ;
F_92 ( V_3 , V_178 , V_87 ) ;
F_86 ( V_3 , V_87 , 0 , V_69 ) ;
F_93 ( F_94 ( V_87 ) ) ;
F_95 ( V_3 , V_9 , V_87 ) ;
F_41 ( & V_87 -> V_90 , L_9 , V_9 ) ;
F_42 ( V_3 , V_87 ) ;
}
}
return V_184 > 0 ? V_184 : V_13 ;
}
static void F_96 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_86 * V_87 )
{
struct V_87 * V_188 = V_87 -> V_189 ;
F_93 ( V_188 ) ;
F_97 ( V_188 ) ;
F_95 ( V_3 , V_9 , V_87 ) ;
F_41 ( & V_87 -> V_90 , L_9 , F_98 ( V_9 ) ) ;
F_42 ( V_3 , V_87 ) ;
}
static bool F_99 ( struct V_22 * V_23 ,
struct V_177 * V_178 )
{
struct V_86 * V_87 ;
T_4 V_190 = V_191 ;
F_100 (page, plist) {
struct V_192 * V_193 = F_101 ( V_23 , V_87 ) ;
if ( V_190 == V_191 ) {
V_190 = F_102 ( V_193 ) ;
continue;
}
++ V_190 ;
if ( V_190 == F_102 ( V_193 ) )
continue;
return false ;
}
return true ;
}
int F_103 ( const struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_22 * V_23 = V_9 -> V_49 ;
struct V_10 * V_10 = F_10 ( V_23 ) ;
struct V_1 * V_6 = F_4 ( V_3 ) ;
struct V_177 * V_182 = & V_6 -> V_63 . V_64 . V_65 ;
struct V_86 * V_87 ;
int V_13 = 0 ;
int V_184 = 0 ;
unsigned int V_194 = V_6 -> V_63 . V_64 . V_65 . V_70 ;
if ( V_194 == 0 )
return 0 ;
F_22 ( V_37 , L_10 ,
V_194 , V_6 -> V_63 . V_64 . V_67 , V_6 -> V_63 . V_64 . V_68 ) ;
F_3 ( F_99 ( V_23 , V_182 ) ) ;
V_13 = F_104 ( V_3 , V_9 , V_182 ,
V_6 -> V_63 . V_64 . V_67 , V_6 -> V_63 . V_64 . V_68 ,
F_96 ) ;
V_194 -= V_182 -> V_70 ;
if ( V_194 > 0 ) {
V_184 = V_194 << V_35 ;
V_184 -= V_6 -> V_63 . V_64 . V_67 ;
if ( V_182 -> V_70 == 0 )
V_184 -= V_69 - V_6 -> V_63 . V_64 . V_68 ;
F_105 ( V_184 > 0 , L_11 , V_184 , V_194 ) ;
V_6 -> V_63 . V_64 . V_66 += V_184 ;
F_22 ( V_37 , L_12 ,
V_194 , V_184 , V_6 -> V_63 . V_64 . V_66 ) ;
V_6 -> V_63 . V_64 . V_67 = 0 ;
}
F_3 ( F_99 ( V_23 , V_182 ) ) ;
F_3 ( F_106 ( V_13 == 0 , V_182 -> V_70 == 0 ) ) ;
if ( V_13 == - V_195 && ! F_107 ( V_9 ) ) {
V_13 = F_84 ( V_3 , V_9 , V_182 ,
V_6 -> V_63 . V_64 . V_67 ,
V_6 -> V_63 . V_64 . V_68 ) ;
if ( V_13 > 0 ) {
V_6 -> V_63 . V_64 . V_66 += V_13 ;
V_13 = 0 ;
}
}
F_108 ( V_3 , V_10 ) ;
while ( V_182 -> V_70 > 0 ) {
V_87 = F_85 ( V_182 ) ;
F_92 ( V_3 , V_182 , V_87 ) ;
if ( ! F_109 ( F_94 ( V_87 ) ) )
F_110 ( V_3 , V_9 , V_87 ) ;
F_95 ( V_3 , V_9 , V_87 ) ;
F_41 ( & V_87 -> V_90 , L_9 , V_9 ) ;
F_42 ( V_3 , V_87 ) ;
}
F_111 ( V_3 , V_182 ) ;
return V_13 ;
}
static int F_112 ( const struct V_2 * V_3 ,
const struct V_4 * V_62 )
{
struct V_1 * V_6 = F_1 ( V_3 , V_62 ) ;
struct V_8 * V_9 = V_62 -> V_77 ;
struct V_22 * V_23 = V_9 -> V_49 ;
struct V_10 * V_10 = F_10 ( V_23 ) ;
struct V_11 * V_12 = F_6 ( V_10 ) ;
T_5 V_31 = 0 ;
T_1 V_29 = V_9 -> V_63 . V_136 . V_138 . V_133 ;
T_2 V_162 = V_9 -> V_63 . V_136 . V_138 . V_126 ;
F_47 ( & V_12 -> V_160 ) ;
if ( ! F_5 ( V_3 , V_9 , V_10 ) )
return 0 ;
if ( F_113 ( V_9 ) ) {
F_108 ( V_3 , V_10 ) ;
V_29 = F_20 ( V_10 ) ;
V_9 -> V_63 . V_136 . V_138 . V_133 = V_29 ;
V_6 -> V_172 -> V_173 = V_29 ;
} else {
F_3 ( V_6 -> V_172 -> V_173 == V_29 ) ;
}
F_22 ( V_37 , L_13 , V_29 , V_29 + ( long long ) V_162 ) ;
if ( V_29 + V_162 > F_114 ( V_10 ) ) {
F_22 ( V_165 ,
L_14 V_38 L_15 ,
F_115 ( V_10 -> V_196 , NULL , 0 ) ,
F_23 ( F_116 ( V_10 ) ) , V_29 + V_162 ,
F_114 ( V_10 ) ) ;
return - V_197 ;
}
if ( ! V_6 -> V_111 ) {
V_31 = 0 ;
} else {
bool V_198 = ! F_117 ( V_10 ) ;
if ( V_198 )
F_71 ( V_10 ) ;
V_31 = F_118 ( V_6 -> V_172 ,
V_6 -> V_111 ) ;
if ( V_198 )
F_74 ( V_10 ) ;
if ( V_31 > 0 || V_31 == - V_199 )
V_31 = F_119 ( V_6 -> V_172 , V_31 ) ;
}
if ( V_31 > 0 ) {
V_31 = F_103 ( V_3 , V_9 ) ;
if ( V_6 -> V_63 . V_64 . V_66 > 0 ) {
V_31 = V_6 -> V_63 . V_64 . V_66 ;
V_9 -> V_174 += V_31 ;
F_22 ( V_37 , L_16 ,
V_9 -> V_174 , V_31 ) ;
}
}
if ( V_31 > 0 ) {
F_120 ( V_200 , & ( F_6 ( V_10 ) ) -> V_85 ) ;
if ( V_31 < V_162 )
V_9 -> V_20 = 0 ;
F_82 ( F_83 ( V_10 ) , V_102 -> V_175 ,
V_6 -> V_50 , V_29 , V_31 , V_201 ) ;
V_31 = 0 ;
}
return V_31 ;
}
static void F_121 ( const struct V_2 * V_3 ,
const struct V_4 * V_62 )
{
struct V_10 * V_10 = F_10 ( V_62 -> V_71 ) ;
struct V_11 * V_12 = F_6 ( V_10 ) ;
F_52 ( & V_12 -> V_160 ) ;
}
static int F_122 ( struct V_202 * V_203 )
{
struct V_204 * V_205 = V_203 -> V_206 ;
V_203 -> V_207 = F_123 ( V_203 -> V_134 , V_205 ) ;
V_203 -> V_208 = 1 ;
if ( V_205 -> V_87 ) {
F_22 ( V_209 ,
L_17 ,
V_205 -> V_87 , V_205 -> V_87 -> V_210 , V_205 -> V_87 -> V_190 ,
( long ) V_205 -> V_87 -> V_117 , F_124 ( V_205 -> V_87 ) ,
F_125 ( V_205 -> V_87 ) , ( void * ) V_205 -> V_211 ) ;
if ( F_126 ( ! ( V_203 -> V_207 & V_212 ) ) ) {
F_127 ( V_205 -> V_87 ) ;
V_203 -> V_207 |= V_212 ;
}
V_203 -> V_213 = V_205 -> V_87 ;
return 0 ;
}
if ( V_203 -> V_207 & ( V_214 | V_215 ) ) {
F_22 ( V_209 , L_18 , ( void * ) V_205 -> V_211 ) ;
return - V_216 ;
}
if ( V_203 -> V_207 & V_217 ) {
F_22 ( V_209 , L_19 , ( void * ) V_205 -> V_211 ) ;
return - V_218 ;
}
if ( V_203 -> V_207 & V_219 )
return - V_220 ;
F_128 ( L_20 , V_203 -> V_207 ) ;
return - V_119 ;
}
static void F_129 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_86 * V_87 )
{
F_97 ( V_87 -> V_189 ) ;
}
static int F_130 ( const struct V_2 * V_3 ,
const struct V_4 * V_62 )
{
struct V_1 * V_6 = F_1 ( V_3 , V_62 ) ;
struct V_8 * V_9 = V_62 -> V_77 ;
struct V_22 * V_23 = V_9 -> V_49 ;
struct V_10 * V_10 = F_10 ( V_23 ) ;
struct V_11 * V_12 = F_6 ( V_10 ) ;
struct V_221 * V_222 = & V_9 -> V_63 . V_88 ;
struct V_202 * V_203 = & V_6 -> V_63 . V_73 ;
T_1 V_223 ;
int V_31 = 0 ;
struct V_87 * V_188 = NULL ;
struct V_86 * V_87 ;
T_1 V_33 ;
T_4 V_224 ;
F_47 ( & V_12 -> V_160 ) ;
V_223 = F_131 ( V_23 , V_222 -> V_135 + 1 ) - 1 ;
F_3 ( F_30 ( V_23 , V_223 ) == V_222 -> V_135 ) ;
V_31 = F_16 ( V_3 , V_23 , V_9 , 0 , V_223 + 1 , NULL ) ;
if ( V_31 != 0 )
return V_31 ;
if ( V_222 -> V_225 ) {
F_3 ( V_203 -> V_213 ) ;
F_127 ( V_203 -> V_213 ) ;
} else {
V_31 = F_122 ( V_203 ) ;
if ( V_31 != 0 )
return V_31 ;
}
V_188 = V_203 -> V_213 ;
F_3 ( F_132 ( V_188 ) ) ;
if ( F_133 ( V_226 ) )
F_134 ( V_188 ) ;
V_33 = F_20 ( V_10 ) ;
if ( F_126 ( ( V_188 -> V_210 != V_10 -> V_227 ) ||
( F_135 ( V_188 ) > V_33 ) ) ) {
F_22 ( V_209 , L_21 ) ;
V_31 = 1 ;
goto V_164;
}
V_224 = F_30 ( V_23 , V_33 - 1 ) ;
if ( V_222 -> V_225 ) {
if ( V_224 < V_222 -> V_135 ) {
F_22 ( V_209 ,
L_22 ,
V_188 -> V_210 , V_222 -> V_135 , V_224 ) ;
V_31 = - V_228 ;
goto V_164;
}
}
V_87 = F_136 ( V_3 , V_23 , V_222 -> V_135 , V_188 , V_229 ) ;
if ( F_137 ( V_87 ) ) {
V_31 = F_138 ( V_87 ) ;
goto V_164;
}
if ( V_222 -> V_225 ) {
F_139 ( V_188 ) ;
if ( ! F_109 ( V_188 ) ) {
struct V_177 * V_178 = & V_9 -> V_183 . V_185 ;
struct V_192 * V_193 = F_101 ( V_23 , V_87 ) ;
int V_180 = V_69 ;
F_140 ( V_3 , V_9 , V_87 ) ;
F_32 ( V_178 ) ;
F_141 ( V_178 , V_87 ) ;
if ( V_224 == F_102 ( V_193 ) )
V_180 = V_33 & ~ V_114 ;
V_31 = F_104 ( V_3 , V_9 , V_178 , 0 , V_180 ,
F_129 ) ;
F_3 ( F_142 ( V_87 , V_9 ) ) ;
F_111 ( V_3 , V_178 ) ;
V_188 = NULL ;
if ( V_31 < 0 ) {
F_110 ( V_3 , V_9 , V_87 ) ;
F_95 ( V_3 , V_9 , V_87 ) ;
F_42 ( V_3 , V_87 ) ;
if ( V_31 == - V_195 )
V_31 = - V_230 ;
goto V_164;
} else {
F_95 ( V_3 , V_9 , V_87 ) ;
}
}
}
F_3 ( ! V_222 -> V_225 || V_222 -> V_135 <= V_224 ) ;
if ( V_222 -> V_135 == V_224 )
V_222 -> V_231 = V_33 - F_131 ( V_23 , V_222 -> V_135 ) ;
else
V_222 -> V_231 = F_143 ( V_23 ) ;
F_144 ( & V_87 -> V_90 , L_5 , V_9 ) ;
V_222 -> V_89 = V_87 ;
V_164:
if ( V_188 )
F_145 ( V_188 ) ;
V_203 -> V_207 &= ~ V_212 ;
return V_31 ;
}
static void F_146 ( const struct V_2 * V_3 ,
const struct V_4 * V_62 )
{
struct V_10 * V_10 = F_10 ( V_62 -> V_71 ) ;
struct V_11 * V_12 = F_6 ( V_10 ) ;
F_26 ( V_3 , V_62 -> V_77 -> V_49 ,
F_27 ( V_62 -> V_77 -> V_49 ) ) ;
F_52 ( & V_12 -> V_160 ) ;
}
static int F_147 ( const struct V_2 * V_3 ,
const struct V_4 * V_62 )
{
return 0 ;
}
static int F_148 ( const struct V_2 * V_3 ,
const struct V_4 * V_62 ,
T_4 V_24 , struct V_232 * V_233 )
{
int V_31 = 0 ;
if ( V_62 -> V_77 -> V_14 == V_15 ||
V_62 -> V_77 -> V_14 == V_21 ) {
struct V_1 * V_6 = F_1 ( V_3 , V_62 ) ;
if ( F_126 ( V_6 -> V_50 -> V_51 & V_52 ) ) {
V_233 -> V_234 = V_191 ;
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
V_9 -> V_78 , V_9 -> V_79 ,
V_6 -> V_17 , V_9 -> V_80 ) ;
F_150 ( V_6 , V_7 ) ;
F_151 ( V_9 , & V_6 -> V_7 , V_23 , & V_235 ) ;
V_6 -> V_169 = false ;
V_31 = 0 ;
if ( V_9 -> V_14 == V_15 || V_9 -> V_14 == V_16 ) {
T_2 V_25 ;
struct V_11 * V_12 = F_6 ( V_10 ) ;
V_25 = V_9 -> V_63 . V_125 . V_126 ;
if ( V_25 == 0 )
V_31 = 1 ;
else
V_6 -> V_124 = V_25 ;
F_152 ( V_12 -> V_236 ) ;
} else if ( V_9 -> V_14 == V_237 ) {
if ( ! F_63 ( V_9 ) )
V_9 -> V_238 = V_239 ;
}
if ( V_9 -> V_14 == V_240 && ! V_9 -> V_79 )
V_9 -> V_78 = 1 ;
if ( V_31 == 0 && ! V_9 -> V_78 ) {
V_31 = F_38 ( V_10 , & V_6 -> V_17 ) ;
if ( V_31 == - V_241 )
V_31 = 0 ;
if ( V_31 < 0 )
F_128 ( L_23 V_38 L_24 ,
F_115 ( V_10 -> V_196 , NULL , 0 ) ,
F_23 ( F_24 ( & V_23 -> V_39 ) ) , V_31 ) ;
}
return V_31 ;
}
