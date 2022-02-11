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
V_88 = F_75 ( V_6 , V_167 ) ;
break;
}
return V_172 ;
case V_192 :
V_88 = F_76 ( V_6 , F_37 ( V_6 , 4 ) ,
F_37 ( V_6 , 5 ) ,
F_37 ( V_6 , 6 ) ) ;
if ( V_88 == V_164 )
return V_172 ;
break;
case V_193 :
V_88 = F_77 ( V_6 , F_37 ( V_6 , 4 ) ,
F_37 ( V_6 , 5 ) ,
F_37 ( V_6 , 6 ) ,
F_37 ( V_6 , 7 ) ) ;
if ( V_88 == V_164 )
return V_172 ;
break;
case V_194 :
V_88 = F_78 ( V_6 , F_37 ( V_6 , 4 ) ,
F_37 ( V_6 , 5 ) ,
F_37 ( V_6 , 6 ) ,
F_37 ( V_6 , 7 ) ) ;
if ( V_88 == V_164 )
return V_172 ;
break;
default:
return V_172 ;
}
F_79 ( V_6 , 3 , V_88 ) ;
V_6 -> V_25 . V_195 = 0 ;
return V_196 ;
}
static int F_80 ( unsigned long V_197 )
{
switch ( V_197 ) {
case V_173 :
case V_174 :
case V_177 :
case V_178 :
case V_185 :
case V_183 :
case V_184 :
#ifdef F_81
case V_186 :
case V_187 :
case V_188 :
case V_189 :
case V_190 :
case V_191 :
#endif
return 1 ;
}
return F_82 ( V_197 ) ;
}
static int F_83 ( struct V_198 * V_199 ,
struct V_1 * V_6 )
{
T_2 V_86 ;
if ( F_84 ( V_6 , V_200 , & V_86 ) !=
V_201 ) {
return V_196 ;
}
if ( V_86 == V_202 ) {
V_199 -> V_203 = V_204 ;
V_199 -> V_205 . V_25 . V_206 = F_59 ( V_6 ) ;
return V_172 ;
} else {
F_85 ( V_6 , V_207 ) ;
return V_196 ;
}
}
static int F_86 ( struct V_198 * V_199 , struct V_1 * V_6 ,
struct V_208 * V_209 )
{
int V_61 = V_172 ;
V_6 -> V_23 . V_210 ++ ;
if ( V_6 -> V_25 . V_43 . V_41 & V_211 ) {
F_87 ( V_212 L_14 ) ;
F_87 ( V_212 L_15 ,
V_6 -> V_25 . V_64 , F_59 ( V_6 ) ,
V_6 -> V_25 . V_43 . V_41 ) ;
F_35 ( V_6 ) ;
V_199 -> V_203 = V_213 ;
V_199 -> V_214 . V_215 = V_6 -> V_25 . V_64 ;
return V_172 ;
}
V_199 -> V_203 = V_216 ;
V_199 -> V_217 = 1 ;
switch ( V_6 -> V_25 . V_64 ) {
case V_218 :
V_6 -> V_23 . V_219 ++ ;
V_61 = V_196 ;
break;
case V_220 :
case V_221 :
case V_222 :
V_6 -> V_23 . V_223 ++ ;
V_61 = V_196 ;
break;
case V_224 :
case V_225 :
V_61 = V_196 ;
break;
case V_226 :
F_88 ( V_6 ,
V_226 ) ;
V_61 = V_196 ;
break;
case V_227 :
{
T_3 V_27 ;
V_27 = V_6 -> V_25 . V_43 . V_41 & 0x1f0000ull ;
F_85 ( V_6 , V_27 ) ;
V_61 = V_196 ;
break;
}
case V_228 :
{
int V_5 ;
V_199 -> V_229 . V_230 = F_37 ( V_6 , 3 ) ;
for ( V_5 = 0 ; V_5 < 9 ; ++ V_5 )
V_199 -> V_229 . args [ V_5 ] = F_37 ( V_6 , 4 + V_5 ) ;
V_199 -> V_203 = V_231 ;
V_6 -> V_25 . V_195 = 1 ;
V_61 = V_172 ;
break;
}
case V_232 :
V_61 = V_233 ;
break;
case V_234 :
V_6 -> V_25 . V_77 = F_59 ( V_6 ) ;
V_6 -> V_25 . V_78 = 0 ;
V_61 = V_233 ;
break;
case V_235 :
if ( V_6 -> V_25 . V_236 != V_237 )
V_6 -> V_25 . V_86 = F_89 ( V_6 ) ?
F_90 ( V_6 -> V_25 . V_236 ) :
V_6 -> V_25 . V_236 ;
if ( V_6 -> V_238 & V_239 ) {
V_61 = F_83 ( V_199 , V_6 ) ;
} else {
F_85 ( V_6 , V_207 ) ;
V_61 = V_196 ;
}
break;
case V_240 :
F_85 ( V_6 , V_207 ) ;
V_61 = V_196 ;
break;
case V_241 :
V_61 = V_242 ;
break;
default:
F_35 ( V_6 ) ;
F_87 ( V_212 L_15 ,
V_6 -> V_25 . V_64 , F_59 ( V_6 ) ,
V_6 -> V_25 . V_43 . V_41 ) ;
V_199 -> V_214 . V_215 = V_6 -> V_25 . V_64 ;
V_61 = V_172 ;
break;
}
return V_61 ;
}
static int F_91 ( struct V_1 * V_6 ,
struct V_243 * V_244 )
{
int V_5 ;
memset ( V_244 , 0 , sizeof( struct V_243 ) ) ;
V_244 -> V_44 = V_6 -> V_25 . V_44 ;
for ( V_5 = 0 ; V_5 < V_6 -> V_25 . V_79 ; V_5 ++ ) {
V_244 -> V_245 . V_246 . V_247 . V_80 [ V_5 ] . V_248 = V_6 -> V_25 . V_80 [ V_5 ] . V_81 ;
V_244 -> V_245 . V_246 . V_247 . V_80 [ V_5 ] . V_249 = V_6 -> V_25 . V_80 [ V_5 ] . V_82 ;
}
return 0 ;
}
static int F_92 ( struct V_1 * V_6 ,
struct V_243 * V_244 )
{
int V_5 , V_250 ;
if ( V_244 -> V_44 != V_6 -> V_25 . V_44 )
return - V_58 ;
V_250 = 0 ;
for ( V_5 = 0 ; V_5 < V_6 -> V_25 . V_251 ; V_5 ++ ) {
if ( V_244 -> V_245 . V_246 . V_247 . V_80 [ V_5 ] . V_248 & V_252 ) {
V_6 -> V_25 . V_80 [ V_250 ] . V_81 = V_244 -> V_245 . V_246 . V_247 . V_80 [ V_5 ] . V_248 ;
V_6 -> V_25 . V_80 [ V_250 ] . V_82 = V_244 -> V_245 . V_246 . V_247 . V_80 [ V_5 ] . V_249 ;
++ V_250 ;
}
}
V_6 -> V_25 . V_79 = V_250 ;
return 0 ;
}
static void F_93 ( struct V_1 * V_6 , T_1 V_253 ,
bool V_254 )
{
struct V_84 * V_84 = V_6 -> V_84 ;
struct V_2 * V_3 = V_6 -> V_25 . V_32 ;
T_1 V_255 ;
F_39 ( & V_84 -> V_59 ) ;
F_33 ( & V_3 -> V_59 ) ;
if ( ( V_253 & V_256 ) != ( V_3 -> V_83 & V_256 ) ) {
struct V_1 * V_6 ;
int V_5 ;
F_94 (i, vcpu, kvm) {
if ( V_6 -> V_25 . V_32 != V_3 )
continue;
if ( V_253 & V_256 )
V_6 -> V_25 . V_257 |= V_258 ;
else
V_6 -> V_25 . V_257 &= ~ V_258 ;
}
}
V_255 = V_259 | V_256 | V_260 ;
if ( F_5 ( V_13 ) )
V_255 |= V_261 ;
if ( V_254 )
V_255 &= 0xFFFFFFFF ;
V_3 -> V_83 = ( V_3 -> V_83 & ~ V_255 ) | ( V_253 & V_255 ) ;
F_34 ( & V_3 -> V_59 ) ;
F_41 ( & V_84 -> V_59 ) ;
}
static int F_95 ( struct V_1 * V_6 , T_1 V_87 ,
union V_262 * V_263 )
{
int V_61 = 0 ;
long int V_5 ;
switch ( V_87 ) {
case V_264 :
* V_263 = F_96 ( V_87 , V_202 ) ;
break;
case V_265 :
* V_263 = F_96 ( V_87 , 0 ) ;
break;
case V_266 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_267 ) ;
break;
case V_268 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_269 ) ;
break;
case V_270 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_271 ) ;
break;
case V_272 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_273 ) ;
break;
case V_274 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_275 ) ;
break;
case V_276 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_277 ) ;
break;
case V_278 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_279 ) ;
break;
case V_280 ... V_281 :
V_5 = V_87 - V_280 ;
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_282 [ V_5 ] ) ;
break;
case V_283 ... V_284 :
V_5 = V_87 - V_283 ;
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_285 [ V_5 ] ) ;
break;
case V_286 ... V_287 :
V_5 = V_87 - V_286 ;
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_288 [ V_5 ] ) ;
break;
case V_289 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_290 ) ;
break;
case V_291 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_292 ) ;
break;
case V_293 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_294 ) ;
break;
case V_295 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_296 ) ;
break;
case V_297 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_298 ) ;
break;
case V_299 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_32 -> V_300 ) ;
break;
case V_301 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_32 -> V_302 ) ;
break;
case V_303 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_162 ) ;
break;
case V_304 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_163 ) ;
break;
case V_305 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_158 ) ;
break;
case V_306 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_307 ) ;
break;
case V_308 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_309 ) ;
break;
case V_310 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_311 ) ;
break;
case V_312 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_313 ) ;
break;
case V_314 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_315 ) ;
break;
case V_316 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_317 ) ;
break;
case V_318 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_319 ) ;
break;
case V_320 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_321 ) ;
break;
case V_322 :
F_33 ( & V_6 -> V_25 . V_99 ) ;
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_90 . V_100 ) ;
F_34 ( & V_6 -> V_25 . V_99 ) ;
break;
case V_323 :
F_33 ( & V_6 -> V_25 . V_99 ) ;
V_263 -> V_324 . V_96 = V_6 -> V_25 . V_123 . V_100 ;
V_263 -> V_324 . V_117 = V_6 -> V_25 . V_123 . V_97 ;
F_34 ( & V_6 -> V_25 . V_99 ) ;
break;
case V_325 :
F_33 ( & V_6 -> V_25 . V_99 ) ;
V_263 -> V_324 . V_96 = V_6 -> V_25 . V_122 . V_100 ;
V_263 -> V_324 . V_117 = V_6 -> V_25 . V_122 . V_97 ;
F_34 ( & V_6 -> V_25 . V_99 ) ;
break;
case V_326 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_32 -> V_144 ) ;
break;
case V_327 :
case V_328 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_32 -> V_83 ) ;
break;
case V_329 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_330 ) ;
break;
#ifdef F_97
case V_331 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_332 ) ;
break;
case V_333 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_334 ) ;
break;
case V_335 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_336 ) ;
break;
case V_337 ... V_338 :
V_5 = V_87 - V_337 ;
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_339 [ V_5 ] ) ;
break;
case V_340 ... V_341 :
{
int V_250 ;
V_5 = V_87 - V_340 ;
if ( V_5 < 32 )
for ( V_250 = 0 ; V_250 < V_342 ; V_250 ++ )
V_263 -> V_343 [ V_250 ] = V_6 -> V_25 . V_344 . V_345 [ V_5 ] [ V_250 ] ;
else {
if ( F_5 ( V_346 ) )
V_263 -> V_347 = V_6 -> V_25 . V_348 . V_349 [ V_5 - 32 ] ;
else
V_61 = - V_350 ;
}
break;
}
case V_351 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_352 ) ;
break;
case V_353 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_354 ) ;
break;
case V_355 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_356 ) ;
break;
case V_357 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_358 ) ;
break;
case V_359 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_344 . V_360 ) ;
break;
case V_361 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_362 ) ;
break;
case V_363 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_364 ) ;
break;
case V_365 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_366 ) ;
break;
case V_367 :
if ( F_5 ( V_346 ) )
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_348 . V_368 . V_245 [ 3 ] ) ;
else
V_61 = - V_350 ;
break;
case V_369 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_370 ) ;
break;
case V_371 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_372 ) ;
break;
#endif
case V_373 :
* V_263 = F_96 ( V_87 , V_6 -> V_25 . V_32 -> V_45 ) ;
break;
default:
V_61 = - V_58 ;
break;
}
return V_61 ;
}
static int F_98 ( struct V_1 * V_6 , T_1 V_87 ,
union V_262 * V_263 )
{
int V_61 = 0 ;
long int V_5 ;
unsigned long V_96 , V_97 ;
switch ( V_87 ) {
case V_265 :
if ( F_99 ( V_87 , * V_263 ) )
V_61 = - V_58 ;
break;
case V_266 :
V_6 -> V_25 . V_267 = F_99 ( V_87 , * V_263 ) ;
break;
case V_268 :
V_6 -> V_25 . V_269 = F_99 ( V_87 , * V_263 ) & ~ V_161 ;
break;
case V_270 :
V_6 -> V_25 . V_271 = F_99 ( V_87 , * V_263 ) ;
break;
case V_272 :
V_6 -> V_25 . V_273 = F_99 ( V_87 , * V_263 ) ;
break;
case V_274 :
V_6 -> V_25 . V_275 = F_99 ( V_87 , * V_263 ) ;
break;
case V_276 :
V_6 -> V_25 . V_277 = F_99 ( V_87 , * V_263 ) ;
break;
case V_278 :
V_6 -> V_25 . V_279 = F_99 ( V_87 , * V_263 ) ;
break;
case V_280 ... V_281 :
V_5 = V_87 - V_280 ;
V_6 -> V_25 . V_282 [ V_5 ] = F_99 ( V_87 , * V_263 ) ;
break;
case V_283 ... V_284 :
V_5 = V_87 - V_283 ;
V_6 -> V_25 . V_285 [ V_5 ] = F_99 ( V_87 , * V_263 ) ;
break;
case V_286 ... V_287 :
V_5 = V_87 - V_286 ;
V_6 -> V_25 . V_288 [ V_5 ] = F_99 ( V_87 , * V_263 ) ;
break;
case V_289 :
V_6 -> V_25 . V_290 = F_99 ( V_87 , * V_263 ) ;
break;
case V_291 :
V_6 -> V_25 . V_292 = F_99 ( V_87 , * V_263 ) ;
break;
case V_293 :
V_6 -> V_25 . V_294 = F_99 ( V_87 , * V_263 ) ;
break;
case V_295 :
V_6 -> V_25 . V_296 = F_99 ( V_87 , * V_263 ) ;
break;
case V_297 :
V_6 -> V_25 . V_298 = F_99 ( V_87 , * V_263 ) ;
break;
case V_299 :
V_6 -> V_25 . V_32 -> V_300 = F_99 ( V_87 , * V_263 ) ;
break;
case V_301 :
V_6 -> V_25 . V_32 -> V_302 = F_99 ( V_87 , * V_263 ) ;
break;
case V_303 :
V_6 -> V_25 . V_162 = F_99 ( V_87 , * V_263 ) ;
break;
case V_304 :
V_6 -> V_25 . V_163 = F_99 ( V_87 , * V_263 ) & ~ V_374 ;
break;
case V_305 :
V_6 -> V_25 . V_158 = F_99 ( V_87 , * V_263 ) ;
if ( ( V_6 -> V_25 . V_158 & V_155 ) == V_156 )
V_6 -> V_25 . V_158 &= ~ V_155 ;
break;
case V_306 :
V_6 -> V_25 . V_307 = F_99 ( V_87 , * V_263 ) ;
break;
case V_308 :
V_6 -> V_25 . V_309 = F_99 ( V_87 , * V_263 ) ;
break;
case V_310 :
V_6 -> V_25 . V_311 = F_99 ( V_87 , * V_263 ) ;
break;
case V_312 :
V_6 -> V_25 . V_313 = F_99 ( V_87 , * V_263 ) ;
break;
case V_314 :
V_6 -> V_25 . V_315 = F_99 ( V_87 , * V_263 ) ;
break;
case V_316 :
V_6 -> V_25 . V_317 = F_99 ( V_87 , * V_263 ) ;
break;
case V_318 :
V_6 -> V_25 . V_319 = F_99 ( V_87 , * V_263 ) ;
break;
case V_320 :
V_6 -> V_25 . V_321 = F_99 ( V_87 , * V_263 ) & V_375 ;
break;
case V_322 :
V_96 = F_99 ( V_87 , * V_263 ) ;
V_61 = - V_58 ;
if ( ! V_96 && ( V_6 -> V_25 . V_123 . V_100 ||
V_6 -> V_25 . V_122 . V_100 ) )
break;
V_61 = F_44 ( V_6 , & V_6 -> V_25 . V_90 , V_96 , sizeof( struct V_89 ) ) ;
break;
case V_323 :
V_96 = V_263 -> V_324 . V_96 ;
V_97 = V_263 -> V_324 . V_117 ;
V_61 = - V_58 ;
if ( V_96 && ! V_6 -> V_25 . V_90 . V_100 )
break;
V_61 = F_44 ( V_6 , & V_6 -> V_25 . V_123 , V_96 , V_97 ) ;
break;
case V_325 :
V_96 = V_263 -> V_324 . V_96 ;
V_97 = V_263 -> V_324 . V_117 ;
V_61 = - V_58 ;
if ( V_96 && ( V_97 < sizeof( struct V_120 ) ||
! V_6 -> V_25 . V_90 . V_100 ) )
break;
V_97 -= V_97 % sizeof( struct V_120 ) ;
V_61 = F_44 ( V_6 , & V_6 -> V_25 . V_122 , V_96 , V_97 ) ;
break;
case V_326 :
V_6 -> V_25 . V_32 -> V_144 =
F_100 ( F_99 ( V_87 , * V_263 ) , 1UL << 24 ) ;
break;
case V_327 :
F_93 ( V_6 , F_99 ( V_87 , * V_263 ) , true ) ;
break;
case V_328 :
F_93 ( V_6 , F_99 ( V_87 , * V_263 ) , false ) ;
break;
case V_329 :
V_6 -> V_25 . V_330 = F_99 ( V_87 , * V_263 ) ;
break;
#ifdef F_97
case V_331 :
V_6 -> V_25 . V_332 = F_99 ( V_87 , * V_263 ) ;
break;
case V_333 :
V_6 -> V_25 . V_334 = F_99 ( V_87 , * V_263 ) ;
break;
case V_335 :
V_6 -> V_25 . V_336 = F_99 ( V_87 , * V_263 ) ;
break;
case V_337 ... V_338 :
V_5 = V_87 - V_337 ;
V_6 -> V_25 . V_339 [ V_5 ] = F_99 ( V_87 , * V_263 ) ;
break;
case V_340 ... V_341 :
{
int V_250 ;
V_5 = V_87 - V_340 ;
if ( V_5 < 32 )
for ( V_250 = 0 ; V_250 < V_342 ; V_250 ++ )
V_6 -> V_25 . V_344 . V_345 [ V_5 ] [ V_250 ] = V_263 -> V_343 [ V_250 ] ;
else
if ( F_5 ( V_346 ) )
V_6 -> V_25 . V_348 . V_349 [ V_5 - 32 ] = V_263 -> V_347 ;
else
V_61 = - V_350 ;
break;
}
case V_351 :
V_6 -> V_25 . V_352 = F_99 ( V_87 , * V_263 ) ;
break;
case V_353 :
V_6 -> V_25 . V_354 = F_99 ( V_87 , * V_263 ) ;
break;
case V_355 :
V_6 -> V_25 . V_356 = F_99 ( V_87 , * V_263 ) ;
break;
case V_357 :
V_6 -> V_25 . V_358 = F_99 ( V_87 , * V_263 ) ;
break;
case V_359 :
V_6 -> V_25 . V_344 . V_360 = F_99 ( V_87 , * V_263 ) ;
break;
case V_361 :
V_6 -> V_25 . V_362 = F_99 ( V_87 , * V_263 ) ;
break;
case V_363 :
V_6 -> V_25 . V_364 = F_99 ( V_87 , * V_263 ) ;
break;
case V_365 :
V_6 -> V_25 . V_366 = F_99 ( V_87 , * V_263 ) ;
break;
case V_367 :
if ( F_5 ( V_346 ) )
V_6 -> V_25 . V_349 . V_368 . V_245 [ 3 ] = F_99 ( V_87 , * V_263 ) ;
else
V_61 = - V_350 ;
break;
case V_369 :
V_6 -> V_25 . V_370 = F_99 ( V_87 , * V_263 ) ;
break;
case V_371 :
V_6 -> V_25 . V_372 = F_99 ( V_87 , * V_263 ) ;
break;
#endif
case V_373 :
V_61 = F_32 ( V_6 , F_99 ( V_87 , * V_263 ) ) ;
break;
default:
V_61 = - V_58 ;
break;
}
return V_61 ;
}
static int F_101 ( void )
{
if ( F_5 ( V_12 ) )
return 1 ;
return V_376 ;
}
static struct V_2 * F_102 ( struct V_84 * V_84 , int V_377 )
{
struct V_2 * V_32 ;
V_32 = F_103 ( sizeof( struct V_2 ) , V_378 ) ;
if ( V_32 == NULL )
return NULL ;
F_104 ( & V_32 -> V_59 ) ;
F_104 ( & V_32 -> V_28 ) ;
F_105 ( & V_32 -> V_379 ) ;
V_32 -> V_29 = V_30 ;
V_32 -> V_83 = V_84 -> V_25 . V_83 ;
V_32 -> V_380 = V_377 * F_101 () ;
V_32 -> V_84 = V_84 ;
F_106 ( & V_32 -> V_381 ) ;
return V_32 ;
}
static int F_107 ( struct V_382 * V_382 , struct V_383 * V_383 )
{
struct V_1 * V_6 = V_382 -> V_384 ;
struct V_385 * V_133 ;
V_133 = F_103 ( sizeof( * V_133 ) , V_378 ) ;
if ( ! V_133 )
return - V_386 ;
F_108 ( V_6 -> V_84 ) ;
V_133 -> V_6 = V_6 ;
V_383 -> V_387 = V_133 ;
return F_109 ( V_382 , V_383 ) ;
}
static int F_110 ( struct V_382 * V_382 , struct V_383 * V_383 )
{
struct V_385 * V_133 = V_383 -> V_387 ;
F_111 ( V_133 -> V_6 -> V_84 ) ;
F_112 ( V_133 ) ;
return 0 ;
}
static T_4 F_113 ( struct V_383 * V_383 , char T_5 * V_388 ,
T_6 V_97 , T_7 * V_389 )
{
struct V_385 * V_133 = V_383 -> V_387 ;
struct V_1 * V_6 = V_133 -> V_6 ;
char * V_246 , * V_390 ;
struct V_391 V_392 ;
T_1 V_393 ;
T_7 V_394 ;
T_4 V_395 ;
int V_5 , V_396 ;
bool V_397 ;
if ( ! V_133 -> V_398 ) {
V_246 = V_133 -> V_388 ;
V_390 = V_246 + sizeof( V_133 -> V_388 ) ;
for ( V_5 = 0 ; V_5 < V_399 ; ++ V_5 ) {
struct V_391 * V_400 ;
V_400 = (struct V_391 * )
( ( unsigned long ) V_6 + V_401 [ V_5 ] . V_402 ) ;
V_397 = false ;
for ( V_396 = 0 ; V_396 < 1000 ; ++ V_396 ) {
V_393 = V_400 -> V_403 ;
if ( ! ( V_393 & 1 ) ) {
F_114 () ;
V_392 = * V_400 ;
F_114 () ;
if ( V_393 == V_400 -> V_403 ) {
V_397 = true ;
break;
}
}
F_115 ( 1 ) ;
}
if ( ! V_397 )
snprintf ( V_246 , V_390 - V_246 , L_16 ,
V_401 [ V_5 ] . V_404 ) ;
else
snprintf ( V_246 , V_390 - V_246 ,
L_17 ,
V_401 [ V_5 ] . V_404 , V_393 / 2 ,
F_116 ( V_392 . V_405 ) ,
F_116 ( V_392 . V_406 ) ,
F_116 ( V_392 . V_407 ) ) ;
V_246 += strlen ( V_246 ) ;
}
V_133 -> V_398 = V_246 - V_133 -> V_388 ;
}
V_394 = * V_389 ;
if ( V_394 >= V_133 -> V_398 )
return 0 ;
if ( V_97 > V_133 -> V_398 - V_394 )
V_97 = V_133 -> V_398 - V_394 ;
V_395 = F_117 ( V_388 , V_133 -> V_388 + V_394 , V_97 ) ;
if ( V_395 ) {
if ( V_395 == V_97 )
return - V_408 ;
V_97 -= V_395 ;
}
* V_389 = V_394 + V_97 ;
return V_97 ;
}
static T_4 F_118 ( struct V_383 * V_383 , const char T_5 * V_388 ,
T_6 V_97 , T_7 * V_389 )
{
return - V_409 ;
}
static void F_119 ( struct V_1 * V_6 , unsigned int V_87 )
{
char V_388 [ 16 ] ;
struct V_84 * V_84 = V_6 -> V_84 ;
snprintf ( V_388 , sizeof( V_388 ) , L_18 , V_87 ) ;
if ( F_120 ( V_84 -> V_25 . V_410 ) )
return;
V_6 -> V_25 . V_410 = F_121 ( V_388 , V_84 -> V_25 . V_410 ) ;
if ( F_120 ( V_6 -> V_25 . V_410 ) )
return;
V_6 -> V_25 . V_411 =
F_122 ( L_19 , 0444 , V_6 -> V_25 . V_410 ,
V_6 , & V_412 ) ;
}
static void F_119 ( struct V_1 * V_6 , unsigned int V_87 )
{
}
static struct V_1 * F_123 ( struct V_84 * V_84 ,
unsigned int V_87 )
{
struct V_1 * V_6 ;
int V_108 = - V_58 ;
int V_377 ;
struct V_2 * V_32 ;
V_377 = V_87 / F_101 () ;
if ( V_377 >= V_413 )
goto V_414;
V_108 = - V_386 ;
V_6 = F_124 ( V_415 , V_378 ) ;
if ( ! V_6 )
goto V_414;
V_108 = F_125 ( V_6 , V_84 , V_87 ) ;
if ( V_108 )
goto V_416;
V_6 -> V_25 . V_417 = & V_6 -> V_25 . V_43 ;
#ifdef F_126
#ifdef F_127
V_6 -> V_25 . V_418 = true ;
#else
V_6 -> V_25 . V_418 = false ;
#endif
#endif
V_6 -> V_25 . V_282 [ 0 ] = V_419 ;
V_6 -> V_25 . V_420 = V_421 ;
F_31 ( V_6 , F_128 ( V_422 ) ) ;
F_104 ( & V_6 -> V_25 . V_99 ) ;
F_104 ( & V_6 -> V_25 . V_36 ) ;
V_6 -> V_25 . V_39 = V_30 ;
V_6 -> V_25 . V_257 = V_423 | V_424 ;
F_129 ( V_6 ) ;
V_6 -> V_25 . V_37 = V_425 ;
F_130 ( & V_6 -> V_25 . V_426 ) ;
F_39 ( & V_84 -> V_59 ) ;
V_32 = V_84 -> V_25 . V_427 [ V_377 ] ;
if ( ! V_32 ) {
V_32 = F_102 ( V_84 , V_377 ) ;
V_84 -> V_25 . V_427 [ V_377 ] = V_32 ;
V_84 -> V_25 . V_428 ++ ;
}
F_41 ( & V_84 -> V_59 ) ;
if ( ! V_32 )
goto V_416;
F_33 ( & V_32 -> V_59 ) ;
++ V_32 -> V_429 ;
F_34 ( & V_32 -> V_59 ) ;
V_6 -> V_25 . V_32 = V_32 ;
V_6 -> V_25 . V_142 = V_6 -> V_62 - V_32 -> V_380 ;
V_6 -> V_25 . V_26 = - 1 ;
V_6 -> V_25 . V_430 = - 1 ;
V_6 -> V_25 . V_431 = V_432 ;
F_131 ( V_6 ) ;
F_119 ( V_6 , V_87 ) ;
return V_6 ;
V_416:
F_132 ( V_415 , V_6 ) ;
V_414:
return F_133 ( V_108 ) ;
}
static void F_134 ( struct V_84 * V_84 , struct V_94 * V_90 )
{
if ( V_90 -> V_103 )
F_50 ( V_84 , V_90 -> V_103 , V_90 -> V_127 ,
V_90 -> V_128 ) ;
}
static void F_135 ( struct V_1 * V_6 )
{
F_33 ( & V_6 -> V_25 . V_99 ) ;
F_134 ( V_6 -> V_84 , & V_6 -> V_25 . V_122 ) ;
F_134 ( V_6 -> V_84 , & V_6 -> V_25 . V_123 ) ;
F_134 ( V_6 -> V_84 , & V_6 -> V_25 . V_90 ) ;
F_34 ( & V_6 -> V_25 . V_99 ) ;
F_136 ( V_6 ) ;
F_132 ( V_415 , V_6 ) ;
}
static int F_137 ( struct V_1 * V_6 )
{
return 1 ;
}
static void F_138 ( struct V_1 * V_6 )
{
unsigned long V_433 , V_132 ;
V_132 = F_139 () ;
if ( V_132 > V_6 -> V_25 . V_434 ) {
F_140 ( V_6 ) ;
F_141 ( V_6 ) ;
return;
}
V_433 = ( V_6 -> V_25 . V_434 - V_132 ) * V_435
/ V_436 ;
F_142 ( & V_6 -> V_25 . V_437 , V_433 , V_438 ) ;
V_6 -> V_25 . V_439 = 1 ;
}
static void F_30 ( struct V_1 * V_6 )
{
V_6 -> V_25 . V_176 = 0 ;
if ( V_6 -> V_25 . V_439 ) {
F_143 ( & V_6 -> V_25 . V_437 ) ;
V_6 -> V_25 . V_439 = 0 ;
}
}
static void F_144 ( struct V_2 * V_3 ,
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
-- V_3 -> V_440 ;
F_145 ( V_3 -> V_8 [ V_6 -> V_25 . V_142 ] , NULL ) ;
}
static int F_146 ( int V_9 )
{
struct V_441 * V_442 ;
long V_443 = 10000 ;
V_442 = & V_17 [ V_9 ] ;
V_442 -> V_18 . V_1 = NULL ;
V_442 -> V_18 . V_444 = NULL ;
V_442 -> V_18 . V_445 = 0 ;
F_60 () ;
V_442 -> V_18 . V_446 = 1 ;
F_7 () ;
while ( V_442 -> V_18 . V_447 == V_448 ) {
if ( -- V_443 <= 0 ) {
F_36 ( L_20 , V_9 ) ;
return - V_449 ;
}
F_115 ( 1 ) ;
}
return 0 ;
}
static void F_147 ( int V_9 )
{
struct V_441 * V_442 ;
V_442 = & V_17 [ V_9 ] ;
V_442 -> V_18 . V_446 = 0 ;
V_442 -> V_18 . V_1 = NULL ;
V_442 -> V_18 . V_444 = NULL ;
V_442 -> V_18 . V_450 = NULL ;
}
static void F_148 ( void * V_451 )
{
}
static void F_149 ( struct V_84 * V_84 , int V_9 , struct V_1 * V_6 )
{
int V_5 ;
V_9 = F_9 ( V_9 ) ;
F_150 ( V_9 , & V_84 -> V_25 . V_452 ) ;
F_7 () ;
for ( V_5 = 0 ; V_5 < V_453 ; ++ V_5 )
if ( F_151 ( V_9 + V_5 , & V_84 -> V_25 . V_454 ) )
F_152 ( V_9 + V_5 , F_148 , NULL , 1 ) ;
}
static void F_153 ( struct V_1 * V_6 , struct V_2 * V_3 )
{
int V_9 ;
struct V_441 * V_442 ;
struct V_2 * V_455 = V_3 -> V_456 ;
struct V_84 * V_84 = V_3 -> V_84 ;
V_9 = V_3 -> V_141 ;
if ( V_6 ) {
if ( V_6 -> V_25 . V_439 ) {
F_143 ( & V_6 -> V_25 . V_437 ) ;
V_6 -> V_25 . V_439 = 0 ;
}
V_9 += V_6 -> V_25 . V_142 ;
V_6 -> V_9 = V_455 -> V_141 ;
V_6 -> V_25 . V_26 = V_9 ;
if ( F_154 ( V_84 ) && V_6 -> V_25 . V_430 != V_9 ) {
if ( V_6 -> V_25 . V_430 >= 0 &&
F_9 ( V_6 -> V_25 . V_430 ) !=
F_9 ( V_9 ) )
F_149 ( V_84 , V_6 -> V_25 . V_430 , V_6 ) ;
V_6 -> V_25 . V_430 = V_9 ;
}
F_150 ( V_9 , & V_84 -> V_25 . V_454 ) ;
}
V_442 = & V_17 [ V_9 ] ;
V_442 -> V_18 . V_1 = V_6 ;
V_442 -> V_18 . V_142 = V_9 - V_455 -> V_141 ;
F_60 () ;
V_442 -> V_18 . V_444 = V_455 ;
if ( V_9 != F_10 () )
F_3 ( V_9 ) ;
}
static void F_155 ( void )
{
int V_9 = F_10 () ;
int V_5 , V_396 ;
int V_457 = F_101 () ;
if ( V_457 <= 1 )
return;
for ( V_396 = 0 ; V_396 < 1000000 ; ++ V_396 ) {
for ( V_5 = 1 ; V_5 < V_457 ; ++ V_5 )
if ( V_17 [ V_9 + V_5 ] . V_18 . V_444 )
break;
if ( V_5 == V_457 ) {
F_156 () ;
return;
}
F_157 () ;
}
F_156 () ;
for ( V_5 = 1 ; V_5 < V_457 ; ++ V_5 )
if ( V_17 [ V_9 + V_5 ] . V_18 . V_444 )
F_36 ( L_21 , V_9 + V_5 ) ;
}
static int F_158 ( void )
{
int V_9 = F_10 () ;
int V_458 ;
if ( F_159 ( V_9 ) )
return 0 ;
V_458 = 0 ;
while ( ++ V_458 < V_376 )
if ( F_20 ( V_9 + V_458 ) )
return 0 ;
for ( V_458 = 1 ; V_458 < V_376 ; ++ V_458 ) {
if ( F_146 ( V_9 + V_458 ) ) {
do {
F_147 ( V_9 + V_458 ) ;
} while ( -- V_458 > 0 );
return 0 ;
}
}
return 1 ;
}
static void F_160 ( void )
{
int V_9 ;
F_161 (cpu) {
struct V_459 * V_460 = & F_162 ( V_461 , V_9 ) ;
F_104 ( & V_460 -> V_59 ) ;
F_106 ( & V_460 -> V_462 ) ;
}
}
static void F_163 ( struct V_2 * V_3 )
{
struct V_459 * V_460 = F_164 ( & V_461 ) ;
V_3 -> V_34 = V_463 ;
V_3 -> V_141 = F_10 () ;
if ( V_3 -> V_429 < F_101 () ) {
F_33 ( & V_460 -> V_59 ) ;
F_165 ( & V_3 -> V_381 , & V_460 -> V_462 ) ;
F_34 ( & V_460 -> V_59 ) ;
}
F_22 ( V_3 ) ;
}
static void F_166 ( struct V_2 * V_3 )
{
struct V_459 * V_460 ;
F_26 ( V_3 ) ;
if ( ! F_68 ( & V_3 -> V_381 ) ) {
V_460 = & F_162 ( V_461 , V_3 -> V_141 ) ;
F_33 ( & V_460 -> V_59 ) ;
F_167 ( & V_3 -> V_381 ) ;
F_34 ( & V_460 -> V_59 ) ;
}
V_3 -> V_34 = V_134 ;
}
static void F_168 ( struct V_464 * V_465 , struct V_2 * V_3 )
{
int V_466 ;
memset ( V_465 , 0 , sizeof( * V_465 ) ) ;
V_465 -> V_467 = 1 ;
V_465 -> V_468 = V_3 -> V_429 ;
V_465 -> V_469 = V_3 -> V_429 ;
V_465 -> V_470 [ 0 ] = V_3 -> V_429 ;
V_465 -> V_471 [ 0 ] = V_3 -> V_84 ;
for ( V_466 = 0 ; V_466 < V_472 ; ++ V_466 )
F_106 ( & V_465 -> V_473 [ V_466 ] ) ;
F_165 ( & V_3 -> V_381 , & V_465 -> V_473 [ 0 ] ) ;
}
static bool F_169 ( int V_467 , int V_457 )
{
if ( V_467 > 1 && V_376 < V_7 )
return false ;
if ( V_467 > V_472 )
return false ;
if ( V_467 > 1 ) {
if ( ! ( V_474 & 2 ) )
V_467 = 4 ;
if ( V_467 > 2 && ! ( V_474 & 4 ) )
return false ;
}
return V_467 * F_170 ( V_457 ) <= V_7 ;
}
static void F_171 ( struct V_2 * V_3 )
{
V_3 -> V_456 = V_3 ;
V_3 -> V_475 = 0 ;
V_3 -> V_476 = 0 ;
V_3 -> V_477 = 0 ;
V_3 -> V_478 = 0 ;
}
static bool F_172 ( struct V_2 * V_3 , struct V_464 * V_465 )
{
int V_457 = V_3 -> V_429 ;
int V_466 ;
if ( ! F_5 ( V_13 ) )
return false ;
if ( V_457 < V_465 -> V_468 )
V_457 = V_465 -> V_468 ;
if ( ! F_169 ( V_465 -> V_467 + 1 , V_457 ) )
return false ;
V_465 -> V_468 = V_457 ;
V_466 = V_465 -> V_467 ;
++ V_465 -> V_467 ;
V_465 -> V_469 += V_3 -> V_429 ;
V_465 -> V_470 [ V_466 ] = V_3 -> V_429 ;
V_465 -> V_471 [ V_466 ] = V_3 -> V_84 ;
F_171 ( V_3 ) ;
F_173 ( & V_3 -> V_381 , & V_465 -> V_473 [ V_466 ] ) ;
return true ;
}
static bool F_174 ( struct V_2 * V_479 , struct V_464 * V_465 ,
int V_480 )
{
if ( V_465 -> V_469 + V_479 -> V_429 > V_480 )
return false ;
return F_172 ( V_479 , V_465 ) ;
}
static void F_175 ( struct V_2 * V_3 )
{
int V_5 ;
struct V_1 * V_6 ;
F_176 (i, vcpu, vc) {
if ( F_177 ( V_6 -> V_25 . V_481 ) )
V_6 -> V_25 . V_88 = - V_482 ;
else if ( V_6 -> V_25 . V_90 . V_101 ||
V_6 -> V_25 . V_123 . V_101 ||
V_6 -> V_25 . V_122 . V_101 )
V_6 -> V_25 . V_88 = V_196 ;
else
continue;
F_144 ( V_3 , V_6 ) ;
F_178 ( & V_6 -> V_25 . V_426 ) ;
}
}
static void F_179 ( struct V_464 * V_465 , int V_480 )
{
struct V_459 * V_460 = F_164 ( & V_461 ) ;
struct V_2 * V_479 , * V_483 ;
F_33 ( & V_460 -> V_59 ) ;
F_180 (pvc, vcnext, &lp->list, preempt_list) {
if ( ! F_181 ( & V_479 -> V_59 ) )
continue;
F_175 ( V_479 ) ;
if ( ! V_479 -> V_440 ) {
F_167 ( & V_479 -> V_381 ) ;
if ( V_479 -> V_33 == NULL ) {
V_479 -> V_34 = V_134 ;
F_26 ( V_479 ) ;
}
F_34 ( & V_479 -> V_59 ) ;
continue;
}
if ( ! F_174 ( V_479 , V_465 , V_480 ) ) {
F_34 ( & V_479 -> V_59 ) ;
continue;
}
F_26 ( V_479 ) ;
V_479 -> V_34 = V_484 ;
if ( V_465 -> V_469 >= V_480 )
break;
}
F_34 ( & V_460 -> V_59 ) ;
}
static void F_182 ( struct V_2 * V_3 , bool V_485 )
{
int V_486 = 0 , V_5 ;
T_1 V_132 ;
long V_88 ;
struct V_1 * V_6 ;
F_33 ( & V_3 -> V_59 ) ;
V_132 = F_139 () ;
F_176 (i, vcpu, vc) {
if ( V_132 < V_6 -> V_25 . V_434 &&
F_183 ( V_6 ) )
F_184 ( V_6 ) ;
F_185 ( V_6 ) ;
V_88 = V_196 ;
if ( V_6 -> V_25 . V_64 )
V_88 = F_86 ( V_6 -> V_25 . V_198 , V_6 ,
V_6 -> V_25 . V_481 ) ;
V_6 -> V_25 . V_88 = V_88 ;
V_6 -> V_25 . V_64 = 0 ;
if ( F_186 ( V_6 -> V_25 . V_88 ) ) {
if ( V_6 -> V_25 . V_487 )
F_141 ( V_6 ) ;
if ( V_6 -> V_25 . V_176 )
F_138 ( V_6 ) ;
else
++ V_486 ;
} else {
F_144 ( V_3 , V_6 ) ;
F_178 ( & V_6 -> V_25 . V_426 ) ;
}
}
F_167 ( & V_3 -> V_381 ) ;
if ( ! V_485 ) {
if ( V_486 > 0 ) {
F_163 ( V_3 ) ;
} else if ( V_3 -> V_33 ) {
V_3 -> V_34 = V_463 ;
F_22 ( V_3 ) ;
} else {
V_3 -> V_34 = V_134 ;
}
if ( V_3 -> V_440 > 0 && V_3 -> V_33 == NULL ) {
V_5 = - 1 ;
V_6 = F_1 ( V_3 , & V_5 ) ;
F_178 ( & V_6 -> V_25 . V_426 ) ;
}
}
F_34 ( & V_3 -> V_59 ) ;
}
static inline int F_187 ( unsigned int V_9 )
{
int V_377 ;
if ( ! V_488 || F_11 ( V_9 ) )
return 0 ;
V_377 = V_9 >> V_489 ;
V_488 -> V_490 [ V_377 ] . V_491 . V_492 = 0 ;
return 0 ;
}
static inline int F_188 ( unsigned int V_9 )
{
int V_377 ;
if ( ! V_488 || F_11 ( V_9 ) )
return 0 ;
V_377 = V_9 >> V_489 ;
V_488 -> V_490 [ V_377 ] . V_491 . V_492 = 1 ;
return 0 ;
}
static T_8 void F_189 ( struct V_2 * V_3 )
{
struct V_1 * V_6 ;
int V_5 ;
int V_493 ;
struct V_464 V_464 ;
struct V_2 * V_479 , * V_483 ;
struct V_450 V_494 , * V_495 ;
int V_496 , V_497 , V_498 ;
int V_466 ;
bool V_499 ;
unsigned long V_500 , V_501 ;
int V_141 , V_458 ;
int V_480 ;
int V_502 ;
F_175 ( V_3 ) ;
if ( V_3 -> V_33 -> V_25 . V_37 != V_166 )
return;
F_171 ( V_3 ) ;
V_3 -> V_29 = V_30 ;
V_502 = F_101 () ;
if ( ( V_502 > 1 ) &&
( ( V_3 -> V_429 > V_376 ) || ! F_158 () ) ) {
F_176 (i, vcpu, vc) {
V_6 -> V_25 . V_88 = - V_449 ;
F_144 ( V_3 , V_6 ) ;
F_178 ( & V_6 -> V_25 . V_426 ) ;
}
goto V_414;
}
F_168 ( & V_464 , V_3 ) ;
V_141 = F_10 () ;
V_480 = V_502 ;
if ( V_503 && V_503 < V_480 )
V_480 = V_503 ;
if ( V_3 -> V_429 < V_480 )
F_179 ( & V_464 , V_480 ) ;
V_497 = V_376 ;
V_500 = V_501 = 0 ;
V_496 = V_464 . V_467 ;
V_495 = NULL ;
if ( V_496 > 1 ) {
if ( V_496 == 2 && ( V_474 & 2 ) ) {
V_500 = V_504 ;
V_501 = V_505 ;
} else {
V_496 = 4 ;
V_500 = V_506 ;
V_501 = V_507 ;
}
V_497 = V_7 / V_496 ;
V_495 = & V_494 ;
memset ( & V_494 , 0 , sizeof( V_494 ) ) ;
V_494 . V_508 = F_128 ( V_509 ) ;
V_494 . V_510 = F_128 ( V_511 ) ;
V_494 . V_512 = F_128 ( V_513 ) ;
V_494 . V_497 = V_497 ;
for ( V_466 = 0 ; V_466 < V_464 . V_467 ; ++ V_466 )
V_494 . V_514 [ V_466 ] =
F_190 ( & V_464 . V_473 [ V_466 ] ,
struct V_2 , V_381 ) ;
F_60 () ;
}
V_141 = F_10 () ;
for ( V_458 = 0 ; V_458 < V_502 ; ++ V_458 )
V_17 [ V_141 + V_458 ] . V_18 . V_450 = V_495 ;
if ( V_500 ) {
unsigned long V_515 = F_128 ( V_516 ) ;
V_515 |= V_500 | V_517 ;
F_191 () ;
F_192 ( V_516 , V_515 ) ;
F_193 () ;
for (; ; ) {
V_515 = F_128 ( V_516 ) ;
if ( V_515 & V_501 )
break;
F_194 () ;
}
}
F_187 ( V_141 ) ;
V_498 = 0 ;
for ( V_466 = 0 ; V_466 < V_464 . V_467 ; ++ V_466 ) {
V_458 = V_518 [ V_466 ] ;
V_499 = false ;
V_498 |= 1 << V_458 ;
F_195 (pvc, &core_info.vcs[sub], preempt_list) {
V_479 -> V_141 = V_141 + V_458 ;
F_176 (i, vcpu, pvc) {
F_153 ( V_6 , V_479 ) ;
F_54 ( V_6 , V_479 ) ;
F_196 ( V_6 ) ;
if ( ! V_6 -> V_25 . V_142 )
V_499 = true ;
V_498 |= 1 << ( V_458 + V_6 -> V_25 . V_142 ) ;
}
if ( V_479 -> V_456 == V_479 && ! V_499 )
F_153 ( NULL , V_479 ) ;
V_458 += V_479 -> V_429 ;
}
}
F_7 () ;
if ( V_500 )
V_494 . V_519 = 1 ;
if ( V_496 > 1 )
for ( V_458 = 1 ; V_458 < V_376 ; ++ V_458 )
if ( ! ( V_498 & ( 1 << V_458 ) ) )
F_3 ( V_141 + V_458 ) ;
V_3 -> V_34 = V_520 ;
F_8 () ;
F_197 ( V_3 , 0 ) ;
for ( V_466 = 0 ; V_466 < V_464 . V_467 ; ++ V_466 )
F_195 (pvc, &core_info.vcs[sub], preempt_list)
F_34 ( & V_479 -> V_59 ) ;
F_198 () ;
V_493 = F_69 ( & V_3 -> V_84 -> V_181 ) ;
F_199 () ;
F_71 ( & V_3 -> V_84 -> V_181 , V_493 ) ;
F_33 ( & V_3 -> V_59 ) ;
V_3 -> V_34 = V_521 ;
F_155 () ;
if ( V_496 > 1 ) {
unsigned long V_515 = F_128 ( V_516 ) ;
unsigned long V_396 = 0 ;
V_515 &= ~ V_517 ;
V_501 = V_505 | V_507 ;
F_191 () ;
F_192 ( V_516 , V_515 ) ;
F_193 () ;
for (; ; ) {
V_515 = F_128 ( V_516 ) ;
if ( ! ( V_515 & V_501 ) )
break;
F_194 () ;
++ V_396 ;
}
V_494 . V_519 = 0 ;
}
for ( V_5 = 0 ; V_5 < V_502 ; ++ V_5 ) {
F_147 ( V_141 + V_5 ) ;
if ( V_495 && V_495 -> V_522 [ V_5 ] )
F_3 ( V_141 + V_5 ) ;
F_200 ( V_141 + V_5 , & V_3 -> V_84 -> V_25 . V_454 ) ;
}
F_188 ( V_141 ) ;
F_34 ( & V_3 -> V_59 ) ;
F_7 () ;
F_201 () ;
for ( V_466 = 0 ; V_466 < V_464 . V_467 ; ++ V_466 )
F_180 (pvc, vcnext, &core_info.vcs[sub],
preempt_list)
F_182 ( V_479 , V_479 == V_3 ) ;
F_33 ( & V_3 -> V_59 ) ;
F_12 () ;
V_414:
V_3 -> V_34 = V_134 ;
F_197 ( V_3 , 1 ) ;
}
static void F_202 ( struct V_2 * V_3 ,
struct V_1 * V_6 , int V_523 )
{
F_203 ( V_524 ) ;
F_204 ( & V_6 -> V_25 . V_426 , & V_524 , V_523 ) ;
if ( V_6 -> V_25 . V_37 == V_166 ) {
F_34 ( & V_3 -> V_59 ) ;
F_205 () ;
F_33 ( & V_3 -> V_59 ) ;
}
F_206 ( & V_6 -> V_25 . V_426 , & V_524 ) ;
}
static void F_207 ( struct V_2 * V_3 )
{
if ( V_3 -> V_525 == 0 && V_526 )
V_3 -> V_525 = 10000 ;
else
V_3 -> V_525 *= V_526 ;
}
static void F_208 ( struct V_2 * V_3 )
{
if ( V_527 == 0 )
V_3 -> V_525 = 0 ;
else
V_3 -> V_525 /= V_527 ;
}
static int F_209 ( struct V_2 * V_3 )
{
struct V_1 * V_6 ;
int V_5 ;
F_176 (i, vcpu, vc) {
if ( V_6 -> V_25 . V_487 || ! V_6 -> V_25 . V_176 ||
V_6 -> V_25 . V_175 )
return 1 ;
}
return 0 ;
}
static void F_210 ( struct V_2 * V_3 )
{
T_9 V_528 , V_529 , V_530 ;
int V_531 = 1 ;
T_1 V_532 ;
F_211 ( V_524 ) ;
V_528 = V_529 = F_212 () ;
if ( V_3 -> V_525 ) {
T_9 V_533 = F_213 ( V_529 , V_3 -> V_525 ) ;
++ V_3 -> V_33 -> V_23 . V_534 ;
V_3 -> V_34 = V_535 ;
F_34 ( & V_3 -> V_59 ) ;
do {
if ( F_209 ( V_3 ) ) {
V_531 = 0 ;
break;
}
V_528 = F_212 () ;
} while ( F_214 () && F_215 ( V_528 , V_533 ) );
F_33 ( & V_3 -> V_59 ) ;
V_3 -> V_34 = V_134 ;
if ( ! V_531 ) {
++ V_3 -> V_33 -> V_23 . V_536 ;
goto V_414;
}
}
F_216 ( & V_3 -> V_379 , & V_524 , V_537 ) ;
if ( F_209 ( V_3 ) ) {
F_217 ( & V_3 -> V_379 , & V_524 ) ;
V_531 = 0 ;
if ( V_3 -> V_525 )
++ V_3 -> V_33 -> V_23 . V_536 ;
goto V_414;
}
V_530 = F_212 () ;
V_3 -> V_34 = V_35 ;
F_218 ( V_3 , 0 ) ;
F_34 ( & V_3 -> V_59 ) ;
F_205 () ;
F_217 ( & V_3 -> V_379 , & V_524 ) ;
F_33 ( & V_3 -> V_59 ) ;
V_3 -> V_34 = V_134 ;
F_218 ( V_3 , 1 ) ;
++ V_3 -> V_33 -> V_23 . V_538 ;
V_528 = F_212 () ;
V_414:
V_532 = F_219 ( V_528 ) - F_219 ( V_529 ) ;
if ( V_531 ) {
V_3 -> V_33 -> V_23 . V_539 +=
F_219 ( V_528 ) - F_219 ( V_530 ) ;
if ( V_3 -> V_525 )
V_3 -> V_33 -> V_23 . V_540 +=
F_219 ( V_530 ) -
F_219 ( V_529 ) ;
} else {
if ( V_3 -> V_525 )
V_3 -> V_33 -> V_23 . V_541 +=
F_219 ( V_528 ) -
F_219 ( V_529 ) ;
}
if ( V_525 ) {
if ( V_532 <= V_3 -> V_525 )
;
else if ( V_3 -> V_525 && V_532 > V_525 )
F_208 ( V_3 ) ;
else if ( V_3 -> V_525 < V_525 &&
V_532 < V_525 )
F_207 ( V_3 ) ;
if ( V_3 -> V_525 > V_525 )
V_3 -> V_525 = V_525 ;
} else
V_3 -> V_525 = 0 ;
F_220 ( V_531 , V_532 ) ;
}
static int F_221 ( struct V_198 * V_198 , struct V_1 * V_6 )
{
int V_542 , V_5 ;
struct V_2 * V_3 ;
struct V_1 * V_95 ;
F_222 ( V_6 ) ;
V_198 -> V_203 = 0 ;
V_6 -> V_25 . V_88 = V_196 ;
V_6 -> V_25 . V_64 = 0 ;
F_52 ( V_6 ) ;
V_3 = V_6 -> V_25 . V_32 ;
F_33 ( & V_3 -> V_59 ) ;
V_6 -> V_25 . V_176 = 0 ;
V_6 -> V_25 . V_481 = V_543 ;
V_6 -> V_25 . V_198 = V_198 ;
V_6 -> V_25 . V_138 = F_53 ( V_3 , F_24 () ) ;
V_6 -> V_25 . V_37 = V_166 ;
V_6 -> V_25 . V_39 = V_30 ;
F_145 ( V_3 -> V_8 [ V_6 -> V_25 . V_142 ] , V_6 ) ;
++ V_3 -> V_440 ;
if ( ! F_177 ( V_543 ) ) {
if ( V_3 -> V_34 == V_484 ) {
struct V_2 * V_455 = V_3 -> V_456 ;
if ( F_181 ( & V_455 -> V_59 ) ) {
if ( V_455 -> V_34 == V_520 &&
! F_223 ( V_455 ) ) {
F_54 ( V_6 , V_3 ) ;
F_153 ( V_6 , V_3 ) ;
F_196 ( V_6 ) ;
}
F_34 ( & V_455 -> V_59 ) ;
}
} else if ( V_3 -> V_34 == V_520 &&
! F_223 ( V_3 ) ) {
F_54 ( V_6 , V_3 ) ;
F_153 ( V_6 , V_3 ) ;
F_196 ( V_6 ) ;
} else if ( V_3 -> V_34 == V_35 ) {
F_19 ( & V_3 -> V_379 ) ;
}
}
while ( V_6 -> V_25 . V_37 == V_166 &&
! F_177 ( V_543 ) ) {
if ( V_3 -> V_34 == V_463 && V_3 -> V_33 == NULL )
F_166 ( V_3 ) ;
if ( V_3 -> V_34 != V_134 ) {
F_202 ( V_3 , V_6 , V_537 ) ;
continue;
}
F_176 (i, v, vc) {
F_141 ( V_95 ) ;
if ( F_177 ( V_95 -> V_25 . V_481 ) ) {
F_144 ( V_3 , V_95 ) ;
V_95 -> V_23 . V_544 ++ ;
V_95 -> V_25 . V_198 -> V_203 = V_545 ;
V_95 -> V_25 . V_88 = - V_482 ;
F_178 ( & V_95 -> V_25 . V_426 ) ;
}
}
if ( ! V_3 -> V_440 || V_6 -> V_25 . V_37 != V_166 )
break;
V_542 = 0 ;
F_176 (i, v, vc) {
if ( ! V_95 -> V_25 . V_487 && ! V_95 -> V_25 . V_175 )
V_542 += V_95 -> V_25 . V_176 ;
else
V_95 -> V_25 . V_176 = 0 ;
}
V_3 -> V_33 = V_6 ;
if ( V_542 == V_3 -> V_440 ) {
F_210 ( V_3 ) ;
} else if ( F_224 () ) {
F_163 ( V_3 ) ;
F_225 ( & V_3 -> V_59 ) ;
if ( V_3 -> V_34 == V_463 )
F_166 ( V_3 ) ;
} else {
F_189 ( V_3 ) ;
}
V_3 -> V_33 = NULL ;
}
while ( V_6 -> V_25 . V_37 == V_166 &&
( V_3 -> V_34 == V_520 ||
V_3 -> V_34 == V_521 ||
V_3 -> V_34 == V_484 ) )
F_202 ( V_3 , V_6 , V_546 ) ;
if ( V_3 -> V_34 == V_463 && V_3 -> V_33 == NULL )
F_166 ( V_3 ) ;
if ( V_6 -> V_25 . V_37 == V_166 ) {
F_144 ( V_3 , V_6 ) ;
V_6 -> V_23 . V_544 ++ ;
V_198 -> V_203 = V_545 ;
V_6 -> V_25 . V_88 = - V_482 ;
}
if ( V_3 -> V_440 && V_3 -> V_34 == V_134 ) {
V_5 = - 1 ;
V_95 = F_1 ( V_3 , & V_5 ) ;
F_178 ( & V_95 -> V_25 . V_426 ) ;
}
F_226 ( V_6 , V_198 ) ;
F_34 ( & V_3 -> V_59 ) ;
return V_6 -> V_25 . V_88 ;
}
static int F_227 ( struct V_198 * V_199 , struct V_1 * V_6 )
{
int V_61 ;
int V_493 ;
if ( ! V_6 -> V_25 . V_547 ) {
V_199 -> V_203 = V_213 ;
return - V_58 ;
}
F_141 ( V_6 ) ;
if ( F_177 ( V_543 ) ) {
V_199 -> V_203 = V_545 ;
return - V_482 ;
}
F_228 ( & V_6 -> V_84 -> V_25 . V_548 ) ;
F_7 () ;
if ( ! F_154 ( V_6 -> V_84 ) && ! V_6 -> V_84 -> V_25 . V_549 ) {
V_61 = F_229 ( V_6 ) ;
if ( V_61 )
goto V_414;
}
F_230 ( V_543 ) ;
V_6 -> V_25 . V_22 = & V_6 -> V_25 . V_32 -> V_379 ;
V_6 -> V_25 . V_550 = V_543 -> V_551 -> V_552 ;
V_6 -> V_25 . V_37 = V_38 ;
do {
V_61 = F_221 ( V_199 , V_6 ) ;
if ( V_199 -> V_203 == V_231 &&
! ( V_6 -> V_25 . V_43 . V_41 & V_553 ) ) {
F_231 ( V_6 ) ;
V_61 = F_66 ( V_6 ) ;
F_232 ( V_6 , V_61 ) ;
F_141 ( V_6 ) ;
} else if ( V_61 == V_233 ) {
V_493 = F_69 ( & V_6 -> V_84 -> V_181 ) ;
V_61 = F_233 ( V_199 , V_6 ,
V_6 -> V_25 . V_77 , V_6 -> V_25 . V_78 ) ;
F_71 ( & V_6 -> V_84 -> V_181 , V_493 ) ;
} else if ( V_61 == V_242 )
V_61 = F_234 ( V_6 , 0 ) ;
} while ( F_186 ( V_61 ) );
V_414:
V_6 -> V_25 . V_37 = V_425 ;
F_235 ( & V_6 -> V_84 -> V_25 . V_548 ) ;
return V_61 ;
}
static void F_236 ( struct V_554 * * V_555 ,
int V_556 )
{
struct V_557 * V_558 = & V_559 [ V_556 ] ;
if ( ! V_558 -> V_560 )
return;
( * V_555 ) -> V_561 = V_558 -> V_560 ;
( * V_555 ) -> V_562 = V_558 -> V_563 ;
( * V_555 ) -> V_564 [ 0 ] . V_561 = V_558 -> V_560 ;
( * V_555 ) -> V_564 [ 0 ] . V_565 = V_558 -> V_566 [ V_556 ] ;
if ( V_556 != V_567 && V_558 -> V_566 [ V_567 ] != - 1 ) {
( * V_555 ) -> V_564 [ 1 ] . V_561 = 24 ;
( * V_555 ) -> V_564 [ 1 ] . V_565 = V_558 -> V_566 [ V_567 ] ;
}
( * V_555 ) ++ ;
}
static int F_237 ( struct V_84 * V_84 ,
struct V_568 * V_569 )
{
struct V_554 * V_555 ;
if ( F_238 () )
return - V_58 ;
V_569 -> V_27 = V_570 ;
if ( F_239 ( V_571 ) )
V_569 -> V_27 |= V_572 ;
V_569 -> V_573 = V_574 ;
V_555 = & V_569 -> V_555 [ 0 ] ;
F_236 ( & V_555 , V_575 ) ;
F_236 ( & V_555 , V_576 ) ;
F_236 ( & V_555 , V_567 ) ;
return 0 ;
}
static int F_240 ( struct V_84 * V_84 ,
struct V_577 * log )
{
struct V_578 * V_579 ;
struct V_580 * V_581 ;
int V_5 , V_61 ;
unsigned long V_395 ;
unsigned long * V_388 ;
struct V_1 * V_6 ;
F_39 ( & V_84 -> V_582 ) ;
V_61 = - V_58 ;
if ( log -> V_583 >= V_584 )
goto V_414;
V_579 = V_578 ( V_84 ) ;
V_581 = F_241 ( V_579 , log -> V_583 ) ;
V_61 = - V_182 ;
if ( ! V_581 -> V_585 )
goto V_414;
V_395 = F_242 ( V_581 ) ;
V_388 = V_581 -> V_585 + V_395 / sizeof( long ) ;
memset ( V_388 , 0 , V_395 ) ;
if ( F_154 ( V_84 ) )
V_61 = F_243 ( V_84 , V_581 , V_388 ) ;
else
V_61 = F_244 ( V_84 , V_581 , V_388 ) ;
if ( V_61 )
goto V_414;
F_94 (i, vcpu, kvm) {
F_33 ( & V_6 -> V_25 . V_99 ) ;
F_245 ( & V_6 -> V_25 . V_90 , V_581 , V_388 ) ;
F_245 ( & V_6 -> V_25 . V_122 , V_581 , V_388 ) ;
F_34 ( & V_6 -> V_25 . V_99 ) ;
}
V_61 = - V_408 ;
if ( F_117 ( log -> V_585 , V_388 , V_395 ) )
goto V_414;
V_61 = 0 ;
V_414:
F_41 ( & V_84 -> V_582 ) ;
return V_61 ;
}
static void F_246 ( struct V_580 * free ,
struct V_580 * V_586 )
{
if ( ! V_586 || free -> V_25 . V_587 != V_586 -> V_25 . V_587 ) {
F_247 ( free -> V_25 . V_587 ) ;
free -> V_25 . V_587 = NULL ;
}
}
static int F_248 ( struct V_580 * V_583 ,
unsigned long V_588 )
{
if ( F_238 () ) {
V_583 -> V_25 . V_587 = NULL ;
return 0 ;
}
V_583 -> V_25 . V_587 = F_249 ( V_588 * sizeof( * V_583 -> V_25 . V_587 ) ) ;
if ( ! V_583 -> V_25 . V_587 )
return - V_386 ;
return 0 ;
}
static int F_250 ( struct V_84 * V_84 ,
struct V_580 * V_581 ,
const struct V_589 * V_590 )
{
return 0 ;
}
static void F_251 ( struct V_84 * V_84 ,
const struct V_589 * V_590 ,
const struct V_580 * V_591 ,
const struct V_580 * V_592 )
{
unsigned long V_588 = V_590 -> V_593 >> V_594 ;
struct V_578 * V_579 ;
struct V_580 * V_581 ;
if ( V_588 )
F_252 ( & V_84 -> V_25 . V_595 ) ;
if ( V_588 && V_591 -> V_588 && ! F_154 ( V_84 ) ) {
V_579 = V_578 ( V_84 ) ;
V_581 = F_241 ( V_579 , V_590 -> V_583 ) ;
F_244 ( V_84 , V_581 , NULL ) ;
}
}
void F_253 ( struct V_84 * V_84 , unsigned long V_83 , unsigned long V_255 )
{
long int V_5 ;
T_2 V_596 = 0 ;
if ( ( V_84 -> V_25 . V_83 & V_255 ) == V_83 )
return;
V_84 -> V_25 . V_83 = ( V_84 -> V_25 . V_83 & ~ V_255 ) | V_83 ;
for ( V_5 = 0 ; V_5 < V_413 ; ++ V_5 ) {
struct V_2 * V_3 = V_84 -> V_25 . V_427 [ V_5 ] ;
if ( ! V_3 )
continue;
F_33 ( & V_3 -> V_59 ) ;
V_3 -> V_83 = ( V_3 -> V_83 & ~ V_255 ) | V_83 ;
F_34 ( & V_3 -> V_59 ) ;
if ( ++ V_596 >= V_84 -> V_25 . V_428 )
break;
}
}
static void F_254 ( struct V_1 * V_6 )
{
return;
}
static void F_255 ( struct V_84 * V_84 )
{
unsigned long V_597 , V_598 ;
if ( ! F_154 ( V_84 ) ) {
V_597 = ( ( V_84 -> V_25 . V_599 & V_600 ) >> 1 ) |
( ( V_84 -> V_25 . V_599 & V_601 ) << 1 ) ;
V_597 |= V_84 -> V_25 . V_85 ;
V_598 = V_84 -> V_25 . V_602 ;
} else {
V_597 = V_603 | F_256 () |
F_257 ( V_84 -> V_25 . V_604 ) | V_605 ;
V_598 = V_606 | V_84 -> V_25 . V_602 ;
}
F_258 ( V_84 -> V_25 . V_607 , V_597 , V_598 ) ;
}
static int F_229 ( struct V_1 * V_6 )
{
int V_108 = 0 ;
struct V_84 * V_84 = V_6 -> V_84 ;
unsigned long V_608 ;
struct V_580 * V_581 ;
struct V_609 * V_610 ;
unsigned long V_83 = 0 , V_611 ;
unsigned long V_612 , V_613 ;
int V_493 ;
F_39 ( & V_84 -> V_59 ) ;
if ( V_84 -> V_25 . V_549 )
goto V_414;
if ( ! V_84 -> V_25 . V_614 . V_615 ) {
int V_616 = V_617 ;
struct V_618 V_569 ;
V_108 = F_259 ( & V_569 , V_616 ) ;
while ( ( V_108 == - V_386 ) && -- V_616 >= V_619 )
V_108 = F_259 ( & V_569 , V_616 ) ;
if ( V_108 < 0 ) {
F_36 ( L_22 ) ;
goto V_414;
}
F_260 ( V_84 , & V_569 ) ;
}
V_493 = F_69 ( & V_84 -> V_181 ) ;
V_581 = F_261 ( V_84 , 0 ) ;
V_108 = - V_58 ;
if ( ! V_581 || ( V_581 -> V_27 & V_620 ) )
goto V_621;
V_608 = V_581 -> V_622 ;
F_262 ( & V_543 -> V_551 -> V_623 ) ;
V_610 = F_263 ( V_543 -> V_551 , V_608 ) ;
if ( ! V_610 || V_610 -> V_624 > V_608 || ( V_610 -> V_625 & V_626 ) )
goto V_627;
V_612 = F_264 ( V_610 ) ;
V_613 = F_265 ( V_612 ) ;
F_266 ( & V_543 -> V_551 -> V_623 ) ;
V_108 = - V_58 ;
if ( ! ( V_612 == 0x1000 || V_612 == 0x10000 ||
V_612 == 0x1000000 ) )
goto V_621;
V_611 = F_267 ( V_612 ) ;
V_84 -> V_25 . V_599 = V_611 | V_628 |
( V_629 << V_630 ) ;
F_268 ( V_6 , V_581 , V_613 ) ;
if ( ! F_5 ( V_12 ) ) {
V_83 = V_611 << ( V_631 - 4 ) ;
F_253 ( V_84 , V_83 , V_632 ) ;
} else {
F_255 ( V_84 ) ;
}
F_60 () ;
V_84 -> V_25 . V_549 = 1 ;
V_108 = 0 ;
V_621:
F_71 ( & V_84 -> V_181 , V_493 ) ;
V_414:
F_41 ( & V_84 -> V_59 ) ;
return V_108 ;
V_627:
F_266 ( & V_543 -> V_551 -> V_623 ) ;
goto V_621;
}
void F_269 ( void )
{
struct V_633 * V_634 ;
unsigned long V_635 ;
int V_9 , V_377 ;
int V_636 ;
if ( V_488 != NULL )
return;
V_634 = F_103 ( sizeof( struct V_633 ) , V_378 ) ;
if ( ! V_634 )
return;
V_636 = F_270 () * sizeof( struct V_637 ) ;
V_634 -> V_490 = F_103 ( V_636 , V_378 ) ;
if ( ! V_634 -> V_490 ) {
F_112 ( V_634 ) ;
return;
}
F_271 () ;
for ( V_9 = 0 ; V_9 < V_16 ; V_9 += V_453 ) {
if ( ! F_20 ( V_9 ) )
continue;
V_377 = V_9 >> V_489 ;
V_634 -> V_490 [ V_377 ] . V_491 . V_492 = 1 ;
}
V_634 -> V_638 = F_16 ;
F_60 () ;
V_635 = ( unsigned long ) V_634 ;
if ( F_272 ( ( unsigned long * ) & V_488 , 0 , V_635 ) ) {
F_273 () ;
F_112 ( V_634 -> V_490 ) ;
F_112 ( V_634 ) ;
return;
}
F_274 ( V_639 ,
L_23 ,
F_188 ,
F_187 ) ;
F_273 () ;
}
void F_275 ( void )
{
if ( V_488 ) {
F_276 ( V_639 ) ;
F_112 ( V_488 -> V_490 ) ;
F_112 ( V_488 ) ;
V_488 = NULL ;
}
}
static int F_277 ( struct V_84 * V_84 )
{
unsigned long V_83 , V_607 ;
char V_388 [ 32 ] ;
int V_88 ;
V_607 = F_278 () ;
if ( ( long ) V_607 < 0 )
return - V_386 ;
V_84 -> V_25 . V_607 = V_607 ;
F_269 () ;
if ( ! F_5 ( V_12 ) )
F_279 ( & V_84 -> V_25 . V_452 ) ;
memcpy ( V_84 -> V_25 . V_171 , V_640 ,
sizeof( V_84 -> V_25 . V_171 ) ) ;
if ( ! F_5 ( V_12 ) )
V_84 -> V_25 . V_641 = F_128 ( V_642 ) ;
V_84 -> V_25 . V_643 = F_128 ( V_644 ) ;
V_84 -> V_25 . V_645 = V_83 = F_128 ( V_646 ) ;
V_83 &= V_647 | V_648 ;
V_83 |= ( 4UL << V_649 ) | V_650 |
V_651 | V_652 ;
V_84 -> V_25 . V_599 = V_628 |
( V_629 << V_630 ) ;
if ( F_5 ( V_13 ) )
V_83 |= V_653 ;
if ( F_5 ( V_12 ) ) {
V_83 &= ~ V_651 ;
V_83 |= V_654 ;
}
if ( F_238 () ) {
V_84 -> V_25 . V_655 = 1 ;
V_83 &= ~ V_652 ;
V_83 |= V_656 | V_657 | V_658 ;
V_88 = F_280 ( V_84 ) ;
if ( V_88 ) {
F_281 ( V_84 -> V_25 . V_607 ) ;
return V_88 ;
}
F_255 ( V_84 ) ;
}
V_84 -> V_25 . V_83 = V_83 ;
V_84 -> V_25 . V_659 = NULL ;
if ( F_154 ( V_84 ) )
V_84 -> V_25 . V_660 = V_661 ;
else if ( F_5 ( V_12 ) )
V_84 -> V_25 . V_660 = V_662 ;
else if ( F_5 ( V_13 ) )
V_84 -> V_25 . V_660 = V_663 ;
else
V_84 -> V_25 . V_660 = V_664 ;
if ( ! F_5 ( V_12 ) )
F_282 () ;
snprintf ( V_388 , sizeof( V_388 ) , L_24 , V_543 -> V_313 ) ;
V_84 -> V_25 . V_410 = F_121 ( V_388 , V_665 ) ;
if ( ! F_120 ( V_84 -> V_25 . V_410 ) )
F_283 ( V_84 ) ;
return 0 ;
}
static void F_284 ( struct V_84 * V_84 )
{
long int V_5 ;
for ( V_5 = 0 ; V_5 < V_413 ; ++ V_5 )
F_112 ( V_84 -> V_25 . V_427 [ V_5 ] ) ;
V_84 -> V_25 . V_428 = 0 ;
}
static void F_285 ( struct V_84 * V_84 )
{
F_286 ( V_84 -> V_25 . V_410 ) ;
if ( ! F_5 ( V_12 ) )
F_287 () ;
F_284 ( V_84 ) ;
F_281 ( V_84 -> V_25 . V_607 ) ;
if ( F_154 ( V_84 ) )
F_288 ( V_84 ) ;
else
F_289 ( & V_84 -> V_25 . V_614 ) ;
F_290 ( V_84 ) ;
}
static int F_291 ( struct V_198 * V_199 , struct V_1 * V_6 ,
unsigned int V_666 , int * V_667 )
{
return V_668 ;
}
static int F_292 ( struct V_1 * V_6 , int V_669 ,
T_3 V_670 )
{
return V_668 ;
}
static int F_293 ( struct V_1 * V_6 , int V_669 ,
T_3 * V_670 )
{
return V_668 ;
}
static int F_294 ( void )
{
if ( ! F_5 ( V_671 ) ||
! F_5 ( V_50 ) )
return - V_672 ;
return 0 ;
}
void F_290 ( struct V_84 * V_84 )
{
F_112 ( V_84 -> V_25 . V_673 ) ;
}
static struct V_674 * F_295 ( void )
{
return F_103 ( sizeof( struct V_674 ) , V_378 ) ;
}
static int F_296 ( struct V_84 * V_84 , int V_675 , int V_676 )
{
struct V_677 * V_678 ;
struct V_679 * V_680 ;
struct V_674 * V_673 ;
struct V_681 * V_682 ;
int V_5 ;
if ( ! V_683 )
return 1 ;
V_678 = F_297 ( V_675 ) ;
if ( ! V_678 )
return - V_672 ;
F_39 ( & V_84 -> V_59 ) ;
V_673 = V_84 -> V_25 . V_673 ;
if ( V_673 == NULL ) {
V_673 = F_295 () ;
if ( V_673 == NULL ) {
F_41 ( & V_84 -> V_59 ) ;
return - V_386 ;
}
V_84 -> V_25 . V_673 = V_673 ;
}
V_682 = F_298 ( & V_678 -> V_684 ) ;
if ( ! V_682 || ! F_299 ( V_682 ) ) {
F_300 ( L_25 ,
V_675 , V_676 ) ;
F_41 ( & V_84 -> V_59 ) ;
return - V_182 ;
}
for ( V_5 = 0 ; V_5 < V_673 -> V_685 ; V_5 ++ ) {
if ( V_676 == V_673 -> V_686 [ V_5 ] . V_687 ) {
if ( V_673 -> V_686 [ V_5 ] . V_688 ) {
F_41 ( & V_84 -> V_59 ) ;
return - V_58 ;
}
break;
}
}
if ( V_5 == V_689 ) {
F_41 ( & V_84 -> V_59 ) ;
return - V_690 ;
}
V_680 = & V_673 -> V_686 [ V_5 ] ;
V_680 -> V_687 = V_676 ;
V_680 -> V_678 = V_678 ;
F_60 () ;
V_680 -> V_688 = V_678 -> V_684 . V_691 ;
if ( V_5 == V_673 -> V_685 )
V_673 -> V_685 ++ ;
F_301 ( V_84 , V_676 , V_678 -> V_684 . V_691 ) ;
F_41 ( & V_84 -> V_59 ) ;
return 0 ;
}
static int F_302 ( struct V_84 * V_84 , int V_675 , int V_676 )
{
struct V_677 * V_678 ;
struct V_674 * V_673 ;
int V_5 ;
if ( ! V_683 )
return 0 ;
V_678 = F_297 ( V_675 ) ;
if ( ! V_678 )
return - V_672 ;
F_39 ( & V_84 -> V_59 ) ;
if ( V_84 -> V_25 . V_673 == NULL ) {
F_41 ( & V_84 -> V_59 ) ;
return 0 ;
}
V_673 = V_84 -> V_25 . V_673 ;
for ( V_5 = 0 ; V_5 < V_673 -> V_685 ; V_5 ++ ) {
if ( V_676 == V_673 -> V_686 [ V_5 ] . V_687 )
break;
}
if ( V_5 == V_673 -> V_685 ) {
F_41 ( & V_84 -> V_59 ) ;
return - V_692 ;
}
F_303 ( V_84 , V_676 , V_673 -> V_686 [ V_5 ] . V_688 ) ;
V_673 -> V_686 [ V_5 ] . V_688 = 0 ;
F_41 ( & V_84 -> V_59 ) ;
return 0 ;
}
static int F_304 ( struct V_693 * V_694 ,
struct V_695 * V_696 )
{
int V_88 = 0 ;
struct V_697 * V_698 =
F_305 ( V_694 , struct V_697 , V_699 ) ;
V_698 -> V_700 = V_696 ;
V_88 = F_296 ( V_698 -> V_84 , V_696 -> V_701 , V_698 -> V_702 ) ;
if ( V_88 )
F_306 ( L_26 ,
V_696 -> V_701 , V_698 -> V_702 , V_88 ) ;
return V_88 ;
}
static void F_307 ( struct V_693 * V_694 ,
struct V_695 * V_696 )
{
int V_88 ;
struct V_697 * V_698 =
F_305 ( V_694 , struct V_697 , V_699 ) ;
V_698 -> V_700 = NULL ;
V_88 = F_302 ( V_698 -> V_84 , V_696 -> V_701 , V_698 -> V_702 ) ;
if ( V_88 )
F_300 ( L_27 ,
V_696 -> V_701 , V_698 -> V_702 , V_88 ) ;
}
static long F_308 ( struct V_383 * V_703 ,
unsigned int V_704 , unsigned long V_705 )
{
struct V_84 * V_84 V_706 = V_703 -> V_387 ;
void T_5 * V_707 = ( void T_5 * ) V_705 ;
long V_61 ;
switch ( V_704 ) {
case V_708 : {
T_2 V_709 ;
V_61 = - V_408 ;
if ( F_309 ( V_709 , ( T_2 T_5 * ) V_707 ) )
break;
V_61 = F_310 ( V_84 , V_709 ) ;
if ( V_61 )
break;
V_61 = 0 ;
break;
}
case V_710 : {
struct V_711 V_712 ;
V_61 = - V_408 ;
if ( F_311 ( & V_712 , V_707 , sizeof( V_712 ) ) )
break;
V_61 = F_312 ( V_84 , & V_712 ) ;
break;
}
case V_713 : {
struct V_714 V_715 ;
V_61 = - V_408 ;
if ( F_311 ( & V_715 , V_707 , sizeof( V_715 ) ) )
break;
V_61 = F_313 ( V_84 , & V_715 ) ;
break;
}
case V_716 : {
struct V_714 V_715 ;
V_61 = - V_408 ;
if ( F_311 ( & V_715 , V_707 , sizeof( V_715 ) ) )
break;
V_61 = F_314 ( V_84 , & V_715 ) ;
break;
}
default:
V_61 = - V_717 ;
}
return V_61 ;
}
static void F_315 ( void )
{
int V_5 ;
unsigned int V_718 ;
for ( V_5 = 0 ; V_719 [ V_5 ] ; ++ V_5 ) {
V_718 = V_719 [ V_5 ] ;
F_316 ( ! F_80 ( V_718 ) ) ;
F_317 ( V_718 / 4 , V_640 ) ;
}
}
static int F_318 ( struct V_84 * V_84 , struct V_720 * V_721 )
{
unsigned long V_83 ;
int V_655 ;
if ( ! F_5 ( V_12 ) )
return - V_692 ;
if ( V_721 -> V_27 & ~ ( V_722 | V_723 ) )
return - V_58 ;
V_655 = ! ! ( V_721 -> V_27 & V_722 ) ;
if ( V_655 != F_154 ( V_84 ) )
return - V_58 ;
if ( ! ! ( V_721 -> V_602 & V_606 ) != V_655 )
return - V_58 ;
if ( ( V_721 -> V_602 & V_724 ) > 24 )
return - V_58 ;
V_84 -> V_25 . V_602 = V_721 -> V_602 ;
F_255 ( V_84 ) ;
V_83 = ( V_721 -> V_27 & V_723 ) ? V_657 : 0 ;
F_253 ( V_84 , V_83 , V_657 ) ;
return 0 ;
}
static int F_319 ( void )
{
int V_5 , V_250 ;
int V_725 = F_270 () ;
struct V_726 * V_726 ;
for ( V_5 = 0 ; V_5 < V_725 ; V_5 ++ ) {
int V_727 = V_5 * V_453 ;
int V_728 = F_320 ( V_727 ) ;
if ( V_17 [ V_727 ] . V_726 )
continue;
V_726 =
F_321 ( sizeof( struct V_726 ) ,
V_378 , V_728 ) ;
if ( ! V_726 )
return - V_386 ;
memset ( V_726 , 0 ,
sizeof( struct V_726 ) ) ;
for ( V_250 = 0 ; V_250 < V_453 ; V_250 ++ ) {
int V_9 = V_727 + V_250 ;
V_17 [ V_9 ] . V_726 = V_726 ;
}
}
return 0 ;
}
static int F_322 ( void )
{
return F_5 ( V_12 ) && F_238 () ;
}
static int F_323 ( void )
{
int V_61 ;
V_61 = F_294 () ;
if ( V_61 < 0 )
return - V_692 ;
V_61 = F_319 () ;
if ( V_61 )
return V_61 ;
#ifdef V_15
if ( ! F_324 () -> V_18 . V_19 ) {
struct V_729 * V_730 ;
V_730 = F_325 ( NULL , NULL , L_28 ) ;
if ( ! V_730 ) {
F_36 ( L_29 ) ;
return - V_692 ;
}
}
#endif
V_731 . V_732 = V_733 ;
V_734 = & V_731 ;
F_315 () ;
F_160 () ;
V_61 = F_326 () ;
if ( V_61 )
return V_61 ;
if ( F_322 () )
V_61 = F_327 () ;
return V_61 ;
}
static void F_328 ( void )
{
F_275 () ;
if ( F_322 () )
F_329 () ;
V_734 = NULL ;
}
