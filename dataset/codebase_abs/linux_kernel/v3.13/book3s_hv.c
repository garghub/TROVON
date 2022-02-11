static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 = V_2 -> V_4 ;
T_1 * V_5 ;
V_5 = F_2 ( V_2 ) ;
if ( F_3 ( V_5 ) ) {
F_4 ( V_5 ) ;
++ V_2 -> V_6 . V_7 ;
}
V_3 = F_5 () ;
if ( V_4 != V_3 && V_4 >= 0 && V_4 < V_8 ) {
int V_9 = V_4 + V_2 -> V_10 . V_11 ;
if ( V_12 [ V_9 ] . V_13 . V_14 )
F_6 ( V_9 ) ;
else if ( F_7 ( V_4 ) )
F_8 ( V_4 ) ;
}
F_9 () ;
}
static void F_10 ( struct V_1 * V_2 , int V_4 )
{
struct V_15 * V_16 = V_2 -> V_10 . V_17 ;
unsigned long V_18 ;
F_11 ( & V_2 -> V_10 . V_19 , V_18 ) ;
if ( V_16 -> V_20 == V_2 && V_16 -> V_21 != V_22 &&
V_16 -> V_23 != V_24 ) {
V_16 -> V_25 += F_12 () - V_16 -> V_23 ;
V_16 -> V_23 = V_24 ;
}
if ( V_2 -> V_10 . V_26 == V_27 &&
V_2 -> V_10 . V_28 != V_24 ) {
V_2 -> V_10 . V_29 += F_12 () - V_2 -> V_10 . V_28 ;
V_2 -> V_10 . V_28 = V_24 ;
}
F_13 ( & V_2 -> V_10 . V_19 , V_18 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_10 . V_17 ;
unsigned long V_18 ;
F_11 ( & V_2 -> V_10 . V_19 , V_18 ) ;
if ( V_16 -> V_20 == V_2 && V_16 -> V_21 != V_22 )
V_16 -> V_23 = F_12 () ;
if ( V_2 -> V_10 . V_26 == V_27 )
V_2 -> V_10 . V_28 = F_12 () ;
F_13 ( & V_2 -> V_10 . V_19 , V_18 ) ;
}
static void F_15 ( struct V_1 * V_2 , T_2 V_30 )
{
V_2 -> V_10 . V_31 . V_30 = V_30 ;
F_16 ( V_2 ) ;
}
void F_17 ( struct V_1 * V_2 , T_3 V_32 )
{
V_2 -> V_10 . V_32 = V_32 ;
}
int F_18 ( struct V_1 * V_2 , T_3 V_33 )
{
unsigned long V_34 = 0 ;
struct V_15 * V_16 = V_2 -> V_10 . V_17 ;
if ( V_33 ) {
if ( ! F_19 ( V_35 ) )
return - V_36 ;
switch ( V_33 ) {
case V_37 :
V_34 = V_38 ;
break;
case V_39 :
case V_40 :
break;
default:
return - V_36 ;
}
}
F_20 ( & V_16 -> V_41 ) ;
V_16 -> V_33 = V_33 ;
V_16 -> V_34 = V_34 ;
F_21 ( & V_16 -> V_41 ) ;
return 0 ;
}
void F_22 ( struct V_1 * V_2 )
{
int V_42 ;
F_23 ( L_1 , V_2 , V_2 -> V_43 ) ;
F_23 ( L_2 ,
V_2 -> V_10 . V_44 , V_2 -> V_10 . V_31 . V_30 , V_2 -> V_10 . V_45 ) ;
for ( V_42 = 0 ; V_42 < 16 ; ++ V_42 )
F_23 ( L_3 ,
V_42 , F_24 ( V_2 , V_42 ) ,
V_42 + 16 , F_24 ( V_2 , V_42 + 16 ) ) ;
F_23 ( L_4 ,
V_2 -> V_10 . V_46 , V_2 -> V_10 . V_47 ) ;
F_23 ( L_5 ,
V_2 -> V_10 . V_31 . V_48 , V_2 -> V_10 . V_31 . V_49 ) ;
F_23 ( L_6 ,
V_2 -> V_10 . V_31 . V_50 , V_2 -> V_10 . V_31 . V_51 ) ;
F_23 ( L_7 ,
V_2 -> V_10 . V_31 . V_52 , V_2 -> V_10 . V_31 . V_53 ) ;
F_23 ( L_8 ,
V_2 -> V_10 . V_54 , V_2 -> V_10 . V_55 , V_2 -> V_10 . V_31 . V_56 ) ;
F_23 ( L_9 , V_2 -> V_10 . V_31 . V_57 ) ;
F_23 ( L_10 ,
V_2 -> V_10 . V_58 , V_2 -> V_10 . V_59 ) ;
F_23 ( L_11 , V_2 -> V_10 . V_60 ) ;
for ( V_42 = 0 ; V_42 < V_2 -> V_10 . V_60 ; ++ V_42 )
F_23 ( L_12 ,
V_2 -> V_10 . V_61 [ V_42 ] . V_62 , V_2 -> V_10 . V_61 [ V_42 ] . V_63 ) ;
F_23 ( L_13 ,
V_2 -> V_10 . V_17 -> V_64 , V_2 -> V_65 -> V_10 . V_66 ,
V_2 -> V_10 . V_67 ) ;
}
struct V_1 * F_25 ( struct V_65 * V_65 , int V_68 )
{
int V_42 ;
struct V_1 * V_69 , * V_70 = NULL ;
F_26 ( & V_65 -> V_41 ) ;
F_27 (r, v, kvm) {
if ( V_69 -> V_43 == V_68 ) {
V_70 = V_69 ;
break;
}
}
F_28 ( & V_65 -> V_41 ) ;
return V_70 ;
}
static void F_29 ( struct V_1 * V_2 , struct V_71 * V_72 )
{
V_72 -> V_73 |= V_74 ;
V_72 -> V_75 = 1 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_76 * V_69 ,
unsigned long V_77 , unsigned long V_78 )
{
if ( V_77 & ( V_79 - 1 ) )
return - V_36 ;
F_20 ( & V_2 -> V_10 . V_80 ) ;
if ( V_69 -> V_81 != V_77 || V_69 -> V_78 != V_78 ) {
V_69 -> V_81 = V_77 ;
V_69 -> V_78 = V_77 ? V_78 : 0 ;
V_69 -> V_82 = 1 ;
}
F_21 ( & V_2 -> V_10 . V_80 ) ;
return 0 ;
}
static int F_31 ( struct V_76 * V_83 )
{
if ( V_83 -> V_82 )
return V_83 -> V_81 != 0 ;
return V_83 -> V_84 != NULL ;
}
static unsigned long F_32 ( struct V_1 * V_2 ,
unsigned long V_18 ,
unsigned long V_85 , unsigned long V_72 )
{
struct V_65 * V_65 = V_2 -> V_65 ;
unsigned long V_78 , V_86 ;
void * V_87 ;
struct V_1 * V_88 ;
int V_89 ;
int V_90 ;
struct V_76 * V_83 ;
V_88 = F_25 ( V_65 , V_85 ) ;
if ( ! V_88 )
return V_91 ;
V_90 = ( V_18 >> V_92 ) & V_93 ;
if ( V_90 == V_94 || V_90 == V_95 ||
V_90 == V_96 ) {
if ( ( V_72 & ( V_79 - 1 ) ) || ! V_72 )
return V_91 ;
V_87 = F_33 ( V_65 , V_72 , & V_86 ) ;
if ( V_87 == NULL )
return V_91 ;
if ( V_90 == V_94 )
V_78 = ( (struct V_97 * ) V_87 ) -> V_98 . V_99 ;
else
V_78 = ( (struct V_97 * ) V_87 ) -> V_98 . V_100 ;
F_34 ( V_65 , V_87 , V_72 , false ) ;
if ( V_78 > V_86 || V_78 < sizeof( struct V_97 ) )
return V_91 ;
} else {
V_72 = 0 ;
V_78 = 0 ;
}
V_89 = V_91 ;
V_83 = NULL ;
F_20 ( & V_88 -> V_10 . V_80 ) ;
switch ( V_90 ) {
case V_94 :
if ( V_78 < sizeof( struct V_71 ) )
break;
V_83 = & V_88 -> V_10 . V_72 ;
V_89 = 0 ;
break;
case V_95 :
if ( V_78 < sizeof( struct V_101 ) )
break;
V_78 -= V_78 % sizeof( struct V_101 ) ;
V_89 = V_102 ;
if ( ! F_31 ( & V_88 -> V_10 . V_72 ) )
break;
V_83 = & V_88 -> V_10 . V_103 ;
V_89 = 0 ;
break;
case V_96 :
V_89 = V_102 ;
if ( ! F_31 ( & V_88 -> V_10 . V_72 ) )
break;
V_83 = & V_88 -> V_10 . V_104 ;
V_89 = 0 ;
break;
case V_105 :
V_89 = V_102 ;
if ( F_31 ( & V_88 -> V_10 . V_103 ) ||
F_31 ( & V_88 -> V_10 . V_104 ) )
break;
V_83 = & V_88 -> V_10 . V_72 ;
V_89 = 0 ;
break;
case V_106 :
V_83 = & V_88 -> V_10 . V_103 ;
V_89 = 0 ;
break;
case V_107 :
V_83 = & V_88 -> V_10 . V_104 ;
V_89 = 0 ;
break;
}
if ( V_83 ) {
V_83 -> V_81 = V_72 ;
V_83 -> V_78 = V_78 ;
V_83 -> V_82 = 1 ;
}
F_21 ( & V_88 -> V_10 . V_80 ) ;
return V_89 ;
}
static void F_35 ( struct V_1 * V_2 , struct V_76 * V_83 )
{
struct V_65 * V_65 = V_2 -> V_65 ;
void * V_87 ;
unsigned long V_86 ;
unsigned long V_108 ;
for (; ; ) {
V_108 = V_83 -> V_81 ;
F_21 ( & V_2 -> V_10 . V_80 ) ;
V_87 = NULL ;
V_86 = 0 ;
if ( V_108 )
V_87 = F_33 ( V_65 , V_108 , & V_86 ) ;
F_20 ( & V_2 -> V_10 . V_80 ) ;
if ( V_108 == V_83 -> V_81 )
break;
if ( V_87 )
F_34 ( V_65 , V_87 , V_108 , false ) ;
}
V_83 -> V_82 = 0 ;
if ( V_87 && V_86 < V_83 -> V_78 ) {
F_34 ( V_65 , V_87 , V_108 , false ) ;
V_87 = NULL ;
}
if ( V_83 -> V_84 )
F_34 ( V_65 , V_83 -> V_84 , V_83 -> V_108 ,
V_83 -> V_109 ) ;
V_83 -> V_108 = V_108 ;
V_83 -> V_84 = V_87 ;
V_83 -> V_109 = false ;
if ( V_87 )
V_83 -> V_110 = V_87 + V_83 -> V_78 ;
}
static void F_36 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_10 . V_72 . V_82 ||
V_2 -> V_10 . V_104 . V_82 ||
V_2 -> V_10 . V_103 . V_82 ) )
return;
F_20 ( & V_2 -> V_10 . V_80 ) ;
if ( V_2 -> V_10 . V_72 . V_82 ) {
F_35 ( V_2 , & V_2 -> V_10 . V_72 ) ;
if ( V_2 -> V_10 . V_72 . V_84 )
F_29 ( V_2 , V_2 -> V_10 . V_72 . V_84 ) ;
}
if ( V_2 -> V_10 . V_103 . V_82 ) {
F_35 ( V_2 , & V_2 -> V_10 . V_103 ) ;
V_2 -> V_10 . V_111 = V_2 -> V_10 . V_103 . V_84 ;
V_2 -> V_10 . V_112 = 0 ;
}
if ( V_2 -> V_10 . V_104 . V_82 )
F_35 ( V_2 , & V_2 -> V_10 . V_104 ) ;
F_21 ( & V_2 -> V_10 . V_80 ) ;
}
static T_2 F_37 ( struct V_15 * V_16 , T_2 V_113 )
{
T_2 V_114 ;
if ( V_16 -> V_21 != V_22 &&
V_16 -> V_20 -> V_10 . V_115 != V_116 ) {
F_38 ( & V_16 -> V_20 -> V_10 . V_19 ) ;
V_114 = V_16 -> V_25 ;
if ( V_16 -> V_23 != V_24 )
V_114 += V_113 - V_16 -> V_23 ;
F_39 ( & V_16 -> V_20 -> V_10 . V_19 ) ;
} else {
V_114 = V_16 -> V_25 ;
}
return V_114 ;
}
static void F_40 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_101 * V_117 ;
struct V_71 * V_72 ;
unsigned long V_118 ;
unsigned long V_119 ;
T_2 V_113 ;
V_117 = V_2 -> V_10 . V_111 ;
V_72 = V_2 -> V_10 . V_72 . V_84 ;
V_113 = F_12 () ;
V_119 = F_37 ( V_16 , V_113 ) ;
V_118 = V_119 - V_2 -> V_10 . V_120 ;
V_2 -> V_10 . V_120 = V_119 ;
F_38 ( & V_2 -> V_10 . V_19 ) ;
V_118 += V_2 -> V_10 . V_29 ;
V_2 -> V_10 . V_29 = 0 ;
F_39 ( & V_2 -> V_10 . V_19 ) ;
if ( ! V_117 || ! V_72 )
return;
memset ( V_117 , 0 , sizeof( struct V_101 ) ) ;
V_117 -> V_121 = 7 ;
V_117 -> V_122 = V_16 -> V_123 + V_2 -> V_10 . V_11 ;
V_117 -> V_124 = V_113 + V_16 -> V_125 ;
V_117 -> V_126 = V_118 ;
V_117 -> V_48 = F_41 ( V_2 ) ;
V_117 -> V_49 = V_2 -> V_10 . V_31 . V_30 ;
++ V_117 ;
if ( V_117 == V_2 -> V_10 . V_103 . V_110 )
V_117 = V_2 -> V_10 . V_103 . V_84 ;
V_2 -> V_10 . V_111 = V_117 ;
F_42 () ;
V_72 -> V_127 = ++ V_2 -> V_10 . V_112 ;
V_2 -> V_10 . V_103 . V_109 = true ;
}
int F_43 ( struct V_1 * V_2 )
{
unsigned long V_128 = F_24 ( V_2 , 3 ) ;
unsigned long V_129 , V_70 = V_130 ;
struct V_1 * V_88 ;
int V_131 , V_132 ;
switch ( V_128 ) {
case V_133 :
V_131 = F_44 ( & V_2 -> V_65 -> V_134 ) ;
V_70 = F_45 ( V_2 , F_24 ( V_2 , 4 ) ,
F_24 ( V_2 , 5 ) ,
F_24 ( V_2 , 6 ) ,
F_24 ( V_2 , 7 ) ) ;
F_46 ( & V_2 -> V_65 -> V_134 , V_131 ) ;
break;
case V_135 :
break;
case V_136 :
V_129 = F_24 ( V_2 , 4 ) ;
V_88 = F_25 ( V_2 -> V_65 , V_129 ) ;
if ( ! V_88 ) {
V_70 = V_91 ;
break;
}
V_88 -> V_10 . V_137 = 1 ;
F_47 () ;
if ( V_2 -> V_10 . V_138 ) {
if ( F_3 ( & V_2 -> V_139 ) ) {
F_4 ( & V_2 -> V_139 ) ;
V_2 -> V_6 . V_7 ++ ;
}
}
break;
case V_140 :
V_129 = F_24 ( V_2 , 4 ) ;
if ( V_129 == - 1 )
break;
V_88 = F_25 ( V_2 -> V_65 , V_129 ) ;
if ( ! V_88 ) {
V_70 = V_91 ;
break;
}
F_48 ( V_88 ) ;
break;
case V_141 :
V_70 = F_32 ( V_2 , F_24 ( V_2 , 4 ) ,
F_24 ( V_2 , 5 ) ,
F_24 ( V_2 , 6 ) ) ;
break;
case V_142 :
if ( F_49 ( & V_2 -> V_65 -> V_10 . V_143 ) )
return V_144 ;
V_131 = F_44 ( & V_2 -> V_65 -> V_134 ) ;
V_132 = F_50 ( V_2 ) ;
F_46 ( & V_2 -> V_65 -> V_134 , V_131 ) ;
if ( V_132 == - V_145 )
return V_144 ;
else if ( V_132 == 0 )
break;
return V_132 ;
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
if ( F_51 ( V_2 ) ) {
V_70 = F_52 ( V_2 , V_128 ) ;
break;
}
default:
return V_144 ;
}
F_53 ( V_2 , 3 , V_70 ) ;
V_2 -> V_10 . V_152 = 0 ;
return V_153 ;
}
static int F_54 ( struct V_154 * V_155 , struct V_1 * V_2 ,
struct V_156 * V_157 )
{
int V_42 = V_144 ;
V_2 -> V_6 . V_158 ++ ;
V_155 -> V_159 = V_160 ;
V_155 -> V_161 = 1 ;
switch ( V_2 -> V_10 . V_45 ) {
case V_162 :
V_2 -> V_6 . V_163 ++ ;
V_42 = V_153 ;
break;
case V_164 :
V_2 -> V_6 . V_165 ++ ;
V_42 = V_153 ;
break;
case V_166 :
V_42 = V_153 ;
break;
case V_167 :
F_55 ( V_2 ,
V_167 ) ;
V_42 = V_153 ;
break;
case V_168 :
{
T_4 V_18 ;
V_18 = V_2 -> V_10 . V_31 . V_30 & 0x1f0000ull ;
F_56 ( V_2 , V_18 ) ;
V_42 = V_153 ;
break;
}
case V_169 :
{
int V_170 ;
if ( V_2 -> V_10 . V_31 . V_30 & V_171 ) {
F_55 ( V_2 , V_169 ) ;
V_42 = V_153 ;
break;
}
V_155 -> V_172 . V_173 = F_24 ( V_2 , 3 ) ;
for ( V_170 = 0 ; V_170 < 9 ; ++ V_170 )
V_155 -> V_172 . args [ V_170 ] = F_24 ( V_2 , 4 + V_170 ) ;
V_155 -> V_159 = V_174 ;
V_2 -> V_10 . V_152 = 1 ;
V_42 = V_144 ;
break;
}
case V_175 :
V_42 = V_176 ;
break;
case V_177 :
V_2 -> V_10 . V_58 = F_41 ( V_2 ) ;
V_2 -> V_10 . V_59 = 0 ;
V_42 = V_176 ;
break;
case V_178 :
F_56 ( V_2 , 0x80000 ) ;
V_42 = V_153 ;
break;
default:
F_22 ( V_2 ) ;
F_57 ( V_179 L_14 ,
V_2 -> V_10 . V_45 , F_41 ( V_2 ) ,
V_2 -> V_10 . V_31 . V_30 ) ;
V_155 -> V_180 . V_181 = V_2 -> V_10 . V_45 ;
V_42 = V_144 ;
break;
}
return V_42 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_182 * V_183 )
{
int V_170 ;
memset ( V_183 , 0 , sizeof( struct V_182 ) ) ;
V_183 -> V_32 = V_2 -> V_10 . V_32 ;
for ( V_170 = 0 ; V_170 < V_2 -> V_10 . V_60 ; V_170 ++ ) {
V_183 -> V_184 . V_185 . V_186 . V_61 [ V_170 ] . V_187 = V_2 -> V_10 . V_61 [ V_170 ] . V_62 ;
V_183 -> V_184 . V_185 . V_186 . V_61 [ V_170 ] . V_188 = V_2 -> V_10 . V_61 [ V_170 ] . V_63 ;
}
return 0 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_182 * V_183 )
{
int V_170 , V_189 ;
F_17 ( V_2 , V_183 -> V_32 ) ;
V_189 = 0 ;
for ( V_170 = 0 ; V_170 < V_2 -> V_10 . V_190 ; V_170 ++ ) {
if ( V_183 -> V_184 . V_185 . V_186 . V_61 [ V_170 ] . V_187 & V_191 ) {
V_2 -> V_10 . V_61 [ V_189 ] . V_62 = V_183 -> V_184 . V_185 . V_186 . V_61 [ V_170 ] . V_187 ;
V_2 -> V_10 . V_61 [ V_189 ] . V_63 = V_183 -> V_184 . V_185 . V_186 . V_61 [ V_170 ] . V_188 ;
++ V_189 ;
}
}
V_2 -> V_10 . V_60 = V_189 ;
return 0 ;
}
static void F_60 ( struct V_1 * V_2 , T_2 V_192 )
{
struct V_15 * V_16 = V_2 -> V_10 . V_17 ;
T_2 V_193 ;
F_20 ( & V_16 -> V_41 ) ;
V_193 = V_194 | V_195 | V_196 ;
V_16 -> V_64 = ( V_16 -> V_64 & ~ V_193 ) | ( V_192 & V_193 ) ;
F_21 ( & V_16 -> V_41 ) ;
}
static int F_61 ( struct V_1 * V_2 , T_2 V_68 ,
union V_197 * V_198 )
{
int V_42 = 0 ;
long int V_170 ;
switch ( V_68 ) {
case V_199 :
* V_198 = F_62 ( V_68 , 0 ) ;
break;
case V_200 :
* V_198 = F_62 ( V_68 , V_2 -> V_10 . V_201 ) ;
break;
case V_202 :
* V_198 = F_62 ( V_68 , V_2 -> V_10 . V_203 ) ;
break;
case V_204 :
* V_198 = F_62 ( V_68 , V_2 -> V_10 . V_205 ) ;
break;
case V_206 :
* V_198 = F_62 ( V_68 , V_2 -> V_10 . V_207 ) ;
break;
case V_208 :
* V_198 = F_62 ( V_68 , V_2 -> V_10 . V_209 ) ;
break;
case V_210 :
* V_198 = F_62 ( V_68 , V_2 -> V_10 . V_211 ) ;
break;
case V_212 ... V_213 :
V_170 = V_68 - V_212 ;
* V_198 = F_62 ( V_68 , V_2 -> V_10 . V_214 [ V_170 ] ) ;
break;
case V_215 ... V_216 :
V_170 = V_68 - V_215 ;
* V_198 = F_62 ( V_68 , V_2 -> V_10 . V_217 [ V_170 ] ) ;
break;
case V_218 :
* V_198 = F_62 ( V_68 , V_2 -> V_10 . V_219 ) ;
break;
case V_220 :
* V_198 = F_62 ( V_68 , V_2 -> V_10 . V_221 ) ;
break;
#ifdef F_63
case V_222 ... V_223 :
if ( F_19 ( V_224 ) ) {
long int V_170 = V_68 - V_222 ;
* V_198 = F_62 ( V_68 , V_2 -> V_10 . V_225 [ 2 * V_170 ] ) ;
} else {
V_42 = - V_36 ;
}
break;
case V_226 ... V_227 :
if ( F_19 ( V_224 ) ) {
long int V_170 = V_68 - V_226 ;
V_198 -> V_228 [ 0 ] = V_2 -> V_10 . V_225 [ 2 * V_170 ] ;
V_198 -> V_228 [ 1 ] = V_2 -> V_10 . V_225 [ 2 * V_170 + 1 ] ;
} else {
V_42 = - V_229 ;
}
break;
#endif
case V_230 :
F_20 ( & V_2 -> V_10 . V_80 ) ;
* V_198 = F_62 ( V_68 , V_2 -> V_10 . V_72 . V_81 ) ;
F_21 ( & V_2 -> V_10 . V_80 ) ;
break;
case V_231 :
F_20 ( & V_2 -> V_10 . V_80 ) ;
V_198 -> V_232 . V_77 = V_2 -> V_10 . V_104 . V_81 ;
V_198 -> V_232 . V_98 = V_2 -> V_10 . V_104 . V_78 ;
F_21 ( & V_2 -> V_10 . V_80 ) ;
break;
case V_233 :
F_20 ( & V_2 -> V_10 . V_80 ) ;
V_198 -> V_232 . V_77 = V_2 -> V_10 . V_103 . V_81 ;
V_198 -> V_232 . V_98 = V_2 -> V_10 . V_103 . V_78 ;
F_21 ( & V_2 -> V_10 . V_80 ) ;
break;
case V_234 :
* V_198 = F_62 ( V_68 , V_2 -> V_10 . V_17 -> V_125 ) ;
break;
case V_235 :
* V_198 = F_62 ( V_68 , V_2 -> V_10 . V_17 -> V_64 ) ;
break;
case V_236 :
* V_198 = F_62 ( V_68 , V_2 -> V_10 . V_237 ) ;
break;
case V_238 :
* V_198 = F_62 ( V_68 , V_2 -> V_10 . V_17 -> V_33 ) ;
break;
default:
V_42 = - V_36 ;
break;
}
return V_42 ;
}
static int F_64 ( struct V_1 * V_2 , T_2 V_68 ,
union V_197 * V_198 )
{
int V_42 = 0 ;
long int V_170 ;
unsigned long V_77 , V_78 ;
switch ( V_68 ) {
case V_199 :
if ( F_65 ( V_68 , * V_198 ) )
V_42 = - V_36 ;
break;
case V_200 :
V_2 -> V_10 . V_201 = F_65 ( V_68 , * V_198 ) ;
break;
case V_202 :
V_2 -> V_10 . V_203 = F_65 ( V_68 , * V_198 ) ;
break;
case V_204 :
V_2 -> V_10 . V_205 = F_65 ( V_68 , * V_198 ) ;
break;
case V_206 :
V_2 -> V_10 . V_207 = F_65 ( V_68 , * V_198 ) ;
break;
case V_208 :
V_2 -> V_10 . V_209 = F_65 ( V_68 , * V_198 ) ;
break;
case V_210 :
V_2 -> V_10 . V_211 = F_65 ( V_68 , * V_198 ) ;
break;
case V_212 ... V_213 :
V_170 = V_68 - V_212 ;
V_2 -> V_10 . V_214 [ V_170 ] = F_65 ( V_68 , * V_198 ) ;
break;
case V_215 ... V_216 :
V_170 = V_68 - V_215 ;
V_2 -> V_10 . V_217 [ V_170 ] = F_65 ( V_68 , * V_198 ) ;
break;
case V_218 :
V_2 -> V_10 . V_219 = F_65 ( V_68 , * V_198 ) ;
break;
case V_220 :
V_2 -> V_10 . V_221 = F_65 ( V_68 , * V_198 ) ;
break;
#ifdef F_63
case V_222 ... V_223 :
if ( F_19 ( V_224 ) ) {
long int V_170 = V_68 - V_222 ;
V_2 -> V_10 . V_225 [ 2 * V_170 ] = F_65 ( V_68 , * V_198 ) ;
} else {
V_42 = - V_36 ;
}
break;
case V_226 ... V_227 :
if ( F_19 ( V_224 ) ) {
long int V_170 = V_68 - V_226 ;
V_2 -> V_10 . V_225 [ 2 * V_170 ] = V_198 -> V_228 [ 0 ] ;
V_2 -> V_10 . V_225 [ 2 * V_170 + 1 ] = V_198 -> V_228 [ 1 ] ;
} else {
V_42 = - V_229 ;
}
break;
#endif
case V_230 :
V_77 = F_65 ( V_68 , * V_198 ) ;
V_42 = - V_36 ;
if ( ! V_77 && ( V_2 -> V_10 . V_104 . V_81 ||
V_2 -> V_10 . V_103 . V_81 ) )
break;
V_42 = F_30 ( V_2 , & V_2 -> V_10 . V_72 , V_77 , sizeof( struct V_71 ) ) ;
break;
case V_231 :
V_77 = V_198 -> V_232 . V_77 ;
V_78 = V_198 -> V_232 . V_98 ;
V_42 = - V_36 ;
if ( V_77 && ! V_2 -> V_10 . V_72 . V_81 )
break;
V_42 = F_30 ( V_2 , & V_2 -> V_10 . V_104 , V_77 , V_78 ) ;
break;
case V_233 :
V_77 = V_198 -> V_232 . V_77 ;
V_78 = V_198 -> V_232 . V_98 ;
V_42 = - V_36 ;
if ( V_77 && ( V_78 < sizeof( struct V_101 ) ||
! V_2 -> V_10 . V_72 . V_81 ) )
break;
V_78 -= V_78 % sizeof( struct V_101 ) ;
V_42 = F_30 ( V_2 , & V_2 -> V_10 . V_103 , V_77 , V_78 ) ;
break;
case V_234 :
V_2 -> V_10 . V_17 -> V_125 =
F_66 ( F_65 ( V_68 , * V_198 ) , 1UL << 24 ) ;
break;
case V_235 :
F_60 ( V_2 , F_65 ( V_68 , * V_198 ) ) ;
break;
case V_236 :
V_2 -> V_10 . V_237 = F_65 ( V_68 , * V_198 ) ;
break;
case V_238 :
V_42 = F_18 ( V_2 , F_65 ( V_68 , * V_198 ) ) ;
break;
default:
V_42 = - V_36 ;
break;
}
return V_42 ;
}
static struct V_1 * F_67 ( struct V_65 * V_65 ,
unsigned int V_68 )
{
struct V_1 * V_2 ;
int V_89 = - V_36 ;
int V_239 ;
struct V_15 * V_17 ;
V_239 = V_68 / V_240 ;
if ( V_239 >= V_241 )
goto V_242;
V_89 = - V_243 ;
V_2 = F_68 ( V_244 , V_245 ) ;
if ( ! V_2 )
goto V_242;
V_89 = F_69 ( V_2 , V_65 , V_68 ) ;
if ( V_89 )
goto V_246;
V_2 -> V_10 . V_247 = & V_2 -> V_10 . V_31 ;
V_2 -> V_10 . V_214 [ 0 ] = V_248 ;
V_2 -> V_10 . V_249 = V_250 ;
F_17 ( V_2 , F_70 ( V_251 ) ) ;
F_71 ( & V_2 -> V_10 . V_80 ) ;
F_71 ( & V_2 -> V_10 . V_19 ) ;
V_2 -> V_10 . V_28 = V_24 ;
F_72 ( V_2 ) ;
V_2 -> V_10 . V_26 = V_252 ;
F_73 ( & V_2 -> V_10 . V_253 ) ;
F_26 ( & V_65 -> V_41 ) ;
V_17 = V_65 -> V_10 . V_254 [ V_239 ] ;
if ( ! V_17 ) {
V_17 = F_74 ( sizeof( struct V_15 ) , V_245 ) ;
if ( V_17 ) {
F_75 ( & V_17 -> V_255 ) ;
F_71 ( & V_17 -> V_41 ) ;
F_73 ( & V_17 -> V_139 ) ;
V_17 -> V_23 = V_24 ;
V_17 -> V_64 = V_65 -> V_10 . V_64 ;
}
V_65 -> V_10 . V_254 [ V_239 ] = V_17 ;
V_65 -> V_10 . V_256 ++ ;
}
F_28 ( & V_65 -> V_41 ) ;
if ( ! V_17 )
goto V_246;
F_20 ( & V_17 -> V_41 ) ;
++ V_17 -> V_257 ;
F_21 ( & V_17 -> V_41 ) ;
V_2 -> V_10 . V_17 = V_17 ;
V_2 -> V_10 . V_258 = V_259 ;
F_76 ( V_2 ) ;
return V_2 ;
V_246:
F_77 ( V_244 , V_2 ) ;
V_242:
return F_78 ( V_89 ) ;
}
static void F_79 ( struct V_65 * V_65 , struct V_76 * V_72 )
{
if ( V_72 -> V_84 )
F_34 ( V_65 , V_72 -> V_84 , V_72 -> V_108 ,
V_72 -> V_109 ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
F_20 ( & V_2 -> V_10 . V_80 ) ;
F_79 ( V_2 -> V_65 , & V_2 -> V_10 . V_103 ) ;
F_79 ( V_2 -> V_65 , & V_2 -> V_10 . V_104 ) ;
F_79 ( V_2 -> V_65 , & V_2 -> V_10 . V_72 ) ;
F_21 ( & V_2 -> V_10 . V_80 ) ;
F_81 ( V_2 ) ;
F_77 ( V_244 , V_2 ) ;
}
static int F_82 ( struct V_1 * V_2 )
{
return 1 ;
}
static void F_83 ( struct V_1 * V_2 )
{
unsigned long V_260 , V_113 ;
V_113 = F_84 () ;
if ( V_113 > V_2 -> V_10 . V_261 ) {
F_85 ( V_2 ) ;
F_86 ( V_2 ) ;
return;
}
V_260 = ( V_2 -> V_10 . V_261 - V_113 ) * V_262
/ V_263 ;
F_87 ( & V_2 -> V_10 . V_264 , F_88 ( 0 , V_260 ) ,
V_265 ) ;
V_2 -> V_10 . V_266 = 1 ;
}
static void F_16 ( struct V_1 * V_2 )
{
V_2 -> V_10 . V_138 = 0 ;
if ( V_2 -> V_10 . V_266 ) {
F_89 ( & V_2 -> V_10 . V_264 ) ;
V_2 -> V_10 . V_266 = 0 ;
}
}
static void F_90 ( struct V_15 * V_16 ,
struct V_1 * V_2 )
{
T_2 V_113 ;
if ( V_2 -> V_10 . V_26 != V_267 )
return;
F_38 ( & V_2 -> V_10 . V_19 ) ;
V_113 = F_12 () ;
V_2 -> V_10 . V_29 += F_37 ( V_16 , V_113 ) -
V_2 -> V_10 . V_120 ;
V_2 -> V_10 . V_28 = V_113 ;
V_2 -> V_10 . V_26 = V_27 ;
F_39 ( & V_2 -> V_10 . V_19 ) ;
-- V_16 -> V_268 ;
F_91 ( & V_2 -> V_10 . V_269 ) ;
}
static int F_92 ( int V_4 )
{
struct V_270 * V_271 ;
long V_272 = 1000 ;
V_271 = & V_12 [ V_4 ] ;
V_271 -> V_13 . V_273 = 1 ;
V_271 -> V_13 . V_1 = NULL ;
F_47 () ;
while ( V_271 -> V_13 . V_274 == V_275 ) {
if ( -- V_272 <= 0 ) {
F_23 ( L_15 , V_4 ) ;
return - V_276 ;
}
F_93 ( 1 ) ;
}
return 0 ;
}
static void F_94 ( int V_4 )
{
struct V_270 * V_271 ;
V_271 = & V_12 [ V_4 ] ;
V_271 -> V_13 . V_273 = 0 ;
V_271 -> V_13 . V_1 = NULL ;
}
static void F_95 ( struct V_1 * V_2 )
{
int V_4 ;
struct V_270 * V_271 ;
struct V_15 * V_16 = V_2 -> V_10 . V_17 ;
if ( V_2 -> V_10 . V_266 ) {
F_89 ( & V_2 -> V_10 . V_264 ) ;
V_2 -> V_10 . V_266 = 0 ;
}
V_4 = V_16 -> V_123 + V_2 -> V_10 . V_11 ;
V_271 = & V_12 [ V_4 ] ;
V_271 -> V_13 . V_1 = V_2 ;
V_271 -> V_13 . V_277 = V_16 ;
V_271 -> V_13 . V_278 = 0 ;
V_2 -> V_4 = V_16 -> V_123 ;
F_42 () ;
#if F_96 ( V_279 ) && F_96 ( V_280 )
if ( V_2 -> V_10 . V_11 ) {
F_6 ( V_4 ) ;
++ V_16 -> V_281 ;
}
#endif
}
static void F_97 ( struct V_15 * V_16 )
{
int V_170 ;
F_98 () ;
V_170 = 0 ;
while ( V_16 -> V_282 < V_16 -> V_281 ) {
if ( ++ V_170 >= 1000000 ) {
F_23 ( L_16 ,
V_16 -> V_282 , V_16 -> V_281 ) ;
break;
}
F_99 () ;
}
F_100 () ;
}
static int F_101 ( void )
{
int V_4 = F_102 () ;
int V_283 = F_103 ( V_4 ) ;
if ( V_283 )
return 0 ;
while ( ++ V_283 < V_240 )
if ( F_7 ( V_4 + V_283 ) )
return 0 ;
for ( V_283 = 1 ; V_283 < V_240 ; ++ V_283 ) {
if ( F_92 ( V_4 + V_283 ) ) {
do {
F_94 ( V_4 + V_283 ) ;
} while ( -- V_283 > 0 );
return 0 ;
}
}
return 1 ;
}
static void F_104 ( struct V_15 * V_16 )
{
struct V_1 * V_2 , * V_284 , * V_285 ;
long V_70 ;
T_2 V_113 ;
int V_11 , V_170 , V_286 ;
int V_287 ;
struct V_1 * V_288 [ V_240 ] ;
V_286 = 0 ;
F_105 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( F_106 ( V_2 -> V_10 . V_115 ) )
return;
if ( V_2 -> V_10 . V_72 . V_82 ||
V_2 -> V_10 . V_104 . V_82 ||
V_2 -> V_10 . V_103 . V_82 )
V_288 [ V_286 ++ ] = V_2 ;
}
V_16 -> V_281 = 0 ;
V_16 -> V_282 = 0 ;
V_16 -> V_289 = 0 ;
V_16 -> V_21 = V_290 ;
V_16 -> V_291 = 0 ;
V_16 -> V_292 = 0 ;
if ( V_286 ) {
F_21 ( & V_16 -> V_41 ) ;
for ( V_170 = 0 ; V_170 < V_286 ; ++ V_170 )
F_36 ( V_288 [ V_170 ] ) ;
F_20 ( & V_16 -> V_41 ) ;
}
V_11 = 0 ;
V_284 = NULL ;
F_105 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( ! V_2 -> V_10 . V_138 ) {
if ( ! V_11 )
V_284 = V_2 ;
V_2 -> V_10 . V_11 = V_11 ++ ;
}
}
if ( ! V_284 )
goto V_242;
F_105 (vcpu, &vc->runnable_threads, arch.run_list)
if ( V_2 -> V_10 . V_138 )
V_2 -> V_10 . V_11 = V_11 ++ ;
if ( V_240 > 1 && ! F_101 () ) {
F_105 (vcpu, &vc->runnable_threads, arch.run_list)
V_2 -> V_10 . V_70 = - V_276 ;
goto V_242;
}
V_16 -> V_123 = F_102 () ;
F_105 (vcpu, &vc->runnable_threads, arch.run_list) {
F_95 ( V_2 ) ;
F_40 ( V_2 , V_16 ) ;
}
V_16 -> V_21 = V_293 ;
F_107 () ;
F_21 ( & V_16 -> V_41 ) ;
F_108 () ;
V_287 = F_44 ( & V_284 -> V_65 -> V_134 ) ;
F_109 ( NULL , V_284 ) ;
F_20 ( & V_16 -> V_41 ) ;
F_105 (vcpu, &vc->runnable_threads, arch.run_list)
V_2 -> V_4 = - 1 ;
if ( V_16 -> V_282 < V_16 -> V_281 )
F_97 ( V_16 ) ;
for ( V_170 = 0 ; V_170 < V_240 ; ++ V_170 )
F_94 ( V_16 -> V_123 + V_170 ) ;
V_16 -> V_21 = V_294 ;
F_21 ( & V_16 -> V_41 ) ;
F_46 ( & V_284 -> V_65 -> V_134 , V_287 ) ;
F_47 () ;
F_110 () ;
F_111 () ;
F_112 ( V_2 ) ;
F_20 ( & V_16 -> V_41 ) ;
V_113 = F_84 () ;
F_105 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( V_113 < V_2 -> V_10 . V_261 &&
F_113 ( V_2 ) )
F_114 ( V_2 ) ;
V_70 = V_153 ;
if ( V_2 -> V_10 . V_45 )
V_70 = F_54 ( V_2 -> V_10 . V_154 , V_2 ,
V_2 -> V_10 . V_115 ) ;
V_2 -> V_10 . V_70 = V_70 ;
V_2 -> V_10 . V_45 = 0 ;
if ( V_2 -> V_10 . V_138 ) {
if ( V_70 != V_153 )
F_16 ( V_2 ) ;
else
F_83 ( V_2 ) ;
}
}
V_242:
V_16 -> V_21 = V_22 ;
F_115 (vcpu, vnext, &vc->runnable_threads,
arch.run_list) {
if ( V_2 -> V_10 . V_70 != V_153 ) {
F_90 ( V_16 , V_2 ) ;
F_116 ( & V_2 -> V_10 . V_253 ) ;
}
}
}
static void F_117 ( struct V_1 * V_2 , int V_295 )
{
F_118 ( V_296 ) ;
F_119 ( & V_2 -> V_10 . V_253 , & V_296 , V_295 ) ;
if ( V_2 -> V_10 . V_26 == V_267 )
F_120 () ;
F_121 ( & V_2 -> V_10 . V_253 , & V_296 ) ;
}
static void F_122 ( struct V_15 * V_16 )
{
F_118 ( V_296 ) ;
F_119 ( & V_16 -> V_139 , & V_296 , V_297 ) ;
V_16 -> V_21 = V_298 ;
F_21 ( & V_16 -> V_41 ) ;
F_120 () ;
F_121 ( & V_16 -> V_139 , & V_296 ) ;
F_20 ( & V_16 -> V_41 ) ;
V_16 -> V_21 = V_22 ;
}
static int F_123 ( struct V_154 * V_154 , struct V_1 * V_2 )
{
int V_299 ;
struct V_15 * V_16 ;
struct V_1 * V_69 , * V_300 ;
V_154 -> V_159 = 0 ;
V_2 -> V_10 . V_70 = V_153 ;
V_2 -> V_10 . V_45 = 0 ;
F_36 ( V_2 ) ;
V_16 = V_2 -> V_10 . V_17 ;
F_20 ( & V_16 -> V_41 ) ;
V_2 -> V_10 . V_138 = 0 ;
V_2 -> V_10 . V_115 = V_116 ;
V_2 -> V_10 . V_154 = V_154 ;
V_2 -> V_10 . V_120 = F_37 ( V_16 , F_12 () ) ;
V_2 -> V_10 . V_26 = V_267 ;
V_2 -> V_10 . V_28 = V_24 ;
F_124 ( & V_2 -> V_10 . V_269 , & V_16 -> V_255 ) ;
++ V_16 -> V_268 ;
if ( ! F_106 ( V_116 ) ) {
if ( V_16 -> V_21 == V_293 &&
F_125 ( V_16 ) == 0 ) {
V_2 -> V_10 . V_11 = V_16 -> V_268 - 1 ;
F_40 ( V_2 , V_16 ) ;
F_95 ( V_2 ) ;
} else if ( V_16 -> V_21 == V_298 ) {
F_116 ( & V_16 -> V_139 ) ;
}
}
while ( V_2 -> V_10 . V_26 == V_267 &&
! F_106 ( V_116 ) ) {
if ( V_16 -> V_21 != V_22 ) {
F_21 ( & V_16 -> V_41 ) ;
F_117 ( V_2 , V_297 ) ;
F_20 ( & V_16 -> V_41 ) ;
continue;
}
F_115 (v, vn, &vc->runnable_threads,
arch.run_list) {
F_86 ( V_69 ) ;
if ( F_106 ( V_69 -> V_10 . V_115 ) ) {
F_90 ( V_16 , V_69 ) ;
V_69 -> V_6 . V_301 ++ ;
V_69 -> V_10 . V_154 -> V_159 = V_302 ;
V_69 -> V_10 . V_70 = - V_303 ;
F_116 ( & V_69 -> V_10 . V_253 ) ;
}
}
if ( ! V_16 -> V_268 || V_2 -> V_10 . V_26 != V_267 )
break;
V_16 -> V_20 = V_2 ;
V_299 = 0 ;
F_105 (v, &vc->runnable_threads, arch.run_list) {
if ( ! V_69 -> V_10 . V_304 )
V_299 += V_69 -> V_10 . V_138 ;
else
V_69 -> V_10 . V_138 = 0 ;
}
if ( V_299 == V_16 -> V_268 )
F_122 ( V_16 ) ;
else
F_104 ( V_16 ) ;
V_16 -> V_20 = NULL ;
}
while ( V_2 -> V_10 . V_26 == V_267 &&
( V_16 -> V_21 == V_293 ||
V_16 -> V_21 == V_294 ) ) {
F_21 ( & V_16 -> V_41 ) ;
F_117 ( V_2 , V_305 ) ;
F_20 ( & V_16 -> V_41 ) ;
}
if ( V_2 -> V_10 . V_26 == V_267 ) {
F_90 ( V_16 , V_2 ) ;
V_2 -> V_6 . V_301 ++ ;
V_154 -> V_159 = V_302 ;
V_2 -> V_10 . V_70 = - V_303 ;
}
if ( V_16 -> V_268 && V_16 -> V_21 == V_22 ) {
V_69 = F_126 ( & V_16 -> V_255 ,
struct V_1 , V_10 . V_269 ) ;
F_116 ( & V_69 -> V_10 . V_253 ) ;
}
F_21 ( & V_16 -> V_41 ) ;
return V_2 -> V_10 . V_70 ;
}
static int F_127 ( struct V_154 * V_155 , struct V_1 * V_2 )
{
int V_42 ;
int V_287 ;
if ( ! V_2 -> V_10 . V_306 ) {
V_155 -> V_159 = V_307 ;
return - V_36 ;
}
F_86 ( V_2 ) ;
if ( F_106 ( V_116 ) ) {
V_155 -> V_159 = V_302 ;
return - V_303 ;
}
F_128 ( & V_2 -> V_65 -> V_10 . V_308 ) ;
F_47 () ;
if ( ! V_2 -> V_65 -> V_10 . V_309 ) {
V_42 = F_129 ( V_2 ) ;
if ( V_42 )
goto V_242;
}
F_130 ( V_116 ) ;
F_131 ( V_116 ) ;
F_132 ( V_116 ) ;
V_2 -> V_10 . V_5 = & V_2 -> V_10 . V_17 -> V_139 ;
V_2 -> V_10 . V_310 = V_116 -> V_311 -> V_312 ;
V_2 -> V_10 . V_26 = V_27 ;
do {
V_42 = F_123 ( V_155 , V_2 ) ;
if ( V_155 -> V_159 == V_174 &&
! ( V_2 -> V_10 . V_31 . V_30 & V_171 ) ) {
V_42 = F_43 ( V_2 ) ;
F_86 ( V_2 ) ;
} else if ( V_42 == V_176 ) {
V_287 = F_44 ( & V_2 -> V_65 -> V_134 ) ;
V_42 = F_133 ( V_155 , V_2 ,
V_2 -> V_10 . V_58 , V_2 -> V_10 . V_59 ) ;
F_46 ( & V_2 -> V_65 -> V_134 , V_287 ) ;
}
} while ( V_42 == V_153 );
V_242:
V_2 -> V_10 . V_26 = V_252 ;
F_134 ( & V_2 -> V_65 -> V_10 . V_308 ) ;
return V_42 ;
}
static inline int F_135 ( unsigned long V_313 )
{
switch ( V_313 ) {
case 32ul << 20 :
if ( F_19 ( V_35 ) )
return 8 ;
return - 1 ;
case 64ul << 20 :
return 3 ;
case 128ul << 20 :
return 7 ;
case 256ul << 20 :
return 4 ;
case 1ul << 30 :
return 2 ;
case 16ul << 30 :
return 1 ;
case 256ul << 30 :
return 0 ;
default:
return - 1 ;
}
}
static int F_136 ( struct V_314 * V_315 , struct V_316 * V_317 )
{
struct V_318 * V_318 ;
struct V_319 * V_320 = V_315 -> V_321 -> V_322 ;
if ( V_317 -> V_323 >= V_324 )
return V_325 ;
V_318 = F_137 ( V_320 -> V_326 + V_317 -> V_323 ) ;
F_138 ( V_318 ) ;
V_317 -> V_318 = V_318 ;
return 0 ;
}
static int F_139 ( struct V_327 * V_327 , struct V_314 * V_315 )
{
V_315 -> V_328 |= V_329 | V_330 ;
V_315 -> V_331 = & V_332 ;
return 0 ;
}
static int F_140 ( struct V_333 * V_333 , struct V_327 * V_334 )
{
struct V_319 * V_320 = V_334 -> V_322 ;
F_141 ( V_320 ) ;
return 0 ;
}
static long F_142 ( struct V_65 * V_65 ,
struct V_335 * V_70 )
{
long V_336 ;
struct V_319 * V_320 ;
if ( ! F_19 ( V_337 ) ||
! F_19 ( V_338 ) )
return - V_36 ;
if ( ! V_324 )
return - V_36 ;
V_320 = F_143 () ;
if ( ! V_320 )
return - V_243 ;
V_336 = F_144 ( L_17 , & V_339 , V_320 , V_340 | V_341 ) ;
if ( V_336 < 0 )
F_141 ( V_320 ) ;
V_70 -> V_313 = V_324 << V_342 ;
return V_336 ;
}
static void F_145 ( struct V_343 * * V_344 ,
int V_345 )
{
struct V_346 * V_347 = & V_348 [ V_345 ] ;
if ( ! V_347 -> V_349 )
return;
( * V_344 ) -> V_350 = V_347 -> V_349 ;
( * V_344 ) -> V_351 = V_347 -> V_352 ;
( * V_344 ) -> V_353 [ 0 ] . V_350 = V_347 -> V_349 ;
( * V_344 ) -> V_353 [ 0 ] . V_354 = V_347 -> V_355 [ V_345 ] ;
( * V_344 ) ++ ;
}
static int F_146 ( struct V_65 * V_65 ,
struct V_356 * V_357 )
{
struct V_343 * V_344 ;
V_357 -> V_18 = V_358 ;
if ( F_147 ( V_359 ) )
V_357 -> V_18 |= V_360 ;
V_357 -> V_361 = V_362 ;
V_344 = & V_357 -> V_344 [ 0 ] ;
F_145 ( & V_344 , V_363 ) ;
F_145 ( & V_344 , V_364 ) ;
F_145 ( & V_344 , V_365 ) ;
return 0 ;
}
static int F_148 ( struct V_65 * V_65 ,
struct V_366 * log )
{
struct V_367 * V_368 ;
int V_42 ;
unsigned long V_369 ;
F_26 ( & V_65 -> V_370 ) ;
V_42 = - V_36 ;
if ( log -> V_371 >= V_372 )
goto V_242;
V_368 = F_149 ( V_65 -> V_373 , log -> V_371 ) ;
V_42 = - V_145 ;
if ( ! V_368 -> V_374 )
goto V_242;
V_369 = F_150 ( V_368 ) ;
memset ( V_368 -> V_374 , 0 , V_369 ) ;
V_42 = F_151 ( V_65 , V_368 , V_368 -> V_374 ) ;
if ( V_42 )
goto V_242;
V_42 = - V_375 ;
if ( F_152 ( log -> V_374 , V_368 -> V_374 , V_369 ) )
goto V_242;
V_42 = 0 ;
V_242:
F_28 ( & V_65 -> V_370 ) ;
return V_42 ;
}
static void F_153 ( struct V_367 * V_368 )
{
unsigned long * V_376 ;
unsigned long V_189 , V_377 , V_378 ;
struct V_318 * V_318 ;
V_376 = V_368 -> V_10 . V_379 ;
V_377 = V_368 -> V_377 ;
if ( ! V_376 )
return;
for ( V_189 = 0 ; V_189 < V_377 ; V_189 ++ ) {
if ( ! ( V_376 [ V_189 ] & V_380 ) )
continue;
V_378 = V_376 [ V_189 ] >> V_342 ;
V_318 = F_137 ( V_378 ) ;
F_154 ( V_318 ) ;
F_155 ( V_318 ) ;
}
}
static void F_156 ( struct V_367 * free ,
struct V_367 * V_381 )
{
if ( ! V_381 || free -> V_10 . V_382 != V_381 -> V_10 . V_382 ) {
F_157 ( free -> V_10 . V_382 ) ;
free -> V_10 . V_382 = NULL ;
}
if ( ! V_381 || free -> V_10 . V_379 != V_381 -> V_10 . V_379 ) {
F_153 ( free ) ;
F_157 ( free -> V_10 . V_379 ) ;
free -> V_10 . V_379 = NULL ;
}
}
static int F_158 ( struct V_367 * V_371 ,
unsigned long V_377 )
{
V_371 -> V_10 . V_382 = F_159 ( V_377 * sizeof( * V_371 -> V_10 . V_382 ) ) ;
if ( ! V_371 -> V_10 . V_382 )
return - V_243 ;
V_371 -> V_10 . V_379 = NULL ;
return 0 ;
}
static int F_160 ( struct V_65 * V_65 ,
struct V_367 * V_368 ,
struct V_383 * V_384 )
{
unsigned long * V_385 ;
V_385 = V_368 -> V_10 . V_379 ;
if ( ! V_65 -> V_10 . V_386 && ! V_385 && V_368 -> V_377 ) {
V_385 = F_159 ( V_368 -> V_377 * sizeof( unsigned long ) ) ;
if ( ! V_385 )
return - V_243 ;
V_368 -> V_10 . V_379 = V_385 ;
}
return 0 ;
}
static void F_161 ( struct V_65 * V_65 ,
struct V_383 * V_384 ,
const struct V_367 * V_387 )
{
unsigned long V_377 = V_384 -> V_388 >> V_342 ;
struct V_367 * V_368 ;
if ( V_377 && V_387 -> V_377 ) {
V_368 = F_149 ( V_65 -> V_373 , V_384 -> V_371 ) ;
F_151 ( V_65 , V_368 , NULL ) ;
}
}
void F_162 ( struct V_65 * V_65 , unsigned long V_64 , unsigned long V_193 )
{
long int V_170 ;
T_3 V_389 = 0 ;
if ( ( V_65 -> V_10 . V_64 & V_193 ) == V_64 )
return;
V_65 -> V_10 . V_64 = ( V_65 -> V_10 . V_64 & ~ V_193 ) | V_64 ;
for ( V_170 = 0 ; V_170 < V_241 ; ++ V_170 ) {
struct V_15 * V_16 = V_65 -> V_10 . V_254 [ V_170 ] ;
if ( ! V_16 )
continue;
F_20 ( & V_16 -> V_41 ) ;
V_16 -> V_64 = ( V_16 -> V_64 & ~ V_193 ) | V_64 ;
F_21 ( & V_16 -> V_41 ) ;
if ( ++ V_389 >= V_65 -> V_10 . V_256 )
break;
}
}
static void F_163 ( struct V_1 * V_2 )
{
return;
}
static int F_129 ( struct V_1 * V_2 )
{
int V_89 = 0 ;
struct V_65 * V_65 = V_2 -> V_65 ;
struct V_319 * V_320 = NULL ;
unsigned long V_390 ;
struct V_367 * V_368 ;
struct V_314 * V_315 ;
unsigned long V_64 = 0 , V_391 ;
unsigned long V_392 = 0 ;
unsigned long V_393 , V_394 ;
unsigned long V_313 ;
unsigned long V_395 ;
unsigned long * V_376 ;
unsigned long V_170 , V_377 ;
int V_287 ;
F_26 ( & V_65 -> V_41 ) ;
if ( V_65 -> V_10 . V_309 )
goto V_242;
if ( ! V_65 -> V_10 . V_396 ) {
V_89 = F_164 ( V_65 , NULL ) ;
if ( V_89 ) {
F_23 ( L_18 ) ;
goto V_242;
}
}
V_287 = F_44 ( & V_65 -> V_134 ) ;
V_368 = F_165 ( V_65 , 0 ) ;
V_89 = - V_36 ;
if ( ! V_368 || ( V_368 -> V_18 & V_397 ) )
goto V_398;
V_390 = V_368 -> V_399 ;
F_166 ( & V_116 -> V_311 -> V_400 ) ;
V_315 = F_167 ( V_116 -> V_311 , V_390 ) ;
if ( ! V_315 || V_315 -> V_401 > V_390 || ( V_315 -> V_328 & V_402 ) )
goto V_403;
V_393 = F_168 ( V_315 ) ;
V_394 = F_169 ( V_393 ) ;
if ( V_315 -> V_321 && V_315 -> V_321 -> V_404 == & V_339 &&
V_390 == V_315 -> V_401 )
V_320 = V_315 -> V_321 -> V_322 ;
F_170 ( & V_116 -> V_311 -> V_400 ) ;
if ( ! V_320 ) {
V_89 = - V_405 ;
if ( F_19 ( V_338 ) ) {
F_23 ( L_19 ) ;
goto V_398;
}
V_89 = - V_36 ;
if ( ! ( V_393 == 0x1000 || V_393 == 0x10000 ||
V_393 == 0x1000000 ) )
goto V_398;
V_391 = F_171 ( V_393 ) ;
V_65 -> V_10 . V_406 = V_391 | V_407 |
( V_408 << V_409 ) ;
V_392 = V_410 ;
V_64 = V_391 << ( V_411 - 4 ) ;
F_172 ( V_2 , V_368 , V_394 ) ;
} else {
V_313 = V_324 ;
if ( V_313 > V_368 -> V_377 )
V_313 = V_368 -> V_377 ;
V_313 <<= V_342 ;
V_395 = F_135 ( V_313 ) ;
V_89 = - V_36 ;
if ( ( long ) V_395 < 0 ) {
F_23 ( L_20 , V_313 ) ;
goto V_398;
}
F_128 ( & V_320 -> V_412 ) ;
V_65 -> V_10 . V_413 = V_320 ;
if ( F_19 ( V_338 ) ) {
V_392 = ( 1ul << V_414 ) |
( 3ul << V_415 ) | V_416 ;
V_64 = ( ( V_395 >> 2 ) << V_414 ) |
( ( V_395 & 3 ) << V_415 ) ;
V_64 |= ( ( V_320 -> V_326 >> ( 26 - V_342 ) ) & 0xffff )
<< V_417 ;
} else {
V_392 = V_418 | V_419 | V_420 ;
V_64 = V_395 << V_421 ;
V_65 -> V_10 . V_422 = V_320 -> V_326 << V_342 ;
}
F_173 ( L_21 ,
V_320 -> V_326 << V_342 , V_313 , V_64 ) ;
V_377 = V_324 ;
V_394 = F_169 ( V_377 ) ;
V_376 = V_368 -> V_10 . V_379 ;
if ( V_376 ) {
if ( V_377 > V_368 -> V_377 )
V_377 = V_368 -> V_377 ;
F_20 ( & V_65 -> V_10 . V_423 ) ;
for ( V_170 = 0 ; V_170 < V_377 ; ++ V_170 )
V_376 [ V_170 ] = ( ( V_320 -> V_326 + V_170 ) << V_342 ) +
V_394 ;
F_21 ( & V_65 -> V_10 . V_423 ) ;
}
}
F_162 ( V_65 , V_64 , V_392 ) ;
F_42 () ;
V_65 -> V_10 . V_309 = 1 ;
V_89 = 0 ;
V_398:
F_46 ( & V_65 -> V_134 , V_287 ) ;
V_242:
F_28 ( & V_65 -> V_41 ) ;
return V_89 ;
V_403:
F_170 ( & V_116 -> V_311 -> V_400 ) ;
goto V_398;
}
static int F_174 ( struct V_65 * V_65 )
{
unsigned long V_64 , V_424 ;
V_424 = F_175 () ;
if ( ( long ) V_424 < 0 )
return - V_243 ;
V_65 -> V_10 . V_424 = V_424 ;
F_176 ( & V_65 -> V_10 . V_425 ) ;
V_65 -> V_10 . V_413 = NULL ;
V_65 -> V_10 . V_426 = F_70 ( V_427 ) ;
if ( F_19 ( V_338 ) ) {
V_65 -> V_10 . V_428 = 0 ;
V_65 -> V_10 . V_429 = V_64 = F_70 ( V_430 ) ;
V_64 &= ~ ( ( 3 << V_431 ) | ( 0xful << V_432 ) ) ;
V_64 |= ( ( V_424 >> 4 ) << V_431 ) |
( ( V_424 & 0xf ) << V_432 ) ;
} else {
V_65 -> V_10 . V_428 = F_70 ( V_433 ) ;
V_65 -> V_10 . V_429 = V_64 = F_70 ( V_434 ) ;
V_64 &= V_435 | V_436 ;
V_64 |= ( 4UL << V_437 ) | V_438 |
V_418 | V_439 ;
V_65 -> V_10 . V_406 = V_407 |
( V_408 << V_409 ) ;
}
V_65 -> V_10 . V_64 = V_64 ;
V_65 -> V_10 . V_386 = ! ! F_19 ( V_35 ) ;
F_71 ( & V_65 -> V_10 . V_423 ) ;
F_177 () ;
return 0 ;
}
static void F_178 ( struct V_65 * V_65 )
{
long int V_170 ;
for ( V_170 = 0 ; V_170 < V_241 ; ++ V_170 )
F_179 ( V_65 -> V_10 . V_254 [ V_170 ] ) ;
V_65 -> V_10 . V_256 = 0 ;
}
static void F_180 ( struct V_65 * V_65 )
{
F_181 () ;
F_178 ( V_65 ) ;
if ( V_65 -> V_10 . V_413 ) {
F_141 ( V_65 -> V_10 . V_413 ) ;
V_65 -> V_10 . V_413 = NULL ;
}
F_182 ( V_65 ) ;
}
static int F_183 ( struct V_154 * V_155 , struct V_1 * V_2 ,
unsigned int V_440 , int * V_441 )
{
return V_442 ;
}
static int F_184 ( struct V_1 * V_2 , int V_443 ,
T_4 V_444 )
{
return V_442 ;
}
static int F_185 ( struct V_1 * V_2 , int V_443 ,
T_4 * V_444 )
{
return V_442 ;
}
static int F_186 ( void )
{
if ( ! F_19 ( V_337 ) )
return - V_445 ;
return 0 ;
}
static long F_187 ( struct V_327 * V_334 ,
unsigned int V_446 , unsigned long V_447 )
{
struct V_65 * V_65 V_448 = V_334 -> V_322 ;
void T_5 * V_449 = ( void T_5 * ) V_447 ;
long V_42 ;
switch ( V_446 ) {
case V_450 : {
struct V_335 V_413 ;
struct V_65 * V_65 = V_334 -> V_322 ;
V_42 = F_142 ( V_65 , & V_413 ) ;
if ( V_42 >= 0 && F_152 ( V_449 , & V_413 , sizeof( V_413 ) ) )
V_42 = - V_375 ;
break;
}
case V_451 : {
T_3 V_452 ;
V_42 = - V_375 ;
if ( F_188 ( V_452 , ( T_3 T_5 * ) V_449 ) )
break;
V_42 = F_189 ( V_65 , & V_452 ) ;
if ( V_42 )
break;
V_42 = - V_375 ;
if ( F_190 ( V_452 , ( T_3 T_5 * ) V_449 ) )
break;
V_42 = 0 ;
break;
}
case V_453 : {
struct V_454 V_455 ;
V_42 = - V_375 ;
if ( F_191 ( & V_455 , V_449 , sizeof( V_455 ) ) )
break;
V_42 = F_192 ( V_65 , & V_455 ) ;
break;
}
default:
V_42 = - V_456 ;
}
return V_42 ;
}
static int F_193 ( void )
{
int V_42 ;
V_42 = F_186 () ;
if ( V_42 < 0 )
return V_42 ;
V_457 . V_458 = V_459 ;
V_460 = & V_457 ;
V_42 = F_194 () ;
return V_42 ;
}
static void F_195 ( void )
{
V_460 = NULL ;
}
