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
T_2 V_54 , V_26 , V_55 = 0 ;
unsigned long V_56 ;
V_4 -> V_57 [ V_25 ] = true ;
F_8 ( V_4 -> V_8 , F_9 ( V_25 ) ,
V_58 , V_52 ? 0 : V_58 ) ;
if ( V_52 )
goto V_41;
switch ( V_45 ) {
case V_59 :
case V_60 :
V_49 = V_4 -> V_61 ;
break;
case V_51 :
V_55 |= V_62 ;
case V_63 :
V_55 |= V_64 ;
break;
default:
return - V_38 ;
}
if ( F_13 ( V_49 ) ) {
F_7 ( V_24 -> V_11 , L_15 ,
V_45 % 2 ? L_16 : L_17 ) ;
return F_14 ( V_49 ) ;
}
V_56 = F_15 ( V_49 ) ;
V_26 = V_56 / V_46 ;
if ( V_26 * V_46 > V_56 )
V_54 = V_26 * V_46 - V_56 ;
else if ( V_26 * V_46 < V_56 )
V_54 = V_56 - V_26 * V_46 ;
else
V_54 = 0 ;
if ( V_54 != 0 && V_56 / V_54 < 1000 ) {
F_7 ( V_24 -> V_11 , L_18 ,
V_25 ? 'T' : 'R' ) ;
return - V_38 ;
}
if ( V_26 == 1 && V_49 == V_4 -> V_50 ) {
V_55 |= V_25 ? V_65 : V_66 ;
goto V_41;
} else if ( V_26 < 2 ) {
F_7 ( V_24 -> V_11 , L_18 ,
V_25 ? 'T' : 'R' ) ;
return - V_38 ;
}
V_54 = F_5 ( V_24 , V_25 , V_26 , false , 0 ) ;
if ( V_54 )
return V_54 ;
V_4 -> V_57 [ V_25 ] = false ;
V_41:
V_4 -> V_67 [ V_25 ] = V_46 ;
F_8 ( V_4 -> V_8 , V_68 ,
V_25 ? V_62 | V_65 :
V_64 | V_66 , V_55 ) ;
return 0 ;
}
static int F_16 ( struct V_23 * V_24 , bool V_25 , T_2 V_46 )
{
struct V_3 * V_4 = F_6 ( V_24 ) ;
T_2 V_67 = V_4 -> V_67 [ V_25 ] ;
T_2 V_33 , V_26 = V_67 / V_46 ;
if ( V_4 -> V_69 )
return 0 ;
if ( V_26 * V_46 > V_67 )
V_33 = V_26 * V_46 - V_67 ;
else if ( V_26 * V_46 < V_67 )
V_33 = V_67 - V_26 * V_46 ;
else
V_33 = 0 ;
if ( V_33 != 0 && V_67 / V_33 < 1000 ) {
F_7 ( V_24 -> V_11 , L_19 ,
V_25 ? 'T' : 'R' ) ;
return - V_38 ;
}
if ( ! V_4 -> V_57 [ V_25 ] && ( V_26 > 16 || V_26 == 0 ) ) {
F_7 ( V_24 -> V_11 , L_20 ) ;
return - V_38 ;
}
return F_5 ( V_24 , V_25 , V_26 , true ,
V_4 -> V_57 [ V_25 ] ? 0 : V_26 ) ;
}
static int F_17 ( struct V_23 * V_24 , T_2 V_70 ,
T_2 V_71 , int V_72 , int V_73 )
{
struct V_3 * V_4 = F_6 ( V_24 ) ;
F_8 ( V_4 -> V_8 , V_74 ,
V_75 , F_18 ( V_72 ) ) ;
F_8 ( V_4 -> V_8 , V_76 ,
V_77 , F_19 ( V_70 ) ) ;
F_8 ( V_4 -> V_8 , V_78 ,
V_79 , F_20 ( V_70 ) ) ;
F_8 ( V_4 -> V_8 , V_80 ,
V_75 , F_18 ( V_72 ) ) ;
F_8 ( V_4 -> V_8 , V_81 ,
V_77 , F_19 ( V_71 ) ) ;
F_8 ( V_4 -> V_8 , V_82 ,
V_79 , F_20 ( V_71 ) ) ;
V_4 -> V_73 = V_73 ;
return 0 ;
}
static int F_21 ( struct V_23 * V_24 , unsigned int V_83 )
{
struct V_3 * V_4 = F_6 ( V_24 ) ;
T_2 V_84 = 0 , V_85 = 0 , V_86 ;
switch ( V_83 & V_87 ) {
case V_88 :
V_84 |= V_89 ;
V_85 |= V_90 | V_91 | V_92 ;
break;
case V_93 :
V_85 |= V_91 | V_92 ;
break;
case V_94 :
V_85 |= V_91 | V_92 | V_95 ;
break;
case V_96 :
V_84 |= V_97 | V_89 ;
V_85 |= V_91 | V_92 ;
break;
case V_98 :
V_84 |= V_97 ;
V_85 |= V_91 | V_92 ;
break;
default:
return - V_38 ;
}
switch ( V_83 & V_99 ) {
case V_100 :
break;
case V_101 :
V_85 ^= V_91 | V_92 ;
break;
case V_102 :
V_85 ^= V_90 ;
break;
case V_103 :
V_85 ^= V_91 | V_92 | V_90 ;
break;
default:
return - V_38 ;
}
V_4 -> V_69 = false ;
switch ( V_83 & V_104 ) {
case V_105 :
V_4 -> V_69 = true ;
break;
case V_106 :
V_85 |= V_107 ;
break;
case V_108 :
V_85 |= V_109 ;
break;
case V_110 :
V_85 |= V_109 | V_107 ;
break;
default:
return - V_38 ;
}
V_86 = V_97 | V_89 ;
F_8 ( V_4 -> V_8 , V_111 , V_86 , V_84 ) ;
F_8 ( V_4 -> V_8 , V_112 , V_86 , V_84 ) ;
V_86 = V_91 | V_92 | V_90 |
V_109 | V_107 | V_95 ;
F_8 ( V_4 -> V_8 , V_74 , V_86 , V_85 ) ;
F_8 ( V_4 -> V_8 , V_80 , V_86 , V_85 ) ;
return 0 ;
}
static int F_22 ( struct V_113 * V_114 ,
struct V_23 * V_24 )
{
int V_54 ;
struct V_3 * V_4 = F_6 ( V_24 ) ;
V_54 = F_23 ( V_4 -> V_115 ) ;
if ( V_54 )
return V_54 ;
if ( ! F_13 ( V_4 -> V_50 ) ) {
V_54 = F_23 ( V_4 -> V_50 ) ;
if ( V_54 )
goto V_116;
}
if ( ! F_13 ( V_4 -> V_61 ) ) {
V_54 = F_23 ( V_4 -> V_61 ) ;
if ( V_54 )
goto V_117;
}
if ( ! V_24 -> V_118 ) {
F_8 ( V_4 -> V_8 , V_119 ,
V_120 , V_4 -> V_121 ?
V_120 : 0 ) ;
F_8 ( V_4 -> V_8 , V_74 ,
V_75 , F_18 ( 2 ) ) ;
F_8 ( V_4 -> V_8 , V_80 ,
V_75 , F_18 ( 2 ) ) ;
}
return 0 ;
V_117:
if ( ! F_13 ( V_4 -> V_50 ) )
F_24 ( V_4 -> V_50 ) ;
V_116:
F_24 ( V_4 -> V_115 ) ;
return V_54 ;
}
static int F_25 ( struct V_113 * V_114 ,
struct V_122 * V_123 ,
struct V_23 * V_24 )
{
struct V_3 * V_4 = F_6 ( V_24 ) ;
bool V_25 = V_114 -> V_124 == V_125 ;
T_2 V_126 = F_26 ( F_27 ( V_123 ) ) ;
T_2 V_127 = F_28 ( V_123 ) ;
T_2 V_128 , V_86 , V_129 , V_54 ;
V_128 = F_29 ( V_123 ) * V_4 -> V_73 * 2 ;
V_54 = F_16 ( V_24 , V_25 , V_128 ) ;
if ( V_54 )
return V_54 ;
F_8 ( V_4 -> V_8 , F_30 ( V_25 ) ,
V_130 , F_28 ( V_123 ) > 1 ?
V_131 : 0 ) ;
F_8 ( V_4 -> V_8 , F_31 ( V_25 ) ,
V_132 , V_133 ) ;
V_86 = V_132 | V_134 | V_135 |
( V_25 ? V_136 | V_137 : V_138 ) ;
V_129 = F_32 ( V_126 ) | F_33 ( V_4 -> V_139 ) |
( V_25 ? F_34 ( V_127 ) | V_137 : F_35 ( V_127 ) ) ;
F_8 ( V_4 -> V_8 , F_31 ( V_25 ) , V_86 , V_129 ) ;
V_86 = V_140 | ( V_25 ? V_141 : 0 ) ;
V_129 = F_36 ( V_4 -> V_73 , V_126 ) | ( V_25 ? V_141 : 0 ) ;
F_8 ( V_4 -> V_8 , F_30 ( V_25 ) , V_86 , V_129 ) ;
F_8 ( V_4 -> V_8 , V_142 ,
V_143 , F_37 ( V_144 ) ) ;
F_8 ( V_4 -> V_8 , V_145 ,
V_146 , F_38 ( V_144 ) ) ;
return 0 ;
}
static void F_39 ( struct V_113 * V_114 ,
struct V_23 * V_24 )
{
struct V_3 * V_4 = F_6 ( V_24 ) ;
if ( ! F_13 ( V_4 -> V_61 ) )
F_24 ( V_4 -> V_61 ) ;
if ( ! F_13 ( V_4 -> V_50 ) )
F_24 ( V_4 -> V_50 ) ;
F_24 ( V_4 -> V_115 ) ;
}
static int F_40 ( struct V_113 * V_114 , int V_147 ,
struct V_23 * V_24 )
{
struct V_3 * V_4 = F_6 ( V_24 ) ;
bool V_25 = V_114 -> V_124 == V_125 ;
T_3 V_35 , V_127 = V_114 -> V_148 -> V_127 ;
switch ( V_147 ) {
case V_149 :
case V_150 :
case V_151 :
F_8 ( V_4 -> V_8 , F_31 ( V_25 ) ,
V_152 , V_153 ) ;
for ( V_35 = 0 ; V_25 && V_35 < V_127 ; V_35 ++ )
F_41 ( V_4 -> V_8 , V_154 , 0x0 ) ;
F_8 ( V_4 -> V_8 , F_30 ( V_25 ) ,
V_25 ? V_155 : V_156 ,
V_25 ? F_42 ( V_127 ) : F_43 ( V_127 ) ) ;
break;
case V_157 :
case V_158 :
case V_159 :
F_8 ( V_4 -> V_8 , F_30 ( V_25 ) ,
V_25 ? V_155 : V_156 , 0 ) ;
F_8 ( V_4 -> V_8 , F_31 ( V_25 ) ,
V_133 | V_153 , V_133 ) ;
F_8 ( V_4 -> V_8 , F_31 ( V_25 ) ,
V_133 , 0 ) ;
break;
default:
return - V_38 ;
}
return 0 ;
}
static int F_44 ( struct V_23 * V_24 )
{
struct V_3 * V_4 = F_6 ( V_24 ) ;
F_45 ( V_24 , & V_4 -> V_160 ,
& V_4 -> V_161 ) ;
return 0 ;
}
static bool F_46 ( struct V_162 * V_11 , unsigned int V_163 )
{
switch ( V_163 ) {
case V_164 :
case V_68 :
case V_9 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_119 :
case V_111 :
case V_74 :
case V_112 :
case V_80 :
case V_76 :
case V_78 :
case V_81 :
case V_82 :
case V_142 :
case V_145 :
return true ;
default:
return false ;
}
}
static bool F_47 ( struct V_162 * V_11 , unsigned int V_163 )
{
switch ( V_163 ) {
case V_154 :
case V_68 :
case V_165 :
case V_167 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_119 :
case V_111 :
case V_74 :
case V_112 :
case V_80 :
case V_76 :
case V_78 :
case V_81 :
case V_82 :
case V_142 :
case V_145 :
return true ;
default:
return false ;
}
}
static int F_48 ( struct V_5 * V_6 )
{
struct V_181 * V_182 = V_6 -> V_11 . V_183 ;
struct V_3 * V_4 ;
struct V_184 * V_185 ;
const T_4 * V_186 ;
void T_5 * V_187 ;
int V_1 , V_54 ;
V_4 = F_49 ( & V_6 -> V_11 , sizeof( * V_4 ) , V_188 ) ;
if ( ! V_4 )
return - V_189 ;
V_4 -> V_6 = V_6 ;
strcpy ( V_4 -> V_190 , V_182 -> V_190 ) ;
if ( F_50 ( V_182 , L_21 ) )
V_191 . V_192 = V_193 ;
V_185 = F_51 ( V_6 , V_194 , 0 ) ;
V_187 = F_52 ( & V_6 -> V_11 , V_185 ) ;
if ( F_13 ( V_187 ) )
return F_14 ( V_187 ) ;
V_4 -> V_8 = F_53 ( & V_6 -> V_11 ,
L_22 , V_187 , & V_191 ) ;
if ( F_13 ( V_4 -> V_8 ) ) {
F_7 ( & V_6 -> V_11 , L_23 ,
F_14 ( V_4 -> V_8 ) ) ;
return F_14 ( V_4 -> V_8 ) ;
}
V_4 -> V_115 = F_54 ( & V_6 -> V_11 , L_22 ) ;
if ( F_13 ( V_4 -> V_115 ) ) {
F_7 ( & V_6 -> V_11 , L_24 ,
F_14 ( V_4 -> V_115 ) ) ;
return F_14 ( V_4 -> V_115 ) ;
}
V_4 -> V_50 = F_54 ( & V_6 -> V_11 , L_16 ) ;
if ( F_13 ( V_4 -> V_50 ) )
F_4 ( & V_6 -> V_11 , L_25 ,
F_14 ( V_4 -> V_50 ) ) ;
V_4 -> V_61 = F_54 ( & V_6 -> V_11 , L_17 ) ;
if ( F_13 ( V_4 -> V_61 ) )
F_4 ( & V_6 -> V_11 , L_26 ,
F_14 ( V_4 -> V_61 ) ) ;
V_1 = F_55 ( V_6 , 0 ) ;
if ( V_1 < 0 ) {
F_7 ( & V_6 -> V_11 , L_27 , V_182 -> V_195 ) ;
return V_1 ;
}
V_54 = F_56 ( & V_6 -> V_11 , V_1 , F_1 , 0 ,
V_4 -> V_190 , V_4 ) ;
if ( V_54 ) {
F_7 ( & V_6 -> V_11 , L_28 , V_1 ) ;
return V_54 ;
}
V_4 -> V_73 = 32 ;
V_4 -> V_69 = true ;
V_186 = F_57 ( V_182 , L_29 , NULL ) ;
if ( V_186 )
V_4 -> V_139 = F_58 ( V_186 ) ;
else
V_4 -> V_139 = 64 ;
V_4 -> V_160 . V_196 = 16 ;
V_4 -> V_161 . V_196 = 16 ;
V_4 -> V_160 . V_197 = V_185 -> V_198 + V_154 ;
V_4 -> V_161 . V_197 = V_185 -> V_198 + V_164 ;
V_4 -> V_121 =
F_50 ( V_182 , L_30 ) ;
if ( V_4 -> V_121 ) {
V_199 . V_200 = 1 ;
V_199 . V_201 = 1 ;
V_199 . V_202 = 1 ;
}
F_59 ( & V_6 -> V_11 , V_4 ) ;
V_54 = F_41 ( V_4 -> V_8 , V_68 , V_203 ) ;
if ( V_54 ) {
F_7 ( & V_6 -> V_11 , L_31 , V_54 ) ;
return V_54 ;
}
V_54 = F_41 ( V_4 -> V_8 , V_68 , V_204 ) ;
if ( V_54 ) {
F_7 ( & V_6 -> V_11 , L_32 , V_54 ) ;
return V_54 ;
}
V_54 = F_60 ( & V_6 -> V_11 , & V_205 ,
& V_199 , 1 ) ;
if ( V_54 ) {
F_7 ( & V_6 -> V_11 , L_33 , V_54 ) ;
return V_54 ;
}
V_54 = F_61 ( V_6 ) ;
if ( V_54 )
F_7 ( & V_6 -> V_11 , L_34 , V_54 ) ;
return V_54 ;
}
