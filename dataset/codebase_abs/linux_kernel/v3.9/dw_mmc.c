static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_9 * V_11 ;
struct V_12 * V_13 ;
F_2 ( & V_5 -> V_14 -> V_15 ) ;
V_8 = V_5 -> V_8 ;
if ( V_8 ) {
V_10 = V_8 -> V_10 ;
V_13 = V_8 -> V_13 ;
V_11 = V_8 -> V_11 ;
if ( V_10 )
F_3 ( V_2 ,
L_1 ,
V_10 -> V_16 , V_10 -> V_17 , V_10 -> V_18 ,
V_10 -> V_19 [ 0 ] , V_10 -> V_19 [ 1 ] , V_10 -> V_19 [ 2 ] ,
V_10 -> V_19 [ 2 ] , V_10 -> error ) ;
if ( V_13 )
F_3 ( V_2 , L_2 ,
V_13 -> V_20 , V_13 -> V_21 ,
V_13 -> V_22 , V_13 -> V_18 , V_13 -> error ) ;
if ( V_11 )
F_3 ( V_2 ,
L_1 ,
V_11 -> V_16 , V_11 -> V_17 , V_11 -> V_18 ,
V_11 -> V_19 [ 0 ] , V_11 -> V_19 [ 1 ] , V_11 -> V_19 [ 2 ] ,
V_11 -> V_19 [ 2 ] , V_11 -> error ) ;
}
F_4 ( & V_5 -> V_14 -> V_15 ) ;
return 0 ;
}
static int F_5 ( struct V_23 * V_23 , struct V_24 * V_24 )
{
return F_6 ( V_24 , F_1 , V_23 -> V_25 ) ;
}
static int F_7 ( struct V_1 * V_2 , void * V_3 )
{
F_3 ( V_2 , L_3 , V_26 ) ;
F_3 ( V_2 , L_4 , V_27 ) ;
F_3 ( V_2 , L_5 , V_28 ) ;
F_3 ( V_2 , L_6 , V_29 ) ;
F_3 ( V_2 , L_7 , V_30 ) ;
F_3 ( V_2 , L_8 , V_31 ) ;
return 0 ;
}
static int F_8 ( struct V_23 * V_23 , struct V_24 * V_24 )
{
return F_6 ( V_24 , F_7 , V_23 -> V_25 ) ;
}
static void F_9 ( struct V_4 * V_5 )
{
struct V_32 * V_33 = V_5 -> V_33 ;
struct V_34 * V_14 = V_5 -> V_14 ;
struct V_35 * V_36 ;
struct V_35 * V_37 ;
V_36 = V_33 -> V_38 ;
if ( ! V_36 )
return;
V_37 = F_10 ( L_9 , V_39 , V_36 , V_14 ,
& V_40 ) ;
if ( ! V_37 )
goto V_41;
V_37 = F_10 ( L_10 , V_39 , V_36 , V_5 ,
& V_42 ) ;
if ( ! V_37 )
goto V_41;
V_37 = F_11 ( L_11 , V_39 , V_36 , ( V_43 * ) & V_14 -> V_44 ) ;
if ( ! V_37 )
goto V_41;
V_37 = F_12 ( L_12 , V_39 , V_36 ,
( V_43 * ) & V_14 -> V_45 ) ;
if ( ! V_37 )
goto V_41;
V_37 = F_12 ( L_13 , V_39 , V_36 ,
( V_43 * ) & V_14 -> V_46 ) ;
if ( ! V_37 )
goto V_41;
return;
V_41:
F_13 ( & V_33 -> V_47 , L_14 ) ;
}
static void F_14 ( struct V_34 * V_14 )
{
F_15 ( V_14 , V_48 , 0xffffffff ) ;
}
static V_43 F_16 ( struct V_32 * V_33 , struct V_9 * V_10 )
{
struct V_12 * V_13 ;
struct V_4 * V_5 = F_17 ( V_33 ) ;
const struct V_49 * V_50 = V_5 -> V_14 -> V_50 ;
V_43 V_51 ;
V_10 -> error = - V_52 ;
V_51 = V_10 -> V_16 ;
if ( V_51 == V_53 )
V_51 |= V_54 ;
else
V_51 |= V_55 ;
if ( V_10 -> V_18 & V_56 ) {
V_51 |= V_57 ;
if ( V_10 -> V_18 & V_58 )
V_51 |= V_59 ;
}
if ( V_10 -> V_18 & V_60 )
V_51 |= V_61 ;
V_13 = V_10 -> V_13 ;
if ( V_13 ) {
V_51 |= V_62 ;
if ( V_13 -> V_18 & V_63 )
V_51 |= V_64 ;
if ( V_13 -> V_18 & V_65 )
V_51 |= V_66 ;
}
if ( V_50 && V_50 -> V_67 )
V_50 -> V_67 ( V_5 -> V_14 , & V_51 ) ;
return V_51 ;
}
static void F_18 ( struct V_34 * V_14 ,
struct V_9 * V_10 , V_43 V_68 )
{
V_14 -> V_10 = V_10 ;
F_19 ( V_14 -> V_69 ,
L_15 ,
V_10 -> V_17 , V_68 ) ;
F_15 ( V_14 , V_70 , V_10 -> V_17 ) ;
F_20 () ;
F_15 ( V_14 , V_71 , V_68 | V_72 ) ;
}
static void F_21 ( struct V_34 * V_14 , struct V_12 * V_13 )
{
F_18 ( V_14 , V_13 -> V_11 , V_14 -> V_73 ) ;
}
static void F_22 ( struct V_34 * V_14 )
{
if ( V_14 -> V_74 ) {
V_14 -> V_75 -> V_11 ( V_14 ) ;
V_14 -> V_75 -> V_76 ( V_14 ) ;
} else {
F_23 ( V_77 , & V_14 -> V_45 ) ;
}
}
static int F_24 ( struct V_12 * V_13 )
{
if ( V_13 -> V_18 & V_65 )
return V_78 ;
else
return V_79 ;
}
static void F_25 ( struct V_34 * V_14 )
{
struct V_12 * V_13 = V_14 -> V_13 ;
if ( V_13 )
if ( ! V_13 -> V_80 )
F_26 ( V_14 -> V_69 ,
V_13 -> V_81 ,
V_13 -> V_82 ,
F_24 ( V_13 ) ) ;
}
static void F_27 ( struct V_34 * V_14 )
{
V_43 V_83 ;
V_83 = F_28 ( V_14 , V_84 ) ;
V_83 &= ~ V_85 ;
V_83 |= V_86 ;
F_15 ( V_14 , V_84 , V_83 ) ;
V_83 = F_28 ( V_14 , V_87 ) ;
V_83 &= ~ ( V_88 | V_89 ) ;
F_15 ( V_14 , V_87 , V_83 ) ;
}
static void F_29 ( struct V_34 * V_14 )
{
struct V_12 * V_13 = V_14 -> V_13 ;
F_19 ( V_14 -> V_69 , L_16 ) ;
V_14 -> V_75 -> V_76 ( V_14 ) ;
if ( V_13 ) {
F_23 ( V_77 , & V_14 -> V_45 ) ;
F_30 ( & V_14 -> V_90 ) ;
}
}
static void F_31 ( struct V_34 * V_14 , struct V_12 * V_13 ,
unsigned int V_82 )
{
int V_91 ;
struct V_92 * V_93 = V_14 -> V_94 ;
for ( V_91 = 0 ; V_91 < V_82 ; V_91 ++ , V_93 ++ ) {
unsigned int V_95 = F_32 ( & V_13 -> V_81 [ V_91 ] ) ;
V_43 V_96 = F_33 ( & V_13 -> V_81 [ V_91 ] ) ;
V_93 -> V_97 = V_98 | V_99 | V_100 ;
F_34 ( V_93 , V_95 ) ;
V_93 -> V_101 = V_96 ;
}
V_93 = V_14 -> V_94 ;
V_93 -> V_97 |= V_102 ;
V_93 = V_14 -> V_94 + ( V_91 - 1 ) * sizeof( struct V_92 ) ;
V_93 -> V_97 &= ~ ( V_100 | V_99 ) ;
V_93 -> V_97 |= V_103 ;
F_20 () ;
}
static void F_35 ( struct V_34 * V_14 , unsigned int V_82 )
{
V_43 V_83 ;
F_31 ( V_14 , V_14 -> V_13 , V_82 ) ;
V_83 = F_28 ( V_14 , V_84 ) ;
V_83 |= V_85 ;
F_15 ( V_14 , V_84 , V_83 ) ;
F_20 () ;
V_83 = F_28 ( V_14 , V_87 ) ;
V_83 |= V_88 | V_89 ;
F_15 ( V_14 , V_87 , V_83 ) ;
F_15 ( V_14 , V_104 , 1 ) ;
}
static int F_36 ( struct V_34 * V_14 )
{
struct V_92 * V_105 ;
int V_91 ;
V_14 -> V_106 = V_107 / sizeof( struct V_92 ) ;
for ( V_91 = 0 , V_105 = V_14 -> V_94 ; V_91 < V_14 -> V_106 - 1 ; V_91 ++ , V_105 ++ )
V_105 -> V_108 = V_14 -> V_109 + ( sizeof( struct V_92 ) * ( V_91 + 1 ) ) ;
V_105 -> V_108 = V_14 -> V_109 ;
V_105 -> V_97 = V_110 ;
F_15 ( V_14 , V_87 , V_111 ) ;
F_15 ( V_14 , V_112 , V_113 | V_114 |
V_115 ) ;
F_15 ( V_14 , V_116 , V_14 -> V_109 ) ;
return 0 ;
}
static int F_37 ( struct V_34 * V_14 ,
struct V_12 * V_13 ,
bool V_117 )
{
struct V_118 * V_81 ;
unsigned int V_91 , V_82 ;
if ( ! V_117 && V_13 -> V_80 )
return V_13 -> V_80 ;
if ( V_13 -> V_21 * V_13 -> V_22 < V_119 )
return - V_120 ;
if ( V_13 -> V_22 & 3 )
return - V_120 ;
F_38 (data->sg, sg, data->sg_len, i) {
if ( V_81 -> V_121 & 3 || V_81 -> V_95 & 3 )
return - V_120 ;
}
V_82 = F_39 ( V_14 -> V_69 ,
V_13 -> V_81 ,
V_13 -> V_82 ,
F_24 ( V_13 ) ) ;
if ( V_82 == 0 )
return - V_120 ;
if ( V_117 )
V_13 -> V_80 = V_82 ;
return V_82 ;
}
static void F_40 ( struct V_32 * V_33 ,
struct V_7 * V_8 ,
bool V_122 )
{
struct V_4 * V_5 = F_17 ( V_33 ) ;
struct V_12 * V_13 = V_8 -> V_13 ;
if ( ! V_5 -> V_14 -> V_123 || ! V_13 )
return;
if ( V_13 -> V_80 ) {
V_13 -> V_80 = 0 ;
return;
}
if ( F_37 ( V_5 -> V_14 , V_8 -> V_13 , 1 ) < 0 )
V_13 -> V_80 = 0 ;
}
static void F_41 ( struct V_32 * V_33 ,
struct V_7 * V_8 ,
int V_41 )
{
struct V_4 * V_5 = F_17 ( V_33 ) ;
struct V_12 * V_13 = V_8 -> V_13 ;
if ( ! V_5 -> V_14 -> V_123 || ! V_13 )
return;
if ( V_13 -> V_80 )
F_26 ( V_5 -> V_14 -> V_69 ,
V_13 -> V_81 ,
V_13 -> V_82 ,
F_24 ( V_13 ) ) ;
V_13 -> V_80 = 0 ;
}
static int F_42 ( struct V_34 * V_14 , struct V_12 * V_13 )
{
int V_82 ;
V_43 V_83 ;
V_14 -> V_74 = 0 ;
if ( ! V_14 -> V_123 )
return - V_124 ;
V_82 = F_37 ( V_14 , V_13 , 0 ) ;
if ( V_82 < 0 ) {
V_14 -> V_75 -> V_11 ( V_14 ) ;
return V_82 ;
}
V_14 -> V_74 = 1 ;
F_19 ( V_14 -> V_69 ,
L_17 ,
( unsigned long ) V_14 -> V_94 , ( unsigned long ) V_14 -> V_109 ,
V_82 ) ;
V_83 = F_28 ( V_14 , V_84 ) ;
V_83 |= V_125 ;
F_15 ( V_14 , V_84 , V_83 ) ;
V_83 = F_28 ( V_14 , V_126 ) ;
V_83 &= ~ ( V_127 | V_128 ) ;
F_15 ( V_14 , V_126 , V_83 ) ;
V_14 -> V_75 -> V_129 ( V_14 , V_82 ) ;
return 0 ;
}
static void F_43 ( struct V_34 * V_14 , struct V_12 * V_13 )
{
V_43 V_83 ;
V_13 -> error = - V_52 ;
F_44 ( V_14 -> V_13 ) ;
V_14 -> V_81 = NULL ;
V_14 -> V_13 = V_13 ;
if ( V_13 -> V_18 & V_130 )
V_14 -> V_131 = V_132 ;
else
V_14 -> V_131 = V_133 ;
if ( F_42 ( V_14 , V_13 ) ) {
int V_18 = V_134 ;
if ( V_14 -> V_13 -> V_18 & V_130 )
V_18 |= V_135 ;
else
V_18 |= V_136 ;
F_45 ( & V_14 -> V_137 , V_13 -> V_81 , V_13 -> V_82 , V_18 ) ;
V_14 -> V_81 = V_13 -> V_81 ;
V_14 -> V_138 = 0 ;
V_14 -> V_139 = 0 ;
F_15 ( V_14 , V_140 , V_128 | V_127 ) ;
V_83 = F_28 ( V_14 , V_126 ) ;
V_83 |= V_128 | V_127 ;
F_15 ( V_14 , V_126 , V_83 ) ;
V_83 = F_28 ( V_14 , V_84 ) ;
V_83 &= ~ V_125 ;
F_15 ( V_14 , V_84 , V_83 ) ;
}
}
static void F_46 ( struct V_4 * V_5 , V_43 V_10 , V_43 V_17 )
{
struct V_34 * V_14 = V_5 -> V_14 ;
unsigned long V_141 = V_142 + F_47 ( 500 ) ;
unsigned int V_143 = 0 ;
F_15 ( V_14 , V_70 , V_17 ) ;
F_20 () ;
F_15 ( V_14 , V_71 , V_72 | V_10 ) ;
while ( F_48 ( V_142 , V_141 ) ) {
V_143 = F_28 ( V_14 , V_71 ) ;
if ( ! ( V_143 & V_72 ) )
return;
}
F_13 ( & V_5 -> V_33 -> V_47 ,
L_18 ,
V_10 , V_17 , V_143 ) ;
}
static void F_49 ( struct V_4 * V_5 , bool V_144 )
{
struct V_34 * V_14 = V_5 -> V_14 ;
V_43 div ;
V_43 V_145 ;
if ( V_5 -> clock != V_14 -> V_146 || V_144 ) {
div = V_14 -> V_147 / V_5 -> clock ;
if ( V_14 -> V_147 % V_5 -> clock && V_14 -> V_147 > V_5 -> clock )
div += 1 ;
div = ( V_14 -> V_147 != V_5 -> clock ) ? F_50 ( div , 2 ) : 0 ;
F_51 ( & V_5 -> V_33 -> V_47 ,
L_19
L_20 , V_5 -> V_148 , V_14 -> V_147 , V_5 -> clock ,
div ? ( ( V_14 -> V_147 / div ) >> 1 ) : V_14 -> V_147 , div ) ;
F_15 ( V_14 , V_149 , 0 ) ;
F_15 ( V_14 , V_150 , 0 ) ;
F_46 ( V_5 ,
V_151 | V_55 , 0 ) ;
F_15 ( V_14 , V_152 , div ) ;
F_46 ( V_5 ,
V_151 | V_55 , 0 ) ;
V_145 = V_153 << V_5 -> V_148 ;
if ( ! ( F_28 ( V_14 , V_126 ) & F_52 ( V_5 -> V_148 ) ) )
V_145 |= V_154 << V_5 -> V_148 ;
F_15 ( V_14 , V_149 , V_145 ) ;
F_46 ( V_5 ,
V_151 | V_55 , 0 ) ;
V_14 -> V_146 = V_5 -> clock ;
}
F_15 ( V_14 , V_155 , ( V_5 -> V_156 << V_5 -> V_148 ) ) ;
}
static void F_53 ( struct V_34 * V_14 ,
struct V_4 * V_5 ,
struct V_9 * V_10 )
{
struct V_7 * V_8 ;
struct V_12 * V_13 ;
V_43 V_157 ;
V_8 = V_5 -> V_8 ;
if ( V_14 -> V_158 -> V_159 )
V_14 -> V_158 -> V_159 ( V_5 -> V_148 ) ;
V_14 -> V_160 = V_5 ;
V_14 -> V_8 = V_8 ;
V_14 -> V_45 = 0 ;
V_14 -> V_46 = 0 ;
V_14 -> V_161 = 0 ;
V_13 = V_10 -> V_13 ;
if ( V_13 ) {
F_14 ( V_14 ) ;
F_15 ( V_14 , V_162 , V_13 -> V_22 * V_13 -> V_21 ) ;
F_15 ( V_14 , V_163 , V_13 -> V_22 ) ;
}
V_157 = F_16 ( V_5 -> V_33 , V_10 ) ;
if ( F_54 ( V_164 , & V_5 -> V_18 ) )
V_157 |= V_165 ;
if ( V_13 ) {
F_43 ( V_14 , V_13 ) ;
F_20 () ;
}
F_18 ( V_14 , V_10 , V_157 ) ;
if ( V_8 -> V_11 )
V_14 -> V_73 = F_16 ( V_5 -> V_33 , V_8 -> V_11 ) ;
}
static void F_55 ( struct V_34 * V_14 ,
struct V_4 * V_5 )
{
struct V_7 * V_8 = V_5 -> V_8 ;
struct V_9 * V_10 ;
V_10 = V_8 -> V_166 ? V_8 -> V_166 : V_8 -> V_10 ;
F_53 ( V_14 , V_5 , V_10 ) ;
}
static void F_56 ( struct V_34 * V_14 , struct V_4 * V_5 ,
struct V_7 * V_8 )
{
F_19 ( & V_5 -> V_33 -> V_47 , L_21 ,
V_14 -> V_44 ) ;
V_5 -> V_8 = V_8 ;
if ( V_14 -> V_44 == V_167 ) {
V_14 -> V_44 = V_168 ;
F_55 ( V_14 , V_5 ) ;
} else {
F_57 ( & V_5 -> V_169 , & V_14 -> V_170 ) ;
}
}
static void F_58 ( struct V_32 * V_33 , struct V_7 * V_8 )
{
struct V_4 * V_5 = F_17 ( V_33 ) ;
struct V_34 * V_14 = V_5 -> V_14 ;
F_44 ( V_5 -> V_8 ) ;
F_2 ( & V_14 -> V_15 ) ;
if ( ! F_59 ( V_171 , & V_5 -> V_18 ) ) {
F_4 ( & V_14 -> V_15 ) ;
V_8 -> V_10 -> error = - V_172 ;
F_60 ( V_33 , V_8 ) ;
return;
}
F_56 ( V_14 , V_5 , V_8 ) ;
F_4 ( & V_14 -> V_15 ) ;
}
static void F_61 ( struct V_32 * V_33 , struct V_173 * V_174 )
{
struct V_4 * V_5 = F_17 ( V_33 ) ;
const struct V_49 * V_50 = V_5 -> V_14 -> V_50 ;
V_43 V_175 ;
switch ( V_174 -> V_176 ) {
case V_177 :
V_5 -> V_156 = V_178 ;
break;
case V_179 :
V_5 -> V_156 = V_180 ;
break;
default:
V_5 -> V_156 = V_181 ;
}
V_175 = F_28 ( V_5 -> V_14 , V_182 ) ;
if ( V_174 -> V_183 == V_184 )
V_175 |= ( 0x1 << V_5 -> V_148 ) << 16 ;
else
V_175 &= ~ ( 0x1 << V_5 -> V_148 ) << 16 ;
F_15 ( V_5 -> V_14 , V_182 , V_175 ) ;
if ( V_174 -> clock ) {
V_5 -> clock = V_174 -> clock ;
}
if ( V_50 && V_50 -> V_185 )
V_50 -> V_185 ( V_5 -> V_14 , V_174 ) ;
F_49 ( V_5 , false ) ;
switch ( V_174 -> V_186 ) {
case V_187 :
F_23 ( V_164 , & V_5 -> V_18 ) ;
break;
default:
break;
}
}
static int F_62 ( struct V_32 * V_33 )
{
int V_188 ;
struct V_4 * V_5 = F_17 ( V_33 ) ;
struct V_189 * V_190 = V_5 -> V_14 -> V_158 ;
if ( V_5 -> V_191 & V_192 )
V_188 = 0 ;
else if ( V_190 -> V_193 )
V_188 = V_190 -> V_193 ( V_5 -> V_148 ) ;
else if ( F_63 ( V_5 -> V_194 ) )
V_188 = F_64 ( V_5 -> V_194 ) ;
else
V_188 =
F_28 ( V_5 -> V_14 , V_195 ) & ( 1 << V_5 -> V_148 ) ? 1 : 0 ;
F_65 ( & V_33 -> V_47 , L_22 ,
V_188 ? L_23 : L_24 ) ;
return V_188 ;
}
static int F_66 ( struct V_32 * V_33 )
{
int V_196 ;
struct V_4 * V_5 = F_17 ( V_33 ) ;
struct V_189 * V_190 = V_5 -> V_14 -> V_158 ;
if ( V_190 -> V_191 & V_197 )
V_196 = 1 ;
else if ( V_190 -> V_198 )
V_196 = ! V_190 -> V_198 ( V_5 -> V_148 ) ;
else
V_196 = ( F_28 ( V_5 -> V_14 , V_199 ) & ( 1 << V_5 -> V_148 ) )
== 0 ? 1 : 0 ;
if ( V_196 )
F_65 ( & V_33 -> V_47 , L_25 ) ;
else
F_65 ( & V_33 -> V_47 , L_26 ) ;
return V_196 ;
}
static void F_67 ( struct V_4 * V_5 )
{
struct V_34 * V_14 = V_5 -> V_14 ;
V_43 V_145 ;
const V_43 V_200 = V_154 << V_5 -> V_148 ;
V_145 = F_28 ( V_14 , V_149 ) ;
if ( V_145 & V_200 ) {
F_15 ( V_14 , V_149 , V_145 & ~ V_200 ) ;
F_46 ( V_5 , V_151 |
V_55 , 0 ) ;
}
}
static void F_68 ( struct V_32 * V_33 , int V_201 )
{
struct V_4 * V_5 = F_17 ( V_33 ) ;
struct V_34 * V_14 = V_5 -> V_14 ;
V_43 V_202 ;
V_202 = F_28 ( V_14 , V_126 ) ;
if ( V_201 ) {
F_67 ( V_5 ) ;
F_15 ( V_14 , V_126 ,
( V_202 | F_52 ( V_5 -> V_148 ) ) ) ;
} else {
F_15 ( V_14 , V_126 ,
( V_202 & ~ F_52 ( V_5 -> V_148 ) ) ) ;
}
}
static void F_69 ( struct V_34 * V_14 , struct V_7 * V_8 )
__releases( &host->lock
static void F_70 ( struct V_34 * V_14 , struct V_9 * V_10 )
{
V_43 V_203 = V_14 -> V_143 ;
V_14 -> V_143 = 0 ;
if ( V_10 -> V_18 & V_56 ) {
if ( V_10 -> V_18 & V_58 ) {
V_10 -> V_19 [ 3 ] = F_28 ( V_14 , V_204 ) ;
V_10 -> V_19 [ 2 ] = F_28 ( V_14 , V_205 ) ;
V_10 -> V_19 [ 1 ] = F_28 ( V_14 , V_206 ) ;
V_10 -> V_19 [ 0 ] = F_28 ( V_14 , V_207 ) ;
} else {
V_10 -> V_19 [ 0 ] = F_28 ( V_14 , V_204 ) ;
V_10 -> V_19 [ 1 ] = 0 ;
V_10 -> V_19 [ 2 ] = 0 ;
V_10 -> V_19 [ 3 ] = 0 ;
}
}
if ( V_203 & V_208 )
V_10 -> error = - V_209 ;
else if ( ( V_10 -> V_18 & V_60 ) && ( V_203 & V_210 ) )
V_10 -> error = - V_211 ;
else if ( V_203 & V_212 )
V_10 -> error = - V_213 ;
else
V_10 -> error = 0 ;
if ( V_10 -> error ) {
if ( V_14 -> V_191 & V_214 )
F_71 ( 20 ) ;
if ( V_10 -> V_13 ) {
F_22 ( V_14 ) ;
V_14 -> V_13 = NULL ;
}
}
}
static void F_72 ( unsigned long V_215 )
{
struct V_34 * V_14 = (struct V_34 * ) V_215 ;
struct V_12 * V_13 ;
struct V_9 * V_10 ;
enum V_216 V_44 ;
enum V_216 V_217 ;
V_43 V_203 , V_218 ;
F_73 ( & V_14 -> V_15 ) ;
V_44 = V_14 -> V_44 ;
V_13 = V_14 -> V_13 ;
do {
V_217 = V_44 ;
switch ( V_44 ) {
case V_167 :
break;
case V_168 :
if ( ! F_54 ( V_219 ,
& V_14 -> V_45 ) )
break;
V_10 = V_14 -> V_10 ;
V_14 -> V_10 = NULL ;
F_23 ( V_219 , & V_14 -> V_46 ) ;
F_70 ( V_14 , V_10 ) ;
if ( V_10 == V_14 -> V_8 -> V_166 && ! V_10 -> error ) {
V_217 = V_44 = V_168 ;
F_53 ( V_14 , V_14 -> V_160 ,
V_14 -> V_8 -> V_10 ) ;
goto V_220;
}
if ( ! V_14 -> V_8 -> V_13 || V_10 -> error ) {
F_69 ( V_14 , V_14 -> V_8 ) ;
goto V_220;
}
V_217 = V_44 = V_221 ;
case V_221 :
if ( F_54 ( V_222 ,
& V_14 -> V_45 ) ) {
F_22 ( V_14 ) ;
if ( V_13 -> V_11 )
F_21 ( V_14 , V_13 ) ;
V_44 = V_223 ;
break;
}
if ( ! F_54 ( V_77 ,
& V_14 -> V_45 ) )
break;
F_23 ( V_77 , & V_14 -> V_46 ) ;
V_217 = V_44 = V_224 ;
case V_224 :
if ( ! F_54 ( V_225 ,
& V_14 -> V_45 ) )
break;
V_14 -> V_13 = NULL ;
F_23 ( V_225 , & V_14 -> V_46 ) ;
V_203 = V_14 -> V_161 ;
if ( V_203 & V_226 ) {
if ( V_203 & V_227 ) {
V_13 -> error = - V_209 ;
} else if ( V_203 & V_228 ) {
V_13 -> error = - V_211 ;
} else if ( V_203 & V_229 &&
V_14 -> V_131 ==
V_133 ) {
V_13 -> V_20 = 0 ;
V_13 -> error = - V_209 ;
} else {
F_13 ( V_14 -> V_69 ,
L_27
L_28 ,
V_203 ) ;
V_13 -> error = - V_213 ;
}
F_74 ( & V_14 -> V_137 ) ;
V_14 -> V_81 = NULL ;
V_218 = F_28 ( V_14 , V_84 ) ;
V_218 |= V_230 ;
F_15 ( V_14 , V_84 , V_218 ) ;
} else {
V_13 -> V_20 = V_13 -> V_21 * V_13 -> V_22 ;
V_13 -> error = 0 ;
}
if ( ! V_13 -> V_11 ) {
F_69 ( V_14 , V_14 -> V_8 ) ;
goto V_220;
}
if ( V_14 -> V_8 -> V_166 && ! V_13 -> error ) {
V_13 -> V_11 -> error = 0 ;
F_69 ( V_14 , V_14 -> V_8 ) ;
goto V_220;
}
V_217 = V_44 = V_231 ;
if ( ! V_13 -> error )
F_21 ( V_14 , V_13 ) ;
case V_231 :
if ( ! F_54 ( V_219 ,
& V_14 -> V_45 ) )
break;
V_14 -> V_10 = NULL ;
F_70 ( V_14 , V_14 -> V_8 -> V_11 ) ;
F_69 ( V_14 , V_14 -> V_8 ) ;
goto V_220;
case V_223 :
if ( ! F_54 ( V_77 ,
& V_14 -> V_45 ) )
break;
V_44 = V_224 ;
break;
}
} while ( V_44 != V_217 );
V_14 -> V_44 = V_44 ;
V_220:
F_75 ( & V_14 -> V_15 ) ;
}
static void F_76 ( struct V_34 * V_14 , void * V_232 , int V_233 )
{
memcpy ( ( void * ) & V_14 -> V_234 , V_232 , V_233 ) ;
V_14 -> V_139 = V_233 ;
}
static int F_77 ( struct V_34 * V_14 , void * V_232 , int V_233 )
{
V_233 = F_78 ( V_233 , ( 1 << V_14 -> V_235 ) - V_14 -> V_139 ) ;
memcpy ( ( void * ) & V_14 -> V_234 + V_14 -> V_139 , V_232 , V_233 ) ;
V_14 -> V_139 += V_233 ;
return V_233 ;
}
static int F_79 ( struct V_34 * V_14 , void * V_232 , int V_233 )
{
V_233 = F_78 ( V_233 , ( int ) V_14 -> V_139 ) ;
if ( V_233 ) {
memcpy ( V_232 , ( void * ) & V_14 -> V_234 + V_14 -> V_138 ,
V_233 ) ;
V_14 -> V_139 -= V_233 ;
V_14 -> V_138 += V_233 ;
}
return V_233 ;
}
static void F_80 ( struct V_34 * V_14 , void * V_232 , int V_233 )
{
memcpy ( V_232 , & V_14 -> V_234 , V_233 ) ;
V_14 -> V_138 = V_233 ;
V_14 -> V_139 = ( 1 << V_14 -> V_235 ) - V_233 ;
}
static void F_81 ( struct V_34 * V_14 , void * V_232 , int V_233 )
{
if ( F_82 ( V_14 -> V_139 ) ) {
int V_236 = F_77 ( V_14 , V_232 , V_233 ) ;
V_232 += V_236 ;
V_233 -= V_236 ;
if ( ! F_83 ( V_14 -> V_81 ) || V_14 -> V_139 == 2 ) {
F_84 ( V_14 , F_85 ( V_14 -> V_237 ) ,
V_14 -> V_238 ) ;
V_14 -> V_139 = 0 ;
}
}
#ifndef F_86
if ( F_82 ( ( unsigned long ) V_232 & 0x1 ) ) {
while ( V_233 >= 2 ) {
T_1 V_239 [ 64 ] ;
int V_236 = F_78 ( V_233 & - 2 , ( int ) sizeof( V_239 ) ) ;
int V_240 = V_236 >> 1 ;
int V_91 ;
memcpy ( V_239 , V_232 , V_236 ) ;
V_232 += V_236 ;
V_233 -= V_236 ;
for ( V_91 = 0 ; V_91 < V_240 ; ++ V_91 )
F_84 ( V_14 , F_85 ( V_14 -> V_237 ) ,
V_239 [ V_91 ] ) ;
}
} else
#endif
{
T_1 * V_158 = V_232 ;
for (; V_233 >= 2 ; V_233 -= 2 )
F_84 ( V_14 , F_85 ( V_14 -> V_237 ) , * V_158 ++ ) ;
V_232 = V_158 ;
}
if ( V_233 ) {
F_76 ( V_14 , V_232 , V_233 ) ;
if ( ! F_83 ( V_14 -> V_81 ) )
F_84 ( V_14 , F_85 ( V_14 -> V_237 ) ,
V_14 -> V_238 ) ;
}
}
static void F_87 ( struct V_34 * V_14 , void * V_232 , int V_233 )
{
#ifndef F_86
if ( F_82 ( ( unsigned long ) V_232 & 0x1 ) ) {
while ( V_233 >= 2 ) {
T_1 V_239 [ 64 ] ;
int V_236 = F_78 ( V_233 & - 2 , ( int ) sizeof( V_239 ) ) ;
int V_240 = V_236 >> 1 ;
int V_91 ;
for ( V_91 = 0 ; V_91 < V_240 ; ++ V_91 )
V_239 [ V_91 ] = F_88 ( V_14 ,
F_85 ( V_14 -> V_237 ) ) ;
memcpy ( V_232 , V_239 , V_236 ) ;
V_232 += V_236 ;
V_233 -= V_236 ;
}
} else
#endif
{
T_1 * V_158 = V_232 ;
for (; V_233 >= 2 ; V_233 -= 2 )
* V_158 ++ = F_88 ( V_14 , F_85 ( V_14 -> V_237 ) ) ;
V_232 = V_158 ;
}
if ( V_233 ) {
V_14 -> V_238 = F_88 ( V_14 , F_85 ( V_14 -> V_237 ) ) ;
F_80 ( V_14 , V_232 , V_233 ) ;
}
}
static void F_89 ( struct V_34 * V_14 , void * V_232 , int V_233 )
{
if ( F_82 ( V_14 -> V_139 ) ) {
int V_236 = F_77 ( V_14 , V_232 , V_233 ) ;
V_232 += V_236 ;
V_233 -= V_236 ;
if ( ! F_83 ( V_14 -> V_81 ) || V_14 -> V_139 == 4 ) {
F_15 ( V_14 , F_85 ( V_14 -> V_237 ) ,
V_14 -> V_241 ) ;
V_14 -> V_139 = 0 ;
}
}
#ifndef F_86
if ( F_82 ( ( unsigned long ) V_232 & 0x3 ) ) {
while ( V_233 >= 4 ) {
V_43 V_239 [ 32 ] ;
int V_236 = F_78 ( V_233 & - 4 , ( int ) sizeof( V_239 ) ) ;
int V_240 = V_236 >> 2 ;
int V_91 ;
memcpy ( V_239 , V_232 , V_236 ) ;
V_232 += V_236 ;
V_233 -= V_236 ;
for ( V_91 = 0 ; V_91 < V_240 ; ++ V_91 )
F_15 ( V_14 , F_85 ( V_14 -> V_237 ) ,
V_239 [ V_91 ] ) ;
}
} else
#endif
{
V_43 * V_158 = V_232 ;
for (; V_233 >= 4 ; V_233 -= 4 )
F_15 ( V_14 , F_85 ( V_14 -> V_237 ) , * V_158 ++ ) ;
V_232 = V_158 ;
}
if ( V_233 ) {
F_76 ( V_14 , V_232 , V_233 ) ;
if ( ! F_83 ( V_14 -> V_81 ) )
F_15 ( V_14 , F_85 ( V_14 -> V_237 ) ,
V_14 -> V_241 ) ;
}
}
static void F_90 ( struct V_34 * V_14 , void * V_232 , int V_233 )
{
#ifndef F_86
if ( F_82 ( ( unsigned long ) V_232 & 0x3 ) ) {
while ( V_233 >= 4 ) {
V_43 V_239 [ 32 ] ;
int V_236 = F_78 ( V_233 & - 4 , ( int ) sizeof( V_239 ) ) ;
int V_240 = V_236 >> 2 ;
int V_91 ;
for ( V_91 = 0 ; V_91 < V_240 ; ++ V_91 )
V_239 [ V_91 ] = F_28 ( V_14 ,
F_85 ( V_14 -> V_237 ) ) ;
memcpy ( V_232 , V_239 , V_236 ) ;
V_232 += V_236 ;
V_233 -= V_236 ;
}
} else
#endif
{
V_43 * V_158 = V_232 ;
for (; V_233 >= 4 ; V_233 -= 4 )
* V_158 ++ = F_28 ( V_14 , F_85 ( V_14 -> V_237 ) ) ;
V_232 = V_158 ;
}
if ( V_233 ) {
V_14 -> V_241 = F_28 ( V_14 , F_85 ( V_14 -> V_237 ) ) ;
F_80 ( V_14 , V_232 , V_233 ) ;
}
}
static void F_91 ( struct V_34 * V_14 , void * V_232 , int V_233 )
{
if ( F_82 ( V_14 -> V_139 ) ) {
int V_236 = F_77 ( V_14 , V_232 , V_233 ) ;
V_232 += V_236 ;
V_233 -= V_236 ;
if ( ! F_83 ( V_14 -> V_81 ) || V_14 -> V_139 == 8 ) {
F_84 ( V_14 , F_85 ( V_14 -> V_237 ) ,
V_14 -> V_234 ) ;
V_14 -> V_139 = 0 ;
}
}
#ifndef F_86
if ( F_82 ( ( unsigned long ) V_232 & 0x7 ) ) {
while ( V_233 >= 8 ) {
T_2 V_239 [ 16 ] ;
int V_236 = F_78 ( V_233 & - 8 , ( int ) sizeof( V_239 ) ) ;
int V_240 = V_236 >> 3 ;
int V_91 ;
memcpy ( V_239 , V_232 , V_236 ) ;
V_232 += V_236 ;
V_233 -= V_236 ;
for ( V_91 = 0 ; V_91 < V_240 ; ++ V_91 )
F_92 ( V_14 , F_85 ( V_14 -> V_237 ) ,
V_239 [ V_91 ] ) ;
}
} else
#endif
{
T_2 * V_158 = V_232 ;
for (; V_233 >= 8 ; V_233 -= 8 )
F_92 ( V_14 , F_85 ( V_14 -> V_237 ) , * V_158 ++ ) ;
V_232 = V_158 ;
}
if ( V_233 ) {
F_76 ( V_14 , V_232 , V_233 ) ;
if ( ! F_83 ( V_14 -> V_81 ) )
F_92 ( V_14 , F_85 ( V_14 -> V_237 ) ,
V_14 -> V_234 ) ;
}
}
static void F_93 ( struct V_34 * V_14 , void * V_232 , int V_233 )
{
#ifndef F_86
if ( F_82 ( ( unsigned long ) V_232 & 0x7 ) ) {
while ( V_233 >= 8 ) {
T_2 V_239 [ 16 ] ;
int V_236 = F_78 ( V_233 & - 8 , ( int ) sizeof( V_239 ) ) ;
int V_240 = V_236 >> 3 ;
int V_91 ;
for ( V_91 = 0 ; V_91 < V_240 ; ++ V_91 )
V_239 [ V_91 ] = F_94 ( V_14 ,
F_85 ( V_14 -> V_237 ) ) ;
memcpy ( V_232 , V_239 , V_236 ) ;
V_232 += V_236 ;
V_233 -= V_236 ;
}
} else
#endif
{
T_2 * V_158 = V_232 ;
for (; V_233 >= 8 ; V_233 -= 8 )
* V_158 ++ = F_94 ( V_14 , F_85 ( V_14 -> V_237 ) ) ;
V_232 = V_158 ;
}
if ( V_233 ) {
V_14 -> V_234 = F_94 ( V_14 , F_85 ( V_14 -> V_237 ) ) ;
F_80 ( V_14 , V_232 , V_233 ) ;
}
}
static void F_95 ( struct V_34 * V_14 , void * V_232 , int V_233 )
{
int V_236 ;
V_236 = F_79 ( V_14 , V_232 , V_233 ) ;
if ( F_82 ( V_236 == V_233 ) )
return;
V_232 += V_236 ;
V_233 -= V_236 ;
V_14 -> V_242 ( V_14 , V_232 , V_233 ) ;
}
static void F_96 ( struct V_34 * V_14 )
{
struct V_243 * V_137 = & V_14 -> V_137 ;
void * V_232 ;
unsigned int V_121 ;
struct V_12 * V_13 = V_14 -> V_13 ;
int V_244 = V_14 -> V_235 ;
V_43 V_203 ;
unsigned int V_245 = 0 , V_236 ;
unsigned int V_246 , V_247 ;
do {
if ( ! F_97 ( V_137 ) )
goto V_248;
V_14 -> V_81 = V_137 -> V_249 . V_81 ;
V_232 = V_137 -> V_250 ;
V_246 = V_137 -> V_95 ;
V_121 = 0 ;
do {
V_247 = ( F_98 ( F_28 ( V_14 , V_251 ) )
<< V_244 ) + V_14 -> V_139 ;
V_236 = F_78 ( V_246 , V_247 ) ;
if ( ! V_236 )
break;
F_95 ( V_14 , ( void * ) ( V_232 + V_121 ) , V_236 ) ;
V_121 += V_236 ;
V_245 += V_236 ;
V_246 -= V_236 ;
} while ( V_246 );
V_137 -> V_252 = V_121 ;
V_203 = F_28 ( V_14 , V_253 ) ;
F_15 ( V_14 , V_140 , V_127 ) ;
} while ( V_203 & V_127 );
V_13 -> V_20 += V_245 ;
if ( ! V_246 ) {
if ( ! F_97 ( V_137 ) )
goto V_248;
V_137 -> V_252 = 0 ;
}
F_74 ( V_137 ) ;
return;
V_248:
V_13 -> V_20 += V_245 ;
F_74 ( V_137 ) ;
V_14 -> V_81 = NULL ;
F_99 () ;
F_23 ( V_77 , & V_14 -> V_45 ) ;
}
static void F_100 ( struct V_34 * V_14 )
{
struct V_243 * V_137 = & V_14 -> V_137 ;
void * V_232 ;
unsigned int V_121 ;
struct V_12 * V_13 = V_14 -> V_13 ;
int V_244 = V_14 -> V_235 ;
V_43 V_203 ;
unsigned int V_245 = 0 , V_236 ;
unsigned int V_254 = V_14 -> V_254 ;
unsigned int V_246 , V_247 ;
do {
if ( ! F_97 ( V_137 ) )
goto V_248;
V_14 -> V_81 = V_137 -> V_249 . V_81 ;
V_232 = V_137 -> V_250 ;
V_246 = V_137 -> V_95 ;
V_121 = 0 ;
do {
V_247 = ( ( V_254 -
F_98 ( F_28 ( V_14 , V_251 ) ) )
<< V_244 ) - V_14 -> V_139 ;
V_236 = F_78 ( V_246 , V_247 ) ;
if ( ! V_236 )
break;
V_14 -> V_255 ( V_14 , ( void * ) ( V_232 + V_121 ) , V_236 ) ;
V_121 += V_236 ;
V_245 += V_236 ;
V_246 -= V_236 ;
} while ( V_246 );
V_137 -> V_252 = V_121 ;
V_203 = F_28 ( V_14 , V_253 ) ;
F_15 ( V_14 , V_140 , V_128 ) ;
} while ( V_203 & V_128 );
V_13 -> V_20 += V_245 ;
if ( ! V_246 ) {
if ( ! F_97 ( V_137 ) )
goto V_248;
V_137 -> V_252 = 0 ;
}
F_74 ( V_137 ) ;
return;
V_248:
V_13 -> V_20 += V_245 ;
F_74 ( V_137 ) ;
V_14 -> V_81 = NULL ;
F_99 () ;
F_23 ( V_77 , & V_14 -> V_45 ) ;
}
static void F_101 ( struct V_34 * V_14 , V_43 V_203 )
{
if ( ! V_14 -> V_143 )
V_14 -> V_143 = V_203 ;
F_99 () ;
F_23 ( V_219 , & V_14 -> V_45 ) ;
F_30 ( & V_14 -> V_90 ) ;
}
static T_3 F_102 ( int V_256 , void * V_257 )
{
struct V_34 * V_14 = V_257 ;
V_43 V_258 ;
unsigned int V_259 = 0 ;
int V_91 ;
do {
V_258 = F_28 ( V_14 , V_253 ) ;
if ( V_14 -> V_191 & V_260 ) {
if ( ! V_258 &&
( ( F_28 ( V_14 , V_251 ) >> 17 ) & 0x1fff ) )
V_258 |= V_261 ;
}
if ( ! V_258 )
break;
if ( V_258 & V_262 ) {
F_15 ( V_14 , V_140 , V_262 ) ;
V_14 -> V_143 = V_258 ;
F_99 () ;
F_23 ( V_219 , & V_14 -> V_45 ) ;
}
if ( V_258 & V_226 ) {
F_15 ( V_14 , V_140 , V_226 ) ;
V_14 -> V_161 = V_258 ;
F_99 () ;
F_23 ( V_222 , & V_14 -> V_45 ) ;
F_30 ( & V_14 -> V_90 ) ;
}
if ( V_258 & V_261 ) {
F_15 ( V_14 , V_140 , V_261 ) ;
if ( ! V_14 -> V_161 )
V_14 -> V_161 = V_258 ;
F_99 () ;
if ( V_14 -> V_131 == V_132 ) {
if ( V_14 -> V_81 != NULL )
F_96 ( V_14 ) ;
}
F_23 ( V_225 , & V_14 -> V_45 ) ;
F_30 ( & V_14 -> V_90 ) ;
}
if ( V_258 & V_127 ) {
F_15 ( V_14 , V_140 , V_127 ) ;
if ( V_14 -> V_131 == V_132 && V_14 -> V_81 )
F_96 ( V_14 ) ;
}
if ( V_258 & V_128 ) {
F_15 ( V_14 , V_140 , V_128 ) ;
if ( V_14 -> V_131 == V_133 && V_14 -> V_81 )
F_100 ( V_14 ) ;
}
if ( V_258 & V_263 ) {
F_15 ( V_14 , V_140 , V_263 ) ;
F_101 ( V_14 , V_258 ) ;
}
if ( V_258 & V_264 ) {
F_15 ( V_14 , V_140 , V_264 ) ;
F_103 ( V_14 -> V_265 , & V_14 -> V_266 ) ;
}
for ( V_91 = 0 ; V_91 < V_14 -> V_267 ; V_91 ++ ) {
struct V_4 * V_5 = V_14 -> V_5 [ V_91 ] ;
if ( V_258 & F_52 ( V_91 ) ) {
F_15 ( V_14 , V_140 , F_52 ( V_91 ) ) ;
F_104 ( V_5 -> V_33 ) ;
}
}
} while ( V_259 ++ < 5 );
#ifdef F_105
V_258 = F_28 ( V_14 , V_268 ) ;
if ( V_258 & ( V_115 | V_114 ) ) {
F_15 ( V_14 , V_268 , V_115 | V_114 ) ;
F_15 ( V_14 , V_268 , V_113 ) ;
V_14 -> V_75 -> V_269 ( V_14 ) ;
}
#endif
return V_270 ;
}
static void F_106 ( struct V_271 * V_272 )
{
struct V_34 * V_14 = F_107 ( V_272 , struct V_34 , V_266 ) ;
int V_91 ;
for ( V_91 = 0 ; V_91 < V_14 -> V_267 ; V_91 ++ ) {
struct V_4 * V_5 = V_14 -> V_5 [ V_91 ] ;
struct V_32 * V_33 = V_5 -> V_33 ;
struct V_7 * V_8 ;
int V_196 ;
V_43 V_218 ;
V_196 = F_66 ( V_33 ) ;
while ( V_196 != V_5 -> V_273 ) {
F_65 ( & V_5 -> V_33 -> V_47 , L_29 ,
V_196 ? L_30 : L_31 ) ;
if ( V_196 != 0 && V_14 -> V_158 -> V_274 )
V_14 -> V_158 -> V_274 ( V_5 -> V_148 , V_33 -> V_275 ) ;
F_2 ( & V_14 -> V_15 ) ;
V_5 -> V_273 = V_196 ;
if ( V_196 != 0 )
F_23 ( V_171 , & V_5 -> V_18 ) ;
V_8 = V_5 -> V_8 ;
if ( V_8 ) {
if ( V_8 == V_14 -> V_8 ) {
V_14 -> V_13 = NULL ;
V_14 -> V_10 = NULL ;
switch ( V_14 -> V_44 ) {
case V_167 :
break;
case V_168 :
V_8 -> V_10 -> error = - V_172 ;
if ( ! V_8 -> V_13 )
break;
case V_221 :
V_8 -> V_13 -> error = - V_172 ;
F_22 ( V_14 ) ;
break;
case V_224 :
case V_223 :
if ( V_8 -> V_13 -> error == - V_52 )
V_8 -> V_13 -> error = - V_172 ;
if ( ! V_8 -> V_11 )
break;
case V_231 :
V_8 -> V_11 -> error = - V_172 ;
break;
}
F_69 ( V_14 , V_8 ) ;
} else {
F_108 ( & V_5 -> V_169 ) ;
V_8 -> V_10 -> error = - V_172 ;
if ( V_8 -> V_13 )
V_8 -> V_13 -> error = - V_172 ;
if ( V_8 -> V_11 )
V_8 -> V_11 -> error = - V_172 ;
F_75 ( & V_14 -> V_15 ) ;
F_60 ( V_5 -> V_33 , V_8 ) ;
F_73 ( & V_14 -> V_15 ) ;
}
}
if ( V_196 == 0 ) {
F_109 ( V_171 , & V_5 -> V_18 ) ;
F_74 ( & V_14 -> V_137 ) ;
V_14 -> V_81 = NULL ;
V_218 = F_28 ( V_14 , V_84 ) ;
V_218 |= V_230 ;
F_15 ( V_14 , V_84 , V_218 ) ;
#ifdef F_105
V_218 = F_28 ( V_14 , V_87 ) ;
V_218 |= V_111 ;
F_15 ( V_14 , V_87 , V_218 ) ;
#endif
}
F_4 ( & V_14 -> V_15 ) ;
if ( V_196 == 0 && V_14 -> V_158 -> V_274 )
V_14 -> V_158 -> V_274 ( V_5 -> V_148 , 0 ) ;
V_196 = F_66 ( V_33 ) ;
}
F_110 ( V_5 -> V_33 ,
F_47 ( V_14 -> V_158 -> V_276 ) ) ;
}
}
static struct V_277 * F_111 ( struct V_278 * V_69 , T_4 V_5 )
{
struct V_277 * V_279 ;
const T_5 * V_250 ;
int V_236 ;
if ( ! V_69 || ! V_69 -> V_280 )
return NULL ;
F_112 (dev->of_node, np) {
V_250 = F_113 ( V_279 , L_32 , & V_236 ) ;
if ( ! V_250 || ( V_236 < sizeof( int ) ) )
continue;
if ( F_114 ( V_250 ) == V_5 )
return V_279 ;
}
return NULL ;
}
static int F_115 ( struct V_278 * V_69 , T_4 V_5 )
{
struct V_277 * V_279 = F_111 ( V_69 , V_5 ) ;
int V_191 = 0 ;
int V_281 ;
for ( V_281 = 0 ; V_281 < F_116 ( V_282 ) ; V_281 ++ )
if ( F_113 ( V_279 , V_282 [ V_281 ] . V_283 , NULL ) )
V_191 |= V_282 [ V_281 ] . V_148 ;
return V_191 ;
}
static V_43 F_117 ( struct V_278 * V_69 , T_4 V_5 )
{
struct V_277 * V_279 = F_111 ( V_69 , V_5 ) ;
V_43 V_284 = 1 ;
if ( ! V_279 )
return 1 ;
if ( F_118 ( V_279 , L_33 , & V_284 ) )
F_13 ( V_69 , L_34
L_35 ) ;
return V_284 ;
}
static int F_119 ( struct V_278 * V_69 , T_4 V_5 )
{
struct V_277 * V_279 = F_111 ( V_69 , V_5 ) ;
int V_285 ;
if ( ! V_279 )
return - V_120 ;
V_285 = F_120 ( V_279 , L_36 , 0 ) ;
if ( ! F_63 ( V_285 ) )
return - V_120 ;
if ( F_121 ( V_69 , V_285 , L_37 ) ) {
F_122 ( V_69 , L_38 , V_285 ) ;
return - V_120 ;
}
return V_285 ;
}
static int F_115 ( struct V_278 * V_69 , T_4 V_5 )
{
return 0 ;
}
static V_43 F_117 ( struct V_278 * V_69 , T_4 V_5 )
{
return 1 ;
}
static struct V_277 * F_111 ( struct V_278 * V_69 , T_4 V_5 )
{
return NULL ;
}
static int F_119 ( struct V_278 * V_69 , T_4 V_5 )
{
return - V_120 ;
}
static int F_123 ( struct V_34 * V_14 , unsigned int V_148 )
{
struct V_32 * V_33 ;
struct V_4 * V_5 ;
const struct V_49 * V_50 = V_14 -> V_50 ;
int V_286 , V_287 ;
T_4 V_176 ;
V_33 = F_124 ( sizeof( struct V_4 ) , V_14 -> V_69 ) ;
if ( ! V_33 )
return - V_288 ;
V_5 = F_17 ( V_33 ) ;
V_5 -> V_148 = V_148 ;
V_5 -> V_33 = V_33 ;
V_5 -> V_14 = V_14 ;
V_14 -> V_5 [ V_148 ] = V_5 ;
V_5 -> V_191 = F_115 ( V_14 -> V_69 , V_5 -> V_148 ) ;
V_33 -> V_289 = & V_290 ;
V_33 -> V_291 = F_50 ( V_14 -> V_147 , 510 ) ;
V_33 -> V_292 = V_14 -> V_147 ;
if ( V_14 -> V_158 -> V_293 )
V_33 -> V_275 = V_14 -> V_158 -> V_293 ( V_148 ) ;
else
V_33 -> V_275 = V_294 | V_295 ;
if ( V_14 -> V_158 -> V_274 )
V_14 -> V_158 -> V_274 ( V_148 , 0 ) ;
if ( V_14 -> V_158 -> V_296 )
V_33 -> V_296 = V_14 -> V_158 -> V_296 ;
if ( V_14 -> V_158 -> V_297 )
V_33 -> V_297 = V_14 -> V_158 -> V_297 ;
if ( V_14 -> V_69 -> V_280 ) {
V_286 = F_125 ( V_14 -> V_69 -> V_280 , L_39 ) ;
if ( V_286 < 0 )
V_286 = 0 ;
} else {
V_286 = F_126 ( V_14 -> V_69 ) -> V_148 ;
}
if ( V_50 && V_50 -> V_296 )
V_33 -> V_296 |= V_50 -> V_296 [ V_286 ] ;
if ( V_14 -> V_158 -> V_298 )
V_33 -> V_298 = V_14 -> V_158 -> V_298 ;
if ( V_14 -> V_158 -> V_299 )
V_176 = V_14 -> V_158 -> V_299 ( V_5 -> V_148 ) ;
else if ( V_14 -> V_69 -> V_280 )
V_176 = F_117 ( V_14 -> V_69 , V_5 -> V_148 ) ;
else
V_176 = 1 ;
if ( V_50 && V_50 -> V_300 ) {
struct V_277 * V_301 ;
V_301 = F_111 ( V_14 -> V_69 , V_5 -> V_148 ) ;
V_287 = V_50 -> V_300 ( V_14 , V_301 , V_176 ) ;
if ( V_287 )
goto V_302;
}
switch ( V_176 ) {
case 8 :
V_33 -> V_296 |= V_303 ;
case 4 :
V_33 -> V_296 |= V_304 ;
}
if ( V_14 -> V_158 -> V_191 & V_305 )
V_33 -> V_296 |= V_306 | V_307 ;
if ( V_14 -> V_158 -> V_308 ) {
V_33 -> V_309 = V_14 -> V_158 -> V_308 -> V_309 ;
V_33 -> V_310 = V_14 -> V_158 -> V_308 -> V_310 ;
V_33 -> V_311 = V_14 -> V_158 -> V_308 -> V_311 ;
V_33 -> V_312 = V_14 -> V_158 -> V_308 -> V_312 ;
V_33 -> V_313 = V_14 -> V_158 -> V_308 -> V_313 ;
} else {
#ifdef F_105
V_33 -> V_309 = V_14 -> V_106 ;
V_33 -> V_310 = 65536 ;
V_33 -> V_311 = V_14 -> V_106 ;
V_33 -> V_313 = 0x1000 ;
V_33 -> V_312 = V_33 -> V_313 * V_33 -> V_311 ;
#else
V_33 -> V_309 = 64 ;
V_33 -> V_310 = 65536 ;
V_33 -> V_311 = 512 ;
V_33 -> V_312 = V_33 -> V_310 * V_33 -> V_311 ;
V_33 -> V_313 = V_33 -> V_312 ;
#endif
}
V_14 -> V_314 = F_127 ( F_128 ( V_33 ) , L_40 ) ;
if ( F_129 ( V_14 -> V_314 ) ) {
F_130 ( L_41 , F_131 ( V_33 ) ) ;
V_14 -> V_314 = NULL ;
} else
F_132 ( V_14 -> V_314 ) ;
if ( F_66 ( V_33 ) )
F_23 ( V_171 , & V_5 -> V_18 ) ;
else
F_109 ( V_171 , & V_5 -> V_18 ) ;
V_5 -> V_194 = F_119 ( V_14 -> V_69 , V_5 -> V_148 ) ;
F_133 ( V_33 ) ;
#if F_134 ( V_315 )
F_9 ( V_5 ) ;
#endif
V_5 -> V_273 = 0 ;
F_103 ( V_14 -> V_265 , & V_14 -> V_266 ) ;
return 0 ;
V_302:
F_135 ( V_33 ) ;
return - V_120 ;
}
static void F_136 ( struct V_4 * V_5 , unsigned int V_148 )
{
if ( V_5 -> V_14 -> V_158 -> exit )
V_5 -> V_14 -> V_158 -> exit ( V_148 ) ;
F_137 ( V_5 -> V_33 ) ;
V_5 -> V_14 -> V_5 [ V_148 ] = NULL ;
F_135 ( V_5 -> V_33 ) ;
}
static void F_138 ( struct V_34 * V_14 )
{
V_14 -> V_94 = F_139 ( V_14 -> V_69 , V_107 ,
& V_14 -> V_109 , V_316 ) ;
if ( ! V_14 -> V_94 ) {
F_13 ( V_14 -> V_69 , L_42 ,
V_317 ) ;
goto V_318;
}
#ifdef F_105
V_14 -> V_75 = & V_319 ;
F_51 ( V_14 -> V_69 , L_43 ) ;
#endif
if ( ! V_14 -> V_75 )
goto V_318;
if ( V_14 -> V_75 -> V_320 && V_14 -> V_75 -> V_129 &&
V_14 -> V_75 -> V_11 && V_14 -> V_75 -> V_76 ) {
if ( V_14 -> V_75 -> V_320 ( V_14 ) ) {
F_13 ( V_14 -> V_69 , L_44
L_45 , V_317 ) ;
goto V_318;
}
} else {
F_13 ( V_14 -> V_69 , L_46 ) ;
goto V_318;
}
V_14 -> V_123 = 1 ;
return;
V_318:
F_51 ( V_14 -> V_69 , L_47 ) ;
V_14 -> V_123 = 0 ;
return;
}
static bool F_140 ( struct V_278 * V_69 , struct V_34 * V_14 )
{
unsigned long V_141 = V_142 + F_47 ( 500 ) ;
unsigned int V_218 ;
F_15 ( V_14 , V_84 , ( V_321 | V_230 |
V_86 ) ) ;
do {
V_218 = F_28 ( V_14 , V_84 ) ;
if ( ! ( V_218 & ( V_321 | V_230 |
V_86 ) ) )
return true ;
} while ( F_48 ( V_142 , V_141 ) );
F_13 ( V_69 , L_48 , V_218 ) ;
return false ;
}
static struct V_189 * F_141 ( struct V_34 * V_14 )
{
struct V_189 * V_158 ;
struct V_278 * V_69 = V_14 -> V_69 ;
struct V_277 * V_279 = V_69 -> V_280 ;
const struct V_49 * V_50 = V_14 -> V_50 ;
int V_281 , V_287 ;
V_158 = F_142 ( V_69 , sizeof( * V_158 ) , V_316 ) ;
if ( ! V_158 ) {
F_13 ( V_69 , L_49 ) ;
return F_143 ( - V_288 ) ;
}
if ( F_118 ( V_69 -> V_280 , L_50 ,
& V_158 -> V_267 ) ) {
F_51 ( V_69 , L_51
L_52 ) ;
V_158 -> V_267 = 1 ;
}
for ( V_281 = 0 ; V_281 < F_116 ( V_322 ) ; V_281 ++ )
if ( F_113 ( V_279 , V_322 [ V_281 ] . V_283 , NULL ) )
V_158 -> V_191 |= V_322 [ V_281 ] . V_148 ;
if ( F_118 ( V_279 , L_53 , & V_158 -> V_254 ) )
F_51 ( V_69 , L_54
L_55 ) ;
F_118 ( V_279 , L_56 , & V_158 -> V_276 ) ;
if ( V_50 && V_50 -> V_323 ) {
V_287 = V_50 -> V_323 ( V_14 ) ;
if ( V_287 )
return F_143 ( V_287 ) ;
}
if ( F_144 ( V_279 , L_57 , NULL ) )
V_158 -> V_297 |= V_324 ;
if ( F_144 ( V_279 , L_58 , NULL ) )
V_158 -> V_297 |= V_325 ;
return V_158 ;
}
static struct V_189 * F_141 ( struct V_34 * V_14 )
{
return F_143 ( - V_120 ) ;
}
int F_145 ( struct V_34 * V_14 )
{
const struct V_49 * V_50 = V_14 -> V_50 ;
int V_326 , V_91 , V_287 = 0 ;
V_43 V_327 ;
int V_328 = 0 ;
if ( ! V_14 -> V_158 ) {
V_14 -> V_158 = F_141 ( V_14 ) ;
if ( F_129 ( V_14 -> V_158 ) ) {
F_13 ( V_14 -> V_69 , L_59 ) ;
return - V_120 ;
}
}
if ( ! V_14 -> V_158 -> V_159 && V_14 -> V_158 -> V_267 > 1 ) {
F_13 ( V_14 -> V_69 ,
L_60 ) ;
return - V_124 ;
}
V_14 -> V_329 = F_146 ( V_14 -> V_69 , L_61 ) ;
if ( F_129 ( V_14 -> V_329 ) ) {
F_65 ( V_14 -> V_69 , L_62 ) ;
} else {
V_287 = F_147 ( V_14 -> V_329 ) ;
if ( V_287 ) {
F_13 ( V_14 -> V_69 , L_63 ) ;
return V_287 ;
}
}
V_14 -> V_330 = F_146 ( V_14 -> V_69 , L_64 ) ;
if ( F_129 ( V_14 -> V_330 ) ) {
F_65 ( V_14 -> V_69 , L_65 ) ;
} else {
V_287 = F_147 ( V_14 -> V_330 ) ;
if ( V_287 ) {
F_13 ( V_14 -> V_69 , L_66 ) ;
goto V_331;
}
}
if ( F_129 ( V_14 -> V_330 ) )
V_14 -> V_147 = V_14 -> V_158 -> V_147 ;
else
V_14 -> V_147 = F_148 ( V_14 -> V_330 ) ;
if ( V_50 && V_50 -> V_332 ) {
V_287 = V_50 -> V_332 ( V_14 ) ;
if ( V_287 ) {
F_13 ( V_14 -> V_69 ,
L_67 ) ;
goto V_333;
}
}
if ( ! V_14 -> V_147 ) {
F_13 ( V_14 -> V_69 ,
L_68 ) ;
V_287 = - V_124 ;
goto V_333;
}
V_14 -> V_191 = V_14 -> V_158 -> V_191 ;
F_149 ( & V_14 -> V_15 ) ;
F_150 ( & V_14 -> V_170 ) ;
V_91 = ( F_28 ( V_14 , V_334 ) >> 7 ) & 0x7 ;
if ( ! V_91 ) {
V_14 -> V_255 = F_81 ;
V_14 -> V_242 = F_87 ;
V_326 = 16 ;
V_14 -> V_235 = 1 ;
} else if ( V_91 == 2 ) {
V_14 -> V_255 = F_91 ;
V_14 -> V_242 = F_93 ;
V_326 = 64 ;
V_14 -> V_235 = 3 ;
} else {
F_151 ( ( V_91 != 1 ) ,
L_69
L_70 ) ;
V_14 -> V_255 = F_89 ;
V_14 -> V_242 = F_90 ;
V_326 = 32 ;
V_14 -> V_235 = 2 ;
}
if ( ! F_140 ( V_14 -> V_69 , V_14 ) )
return - V_124 ;
V_14 -> V_75 = V_14 -> V_158 -> V_75 ;
F_138 ( V_14 ) ;
F_15 ( V_14 , V_140 , 0xFFFFFFFF ) ;
F_15 ( V_14 , V_126 , 0 ) ;
F_15 ( V_14 , V_48 , 0xFFFFFFFF ) ;
if ( ! V_14 -> V_158 -> V_254 ) {
V_327 = F_28 ( V_14 , V_335 ) ;
V_327 = 1 + ( ( V_327 >> 16 ) & 0xfff ) ;
} else {
V_327 = V_14 -> V_158 -> V_254 ;
}
V_14 -> V_254 = V_327 ;
V_14 -> V_336 = ( ( 0x2 << 28 ) | ( ( V_327 / 2 - 1 ) << 16 ) |
( ( V_327 / 2 ) << 0 ) ) ;
F_15 ( V_14 , V_335 , V_14 -> V_336 ) ;
F_15 ( V_14 , V_149 , 0 ) ;
F_15 ( V_14 , V_150 , 0 ) ;
F_152 ( & V_14 -> V_90 , F_72 , ( unsigned long ) V_14 ) ;
V_14 -> V_265 = F_153 ( L_71 ,
V_337 | V_338 , 1 ) ;
if ( ! V_14 -> V_265 )
goto V_339;
F_154 ( & V_14 -> V_266 , F_106 ) ;
V_287 = F_155 ( V_14 -> V_69 , V_14 -> V_256 , F_102 ,
V_14 -> V_340 , L_72 , V_14 ) ;
if ( V_287 )
goto V_341;
if ( V_14 -> V_158 -> V_267 )
V_14 -> V_267 = V_14 -> V_158 -> V_267 ;
else
V_14 -> V_267 = ( ( F_28 ( V_14 , V_334 ) >> 1 ) & 0x1F ) + 1 ;
F_15 ( V_14 , V_140 , 0xFFFFFFFF ) ;
F_15 ( V_14 , V_126 , V_263 | V_261 |
V_128 | V_127 |
V_342 | V_264 ) ;
F_15 ( V_14 , V_84 , V_343 ) ;
F_51 ( V_14 -> V_69 , L_73
L_74
L_75 ,
V_14 -> V_256 , V_326 , V_327 ) ;
for ( V_91 = 0 ; V_91 < V_14 -> V_267 ; V_91 ++ ) {
V_287 = F_123 ( V_14 , V_91 ) ;
if ( V_287 )
F_65 ( V_14 -> V_69 , L_76 , V_91 ) ;
else
V_328 ++ ;
}
if ( V_328 ) {
F_51 ( V_14 -> V_69 , L_77 , V_328 ) ;
} else {
F_65 ( V_14 -> V_69 , L_78
L_79 , V_14 -> V_267 ) ;
goto V_341;
}
V_14 -> V_344 = F_156 ( F_28 ( V_14 , V_345 ) ) ;
F_51 ( V_14 -> V_69 , L_80 , V_14 -> V_344 ) ;
if ( V_14 -> V_344 < V_346 )
V_14 -> V_237 = V_347 ;
else
V_14 -> V_237 = V_348 ;
if ( V_14 -> V_191 & V_260 )
F_51 ( V_14 -> V_69 , L_81 ) ;
return 0 ;
V_341:
F_157 ( V_14 -> V_265 ) ;
V_339:
if ( V_14 -> V_123 && V_14 -> V_75 -> exit )
V_14 -> V_75 -> exit ( V_14 ) ;
if ( V_14 -> V_314 )
F_158 ( V_14 -> V_314 ) ;
V_333:
if ( ! F_129 ( V_14 -> V_330 ) )
F_159 ( V_14 -> V_330 ) ;
V_331:
if ( ! F_129 ( V_14 -> V_329 ) )
F_159 ( V_14 -> V_329 ) ;
return V_287 ;
}
void F_160 ( struct V_34 * V_14 )
{
int V_91 ;
F_15 ( V_14 , V_140 , 0xFFFFFFFF ) ;
F_15 ( V_14 , V_126 , 0 ) ;
for ( V_91 = 0 ; V_91 < V_14 -> V_267 ; V_91 ++ ) {
F_65 ( V_14 -> V_69 , L_82 , V_91 ) ;
if ( V_14 -> V_5 [ V_91 ] )
F_136 ( V_14 -> V_5 [ V_91 ] , V_91 ) ;
}
F_15 ( V_14 , V_149 , 0 ) ;
F_15 ( V_14 , V_150 , 0 ) ;
F_157 ( V_14 -> V_265 ) ;
if ( V_14 -> V_123 && V_14 -> V_75 -> exit )
V_14 -> V_75 -> exit ( V_14 ) ;
if ( V_14 -> V_314 )
F_158 ( V_14 -> V_314 ) ;
if ( ! F_129 ( V_14 -> V_330 ) )
F_159 ( V_14 -> V_330 ) ;
if ( ! F_129 ( V_14 -> V_329 ) )
F_159 ( V_14 -> V_329 ) ;
}
int F_161 ( struct V_34 * V_14 )
{
int V_91 , V_287 = 0 ;
for ( V_91 = 0 ; V_91 < V_14 -> V_267 ; V_91 ++ ) {
struct V_4 * V_5 = V_14 -> V_5 [ V_91 ] ;
if ( ! V_5 )
continue;
V_287 = F_162 ( V_5 -> V_33 ) ;
if ( V_287 < 0 ) {
while ( -- V_91 >= 0 ) {
V_5 = V_14 -> V_5 [ V_91 ] ;
if ( V_5 )
F_163 ( V_14 -> V_5 [ V_91 ] -> V_33 ) ;
}
return V_287 ;
}
}
if ( V_14 -> V_314 )
F_158 ( V_14 -> V_314 ) ;
return 0 ;
}
int F_164 ( struct V_34 * V_14 )
{
int V_91 , V_287 ;
if ( V_14 -> V_314 )
F_132 ( V_14 -> V_314 ) ;
if ( ! F_140 ( V_14 -> V_69 , V_14 ) ) {
V_287 = - V_124 ;
return V_287 ;
}
if ( V_14 -> V_123 && V_14 -> V_75 -> V_320 )
V_14 -> V_75 -> V_320 ( V_14 ) ;
F_15 ( V_14 , V_335 , V_14 -> V_336 ) ;
F_15 ( V_14 , V_140 , 0xFFFFFFFF ) ;
F_15 ( V_14 , V_126 , V_263 | V_261 |
V_128 | V_127 |
V_342 | V_264 ) ;
F_15 ( V_14 , V_84 , V_343 ) ;
for ( V_91 = 0 ; V_91 < V_14 -> V_267 ; V_91 ++ ) {
struct V_4 * V_5 = V_14 -> V_5 [ V_91 ] ;
if ( ! V_5 )
continue;
if ( V_5 -> V_33 -> V_349 & V_324 ) {
F_61 ( V_5 -> V_33 , & V_5 -> V_33 -> V_174 ) ;
F_49 ( V_5 , true ) ;
}
V_287 = F_163 ( V_14 -> V_5 [ V_91 ] -> V_33 ) ;
if ( V_287 < 0 )
return V_287 ;
}
return 0 ;
}
static int T_6 F_165 ( void )
{
F_166 ( V_350 L_83 ) ;
return 0 ;
}
static void T_7 F_167 ( void )
{
}
