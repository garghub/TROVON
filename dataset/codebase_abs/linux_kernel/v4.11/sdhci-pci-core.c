static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_4 == V_5 ||
V_2 -> V_3 -> V_4 == V_6 )
V_2 -> V_7 |= V_8 ;
return 0 ;
}
static int F_2 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_12 =
( ( 0x21 << V_13 )
& V_14 ) |
( ( 0x21 << V_15 )
& V_16 ) |
V_17 |
V_18 |
V_19 |
V_20 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
F_4 ( 500 ) ;
return 0 ;
}
static int F_5 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_22 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
V_2 -> V_23 = 1 ;
return 0 ;
}
static int F_7 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_22 ;
return 0 ;
}
static T_1 F_8 ( int V_24 , void * V_25 )
{
struct V_9 * V_10 = V_25 ;
struct V_26 * V_11 = V_10 -> V_11 ;
F_9 ( V_11 -> V_21 , F_10 ( 200 ) ) ;
return V_27 ;
}
static void F_11 ( struct V_9 * V_10 )
{
int V_28 , V_24 , V_29 = V_10 -> V_30 ;
V_10 -> V_30 = - V_31 ;
V_10 -> V_32 = - V_31 ;
if ( ! F_12 ( V_29 ) )
return;
V_28 = F_13 ( & V_10 -> V_2 -> V_3 -> V_33 , V_29 , L_1 ) ;
if ( V_28 < 0 )
goto V_34;
V_28 = F_14 ( V_29 ) ;
if ( V_28 < 0 )
goto V_35;
V_24 = F_15 ( V_29 ) ;
if ( V_24 < 0 )
goto V_35;
V_28 = F_16 ( V_24 , F_8 , V_36 |
V_37 , L_1 , V_10 ) ;
if ( V_28 )
goto V_35;
V_10 -> V_30 = V_29 ;
V_10 -> V_32 = V_24 ;
return;
V_35:
F_17 ( & V_10 -> V_2 -> V_3 -> V_33 , V_29 ) ;
V_34:
F_18 ( & V_10 -> V_2 -> V_3 -> V_33 , L_2 ) ;
}
static void F_19 ( struct V_9 * V_10 )
{
if ( V_10 -> V_32 >= 0 )
F_20 ( V_10 -> V_32 , V_10 ) ;
}
static inline void F_11 ( struct V_9 * V_10 )
{
}
static inline void F_19 ( struct V_9 * V_10 )
{
}
static int F_21 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_22 | V_38 ;
V_10 -> V_11 -> V_21 -> V_39 |= V_40 |
V_41 ;
return 0 ;
}
static int F_22 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_42 | V_38 ;
return 0 ;
}
static void F_23 ( struct V_26 * V_11 )
{
T_2 V_43 ;
V_43 = F_24 ( V_11 , V_44 ) ;
V_43 |= 0x10 ;
F_25 ( V_11 , V_43 , V_44 ) ;
F_26 ( 9 ) ;
V_43 &= ~ 0x10 ;
F_25 ( V_11 , V_43 , V_44 ) ;
F_27 ( 300 , 1000 ) ;
}
static int F_28 ( struct V_26 * V_11 ,
struct V_45 * V_46 ,
unsigned int V_47 ,
int V_48 , int V_49 , int * V_50 )
{
int V_51 ;
if ( V_52 > 0 )
V_51 = V_52 & 0xf ;
else
V_51 = 0 ;
if ( ( F_29 ( V_51 ) & V_49 ) == 0 )
V_51 = 0 ;
return V_51 ;
}
static void F_30 ( struct V_26 * V_11 )
{
T_3 V_53 , V_54 , V_55 ;
T_4 V_56 ;
if ( V_52 )
return;
V_52 = - 1 ;
V_56 = F_31 ( V_11 , V_57 ) & 0x7 ;
if ( V_56 != 3 && V_56 != 5 )
return;
V_53 = F_32 ( V_11 , V_58 ) ;
if ( V_53 & 0x3 )
return;
F_33 ( V_11 , 0x007f0023 , V_59 ) ;
F_33 ( V_11 , 0 , V_60 ) ;
F_34 ( V_11 , 0x10 , V_61 ) ;
F_25 ( V_11 , 0xe , V_62 ) ;
F_34 ( V_11 , 512 , V_63 ) ;
F_34 ( V_11 , 1 , V_64 ) ;
F_33 ( V_11 , 0 , V_65 ) ;
F_34 ( V_11 , 0x83b , V_66 ) ;
for ( V_54 = 0 ; V_54 < 1000 ; V_54 ++ ) {
V_53 = F_32 ( V_11 , V_67 ) ;
if ( V_53 & 0xffff8000 )
return;
if ( V_53 & 0x20 )
break;
F_26 ( 1 ) ;
}
V_53 = F_32 ( V_11 , V_58 ) ;
if ( ! ( V_53 & 0x800 ) )
return;
for ( V_54 = 0 ; V_54 < 47 ; V_54 ++ )
V_53 = F_32 ( V_11 , V_68 ) ;
V_55 = V_53 & 0xf00 ;
if ( V_55 != 0x200 && V_55 != 0x300 )
return;
V_52 = 0x10 | ( ( V_53 >> 12 ) & 0xf ) ;
}
static int F_35 ( struct V_69 * V_21 )
{
int V_70 = F_36 ( V_21 ) ;
struct V_26 * V_11 = F_37 ( V_21 ) ;
unsigned long V_71 ;
int V_72 = 0 ;
if ( ! V_70 )
return 0 ;
F_38 ( & V_11 -> V_73 , V_71 ) ;
if ( V_11 -> V_71 & V_74 )
goto V_34;
V_72 = ! ! ( F_32 ( V_11 , V_58 ) & V_75 ) ;
V_34:
F_39 ( & V_11 -> V_73 , V_71 ) ;
return V_72 ;
}
static int F_40 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_22 | V_38 |
V_76 | V_77 |
V_78 |
V_79 ;
V_10 -> V_11 -> V_21 -> V_39 |= V_41 ;
V_10 -> V_80 = F_23 ;
if ( V_10 -> V_2 -> V_3 -> V_81 == V_82 )
V_10 -> V_11 -> V_83 = 1000 ;
if ( V_10 -> V_2 -> V_3 -> V_81 == V_84 ) {
F_30 ( V_10 -> V_11 ) ;
V_10 -> V_85 = F_28 ;
}
return 0 ;
}
static int F_41 ( struct V_9 * V_10 )
{
T_5 V_86 ;
unsigned long long V_87 ;
V_86 = F_42 ( F_43 ( & V_10 -> V_2 -> V_3 -> V_33 ) ,
L_3 , NULL , & V_87 ) ;
if ( F_44 ( V_86 ) ) {
F_45 ( & V_10 -> V_2 -> V_3 -> V_33 ,
L_4 ) ;
return - V_31 ;
}
V_10 -> V_11 -> V_21 -> V_88 = V_87 * 1000000 ;
return 0 ;
}
static inline int F_41 ( struct V_9 * V_10 )
{
return 0 ;
}
static int F_46 ( struct V_9 * V_10 )
{
int V_28 ;
V_28 = F_41 ( V_10 ) ;
if ( V_28 )
return V_28 ;
V_10 -> V_11 -> V_21 -> V_12 |= V_42 | V_38 |
V_79 ;
return 0 ;
}
static int F_47 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_42 | V_38 |
V_79 ;
return 0 ;
}
static int F_48 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_79 ;
V_10 -> V_89 = 0 ;
V_10 -> V_90 = true ;
if ( V_10 -> V_2 -> V_3 -> V_81 == V_91 ||
V_10 -> V_2 -> V_3 -> V_81 == V_92 ||
V_10 -> V_2 -> V_3 -> V_81 == V_93 ||
V_10 -> V_2 -> V_3 -> V_81 == V_94 ) {
V_10 -> V_11 -> V_95 . V_96 = F_35 ;
V_10 -> V_11 -> V_21 -> V_12 |= V_97 ;
}
return 0 ;
}
static void F_49 ( struct V_26 * V_11 , unsigned char V_98 ,
unsigned short V_99 )
{
int V_100 ;
T_2 V_43 ;
F_50 ( V_11 , V_98 , V_99 ) ;
if ( V_98 == V_101 )
return;
F_51 ( & V_11 -> V_73 ) ;
for ( V_100 = 0 ; V_100 < V_102 ; V_100 ++ ) {
V_43 = F_24 ( V_11 , V_44 ) ;
if ( V_43 & V_103 )
break;
F_26 ( V_104 ) ;
V_43 |= V_103 ;
F_25 ( V_11 , V_43 , V_44 ) ;
}
F_52 ( & V_11 -> V_73 ) ;
}
static int F_53 ( struct V_9 * V_10 )
{
unsigned int V_105 = F_54 ( V_10 -> V_2 -> V_3 -> V_106 ) ;
switch ( V_105 ) {
case V_107 :
case V_108 :
V_10 -> V_11 -> V_21 -> V_12 |= V_38 |
V_22 |
V_77 ;
break;
case V_109 :
V_10 -> V_11 -> V_110 |= V_111 ;
break;
case V_112 :
V_10 -> V_11 -> V_21 -> V_12 |= V_38 |
V_42 ;
break;
default:
return - V_113 ;
}
return 0 ;
}
static int F_55 ( struct V_1 * V_2 , int V_114 )
{
T_2 V_115 ;
int V_72 ;
V_72 = F_56 ( V_2 -> V_3 , 0xAE , & V_115 ) ;
if ( V_72 )
return V_72 ;
if ( V_114 )
V_115 |= 0x47 ;
else
V_115 &= ~ 0x47 ;
return F_57 ( V_2 -> V_3 , 0xAE , V_115 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
int V_72 ;
T_4 V_116 = 0 ;
if ( V_2 -> V_3 -> V_117 == 0 ) {
V_2 -> V_7 |= V_118 |
V_119 |
V_120 |
V_121 |
V_122 ;
}
if ( V_2 -> V_3 -> V_81 == V_123 )
V_116 = V_124 ;
else if ( V_2 -> V_3 -> V_81 == V_125 )
V_116 = V_126 ;
if ( V_116 ) {
struct V_127 * V_128 ;
V_128 = NULL ;
while ( ( V_128 = F_59 ( V_129 ,
V_116 , V_128 ) ) != NULL ) {
if ( ( F_60 ( V_2 -> V_3 -> V_106 ) ==
F_60 ( V_128 -> V_106 ) ) &&
( V_2 -> V_3 -> V_130 == V_128 -> V_130 ) )
break;
}
if ( V_128 ) {
F_61 ( V_128 ) ;
F_62 ( & V_2 -> V_3 -> V_33 , L_5
L_6 ) ;
return - V_113 ;
}
}
V_72 = F_55 ( V_2 , 1 ) ;
if ( V_72 ) {
F_45 ( & V_2 -> V_3 -> V_33 , L_7 ) ;
return V_72 ;
}
if ( V_2 -> V_3 -> V_81 == V_125 ||
V_2 -> V_3 -> V_81 == V_126 )
V_2 -> V_7 |= V_131 ;
return 0 ;
}
static void F_63 ( struct V_26 * V_11 , int V_114 )
{
T_2 V_115 ;
V_115 = F_64 ( V_11 -> V_132 + 0xC0 ) ;
if ( V_114 )
V_115 |= 0x01 ;
else
V_115 &= ~ 0x01 ;
F_65 ( V_115 , V_11 -> V_132 + 0xC0 ) ;
}
static int F_66 ( struct V_9 * V_10 )
{
if ( V_10 -> V_2 -> V_3 -> V_117 == 0 ) {
T_4 V_133 ;
V_133 = F_67 ( V_10 -> V_11 -> V_132 + V_134 ) ;
V_133 = ( V_133 & V_135 ) >>
V_136 ;
if ( V_133 < 0xAC )
V_10 -> V_11 -> V_7 |= V_137 ;
}
if ( V_10 -> V_2 -> V_3 -> V_81 == V_126 ) {
V_10 -> V_11 -> V_138 = V_139 | V_140 |
V_141 | V_142 |
V_143 ;
V_10 -> V_11 -> V_144 = V_139 | V_140 |
V_141 | V_142 ;
}
if ( V_10 -> V_2 -> V_3 -> V_81 == V_124 ||
V_10 -> V_2 -> V_3 -> V_81 == V_126 )
F_63 ( V_10 -> V_11 , 1 ) ;
V_10 -> V_11 -> V_21 -> V_12 |= V_145 ;
return 0 ;
}
static void F_68 ( struct V_9 * V_10 , int V_146 )
{
if ( V_146 )
return;
if ( V_10 -> V_2 -> V_3 -> V_81 == V_124 ||
V_10 -> V_2 -> V_3 -> V_81 == V_126 )
F_63 ( V_10 -> V_11 , 0 ) ;
}
static int F_69 ( struct V_1 * V_2 )
{
int V_54 ;
if ( V_2 -> V_3 -> V_81 == V_124 ||
V_2 -> V_3 -> V_81 == V_126 ) {
for ( V_54 = 0 ; V_54 < V_2 -> V_23 ; V_54 ++ )
F_63 ( V_2 -> V_147 [ V_54 ] -> V_11 , 0 ) ;
}
return 0 ;
}
static int F_70 ( struct V_1 * V_2 )
{
int V_72 , V_54 ;
if ( V_2 -> V_3 -> V_81 == V_124 ||
V_2 -> V_3 -> V_81 == V_126 ) {
for ( V_54 = 0 ; V_54 < V_2 -> V_23 ; V_54 ++ )
F_63 ( V_2 -> V_147 [ V_54 ] -> V_11 , 1 ) ;
}
V_72 = F_55 ( V_2 , 1 ) ;
if ( V_72 ) {
F_45 ( & V_2 -> V_3 -> V_33 , L_7 ) ;
return V_72 ;
}
return 0 ;
}
static int F_71 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_3 -> V_148 & 0x0000FF ) == V_149 ) {
V_2 -> V_3 -> V_148 &= ~ 0x0000FF ;
V_2 -> V_3 -> V_148 |= V_150 ;
}
return 0 ;
}
static int F_72 ( struct V_9 * V_10 )
{
int V_151 , V_152 ;
T_2 V_153 = F_64 ( V_10 -> V_11 -> V_132 + V_154 ) ;
T_2 V_155 = F_64 ( V_10 -> V_11 -> V_132 + V_156 ) ;
F_62 ( & V_10 -> V_2 -> V_3 -> V_33 , L_8
L_9 ,
V_153 >> 4 , V_153 & 0xf ,
V_155 >> 4 , V_155 & 0xf ) ;
if ( V_155 >= 0x20 )
V_10 -> V_11 -> V_7 |= V_157 ;
F_65 ( V_158 , V_10 -> V_11 -> V_132 + V_159 ) ;
F_65 ( V_160 , V_10 -> V_11 -> V_132 + V_161 ) ;
F_26 ( 50 ) ;
V_151 = 10 ;
do {
V_152 = F_73 ( V_10 -> V_11 -> V_132 + V_162 ) ;
if ( V_152 & V_163 )
break;
F_26 ( 100 ) ;
} while ( -- V_151 );
if ( ! V_151 ) {
F_45 ( & V_10 -> V_2 -> V_3 -> V_33 ,
L_10 ) ;
F_65 ( 0 , V_10 -> V_11 -> V_132 + V_161 ) ;
return - V_113 ;
}
return 0 ;
}
static int F_74 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_117 == 0x10 )
V_2 -> V_7 |= V_164 ;
return 0 ;
}
static int F_75 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_39 |= V_165 ;
return 0 ;
}
static void F_76 ( struct V_26 * V_11 )
{
unsigned int V_53 ;
V_53 = F_31 ( V_11 , V_57 ) ;
V_53 |= V_166 | V_167 ;
F_34 ( V_11 , V_53 , V_57 ) ;
V_53 = F_31 ( V_11 , V_57 ) ;
V_53 &= ~ V_167 ;
F_34 ( V_11 , V_53 , V_57 ) ;
}
static void F_77 ( struct V_127 * V_3 , T_2 V_168 )
{
unsigned int V_53 ;
F_78 ( V_3 , V_169 , & V_53 ) ;
V_53 &= ~ V_170 ;
V_53 |= ( V_171 | ( V_168 << 1 ) ) ;
F_79 ( V_3 , V_169 , V_53 ) ;
}
static void F_80 ( struct V_127 * V_3 )
{
unsigned int V_53 ;
F_78 ( V_3 , V_172 , & V_53 ) ;
V_53 |= V_173 ;
F_79 ( V_3 , V_172 , V_53 ) ;
}
static int F_81 ( struct V_26 * V_11 , T_3 V_174 )
{
struct V_9 * V_10 = F_82 ( V_11 ) ;
struct V_127 * V_3 = V_10 -> V_2 -> V_3 ;
T_2 V_175 = 0 ;
T_2 V_176 = 0 ;
T_2 V_177 = 0 ;
T_2 V_178 , V_179 ;
F_76 ( V_11 ) ;
for ( V_179 = 0 ; V_179 < 12 ; V_179 ++ ) {
F_77 ( V_3 , V_179 ) ;
if ( F_83 ( V_11 -> V_21 , V_174 , NULL ) ) {
V_175 = 0 ;
F_4 ( V_180 ) ;
V_178 = V_181 | V_182 ;
F_25 ( V_11 , V_178 , V_183 ) ;
} else if ( ++ V_175 > V_176 ) {
V_176 = V_175 ;
V_177 = V_179 ;
}
}
if ( ! V_176 ) {
F_45 ( & V_3 -> V_33 , L_11 ) ;
return - V_184 ;
}
F_77 ( V_3 , V_177 - V_176 / 2 ) ;
F_80 ( V_3 ) ;
V_11 -> V_21 -> V_185 = 0 ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 )
{
struct V_127 * V_186 ;
enum V_187 V_188 ;
V_186 = F_59 ( V_189 ,
V_190 , NULL ) ;
if ( V_186 ) {
V_188 = V_191 ;
} else {
V_186 = F_59 ( V_189 ,
V_192 , NULL ) ;
if ( V_186 ) {
if ( V_186 -> V_117 < 0x51 )
V_188 = V_193 ;
else
V_188 = V_194 ;
} else {
V_188 = V_195 ;
}
}
if ( V_188 == V_191 || V_188 == V_193 )
V_2 -> V_110 |= V_196 ;
return 0 ;
}
static int F_85 ( struct V_26 * V_11 )
{
struct V_9 * V_10 ;
struct V_127 * V_3 ;
V_10 = F_82 ( V_11 ) ;
V_3 = V_10 -> V_2 -> V_3 ;
if ( ( ( V_3 -> V_148 & 0xFFFF00 ) == ( V_197 << 8 ) ) &&
( ( V_3 -> V_148 & 0x0000FF ) != V_150 ) &&
( V_11 -> V_71 & V_198 ) ) {
F_18 ( & V_3 -> V_33 , L_12
L_13 ) ;
}
F_86 ( V_3 ) ;
return 0 ;
}
static void F_87 ( struct V_26 * V_11 , int V_199 )
{
T_2 V_178 ;
V_178 = F_24 ( V_11 , V_200 ) ;
switch ( V_199 ) {
case V_201 :
V_178 |= V_202 ;
V_178 &= ~ V_203 ;
break;
case V_204 :
V_178 |= V_203 ;
V_178 &= ~ V_202 ;
break;
default:
V_178 &= ~ ( V_202 | V_203 ) ;
break;
}
F_25 ( V_11 , V_178 , V_200 ) ;
}
static void F_88 ( struct V_26 * V_11 )
{
struct V_9 * V_10 = F_82 ( V_11 ) ;
int V_205 = V_10 -> V_205 ;
if ( ! F_12 ( V_205 ) )
return;
F_89 ( V_205 , 0 ) ;
F_26 ( 10 ) ;
F_89 ( V_205 , 1 ) ;
F_27 ( 300 , 1000 ) ;
}
static void F_90 ( struct V_26 * V_11 )
{
struct V_9 * V_10 = F_82 ( V_11 ) ;
if ( V_10 -> V_80 )
V_10 -> V_80 ( V_11 ) ;
}
static int F_91 ( struct V_26 * V_11 ,
struct V_45 * V_46 ,
unsigned int V_47 , int V_48 ,
int V_49 , int * V_50 )
{
struct V_9 * V_10 = F_82 ( V_11 ) ;
if ( ! V_10 -> V_85 )
return 0 ;
return V_10 -> V_85 ( V_11 , V_46 , V_47 , V_48 ,
V_49 , V_50 ) ;
}
static int F_92 ( struct V_81 * V_33 )
{
struct V_127 * V_3 = F_93 ( V_33 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_6 V_206 ;
T_6 V_207 = 0 ;
int V_54 , V_72 ;
V_2 = F_94 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
for ( V_54 = 0 ; V_54 < V_2 -> V_23 ; V_54 ++ ) {
V_10 = V_2 -> V_147 [ V_54 ] ;
if ( ! V_10 )
continue;
V_72 = F_95 ( V_10 -> V_11 ) ;
if ( V_72 )
goto V_208;
V_206 = V_10 -> V_11 -> V_21 -> V_207 ;
if ( V_206 & V_209 )
F_96 ( V_10 -> V_11 ) ;
V_207 |= V_206 ;
}
if ( V_2 -> V_210 && V_2 -> V_210 -> V_211 ) {
V_72 = V_2 -> V_210 -> V_211 ( V_2 ) ;
if ( V_72 )
goto V_208;
}
if ( V_207 & V_212 ) {
if ( V_207 & V_209 )
F_97 ( V_33 , true ) ;
else
F_97 ( V_33 , false ) ;
} else
F_97 ( V_33 , false ) ;
return 0 ;
V_208:
while ( -- V_54 >= 0 )
F_98 ( V_2 -> V_147 [ V_54 ] -> V_11 ) ;
return V_72 ;
}
static int F_99 ( struct V_81 * V_33 )
{
struct V_127 * V_3 = F_93 ( V_33 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_54 , V_72 ;
V_2 = F_94 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_210 && V_2 -> V_210 -> V_213 ) {
V_72 = V_2 -> V_210 -> V_213 ( V_2 ) ;
if ( V_72 )
return V_72 ;
}
for ( V_54 = 0 ; V_54 < V_2 -> V_23 ; V_54 ++ ) {
V_10 = V_2 -> V_147 [ V_54 ] ;
if ( ! V_10 )
continue;
V_72 = F_98 ( V_10 -> V_11 ) ;
if ( V_72 )
return V_72 ;
}
return 0 ;
}
static int F_100 ( struct V_81 * V_33 )
{
struct V_127 * V_3 = F_93 ( V_33 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_54 , V_72 ;
V_2 = F_94 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
for ( V_54 = 0 ; V_54 < V_2 -> V_23 ; V_54 ++ ) {
V_10 = V_2 -> V_147 [ V_54 ] ;
if ( ! V_10 )
continue;
V_72 = F_101 ( V_10 -> V_11 ) ;
if ( V_72 )
goto V_214;
}
if ( V_2 -> V_210 && V_2 -> V_210 -> V_211 ) {
V_72 = V_2 -> V_210 -> V_211 ( V_2 ) ;
if ( V_72 )
goto V_214;
}
return 0 ;
V_214:
while ( -- V_54 >= 0 )
F_102 ( V_2 -> V_147 [ V_54 ] -> V_11 ) ;
return V_72 ;
}
static int F_103 ( struct V_81 * V_33 )
{
struct V_127 * V_3 = F_93 ( V_33 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_54 , V_72 ;
V_2 = F_94 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_210 && V_2 -> V_210 -> V_213 ) {
V_72 = V_2 -> V_210 -> V_213 ( V_2 ) ;
if ( V_72 )
return V_72 ;
}
for ( V_54 = 0 ; V_54 < V_2 -> V_23 ; V_54 ++ ) {
V_10 = V_2 -> V_147 [ V_54 ] ;
if ( ! V_10 )
continue;
V_72 = F_102 ( V_10 -> V_11 ) ;
if ( V_72 )
return V_72 ;
}
return 0 ;
}
static struct V_9 * F_104 (
struct V_127 * V_3 , struct V_1 * V_2 , int V_215 ,
int V_216 )
{
struct V_9 * V_10 ;
struct V_26 * V_11 ;
int V_72 , V_217 = V_215 + V_216 ;
if ( ! ( F_105 ( V_3 , V_217 ) & V_218 ) ) {
F_45 ( & V_3 -> V_33 , L_14 , V_217 ) ;
return F_106 ( - V_113 ) ;
}
if ( F_107 ( V_3 , V_217 ) < 0x100 ) {
F_45 ( & V_3 -> V_33 , L_15
L_16 ) ;
}
if ( ( V_3 -> V_148 & 0x0000FF ) == V_149 ) {
F_45 ( & V_3 -> V_33 , L_17 ) ;
return F_106 ( - V_113 ) ;
}
if ( ( V_3 -> V_148 & 0x0000FF ) > V_149 ) {
F_45 ( & V_3 -> V_33 , L_18 ) ;
return F_106 ( - V_113 ) ;
}
V_11 = F_108 ( & V_3 -> V_33 , sizeof( struct V_9 ) ) ;
if ( F_109 ( V_11 ) ) {
F_45 ( & V_3 -> V_33 , L_19 ) ;
return F_110 ( V_11 ) ;
}
V_10 = F_82 ( V_11 ) ;
V_10 -> V_2 = V_2 ;
V_10 -> V_11 = V_11 ;
V_10 -> V_205 = - V_31 ;
V_10 -> V_30 = - V_31 ;
V_10 -> V_89 = - 1 ;
if ( * V_219 )
V_10 -> V_220 = V_219 ( V_3 , V_216 ) ;
if ( V_10 -> V_220 ) {
if ( V_10 -> V_220 -> V_221 ) {
V_72 = V_10 -> V_220 -> V_221 ( V_10 -> V_220 ) ;
if ( V_72 ) {
F_45 ( & V_3 -> V_33 , L_20 ) ;
goto free;
}
}
V_10 -> V_205 = V_10 -> V_220 -> V_205 ;
V_10 -> V_30 = V_10 -> V_220 -> V_30 ;
}
V_11 -> V_222 = L_21 ;
V_11 -> V_223 = V_2 -> V_210 && V_2 -> V_210 -> V_223 ?
V_2 -> V_210 -> V_223 :
& V_224 ;
V_11 -> V_7 = V_2 -> V_7 ;
V_11 -> V_110 = V_2 -> V_110 ;
V_11 -> V_24 = V_3 -> V_24 ;
V_72 = F_111 ( V_3 , F_112 ( V_217 ) , F_113 ( V_11 -> V_21 ) ) ;
if ( V_72 ) {
F_45 ( & V_3 -> V_33 , L_22 ) ;
goto V_225;
}
V_11 -> V_132 = F_114 ( V_3 ) [ V_217 ] ;
if ( V_2 -> V_210 && V_2 -> V_210 -> V_226 ) {
V_72 = V_2 -> V_210 -> V_226 ( V_10 ) ;
if ( V_72 )
goto V_225;
}
if ( F_12 ( V_10 -> V_205 ) ) {
if ( ! F_13 ( & V_3 -> V_33 , V_10 -> V_205 , L_23 ) ) {
F_115 ( V_10 -> V_205 , 1 ) ;
V_10 -> V_11 -> V_21 -> V_12 |= V_76 ;
V_10 -> V_80 = F_88 ;
} else {
F_18 ( & V_3 -> V_33 , L_24 ) ;
V_10 -> V_205 = - V_31 ;
}
}
V_11 -> V_21 -> V_227 = V_212 | V_209 ;
V_11 -> V_21 -> V_216 = V_216 ;
V_11 -> V_21 -> V_39 |= V_228 ;
if ( V_10 -> V_89 >= 0 ) {
V_72 = F_116 ( V_11 -> V_21 , NULL , V_10 -> V_89 ,
V_10 -> V_90 , 0 , NULL ) ;
if ( V_72 == - V_229 )
goto remove;
if ( V_72 ) {
F_18 ( & V_3 -> V_33 , L_25 ) ;
V_10 -> V_89 = - 1 ;
}
}
V_72 = F_117 ( V_11 ) ;
if ( V_72 )
goto remove;
F_11 ( V_10 ) ;
if ( V_2 -> V_210 && V_2 -> V_210 -> V_230 &&
! F_12 ( V_10 -> V_30 ) && V_10 -> V_89 < 0 )
V_2 -> V_231 = false ;
return V_10 ;
remove:
if ( V_2 -> V_210 && V_2 -> V_210 -> V_232 )
V_2 -> V_210 -> V_232 ( V_10 , 0 ) ;
V_225:
if ( V_10 -> V_220 && V_10 -> V_220 -> V_225 )
V_10 -> V_220 -> V_225 ( V_10 -> V_220 ) ;
free:
F_118 ( V_11 ) ;
return F_106 ( V_72 ) ;
}
static void F_119 ( struct V_9 * V_10 )
{
int V_146 ;
T_3 V_115 ;
F_19 ( V_10 ) ;
V_146 = 0 ;
V_115 = F_67 ( V_10 -> V_11 -> V_132 + V_67 ) ;
if ( V_115 == ( T_3 ) - 1 )
V_146 = 1 ;
F_120 ( V_10 -> V_11 , V_146 ) ;
if ( V_10 -> V_2 -> V_210 && V_10 -> V_2 -> V_210 -> V_232 )
V_10 -> V_2 -> V_210 -> V_232 ( V_10 , V_146 ) ;
if ( V_10 -> V_220 && V_10 -> V_220 -> V_225 )
V_10 -> V_220 -> V_225 ( V_10 -> V_220 ) ;
F_118 ( V_10 -> V_11 ) ;
}
static void F_121 ( struct V_81 * V_33 )
{
F_122 ( V_33 , 1 ) ;
F_123 ( V_33 , 50 ) ;
F_124 ( V_33 ) ;
F_125 ( V_33 ) ;
F_126 ( V_33 ) ;
}
static void F_127 ( struct V_81 * V_33 )
{
F_128 ( V_33 ) ;
F_129 ( V_33 ) ;
}
static int F_130 ( struct V_127 * V_3 ,
const struct V_233 * V_234 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_2 V_147 , V_215 ;
int V_72 , V_54 ;
F_131 ( V_3 == NULL ) ;
F_131 ( V_234 == NULL ) ;
F_62 ( & V_3 -> V_33 , L_26 ,
( int ) V_3 -> V_235 , ( int ) V_3 -> V_81 , ( int ) V_3 -> V_117 ) ;
V_72 = F_56 ( V_3 , V_236 , & V_147 ) ;
if ( V_72 )
return V_72 ;
V_147 = F_132 ( V_147 ) + 1 ;
F_133 ( & V_3 -> V_33 , L_27 , V_147 ) ;
if ( V_147 == 0 )
return - V_113 ;
F_131 ( V_147 > V_237 ) ;
V_72 = F_56 ( V_3 , V_236 , & V_215 ) ;
if ( V_72 )
return V_72 ;
V_215 &= V_238 ;
if ( V_215 > 5 ) {
F_45 ( & V_3 -> V_33 , L_28 ) ;
return - V_113 ;
}
V_72 = F_134 ( V_3 ) ;
if ( V_72 )
return V_72 ;
V_2 = F_135 ( & V_3 -> V_33 , sizeof( * V_2 ) , V_239 ) ;
if ( ! V_2 )
return - V_240 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_210 = ( const struct V_241 * ) V_234 -> V_242 ;
if ( V_2 -> V_210 ) {
V_2 -> V_7 = V_2 -> V_210 -> V_7 ;
V_2 -> V_110 = V_2 -> V_210 -> V_110 ;
V_2 -> V_231 = V_2 -> V_210 -> V_231 ;
}
V_2 -> V_23 = V_147 ;
F_136 ( V_3 , V_2 ) ;
if ( V_2 -> V_210 && V_2 -> V_210 -> V_243 ) {
V_72 = V_2 -> V_210 -> V_243 ( V_2 ) ;
if ( V_72 )
return V_72 ;
}
V_147 = V_2 -> V_23 ;
for ( V_54 = 0 ; V_54 < V_147 ; V_54 ++ ) {
V_10 = F_104 ( V_3 , V_2 , V_215 , V_54 ) ;
if ( F_109 ( V_10 ) ) {
for ( V_54 -- ; V_54 >= 0 ; V_54 -- )
F_119 ( V_2 -> V_147 [ V_54 ] ) ;
return F_137 ( V_10 ) ;
}
V_2 -> V_147 [ V_54 ] = V_10 ;
}
if ( V_2 -> V_231 )
F_121 ( & V_3 -> V_33 ) ;
return 0 ;
}
static void F_138 ( struct V_127 * V_3 )
{
int V_54 ;
struct V_1 * V_2 = F_94 ( V_3 ) ;
if ( V_2 -> V_231 )
F_127 ( & V_3 -> V_33 ) ;
for ( V_54 = 0 ; V_54 < V_2 -> V_23 ; V_54 ++ )
F_119 ( V_2 -> V_147 [ V_54 ] ) ;
}
