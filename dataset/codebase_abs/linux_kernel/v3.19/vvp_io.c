int F_1 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_7 == V_8 || V_4 -> V_7 == V_9 ) ;
return V_6 -> V_10 == V_11 ;
}
static bool F_4 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_12 * V_12 )
{
struct V_13 * V_14 = F_5 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_2 ) ;
bool V_17 = true ;
switch ( V_4 -> V_7 ) {
case V_8 :
case V_9 :
if ( F_7 ( V_14 ) != V_16 -> V_18 ) {
V_4 -> V_19 = 1 ;
V_4 -> V_20 = 0 ;
V_17 = false ;
}
case V_21 :
default:
break;
}
return V_17 ;
}
static int F_8 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_5 * V_6 = F_9 ( V_2 , V_23 ) ;
struct V_12 * V_12 = F_10 ( V_23 -> V_24 ) ;
F_3 ( V_12 ==
F_11 ( F_12 ( V_2 , V_23 ) -> V_25 -> V_26 ) ) ;
V_6 -> V_27 . V_28 . V_29 = F_13 ( V_12 -> V_30 ) ;
return 0 ;
}
static void F_14 ( const struct V_1 * V_2 , const struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_31 ;
struct V_32 * V_33 = V_4 -> V_34 ;
struct V_15 * V_16 = F_12 ( V_2 , V_23 ) ;
F_15 ( V_2 , V_33 , F_16 ( V_33 ) ) ;
F_17 ( V_35 , V_36
L_1 ,
F_18 ( F_19 ( & V_33 -> V_37 ) ) ,
V_4 -> V_38 , V_4 -> V_39 ,
V_16 -> V_18 , V_4 -> V_40 ) ;
if ( V_4 -> V_40 == 1 ) {
int V_17 ;
V_17 = F_20 ( F_10 ( V_33 ) ) ;
if ( V_17 == 0 ) {
V_4 -> V_40 = 0 ;
V_4 -> V_19 = 1 ;
V_4 -> V_39 = 1 ;
} else {
V_4 -> V_40 = 1 ;
V_4 -> V_19 = 0 ;
V_4 -> V_39 = 0 ;
V_4 -> V_41 = V_17 ;
}
}
if ( ! V_4 -> V_38 && V_4 -> V_39 ) {
T_1 V_42 = 0 ;
F_21 ( F_10 ( V_33 ) , & V_42 ) ;
V_4 -> V_19 = V_16 -> V_18 != V_42 ;
if ( V_4 -> V_19 ) {
F_17 ( V_35 ,
V_36 L_2 ,
F_18 ( F_19 ( & V_33 -> V_37 ) ) ,
V_16 -> V_18 , V_42 ) ;
F_5 ( F_10 ( V_33 ) ) -> V_43 &=
~ V_44 ;
}
}
}
static void F_22 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_31 ;
struct V_45 * V_46 = V_4 -> V_27 . V_47 . V_48 ;
F_15 ( V_2 , V_4 -> V_34 , F_16 ( V_4 -> V_34 ) ) ;
if ( V_46 != NULL ) {
F_23 ( & V_46 -> V_49 , L_3 , V_4 ) ;
F_24 ( V_2 , V_46 ) ;
V_4 -> V_27 . V_47 . V_48 = NULL ;
}
F_14 ( V_2 , V_23 ) ;
}
static enum V_50 F_25 ( struct V_51 * V_52 )
{
if ( ( V_52 -> V_53 & V_54 ) && ( V_52 -> V_53 & V_55 ) )
return V_56 ;
return V_57 ;
}
static int F_26 ( const struct V_1 * V_2 ,
struct V_15 * V_6 , struct V_3 * V_4 )
{
struct V_58 * V_59 = F_27 ( V_2 ) ;
struct V_60 * V_61 = V_62 -> V_61 ;
struct V_51 * V_52 ;
struct V_63 * V_64 = & V_59 -> V_65 ;
T_2 V_66 ;
unsigned long V_67 ;
T_3 V_68 ;
int V_69 ;
struct V_70 V_71 ;
struct V_72 V_73 ;
F_3 ( V_4 -> V_7 == V_8 || V_4 -> V_7 == V_9 ) ;
if ( ! F_1 ( V_2 , V_4 ) )
return 0 ;
if ( V_6 -> V_74 == NULL )
return 0 ;
if ( V_61 == NULL )
return 0 ;
F_28 (iov, i, *(vio->cui_iter)) {
V_67 = ( unsigned long ) V_73 . V_75 ;
V_68 = V_73 . V_76 ;
if ( V_68 == 0 )
continue;
V_68 += V_67 & ( ~ V_77 ) ;
V_67 &= V_77 ;
F_29 ( & V_61 -> V_78 ) ;
while ( ( V_52 = F_30 ( V_61 , V_67 , V_68 ) ) != NULL ) {
struct V_12 * V_12 = F_11 ( V_52 -> V_79 ) ;
int V_80 = V_81 ;
if ( F_31 ( V_52 -> V_79 ) ) {
V_80 = V_82 ;
}
F_32 ( & V_66 , V_52 , V_67 , V_68 ) ;
V_64 -> V_83 = F_25 ( V_52 ) ;
V_64 -> V_84 = F_5 ( V_12 ) -> V_85 ;
V_64 -> V_86 = F_33 ( V_64 -> V_84 ,
V_66 . V_87 . V_88 ) ;
V_64 -> V_89 = F_33 ( V_64 -> V_84 ,
V_66 . V_87 . V_90 ) ;
V_64 -> V_91 = V_80 ;
V_69 = F_34 ( V_2 , V_4 , V_64 ) ;
F_17 ( V_35 , L_4 ,
V_64 -> V_83 , V_64 -> V_86 ,
V_64 -> V_89 ) ;
if ( V_69 < 0 ) {
F_35 ( & V_61 -> V_78 ) ;
return V_69 ;
}
if ( V_52 -> V_92 - V_67 >= V_68 )
break;
V_68 -= V_52 -> V_92 - V_67 ;
V_67 = V_52 -> V_92 ;
}
F_35 ( & V_61 -> V_78 ) ;
}
return 0 ;
}
static int F_36 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_50 V_93 , T_4 V_88 , T_4 V_90 )
{
struct V_15 * V_16 = F_6 ( V_2 ) ;
int V_69 ;
int V_94 = 0 ;
F_3 ( V_4 -> V_7 == V_8 || V_4 -> V_7 == V_9 ) ;
F_37 ( V_2 , V_16 , V_4 ) ;
if ( V_4 -> V_27 . V_95 . V_96 )
V_94 |= V_97 ;
V_69 = F_26 ( V_2 , V_16 , V_4 ) ;
if ( V_69 == 0 )
V_69 = F_38 ( V_2 , V_4 , V_94 , V_93 , V_88 , V_90 ) ;
return V_69 ;
}
static int F_39 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_31 ;
struct V_13 * V_14 = F_5 ( F_10 ( V_4 -> V_34 ) ) ;
int V_69 ;
if ( V_14 -> V_98 )
V_69 = F_36 ( V_2 , V_4 , V_57 ,
V_4 -> V_27 . V_99 . V_100 . V_101 ,
V_4 -> V_27 . V_99 . V_100 . V_101 +
V_4 -> V_27 . V_99 . V_100 . V_102 - 1 ) ;
else
V_69 = 0 ;
return V_69 ;
}
static int F_40 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_31 ;
struct V_5 * V_6 = F_9 ( V_2 , V_23 ) ;
return F_41
( V_2 , V_4 , 0 , F_25 ( V_6 -> V_27 . V_28 . V_103 ) ,
V_4 -> V_27 . V_47 . V_104 , V_4 -> V_27 . V_47 . V_104 ) ;
}
static int F_42 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_31 ;
T_4 V_88 ;
T_4 V_90 ;
if ( V_4 -> V_27 . V_105 . V_106 ) {
V_88 = 0 ;
V_90 = V_107 ;
} else {
V_88 = V_4 -> V_27 . V_105 . V_108 . V_101 ;
V_90 = V_88 + V_4 -> V_27 . V_105 . V_108 . V_102 - 1 ;
}
return F_36 ( V_2 , V_4 , V_56 , V_88 , V_90 ) ;
}
static int F_43 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
return 0 ;
}
static int F_44 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_15 * V_16 = F_6 ( V_2 ) ;
struct V_3 * V_4 = V_23 -> V_31 ;
T_5 V_109 ;
T_1 V_110 = 0 ;
if ( F_45 ( V_4 ) ) {
V_109 = V_4 -> V_27 . V_111 . V_112 . V_113 ;
if ( V_109 == 0 )
V_110 = V_114 ;
} else {
if ( ( V_4 -> V_27 . V_111 . V_112 . V_115 >=
V_4 -> V_27 . V_111 . V_112 . V_116 ) ||
( V_4 -> V_27 . V_111 . V_112 . V_117 >=
V_4 -> V_27 . V_111 . V_112 . V_116 ) )
return 0 ;
V_109 = 0 ;
}
V_16 -> V_27 . V_118 . V_119 = V_120 ;
return F_38 ( V_2 , V_4 , V_110 , V_56 ,
V_109 , V_107 ) ;
}
static int F_46 ( struct V_12 * V_12 , T_6 V_121 )
{
int V_69 ;
F_47 ( V_12 ) ;
V_69 = F_48 ( V_12 , V_121 ) ;
if ( V_69 < 0 ) {
F_49 ( V_12 ) ;
return V_69 ;
}
F_50 ( V_12 , V_121 ) ;
F_49 ( V_12 ) ;
return V_69 ;
}
static int F_51 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 ,
struct V_12 * V_12 , T_4 V_121 )
{
F_52 ( V_12 ) ;
return 0 ;
}
static int F_53 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_31 ;
struct V_32 * V_33 = V_4 -> V_34 ;
struct V_122 * V_123 = F_54 ( V_2 ) ;
int V_69 ;
unsigned V_124 = V_125 ;
F_55 ( V_33 ) ;
V_123 -> V_126 = V_4 -> V_27 . V_111 . V_112 . V_116 ;
if ( V_4 -> V_27 . V_111 . V_127 & V_128 ) {
V_123 -> V_129 = V_4 -> V_27 . V_111 . V_112 . V_117 ;
V_124 |= V_130 ;
}
if ( V_4 -> V_27 . V_111 . V_127 & V_131 ) {
V_123 -> V_132 = V_4 -> V_27 . V_111 . V_112 . V_115 ;
V_124 |= V_133 ;
}
V_69 = F_56 ( V_2 , V_33 , V_123 , V_124 ) ;
F_57 ( V_33 ) ;
return V_69 ;
}
static int F_58 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_31 ;
struct V_12 * V_12 = F_10 ( V_4 -> V_34 ) ;
int V_69 = 0 ;
F_59 ( & V_12 -> V_134 ) ;
if ( F_45 ( V_4 ) )
V_69 = F_51 ( V_2 , V_23 , V_12 ,
V_4 -> V_27 . V_111 . V_112 . V_113 ) ;
if ( V_69 == 0 )
V_69 = F_53 ( V_2 , V_23 ) ;
return V_69 ;
}
static void F_60 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_31 ;
struct V_12 * V_12 = F_10 ( V_4 -> V_34 ) ;
if ( F_45 ( V_4 ) ) {
F_46 ( V_12 , V_4 -> V_27 . V_111 . V_112 . V_113 ) ;
F_61 ( V_12 ) ;
}
F_62 ( & V_12 -> V_134 ) ;
}
static void F_63 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
F_14 ( V_2 , V_23 ) ;
}
static int F_64 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_5 * V_6 = F_9 ( V_2 , V_23 ) ;
struct V_15 * V_16 = F_12 ( V_2 , V_23 ) ;
struct V_3 * V_4 = V_23 -> V_31 ;
struct V_32 * V_33 = V_4 -> V_34 ;
struct V_12 * V_12 = F_10 ( V_33 ) ;
struct V_135 * V_136 = & V_6 -> V_137 ;
struct V_138 * V_138 = V_16 -> V_25 -> V_26 ;
int V_69 ;
T_4 V_139 = V_4 -> V_27 . V_99 . V_100 . V_101 ;
long V_140 = V_4 -> V_27 . V_99 . V_100 . V_102 ;
long V_141 = V_16 -> V_142 ;
int V_143 = 0 ;
F_15 ( V_2 , V_33 , F_16 ( V_33 ) ) ;
F_17 ( V_35 , L_5 , V_139 , V_139 + V_140 ) ;
if ( ! F_4 ( V_2 , V_4 , V_12 ) )
return 0 ;
V_69 = F_65 ( V_2 , V_33 , V_4 , V_139 , V_141 , & V_143 ) ;
if ( V_69 != 0 )
return V_69 ;
else if ( V_143 != 0 )
goto V_144;
F_66 ( V_145 , V_2 , & V_33 -> V_37 ,
L_6 ,
V_12 -> V_146 , V_140 , V_139 , F_67 ( V_12 ) ) ;
V_16 -> V_25 -> V_26 -> V_147 . V_148 = 0 ;
if ( ! V_6 -> V_149 ) {
V_6 -> V_149 = 1 ;
V_136 -> V_150 = F_33 ( V_33 , V_139 ) ;
V_136 -> V_151 = F_33 ( V_33 , V_141 + V_152 - 1 ) ;
F_68 ( V_138 , V_136 ) ;
}
F_69 ( V_138 ) ;
switch ( V_6 -> V_10 ) {
case V_11 :
F_3 ( V_16 -> V_153 -> V_154 == V_139 ) ;
V_69 = F_70 ( V_16 -> V_153 , V_16 -> V_74 ) ;
break;
case V_155 :
V_69 = F_71 ( V_138 , & V_139 ,
V_6 -> V_27 . V_156 . V_157 , V_140 ,
V_6 -> V_27 . V_156 . V_158 ) ;
V_4 -> V_20 = 0 ;
break;
default:
F_72 ( L_7 , V_6 -> V_10 ) ;
F_73 () ;
}
V_144:
if ( V_69 >= 0 ) {
if ( V_69 < V_140 )
V_4 -> V_20 = 0 ;
V_4 -> V_159 += V_69 ;
F_74 ( F_75 ( V_12 ) , V_62 -> V_160 ,
V_16 -> V_25 , V_139 , V_69 , V_161 ) ;
V_69 = 0 ;
}
return V_69 ;
}
static void F_76 ( const struct V_1 * V_2 , const struct V_22 * V_23 )
{
struct V_5 * V_6 = F_9 ( V_2 , V_23 ) ;
struct V_15 * V_16 = F_12 ( V_2 , V_23 ) ;
if ( V_6 -> V_149 )
F_77 ( V_16 -> V_25 -> V_26 , & V_6 -> V_137 ) ;
F_14 ( V_2 , V_23 ) ;
}
static int F_78 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_15 * V_16 = F_12 ( V_2 , V_23 ) ;
struct V_3 * V_4 = V_23 -> V_31 ;
struct V_32 * V_33 = V_4 -> V_34 ;
struct V_12 * V_12 = F_10 ( V_33 ) ;
T_3 V_69 = 0 ;
T_4 V_139 = V_4 -> V_27 . V_105 . V_108 . V_101 ;
T_6 V_140 = V_4 -> V_27 . V_105 . V_108 . V_102 ;
if ( ! F_4 ( V_2 , V_4 , V_12 ) )
return 0 ;
if ( F_79 ( V_4 ) ) {
V_139 = V_4 -> V_27 . V_105 . V_108 . V_101 = F_67 ( V_12 ) ;
V_16 -> V_153 -> V_154 = V_139 ;
} else {
F_3 ( V_16 -> V_153 -> V_154 == V_139 ) ;
}
F_17 ( V_35 , L_8 , V_139 , V_139 + ( long long ) V_140 ) ;
if ( V_16 -> V_74 == NULL )
V_69 = 0 ;
else
V_69 = F_80 ( V_16 -> V_153 , V_16 -> V_74 ) ;
if ( V_69 > 0 ) {
if ( V_69 < V_140 )
V_4 -> V_20 = 0 ;
V_4 -> V_159 += V_69 ;
F_74 ( F_75 ( V_12 ) , V_62 -> V_160 ,
V_16 -> V_25 , V_139 , V_69 , V_162 ) ;
V_69 = 0 ;
}
return V_69 ;
}
static int F_81 ( struct V_163 * V_164 )
{
struct V_165 * V_166 = V_164 -> V_28 . V_167 ;
V_164 -> V_28 . V_168 = F_82 ( V_164 -> V_103 , V_166 ) ;
V_164 -> V_28 . V_169 = 1 ;
if ( V_166 -> V_46 ) {
F_17 ( V_170 ,
L_9 ,
V_166 -> V_46 , V_166 -> V_46 -> V_171 , V_166 -> V_46 -> V_172 ,
( long ) V_166 -> V_46 -> V_80 , F_83 ( V_166 -> V_46 ) ,
F_84 ( V_166 -> V_46 ) , V_166 -> V_173 ) ;
if ( F_85 ( ! ( V_164 -> V_28 . V_168 & V_174 ) ) ) {
F_86 ( V_166 -> V_46 ) ;
V_164 -> V_28 . V_168 |= V_174 ;
}
V_164 -> V_175 = V_166 -> V_46 ;
return 0 ;
}
if ( V_164 -> V_28 . V_168 & ( V_176 | V_177 ) ) {
F_17 ( V_170 , L_10 , V_166 -> V_173 ) ;
return - V_178 ;
}
if ( V_164 -> V_28 . V_168 & V_179 ) {
F_17 ( V_170 , L_11 , V_166 -> V_173 ) ;
return - V_180 ;
}
if ( V_164 -> V_28 . V_168 & V_181 )
return - V_182 ;
F_72 ( L_12 , V_164 -> V_28 . V_168 ) ;
return - V_183 ;
}
static int F_87 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_5 * V_6 = F_9 ( V_2 , V_23 ) ;
struct V_3 * V_4 = V_23 -> V_31 ;
struct V_32 * V_33 = V_4 -> V_34 ;
struct V_12 * V_12 = F_10 ( V_33 ) ;
struct V_184 * V_185 = & V_4 -> V_27 . V_47 ;
struct V_163 * V_164 = & V_6 -> V_27 . V_28 ;
T_4 V_186 ;
int V_69 = 0 ;
struct V_46 * V_187 = NULL ;
struct V_45 * V_46 ;
T_4 V_121 ;
T_7 V_188 ;
if ( V_185 -> V_189 &&
F_13 ( V_12 -> V_30 ) != V_6 -> V_27 . V_28 . V_29 )
F_88 ( L_13 V_36
L_14 ,
F_18 ( F_19 ( & V_33 -> V_37 ) ) ) ;
V_186 = F_89 ( V_33 , V_185 -> V_104 + 1 ) - 1 ;
F_3 ( F_33 ( V_33 , V_186 ) == V_185 -> V_104 ) ;
V_69 = F_65 ( V_2 , V_33 , V_4 , 0 , V_186 + 1 , NULL ) ;
if ( V_69 != 0 )
return V_69 ;
if ( V_185 -> V_190 ) {
F_3 ( V_164 -> V_175 != NULL ) ;
F_86 ( V_164 -> V_175 ) ;
} else {
V_69 = F_81 ( V_164 ) ;
if ( V_69 != 0 )
return V_69 ;
}
V_187 = V_164 -> V_175 ;
F_3 ( F_90 ( V_187 ) ) ;
if ( F_91 ( V_191 ) )
F_92 ( V_187 ) ;
V_121 = F_67 ( V_12 ) ;
if ( F_85 ( ( V_187 -> V_171 != V_12 -> V_192 ) ||
( F_93 ( V_187 ) > V_121 ) ) ) {
F_17 ( V_170 , L_15 ) ;
V_69 = + 1 ;
goto V_144;
}
if ( V_185 -> V_190 ) {
T_7 V_193 ;
V_193 = F_33 ( V_33 , V_121 - 1 ) ;
if ( V_193 < V_185 -> V_104 ) {
F_17 ( V_170 ,
L_16 ,
V_187 -> V_171 , V_185 -> V_104 , V_193 ) ;
V_69 = - V_194 ;
goto V_144;
}
}
V_46 = F_94 ( V_2 , V_33 , V_185 -> V_104 , V_187 , V_195 ) ;
if ( F_95 ( V_46 ) ) {
V_69 = F_96 ( V_46 ) ;
goto V_144;
}
if ( V_185 -> V_190 ) {
F_97 ( V_187 ) ;
if ( F_98 ( V_187 ) ) {
struct V_196 * V_197 ;
F_99 ( V_2 , V_4 , V_46 ) ;
V_197 = F_100 ( F_101 ( V_46 , & V_198 ) ) ;
F_102 ( F_103 ( V_33 ) , V_197 ) ;
V_69 = F_104 ( V_2 , V_4 , V_46 , V_199 ) ;
F_3 ( F_105 ( V_46 , V_4 ) ) ;
V_187 = NULL ;
if ( V_69 < 0 ) {
F_106 ( V_2 , V_4 , V_46 ) ;
F_107 ( V_2 , V_4 , V_46 ) ;
F_108 ( V_2 , V_4 , V_46 ) ;
F_24 ( V_2 , V_46 ) ;
if ( V_69 == - V_200 )
V_69 = - V_201 ;
goto V_144;
} else
F_108 ( V_2 , V_4 , V_46 ) ;
}
}
V_188 = F_33 ( V_33 , V_121 - 1 ) ;
F_3 ( ! V_185 -> V_190 || V_185 -> V_104 <= V_188 ) ;
if ( V_185 -> V_104 == V_188 )
V_185 -> V_202 = V_121 - F_89 ( V_33 , V_185 -> V_104 ) ;
else
V_185 -> V_202 = F_109 ( V_33 ) ;
F_110 ( & V_46 -> V_49 , L_3 , V_4 ) ;
V_185 -> V_48 = V_46 ;
V_144:
if ( V_187 != NULL )
F_111 ( V_187 ) ;
V_164 -> V_28 . V_168 &= ~ V_174 ;
return V_69 ;
}
static int F_112 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
return 0 ;
}
static int F_113 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 ,
const struct V_203 * V_204 )
{
struct V_3 * V_4 = V_23 -> V_31 ;
struct V_32 * V_33 = V_204 -> V_205 ;
struct V_196 * V_197 = F_100 ( V_204 ) ;
struct V_45 * V_46 = V_204 -> V_206 ;
struct V_12 * V_12 = F_10 ( V_33 ) ;
struct V_207 * V_208 = F_75 ( V_12 ) ;
struct V_209 * V_210 = F_12 ( V_2 , V_23 ) -> V_25 ;
struct V_211 * V_212 = & V_210 -> V_213 ;
struct V_46 * V_187 = V_197 -> V_214 ;
struct V_215 * V_216 = & V_4 -> V_217 ;
int V_17 ;
F_15 ( V_2 , V_33 , F_16 ( V_33 ) ) ;
F_3 ( V_204 -> V_205 == V_33 ) ;
if ( V_208 -> V_218 . V_219 &&
V_208 -> V_218 . V_220 )
F_114 ( V_208 , V_12 , V_212 , V_46 -> V_221 ,
V_197 -> V_222 ) ;
V_17 = F_115 ( V_2 , V_4 , V_46 ) ;
if ( V_17 != - V_223 ) {
F_116 ( V_224 , V_2 , V_46 , L_17 ,
V_17 == - V_194 ? L_18 :
L_19 , V_17 ) ;
if ( V_17 != - V_194 )
return V_17 ;
}
if ( V_197 -> V_222 ) {
V_197 -> V_225 = 1 ;
F_117 ( V_2 , V_46 , 1 ) ;
}
F_118 ( V_216 , V_46 ) ;
if ( V_208 -> V_218 . V_219 &&
V_208 -> V_218 . V_220 )
F_119 ( V_2 , V_4 , V_212 ,
V_187 -> V_171 , & V_216 -> V_226 , V_210 -> V_227 ) ;
return 0 ;
}
static int F_120 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_45 * V_46 , struct V_196 * V_197 ,
enum V_228 V_229 )
{
struct V_215 * V_216 ;
int V_69 ;
F_3 ( V_4 -> V_7 == V_8 || V_4 -> V_7 == V_9 ) ;
V_216 = & V_4 -> V_217 ;
F_121 ( V_216 , V_46 ) ;
V_69 = F_122 ( V_2 , V_4 , V_229 , V_216 , 0 ) ;
F_3 ( F_105 ( V_46 , V_4 ) ) ;
if ( V_229 == V_230 )
F_123 ( V_2 , V_4 , & V_216 -> V_226 ) ;
F_124 ( V_2 , V_216 ) ;
return V_69 ;
}
static int F_125 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_32 * V_33 , struct V_45 * V_231 ,
struct V_196 * V_197 ,
unsigned V_232 , unsigned V_233 )
{
struct V_122 * V_123 = F_54 ( V_2 ) ;
T_4 V_186 = F_89 ( V_33 , V_231 -> V_221 ) ;
int V_69 ;
F_55 ( V_33 ) ;
V_69 = F_126 ( V_2 , V_33 , V_123 ) ;
F_57 ( V_33 ) ;
if ( V_69 == 0 ) {
if ( V_123 -> V_234 <= V_186 ) {
char * V_235 = F_127 ( V_197 -> V_214 ) ;
memset ( V_235 , 0 , F_109 ( V_33 ) ) ;
F_128 ( V_235 ) ;
} else if ( V_197 -> V_222 )
V_197 -> V_225 = 1 ;
else
V_69 = F_120 ( V_2 , V_4 , V_231 , V_197 , V_230 ) ;
if ( V_69 == 0 )
F_117 ( V_2 , V_231 , 1 ) ;
}
return V_69 ;
}
static int F_129 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 ,
const struct V_203 * V_204 ,
unsigned V_232 , unsigned V_233 )
{
struct V_32 * V_33 = V_204 -> V_205 ;
struct V_196 * V_197 = F_100 ( V_204 ) ;
struct V_45 * V_231 = V_204 -> V_206 ;
struct V_46 * V_187 = V_197 -> V_214 ;
int V_69 ;
F_130 ( F_131 ( V_2 , V_231 ) ) ;
F_3 ( V_187 -> V_171 -> V_236 == F_10 ( V_33 ) ) ;
V_69 = 0 ;
F_116 ( V_170 , V_2 , V_231 , L_20 , V_232 , V_233 ) ;
if ( ! F_132 ( V_187 ) ) {
if ( V_232 == 0 && V_233 == V_152 ) {
F_116 ( V_170 , V_2 , V_231 , L_21 ) ;
F_133 ( V_46 , 0x11 ) ;
} else
V_69 = F_125 ( V_2 , V_23 -> V_31 , V_33 ,
V_231 , V_197 , V_232 , V_233 ) ;
} else
F_116 ( V_170 , V_2 , V_231 , L_22 ) ;
return V_69 ;
}
static int F_134 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 ,
const struct V_203 * V_204 ,
unsigned V_232 , unsigned V_233 )
{
struct V_32 * V_33 = V_204 -> V_205 ;
struct V_3 * V_4 = V_23 -> V_31 ;
struct V_196 * V_197 = F_100 ( V_204 ) ;
struct V_45 * V_231 = V_204 -> V_206 ;
struct V_12 * V_12 = F_10 ( V_33 ) ;
struct V_207 * V_208 = F_75 ( V_12 ) ;
struct V_13 * V_14 = F_5 ( V_12 ) ;
struct V_46 * V_187 = V_197 -> V_214 ;
int V_69 ;
int V_237 ;
T_4 V_121 ;
F_130 ( F_131 ( V_2 , V_231 ) ) ;
F_3 ( V_187 -> V_171 -> V_236 == V_12 ) ;
F_66 ( V_145 , V_2 , & V_33 -> V_37 , L_23 ) ;
F_116 ( V_170 , V_2 , V_231 , L_24 , V_232 , V_233 ) ;
if ( ! F_135 ( V_187 ) ) {
V_237 = V_238 ;
V_69 = F_104 ( V_2 , V_4 , V_231 , V_199 ) ;
if ( V_69 == 0 ) {
F_98 ( V_187 ) ;
F_102 ( F_103 ( V_33 ) , V_197 ) ;
} else if ( V_69 == - V_200 ) {
T_7 V_193 = F_67 ( V_12 ) >> V_239 ;
bool V_240 = true ;
if ( V_193 > V_231 -> V_221 ) {
V_233 = V_152 ;
V_240 = false ;
} else if ( V_193 == V_231 -> V_221 ) {
int V_241 = F_67 ( V_12 ) & ~ V_77 ;
if ( V_233 < V_241 )
V_233 = V_241 ;
}
if ( V_240 )
F_136 ( V_2 , V_231 , 0 , V_233 ) ;
V_69 = F_120 ( V_2 , V_4 , V_231 , V_197 , V_199 ) ;
if ( V_69 )
F_72 ( L_25 ,
V_231 -> V_221 , V_12 , V_69 ) ;
}
} else {
V_237 = V_242 ;
V_69 = 0 ;
}
F_137 ( V_208 , V_237 , 1 ) ;
if ( V_69 == 0 ) {
F_138 ( & V_14 -> V_243 ) ;
V_14 -> V_43 |= V_244 ;
F_139 ( & V_14 -> V_243 ) ;
}
V_121 = F_89 ( V_33 , V_231 -> V_221 ) + V_233 ;
F_47 ( V_12 ) ;
if ( V_69 == 0 ) {
if ( V_121 > F_67 ( V_12 ) ) {
F_140 ( V_12 , V_121 ) ;
F_17 ( V_35 , V_36 L_26 ,
F_18 ( F_19 ( & V_33 -> V_37 ) ) ,
( unsigned long ) V_121 ) ;
}
F_117 ( V_2 , V_231 , 1 ) ;
} else {
if ( V_121 > F_67 ( V_12 ) )
F_107 ( V_2 , V_4 , V_231 ) ;
}
F_49 ( V_12 ) ;
return V_69 ;
}
int F_141 ( const struct V_1 * V_2 , struct V_32 * V_33 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_15 * V_16 = F_6 ( V_2 ) ;
struct V_12 * V_12 = F_10 ( V_33 ) ;
int V_69 ;
F_15 ( V_2 , V_33 , F_16 ( V_33 ) ) ;
F_17 ( V_35 , V_36
L_1 ,
F_18 ( F_19 ( & V_33 -> V_37 ) ) ,
V_4 -> V_38 , V_4 -> V_39 ,
V_16 -> V_18 , V_4 -> V_40 ) ;
F_142 ( V_16 , V_245 ) ;
F_143 ( V_4 , & V_16 -> V_245 , V_33 , & V_246 ) ;
V_6 -> V_149 = 0 ;
V_69 = 0 ;
if ( V_4 -> V_7 == V_8 || V_4 -> V_7 == V_9 ) {
T_6 V_68 ;
struct V_13 * V_14 = F_5 ( V_12 ) ;
V_68 = V_4 -> V_27 . V_95 . V_102 ;
if ( V_68 == 0 )
V_69 = 1 ;
else
V_16 -> V_142 = V_68 ;
F_144 ( V_14 -> V_247 ) ;
} else if ( V_4 -> V_7 == V_248 ) {
if ( ! F_45 ( V_4 ) )
V_4 -> V_249 = V_250 ;
}
if ( V_4 -> V_7 == V_251 && ! V_4 -> V_39 )
V_4 -> V_38 = 1 ;
if ( V_69 == 0 && ! V_4 -> V_38 ) {
V_69 = F_21 ( V_12 , & V_16 -> V_18 ) ;
if ( V_69 == - V_252 )
V_69 = 0 ;
if ( V_69 < 0 )
F_72 ( L_27 V_36 L_28 ,
F_145 ( V_12 -> V_253 , NULL , 0 ) ,
F_18 ( F_19 ( & V_33 -> V_37 ) ) , V_69 ) ;
}
return V_69 ;
}
static struct V_5 * F_9 ( const struct V_1 * V_2 ,
const struct V_22 * V_204 )
{
F_12 ( V_2 , V_204 ) ;
return F_2 ( V_2 ) ;
}
