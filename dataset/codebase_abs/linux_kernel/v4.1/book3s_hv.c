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
int V_1 = V_12 -> V_1 ;
T_1 * V_13 ;
V_13 = F_13 ( V_12 ) ;
if ( F_14 ( V_13 ) ) {
F_15 ( V_13 ) ;
++ V_12 -> V_14 . V_15 ;
}
if ( F_1 ( V_1 + V_12 -> V_16 . V_17 ) )
return;
if ( V_1 >= 0 && V_1 < V_7 && F_16 ( V_1 ) )
F_17 ( V_1 ) ;
}
static void F_18 ( struct V_11 * V_12 , int V_1 )
{
struct V_18 * V_19 = V_12 -> V_16 . V_20 ;
unsigned long V_21 ;
if ( V_19 -> V_22 == V_12 && V_19 -> V_23 != V_24 ) {
F_19 ( & V_19 -> V_25 , V_21 ) ;
if ( V_19 -> V_26 != V_27 ) {
V_19 -> V_28 += F_20 () - V_19 -> V_26 ;
V_19 -> V_26 = V_27 ;
}
F_21 ( & V_19 -> V_25 , V_21 ) ;
}
F_19 ( & V_12 -> V_16 . V_29 , V_21 ) ;
if ( V_12 -> V_16 . V_30 == V_31 &&
V_12 -> V_16 . V_32 != V_27 ) {
V_12 -> V_16 . V_33 += F_20 () - V_12 -> V_16 . V_32 ;
V_12 -> V_16 . V_32 = V_27 ;
}
F_21 ( & V_12 -> V_16 . V_29 , V_21 ) ;
}
static void F_22 ( struct V_11 * V_12 )
{
struct V_18 * V_19 = V_12 -> V_16 . V_20 ;
unsigned long V_21 ;
if ( V_19 -> V_22 == V_12 && V_19 -> V_23 != V_24 ) {
F_19 ( & V_19 -> V_25 , V_21 ) ;
V_19 -> V_26 = F_20 () ;
F_21 ( & V_19 -> V_25 , V_21 ) ;
}
F_19 ( & V_12 -> V_16 . V_29 , V_21 ) ;
if ( V_12 -> V_16 . V_30 == V_31 )
V_12 -> V_16 . V_32 = F_20 () ;
F_21 ( & V_12 -> V_16 . V_29 , V_21 ) ;
}
static void F_23 ( struct V_11 * V_12 , T_2 V_34 )
{
V_12 -> V_16 . V_35 . V_34 = V_34 ;
F_24 ( V_12 ) ;
}
void F_25 ( struct V_11 * V_12 , T_3 V_36 )
{
V_12 -> V_16 . V_36 = V_36 ;
}
int F_26 ( struct V_11 * V_12 , T_3 V_37 )
{
unsigned long V_38 = 0 ;
struct V_18 * V_19 = V_12 -> V_16 . V_20 ;
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
F_27 ( & V_19 -> V_46 ) ;
V_19 -> V_37 = V_37 ;
V_19 -> V_38 = V_38 ;
F_28 ( & V_19 -> V_46 ) ;
return 0 ;
}
void F_29 ( struct V_11 * V_12 )
{
int V_47 ;
F_30 ( L_1 , V_12 , V_12 -> V_48 ) ;
F_30 ( L_2 ,
V_12 -> V_16 . V_49 , V_12 -> V_16 . V_35 . V_34 , V_12 -> V_16 . V_50 ) ;
for ( V_47 = 0 ; V_47 < 16 ; ++ V_47 )
F_30 ( L_3 ,
V_47 , F_31 ( V_12 , V_47 ) ,
V_47 + 16 , F_31 ( V_12 , V_47 + 16 ) ) ;
F_30 ( L_4 ,
V_12 -> V_16 . V_51 , V_12 -> V_16 . V_52 ) ;
F_30 ( L_5 ,
V_12 -> V_16 . V_35 . V_53 , V_12 -> V_16 . V_35 . V_54 ) ;
F_30 ( L_6 ,
V_12 -> V_16 . V_35 . V_55 , V_12 -> V_16 . V_35 . V_56 ) ;
F_30 ( L_7 ,
V_12 -> V_16 . V_35 . V_57 , V_12 -> V_16 . V_35 . V_58 ) ;
F_30 ( L_8 ,
V_12 -> V_16 . V_59 , V_12 -> V_16 . V_60 , V_12 -> V_16 . V_35 . V_61 ) ;
F_30 ( L_9 , V_12 -> V_16 . V_35 . V_62 ) ;
F_30 ( L_10 ,
V_12 -> V_16 . V_63 , V_12 -> V_16 . V_64 ) ;
F_30 ( L_11 , V_12 -> V_16 . V_65 ) ;
for ( V_47 = 0 ; V_47 < V_12 -> V_16 . V_65 ; ++ V_47 )
F_30 ( L_12 ,
V_12 -> V_16 . V_66 [ V_47 ] . V_67 , V_12 -> V_16 . V_66 [ V_47 ] . V_68 ) ;
F_30 ( L_13 ,
V_12 -> V_16 . V_20 -> V_69 , V_12 -> V_70 -> V_16 . V_71 ,
V_12 -> V_16 . V_72 ) ;
}
struct V_11 * F_32 ( struct V_70 * V_70 , int V_73 )
{
int V_47 ;
struct V_11 * V_74 , * V_75 = NULL ;
F_33 ( & V_70 -> V_46 ) ;
F_34 (r, v, kvm) {
if ( V_74 -> V_48 == V_73 ) {
V_75 = V_74 ;
break;
}
}
F_35 ( & V_70 -> V_46 ) ;
return V_75 ;
}
static void F_36 ( struct V_11 * V_12 , struct V_76 * V_77 )
{
V_77 -> V_78 |= V_79 ;
V_77 -> V_80 = F_37 ( 1 ) ;
}
static int F_38 ( struct V_11 * V_12 , struct V_81 * V_74 ,
unsigned long V_82 , unsigned long V_83 )
{
if ( V_82 & ( V_84 - 1 ) )
return - V_45 ;
F_27 ( & V_12 -> V_16 . V_85 ) ;
if ( V_74 -> V_86 != V_82 || V_74 -> V_83 != V_83 ) {
V_74 -> V_86 = V_82 ;
V_74 -> V_83 = V_82 ? V_83 : 0 ;
V_74 -> V_87 = 1 ;
}
F_28 ( & V_12 -> V_16 . V_85 ) ;
return 0 ;
}
static int F_39 ( struct V_81 * V_88 )
{
if ( V_88 -> V_87 )
return V_88 -> V_86 != 0 ;
return V_88 -> V_89 != NULL ;
}
static unsigned long F_40 ( struct V_11 * V_12 ,
unsigned long V_21 ,
unsigned long V_90 , unsigned long V_77 )
{
struct V_70 * V_70 = V_12 -> V_70 ;
unsigned long V_83 , V_91 ;
void * V_92 ;
struct V_11 * V_93 ;
int V_94 ;
int V_95 ;
struct V_81 * V_88 ;
V_93 = F_32 ( V_70 , V_90 ) ;
if ( ! V_93 )
return V_96 ;
V_95 = ( V_21 >> V_97 ) & V_98 ;
if ( V_95 == V_99 || V_95 == V_100 ||
V_95 == V_101 ) {
if ( ( V_77 & ( V_84 - 1 ) ) || ! V_77 )
return V_96 ;
V_92 = F_41 ( V_70 , V_77 , & V_91 ) ;
if ( V_92 == NULL )
return V_96 ;
if ( V_95 == V_99 )
V_83 = F_42 ( ( (struct V_102 * ) V_92 ) -> V_103 . V_104 ) ;
else
V_83 = F_43 ( ( (struct V_102 * ) V_92 ) -> V_103 . V_105 ) ;
F_44 ( V_70 , V_92 , V_77 , false ) ;
if ( V_83 > V_91 || V_83 < sizeof( struct V_102 ) )
return V_96 ;
} else {
V_77 = 0 ;
V_83 = 0 ;
}
V_94 = V_96 ;
V_88 = NULL ;
F_27 ( & V_93 -> V_16 . V_85 ) ;
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
if ( ! F_39 ( & V_93 -> V_16 . V_77 ) )
break;
V_88 = & V_93 -> V_16 . V_108 ;
V_94 = 0 ;
break;
case V_101 :
V_94 = V_107 ;
if ( ! F_39 ( & V_93 -> V_16 . V_77 ) )
break;
V_88 = & V_93 -> V_16 . V_109 ;
V_94 = 0 ;
break;
case V_110 :
V_94 = V_107 ;
if ( F_39 ( & V_93 -> V_16 . V_108 ) ||
F_39 ( & V_93 -> V_16 . V_109 ) )
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
F_28 ( & V_93 -> V_16 . V_85 ) ;
return V_94 ;
}
static void F_45 ( struct V_11 * V_12 , struct V_81 * V_88 )
{
struct V_70 * V_70 = V_12 -> V_70 ;
void * V_92 ;
unsigned long V_91 ;
unsigned long V_113 ;
for (; ; ) {
V_113 = V_88 -> V_86 ;
F_28 ( & V_12 -> V_16 . V_85 ) ;
V_92 = NULL ;
V_91 = 0 ;
if ( V_113 )
V_92 = F_41 ( V_70 , V_113 , & V_91 ) ;
F_27 ( & V_12 -> V_16 . V_85 ) ;
if ( V_113 == V_88 -> V_86 )
break;
if ( V_92 )
F_44 ( V_70 , V_92 , V_113 , false ) ;
}
V_88 -> V_87 = 0 ;
if ( V_92 && V_91 < V_88 -> V_83 ) {
F_44 ( V_70 , V_92 , V_113 , false ) ;
V_92 = NULL ;
}
if ( V_88 -> V_89 )
F_44 ( V_70 , V_88 -> V_89 , V_88 -> V_113 ,
V_88 -> V_114 ) ;
V_88 -> V_113 = V_113 ;
V_88 -> V_89 = V_92 ;
V_88 -> V_114 = false ;
if ( V_92 )
V_88 -> V_115 = V_92 + V_88 -> V_83 ;
}
static void F_46 ( struct V_11 * V_12 )
{
if ( ! ( V_12 -> V_16 . V_77 . V_87 ||
V_12 -> V_16 . V_109 . V_87 ||
V_12 -> V_16 . V_108 . V_87 ) )
return;
F_27 ( & V_12 -> V_16 . V_85 ) ;
if ( V_12 -> V_16 . V_77 . V_87 ) {
F_45 ( V_12 , & V_12 -> V_16 . V_77 ) ;
if ( V_12 -> V_16 . V_77 . V_89 )
F_36 ( V_12 , V_12 -> V_16 . V_77 . V_89 ) ;
}
if ( V_12 -> V_16 . V_108 . V_87 ) {
F_45 ( V_12 , & V_12 -> V_16 . V_108 ) ;
V_12 -> V_16 . V_116 = V_12 -> V_16 . V_108 . V_89 ;
V_12 -> V_16 . V_117 = 0 ;
}
if ( V_12 -> V_16 . V_109 . V_87 )
F_45 ( V_12 , & V_12 -> V_16 . V_109 ) ;
F_28 ( & V_12 -> V_16 . V_85 ) ;
}
static T_2 F_47 ( struct V_18 * V_19 , T_2 V_118 )
{
T_2 V_119 ;
unsigned long V_21 ;
F_19 ( & V_19 -> V_25 , V_21 ) ;
V_119 = V_19 -> V_28 ;
if ( V_19 -> V_23 != V_24 &&
V_19 -> V_26 != V_27 )
V_119 += V_118 - V_19 -> V_26 ;
F_21 ( & V_19 -> V_25 , V_21 ) ;
return V_119 ;
}
static void F_48 ( struct V_11 * V_12 ,
struct V_18 * V_19 )
{
struct V_106 * V_120 ;
struct V_76 * V_77 ;
unsigned long V_121 ;
unsigned long V_122 ;
T_2 V_118 ;
V_120 = V_12 -> V_16 . V_116 ;
V_77 = V_12 -> V_16 . V_77 . V_89 ;
V_118 = F_20 () ;
V_122 = F_47 ( V_19 , V_118 ) ;
V_121 = V_122 - V_12 -> V_16 . V_123 ;
V_12 -> V_16 . V_123 = V_122 ;
F_49 ( & V_12 -> V_16 . V_29 ) ;
V_121 += V_12 -> V_16 . V_33 ;
V_12 -> V_16 . V_33 = 0 ;
F_50 ( & V_12 -> V_16 . V_29 ) ;
if ( ! V_120 || ! V_77 )
return;
memset ( V_120 , 0 , sizeof( struct V_106 ) ) ;
V_120 -> V_124 = 7 ;
V_120 -> V_125 = F_51 ( V_19 -> V_126 + V_12 -> V_16 . V_17 ) ;
V_120 -> V_127 = F_52 ( V_118 + V_19 -> V_128 ) ;
V_120 -> V_129 = F_37 ( V_121 ) ;
V_120 -> V_53 = F_52 ( F_53 ( V_12 ) ) ;
V_120 -> V_54 = F_52 ( V_12 -> V_16 . V_35 . V_34 ) ;
++ V_120 ;
if ( V_120 == V_12 -> V_16 . V_108 . V_115 )
V_120 = V_12 -> V_16 . V_108 . V_89 ;
V_12 -> V_16 . V_116 = V_120 ;
F_54 () ;
V_77 -> V_130 = F_52 ( ++ V_12 -> V_16 . V_117 ) ;
V_12 -> V_16 . V_108 . V_114 = true ;
}
static bool F_55 ( struct V_11 * V_12 )
{
if ( V_12 -> V_16 . V_20 -> V_37 >= V_44 )
return true ;
if ( ( ! V_12 -> V_16 . V_20 -> V_37 ) &&
F_2 ( V_2 ) )
return true ;
return false ;
}
static int F_56 ( struct V_11 * V_12 , unsigned long V_131 ,
unsigned long V_132 , unsigned long V_133 ,
unsigned long V_134 )
{
switch ( V_132 ) {
case V_135 :
if ( ! F_55 ( V_12 ) )
return V_136 ;
if ( V_134 )
return V_137 ;
if ( V_131 )
return V_138 ;
if ( ( V_133 & V_139 ) == V_140 )
return V_141 ;
V_12 -> V_16 . V_142 = V_133 ;
return V_143 ;
case V_144 :
if ( ! F_55 ( V_12 ) )
return V_136 ;
if ( V_131 )
return V_138 ;
if ( V_134 & V_145 )
return V_137 ;
V_12 -> V_16 . V_146 = V_133 ;
V_12 -> V_16 . V_147 = V_134 ;
return V_143 ;
default:
return V_148 ;
}
}
static int F_57 ( struct V_11 * V_149 )
{
struct V_18 * V_20 = V_149 -> V_16 . V_20 ;
F_27 ( & V_20 -> V_46 ) ;
if ( V_149 -> V_16 . V_30 == V_150 &&
V_20 -> V_23 != V_24 )
V_149 = V_20 -> V_22 ;
F_28 ( & V_20 -> V_46 ) ;
return F_58 ( V_149 ) ;
}
static int F_59 ( struct V_11 * V_12 )
{
int V_80 = 0 ;
struct V_76 * V_76 ;
F_27 ( & V_12 -> V_16 . V_85 ) ;
V_76 = (struct V_76 * ) V_12 -> V_16 . V_77 . V_89 ;
if ( V_76 )
V_80 = F_43 ( V_76 -> V_80 ) ;
F_28 ( & V_12 -> V_16 . V_85 ) ;
return V_80 ;
}
int F_60 ( struct V_11 * V_12 )
{
unsigned long V_151 = F_31 ( V_12 , 3 ) ;
unsigned long V_149 , V_75 = V_143 ;
int V_80 ;
struct V_11 * V_93 ;
int V_152 , V_153 ;
if ( V_151 <= V_154 &&
! F_61 ( V_151 / 4 , V_12 -> V_70 -> V_16 . V_155 ) )
return V_156 ;
switch ( V_151 ) {
case V_157 :
break;
case V_158 :
V_149 = F_31 ( V_12 , 4 ) ;
V_93 = F_32 ( V_12 -> V_70 , V_149 ) ;
if ( ! V_93 ) {
V_75 = V_96 ;
break;
}
V_93 -> V_16 . V_159 = 1 ;
F_8 () ;
if ( V_12 -> V_16 . V_160 ) {
if ( F_14 ( & V_12 -> V_161 ) ) {
F_15 ( & V_12 -> V_161 ) ;
V_12 -> V_14 . V_15 ++ ;
}
}
break;
case V_162 :
V_149 = F_31 ( V_12 , 4 ) ;
if ( V_149 == - 1 )
break;
V_93 = F_32 ( V_12 -> V_70 , V_149 ) ;
if ( ! V_93 ) {
V_75 = V_96 ;
break;
}
V_80 = F_31 ( V_12 , 5 ) ;
if ( F_59 ( V_93 ) != V_80 )
break;
F_57 ( V_93 ) ;
break;
case V_163 :
V_75 = F_40 ( V_12 , F_31 ( V_12 , 4 ) ,
F_31 ( V_12 , 5 ) ,
F_31 ( V_12 , 6 ) ) ;
break;
case V_164 :
if ( F_62 ( & V_12 -> V_70 -> V_16 . V_165 ) )
return V_156 ;
V_152 = F_63 ( & V_12 -> V_70 -> V_166 ) ;
V_153 = F_64 ( V_12 ) ;
F_65 ( & V_12 -> V_70 -> V_166 , V_152 ) ;
if ( V_153 == - V_167 )
return V_156 ;
else if ( V_153 == 0 )
break;
return V_153 ;
case V_168 :
V_75 = F_66 ( V_12 ) ;
if ( V_75 == V_148 )
return V_156 ;
break;
case V_169 :
V_75 = F_67 ( V_12 ) ;
if ( V_75 == V_148 )
return V_156 ;
break;
case V_170 :
V_75 = F_56 ( V_12 , F_31 ( V_12 , 4 ) ,
F_31 ( V_12 , 5 ) ,
F_31 ( V_12 , 6 ) ,
F_31 ( V_12 , 7 ) ) ;
if ( V_75 == V_148 )
return V_156 ;
break;
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
if ( F_68 ( V_12 ) ) {
V_75 = F_69 ( V_12 , V_151 ) ;
break;
}
default:
return V_156 ;
}
F_70 ( V_12 , 3 , V_75 ) ;
V_12 -> V_16 . V_177 = 0 ;
return V_178 ;
}
static int F_71 ( unsigned long V_179 )
{
switch ( V_179 ) {
case V_157 :
case V_158 :
case V_162 :
case V_163 :
case V_170 :
case V_168 :
case V_169 :
#ifdef F_72
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
#endif
return 1 ;
}
return F_73 ( V_179 ) ;
}
static int F_74 ( struct V_180 * V_181 ,
struct V_11 * V_12 )
{
T_3 V_72 ;
if ( F_75 ( V_12 , V_182 , & V_72 ) !=
V_183 ) {
return V_178 ;
}
if ( V_72 == V_184 ) {
V_181 -> V_185 = V_186 ;
V_181 -> V_187 . V_16 . V_188 = F_53 ( V_12 ) ;
return V_156 ;
} else {
F_76 ( V_12 , V_189 ) ;
return V_178 ;
}
}
static int F_77 ( struct V_180 * V_181 , struct V_11 * V_12 ,
struct V_190 * V_191 )
{
int V_47 = V_156 ;
V_12 -> V_14 . V_192 ++ ;
V_181 -> V_185 = V_193 ;
V_181 -> V_194 = 1 ;
switch ( V_12 -> V_16 . V_50 ) {
case V_195 :
V_12 -> V_14 . V_196 ++ ;
V_47 = V_178 ;
break;
case V_197 :
case V_198 :
V_12 -> V_14 . V_199 ++ ;
V_47 = V_178 ;
break;
case V_200 :
case V_201 :
V_47 = V_178 ;
break;
case V_202 :
F_78 ( V_12 ,
V_202 ) ;
V_47 = V_178 ;
break;
case V_203 :
{
T_4 V_21 ;
V_21 = V_12 -> V_16 . V_35 . V_34 & 0x1f0000ull ;
F_76 ( V_12 , V_21 ) ;
V_47 = V_178 ;
break;
}
case V_204 :
{
int V_205 ;
V_181 -> V_206 . V_207 = F_31 ( V_12 , 3 ) ;
for ( V_205 = 0 ; V_205 < 9 ; ++ V_205 )
V_181 -> V_206 . args [ V_205 ] = F_31 ( V_12 , 4 + V_205 ) ;
V_181 -> V_185 = V_208 ;
V_12 -> V_16 . V_177 = 1 ;
V_47 = V_156 ;
break;
}
case V_209 :
V_47 = V_210 ;
break;
case V_211 :
V_12 -> V_16 . V_63 = F_53 ( V_12 ) ;
V_12 -> V_16 . V_64 = 0 ;
V_47 = V_210 ;
break;
case V_212 :
if ( V_12 -> V_16 . V_213 != V_214 )
V_12 -> V_16 . V_72 = F_79 ( V_12 ) ?
F_80 ( V_12 -> V_16 . V_213 ) :
V_12 -> V_16 . V_213 ;
if ( V_12 -> V_215 & V_216 ) {
V_47 = F_74 ( V_181 , V_12 ) ;
} else {
F_76 ( V_12 , V_189 ) ;
V_47 = V_178 ;
}
break;
case V_217 :
F_76 ( V_12 , V_189 ) ;
V_47 = V_178 ;
break;
default:
F_29 ( V_12 ) ;
F_81 ( V_218 L_14 ,
V_12 -> V_16 . V_50 , F_53 ( V_12 ) ,
V_12 -> V_16 . V_35 . V_34 ) ;
V_181 -> V_219 . V_220 = V_12 -> V_16 . V_50 ;
V_47 = V_156 ;
break;
}
return V_47 ;
}
static int F_82 ( struct V_11 * V_12 ,
struct V_221 * V_222 )
{
int V_205 ;
memset ( V_222 , 0 , sizeof( struct V_221 ) ) ;
V_222 -> V_36 = V_12 -> V_16 . V_36 ;
for ( V_205 = 0 ; V_205 < V_12 -> V_16 . V_65 ; V_205 ++ ) {
V_222 -> V_223 . V_224 . V_225 . V_66 [ V_205 ] . V_226 = V_12 -> V_16 . V_66 [ V_205 ] . V_67 ;
V_222 -> V_223 . V_224 . V_225 . V_66 [ V_205 ] . V_227 = V_12 -> V_16 . V_66 [ V_205 ] . V_68 ;
}
return 0 ;
}
static int F_83 ( struct V_11 * V_12 ,
struct V_221 * V_222 )
{
int V_205 , V_228 ;
if ( V_222 -> V_36 != V_12 -> V_16 . V_36 )
return - V_45 ;
V_228 = 0 ;
for ( V_205 = 0 ; V_205 < V_12 -> V_16 . V_229 ; V_205 ++ ) {
if ( V_222 -> V_223 . V_224 . V_225 . V_66 [ V_205 ] . V_226 & V_230 ) {
V_12 -> V_16 . V_66 [ V_228 ] . V_67 = V_222 -> V_223 . V_224 . V_225 . V_66 [ V_205 ] . V_226 ;
V_12 -> V_16 . V_66 [ V_228 ] . V_68 = V_222 -> V_223 . V_224 . V_225 . V_66 [ V_205 ] . V_227 ;
++ V_228 ;
}
}
V_12 -> V_16 . V_65 = V_228 ;
return 0 ;
}
static void F_84 ( struct V_11 * V_12 , T_2 V_231 ,
bool V_232 )
{
struct V_70 * V_70 = V_12 -> V_70 ;
struct V_18 * V_19 = V_12 -> V_16 . V_20 ;
T_2 V_233 ;
F_33 ( & V_70 -> V_46 ) ;
F_27 ( & V_19 -> V_46 ) ;
if ( ( V_231 & V_234 ) != ( V_19 -> V_69 & V_234 ) ) {
struct V_11 * V_12 ;
int V_205 ;
F_34 (i, vcpu, kvm) {
if ( V_12 -> V_16 . V_20 != V_19 )
continue;
if ( V_231 & V_234 )
V_12 -> V_16 . V_235 |= V_236 ;
else
V_12 -> V_16 . V_235 &= ~ V_236 ;
}
}
V_233 = V_237 | V_234 | V_238 ;
if ( F_2 ( V_2 ) )
V_233 |= V_239 ;
if ( V_232 )
V_233 &= 0xFFFFFFFF ;
V_19 -> V_69 = ( V_19 -> V_69 & ~ V_233 ) | ( V_231 & V_233 ) ;
F_28 ( & V_19 -> V_46 ) ;
F_35 ( & V_70 -> V_46 ) ;
}
static int F_85 ( struct V_11 * V_12 , T_2 V_73 ,
union V_240 * V_241 )
{
int V_47 = 0 ;
long int V_205 ;
switch ( V_73 ) {
case V_242 :
* V_241 = F_86 ( V_73 , V_184 ) ;
break;
case V_243 :
* V_241 = F_86 ( V_73 , 0 ) ;
break;
case V_244 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_245 ) ;
break;
case V_246 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_247 ) ;
break;
case V_248 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_249 ) ;
break;
case V_250 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_251 ) ;
break;
case V_252 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_253 ) ;
break;
case V_254 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_255 ) ;
break;
case V_256 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_257 ) ;
break;
case V_258 ... V_259 :
V_205 = V_73 - V_258 ;
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_260 [ V_205 ] ) ;
break;
case V_261 ... V_262 :
V_205 = V_73 - V_261 ;
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_263 [ V_205 ] ) ;
break;
case V_264 ... V_265 :
V_205 = V_73 - V_264 ;
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_266 [ V_205 ] ) ;
break;
case V_267 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_268 ) ;
break;
case V_269 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_270 ) ;
break;
case V_271 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_272 ) ;
break;
case V_273 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_274 ) ;
break;
case V_275 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_276 ) ;
break;
case V_277 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_20 -> V_278 ) ;
break;
case V_279 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_146 ) ;
break;
case V_280 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_147 ) ;
break;
case V_281 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_142 ) ;
break;
case V_282 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_283 ) ;
break;
case V_284 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_285 ) ;
break;
case V_286 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_287 ) ;
break;
case V_288 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_289 ) ;
break;
case V_290 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_291 ) ;
break;
case V_292 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_293 ) ;
break;
case V_294 :
F_27 ( & V_12 -> V_16 . V_85 ) ;
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_77 . V_86 ) ;
F_28 ( & V_12 -> V_16 . V_85 ) ;
break;
case V_295 :
F_27 ( & V_12 -> V_16 . V_85 ) ;
V_241 -> V_296 . V_82 = V_12 -> V_16 . V_109 . V_86 ;
V_241 -> V_296 . V_103 = V_12 -> V_16 . V_109 . V_83 ;
F_28 ( & V_12 -> V_16 . V_85 ) ;
break;
case V_297 :
F_27 ( & V_12 -> V_16 . V_85 ) ;
V_241 -> V_296 . V_82 = V_12 -> V_16 . V_108 . V_86 ;
V_241 -> V_296 . V_103 = V_12 -> V_16 . V_108 . V_83 ;
F_28 ( & V_12 -> V_16 . V_85 ) ;
break;
case V_298 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_20 -> V_128 ) ;
break;
case V_299 :
case V_300 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_20 -> V_69 ) ;
break;
case V_301 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_302 ) ;
break;
#ifdef F_87
case V_303 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_304 ) ;
break;
case V_305 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_306 ) ;
break;
case V_307 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_308 ) ;
break;
case V_309 ... V_310 :
V_205 = V_73 - V_309 ;
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_311 [ V_205 ] ) ;
break;
case V_312 ... V_313 :
{
int V_228 ;
V_205 = V_73 - V_312 ;
if ( V_205 < 32 )
for ( V_228 = 0 ; V_228 < V_314 ; V_228 ++ )
V_241 -> V_315 [ V_228 ] = V_12 -> V_16 . V_316 . V_317 [ V_205 ] [ V_228 ] ;
else {
if ( F_2 ( V_318 ) )
V_241 -> V_319 = V_12 -> V_16 . V_320 . V_321 [ V_205 - 32 ] ;
else
V_47 = - V_322 ;
}
break;
}
case V_323 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_324 ) ;
break;
case V_325 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_326 ) ;
break;
case V_327 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_328 ) ;
break;
case V_329 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_316 . V_330 ) ;
break;
case V_331 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_332 ) ;
break;
case V_333 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_334 ) ;
break;
case V_335 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_336 ) ;
break;
case V_337 :
if ( F_2 ( V_318 ) )
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_320 . V_338 . V_223 [ 3 ] ) ;
else
V_47 = - V_322 ;
break;
case V_339 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_340 ) ;
break;
case V_341 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_342 ) ;
break;
#endif
case V_343 :
* V_241 = F_86 ( V_73 , V_12 -> V_16 . V_20 -> V_37 ) ;
break;
default:
V_47 = - V_45 ;
break;
}
return V_47 ;
}
static int F_88 ( struct V_11 * V_12 , T_2 V_73 ,
union V_240 * V_241 )
{
int V_47 = 0 ;
long int V_205 ;
unsigned long V_82 , V_83 ;
switch ( V_73 ) {
case V_243 :
if ( F_89 ( V_73 , * V_241 ) )
V_47 = - V_45 ;
break;
case V_244 :
V_12 -> V_16 . V_245 = F_89 ( V_73 , * V_241 ) ;
break;
case V_246 :
V_12 -> V_16 . V_247 = F_89 ( V_73 , * V_241 ) & ~ V_145 ;
break;
case V_248 :
V_12 -> V_16 . V_249 = F_89 ( V_73 , * V_241 ) ;
break;
case V_250 :
V_12 -> V_16 . V_251 = F_89 ( V_73 , * V_241 ) ;
break;
case V_252 :
V_12 -> V_16 . V_253 = F_89 ( V_73 , * V_241 ) ;
break;
case V_254 :
V_12 -> V_16 . V_255 = F_89 ( V_73 , * V_241 ) ;
break;
case V_256 :
V_12 -> V_16 . V_257 = F_89 ( V_73 , * V_241 ) ;
break;
case V_258 ... V_259 :
V_205 = V_73 - V_258 ;
V_12 -> V_16 . V_260 [ V_205 ] = F_89 ( V_73 , * V_241 ) ;
break;
case V_261 ... V_262 :
V_205 = V_73 - V_261 ;
V_12 -> V_16 . V_263 [ V_205 ] = F_89 ( V_73 , * V_241 ) ;
break;
case V_264 ... V_265 :
V_205 = V_73 - V_264 ;
V_12 -> V_16 . V_266 [ V_205 ] = F_89 ( V_73 , * V_241 ) ;
break;
case V_267 :
V_12 -> V_16 . V_268 = F_89 ( V_73 , * V_241 ) ;
break;
case V_269 :
V_12 -> V_16 . V_270 = F_89 ( V_73 , * V_241 ) ;
break;
case V_271 :
V_12 -> V_16 . V_272 = F_89 ( V_73 , * V_241 ) ;
break;
case V_273 :
V_12 -> V_16 . V_274 = F_89 ( V_73 , * V_241 ) ;
break;
case V_275 :
V_12 -> V_16 . V_276 = F_89 ( V_73 , * V_241 ) ;
break;
case V_277 :
V_12 -> V_16 . V_20 -> V_278 = F_89 ( V_73 , * V_241 ) ;
break;
case V_279 :
V_12 -> V_16 . V_146 = F_89 ( V_73 , * V_241 ) ;
break;
case V_280 :
V_12 -> V_16 . V_147 = F_89 ( V_73 , * V_241 ) & ~ V_344 ;
break;
case V_281 :
V_12 -> V_16 . V_142 = F_89 ( V_73 , * V_241 ) ;
if ( ( V_12 -> V_16 . V_142 & V_139 ) == V_140 )
V_12 -> V_16 . V_142 &= ~ V_139 ;
break;
case V_282 :
V_12 -> V_16 . V_283 = F_89 ( V_73 , * V_241 ) ;
break;
case V_284 :
V_12 -> V_16 . V_285 = F_89 ( V_73 , * V_241 ) ;
break;
case V_286 :
V_12 -> V_16 . V_287 = F_89 ( V_73 , * V_241 ) ;
break;
case V_288 :
V_12 -> V_16 . V_289 = F_89 ( V_73 , * V_241 ) ;
break;
case V_290 :
V_12 -> V_16 . V_291 = F_89 ( V_73 , * V_241 ) ;
break;
case V_292 :
V_12 -> V_16 . V_293 = F_89 ( V_73 , * V_241 ) ;
break;
case V_294 :
V_82 = F_89 ( V_73 , * V_241 ) ;
V_47 = - V_45 ;
if ( ! V_82 && ( V_12 -> V_16 . V_109 . V_86 ||
V_12 -> V_16 . V_108 . V_86 ) )
break;
V_47 = F_38 ( V_12 , & V_12 -> V_16 . V_77 , V_82 , sizeof( struct V_76 ) ) ;
break;
case V_295 :
V_82 = V_241 -> V_296 . V_82 ;
V_83 = V_241 -> V_296 . V_103 ;
V_47 = - V_45 ;
if ( V_82 && ! V_12 -> V_16 . V_77 . V_86 )
break;
V_47 = F_38 ( V_12 , & V_12 -> V_16 . V_109 , V_82 , V_83 ) ;
break;
case V_297 :
V_82 = V_241 -> V_296 . V_82 ;
V_83 = V_241 -> V_296 . V_103 ;
V_47 = - V_45 ;
if ( V_82 && ( V_83 < sizeof( struct V_106 ) ||
! V_12 -> V_16 . V_77 . V_86 ) )
break;
V_83 -= V_83 % sizeof( struct V_106 ) ;
V_47 = F_38 ( V_12 , & V_12 -> V_16 . V_108 , V_82 , V_83 ) ;
break;
case V_298 :
V_12 -> V_16 . V_20 -> V_128 =
F_90 ( F_89 ( V_73 , * V_241 ) , 1UL << 24 ) ;
break;
case V_299 :
F_84 ( V_12 , F_89 ( V_73 , * V_241 ) , true ) ;
break;
case V_300 :
F_84 ( V_12 , F_89 ( V_73 , * V_241 ) , false ) ;
break;
case V_301 :
V_12 -> V_16 . V_302 = F_89 ( V_73 , * V_241 ) ;
break;
#ifdef F_87
case V_303 :
V_12 -> V_16 . V_304 = F_89 ( V_73 , * V_241 ) ;
break;
case V_305 :
V_12 -> V_16 . V_306 = F_89 ( V_73 , * V_241 ) ;
break;
case V_307 :
V_12 -> V_16 . V_308 = F_89 ( V_73 , * V_241 ) ;
break;
case V_309 ... V_310 :
V_205 = V_73 - V_309 ;
V_12 -> V_16 . V_311 [ V_205 ] = F_89 ( V_73 , * V_241 ) ;
break;
case V_312 ... V_313 :
{
int V_228 ;
V_205 = V_73 - V_312 ;
if ( V_205 < 32 )
for ( V_228 = 0 ; V_228 < V_314 ; V_228 ++ )
V_12 -> V_16 . V_316 . V_317 [ V_205 ] [ V_228 ] = V_241 -> V_315 [ V_228 ] ;
else
if ( F_2 ( V_318 ) )
V_12 -> V_16 . V_320 . V_321 [ V_205 - 32 ] = V_241 -> V_319 ;
else
V_47 = - V_322 ;
break;
}
case V_323 :
V_12 -> V_16 . V_324 = F_89 ( V_73 , * V_241 ) ;
break;
case V_325 :
V_12 -> V_16 . V_326 = F_89 ( V_73 , * V_241 ) ;
break;
case V_327 :
V_12 -> V_16 . V_328 = F_89 ( V_73 , * V_241 ) ;
break;
case V_329 :
V_12 -> V_16 . V_316 . V_330 = F_89 ( V_73 , * V_241 ) ;
break;
case V_331 :
V_12 -> V_16 . V_332 = F_89 ( V_73 , * V_241 ) ;
break;
case V_333 :
V_12 -> V_16 . V_334 = F_89 ( V_73 , * V_241 ) ;
break;
case V_335 :
V_12 -> V_16 . V_336 = F_89 ( V_73 , * V_241 ) ;
break;
case V_337 :
if ( F_2 ( V_318 ) )
V_12 -> V_16 . V_321 . V_338 . V_223 [ 3 ] = F_89 ( V_73 , * V_241 ) ;
else
V_47 = - V_322 ;
break;
case V_339 :
V_12 -> V_16 . V_340 = F_89 ( V_73 , * V_241 ) ;
break;
case V_341 :
V_12 -> V_16 . V_342 = F_89 ( V_73 , * V_241 ) ;
break;
#endif
case V_343 :
V_47 = F_26 ( V_12 , F_89 ( V_73 , * V_241 ) ) ;
break;
default:
V_47 = - V_45 ;
break;
}
return V_47 ;
}
static struct V_18 * F_91 ( struct V_70 * V_70 , int V_345 )
{
struct V_18 * V_20 ;
V_20 = F_92 ( sizeof( struct V_18 ) , V_346 ) ;
if ( V_20 == NULL )
return NULL ;
F_93 ( & V_20 -> V_347 ) ;
F_94 ( & V_20 -> V_46 ) ;
F_94 ( & V_20 -> V_25 ) ;
F_95 ( & V_20 -> V_161 ) ;
V_20 -> V_26 = V_27 ;
V_20 -> V_69 = V_70 -> V_16 . V_69 ;
V_20 -> V_348 = V_345 * V_349 ;
V_20 -> V_70 = V_70 ;
V_20 -> V_350 = false ;
if ( F_2 ( V_2 ) )
V_20 -> V_351 = ( void * ) F_96 (
V_346 | V_352 ,
V_353 ) ;
return V_20 ;
}
static int F_97 ( struct V_354 * V_354 , struct V_355 * V_355 )
{
struct V_11 * V_12 = V_354 -> V_356 ;
struct V_357 * V_119 ;
V_119 = F_92 ( sizeof( * V_119 ) , V_346 ) ;
if ( ! V_119 )
return - V_358 ;
F_98 ( V_12 -> V_70 ) ;
V_119 -> V_12 = V_12 ;
V_355 -> V_359 = V_119 ;
return F_99 ( V_354 , V_355 ) ;
}
static int F_100 ( struct V_354 * V_354 , struct V_355 * V_355 )
{
struct V_357 * V_119 = V_355 -> V_359 ;
F_101 ( V_119 -> V_12 -> V_70 ) ;
F_102 ( V_119 ) ;
return 0 ;
}
static T_5 F_103 ( struct V_355 * V_355 , char T_6 * V_360 ,
T_7 V_83 , T_8 * V_361 )
{
struct V_357 * V_119 = V_355 -> V_359 ;
struct V_11 * V_12 = V_119 -> V_12 ;
char * V_224 , * V_362 ;
struct V_363 V_364 ;
T_2 V_365 ;
T_8 V_366 ;
T_5 V_367 ;
int V_205 , V_368 ;
bool V_369 ;
if ( ! V_119 -> V_370 ) {
V_224 = V_119 -> V_360 ;
V_362 = V_224 + sizeof( V_119 -> V_360 ) ;
for ( V_205 = 0 ; V_205 < V_371 ; ++ V_205 ) {
struct V_363 * V_372 ;
V_372 = (struct V_363 * )
( ( unsigned long ) V_12 + V_373 [ V_205 ] . V_374 ) ;
V_369 = false ;
for ( V_368 = 0 ; V_368 < 1000 ; ++ V_368 ) {
V_365 = V_372 -> V_375 ;
if ( ! ( V_365 & 1 ) ) {
F_104 () ;
V_364 = * V_372 ;
F_104 () ;
if ( V_365 == V_372 -> V_375 ) {
V_369 = true ;
break;
}
}
F_105 ( 1 ) ;
}
if ( ! V_369 )
snprintf ( V_224 , V_362 - V_224 , L_15 ,
V_373 [ V_205 ] . V_376 ) ;
else
snprintf ( V_224 , V_362 - V_224 ,
L_16 ,
V_373 [ V_205 ] . V_376 , V_365 / 2 ,
F_106 ( V_364 . V_377 ) ,
F_106 ( V_364 . V_378 ) ,
F_106 ( V_364 . V_379 ) ) ;
V_224 += strlen ( V_224 ) ;
}
V_119 -> V_370 = V_224 - V_119 -> V_360 ;
}
V_366 = * V_361 ;
if ( V_366 >= V_119 -> V_370 )
return 0 ;
if ( V_83 > V_119 -> V_370 - V_366 )
V_83 = V_119 -> V_370 - V_366 ;
V_367 = F_107 ( V_360 , V_119 -> V_360 + V_366 , V_83 ) ;
if ( V_367 ) {
if ( V_367 == V_83 )
return - V_380 ;
V_83 -= V_367 ;
}
* V_361 = V_366 + V_83 ;
return V_83 ;
}
static T_5 F_108 ( struct V_355 * V_355 , const char T_6 * V_360 ,
T_7 V_83 , T_8 * V_361 )
{
return - V_381 ;
}
static void F_109 ( struct V_11 * V_12 , unsigned int V_73 )
{
char V_360 [ 16 ] ;
struct V_70 * V_70 = V_12 -> V_70 ;
snprintf ( V_360 , sizeof( V_360 ) , L_17 , V_73 ) ;
if ( F_110 ( V_70 -> V_16 . V_382 ) )
return;
V_12 -> V_16 . V_382 = F_111 ( V_360 , V_70 -> V_16 . V_382 ) ;
if ( F_110 ( V_12 -> V_16 . V_382 ) )
return;
V_12 -> V_16 . V_383 =
F_112 ( L_18 , 0444 , V_12 -> V_16 . V_382 ,
V_12 , & V_384 ) ;
}
static void F_109 ( struct V_11 * V_12 , unsigned int V_73 )
{
}
static struct V_11 * F_113 ( struct V_70 * V_70 ,
unsigned int V_73 )
{
struct V_11 * V_12 ;
int V_94 = - V_45 ;
int V_345 ;
struct V_18 * V_20 ;
V_345 = V_73 / V_349 ;
if ( V_345 >= V_385 )
goto V_386;
V_94 = - V_358 ;
V_12 = F_114 ( V_387 , V_346 ) ;
if ( ! V_12 )
goto V_386;
V_94 = F_115 ( V_12 , V_70 , V_73 ) ;
if ( V_94 )
goto V_388;
V_12 -> V_16 . V_389 = & V_12 -> V_16 . V_35 ;
#ifdef F_116
#ifdef F_117
V_12 -> V_16 . V_390 = true ;
#else
V_12 -> V_16 . V_390 = false ;
#endif
#endif
V_12 -> V_16 . V_260 [ 0 ] = V_391 ;
V_12 -> V_16 . V_392 = V_393 ;
F_25 ( V_12 , F_118 ( V_394 ) ) ;
F_94 ( & V_12 -> V_16 . V_85 ) ;
F_94 ( & V_12 -> V_16 . V_29 ) ;
V_12 -> V_16 . V_32 = V_27 ;
V_12 -> V_16 . V_235 = V_395 | V_396 ;
F_119 ( V_12 ) ;
V_12 -> V_16 . V_30 = V_397 ;
F_95 ( & V_12 -> V_16 . V_398 ) ;
F_33 ( & V_70 -> V_46 ) ;
V_20 = V_70 -> V_16 . V_399 [ V_345 ] ;
if ( ! V_20 ) {
V_20 = F_91 ( V_70 , V_345 ) ;
V_70 -> V_16 . V_399 [ V_345 ] = V_20 ;
V_70 -> V_16 . V_400 ++ ;
}
F_35 ( & V_70 -> V_46 ) ;
if ( ! V_20 )
goto V_388;
F_27 ( & V_20 -> V_46 ) ;
++ V_20 -> V_401 ;
F_28 ( & V_20 -> V_46 ) ;
V_12 -> V_16 . V_20 = V_20 ;
V_12 -> V_16 . V_17 = V_12 -> V_48 - V_20 -> V_348 ;
V_12 -> V_16 . V_402 = V_403 ;
F_120 ( V_12 ) ;
F_109 ( V_12 , V_73 ) ;
return V_12 ;
V_388:
F_121 ( V_387 , V_12 ) ;
V_386:
return F_122 ( V_94 ) ;
}
static void F_123 ( struct V_70 * V_70 , struct V_81 * V_77 )
{
if ( V_77 -> V_89 )
F_44 ( V_70 , V_77 -> V_89 , V_77 -> V_113 ,
V_77 -> V_114 ) ;
}
static void F_124 ( struct V_11 * V_12 )
{
F_27 ( & V_12 -> V_16 . V_85 ) ;
F_123 ( V_12 -> V_70 , & V_12 -> V_16 . V_108 ) ;
F_123 ( V_12 -> V_70 , & V_12 -> V_16 . V_109 ) ;
F_123 ( V_12 -> V_70 , & V_12 -> V_16 . V_77 ) ;
F_28 ( & V_12 -> V_16 . V_85 ) ;
F_125 ( V_12 ) ;
F_121 ( V_387 , V_12 ) ;
}
static int F_126 ( struct V_11 * V_12 )
{
return 1 ;
}
static void F_127 ( struct V_11 * V_12 )
{
unsigned long V_404 , V_118 ;
V_118 = F_128 () ;
if ( V_118 > V_12 -> V_16 . V_405 ) {
F_129 ( V_12 ) ;
F_130 ( V_12 ) ;
return;
}
V_404 = ( V_12 -> V_16 . V_405 - V_118 ) * V_406
/ V_407 ;
F_131 ( & V_12 -> V_16 . V_408 , F_132 ( 0 , V_404 ) ,
V_409 ) ;
V_12 -> V_16 . V_410 = 1 ;
}
static void F_24 ( struct V_11 * V_12 )
{
V_12 -> V_16 . V_160 = 0 ;
if ( V_12 -> V_16 . V_410 ) {
F_133 ( & V_12 -> V_16 . V_408 ) ;
V_12 -> V_16 . V_410 = 0 ;
}
}
static void F_134 ( struct V_18 * V_19 ,
struct V_11 * V_12 )
{
T_2 V_118 ;
if ( V_12 -> V_16 . V_30 != V_150 )
return;
F_49 ( & V_12 -> V_16 . V_29 ) ;
V_118 = F_20 () ;
V_12 -> V_16 . V_33 += F_47 ( V_19 , V_118 ) -
V_12 -> V_16 . V_123 ;
V_12 -> V_16 . V_32 = V_118 ;
V_12 -> V_16 . V_30 = V_31 ;
F_50 ( & V_12 -> V_16 . V_29 ) ;
-- V_19 -> V_411 ;
F_135 ( & V_12 -> V_16 . V_412 ) ;
}
static int F_136 ( int V_1 )
{
struct V_413 * V_414 ;
long V_415 = 10000 ;
V_414 = & V_8 [ V_1 ] ;
V_414 -> V_9 . V_11 = NULL ;
V_414 -> V_9 . V_416 = 0 ;
F_54 () ;
V_414 -> V_9 . V_417 = 1 ;
F_8 () ;
while ( V_414 -> V_9 . V_418 == V_419 ) {
if ( -- V_415 <= 0 ) {
F_30 ( L_19 , V_1 ) ;
return - V_420 ;
}
F_105 ( 1 ) ;
}
return 0 ;
}
static void F_137 ( int V_1 )
{
struct V_413 * V_414 ;
V_414 = & V_8 [ V_1 ] ;
V_414 -> V_9 . V_417 = 0 ;
V_414 -> V_9 . V_11 = NULL ;
}
static void F_138 ( struct V_11 * V_12 )
{
int V_1 ;
struct V_413 * V_414 ;
struct V_18 * V_19 = V_12 -> V_16 . V_20 ;
if ( V_12 -> V_16 . V_410 ) {
F_133 ( & V_12 -> V_16 . V_408 ) ;
V_12 -> V_16 . V_410 = 0 ;
}
V_1 = V_19 -> V_126 + V_12 -> V_16 . V_17 ;
V_414 = & V_8 [ V_1 ] ;
V_414 -> V_9 . V_421 = V_19 ;
V_414 -> V_9 . V_17 = V_12 -> V_16 . V_17 ;
V_12 -> V_1 = V_19 -> V_126 ;
F_54 () ;
V_414 -> V_9 . V_11 = V_12 ;
if ( V_1 != F_5 () )
F_1 ( V_1 ) ;
}
static void F_139 ( void )
{
int V_1 = F_5 () ;
int V_205 , V_368 ;
for ( V_368 = 0 ; V_368 < 1000000 ; ++ V_368 ) {
for ( V_205 = 1 ; V_205 < V_349 ; ++ V_205 )
if ( V_8 [ V_1 + V_205 ] . V_9 . V_11 )
break;
if ( V_205 == V_349 ) {
F_140 () ;
return;
}
F_141 () ;
}
F_140 () ;
for ( V_205 = 1 ; V_205 < V_349 ; ++ V_205 )
if ( V_8 [ V_1 + V_205 ] . V_9 . V_11 )
F_30 ( L_20 , V_1 + V_205 ) ;
}
static int F_142 ( void )
{
int V_1 = F_5 () ;
int V_422 ;
if ( F_143 ( V_1 ) )
return 0 ;
V_422 = 0 ;
while ( ++ V_422 < V_349 )
if ( F_16 ( V_1 + V_422 ) )
return 0 ;
for ( V_422 = 1 ; V_422 < V_349 ; ++ V_422 ) {
if ( F_136 ( V_1 + V_422 ) ) {
do {
F_137 ( V_1 + V_422 ) ;
} while ( -- V_422 > 0 );
return 0 ;
}
}
return 1 ;
}
static void F_144 ( struct V_18 * V_19 )
{
T_9 V_423 , V_424 ;
V_423 = ( T_9 ) F_145 ( V_19 -> V_351 ) ;
V_424 = V_423 & V_425 ;
F_146 ( V_426 , V_424 | V_427 ) ;
F_147 ( V_424 | V_428 ) ;
V_19 -> V_350 = true ;
}
static void F_148 ( const struct V_18 * V_19 )
{
T_9 V_423 , V_424 ;
V_423 = F_145 ( V_19 -> V_351 ) ;
V_424 = V_423 & V_425 ;
F_147 ( V_424 | V_429 ) ;
F_146 ( V_426 , V_424 | V_430 ) ;
}
static void F_149 ( struct V_18 * V_19 )
{
struct V_11 * V_12 , * V_431 ;
F_150 (vcpu, vnext, &vc->runnable_threads,
arch.run_list) {
if ( F_151 ( V_12 -> V_16 . V_432 ) )
V_12 -> V_16 . V_75 = - V_433 ;
else if ( V_12 -> V_16 . V_77 . V_87 ||
V_12 -> V_16 . V_109 . V_87 ||
V_12 -> V_16 . V_108 . V_87 )
V_12 -> V_16 . V_75 = V_178 ;
else
continue;
F_134 ( V_19 , V_12 ) ;
F_152 ( & V_12 -> V_16 . V_398 ) ;
}
}
static void F_153 ( struct V_18 * V_19 )
{
T_2 V_118 ;
long V_75 ;
struct V_11 * V_12 , * V_431 ;
V_118 = F_128 () ;
F_150 (vcpu, vnext, &vc->runnable_threads,
arch.run_list) {
if ( V_118 < V_12 -> V_16 . V_405 &&
F_154 ( V_12 ) )
F_155 ( V_12 ) ;
F_156 ( V_12 ) ;
V_75 = V_178 ;
if ( V_12 -> V_16 . V_50 )
V_75 = F_77 ( V_12 -> V_16 . V_180 , V_12 ,
V_12 -> V_16 . V_432 ) ;
V_12 -> V_16 . V_75 = V_75 ;
V_12 -> V_16 . V_50 = 0 ;
if ( V_12 -> V_16 . V_160 ) {
if ( ! F_157 ( V_75 ) )
F_24 ( V_12 ) ;
else
F_127 ( V_12 ) ;
}
if ( ! F_157 ( V_12 -> V_16 . V_75 ) ) {
F_134 ( V_19 , V_12 ) ;
F_152 ( & V_12 -> V_16 . V_398 ) ;
}
}
}
static T_10 void F_158 ( struct V_18 * V_19 )
{
struct V_11 * V_12 , * V_431 ;
int V_205 ;
int V_434 ;
F_149 ( V_19 ) ;
if ( V_19 -> V_22 -> V_16 . V_30 != V_150 )
return;
V_19 -> V_435 = 0 ;
V_19 -> V_26 = V_27 ;
V_19 -> V_436 = 0 ;
V_19 -> V_437 = 0 ;
V_19 -> V_438 = 0 ;
if ( ( V_439 > 1 ) &&
( ( V_19 -> V_401 > V_349 ) || ! F_142 () ) ) {
F_150 (vcpu, vnext, &vc->runnable_threads,
arch.run_list) {
V_12 -> V_16 . V_75 = - V_420 ;
F_134 ( V_19 , V_12 ) ;
F_152 ( & V_12 -> V_16 . V_398 ) ;
}
goto V_386;
}
V_19 -> V_126 = F_5 () ;
F_159 (vcpu, &vc->runnable_threads, arch.run_list) {
F_138 ( V_12 ) ;
F_48 ( V_12 , V_19 ) ;
F_160 ( V_12 ) ;
}
F_161 () -> V_9 . V_421 = V_19 ;
F_161 () -> V_9 . V_17 = 0 ;
V_19 -> V_23 = V_440 ;
F_3 () ;
F_162 ( V_19 , 0 ) ;
F_28 ( & V_19 -> V_46 ) ;
F_163 () ;
V_434 = F_63 ( & V_19 -> V_70 -> V_166 ) ;
if ( V_19 -> V_350 )
F_148 ( V_19 ) ;
F_164 () ;
F_27 ( & V_19 -> V_46 ) ;
if ( V_19 -> V_351 )
F_144 ( V_19 ) ;
F_159 (vcpu, &vc->runnable_threads, arch.run_list)
V_12 -> V_1 = - 1 ;
F_139 () ;
for ( V_205 = 0 ; V_205 < V_349 ; ++ V_205 )
F_137 ( V_19 -> V_126 + V_205 ) ;
V_19 -> V_23 = V_441 ;
F_28 ( & V_19 -> V_46 ) ;
F_65 ( & V_19 -> V_70 -> V_166 , V_434 ) ;
F_8 () ;
F_165 () ;
F_9 () ;
F_27 ( & V_19 -> V_46 ) ;
F_153 ( V_19 ) ;
V_386:
V_19 -> V_23 = V_24 ;
F_162 ( V_19 , 1 ) ;
}
static void F_166 ( struct V_11 * V_12 , int V_442 )
{
F_167 ( V_443 ) ;
F_168 ( & V_12 -> V_16 . V_398 , & V_443 , V_442 ) ;
if ( V_12 -> V_16 . V_30 == V_150 )
F_169 () ;
F_170 ( & V_12 -> V_16 . V_398 , & V_443 ) ;
}
static void F_171 ( struct V_18 * V_19 )
{
struct V_11 * V_12 ;
int V_444 = 1 ;
F_167 ( V_443 ) ;
F_168 ( & V_19 -> V_161 , & V_443 , V_445 ) ;
F_159 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( V_12 -> V_16 . V_446 || ! V_12 -> V_16 . V_160 ) {
V_444 = 0 ;
break;
}
}
if ( ! V_444 ) {
F_170 ( & V_19 -> V_161 , & V_443 ) ;
return;
}
V_19 -> V_23 = V_447 ;
F_172 ( V_19 , 0 ) ;
F_28 ( & V_19 -> V_46 ) ;
F_169 () ;
F_170 ( & V_19 -> V_161 , & V_443 ) ;
F_27 ( & V_19 -> V_46 ) ;
V_19 -> V_23 = V_24 ;
F_172 ( V_19 , 1 ) ;
}
static int F_173 ( struct V_180 * V_180 , struct V_11 * V_12 )
{
int V_448 ;
struct V_18 * V_19 ;
struct V_11 * V_74 , * V_449 ;
F_174 ( V_12 ) ;
V_180 -> V_185 = 0 ;
V_12 -> V_16 . V_75 = V_178 ;
V_12 -> V_16 . V_50 = 0 ;
F_46 ( V_12 ) ;
V_19 = V_12 -> V_16 . V_20 ;
F_27 ( & V_19 -> V_46 ) ;
V_12 -> V_16 . V_160 = 0 ;
V_12 -> V_16 . V_432 = V_450 ;
V_12 -> V_16 . V_180 = V_180 ;
V_12 -> V_16 . V_123 = F_47 ( V_19 , F_20 () ) ;
V_12 -> V_16 . V_30 = V_150 ;
V_12 -> V_16 . V_32 = V_27 ;
F_175 ( & V_12 -> V_16 . V_412 , & V_19 -> V_347 ) ;
++ V_19 -> V_411 ;
if ( ! F_151 ( V_450 ) ) {
if ( V_19 -> V_23 == V_440 && ! F_176 ( V_19 ) ) {
F_48 ( V_12 , V_19 ) ;
F_138 ( V_12 ) ;
F_160 ( V_12 ) ;
} else if ( V_19 -> V_23 == V_447 ) {
F_152 ( & V_19 -> V_161 ) ;
}
}
while ( V_12 -> V_16 . V_30 == V_150 &&
! F_151 ( V_450 ) ) {
if ( V_19 -> V_23 != V_24 ) {
F_28 ( & V_19 -> V_46 ) ;
F_166 ( V_12 , V_445 ) ;
F_27 ( & V_19 -> V_46 ) ;
continue;
}
F_150 (v, vn, &vc->runnable_threads,
arch.run_list) {
F_130 ( V_74 ) ;
if ( F_151 ( V_74 -> V_16 . V_432 ) ) {
F_134 ( V_19 , V_74 ) ;
V_74 -> V_14 . V_451 ++ ;
V_74 -> V_16 . V_180 -> V_185 = V_452 ;
V_74 -> V_16 . V_75 = - V_433 ;
F_152 ( & V_74 -> V_16 . V_398 ) ;
}
}
if ( ! V_19 -> V_411 || V_12 -> V_16 . V_30 != V_150 )
break;
V_448 = 0 ;
F_159 (v, &vc->runnable_threads, arch.run_list) {
if ( ! V_74 -> V_16 . V_446 )
V_448 += V_74 -> V_16 . V_160 ;
else
V_74 -> V_16 . V_160 = 0 ;
}
V_19 -> V_22 = V_12 ;
if ( V_448 == V_19 -> V_411 ) {
F_171 ( V_19 ) ;
} else if ( F_177 () ) {
V_19 -> V_23 = V_453 ;
F_178 ( & V_19 -> V_46 ) ;
V_19 -> V_23 = V_24 ;
} else {
F_158 ( V_19 ) ;
}
V_19 -> V_22 = NULL ;
}
while ( V_12 -> V_16 . V_30 == V_150 &&
( V_19 -> V_23 == V_440 ||
V_19 -> V_23 == V_441 ) ) {
F_28 ( & V_19 -> V_46 ) ;
F_166 ( V_12 , V_454 ) ;
F_27 ( & V_19 -> V_46 ) ;
}
if ( V_12 -> V_16 . V_30 == V_150 ) {
F_134 ( V_19 , V_12 ) ;
V_12 -> V_14 . V_451 ++ ;
V_180 -> V_185 = V_452 ;
V_12 -> V_16 . V_75 = - V_433 ;
}
if ( V_19 -> V_411 && V_19 -> V_23 == V_24 ) {
V_74 = F_179 ( & V_19 -> V_347 ,
struct V_11 , V_16 . V_412 ) ;
F_152 ( & V_74 -> V_16 . V_398 ) ;
}
F_180 ( V_12 , V_180 ) ;
F_28 ( & V_19 -> V_46 ) ;
return V_12 -> V_16 . V_75 ;
}
static int F_181 ( struct V_180 * V_181 , struct V_11 * V_12 )
{
int V_47 ;
int V_434 ;
if ( ! V_12 -> V_16 . V_455 ) {
V_181 -> V_185 = V_456 ;
return - V_45 ;
}
F_130 ( V_12 ) ;
if ( F_151 ( V_450 ) ) {
V_181 -> V_185 = V_452 ;
return - V_433 ;
}
F_182 ( & V_12 -> V_70 -> V_16 . V_457 ) ;
F_8 () ;
if ( ! V_12 -> V_70 -> V_16 . V_458 ) {
V_47 = F_183 ( V_12 ) ;
if ( V_47 )
goto V_386;
}
F_184 ( V_450 ) ;
F_185 ( V_450 ) ;
F_186 ( V_450 ) ;
V_12 -> V_16 . V_13 = & V_12 -> V_16 . V_20 -> V_161 ;
V_12 -> V_16 . V_459 = V_450 -> V_460 -> V_461 ;
V_12 -> V_16 . V_30 = V_31 ;
do {
V_47 = F_173 ( V_181 , V_12 ) ;
if ( V_181 -> V_185 == V_208 &&
! ( V_12 -> V_16 . V_35 . V_34 & V_462 ) ) {
F_187 ( V_12 ) ;
V_47 = F_60 ( V_12 ) ;
F_188 ( V_12 , V_47 ) ;
F_130 ( V_12 ) ;
} else if ( V_47 == V_210 ) {
V_434 = F_63 ( & V_12 -> V_70 -> V_166 ) ;
V_47 = F_189 ( V_181 , V_12 ,
V_12 -> V_16 . V_63 , V_12 -> V_16 . V_64 ) ;
F_65 ( & V_12 -> V_70 -> V_166 , V_434 ) ;
}
} while ( F_157 ( V_47 ) );
V_386:
V_12 -> V_16 . V_30 = V_397 ;
F_190 ( & V_12 -> V_70 -> V_16 . V_457 ) ;
return V_47 ;
}
static void F_191 ( struct V_463 * * V_464 ,
int V_465 )
{
struct V_466 * V_467 = & V_468 [ V_465 ] ;
if ( ! V_467 -> V_469 )
return;
( * V_464 ) -> V_470 = V_467 -> V_469 ;
( * V_464 ) -> V_471 = V_467 -> V_472 ;
( * V_464 ) -> V_473 [ 0 ] . V_470 = V_467 -> V_469 ;
( * V_464 ) -> V_473 [ 0 ] . V_474 = V_467 -> V_475 [ V_465 ] ;
if ( V_465 != V_476 && V_467 -> V_475 [ V_476 ] != - 1 ) {
( * V_464 ) -> V_473 [ 1 ] . V_470 = 24 ;
( * V_464 ) -> V_473 [ 1 ] . V_474 = V_467 -> V_475 [ V_476 ] ;
}
( * V_464 ) ++ ;
}
static int F_192 ( struct V_70 * V_70 ,
struct V_477 * V_478 )
{
struct V_463 * V_464 ;
V_478 -> V_21 = V_479 ;
if ( F_193 ( V_480 ) )
V_478 -> V_21 |= V_481 ;
V_478 -> V_482 = V_483 ;
V_464 = & V_478 -> V_464 [ 0 ] ;
F_191 ( & V_464 , V_484 ) ;
F_191 ( & V_464 , V_485 ) ;
F_191 ( & V_464 , V_476 ) ;
return 0 ;
}
static int F_194 ( struct V_70 * V_70 ,
struct V_486 * log )
{
struct V_487 * V_488 ;
int V_47 ;
unsigned long V_367 ;
F_33 ( & V_70 -> V_489 ) ;
V_47 = - V_45 ;
if ( log -> V_490 >= V_491 )
goto V_386;
V_488 = F_195 ( V_70 -> V_492 , log -> V_490 ) ;
V_47 = - V_167 ;
if ( ! V_488 -> V_493 )
goto V_386;
V_367 = F_196 ( V_488 ) ;
memset ( V_488 -> V_493 , 0 , V_367 ) ;
V_47 = F_197 ( V_70 , V_488 , V_488 -> V_493 ) ;
if ( V_47 )
goto V_386;
V_47 = - V_380 ;
if ( F_107 ( log -> V_493 , V_488 -> V_493 , V_367 ) )
goto V_386;
V_47 = 0 ;
V_386:
F_35 ( & V_70 -> V_489 ) ;
return V_47 ;
}
static void F_198 ( struct V_487 * free ,
struct V_487 * V_494 )
{
if ( ! V_494 || free -> V_16 . V_495 != V_494 -> V_16 . V_495 ) {
F_199 ( free -> V_16 . V_495 ) ;
free -> V_16 . V_495 = NULL ;
}
}
static int F_200 ( struct V_487 * V_490 ,
unsigned long V_496 )
{
V_490 -> V_16 . V_495 = F_201 ( V_496 * sizeof( * V_490 -> V_16 . V_495 ) ) ;
if ( ! V_490 -> V_16 . V_495 )
return - V_358 ;
return 0 ;
}
static int F_202 ( struct V_70 * V_70 ,
struct V_487 * V_488 ,
struct V_497 * V_498 )
{
return 0 ;
}
static void F_203 ( struct V_70 * V_70 ,
struct V_497 * V_498 ,
const struct V_487 * V_499 )
{
unsigned long V_496 = V_498 -> V_500 >> V_501 ;
struct V_487 * V_488 ;
if ( V_496 && V_499 -> V_496 ) {
V_488 = F_195 ( V_70 -> V_492 , V_498 -> V_490 ) ;
F_197 ( V_70 , V_488 , NULL ) ;
}
}
void F_204 ( struct V_70 * V_70 , unsigned long V_69 , unsigned long V_233 )
{
long int V_205 ;
T_3 V_502 = 0 ;
if ( ( V_70 -> V_16 . V_69 & V_233 ) == V_69 )
return;
V_70 -> V_16 . V_69 = ( V_70 -> V_16 . V_69 & ~ V_233 ) | V_69 ;
for ( V_205 = 0 ; V_205 < V_385 ; ++ V_205 ) {
struct V_18 * V_19 = V_70 -> V_16 . V_399 [ V_205 ] ;
if ( ! V_19 )
continue;
F_27 ( & V_19 -> V_46 ) ;
V_19 -> V_69 = ( V_19 -> V_69 & ~ V_233 ) | V_69 ;
F_28 ( & V_19 -> V_46 ) ;
if ( ++ V_502 >= V_70 -> V_16 . V_400 )
break;
}
}
static void F_205 ( struct V_11 * V_12 )
{
return;
}
static int F_183 ( struct V_11 * V_12 )
{
int V_94 = 0 ;
struct V_70 * V_70 = V_12 -> V_70 ;
unsigned long V_503 ;
struct V_487 * V_488 ;
struct V_504 * V_505 ;
unsigned long V_69 = 0 , V_506 ;
unsigned long V_507 , V_508 ;
int V_434 ;
F_33 ( & V_70 -> V_46 ) ;
if ( V_70 -> V_16 . V_458 )
goto V_386;
if ( ! V_70 -> V_16 . V_509 ) {
V_94 = F_206 ( V_70 , NULL ) ;
if ( V_94 ) {
F_30 ( L_21 ) ;
goto V_386;
}
}
V_434 = F_63 ( & V_70 -> V_166 ) ;
V_488 = F_207 ( V_70 , 0 ) ;
V_94 = - V_45 ;
if ( ! V_488 || ( V_488 -> V_21 & V_510 ) )
goto V_511;
V_503 = V_488 -> V_512 ;
F_208 ( & V_450 -> V_460 -> V_513 ) ;
V_505 = F_209 ( V_450 -> V_460 , V_503 ) ;
if ( ! V_505 || V_505 -> V_514 > V_503 || ( V_505 -> V_515 & V_516 ) )
goto V_517;
V_507 = F_210 ( V_505 ) ;
V_508 = F_211 ( V_507 ) ;
F_212 ( & V_450 -> V_460 -> V_513 ) ;
V_94 = - V_45 ;
if ( ! ( V_507 == 0x1000 || V_507 == 0x10000 ||
V_507 == 0x1000000 ) )
goto V_511;
V_506 = F_213 ( V_507 ) ;
V_70 -> V_16 . V_518 = V_506 | V_519 |
( V_520 << V_521 ) ;
V_69 = V_506 << ( V_522 - 4 ) ;
F_214 ( V_12 , V_488 , V_508 ) ;
F_204 ( V_70 , V_69 , V_523 ) ;
F_54 () ;
V_70 -> V_16 . V_458 = 1 ;
V_94 = 0 ;
V_511:
F_65 ( & V_70 -> V_166 , V_434 ) ;
V_386:
F_35 ( & V_70 -> V_46 ) ;
return V_94 ;
V_517:
F_212 ( & V_450 -> V_460 -> V_513 ) ;
goto V_511;
}
static int F_215 ( struct V_70 * V_70 )
{
unsigned long V_69 , V_524 ;
char V_360 [ 32 ] ;
V_524 = F_216 () ;
if ( ( long ) V_524 < 0 )
return - V_358 ;
V_70 -> V_16 . V_524 = V_524 ;
F_217 ( & V_70 -> V_16 . V_525 ) ;
memcpy ( V_70 -> V_16 . V_155 , V_526 ,
sizeof( V_70 -> V_16 . V_155 ) ) ;
V_70 -> V_16 . V_527 = F_118 ( V_528 ) ;
V_70 -> V_16 . V_529 = F_118 ( V_530 ) ;
V_70 -> V_16 . V_531 = V_69 = F_118 ( V_532 ) ;
V_69 &= V_533 | V_534 ;
V_69 |= ( 4UL << V_535 ) | V_536 |
V_537 | V_538 ;
V_70 -> V_16 . V_518 = V_519 |
( V_520 << V_521 ) ;
if ( F_2 ( V_2 ) )
V_69 |= V_539 ;
V_70 -> V_16 . V_69 = V_69 ;
F_218 () ;
snprintf ( V_360 , sizeof( V_360 ) , L_22 , V_450 -> V_289 ) ;
V_70 -> V_16 . V_382 = F_111 ( V_360 , V_540 ) ;
if ( ! F_110 ( V_70 -> V_16 . V_382 ) )
F_219 ( V_70 ) ;
return 0 ;
}
static void F_220 ( struct V_70 * V_70 )
{
long int V_205 ;
for ( V_205 = 0 ; V_205 < V_385 ; ++ V_205 ) {
if ( V_70 -> V_16 . V_399 [ V_205 ] && V_70 -> V_16 . V_399 [ V_205 ] -> V_351 ) {
struct V_18 * V_19 = V_70 -> V_16 . V_399 [ V_205 ] ;
F_221 ( ( unsigned long ) V_19 -> V_351 ,
V_353 ) ;
}
F_102 ( V_70 -> V_16 . V_399 [ V_205 ] ) ;
}
V_70 -> V_16 . V_400 = 0 ;
}
static void F_222 ( struct V_70 * V_70 )
{
F_223 ( V_70 -> V_16 . V_382 ) ;
F_224 () ;
F_220 ( V_70 ) ;
F_225 ( V_70 ) ;
}
static int F_226 ( struct V_180 * V_181 , struct V_11 * V_12 ,
unsigned int V_541 , int * V_542 )
{
return V_543 ;
}
static int F_227 ( struct V_11 * V_12 , int V_544 ,
T_4 V_545 )
{
return V_543 ;
}
static int F_228 ( struct V_11 * V_12 , int V_544 ,
T_4 * V_545 )
{
return V_543 ;
}
static int F_229 ( void )
{
if ( ! F_2 ( V_546 ) ||
! F_2 ( V_547 ) )
return - V_548 ;
return 0 ;
}
static long F_230 ( struct V_355 * V_549 ,
unsigned int V_550 , unsigned long V_551 )
{
struct V_70 * V_70 V_552 = V_549 -> V_359 ;
void T_6 * V_553 = ( void T_6 * ) V_551 ;
long V_47 ;
switch ( V_550 ) {
case V_554 : {
T_3 V_555 ;
V_47 = - V_380 ;
if ( F_231 ( V_555 , ( T_3 T_6 * ) V_553 ) )
break;
V_47 = F_232 ( V_70 , & V_555 ) ;
if ( V_47 )
break;
V_47 = - V_380 ;
if ( F_233 ( V_555 , ( T_3 T_6 * ) V_553 ) )
break;
V_47 = 0 ;
break;
}
case V_556 : {
struct V_557 V_558 ;
V_47 = - V_380 ;
if ( F_234 ( & V_558 , V_553 , sizeof( V_558 ) ) )
break;
V_47 = F_235 ( V_70 , & V_558 ) ;
break;
}
default:
V_47 = - V_559 ;
}
return V_47 ;
}
static void F_236 ( void )
{
int V_205 ;
unsigned int V_560 ;
for ( V_205 = 0 ; V_561 [ V_205 ] ; ++ V_205 ) {
V_560 = V_561 [ V_205 ] ;
F_237 ( ! F_71 ( V_560 ) ) ;
F_238 ( V_560 / 4 , V_526 ) ;
}
}
static int F_239 ( void )
{
int V_47 ;
V_47 = F_229 () ;
if ( V_47 < 0 )
return - V_562 ;
V_563 . V_564 = V_565 ;
V_566 = & V_563 ;
F_236 () ;
V_47 = F_240 () ;
return V_47 ;
}
static void F_241 ( void )
{
V_566 = NULL ;
}
