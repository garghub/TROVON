static bool F_1 ( int V_1 )
{
if ( F_2 ( V_2 ) ) {
F_3 () ;
if ( F_4 ( V_1 ) ==
F_4 ( F_5 () ) ) {
unsigned long V_3 = F_6 ( V_4 ) ;
V_3 |= F_7 ( V_1 ) ;
F_8 () ;
__asm__ __volatile__ (PPC_MSGSND(%0) : : "r" (msg));
F_9 () ;
return true ;
}
F_9 () ;
}
#if F_10 ( V_5 ) && F_10 ( V_6 )
if ( V_1 >= 0 && V_1 < V_7 && V_8 [ V_1 ] . V_9 . V_10 ) {
F_11 ( V_1 ) ;
return true ;
}
#endif
return false ;
}
static void F_12 ( struct V_11 * V_12 )
{
int V_1 ;
T_1 * V_13 ;
V_13 = F_13 ( V_12 ) ;
if ( F_14 ( V_13 ) ) {
F_15 ( V_13 ) ;
++ V_12 -> V_14 . V_15 ;
}
if ( F_1 ( V_12 -> V_16 . V_17 ) )
return;
V_1 = V_12 -> V_1 ;
if ( V_1 >= 0 && V_1 < V_7 && F_16 ( V_1 ) )
F_17 ( V_1 ) ;
}
static void F_18 ( struct V_18 * V_19 )
{
unsigned long V_20 ;
F_19 ( & V_19 -> V_21 , V_20 ) ;
V_19 -> V_22 = F_20 () ;
F_21 ( & V_19 -> V_21 , V_20 ) ;
}
static void F_22 ( struct V_18 * V_19 )
{
unsigned long V_20 ;
F_19 ( & V_19 -> V_21 , V_20 ) ;
if ( V_19 -> V_22 != V_23 ) {
V_19 -> V_24 += F_20 () - V_19 -> V_22 ;
V_19 -> V_22 = V_23 ;
}
F_21 ( & V_19 -> V_21 , V_20 ) ;
}
static void F_23 ( struct V_11 * V_12 , int V_1 )
{
struct V_18 * V_19 = V_12 -> V_16 . V_25 ;
unsigned long V_20 ;
if ( V_19 -> V_26 == V_12 && V_19 -> V_27 >= V_28 )
F_22 ( V_19 ) ;
F_19 ( & V_12 -> V_16 . V_29 , V_20 ) ;
if ( V_12 -> V_16 . V_30 == V_31 &&
V_12 -> V_16 . V_32 != V_23 ) {
V_12 -> V_16 . V_33 += F_20 () - V_12 -> V_16 . V_32 ;
V_12 -> V_16 . V_32 = V_23 ;
}
F_21 ( & V_12 -> V_16 . V_29 , V_20 ) ;
}
static void F_24 ( struct V_11 * V_12 )
{
struct V_18 * V_19 = V_12 -> V_16 . V_25 ;
unsigned long V_20 ;
if ( V_19 -> V_26 == V_12 && V_19 -> V_27 >= V_28 )
F_18 ( V_19 ) ;
F_19 ( & V_12 -> V_16 . V_29 , V_20 ) ;
if ( V_12 -> V_16 . V_30 == V_31 )
V_12 -> V_16 . V_32 = F_20 () ;
F_21 ( & V_12 -> V_16 . V_29 , V_20 ) ;
}
static void F_25 ( struct V_11 * V_12 , T_2 V_34 )
{
V_12 -> V_16 . V_35 . V_34 = V_34 ;
F_26 ( V_12 ) ;
}
static void F_27 ( struct V_11 * V_12 , T_3 V_36 )
{
V_12 -> V_16 . V_36 = V_36 ;
}
static int F_28 ( struct V_11 * V_12 , T_3 V_37 )
{
unsigned long V_38 = 0 ;
struct V_18 * V_19 = V_12 -> V_16 . V_25 ;
if ( V_37 ) {
switch ( V_37 ) {
case V_39 :
V_38 = V_40 | V_41 ;
break;
case V_42 :
case V_43 :
V_38 = V_40 ;
break;
case V_44 :
break;
default:
return - V_45 ;
}
if ( ! F_2 ( V_2 ) ) {
if ( ! ( V_38 & V_40 ) )
return - V_45 ;
V_38 &= ~ V_40 ;
}
}
F_29 ( & V_19 -> V_46 ) ;
V_19 -> V_37 = V_37 ;
V_19 -> V_38 = V_38 ;
F_30 ( & V_19 -> V_46 ) ;
return 0 ;
}
static void F_31 ( struct V_11 * V_12 )
{
int V_47 ;
F_32 ( L_1 , V_12 , V_12 -> V_48 ) ;
F_32 ( L_2 ,
V_12 -> V_16 . V_49 , V_12 -> V_16 . V_35 . V_34 , V_12 -> V_16 . V_50 ) ;
for ( V_47 = 0 ; V_47 < 16 ; ++ V_47 )
F_32 ( L_3 ,
V_47 , F_33 ( V_12 , V_47 ) ,
V_47 + 16 , F_33 ( V_12 , V_47 + 16 ) ) ;
F_32 ( L_4 ,
V_12 -> V_16 . V_51 , V_12 -> V_16 . V_52 ) ;
F_32 ( L_5 ,
V_12 -> V_16 . V_35 . V_53 , V_12 -> V_16 . V_35 . V_54 ) ;
F_32 ( L_6 ,
V_12 -> V_16 . V_35 . V_55 , V_12 -> V_16 . V_35 . V_56 ) ;
F_32 ( L_7 ,
V_12 -> V_16 . V_35 . V_57 , V_12 -> V_16 . V_35 . V_58 ) ;
F_32 ( L_8 ,
V_12 -> V_16 . V_59 , V_12 -> V_16 . V_60 , V_12 -> V_16 . V_35 . V_61 ) ;
F_32 ( L_9 , V_12 -> V_16 . V_35 . V_62 ) ;
F_32 ( L_10 ,
V_12 -> V_16 . V_63 , V_12 -> V_16 . V_64 ) ;
F_32 ( L_11 , V_12 -> V_16 . V_65 ) ;
for ( V_47 = 0 ; V_47 < V_12 -> V_16 . V_65 ; ++ V_47 )
F_32 ( L_12 ,
V_12 -> V_16 . V_66 [ V_47 ] . V_67 , V_12 -> V_16 . V_66 [ V_47 ] . V_68 ) ;
F_32 ( L_13 ,
V_12 -> V_16 . V_25 -> V_69 , V_12 -> V_70 -> V_16 . V_71 ,
V_12 -> V_16 . V_72 ) ;
}
static struct V_11 * F_34 ( struct V_70 * V_70 , int V_73 )
{
int V_47 ;
struct V_11 * V_74 , * V_75 = NULL ;
F_35 ( & V_70 -> V_46 ) ;
F_36 (r, v, kvm) {
if ( V_74 -> V_48 == V_73 ) {
V_75 = V_74 ;
break;
}
}
F_37 ( & V_70 -> V_46 ) ;
return V_75 ;
}
static void F_38 ( struct V_11 * V_12 , struct V_76 * V_77 )
{
V_77 -> V_78 |= V_79 ;
V_77 -> V_80 = F_39 ( 1 ) ;
}
static int F_40 ( struct V_11 * V_12 , struct V_81 * V_74 ,
unsigned long V_82 , unsigned long V_83 )
{
if ( V_82 & ( V_84 - 1 ) )
return - V_45 ;
F_29 ( & V_12 -> V_16 . V_85 ) ;
if ( V_74 -> V_86 != V_82 || V_74 -> V_83 != V_83 ) {
V_74 -> V_86 = V_82 ;
V_74 -> V_83 = V_82 ? V_83 : 0 ;
V_74 -> V_87 = 1 ;
}
F_30 ( & V_12 -> V_16 . V_85 ) ;
return 0 ;
}
static int F_41 ( struct V_81 * V_88 )
{
if ( V_88 -> V_87 )
return V_88 -> V_86 != 0 ;
return V_88 -> V_89 != NULL ;
}
static unsigned long F_42 ( struct V_11 * V_12 ,
unsigned long V_20 ,
unsigned long V_90 , unsigned long V_77 )
{
struct V_70 * V_70 = V_12 -> V_70 ;
unsigned long V_83 , V_91 ;
void * V_92 ;
struct V_11 * V_93 ;
int V_94 ;
int V_95 ;
struct V_81 * V_88 ;
V_93 = F_34 ( V_70 , V_90 ) ;
if ( ! V_93 )
return V_96 ;
V_95 = ( V_20 >> V_97 ) & V_98 ;
if ( V_95 == V_99 || V_95 == V_100 ||
V_95 == V_101 ) {
if ( ( V_77 & ( V_84 - 1 ) ) || ! V_77 )
return V_96 ;
V_92 = F_43 ( V_70 , V_77 , & V_91 ) ;
if ( V_92 == NULL )
return V_96 ;
if ( V_95 == V_99 )
V_83 = F_44 ( ( (struct V_102 * ) V_92 ) -> V_103 . V_104 ) ;
else
V_83 = F_45 ( ( (struct V_102 * ) V_92 ) -> V_103 . V_105 ) ;
F_46 ( V_70 , V_92 , V_77 , false ) ;
if ( V_83 > V_91 || V_83 < sizeof( struct V_102 ) )
return V_96 ;
} else {
V_77 = 0 ;
V_83 = 0 ;
}
V_94 = V_96 ;
V_88 = NULL ;
F_29 ( & V_93 -> V_16 . V_85 ) ;
switch ( V_95 ) {
case V_99 :
if ( V_83 < sizeof( struct V_76 ) )
break;
V_88 = & V_93 -> V_16 . V_77 ;
V_94 = 0 ;
break;
case V_100 :
if ( V_83 < sizeof( struct V_106 ) )
break;
V_83 -= V_83 % sizeof( struct V_106 ) ;
V_94 = V_107 ;
if ( ! F_41 ( & V_93 -> V_16 . V_77 ) )
break;
V_88 = & V_93 -> V_16 . V_108 ;
V_94 = 0 ;
break;
case V_101 :
V_94 = V_107 ;
if ( ! F_41 ( & V_93 -> V_16 . V_77 ) )
break;
V_88 = & V_93 -> V_16 . V_109 ;
V_94 = 0 ;
break;
case V_110 :
V_94 = V_107 ;
if ( F_41 ( & V_93 -> V_16 . V_108 ) ||
F_41 ( & V_93 -> V_16 . V_109 ) )
break;
V_88 = & V_93 -> V_16 . V_77 ;
V_94 = 0 ;
break;
case V_111 :
V_88 = & V_93 -> V_16 . V_108 ;
V_94 = 0 ;
break;
case V_112 :
V_88 = & V_93 -> V_16 . V_109 ;
V_94 = 0 ;
break;
}
if ( V_88 ) {
V_88 -> V_86 = V_77 ;
V_88 -> V_83 = V_83 ;
V_88 -> V_87 = 1 ;
}
F_30 ( & V_93 -> V_16 . V_85 ) ;
return V_94 ;
}
static void F_47 ( struct V_11 * V_12 , struct V_81 * V_88 )
{
struct V_70 * V_70 = V_12 -> V_70 ;
void * V_92 ;
unsigned long V_91 ;
unsigned long V_113 ;
for (; ; ) {
V_113 = V_88 -> V_86 ;
F_30 ( & V_12 -> V_16 . V_85 ) ;
V_92 = NULL ;
V_91 = 0 ;
if ( V_113 )
V_92 = F_43 ( V_70 , V_113 , & V_91 ) ;
F_29 ( & V_12 -> V_16 . V_85 ) ;
if ( V_113 == V_88 -> V_86 )
break;
if ( V_92 )
F_46 ( V_70 , V_92 , V_113 , false ) ;
}
V_88 -> V_87 = 0 ;
if ( V_92 && V_91 < V_88 -> V_83 ) {
F_46 ( V_70 , V_92 , V_113 , false ) ;
V_92 = NULL ;
}
if ( V_88 -> V_89 )
F_46 ( V_70 , V_88 -> V_89 , V_88 -> V_113 ,
V_88 -> V_114 ) ;
V_88 -> V_113 = V_113 ;
V_88 -> V_89 = V_92 ;
V_88 -> V_114 = false ;
if ( V_92 )
V_88 -> V_115 = V_92 + V_88 -> V_83 ;
}
static void F_48 ( struct V_11 * V_12 )
{
if ( ! ( V_12 -> V_16 . V_77 . V_87 ||
V_12 -> V_16 . V_109 . V_87 ||
V_12 -> V_16 . V_108 . V_87 ) )
return;
F_29 ( & V_12 -> V_16 . V_85 ) ;
if ( V_12 -> V_16 . V_77 . V_87 ) {
F_47 ( V_12 , & V_12 -> V_16 . V_77 ) ;
if ( V_12 -> V_16 . V_77 . V_89 )
F_38 ( V_12 , V_12 -> V_16 . V_77 . V_89 ) ;
}
if ( V_12 -> V_16 . V_108 . V_87 ) {
F_47 ( V_12 , & V_12 -> V_16 . V_108 ) ;
V_12 -> V_16 . V_116 = V_12 -> V_16 . V_108 . V_89 ;
V_12 -> V_16 . V_117 = 0 ;
}
if ( V_12 -> V_16 . V_109 . V_87 )
F_47 ( V_12 , & V_12 -> V_16 . V_109 ) ;
F_30 ( & V_12 -> V_16 . V_85 ) ;
}
static T_2 F_49 ( struct V_18 * V_19 , T_2 V_118 )
{
T_2 V_119 ;
unsigned long V_20 ;
F_19 ( & V_19 -> V_21 , V_20 ) ;
V_119 = V_19 -> V_24 ;
if ( V_19 -> V_27 != V_120 &&
V_19 -> V_22 != V_23 )
V_119 += V_118 - V_19 -> V_22 ;
F_21 ( & V_19 -> V_21 , V_20 ) ;
return V_119 ;
}
static void F_50 ( struct V_11 * V_12 ,
struct V_18 * V_19 )
{
struct V_106 * V_121 ;
struct V_76 * V_77 ;
unsigned long V_122 ;
unsigned long V_123 ;
T_2 V_118 ;
V_121 = V_12 -> V_16 . V_116 ;
V_77 = V_12 -> V_16 . V_77 . V_89 ;
V_118 = F_20 () ;
V_123 = F_49 ( V_19 , V_118 ) ;
V_122 = V_123 - V_12 -> V_16 . V_124 ;
V_12 -> V_16 . V_124 = V_123 ;
F_51 ( & V_12 -> V_16 . V_29 ) ;
V_122 += V_12 -> V_16 . V_33 ;
V_12 -> V_16 . V_33 = 0 ;
F_52 ( & V_12 -> V_16 . V_29 ) ;
if ( ! V_121 || ! V_77 )
return;
memset ( V_121 , 0 , sizeof( struct V_106 ) ) ;
V_121 -> V_125 = 7 ;
V_121 -> V_126 = F_53 ( V_19 -> V_127 + V_12 -> V_16 . V_128 ) ;
V_121 -> V_129 = F_54 ( V_118 + V_19 -> V_130 ) ;
V_121 -> V_131 = F_39 ( V_122 ) ;
V_121 -> V_53 = F_54 ( F_55 ( V_12 ) ) ;
V_121 -> V_54 = F_54 ( V_12 -> V_16 . V_35 . V_34 ) ;
++ V_121 ;
if ( V_121 == V_12 -> V_16 . V_108 . V_115 )
V_121 = V_12 -> V_16 . V_108 . V_89 ;
V_12 -> V_16 . V_116 = V_121 ;
F_56 () ;
V_77 -> V_132 = F_54 ( ++ V_12 -> V_16 . V_117 ) ;
V_12 -> V_16 . V_108 . V_114 = true ;
}
static bool F_57 ( struct V_11 * V_12 )
{
if ( V_12 -> V_16 . V_25 -> V_37 >= V_44 )
return true ;
if ( ( ! V_12 -> V_16 . V_25 -> V_37 ) &&
F_2 ( V_2 ) )
return true ;
return false ;
}
static int F_58 ( struct V_11 * V_12 , unsigned long V_133 ,
unsigned long V_134 , unsigned long V_135 ,
unsigned long V_136 )
{
switch ( V_134 ) {
case V_137 :
if ( ! F_57 ( V_12 ) )
return V_138 ;
if ( V_136 )
return V_139 ;
if ( V_133 )
return V_140 ;
if ( ( V_135 & V_141 ) == V_142 )
return V_143 ;
V_12 -> V_16 . V_144 = V_135 ;
return V_145 ;
case V_146 :
if ( ! F_57 ( V_12 ) )
return V_138 ;
if ( V_133 )
return V_140 ;
if ( V_136 & V_147 )
return V_139 ;
V_12 -> V_16 . V_148 = V_135 ;
V_12 -> V_16 . V_149 = V_136 ;
return V_145 ;
default:
return V_150 ;
}
}
static int F_59 ( struct V_11 * V_151 )
{
struct V_18 * V_25 = V_151 -> V_16 . V_25 ;
F_29 ( & V_25 -> V_46 ) ;
if ( V_151 -> V_16 . V_30 == V_152 &&
V_25 -> V_27 != V_120 &&
V_25 -> V_26 )
V_151 = V_25 -> V_26 ;
F_30 ( & V_25 -> V_46 ) ;
return F_60 ( V_151 ) ;
}
static int F_61 ( struct V_11 * V_12 )
{
int V_80 = 0 ;
struct V_76 * V_76 ;
F_29 ( & V_12 -> V_16 . V_85 ) ;
V_76 = (struct V_76 * ) V_12 -> V_16 . V_77 . V_89 ;
if ( V_76 )
V_80 = F_45 ( V_76 -> V_80 ) ;
F_30 ( & V_12 -> V_16 . V_85 ) ;
return V_80 ;
}
int F_62 ( struct V_11 * V_12 )
{
unsigned long V_153 = F_33 ( V_12 , 3 ) ;
unsigned long V_151 , V_75 = V_145 ;
int V_80 ;
struct V_11 * V_93 ;
int V_154 , V_155 ;
if ( V_153 <= V_156 &&
! F_63 ( V_153 / 4 , V_12 -> V_70 -> V_16 . V_157 ) )
return V_158 ;
switch ( V_153 ) {
case V_159 :
break;
case V_160 :
V_151 = F_33 ( V_12 , 4 ) ;
V_93 = F_34 ( V_12 -> V_70 , V_151 ) ;
if ( ! V_93 ) {
V_75 = V_96 ;
break;
}
V_93 -> V_16 . V_161 = 1 ;
F_8 () ;
if ( V_12 -> V_16 . V_162 ) {
if ( F_14 ( & V_12 -> V_163 ) ) {
F_15 ( & V_12 -> V_163 ) ;
V_12 -> V_14 . V_15 ++ ;
}
}
break;
case V_164 :
V_151 = F_33 ( V_12 , 4 ) ;
if ( V_151 == - 1 )
break;
V_93 = F_34 ( V_12 -> V_70 , V_151 ) ;
if ( ! V_93 ) {
V_75 = V_96 ;
break;
}
V_80 = F_33 ( V_12 , 5 ) ;
if ( F_61 ( V_93 ) != V_80 )
break;
F_59 ( V_93 ) ;
break;
case V_165 :
V_75 = F_42 ( V_12 , F_33 ( V_12 , 4 ) ,
F_33 ( V_12 , 5 ) ,
F_33 ( V_12 , 6 ) ) ;
break;
case V_166 :
if ( F_64 ( & V_12 -> V_70 -> V_16 . V_167 ) )
return V_158 ;
V_154 = F_65 ( & V_12 -> V_70 -> V_168 ) ;
V_155 = F_66 ( V_12 ) ;
F_67 ( & V_12 -> V_70 -> V_168 , V_154 ) ;
if ( V_155 == - V_169 )
return V_158 ;
else if ( V_155 == 0 )
break;
return V_155 ;
case V_170 :
V_75 = F_68 ( V_12 ) ;
if ( V_75 == V_150 )
return V_158 ;
break;
case V_171 :
V_75 = F_69 ( V_12 ) ;
if ( V_75 == V_150 )
return V_158 ;
break;
case V_172 :
V_75 = F_58 ( V_12 , F_33 ( V_12 , 4 ) ,
F_33 ( V_12 , 5 ) ,
F_33 ( V_12 , 6 ) ,
F_33 ( V_12 , 7 ) ) ;
if ( V_75 == V_150 )
return V_158 ;
break;
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
if ( F_70 ( V_12 ) ) {
V_75 = F_71 ( V_12 , V_153 ) ;
break;
}
default:
return V_158 ;
}
F_72 ( V_12 , 3 , V_75 ) ;
V_12 -> V_16 . V_179 = 0 ;
return V_180 ;
}
static int F_73 ( unsigned long V_181 )
{
switch ( V_181 ) {
case V_159 :
case V_160 :
case V_164 :
case V_165 :
case V_172 :
case V_170 :
case V_171 :
#ifdef F_74
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
#endif
return 1 ;
}
return F_75 ( V_181 ) ;
}
static int F_76 ( struct V_182 * V_183 ,
struct V_11 * V_12 )
{
T_3 V_72 ;
if ( F_77 ( V_12 , V_184 , & V_72 ) !=
V_185 ) {
return V_180 ;
}
if ( V_72 == V_186 ) {
V_183 -> V_187 = V_188 ;
V_183 -> V_189 . V_16 . V_190 = F_55 ( V_12 ) ;
return V_158 ;
} else {
F_78 ( V_12 , V_191 ) ;
return V_180 ;
}
}
static int F_79 ( struct V_182 * V_183 , struct V_11 * V_12 ,
struct V_192 * V_193 )
{
int V_47 = V_158 ;
V_12 -> V_14 . V_194 ++ ;
V_183 -> V_187 = V_195 ;
V_183 -> V_196 = 1 ;
switch ( V_12 -> V_16 . V_50 ) {
case V_197 :
V_12 -> V_14 . V_198 ++ ;
V_47 = V_180 ;
break;
case V_199 :
case V_200 :
V_12 -> V_14 . V_201 ++ ;
V_47 = V_180 ;
break;
case V_202 :
case V_203 :
V_47 = V_180 ;
break;
case V_204 :
F_80 ( V_12 ,
V_204 ) ;
V_47 = V_180 ;
break;
case V_205 :
{
T_4 V_20 ;
V_20 = V_12 -> V_16 . V_35 . V_34 & 0x1f0000ull ;
F_78 ( V_12 , V_20 ) ;
V_47 = V_180 ;
break;
}
case V_206 :
{
int V_207 ;
V_183 -> V_208 . V_209 = F_33 ( V_12 , 3 ) ;
for ( V_207 = 0 ; V_207 < 9 ; ++ V_207 )
V_183 -> V_208 . args [ V_207 ] = F_33 ( V_12 , 4 + V_207 ) ;
V_183 -> V_187 = V_210 ;
V_12 -> V_16 . V_179 = 1 ;
V_47 = V_158 ;
break;
}
case V_211 :
V_47 = V_212 ;
break;
case V_213 :
V_12 -> V_16 . V_63 = F_55 ( V_12 ) ;
V_12 -> V_16 . V_64 = 0 ;
V_47 = V_212 ;
break;
case V_214 :
if ( V_12 -> V_16 . V_215 != V_216 )
V_12 -> V_16 . V_72 = F_81 ( V_12 ) ?
F_82 ( V_12 -> V_16 . V_215 ) :
V_12 -> V_16 . V_215 ;
if ( V_12 -> V_217 & V_218 ) {
V_47 = F_76 ( V_183 , V_12 ) ;
} else {
F_78 ( V_12 , V_191 ) ;
V_47 = V_180 ;
}
break;
case V_219 :
F_78 ( V_12 , V_191 ) ;
V_47 = V_180 ;
break;
default:
F_31 ( V_12 ) ;
F_83 ( V_220 L_14 ,
V_12 -> V_16 . V_50 , F_55 ( V_12 ) ,
V_12 -> V_16 . V_35 . V_34 ) ;
V_183 -> V_221 . V_222 = V_12 -> V_16 . V_50 ;
V_47 = V_158 ;
break;
}
return V_47 ;
}
static int F_84 ( struct V_11 * V_12 ,
struct V_223 * V_224 )
{
int V_207 ;
memset ( V_224 , 0 , sizeof( struct V_223 ) ) ;
V_224 -> V_36 = V_12 -> V_16 . V_36 ;
for ( V_207 = 0 ; V_207 < V_12 -> V_16 . V_65 ; V_207 ++ ) {
V_224 -> V_225 . V_226 . V_227 . V_66 [ V_207 ] . V_228 = V_12 -> V_16 . V_66 [ V_207 ] . V_67 ;
V_224 -> V_225 . V_226 . V_227 . V_66 [ V_207 ] . V_229 = V_12 -> V_16 . V_66 [ V_207 ] . V_68 ;
}
return 0 ;
}
static int F_85 ( struct V_11 * V_12 ,
struct V_223 * V_224 )
{
int V_207 , V_230 ;
if ( V_224 -> V_36 != V_12 -> V_16 . V_36 )
return - V_45 ;
V_230 = 0 ;
for ( V_207 = 0 ; V_207 < V_12 -> V_16 . V_231 ; V_207 ++ ) {
if ( V_224 -> V_225 . V_226 . V_227 . V_66 [ V_207 ] . V_228 & V_232 ) {
V_12 -> V_16 . V_66 [ V_230 ] . V_67 = V_224 -> V_225 . V_226 . V_227 . V_66 [ V_207 ] . V_228 ;
V_12 -> V_16 . V_66 [ V_230 ] . V_68 = V_224 -> V_225 . V_226 . V_227 . V_66 [ V_207 ] . V_229 ;
++ V_230 ;
}
}
V_12 -> V_16 . V_65 = V_230 ;
return 0 ;
}
static void F_86 ( struct V_11 * V_12 , T_2 V_233 ,
bool V_234 )
{
struct V_70 * V_70 = V_12 -> V_70 ;
struct V_18 * V_19 = V_12 -> V_16 . V_25 ;
T_2 V_235 ;
F_35 ( & V_70 -> V_46 ) ;
F_29 ( & V_19 -> V_46 ) ;
if ( ( V_233 & V_236 ) != ( V_19 -> V_69 & V_236 ) ) {
struct V_11 * V_12 ;
int V_207 ;
F_36 (i, vcpu, kvm) {
if ( V_12 -> V_16 . V_25 != V_19 )
continue;
if ( V_233 & V_236 )
V_12 -> V_16 . V_237 |= V_238 ;
else
V_12 -> V_16 . V_237 &= ~ V_238 ;
}
}
V_235 = V_239 | V_236 | V_240 ;
if ( F_2 ( V_2 ) )
V_235 |= V_241 ;
if ( V_234 )
V_235 &= 0xFFFFFFFF ;
V_19 -> V_69 = ( V_19 -> V_69 & ~ V_235 ) | ( V_233 & V_235 ) ;
F_30 ( & V_19 -> V_46 ) ;
F_37 ( & V_70 -> V_46 ) ;
}
static int F_87 ( struct V_11 * V_12 , T_2 V_73 ,
union V_242 * V_243 )
{
int V_47 = 0 ;
long int V_207 ;
switch ( V_73 ) {
case V_244 :
* V_243 = F_88 ( V_73 , V_186 ) ;
break;
case V_245 :
* V_243 = F_88 ( V_73 , 0 ) ;
break;
case V_246 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_247 ) ;
break;
case V_248 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_249 ) ;
break;
case V_250 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_251 ) ;
break;
case V_252 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_253 ) ;
break;
case V_254 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_255 ) ;
break;
case V_256 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_257 ) ;
break;
case V_258 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_259 ) ;
break;
case V_260 ... V_261 :
V_207 = V_73 - V_260 ;
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_262 [ V_207 ] ) ;
break;
case V_263 ... V_264 :
V_207 = V_73 - V_263 ;
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_265 [ V_207 ] ) ;
break;
case V_266 ... V_267 :
V_207 = V_73 - V_266 ;
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_268 [ V_207 ] ) ;
break;
case V_269 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_270 ) ;
break;
case V_271 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_272 ) ;
break;
case V_273 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_274 ) ;
break;
case V_275 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_276 ) ;
break;
case V_277 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_278 ) ;
break;
case V_279 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_25 -> V_280 ) ;
break;
case V_281 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_148 ) ;
break;
case V_282 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_149 ) ;
break;
case V_283 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_144 ) ;
break;
case V_284 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_285 ) ;
break;
case V_286 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_287 ) ;
break;
case V_288 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_289 ) ;
break;
case V_290 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_291 ) ;
break;
case V_292 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_293 ) ;
break;
case V_294 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_295 ) ;
break;
case V_296 :
F_29 ( & V_12 -> V_16 . V_85 ) ;
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_77 . V_86 ) ;
F_30 ( & V_12 -> V_16 . V_85 ) ;
break;
case V_297 :
F_29 ( & V_12 -> V_16 . V_85 ) ;
V_243 -> V_298 . V_82 = V_12 -> V_16 . V_109 . V_86 ;
V_243 -> V_298 . V_103 = V_12 -> V_16 . V_109 . V_83 ;
F_30 ( & V_12 -> V_16 . V_85 ) ;
break;
case V_299 :
F_29 ( & V_12 -> V_16 . V_85 ) ;
V_243 -> V_298 . V_82 = V_12 -> V_16 . V_108 . V_86 ;
V_243 -> V_298 . V_103 = V_12 -> V_16 . V_108 . V_83 ;
F_30 ( & V_12 -> V_16 . V_85 ) ;
break;
case V_300 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_25 -> V_130 ) ;
break;
case V_301 :
case V_302 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_25 -> V_69 ) ;
break;
case V_303 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_304 ) ;
break;
#ifdef F_89
case V_305 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_306 ) ;
break;
case V_307 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_308 ) ;
break;
case V_309 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_310 ) ;
break;
case V_311 ... V_312 :
V_207 = V_73 - V_311 ;
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_313 [ V_207 ] ) ;
break;
case V_314 ... V_315 :
{
int V_230 ;
V_207 = V_73 - V_314 ;
if ( V_207 < 32 )
for ( V_230 = 0 ; V_230 < V_316 ; V_230 ++ )
V_243 -> V_317 [ V_230 ] = V_12 -> V_16 . V_318 . V_319 [ V_207 ] [ V_230 ] ;
else {
if ( F_2 ( V_320 ) )
V_243 -> V_321 = V_12 -> V_16 . V_322 . V_323 [ V_207 - 32 ] ;
else
V_47 = - V_324 ;
}
break;
}
case V_325 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_326 ) ;
break;
case V_327 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_328 ) ;
break;
case V_329 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_330 ) ;
break;
case V_331 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_318 . V_332 ) ;
break;
case V_333 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_334 ) ;
break;
case V_335 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_336 ) ;
break;
case V_337 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_338 ) ;
break;
case V_339 :
if ( F_2 ( V_320 ) )
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_322 . V_340 . V_225 [ 3 ] ) ;
else
V_47 = - V_324 ;
break;
case V_341 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_342 ) ;
break;
case V_343 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_344 ) ;
break;
#endif
case V_345 :
* V_243 = F_88 ( V_73 , V_12 -> V_16 . V_25 -> V_37 ) ;
break;
default:
V_47 = - V_45 ;
break;
}
return V_47 ;
}
static int F_90 ( struct V_11 * V_12 , T_2 V_73 ,
union V_242 * V_243 )
{
int V_47 = 0 ;
long int V_207 ;
unsigned long V_82 , V_83 ;
switch ( V_73 ) {
case V_245 :
if ( F_91 ( V_73 , * V_243 ) )
V_47 = - V_45 ;
break;
case V_246 :
V_12 -> V_16 . V_247 = F_91 ( V_73 , * V_243 ) ;
break;
case V_248 :
V_12 -> V_16 . V_249 = F_91 ( V_73 , * V_243 ) & ~ V_147 ;
break;
case V_250 :
V_12 -> V_16 . V_251 = F_91 ( V_73 , * V_243 ) ;
break;
case V_252 :
V_12 -> V_16 . V_253 = F_91 ( V_73 , * V_243 ) ;
break;
case V_254 :
V_12 -> V_16 . V_255 = F_91 ( V_73 , * V_243 ) ;
break;
case V_256 :
V_12 -> V_16 . V_257 = F_91 ( V_73 , * V_243 ) ;
break;
case V_258 :
V_12 -> V_16 . V_259 = F_91 ( V_73 , * V_243 ) ;
break;
case V_260 ... V_261 :
V_207 = V_73 - V_260 ;
V_12 -> V_16 . V_262 [ V_207 ] = F_91 ( V_73 , * V_243 ) ;
break;
case V_263 ... V_264 :
V_207 = V_73 - V_263 ;
V_12 -> V_16 . V_265 [ V_207 ] = F_91 ( V_73 , * V_243 ) ;
break;
case V_266 ... V_267 :
V_207 = V_73 - V_266 ;
V_12 -> V_16 . V_268 [ V_207 ] = F_91 ( V_73 , * V_243 ) ;
break;
case V_269 :
V_12 -> V_16 . V_270 = F_91 ( V_73 , * V_243 ) ;
break;
case V_271 :
V_12 -> V_16 . V_272 = F_91 ( V_73 , * V_243 ) ;
break;
case V_273 :
V_12 -> V_16 . V_274 = F_91 ( V_73 , * V_243 ) ;
break;
case V_275 :
V_12 -> V_16 . V_276 = F_91 ( V_73 , * V_243 ) ;
break;
case V_277 :
V_12 -> V_16 . V_278 = F_91 ( V_73 , * V_243 ) ;
break;
case V_279 :
V_12 -> V_16 . V_25 -> V_280 = F_91 ( V_73 , * V_243 ) ;
break;
case V_281 :
V_12 -> V_16 . V_148 = F_91 ( V_73 , * V_243 ) ;
break;
case V_282 :
V_12 -> V_16 . V_149 = F_91 ( V_73 , * V_243 ) & ~ V_346 ;
break;
case V_283 :
V_12 -> V_16 . V_144 = F_91 ( V_73 , * V_243 ) ;
if ( ( V_12 -> V_16 . V_144 & V_141 ) == V_142 )
V_12 -> V_16 . V_144 &= ~ V_141 ;
break;
case V_284 :
V_12 -> V_16 . V_285 = F_91 ( V_73 , * V_243 ) ;
break;
case V_286 :
V_12 -> V_16 . V_287 = F_91 ( V_73 , * V_243 ) ;
break;
case V_288 :
V_12 -> V_16 . V_289 = F_91 ( V_73 , * V_243 ) ;
break;
case V_290 :
V_12 -> V_16 . V_291 = F_91 ( V_73 , * V_243 ) ;
break;
case V_292 :
V_12 -> V_16 . V_293 = F_91 ( V_73 , * V_243 ) ;
break;
case V_294 :
V_12 -> V_16 . V_295 = F_91 ( V_73 , * V_243 ) ;
break;
case V_296 :
V_82 = F_91 ( V_73 , * V_243 ) ;
V_47 = - V_45 ;
if ( ! V_82 && ( V_12 -> V_16 . V_109 . V_86 ||
V_12 -> V_16 . V_108 . V_86 ) )
break;
V_47 = F_40 ( V_12 , & V_12 -> V_16 . V_77 , V_82 , sizeof( struct V_76 ) ) ;
break;
case V_297 :
V_82 = V_243 -> V_298 . V_82 ;
V_83 = V_243 -> V_298 . V_103 ;
V_47 = - V_45 ;
if ( V_82 && ! V_12 -> V_16 . V_77 . V_86 )
break;
V_47 = F_40 ( V_12 , & V_12 -> V_16 . V_109 , V_82 , V_83 ) ;
break;
case V_299 :
V_82 = V_243 -> V_298 . V_82 ;
V_83 = V_243 -> V_298 . V_103 ;
V_47 = - V_45 ;
if ( V_82 && ( V_83 < sizeof( struct V_106 ) ||
! V_12 -> V_16 . V_77 . V_86 ) )
break;
V_83 -= V_83 % sizeof( struct V_106 ) ;
V_47 = F_40 ( V_12 , & V_12 -> V_16 . V_108 , V_82 , V_83 ) ;
break;
case V_300 :
V_12 -> V_16 . V_25 -> V_130 =
F_92 ( F_91 ( V_73 , * V_243 ) , 1UL << 24 ) ;
break;
case V_301 :
F_86 ( V_12 , F_91 ( V_73 , * V_243 ) , true ) ;
break;
case V_302 :
F_86 ( V_12 , F_91 ( V_73 , * V_243 ) , false ) ;
break;
case V_303 :
V_12 -> V_16 . V_304 = F_91 ( V_73 , * V_243 ) ;
break;
#ifdef F_89
case V_305 :
V_12 -> V_16 . V_306 = F_91 ( V_73 , * V_243 ) ;
break;
case V_307 :
V_12 -> V_16 . V_308 = F_91 ( V_73 , * V_243 ) ;
break;
case V_309 :
V_12 -> V_16 . V_310 = F_91 ( V_73 , * V_243 ) ;
break;
case V_311 ... V_312 :
V_207 = V_73 - V_311 ;
V_12 -> V_16 . V_313 [ V_207 ] = F_91 ( V_73 , * V_243 ) ;
break;
case V_314 ... V_315 :
{
int V_230 ;
V_207 = V_73 - V_314 ;
if ( V_207 < 32 )
for ( V_230 = 0 ; V_230 < V_316 ; V_230 ++ )
V_12 -> V_16 . V_318 . V_319 [ V_207 ] [ V_230 ] = V_243 -> V_317 [ V_230 ] ;
else
if ( F_2 ( V_320 ) )
V_12 -> V_16 . V_322 . V_323 [ V_207 - 32 ] = V_243 -> V_321 ;
else
V_47 = - V_324 ;
break;
}
case V_325 :
V_12 -> V_16 . V_326 = F_91 ( V_73 , * V_243 ) ;
break;
case V_327 :
V_12 -> V_16 . V_328 = F_91 ( V_73 , * V_243 ) ;
break;
case V_329 :
V_12 -> V_16 . V_330 = F_91 ( V_73 , * V_243 ) ;
break;
case V_331 :
V_12 -> V_16 . V_318 . V_332 = F_91 ( V_73 , * V_243 ) ;
break;
case V_333 :
V_12 -> V_16 . V_334 = F_91 ( V_73 , * V_243 ) ;
break;
case V_335 :
V_12 -> V_16 . V_336 = F_91 ( V_73 , * V_243 ) ;
break;
case V_337 :
V_12 -> V_16 . V_338 = F_91 ( V_73 , * V_243 ) ;
break;
case V_339 :
if ( F_2 ( V_320 ) )
V_12 -> V_16 . V_323 . V_340 . V_225 [ 3 ] = F_91 ( V_73 , * V_243 ) ;
else
V_47 = - V_324 ;
break;
case V_341 :
V_12 -> V_16 . V_342 = F_91 ( V_73 , * V_243 ) ;
break;
case V_343 :
V_12 -> V_16 . V_344 = F_91 ( V_73 , * V_243 ) ;
break;
#endif
case V_345 :
V_47 = F_28 ( V_12 , F_91 ( V_73 , * V_243 ) ) ;
break;
default:
V_47 = - V_45 ;
break;
}
return V_47 ;
}
static struct V_18 * F_93 ( struct V_70 * V_70 , int V_347 )
{
struct V_18 * V_25 ;
V_25 = F_94 ( sizeof( struct V_18 ) , V_348 ) ;
if ( V_25 == NULL )
return NULL ;
F_95 ( & V_25 -> V_349 ) ;
F_96 ( & V_25 -> V_46 ) ;
F_96 ( & V_25 -> V_21 ) ;
F_97 ( & V_25 -> V_163 ) ;
V_25 -> V_22 = V_23 ;
V_25 -> V_69 = V_70 -> V_16 . V_69 ;
V_25 -> V_350 = V_347 * V_351 ;
V_25 -> V_70 = V_70 ;
F_95 ( & V_25 -> V_352 ) ;
return V_25 ;
}
static int F_98 ( struct V_353 * V_353 , struct V_354 * V_354 )
{
struct V_11 * V_12 = V_353 -> V_355 ;
struct V_356 * V_119 ;
V_119 = F_94 ( sizeof( * V_119 ) , V_348 ) ;
if ( ! V_119 )
return - V_357 ;
F_99 ( V_12 -> V_70 ) ;
V_119 -> V_12 = V_12 ;
V_354 -> V_358 = V_119 ;
return F_100 ( V_353 , V_354 ) ;
}
static int F_101 ( struct V_353 * V_353 , struct V_354 * V_354 )
{
struct V_356 * V_119 = V_354 -> V_358 ;
F_102 ( V_119 -> V_12 -> V_70 ) ;
F_103 ( V_119 ) ;
return 0 ;
}
static T_5 F_104 ( struct V_354 * V_354 , char T_6 * V_359 ,
T_7 V_83 , T_8 * V_360 )
{
struct V_356 * V_119 = V_354 -> V_358 ;
struct V_11 * V_12 = V_119 -> V_12 ;
char * V_226 , * V_361 ;
struct V_362 V_363 ;
T_2 V_364 ;
T_8 V_365 ;
T_5 V_366 ;
int V_207 , V_367 ;
bool V_368 ;
if ( ! V_119 -> V_369 ) {
V_226 = V_119 -> V_359 ;
V_361 = V_226 + sizeof( V_119 -> V_359 ) ;
for ( V_207 = 0 ; V_207 < V_370 ; ++ V_207 ) {
struct V_362 * V_371 ;
V_371 = (struct V_362 * )
( ( unsigned long ) V_12 + V_372 [ V_207 ] . V_373 ) ;
V_368 = false ;
for ( V_367 = 0 ; V_367 < 1000 ; ++ V_367 ) {
V_364 = V_371 -> V_374 ;
if ( ! ( V_364 & 1 ) ) {
F_105 () ;
V_363 = * V_371 ;
F_105 () ;
if ( V_364 == V_371 -> V_374 ) {
V_368 = true ;
break;
}
}
F_106 ( 1 ) ;
}
if ( ! V_368 )
snprintf ( V_226 , V_361 - V_226 , L_15 ,
V_372 [ V_207 ] . V_375 ) ;
else
snprintf ( V_226 , V_361 - V_226 ,
L_16 ,
V_372 [ V_207 ] . V_375 , V_364 / 2 ,
F_107 ( V_363 . V_376 ) ,
F_107 ( V_363 . V_377 ) ,
F_107 ( V_363 . V_378 ) ) ;
V_226 += strlen ( V_226 ) ;
}
V_119 -> V_369 = V_226 - V_119 -> V_359 ;
}
V_365 = * V_360 ;
if ( V_365 >= V_119 -> V_369 )
return 0 ;
if ( V_83 > V_119 -> V_369 - V_365 )
V_83 = V_119 -> V_369 - V_365 ;
V_366 = F_108 ( V_359 , V_119 -> V_359 + V_365 , V_83 ) ;
if ( V_366 ) {
if ( V_366 == V_83 )
return - V_379 ;
V_83 -= V_366 ;
}
* V_360 = V_365 + V_83 ;
return V_83 ;
}
static T_5 F_109 ( struct V_354 * V_354 , const char T_6 * V_359 ,
T_7 V_83 , T_8 * V_360 )
{
return - V_380 ;
}
static void F_110 ( struct V_11 * V_12 , unsigned int V_73 )
{
char V_359 [ 16 ] ;
struct V_70 * V_70 = V_12 -> V_70 ;
snprintf ( V_359 , sizeof( V_359 ) , L_17 , V_73 ) ;
if ( F_111 ( V_70 -> V_16 . V_381 ) )
return;
V_12 -> V_16 . V_381 = F_112 ( V_359 , V_70 -> V_16 . V_381 ) ;
if ( F_111 ( V_12 -> V_16 . V_381 ) )
return;
V_12 -> V_16 . V_382 =
F_113 ( L_18 , 0444 , V_12 -> V_16 . V_381 ,
V_12 , & V_383 ) ;
}
static void F_110 ( struct V_11 * V_12 , unsigned int V_73 )
{
}
static struct V_11 * F_114 ( struct V_70 * V_70 ,
unsigned int V_73 )
{
struct V_11 * V_12 ;
int V_94 = - V_45 ;
int V_347 ;
struct V_18 * V_25 ;
V_347 = V_73 / V_351 ;
if ( V_347 >= V_384 )
goto V_385;
V_94 = - V_357 ;
V_12 = F_115 ( V_386 , V_348 ) ;
if ( ! V_12 )
goto V_385;
V_94 = F_116 ( V_12 , V_70 , V_73 ) ;
if ( V_94 )
goto V_387;
V_12 -> V_16 . V_388 = & V_12 -> V_16 . V_35 ;
#ifdef F_117
#ifdef F_118
V_12 -> V_16 . V_389 = true ;
#else
V_12 -> V_16 . V_389 = false ;
#endif
#endif
V_12 -> V_16 . V_262 [ 0 ] = V_390 ;
V_12 -> V_16 . V_391 = V_392 ;
F_27 ( V_12 , F_119 ( V_393 ) ) ;
F_96 ( & V_12 -> V_16 . V_85 ) ;
F_96 ( & V_12 -> V_16 . V_29 ) ;
V_12 -> V_16 . V_32 = V_23 ;
V_12 -> V_16 . V_237 = V_394 | V_395 ;
F_120 ( V_12 ) ;
V_12 -> V_16 . V_30 = V_396 ;
F_97 ( & V_12 -> V_16 . V_397 ) ;
F_35 ( & V_70 -> V_46 ) ;
V_25 = V_70 -> V_16 . V_398 [ V_347 ] ;
if ( ! V_25 ) {
V_25 = F_93 ( V_70 , V_347 ) ;
V_70 -> V_16 . V_398 [ V_347 ] = V_25 ;
V_70 -> V_16 . V_399 ++ ;
}
F_37 ( & V_70 -> V_46 ) ;
if ( ! V_25 )
goto V_387;
F_29 ( & V_25 -> V_46 ) ;
++ V_25 -> V_400 ;
F_30 ( & V_25 -> V_46 ) ;
V_12 -> V_16 . V_25 = V_25 ;
V_12 -> V_16 . V_128 = V_12 -> V_48 - V_25 -> V_350 ;
V_12 -> V_16 . V_17 = - 1 ;
V_12 -> V_16 . V_401 = V_402 ;
F_121 ( V_12 ) ;
F_110 ( V_12 , V_73 ) ;
return V_12 ;
V_387:
F_122 ( V_386 , V_12 ) ;
V_385:
return F_123 ( V_94 ) ;
}
static void F_124 ( struct V_70 * V_70 , struct V_81 * V_77 )
{
if ( V_77 -> V_89 )
F_46 ( V_70 , V_77 -> V_89 , V_77 -> V_113 ,
V_77 -> V_114 ) ;
}
static void F_125 ( struct V_11 * V_12 )
{
F_29 ( & V_12 -> V_16 . V_85 ) ;
F_124 ( V_12 -> V_70 , & V_12 -> V_16 . V_108 ) ;
F_124 ( V_12 -> V_70 , & V_12 -> V_16 . V_109 ) ;
F_124 ( V_12 -> V_70 , & V_12 -> V_16 . V_77 ) ;
F_30 ( & V_12 -> V_16 . V_85 ) ;
F_126 ( V_12 ) ;
F_122 ( V_386 , V_12 ) ;
}
static int F_127 ( struct V_11 * V_12 )
{
return 1 ;
}
static void F_128 ( struct V_11 * V_12 )
{
unsigned long V_403 , V_118 ;
V_118 = F_129 () ;
if ( V_118 > V_12 -> V_16 . V_404 ) {
F_130 ( V_12 ) ;
F_131 ( V_12 ) ;
return;
}
V_403 = ( V_12 -> V_16 . V_404 - V_118 ) * V_405
/ V_406 ;
F_132 ( & V_12 -> V_16 . V_407 , F_133 ( 0 , V_403 ) ,
V_408 ) ;
V_12 -> V_16 . V_409 = 1 ;
}
static void F_26 ( struct V_11 * V_12 )
{
V_12 -> V_16 . V_162 = 0 ;
if ( V_12 -> V_16 . V_409 ) {
F_134 ( & V_12 -> V_16 . V_407 ) ;
V_12 -> V_16 . V_409 = 0 ;
}
}
static void F_135 ( struct V_18 * V_19 ,
struct V_11 * V_12 )
{
T_2 V_118 ;
if ( V_12 -> V_16 . V_30 != V_152 )
return;
F_51 ( & V_12 -> V_16 . V_29 ) ;
V_118 = F_20 () ;
V_12 -> V_16 . V_33 += F_49 ( V_19 , V_118 ) -
V_12 -> V_16 . V_124 ;
V_12 -> V_16 . V_32 = V_118 ;
V_12 -> V_16 . V_30 = V_31 ;
F_52 ( & V_12 -> V_16 . V_29 ) ;
-- V_19 -> V_410 ;
F_136 ( & V_12 -> V_16 . V_411 ) ;
}
static int F_137 ( int V_1 )
{
struct V_412 * V_413 ;
long V_414 = 10000 ;
V_413 = & V_8 [ V_1 ] ;
V_413 -> V_9 . V_11 = NULL ;
V_413 -> V_9 . V_415 = NULL ;
V_413 -> V_9 . V_416 = 0 ;
F_56 () ;
V_413 -> V_9 . V_417 = 1 ;
F_8 () ;
while ( V_413 -> V_9 . V_418 == V_419 ) {
if ( -- V_414 <= 0 ) {
F_32 ( L_19 , V_1 ) ;
return - V_420 ;
}
F_106 ( 1 ) ;
}
return 0 ;
}
static void F_138 ( int V_1 )
{
struct V_412 * V_413 ;
V_413 = & V_8 [ V_1 ] ;
V_413 -> V_9 . V_417 = 0 ;
V_413 -> V_9 . V_11 = NULL ;
V_413 -> V_9 . V_415 = NULL ;
V_413 -> V_9 . V_421 = NULL ;
}
static void F_139 ( struct V_11 * V_12 , struct V_18 * V_19 )
{
int V_1 ;
struct V_412 * V_413 ;
struct V_18 * V_422 = V_19 -> V_423 ;
V_1 = V_19 -> V_127 ;
if ( V_12 ) {
if ( V_12 -> V_16 . V_409 ) {
F_134 ( & V_12 -> V_16 . V_407 ) ;
V_12 -> V_16 . V_409 = 0 ;
}
V_1 += V_12 -> V_16 . V_128 ;
V_12 -> V_1 = V_422 -> V_127 ;
V_12 -> V_16 . V_17 = V_1 ;
}
V_413 = & V_8 [ V_1 ] ;
V_413 -> V_9 . V_11 = V_12 ;
V_413 -> V_9 . V_128 = V_1 - V_422 -> V_127 ;
F_56 () ;
V_413 -> V_9 . V_415 = V_422 ;
if ( V_1 != F_5 () )
F_1 ( V_1 ) ;
}
static void F_140 ( void )
{
int V_1 = F_5 () ;
int V_207 , V_367 ;
for ( V_367 = 0 ; V_367 < 1000000 ; ++ V_367 ) {
for ( V_207 = 1 ; V_207 < V_351 ; ++ V_207 )
if ( V_8 [ V_1 + V_207 ] . V_9 . V_415 )
break;
if ( V_207 == V_351 ) {
F_141 () ;
return;
}
F_142 () ;
}
F_141 () ;
for ( V_207 = 1 ; V_207 < V_351 ; ++ V_207 )
if ( V_8 [ V_1 + V_207 ] . V_9 . V_415 )
F_32 ( L_20 , V_1 + V_207 ) ;
}
static int F_143 ( void )
{
int V_1 = F_5 () ;
int V_424 ;
if ( F_144 ( V_1 ) )
return 0 ;
V_424 = 0 ;
while ( ++ V_424 < V_351 )
if ( F_16 ( V_1 + V_424 ) )
return 0 ;
for ( V_424 = 1 ; V_424 < V_351 ; ++ V_424 ) {
if ( F_137 ( V_1 + V_424 ) ) {
do {
F_138 ( V_1 + V_424 ) ;
} while ( -- V_424 > 0 );
return 0 ;
}
}
return 1 ;
}
static void F_145 ( void )
{
int V_1 ;
F_146 (cpu) {
struct V_425 * V_426 = & F_147 ( V_427 , V_1 ) ;
F_96 ( & V_426 -> V_46 ) ;
F_95 ( & V_426 -> V_428 ) ;
}
}
static void F_148 ( struct V_18 * V_19 )
{
struct V_425 * V_426 = F_149 ( & V_427 ) ;
V_19 -> V_27 = V_429 ;
V_19 -> V_127 = F_5 () ;
if ( V_19 -> V_400 < V_351 ) {
F_29 ( & V_426 -> V_46 ) ;
F_150 ( & V_19 -> V_352 , & V_426 -> V_428 ) ;
F_30 ( & V_426 -> V_46 ) ;
}
F_18 ( V_19 ) ;
}
static void F_151 ( struct V_18 * V_19 )
{
struct V_425 * V_426 ;
F_22 ( V_19 ) ;
if ( ! F_64 ( & V_19 -> V_352 ) ) {
V_426 = & F_147 ( V_427 , V_19 -> V_127 ) ;
F_29 ( & V_426 -> V_46 ) ;
F_152 ( & V_19 -> V_352 ) ;
F_30 ( & V_426 -> V_46 ) ;
}
V_19 -> V_27 = V_120 ;
}
static void F_153 ( struct V_430 * V_431 , struct V_18 * V_19 )
{
int V_432 ;
memset ( V_431 , 0 , sizeof( * V_431 ) ) ;
V_431 -> V_433 = 1 ;
V_431 -> V_434 = V_19 -> V_400 ;
V_431 -> V_435 = V_19 -> V_400 ;
V_431 -> V_436 [ 0 ] = V_19 -> V_400 ;
V_431 -> V_437 [ 0 ] = V_19 -> V_70 ;
for ( V_432 = 0 ; V_432 < V_438 ; ++ V_432 )
F_95 ( & V_431 -> V_439 [ V_432 ] ) ;
F_150 ( & V_19 -> V_352 , & V_431 -> V_439 [ 0 ] ) ;
}
static bool F_154 ( int V_433 , int V_440 )
{
if ( V_433 > 1 && V_351 < V_441 )
return false ;
if ( V_433 > V_438 )
return false ;
if ( V_433 > 1 ) {
if ( ! ( V_442 & 2 ) )
V_433 = 4 ;
if ( V_433 > 2 && ! ( V_442 & 4 ) )
return false ;
}
return V_433 * F_155 ( V_440 ) <= V_441 ;
}
static void F_156 ( struct V_18 * V_19 )
{
V_19 -> V_423 = V_19 ;
V_19 -> V_443 = 0 ;
V_19 -> V_444 = 0 ;
V_19 -> V_445 = 0 ;
V_19 -> V_446 = 0 ;
}
static bool F_157 ( struct V_430 * V_431 )
{
int V_432 , V_447 ;
int V_448 = - 1 ;
int V_424 ;
int V_433 = V_431 -> V_433 ;
struct V_18 * V_19 , * V_449 ;
struct V_18 * V_450 = NULL ;
for ( V_432 = 0 ; V_432 < V_431 -> V_433 ; ++ V_432 ) {
if ( V_431 -> V_436 [ V_432 ] <= 2 )
continue;
if ( V_448 >= 0 )
return false ;
V_448 = V_432 ;
V_19 = F_158 ( & V_431 -> V_439 [ V_432 ] , struct V_18 ,
V_352 ) ;
if ( V_19 -> V_400 > 2 )
return false ;
V_433 += ( V_431 -> V_436 [ V_432 ] - 1 ) >> 1 ;
}
if ( V_433 > 3 || V_448 < 0 )
return false ;
V_447 = V_431 -> V_433 ;
V_424 = 0 ;
V_432 = V_448 ;
F_159 (vc, vcnext, &cip->vcs[sub], preempt_list) {
if ( V_424 >= 2 ) {
F_136 ( & V_19 -> V_352 ) ;
F_150 ( & V_19 -> V_352 , & V_431 -> V_439 [ V_447 ] ) ;
if ( ++ V_431 -> V_436 [ V_447 ] == 1 ) {
V_431 -> V_437 [ V_447 ] = V_19 -> V_70 ;
F_156 ( V_19 ) ;
V_450 = V_19 ;
++ V_431 -> V_433 ;
} else {
V_19 -> V_423 = V_450 ;
++ V_447 ;
}
}
V_424 += V_19 -> V_400 ;
}
V_431 -> V_436 [ V_448 ] = 2 ;
V_431 -> V_434 = 2 ;
return true ;
}
static bool F_160 ( struct V_18 * V_19 , struct V_430 * V_431 )
{
int V_440 = V_19 -> V_400 ;
int V_432 ;
if ( ! F_2 ( V_2 ) )
return false ;
if ( V_440 < V_431 -> V_434 )
V_440 = V_431 -> V_434 ;
if ( F_154 ( V_431 -> V_433 + 1 , V_440 ) ) {
V_431 -> V_434 = V_440 ;
} else if ( V_431 -> V_433 <= 2 && V_431 -> V_435 <= 6 &&
V_19 -> V_400 <= 2 ) {
if ( ! F_157 ( V_431 ) )
return false ;
} else {
return false ;
}
V_432 = V_431 -> V_433 ;
++ V_431 -> V_433 ;
V_431 -> V_435 += V_19 -> V_400 ;
V_431 -> V_436 [ V_432 ] = V_19 -> V_400 ;
V_431 -> V_437 [ V_432 ] = V_19 -> V_70 ;
F_156 ( V_19 ) ;
F_136 ( & V_19 -> V_352 ) ;
F_150 ( & V_19 -> V_352 , & V_431 -> V_439 [ V_432 ] ) ;
return true ;
}
static bool F_161 ( struct V_18 * V_451 ,
struct V_430 * V_431 , int V_432 )
{
struct V_18 * V_19 ;
int V_452 ;
V_19 = F_158 ( & V_431 -> V_439 [ V_432 ] , struct V_18 ,
V_352 ) ;
if ( V_451 -> V_70 != V_19 -> V_70 ||
V_451 -> V_130 != V_19 -> V_130 ||
V_451 -> V_38 != V_19 -> V_38 ||
V_451 -> V_69 != V_19 -> V_69 )
return false ;
if ( F_2 ( V_2 ) &&
( V_19 -> V_400 > 1 || V_451 -> V_400 > 1 ) )
return false ;
V_452 = V_431 -> V_436 [ V_432 ] + V_451 -> V_400 ;
if ( V_452 > V_431 -> V_434 ) {
if ( ! F_154 ( V_431 -> V_433 , V_452 ) )
return false ;
V_431 -> V_434 = V_452 ;
}
V_431 -> V_435 += V_451 -> V_400 ;
V_431 -> V_436 [ V_432 ] = V_452 ;
V_451 -> V_423 = V_19 ;
F_136 ( & V_451 -> V_352 ) ;
F_150 ( & V_451 -> V_352 , & V_431 -> V_439 [ V_432 ] ) ;
return true ;
}
static bool F_162 ( struct V_18 * V_451 , struct V_430 * V_431 ,
int V_453 )
{
int V_432 ;
if ( V_431 -> V_435 + V_451 -> V_400 > V_453 )
return false ;
for ( V_432 = 0 ; V_432 < V_431 -> V_433 ; ++ V_432 )
if ( V_431 -> V_436 [ V_432 ] &&
F_161 ( V_451 , V_431 , V_432 ) )
return true ;
if ( F_160 ( V_451 , V_431 ) )
return true ;
return false ;
}
static void F_163 ( struct V_18 * V_19 )
{
struct V_11 * V_12 , * V_454 ;
F_159 (vcpu, vnext, &vc->runnable_threads,
arch.run_list) {
if ( F_164 ( V_12 -> V_16 . V_455 ) )
V_12 -> V_16 . V_75 = - V_456 ;
else if ( V_12 -> V_16 . V_77 . V_87 ||
V_12 -> V_16 . V_109 . V_87 ||
V_12 -> V_16 . V_108 . V_87 )
V_12 -> V_16 . V_75 = V_180 ;
else
continue;
F_135 ( V_19 , V_12 ) ;
F_165 ( & V_12 -> V_16 . V_397 ) ;
}
}
static void F_166 ( struct V_430 * V_431 , int V_453 )
{
struct V_425 * V_426 = F_149 ( & V_427 ) ;
struct V_18 * V_451 , * V_449 ;
F_29 ( & V_426 -> V_46 ) ;
F_159 (pvc, vcnext, &lp->list, preempt_list) {
if ( ! F_167 ( & V_451 -> V_46 ) )
continue;
F_163 ( V_451 ) ;
if ( ! V_451 -> V_410 ) {
F_152 ( & V_451 -> V_352 ) ;
if ( V_451 -> V_26 == NULL ) {
V_451 -> V_27 = V_120 ;
F_22 ( V_451 ) ;
}
F_30 ( & V_451 -> V_46 ) ;
continue;
}
if ( ! F_162 ( V_451 , V_431 , V_453 ) ) {
F_30 ( & V_451 -> V_46 ) ;
continue;
}
F_22 ( V_451 ) ;
V_451 -> V_27 = V_457 ;
if ( V_431 -> V_435 >= V_453 )
break;
}
F_30 ( & V_426 -> V_46 ) ;
}
static void F_168 ( struct V_18 * V_19 , bool V_458 )
{
int V_459 = 0 ;
T_2 V_118 ;
long V_75 ;
struct V_11 * V_12 , * V_454 ;
F_29 ( & V_19 -> V_46 ) ;
V_118 = F_129 () ;
F_159 (vcpu, vnext, &vc->runnable_threads,
arch.run_list) {
if ( V_118 < V_12 -> V_16 . V_404 &&
F_169 ( V_12 ) )
F_170 ( V_12 ) ;
F_171 ( V_12 ) ;
V_75 = V_180 ;
if ( V_12 -> V_16 . V_50 )
V_75 = F_79 ( V_12 -> V_16 . V_182 , V_12 ,
V_12 -> V_16 . V_455 ) ;
V_12 -> V_16 . V_75 = V_75 ;
V_12 -> V_16 . V_50 = 0 ;
if ( F_172 ( V_12 -> V_16 . V_75 ) ) {
if ( V_12 -> V_16 . V_460 )
F_131 ( V_12 ) ;
if ( V_12 -> V_16 . V_162 )
F_128 ( V_12 ) ;
else
++ V_459 ;
} else {
F_135 ( V_19 , V_12 ) ;
F_165 ( & V_12 -> V_16 . V_397 ) ;
}
}
F_152 ( & V_19 -> V_352 ) ;
if ( ! V_458 ) {
if ( V_459 > 0 ) {
F_148 ( V_19 ) ;
} else if ( V_19 -> V_26 ) {
V_19 -> V_27 = V_429 ;
F_18 ( V_19 ) ;
} else {
V_19 -> V_27 = V_120 ;
}
if ( V_19 -> V_410 > 0 && V_19 -> V_26 == NULL ) {
V_12 = F_158 ( & V_19 -> V_349 ,
struct V_11 , V_16 . V_411 ) ;
F_165 ( & V_12 -> V_16 . V_397 ) ;
}
}
F_30 ( & V_19 -> V_46 ) ;
}
static T_9 void F_173 ( struct V_18 * V_19 )
{
struct V_11 * V_12 , * V_454 ;
int V_207 ;
int V_461 ;
struct V_430 V_430 ;
struct V_18 * V_451 , * V_449 ;
struct V_421 V_462 , * V_463 ;
int V_464 , V_465 , V_466 ;
int V_432 ;
bool V_467 ;
unsigned long V_468 , V_469 ;
int V_127 , V_424 ;
int V_453 ;
F_163 ( V_19 ) ;
if ( V_19 -> V_26 -> V_16 . V_30 != V_152 )
return;
F_156 ( V_19 ) ;
V_19 -> V_22 = V_23 ;
if ( ( V_470 > 1 ) &&
( ( V_19 -> V_400 > V_351 ) || ! F_143 () ) ) {
F_159 (vcpu, vnext, &vc->runnable_threads,
arch.run_list) {
V_12 -> V_16 . V_75 = - V_420 ;
F_135 ( V_19 , V_12 ) ;
F_165 ( & V_12 -> V_16 . V_397 ) ;
}
goto V_385;
}
F_153 ( & V_430 , V_19 ) ;
V_127 = F_5 () ;
V_453 = V_351 ;
if ( V_471 && V_471 < V_453 )
V_453 = V_471 ;
if ( V_19 -> V_400 < V_453 )
F_166 ( & V_430 , V_453 ) ;
V_465 = V_351 ;
V_468 = V_469 = 0 ;
V_464 = V_430 . V_433 ;
V_463 = NULL ;
if ( V_464 > 1 ) {
if ( V_464 == 2 && ( V_442 & 2 ) ) {
V_468 = V_472 ;
V_469 = V_473 ;
} else {
V_464 = 4 ;
V_468 = V_474 ;
V_469 = V_475 ;
}
V_465 = V_441 / V_464 ;
V_463 = & V_462 ;
memset ( & V_462 , 0 , sizeof( V_462 ) ) ;
V_462 . V_476 = F_119 ( V_477 ) ;
V_462 . V_478 = F_119 ( V_479 ) ;
V_462 . V_480 = F_119 ( V_481 ) ;
V_462 . V_465 = V_465 ;
for ( V_432 = 0 ; V_432 < V_430 . V_433 ; ++ V_432 )
V_462 . V_482 [ V_432 ] =
F_158 ( & V_430 . V_439 [ V_432 ] ,
struct V_18 , V_352 ) ;
F_56 () ;
}
V_127 = F_5 () ;
for ( V_424 = 0 ; V_424 < V_351 ; ++ V_424 )
V_8 [ V_127 + V_424 ] . V_9 . V_421 = V_463 ;
if ( V_468 ) {
unsigned long V_483 = F_119 ( V_484 ) ;
V_483 |= V_468 | V_485 ;
F_174 () ;
F_175 ( V_484 , V_483 ) ;
F_176 () ;
for (; ; ) {
V_483 = F_119 ( V_484 ) ;
if ( V_483 & V_469 )
break;
F_177 () ;
}
}
V_466 = 0 ;
for ( V_432 = 0 ; V_432 < V_430 . V_433 ; ++ V_432 ) {
V_424 = V_486 [ V_432 ] ;
V_467 = false ;
V_466 |= 1 << V_424 ;
F_178 (pvc, &core_info.vcs[sub], preempt_list) {
V_451 -> V_127 = V_127 + V_424 ;
F_178 (vcpu, &pvc->runnable_threads,
arch.run_list) {
F_139 ( V_12 , V_451 ) ;
F_50 ( V_12 , V_451 ) ;
F_179 ( V_12 ) ;
if ( ! V_12 -> V_16 . V_128 )
V_467 = true ;
V_466 |= 1 << ( V_424 + V_12 -> V_16 . V_128 ) ;
}
if ( V_451 -> V_423 == V_451 && ! V_467 )
F_139 ( NULL , V_451 ) ;
V_424 += V_451 -> V_400 ;
}
}
F_8 () ;
if ( V_468 )
V_462 . V_487 = 1 ;
if ( V_464 > 1 )
for ( V_424 = 1 ; V_424 < V_351 ; ++ V_424 )
if ( ! ( V_466 & ( 1 << V_424 ) ) )
F_1 ( V_127 + V_424 ) ;
V_19 -> V_27 = V_488 ;
F_3 () ;
F_180 ( V_19 , 0 ) ;
for ( V_432 = 0 ; V_432 < V_430 . V_433 ; ++ V_432 )
F_178 (pvc, &core_info.vcs[sub], preempt_list)
F_30 ( & V_451 -> V_46 ) ;
F_181 () ;
V_461 = F_65 ( & V_19 -> V_70 -> V_168 ) ;
F_182 () ;
F_67 ( & V_19 -> V_70 -> V_168 , V_461 ) ;
F_29 ( & V_19 -> V_46 ) ;
V_19 -> V_27 = V_489 ;
F_140 () ;
if ( V_464 > 1 ) {
unsigned long V_483 = F_119 ( V_484 ) ;
unsigned long V_367 = 0 ;
V_483 &= ~ V_485 ;
V_469 = V_473 | V_475 ;
F_174 () ;
F_175 ( V_484 , V_483 ) ;
F_176 () ;
for (; ; ) {
V_483 = F_119 ( V_484 ) ;
if ( ! ( V_483 & V_469 ) )
break;
F_177 () ;
++ V_367 ;
}
V_462 . V_487 = 0 ;
}
for ( V_207 = 0 ; V_207 < V_351 ; ++ V_207 ) {
F_138 ( V_127 + V_207 ) ;
if ( V_463 && V_463 -> V_490 [ V_207 ] )
F_1 ( V_127 + V_207 ) ;
}
F_30 ( & V_19 -> V_46 ) ;
F_8 () ;
F_183 () ;
for ( V_432 = 0 ; V_432 < V_430 . V_433 ; ++ V_432 )
F_159 (pvc, vcnext, &core_info.vcs[sub],
preempt_list)
F_168 ( V_451 , V_451 == V_19 ) ;
F_29 ( & V_19 -> V_46 ) ;
F_9 () ;
V_385:
V_19 -> V_27 = V_120 ;
F_180 ( V_19 , 1 ) ;
}
static void F_184 ( struct V_18 * V_19 ,
struct V_11 * V_12 , int V_491 )
{
F_185 ( V_492 ) ;
F_186 ( & V_12 -> V_16 . V_397 , & V_492 , V_491 ) ;
if ( V_12 -> V_16 . V_30 == V_152 ) {
F_30 ( & V_19 -> V_46 ) ;
F_187 () ;
F_29 ( & V_19 -> V_46 ) ;
}
F_188 ( & V_12 -> V_16 . V_397 , & V_492 ) ;
}
static void F_189 ( struct V_18 * V_19 )
{
struct V_11 * V_12 ;
int V_493 = 1 ;
F_185 ( V_492 ) ;
F_186 ( & V_19 -> V_163 , & V_492 , V_494 ) ;
F_178 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( V_12 -> V_16 . V_460 || ! V_12 -> V_16 . V_162 ) {
V_493 = 0 ;
break;
}
}
if ( ! V_493 ) {
F_188 ( & V_19 -> V_163 , & V_492 ) ;
return;
}
V_19 -> V_27 = V_28 ;
F_190 ( V_19 , 0 ) ;
F_30 ( & V_19 -> V_46 ) ;
F_187 () ;
F_188 ( & V_19 -> V_163 , & V_492 ) ;
F_29 ( & V_19 -> V_46 ) ;
V_19 -> V_27 = V_120 ;
F_190 ( V_19 , 1 ) ;
}
static int F_191 ( struct V_182 * V_182 , struct V_11 * V_12 )
{
int V_495 ;
struct V_18 * V_19 ;
struct V_11 * V_74 , * V_496 ;
F_192 ( V_12 ) ;
V_182 -> V_187 = 0 ;
V_12 -> V_16 . V_75 = V_180 ;
V_12 -> V_16 . V_50 = 0 ;
F_48 ( V_12 ) ;
V_19 = V_12 -> V_16 . V_25 ;
F_29 ( & V_19 -> V_46 ) ;
V_12 -> V_16 . V_162 = 0 ;
V_12 -> V_16 . V_455 = V_497 ;
V_12 -> V_16 . V_182 = V_182 ;
V_12 -> V_16 . V_124 = F_49 ( V_19 , F_20 () ) ;
V_12 -> V_16 . V_30 = V_152 ;
V_12 -> V_16 . V_32 = V_23 ;
F_150 ( & V_12 -> V_16 . V_411 , & V_19 -> V_349 ) ;
++ V_19 -> V_410 ;
if ( ! F_164 ( V_497 ) ) {
if ( V_19 -> V_27 == V_457 ) {
struct V_18 * V_422 = V_19 -> V_423 ;
if ( F_167 ( & V_422 -> V_46 ) ) {
if ( V_422 -> V_27 == V_488 &&
! F_193 ( V_422 ) ) {
F_50 ( V_12 , V_19 ) ;
F_139 ( V_12 , V_19 ) ;
F_179 ( V_12 ) ;
}
F_30 ( & V_422 -> V_46 ) ;
}
} else if ( V_19 -> V_27 == V_488 &&
! F_193 ( V_19 ) ) {
F_50 ( V_12 , V_19 ) ;
F_139 ( V_12 , V_19 ) ;
F_179 ( V_12 ) ;
} else if ( V_19 -> V_27 == V_28 ) {
F_165 ( & V_19 -> V_163 ) ;
}
}
while ( V_12 -> V_16 . V_30 == V_152 &&
! F_164 ( V_497 ) ) {
if ( V_19 -> V_27 == V_429 && V_19 -> V_26 == NULL )
F_151 ( V_19 ) ;
if ( V_19 -> V_27 != V_120 ) {
F_184 ( V_19 , V_12 , V_494 ) ;
continue;
}
F_159 (v, vn, &vc->runnable_threads,
arch.run_list) {
F_131 ( V_74 ) ;
if ( F_164 ( V_74 -> V_16 . V_455 ) ) {
F_135 ( V_19 , V_74 ) ;
V_74 -> V_14 . V_498 ++ ;
V_74 -> V_16 . V_182 -> V_187 = V_499 ;
V_74 -> V_16 . V_75 = - V_456 ;
F_165 ( & V_74 -> V_16 . V_397 ) ;
}
}
if ( ! V_19 -> V_410 || V_12 -> V_16 . V_30 != V_152 )
break;
V_495 = 0 ;
F_178 (v, &vc->runnable_threads, arch.run_list) {
if ( ! V_74 -> V_16 . V_460 )
V_495 += V_74 -> V_16 . V_162 ;
else
V_74 -> V_16 . V_162 = 0 ;
}
V_19 -> V_26 = V_12 ;
if ( V_495 == V_19 -> V_410 ) {
F_189 ( V_19 ) ;
} else if ( F_194 () ) {
F_148 ( V_19 ) ;
F_195 ( & V_19 -> V_46 ) ;
if ( V_19 -> V_27 == V_429 )
F_151 ( V_19 ) ;
} else {
F_173 ( V_19 ) ;
}
V_19 -> V_26 = NULL ;
}
while ( V_12 -> V_16 . V_30 == V_152 &&
( V_19 -> V_27 == V_488 ||
V_19 -> V_27 == V_489 ||
V_19 -> V_27 == V_457 ) )
F_184 ( V_19 , V_12 , V_500 ) ;
if ( V_19 -> V_27 == V_429 && V_19 -> V_26 == NULL )
F_151 ( V_19 ) ;
if ( V_12 -> V_16 . V_30 == V_152 ) {
F_135 ( V_19 , V_12 ) ;
V_12 -> V_14 . V_498 ++ ;
V_182 -> V_187 = V_499 ;
V_12 -> V_16 . V_75 = - V_456 ;
}
if ( V_19 -> V_410 && V_19 -> V_27 == V_120 ) {
V_74 = F_158 ( & V_19 -> V_349 ,
struct V_11 , V_16 . V_411 ) ;
F_165 ( & V_74 -> V_16 . V_397 ) ;
}
F_196 ( V_12 , V_182 ) ;
F_30 ( & V_19 -> V_46 ) ;
return V_12 -> V_16 . V_75 ;
}
static int F_197 ( struct V_182 * V_183 , struct V_11 * V_12 )
{
int V_47 ;
int V_461 ;
if ( ! V_12 -> V_16 . V_501 ) {
V_183 -> V_187 = V_502 ;
return - V_45 ;
}
F_131 ( V_12 ) ;
if ( F_164 ( V_497 ) ) {
V_183 -> V_187 = V_499 ;
return - V_456 ;
}
F_198 ( & V_12 -> V_70 -> V_16 . V_503 ) ;
F_8 () ;
if ( ! V_12 -> V_70 -> V_16 . V_504 ) {
V_47 = F_199 ( V_12 ) ;
if ( V_47 )
goto V_385;
}
F_200 ( V_497 ) ;
F_201 ( V_497 ) ;
F_202 ( V_497 ) ;
V_12 -> V_16 . V_13 = & V_12 -> V_16 . V_25 -> V_163 ;
V_12 -> V_16 . V_505 = V_497 -> V_506 -> V_507 ;
V_12 -> V_16 . V_30 = V_31 ;
do {
V_47 = F_191 ( V_183 , V_12 ) ;
if ( V_183 -> V_187 == V_210 &&
! ( V_12 -> V_16 . V_35 . V_34 & V_508 ) ) {
F_203 ( V_12 ) ;
V_47 = F_62 ( V_12 ) ;
F_204 ( V_12 , V_47 ) ;
F_131 ( V_12 ) ;
} else if ( V_47 == V_212 ) {
V_461 = F_65 ( & V_12 -> V_70 -> V_168 ) ;
V_47 = F_205 ( V_183 , V_12 ,
V_12 -> V_16 . V_63 , V_12 -> V_16 . V_64 ) ;
F_67 ( & V_12 -> V_70 -> V_168 , V_461 ) ;
}
} while ( F_172 ( V_47 ) );
V_385:
V_12 -> V_16 . V_30 = V_396 ;
F_206 ( & V_12 -> V_70 -> V_16 . V_503 ) ;
return V_47 ;
}
static void F_207 ( struct V_509 * * V_510 ,
int V_511 )
{
struct V_512 * V_513 = & V_514 [ V_511 ] ;
if ( ! V_513 -> V_515 )
return;
( * V_510 ) -> V_516 = V_513 -> V_515 ;
( * V_510 ) -> V_517 = V_513 -> V_518 ;
( * V_510 ) -> V_519 [ 0 ] . V_516 = V_513 -> V_515 ;
( * V_510 ) -> V_519 [ 0 ] . V_520 = V_513 -> V_521 [ V_511 ] ;
if ( V_511 != V_522 && V_513 -> V_521 [ V_522 ] != - 1 ) {
( * V_510 ) -> V_519 [ 1 ] . V_516 = 24 ;
( * V_510 ) -> V_519 [ 1 ] . V_520 = V_513 -> V_521 [ V_522 ] ;
}
( * V_510 ) ++ ;
}
static int F_208 ( struct V_70 * V_70 ,
struct V_523 * V_524 )
{
struct V_509 * V_510 ;
V_524 -> V_20 = V_525 ;
if ( F_209 ( V_526 ) )
V_524 -> V_20 |= V_527 ;
V_524 -> V_528 = V_529 ;
V_510 = & V_524 -> V_510 [ 0 ] ;
F_207 ( & V_510 , V_530 ) ;
F_207 ( & V_510 , V_531 ) ;
F_207 ( & V_510 , V_522 ) ;
return 0 ;
}
static int F_210 ( struct V_70 * V_70 ,
struct V_532 * log )
{
struct V_533 * V_534 ;
struct V_535 * V_536 ;
int V_47 ;
unsigned long V_366 ;
F_35 ( & V_70 -> V_537 ) ;
V_47 = - V_45 ;
if ( log -> V_538 >= V_539 )
goto V_385;
V_534 = V_533 ( V_70 ) ;
V_536 = F_211 ( V_534 , log -> V_538 ) ;
V_47 = - V_169 ;
if ( ! V_536 -> V_540 )
goto V_385;
V_366 = F_212 ( V_536 ) ;
memset ( V_536 -> V_540 , 0 , V_366 ) ;
V_47 = F_213 ( V_70 , V_536 , V_536 -> V_540 ) ;
if ( V_47 )
goto V_385;
V_47 = - V_379 ;
if ( F_108 ( log -> V_540 , V_536 -> V_540 , V_366 ) )
goto V_385;
V_47 = 0 ;
V_385:
F_37 ( & V_70 -> V_537 ) ;
return V_47 ;
}
static void F_214 ( struct V_535 * free ,
struct V_535 * V_541 )
{
if ( ! V_541 || free -> V_16 . V_542 != V_541 -> V_16 . V_542 ) {
F_215 ( free -> V_16 . V_542 ) ;
free -> V_16 . V_542 = NULL ;
}
}
static int F_216 ( struct V_535 * V_538 ,
unsigned long V_543 )
{
V_538 -> V_16 . V_542 = F_217 ( V_543 * sizeof( * V_538 -> V_16 . V_542 ) ) ;
if ( ! V_538 -> V_16 . V_542 )
return - V_357 ;
return 0 ;
}
static int F_218 ( struct V_70 * V_70 ,
struct V_535 * V_536 ,
const struct V_544 * V_545 )
{
return 0 ;
}
static void F_219 ( struct V_70 * V_70 ,
const struct V_544 * V_545 ,
const struct V_535 * V_546 ,
const struct V_535 * V_547 )
{
unsigned long V_543 = V_545 -> V_548 >> V_549 ;
struct V_533 * V_534 ;
struct V_535 * V_536 ;
if ( V_543 && V_546 -> V_543 ) {
V_534 = V_533 ( V_70 ) ;
V_536 = F_211 ( V_534 , V_545 -> V_538 ) ;
F_213 ( V_70 , V_536 , NULL ) ;
}
}
void F_220 ( struct V_70 * V_70 , unsigned long V_69 , unsigned long V_235 )
{
long int V_207 ;
T_3 V_550 = 0 ;
if ( ( V_70 -> V_16 . V_69 & V_235 ) == V_69 )
return;
V_70 -> V_16 . V_69 = ( V_70 -> V_16 . V_69 & ~ V_235 ) | V_69 ;
for ( V_207 = 0 ; V_207 < V_384 ; ++ V_207 ) {
struct V_18 * V_19 = V_70 -> V_16 . V_398 [ V_207 ] ;
if ( ! V_19 )
continue;
F_29 ( & V_19 -> V_46 ) ;
V_19 -> V_69 = ( V_19 -> V_69 & ~ V_235 ) | V_69 ;
F_30 ( & V_19 -> V_46 ) ;
if ( ++ V_550 >= V_70 -> V_16 . V_399 )
break;
}
}
static void F_221 ( struct V_11 * V_12 )
{
return;
}
static int F_199 ( struct V_11 * V_12 )
{
int V_94 = 0 ;
struct V_70 * V_70 = V_12 -> V_70 ;
unsigned long V_551 ;
struct V_535 * V_536 ;
struct V_552 * V_553 ;
unsigned long V_69 = 0 , V_554 ;
unsigned long V_555 , V_556 ;
int V_461 ;
F_35 ( & V_70 -> V_46 ) ;
if ( V_70 -> V_16 . V_504 )
goto V_385;
if ( ! V_70 -> V_16 . V_557 ) {
V_94 = F_222 ( V_70 , NULL ) ;
if ( V_94 ) {
F_32 ( L_21 ) ;
goto V_385;
}
}
V_461 = F_65 ( & V_70 -> V_168 ) ;
V_536 = F_223 ( V_70 , 0 ) ;
V_94 = - V_45 ;
if ( ! V_536 || ( V_536 -> V_20 & V_558 ) )
goto V_559;
V_551 = V_536 -> V_560 ;
F_224 ( & V_497 -> V_506 -> V_561 ) ;
V_553 = F_225 ( V_497 -> V_506 , V_551 ) ;
if ( ! V_553 || V_553 -> V_562 > V_551 || ( V_553 -> V_563 & V_564 ) )
goto V_565;
V_555 = F_226 ( V_553 ) ;
V_556 = F_227 ( V_555 ) ;
F_228 ( & V_497 -> V_506 -> V_561 ) ;
V_94 = - V_45 ;
if ( ! ( V_555 == 0x1000 || V_555 == 0x10000 ||
V_555 == 0x1000000 ) )
goto V_559;
V_554 = F_229 ( V_555 ) ;
V_70 -> V_16 . V_566 = V_554 | V_567 |
( V_568 << V_569 ) ;
V_69 = V_554 << ( V_570 - 4 ) ;
F_230 ( V_12 , V_536 , V_556 ) ;
F_220 ( V_70 , V_69 , V_571 ) ;
F_56 () ;
V_70 -> V_16 . V_504 = 1 ;
V_94 = 0 ;
V_559:
F_67 ( & V_70 -> V_168 , V_461 ) ;
V_385:
F_37 ( & V_70 -> V_46 ) ;
return V_94 ;
V_565:
F_228 ( & V_497 -> V_506 -> V_561 ) ;
goto V_559;
}
static int F_231 ( struct V_70 * V_70 )
{
unsigned long V_69 , V_572 ;
char V_359 [ 32 ] ;
V_572 = F_232 () ;
if ( ( long ) V_572 < 0 )
return - V_357 ;
V_70 -> V_16 . V_572 = V_572 ;
F_233 ( & V_70 -> V_16 . V_573 ) ;
memcpy ( V_70 -> V_16 . V_157 , V_574 ,
sizeof( V_70 -> V_16 . V_157 ) ) ;
V_70 -> V_16 . V_575 = F_119 ( V_576 ) ;
V_70 -> V_16 . V_577 = F_119 ( V_578 ) ;
V_70 -> V_16 . V_579 = V_69 = F_119 ( V_580 ) ;
V_69 &= V_581 | V_582 ;
V_69 |= ( 4UL << V_583 ) | V_584 |
V_585 | V_586 ;
V_70 -> V_16 . V_566 = V_567 |
( V_568 << V_569 ) ;
if ( F_2 ( V_2 ) )
V_69 |= V_587 ;
V_70 -> V_16 . V_69 = V_69 ;
F_234 () ;
snprintf ( V_359 , sizeof( V_359 ) , L_22 , V_497 -> V_291 ) ;
V_70 -> V_16 . V_381 = F_112 ( V_359 , V_588 ) ;
if ( ! F_111 ( V_70 -> V_16 . V_381 ) )
F_235 ( V_70 ) ;
return 0 ;
}
static void F_236 ( struct V_70 * V_70 )
{
long int V_207 ;
for ( V_207 = 0 ; V_207 < V_384 ; ++ V_207 )
F_103 ( V_70 -> V_16 . V_398 [ V_207 ] ) ;
V_70 -> V_16 . V_399 = 0 ;
}
static void F_237 ( struct V_70 * V_70 )
{
F_238 ( V_70 -> V_16 . V_381 ) ;
F_239 () ;
F_236 ( V_70 ) ;
F_240 ( V_70 ) ;
}
static int F_241 ( struct V_182 * V_183 , struct V_11 * V_12 ,
unsigned int V_589 , int * V_590 )
{
return V_591 ;
}
static int F_242 ( struct V_11 * V_12 , int V_592 ,
T_4 V_593 )
{
return V_591 ;
}
static int F_243 ( struct V_11 * V_12 , int V_592 ,
T_4 * V_593 )
{
return V_591 ;
}
static int F_244 ( void )
{
if ( ! F_2 ( V_594 ) ||
! F_2 ( V_595 ) )
return - V_596 ;
return 0 ;
}
static long F_245 ( struct V_354 * V_597 ,
unsigned int V_598 , unsigned long V_599 )
{
struct V_70 * V_70 V_600 = V_597 -> V_358 ;
void T_6 * V_601 = ( void T_6 * ) V_599 ;
long V_47 ;
switch ( V_598 ) {
case V_602 : {
T_3 V_603 ;
V_47 = - V_379 ;
if ( F_246 ( V_603 , ( T_3 T_6 * ) V_601 ) )
break;
V_47 = F_247 ( V_70 , & V_603 ) ;
if ( V_47 )
break;
V_47 = - V_379 ;
if ( F_248 ( V_603 , ( T_3 T_6 * ) V_601 ) )
break;
V_47 = 0 ;
break;
}
case V_604 : {
struct V_605 V_606 ;
V_47 = - V_379 ;
if ( F_249 ( & V_606 , V_601 , sizeof( V_606 ) ) )
break;
V_47 = F_250 ( V_70 , & V_606 ) ;
break;
}
default:
V_47 = - V_607 ;
}
return V_47 ;
}
static void F_251 ( void )
{
int V_207 ;
unsigned int V_608 ;
for ( V_207 = 0 ; V_609 [ V_207 ] ; ++ V_207 ) {
V_608 = V_609 [ V_207 ] ;
F_252 ( ! F_73 ( V_608 ) ) ;
F_253 ( V_608 / 4 , V_574 ) ;
}
}
static int F_254 ( void )
{
int V_47 ;
V_47 = F_244 () ;
if ( V_47 < 0 )
return - V_610 ;
V_611 . V_612 = V_613 ;
V_614 = & V_611 ;
F_251 () ;
F_145 () ;
V_47 = F_255 () ;
return V_47 ;
}
static void F_256 ( void )
{
V_614 = NULL ;
}
