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
if ( ( V_34 & V_35 ) == V_35 )
V_34 &= ~ V_35 ;
V_12 -> V_16 . V_36 . V_34 = V_34 ;
F_26 ( V_12 ) ;
}
static void F_27 ( struct V_11 * V_12 , T_3 V_37 )
{
V_12 -> V_16 . V_37 = V_37 ;
}
static int F_28 ( struct V_11 * V_12 , T_3 V_38 )
{
unsigned long V_39 = 0 ;
struct V_18 * V_19 = V_12 -> V_16 . V_25 ;
if ( V_38 ) {
switch ( V_38 ) {
case V_40 :
V_39 = V_41 | V_42 ;
break;
case V_43 :
case V_44 :
V_39 = V_41 ;
break;
case V_45 :
break;
default:
return - V_46 ;
}
if ( ! F_2 ( V_2 ) ) {
if ( ! ( V_39 & V_41 ) )
return - V_46 ;
V_39 &= ~ V_41 ;
}
}
F_29 ( & V_19 -> V_47 ) ;
V_19 -> V_38 = V_38 ;
V_19 -> V_39 = V_39 ;
F_30 ( & V_19 -> V_47 ) ;
return 0 ;
}
static void F_31 ( struct V_11 * V_12 )
{
int V_48 ;
F_32 ( L_1 , V_12 , V_12 -> V_49 ) ;
F_32 ( L_2 ,
V_12 -> V_16 . V_50 , V_12 -> V_16 . V_36 . V_34 , V_12 -> V_16 . V_51 ) ;
for ( V_48 = 0 ; V_48 < 16 ; ++ V_48 )
F_32 ( L_3 ,
V_48 , F_33 ( V_12 , V_48 ) ,
V_48 + 16 , F_33 ( V_12 , V_48 + 16 ) ) ;
F_32 ( L_4 ,
V_12 -> V_16 . V_52 , V_12 -> V_16 . V_53 ) ;
F_32 ( L_5 ,
V_12 -> V_16 . V_36 . V_54 , V_12 -> V_16 . V_36 . V_55 ) ;
F_32 ( L_6 ,
V_12 -> V_16 . V_36 . V_56 , V_12 -> V_16 . V_36 . V_57 ) ;
F_32 ( L_7 ,
V_12 -> V_16 . V_36 . V_58 , V_12 -> V_16 . V_36 . V_59 ) ;
F_32 ( L_8 ,
V_12 -> V_16 . V_60 , V_12 -> V_16 . V_61 , V_12 -> V_16 . V_36 . V_62 ) ;
F_32 ( L_9 , V_12 -> V_16 . V_36 . V_63 ) ;
F_32 ( L_10 ,
V_12 -> V_16 . V_64 , V_12 -> V_16 . V_65 ) ;
F_32 ( L_11 , V_12 -> V_16 . V_66 ) ;
for ( V_48 = 0 ; V_48 < V_12 -> V_16 . V_66 ; ++ V_48 )
F_32 ( L_12 ,
V_12 -> V_16 . V_67 [ V_48 ] . V_68 , V_12 -> V_16 . V_67 [ V_48 ] . V_69 ) ;
F_32 ( L_13 ,
V_12 -> V_16 . V_25 -> V_70 , V_12 -> V_71 -> V_16 . V_72 ,
V_12 -> V_16 . V_73 ) ;
}
static struct V_11 * F_34 ( struct V_71 * V_71 , int V_74 )
{
int V_48 ;
struct V_11 * V_75 , * V_76 = NULL ;
F_35 ( & V_71 -> V_47 ) ;
F_36 (r, v, kvm) {
if ( V_75 -> V_49 == V_74 ) {
V_76 = V_75 ;
break;
}
}
F_37 ( & V_71 -> V_47 ) ;
return V_76 ;
}
static void F_38 ( struct V_11 * V_12 , struct V_77 * V_78 )
{
V_78 -> V_79 |= V_80 ;
V_78 -> V_81 = F_39 ( 1 ) ;
}
static int F_40 ( struct V_11 * V_12 , struct V_82 * V_75 ,
unsigned long V_83 , unsigned long V_84 )
{
if ( V_83 & ( V_85 - 1 ) )
return - V_46 ;
F_29 ( & V_12 -> V_16 . V_86 ) ;
if ( V_75 -> V_87 != V_83 || V_75 -> V_84 != V_84 ) {
V_75 -> V_87 = V_83 ;
V_75 -> V_84 = V_83 ? V_84 : 0 ;
V_75 -> V_88 = 1 ;
}
F_30 ( & V_12 -> V_16 . V_86 ) ;
return 0 ;
}
static int F_41 ( struct V_82 * V_89 )
{
if ( V_89 -> V_88 )
return V_89 -> V_87 != 0 ;
return V_89 -> V_90 != NULL ;
}
static unsigned long F_42 ( struct V_11 * V_12 ,
unsigned long V_20 ,
unsigned long V_91 , unsigned long V_78 )
{
struct V_71 * V_71 = V_12 -> V_71 ;
unsigned long V_84 , V_92 ;
void * V_93 ;
struct V_11 * V_94 ;
int V_95 ;
int V_96 ;
struct V_82 * V_89 ;
V_94 = F_34 ( V_71 , V_91 ) ;
if ( ! V_94 )
return V_97 ;
V_96 = ( V_20 >> V_98 ) & V_99 ;
if ( V_96 == V_100 || V_96 == V_101 ||
V_96 == V_102 ) {
if ( ( V_78 & ( V_85 - 1 ) ) || ! V_78 )
return V_97 ;
V_93 = F_43 ( V_71 , V_78 , & V_92 ) ;
if ( V_93 == NULL )
return V_97 ;
if ( V_96 == V_100 )
V_84 = F_44 ( ( (struct V_103 * ) V_93 ) -> V_104 . V_105 ) ;
else
V_84 = F_45 ( ( (struct V_103 * ) V_93 ) -> V_104 . V_106 ) ;
F_46 ( V_71 , V_93 , V_78 , false ) ;
if ( V_84 > V_92 || V_84 < sizeof( struct V_103 ) )
return V_97 ;
} else {
V_78 = 0 ;
V_84 = 0 ;
}
V_95 = V_97 ;
V_89 = NULL ;
F_29 ( & V_94 -> V_16 . V_86 ) ;
switch ( V_96 ) {
case V_100 :
if ( V_84 < sizeof( struct V_77 ) )
break;
V_89 = & V_94 -> V_16 . V_78 ;
V_95 = 0 ;
break;
case V_101 :
if ( V_84 < sizeof( struct V_107 ) )
break;
V_84 -= V_84 % sizeof( struct V_107 ) ;
V_95 = V_108 ;
if ( ! F_41 ( & V_94 -> V_16 . V_78 ) )
break;
V_89 = & V_94 -> V_16 . V_109 ;
V_95 = 0 ;
break;
case V_102 :
V_95 = V_108 ;
if ( ! F_41 ( & V_94 -> V_16 . V_78 ) )
break;
V_89 = & V_94 -> V_16 . V_110 ;
V_95 = 0 ;
break;
case V_111 :
V_95 = V_108 ;
if ( F_41 ( & V_94 -> V_16 . V_109 ) ||
F_41 ( & V_94 -> V_16 . V_110 ) )
break;
V_89 = & V_94 -> V_16 . V_78 ;
V_95 = 0 ;
break;
case V_112 :
V_89 = & V_94 -> V_16 . V_109 ;
V_95 = 0 ;
break;
case V_113 :
V_89 = & V_94 -> V_16 . V_110 ;
V_95 = 0 ;
break;
}
if ( V_89 ) {
V_89 -> V_87 = V_78 ;
V_89 -> V_84 = V_84 ;
V_89 -> V_88 = 1 ;
}
F_30 ( & V_94 -> V_16 . V_86 ) ;
return V_95 ;
}
static void F_47 ( struct V_11 * V_12 , struct V_82 * V_89 )
{
struct V_71 * V_71 = V_12 -> V_71 ;
void * V_93 ;
unsigned long V_92 ;
unsigned long V_114 ;
for (; ; ) {
V_114 = V_89 -> V_87 ;
F_30 ( & V_12 -> V_16 . V_86 ) ;
V_93 = NULL ;
V_92 = 0 ;
if ( V_114 )
V_93 = F_43 ( V_71 , V_114 , & V_92 ) ;
F_29 ( & V_12 -> V_16 . V_86 ) ;
if ( V_114 == V_89 -> V_87 )
break;
if ( V_93 )
F_46 ( V_71 , V_93 , V_114 , false ) ;
}
V_89 -> V_88 = 0 ;
if ( V_93 && V_92 < V_89 -> V_84 ) {
F_46 ( V_71 , V_93 , V_114 , false ) ;
V_93 = NULL ;
}
if ( V_89 -> V_90 )
F_46 ( V_71 , V_89 -> V_90 , V_89 -> V_114 ,
V_89 -> V_115 ) ;
V_89 -> V_114 = V_114 ;
V_89 -> V_90 = V_93 ;
V_89 -> V_115 = false ;
if ( V_93 )
V_89 -> V_116 = V_93 + V_89 -> V_84 ;
}
static void F_48 ( struct V_11 * V_12 )
{
if ( ! ( V_12 -> V_16 . V_78 . V_88 ||
V_12 -> V_16 . V_110 . V_88 ||
V_12 -> V_16 . V_109 . V_88 ) )
return;
F_29 ( & V_12 -> V_16 . V_86 ) ;
if ( V_12 -> V_16 . V_78 . V_88 ) {
F_47 ( V_12 , & V_12 -> V_16 . V_78 ) ;
if ( V_12 -> V_16 . V_78 . V_90 )
F_38 ( V_12 , V_12 -> V_16 . V_78 . V_90 ) ;
}
if ( V_12 -> V_16 . V_109 . V_88 ) {
F_47 ( V_12 , & V_12 -> V_16 . V_109 ) ;
V_12 -> V_16 . V_117 = V_12 -> V_16 . V_109 . V_90 ;
V_12 -> V_16 . V_118 = 0 ;
}
if ( V_12 -> V_16 . V_110 . V_88 )
F_47 ( V_12 , & V_12 -> V_16 . V_110 ) ;
F_30 ( & V_12 -> V_16 . V_86 ) ;
}
static T_2 F_49 ( struct V_18 * V_19 , T_2 V_119 )
{
T_2 V_120 ;
unsigned long V_20 ;
F_19 ( & V_19 -> V_21 , V_20 ) ;
V_120 = V_19 -> V_24 ;
if ( V_19 -> V_27 != V_121 &&
V_19 -> V_22 != V_23 )
V_120 += V_119 - V_19 -> V_22 ;
F_21 ( & V_19 -> V_21 , V_20 ) ;
return V_120 ;
}
static void F_50 ( struct V_11 * V_12 ,
struct V_18 * V_19 )
{
struct V_107 * V_122 ;
struct V_77 * V_78 ;
unsigned long V_123 ;
unsigned long V_124 ;
T_2 V_119 ;
V_122 = V_12 -> V_16 . V_117 ;
V_78 = V_12 -> V_16 . V_78 . V_90 ;
V_119 = F_20 () ;
V_124 = F_49 ( V_19 , V_119 ) ;
V_123 = V_124 - V_12 -> V_16 . V_125 ;
V_12 -> V_16 . V_125 = V_124 ;
F_51 ( & V_12 -> V_16 . V_29 ) ;
V_123 += V_12 -> V_16 . V_33 ;
V_12 -> V_16 . V_33 = 0 ;
F_52 ( & V_12 -> V_16 . V_29 ) ;
if ( ! V_122 || ! V_78 )
return;
memset ( V_122 , 0 , sizeof( struct V_107 ) ) ;
V_122 -> V_126 = 7 ;
V_122 -> V_127 = F_53 ( V_19 -> V_128 + V_12 -> V_16 . V_129 ) ;
V_122 -> V_130 = F_54 ( V_119 + V_19 -> V_131 ) ;
V_122 -> V_132 = F_39 ( V_123 ) ;
V_122 -> V_54 = F_54 ( F_55 ( V_12 ) ) ;
V_122 -> V_55 = F_54 ( V_12 -> V_16 . V_36 . V_34 ) ;
++ V_122 ;
if ( V_122 == V_12 -> V_16 . V_109 . V_116 )
V_122 = V_12 -> V_16 . V_109 . V_90 ;
V_12 -> V_16 . V_117 = V_122 ;
F_56 () ;
V_78 -> V_133 = F_54 ( ++ V_12 -> V_16 . V_118 ) ;
V_12 -> V_16 . V_109 . V_115 = true ;
}
static bool F_57 ( struct V_11 * V_12 )
{
if ( V_12 -> V_16 . V_25 -> V_38 >= V_45 )
return true ;
if ( ( ! V_12 -> V_16 . V_25 -> V_38 ) &&
F_2 ( V_2 ) )
return true ;
return false ;
}
static int F_58 ( struct V_11 * V_12 , unsigned long V_134 ,
unsigned long V_135 , unsigned long V_136 ,
unsigned long V_137 )
{
switch ( V_135 ) {
case V_138 :
if ( ! F_57 ( V_12 ) )
return V_139 ;
if ( V_137 )
return V_140 ;
if ( V_134 )
return V_141 ;
if ( ( V_136 & V_142 ) == V_143 )
return V_144 ;
V_12 -> V_16 . V_145 = V_136 ;
return V_146 ;
case V_147 :
if ( ! F_57 ( V_12 ) )
return V_139 ;
if ( V_134 )
return V_141 ;
if ( V_137 & V_148 )
return V_140 ;
V_12 -> V_16 . V_149 = V_136 ;
V_12 -> V_16 . V_150 = V_137 ;
return V_146 ;
default:
return V_151 ;
}
}
static int F_59 ( struct V_11 * V_152 )
{
struct V_18 * V_25 = V_152 -> V_16 . V_25 ;
F_29 ( & V_25 -> V_47 ) ;
if ( V_152 -> V_16 . V_30 == V_153 &&
V_25 -> V_27 != V_121 &&
V_25 -> V_26 )
V_152 = V_25 -> V_26 ;
F_30 ( & V_25 -> V_47 ) ;
return F_60 ( V_152 ) ;
}
static int F_61 ( struct V_11 * V_12 )
{
int V_81 = 0 ;
struct V_77 * V_77 ;
F_29 ( & V_12 -> V_16 . V_86 ) ;
V_77 = (struct V_77 * ) V_12 -> V_16 . V_78 . V_90 ;
if ( V_77 )
V_81 = F_45 ( V_77 -> V_81 ) ;
F_30 ( & V_12 -> V_16 . V_86 ) ;
return V_81 ;
}
int F_62 ( struct V_11 * V_12 )
{
unsigned long V_154 = F_33 ( V_12 , 3 ) ;
unsigned long V_152 , V_76 = V_146 ;
int V_81 ;
struct V_11 * V_94 ;
int V_155 , V_156 ;
if ( V_154 <= V_157 &&
! F_63 ( V_154 / 4 , V_12 -> V_71 -> V_16 . V_158 ) )
return V_159 ;
switch ( V_154 ) {
case V_160 :
break;
case V_161 :
V_152 = F_33 ( V_12 , 4 ) ;
V_94 = F_34 ( V_12 -> V_71 , V_152 ) ;
if ( ! V_94 ) {
V_76 = V_97 ;
break;
}
V_94 -> V_16 . V_162 = 1 ;
F_8 () ;
if ( V_12 -> V_16 . V_163 ) {
if ( F_14 ( & V_12 -> V_164 ) ) {
F_15 ( & V_12 -> V_164 ) ;
V_12 -> V_14 . V_15 ++ ;
}
}
break;
case V_165 :
V_152 = F_33 ( V_12 , 4 ) ;
if ( V_152 == - 1 )
break;
V_94 = F_34 ( V_12 -> V_71 , V_152 ) ;
if ( ! V_94 ) {
V_76 = V_97 ;
break;
}
V_81 = F_33 ( V_12 , 5 ) ;
if ( F_61 ( V_94 ) != V_81 )
break;
F_59 ( V_94 ) ;
break;
case V_166 :
V_76 = F_42 ( V_12 , F_33 ( V_12 , 4 ) ,
F_33 ( V_12 , 5 ) ,
F_33 ( V_12 , 6 ) ) ;
break;
case V_167 :
if ( F_64 ( & V_12 -> V_71 -> V_16 . V_168 ) )
return V_159 ;
V_155 = F_65 ( & V_12 -> V_71 -> V_169 ) ;
V_156 = F_66 ( V_12 ) ;
F_67 ( & V_12 -> V_71 -> V_169 , V_155 ) ;
if ( V_156 == - V_170 )
return V_159 ;
else if ( V_156 == 0 )
break;
return V_156 ;
case V_171 :
V_76 = F_68 ( V_12 ) ;
if ( V_76 == V_151 )
return V_159 ;
break;
case V_172 :
V_76 = F_69 ( V_12 ) ;
if ( V_76 == V_151 )
return V_159 ;
break;
case V_173 :
V_76 = F_58 ( V_12 , F_33 ( V_12 , 4 ) ,
F_33 ( V_12 , 5 ) ,
F_33 ( V_12 , 6 ) ,
F_33 ( V_12 , 7 ) ) ;
if ( V_76 == V_151 )
return V_159 ;
break;
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
if ( F_70 ( V_12 ) ) {
V_76 = F_71 ( V_12 , V_154 ) ;
break;
}
default:
return V_159 ;
}
F_72 ( V_12 , 3 , V_76 ) ;
V_12 -> V_16 . V_180 = 0 ;
return V_181 ;
}
static int F_73 ( unsigned long V_182 )
{
switch ( V_182 ) {
case V_160 :
case V_161 :
case V_165 :
case V_166 :
case V_173 :
case V_171 :
case V_172 :
#ifdef F_74
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
#endif
return 1 ;
}
return F_75 ( V_182 ) ;
}
static int F_76 ( struct V_183 * V_184 ,
struct V_11 * V_12 )
{
T_3 V_73 ;
if ( F_77 ( V_12 , V_185 , & V_73 ) !=
V_186 ) {
return V_181 ;
}
if ( V_73 == V_187 ) {
V_184 -> V_188 = V_189 ;
V_184 -> V_190 . V_16 . V_191 = F_55 ( V_12 ) ;
return V_159 ;
} else {
F_78 ( V_12 , V_192 ) ;
return V_181 ;
}
}
static int F_79 ( struct V_183 * V_184 , struct V_11 * V_12 ,
struct V_193 * V_194 )
{
int V_48 = V_159 ;
V_12 -> V_14 . V_195 ++ ;
V_184 -> V_188 = V_196 ;
V_184 -> V_197 = 1 ;
switch ( V_12 -> V_16 . V_51 ) {
case V_198 :
V_12 -> V_14 . V_199 ++ ;
V_48 = V_181 ;
break;
case V_200 :
case V_201 :
V_12 -> V_14 . V_202 ++ ;
V_48 = V_181 ;
break;
case V_203 :
case V_204 :
V_48 = V_181 ;
break;
case V_205 :
F_80 ( V_12 ,
V_205 ) ;
V_48 = V_181 ;
break;
case V_206 :
{
T_4 V_20 ;
V_20 = V_12 -> V_16 . V_36 . V_34 & 0x1f0000ull ;
F_78 ( V_12 , V_20 ) ;
V_48 = V_181 ;
break;
}
case V_207 :
{
int V_208 ;
V_184 -> V_209 . V_210 = F_33 ( V_12 , 3 ) ;
for ( V_208 = 0 ; V_208 < 9 ; ++ V_208 )
V_184 -> V_209 . args [ V_208 ] = F_33 ( V_12 , 4 + V_208 ) ;
V_184 -> V_188 = V_211 ;
V_12 -> V_16 . V_180 = 1 ;
V_48 = V_159 ;
break;
}
case V_212 :
V_48 = V_213 ;
break;
case V_214 :
V_12 -> V_16 . V_64 = F_55 ( V_12 ) ;
V_12 -> V_16 . V_65 = 0 ;
V_48 = V_213 ;
break;
case V_215 :
if ( V_12 -> V_16 . V_216 != V_217 )
V_12 -> V_16 . V_73 = F_81 ( V_12 ) ?
F_82 ( V_12 -> V_16 . V_216 ) :
V_12 -> V_16 . V_216 ;
if ( V_12 -> V_218 & V_219 ) {
V_48 = F_76 ( V_184 , V_12 ) ;
} else {
F_78 ( V_12 , V_192 ) ;
V_48 = V_181 ;
}
break;
case V_220 :
F_78 ( V_12 , V_192 ) ;
V_48 = V_181 ;
break;
default:
F_31 ( V_12 ) ;
F_83 ( V_221 L_14 ,
V_12 -> V_16 . V_51 , F_55 ( V_12 ) ,
V_12 -> V_16 . V_36 . V_34 ) ;
V_184 -> V_222 . V_223 = V_12 -> V_16 . V_51 ;
V_48 = V_159 ;
break;
}
return V_48 ;
}
static int F_84 ( struct V_11 * V_12 ,
struct V_224 * V_225 )
{
int V_208 ;
memset ( V_225 , 0 , sizeof( struct V_224 ) ) ;
V_225 -> V_37 = V_12 -> V_16 . V_37 ;
for ( V_208 = 0 ; V_208 < V_12 -> V_16 . V_66 ; V_208 ++ ) {
V_225 -> V_226 . V_227 . V_228 . V_67 [ V_208 ] . V_229 = V_12 -> V_16 . V_67 [ V_208 ] . V_68 ;
V_225 -> V_226 . V_227 . V_228 . V_67 [ V_208 ] . V_230 = V_12 -> V_16 . V_67 [ V_208 ] . V_69 ;
}
return 0 ;
}
static int F_85 ( struct V_11 * V_12 ,
struct V_224 * V_225 )
{
int V_208 , V_231 ;
if ( V_225 -> V_37 != V_12 -> V_16 . V_37 )
return - V_46 ;
V_231 = 0 ;
for ( V_208 = 0 ; V_208 < V_12 -> V_16 . V_232 ; V_208 ++ ) {
if ( V_225 -> V_226 . V_227 . V_228 . V_67 [ V_208 ] . V_229 & V_233 ) {
V_12 -> V_16 . V_67 [ V_231 ] . V_68 = V_225 -> V_226 . V_227 . V_228 . V_67 [ V_208 ] . V_229 ;
V_12 -> V_16 . V_67 [ V_231 ] . V_69 = V_225 -> V_226 . V_227 . V_228 . V_67 [ V_208 ] . V_230 ;
++ V_231 ;
}
}
V_12 -> V_16 . V_66 = V_231 ;
return 0 ;
}
static void F_86 ( struct V_11 * V_12 , T_2 V_234 ,
bool V_235 )
{
struct V_71 * V_71 = V_12 -> V_71 ;
struct V_18 * V_19 = V_12 -> V_16 . V_25 ;
T_2 V_236 ;
F_35 ( & V_71 -> V_47 ) ;
F_29 ( & V_19 -> V_47 ) ;
if ( ( V_234 & V_237 ) != ( V_19 -> V_70 & V_237 ) ) {
struct V_11 * V_12 ;
int V_208 ;
F_36 (i, vcpu, kvm) {
if ( V_12 -> V_16 . V_25 != V_19 )
continue;
if ( V_234 & V_237 )
V_12 -> V_16 . V_238 |= V_239 ;
else
V_12 -> V_16 . V_238 &= ~ V_239 ;
}
}
V_236 = V_240 | V_237 | V_241 ;
if ( F_2 ( V_2 ) )
V_236 |= V_242 ;
if ( V_235 )
V_236 &= 0xFFFFFFFF ;
V_19 -> V_70 = ( V_19 -> V_70 & ~ V_236 ) | ( V_234 & V_236 ) ;
F_30 ( & V_19 -> V_47 ) ;
F_37 ( & V_71 -> V_47 ) ;
}
static int F_87 ( struct V_11 * V_12 , T_2 V_74 ,
union V_243 * V_244 )
{
int V_48 = 0 ;
long int V_208 ;
switch ( V_74 ) {
case V_245 :
* V_244 = F_88 ( V_74 , V_187 ) ;
break;
case V_246 :
* V_244 = F_88 ( V_74 , 0 ) ;
break;
case V_247 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_248 ) ;
break;
case V_249 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_250 ) ;
break;
case V_251 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_252 ) ;
break;
case V_253 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_254 ) ;
break;
case V_255 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_256 ) ;
break;
case V_257 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_258 ) ;
break;
case V_259 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_260 ) ;
break;
case V_261 ... V_262 :
V_208 = V_74 - V_261 ;
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_263 [ V_208 ] ) ;
break;
case V_264 ... V_265 :
V_208 = V_74 - V_264 ;
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_266 [ V_208 ] ) ;
break;
case V_267 ... V_268 :
V_208 = V_74 - V_267 ;
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_269 [ V_208 ] ) ;
break;
case V_270 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_271 ) ;
break;
case V_272 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_273 ) ;
break;
case V_274 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_275 ) ;
break;
case V_276 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_277 ) ;
break;
case V_278 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_279 ) ;
break;
case V_280 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_25 -> V_281 ) ;
break;
case V_282 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_149 ) ;
break;
case V_283 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_150 ) ;
break;
case V_284 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_145 ) ;
break;
case V_285 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_286 ) ;
break;
case V_287 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_288 ) ;
break;
case V_289 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_290 ) ;
break;
case V_291 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_292 ) ;
break;
case V_293 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_294 ) ;
break;
case V_295 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_296 ) ;
break;
case V_297 :
F_29 ( & V_12 -> V_16 . V_86 ) ;
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_78 . V_87 ) ;
F_30 ( & V_12 -> V_16 . V_86 ) ;
break;
case V_298 :
F_29 ( & V_12 -> V_16 . V_86 ) ;
V_244 -> V_299 . V_83 = V_12 -> V_16 . V_110 . V_87 ;
V_244 -> V_299 . V_104 = V_12 -> V_16 . V_110 . V_84 ;
F_30 ( & V_12 -> V_16 . V_86 ) ;
break;
case V_300 :
F_29 ( & V_12 -> V_16 . V_86 ) ;
V_244 -> V_299 . V_83 = V_12 -> V_16 . V_109 . V_87 ;
V_244 -> V_299 . V_104 = V_12 -> V_16 . V_109 . V_84 ;
F_30 ( & V_12 -> V_16 . V_86 ) ;
break;
case V_301 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_25 -> V_131 ) ;
break;
case V_302 :
case V_303 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_25 -> V_70 ) ;
break;
case V_304 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_305 ) ;
break;
#ifdef F_89
case V_306 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_307 ) ;
break;
case V_308 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_309 ) ;
break;
case V_310 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_311 ) ;
break;
case V_312 ... V_313 :
V_208 = V_74 - V_312 ;
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_314 [ V_208 ] ) ;
break;
case V_315 ... V_316 :
{
int V_231 ;
V_208 = V_74 - V_315 ;
if ( V_208 < 32 )
for ( V_231 = 0 ; V_231 < V_317 ; V_231 ++ )
V_244 -> V_318 [ V_231 ] = V_12 -> V_16 . V_319 . V_320 [ V_208 ] [ V_231 ] ;
else {
if ( F_2 ( V_321 ) )
V_244 -> V_322 = V_12 -> V_16 . V_323 . V_324 [ V_208 - 32 ] ;
else
V_48 = - V_325 ;
}
break;
}
case V_326 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_327 ) ;
break;
case V_328 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_329 ) ;
break;
case V_330 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_331 ) ;
break;
case V_332 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_319 . V_333 ) ;
break;
case V_334 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_335 ) ;
break;
case V_336 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_337 ) ;
break;
case V_338 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_339 ) ;
break;
case V_340 :
if ( F_2 ( V_321 ) )
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_323 . V_341 . V_226 [ 3 ] ) ;
else
V_48 = - V_325 ;
break;
case V_342 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_343 ) ;
break;
case V_344 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_345 ) ;
break;
#endif
case V_346 :
* V_244 = F_88 ( V_74 , V_12 -> V_16 . V_25 -> V_38 ) ;
break;
default:
V_48 = - V_46 ;
break;
}
return V_48 ;
}
static int F_90 ( struct V_11 * V_12 , T_2 V_74 ,
union V_243 * V_244 )
{
int V_48 = 0 ;
long int V_208 ;
unsigned long V_83 , V_84 ;
switch ( V_74 ) {
case V_246 :
if ( F_91 ( V_74 , * V_244 ) )
V_48 = - V_46 ;
break;
case V_247 :
V_12 -> V_16 . V_248 = F_91 ( V_74 , * V_244 ) ;
break;
case V_249 :
V_12 -> V_16 . V_250 = F_91 ( V_74 , * V_244 ) & ~ V_148 ;
break;
case V_251 :
V_12 -> V_16 . V_252 = F_91 ( V_74 , * V_244 ) ;
break;
case V_253 :
V_12 -> V_16 . V_254 = F_91 ( V_74 , * V_244 ) ;
break;
case V_255 :
V_12 -> V_16 . V_256 = F_91 ( V_74 , * V_244 ) ;
break;
case V_257 :
V_12 -> V_16 . V_258 = F_91 ( V_74 , * V_244 ) ;
break;
case V_259 :
V_12 -> V_16 . V_260 = F_91 ( V_74 , * V_244 ) ;
break;
case V_261 ... V_262 :
V_208 = V_74 - V_261 ;
V_12 -> V_16 . V_263 [ V_208 ] = F_91 ( V_74 , * V_244 ) ;
break;
case V_264 ... V_265 :
V_208 = V_74 - V_264 ;
V_12 -> V_16 . V_266 [ V_208 ] = F_91 ( V_74 , * V_244 ) ;
break;
case V_267 ... V_268 :
V_208 = V_74 - V_267 ;
V_12 -> V_16 . V_269 [ V_208 ] = F_91 ( V_74 , * V_244 ) ;
break;
case V_270 :
V_12 -> V_16 . V_271 = F_91 ( V_74 , * V_244 ) ;
break;
case V_272 :
V_12 -> V_16 . V_273 = F_91 ( V_74 , * V_244 ) ;
break;
case V_274 :
V_12 -> V_16 . V_275 = F_91 ( V_74 , * V_244 ) ;
break;
case V_276 :
V_12 -> V_16 . V_277 = F_91 ( V_74 , * V_244 ) ;
break;
case V_278 :
V_12 -> V_16 . V_279 = F_91 ( V_74 , * V_244 ) ;
break;
case V_280 :
V_12 -> V_16 . V_25 -> V_281 = F_91 ( V_74 , * V_244 ) ;
break;
case V_282 :
V_12 -> V_16 . V_149 = F_91 ( V_74 , * V_244 ) ;
break;
case V_283 :
V_12 -> V_16 . V_150 = F_91 ( V_74 , * V_244 ) & ~ V_347 ;
break;
case V_284 :
V_12 -> V_16 . V_145 = F_91 ( V_74 , * V_244 ) ;
if ( ( V_12 -> V_16 . V_145 & V_142 ) == V_143 )
V_12 -> V_16 . V_145 &= ~ V_142 ;
break;
case V_285 :
V_12 -> V_16 . V_286 = F_91 ( V_74 , * V_244 ) ;
break;
case V_287 :
V_12 -> V_16 . V_288 = F_91 ( V_74 , * V_244 ) ;
break;
case V_289 :
V_12 -> V_16 . V_290 = F_91 ( V_74 , * V_244 ) ;
break;
case V_291 :
V_12 -> V_16 . V_292 = F_91 ( V_74 , * V_244 ) ;
break;
case V_293 :
V_12 -> V_16 . V_294 = F_91 ( V_74 , * V_244 ) ;
break;
case V_295 :
V_12 -> V_16 . V_296 = F_91 ( V_74 , * V_244 ) ;
break;
case V_297 :
V_83 = F_91 ( V_74 , * V_244 ) ;
V_48 = - V_46 ;
if ( ! V_83 && ( V_12 -> V_16 . V_110 . V_87 ||
V_12 -> V_16 . V_109 . V_87 ) )
break;
V_48 = F_40 ( V_12 , & V_12 -> V_16 . V_78 , V_83 , sizeof( struct V_77 ) ) ;
break;
case V_298 :
V_83 = V_244 -> V_299 . V_83 ;
V_84 = V_244 -> V_299 . V_104 ;
V_48 = - V_46 ;
if ( V_83 && ! V_12 -> V_16 . V_78 . V_87 )
break;
V_48 = F_40 ( V_12 , & V_12 -> V_16 . V_110 , V_83 , V_84 ) ;
break;
case V_300 :
V_83 = V_244 -> V_299 . V_83 ;
V_84 = V_244 -> V_299 . V_104 ;
V_48 = - V_46 ;
if ( V_83 && ( V_84 < sizeof( struct V_107 ) ||
! V_12 -> V_16 . V_78 . V_87 ) )
break;
V_84 -= V_84 % sizeof( struct V_107 ) ;
V_48 = F_40 ( V_12 , & V_12 -> V_16 . V_109 , V_83 , V_84 ) ;
break;
case V_301 :
V_12 -> V_16 . V_25 -> V_131 =
F_92 ( F_91 ( V_74 , * V_244 ) , 1UL << 24 ) ;
break;
case V_302 :
F_86 ( V_12 , F_91 ( V_74 , * V_244 ) , true ) ;
break;
case V_303 :
F_86 ( V_12 , F_91 ( V_74 , * V_244 ) , false ) ;
break;
case V_304 :
V_12 -> V_16 . V_305 = F_91 ( V_74 , * V_244 ) ;
break;
#ifdef F_89
case V_306 :
V_12 -> V_16 . V_307 = F_91 ( V_74 , * V_244 ) ;
break;
case V_308 :
V_12 -> V_16 . V_309 = F_91 ( V_74 , * V_244 ) ;
break;
case V_310 :
V_12 -> V_16 . V_311 = F_91 ( V_74 , * V_244 ) ;
break;
case V_312 ... V_313 :
V_208 = V_74 - V_312 ;
V_12 -> V_16 . V_314 [ V_208 ] = F_91 ( V_74 , * V_244 ) ;
break;
case V_315 ... V_316 :
{
int V_231 ;
V_208 = V_74 - V_315 ;
if ( V_208 < 32 )
for ( V_231 = 0 ; V_231 < V_317 ; V_231 ++ )
V_12 -> V_16 . V_319 . V_320 [ V_208 ] [ V_231 ] = V_244 -> V_318 [ V_231 ] ;
else
if ( F_2 ( V_321 ) )
V_12 -> V_16 . V_323 . V_324 [ V_208 - 32 ] = V_244 -> V_322 ;
else
V_48 = - V_325 ;
break;
}
case V_326 :
V_12 -> V_16 . V_327 = F_91 ( V_74 , * V_244 ) ;
break;
case V_328 :
V_12 -> V_16 . V_329 = F_91 ( V_74 , * V_244 ) ;
break;
case V_330 :
V_12 -> V_16 . V_331 = F_91 ( V_74 , * V_244 ) ;
break;
case V_332 :
V_12 -> V_16 . V_319 . V_333 = F_91 ( V_74 , * V_244 ) ;
break;
case V_334 :
V_12 -> V_16 . V_335 = F_91 ( V_74 , * V_244 ) ;
break;
case V_336 :
V_12 -> V_16 . V_337 = F_91 ( V_74 , * V_244 ) ;
break;
case V_338 :
V_12 -> V_16 . V_339 = F_91 ( V_74 , * V_244 ) ;
break;
case V_340 :
if ( F_2 ( V_321 ) )
V_12 -> V_16 . V_324 . V_341 . V_226 [ 3 ] = F_91 ( V_74 , * V_244 ) ;
else
V_48 = - V_325 ;
break;
case V_342 :
V_12 -> V_16 . V_343 = F_91 ( V_74 , * V_244 ) ;
break;
case V_344 :
V_12 -> V_16 . V_345 = F_91 ( V_74 , * V_244 ) ;
break;
#endif
case V_346 :
V_48 = F_28 ( V_12 , F_91 ( V_74 , * V_244 ) ) ;
break;
default:
V_48 = - V_46 ;
break;
}
return V_48 ;
}
static struct V_18 * F_93 ( struct V_71 * V_71 , int V_348 )
{
struct V_18 * V_25 ;
V_25 = F_94 ( sizeof( struct V_18 ) , V_349 ) ;
if ( V_25 == NULL )
return NULL ;
F_95 ( & V_25 -> V_350 ) ;
F_96 ( & V_25 -> V_47 ) ;
F_96 ( & V_25 -> V_21 ) ;
F_97 ( & V_25 -> V_164 ) ;
V_25 -> V_22 = V_23 ;
V_25 -> V_70 = V_71 -> V_16 . V_70 ;
V_25 -> V_351 = V_348 * V_352 ;
V_25 -> V_71 = V_71 ;
F_95 ( & V_25 -> V_353 ) ;
return V_25 ;
}
static int F_98 ( struct V_354 * V_354 , struct V_355 * V_355 )
{
struct V_11 * V_12 = V_354 -> V_356 ;
struct V_357 * V_120 ;
V_120 = F_94 ( sizeof( * V_120 ) , V_349 ) ;
if ( ! V_120 )
return - V_358 ;
F_99 ( V_12 -> V_71 ) ;
V_120 -> V_12 = V_12 ;
V_355 -> V_359 = V_120 ;
return F_100 ( V_354 , V_355 ) ;
}
static int F_101 ( struct V_354 * V_354 , struct V_355 * V_355 )
{
struct V_357 * V_120 = V_355 -> V_359 ;
F_102 ( V_120 -> V_12 -> V_71 ) ;
F_103 ( V_120 ) ;
return 0 ;
}
static T_5 F_104 ( struct V_355 * V_355 , char T_6 * V_360 ,
T_7 V_84 , T_8 * V_361 )
{
struct V_357 * V_120 = V_355 -> V_359 ;
struct V_11 * V_12 = V_120 -> V_12 ;
char * V_227 , * V_362 ;
struct V_363 V_364 ;
T_2 V_365 ;
T_8 V_366 ;
T_5 V_367 ;
int V_208 , V_368 ;
bool V_369 ;
if ( ! V_120 -> V_370 ) {
V_227 = V_120 -> V_360 ;
V_362 = V_227 + sizeof( V_120 -> V_360 ) ;
for ( V_208 = 0 ; V_208 < V_371 ; ++ V_208 ) {
struct V_363 * V_372 ;
V_372 = (struct V_363 * )
( ( unsigned long ) V_12 + V_373 [ V_208 ] . V_374 ) ;
V_369 = false ;
for ( V_368 = 0 ; V_368 < 1000 ; ++ V_368 ) {
V_365 = V_372 -> V_375 ;
if ( ! ( V_365 & 1 ) ) {
F_105 () ;
V_364 = * V_372 ;
F_105 () ;
if ( V_365 == V_372 -> V_375 ) {
V_369 = true ;
break;
}
}
F_106 ( 1 ) ;
}
if ( ! V_369 )
snprintf ( V_227 , V_362 - V_227 , L_15 ,
V_373 [ V_208 ] . V_376 ) ;
else
snprintf ( V_227 , V_362 - V_227 ,
L_16 ,
V_373 [ V_208 ] . V_376 , V_365 / 2 ,
F_107 ( V_364 . V_377 ) ,
F_107 ( V_364 . V_378 ) ,
F_107 ( V_364 . V_379 ) ) ;
V_227 += strlen ( V_227 ) ;
}
V_120 -> V_370 = V_227 - V_120 -> V_360 ;
}
V_366 = * V_361 ;
if ( V_366 >= V_120 -> V_370 )
return 0 ;
if ( V_84 > V_120 -> V_370 - V_366 )
V_84 = V_120 -> V_370 - V_366 ;
V_367 = F_108 ( V_360 , V_120 -> V_360 + V_366 , V_84 ) ;
if ( V_367 ) {
if ( V_367 == V_84 )
return - V_380 ;
V_84 -= V_367 ;
}
* V_361 = V_366 + V_84 ;
return V_84 ;
}
static T_5 F_109 ( struct V_355 * V_355 , const char T_6 * V_360 ,
T_7 V_84 , T_8 * V_361 )
{
return - V_381 ;
}
static void F_110 ( struct V_11 * V_12 , unsigned int V_74 )
{
char V_360 [ 16 ] ;
struct V_71 * V_71 = V_12 -> V_71 ;
snprintf ( V_360 , sizeof( V_360 ) , L_17 , V_74 ) ;
if ( F_111 ( V_71 -> V_16 . V_382 ) )
return;
V_12 -> V_16 . V_382 = F_112 ( V_360 , V_71 -> V_16 . V_382 ) ;
if ( F_111 ( V_12 -> V_16 . V_382 ) )
return;
V_12 -> V_16 . V_383 =
F_113 ( L_18 , 0444 , V_12 -> V_16 . V_382 ,
V_12 , & V_384 ) ;
}
static void F_110 ( struct V_11 * V_12 , unsigned int V_74 )
{
}
static struct V_11 * F_114 ( struct V_71 * V_71 ,
unsigned int V_74 )
{
struct V_11 * V_12 ;
int V_95 = - V_46 ;
int V_348 ;
struct V_18 * V_25 ;
V_348 = V_74 / V_352 ;
if ( V_348 >= V_385 )
goto V_386;
V_95 = - V_358 ;
V_12 = F_115 ( V_387 , V_349 ) ;
if ( ! V_12 )
goto V_386;
V_95 = F_116 ( V_12 , V_71 , V_74 ) ;
if ( V_95 )
goto V_388;
V_12 -> V_16 . V_389 = & V_12 -> V_16 . V_36 ;
#ifdef F_117
#ifdef F_118
V_12 -> V_16 . V_390 = true ;
#else
V_12 -> V_16 . V_390 = false ;
#endif
#endif
V_12 -> V_16 . V_263 [ 0 ] = V_391 ;
V_12 -> V_16 . V_392 = V_393 ;
F_27 ( V_12 , F_119 ( V_394 ) ) ;
F_96 ( & V_12 -> V_16 . V_86 ) ;
F_96 ( & V_12 -> V_16 . V_29 ) ;
V_12 -> V_16 . V_32 = V_23 ;
V_12 -> V_16 . V_238 = V_395 | V_396 ;
F_120 ( V_12 ) ;
V_12 -> V_16 . V_30 = V_397 ;
F_97 ( & V_12 -> V_16 . V_398 ) ;
F_35 ( & V_71 -> V_47 ) ;
V_25 = V_71 -> V_16 . V_399 [ V_348 ] ;
if ( ! V_25 ) {
V_25 = F_93 ( V_71 , V_348 ) ;
V_71 -> V_16 . V_399 [ V_348 ] = V_25 ;
V_71 -> V_16 . V_400 ++ ;
}
F_37 ( & V_71 -> V_47 ) ;
if ( ! V_25 )
goto V_388;
F_29 ( & V_25 -> V_47 ) ;
++ V_25 -> V_401 ;
F_30 ( & V_25 -> V_47 ) ;
V_12 -> V_16 . V_25 = V_25 ;
V_12 -> V_16 . V_129 = V_12 -> V_49 - V_25 -> V_351 ;
V_12 -> V_16 . V_17 = - 1 ;
V_12 -> V_16 . V_402 = V_403 ;
F_121 ( V_12 ) ;
F_110 ( V_12 , V_74 ) ;
return V_12 ;
V_388:
F_122 ( V_387 , V_12 ) ;
V_386:
return F_123 ( V_95 ) ;
}
static void F_124 ( struct V_71 * V_71 , struct V_82 * V_78 )
{
if ( V_78 -> V_90 )
F_46 ( V_71 , V_78 -> V_90 , V_78 -> V_114 ,
V_78 -> V_115 ) ;
}
static void F_125 ( struct V_11 * V_12 )
{
F_29 ( & V_12 -> V_16 . V_86 ) ;
F_124 ( V_12 -> V_71 , & V_12 -> V_16 . V_109 ) ;
F_124 ( V_12 -> V_71 , & V_12 -> V_16 . V_110 ) ;
F_124 ( V_12 -> V_71 , & V_12 -> V_16 . V_78 ) ;
F_30 ( & V_12 -> V_16 . V_86 ) ;
F_126 ( V_12 ) ;
F_122 ( V_387 , V_12 ) ;
}
static int F_127 ( struct V_11 * V_12 )
{
return 1 ;
}
static void F_128 ( struct V_11 * V_12 )
{
unsigned long V_404 , V_119 ;
V_119 = F_129 () ;
if ( V_119 > V_12 -> V_16 . V_405 ) {
F_130 ( V_12 ) ;
F_131 ( V_12 ) ;
return;
}
V_404 = ( V_12 -> V_16 . V_405 - V_119 ) * V_406
/ V_407 ;
F_132 ( & V_12 -> V_16 . V_408 , F_133 ( 0 , V_404 ) ,
V_409 ) ;
V_12 -> V_16 . V_410 = 1 ;
}
static void F_26 ( struct V_11 * V_12 )
{
V_12 -> V_16 . V_163 = 0 ;
if ( V_12 -> V_16 . V_410 ) {
F_134 ( & V_12 -> V_16 . V_408 ) ;
V_12 -> V_16 . V_410 = 0 ;
}
}
static void F_135 ( struct V_18 * V_19 ,
struct V_11 * V_12 )
{
T_2 V_119 ;
if ( V_12 -> V_16 . V_30 != V_153 )
return;
F_51 ( & V_12 -> V_16 . V_29 ) ;
V_119 = F_20 () ;
V_12 -> V_16 . V_33 += F_49 ( V_19 , V_119 ) -
V_12 -> V_16 . V_125 ;
V_12 -> V_16 . V_32 = V_119 ;
V_12 -> V_16 . V_30 = V_31 ;
F_52 ( & V_12 -> V_16 . V_29 ) ;
-- V_19 -> V_411 ;
F_136 ( & V_12 -> V_16 . V_412 ) ;
}
static int F_137 ( int V_1 )
{
struct V_413 * V_414 ;
long V_415 = 10000 ;
V_414 = & V_8 [ V_1 ] ;
V_414 -> V_9 . V_11 = NULL ;
V_414 -> V_9 . V_416 = NULL ;
V_414 -> V_9 . V_417 = 0 ;
F_56 () ;
V_414 -> V_9 . V_418 = 1 ;
F_8 () ;
while ( V_414 -> V_9 . V_419 == V_420 ) {
if ( -- V_415 <= 0 ) {
F_32 ( L_19 , V_1 ) ;
return - V_421 ;
}
F_106 ( 1 ) ;
}
return 0 ;
}
static void F_138 ( int V_1 )
{
struct V_413 * V_414 ;
V_414 = & V_8 [ V_1 ] ;
V_414 -> V_9 . V_418 = 0 ;
V_414 -> V_9 . V_11 = NULL ;
V_414 -> V_9 . V_416 = NULL ;
V_414 -> V_9 . V_422 = NULL ;
}
static void F_139 ( struct V_11 * V_12 , struct V_18 * V_19 )
{
int V_1 ;
struct V_413 * V_414 ;
struct V_18 * V_423 = V_19 -> V_424 ;
V_1 = V_19 -> V_128 ;
if ( V_12 ) {
if ( V_12 -> V_16 . V_410 ) {
F_134 ( & V_12 -> V_16 . V_408 ) ;
V_12 -> V_16 . V_410 = 0 ;
}
V_1 += V_12 -> V_16 . V_129 ;
V_12 -> V_1 = V_423 -> V_128 ;
V_12 -> V_16 . V_17 = V_1 ;
}
V_414 = & V_8 [ V_1 ] ;
V_414 -> V_9 . V_11 = V_12 ;
V_414 -> V_9 . V_129 = V_1 - V_423 -> V_128 ;
F_56 () ;
V_414 -> V_9 . V_416 = V_423 ;
if ( V_1 != F_5 () )
F_1 ( V_1 ) ;
}
static void F_140 ( void )
{
int V_1 = F_5 () ;
int V_208 , V_368 ;
for ( V_368 = 0 ; V_368 < 1000000 ; ++ V_368 ) {
for ( V_208 = 1 ; V_208 < V_352 ; ++ V_208 )
if ( V_8 [ V_1 + V_208 ] . V_9 . V_416 )
break;
if ( V_208 == V_352 ) {
F_141 () ;
return;
}
F_142 () ;
}
F_141 () ;
for ( V_208 = 1 ; V_208 < V_352 ; ++ V_208 )
if ( V_8 [ V_1 + V_208 ] . V_9 . V_416 )
F_32 ( L_20 , V_1 + V_208 ) ;
}
static int F_143 ( void )
{
int V_1 = F_5 () ;
int V_425 ;
if ( F_144 ( V_1 ) )
return 0 ;
V_425 = 0 ;
while ( ++ V_425 < V_352 )
if ( F_16 ( V_1 + V_425 ) )
return 0 ;
for ( V_425 = 1 ; V_425 < V_352 ; ++ V_425 ) {
if ( F_137 ( V_1 + V_425 ) ) {
do {
F_138 ( V_1 + V_425 ) ;
} while ( -- V_425 > 0 );
return 0 ;
}
}
return 1 ;
}
static void F_145 ( void )
{
int V_1 ;
F_146 (cpu) {
struct V_426 * V_427 = & F_147 ( V_428 , V_1 ) ;
F_96 ( & V_427 -> V_47 ) ;
F_95 ( & V_427 -> V_429 ) ;
}
}
static void F_148 ( struct V_18 * V_19 )
{
struct V_426 * V_427 = F_149 ( & V_428 ) ;
V_19 -> V_27 = V_430 ;
V_19 -> V_128 = F_5 () ;
if ( V_19 -> V_401 < V_352 ) {
F_29 ( & V_427 -> V_47 ) ;
F_150 ( & V_19 -> V_353 , & V_427 -> V_429 ) ;
F_30 ( & V_427 -> V_47 ) ;
}
F_18 ( V_19 ) ;
}
static void F_151 ( struct V_18 * V_19 )
{
struct V_426 * V_427 ;
F_22 ( V_19 ) ;
if ( ! F_64 ( & V_19 -> V_353 ) ) {
V_427 = & F_147 ( V_428 , V_19 -> V_128 ) ;
F_29 ( & V_427 -> V_47 ) ;
F_152 ( & V_19 -> V_353 ) ;
F_30 ( & V_427 -> V_47 ) ;
}
V_19 -> V_27 = V_121 ;
}
static void F_153 ( struct V_431 * V_432 , struct V_18 * V_19 )
{
int V_433 ;
memset ( V_432 , 0 , sizeof( * V_432 ) ) ;
V_432 -> V_434 = 1 ;
V_432 -> V_435 = V_19 -> V_401 ;
V_432 -> V_436 = V_19 -> V_401 ;
V_432 -> V_437 [ 0 ] = V_19 -> V_401 ;
V_432 -> V_438 [ 0 ] = V_19 -> V_71 ;
for ( V_433 = 0 ; V_433 < V_439 ; ++ V_433 )
F_95 ( & V_432 -> V_440 [ V_433 ] ) ;
F_150 ( & V_19 -> V_353 , & V_432 -> V_440 [ 0 ] ) ;
}
static bool F_154 ( int V_434 , int V_441 )
{
if ( V_434 > 1 && V_352 < V_442 )
return false ;
if ( V_434 > V_439 )
return false ;
if ( V_434 > 1 ) {
if ( ! ( V_443 & 2 ) )
V_434 = 4 ;
if ( V_434 > 2 && ! ( V_443 & 4 ) )
return false ;
}
return V_434 * F_155 ( V_441 ) <= V_442 ;
}
static void F_156 ( struct V_18 * V_19 )
{
V_19 -> V_424 = V_19 ;
V_19 -> V_444 = 0 ;
V_19 -> V_445 = 0 ;
V_19 -> V_446 = 0 ;
V_19 -> V_447 = 0 ;
}
static bool F_157 ( struct V_431 * V_432 )
{
int V_433 , V_448 ;
int V_449 = - 1 ;
int V_425 ;
int V_434 = V_432 -> V_434 ;
struct V_18 * V_19 , * V_450 ;
struct V_18 * V_451 = NULL ;
for ( V_433 = 0 ; V_433 < V_432 -> V_434 ; ++ V_433 ) {
if ( V_432 -> V_437 [ V_433 ] <= 2 )
continue;
if ( V_449 >= 0 )
return false ;
V_449 = V_433 ;
V_19 = F_158 ( & V_432 -> V_440 [ V_433 ] , struct V_18 ,
V_353 ) ;
if ( V_19 -> V_401 > 2 )
return false ;
V_434 += ( V_432 -> V_437 [ V_433 ] - 1 ) >> 1 ;
}
if ( V_449 < 0 || ! F_154 ( V_434 + 1 , 2 ) )
return false ;
V_448 = V_432 -> V_434 ;
V_425 = 0 ;
V_433 = V_449 ;
F_159 (vc, vcnext, &cip->vcs[sub], preempt_list) {
if ( V_425 >= 2 ) {
F_136 ( & V_19 -> V_353 ) ;
F_150 ( & V_19 -> V_353 , & V_432 -> V_440 [ V_448 ] ) ;
if ( ++ V_432 -> V_437 [ V_448 ] == 1 ) {
V_432 -> V_438 [ V_448 ] = V_19 -> V_71 ;
F_156 ( V_19 ) ;
V_451 = V_19 ;
++ V_432 -> V_434 ;
} else {
V_19 -> V_424 = V_451 ;
++ V_448 ;
}
}
V_425 += V_19 -> V_401 ;
}
V_432 -> V_437 [ V_449 ] = 2 ;
V_432 -> V_435 = 2 ;
return true ;
}
static bool F_160 ( struct V_18 * V_19 , struct V_431 * V_432 )
{
int V_441 = V_19 -> V_401 ;
int V_433 ;
if ( ! F_2 ( V_2 ) )
return false ;
if ( V_441 < V_432 -> V_435 )
V_441 = V_432 -> V_435 ;
if ( F_154 ( V_432 -> V_434 + 1 , V_441 ) ) {
V_432 -> V_435 = V_441 ;
} else if ( V_432 -> V_434 <= 2 && V_432 -> V_436 <= 6 &&
V_19 -> V_401 <= 2 ) {
if ( ! F_157 ( V_432 ) )
return false ;
} else {
return false ;
}
V_433 = V_432 -> V_434 ;
++ V_432 -> V_434 ;
V_432 -> V_436 += V_19 -> V_401 ;
V_432 -> V_437 [ V_433 ] = V_19 -> V_401 ;
V_432 -> V_438 [ V_433 ] = V_19 -> V_71 ;
F_156 ( V_19 ) ;
F_136 ( & V_19 -> V_353 ) ;
F_150 ( & V_19 -> V_353 , & V_432 -> V_440 [ V_433 ] ) ;
return true ;
}
static bool F_161 ( struct V_18 * V_452 ,
struct V_431 * V_432 , int V_433 )
{
struct V_18 * V_19 ;
int V_453 ;
V_19 = F_158 ( & V_432 -> V_440 [ V_433 ] , struct V_18 ,
V_353 ) ;
if ( V_452 -> V_71 != V_19 -> V_71 ||
V_452 -> V_131 != V_19 -> V_131 ||
V_452 -> V_39 != V_19 -> V_39 ||
V_452 -> V_70 != V_19 -> V_70 )
return false ;
if ( F_2 ( V_2 ) &&
( V_19 -> V_401 > 1 || V_452 -> V_401 > 1 ) )
return false ;
V_453 = V_432 -> V_437 [ V_433 ] + V_452 -> V_401 ;
if ( V_453 > V_432 -> V_435 ) {
if ( ! F_154 ( V_432 -> V_434 , V_453 ) )
return false ;
V_432 -> V_435 = V_453 ;
}
V_432 -> V_436 += V_452 -> V_401 ;
V_432 -> V_437 [ V_433 ] = V_453 ;
V_452 -> V_424 = V_19 ;
F_136 ( & V_452 -> V_353 ) ;
F_150 ( & V_452 -> V_353 , & V_432 -> V_440 [ V_433 ] ) ;
return true ;
}
static bool F_162 ( struct V_18 * V_452 , struct V_431 * V_432 ,
int V_454 )
{
int V_433 ;
if ( V_432 -> V_436 + V_452 -> V_401 > V_454 )
return false ;
for ( V_433 = 0 ; V_433 < V_432 -> V_434 ; ++ V_433 )
if ( V_432 -> V_437 [ V_433 ] &&
F_161 ( V_452 , V_432 , V_433 ) )
return true ;
if ( F_160 ( V_452 , V_432 ) )
return true ;
return false ;
}
static void F_163 ( struct V_18 * V_19 )
{
struct V_11 * V_12 , * V_455 ;
F_159 (vcpu, vnext, &vc->runnable_threads,
arch.run_list) {
if ( F_164 ( V_12 -> V_16 . V_456 ) )
V_12 -> V_16 . V_76 = - V_457 ;
else if ( V_12 -> V_16 . V_78 . V_88 ||
V_12 -> V_16 . V_110 . V_88 ||
V_12 -> V_16 . V_109 . V_88 )
V_12 -> V_16 . V_76 = V_181 ;
else
continue;
F_135 ( V_19 , V_12 ) ;
F_165 ( & V_12 -> V_16 . V_398 ) ;
}
}
static void F_166 ( struct V_431 * V_432 , int V_454 )
{
struct V_426 * V_427 = F_149 ( & V_428 ) ;
struct V_18 * V_452 , * V_450 ;
F_29 ( & V_427 -> V_47 ) ;
F_159 (pvc, vcnext, &lp->list, preempt_list) {
if ( ! F_167 ( & V_452 -> V_47 ) )
continue;
F_163 ( V_452 ) ;
if ( ! V_452 -> V_411 ) {
F_152 ( & V_452 -> V_353 ) ;
if ( V_452 -> V_26 == NULL ) {
V_452 -> V_27 = V_121 ;
F_22 ( V_452 ) ;
}
F_30 ( & V_452 -> V_47 ) ;
continue;
}
if ( ! F_162 ( V_452 , V_432 , V_454 ) ) {
F_30 ( & V_452 -> V_47 ) ;
continue;
}
F_22 ( V_452 ) ;
V_452 -> V_27 = V_458 ;
if ( V_432 -> V_436 >= V_454 )
break;
}
F_30 ( & V_427 -> V_47 ) ;
}
static void F_168 ( struct V_18 * V_19 , bool V_459 )
{
int V_460 = 0 ;
T_2 V_119 ;
long V_76 ;
struct V_11 * V_12 , * V_455 ;
F_29 ( & V_19 -> V_47 ) ;
V_119 = F_129 () ;
F_159 (vcpu, vnext, &vc->runnable_threads,
arch.run_list) {
if ( V_119 < V_12 -> V_16 . V_405 &&
F_169 ( V_12 ) )
F_170 ( V_12 ) ;
F_171 ( V_12 ) ;
V_76 = V_181 ;
if ( V_12 -> V_16 . V_51 )
V_76 = F_79 ( V_12 -> V_16 . V_183 , V_12 ,
V_12 -> V_16 . V_456 ) ;
V_12 -> V_16 . V_76 = V_76 ;
V_12 -> V_16 . V_51 = 0 ;
if ( F_172 ( V_12 -> V_16 . V_76 ) ) {
if ( V_12 -> V_16 . V_461 )
F_131 ( V_12 ) ;
if ( V_12 -> V_16 . V_163 )
F_128 ( V_12 ) ;
else
++ V_460 ;
} else {
F_135 ( V_19 , V_12 ) ;
F_165 ( & V_12 -> V_16 . V_398 ) ;
}
}
F_152 ( & V_19 -> V_353 ) ;
if ( ! V_459 ) {
if ( V_460 > 0 ) {
F_148 ( V_19 ) ;
} else if ( V_19 -> V_26 ) {
V_19 -> V_27 = V_430 ;
F_18 ( V_19 ) ;
} else {
V_19 -> V_27 = V_121 ;
}
if ( V_19 -> V_411 > 0 && V_19 -> V_26 == NULL ) {
V_12 = F_158 ( & V_19 -> V_350 ,
struct V_11 , V_16 . V_412 ) ;
F_165 ( & V_12 -> V_16 . V_398 ) ;
}
}
F_30 ( & V_19 -> V_47 ) ;
}
static T_9 void F_173 ( struct V_18 * V_19 )
{
struct V_11 * V_12 , * V_455 ;
int V_208 ;
int V_462 ;
struct V_431 V_431 ;
struct V_18 * V_452 , * V_450 ;
struct V_422 V_463 , * V_464 ;
int V_465 , V_466 , V_467 ;
int V_433 ;
bool V_468 ;
unsigned long V_469 , V_470 ;
int V_128 , V_425 ;
int V_454 ;
F_163 ( V_19 ) ;
if ( V_19 -> V_26 -> V_16 . V_30 != V_153 )
return;
F_156 ( V_19 ) ;
V_19 -> V_22 = V_23 ;
if ( ( V_471 > 1 ) &&
( ( V_19 -> V_401 > V_352 ) || ! F_143 () ) ) {
F_159 (vcpu, vnext, &vc->runnable_threads,
arch.run_list) {
V_12 -> V_16 . V_76 = - V_421 ;
F_135 ( V_19 , V_12 ) ;
F_165 ( & V_12 -> V_16 . V_398 ) ;
}
goto V_386;
}
F_153 ( & V_431 , V_19 ) ;
V_128 = F_5 () ;
V_454 = V_352 ;
if ( V_472 && V_472 < V_454 )
V_454 = V_472 ;
if ( V_19 -> V_401 < V_454 )
F_166 ( & V_431 , V_454 ) ;
V_466 = V_352 ;
V_469 = V_470 = 0 ;
V_465 = V_431 . V_434 ;
V_464 = NULL ;
if ( V_465 > 1 ) {
if ( V_465 == 2 && ( V_443 & 2 ) ) {
V_469 = V_473 ;
V_470 = V_474 ;
} else {
V_465 = 4 ;
V_469 = V_475 ;
V_470 = V_476 ;
}
V_466 = V_442 / V_465 ;
V_464 = & V_463 ;
memset ( & V_463 , 0 , sizeof( V_463 ) ) ;
V_463 . V_477 = F_119 ( V_478 ) ;
V_463 . V_479 = F_119 ( V_480 ) ;
V_463 . V_481 = F_119 ( V_482 ) ;
V_463 . V_466 = V_466 ;
for ( V_433 = 0 ; V_433 < V_431 . V_434 ; ++ V_433 )
V_463 . V_483 [ V_433 ] =
F_158 ( & V_431 . V_440 [ V_433 ] ,
struct V_18 , V_353 ) ;
F_56 () ;
}
V_128 = F_5 () ;
for ( V_425 = 0 ; V_425 < V_352 ; ++ V_425 )
V_8 [ V_128 + V_425 ] . V_9 . V_422 = V_464 ;
if ( V_469 ) {
unsigned long V_484 = F_119 ( V_485 ) ;
V_484 |= V_469 | V_486 ;
F_174 () ;
F_175 ( V_485 , V_484 ) ;
F_176 () ;
for (; ; ) {
V_484 = F_119 ( V_485 ) ;
if ( V_484 & V_470 )
break;
F_177 () ;
}
}
V_467 = 0 ;
for ( V_433 = 0 ; V_433 < V_431 . V_434 ; ++ V_433 ) {
V_425 = V_487 [ V_433 ] ;
V_468 = false ;
V_467 |= 1 << V_425 ;
F_178 (pvc, &core_info.vcs[sub], preempt_list) {
V_452 -> V_128 = V_128 + V_425 ;
F_178 (vcpu, &pvc->runnable_threads,
arch.run_list) {
F_139 ( V_12 , V_452 ) ;
F_50 ( V_12 , V_452 ) ;
F_179 ( V_12 ) ;
if ( ! V_12 -> V_16 . V_129 )
V_468 = true ;
V_467 |= 1 << ( V_425 + V_12 -> V_16 . V_129 ) ;
}
if ( V_452 -> V_424 == V_452 && ! V_468 )
F_139 ( NULL , V_452 ) ;
V_425 += V_452 -> V_401 ;
}
}
F_8 () ;
if ( V_469 )
V_463 . V_488 = 1 ;
if ( V_465 > 1 )
for ( V_425 = 1 ; V_425 < V_352 ; ++ V_425 )
if ( ! ( V_467 & ( 1 << V_425 ) ) )
F_1 ( V_128 + V_425 ) ;
V_19 -> V_27 = V_489 ;
F_3 () ;
F_180 ( V_19 , 0 ) ;
for ( V_433 = 0 ; V_433 < V_431 . V_434 ; ++ V_433 )
F_178 (pvc, &core_info.vcs[sub], preempt_list)
F_30 ( & V_452 -> V_47 ) ;
F_181 () ;
V_462 = F_65 ( & V_19 -> V_71 -> V_169 ) ;
F_182 () ;
F_67 ( & V_19 -> V_71 -> V_169 , V_462 ) ;
F_29 ( & V_19 -> V_47 ) ;
V_19 -> V_27 = V_490 ;
F_140 () ;
if ( V_465 > 1 ) {
unsigned long V_484 = F_119 ( V_485 ) ;
unsigned long V_368 = 0 ;
V_484 &= ~ V_486 ;
V_470 = V_474 | V_476 ;
F_174 () ;
F_175 ( V_485 , V_484 ) ;
F_176 () ;
for (; ; ) {
V_484 = F_119 ( V_485 ) ;
if ( ! ( V_484 & V_470 ) )
break;
F_177 () ;
++ V_368 ;
}
V_463 . V_488 = 0 ;
}
for ( V_208 = 0 ; V_208 < V_352 ; ++ V_208 ) {
F_138 ( V_128 + V_208 ) ;
if ( V_464 && V_464 -> V_491 [ V_208 ] )
F_1 ( V_128 + V_208 ) ;
}
F_30 ( & V_19 -> V_47 ) ;
F_8 () ;
F_183 () ;
for ( V_433 = 0 ; V_433 < V_431 . V_434 ; ++ V_433 )
F_159 (pvc, vcnext, &core_info.vcs[sub],
preempt_list)
F_168 ( V_452 , V_452 == V_19 ) ;
F_29 ( & V_19 -> V_47 ) ;
F_9 () ;
V_386:
V_19 -> V_27 = V_121 ;
F_180 ( V_19 , 1 ) ;
}
static void F_184 ( struct V_18 * V_19 ,
struct V_11 * V_12 , int V_492 )
{
F_185 ( V_493 ) ;
F_186 ( & V_12 -> V_16 . V_398 , & V_493 , V_492 ) ;
if ( V_12 -> V_16 . V_30 == V_153 ) {
F_30 ( & V_19 -> V_47 ) ;
F_187 () ;
F_29 ( & V_19 -> V_47 ) ;
}
F_188 ( & V_12 -> V_16 . V_398 , & V_493 ) ;
}
static void F_189 ( struct V_18 * V_19 )
{
struct V_11 * V_12 ;
int V_494 = 1 ;
F_185 ( V_493 ) ;
F_186 ( & V_19 -> V_164 , & V_493 , V_495 ) ;
F_178 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( V_12 -> V_16 . V_461 || ! V_12 -> V_16 . V_163 ) {
V_494 = 0 ;
break;
}
}
if ( ! V_494 ) {
F_188 ( & V_19 -> V_164 , & V_493 ) ;
return;
}
V_19 -> V_27 = V_28 ;
F_190 ( V_19 , 0 ) ;
F_30 ( & V_19 -> V_47 ) ;
F_187 () ;
F_188 ( & V_19 -> V_164 , & V_493 ) ;
F_29 ( & V_19 -> V_47 ) ;
V_19 -> V_27 = V_121 ;
F_190 ( V_19 , 1 ) ;
}
static int F_191 ( struct V_183 * V_183 , struct V_11 * V_12 )
{
int V_496 ;
struct V_18 * V_19 ;
struct V_11 * V_75 , * V_497 ;
F_192 ( V_12 ) ;
V_183 -> V_188 = 0 ;
V_12 -> V_16 . V_76 = V_181 ;
V_12 -> V_16 . V_51 = 0 ;
F_48 ( V_12 ) ;
V_19 = V_12 -> V_16 . V_25 ;
F_29 ( & V_19 -> V_47 ) ;
V_12 -> V_16 . V_163 = 0 ;
V_12 -> V_16 . V_456 = V_498 ;
V_12 -> V_16 . V_183 = V_183 ;
V_12 -> V_16 . V_125 = F_49 ( V_19 , F_20 () ) ;
V_12 -> V_16 . V_30 = V_153 ;
V_12 -> V_16 . V_32 = V_23 ;
F_150 ( & V_12 -> V_16 . V_412 , & V_19 -> V_350 ) ;
++ V_19 -> V_411 ;
if ( ! F_164 ( V_498 ) ) {
if ( V_19 -> V_27 == V_458 ) {
struct V_18 * V_423 = V_19 -> V_424 ;
if ( F_167 ( & V_423 -> V_47 ) ) {
if ( V_423 -> V_27 == V_489 &&
! F_193 ( V_423 ) ) {
F_50 ( V_12 , V_19 ) ;
F_139 ( V_12 , V_19 ) ;
F_179 ( V_12 ) ;
}
F_30 ( & V_423 -> V_47 ) ;
}
} else if ( V_19 -> V_27 == V_489 &&
! F_193 ( V_19 ) ) {
F_50 ( V_12 , V_19 ) ;
F_139 ( V_12 , V_19 ) ;
F_179 ( V_12 ) ;
} else if ( V_19 -> V_27 == V_28 ) {
F_165 ( & V_19 -> V_164 ) ;
}
}
while ( V_12 -> V_16 . V_30 == V_153 &&
! F_164 ( V_498 ) ) {
if ( V_19 -> V_27 == V_430 && V_19 -> V_26 == NULL )
F_151 ( V_19 ) ;
if ( V_19 -> V_27 != V_121 ) {
F_184 ( V_19 , V_12 , V_495 ) ;
continue;
}
F_159 (v, vn, &vc->runnable_threads,
arch.run_list) {
F_131 ( V_75 ) ;
if ( F_164 ( V_75 -> V_16 . V_456 ) ) {
F_135 ( V_19 , V_75 ) ;
V_75 -> V_14 . V_499 ++ ;
V_75 -> V_16 . V_183 -> V_188 = V_500 ;
V_75 -> V_16 . V_76 = - V_457 ;
F_165 ( & V_75 -> V_16 . V_398 ) ;
}
}
if ( ! V_19 -> V_411 || V_12 -> V_16 . V_30 != V_153 )
break;
V_496 = 0 ;
F_178 (v, &vc->runnable_threads, arch.run_list) {
if ( ! V_75 -> V_16 . V_461 )
V_496 += V_75 -> V_16 . V_163 ;
else
V_75 -> V_16 . V_163 = 0 ;
}
V_19 -> V_26 = V_12 ;
if ( V_496 == V_19 -> V_411 ) {
F_189 ( V_19 ) ;
} else if ( F_194 () ) {
F_148 ( V_19 ) ;
F_195 ( & V_19 -> V_47 ) ;
if ( V_19 -> V_27 == V_430 )
F_151 ( V_19 ) ;
} else {
F_173 ( V_19 ) ;
}
V_19 -> V_26 = NULL ;
}
while ( V_12 -> V_16 . V_30 == V_153 &&
( V_19 -> V_27 == V_489 ||
V_19 -> V_27 == V_490 ||
V_19 -> V_27 == V_458 ) )
F_184 ( V_19 , V_12 , V_501 ) ;
if ( V_19 -> V_27 == V_430 && V_19 -> V_26 == NULL )
F_151 ( V_19 ) ;
if ( V_12 -> V_16 . V_30 == V_153 ) {
F_135 ( V_19 , V_12 ) ;
V_12 -> V_14 . V_499 ++ ;
V_183 -> V_188 = V_500 ;
V_12 -> V_16 . V_76 = - V_457 ;
}
if ( V_19 -> V_411 && V_19 -> V_27 == V_121 ) {
V_75 = F_158 ( & V_19 -> V_350 ,
struct V_11 , V_16 . V_412 ) ;
F_165 ( & V_75 -> V_16 . V_398 ) ;
}
F_196 ( V_12 , V_183 ) ;
F_30 ( & V_19 -> V_47 ) ;
return V_12 -> V_16 . V_76 ;
}
static int F_197 ( struct V_183 * V_184 , struct V_11 * V_12 )
{
int V_48 ;
int V_462 ;
if ( ! V_12 -> V_16 . V_502 ) {
V_184 -> V_188 = V_503 ;
return - V_46 ;
}
F_131 ( V_12 ) ;
if ( F_164 ( V_498 ) ) {
V_184 -> V_188 = V_500 ;
return - V_457 ;
}
F_198 ( & V_12 -> V_71 -> V_16 . V_504 ) ;
F_8 () ;
if ( ! V_12 -> V_71 -> V_16 . V_505 ) {
V_48 = F_199 ( V_12 ) ;
if ( V_48 )
goto V_386;
}
F_200 ( V_498 ) ;
F_201 ( V_498 ) ;
F_202 ( V_498 ) ;
V_12 -> V_16 . V_13 = & V_12 -> V_16 . V_25 -> V_164 ;
V_12 -> V_16 . V_506 = V_498 -> V_507 -> V_508 ;
V_12 -> V_16 . V_30 = V_31 ;
do {
V_48 = F_191 ( V_184 , V_12 ) ;
if ( V_184 -> V_188 == V_211 &&
! ( V_12 -> V_16 . V_36 . V_34 & V_509 ) ) {
F_203 ( V_12 ) ;
V_48 = F_62 ( V_12 ) ;
F_204 ( V_12 , V_48 ) ;
F_131 ( V_12 ) ;
} else if ( V_48 == V_213 ) {
V_462 = F_65 ( & V_12 -> V_71 -> V_169 ) ;
V_48 = F_205 ( V_184 , V_12 ,
V_12 -> V_16 . V_64 , V_12 -> V_16 . V_65 ) ;
F_67 ( & V_12 -> V_71 -> V_169 , V_462 ) ;
}
} while ( F_172 ( V_48 ) );
V_386:
V_12 -> V_16 . V_30 = V_397 ;
F_206 ( & V_12 -> V_71 -> V_16 . V_504 ) ;
return V_48 ;
}
static void F_207 ( struct V_510 * * V_511 ,
int V_512 )
{
struct V_513 * V_514 = & V_515 [ V_512 ] ;
if ( ! V_514 -> V_516 )
return;
( * V_511 ) -> V_517 = V_514 -> V_516 ;
( * V_511 ) -> V_518 = V_514 -> V_519 ;
( * V_511 ) -> V_520 [ 0 ] . V_517 = V_514 -> V_516 ;
( * V_511 ) -> V_520 [ 0 ] . V_521 = V_514 -> V_522 [ V_512 ] ;
if ( V_512 != V_523 && V_514 -> V_522 [ V_523 ] != - 1 ) {
( * V_511 ) -> V_520 [ 1 ] . V_517 = 24 ;
( * V_511 ) -> V_520 [ 1 ] . V_521 = V_514 -> V_522 [ V_523 ] ;
}
( * V_511 ) ++ ;
}
static int F_208 ( struct V_71 * V_71 ,
struct V_524 * V_525 )
{
struct V_510 * V_511 ;
V_525 -> V_20 = V_526 ;
if ( F_209 ( V_527 ) )
V_525 -> V_20 |= V_528 ;
V_525 -> V_529 = V_530 ;
V_511 = & V_525 -> V_511 [ 0 ] ;
F_207 ( & V_511 , V_531 ) ;
F_207 ( & V_511 , V_532 ) ;
F_207 ( & V_511 , V_523 ) ;
return 0 ;
}
static int F_210 ( struct V_71 * V_71 ,
struct V_533 * log )
{
struct V_534 * V_535 ;
struct V_536 * V_537 ;
int V_48 ;
unsigned long V_367 ;
F_35 ( & V_71 -> V_538 ) ;
V_48 = - V_46 ;
if ( log -> V_539 >= V_540 )
goto V_386;
V_535 = V_534 ( V_71 ) ;
V_537 = F_211 ( V_535 , log -> V_539 ) ;
V_48 = - V_170 ;
if ( ! V_537 -> V_541 )
goto V_386;
V_367 = F_212 ( V_537 ) ;
memset ( V_537 -> V_541 , 0 , V_367 ) ;
V_48 = F_213 ( V_71 , V_537 , V_537 -> V_541 ) ;
if ( V_48 )
goto V_386;
V_48 = - V_380 ;
if ( F_108 ( log -> V_541 , V_537 -> V_541 , V_367 ) )
goto V_386;
V_48 = 0 ;
V_386:
F_37 ( & V_71 -> V_538 ) ;
return V_48 ;
}
static void F_214 ( struct V_536 * free ,
struct V_536 * V_542 )
{
if ( ! V_542 || free -> V_16 . V_543 != V_542 -> V_16 . V_543 ) {
F_215 ( free -> V_16 . V_543 ) ;
free -> V_16 . V_543 = NULL ;
}
}
static int F_216 ( struct V_536 * V_539 ,
unsigned long V_544 )
{
V_539 -> V_16 . V_543 = F_217 ( V_544 * sizeof( * V_539 -> V_16 . V_543 ) ) ;
if ( ! V_539 -> V_16 . V_543 )
return - V_358 ;
return 0 ;
}
static int F_218 ( struct V_71 * V_71 ,
struct V_536 * V_537 ,
const struct V_545 * V_546 )
{
return 0 ;
}
static void F_219 ( struct V_71 * V_71 ,
const struct V_545 * V_546 ,
const struct V_536 * V_547 ,
const struct V_536 * V_548 )
{
unsigned long V_544 = V_546 -> V_549 >> V_550 ;
struct V_534 * V_535 ;
struct V_536 * V_537 ;
if ( V_544 && V_547 -> V_544 ) {
V_535 = V_534 ( V_71 ) ;
V_537 = F_211 ( V_535 , V_546 -> V_539 ) ;
F_213 ( V_71 , V_537 , NULL ) ;
}
}
void F_220 ( struct V_71 * V_71 , unsigned long V_70 , unsigned long V_236 )
{
long int V_208 ;
T_3 V_551 = 0 ;
if ( ( V_71 -> V_16 . V_70 & V_236 ) == V_70 )
return;
V_71 -> V_16 . V_70 = ( V_71 -> V_16 . V_70 & ~ V_236 ) | V_70 ;
for ( V_208 = 0 ; V_208 < V_385 ; ++ V_208 ) {
struct V_18 * V_19 = V_71 -> V_16 . V_399 [ V_208 ] ;
if ( ! V_19 )
continue;
F_29 ( & V_19 -> V_47 ) ;
V_19 -> V_70 = ( V_19 -> V_70 & ~ V_236 ) | V_70 ;
F_30 ( & V_19 -> V_47 ) ;
if ( ++ V_551 >= V_71 -> V_16 . V_400 )
break;
}
}
static void F_221 ( struct V_11 * V_12 )
{
return;
}
static int F_199 ( struct V_11 * V_12 )
{
int V_95 = 0 ;
struct V_71 * V_71 = V_12 -> V_71 ;
unsigned long V_552 ;
struct V_536 * V_537 ;
struct V_553 * V_554 ;
unsigned long V_70 = 0 , V_555 ;
unsigned long V_556 , V_557 ;
int V_462 ;
F_35 ( & V_71 -> V_47 ) ;
if ( V_71 -> V_16 . V_505 )
goto V_386;
if ( ! V_71 -> V_16 . V_558 ) {
V_95 = F_222 ( V_71 , NULL ) ;
if ( V_95 ) {
F_32 ( L_21 ) ;
goto V_386;
}
}
V_462 = F_65 ( & V_71 -> V_169 ) ;
V_537 = F_223 ( V_71 , 0 ) ;
V_95 = - V_46 ;
if ( ! V_537 || ( V_537 -> V_20 & V_559 ) )
goto V_560;
V_552 = V_537 -> V_561 ;
F_224 ( & V_498 -> V_507 -> V_562 ) ;
V_554 = F_225 ( V_498 -> V_507 , V_552 ) ;
if ( ! V_554 || V_554 -> V_563 > V_552 || ( V_554 -> V_564 & V_565 ) )
goto V_566;
V_556 = F_226 ( V_554 ) ;
V_557 = F_227 ( V_556 ) ;
F_228 ( & V_498 -> V_507 -> V_562 ) ;
V_95 = - V_46 ;
if ( ! ( V_556 == 0x1000 || V_556 == 0x10000 ||
V_556 == 0x1000000 ) )
goto V_560;
V_555 = F_229 ( V_556 ) ;
V_71 -> V_16 . V_567 = V_555 | V_568 |
( V_569 << V_570 ) ;
V_70 = V_555 << ( V_571 - 4 ) ;
F_230 ( V_12 , V_537 , V_557 ) ;
F_220 ( V_71 , V_70 , V_572 ) ;
F_56 () ;
V_71 -> V_16 . V_505 = 1 ;
V_95 = 0 ;
V_560:
F_67 ( & V_71 -> V_169 , V_462 ) ;
V_386:
F_37 ( & V_71 -> V_47 ) ;
return V_95 ;
V_566:
F_228 ( & V_498 -> V_507 -> V_562 ) ;
goto V_560;
}
static int F_231 ( struct V_71 * V_71 )
{
unsigned long V_70 , V_573 ;
char V_360 [ 32 ] ;
V_573 = F_232 () ;
if ( ( long ) V_573 < 0 )
return - V_358 ;
V_71 -> V_16 . V_573 = V_573 ;
F_233 ( & V_71 -> V_16 . V_574 ) ;
memcpy ( V_71 -> V_16 . V_158 , V_575 ,
sizeof( V_71 -> V_16 . V_158 ) ) ;
V_71 -> V_16 . V_576 = F_119 ( V_577 ) ;
V_71 -> V_16 . V_578 = F_119 ( V_579 ) ;
V_71 -> V_16 . V_580 = V_70 = F_119 ( V_581 ) ;
V_70 &= V_582 | V_583 ;
V_70 |= ( 4UL << V_584 ) | V_585 |
V_586 | V_587 ;
V_71 -> V_16 . V_567 = V_568 |
( V_569 << V_570 ) ;
if ( F_2 ( V_2 ) )
V_70 |= V_588 ;
V_71 -> V_16 . V_70 = V_70 ;
F_234 () ;
snprintf ( V_360 , sizeof( V_360 ) , L_22 , V_498 -> V_292 ) ;
V_71 -> V_16 . V_382 = F_112 ( V_360 , V_589 ) ;
if ( ! F_111 ( V_71 -> V_16 . V_382 ) )
F_235 ( V_71 ) ;
return 0 ;
}
static void F_236 ( struct V_71 * V_71 )
{
long int V_208 ;
for ( V_208 = 0 ; V_208 < V_385 ; ++ V_208 )
F_103 ( V_71 -> V_16 . V_399 [ V_208 ] ) ;
V_71 -> V_16 . V_400 = 0 ;
}
static void F_237 ( struct V_71 * V_71 )
{
F_238 ( V_71 -> V_16 . V_382 ) ;
F_239 () ;
F_236 ( V_71 ) ;
F_240 ( V_71 ) ;
}
static int F_241 ( struct V_183 * V_184 , struct V_11 * V_12 ,
unsigned int V_590 , int * V_591 )
{
return V_592 ;
}
static int F_242 ( struct V_11 * V_12 , int V_593 ,
T_4 V_594 )
{
return V_592 ;
}
static int F_243 ( struct V_11 * V_12 , int V_593 ,
T_4 * V_594 )
{
return V_592 ;
}
static int F_244 ( void )
{
if ( ! F_2 ( V_595 ) ||
! F_2 ( V_596 ) )
return - V_597 ;
return 0 ;
}
static long F_245 ( struct V_355 * V_598 ,
unsigned int V_599 , unsigned long V_600 )
{
struct V_71 * V_71 V_601 = V_598 -> V_359 ;
void T_6 * V_602 = ( void T_6 * ) V_600 ;
long V_48 ;
switch ( V_599 ) {
case V_603 : {
T_3 V_604 ;
V_48 = - V_380 ;
if ( F_246 ( V_604 , ( T_3 T_6 * ) V_602 ) )
break;
V_48 = F_247 ( V_71 , & V_604 ) ;
if ( V_48 )
break;
V_48 = - V_380 ;
if ( F_248 ( V_604 , ( T_3 T_6 * ) V_602 ) )
break;
V_48 = 0 ;
break;
}
case V_605 : {
struct V_606 V_607 ;
V_48 = - V_380 ;
if ( F_249 ( & V_607 , V_602 , sizeof( V_607 ) ) )
break;
V_48 = F_250 ( V_71 , & V_607 ) ;
break;
}
default:
V_48 = - V_608 ;
}
return V_48 ;
}
static void F_251 ( void )
{
int V_208 ;
unsigned int V_609 ;
for ( V_208 = 0 ; V_610 [ V_208 ] ; ++ V_208 ) {
V_609 = V_610 [ V_208 ] ;
F_252 ( ! F_73 ( V_609 ) ) ;
F_253 ( V_609 / 4 , V_575 ) ;
}
}
static int F_254 ( void )
{
int V_48 ;
V_48 = F_244 () ;
if ( V_48 < 0 )
return - V_611 ;
V_612 . V_613 = V_614 ;
V_615 = & V_612 ;
F_251 () ;
F_145 () ;
V_48 = F_255 () ;
return V_48 ;
}
static void F_256 ( void )
{
V_615 = NULL ;
}
