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
struct V_11 * V_75 ;
F_35 ( & V_71 -> V_47 ) ;
V_75 = F_36 ( V_71 , V_74 ) ;
F_37 ( & V_71 -> V_47 ) ;
return V_75 ;
}
static void F_38 ( struct V_11 * V_12 , struct V_76 * V_77 )
{
V_77 -> V_78 |= V_79 ;
V_77 -> V_80 = F_39 ( 1 ) ;
}
static int F_40 ( struct V_11 * V_12 , struct V_81 * V_82 ,
unsigned long V_83 , unsigned long V_84 )
{
if ( V_83 & ( V_85 - 1 ) )
return - V_46 ;
F_29 ( & V_12 -> V_16 . V_86 ) ;
if ( V_82 -> V_87 != V_83 || V_82 -> V_84 != V_84 ) {
V_82 -> V_87 = V_83 ;
V_82 -> V_84 = V_83 ? V_84 : 0 ;
V_82 -> V_88 = 1 ;
}
F_30 ( & V_12 -> V_16 . V_86 ) ;
return 0 ;
}
static int F_41 ( struct V_81 * V_89 )
{
if ( V_89 -> V_88 )
return V_89 -> V_87 != 0 ;
return V_89 -> V_90 != NULL ;
}
static unsigned long F_42 ( struct V_11 * V_12 ,
unsigned long V_20 ,
unsigned long V_91 , unsigned long V_77 )
{
struct V_71 * V_71 = V_12 -> V_71 ;
unsigned long V_84 , V_92 ;
void * V_93 ;
struct V_11 * V_94 ;
int V_95 ;
int V_96 ;
struct V_81 * V_89 ;
V_94 = F_34 ( V_71 , V_91 ) ;
if ( ! V_94 )
return V_97 ;
V_96 = ( V_20 >> V_98 ) & V_99 ;
if ( V_96 == V_100 || V_96 == V_101 ||
V_96 == V_102 ) {
if ( ( V_77 & ( V_85 - 1 ) ) || ! V_77 )
return V_97 ;
V_93 = F_43 ( V_71 , V_77 , & V_92 ) ;
if ( V_93 == NULL )
return V_97 ;
if ( V_96 == V_100 )
V_84 = F_44 ( ( (struct V_103 * ) V_93 ) -> V_104 . V_105 ) ;
else
V_84 = F_45 ( ( (struct V_103 * ) V_93 ) -> V_104 . V_106 ) ;
F_46 ( V_71 , V_93 , V_77 , false ) ;
if ( V_84 > V_92 || V_84 < sizeof( struct V_103 ) )
return V_97 ;
} else {
V_77 = 0 ;
V_84 = 0 ;
}
V_95 = V_97 ;
V_89 = NULL ;
F_29 ( & V_94 -> V_16 . V_86 ) ;
switch ( V_96 ) {
case V_100 :
if ( V_84 < sizeof( struct V_76 ) )
break;
V_89 = & V_94 -> V_16 . V_77 ;
V_95 = 0 ;
break;
case V_101 :
if ( V_84 < sizeof( struct V_107 ) )
break;
V_84 -= V_84 % sizeof( struct V_107 ) ;
V_95 = V_108 ;
if ( ! F_41 ( & V_94 -> V_16 . V_77 ) )
break;
V_89 = & V_94 -> V_16 . V_109 ;
V_95 = 0 ;
break;
case V_102 :
V_95 = V_108 ;
if ( ! F_41 ( & V_94 -> V_16 . V_77 ) )
break;
V_89 = & V_94 -> V_16 . V_110 ;
V_95 = 0 ;
break;
case V_111 :
V_95 = V_108 ;
if ( F_41 ( & V_94 -> V_16 . V_109 ) ||
F_41 ( & V_94 -> V_16 . V_110 ) )
break;
V_89 = & V_94 -> V_16 . V_77 ;
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
V_89 -> V_87 = V_77 ;
V_89 -> V_84 = V_84 ;
V_89 -> V_88 = 1 ;
}
F_30 ( & V_94 -> V_16 . V_86 ) ;
return V_95 ;
}
static void F_47 ( struct V_11 * V_12 , struct V_81 * V_89 )
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
if ( ! ( V_12 -> V_16 . V_77 . V_88 ||
V_12 -> V_16 . V_110 . V_88 ||
V_12 -> V_16 . V_109 . V_88 ) )
return;
F_29 ( & V_12 -> V_16 . V_86 ) ;
if ( V_12 -> V_16 . V_77 . V_88 ) {
F_47 ( V_12 , & V_12 -> V_16 . V_77 ) ;
if ( V_12 -> V_16 . V_77 . V_90 )
F_38 ( V_12 , V_12 -> V_16 . V_77 . V_90 ) ;
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
struct V_76 * V_77 ;
unsigned long V_123 ;
unsigned long V_124 ;
T_2 V_119 ;
V_122 = V_12 -> V_16 . V_117 ;
V_77 = V_12 -> V_16 . V_77 . V_90 ;
V_119 = F_20 () ;
V_124 = F_49 ( V_19 , V_119 ) ;
V_123 = V_124 - V_12 -> V_16 . V_125 ;
V_12 -> V_16 . V_125 = V_124 ;
F_51 ( & V_12 -> V_16 . V_29 ) ;
V_123 += V_12 -> V_16 . V_33 ;
V_12 -> V_16 . V_33 = 0 ;
F_52 ( & V_12 -> V_16 . V_29 ) ;
if ( ! V_122 || ! V_77 )
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
V_77 -> V_133 = F_54 ( ++ V_12 -> V_16 . V_118 ) ;
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
int V_80 = 0 ;
struct V_76 * V_76 ;
F_29 ( & V_12 -> V_16 . V_86 ) ;
V_76 = (struct V_76 * ) V_12 -> V_16 . V_77 . V_90 ;
if ( V_76 )
V_80 = F_45 ( V_76 -> V_80 ) ;
F_30 ( & V_12 -> V_16 . V_86 ) ;
return V_80 ;
}
int F_62 ( struct V_11 * V_12 )
{
unsigned long V_154 = F_33 ( V_12 , 3 ) ;
unsigned long V_152 , V_75 = V_146 ;
int V_80 ;
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
V_75 = V_97 ;
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
V_75 = V_97 ;
break;
}
V_80 = F_33 ( V_12 , 5 ) ;
if ( F_61 ( V_94 ) != V_80 )
break;
F_59 ( V_94 ) ;
break;
case V_166 :
V_75 = F_42 ( V_12 , F_33 ( V_12 , 4 ) ,
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
V_75 = F_68 ( V_12 ) ;
if ( V_75 == V_151 )
return V_159 ;
break;
case V_172 :
V_75 = F_69 ( V_12 ) ;
if ( V_75 == V_151 )
return V_159 ;
break;
case V_173 :
V_75 = F_58 ( V_12 , F_33 ( V_12 , 4 ) ,
F_33 ( V_12 , 5 ) ,
F_33 ( V_12 , 6 ) ,
F_33 ( V_12 , 7 ) ) ;
if ( V_75 == V_151 )
return V_159 ;
break;
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
if ( F_70 ( V_12 ) ) {
V_75 = F_71 ( V_12 , V_154 ) ;
break;
}
default:
return V_159 ;
}
F_72 ( V_12 , 3 , V_75 ) ;
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
if ( V_12 -> V_16 . V_36 . V_34 & V_196 ) {
F_80 ( V_197 L_14 ) ;
F_80 ( V_197 L_15 ,
V_12 -> V_16 . V_51 , F_55 ( V_12 ) ,
V_12 -> V_16 . V_36 . V_34 ) ;
F_31 ( V_12 ) ;
V_184 -> V_188 = V_198 ;
V_184 -> V_199 . V_200 = V_12 -> V_16 . V_51 ;
return V_159 ;
}
V_184 -> V_188 = V_201 ;
V_184 -> V_202 = 1 ;
switch ( V_12 -> V_16 . V_51 ) {
case V_203 :
V_12 -> V_14 . V_204 ++ ;
V_48 = V_181 ;
break;
case V_205 :
case V_206 :
V_12 -> V_14 . V_207 ++ ;
V_48 = V_181 ;
break;
case V_208 :
case V_209 :
V_48 = V_181 ;
break;
case V_210 :
F_81 ( V_12 ,
V_210 ) ;
V_48 = V_181 ;
break;
case V_211 :
{
T_4 V_20 ;
V_20 = V_12 -> V_16 . V_36 . V_34 & 0x1f0000ull ;
F_78 ( V_12 , V_20 ) ;
V_48 = V_181 ;
break;
}
case V_212 :
{
int V_213 ;
V_184 -> V_214 . V_215 = F_33 ( V_12 , 3 ) ;
for ( V_213 = 0 ; V_213 < 9 ; ++ V_213 )
V_184 -> V_214 . args [ V_213 ] = F_33 ( V_12 , 4 + V_213 ) ;
V_184 -> V_188 = V_216 ;
V_12 -> V_16 . V_180 = 1 ;
V_48 = V_159 ;
break;
}
case V_217 :
V_48 = V_218 ;
break;
case V_219 :
V_12 -> V_16 . V_64 = F_55 ( V_12 ) ;
V_12 -> V_16 . V_65 = 0 ;
V_48 = V_218 ;
break;
case V_220 :
if ( V_12 -> V_16 . V_221 != V_222 )
V_12 -> V_16 . V_73 = F_82 ( V_12 ) ?
F_83 ( V_12 -> V_16 . V_221 ) :
V_12 -> V_16 . V_221 ;
if ( V_12 -> V_223 & V_224 ) {
V_48 = F_76 ( V_184 , V_12 ) ;
} else {
F_78 ( V_12 , V_192 ) ;
V_48 = V_181 ;
}
break;
case V_225 :
F_78 ( V_12 , V_192 ) ;
V_48 = V_181 ;
break;
default:
F_31 ( V_12 ) ;
F_80 ( V_197 L_15 ,
V_12 -> V_16 . V_51 , F_55 ( V_12 ) ,
V_12 -> V_16 . V_36 . V_34 ) ;
V_184 -> V_199 . V_200 = V_12 -> V_16 . V_51 ;
V_48 = V_159 ;
break;
}
return V_48 ;
}
static int F_84 ( struct V_11 * V_12 ,
struct V_226 * V_227 )
{
int V_213 ;
memset ( V_227 , 0 , sizeof( struct V_226 ) ) ;
V_227 -> V_37 = V_12 -> V_16 . V_37 ;
for ( V_213 = 0 ; V_213 < V_12 -> V_16 . V_66 ; V_213 ++ ) {
V_227 -> V_228 . V_229 . V_230 . V_67 [ V_213 ] . V_231 = V_12 -> V_16 . V_67 [ V_213 ] . V_68 ;
V_227 -> V_228 . V_229 . V_230 . V_67 [ V_213 ] . V_232 = V_12 -> V_16 . V_67 [ V_213 ] . V_69 ;
}
return 0 ;
}
static int F_85 ( struct V_11 * V_12 ,
struct V_226 * V_227 )
{
int V_213 , V_233 ;
if ( V_227 -> V_37 != V_12 -> V_16 . V_37 )
return - V_46 ;
V_233 = 0 ;
for ( V_213 = 0 ; V_213 < V_12 -> V_16 . V_234 ; V_213 ++ ) {
if ( V_227 -> V_228 . V_229 . V_230 . V_67 [ V_213 ] . V_231 & V_235 ) {
V_12 -> V_16 . V_67 [ V_233 ] . V_68 = V_227 -> V_228 . V_229 . V_230 . V_67 [ V_213 ] . V_231 ;
V_12 -> V_16 . V_67 [ V_233 ] . V_69 = V_227 -> V_228 . V_229 . V_230 . V_67 [ V_213 ] . V_232 ;
++ V_233 ;
}
}
V_12 -> V_16 . V_66 = V_233 ;
return 0 ;
}
static void F_86 ( struct V_11 * V_12 , T_2 V_236 ,
bool V_237 )
{
struct V_71 * V_71 = V_12 -> V_71 ;
struct V_18 * V_19 = V_12 -> V_16 . V_25 ;
T_2 V_238 ;
F_35 ( & V_71 -> V_47 ) ;
F_29 ( & V_19 -> V_47 ) ;
if ( ( V_236 & V_239 ) != ( V_19 -> V_70 & V_239 ) ) {
struct V_11 * V_12 ;
int V_213 ;
F_87 (i, vcpu, kvm) {
if ( V_12 -> V_16 . V_25 != V_19 )
continue;
if ( V_236 & V_239 )
V_12 -> V_16 . V_240 |= V_241 ;
else
V_12 -> V_16 . V_240 &= ~ V_241 ;
}
}
V_238 = V_242 | V_239 | V_243 ;
if ( F_2 ( V_2 ) )
V_238 |= V_244 ;
if ( V_237 )
V_238 &= 0xFFFFFFFF ;
V_19 -> V_70 = ( V_19 -> V_70 & ~ V_238 ) | ( V_236 & V_238 ) ;
F_30 ( & V_19 -> V_47 ) ;
F_37 ( & V_71 -> V_47 ) ;
}
static int F_88 ( struct V_11 * V_12 , T_2 V_74 ,
union V_245 * V_246 )
{
int V_48 = 0 ;
long int V_213 ;
switch ( V_74 ) {
case V_247 :
* V_246 = F_89 ( V_74 , V_187 ) ;
break;
case V_248 :
* V_246 = F_89 ( V_74 , 0 ) ;
break;
case V_249 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_250 ) ;
break;
case V_251 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_252 ) ;
break;
case V_253 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_254 ) ;
break;
case V_255 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_256 ) ;
break;
case V_257 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_258 ) ;
break;
case V_259 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_260 ) ;
break;
case V_261 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_262 ) ;
break;
case V_263 ... V_264 :
V_213 = V_74 - V_263 ;
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_265 [ V_213 ] ) ;
break;
case V_266 ... V_267 :
V_213 = V_74 - V_266 ;
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_268 [ V_213 ] ) ;
break;
case V_269 ... V_270 :
V_213 = V_74 - V_269 ;
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_271 [ V_213 ] ) ;
break;
case V_272 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_273 ) ;
break;
case V_274 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_275 ) ;
break;
case V_276 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_277 ) ;
break;
case V_278 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_279 ) ;
break;
case V_280 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_281 ) ;
break;
case V_282 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_25 -> V_283 ) ;
break;
case V_284 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_149 ) ;
break;
case V_285 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_150 ) ;
break;
case V_286 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_145 ) ;
break;
case V_287 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_288 ) ;
break;
case V_289 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_290 ) ;
break;
case V_291 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_292 ) ;
break;
case V_293 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_294 ) ;
break;
case V_295 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_296 ) ;
break;
case V_297 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_298 ) ;
break;
case V_299 :
F_29 ( & V_12 -> V_16 . V_86 ) ;
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_77 . V_87 ) ;
F_30 ( & V_12 -> V_16 . V_86 ) ;
break;
case V_300 :
F_29 ( & V_12 -> V_16 . V_86 ) ;
V_246 -> V_301 . V_83 = V_12 -> V_16 . V_110 . V_87 ;
V_246 -> V_301 . V_104 = V_12 -> V_16 . V_110 . V_84 ;
F_30 ( & V_12 -> V_16 . V_86 ) ;
break;
case V_302 :
F_29 ( & V_12 -> V_16 . V_86 ) ;
V_246 -> V_301 . V_83 = V_12 -> V_16 . V_109 . V_87 ;
V_246 -> V_301 . V_104 = V_12 -> V_16 . V_109 . V_84 ;
F_30 ( & V_12 -> V_16 . V_86 ) ;
break;
case V_303 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_25 -> V_131 ) ;
break;
case V_304 :
case V_305 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_25 -> V_70 ) ;
break;
case V_306 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_307 ) ;
break;
#ifdef F_90
case V_308 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_309 ) ;
break;
case V_310 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_311 ) ;
break;
case V_312 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_313 ) ;
break;
case V_314 ... V_315 :
V_213 = V_74 - V_314 ;
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_316 [ V_213 ] ) ;
break;
case V_317 ... V_318 :
{
int V_233 ;
V_213 = V_74 - V_317 ;
if ( V_213 < 32 )
for ( V_233 = 0 ; V_233 < V_319 ; V_233 ++ )
V_246 -> V_320 [ V_233 ] = V_12 -> V_16 . V_321 . V_322 [ V_213 ] [ V_233 ] ;
else {
if ( F_2 ( V_323 ) )
V_246 -> V_324 = V_12 -> V_16 . V_325 . V_326 [ V_213 - 32 ] ;
else
V_48 = - V_327 ;
}
break;
}
case V_328 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_329 ) ;
break;
case V_330 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_331 ) ;
break;
case V_332 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_333 ) ;
break;
case V_334 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_321 . V_335 ) ;
break;
case V_336 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_337 ) ;
break;
case V_338 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_339 ) ;
break;
case V_340 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_341 ) ;
break;
case V_342 :
if ( F_2 ( V_323 ) )
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_325 . V_343 . V_228 [ 3 ] ) ;
else
V_48 = - V_327 ;
break;
case V_344 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_345 ) ;
break;
case V_346 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_347 ) ;
break;
#endif
case V_348 :
* V_246 = F_89 ( V_74 , V_12 -> V_16 . V_25 -> V_38 ) ;
break;
default:
V_48 = - V_46 ;
break;
}
return V_48 ;
}
static int F_91 ( struct V_11 * V_12 , T_2 V_74 ,
union V_245 * V_246 )
{
int V_48 = 0 ;
long int V_213 ;
unsigned long V_83 , V_84 ;
switch ( V_74 ) {
case V_248 :
if ( F_92 ( V_74 , * V_246 ) )
V_48 = - V_46 ;
break;
case V_249 :
V_12 -> V_16 . V_250 = F_92 ( V_74 , * V_246 ) ;
break;
case V_251 :
V_12 -> V_16 . V_252 = F_92 ( V_74 , * V_246 ) & ~ V_148 ;
break;
case V_253 :
V_12 -> V_16 . V_254 = F_92 ( V_74 , * V_246 ) ;
break;
case V_255 :
V_12 -> V_16 . V_256 = F_92 ( V_74 , * V_246 ) ;
break;
case V_257 :
V_12 -> V_16 . V_258 = F_92 ( V_74 , * V_246 ) ;
break;
case V_259 :
V_12 -> V_16 . V_260 = F_92 ( V_74 , * V_246 ) ;
break;
case V_261 :
V_12 -> V_16 . V_262 = F_92 ( V_74 , * V_246 ) ;
break;
case V_263 ... V_264 :
V_213 = V_74 - V_263 ;
V_12 -> V_16 . V_265 [ V_213 ] = F_92 ( V_74 , * V_246 ) ;
break;
case V_266 ... V_267 :
V_213 = V_74 - V_266 ;
V_12 -> V_16 . V_268 [ V_213 ] = F_92 ( V_74 , * V_246 ) ;
break;
case V_269 ... V_270 :
V_213 = V_74 - V_269 ;
V_12 -> V_16 . V_271 [ V_213 ] = F_92 ( V_74 , * V_246 ) ;
break;
case V_272 :
V_12 -> V_16 . V_273 = F_92 ( V_74 , * V_246 ) ;
break;
case V_274 :
V_12 -> V_16 . V_275 = F_92 ( V_74 , * V_246 ) ;
break;
case V_276 :
V_12 -> V_16 . V_277 = F_92 ( V_74 , * V_246 ) ;
break;
case V_278 :
V_12 -> V_16 . V_279 = F_92 ( V_74 , * V_246 ) ;
break;
case V_280 :
V_12 -> V_16 . V_281 = F_92 ( V_74 , * V_246 ) ;
break;
case V_282 :
V_12 -> V_16 . V_25 -> V_283 = F_92 ( V_74 , * V_246 ) ;
break;
case V_284 :
V_12 -> V_16 . V_149 = F_92 ( V_74 , * V_246 ) ;
break;
case V_285 :
V_12 -> V_16 . V_150 = F_92 ( V_74 , * V_246 ) & ~ V_349 ;
break;
case V_286 :
V_12 -> V_16 . V_145 = F_92 ( V_74 , * V_246 ) ;
if ( ( V_12 -> V_16 . V_145 & V_142 ) == V_143 )
V_12 -> V_16 . V_145 &= ~ V_142 ;
break;
case V_287 :
V_12 -> V_16 . V_288 = F_92 ( V_74 , * V_246 ) ;
break;
case V_289 :
V_12 -> V_16 . V_290 = F_92 ( V_74 , * V_246 ) ;
break;
case V_291 :
V_12 -> V_16 . V_292 = F_92 ( V_74 , * V_246 ) ;
break;
case V_293 :
V_12 -> V_16 . V_294 = F_92 ( V_74 , * V_246 ) ;
break;
case V_295 :
V_12 -> V_16 . V_296 = F_92 ( V_74 , * V_246 ) ;
break;
case V_297 :
V_12 -> V_16 . V_298 = F_92 ( V_74 , * V_246 ) ;
break;
case V_299 :
V_83 = F_92 ( V_74 , * V_246 ) ;
V_48 = - V_46 ;
if ( ! V_83 && ( V_12 -> V_16 . V_110 . V_87 ||
V_12 -> V_16 . V_109 . V_87 ) )
break;
V_48 = F_40 ( V_12 , & V_12 -> V_16 . V_77 , V_83 , sizeof( struct V_76 ) ) ;
break;
case V_300 :
V_83 = V_246 -> V_301 . V_83 ;
V_84 = V_246 -> V_301 . V_104 ;
V_48 = - V_46 ;
if ( V_83 && ! V_12 -> V_16 . V_77 . V_87 )
break;
V_48 = F_40 ( V_12 , & V_12 -> V_16 . V_110 , V_83 , V_84 ) ;
break;
case V_302 :
V_83 = V_246 -> V_301 . V_83 ;
V_84 = V_246 -> V_301 . V_104 ;
V_48 = - V_46 ;
if ( V_83 && ( V_84 < sizeof( struct V_107 ) ||
! V_12 -> V_16 . V_77 . V_87 ) )
break;
V_84 -= V_84 % sizeof( struct V_107 ) ;
V_48 = F_40 ( V_12 , & V_12 -> V_16 . V_109 , V_83 , V_84 ) ;
break;
case V_303 :
V_12 -> V_16 . V_25 -> V_131 =
F_93 ( F_92 ( V_74 , * V_246 ) , 1UL << 24 ) ;
break;
case V_304 :
F_86 ( V_12 , F_92 ( V_74 , * V_246 ) , true ) ;
break;
case V_305 :
F_86 ( V_12 , F_92 ( V_74 , * V_246 ) , false ) ;
break;
case V_306 :
V_12 -> V_16 . V_307 = F_92 ( V_74 , * V_246 ) ;
break;
#ifdef F_90
case V_308 :
V_12 -> V_16 . V_309 = F_92 ( V_74 , * V_246 ) ;
break;
case V_310 :
V_12 -> V_16 . V_311 = F_92 ( V_74 , * V_246 ) ;
break;
case V_312 :
V_12 -> V_16 . V_313 = F_92 ( V_74 , * V_246 ) ;
break;
case V_314 ... V_315 :
V_213 = V_74 - V_314 ;
V_12 -> V_16 . V_316 [ V_213 ] = F_92 ( V_74 , * V_246 ) ;
break;
case V_317 ... V_318 :
{
int V_233 ;
V_213 = V_74 - V_317 ;
if ( V_213 < 32 )
for ( V_233 = 0 ; V_233 < V_319 ; V_233 ++ )
V_12 -> V_16 . V_321 . V_322 [ V_213 ] [ V_233 ] = V_246 -> V_320 [ V_233 ] ;
else
if ( F_2 ( V_323 ) )
V_12 -> V_16 . V_325 . V_326 [ V_213 - 32 ] = V_246 -> V_324 ;
else
V_48 = - V_327 ;
break;
}
case V_328 :
V_12 -> V_16 . V_329 = F_92 ( V_74 , * V_246 ) ;
break;
case V_330 :
V_12 -> V_16 . V_331 = F_92 ( V_74 , * V_246 ) ;
break;
case V_332 :
V_12 -> V_16 . V_333 = F_92 ( V_74 , * V_246 ) ;
break;
case V_334 :
V_12 -> V_16 . V_321 . V_335 = F_92 ( V_74 , * V_246 ) ;
break;
case V_336 :
V_12 -> V_16 . V_337 = F_92 ( V_74 , * V_246 ) ;
break;
case V_338 :
V_12 -> V_16 . V_339 = F_92 ( V_74 , * V_246 ) ;
break;
case V_340 :
V_12 -> V_16 . V_341 = F_92 ( V_74 , * V_246 ) ;
break;
case V_342 :
if ( F_2 ( V_323 ) )
V_12 -> V_16 . V_326 . V_343 . V_228 [ 3 ] = F_92 ( V_74 , * V_246 ) ;
else
V_48 = - V_327 ;
break;
case V_344 :
V_12 -> V_16 . V_345 = F_92 ( V_74 , * V_246 ) ;
break;
case V_346 :
V_12 -> V_16 . V_347 = F_92 ( V_74 , * V_246 ) ;
break;
#endif
case V_348 :
V_48 = F_28 ( V_12 , F_92 ( V_74 , * V_246 ) ) ;
break;
default:
V_48 = - V_46 ;
break;
}
return V_48 ;
}
static struct V_18 * F_94 ( struct V_71 * V_71 , int V_350 )
{
struct V_18 * V_25 ;
V_25 = F_95 ( sizeof( struct V_18 ) , V_351 ) ;
if ( V_25 == NULL )
return NULL ;
F_96 ( & V_25 -> V_352 ) ;
F_97 ( & V_25 -> V_47 ) ;
F_97 ( & V_25 -> V_21 ) ;
F_98 ( & V_25 -> V_164 ) ;
V_25 -> V_22 = V_23 ;
V_25 -> V_70 = V_71 -> V_16 . V_70 ;
V_25 -> V_353 = V_350 * V_354 ;
V_25 -> V_71 = V_71 ;
F_96 ( & V_25 -> V_355 ) ;
return V_25 ;
}
static int F_99 ( struct V_356 * V_356 , struct V_357 * V_357 )
{
struct V_11 * V_12 = V_356 -> V_358 ;
struct V_359 * V_120 ;
V_120 = F_95 ( sizeof( * V_120 ) , V_351 ) ;
if ( ! V_120 )
return - V_360 ;
F_100 ( V_12 -> V_71 ) ;
V_120 -> V_12 = V_12 ;
V_357 -> V_361 = V_120 ;
return F_101 ( V_356 , V_357 ) ;
}
static int F_102 ( struct V_356 * V_356 , struct V_357 * V_357 )
{
struct V_359 * V_120 = V_357 -> V_361 ;
F_103 ( V_120 -> V_12 -> V_71 ) ;
F_104 ( V_120 ) ;
return 0 ;
}
static T_5 F_105 ( struct V_357 * V_357 , char T_6 * V_362 ,
T_7 V_84 , T_8 * V_363 )
{
struct V_359 * V_120 = V_357 -> V_361 ;
struct V_11 * V_12 = V_120 -> V_12 ;
char * V_229 , * V_364 ;
struct V_365 V_366 ;
T_2 V_367 ;
T_8 V_368 ;
T_5 V_369 ;
int V_213 , V_370 ;
bool V_371 ;
if ( ! V_120 -> V_372 ) {
V_229 = V_120 -> V_362 ;
V_364 = V_229 + sizeof( V_120 -> V_362 ) ;
for ( V_213 = 0 ; V_213 < V_373 ; ++ V_213 ) {
struct V_365 * V_374 ;
V_374 = (struct V_365 * )
( ( unsigned long ) V_12 + V_375 [ V_213 ] . V_376 ) ;
V_371 = false ;
for ( V_370 = 0 ; V_370 < 1000 ; ++ V_370 ) {
V_367 = V_374 -> V_377 ;
if ( ! ( V_367 & 1 ) ) {
F_106 () ;
V_366 = * V_374 ;
F_106 () ;
if ( V_367 == V_374 -> V_377 ) {
V_371 = true ;
break;
}
}
F_107 ( 1 ) ;
}
if ( ! V_371 )
snprintf ( V_229 , V_364 - V_229 , L_16 ,
V_375 [ V_213 ] . V_378 ) ;
else
snprintf ( V_229 , V_364 - V_229 ,
L_17 ,
V_375 [ V_213 ] . V_378 , V_367 / 2 ,
F_108 ( V_366 . V_379 ) ,
F_108 ( V_366 . V_380 ) ,
F_108 ( V_366 . V_381 ) ) ;
V_229 += strlen ( V_229 ) ;
}
V_120 -> V_372 = V_229 - V_120 -> V_362 ;
}
V_368 = * V_363 ;
if ( V_368 >= V_120 -> V_372 )
return 0 ;
if ( V_84 > V_120 -> V_372 - V_368 )
V_84 = V_120 -> V_372 - V_368 ;
V_369 = F_109 ( V_362 , V_120 -> V_362 + V_368 , V_84 ) ;
if ( V_369 ) {
if ( V_369 == V_84 )
return - V_382 ;
V_84 -= V_369 ;
}
* V_363 = V_368 + V_84 ;
return V_84 ;
}
static T_5 F_110 ( struct V_357 * V_357 , const char T_6 * V_362 ,
T_7 V_84 , T_8 * V_363 )
{
return - V_383 ;
}
static void F_111 ( struct V_11 * V_12 , unsigned int V_74 )
{
char V_362 [ 16 ] ;
struct V_71 * V_71 = V_12 -> V_71 ;
snprintf ( V_362 , sizeof( V_362 ) , L_18 , V_74 ) ;
if ( F_112 ( V_71 -> V_16 . V_384 ) )
return;
V_12 -> V_16 . V_384 = F_113 ( V_362 , V_71 -> V_16 . V_384 ) ;
if ( F_112 ( V_12 -> V_16 . V_384 ) )
return;
V_12 -> V_16 . V_385 =
F_114 ( L_19 , 0444 , V_12 -> V_16 . V_384 ,
V_12 , & V_386 ) ;
}
static void F_111 ( struct V_11 * V_12 , unsigned int V_74 )
{
}
static struct V_11 * F_115 ( struct V_71 * V_71 ,
unsigned int V_74 )
{
struct V_11 * V_12 ;
int V_95 = - V_46 ;
int V_350 ;
struct V_18 * V_25 ;
V_350 = V_74 / V_354 ;
if ( V_350 >= V_387 )
goto V_388;
V_95 = - V_360 ;
V_12 = F_116 ( V_389 , V_351 ) ;
if ( ! V_12 )
goto V_388;
V_95 = F_117 ( V_12 , V_71 , V_74 ) ;
if ( V_95 )
goto V_390;
V_12 -> V_16 . V_391 = & V_12 -> V_16 . V_36 ;
#ifdef F_118
#ifdef F_119
V_12 -> V_16 . V_392 = true ;
#else
V_12 -> V_16 . V_392 = false ;
#endif
#endif
V_12 -> V_16 . V_265 [ 0 ] = V_393 ;
V_12 -> V_16 . V_394 = V_395 ;
F_27 ( V_12 , F_120 ( V_396 ) ) ;
F_97 ( & V_12 -> V_16 . V_86 ) ;
F_97 ( & V_12 -> V_16 . V_29 ) ;
V_12 -> V_16 . V_32 = V_23 ;
V_12 -> V_16 . V_240 = V_397 | V_398 ;
F_121 ( V_12 ) ;
V_12 -> V_16 . V_30 = V_399 ;
F_98 ( & V_12 -> V_16 . V_400 ) ;
F_35 ( & V_71 -> V_47 ) ;
V_25 = V_71 -> V_16 . V_401 [ V_350 ] ;
if ( ! V_25 ) {
V_25 = F_94 ( V_71 , V_350 ) ;
V_71 -> V_16 . V_401 [ V_350 ] = V_25 ;
V_71 -> V_16 . V_402 ++ ;
}
F_37 ( & V_71 -> V_47 ) ;
if ( ! V_25 )
goto V_390;
F_29 ( & V_25 -> V_47 ) ;
++ V_25 -> V_403 ;
F_30 ( & V_25 -> V_47 ) ;
V_12 -> V_16 . V_25 = V_25 ;
V_12 -> V_16 . V_129 = V_12 -> V_49 - V_25 -> V_353 ;
V_12 -> V_16 . V_17 = - 1 ;
V_12 -> V_16 . V_404 = V_405 ;
F_122 ( V_12 ) ;
F_111 ( V_12 , V_74 ) ;
return V_12 ;
V_390:
F_123 ( V_389 , V_12 ) ;
V_388:
return F_124 ( V_95 ) ;
}
static void F_125 ( struct V_71 * V_71 , struct V_81 * V_77 )
{
if ( V_77 -> V_90 )
F_46 ( V_71 , V_77 -> V_90 , V_77 -> V_114 ,
V_77 -> V_115 ) ;
}
static void F_126 ( struct V_11 * V_12 )
{
F_29 ( & V_12 -> V_16 . V_86 ) ;
F_125 ( V_12 -> V_71 , & V_12 -> V_16 . V_109 ) ;
F_125 ( V_12 -> V_71 , & V_12 -> V_16 . V_110 ) ;
F_125 ( V_12 -> V_71 , & V_12 -> V_16 . V_77 ) ;
F_30 ( & V_12 -> V_16 . V_86 ) ;
F_127 ( V_12 ) ;
F_123 ( V_389 , V_12 ) ;
}
static int F_128 ( struct V_11 * V_12 )
{
return 1 ;
}
static void F_129 ( struct V_11 * V_12 )
{
unsigned long V_406 , V_119 ;
V_119 = F_130 () ;
if ( V_119 > V_12 -> V_16 . V_407 ) {
F_131 ( V_12 ) ;
F_132 ( V_12 ) ;
return;
}
V_406 = ( V_12 -> V_16 . V_407 - V_119 ) * V_408
/ V_409 ;
F_133 ( & V_12 -> V_16 . V_410 , F_134 ( 0 , V_406 ) ,
V_411 ) ;
V_12 -> V_16 . V_412 = 1 ;
}
static void F_26 ( struct V_11 * V_12 )
{
V_12 -> V_16 . V_163 = 0 ;
if ( V_12 -> V_16 . V_412 ) {
F_135 ( & V_12 -> V_16 . V_410 ) ;
V_12 -> V_16 . V_412 = 0 ;
}
}
static void F_136 ( struct V_18 * V_19 ,
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
-- V_19 -> V_413 ;
F_137 ( & V_12 -> V_16 . V_414 ) ;
}
static int F_138 ( int V_1 )
{
struct V_415 * V_416 ;
long V_417 = 10000 ;
V_416 = & V_8 [ V_1 ] ;
V_416 -> V_9 . V_11 = NULL ;
V_416 -> V_9 . V_418 = NULL ;
V_416 -> V_9 . V_419 = 0 ;
F_56 () ;
V_416 -> V_9 . V_420 = 1 ;
F_8 () ;
while ( V_416 -> V_9 . V_421 == V_422 ) {
if ( -- V_417 <= 0 ) {
F_32 ( L_20 , V_1 ) ;
return - V_423 ;
}
F_107 ( 1 ) ;
}
return 0 ;
}
static void F_139 ( int V_1 )
{
struct V_415 * V_416 ;
V_416 = & V_8 [ V_1 ] ;
V_416 -> V_9 . V_420 = 0 ;
V_416 -> V_9 . V_11 = NULL ;
V_416 -> V_9 . V_418 = NULL ;
V_416 -> V_9 . V_424 = NULL ;
}
static void F_140 ( struct V_11 * V_12 , struct V_18 * V_19 )
{
int V_1 ;
struct V_415 * V_416 ;
struct V_18 * V_425 = V_19 -> V_426 ;
V_1 = V_19 -> V_128 ;
if ( V_12 ) {
if ( V_12 -> V_16 . V_412 ) {
F_135 ( & V_12 -> V_16 . V_410 ) ;
V_12 -> V_16 . V_412 = 0 ;
}
V_1 += V_12 -> V_16 . V_129 ;
V_12 -> V_1 = V_425 -> V_128 ;
V_12 -> V_16 . V_17 = V_1 ;
}
V_416 = & V_8 [ V_1 ] ;
V_416 -> V_9 . V_11 = V_12 ;
V_416 -> V_9 . V_129 = V_1 - V_425 -> V_128 ;
F_56 () ;
V_416 -> V_9 . V_418 = V_425 ;
if ( V_1 != F_5 () )
F_1 ( V_1 ) ;
}
static void F_141 ( void )
{
int V_1 = F_5 () ;
int V_213 , V_370 ;
for ( V_370 = 0 ; V_370 < 1000000 ; ++ V_370 ) {
for ( V_213 = 1 ; V_213 < V_354 ; ++ V_213 )
if ( V_8 [ V_1 + V_213 ] . V_9 . V_418 )
break;
if ( V_213 == V_354 ) {
F_142 () ;
return;
}
F_143 () ;
}
F_142 () ;
for ( V_213 = 1 ; V_213 < V_354 ; ++ V_213 )
if ( V_8 [ V_1 + V_213 ] . V_9 . V_418 )
F_32 ( L_21 , V_1 + V_213 ) ;
}
static int F_144 ( void )
{
int V_1 = F_5 () ;
int V_427 ;
if ( F_145 ( V_1 ) )
return 0 ;
V_427 = 0 ;
while ( ++ V_427 < V_354 )
if ( F_16 ( V_1 + V_427 ) )
return 0 ;
for ( V_427 = 1 ; V_427 < V_354 ; ++ V_427 ) {
if ( F_138 ( V_1 + V_427 ) ) {
do {
F_139 ( V_1 + V_427 ) ;
} while ( -- V_427 > 0 );
return 0 ;
}
}
return 1 ;
}
static void F_146 ( void )
{
int V_1 ;
F_147 (cpu) {
struct V_428 * V_429 = & F_148 ( V_430 , V_1 ) ;
F_97 ( & V_429 -> V_47 ) ;
F_96 ( & V_429 -> V_431 ) ;
}
}
static void F_149 ( struct V_18 * V_19 )
{
struct V_428 * V_429 = F_150 ( & V_430 ) ;
V_19 -> V_27 = V_432 ;
V_19 -> V_128 = F_5 () ;
if ( V_19 -> V_403 < V_354 ) {
F_29 ( & V_429 -> V_47 ) ;
F_151 ( & V_19 -> V_355 , & V_429 -> V_431 ) ;
F_30 ( & V_429 -> V_47 ) ;
}
F_18 ( V_19 ) ;
}
static void F_152 ( struct V_18 * V_19 )
{
struct V_428 * V_429 ;
F_22 ( V_19 ) ;
if ( ! F_64 ( & V_19 -> V_355 ) ) {
V_429 = & F_148 ( V_430 , V_19 -> V_128 ) ;
F_29 ( & V_429 -> V_47 ) ;
F_153 ( & V_19 -> V_355 ) ;
F_30 ( & V_429 -> V_47 ) ;
}
V_19 -> V_27 = V_121 ;
}
static void F_154 ( struct V_433 * V_434 , struct V_18 * V_19 )
{
int V_435 ;
memset ( V_434 , 0 , sizeof( * V_434 ) ) ;
V_434 -> V_436 = 1 ;
V_434 -> V_437 = V_19 -> V_403 ;
V_434 -> V_438 = V_19 -> V_403 ;
V_434 -> V_439 [ 0 ] = V_19 -> V_403 ;
V_434 -> V_440 [ 0 ] = V_19 -> V_71 ;
for ( V_435 = 0 ; V_435 < V_441 ; ++ V_435 )
F_96 ( & V_434 -> V_442 [ V_435 ] ) ;
F_151 ( & V_19 -> V_355 , & V_434 -> V_442 [ 0 ] ) ;
}
static bool F_155 ( int V_436 , int V_443 )
{
if ( V_436 > 1 && V_354 < V_444 )
return false ;
if ( V_436 > V_441 )
return false ;
if ( V_436 > 1 ) {
if ( ! ( V_445 & 2 ) )
V_436 = 4 ;
if ( V_436 > 2 && ! ( V_445 & 4 ) )
return false ;
}
return V_436 * F_156 ( V_443 ) <= V_444 ;
}
static void F_157 ( struct V_18 * V_19 )
{
V_19 -> V_426 = V_19 ;
V_19 -> V_446 = 0 ;
V_19 -> V_447 = 0 ;
V_19 -> V_448 = 0 ;
V_19 -> V_449 = 0 ;
}
static bool F_158 ( struct V_433 * V_434 )
{
int V_435 , V_450 ;
int V_451 = - 1 ;
int V_427 ;
int V_436 = V_434 -> V_436 ;
struct V_18 * V_19 , * V_452 ;
struct V_18 * V_453 = NULL ;
for ( V_435 = 0 ; V_435 < V_434 -> V_436 ; ++ V_435 ) {
if ( V_434 -> V_439 [ V_435 ] <= 2 )
continue;
if ( V_451 >= 0 )
return false ;
V_451 = V_435 ;
V_19 = F_159 ( & V_434 -> V_442 [ V_435 ] , struct V_18 ,
V_355 ) ;
if ( V_19 -> V_403 > 2 )
return false ;
V_436 += ( V_434 -> V_439 [ V_435 ] - 1 ) >> 1 ;
}
if ( V_451 < 0 || ! F_155 ( V_436 + 1 , 2 ) )
return false ;
V_450 = V_434 -> V_436 ;
V_427 = 0 ;
V_435 = V_451 ;
F_160 (vc, vcnext, &cip->vcs[sub], preempt_list) {
if ( V_427 >= 2 ) {
F_137 ( & V_19 -> V_355 ) ;
F_151 ( & V_19 -> V_355 , & V_434 -> V_442 [ V_450 ] ) ;
if ( ++ V_434 -> V_439 [ V_450 ] == 1 ) {
V_434 -> V_440 [ V_450 ] = V_19 -> V_71 ;
F_157 ( V_19 ) ;
V_453 = V_19 ;
++ V_434 -> V_436 ;
} else {
V_19 -> V_426 = V_453 ;
++ V_450 ;
}
}
V_427 += V_19 -> V_403 ;
}
V_434 -> V_439 [ V_451 ] = 2 ;
V_434 -> V_437 = 2 ;
return true ;
}
static bool F_161 ( struct V_18 * V_19 , struct V_433 * V_434 )
{
int V_443 = V_19 -> V_403 ;
int V_435 ;
if ( ! F_2 ( V_2 ) )
return false ;
if ( V_443 < V_434 -> V_437 )
V_443 = V_434 -> V_437 ;
if ( F_155 ( V_434 -> V_436 + 1 , V_443 ) ) {
V_434 -> V_437 = V_443 ;
} else if ( V_434 -> V_436 <= 2 && V_434 -> V_438 <= 6 &&
V_19 -> V_403 <= 2 ) {
if ( ! F_158 ( V_434 ) )
return false ;
} else {
return false ;
}
V_435 = V_434 -> V_436 ;
++ V_434 -> V_436 ;
V_434 -> V_438 += V_19 -> V_403 ;
V_434 -> V_439 [ V_435 ] = V_19 -> V_403 ;
V_434 -> V_440 [ V_435 ] = V_19 -> V_71 ;
F_157 ( V_19 ) ;
F_137 ( & V_19 -> V_355 ) ;
F_151 ( & V_19 -> V_355 , & V_434 -> V_442 [ V_435 ] ) ;
return true ;
}
static bool F_162 ( struct V_18 * V_454 ,
struct V_433 * V_434 , int V_435 )
{
struct V_18 * V_19 ;
int V_455 ;
V_19 = F_159 ( & V_434 -> V_442 [ V_435 ] , struct V_18 ,
V_355 ) ;
if ( V_454 -> V_71 != V_19 -> V_71 ||
V_454 -> V_131 != V_19 -> V_131 ||
V_454 -> V_39 != V_19 -> V_39 ||
V_454 -> V_70 != V_19 -> V_70 )
return false ;
if ( F_2 ( V_2 ) &&
( V_19 -> V_403 > 1 || V_454 -> V_403 > 1 ) )
return false ;
V_455 = V_434 -> V_439 [ V_435 ] + V_454 -> V_403 ;
if ( V_455 > V_434 -> V_437 ) {
if ( ! F_155 ( V_434 -> V_436 , V_455 ) )
return false ;
V_434 -> V_437 = V_455 ;
}
V_434 -> V_438 += V_454 -> V_403 ;
V_434 -> V_439 [ V_435 ] = V_455 ;
V_454 -> V_426 = V_19 ;
F_137 ( & V_454 -> V_355 ) ;
F_151 ( & V_454 -> V_355 , & V_434 -> V_442 [ V_435 ] ) ;
return true ;
}
static bool F_163 ( struct V_18 * V_454 , struct V_433 * V_434 ,
int V_456 )
{
int V_435 ;
if ( V_434 -> V_438 + V_454 -> V_403 > V_456 )
return false ;
for ( V_435 = 0 ; V_435 < V_434 -> V_436 ; ++ V_435 )
if ( V_434 -> V_439 [ V_435 ] &&
F_162 ( V_454 , V_434 , V_435 ) )
return true ;
if ( F_161 ( V_454 , V_434 ) )
return true ;
return false ;
}
static void F_164 ( struct V_18 * V_19 )
{
struct V_11 * V_12 , * V_457 ;
F_160 (vcpu, vnext, &vc->runnable_threads,
arch.run_list) {
if ( F_165 ( V_12 -> V_16 . V_458 ) )
V_12 -> V_16 . V_75 = - V_459 ;
else if ( V_12 -> V_16 . V_77 . V_88 ||
V_12 -> V_16 . V_110 . V_88 ||
V_12 -> V_16 . V_109 . V_88 )
V_12 -> V_16 . V_75 = V_181 ;
else
continue;
F_136 ( V_19 , V_12 ) ;
F_166 ( & V_12 -> V_16 . V_400 ) ;
}
}
static void F_167 ( struct V_433 * V_434 , int V_456 )
{
struct V_428 * V_429 = F_150 ( & V_430 ) ;
struct V_18 * V_454 , * V_452 ;
F_29 ( & V_429 -> V_47 ) ;
F_160 (pvc, vcnext, &lp->list, preempt_list) {
if ( ! F_168 ( & V_454 -> V_47 ) )
continue;
F_164 ( V_454 ) ;
if ( ! V_454 -> V_413 ) {
F_153 ( & V_454 -> V_355 ) ;
if ( V_454 -> V_26 == NULL ) {
V_454 -> V_27 = V_121 ;
F_22 ( V_454 ) ;
}
F_30 ( & V_454 -> V_47 ) ;
continue;
}
if ( ! F_163 ( V_454 , V_434 , V_456 ) ) {
F_30 ( & V_454 -> V_47 ) ;
continue;
}
F_22 ( V_454 ) ;
V_454 -> V_27 = V_460 ;
if ( V_434 -> V_438 >= V_456 )
break;
}
F_30 ( & V_429 -> V_47 ) ;
}
static void F_169 ( struct V_18 * V_19 , bool V_461 )
{
int V_462 = 0 ;
T_2 V_119 ;
long V_75 ;
struct V_11 * V_12 , * V_457 ;
F_29 ( & V_19 -> V_47 ) ;
V_119 = F_130 () ;
F_160 (vcpu, vnext, &vc->runnable_threads,
arch.run_list) {
if ( V_119 < V_12 -> V_16 . V_407 &&
F_170 ( V_12 ) )
F_171 ( V_12 ) ;
F_172 ( V_12 ) ;
V_75 = V_181 ;
if ( V_12 -> V_16 . V_51 )
V_75 = F_79 ( V_12 -> V_16 . V_183 , V_12 ,
V_12 -> V_16 . V_458 ) ;
V_12 -> V_16 . V_75 = V_75 ;
V_12 -> V_16 . V_51 = 0 ;
if ( F_173 ( V_12 -> V_16 . V_75 ) ) {
if ( V_12 -> V_16 . V_463 )
F_132 ( V_12 ) ;
if ( V_12 -> V_16 . V_163 )
F_129 ( V_12 ) ;
else
++ V_462 ;
} else {
F_136 ( V_19 , V_12 ) ;
F_166 ( & V_12 -> V_16 . V_400 ) ;
}
}
F_153 ( & V_19 -> V_355 ) ;
if ( ! V_461 ) {
if ( V_462 > 0 ) {
F_149 ( V_19 ) ;
} else if ( V_19 -> V_26 ) {
V_19 -> V_27 = V_432 ;
F_18 ( V_19 ) ;
} else {
V_19 -> V_27 = V_121 ;
}
if ( V_19 -> V_413 > 0 && V_19 -> V_26 == NULL ) {
V_12 = F_159 ( & V_19 -> V_352 ,
struct V_11 , V_16 . V_414 ) ;
F_166 ( & V_12 -> V_16 . V_400 ) ;
}
}
F_30 ( & V_19 -> V_47 ) ;
}
static T_9 void F_174 ( struct V_18 * V_19 )
{
struct V_11 * V_12 , * V_457 ;
int V_213 ;
int V_464 ;
struct V_433 V_433 ;
struct V_18 * V_454 , * V_452 ;
struct V_424 V_465 , * V_466 ;
int V_467 , V_468 , V_469 ;
int V_435 ;
bool V_470 ;
unsigned long V_471 , V_472 ;
int V_128 , V_427 ;
int V_456 ;
F_164 ( V_19 ) ;
if ( V_19 -> V_26 -> V_16 . V_30 != V_153 )
return;
F_157 ( V_19 ) ;
V_19 -> V_22 = V_23 ;
if ( ( V_473 > 1 ) &&
( ( V_19 -> V_403 > V_354 ) || ! F_144 () ) ) {
F_160 (vcpu, vnext, &vc->runnable_threads,
arch.run_list) {
V_12 -> V_16 . V_75 = - V_423 ;
F_136 ( V_19 , V_12 ) ;
F_166 ( & V_12 -> V_16 . V_400 ) ;
}
goto V_388;
}
F_154 ( & V_433 , V_19 ) ;
V_128 = F_5 () ;
V_456 = V_354 ;
if ( V_474 && V_474 < V_456 )
V_456 = V_474 ;
if ( V_19 -> V_403 < V_456 )
F_167 ( & V_433 , V_456 ) ;
V_468 = V_354 ;
V_471 = V_472 = 0 ;
V_467 = V_433 . V_436 ;
V_466 = NULL ;
if ( V_467 > 1 ) {
if ( V_467 == 2 && ( V_445 & 2 ) ) {
V_471 = V_475 ;
V_472 = V_476 ;
} else {
V_467 = 4 ;
V_471 = V_477 ;
V_472 = V_478 ;
}
V_468 = V_444 / V_467 ;
V_466 = & V_465 ;
memset ( & V_465 , 0 , sizeof( V_465 ) ) ;
V_465 . V_479 = F_120 ( V_480 ) ;
V_465 . V_481 = F_120 ( V_482 ) ;
V_465 . V_483 = F_120 ( V_484 ) ;
V_465 . V_468 = V_468 ;
for ( V_435 = 0 ; V_435 < V_433 . V_436 ; ++ V_435 )
V_465 . V_485 [ V_435 ] =
F_159 ( & V_433 . V_442 [ V_435 ] ,
struct V_18 , V_355 ) ;
F_56 () ;
}
V_128 = F_5 () ;
for ( V_427 = 0 ; V_427 < V_354 ; ++ V_427 )
V_8 [ V_128 + V_427 ] . V_9 . V_424 = V_466 ;
if ( V_471 ) {
unsigned long V_486 = F_120 ( V_487 ) ;
V_486 |= V_471 | V_488 ;
F_175 () ;
F_176 ( V_487 , V_486 ) ;
F_177 () ;
for (; ; ) {
V_486 = F_120 ( V_487 ) ;
if ( V_486 & V_472 )
break;
F_178 () ;
}
}
V_469 = 0 ;
for ( V_435 = 0 ; V_435 < V_433 . V_436 ; ++ V_435 ) {
V_427 = V_489 [ V_435 ] ;
V_470 = false ;
V_469 |= 1 << V_427 ;
F_179 (pvc, &core_info.vcs[sub], preempt_list) {
V_454 -> V_128 = V_128 + V_427 ;
F_179 (vcpu, &pvc->runnable_threads,
arch.run_list) {
F_140 ( V_12 , V_454 ) ;
F_50 ( V_12 , V_454 ) ;
F_180 ( V_12 ) ;
if ( ! V_12 -> V_16 . V_129 )
V_470 = true ;
V_469 |= 1 << ( V_427 + V_12 -> V_16 . V_129 ) ;
}
if ( V_454 -> V_426 == V_454 && ! V_470 )
F_140 ( NULL , V_454 ) ;
V_427 += V_454 -> V_403 ;
}
}
F_8 () ;
if ( V_471 )
V_465 . V_490 = 1 ;
if ( V_467 > 1 )
for ( V_427 = 1 ; V_427 < V_354 ; ++ V_427 )
if ( ! ( V_469 & ( 1 << V_427 ) ) )
F_1 ( V_128 + V_427 ) ;
V_19 -> V_27 = V_491 ;
F_3 () ;
F_181 ( V_19 , 0 ) ;
for ( V_435 = 0 ; V_435 < V_433 . V_436 ; ++ V_435 )
F_179 (pvc, &core_info.vcs[sub], preempt_list)
F_30 ( & V_454 -> V_47 ) ;
F_182 () ;
V_464 = F_65 ( & V_19 -> V_71 -> V_169 ) ;
F_183 () ;
F_67 ( & V_19 -> V_71 -> V_169 , V_464 ) ;
F_29 ( & V_19 -> V_47 ) ;
V_19 -> V_27 = V_492 ;
F_141 () ;
if ( V_467 > 1 ) {
unsigned long V_486 = F_120 ( V_487 ) ;
unsigned long V_370 = 0 ;
V_486 &= ~ V_488 ;
V_472 = V_476 | V_478 ;
F_175 () ;
F_176 ( V_487 , V_486 ) ;
F_177 () ;
for (; ; ) {
V_486 = F_120 ( V_487 ) ;
if ( ! ( V_486 & V_472 ) )
break;
F_178 () ;
++ V_370 ;
}
V_465 . V_490 = 0 ;
}
for ( V_213 = 0 ; V_213 < V_354 ; ++ V_213 ) {
F_139 ( V_128 + V_213 ) ;
if ( V_466 && V_466 -> V_493 [ V_213 ] )
F_1 ( V_128 + V_213 ) ;
}
F_30 ( & V_19 -> V_47 ) ;
F_8 () ;
F_184 () ;
for ( V_435 = 0 ; V_435 < V_433 . V_436 ; ++ V_435 )
F_160 (pvc, vcnext, &core_info.vcs[sub],
preempt_list)
F_169 ( V_454 , V_454 == V_19 ) ;
F_29 ( & V_19 -> V_47 ) ;
F_9 () ;
V_388:
V_19 -> V_27 = V_121 ;
F_181 ( V_19 , 1 ) ;
}
static void F_185 ( struct V_18 * V_19 ,
struct V_11 * V_12 , int V_494 )
{
F_186 ( V_495 ) ;
F_187 ( & V_12 -> V_16 . V_400 , & V_495 , V_494 ) ;
if ( V_12 -> V_16 . V_30 == V_153 ) {
F_30 ( & V_19 -> V_47 ) ;
F_188 () ;
F_29 ( & V_19 -> V_47 ) ;
}
F_189 ( & V_12 -> V_16 . V_400 , & V_495 ) ;
}
static void F_190 ( struct V_18 * V_19 )
{
struct V_11 * V_12 ;
int V_496 = 1 ;
F_186 ( V_495 ) ;
F_187 ( & V_19 -> V_164 , & V_495 , V_497 ) ;
F_179 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( V_12 -> V_16 . V_463 || ! V_12 -> V_16 . V_163 ) {
V_496 = 0 ;
break;
}
}
if ( ! V_496 ) {
F_189 ( & V_19 -> V_164 , & V_495 ) ;
return;
}
V_19 -> V_27 = V_28 ;
F_191 ( V_19 , 0 ) ;
F_30 ( & V_19 -> V_47 ) ;
F_188 () ;
F_189 ( & V_19 -> V_164 , & V_495 ) ;
F_29 ( & V_19 -> V_47 ) ;
V_19 -> V_27 = V_121 ;
F_191 ( V_19 , 1 ) ;
}
static int F_192 ( struct V_183 * V_183 , struct V_11 * V_12 )
{
int V_498 ;
struct V_18 * V_19 ;
struct V_11 * V_82 , * V_499 ;
F_193 ( V_12 ) ;
V_183 -> V_188 = 0 ;
V_12 -> V_16 . V_75 = V_181 ;
V_12 -> V_16 . V_51 = 0 ;
F_48 ( V_12 ) ;
V_19 = V_12 -> V_16 . V_25 ;
F_29 ( & V_19 -> V_47 ) ;
V_12 -> V_16 . V_163 = 0 ;
V_12 -> V_16 . V_458 = V_500 ;
V_12 -> V_16 . V_183 = V_183 ;
V_12 -> V_16 . V_125 = F_49 ( V_19 , F_20 () ) ;
V_12 -> V_16 . V_30 = V_153 ;
V_12 -> V_16 . V_32 = V_23 ;
F_151 ( & V_12 -> V_16 . V_414 , & V_19 -> V_352 ) ;
++ V_19 -> V_413 ;
if ( ! F_165 ( V_500 ) ) {
if ( V_19 -> V_27 == V_460 ) {
struct V_18 * V_425 = V_19 -> V_426 ;
if ( F_168 ( & V_425 -> V_47 ) ) {
if ( V_425 -> V_27 == V_491 &&
! F_194 ( V_425 ) ) {
F_50 ( V_12 , V_19 ) ;
F_140 ( V_12 , V_19 ) ;
F_180 ( V_12 ) ;
}
F_30 ( & V_425 -> V_47 ) ;
}
} else if ( V_19 -> V_27 == V_491 &&
! F_194 ( V_19 ) ) {
F_50 ( V_12 , V_19 ) ;
F_140 ( V_12 , V_19 ) ;
F_180 ( V_12 ) ;
} else if ( V_19 -> V_27 == V_28 ) {
F_166 ( & V_19 -> V_164 ) ;
}
}
while ( V_12 -> V_16 . V_30 == V_153 &&
! F_165 ( V_500 ) ) {
if ( V_19 -> V_27 == V_432 && V_19 -> V_26 == NULL )
F_152 ( V_19 ) ;
if ( V_19 -> V_27 != V_121 ) {
F_185 ( V_19 , V_12 , V_497 ) ;
continue;
}
F_160 (v, vn, &vc->runnable_threads,
arch.run_list) {
F_132 ( V_82 ) ;
if ( F_165 ( V_82 -> V_16 . V_458 ) ) {
F_136 ( V_19 , V_82 ) ;
V_82 -> V_14 . V_501 ++ ;
V_82 -> V_16 . V_183 -> V_188 = V_502 ;
V_82 -> V_16 . V_75 = - V_459 ;
F_166 ( & V_82 -> V_16 . V_400 ) ;
}
}
if ( ! V_19 -> V_413 || V_12 -> V_16 . V_30 != V_153 )
break;
V_498 = 0 ;
F_179 (v, &vc->runnable_threads, arch.run_list) {
if ( ! V_82 -> V_16 . V_463 )
V_498 += V_82 -> V_16 . V_163 ;
else
V_82 -> V_16 . V_163 = 0 ;
}
V_19 -> V_26 = V_12 ;
if ( V_498 == V_19 -> V_413 ) {
F_190 ( V_19 ) ;
} else if ( F_195 () ) {
F_149 ( V_19 ) ;
F_196 ( & V_19 -> V_47 ) ;
if ( V_19 -> V_27 == V_432 )
F_152 ( V_19 ) ;
} else {
F_174 ( V_19 ) ;
}
V_19 -> V_26 = NULL ;
}
while ( V_12 -> V_16 . V_30 == V_153 &&
( V_19 -> V_27 == V_491 ||
V_19 -> V_27 == V_492 ||
V_19 -> V_27 == V_460 ) )
F_185 ( V_19 , V_12 , V_503 ) ;
if ( V_19 -> V_27 == V_432 && V_19 -> V_26 == NULL )
F_152 ( V_19 ) ;
if ( V_12 -> V_16 . V_30 == V_153 ) {
F_136 ( V_19 , V_12 ) ;
V_12 -> V_14 . V_501 ++ ;
V_183 -> V_188 = V_502 ;
V_12 -> V_16 . V_75 = - V_459 ;
}
if ( V_19 -> V_413 && V_19 -> V_27 == V_121 ) {
V_82 = F_159 ( & V_19 -> V_352 ,
struct V_11 , V_16 . V_414 ) ;
F_166 ( & V_82 -> V_16 . V_400 ) ;
}
F_197 ( V_12 , V_183 ) ;
F_30 ( & V_19 -> V_47 ) ;
return V_12 -> V_16 . V_75 ;
}
static int F_198 ( struct V_183 * V_184 , struct V_11 * V_12 )
{
int V_48 ;
int V_464 ;
if ( ! V_12 -> V_16 . V_504 ) {
V_184 -> V_188 = V_198 ;
return - V_46 ;
}
F_132 ( V_12 ) ;
if ( F_165 ( V_500 ) ) {
V_184 -> V_188 = V_502 ;
return - V_459 ;
}
F_199 ( & V_12 -> V_71 -> V_16 . V_505 ) ;
F_8 () ;
if ( ! V_12 -> V_71 -> V_16 . V_506 ) {
V_48 = F_200 ( V_12 ) ;
if ( V_48 )
goto V_388;
}
F_201 ( V_500 ) ;
V_12 -> V_16 . V_13 = & V_12 -> V_16 . V_25 -> V_164 ;
V_12 -> V_16 . V_507 = V_500 -> V_508 -> V_509 ;
V_12 -> V_16 . V_30 = V_31 ;
do {
V_48 = F_192 ( V_184 , V_12 ) ;
if ( V_184 -> V_188 == V_216 &&
! ( V_12 -> V_16 . V_36 . V_34 & V_510 ) ) {
F_202 ( V_12 ) ;
V_48 = F_62 ( V_12 ) ;
F_203 ( V_12 , V_48 ) ;
F_132 ( V_12 ) ;
} else if ( V_48 == V_218 ) {
V_464 = F_65 ( & V_12 -> V_71 -> V_169 ) ;
V_48 = F_204 ( V_184 , V_12 ,
V_12 -> V_16 . V_64 , V_12 -> V_16 . V_65 ) ;
F_67 ( & V_12 -> V_71 -> V_169 , V_464 ) ;
}
} while ( F_173 ( V_48 ) );
V_388:
V_12 -> V_16 . V_30 = V_399 ;
F_205 ( & V_12 -> V_71 -> V_16 . V_505 ) ;
return V_48 ;
}
static void F_206 ( struct V_511 * * V_512 ,
int V_513 )
{
struct V_514 * V_515 = & V_516 [ V_513 ] ;
if ( ! V_515 -> V_517 )
return;
( * V_512 ) -> V_518 = V_515 -> V_517 ;
( * V_512 ) -> V_519 = V_515 -> V_520 ;
( * V_512 ) -> V_521 [ 0 ] . V_518 = V_515 -> V_517 ;
( * V_512 ) -> V_521 [ 0 ] . V_522 = V_515 -> V_523 [ V_513 ] ;
if ( V_513 != V_524 && V_515 -> V_523 [ V_524 ] != - 1 ) {
( * V_512 ) -> V_521 [ 1 ] . V_518 = 24 ;
( * V_512 ) -> V_521 [ 1 ] . V_522 = V_515 -> V_523 [ V_524 ] ;
}
( * V_512 ) ++ ;
}
static int F_207 ( struct V_71 * V_71 ,
struct V_525 * V_526 )
{
struct V_511 * V_512 ;
V_526 -> V_20 = V_527 ;
if ( F_208 ( V_528 ) )
V_526 -> V_20 |= V_529 ;
V_526 -> V_530 = V_531 ;
V_512 = & V_526 -> V_512 [ 0 ] ;
F_206 ( & V_512 , V_532 ) ;
F_206 ( & V_512 , V_533 ) ;
F_206 ( & V_512 , V_524 ) ;
return 0 ;
}
static int F_209 ( struct V_71 * V_71 ,
struct V_534 * log )
{
struct V_535 * V_536 ;
struct V_537 * V_538 ;
int V_48 ;
unsigned long V_369 ;
F_35 ( & V_71 -> V_539 ) ;
V_48 = - V_46 ;
if ( log -> V_540 >= V_541 )
goto V_388;
V_536 = V_535 ( V_71 ) ;
V_538 = F_210 ( V_536 , log -> V_540 ) ;
V_48 = - V_170 ;
if ( ! V_538 -> V_542 )
goto V_388;
V_369 = F_211 ( V_538 ) ;
memset ( V_538 -> V_542 , 0 , V_369 ) ;
V_48 = F_212 ( V_71 , V_538 , V_538 -> V_542 ) ;
if ( V_48 )
goto V_388;
V_48 = - V_382 ;
if ( F_109 ( log -> V_542 , V_538 -> V_542 , V_369 ) )
goto V_388;
V_48 = 0 ;
V_388:
F_37 ( & V_71 -> V_539 ) ;
return V_48 ;
}
static void F_213 ( struct V_537 * free ,
struct V_537 * V_543 )
{
if ( ! V_543 || free -> V_16 . V_544 != V_543 -> V_16 . V_544 ) {
F_214 ( free -> V_16 . V_544 ) ;
free -> V_16 . V_544 = NULL ;
}
}
static int F_215 ( struct V_537 * V_540 ,
unsigned long V_545 )
{
V_540 -> V_16 . V_544 = F_216 ( V_545 * sizeof( * V_540 -> V_16 . V_544 ) ) ;
if ( ! V_540 -> V_16 . V_544 )
return - V_360 ;
return 0 ;
}
static int F_217 ( struct V_71 * V_71 ,
struct V_537 * V_538 ,
const struct V_546 * V_547 )
{
return 0 ;
}
static void F_218 ( struct V_71 * V_71 ,
const struct V_546 * V_547 ,
const struct V_537 * V_548 ,
const struct V_537 * V_549 )
{
unsigned long V_545 = V_547 -> V_550 >> V_551 ;
struct V_535 * V_536 ;
struct V_537 * V_538 ;
if ( V_545 && V_548 -> V_545 ) {
V_536 = V_535 ( V_71 ) ;
V_538 = F_210 ( V_536 , V_547 -> V_540 ) ;
F_212 ( V_71 , V_538 , NULL ) ;
}
}
void F_219 ( struct V_71 * V_71 , unsigned long V_70 , unsigned long V_238 )
{
long int V_213 ;
T_3 V_552 = 0 ;
if ( ( V_71 -> V_16 . V_70 & V_238 ) == V_70 )
return;
V_71 -> V_16 . V_70 = ( V_71 -> V_16 . V_70 & ~ V_238 ) | V_70 ;
for ( V_213 = 0 ; V_213 < V_387 ; ++ V_213 ) {
struct V_18 * V_19 = V_71 -> V_16 . V_401 [ V_213 ] ;
if ( ! V_19 )
continue;
F_29 ( & V_19 -> V_47 ) ;
V_19 -> V_70 = ( V_19 -> V_70 & ~ V_238 ) | V_70 ;
F_30 ( & V_19 -> V_47 ) ;
if ( ++ V_552 >= V_71 -> V_16 . V_402 )
break;
}
}
static void F_220 ( struct V_11 * V_12 )
{
return;
}
static int F_200 ( struct V_11 * V_12 )
{
int V_95 = 0 ;
struct V_71 * V_71 = V_12 -> V_71 ;
unsigned long V_553 ;
struct V_537 * V_538 ;
struct V_554 * V_555 ;
unsigned long V_70 = 0 , V_556 ;
unsigned long V_557 , V_558 ;
int V_464 ;
F_35 ( & V_71 -> V_47 ) ;
if ( V_71 -> V_16 . V_506 )
goto V_388;
if ( ! V_71 -> V_16 . V_559 ) {
V_95 = F_221 ( V_71 , NULL ) ;
if ( V_95 ) {
F_32 ( L_22 ) ;
goto V_388;
}
}
V_464 = F_65 ( & V_71 -> V_169 ) ;
V_538 = F_222 ( V_71 , 0 ) ;
V_95 = - V_46 ;
if ( ! V_538 || ( V_538 -> V_20 & V_560 ) )
goto V_561;
V_553 = V_538 -> V_562 ;
F_223 ( & V_500 -> V_508 -> V_563 ) ;
V_555 = F_224 ( V_500 -> V_508 , V_553 ) ;
if ( ! V_555 || V_555 -> V_564 > V_553 || ( V_555 -> V_565 & V_566 ) )
goto V_567;
V_557 = F_225 ( V_555 ) ;
V_558 = F_226 ( V_557 ) ;
F_227 ( & V_500 -> V_508 -> V_563 ) ;
V_95 = - V_46 ;
if ( ! ( V_557 == 0x1000 || V_557 == 0x10000 ||
V_557 == 0x1000000 ) )
goto V_561;
V_556 = F_228 ( V_557 ) ;
V_71 -> V_16 . V_568 = V_556 | V_569 |
( V_570 << V_571 ) ;
V_70 = V_556 << ( V_572 - 4 ) ;
F_229 ( V_12 , V_538 , V_558 ) ;
F_219 ( V_71 , V_70 , V_573 ) ;
F_56 () ;
V_71 -> V_16 . V_506 = 1 ;
V_95 = 0 ;
V_561:
F_67 ( & V_71 -> V_169 , V_464 ) ;
V_388:
F_37 ( & V_71 -> V_47 ) ;
return V_95 ;
V_567:
F_227 ( & V_500 -> V_508 -> V_563 ) ;
goto V_561;
}
static int F_230 ( struct V_71 * V_71 )
{
unsigned long V_70 , V_574 ;
char V_362 [ 32 ] ;
V_574 = F_231 () ;
if ( ( long ) V_574 < 0 )
return - V_360 ;
V_71 -> V_16 . V_574 = V_574 ;
F_232 ( & V_71 -> V_16 . V_575 ) ;
memcpy ( V_71 -> V_16 . V_158 , V_576 ,
sizeof( V_71 -> V_16 . V_158 ) ) ;
V_71 -> V_16 . V_577 = F_120 ( V_578 ) ;
V_71 -> V_16 . V_579 = F_120 ( V_580 ) ;
V_71 -> V_16 . V_581 = V_70 = F_120 ( V_582 ) ;
V_70 &= V_583 | V_584 ;
V_70 |= ( 4UL << V_585 ) | V_586 |
V_587 | V_588 ;
V_71 -> V_16 . V_568 = V_569 |
( V_570 << V_571 ) ;
if ( F_2 ( V_2 ) )
V_70 |= V_589 ;
V_71 -> V_16 . V_70 = V_70 ;
F_233 () ;
snprintf ( V_362 , sizeof( V_362 ) , L_23 , V_500 -> V_294 ) ;
V_71 -> V_16 . V_384 = F_113 ( V_362 , V_590 ) ;
if ( ! F_112 ( V_71 -> V_16 . V_384 ) )
F_234 ( V_71 ) ;
return 0 ;
}
static void F_235 ( struct V_71 * V_71 )
{
long int V_213 ;
for ( V_213 = 0 ; V_213 < V_387 ; ++ V_213 )
F_104 ( V_71 -> V_16 . V_401 [ V_213 ] ) ;
V_71 -> V_16 . V_402 = 0 ;
}
static void F_236 ( struct V_71 * V_71 )
{
F_237 ( V_71 -> V_16 . V_384 ) ;
F_238 () ;
F_235 ( V_71 ) ;
F_239 ( V_71 ) ;
}
static int F_240 ( struct V_183 * V_184 , struct V_11 * V_12 ,
unsigned int V_591 , int * V_592 )
{
return V_593 ;
}
static int F_241 ( struct V_11 * V_12 , int V_594 ,
T_4 V_595 )
{
return V_593 ;
}
static int F_242 ( struct V_11 * V_12 , int V_594 ,
T_4 * V_595 )
{
return V_593 ;
}
static int F_243 ( void )
{
if ( ! F_2 ( V_596 ) ||
! F_2 ( V_597 ) )
return - V_598 ;
return 0 ;
}
static long F_244 ( struct V_357 * V_599 ,
unsigned int V_600 , unsigned long V_601 )
{
struct V_71 * V_71 V_602 = V_599 -> V_361 ;
void T_6 * V_603 = ( void T_6 * ) V_601 ;
long V_48 ;
switch ( V_600 ) {
case V_604 : {
T_3 V_605 ;
V_48 = - V_382 ;
if ( F_245 ( V_605 , ( T_3 T_6 * ) V_603 ) )
break;
V_48 = F_246 ( V_71 , & V_605 ) ;
if ( V_48 )
break;
V_48 = - V_382 ;
if ( F_247 ( V_605 , ( T_3 T_6 * ) V_603 ) )
break;
V_48 = 0 ;
break;
}
case V_606 : {
struct V_607 V_608 ;
V_48 = - V_382 ;
if ( F_248 ( & V_608 , V_603 , sizeof( V_608 ) ) )
break;
V_48 = F_249 ( V_71 , & V_608 ) ;
break;
}
default:
V_48 = - V_609 ;
}
return V_48 ;
}
static void F_250 ( void )
{
int V_213 ;
unsigned int V_610 ;
for ( V_213 = 0 ; V_611 [ V_213 ] ; ++ V_213 ) {
V_610 = V_611 [ V_213 ] ;
F_251 ( ! F_73 ( V_610 ) ) ;
F_252 ( V_610 / 4 , V_576 ) ;
}
}
static int F_253 ( void )
{
int V_48 ;
V_48 = F_243 () ;
if ( V_48 < 0 )
return - V_612 ;
V_613 . V_614 = V_615 ;
V_616 = & V_613 ;
F_250 () ;
F_146 () ;
V_48 = F_254 () ;
return V_48 ;
}
static void F_255 ( void )
{
V_616 = NULL ;
}
