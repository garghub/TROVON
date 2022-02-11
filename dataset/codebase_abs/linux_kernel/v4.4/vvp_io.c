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
V_6 -> V_27 . V_28 . V_29 = V_12 -> V_30 . V_31 ;
return 0 ;
}
static void F_13 ( const struct V_1 * V_2 , const struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_32 ;
struct V_33 * V_34 = V_4 -> V_35 ;
struct V_15 * V_16 = F_12 ( V_2 , V_23 ) ;
F_14 ( V_2 , V_34 , F_15 ( V_34 ) ) ;
F_16 ( V_36 , V_37
L_1 ,
F_17 ( F_18 ( & V_34 -> V_38 ) ) ,
V_4 -> V_39 , V_4 -> V_40 ,
V_16 -> V_18 , V_4 -> V_41 ) ;
if ( V_4 -> V_41 == 1 ) {
int V_17 ;
V_17 = F_19 ( F_10 ( V_34 ) ) ;
if ( V_17 == 0 ) {
V_4 -> V_41 = 0 ;
V_4 -> V_19 = 1 ;
V_4 -> V_40 = 1 ;
} else {
V_4 -> V_41 = 1 ;
V_4 -> V_19 = 0 ;
V_4 -> V_40 = 0 ;
V_4 -> V_42 = V_17 ;
}
}
if ( ! V_4 -> V_39 && V_4 -> V_40 ) {
T_1 V_43 = 0 ;
F_20 ( F_10 ( V_34 ) , & V_43 ) ;
V_4 -> V_19 = V_16 -> V_18 != V_43 ;
if ( V_4 -> V_19 ) {
F_16 ( V_36 ,
V_37 L_2 ,
F_17 ( F_18 ( & V_34 -> V_38 ) ) ,
V_16 -> V_18 , V_43 ) ;
F_5 ( F_10 ( V_34 ) ) -> V_44 &=
~ V_45 ;
}
}
}
static void F_21 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_32 ;
struct V_46 * V_47 = V_4 -> V_27 . V_48 . V_49 ;
F_14 ( V_2 , V_4 -> V_35 , F_15 ( V_4 -> V_35 ) ) ;
if ( V_47 != NULL ) {
F_22 ( & V_47 -> V_50 , L_3 , V_4 ) ;
F_23 ( V_2 , V_47 ) ;
V_4 -> V_27 . V_48 . V_49 = NULL ;
}
F_13 ( V_2 , V_23 ) ;
}
static enum V_51 F_24 ( struct V_52 * V_53 )
{
if ( ( V_53 -> V_54 & V_55 ) && ( V_53 -> V_54 & V_56 ) )
return V_57 ;
return V_58 ;
}
static int F_25 ( const struct V_1 * V_2 ,
struct V_15 * V_6 , struct V_3 * V_4 )
{
struct V_59 * V_60 = F_26 ( V_2 ) ;
struct V_61 * V_62 = V_63 -> V_62 ;
struct V_52 * V_53 ;
struct V_64 * V_65 = & V_60 -> V_66 ;
T_2 V_67 ;
unsigned long V_68 ;
T_3 V_69 ;
int V_70 ;
struct V_71 V_72 ;
struct V_73 V_74 ;
F_3 ( V_4 -> V_7 == V_8 || V_4 -> V_7 == V_9 ) ;
if ( ! F_1 ( V_2 , V_4 ) )
return 0 ;
if ( V_6 -> V_75 == NULL )
return 0 ;
if ( V_62 == NULL )
return 0 ;
F_27 (iov, i, *(vio->cui_iter)) {
V_68 = ( unsigned long ) V_74 . V_76 ;
V_69 = V_74 . V_77 ;
if ( V_69 == 0 )
continue;
V_69 += V_68 & ( ~ V_78 ) ;
V_68 &= V_78 ;
F_28 ( & V_62 -> V_79 ) ;
while ( ( V_53 = F_29 ( V_62 , V_68 , V_69 ) ) != NULL ) {
struct V_12 * V_12 = F_11 ( V_53 -> V_80 ) ;
int V_81 = V_82 ;
if ( F_30 ( V_53 -> V_80 ) ) {
V_81 = V_83 ;
}
F_31 ( & V_67 , V_53 , V_68 , V_69 ) ;
V_65 -> V_84 = F_24 ( V_53 ) ;
V_65 -> V_85 = F_5 ( V_12 ) -> V_86 ;
V_65 -> V_87 = F_32 ( V_65 -> V_85 ,
V_67 . V_88 . V_89 ) ;
V_65 -> V_90 = F_32 ( V_65 -> V_85 ,
V_67 . V_88 . V_91 ) ;
V_65 -> V_92 = V_81 ;
V_70 = F_33 ( V_2 , V_4 , V_65 ) ;
F_16 ( V_36 , L_4 ,
V_65 -> V_84 , V_65 -> V_87 ,
V_65 -> V_90 ) ;
if ( V_70 < 0 ) {
F_34 ( & V_62 -> V_79 ) ;
return V_70 ;
}
if ( V_53 -> V_93 - V_68 >= V_69 )
break;
V_69 -= V_53 -> V_93 - V_68 ;
V_68 = V_53 -> V_93 ;
}
F_34 ( & V_62 -> V_79 ) ;
}
return 0 ;
}
static int F_35 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_51 V_94 , T_4 V_89 , T_4 V_91 )
{
struct V_15 * V_16 = F_6 ( V_2 ) ;
int V_70 ;
int V_95 = 0 ;
F_3 ( V_4 -> V_7 == V_8 || V_4 -> V_7 == V_9 ) ;
F_36 ( V_2 , V_16 , V_4 ) ;
if ( V_4 -> V_27 . V_96 . V_97 )
V_95 |= V_98 ;
V_70 = F_25 ( V_2 , V_16 , V_4 ) ;
if ( V_70 == 0 )
V_70 = F_37 ( V_2 , V_4 , V_95 , V_94 , V_89 , V_91 ) ;
return V_70 ;
}
static int F_38 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_32 ;
struct V_99 * V_100 = & V_4 -> V_27 . V_101 . V_100 ;
int V_70 ;
V_70 = F_35 ( V_2 , V_4 , V_58 , V_100 -> V_102 ,
V_100 -> V_102 + V_100 -> V_103 - 1 ) ;
return V_70 ;
}
static int F_39 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_32 ;
struct V_5 * V_6 = F_9 ( V_2 , V_23 ) ;
return F_40
( V_2 , V_4 , 0 , F_24 ( V_6 -> V_27 . V_28 . V_104 ) ,
V_4 -> V_27 . V_48 . V_105 , V_4 -> V_27 . V_48 . V_105 ) ;
}
static int F_41 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_32 ;
T_4 V_89 ;
T_4 V_91 ;
if ( V_4 -> V_27 . V_106 . V_107 ) {
V_89 = 0 ;
V_91 = V_108 ;
} else {
V_89 = V_4 -> V_27 . V_106 . V_109 . V_102 ;
V_91 = V_89 + V_4 -> V_27 . V_106 . V_109 . V_103 - 1 ;
}
return F_35 ( V_2 , V_4 , V_57 , V_89 , V_91 ) ;
}
static int F_42 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
return 0 ;
}
static int F_43 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_15 * V_16 = F_6 ( V_2 ) ;
struct V_3 * V_4 = V_23 -> V_32 ;
T_5 V_110 ;
T_1 V_111 = 0 ;
if ( F_44 ( V_4 ) ) {
V_110 = V_4 -> V_27 . V_112 . V_113 . V_114 ;
if ( V_110 == 0 )
V_111 = V_115 ;
} else {
if ( ( V_4 -> V_27 . V_112 . V_113 . V_116 >=
V_4 -> V_27 . V_112 . V_113 . V_117 ) ||
( V_4 -> V_27 . V_112 . V_113 . V_118 >=
V_4 -> V_27 . V_112 . V_113 . V_117 ) )
return 0 ;
V_110 = 0 ;
}
V_16 -> V_27 . V_119 . V_120 = V_121 ;
return F_37 ( V_2 , V_4 , V_111 , V_57 ,
V_110 , V_108 ) ;
}
static int F_45 ( struct V_12 * V_12 , T_6 V_122 )
{
int V_70 ;
F_46 ( V_12 ) ;
V_70 = F_47 ( V_12 , V_122 ) ;
if ( V_70 < 0 ) {
F_48 ( V_12 ) ;
return V_70 ;
}
F_49 ( V_12 , V_122 ) ;
F_48 ( V_12 ) ;
return V_70 ;
}
static int F_50 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 ,
struct V_12 * V_12 , T_4 V_122 )
{
F_51 ( V_12 ) ;
return 0 ;
}
static int F_52 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_32 ;
struct V_33 * V_34 = V_4 -> V_35 ;
struct V_123 * V_124 = F_53 ( V_2 ) ;
int V_70 ;
unsigned V_125 = V_126 ;
F_54 ( V_34 ) ;
V_124 -> V_127 = V_4 -> V_27 . V_112 . V_113 . V_117 ;
if ( V_4 -> V_27 . V_112 . V_128 & V_129 ) {
V_124 -> V_130 = V_4 -> V_27 . V_112 . V_113 . V_118 ;
V_125 |= V_131 ;
}
if ( V_4 -> V_27 . V_112 . V_128 & V_132 ) {
V_124 -> V_133 = V_4 -> V_27 . V_112 . V_113 . V_116 ;
V_125 |= V_134 ;
}
V_70 = F_55 ( V_2 , V_34 , V_124 , V_125 ) ;
F_56 ( V_34 ) ;
return V_70 ;
}
static int F_57 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_32 ;
struct V_12 * V_12 = F_10 ( V_4 -> V_35 ) ;
int V_70 = 0 ;
F_58 ( & V_12 -> V_135 ) ;
if ( F_44 ( V_4 ) )
V_70 = F_50 ( V_2 , V_23 , V_12 ,
V_4 -> V_27 . V_112 . V_113 . V_114 ) ;
if ( V_70 == 0 )
V_70 = F_52 ( V_2 , V_23 ) ;
return V_70 ;
}
static void F_59 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_32 ;
struct V_12 * V_12 = F_10 ( V_4 -> V_35 ) ;
if ( F_44 ( V_4 ) )
F_45 ( V_12 , V_4 -> V_27 . V_112 . V_113 . V_114 ) ;
F_60 ( & V_12 -> V_135 ) ;
}
static void F_61 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
F_13 ( V_2 , V_23 ) ;
}
static int F_62 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_5 * V_6 = F_9 ( V_2 , V_23 ) ;
struct V_15 * V_16 = F_12 ( V_2 , V_23 ) ;
struct V_3 * V_4 = V_23 -> V_32 ;
struct V_33 * V_34 = V_4 -> V_35 ;
struct V_12 * V_12 = F_10 ( V_34 ) ;
struct V_136 * V_137 = & V_6 -> V_138 ;
struct V_139 * V_139 = V_16 -> V_25 -> V_26 ;
int V_70 ;
T_4 V_140 = V_4 -> V_27 . V_101 . V_100 . V_102 ;
long V_141 = V_4 -> V_27 . V_101 . V_100 . V_103 ;
long V_142 = V_16 -> V_143 ;
int V_144 = 0 ;
F_14 ( V_2 , V_34 , F_15 ( V_34 ) ) ;
F_16 ( V_36 , L_5 , V_140 , V_140 + V_141 ) ;
if ( ! F_4 ( V_2 , V_4 , V_12 ) )
return 0 ;
V_70 = F_63 ( V_2 , V_34 , V_4 , V_140 , V_142 , & V_144 ) ;
if ( V_70 != 0 )
return V_70 ;
else if ( V_144 != 0 )
goto V_145;
F_64 ( V_146 , V_2 , & V_34 -> V_38 ,
L_6 ,
V_12 -> V_147 , V_141 , V_140 , F_65 ( V_12 ) ) ;
V_16 -> V_25 -> V_26 -> V_148 . V_149 = 0 ;
if ( ! V_6 -> V_150 ) {
V_6 -> V_150 = 1 ;
V_137 -> V_151 = F_32 ( V_34 , V_140 ) ;
V_137 -> V_152 = F_32 ( V_34 , V_142 + V_153 - 1 ) ;
F_66 ( V_139 , V_137 ) ;
}
F_67 ( V_139 ) ;
switch ( V_6 -> V_10 ) {
case V_11 :
F_3 ( V_16 -> V_154 -> V_155 == V_140 ) ;
V_70 = F_68 ( V_16 -> V_154 , V_16 -> V_75 ) ;
break;
case V_156 :
V_70 = F_69 ( V_139 , & V_140 ,
V_6 -> V_27 . V_157 . V_158 , V_141 ,
V_6 -> V_27 . V_157 . V_159 ) ;
V_4 -> V_20 = 0 ;
break;
default:
F_70 ( L_7 , V_6 -> V_10 ) ;
F_71 () ;
}
V_145:
if ( V_70 >= 0 ) {
if ( V_70 < V_141 )
V_4 -> V_20 = 0 ;
V_4 -> V_160 += V_70 ;
F_72 ( F_73 ( V_12 ) , V_63 -> V_161 ,
V_16 -> V_25 , V_140 , V_70 , V_162 ) ;
V_70 = 0 ;
}
return V_70 ;
}
static void F_74 ( const struct V_1 * V_2 , const struct V_22 * V_23 )
{
struct V_5 * V_6 = F_9 ( V_2 , V_23 ) ;
struct V_15 * V_16 = F_12 ( V_2 , V_23 ) ;
if ( V_6 -> V_150 )
F_75 ( V_16 -> V_25 -> V_26 , & V_6 -> V_138 ) ;
F_13 ( V_2 , V_23 ) ;
}
static int F_76 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_15 * V_16 = F_12 ( V_2 , V_23 ) ;
struct V_3 * V_4 = V_23 -> V_32 ;
struct V_33 * V_34 = V_4 -> V_35 ;
struct V_12 * V_12 = F_10 ( V_34 ) ;
T_3 V_70 = 0 ;
T_4 V_140 = V_4 -> V_27 . V_106 . V_109 . V_102 ;
T_6 V_141 = V_4 -> V_27 . V_106 . V_109 . V_103 ;
if ( ! F_4 ( V_2 , V_4 , V_12 ) )
return 0 ;
if ( F_77 ( V_4 ) ) {
V_140 = V_4 -> V_27 . V_106 . V_109 . V_102 = F_65 ( V_12 ) ;
V_16 -> V_154 -> V_155 = V_140 ;
} else {
F_3 ( V_16 -> V_154 -> V_155 == V_140 ) ;
}
F_16 ( V_36 , L_8 , V_140 , V_140 + ( long long ) V_141 ) ;
if ( V_16 -> V_75 == NULL )
V_70 = 0 ;
else
V_70 = F_78 ( V_16 -> V_154 , V_16 -> V_75 ) ;
if ( V_70 > 0 ) {
if ( V_70 < V_141 )
V_4 -> V_20 = 0 ;
V_4 -> V_160 += V_70 ;
F_72 ( F_73 ( V_12 ) , V_63 -> V_161 ,
V_16 -> V_25 , V_140 , V_70 , V_163 ) ;
V_70 = 0 ;
}
return V_70 ;
}
static int F_79 ( struct V_164 * V_165 )
{
struct V_166 * V_167 = V_165 -> V_28 . V_168 ;
V_165 -> V_28 . V_169 = F_80 ( V_165 -> V_104 , V_167 ) ;
V_165 -> V_28 . V_170 = 1 ;
if ( V_167 -> V_47 ) {
F_16 ( V_171 ,
L_9 ,
V_167 -> V_47 , V_167 -> V_47 -> V_172 , V_167 -> V_47 -> V_173 ,
( long ) V_167 -> V_47 -> V_81 , F_81 ( V_167 -> V_47 ) ,
F_82 ( V_167 -> V_47 ) , V_167 -> V_174 ) ;
if ( F_83 ( ! ( V_165 -> V_28 . V_169 & V_175 ) ) ) {
F_84 ( V_167 -> V_47 ) ;
V_165 -> V_28 . V_169 |= V_175 ;
}
V_165 -> V_176 = V_167 -> V_47 ;
return 0 ;
}
if ( V_165 -> V_28 . V_169 & ( V_177 | V_178 ) ) {
F_16 ( V_171 , L_10 , V_167 -> V_174 ) ;
return - V_179 ;
}
if ( V_165 -> V_28 . V_169 & V_180 ) {
F_16 ( V_171 , L_11 , V_167 -> V_174 ) ;
return - V_181 ;
}
if ( V_165 -> V_28 . V_169 & V_182 )
return - V_183 ;
F_70 ( L_12 , V_165 -> V_28 . V_169 ) ;
return - V_184 ;
}
static int F_85 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_5 * V_6 = F_9 ( V_2 , V_23 ) ;
struct V_3 * V_4 = V_23 -> V_32 ;
struct V_33 * V_34 = V_4 -> V_35 ;
struct V_12 * V_12 = F_10 ( V_34 ) ;
struct V_185 * V_186 = & V_4 -> V_27 . V_48 ;
struct V_164 * V_165 = & V_6 -> V_27 . V_28 ;
T_4 V_187 ;
int V_70 = 0 ;
struct V_47 * V_188 = NULL ;
struct V_46 * V_47 ;
T_4 V_122 ;
T_7 V_189 ;
if ( V_186 -> V_190 &&
V_12 -> V_30 . V_31 != V_6 -> V_27 . V_28 . V_29 )
F_86 ( L_13 V_37
L_14 ,
F_17 ( F_18 ( & V_34 -> V_38 ) ) ) ;
V_187 = F_87 ( V_34 , V_186 -> V_105 + 1 ) - 1 ;
F_3 ( F_32 ( V_34 , V_187 ) == V_186 -> V_105 ) ;
V_70 = F_63 ( V_2 , V_34 , V_4 , 0 , V_187 + 1 , NULL ) ;
if ( V_70 != 0 )
return V_70 ;
if ( V_186 -> V_191 ) {
F_3 ( V_165 -> V_176 != NULL ) ;
F_84 ( V_165 -> V_176 ) ;
} else {
V_70 = F_79 ( V_165 ) ;
if ( V_70 != 0 )
return V_70 ;
}
V_188 = V_165 -> V_176 ;
F_3 ( F_88 ( V_188 ) ) ;
if ( F_89 ( V_192 ) )
F_90 ( V_188 ) ;
V_122 = F_65 ( V_12 ) ;
if ( F_83 ( ( V_188 -> V_172 != V_12 -> V_193 ) ||
( F_91 ( V_188 ) > V_122 ) ) ) {
F_16 ( V_171 , L_15 ) ;
V_70 = 1 ;
goto V_145;
}
if ( V_186 -> V_191 ) {
T_7 V_194 ;
V_194 = F_32 ( V_34 , V_122 - 1 ) ;
if ( V_194 < V_186 -> V_105 ) {
F_16 ( V_171 ,
L_16 ,
V_188 -> V_172 , V_186 -> V_105 , V_194 ) ;
V_70 = - V_195 ;
goto V_145;
}
}
V_47 = F_92 ( V_2 , V_34 , V_186 -> V_105 , V_188 , V_196 ) ;
if ( F_93 ( V_47 ) ) {
V_70 = F_94 ( V_47 ) ;
goto V_145;
}
if ( V_186 -> V_191 ) {
F_95 ( V_188 ) ;
if ( F_96 ( V_188 ) ) {
struct V_197 * V_198 ;
F_97 ( V_2 , V_4 , V_47 ) ;
V_198 = F_98 ( F_99 ( V_47 , & V_199 ) ) ;
F_100 ( F_101 ( V_34 ) , V_198 ) ;
V_70 = F_102 ( V_2 , V_4 , V_47 , V_200 ) ;
F_3 ( F_103 ( V_47 , V_4 ) ) ;
V_188 = NULL ;
if ( V_70 < 0 ) {
F_104 ( V_2 , V_4 , V_47 ) ;
F_105 ( V_2 , V_4 , V_47 ) ;
F_106 ( V_2 , V_4 , V_47 ) ;
F_23 ( V_2 , V_47 ) ;
if ( V_70 == - V_201 )
V_70 = - V_202 ;
goto V_145;
} else
F_106 ( V_2 , V_4 , V_47 ) ;
}
}
V_189 = F_32 ( V_34 , V_122 - 1 ) ;
F_3 ( ! V_186 -> V_191 || V_186 -> V_105 <= V_189 ) ;
if ( V_186 -> V_105 == V_189 )
V_186 -> V_203 = V_122 - F_87 ( V_34 , V_186 -> V_105 ) ;
else
V_186 -> V_203 = F_107 ( V_34 ) ;
F_108 ( & V_47 -> V_50 , L_3 , V_4 ) ;
V_186 -> V_49 = V_47 ;
V_145:
if ( V_188 != NULL )
F_109 ( V_188 ) ;
V_165 -> V_28 . V_169 &= ~ V_175 ;
return V_70 ;
}
static int F_110 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
return 0 ;
}
static int F_111 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 ,
const struct V_204 * V_205 )
{
struct V_3 * V_4 = V_23 -> V_32 ;
struct V_33 * V_34 = V_205 -> V_206 ;
struct V_197 * V_198 = F_98 ( V_205 ) ;
struct V_46 * V_47 = V_205 -> V_207 ;
struct V_12 * V_12 = F_10 ( V_34 ) ;
struct V_208 * V_209 = F_73 ( V_12 ) ;
struct V_210 * V_211 = F_12 ( V_2 , V_23 ) -> V_25 ;
struct V_212 * V_213 = & V_211 -> V_214 ;
struct V_47 * V_188 = V_198 -> V_215 ;
struct V_216 * V_217 = & V_4 -> V_218 ;
int V_17 ;
F_14 ( V_2 , V_34 , F_15 ( V_34 ) ) ;
F_3 ( V_205 -> V_206 == V_34 ) ;
if ( V_209 -> V_219 . V_220 &&
V_209 -> V_219 . V_221 )
F_112 ( V_209 , V_12 , V_213 , V_47 -> V_222 ,
V_198 -> V_223 ) ;
V_17 = F_113 ( V_2 , V_4 , V_47 ) ;
if ( V_17 != - V_224 ) {
F_114 ( V_225 , V_2 , V_47 , L_17 ,
V_17 == - V_195 ? L_18 :
L_19 , V_17 ) ;
if ( V_17 != - V_195 )
return V_17 ;
}
if ( V_198 -> V_223 ) {
V_198 -> V_226 = 1 ;
F_115 ( V_2 , V_47 , 1 ) ;
}
F_116 ( V_217 , V_47 ) ;
if ( V_209 -> V_219 . V_220 &&
V_209 -> V_219 . V_221 )
F_117 ( V_2 , V_4 , V_213 ,
V_188 -> V_172 , & V_217 -> V_227 , V_211 -> V_228 ) ;
return 0 ;
}
static int F_118 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_46 * V_47 , struct V_197 * V_198 ,
enum V_229 V_230 )
{
struct V_216 * V_217 ;
int V_70 ;
F_3 ( V_4 -> V_7 == V_8 || V_4 -> V_7 == V_9 ) ;
V_217 = & V_4 -> V_218 ;
F_119 ( V_217 , V_47 ) ;
V_70 = F_120 ( V_2 , V_4 , V_230 , V_217 , 0 ) ;
F_3 ( F_103 ( V_47 , V_4 ) ) ;
if ( V_230 == V_231 )
F_121 ( V_2 , V_4 , & V_217 -> V_227 ) ;
F_122 ( V_2 , V_217 ) ;
return V_70 ;
}
static int F_123 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_33 * V_34 , struct V_46 * V_232 ,
struct V_197 * V_198 ,
unsigned V_233 , unsigned V_234 )
{
struct V_123 * V_124 = F_53 ( V_2 ) ;
T_4 V_187 = F_87 ( V_34 , V_232 -> V_222 ) ;
int V_70 ;
F_54 ( V_34 ) ;
V_70 = F_124 ( V_2 , V_34 , V_124 ) ;
F_56 ( V_34 ) ;
if ( V_70 == 0 ) {
if ( V_124 -> V_235 <= V_187 ) {
char * V_236 = F_125 ( V_198 -> V_215 ) ;
memset ( V_236 , 0 , F_107 ( V_34 ) ) ;
F_126 ( V_236 ) ;
} else if ( V_198 -> V_223 )
V_198 -> V_226 = 1 ;
else
V_70 = F_118 ( V_2 , V_4 , V_232 , V_198 , V_231 ) ;
if ( V_70 == 0 )
F_115 ( V_2 , V_232 , 1 ) ;
}
return V_70 ;
}
static int F_127 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 ,
const struct V_204 * V_205 ,
unsigned V_233 , unsigned V_234 )
{
struct V_33 * V_34 = V_205 -> V_206 ;
struct V_197 * V_198 = F_98 ( V_205 ) ;
struct V_46 * V_232 = V_205 -> V_207 ;
struct V_47 * V_188 = V_198 -> V_215 ;
int V_70 ;
F_128 ( F_129 ( V_2 , V_232 ) ) ;
F_3 ( V_188 -> V_172 -> V_237 == F_10 ( V_34 ) ) ;
V_70 = 0 ;
F_114 ( V_171 , V_2 , V_232 , L_20 , V_233 , V_234 ) ;
if ( ! F_130 ( V_188 ) ) {
if ( V_233 == 0 && V_234 == V_153 ) {
F_114 ( V_171 , V_2 , V_232 , L_21 ) ;
F_131 ( V_47 , 0x11 ) ;
} else
V_70 = F_123 ( V_2 , V_23 -> V_32 , V_34 ,
V_232 , V_198 , V_233 , V_234 ) ;
} else
F_114 ( V_171 , V_2 , V_232 , L_22 ) ;
return V_70 ;
}
static int F_132 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 ,
const struct V_204 * V_205 ,
unsigned V_233 , unsigned V_234 )
{
struct V_33 * V_34 = V_205 -> V_206 ;
struct V_3 * V_4 = V_23 -> V_32 ;
struct V_197 * V_198 = F_98 ( V_205 ) ;
struct V_46 * V_232 = V_205 -> V_207 ;
struct V_12 * V_12 = F_10 ( V_34 ) ;
struct V_208 * V_209 = F_73 ( V_12 ) ;
struct V_13 * V_14 = F_5 ( V_12 ) ;
struct V_47 * V_188 = V_198 -> V_215 ;
int V_70 ;
int V_238 ;
T_4 V_122 ;
F_128 ( F_129 ( V_2 , V_232 ) ) ;
F_3 ( V_188 -> V_172 -> V_237 == V_12 ) ;
F_64 ( V_146 , V_2 , & V_34 -> V_38 , L_23 ) ;
F_114 ( V_171 , V_2 , V_232 , L_24 , V_233 , V_234 ) ;
if ( ! F_133 ( V_188 ) ) {
V_238 = V_239 ;
V_70 = F_102 ( V_2 , V_4 , V_232 , V_200 ) ;
if ( V_70 == 0 ) {
F_96 ( V_188 ) ;
F_100 ( F_101 ( V_34 ) , V_198 ) ;
} else if ( V_70 == - V_201 ) {
T_7 V_194 = F_65 ( V_12 ) >> V_240 ;
bool V_241 = true ;
if ( V_194 > V_232 -> V_222 ) {
V_234 = V_153 ;
V_241 = false ;
} else if ( V_194 == V_232 -> V_222 ) {
int V_242 = F_65 ( V_12 ) & ~ V_78 ;
if ( V_234 < V_242 )
V_234 = V_242 ;
}
if ( V_241 )
F_134 ( V_2 , V_232 , 0 , V_234 ) ;
V_70 = F_118 ( V_2 , V_4 , V_232 , V_198 , V_200 ) ;
if ( V_70 )
F_70 ( L_25 ,
V_232 -> V_222 , V_12 , V_70 ) ;
}
} else {
V_238 = V_243 ;
V_70 = 0 ;
}
F_135 ( V_209 , V_238 , 1 ) ;
if ( V_70 == 0 ) {
F_136 ( & V_14 -> V_244 ) ;
V_14 -> V_44 |= V_245 ;
F_137 ( & V_14 -> V_244 ) ;
}
V_122 = F_87 ( V_34 , V_232 -> V_222 ) + V_234 ;
F_46 ( V_12 ) ;
if ( V_70 == 0 ) {
if ( V_122 > F_65 ( V_12 ) ) {
F_138 ( V_12 , V_122 ) ;
F_16 ( V_36 , V_37 L_26 ,
F_17 ( F_18 ( & V_34 -> V_38 ) ) ,
( unsigned long ) V_122 ) ;
}
F_115 ( V_2 , V_232 , 1 ) ;
} else {
if ( V_122 > F_65 ( V_12 ) )
F_105 ( V_2 , V_4 , V_232 ) ;
}
F_48 ( V_12 ) ;
return V_70 ;
}
int F_139 ( const struct V_1 * V_2 , struct V_33 * V_34 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_15 * V_16 = F_6 ( V_2 ) ;
struct V_12 * V_12 = F_10 ( V_34 ) ;
int V_70 ;
F_14 ( V_2 , V_34 , F_15 ( V_34 ) ) ;
F_16 ( V_36 , V_37
L_1 ,
F_17 ( F_18 ( & V_34 -> V_38 ) ) ,
V_4 -> V_39 , V_4 -> V_40 ,
V_16 -> V_18 , V_4 -> V_41 ) ;
F_140 ( V_16 , V_246 ) ;
F_141 ( V_4 , & V_16 -> V_246 , V_34 , & V_247 ) ;
V_6 -> V_150 = 0 ;
V_70 = 0 ;
if ( V_4 -> V_7 == V_8 || V_4 -> V_7 == V_9 ) {
T_6 V_69 ;
struct V_13 * V_14 = F_5 ( V_12 ) ;
V_69 = V_4 -> V_27 . V_96 . V_103 ;
if ( V_69 == 0 )
V_70 = 1 ;
else
V_16 -> V_143 = V_69 ;
F_142 ( V_14 -> V_248 ) ;
} else if ( V_4 -> V_7 == V_249 ) {
if ( ! F_44 ( V_4 ) )
V_4 -> V_250 = V_251 ;
}
if ( V_4 -> V_7 == V_252 && ! V_4 -> V_40 )
V_4 -> V_39 = 1 ;
if ( V_70 == 0 && ! V_4 -> V_39 ) {
V_70 = F_20 ( V_12 , & V_16 -> V_18 ) ;
if ( V_70 == - V_253 )
V_70 = 0 ;
if ( V_70 < 0 )
F_70 ( L_27 V_37 L_28 ,
F_143 ( V_12 -> V_254 , NULL , 0 ) ,
F_17 ( F_18 ( & V_34 -> V_38 ) ) , V_70 ) ;
}
return V_70 ;
}
static struct V_5 * F_9 ( const struct V_1 * V_2 ,
const struct V_22 * V_205 )
{
F_12 ( V_2 , V_205 ) ;
return F_2 ( V_2 ) ;
}
