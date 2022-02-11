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
if ( V_26 == 1 ) {
V_55 |= V_25 ? V_65 : V_66 ;
goto V_41;
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
if ( V_4 -> V_57 [ V_25 ] && ( V_26 > 16 || V_26 == 0 ) ) {
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
struct V_3 * V_4 = F_6 ( V_24 ) ;
F_23 ( V_4 -> V_115 ) ;
if ( ! F_13 ( V_4 -> V_50 ) )
F_23 ( V_4 -> V_50 ) ;
if ( ! F_13 ( V_4 -> V_61 ) )
F_23 ( V_4 -> V_61 ) ;
if ( ! V_24 -> V_116 ) {
F_8 ( V_4 -> V_8 , V_117 ,
V_118 , F_24 ( V_119 ) ) ;
F_8 ( V_4 -> V_8 , V_120 ,
V_121 , F_25 ( V_119 ) ) ;
F_8 ( V_4 -> V_8 , V_122 ,
V_123 , V_4 -> V_124 ?
V_123 : 0 ) ;
F_8 ( V_4 -> V_8 , V_74 ,
V_75 , F_18 ( 2 ) ) ;
F_8 ( V_4 -> V_8 , V_80 ,
V_75 , F_18 ( 2 ) ) ;
}
return 0 ;
}
static int F_26 ( struct V_113 * V_114 ,
struct V_125 * V_126 ,
struct V_23 * V_24 )
{
struct V_3 * V_4 = F_6 ( V_24 ) ;
bool V_25 = V_114 -> V_127 == V_128 ;
T_2 V_129 = F_27 ( F_28 ( V_126 ) ) ;
T_2 V_130 = F_29 ( V_126 ) ;
T_2 V_131 , V_86 , V_132 , V_54 ;
V_131 = F_30 ( V_126 ) * V_4 -> V_73 * 2 ;
V_54 = F_16 ( V_24 , V_25 , V_131 ) ;
if ( V_54 )
return V_54 ;
F_8 ( V_4 -> V_8 , F_31 ( V_25 ) ,
V_133 , F_29 ( V_126 ) > 1 ?
V_134 : 0 ) ;
F_8 ( V_4 -> V_8 , F_32 ( V_25 ) ,
V_135 , V_136 ) ;
V_86 = V_135 | V_137 | V_138 |
( V_25 ? V_139 | V_140 : V_141 ) ;
V_132 = F_33 ( V_129 ) | F_34 ( V_4 -> V_142 ) |
( V_25 ? F_35 ( V_130 ) | V_140 : F_36 ( V_130 ) ) ;
F_8 ( V_4 -> V_8 , F_32 ( V_25 ) , V_86 , V_132 ) ;
V_86 = V_143 | ( V_25 ? V_144 : 0 ) ;
V_132 = F_37 ( V_4 -> V_73 , V_129 ) | ( V_25 ? V_144 : 0 ) ;
F_8 ( V_4 -> V_8 , F_31 ( V_25 ) , V_86 , V_132 ) ;
return 0 ;
}
static void F_38 ( struct V_113 * V_114 ,
struct V_23 * V_24 )
{
struct V_3 * V_4 = F_6 ( V_24 ) ;
if ( ! F_13 ( V_4 -> V_61 ) )
F_39 ( V_4 -> V_61 ) ;
if ( ! F_13 ( V_4 -> V_50 ) )
F_39 ( V_4 -> V_50 ) ;
F_39 ( V_4 -> V_115 ) ;
}
static int F_40 ( struct V_113 * V_114 , int V_145 ,
struct V_23 * V_24 )
{
struct V_3 * V_4 = F_6 ( V_24 ) ;
bool V_25 = V_114 -> V_127 == V_128 ;
T_3 V_35 , V_130 = V_114 -> V_146 -> V_130 ;
switch ( V_145 ) {
case V_147 :
case V_148 :
case V_149 :
F_8 ( V_4 -> V_8 , F_32 ( V_25 ) ,
V_150 , V_151 ) ;
for ( V_35 = 0 ; V_25 && V_35 < V_130 ; V_35 ++ )
F_41 ( V_4 -> V_8 , V_152 , 0x0 ) ;
F_8 ( V_4 -> V_8 , F_31 ( V_25 ) ,
V_25 ? V_153 : V_154 ,
V_25 ? F_42 ( V_130 ) : F_43 ( V_130 ) ) ;
break;
case V_155 :
case V_156 :
case V_157 :
F_8 ( V_4 -> V_8 , F_31 ( V_25 ) ,
V_25 ? V_153 : V_154 , 0 ) ;
F_8 ( V_4 -> V_8 , F_32 ( V_25 ) ,
V_136 | V_151 , V_136 ) ;
F_8 ( V_4 -> V_8 , F_32 ( V_25 ) ,
V_136 , 0 ) ;
break;
default:
return - V_38 ;
}
return 0 ;
}
static int F_44 ( struct V_23 * V_24 )
{
struct V_3 * V_4 = F_6 ( V_24 ) ;
F_45 ( V_24 , & V_4 -> V_158 ,
& V_4 -> V_159 ) ;
return 0 ;
}
static bool F_46 ( struct V_160 * V_11 , unsigned int V_161 )
{
switch ( V_161 ) {
case V_162 :
case V_68 :
case V_9 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_122 :
case V_111 :
case V_74 :
case V_112 :
case V_80 :
case V_76 :
case V_78 :
case V_81 :
case V_82 :
case V_117 :
case V_120 :
return true ;
default:
return false ;
}
}
static bool F_47 ( struct V_160 * V_11 , unsigned int V_161 )
{
switch ( V_161 ) {
case V_152 :
case V_68 :
case V_163 :
case V_165 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_122 :
case V_111 :
case V_74 :
case V_112 :
case V_80 :
case V_76 :
case V_78 :
case V_81 :
case V_82 :
case V_117 :
case V_120 :
return true ;
default:
return false ;
}
}
static int F_48 ( struct V_5 * V_6 )
{
struct V_179 * V_180 = V_6 -> V_11 . V_181 ;
struct V_3 * V_4 ;
struct V_182 * V_183 ;
const T_4 * V_184 ;
void T_5 * V_185 ;
int V_1 , V_54 ;
V_4 = F_49 ( & V_6 -> V_11 , sizeof( * V_4 ) , V_186 ) ;
if ( ! V_4 )
return - V_187 ;
V_4 -> V_6 = V_6 ;
strcpy ( V_4 -> V_188 , V_180 -> V_188 ) ;
V_183 = F_50 ( V_6 , V_189 , 0 ) ;
V_185 = F_51 ( & V_6 -> V_11 , V_183 ) ;
if ( F_13 ( V_185 ) )
return F_14 ( V_185 ) ;
V_4 -> V_8 = F_52 ( & V_6 -> V_11 ,
L_21 , V_185 , & V_190 ) ;
if ( F_13 ( V_4 -> V_8 ) ) {
F_7 ( & V_6 -> V_11 , L_22 ,
F_14 ( V_4 -> V_8 ) ) ;
return F_14 ( V_4 -> V_8 ) ;
}
V_4 -> V_115 = F_53 ( & V_6 -> V_11 , L_21 ) ;
if ( F_13 ( V_4 -> V_115 ) ) {
F_7 ( & V_6 -> V_11 , L_23 ,
F_14 ( V_4 -> V_115 ) ) ;
return F_14 ( V_4 -> V_115 ) ;
}
V_4 -> V_50 = F_53 ( & V_6 -> V_11 , L_16 ) ;
if ( F_13 ( V_4 -> V_50 ) )
F_4 ( & V_6 -> V_11 , L_24 ,
F_14 ( V_4 -> V_50 ) ) ;
V_4 -> V_61 = F_53 ( & V_6 -> V_11 , L_17 ) ;
if ( F_13 ( V_4 -> V_61 ) )
F_4 ( & V_6 -> V_11 , L_25 ,
F_14 ( V_4 -> V_61 ) ) ;
V_1 = F_54 ( V_6 , 0 ) ;
if ( V_1 < 0 ) {
F_7 ( & V_6 -> V_11 , L_26 , V_180 -> V_191 ) ;
return V_1 ;
}
V_54 = F_55 ( & V_6 -> V_11 , V_1 , F_1 , 0 ,
V_4 -> V_188 , V_4 ) ;
if ( V_54 ) {
F_7 ( & V_6 -> V_11 , L_27 , V_1 ) ;
return V_54 ;
}
V_4 -> V_73 = 32 ;
V_4 -> V_69 = true ;
V_184 = F_56 ( V_180 , L_28 , NULL ) ;
if ( V_184 )
V_4 -> V_142 = F_57 ( V_184 ) ;
else
V_4 -> V_142 = 64 ;
V_4 -> V_158 . V_192 = 16 ;
V_4 -> V_159 . V_192 = 16 ;
V_4 -> V_158 . V_193 = V_183 -> V_194 + V_152 ;
V_4 -> V_159 . V_193 = V_183 -> V_194 + V_162 ;
V_4 -> V_124 =
F_58 ( V_180 , L_29 ) ;
if ( V_4 -> V_124 ) {
V_195 . V_196 = 1 ;
V_195 . V_197 = 1 ;
V_195 . V_198 = 1 ;
}
F_59 ( & V_6 -> V_11 , V_4 ) ;
V_54 = F_41 ( V_4 -> V_8 , V_68 , V_199 ) ;
if ( V_54 ) {
F_7 ( & V_6 -> V_11 , L_30 , V_54 ) ;
return V_54 ;
}
V_54 = F_41 ( V_4 -> V_8 , V_68 , V_200 ) ;
if ( V_54 ) {
F_7 ( & V_6 -> V_11 , L_31 , V_54 ) ;
return V_54 ;
}
V_54 = F_60 ( & V_6 -> V_11 , & V_201 ,
& V_195 , 1 ) ;
if ( V_54 ) {
F_7 ( & V_6 -> V_11 , L_32 , V_54 ) ;
return V_54 ;
}
V_54 = F_61 ( V_6 ) ;
if ( V_54 )
F_7 ( & V_6 -> V_11 , L_33 , V_54 ) ;
return V_54 ;
}
