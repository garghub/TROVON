static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_2 V_7 ;
F_2 ( V_4 -> V_8 , V_9 , & V_7 ) ;
if ( V_7 & V_10 )
F_3 ( & V_6 -> V_11 , L_1 ) ;
if ( V_7 & V_12 )
F_4 ( & V_6 -> V_11 , L_2 ) ;
if ( V_7 & V_13 )
F_4 ( & V_6 -> V_11 , L_3 ) ;
if ( V_7 & V_14 )
F_3 ( & V_6 -> V_11 , L_4 ) ;
if ( V_7 & V_15 )
F_3 ( & V_6 -> V_11 , L_5 ) ;
if ( V_7 & V_16 )
F_3 ( & V_6 -> V_11 , L_6 ) ;
if ( V_7 & V_17 )
F_3 ( & V_6 -> V_11 , L_7 ) ;
if ( V_7 & V_18 )
F_3 ( & V_6 -> V_11 , L_8 ) ;
if ( V_7 & V_19 )
F_3 ( & V_6 -> V_11 , L_9 ) ;
if ( V_7 & V_20 )
F_3 ( & V_6 -> V_11 , L_10 ) ;
if ( V_7 & V_21 )
F_3 ( & V_6 -> V_11 , L_11 ) ;
return V_22 ;
}
static int F_5 ( struct V_23 * V_24 , bool V_25 , T_2 V_26 ,
bool V_27 , T_2 V_28 )
{
struct V_3 * V_4 = F_6 ( V_24 ) ;
T_2 V_29 , V_30 = 999 , V_31 , V_32 , V_33 , V_34 , V_35 , V_36 ;
V_31 = V_27 ? 16 : 1 ;
if ( V_27 && V_28 )
goto V_37;
if ( V_26 > 2 * 8 * 256 * V_31 || V_26 < 2 ) {
F_7 ( V_24 -> V_11 , L_12 ,
2 * 8 * 256 * V_31 ) ;
return - V_38 ;
} else if ( V_26 % 2 ) {
F_7 ( V_24 -> V_11 , L_13 ) ;
return - V_38 ;
}
V_26 /= 2 ;
V_29 = V_26 <= 256 * V_31 ? V_39 : V_40 ;
V_34 = ( V_29 ? 1 : 8 ) * 256 * V_31 / 1000 ;
for ( V_35 = 1 ; V_35 <= 256 ; V_35 ++ ) {
for ( V_36 = 1 ; V_36 <= V_31 ; V_36 ++ ) {
V_32 = ( V_29 ? 1 : 8 ) * V_35 * V_36 ;
if ( V_32 == V_26 )
V_33 = 0 ;
else if ( V_32 / V_26 == 1 )
V_33 = V_32 - V_26 ;
else if ( V_26 / V_32 == 1 )
V_33 = V_26 - V_32 ;
else
continue;
V_33 = V_33 * 1000 / V_26 ;
if ( V_33 < V_34 ) {
V_34 = V_33 ;
V_30 = V_35 ;
V_28 = V_36 ;
}
if ( V_34 == 0 )
goto V_41;
}
}
if ( V_30 == 999 ) {
F_7 ( V_24 -> V_11 , L_14 ) ;
return - V_38 ;
}
V_41:
F_8 ( V_4 -> V_8 , F_9 ( V_25 ) ,
V_42 | V_43 ,
V_29 | F_10 ( V_30 ) ) ;
V_37:
if ( V_31 <= 1 )
return 0 ;
F_8 ( V_4 -> V_8 , F_9 ( V_25 ) ,
V_44 , F_11 ( V_28 ) ) ;
return 0 ;
}
static int F_12 ( struct V_23 * V_24 , int V_45 ,
unsigned int V_46 , int V_47 )
{
struct V_3 * V_4 = F_6 ( V_24 ) ;
struct V_48 * V_49 = V_4 -> V_50 ;
bool V_25 = V_45 <= V_51 ;
bool V_52 = V_47 == V_53 ;
T_2 V_26 , V_54 = 0 ;
unsigned long V_55 ;
int V_56 ;
if ( V_46 == V_4 -> V_57 [ V_25 ] && V_47 == V_4 -> V_58 [ V_25 ] )
return 0 ;
V_4 -> V_59 [ V_25 ] = true ;
F_8 ( V_4 -> V_8 , F_9 ( V_25 ) ,
V_60 , V_52 ? 0 : V_60 ) ;
if ( V_52 )
goto V_41;
switch ( V_45 ) {
case V_61 :
case V_62 :
V_49 = V_4 -> V_63 ;
break;
case V_51 :
V_54 |= V_64 ;
case V_65 :
V_54 |= V_66 ;
break;
default:
return - V_38 ;
}
if ( F_13 ( V_49 ) ) {
F_7 ( V_24 -> V_11 , L_15 ,
V_45 % 2 ? L_16 : L_17 ) ;
return F_14 ( V_49 ) ;
}
V_55 = F_15 ( V_49 ) ;
V_26 = V_55 / V_46 ;
if ( V_26 * V_46 > V_55 )
V_56 = V_26 * V_46 - V_55 ;
else if ( V_26 * V_46 < V_55 )
V_56 = V_55 - V_26 * V_46 ;
else
V_56 = 0 ;
if ( V_56 != 0 && V_55 / V_56 < 1000 ) {
F_7 ( V_24 -> V_11 , L_18 ,
V_25 ? 'T' : 'R' ) ;
return - V_38 ;
}
if ( V_26 == 1 && V_49 == V_4 -> V_50 ) {
V_54 |= V_25 ? V_67 : V_68 ;
goto V_41;
} else if ( V_26 < 2 ) {
F_7 ( V_24 -> V_11 , L_18 ,
V_25 ? 'T' : 'R' ) ;
return - V_38 ;
}
V_56 = F_5 ( V_24 , V_25 , V_26 , false , 0 ) ;
if ( V_56 )
return V_56 ;
V_4 -> V_59 [ V_25 ] = false ;
V_41:
V_4 -> V_58 [ V_25 ] = V_47 ;
V_4 -> V_57 [ V_25 ] = V_46 ;
F_8 ( V_4 -> V_8 , V_69 ,
V_25 ? V_64 | V_67 :
V_66 | V_68 , V_54 ) ;
return 0 ;
}
static int F_16 ( struct V_23 * V_24 , bool V_25 , T_2 V_46 )
{
struct V_3 * V_4 = F_6 ( V_24 ) ;
T_2 V_57 = V_4 -> V_57 [ V_25 ] ;
T_2 V_33 , V_26 = V_57 / V_46 ;
int V_56 ;
if ( V_4 -> V_70 || V_4 -> V_71 [ V_25 ] == V_46 )
return 0 ;
if ( V_26 * V_46 > V_57 )
V_33 = V_26 * V_46 - V_57 ;
else if ( V_26 * V_46 < V_57 )
V_33 = V_57 - V_26 * V_46 ;
else
V_33 = 0 ;
if ( V_33 != 0 && V_57 / V_33 < 1000 ) {
F_7 ( V_24 -> V_11 , L_19 ,
V_25 ? 'T' : 'R' ) ;
return - V_38 ;
}
if ( ! V_4 -> V_59 [ V_25 ] && ( V_26 > 16 || V_26 == 0 ) ) {
F_7 ( V_24 -> V_11 , L_20 ) ;
return - V_38 ;
}
V_56 = F_5 ( V_24 , V_25 , V_26 , true ,
V_4 -> V_59 [ V_25 ] ? 0 : V_26 ) ;
if ( V_56 )
return V_56 ;
V_4 -> V_71 [ V_25 ] = V_46 ;
return 0 ;
}
static int F_17 ( struct V_23 * V_24 , T_2 V_72 ,
T_2 V_73 , int V_74 , int V_75 )
{
struct V_3 * V_4 = F_6 ( V_24 ) ;
F_8 ( V_4 -> V_8 , V_76 ,
V_77 , F_18 ( V_74 ) ) ;
F_8 ( V_4 -> V_8 , V_78 ,
V_79 , F_19 ( V_72 ) ) ;
F_8 ( V_4 -> V_8 , V_80 ,
V_81 , F_20 ( V_72 ) ) ;
F_8 ( V_4 -> V_8 , V_82 ,
V_77 , F_18 ( V_74 ) ) ;
F_8 ( V_4 -> V_8 , V_83 ,
V_79 , F_19 ( V_73 ) ) ;
F_8 ( V_4 -> V_8 , V_84 ,
V_81 , F_20 ( V_73 ) ) ;
V_4 -> V_75 = V_75 ;
V_4 -> V_74 = V_74 ;
return 0 ;
}
static int F_21 ( struct V_23 * V_24 , unsigned int V_85 )
{
struct V_3 * V_4 = F_6 ( V_24 ) ;
T_2 V_86 = 0 , V_87 = 0 , V_88 ;
switch ( V_85 & V_89 ) {
case V_90 :
V_86 |= V_91 ;
V_87 |= V_92 | V_93 | V_94 ;
break;
case V_95 :
V_87 |= V_93 | V_94 ;
break;
case V_96 :
V_87 |= V_93 | V_94 | V_97 ;
break;
case V_98 :
V_86 |= V_99 | V_91 ;
V_87 |= V_93 | V_94 ;
break;
case V_100 :
V_86 |= V_99 ;
V_87 |= V_93 | V_94 ;
break;
default:
return - V_38 ;
}
switch ( V_85 & V_101 ) {
case V_102 :
break;
case V_103 :
V_87 ^= V_93 | V_94 ;
break;
case V_104 :
V_87 ^= V_92 ;
break;
case V_105 :
V_87 ^= V_93 | V_94 | V_92 ;
break;
default:
return - V_38 ;
}
V_4 -> V_70 = false ;
switch ( V_85 & V_106 ) {
case V_107 :
V_4 -> V_70 = true ;
break;
case V_108 :
V_87 |= V_109 ;
break;
case V_110 :
V_87 |= V_111 ;
break;
case V_112 :
V_87 |= V_111 | V_109 ;
break;
default:
return - V_38 ;
}
V_88 = V_99 | V_91 ;
F_8 ( V_4 -> V_8 , V_113 , V_88 , V_86 ) ;
F_8 ( V_4 -> V_8 , V_114 , V_88 , V_86 ) ;
V_88 = V_93 | V_94 | V_92 |
V_111 | V_109 | V_97 ;
F_8 ( V_4 -> V_8 , V_76 , V_88 , V_87 ) ;
F_8 ( V_4 -> V_8 , V_82 , V_88 , V_87 ) ;
return 0 ;
}
static int F_22 ( struct V_115 * V_116 ,
struct V_23 * V_24 )
{
struct V_3 * V_4 = F_6 ( V_24 ) ;
int V_56 ;
V_56 = F_23 ( V_4 -> V_117 ) ;
if ( V_56 )
return V_56 ;
if ( ! F_13 ( V_4 -> V_118 ) ) {
V_56 = F_23 ( V_4 -> V_118 ) ;
if ( V_56 )
goto V_119;
}
if ( ! F_13 ( V_4 -> V_50 ) ) {
V_56 = F_23 ( V_4 -> V_50 ) ;
if ( V_56 )
goto V_120;
}
if ( ! F_13 ( V_4 -> V_63 ) ) {
V_56 = F_23 ( V_4 -> V_63 ) ;
if ( V_56 )
goto V_121;
}
if ( ! V_24 -> V_122 ) {
F_8 ( V_4 -> V_8 , V_123 ,
V_124 , V_4 -> V_125 ?
V_124 : 0 ) ;
F_8 ( V_4 -> V_8 , V_76 ,
V_77 , F_18 ( 2 ) ) ;
F_8 ( V_4 -> V_8 , V_82 ,
V_77 , F_18 ( 2 ) ) ;
}
return 0 ;
V_121:
if ( ! F_13 ( V_4 -> V_50 ) )
F_24 ( V_4 -> V_50 ) ;
V_120:
if ( ! F_13 ( V_4 -> V_118 ) )
F_24 ( V_4 -> V_118 ) ;
V_119:
F_24 ( V_4 -> V_117 ) ;
return V_56 ;
}
static int F_25 ( struct V_115 * V_116 ,
struct V_126 * V_127 ,
struct V_23 * V_24 )
{
struct V_3 * V_4 = F_6 ( V_24 ) ;
bool V_25 = V_116 -> V_128 == V_129 ;
T_2 V_130 = F_26 ( V_127 ) ;
T_2 V_131 = F_27 ( V_127 ) ;
T_2 V_132 = F_28 ( V_131 , V_4 -> V_74 ) ;
T_2 V_75 = V_130 ;
T_2 V_133 , V_88 , V_134 ;
int V_56 ;
if ( V_4 -> V_75 )
V_75 = V_4 -> V_75 ;
V_133 = F_29 ( V_127 ) * V_75 * V_4 -> V_74 ;
V_56 = F_16 ( V_24 , V_25 , V_133 ) ;
if ( V_56 )
return V_56 ;
F_8 ( V_4 -> V_8 , F_30 ( V_25 ) ,
V_135 , F_27 ( V_127 ) > 1 ?
V_136 : 0 ) ;
F_8 ( V_4 -> V_8 , F_31 ( V_25 ) ,
V_137 , V_138 ) ;
V_88 = V_137 | V_139 | V_140 |
( V_25 ? V_141 | V_142 : V_143 ) ;
V_134 = F_32 ( V_130 ) | F_33 ( V_4 -> V_144 ) |
( V_25 ? F_34 ( V_132 ) | V_142 : F_35 ( V_132 ) ) ;
F_8 ( V_4 -> V_8 , F_31 ( V_25 ) , V_88 , V_134 ) ;
V_88 = V_145 | ( V_25 ? V_146 : 0 ) ;
V_134 = F_36 ( V_75 , V_130 ) | ( V_25 ? V_146 : 0 ) ;
F_8 ( V_4 -> V_8 , F_30 ( V_25 ) , V_88 , V_134 ) ;
F_8 ( V_4 -> V_8 , V_147 ,
V_148 , F_37 ( V_149 ) ) ;
F_8 ( V_4 -> V_8 , V_150 ,
V_151 , F_38 ( V_149 ) ) ;
return 0 ;
}
static void F_39 ( struct V_115 * V_116 ,
struct V_23 * V_24 )
{
struct V_3 * V_4 = F_6 ( V_24 ) ;
if ( ! F_13 ( V_4 -> V_63 ) )
F_24 ( V_4 -> V_63 ) ;
if ( ! F_13 ( V_4 -> V_50 ) )
F_24 ( V_4 -> V_50 ) ;
if ( ! F_13 ( V_4 -> V_118 ) )
F_24 ( V_4 -> V_118 ) ;
F_24 ( V_4 -> V_117 ) ;
}
static int F_40 ( struct V_115 * V_116 , int V_152 ,
struct V_23 * V_24 )
{
struct V_3 * V_4 = F_6 ( V_24 ) ;
bool V_25 = V_116 -> V_128 == V_129 ;
T_3 V_35 , V_131 = V_116 -> V_153 -> V_131 ;
T_2 V_132 = F_28 ( V_131 , V_4 -> V_74 ) ;
switch ( V_152 ) {
case V_154 :
case V_155 :
case V_156 :
F_8 ( V_4 -> V_8 , F_31 ( V_25 ) ,
V_157 , V_158 ) ;
for ( V_35 = 0 ; V_25 && V_35 < V_131 ; V_35 ++ )
F_41 ( V_4 -> V_8 , V_159 , 0x0 ) ;
F_8 ( V_4 -> V_8 , F_30 ( V_25 ) ,
V_25 ? V_160 : V_161 ,
V_25 ? F_42 ( V_132 ) : F_43 ( V_132 ) ) ;
break;
case V_162 :
case V_163 :
case V_164 :
F_8 ( V_4 -> V_8 , F_30 ( V_25 ) ,
V_25 ? V_160 : V_161 , 0 ) ;
F_8 ( V_4 -> V_8 , F_31 ( V_25 ) ,
V_138 | V_158 , V_138 ) ;
F_8 ( V_4 -> V_8 , F_31 ( V_25 ) ,
V_138 , 0 ) ;
break;
default:
return - V_38 ;
}
return 0 ;
}
static int F_44 ( struct V_23 * V_24 )
{
struct V_3 * V_4 = F_6 ( V_24 ) ;
F_45 ( V_24 , & V_4 -> V_165 ,
& V_4 -> V_166 ) ;
return 0 ;
}
static bool F_46 ( struct V_167 * V_11 , unsigned int V_168 )
{
switch ( V_168 ) {
case V_169 :
case V_69 :
case V_9 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_123 :
case V_113 :
case V_76 :
case V_114 :
case V_82 :
case V_78 :
case V_80 :
case V_83 :
case V_84 :
case V_147 :
case V_150 :
return true ;
default:
return false ;
}
}
static bool F_47 ( struct V_167 * V_11 , unsigned int V_168 )
{
switch ( V_168 ) {
case V_169 :
case V_9 :
case V_171 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
return true ;
default:
return false ;
}
}
static bool F_48 ( struct V_167 * V_11 , unsigned int V_168 )
{
switch ( V_168 ) {
case V_159 :
case V_69 :
case V_170 :
case V_172 :
case V_179 :
case V_180 :
case V_181 :
case V_182 :
case V_183 :
case V_184 :
case V_185 :
case V_123 :
case V_113 :
case V_76 :
case V_114 :
case V_82 :
case V_78 :
case V_80 :
case V_83 :
case V_84 :
case V_147 :
case V_150 :
return true ;
default:
return false ;
}
}
static int F_49 ( struct V_5 * V_6 )
{
struct V_186 * V_187 = V_6 -> V_11 . V_188 ;
struct V_3 * V_4 ;
struct V_189 * V_190 ;
const T_4 * V_191 ;
void T_5 * V_192 ;
int V_1 , V_56 ;
V_4 = F_50 ( & V_6 -> V_11 , sizeof( * V_4 ) , V_193 ) ;
if ( ! V_4 )
return - V_194 ;
V_4 -> V_6 = V_6 ;
strncpy ( V_4 -> V_195 , V_187 -> V_195 , sizeof( V_4 -> V_195 ) - 1 ) ;
V_190 = F_51 ( V_6 , V_196 , 0 ) ;
V_192 = F_52 ( & V_6 -> V_11 , V_190 ) ;
if ( F_13 ( V_192 ) )
return F_14 ( V_192 ) ;
V_4 -> V_8 = F_53 ( & V_6 -> V_11 ,
L_21 , V_192 , & V_197 ) ;
if ( F_13 ( V_4 -> V_8 ) ) {
F_7 ( & V_6 -> V_11 , L_22 ,
F_14 ( V_4 -> V_8 ) ) ;
return F_14 ( V_4 -> V_8 ) ;
}
V_4 -> V_117 = F_54 ( & V_6 -> V_11 , L_21 ) ;
if ( F_13 ( V_4 -> V_117 ) ) {
F_7 ( & V_6 -> V_11 , L_23 ,
F_14 ( V_4 -> V_117 ) ) ;
return F_14 ( V_4 -> V_117 ) ;
}
V_4 -> V_50 = F_54 ( & V_6 -> V_11 , L_16 ) ;
if ( F_13 ( V_4 -> V_50 ) )
F_4 ( & V_6 -> V_11 , L_24 ,
F_14 ( V_4 -> V_50 ) ) ;
V_4 -> V_63 = F_54 ( & V_6 -> V_11 , L_17 ) ;
if ( F_13 ( V_4 -> V_63 ) )
F_4 ( & V_6 -> V_11 , L_25 ,
F_14 ( V_4 -> V_63 ) ) ;
V_4 -> V_118 = F_54 ( & V_6 -> V_11 , L_26 ) ;
if ( F_13 ( V_4 -> V_118 ) )
F_4 ( & V_6 -> V_11 , L_27 ,
F_14 ( V_4 -> V_118 ) ) ;
V_1 = F_55 ( V_6 , 0 ) ;
if ( V_1 < 0 ) {
F_7 ( & V_6 -> V_11 , L_28 , V_6 -> V_195 ) ;
return V_1 ;
}
V_56 = F_56 ( & V_6 -> V_11 , V_1 , F_1 , 0 ,
V_4 -> V_195 , V_4 ) ;
if ( V_56 ) {
F_7 ( & V_6 -> V_11 , L_29 , V_1 ) ;
return V_56 ;
}
V_4 -> V_74 = 2 ;
V_4 -> V_70 = true ;
V_191 = F_57 ( V_187 , L_30 , NULL ) ;
if ( V_191 )
V_4 -> V_144 = F_58 ( V_191 ) ;
else
V_4 -> V_144 = 64 ;
V_4 -> V_165 . V_198 = 16 ;
V_4 -> V_166 . V_198 = 16 ;
V_4 -> V_165 . V_199 = V_190 -> V_200 + V_159 ;
V_4 -> V_166 . V_199 = V_190 -> V_200 + V_169 ;
V_4 -> V_125 =
F_59 ( V_187 , L_31 ) ;
if ( V_4 -> V_125 ) {
V_201 . V_202 = 1 ;
V_201 . V_203 = 1 ;
V_201 . V_204 = 1 ;
}
F_60 ( & V_6 -> V_11 , V_4 ) ;
V_56 = F_41 ( V_4 -> V_8 , V_69 , V_205 ) ;
if ( V_56 ) {
F_7 ( & V_6 -> V_11 , L_32 , V_56 ) ;
return V_56 ;
}
V_56 = F_41 ( V_4 -> V_8 , V_69 , V_206 ) ;
if ( V_56 ) {
F_7 ( & V_6 -> V_11 , L_33 , V_56 ) ;
return V_56 ;
}
V_56 = F_61 ( & V_6 -> V_11 , & V_207 ,
& V_201 , 1 ) ;
if ( V_56 ) {
F_7 ( & V_6 -> V_11 , L_34 , V_56 ) ;
return V_56 ;
}
V_56 = F_62 ( V_6 , V_208 ) ;
if ( V_56 )
F_7 ( & V_6 -> V_11 , L_35 , V_56 ) ;
return V_56 ;
}
static int F_63 ( struct V_167 * V_11 )
{
struct V_3 * V_209 = F_64 ( V_11 ) ;
F_65 ( V_209 -> V_8 , true ) ;
F_66 ( V_209 -> V_8 ) ;
return 0 ;
}
static int F_67 ( struct V_167 * V_11 )
{
struct V_3 * V_209 = F_64 ( V_11 ) ;
int V_56 ;
F_65 ( V_209 -> V_8 , false ) ;
F_8 ( V_209 -> V_8 , V_170 ,
V_138 , V_138 ) ;
F_8 ( V_209 -> V_8 , V_172 ,
V_138 , V_138 ) ;
V_56 = F_68 ( V_209 -> V_8 ) ;
if ( V_56 )
return V_56 ;
F_8 ( V_209 -> V_8 , V_170 , V_138 , 0 ) ;
F_8 ( V_209 -> V_8 , V_172 , V_138 , 0 ) ;
return 0 ;
}
