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
unsigned long V_27 ;
V_135 = V_6 -> V_25 . V_130 ;
V_90 = V_6 -> V_25 . V_90 . V_103 ;
V_132 = F_24 () ;
V_137 = F_53 ( V_3 , V_132 ) ;
V_136 = V_137 - V_6 -> V_25 . V_138 ;
V_6 -> V_25 . V_138 = V_137 ;
F_23 ( & V_6 -> V_25 . V_36 , V_27 ) ;
V_136 += V_6 -> V_25 . V_40 ;
V_6 -> V_25 . V_40 = 0 ;
F_25 ( & V_6 -> V_25 . V_36 , V_27 ) ;
if ( ! V_135 || ! V_90 )
return;
memset ( V_135 , 0 , sizeof( struct V_120 ) ) ;
V_135 -> V_139 = 7 ;
V_135 -> V_140 = F_55 ( V_3 -> V_141 + V_6 -> V_25 . V_142 ) ;
V_135 -> V_143 = F_56 ( V_132 + V_3 -> V_144 ) ;
V_135 -> V_145 = F_43 ( V_136 ) ;
V_135 -> V_67 = F_56 ( F_57 ( V_6 ) ) ;
V_135 -> V_68 = F_56 ( V_6 -> V_25 . V_43 . V_41 ) ;
++ V_135 ;
if ( V_135 == V_6 -> V_25 . V_122 . V_129 )
V_135 = V_6 -> V_25 . V_122 . V_103 ;
V_6 -> V_25 . V_130 = V_135 ;
F_58 () ;
V_90 -> V_146 = F_56 ( ++ V_6 -> V_25 . V_131 ) ;
V_6 -> V_25 . V_122 . V_128 = true ;
}
static bool F_59 ( struct V_1 * V_6 )
{
int V_147 ;
struct V_2 * V_3 ;
if ( V_6 -> V_25 . V_148 )
return true ;
F_60 () ;
V_3 = V_6 -> V_25 . V_32 ;
V_147 = V_6 -> V_62 - V_3 -> V_149 ;
return ! ! ( V_3 -> V_150 & ( 1 << V_147 ) ) ;
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
static int F_62 ( struct V_1 * V_6 , unsigned long V_151 ,
unsigned long V_152 , unsigned long V_153 ,
unsigned long V_154 )
{
switch ( V_152 ) {
case V_155 :
if ( ! F_61 ( V_6 ) )
return V_156 ;
if ( V_154 )
return V_157 ;
if ( V_151 )
return V_158 ;
if ( ( V_153 & V_159 ) == V_160 )
return V_161 ;
V_6 -> V_25 . V_162 = V_153 ;
return V_163 ;
case V_164 :
if ( ! F_61 ( V_6 ) )
return V_156 ;
if ( V_151 )
return V_158 ;
if ( V_154 & V_165 )
return V_157 ;
V_6 -> V_25 . V_166 = V_153 ;
V_6 -> V_25 . V_167 = V_154 ;
return V_163 ;
default:
return V_168 ;
}
}
static int F_63 ( struct V_1 * V_169 )
{
struct V_2 * V_32 = V_169 -> V_25 . V_32 ;
F_33 ( & V_32 -> V_59 ) ;
if ( V_169 -> V_25 . V_37 == V_170 &&
V_32 -> V_34 != V_134 &&
V_32 -> V_33 )
V_169 = V_32 -> V_33 ;
F_34 ( & V_32 -> V_59 ) ;
return F_64 ( V_169 ) ;
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
unsigned long V_171 = F_37 ( V_6 , 3 ) ;
unsigned long V_169 , V_88 = V_163 ;
int V_93 ;
struct V_1 * V_107 ;
int V_172 , V_173 ;
if ( V_171 <= V_174 &&
! F_67 ( V_171 / 4 , V_6 -> V_84 -> V_25 . V_175 ) )
return V_176 ;
switch ( V_171 ) {
case V_177 :
break;
case V_178 :
V_169 = F_37 ( V_6 , 4 ) ;
V_107 = F_38 ( V_6 -> V_84 , V_169 ) ;
if ( ! V_107 ) {
V_88 = V_110 ;
break;
}
V_107 -> V_25 . V_179 = 1 ;
F_7 () ;
if ( V_107 -> V_25 . V_180 )
F_16 ( V_107 ) ;
break;
case V_181 :
V_169 = F_37 ( V_6 , 4 ) ;
if ( V_169 == - 1 )
break;
V_107 = F_38 ( V_6 -> V_84 , V_169 ) ;
if ( ! V_107 ) {
V_88 = V_110 ;
break;
}
V_93 = F_37 ( V_6 , 5 ) ;
if ( F_65 ( V_107 ) != V_93 )
break;
F_63 ( V_107 ) ;
break;
case V_182 :
V_88 = F_46 ( V_6 , F_37 ( V_6 , 4 ) ,
F_37 ( V_6 , 5 ) ,
F_37 ( V_6 , 6 ) ) ;
break;
case V_183 :
if ( F_68 ( & V_6 -> V_84 -> V_25 . V_184 ) )
return V_176 ;
V_172 = F_69 ( & V_6 -> V_84 -> V_185 ) ;
V_173 = F_70 ( V_6 ) ;
F_71 ( & V_6 -> V_84 -> V_185 , V_172 ) ;
if ( V_173 == - V_186 )
return V_176 ;
else if ( V_173 == 0 )
break;
return V_173 ;
case V_187 :
V_88 = F_72 ( V_6 ) ;
if ( V_88 == V_168 )
return V_176 ;
break;
case V_188 :
V_88 = F_73 ( V_6 ) ;
if ( V_88 == V_168 )
return V_176 ;
break;
case V_189 :
V_88 = F_62 ( V_6 , F_37 ( V_6 , 4 ) ,
F_37 ( V_6 , 5 ) ,
F_37 ( V_6 , 6 ) ,
F_37 ( V_6 , 7 ) ) ;
if ( V_88 == V_168 )
return V_176 ;
break;
case V_190 :
case V_191 :
case V_192 :
case V_193 :
case V_194 :
case V_195 :
if ( F_74 ( V_6 ) ) {
if ( F_75 () ) {
V_88 = V_196 ;
return V_197 ;
}
V_88 = F_76 ( V_6 , V_171 ) ;
break;
}
return V_176 ;
case V_198 :
V_88 = F_77 ( V_6 , F_37 ( V_6 , 4 ) ,
F_37 ( V_6 , 5 ) ,
F_37 ( V_6 , 6 ) ) ;
if ( V_88 == V_168 )
return V_176 ;
break;
case V_199 :
V_88 = F_78 ( V_6 , F_37 ( V_6 , 4 ) ,
F_37 ( V_6 , 5 ) ,
F_37 ( V_6 , 6 ) ,
F_37 ( V_6 , 7 ) ) ;
if ( V_88 == V_168 )
return V_176 ;
break;
case V_200 :
V_88 = F_79 ( V_6 , F_37 ( V_6 , 4 ) ,
F_37 ( V_6 , 5 ) ,
F_37 ( V_6 , 6 ) ,
F_37 ( V_6 , 7 ) ) ;
if ( V_88 == V_168 )
return V_176 ;
break;
default:
return V_176 ;
}
F_80 ( V_6 , 3 , V_88 ) ;
V_6 -> V_25 . V_201 = 0 ;
return V_197 ;
}
static int F_81 ( unsigned long V_202 )
{
switch ( V_202 ) {
case V_177 :
case V_178 :
case V_181 :
case V_182 :
case V_189 :
case V_187 :
case V_188 :
#ifdef F_82
case V_190 :
case V_191 :
case V_192 :
case V_193 :
case V_194 :
case V_195 :
#endif
return 1 ;
}
return F_83 ( V_202 ) ;
}
static int F_84 ( struct V_203 * V_204 ,
struct V_1 * V_6 )
{
T_2 V_86 ;
if ( F_85 ( V_6 , V_205 , & V_86 ) !=
V_206 ) {
return V_197 ;
}
if ( V_86 == V_207 ) {
V_204 -> V_208 = V_209 ;
V_204 -> V_210 . V_25 . V_211 = F_57 ( V_6 ) ;
return V_176 ;
} else {
F_86 ( V_6 , V_212 ) ;
return V_197 ;
}
}
static void F_87 ( void * V_213 )
{
}
static unsigned long F_88 ( struct V_1 * V_6 )
{
int V_147 , V_9 , V_141 , V_214 ;
struct V_1 * V_95 ;
unsigned long V_150 ;
V_214 = V_6 -> V_84 -> V_25 . V_215 ;
V_150 = 0 ;
V_9 = V_6 -> V_62 & ~ ( V_214 - 1 ) ;
for ( V_147 = 0 ; V_147 < V_214 ; ++ V_147 , ++ V_9 ) {
V_95 = F_38 ( V_6 -> V_84 , V_9 ) ;
if ( ! V_95 )
continue;
V_141 = F_2 ( V_95 -> V_9 ) ;
if ( V_141 >= 0 )
F_89 ( V_141 , F_87 , NULL , 1 ) ;
if ( F_59 ( V_95 ) )
V_150 |= 1 << V_147 ;
}
return V_150 ;
}
static int F_90 ( struct V_1 * V_6 )
{
T_2 V_216 , V_217 , V_147 ;
unsigned long V_218 ;
struct V_84 * V_84 = V_6 -> V_84 ;
struct V_1 * V_107 ;
if ( ! F_5 ( V_12 ) )
return V_219 ;
if ( F_85 ( V_6 , V_205 , & V_216 ) != V_206 )
return V_197 ;
if ( F_91 ( V_216 ) != 31 )
return V_219 ;
V_217 = F_92 ( V_216 ) ;
V_147 = V_6 -> V_62 & ( V_84 -> V_25 . V_215 - 1 ) ;
switch ( F_93 ( V_216 ) ) {
case V_220 :
V_218 = F_37 ( V_6 , V_217 ) ;
if ( ( ( V_218 >> 27 ) & 0xf ) != V_11 )
break;
V_218 &= 0x3f ;
if ( V_218 >= V_84 -> V_25 . V_215 )
break;
V_107 = F_38 ( V_84 , V_6 -> V_62 - V_147 + V_218 ) ;
if ( ! V_107 )
break;
if ( ! V_107 -> V_25 . V_148 ) {
V_107 -> V_25 . V_148 = 1 ;
F_16 ( V_107 ) ;
}
break;
case V_221 :
V_218 = F_37 ( V_6 , V_217 ) ;
if ( ( ( V_218 >> 27 ) & 0xf ) != V_11 )
break;
V_6 -> V_25 . V_32 -> V_150 = 0 ;
V_6 -> V_25 . V_148 = 0 ;
break;
case V_222 :
switch ( F_94 ( V_216 ) ) {
case V_223 :
V_218 = V_147 ;
break;
case V_224 :
V_218 = F_88 ( V_6 ) ;
break;
default:
return V_219 ;
}
F_80 ( V_6 , F_95 ( V_216 ) , V_218 ) ;
break;
default:
return V_219 ;
}
F_96 ( V_6 , F_57 ( V_6 ) + 4 ) ;
return V_197 ;
}
static int F_97 ( struct V_203 * V_204 , struct V_1 * V_6 ,
struct V_225 * V_226 )
{
int V_61 = V_176 ;
V_6 -> V_23 . V_227 ++ ;
if ( V_6 -> V_25 . V_43 . V_41 & V_228 ) {
F_98 ( V_229 L_14 ) ;
F_98 ( V_229 L_15 ,
V_6 -> V_25 . V_64 , F_57 ( V_6 ) ,
V_6 -> V_25 . V_43 . V_41 ) ;
F_35 ( V_6 ) ;
V_204 -> V_208 = V_230 ;
V_204 -> V_231 . V_232 = V_6 -> V_25 . V_64 ;
return V_176 ;
}
V_204 -> V_208 = V_233 ;
V_204 -> V_234 = 1 ;
switch ( V_6 -> V_25 . V_64 ) {
case V_235 :
V_6 -> V_23 . V_236 ++ ;
V_61 = V_197 ;
break;
case V_237 :
case V_238 :
case V_239 :
V_6 -> V_23 . V_240 ++ ;
V_61 = V_197 ;
break;
case V_241 :
case V_242 :
V_61 = V_197 ;
break;
case V_243 :
V_204 -> V_208 = V_244 ;
V_204 -> V_231 . V_232 = V_6 -> V_25 . V_64 ;
V_204 -> V_27 &= ~ V_245 ;
if ( V_6 -> V_25 . V_246 . V_247 == V_248 )
V_204 -> V_27 |= V_249 ;
else
V_204 -> V_27 |= V_250 ;
V_61 = V_176 ;
F_99 ( & V_6 -> V_25 . V_246 , false ) ;
break;
case V_251 :
{
T_3 V_27 ;
V_27 = V_6 -> V_25 . V_43 . V_41 & 0x1f0000ull ;
F_86 ( V_6 , V_27 ) ;
V_61 = V_197 ;
break;
}
case V_252 :
{
int V_5 ;
V_204 -> V_253 . V_254 = F_37 ( V_6 , 3 ) ;
for ( V_5 = 0 ; V_5 < 9 ; ++ V_5 )
V_204 -> V_253 . args [ V_5 ] = F_37 ( V_6 , 4 + V_5 ) ;
V_204 -> V_208 = V_255 ;
V_6 -> V_25 . V_201 = 1 ;
V_61 = V_176 ;
break;
}
case V_256 :
V_61 = V_257 ;
break;
case V_258 :
V_6 -> V_25 . V_77 = F_57 ( V_6 ) ;
V_6 -> V_25 . V_78 = 0 ;
V_61 = V_257 ;
break;
case V_259 :
if ( V_6 -> V_25 . V_260 != V_261 )
V_6 -> V_25 . V_86 = F_100 ( V_6 ) ?
F_101 ( V_6 -> V_25 . V_260 ) :
V_6 -> V_25 . V_260 ;
if ( V_6 -> V_262 & V_263 ) {
V_61 = F_84 ( V_204 , V_6 ) ;
} else {
F_86 ( V_6 , V_212 ) ;
V_61 = V_197 ;
}
break;
case V_264 :
V_61 = V_219 ;
if ( ( V_6 -> V_25 . V_265 >> 56 ) == V_266 )
V_61 = F_90 ( V_6 ) ;
if ( V_61 == V_219 ) {
F_86 ( V_6 , V_212 ) ;
V_61 = V_197 ;
}
break;
case V_267 :
V_61 = V_268 ;
break;
default:
F_35 ( V_6 ) ;
F_98 ( V_229 L_15 ,
V_6 -> V_25 . V_64 , F_57 ( V_6 ) ,
V_6 -> V_25 . V_43 . V_41 ) ;
V_204 -> V_231 . V_232 = V_6 -> V_25 . V_64 ;
V_61 = V_176 ;
break;
}
return V_61 ;
}
static int F_102 ( struct V_1 * V_6 ,
struct V_269 * V_270 )
{
int V_5 ;
memset ( V_270 , 0 , sizeof( struct V_269 ) ) ;
V_270 -> V_44 = V_6 -> V_25 . V_44 ;
for ( V_5 = 0 ; V_5 < V_6 -> V_25 . V_79 ; V_5 ++ ) {
V_270 -> V_271 . V_272 . V_273 . V_80 [ V_5 ] . V_274 = V_6 -> V_25 . V_80 [ V_5 ] . V_81 ;
V_270 -> V_271 . V_272 . V_273 . V_80 [ V_5 ] . V_275 = V_6 -> V_25 . V_80 [ V_5 ] . V_82 ;
}
return 0 ;
}
static int F_103 ( struct V_1 * V_6 ,
struct V_269 * V_270 )
{
int V_5 , V_276 ;
if ( V_270 -> V_44 != V_6 -> V_25 . V_44 )
return - V_58 ;
V_276 = 0 ;
for ( V_5 = 0 ; V_5 < V_6 -> V_25 . V_277 ; V_5 ++ ) {
if ( V_270 -> V_271 . V_272 . V_273 . V_80 [ V_5 ] . V_274 & V_278 ) {
V_6 -> V_25 . V_80 [ V_276 ] . V_81 = V_270 -> V_271 . V_272 . V_273 . V_80 [ V_5 ] . V_274 ;
V_6 -> V_25 . V_80 [ V_276 ] . V_82 = V_270 -> V_271 . V_272 . V_273 . V_80 [ V_5 ] . V_275 ;
++ V_276 ;
}
}
V_6 -> V_25 . V_79 = V_276 ;
return 0 ;
}
static void F_104 ( struct V_1 * V_6 , T_1 V_279 ,
bool V_280 )
{
struct V_84 * V_84 = V_6 -> V_84 ;
struct V_2 * V_3 = V_6 -> V_25 . V_32 ;
T_1 V_281 ;
F_39 ( & V_84 -> V_59 ) ;
F_33 ( & V_3 -> V_59 ) ;
if ( ( V_279 & V_282 ) != ( V_3 -> V_83 & V_282 ) ) {
struct V_1 * V_6 ;
int V_5 ;
F_105 (i, vcpu, kvm) {
if ( V_6 -> V_25 . V_32 != V_3 )
continue;
if ( V_279 & V_282 )
V_6 -> V_25 . V_283 |= V_284 ;
else
V_6 -> V_25 . V_283 &= ~ V_284 ;
}
}
V_281 = V_285 | V_282 | V_286 ;
if ( F_5 ( V_13 ) )
V_281 |= V_287 ;
if ( F_5 ( V_12 ) )
V_281 |= V_288 ;
if ( V_280 )
V_281 &= 0xFFFFFFFF ;
V_3 -> V_83 = ( V_3 -> V_83 & ~ V_281 ) | ( V_279 & V_281 ) ;
F_34 ( & V_3 -> V_59 ) ;
F_41 ( & V_84 -> V_59 ) ;
}
static int F_106 ( struct V_1 * V_6 , T_1 V_87 ,
union V_289 * V_290 )
{
int V_61 = 0 ;
long int V_5 ;
switch ( V_87 ) {
case V_291 :
* V_290 = F_107 ( V_87 , V_207 ) ;
break;
case V_292 :
* V_290 = F_107 ( V_87 , 0 ) ;
break;
case V_293 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_294 ) ;
break;
case V_295 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_296 ) ;
break;
case V_297 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_298 ) ;
break;
case V_299 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_300 ) ;
break;
case V_301 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_302 ) ;
break;
case V_303 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_304 ) ;
break;
case V_305 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_306 ) ;
break;
case V_307 ... V_308 :
V_5 = V_87 - V_307 ;
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_309 [ V_5 ] ) ;
break;
case V_310 ... V_311 :
V_5 = V_87 - V_310 ;
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_312 [ V_5 ] ) ;
break;
case V_313 ... V_314 :
V_5 = V_87 - V_313 ;
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_315 [ V_5 ] ) ;
break;
case V_316 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_317 ) ;
break;
case V_318 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_319 ) ;
break;
case V_320 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_321 ) ;
break;
case V_322 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_323 ) ;
break;
case V_324 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_325 ) ;
break;
case V_326 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_32 -> V_150 ) ;
break;
case V_327 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_32 -> V_328 ) ;
break;
case V_329 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_166 ) ;
break;
case V_330 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_167 ) ;
break;
case V_331 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_162 ) ;
break;
case V_332 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_333 ) ;
break;
case V_334 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_335 ) ;
break;
case V_336 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_337 ) ;
break;
case V_338 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_339 ) ;
break;
case V_340 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_341 ) ;
break;
case V_342 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_343 ) ;
break;
case V_344 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_345 ) ;
break;
case V_346 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_347 ) ;
break;
case V_348 :
F_33 ( & V_6 -> V_25 . V_99 ) ;
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_90 . V_100 ) ;
F_34 ( & V_6 -> V_25 . V_99 ) ;
break;
case V_349 :
F_33 ( & V_6 -> V_25 . V_99 ) ;
V_290 -> V_350 . V_96 = V_6 -> V_25 . V_123 . V_100 ;
V_290 -> V_350 . V_117 = V_6 -> V_25 . V_123 . V_97 ;
F_34 ( & V_6 -> V_25 . V_99 ) ;
break;
case V_351 :
F_33 ( & V_6 -> V_25 . V_99 ) ;
V_290 -> V_350 . V_96 = V_6 -> V_25 . V_122 . V_100 ;
V_290 -> V_350 . V_117 = V_6 -> V_25 . V_122 . V_97 ;
F_34 ( & V_6 -> V_25 . V_99 ) ;
break;
case V_352 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_32 -> V_144 ) ;
break;
case V_353 :
case V_354 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_32 -> V_83 ) ;
break;
case V_355 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_356 ) ;
break;
#ifdef F_108
case V_357 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_358 ) ;
break;
case V_359 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_360 ) ;
break;
case V_361 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_362 ) ;
break;
case V_363 ... V_364 :
V_5 = V_87 - V_363 ;
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_365 [ V_5 ] ) ;
break;
case V_366 ... V_367 :
{
int V_276 ;
V_5 = V_87 - V_366 ;
if ( V_5 < 32 )
for ( V_276 = 0 ; V_276 < V_368 ; V_276 ++ )
V_290 -> V_369 [ V_276 ] = V_6 -> V_25 . V_370 . V_371 [ V_5 ] [ V_276 ] ;
else {
if ( F_5 ( V_372 ) )
V_290 -> V_373 = V_6 -> V_25 . V_374 . V_375 [ V_5 - 32 ] ;
else
V_61 = - V_376 ;
}
break;
}
case V_377 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_378 ) ;
break;
case V_379 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_380 ) ;
break;
case V_381 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_382 ) ;
break;
case V_383 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_384 ) ;
break;
case V_385 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_370 . V_386 ) ;
break;
case V_387 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_388 ) ;
break;
case V_389 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_390 ) ;
break;
case V_391 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_392 ) ;
break;
case V_393 :
if ( F_5 ( V_372 ) )
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_374 . V_394 . V_271 [ 3 ] ) ;
else
V_61 = - V_376 ;
break;
case V_395 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_396 ) ;
break;
case V_397 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_398 ) ;
break;
#endif
case V_399 :
* V_290 = F_107 ( V_87 , V_6 -> V_25 . V_32 -> V_45 ) ;
break;
default:
V_61 = - V_58 ;
break;
}
return V_61 ;
}
static int F_109 ( struct V_1 * V_6 , T_1 V_87 ,
union V_289 * V_290 )
{
int V_61 = 0 ;
long int V_5 ;
unsigned long V_96 , V_97 ;
switch ( V_87 ) {
case V_292 :
if ( F_110 ( V_87 , * V_290 ) )
V_61 = - V_58 ;
break;
case V_293 :
V_6 -> V_25 . V_294 = F_110 ( V_87 , * V_290 ) ;
break;
case V_295 :
V_6 -> V_25 . V_296 = F_110 ( V_87 , * V_290 ) & ~ V_165 ;
break;
case V_297 :
V_6 -> V_25 . V_298 = F_110 ( V_87 , * V_290 ) ;
break;
case V_299 :
V_6 -> V_25 . V_300 = F_110 ( V_87 , * V_290 ) ;
break;
case V_301 :
V_6 -> V_25 . V_302 = F_110 ( V_87 , * V_290 ) ;
break;
case V_303 :
V_6 -> V_25 . V_304 = F_110 ( V_87 , * V_290 ) ;
break;
case V_305 :
V_6 -> V_25 . V_306 = F_110 ( V_87 , * V_290 ) ;
break;
case V_307 ... V_308 :
V_5 = V_87 - V_307 ;
V_6 -> V_25 . V_309 [ V_5 ] = F_110 ( V_87 , * V_290 ) ;
break;
case V_310 ... V_311 :
V_5 = V_87 - V_310 ;
V_6 -> V_25 . V_312 [ V_5 ] = F_110 ( V_87 , * V_290 ) ;
break;
case V_313 ... V_314 :
V_5 = V_87 - V_313 ;
V_6 -> V_25 . V_315 [ V_5 ] = F_110 ( V_87 , * V_290 ) ;
break;
case V_316 :
V_6 -> V_25 . V_317 = F_110 ( V_87 , * V_290 ) ;
break;
case V_318 :
V_6 -> V_25 . V_319 = F_110 ( V_87 , * V_290 ) ;
break;
case V_320 :
V_6 -> V_25 . V_321 = F_110 ( V_87 , * V_290 ) ;
break;
case V_322 :
V_6 -> V_25 . V_323 = F_110 ( V_87 , * V_290 ) ;
break;
case V_324 :
V_6 -> V_25 . V_325 = F_110 ( V_87 , * V_290 ) ;
break;
case V_326 :
V_6 -> V_25 . V_32 -> V_150 = F_110 ( V_87 , * V_290 ) ;
break;
case V_327 :
V_6 -> V_25 . V_32 -> V_328 = F_110 ( V_87 , * V_290 ) ;
break;
case V_329 :
V_6 -> V_25 . V_166 = F_110 ( V_87 , * V_290 ) ;
break;
case V_330 :
V_6 -> V_25 . V_167 = F_110 ( V_87 , * V_290 ) & ~ V_400 ;
break;
case V_331 :
V_6 -> V_25 . V_162 = F_110 ( V_87 , * V_290 ) ;
if ( ( V_6 -> V_25 . V_162 & V_159 ) == V_160 )
V_6 -> V_25 . V_162 &= ~ V_159 ;
break;
case V_332 :
V_6 -> V_25 . V_333 = F_110 ( V_87 , * V_290 ) ;
break;
case V_334 :
V_6 -> V_25 . V_335 = F_110 ( V_87 , * V_290 ) ;
break;
case V_336 :
V_6 -> V_25 . V_337 = F_110 ( V_87 , * V_290 ) ;
break;
case V_338 :
V_6 -> V_25 . V_339 = F_110 ( V_87 , * V_290 ) ;
break;
case V_340 :
V_6 -> V_25 . V_341 = F_110 ( V_87 , * V_290 ) ;
break;
case V_342 :
V_6 -> V_25 . V_343 = F_110 ( V_87 , * V_290 ) ;
break;
case V_344 :
V_6 -> V_25 . V_345 = F_110 ( V_87 , * V_290 ) ;
break;
case V_346 :
V_6 -> V_25 . V_347 = F_110 ( V_87 , * V_290 ) & V_401 ;
break;
case V_348 :
V_96 = F_110 ( V_87 , * V_290 ) ;
V_61 = - V_58 ;
if ( ! V_96 && ( V_6 -> V_25 . V_123 . V_100 ||
V_6 -> V_25 . V_122 . V_100 ) )
break;
V_61 = F_44 ( V_6 , & V_6 -> V_25 . V_90 , V_96 , sizeof( struct V_89 ) ) ;
break;
case V_349 :
V_96 = V_290 -> V_350 . V_96 ;
V_97 = V_290 -> V_350 . V_117 ;
V_61 = - V_58 ;
if ( V_96 && ! V_6 -> V_25 . V_90 . V_100 )
break;
V_61 = F_44 ( V_6 , & V_6 -> V_25 . V_123 , V_96 , V_97 ) ;
break;
case V_351 :
V_96 = V_290 -> V_350 . V_96 ;
V_97 = V_290 -> V_350 . V_117 ;
V_61 = - V_58 ;
if ( V_96 && ( V_97 < sizeof( struct V_120 ) ||
! V_6 -> V_25 . V_90 . V_100 ) )
break;
V_97 -= V_97 % sizeof( struct V_120 ) ;
V_61 = F_44 ( V_6 , & V_6 -> V_25 . V_122 , V_96 , V_97 ) ;
break;
case V_352 :
if ( F_5 ( V_402 ) )
break;
V_6 -> V_25 . V_32 -> V_144 =
F_111 ( F_110 ( V_87 , * V_290 ) , 1UL << 24 ) ;
break;
case V_353 :
F_104 ( V_6 , F_110 ( V_87 , * V_290 ) , true ) ;
break;
case V_354 :
F_104 ( V_6 , F_110 ( V_87 , * V_290 ) , false ) ;
break;
case V_355 :
V_6 -> V_25 . V_356 = F_110 ( V_87 , * V_290 ) ;
break;
#ifdef F_108
case V_357 :
V_6 -> V_25 . V_358 = F_110 ( V_87 , * V_290 ) ;
break;
case V_359 :
V_6 -> V_25 . V_360 = F_110 ( V_87 , * V_290 ) ;
break;
case V_361 :
V_6 -> V_25 . V_362 = F_110 ( V_87 , * V_290 ) ;
break;
case V_363 ... V_364 :
V_5 = V_87 - V_363 ;
V_6 -> V_25 . V_365 [ V_5 ] = F_110 ( V_87 , * V_290 ) ;
break;
case V_366 ... V_367 :
{
int V_276 ;
V_5 = V_87 - V_366 ;
if ( V_5 < 32 )
for ( V_276 = 0 ; V_276 < V_368 ; V_276 ++ )
V_6 -> V_25 . V_370 . V_371 [ V_5 ] [ V_276 ] = V_290 -> V_369 [ V_276 ] ;
else
if ( F_5 ( V_372 ) )
V_6 -> V_25 . V_374 . V_375 [ V_5 - 32 ] = V_290 -> V_373 ;
else
V_61 = - V_376 ;
break;
}
case V_377 :
V_6 -> V_25 . V_378 = F_110 ( V_87 , * V_290 ) ;
break;
case V_379 :
V_6 -> V_25 . V_380 = F_110 ( V_87 , * V_290 ) ;
break;
case V_381 :
V_6 -> V_25 . V_382 = F_110 ( V_87 , * V_290 ) ;
break;
case V_383 :
V_6 -> V_25 . V_384 = F_110 ( V_87 , * V_290 ) ;
break;
case V_385 :
V_6 -> V_25 . V_370 . V_386 = F_110 ( V_87 , * V_290 ) ;
break;
case V_387 :
V_6 -> V_25 . V_388 = F_110 ( V_87 , * V_290 ) ;
break;
case V_389 :
V_6 -> V_25 . V_390 = F_110 ( V_87 , * V_290 ) ;
break;
case V_391 :
V_6 -> V_25 . V_392 = F_110 ( V_87 , * V_290 ) ;
break;
case V_393 :
if ( F_5 ( V_372 ) )
V_6 -> V_25 . V_375 . V_394 . V_271 [ 3 ] = F_110 ( V_87 , * V_290 ) ;
else
V_61 = - V_376 ;
break;
case V_395 :
V_6 -> V_25 . V_396 = F_110 ( V_87 , * V_290 ) ;
break;
case V_397 :
V_6 -> V_25 . V_398 = F_110 ( V_87 , * V_290 ) ;
break;
#endif
case V_399 :
V_61 = F_32 ( V_6 , F_110 ( V_87 , * V_290 ) ) ;
break;
default:
V_61 = - V_58 ;
break;
}
return V_61 ;
}
static int F_112 ( void )
{
if ( F_5 ( V_12 ) )
return 1 ;
return V_403 ;
}
static struct V_2 * F_113 ( struct V_84 * V_84 , int V_404 )
{
struct V_2 * V_32 ;
V_32 = F_114 ( sizeof( struct V_2 ) , V_405 ) ;
if ( V_32 == NULL )
return NULL ;
F_115 ( & V_32 -> V_59 ) ;
F_115 ( & V_32 -> V_28 ) ;
F_116 ( & V_32 -> V_406 ) ;
V_32 -> V_29 = V_30 ;
V_32 -> V_83 = V_84 -> V_25 . V_83 ;
V_32 -> V_149 = V_404 * V_84 -> V_25 . V_407 ;
V_32 -> V_84 = V_84 ;
F_117 ( & V_32 -> V_408 ) ;
return V_32 ;
}
static int F_118 ( struct V_409 * V_409 , struct V_410 * V_410 )
{
struct V_1 * V_6 = V_409 -> V_411 ;
struct V_412 * V_133 ;
V_133 = F_114 ( sizeof( * V_133 ) , V_405 ) ;
if ( ! V_133 )
return - V_413 ;
F_119 ( V_6 -> V_84 ) ;
V_133 -> V_6 = V_6 ;
V_410 -> V_414 = V_133 ;
return F_120 ( V_409 , V_410 ) ;
}
static int F_121 ( struct V_409 * V_409 , struct V_410 * V_410 )
{
struct V_412 * V_133 = V_410 -> V_414 ;
F_122 ( V_133 -> V_6 -> V_84 ) ;
F_123 ( V_133 ) ;
return 0 ;
}
static T_4 F_124 ( struct V_410 * V_410 , char T_5 * V_415 ,
T_6 V_97 , T_7 * V_416 )
{
struct V_412 * V_133 = V_410 -> V_414 ;
struct V_1 * V_6 = V_133 -> V_6 ;
char * V_272 , * V_417 ;
struct V_418 V_419 ;
T_1 V_420 ;
T_7 V_421 ;
T_4 V_422 ;
int V_5 , V_423 ;
bool V_424 ;
if ( ! V_133 -> V_425 ) {
V_272 = V_133 -> V_415 ;
V_417 = V_272 + sizeof( V_133 -> V_415 ) ;
for ( V_5 = 0 ; V_5 < V_426 ; ++ V_5 ) {
struct V_418 * V_427 ;
V_427 = (struct V_418 * )
( ( unsigned long ) V_6 + V_428 [ V_5 ] . V_429 ) ;
V_424 = false ;
for ( V_423 = 0 ; V_423 < 1000 ; ++ V_423 ) {
V_420 = V_427 -> V_430 ;
if ( ! ( V_420 & 1 ) ) {
F_60 () ;
V_419 = * V_427 ;
F_60 () ;
if ( V_420 == V_427 -> V_430 ) {
V_424 = true ;
break;
}
}
F_125 ( 1 ) ;
}
if ( ! V_424 )
snprintf ( V_272 , V_417 - V_272 , L_16 ,
V_428 [ V_5 ] . V_431 ) ;
else
snprintf ( V_272 , V_417 - V_272 ,
L_17 ,
V_428 [ V_5 ] . V_431 , V_420 / 2 ,
F_126 ( V_419 . V_432 ) ,
F_126 ( V_419 . V_433 ) ,
F_126 ( V_419 . V_434 ) ) ;
V_272 += strlen ( V_272 ) ;
}
V_133 -> V_425 = V_272 - V_133 -> V_415 ;
}
V_421 = * V_416 ;
if ( V_421 >= V_133 -> V_425 )
return 0 ;
if ( V_97 > V_133 -> V_425 - V_421 )
V_97 = V_133 -> V_425 - V_421 ;
V_422 = F_127 ( V_415 , V_133 -> V_415 + V_421 , V_97 ) ;
if ( V_422 ) {
if ( V_422 == V_97 )
return - V_435 ;
V_97 -= V_422 ;
}
* V_416 = V_421 + V_97 ;
return V_97 ;
}
static T_4 F_128 ( struct V_410 * V_410 , const char T_5 * V_415 ,
T_6 V_97 , T_7 * V_416 )
{
return - V_436 ;
}
static void F_129 ( struct V_1 * V_6 , unsigned int V_87 )
{
char V_415 [ 16 ] ;
struct V_84 * V_84 = V_6 -> V_84 ;
snprintf ( V_415 , sizeof( V_415 ) , L_18 , V_87 ) ;
if ( F_130 ( V_84 -> V_25 . V_437 ) )
return;
V_6 -> V_25 . V_437 = F_131 ( V_415 , V_84 -> V_25 . V_437 ) ;
if ( F_130 ( V_6 -> V_25 . V_437 ) )
return;
V_6 -> V_25 . V_438 =
F_132 ( L_19 , 0444 , V_6 -> V_25 . V_437 ,
V_6 , & V_439 ) ;
}
static void F_129 ( struct V_1 * V_6 , unsigned int V_87 )
{
}
static struct V_1 * F_133 ( struct V_84 * V_84 ,
unsigned int V_87 )
{
struct V_1 * V_6 ;
int V_108 ;
int V_404 ;
struct V_2 * V_32 ;
V_108 = - V_413 ;
V_6 = F_134 ( V_440 , V_405 ) ;
if ( ! V_6 )
goto V_441;
V_108 = F_135 ( V_6 , V_84 , V_87 ) ;
if ( V_108 )
goto V_442;
V_6 -> V_25 . V_443 = & V_6 -> V_25 . V_43 ;
#ifdef F_136
#ifdef F_137
V_6 -> V_25 . V_444 = true ;
#else
V_6 -> V_25 . V_444 = false ;
#endif
#endif
V_6 -> V_25 . V_309 [ 0 ] = V_445 ;
V_6 -> V_25 . V_446 = V_447 ;
F_31 ( V_6 , F_138 ( V_448 ) ) ;
F_115 ( & V_6 -> V_25 . V_99 ) ;
F_115 ( & V_6 -> V_25 . V_36 ) ;
V_6 -> V_25 . V_39 = V_30 ;
V_6 -> V_25 . V_283 = V_449 | V_450 ;
V_6 -> V_25 . V_265 = F_138 ( V_451 ) ;
if ( ! F_5 ( V_452 ) )
V_6 -> V_25 . V_265 &= ~ V_453 ;
if ( F_5 ( V_12 ) )
V_6 -> V_25 . V_265 &= ~ V_454 ;
F_139 ( V_6 ) ;
V_6 -> V_25 . V_37 = V_455 ;
F_140 ( & V_6 -> V_25 . V_456 ) ;
F_39 ( & V_84 -> V_59 ) ;
V_32 = NULL ;
V_108 = - V_58 ;
V_404 = V_87 / V_84 -> V_25 . V_407 ;
if ( V_404 < V_457 ) {
V_32 = V_84 -> V_25 . V_458 [ V_404 ] ;
if ( ! V_32 ) {
V_108 = - V_413 ;
V_32 = F_113 ( V_84 , V_404 ) ;
V_84 -> V_25 . V_458 [ V_404 ] = V_32 ;
V_84 -> V_25 . V_459 ++ ;
}
}
F_41 ( & V_84 -> V_59 ) ;
if ( ! V_32 )
goto V_442;
F_33 ( & V_32 -> V_59 ) ;
++ V_32 -> V_460 ;
F_34 ( & V_32 -> V_59 ) ;
V_6 -> V_25 . V_32 = V_32 ;
V_6 -> V_25 . V_142 = V_6 -> V_62 - V_32 -> V_149 ;
V_6 -> V_25 . V_26 = - 1 ;
V_6 -> V_25 . V_461 = - 1 ;
V_6 -> V_25 . V_462 = V_463 ;
F_141 ( V_6 ) ;
F_129 ( V_6 , V_87 ) ;
return V_6 ;
V_442:
F_142 ( V_440 , V_6 ) ;
V_441:
return F_143 ( V_108 ) ;
}
static int F_144 ( struct V_84 * V_84 , unsigned long V_407 ,
unsigned long V_27 )
{
int V_108 ;
int V_464 = 0 ;
if ( V_27 )
return - V_58 ;
if ( V_407 > V_7 || ! F_145 ( V_407 ) )
return - V_58 ;
if ( ! F_5 ( V_12 ) ) {
if ( V_407 > V_403 )
return - V_58 ;
} else {
V_464 = V_407 ;
V_407 = 1 ;
}
F_39 ( & V_84 -> V_59 ) ;
V_108 = - V_465 ;
if ( ! V_84 -> V_25 . V_459 ) {
V_84 -> V_25 . V_407 = V_407 ;
V_84 -> V_25 . V_215 = V_464 ;
V_108 = 0 ;
}
F_41 ( & V_84 -> V_59 ) ;
return V_108 ;
}
static void F_146 ( struct V_84 * V_84 , struct V_94 * V_90 )
{
if ( V_90 -> V_103 )
F_50 ( V_84 , V_90 -> V_103 , V_90 -> V_127 ,
V_90 -> V_128 ) ;
}
static void F_147 ( struct V_1 * V_6 )
{
F_33 ( & V_6 -> V_25 . V_99 ) ;
F_146 ( V_6 -> V_84 , & V_6 -> V_25 . V_122 ) ;
F_146 ( V_6 -> V_84 , & V_6 -> V_25 . V_123 ) ;
F_146 ( V_6 -> V_84 , & V_6 -> V_25 . V_90 ) ;
F_34 ( & V_6 -> V_25 . V_99 ) ;
F_148 ( V_6 ) ;
F_142 ( V_440 , V_6 ) ;
}
static int F_149 ( struct V_1 * V_6 )
{
return 1 ;
}
static void F_150 ( struct V_1 * V_6 )
{
unsigned long V_466 , V_132 ;
V_132 = F_151 () ;
if ( V_132 > V_6 -> V_25 . V_467 ) {
F_152 ( V_6 ) ;
F_153 ( V_6 ) ;
return;
}
V_466 = ( V_6 -> V_25 . V_467 - V_132 ) * V_468
/ V_469 ;
F_154 ( & V_6 -> V_25 . V_470 , V_466 , V_471 ) ;
V_6 -> V_25 . V_472 = 1 ;
}
static void F_30 ( struct V_1 * V_6 )
{
V_6 -> V_25 . V_180 = 0 ;
if ( V_6 -> V_25 . V_472 ) {
F_155 ( & V_6 -> V_25 . V_470 ) ;
V_6 -> V_25 . V_472 = 0 ;
}
}
static void F_156 ( struct V_2 * V_3 ,
struct V_1 * V_6 )
{
T_1 V_132 ;
if ( V_6 -> V_25 . V_37 != V_170 )
return;
F_157 ( & V_6 -> V_25 . V_36 ) ;
V_132 = F_24 () ;
V_6 -> V_25 . V_40 += F_53 ( V_3 , V_132 ) -
V_6 -> V_25 . V_138 ;
V_6 -> V_25 . V_39 = V_132 ;
V_6 -> V_25 . V_37 = V_38 ;
F_158 ( & V_6 -> V_25 . V_36 ) ;
-- V_3 -> V_473 ;
F_159 ( V_3 -> V_8 [ V_6 -> V_25 . V_142 ] , NULL ) ;
}
static int F_160 ( int V_9 )
{
struct V_474 * V_475 ;
long V_476 = 10000 ;
V_475 = & V_17 [ V_9 ] ;
V_475 -> V_18 . V_1 = NULL ;
V_475 -> V_18 . V_477 = NULL ;
V_475 -> V_18 . V_478 = 0 ;
F_58 () ;
V_475 -> V_18 . V_479 = 1 ;
F_7 () ;
while ( V_475 -> V_18 . V_480 == V_481 ) {
if ( -- V_476 <= 0 ) {
F_36 ( L_20 , V_9 ) ;
return - V_465 ;
}
F_125 ( 1 ) ;
}
return 0 ;
}
static void F_161 ( int V_9 )
{
struct V_474 * V_475 ;
V_475 = & V_17 [ V_9 ] ;
V_475 -> V_18 . V_479 = 0 ;
V_475 -> V_18 . V_1 = NULL ;
V_475 -> V_18 . V_477 = NULL ;
V_475 -> V_18 . V_482 = NULL ;
}
static void F_162 ( struct V_84 * V_84 , int V_9 , struct V_1 * V_6 )
{
int V_5 ;
V_9 = F_9 ( V_9 ) ;
F_163 ( V_9 , & V_84 -> V_25 . V_483 ) ;
F_7 () ;
for ( V_5 = 0 ; V_5 < V_484 ; ++ V_5 )
if ( F_164 ( V_9 + V_5 , & V_84 -> V_25 . V_485 ) )
F_89 ( V_9 + V_5 , F_87 , NULL , 1 ) ;
}
static void F_165 ( struct V_1 * V_6 , int V_141 )
{
struct V_84 * V_84 = V_6 -> V_84 ;
if ( V_6 -> V_25 . V_461 != V_141 ) {
if ( V_6 -> V_25 . V_461 >= 0 &&
F_9 ( V_6 -> V_25 . V_461 ) !=
F_9 ( V_141 ) )
F_162 ( V_84 , V_6 -> V_25 . V_461 , V_6 ) ;
V_6 -> V_25 . V_461 = V_141 ;
}
}
static void F_166 ( struct V_1 * V_6 , struct V_2 * V_3 )
{
int V_9 ;
struct V_474 * V_475 ;
struct V_84 * V_84 = V_3 -> V_84 ;
V_9 = V_3 -> V_141 ;
if ( V_6 ) {
if ( V_6 -> V_25 . V_472 ) {
F_155 ( & V_6 -> V_25 . V_470 ) ;
V_6 -> V_25 . V_472 = 0 ;
}
V_9 += V_6 -> V_25 . V_142 ;
V_6 -> V_9 = V_3 -> V_141 ;
V_6 -> V_25 . V_26 = V_9 ;
F_163 ( V_9 , & V_84 -> V_25 . V_485 ) ;
}
V_475 = & V_17 [ V_9 ] ;
V_475 -> V_18 . V_1 = V_6 ;
V_475 -> V_18 . V_142 = V_9 - V_3 -> V_141 ;
F_58 () ;
V_475 -> V_18 . V_477 = V_3 ;
if ( V_9 != F_10 () )
F_3 ( V_9 ) ;
}
static void F_167 ( void )
{
int V_9 = F_10 () ;
int V_5 , V_423 ;
int V_486 = F_112 () ;
if ( V_486 <= 1 )
return;
for ( V_423 = 0 ; V_423 < 1000000 ; ++ V_423 ) {
for ( V_5 = 1 ; V_5 < V_486 ; ++ V_5 )
if ( V_17 [ V_9 + V_5 ] . V_18 . V_477 )
break;
if ( V_5 == V_486 ) {
F_168 () ;
return;
}
F_169 () ;
}
F_168 () ;
for ( V_5 = 1 ; V_5 < V_486 ; ++ V_5 )
if ( V_17 [ V_9 + V_5 ] . V_18 . V_477 )
F_36 ( L_21 , V_9 + V_5 ) ;
}
static int F_170 ( void )
{
int V_9 = F_10 () ;
int V_147 ;
if ( F_171 ( V_9 ) )
return 0 ;
V_147 = 0 ;
while ( ++ V_147 < V_403 )
if ( F_20 ( V_9 + V_147 ) )
return 0 ;
for ( V_147 = 1 ; V_147 < V_403 ; ++ V_147 ) {
if ( F_160 ( V_9 + V_147 ) ) {
do {
F_161 ( V_9 + V_147 ) ;
} while ( -- V_147 > 0 );
return 0 ;
}
}
return 1 ;
}
static void F_172 ( void )
{
int V_9 ;
F_173 (cpu) {
struct V_487 * V_488 = & F_174 ( V_489 , V_9 ) ;
F_115 ( & V_488 -> V_59 ) ;
F_117 ( & V_488 -> V_490 ) ;
}
}
static void F_175 ( struct V_2 * V_3 )
{
struct V_487 * V_488 = F_176 ( & V_489 ) ;
V_3 -> V_34 = V_491 ;
V_3 -> V_141 = F_10 () ;
if ( V_3 -> V_460 < F_112 () ) {
F_33 ( & V_488 -> V_59 ) ;
F_177 ( & V_3 -> V_408 , & V_488 -> V_490 ) ;
F_34 ( & V_488 -> V_59 ) ;
}
F_22 ( V_3 ) ;
}
static void F_178 ( struct V_2 * V_3 )
{
struct V_487 * V_488 ;
F_26 ( V_3 ) ;
if ( ! F_68 ( & V_3 -> V_408 ) ) {
V_488 = & F_174 ( V_489 , V_3 -> V_141 ) ;
F_33 ( & V_488 -> V_59 ) ;
F_179 ( & V_3 -> V_408 ) ;
F_34 ( & V_488 -> V_59 ) ;
}
V_3 -> V_34 = V_134 ;
}
static void F_180 ( struct V_492 * V_493 , struct V_2 * V_3 )
{
memset ( V_493 , 0 , sizeof( * V_493 ) ) ;
V_493 -> V_494 = 1 ;
V_493 -> V_495 = V_3 -> V_460 ;
V_493 -> V_496 = V_3 -> V_460 ;
V_493 -> V_497 [ 0 ] = V_3 -> V_460 ;
V_493 -> V_3 [ 0 ] = V_3 ;
}
static bool F_181 ( int V_494 , int V_486 )
{
if ( V_494 > 1 && V_403 < V_7 )
return false ;
if ( V_494 > V_498 )
return false ;
if ( V_494 > 1 ) {
if ( ! ( V_499 & 2 ) )
V_494 = 4 ;
if ( V_494 > 2 && ! ( V_499 & 4 ) )
return false ;
}
return V_494 * F_182 ( V_486 ) <= V_7 ;
}
static void F_183 ( struct V_2 * V_3 )
{
V_3 -> V_500 = 0 ;
V_3 -> V_501 = 0 ;
V_3 -> V_502 = 0 ;
V_3 -> V_503 = 0 ;
}
static bool F_184 ( struct V_2 * V_3 , struct V_492 * V_493 )
{
int V_486 = V_3 -> V_460 ;
int V_504 ;
if ( ! F_5 ( V_13 ) )
return false ;
if ( V_486 < V_493 -> V_495 )
V_486 = V_493 -> V_495 ;
if ( ! F_181 ( V_493 -> V_494 + 1 , V_486 ) )
return false ;
V_493 -> V_495 = V_486 ;
V_504 = V_493 -> V_494 ;
++ V_493 -> V_494 ;
V_493 -> V_496 += V_3 -> V_460 ;
V_493 -> V_497 [ V_504 ] = V_3 -> V_460 ;
V_493 -> V_3 [ V_504 ] = V_3 ;
F_183 ( V_3 ) ;
F_179 ( & V_3 -> V_408 ) ;
return true ;
}
static bool F_185 ( struct V_2 * V_505 , struct V_492 * V_493 ,
int V_506 )
{
if ( V_493 -> V_496 + V_505 -> V_460 > V_506 )
return false ;
return F_184 ( V_505 , V_493 ) ;
}
static void F_186 ( struct V_2 * V_3 )
{
int V_5 ;
struct V_1 * V_6 ;
F_187 (i, vcpu, vc) {
if ( F_188 ( V_6 -> V_25 . V_507 ) )
V_6 -> V_25 . V_88 = - V_508 ;
else if ( V_6 -> V_25 . V_90 . V_101 ||
V_6 -> V_25 . V_123 . V_101 ||
V_6 -> V_25 . V_122 . V_101 )
V_6 -> V_25 . V_88 = V_197 ;
else
continue;
F_156 ( V_3 , V_6 ) ;
F_189 ( & V_6 -> V_25 . V_456 ) ;
}
}
static void F_190 ( struct V_492 * V_493 , int V_506 )
{
struct V_487 * V_488 = F_176 ( & V_489 ) ;
struct V_2 * V_505 , * V_509 ;
F_33 ( & V_488 -> V_59 ) ;
F_191 (pvc, vcnext, &lp->list, preempt_list) {
if ( ! F_192 ( & V_505 -> V_59 ) )
continue;
F_186 ( V_505 ) ;
if ( ! V_505 -> V_473 ) {
F_179 ( & V_505 -> V_408 ) ;
if ( V_505 -> V_33 == NULL ) {
V_505 -> V_34 = V_134 ;
F_26 ( V_505 ) ;
}
F_34 ( & V_505 -> V_59 ) ;
continue;
}
if ( ! F_185 ( V_505 , V_493 , V_506 ) ) {
F_34 ( & V_505 -> V_59 ) ;
continue;
}
F_26 ( V_505 ) ;
V_505 -> V_34 = V_510 ;
if ( V_493 -> V_496 >= V_506 )
break;
}
F_34 ( & V_488 -> V_59 ) ;
}
static bool F_193 ( struct V_492 * V_493 )
{
int V_504 , V_5 ;
struct V_1 * V_6 ;
for ( V_504 = 0 ; V_504 < V_493 -> V_494 ; ++ V_504 )
F_187 (i, vcpu, cip->vc[sub])
if ( F_188 ( V_6 -> V_25 . V_507 ) )
return true ;
return false ;
}
static void F_194 ( struct V_2 * V_3 , bool V_511 )
{
int V_512 = 0 , V_5 ;
T_1 V_132 ;
long V_88 ;
struct V_1 * V_6 ;
F_33 ( & V_3 -> V_59 ) ;
V_132 = F_151 () ;
F_187 (i, vcpu, vc) {
if ( V_132 < V_6 -> V_25 . V_467 &&
F_195 ( V_6 ) )
F_196 ( V_6 ) ;
F_197 ( V_6 ) ;
V_88 = V_197 ;
if ( V_6 -> V_25 . V_64 )
V_88 = F_97 ( V_6 -> V_25 . V_203 , V_6 ,
V_6 -> V_25 . V_507 ) ;
V_6 -> V_25 . V_88 = V_88 ;
V_6 -> V_25 . V_64 = 0 ;
if ( F_198 ( V_6 -> V_25 . V_88 ) ) {
if ( V_6 -> V_25 . V_513 )
F_153 ( V_6 ) ;
if ( V_6 -> V_25 . V_180 )
F_150 ( V_6 ) ;
else
++ V_512 ;
} else {
F_156 ( V_3 , V_6 ) ;
F_189 ( & V_6 -> V_25 . V_456 ) ;
}
}
if ( ! V_511 ) {
if ( V_512 > 0 ) {
F_175 ( V_3 ) ;
} else if ( V_3 -> V_33 ) {
V_3 -> V_34 = V_491 ;
F_22 ( V_3 ) ;
} else {
V_3 -> V_34 = V_134 ;
}
if ( V_3 -> V_473 > 0 && V_3 -> V_33 == NULL ) {
V_5 = - 1 ;
V_6 = F_1 ( V_3 , & V_5 ) ;
F_189 ( & V_6 -> V_25 . V_456 ) ;
}
}
F_34 ( & V_3 -> V_59 ) ;
}
static inline int F_199 ( unsigned int V_9 )
{
int V_404 ;
if ( ! V_514 || F_11 ( V_9 ) )
return 0 ;
V_404 = V_9 >> V_515 ;
V_514 -> V_516 [ V_404 ] . V_517 . V_518 = 0 ;
return 0 ;
}
static inline int F_200 ( unsigned int V_9 )
{
int V_404 ;
if ( ! V_514 || F_11 ( V_9 ) )
return 0 ;
V_404 = V_9 >> V_515 ;
V_514 -> V_516 [ V_404 ] . V_517 . V_518 = 1 ;
return 0 ;
}
static void F_201 ( int V_64 )
{
switch ( V_64 ) {
case V_237 :
V_519 -> V_520 |= V_521 ;
break;
case V_238 :
V_519 -> V_520 |= V_522 ;
break;
case V_241 :
V_519 -> V_520 |= V_523 ;
break;
}
}
static T_8 void F_202 ( struct V_2 * V_3 )
{
struct V_1 * V_6 ;
int V_5 ;
int V_524 ;
struct V_492 V_492 ;
struct V_2 * V_505 ;
struct V_482 V_525 , * V_526 ;
int V_527 , V_528 , V_529 ;
int V_504 ;
bool V_530 ;
unsigned long V_531 , V_532 ;
int V_141 , V_147 ;
int V_506 ;
int V_533 ;
int V_64 ;
F_186 ( V_3 ) ;
if ( V_3 -> V_33 -> V_25 . V_37 != V_170 )
return;
F_183 ( V_3 ) ;
V_3 -> V_29 = V_30 ;
V_533 = F_112 () ;
if ( ( V_533 > 1 ) &&
( ( V_3 -> V_460 > V_403 ) || ! F_170 () ) ) {
F_187 (i, vcpu, vc) {
V_6 -> V_25 . V_88 = - V_465 ;
F_156 ( V_3 , V_6 ) ;
F_189 ( & V_6 -> V_25 . V_456 ) ;
}
goto V_441;
}
F_180 ( & V_492 , V_3 ) ;
V_141 = F_10 () ;
V_506 = V_533 ;
if ( V_534 && V_534 < V_506 )
V_506 = V_534 ;
if ( V_3 -> V_460 < V_506 )
F_190 ( & V_492 , V_506 ) ;
V_141 = F_10 () ;
if ( F_203 ( V_3 -> V_84 ) ) {
for ( V_504 = 0 ; V_504 < V_492 . V_494 ; ++ V_504 )
F_187 (i, vcpu, core_info.vc[sub])
F_165 ( V_6 , V_141 ) ;
}
F_204 () ;
F_205 () ;
if ( F_206 () || F_207 () ||
F_193 ( & V_492 ) ) {
F_208 () ;
V_3 -> V_34 = V_134 ;
for ( V_504 = 1 ; V_504 < V_492 . V_494 ; ++ V_504 ) {
V_505 = V_492 . V_3 [ V_504 ] ;
F_175 ( V_505 ) ;
F_34 ( & V_505 -> V_59 ) ;
}
for ( V_5 = 0 ; V_5 < V_533 ; ++ V_5 )
F_161 ( V_141 + V_5 ) ;
return;
}
F_199 ( V_141 ) ;
V_528 = V_403 ;
V_531 = V_532 = 0 ;
V_527 = V_492 . V_494 ;
V_526 = NULL ;
if ( V_527 > 1 ) {
if ( V_527 == 2 && ( V_499 & 2 ) ) {
V_531 = V_535 ;
V_532 = V_536 ;
} else {
V_527 = 4 ;
V_531 = V_537 ;
V_532 = V_538 ;
}
V_528 = V_7 / V_527 ;
V_526 = & V_525 ;
memset ( & V_525 , 0 , sizeof( V_525 ) ) ;
V_525 . V_539 = F_138 ( V_540 ) ;
V_525 . V_541 = F_138 ( V_542 ) ;
V_525 . V_543 = F_138 ( V_544 ) ;
V_525 . V_528 = V_528 ;
for ( V_504 = 0 ; V_504 < V_492 . V_494 ; ++ V_504 )
V_525 . V_3 [ V_504 ] = V_492 . V_3 [ V_504 ] ;
F_58 () ;
}
for ( V_147 = 0 ; V_147 < V_533 ; ++ V_147 )
V_17 [ V_141 + V_147 ] . V_18 . V_482 = V_526 ;
if ( V_531 ) {
unsigned long V_545 = F_138 ( V_546 ) ;
V_545 |= V_531 | V_547 ;
F_209 () ;
F_210 ( V_546 , V_545 ) ;
F_211 () ;
for (; ; ) {
V_545 = F_138 ( V_546 ) ;
if ( V_545 & V_532 )
break;
F_212 () ;
}
}
V_529 = 0 ;
for ( V_504 = 0 ; V_504 < V_492 . V_494 ; ++ V_504 ) {
V_147 = V_548 [ V_504 ] ;
V_530 = false ;
V_529 |= 1 << V_147 ;
V_505 = V_492 . V_3 [ V_504 ] ;
V_505 -> V_141 = V_141 + V_147 ;
F_187 (i, vcpu, pvc) {
F_166 ( V_6 , V_505 ) ;
F_54 ( V_6 , V_505 ) ;
F_213 ( V_6 ) ;
if ( ! V_6 -> V_25 . V_142 )
V_530 = true ;
V_529 |= 1 << ( V_147 + V_6 -> V_25 . V_142 ) ;
}
if ( ! V_530 )
F_166 ( NULL , V_505 ) ;
V_147 += V_505 -> V_460 ;
}
F_7 () ;
if ( V_531 )
V_525 . V_549 = 1 ;
if ( V_527 > 1 )
for ( V_147 = 1 ; V_147 < V_403 ; ++ V_147 )
if ( ! ( V_529 & ( 1 << V_147 ) ) )
F_3 ( V_141 + V_147 ) ;
V_3 -> V_34 = V_550 ;
F_8 () ;
F_214 ( V_3 , 0 ) ;
for ( V_504 = 0 ; V_504 < V_492 . V_494 ; ++ V_504 )
F_34 ( & V_492 . V_3 [ V_504 ] -> V_59 ) ;
F_215 () ;
F_216 () ;
V_524 = F_69 ( & V_3 -> V_84 -> V_185 ) ;
V_64 = F_217 () ;
F_71 ( & V_3 -> V_84 -> V_185 , V_524 ) ;
F_218 () ;
F_219 () ;
F_201 ( V_64 ) ;
F_33 ( & V_3 -> V_59 ) ;
V_3 -> V_34 = V_551 ;
F_167 () ;
if ( V_527 > 1 ) {
unsigned long V_545 = F_138 ( V_546 ) ;
unsigned long V_423 = 0 ;
V_545 &= ~ V_547 ;
V_532 = V_536 | V_538 ;
F_209 () ;
F_210 ( V_546 , V_545 ) ;
F_211 () ;
for (; ; ) {
V_545 = F_138 ( V_546 ) ;
if ( ! ( V_545 & V_532 ) )
break;
F_212 () ;
++ V_423 ;
}
V_525 . V_549 = 0 ;
}
F_200 ( V_141 ) ;
F_208 () ;
for ( V_5 = 0 ; V_5 < V_533 ; ++ V_5 ) {
F_161 ( V_141 + V_5 ) ;
if ( V_526 && V_526 -> V_552 [ V_5 ] )
F_3 ( V_141 + V_5 ) ;
F_220 ( V_141 + V_5 , & V_3 -> V_84 -> V_25 . V_485 ) ;
}
F_34 ( & V_3 -> V_59 ) ;
F_7 () ;
for ( V_504 = 0 ; V_504 < V_492 . V_494 ; ++ V_504 ) {
V_505 = V_492 . V_3 [ V_504 ] ;
F_194 ( V_505 , V_505 == V_3 ) ;
}
F_33 ( & V_3 -> V_59 ) ;
F_12 () ;
V_441:
V_3 -> V_34 = V_134 ;
F_214 ( V_3 , 1 ) ;
}
static void F_221 ( struct V_2 * V_3 ,
struct V_1 * V_6 , int V_553 )
{
F_222 ( V_554 ) ;
F_223 ( & V_6 -> V_25 . V_456 , & V_554 , V_553 ) ;
if ( V_6 -> V_25 . V_37 == V_170 ) {
F_34 ( & V_3 -> V_59 ) ;
F_224 () ;
F_33 ( & V_3 -> V_59 ) ;
}
F_225 ( & V_6 -> V_25 . V_456 , & V_554 ) ;
}
static void F_226 ( struct V_2 * V_3 )
{
if ( V_3 -> V_555 == 0 && V_556 )
V_3 -> V_555 = 10000 ;
else
V_3 -> V_555 *= V_556 ;
}
static void F_227 ( struct V_2 * V_3 )
{
if ( V_557 == 0 )
V_3 -> V_555 = 0 ;
else
V_3 -> V_555 /= V_557 ;
}
static inline bool F_228 ( struct V_1 * V_6 )
{
if ( ! F_75 () )
return false ;
return V_6 -> V_25 . V_558 . V_559 <
V_6 -> V_25 . V_558 . V_560 ;
}
static inline bool F_228 ( struct V_1 * V_6 )
{
return false ;
}
static bool F_229 ( struct V_1 * V_6 )
{
if ( V_6 -> V_25 . V_513 || V_6 -> V_25 . V_179 ||
F_59 ( V_6 ) || F_228 ( V_6 ) )
return true ;
return false ;
}
static int F_230 ( struct V_2 * V_3 )
{
struct V_1 * V_6 ;
int V_5 ;
F_187 (i, vcpu, vc) {
if ( ! V_6 -> V_25 . V_180 || F_229 ( V_6 ) )
return 1 ;
}
return 0 ;
}
static void F_231 ( struct V_2 * V_3 )
{
T_9 V_561 , V_562 , V_563 ;
int V_564 = 1 ;
T_1 V_565 ;
F_232 ( V_554 ) ;
V_561 = V_562 = F_233 () ;
if ( V_3 -> V_555 ) {
T_9 V_566 = F_234 ( V_562 , V_3 -> V_555 ) ;
++ V_3 -> V_33 -> V_23 . V_567 ;
V_3 -> V_34 = V_568 ;
F_34 ( & V_3 -> V_59 ) ;
do {
if ( F_230 ( V_3 ) ) {
V_564 = 0 ;
break;
}
V_561 = F_233 () ;
} while ( F_235 () && F_236 ( V_561 , V_566 ) );
F_33 ( & V_3 -> V_59 ) ;
V_3 -> V_34 = V_134 ;
if ( ! V_564 ) {
++ V_3 -> V_33 -> V_23 . V_569 ;
goto V_441;
}
}
F_237 ( & V_3 -> V_406 , & V_554 , V_570 ) ;
if ( F_230 ( V_3 ) ) {
F_238 ( & V_3 -> V_406 , & V_554 ) ;
V_564 = 0 ;
if ( V_3 -> V_555 )
++ V_3 -> V_33 -> V_23 . V_569 ;
goto V_441;
}
V_563 = F_233 () ;
V_3 -> V_34 = V_35 ;
F_239 ( V_3 , 0 ) ;
F_34 ( & V_3 -> V_59 ) ;
F_224 () ;
F_238 ( & V_3 -> V_406 , & V_554 ) ;
F_33 ( & V_3 -> V_59 ) ;
V_3 -> V_34 = V_134 ;
F_239 ( V_3 , 1 ) ;
++ V_3 -> V_33 -> V_23 . V_571 ;
V_561 = F_233 () ;
V_441:
V_565 = F_240 ( V_561 ) - F_240 ( V_562 ) ;
if ( V_564 ) {
V_3 -> V_33 -> V_23 . V_572 +=
F_240 ( V_561 ) - F_240 ( V_563 ) ;
if ( V_3 -> V_555 )
V_3 -> V_33 -> V_23 . V_573 +=
F_240 ( V_563 ) -
F_240 ( V_562 ) ;
} else {
if ( V_3 -> V_555 )
V_3 -> V_33 -> V_23 . V_574 +=
F_240 ( V_561 ) -
F_240 ( V_562 ) ;
}
if ( V_555 ) {
if ( V_565 <= V_3 -> V_555 )
;
else if ( V_3 -> V_555 && V_565 > V_555 )
F_227 ( V_3 ) ;
else if ( V_3 -> V_555 < V_555 &&
V_565 < V_555 )
F_226 ( V_3 ) ;
if ( V_3 -> V_555 > V_555 )
V_3 -> V_555 = V_555 ;
} else
V_3 -> V_555 = 0 ;
F_241 ( V_564 , V_565 ) ;
}
static int F_242 ( struct V_203 * V_203 , struct V_1 * V_6 )
{
int V_575 , V_5 ;
struct V_2 * V_3 ;
struct V_1 * V_95 ;
F_243 ( V_6 ) ;
V_203 -> V_208 = 0 ;
V_6 -> V_25 . V_88 = V_197 ;
V_6 -> V_25 . V_64 = 0 ;
F_52 ( V_6 ) ;
V_3 = V_6 -> V_25 . V_32 ;
F_33 ( & V_3 -> V_59 ) ;
V_6 -> V_25 . V_180 = 0 ;
V_6 -> V_25 . V_507 = V_576 ;
V_6 -> V_25 . V_203 = V_203 ;
V_6 -> V_25 . V_138 = F_53 ( V_3 , F_24 () ) ;
V_6 -> V_25 . V_37 = V_170 ;
V_6 -> V_25 . V_39 = V_30 ;
F_159 ( V_3 -> V_8 [ V_6 -> V_25 . V_142 ] , V_6 ) ;
++ V_3 -> V_473 ;
if ( ! F_188 ( V_576 ) ) {
if ( V_3 -> V_34 == V_510 ) {
if ( F_192 ( & V_3 -> V_59 ) ) {
if ( V_3 -> V_34 == V_550 &&
! F_244 ( V_3 ) ) {
F_54 ( V_6 , V_3 ) ;
F_166 ( V_6 , V_3 ) ;
F_213 ( V_6 ) ;
}
F_34 ( & V_3 -> V_59 ) ;
}
} else if ( V_3 -> V_34 == V_550 &&
! F_244 ( V_3 ) ) {
F_54 ( V_6 , V_3 ) ;
F_166 ( V_6 , V_3 ) ;
F_213 ( V_6 ) ;
} else if ( V_3 -> V_34 == V_35 ) {
F_19 ( & V_3 -> V_406 ) ;
}
}
while ( V_6 -> V_25 . V_37 == V_170 &&
! F_188 ( V_576 ) ) {
if ( V_3 -> V_34 == V_491 && V_3 -> V_33 == NULL )
F_178 ( V_3 ) ;
if ( V_3 -> V_34 != V_134 ) {
F_221 ( V_3 , V_6 , V_570 ) ;
continue;
}
F_187 (i, v, vc) {
F_153 ( V_95 ) ;
if ( F_188 ( V_95 -> V_25 . V_507 ) ) {
F_156 ( V_3 , V_95 ) ;
V_95 -> V_23 . V_577 ++ ;
V_95 -> V_25 . V_203 -> V_208 = V_578 ;
V_95 -> V_25 . V_88 = - V_508 ;
F_189 ( & V_95 -> V_25 . V_456 ) ;
}
}
if ( ! V_3 -> V_473 || V_6 -> V_25 . V_37 != V_170 )
break;
V_575 = 0 ;
F_187 (i, v, vc) {
if ( ! F_229 ( V_95 ) )
V_575 += V_95 -> V_25 . V_180 ;
else
V_95 -> V_25 . V_180 = 0 ;
}
V_3 -> V_33 = V_6 ;
if ( V_575 == V_3 -> V_473 ) {
F_231 ( V_3 ) ;
} else if ( F_207 () ) {
F_175 ( V_3 ) ;
F_245 ( & V_3 -> V_59 ) ;
if ( V_3 -> V_34 == V_491 )
F_178 ( V_3 ) ;
} else {
F_202 ( V_3 ) ;
}
V_3 -> V_33 = NULL ;
}
while ( V_6 -> V_25 . V_37 == V_170 &&
( V_3 -> V_34 == V_550 ||
V_3 -> V_34 == V_551 ||
V_3 -> V_34 == V_510 ) )
F_221 ( V_3 , V_6 , V_579 ) ;
if ( V_3 -> V_34 == V_491 && V_3 -> V_33 == NULL )
F_178 ( V_3 ) ;
if ( V_6 -> V_25 . V_37 == V_170 ) {
F_156 ( V_3 , V_6 ) ;
V_6 -> V_23 . V_577 ++ ;
V_203 -> V_208 = V_578 ;
V_6 -> V_25 . V_88 = - V_508 ;
}
if ( V_3 -> V_473 && V_3 -> V_34 == V_134 ) {
V_5 = - 1 ;
V_95 = F_1 ( V_3 , & V_5 ) ;
F_189 ( & V_95 -> V_25 . V_456 ) ;
}
F_246 ( V_6 , V_203 ) ;
F_34 ( & V_3 -> V_59 ) ;
return V_6 -> V_25 . V_88 ;
}
static int F_247 ( struct V_203 * V_204 , struct V_1 * V_6 )
{
int V_61 ;
int V_524 ;
unsigned long V_580 [ 3 ] = {} ;
unsigned long V_581 = 0 ;
unsigned int V_582 ;
if ( ! V_6 -> V_25 . V_583 ) {
V_204 -> V_208 = V_230 ;
return - V_58 ;
}
#ifdef F_108
if ( F_5 ( V_452 ) && V_576 -> V_584 . V_585 &&
( V_576 -> V_584 . V_585 -> V_41 & V_586 ) ) {
if ( F_248 ( V_576 -> V_584 . V_585 -> V_41 ) ) {
V_204 -> V_208 = V_587 ;
V_204 -> V_588 . V_589 = 0 ;
return - V_58 ;
}
F_249 ( F_250 () | V_586 ) ;
V_576 -> V_584 . V_590 = F_138 ( V_591 ) ;
V_576 -> V_584 . V_592 = F_138 ( V_593 ) ;
V_576 -> V_584 . V_594 = F_138 ( V_595 ) ;
V_576 -> V_584 . V_585 -> V_41 &= ~ V_586 ;
}
#endif
F_153 ( V_6 ) ;
if ( F_188 ( V_576 ) ) {
V_204 -> V_208 = V_578 ;
return - V_508 ;
}
F_251 ( & V_6 -> V_84 -> V_25 . V_596 ) ;
F_7 () ;
if ( ! F_203 ( V_6 -> V_84 ) && ! V_6 -> V_84 -> V_25 . V_597 ) {
V_61 = F_252 ( V_6 ) ;
if ( V_61 )
goto V_441;
}
F_253 ( V_576 ) ;
if ( F_5 ( V_13 ) ) {
V_580 [ 0 ] = F_138 ( V_598 ) ;
V_580 [ 1 ] = F_138 ( V_599 ) ;
V_580 [ 2 ] = F_138 ( V_600 ) ;
V_581 = F_138 ( V_601 ) ;
}
V_582 = F_138 ( V_602 ) ;
V_6 -> V_25 . V_22 = & V_6 -> V_25 . V_32 -> V_406 ;
V_6 -> V_25 . V_603 = V_576 -> V_604 -> V_605 ;
V_6 -> V_25 . V_37 = V_38 ;
do {
V_61 = F_242 ( V_204 , V_6 ) ;
if ( V_204 -> V_208 == V_255 &&
! ( V_6 -> V_25 . V_43 . V_41 & V_606 ) ) {
F_254 ( V_6 ) ;
V_61 = F_66 ( V_6 ) ;
F_255 ( V_6 , V_61 ) ;
F_153 ( V_6 ) ;
} else if ( V_61 == V_257 ) {
V_524 = F_69 ( & V_6 -> V_84 -> V_185 ) ;
V_61 = F_256 ( V_204 , V_6 ,
V_6 -> V_25 . V_77 , V_6 -> V_25 . V_78 ) ;
F_71 ( & V_6 -> V_84 -> V_185 , V_524 ) ;
} else if ( V_61 == V_268 ) {
if ( F_257 ( F_75 () ) )
V_61 = V_163 ;
else
V_61 = F_258 ( V_6 , 0 ) ;
}
} while ( F_198 ( V_61 ) );
if ( F_5 ( V_13 ) ) {
F_210 ( V_598 , V_580 [ 0 ] ) ;
F_210 ( V_599 , V_580 [ 1 ] ) ;
F_210 ( V_600 , V_580 [ 2 ] ) ;
F_210 ( V_601 , V_581 ) ;
F_210 ( V_607 , V_576 -> V_584 . V_608 ) ;
}
F_210 ( V_602 , V_582 ) ;
V_441:
V_6 -> V_25 . V_37 = V_455 ;
F_259 ( & V_6 -> V_84 -> V_25 . V_596 ) ;
return V_61 ;
}
static void F_260 ( struct V_609 * * V_610 ,
int V_611 )
{
struct V_612 * V_613 = & V_614 [ V_611 ] ;
if ( ! V_613 -> V_615 )
return;
( * V_610 ) -> V_616 = V_613 -> V_615 ;
( * V_610 ) -> V_617 = V_613 -> V_618 ;
( * V_610 ) -> V_619 [ 0 ] . V_616 = V_613 -> V_615 ;
( * V_610 ) -> V_619 [ 0 ] . V_620 = V_613 -> V_621 [ V_611 ] ;
if ( V_611 != V_622 && V_613 -> V_621 [ V_622 ] != - 1 ) {
( * V_610 ) -> V_619 [ 1 ] . V_616 = 24 ;
( * V_610 ) -> V_619 [ 1 ] . V_620 = V_613 -> V_621 [ V_622 ] ;
}
( * V_610 ) ++ ;
}
static int F_261 ( struct V_84 * V_84 ,
struct V_623 * V_624 )
{
struct V_609 * V_610 ;
if ( F_262 () )
return - V_58 ;
V_624 -> V_27 = V_625 ;
if ( F_263 ( V_626 ) )
V_624 -> V_27 |= V_627 ;
V_624 -> V_628 = V_629 ;
V_610 = & V_624 -> V_610 [ 0 ] ;
F_260 ( & V_610 , V_630 ) ;
F_260 ( & V_610 , V_631 ) ;
F_260 ( & V_610 , V_622 ) ;
return 0 ;
}
static int F_264 ( struct V_84 * V_84 ,
struct V_632 * log )
{
struct V_633 * V_634 ;
struct V_635 * V_636 ;
int V_5 , V_61 ;
unsigned long V_422 ;
unsigned long * V_415 ;
struct V_1 * V_6 ;
F_39 ( & V_84 -> V_637 ) ;
V_61 = - V_58 ;
if ( log -> V_638 >= V_639 )
goto V_441;
V_634 = V_633 ( V_84 ) ;
V_636 = F_265 ( V_634 , log -> V_638 ) ;
V_61 = - V_186 ;
if ( ! V_636 -> V_640 )
goto V_441;
V_422 = F_266 ( V_636 ) ;
V_415 = V_636 -> V_640 + V_422 / sizeof( long ) ;
memset ( V_415 , 0 , V_422 ) ;
if ( F_203 ( V_84 ) )
V_61 = F_267 ( V_84 , V_636 , V_415 ) ;
else
V_61 = F_268 ( V_84 , V_636 , V_415 ) ;
if ( V_61 )
goto V_441;
F_105 (i, vcpu, kvm) {
F_33 ( & V_6 -> V_25 . V_99 ) ;
F_269 ( & V_6 -> V_25 . V_90 , V_636 , V_415 ) ;
F_269 ( & V_6 -> V_25 . V_122 , V_636 , V_415 ) ;
F_34 ( & V_6 -> V_25 . V_99 ) ;
}
V_61 = - V_435 ;
if ( F_127 ( log -> V_640 , V_415 , V_422 ) )
goto V_441;
V_61 = 0 ;
V_441:
F_41 ( & V_84 -> V_637 ) ;
return V_61 ;
}
static void F_270 ( struct V_635 * free ,
struct V_635 * V_641 )
{
if ( ! V_641 || free -> V_25 . V_642 != V_641 -> V_25 . V_642 ) {
F_271 ( free -> V_25 . V_642 ) ;
free -> V_25 . V_642 = NULL ;
}
}
static int F_272 ( struct V_635 * V_638 ,
unsigned long V_643 )
{
if ( F_262 () ) {
V_638 -> V_25 . V_642 = NULL ;
return 0 ;
}
V_638 -> V_25 . V_642 = F_273 ( V_643 * sizeof( * V_638 -> V_25 . V_642 ) ) ;
if ( ! V_638 -> V_25 . V_642 )
return - V_413 ;
return 0 ;
}
static int F_274 ( struct V_84 * V_84 ,
struct V_635 * V_636 ,
const struct V_644 * V_645 )
{
return 0 ;
}
static void F_275 ( struct V_84 * V_84 ,
const struct V_644 * V_645 ,
const struct V_635 * V_646 ,
const struct V_635 * V_647 )
{
unsigned long V_643 = V_645 -> V_648 >> V_649 ;
struct V_633 * V_634 ;
struct V_635 * V_636 ;
if ( V_643 )
F_276 ( & V_84 -> V_25 . V_650 ) ;
if ( V_643 && V_646 -> V_643 && ! F_203 ( V_84 ) ) {
V_634 = V_633 ( V_84 ) ;
V_636 = F_265 ( V_634 , V_645 -> V_638 ) ;
F_268 ( V_84 , V_636 , NULL ) ;
}
}
void F_277 ( struct V_84 * V_84 , unsigned long V_83 , unsigned long V_281 )
{
long int V_5 ;
T_2 V_651 = 0 ;
if ( ( V_84 -> V_25 . V_83 & V_281 ) == V_83 )
return;
V_84 -> V_25 . V_83 = ( V_84 -> V_25 . V_83 & ~ V_281 ) | V_83 ;
for ( V_5 = 0 ; V_5 < V_457 ; ++ V_5 ) {
struct V_2 * V_3 = V_84 -> V_25 . V_458 [ V_5 ] ;
if ( ! V_3 )
continue;
F_33 ( & V_3 -> V_59 ) ;
V_3 -> V_83 = ( V_3 -> V_83 & ~ V_281 ) | V_83 ;
F_34 ( & V_3 -> V_59 ) ;
if ( ++ V_651 >= V_84 -> V_25 . V_459 )
break;
}
}
static void F_278 ( struct V_1 * V_6 )
{
return;
}
static void F_279 ( struct V_84 * V_84 )
{
unsigned long V_652 , V_653 ;
if ( ! F_203 ( V_84 ) ) {
V_652 = ( ( V_84 -> V_25 . V_654 & V_655 ) >> 1 ) |
( ( V_84 -> V_25 . V_654 & V_656 ) << 1 ) ;
V_652 |= V_84 -> V_25 . V_85 ;
V_653 = V_84 -> V_25 . V_657 ;
} else {
V_652 = V_658 | F_280 () |
F_281 ( V_84 -> V_25 . V_659 ) | V_660 ;
V_653 = V_661 | V_84 -> V_25 . V_657 ;
}
F_282 ( V_84 -> V_25 . V_662 , V_652 , V_653 ) ;
}
static int F_252 ( struct V_1 * V_6 )
{
int V_108 = 0 ;
struct V_84 * V_84 = V_6 -> V_84 ;
unsigned long V_663 ;
struct V_635 * V_636 ;
struct V_664 * V_665 ;
unsigned long V_83 = 0 , V_666 ;
unsigned long V_667 , V_668 ;
int V_524 ;
F_39 ( & V_84 -> V_59 ) ;
if ( V_84 -> V_25 . V_597 )
goto V_441;
if ( ! V_84 -> V_25 . V_669 . V_670 ) {
int V_671 = V_672 ;
struct V_673 V_624 ;
V_108 = F_283 ( & V_624 , V_671 ) ;
while ( ( V_108 == - V_413 ) && -- V_671 >= V_674 )
V_108 = F_283 ( & V_624 , V_671 ) ;
if ( V_108 < 0 ) {
F_36 ( L_22 ) ;
goto V_441;
}
F_284 ( V_84 , & V_624 ) ;
}
V_524 = F_69 ( & V_84 -> V_185 ) ;
V_636 = F_285 ( V_84 , 0 ) ;
V_108 = - V_58 ;
if ( ! V_636 || ( V_636 -> V_27 & V_675 ) )
goto V_676;
V_663 = V_636 -> V_677 ;
F_286 ( & V_576 -> V_604 -> V_678 ) ;
V_665 = F_287 ( V_576 -> V_604 , V_663 ) ;
if ( ! V_665 || V_665 -> V_679 > V_663 || ( V_665 -> V_680 & V_681 ) )
goto V_682;
V_667 = F_288 ( V_665 ) ;
V_668 = F_289 ( V_667 ) ;
F_290 ( & V_576 -> V_604 -> V_678 ) ;
V_108 = - V_58 ;
if ( ! ( V_667 == 0x1000 || V_667 == 0x10000 ||
V_667 == 0x1000000 ) )
goto V_676;
V_666 = F_291 ( V_667 ) ;
V_84 -> V_25 . V_654 = V_666 | V_683 |
( V_684 << V_685 ) ;
F_292 ( V_6 , V_636 , V_668 ) ;
if ( ! F_5 ( V_12 ) ) {
V_83 = V_666 << ( V_686 - 4 ) ;
F_277 ( V_84 , V_83 , V_687 ) ;
} else {
F_279 ( V_84 ) ;
}
F_58 () ;
V_84 -> V_25 . V_597 = 1 ;
V_108 = 0 ;
V_676:
F_71 ( & V_84 -> V_185 , V_524 ) ;
V_441:
F_41 ( & V_84 -> V_59 ) ;
return V_108 ;
V_682:
F_290 ( & V_576 -> V_604 -> V_678 ) ;
goto V_676;
}
void F_293 ( void )
{
struct V_688 * V_689 ;
unsigned long V_690 ;
int V_9 , V_404 ;
int V_691 ;
if ( V_514 != NULL )
return;
V_689 = F_114 ( sizeof( struct V_688 ) , V_405 ) ;
if ( ! V_689 )
return;
V_691 = F_294 () * sizeof( struct V_692 ) ;
V_689 -> V_516 = F_114 ( V_691 , V_405 ) ;
if ( ! V_689 -> V_516 ) {
F_123 ( V_689 ) ;
return;
}
F_295 () ;
for ( V_9 = 0 ; V_9 < V_16 ; V_9 += V_484 ) {
if ( ! F_20 ( V_9 ) )
continue;
V_404 = V_9 >> V_515 ;
V_689 -> V_516 [ V_404 ] . V_517 . V_518 = 1 ;
}
V_689 -> V_693 = F_16 ;
F_58 () ;
V_690 = ( unsigned long ) V_689 ;
if ( F_296 ( ( unsigned long * ) & V_514 , 0 , V_690 ) ) {
F_297 () ;
F_123 ( V_689 -> V_516 ) ;
F_123 ( V_689 ) ;
return;
}
F_298 ( V_694 ,
L_23 ,
F_200 ,
F_199 ) ;
F_297 () ;
}
void F_299 ( void )
{
if ( V_514 ) {
F_300 ( V_694 ) ;
F_123 ( V_514 -> V_516 ) ;
F_123 ( V_514 ) ;
V_514 = NULL ;
}
}
static int F_301 ( struct V_84 * V_84 )
{
unsigned long V_83 , V_662 ;
char V_415 [ 32 ] ;
int V_88 ;
V_662 = F_302 () ;
if ( ( long ) V_662 < 0 )
return - V_413 ;
V_84 -> V_25 . V_662 = V_662 ;
F_293 () ;
if ( ! F_5 ( V_12 ) )
F_303 ( & V_84 -> V_25 . V_483 ) ;
memcpy ( V_84 -> V_25 . V_175 , V_695 ,
sizeof( V_84 -> V_25 . V_175 ) ) ;
if ( ! F_5 ( V_12 ) )
V_84 -> V_25 . V_696 = F_138 ( V_697 ) ;
V_84 -> V_25 . V_698 = F_138 ( V_699 ) ;
V_84 -> V_25 . V_700 = V_83 = F_138 ( V_701 ) ;
V_83 &= V_702 | V_703 ;
V_83 |= ( 4UL << V_704 ) | V_705 |
V_706 | V_707 ;
V_84 -> V_25 . V_654 = V_683 |
( V_684 << V_685 ) ;
if ( F_5 ( V_13 ) )
V_83 |= V_708 ;
if ( F_5 ( V_12 ) ) {
V_83 &= ~ V_706 ;
V_83 |= V_709 | V_710 ;
if ( F_75 () )
V_83 |= V_703 ;
}
if ( F_262 () ) {
V_84 -> V_25 . V_711 = 1 ;
V_83 &= ~ V_707 ;
V_83 |= V_712 | V_713 | V_714 ;
V_88 = F_304 ( V_84 ) ;
if ( V_88 ) {
F_305 ( V_84 -> V_25 . V_662 ) ;
return V_88 ;
}
F_279 ( V_84 ) ;
}
V_84 -> V_25 . V_83 = V_83 ;
V_84 -> V_25 . V_715 = NULL ;
if ( F_203 ( V_84 ) )
V_84 -> V_25 . V_716 = V_717 ;
else if ( F_5 ( V_12 ) )
V_84 -> V_25 . V_716 = V_718 ;
else if ( F_5 ( V_13 ) )
V_84 -> V_25 . V_716 = V_719 ;
else
V_84 -> V_25 . V_716 = V_720 ;
if ( ! F_5 ( V_12 ) )
F_306 () ;
if ( ! F_5 ( V_12 ) )
V_84 -> V_25 . V_407 = V_403 ;
else
V_84 -> V_25 . V_407 = 1 ;
V_84 -> V_25 . V_215 = 1 ;
snprintf ( V_415 , sizeof( V_415 ) , L_24 , V_576 -> V_339 ) ;
V_84 -> V_25 . V_437 = F_131 ( V_415 , V_721 ) ;
if ( ! F_130 ( V_84 -> V_25 . V_437 ) )
F_307 ( V_84 ) ;
return 0 ;
}
static void F_308 ( struct V_84 * V_84 )
{
long int V_5 ;
for ( V_5 = 0 ; V_5 < V_457 ; ++ V_5 )
F_123 ( V_84 -> V_25 . V_458 [ V_5 ] ) ;
V_84 -> V_25 . V_459 = 0 ;
}
static void F_309 ( struct V_84 * V_84 )
{
F_310 ( V_84 -> V_25 . V_437 ) ;
if ( ! F_5 ( V_12 ) )
F_311 () ;
F_308 ( V_84 ) ;
F_305 ( V_84 -> V_25 . V_662 ) ;
if ( F_203 ( V_84 ) )
F_312 ( V_84 ) ;
else
F_313 ( & V_84 -> V_25 . V_669 ) ;
F_314 ( V_84 ) ;
}
static int F_315 ( struct V_203 * V_204 , struct V_1 * V_6 ,
unsigned int V_216 , int * V_722 )
{
return V_219 ;
}
static int F_316 ( struct V_1 * V_6 , int V_723 ,
T_3 V_724 )
{
return V_219 ;
}
static int F_317 ( struct V_1 * V_6 , int V_723 ,
T_3 * V_724 )
{
return V_219 ;
}
static int F_318 ( void )
{
if ( ! F_5 ( V_725 ) ||
! F_5 ( V_50 ) )
return - V_726 ;
return 0 ;
}
void F_314 ( struct V_84 * V_84 )
{
F_123 ( V_84 -> V_25 . V_727 ) ;
}
static struct V_728 * F_319 ( void )
{
return F_114 ( sizeof( struct V_728 ) , V_405 ) ;
}
static int F_320 ( struct V_84 * V_84 , int V_729 , int V_730 )
{
struct V_731 * V_732 ;
struct V_733 * V_734 ;
struct V_728 * V_727 ;
struct V_735 * V_736 ;
int V_5 , V_173 = 0 ;
if ( ! V_737 )
return 1 ;
V_732 = F_321 ( V_729 ) ;
if ( ! V_732 )
return - V_726 ;
F_39 ( & V_84 -> V_59 ) ;
V_727 = V_84 -> V_25 . V_727 ;
if ( V_727 == NULL ) {
V_727 = F_319 () ;
if ( V_727 == NULL ) {
F_41 ( & V_84 -> V_59 ) ;
return - V_413 ;
}
V_84 -> V_25 . V_727 = V_727 ;
}
V_736 = F_322 ( & V_732 -> V_738 ) ;
if ( ! V_736 || ! ( F_323 ( V_736 ) || F_324 ( V_736 ) ) ) {
F_325 ( L_25 ,
V_729 , V_730 ) ;
F_41 ( & V_84 -> V_59 ) ;
return - V_186 ;
}
for ( V_5 = 0 ; V_5 < V_727 -> V_739 ; V_5 ++ ) {
if ( V_730 == V_727 -> V_740 [ V_5 ] . V_741 ) {
if ( V_727 -> V_740 [ V_5 ] . V_742 ) {
F_41 ( & V_84 -> V_59 ) ;
return - V_58 ;
}
break;
}
}
if ( V_5 == V_743 ) {
F_41 ( & V_84 -> V_59 ) ;
return - V_744 ;
}
V_734 = & V_727 -> V_740 [ V_5 ] ;
V_734 -> V_741 = V_730 ;
V_734 -> V_732 = V_732 ;
F_58 () ;
V_734 -> V_742 = V_732 -> V_738 . V_745 ;
if ( V_5 == V_727 -> V_739 )
V_727 -> V_739 ++ ;
if ( F_75 () )
V_173 = F_326 ( V_84 , V_730 , V_732 ) ;
else
F_327 ( V_84 , V_730 , V_732 -> V_738 . V_745 ) ;
if ( V_173 )
V_734 -> V_742 = 0 ;
F_41 ( & V_84 -> V_59 ) ;
return 0 ;
}
static int F_328 ( struct V_84 * V_84 , int V_729 , int V_730 )
{
struct V_731 * V_732 ;
struct V_728 * V_727 ;
int V_5 , V_173 = 0 ;
if ( ! V_737 )
return 0 ;
V_732 = F_321 ( V_729 ) ;
if ( ! V_732 )
return - V_726 ;
F_39 ( & V_84 -> V_59 ) ;
if ( ! V_84 -> V_25 . V_727 )
goto V_746;
V_727 = V_84 -> V_25 . V_727 ;
for ( V_5 = 0 ; V_5 < V_727 -> V_739 ; V_5 ++ ) {
if ( V_730 == V_727 -> V_740 [ V_5 ] . V_741 )
break;
}
if ( V_5 == V_727 -> V_739 ) {
F_41 ( & V_84 -> V_59 ) ;
return - V_747 ;
}
if ( F_75 () )
V_173 = F_329 ( V_84 , V_730 , V_727 -> V_740 [ V_5 ] . V_732 ) ;
else
F_330 ( V_84 , V_730 , V_727 -> V_740 [ V_5 ] . V_742 ) ;
V_727 -> V_740 [ V_5 ] . V_742 = 0 ;
V_746:
F_41 ( & V_84 -> V_59 ) ;
return V_173 ;
}
static int F_331 ( struct V_748 * V_749 ,
struct V_750 * V_751 )
{
int V_88 = 0 ;
struct V_752 * V_753 =
F_332 ( V_749 , struct V_752 , V_754 ) ;
V_753 -> V_755 = V_751 ;
V_88 = F_320 ( V_753 -> V_84 , V_751 -> V_756 , V_753 -> V_757 ) ;
if ( V_88 )
F_333 ( L_26 ,
V_751 -> V_756 , V_753 -> V_757 , V_88 ) ;
return V_88 ;
}
static void F_334 ( struct V_748 * V_749 ,
struct V_750 * V_751 )
{
int V_88 ;
struct V_752 * V_753 =
F_332 ( V_749 , struct V_752 , V_754 ) ;
V_753 -> V_755 = NULL ;
V_88 = F_328 ( V_753 -> V_84 , V_751 -> V_756 , V_753 -> V_757 ) ;
if ( V_88 )
F_325 ( L_27 ,
V_751 -> V_756 , V_753 -> V_757 , V_88 ) ;
}
static long F_335 ( struct V_410 * V_758 ,
unsigned int V_759 , unsigned long V_218 )
{
struct V_84 * V_84 V_760 = V_758 -> V_414 ;
void T_5 * V_761 = ( void T_5 * ) V_218 ;
long V_61 ;
switch ( V_759 ) {
case V_762 : {
T_2 V_763 ;
V_61 = - V_435 ;
if ( F_336 ( V_763 , ( T_2 T_5 * ) V_761 ) )
break;
V_61 = F_337 ( V_84 , V_763 ) ;
if ( V_61 )
break;
V_61 = 0 ;
break;
}
case V_764 : {
struct V_765 V_766 ;
V_61 = - V_435 ;
if ( F_338 ( & V_766 , V_761 , sizeof( V_766 ) ) )
break;
V_61 = F_339 ( V_84 , & V_766 ) ;
break;
}
case V_767 : {
struct V_768 V_769 ;
V_61 = - V_435 ;
if ( F_338 ( & V_769 , V_761 , sizeof( V_769 ) ) )
break;
V_61 = F_340 ( V_84 , & V_769 ) ;
break;
}
case V_770 : {
struct V_768 V_769 ;
V_61 = - V_435 ;
if ( F_338 ( & V_769 , V_761 , sizeof( V_769 ) ) )
break;
V_61 = F_341 ( V_84 , & V_769 ) ;
break;
}
default:
V_61 = - V_771 ;
}
return V_61 ;
}
static void F_342 ( void )
{
int V_5 ;
unsigned int V_772 ;
for ( V_5 = 0 ; V_773 [ V_5 ] ; ++ V_5 ) {
V_772 = V_773 [ V_5 ] ;
F_257 ( ! F_81 ( V_772 ) ) ;
F_343 ( V_772 / 4 , V_695 ) ;
}
}
static int F_344 ( struct V_84 * V_84 , struct V_774 * V_775 )
{
unsigned long V_83 ;
int V_711 ;
if ( ! F_5 ( V_12 ) )
return - V_747 ;
if ( V_775 -> V_27 & ~ ( V_776 | V_777 ) )
return - V_58 ;
V_711 = ! ! ( V_775 -> V_27 & V_776 ) ;
if ( V_711 != F_203 ( V_84 ) )
return - V_58 ;
if ( ! ! ( V_775 -> V_657 & V_661 ) != V_711 )
return - V_58 ;
if ( ( V_775 -> V_657 & V_778 ) > 24 )
return - V_58 ;
V_84 -> V_25 . V_657 = V_775 -> V_657 ;
F_279 ( V_84 ) ;
V_83 = ( V_775 -> V_27 & V_777 ) ? V_713 : 0 ;
F_277 ( V_84 , V_83 , V_713 ) ;
return 0 ;
}
static int F_345 ( void )
{
int V_5 , V_276 ;
int V_779 = F_294 () ;
struct V_780 * V_780 ;
for ( V_5 = 0 ; V_5 < V_779 ; V_5 ++ ) {
int V_781 = V_5 * V_484 ;
int V_782 = F_346 ( V_781 ) ;
if ( V_17 [ V_781 ] . V_780 )
continue;
V_780 =
F_347 ( sizeof( struct V_780 ) ,
V_405 , V_782 ) ;
if ( ! V_780 )
return - V_413 ;
memset ( V_780 , 0 ,
sizeof( struct V_780 ) ) ;
for ( V_276 = 0 ; V_276 < V_484 ; V_276 ++ ) {
int V_9 = V_781 + V_276 ;
V_17 [ V_9 ] . V_780 = V_780 ;
}
}
return 0 ;
}
static int F_348 ( void )
{
return F_5 ( V_12 ) && F_262 () ;
}
static int F_349 ( void )
{
int V_61 ;
V_61 = F_318 () ;
if ( V_61 < 0 )
return - V_747 ;
V_61 = F_345 () ;
if ( V_61 )
return V_61 ;
#ifdef V_15
if ( ! F_75 () && ! V_519 -> V_18 . V_19 ) {
struct V_783 * V_784 ;
V_784 = F_350 ( NULL , NULL , L_28 ) ;
if ( ! V_784 ) {
F_36 ( L_29 ) ;
return - V_747 ;
}
}
#endif
V_785 . V_786 = V_787 ;
V_788 = & V_785 ;
F_342 () ;
F_172 () ;
V_61 = F_351 () ;
if ( V_61 )
return V_61 ;
if ( F_348 () )
V_61 = F_352 () ;
return V_61 ;
}
static void F_353 ( void )
{
F_299 () ;
if ( F_348 () )
F_354 () ;
V_788 = NULL ;
}
