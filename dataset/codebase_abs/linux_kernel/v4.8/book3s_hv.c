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
struct V_13 * V_14 ;
V_14 = F_13 ( V_12 ) ;
if ( F_14 ( V_14 ) ) {
F_15 ( V_14 ) ;
++ V_12 -> V_15 . V_16 ;
}
if ( F_1 ( V_12 -> V_17 . V_18 ) )
return;
V_1 = V_12 -> V_1 ;
if ( V_1 >= 0 && V_1 < V_7 && F_16 ( V_1 ) )
F_17 ( V_1 ) ;
}
static void F_18 ( struct V_19 * V_20 )
{
unsigned long V_21 ;
F_19 ( & V_20 -> V_22 , V_21 ) ;
V_20 -> V_23 = F_20 () ;
F_21 ( & V_20 -> V_22 , V_21 ) ;
}
static void F_22 ( struct V_19 * V_20 )
{
unsigned long V_21 ;
F_19 ( & V_20 -> V_22 , V_21 ) ;
if ( V_20 -> V_23 != V_24 ) {
V_20 -> V_25 += F_20 () - V_20 -> V_23 ;
V_20 -> V_23 = V_24 ;
}
F_21 ( & V_20 -> V_22 , V_21 ) ;
}
static void F_23 ( struct V_11 * V_12 , int V_1 )
{
struct V_19 * V_20 = V_12 -> V_17 . V_26 ;
unsigned long V_21 ;
if ( V_20 -> V_27 == V_12 && V_20 -> V_28 >= V_29 )
F_22 ( V_20 ) ;
F_19 ( & V_12 -> V_17 . V_30 , V_21 ) ;
if ( V_12 -> V_17 . V_31 == V_32 &&
V_12 -> V_17 . V_33 != V_24 ) {
V_12 -> V_17 . V_34 += F_20 () - V_12 -> V_17 . V_33 ;
V_12 -> V_17 . V_33 = V_24 ;
}
F_21 ( & V_12 -> V_17 . V_30 , V_21 ) ;
}
static void F_24 ( struct V_11 * V_12 )
{
struct V_19 * V_20 = V_12 -> V_17 . V_26 ;
unsigned long V_21 ;
if ( V_20 -> V_27 == V_12 && V_20 -> V_28 >= V_29 )
F_18 ( V_20 ) ;
F_19 ( & V_12 -> V_17 . V_30 , V_21 ) ;
if ( V_12 -> V_17 . V_31 == V_32 )
V_12 -> V_17 . V_33 = F_20 () ;
F_21 ( & V_12 -> V_17 . V_30 , V_21 ) ;
}
static void F_25 ( struct V_11 * V_12 , T_1 V_35 )
{
if ( ( V_35 & V_36 ) == V_36 )
V_35 &= ~ V_36 ;
V_12 -> V_17 . V_37 . V_35 = V_35 ;
F_26 ( V_12 ) ;
}
static void F_27 ( struct V_11 * V_12 , T_2 V_38 )
{
V_12 -> V_17 . V_38 = V_38 ;
}
static int F_28 ( struct V_11 * V_12 , T_2 V_39 )
{
unsigned long V_40 = 0 ;
struct V_19 * V_20 = V_12 -> V_17 . V_26 ;
if ( V_39 ) {
switch ( V_39 ) {
case V_41 :
V_40 = V_42 | V_43 ;
break;
case V_44 :
case V_45 :
V_40 = V_42 ;
break;
case V_46 :
break;
default:
return - V_47 ;
}
if ( ! F_2 ( V_2 ) ) {
if ( ! ( V_40 & V_42 ) )
return - V_47 ;
V_40 &= ~ V_42 ;
}
}
F_29 ( & V_20 -> V_48 ) ;
V_20 -> V_39 = V_39 ;
V_20 -> V_40 = V_40 ;
F_30 ( & V_20 -> V_48 ) ;
return 0 ;
}
static void F_31 ( struct V_11 * V_12 )
{
int V_49 ;
F_32 ( L_1 , V_12 , V_12 -> V_50 ) ;
F_32 ( L_2 ,
V_12 -> V_17 . V_51 , V_12 -> V_17 . V_37 . V_35 , V_12 -> V_17 . V_52 ) ;
for ( V_49 = 0 ; V_49 < 16 ; ++ V_49 )
F_32 ( L_3 ,
V_49 , F_33 ( V_12 , V_49 ) ,
V_49 + 16 , F_33 ( V_12 , V_49 + 16 ) ) ;
F_32 ( L_4 ,
V_12 -> V_17 . V_53 , V_12 -> V_17 . V_54 ) ;
F_32 ( L_5 ,
V_12 -> V_17 . V_37 . V_55 , V_12 -> V_17 . V_37 . V_56 ) ;
F_32 ( L_6 ,
V_12 -> V_17 . V_37 . V_57 , V_12 -> V_17 . V_37 . V_58 ) ;
F_32 ( L_7 ,
V_12 -> V_17 . V_37 . V_59 , V_12 -> V_17 . V_37 . V_60 ) ;
F_32 ( L_8 ,
V_12 -> V_17 . V_61 , V_12 -> V_17 . V_62 , V_12 -> V_17 . V_37 . V_63 ) ;
F_32 ( L_9 , V_12 -> V_17 . V_37 . V_64 ) ;
F_32 ( L_10 ,
V_12 -> V_17 . V_65 , V_12 -> V_17 . V_66 ) ;
F_32 ( L_11 , V_12 -> V_17 . V_67 ) ;
for ( V_49 = 0 ; V_49 < V_12 -> V_17 . V_67 ; ++ V_49 )
F_32 ( L_12 ,
V_12 -> V_17 . V_68 [ V_49 ] . V_69 , V_12 -> V_17 . V_68 [ V_49 ] . V_70 ) ;
F_32 ( L_13 ,
V_12 -> V_17 . V_26 -> V_71 , V_12 -> V_72 -> V_17 . V_73 ,
V_12 -> V_17 . V_74 ) ;
}
static struct V_11 * F_34 ( struct V_72 * V_72 , int V_75 )
{
struct V_11 * V_76 ;
F_35 ( & V_72 -> V_48 ) ;
V_76 = F_36 ( V_72 , V_75 ) ;
F_37 ( & V_72 -> V_48 ) ;
return V_76 ;
}
static void F_38 ( struct V_11 * V_12 , struct V_77 * V_78 )
{
V_78 -> V_79 |= V_80 ;
V_78 -> V_81 = F_39 ( 1 ) ;
}
static int F_40 ( struct V_11 * V_12 , struct V_82 * V_83 ,
unsigned long V_84 , unsigned long V_85 )
{
if ( V_84 & ( V_86 - 1 ) )
return - V_47 ;
F_29 ( & V_12 -> V_17 . V_87 ) ;
if ( V_83 -> V_88 != V_84 || V_83 -> V_85 != V_85 ) {
V_83 -> V_88 = V_84 ;
V_83 -> V_85 = V_84 ? V_85 : 0 ;
V_83 -> V_89 = 1 ;
}
F_30 ( & V_12 -> V_17 . V_87 ) ;
return 0 ;
}
static int F_41 ( struct V_82 * V_90 )
{
if ( V_90 -> V_89 )
return V_90 -> V_88 != 0 ;
return V_90 -> V_91 != NULL ;
}
static unsigned long F_42 ( struct V_11 * V_12 ,
unsigned long V_21 ,
unsigned long V_92 , unsigned long V_78 )
{
struct V_72 * V_72 = V_12 -> V_72 ;
unsigned long V_85 , V_93 ;
void * V_94 ;
struct V_11 * V_95 ;
int V_96 ;
int V_97 ;
struct V_82 * V_90 ;
V_95 = F_34 ( V_72 , V_92 ) ;
if ( ! V_95 )
return V_98 ;
V_97 = ( V_21 >> V_99 ) & V_100 ;
if ( V_97 == V_101 || V_97 == V_102 ||
V_97 == V_103 ) {
if ( ( V_78 & ( V_86 - 1 ) ) || ! V_78 )
return V_98 ;
V_94 = F_43 ( V_72 , V_78 , & V_93 ) ;
if ( V_94 == NULL )
return V_98 ;
if ( V_97 == V_101 )
V_85 = F_44 ( ( (struct V_104 * ) V_94 ) -> V_105 . V_106 ) ;
else
V_85 = F_45 ( ( (struct V_104 * ) V_94 ) -> V_105 . V_107 ) ;
F_46 ( V_72 , V_94 , V_78 , false ) ;
if ( V_85 > V_93 || V_85 < sizeof( struct V_104 ) )
return V_98 ;
} else {
V_78 = 0 ;
V_85 = 0 ;
}
V_96 = V_98 ;
V_90 = NULL ;
F_29 ( & V_95 -> V_17 . V_87 ) ;
switch ( V_97 ) {
case V_101 :
if ( V_85 < sizeof( struct V_77 ) )
break;
V_90 = & V_95 -> V_17 . V_78 ;
V_96 = 0 ;
break;
case V_102 :
if ( V_85 < sizeof( struct V_108 ) )
break;
V_85 -= V_85 % sizeof( struct V_108 ) ;
V_96 = V_109 ;
if ( ! F_41 ( & V_95 -> V_17 . V_78 ) )
break;
V_90 = & V_95 -> V_17 . V_110 ;
V_96 = 0 ;
break;
case V_103 :
V_96 = V_109 ;
if ( ! F_41 ( & V_95 -> V_17 . V_78 ) )
break;
V_90 = & V_95 -> V_17 . V_111 ;
V_96 = 0 ;
break;
case V_112 :
V_96 = V_109 ;
if ( F_41 ( & V_95 -> V_17 . V_110 ) ||
F_41 ( & V_95 -> V_17 . V_111 ) )
break;
V_90 = & V_95 -> V_17 . V_78 ;
V_96 = 0 ;
break;
case V_113 :
V_90 = & V_95 -> V_17 . V_110 ;
V_96 = 0 ;
break;
case V_114 :
V_90 = & V_95 -> V_17 . V_111 ;
V_96 = 0 ;
break;
}
if ( V_90 ) {
V_90 -> V_88 = V_78 ;
V_90 -> V_85 = V_85 ;
V_90 -> V_89 = 1 ;
}
F_30 ( & V_95 -> V_17 . V_87 ) ;
return V_96 ;
}
static void F_47 ( struct V_11 * V_12 , struct V_82 * V_90 )
{
struct V_72 * V_72 = V_12 -> V_72 ;
void * V_94 ;
unsigned long V_93 ;
unsigned long V_115 ;
for (; ; ) {
V_115 = V_90 -> V_88 ;
F_30 ( & V_12 -> V_17 . V_87 ) ;
V_94 = NULL ;
V_93 = 0 ;
if ( V_115 )
V_94 = F_43 ( V_72 , V_115 , & V_93 ) ;
F_29 ( & V_12 -> V_17 . V_87 ) ;
if ( V_115 == V_90 -> V_88 )
break;
if ( V_94 )
F_46 ( V_72 , V_94 , V_115 , false ) ;
}
V_90 -> V_89 = 0 ;
if ( V_94 && V_93 < V_90 -> V_85 ) {
F_46 ( V_72 , V_94 , V_115 , false ) ;
V_94 = NULL ;
}
if ( V_90 -> V_91 )
F_46 ( V_72 , V_90 -> V_91 , V_90 -> V_115 ,
V_90 -> V_116 ) ;
V_90 -> V_115 = V_115 ;
V_90 -> V_91 = V_94 ;
V_90 -> V_116 = false ;
if ( V_94 )
V_90 -> V_117 = V_94 + V_90 -> V_85 ;
}
static void F_48 ( struct V_11 * V_12 )
{
if ( ! ( V_12 -> V_17 . V_78 . V_89 ||
V_12 -> V_17 . V_111 . V_89 ||
V_12 -> V_17 . V_110 . V_89 ) )
return;
F_29 ( & V_12 -> V_17 . V_87 ) ;
if ( V_12 -> V_17 . V_78 . V_89 ) {
F_47 ( V_12 , & V_12 -> V_17 . V_78 ) ;
if ( V_12 -> V_17 . V_78 . V_91 )
F_38 ( V_12 , V_12 -> V_17 . V_78 . V_91 ) ;
}
if ( V_12 -> V_17 . V_110 . V_89 ) {
F_47 ( V_12 , & V_12 -> V_17 . V_110 ) ;
V_12 -> V_17 . V_118 = V_12 -> V_17 . V_110 . V_91 ;
V_12 -> V_17 . V_119 = 0 ;
}
if ( V_12 -> V_17 . V_111 . V_89 )
F_47 ( V_12 , & V_12 -> V_17 . V_111 ) ;
F_30 ( & V_12 -> V_17 . V_87 ) ;
}
static T_1 F_49 ( struct V_19 * V_20 , T_1 V_120 )
{
T_1 V_121 ;
unsigned long V_21 ;
F_19 ( & V_20 -> V_22 , V_21 ) ;
V_121 = V_20 -> V_25 ;
if ( V_20 -> V_28 != V_122 &&
V_20 -> V_23 != V_24 )
V_121 += V_120 - V_20 -> V_23 ;
F_21 ( & V_20 -> V_22 , V_21 ) ;
return V_121 ;
}
static void F_50 ( struct V_11 * V_12 ,
struct V_19 * V_20 )
{
struct V_108 * V_123 ;
struct V_77 * V_78 ;
unsigned long V_124 ;
unsigned long V_125 ;
T_1 V_120 ;
V_123 = V_12 -> V_17 . V_118 ;
V_78 = V_12 -> V_17 . V_78 . V_91 ;
V_120 = F_20 () ;
V_125 = F_49 ( V_20 , V_120 ) ;
V_124 = V_125 - V_12 -> V_17 . V_126 ;
V_12 -> V_17 . V_126 = V_125 ;
F_51 ( & V_12 -> V_17 . V_30 ) ;
V_124 += V_12 -> V_17 . V_34 ;
V_12 -> V_17 . V_34 = 0 ;
F_52 ( & V_12 -> V_17 . V_30 ) ;
if ( ! V_123 || ! V_78 )
return;
memset ( V_123 , 0 , sizeof( struct V_108 ) ) ;
V_123 -> V_127 = 7 ;
V_123 -> V_128 = F_53 ( V_20 -> V_129 + V_12 -> V_17 . V_130 ) ;
V_123 -> V_131 = F_54 ( V_120 + V_20 -> V_132 ) ;
V_123 -> V_133 = F_39 ( V_124 ) ;
V_123 -> V_55 = F_54 ( F_55 ( V_12 ) ) ;
V_123 -> V_56 = F_54 ( V_12 -> V_17 . V_37 . V_35 ) ;
++ V_123 ;
if ( V_123 == V_12 -> V_17 . V_110 . V_117 )
V_123 = V_12 -> V_17 . V_110 . V_91 ;
V_12 -> V_17 . V_118 = V_123 ;
F_56 () ;
V_78 -> V_134 = F_54 ( ++ V_12 -> V_17 . V_119 ) ;
V_12 -> V_17 . V_110 . V_116 = true ;
}
static bool F_57 ( struct V_11 * V_12 )
{
if ( V_12 -> V_17 . V_26 -> V_39 >= V_46 )
return true ;
if ( ( ! V_12 -> V_17 . V_26 -> V_39 ) &&
F_2 ( V_2 ) )
return true ;
return false ;
}
static int F_58 ( struct V_11 * V_12 , unsigned long V_135 ,
unsigned long V_136 , unsigned long V_137 ,
unsigned long V_138 )
{
switch ( V_136 ) {
case V_139 :
if ( ! F_57 ( V_12 ) )
return V_140 ;
if ( V_138 )
return V_141 ;
if ( V_135 )
return V_142 ;
if ( ( V_137 & V_143 ) == V_144 )
return V_145 ;
V_12 -> V_17 . V_146 = V_137 ;
return V_147 ;
case V_148 :
if ( ! F_57 ( V_12 ) )
return V_140 ;
if ( V_135 )
return V_142 ;
if ( V_138 & V_149 )
return V_141 ;
V_12 -> V_17 . V_150 = V_137 ;
V_12 -> V_17 . V_151 = V_138 ;
return V_147 ;
default:
return V_152 ;
}
}
static int F_59 ( struct V_11 * V_153 )
{
struct V_19 * V_26 = V_153 -> V_17 . V_26 ;
F_29 ( & V_26 -> V_48 ) ;
if ( V_153 -> V_17 . V_31 == V_154 &&
V_26 -> V_28 != V_122 &&
V_26 -> V_27 )
V_153 = V_26 -> V_27 ;
F_30 ( & V_26 -> V_48 ) ;
return F_60 ( V_153 ) ;
}
static int F_61 ( struct V_11 * V_12 )
{
int V_81 = 0 ;
struct V_77 * V_77 ;
F_29 ( & V_12 -> V_17 . V_87 ) ;
V_77 = (struct V_77 * ) V_12 -> V_17 . V_78 . V_91 ;
if ( V_77 )
V_81 = F_45 ( V_77 -> V_81 ) ;
F_30 ( & V_12 -> V_17 . V_87 ) ;
return V_81 ;
}
int F_62 ( struct V_11 * V_12 )
{
unsigned long V_155 = F_33 ( V_12 , 3 ) ;
unsigned long V_153 , V_76 = V_147 ;
int V_81 ;
struct V_11 * V_95 ;
int V_156 , V_157 ;
if ( V_155 <= V_158 &&
! F_63 ( V_155 / 4 , V_12 -> V_72 -> V_17 . V_159 ) )
return V_160 ;
switch ( V_155 ) {
case V_161 :
break;
case V_162 :
V_153 = F_33 ( V_12 , 4 ) ;
V_95 = F_34 ( V_12 -> V_72 , V_153 ) ;
if ( ! V_95 ) {
V_76 = V_98 ;
break;
}
V_95 -> V_17 . V_163 = 1 ;
F_8 () ;
if ( V_12 -> V_17 . V_164 ) {
if ( F_14 ( & V_12 -> V_165 ) ) {
F_15 ( & V_12 -> V_165 ) ;
V_12 -> V_15 . V_16 ++ ;
}
}
break;
case V_166 :
V_153 = F_33 ( V_12 , 4 ) ;
if ( V_153 == - 1 )
break;
V_95 = F_34 ( V_12 -> V_72 , V_153 ) ;
if ( ! V_95 ) {
V_76 = V_98 ;
break;
}
V_81 = F_33 ( V_12 , 5 ) ;
if ( F_61 ( V_95 ) != V_81 )
break;
F_59 ( V_95 ) ;
break;
case V_167 :
V_76 = F_42 ( V_12 , F_33 ( V_12 , 4 ) ,
F_33 ( V_12 , 5 ) ,
F_33 ( V_12 , 6 ) ) ;
break;
case V_168 :
if ( F_64 ( & V_12 -> V_72 -> V_17 . V_169 ) )
return V_160 ;
V_156 = F_65 ( & V_12 -> V_72 -> V_170 ) ;
V_157 = F_66 ( V_12 ) ;
F_67 ( & V_12 -> V_72 -> V_170 , V_156 ) ;
if ( V_157 == - V_171 )
return V_160 ;
else if ( V_157 == 0 )
break;
return V_157 ;
case V_172 :
V_76 = F_68 ( V_12 ) ;
if ( V_76 == V_152 )
return V_160 ;
break;
case V_173 :
V_76 = F_69 ( V_12 ) ;
if ( V_76 == V_152 )
return V_160 ;
break;
case V_174 :
V_76 = F_58 ( V_12 , F_33 ( V_12 , 4 ) ,
F_33 ( V_12 , 5 ) ,
F_33 ( V_12 , 6 ) ,
F_33 ( V_12 , 7 ) ) ;
if ( V_76 == V_152 )
return V_160 ;
break;
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
if ( F_70 ( V_12 ) ) {
V_76 = F_71 ( V_12 , V_155 ) ;
break;
}
return V_160 ;
case V_181 :
V_76 = F_72 ( V_12 , F_33 ( V_12 , 4 ) ,
F_33 ( V_12 , 5 ) ,
F_33 ( V_12 , 6 ) ) ;
if ( V_76 == V_152 )
return V_160 ;
break;
case V_182 :
V_76 = F_73 ( V_12 , F_33 ( V_12 , 4 ) ,
F_33 ( V_12 , 5 ) ,
F_33 ( V_12 , 6 ) ,
F_33 ( V_12 , 7 ) ) ;
if ( V_76 == V_152 )
return V_160 ;
break;
case V_183 :
V_76 = F_74 ( V_12 , F_33 ( V_12 , 4 ) ,
F_33 ( V_12 , 5 ) ,
F_33 ( V_12 , 6 ) ,
F_33 ( V_12 , 7 ) ) ;
if ( V_76 == V_152 )
return V_160 ;
break;
default:
return V_160 ;
}
F_75 ( V_12 , 3 , V_76 ) ;
V_12 -> V_17 . V_184 = 0 ;
return V_185 ;
}
static int F_76 ( unsigned long V_186 )
{
switch ( V_186 ) {
case V_161 :
case V_162 :
case V_166 :
case V_167 :
case V_174 :
case V_172 :
case V_173 :
#ifdef F_77
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
#endif
return 1 ;
}
return F_78 ( V_186 ) ;
}
static int F_79 ( struct V_187 * V_188 ,
struct V_11 * V_12 )
{
T_2 V_74 ;
if ( F_80 ( V_12 , V_189 , & V_74 ) !=
V_190 ) {
return V_185 ;
}
if ( V_74 == V_191 ) {
V_188 -> V_192 = V_193 ;
V_188 -> V_194 . V_17 . V_195 = F_55 ( V_12 ) ;
return V_160 ;
} else {
F_81 ( V_12 , V_196 ) ;
return V_185 ;
}
}
static int F_82 ( struct V_187 * V_188 , struct V_11 * V_12 ,
struct V_197 * V_198 )
{
int V_49 = V_160 ;
V_12 -> V_15 . V_199 ++ ;
if ( V_12 -> V_17 . V_37 . V_35 & V_200 ) {
F_83 ( V_201 L_14 ) ;
F_83 ( V_201 L_15 ,
V_12 -> V_17 . V_52 , F_55 ( V_12 ) ,
V_12 -> V_17 . V_37 . V_35 ) ;
F_31 ( V_12 ) ;
V_188 -> V_192 = V_202 ;
V_188 -> V_203 . V_204 = V_12 -> V_17 . V_52 ;
return V_160 ;
}
V_188 -> V_192 = V_205 ;
V_188 -> V_206 = 1 ;
switch ( V_12 -> V_17 . V_52 ) {
case V_207 :
V_12 -> V_15 . V_208 ++ ;
V_49 = V_185 ;
break;
case V_209 :
case V_210 :
V_12 -> V_15 . V_211 ++ ;
V_49 = V_185 ;
break;
case V_212 :
case V_213 :
V_49 = V_185 ;
break;
case V_214 :
F_84 ( V_12 ,
V_214 ) ;
V_49 = V_185 ;
break;
case V_215 :
{
T_3 V_21 ;
V_21 = V_12 -> V_17 . V_37 . V_35 & 0x1f0000ull ;
F_81 ( V_12 , V_21 ) ;
V_49 = V_185 ;
break;
}
case V_216 :
{
int V_217 ;
V_188 -> V_218 . V_219 = F_33 ( V_12 , 3 ) ;
for ( V_217 = 0 ; V_217 < 9 ; ++ V_217 )
V_188 -> V_218 . args [ V_217 ] = F_33 ( V_12 , 4 + V_217 ) ;
V_188 -> V_192 = V_220 ;
V_12 -> V_17 . V_184 = 1 ;
V_49 = V_160 ;
break;
}
case V_221 :
V_49 = V_222 ;
break;
case V_223 :
V_12 -> V_17 . V_65 = F_55 ( V_12 ) ;
V_12 -> V_17 . V_66 = 0 ;
V_49 = V_222 ;
break;
case V_224 :
if ( V_12 -> V_17 . V_225 != V_226 )
V_12 -> V_17 . V_74 = F_85 ( V_12 ) ?
F_86 ( V_12 -> V_17 . V_225 ) :
V_12 -> V_17 . V_225 ;
if ( V_12 -> V_227 & V_228 ) {
V_49 = F_79 ( V_188 , V_12 ) ;
} else {
F_81 ( V_12 , V_196 ) ;
V_49 = V_185 ;
}
break;
case V_229 :
F_81 ( V_12 , V_196 ) ;
V_49 = V_185 ;
break;
default:
F_31 ( V_12 ) ;
F_83 ( V_201 L_15 ,
V_12 -> V_17 . V_52 , F_55 ( V_12 ) ,
V_12 -> V_17 . V_37 . V_35 ) ;
V_188 -> V_203 . V_204 = V_12 -> V_17 . V_52 ;
V_49 = V_160 ;
break;
}
return V_49 ;
}
static int F_87 ( struct V_11 * V_12 ,
struct V_230 * V_231 )
{
int V_217 ;
memset ( V_231 , 0 , sizeof( struct V_230 ) ) ;
V_231 -> V_38 = V_12 -> V_17 . V_38 ;
for ( V_217 = 0 ; V_217 < V_12 -> V_17 . V_67 ; V_217 ++ ) {
V_231 -> V_232 . V_233 . V_234 . V_68 [ V_217 ] . V_235 = V_12 -> V_17 . V_68 [ V_217 ] . V_69 ;
V_231 -> V_232 . V_233 . V_234 . V_68 [ V_217 ] . V_236 = V_12 -> V_17 . V_68 [ V_217 ] . V_70 ;
}
return 0 ;
}
static int F_88 ( struct V_11 * V_12 ,
struct V_230 * V_231 )
{
int V_217 , V_237 ;
if ( V_231 -> V_38 != V_12 -> V_17 . V_38 )
return - V_47 ;
V_237 = 0 ;
for ( V_217 = 0 ; V_217 < V_12 -> V_17 . V_238 ; V_217 ++ ) {
if ( V_231 -> V_232 . V_233 . V_234 . V_68 [ V_217 ] . V_235 & V_239 ) {
V_12 -> V_17 . V_68 [ V_237 ] . V_69 = V_231 -> V_232 . V_233 . V_234 . V_68 [ V_217 ] . V_235 ;
V_12 -> V_17 . V_68 [ V_237 ] . V_70 = V_231 -> V_232 . V_233 . V_234 . V_68 [ V_217 ] . V_236 ;
++ V_237 ;
}
}
V_12 -> V_17 . V_67 = V_237 ;
return 0 ;
}
static void F_89 ( struct V_11 * V_12 , T_1 V_240 ,
bool V_241 )
{
struct V_72 * V_72 = V_12 -> V_72 ;
struct V_19 * V_20 = V_12 -> V_17 . V_26 ;
T_1 V_242 ;
F_35 ( & V_72 -> V_48 ) ;
F_29 ( & V_20 -> V_48 ) ;
if ( ( V_240 & V_243 ) != ( V_20 -> V_71 & V_243 ) ) {
struct V_11 * V_12 ;
int V_217 ;
F_90 (i, vcpu, kvm) {
if ( V_12 -> V_17 . V_26 != V_20 )
continue;
if ( V_240 & V_243 )
V_12 -> V_17 . V_244 |= V_245 ;
else
V_12 -> V_17 . V_244 &= ~ V_245 ;
}
}
V_242 = V_246 | V_243 | V_247 ;
if ( F_2 ( V_2 ) )
V_242 |= V_248 ;
if ( V_241 )
V_242 &= 0xFFFFFFFF ;
V_20 -> V_71 = ( V_20 -> V_71 & ~ V_242 ) | ( V_240 & V_242 ) ;
F_30 ( & V_20 -> V_48 ) ;
F_37 ( & V_72 -> V_48 ) ;
}
static int F_91 ( struct V_11 * V_12 , T_1 V_75 ,
union V_249 * V_250 )
{
int V_49 = 0 ;
long int V_217 ;
switch ( V_75 ) {
case V_251 :
* V_250 = F_92 ( V_75 , V_191 ) ;
break;
case V_252 :
* V_250 = F_92 ( V_75 , 0 ) ;
break;
case V_253 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_254 ) ;
break;
case V_255 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_256 ) ;
break;
case V_257 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_258 ) ;
break;
case V_259 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_260 ) ;
break;
case V_261 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_262 ) ;
break;
case V_263 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_264 ) ;
break;
case V_265 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_266 ) ;
break;
case V_267 ... V_268 :
V_217 = V_75 - V_267 ;
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_269 [ V_217 ] ) ;
break;
case V_270 ... V_271 :
V_217 = V_75 - V_270 ;
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_272 [ V_217 ] ) ;
break;
case V_273 ... V_274 :
V_217 = V_75 - V_273 ;
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_275 [ V_217 ] ) ;
break;
case V_276 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_277 ) ;
break;
case V_278 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_279 ) ;
break;
case V_280 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_281 ) ;
break;
case V_282 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_283 ) ;
break;
case V_284 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_285 ) ;
break;
case V_286 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_26 -> V_287 ) ;
break;
case V_288 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_150 ) ;
break;
case V_289 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_151 ) ;
break;
case V_290 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_146 ) ;
break;
case V_291 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_292 ) ;
break;
case V_293 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_294 ) ;
break;
case V_295 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_296 ) ;
break;
case V_297 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_298 ) ;
break;
case V_299 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_300 ) ;
break;
case V_301 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_302 ) ;
break;
case V_303 :
F_29 ( & V_12 -> V_17 . V_87 ) ;
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_78 . V_88 ) ;
F_30 ( & V_12 -> V_17 . V_87 ) ;
break;
case V_304 :
F_29 ( & V_12 -> V_17 . V_87 ) ;
V_250 -> V_305 . V_84 = V_12 -> V_17 . V_111 . V_88 ;
V_250 -> V_305 . V_105 = V_12 -> V_17 . V_111 . V_85 ;
F_30 ( & V_12 -> V_17 . V_87 ) ;
break;
case V_306 :
F_29 ( & V_12 -> V_17 . V_87 ) ;
V_250 -> V_305 . V_84 = V_12 -> V_17 . V_110 . V_88 ;
V_250 -> V_305 . V_105 = V_12 -> V_17 . V_110 . V_85 ;
F_30 ( & V_12 -> V_17 . V_87 ) ;
break;
case V_307 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_26 -> V_132 ) ;
break;
case V_308 :
case V_309 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_26 -> V_71 ) ;
break;
case V_310 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_311 ) ;
break;
#ifdef F_93
case V_312 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_313 ) ;
break;
case V_314 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_315 ) ;
break;
case V_316 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_317 ) ;
break;
case V_318 ... V_319 :
V_217 = V_75 - V_318 ;
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_320 [ V_217 ] ) ;
break;
case V_321 ... V_322 :
{
int V_237 ;
V_217 = V_75 - V_321 ;
if ( V_217 < 32 )
for ( V_237 = 0 ; V_237 < V_323 ; V_237 ++ )
V_250 -> V_324 [ V_237 ] = V_12 -> V_17 . V_325 . V_326 [ V_217 ] [ V_237 ] ;
else {
if ( F_2 ( V_327 ) )
V_250 -> V_328 = V_12 -> V_17 . V_329 . V_330 [ V_217 - 32 ] ;
else
V_49 = - V_331 ;
}
break;
}
case V_332 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_333 ) ;
break;
case V_334 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_335 ) ;
break;
case V_336 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_337 ) ;
break;
case V_338 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_325 . V_339 ) ;
break;
case V_340 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_341 ) ;
break;
case V_342 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_343 ) ;
break;
case V_344 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_345 ) ;
break;
case V_346 :
if ( F_2 ( V_327 ) )
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_329 . V_347 . V_232 [ 3 ] ) ;
else
V_49 = - V_331 ;
break;
case V_348 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_349 ) ;
break;
case V_350 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_351 ) ;
break;
#endif
case V_352 :
* V_250 = F_92 ( V_75 , V_12 -> V_17 . V_26 -> V_39 ) ;
break;
default:
V_49 = - V_47 ;
break;
}
return V_49 ;
}
static int F_94 ( struct V_11 * V_12 , T_1 V_75 ,
union V_249 * V_250 )
{
int V_49 = 0 ;
long int V_217 ;
unsigned long V_84 , V_85 ;
switch ( V_75 ) {
case V_252 :
if ( F_95 ( V_75 , * V_250 ) )
V_49 = - V_47 ;
break;
case V_253 :
V_12 -> V_17 . V_254 = F_95 ( V_75 , * V_250 ) ;
break;
case V_255 :
V_12 -> V_17 . V_256 = F_95 ( V_75 , * V_250 ) & ~ V_149 ;
break;
case V_257 :
V_12 -> V_17 . V_258 = F_95 ( V_75 , * V_250 ) ;
break;
case V_259 :
V_12 -> V_17 . V_260 = F_95 ( V_75 , * V_250 ) ;
break;
case V_261 :
V_12 -> V_17 . V_262 = F_95 ( V_75 , * V_250 ) ;
break;
case V_263 :
V_12 -> V_17 . V_264 = F_95 ( V_75 , * V_250 ) ;
break;
case V_265 :
V_12 -> V_17 . V_266 = F_95 ( V_75 , * V_250 ) ;
break;
case V_267 ... V_268 :
V_217 = V_75 - V_267 ;
V_12 -> V_17 . V_269 [ V_217 ] = F_95 ( V_75 , * V_250 ) ;
break;
case V_270 ... V_271 :
V_217 = V_75 - V_270 ;
V_12 -> V_17 . V_272 [ V_217 ] = F_95 ( V_75 , * V_250 ) ;
break;
case V_273 ... V_274 :
V_217 = V_75 - V_273 ;
V_12 -> V_17 . V_275 [ V_217 ] = F_95 ( V_75 , * V_250 ) ;
break;
case V_276 :
V_12 -> V_17 . V_277 = F_95 ( V_75 , * V_250 ) ;
break;
case V_278 :
V_12 -> V_17 . V_279 = F_95 ( V_75 , * V_250 ) ;
break;
case V_280 :
V_12 -> V_17 . V_281 = F_95 ( V_75 , * V_250 ) ;
break;
case V_282 :
V_12 -> V_17 . V_283 = F_95 ( V_75 , * V_250 ) ;
break;
case V_284 :
V_12 -> V_17 . V_285 = F_95 ( V_75 , * V_250 ) ;
break;
case V_286 :
V_12 -> V_17 . V_26 -> V_287 = F_95 ( V_75 , * V_250 ) ;
break;
case V_288 :
V_12 -> V_17 . V_150 = F_95 ( V_75 , * V_250 ) ;
break;
case V_289 :
V_12 -> V_17 . V_151 = F_95 ( V_75 , * V_250 ) & ~ V_353 ;
break;
case V_290 :
V_12 -> V_17 . V_146 = F_95 ( V_75 , * V_250 ) ;
if ( ( V_12 -> V_17 . V_146 & V_143 ) == V_144 )
V_12 -> V_17 . V_146 &= ~ V_143 ;
break;
case V_291 :
V_12 -> V_17 . V_292 = F_95 ( V_75 , * V_250 ) ;
break;
case V_293 :
V_12 -> V_17 . V_294 = F_95 ( V_75 , * V_250 ) ;
break;
case V_295 :
V_12 -> V_17 . V_296 = F_95 ( V_75 , * V_250 ) ;
break;
case V_297 :
V_12 -> V_17 . V_298 = F_95 ( V_75 , * V_250 ) ;
break;
case V_299 :
V_12 -> V_17 . V_300 = F_95 ( V_75 , * V_250 ) ;
break;
case V_301 :
V_12 -> V_17 . V_302 = F_95 ( V_75 , * V_250 ) ;
break;
case V_303 :
V_84 = F_95 ( V_75 , * V_250 ) ;
V_49 = - V_47 ;
if ( ! V_84 && ( V_12 -> V_17 . V_111 . V_88 ||
V_12 -> V_17 . V_110 . V_88 ) )
break;
V_49 = F_40 ( V_12 , & V_12 -> V_17 . V_78 , V_84 , sizeof( struct V_77 ) ) ;
break;
case V_304 :
V_84 = V_250 -> V_305 . V_84 ;
V_85 = V_250 -> V_305 . V_105 ;
V_49 = - V_47 ;
if ( V_84 && ! V_12 -> V_17 . V_78 . V_88 )
break;
V_49 = F_40 ( V_12 , & V_12 -> V_17 . V_111 , V_84 , V_85 ) ;
break;
case V_306 :
V_84 = V_250 -> V_305 . V_84 ;
V_85 = V_250 -> V_305 . V_105 ;
V_49 = - V_47 ;
if ( V_84 && ( V_85 < sizeof( struct V_108 ) ||
! V_12 -> V_17 . V_78 . V_88 ) )
break;
V_85 -= V_85 % sizeof( struct V_108 ) ;
V_49 = F_40 ( V_12 , & V_12 -> V_17 . V_110 , V_84 , V_85 ) ;
break;
case V_307 :
V_12 -> V_17 . V_26 -> V_132 =
F_96 ( F_95 ( V_75 , * V_250 ) , 1UL << 24 ) ;
break;
case V_308 :
F_89 ( V_12 , F_95 ( V_75 , * V_250 ) , true ) ;
break;
case V_309 :
F_89 ( V_12 , F_95 ( V_75 , * V_250 ) , false ) ;
break;
case V_310 :
V_12 -> V_17 . V_311 = F_95 ( V_75 , * V_250 ) ;
break;
#ifdef F_93
case V_312 :
V_12 -> V_17 . V_313 = F_95 ( V_75 , * V_250 ) ;
break;
case V_314 :
V_12 -> V_17 . V_315 = F_95 ( V_75 , * V_250 ) ;
break;
case V_316 :
V_12 -> V_17 . V_317 = F_95 ( V_75 , * V_250 ) ;
break;
case V_318 ... V_319 :
V_217 = V_75 - V_318 ;
V_12 -> V_17 . V_320 [ V_217 ] = F_95 ( V_75 , * V_250 ) ;
break;
case V_321 ... V_322 :
{
int V_237 ;
V_217 = V_75 - V_321 ;
if ( V_217 < 32 )
for ( V_237 = 0 ; V_237 < V_323 ; V_237 ++ )
V_12 -> V_17 . V_325 . V_326 [ V_217 ] [ V_237 ] = V_250 -> V_324 [ V_237 ] ;
else
if ( F_2 ( V_327 ) )
V_12 -> V_17 . V_329 . V_330 [ V_217 - 32 ] = V_250 -> V_328 ;
else
V_49 = - V_331 ;
break;
}
case V_332 :
V_12 -> V_17 . V_333 = F_95 ( V_75 , * V_250 ) ;
break;
case V_334 :
V_12 -> V_17 . V_335 = F_95 ( V_75 , * V_250 ) ;
break;
case V_336 :
V_12 -> V_17 . V_337 = F_95 ( V_75 , * V_250 ) ;
break;
case V_338 :
V_12 -> V_17 . V_325 . V_339 = F_95 ( V_75 , * V_250 ) ;
break;
case V_340 :
V_12 -> V_17 . V_341 = F_95 ( V_75 , * V_250 ) ;
break;
case V_342 :
V_12 -> V_17 . V_343 = F_95 ( V_75 , * V_250 ) ;
break;
case V_344 :
V_12 -> V_17 . V_345 = F_95 ( V_75 , * V_250 ) ;
break;
case V_346 :
if ( F_2 ( V_327 ) )
V_12 -> V_17 . V_330 . V_347 . V_232 [ 3 ] = F_95 ( V_75 , * V_250 ) ;
else
V_49 = - V_331 ;
break;
case V_348 :
V_12 -> V_17 . V_349 = F_95 ( V_75 , * V_250 ) ;
break;
case V_350 :
V_12 -> V_17 . V_351 = F_95 ( V_75 , * V_250 ) ;
break;
#endif
case V_352 :
V_49 = F_28 ( V_12 , F_95 ( V_75 , * V_250 ) ) ;
break;
default:
V_49 = - V_47 ;
break;
}
return V_49 ;
}
static struct V_19 * F_97 ( struct V_72 * V_72 , int V_354 )
{
struct V_19 * V_26 ;
V_26 = F_98 ( sizeof( struct V_19 ) , V_355 ) ;
if ( V_26 == NULL )
return NULL ;
F_99 ( & V_26 -> V_356 ) ;
F_100 ( & V_26 -> V_48 ) ;
F_100 ( & V_26 -> V_22 ) ;
F_101 ( & V_26 -> V_165 ) ;
V_26 -> V_23 = V_24 ;
V_26 -> V_71 = V_72 -> V_17 . V_71 ;
V_26 -> V_357 = V_354 * V_358 ;
V_26 -> V_72 = V_72 ;
F_99 ( & V_26 -> V_359 ) ;
return V_26 ;
}
static int F_102 ( struct V_360 * V_360 , struct V_361 * V_361 )
{
struct V_11 * V_12 = V_360 -> V_362 ;
struct V_363 * V_121 ;
V_121 = F_98 ( sizeof( * V_121 ) , V_355 ) ;
if ( ! V_121 )
return - V_364 ;
F_103 ( V_12 -> V_72 ) ;
V_121 -> V_12 = V_12 ;
V_361 -> V_365 = V_121 ;
return F_104 ( V_360 , V_361 ) ;
}
static int F_105 ( struct V_360 * V_360 , struct V_361 * V_361 )
{
struct V_363 * V_121 = V_361 -> V_365 ;
F_106 ( V_121 -> V_12 -> V_72 ) ;
F_107 ( V_121 ) ;
return 0 ;
}
static T_4 F_108 ( struct V_361 * V_361 , char T_5 * V_366 ,
T_6 V_85 , T_7 * V_367 )
{
struct V_363 * V_121 = V_361 -> V_365 ;
struct V_11 * V_12 = V_121 -> V_12 ;
char * V_233 , * V_368 ;
struct V_369 V_370 ;
T_1 V_371 ;
T_7 V_372 ;
T_4 V_373 ;
int V_217 , V_374 ;
bool V_375 ;
if ( ! V_121 -> V_376 ) {
V_233 = V_121 -> V_366 ;
V_368 = V_233 + sizeof( V_121 -> V_366 ) ;
for ( V_217 = 0 ; V_217 < V_377 ; ++ V_217 ) {
struct V_369 * V_378 ;
V_378 = (struct V_369 * )
( ( unsigned long ) V_12 + V_379 [ V_217 ] . V_380 ) ;
V_375 = false ;
for ( V_374 = 0 ; V_374 < 1000 ; ++ V_374 ) {
V_371 = V_378 -> V_381 ;
if ( ! ( V_371 & 1 ) ) {
F_109 () ;
V_370 = * V_378 ;
F_109 () ;
if ( V_371 == V_378 -> V_381 ) {
V_375 = true ;
break;
}
}
F_110 ( 1 ) ;
}
if ( ! V_375 )
snprintf ( V_233 , V_368 - V_233 , L_16 ,
V_379 [ V_217 ] . V_382 ) ;
else
snprintf ( V_233 , V_368 - V_233 ,
L_17 ,
V_379 [ V_217 ] . V_382 , V_371 / 2 ,
F_111 ( V_370 . V_383 ) ,
F_111 ( V_370 . V_384 ) ,
F_111 ( V_370 . V_385 ) ) ;
V_233 += strlen ( V_233 ) ;
}
V_121 -> V_376 = V_233 - V_121 -> V_366 ;
}
V_372 = * V_367 ;
if ( V_372 >= V_121 -> V_376 )
return 0 ;
if ( V_85 > V_121 -> V_376 - V_372 )
V_85 = V_121 -> V_376 - V_372 ;
V_373 = F_112 ( V_366 , V_121 -> V_366 + V_372 , V_85 ) ;
if ( V_373 ) {
if ( V_373 == V_85 )
return - V_386 ;
V_85 -= V_373 ;
}
* V_367 = V_372 + V_85 ;
return V_85 ;
}
static T_4 F_113 ( struct V_361 * V_361 , const char T_5 * V_366 ,
T_6 V_85 , T_7 * V_367 )
{
return - V_387 ;
}
static void F_114 ( struct V_11 * V_12 , unsigned int V_75 )
{
char V_366 [ 16 ] ;
struct V_72 * V_72 = V_12 -> V_72 ;
snprintf ( V_366 , sizeof( V_366 ) , L_18 , V_75 ) ;
if ( F_115 ( V_72 -> V_17 . V_388 ) )
return;
V_12 -> V_17 . V_388 = F_116 ( V_366 , V_72 -> V_17 . V_388 ) ;
if ( F_115 ( V_12 -> V_17 . V_388 ) )
return;
V_12 -> V_17 . V_389 =
F_117 ( L_19 , 0444 , V_12 -> V_17 . V_388 ,
V_12 , & V_390 ) ;
}
static void F_114 ( struct V_11 * V_12 , unsigned int V_75 )
{
}
static struct V_11 * F_118 ( struct V_72 * V_72 ,
unsigned int V_75 )
{
struct V_11 * V_12 ;
int V_96 = - V_47 ;
int V_354 ;
struct V_19 * V_26 ;
V_354 = V_75 / V_358 ;
if ( V_354 >= V_391 )
goto V_392;
V_96 = - V_364 ;
V_12 = F_119 ( V_393 , V_355 ) ;
if ( ! V_12 )
goto V_392;
V_96 = F_120 ( V_12 , V_72 , V_75 ) ;
if ( V_96 )
goto V_394;
V_12 -> V_17 . V_395 = & V_12 -> V_17 . V_37 ;
#ifdef F_121
#ifdef F_122
V_12 -> V_17 . V_396 = true ;
#else
V_12 -> V_17 . V_396 = false ;
#endif
#endif
V_12 -> V_17 . V_269 [ 0 ] = V_397 ;
V_12 -> V_17 . V_398 = V_399 ;
F_27 ( V_12 , F_123 ( V_400 ) ) ;
F_100 ( & V_12 -> V_17 . V_87 ) ;
F_100 ( & V_12 -> V_17 . V_30 ) ;
V_12 -> V_17 . V_33 = V_24 ;
V_12 -> V_17 . V_244 = V_401 | V_402 ;
F_124 ( V_12 ) ;
V_12 -> V_17 . V_31 = V_403 ;
F_125 ( & V_12 -> V_17 . V_404 ) ;
F_35 ( & V_72 -> V_48 ) ;
V_26 = V_72 -> V_17 . V_405 [ V_354 ] ;
if ( ! V_26 ) {
V_26 = F_97 ( V_72 , V_354 ) ;
V_72 -> V_17 . V_405 [ V_354 ] = V_26 ;
V_72 -> V_17 . V_406 ++ ;
}
F_37 ( & V_72 -> V_48 ) ;
if ( ! V_26 )
goto V_394;
F_29 ( & V_26 -> V_48 ) ;
++ V_26 -> V_407 ;
F_30 ( & V_26 -> V_48 ) ;
V_12 -> V_17 . V_26 = V_26 ;
V_12 -> V_17 . V_130 = V_12 -> V_50 - V_26 -> V_357 ;
V_12 -> V_17 . V_18 = - 1 ;
V_12 -> V_17 . V_408 = V_409 ;
F_126 ( V_12 ) ;
F_114 ( V_12 , V_75 ) ;
return V_12 ;
V_394:
F_127 ( V_393 , V_12 ) ;
V_392:
return F_128 ( V_96 ) ;
}
static void F_129 ( struct V_72 * V_72 , struct V_82 * V_78 )
{
if ( V_78 -> V_91 )
F_46 ( V_72 , V_78 -> V_91 , V_78 -> V_115 ,
V_78 -> V_116 ) ;
}
static void F_130 ( struct V_11 * V_12 )
{
F_29 ( & V_12 -> V_17 . V_87 ) ;
F_129 ( V_12 -> V_72 , & V_12 -> V_17 . V_110 ) ;
F_129 ( V_12 -> V_72 , & V_12 -> V_17 . V_111 ) ;
F_129 ( V_12 -> V_72 , & V_12 -> V_17 . V_78 ) ;
F_30 ( & V_12 -> V_17 . V_87 ) ;
F_131 ( V_12 ) ;
F_127 ( V_393 , V_12 ) ;
}
static int F_132 ( struct V_11 * V_12 )
{
return 1 ;
}
static void F_133 ( struct V_11 * V_12 )
{
unsigned long V_410 , V_120 ;
V_120 = F_134 () ;
if ( V_120 > V_12 -> V_17 . V_411 ) {
F_135 ( V_12 ) ;
F_136 ( V_12 ) ;
return;
}
V_410 = ( V_12 -> V_17 . V_411 - V_120 ) * V_412
/ V_413 ;
F_137 ( & V_12 -> V_17 . V_414 , F_138 ( 0 , V_410 ) ,
V_415 ) ;
V_12 -> V_17 . V_416 = 1 ;
}
static void F_26 ( struct V_11 * V_12 )
{
V_12 -> V_17 . V_164 = 0 ;
if ( V_12 -> V_17 . V_416 ) {
F_139 ( & V_12 -> V_17 . V_414 ) ;
V_12 -> V_17 . V_416 = 0 ;
}
}
static void F_140 ( struct V_19 * V_20 ,
struct V_11 * V_12 )
{
T_1 V_120 ;
if ( V_12 -> V_17 . V_31 != V_154 )
return;
F_51 ( & V_12 -> V_17 . V_30 ) ;
V_120 = F_20 () ;
V_12 -> V_17 . V_34 += F_49 ( V_20 , V_120 ) -
V_12 -> V_17 . V_126 ;
V_12 -> V_17 . V_33 = V_120 ;
V_12 -> V_17 . V_31 = V_32 ;
F_52 ( & V_12 -> V_17 . V_30 ) ;
-- V_20 -> V_417 ;
F_141 ( & V_12 -> V_17 . V_418 ) ;
}
static int F_142 ( int V_1 )
{
struct V_419 * V_420 ;
long V_421 = 10000 ;
V_420 = & V_8 [ V_1 ] ;
V_420 -> V_9 . V_11 = NULL ;
V_420 -> V_9 . V_422 = NULL ;
V_420 -> V_9 . V_423 = 0 ;
F_56 () ;
V_420 -> V_9 . V_424 = 1 ;
F_8 () ;
while ( V_420 -> V_9 . V_425 == V_426 ) {
if ( -- V_421 <= 0 ) {
F_32 ( L_20 , V_1 ) ;
return - V_427 ;
}
F_110 ( 1 ) ;
}
return 0 ;
}
static void F_143 ( int V_1 )
{
struct V_419 * V_420 ;
V_420 = & V_8 [ V_1 ] ;
V_420 -> V_9 . V_424 = 0 ;
V_420 -> V_9 . V_11 = NULL ;
V_420 -> V_9 . V_422 = NULL ;
V_420 -> V_9 . V_428 = NULL ;
}
static void F_144 ( struct V_11 * V_12 , struct V_19 * V_20 )
{
int V_1 ;
struct V_419 * V_420 ;
struct V_19 * V_429 = V_20 -> V_430 ;
V_1 = V_20 -> V_129 ;
if ( V_12 ) {
if ( V_12 -> V_17 . V_416 ) {
F_139 ( & V_12 -> V_17 . V_414 ) ;
V_12 -> V_17 . V_416 = 0 ;
}
V_1 += V_12 -> V_17 . V_130 ;
V_12 -> V_1 = V_429 -> V_129 ;
V_12 -> V_17 . V_18 = V_1 ;
}
V_420 = & V_8 [ V_1 ] ;
V_420 -> V_9 . V_11 = V_12 ;
V_420 -> V_9 . V_130 = V_1 - V_429 -> V_129 ;
F_56 () ;
V_420 -> V_9 . V_422 = V_429 ;
if ( V_1 != F_5 () )
F_1 ( V_1 ) ;
}
static void F_145 ( void )
{
int V_1 = F_5 () ;
int V_217 , V_374 ;
for ( V_374 = 0 ; V_374 < 1000000 ; ++ V_374 ) {
for ( V_217 = 1 ; V_217 < V_358 ; ++ V_217 )
if ( V_8 [ V_1 + V_217 ] . V_9 . V_422 )
break;
if ( V_217 == V_358 ) {
F_146 () ;
return;
}
F_147 () ;
}
F_146 () ;
for ( V_217 = 1 ; V_217 < V_358 ; ++ V_217 )
if ( V_8 [ V_1 + V_217 ] . V_9 . V_422 )
F_32 ( L_21 , V_1 + V_217 ) ;
}
static int F_148 ( void )
{
int V_1 = F_5 () ;
int V_431 ;
if ( F_149 ( V_1 ) )
return 0 ;
V_431 = 0 ;
while ( ++ V_431 < V_358 )
if ( F_16 ( V_1 + V_431 ) )
return 0 ;
for ( V_431 = 1 ; V_431 < V_358 ; ++ V_431 ) {
if ( F_142 ( V_1 + V_431 ) ) {
do {
F_143 ( V_1 + V_431 ) ;
} while ( -- V_431 > 0 );
return 0 ;
}
}
return 1 ;
}
static void F_150 ( void )
{
int V_1 ;
F_151 (cpu) {
struct V_432 * V_433 = & F_152 ( V_434 , V_1 ) ;
F_100 ( & V_433 -> V_48 ) ;
F_99 ( & V_433 -> V_435 ) ;
}
}
static void F_153 ( struct V_19 * V_20 )
{
struct V_432 * V_433 = F_154 ( & V_434 ) ;
V_20 -> V_28 = V_436 ;
V_20 -> V_129 = F_5 () ;
if ( V_20 -> V_407 < V_358 ) {
F_29 ( & V_433 -> V_48 ) ;
F_155 ( & V_20 -> V_359 , & V_433 -> V_435 ) ;
F_30 ( & V_433 -> V_48 ) ;
}
F_18 ( V_20 ) ;
}
static void F_156 ( struct V_19 * V_20 )
{
struct V_432 * V_433 ;
F_22 ( V_20 ) ;
if ( ! F_64 ( & V_20 -> V_359 ) ) {
V_433 = & F_152 ( V_434 , V_20 -> V_129 ) ;
F_29 ( & V_433 -> V_48 ) ;
F_157 ( & V_20 -> V_359 ) ;
F_30 ( & V_433 -> V_48 ) ;
}
V_20 -> V_28 = V_122 ;
}
static void F_158 ( struct V_437 * V_438 , struct V_19 * V_20 )
{
int V_439 ;
memset ( V_438 , 0 , sizeof( * V_438 ) ) ;
V_438 -> V_440 = 1 ;
V_438 -> V_441 = V_20 -> V_407 ;
V_438 -> V_442 = V_20 -> V_407 ;
V_438 -> V_443 [ 0 ] = V_20 -> V_407 ;
V_438 -> V_444 [ 0 ] = V_20 -> V_72 ;
for ( V_439 = 0 ; V_439 < V_445 ; ++ V_439 )
F_99 ( & V_438 -> V_446 [ V_439 ] ) ;
F_155 ( & V_20 -> V_359 , & V_438 -> V_446 [ 0 ] ) ;
}
static bool F_159 ( int V_440 , int V_447 )
{
if ( V_440 > 1 && V_358 < V_448 )
return false ;
if ( V_440 > V_445 )
return false ;
if ( V_440 > 1 ) {
if ( ! ( V_449 & 2 ) )
V_440 = 4 ;
if ( V_440 > 2 && ! ( V_449 & 4 ) )
return false ;
}
return V_440 * F_160 ( V_447 ) <= V_448 ;
}
static void F_161 ( struct V_19 * V_20 )
{
V_20 -> V_430 = V_20 ;
V_20 -> V_450 = 0 ;
V_20 -> V_451 = 0 ;
V_20 -> V_452 = 0 ;
V_20 -> V_453 = 0 ;
}
static bool F_162 ( struct V_437 * V_438 )
{
int V_439 , V_454 ;
int V_455 = - 1 ;
int V_431 ;
int V_440 = V_438 -> V_440 ;
struct V_19 * V_20 , * V_456 ;
struct V_19 * V_457 = NULL ;
for ( V_439 = 0 ; V_439 < V_438 -> V_440 ; ++ V_439 ) {
if ( V_438 -> V_443 [ V_439 ] <= 2 )
continue;
if ( V_455 >= 0 )
return false ;
V_455 = V_439 ;
V_20 = F_163 ( & V_438 -> V_446 [ V_439 ] , struct V_19 ,
V_359 ) ;
if ( V_20 -> V_407 > 2 )
return false ;
V_440 += ( V_438 -> V_443 [ V_439 ] - 1 ) >> 1 ;
}
if ( V_455 < 0 || ! F_159 ( V_440 + 1 , 2 ) )
return false ;
V_454 = V_438 -> V_440 ;
V_431 = 0 ;
V_439 = V_455 ;
F_164 (vc, vcnext, &cip->vcs[sub], preempt_list) {
if ( V_431 >= 2 ) {
F_141 ( & V_20 -> V_359 ) ;
F_155 ( & V_20 -> V_359 , & V_438 -> V_446 [ V_454 ] ) ;
if ( ++ V_438 -> V_443 [ V_454 ] == 1 ) {
V_438 -> V_444 [ V_454 ] = V_20 -> V_72 ;
F_161 ( V_20 ) ;
V_457 = V_20 ;
++ V_438 -> V_440 ;
} else {
V_20 -> V_430 = V_457 ;
++ V_454 ;
}
}
V_431 += V_20 -> V_407 ;
}
V_438 -> V_443 [ V_455 ] = 2 ;
V_438 -> V_441 = 2 ;
return true ;
}
static bool F_165 ( struct V_19 * V_20 , struct V_437 * V_438 )
{
int V_447 = V_20 -> V_407 ;
int V_439 ;
if ( ! F_2 ( V_2 ) )
return false ;
if ( V_447 < V_438 -> V_441 )
V_447 = V_438 -> V_441 ;
if ( F_159 ( V_438 -> V_440 + 1 , V_447 ) ) {
V_438 -> V_441 = V_447 ;
} else if ( V_438 -> V_440 <= 2 && V_438 -> V_442 <= 6 &&
V_20 -> V_407 <= 2 ) {
if ( ! F_162 ( V_438 ) )
return false ;
} else {
return false ;
}
V_439 = V_438 -> V_440 ;
++ V_438 -> V_440 ;
V_438 -> V_442 += V_20 -> V_407 ;
V_438 -> V_443 [ V_439 ] = V_20 -> V_407 ;
V_438 -> V_444 [ V_439 ] = V_20 -> V_72 ;
F_161 ( V_20 ) ;
F_141 ( & V_20 -> V_359 ) ;
F_155 ( & V_20 -> V_359 , & V_438 -> V_446 [ V_439 ] ) ;
return true ;
}
static bool F_166 ( struct V_19 * V_458 ,
struct V_437 * V_438 , int V_439 )
{
struct V_19 * V_20 ;
int V_459 ;
V_20 = F_163 ( & V_438 -> V_446 [ V_439 ] , struct V_19 ,
V_359 ) ;
if ( V_458 -> V_72 != V_20 -> V_72 ||
V_458 -> V_132 != V_20 -> V_132 ||
V_458 -> V_40 != V_20 -> V_40 ||
V_458 -> V_71 != V_20 -> V_71 )
return false ;
if ( F_2 ( V_2 ) &&
( V_20 -> V_407 > 1 || V_458 -> V_407 > 1 ) )
return false ;
V_459 = V_438 -> V_443 [ V_439 ] + V_458 -> V_407 ;
if ( V_459 > V_438 -> V_441 ) {
if ( ! F_159 ( V_438 -> V_440 , V_459 ) )
return false ;
V_438 -> V_441 = V_459 ;
}
V_438 -> V_442 += V_458 -> V_407 ;
V_438 -> V_443 [ V_439 ] = V_459 ;
V_458 -> V_430 = V_20 ;
F_141 ( & V_458 -> V_359 ) ;
F_155 ( & V_458 -> V_359 , & V_438 -> V_446 [ V_439 ] ) ;
return true ;
}
static bool F_167 ( struct V_19 * V_458 , struct V_437 * V_438 ,
int V_460 )
{
int V_439 ;
if ( V_438 -> V_442 + V_458 -> V_407 > V_460 )
return false ;
for ( V_439 = 0 ; V_439 < V_438 -> V_440 ; ++ V_439 )
if ( V_438 -> V_443 [ V_439 ] &&
F_166 ( V_458 , V_438 , V_439 ) )
return true ;
if ( F_165 ( V_458 , V_438 ) )
return true ;
return false ;
}
static void F_168 ( struct V_19 * V_20 )
{
struct V_11 * V_12 , * V_461 ;
F_164 (vcpu, vnext, &vc->runnable_threads,
arch.run_list) {
if ( F_169 ( V_12 -> V_17 . V_462 ) )
V_12 -> V_17 . V_76 = - V_463 ;
else if ( V_12 -> V_17 . V_78 . V_89 ||
V_12 -> V_17 . V_111 . V_89 ||
V_12 -> V_17 . V_110 . V_89 )
V_12 -> V_17 . V_76 = V_185 ;
else
continue;
F_140 ( V_20 , V_12 ) ;
F_170 ( & V_12 -> V_17 . V_404 ) ;
}
}
static void F_171 ( struct V_437 * V_438 , int V_460 )
{
struct V_432 * V_433 = F_154 ( & V_434 ) ;
struct V_19 * V_458 , * V_456 ;
F_29 ( & V_433 -> V_48 ) ;
F_164 (pvc, vcnext, &lp->list, preempt_list) {
if ( ! F_172 ( & V_458 -> V_48 ) )
continue;
F_168 ( V_458 ) ;
if ( ! V_458 -> V_417 ) {
F_157 ( & V_458 -> V_359 ) ;
if ( V_458 -> V_27 == NULL ) {
V_458 -> V_28 = V_122 ;
F_22 ( V_458 ) ;
}
F_30 ( & V_458 -> V_48 ) ;
continue;
}
if ( ! F_167 ( V_458 , V_438 , V_460 ) ) {
F_30 ( & V_458 -> V_48 ) ;
continue;
}
F_22 ( V_458 ) ;
V_458 -> V_28 = V_464 ;
if ( V_438 -> V_442 >= V_460 )
break;
}
F_30 ( & V_433 -> V_48 ) ;
}
static void F_173 ( struct V_19 * V_20 , bool V_465 )
{
int V_466 = 0 ;
T_1 V_120 ;
long V_76 ;
struct V_11 * V_12 , * V_461 ;
F_29 ( & V_20 -> V_48 ) ;
V_120 = F_134 () ;
F_164 (vcpu, vnext, &vc->runnable_threads,
arch.run_list) {
if ( V_120 < V_12 -> V_17 . V_411 &&
F_174 ( V_12 ) )
F_175 ( V_12 ) ;
F_176 ( V_12 ) ;
V_76 = V_185 ;
if ( V_12 -> V_17 . V_52 )
V_76 = F_82 ( V_12 -> V_17 . V_187 , V_12 ,
V_12 -> V_17 . V_462 ) ;
V_12 -> V_17 . V_76 = V_76 ;
V_12 -> V_17 . V_52 = 0 ;
if ( F_177 ( V_12 -> V_17 . V_76 ) ) {
if ( V_12 -> V_17 . V_467 )
F_136 ( V_12 ) ;
if ( V_12 -> V_17 . V_164 )
F_133 ( V_12 ) ;
else
++ V_466 ;
} else {
F_140 ( V_20 , V_12 ) ;
F_170 ( & V_12 -> V_17 . V_404 ) ;
}
}
F_157 ( & V_20 -> V_359 ) ;
if ( ! V_465 ) {
if ( V_466 > 0 ) {
F_153 ( V_20 ) ;
} else if ( V_20 -> V_27 ) {
V_20 -> V_28 = V_436 ;
F_18 ( V_20 ) ;
} else {
V_20 -> V_28 = V_122 ;
}
if ( V_20 -> V_417 > 0 && V_20 -> V_27 == NULL ) {
V_12 = F_163 ( & V_20 -> V_356 ,
struct V_11 , V_17 . V_418 ) ;
F_170 ( & V_12 -> V_17 . V_404 ) ;
}
}
F_30 ( & V_20 -> V_48 ) ;
}
static inline void F_178 ( int V_1 )
{
int V_354 ;
if ( ! V_468 || F_7 ( V_1 ) )
return;
V_354 = V_1 >> V_469 ;
V_468 -> V_470 [ V_354 ] . V_471 . V_472 = 0 ;
}
static inline void F_179 ( int V_1 )
{
int V_354 ;
if ( ! V_468 || F_7 ( V_1 ) )
return;
V_354 = V_1 >> V_469 ;
V_468 -> V_470 [ V_354 ] . V_471 . V_472 = 1 ;
}
static T_8 void F_180 ( struct V_19 * V_20 )
{
struct V_11 * V_12 , * V_461 ;
int V_217 ;
int V_473 ;
struct V_437 V_437 ;
struct V_19 * V_458 , * V_456 ;
struct V_428 V_474 , * V_475 ;
int V_476 , V_477 , V_478 ;
int V_439 ;
bool V_479 ;
unsigned long V_480 , V_481 ;
int V_129 , V_431 ;
int V_460 ;
F_168 ( V_20 ) ;
if ( V_20 -> V_27 -> V_17 . V_31 != V_154 )
return;
F_161 ( V_20 ) ;
V_20 -> V_23 = V_24 ;
if ( ( V_482 > 1 ) &&
( ( V_20 -> V_407 > V_358 ) || ! F_148 () ) ) {
F_164 (vcpu, vnext, &vc->runnable_threads,
arch.run_list) {
V_12 -> V_17 . V_76 = - V_427 ;
F_140 ( V_20 , V_12 ) ;
F_170 ( & V_12 -> V_17 . V_404 ) ;
}
goto V_392;
}
F_158 ( & V_437 , V_20 ) ;
V_129 = F_5 () ;
V_460 = V_358 ;
if ( V_483 && V_483 < V_460 )
V_460 = V_483 ;
if ( V_20 -> V_407 < V_460 )
F_171 ( & V_437 , V_460 ) ;
V_477 = V_358 ;
V_480 = V_481 = 0 ;
V_476 = V_437 . V_440 ;
V_475 = NULL ;
if ( V_476 > 1 ) {
if ( V_476 == 2 && ( V_449 & 2 ) ) {
V_480 = V_484 ;
V_481 = V_485 ;
} else {
V_476 = 4 ;
V_480 = V_486 ;
V_481 = V_487 ;
}
V_477 = V_448 / V_476 ;
V_475 = & V_474 ;
memset ( & V_474 , 0 , sizeof( V_474 ) ) ;
V_474 . V_488 = F_123 ( V_489 ) ;
V_474 . V_490 = F_123 ( V_491 ) ;
V_474 . V_492 = F_123 ( V_493 ) ;
V_474 . V_477 = V_477 ;
for ( V_439 = 0 ; V_439 < V_437 . V_440 ; ++ V_439 )
V_474 . V_494 [ V_439 ] =
F_163 ( & V_437 . V_446 [ V_439 ] ,
struct V_19 , V_359 ) ;
F_56 () ;
}
V_129 = F_5 () ;
for ( V_431 = 0 ; V_431 < V_358 ; ++ V_431 )
V_8 [ V_129 + V_431 ] . V_9 . V_428 = V_475 ;
if ( V_480 ) {
unsigned long V_495 = F_123 ( V_496 ) ;
V_495 |= V_480 | V_497 ;
F_181 () ;
F_182 ( V_496 , V_495 ) ;
F_183 () ;
for (; ; ) {
V_495 = F_123 ( V_496 ) ;
if ( V_495 & V_481 )
break;
F_184 () ;
}
}
F_178 ( V_129 ) ;
V_478 = 0 ;
for ( V_439 = 0 ; V_439 < V_437 . V_440 ; ++ V_439 ) {
V_431 = V_498 [ V_439 ] ;
V_479 = false ;
V_478 |= 1 << V_431 ;
F_185 (pvc, &core_info.vcs[sub], preempt_list) {
V_458 -> V_129 = V_129 + V_431 ;
F_185 (vcpu, &pvc->runnable_threads,
arch.run_list) {
F_144 ( V_12 , V_458 ) ;
F_50 ( V_12 , V_458 ) ;
F_186 ( V_12 ) ;
if ( ! V_12 -> V_17 . V_130 )
V_479 = true ;
V_478 |= 1 << ( V_431 + V_12 -> V_17 . V_130 ) ;
}
if ( V_458 -> V_430 == V_458 && ! V_479 )
F_144 ( NULL , V_458 ) ;
V_431 += V_458 -> V_407 ;
}
}
F_8 () ;
if ( V_480 )
V_474 . V_499 = 1 ;
if ( V_476 > 1 )
for ( V_431 = 1 ; V_431 < V_358 ; ++ V_431 )
if ( ! ( V_478 & ( 1 << V_431 ) ) )
F_1 ( V_129 + V_431 ) ;
V_20 -> V_28 = V_500 ;
F_3 () ;
F_187 ( V_20 , 0 ) ;
for ( V_439 = 0 ; V_439 < V_437 . V_440 ; ++ V_439 )
F_185 (pvc, &core_info.vcs[sub], preempt_list)
F_30 ( & V_458 -> V_48 ) ;
F_188 () ;
V_473 = F_65 ( & V_20 -> V_72 -> V_170 ) ;
F_189 () ;
F_67 ( & V_20 -> V_72 -> V_170 , V_473 ) ;
F_29 ( & V_20 -> V_48 ) ;
V_20 -> V_28 = V_501 ;
F_145 () ;
if ( V_476 > 1 ) {
unsigned long V_495 = F_123 ( V_496 ) ;
unsigned long V_374 = 0 ;
V_495 &= ~ V_497 ;
V_481 = V_485 | V_487 ;
F_181 () ;
F_182 ( V_496 , V_495 ) ;
F_183 () ;
for (; ; ) {
V_495 = F_123 ( V_496 ) ;
if ( ! ( V_495 & V_481 ) )
break;
F_184 () ;
++ V_374 ;
}
V_474 . V_499 = 0 ;
}
for ( V_217 = 0 ; V_217 < V_358 ; ++ V_217 ) {
F_143 ( V_129 + V_217 ) ;
if ( V_475 && V_475 -> V_502 [ V_217 ] )
F_1 ( V_129 + V_217 ) ;
}
F_179 ( V_129 ) ;
F_30 ( & V_20 -> V_48 ) ;
F_8 () ;
F_190 () ;
for ( V_439 = 0 ; V_439 < V_437 . V_440 ; ++ V_439 )
F_164 (pvc, vcnext, &core_info.vcs[sub],
preempt_list)
F_173 ( V_458 , V_458 == V_20 ) ;
F_29 ( & V_20 -> V_48 ) ;
F_9 () ;
V_392:
V_20 -> V_28 = V_122 ;
F_187 ( V_20 , 1 ) ;
}
static void F_191 ( struct V_19 * V_20 ,
struct V_11 * V_12 , int V_503 )
{
F_192 ( V_504 ) ;
F_193 ( & V_12 -> V_17 . V_404 , & V_504 , V_503 ) ;
if ( V_12 -> V_17 . V_31 == V_154 ) {
F_30 ( & V_20 -> V_48 ) ;
F_194 () ;
F_29 ( & V_20 -> V_48 ) ;
}
F_195 ( & V_12 -> V_17 . V_404 , & V_504 ) ;
}
static void F_196 ( struct V_19 * V_20 )
{
struct V_11 * V_12 ;
int V_505 = 1 ;
F_197 ( V_504 ) ;
F_198 ( & V_20 -> V_165 , & V_504 , V_506 ) ;
F_185 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( V_12 -> V_17 . V_467 || ! V_12 -> V_17 . V_164 ) {
V_505 = 0 ;
break;
}
}
if ( ! V_505 ) {
F_199 ( & V_20 -> V_165 , & V_504 ) ;
return;
}
V_20 -> V_28 = V_29 ;
F_200 ( V_20 , 0 ) ;
F_30 ( & V_20 -> V_48 ) ;
F_194 () ;
F_199 ( & V_20 -> V_165 , & V_504 ) ;
F_29 ( & V_20 -> V_48 ) ;
V_20 -> V_28 = V_122 ;
F_200 ( V_20 , 1 ) ;
}
static int F_201 ( struct V_187 * V_187 , struct V_11 * V_12 )
{
int V_507 ;
struct V_19 * V_20 ;
struct V_11 * V_83 , * V_508 ;
F_202 ( V_12 ) ;
V_187 -> V_192 = 0 ;
V_12 -> V_17 . V_76 = V_185 ;
V_12 -> V_17 . V_52 = 0 ;
F_48 ( V_12 ) ;
V_20 = V_12 -> V_17 . V_26 ;
F_29 ( & V_20 -> V_48 ) ;
V_12 -> V_17 . V_164 = 0 ;
V_12 -> V_17 . V_462 = V_509 ;
V_12 -> V_17 . V_187 = V_187 ;
V_12 -> V_17 . V_126 = F_49 ( V_20 , F_20 () ) ;
V_12 -> V_17 . V_31 = V_154 ;
V_12 -> V_17 . V_33 = V_24 ;
F_155 ( & V_12 -> V_17 . V_418 , & V_20 -> V_356 ) ;
++ V_20 -> V_417 ;
if ( ! F_169 ( V_509 ) ) {
if ( V_20 -> V_28 == V_464 ) {
struct V_19 * V_429 = V_20 -> V_430 ;
if ( F_172 ( & V_429 -> V_48 ) ) {
if ( V_429 -> V_28 == V_500 &&
! F_203 ( V_429 ) ) {
F_50 ( V_12 , V_20 ) ;
F_144 ( V_12 , V_20 ) ;
F_186 ( V_12 ) ;
}
F_30 ( & V_429 -> V_48 ) ;
}
} else if ( V_20 -> V_28 == V_500 &&
! F_203 ( V_20 ) ) {
F_50 ( V_12 , V_20 ) ;
F_144 ( V_12 , V_20 ) ;
F_186 ( V_12 ) ;
} else if ( V_20 -> V_28 == V_29 ) {
F_15 ( & V_20 -> V_165 ) ;
}
}
while ( V_12 -> V_17 . V_31 == V_154 &&
! F_169 ( V_509 ) ) {
if ( V_20 -> V_28 == V_436 && V_20 -> V_27 == NULL )
F_156 ( V_20 ) ;
if ( V_20 -> V_28 != V_122 ) {
F_191 ( V_20 , V_12 , V_506 ) ;
continue;
}
F_164 (v, vn, &vc->runnable_threads,
arch.run_list) {
F_136 ( V_83 ) ;
if ( F_169 ( V_83 -> V_17 . V_462 ) ) {
F_140 ( V_20 , V_83 ) ;
V_83 -> V_15 . V_510 ++ ;
V_83 -> V_17 . V_187 -> V_192 = V_511 ;
V_83 -> V_17 . V_76 = - V_463 ;
F_170 ( & V_83 -> V_17 . V_404 ) ;
}
}
if ( ! V_20 -> V_417 || V_12 -> V_17 . V_31 != V_154 )
break;
V_507 = 0 ;
F_185 (v, &vc->runnable_threads, arch.run_list) {
if ( ! V_83 -> V_17 . V_467 )
V_507 += V_83 -> V_17 . V_164 ;
else
V_83 -> V_17 . V_164 = 0 ;
}
V_20 -> V_27 = V_12 ;
if ( V_507 == V_20 -> V_417 ) {
F_196 ( V_20 ) ;
} else if ( F_204 () ) {
F_153 ( V_20 ) ;
F_205 ( & V_20 -> V_48 ) ;
if ( V_20 -> V_28 == V_436 )
F_156 ( V_20 ) ;
} else {
F_180 ( V_20 ) ;
}
V_20 -> V_27 = NULL ;
}
while ( V_12 -> V_17 . V_31 == V_154 &&
( V_20 -> V_28 == V_500 ||
V_20 -> V_28 == V_501 ||
V_20 -> V_28 == V_464 ) )
F_191 ( V_20 , V_12 , V_512 ) ;
if ( V_20 -> V_28 == V_436 && V_20 -> V_27 == NULL )
F_156 ( V_20 ) ;
if ( V_12 -> V_17 . V_31 == V_154 ) {
F_140 ( V_20 , V_12 ) ;
V_12 -> V_15 . V_510 ++ ;
V_187 -> V_192 = V_511 ;
V_12 -> V_17 . V_76 = - V_463 ;
}
if ( V_20 -> V_417 && V_20 -> V_28 == V_122 ) {
V_83 = F_163 ( & V_20 -> V_356 ,
struct V_11 , V_17 . V_418 ) ;
F_170 ( & V_83 -> V_17 . V_404 ) ;
}
F_206 ( V_12 , V_187 ) ;
F_30 ( & V_20 -> V_48 ) ;
return V_12 -> V_17 . V_76 ;
}
static int F_207 ( struct V_187 * V_188 , struct V_11 * V_12 )
{
int V_49 ;
int V_473 ;
if ( ! V_12 -> V_17 . V_513 ) {
V_188 -> V_192 = V_202 ;
return - V_47 ;
}
F_136 ( V_12 ) ;
if ( F_169 ( V_509 ) ) {
V_188 -> V_192 = V_511 ;
return - V_463 ;
}
F_208 ( & V_12 -> V_72 -> V_17 . V_514 ) ;
F_8 () ;
if ( ! V_12 -> V_72 -> V_17 . V_515 ) {
V_49 = F_209 ( V_12 ) ;
if ( V_49 )
goto V_392;
}
F_210 ( V_509 ) ;
V_12 -> V_17 . V_14 = & V_12 -> V_17 . V_26 -> V_165 ;
V_12 -> V_17 . V_516 = V_509 -> V_517 -> V_518 ;
V_12 -> V_17 . V_31 = V_32 ;
do {
V_49 = F_201 ( V_188 , V_12 ) ;
if ( V_188 -> V_192 == V_220 &&
! ( V_12 -> V_17 . V_37 . V_35 & V_519 ) ) {
F_211 ( V_12 ) ;
V_49 = F_62 ( V_12 ) ;
F_212 ( V_12 , V_49 ) ;
F_136 ( V_12 ) ;
} else if ( V_49 == V_222 ) {
V_473 = F_65 ( & V_12 -> V_72 -> V_170 ) ;
V_49 = F_213 ( V_188 , V_12 ,
V_12 -> V_17 . V_65 , V_12 -> V_17 . V_66 ) ;
F_67 ( & V_12 -> V_72 -> V_170 , V_473 ) ;
}
} while ( F_177 ( V_49 ) );
V_392:
V_12 -> V_17 . V_31 = V_403 ;
F_214 ( & V_12 -> V_72 -> V_17 . V_514 ) ;
return V_49 ;
}
static void F_215 ( struct V_520 * * V_521 ,
int V_522 )
{
struct V_523 * V_524 = & V_525 [ V_522 ] ;
if ( ! V_524 -> V_526 )
return;
( * V_521 ) -> V_527 = V_524 -> V_526 ;
( * V_521 ) -> V_528 = V_524 -> V_529 ;
( * V_521 ) -> V_530 [ 0 ] . V_527 = V_524 -> V_526 ;
( * V_521 ) -> V_530 [ 0 ] . V_531 = V_524 -> V_532 [ V_522 ] ;
if ( V_522 != V_533 && V_524 -> V_532 [ V_533 ] != - 1 ) {
( * V_521 ) -> V_530 [ 1 ] . V_527 = 24 ;
( * V_521 ) -> V_530 [ 1 ] . V_531 = V_524 -> V_532 [ V_533 ] ;
}
( * V_521 ) ++ ;
}
static int F_216 ( struct V_72 * V_72 ,
struct V_534 * V_535 )
{
struct V_520 * V_521 ;
V_535 -> V_21 = V_536 ;
if ( F_217 ( V_537 ) )
V_535 -> V_21 |= V_538 ;
V_535 -> V_539 = V_540 ;
V_521 = & V_535 -> V_521 [ 0 ] ;
F_215 ( & V_521 , V_541 ) ;
F_215 ( & V_521 , V_542 ) ;
F_215 ( & V_521 , V_533 ) ;
return 0 ;
}
static int F_218 ( struct V_72 * V_72 ,
struct V_543 * log )
{
struct V_544 * V_545 ;
struct V_546 * V_547 ;
int V_49 ;
unsigned long V_373 ;
F_35 ( & V_72 -> V_548 ) ;
V_49 = - V_47 ;
if ( log -> V_549 >= V_550 )
goto V_392;
V_545 = V_544 ( V_72 ) ;
V_547 = F_219 ( V_545 , log -> V_549 ) ;
V_49 = - V_171 ;
if ( ! V_547 -> V_551 )
goto V_392;
V_373 = F_220 ( V_547 ) ;
memset ( V_547 -> V_551 , 0 , V_373 ) ;
V_49 = F_221 ( V_72 , V_547 , V_547 -> V_551 ) ;
if ( V_49 )
goto V_392;
V_49 = - V_386 ;
if ( F_112 ( log -> V_551 , V_547 -> V_551 , V_373 ) )
goto V_392;
V_49 = 0 ;
V_392:
F_37 ( & V_72 -> V_548 ) ;
return V_49 ;
}
static void F_222 ( struct V_546 * free ,
struct V_546 * V_552 )
{
if ( ! V_552 || free -> V_17 . V_553 != V_552 -> V_17 . V_553 ) {
F_223 ( free -> V_17 . V_553 ) ;
free -> V_17 . V_553 = NULL ;
}
}
static int F_224 ( struct V_546 * V_549 ,
unsigned long V_554 )
{
V_549 -> V_17 . V_553 = F_225 ( V_554 * sizeof( * V_549 -> V_17 . V_553 ) ) ;
if ( ! V_549 -> V_17 . V_553 )
return - V_364 ;
return 0 ;
}
static int F_226 ( struct V_72 * V_72 ,
struct V_546 * V_547 ,
const struct V_555 * V_556 )
{
return 0 ;
}
static void F_227 ( struct V_72 * V_72 ,
const struct V_555 * V_556 ,
const struct V_546 * V_557 ,
const struct V_546 * V_558 )
{
unsigned long V_554 = V_556 -> V_559 >> V_560 ;
struct V_544 * V_545 ;
struct V_546 * V_547 ;
if ( V_554 && V_557 -> V_554 ) {
V_545 = V_544 ( V_72 ) ;
V_547 = F_219 ( V_545 , V_556 -> V_549 ) ;
F_221 ( V_72 , V_547 , NULL ) ;
}
}
void F_228 ( struct V_72 * V_72 , unsigned long V_71 , unsigned long V_242 )
{
long int V_217 ;
T_2 V_561 = 0 ;
if ( ( V_72 -> V_17 . V_71 & V_242 ) == V_71 )
return;
V_72 -> V_17 . V_71 = ( V_72 -> V_17 . V_71 & ~ V_242 ) | V_71 ;
for ( V_217 = 0 ; V_217 < V_391 ; ++ V_217 ) {
struct V_19 * V_20 = V_72 -> V_17 . V_405 [ V_217 ] ;
if ( ! V_20 )
continue;
F_29 ( & V_20 -> V_48 ) ;
V_20 -> V_71 = ( V_20 -> V_71 & ~ V_242 ) | V_71 ;
F_30 ( & V_20 -> V_48 ) ;
if ( ++ V_561 >= V_72 -> V_17 . V_406 )
break;
}
}
static void F_229 ( struct V_11 * V_12 )
{
return;
}
static int F_209 ( struct V_11 * V_12 )
{
int V_96 = 0 ;
struct V_72 * V_72 = V_12 -> V_72 ;
unsigned long V_562 ;
struct V_546 * V_547 ;
struct V_563 * V_564 ;
unsigned long V_71 = 0 , V_565 ;
unsigned long V_566 , V_567 ;
int V_473 ;
F_35 ( & V_72 -> V_48 ) ;
if ( V_72 -> V_17 . V_515 )
goto V_392;
if ( ! V_72 -> V_17 . V_568 ) {
V_96 = F_230 ( V_72 , NULL ) ;
if ( V_96 ) {
F_32 ( L_22 ) ;
goto V_392;
}
}
V_473 = F_65 ( & V_72 -> V_170 ) ;
V_547 = F_231 ( V_72 , 0 ) ;
V_96 = - V_47 ;
if ( ! V_547 || ( V_547 -> V_21 & V_569 ) )
goto V_570;
V_562 = V_547 -> V_571 ;
F_232 ( & V_509 -> V_517 -> V_572 ) ;
V_564 = F_233 ( V_509 -> V_517 , V_562 ) ;
if ( ! V_564 || V_564 -> V_573 > V_562 || ( V_564 -> V_574 & V_575 ) )
goto V_576;
V_566 = F_234 ( V_564 ) ;
V_567 = F_235 ( V_566 ) ;
F_236 ( & V_509 -> V_517 -> V_572 ) ;
V_96 = - V_47 ;
if ( ! ( V_566 == 0x1000 || V_566 == 0x10000 ||
V_566 == 0x1000000 ) )
goto V_570;
V_565 = F_237 ( V_566 ) ;
V_72 -> V_17 . V_577 = V_565 | V_578 |
( V_579 << V_580 ) ;
V_71 = V_565 << ( V_581 - 4 ) ;
F_238 ( V_12 , V_547 , V_567 ) ;
F_228 ( V_72 , V_71 , V_582 ) ;
F_56 () ;
V_72 -> V_17 . V_515 = 1 ;
V_96 = 0 ;
V_570:
F_67 ( & V_72 -> V_170 , V_473 ) ;
V_392:
F_37 ( & V_72 -> V_48 ) ;
return V_96 ;
V_576:
F_236 ( & V_509 -> V_517 -> V_572 ) ;
goto V_570;
}
static int F_239 ( struct V_583 * V_584 , unsigned long V_585 ,
void * V_586 )
{
unsigned long V_1 = ( long ) V_586 ;
switch ( V_585 ) {
case V_587 :
case V_588 :
F_179 ( V_1 ) ;
break;
#ifdef F_240
case V_589 :
case V_590 :
case V_591 :
case V_592 :
F_178 ( V_1 ) ;
break;
#endif
default:
break;
}
return V_593 ;
}
void F_241 ( void )
{
struct V_594 * V_595 ;
unsigned long V_596 ;
int V_1 , V_354 ;
int V_597 ;
if ( V_468 != NULL )
return;
V_595 = F_98 ( sizeof( struct V_594 ) , V_355 ) ;
if ( ! V_595 )
return;
V_597 = F_242 () * sizeof( struct V_598 ) ;
V_595 -> V_470 = F_98 ( V_597 , V_355 ) ;
if ( ! V_595 -> V_470 ) {
F_107 ( V_595 ) ;
return;
}
F_243 () ;
for ( V_1 = 0 ; V_1 < V_7 ; V_1 += V_482 ) {
if ( ! F_16 ( V_1 ) )
continue;
V_354 = V_1 >> V_469 ;
V_595 -> V_470 [ V_354 ] . V_471 . V_472 = 1 ;
}
V_595 -> V_599 = F_12 ;
F_56 () ;
V_596 = ( unsigned long ) V_595 ;
if ( F_244 ( ( unsigned long * ) & V_468 , 0 , V_596 ) ) {
F_245 () ;
F_107 ( V_595 -> V_470 ) ;
F_107 ( V_595 ) ;
return;
}
F_246 ( & V_600 ) ;
F_245 () ;
}
void F_247 ( void )
{
if ( V_468 ) {
F_248 ( & V_600 ) ;
F_107 ( V_468 -> V_470 ) ;
F_107 ( V_468 ) ;
V_468 = NULL ;
}
}
static int F_249 ( struct V_72 * V_72 )
{
unsigned long V_71 , V_601 ;
char V_366 [ 32 ] ;
V_601 = F_250 () ;
if ( ( long ) V_601 < 0 )
return - V_364 ;
V_72 -> V_17 . V_601 = V_601 ;
F_241 () ;
F_251 ( & V_72 -> V_17 . V_602 ) ;
memcpy ( V_72 -> V_17 . V_159 , V_603 ,
sizeof( V_72 -> V_17 . V_159 ) ) ;
V_72 -> V_17 . V_604 = F_123 ( V_605 ) ;
V_72 -> V_17 . V_606 = F_123 ( V_607 ) ;
V_72 -> V_17 . V_608 = V_71 = F_123 ( V_609 ) ;
V_71 &= V_610 | V_611 ;
V_71 |= ( 4UL << V_612 ) | V_613 |
V_614 | V_615 ;
V_72 -> V_17 . V_577 = V_578 |
( V_579 << V_580 ) ;
if ( F_2 ( V_2 ) )
V_71 |= V_616 ;
V_72 -> V_17 . V_71 = V_71 ;
F_252 () ;
snprintf ( V_366 , sizeof( V_366 ) , L_23 , V_509 -> V_298 ) ;
V_72 -> V_17 . V_388 = F_116 ( V_366 , V_617 ) ;
if ( ! F_115 ( V_72 -> V_17 . V_388 ) )
F_253 ( V_72 ) ;
return 0 ;
}
static void F_254 ( struct V_72 * V_72 )
{
long int V_217 ;
for ( V_217 = 0 ; V_217 < V_391 ; ++ V_217 )
F_107 ( V_72 -> V_17 . V_405 [ V_217 ] ) ;
V_72 -> V_17 . V_406 = 0 ;
}
static void F_255 ( struct V_72 * V_72 )
{
F_256 ( V_72 -> V_17 . V_388 ) ;
F_257 () ;
F_254 ( V_72 ) ;
F_258 ( V_72 ) ;
}
static int F_259 ( struct V_187 * V_188 , struct V_11 * V_12 ,
unsigned int V_618 , int * V_619 )
{
return V_620 ;
}
static int F_260 ( struct V_11 * V_12 , int V_621 ,
T_3 V_622 )
{
return V_620 ;
}
static int F_261 ( struct V_11 * V_12 , int V_621 ,
T_3 * V_622 )
{
return V_620 ;
}
static int F_262 ( void )
{
if ( ! F_2 ( V_623 ) ||
! F_2 ( V_624 ) )
return - V_625 ;
if ( F_2 ( V_626 ) )
return - V_625 ;
return 0 ;
}
static long F_263 ( struct V_361 * V_627 ,
unsigned int V_628 , unsigned long V_629 )
{
struct V_72 * V_72 V_630 = V_627 -> V_365 ;
void T_5 * V_631 = ( void T_5 * ) V_629 ;
long V_49 ;
switch ( V_628 ) {
case V_632 : {
T_2 V_633 ;
V_49 = - V_386 ;
if ( F_264 ( V_633 , ( T_2 T_5 * ) V_631 ) )
break;
V_49 = F_265 ( V_72 , & V_633 ) ;
if ( V_49 )
break;
V_49 = - V_386 ;
if ( F_266 ( V_633 , ( T_2 T_5 * ) V_631 ) )
break;
V_49 = 0 ;
break;
}
case V_634 : {
struct V_635 V_636 ;
V_49 = - V_386 ;
if ( F_267 ( & V_636 , V_631 , sizeof( V_636 ) ) )
break;
V_49 = F_268 ( V_72 , & V_636 ) ;
break;
}
default:
V_49 = - V_637 ;
}
return V_49 ;
}
static void F_269 ( void )
{
int V_217 ;
unsigned int V_638 ;
for ( V_217 = 0 ; V_639 [ V_217 ] ; ++ V_217 ) {
V_638 = V_639 [ V_217 ] ;
F_270 ( ! F_76 ( V_638 ) ) ;
F_271 ( V_638 / 4 , V_603 ) ;
}
}
static int F_272 ( void )
{
int V_217 , V_237 ;
int V_640 = F_242 () ;
struct V_641 * V_641 ;
for ( V_217 = 0 ; V_217 < V_640 ; V_217 ++ ) {
int V_642 = V_217 * V_482 ;
int V_643 = F_273 ( V_642 ) ;
if ( V_8 [ V_642 ] . V_641 )
continue;
V_641 =
F_274 ( sizeof( struct V_641 ) ,
V_355 , V_643 ) ;
if ( ! V_641 )
return - V_364 ;
memset ( V_641 , 0 ,
sizeof( struct V_641 ) ) ;
for ( V_237 = 0 ; V_237 < V_482 ; V_237 ++ ) {
int V_1 = V_642 + V_237 ;
V_8 [ V_1 ] . V_641 = V_641 ;
}
}
return 0 ;
}
static int F_275 ( void )
{
int V_49 ;
V_49 = F_262 () ;
if ( V_49 < 0 )
return - V_644 ;
V_49 = F_272 () ;
if ( V_49 )
return V_49 ;
V_645 . V_646 = V_647 ;
V_648 = & V_645 ;
F_269 () ;
F_150 () ;
V_49 = F_276 () ;
return V_49 ;
}
static void F_277 ( void )
{
F_247 () ;
V_648 = NULL ;
}
