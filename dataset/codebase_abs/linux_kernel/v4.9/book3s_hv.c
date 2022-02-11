static inline struct V_1 * F_1 ( struct V_2 * V_3 ,
int * V_4 )
{
int V_5 = * V_4 ;
struct V_1 * V_6 ;
while ( ++ V_5 < V_7 ) {
V_6 = F_2 ( V_3 -> V_8 [ V_5 ] ) ;
if ( V_6 ) {
* V_4 = V_5 ;
return V_6 ;
}
}
return NULL ;
}
static bool F_3 ( int V_9 )
{
if ( F_4 ( V_10 ) ) {
F_5 () ;
if ( F_6 ( V_9 ) ==
F_6 ( F_7 () ) ) {
unsigned long V_11 = F_8 ( V_12 ) ;
V_11 |= F_9 ( V_9 ) ;
F_10 () ;
__asm__ __volatile__ (PPC_MSGSND(%0) : : "r" (msg));
F_11 () ;
return true ;
}
F_11 () ;
}
#if F_12 ( V_13 ) && F_12 ( V_14 )
if ( V_9 >= 0 && V_9 < V_15 && V_16 [ V_9 ] . V_17 . V_18 ) {
F_13 ( V_9 ) ;
return true ;
}
#endif
return false ;
}
static void F_14 ( struct V_1 * V_6 )
{
int V_9 ;
struct V_19 * V_20 ;
V_20 = F_15 ( V_6 ) ;
if ( F_16 ( V_20 ) ) {
F_17 ( V_20 ) ;
++ V_6 -> V_21 . V_22 ;
}
if ( F_3 ( V_6 -> V_23 . V_24 ) )
return;
V_9 = V_6 -> V_9 ;
if ( V_9 >= 0 && V_9 < V_15 && F_18 ( V_9 ) )
F_19 ( V_9 ) ;
}
static void F_20 ( struct V_2 * V_3 )
{
unsigned long V_25 ;
F_21 ( & V_3 -> V_26 , V_25 ) ;
V_3 -> V_27 = F_22 () ;
F_23 ( & V_3 -> V_26 , V_25 ) ;
}
static void F_24 ( struct V_2 * V_3 )
{
unsigned long V_25 ;
F_21 ( & V_3 -> V_26 , V_25 ) ;
if ( V_3 -> V_27 != V_28 ) {
V_3 -> V_29 += F_22 () - V_3 -> V_27 ;
V_3 -> V_27 = V_28 ;
}
F_23 ( & V_3 -> V_26 , V_25 ) ;
}
static void F_25 ( struct V_1 * V_6 , int V_9 )
{
struct V_2 * V_3 = V_6 -> V_23 . V_30 ;
unsigned long V_25 ;
if ( V_3 -> V_31 == V_6 && V_3 -> V_32 >= V_33 )
F_24 ( V_3 ) ;
F_21 ( & V_6 -> V_23 . V_34 , V_25 ) ;
if ( V_6 -> V_23 . V_35 == V_36 &&
V_6 -> V_23 . V_37 != V_28 ) {
V_6 -> V_23 . V_38 += F_22 () - V_6 -> V_23 . V_37 ;
V_6 -> V_23 . V_37 = V_28 ;
}
F_23 ( & V_6 -> V_23 . V_34 , V_25 ) ;
}
static void F_26 ( struct V_1 * V_6 )
{
struct V_2 * V_3 = V_6 -> V_23 . V_30 ;
unsigned long V_25 ;
if ( V_3 -> V_31 == V_6 && V_3 -> V_32 >= V_33 )
F_20 ( V_3 ) ;
F_21 ( & V_6 -> V_23 . V_34 , V_25 ) ;
if ( V_6 -> V_23 . V_35 == V_36 )
V_6 -> V_23 . V_37 = F_22 () ;
F_23 ( & V_6 -> V_23 . V_34 , V_25 ) ;
}
static void F_27 ( struct V_1 * V_6 , T_1 V_39 )
{
if ( ( V_39 & V_40 ) == V_40 )
V_39 &= ~ V_40 ;
V_6 -> V_23 . V_41 . V_39 = V_39 ;
F_28 ( V_6 ) ;
}
static void F_29 ( struct V_1 * V_6 , T_2 V_42 )
{
V_6 -> V_23 . V_42 = V_42 ;
}
static int F_30 ( struct V_1 * V_6 , T_2 V_43 )
{
unsigned long V_44 = 0 ;
struct V_2 * V_3 = V_6 -> V_23 . V_30 ;
if ( V_43 ) {
switch ( V_43 ) {
case V_45 :
V_44 = V_46 | V_47 ;
break;
case V_48 :
case V_49 :
V_44 = V_46 ;
break;
case V_50 :
break;
default:
return - V_51 ;
}
if ( ! F_4 ( V_10 ) ) {
if ( ! ( V_44 & V_46 ) )
return - V_51 ;
V_44 &= ~ V_46 ;
}
}
F_31 ( & V_3 -> V_52 ) ;
V_3 -> V_43 = V_43 ;
V_3 -> V_44 = V_44 ;
F_32 ( & V_3 -> V_52 ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_6 )
{
int V_53 ;
F_34 ( L_1 , V_6 , V_6 -> V_54 ) ;
F_34 ( L_2 ,
V_6 -> V_23 . V_55 , V_6 -> V_23 . V_41 . V_39 , V_6 -> V_23 . V_56 ) ;
for ( V_53 = 0 ; V_53 < 16 ; ++ V_53 )
F_34 ( L_3 ,
V_53 , F_35 ( V_6 , V_53 ) ,
V_53 + 16 , F_35 ( V_6 , V_53 + 16 ) ) ;
F_34 ( L_4 ,
V_6 -> V_23 . V_57 , V_6 -> V_23 . V_58 ) ;
F_34 ( L_5 ,
V_6 -> V_23 . V_41 . V_59 , V_6 -> V_23 . V_41 . V_60 ) ;
F_34 ( L_6 ,
V_6 -> V_23 . V_41 . V_61 , V_6 -> V_23 . V_41 . V_62 ) ;
F_34 ( L_7 ,
V_6 -> V_23 . V_41 . V_63 , V_6 -> V_23 . V_41 . V_64 ) ;
F_34 ( L_8 ,
V_6 -> V_23 . V_65 , V_6 -> V_23 . V_66 , V_6 -> V_23 . V_41 . V_67 ) ;
F_34 ( L_9 , V_6 -> V_23 . V_41 . V_68 ) ;
F_34 ( L_10 ,
V_6 -> V_23 . V_69 , V_6 -> V_23 . V_70 ) ;
F_34 ( L_11 , V_6 -> V_23 . V_71 ) ;
for ( V_53 = 0 ; V_53 < V_6 -> V_23 . V_71 ; ++ V_53 )
F_34 ( L_12 ,
V_6 -> V_23 . V_72 [ V_53 ] . V_73 , V_6 -> V_23 . V_72 [ V_53 ] . V_74 ) ;
F_34 ( L_13 ,
V_6 -> V_23 . V_30 -> V_75 , V_6 -> V_76 -> V_23 . V_77 ,
V_6 -> V_23 . V_78 ) ;
}
static struct V_1 * F_36 ( struct V_76 * V_76 , int V_79 )
{
struct V_1 * V_80 ;
F_37 ( & V_76 -> V_52 ) ;
V_80 = F_38 ( V_76 , V_79 ) ;
F_39 ( & V_76 -> V_52 ) ;
return V_80 ;
}
static void F_40 ( struct V_1 * V_6 , struct V_81 * V_82 )
{
V_82 -> V_83 |= V_84 ;
V_82 -> V_85 = F_41 ( 1 ) ;
}
static int F_42 ( struct V_1 * V_6 , struct V_86 * V_87 ,
unsigned long V_88 , unsigned long V_89 )
{
if ( V_88 & ( V_90 - 1 ) )
return - V_51 ;
F_31 ( & V_6 -> V_23 . V_91 ) ;
if ( V_87 -> V_92 != V_88 || V_87 -> V_89 != V_89 ) {
V_87 -> V_92 = V_88 ;
V_87 -> V_89 = V_88 ? V_89 : 0 ;
V_87 -> V_93 = 1 ;
}
F_32 ( & V_6 -> V_23 . V_91 ) ;
return 0 ;
}
static int F_43 ( struct V_86 * V_94 )
{
if ( V_94 -> V_93 )
return V_94 -> V_92 != 0 ;
return V_94 -> V_95 != NULL ;
}
static unsigned long F_44 ( struct V_1 * V_6 ,
unsigned long V_25 ,
unsigned long V_96 , unsigned long V_82 )
{
struct V_76 * V_76 = V_6 -> V_76 ;
unsigned long V_89 , V_97 ;
void * V_98 ;
struct V_1 * V_99 ;
int V_100 ;
int V_101 ;
struct V_86 * V_94 ;
V_99 = F_36 ( V_76 , V_96 ) ;
if ( ! V_99 )
return V_102 ;
V_101 = ( V_25 >> V_103 ) & V_104 ;
if ( V_101 == V_105 || V_101 == V_106 ||
V_101 == V_107 ) {
if ( ( V_82 & ( V_90 - 1 ) ) || ! V_82 )
return V_102 ;
V_98 = F_45 ( V_76 , V_82 , & V_97 ) ;
if ( V_98 == NULL )
return V_102 ;
if ( V_101 == V_105 )
V_89 = F_46 ( ( (struct V_108 * ) V_98 ) -> V_109 . V_110 ) ;
else
V_89 = F_47 ( ( (struct V_108 * ) V_98 ) -> V_109 . V_111 ) ;
F_48 ( V_76 , V_98 , V_82 , false ) ;
if ( V_89 > V_97 || V_89 < sizeof( struct V_108 ) )
return V_102 ;
} else {
V_82 = 0 ;
V_89 = 0 ;
}
V_100 = V_102 ;
V_94 = NULL ;
F_31 ( & V_99 -> V_23 . V_91 ) ;
switch ( V_101 ) {
case V_105 :
if ( V_89 < sizeof( struct V_81 ) )
break;
V_94 = & V_99 -> V_23 . V_82 ;
V_100 = 0 ;
break;
case V_106 :
if ( V_89 < sizeof( struct V_112 ) )
break;
V_89 -= V_89 % sizeof( struct V_112 ) ;
V_100 = V_113 ;
if ( ! F_43 ( & V_99 -> V_23 . V_82 ) )
break;
V_94 = & V_99 -> V_23 . V_114 ;
V_100 = 0 ;
break;
case V_107 :
V_100 = V_113 ;
if ( ! F_43 ( & V_99 -> V_23 . V_82 ) )
break;
V_94 = & V_99 -> V_23 . V_115 ;
V_100 = 0 ;
break;
case V_116 :
V_100 = V_113 ;
if ( F_43 ( & V_99 -> V_23 . V_114 ) ||
F_43 ( & V_99 -> V_23 . V_115 ) )
break;
V_94 = & V_99 -> V_23 . V_82 ;
V_100 = 0 ;
break;
case V_117 :
V_94 = & V_99 -> V_23 . V_114 ;
V_100 = 0 ;
break;
case V_118 :
V_94 = & V_99 -> V_23 . V_115 ;
V_100 = 0 ;
break;
}
if ( V_94 ) {
V_94 -> V_92 = V_82 ;
V_94 -> V_89 = V_89 ;
V_94 -> V_93 = 1 ;
}
F_32 ( & V_99 -> V_23 . V_91 ) ;
return V_100 ;
}
static void F_49 ( struct V_1 * V_6 , struct V_86 * V_94 )
{
struct V_76 * V_76 = V_6 -> V_76 ;
void * V_98 ;
unsigned long V_97 ;
unsigned long V_119 ;
for (; ; ) {
V_119 = V_94 -> V_92 ;
F_32 ( & V_6 -> V_23 . V_91 ) ;
V_98 = NULL ;
V_97 = 0 ;
if ( V_119 )
V_98 = F_45 ( V_76 , V_119 , & V_97 ) ;
F_31 ( & V_6 -> V_23 . V_91 ) ;
if ( V_119 == V_94 -> V_92 )
break;
if ( V_98 )
F_48 ( V_76 , V_98 , V_119 , false ) ;
}
V_94 -> V_93 = 0 ;
if ( V_98 && V_97 < V_94 -> V_89 ) {
F_48 ( V_76 , V_98 , V_119 , false ) ;
V_98 = NULL ;
}
if ( V_94 -> V_95 )
F_48 ( V_76 , V_94 -> V_95 , V_94 -> V_119 ,
V_94 -> V_120 ) ;
V_94 -> V_119 = V_119 ;
V_94 -> V_95 = V_98 ;
V_94 -> V_120 = false ;
if ( V_98 )
V_94 -> V_121 = V_98 + V_94 -> V_89 ;
}
static void F_50 ( struct V_1 * V_6 )
{
if ( ! ( V_6 -> V_23 . V_82 . V_93 ||
V_6 -> V_23 . V_115 . V_93 ||
V_6 -> V_23 . V_114 . V_93 ) )
return;
F_31 ( & V_6 -> V_23 . V_91 ) ;
if ( V_6 -> V_23 . V_82 . V_93 ) {
F_49 ( V_6 , & V_6 -> V_23 . V_82 ) ;
if ( V_6 -> V_23 . V_82 . V_95 )
F_40 ( V_6 , V_6 -> V_23 . V_82 . V_95 ) ;
}
if ( V_6 -> V_23 . V_114 . V_93 ) {
F_49 ( V_6 , & V_6 -> V_23 . V_114 ) ;
V_6 -> V_23 . V_122 = V_6 -> V_23 . V_114 . V_95 ;
V_6 -> V_23 . V_123 = 0 ;
}
if ( V_6 -> V_23 . V_115 . V_93 )
F_49 ( V_6 , & V_6 -> V_23 . V_115 ) ;
F_32 ( & V_6 -> V_23 . V_91 ) ;
}
static T_1 F_51 ( struct V_2 * V_3 , T_1 V_124 )
{
T_1 V_125 ;
unsigned long V_25 ;
F_21 ( & V_3 -> V_26 , V_25 ) ;
V_125 = V_3 -> V_29 ;
if ( V_3 -> V_32 != V_126 &&
V_3 -> V_27 != V_28 )
V_125 += V_124 - V_3 -> V_27 ;
F_23 ( & V_3 -> V_26 , V_25 ) ;
return V_125 ;
}
static void F_52 ( struct V_1 * V_6 ,
struct V_2 * V_3 )
{
struct V_112 * V_127 ;
struct V_81 * V_82 ;
unsigned long V_128 ;
unsigned long V_129 ;
T_1 V_124 ;
V_127 = V_6 -> V_23 . V_122 ;
V_82 = V_6 -> V_23 . V_82 . V_95 ;
V_124 = F_22 () ;
V_129 = F_51 ( V_3 , V_124 ) ;
V_128 = V_129 - V_6 -> V_23 . V_130 ;
V_6 -> V_23 . V_130 = V_129 ;
F_53 ( & V_6 -> V_23 . V_34 ) ;
V_128 += V_6 -> V_23 . V_38 ;
V_6 -> V_23 . V_38 = 0 ;
F_54 ( & V_6 -> V_23 . V_34 ) ;
if ( ! V_127 || ! V_82 )
return;
memset ( V_127 , 0 , sizeof( struct V_112 ) ) ;
V_127 -> V_131 = 7 ;
V_127 -> V_132 = F_55 ( V_3 -> V_133 + V_6 -> V_23 . V_134 ) ;
V_127 -> V_135 = F_56 ( V_124 + V_3 -> V_136 ) ;
V_127 -> V_137 = F_41 ( V_128 ) ;
V_127 -> V_59 = F_56 ( F_57 ( V_6 ) ) ;
V_127 -> V_60 = F_56 ( V_6 -> V_23 . V_41 . V_39 ) ;
++ V_127 ;
if ( V_127 == V_6 -> V_23 . V_114 . V_121 )
V_127 = V_6 -> V_23 . V_114 . V_95 ;
V_6 -> V_23 . V_122 = V_127 ;
F_58 () ;
V_82 -> V_138 = F_56 ( ++ V_6 -> V_23 . V_123 ) ;
V_6 -> V_23 . V_114 . V_120 = true ;
}
static bool F_59 ( struct V_1 * V_6 )
{
if ( V_6 -> V_23 . V_30 -> V_43 >= V_50 )
return true ;
if ( ( ! V_6 -> V_23 . V_30 -> V_43 ) &&
F_4 ( V_10 ) )
return true ;
return false ;
}
static int F_60 ( struct V_1 * V_6 , unsigned long V_139 ,
unsigned long V_140 , unsigned long V_141 ,
unsigned long V_142 )
{
switch ( V_140 ) {
case V_143 :
if ( ! F_59 ( V_6 ) )
return V_144 ;
if ( V_142 )
return V_145 ;
if ( V_139 )
return V_146 ;
if ( ( V_141 & V_147 ) == V_148 )
return V_149 ;
V_6 -> V_23 . V_150 = V_141 ;
return V_151 ;
case V_152 :
if ( ! F_59 ( V_6 ) )
return V_144 ;
if ( V_139 )
return V_146 ;
if ( V_142 & V_153 )
return V_145 ;
V_6 -> V_23 . V_154 = V_141 ;
V_6 -> V_23 . V_155 = V_142 ;
return V_151 ;
default:
return V_156 ;
}
}
static int F_61 ( struct V_1 * V_157 )
{
struct V_2 * V_30 = V_157 -> V_23 . V_30 ;
F_31 ( & V_30 -> V_52 ) ;
if ( V_157 -> V_23 . V_35 == V_158 &&
V_30 -> V_32 != V_126 &&
V_30 -> V_31 )
V_157 = V_30 -> V_31 ;
F_32 ( & V_30 -> V_52 ) ;
return F_62 ( V_157 ) ;
}
static int F_63 ( struct V_1 * V_6 )
{
int V_85 = 0 ;
struct V_81 * V_81 ;
F_31 ( & V_6 -> V_23 . V_91 ) ;
V_81 = (struct V_81 * ) V_6 -> V_23 . V_82 . V_95 ;
if ( V_81 )
V_85 = F_47 ( V_81 -> V_85 ) ;
F_32 ( & V_6 -> V_23 . V_91 ) ;
return V_85 ;
}
int F_64 ( struct V_1 * V_6 )
{
unsigned long V_159 = F_35 ( V_6 , 3 ) ;
unsigned long V_157 , V_80 = V_151 ;
int V_85 ;
struct V_1 * V_99 ;
int V_160 , V_161 ;
if ( V_159 <= V_162 &&
! F_65 ( V_159 / 4 , V_6 -> V_76 -> V_23 . V_163 ) )
return V_164 ;
switch ( V_159 ) {
case V_165 :
break;
case V_166 :
V_157 = F_35 ( V_6 , 4 ) ;
V_99 = F_36 ( V_6 -> V_76 , V_157 ) ;
if ( ! V_99 ) {
V_80 = V_102 ;
break;
}
V_99 -> V_23 . V_167 = 1 ;
F_10 () ;
if ( V_6 -> V_23 . V_168 ) {
if ( F_16 ( & V_6 -> V_169 ) ) {
F_17 ( & V_6 -> V_169 ) ;
V_6 -> V_21 . V_22 ++ ;
}
}
break;
case V_170 :
V_157 = F_35 ( V_6 , 4 ) ;
if ( V_157 == - 1 )
break;
V_99 = F_36 ( V_6 -> V_76 , V_157 ) ;
if ( ! V_99 ) {
V_80 = V_102 ;
break;
}
V_85 = F_35 ( V_6 , 5 ) ;
if ( F_63 ( V_99 ) != V_85 )
break;
F_61 ( V_99 ) ;
break;
case V_171 :
V_80 = F_44 ( V_6 , F_35 ( V_6 , 4 ) ,
F_35 ( V_6 , 5 ) ,
F_35 ( V_6 , 6 ) ) ;
break;
case V_172 :
if ( F_66 ( & V_6 -> V_76 -> V_23 . V_173 ) )
return V_164 ;
V_160 = F_67 ( & V_6 -> V_76 -> V_174 ) ;
V_161 = F_68 ( V_6 ) ;
F_69 ( & V_6 -> V_76 -> V_174 , V_160 ) ;
if ( V_161 == - V_175 )
return V_164 ;
else if ( V_161 == 0 )
break;
return V_161 ;
case V_176 :
V_80 = F_70 ( V_6 ) ;
if ( V_80 == V_156 )
return V_164 ;
break;
case V_177 :
V_80 = F_71 ( V_6 ) ;
if ( V_80 == V_156 )
return V_164 ;
break;
case V_178 :
V_80 = F_60 ( V_6 , F_35 ( V_6 , 4 ) ,
F_35 ( V_6 , 5 ) ,
F_35 ( V_6 , 6 ) ,
F_35 ( V_6 , 7 ) ) ;
if ( V_80 == V_156 )
return V_164 ;
break;
case V_179 :
case V_180 :
case V_181 :
case V_182 :
case V_183 :
case V_184 :
if ( F_72 ( V_6 ) ) {
V_80 = F_73 ( V_6 , V_159 ) ;
break;
}
return V_164 ;
case V_185 :
V_80 = F_74 ( V_6 , F_35 ( V_6 , 4 ) ,
F_35 ( V_6 , 5 ) ,
F_35 ( V_6 , 6 ) ) ;
if ( V_80 == V_156 )
return V_164 ;
break;
case V_186 :
V_80 = F_75 ( V_6 , F_35 ( V_6 , 4 ) ,
F_35 ( V_6 , 5 ) ,
F_35 ( V_6 , 6 ) ,
F_35 ( V_6 , 7 ) ) ;
if ( V_80 == V_156 )
return V_164 ;
break;
case V_187 :
V_80 = F_76 ( V_6 , F_35 ( V_6 , 4 ) ,
F_35 ( V_6 , 5 ) ,
F_35 ( V_6 , 6 ) ,
F_35 ( V_6 , 7 ) ) ;
if ( V_80 == V_156 )
return V_164 ;
break;
default:
return V_164 ;
}
F_77 ( V_6 , 3 , V_80 ) ;
V_6 -> V_23 . V_188 = 0 ;
return V_189 ;
}
static int F_78 ( unsigned long V_190 )
{
switch ( V_190 ) {
case V_165 :
case V_166 :
case V_170 :
case V_171 :
case V_178 :
case V_176 :
case V_177 :
#ifdef F_79
case V_179 :
case V_180 :
case V_181 :
case V_182 :
case V_183 :
case V_184 :
#endif
return 1 ;
}
return F_80 ( V_190 ) ;
}
static int F_81 ( struct V_191 * V_192 ,
struct V_1 * V_6 )
{
T_2 V_78 ;
if ( F_82 ( V_6 , V_193 , & V_78 ) !=
V_194 ) {
return V_189 ;
}
if ( V_78 == V_195 ) {
V_192 -> V_196 = V_197 ;
V_192 -> V_198 . V_23 . V_199 = F_57 ( V_6 ) ;
return V_164 ;
} else {
F_83 ( V_6 , V_200 ) ;
return V_189 ;
}
}
static int F_84 ( struct V_191 * V_192 , struct V_1 * V_6 ,
struct V_201 * V_202 )
{
int V_53 = V_164 ;
V_6 -> V_21 . V_203 ++ ;
if ( V_6 -> V_23 . V_41 . V_39 & V_204 ) {
F_85 ( V_205 L_14 ) ;
F_85 ( V_205 L_15 ,
V_6 -> V_23 . V_56 , F_57 ( V_6 ) ,
V_6 -> V_23 . V_41 . V_39 ) ;
F_33 ( V_6 ) ;
V_192 -> V_196 = V_206 ;
V_192 -> V_207 . V_208 = V_6 -> V_23 . V_56 ;
return V_164 ;
}
V_192 -> V_196 = V_209 ;
V_192 -> V_210 = 1 ;
switch ( V_6 -> V_23 . V_56 ) {
case V_211 :
V_6 -> V_21 . V_212 ++ ;
V_53 = V_189 ;
break;
case V_213 :
case V_214 :
V_6 -> V_21 . V_215 ++ ;
V_53 = V_189 ;
break;
case V_216 :
case V_217 :
V_53 = V_189 ;
break;
case V_218 :
F_86 ( V_6 ,
V_218 ) ;
V_53 = V_189 ;
break;
case V_219 :
{
T_3 V_25 ;
V_25 = V_6 -> V_23 . V_41 . V_39 & 0x1f0000ull ;
F_83 ( V_6 , V_25 ) ;
V_53 = V_189 ;
break;
}
case V_220 :
{
int V_5 ;
V_192 -> V_221 . V_222 = F_35 ( V_6 , 3 ) ;
for ( V_5 = 0 ; V_5 < 9 ; ++ V_5 )
V_192 -> V_221 . args [ V_5 ] = F_35 ( V_6 , 4 + V_5 ) ;
V_192 -> V_196 = V_223 ;
V_6 -> V_23 . V_188 = 1 ;
V_53 = V_164 ;
break;
}
case V_224 :
V_53 = V_225 ;
break;
case V_226 :
V_6 -> V_23 . V_69 = F_57 ( V_6 ) ;
V_6 -> V_23 . V_70 = 0 ;
V_53 = V_225 ;
break;
case V_227 :
if ( V_6 -> V_23 . V_228 != V_229 )
V_6 -> V_23 . V_78 = F_87 ( V_6 ) ?
F_88 ( V_6 -> V_23 . V_228 ) :
V_6 -> V_23 . V_228 ;
if ( V_6 -> V_230 & V_231 ) {
V_53 = F_81 ( V_192 , V_6 ) ;
} else {
F_83 ( V_6 , V_200 ) ;
V_53 = V_189 ;
}
break;
case V_232 :
F_83 ( V_6 , V_200 ) ;
V_53 = V_189 ;
break;
case V_233 :
V_53 = V_234 ;
break;
default:
F_33 ( V_6 ) ;
F_85 ( V_205 L_15 ,
V_6 -> V_23 . V_56 , F_57 ( V_6 ) ,
V_6 -> V_23 . V_41 . V_39 ) ;
V_192 -> V_207 . V_208 = V_6 -> V_23 . V_56 ;
V_53 = V_164 ;
break;
}
return V_53 ;
}
static int F_89 ( struct V_1 * V_6 ,
struct V_235 * V_236 )
{
int V_5 ;
memset ( V_236 , 0 , sizeof( struct V_235 ) ) ;
V_236 -> V_42 = V_6 -> V_23 . V_42 ;
for ( V_5 = 0 ; V_5 < V_6 -> V_23 . V_71 ; V_5 ++ ) {
V_236 -> V_237 . V_238 . V_239 . V_72 [ V_5 ] . V_240 = V_6 -> V_23 . V_72 [ V_5 ] . V_73 ;
V_236 -> V_237 . V_238 . V_239 . V_72 [ V_5 ] . V_241 = V_6 -> V_23 . V_72 [ V_5 ] . V_74 ;
}
return 0 ;
}
static int F_90 ( struct V_1 * V_6 ,
struct V_235 * V_236 )
{
int V_5 , V_242 ;
if ( V_236 -> V_42 != V_6 -> V_23 . V_42 )
return - V_51 ;
V_242 = 0 ;
for ( V_5 = 0 ; V_5 < V_6 -> V_23 . V_243 ; V_5 ++ ) {
if ( V_236 -> V_237 . V_238 . V_239 . V_72 [ V_5 ] . V_240 & V_244 ) {
V_6 -> V_23 . V_72 [ V_242 ] . V_73 = V_236 -> V_237 . V_238 . V_239 . V_72 [ V_5 ] . V_240 ;
V_6 -> V_23 . V_72 [ V_242 ] . V_74 = V_236 -> V_237 . V_238 . V_239 . V_72 [ V_5 ] . V_241 ;
++ V_242 ;
}
}
V_6 -> V_23 . V_71 = V_242 ;
return 0 ;
}
static void F_91 ( struct V_1 * V_6 , T_1 V_245 ,
bool V_246 )
{
struct V_76 * V_76 = V_6 -> V_76 ;
struct V_2 * V_3 = V_6 -> V_23 . V_30 ;
T_1 V_247 ;
F_37 ( & V_76 -> V_52 ) ;
F_31 ( & V_3 -> V_52 ) ;
if ( ( V_245 & V_248 ) != ( V_3 -> V_75 & V_248 ) ) {
struct V_1 * V_6 ;
int V_5 ;
F_92 (i, vcpu, kvm) {
if ( V_6 -> V_23 . V_30 != V_3 )
continue;
if ( V_245 & V_248 )
V_6 -> V_23 . V_249 |= V_250 ;
else
V_6 -> V_23 . V_249 &= ~ V_250 ;
}
}
V_247 = V_251 | V_248 | V_252 ;
if ( F_4 ( V_10 ) )
V_247 |= V_253 ;
if ( V_246 )
V_247 &= 0xFFFFFFFF ;
V_3 -> V_75 = ( V_3 -> V_75 & ~ V_247 ) | ( V_245 & V_247 ) ;
F_32 ( & V_3 -> V_52 ) ;
F_39 ( & V_76 -> V_52 ) ;
}
static int F_93 ( struct V_1 * V_6 , T_1 V_79 ,
union V_254 * V_255 )
{
int V_53 = 0 ;
long int V_5 ;
switch ( V_79 ) {
case V_256 :
* V_255 = F_94 ( V_79 , V_195 ) ;
break;
case V_257 :
* V_255 = F_94 ( V_79 , 0 ) ;
break;
case V_258 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_259 ) ;
break;
case V_260 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_261 ) ;
break;
case V_262 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_263 ) ;
break;
case V_264 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_265 ) ;
break;
case V_266 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_267 ) ;
break;
case V_268 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_269 ) ;
break;
case V_270 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_271 ) ;
break;
case V_272 ... V_273 :
V_5 = V_79 - V_272 ;
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_274 [ V_5 ] ) ;
break;
case V_275 ... V_276 :
V_5 = V_79 - V_275 ;
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_277 [ V_5 ] ) ;
break;
case V_278 ... V_279 :
V_5 = V_79 - V_278 ;
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_280 [ V_5 ] ) ;
break;
case V_281 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_282 ) ;
break;
case V_283 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_284 ) ;
break;
case V_285 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_286 ) ;
break;
case V_287 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_288 ) ;
break;
case V_289 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_290 ) ;
break;
case V_291 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_30 -> V_292 ) ;
break;
case V_293 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_30 -> V_294 ) ;
break;
case V_295 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_154 ) ;
break;
case V_296 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_155 ) ;
break;
case V_297 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_150 ) ;
break;
case V_298 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_299 ) ;
break;
case V_300 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_301 ) ;
break;
case V_302 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_303 ) ;
break;
case V_304 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_305 ) ;
break;
case V_306 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_307 ) ;
break;
case V_308 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_309 ) ;
break;
case V_310 :
F_31 ( & V_6 -> V_23 . V_91 ) ;
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_82 . V_92 ) ;
F_32 ( & V_6 -> V_23 . V_91 ) ;
break;
case V_311 :
F_31 ( & V_6 -> V_23 . V_91 ) ;
V_255 -> V_312 . V_88 = V_6 -> V_23 . V_115 . V_92 ;
V_255 -> V_312 . V_109 = V_6 -> V_23 . V_115 . V_89 ;
F_32 ( & V_6 -> V_23 . V_91 ) ;
break;
case V_313 :
F_31 ( & V_6 -> V_23 . V_91 ) ;
V_255 -> V_312 . V_88 = V_6 -> V_23 . V_114 . V_92 ;
V_255 -> V_312 . V_109 = V_6 -> V_23 . V_114 . V_89 ;
F_32 ( & V_6 -> V_23 . V_91 ) ;
break;
case V_314 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_30 -> V_136 ) ;
break;
case V_315 :
case V_316 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_30 -> V_75 ) ;
break;
case V_317 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_318 ) ;
break;
#ifdef F_95
case V_319 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_320 ) ;
break;
case V_321 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_322 ) ;
break;
case V_323 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_324 ) ;
break;
case V_325 ... V_326 :
V_5 = V_79 - V_325 ;
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_327 [ V_5 ] ) ;
break;
case V_328 ... V_329 :
{
int V_242 ;
V_5 = V_79 - V_328 ;
if ( V_5 < 32 )
for ( V_242 = 0 ; V_242 < V_330 ; V_242 ++ )
V_255 -> V_331 [ V_242 ] = V_6 -> V_23 . V_332 . V_333 [ V_5 ] [ V_242 ] ;
else {
if ( F_4 ( V_334 ) )
V_255 -> V_335 = V_6 -> V_23 . V_336 . V_337 [ V_5 - 32 ] ;
else
V_53 = - V_338 ;
}
break;
}
case V_339 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_340 ) ;
break;
case V_341 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_342 ) ;
break;
case V_343 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_344 ) ;
break;
case V_345 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_332 . V_346 ) ;
break;
case V_347 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_348 ) ;
break;
case V_349 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_350 ) ;
break;
case V_351 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_352 ) ;
break;
case V_353 :
if ( F_4 ( V_334 ) )
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_336 . V_354 . V_237 [ 3 ] ) ;
else
V_53 = - V_338 ;
break;
case V_355 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_356 ) ;
break;
case V_357 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_358 ) ;
break;
#endif
case V_359 :
* V_255 = F_94 ( V_79 , V_6 -> V_23 . V_30 -> V_43 ) ;
break;
default:
V_53 = - V_51 ;
break;
}
return V_53 ;
}
static int F_96 ( struct V_1 * V_6 , T_1 V_79 ,
union V_254 * V_255 )
{
int V_53 = 0 ;
long int V_5 ;
unsigned long V_88 , V_89 ;
switch ( V_79 ) {
case V_257 :
if ( F_97 ( V_79 , * V_255 ) )
V_53 = - V_51 ;
break;
case V_258 :
V_6 -> V_23 . V_259 = F_97 ( V_79 , * V_255 ) ;
break;
case V_260 :
V_6 -> V_23 . V_261 = F_97 ( V_79 , * V_255 ) & ~ V_153 ;
break;
case V_262 :
V_6 -> V_23 . V_263 = F_97 ( V_79 , * V_255 ) ;
break;
case V_264 :
V_6 -> V_23 . V_265 = F_97 ( V_79 , * V_255 ) ;
break;
case V_266 :
V_6 -> V_23 . V_267 = F_97 ( V_79 , * V_255 ) ;
break;
case V_268 :
V_6 -> V_23 . V_269 = F_97 ( V_79 , * V_255 ) ;
break;
case V_270 :
V_6 -> V_23 . V_271 = F_97 ( V_79 , * V_255 ) ;
break;
case V_272 ... V_273 :
V_5 = V_79 - V_272 ;
V_6 -> V_23 . V_274 [ V_5 ] = F_97 ( V_79 , * V_255 ) ;
break;
case V_275 ... V_276 :
V_5 = V_79 - V_275 ;
V_6 -> V_23 . V_277 [ V_5 ] = F_97 ( V_79 , * V_255 ) ;
break;
case V_278 ... V_279 :
V_5 = V_79 - V_278 ;
V_6 -> V_23 . V_280 [ V_5 ] = F_97 ( V_79 , * V_255 ) ;
break;
case V_281 :
V_6 -> V_23 . V_282 = F_97 ( V_79 , * V_255 ) ;
break;
case V_283 :
V_6 -> V_23 . V_284 = F_97 ( V_79 , * V_255 ) ;
break;
case V_285 :
V_6 -> V_23 . V_286 = F_97 ( V_79 , * V_255 ) ;
break;
case V_287 :
V_6 -> V_23 . V_288 = F_97 ( V_79 , * V_255 ) ;
break;
case V_289 :
V_6 -> V_23 . V_290 = F_97 ( V_79 , * V_255 ) ;
break;
case V_291 :
V_6 -> V_23 . V_30 -> V_292 = F_97 ( V_79 , * V_255 ) ;
break;
case V_293 :
V_6 -> V_23 . V_30 -> V_294 = F_97 ( V_79 , * V_255 ) ;
break;
case V_295 :
V_6 -> V_23 . V_154 = F_97 ( V_79 , * V_255 ) ;
break;
case V_296 :
V_6 -> V_23 . V_155 = F_97 ( V_79 , * V_255 ) & ~ V_360 ;
break;
case V_297 :
V_6 -> V_23 . V_150 = F_97 ( V_79 , * V_255 ) ;
if ( ( V_6 -> V_23 . V_150 & V_147 ) == V_148 )
V_6 -> V_23 . V_150 &= ~ V_147 ;
break;
case V_298 :
V_6 -> V_23 . V_299 = F_97 ( V_79 , * V_255 ) ;
break;
case V_300 :
V_6 -> V_23 . V_301 = F_97 ( V_79 , * V_255 ) ;
break;
case V_302 :
V_6 -> V_23 . V_303 = F_97 ( V_79 , * V_255 ) ;
break;
case V_304 :
V_6 -> V_23 . V_305 = F_97 ( V_79 , * V_255 ) ;
break;
case V_306 :
V_6 -> V_23 . V_307 = F_97 ( V_79 , * V_255 ) ;
break;
case V_308 :
V_6 -> V_23 . V_309 = F_97 ( V_79 , * V_255 ) ;
break;
case V_310 :
V_88 = F_97 ( V_79 , * V_255 ) ;
V_53 = - V_51 ;
if ( ! V_88 && ( V_6 -> V_23 . V_115 . V_92 ||
V_6 -> V_23 . V_114 . V_92 ) )
break;
V_53 = F_42 ( V_6 , & V_6 -> V_23 . V_82 , V_88 , sizeof( struct V_81 ) ) ;
break;
case V_311 :
V_88 = V_255 -> V_312 . V_88 ;
V_89 = V_255 -> V_312 . V_109 ;
V_53 = - V_51 ;
if ( V_88 && ! V_6 -> V_23 . V_82 . V_92 )
break;
V_53 = F_42 ( V_6 , & V_6 -> V_23 . V_115 , V_88 , V_89 ) ;
break;
case V_313 :
V_88 = V_255 -> V_312 . V_88 ;
V_89 = V_255 -> V_312 . V_109 ;
V_53 = - V_51 ;
if ( V_88 && ( V_89 < sizeof( struct V_112 ) ||
! V_6 -> V_23 . V_82 . V_92 ) )
break;
V_89 -= V_89 % sizeof( struct V_112 ) ;
V_53 = F_42 ( V_6 , & V_6 -> V_23 . V_114 , V_88 , V_89 ) ;
break;
case V_314 :
V_6 -> V_23 . V_30 -> V_136 =
F_98 ( F_97 ( V_79 , * V_255 ) , 1UL << 24 ) ;
break;
case V_315 :
F_91 ( V_6 , F_97 ( V_79 , * V_255 ) , true ) ;
break;
case V_316 :
F_91 ( V_6 , F_97 ( V_79 , * V_255 ) , false ) ;
break;
case V_317 :
V_6 -> V_23 . V_318 = F_97 ( V_79 , * V_255 ) ;
break;
#ifdef F_95
case V_319 :
V_6 -> V_23 . V_320 = F_97 ( V_79 , * V_255 ) ;
break;
case V_321 :
V_6 -> V_23 . V_322 = F_97 ( V_79 , * V_255 ) ;
break;
case V_323 :
V_6 -> V_23 . V_324 = F_97 ( V_79 , * V_255 ) ;
break;
case V_325 ... V_326 :
V_5 = V_79 - V_325 ;
V_6 -> V_23 . V_327 [ V_5 ] = F_97 ( V_79 , * V_255 ) ;
break;
case V_328 ... V_329 :
{
int V_242 ;
V_5 = V_79 - V_328 ;
if ( V_5 < 32 )
for ( V_242 = 0 ; V_242 < V_330 ; V_242 ++ )
V_6 -> V_23 . V_332 . V_333 [ V_5 ] [ V_242 ] = V_255 -> V_331 [ V_242 ] ;
else
if ( F_4 ( V_334 ) )
V_6 -> V_23 . V_336 . V_337 [ V_5 - 32 ] = V_255 -> V_335 ;
else
V_53 = - V_338 ;
break;
}
case V_339 :
V_6 -> V_23 . V_340 = F_97 ( V_79 , * V_255 ) ;
break;
case V_341 :
V_6 -> V_23 . V_342 = F_97 ( V_79 , * V_255 ) ;
break;
case V_343 :
V_6 -> V_23 . V_344 = F_97 ( V_79 , * V_255 ) ;
break;
case V_345 :
V_6 -> V_23 . V_332 . V_346 = F_97 ( V_79 , * V_255 ) ;
break;
case V_347 :
V_6 -> V_23 . V_348 = F_97 ( V_79 , * V_255 ) ;
break;
case V_349 :
V_6 -> V_23 . V_350 = F_97 ( V_79 , * V_255 ) ;
break;
case V_351 :
V_6 -> V_23 . V_352 = F_97 ( V_79 , * V_255 ) ;
break;
case V_353 :
if ( F_4 ( V_334 ) )
V_6 -> V_23 . V_337 . V_354 . V_237 [ 3 ] = F_97 ( V_79 , * V_255 ) ;
else
V_53 = - V_338 ;
break;
case V_355 :
V_6 -> V_23 . V_356 = F_97 ( V_79 , * V_255 ) ;
break;
case V_357 :
V_6 -> V_23 . V_358 = F_97 ( V_79 , * V_255 ) ;
break;
#endif
case V_359 :
V_53 = F_30 ( V_6 , F_97 ( V_79 , * V_255 ) ) ;
break;
default:
V_53 = - V_51 ;
break;
}
return V_53 ;
}
static struct V_2 * F_99 ( struct V_76 * V_76 , int V_361 )
{
struct V_2 * V_30 ;
V_30 = F_100 ( sizeof( struct V_2 ) , V_362 ) ;
if ( V_30 == NULL )
return NULL ;
F_101 ( & V_30 -> V_52 ) ;
F_101 ( & V_30 -> V_26 ) ;
F_102 ( & V_30 -> V_169 ) ;
V_30 -> V_27 = V_28 ;
V_30 -> V_75 = V_76 -> V_23 . V_75 ;
V_30 -> V_363 = V_361 * V_364 ;
V_30 -> V_76 = V_76 ;
F_103 ( & V_30 -> V_365 ) ;
return V_30 ;
}
static int F_104 ( struct V_366 * V_366 , struct V_367 * V_367 )
{
struct V_1 * V_6 = V_366 -> V_368 ;
struct V_369 * V_125 ;
V_125 = F_100 ( sizeof( * V_125 ) , V_362 ) ;
if ( ! V_125 )
return - V_370 ;
F_105 ( V_6 -> V_76 ) ;
V_125 -> V_6 = V_6 ;
V_367 -> V_371 = V_125 ;
return F_106 ( V_366 , V_367 ) ;
}
static int F_107 ( struct V_366 * V_366 , struct V_367 * V_367 )
{
struct V_369 * V_125 = V_367 -> V_371 ;
F_108 ( V_125 -> V_6 -> V_76 ) ;
F_109 ( V_125 ) ;
return 0 ;
}
static T_4 F_110 ( struct V_367 * V_367 , char T_5 * V_372 ,
T_6 V_89 , T_7 * V_373 )
{
struct V_369 * V_125 = V_367 -> V_371 ;
struct V_1 * V_6 = V_125 -> V_6 ;
char * V_238 , * V_374 ;
struct V_375 V_376 ;
T_1 V_377 ;
T_7 V_378 ;
T_4 V_379 ;
int V_5 , V_380 ;
bool V_381 ;
if ( ! V_125 -> V_382 ) {
V_238 = V_125 -> V_372 ;
V_374 = V_238 + sizeof( V_125 -> V_372 ) ;
for ( V_5 = 0 ; V_5 < V_383 ; ++ V_5 ) {
struct V_375 * V_384 ;
V_384 = (struct V_375 * )
( ( unsigned long ) V_6 + V_385 [ V_5 ] . V_386 ) ;
V_381 = false ;
for ( V_380 = 0 ; V_380 < 1000 ; ++ V_380 ) {
V_377 = V_384 -> V_387 ;
if ( ! ( V_377 & 1 ) ) {
F_111 () ;
V_376 = * V_384 ;
F_111 () ;
if ( V_377 == V_384 -> V_387 ) {
V_381 = true ;
break;
}
}
F_112 ( 1 ) ;
}
if ( ! V_381 )
snprintf ( V_238 , V_374 - V_238 , L_16 ,
V_385 [ V_5 ] . V_388 ) ;
else
snprintf ( V_238 , V_374 - V_238 ,
L_17 ,
V_385 [ V_5 ] . V_388 , V_377 / 2 ,
F_113 ( V_376 . V_389 ) ,
F_113 ( V_376 . V_390 ) ,
F_113 ( V_376 . V_391 ) ) ;
V_238 += strlen ( V_238 ) ;
}
V_125 -> V_382 = V_238 - V_125 -> V_372 ;
}
V_378 = * V_373 ;
if ( V_378 >= V_125 -> V_382 )
return 0 ;
if ( V_89 > V_125 -> V_382 - V_378 )
V_89 = V_125 -> V_382 - V_378 ;
V_379 = F_114 ( V_372 , V_125 -> V_372 + V_378 , V_89 ) ;
if ( V_379 ) {
if ( V_379 == V_89 )
return - V_392 ;
V_89 -= V_379 ;
}
* V_373 = V_378 + V_89 ;
return V_89 ;
}
static T_4 F_115 ( struct V_367 * V_367 , const char T_5 * V_372 ,
T_6 V_89 , T_7 * V_373 )
{
return - V_393 ;
}
static void F_116 ( struct V_1 * V_6 , unsigned int V_79 )
{
char V_372 [ 16 ] ;
struct V_76 * V_76 = V_6 -> V_76 ;
snprintf ( V_372 , sizeof( V_372 ) , L_18 , V_79 ) ;
if ( F_117 ( V_76 -> V_23 . V_394 ) )
return;
V_6 -> V_23 . V_394 = F_118 ( V_372 , V_76 -> V_23 . V_394 ) ;
if ( F_117 ( V_6 -> V_23 . V_394 ) )
return;
V_6 -> V_23 . V_395 =
F_119 ( L_19 , 0444 , V_6 -> V_23 . V_394 ,
V_6 , & V_396 ) ;
}
static void F_116 ( struct V_1 * V_6 , unsigned int V_79 )
{
}
static struct V_1 * F_120 ( struct V_76 * V_76 ,
unsigned int V_79 )
{
struct V_1 * V_6 ;
int V_100 = - V_51 ;
int V_361 ;
struct V_2 * V_30 ;
V_361 = V_79 / V_364 ;
if ( V_361 >= V_397 )
goto V_398;
V_100 = - V_370 ;
V_6 = F_121 ( V_399 , V_362 ) ;
if ( ! V_6 )
goto V_398;
V_100 = F_122 ( V_6 , V_76 , V_79 ) ;
if ( V_100 )
goto V_400;
V_6 -> V_23 . V_401 = & V_6 -> V_23 . V_41 ;
#ifdef F_123
#ifdef F_124
V_6 -> V_23 . V_402 = true ;
#else
V_6 -> V_23 . V_402 = false ;
#endif
#endif
V_6 -> V_23 . V_274 [ 0 ] = V_403 ;
V_6 -> V_23 . V_404 = V_405 ;
F_29 ( V_6 , F_125 ( V_406 ) ) ;
F_101 ( & V_6 -> V_23 . V_91 ) ;
F_101 ( & V_6 -> V_23 . V_34 ) ;
V_6 -> V_23 . V_37 = V_28 ;
V_6 -> V_23 . V_249 = V_407 | V_408 ;
F_126 ( V_6 ) ;
V_6 -> V_23 . V_35 = V_409 ;
F_127 ( & V_6 -> V_23 . V_410 ) ;
F_37 ( & V_76 -> V_52 ) ;
V_30 = V_76 -> V_23 . V_411 [ V_361 ] ;
if ( ! V_30 ) {
V_30 = F_99 ( V_76 , V_361 ) ;
V_76 -> V_23 . V_411 [ V_361 ] = V_30 ;
V_76 -> V_23 . V_412 ++ ;
}
F_39 ( & V_76 -> V_52 ) ;
if ( ! V_30 )
goto V_400;
F_31 ( & V_30 -> V_52 ) ;
++ V_30 -> V_413 ;
F_32 ( & V_30 -> V_52 ) ;
V_6 -> V_23 . V_30 = V_30 ;
V_6 -> V_23 . V_134 = V_6 -> V_54 - V_30 -> V_363 ;
V_6 -> V_23 . V_24 = - 1 ;
V_6 -> V_23 . V_414 = V_415 ;
F_128 ( V_6 ) ;
F_116 ( V_6 , V_79 ) ;
return V_6 ;
V_400:
F_129 ( V_399 , V_6 ) ;
V_398:
return F_130 ( V_100 ) ;
}
static void F_131 ( struct V_76 * V_76 , struct V_86 * V_82 )
{
if ( V_82 -> V_95 )
F_48 ( V_76 , V_82 -> V_95 , V_82 -> V_119 ,
V_82 -> V_120 ) ;
}
static void F_132 ( struct V_1 * V_6 )
{
F_31 ( & V_6 -> V_23 . V_91 ) ;
F_131 ( V_6 -> V_76 , & V_6 -> V_23 . V_114 ) ;
F_131 ( V_6 -> V_76 , & V_6 -> V_23 . V_115 ) ;
F_131 ( V_6 -> V_76 , & V_6 -> V_23 . V_82 ) ;
F_32 ( & V_6 -> V_23 . V_91 ) ;
F_133 ( V_6 ) ;
F_129 ( V_399 , V_6 ) ;
}
static int F_134 ( struct V_1 * V_6 )
{
return 1 ;
}
static void F_135 ( struct V_1 * V_6 )
{
unsigned long V_416 , V_124 ;
V_124 = F_136 () ;
if ( V_124 > V_6 -> V_23 . V_417 ) {
F_137 ( V_6 ) ;
F_138 ( V_6 ) ;
return;
}
V_416 = ( V_6 -> V_23 . V_417 - V_124 ) * V_418
/ V_419 ;
F_139 ( & V_6 -> V_23 . V_420 , F_140 ( 0 , V_416 ) ,
V_421 ) ;
V_6 -> V_23 . V_422 = 1 ;
}
static void F_28 ( struct V_1 * V_6 )
{
V_6 -> V_23 . V_168 = 0 ;
if ( V_6 -> V_23 . V_422 ) {
F_141 ( & V_6 -> V_23 . V_420 ) ;
V_6 -> V_23 . V_422 = 0 ;
}
}
static void F_142 ( struct V_2 * V_3 ,
struct V_1 * V_6 )
{
T_1 V_124 ;
if ( V_6 -> V_23 . V_35 != V_158 )
return;
F_53 ( & V_6 -> V_23 . V_34 ) ;
V_124 = F_22 () ;
V_6 -> V_23 . V_38 += F_51 ( V_3 , V_124 ) -
V_6 -> V_23 . V_130 ;
V_6 -> V_23 . V_37 = V_124 ;
V_6 -> V_23 . V_35 = V_36 ;
F_54 ( & V_6 -> V_23 . V_34 ) ;
-- V_3 -> V_423 ;
F_143 ( V_3 -> V_8 [ V_6 -> V_23 . V_134 ] , NULL ) ;
}
static int F_144 ( int V_9 )
{
struct V_424 * V_425 ;
long V_426 = 10000 ;
V_425 = & V_16 [ V_9 ] ;
V_425 -> V_17 . V_1 = NULL ;
V_425 -> V_17 . V_427 = NULL ;
V_425 -> V_17 . V_428 = 0 ;
F_58 () ;
V_425 -> V_17 . V_429 = 1 ;
F_10 () ;
while ( V_425 -> V_17 . V_430 == V_431 ) {
if ( -- V_426 <= 0 ) {
F_34 ( L_20 , V_9 ) ;
return - V_432 ;
}
F_112 ( 1 ) ;
}
return 0 ;
}
static void F_145 ( int V_9 )
{
struct V_424 * V_425 ;
V_425 = & V_16 [ V_9 ] ;
V_425 -> V_17 . V_429 = 0 ;
V_425 -> V_17 . V_1 = NULL ;
V_425 -> V_17 . V_427 = NULL ;
V_425 -> V_17 . V_433 = NULL ;
}
static void F_146 ( struct V_1 * V_6 , struct V_2 * V_3 )
{
int V_9 ;
struct V_424 * V_425 ;
struct V_2 * V_434 = V_3 -> V_435 ;
V_9 = V_3 -> V_133 ;
if ( V_6 ) {
if ( V_6 -> V_23 . V_422 ) {
F_141 ( & V_6 -> V_23 . V_420 ) ;
V_6 -> V_23 . V_422 = 0 ;
}
V_9 += V_6 -> V_23 . V_134 ;
V_6 -> V_9 = V_434 -> V_133 ;
V_6 -> V_23 . V_24 = V_9 ;
}
V_425 = & V_16 [ V_9 ] ;
V_425 -> V_17 . V_1 = V_6 ;
V_425 -> V_17 . V_134 = V_9 - V_434 -> V_133 ;
F_58 () ;
V_425 -> V_17 . V_427 = V_434 ;
if ( V_9 != F_7 () )
F_3 ( V_9 ) ;
}
static void F_147 ( void )
{
int V_9 = F_7 () ;
int V_5 , V_380 ;
for ( V_380 = 0 ; V_380 < 1000000 ; ++ V_380 ) {
for ( V_5 = 1 ; V_5 < V_364 ; ++ V_5 )
if ( V_16 [ V_9 + V_5 ] . V_17 . V_427 )
break;
if ( V_5 == V_364 ) {
F_148 () ;
return;
}
F_149 () ;
}
F_148 () ;
for ( V_5 = 1 ; V_5 < V_364 ; ++ V_5 )
if ( V_16 [ V_9 + V_5 ] . V_17 . V_427 )
F_34 ( L_21 , V_9 + V_5 ) ;
}
static int F_150 ( void )
{
int V_9 = F_7 () ;
int V_436 ;
if ( F_151 ( V_9 ) )
return 0 ;
V_436 = 0 ;
while ( ++ V_436 < V_364 )
if ( F_18 ( V_9 + V_436 ) )
return 0 ;
for ( V_436 = 1 ; V_436 < V_364 ; ++ V_436 ) {
if ( F_144 ( V_9 + V_436 ) ) {
do {
F_145 ( V_9 + V_436 ) ;
} while ( -- V_436 > 0 );
return 0 ;
}
}
return 1 ;
}
static void F_152 ( void )
{
int V_9 ;
F_153 (cpu) {
struct V_437 * V_438 = & F_154 ( V_439 , V_9 ) ;
F_101 ( & V_438 -> V_52 ) ;
F_103 ( & V_438 -> V_440 ) ;
}
}
static void F_155 ( struct V_2 * V_3 )
{
struct V_437 * V_438 = F_156 ( & V_439 ) ;
V_3 -> V_32 = V_441 ;
V_3 -> V_133 = F_7 () ;
if ( V_3 -> V_413 < V_364 ) {
F_31 ( & V_438 -> V_52 ) ;
F_157 ( & V_3 -> V_365 , & V_438 -> V_440 ) ;
F_32 ( & V_438 -> V_52 ) ;
}
F_20 ( V_3 ) ;
}
static void F_158 ( struct V_2 * V_3 )
{
struct V_437 * V_438 ;
F_24 ( V_3 ) ;
if ( ! F_66 ( & V_3 -> V_365 ) ) {
V_438 = & F_154 ( V_439 , V_3 -> V_133 ) ;
F_31 ( & V_438 -> V_52 ) ;
F_159 ( & V_3 -> V_365 ) ;
F_32 ( & V_438 -> V_52 ) ;
}
V_3 -> V_32 = V_126 ;
}
static void F_160 ( struct V_442 * V_443 , struct V_2 * V_3 )
{
int V_444 ;
memset ( V_443 , 0 , sizeof( * V_443 ) ) ;
V_443 -> V_445 = 1 ;
V_443 -> V_446 = V_3 -> V_413 ;
V_443 -> V_447 = V_3 -> V_413 ;
V_443 -> V_448 [ 0 ] = V_3 -> V_413 ;
V_443 -> V_449 [ 0 ] = V_3 -> V_76 ;
for ( V_444 = 0 ; V_444 < V_450 ; ++ V_444 )
F_103 ( & V_443 -> V_451 [ V_444 ] ) ;
F_157 ( & V_3 -> V_365 , & V_443 -> V_451 [ 0 ] ) ;
}
static bool F_161 ( int V_445 , int V_452 )
{
if ( V_445 > 1 && V_364 < V_7 )
return false ;
if ( V_445 > V_450 )
return false ;
if ( V_445 > 1 ) {
if ( ! ( V_453 & 2 ) )
V_445 = 4 ;
if ( V_445 > 2 && ! ( V_453 & 4 ) )
return false ;
}
return V_445 * F_162 ( V_452 ) <= V_7 ;
}
static void F_163 ( struct V_2 * V_3 )
{
V_3 -> V_435 = V_3 ;
V_3 -> V_454 = 0 ;
V_3 -> V_455 = 0 ;
V_3 -> V_456 = 0 ;
V_3 -> V_457 = 0 ;
}
static bool F_164 ( struct V_2 * V_3 , struct V_442 * V_443 )
{
int V_452 = V_3 -> V_413 ;
int V_444 ;
if ( ! F_4 ( V_10 ) )
return false ;
if ( V_452 < V_443 -> V_446 )
V_452 = V_443 -> V_446 ;
if ( ! F_161 ( V_443 -> V_445 + 1 , V_452 ) )
return false ;
V_443 -> V_446 = V_452 ;
V_444 = V_443 -> V_445 ;
++ V_443 -> V_445 ;
V_443 -> V_447 += V_3 -> V_413 ;
V_443 -> V_448 [ V_444 ] = V_3 -> V_413 ;
V_443 -> V_449 [ V_444 ] = V_3 -> V_76 ;
F_163 ( V_3 ) ;
F_165 ( & V_3 -> V_365 ) ;
F_157 ( & V_3 -> V_365 , & V_443 -> V_451 [ V_444 ] ) ;
return true ;
}
static bool F_166 ( struct V_2 * V_458 , struct V_442 * V_443 ,
int V_459 )
{
if ( V_443 -> V_447 + V_458 -> V_413 > V_459 )
return false ;
return F_164 ( V_458 , V_443 ) ;
}
static void F_167 ( struct V_2 * V_3 )
{
int V_5 ;
struct V_1 * V_6 ;
F_168 (i, vcpu, vc) {
if ( F_169 ( V_6 -> V_23 . V_460 ) )
V_6 -> V_23 . V_80 = - V_461 ;
else if ( V_6 -> V_23 . V_82 . V_93 ||
V_6 -> V_23 . V_115 . V_93 ||
V_6 -> V_23 . V_114 . V_93 )
V_6 -> V_23 . V_80 = V_189 ;
else
continue;
F_142 ( V_3 , V_6 ) ;
F_170 ( & V_6 -> V_23 . V_410 ) ;
}
}
static void F_171 ( struct V_442 * V_443 , int V_459 )
{
struct V_437 * V_438 = F_156 ( & V_439 ) ;
struct V_2 * V_458 , * V_462 ;
F_31 ( & V_438 -> V_52 ) ;
F_172 (pvc, vcnext, &lp->list, preempt_list) {
if ( ! F_173 ( & V_458 -> V_52 ) )
continue;
F_167 ( V_458 ) ;
if ( ! V_458 -> V_423 ) {
F_159 ( & V_458 -> V_365 ) ;
if ( V_458 -> V_31 == NULL ) {
V_458 -> V_32 = V_126 ;
F_24 ( V_458 ) ;
}
F_32 ( & V_458 -> V_52 ) ;
continue;
}
if ( ! F_166 ( V_458 , V_443 , V_459 ) ) {
F_32 ( & V_458 -> V_52 ) ;
continue;
}
F_24 ( V_458 ) ;
V_458 -> V_32 = V_463 ;
if ( V_443 -> V_447 >= V_459 )
break;
}
F_32 ( & V_438 -> V_52 ) ;
}
static void F_174 ( struct V_2 * V_3 , bool V_464 )
{
int V_465 = 0 , V_5 ;
T_1 V_124 ;
long V_80 ;
struct V_1 * V_6 ;
F_31 ( & V_3 -> V_52 ) ;
V_124 = F_136 () ;
F_168 (i, vcpu, vc) {
if ( V_124 < V_6 -> V_23 . V_417 &&
F_175 ( V_6 ) )
F_176 ( V_6 ) ;
F_177 ( V_6 ) ;
V_80 = V_189 ;
if ( V_6 -> V_23 . V_56 )
V_80 = F_84 ( V_6 -> V_23 . V_191 , V_6 ,
V_6 -> V_23 . V_460 ) ;
V_6 -> V_23 . V_80 = V_80 ;
V_6 -> V_23 . V_56 = 0 ;
if ( F_178 ( V_6 -> V_23 . V_80 ) ) {
if ( V_6 -> V_23 . V_466 )
F_138 ( V_6 ) ;
if ( V_6 -> V_23 . V_168 )
F_135 ( V_6 ) ;
else
++ V_465 ;
} else {
F_142 ( V_3 , V_6 ) ;
F_170 ( & V_6 -> V_23 . V_410 ) ;
}
}
F_159 ( & V_3 -> V_365 ) ;
if ( ! V_464 ) {
if ( V_465 > 0 ) {
F_155 ( V_3 ) ;
} else if ( V_3 -> V_31 ) {
V_3 -> V_32 = V_441 ;
F_20 ( V_3 ) ;
} else {
V_3 -> V_32 = V_126 ;
}
if ( V_3 -> V_423 > 0 && V_3 -> V_31 == NULL ) {
V_5 = - 1 ;
V_6 = F_1 ( V_3 , & V_5 ) ;
F_170 ( & V_6 -> V_23 . V_410 ) ;
}
}
F_32 ( & V_3 -> V_52 ) ;
}
static inline void F_179 ( int V_9 )
{
int V_361 ;
if ( ! V_467 || F_9 ( V_9 ) )
return;
V_361 = V_9 >> V_468 ;
V_467 -> V_469 [ V_361 ] . V_470 . V_471 = 0 ;
}
static inline void F_180 ( int V_9 )
{
int V_361 ;
if ( ! V_467 || F_9 ( V_9 ) )
return;
V_361 = V_9 >> V_468 ;
V_467 -> V_469 [ V_361 ] . V_470 . V_471 = 1 ;
}
static T_8 void F_181 ( struct V_2 * V_3 )
{
struct V_1 * V_6 ;
int V_5 ;
int V_472 ;
struct V_442 V_442 ;
struct V_2 * V_458 , * V_462 ;
struct V_433 V_473 , * V_474 ;
int V_475 , V_476 , V_477 ;
int V_444 ;
bool V_478 ;
unsigned long V_479 , V_480 ;
int V_133 , V_436 ;
int V_459 ;
F_167 ( V_3 ) ;
if ( V_3 -> V_31 -> V_23 . V_35 != V_158 )
return;
F_163 ( V_3 ) ;
V_3 -> V_27 = V_28 ;
if ( ( V_481 > 1 ) &&
( ( V_3 -> V_413 > V_364 ) || ! F_150 () ) ) {
F_168 (i, vcpu, vc) {
V_6 -> V_23 . V_80 = - V_432 ;
F_142 ( V_3 , V_6 ) ;
F_170 ( & V_6 -> V_23 . V_410 ) ;
}
goto V_398;
}
F_160 ( & V_442 , V_3 ) ;
V_133 = F_7 () ;
V_459 = V_364 ;
if ( V_482 && V_482 < V_459 )
V_459 = V_482 ;
if ( V_3 -> V_413 < V_459 )
F_171 ( & V_442 , V_459 ) ;
V_476 = V_364 ;
V_479 = V_480 = 0 ;
V_475 = V_442 . V_445 ;
V_474 = NULL ;
if ( V_475 > 1 ) {
if ( V_475 == 2 && ( V_453 & 2 ) ) {
V_479 = V_483 ;
V_480 = V_484 ;
} else {
V_475 = 4 ;
V_479 = V_485 ;
V_480 = V_486 ;
}
V_476 = V_7 / V_475 ;
V_474 = & V_473 ;
memset ( & V_473 , 0 , sizeof( V_473 ) ) ;
V_473 . V_487 = F_125 ( V_488 ) ;
V_473 . V_489 = F_125 ( V_490 ) ;
V_473 . V_491 = F_125 ( V_492 ) ;
V_473 . V_476 = V_476 ;
for ( V_444 = 0 ; V_444 < V_442 . V_445 ; ++ V_444 )
V_473 . V_493 [ V_444 ] =
F_182 ( & V_442 . V_451 [ V_444 ] ,
struct V_2 , V_365 ) ;
F_58 () ;
}
V_133 = F_7 () ;
for ( V_436 = 0 ; V_436 < V_364 ; ++ V_436 )
V_16 [ V_133 + V_436 ] . V_17 . V_433 = V_474 ;
if ( V_479 ) {
unsigned long V_494 = F_125 ( V_495 ) ;
V_494 |= V_479 | V_496 ;
F_183 () ;
F_184 ( V_495 , V_494 ) ;
F_185 () ;
for (; ; ) {
V_494 = F_125 ( V_495 ) ;
if ( V_494 & V_480 )
break;
F_186 () ;
}
}
F_179 ( V_133 ) ;
V_477 = 0 ;
for ( V_444 = 0 ; V_444 < V_442 . V_445 ; ++ V_444 ) {
V_436 = V_497 [ V_444 ] ;
V_478 = false ;
V_477 |= 1 << V_436 ;
F_187 (pvc, &core_info.vcs[sub], preempt_list) {
V_458 -> V_133 = V_133 + V_436 ;
F_168 (i, vcpu, pvc) {
F_146 ( V_6 , V_458 ) ;
F_52 ( V_6 , V_458 ) ;
F_188 ( V_6 ) ;
if ( ! V_6 -> V_23 . V_134 )
V_478 = true ;
V_477 |= 1 << ( V_436 + V_6 -> V_23 . V_134 ) ;
}
if ( V_458 -> V_435 == V_458 && ! V_478 )
F_146 ( NULL , V_458 ) ;
V_436 += V_458 -> V_413 ;
}
}
F_10 () ;
if ( V_479 )
V_473 . V_498 = 1 ;
if ( V_475 > 1 )
for ( V_436 = 1 ; V_436 < V_364 ; ++ V_436 )
if ( ! ( V_477 & ( 1 << V_436 ) ) )
F_3 ( V_133 + V_436 ) ;
V_3 -> V_32 = V_499 ;
F_5 () ;
F_189 ( V_3 , 0 ) ;
for ( V_444 = 0 ; V_444 < V_442 . V_445 ; ++ V_444 )
F_187 (pvc, &core_info.vcs[sub], preempt_list)
F_32 ( & V_458 -> V_52 ) ;
F_190 () ;
V_472 = F_67 ( & V_3 -> V_76 -> V_174 ) ;
F_191 () ;
F_69 ( & V_3 -> V_76 -> V_174 , V_472 ) ;
F_31 ( & V_3 -> V_52 ) ;
V_3 -> V_32 = V_500 ;
F_147 () ;
if ( V_475 > 1 ) {
unsigned long V_494 = F_125 ( V_495 ) ;
unsigned long V_380 = 0 ;
V_494 &= ~ V_496 ;
V_480 = V_484 | V_486 ;
F_183 () ;
F_184 ( V_495 , V_494 ) ;
F_185 () ;
for (; ; ) {
V_494 = F_125 ( V_495 ) ;
if ( ! ( V_494 & V_480 ) )
break;
F_186 () ;
++ V_380 ;
}
V_473 . V_498 = 0 ;
}
for ( V_5 = 0 ; V_5 < V_364 ; ++ V_5 ) {
F_145 ( V_133 + V_5 ) ;
if ( V_474 && V_474 -> V_501 [ V_5 ] )
F_3 ( V_133 + V_5 ) ;
}
F_180 ( V_133 ) ;
F_32 ( & V_3 -> V_52 ) ;
F_10 () ;
F_192 () ;
for ( V_444 = 0 ; V_444 < V_442 . V_445 ; ++ V_444 )
F_172 (pvc, vcnext, &core_info.vcs[sub],
preempt_list)
F_174 ( V_458 , V_458 == V_3 ) ;
F_31 ( & V_3 -> V_52 ) ;
F_11 () ;
V_398:
V_3 -> V_32 = V_126 ;
F_189 ( V_3 , 1 ) ;
}
static void F_193 ( struct V_2 * V_3 ,
struct V_1 * V_6 , int V_502 )
{
F_194 ( V_503 ) ;
F_195 ( & V_6 -> V_23 . V_410 , & V_503 , V_502 ) ;
if ( V_6 -> V_23 . V_35 == V_158 ) {
F_32 ( & V_3 -> V_52 ) ;
F_196 () ;
F_31 ( & V_3 -> V_52 ) ;
}
F_197 ( & V_6 -> V_23 . V_410 , & V_503 ) ;
}
static void F_198 ( struct V_2 * V_3 )
{
if ( V_3 -> V_504 == 0 && V_505 )
V_3 -> V_504 = 10000 ;
else
V_3 -> V_504 *= V_505 ;
if ( V_3 -> V_504 > V_506 )
V_3 -> V_504 = V_506 ;
}
static void F_199 ( struct V_2 * V_3 )
{
if ( V_507 == 0 )
V_3 -> V_504 = 0 ;
else
V_3 -> V_504 /= V_507 ;
}
static int F_200 ( struct V_2 * V_3 )
{
struct V_1 * V_6 ;
int V_5 ;
F_168 (i, vcpu, vc) {
if ( V_6 -> V_23 . V_466 || ! V_6 -> V_23 . V_168 )
return 1 ;
}
return 0 ;
}
static void F_201 ( struct V_2 * V_3 )
{
T_9 V_508 , V_509 , V_510 ;
int V_511 = 1 ;
T_1 V_512 ;
F_202 ( V_503 ) ;
V_508 = V_509 = F_203 () ;
if ( V_3 -> V_504 ) {
T_9 V_513 = F_204 ( V_509 , V_3 -> V_504 ) ;
++ V_3 -> V_31 -> V_21 . V_514 ;
V_3 -> V_32 = V_515 ;
F_32 ( & V_3 -> V_52 ) ;
do {
if ( F_200 ( V_3 ) ) {
V_511 = 0 ;
break;
}
V_508 = F_203 () ;
} while ( F_205 () && F_206 ( V_508 , V_513 ) );
F_31 ( & V_3 -> V_52 ) ;
V_3 -> V_32 = V_126 ;
if ( ! V_511 ) {
++ V_3 -> V_31 -> V_21 . V_516 ;
goto V_398;
}
}
F_207 ( & V_3 -> V_169 , & V_503 , V_517 ) ;
if ( F_200 ( V_3 ) ) {
F_208 ( & V_3 -> V_169 , & V_503 ) ;
V_511 = 0 ;
if ( V_3 -> V_504 )
++ V_3 -> V_31 -> V_21 . V_516 ;
goto V_398;
}
V_510 = F_203 () ;
V_3 -> V_32 = V_33 ;
F_209 ( V_3 , 0 ) ;
F_32 ( & V_3 -> V_52 ) ;
F_196 () ;
F_208 ( & V_3 -> V_169 , & V_503 ) ;
F_31 ( & V_3 -> V_52 ) ;
V_3 -> V_32 = V_126 ;
F_209 ( V_3 , 1 ) ;
++ V_3 -> V_31 -> V_21 . V_518 ;
V_508 = F_203 () ;
V_398:
V_512 = F_210 ( V_508 ) - F_210 ( V_509 ) ;
if ( V_511 ) {
V_3 -> V_31 -> V_21 . V_519 +=
F_210 ( V_508 ) - F_210 ( V_510 ) ;
if ( V_3 -> V_504 )
V_3 -> V_31 -> V_21 . V_520 +=
F_210 ( V_510 ) -
F_210 ( V_509 ) ;
} else {
if ( V_3 -> V_504 )
V_3 -> V_31 -> V_21 . V_521 +=
F_210 ( V_508 ) -
F_210 ( V_509 ) ;
}
if ( V_506 ) {
if ( V_512 <= V_3 -> V_504 )
;
else if ( V_3 -> V_504 && V_512 > V_506 )
F_199 ( V_3 ) ;
else if ( V_3 -> V_504 < V_506 &&
V_512 < V_506 )
F_198 ( V_3 ) ;
} else
V_3 -> V_504 = 0 ;
F_211 ( V_511 , V_512 ) ;
}
static int F_212 ( struct V_191 * V_191 , struct V_1 * V_6 )
{
int V_522 , V_5 ;
struct V_2 * V_3 ;
struct V_1 * V_87 ;
F_213 ( V_6 ) ;
V_191 -> V_196 = 0 ;
V_6 -> V_23 . V_80 = V_189 ;
V_6 -> V_23 . V_56 = 0 ;
F_50 ( V_6 ) ;
V_3 = V_6 -> V_23 . V_30 ;
F_31 ( & V_3 -> V_52 ) ;
V_6 -> V_23 . V_168 = 0 ;
V_6 -> V_23 . V_460 = V_523 ;
V_6 -> V_23 . V_191 = V_191 ;
V_6 -> V_23 . V_130 = F_51 ( V_3 , F_22 () ) ;
V_6 -> V_23 . V_35 = V_158 ;
V_6 -> V_23 . V_37 = V_28 ;
F_143 ( V_3 -> V_8 [ V_6 -> V_23 . V_134 ] , V_6 ) ;
++ V_3 -> V_423 ;
if ( ! F_169 ( V_523 ) ) {
if ( V_3 -> V_32 == V_463 ) {
struct V_2 * V_434 = V_3 -> V_435 ;
if ( F_173 ( & V_434 -> V_52 ) ) {
if ( V_434 -> V_32 == V_499 &&
! F_214 ( V_434 ) ) {
F_52 ( V_6 , V_3 ) ;
F_146 ( V_6 , V_3 ) ;
F_188 ( V_6 ) ;
}
F_32 ( & V_434 -> V_52 ) ;
}
} else if ( V_3 -> V_32 == V_499 &&
! F_214 ( V_3 ) ) {
F_52 ( V_6 , V_3 ) ;
F_146 ( V_6 , V_3 ) ;
F_188 ( V_6 ) ;
} else if ( V_3 -> V_32 == V_33 ) {
F_17 ( & V_3 -> V_169 ) ;
}
}
while ( V_6 -> V_23 . V_35 == V_158 &&
! F_169 ( V_523 ) ) {
if ( V_3 -> V_32 == V_441 && V_3 -> V_31 == NULL )
F_158 ( V_3 ) ;
if ( V_3 -> V_32 != V_126 ) {
F_193 ( V_3 , V_6 , V_517 ) ;
continue;
}
F_168 (i, v, vc) {
F_138 ( V_87 ) ;
if ( F_169 ( V_87 -> V_23 . V_460 ) ) {
F_142 ( V_3 , V_87 ) ;
V_87 -> V_21 . V_524 ++ ;
V_87 -> V_23 . V_191 -> V_196 = V_525 ;
V_87 -> V_23 . V_80 = - V_461 ;
F_170 ( & V_87 -> V_23 . V_410 ) ;
}
}
if ( ! V_3 -> V_423 || V_6 -> V_23 . V_35 != V_158 )
break;
V_522 = 0 ;
F_168 (i, v, vc) {
if ( ! V_87 -> V_23 . V_466 )
V_522 += V_87 -> V_23 . V_168 ;
else
V_87 -> V_23 . V_168 = 0 ;
}
V_3 -> V_31 = V_6 ;
if ( V_522 == V_3 -> V_423 ) {
F_201 ( V_3 ) ;
} else if ( F_215 () ) {
F_155 ( V_3 ) ;
F_216 ( & V_3 -> V_52 ) ;
if ( V_3 -> V_32 == V_441 )
F_158 ( V_3 ) ;
} else {
F_181 ( V_3 ) ;
}
V_3 -> V_31 = NULL ;
}
while ( V_6 -> V_23 . V_35 == V_158 &&
( V_3 -> V_32 == V_499 ||
V_3 -> V_32 == V_500 ||
V_3 -> V_32 == V_463 ) )
F_193 ( V_3 , V_6 , V_526 ) ;
if ( V_3 -> V_32 == V_441 && V_3 -> V_31 == NULL )
F_158 ( V_3 ) ;
if ( V_6 -> V_23 . V_35 == V_158 ) {
F_142 ( V_3 , V_6 ) ;
V_6 -> V_21 . V_524 ++ ;
V_191 -> V_196 = V_525 ;
V_6 -> V_23 . V_80 = - V_461 ;
}
if ( V_3 -> V_423 && V_3 -> V_32 == V_126 ) {
V_5 = - 1 ;
V_87 = F_1 ( V_3 , & V_5 ) ;
F_170 ( & V_87 -> V_23 . V_410 ) ;
}
F_217 ( V_6 , V_191 ) ;
F_32 ( & V_3 -> V_52 ) ;
return V_6 -> V_23 . V_80 ;
}
static int F_218 ( struct V_191 * V_192 , struct V_1 * V_6 )
{
int V_53 ;
int V_472 ;
if ( ! V_6 -> V_23 . V_527 ) {
V_192 -> V_196 = V_206 ;
return - V_51 ;
}
F_138 ( V_6 ) ;
if ( F_169 ( V_523 ) ) {
V_192 -> V_196 = V_525 ;
return - V_461 ;
}
F_219 ( & V_6 -> V_76 -> V_23 . V_528 ) ;
F_10 () ;
if ( ! V_6 -> V_76 -> V_23 . V_529 ) {
V_53 = F_220 ( V_6 ) ;
if ( V_53 )
goto V_398;
}
F_221 ( V_523 ) ;
V_6 -> V_23 . V_20 = & V_6 -> V_23 . V_30 -> V_169 ;
V_6 -> V_23 . V_530 = V_523 -> V_531 -> V_532 ;
V_6 -> V_23 . V_35 = V_36 ;
do {
V_53 = F_212 ( V_192 , V_6 ) ;
if ( V_192 -> V_196 == V_223 &&
! ( V_6 -> V_23 . V_41 . V_39 & V_533 ) ) {
F_222 ( V_6 ) ;
V_53 = F_64 ( V_6 ) ;
F_223 ( V_6 , V_53 ) ;
F_138 ( V_6 ) ;
} else if ( V_53 == V_225 ) {
V_472 = F_67 ( & V_6 -> V_76 -> V_174 ) ;
V_53 = F_224 ( V_192 , V_6 ,
V_6 -> V_23 . V_69 , V_6 -> V_23 . V_70 ) ;
F_69 ( & V_6 -> V_76 -> V_174 , V_472 ) ;
} else if ( V_53 == V_234 )
V_53 = F_225 ( V_6 , 0 ) ;
} while ( F_178 ( V_53 ) );
V_398:
V_6 -> V_23 . V_35 = V_409 ;
F_226 ( & V_6 -> V_76 -> V_23 . V_528 ) ;
return V_53 ;
}
static void F_227 ( struct V_534 * * V_535 ,
int V_536 )
{
struct V_537 * V_538 = & V_539 [ V_536 ] ;
if ( ! V_538 -> V_540 )
return;
( * V_535 ) -> V_541 = V_538 -> V_540 ;
( * V_535 ) -> V_542 = V_538 -> V_543 ;
( * V_535 ) -> V_544 [ 0 ] . V_541 = V_538 -> V_540 ;
( * V_535 ) -> V_544 [ 0 ] . V_545 = V_538 -> V_546 [ V_536 ] ;
if ( V_536 != V_547 && V_538 -> V_546 [ V_547 ] != - 1 ) {
( * V_535 ) -> V_544 [ 1 ] . V_541 = 24 ;
( * V_535 ) -> V_544 [ 1 ] . V_545 = V_538 -> V_546 [ V_547 ] ;
}
( * V_535 ) ++ ;
}
static int F_228 ( struct V_76 * V_76 ,
struct V_548 * V_549 )
{
struct V_534 * V_535 ;
V_549 -> V_25 = V_550 ;
if ( F_229 ( V_551 ) )
V_549 -> V_25 |= V_552 ;
V_549 -> V_553 = V_554 ;
V_535 = & V_549 -> V_535 [ 0 ] ;
F_227 ( & V_535 , V_555 ) ;
F_227 ( & V_535 , V_556 ) ;
F_227 ( & V_535 , V_547 ) ;
return 0 ;
}
static int F_230 ( struct V_76 * V_76 ,
struct V_557 * log )
{
struct V_558 * V_559 ;
struct V_560 * V_561 ;
int V_53 ;
unsigned long V_379 ;
F_37 ( & V_76 -> V_562 ) ;
V_53 = - V_51 ;
if ( log -> V_563 >= V_564 )
goto V_398;
V_559 = V_558 ( V_76 ) ;
V_561 = F_231 ( V_559 , log -> V_563 ) ;
V_53 = - V_175 ;
if ( ! V_561 -> V_565 )
goto V_398;
V_379 = F_232 ( V_561 ) ;
memset ( V_561 -> V_565 , 0 , V_379 ) ;
V_53 = F_233 ( V_76 , V_561 , V_561 -> V_565 ) ;
if ( V_53 )
goto V_398;
V_53 = - V_392 ;
if ( F_114 ( log -> V_565 , V_561 -> V_565 , V_379 ) )
goto V_398;
V_53 = 0 ;
V_398:
F_39 ( & V_76 -> V_562 ) ;
return V_53 ;
}
static void F_234 ( struct V_560 * free ,
struct V_560 * V_566 )
{
if ( ! V_566 || free -> V_23 . V_567 != V_566 -> V_23 . V_567 ) {
F_235 ( free -> V_23 . V_567 ) ;
free -> V_23 . V_567 = NULL ;
}
}
static int F_236 ( struct V_560 * V_563 ,
unsigned long V_568 )
{
V_563 -> V_23 . V_567 = F_237 ( V_568 * sizeof( * V_563 -> V_23 . V_567 ) ) ;
if ( ! V_563 -> V_23 . V_567 )
return - V_370 ;
return 0 ;
}
static int F_238 ( struct V_76 * V_76 ,
struct V_560 * V_561 ,
const struct V_569 * V_570 )
{
return 0 ;
}
static void F_239 ( struct V_76 * V_76 ,
const struct V_569 * V_570 ,
const struct V_560 * V_571 ,
const struct V_560 * V_572 )
{
unsigned long V_568 = V_570 -> V_573 >> V_574 ;
struct V_558 * V_559 ;
struct V_560 * V_561 ;
if ( V_568 && V_571 -> V_568 ) {
V_559 = V_558 ( V_76 ) ;
V_561 = F_231 ( V_559 , V_570 -> V_563 ) ;
F_233 ( V_76 , V_561 , NULL ) ;
}
}
void F_240 ( struct V_76 * V_76 , unsigned long V_75 , unsigned long V_247 )
{
long int V_5 ;
T_2 V_575 = 0 ;
if ( ( V_76 -> V_23 . V_75 & V_247 ) == V_75 )
return;
V_76 -> V_23 . V_75 = ( V_76 -> V_23 . V_75 & ~ V_247 ) | V_75 ;
for ( V_5 = 0 ; V_5 < V_397 ; ++ V_5 ) {
struct V_2 * V_3 = V_76 -> V_23 . V_411 [ V_5 ] ;
if ( ! V_3 )
continue;
F_31 ( & V_3 -> V_52 ) ;
V_3 -> V_75 = ( V_3 -> V_75 & ~ V_247 ) | V_75 ;
F_32 ( & V_3 -> V_52 ) ;
if ( ++ V_575 >= V_76 -> V_23 . V_412 )
break;
}
}
static void F_241 ( struct V_1 * V_6 )
{
return;
}
static int F_220 ( struct V_1 * V_6 )
{
int V_100 = 0 ;
struct V_76 * V_76 = V_6 -> V_76 ;
unsigned long V_576 ;
struct V_560 * V_561 ;
struct V_577 * V_578 ;
unsigned long V_75 = 0 , V_579 ;
unsigned long V_580 , V_581 ;
int V_472 ;
F_37 ( & V_76 -> V_52 ) ;
if ( V_76 -> V_23 . V_529 )
goto V_398;
if ( ! V_76 -> V_23 . V_582 ) {
V_100 = F_242 ( V_76 , NULL ) ;
if ( V_100 ) {
F_34 ( L_22 ) ;
goto V_398;
}
}
V_472 = F_67 ( & V_76 -> V_174 ) ;
V_561 = F_243 ( V_76 , 0 ) ;
V_100 = - V_51 ;
if ( ! V_561 || ( V_561 -> V_25 & V_583 ) )
goto V_584;
V_576 = V_561 -> V_585 ;
F_244 ( & V_523 -> V_531 -> V_586 ) ;
V_578 = F_245 ( V_523 -> V_531 , V_576 ) ;
if ( ! V_578 || V_578 -> V_587 > V_576 || ( V_578 -> V_588 & V_589 ) )
goto V_590;
V_580 = F_246 ( V_578 ) ;
V_581 = F_247 ( V_580 ) ;
F_248 ( & V_523 -> V_531 -> V_586 ) ;
V_100 = - V_51 ;
if ( ! ( V_580 == 0x1000 || V_580 == 0x10000 ||
V_580 == 0x1000000 ) )
goto V_584;
V_579 = F_249 ( V_580 ) ;
V_76 -> V_23 . V_591 = V_579 | V_592 |
( V_593 << V_594 ) ;
V_75 = V_579 << ( V_595 - 4 ) ;
F_250 ( V_6 , V_561 , V_581 ) ;
F_240 ( V_76 , V_75 , V_596 ) ;
F_58 () ;
V_76 -> V_23 . V_529 = 1 ;
V_100 = 0 ;
V_584:
F_69 ( & V_76 -> V_174 , V_472 ) ;
V_398:
F_39 ( & V_76 -> V_52 ) ;
return V_100 ;
V_590:
F_248 ( & V_523 -> V_531 -> V_586 ) ;
goto V_584;
}
static int F_251 ( struct V_597 * V_598 , unsigned long V_599 ,
void * V_600 )
{
unsigned long V_9 = ( long ) V_600 ;
switch ( V_599 ) {
case V_601 :
case V_602 :
F_180 ( V_9 ) ;
break;
#ifdef F_252
case V_603 :
case V_604 :
case V_605 :
case V_606 :
F_179 ( V_9 ) ;
break;
#endif
default:
break;
}
return V_607 ;
}
void F_253 ( void )
{
struct V_608 * V_609 ;
unsigned long V_610 ;
int V_9 , V_361 ;
int V_611 ;
if ( V_467 != NULL )
return;
V_609 = F_100 ( sizeof( struct V_608 ) , V_362 ) ;
if ( ! V_609 )
return;
V_611 = F_254 () * sizeof( struct V_612 ) ;
V_609 -> V_469 = F_100 ( V_611 , V_362 ) ;
if ( ! V_609 -> V_469 ) {
F_109 ( V_609 ) ;
return;
}
F_255 () ;
for ( V_9 = 0 ; V_9 < V_15 ; V_9 += V_481 ) {
if ( ! F_18 ( V_9 ) )
continue;
V_361 = V_9 >> V_468 ;
V_609 -> V_469 [ V_361 ] . V_470 . V_471 = 1 ;
}
V_609 -> V_613 = F_14 ;
F_58 () ;
V_610 = ( unsigned long ) V_609 ;
if ( F_256 ( ( unsigned long * ) & V_467 , 0 , V_610 ) ) {
F_257 () ;
F_109 ( V_609 -> V_469 ) ;
F_109 ( V_609 ) ;
return;
}
F_258 ( & V_614 ) ;
F_257 () ;
}
void F_259 ( void )
{
if ( V_467 ) {
F_260 ( & V_614 ) ;
F_109 ( V_467 -> V_469 ) ;
F_109 ( V_467 ) ;
V_467 = NULL ;
}
}
static int F_261 ( struct V_76 * V_76 )
{
unsigned long V_75 , V_615 ;
char V_372 [ 32 ] ;
V_615 = F_262 () ;
if ( ( long ) V_615 < 0 )
return - V_370 ;
V_76 -> V_23 . V_615 = V_615 ;
F_253 () ;
F_263 ( & V_76 -> V_23 . V_616 ) ;
memcpy ( V_76 -> V_23 . V_163 , V_617 ,
sizeof( V_76 -> V_23 . V_163 ) ) ;
V_76 -> V_23 . V_618 = F_125 ( V_619 ) ;
V_76 -> V_23 . V_620 = F_125 ( V_621 ) ;
V_76 -> V_23 . V_622 = V_75 = F_125 ( V_623 ) ;
V_75 &= V_624 | V_625 ;
V_75 |= ( 4UL << V_626 ) | V_627 |
V_628 | V_629 ;
V_76 -> V_23 . V_591 = V_592 |
( V_593 << V_594 ) ;
if ( F_4 ( V_10 ) )
V_75 |= V_630 ;
V_76 -> V_23 . V_75 = V_75 ;
F_264 () ;
snprintf ( V_372 , sizeof( V_372 ) , L_23 , V_523 -> V_305 ) ;
V_76 -> V_23 . V_394 = F_118 ( V_372 , V_631 ) ;
if ( ! F_117 ( V_76 -> V_23 . V_394 ) )
F_265 ( V_76 ) ;
return 0 ;
}
static void F_266 ( struct V_76 * V_76 )
{
long int V_5 ;
for ( V_5 = 0 ; V_5 < V_397 ; ++ V_5 )
F_109 ( V_76 -> V_23 . V_411 [ V_5 ] ) ;
V_76 -> V_23 . V_412 = 0 ;
}
static void F_267 ( struct V_76 * V_76 )
{
F_268 ( V_76 -> V_23 . V_394 ) ;
F_269 () ;
F_266 ( V_76 ) ;
F_270 ( V_76 ) ;
F_271 ( V_76 ) ;
}
static int F_272 ( struct V_191 * V_192 , struct V_1 * V_6 ,
unsigned int V_632 , int * V_633 )
{
return V_634 ;
}
static int F_273 ( struct V_1 * V_6 , int V_635 ,
T_3 V_636 )
{
return V_634 ;
}
static int F_274 ( struct V_1 * V_6 , int V_635 ,
T_3 * V_636 )
{
return V_634 ;
}
static int F_275 ( void )
{
if ( ! F_4 ( V_637 ) ||
! F_4 ( V_638 ) )
return - V_639 ;
if ( F_4 ( V_640 ) )
return - V_639 ;
return 0 ;
}
void F_271 ( struct V_76 * V_76 )
{
F_109 ( V_76 -> V_23 . V_641 ) ;
}
static struct V_642 * F_276 ( void )
{
return F_100 ( sizeof( struct V_642 ) , V_362 ) ;
}
static int F_277 ( struct V_76 * V_76 , int V_643 , int V_644 )
{
struct V_645 * V_646 ;
struct V_647 * V_648 ;
struct V_642 * V_641 ;
struct V_649 * V_650 ;
int V_5 ;
if ( ! V_651 )
return 1 ;
V_646 = F_278 ( V_643 ) ;
if ( ! V_646 )
return - V_639 ;
F_37 ( & V_76 -> V_52 ) ;
V_641 = V_76 -> V_23 . V_641 ;
if ( V_641 == NULL ) {
V_641 = F_276 () ;
if ( V_641 == NULL ) {
F_39 ( & V_76 -> V_52 ) ;
return - V_370 ;
}
V_76 -> V_23 . V_641 = V_641 ;
}
V_650 = F_279 ( & V_646 -> V_652 ) ;
if ( ! V_650 || ! F_280 ( V_650 ) ) {
F_281 ( L_24 ,
V_643 , V_644 ) ;
F_39 ( & V_76 -> V_52 ) ;
return - V_175 ;
}
for ( V_5 = 0 ; V_5 < V_641 -> V_653 ; V_5 ++ ) {
if ( V_644 == V_641 -> V_654 [ V_5 ] . V_655 ) {
if ( V_641 -> V_654 [ V_5 ] . V_656 ) {
F_39 ( & V_76 -> V_52 ) ;
return - V_51 ;
}
break;
}
}
if ( V_5 == V_657 ) {
F_39 ( & V_76 -> V_52 ) ;
return - V_658 ;
}
V_648 = & V_641 -> V_654 [ V_5 ] ;
V_648 -> V_655 = V_644 ;
V_648 -> V_646 = V_646 ;
F_58 () ;
V_648 -> V_656 = V_646 -> V_652 . V_659 ;
if ( V_5 == V_641 -> V_653 )
V_641 -> V_653 ++ ;
F_282 ( V_76 , V_644 , V_646 -> V_652 . V_659 ) ;
F_39 ( & V_76 -> V_52 ) ;
return 0 ;
}
static int F_283 ( struct V_76 * V_76 , int V_643 , int V_644 )
{
struct V_645 * V_646 ;
struct V_642 * V_641 ;
int V_5 ;
if ( ! V_651 )
return 0 ;
V_646 = F_278 ( V_643 ) ;
if ( ! V_646 )
return - V_639 ;
F_37 ( & V_76 -> V_52 ) ;
if ( V_76 -> V_23 . V_641 == NULL ) {
F_39 ( & V_76 -> V_52 ) ;
return 0 ;
}
V_641 = V_76 -> V_23 . V_641 ;
for ( V_5 = 0 ; V_5 < V_641 -> V_653 ; V_5 ++ ) {
if ( V_644 == V_641 -> V_654 [ V_5 ] . V_655 )
break;
}
if ( V_5 == V_641 -> V_653 ) {
F_39 ( & V_76 -> V_52 ) ;
return - V_660 ;
}
F_284 ( V_76 , V_644 , V_641 -> V_654 [ V_5 ] . V_656 ) ;
V_641 -> V_654 [ V_5 ] . V_656 = 0 ;
F_39 ( & V_76 -> V_52 ) ;
return 0 ;
}
static int F_285 ( struct V_661 * V_662 ,
struct V_663 * V_664 )
{
int V_80 = 0 ;
struct V_665 * V_666 =
F_286 ( V_662 , struct V_665 , V_667 ) ;
V_666 -> V_668 = V_664 ;
V_80 = F_277 ( V_666 -> V_76 , V_664 -> V_669 , V_666 -> V_670 ) ;
if ( V_80 )
F_287 ( L_25 ,
V_664 -> V_669 , V_666 -> V_670 , V_80 ) ;
return V_80 ;
}
static void F_288 ( struct V_661 * V_662 ,
struct V_663 * V_664 )
{
int V_80 ;
struct V_665 * V_666 =
F_286 ( V_662 , struct V_665 , V_667 ) ;
V_666 -> V_668 = NULL ;
V_80 = F_283 ( V_666 -> V_76 , V_664 -> V_669 , V_666 -> V_670 ) ;
if ( V_80 )
F_281 ( L_26 ,
V_664 -> V_669 , V_666 -> V_670 , V_80 ) ;
}
static long F_289 ( struct V_367 * V_671 ,
unsigned int V_672 , unsigned long V_673 )
{
struct V_76 * V_76 V_674 = V_671 -> V_371 ;
void T_5 * V_675 = ( void T_5 * ) V_673 ;
long V_53 ;
switch ( V_672 ) {
case V_676 : {
T_2 V_677 ;
V_53 = - V_392 ;
if ( F_290 ( V_677 , ( T_2 T_5 * ) V_675 ) )
break;
V_53 = F_291 ( V_76 , & V_677 ) ;
if ( V_53 )
break;
V_53 = - V_392 ;
if ( F_292 ( V_677 , ( T_2 T_5 * ) V_675 ) )
break;
V_53 = 0 ;
break;
}
case V_678 : {
struct V_679 V_680 ;
V_53 = - V_392 ;
if ( F_293 ( & V_680 , V_675 , sizeof( V_680 ) ) )
break;
V_53 = F_294 ( V_76 , & V_680 ) ;
break;
}
default:
V_53 = - V_681 ;
}
return V_53 ;
}
static void F_295 ( void )
{
int V_5 ;
unsigned int V_682 ;
for ( V_5 = 0 ; V_683 [ V_5 ] ; ++ V_5 ) {
V_682 = V_683 [ V_5 ] ;
F_296 ( ! F_78 ( V_682 ) ) ;
F_297 ( V_682 / 4 , V_617 ) ;
}
}
static int F_298 ( void )
{
int V_5 , V_242 ;
int V_684 = F_254 () ;
struct V_685 * V_685 ;
for ( V_5 = 0 ; V_5 < V_684 ; V_5 ++ ) {
int V_686 = V_5 * V_481 ;
int V_687 = F_299 ( V_686 ) ;
if ( V_16 [ V_686 ] . V_685 )
continue;
V_685 =
F_300 ( sizeof( struct V_685 ) ,
V_362 , V_687 ) ;
if ( ! V_685 )
return - V_370 ;
memset ( V_685 , 0 ,
sizeof( struct V_685 ) ) ;
for ( V_242 = 0 ; V_242 < V_481 ; V_242 ++ ) {
int V_9 = V_686 + V_242 ;
V_16 [ V_9 ] . V_685 = V_685 ;
}
}
return 0 ;
}
static int F_301 ( void )
{
int V_53 ;
V_53 = F_275 () ;
if ( V_53 < 0 )
return - V_660 ;
V_53 = F_298 () ;
if ( V_53 )
return V_53 ;
V_688 . V_689 = V_690 ;
V_691 = & V_688 ;
F_295 () ;
F_152 () ;
V_53 = F_302 () ;
return V_53 ;
}
static void F_303 ( void )
{
F_259 () ;
V_691 = NULL ;
}
