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
unsigned long V_10 = F_4 ( V_11 ) ;
if ( F_5 ( V_12 ) ) {
V_10 |= F_6 ( V_9 ) ;
F_7 () ;
__asm__ __volatile__ (PPC_MSGSND(%0) : : "r" (msg));
return true ;
}
if ( F_5 ( V_13 ) ) {
F_8 () ;
if ( F_9 ( V_9 ) ==
F_9 ( F_10 () ) ) {
V_10 |= F_11 ( V_9 ) ;
F_7 () ;
__asm__ __volatile__ (PPC_MSGSND(%0) : : "r" (msg));
F_12 () ;
return true ;
}
F_12 () ;
}
#if F_13 ( V_14 ) && F_13 ( V_15 )
if ( V_9 >= 0 && V_9 < V_16 ) {
if ( V_17 [ V_9 ] . V_18 . V_19 ) {
F_14 ( V_9 ) ;
return true ;
}
F_15 ( F_6 ( V_9 ) , V_20 ) ;
return true ;
}
#endif
return false ;
}
static void F_16 ( struct V_1 * V_6 )
{
int V_9 ;
struct V_21 * V_22 ;
V_22 = F_17 ( V_6 ) ;
if ( F_18 ( V_22 ) ) {
F_19 ( V_22 ) ;
++ V_6 -> V_23 . V_24 ;
}
V_9 = F_2 ( V_6 -> V_25 . V_26 ) ;
if ( V_9 >= 0 && F_3 ( V_9 ) )
return;
V_9 = V_6 -> V_9 ;
if ( V_9 >= 0 && V_9 < V_16 && F_20 ( V_9 ) )
F_21 ( V_9 ) ;
}
static void F_22 ( struct V_2 * V_3 )
{
unsigned long V_27 ;
F_23 ( & V_3 -> V_28 , V_27 ) ;
V_3 -> V_29 = F_24 () ;
F_25 ( & V_3 -> V_28 , V_27 ) ;
}
static void F_26 ( struct V_2 * V_3 )
{
unsigned long V_27 ;
F_23 ( & V_3 -> V_28 , V_27 ) ;
if ( V_3 -> V_29 != V_30 ) {
V_3 -> V_31 += F_24 () - V_3 -> V_29 ;
V_3 -> V_29 = V_30 ;
}
F_25 ( & V_3 -> V_28 , V_27 ) ;
}
static void F_27 ( struct V_1 * V_6 , int V_9 )
{
struct V_2 * V_3 = V_6 -> V_25 . V_32 ;
unsigned long V_27 ;
if ( V_3 -> V_33 == V_6 && V_3 -> V_34 >= V_35 )
F_26 ( V_3 ) ;
F_23 ( & V_6 -> V_25 . V_36 , V_27 ) ;
if ( V_6 -> V_25 . V_37 == V_38 &&
V_6 -> V_25 . V_39 != V_30 ) {
V_6 -> V_25 . V_40 += F_24 () - V_6 -> V_25 . V_39 ;
V_6 -> V_25 . V_39 = V_30 ;
}
F_25 ( & V_6 -> V_25 . V_36 , V_27 ) ;
}
static void F_28 ( struct V_1 * V_6 )
{
struct V_2 * V_3 = V_6 -> V_25 . V_32 ;
unsigned long V_27 ;
if ( V_3 -> V_33 == V_6 && V_3 -> V_34 >= V_35 )
F_22 ( V_3 ) ;
F_23 ( & V_6 -> V_25 . V_36 , V_27 ) ;
if ( V_6 -> V_25 . V_37 == V_38 )
V_6 -> V_25 . V_39 = F_24 () ;
F_25 ( & V_6 -> V_25 . V_36 , V_27 ) ;
}
static void F_29 ( struct V_1 * V_6 , T_1 V_41 )
{
if ( ( V_41 & V_42 ) == V_42 )
V_41 &= ~ V_42 ;
V_6 -> V_25 . V_43 . V_41 = V_41 ;
F_30 ( V_6 ) ;
}
static void F_31 ( struct V_1 * V_6 , T_2 V_44 )
{
V_6 -> V_25 . V_44 = V_44 ;
}
static int F_32 ( struct V_1 * V_6 , T_2 V_45 )
{
unsigned long V_46 = 0 , V_47 = 0 ;
struct V_2 * V_3 = V_6 -> V_25 . V_32 ;
if ( F_5 ( V_12 ) )
V_46 = V_48 ;
else if ( F_5 ( V_13 ) )
V_46 = V_49 ;
else if ( F_5 ( V_50 ) )
V_46 = V_51 ;
else
V_46 = V_52 ;
V_47 = V_46 ;
if ( V_45 ) {
switch ( V_45 ) {
case V_53 :
V_47 = V_52 ;
break;
case V_54 :
case V_55 :
V_47 = V_51 ;
break;
case V_56 :
V_47 = V_49 ;
break;
case V_57 :
V_47 = V_48 ;
break;
default:
return - V_58 ;
}
}
if ( V_47 > V_46 )
return - V_58 ;
F_33 ( & V_3 -> V_59 ) ;
V_3 -> V_45 = V_45 ;
V_3 -> V_60 = V_46 - V_47 ;
F_34 ( & V_3 -> V_59 ) ;
return 0 ;
}
static void F_35 ( struct V_1 * V_6 )
{
int V_61 ;
F_36 ( L_1 , V_6 , V_6 -> V_62 ) ;
F_36 ( L_2 ,
V_6 -> V_25 . V_63 , V_6 -> V_25 . V_43 . V_41 , V_6 -> V_25 . V_64 ) ;
for ( V_61 = 0 ; V_61 < 16 ; ++ V_61 )
F_36 ( L_3 ,
V_61 , F_37 ( V_6 , V_61 ) ,
V_61 + 16 , F_37 ( V_6 , V_61 + 16 ) ) ;
F_36 ( L_4 ,
V_6 -> V_25 . V_65 , V_6 -> V_25 . V_66 ) ;
F_36 ( L_5 ,
V_6 -> V_25 . V_43 . V_67 , V_6 -> V_25 . V_43 . V_68 ) ;
F_36 ( L_6 ,
V_6 -> V_25 . V_43 . V_69 , V_6 -> V_25 . V_43 . V_70 ) ;
F_36 ( L_7 ,
V_6 -> V_25 . V_43 . V_71 , V_6 -> V_25 . V_43 . V_72 ) ;
F_36 ( L_8 ,
V_6 -> V_25 . V_73 , V_6 -> V_25 . V_74 , V_6 -> V_25 . V_43 . V_75 ) ;
F_36 ( L_9 , V_6 -> V_25 . V_43 . V_76 ) ;
F_36 ( L_10 ,
V_6 -> V_25 . V_77 , V_6 -> V_25 . V_78 ) ;
F_36 ( L_11 , V_6 -> V_25 . V_79 ) ;
for ( V_61 = 0 ; V_61 < V_6 -> V_25 . V_79 ; ++ V_61 )
F_36 ( L_12 ,
V_6 -> V_25 . V_80 [ V_61 ] . V_81 , V_6 -> V_25 . V_80 [ V_61 ] . V_82 ) ;
F_36 ( L_13 ,
V_6 -> V_25 . V_32 -> V_83 , V_6 -> V_84 -> V_25 . V_85 ,
V_6 -> V_25 . V_86 ) ;
}
static struct V_1 * F_38 ( struct V_84 * V_84 , int V_87 )
{
struct V_1 * V_88 ;
F_39 ( & V_84 -> V_59 ) ;
V_88 = F_40 ( V_84 , V_87 ) ;
F_41 ( & V_84 -> V_59 ) ;
return V_88 ;
}
static void F_42 ( struct V_1 * V_6 , struct V_89 * V_90 )
{
V_90 -> V_91 |= V_92 ;
V_90 -> V_93 = F_43 ( 1 ) ;
}
static int F_44 ( struct V_1 * V_6 , struct V_94 * V_95 ,
unsigned long V_96 , unsigned long V_97 )
{
if ( V_96 & ( V_98 - 1 ) )
return - V_58 ;
F_33 ( & V_6 -> V_25 . V_99 ) ;
if ( V_95 -> V_100 != V_96 || V_95 -> V_97 != V_97 ) {
V_95 -> V_100 = V_96 ;
V_95 -> V_97 = V_96 ? V_97 : 0 ;
V_95 -> V_101 = 1 ;
}
F_34 ( & V_6 -> V_25 . V_99 ) ;
return 0 ;
}
static int F_45 ( struct V_94 * V_102 )
{
if ( V_102 -> V_101 )
return V_102 -> V_100 != 0 ;
return V_102 -> V_103 != NULL ;
}
static unsigned long F_46 ( struct V_1 * V_6 ,
unsigned long V_27 ,
unsigned long V_104 , unsigned long V_90 )
{
struct V_84 * V_84 = V_6 -> V_84 ;
unsigned long V_97 , V_105 ;
void * V_106 ;
struct V_1 * V_107 ;
int V_108 ;
int V_109 ;
struct V_94 * V_102 ;
V_107 = F_38 ( V_84 , V_104 ) ;
if ( ! V_107 )
return V_110 ;
V_109 = ( V_27 >> V_111 ) & V_112 ;
if ( V_109 == V_113 || V_109 == V_114 ||
V_109 == V_115 ) {
if ( ( V_90 & ( V_98 - 1 ) ) || ! V_90 )
return V_110 ;
V_106 = F_47 ( V_84 , V_90 , & V_105 ) ;
if ( V_106 == NULL )
return V_110 ;
if ( V_109 == V_113 )
V_97 = F_48 ( ( (struct V_116 * ) V_106 ) -> V_117 . V_118 ) ;
else
V_97 = F_49 ( ( (struct V_116 * ) V_106 ) -> V_117 . V_119 ) ;
F_50 ( V_84 , V_106 , V_90 , false ) ;
if ( V_97 > V_105 || V_97 < sizeof( struct V_116 ) )
return V_110 ;
} else {
V_90 = 0 ;
V_97 = 0 ;
}
V_108 = V_110 ;
V_102 = NULL ;
F_33 ( & V_107 -> V_25 . V_99 ) ;
switch ( V_109 ) {
case V_113 :
if ( V_97 < sizeof( struct V_89 ) )
break;
V_102 = & V_107 -> V_25 . V_90 ;
V_108 = 0 ;
break;
case V_114 :
if ( V_97 < sizeof( struct V_120 ) )
break;
V_97 -= V_97 % sizeof( struct V_120 ) ;
V_108 = V_121 ;
if ( ! F_45 ( & V_107 -> V_25 . V_90 ) )
break;
V_102 = & V_107 -> V_25 . V_122 ;
V_108 = 0 ;
break;
case V_115 :
V_108 = V_121 ;
if ( ! F_45 ( & V_107 -> V_25 . V_90 ) )
break;
V_102 = & V_107 -> V_25 . V_123 ;
V_108 = 0 ;
break;
case V_124 :
V_108 = V_121 ;
if ( F_45 ( & V_107 -> V_25 . V_122 ) ||
F_45 ( & V_107 -> V_25 . V_123 ) )
break;
V_102 = & V_107 -> V_25 . V_90 ;
V_108 = 0 ;
break;
case V_125 :
V_102 = & V_107 -> V_25 . V_122 ;
V_108 = 0 ;
break;
case V_126 :
V_102 = & V_107 -> V_25 . V_123 ;
V_108 = 0 ;
break;
}
if ( V_102 ) {
V_102 -> V_100 = V_90 ;
V_102 -> V_97 = V_97 ;
V_102 -> V_101 = 1 ;
}
F_34 ( & V_107 -> V_25 . V_99 ) ;
return V_108 ;
}
static void F_51 ( struct V_1 * V_6 , struct V_94 * V_102 )
{
struct V_84 * V_84 = V_6 -> V_84 ;
void * V_106 ;
unsigned long V_105 ;
unsigned long V_127 ;
for (; ; ) {
V_127 = V_102 -> V_100 ;
F_34 ( & V_6 -> V_25 . V_99 ) ;
V_106 = NULL ;
V_105 = 0 ;
if ( V_127 )
V_106 = F_47 ( V_84 , V_127 , & V_105 ) ;
F_33 ( & V_6 -> V_25 . V_99 ) ;
if ( V_127 == V_102 -> V_100 )
break;
if ( V_106 )
F_50 ( V_84 , V_106 , V_127 , false ) ;
}
V_102 -> V_101 = 0 ;
if ( V_106 && V_105 < V_102 -> V_97 ) {
F_50 ( V_84 , V_106 , V_127 , false ) ;
V_106 = NULL ;
}
if ( V_102 -> V_103 )
F_50 ( V_84 , V_102 -> V_103 , V_102 -> V_127 ,
V_102 -> V_128 ) ;
V_102 -> V_127 = V_127 ;
V_102 -> V_103 = V_106 ;
V_102 -> V_128 = false ;
if ( V_106 )
V_102 -> V_129 = V_106 + V_102 -> V_97 ;
}
static void F_52 ( struct V_1 * V_6 )
{
if ( ! ( V_6 -> V_25 . V_90 . V_101 ||
V_6 -> V_25 . V_123 . V_101 ||
V_6 -> V_25 . V_122 . V_101 ) )
return;
F_33 ( & V_6 -> V_25 . V_99 ) ;
if ( V_6 -> V_25 . V_90 . V_101 ) {
F_51 ( V_6 , & V_6 -> V_25 . V_90 ) ;
if ( V_6 -> V_25 . V_90 . V_103 )
F_42 ( V_6 , V_6 -> V_25 . V_90 . V_103 ) ;
}
if ( V_6 -> V_25 . V_122 . V_101 ) {
F_51 ( V_6 , & V_6 -> V_25 . V_122 ) ;
V_6 -> V_25 . V_130 = V_6 -> V_25 . V_122 . V_103 ;
V_6 -> V_25 . V_131 = 0 ;
}
if ( V_6 -> V_25 . V_123 . V_101 )
F_51 ( V_6 , & V_6 -> V_25 . V_123 ) ;
F_34 ( & V_6 -> V_25 . V_99 ) ;
}
static T_1 F_53 ( struct V_2 * V_3 , T_1 V_132 )
{
T_1 V_133 ;
unsigned long V_27 ;
F_23 ( & V_3 -> V_28 , V_27 ) ;
V_133 = V_3 -> V_31 ;
if ( V_3 -> V_34 != V_134 &&
V_3 -> V_29 != V_30 )
V_133 += V_132 - V_3 -> V_29 ;
F_25 ( & V_3 -> V_28 , V_27 ) ;
return V_133 ;
}
static void F_54 ( struct V_1 * V_6 ,
struct V_2 * V_3 )
{
struct V_120 * V_135 ;
struct V_89 * V_90 ;
unsigned long V_136 ;
unsigned long V_137 ;
T_1 V_132 ;
V_135 = V_6 -> V_25 . V_130 ;
V_90 = V_6 -> V_25 . V_90 . V_103 ;
V_132 = F_24 () ;
V_137 = F_53 ( V_3 , V_132 ) ;
V_136 = V_137 - V_6 -> V_25 . V_138 ;
V_6 -> V_25 . V_138 = V_137 ;
F_55 ( & V_6 -> V_25 . V_36 ) ;
V_136 += V_6 -> V_25 . V_40 ;
V_6 -> V_25 . V_40 = 0 ;
F_56 ( & V_6 -> V_25 . V_36 ) ;
if ( ! V_135 || ! V_90 )
return;
memset ( V_135 , 0 , sizeof( struct V_120 ) ) ;
V_135 -> V_139 = 7 ;
V_135 -> V_140 = F_57 ( V_3 -> V_141 + V_6 -> V_25 . V_142 ) ;
V_135 -> V_143 = F_58 ( V_132 + V_3 -> V_144 ) ;
V_135 -> V_145 = F_43 ( V_136 ) ;
V_135 -> V_67 = F_58 ( F_59 ( V_6 ) ) ;
V_135 -> V_68 = F_58 ( V_6 -> V_25 . V_43 . V_41 ) ;
++ V_135 ;
if ( V_135 == V_6 -> V_25 . V_122 . V_129 )
V_135 = V_6 -> V_25 . V_122 . V_103 ;
V_6 -> V_25 . V_130 = V_135 ;
F_60 () ;
V_90 -> V_146 = F_58 ( ++ V_6 -> V_25 . V_131 ) ;
V_6 -> V_25 . V_122 . V_128 = true ;
}
static bool F_61 ( struct V_1 * V_6 )
{
if ( V_6 -> V_25 . V_32 -> V_45 >= V_56 )
return true ;
if ( ( ! V_6 -> V_25 . V_32 -> V_45 ) &&
F_5 ( V_13 ) )
return true ;
return false ;
}
static int F_62 ( struct V_1 * V_6 , unsigned long V_147 ,
unsigned long V_148 , unsigned long V_149 ,
unsigned long V_150 )
{
switch ( V_148 ) {
case V_151 :
if ( ! F_61 ( V_6 ) )
return V_152 ;
if ( V_150 )
return V_153 ;
if ( V_147 )
return V_154 ;
if ( ( V_149 & V_155 ) == V_156 )
return V_157 ;
V_6 -> V_25 . V_158 = V_149 ;
return V_159 ;
case V_160 :
if ( ! F_61 ( V_6 ) )
return V_152 ;
if ( V_147 )
return V_154 ;
if ( V_150 & V_161 )
return V_153 ;
V_6 -> V_25 . V_162 = V_149 ;
V_6 -> V_25 . V_163 = V_150 ;
return V_159 ;
default:
return V_164 ;
}
}
static int F_63 ( struct V_1 * V_165 )
{
struct V_2 * V_32 = V_165 -> V_25 . V_32 ;
F_33 ( & V_32 -> V_59 ) ;
if ( V_165 -> V_25 . V_37 == V_166 &&
V_32 -> V_34 != V_134 &&
V_32 -> V_33 )
V_165 = V_32 -> V_33 ;
F_34 ( & V_32 -> V_59 ) ;
return F_64 ( V_165 ) ;
}
static int F_65 ( struct V_1 * V_6 )
{
int V_93 = 0 ;
struct V_89 * V_89 ;
F_33 ( & V_6 -> V_25 . V_99 ) ;
V_89 = (struct V_89 * ) V_6 -> V_25 . V_90 . V_103 ;
if ( V_89 )
V_93 = F_49 ( V_89 -> V_93 ) ;
F_34 ( & V_6 -> V_25 . V_99 ) ;
return V_93 ;
}
int F_66 ( struct V_1 * V_6 )
{
unsigned long V_167 = F_37 ( V_6 , 3 ) ;
unsigned long V_165 , V_88 = V_159 ;
int V_93 ;
struct V_1 * V_107 ;
int V_168 , V_169 ;
if ( V_167 <= V_170 &&
! F_67 ( V_167 / 4 , V_6 -> V_84 -> V_25 . V_171 ) )
return V_172 ;
switch ( V_167 ) {
case V_173 :
break;
case V_174 :
V_165 = F_37 ( V_6 , 4 ) ;
V_107 = F_38 ( V_6 -> V_84 , V_165 ) ;
if ( ! V_107 ) {
V_88 = V_110 ;
break;
}
V_107 -> V_25 . V_175 = 1 ;
F_7 () ;
if ( V_107 -> V_25 . V_176 )
F_16 ( V_107 ) ;
break;
case V_177 :
V_165 = F_37 ( V_6 , 4 ) ;
if ( V_165 == - 1 )
break;
V_107 = F_38 ( V_6 -> V_84 , V_165 ) ;
if ( ! V_107 ) {
V_88 = V_110 ;
break;
}
V_93 = F_37 ( V_6 , 5 ) ;
if ( F_65 ( V_107 ) != V_93 )
break;
F_63 ( V_107 ) ;
break;
case V_178 :
V_88 = F_46 ( V_6 , F_37 ( V_6 , 4 ) ,
F_37 ( V_6 , 5 ) ,
F_37 ( V_6 , 6 ) ) ;
break;
case V_179 :
if ( F_68 ( & V_6 -> V_84 -> V_25 . V_180 ) )
return V_172 ;
V_168 = F_69 ( & V_6 -> V_84 -> V_181 ) ;
V_169 = F_70 ( V_6 ) ;
F_71 ( & V_6 -> V_84 -> V_181 , V_168 ) ;
if ( V_169 == - V_182 )
return V_172 ;
else if ( V_169 == 0 )
break;
return V_169 ;
case V_183 :
V_88 = F_72 ( V_6 ) ;
if ( V_88 == V_164 )
return V_172 ;
break;
case V_184 :
V_88 = F_73 ( V_6 ) ;
if ( V_88 == V_164 )
return V_172 ;
break;
case V_185 :
V_88 = F_62 ( V_6 , F_37 ( V_6 , 4 ) ,
F_37 ( V_6 , 5 ) ,
F_37 ( V_6 , 6 ) ,
F_37 ( V_6 , 7 ) ) ;
if ( V_88 == V_164 )
return V_172 ;
break;
case V_186 :
case V_187 :
case V_188 :
case V_189 :
case V_190 :
case V_191 :
if ( F_74 ( V_6 ) ) {
if ( F_75 () ) {
V_88 = V_192 ;
return V_193 ;
}
V_88 = F_76 ( V_6 , V_167 ) ;
break;
}
return V_172 ;
case V_194 :
V_88 = F_77 ( V_6 , F_37 ( V_6 , 4 ) ,
F_37 ( V_6 , 5 ) ,
F_37 ( V_6 , 6 ) ) ;
if ( V_88 == V_164 )
return V_172 ;
break;
case V_195 :
V_88 = F_78 ( V_6 , F_37 ( V_6 , 4 ) ,
F_37 ( V_6 , 5 ) ,
F_37 ( V_6 , 6 ) ,
F_37 ( V_6 , 7 ) ) ;
if ( V_88 == V_164 )
return V_172 ;
break;
case V_196 :
V_88 = F_79 ( V_6 , F_37 ( V_6 , 4 ) ,
F_37 ( V_6 , 5 ) ,
F_37 ( V_6 , 6 ) ,
F_37 ( V_6 , 7 ) ) ;
if ( V_88 == V_164 )
return V_172 ;
break;
default:
return V_172 ;
}
F_80 ( V_6 , 3 , V_88 ) ;
V_6 -> V_25 . V_197 = 0 ;
return V_193 ;
}
static int F_81 ( unsigned long V_198 )
{
switch ( V_198 ) {
case V_173 :
case V_174 :
case V_177 :
case V_178 :
case V_185 :
case V_183 :
case V_184 :
#ifdef F_82
case V_186 :
case V_187 :
case V_188 :
case V_189 :
case V_190 :
case V_191 :
#endif
return 1 ;
}
return F_83 ( V_198 ) ;
}
static int F_84 ( struct V_199 * V_200 ,
struct V_1 * V_6 )
{
T_2 V_86 ;
if ( F_85 ( V_6 , V_201 , & V_86 ) !=
V_202 ) {
return V_193 ;
}
if ( V_86 == V_203 ) {
V_200 -> V_204 = V_205 ;
V_200 -> V_206 . V_25 . V_207 = F_59 ( V_6 ) ;
return V_172 ;
} else {
F_86 ( V_6 , V_208 ) ;
return V_193 ;
}
}
static int F_87 ( struct V_199 * V_200 , struct V_1 * V_6 ,
struct V_209 * V_210 )
{
int V_61 = V_172 ;
V_6 -> V_23 . V_211 ++ ;
if ( V_6 -> V_25 . V_43 . V_41 & V_212 ) {
F_88 ( V_213 L_14 ) ;
F_88 ( V_213 L_15 ,
V_6 -> V_25 . V_64 , F_59 ( V_6 ) ,
V_6 -> V_25 . V_43 . V_41 ) ;
F_35 ( V_6 ) ;
V_200 -> V_204 = V_214 ;
V_200 -> V_215 . V_216 = V_6 -> V_25 . V_64 ;
return V_172 ;
}
V_200 -> V_204 = V_217 ;
V_200 -> V_218 = 1 ;
switch ( V_6 -> V_25 . V_64 ) {
case V_219 :
V_6 -> V_23 . V_220 ++ ;
V_61 = V_193 ;
break;
case V_221 :
case V_222 :
case V_223 :
V_6 -> V_23 . V_224 ++ ;
V_61 = V_193 ;
break;
case V_225 :
case V_226 :
V_61 = V_193 ;
break;
case V_227 :
F_89 ( V_6 ,
V_227 ) ;
V_61 = V_193 ;
break;
case V_228 :
{
T_3 V_27 ;
V_27 = V_6 -> V_25 . V_43 . V_41 & 0x1f0000ull ;
F_86 ( V_6 , V_27 ) ;
V_61 = V_193 ;
break;
}
case V_229 :
{
int V_5 ;
V_200 -> V_230 . V_231 = F_37 ( V_6 , 3 ) ;
for ( V_5 = 0 ; V_5 < 9 ; ++ V_5 )
V_200 -> V_230 . args [ V_5 ] = F_37 ( V_6 , 4 + V_5 ) ;
V_200 -> V_204 = V_232 ;
V_6 -> V_25 . V_197 = 1 ;
V_61 = V_172 ;
break;
}
case V_233 :
V_61 = V_234 ;
break;
case V_235 :
V_6 -> V_25 . V_77 = F_59 ( V_6 ) ;
V_6 -> V_25 . V_78 = 0 ;
V_61 = V_234 ;
break;
case V_236 :
if ( V_6 -> V_25 . V_237 != V_238 )
V_6 -> V_25 . V_86 = F_90 ( V_6 ) ?
F_91 ( V_6 -> V_25 . V_237 ) :
V_6 -> V_25 . V_237 ;
if ( V_6 -> V_239 & V_240 ) {
V_61 = F_84 ( V_200 , V_6 ) ;
} else {
F_86 ( V_6 , V_208 ) ;
V_61 = V_193 ;
}
break;
case V_241 :
F_86 ( V_6 , V_208 ) ;
V_61 = V_193 ;
break;
case V_242 :
V_61 = V_243 ;
break;
default:
F_35 ( V_6 ) ;
F_88 ( V_213 L_15 ,
V_6 -> V_25 . V_64 , F_59 ( V_6 ) ,
V_6 -> V_25 . V_43 . V_41 ) ;
V_200 -> V_215 . V_216 = V_6 -> V_25 . V_64 ;
V_61 = V_172 ;
break;
}
return V_61 ;
}
static int F_92 ( struct V_1 * V_6 ,
struct V_244 * V_245 )
{
int V_5 ;
memset ( V_245 , 0 , sizeof( struct V_244 ) ) ;
V_245 -> V_44 = V_6 -> V_25 . V_44 ;
for ( V_5 = 0 ; V_5 < V_6 -> V_25 . V_79 ; V_5 ++ ) {
V_245 -> V_246 . V_247 . V_248 . V_80 [ V_5 ] . V_249 = V_6 -> V_25 . V_80 [ V_5 ] . V_81 ;
V_245 -> V_246 . V_247 . V_248 . V_80 [ V_5 ] . V_250 = V_6 -> V_25 . V_80 [ V_5 ] . V_82 ;
}
return 0 ;
}
static int F_93 ( struct V_1 * V_6 ,
struct V_244 * V_245 )
{
int V_5 , V_251 ;
if ( V_245 -> V_44 != V_6 -> V_25 . V_44 )
return - V_58 ;
V_251 = 0 ;
for ( V_5 = 0 ; V_5 < V_6 -> V_25 . V_252 ; V_5 ++ ) {
if ( V_245 -> V_246 . V_247 . V_248 . V_80 [ V_5 ] . V_249 & V_253 ) {
V_6 -> V_25 . V_80 [ V_251 ] . V_81 = V_245 -> V_246 . V_247 . V_248 . V_80 [ V_5 ] . V_249 ;
V_6 -> V_25 . V_80 [ V_251 ] . V_82 = V_245 -> V_246 . V_247 . V_248 . V_80 [ V_5 ] . V_250 ;
++ V_251 ;
}
}
V_6 -> V_25 . V_79 = V_251 ;
return 0 ;
}
static void F_94 ( struct V_1 * V_6 , T_1 V_254 ,
bool V_255 )
{
struct V_84 * V_84 = V_6 -> V_84 ;
struct V_2 * V_3 = V_6 -> V_25 . V_32 ;
T_1 V_256 ;
F_39 ( & V_84 -> V_59 ) ;
F_33 ( & V_3 -> V_59 ) ;
if ( ( V_254 & V_257 ) != ( V_3 -> V_83 & V_257 ) ) {
struct V_1 * V_6 ;
int V_5 ;
F_95 (i, vcpu, kvm) {
if ( V_6 -> V_25 . V_32 != V_3 )
continue;
if ( V_254 & V_257 )
V_6 -> V_25 . V_258 |= V_259 ;
else
V_6 -> V_25 . V_258 &= ~ V_259 ;
}
}
V_256 = V_260 | V_257 | V_261 ;
if ( F_5 ( V_13 ) )
V_256 |= V_262 ;
if ( V_255 )
V_256 &= 0xFFFFFFFF ;
V_3 -> V_83 = ( V_3 -> V_83 & ~ V_256 ) | ( V_254 & V_256 ) ;
F_34 ( & V_3 -> V_59 ) ;
F_41 ( & V_84 -> V_59 ) ;
}
static int F_96 ( struct V_1 * V_6 , T_1 V_87 ,
union V_263 * V_264 )
{
int V_61 = 0 ;
long int V_5 ;
switch ( V_87 ) {
case V_265 :
* V_264 = F_97 ( V_87 , V_203 ) ;
break;
case V_266 :
* V_264 = F_97 ( V_87 , 0 ) ;
break;
case V_267 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_268 ) ;
break;
case V_269 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_270 ) ;
break;
case V_271 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_272 ) ;
break;
case V_273 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_274 ) ;
break;
case V_275 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_276 ) ;
break;
case V_277 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_278 ) ;
break;
case V_279 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_280 ) ;
break;
case V_281 ... V_282 :
V_5 = V_87 - V_281 ;
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_283 [ V_5 ] ) ;
break;
case V_284 ... V_285 :
V_5 = V_87 - V_284 ;
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_286 [ V_5 ] ) ;
break;
case V_287 ... V_288 :
V_5 = V_87 - V_287 ;
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_289 [ V_5 ] ) ;
break;
case V_290 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_291 ) ;
break;
case V_292 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_293 ) ;
break;
case V_294 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_295 ) ;
break;
case V_296 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_297 ) ;
break;
case V_298 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_299 ) ;
break;
case V_300 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_32 -> V_301 ) ;
break;
case V_302 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_32 -> V_303 ) ;
break;
case V_304 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_162 ) ;
break;
case V_305 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_163 ) ;
break;
case V_306 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_158 ) ;
break;
case V_307 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_308 ) ;
break;
case V_309 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_310 ) ;
break;
case V_311 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_312 ) ;
break;
case V_313 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_314 ) ;
break;
case V_315 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_316 ) ;
break;
case V_317 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_318 ) ;
break;
case V_319 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_320 ) ;
break;
case V_321 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_322 ) ;
break;
case V_323 :
F_33 ( & V_6 -> V_25 . V_99 ) ;
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_90 . V_100 ) ;
F_34 ( & V_6 -> V_25 . V_99 ) ;
break;
case V_324 :
F_33 ( & V_6 -> V_25 . V_99 ) ;
V_264 -> V_325 . V_96 = V_6 -> V_25 . V_123 . V_100 ;
V_264 -> V_325 . V_117 = V_6 -> V_25 . V_123 . V_97 ;
F_34 ( & V_6 -> V_25 . V_99 ) ;
break;
case V_326 :
F_33 ( & V_6 -> V_25 . V_99 ) ;
V_264 -> V_325 . V_96 = V_6 -> V_25 . V_122 . V_100 ;
V_264 -> V_325 . V_117 = V_6 -> V_25 . V_122 . V_97 ;
F_34 ( & V_6 -> V_25 . V_99 ) ;
break;
case V_327 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_32 -> V_144 ) ;
break;
case V_328 :
case V_329 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_32 -> V_83 ) ;
break;
case V_330 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_331 ) ;
break;
#ifdef F_98
case V_332 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_333 ) ;
break;
case V_334 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_335 ) ;
break;
case V_336 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_337 ) ;
break;
case V_338 ... V_339 :
V_5 = V_87 - V_338 ;
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_340 [ V_5 ] ) ;
break;
case V_341 ... V_342 :
{
int V_251 ;
V_5 = V_87 - V_341 ;
if ( V_5 < 32 )
for ( V_251 = 0 ; V_251 < V_343 ; V_251 ++ )
V_264 -> V_344 [ V_251 ] = V_6 -> V_25 . V_345 . V_346 [ V_5 ] [ V_251 ] ;
else {
if ( F_5 ( V_347 ) )
V_264 -> V_348 = V_6 -> V_25 . V_349 . V_350 [ V_5 - 32 ] ;
else
V_61 = - V_351 ;
}
break;
}
case V_352 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_353 ) ;
break;
case V_354 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_355 ) ;
break;
case V_356 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_357 ) ;
break;
case V_358 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_359 ) ;
break;
case V_360 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_345 . V_361 ) ;
break;
case V_362 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_363 ) ;
break;
case V_364 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_365 ) ;
break;
case V_366 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_367 ) ;
break;
case V_368 :
if ( F_5 ( V_347 ) )
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_349 . V_369 . V_246 [ 3 ] ) ;
else
V_61 = - V_351 ;
break;
case V_370 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_371 ) ;
break;
case V_372 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_373 ) ;
break;
#endif
case V_374 :
* V_264 = F_97 ( V_87 , V_6 -> V_25 . V_32 -> V_45 ) ;
break;
default:
V_61 = - V_58 ;
break;
}
return V_61 ;
}
static int F_99 ( struct V_1 * V_6 , T_1 V_87 ,
union V_263 * V_264 )
{
int V_61 = 0 ;
long int V_5 ;
unsigned long V_96 , V_97 ;
switch ( V_87 ) {
case V_266 :
if ( F_100 ( V_87 , * V_264 ) )
V_61 = - V_58 ;
break;
case V_267 :
V_6 -> V_25 . V_268 = F_100 ( V_87 , * V_264 ) ;
break;
case V_269 :
V_6 -> V_25 . V_270 = F_100 ( V_87 , * V_264 ) & ~ V_161 ;
break;
case V_271 :
V_6 -> V_25 . V_272 = F_100 ( V_87 , * V_264 ) ;
break;
case V_273 :
V_6 -> V_25 . V_274 = F_100 ( V_87 , * V_264 ) ;
break;
case V_275 :
V_6 -> V_25 . V_276 = F_100 ( V_87 , * V_264 ) ;
break;
case V_277 :
V_6 -> V_25 . V_278 = F_100 ( V_87 , * V_264 ) ;
break;
case V_279 :
V_6 -> V_25 . V_280 = F_100 ( V_87 , * V_264 ) ;
break;
case V_281 ... V_282 :
V_5 = V_87 - V_281 ;
V_6 -> V_25 . V_283 [ V_5 ] = F_100 ( V_87 , * V_264 ) ;
break;
case V_284 ... V_285 :
V_5 = V_87 - V_284 ;
V_6 -> V_25 . V_286 [ V_5 ] = F_100 ( V_87 , * V_264 ) ;
break;
case V_287 ... V_288 :
V_5 = V_87 - V_287 ;
V_6 -> V_25 . V_289 [ V_5 ] = F_100 ( V_87 , * V_264 ) ;
break;
case V_290 :
V_6 -> V_25 . V_291 = F_100 ( V_87 , * V_264 ) ;
break;
case V_292 :
V_6 -> V_25 . V_293 = F_100 ( V_87 , * V_264 ) ;
break;
case V_294 :
V_6 -> V_25 . V_295 = F_100 ( V_87 , * V_264 ) ;
break;
case V_296 :
V_6 -> V_25 . V_297 = F_100 ( V_87 , * V_264 ) ;
break;
case V_298 :
V_6 -> V_25 . V_299 = F_100 ( V_87 , * V_264 ) ;
break;
case V_300 :
V_6 -> V_25 . V_32 -> V_301 = F_100 ( V_87 , * V_264 ) ;
break;
case V_302 :
V_6 -> V_25 . V_32 -> V_303 = F_100 ( V_87 , * V_264 ) ;
break;
case V_304 :
V_6 -> V_25 . V_162 = F_100 ( V_87 , * V_264 ) ;
break;
case V_305 :
V_6 -> V_25 . V_163 = F_100 ( V_87 , * V_264 ) & ~ V_375 ;
break;
case V_306 :
V_6 -> V_25 . V_158 = F_100 ( V_87 , * V_264 ) ;
if ( ( V_6 -> V_25 . V_158 & V_155 ) == V_156 )
V_6 -> V_25 . V_158 &= ~ V_155 ;
break;
case V_307 :
V_6 -> V_25 . V_308 = F_100 ( V_87 , * V_264 ) ;
break;
case V_309 :
V_6 -> V_25 . V_310 = F_100 ( V_87 , * V_264 ) ;
break;
case V_311 :
V_6 -> V_25 . V_312 = F_100 ( V_87 , * V_264 ) ;
break;
case V_313 :
V_6 -> V_25 . V_314 = F_100 ( V_87 , * V_264 ) ;
break;
case V_315 :
V_6 -> V_25 . V_316 = F_100 ( V_87 , * V_264 ) ;
break;
case V_317 :
V_6 -> V_25 . V_318 = F_100 ( V_87 , * V_264 ) ;
break;
case V_319 :
V_6 -> V_25 . V_320 = F_100 ( V_87 , * V_264 ) ;
break;
case V_321 :
V_6 -> V_25 . V_322 = F_100 ( V_87 , * V_264 ) & V_376 ;
break;
case V_323 :
V_96 = F_100 ( V_87 , * V_264 ) ;
V_61 = - V_58 ;
if ( ! V_96 && ( V_6 -> V_25 . V_123 . V_100 ||
V_6 -> V_25 . V_122 . V_100 ) )
break;
V_61 = F_44 ( V_6 , & V_6 -> V_25 . V_90 , V_96 , sizeof( struct V_89 ) ) ;
break;
case V_324 :
V_96 = V_264 -> V_325 . V_96 ;
V_97 = V_264 -> V_325 . V_117 ;
V_61 = - V_58 ;
if ( V_96 && ! V_6 -> V_25 . V_90 . V_100 )
break;
V_61 = F_44 ( V_6 , & V_6 -> V_25 . V_123 , V_96 , V_97 ) ;
break;
case V_326 :
V_96 = V_264 -> V_325 . V_96 ;
V_97 = V_264 -> V_325 . V_117 ;
V_61 = - V_58 ;
if ( V_96 && ( V_97 < sizeof( struct V_120 ) ||
! V_6 -> V_25 . V_90 . V_100 ) )
break;
V_97 -= V_97 % sizeof( struct V_120 ) ;
V_61 = F_44 ( V_6 , & V_6 -> V_25 . V_122 , V_96 , V_97 ) ;
break;
case V_327 :
if ( F_5 ( V_377 ) )
break;
V_6 -> V_25 . V_32 -> V_144 =
F_101 ( F_100 ( V_87 , * V_264 ) , 1UL << 24 ) ;
break;
case V_328 :
F_94 ( V_6 , F_100 ( V_87 , * V_264 ) , true ) ;
break;
case V_329 :
F_94 ( V_6 , F_100 ( V_87 , * V_264 ) , false ) ;
break;
case V_330 :
V_6 -> V_25 . V_331 = F_100 ( V_87 , * V_264 ) ;
break;
#ifdef F_98
case V_332 :
V_6 -> V_25 . V_333 = F_100 ( V_87 , * V_264 ) ;
break;
case V_334 :
V_6 -> V_25 . V_335 = F_100 ( V_87 , * V_264 ) ;
break;
case V_336 :
V_6 -> V_25 . V_337 = F_100 ( V_87 , * V_264 ) ;
break;
case V_338 ... V_339 :
V_5 = V_87 - V_338 ;
V_6 -> V_25 . V_340 [ V_5 ] = F_100 ( V_87 , * V_264 ) ;
break;
case V_341 ... V_342 :
{
int V_251 ;
V_5 = V_87 - V_341 ;
if ( V_5 < 32 )
for ( V_251 = 0 ; V_251 < V_343 ; V_251 ++ )
V_6 -> V_25 . V_345 . V_346 [ V_5 ] [ V_251 ] = V_264 -> V_344 [ V_251 ] ;
else
if ( F_5 ( V_347 ) )
V_6 -> V_25 . V_349 . V_350 [ V_5 - 32 ] = V_264 -> V_348 ;
else
V_61 = - V_351 ;
break;
}
case V_352 :
V_6 -> V_25 . V_353 = F_100 ( V_87 , * V_264 ) ;
break;
case V_354 :
V_6 -> V_25 . V_355 = F_100 ( V_87 , * V_264 ) ;
break;
case V_356 :
V_6 -> V_25 . V_357 = F_100 ( V_87 , * V_264 ) ;
break;
case V_358 :
V_6 -> V_25 . V_359 = F_100 ( V_87 , * V_264 ) ;
break;
case V_360 :
V_6 -> V_25 . V_345 . V_361 = F_100 ( V_87 , * V_264 ) ;
break;
case V_362 :
V_6 -> V_25 . V_363 = F_100 ( V_87 , * V_264 ) ;
break;
case V_364 :
V_6 -> V_25 . V_365 = F_100 ( V_87 , * V_264 ) ;
break;
case V_366 :
V_6 -> V_25 . V_367 = F_100 ( V_87 , * V_264 ) ;
break;
case V_368 :
if ( F_5 ( V_347 ) )
V_6 -> V_25 . V_350 . V_369 . V_246 [ 3 ] = F_100 ( V_87 , * V_264 ) ;
else
V_61 = - V_351 ;
break;
case V_370 :
V_6 -> V_25 . V_371 = F_100 ( V_87 , * V_264 ) ;
break;
case V_372 :
V_6 -> V_25 . V_373 = F_100 ( V_87 , * V_264 ) ;
break;
#endif
case V_374 :
V_61 = F_32 ( V_6 , F_100 ( V_87 , * V_264 ) ) ;
break;
default:
V_61 = - V_58 ;
break;
}
return V_61 ;
}
static int F_102 ( void )
{
if ( F_5 ( V_12 ) )
return 1 ;
return V_378 ;
}
static struct V_2 * F_103 ( struct V_84 * V_84 , int V_379 )
{
struct V_2 * V_32 ;
V_32 = F_104 ( sizeof( struct V_2 ) , V_380 ) ;
if ( V_32 == NULL )
return NULL ;
F_105 ( & V_32 -> V_59 ) ;
F_105 ( & V_32 -> V_28 ) ;
F_106 ( & V_32 -> V_381 ) ;
V_32 -> V_29 = V_30 ;
V_32 -> V_83 = V_84 -> V_25 . V_83 ;
V_32 -> V_382 = V_379 * F_102 () ;
V_32 -> V_84 = V_84 ;
F_107 ( & V_32 -> V_383 ) ;
return V_32 ;
}
static int F_108 ( struct V_384 * V_384 , struct V_385 * V_385 )
{
struct V_1 * V_6 = V_384 -> V_386 ;
struct V_387 * V_133 ;
V_133 = F_104 ( sizeof( * V_133 ) , V_380 ) ;
if ( ! V_133 )
return - V_388 ;
F_109 ( V_6 -> V_84 ) ;
V_133 -> V_6 = V_6 ;
V_385 -> V_389 = V_133 ;
return F_110 ( V_384 , V_385 ) ;
}
static int F_111 ( struct V_384 * V_384 , struct V_385 * V_385 )
{
struct V_387 * V_133 = V_385 -> V_389 ;
F_112 ( V_133 -> V_6 -> V_84 ) ;
F_113 ( V_133 ) ;
return 0 ;
}
static T_4 F_114 ( struct V_385 * V_385 , char T_5 * V_390 ,
T_6 V_97 , T_7 * V_391 )
{
struct V_387 * V_133 = V_385 -> V_389 ;
struct V_1 * V_6 = V_133 -> V_6 ;
char * V_247 , * V_392 ;
struct V_393 V_394 ;
T_1 V_395 ;
T_7 V_396 ;
T_4 V_397 ;
int V_5 , V_398 ;
bool V_399 ;
if ( ! V_133 -> V_400 ) {
V_247 = V_133 -> V_390 ;
V_392 = V_247 + sizeof( V_133 -> V_390 ) ;
for ( V_5 = 0 ; V_5 < V_401 ; ++ V_5 ) {
struct V_393 * V_402 ;
V_402 = (struct V_393 * )
( ( unsigned long ) V_6 + V_403 [ V_5 ] . V_404 ) ;
V_399 = false ;
for ( V_398 = 0 ; V_398 < 1000 ; ++ V_398 ) {
V_395 = V_402 -> V_405 ;
if ( ! ( V_395 & 1 ) ) {
F_115 () ;
V_394 = * V_402 ;
F_115 () ;
if ( V_395 == V_402 -> V_405 ) {
V_399 = true ;
break;
}
}
F_116 ( 1 ) ;
}
if ( ! V_399 )
snprintf ( V_247 , V_392 - V_247 , L_16 ,
V_403 [ V_5 ] . V_406 ) ;
else
snprintf ( V_247 , V_392 - V_247 ,
L_17 ,
V_403 [ V_5 ] . V_406 , V_395 / 2 ,
F_117 ( V_394 . V_407 ) ,
F_117 ( V_394 . V_408 ) ,
F_117 ( V_394 . V_409 ) ) ;
V_247 += strlen ( V_247 ) ;
}
V_133 -> V_400 = V_247 - V_133 -> V_390 ;
}
V_396 = * V_391 ;
if ( V_396 >= V_133 -> V_400 )
return 0 ;
if ( V_97 > V_133 -> V_400 - V_396 )
V_97 = V_133 -> V_400 - V_396 ;
V_397 = F_118 ( V_390 , V_133 -> V_390 + V_396 , V_97 ) ;
if ( V_397 ) {
if ( V_397 == V_97 )
return - V_410 ;
V_97 -= V_397 ;
}
* V_391 = V_396 + V_97 ;
return V_97 ;
}
static T_4 F_119 ( struct V_385 * V_385 , const char T_5 * V_390 ,
T_6 V_97 , T_7 * V_391 )
{
return - V_411 ;
}
static void F_120 ( struct V_1 * V_6 , unsigned int V_87 )
{
char V_390 [ 16 ] ;
struct V_84 * V_84 = V_6 -> V_84 ;
snprintf ( V_390 , sizeof( V_390 ) , L_18 , V_87 ) ;
if ( F_121 ( V_84 -> V_25 . V_412 ) )
return;
V_6 -> V_25 . V_412 = F_122 ( V_390 , V_84 -> V_25 . V_412 ) ;
if ( F_121 ( V_6 -> V_25 . V_412 ) )
return;
V_6 -> V_25 . V_413 =
F_123 ( L_19 , 0444 , V_6 -> V_25 . V_412 ,
V_6 , & V_414 ) ;
}
static void F_120 ( struct V_1 * V_6 , unsigned int V_87 )
{
}
static struct V_1 * F_124 ( struct V_84 * V_84 ,
unsigned int V_87 )
{
struct V_1 * V_6 ;
int V_108 = - V_58 ;
int V_379 ;
struct V_2 * V_32 ;
V_379 = V_87 / F_102 () ;
if ( V_379 >= V_415 )
goto V_416;
V_108 = - V_388 ;
V_6 = F_125 ( V_417 , V_380 ) ;
if ( ! V_6 )
goto V_416;
V_108 = F_126 ( V_6 , V_84 , V_87 ) ;
if ( V_108 )
goto V_418;
V_6 -> V_25 . V_419 = & V_6 -> V_25 . V_43 ;
#ifdef F_127
#ifdef F_128
V_6 -> V_25 . V_420 = true ;
#else
V_6 -> V_25 . V_420 = false ;
#endif
#endif
V_6 -> V_25 . V_283 [ 0 ] = V_421 ;
V_6 -> V_25 . V_422 = V_423 ;
F_31 ( V_6 , F_129 ( V_424 ) ) ;
F_105 ( & V_6 -> V_25 . V_99 ) ;
F_105 ( & V_6 -> V_25 . V_36 ) ;
V_6 -> V_25 . V_39 = V_30 ;
V_6 -> V_25 . V_258 = V_425 | V_426 ;
F_130 ( V_6 ) ;
V_6 -> V_25 . V_37 = V_427 ;
F_131 ( & V_6 -> V_25 . V_428 ) ;
F_39 ( & V_84 -> V_59 ) ;
V_32 = V_84 -> V_25 . V_429 [ V_379 ] ;
if ( ! V_32 ) {
V_32 = F_103 ( V_84 , V_379 ) ;
V_84 -> V_25 . V_429 [ V_379 ] = V_32 ;
V_84 -> V_25 . V_430 ++ ;
}
F_41 ( & V_84 -> V_59 ) ;
if ( ! V_32 )
goto V_418;
F_33 ( & V_32 -> V_59 ) ;
++ V_32 -> V_431 ;
F_34 ( & V_32 -> V_59 ) ;
V_6 -> V_25 . V_32 = V_32 ;
V_6 -> V_25 . V_142 = V_6 -> V_62 - V_32 -> V_382 ;
V_6 -> V_25 . V_26 = - 1 ;
V_6 -> V_25 . V_432 = - 1 ;
V_6 -> V_25 . V_433 = V_434 ;
F_132 ( V_6 ) ;
F_120 ( V_6 , V_87 ) ;
return V_6 ;
V_418:
F_133 ( V_417 , V_6 ) ;
V_416:
return F_134 ( V_108 ) ;
}
static void F_135 ( struct V_84 * V_84 , struct V_94 * V_90 )
{
if ( V_90 -> V_103 )
F_50 ( V_84 , V_90 -> V_103 , V_90 -> V_127 ,
V_90 -> V_128 ) ;
}
static void F_136 ( struct V_1 * V_6 )
{
F_33 ( & V_6 -> V_25 . V_99 ) ;
F_135 ( V_6 -> V_84 , & V_6 -> V_25 . V_122 ) ;
F_135 ( V_6 -> V_84 , & V_6 -> V_25 . V_123 ) ;
F_135 ( V_6 -> V_84 , & V_6 -> V_25 . V_90 ) ;
F_34 ( & V_6 -> V_25 . V_99 ) ;
F_137 ( V_6 ) ;
F_133 ( V_417 , V_6 ) ;
}
static int F_138 ( struct V_1 * V_6 )
{
return 1 ;
}
static void F_139 ( struct V_1 * V_6 )
{
unsigned long V_435 , V_132 ;
V_132 = F_140 () ;
if ( V_132 > V_6 -> V_25 . V_436 ) {
F_141 ( V_6 ) ;
F_142 ( V_6 ) ;
return;
}
V_435 = ( V_6 -> V_25 . V_436 - V_132 ) * V_437
/ V_438 ;
F_143 ( & V_6 -> V_25 . V_439 , V_435 , V_440 ) ;
V_6 -> V_25 . V_441 = 1 ;
}
static void F_30 ( struct V_1 * V_6 )
{
V_6 -> V_25 . V_176 = 0 ;
if ( V_6 -> V_25 . V_441 ) {
F_144 ( & V_6 -> V_25 . V_439 ) ;
V_6 -> V_25 . V_441 = 0 ;
}
}
static void F_145 ( struct V_2 * V_3 ,
struct V_1 * V_6 )
{
T_1 V_132 ;
if ( V_6 -> V_25 . V_37 != V_166 )
return;
F_55 ( & V_6 -> V_25 . V_36 ) ;
V_132 = F_24 () ;
V_6 -> V_25 . V_40 += F_53 ( V_3 , V_132 ) -
V_6 -> V_25 . V_138 ;
V_6 -> V_25 . V_39 = V_132 ;
V_6 -> V_25 . V_37 = V_38 ;
F_56 ( & V_6 -> V_25 . V_36 ) ;
-- V_3 -> V_442 ;
F_146 ( V_3 -> V_8 [ V_6 -> V_25 . V_142 ] , NULL ) ;
}
static int F_147 ( int V_9 )
{
struct V_443 * V_444 ;
long V_445 = 10000 ;
V_444 = & V_17 [ V_9 ] ;
V_444 -> V_18 . V_1 = NULL ;
V_444 -> V_18 . V_446 = NULL ;
V_444 -> V_18 . V_447 = 0 ;
F_60 () ;
V_444 -> V_18 . V_448 = 1 ;
F_7 () ;
while ( V_444 -> V_18 . V_449 == V_450 ) {
if ( -- V_445 <= 0 ) {
F_36 ( L_20 , V_9 ) ;
return - V_451 ;
}
F_116 ( 1 ) ;
}
return 0 ;
}
static void F_148 ( int V_9 )
{
struct V_443 * V_444 ;
V_444 = & V_17 [ V_9 ] ;
V_444 -> V_18 . V_448 = 0 ;
V_444 -> V_18 . V_1 = NULL ;
V_444 -> V_18 . V_446 = NULL ;
V_444 -> V_18 . V_452 = NULL ;
}
static void F_149 ( void * V_453 )
{
}
static void F_150 ( struct V_84 * V_84 , int V_9 , struct V_1 * V_6 )
{
int V_5 ;
V_9 = F_9 ( V_9 ) ;
F_151 ( V_9 , & V_84 -> V_25 . V_454 ) ;
F_7 () ;
for ( V_5 = 0 ; V_5 < V_455 ; ++ V_5 )
if ( F_152 ( V_9 + V_5 , & V_84 -> V_25 . V_456 ) )
F_153 ( V_9 + V_5 , F_149 , NULL , 1 ) ;
}
static void F_154 ( struct V_1 * V_6 , struct V_2 * V_3 )
{
int V_9 ;
struct V_443 * V_444 ;
struct V_2 * V_457 = V_3 -> V_458 ;
struct V_84 * V_84 = V_3 -> V_84 ;
V_9 = V_3 -> V_141 ;
if ( V_6 ) {
if ( V_6 -> V_25 . V_441 ) {
F_144 ( & V_6 -> V_25 . V_439 ) ;
V_6 -> V_25 . V_441 = 0 ;
}
V_9 += V_6 -> V_25 . V_142 ;
V_6 -> V_9 = V_457 -> V_141 ;
V_6 -> V_25 . V_26 = V_9 ;
if ( F_155 ( V_84 ) && V_6 -> V_25 . V_432 != V_9 ) {
if ( V_6 -> V_25 . V_432 >= 0 &&
F_9 ( V_6 -> V_25 . V_432 ) !=
F_9 ( V_9 ) )
F_150 ( V_84 , V_6 -> V_25 . V_432 , V_6 ) ;
V_6 -> V_25 . V_432 = V_9 ;
}
F_151 ( V_9 , & V_84 -> V_25 . V_456 ) ;
}
V_444 = & V_17 [ V_9 ] ;
V_444 -> V_18 . V_1 = V_6 ;
V_444 -> V_18 . V_142 = V_9 - V_457 -> V_141 ;
F_60 () ;
V_444 -> V_18 . V_446 = V_457 ;
if ( V_9 != F_10 () )
F_3 ( V_9 ) ;
}
static void F_156 ( void )
{
int V_9 = F_10 () ;
int V_5 , V_398 ;
int V_459 = F_102 () ;
if ( V_459 <= 1 )
return;
for ( V_398 = 0 ; V_398 < 1000000 ; ++ V_398 ) {
for ( V_5 = 1 ; V_5 < V_459 ; ++ V_5 )
if ( V_17 [ V_9 + V_5 ] . V_18 . V_446 )
break;
if ( V_5 == V_459 ) {
F_157 () ;
return;
}
F_158 () ;
}
F_157 () ;
for ( V_5 = 1 ; V_5 < V_459 ; ++ V_5 )
if ( V_17 [ V_9 + V_5 ] . V_18 . V_446 )
F_36 ( L_21 , V_9 + V_5 ) ;
}
static int F_159 ( void )
{
int V_9 = F_10 () ;
int V_460 ;
if ( F_160 ( V_9 ) )
return 0 ;
V_460 = 0 ;
while ( ++ V_460 < V_378 )
if ( F_20 ( V_9 + V_460 ) )
return 0 ;
for ( V_460 = 1 ; V_460 < V_378 ; ++ V_460 ) {
if ( F_147 ( V_9 + V_460 ) ) {
do {
F_148 ( V_9 + V_460 ) ;
} while ( -- V_460 > 0 );
return 0 ;
}
}
return 1 ;
}
static void F_161 ( void )
{
int V_9 ;
F_162 (cpu) {
struct V_461 * V_462 = & F_163 ( V_463 , V_9 ) ;
F_105 ( & V_462 -> V_59 ) ;
F_107 ( & V_462 -> V_464 ) ;
}
}
static void F_164 ( struct V_2 * V_3 )
{
struct V_461 * V_462 = F_165 ( & V_463 ) ;
V_3 -> V_34 = V_465 ;
V_3 -> V_141 = F_10 () ;
if ( V_3 -> V_431 < F_102 () ) {
F_33 ( & V_462 -> V_59 ) ;
F_166 ( & V_3 -> V_383 , & V_462 -> V_464 ) ;
F_34 ( & V_462 -> V_59 ) ;
}
F_22 ( V_3 ) ;
}
static void F_167 ( struct V_2 * V_3 )
{
struct V_461 * V_462 ;
F_26 ( V_3 ) ;
if ( ! F_68 ( & V_3 -> V_383 ) ) {
V_462 = & F_163 ( V_463 , V_3 -> V_141 ) ;
F_33 ( & V_462 -> V_59 ) ;
F_168 ( & V_3 -> V_383 ) ;
F_34 ( & V_462 -> V_59 ) ;
}
V_3 -> V_34 = V_134 ;
}
static void F_169 ( struct V_466 * V_467 , struct V_2 * V_3 )
{
int V_468 ;
memset ( V_467 , 0 , sizeof( * V_467 ) ) ;
V_467 -> V_469 = 1 ;
V_467 -> V_470 = V_3 -> V_431 ;
V_467 -> V_471 = V_3 -> V_431 ;
V_467 -> V_472 [ 0 ] = V_3 -> V_431 ;
V_467 -> V_473 [ 0 ] = V_3 -> V_84 ;
for ( V_468 = 0 ; V_468 < V_474 ; ++ V_468 )
F_107 ( & V_467 -> V_475 [ V_468 ] ) ;
F_166 ( & V_3 -> V_383 , & V_467 -> V_475 [ 0 ] ) ;
}
static bool F_170 ( int V_469 , int V_459 )
{
if ( V_469 > 1 && V_378 < V_7 )
return false ;
if ( V_469 > V_474 )
return false ;
if ( V_469 > 1 ) {
if ( ! ( V_476 & 2 ) )
V_469 = 4 ;
if ( V_469 > 2 && ! ( V_476 & 4 ) )
return false ;
}
return V_469 * F_171 ( V_459 ) <= V_7 ;
}
static void F_172 ( struct V_2 * V_3 )
{
V_3 -> V_458 = V_3 ;
V_3 -> V_477 = 0 ;
V_3 -> V_478 = 0 ;
V_3 -> V_479 = 0 ;
V_3 -> V_480 = 0 ;
}
static bool F_173 ( struct V_2 * V_3 , struct V_466 * V_467 )
{
int V_459 = V_3 -> V_431 ;
int V_468 ;
if ( ! F_5 ( V_13 ) )
return false ;
if ( V_459 < V_467 -> V_470 )
V_459 = V_467 -> V_470 ;
if ( ! F_170 ( V_467 -> V_469 + 1 , V_459 ) )
return false ;
V_467 -> V_470 = V_459 ;
V_468 = V_467 -> V_469 ;
++ V_467 -> V_469 ;
V_467 -> V_471 += V_3 -> V_431 ;
V_467 -> V_472 [ V_468 ] = V_3 -> V_431 ;
V_467 -> V_473 [ V_468 ] = V_3 -> V_84 ;
F_172 ( V_3 ) ;
F_174 ( & V_3 -> V_383 , & V_467 -> V_475 [ V_468 ] ) ;
return true ;
}
static bool F_175 ( struct V_2 * V_481 , struct V_466 * V_467 ,
int V_482 )
{
if ( V_467 -> V_471 + V_481 -> V_431 > V_482 )
return false ;
return F_173 ( V_481 , V_467 ) ;
}
static void F_176 ( struct V_2 * V_3 )
{
int V_5 ;
struct V_1 * V_6 ;
F_177 (i, vcpu, vc) {
if ( F_178 ( V_6 -> V_25 . V_483 ) )
V_6 -> V_25 . V_88 = - V_484 ;
else if ( V_6 -> V_25 . V_90 . V_101 ||
V_6 -> V_25 . V_123 . V_101 ||
V_6 -> V_25 . V_122 . V_101 )
V_6 -> V_25 . V_88 = V_193 ;
else
continue;
F_145 ( V_3 , V_6 ) ;
F_179 ( & V_6 -> V_25 . V_428 ) ;
}
}
static void F_180 ( struct V_466 * V_467 , int V_482 )
{
struct V_461 * V_462 = F_165 ( & V_463 ) ;
struct V_2 * V_481 , * V_485 ;
F_33 ( & V_462 -> V_59 ) ;
F_181 (pvc, vcnext, &lp->list, preempt_list) {
if ( ! F_182 ( & V_481 -> V_59 ) )
continue;
F_176 ( V_481 ) ;
if ( ! V_481 -> V_442 ) {
F_168 ( & V_481 -> V_383 ) ;
if ( V_481 -> V_33 == NULL ) {
V_481 -> V_34 = V_134 ;
F_26 ( V_481 ) ;
}
F_34 ( & V_481 -> V_59 ) ;
continue;
}
if ( ! F_175 ( V_481 , V_467 , V_482 ) ) {
F_34 ( & V_481 -> V_59 ) ;
continue;
}
F_26 ( V_481 ) ;
V_481 -> V_34 = V_486 ;
if ( V_467 -> V_471 >= V_482 )
break;
}
F_34 ( & V_462 -> V_59 ) ;
}
static void F_183 ( struct V_2 * V_3 , bool V_487 )
{
int V_488 = 0 , V_5 ;
T_1 V_132 ;
long V_88 ;
struct V_1 * V_6 ;
F_33 ( & V_3 -> V_59 ) ;
V_132 = F_140 () ;
F_177 (i, vcpu, vc) {
if ( V_132 < V_6 -> V_25 . V_436 &&
F_184 ( V_6 ) )
F_185 ( V_6 ) ;
F_186 ( V_6 ) ;
V_88 = V_193 ;
if ( V_6 -> V_25 . V_64 )
V_88 = F_87 ( V_6 -> V_25 . V_199 , V_6 ,
V_6 -> V_25 . V_483 ) ;
V_6 -> V_25 . V_88 = V_88 ;
V_6 -> V_25 . V_64 = 0 ;
if ( F_187 ( V_6 -> V_25 . V_88 ) ) {
if ( V_6 -> V_25 . V_489 )
F_142 ( V_6 ) ;
if ( V_6 -> V_25 . V_176 )
F_139 ( V_6 ) ;
else
++ V_488 ;
} else {
F_145 ( V_3 , V_6 ) ;
F_179 ( & V_6 -> V_25 . V_428 ) ;
}
}
F_168 ( & V_3 -> V_383 ) ;
if ( ! V_487 ) {
if ( V_488 > 0 ) {
F_164 ( V_3 ) ;
} else if ( V_3 -> V_33 ) {
V_3 -> V_34 = V_465 ;
F_22 ( V_3 ) ;
} else {
V_3 -> V_34 = V_134 ;
}
if ( V_3 -> V_442 > 0 && V_3 -> V_33 == NULL ) {
V_5 = - 1 ;
V_6 = F_1 ( V_3 , & V_5 ) ;
F_179 ( & V_6 -> V_25 . V_428 ) ;
}
}
F_34 ( & V_3 -> V_59 ) ;
}
static inline int F_188 ( unsigned int V_9 )
{
int V_379 ;
if ( ! V_490 || F_11 ( V_9 ) )
return 0 ;
V_379 = V_9 >> V_491 ;
V_490 -> V_492 [ V_379 ] . V_493 . V_494 = 0 ;
return 0 ;
}
static inline int F_189 ( unsigned int V_9 )
{
int V_379 ;
if ( ! V_490 || F_11 ( V_9 ) )
return 0 ;
V_379 = V_9 >> V_491 ;
V_490 -> V_492 [ V_379 ] . V_493 . V_494 = 1 ;
return 0 ;
}
static T_8 void F_190 ( struct V_2 * V_3 )
{
struct V_1 * V_6 ;
int V_5 ;
int V_495 ;
struct V_466 V_466 ;
struct V_2 * V_481 , * V_485 ;
struct V_452 V_496 , * V_497 ;
int V_498 , V_499 , V_500 ;
int V_468 ;
bool V_501 ;
unsigned long V_502 , V_503 ;
int V_141 , V_460 ;
int V_482 ;
int V_504 ;
F_176 ( V_3 ) ;
if ( V_3 -> V_33 -> V_25 . V_37 != V_166 )
return;
F_172 ( V_3 ) ;
V_3 -> V_29 = V_30 ;
V_504 = F_102 () ;
if ( ( V_504 > 1 ) &&
( ( V_3 -> V_431 > V_378 ) || ! F_159 () ) ) {
F_177 (i, vcpu, vc) {
V_6 -> V_25 . V_88 = - V_451 ;
F_145 ( V_3 , V_6 ) ;
F_179 ( & V_6 -> V_25 . V_428 ) ;
}
goto V_416;
}
F_169 ( & V_466 , V_3 ) ;
V_141 = F_10 () ;
V_482 = V_504 ;
if ( V_505 && V_505 < V_482 )
V_482 = V_505 ;
if ( V_3 -> V_431 < V_482 )
F_180 ( & V_466 , V_482 ) ;
V_499 = V_378 ;
V_502 = V_503 = 0 ;
V_498 = V_466 . V_469 ;
V_497 = NULL ;
if ( V_498 > 1 ) {
if ( V_498 == 2 && ( V_476 & 2 ) ) {
V_502 = V_506 ;
V_503 = V_507 ;
} else {
V_498 = 4 ;
V_502 = V_508 ;
V_503 = V_509 ;
}
V_499 = V_7 / V_498 ;
V_497 = & V_496 ;
memset ( & V_496 , 0 , sizeof( V_496 ) ) ;
V_496 . V_510 = F_129 ( V_511 ) ;
V_496 . V_512 = F_129 ( V_513 ) ;
V_496 . V_514 = F_129 ( V_515 ) ;
V_496 . V_499 = V_499 ;
for ( V_468 = 0 ; V_468 < V_466 . V_469 ; ++ V_468 )
V_496 . V_516 [ V_468 ] =
F_191 ( & V_466 . V_475 [ V_468 ] ,
struct V_2 , V_383 ) ;
F_60 () ;
}
V_141 = F_10 () ;
for ( V_460 = 0 ; V_460 < V_504 ; ++ V_460 )
V_17 [ V_141 + V_460 ] . V_18 . V_452 = V_497 ;
if ( V_502 ) {
unsigned long V_517 = F_129 ( V_518 ) ;
V_517 |= V_502 | V_519 ;
F_192 () ;
F_193 ( V_518 , V_517 ) ;
F_194 () ;
for (; ; ) {
V_517 = F_129 ( V_518 ) ;
if ( V_517 & V_503 )
break;
F_195 () ;
}
}
F_188 ( V_141 ) ;
V_500 = 0 ;
for ( V_468 = 0 ; V_468 < V_466 . V_469 ; ++ V_468 ) {
V_460 = V_520 [ V_468 ] ;
V_501 = false ;
V_500 |= 1 << V_460 ;
F_196 (pvc, &core_info.vcs[sub], preempt_list) {
V_481 -> V_141 = V_141 + V_460 ;
F_177 (i, vcpu, pvc) {
F_154 ( V_6 , V_481 ) ;
F_54 ( V_6 , V_481 ) ;
F_197 ( V_6 ) ;
if ( ! V_6 -> V_25 . V_142 )
V_501 = true ;
V_500 |= 1 << ( V_460 + V_6 -> V_25 . V_142 ) ;
}
if ( V_481 -> V_458 == V_481 && ! V_501 )
F_154 ( NULL , V_481 ) ;
V_460 += V_481 -> V_431 ;
}
}
F_7 () ;
if ( V_502 )
V_496 . V_521 = 1 ;
if ( V_498 > 1 )
for ( V_460 = 1 ; V_460 < V_378 ; ++ V_460 )
if ( ! ( V_500 & ( 1 << V_460 ) ) )
F_3 ( V_141 + V_460 ) ;
V_3 -> V_34 = V_522 ;
F_8 () ;
F_198 ( V_3 , 0 ) ;
for ( V_468 = 0 ; V_468 < V_466 . V_469 ; ++ V_468 )
F_196 (pvc, &core_info.vcs[sub], preempt_list)
F_34 ( & V_481 -> V_59 ) ;
F_199 () ;
V_495 = F_69 ( & V_3 -> V_84 -> V_181 ) ;
F_200 () ;
F_71 ( & V_3 -> V_84 -> V_181 , V_495 ) ;
F_33 ( & V_3 -> V_59 ) ;
V_3 -> V_34 = V_523 ;
F_156 () ;
if ( V_498 > 1 ) {
unsigned long V_517 = F_129 ( V_518 ) ;
unsigned long V_398 = 0 ;
V_517 &= ~ V_519 ;
V_503 = V_507 | V_509 ;
F_192 () ;
F_193 ( V_518 , V_517 ) ;
F_194 () ;
for (; ; ) {
V_517 = F_129 ( V_518 ) ;
if ( ! ( V_517 & V_503 ) )
break;
F_195 () ;
++ V_398 ;
}
V_496 . V_521 = 0 ;
}
for ( V_5 = 0 ; V_5 < V_504 ; ++ V_5 ) {
F_148 ( V_141 + V_5 ) ;
if ( V_497 && V_497 -> V_524 [ V_5 ] )
F_3 ( V_141 + V_5 ) ;
F_201 ( V_141 + V_5 , & V_3 -> V_84 -> V_25 . V_456 ) ;
}
F_189 ( V_141 ) ;
F_34 ( & V_3 -> V_59 ) ;
F_7 () ;
F_202 () ;
for ( V_468 = 0 ; V_468 < V_466 . V_469 ; ++ V_468 )
F_181 (pvc, vcnext, &core_info.vcs[sub],
preempt_list)
F_183 ( V_481 , V_481 == V_3 ) ;
F_33 ( & V_3 -> V_59 ) ;
F_12 () ;
V_416:
V_3 -> V_34 = V_134 ;
F_198 ( V_3 , 1 ) ;
}
static void F_203 ( struct V_2 * V_3 ,
struct V_1 * V_6 , int V_525 )
{
F_204 ( V_526 ) ;
F_205 ( & V_6 -> V_25 . V_428 , & V_526 , V_525 ) ;
if ( V_6 -> V_25 . V_37 == V_166 ) {
F_34 ( & V_3 -> V_59 ) ;
F_206 () ;
F_33 ( & V_3 -> V_59 ) ;
}
F_207 ( & V_6 -> V_25 . V_428 , & V_526 ) ;
}
static void F_208 ( struct V_2 * V_3 )
{
if ( V_3 -> V_527 == 0 && V_528 )
V_3 -> V_527 = 10000 ;
else
V_3 -> V_527 *= V_528 ;
}
static void F_209 ( struct V_2 * V_3 )
{
if ( V_529 == 0 )
V_3 -> V_527 = 0 ;
else
V_3 -> V_527 /= V_529 ;
}
static int F_210 ( struct V_2 * V_3 )
{
struct V_1 * V_6 ;
int V_5 ;
F_177 (i, vcpu, vc) {
if ( V_6 -> V_25 . V_489 || ! V_6 -> V_25 . V_176 ||
V_6 -> V_25 . V_175 )
return 1 ;
}
return 0 ;
}
static void F_211 ( struct V_2 * V_3 )
{
T_9 V_530 , V_531 , V_532 ;
int V_533 = 1 ;
T_1 V_534 ;
F_212 ( V_526 ) ;
V_530 = V_531 = F_213 () ;
if ( V_3 -> V_527 ) {
T_9 V_535 = F_214 ( V_531 , V_3 -> V_527 ) ;
++ V_3 -> V_33 -> V_23 . V_536 ;
V_3 -> V_34 = V_537 ;
F_34 ( & V_3 -> V_59 ) ;
do {
if ( F_210 ( V_3 ) ) {
V_533 = 0 ;
break;
}
V_530 = F_213 () ;
} while ( F_215 () && F_216 ( V_530 , V_535 ) );
F_33 ( & V_3 -> V_59 ) ;
V_3 -> V_34 = V_134 ;
if ( ! V_533 ) {
++ V_3 -> V_33 -> V_23 . V_538 ;
goto V_416;
}
}
F_217 ( & V_3 -> V_381 , & V_526 , V_539 ) ;
if ( F_210 ( V_3 ) ) {
F_218 ( & V_3 -> V_381 , & V_526 ) ;
V_533 = 0 ;
if ( V_3 -> V_527 )
++ V_3 -> V_33 -> V_23 . V_538 ;
goto V_416;
}
V_532 = F_213 () ;
V_3 -> V_34 = V_35 ;
F_219 ( V_3 , 0 ) ;
F_34 ( & V_3 -> V_59 ) ;
F_206 () ;
F_218 ( & V_3 -> V_381 , & V_526 ) ;
F_33 ( & V_3 -> V_59 ) ;
V_3 -> V_34 = V_134 ;
F_219 ( V_3 , 1 ) ;
++ V_3 -> V_33 -> V_23 . V_540 ;
V_530 = F_213 () ;
V_416:
V_534 = F_220 ( V_530 ) - F_220 ( V_531 ) ;
if ( V_533 ) {
V_3 -> V_33 -> V_23 . V_541 +=
F_220 ( V_530 ) - F_220 ( V_532 ) ;
if ( V_3 -> V_527 )
V_3 -> V_33 -> V_23 . V_542 +=
F_220 ( V_532 ) -
F_220 ( V_531 ) ;
} else {
if ( V_3 -> V_527 )
V_3 -> V_33 -> V_23 . V_543 +=
F_220 ( V_530 ) -
F_220 ( V_531 ) ;
}
if ( V_527 ) {
if ( V_534 <= V_3 -> V_527 )
;
else if ( V_3 -> V_527 && V_534 > V_527 )
F_209 ( V_3 ) ;
else if ( V_3 -> V_527 < V_527 &&
V_534 < V_527 )
F_208 ( V_3 ) ;
if ( V_3 -> V_527 > V_527 )
V_3 -> V_527 = V_527 ;
} else
V_3 -> V_527 = 0 ;
F_221 ( V_533 , V_534 ) ;
}
static int F_222 ( struct V_199 * V_199 , struct V_1 * V_6 )
{
int V_544 , V_5 ;
struct V_2 * V_3 ;
struct V_1 * V_95 ;
F_223 ( V_6 ) ;
V_199 -> V_204 = 0 ;
V_6 -> V_25 . V_88 = V_193 ;
V_6 -> V_25 . V_64 = 0 ;
F_52 ( V_6 ) ;
V_3 = V_6 -> V_25 . V_32 ;
F_33 ( & V_3 -> V_59 ) ;
V_6 -> V_25 . V_176 = 0 ;
V_6 -> V_25 . V_483 = V_545 ;
V_6 -> V_25 . V_199 = V_199 ;
V_6 -> V_25 . V_138 = F_53 ( V_3 , F_24 () ) ;
V_6 -> V_25 . V_37 = V_166 ;
V_6 -> V_25 . V_39 = V_30 ;
F_146 ( V_3 -> V_8 [ V_6 -> V_25 . V_142 ] , V_6 ) ;
++ V_3 -> V_442 ;
if ( ! F_178 ( V_545 ) ) {
if ( V_3 -> V_34 == V_486 ) {
struct V_2 * V_457 = V_3 -> V_458 ;
if ( F_182 ( & V_457 -> V_59 ) ) {
if ( V_457 -> V_34 == V_522 &&
! F_224 ( V_457 ) ) {
F_54 ( V_6 , V_3 ) ;
F_154 ( V_6 , V_3 ) ;
F_197 ( V_6 ) ;
}
F_34 ( & V_457 -> V_59 ) ;
}
} else if ( V_3 -> V_34 == V_522 &&
! F_224 ( V_3 ) ) {
F_54 ( V_6 , V_3 ) ;
F_154 ( V_6 , V_3 ) ;
F_197 ( V_6 ) ;
} else if ( V_3 -> V_34 == V_35 ) {
F_19 ( & V_3 -> V_381 ) ;
}
}
while ( V_6 -> V_25 . V_37 == V_166 &&
! F_178 ( V_545 ) ) {
if ( V_3 -> V_34 == V_465 && V_3 -> V_33 == NULL )
F_167 ( V_3 ) ;
if ( V_3 -> V_34 != V_134 ) {
F_203 ( V_3 , V_6 , V_539 ) ;
continue;
}
F_177 (i, v, vc) {
F_142 ( V_95 ) ;
if ( F_178 ( V_95 -> V_25 . V_483 ) ) {
F_145 ( V_3 , V_95 ) ;
V_95 -> V_23 . V_546 ++ ;
V_95 -> V_25 . V_199 -> V_204 = V_547 ;
V_95 -> V_25 . V_88 = - V_484 ;
F_179 ( & V_95 -> V_25 . V_428 ) ;
}
}
if ( ! V_3 -> V_442 || V_6 -> V_25 . V_37 != V_166 )
break;
V_544 = 0 ;
F_177 (i, v, vc) {
if ( ! V_95 -> V_25 . V_489 && ! V_95 -> V_25 . V_175 )
V_544 += V_95 -> V_25 . V_176 ;
else
V_95 -> V_25 . V_176 = 0 ;
}
V_3 -> V_33 = V_6 ;
if ( V_544 == V_3 -> V_442 ) {
F_211 ( V_3 ) ;
} else if ( F_225 () ) {
F_164 ( V_3 ) ;
F_226 ( & V_3 -> V_59 ) ;
if ( V_3 -> V_34 == V_465 )
F_167 ( V_3 ) ;
} else {
F_190 ( V_3 ) ;
}
V_3 -> V_33 = NULL ;
}
while ( V_6 -> V_25 . V_37 == V_166 &&
( V_3 -> V_34 == V_522 ||
V_3 -> V_34 == V_523 ||
V_3 -> V_34 == V_486 ) )
F_203 ( V_3 , V_6 , V_548 ) ;
if ( V_3 -> V_34 == V_465 && V_3 -> V_33 == NULL )
F_167 ( V_3 ) ;
if ( V_6 -> V_25 . V_37 == V_166 ) {
F_145 ( V_3 , V_6 ) ;
V_6 -> V_23 . V_546 ++ ;
V_199 -> V_204 = V_547 ;
V_6 -> V_25 . V_88 = - V_484 ;
}
if ( V_3 -> V_442 && V_3 -> V_34 == V_134 ) {
V_5 = - 1 ;
V_95 = F_1 ( V_3 , & V_5 ) ;
F_179 ( & V_95 -> V_25 . V_428 ) ;
}
F_227 ( V_6 , V_199 ) ;
F_34 ( & V_3 -> V_59 ) ;
return V_6 -> V_25 . V_88 ;
}
static int F_228 ( struct V_199 * V_200 , struct V_1 * V_6 )
{
int V_61 ;
int V_495 ;
unsigned long V_549 [ 3 ] = {} ;
unsigned long V_550 = 0 ;
unsigned int V_551 ;
if ( ! V_6 -> V_25 . V_552 ) {
V_200 -> V_204 = V_214 ;
return - V_58 ;
}
#ifdef F_98
if ( F_5 ( V_553 ) && V_545 -> V_554 . V_555 &&
( V_545 -> V_554 . V_555 -> V_41 & V_556 ) ) {
if ( F_229 ( V_545 -> V_554 . V_555 -> V_41 ) ) {
V_200 -> V_204 = V_557 ;
V_200 -> V_558 . V_559 = 0 ;
return - V_58 ;
}
V_545 -> V_554 . V_560 = F_129 ( V_561 ) ;
V_545 -> V_554 . V_562 = F_129 ( V_563 ) ;
V_545 -> V_554 . V_564 = F_129 ( V_565 ) ;
V_545 -> V_554 . V_555 -> V_41 &= ~ V_556 ;
}
#endif
F_142 ( V_6 ) ;
if ( F_178 ( V_545 ) ) {
V_200 -> V_204 = V_547 ;
return - V_484 ;
}
F_230 ( & V_6 -> V_84 -> V_25 . V_566 ) ;
F_7 () ;
if ( ! F_155 ( V_6 -> V_84 ) && ! V_6 -> V_84 -> V_25 . V_567 ) {
V_61 = F_231 ( V_6 ) ;
if ( V_61 )
goto V_416;
}
F_232 ( V_545 ) ;
if ( F_5 ( V_13 ) ) {
V_549 [ 0 ] = F_129 ( V_568 ) ;
V_549 [ 1 ] = F_129 ( V_569 ) ;
V_549 [ 2 ] = F_129 ( V_570 ) ;
V_550 = F_129 ( V_571 ) ;
}
V_551 = F_129 ( V_572 ) ;
V_6 -> V_25 . V_22 = & V_6 -> V_25 . V_32 -> V_381 ;
V_6 -> V_25 . V_573 = V_545 -> V_574 -> V_575 ;
V_6 -> V_25 . V_37 = V_38 ;
do {
V_61 = F_222 ( V_200 , V_6 ) ;
if ( V_200 -> V_204 == V_232 &&
! ( V_6 -> V_25 . V_43 . V_41 & V_576 ) ) {
F_233 ( V_6 ) ;
V_61 = F_66 ( V_6 ) ;
F_234 ( V_6 , V_61 ) ;
F_142 ( V_6 ) ;
} else if ( V_61 == V_234 ) {
V_495 = F_69 ( & V_6 -> V_84 -> V_181 ) ;
V_61 = F_235 ( V_200 , V_6 ,
V_6 -> V_25 . V_77 , V_6 -> V_25 . V_78 ) ;
F_71 ( & V_6 -> V_84 -> V_181 , V_495 ) ;
} else if ( V_61 == V_243 ) {
if ( F_236 ( F_75 () ) )
V_61 = V_159 ;
else
V_61 = F_237 ( V_6 , 0 ) ;
}
} while ( F_187 ( V_61 ) );
if ( F_5 ( V_13 ) ) {
F_193 ( V_568 , V_549 [ 0 ] ) ;
F_193 ( V_569 , V_549 [ 1 ] ) ;
F_193 ( V_570 , V_549 [ 2 ] ) ;
F_193 ( V_571 , V_550 ) ;
F_193 ( V_577 , V_545 -> V_554 . V_578 ) ;
}
F_193 ( V_572 , V_551 ) ;
V_416:
V_6 -> V_25 . V_37 = V_427 ;
F_238 ( & V_6 -> V_84 -> V_25 . V_566 ) ;
return V_61 ;
}
static void F_239 ( struct V_579 * * V_580 ,
int V_581 )
{
struct V_582 * V_583 = & V_584 [ V_581 ] ;
if ( ! V_583 -> V_585 )
return;
( * V_580 ) -> V_586 = V_583 -> V_585 ;
( * V_580 ) -> V_587 = V_583 -> V_588 ;
( * V_580 ) -> V_589 [ 0 ] . V_586 = V_583 -> V_585 ;
( * V_580 ) -> V_589 [ 0 ] . V_590 = V_583 -> V_591 [ V_581 ] ;
if ( V_581 != V_592 && V_583 -> V_591 [ V_592 ] != - 1 ) {
( * V_580 ) -> V_589 [ 1 ] . V_586 = 24 ;
( * V_580 ) -> V_589 [ 1 ] . V_590 = V_583 -> V_591 [ V_592 ] ;
}
( * V_580 ) ++ ;
}
static int F_240 ( struct V_84 * V_84 ,
struct V_593 * V_594 )
{
struct V_579 * V_580 ;
if ( F_241 () )
return - V_58 ;
V_594 -> V_27 = V_595 ;
if ( F_242 ( V_596 ) )
V_594 -> V_27 |= V_597 ;
V_594 -> V_598 = V_599 ;
V_580 = & V_594 -> V_580 [ 0 ] ;
F_239 ( & V_580 , V_600 ) ;
F_239 ( & V_580 , V_601 ) ;
F_239 ( & V_580 , V_592 ) ;
return 0 ;
}
static int F_243 ( struct V_84 * V_84 ,
struct V_602 * log )
{
struct V_603 * V_604 ;
struct V_605 * V_606 ;
int V_5 , V_61 ;
unsigned long V_397 ;
unsigned long * V_390 ;
struct V_1 * V_6 ;
F_39 ( & V_84 -> V_607 ) ;
V_61 = - V_58 ;
if ( log -> V_608 >= V_609 )
goto V_416;
V_604 = V_603 ( V_84 ) ;
V_606 = F_244 ( V_604 , log -> V_608 ) ;
V_61 = - V_182 ;
if ( ! V_606 -> V_610 )
goto V_416;
V_397 = F_245 ( V_606 ) ;
V_390 = V_606 -> V_610 + V_397 / sizeof( long ) ;
memset ( V_390 , 0 , V_397 ) ;
if ( F_155 ( V_84 ) )
V_61 = F_246 ( V_84 , V_606 , V_390 ) ;
else
V_61 = F_247 ( V_84 , V_606 , V_390 ) ;
if ( V_61 )
goto V_416;
F_95 (i, vcpu, kvm) {
F_33 ( & V_6 -> V_25 . V_99 ) ;
F_248 ( & V_6 -> V_25 . V_90 , V_606 , V_390 ) ;
F_248 ( & V_6 -> V_25 . V_122 , V_606 , V_390 ) ;
F_34 ( & V_6 -> V_25 . V_99 ) ;
}
V_61 = - V_410 ;
if ( F_118 ( log -> V_610 , V_390 , V_397 ) )
goto V_416;
V_61 = 0 ;
V_416:
F_41 ( & V_84 -> V_607 ) ;
return V_61 ;
}
static void F_249 ( struct V_605 * free ,
struct V_605 * V_611 )
{
if ( ! V_611 || free -> V_25 . V_612 != V_611 -> V_25 . V_612 ) {
F_250 ( free -> V_25 . V_612 ) ;
free -> V_25 . V_612 = NULL ;
}
}
static int F_251 ( struct V_605 * V_608 ,
unsigned long V_613 )
{
if ( F_241 () ) {
V_608 -> V_25 . V_612 = NULL ;
return 0 ;
}
V_608 -> V_25 . V_612 = F_252 ( V_613 * sizeof( * V_608 -> V_25 . V_612 ) ) ;
if ( ! V_608 -> V_25 . V_612 )
return - V_388 ;
return 0 ;
}
static int F_253 ( struct V_84 * V_84 ,
struct V_605 * V_606 ,
const struct V_614 * V_615 )
{
return 0 ;
}
static void F_254 ( struct V_84 * V_84 ,
const struct V_614 * V_615 ,
const struct V_605 * V_616 ,
const struct V_605 * V_617 )
{
unsigned long V_613 = V_615 -> V_618 >> V_619 ;
struct V_603 * V_604 ;
struct V_605 * V_606 ;
if ( V_613 )
F_255 ( & V_84 -> V_25 . V_620 ) ;
if ( V_613 && V_616 -> V_613 && ! F_155 ( V_84 ) ) {
V_604 = V_603 ( V_84 ) ;
V_606 = F_244 ( V_604 , V_615 -> V_608 ) ;
F_247 ( V_84 , V_606 , NULL ) ;
}
}
void F_256 ( struct V_84 * V_84 , unsigned long V_83 , unsigned long V_256 )
{
long int V_5 ;
T_2 V_621 = 0 ;
if ( ( V_84 -> V_25 . V_83 & V_256 ) == V_83 )
return;
V_84 -> V_25 . V_83 = ( V_84 -> V_25 . V_83 & ~ V_256 ) | V_83 ;
for ( V_5 = 0 ; V_5 < V_415 ; ++ V_5 ) {
struct V_2 * V_3 = V_84 -> V_25 . V_429 [ V_5 ] ;
if ( ! V_3 )
continue;
F_33 ( & V_3 -> V_59 ) ;
V_3 -> V_83 = ( V_3 -> V_83 & ~ V_256 ) | V_83 ;
F_34 ( & V_3 -> V_59 ) ;
if ( ++ V_621 >= V_84 -> V_25 . V_430 )
break;
}
}
static void F_257 ( struct V_1 * V_6 )
{
return;
}
static void F_258 ( struct V_84 * V_84 )
{
unsigned long V_622 , V_623 ;
if ( ! F_155 ( V_84 ) ) {
V_622 = ( ( V_84 -> V_25 . V_624 & V_625 ) >> 1 ) |
( ( V_84 -> V_25 . V_624 & V_626 ) << 1 ) ;
V_622 |= V_84 -> V_25 . V_85 ;
V_623 = V_84 -> V_25 . V_627 ;
} else {
V_622 = V_628 | F_259 () |
F_260 ( V_84 -> V_25 . V_629 ) | V_630 ;
V_623 = V_631 | V_84 -> V_25 . V_627 ;
}
F_261 ( V_84 -> V_25 . V_632 , V_622 , V_623 ) ;
}
static int F_231 ( struct V_1 * V_6 )
{
int V_108 = 0 ;
struct V_84 * V_84 = V_6 -> V_84 ;
unsigned long V_633 ;
struct V_605 * V_606 ;
struct V_634 * V_635 ;
unsigned long V_83 = 0 , V_636 ;
unsigned long V_637 , V_638 ;
int V_495 ;
F_39 ( & V_84 -> V_59 ) ;
if ( V_84 -> V_25 . V_567 )
goto V_416;
if ( ! V_84 -> V_25 . V_639 . V_640 ) {
int V_641 = V_642 ;
struct V_643 V_594 ;
V_108 = F_262 ( & V_594 , V_641 ) ;
while ( ( V_108 == - V_388 ) && -- V_641 >= V_644 )
V_108 = F_262 ( & V_594 , V_641 ) ;
if ( V_108 < 0 ) {
F_36 ( L_22 ) ;
goto V_416;
}
F_263 ( V_84 , & V_594 ) ;
}
V_495 = F_69 ( & V_84 -> V_181 ) ;
V_606 = F_264 ( V_84 , 0 ) ;
V_108 = - V_58 ;
if ( ! V_606 || ( V_606 -> V_27 & V_645 ) )
goto V_646;
V_633 = V_606 -> V_647 ;
F_265 ( & V_545 -> V_574 -> V_648 ) ;
V_635 = F_266 ( V_545 -> V_574 , V_633 ) ;
if ( ! V_635 || V_635 -> V_649 > V_633 || ( V_635 -> V_650 & V_651 ) )
goto V_652;
V_637 = F_267 ( V_635 ) ;
V_638 = F_268 ( V_637 ) ;
F_269 ( & V_545 -> V_574 -> V_648 ) ;
V_108 = - V_58 ;
if ( ! ( V_637 == 0x1000 || V_637 == 0x10000 ||
V_637 == 0x1000000 ) )
goto V_646;
V_636 = F_270 ( V_637 ) ;
V_84 -> V_25 . V_624 = V_636 | V_653 |
( V_654 << V_655 ) ;
F_271 ( V_6 , V_606 , V_638 ) ;
if ( ! F_5 ( V_12 ) ) {
V_83 = V_636 << ( V_656 - 4 ) ;
F_256 ( V_84 , V_83 , V_657 ) ;
} else {
F_258 ( V_84 ) ;
}
F_60 () ;
V_84 -> V_25 . V_567 = 1 ;
V_108 = 0 ;
V_646:
F_71 ( & V_84 -> V_181 , V_495 ) ;
V_416:
F_41 ( & V_84 -> V_59 ) ;
return V_108 ;
V_652:
F_269 ( & V_545 -> V_574 -> V_648 ) ;
goto V_646;
}
void F_272 ( void )
{
struct V_658 * V_659 ;
unsigned long V_660 ;
int V_9 , V_379 ;
int V_661 ;
if ( V_490 != NULL )
return;
V_659 = F_104 ( sizeof( struct V_658 ) , V_380 ) ;
if ( ! V_659 )
return;
V_661 = F_273 () * sizeof( struct V_662 ) ;
V_659 -> V_492 = F_104 ( V_661 , V_380 ) ;
if ( ! V_659 -> V_492 ) {
F_113 ( V_659 ) ;
return;
}
F_274 () ;
for ( V_9 = 0 ; V_9 < V_16 ; V_9 += V_455 ) {
if ( ! F_20 ( V_9 ) )
continue;
V_379 = V_9 >> V_491 ;
V_659 -> V_492 [ V_379 ] . V_493 . V_494 = 1 ;
}
V_659 -> V_663 = F_16 ;
F_60 () ;
V_660 = ( unsigned long ) V_659 ;
if ( F_275 ( ( unsigned long * ) & V_490 , 0 , V_660 ) ) {
F_276 () ;
F_113 ( V_659 -> V_492 ) ;
F_113 ( V_659 ) ;
return;
}
F_277 ( V_664 ,
L_23 ,
F_189 ,
F_188 ) ;
F_276 () ;
}
void F_278 ( void )
{
if ( V_490 ) {
F_279 ( V_664 ) ;
F_113 ( V_490 -> V_492 ) ;
F_113 ( V_490 ) ;
V_490 = NULL ;
}
}
static int F_280 ( struct V_84 * V_84 )
{
unsigned long V_83 , V_632 ;
char V_390 [ 32 ] ;
int V_88 ;
V_632 = F_281 () ;
if ( ( long ) V_632 < 0 )
return - V_388 ;
V_84 -> V_25 . V_632 = V_632 ;
F_272 () ;
if ( ! F_5 ( V_12 ) )
F_282 ( & V_84 -> V_25 . V_454 ) ;
memcpy ( V_84 -> V_25 . V_171 , V_665 ,
sizeof( V_84 -> V_25 . V_171 ) ) ;
if ( ! F_5 ( V_12 ) )
V_84 -> V_25 . V_666 = F_129 ( V_667 ) ;
V_84 -> V_25 . V_668 = F_129 ( V_669 ) ;
V_84 -> V_25 . V_670 = V_83 = F_129 ( V_671 ) ;
V_83 &= V_672 | V_673 ;
V_83 |= ( 4UL << V_674 ) | V_675 |
V_676 | V_677 ;
V_84 -> V_25 . V_624 = V_653 |
( V_654 << V_655 ) ;
if ( F_5 ( V_13 ) )
V_83 |= V_678 ;
if ( F_5 ( V_12 ) ) {
V_83 &= ~ V_676 ;
V_83 |= V_679 | V_680 ;
if ( F_75 () )
V_83 |= V_673 ;
}
if ( F_241 () ) {
V_84 -> V_25 . V_681 = 1 ;
V_83 &= ~ V_677 ;
V_83 |= V_682 | V_683 | V_684 ;
V_88 = F_283 ( V_84 ) ;
if ( V_88 ) {
F_284 ( V_84 -> V_25 . V_632 ) ;
return V_88 ;
}
F_258 ( V_84 ) ;
}
V_84 -> V_25 . V_83 = V_83 ;
V_84 -> V_25 . V_685 = NULL ;
if ( F_155 ( V_84 ) )
V_84 -> V_25 . V_686 = V_687 ;
else if ( F_5 ( V_12 ) )
V_84 -> V_25 . V_686 = V_688 ;
else if ( F_5 ( V_13 ) )
V_84 -> V_25 . V_686 = V_689 ;
else
V_84 -> V_25 . V_686 = V_690 ;
if ( ! F_5 ( V_12 ) )
F_285 () ;
snprintf ( V_390 , sizeof( V_390 ) , L_24 , V_545 -> V_314 ) ;
V_84 -> V_25 . V_412 = F_122 ( V_390 , V_691 ) ;
if ( ! F_121 ( V_84 -> V_25 . V_412 ) )
F_286 ( V_84 ) ;
return 0 ;
}
static void F_287 ( struct V_84 * V_84 )
{
long int V_5 ;
for ( V_5 = 0 ; V_5 < V_415 ; ++ V_5 )
F_113 ( V_84 -> V_25 . V_429 [ V_5 ] ) ;
V_84 -> V_25 . V_430 = 0 ;
}
static void F_288 ( struct V_84 * V_84 )
{
F_289 ( V_84 -> V_25 . V_412 ) ;
if ( ! F_5 ( V_12 ) )
F_290 () ;
F_287 ( V_84 ) ;
F_284 ( V_84 -> V_25 . V_632 ) ;
if ( F_155 ( V_84 ) )
F_291 ( V_84 ) ;
else
F_292 ( & V_84 -> V_25 . V_639 ) ;
F_293 ( V_84 ) ;
}
static int F_294 ( struct V_199 * V_200 , struct V_1 * V_6 ,
unsigned int V_692 , int * V_693 )
{
return V_694 ;
}
static int F_295 ( struct V_1 * V_6 , int V_695 ,
T_3 V_696 )
{
return V_694 ;
}
static int F_296 ( struct V_1 * V_6 , int V_695 ,
T_3 * V_696 )
{
return V_694 ;
}
static int F_297 ( void )
{
if ( ! F_5 ( V_697 ) ||
! F_5 ( V_50 ) )
return - V_698 ;
return 0 ;
}
void F_293 ( struct V_84 * V_84 )
{
F_113 ( V_84 -> V_25 . V_699 ) ;
}
static struct V_700 * F_298 ( void )
{
return F_104 ( sizeof( struct V_700 ) , V_380 ) ;
}
static int F_299 ( struct V_84 * V_84 , int V_701 , int V_702 )
{
struct V_703 * V_704 ;
struct V_705 * V_706 ;
struct V_700 * V_699 ;
struct V_707 * V_708 ;
int V_5 , V_169 = 0 ;
if ( ! V_709 )
return 1 ;
V_704 = F_300 ( V_701 ) ;
if ( ! V_704 )
return - V_698 ;
F_39 ( & V_84 -> V_59 ) ;
V_699 = V_84 -> V_25 . V_699 ;
if ( V_699 == NULL ) {
V_699 = F_298 () ;
if ( V_699 == NULL ) {
F_41 ( & V_84 -> V_59 ) ;
return - V_388 ;
}
V_84 -> V_25 . V_699 = V_699 ;
}
V_708 = F_301 ( & V_704 -> V_710 ) ;
if ( ! V_708 || ! ( F_302 ( V_708 ) || F_303 ( V_708 ) ) ) {
F_304 ( L_25 ,
V_701 , V_702 ) ;
F_41 ( & V_84 -> V_59 ) ;
return - V_182 ;
}
for ( V_5 = 0 ; V_5 < V_699 -> V_711 ; V_5 ++ ) {
if ( V_702 == V_699 -> V_712 [ V_5 ] . V_713 ) {
if ( V_699 -> V_712 [ V_5 ] . V_714 ) {
F_41 ( & V_84 -> V_59 ) ;
return - V_58 ;
}
break;
}
}
if ( V_5 == V_715 ) {
F_41 ( & V_84 -> V_59 ) ;
return - V_716 ;
}
V_706 = & V_699 -> V_712 [ V_5 ] ;
V_706 -> V_713 = V_702 ;
V_706 -> V_704 = V_704 ;
F_60 () ;
V_706 -> V_714 = V_704 -> V_710 . V_717 ;
if ( V_5 == V_699 -> V_711 )
V_699 -> V_711 ++ ;
if ( F_75 () )
V_169 = F_305 ( V_84 , V_702 , V_704 ) ;
else
F_306 ( V_84 , V_702 , V_704 -> V_710 . V_717 ) ;
if ( V_169 )
V_706 -> V_714 = 0 ;
F_41 ( & V_84 -> V_59 ) ;
return 0 ;
}
static int F_307 ( struct V_84 * V_84 , int V_701 , int V_702 )
{
struct V_703 * V_704 ;
struct V_700 * V_699 ;
int V_5 , V_169 = 0 ;
if ( ! V_709 )
return 0 ;
V_704 = F_300 ( V_701 ) ;
if ( ! V_704 )
return - V_698 ;
F_39 ( & V_84 -> V_59 ) ;
if ( ! V_84 -> V_25 . V_699 )
goto V_718;
V_699 = V_84 -> V_25 . V_699 ;
for ( V_5 = 0 ; V_5 < V_699 -> V_711 ; V_5 ++ ) {
if ( V_702 == V_699 -> V_712 [ V_5 ] . V_713 )
break;
}
if ( V_5 == V_699 -> V_711 ) {
F_41 ( & V_84 -> V_59 ) ;
return - V_719 ;
}
if ( F_75 () )
V_169 = F_308 ( V_84 , V_702 , V_699 -> V_712 [ V_5 ] . V_704 ) ;
else
F_309 ( V_84 , V_702 , V_699 -> V_712 [ V_5 ] . V_714 ) ;
V_699 -> V_712 [ V_5 ] . V_714 = 0 ;
V_718:
F_41 ( & V_84 -> V_59 ) ;
return V_169 ;
}
static int F_310 ( struct V_720 * V_721 ,
struct V_722 * V_723 )
{
int V_88 = 0 ;
struct V_724 * V_725 =
F_311 ( V_721 , struct V_724 , V_726 ) ;
V_725 -> V_727 = V_723 ;
V_88 = F_299 ( V_725 -> V_84 , V_723 -> V_728 , V_725 -> V_729 ) ;
if ( V_88 )
F_312 ( L_26 ,
V_723 -> V_728 , V_725 -> V_729 , V_88 ) ;
return V_88 ;
}
static void F_313 ( struct V_720 * V_721 ,
struct V_722 * V_723 )
{
int V_88 ;
struct V_724 * V_725 =
F_311 ( V_721 , struct V_724 , V_726 ) ;
V_725 -> V_727 = NULL ;
V_88 = F_307 ( V_725 -> V_84 , V_723 -> V_728 , V_725 -> V_729 ) ;
if ( V_88 )
F_304 ( L_27 ,
V_723 -> V_728 , V_725 -> V_729 , V_88 ) ;
}
static long F_314 ( struct V_385 * V_730 ,
unsigned int V_731 , unsigned long V_732 )
{
struct V_84 * V_84 V_733 = V_730 -> V_389 ;
void T_5 * V_734 = ( void T_5 * ) V_732 ;
long V_61 ;
switch ( V_731 ) {
case V_735 : {
T_2 V_736 ;
V_61 = - V_410 ;
if ( F_315 ( V_736 , ( T_2 T_5 * ) V_734 ) )
break;
V_61 = F_316 ( V_84 , V_736 ) ;
if ( V_61 )
break;
V_61 = 0 ;
break;
}
case V_737 : {
struct V_738 V_739 ;
V_61 = - V_410 ;
if ( F_317 ( & V_739 , V_734 , sizeof( V_739 ) ) )
break;
V_61 = F_318 ( V_84 , & V_739 ) ;
break;
}
case V_740 : {
struct V_741 V_742 ;
V_61 = - V_410 ;
if ( F_317 ( & V_742 , V_734 , sizeof( V_742 ) ) )
break;
V_61 = F_319 ( V_84 , & V_742 ) ;
break;
}
case V_743 : {
struct V_741 V_742 ;
V_61 = - V_410 ;
if ( F_317 ( & V_742 , V_734 , sizeof( V_742 ) ) )
break;
V_61 = F_320 ( V_84 , & V_742 ) ;
break;
}
default:
V_61 = - V_744 ;
}
return V_61 ;
}
static void F_321 ( void )
{
int V_5 ;
unsigned int V_745 ;
for ( V_5 = 0 ; V_746 [ V_5 ] ; ++ V_5 ) {
V_745 = V_746 [ V_5 ] ;
F_236 ( ! F_81 ( V_745 ) ) ;
F_322 ( V_745 / 4 , V_665 ) ;
}
}
static int F_323 ( struct V_84 * V_84 , struct V_747 * V_748 )
{
unsigned long V_83 ;
int V_681 ;
if ( ! F_5 ( V_12 ) )
return - V_719 ;
if ( V_748 -> V_27 & ~ ( V_749 | V_750 ) )
return - V_58 ;
V_681 = ! ! ( V_748 -> V_27 & V_749 ) ;
if ( V_681 != F_155 ( V_84 ) )
return - V_58 ;
if ( ! ! ( V_748 -> V_627 & V_631 ) != V_681 )
return - V_58 ;
if ( ( V_748 -> V_627 & V_751 ) > 24 )
return - V_58 ;
V_84 -> V_25 . V_627 = V_748 -> V_627 ;
F_258 ( V_84 ) ;
V_83 = ( V_748 -> V_27 & V_750 ) ? V_683 : 0 ;
F_256 ( V_84 , V_83 , V_683 ) ;
return 0 ;
}
static int F_324 ( void )
{
int V_5 , V_251 ;
int V_752 = F_273 () ;
struct V_753 * V_753 ;
for ( V_5 = 0 ; V_5 < V_752 ; V_5 ++ ) {
int V_754 = V_5 * V_455 ;
int V_755 = F_325 ( V_754 ) ;
if ( V_17 [ V_754 ] . V_753 )
continue;
V_753 =
F_326 ( sizeof( struct V_753 ) ,
V_380 , V_755 ) ;
if ( ! V_753 )
return - V_388 ;
memset ( V_753 , 0 ,
sizeof( struct V_753 ) ) ;
for ( V_251 = 0 ; V_251 < V_455 ; V_251 ++ ) {
int V_9 = V_754 + V_251 ;
V_17 [ V_9 ] . V_753 = V_753 ;
}
}
return 0 ;
}
static int F_327 ( void )
{
return F_5 ( V_12 ) && F_241 () ;
}
static int F_328 ( void )
{
int V_61 ;
V_61 = F_297 () ;
if ( V_61 < 0 )
return - V_719 ;
V_61 = F_324 () ;
if ( V_61 )
return V_61 ;
#ifdef V_15
if ( ! F_75 () && ! V_756 -> V_18 . V_19 ) {
struct V_757 * V_758 ;
V_758 = F_329 ( NULL , NULL , L_28 ) ;
if ( ! V_758 ) {
F_36 ( L_29 ) ;
return - V_719 ;
}
}
#endif
V_759 . V_760 = V_761 ;
V_762 = & V_759 ;
F_321 () ;
F_161 () ;
V_61 = F_330 () ;
if ( V_61 )
return V_61 ;
if ( F_327 () )
V_61 = F_331 () ;
return V_61 ;
}
static void F_332 ( void )
{
F_278 () ;
if ( F_327 () )
F_333 () ;
V_762 = NULL ;
}
