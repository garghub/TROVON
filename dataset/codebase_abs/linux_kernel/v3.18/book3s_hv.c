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
static int F_66 ( struct V_178 * V_179 ,
struct V_1 * V_2 )
{
T_3 V_70 ;
if ( F_67 ( V_2 , V_180 , & V_70 ) !=
V_181 ) {
return V_176 ;
}
if ( V_70 == V_182 ) {
V_179 -> V_183 = V_184 ;
V_179 -> V_185 . V_10 . V_186 = F_47 ( V_2 ) ;
return V_155 ;
} else {
F_68 ( V_2 , V_187 ) ;
return V_176 ;
}
}
static int F_69 ( struct V_178 * V_179 , struct V_1 * V_2 ,
struct V_188 * V_189 )
{
int V_45 = V_155 ;
V_2 -> V_6 . V_190 ++ ;
V_179 -> V_183 = V_191 ;
V_179 -> V_192 = 1 ;
switch ( V_2 -> V_10 . V_48 ) {
case V_193 :
V_2 -> V_6 . V_194 ++ ;
V_45 = V_176 ;
break;
case V_195 :
case V_196 :
V_2 -> V_6 . V_197 ++ ;
V_45 = V_176 ;
break;
case V_198 :
V_45 = V_176 ;
break;
case V_199 :
F_70 ( V_2 ,
V_199 ) ;
V_45 = V_176 ;
break;
case V_200 :
{
T_4 V_18 ;
V_18 = V_2 -> V_10 . V_31 . V_30 & 0x1f0000ull ;
F_68 ( V_2 , V_18 ) ;
V_45 = V_176 ;
break;
}
case V_201 :
{
int V_202 ;
V_179 -> V_203 . V_204 = F_25 ( V_2 , 3 ) ;
for ( V_202 = 0 ; V_202 < 9 ; ++ V_202 )
V_179 -> V_203 . args [ V_202 ] = F_25 ( V_2 , 4 + V_202 ) ;
V_179 -> V_183 = V_205 ;
V_2 -> V_10 . V_175 = 1 ;
V_45 = V_155 ;
break;
}
case V_206 :
V_45 = V_207 ;
break;
case V_208 :
V_2 -> V_10 . V_61 = F_47 ( V_2 ) ;
V_2 -> V_10 . V_62 = 0 ;
V_45 = V_207 ;
break;
case V_209 :
if ( V_2 -> V_210 & V_211 ) {
V_45 = F_66 ( V_179 , V_2 ) ;
} else {
F_68 ( V_2 , V_187 ) ;
V_45 = V_176 ;
}
break;
case V_212 :
F_68 ( V_2 , V_187 ) ;
V_45 = V_176 ;
break;
default:
F_23 ( V_2 ) ;
F_71 ( V_213 L_14 ,
V_2 -> V_10 . V_48 , F_47 ( V_2 ) ,
V_2 -> V_10 . V_31 . V_30 ) ;
V_179 -> V_214 . V_215 = V_2 -> V_10 . V_48 ;
V_45 = V_155 ;
break;
}
return V_45 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_216 * V_217 )
{
int V_202 ;
memset ( V_217 , 0 , sizeof( struct V_216 ) ) ;
V_217 -> V_32 = V_2 -> V_10 . V_32 ;
for ( V_202 = 0 ; V_202 < V_2 -> V_10 . V_63 ; V_202 ++ ) {
V_217 -> V_218 . V_219 . V_220 . V_64 [ V_202 ] . V_221 = V_2 -> V_10 . V_64 [ V_202 ] . V_65 ;
V_217 -> V_218 . V_219 . V_220 . V_64 [ V_202 ] . V_222 = V_2 -> V_10 . V_64 [ V_202 ] . V_66 ;
}
return 0 ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_216 * V_217 )
{
int V_202 , V_223 ;
if ( V_217 -> V_32 != V_2 -> V_10 . V_32 )
return - V_36 ;
V_223 = 0 ;
for ( V_202 = 0 ; V_202 < V_2 -> V_10 . V_224 ; V_202 ++ ) {
if ( V_217 -> V_218 . V_219 . V_220 . V_64 [ V_202 ] . V_221 & V_225 ) {
V_2 -> V_10 . V_64 [ V_223 ] . V_65 = V_217 -> V_218 . V_219 . V_220 . V_64 [ V_202 ] . V_221 ;
V_2 -> V_10 . V_64 [ V_223 ] . V_66 = V_217 -> V_218 . V_219 . V_220 . V_64 [ V_202 ] . V_222 ;
++ V_223 ;
}
}
V_2 -> V_10 . V_63 = V_223 ;
return 0 ;
}
static void F_74 ( struct V_1 * V_2 , T_2 V_226 ,
bool V_227 )
{
struct V_15 * V_16 = V_2 -> V_10 . V_17 ;
T_2 V_228 ;
F_21 ( & V_16 -> V_44 ) ;
if ( ( V_226 & V_229 ) != ( V_16 -> V_67 & V_229 ) ) {
struct V_68 * V_68 = V_2 -> V_68 ;
struct V_1 * V_2 ;
int V_202 ;
F_27 ( & V_68 -> V_44 ) ;
F_28 (i, vcpu, kvm) {
if ( V_2 -> V_10 . V_17 != V_16 )
continue;
if ( V_226 & V_229 )
V_2 -> V_10 . V_230 |= V_231 ;
else
V_2 -> V_10 . V_230 &= ~ V_231 ;
}
F_29 ( & V_68 -> V_44 ) ;
}
V_228 = V_232 | V_229 | V_233 ;
if ( F_20 ( V_43 ) )
V_228 |= V_234 ;
if ( V_227 )
V_228 &= 0xFFFFFFFF ;
V_16 -> V_67 = ( V_16 -> V_67 & ~ V_228 ) | ( V_226 & V_228 ) ;
F_22 ( & V_16 -> V_44 ) ;
}
static int F_75 ( struct V_1 * V_2 , T_2 V_71 ,
union V_235 * V_236 )
{
int V_45 = 0 ;
long int V_202 ;
switch ( V_71 ) {
case V_237 :
* V_236 = F_76 ( V_71 , V_182 ) ;
break;
case V_238 :
* V_236 = F_76 ( V_71 , 0 ) ;
break;
case V_239 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_240 ) ;
break;
case V_241 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_242 ) ;
break;
case V_243 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_244 ) ;
break;
case V_245 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_246 ) ;
break;
case V_247 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_248 ) ;
break;
case V_249 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_250 ) ;
break;
case V_251 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_252 ) ;
break;
case V_253 ... V_254 :
V_202 = V_71 - V_253 ;
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_255 [ V_202 ] ) ;
break;
case V_256 ... V_257 :
V_202 = V_71 - V_256 ;
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_258 [ V_202 ] ) ;
break;
case V_259 ... V_260 :
V_202 = V_71 - V_259 ;
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_261 [ V_202 ] ) ;
break;
case V_262 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_263 ) ;
break;
case V_264 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_265 ) ;
break;
case V_266 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_267 ) ;
break;
case V_268 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_269 ) ;
break;
case V_270 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_271 ) ;
break;
case V_272 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_17 -> V_273 ) ;
break;
case V_274 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_146 ) ;
break;
case V_275 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_147 ) ;
break;
case V_276 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_142 ) ;
break;
case V_277 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_278 ) ;
break;
case V_279 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_280 ) ;
break;
case V_281 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_282 ) ;
break;
case V_283 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_284 ) ;
break;
case V_285 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_286 ) ;
break;
case V_287 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_288 ) ;
break;
case V_289 :
F_21 ( & V_2 -> V_10 . V_83 ) ;
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_75 . V_84 ) ;
F_22 ( & V_2 -> V_10 . V_83 ) ;
break;
case V_290 :
F_21 ( & V_2 -> V_10 . V_83 ) ;
V_236 -> V_291 . V_80 = V_2 -> V_10 . V_107 . V_84 ;
V_236 -> V_291 . V_101 = V_2 -> V_10 . V_107 . V_81 ;
F_22 ( & V_2 -> V_10 . V_83 ) ;
break;
case V_292 :
F_21 ( & V_2 -> V_10 . V_83 ) ;
V_236 -> V_291 . V_80 = V_2 -> V_10 . V_106 . V_84 ;
V_236 -> V_291 . V_101 = V_2 -> V_10 . V_106 . V_81 ;
F_22 ( & V_2 -> V_10 . V_83 ) ;
break;
case V_293 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_17 -> V_128 ) ;
break;
case V_294 :
case V_295 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_17 -> V_67 ) ;
break;
case V_296 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_297 ) ;
break;
#ifdef F_77
case V_298 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_299 ) ;
break;
case V_300 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_301 ) ;
break;
case V_302 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_303 ) ;
break;
case V_304 ... V_305 :
V_202 = V_71 - V_304 ;
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_306 [ V_202 ] ) ;
break;
case V_307 ... V_308 :
{
int V_223 ;
V_202 = V_71 - V_307 ;
if ( V_202 < 32 )
for ( V_223 = 0 ; V_223 < V_309 ; V_223 ++ )
V_236 -> V_310 [ V_223 ] = V_2 -> V_10 . V_311 . V_312 [ V_202 ] [ V_223 ] ;
else {
if ( F_20 ( V_313 ) )
V_236 -> V_314 = V_2 -> V_10 . V_315 . V_316 [ V_202 - 32 ] ;
else
V_45 = - V_317 ;
}
break;
}
case V_318 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_319 ) ;
break;
case V_320 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_321 ) ;
break;
case V_322 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_323 ) ;
break;
case V_324 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_311 . V_325 ) ;
break;
case V_326 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_327 ) ;
break;
case V_328 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_329 ) ;
break;
case V_330 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_331 ) ;
break;
case V_332 :
if ( F_20 ( V_313 ) )
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_315 . V_333 . V_218 [ 3 ] ) ;
else
V_45 = - V_317 ;
break;
case V_334 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_335 ) ;
break;
case V_336 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_337 ) ;
break;
#endif
case V_338 :
* V_236 = F_76 ( V_71 , V_2 -> V_10 . V_17 -> V_33 ) ;
break;
default:
V_45 = - V_36 ;
break;
}
return V_45 ;
}
static int F_78 ( struct V_1 * V_2 , T_2 V_71 ,
union V_235 * V_236 )
{
int V_45 = 0 ;
long int V_202 ;
unsigned long V_80 , V_81 ;
switch ( V_71 ) {
case V_238 :
if ( F_79 ( V_71 , * V_236 ) )
V_45 = - V_36 ;
break;
case V_239 :
V_2 -> V_10 . V_240 = F_79 ( V_71 , * V_236 ) ;
break;
case V_241 :
V_2 -> V_10 . V_242 = F_79 ( V_71 , * V_236 ) & ~ V_145 ;
break;
case V_243 :
V_2 -> V_10 . V_244 = F_79 ( V_71 , * V_236 ) ;
break;
case V_245 :
V_2 -> V_10 . V_246 = F_79 ( V_71 , * V_236 ) ;
break;
case V_247 :
V_2 -> V_10 . V_248 = F_79 ( V_71 , * V_236 ) ;
break;
case V_249 :
V_2 -> V_10 . V_250 = F_79 ( V_71 , * V_236 ) ;
break;
case V_251 :
V_2 -> V_10 . V_252 = F_79 ( V_71 , * V_236 ) ;
break;
case V_253 ... V_254 :
V_202 = V_71 - V_253 ;
V_2 -> V_10 . V_255 [ V_202 ] = F_79 ( V_71 , * V_236 ) ;
break;
case V_256 ... V_257 :
V_202 = V_71 - V_256 ;
V_2 -> V_10 . V_258 [ V_202 ] = F_79 ( V_71 , * V_236 ) ;
break;
case V_259 ... V_260 :
V_202 = V_71 - V_259 ;
V_2 -> V_10 . V_261 [ V_202 ] = F_79 ( V_71 , * V_236 ) ;
break;
case V_262 :
V_2 -> V_10 . V_263 = F_79 ( V_71 , * V_236 ) ;
break;
case V_264 :
V_2 -> V_10 . V_265 = F_79 ( V_71 , * V_236 ) ;
break;
case V_266 :
V_2 -> V_10 . V_267 = F_79 ( V_71 , * V_236 ) ;
break;
case V_268 :
V_2 -> V_10 . V_269 = F_79 ( V_71 , * V_236 ) ;
break;
case V_270 :
V_2 -> V_10 . V_271 = F_79 ( V_71 , * V_236 ) ;
break;
case V_272 :
V_2 -> V_10 . V_17 -> V_273 = F_79 ( V_71 , * V_236 ) ;
break;
case V_274 :
V_2 -> V_10 . V_146 = F_79 ( V_71 , * V_236 ) ;
break;
case V_275 :
V_2 -> V_10 . V_147 = F_79 ( V_71 , * V_236 ) & ~ V_339 ;
break;
case V_276 :
V_2 -> V_10 . V_142 = F_79 ( V_71 , * V_236 ) ;
if ( ( V_2 -> V_10 . V_142 & V_139 ) == V_140 )
V_2 -> V_10 . V_142 &= ~ V_139 ;
break;
case V_277 :
V_2 -> V_10 . V_278 = F_79 ( V_71 , * V_236 ) ;
break;
case V_279 :
V_2 -> V_10 . V_280 = F_79 ( V_71 , * V_236 ) ;
break;
case V_281 :
V_2 -> V_10 . V_282 = F_79 ( V_71 , * V_236 ) ;
break;
case V_283 :
V_2 -> V_10 . V_284 = F_79 ( V_71 , * V_236 ) ;
break;
case V_285 :
V_2 -> V_10 . V_286 = F_79 ( V_71 , * V_236 ) ;
break;
case V_287 :
V_2 -> V_10 . V_288 = F_79 ( V_71 , * V_236 ) ;
break;
case V_289 :
V_80 = F_79 ( V_71 , * V_236 ) ;
V_45 = - V_36 ;
if ( ! V_80 && ( V_2 -> V_10 . V_107 . V_84 ||
V_2 -> V_10 . V_106 . V_84 ) )
break;
V_45 = F_32 ( V_2 , & V_2 -> V_10 . V_75 , V_80 , sizeof( struct V_74 ) ) ;
break;
case V_290 :
V_80 = V_236 -> V_291 . V_80 ;
V_81 = V_236 -> V_291 . V_101 ;
V_45 = - V_36 ;
if ( V_80 && ! V_2 -> V_10 . V_75 . V_84 )
break;
V_45 = F_32 ( V_2 , & V_2 -> V_10 . V_107 , V_80 , V_81 ) ;
break;
case V_292 :
V_80 = V_236 -> V_291 . V_80 ;
V_81 = V_236 -> V_291 . V_101 ;
V_45 = - V_36 ;
if ( V_80 && ( V_81 < sizeof( struct V_104 ) ||
! V_2 -> V_10 . V_75 . V_84 ) )
break;
V_81 -= V_81 % sizeof( struct V_104 ) ;
V_45 = F_32 ( V_2 , & V_2 -> V_10 . V_106 , V_80 , V_81 ) ;
break;
case V_293 :
V_2 -> V_10 . V_17 -> V_128 =
F_80 ( F_79 ( V_71 , * V_236 ) , 1UL << 24 ) ;
break;
case V_294 :
F_74 ( V_2 , F_79 ( V_71 , * V_236 ) , true ) ;
break;
case V_295 :
F_74 ( V_2 , F_79 ( V_71 , * V_236 ) , false ) ;
break;
case V_296 :
V_2 -> V_10 . V_297 = F_79 ( V_71 , * V_236 ) ;
break;
#ifdef F_77
case V_298 :
V_2 -> V_10 . V_299 = F_79 ( V_71 , * V_236 ) ;
break;
case V_300 :
V_2 -> V_10 . V_301 = F_79 ( V_71 , * V_236 ) ;
break;
case V_302 :
V_2 -> V_10 . V_303 = F_79 ( V_71 , * V_236 ) ;
break;
case V_304 ... V_305 :
V_202 = V_71 - V_304 ;
V_2 -> V_10 . V_306 [ V_202 ] = F_79 ( V_71 , * V_236 ) ;
break;
case V_307 ... V_308 :
{
int V_223 ;
V_202 = V_71 - V_307 ;
if ( V_202 < 32 )
for ( V_223 = 0 ; V_223 < V_309 ; V_223 ++ )
V_2 -> V_10 . V_311 . V_312 [ V_202 ] [ V_223 ] = V_236 -> V_310 [ V_223 ] ;
else
if ( F_20 ( V_313 ) )
V_2 -> V_10 . V_315 . V_316 [ V_202 - 32 ] = V_236 -> V_314 ;
else
V_45 = - V_317 ;
break;
}
case V_318 :
V_2 -> V_10 . V_319 = F_79 ( V_71 , * V_236 ) ;
break;
case V_320 :
V_2 -> V_10 . V_321 = F_79 ( V_71 , * V_236 ) ;
break;
case V_322 :
V_2 -> V_10 . V_323 = F_79 ( V_71 , * V_236 ) ;
break;
case V_324 :
V_2 -> V_10 . V_311 . V_325 = F_79 ( V_71 , * V_236 ) ;
break;
case V_326 :
V_2 -> V_10 . V_327 = F_79 ( V_71 , * V_236 ) ;
break;
case V_328 :
V_2 -> V_10 . V_329 = F_79 ( V_71 , * V_236 ) ;
break;
case V_330 :
V_2 -> V_10 . V_331 = F_79 ( V_71 , * V_236 ) ;
break;
case V_332 :
if ( F_20 ( V_313 ) )
V_2 -> V_10 . V_316 . V_333 . V_218 [ 3 ] = F_79 ( V_71 , * V_236 ) ;
else
V_45 = - V_317 ;
break;
case V_334 :
V_2 -> V_10 . V_335 = F_79 ( V_71 , * V_236 ) ;
break;
case V_336 :
V_2 -> V_10 . V_337 = F_79 ( V_71 , * V_236 ) ;
break;
#endif
case V_338 :
V_45 = F_19 ( V_2 , F_79 ( V_71 , * V_236 ) ) ;
break;
default:
V_45 = - V_36 ;
break;
}
return V_45 ;
}
static struct V_15 * F_81 ( struct V_68 * V_68 , int V_340 )
{
struct V_15 * V_17 ;
V_17 = F_82 ( sizeof( struct V_15 ) , V_341 ) ;
if ( V_17 == NULL )
return NULL ;
F_83 ( & V_17 -> V_342 ) ;
F_84 ( & V_17 -> V_44 ) ;
F_85 ( & V_17 -> V_162 ) ;
V_17 -> V_23 = V_24 ;
V_17 -> V_67 = V_68 -> V_10 . V_67 ;
V_17 -> V_343 = V_340 * V_344 ;
V_17 -> V_68 = V_68 ;
V_17 -> V_345 = false ;
if ( F_20 ( V_43 ) )
V_17 -> V_346 = ( void * ) F_86 (
V_341 | V_347 ,
V_348 ) ;
return V_17 ;
}
static struct V_1 * F_87 ( struct V_68 * V_68 ,
unsigned int V_71 )
{
struct V_1 * V_2 ;
int V_92 = - V_36 ;
int V_340 ;
struct V_15 * V_17 ;
V_340 = V_71 / V_344 ;
if ( V_340 >= V_349 )
goto V_350;
V_92 = - V_351 ;
V_2 = F_88 ( V_352 , V_341 ) ;
if ( ! V_2 )
goto V_350;
V_92 = F_89 ( V_2 , V_68 , V_71 ) ;
if ( V_92 )
goto V_353;
V_2 -> V_10 . V_354 = & V_2 -> V_10 . V_31 ;
#ifdef F_90
#ifdef F_91
V_2 -> V_10 . V_355 = true ;
#else
V_2 -> V_10 . V_355 = false ;
#endif
#endif
V_2 -> V_10 . V_255 [ 0 ] = V_356 ;
V_2 -> V_10 . V_357 = V_358 ;
F_18 ( V_2 , F_92 ( V_359 ) ) ;
F_84 ( & V_2 -> V_10 . V_83 ) ;
F_84 ( & V_2 -> V_10 . V_19 ) ;
V_2 -> V_10 . V_28 = V_24 ;
V_2 -> V_10 . V_230 = V_360 | V_361 ;
F_93 ( V_2 ) ;
V_2 -> V_10 . V_26 = V_362 ;
F_85 ( & V_2 -> V_10 . V_363 ) ;
F_27 ( & V_68 -> V_44 ) ;
V_17 = V_68 -> V_10 . V_364 [ V_340 ] ;
if ( ! V_17 ) {
V_17 = F_81 ( V_68 , V_340 ) ;
V_68 -> V_10 . V_364 [ V_340 ] = V_17 ;
V_68 -> V_10 . V_365 ++ ;
}
F_29 ( & V_68 -> V_44 ) ;
if ( ! V_17 )
goto V_353;
F_21 ( & V_17 -> V_44 ) ;
++ V_17 -> V_366 ;
F_22 ( & V_17 -> V_44 ) ;
V_2 -> V_10 . V_17 = V_17 ;
V_2 -> V_10 . V_11 = V_2 -> V_46 - V_17 -> V_343 ;
V_2 -> V_10 . V_367 = V_368 ;
F_94 ( V_2 ) ;
return V_2 ;
V_353:
F_95 ( V_352 , V_2 ) ;
V_350:
return F_96 ( V_92 ) ;
}
static void F_97 ( struct V_68 * V_68 , struct V_79 * V_75 )
{
if ( V_75 -> V_87 )
F_38 ( V_68 , V_75 -> V_87 , V_75 -> V_111 ,
V_75 -> V_112 ) ;
}
static void F_98 ( struct V_1 * V_2 )
{
F_21 ( & V_2 -> V_10 . V_83 ) ;
F_97 ( V_2 -> V_68 , & V_2 -> V_10 . V_106 ) ;
F_97 ( V_2 -> V_68 , & V_2 -> V_10 . V_107 ) ;
F_97 ( V_2 -> V_68 , & V_2 -> V_10 . V_75 ) ;
F_22 ( & V_2 -> V_10 . V_83 ) ;
F_99 ( V_2 ) ;
F_95 ( V_352 , V_2 ) ;
}
static int F_100 ( struct V_1 * V_2 )
{
return 1 ;
}
static void F_101 ( struct V_1 * V_2 )
{
unsigned long V_369 , V_116 ;
V_116 = F_102 () ;
if ( V_116 > V_2 -> V_10 . V_370 ) {
F_103 ( V_2 ) ;
F_104 ( V_2 ) ;
return;
}
V_369 = ( V_2 -> V_10 . V_370 - V_116 ) * V_371
/ V_372 ;
F_105 ( & V_2 -> V_10 . V_373 , F_106 ( 0 , V_369 ) ,
V_374 ) ;
V_2 -> V_10 . V_375 = 1 ;
}
static void F_17 ( struct V_1 * V_2 )
{
V_2 -> V_10 . V_161 = 0 ;
if ( V_2 -> V_10 . V_375 ) {
F_107 ( & V_2 -> V_10 . V_373 ) ;
V_2 -> V_10 . V_375 = 0 ;
}
}
static void F_108 ( struct V_15 * V_16 ,
struct V_1 * V_2 )
{
T_2 V_116 ;
if ( V_2 -> V_10 . V_26 != V_376 )
return;
F_42 ( & V_2 -> V_10 . V_19 ) ;
V_116 = F_13 () ;
V_2 -> V_10 . V_29 += F_41 ( V_16 , V_116 ) -
V_2 -> V_10 . V_123 ;
V_2 -> V_10 . V_28 = V_116 ;
V_2 -> V_10 . V_26 = V_27 ;
F_43 ( & V_2 -> V_10 . V_19 ) ;
-- V_16 -> V_377 ;
F_109 ( & V_2 -> V_10 . V_378 ) ;
}
static int F_110 ( int V_4 )
{
struct V_379 * V_380 ;
long V_381 = 10000 ;
V_380 = & V_12 [ V_4 ] ;
V_380 -> V_13 . V_382 = 1 ;
V_380 -> V_13 . V_1 = NULL ;
F_56 () ;
while ( V_380 -> V_13 . V_383 == V_384 ) {
if ( -- V_381 <= 0 ) {
F_24 ( L_15 , V_4 ) ;
return - V_385 ;
}
F_111 ( 1 ) ;
}
return 0 ;
}
static void F_112 ( int V_4 )
{
struct V_379 * V_380 ;
V_380 = & V_12 [ V_4 ] ;
V_380 -> V_13 . V_382 = 0 ;
V_380 -> V_13 . V_1 = NULL ;
}
static void F_113 ( struct V_1 * V_2 )
{
int V_4 ;
struct V_379 * V_380 ;
struct V_15 * V_16 = V_2 -> V_10 . V_17 ;
if ( V_2 -> V_10 . V_375 ) {
F_107 ( & V_2 -> V_10 . V_373 ) ;
V_2 -> V_10 . V_375 = 0 ;
}
V_4 = V_16 -> V_126 + V_2 -> V_10 . V_11 ;
V_380 = & V_12 [ V_4 ] ;
V_380 -> V_13 . V_1 = V_2 ;
V_380 -> V_13 . V_386 = V_16 ;
V_380 -> V_13 . V_11 = V_2 -> V_10 . V_11 ;
V_2 -> V_4 = V_16 -> V_126 ;
F_48 () ;
#if F_114 ( F_6 ) && F_114 ( V_387 )
if ( V_4 != F_115 () ) {
F_7 ( V_4 ) ;
if ( V_2 -> V_10 . V_11 )
++ V_16 -> V_388 ;
}
#endif
}
static void F_116 ( struct V_15 * V_16 )
{
int V_202 ;
F_117 () ;
V_202 = 0 ;
while ( V_16 -> V_389 < V_16 -> V_388 ) {
if ( ++ V_202 >= 1000000 ) {
F_24 ( L_16 ,
V_16 -> V_389 , V_16 -> V_388 ) ;
break;
}
F_118 () ;
}
F_119 () ;
}
static int F_120 ( void )
{
int V_4 = F_115 () ;
int V_390 ;
if ( F_121 ( V_4 ) )
return 0 ;
V_390 = 0 ;
while ( ++ V_390 < V_344 )
if ( F_8 ( V_4 + V_390 ) )
return 0 ;
for ( V_390 = 1 ; V_390 < V_344 ; ++ V_390 ) {
if ( F_110 ( V_4 + V_390 ) ) {
do {
F_112 ( V_4 + V_390 ) ;
} while ( -- V_390 > 0 );
return 0 ;
}
}
return 1 ;
}
static void F_122 ( struct V_15 * V_16 )
{
T_5 V_391 , V_392 ;
V_391 = ( T_5 ) F_123 ( V_16 -> V_346 ) ;
V_392 = V_391 & V_393 ;
F_124 ( V_394 , V_392 | V_395 ) ;
F_125 ( V_392 | V_396 ) ;
V_16 -> V_345 = true ;
}
static void F_126 ( const struct V_15 * V_16 )
{
T_5 V_391 , V_392 ;
V_391 = F_123 ( V_16 -> V_346 ) ;
V_392 = V_391 & V_393 ;
F_125 ( V_392 | V_397 ) ;
F_124 ( V_394 , V_392 | V_398 ) ;
}
static void F_127 ( struct V_15 * V_16 )
{
struct V_1 * V_2 , * V_399 ;
long V_73 ;
T_2 V_116 ;
int V_202 , V_400 ;
int V_401 ;
struct V_1 * V_402 [ V_403 ] ;
V_400 = 0 ;
F_128 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( F_129 ( V_2 -> V_10 . V_118 ) )
return;
if ( V_2 -> V_10 . V_75 . V_85 ||
V_2 -> V_10 . V_107 . V_85 ||
V_2 -> V_10 . V_106 . V_85 )
V_402 [ V_400 ++ ] = V_2 ;
}
V_16 -> V_388 = 0 ;
V_16 -> V_389 = 0 ;
V_16 -> V_404 = 0 ;
V_16 -> V_21 = V_405 ;
V_16 -> V_406 = 0 ;
V_16 -> V_407 = 0 ;
if ( V_400 ) {
F_22 ( & V_16 -> V_44 ) ;
for ( V_202 = 0 ; V_202 < V_400 ; ++ V_202 )
F_40 ( V_402 [ V_202 ] ) ;
F_21 ( & V_16 -> V_44 ) ;
}
if ( ( V_403 > 1 ) &&
( ( V_16 -> V_366 > V_344 ) || ! F_120 () ) ) {
F_128 (vcpu, &vc->runnable_threads, arch.run_list)
V_2 -> V_10 . V_73 = - V_385 ;
goto V_350;
}
V_16 -> V_126 = F_115 () ;
F_128 (vcpu, &vc->runnable_threads, arch.run_list) {
F_113 ( V_2 ) ;
F_44 ( V_2 , V_16 ) ;
}
F_130 () -> V_13 . V_386 = V_16 ;
F_130 () -> V_13 . V_11 = 0 ;
V_16 -> V_21 = V_408 ;
F_131 () ;
F_22 ( & V_16 -> V_44 ) ;
F_132 () ;
V_401 = F_53 ( & V_16 -> V_68 -> V_157 ) ;
if ( V_16 -> V_345 )
F_126 ( V_16 ) ;
F_133 () ;
F_21 ( & V_16 -> V_44 ) ;
if ( V_16 -> V_346 )
F_122 ( V_16 ) ;
F_128 (vcpu, &vc->runnable_threads, arch.run_list)
V_2 -> V_4 = - 1 ;
if ( V_16 -> V_389 < V_16 -> V_388 )
F_116 ( V_16 ) ;
for ( V_202 = 0 ; V_202 < V_344 ; ++ V_202 )
F_112 ( V_16 -> V_126 + V_202 ) ;
V_16 -> V_21 = V_409 ;
F_22 ( & V_16 -> V_44 ) ;
F_55 ( & V_16 -> V_68 -> V_157 , V_401 ) ;
F_56 () ;
F_134 () ;
F_135 () ;
F_136 () ;
F_21 ( & V_16 -> V_44 ) ;
V_116 = F_102 () ;
F_128 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( V_116 < V_2 -> V_10 . V_370 &&
F_137 ( V_2 ) )
F_138 ( V_2 ) ;
V_73 = V_176 ;
if ( V_2 -> V_10 . V_48 )
V_73 = F_69 ( V_2 -> V_10 . V_178 , V_2 ,
V_2 -> V_10 . V_118 ) ;
V_2 -> V_10 . V_73 = V_73 ;
V_2 -> V_10 . V_48 = 0 ;
if ( V_2 -> V_10 . V_161 ) {
if ( ! F_139 ( V_73 ) )
F_17 ( V_2 ) ;
else
F_101 ( V_2 ) ;
}
}
V_350:
V_16 -> V_21 = V_22 ;
F_140 (vcpu, vnext, &vc->runnable_threads,
arch.run_list) {
if ( ! F_139 ( V_2 -> V_10 . V_73 ) ) {
F_108 ( V_16 , V_2 ) ;
F_141 ( & V_2 -> V_10 . V_363 ) ;
}
}
}
static void F_142 ( struct V_1 * V_2 , int V_410 )
{
F_143 ( V_411 ) ;
F_144 ( & V_2 -> V_10 . V_363 , & V_411 , V_410 ) ;
if ( V_2 -> V_10 . V_26 == V_376 )
F_145 () ;
F_146 ( & V_2 -> V_10 . V_363 , & V_411 ) ;
}
static void F_147 ( struct V_15 * V_16 )
{
F_143 ( V_411 ) ;
F_144 ( & V_16 -> V_162 , & V_411 , V_412 ) ;
V_16 -> V_21 = V_413 ;
F_22 ( & V_16 -> V_44 ) ;
F_145 () ;
F_146 ( & V_16 -> V_162 , & V_411 ) ;
F_21 ( & V_16 -> V_44 ) ;
V_16 -> V_21 = V_22 ;
}
static int F_148 ( struct V_178 * V_178 , struct V_1 * V_2 )
{
int V_414 ;
struct V_15 * V_16 ;
struct V_1 * V_72 , * V_415 ;
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
V_2 -> V_10 . V_26 = V_376 ;
V_2 -> V_10 . V_28 = V_24 ;
F_149 ( & V_2 -> V_10 . V_378 , & V_16 -> V_342 ) ;
++ V_16 -> V_377 ;
if ( ! F_129 ( V_119 ) ) {
if ( V_16 -> V_21 == V_408 &&
F_150 ( V_16 ) == 0 ) {
F_44 ( V_2 , V_16 ) ;
F_113 ( V_2 ) ;
} else if ( V_16 -> V_21 == V_413 ) {
F_141 ( & V_16 -> V_162 ) ;
}
}
while ( V_2 -> V_10 . V_26 == V_376 &&
! F_129 ( V_119 ) ) {
if ( V_16 -> V_21 != V_22 ) {
F_22 ( & V_16 -> V_44 ) ;
F_142 ( V_2 , V_412 ) ;
F_21 ( & V_16 -> V_44 ) ;
continue;
}
F_140 (v, vn, &vc->runnable_threads,
arch.run_list) {
F_104 ( V_72 ) ;
if ( F_129 ( V_72 -> V_10 . V_118 ) ) {
F_108 ( V_16 , V_72 ) ;
V_72 -> V_6 . V_416 ++ ;
V_72 -> V_10 . V_178 -> V_183 = V_417 ;
V_72 -> V_10 . V_73 = - V_418 ;
F_141 ( & V_72 -> V_10 . V_363 ) ;
}
}
if ( ! V_16 -> V_377 || V_2 -> V_10 . V_26 != V_376 )
break;
V_16 -> V_20 = V_2 ;
V_414 = 0 ;
F_128 (v, &vc->runnable_threads, arch.run_list) {
if ( ! V_72 -> V_10 . V_419 )
V_414 += V_72 -> V_10 . V_161 ;
else
V_72 -> V_10 . V_161 = 0 ;
}
if ( V_414 == V_16 -> V_377 )
F_147 ( V_16 ) ;
else
F_127 ( V_16 ) ;
V_16 -> V_20 = NULL ;
}
while ( V_2 -> V_10 . V_26 == V_376 &&
( V_16 -> V_21 == V_408 ||
V_16 -> V_21 == V_409 ) ) {
F_22 ( & V_16 -> V_44 ) ;
F_142 ( V_2 , V_420 ) ;
F_21 ( & V_16 -> V_44 ) ;
}
if ( V_2 -> V_10 . V_26 == V_376 ) {
F_108 ( V_16 , V_2 ) ;
V_2 -> V_6 . V_416 ++ ;
V_178 -> V_183 = V_417 ;
V_2 -> V_10 . V_73 = - V_418 ;
}
if ( V_16 -> V_377 && V_16 -> V_21 == V_22 ) {
V_72 = F_151 ( & V_16 -> V_342 ,
struct V_1 , V_10 . V_378 ) ;
F_141 ( & V_72 -> V_10 . V_363 ) ;
}
F_22 ( & V_16 -> V_44 ) ;
return V_2 -> V_10 . V_73 ;
}
static int F_152 ( struct V_178 * V_179 , struct V_1 * V_2 )
{
int V_45 ;
int V_401 ;
if ( ! V_2 -> V_10 . V_421 ) {
V_179 -> V_183 = V_422 ;
return - V_36 ;
}
F_104 ( V_2 ) ;
if ( F_129 ( V_119 ) ) {
V_179 -> V_183 = V_417 ;
return - V_418 ;
}
F_153 ( & V_2 -> V_68 -> V_10 . V_423 ) ;
F_56 () ;
if ( ! V_2 -> V_68 -> V_10 . V_424 ) {
V_45 = F_154 ( V_2 ) ;
if ( V_45 )
goto V_350;
}
F_155 ( V_119 ) ;
F_156 ( V_119 ) ;
F_157 ( V_119 ) ;
V_2 -> V_10 . V_5 = & V_2 -> V_10 . V_17 -> V_162 ;
V_2 -> V_10 . V_425 = V_119 -> V_426 -> V_427 ;
V_2 -> V_10 . V_26 = V_27 ;
do {
V_45 = F_148 ( V_179 , V_2 ) ;
if ( V_179 -> V_183 == V_205 &&
! ( V_2 -> V_10 . V_31 . V_30 & V_428 ) ) {
V_45 = F_51 ( V_2 ) ;
F_104 ( V_2 ) ;
} else if ( V_45 == V_207 ) {
V_401 = F_53 ( & V_2 -> V_68 -> V_157 ) ;
V_45 = F_158 ( V_179 , V_2 ,
V_2 -> V_10 . V_61 , V_2 -> V_10 . V_62 ) ;
F_55 ( & V_2 -> V_68 -> V_157 , V_401 ) ;
}
} while ( F_139 ( V_45 ) );
V_350:
V_2 -> V_10 . V_26 = V_362 ;
F_159 ( & V_2 -> V_68 -> V_10 . V_423 ) ;
return V_45 ;
}
static inline int F_160 ( unsigned long V_429 )
{
switch ( V_429 ) {
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
static int F_161 ( struct V_430 * V_431 , struct V_432 * V_433 )
{
struct V_434 * V_434 ;
struct V_435 * V_436 = V_431 -> V_437 -> V_438 ;
if ( V_433 -> V_439 >= V_440 )
return V_441 ;
V_434 = F_162 ( V_436 -> V_442 + V_433 -> V_439 ) ;
F_163 ( V_434 ) ;
V_433 -> V_434 = V_434 ;
return 0 ;
}
static int F_164 ( struct V_443 * V_443 , struct V_430 * V_431 )
{
V_431 -> V_444 |= V_445 | V_446 ;
V_431 -> V_447 = & V_448 ;
return 0 ;
}
static int F_165 ( struct V_449 * V_449 , struct V_443 * V_450 )
{
struct V_435 * V_436 = V_450 -> V_438 ;
F_166 ( V_436 ) ;
return 0 ;
}
static long F_167 ( struct V_68 * V_68 ,
struct V_451 * V_73 )
{
long V_452 ;
struct V_435 * V_436 ;
if ( ! F_20 ( V_453 ) ||
! F_20 ( V_454 ) )
return - V_36 ;
if ( ! V_440 )
return - V_36 ;
V_436 = F_168 () ;
if ( ! V_436 )
return - V_351 ;
V_452 = F_169 ( L_17 , & V_455 , V_436 , V_456 | V_457 ) ;
if ( V_452 < 0 )
F_166 ( V_436 ) ;
V_73 -> V_429 = V_440 << V_458 ;
return V_452 ;
}
static void F_170 ( struct V_459 * * V_460 ,
int V_461 )
{
struct V_462 * V_463 = & V_464 [ V_461 ] ;
if ( ! V_463 -> V_465 )
return;
( * V_460 ) -> V_466 = V_463 -> V_465 ;
( * V_460 ) -> V_467 = V_463 -> V_468 ;
( * V_460 ) -> V_469 [ 0 ] . V_466 = V_463 -> V_465 ;
( * V_460 ) -> V_469 [ 0 ] . V_470 = V_463 -> V_471 [ V_461 ] ;
if ( V_461 != V_472 && V_463 -> V_471 [ V_472 ] != - 1 ) {
( * V_460 ) -> V_469 [ 1 ] . V_466 = 24 ;
( * V_460 ) -> V_469 [ 1 ] . V_470 = V_463 -> V_471 [ V_472 ] ;
}
( * V_460 ) ++ ;
}
static int F_171 ( struct V_68 * V_68 ,
struct V_473 * V_474 )
{
struct V_459 * V_460 ;
V_474 -> V_18 = V_475 ;
if ( F_172 ( V_476 ) )
V_474 -> V_18 |= V_477 ;
V_474 -> V_478 = V_479 ;
V_460 = & V_474 -> V_460 [ 0 ] ;
F_170 ( & V_460 , V_480 ) ;
F_170 ( & V_460 , V_481 ) ;
F_170 ( & V_460 , V_472 ) ;
return 0 ;
}
static int F_173 ( struct V_68 * V_68 ,
struct V_482 * log )
{
struct V_483 * V_484 ;
int V_45 ;
unsigned long V_485 ;
F_27 ( & V_68 -> V_486 ) ;
V_45 = - V_36 ;
if ( log -> V_487 >= V_488 )
goto V_350;
V_484 = F_174 ( V_68 -> V_489 , log -> V_487 ) ;
V_45 = - V_167 ;
if ( ! V_484 -> V_490 )
goto V_350;
V_485 = F_175 ( V_484 ) ;
memset ( V_484 -> V_490 , 0 , V_485 ) ;
V_45 = F_176 ( V_68 , V_484 , V_484 -> V_490 ) ;
if ( V_45 )
goto V_350;
V_45 = - V_491 ;
if ( F_177 ( log -> V_490 , V_484 -> V_490 , V_485 ) )
goto V_350;
V_45 = 0 ;
V_350:
F_29 ( & V_68 -> V_486 ) ;
return V_45 ;
}
static void F_178 ( struct V_483 * V_484 )
{
unsigned long * V_492 ;
unsigned long V_223 , V_493 , V_494 ;
struct V_434 * V_434 ;
V_492 = V_484 -> V_10 . V_495 ;
V_493 = V_484 -> V_493 ;
if ( ! V_492 )
return;
for ( V_223 = 0 ; V_223 < V_493 ; V_223 ++ ) {
if ( ! ( V_492 [ V_223 ] & V_496 ) )
continue;
V_494 = V_492 [ V_223 ] >> V_458 ;
V_434 = F_162 ( V_494 ) ;
F_179 ( V_434 ) ;
F_180 ( V_434 ) ;
}
}
static void F_181 ( struct V_483 * free ,
struct V_483 * V_497 )
{
if ( ! V_497 || free -> V_10 . V_498 != V_497 -> V_10 . V_498 ) {
F_182 ( free -> V_10 . V_498 ) ;
free -> V_10 . V_498 = NULL ;
}
if ( ! V_497 || free -> V_10 . V_495 != V_497 -> V_10 . V_495 ) {
F_178 ( free ) ;
F_182 ( free -> V_10 . V_495 ) ;
free -> V_10 . V_495 = NULL ;
}
}
static int F_183 ( struct V_483 * V_487 ,
unsigned long V_493 )
{
V_487 -> V_10 . V_498 = F_184 ( V_493 * sizeof( * V_487 -> V_10 . V_498 ) ) ;
if ( ! V_487 -> V_10 . V_498 )
return - V_351 ;
V_487 -> V_10 . V_495 = NULL ;
return 0 ;
}
static int F_185 ( struct V_68 * V_68 ,
struct V_483 * V_484 ,
struct V_499 * V_500 )
{
unsigned long * V_501 ;
V_501 = V_484 -> V_10 . V_495 ;
if ( ! V_68 -> V_10 . V_502 && ! V_501 && V_484 -> V_493 ) {
V_501 = F_184 ( V_484 -> V_493 * sizeof( unsigned long ) ) ;
if ( ! V_501 )
return - V_351 ;
V_484 -> V_10 . V_495 = V_501 ;
}
return 0 ;
}
static void F_186 ( struct V_68 * V_68 ,
struct V_499 * V_500 ,
const struct V_483 * V_503 )
{
unsigned long V_493 = V_500 -> V_504 >> V_458 ;
struct V_483 * V_484 ;
if ( V_493 && V_503 -> V_493 ) {
V_484 = F_174 ( V_68 -> V_489 , V_500 -> V_487 ) ;
F_176 ( V_68 , V_484 , NULL ) ;
}
}
void F_187 ( struct V_68 * V_68 , unsigned long V_67 , unsigned long V_228 )
{
long int V_202 ;
T_3 V_505 = 0 ;
if ( ( V_68 -> V_10 . V_67 & V_228 ) == V_67 )
return;
V_68 -> V_10 . V_67 = ( V_68 -> V_10 . V_67 & ~ V_228 ) | V_67 ;
for ( V_202 = 0 ; V_202 < V_349 ; ++ V_202 ) {
struct V_15 * V_16 = V_68 -> V_10 . V_364 [ V_202 ] ;
if ( ! V_16 )
continue;
F_21 ( & V_16 -> V_44 ) ;
V_16 -> V_67 = ( V_16 -> V_67 & ~ V_228 ) | V_67 ;
F_22 ( & V_16 -> V_44 ) ;
if ( ++ V_505 >= V_68 -> V_10 . V_365 )
break;
}
}
static void F_188 ( struct V_1 * V_2 )
{
return;
}
static int F_154 ( struct V_1 * V_2 )
{
int V_92 = 0 ;
struct V_68 * V_68 = V_2 -> V_68 ;
struct V_435 * V_436 = NULL ;
unsigned long V_506 ;
struct V_483 * V_484 ;
struct V_430 * V_431 ;
unsigned long V_67 = 0 , V_507 ;
unsigned long V_508 = 0 ;
unsigned long V_509 , V_510 ;
unsigned long V_429 ;
unsigned long V_511 ;
unsigned long * V_492 ;
unsigned long V_202 , V_493 ;
int V_401 ;
F_27 ( & V_68 -> V_44 ) ;
if ( V_68 -> V_10 . V_424 )
goto V_350;
if ( ! V_68 -> V_10 . V_512 ) {
V_92 = F_189 ( V_68 , NULL ) ;
if ( V_92 ) {
F_24 ( L_18 ) ;
goto V_350;
}
}
V_401 = F_53 ( & V_68 -> V_157 ) ;
V_484 = F_190 ( V_68 , 0 ) ;
V_92 = - V_36 ;
if ( ! V_484 || ( V_484 -> V_18 & V_513 ) )
goto V_514;
V_506 = V_484 -> V_515 ;
F_191 ( & V_119 -> V_426 -> V_516 ) ;
V_431 = F_192 ( V_119 -> V_426 , V_506 ) ;
if ( ! V_431 || V_431 -> V_517 > V_506 || ( V_431 -> V_444 & V_518 ) )
goto V_519;
V_509 = F_193 ( V_431 ) ;
V_510 = F_194 ( V_509 ) ;
if ( V_431 -> V_437 && V_431 -> V_437 -> V_520 == & V_455 &&
V_506 == V_431 -> V_517 )
V_436 = V_431 -> V_437 -> V_438 ;
F_195 ( & V_119 -> V_426 -> V_516 ) ;
if ( ! V_436 ) {
V_92 = - V_521 ;
if ( F_20 ( V_454 ) ) {
F_24 ( L_19 ) ;
goto V_514;
}
V_92 = - V_36 ;
if ( ! ( V_509 == 0x1000 || V_509 == 0x10000 ||
V_509 == 0x1000000 ) )
goto V_514;
V_507 = F_196 ( V_509 ) ;
V_68 -> V_10 . V_522 = V_507 | V_523 |
( V_524 << V_525 ) ;
V_508 = V_526 ;
V_67 = V_507 << ( V_527 - 4 ) ;
F_197 ( V_2 , V_484 , V_510 ) ;
} else {
V_429 = V_440 ;
if ( V_429 > V_484 -> V_493 )
V_429 = V_484 -> V_493 ;
V_429 <<= V_458 ;
V_511 = F_160 ( V_429 ) ;
V_92 = - V_36 ;
if ( ( long ) V_511 < 0 ) {
F_24 ( L_20 , V_429 ) ;
goto V_514;
}
F_153 ( & V_436 -> V_528 ) ;
V_68 -> V_10 . V_529 = V_436 ;
if ( F_20 ( V_454 ) ) {
V_508 = ( 1ul << V_530 ) |
( 3ul << V_531 ) | V_532 ;
V_67 = ( ( V_511 >> 2 ) << V_530 ) |
( ( V_511 & 3 ) << V_531 ) ;
V_67 |= ( ( V_436 -> V_442 >> ( 26 - V_458 ) ) & 0xffff )
<< V_533 ;
} else {
V_508 = V_534 | V_535 | V_536 ;
V_67 = V_511 << V_537 ;
V_68 -> V_10 . V_538 = V_436 -> V_442 << V_458 ;
}
F_198 ( L_21 ,
V_436 -> V_442 << V_458 , V_429 , V_67 ) ;
V_493 = V_440 ;
V_510 = F_194 ( V_493 ) ;
V_492 = V_484 -> V_10 . V_495 ;
if ( V_492 ) {
if ( V_493 > V_484 -> V_493 )
V_493 = V_484 -> V_493 ;
F_21 ( & V_68 -> V_10 . V_539 ) ;
for ( V_202 = 0 ; V_202 < V_493 ; ++ V_202 )
V_492 [ V_202 ] = ( ( V_436 -> V_442 + V_202 ) << V_458 ) +
V_510 ;
F_22 ( & V_68 -> V_10 . V_539 ) ;
}
}
F_187 ( V_68 , V_67 , V_508 ) ;
F_48 () ;
V_68 -> V_10 . V_424 = 1 ;
V_92 = 0 ;
V_514:
F_55 ( & V_68 -> V_157 , V_401 ) ;
V_350:
F_29 ( & V_68 -> V_44 ) ;
return V_92 ;
V_519:
F_195 ( & V_119 -> V_426 -> V_516 ) ;
goto V_514;
}
static int F_199 ( struct V_68 * V_68 )
{
unsigned long V_67 , V_540 ;
V_540 = F_200 () ;
if ( ( long ) V_540 < 0 )
return - V_351 ;
V_68 -> V_10 . V_540 = V_540 ;
F_201 ( & V_68 -> V_10 . V_541 ) ;
memcpy ( V_68 -> V_10 . V_154 , V_542 ,
sizeof( V_68 -> V_10 . V_154 ) ) ;
V_68 -> V_10 . V_529 = NULL ;
V_68 -> V_10 . V_543 = F_92 ( V_544 ) ;
if ( F_20 ( V_454 ) ) {
V_68 -> V_10 . V_545 = 0 ;
V_68 -> V_10 . V_546 = V_67 = F_92 ( V_547 ) ;
V_67 &= ~ ( ( 3 << V_548 ) | ( 0xful << V_549 ) ) ;
V_67 |= ( ( V_540 >> 4 ) << V_548 ) |
( ( V_540 & 0xf ) << V_549 ) ;
} else {
V_68 -> V_10 . V_545 = F_92 ( V_550 ) ;
V_68 -> V_10 . V_546 = V_67 = F_92 ( V_551 ) ;
V_67 &= V_552 | V_553 ;
V_67 |= ( 4UL << V_554 ) | V_555 |
V_534 | V_556 ;
V_68 -> V_10 . V_522 = V_523 |
( V_524 << V_525 ) ;
if ( F_20 ( V_43 ) )
V_67 |= V_557 ;
}
V_68 -> V_10 . V_67 = V_67 ;
V_68 -> V_10 . V_502 = ! ! F_20 ( V_35 ) ;
F_84 ( & V_68 -> V_10 . V_539 ) ;
F_202 () ;
return 0 ;
}
static void F_203 ( struct V_68 * V_68 )
{
long int V_202 ;
for ( V_202 = 0 ; V_202 < V_349 ; ++ V_202 ) {
if ( V_68 -> V_10 . V_364 [ V_202 ] && V_68 -> V_10 . V_364 [ V_202 ] -> V_346 ) {
struct V_15 * V_16 = V_68 -> V_10 . V_364 [ V_202 ] ;
F_204 ( ( unsigned long ) V_16 -> V_346 ,
V_348 ) ;
}
F_205 ( V_68 -> V_10 . V_364 [ V_202 ] ) ;
}
V_68 -> V_10 . V_365 = 0 ;
}
static void F_206 ( struct V_68 * V_68 )
{
F_207 () ;
F_203 ( V_68 ) ;
if ( V_68 -> V_10 . V_529 ) {
F_166 ( V_68 -> V_10 . V_529 ) ;
V_68 -> V_10 . V_529 = NULL ;
}
F_208 ( V_68 ) ;
}
static int F_209 ( struct V_178 * V_179 , struct V_1 * V_2 ,
unsigned int V_558 , int * V_559 )
{
return V_560 ;
}
static int F_210 ( struct V_1 * V_2 , int V_561 ,
T_4 V_562 )
{
return V_560 ;
}
static int F_211 ( struct V_1 * V_2 , int V_561 ,
T_4 * V_562 )
{
return V_560 ;
}
static int F_212 ( void )
{
if ( ! F_20 ( V_453 ) )
return - V_563 ;
return 0 ;
}
static long F_213 ( struct V_443 * V_450 ,
unsigned int V_564 , unsigned long V_565 )
{
struct V_68 * V_68 V_566 = V_450 -> V_438 ;
void T_6 * V_567 = ( void T_6 * ) V_565 ;
long V_45 ;
switch ( V_564 ) {
case V_568 : {
struct V_451 V_529 ;
struct V_68 * V_68 = V_450 -> V_438 ;
V_45 = F_167 ( V_68 , & V_529 ) ;
if ( V_45 >= 0 && F_177 ( V_567 , & V_529 , sizeof( V_529 ) ) )
V_45 = - V_491 ;
break;
}
case V_569 : {
T_3 V_570 ;
V_45 = - V_491 ;
if ( F_214 ( V_570 , ( T_3 T_6 * ) V_567 ) )
break;
V_45 = F_215 ( V_68 , & V_570 ) ;
if ( V_45 )
break;
V_45 = - V_491 ;
if ( F_216 ( V_570 , ( T_3 T_6 * ) V_567 ) )
break;
V_45 = 0 ;
break;
}
case V_571 : {
struct V_572 V_573 ;
V_45 = - V_491 ;
if ( F_217 ( & V_573 , V_567 , sizeof( V_573 ) ) )
break;
V_45 = F_218 ( V_68 , & V_573 ) ;
break;
}
default:
V_45 = - V_574 ;
}
return V_45 ;
}
static void F_219 ( void )
{
int V_202 ;
unsigned int V_575 ;
for ( V_202 = 0 ; V_576 [ V_202 ] ; ++ V_202 ) {
V_575 = V_576 [ V_202 ] ;
F_220 ( ! F_63 ( V_575 ) ) ;
F_221 ( V_575 / 4 , V_542 ) ;
}
}
static int F_222 ( void )
{
int V_45 ;
V_45 = F_212 () ;
if ( V_45 < 0 )
return - V_577 ;
V_578 . V_579 = V_580 ;
V_581 = & V_578 ;
F_219 () ;
V_45 = F_223 () ;
return V_45 ;
}
static void F_224 ( void )
{
V_581 = NULL ;
}
