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
#ifdef F_6
int V_9 = V_4 + V_2 -> V_10 . V_11 ;
if ( V_12 [ V_9 ] . V_13 . V_14 )
F_7 ( V_9 ) ;
else
#endif
if ( F_8 ( V_4 ) )
F_9 ( V_4 ) ;
}
F_10 () ;
}
static void F_11 ( struct V_1 * V_2 , int V_4 )
{
struct V_15 * V_16 = V_2 -> V_10 . V_17 ;
unsigned long V_18 ;
F_12 ( & V_2 -> V_10 . V_19 , V_18 ) ;
if ( V_16 -> V_20 == V_2 && V_16 -> V_21 != V_22 &&
V_16 -> V_23 != V_24 ) {
V_16 -> V_25 += F_13 () - V_16 -> V_23 ;
V_16 -> V_23 = V_24 ;
}
if ( V_2 -> V_10 . V_26 == V_27 &&
V_2 -> V_10 . V_28 != V_24 ) {
V_2 -> V_10 . V_29 += F_13 () - V_2 -> V_10 . V_28 ;
V_2 -> V_10 . V_28 = V_24 ;
}
F_14 ( & V_2 -> V_10 . V_19 , V_18 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_10 . V_17 ;
unsigned long V_18 ;
F_12 ( & V_2 -> V_10 . V_19 , V_18 ) ;
if ( V_16 -> V_20 == V_2 && V_16 -> V_21 != V_22 )
V_16 -> V_23 = F_13 () ;
if ( V_2 -> V_10 . V_26 == V_27 )
V_2 -> V_10 . V_28 = F_13 () ;
F_14 ( & V_2 -> V_10 . V_19 , V_18 ) ;
}
static void F_16 ( struct V_1 * V_2 , T_2 V_30 )
{
V_2 -> V_10 . V_31 . V_30 = V_30 ;
F_17 ( V_2 ) ;
}
void F_18 ( struct V_1 * V_2 , T_3 V_32 )
{
V_2 -> V_10 . V_32 = V_32 ;
}
int F_19 ( struct V_1 * V_2 , T_3 V_33 )
{
unsigned long V_34 = 0 ;
struct V_15 * V_16 = V_2 -> V_10 . V_17 ;
if ( V_33 ) {
if ( ! F_20 ( V_35 ) )
return - V_36 ;
switch ( V_33 ) {
case V_37 :
V_34 = V_38 | V_39 ;
break;
case V_40 :
case V_41 :
V_34 = V_38 ;
break;
case V_42 :
break;
default:
return - V_36 ;
}
if ( ! F_20 ( V_43 ) ) {
if ( ! ( V_34 & V_38 ) )
return - V_36 ;
V_34 &= ~ V_38 ;
}
}
F_21 ( & V_16 -> V_44 ) ;
V_16 -> V_33 = V_33 ;
V_16 -> V_34 = V_34 ;
F_22 ( & V_16 -> V_44 ) ;
return 0 ;
}
void F_23 ( struct V_1 * V_2 )
{
int V_45 ;
F_24 ( L_1 , V_2 , V_2 -> V_46 ) ;
F_24 ( L_2 ,
V_2 -> V_10 . V_47 , V_2 -> V_10 . V_31 . V_30 , V_2 -> V_10 . V_48 ) ;
for ( V_45 = 0 ; V_45 < 16 ; ++ V_45 )
F_24 ( L_3 ,
V_45 , F_25 ( V_2 , V_45 ) ,
V_45 + 16 , F_25 ( V_2 , V_45 + 16 ) ) ;
F_24 ( L_4 ,
V_2 -> V_10 . V_49 , V_2 -> V_10 . V_50 ) ;
F_24 ( L_5 ,
V_2 -> V_10 . V_31 . V_51 , V_2 -> V_10 . V_31 . V_52 ) ;
F_24 ( L_6 ,
V_2 -> V_10 . V_31 . V_53 , V_2 -> V_10 . V_31 . V_54 ) ;
F_24 ( L_7 ,
V_2 -> V_10 . V_31 . V_55 , V_2 -> V_10 . V_31 . V_56 ) ;
F_24 ( L_8 ,
V_2 -> V_10 . V_57 , V_2 -> V_10 . V_58 , V_2 -> V_10 . V_31 . V_59 ) ;
F_24 ( L_9 , V_2 -> V_10 . V_31 . V_60 ) ;
F_24 ( L_10 ,
V_2 -> V_10 . V_61 , V_2 -> V_10 . V_62 ) ;
F_24 ( L_11 , V_2 -> V_10 . V_63 ) ;
for ( V_45 = 0 ; V_45 < V_2 -> V_10 . V_63 ; ++ V_45 )
F_24 ( L_12 ,
V_2 -> V_10 . V_64 [ V_45 ] . V_65 , V_2 -> V_10 . V_64 [ V_45 ] . V_66 ) ;
F_24 ( L_13 ,
V_2 -> V_10 . V_17 -> V_67 , V_2 -> V_68 -> V_10 . V_69 ,
V_2 -> V_10 . V_70 ) ;
}
struct V_1 * F_26 ( struct V_68 * V_68 , int V_71 )
{
int V_45 ;
struct V_1 * V_72 , * V_73 = NULL ;
F_27 ( & V_68 -> V_44 ) ;
F_28 (r, v, kvm) {
if ( V_72 -> V_46 == V_71 ) {
V_73 = V_72 ;
break;
}
}
F_29 ( & V_68 -> V_44 ) ;
return V_73 ;
}
static void F_30 ( struct V_1 * V_2 , struct V_74 * V_75 )
{
V_75 -> V_76 |= V_77 ;
V_75 -> V_78 = F_31 ( 1 ) ;
}
static int F_32 ( struct V_1 * V_2 , struct V_79 * V_72 ,
unsigned long V_80 , unsigned long V_81 )
{
if ( V_80 & ( V_82 - 1 ) )
return - V_36 ;
F_21 ( & V_2 -> V_10 . V_83 ) ;
if ( V_72 -> V_84 != V_80 || V_72 -> V_81 != V_81 ) {
V_72 -> V_84 = V_80 ;
V_72 -> V_81 = V_80 ? V_81 : 0 ;
V_72 -> V_85 = 1 ;
}
F_22 ( & V_2 -> V_10 . V_83 ) ;
return 0 ;
}
static int F_33 ( struct V_79 * V_86 )
{
if ( V_86 -> V_85 )
return V_86 -> V_84 != 0 ;
return V_86 -> V_87 != NULL ;
}
static unsigned long F_34 ( struct V_1 * V_2 ,
unsigned long V_18 ,
unsigned long V_88 , unsigned long V_75 )
{
struct V_68 * V_68 = V_2 -> V_68 ;
unsigned long V_81 , V_89 ;
void * V_90 ;
struct V_1 * V_91 ;
int V_92 ;
int V_93 ;
struct V_79 * V_86 ;
V_91 = F_26 ( V_68 , V_88 ) ;
if ( ! V_91 )
return V_94 ;
V_93 = ( V_18 >> V_95 ) & V_96 ;
if ( V_93 == V_97 || V_93 == V_98 ||
V_93 == V_99 ) {
if ( ( V_75 & ( V_82 - 1 ) ) || ! V_75 )
return V_94 ;
V_90 = F_35 ( V_68 , V_75 , & V_89 ) ;
if ( V_90 == NULL )
return V_94 ;
if ( V_93 == V_97 )
V_81 = F_36 ( ( (struct V_100 * ) V_90 ) -> V_101 . V_102 ) ;
else
V_81 = F_37 ( ( (struct V_100 * ) V_90 ) -> V_101 . V_103 ) ;
F_38 ( V_68 , V_90 , V_75 , false ) ;
if ( V_81 > V_89 || V_81 < sizeof( struct V_100 ) )
return V_94 ;
} else {
V_75 = 0 ;
V_81 = 0 ;
}
V_92 = V_94 ;
V_86 = NULL ;
F_21 ( & V_91 -> V_10 . V_83 ) ;
switch ( V_93 ) {
case V_97 :
if ( V_81 < sizeof( struct V_74 ) )
break;
V_86 = & V_91 -> V_10 . V_75 ;
V_92 = 0 ;
break;
case V_98 :
if ( V_81 < sizeof( struct V_104 ) )
break;
V_81 -= V_81 % sizeof( struct V_104 ) ;
V_92 = V_105 ;
if ( ! F_33 ( & V_91 -> V_10 . V_75 ) )
break;
V_86 = & V_91 -> V_10 . V_106 ;
V_92 = 0 ;
break;
case V_99 :
V_92 = V_105 ;
if ( ! F_33 ( & V_91 -> V_10 . V_75 ) )
break;
V_86 = & V_91 -> V_10 . V_107 ;
V_92 = 0 ;
break;
case V_108 :
V_92 = V_105 ;
if ( F_33 ( & V_91 -> V_10 . V_106 ) ||
F_33 ( & V_91 -> V_10 . V_107 ) )
break;
V_86 = & V_91 -> V_10 . V_75 ;
V_92 = 0 ;
break;
case V_109 :
V_86 = & V_91 -> V_10 . V_106 ;
V_92 = 0 ;
break;
case V_110 :
V_86 = & V_91 -> V_10 . V_107 ;
V_92 = 0 ;
break;
}
if ( V_86 ) {
V_86 -> V_84 = V_75 ;
V_86 -> V_81 = V_81 ;
V_86 -> V_85 = 1 ;
}
F_22 ( & V_91 -> V_10 . V_83 ) ;
return V_92 ;
}
static void F_39 ( struct V_1 * V_2 , struct V_79 * V_86 )
{
struct V_68 * V_68 = V_2 -> V_68 ;
void * V_90 ;
unsigned long V_89 ;
unsigned long V_111 ;
for (; ; ) {
V_111 = V_86 -> V_84 ;
F_22 ( & V_2 -> V_10 . V_83 ) ;
V_90 = NULL ;
V_89 = 0 ;
if ( V_111 )
V_90 = F_35 ( V_68 , V_111 , & V_89 ) ;
F_21 ( & V_2 -> V_10 . V_83 ) ;
if ( V_111 == V_86 -> V_84 )
break;
if ( V_90 )
F_38 ( V_68 , V_90 , V_111 , false ) ;
}
V_86 -> V_85 = 0 ;
if ( V_90 && V_89 < V_86 -> V_81 ) {
F_38 ( V_68 , V_90 , V_111 , false ) ;
V_90 = NULL ;
}
if ( V_86 -> V_87 )
F_38 ( V_68 , V_86 -> V_87 , V_86 -> V_111 ,
V_86 -> V_112 ) ;
V_86 -> V_111 = V_111 ;
V_86 -> V_87 = V_90 ;
V_86 -> V_112 = false ;
if ( V_90 )
V_86 -> V_113 = V_90 + V_86 -> V_81 ;
}
static void F_40 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_10 . V_75 . V_85 ||
V_2 -> V_10 . V_107 . V_85 ||
V_2 -> V_10 . V_106 . V_85 ) )
return;
F_21 ( & V_2 -> V_10 . V_83 ) ;
if ( V_2 -> V_10 . V_75 . V_85 ) {
F_39 ( V_2 , & V_2 -> V_10 . V_75 ) ;
if ( V_2 -> V_10 . V_75 . V_87 )
F_30 ( V_2 , V_2 -> V_10 . V_75 . V_87 ) ;
}
if ( V_2 -> V_10 . V_106 . V_85 ) {
F_39 ( V_2 , & V_2 -> V_10 . V_106 ) ;
V_2 -> V_10 . V_114 = V_2 -> V_10 . V_106 . V_87 ;
V_2 -> V_10 . V_115 = 0 ;
}
if ( V_2 -> V_10 . V_107 . V_85 )
F_39 ( V_2 , & V_2 -> V_10 . V_107 ) ;
F_22 ( & V_2 -> V_10 . V_83 ) ;
}
static T_2 F_41 ( struct V_15 * V_16 , T_2 V_116 )
{
T_2 V_117 ;
if ( V_16 -> V_21 != V_22 &&
V_16 -> V_20 -> V_10 . V_118 != V_119 ) {
F_42 ( & V_16 -> V_20 -> V_10 . V_19 ) ;
V_117 = V_16 -> V_25 ;
if ( V_16 -> V_23 != V_24 )
V_117 += V_116 - V_16 -> V_23 ;
F_43 ( & V_16 -> V_20 -> V_10 . V_19 ) ;
} else {
V_117 = V_16 -> V_25 ;
}
return V_117 ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_104 * V_120 ;
struct V_74 * V_75 ;
unsigned long V_121 ;
unsigned long V_122 ;
T_2 V_116 ;
V_120 = V_2 -> V_10 . V_114 ;
V_75 = V_2 -> V_10 . V_75 . V_87 ;
V_116 = F_13 () ;
V_122 = F_41 ( V_16 , V_116 ) ;
V_121 = V_122 - V_2 -> V_10 . V_123 ;
V_2 -> V_10 . V_123 = V_122 ;
F_42 ( & V_2 -> V_10 . V_19 ) ;
V_121 += V_2 -> V_10 . V_29 ;
V_2 -> V_10 . V_29 = 0 ;
F_43 ( & V_2 -> V_10 . V_19 ) ;
if ( ! V_120 || ! V_75 )
return;
memset ( V_120 , 0 , sizeof( struct V_104 ) ) ;
V_120 -> V_124 = 7 ;
V_120 -> V_125 = F_45 ( V_16 -> V_126 + V_2 -> V_10 . V_11 ) ;
V_120 -> V_127 = F_46 ( V_116 + V_16 -> V_128 ) ;
V_120 -> V_129 = F_31 ( V_121 ) ;
V_120 -> V_51 = F_46 ( F_47 ( V_2 ) ) ;
V_120 -> V_52 = F_46 ( V_2 -> V_10 . V_31 . V_30 ) ;
++ V_120 ;
if ( V_120 == V_2 -> V_10 . V_106 . V_113 )
V_120 = V_2 -> V_10 . V_106 . V_87 ;
V_2 -> V_10 . V_114 = V_120 ;
F_48 () ;
V_75 -> V_130 = F_46 ( ++ V_2 -> V_10 . V_115 ) ;
V_2 -> V_10 . V_106 . V_112 = true ;
}
static bool F_49 ( struct V_1 * V_2 )
{
if ( V_2 -> V_10 . V_17 -> V_33 >= V_42 )
return true ;
if ( ( ! V_2 -> V_10 . V_17 -> V_33 ) &&
F_20 ( V_43 ) )
return true ;
return false ;
}
static int F_50 ( struct V_1 * V_2 , unsigned long V_131 ,
unsigned long V_132 , unsigned long V_133 ,
unsigned long V_134 )
{
switch ( V_132 ) {
case V_135 :
if ( ! F_49 ( V_2 ) )
return V_136 ;
if ( V_134 )
return V_137 ;
if ( V_131 )
return V_138 ;
if ( ( V_133 & V_139 ) == V_140 )
return V_141 ;
V_2 -> V_10 . V_142 = V_133 ;
return V_143 ;
case V_144 :
if ( ! F_49 ( V_2 ) )
return V_136 ;
if ( V_131 )
return V_138 ;
if ( V_134 & V_145 )
return V_137 ;
V_2 -> V_10 . V_146 = V_133 ;
V_2 -> V_10 . V_147 = V_134 ;
return V_143 ;
default:
return V_148 ;
}
}
int F_51 ( struct V_1 * V_2 )
{
unsigned long V_149 = F_25 ( V_2 , 3 ) ;
unsigned long V_150 , V_73 = V_143 ;
struct V_1 * V_91 ;
int V_151 , V_152 ;
if ( V_149 <= V_153 &&
! F_52 ( V_149 / 4 , V_2 -> V_68 -> V_10 . V_154 ) )
return V_155 ;
switch ( V_149 ) {
case V_156 :
V_151 = F_53 ( & V_2 -> V_68 -> V_157 ) ;
V_73 = F_54 ( V_2 , F_25 ( V_2 , 4 ) ,
F_25 ( V_2 , 5 ) ,
F_25 ( V_2 , 6 ) ,
F_25 ( V_2 , 7 ) ) ;
F_55 ( & V_2 -> V_68 -> V_157 , V_151 ) ;
break;
case V_158 :
break;
case V_159 :
V_150 = F_25 ( V_2 , 4 ) ;
V_91 = F_26 ( V_2 -> V_68 , V_150 ) ;
if ( ! V_91 ) {
V_73 = V_94 ;
break;
}
V_91 -> V_10 . V_160 = 1 ;
F_56 () ;
if ( V_2 -> V_10 . V_161 ) {
if ( F_3 ( & V_2 -> V_162 ) ) {
F_4 ( & V_2 -> V_162 ) ;
V_2 -> V_6 . V_7 ++ ;
}
}
break;
case V_163 :
V_150 = F_25 ( V_2 , 4 ) ;
if ( V_150 == - 1 )
break;
V_91 = F_26 ( V_2 -> V_68 , V_150 ) ;
if ( ! V_91 ) {
V_73 = V_94 ;
break;
}
F_57 ( V_91 ) ;
break;
case V_164 :
V_73 = F_34 ( V_2 , F_25 ( V_2 , 4 ) ,
F_25 ( V_2 , 5 ) ,
F_25 ( V_2 , 6 ) ) ;
break;
case V_165 :
if ( F_58 ( & V_2 -> V_68 -> V_10 . V_166 ) )
return V_155 ;
V_151 = F_53 ( & V_2 -> V_68 -> V_157 ) ;
V_152 = F_59 ( V_2 ) ;
F_55 ( & V_2 -> V_68 -> V_157 , V_151 ) ;
if ( V_152 == - V_167 )
return V_155 ;
else if ( V_152 == 0 )
break;
return V_152 ;
case V_168 :
V_73 = F_50 ( V_2 , F_25 ( V_2 , 4 ) ,
F_25 ( V_2 , 5 ) ,
F_25 ( V_2 , 6 ) ,
F_25 ( V_2 , 7 ) ) ;
if ( V_73 == V_148 )
return V_155 ;
break;
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
if ( F_60 ( V_2 ) ) {
V_73 = F_61 ( V_2 , V_149 ) ;
break;
}
default:
return V_155 ;
}
F_62 ( V_2 , 3 , V_73 ) ;
V_2 -> V_10 . V_175 = 0 ;
return V_176 ;
}
static int F_63 ( unsigned long V_177 )
{
switch ( V_177 ) {
case V_158 :
case V_159 :
case V_163 :
case V_164 :
case V_168 :
#ifdef F_64
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
#endif
return 1 ;
}
return F_65 ( V_177 ) ;
}
static int F_66 ( struct V_178 * V_179 , struct V_1 * V_2 ,
struct V_180 * V_181 )
{
int V_45 = V_155 ;
V_2 -> V_6 . V_182 ++ ;
V_179 -> V_183 = V_184 ;
V_179 -> V_185 = 1 ;
switch ( V_2 -> V_10 . V_48 ) {
case V_186 :
V_2 -> V_6 . V_187 ++ ;
V_45 = V_176 ;
break;
case V_188 :
case V_189 :
V_2 -> V_6 . V_190 ++ ;
V_45 = V_176 ;
break;
case V_191 :
V_45 = V_176 ;
break;
case V_192 :
F_67 ( V_2 ,
V_192 ) ;
V_45 = V_176 ;
break;
case V_193 :
{
T_4 V_18 ;
V_18 = V_2 -> V_10 . V_31 . V_30 & 0x1f0000ull ;
F_68 ( V_2 , V_18 ) ;
V_45 = V_176 ;
break;
}
case V_194 :
{
int V_195 ;
V_179 -> V_196 . V_197 = F_25 ( V_2 , 3 ) ;
for ( V_195 = 0 ; V_195 < 9 ; ++ V_195 )
V_179 -> V_196 . args [ V_195 ] = F_25 ( V_2 , 4 + V_195 ) ;
V_179 -> V_183 = V_198 ;
V_2 -> V_10 . V_175 = 1 ;
V_45 = V_155 ;
break;
}
case V_199 :
V_45 = V_200 ;
break;
case V_201 :
V_2 -> V_10 . V_61 = F_47 ( V_2 ) ;
V_2 -> V_10 . V_62 = 0 ;
V_45 = V_200 ;
break;
case V_202 :
F_68 ( V_2 , V_203 ) ;
V_45 = V_176 ;
break;
case V_204 :
F_68 ( V_2 , V_203 ) ;
V_45 = V_176 ;
break;
default:
F_23 ( V_2 ) ;
F_69 ( V_205 L_14 ,
V_2 -> V_10 . V_48 , F_47 ( V_2 ) ,
V_2 -> V_10 . V_31 . V_30 ) ;
V_179 -> V_206 . V_207 = V_2 -> V_10 . V_48 ;
V_45 = V_155 ;
break;
}
return V_45 ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_208 * V_209 )
{
int V_195 ;
memset ( V_209 , 0 , sizeof( struct V_208 ) ) ;
V_209 -> V_32 = V_2 -> V_10 . V_32 ;
for ( V_195 = 0 ; V_195 < V_2 -> V_10 . V_63 ; V_195 ++ ) {
V_209 -> V_210 . V_211 . V_212 . V_64 [ V_195 ] . V_213 = V_2 -> V_10 . V_64 [ V_195 ] . V_65 ;
V_209 -> V_210 . V_211 . V_212 . V_64 [ V_195 ] . V_214 = V_2 -> V_10 . V_64 [ V_195 ] . V_66 ;
}
return 0 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_208 * V_209 )
{
int V_195 , V_215 ;
F_18 ( V_2 , V_209 -> V_32 ) ;
V_215 = 0 ;
for ( V_195 = 0 ; V_195 < V_2 -> V_10 . V_216 ; V_195 ++ ) {
if ( V_209 -> V_210 . V_211 . V_212 . V_64 [ V_195 ] . V_213 & V_217 ) {
V_2 -> V_10 . V_64 [ V_215 ] . V_65 = V_209 -> V_210 . V_211 . V_212 . V_64 [ V_195 ] . V_213 ;
V_2 -> V_10 . V_64 [ V_215 ] . V_66 = V_209 -> V_210 . V_211 . V_212 . V_64 [ V_195 ] . V_214 ;
++ V_215 ;
}
}
V_2 -> V_10 . V_63 = V_215 ;
return 0 ;
}
static void F_72 ( struct V_1 * V_2 , T_2 V_218 ,
bool V_219 )
{
struct V_15 * V_16 = V_2 -> V_10 . V_17 ;
T_2 V_220 ;
F_21 ( & V_16 -> V_44 ) ;
if ( ( V_218 & V_221 ) != ( V_16 -> V_67 & V_221 ) ) {
struct V_68 * V_68 = V_2 -> V_68 ;
struct V_1 * V_2 ;
int V_195 ;
F_27 ( & V_68 -> V_44 ) ;
F_28 (i, vcpu, kvm) {
if ( V_2 -> V_10 . V_17 != V_16 )
continue;
if ( V_218 & V_221 )
V_2 -> V_10 . V_222 |= V_223 ;
else
V_2 -> V_10 . V_222 &= ~ V_223 ;
}
F_29 ( & V_68 -> V_44 ) ;
}
V_220 = V_224 | V_221 | V_225 ;
if ( F_20 ( V_43 ) )
V_220 |= V_226 ;
if ( V_219 )
V_220 &= 0xFFFFFFFF ;
V_16 -> V_67 = ( V_16 -> V_67 & ~ V_220 ) | ( V_218 & V_220 ) ;
F_22 ( & V_16 -> V_44 ) ;
}
static int F_73 ( struct V_1 * V_2 , T_2 V_71 ,
union V_227 * V_228 )
{
int V_45 = 0 ;
long int V_195 ;
switch ( V_71 ) {
case V_229 :
* V_228 = F_74 ( V_71 , 0 ) ;
break;
case V_230 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_231 ) ;
break;
case V_232 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_233 ) ;
break;
case V_234 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_235 ) ;
break;
case V_236 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_237 ) ;
break;
case V_238 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_239 ) ;
break;
case V_240 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_241 ) ;
break;
case V_242 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_243 ) ;
break;
case V_244 ... V_245 :
V_195 = V_71 - V_244 ;
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_246 [ V_195 ] ) ;
break;
case V_247 ... V_248 :
V_195 = V_71 - V_247 ;
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_249 [ V_195 ] ) ;
break;
case V_250 ... V_251 :
V_195 = V_71 - V_250 ;
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_252 [ V_195 ] ) ;
break;
case V_253 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_254 ) ;
break;
case V_255 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_256 ) ;
break;
case V_257 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_258 ) ;
break;
case V_259 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_260 ) ;
break;
case V_261 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_262 ) ;
break;
case V_263 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_17 -> V_264 ) ;
break;
case V_265 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_146 ) ;
break;
case V_266 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_147 ) ;
break;
case V_267 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_142 ) ;
break;
case V_268 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_269 ) ;
break;
case V_270 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_271 ) ;
break;
case V_272 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_273 ) ;
break;
case V_274 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_275 ) ;
break;
case V_276 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_277 ) ;
break;
case V_278 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_279 ) ;
break;
case V_280 :
F_21 ( & V_2 -> V_10 . V_83 ) ;
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_75 . V_84 ) ;
F_22 ( & V_2 -> V_10 . V_83 ) ;
break;
case V_281 :
F_21 ( & V_2 -> V_10 . V_83 ) ;
V_228 -> V_282 . V_80 = V_2 -> V_10 . V_107 . V_84 ;
V_228 -> V_282 . V_101 = V_2 -> V_10 . V_107 . V_81 ;
F_22 ( & V_2 -> V_10 . V_83 ) ;
break;
case V_283 :
F_21 ( & V_2 -> V_10 . V_83 ) ;
V_228 -> V_282 . V_80 = V_2 -> V_10 . V_106 . V_84 ;
V_228 -> V_282 . V_101 = V_2 -> V_10 . V_106 . V_81 ;
F_22 ( & V_2 -> V_10 . V_83 ) ;
break;
case V_284 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_17 -> V_128 ) ;
break;
case V_285 :
case V_286 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_17 -> V_67 ) ;
break;
case V_287 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_288 ) ;
break;
#ifdef F_75
case V_289 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_290 ) ;
break;
case V_291 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_292 ) ;
break;
case V_293 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_294 ) ;
break;
case V_295 ... V_296 :
V_195 = V_71 - V_295 ;
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_297 [ V_195 ] ) ;
break;
case V_298 ... V_299 :
{
int V_215 ;
V_195 = V_71 - V_298 ;
if ( V_195 < 32 )
for ( V_215 = 0 ; V_215 < V_300 ; V_215 ++ )
V_228 -> V_301 [ V_215 ] = V_2 -> V_10 . V_302 . V_303 [ V_195 ] [ V_215 ] ;
else {
if ( F_20 ( V_304 ) )
V_228 -> V_305 = V_2 -> V_10 . V_306 . V_307 [ V_195 - 32 ] ;
else
V_45 = - V_308 ;
}
break;
}
case V_309 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_310 ) ;
break;
case V_311 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_312 ) ;
break;
case V_313 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_314 ) ;
break;
case V_315 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_302 . V_316 ) ;
break;
case V_317 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_318 ) ;
break;
case V_319 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_320 ) ;
break;
case V_321 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_322 ) ;
break;
case V_323 :
if ( F_20 ( V_304 ) )
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_306 . V_324 . V_210 [ 3 ] ) ;
else
V_45 = - V_308 ;
break;
case V_325 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_326 ) ;
break;
case V_327 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_328 ) ;
break;
#endif
case V_329 :
* V_228 = F_74 ( V_71 , V_2 -> V_10 . V_17 -> V_33 ) ;
break;
default:
V_45 = - V_36 ;
break;
}
return V_45 ;
}
static int F_76 ( struct V_1 * V_2 , T_2 V_71 ,
union V_227 * V_228 )
{
int V_45 = 0 ;
long int V_195 ;
unsigned long V_80 , V_81 ;
switch ( V_71 ) {
case V_229 :
if ( F_77 ( V_71 , * V_228 ) )
V_45 = - V_36 ;
break;
case V_230 :
V_2 -> V_10 . V_231 = F_77 ( V_71 , * V_228 ) ;
break;
case V_232 :
V_2 -> V_10 . V_233 = F_77 ( V_71 , * V_228 ) & ~ V_145 ;
break;
case V_234 :
V_2 -> V_10 . V_235 = F_77 ( V_71 , * V_228 ) ;
break;
case V_236 :
V_2 -> V_10 . V_237 = F_77 ( V_71 , * V_228 ) ;
break;
case V_238 :
V_2 -> V_10 . V_239 = F_77 ( V_71 , * V_228 ) ;
break;
case V_240 :
V_2 -> V_10 . V_241 = F_77 ( V_71 , * V_228 ) ;
break;
case V_242 :
V_2 -> V_10 . V_243 = F_77 ( V_71 , * V_228 ) ;
break;
case V_244 ... V_245 :
V_195 = V_71 - V_244 ;
V_2 -> V_10 . V_246 [ V_195 ] = F_77 ( V_71 , * V_228 ) ;
break;
case V_247 ... V_248 :
V_195 = V_71 - V_247 ;
V_2 -> V_10 . V_249 [ V_195 ] = F_77 ( V_71 , * V_228 ) ;
break;
case V_250 ... V_251 :
V_195 = V_71 - V_250 ;
V_2 -> V_10 . V_252 [ V_195 ] = F_77 ( V_71 , * V_228 ) ;
break;
case V_253 :
V_2 -> V_10 . V_254 = F_77 ( V_71 , * V_228 ) ;
break;
case V_255 :
V_2 -> V_10 . V_256 = F_77 ( V_71 , * V_228 ) ;
break;
case V_257 :
V_2 -> V_10 . V_258 = F_77 ( V_71 , * V_228 ) ;
break;
case V_259 :
V_2 -> V_10 . V_260 = F_77 ( V_71 , * V_228 ) ;
break;
case V_261 :
V_2 -> V_10 . V_262 = F_77 ( V_71 , * V_228 ) ;
break;
case V_263 :
V_2 -> V_10 . V_17 -> V_264 = F_77 ( V_71 , * V_228 ) ;
break;
case V_265 :
V_2 -> V_10 . V_146 = F_77 ( V_71 , * V_228 ) ;
break;
case V_266 :
V_2 -> V_10 . V_147 = F_77 ( V_71 , * V_228 ) & ~ V_330 ;
break;
case V_267 :
V_2 -> V_10 . V_142 = F_77 ( V_71 , * V_228 ) ;
if ( ( V_2 -> V_10 . V_142 & V_139 ) == V_140 )
V_2 -> V_10 . V_142 &= ~ V_139 ;
break;
case V_268 :
V_2 -> V_10 . V_269 = F_77 ( V_71 , * V_228 ) ;
break;
case V_270 :
V_2 -> V_10 . V_271 = F_77 ( V_71 , * V_228 ) ;
break;
case V_272 :
V_2 -> V_10 . V_273 = F_77 ( V_71 , * V_228 ) ;
break;
case V_274 :
V_2 -> V_10 . V_275 = F_77 ( V_71 , * V_228 ) ;
break;
case V_276 :
V_2 -> V_10 . V_277 = F_77 ( V_71 , * V_228 ) ;
break;
case V_278 :
V_2 -> V_10 . V_279 = F_77 ( V_71 , * V_228 ) ;
break;
case V_280 :
V_80 = F_77 ( V_71 , * V_228 ) ;
V_45 = - V_36 ;
if ( ! V_80 && ( V_2 -> V_10 . V_107 . V_84 ||
V_2 -> V_10 . V_106 . V_84 ) )
break;
V_45 = F_32 ( V_2 , & V_2 -> V_10 . V_75 , V_80 , sizeof( struct V_74 ) ) ;
break;
case V_281 :
V_80 = V_228 -> V_282 . V_80 ;
V_81 = V_228 -> V_282 . V_101 ;
V_45 = - V_36 ;
if ( V_80 && ! V_2 -> V_10 . V_75 . V_84 )
break;
V_45 = F_32 ( V_2 , & V_2 -> V_10 . V_107 , V_80 , V_81 ) ;
break;
case V_283 :
V_80 = V_228 -> V_282 . V_80 ;
V_81 = V_228 -> V_282 . V_101 ;
V_45 = - V_36 ;
if ( V_80 && ( V_81 < sizeof( struct V_104 ) ||
! V_2 -> V_10 . V_75 . V_84 ) )
break;
V_81 -= V_81 % sizeof( struct V_104 ) ;
V_45 = F_32 ( V_2 , & V_2 -> V_10 . V_106 , V_80 , V_81 ) ;
break;
case V_284 :
V_2 -> V_10 . V_17 -> V_128 =
F_78 ( F_77 ( V_71 , * V_228 ) , 1UL << 24 ) ;
break;
case V_285 :
F_72 ( V_2 , F_77 ( V_71 , * V_228 ) , true ) ;
break;
case V_286 :
F_72 ( V_2 , F_77 ( V_71 , * V_228 ) , false ) ;
break;
case V_287 :
V_2 -> V_10 . V_288 = F_77 ( V_71 , * V_228 ) ;
break;
#ifdef F_75
case V_289 :
V_2 -> V_10 . V_290 = F_77 ( V_71 , * V_228 ) ;
break;
case V_291 :
V_2 -> V_10 . V_292 = F_77 ( V_71 , * V_228 ) ;
break;
case V_293 :
V_2 -> V_10 . V_294 = F_77 ( V_71 , * V_228 ) ;
break;
case V_295 ... V_296 :
V_195 = V_71 - V_295 ;
V_2 -> V_10 . V_297 [ V_195 ] = F_77 ( V_71 , * V_228 ) ;
break;
case V_298 ... V_299 :
{
int V_215 ;
V_195 = V_71 - V_298 ;
if ( V_195 < 32 )
for ( V_215 = 0 ; V_215 < V_300 ; V_215 ++ )
V_2 -> V_10 . V_302 . V_303 [ V_195 ] [ V_215 ] = V_228 -> V_301 [ V_215 ] ;
else
if ( F_20 ( V_304 ) )
V_2 -> V_10 . V_306 . V_307 [ V_195 - 32 ] = V_228 -> V_305 ;
else
V_45 = - V_308 ;
break;
}
case V_309 :
V_2 -> V_10 . V_310 = F_77 ( V_71 , * V_228 ) ;
break;
case V_311 :
V_2 -> V_10 . V_312 = F_77 ( V_71 , * V_228 ) ;
break;
case V_313 :
V_2 -> V_10 . V_314 = F_77 ( V_71 , * V_228 ) ;
break;
case V_315 :
V_2 -> V_10 . V_302 . V_316 = F_77 ( V_71 , * V_228 ) ;
break;
case V_317 :
V_2 -> V_10 . V_318 = F_77 ( V_71 , * V_228 ) ;
break;
case V_319 :
V_2 -> V_10 . V_320 = F_77 ( V_71 , * V_228 ) ;
break;
case V_321 :
V_2 -> V_10 . V_322 = F_77 ( V_71 , * V_228 ) ;
break;
case V_323 :
if ( F_20 ( V_304 ) )
V_2 -> V_10 . V_307 . V_324 . V_210 [ 3 ] = F_77 ( V_71 , * V_228 ) ;
else
V_45 = - V_308 ;
break;
case V_325 :
V_2 -> V_10 . V_326 = F_77 ( V_71 , * V_228 ) ;
break;
case V_327 :
V_2 -> V_10 . V_328 = F_77 ( V_71 , * V_228 ) ;
break;
#endif
case V_329 :
V_45 = F_19 ( V_2 , F_77 ( V_71 , * V_228 ) ) ;
break;
default:
V_45 = - V_36 ;
break;
}
return V_45 ;
}
static struct V_15 * F_79 ( struct V_68 * V_68 , int V_331 )
{
struct V_15 * V_17 ;
V_17 = F_80 ( sizeof( struct V_15 ) , V_332 ) ;
if ( V_17 == NULL )
return NULL ;
F_81 ( & V_17 -> V_333 ) ;
F_82 ( & V_17 -> V_44 ) ;
F_83 ( & V_17 -> V_162 ) ;
V_17 -> V_23 = V_24 ;
V_17 -> V_67 = V_68 -> V_10 . V_67 ;
V_17 -> V_334 = V_331 * V_335 ;
V_17 -> V_68 = V_68 ;
V_17 -> V_336 = false ;
if ( F_20 ( V_43 ) )
V_17 -> V_337 = ( void * ) F_84 (
V_332 | V_338 ,
V_339 ) ;
return V_17 ;
}
static struct V_1 * F_85 ( struct V_68 * V_68 ,
unsigned int V_71 )
{
struct V_1 * V_2 ;
int V_92 = - V_36 ;
int V_331 ;
struct V_15 * V_17 ;
V_331 = V_71 / V_335 ;
if ( V_331 >= V_340 )
goto V_341;
V_92 = - V_342 ;
V_2 = F_86 ( V_343 , V_332 ) ;
if ( ! V_2 )
goto V_341;
V_92 = F_87 ( V_2 , V_68 , V_71 ) ;
if ( V_92 )
goto V_344;
V_2 -> V_10 . V_345 = & V_2 -> V_10 . V_31 ;
#ifdef F_88
#ifdef F_89
V_2 -> V_10 . V_346 = true ;
#else
V_2 -> V_10 . V_346 = false ;
#endif
#endif
V_2 -> V_10 . V_246 [ 0 ] = V_347 ;
V_2 -> V_10 . V_348 = V_349 ;
F_18 ( V_2 , F_90 ( V_350 ) ) ;
F_82 ( & V_2 -> V_10 . V_83 ) ;
F_82 ( & V_2 -> V_10 . V_19 ) ;
V_2 -> V_10 . V_28 = V_24 ;
V_2 -> V_10 . V_222 = V_351 | V_352 ;
F_91 ( V_2 ) ;
V_2 -> V_10 . V_26 = V_353 ;
F_83 ( & V_2 -> V_10 . V_354 ) ;
F_27 ( & V_68 -> V_44 ) ;
V_17 = V_68 -> V_10 . V_355 [ V_331 ] ;
if ( ! V_17 ) {
V_17 = F_79 ( V_68 , V_331 ) ;
V_68 -> V_10 . V_355 [ V_331 ] = V_17 ;
V_68 -> V_10 . V_356 ++ ;
}
F_29 ( & V_68 -> V_44 ) ;
if ( ! V_17 )
goto V_344;
F_21 ( & V_17 -> V_44 ) ;
++ V_17 -> V_357 ;
F_22 ( & V_17 -> V_44 ) ;
V_2 -> V_10 . V_17 = V_17 ;
V_2 -> V_10 . V_11 = V_2 -> V_46 - V_17 -> V_334 ;
V_2 -> V_10 . V_358 = V_359 ;
F_92 ( V_2 ) ;
return V_2 ;
V_344:
F_93 ( V_343 , V_2 ) ;
V_341:
return F_94 ( V_92 ) ;
}
static void F_95 ( struct V_68 * V_68 , struct V_79 * V_75 )
{
if ( V_75 -> V_87 )
F_38 ( V_68 , V_75 -> V_87 , V_75 -> V_111 ,
V_75 -> V_112 ) ;
}
static void F_96 ( struct V_1 * V_2 )
{
F_21 ( & V_2 -> V_10 . V_83 ) ;
F_95 ( V_2 -> V_68 , & V_2 -> V_10 . V_106 ) ;
F_95 ( V_2 -> V_68 , & V_2 -> V_10 . V_107 ) ;
F_95 ( V_2 -> V_68 , & V_2 -> V_10 . V_75 ) ;
F_22 ( & V_2 -> V_10 . V_83 ) ;
F_97 ( V_2 ) ;
F_93 ( V_343 , V_2 ) ;
}
static int F_98 ( struct V_1 * V_2 )
{
return 1 ;
}
static void F_99 ( struct V_1 * V_2 )
{
unsigned long V_360 , V_116 ;
V_116 = F_100 () ;
if ( V_116 > V_2 -> V_10 . V_361 ) {
F_101 ( V_2 ) ;
F_102 ( V_2 ) ;
return;
}
V_360 = ( V_2 -> V_10 . V_361 - V_116 ) * V_362
/ V_363 ;
F_103 ( & V_2 -> V_10 . V_364 , F_104 ( 0 , V_360 ) ,
V_365 ) ;
V_2 -> V_10 . V_366 = 1 ;
}
static void F_17 ( struct V_1 * V_2 )
{
V_2 -> V_10 . V_161 = 0 ;
if ( V_2 -> V_10 . V_366 ) {
F_105 ( & V_2 -> V_10 . V_364 ) ;
V_2 -> V_10 . V_366 = 0 ;
}
}
static void F_106 ( struct V_15 * V_16 ,
struct V_1 * V_2 )
{
T_2 V_116 ;
if ( V_2 -> V_10 . V_26 != V_367 )
return;
F_42 ( & V_2 -> V_10 . V_19 ) ;
V_116 = F_13 () ;
V_2 -> V_10 . V_29 += F_41 ( V_16 , V_116 ) -
V_2 -> V_10 . V_123 ;
V_2 -> V_10 . V_28 = V_116 ;
V_2 -> V_10 . V_26 = V_27 ;
F_43 ( & V_2 -> V_10 . V_19 ) ;
-- V_16 -> V_368 ;
F_107 ( & V_2 -> V_10 . V_369 ) ;
}
static int F_108 ( int V_4 )
{
struct V_370 * V_371 ;
long V_372 = 1000 ;
V_371 = & V_12 [ V_4 ] ;
V_371 -> V_13 . V_373 = 1 ;
V_371 -> V_13 . V_1 = NULL ;
F_56 () ;
while ( V_371 -> V_13 . V_374 == V_375 ) {
if ( -- V_372 <= 0 ) {
F_24 ( L_15 , V_4 ) ;
return - V_376 ;
}
F_109 ( 1 ) ;
}
return 0 ;
}
static void F_110 ( int V_4 )
{
struct V_370 * V_371 ;
V_371 = & V_12 [ V_4 ] ;
V_371 -> V_13 . V_373 = 0 ;
V_371 -> V_13 . V_1 = NULL ;
}
static void F_111 ( struct V_1 * V_2 )
{
int V_4 ;
struct V_370 * V_371 ;
struct V_15 * V_16 = V_2 -> V_10 . V_17 ;
if ( V_2 -> V_10 . V_366 ) {
F_105 ( & V_2 -> V_10 . V_364 ) ;
V_2 -> V_10 . V_366 = 0 ;
}
V_4 = V_16 -> V_126 + V_2 -> V_10 . V_11 ;
V_371 = & V_12 [ V_4 ] ;
V_371 -> V_13 . V_1 = V_2 ;
V_371 -> V_13 . V_377 = V_16 ;
V_371 -> V_13 . V_11 = V_2 -> V_10 . V_11 ;
V_2 -> V_4 = V_16 -> V_126 ;
F_48 () ;
#if F_112 ( F_6 ) && F_112 ( V_378 )
if ( V_4 != F_113 () ) {
F_7 ( V_4 ) ;
if ( V_2 -> V_10 . V_11 )
++ V_16 -> V_379 ;
}
#endif
}
static void F_114 ( struct V_15 * V_16 )
{
int V_195 ;
F_115 () ;
V_195 = 0 ;
while ( V_16 -> V_380 < V_16 -> V_379 ) {
if ( ++ V_195 >= 1000000 ) {
F_24 ( L_16 ,
V_16 -> V_380 , V_16 -> V_379 ) ;
break;
}
F_116 () ;
}
F_117 () ;
}
static int F_118 ( void )
{
int V_4 = F_113 () ;
int V_381 ;
if ( F_119 ( V_4 ) )
return 0 ;
V_381 = 0 ;
while ( ++ V_381 < V_335 )
if ( F_8 ( V_4 + V_381 ) )
return 0 ;
for ( V_381 = 1 ; V_381 < V_335 ; ++ V_381 ) {
if ( F_108 ( V_4 + V_381 ) ) {
do {
F_110 ( V_4 + V_381 ) ;
} while ( -- V_381 > 0 );
return 0 ;
}
}
return 1 ;
}
static void F_120 ( struct V_15 * V_16 )
{
T_5 V_382 , V_383 ;
V_382 = ( T_5 ) F_121 ( V_16 -> V_337 ) ;
V_383 = V_382 & V_384 ;
F_122 ( V_385 , V_383 | V_386 ) ;
F_123 ( V_383 | V_387 ) ;
V_16 -> V_336 = true ;
}
static void F_124 ( const struct V_15 * V_16 )
{
T_5 V_382 , V_383 ;
V_382 = F_121 ( V_16 -> V_337 ) ;
V_383 = V_382 & V_384 ;
F_123 ( V_383 | V_388 ) ;
F_122 ( V_385 , V_383 | V_389 ) ;
}
static void F_125 ( struct V_15 * V_16 )
{
struct V_1 * V_2 , * V_390 ;
long V_73 ;
T_2 V_116 ;
int V_195 , V_391 ;
int V_392 ;
struct V_1 * V_393 [ V_394 ] ;
V_391 = 0 ;
F_126 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( F_127 ( V_2 -> V_10 . V_118 ) )
return;
if ( V_2 -> V_10 . V_75 . V_85 ||
V_2 -> V_10 . V_107 . V_85 ||
V_2 -> V_10 . V_106 . V_85 )
V_393 [ V_391 ++ ] = V_2 ;
}
V_16 -> V_379 = 0 ;
V_16 -> V_380 = 0 ;
V_16 -> V_395 = 0 ;
V_16 -> V_21 = V_396 ;
V_16 -> V_397 = 0 ;
V_16 -> V_398 = 0 ;
if ( V_391 ) {
F_22 ( & V_16 -> V_44 ) ;
for ( V_195 = 0 ; V_195 < V_391 ; ++ V_195 )
F_40 ( V_393 [ V_195 ] ) ;
F_21 ( & V_16 -> V_44 ) ;
}
if ( ( V_394 > 1 ) &&
( ( V_16 -> V_357 > V_335 ) || ! F_118 () ) ) {
F_126 (vcpu, &vc->runnable_threads, arch.run_list)
V_2 -> V_10 . V_73 = - V_376 ;
goto V_341;
}
V_16 -> V_126 = F_113 () ;
F_126 (vcpu, &vc->runnable_threads, arch.run_list) {
F_111 ( V_2 ) ;
F_44 ( V_2 , V_16 ) ;
}
F_128 () -> V_13 . V_377 = V_16 ;
F_128 () -> V_13 . V_11 = 0 ;
V_16 -> V_21 = V_399 ;
F_129 () ;
F_22 ( & V_16 -> V_44 ) ;
F_130 () ;
V_392 = F_53 ( & V_16 -> V_68 -> V_157 ) ;
if ( V_16 -> V_336 )
F_124 ( V_16 ) ;
F_131 () ;
F_21 ( & V_16 -> V_44 ) ;
if ( V_16 -> V_337 )
F_120 ( V_16 ) ;
F_126 (vcpu, &vc->runnable_threads, arch.run_list)
V_2 -> V_4 = - 1 ;
if ( V_16 -> V_380 < V_16 -> V_379 )
F_114 ( V_16 ) ;
for ( V_195 = 0 ; V_195 < V_335 ; ++ V_195 )
F_110 ( V_16 -> V_126 + V_195 ) ;
V_16 -> V_21 = V_400 ;
F_22 ( & V_16 -> V_44 ) ;
F_55 ( & V_16 -> V_68 -> V_157 , V_392 ) ;
F_56 () ;
F_132 () ;
F_133 () ;
F_134 () ;
F_21 ( & V_16 -> V_44 ) ;
V_116 = F_100 () ;
F_126 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( V_116 < V_2 -> V_10 . V_361 &&
F_135 ( V_2 ) )
F_136 ( V_2 ) ;
V_73 = V_176 ;
if ( V_2 -> V_10 . V_48 )
V_73 = F_66 ( V_2 -> V_10 . V_178 , V_2 ,
V_2 -> V_10 . V_118 ) ;
V_2 -> V_10 . V_73 = V_73 ;
V_2 -> V_10 . V_48 = 0 ;
if ( V_2 -> V_10 . V_161 ) {
if ( ! F_137 ( V_73 ) )
F_17 ( V_2 ) ;
else
F_99 ( V_2 ) ;
}
}
V_341:
V_16 -> V_21 = V_22 ;
F_138 (vcpu, vnext, &vc->runnable_threads,
arch.run_list) {
if ( ! F_137 ( V_2 -> V_10 . V_73 ) ) {
F_106 ( V_16 , V_2 ) ;
F_139 ( & V_2 -> V_10 . V_354 ) ;
}
}
}
static void F_140 ( struct V_1 * V_2 , int V_401 )
{
F_141 ( V_402 ) ;
F_142 ( & V_2 -> V_10 . V_354 , & V_402 , V_401 ) ;
if ( V_2 -> V_10 . V_26 == V_367 )
F_143 () ;
F_144 ( & V_2 -> V_10 . V_354 , & V_402 ) ;
}
static void F_145 ( struct V_15 * V_16 )
{
F_141 ( V_402 ) ;
F_142 ( & V_16 -> V_162 , & V_402 , V_403 ) ;
V_16 -> V_21 = V_404 ;
F_22 ( & V_16 -> V_44 ) ;
F_143 () ;
F_144 ( & V_16 -> V_162 , & V_402 ) ;
F_21 ( & V_16 -> V_44 ) ;
V_16 -> V_21 = V_22 ;
}
static int F_146 ( struct V_178 * V_178 , struct V_1 * V_2 )
{
int V_405 ;
struct V_15 * V_16 ;
struct V_1 * V_72 , * V_406 ;
V_178 -> V_183 = 0 ;
V_2 -> V_10 . V_73 = V_176 ;
V_2 -> V_10 . V_48 = 0 ;
F_40 ( V_2 ) ;
V_16 = V_2 -> V_10 . V_17 ;
F_21 ( & V_16 -> V_44 ) ;
V_2 -> V_10 . V_161 = 0 ;
V_2 -> V_10 . V_118 = V_119 ;
V_2 -> V_10 . V_178 = V_178 ;
V_2 -> V_10 . V_123 = F_41 ( V_16 , F_13 () ) ;
V_2 -> V_10 . V_26 = V_367 ;
V_2 -> V_10 . V_28 = V_24 ;
F_147 ( & V_2 -> V_10 . V_369 , & V_16 -> V_333 ) ;
++ V_16 -> V_368 ;
if ( ! F_127 ( V_119 ) ) {
if ( V_16 -> V_21 == V_399 &&
F_148 ( V_16 ) == 0 ) {
F_44 ( V_2 , V_16 ) ;
F_111 ( V_2 ) ;
} else if ( V_16 -> V_21 == V_404 ) {
F_139 ( & V_16 -> V_162 ) ;
}
}
while ( V_2 -> V_10 . V_26 == V_367 &&
! F_127 ( V_119 ) ) {
if ( V_16 -> V_21 != V_22 ) {
F_22 ( & V_16 -> V_44 ) ;
F_140 ( V_2 , V_403 ) ;
F_21 ( & V_16 -> V_44 ) ;
continue;
}
F_138 (v, vn, &vc->runnable_threads,
arch.run_list) {
F_102 ( V_72 ) ;
if ( F_127 ( V_72 -> V_10 . V_118 ) ) {
F_106 ( V_16 , V_72 ) ;
V_72 -> V_6 . V_407 ++ ;
V_72 -> V_10 . V_178 -> V_183 = V_408 ;
V_72 -> V_10 . V_73 = - V_409 ;
F_139 ( & V_72 -> V_10 . V_354 ) ;
}
}
if ( ! V_16 -> V_368 || V_2 -> V_10 . V_26 != V_367 )
break;
V_16 -> V_20 = V_2 ;
V_405 = 0 ;
F_126 (v, &vc->runnable_threads, arch.run_list) {
if ( ! V_72 -> V_10 . V_410 )
V_405 += V_72 -> V_10 . V_161 ;
else
V_72 -> V_10 . V_161 = 0 ;
}
if ( V_405 == V_16 -> V_368 )
F_145 ( V_16 ) ;
else
F_125 ( V_16 ) ;
V_16 -> V_20 = NULL ;
}
while ( V_2 -> V_10 . V_26 == V_367 &&
( V_16 -> V_21 == V_399 ||
V_16 -> V_21 == V_400 ) ) {
F_22 ( & V_16 -> V_44 ) ;
F_140 ( V_2 , V_411 ) ;
F_21 ( & V_16 -> V_44 ) ;
}
if ( V_2 -> V_10 . V_26 == V_367 ) {
F_106 ( V_16 , V_2 ) ;
V_2 -> V_6 . V_407 ++ ;
V_178 -> V_183 = V_408 ;
V_2 -> V_10 . V_73 = - V_409 ;
}
if ( V_16 -> V_368 && V_16 -> V_21 == V_22 ) {
V_72 = F_149 ( & V_16 -> V_333 ,
struct V_1 , V_10 . V_369 ) ;
F_139 ( & V_72 -> V_10 . V_354 ) ;
}
F_22 ( & V_16 -> V_44 ) ;
return V_2 -> V_10 . V_73 ;
}
static int F_150 ( struct V_178 * V_179 , struct V_1 * V_2 )
{
int V_45 ;
int V_392 ;
if ( ! V_2 -> V_10 . V_412 ) {
V_179 -> V_183 = V_413 ;
return - V_36 ;
}
F_102 ( V_2 ) ;
if ( F_127 ( V_119 ) ) {
V_179 -> V_183 = V_408 ;
return - V_409 ;
}
F_151 ( & V_2 -> V_68 -> V_10 . V_414 ) ;
F_56 () ;
if ( ! V_2 -> V_68 -> V_10 . V_415 ) {
V_45 = F_152 ( V_2 ) ;
if ( V_45 )
goto V_341;
}
F_153 ( V_119 ) ;
F_154 ( V_119 ) ;
F_155 ( V_119 ) ;
V_2 -> V_10 . V_5 = & V_2 -> V_10 . V_17 -> V_162 ;
V_2 -> V_10 . V_416 = V_119 -> V_417 -> V_418 ;
V_2 -> V_10 . V_26 = V_27 ;
do {
V_45 = F_146 ( V_179 , V_2 ) ;
if ( V_179 -> V_183 == V_198 &&
! ( V_2 -> V_10 . V_31 . V_30 & V_419 ) ) {
V_45 = F_51 ( V_2 ) ;
F_102 ( V_2 ) ;
} else if ( V_45 == V_200 ) {
V_392 = F_53 ( & V_2 -> V_68 -> V_157 ) ;
V_45 = F_156 ( V_179 , V_2 ,
V_2 -> V_10 . V_61 , V_2 -> V_10 . V_62 ) ;
F_55 ( & V_2 -> V_68 -> V_157 , V_392 ) ;
}
} while ( F_137 ( V_45 ) );
V_341:
V_2 -> V_10 . V_26 = V_353 ;
F_157 ( & V_2 -> V_68 -> V_10 . V_414 ) ;
return V_45 ;
}
static inline int F_158 ( unsigned long V_420 )
{
switch ( V_420 ) {
case 32ul << 20 :
if ( F_20 ( V_35 ) )
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
static int F_159 ( struct V_421 * V_422 , struct V_423 * V_424 )
{
struct V_425 * V_425 ;
struct V_426 * V_427 = V_422 -> V_428 -> V_429 ;
if ( V_424 -> V_430 >= V_431 )
return V_432 ;
V_425 = F_160 ( V_427 -> V_433 + V_424 -> V_430 ) ;
F_161 ( V_425 ) ;
V_424 -> V_425 = V_425 ;
return 0 ;
}
static int F_162 ( struct V_434 * V_434 , struct V_421 * V_422 )
{
V_422 -> V_435 |= V_436 | V_437 ;
V_422 -> V_438 = & V_439 ;
return 0 ;
}
static int F_163 ( struct V_440 * V_440 , struct V_434 * V_441 )
{
struct V_426 * V_427 = V_441 -> V_429 ;
F_164 ( V_427 ) ;
return 0 ;
}
static long F_165 ( struct V_68 * V_68 ,
struct V_442 * V_73 )
{
long V_443 ;
struct V_426 * V_427 ;
if ( ! F_20 ( V_444 ) ||
! F_20 ( V_445 ) )
return - V_36 ;
if ( ! V_431 )
return - V_36 ;
V_427 = F_166 () ;
if ( ! V_427 )
return - V_342 ;
V_443 = F_167 ( L_17 , & V_446 , V_427 , V_447 | V_448 ) ;
if ( V_443 < 0 )
F_164 ( V_427 ) ;
V_73 -> V_420 = V_431 << V_449 ;
return V_443 ;
}
static void F_168 ( struct V_450 * * V_451 ,
int V_452 )
{
struct V_453 * V_454 = & V_455 [ V_452 ] ;
if ( ! V_454 -> V_456 )
return;
( * V_451 ) -> V_457 = V_454 -> V_456 ;
( * V_451 ) -> V_458 = V_454 -> V_459 ;
( * V_451 ) -> V_460 [ 0 ] . V_457 = V_454 -> V_456 ;
( * V_451 ) -> V_460 [ 0 ] . V_461 = V_454 -> V_462 [ V_452 ] ;
if ( V_452 != V_463 && V_454 -> V_462 [ V_463 ] != - 1 ) {
( * V_451 ) -> V_460 [ 1 ] . V_457 = 24 ;
( * V_451 ) -> V_460 [ 1 ] . V_461 = V_454 -> V_462 [ V_463 ] ;
}
( * V_451 ) ++ ;
}
static int F_169 ( struct V_68 * V_68 ,
struct V_464 * V_465 )
{
struct V_450 * V_451 ;
V_465 -> V_18 = V_466 ;
if ( F_170 ( V_467 ) )
V_465 -> V_18 |= V_468 ;
V_465 -> V_469 = V_470 ;
V_451 = & V_465 -> V_451 [ 0 ] ;
F_168 ( & V_451 , V_471 ) ;
F_168 ( & V_451 , V_472 ) ;
F_168 ( & V_451 , V_463 ) ;
return 0 ;
}
static int F_171 ( struct V_68 * V_68 ,
struct V_473 * log )
{
struct V_474 * V_475 ;
int V_45 ;
unsigned long V_476 ;
F_27 ( & V_68 -> V_477 ) ;
V_45 = - V_36 ;
if ( log -> V_478 >= V_479 )
goto V_341;
V_475 = F_172 ( V_68 -> V_480 , log -> V_478 ) ;
V_45 = - V_167 ;
if ( ! V_475 -> V_481 )
goto V_341;
V_476 = F_173 ( V_475 ) ;
memset ( V_475 -> V_481 , 0 , V_476 ) ;
V_45 = F_174 ( V_68 , V_475 , V_475 -> V_481 ) ;
if ( V_45 )
goto V_341;
V_45 = - V_482 ;
if ( F_175 ( log -> V_481 , V_475 -> V_481 , V_476 ) )
goto V_341;
V_45 = 0 ;
V_341:
F_29 ( & V_68 -> V_477 ) ;
return V_45 ;
}
static void F_176 ( struct V_474 * V_475 )
{
unsigned long * V_483 ;
unsigned long V_215 , V_484 , V_485 ;
struct V_425 * V_425 ;
V_483 = V_475 -> V_10 . V_486 ;
V_484 = V_475 -> V_484 ;
if ( ! V_483 )
return;
for ( V_215 = 0 ; V_215 < V_484 ; V_215 ++ ) {
if ( ! ( V_483 [ V_215 ] & V_487 ) )
continue;
V_485 = V_483 [ V_215 ] >> V_449 ;
V_425 = F_160 ( V_485 ) ;
F_177 ( V_425 ) ;
F_178 ( V_425 ) ;
}
}
static void F_179 ( struct V_474 * free ,
struct V_474 * V_488 )
{
if ( ! V_488 || free -> V_10 . V_489 != V_488 -> V_10 . V_489 ) {
F_180 ( free -> V_10 . V_489 ) ;
free -> V_10 . V_489 = NULL ;
}
if ( ! V_488 || free -> V_10 . V_486 != V_488 -> V_10 . V_486 ) {
F_176 ( free ) ;
F_180 ( free -> V_10 . V_486 ) ;
free -> V_10 . V_486 = NULL ;
}
}
static int F_181 ( struct V_474 * V_478 ,
unsigned long V_484 )
{
V_478 -> V_10 . V_489 = F_182 ( V_484 * sizeof( * V_478 -> V_10 . V_489 ) ) ;
if ( ! V_478 -> V_10 . V_489 )
return - V_342 ;
V_478 -> V_10 . V_486 = NULL ;
return 0 ;
}
static int F_183 ( struct V_68 * V_68 ,
struct V_474 * V_475 ,
struct V_490 * V_491 )
{
unsigned long * V_492 ;
V_492 = V_475 -> V_10 . V_486 ;
if ( ! V_68 -> V_10 . V_493 && ! V_492 && V_475 -> V_484 ) {
V_492 = F_182 ( V_475 -> V_484 * sizeof( unsigned long ) ) ;
if ( ! V_492 )
return - V_342 ;
V_475 -> V_10 . V_486 = V_492 ;
}
return 0 ;
}
static void F_184 ( struct V_68 * V_68 ,
struct V_490 * V_491 ,
const struct V_474 * V_494 )
{
unsigned long V_484 = V_491 -> V_495 >> V_449 ;
struct V_474 * V_475 ;
if ( V_484 && V_494 -> V_484 ) {
V_475 = F_172 ( V_68 -> V_480 , V_491 -> V_478 ) ;
F_174 ( V_68 , V_475 , NULL ) ;
}
}
void F_185 ( struct V_68 * V_68 , unsigned long V_67 , unsigned long V_220 )
{
long int V_195 ;
T_3 V_496 = 0 ;
if ( ( V_68 -> V_10 . V_67 & V_220 ) == V_67 )
return;
V_68 -> V_10 . V_67 = ( V_68 -> V_10 . V_67 & ~ V_220 ) | V_67 ;
for ( V_195 = 0 ; V_195 < V_340 ; ++ V_195 ) {
struct V_15 * V_16 = V_68 -> V_10 . V_355 [ V_195 ] ;
if ( ! V_16 )
continue;
F_21 ( & V_16 -> V_44 ) ;
V_16 -> V_67 = ( V_16 -> V_67 & ~ V_220 ) | V_67 ;
F_22 ( & V_16 -> V_44 ) ;
if ( ++ V_496 >= V_68 -> V_10 . V_356 )
break;
}
}
static void F_186 ( struct V_1 * V_2 )
{
return;
}
static int F_152 ( struct V_1 * V_2 )
{
int V_92 = 0 ;
struct V_68 * V_68 = V_2 -> V_68 ;
struct V_426 * V_427 = NULL ;
unsigned long V_497 ;
struct V_474 * V_475 ;
struct V_421 * V_422 ;
unsigned long V_67 = 0 , V_498 ;
unsigned long V_499 = 0 ;
unsigned long V_500 , V_501 ;
unsigned long V_420 ;
unsigned long V_502 ;
unsigned long * V_483 ;
unsigned long V_195 , V_484 ;
int V_392 ;
F_27 ( & V_68 -> V_44 ) ;
if ( V_68 -> V_10 . V_415 )
goto V_341;
if ( ! V_68 -> V_10 . V_503 ) {
V_92 = F_187 ( V_68 , NULL ) ;
if ( V_92 ) {
F_24 ( L_18 ) ;
goto V_341;
}
}
V_392 = F_53 ( & V_68 -> V_157 ) ;
V_475 = F_188 ( V_68 , 0 ) ;
V_92 = - V_36 ;
if ( ! V_475 || ( V_475 -> V_18 & V_504 ) )
goto V_505;
V_497 = V_475 -> V_506 ;
F_189 ( & V_119 -> V_417 -> V_507 ) ;
V_422 = F_190 ( V_119 -> V_417 , V_497 ) ;
if ( ! V_422 || V_422 -> V_508 > V_497 || ( V_422 -> V_435 & V_509 ) )
goto V_510;
V_500 = F_191 ( V_422 ) ;
V_501 = F_192 ( V_500 ) ;
if ( V_422 -> V_428 && V_422 -> V_428 -> V_511 == & V_446 &&
V_497 == V_422 -> V_508 )
V_427 = V_422 -> V_428 -> V_429 ;
F_193 ( & V_119 -> V_417 -> V_507 ) ;
if ( ! V_427 ) {
V_92 = - V_512 ;
if ( F_20 ( V_445 ) ) {
F_24 ( L_19 ) ;
goto V_505;
}
V_92 = - V_36 ;
if ( ! ( V_500 == 0x1000 || V_500 == 0x10000 ||
V_500 == 0x1000000 ) )
goto V_505;
V_498 = F_194 ( V_500 ) ;
V_68 -> V_10 . V_513 = V_498 | V_514 |
( V_515 << V_516 ) ;
V_499 = V_517 ;
V_67 = V_498 << ( V_518 - 4 ) ;
F_195 ( V_2 , V_475 , V_501 ) ;
} else {
V_420 = V_431 ;
if ( V_420 > V_475 -> V_484 )
V_420 = V_475 -> V_484 ;
V_420 <<= V_449 ;
V_502 = F_158 ( V_420 ) ;
V_92 = - V_36 ;
if ( ( long ) V_502 < 0 ) {
F_24 ( L_20 , V_420 ) ;
goto V_505;
}
F_151 ( & V_427 -> V_519 ) ;
V_68 -> V_10 . V_520 = V_427 ;
if ( F_20 ( V_445 ) ) {
V_499 = ( 1ul << V_521 ) |
( 3ul << V_522 ) | V_523 ;
V_67 = ( ( V_502 >> 2 ) << V_521 ) |
( ( V_502 & 3 ) << V_522 ) ;
V_67 |= ( ( V_427 -> V_433 >> ( 26 - V_449 ) ) & 0xffff )
<< V_524 ;
} else {
V_499 = V_525 | V_526 | V_527 ;
V_67 = V_502 << V_528 ;
V_68 -> V_10 . V_529 = V_427 -> V_433 << V_449 ;
}
F_196 ( L_21 ,
V_427 -> V_433 << V_449 , V_420 , V_67 ) ;
V_484 = V_431 ;
V_501 = F_192 ( V_484 ) ;
V_483 = V_475 -> V_10 . V_486 ;
if ( V_483 ) {
if ( V_484 > V_475 -> V_484 )
V_484 = V_475 -> V_484 ;
F_21 ( & V_68 -> V_10 . V_530 ) ;
for ( V_195 = 0 ; V_195 < V_484 ; ++ V_195 )
V_483 [ V_195 ] = ( ( V_427 -> V_433 + V_195 ) << V_449 ) +
V_501 ;
F_22 ( & V_68 -> V_10 . V_530 ) ;
}
}
F_185 ( V_68 , V_67 , V_499 ) ;
F_48 () ;
V_68 -> V_10 . V_415 = 1 ;
V_92 = 0 ;
V_505:
F_55 ( & V_68 -> V_157 , V_392 ) ;
V_341:
F_29 ( & V_68 -> V_44 ) ;
return V_92 ;
V_510:
F_193 ( & V_119 -> V_417 -> V_507 ) ;
goto V_505;
}
static int F_197 ( struct V_68 * V_68 )
{
unsigned long V_67 , V_531 ;
V_531 = F_198 () ;
if ( ( long ) V_531 < 0 )
return - V_342 ;
V_68 -> V_10 . V_531 = V_531 ;
F_199 ( & V_68 -> V_10 . V_532 ) ;
memcpy ( V_68 -> V_10 . V_154 , V_533 ,
sizeof( V_68 -> V_10 . V_154 ) ) ;
V_68 -> V_10 . V_520 = NULL ;
V_68 -> V_10 . V_534 = F_90 ( V_535 ) ;
if ( F_20 ( V_445 ) ) {
V_68 -> V_10 . V_536 = 0 ;
V_68 -> V_10 . V_537 = V_67 = F_90 ( V_538 ) ;
V_67 &= ~ ( ( 3 << V_539 ) | ( 0xful << V_540 ) ) ;
V_67 |= ( ( V_531 >> 4 ) << V_539 ) |
( ( V_531 & 0xf ) << V_540 ) ;
} else {
V_68 -> V_10 . V_536 = F_90 ( V_541 ) ;
V_68 -> V_10 . V_537 = V_67 = F_90 ( V_542 ) ;
V_67 &= V_543 | V_544 ;
V_67 |= ( 4UL << V_545 ) | V_546 |
V_525 | V_547 ;
V_68 -> V_10 . V_513 = V_514 |
( V_515 << V_516 ) ;
if ( F_20 ( V_43 ) )
V_67 |= V_548 ;
}
V_68 -> V_10 . V_67 = V_67 ;
V_68 -> V_10 . V_493 = ! ! F_20 ( V_35 ) ;
F_82 ( & V_68 -> V_10 . V_530 ) ;
F_200 () ;
return 0 ;
}
static void F_201 ( struct V_68 * V_68 )
{
long int V_195 ;
for ( V_195 = 0 ; V_195 < V_340 ; ++ V_195 ) {
if ( V_68 -> V_10 . V_355 [ V_195 ] && V_68 -> V_10 . V_355 [ V_195 ] -> V_337 ) {
struct V_15 * V_16 = V_68 -> V_10 . V_355 [ V_195 ] ;
F_202 ( ( unsigned long ) V_16 -> V_337 ,
V_339 ) ;
}
F_203 ( V_68 -> V_10 . V_355 [ V_195 ] ) ;
}
V_68 -> V_10 . V_356 = 0 ;
}
static void F_204 ( struct V_68 * V_68 )
{
F_205 () ;
F_201 ( V_68 ) ;
if ( V_68 -> V_10 . V_520 ) {
F_164 ( V_68 -> V_10 . V_520 ) ;
V_68 -> V_10 . V_520 = NULL ;
}
F_206 ( V_68 ) ;
}
static int F_207 ( struct V_178 * V_179 , struct V_1 * V_2 ,
unsigned int V_549 , int * V_550 )
{
return V_551 ;
}
static int F_208 ( struct V_1 * V_2 , int V_552 ,
T_4 V_553 )
{
return V_551 ;
}
static int F_209 ( struct V_1 * V_2 , int V_552 ,
T_4 * V_553 )
{
return V_551 ;
}
static int F_210 ( void )
{
if ( ! F_20 ( V_444 ) )
return - V_554 ;
return 0 ;
}
static long F_211 ( struct V_434 * V_441 ,
unsigned int V_555 , unsigned long V_556 )
{
struct V_68 * V_68 V_557 = V_441 -> V_429 ;
void T_6 * V_558 = ( void T_6 * ) V_556 ;
long V_45 ;
switch ( V_555 ) {
case V_559 : {
struct V_442 V_520 ;
struct V_68 * V_68 = V_441 -> V_429 ;
V_45 = F_165 ( V_68 , & V_520 ) ;
if ( V_45 >= 0 && F_175 ( V_558 , & V_520 , sizeof( V_520 ) ) )
V_45 = - V_482 ;
break;
}
case V_560 : {
T_3 V_561 ;
V_45 = - V_482 ;
if ( F_212 ( V_561 , ( T_3 T_6 * ) V_558 ) )
break;
V_45 = F_213 ( V_68 , & V_561 ) ;
if ( V_45 )
break;
V_45 = - V_482 ;
if ( F_214 ( V_561 , ( T_3 T_6 * ) V_558 ) )
break;
V_45 = 0 ;
break;
}
case V_562 : {
struct V_563 V_564 ;
V_45 = - V_482 ;
if ( F_215 ( & V_564 , V_558 , sizeof( V_564 ) ) )
break;
V_45 = F_216 ( V_68 , & V_564 ) ;
break;
}
default:
V_45 = - V_565 ;
}
return V_45 ;
}
static void F_217 ( void )
{
int V_195 ;
unsigned int V_566 ;
for ( V_195 = 0 ; V_567 [ V_195 ] ; ++ V_195 ) {
V_566 = V_567 [ V_195 ] ;
F_218 ( ! F_63 ( V_566 ) ) ;
F_219 ( V_566 / 4 , V_533 ) ;
}
}
static int F_220 ( void )
{
int V_45 ;
V_45 = F_210 () ;
if ( V_45 < 0 )
return - V_568 ;
V_569 . V_570 = V_571 ;
V_572 = & V_569 ;
F_217 () ;
V_45 = F_221 () ;
return V_45 ;
}
static void F_222 ( void )
{
V_572 = NULL ;
}
