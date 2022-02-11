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
V_75 -> V_78 = 1 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_79 * V_72 ,
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
static int F_32 ( struct V_79 * V_86 )
{
if ( V_86 -> V_85 )
return V_86 -> V_84 != 0 ;
return V_86 -> V_87 != NULL ;
}
static unsigned long F_33 ( struct V_1 * V_2 ,
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
V_90 = F_34 ( V_68 , V_75 , & V_89 ) ;
if ( V_90 == NULL )
return V_94 ;
if ( V_93 == V_97 )
V_81 = ( (struct V_100 * ) V_90 ) -> V_101 . V_102 ;
else
V_81 = ( (struct V_100 * ) V_90 ) -> V_101 . V_103 ;
F_35 ( V_68 , V_90 , V_75 , false ) ;
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
if ( ! F_32 ( & V_91 -> V_10 . V_75 ) )
break;
V_86 = & V_91 -> V_10 . V_106 ;
V_92 = 0 ;
break;
case V_99 :
V_92 = V_105 ;
if ( ! F_32 ( & V_91 -> V_10 . V_75 ) )
break;
V_86 = & V_91 -> V_10 . V_107 ;
V_92 = 0 ;
break;
case V_108 :
V_92 = V_105 ;
if ( F_32 ( & V_91 -> V_10 . V_106 ) ||
F_32 ( & V_91 -> V_10 . V_107 ) )
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
static void F_36 ( struct V_1 * V_2 , struct V_79 * V_86 )
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
V_90 = F_34 ( V_68 , V_111 , & V_89 ) ;
F_21 ( & V_2 -> V_10 . V_83 ) ;
if ( V_111 == V_86 -> V_84 )
break;
if ( V_90 )
F_35 ( V_68 , V_90 , V_111 , false ) ;
}
V_86 -> V_85 = 0 ;
if ( V_90 && V_89 < V_86 -> V_81 ) {
F_35 ( V_68 , V_90 , V_111 , false ) ;
V_90 = NULL ;
}
if ( V_86 -> V_87 )
F_35 ( V_68 , V_86 -> V_87 , V_86 -> V_111 ,
V_86 -> V_112 ) ;
V_86 -> V_111 = V_111 ;
V_86 -> V_87 = V_90 ;
V_86 -> V_112 = false ;
if ( V_90 )
V_86 -> V_113 = V_90 + V_86 -> V_81 ;
}
static void F_37 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_10 . V_75 . V_85 ||
V_2 -> V_10 . V_107 . V_85 ||
V_2 -> V_10 . V_106 . V_85 ) )
return;
F_21 ( & V_2 -> V_10 . V_83 ) ;
if ( V_2 -> V_10 . V_75 . V_85 ) {
F_36 ( V_2 , & V_2 -> V_10 . V_75 ) ;
if ( V_2 -> V_10 . V_75 . V_87 )
F_30 ( V_2 , V_2 -> V_10 . V_75 . V_87 ) ;
}
if ( V_2 -> V_10 . V_106 . V_85 ) {
F_36 ( V_2 , & V_2 -> V_10 . V_106 ) ;
V_2 -> V_10 . V_114 = V_2 -> V_10 . V_106 . V_87 ;
V_2 -> V_10 . V_115 = 0 ;
}
if ( V_2 -> V_10 . V_107 . V_85 )
F_36 ( V_2 , & V_2 -> V_10 . V_107 ) ;
F_22 ( & V_2 -> V_10 . V_83 ) ;
}
static T_2 F_38 ( struct V_15 * V_16 , T_2 V_116 )
{
T_2 V_117 ;
if ( V_16 -> V_21 != V_22 &&
V_16 -> V_20 -> V_10 . V_118 != V_119 ) {
F_39 ( & V_16 -> V_20 -> V_10 . V_19 ) ;
V_117 = V_16 -> V_25 ;
if ( V_16 -> V_23 != V_24 )
V_117 += V_116 - V_16 -> V_23 ;
F_40 ( & V_16 -> V_20 -> V_10 . V_19 ) ;
} else {
V_117 = V_16 -> V_25 ;
}
return V_117 ;
}
static void F_41 ( struct V_1 * V_2 ,
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
V_122 = F_38 ( V_16 , V_116 ) ;
V_121 = V_122 - V_2 -> V_10 . V_123 ;
V_2 -> V_10 . V_123 = V_122 ;
F_39 ( & V_2 -> V_10 . V_19 ) ;
V_121 += V_2 -> V_10 . V_29 ;
V_2 -> V_10 . V_29 = 0 ;
F_40 ( & V_2 -> V_10 . V_19 ) ;
if ( ! V_120 || ! V_75 )
return;
memset ( V_120 , 0 , sizeof( struct V_104 ) ) ;
V_120 -> V_124 = 7 ;
V_120 -> V_125 = V_16 -> V_126 + V_2 -> V_10 . V_11 ;
V_120 -> V_127 = V_116 + V_16 -> V_128 ;
V_120 -> V_129 = V_121 ;
V_120 -> V_51 = F_42 ( V_2 ) ;
V_120 -> V_52 = V_2 -> V_10 . V_31 . V_30 ;
++ V_120 ;
if ( V_120 == V_2 -> V_10 . V_106 . V_113 )
V_120 = V_2 -> V_10 . V_106 . V_87 ;
V_2 -> V_10 . V_114 = V_120 ;
F_43 () ;
V_75 -> V_130 = ++ V_2 -> V_10 . V_115 ;
V_2 -> V_10 . V_106 . V_112 = true ;
}
int F_44 ( struct V_1 * V_2 )
{
unsigned long V_131 = F_25 ( V_2 , 3 ) ;
unsigned long V_132 , V_73 = V_133 ;
struct V_1 * V_91 ;
int V_134 , V_135 ;
switch ( V_131 ) {
case V_136 :
V_134 = F_45 ( & V_2 -> V_68 -> V_137 ) ;
V_73 = F_46 ( V_2 , F_25 ( V_2 , 4 ) ,
F_25 ( V_2 , 5 ) ,
F_25 ( V_2 , 6 ) ,
F_25 ( V_2 , 7 ) ) ;
F_47 ( & V_2 -> V_68 -> V_137 , V_134 ) ;
break;
case V_138 :
break;
case V_139 :
V_132 = F_25 ( V_2 , 4 ) ;
V_91 = F_26 ( V_2 -> V_68 , V_132 ) ;
if ( ! V_91 ) {
V_73 = V_94 ;
break;
}
V_91 -> V_10 . V_140 = 1 ;
F_48 () ;
if ( V_2 -> V_10 . V_141 ) {
if ( F_3 ( & V_2 -> V_142 ) ) {
F_4 ( & V_2 -> V_142 ) ;
V_2 -> V_6 . V_7 ++ ;
}
}
break;
case V_143 :
V_132 = F_25 ( V_2 , 4 ) ;
if ( V_132 == - 1 )
break;
V_91 = F_26 ( V_2 -> V_68 , V_132 ) ;
if ( ! V_91 ) {
V_73 = V_94 ;
break;
}
F_49 ( V_91 ) ;
break;
case V_144 :
V_73 = F_33 ( V_2 , F_25 ( V_2 , 4 ) ,
F_25 ( V_2 , 5 ) ,
F_25 ( V_2 , 6 ) ) ;
break;
case V_145 :
if ( F_50 ( & V_2 -> V_68 -> V_10 . V_146 ) )
return V_147 ;
V_134 = F_45 ( & V_2 -> V_68 -> V_137 ) ;
V_135 = F_51 ( V_2 ) ;
F_47 ( & V_2 -> V_68 -> V_137 , V_134 ) ;
if ( V_135 == - V_148 )
return V_147 ;
else if ( V_135 == 0 )
break;
return V_135 ;
case V_149 :
case V_150 :
case V_151 :
case V_152 :
case V_153 :
case V_154 :
if ( F_52 ( V_2 ) ) {
V_73 = F_53 ( V_2 , V_131 ) ;
break;
}
default:
return V_147 ;
}
F_54 ( V_2 , 3 , V_73 ) ;
V_2 -> V_10 . V_155 = 0 ;
return V_156 ;
}
static int F_55 ( struct V_157 * V_158 , struct V_1 * V_2 ,
struct V_159 * V_160 )
{
int V_45 = V_147 ;
V_2 -> V_6 . V_161 ++ ;
V_158 -> V_162 = V_163 ;
V_158 -> V_164 = 1 ;
switch ( V_2 -> V_10 . V_48 ) {
case V_165 :
V_2 -> V_6 . V_166 ++ ;
V_45 = V_156 ;
break;
case V_167 :
case V_168 :
V_2 -> V_6 . V_169 ++ ;
V_45 = V_156 ;
break;
case V_170 :
V_45 = V_156 ;
break;
case V_171 :
F_56 ( V_2 ,
V_171 ) ;
V_45 = V_156 ;
break;
case V_172 :
{
T_4 V_18 ;
V_18 = V_2 -> V_10 . V_31 . V_30 & 0x1f0000ull ;
F_57 ( V_2 , V_18 ) ;
V_45 = V_156 ;
break;
}
case V_173 :
{
int V_174 ;
V_158 -> V_175 . V_176 = F_25 ( V_2 , 3 ) ;
for ( V_174 = 0 ; V_174 < 9 ; ++ V_174 )
V_158 -> V_175 . args [ V_174 ] = F_25 ( V_2 , 4 + V_174 ) ;
V_158 -> V_162 = V_177 ;
V_2 -> V_10 . V_155 = 1 ;
V_45 = V_147 ;
break;
}
case V_178 :
V_45 = V_179 ;
break;
case V_180 :
V_2 -> V_10 . V_61 = F_42 ( V_2 ) ;
V_2 -> V_10 . V_62 = 0 ;
V_45 = V_179 ;
break;
case V_181 :
F_57 ( V_2 , V_182 ) ;
V_45 = V_156 ;
break;
case V_183 :
F_57 ( V_2 , V_182 ) ;
V_45 = V_156 ;
break;
default:
F_23 ( V_2 ) ;
F_58 ( V_184 L_14 ,
V_2 -> V_10 . V_48 , F_42 ( V_2 ) ,
V_2 -> V_10 . V_31 . V_30 ) ;
V_158 -> V_185 . V_186 = V_2 -> V_10 . V_48 ;
V_45 = V_147 ;
break;
}
return V_45 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_187 * V_188 )
{
int V_174 ;
memset ( V_188 , 0 , sizeof( struct V_187 ) ) ;
V_188 -> V_32 = V_2 -> V_10 . V_32 ;
for ( V_174 = 0 ; V_174 < V_2 -> V_10 . V_63 ; V_174 ++ ) {
V_188 -> V_189 . V_190 . V_191 . V_64 [ V_174 ] . V_192 = V_2 -> V_10 . V_64 [ V_174 ] . V_65 ;
V_188 -> V_189 . V_190 . V_191 . V_64 [ V_174 ] . V_193 = V_2 -> V_10 . V_64 [ V_174 ] . V_66 ;
}
return 0 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_187 * V_188 )
{
int V_174 , V_194 ;
F_18 ( V_2 , V_188 -> V_32 ) ;
V_194 = 0 ;
for ( V_174 = 0 ; V_174 < V_2 -> V_10 . V_195 ; V_174 ++ ) {
if ( V_188 -> V_189 . V_190 . V_191 . V_64 [ V_174 ] . V_192 & V_196 ) {
V_2 -> V_10 . V_64 [ V_194 ] . V_65 = V_188 -> V_189 . V_190 . V_191 . V_64 [ V_174 ] . V_192 ;
V_2 -> V_10 . V_64 [ V_194 ] . V_66 = V_188 -> V_189 . V_190 . V_191 . V_64 [ V_174 ] . V_193 ;
++ V_194 ;
}
}
V_2 -> V_10 . V_63 = V_194 ;
return 0 ;
}
static void F_61 ( struct V_1 * V_2 , T_2 V_197 )
{
struct V_15 * V_16 = V_2 -> V_10 . V_17 ;
T_2 V_198 ;
F_21 ( & V_16 -> V_44 ) ;
if ( ( V_197 & V_199 ) != ( V_16 -> V_67 & V_199 ) ) {
struct V_68 * V_68 = V_2 -> V_68 ;
struct V_1 * V_2 ;
int V_174 ;
F_27 ( & V_68 -> V_44 ) ;
F_28 (i, vcpu, kvm) {
if ( V_2 -> V_10 . V_17 != V_16 )
continue;
if ( V_197 & V_199 )
V_2 -> V_10 . V_200 |= V_201 ;
else
V_2 -> V_10 . V_200 &= ~ V_201 ;
}
F_29 ( & V_68 -> V_44 ) ;
}
V_198 = V_202 | V_199 | V_203 ;
if ( F_20 ( V_43 ) )
V_198 |= V_204 ;
V_16 -> V_67 = ( V_16 -> V_67 & ~ V_198 ) | ( V_197 & V_198 ) ;
F_22 ( & V_16 -> V_44 ) ;
}
static int F_62 ( struct V_1 * V_2 , T_2 V_71 ,
union V_205 * V_206 )
{
int V_45 = 0 ;
long int V_174 ;
switch ( V_71 ) {
case V_207 :
* V_206 = F_63 ( V_71 , 0 ) ;
break;
case V_208 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_209 ) ;
break;
case V_210 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_211 ) ;
break;
case V_212 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_213 ) ;
break;
case V_214 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_215 ) ;
break;
case V_216 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_217 ) ;
break;
case V_218 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_219 ) ;
break;
case V_220 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_221 ) ;
break;
case V_222 ... V_223 :
V_174 = V_71 - V_222 ;
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_224 [ V_174 ] ) ;
break;
case V_225 ... V_226 :
V_174 = V_71 - V_225 ;
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_227 [ V_174 ] ) ;
break;
case V_228 ... V_229 :
V_174 = V_71 - V_228 ;
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_230 [ V_174 ] ) ;
break;
case V_231 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_232 ) ;
break;
case V_233 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_234 ) ;
break;
case V_235 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_236 ) ;
break;
case V_237 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_238 ) ;
break;
#ifdef F_64
case V_239 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_240 ) ;
break;
case V_241 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_242 ) ;
break;
case V_243 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_244 ) ;
break;
#endif
case V_245 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_246 ) ;
break;
case V_247 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_248 ) ;
break;
case V_249 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_250 ) ;
break;
case V_251 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_252 ) ;
break;
case V_253 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_254 ) ;
break;
case V_255 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_256 ) ;
break;
case V_257 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_17 -> V_258 ) ;
break;
case V_259 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_260 ) ;
break;
case V_261 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_262 ) ;
break;
case V_263 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_264 ) ;
break;
case V_265 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_266 ) ;
break;
case V_267 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_268 ) ;
break;
case V_269 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_270 ) ;
break;
case V_271 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_272 ) ;
break;
case V_273 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_274 ) ;
break;
case V_275 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_276 ) ;
break;
case V_277 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_278 ) ;
break;
case V_279 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_280 ) ;
break;
case V_281 :
F_21 ( & V_2 -> V_10 . V_83 ) ;
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_75 . V_84 ) ;
F_22 ( & V_2 -> V_10 . V_83 ) ;
break;
case V_282 :
F_21 ( & V_2 -> V_10 . V_83 ) ;
V_206 -> V_283 . V_80 = V_2 -> V_10 . V_107 . V_84 ;
V_206 -> V_283 . V_101 = V_2 -> V_10 . V_107 . V_81 ;
F_22 ( & V_2 -> V_10 . V_83 ) ;
break;
case V_284 :
F_21 ( & V_2 -> V_10 . V_83 ) ;
V_206 -> V_283 . V_80 = V_2 -> V_10 . V_106 . V_84 ;
V_206 -> V_283 . V_101 = V_2 -> V_10 . V_106 . V_81 ;
F_22 ( & V_2 -> V_10 . V_83 ) ;
break;
case V_285 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_17 -> V_128 ) ;
break;
case V_286 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_17 -> V_67 ) ;
break;
case V_287 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_288 ) ;
break;
case V_289 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_17 -> V_33 ) ;
break;
default:
V_45 = - V_36 ;
break;
}
return V_45 ;
}
static int F_65 ( struct V_1 * V_2 , T_2 V_71 ,
union V_205 * V_206 )
{
int V_45 = 0 ;
long int V_174 ;
unsigned long V_80 , V_81 ;
switch ( V_71 ) {
case V_207 :
if ( F_66 ( V_71 , * V_206 ) )
V_45 = - V_36 ;
break;
case V_208 :
V_2 -> V_10 . V_209 = F_66 ( V_71 , * V_206 ) ;
break;
case V_210 :
V_2 -> V_10 . V_211 = F_66 ( V_71 , * V_206 ) & ~ V_290 ;
break;
case V_212 :
V_2 -> V_10 . V_213 = F_66 ( V_71 , * V_206 ) ;
break;
case V_214 :
V_2 -> V_10 . V_215 = F_66 ( V_71 , * V_206 ) ;
break;
case V_216 :
V_2 -> V_10 . V_217 = F_66 ( V_71 , * V_206 ) ;
break;
case V_218 :
V_2 -> V_10 . V_219 = F_66 ( V_71 , * V_206 ) ;
break;
case V_220 :
V_2 -> V_10 . V_221 = F_66 ( V_71 , * V_206 ) ;
break;
case V_222 ... V_223 :
V_174 = V_71 - V_222 ;
V_2 -> V_10 . V_224 [ V_174 ] = F_66 ( V_71 , * V_206 ) ;
break;
case V_225 ... V_226 :
V_174 = V_71 - V_225 ;
V_2 -> V_10 . V_227 [ V_174 ] = F_66 ( V_71 , * V_206 ) ;
break;
case V_228 ... V_229 :
V_174 = V_71 - V_228 ;
V_2 -> V_10 . V_230 [ V_174 ] = F_66 ( V_71 , * V_206 ) ;
break;
case V_231 :
V_2 -> V_10 . V_232 = F_66 ( V_71 , * V_206 ) ;
break;
case V_233 :
V_2 -> V_10 . V_234 = F_66 ( V_71 , * V_206 ) ;
break;
case V_235 :
V_2 -> V_10 . V_236 = F_66 ( V_71 , * V_206 ) ;
break;
case V_237 :
V_2 -> V_10 . V_238 = F_66 ( V_71 , * V_206 ) ;
break;
#ifdef F_64
case V_239 :
V_2 -> V_10 . V_240 = F_66 ( V_71 , * V_206 ) ;
break;
case V_241 :
V_2 -> V_10 . V_242 = F_66 ( V_71 , * V_206 ) ;
break;
case V_243 :
V_2 -> V_10 . V_244 = F_66 ( V_71 , * V_206 ) ;
break;
#endif
case V_245 :
V_2 -> V_10 . V_246 = F_66 ( V_71 , * V_206 ) ;
break;
case V_247 :
V_2 -> V_10 . V_248 = F_66 ( V_71 , * V_206 ) ;
break;
case V_249 :
V_2 -> V_10 . V_250 = F_66 ( V_71 , * V_206 ) ;
break;
case V_251 :
V_2 -> V_10 . V_252 = F_66 ( V_71 , * V_206 ) ;
break;
case V_253 :
V_2 -> V_10 . V_254 = F_66 ( V_71 , * V_206 ) ;
break;
case V_255 :
V_2 -> V_10 . V_256 = F_66 ( V_71 , * V_206 ) ;
break;
case V_257 :
V_2 -> V_10 . V_17 -> V_258 = F_66 ( V_71 , * V_206 ) ;
break;
case V_259 :
V_2 -> V_10 . V_260 = F_66 ( V_71 , * V_206 ) ;
break;
case V_261 :
V_2 -> V_10 . V_262 = F_66 ( V_71 , * V_206 ) & ~ V_291 ;
break;
case V_263 :
V_2 -> V_10 . V_264 = F_66 ( V_71 , * V_206 ) ;
if ( ( V_2 -> V_10 . V_264 & V_292 ) == V_293 )
V_2 -> V_10 . V_264 &= ~ V_292 ;
break;
case V_265 :
V_2 -> V_10 . V_266 = F_66 ( V_71 , * V_206 ) ;
break;
case V_267 :
V_2 -> V_10 . V_268 = F_66 ( V_71 , * V_206 ) ;
break;
case V_269 :
V_2 -> V_10 . V_270 = F_66 ( V_71 , * V_206 ) ;
break;
case V_271 :
V_2 -> V_10 . V_272 = F_66 ( V_71 , * V_206 ) ;
break;
case V_273 :
V_2 -> V_10 . V_274 = F_66 ( V_71 , * V_206 ) ;
break;
case V_275 :
V_2 -> V_10 . V_276 = F_66 ( V_71 , * V_206 ) ;
break;
case V_277 :
V_2 -> V_10 . V_278 = F_66 ( V_71 , * V_206 ) ;
break;
case V_279 :
V_2 -> V_10 . V_280 = F_66 ( V_71 , * V_206 ) ;
break;
case V_281 :
V_80 = F_66 ( V_71 , * V_206 ) ;
V_45 = - V_36 ;
if ( ! V_80 && ( V_2 -> V_10 . V_107 . V_84 ||
V_2 -> V_10 . V_106 . V_84 ) )
break;
V_45 = F_31 ( V_2 , & V_2 -> V_10 . V_75 , V_80 , sizeof( struct V_74 ) ) ;
break;
case V_282 :
V_80 = V_206 -> V_283 . V_80 ;
V_81 = V_206 -> V_283 . V_101 ;
V_45 = - V_36 ;
if ( V_80 && ! V_2 -> V_10 . V_75 . V_84 )
break;
V_45 = F_31 ( V_2 , & V_2 -> V_10 . V_107 , V_80 , V_81 ) ;
break;
case V_284 :
V_80 = V_206 -> V_283 . V_80 ;
V_81 = V_206 -> V_283 . V_101 ;
V_45 = - V_36 ;
if ( V_80 && ( V_81 < sizeof( struct V_104 ) ||
! V_2 -> V_10 . V_75 . V_84 ) )
break;
V_81 -= V_81 % sizeof( struct V_104 ) ;
V_45 = F_31 ( V_2 , & V_2 -> V_10 . V_106 , V_80 , V_81 ) ;
break;
case V_285 :
V_2 -> V_10 . V_17 -> V_128 =
F_67 ( F_66 ( V_71 , * V_206 ) , 1UL << 24 ) ;
break;
case V_286 :
F_61 ( V_2 , F_66 ( V_71 , * V_206 ) ) ;
break;
case V_287 :
V_2 -> V_10 . V_288 = F_66 ( V_71 , * V_206 ) ;
break;
case V_289 :
V_45 = F_19 ( V_2 , F_66 ( V_71 , * V_206 ) ) ;
break;
default:
V_45 = - V_36 ;
break;
}
return V_45 ;
}
static struct V_1 * F_68 ( struct V_68 * V_68 ,
unsigned int V_71 )
{
struct V_1 * V_2 ;
int V_92 = - V_36 ;
int V_294 ;
struct V_15 * V_17 ;
V_294 = V_71 / V_295 ;
if ( V_294 >= V_296 )
goto V_297;
V_92 = - V_298 ;
V_2 = F_69 ( V_299 , V_300 ) ;
if ( ! V_2 )
goto V_297;
V_92 = F_70 ( V_2 , V_68 , V_71 ) ;
if ( V_92 )
goto V_301;
V_2 -> V_10 . V_302 = & V_2 -> V_10 . V_31 ;
V_2 -> V_10 . V_224 [ 0 ] = V_303 ;
V_2 -> V_10 . V_304 = V_305 ;
F_18 ( V_2 , F_71 ( V_306 ) ) ;
F_72 ( & V_2 -> V_10 . V_83 ) ;
F_72 ( & V_2 -> V_10 . V_19 ) ;
V_2 -> V_10 . V_28 = V_24 ;
V_2 -> V_10 . V_200 = V_307 | V_308 ;
F_73 ( V_2 ) ;
V_2 -> V_10 . V_26 = V_309 ;
F_74 ( & V_2 -> V_10 . V_310 ) ;
F_27 ( & V_68 -> V_44 ) ;
V_17 = V_68 -> V_10 . V_311 [ V_294 ] ;
if ( ! V_17 ) {
V_17 = F_75 ( sizeof( struct V_15 ) , V_300 ) ;
if ( V_17 ) {
F_76 ( & V_17 -> V_312 ) ;
F_72 ( & V_17 -> V_44 ) ;
F_74 ( & V_17 -> V_142 ) ;
V_17 -> V_23 = V_24 ;
V_17 -> V_67 = V_68 -> V_10 . V_67 ;
V_17 -> V_313 = V_294 * V_295 ;
V_17 -> V_68 = V_68 ;
}
V_68 -> V_10 . V_311 [ V_294 ] = V_17 ;
V_68 -> V_10 . V_314 ++ ;
}
F_29 ( & V_68 -> V_44 ) ;
if ( ! V_17 )
goto V_301;
F_21 ( & V_17 -> V_44 ) ;
++ V_17 -> V_315 ;
F_22 ( & V_17 -> V_44 ) ;
V_2 -> V_10 . V_17 = V_17 ;
V_2 -> V_10 . V_11 = V_2 -> V_46 - V_17 -> V_313 ;
V_2 -> V_10 . V_316 = V_317 ;
F_77 ( V_2 ) ;
return V_2 ;
V_301:
F_78 ( V_299 , V_2 ) ;
V_297:
return F_79 ( V_92 ) ;
}
static void F_80 ( struct V_68 * V_68 , struct V_79 * V_75 )
{
if ( V_75 -> V_87 )
F_35 ( V_68 , V_75 -> V_87 , V_75 -> V_111 ,
V_75 -> V_112 ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
F_21 ( & V_2 -> V_10 . V_83 ) ;
F_80 ( V_2 -> V_68 , & V_2 -> V_10 . V_106 ) ;
F_80 ( V_2 -> V_68 , & V_2 -> V_10 . V_107 ) ;
F_80 ( V_2 -> V_68 , & V_2 -> V_10 . V_75 ) ;
F_22 ( & V_2 -> V_10 . V_83 ) ;
F_82 ( V_2 ) ;
F_78 ( V_299 , V_2 ) ;
}
static int F_83 ( struct V_1 * V_2 )
{
return 1 ;
}
static void F_84 ( struct V_1 * V_2 )
{
unsigned long V_318 , V_116 ;
V_116 = F_85 () ;
if ( V_116 > V_2 -> V_10 . V_319 ) {
F_86 ( V_2 ) ;
F_87 ( V_2 ) ;
return;
}
V_318 = ( V_2 -> V_10 . V_319 - V_116 ) * V_320
/ V_321 ;
F_88 ( & V_2 -> V_10 . V_322 , F_89 ( 0 , V_318 ) ,
V_323 ) ;
V_2 -> V_10 . V_324 = 1 ;
}
static void F_17 ( struct V_1 * V_2 )
{
V_2 -> V_10 . V_141 = 0 ;
if ( V_2 -> V_10 . V_324 ) {
F_90 ( & V_2 -> V_10 . V_322 ) ;
V_2 -> V_10 . V_324 = 0 ;
}
}
static void F_91 ( struct V_15 * V_16 ,
struct V_1 * V_2 )
{
T_2 V_116 ;
if ( V_2 -> V_10 . V_26 != V_325 )
return;
F_39 ( & V_2 -> V_10 . V_19 ) ;
V_116 = F_13 () ;
V_2 -> V_10 . V_29 += F_38 ( V_16 , V_116 ) -
V_2 -> V_10 . V_123 ;
V_2 -> V_10 . V_28 = V_116 ;
V_2 -> V_10 . V_26 = V_27 ;
F_40 ( & V_2 -> V_10 . V_19 ) ;
-- V_16 -> V_326 ;
F_92 ( & V_2 -> V_10 . V_327 ) ;
}
static int F_93 ( int V_4 )
{
struct V_328 * V_329 ;
long V_330 = 1000 ;
V_329 = & V_12 [ V_4 ] ;
V_329 -> V_13 . V_331 = 1 ;
V_329 -> V_13 . V_1 = NULL ;
F_48 () ;
while ( V_329 -> V_13 . V_332 == V_333 ) {
if ( -- V_330 <= 0 ) {
F_24 ( L_15 , V_4 ) ;
return - V_334 ;
}
F_94 ( 1 ) ;
}
return 0 ;
}
static void F_95 ( int V_4 )
{
struct V_328 * V_329 ;
V_329 = & V_12 [ V_4 ] ;
V_329 -> V_13 . V_331 = 0 ;
V_329 -> V_13 . V_1 = NULL ;
}
static void F_96 ( struct V_1 * V_2 )
{
int V_4 ;
struct V_328 * V_329 ;
struct V_15 * V_16 = V_2 -> V_10 . V_17 ;
if ( V_2 -> V_10 . V_324 ) {
F_90 ( & V_2 -> V_10 . V_322 ) ;
V_2 -> V_10 . V_324 = 0 ;
}
V_4 = V_16 -> V_126 + V_2 -> V_10 . V_11 ;
V_329 = & V_12 [ V_4 ] ;
V_329 -> V_13 . V_1 = V_2 ;
V_329 -> V_13 . V_335 = V_16 ;
V_329 -> V_13 . V_11 = V_2 -> V_10 . V_11 ;
V_2 -> V_4 = V_16 -> V_126 ;
F_43 () ;
#if F_97 ( V_336 ) && F_97 ( V_337 )
if ( V_4 != F_98 () ) {
#ifdef F_6
F_7 ( V_4 ) ;
#endif
if ( V_2 -> V_10 . V_11 )
++ V_16 -> V_338 ;
}
#endif
}
static void F_99 ( struct V_15 * V_16 )
{
int V_174 ;
F_100 () ;
V_174 = 0 ;
while ( V_16 -> V_339 < V_16 -> V_338 ) {
if ( ++ V_174 >= 1000000 ) {
F_24 ( L_16 ,
V_16 -> V_339 , V_16 -> V_338 ) ;
break;
}
F_101 () ;
}
F_102 () ;
}
static int F_103 ( void )
{
int V_4 = F_98 () ;
int V_340 = F_104 ( V_4 ) ;
if ( V_340 )
return 0 ;
while ( ++ V_340 < V_295 )
if ( F_8 ( V_4 + V_340 ) )
return 0 ;
for ( V_340 = 1 ; V_340 < V_295 ; ++ V_340 ) {
if ( F_93 ( V_4 + V_340 ) ) {
do {
F_95 ( V_4 + V_340 ) ;
} while ( -- V_340 > 0 );
return 0 ;
}
}
return 1 ;
}
static void F_105 ( struct V_15 * V_16 )
{
struct V_1 * V_2 , * V_341 ;
long V_73 ;
T_2 V_116 ;
int V_174 , V_342 ;
int V_343 ;
struct V_1 * V_344 [ V_295 ] ;
V_342 = 0 ;
F_106 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( F_107 ( V_2 -> V_10 . V_118 ) )
return;
if ( V_2 -> V_10 . V_75 . V_85 ||
V_2 -> V_10 . V_107 . V_85 ||
V_2 -> V_10 . V_106 . V_85 )
V_344 [ V_342 ++ ] = V_2 ;
}
V_16 -> V_338 = 0 ;
V_16 -> V_339 = 0 ;
V_16 -> V_345 = 0 ;
V_16 -> V_21 = V_346 ;
V_16 -> V_347 = 0 ;
V_16 -> V_348 = 0 ;
if ( V_342 ) {
F_22 ( & V_16 -> V_44 ) ;
for ( V_174 = 0 ; V_174 < V_342 ; ++ V_174 )
F_37 ( V_344 [ V_174 ] ) ;
F_21 ( & V_16 -> V_44 ) ;
}
if ( V_295 > 1 && ! F_103 () ) {
F_106 (vcpu, &vc->runnable_threads, arch.run_list)
V_2 -> V_10 . V_73 = - V_334 ;
goto V_297;
}
V_16 -> V_126 = F_98 () ;
F_106 (vcpu, &vc->runnable_threads, arch.run_list) {
F_96 ( V_2 ) ;
F_41 ( V_2 , V_16 ) ;
}
F_108 () -> V_13 . V_335 = V_16 ;
F_108 () -> V_13 . V_11 = 0 ;
V_16 -> V_21 = V_349 ;
F_109 () ;
F_22 ( & V_16 -> V_44 ) ;
F_110 () ;
V_343 = F_45 ( & V_16 -> V_68 -> V_137 ) ;
F_111 () ;
F_21 ( & V_16 -> V_44 ) ;
F_106 (vcpu, &vc->runnable_threads, arch.run_list)
V_2 -> V_4 = - 1 ;
if ( V_16 -> V_339 < V_16 -> V_338 )
F_99 ( V_16 ) ;
for ( V_174 = 0 ; V_174 < V_295 ; ++ V_174 )
F_95 ( V_16 -> V_126 + V_174 ) ;
V_16 -> V_21 = V_350 ;
F_22 ( & V_16 -> V_44 ) ;
F_47 ( & V_16 -> V_68 -> V_137 , V_343 ) ;
F_48 () ;
F_112 () ;
F_113 () ;
F_114 () ;
F_21 ( & V_16 -> V_44 ) ;
V_116 = F_85 () ;
F_106 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( V_116 < V_2 -> V_10 . V_319 &&
F_115 ( V_2 ) )
F_116 ( V_2 ) ;
V_73 = V_156 ;
if ( V_2 -> V_10 . V_48 )
V_73 = F_55 ( V_2 -> V_10 . V_157 , V_2 ,
V_2 -> V_10 . V_118 ) ;
V_2 -> V_10 . V_73 = V_73 ;
V_2 -> V_10 . V_48 = 0 ;
if ( V_2 -> V_10 . V_141 ) {
if ( V_73 != V_156 )
F_17 ( V_2 ) ;
else
F_84 ( V_2 ) ;
}
}
V_297:
V_16 -> V_21 = V_22 ;
F_117 (vcpu, vnext, &vc->runnable_threads,
arch.run_list) {
if ( V_2 -> V_10 . V_73 != V_156 ) {
F_91 ( V_16 , V_2 ) ;
F_118 ( & V_2 -> V_10 . V_310 ) ;
}
}
}
static void F_119 ( struct V_1 * V_2 , int V_351 )
{
F_120 ( V_352 ) ;
F_121 ( & V_2 -> V_10 . V_310 , & V_352 , V_351 ) ;
if ( V_2 -> V_10 . V_26 == V_325 )
F_122 () ;
F_123 ( & V_2 -> V_10 . V_310 , & V_352 ) ;
}
static void F_124 ( struct V_15 * V_16 )
{
F_120 ( V_352 ) ;
F_121 ( & V_16 -> V_142 , & V_352 , V_353 ) ;
V_16 -> V_21 = V_354 ;
F_22 ( & V_16 -> V_44 ) ;
F_122 () ;
F_123 ( & V_16 -> V_142 , & V_352 ) ;
F_21 ( & V_16 -> V_44 ) ;
V_16 -> V_21 = V_22 ;
}
static int F_125 ( struct V_157 * V_157 , struct V_1 * V_2 )
{
int V_355 ;
struct V_15 * V_16 ;
struct V_1 * V_72 , * V_356 ;
V_157 -> V_162 = 0 ;
V_2 -> V_10 . V_73 = V_156 ;
V_2 -> V_10 . V_48 = 0 ;
F_37 ( V_2 ) ;
V_16 = V_2 -> V_10 . V_17 ;
F_21 ( & V_16 -> V_44 ) ;
V_2 -> V_10 . V_141 = 0 ;
V_2 -> V_10 . V_118 = V_119 ;
V_2 -> V_10 . V_157 = V_157 ;
V_2 -> V_10 . V_123 = F_38 ( V_16 , F_13 () ) ;
V_2 -> V_10 . V_26 = V_325 ;
V_2 -> V_10 . V_28 = V_24 ;
F_126 ( & V_2 -> V_10 . V_327 , & V_16 -> V_312 ) ;
++ V_16 -> V_326 ;
if ( ! F_107 ( V_119 ) ) {
if ( V_16 -> V_21 == V_349 &&
F_127 ( V_16 ) == 0 ) {
F_41 ( V_2 , V_16 ) ;
F_96 ( V_2 ) ;
} else if ( V_16 -> V_21 == V_354 ) {
F_118 ( & V_16 -> V_142 ) ;
}
}
while ( V_2 -> V_10 . V_26 == V_325 &&
! F_107 ( V_119 ) ) {
if ( V_16 -> V_21 != V_22 ) {
F_22 ( & V_16 -> V_44 ) ;
F_119 ( V_2 , V_353 ) ;
F_21 ( & V_16 -> V_44 ) ;
continue;
}
F_117 (v, vn, &vc->runnable_threads,
arch.run_list) {
F_87 ( V_72 ) ;
if ( F_107 ( V_72 -> V_10 . V_118 ) ) {
F_91 ( V_16 , V_72 ) ;
V_72 -> V_6 . V_357 ++ ;
V_72 -> V_10 . V_157 -> V_162 = V_358 ;
V_72 -> V_10 . V_73 = - V_359 ;
F_118 ( & V_72 -> V_10 . V_310 ) ;
}
}
if ( ! V_16 -> V_326 || V_2 -> V_10 . V_26 != V_325 )
break;
V_16 -> V_20 = V_2 ;
V_355 = 0 ;
F_106 (v, &vc->runnable_threads, arch.run_list) {
if ( ! V_72 -> V_10 . V_360 )
V_355 += V_72 -> V_10 . V_141 ;
else
V_72 -> V_10 . V_141 = 0 ;
}
if ( V_355 == V_16 -> V_326 )
F_124 ( V_16 ) ;
else
F_105 ( V_16 ) ;
V_16 -> V_20 = NULL ;
}
while ( V_2 -> V_10 . V_26 == V_325 &&
( V_16 -> V_21 == V_349 ||
V_16 -> V_21 == V_350 ) ) {
F_22 ( & V_16 -> V_44 ) ;
F_119 ( V_2 , V_361 ) ;
F_21 ( & V_16 -> V_44 ) ;
}
if ( V_2 -> V_10 . V_26 == V_325 ) {
F_91 ( V_16 , V_2 ) ;
V_2 -> V_6 . V_357 ++ ;
V_157 -> V_162 = V_358 ;
V_2 -> V_10 . V_73 = - V_359 ;
}
if ( V_16 -> V_326 && V_16 -> V_21 == V_22 ) {
V_72 = F_128 ( & V_16 -> V_312 ,
struct V_1 , V_10 . V_327 ) ;
F_118 ( & V_72 -> V_10 . V_310 ) ;
}
F_22 ( & V_16 -> V_44 ) ;
return V_2 -> V_10 . V_73 ;
}
static int F_129 ( struct V_157 * V_158 , struct V_1 * V_2 )
{
int V_45 ;
int V_343 ;
if ( ! V_2 -> V_10 . V_362 ) {
V_158 -> V_162 = V_363 ;
return - V_36 ;
}
F_87 ( V_2 ) ;
if ( F_107 ( V_119 ) ) {
V_158 -> V_162 = V_358 ;
return - V_359 ;
}
F_130 ( & V_2 -> V_68 -> V_10 . V_364 ) ;
F_48 () ;
if ( ! V_2 -> V_68 -> V_10 . V_365 ) {
V_45 = F_131 ( V_2 ) ;
if ( V_45 )
goto V_297;
}
F_132 ( V_119 ) ;
F_133 ( V_119 ) ;
F_134 ( V_119 ) ;
V_2 -> V_10 . V_5 = & V_2 -> V_10 . V_17 -> V_142 ;
V_2 -> V_10 . V_366 = V_119 -> V_367 -> V_368 ;
V_2 -> V_10 . V_26 = V_27 ;
do {
V_45 = F_125 ( V_158 , V_2 ) ;
if ( V_158 -> V_162 == V_177 &&
! ( V_2 -> V_10 . V_31 . V_30 & V_369 ) ) {
V_45 = F_44 ( V_2 ) ;
F_87 ( V_2 ) ;
} else if ( V_45 == V_179 ) {
V_343 = F_45 ( & V_2 -> V_68 -> V_137 ) ;
V_45 = F_135 ( V_158 , V_2 ,
V_2 -> V_10 . V_61 , V_2 -> V_10 . V_62 ) ;
F_47 ( & V_2 -> V_68 -> V_137 , V_343 ) ;
}
} while ( V_45 == V_156 );
V_297:
V_2 -> V_10 . V_26 = V_309 ;
F_136 ( & V_2 -> V_68 -> V_10 . V_364 ) ;
return V_45 ;
}
static inline int F_137 ( unsigned long V_370 )
{
switch ( V_370 ) {
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
static int F_138 ( struct V_371 * V_372 , struct V_373 * V_374 )
{
struct V_375 * V_375 ;
struct V_376 * V_377 = V_372 -> V_378 -> V_379 ;
if ( V_374 -> V_380 >= V_381 )
return V_382 ;
V_375 = F_139 ( V_377 -> V_383 + V_374 -> V_380 ) ;
F_140 ( V_375 ) ;
V_374 -> V_375 = V_375 ;
return 0 ;
}
static int F_141 ( struct V_384 * V_384 , struct V_371 * V_372 )
{
V_372 -> V_385 |= V_386 | V_387 ;
V_372 -> V_388 = & V_389 ;
return 0 ;
}
static int F_142 ( struct V_390 * V_390 , struct V_384 * V_391 )
{
struct V_376 * V_377 = V_391 -> V_379 ;
F_143 ( V_377 ) ;
return 0 ;
}
static long F_144 ( struct V_68 * V_68 ,
struct V_392 * V_73 )
{
long V_393 ;
struct V_376 * V_377 ;
if ( ! F_20 ( V_394 ) ||
! F_20 ( V_395 ) )
return - V_36 ;
if ( ! V_381 )
return - V_36 ;
V_377 = F_145 () ;
if ( ! V_377 )
return - V_298 ;
V_393 = F_146 ( L_17 , & V_396 , V_377 , V_397 | V_398 ) ;
if ( V_393 < 0 )
F_143 ( V_377 ) ;
V_73 -> V_370 = V_381 << V_399 ;
return V_393 ;
}
static void F_147 ( struct V_400 * * V_401 ,
int V_402 )
{
struct V_403 * V_404 = & V_405 [ V_402 ] ;
if ( ! V_404 -> V_406 )
return;
( * V_401 ) -> V_407 = V_404 -> V_406 ;
( * V_401 ) -> V_408 = V_404 -> V_409 ;
( * V_401 ) -> V_410 [ 0 ] . V_407 = V_404 -> V_406 ;
( * V_401 ) -> V_410 [ 0 ] . V_411 = V_404 -> V_412 [ V_402 ] ;
( * V_401 ) ++ ;
}
static int F_148 ( struct V_68 * V_68 ,
struct V_413 * V_414 )
{
struct V_400 * V_401 ;
V_414 -> V_18 = V_415 ;
if ( F_149 ( V_416 ) )
V_414 -> V_18 |= V_417 ;
V_414 -> V_418 = V_419 ;
V_401 = & V_414 -> V_401 [ 0 ] ;
F_147 ( & V_401 , V_420 ) ;
F_147 ( & V_401 , V_421 ) ;
F_147 ( & V_401 , V_422 ) ;
return 0 ;
}
static int F_150 ( struct V_68 * V_68 ,
struct V_423 * log )
{
struct V_424 * V_425 ;
int V_45 ;
unsigned long V_426 ;
F_27 ( & V_68 -> V_427 ) ;
V_45 = - V_36 ;
if ( log -> V_428 >= V_429 )
goto V_297;
V_425 = F_151 ( V_68 -> V_430 , log -> V_428 ) ;
V_45 = - V_148 ;
if ( ! V_425 -> V_431 )
goto V_297;
V_426 = F_152 ( V_425 ) ;
memset ( V_425 -> V_431 , 0 , V_426 ) ;
V_45 = F_153 ( V_68 , V_425 , V_425 -> V_431 ) ;
if ( V_45 )
goto V_297;
V_45 = - V_432 ;
if ( F_154 ( log -> V_431 , V_425 -> V_431 , V_426 ) )
goto V_297;
V_45 = 0 ;
V_297:
F_29 ( & V_68 -> V_427 ) ;
return V_45 ;
}
static void F_155 ( struct V_424 * V_425 )
{
unsigned long * V_433 ;
unsigned long V_194 , V_434 , V_435 ;
struct V_375 * V_375 ;
V_433 = V_425 -> V_10 . V_436 ;
V_434 = V_425 -> V_434 ;
if ( ! V_433 )
return;
for ( V_194 = 0 ; V_194 < V_434 ; V_194 ++ ) {
if ( ! ( V_433 [ V_194 ] & V_437 ) )
continue;
V_435 = V_433 [ V_194 ] >> V_399 ;
V_375 = F_139 ( V_435 ) ;
F_156 ( V_375 ) ;
F_157 ( V_375 ) ;
}
}
static void F_158 ( struct V_424 * free ,
struct V_424 * V_438 )
{
if ( ! V_438 || free -> V_10 . V_439 != V_438 -> V_10 . V_439 ) {
F_159 ( free -> V_10 . V_439 ) ;
free -> V_10 . V_439 = NULL ;
}
if ( ! V_438 || free -> V_10 . V_436 != V_438 -> V_10 . V_436 ) {
F_155 ( free ) ;
F_159 ( free -> V_10 . V_436 ) ;
free -> V_10 . V_436 = NULL ;
}
}
static int F_160 ( struct V_424 * V_428 ,
unsigned long V_434 )
{
V_428 -> V_10 . V_439 = F_161 ( V_434 * sizeof( * V_428 -> V_10 . V_439 ) ) ;
if ( ! V_428 -> V_10 . V_439 )
return - V_298 ;
V_428 -> V_10 . V_436 = NULL ;
return 0 ;
}
static int F_162 ( struct V_68 * V_68 ,
struct V_424 * V_425 ,
struct V_440 * V_441 )
{
unsigned long * V_442 ;
V_442 = V_425 -> V_10 . V_436 ;
if ( ! V_68 -> V_10 . V_443 && ! V_442 && V_425 -> V_434 ) {
V_442 = F_161 ( V_425 -> V_434 * sizeof( unsigned long ) ) ;
if ( ! V_442 )
return - V_298 ;
V_425 -> V_10 . V_436 = V_442 ;
}
return 0 ;
}
static void F_163 ( struct V_68 * V_68 ,
struct V_440 * V_441 ,
const struct V_424 * V_444 )
{
unsigned long V_434 = V_441 -> V_445 >> V_399 ;
struct V_424 * V_425 ;
if ( V_434 && V_444 -> V_434 ) {
V_425 = F_151 ( V_68 -> V_430 , V_441 -> V_428 ) ;
F_153 ( V_68 , V_425 , NULL ) ;
}
}
void F_164 ( struct V_68 * V_68 , unsigned long V_67 , unsigned long V_198 )
{
long int V_174 ;
T_3 V_446 = 0 ;
if ( ( V_68 -> V_10 . V_67 & V_198 ) == V_67 )
return;
V_68 -> V_10 . V_67 = ( V_68 -> V_10 . V_67 & ~ V_198 ) | V_67 ;
for ( V_174 = 0 ; V_174 < V_296 ; ++ V_174 ) {
struct V_15 * V_16 = V_68 -> V_10 . V_311 [ V_174 ] ;
if ( ! V_16 )
continue;
F_21 ( & V_16 -> V_44 ) ;
V_16 -> V_67 = ( V_16 -> V_67 & ~ V_198 ) | V_67 ;
F_22 ( & V_16 -> V_44 ) ;
if ( ++ V_446 >= V_68 -> V_10 . V_314 )
break;
}
}
static void F_165 ( struct V_1 * V_2 )
{
return;
}
static int F_131 ( struct V_1 * V_2 )
{
int V_92 = 0 ;
struct V_68 * V_68 = V_2 -> V_68 ;
struct V_376 * V_377 = NULL ;
unsigned long V_447 ;
struct V_424 * V_425 ;
struct V_371 * V_372 ;
unsigned long V_67 = 0 , V_448 ;
unsigned long V_449 = 0 ;
unsigned long V_450 , V_451 ;
unsigned long V_370 ;
unsigned long V_452 ;
unsigned long * V_433 ;
unsigned long V_174 , V_434 ;
int V_343 ;
F_27 ( & V_68 -> V_44 ) ;
if ( V_68 -> V_10 . V_365 )
goto V_297;
if ( ! V_68 -> V_10 . V_453 ) {
V_92 = F_166 ( V_68 , NULL ) ;
if ( V_92 ) {
F_24 ( L_18 ) ;
goto V_297;
}
}
V_343 = F_45 ( & V_68 -> V_137 ) ;
V_425 = F_167 ( V_68 , 0 ) ;
V_92 = - V_36 ;
if ( ! V_425 || ( V_425 -> V_18 & V_454 ) )
goto V_455;
V_447 = V_425 -> V_456 ;
F_168 ( & V_119 -> V_367 -> V_457 ) ;
V_372 = F_169 ( V_119 -> V_367 , V_447 ) ;
if ( ! V_372 || V_372 -> V_458 > V_447 || ( V_372 -> V_385 & V_459 ) )
goto V_460;
V_450 = F_170 ( V_372 ) ;
V_451 = F_171 ( V_450 ) ;
if ( V_372 -> V_378 && V_372 -> V_378 -> V_461 == & V_396 &&
V_447 == V_372 -> V_458 )
V_377 = V_372 -> V_378 -> V_379 ;
F_172 ( & V_119 -> V_367 -> V_457 ) ;
if ( ! V_377 ) {
V_92 = - V_462 ;
if ( F_20 ( V_395 ) ) {
F_24 ( L_19 ) ;
goto V_455;
}
V_92 = - V_36 ;
if ( ! ( V_450 == 0x1000 || V_450 == 0x10000 ||
V_450 == 0x1000000 ) )
goto V_455;
V_448 = F_173 ( V_450 ) ;
V_68 -> V_10 . V_463 = V_448 | V_464 |
( V_465 << V_466 ) ;
V_449 = V_467 ;
V_67 = V_448 << ( V_468 - 4 ) ;
F_174 ( V_2 , V_425 , V_451 ) ;
} else {
V_370 = V_381 ;
if ( V_370 > V_425 -> V_434 )
V_370 = V_425 -> V_434 ;
V_370 <<= V_399 ;
V_452 = F_137 ( V_370 ) ;
V_92 = - V_36 ;
if ( ( long ) V_452 < 0 ) {
F_24 ( L_20 , V_370 ) ;
goto V_455;
}
F_130 ( & V_377 -> V_469 ) ;
V_68 -> V_10 . V_470 = V_377 ;
if ( F_20 ( V_395 ) ) {
V_449 = ( 1ul << V_471 ) |
( 3ul << V_472 ) | V_473 ;
V_67 = ( ( V_452 >> 2 ) << V_471 ) |
( ( V_452 & 3 ) << V_472 ) ;
V_67 |= ( ( V_377 -> V_383 >> ( 26 - V_399 ) ) & 0xffff )
<< V_474 ;
} else {
V_449 = V_475 | V_476 | V_477 ;
V_67 = V_452 << V_478 ;
V_68 -> V_10 . V_479 = V_377 -> V_383 << V_399 ;
}
F_175 ( L_21 ,
V_377 -> V_383 << V_399 , V_370 , V_67 ) ;
V_434 = V_381 ;
V_451 = F_171 ( V_434 ) ;
V_433 = V_425 -> V_10 . V_436 ;
if ( V_433 ) {
if ( V_434 > V_425 -> V_434 )
V_434 = V_425 -> V_434 ;
F_21 ( & V_68 -> V_10 . V_480 ) ;
for ( V_174 = 0 ; V_174 < V_434 ; ++ V_174 )
V_433 [ V_174 ] = ( ( V_377 -> V_383 + V_174 ) << V_399 ) +
V_451 ;
F_22 ( & V_68 -> V_10 . V_480 ) ;
}
}
F_164 ( V_68 , V_67 , V_449 ) ;
F_43 () ;
V_68 -> V_10 . V_365 = 1 ;
V_92 = 0 ;
V_455:
F_47 ( & V_68 -> V_137 , V_343 ) ;
V_297:
F_29 ( & V_68 -> V_44 ) ;
return V_92 ;
V_460:
F_172 ( & V_119 -> V_367 -> V_457 ) ;
goto V_455;
}
static int F_176 ( struct V_68 * V_68 )
{
unsigned long V_67 , V_481 ;
V_481 = F_177 () ;
if ( ( long ) V_481 < 0 )
return - V_298 ;
V_68 -> V_10 . V_481 = V_481 ;
F_178 ( & V_68 -> V_10 . V_482 ) ;
V_68 -> V_10 . V_470 = NULL ;
V_68 -> V_10 . V_483 = F_71 ( V_484 ) ;
if ( F_20 ( V_395 ) ) {
V_68 -> V_10 . V_485 = 0 ;
V_68 -> V_10 . V_486 = V_67 = F_71 ( V_487 ) ;
V_67 &= ~ ( ( 3 << V_488 ) | ( 0xful << V_489 ) ) ;
V_67 |= ( ( V_481 >> 4 ) << V_488 ) |
( ( V_481 & 0xf ) << V_489 ) ;
} else {
V_68 -> V_10 . V_485 = F_71 ( V_490 ) ;
V_68 -> V_10 . V_486 = V_67 = F_71 ( V_491 ) ;
V_67 &= V_492 | V_493 ;
V_67 |= ( 4UL << V_494 ) | V_495 |
V_475 | V_496 ;
V_68 -> V_10 . V_463 = V_464 |
( V_465 << V_466 ) ;
if ( F_20 ( V_43 ) )
V_67 |= V_497 ;
}
V_68 -> V_10 . V_67 = V_67 ;
V_68 -> V_10 . V_443 = ! ! F_20 ( V_35 ) ;
F_72 ( & V_68 -> V_10 . V_480 ) ;
F_179 () ;
return 0 ;
}
static void F_180 ( struct V_68 * V_68 )
{
long int V_174 ;
for ( V_174 = 0 ; V_174 < V_296 ; ++ V_174 )
F_181 ( V_68 -> V_10 . V_311 [ V_174 ] ) ;
V_68 -> V_10 . V_314 = 0 ;
}
static void F_182 ( struct V_68 * V_68 )
{
F_183 () ;
F_180 ( V_68 ) ;
if ( V_68 -> V_10 . V_470 ) {
F_143 ( V_68 -> V_10 . V_470 ) ;
V_68 -> V_10 . V_470 = NULL ;
}
F_184 ( V_68 ) ;
}
static int F_185 ( struct V_157 * V_158 , struct V_1 * V_2 ,
unsigned int V_498 , int * V_499 )
{
return V_500 ;
}
static int F_186 ( struct V_1 * V_2 , int V_501 ,
T_4 V_502 )
{
return V_500 ;
}
static int F_187 ( struct V_1 * V_2 , int V_501 ,
T_4 * V_502 )
{
return V_500 ;
}
static int F_188 ( void )
{
if ( ! F_20 ( V_394 ) )
return - V_503 ;
return 0 ;
}
static long F_189 ( struct V_384 * V_391 ,
unsigned int V_504 , unsigned long V_505 )
{
struct V_68 * V_68 V_506 = V_391 -> V_379 ;
void T_5 * V_507 = ( void T_5 * ) V_505 ;
long V_45 ;
switch ( V_504 ) {
case V_508 : {
struct V_392 V_470 ;
struct V_68 * V_68 = V_391 -> V_379 ;
V_45 = F_144 ( V_68 , & V_470 ) ;
if ( V_45 >= 0 && F_154 ( V_507 , & V_470 , sizeof( V_470 ) ) )
V_45 = - V_432 ;
break;
}
case V_509 : {
T_3 V_510 ;
V_45 = - V_432 ;
if ( F_190 ( V_510 , ( T_3 T_5 * ) V_507 ) )
break;
V_45 = F_191 ( V_68 , & V_510 ) ;
if ( V_45 )
break;
V_45 = - V_432 ;
if ( F_192 ( V_510 , ( T_3 T_5 * ) V_507 ) )
break;
V_45 = 0 ;
break;
}
case V_511 : {
struct V_512 V_513 ;
V_45 = - V_432 ;
if ( F_193 ( & V_513 , V_507 , sizeof( V_513 ) ) )
break;
V_45 = F_194 ( V_68 , & V_513 ) ;
break;
}
default:
V_45 = - V_514 ;
}
return V_45 ;
}
static int F_195 ( void )
{
int V_45 ;
V_45 = F_188 () ;
if ( V_45 < 0 )
return V_45 ;
V_515 . V_516 = V_517 ;
V_518 = & V_515 ;
V_45 = F_196 () ;
return V_45 ;
}
static void F_197 ( void )
{
V_518 = NULL ;
}
