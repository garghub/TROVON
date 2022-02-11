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
if ( V_14 -> V_18 != V_16 -> V_19 ) {
V_4 -> V_20 = 1 ;
V_4 -> V_21 = 0 ;
V_17 = false ;
}
case V_22 :
default:
break;
}
return V_17 ;
}
static int F_7 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_5 * V_6 = F_8 ( V_2 , V_24 ) ;
struct V_12 * V_12 = F_9 ( V_24 -> V_25 ) ;
F_3 ( V_12 ==
F_10 ( V_2 , V_24 ) -> V_26 -> V_27 -> V_28 -> V_29 ) ;
V_6 -> V_30 . V_31 . V_32 = F_11 ( V_12 -> V_33 ) ;
return 0 ;
}
static void F_12 ( const struct V_1 * V_2 , const struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_35 * V_36 = V_4 -> V_37 ;
struct V_15 * V_16 = F_10 ( V_2 , V_24 ) ;
F_13 ( V_2 , V_36 , F_14 ( V_36 ) ) ;
F_15 ( V_38 , V_39
L_1 ,
F_16 ( F_17 ( & V_36 -> V_40 ) ) ,
V_4 -> V_41 , V_4 -> V_42 ,
V_16 -> V_19 , V_4 -> V_43 ) ;
if ( V_4 -> V_43 == 1 ) {
int V_17 ;
V_17 = F_18 ( F_9 ( V_36 ) ) ;
if ( V_17 == 0 ) {
V_4 -> V_43 = 0 ;
V_4 -> V_20 = 1 ;
V_4 -> V_42 = 1 ;
} else {
V_4 -> V_43 = 1 ;
V_4 -> V_20 = 0 ;
V_4 -> V_42 = 0 ;
V_4 -> V_44 = V_17 ;
}
}
if ( ! V_4 -> V_41 && V_4 -> V_42 ) {
T_1 V_45 = 0 ;
F_19 ( F_9 ( V_36 ) , & V_45 ) ;
V_4 -> V_20 = V_16 -> V_19 != V_45 ;
if ( V_4 -> V_20 ) {
F_15 ( V_38 ,
V_39 L_2 ,
F_16 ( F_17 ( & V_36 -> V_40 ) ) ,
V_16 -> V_19 , V_45 ) ;
F_5 ( F_9 ( V_36 ) ) -> V_46 &=
~ V_47 ;
}
}
}
static void F_20 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_48 * V_49 = V_4 -> V_30 . V_50 . V_51 ;
F_13 ( V_2 , V_4 -> V_37 , F_14 ( V_4 -> V_37 ) ) ;
if ( V_49 != NULL ) {
F_21 ( & V_49 -> V_52 , L_3 , V_4 ) ;
F_22 ( V_2 , V_49 ) ;
V_4 -> V_30 . V_50 . V_51 = NULL ;
}
F_12 ( V_2 , V_24 ) ;
}
enum V_53 F_23 ( struct V_54 * V_55 )
{
if ( ( V_55 -> V_56 & V_57 ) && ( V_55 -> V_56 & V_58 ) )
return V_59 ;
return V_60 ;
}
static int F_24 ( const struct V_1 * V_2 ,
struct V_15 * V_6 , struct V_3 * V_4 )
{
struct V_61 * V_62 = F_25 ( V_2 ) ;
struct V_63 * V_64 = V_65 -> V_64 ;
struct V_54 * V_55 ;
struct V_66 * V_67 = & V_62 -> V_68 ;
T_2 V_69 ;
unsigned long V_70 ;
unsigned long V_71 ;
T_3 V_72 ;
int V_73 ;
F_3 ( V_4 -> V_7 == V_8 || V_4 -> V_7 == V_9 ) ;
if ( ! F_1 ( V_2 , V_4 ) )
return 0 ;
if ( V_6 -> V_74 == NULL )
return 0 ;
if ( V_64 == NULL )
return 0 ;
for ( V_71 = 0 ; V_71 < V_6 -> V_75 ; V_71 ++ ) {
const struct V_76 * V_77 = & V_6 -> V_74 [ V_71 ] ;
V_70 = ( unsigned long ) V_77 -> V_78 ;
V_72 = V_77 -> V_79 ;
if ( V_72 == 0 )
continue;
V_72 += V_70 & ( ~ V_80 ) ;
V_70 &= V_80 ;
F_26 ( & V_64 -> V_81 ) ;
while( ( V_55 = F_27 ( V_64 , V_70 , V_72 ) ) != NULL ) {
struct V_12 * V_12 = V_55 -> V_82 -> V_28 -> V_29 ;
int V_83 = V_84 ;
if ( F_28 ( V_55 -> V_82 ) ) {
V_83 = V_85 ;
}
F_29 ( & V_69 , V_55 , V_70 , V_72 ) ;
V_67 -> V_86 = F_23 ( V_55 ) ;
V_67 -> V_87 = F_5 ( V_12 ) -> V_88 ;
V_67 -> V_89 = F_30 ( V_67 -> V_87 ,
V_69 . V_90 . V_91 ) ;
V_67 -> V_92 = F_30 ( V_67 -> V_87 ,
V_69 . V_90 . V_93 ) ;
V_67 -> V_94 = V_83 ;
V_73 = F_31 ( V_2 , V_4 , V_67 ) ;
F_15 ( V_38 , L_4 ,
V_67 -> V_86 , V_67 -> V_89 ,
V_67 -> V_92 ) ;
if ( V_73 < 0 )
return V_73 ;
if ( V_55 -> V_95 - V_70 >= V_72 )
break;
V_72 -= V_55 -> V_95 - V_70 ;
V_70 = V_55 -> V_95 ;
}
F_32 ( & V_64 -> V_81 ) ;
}
return 0 ;
}
static int F_33 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_53 V_96 , T_4 V_91 , T_4 V_93 )
{
struct V_15 * V_16 = F_6 ( V_2 ) ;
int V_73 ;
int V_97 = 0 ;
F_3 ( V_4 -> V_7 == V_8 || V_4 -> V_7 == V_9 ) ;
F_34 ( V_2 , V_16 , V_4 ) ;
if ( V_4 -> V_30 . V_98 . V_99 )
V_97 |= V_100 ;
V_73 = F_24 ( V_2 , V_16 , V_4 ) ;
if ( V_73 == 0 )
V_73 = F_35 ( V_2 , V_4 , V_97 , V_96 , V_91 , V_93 ) ;
return V_73 ;
}
static int F_36 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_13 * V_14 = F_5 ( F_9 ( V_4 -> V_37 ) ) ;
int V_73 ;
if ( V_14 -> V_101 )
V_73 = F_33 ( V_2 , V_4 , V_60 ,
V_4 -> V_30 . V_102 . V_103 . V_104 ,
V_4 -> V_30 . V_102 . V_103 . V_104 +
V_4 -> V_30 . V_102 . V_103 . V_105 - 1 ) ;
else
V_73 = 0 ;
return V_73 ;
}
static int F_37 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_5 * V_6 = F_8 ( V_2 , V_24 ) ;
return F_38
( V_2 , V_4 , 0 , F_23 ( V_6 -> V_30 . V_31 . V_106 ) ,
V_4 -> V_30 . V_50 . V_107 , V_4 -> V_30 . V_50 . V_107 ) ;
}
static int F_39 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_34 ;
T_4 V_91 ;
T_4 V_93 ;
if ( V_4 -> V_30 . V_108 . V_109 ) {
V_91 = 0 ;
V_93 = V_110 ;
} else {
V_91 = V_4 -> V_30 . V_108 . V_111 . V_104 ;
V_93 = V_91 + V_4 -> V_30 . V_108 . V_111 . V_105 - 1 ;
}
return F_33 ( V_2 , V_4 , V_59 , V_91 , V_93 ) ;
}
static int F_40 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
return 0 ;
}
static int F_41 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_15 * V_16 = F_6 ( V_2 ) ;
struct V_3 * V_4 = V_24 -> V_34 ;
T_5 V_112 ;
T_1 V_113 = 0 ;
if ( F_42 ( V_4 ) ) {
V_112 = V_4 -> V_30 . V_114 . V_115 . V_116 ;
if ( V_112 == 0 )
V_113 = V_117 ;
} else {
if ( ( V_4 -> V_30 . V_114 . V_115 . V_118 >=
V_4 -> V_30 . V_114 . V_115 . V_119 ) ||
( V_4 -> V_30 . V_114 . V_115 . V_120 >=
V_4 -> V_30 . V_114 . V_115 . V_119 ) )
return 0 ;
V_112 = 0 ;
}
V_16 -> V_30 . V_121 . V_122 = V_123 ;
return F_35 ( V_2 , V_4 , V_113 , V_59 ,
V_112 , V_110 ) ;
}
static int F_43 ( struct V_12 * V_12 , T_6 V_124 )
{
int V_73 ;
F_44 ( V_12 ) ;
V_73 = F_45 ( V_12 , V_124 ) ;
if ( V_73 < 0 ) {
F_46 ( V_12 ) ;
return V_73 ;
}
F_47 ( V_12 , V_124 ) ;
F_46 ( V_12 ) ;
return V_73 ;
}
static int F_48 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 ,
struct V_12 * V_12 , T_4 V_124 )
{
F_49 ( V_12 ) ;
return 0 ;
}
static int F_50 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_35 * V_36 = V_4 -> V_37 ;
struct V_125 * V_126 = F_51 ( V_2 ) ;
int V_73 ;
unsigned V_127 = V_128 ;
F_52 ( V_36 ) ;
V_126 -> V_129 = V_4 -> V_30 . V_114 . V_115 . V_119 ;
if ( V_4 -> V_30 . V_114 . V_130 & V_131 ) {
V_126 -> V_132 = V_4 -> V_30 . V_114 . V_115 . V_120 ;
V_127 |= V_133 ;
}
if ( V_4 -> V_30 . V_114 . V_130 & V_134 ) {
V_126 -> V_135 = V_4 -> V_30 . V_114 . V_115 . V_118 ;
V_127 |= V_136 ;
}
V_73 = F_53 ( V_2 , V_36 , V_126 , V_127 ) ;
F_54 ( V_36 ) ;
return V_73 ;
}
static int F_55 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_12 * V_12 = F_9 ( V_4 -> V_37 ) ;
int V_73 = 0 ;
F_56 ( & V_12 -> V_137 ) ;
if ( F_42 ( V_4 ) )
V_73 = F_48 ( V_2 , V_24 , V_12 ,
V_4 -> V_30 . V_114 . V_115 . V_116 ) ;
if ( V_73 == 0 )
V_73 = F_50 ( V_2 , V_24 ) ;
return V_73 ;
}
static void F_57 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_12 * V_12 = F_9 ( V_4 -> V_37 ) ;
if ( F_42 ( V_4 ) ) {
F_43 ( V_12 , V_4 -> V_30 . V_114 . V_115 . V_116 ) ;
F_58 ( V_12 ) ;
}
F_59 ( & V_12 -> V_137 ) ;
}
static void F_60 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
F_12 ( V_2 , V_24 ) ;
}
static int F_61 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_5 * V_6 = F_8 ( V_2 , V_24 ) ;
struct V_15 * V_16 = F_10 ( V_2 , V_24 ) ;
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_35 * V_36 = V_4 -> V_37 ;
struct V_12 * V_12 = F_9 ( V_36 ) ;
struct V_138 * V_139 = & V_6 -> V_140 ;
struct V_141 * V_141 = V_16 -> V_26 -> V_27 ;
int V_73 ;
T_4 V_142 = V_4 -> V_30 . V_102 . V_103 . V_104 ;
long V_143 = V_4 -> V_30 . V_102 . V_103 . V_105 ;
long V_144 = V_16 -> V_145 ;
int V_146 = 0 ;
F_13 ( V_2 , V_36 , F_14 ( V_36 ) ) ;
F_15 ( V_38 , L_5 , V_142 , V_142 + V_143 ) ;
if ( ! F_4 ( V_2 , V_4 , V_12 ) )
return 0 ;
V_73 = F_62 ( V_2 , V_36 , V_4 , V_142 , V_144 , & V_146 ) ;
if ( V_73 != 0 )
return V_73 ;
else if ( V_146 != 0 )
goto V_147;
F_63 ( V_148 , V_2 , & V_36 -> V_40 ,
L_6 ,
V_12 -> V_149 , V_143 , V_142 , F_64 ( V_12 ) ) ;
V_16 -> V_26 -> V_27 -> V_150 . V_151 = 0 ;
if ( ! V_6 -> V_152 ) {
V_6 -> V_152 = 1 ;
V_139 -> V_153 = F_30 ( V_36 , V_142 ) ;
V_139 -> V_154 = F_30 ( V_36 , V_144 + V_155 - 1 ) ;
F_65 ( V_141 , V_139 ) ;
}
F_66 ( V_141 ) ;
switch ( V_6 -> V_10 ) {
case V_11 :
F_3 ( V_16 -> V_156 -> V_157 == V_142 ) ;
V_73 = F_67 ( V_16 -> V_156 ,
V_16 -> V_74 , V_16 -> V_75 ,
V_16 -> V_156 -> V_157 ) ;
break;
case V_158 :
V_73 = F_68 ( V_141 , & V_142 ,
V_6 -> V_30 . V_159 . V_160 , V_143 ,
V_6 -> V_30 . V_159 . V_161 ) ;
V_4 -> V_21 = 0 ;
break;
default:
F_69 ( L_7 , V_6 -> V_10 ) ;
F_70 () ;
}
V_147:
if ( V_73 >= 0 ) {
if ( V_73 < V_143 )
V_4 -> V_21 = 0 ;
V_4 -> V_162 += V_73 ;
F_71 ( F_72 ( V_12 ) , V_65 -> V_163 ,
V_16 -> V_26 , V_142 , V_73 , V_164 ) ;
V_73 = 0 ;
}
return V_73 ;
}
static void F_73 ( const struct V_1 * V_2 , const struct V_23 * V_24 )
{
struct V_5 * V_6 = F_8 ( V_2 , V_24 ) ;
struct V_15 * V_16 = F_10 ( V_2 , V_24 ) ;
if ( V_6 -> V_152 )
F_74 ( V_16 -> V_26 -> V_27 , & V_6 -> V_140 ) ;
F_12 ( V_2 , V_24 ) ;
}
static int F_75 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_15 * V_16 = F_10 ( V_2 , V_24 ) ;
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_35 * V_36 = V_4 -> V_37 ;
struct V_12 * V_12 = F_9 ( V_36 ) ;
T_3 V_73 = 0 ;
T_4 V_142 = V_4 -> V_30 . V_108 . V_111 . V_104 ;
T_6 V_143 = V_4 -> V_30 . V_108 . V_111 . V_105 ;
if ( ! F_4 ( V_2 , V_4 , V_12 ) )
return 0 ;
if ( F_76 ( V_4 ) ) {
V_142 = V_4 -> V_30 . V_108 . V_111 . V_104 = F_64 ( V_12 ) ;
V_16 -> V_156 -> V_157 = V_142 ;
} else {
F_3 ( V_16 -> V_156 -> V_157 == V_142 ) ;
}
F_15 ( V_38 , L_8 , V_142 , V_142 + ( long long ) V_143 ) ;
if ( V_16 -> V_74 == NULL )
V_73 = 0 ;
else
V_73 = F_77 ( V_16 -> V_156 ,
V_16 -> V_74 , V_16 -> V_75 ,
V_16 -> V_156 -> V_157 ) ;
if ( V_73 > 0 ) {
if ( V_73 < V_143 )
V_4 -> V_21 = 0 ;
V_4 -> V_162 += V_73 ;
F_71 ( F_72 ( V_12 ) , V_65 -> V_163 ,
V_16 -> V_26 , V_142 , V_73 , V_165 ) ;
V_73 = 0 ;
}
return V_73 ;
}
static int F_78 ( struct V_166 * V_167 )
{
struct V_168 * V_169 = V_167 -> V_31 . V_170 ;
V_167 -> V_31 . V_171 = F_79 ( V_167 -> V_106 , V_169 ) ;
if ( V_169 -> V_49 ) {
F_15 ( V_172 ,
L_9 ,
V_169 -> V_49 , V_169 -> V_49 -> V_173 , V_169 -> V_49 -> V_174 ,
( long ) V_169 -> V_49 -> V_83 , F_80 ( V_169 -> V_49 ) ,
F_81 ( V_169 -> V_49 ) , V_169 -> V_175 ) ;
if ( F_82 ( ! ( V_167 -> V_31 . V_171 & V_176 ) ) ) {
F_83 ( V_169 -> V_49 ) ;
V_167 -> V_31 . V_171 &= V_176 ;
}
V_167 -> V_177 = V_169 -> V_49 ;
return 0 ;
}
if ( V_167 -> V_31 . V_171 & V_178 ) {
F_15 ( V_172 , L_10 , V_169 -> V_175 ) ;
return - V_179 ;
}
if ( V_167 -> V_31 . V_171 & V_180 ) {
F_15 ( V_172 , L_11 , V_169 -> V_175 ) ;
return - V_181 ;
}
if ( V_167 -> V_31 . V_171 & V_182 )
return - V_183 ;
F_69 ( L_12 , V_167 -> V_31 . V_171 ) ;
return - V_184 ;
}
static int F_84 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_5 * V_6 = F_8 ( V_2 , V_24 ) ;
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_35 * V_36 = V_4 -> V_37 ;
struct V_12 * V_12 = F_9 ( V_36 ) ;
struct V_185 * V_186 = & V_4 -> V_30 . V_50 ;
struct V_166 * V_167 = & V_6 -> V_30 . V_31 ;
T_4 V_187 ;
int V_73 = 0 ;
struct V_49 * V_188 = NULL ;
struct V_48 * V_49 ;
T_4 V_124 ;
T_7 V_189 ;
if ( V_186 -> V_190 &&
F_11 ( V_12 -> V_33 ) != V_6 -> V_30 . V_31 . V_32 )
F_85 ( L_13 V_39
L_14 ,
F_16 ( F_17 ( & V_36 -> V_40 ) ) ) ;
V_187 = F_86 ( V_36 , V_186 -> V_107 + 1 ) - 1 ;
F_3 ( F_30 ( V_36 , V_187 ) == V_186 -> V_107 ) ;
V_73 = F_62 ( V_2 , V_36 , V_4 , 0 , V_187 + 1 , NULL ) ;
if ( V_73 != 0 )
return V_73 ;
if ( V_186 -> V_191 ) {
F_3 ( V_167 -> V_177 != NULL ) ;
F_83 ( V_167 -> V_177 ) ;
} else {
V_73 = F_78 ( V_167 ) ;
if ( V_73 != 0 )
return V_73 ;
}
V_188 = V_167 -> V_177 ;
F_3 ( F_87 ( V_188 ) ) ;
if ( F_88 ( V_192 ) )
F_89 ( V_188 ) ;
V_124 = F_64 ( V_12 ) ;
if ( F_82 ( ( V_188 -> V_173 != V_12 -> V_193 ) ||
( F_90 ( V_188 ) > V_124 ) ) ) {
F_15 ( V_172 , L_15 ) ;
GOTO ( V_147 , V_73 = + 1 ) ;
}
if ( V_186 -> V_191 ) {
T_7 V_194 ;
V_194 = F_30 ( V_36 , V_124 - 1 ) ;
if ( V_194 < V_186 -> V_107 ) {
F_15 ( V_172 ,
L_16
L_17 ,
V_188 -> V_173 , V_186 -> V_107 , V_194 ) ;
GOTO ( V_147 , V_73 = - V_195 ) ;
}
}
V_49 = F_91 ( V_2 , V_36 , V_186 -> V_107 , V_188 , V_196 ) ;
if ( F_92 ( V_49 ) )
GOTO ( V_147 , V_73 = F_93 ( V_49 ) ) ;
if ( V_186 -> V_191 ) {
F_94 ( V_188 ) ;
if ( F_95 ( V_188 ) ) {
struct V_197 * V_198 ;
F_96 ( V_2 , V_4 , V_49 ) ;
V_198 = F_97 ( F_98 ( V_49 , & V_199 ) ) ;
F_99 ( F_100 ( V_36 ) , V_198 ) ;
V_73 = F_101 ( V_2 , V_4 , V_49 , V_200 ) ;
F_3 ( F_102 ( V_49 , V_4 ) ) ;
V_188 = NULL ;
if ( V_73 < 0 ) {
F_103 ( V_2 , V_4 , V_49 ) ;
F_104 ( V_2 , V_4 , V_49 ) ;
F_105 ( V_2 , V_4 , V_49 ) ;
F_22 ( V_2 , V_49 ) ;
if ( V_73 == - V_201 )
V_73 = - V_202 ;
GOTO ( V_147 , V_73 ) ;
} else
F_105 ( V_2 , V_4 , V_49 ) ;
}
}
V_189 = F_30 ( V_36 , V_124 - 1 ) ;
F_3 ( ! V_186 -> V_191 || V_186 -> V_107 <= V_189 ) ;
if ( V_186 -> V_107 == V_189 )
V_186 -> V_203 = V_124 - F_86 ( V_36 , V_186 -> V_107 ) ;
else
V_186 -> V_203 = F_106 ( V_36 ) ;
F_107 ( & V_49 -> V_52 , L_3 , V_4 ) ;
V_186 -> V_51 = V_49 ;
V_147:
if ( V_188 != NULL )
F_108 ( V_188 ) ;
V_167 -> V_31 . V_171 &= ~ V_176 ;
return V_73 ;
}
static int F_109 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
return 0 ;
}
static int F_110 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 ,
const struct V_204 * V_205 )
{
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_35 * V_36 = V_205 -> V_206 ;
struct V_197 * V_198 = F_97 ( V_205 ) ;
struct V_48 * V_49 = V_205 -> V_207 ;
struct V_12 * V_12 = F_9 ( V_36 ) ;
struct V_208 * V_209 = F_72 ( V_12 ) ;
struct V_210 * V_211 = F_10 ( V_2 , V_24 ) -> V_26 ;
struct V_212 * V_213 = & V_211 -> V_214 ;
struct V_49 * V_188 = V_198 -> V_215 ;
struct V_216 * V_217 = & V_4 -> V_218 ;
int V_17 ;
F_13 ( V_2 , V_36 , F_14 ( V_36 ) ) ;
F_3 ( V_205 -> V_206 == V_36 ) ;
if ( V_209 -> V_219 . V_220 &&
V_209 -> V_219 . V_221 )
F_111 ( V_209 , V_12 , V_213 , V_49 -> V_222 ,
V_198 -> V_223 ) ;
V_17 = F_112 ( V_2 , V_4 , V_49 ) ;
if ( V_17 != - V_224 ) {
F_113 ( V_225 , V_2 , V_49 , L_18 ,
V_17 == - V_195 ? L_19 :
L_20 , V_17 ) ;
if ( V_17 != - V_195 )
return V_17 ;
}
if ( V_198 -> V_223 ) {
V_198 -> V_226 = 1 ;
F_114 ( V_2 , V_49 , 1 ) ;
}
F_115 ( V_217 , V_49 ) ;
if ( V_209 -> V_219 . V_220 &&
V_209 -> V_219 . V_221 )
F_116 ( V_2 , V_4 , V_213 ,
V_188 -> V_173 , & V_217 -> V_227 , V_211 -> V_228 ) ;
return 0 ;
}
static int F_117 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_48 * V_49 , struct V_197 * V_198 ,
enum V_229 V_230 )
{
struct V_216 * V_217 ;
int V_73 ;
F_3 ( V_4 -> V_7 == V_8 || V_4 -> V_7 == V_9 ) ;
V_217 = & V_4 -> V_218 ;
F_118 ( V_217 , V_49 ) ;
V_73 = F_119 ( V_2 , V_4 , V_230 , V_217 , 0 ) ;
F_3 ( F_102 ( V_49 , V_4 ) ) ;
if ( V_230 == V_231 )
F_120 ( V_2 , V_4 , & V_217 -> V_227 ) ;
F_121 ( V_2 , V_217 ) ;
return V_73 ;
}
static int F_122 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_35 * V_36 , struct V_48 * V_232 ,
struct V_197 * V_198 ,
unsigned V_233 , unsigned V_234 )
{
struct V_125 * V_126 = F_51 ( V_2 ) ;
T_4 V_187 = F_86 ( V_36 , V_232 -> V_222 ) ;
int V_73 ;
F_52 ( V_36 ) ;
V_73 = F_123 ( V_2 , V_36 , V_126 ) ;
F_54 ( V_36 ) ;
if ( V_73 == 0 ) {
if ( V_126 -> V_235 <= V_187 ) {
char * V_236 = F_124 ( V_198 -> V_215 ) ;
memset ( V_236 , 0 , F_106 ( V_36 ) ) ;
F_125 ( V_236 ) ;
} else if ( V_198 -> V_223 )
V_198 -> V_226 = 1 ;
else
V_73 = F_117 ( V_2 , V_4 , V_232 , V_198 , V_231 ) ;
if ( V_73 == 0 )
F_114 ( V_2 , V_232 , 1 ) ;
}
return V_73 ;
}
static int F_126 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 ,
const struct V_204 * V_205 ,
unsigned V_233 , unsigned V_234 )
{
struct V_35 * V_36 = V_205 -> V_206 ;
struct V_197 * V_198 = F_97 ( V_205 ) ;
struct V_48 * V_232 = V_205 -> V_207 ;
struct V_49 * V_188 = V_198 -> V_215 ;
int V_73 ;
F_127 ( F_128 ( V_2 , V_232 ) ) ;
F_3 ( V_188 -> V_173 -> V_237 == F_9 ( V_36 ) ) ;
V_73 = 0 ;
F_113 ( V_172 , V_2 , V_232 , L_21 , V_233 , V_234 ) ;
if ( ! F_129 ( V_188 ) ) {
if ( V_233 == 0 && V_234 == V_155 ) {
F_113 ( V_172 , V_2 , V_232 , L_22 ) ;
F_130 ( V_49 , 0x11 ) ;
} else
V_73 = F_122 ( V_2 , V_24 -> V_34 , V_36 ,
V_232 , V_198 , V_233 , V_234 ) ;
} else
F_113 ( V_172 , V_2 , V_232 , L_23 ) ;
return V_73 ;
}
static int F_131 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 ,
const struct V_204 * V_205 ,
unsigned V_233 , unsigned V_234 )
{
struct V_35 * V_36 = V_205 -> V_206 ;
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_197 * V_198 = F_97 ( V_205 ) ;
struct V_48 * V_232 = V_205 -> V_207 ;
struct V_12 * V_12 = F_9 ( V_36 ) ;
struct V_208 * V_209 = F_72 ( V_12 ) ;
struct V_13 * V_14 = F_5 ( V_12 ) ;
struct V_49 * V_188 = V_198 -> V_215 ;
int V_73 ;
int V_238 ;
T_4 V_124 ;
F_127 ( F_128 ( V_2 , V_232 ) ) ;
F_3 ( V_188 -> V_173 -> V_237 == V_12 ) ;
F_63 ( V_148 , V_2 , & V_36 -> V_40 , L_24 ) ;
F_113 ( V_172 , V_2 , V_232 , L_25 , V_233 , V_234 ) ;
if ( ! F_132 ( V_188 ) ) {
V_238 = V_239 ;
V_73 = F_101 ( V_2 , V_4 , V_232 , V_200 ) ;
if ( V_73 == 0 ) {
F_95 ( V_188 ) ;
F_99 ( F_100 ( V_36 ) , V_198 ) ;
} else if ( V_73 == - V_201 ) {
T_7 V_194 = F_64 ( V_12 ) >> V_240 ;
bool V_241 = true ;
if ( V_194 > V_232 -> V_222 ) {
V_234 = V_155 ;
V_241 = false ;
} else if ( V_194 == V_232 -> V_222 ) {
int V_242 = F_64 ( V_12 ) & ~ V_80 ;
if ( V_234 < V_242 )
V_234 = V_242 ;
}
if ( V_241 )
F_133 ( V_2 , V_232 , 0 , V_234 ) ;
V_73 = F_117 ( V_2 , V_4 , V_232 , V_198 , V_200 ) ;
if ( V_73 )
F_69 ( L_26 ,
V_232 -> V_222 , V_12 , V_73 ) ;
}
} else {
V_238 = V_243 ;
V_73 = 0 ;
}
F_134 ( V_209 , V_238 , 1 ) ;
if ( V_73 == 0 ) {
F_135 ( & V_14 -> V_244 ) ;
V_14 -> V_46 |= V_245 ;
F_136 ( & V_14 -> V_244 ) ;
}
V_124 = F_86 ( V_36 , V_232 -> V_222 ) + V_234 ;
F_44 ( V_12 ) ;
if ( V_73 == 0 ) {
if ( V_124 > F_64 ( V_12 ) ) {
F_137 ( V_12 , V_124 ) ;
F_15 ( V_38 , V_39 L_27 ,
F_16 ( F_17 ( & V_36 -> V_40 ) ) ,
( unsigned long ) V_124 ) ;
}
F_114 ( V_2 , V_232 , 1 ) ;
} else {
if ( V_124 > F_64 ( V_12 ) )
F_104 ( V_2 , V_4 , V_232 ) ;
}
F_46 ( V_12 ) ;
return V_73 ;
}
int F_138 ( const struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_15 * V_16 = F_6 ( V_2 ) ;
struct V_12 * V_12 = F_9 ( V_36 ) ;
int V_73 ;
F_13 ( V_2 , V_36 , F_14 ( V_36 ) ) ;
F_15 ( V_38 , V_39
L_1 ,
F_16 ( F_17 ( & V_36 -> V_40 ) ) ,
V_4 -> V_41 , V_4 -> V_42 ,
V_16 -> V_19 , V_4 -> V_43 ) ;
F_139 ( V_16 , V_246 ) ;
F_140 ( V_4 , & V_16 -> V_246 , V_36 , & V_247 ) ;
V_6 -> V_152 = 0 ;
V_73 = 0 ;
if ( V_4 -> V_7 == V_8 || V_4 -> V_7 == V_9 ) {
T_6 V_72 ;
struct V_13 * V_14 = F_5 ( V_12 ) ;
V_72 = V_4 -> V_30 . V_98 . V_105 ;
if ( V_72 == 0 )
V_73 = 1 ;
else {
V_16 -> V_145 = V_72 ;
V_16 -> V_248 = 0 ;
}
F_141 ( V_14 -> V_249 ) ;
} else if ( V_4 -> V_7 == V_250 ) {
if ( ! F_42 ( V_4 ) )
V_4 -> V_251 = V_252 ;
}
if ( V_4 -> V_7 == V_253 && ! V_4 -> V_42 )
V_4 -> V_41 = 1 ;
if ( V_73 == 0 && ! V_4 -> V_41 ) {
V_73 = F_19 ( V_12 , & V_16 -> V_19 ) ;
if ( V_73 == - V_254 )
V_73 = 0 ;
if ( V_73 < 0 )
F_69 ( L_28 V_39 L_29 ,
F_142 ( V_12 -> V_255 , NULL , 0 ) ,
F_16 ( F_17 ( & V_36 -> V_40 ) ) , V_73 ) ;
}
return V_73 ;
}
static struct V_5 * F_8 ( const struct V_1 * V_2 ,
const struct V_23 * V_205 )
{
F_10 ( V_2 , V_205 ) ;
return F_2 ( V_2 ) ;
}
