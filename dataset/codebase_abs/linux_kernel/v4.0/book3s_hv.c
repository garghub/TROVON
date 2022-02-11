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
if ( V_16 -> V_19 == V_2 && V_16 -> V_20 != V_21 ) {
F_12 ( & V_16 -> V_22 , V_18 ) ;
if ( V_16 -> V_23 != V_24 ) {
V_16 -> V_25 += F_13 () - V_16 -> V_23 ;
V_16 -> V_23 = V_24 ;
}
F_14 ( & V_16 -> V_22 , V_18 ) ;
}
F_12 ( & V_2 -> V_10 . V_26 , V_18 ) ;
if ( V_2 -> V_10 . V_27 == V_28 &&
V_2 -> V_10 . V_29 != V_24 ) {
V_2 -> V_10 . V_30 += F_13 () - V_2 -> V_10 . V_29 ;
V_2 -> V_10 . V_29 = V_24 ;
}
F_14 ( & V_2 -> V_10 . V_26 , V_18 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_10 . V_17 ;
unsigned long V_18 ;
if ( V_16 -> V_19 == V_2 && V_16 -> V_20 != V_21 ) {
F_12 ( & V_16 -> V_22 , V_18 ) ;
V_16 -> V_23 = F_13 () ;
F_14 ( & V_16 -> V_22 , V_18 ) ;
}
F_12 ( & V_2 -> V_10 . V_26 , V_18 ) ;
if ( V_2 -> V_10 . V_27 == V_28 )
V_2 -> V_10 . V_29 = F_13 () ;
F_14 ( & V_2 -> V_10 . V_26 , V_18 ) ;
}
static void F_16 ( struct V_1 * V_2 , T_2 V_31 )
{
V_2 -> V_10 . V_32 . V_31 = V_31 ;
F_17 ( V_2 ) ;
}
void F_18 ( struct V_1 * V_2 , T_3 V_33 )
{
V_2 -> V_10 . V_33 = V_33 ;
}
int F_19 ( struct V_1 * V_2 , T_3 V_34 )
{
unsigned long V_35 = 0 ;
struct V_15 * V_16 = V_2 -> V_10 . V_17 ;
if ( V_34 ) {
switch ( V_34 ) {
case V_36 :
V_35 = V_37 | V_38 ;
break;
case V_39 :
case V_40 :
V_35 = V_37 ;
break;
case V_41 :
break;
default:
return - V_42 ;
}
if ( ! F_20 ( V_43 ) ) {
if ( ! ( V_35 & V_37 ) )
return - V_42 ;
V_35 &= ~ V_37 ;
}
}
F_21 ( & V_16 -> V_44 ) ;
V_16 -> V_34 = V_34 ;
V_16 -> V_35 = V_35 ;
F_22 ( & V_16 -> V_44 ) ;
return 0 ;
}
void F_23 ( struct V_1 * V_2 )
{
int V_45 ;
F_24 ( L_1 , V_2 , V_2 -> V_46 ) ;
F_24 ( L_2 ,
V_2 -> V_10 . V_47 , V_2 -> V_10 . V_32 . V_31 , V_2 -> V_10 . V_48 ) ;
for ( V_45 = 0 ; V_45 < 16 ; ++ V_45 )
F_24 ( L_3 ,
V_45 , F_25 ( V_2 , V_45 ) ,
V_45 + 16 , F_25 ( V_2 , V_45 + 16 ) ) ;
F_24 ( L_4 ,
V_2 -> V_10 . V_49 , V_2 -> V_10 . V_50 ) ;
F_24 ( L_5 ,
V_2 -> V_10 . V_32 . V_51 , V_2 -> V_10 . V_32 . V_52 ) ;
F_24 ( L_6 ,
V_2 -> V_10 . V_32 . V_53 , V_2 -> V_10 . V_32 . V_54 ) ;
F_24 ( L_7 ,
V_2 -> V_10 . V_32 . V_55 , V_2 -> V_10 . V_32 . V_56 ) ;
F_24 ( L_8 ,
V_2 -> V_10 . V_57 , V_2 -> V_10 . V_58 , V_2 -> V_10 . V_32 . V_59 ) ;
F_24 ( L_9 , V_2 -> V_10 . V_32 . V_60 ) ;
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
return - V_42 ;
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
unsigned long V_18 ;
F_12 ( & V_16 -> V_22 , V_18 ) ;
V_117 = V_16 -> V_25 ;
if ( V_16 -> V_20 != V_21 &&
V_16 -> V_23 != V_24 )
V_117 += V_116 - V_16 -> V_23 ;
F_14 ( & V_16 -> V_22 , V_18 ) ;
return V_117 ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_104 * V_118 ;
struct V_74 * V_75 ;
unsigned long V_119 ;
unsigned long V_120 ;
T_2 V_116 ;
V_118 = V_2 -> V_10 . V_114 ;
V_75 = V_2 -> V_10 . V_75 . V_87 ;
V_116 = F_13 () ;
V_120 = F_41 ( V_16 , V_116 ) ;
V_119 = V_120 - V_2 -> V_10 . V_121 ;
V_2 -> V_10 . V_121 = V_120 ;
F_43 ( & V_2 -> V_10 . V_26 ) ;
V_119 += V_2 -> V_10 . V_30 ;
V_2 -> V_10 . V_30 = 0 ;
F_44 ( & V_2 -> V_10 . V_26 ) ;
if ( ! V_118 || ! V_75 )
return;
memset ( V_118 , 0 , sizeof( struct V_104 ) ) ;
V_118 -> V_122 = 7 ;
V_118 -> V_123 = F_45 ( V_16 -> V_124 + V_2 -> V_10 . V_11 ) ;
V_118 -> V_125 = F_46 ( V_116 + V_16 -> V_126 ) ;
V_118 -> V_127 = F_31 ( V_119 ) ;
V_118 -> V_51 = F_46 ( F_47 ( V_2 ) ) ;
V_118 -> V_52 = F_46 ( V_2 -> V_10 . V_32 . V_31 ) ;
++ V_118 ;
if ( V_118 == V_2 -> V_10 . V_106 . V_113 )
V_118 = V_2 -> V_10 . V_106 . V_87 ;
V_2 -> V_10 . V_114 = V_118 ;
F_48 () ;
V_75 -> V_128 = F_46 ( ++ V_2 -> V_10 . V_115 ) ;
V_2 -> V_10 . V_106 . V_112 = true ;
}
static bool F_49 ( struct V_1 * V_2 )
{
if ( V_2 -> V_10 . V_17 -> V_34 >= V_41 )
return true ;
if ( ( ! V_2 -> V_10 . V_17 -> V_34 ) &&
F_20 ( V_43 ) )
return true ;
return false ;
}
static int F_50 ( struct V_1 * V_2 , unsigned long V_129 ,
unsigned long V_130 , unsigned long V_131 ,
unsigned long V_132 )
{
switch ( V_130 ) {
case V_133 :
if ( ! F_49 ( V_2 ) )
return V_134 ;
if ( V_132 )
return V_135 ;
if ( V_129 )
return V_136 ;
if ( ( V_131 & V_137 ) == V_138 )
return V_139 ;
V_2 -> V_10 . V_140 = V_131 ;
return V_141 ;
case V_142 :
if ( ! F_49 ( V_2 ) )
return V_134 ;
if ( V_129 )
return V_136 ;
if ( V_132 & V_143 )
return V_135 ;
V_2 -> V_10 . V_144 = V_131 ;
V_2 -> V_10 . V_145 = V_132 ;
return V_141 ;
default:
return V_146 ;
}
}
static int F_51 ( struct V_1 * V_147 )
{
struct V_15 * V_17 = V_147 -> V_10 . V_17 ;
F_21 ( & V_17 -> V_44 ) ;
if ( V_147 -> V_10 . V_27 == V_148 &&
V_17 -> V_20 != V_21 )
V_147 = V_17 -> V_19 ;
F_22 ( & V_17 -> V_44 ) ;
return F_52 ( V_147 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_78 = 0 ;
struct V_74 * V_74 ;
F_21 ( & V_2 -> V_10 . V_83 ) ;
V_74 = (struct V_74 * ) V_2 -> V_10 . V_75 . V_87 ;
if ( V_74 )
V_78 = F_37 ( V_74 -> V_78 ) ;
F_22 ( & V_2 -> V_10 . V_83 ) ;
return V_78 ;
}
int F_54 ( struct V_1 * V_2 )
{
unsigned long V_149 = F_25 ( V_2 , 3 ) ;
unsigned long V_147 , V_73 = V_141 ;
int V_78 ;
struct V_1 * V_91 ;
int V_150 , V_151 ;
if ( V_149 <= V_152 &&
! F_55 ( V_149 / 4 , V_2 -> V_68 -> V_10 . V_153 ) )
return V_154 ;
switch ( V_149 ) {
case V_155 :
break;
case V_156 :
V_147 = F_25 ( V_2 , 4 ) ;
V_91 = F_26 ( V_2 -> V_68 , V_147 ) ;
if ( ! V_91 ) {
V_73 = V_94 ;
break;
}
V_91 -> V_10 . V_157 = 1 ;
F_56 () ;
if ( V_2 -> V_10 . V_158 ) {
if ( F_3 ( & V_2 -> V_159 ) ) {
F_4 ( & V_2 -> V_159 ) ;
V_2 -> V_6 . V_7 ++ ;
}
}
break;
case V_160 :
V_147 = F_25 ( V_2 , 4 ) ;
if ( V_147 == - 1 )
break;
V_91 = F_26 ( V_2 -> V_68 , V_147 ) ;
if ( ! V_91 ) {
V_73 = V_94 ;
break;
}
V_78 = F_25 ( V_2 , 5 ) ;
if ( F_53 ( V_91 ) != V_78 )
break;
F_51 ( V_91 ) ;
break;
case V_161 :
V_73 = F_34 ( V_2 , F_25 ( V_2 , 4 ) ,
F_25 ( V_2 , 5 ) ,
F_25 ( V_2 , 6 ) ) ;
break;
case V_162 :
if ( F_57 ( & V_2 -> V_68 -> V_10 . V_163 ) )
return V_154 ;
V_150 = F_58 ( & V_2 -> V_68 -> V_164 ) ;
V_151 = F_59 ( V_2 ) ;
F_60 ( & V_2 -> V_68 -> V_164 , V_150 ) ;
if ( V_151 == - V_165 )
return V_154 ;
else if ( V_151 == 0 )
break;
return V_151 ;
case V_166 :
V_73 = F_50 ( V_2 , F_25 ( V_2 , 4 ) ,
F_25 ( V_2 , 5 ) ,
F_25 ( V_2 , 6 ) ,
F_25 ( V_2 , 7 ) ) ;
if ( V_73 == V_146 )
return V_154 ;
break;
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
if ( F_61 ( V_2 ) ) {
V_73 = F_62 ( V_2 , V_149 ) ;
break;
}
default:
return V_154 ;
}
F_63 ( V_2 , 3 , V_73 ) ;
V_2 -> V_10 . V_173 = 0 ;
return V_174 ;
}
static int F_64 ( unsigned long V_175 )
{
switch ( V_175 ) {
case V_155 :
case V_156 :
case V_160 :
case V_161 :
case V_166 :
#ifdef F_65
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
#endif
return 1 ;
}
return F_66 ( V_175 ) ;
}
static int F_67 ( struct V_176 * V_177 ,
struct V_1 * V_2 )
{
T_3 V_70 ;
if ( F_68 ( V_2 , V_178 , & V_70 ) !=
V_179 ) {
return V_174 ;
}
if ( V_70 == V_180 ) {
V_177 -> V_181 = V_182 ;
V_177 -> V_183 . V_10 . V_184 = F_47 ( V_2 ) ;
return V_154 ;
} else {
F_69 ( V_2 , V_185 ) ;
return V_174 ;
}
}
static int F_70 ( struct V_176 * V_177 , struct V_1 * V_2 ,
struct V_186 * V_187 )
{
int V_45 = V_154 ;
V_2 -> V_6 . V_188 ++ ;
V_177 -> V_181 = V_189 ;
V_177 -> V_190 = 1 ;
switch ( V_2 -> V_10 . V_48 ) {
case V_191 :
V_2 -> V_6 . V_192 ++ ;
V_45 = V_174 ;
break;
case V_193 :
case V_194 :
V_2 -> V_6 . V_195 ++ ;
V_45 = V_174 ;
break;
case V_196 :
case V_197 :
V_45 = V_174 ;
break;
case V_198 :
F_71 ( V_2 ,
V_198 ) ;
V_45 = V_174 ;
break;
case V_199 :
{
T_4 V_18 ;
V_18 = V_2 -> V_10 . V_32 . V_31 & 0x1f0000ull ;
F_69 ( V_2 , V_18 ) ;
V_45 = V_174 ;
break;
}
case V_200 :
{
int V_201 ;
V_177 -> V_202 . V_203 = F_25 ( V_2 , 3 ) ;
for ( V_201 = 0 ; V_201 < 9 ; ++ V_201 )
V_177 -> V_202 . args [ V_201 ] = F_25 ( V_2 , 4 + V_201 ) ;
V_177 -> V_181 = V_204 ;
V_2 -> V_10 . V_173 = 1 ;
V_45 = V_154 ;
break;
}
case V_205 :
V_45 = V_206 ;
break;
case V_207 :
V_2 -> V_10 . V_61 = F_47 ( V_2 ) ;
V_2 -> V_10 . V_62 = 0 ;
V_45 = V_206 ;
break;
case V_208 :
if ( V_2 -> V_10 . V_209 != V_210 )
V_2 -> V_10 . V_70 = F_72 ( V_2 ) ?
F_73 ( V_2 -> V_10 . V_209 ) :
V_2 -> V_10 . V_209 ;
if ( V_2 -> V_211 & V_212 ) {
V_45 = F_67 ( V_177 , V_2 ) ;
} else {
F_69 ( V_2 , V_185 ) ;
V_45 = V_174 ;
}
break;
case V_213 :
F_69 ( V_2 , V_185 ) ;
V_45 = V_174 ;
break;
default:
F_23 ( V_2 ) ;
F_74 ( V_214 L_14 ,
V_2 -> V_10 . V_48 , F_47 ( V_2 ) ,
V_2 -> V_10 . V_32 . V_31 ) ;
V_177 -> V_215 . V_216 = V_2 -> V_10 . V_48 ;
V_45 = V_154 ;
break;
}
return V_45 ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_217 * V_218 )
{
int V_201 ;
memset ( V_218 , 0 , sizeof( struct V_217 ) ) ;
V_218 -> V_33 = V_2 -> V_10 . V_33 ;
for ( V_201 = 0 ; V_201 < V_2 -> V_10 . V_63 ; V_201 ++ ) {
V_218 -> V_219 . V_220 . V_221 . V_64 [ V_201 ] . V_222 = V_2 -> V_10 . V_64 [ V_201 ] . V_65 ;
V_218 -> V_219 . V_220 . V_221 . V_64 [ V_201 ] . V_223 = V_2 -> V_10 . V_64 [ V_201 ] . V_66 ;
}
return 0 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_217 * V_218 )
{
int V_201 , V_224 ;
if ( V_218 -> V_33 != V_2 -> V_10 . V_33 )
return - V_42 ;
V_224 = 0 ;
for ( V_201 = 0 ; V_201 < V_2 -> V_10 . V_225 ; V_201 ++ ) {
if ( V_218 -> V_219 . V_220 . V_221 . V_64 [ V_201 ] . V_222 & V_226 ) {
V_2 -> V_10 . V_64 [ V_224 ] . V_65 = V_218 -> V_219 . V_220 . V_221 . V_64 [ V_201 ] . V_222 ;
V_2 -> V_10 . V_64 [ V_224 ] . V_66 = V_218 -> V_219 . V_220 . V_221 . V_64 [ V_201 ] . V_223 ;
++ V_224 ;
}
}
V_2 -> V_10 . V_63 = V_224 ;
return 0 ;
}
static void F_77 ( struct V_1 * V_2 , T_2 V_227 ,
bool V_228 )
{
struct V_68 * V_68 = V_2 -> V_68 ;
struct V_15 * V_16 = V_2 -> V_10 . V_17 ;
T_2 V_229 ;
F_27 ( & V_68 -> V_44 ) ;
F_21 ( & V_16 -> V_44 ) ;
if ( ( V_227 & V_230 ) != ( V_16 -> V_67 & V_230 ) ) {
struct V_1 * V_2 ;
int V_201 ;
F_28 (i, vcpu, kvm) {
if ( V_2 -> V_10 . V_17 != V_16 )
continue;
if ( V_227 & V_230 )
V_2 -> V_10 . V_231 |= V_232 ;
else
V_2 -> V_10 . V_231 &= ~ V_232 ;
}
}
V_229 = V_233 | V_230 | V_234 ;
if ( F_20 ( V_43 ) )
V_229 |= V_235 ;
if ( V_228 )
V_229 &= 0xFFFFFFFF ;
V_16 -> V_67 = ( V_16 -> V_67 & ~ V_229 ) | ( V_227 & V_229 ) ;
F_22 ( & V_16 -> V_44 ) ;
F_29 ( & V_68 -> V_44 ) ;
}
static int F_78 ( struct V_1 * V_2 , T_2 V_71 ,
union V_236 * V_237 )
{
int V_45 = 0 ;
long int V_201 ;
switch ( V_71 ) {
case V_238 :
* V_237 = F_79 ( V_71 , V_180 ) ;
break;
case V_239 :
* V_237 = F_79 ( V_71 , 0 ) ;
break;
case V_240 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_241 ) ;
break;
case V_242 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_243 ) ;
break;
case V_244 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_245 ) ;
break;
case V_246 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_247 ) ;
break;
case V_248 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_249 ) ;
break;
case V_250 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_251 ) ;
break;
case V_252 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_253 ) ;
break;
case V_254 ... V_255 :
V_201 = V_71 - V_254 ;
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_256 [ V_201 ] ) ;
break;
case V_257 ... V_258 :
V_201 = V_71 - V_257 ;
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_259 [ V_201 ] ) ;
break;
case V_260 ... V_261 :
V_201 = V_71 - V_260 ;
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_262 [ V_201 ] ) ;
break;
case V_263 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_264 ) ;
break;
case V_265 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_266 ) ;
break;
case V_267 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_268 ) ;
break;
case V_269 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_270 ) ;
break;
case V_271 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_272 ) ;
break;
case V_273 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_17 -> V_274 ) ;
break;
case V_275 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_144 ) ;
break;
case V_276 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_145 ) ;
break;
case V_277 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_140 ) ;
break;
case V_278 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_279 ) ;
break;
case V_280 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_281 ) ;
break;
case V_282 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_283 ) ;
break;
case V_284 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_285 ) ;
break;
case V_286 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_287 ) ;
break;
case V_288 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_289 ) ;
break;
case V_290 :
F_21 ( & V_2 -> V_10 . V_83 ) ;
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_75 . V_84 ) ;
F_22 ( & V_2 -> V_10 . V_83 ) ;
break;
case V_291 :
F_21 ( & V_2 -> V_10 . V_83 ) ;
V_237 -> V_292 . V_80 = V_2 -> V_10 . V_107 . V_84 ;
V_237 -> V_292 . V_101 = V_2 -> V_10 . V_107 . V_81 ;
F_22 ( & V_2 -> V_10 . V_83 ) ;
break;
case V_293 :
F_21 ( & V_2 -> V_10 . V_83 ) ;
V_237 -> V_292 . V_80 = V_2 -> V_10 . V_106 . V_84 ;
V_237 -> V_292 . V_101 = V_2 -> V_10 . V_106 . V_81 ;
F_22 ( & V_2 -> V_10 . V_83 ) ;
break;
case V_294 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_17 -> V_126 ) ;
break;
case V_295 :
case V_296 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_17 -> V_67 ) ;
break;
case V_297 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_298 ) ;
break;
#ifdef F_80
case V_299 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_300 ) ;
break;
case V_301 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_302 ) ;
break;
case V_303 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_304 ) ;
break;
case V_305 ... V_306 :
V_201 = V_71 - V_305 ;
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_307 [ V_201 ] ) ;
break;
case V_308 ... V_309 :
{
int V_224 ;
V_201 = V_71 - V_308 ;
if ( V_201 < 32 )
for ( V_224 = 0 ; V_224 < V_310 ; V_224 ++ )
V_237 -> V_311 [ V_224 ] = V_2 -> V_10 . V_312 . V_313 [ V_201 ] [ V_224 ] ;
else {
if ( F_20 ( V_314 ) )
V_237 -> V_315 = V_2 -> V_10 . V_316 . V_317 [ V_201 - 32 ] ;
else
V_45 = - V_318 ;
}
break;
}
case V_319 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_320 ) ;
break;
case V_321 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_322 ) ;
break;
case V_323 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_324 ) ;
break;
case V_325 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_312 . V_326 ) ;
break;
case V_327 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_328 ) ;
break;
case V_329 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_330 ) ;
break;
case V_331 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_332 ) ;
break;
case V_333 :
if ( F_20 ( V_314 ) )
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_316 . V_334 . V_219 [ 3 ] ) ;
else
V_45 = - V_318 ;
break;
case V_335 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_336 ) ;
break;
case V_337 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_338 ) ;
break;
#endif
case V_339 :
* V_237 = F_79 ( V_71 , V_2 -> V_10 . V_17 -> V_34 ) ;
break;
default:
V_45 = - V_42 ;
break;
}
return V_45 ;
}
static int F_81 ( struct V_1 * V_2 , T_2 V_71 ,
union V_236 * V_237 )
{
int V_45 = 0 ;
long int V_201 ;
unsigned long V_80 , V_81 ;
switch ( V_71 ) {
case V_239 :
if ( F_82 ( V_71 , * V_237 ) )
V_45 = - V_42 ;
break;
case V_240 :
V_2 -> V_10 . V_241 = F_82 ( V_71 , * V_237 ) ;
break;
case V_242 :
V_2 -> V_10 . V_243 = F_82 ( V_71 , * V_237 ) & ~ V_143 ;
break;
case V_244 :
V_2 -> V_10 . V_245 = F_82 ( V_71 , * V_237 ) ;
break;
case V_246 :
V_2 -> V_10 . V_247 = F_82 ( V_71 , * V_237 ) ;
break;
case V_248 :
V_2 -> V_10 . V_249 = F_82 ( V_71 , * V_237 ) ;
break;
case V_250 :
V_2 -> V_10 . V_251 = F_82 ( V_71 , * V_237 ) ;
break;
case V_252 :
V_2 -> V_10 . V_253 = F_82 ( V_71 , * V_237 ) ;
break;
case V_254 ... V_255 :
V_201 = V_71 - V_254 ;
V_2 -> V_10 . V_256 [ V_201 ] = F_82 ( V_71 , * V_237 ) ;
break;
case V_257 ... V_258 :
V_201 = V_71 - V_257 ;
V_2 -> V_10 . V_259 [ V_201 ] = F_82 ( V_71 , * V_237 ) ;
break;
case V_260 ... V_261 :
V_201 = V_71 - V_260 ;
V_2 -> V_10 . V_262 [ V_201 ] = F_82 ( V_71 , * V_237 ) ;
break;
case V_263 :
V_2 -> V_10 . V_264 = F_82 ( V_71 , * V_237 ) ;
break;
case V_265 :
V_2 -> V_10 . V_266 = F_82 ( V_71 , * V_237 ) ;
break;
case V_267 :
V_2 -> V_10 . V_268 = F_82 ( V_71 , * V_237 ) ;
break;
case V_269 :
V_2 -> V_10 . V_270 = F_82 ( V_71 , * V_237 ) ;
break;
case V_271 :
V_2 -> V_10 . V_272 = F_82 ( V_71 , * V_237 ) ;
break;
case V_273 :
V_2 -> V_10 . V_17 -> V_274 = F_82 ( V_71 , * V_237 ) ;
break;
case V_275 :
V_2 -> V_10 . V_144 = F_82 ( V_71 , * V_237 ) ;
break;
case V_276 :
V_2 -> V_10 . V_145 = F_82 ( V_71 , * V_237 ) & ~ V_340 ;
break;
case V_277 :
V_2 -> V_10 . V_140 = F_82 ( V_71 , * V_237 ) ;
if ( ( V_2 -> V_10 . V_140 & V_137 ) == V_138 )
V_2 -> V_10 . V_140 &= ~ V_137 ;
break;
case V_278 :
V_2 -> V_10 . V_279 = F_82 ( V_71 , * V_237 ) ;
break;
case V_280 :
V_2 -> V_10 . V_281 = F_82 ( V_71 , * V_237 ) ;
break;
case V_282 :
V_2 -> V_10 . V_283 = F_82 ( V_71 , * V_237 ) ;
break;
case V_284 :
V_2 -> V_10 . V_285 = F_82 ( V_71 , * V_237 ) ;
break;
case V_286 :
V_2 -> V_10 . V_287 = F_82 ( V_71 , * V_237 ) ;
break;
case V_288 :
V_2 -> V_10 . V_289 = F_82 ( V_71 , * V_237 ) ;
break;
case V_290 :
V_80 = F_82 ( V_71 , * V_237 ) ;
V_45 = - V_42 ;
if ( ! V_80 && ( V_2 -> V_10 . V_107 . V_84 ||
V_2 -> V_10 . V_106 . V_84 ) )
break;
V_45 = F_32 ( V_2 , & V_2 -> V_10 . V_75 , V_80 , sizeof( struct V_74 ) ) ;
break;
case V_291 :
V_80 = V_237 -> V_292 . V_80 ;
V_81 = V_237 -> V_292 . V_101 ;
V_45 = - V_42 ;
if ( V_80 && ! V_2 -> V_10 . V_75 . V_84 )
break;
V_45 = F_32 ( V_2 , & V_2 -> V_10 . V_107 , V_80 , V_81 ) ;
break;
case V_293 :
V_80 = V_237 -> V_292 . V_80 ;
V_81 = V_237 -> V_292 . V_101 ;
V_45 = - V_42 ;
if ( V_80 && ( V_81 < sizeof( struct V_104 ) ||
! V_2 -> V_10 . V_75 . V_84 ) )
break;
V_81 -= V_81 % sizeof( struct V_104 ) ;
V_45 = F_32 ( V_2 , & V_2 -> V_10 . V_106 , V_80 , V_81 ) ;
break;
case V_294 :
V_2 -> V_10 . V_17 -> V_126 =
F_83 ( F_82 ( V_71 , * V_237 ) , 1UL << 24 ) ;
break;
case V_295 :
F_77 ( V_2 , F_82 ( V_71 , * V_237 ) , true ) ;
break;
case V_296 :
F_77 ( V_2 , F_82 ( V_71 , * V_237 ) , false ) ;
break;
case V_297 :
V_2 -> V_10 . V_298 = F_82 ( V_71 , * V_237 ) ;
break;
#ifdef F_80
case V_299 :
V_2 -> V_10 . V_300 = F_82 ( V_71 , * V_237 ) ;
break;
case V_301 :
V_2 -> V_10 . V_302 = F_82 ( V_71 , * V_237 ) ;
break;
case V_303 :
V_2 -> V_10 . V_304 = F_82 ( V_71 , * V_237 ) ;
break;
case V_305 ... V_306 :
V_201 = V_71 - V_305 ;
V_2 -> V_10 . V_307 [ V_201 ] = F_82 ( V_71 , * V_237 ) ;
break;
case V_308 ... V_309 :
{
int V_224 ;
V_201 = V_71 - V_308 ;
if ( V_201 < 32 )
for ( V_224 = 0 ; V_224 < V_310 ; V_224 ++ )
V_2 -> V_10 . V_312 . V_313 [ V_201 ] [ V_224 ] = V_237 -> V_311 [ V_224 ] ;
else
if ( F_20 ( V_314 ) )
V_2 -> V_10 . V_316 . V_317 [ V_201 - 32 ] = V_237 -> V_315 ;
else
V_45 = - V_318 ;
break;
}
case V_319 :
V_2 -> V_10 . V_320 = F_82 ( V_71 , * V_237 ) ;
break;
case V_321 :
V_2 -> V_10 . V_322 = F_82 ( V_71 , * V_237 ) ;
break;
case V_323 :
V_2 -> V_10 . V_324 = F_82 ( V_71 , * V_237 ) ;
break;
case V_325 :
V_2 -> V_10 . V_312 . V_326 = F_82 ( V_71 , * V_237 ) ;
break;
case V_327 :
V_2 -> V_10 . V_328 = F_82 ( V_71 , * V_237 ) ;
break;
case V_329 :
V_2 -> V_10 . V_330 = F_82 ( V_71 , * V_237 ) ;
break;
case V_331 :
V_2 -> V_10 . V_332 = F_82 ( V_71 , * V_237 ) ;
break;
case V_333 :
if ( F_20 ( V_314 ) )
V_2 -> V_10 . V_317 . V_334 . V_219 [ 3 ] = F_82 ( V_71 , * V_237 ) ;
else
V_45 = - V_318 ;
break;
case V_335 :
V_2 -> V_10 . V_336 = F_82 ( V_71 , * V_237 ) ;
break;
case V_337 :
V_2 -> V_10 . V_338 = F_82 ( V_71 , * V_237 ) ;
break;
#endif
case V_339 :
V_45 = F_19 ( V_2 , F_82 ( V_71 , * V_237 ) ) ;
break;
default:
V_45 = - V_42 ;
break;
}
return V_45 ;
}
static struct V_15 * F_84 ( struct V_68 * V_68 , int V_341 )
{
struct V_15 * V_17 ;
V_17 = F_85 ( sizeof( struct V_15 ) , V_342 ) ;
if ( V_17 == NULL )
return NULL ;
F_86 ( & V_17 -> V_343 ) ;
F_87 ( & V_17 -> V_44 ) ;
F_87 ( & V_17 -> V_22 ) ;
F_88 ( & V_17 -> V_159 ) ;
V_17 -> V_23 = V_24 ;
V_17 -> V_67 = V_68 -> V_10 . V_67 ;
V_17 -> V_344 = V_341 * V_345 ;
V_17 -> V_68 = V_68 ;
V_17 -> V_346 = false ;
if ( F_20 ( V_43 ) )
V_17 -> V_347 = ( void * ) F_89 (
V_342 | V_348 ,
V_349 ) ;
return V_17 ;
}
static struct V_1 * F_90 ( struct V_68 * V_68 ,
unsigned int V_71 )
{
struct V_1 * V_2 ;
int V_92 = - V_42 ;
int V_341 ;
struct V_15 * V_17 ;
V_341 = V_71 / V_345 ;
if ( V_341 >= V_350 )
goto V_351;
V_92 = - V_352 ;
V_2 = F_91 ( V_353 , V_342 ) ;
if ( ! V_2 )
goto V_351;
V_92 = F_92 ( V_2 , V_68 , V_71 ) ;
if ( V_92 )
goto V_354;
V_2 -> V_10 . V_355 = & V_2 -> V_10 . V_32 ;
#ifdef F_93
#ifdef F_94
V_2 -> V_10 . V_356 = true ;
#else
V_2 -> V_10 . V_356 = false ;
#endif
#endif
V_2 -> V_10 . V_256 [ 0 ] = V_357 ;
V_2 -> V_10 . V_358 = V_359 ;
F_18 ( V_2 , F_95 ( V_360 ) ) ;
F_87 ( & V_2 -> V_10 . V_83 ) ;
F_87 ( & V_2 -> V_10 . V_26 ) ;
V_2 -> V_10 . V_29 = V_24 ;
V_2 -> V_10 . V_231 = V_361 | V_362 ;
F_96 ( V_2 ) ;
V_2 -> V_10 . V_27 = V_363 ;
F_88 ( & V_2 -> V_10 . V_364 ) ;
F_27 ( & V_68 -> V_44 ) ;
V_17 = V_68 -> V_10 . V_365 [ V_341 ] ;
if ( ! V_17 ) {
V_17 = F_84 ( V_68 , V_341 ) ;
V_68 -> V_10 . V_365 [ V_341 ] = V_17 ;
V_68 -> V_10 . V_366 ++ ;
}
F_29 ( & V_68 -> V_44 ) ;
if ( ! V_17 )
goto V_354;
F_21 ( & V_17 -> V_44 ) ;
++ V_17 -> V_367 ;
F_22 ( & V_17 -> V_44 ) ;
V_2 -> V_10 . V_17 = V_17 ;
V_2 -> V_10 . V_11 = V_2 -> V_46 - V_17 -> V_344 ;
V_2 -> V_10 . V_368 = V_369 ;
F_97 ( V_2 ) ;
return V_2 ;
V_354:
F_98 ( V_353 , V_2 ) ;
V_351:
return F_99 ( V_92 ) ;
}
static void F_100 ( struct V_68 * V_68 , struct V_79 * V_75 )
{
if ( V_75 -> V_87 )
F_38 ( V_68 , V_75 -> V_87 , V_75 -> V_111 ,
V_75 -> V_112 ) ;
}
static void F_101 ( struct V_1 * V_2 )
{
F_21 ( & V_2 -> V_10 . V_83 ) ;
F_100 ( V_2 -> V_68 , & V_2 -> V_10 . V_106 ) ;
F_100 ( V_2 -> V_68 , & V_2 -> V_10 . V_107 ) ;
F_100 ( V_2 -> V_68 , & V_2 -> V_10 . V_75 ) ;
F_22 ( & V_2 -> V_10 . V_83 ) ;
F_102 ( V_2 ) ;
F_98 ( V_353 , V_2 ) ;
}
static int F_103 ( struct V_1 * V_2 )
{
return 1 ;
}
static void F_104 ( struct V_1 * V_2 )
{
unsigned long V_370 , V_116 ;
V_116 = F_105 () ;
if ( V_116 > V_2 -> V_10 . V_371 ) {
F_106 ( V_2 ) ;
F_107 ( V_2 ) ;
return;
}
V_370 = ( V_2 -> V_10 . V_371 - V_116 ) * V_372
/ V_373 ;
F_108 ( & V_2 -> V_10 . V_374 , F_109 ( 0 , V_370 ) ,
V_375 ) ;
V_2 -> V_10 . V_376 = 1 ;
}
static void F_17 ( struct V_1 * V_2 )
{
V_2 -> V_10 . V_158 = 0 ;
if ( V_2 -> V_10 . V_376 ) {
F_110 ( & V_2 -> V_10 . V_374 ) ;
V_2 -> V_10 . V_376 = 0 ;
}
}
static void F_111 ( struct V_15 * V_16 ,
struct V_1 * V_2 )
{
T_2 V_116 ;
if ( V_2 -> V_10 . V_27 != V_148 )
return;
F_43 ( & V_2 -> V_10 . V_26 ) ;
V_116 = F_13 () ;
V_2 -> V_10 . V_30 += F_41 ( V_16 , V_116 ) -
V_2 -> V_10 . V_121 ;
V_2 -> V_10 . V_29 = V_116 ;
V_2 -> V_10 . V_27 = V_28 ;
F_44 ( & V_2 -> V_10 . V_26 ) ;
-- V_16 -> V_377 ;
F_112 ( & V_2 -> V_10 . V_378 ) ;
}
static int F_113 ( int V_4 )
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
F_114 ( 1 ) ;
}
return 0 ;
}
static void F_115 ( int V_4 )
{
struct V_379 * V_380 ;
V_380 = & V_12 [ V_4 ] ;
V_380 -> V_13 . V_382 = 0 ;
V_380 -> V_13 . V_1 = NULL ;
}
static void F_116 ( struct V_1 * V_2 )
{
int V_4 ;
struct V_379 * V_380 ;
struct V_15 * V_16 = V_2 -> V_10 . V_17 ;
if ( V_2 -> V_10 . V_376 ) {
F_110 ( & V_2 -> V_10 . V_374 ) ;
V_2 -> V_10 . V_376 = 0 ;
}
V_4 = V_16 -> V_124 + V_2 -> V_10 . V_11 ;
V_380 = & V_12 [ V_4 ] ;
V_380 -> V_13 . V_1 = V_2 ;
V_380 -> V_13 . V_386 = V_16 ;
V_380 -> V_13 . V_11 = V_2 -> V_10 . V_11 ;
V_2 -> V_4 = V_16 -> V_124 ;
F_48 () ;
#if F_117 ( F_6 ) && F_117 ( V_387 )
if ( V_4 != F_118 () ) {
F_7 ( V_4 ) ;
if ( V_2 -> V_10 . V_11 )
++ V_16 -> V_388 ;
}
#endif
}
static void F_119 ( struct V_15 * V_16 )
{
int V_201 ;
F_120 () ;
V_201 = 0 ;
while ( V_16 -> V_389 < V_16 -> V_388 ) {
if ( ++ V_201 >= 1000000 ) {
F_24 ( L_16 ,
V_16 -> V_389 , V_16 -> V_388 ) ;
break;
}
F_121 () ;
}
F_122 () ;
}
static int F_123 ( void )
{
int V_4 = F_118 () ;
int V_390 ;
if ( F_124 ( V_4 ) )
return 0 ;
V_390 = 0 ;
while ( ++ V_390 < V_345 )
if ( F_8 ( V_4 + V_390 ) )
return 0 ;
for ( V_390 = 1 ; V_390 < V_345 ; ++ V_390 ) {
if ( F_113 ( V_4 + V_390 ) ) {
do {
F_115 ( V_4 + V_390 ) ;
} while ( -- V_390 > 0 );
return 0 ;
}
}
return 1 ;
}
static void F_125 ( struct V_15 * V_16 )
{
T_5 V_391 , V_392 ;
V_391 = ( T_5 ) F_126 ( V_16 -> V_347 ) ;
V_392 = V_391 & V_393 ;
F_127 ( V_394 , V_392 | V_395 ) ;
F_128 ( V_392 | V_396 ) ;
V_16 -> V_346 = true ;
}
static void F_129 ( const struct V_15 * V_16 )
{
T_5 V_391 , V_392 ;
V_391 = F_126 ( V_16 -> V_347 ) ;
V_392 = V_391 & V_393 ;
F_128 ( V_392 | V_397 ) ;
F_127 ( V_394 , V_392 | V_398 ) ;
}
static void F_130 ( struct V_15 * V_16 )
{
struct V_1 * V_2 , * V_399 ;
long V_73 ;
T_2 V_116 ;
int V_201 , V_400 ;
int V_401 ;
struct V_1 * V_402 [ V_403 ] ;
V_400 = 0 ;
F_131 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( F_132 ( V_2 -> V_10 . V_404 ) )
return;
if ( V_2 -> V_10 . V_75 . V_85 ||
V_2 -> V_10 . V_107 . V_85 ||
V_2 -> V_10 . V_106 . V_85 )
V_402 [ V_400 ++ ] = V_2 ;
}
V_16 -> V_388 = 0 ;
V_16 -> V_389 = 0 ;
V_16 -> V_405 = 0 ;
V_16 -> V_23 = V_24 ;
V_16 -> V_20 = V_406 ;
V_16 -> V_407 = 0 ;
V_16 -> V_408 = 0 ;
V_16 -> V_409 = 0 ;
if ( V_400 ) {
F_22 ( & V_16 -> V_44 ) ;
for ( V_201 = 0 ; V_201 < V_400 ; ++ V_201 )
F_40 ( V_402 [ V_201 ] ) ;
F_21 ( & V_16 -> V_44 ) ;
}
if ( ( V_403 > 1 ) &&
( ( V_16 -> V_367 > V_345 ) || ! F_123 () ) ) {
F_131 (vcpu, &vc->runnable_threads, arch.run_list)
V_2 -> V_10 . V_73 = - V_385 ;
goto V_351;
}
V_16 -> V_124 = F_118 () ;
F_131 (vcpu, &vc->runnable_threads, arch.run_list) {
F_116 ( V_2 ) ;
F_42 ( V_2 , V_16 ) ;
F_133 ( V_2 ) ;
}
F_134 () -> V_13 . V_386 = V_16 ;
F_134 () -> V_13 . V_11 = 0 ;
V_16 -> V_20 = V_410 ;
F_135 () ;
F_136 ( V_16 , 0 ) ;
F_22 ( & V_16 -> V_44 ) ;
F_137 () ;
V_401 = F_58 ( & V_16 -> V_68 -> V_164 ) ;
if ( V_16 -> V_346 )
F_129 ( V_16 ) ;
F_138 () ;
F_21 ( & V_16 -> V_44 ) ;
if ( V_16 -> V_347 )
F_125 ( V_16 ) ;
F_131 (vcpu, &vc->runnable_threads, arch.run_list)
V_2 -> V_4 = - 1 ;
if ( V_16 -> V_389 < V_16 -> V_388 )
F_119 ( V_16 ) ;
for ( V_201 = 0 ; V_201 < V_345 ; ++ V_201 )
F_115 ( V_16 -> V_124 + V_201 ) ;
V_16 -> V_20 = V_411 ;
F_22 ( & V_16 -> V_44 ) ;
F_60 ( & V_16 -> V_68 -> V_164 , V_401 ) ;
F_56 () ;
F_139 () ;
F_140 () ;
F_141 () ;
F_21 ( & V_16 -> V_44 ) ;
V_116 = F_105 () ;
F_131 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( V_116 < V_2 -> V_10 . V_371 &&
F_142 ( V_2 ) )
F_143 ( V_2 ) ;
F_144 ( V_2 ) ;
V_73 = V_174 ;
if ( V_2 -> V_10 . V_48 )
V_73 = F_70 ( V_2 -> V_10 . V_176 , V_2 ,
V_2 -> V_10 . V_404 ) ;
V_2 -> V_10 . V_73 = V_73 ;
V_2 -> V_10 . V_48 = 0 ;
if ( V_2 -> V_10 . V_158 ) {
if ( ! F_145 ( V_73 ) )
F_17 ( V_2 ) ;
else
F_104 ( V_2 ) ;
}
}
V_351:
V_16 -> V_20 = V_21 ;
F_146 (vcpu, vnext, &vc->runnable_threads,
arch.run_list) {
if ( ! F_145 ( V_2 -> V_10 . V_73 ) ) {
F_111 ( V_16 , V_2 ) ;
F_147 ( & V_2 -> V_10 . V_364 ) ;
}
}
F_136 ( V_16 , 1 ) ;
}
static void F_148 ( struct V_1 * V_2 , int V_412 )
{
F_149 ( V_413 ) ;
F_150 ( & V_2 -> V_10 . V_364 , & V_413 , V_412 ) ;
if ( V_2 -> V_10 . V_27 == V_148 )
F_151 () ;
F_152 ( & V_2 -> V_10 . V_364 , & V_413 ) ;
}
static void F_153 ( struct V_15 * V_16 )
{
struct V_1 * V_2 ;
int V_414 = 1 ;
F_149 ( V_413 ) ;
F_150 ( & V_16 -> V_159 , & V_413 , V_415 ) ;
F_131 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( V_2 -> V_10 . V_416 || ! V_2 -> V_10 . V_158 ) {
V_414 = 0 ;
break;
}
}
if ( ! V_414 ) {
F_152 ( & V_16 -> V_159 , & V_413 ) ;
return;
}
V_16 -> V_20 = V_417 ;
F_154 ( V_16 , 0 ) ;
F_22 ( & V_16 -> V_44 ) ;
F_151 () ;
F_152 ( & V_16 -> V_159 , & V_413 ) ;
F_21 ( & V_16 -> V_44 ) ;
V_16 -> V_20 = V_21 ;
F_154 ( V_16 , 1 ) ;
}
static int F_155 ( struct V_176 * V_176 , struct V_1 * V_2 )
{
int V_418 ;
struct V_15 * V_16 ;
struct V_1 * V_72 , * V_419 ;
F_156 ( V_2 ) ;
V_176 -> V_181 = 0 ;
V_2 -> V_10 . V_73 = V_174 ;
V_2 -> V_10 . V_48 = 0 ;
F_40 ( V_2 ) ;
V_16 = V_2 -> V_10 . V_17 ;
F_21 ( & V_16 -> V_44 ) ;
V_2 -> V_10 . V_158 = 0 ;
V_2 -> V_10 . V_404 = V_420 ;
V_2 -> V_10 . V_176 = V_176 ;
V_2 -> V_10 . V_121 = F_41 ( V_16 , F_13 () ) ;
V_2 -> V_10 . V_27 = V_148 ;
V_2 -> V_10 . V_29 = V_24 ;
F_157 ( & V_2 -> V_10 . V_378 , & V_16 -> V_343 ) ;
++ V_16 -> V_377 ;
if ( ! F_132 ( V_420 ) ) {
if ( V_16 -> V_20 == V_410 &&
F_158 ( V_16 ) == 0 ) {
F_42 ( V_2 , V_16 ) ;
F_116 ( V_2 ) ;
F_133 ( V_2 ) ;
} else if ( V_16 -> V_20 == V_417 ) {
F_147 ( & V_16 -> V_159 ) ;
}
}
while ( V_2 -> V_10 . V_27 == V_148 &&
! F_132 ( V_420 ) ) {
if ( V_16 -> V_20 != V_21 ) {
F_22 ( & V_16 -> V_44 ) ;
F_148 ( V_2 , V_415 ) ;
F_21 ( & V_16 -> V_44 ) ;
continue;
}
F_146 (v, vn, &vc->runnable_threads,
arch.run_list) {
F_107 ( V_72 ) ;
if ( F_132 ( V_72 -> V_10 . V_404 ) ) {
F_111 ( V_16 , V_72 ) ;
V_72 -> V_6 . V_421 ++ ;
V_72 -> V_10 . V_176 -> V_181 = V_422 ;
V_72 -> V_10 . V_73 = - V_423 ;
F_147 ( & V_72 -> V_10 . V_364 ) ;
}
}
if ( ! V_16 -> V_377 || V_2 -> V_10 . V_27 != V_148 )
break;
V_16 -> V_19 = V_2 ;
V_418 = 0 ;
F_131 (v, &vc->runnable_threads, arch.run_list) {
if ( ! V_72 -> V_10 . V_416 )
V_418 += V_72 -> V_10 . V_158 ;
else
V_72 -> V_10 . V_158 = 0 ;
}
if ( V_418 == V_16 -> V_377 )
F_153 ( V_16 ) ;
else
F_130 ( V_16 ) ;
V_16 -> V_19 = NULL ;
}
while ( V_2 -> V_10 . V_27 == V_148 &&
( V_16 -> V_20 == V_410 ||
V_16 -> V_20 == V_411 ) ) {
F_22 ( & V_16 -> V_44 ) ;
F_148 ( V_2 , V_424 ) ;
F_21 ( & V_16 -> V_44 ) ;
}
if ( V_2 -> V_10 . V_27 == V_148 ) {
F_111 ( V_16 , V_2 ) ;
V_2 -> V_6 . V_421 ++ ;
V_176 -> V_181 = V_422 ;
V_2 -> V_10 . V_73 = - V_423 ;
}
if ( V_16 -> V_377 && V_16 -> V_20 == V_21 ) {
V_72 = F_159 ( & V_16 -> V_343 ,
struct V_1 , V_10 . V_378 ) ;
F_147 ( & V_72 -> V_10 . V_364 ) ;
}
F_160 ( V_2 , V_176 ) ;
F_22 ( & V_16 -> V_44 ) ;
return V_2 -> V_10 . V_73 ;
}
static int F_161 ( struct V_176 * V_177 , struct V_1 * V_2 )
{
int V_45 ;
int V_401 ;
if ( ! V_2 -> V_10 . V_425 ) {
V_177 -> V_181 = V_426 ;
return - V_42 ;
}
F_107 ( V_2 ) ;
if ( F_132 ( V_420 ) ) {
V_177 -> V_181 = V_422 ;
return - V_423 ;
}
F_162 ( & V_2 -> V_68 -> V_10 . V_427 ) ;
F_56 () ;
if ( ! V_2 -> V_68 -> V_10 . V_428 ) {
V_45 = F_163 ( V_2 ) ;
if ( V_45 )
goto V_351;
}
F_164 ( V_420 ) ;
F_165 ( V_420 ) ;
F_166 ( V_420 ) ;
V_2 -> V_10 . V_5 = & V_2 -> V_10 . V_17 -> V_159 ;
V_2 -> V_10 . V_429 = V_420 -> V_430 -> V_431 ;
V_2 -> V_10 . V_27 = V_28 ;
do {
V_45 = F_155 ( V_177 , V_2 ) ;
if ( V_177 -> V_181 == V_204 &&
! ( V_2 -> V_10 . V_32 . V_31 & V_432 ) ) {
F_167 ( V_2 ) ;
V_45 = F_54 ( V_2 ) ;
F_168 ( V_2 , V_45 ) ;
F_107 ( V_2 ) ;
} else if ( V_45 == V_206 ) {
V_401 = F_58 ( & V_2 -> V_68 -> V_164 ) ;
V_45 = F_169 ( V_177 , V_2 ,
V_2 -> V_10 . V_61 , V_2 -> V_10 . V_62 ) ;
F_60 ( & V_2 -> V_68 -> V_164 , V_401 ) ;
}
} while ( F_145 ( V_45 ) );
V_351:
V_2 -> V_10 . V_27 = V_363 ;
F_170 ( & V_2 -> V_68 -> V_10 . V_427 ) ;
return V_45 ;
}
static void F_171 ( struct V_433 * * V_434 ,
int V_435 )
{
struct V_436 * V_437 = & V_438 [ V_435 ] ;
if ( ! V_437 -> V_439 )
return;
( * V_434 ) -> V_440 = V_437 -> V_439 ;
( * V_434 ) -> V_441 = V_437 -> V_442 ;
( * V_434 ) -> V_443 [ 0 ] . V_440 = V_437 -> V_439 ;
( * V_434 ) -> V_443 [ 0 ] . V_444 = V_437 -> V_445 [ V_435 ] ;
if ( V_435 != V_446 && V_437 -> V_445 [ V_446 ] != - 1 ) {
( * V_434 ) -> V_443 [ 1 ] . V_440 = 24 ;
( * V_434 ) -> V_443 [ 1 ] . V_444 = V_437 -> V_445 [ V_446 ] ;
}
( * V_434 ) ++ ;
}
static int F_172 ( struct V_68 * V_68 ,
struct V_447 * V_448 )
{
struct V_433 * V_434 ;
V_448 -> V_18 = V_449 ;
if ( F_173 ( V_450 ) )
V_448 -> V_18 |= V_451 ;
V_448 -> V_452 = V_453 ;
V_434 = & V_448 -> V_434 [ 0 ] ;
F_171 ( & V_434 , V_454 ) ;
F_171 ( & V_434 , V_455 ) ;
F_171 ( & V_434 , V_446 ) ;
return 0 ;
}
static int F_174 ( struct V_68 * V_68 ,
struct V_456 * log )
{
struct V_457 * V_458 ;
int V_45 ;
unsigned long V_459 ;
F_27 ( & V_68 -> V_460 ) ;
V_45 = - V_42 ;
if ( log -> V_461 >= V_462 )
goto V_351;
V_458 = F_175 ( V_68 -> V_463 , log -> V_461 ) ;
V_45 = - V_165 ;
if ( ! V_458 -> V_464 )
goto V_351;
V_459 = F_176 ( V_458 ) ;
memset ( V_458 -> V_464 , 0 , V_459 ) ;
V_45 = F_177 ( V_68 , V_458 , V_458 -> V_464 ) ;
if ( V_45 )
goto V_351;
V_45 = - V_465 ;
if ( F_178 ( log -> V_464 , V_458 -> V_464 , V_459 ) )
goto V_351;
V_45 = 0 ;
V_351:
F_29 ( & V_68 -> V_460 ) ;
return V_45 ;
}
static void F_179 ( struct V_457 * free ,
struct V_457 * V_466 )
{
if ( ! V_466 || free -> V_10 . V_467 != V_466 -> V_10 . V_467 ) {
F_180 ( free -> V_10 . V_467 ) ;
free -> V_10 . V_467 = NULL ;
}
}
static int F_181 ( struct V_457 * V_461 ,
unsigned long V_468 )
{
V_461 -> V_10 . V_467 = F_182 ( V_468 * sizeof( * V_461 -> V_10 . V_467 ) ) ;
if ( ! V_461 -> V_10 . V_467 )
return - V_352 ;
return 0 ;
}
static int F_183 ( struct V_68 * V_68 ,
struct V_457 * V_458 ,
struct V_469 * V_470 )
{
return 0 ;
}
static void F_184 ( struct V_68 * V_68 ,
struct V_469 * V_470 ,
const struct V_457 * V_471 )
{
unsigned long V_468 = V_470 -> V_472 >> V_473 ;
struct V_457 * V_458 ;
if ( V_468 && V_471 -> V_468 ) {
V_458 = F_175 ( V_68 -> V_463 , V_470 -> V_461 ) ;
F_177 ( V_68 , V_458 , NULL ) ;
}
}
void F_185 ( struct V_68 * V_68 , unsigned long V_67 , unsigned long V_229 )
{
long int V_201 ;
T_3 V_474 = 0 ;
if ( ( V_68 -> V_10 . V_67 & V_229 ) == V_67 )
return;
V_68 -> V_10 . V_67 = ( V_68 -> V_10 . V_67 & ~ V_229 ) | V_67 ;
for ( V_201 = 0 ; V_201 < V_350 ; ++ V_201 ) {
struct V_15 * V_16 = V_68 -> V_10 . V_365 [ V_201 ] ;
if ( ! V_16 )
continue;
F_21 ( & V_16 -> V_44 ) ;
V_16 -> V_67 = ( V_16 -> V_67 & ~ V_229 ) | V_67 ;
F_22 ( & V_16 -> V_44 ) ;
if ( ++ V_474 >= V_68 -> V_10 . V_366 )
break;
}
}
static void F_186 ( struct V_1 * V_2 )
{
return;
}
static int F_163 ( struct V_1 * V_2 )
{
int V_92 = 0 ;
struct V_68 * V_68 = V_2 -> V_68 ;
unsigned long V_475 ;
struct V_457 * V_458 ;
struct V_476 * V_477 ;
unsigned long V_67 = 0 , V_478 ;
unsigned long V_479 , V_480 ;
int V_401 ;
F_27 ( & V_68 -> V_44 ) ;
if ( V_68 -> V_10 . V_428 )
goto V_351;
if ( ! V_68 -> V_10 . V_481 ) {
V_92 = F_187 ( V_68 , NULL ) ;
if ( V_92 ) {
F_24 ( L_17 ) ;
goto V_351;
}
}
V_401 = F_58 ( & V_68 -> V_164 ) ;
V_458 = F_188 ( V_68 , 0 ) ;
V_92 = - V_42 ;
if ( ! V_458 || ( V_458 -> V_18 & V_482 ) )
goto V_483;
V_475 = V_458 -> V_484 ;
F_189 ( & V_420 -> V_430 -> V_485 ) ;
V_477 = F_190 ( V_420 -> V_430 , V_475 ) ;
if ( ! V_477 || V_477 -> V_486 > V_475 || ( V_477 -> V_487 & V_488 ) )
goto V_489;
V_479 = F_191 ( V_477 ) ;
V_480 = F_192 ( V_479 ) ;
F_193 ( & V_420 -> V_430 -> V_485 ) ;
V_92 = - V_42 ;
if ( ! ( V_479 == 0x1000 || V_479 == 0x10000 ||
V_479 == 0x1000000 ) )
goto V_483;
V_478 = F_194 ( V_479 ) ;
V_68 -> V_10 . V_490 = V_478 | V_491 |
( V_492 << V_493 ) ;
V_67 = V_478 << ( V_494 - 4 ) ;
F_195 ( V_2 , V_458 , V_480 ) ;
F_185 ( V_68 , V_67 , V_495 ) ;
F_48 () ;
V_68 -> V_10 . V_428 = 1 ;
V_92 = 0 ;
V_483:
F_60 ( & V_68 -> V_164 , V_401 ) ;
V_351:
F_29 ( & V_68 -> V_44 ) ;
return V_92 ;
V_489:
F_193 ( & V_420 -> V_430 -> V_485 ) ;
goto V_483;
}
static int F_196 ( struct V_68 * V_68 )
{
unsigned long V_67 , V_496 ;
V_496 = F_197 () ;
if ( ( long ) V_496 < 0 )
return - V_352 ;
V_68 -> V_10 . V_496 = V_496 ;
F_198 ( & V_68 -> V_10 . V_497 ) ;
memcpy ( V_68 -> V_10 . V_153 , V_498 ,
sizeof( V_68 -> V_10 . V_153 ) ) ;
V_68 -> V_10 . V_499 = F_95 ( V_500 ) ;
V_68 -> V_10 . V_501 = F_95 ( V_502 ) ;
V_68 -> V_10 . V_503 = V_67 = F_95 ( V_504 ) ;
V_67 &= V_505 | V_506 ;
V_67 |= ( 4UL << V_507 ) | V_508 |
V_509 | V_510 ;
V_68 -> V_10 . V_490 = V_491 |
( V_492 << V_493 ) ;
if ( F_20 ( V_43 ) )
V_67 |= V_511 ;
V_68 -> V_10 . V_67 = V_67 ;
F_199 () ;
return 0 ;
}
static void F_200 ( struct V_68 * V_68 )
{
long int V_201 ;
for ( V_201 = 0 ; V_201 < V_350 ; ++ V_201 ) {
if ( V_68 -> V_10 . V_365 [ V_201 ] && V_68 -> V_10 . V_365 [ V_201 ] -> V_347 ) {
struct V_15 * V_16 = V_68 -> V_10 . V_365 [ V_201 ] ;
F_201 ( ( unsigned long ) V_16 -> V_347 ,
V_349 ) ;
}
F_202 ( V_68 -> V_10 . V_365 [ V_201 ] ) ;
}
V_68 -> V_10 . V_366 = 0 ;
}
static void F_203 ( struct V_68 * V_68 )
{
F_204 () ;
F_200 ( V_68 ) ;
F_205 ( V_68 ) ;
}
static int F_206 ( struct V_176 * V_177 , struct V_1 * V_2 ,
unsigned int V_512 , int * V_513 )
{
return V_514 ;
}
static int F_207 ( struct V_1 * V_2 , int V_515 ,
T_4 V_516 )
{
return V_514 ;
}
static int F_208 ( struct V_1 * V_2 , int V_515 ,
T_4 * V_516 )
{
return V_514 ;
}
static int F_209 ( void )
{
if ( ! F_20 ( V_517 ) ||
! F_20 ( V_518 ) )
return - V_519 ;
return 0 ;
}
static long F_210 ( struct V_520 * V_521 ,
unsigned int V_522 , unsigned long V_523 )
{
struct V_68 * V_68 V_524 = V_521 -> V_525 ;
void T_6 * V_526 = ( void T_6 * ) V_523 ;
long V_45 ;
switch ( V_522 ) {
case V_527 : {
T_3 V_528 ;
V_45 = - V_465 ;
if ( F_211 ( V_528 , ( T_3 T_6 * ) V_526 ) )
break;
V_45 = F_212 ( V_68 , & V_528 ) ;
if ( V_45 )
break;
V_45 = - V_465 ;
if ( F_213 ( V_528 , ( T_3 T_6 * ) V_526 ) )
break;
V_45 = 0 ;
break;
}
case V_529 : {
struct V_530 V_531 ;
V_45 = - V_465 ;
if ( F_214 ( & V_531 , V_526 , sizeof( V_531 ) ) )
break;
V_45 = F_215 ( V_68 , & V_531 ) ;
break;
}
default:
V_45 = - V_532 ;
}
return V_45 ;
}
static void F_216 ( void )
{
int V_201 ;
unsigned int V_533 ;
for ( V_201 = 0 ; V_534 [ V_201 ] ; ++ V_201 ) {
V_533 = V_534 [ V_201 ] ;
F_217 ( ! F_64 ( V_533 ) ) ;
F_218 ( V_533 / 4 , V_498 ) ;
}
}
static int F_219 ( void )
{
int V_45 ;
V_45 = F_209 () ;
if ( V_45 < 0 )
return - V_535 ;
V_536 . V_537 = V_538 ;
V_539 = & V_536 ;
F_216 () ;
V_45 = F_220 () ;
return V_45 ;
}
static void F_221 ( void )
{
V_539 = NULL ;
}
