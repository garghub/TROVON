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
case V_239 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_240 ) ;
break;
case V_241 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_242 ) ;
break;
case V_243 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_244 ) ;
break;
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
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_17 -> V_252 ) ;
break;
case V_253 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_254 ) ;
break;
case V_255 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_256 ) ;
break;
case V_257 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_258 ) ;
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
F_21 ( & V_2 -> V_10 . V_83 ) ;
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_75 . V_84 ) ;
F_22 ( & V_2 -> V_10 . V_83 ) ;
break;
case V_276 :
F_21 ( & V_2 -> V_10 . V_83 ) ;
V_206 -> V_277 . V_80 = V_2 -> V_10 . V_107 . V_84 ;
V_206 -> V_277 . V_101 = V_2 -> V_10 . V_107 . V_81 ;
F_22 ( & V_2 -> V_10 . V_83 ) ;
break;
case V_278 :
F_21 ( & V_2 -> V_10 . V_83 ) ;
V_206 -> V_277 . V_80 = V_2 -> V_10 . V_106 . V_84 ;
V_206 -> V_277 . V_101 = V_2 -> V_10 . V_106 . V_81 ;
F_22 ( & V_2 -> V_10 . V_83 ) ;
break;
case V_279 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_17 -> V_128 ) ;
break;
case V_280 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_17 -> V_67 ) ;
break;
case V_281 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_282 ) ;
break;
#ifdef F_64
case V_283 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_284 ) ;
break;
case V_285 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_286 ) ;
break;
case V_287 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_288 ) ;
break;
case V_289 ... V_290 :
V_174 = V_71 - V_289 ;
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_291 [ V_174 ] ) ;
break;
case V_292 ... V_293 :
{
int V_194 ;
V_174 = V_71 - V_292 ;
if ( V_174 < 32 )
for ( V_194 = 0 ; V_194 < V_294 ; V_194 ++ )
V_206 -> V_295 [ V_194 ] = V_2 -> V_10 . V_296 . V_297 [ V_174 ] [ V_194 ] ;
else {
if ( F_20 ( V_298 ) )
V_206 -> V_299 = V_2 -> V_10 . V_300 . V_301 [ V_174 - 32 ] ;
else
V_45 = - V_302 ;
}
break;
}
case V_303 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_304 ) ;
break;
case V_305 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_306 ) ;
break;
case V_307 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_308 ) ;
break;
case V_309 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_296 . V_310 ) ;
break;
case V_311 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_312 ) ;
break;
case V_313 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_314 ) ;
break;
case V_315 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_316 ) ;
break;
case V_317 :
if ( F_20 ( V_298 ) )
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_300 . V_318 . V_189 [ 3 ] ) ;
else
V_45 = - V_302 ;
break;
case V_319 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_320 ) ;
break;
case V_321 :
* V_206 = F_63 ( V_71 , V_2 -> V_10 . V_322 ) ;
break;
#endif
case V_323 :
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
V_2 -> V_10 . V_211 = F_66 ( V_71 , * V_206 ) & ~ V_324 ;
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
case V_239 :
V_2 -> V_10 . V_240 = F_66 ( V_71 , * V_206 ) ;
break;
case V_241 :
V_2 -> V_10 . V_242 = F_66 ( V_71 , * V_206 ) ;
break;
case V_243 :
V_2 -> V_10 . V_244 = F_66 ( V_71 , * V_206 ) ;
break;
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
V_2 -> V_10 . V_17 -> V_252 = F_66 ( V_71 , * V_206 ) ;
break;
case V_253 :
V_2 -> V_10 . V_254 = F_66 ( V_71 , * V_206 ) ;
break;
case V_255 :
V_2 -> V_10 . V_256 = F_66 ( V_71 , * V_206 ) & ~ V_325 ;
break;
case V_257 :
V_2 -> V_10 . V_258 = F_66 ( V_71 , * V_206 ) ;
if ( ( V_2 -> V_10 . V_258 & V_326 ) == V_327 )
V_2 -> V_10 . V_258 &= ~ V_326 ;
break;
case V_259 :
V_2 -> V_10 . V_260 = F_66 ( V_71 , * V_206 ) ;
break;
case V_261 :
V_2 -> V_10 . V_262 = F_66 ( V_71 , * V_206 ) ;
break;
case V_263 :
V_2 -> V_10 . V_264 = F_66 ( V_71 , * V_206 ) ;
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
V_80 = F_66 ( V_71 , * V_206 ) ;
V_45 = - V_36 ;
if ( ! V_80 && ( V_2 -> V_10 . V_107 . V_84 ||
V_2 -> V_10 . V_106 . V_84 ) )
break;
V_45 = F_31 ( V_2 , & V_2 -> V_10 . V_75 , V_80 , sizeof( struct V_74 ) ) ;
break;
case V_276 :
V_80 = V_206 -> V_277 . V_80 ;
V_81 = V_206 -> V_277 . V_101 ;
V_45 = - V_36 ;
if ( V_80 && ! V_2 -> V_10 . V_75 . V_84 )
break;
V_45 = F_31 ( V_2 , & V_2 -> V_10 . V_107 , V_80 , V_81 ) ;
break;
case V_278 :
V_80 = V_206 -> V_277 . V_80 ;
V_81 = V_206 -> V_277 . V_101 ;
V_45 = - V_36 ;
if ( V_80 && ( V_81 < sizeof( struct V_104 ) ||
! V_2 -> V_10 . V_75 . V_84 ) )
break;
V_81 -= V_81 % sizeof( struct V_104 ) ;
V_45 = F_31 ( V_2 , & V_2 -> V_10 . V_106 , V_80 , V_81 ) ;
break;
case V_279 :
V_2 -> V_10 . V_17 -> V_128 =
F_67 ( F_66 ( V_71 , * V_206 ) , 1UL << 24 ) ;
break;
case V_280 :
F_61 ( V_2 , F_66 ( V_71 , * V_206 ) ) ;
break;
case V_281 :
V_2 -> V_10 . V_282 = F_66 ( V_71 , * V_206 ) ;
break;
#ifdef F_64
case V_283 :
V_2 -> V_10 . V_284 = F_66 ( V_71 , * V_206 ) ;
break;
case V_285 :
V_2 -> V_10 . V_286 = F_66 ( V_71 , * V_206 ) ;
break;
case V_287 :
V_2 -> V_10 . V_288 = F_66 ( V_71 , * V_206 ) ;
break;
case V_289 ... V_290 :
V_174 = V_71 - V_289 ;
V_2 -> V_10 . V_291 [ V_174 ] = F_66 ( V_71 , * V_206 ) ;
break;
case V_292 ... V_293 :
{
int V_194 ;
V_174 = V_71 - V_292 ;
if ( V_174 < 32 )
for ( V_194 = 0 ; V_194 < V_294 ; V_194 ++ )
V_2 -> V_10 . V_296 . V_297 [ V_174 ] [ V_194 ] = V_206 -> V_295 [ V_194 ] ;
else
if ( F_20 ( V_298 ) )
V_2 -> V_10 . V_300 . V_301 [ V_174 - 32 ] = V_206 -> V_299 ;
else
V_45 = - V_302 ;
break;
}
case V_303 :
V_2 -> V_10 . V_304 = F_66 ( V_71 , * V_206 ) ;
break;
case V_305 :
V_2 -> V_10 . V_306 = F_66 ( V_71 , * V_206 ) ;
break;
case V_307 :
V_2 -> V_10 . V_308 = F_66 ( V_71 , * V_206 ) ;
break;
case V_309 :
V_2 -> V_10 . V_296 . V_310 = F_66 ( V_71 , * V_206 ) ;
break;
case V_311 :
V_2 -> V_10 . V_312 = F_66 ( V_71 , * V_206 ) ;
break;
case V_313 :
V_2 -> V_10 . V_314 = F_66 ( V_71 , * V_206 ) ;
break;
case V_315 :
V_2 -> V_10 . V_316 = F_66 ( V_71 , * V_206 ) ;
break;
case V_317 :
if ( F_20 ( V_298 ) )
V_2 -> V_10 . V_301 . V_318 . V_189 [ 3 ] = F_66 ( V_71 , * V_206 ) ;
else
V_45 = - V_302 ;
break;
case V_319 :
V_2 -> V_10 . V_320 = F_66 ( V_71 , * V_206 ) ;
break;
case V_321 :
V_2 -> V_10 . V_322 = F_66 ( V_71 , * V_206 ) ;
break;
#endif
case V_323 :
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
int V_328 ;
struct V_15 * V_17 ;
V_328 = V_71 / V_329 ;
if ( V_328 >= V_330 )
goto V_331;
V_92 = - V_332 ;
V_2 = F_69 ( V_333 , V_334 ) ;
if ( ! V_2 )
goto V_331;
V_92 = F_70 ( V_2 , V_68 , V_71 ) ;
if ( V_92 )
goto V_335;
V_2 -> V_10 . V_336 = & V_2 -> V_10 . V_31 ;
V_2 -> V_10 . V_224 [ 0 ] = V_337 ;
V_2 -> V_10 . V_338 = V_339 ;
F_18 ( V_2 , F_71 ( V_340 ) ) ;
F_72 ( & V_2 -> V_10 . V_83 ) ;
F_72 ( & V_2 -> V_10 . V_19 ) ;
V_2 -> V_10 . V_28 = V_24 ;
V_2 -> V_10 . V_200 = V_341 | V_342 ;
F_73 ( V_2 ) ;
V_2 -> V_10 . V_26 = V_343 ;
F_74 ( & V_2 -> V_10 . V_344 ) ;
F_27 ( & V_68 -> V_44 ) ;
V_17 = V_68 -> V_10 . V_345 [ V_328 ] ;
if ( ! V_17 ) {
V_17 = F_75 ( sizeof( struct V_15 ) , V_334 ) ;
if ( V_17 ) {
F_76 ( & V_17 -> V_346 ) ;
F_72 ( & V_17 -> V_44 ) ;
F_74 ( & V_17 -> V_142 ) ;
V_17 -> V_23 = V_24 ;
V_17 -> V_67 = V_68 -> V_10 . V_67 ;
V_17 -> V_347 = V_328 * V_329 ;
V_17 -> V_68 = V_68 ;
}
V_68 -> V_10 . V_345 [ V_328 ] = V_17 ;
V_68 -> V_10 . V_348 ++ ;
}
F_29 ( & V_68 -> V_44 ) ;
if ( ! V_17 )
goto V_335;
F_21 ( & V_17 -> V_44 ) ;
++ V_17 -> V_349 ;
F_22 ( & V_17 -> V_44 ) ;
V_2 -> V_10 . V_17 = V_17 ;
V_2 -> V_10 . V_11 = V_2 -> V_46 - V_17 -> V_347 ;
V_2 -> V_10 . V_350 = V_351 ;
F_77 ( V_2 ) ;
return V_2 ;
V_335:
F_78 ( V_333 , V_2 ) ;
V_331:
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
F_78 ( V_333 , V_2 ) ;
}
static int F_83 ( struct V_1 * V_2 )
{
return 1 ;
}
static void F_84 ( struct V_1 * V_2 )
{
unsigned long V_352 , V_116 ;
V_116 = F_85 () ;
if ( V_116 > V_2 -> V_10 . V_353 ) {
F_86 ( V_2 ) ;
F_87 ( V_2 ) ;
return;
}
V_352 = ( V_2 -> V_10 . V_353 - V_116 ) * V_354
/ V_355 ;
F_88 ( & V_2 -> V_10 . V_356 , F_89 ( 0 , V_352 ) ,
V_357 ) ;
V_2 -> V_10 . V_358 = 1 ;
}
static void F_17 ( struct V_1 * V_2 )
{
V_2 -> V_10 . V_141 = 0 ;
if ( V_2 -> V_10 . V_358 ) {
F_90 ( & V_2 -> V_10 . V_356 ) ;
V_2 -> V_10 . V_358 = 0 ;
}
}
static void F_91 ( struct V_15 * V_16 ,
struct V_1 * V_2 )
{
T_2 V_116 ;
if ( V_2 -> V_10 . V_26 != V_359 )
return;
F_39 ( & V_2 -> V_10 . V_19 ) ;
V_116 = F_13 () ;
V_2 -> V_10 . V_29 += F_38 ( V_16 , V_116 ) -
V_2 -> V_10 . V_123 ;
V_2 -> V_10 . V_28 = V_116 ;
V_2 -> V_10 . V_26 = V_27 ;
F_40 ( & V_2 -> V_10 . V_19 ) ;
-- V_16 -> V_360 ;
F_92 ( & V_2 -> V_10 . V_361 ) ;
}
static int F_93 ( int V_4 )
{
struct V_362 * V_363 ;
long V_364 = 1000 ;
V_363 = & V_12 [ V_4 ] ;
V_363 -> V_13 . V_365 = 1 ;
V_363 -> V_13 . V_1 = NULL ;
F_48 () ;
while ( V_363 -> V_13 . V_366 == V_367 ) {
if ( -- V_364 <= 0 ) {
F_24 ( L_15 , V_4 ) ;
return - V_368 ;
}
F_94 ( 1 ) ;
}
return 0 ;
}
static void F_95 ( int V_4 )
{
struct V_362 * V_363 ;
V_363 = & V_12 [ V_4 ] ;
V_363 -> V_13 . V_365 = 0 ;
V_363 -> V_13 . V_1 = NULL ;
}
static void F_96 ( struct V_1 * V_2 )
{
int V_4 ;
struct V_362 * V_363 ;
struct V_15 * V_16 = V_2 -> V_10 . V_17 ;
if ( V_2 -> V_10 . V_358 ) {
F_90 ( & V_2 -> V_10 . V_356 ) ;
V_2 -> V_10 . V_358 = 0 ;
}
V_4 = V_16 -> V_126 + V_2 -> V_10 . V_11 ;
V_363 = & V_12 [ V_4 ] ;
V_363 -> V_13 . V_1 = V_2 ;
V_363 -> V_13 . V_369 = V_16 ;
V_363 -> V_13 . V_11 = V_2 -> V_10 . V_11 ;
V_2 -> V_4 = V_16 -> V_126 ;
F_43 () ;
#if F_97 ( F_6 ) && F_97 ( V_370 )
if ( V_4 != F_98 () ) {
F_7 ( V_4 ) ;
if ( V_2 -> V_10 . V_11 )
++ V_16 -> V_371 ;
}
#endif
}
static void F_99 ( struct V_15 * V_16 )
{
int V_174 ;
F_100 () ;
V_174 = 0 ;
while ( V_16 -> V_372 < V_16 -> V_371 ) {
if ( ++ V_174 >= 1000000 ) {
F_24 ( L_16 ,
V_16 -> V_372 , V_16 -> V_371 ) ;
break;
}
F_101 () ;
}
F_102 () ;
}
static int F_103 ( void )
{
int V_4 = F_98 () ;
int V_373 = F_104 ( V_4 ) ;
if ( V_373 )
return 0 ;
while ( ++ V_373 < V_329 )
if ( F_8 ( V_4 + V_373 ) )
return 0 ;
for ( V_373 = 1 ; V_373 < V_329 ; ++ V_373 ) {
if ( F_93 ( V_4 + V_373 ) ) {
do {
F_95 ( V_4 + V_373 ) ;
} while ( -- V_373 > 0 );
return 0 ;
}
}
return 1 ;
}
static void F_105 ( struct V_15 * V_16 )
{
struct V_1 * V_2 , * V_374 ;
long V_73 ;
T_2 V_116 ;
int V_174 , V_375 ;
int V_376 ;
struct V_1 * V_377 [ V_329 ] ;
V_375 = 0 ;
F_106 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( F_107 ( V_2 -> V_10 . V_118 ) )
return;
if ( V_2 -> V_10 . V_75 . V_85 ||
V_2 -> V_10 . V_107 . V_85 ||
V_2 -> V_10 . V_106 . V_85 )
V_377 [ V_375 ++ ] = V_2 ;
}
V_16 -> V_371 = 0 ;
V_16 -> V_372 = 0 ;
V_16 -> V_378 = 0 ;
V_16 -> V_21 = V_379 ;
V_16 -> V_380 = 0 ;
V_16 -> V_381 = 0 ;
if ( V_375 ) {
F_22 ( & V_16 -> V_44 ) ;
for ( V_174 = 0 ; V_174 < V_375 ; ++ V_174 )
F_37 ( V_377 [ V_174 ] ) ;
F_21 ( & V_16 -> V_44 ) ;
}
if ( V_329 > 1 && ! F_103 () ) {
F_106 (vcpu, &vc->runnable_threads, arch.run_list)
V_2 -> V_10 . V_73 = - V_368 ;
goto V_331;
}
V_16 -> V_126 = F_98 () ;
F_106 (vcpu, &vc->runnable_threads, arch.run_list) {
F_96 ( V_2 ) ;
F_41 ( V_2 , V_16 ) ;
}
F_108 () -> V_13 . V_369 = V_16 ;
F_108 () -> V_13 . V_11 = 0 ;
V_16 -> V_21 = V_382 ;
F_109 () ;
F_22 ( & V_16 -> V_44 ) ;
F_110 () ;
V_376 = F_45 ( & V_16 -> V_68 -> V_137 ) ;
F_111 () ;
F_21 ( & V_16 -> V_44 ) ;
F_106 (vcpu, &vc->runnable_threads, arch.run_list)
V_2 -> V_4 = - 1 ;
if ( V_16 -> V_372 < V_16 -> V_371 )
F_99 ( V_16 ) ;
for ( V_174 = 0 ; V_174 < V_329 ; ++ V_174 )
F_95 ( V_16 -> V_126 + V_174 ) ;
V_16 -> V_21 = V_383 ;
F_22 ( & V_16 -> V_44 ) ;
F_47 ( & V_16 -> V_68 -> V_137 , V_376 ) ;
F_48 () ;
F_112 () ;
F_113 () ;
F_114 () ;
F_21 ( & V_16 -> V_44 ) ;
V_116 = F_85 () ;
F_106 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( V_116 < V_2 -> V_10 . V_353 &&
F_115 ( V_2 ) )
F_116 ( V_2 ) ;
V_73 = V_156 ;
if ( V_2 -> V_10 . V_48 )
V_73 = F_55 ( V_2 -> V_10 . V_157 , V_2 ,
V_2 -> V_10 . V_118 ) ;
V_2 -> V_10 . V_73 = V_73 ;
V_2 -> V_10 . V_48 = 0 ;
if ( V_2 -> V_10 . V_141 ) {
if ( ! F_117 ( V_73 ) )
F_17 ( V_2 ) ;
else
F_84 ( V_2 ) ;
}
}
V_331:
V_16 -> V_21 = V_22 ;
F_118 (vcpu, vnext, &vc->runnable_threads,
arch.run_list) {
if ( ! F_117 ( V_2 -> V_10 . V_73 ) ) {
F_91 ( V_16 , V_2 ) ;
F_119 ( & V_2 -> V_10 . V_344 ) ;
}
}
}
static void F_120 ( struct V_1 * V_2 , int V_384 )
{
F_121 ( V_385 ) ;
F_122 ( & V_2 -> V_10 . V_344 , & V_385 , V_384 ) ;
if ( V_2 -> V_10 . V_26 == V_359 )
F_123 () ;
F_124 ( & V_2 -> V_10 . V_344 , & V_385 ) ;
}
static void F_125 ( struct V_15 * V_16 )
{
F_121 ( V_385 ) ;
F_122 ( & V_16 -> V_142 , & V_385 , V_386 ) ;
V_16 -> V_21 = V_387 ;
F_22 ( & V_16 -> V_44 ) ;
F_123 () ;
F_124 ( & V_16 -> V_142 , & V_385 ) ;
F_21 ( & V_16 -> V_44 ) ;
V_16 -> V_21 = V_22 ;
}
static int F_126 ( struct V_157 * V_157 , struct V_1 * V_2 )
{
int V_388 ;
struct V_15 * V_16 ;
struct V_1 * V_72 , * V_389 ;
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
V_2 -> V_10 . V_26 = V_359 ;
V_2 -> V_10 . V_28 = V_24 ;
F_127 ( & V_2 -> V_10 . V_361 , & V_16 -> V_346 ) ;
++ V_16 -> V_360 ;
if ( ! F_107 ( V_119 ) ) {
if ( V_16 -> V_21 == V_382 &&
F_128 ( V_16 ) == 0 ) {
F_41 ( V_2 , V_16 ) ;
F_96 ( V_2 ) ;
} else if ( V_16 -> V_21 == V_387 ) {
F_119 ( & V_16 -> V_142 ) ;
}
}
while ( V_2 -> V_10 . V_26 == V_359 &&
! F_107 ( V_119 ) ) {
if ( V_16 -> V_21 != V_22 ) {
F_22 ( & V_16 -> V_44 ) ;
F_120 ( V_2 , V_386 ) ;
F_21 ( & V_16 -> V_44 ) ;
continue;
}
F_118 (v, vn, &vc->runnable_threads,
arch.run_list) {
F_87 ( V_72 ) ;
if ( F_107 ( V_72 -> V_10 . V_118 ) ) {
F_91 ( V_16 , V_72 ) ;
V_72 -> V_6 . V_390 ++ ;
V_72 -> V_10 . V_157 -> V_162 = V_391 ;
V_72 -> V_10 . V_73 = - V_392 ;
F_119 ( & V_72 -> V_10 . V_344 ) ;
}
}
if ( ! V_16 -> V_360 || V_2 -> V_10 . V_26 != V_359 )
break;
V_16 -> V_20 = V_2 ;
V_388 = 0 ;
F_106 (v, &vc->runnable_threads, arch.run_list) {
if ( ! V_72 -> V_10 . V_393 )
V_388 += V_72 -> V_10 . V_141 ;
else
V_72 -> V_10 . V_141 = 0 ;
}
if ( V_388 == V_16 -> V_360 )
F_125 ( V_16 ) ;
else
F_105 ( V_16 ) ;
V_16 -> V_20 = NULL ;
}
while ( V_2 -> V_10 . V_26 == V_359 &&
( V_16 -> V_21 == V_382 ||
V_16 -> V_21 == V_383 ) ) {
F_22 ( & V_16 -> V_44 ) ;
F_120 ( V_2 , V_394 ) ;
F_21 ( & V_16 -> V_44 ) ;
}
if ( V_2 -> V_10 . V_26 == V_359 ) {
F_91 ( V_16 , V_2 ) ;
V_2 -> V_6 . V_390 ++ ;
V_157 -> V_162 = V_391 ;
V_2 -> V_10 . V_73 = - V_392 ;
}
if ( V_16 -> V_360 && V_16 -> V_21 == V_22 ) {
V_72 = F_129 ( & V_16 -> V_346 ,
struct V_1 , V_10 . V_361 ) ;
F_119 ( & V_72 -> V_10 . V_344 ) ;
}
F_22 ( & V_16 -> V_44 ) ;
return V_2 -> V_10 . V_73 ;
}
static int F_130 ( struct V_157 * V_158 , struct V_1 * V_2 )
{
int V_45 ;
int V_376 ;
if ( ! V_2 -> V_10 . V_395 ) {
V_158 -> V_162 = V_396 ;
return - V_36 ;
}
F_87 ( V_2 ) ;
if ( F_107 ( V_119 ) ) {
V_158 -> V_162 = V_391 ;
return - V_392 ;
}
F_131 ( & V_2 -> V_68 -> V_10 . V_397 ) ;
F_48 () ;
if ( ! V_2 -> V_68 -> V_10 . V_398 ) {
V_45 = F_132 ( V_2 ) ;
if ( V_45 )
goto V_331;
}
F_133 ( V_119 ) ;
F_134 ( V_119 ) ;
F_135 ( V_119 ) ;
V_2 -> V_10 . V_5 = & V_2 -> V_10 . V_17 -> V_142 ;
V_2 -> V_10 . V_399 = V_119 -> V_400 -> V_401 ;
V_2 -> V_10 . V_26 = V_27 ;
do {
V_45 = F_126 ( V_158 , V_2 ) ;
if ( V_158 -> V_162 == V_177 &&
! ( V_2 -> V_10 . V_31 . V_30 & V_402 ) ) {
V_45 = F_44 ( V_2 ) ;
F_87 ( V_2 ) ;
} else if ( V_45 == V_179 ) {
V_376 = F_45 ( & V_2 -> V_68 -> V_137 ) ;
V_45 = F_136 ( V_158 , V_2 ,
V_2 -> V_10 . V_61 , V_2 -> V_10 . V_62 ) ;
F_47 ( & V_2 -> V_68 -> V_137 , V_376 ) ;
}
} while ( F_117 ( V_45 ) );
V_331:
V_2 -> V_10 . V_26 = V_343 ;
F_137 ( & V_2 -> V_68 -> V_10 . V_397 ) ;
return V_45 ;
}
static inline int F_138 ( unsigned long V_403 )
{
switch ( V_403 ) {
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
static int F_139 ( struct V_404 * V_405 , struct V_406 * V_407 )
{
struct V_408 * V_408 ;
struct V_409 * V_410 = V_405 -> V_411 -> V_412 ;
if ( V_407 -> V_413 >= V_414 )
return V_415 ;
V_408 = F_140 ( V_410 -> V_416 + V_407 -> V_413 ) ;
F_141 ( V_408 ) ;
V_407 -> V_408 = V_408 ;
return 0 ;
}
static int F_142 ( struct V_417 * V_417 , struct V_404 * V_405 )
{
V_405 -> V_418 |= V_419 | V_420 ;
V_405 -> V_421 = & V_422 ;
return 0 ;
}
static int F_143 ( struct V_423 * V_423 , struct V_417 * V_424 )
{
struct V_409 * V_410 = V_424 -> V_412 ;
F_144 ( V_410 ) ;
return 0 ;
}
static long F_145 ( struct V_68 * V_68 ,
struct V_425 * V_73 )
{
long V_426 ;
struct V_409 * V_410 ;
if ( ! F_20 ( V_427 ) ||
! F_20 ( V_428 ) )
return - V_36 ;
if ( ! V_414 )
return - V_36 ;
V_410 = F_146 () ;
if ( ! V_410 )
return - V_332 ;
V_426 = F_147 ( L_17 , & V_429 , V_410 , V_430 | V_431 ) ;
if ( V_426 < 0 )
F_144 ( V_410 ) ;
V_73 -> V_403 = V_414 << V_432 ;
return V_426 ;
}
static void F_148 ( struct V_433 * * V_434 ,
int V_435 )
{
struct V_436 * V_437 = & V_438 [ V_435 ] ;
if ( ! V_437 -> V_439 )
return;
( * V_434 ) -> V_440 = V_437 -> V_439 ;
( * V_434 ) -> V_441 = V_437 -> V_442 ;
( * V_434 ) -> V_443 [ 0 ] . V_440 = V_437 -> V_439 ;
( * V_434 ) -> V_443 [ 0 ] . V_444 = V_437 -> V_445 [ V_435 ] ;
( * V_434 ) ++ ;
}
static int F_149 ( struct V_68 * V_68 ,
struct V_446 * V_447 )
{
struct V_433 * V_434 ;
V_447 -> V_18 = V_448 ;
if ( F_150 ( V_449 ) )
V_447 -> V_18 |= V_450 ;
V_447 -> V_451 = V_452 ;
V_434 = & V_447 -> V_434 [ 0 ] ;
F_148 ( & V_434 , V_453 ) ;
F_148 ( & V_434 , V_454 ) ;
F_148 ( & V_434 , V_455 ) ;
return 0 ;
}
static int F_151 ( struct V_68 * V_68 ,
struct V_456 * log )
{
struct V_457 * V_458 ;
int V_45 ;
unsigned long V_459 ;
F_27 ( & V_68 -> V_460 ) ;
V_45 = - V_36 ;
if ( log -> V_461 >= V_462 )
goto V_331;
V_458 = F_152 ( V_68 -> V_463 , log -> V_461 ) ;
V_45 = - V_148 ;
if ( ! V_458 -> V_464 )
goto V_331;
V_459 = F_153 ( V_458 ) ;
memset ( V_458 -> V_464 , 0 , V_459 ) ;
V_45 = F_154 ( V_68 , V_458 , V_458 -> V_464 ) ;
if ( V_45 )
goto V_331;
V_45 = - V_465 ;
if ( F_155 ( log -> V_464 , V_458 -> V_464 , V_459 ) )
goto V_331;
V_45 = 0 ;
V_331:
F_29 ( & V_68 -> V_460 ) ;
return V_45 ;
}
static void F_156 ( struct V_457 * V_458 )
{
unsigned long * V_466 ;
unsigned long V_194 , V_467 , V_468 ;
struct V_408 * V_408 ;
V_466 = V_458 -> V_10 . V_469 ;
V_467 = V_458 -> V_467 ;
if ( ! V_466 )
return;
for ( V_194 = 0 ; V_194 < V_467 ; V_194 ++ ) {
if ( ! ( V_466 [ V_194 ] & V_470 ) )
continue;
V_468 = V_466 [ V_194 ] >> V_432 ;
V_408 = F_140 ( V_468 ) ;
F_157 ( V_408 ) ;
F_158 ( V_408 ) ;
}
}
static void F_159 ( struct V_457 * free ,
struct V_457 * V_471 )
{
if ( ! V_471 || free -> V_10 . V_472 != V_471 -> V_10 . V_472 ) {
F_160 ( free -> V_10 . V_472 ) ;
free -> V_10 . V_472 = NULL ;
}
if ( ! V_471 || free -> V_10 . V_469 != V_471 -> V_10 . V_469 ) {
F_156 ( free ) ;
F_160 ( free -> V_10 . V_469 ) ;
free -> V_10 . V_469 = NULL ;
}
}
static int F_161 ( struct V_457 * V_461 ,
unsigned long V_467 )
{
V_461 -> V_10 . V_472 = F_162 ( V_467 * sizeof( * V_461 -> V_10 . V_472 ) ) ;
if ( ! V_461 -> V_10 . V_472 )
return - V_332 ;
V_461 -> V_10 . V_469 = NULL ;
return 0 ;
}
static int F_163 ( struct V_68 * V_68 ,
struct V_457 * V_458 ,
struct V_473 * V_474 )
{
unsigned long * V_475 ;
V_475 = V_458 -> V_10 . V_469 ;
if ( ! V_68 -> V_10 . V_476 && ! V_475 && V_458 -> V_467 ) {
V_475 = F_162 ( V_458 -> V_467 * sizeof( unsigned long ) ) ;
if ( ! V_475 )
return - V_332 ;
V_458 -> V_10 . V_469 = V_475 ;
}
return 0 ;
}
static void F_164 ( struct V_68 * V_68 ,
struct V_473 * V_474 ,
const struct V_457 * V_477 )
{
unsigned long V_467 = V_474 -> V_478 >> V_432 ;
struct V_457 * V_458 ;
if ( V_467 && V_477 -> V_467 ) {
V_458 = F_152 ( V_68 -> V_463 , V_474 -> V_461 ) ;
F_154 ( V_68 , V_458 , NULL ) ;
}
}
void F_165 ( struct V_68 * V_68 , unsigned long V_67 , unsigned long V_198 )
{
long int V_174 ;
T_3 V_479 = 0 ;
if ( ( V_68 -> V_10 . V_67 & V_198 ) == V_67 )
return;
V_68 -> V_10 . V_67 = ( V_68 -> V_10 . V_67 & ~ V_198 ) | V_67 ;
for ( V_174 = 0 ; V_174 < V_330 ; ++ V_174 ) {
struct V_15 * V_16 = V_68 -> V_10 . V_345 [ V_174 ] ;
if ( ! V_16 )
continue;
F_21 ( & V_16 -> V_44 ) ;
V_16 -> V_67 = ( V_16 -> V_67 & ~ V_198 ) | V_67 ;
F_22 ( & V_16 -> V_44 ) ;
if ( ++ V_479 >= V_68 -> V_10 . V_348 )
break;
}
}
static void F_166 ( struct V_1 * V_2 )
{
return;
}
static int F_132 ( struct V_1 * V_2 )
{
int V_92 = 0 ;
struct V_68 * V_68 = V_2 -> V_68 ;
struct V_409 * V_410 = NULL ;
unsigned long V_480 ;
struct V_457 * V_458 ;
struct V_404 * V_405 ;
unsigned long V_67 = 0 , V_481 ;
unsigned long V_482 = 0 ;
unsigned long V_483 , V_484 ;
unsigned long V_403 ;
unsigned long V_485 ;
unsigned long * V_466 ;
unsigned long V_174 , V_467 ;
int V_376 ;
F_27 ( & V_68 -> V_44 ) ;
if ( V_68 -> V_10 . V_398 )
goto V_331;
if ( ! V_68 -> V_10 . V_486 ) {
V_92 = F_167 ( V_68 , NULL ) ;
if ( V_92 ) {
F_24 ( L_18 ) ;
goto V_331;
}
}
V_376 = F_45 ( & V_68 -> V_137 ) ;
V_458 = F_168 ( V_68 , 0 ) ;
V_92 = - V_36 ;
if ( ! V_458 || ( V_458 -> V_18 & V_487 ) )
goto V_488;
V_480 = V_458 -> V_489 ;
F_169 ( & V_119 -> V_400 -> V_490 ) ;
V_405 = F_170 ( V_119 -> V_400 , V_480 ) ;
if ( ! V_405 || V_405 -> V_491 > V_480 || ( V_405 -> V_418 & V_492 ) )
goto V_493;
V_483 = F_171 ( V_405 ) ;
V_484 = F_172 ( V_483 ) ;
if ( V_405 -> V_411 && V_405 -> V_411 -> V_494 == & V_429 &&
V_480 == V_405 -> V_491 )
V_410 = V_405 -> V_411 -> V_412 ;
F_173 ( & V_119 -> V_400 -> V_490 ) ;
if ( ! V_410 ) {
V_92 = - V_495 ;
if ( F_20 ( V_428 ) ) {
F_24 ( L_19 ) ;
goto V_488;
}
V_92 = - V_36 ;
if ( ! ( V_483 == 0x1000 || V_483 == 0x10000 ||
V_483 == 0x1000000 ) )
goto V_488;
V_481 = F_174 ( V_483 ) ;
V_68 -> V_10 . V_496 = V_481 | V_497 |
( V_498 << V_499 ) ;
V_482 = V_500 ;
V_67 = V_481 << ( V_501 - 4 ) ;
F_175 ( V_2 , V_458 , V_484 ) ;
} else {
V_403 = V_414 ;
if ( V_403 > V_458 -> V_467 )
V_403 = V_458 -> V_467 ;
V_403 <<= V_432 ;
V_485 = F_138 ( V_403 ) ;
V_92 = - V_36 ;
if ( ( long ) V_485 < 0 ) {
F_24 ( L_20 , V_403 ) ;
goto V_488;
}
F_131 ( & V_410 -> V_502 ) ;
V_68 -> V_10 . V_503 = V_410 ;
if ( F_20 ( V_428 ) ) {
V_482 = ( 1ul << V_504 ) |
( 3ul << V_505 ) | V_506 ;
V_67 = ( ( V_485 >> 2 ) << V_504 ) |
( ( V_485 & 3 ) << V_505 ) ;
V_67 |= ( ( V_410 -> V_416 >> ( 26 - V_432 ) ) & 0xffff )
<< V_507 ;
} else {
V_482 = V_508 | V_509 | V_510 ;
V_67 = V_485 << V_511 ;
V_68 -> V_10 . V_512 = V_410 -> V_416 << V_432 ;
}
F_176 ( L_21 ,
V_410 -> V_416 << V_432 , V_403 , V_67 ) ;
V_467 = V_414 ;
V_484 = F_172 ( V_467 ) ;
V_466 = V_458 -> V_10 . V_469 ;
if ( V_466 ) {
if ( V_467 > V_458 -> V_467 )
V_467 = V_458 -> V_467 ;
F_21 ( & V_68 -> V_10 . V_513 ) ;
for ( V_174 = 0 ; V_174 < V_467 ; ++ V_174 )
V_466 [ V_174 ] = ( ( V_410 -> V_416 + V_174 ) << V_432 ) +
V_484 ;
F_22 ( & V_68 -> V_10 . V_513 ) ;
}
}
F_165 ( V_68 , V_67 , V_482 ) ;
F_43 () ;
V_68 -> V_10 . V_398 = 1 ;
V_92 = 0 ;
V_488:
F_47 ( & V_68 -> V_137 , V_376 ) ;
V_331:
F_29 ( & V_68 -> V_44 ) ;
return V_92 ;
V_493:
F_173 ( & V_119 -> V_400 -> V_490 ) ;
goto V_488;
}
static int F_177 ( struct V_68 * V_68 )
{
unsigned long V_67 , V_514 ;
V_514 = F_178 () ;
if ( ( long ) V_514 < 0 )
return - V_332 ;
V_68 -> V_10 . V_514 = V_514 ;
F_179 ( & V_68 -> V_10 . V_515 ) ;
V_68 -> V_10 . V_503 = NULL ;
V_68 -> V_10 . V_516 = F_71 ( V_517 ) ;
if ( F_20 ( V_428 ) ) {
V_68 -> V_10 . V_518 = 0 ;
V_68 -> V_10 . V_519 = V_67 = F_71 ( V_520 ) ;
V_67 &= ~ ( ( 3 << V_521 ) | ( 0xful << V_522 ) ) ;
V_67 |= ( ( V_514 >> 4 ) << V_521 ) |
( ( V_514 & 0xf ) << V_522 ) ;
} else {
V_68 -> V_10 . V_518 = F_71 ( V_523 ) ;
V_68 -> V_10 . V_519 = V_67 = F_71 ( V_524 ) ;
V_67 &= V_525 | V_526 ;
V_67 |= ( 4UL << V_527 ) | V_528 |
V_508 | V_529 ;
V_68 -> V_10 . V_496 = V_497 |
( V_498 << V_499 ) ;
if ( F_20 ( V_43 ) )
V_67 |= V_530 ;
}
V_68 -> V_10 . V_67 = V_67 ;
V_68 -> V_10 . V_476 = ! ! F_20 ( V_35 ) ;
F_72 ( & V_68 -> V_10 . V_513 ) ;
F_180 () ;
return 0 ;
}
static void F_181 ( struct V_68 * V_68 )
{
long int V_174 ;
for ( V_174 = 0 ; V_174 < V_330 ; ++ V_174 )
F_182 ( V_68 -> V_10 . V_345 [ V_174 ] ) ;
V_68 -> V_10 . V_348 = 0 ;
}
static void F_183 ( struct V_68 * V_68 )
{
F_184 () ;
F_181 ( V_68 ) ;
if ( V_68 -> V_10 . V_503 ) {
F_144 ( V_68 -> V_10 . V_503 ) ;
V_68 -> V_10 . V_503 = NULL ;
}
F_185 ( V_68 ) ;
}
static int F_186 ( struct V_157 * V_158 , struct V_1 * V_2 ,
unsigned int V_531 , int * V_532 )
{
return V_533 ;
}
static int F_187 ( struct V_1 * V_2 , int V_534 ,
T_4 V_535 )
{
return V_533 ;
}
static int F_188 ( struct V_1 * V_2 , int V_534 ,
T_4 * V_535 )
{
return V_533 ;
}
static int F_189 ( void )
{
if ( ! F_20 ( V_427 ) )
return - V_536 ;
return 0 ;
}
static long F_190 ( struct V_417 * V_424 ,
unsigned int V_537 , unsigned long V_538 )
{
struct V_68 * V_68 V_539 = V_424 -> V_412 ;
void T_5 * V_540 = ( void T_5 * ) V_538 ;
long V_45 ;
switch ( V_537 ) {
case V_541 : {
struct V_425 V_503 ;
struct V_68 * V_68 = V_424 -> V_412 ;
V_45 = F_145 ( V_68 , & V_503 ) ;
if ( V_45 >= 0 && F_155 ( V_540 , & V_503 , sizeof( V_503 ) ) )
V_45 = - V_465 ;
break;
}
case V_542 : {
T_3 V_543 ;
V_45 = - V_465 ;
if ( F_191 ( V_543 , ( T_3 T_5 * ) V_540 ) )
break;
V_45 = F_192 ( V_68 , & V_543 ) ;
if ( V_45 )
break;
V_45 = - V_465 ;
if ( F_193 ( V_543 , ( T_3 T_5 * ) V_540 ) )
break;
V_45 = 0 ;
break;
}
case V_544 : {
struct V_545 V_546 ;
V_45 = - V_465 ;
if ( F_194 ( & V_546 , V_540 , sizeof( V_546 ) ) )
break;
V_45 = F_195 ( V_68 , & V_546 ) ;
break;
}
default:
V_45 = - V_547 ;
}
return V_45 ;
}
static int F_196 ( void )
{
int V_45 ;
V_45 = F_189 () ;
if ( V_45 < 0 )
return - V_548 ;
V_549 . V_550 = V_551 ;
V_552 = & V_549 ;
V_45 = F_197 () ;
return V_45 ;
}
static void F_198 ( void )
{
V_552 = NULL ;
}
