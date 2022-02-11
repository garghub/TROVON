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
if ( F_3 ( V_6 -> V_25 . V_26 ) )
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
if ( V_6 -> V_25 . V_176 ) {
if ( F_18 ( & V_6 -> V_177 ) ) {
F_19 ( & V_6 -> V_177 ) ;
V_6 -> V_23 . V_24 ++ ;
}
}
break;
case V_178 :
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
case V_179 :
V_88 = F_46 ( V_6 , F_37 ( V_6 , 4 ) ,
F_37 ( V_6 , 5 ) ,
F_37 ( V_6 , 6 ) ) ;
break;
case V_180 :
if ( F_68 ( & V_6 -> V_84 -> V_25 . V_181 ) )
return V_172 ;
V_168 = F_69 ( & V_6 -> V_84 -> V_182 ) ;
V_169 = F_70 ( V_6 ) ;
F_71 ( & V_6 -> V_84 -> V_182 , V_168 ) ;
if ( V_169 == - V_183 )
return V_172 ;
else if ( V_169 == 0 )
break;
return V_169 ;
case V_184 :
V_88 = F_72 ( V_6 ) ;
if ( V_88 == V_164 )
return V_172 ;
break;
case V_185 :
V_88 = F_73 ( V_6 ) ;
if ( V_88 == V_164 )
return V_172 ;
break;
case V_186 :
V_88 = F_62 ( V_6 , F_37 ( V_6 , 4 ) ,
F_37 ( V_6 , 5 ) ,
F_37 ( V_6 , 6 ) ,
F_37 ( V_6 , 7 ) ) ;
if ( V_88 == V_164 )
return V_172 ;
break;
case V_187 :
case V_188 :
case V_189 :
case V_190 :
case V_191 :
case V_192 :
if ( F_74 ( V_6 ) ) {
V_88 = F_75 ( V_6 , V_167 ) ;
break;
}
return V_172 ;
case V_193 :
V_88 = F_76 ( V_6 , F_37 ( V_6 , 4 ) ,
F_37 ( V_6 , 5 ) ,
F_37 ( V_6 , 6 ) ) ;
if ( V_88 == V_164 )
return V_172 ;
break;
case V_194 :
V_88 = F_77 ( V_6 , F_37 ( V_6 , 4 ) ,
F_37 ( V_6 , 5 ) ,
F_37 ( V_6 , 6 ) ,
F_37 ( V_6 , 7 ) ) ;
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
default:
return V_172 ;
}
F_79 ( V_6 , 3 , V_88 ) ;
V_6 -> V_25 . V_196 = 0 ;
return V_197 ;
}
static int F_80 ( unsigned long V_198 )
{
switch ( V_198 ) {
case V_173 :
case V_174 :
case V_178 :
case V_179 :
case V_186 :
case V_184 :
case V_185 :
#ifdef F_81
case V_187 :
case V_188 :
case V_189 :
case V_190 :
case V_191 :
case V_192 :
#endif
return 1 ;
}
return F_82 ( V_198 ) ;
}
static int F_83 ( struct V_199 * V_200 ,
struct V_1 * V_6 )
{
T_2 V_86 ;
if ( F_84 ( V_6 , V_201 , & V_86 ) !=
V_202 ) {
return V_197 ;
}
if ( V_86 == V_203 ) {
V_200 -> V_204 = V_205 ;
V_200 -> V_206 . V_25 . V_207 = F_59 ( V_6 ) ;
return V_172 ;
} else {
F_85 ( V_6 , V_208 ) ;
return V_197 ;
}
}
static int F_86 ( struct V_199 * V_200 , struct V_1 * V_6 ,
struct V_209 * V_210 )
{
int V_61 = V_172 ;
V_6 -> V_23 . V_211 ++ ;
if ( V_6 -> V_25 . V_43 . V_41 & V_212 ) {
F_87 ( V_213 L_14 ) ;
F_87 ( V_213 L_15 ,
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
V_61 = V_197 ;
break;
case V_221 :
case V_222 :
case V_223 :
V_6 -> V_23 . V_224 ++ ;
V_61 = V_197 ;
break;
case V_225 :
case V_226 :
V_61 = V_197 ;
break;
case V_227 :
F_88 ( V_6 ,
V_227 ) ;
V_61 = V_197 ;
break;
case V_228 :
{
T_3 V_27 ;
V_27 = V_6 -> V_25 . V_43 . V_41 & 0x1f0000ull ;
F_85 ( V_6 , V_27 ) ;
V_61 = V_197 ;
break;
}
case V_229 :
{
int V_5 ;
V_200 -> V_230 . V_231 = F_37 ( V_6 , 3 ) ;
for ( V_5 = 0 ; V_5 < 9 ; ++ V_5 )
V_200 -> V_230 . args [ V_5 ] = F_37 ( V_6 , 4 + V_5 ) ;
V_200 -> V_204 = V_232 ;
V_6 -> V_25 . V_196 = 1 ;
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
V_6 -> V_25 . V_86 = F_89 ( V_6 ) ?
F_90 ( V_6 -> V_25 . V_237 ) :
V_6 -> V_25 . V_237 ;
if ( V_6 -> V_239 & V_240 ) {
V_61 = F_83 ( V_200 , V_6 ) ;
} else {
F_85 ( V_6 , V_208 ) ;
V_61 = V_197 ;
}
break;
case V_241 :
F_85 ( V_6 , V_208 ) ;
V_61 = V_197 ;
break;
case V_242 :
V_61 = V_243 ;
break;
default:
F_35 ( V_6 ) ;
F_87 ( V_213 L_15 ,
V_6 -> V_25 . V_64 , F_59 ( V_6 ) ,
V_6 -> V_25 . V_43 . V_41 ) ;
V_200 -> V_215 . V_216 = V_6 -> V_25 . V_64 ;
V_61 = V_172 ;
break;
}
return V_61 ;
}
static int F_91 ( struct V_1 * V_6 ,
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
static int F_92 ( struct V_1 * V_6 ,
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
static void F_93 ( struct V_1 * V_6 , T_1 V_254 ,
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
F_94 (i, vcpu, kvm) {
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
static int F_95 ( struct V_1 * V_6 , T_1 V_87 ,
union V_263 * V_264 )
{
int V_61 = 0 ;
long int V_5 ;
switch ( V_87 ) {
case V_265 :
* V_264 = F_96 ( V_87 , V_203 ) ;
break;
case V_266 :
* V_264 = F_96 ( V_87 , 0 ) ;
break;
case V_267 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_268 ) ;
break;
case V_269 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_270 ) ;
break;
case V_271 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_272 ) ;
break;
case V_273 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_274 ) ;
break;
case V_275 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_276 ) ;
break;
case V_277 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_278 ) ;
break;
case V_279 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_280 ) ;
break;
case V_281 ... V_282 :
V_5 = V_87 - V_281 ;
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_283 [ V_5 ] ) ;
break;
case V_284 ... V_285 :
V_5 = V_87 - V_284 ;
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_286 [ V_5 ] ) ;
break;
case V_287 ... V_288 :
V_5 = V_87 - V_287 ;
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_289 [ V_5 ] ) ;
break;
case V_290 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_291 ) ;
break;
case V_292 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_293 ) ;
break;
case V_294 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_295 ) ;
break;
case V_296 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_297 ) ;
break;
case V_298 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_299 ) ;
break;
case V_300 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_32 -> V_301 ) ;
break;
case V_302 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_32 -> V_303 ) ;
break;
case V_304 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_162 ) ;
break;
case V_305 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_163 ) ;
break;
case V_306 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_158 ) ;
break;
case V_307 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_308 ) ;
break;
case V_309 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_310 ) ;
break;
case V_311 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_312 ) ;
break;
case V_313 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_314 ) ;
break;
case V_315 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_316 ) ;
break;
case V_317 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_318 ) ;
break;
case V_319 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_320 ) ;
break;
case V_321 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_322 ) ;
break;
case V_323 :
F_33 ( & V_6 -> V_25 . V_99 ) ;
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_90 . V_100 ) ;
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
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_32 -> V_144 ) ;
break;
case V_328 :
case V_329 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_32 -> V_83 ) ;
break;
case V_330 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_331 ) ;
break;
#ifdef F_97
case V_332 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_333 ) ;
break;
case V_334 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_335 ) ;
break;
case V_336 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_337 ) ;
break;
case V_338 ... V_339 :
V_5 = V_87 - V_338 ;
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_340 [ V_5 ] ) ;
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
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_353 ) ;
break;
case V_354 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_355 ) ;
break;
case V_356 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_357 ) ;
break;
case V_358 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_359 ) ;
break;
case V_360 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_345 . V_361 ) ;
break;
case V_362 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_363 ) ;
break;
case V_364 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_365 ) ;
break;
case V_366 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_367 ) ;
break;
case V_368 :
if ( F_5 ( V_347 ) )
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_349 . V_369 . V_246 [ 3 ] ) ;
else
V_61 = - V_351 ;
break;
case V_370 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_371 ) ;
break;
case V_372 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_373 ) ;
break;
#endif
case V_374 :
* V_264 = F_96 ( V_87 , V_6 -> V_25 . V_32 -> V_45 ) ;
break;
default:
V_61 = - V_58 ;
break;
}
return V_61 ;
}
static int F_98 ( struct V_1 * V_6 , T_1 V_87 ,
union V_263 * V_264 )
{
int V_61 = 0 ;
long int V_5 ;
unsigned long V_96 , V_97 ;
switch ( V_87 ) {
case V_266 :
if ( F_99 ( V_87 , * V_264 ) )
V_61 = - V_58 ;
break;
case V_267 :
V_6 -> V_25 . V_268 = F_99 ( V_87 , * V_264 ) ;
break;
case V_269 :
V_6 -> V_25 . V_270 = F_99 ( V_87 , * V_264 ) & ~ V_161 ;
break;
case V_271 :
V_6 -> V_25 . V_272 = F_99 ( V_87 , * V_264 ) ;
break;
case V_273 :
V_6 -> V_25 . V_274 = F_99 ( V_87 , * V_264 ) ;
break;
case V_275 :
V_6 -> V_25 . V_276 = F_99 ( V_87 , * V_264 ) ;
break;
case V_277 :
V_6 -> V_25 . V_278 = F_99 ( V_87 , * V_264 ) ;
break;
case V_279 :
V_6 -> V_25 . V_280 = F_99 ( V_87 , * V_264 ) ;
break;
case V_281 ... V_282 :
V_5 = V_87 - V_281 ;
V_6 -> V_25 . V_283 [ V_5 ] = F_99 ( V_87 , * V_264 ) ;
break;
case V_284 ... V_285 :
V_5 = V_87 - V_284 ;
V_6 -> V_25 . V_286 [ V_5 ] = F_99 ( V_87 , * V_264 ) ;
break;
case V_287 ... V_288 :
V_5 = V_87 - V_287 ;
V_6 -> V_25 . V_289 [ V_5 ] = F_99 ( V_87 , * V_264 ) ;
break;
case V_290 :
V_6 -> V_25 . V_291 = F_99 ( V_87 , * V_264 ) ;
break;
case V_292 :
V_6 -> V_25 . V_293 = F_99 ( V_87 , * V_264 ) ;
break;
case V_294 :
V_6 -> V_25 . V_295 = F_99 ( V_87 , * V_264 ) ;
break;
case V_296 :
V_6 -> V_25 . V_297 = F_99 ( V_87 , * V_264 ) ;
break;
case V_298 :
V_6 -> V_25 . V_299 = F_99 ( V_87 , * V_264 ) ;
break;
case V_300 :
V_6 -> V_25 . V_32 -> V_301 = F_99 ( V_87 , * V_264 ) ;
break;
case V_302 :
V_6 -> V_25 . V_32 -> V_303 = F_99 ( V_87 , * V_264 ) ;
break;
case V_304 :
V_6 -> V_25 . V_162 = F_99 ( V_87 , * V_264 ) ;
break;
case V_305 :
V_6 -> V_25 . V_163 = F_99 ( V_87 , * V_264 ) & ~ V_375 ;
break;
case V_306 :
V_6 -> V_25 . V_158 = F_99 ( V_87 , * V_264 ) ;
if ( ( V_6 -> V_25 . V_158 & V_155 ) == V_156 )
V_6 -> V_25 . V_158 &= ~ V_155 ;
break;
case V_307 :
V_6 -> V_25 . V_308 = F_99 ( V_87 , * V_264 ) ;
break;
case V_309 :
V_6 -> V_25 . V_310 = F_99 ( V_87 , * V_264 ) ;
break;
case V_311 :
V_6 -> V_25 . V_312 = F_99 ( V_87 , * V_264 ) ;
break;
case V_313 :
V_6 -> V_25 . V_314 = F_99 ( V_87 , * V_264 ) ;
break;
case V_315 :
V_6 -> V_25 . V_316 = F_99 ( V_87 , * V_264 ) ;
break;
case V_317 :
V_6 -> V_25 . V_318 = F_99 ( V_87 , * V_264 ) ;
break;
case V_319 :
V_6 -> V_25 . V_320 = F_99 ( V_87 , * V_264 ) ;
break;
case V_321 :
V_6 -> V_25 . V_322 = F_99 ( V_87 , * V_264 ) & V_376 ;
break;
case V_323 :
V_96 = F_99 ( V_87 , * V_264 ) ;
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
V_6 -> V_25 . V_32 -> V_144 =
F_100 ( F_99 ( V_87 , * V_264 ) , 1UL << 24 ) ;
break;
case V_328 :
F_93 ( V_6 , F_99 ( V_87 , * V_264 ) , true ) ;
break;
case V_329 :
F_93 ( V_6 , F_99 ( V_87 , * V_264 ) , false ) ;
break;
case V_330 :
V_6 -> V_25 . V_331 = F_99 ( V_87 , * V_264 ) ;
break;
#ifdef F_97
case V_332 :
V_6 -> V_25 . V_333 = F_99 ( V_87 , * V_264 ) ;
break;
case V_334 :
V_6 -> V_25 . V_335 = F_99 ( V_87 , * V_264 ) ;
break;
case V_336 :
V_6 -> V_25 . V_337 = F_99 ( V_87 , * V_264 ) ;
break;
case V_338 ... V_339 :
V_5 = V_87 - V_338 ;
V_6 -> V_25 . V_340 [ V_5 ] = F_99 ( V_87 , * V_264 ) ;
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
V_6 -> V_25 . V_353 = F_99 ( V_87 , * V_264 ) ;
break;
case V_354 :
V_6 -> V_25 . V_355 = F_99 ( V_87 , * V_264 ) ;
break;
case V_356 :
V_6 -> V_25 . V_357 = F_99 ( V_87 , * V_264 ) ;
break;
case V_358 :
V_6 -> V_25 . V_359 = F_99 ( V_87 , * V_264 ) ;
break;
case V_360 :
V_6 -> V_25 . V_345 . V_361 = F_99 ( V_87 , * V_264 ) ;
break;
case V_362 :
V_6 -> V_25 . V_363 = F_99 ( V_87 , * V_264 ) ;
break;
case V_364 :
V_6 -> V_25 . V_365 = F_99 ( V_87 , * V_264 ) ;
break;
case V_366 :
V_6 -> V_25 . V_367 = F_99 ( V_87 , * V_264 ) ;
break;
case V_368 :
if ( F_5 ( V_347 ) )
V_6 -> V_25 . V_350 . V_369 . V_246 [ 3 ] = F_99 ( V_87 , * V_264 ) ;
else
V_61 = - V_351 ;
break;
case V_370 :
V_6 -> V_25 . V_371 = F_99 ( V_87 , * V_264 ) ;
break;
case V_372 :
V_6 -> V_25 . V_373 = F_99 ( V_87 , * V_264 ) ;
break;
#endif
case V_374 :
V_61 = F_32 ( V_6 , F_99 ( V_87 , * V_264 ) ) ;
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
return V_377 ;
}
static struct V_2 * F_102 ( struct V_84 * V_84 , int V_378 )
{
struct V_2 * V_32 ;
V_32 = F_103 ( sizeof( struct V_2 ) , V_379 ) ;
if ( V_32 == NULL )
return NULL ;
F_104 ( & V_32 -> V_59 ) ;
F_104 ( & V_32 -> V_28 ) ;
F_105 ( & V_32 -> V_177 ) ;
V_32 -> V_29 = V_30 ;
V_32 -> V_83 = V_84 -> V_25 . V_83 ;
V_32 -> V_380 = V_378 * F_101 () ;
V_32 -> V_84 = V_84 ;
F_106 ( & V_32 -> V_381 ) ;
return V_32 ;
}
static int F_107 ( struct V_382 * V_382 , struct V_383 * V_383 )
{
struct V_1 * V_6 = V_382 -> V_384 ;
struct V_385 * V_133 ;
V_133 = F_103 ( sizeof( * V_133 ) , V_379 ) ;
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
char * V_247 , * V_390 ;
struct V_391 V_392 ;
T_1 V_393 ;
T_7 V_394 ;
T_4 V_395 ;
int V_5 , V_396 ;
bool V_397 ;
if ( ! V_133 -> V_398 ) {
V_247 = V_133 -> V_388 ;
V_390 = V_247 + sizeof( V_133 -> V_388 ) ;
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
snprintf ( V_247 , V_390 - V_247 , L_16 ,
V_401 [ V_5 ] . V_404 ) ;
else
snprintf ( V_247 , V_390 - V_247 ,
L_17 ,
V_401 [ V_5 ] . V_404 , V_393 / 2 ,
F_116 ( V_392 . V_405 ) ,
F_116 ( V_392 . V_406 ) ,
F_116 ( V_392 . V_407 ) ) ;
V_247 += strlen ( V_247 ) ;
}
V_133 -> V_398 = V_247 - V_133 -> V_388 ;
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
int V_378 ;
struct V_2 * V_32 ;
V_378 = V_87 / F_101 () ;
if ( V_378 >= V_413 )
goto V_414;
V_108 = - V_386 ;
V_6 = F_124 ( V_415 , V_379 ) ;
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
V_6 -> V_25 . V_283 [ 0 ] = V_419 ;
V_6 -> V_25 . V_420 = V_421 ;
F_31 ( V_6 , F_128 ( V_422 ) ) ;
F_104 ( & V_6 -> V_25 . V_99 ) ;
F_104 ( & V_6 -> V_25 . V_36 ) ;
V_6 -> V_25 . V_39 = V_30 ;
V_6 -> V_25 . V_258 = V_423 | V_424 ;
F_129 ( V_6 ) ;
V_6 -> V_25 . V_37 = V_425 ;
F_130 ( & V_6 -> V_25 . V_426 ) ;
F_39 ( & V_84 -> V_59 ) ;
V_32 = V_84 -> V_25 . V_427 [ V_378 ] ;
if ( ! V_32 ) {
V_32 = F_102 ( V_84 , V_378 ) ;
V_84 -> V_25 . V_427 [ V_378 ] = V_32 ;
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
V_6 -> V_25 . V_430 = V_431 ;
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
unsigned long V_432 , V_132 ;
V_132 = F_139 () ;
if ( V_132 > V_6 -> V_25 . V_433 ) {
F_140 ( V_6 ) ;
F_141 ( V_6 ) ;
return;
}
V_432 = ( V_6 -> V_25 . V_433 - V_132 ) * V_434
/ V_435 ;
F_142 ( & V_6 -> V_25 . V_436 , V_432 , V_437 ) ;
V_6 -> V_25 . V_438 = 1 ;
}
static void F_30 ( struct V_1 * V_6 )
{
V_6 -> V_25 . V_176 = 0 ;
if ( V_6 -> V_25 . V_438 ) {
F_143 ( & V_6 -> V_25 . V_436 ) ;
V_6 -> V_25 . V_438 = 0 ;
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
-- V_3 -> V_439 ;
F_145 ( V_3 -> V_8 [ V_6 -> V_25 . V_142 ] , NULL ) ;
}
static int F_146 ( int V_9 )
{
struct V_440 * V_441 ;
long V_442 = 10000 ;
V_441 = & V_17 [ V_9 ] ;
V_441 -> V_18 . V_1 = NULL ;
V_441 -> V_18 . V_443 = NULL ;
V_441 -> V_18 . V_444 = 0 ;
F_60 () ;
V_441 -> V_18 . V_445 = 1 ;
F_7 () ;
while ( V_441 -> V_18 . V_446 == V_447 ) {
if ( -- V_442 <= 0 ) {
F_36 ( L_20 , V_9 ) ;
return - V_448 ;
}
F_115 ( 1 ) ;
}
return 0 ;
}
static void F_147 ( int V_9 )
{
struct V_440 * V_441 ;
V_441 = & V_17 [ V_9 ] ;
V_441 -> V_18 . V_445 = 0 ;
V_441 -> V_18 . V_1 = NULL ;
V_441 -> V_18 . V_443 = NULL ;
V_441 -> V_18 . V_449 = NULL ;
}
static void F_148 ( struct V_1 * V_6 , struct V_2 * V_3 )
{
int V_9 ;
struct V_440 * V_441 ;
struct V_2 * V_450 = V_3 -> V_451 ;
V_9 = V_3 -> V_141 ;
if ( V_6 ) {
if ( V_6 -> V_25 . V_438 ) {
F_143 ( & V_6 -> V_25 . V_436 ) ;
V_6 -> V_25 . V_438 = 0 ;
}
V_9 += V_6 -> V_25 . V_142 ;
V_6 -> V_9 = V_450 -> V_141 ;
V_6 -> V_25 . V_26 = V_9 ;
}
V_441 = & V_17 [ V_9 ] ;
V_441 -> V_18 . V_1 = V_6 ;
V_441 -> V_18 . V_142 = V_9 - V_450 -> V_141 ;
F_60 () ;
V_441 -> V_18 . V_443 = V_450 ;
if ( V_9 != F_10 () )
F_3 ( V_9 ) ;
}
static void F_149 ( void )
{
int V_9 = F_10 () ;
int V_5 , V_396 ;
int V_452 = F_101 () ;
if ( V_452 <= 1 )
return;
for ( V_396 = 0 ; V_396 < 1000000 ; ++ V_396 ) {
for ( V_5 = 1 ; V_5 < V_452 ; ++ V_5 )
if ( V_17 [ V_9 + V_5 ] . V_18 . V_443 )
break;
if ( V_5 == V_452 ) {
F_150 () ;
return;
}
F_151 () ;
}
F_150 () ;
for ( V_5 = 1 ; V_5 < V_452 ; ++ V_5 )
if ( V_17 [ V_9 + V_5 ] . V_18 . V_443 )
F_36 ( L_21 , V_9 + V_5 ) ;
}
static int F_152 ( void )
{
int V_9 = F_10 () ;
int V_453 ;
if ( F_153 ( V_9 ) )
return 0 ;
V_453 = 0 ;
while ( ++ V_453 < V_377 )
if ( F_20 ( V_9 + V_453 ) )
return 0 ;
for ( V_453 = 1 ; V_453 < V_377 ; ++ V_453 ) {
if ( F_146 ( V_9 + V_453 ) ) {
do {
F_147 ( V_9 + V_453 ) ;
} while ( -- V_453 > 0 );
return 0 ;
}
}
return 1 ;
}
static void F_154 ( void )
{
int V_9 ;
F_155 (cpu) {
struct V_454 * V_455 = & F_156 ( V_456 , V_9 ) ;
F_104 ( & V_455 -> V_59 ) ;
F_106 ( & V_455 -> V_457 ) ;
}
}
static void F_157 ( struct V_2 * V_3 )
{
struct V_454 * V_455 = F_158 ( & V_456 ) ;
V_3 -> V_34 = V_458 ;
V_3 -> V_141 = F_10 () ;
if ( V_3 -> V_429 < F_101 () ) {
F_33 ( & V_455 -> V_59 ) ;
F_159 ( & V_3 -> V_381 , & V_455 -> V_457 ) ;
F_34 ( & V_455 -> V_59 ) ;
}
F_22 ( V_3 ) ;
}
static void F_160 ( struct V_2 * V_3 )
{
struct V_454 * V_455 ;
F_26 ( V_3 ) ;
if ( ! F_68 ( & V_3 -> V_381 ) ) {
V_455 = & F_156 ( V_456 , V_3 -> V_141 ) ;
F_33 ( & V_455 -> V_59 ) ;
F_161 ( & V_3 -> V_381 ) ;
F_34 ( & V_455 -> V_59 ) ;
}
V_3 -> V_34 = V_134 ;
}
static void F_162 ( struct V_459 * V_460 , struct V_2 * V_3 )
{
int V_461 ;
memset ( V_460 , 0 , sizeof( * V_460 ) ) ;
V_460 -> V_462 = 1 ;
V_460 -> V_463 = V_3 -> V_429 ;
V_460 -> V_464 = V_3 -> V_429 ;
V_460 -> V_465 [ 0 ] = V_3 -> V_429 ;
V_460 -> V_466 [ 0 ] = V_3 -> V_84 ;
for ( V_461 = 0 ; V_461 < V_467 ; ++ V_461 )
F_106 ( & V_460 -> V_468 [ V_461 ] ) ;
F_159 ( & V_3 -> V_381 , & V_460 -> V_468 [ 0 ] ) ;
}
static bool F_163 ( int V_462 , int V_452 )
{
if ( V_462 > 1 && V_377 < V_7 )
return false ;
if ( V_462 > V_467 )
return false ;
if ( V_462 > 1 ) {
if ( ! ( V_469 & 2 ) )
V_462 = 4 ;
if ( V_462 > 2 && ! ( V_469 & 4 ) )
return false ;
}
return V_462 * F_164 ( V_452 ) <= V_7 ;
}
static void F_165 ( struct V_2 * V_3 )
{
V_3 -> V_451 = V_3 ;
V_3 -> V_470 = 0 ;
V_3 -> V_471 = 0 ;
V_3 -> V_472 = 0 ;
V_3 -> V_473 = 0 ;
}
static bool F_166 ( struct V_2 * V_3 , struct V_459 * V_460 )
{
int V_452 = V_3 -> V_429 ;
int V_461 ;
if ( ! F_5 ( V_13 ) )
return false ;
if ( V_452 < V_460 -> V_463 )
V_452 = V_460 -> V_463 ;
if ( ! F_163 ( V_460 -> V_462 + 1 , V_452 ) )
return false ;
V_460 -> V_463 = V_452 ;
V_461 = V_460 -> V_462 ;
++ V_460 -> V_462 ;
V_460 -> V_464 += V_3 -> V_429 ;
V_460 -> V_465 [ V_461 ] = V_3 -> V_429 ;
V_460 -> V_466 [ V_461 ] = V_3 -> V_84 ;
F_165 ( V_3 ) ;
F_167 ( & V_3 -> V_381 , & V_460 -> V_468 [ V_461 ] ) ;
return true ;
}
static bool F_168 ( struct V_2 * V_474 , struct V_459 * V_460 ,
int V_475 )
{
if ( V_460 -> V_464 + V_474 -> V_429 > V_475 )
return false ;
return F_166 ( V_474 , V_460 ) ;
}
static void F_169 ( struct V_2 * V_3 )
{
int V_5 ;
struct V_1 * V_6 ;
F_170 (i, vcpu, vc) {
if ( F_171 ( V_6 -> V_25 . V_476 ) )
V_6 -> V_25 . V_88 = - V_477 ;
else if ( V_6 -> V_25 . V_90 . V_101 ||
V_6 -> V_25 . V_123 . V_101 ||
V_6 -> V_25 . V_122 . V_101 )
V_6 -> V_25 . V_88 = V_197 ;
else
continue;
F_144 ( V_3 , V_6 ) ;
F_172 ( & V_6 -> V_25 . V_426 ) ;
}
}
static void F_173 ( struct V_459 * V_460 , int V_475 )
{
struct V_454 * V_455 = F_158 ( & V_456 ) ;
struct V_2 * V_474 , * V_478 ;
F_33 ( & V_455 -> V_59 ) ;
F_174 (pvc, vcnext, &lp->list, preempt_list) {
if ( ! F_175 ( & V_474 -> V_59 ) )
continue;
F_169 ( V_474 ) ;
if ( ! V_474 -> V_439 ) {
F_161 ( & V_474 -> V_381 ) ;
if ( V_474 -> V_33 == NULL ) {
V_474 -> V_34 = V_134 ;
F_26 ( V_474 ) ;
}
F_34 ( & V_474 -> V_59 ) ;
continue;
}
if ( ! F_168 ( V_474 , V_460 , V_475 ) ) {
F_34 ( & V_474 -> V_59 ) ;
continue;
}
F_26 ( V_474 ) ;
V_474 -> V_34 = V_479 ;
if ( V_460 -> V_464 >= V_475 )
break;
}
F_34 ( & V_455 -> V_59 ) ;
}
static void F_176 ( struct V_2 * V_3 , bool V_480 )
{
int V_481 = 0 , V_5 ;
T_1 V_132 ;
long V_88 ;
struct V_1 * V_6 ;
F_33 ( & V_3 -> V_59 ) ;
V_132 = F_139 () ;
F_170 (i, vcpu, vc) {
if ( V_132 < V_6 -> V_25 . V_433 &&
F_177 ( V_6 ) )
F_178 ( V_6 ) ;
F_179 ( V_6 ) ;
V_88 = V_197 ;
if ( V_6 -> V_25 . V_64 )
V_88 = F_86 ( V_6 -> V_25 . V_199 , V_6 ,
V_6 -> V_25 . V_476 ) ;
V_6 -> V_25 . V_88 = V_88 ;
V_6 -> V_25 . V_64 = 0 ;
if ( F_180 ( V_6 -> V_25 . V_88 ) ) {
if ( V_6 -> V_25 . V_482 )
F_141 ( V_6 ) ;
if ( V_6 -> V_25 . V_176 )
F_138 ( V_6 ) ;
else
++ V_481 ;
} else {
F_144 ( V_3 , V_6 ) ;
F_172 ( & V_6 -> V_25 . V_426 ) ;
}
}
F_161 ( & V_3 -> V_381 ) ;
if ( ! V_480 ) {
if ( V_481 > 0 ) {
F_157 ( V_3 ) ;
} else if ( V_3 -> V_33 ) {
V_3 -> V_34 = V_458 ;
F_22 ( V_3 ) ;
} else {
V_3 -> V_34 = V_134 ;
}
if ( V_3 -> V_439 > 0 && V_3 -> V_33 == NULL ) {
V_5 = - 1 ;
V_6 = F_1 ( V_3 , & V_5 ) ;
F_172 ( & V_6 -> V_25 . V_426 ) ;
}
}
F_34 ( & V_3 -> V_59 ) ;
}
static inline int F_181 ( unsigned int V_9 )
{
int V_378 ;
if ( ! V_483 || F_11 ( V_9 ) )
return 0 ;
V_378 = V_9 >> V_484 ;
V_483 -> V_485 [ V_378 ] . V_486 . V_487 = 0 ;
return 0 ;
}
static inline int F_182 ( unsigned int V_9 )
{
int V_378 ;
if ( ! V_483 || F_11 ( V_9 ) )
return 0 ;
V_378 = V_9 >> V_484 ;
V_483 -> V_485 [ V_378 ] . V_486 . V_487 = 1 ;
return 0 ;
}
static T_8 void F_183 ( struct V_2 * V_3 )
{
struct V_1 * V_6 ;
int V_5 ;
int V_488 ;
struct V_459 V_459 ;
struct V_2 * V_474 , * V_478 ;
struct V_449 V_489 , * V_490 ;
int V_491 , V_492 , V_493 ;
int V_461 ;
bool V_494 ;
unsigned long V_495 , V_496 ;
int V_141 , V_453 ;
int V_475 ;
int V_497 ;
F_169 ( V_3 ) ;
if ( V_3 -> V_33 -> V_25 . V_37 != V_166 )
return;
F_165 ( V_3 ) ;
V_3 -> V_29 = V_30 ;
V_497 = F_101 () ;
if ( ( V_497 > 1 ) &&
( ( V_3 -> V_429 > V_377 ) || ! F_152 () ) ) {
F_170 (i, vcpu, vc) {
V_6 -> V_25 . V_88 = - V_448 ;
F_144 ( V_3 , V_6 ) ;
F_172 ( & V_6 -> V_25 . V_426 ) ;
}
goto V_414;
}
F_162 ( & V_459 , V_3 ) ;
V_141 = F_10 () ;
V_475 = V_497 ;
if ( V_498 && V_498 < V_475 )
V_475 = V_498 ;
if ( V_3 -> V_429 < V_475 )
F_173 ( & V_459 , V_475 ) ;
V_492 = V_377 ;
V_495 = V_496 = 0 ;
V_491 = V_459 . V_462 ;
V_490 = NULL ;
if ( V_491 > 1 ) {
if ( V_491 == 2 && ( V_469 & 2 ) ) {
V_495 = V_499 ;
V_496 = V_500 ;
} else {
V_491 = 4 ;
V_495 = V_501 ;
V_496 = V_502 ;
}
V_492 = V_7 / V_491 ;
V_490 = & V_489 ;
memset ( & V_489 , 0 , sizeof( V_489 ) ) ;
V_489 . V_503 = F_128 ( V_504 ) ;
V_489 . V_505 = F_128 ( V_506 ) ;
V_489 . V_507 = F_128 ( V_508 ) ;
V_489 . V_492 = V_492 ;
for ( V_461 = 0 ; V_461 < V_459 . V_462 ; ++ V_461 )
V_489 . V_509 [ V_461 ] =
F_184 ( & V_459 . V_468 [ V_461 ] ,
struct V_2 , V_381 ) ;
F_60 () ;
}
V_141 = F_10 () ;
for ( V_453 = 0 ; V_453 < V_497 ; ++ V_453 )
V_17 [ V_141 + V_453 ] . V_18 . V_449 = V_490 ;
if ( V_495 ) {
unsigned long V_510 = F_128 ( V_511 ) ;
V_510 |= V_495 | V_512 ;
F_185 () ;
F_186 ( V_511 , V_510 ) ;
F_187 () ;
for (; ; ) {
V_510 = F_128 ( V_511 ) ;
if ( V_510 & V_496 )
break;
F_188 () ;
}
}
F_181 ( V_141 ) ;
V_493 = 0 ;
for ( V_461 = 0 ; V_461 < V_459 . V_462 ; ++ V_461 ) {
V_453 = V_513 [ V_461 ] ;
V_494 = false ;
V_493 |= 1 << V_453 ;
F_189 (pvc, &core_info.vcs[sub], preempt_list) {
V_474 -> V_141 = V_141 + V_453 ;
F_170 (i, vcpu, pvc) {
F_148 ( V_6 , V_474 ) ;
F_54 ( V_6 , V_474 ) ;
F_190 ( V_6 ) ;
if ( ! V_6 -> V_25 . V_142 )
V_494 = true ;
V_493 |= 1 << ( V_453 + V_6 -> V_25 . V_142 ) ;
}
if ( V_474 -> V_451 == V_474 && ! V_494 )
F_148 ( NULL , V_474 ) ;
V_453 += V_474 -> V_429 ;
}
}
F_7 () ;
if ( V_495 )
V_489 . V_514 = 1 ;
if ( V_491 > 1 )
for ( V_453 = 1 ; V_453 < V_377 ; ++ V_453 )
if ( ! ( V_493 & ( 1 << V_453 ) ) )
F_3 ( V_141 + V_453 ) ;
V_3 -> V_34 = V_515 ;
F_8 () ;
F_191 ( V_3 , 0 ) ;
for ( V_461 = 0 ; V_461 < V_459 . V_462 ; ++ V_461 )
F_189 (pvc, &core_info.vcs[sub], preempt_list)
F_34 ( & V_474 -> V_59 ) ;
F_192 () ;
V_488 = F_69 ( & V_3 -> V_84 -> V_182 ) ;
F_193 () ;
F_71 ( & V_3 -> V_84 -> V_182 , V_488 ) ;
F_33 ( & V_3 -> V_59 ) ;
V_3 -> V_34 = V_516 ;
F_149 () ;
if ( V_491 > 1 ) {
unsigned long V_510 = F_128 ( V_511 ) ;
unsigned long V_396 = 0 ;
V_510 &= ~ V_512 ;
V_496 = V_500 | V_502 ;
F_185 () ;
F_186 ( V_511 , V_510 ) ;
F_187 () ;
for (; ; ) {
V_510 = F_128 ( V_511 ) ;
if ( ! ( V_510 & V_496 ) )
break;
F_188 () ;
++ V_396 ;
}
V_489 . V_514 = 0 ;
}
for ( V_5 = 0 ; V_5 < V_497 ; ++ V_5 ) {
F_147 ( V_141 + V_5 ) ;
if ( V_490 && V_490 -> V_517 [ V_5 ] )
F_3 ( V_141 + V_5 ) ;
}
F_182 ( V_141 ) ;
F_34 ( & V_3 -> V_59 ) ;
F_7 () ;
F_194 () ;
for ( V_461 = 0 ; V_461 < V_459 . V_462 ; ++ V_461 )
F_174 (pvc, vcnext, &core_info.vcs[sub],
preempt_list)
F_176 ( V_474 , V_474 == V_3 ) ;
F_33 ( & V_3 -> V_59 ) ;
F_12 () ;
V_414:
V_3 -> V_34 = V_134 ;
F_191 ( V_3 , 1 ) ;
}
static void F_195 ( struct V_2 * V_3 ,
struct V_1 * V_6 , int V_518 )
{
F_196 ( V_519 ) ;
F_197 ( & V_6 -> V_25 . V_426 , & V_519 , V_518 ) ;
if ( V_6 -> V_25 . V_37 == V_166 ) {
F_34 ( & V_3 -> V_59 ) ;
F_198 () ;
F_33 ( & V_3 -> V_59 ) ;
}
F_199 ( & V_6 -> V_25 . V_426 , & V_519 ) ;
}
static void F_200 ( struct V_2 * V_3 )
{
if ( V_3 -> V_520 == 0 && V_521 )
V_3 -> V_520 = 10000 ;
else
V_3 -> V_520 *= V_521 ;
}
static void F_201 ( struct V_2 * V_3 )
{
if ( V_522 == 0 )
V_3 -> V_520 = 0 ;
else
V_3 -> V_520 /= V_522 ;
}
static int F_202 ( struct V_2 * V_3 )
{
struct V_1 * V_6 ;
int V_5 ;
F_170 (i, vcpu, vc) {
if ( V_6 -> V_25 . V_482 || ! V_6 -> V_25 . V_176 )
return 1 ;
}
return 0 ;
}
static void F_203 ( struct V_2 * V_3 )
{
T_9 V_523 , V_524 , V_525 ;
int V_526 = 1 ;
T_1 V_527 ;
F_204 ( V_519 ) ;
V_523 = V_524 = F_205 () ;
if ( V_3 -> V_520 ) {
T_9 V_528 = F_206 ( V_524 , V_3 -> V_520 ) ;
++ V_3 -> V_33 -> V_23 . V_529 ;
V_3 -> V_34 = V_530 ;
F_34 ( & V_3 -> V_59 ) ;
do {
if ( F_202 ( V_3 ) ) {
V_526 = 0 ;
break;
}
V_523 = F_205 () ;
} while ( F_207 () && F_208 ( V_523 , V_528 ) );
F_33 ( & V_3 -> V_59 ) ;
V_3 -> V_34 = V_134 ;
if ( ! V_526 ) {
++ V_3 -> V_33 -> V_23 . V_531 ;
goto V_414;
}
}
F_209 ( & V_3 -> V_177 , & V_519 , V_532 ) ;
if ( F_202 ( V_3 ) ) {
F_210 ( & V_3 -> V_177 , & V_519 ) ;
V_526 = 0 ;
if ( V_3 -> V_520 )
++ V_3 -> V_33 -> V_23 . V_531 ;
goto V_414;
}
V_525 = F_205 () ;
V_3 -> V_34 = V_35 ;
F_211 ( V_3 , 0 ) ;
F_34 ( & V_3 -> V_59 ) ;
F_198 () ;
F_210 ( & V_3 -> V_177 , & V_519 ) ;
F_33 ( & V_3 -> V_59 ) ;
V_3 -> V_34 = V_134 ;
F_211 ( V_3 , 1 ) ;
++ V_3 -> V_33 -> V_23 . V_533 ;
V_523 = F_205 () ;
V_414:
V_527 = F_212 ( V_523 ) - F_212 ( V_524 ) ;
if ( V_526 ) {
V_3 -> V_33 -> V_23 . V_534 +=
F_212 ( V_523 ) - F_212 ( V_525 ) ;
if ( V_3 -> V_520 )
V_3 -> V_33 -> V_23 . V_535 +=
F_212 ( V_525 ) -
F_212 ( V_524 ) ;
} else {
if ( V_3 -> V_520 )
V_3 -> V_33 -> V_23 . V_536 +=
F_212 ( V_523 ) -
F_212 ( V_524 ) ;
}
if ( V_520 ) {
if ( V_527 <= V_3 -> V_520 )
;
else if ( V_3 -> V_520 && V_527 > V_520 )
F_201 ( V_3 ) ;
else if ( V_3 -> V_520 < V_520 &&
V_527 < V_520 )
F_200 ( V_3 ) ;
if ( V_3 -> V_520 > V_520 )
V_3 -> V_520 = V_520 ;
} else
V_3 -> V_520 = 0 ;
F_213 ( V_526 , V_527 ) ;
}
static int F_214 ( struct V_199 * V_199 , struct V_1 * V_6 )
{
int V_537 , V_5 ;
struct V_2 * V_3 ;
struct V_1 * V_95 ;
F_215 ( V_6 ) ;
V_199 -> V_204 = 0 ;
V_6 -> V_25 . V_88 = V_197 ;
V_6 -> V_25 . V_64 = 0 ;
F_52 ( V_6 ) ;
V_3 = V_6 -> V_25 . V_32 ;
F_33 ( & V_3 -> V_59 ) ;
V_6 -> V_25 . V_176 = 0 ;
V_6 -> V_25 . V_476 = V_538 ;
V_6 -> V_25 . V_199 = V_199 ;
V_6 -> V_25 . V_138 = F_53 ( V_3 , F_24 () ) ;
V_6 -> V_25 . V_37 = V_166 ;
V_6 -> V_25 . V_39 = V_30 ;
F_145 ( V_3 -> V_8 [ V_6 -> V_25 . V_142 ] , V_6 ) ;
++ V_3 -> V_439 ;
if ( ! F_171 ( V_538 ) ) {
if ( V_3 -> V_34 == V_479 ) {
struct V_2 * V_450 = V_3 -> V_451 ;
if ( F_175 ( & V_450 -> V_59 ) ) {
if ( V_450 -> V_34 == V_515 &&
! F_216 ( V_450 ) ) {
F_54 ( V_6 , V_3 ) ;
F_148 ( V_6 , V_3 ) ;
F_190 ( V_6 ) ;
}
F_34 ( & V_450 -> V_59 ) ;
}
} else if ( V_3 -> V_34 == V_515 &&
! F_216 ( V_3 ) ) {
F_54 ( V_6 , V_3 ) ;
F_148 ( V_6 , V_3 ) ;
F_190 ( V_6 ) ;
} else if ( V_3 -> V_34 == V_35 ) {
F_19 ( & V_3 -> V_177 ) ;
}
}
while ( V_6 -> V_25 . V_37 == V_166 &&
! F_171 ( V_538 ) ) {
if ( V_3 -> V_34 == V_458 && V_3 -> V_33 == NULL )
F_160 ( V_3 ) ;
if ( V_3 -> V_34 != V_134 ) {
F_195 ( V_3 , V_6 , V_532 ) ;
continue;
}
F_170 (i, v, vc) {
F_141 ( V_95 ) ;
if ( F_171 ( V_95 -> V_25 . V_476 ) ) {
F_144 ( V_3 , V_95 ) ;
V_95 -> V_23 . V_539 ++ ;
V_95 -> V_25 . V_199 -> V_204 = V_540 ;
V_95 -> V_25 . V_88 = - V_477 ;
F_172 ( & V_95 -> V_25 . V_426 ) ;
}
}
if ( ! V_3 -> V_439 || V_6 -> V_25 . V_37 != V_166 )
break;
V_537 = 0 ;
F_170 (i, v, vc) {
if ( ! V_95 -> V_25 . V_482 )
V_537 += V_95 -> V_25 . V_176 ;
else
V_95 -> V_25 . V_176 = 0 ;
}
V_3 -> V_33 = V_6 ;
if ( V_537 == V_3 -> V_439 ) {
F_203 ( V_3 ) ;
} else if ( F_217 () ) {
F_157 ( V_3 ) ;
F_218 ( & V_3 -> V_59 ) ;
if ( V_3 -> V_34 == V_458 )
F_160 ( V_3 ) ;
} else {
F_183 ( V_3 ) ;
}
V_3 -> V_33 = NULL ;
}
while ( V_6 -> V_25 . V_37 == V_166 &&
( V_3 -> V_34 == V_515 ||
V_3 -> V_34 == V_516 ||
V_3 -> V_34 == V_479 ) )
F_195 ( V_3 , V_6 , V_541 ) ;
if ( V_3 -> V_34 == V_458 && V_3 -> V_33 == NULL )
F_160 ( V_3 ) ;
if ( V_6 -> V_25 . V_37 == V_166 ) {
F_144 ( V_3 , V_6 ) ;
V_6 -> V_23 . V_539 ++ ;
V_199 -> V_204 = V_540 ;
V_6 -> V_25 . V_88 = - V_477 ;
}
if ( V_3 -> V_439 && V_3 -> V_34 == V_134 ) {
V_5 = - 1 ;
V_95 = F_1 ( V_3 , & V_5 ) ;
F_172 ( & V_95 -> V_25 . V_426 ) ;
}
F_219 ( V_6 , V_199 ) ;
F_34 ( & V_3 -> V_59 ) ;
return V_6 -> V_25 . V_88 ;
}
static int F_220 ( struct V_199 * V_200 , struct V_1 * V_6 )
{
int V_61 ;
int V_488 ;
if ( ! V_6 -> V_25 . V_542 ) {
V_200 -> V_204 = V_214 ;
return - V_58 ;
}
F_141 ( V_6 ) ;
if ( F_171 ( V_538 ) ) {
V_200 -> V_204 = V_540 ;
return - V_477 ;
}
F_221 ( & V_6 -> V_84 -> V_25 . V_543 ) ;
F_7 () ;
if ( ! V_6 -> V_84 -> V_25 . V_544 ) {
V_61 = F_222 ( V_6 ) ;
if ( V_61 )
goto V_414;
}
F_223 ( V_538 ) ;
V_6 -> V_25 . V_22 = & V_6 -> V_25 . V_32 -> V_177 ;
V_6 -> V_25 . V_545 = V_538 -> V_546 -> V_547 ;
V_6 -> V_25 . V_37 = V_38 ;
do {
V_61 = F_214 ( V_200 , V_6 ) ;
if ( V_200 -> V_204 == V_232 &&
! ( V_6 -> V_25 . V_43 . V_41 & V_548 ) ) {
F_224 ( V_6 ) ;
V_61 = F_66 ( V_6 ) ;
F_225 ( V_6 , V_61 ) ;
F_141 ( V_6 ) ;
} else if ( V_61 == V_234 ) {
V_488 = F_69 ( & V_6 -> V_84 -> V_182 ) ;
V_61 = F_226 ( V_200 , V_6 ,
V_6 -> V_25 . V_77 , V_6 -> V_25 . V_78 ) ;
F_71 ( & V_6 -> V_84 -> V_182 , V_488 ) ;
} else if ( V_61 == V_243 )
V_61 = F_227 ( V_6 , 0 ) ;
} while ( F_180 ( V_61 ) );
V_414:
V_6 -> V_25 . V_37 = V_425 ;
F_228 ( & V_6 -> V_84 -> V_25 . V_543 ) ;
return V_61 ;
}
static void F_229 ( struct V_549 * * V_550 ,
int V_551 )
{
struct V_552 * V_553 = & V_554 [ V_551 ] ;
if ( ! V_553 -> V_555 )
return;
( * V_550 ) -> V_556 = V_553 -> V_555 ;
( * V_550 ) -> V_557 = V_553 -> V_558 ;
( * V_550 ) -> V_559 [ 0 ] . V_556 = V_553 -> V_555 ;
( * V_550 ) -> V_559 [ 0 ] . V_560 = V_553 -> V_561 [ V_551 ] ;
if ( V_551 != V_562 && V_553 -> V_561 [ V_562 ] != - 1 ) {
( * V_550 ) -> V_559 [ 1 ] . V_556 = 24 ;
( * V_550 ) -> V_559 [ 1 ] . V_560 = V_553 -> V_561 [ V_562 ] ;
}
( * V_550 ) ++ ;
}
static int F_230 ( struct V_84 * V_84 ,
struct V_563 * V_564 )
{
struct V_549 * V_550 ;
V_564 -> V_27 = V_565 ;
if ( F_231 ( V_566 ) )
V_564 -> V_27 |= V_567 ;
V_564 -> V_568 = V_569 ;
V_550 = & V_564 -> V_550 [ 0 ] ;
F_229 ( & V_550 , V_570 ) ;
F_229 ( & V_550 , V_571 ) ;
F_229 ( & V_550 , V_562 ) ;
return 0 ;
}
static int F_232 ( struct V_84 * V_84 ,
struct V_572 * log )
{
struct V_573 * V_574 ;
struct V_575 * V_576 ;
int V_61 ;
unsigned long V_395 ;
F_39 ( & V_84 -> V_577 ) ;
V_61 = - V_58 ;
if ( log -> V_578 >= V_579 )
goto V_414;
V_574 = V_573 ( V_84 ) ;
V_576 = F_233 ( V_574 , log -> V_578 ) ;
V_61 = - V_183 ;
if ( ! V_576 -> V_580 )
goto V_414;
V_395 = F_234 ( V_576 ) ;
memset ( V_576 -> V_580 , 0 , V_395 ) ;
V_61 = F_235 ( V_84 , V_576 , V_576 -> V_580 ) ;
if ( V_61 )
goto V_414;
V_61 = - V_408 ;
if ( F_117 ( log -> V_580 , V_576 -> V_580 , V_395 ) )
goto V_414;
V_61 = 0 ;
V_414:
F_41 ( & V_84 -> V_577 ) ;
return V_61 ;
}
static void F_236 ( struct V_575 * free ,
struct V_575 * V_581 )
{
if ( ! V_581 || free -> V_25 . V_582 != V_581 -> V_25 . V_582 ) {
F_237 ( free -> V_25 . V_582 ) ;
free -> V_25 . V_582 = NULL ;
}
}
static int F_238 ( struct V_575 * V_578 ,
unsigned long V_583 )
{
V_578 -> V_25 . V_582 = F_239 ( V_583 * sizeof( * V_578 -> V_25 . V_582 ) ) ;
if ( ! V_578 -> V_25 . V_582 )
return - V_386 ;
return 0 ;
}
static int F_240 ( struct V_84 * V_84 ,
struct V_575 * V_576 ,
const struct V_584 * V_585 )
{
return 0 ;
}
static void F_241 ( struct V_84 * V_84 ,
const struct V_584 * V_585 ,
const struct V_575 * V_586 ,
const struct V_575 * V_587 )
{
unsigned long V_583 = V_585 -> V_588 >> V_589 ;
struct V_573 * V_574 ;
struct V_575 * V_576 ;
if ( V_583 )
F_242 ( & V_84 -> V_25 . V_590 ) ;
if ( V_583 && V_586 -> V_583 ) {
V_574 = V_573 ( V_84 ) ;
V_576 = F_233 ( V_574 , V_585 -> V_578 ) ;
F_235 ( V_84 , V_576 , NULL ) ;
}
}
void F_243 ( struct V_84 * V_84 , unsigned long V_83 , unsigned long V_256 )
{
long int V_5 ;
T_2 V_591 = 0 ;
if ( ( V_84 -> V_25 . V_83 & V_256 ) == V_83 )
return;
V_84 -> V_25 . V_83 = ( V_84 -> V_25 . V_83 & ~ V_256 ) | V_83 ;
for ( V_5 = 0 ; V_5 < V_413 ; ++ V_5 ) {
struct V_2 * V_3 = V_84 -> V_25 . V_427 [ V_5 ] ;
if ( ! V_3 )
continue;
F_33 ( & V_3 -> V_59 ) ;
V_3 -> V_83 = ( V_3 -> V_83 & ~ V_256 ) | V_83 ;
F_34 ( & V_3 -> V_59 ) ;
if ( ++ V_591 >= V_84 -> V_25 . V_428 )
break;
}
}
static void F_244 ( struct V_1 * V_6 )
{
return;
}
static void F_245 ( struct V_84 * V_84 )
{
unsigned long V_592 , V_593 ;
V_592 = ( ( V_84 -> V_25 . V_594 & V_595 ) >> 1 ) |
( ( V_84 -> V_25 . V_594 & V_596 ) << 1 ) ;
V_592 |= V_84 -> V_25 . V_85 ;
V_593 = 0 ;
F_246 ( V_84 -> V_25 . V_597 , V_592 , V_593 ) ;
}
static int F_222 ( struct V_1 * V_6 )
{
int V_108 = 0 ;
struct V_84 * V_84 = V_6 -> V_84 ;
unsigned long V_598 ;
struct V_575 * V_576 ;
struct V_599 * V_600 ;
unsigned long V_83 = 0 , V_601 ;
unsigned long V_602 , V_603 ;
int V_488 ;
F_39 ( & V_84 -> V_59 ) ;
if ( V_84 -> V_25 . V_544 )
goto V_414;
if ( ! V_84 -> V_25 . V_604 ) {
V_108 = F_247 ( V_84 , NULL ) ;
if ( V_108 ) {
F_36 ( L_22 ) ;
goto V_414;
}
}
V_488 = F_69 ( & V_84 -> V_182 ) ;
V_576 = F_248 ( V_84 , 0 ) ;
V_108 = - V_58 ;
if ( ! V_576 || ( V_576 -> V_27 & V_605 ) )
goto V_606;
V_598 = V_576 -> V_607 ;
F_249 ( & V_538 -> V_546 -> V_608 ) ;
V_600 = F_250 ( V_538 -> V_546 , V_598 ) ;
if ( ! V_600 || V_600 -> V_609 > V_598 || ( V_600 -> V_610 & V_611 ) )
goto V_612;
V_602 = F_251 ( V_600 ) ;
V_603 = F_252 ( V_602 ) ;
F_253 ( & V_538 -> V_546 -> V_608 ) ;
V_108 = - V_58 ;
if ( ! ( V_602 == 0x1000 || V_602 == 0x10000 ||
V_602 == 0x1000000 ) )
goto V_606;
V_601 = F_254 ( V_602 ) ;
V_84 -> V_25 . V_594 = V_601 | V_613 |
( V_614 << V_615 ) ;
F_255 ( V_6 , V_576 , V_603 ) ;
if ( ! F_5 ( V_12 ) ) {
V_83 = V_601 << ( V_616 - 4 ) ;
F_243 ( V_84 , V_83 , V_617 ) ;
} else {
F_245 ( V_84 ) ;
}
F_60 () ;
V_84 -> V_25 . V_544 = 1 ;
V_108 = 0 ;
V_606:
F_71 ( & V_84 -> V_182 , V_488 ) ;
V_414:
F_41 ( & V_84 -> V_59 ) ;
return V_108 ;
V_612:
F_253 ( & V_538 -> V_546 -> V_608 ) ;
goto V_606;
}
void F_256 ( void )
{
struct V_618 * V_619 ;
unsigned long V_620 ;
int V_9 , V_378 ;
int V_621 ;
if ( V_483 != NULL )
return;
V_619 = F_103 ( sizeof( struct V_618 ) , V_379 ) ;
if ( ! V_619 )
return;
V_621 = F_257 () * sizeof( struct V_622 ) ;
V_619 -> V_485 = F_103 ( V_621 , V_379 ) ;
if ( ! V_619 -> V_485 ) {
F_112 ( V_619 ) ;
return;
}
F_258 () ;
for ( V_9 = 0 ; V_9 < V_16 ; V_9 += V_623 ) {
if ( ! F_20 ( V_9 ) )
continue;
V_378 = V_9 >> V_484 ;
V_619 -> V_485 [ V_378 ] . V_486 . V_487 = 1 ;
}
V_619 -> V_624 = F_16 ;
F_60 () ;
V_620 = ( unsigned long ) V_619 ;
if ( F_259 ( ( unsigned long * ) & V_483 , 0 , V_620 ) ) {
F_260 () ;
F_112 ( V_619 -> V_485 ) ;
F_112 ( V_619 ) ;
return;
}
F_261 ( V_625 ,
L_23 ,
F_182 ,
F_181 ) ;
F_260 () ;
}
void F_262 ( void )
{
if ( V_483 ) {
F_263 ( V_625 ) ;
F_112 ( V_483 -> V_485 ) ;
F_112 ( V_483 ) ;
V_483 = NULL ;
}
}
static int F_264 ( struct V_84 * V_84 )
{
unsigned long V_83 , V_597 ;
char V_388 [ 32 ] ;
V_597 = F_265 () ;
if ( ( long ) V_597 < 0 )
return - V_386 ;
V_84 -> V_25 . V_597 = V_597 ;
F_256 () ;
if ( ! F_5 ( V_12 ) )
F_266 ( & V_84 -> V_25 . V_626 ) ;
memcpy ( V_84 -> V_25 . V_171 , V_627 ,
sizeof( V_84 -> V_25 . V_171 ) ) ;
if ( ! F_5 ( V_12 ) )
V_84 -> V_25 . V_628 = F_128 ( V_629 ) ;
V_84 -> V_25 . V_630 = F_128 ( V_631 ) ;
V_84 -> V_25 . V_632 = V_83 = F_128 ( V_633 ) ;
V_83 &= V_634 | V_635 ;
V_83 |= ( 4UL << V_636 ) | V_637 |
V_638 | V_639 ;
V_84 -> V_25 . V_594 = V_613 |
( V_614 << V_615 ) ;
if ( F_5 ( V_13 ) )
V_83 |= V_640 ;
if ( F_5 ( V_12 ) ) {
V_83 &= ~ V_638 ;
V_83 |= V_641 ;
}
V_84 -> V_25 . V_83 = V_83 ;
if ( F_5 ( V_12 ) )
V_84 -> V_25 . V_642 = V_643 ;
else if ( F_5 ( V_13 ) )
V_84 -> V_25 . V_642 = V_644 ;
else
V_84 -> V_25 . V_642 = V_645 ;
F_267 () ;
snprintf ( V_388 , sizeof( V_388 ) , L_24 , V_538 -> V_314 ) ;
V_84 -> V_25 . V_410 = F_121 ( V_388 , V_646 ) ;
if ( ! F_120 ( V_84 -> V_25 . V_410 ) )
F_268 ( V_84 ) ;
return 0 ;
}
static void F_269 ( struct V_84 * V_84 )
{
long int V_5 ;
for ( V_5 = 0 ; V_5 < V_413 ; ++ V_5 )
F_112 ( V_84 -> V_25 . V_427 [ V_5 ] ) ;
V_84 -> V_25 . V_428 = 0 ;
}
static void F_270 ( struct V_84 * V_84 )
{
F_271 ( V_84 -> V_25 . V_410 ) ;
F_272 () ;
F_269 ( V_84 ) ;
F_273 ( V_84 ) ;
F_274 ( V_84 ) ;
}
static int F_275 ( struct V_199 * V_200 , struct V_1 * V_6 ,
unsigned int V_647 , int * V_648 )
{
return V_649 ;
}
static int F_276 ( struct V_1 * V_6 , int V_650 ,
T_3 V_651 )
{
return V_649 ;
}
static int F_277 ( struct V_1 * V_6 , int V_650 ,
T_3 * V_651 )
{
return V_649 ;
}
static int F_278 ( void )
{
if ( ! F_5 ( V_652 ) ||
! F_5 ( V_50 ) )
return - V_653 ;
if ( F_5 ( V_12 ) && F_279 () )
return - V_653 ;
return 0 ;
}
void F_274 ( struct V_84 * V_84 )
{
F_112 ( V_84 -> V_25 . V_654 ) ;
}
static struct V_655 * F_280 ( void )
{
return F_103 ( sizeof( struct V_655 ) , V_379 ) ;
}
static int F_281 ( struct V_84 * V_84 , int V_656 , int V_657 )
{
struct V_658 * V_659 ;
struct V_660 * V_661 ;
struct V_655 * V_654 ;
struct V_662 * V_663 ;
int V_5 ;
if ( ! V_664 )
return 1 ;
V_659 = F_282 ( V_656 ) ;
if ( ! V_659 )
return - V_653 ;
F_39 ( & V_84 -> V_59 ) ;
V_654 = V_84 -> V_25 . V_654 ;
if ( V_654 == NULL ) {
V_654 = F_280 () ;
if ( V_654 == NULL ) {
F_41 ( & V_84 -> V_59 ) ;
return - V_386 ;
}
V_84 -> V_25 . V_654 = V_654 ;
}
V_663 = F_283 ( & V_659 -> V_665 ) ;
if ( ! V_663 || ! F_284 ( V_663 ) ) {
F_285 ( L_25 ,
V_656 , V_657 ) ;
F_41 ( & V_84 -> V_59 ) ;
return - V_183 ;
}
for ( V_5 = 0 ; V_5 < V_654 -> V_666 ; V_5 ++ ) {
if ( V_657 == V_654 -> V_667 [ V_5 ] . V_668 ) {
if ( V_654 -> V_667 [ V_5 ] . V_669 ) {
F_41 ( & V_84 -> V_59 ) ;
return - V_58 ;
}
break;
}
}
if ( V_5 == V_670 ) {
F_41 ( & V_84 -> V_59 ) ;
return - V_671 ;
}
V_661 = & V_654 -> V_667 [ V_5 ] ;
V_661 -> V_668 = V_657 ;
V_661 -> V_659 = V_659 ;
F_60 () ;
V_661 -> V_669 = V_659 -> V_665 . V_672 ;
if ( V_5 == V_654 -> V_666 )
V_654 -> V_666 ++ ;
F_286 ( V_84 , V_657 , V_659 -> V_665 . V_672 ) ;
F_41 ( & V_84 -> V_59 ) ;
return 0 ;
}
static int F_287 ( struct V_84 * V_84 , int V_656 , int V_657 )
{
struct V_658 * V_659 ;
struct V_655 * V_654 ;
int V_5 ;
if ( ! V_664 )
return 0 ;
V_659 = F_282 ( V_656 ) ;
if ( ! V_659 )
return - V_653 ;
F_39 ( & V_84 -> V_59 ) ;
if ( V_84 -> V_25 . V_654 == NULL ) {
F_41 ( & V_84 -> V_59 ) ;
return 0 ;
}
V_654 = V_84 -> V_25 . V_654 ;
for ( V_5 = 0 ; V_5 < V_654 -> V_666 ; V_5 ++ ) {
if ( V_657 == V_654 -> V_667 [ V_5 ] . V_668 )
break;
}
if ( V_5 == V_654 -> V_666 ) {
F_41 ( & V_84 -> V_59 ) ;
return - V_673 ;
}
F_288 ( V_84 , V_657 , V_654 -> V_667 [ V_5 ] . V_669 ) ;
V_654 -> V_667 [ V_5 ] . V_669 = 0 ;
F_41 ( & V_84 -> V_59 ) ;
return 0 ;
}
static int F_289 ( struct V_674 * V_675 ,
struct V_676 * V_677 )
{
int V_88 = 0 ;
struct V_678 * V_679 =
F_290 ( V_675 , struct V_678 , V_680 ) ;
V_679 -> V_681 = V_677 ;
V_88 = F_281 ( V_679 -> V_84 , V_677 -> V_682 , V_679 -> V_683 ) ;
if ( V_88 )
F_291 ( L_26 ,
V_677 -> V_682 , V_679 -> V_683 , V_88 ) ;
return V_88 ;
}
static void F_292 ( struct V_674 * V_675 ,
struct V_676 * V_677 )
{
int V_88 ;
struct V_678 * V_679 =
F_290 ( V_675 , struct V_678 , V_680 ) ;
V_679 -> V_681 = NULL ;
V_88 = F_287 ( V_679 -> V_84 , V_677 -> V_682 , V_679 -> V_683 ) ;
if ( V_88 )
F_285 ( L_27 ,
V_677 -> V_682 , V_679 -> V_683 , V_88 ) ;
}
static long F_293 ( struct V_383 * V_684 ,
unsigned int V_685 , unsigned long V_686 )
{
struct V_84 * V_84 V_687 = V_684 -> V_387 ;
void T_5 * V_688 = ( void T_5 * ) V_686 ;
long V_61 ;
switch ( V_685 ) {
case V_689 : {
T_2 V_690 ;
V_61 = - V_408 ;
if ( F_294 ( V_690 , ( T_2 T_5 * ) V_688 ) )
break;
V_61 = F_295 ( V_84 , & V_690 ) ;
if ( V_61 )
break;
V_61 = - V_408 ;
if ( F_296 ( V_690 , ( T_2 T_5 * ) V_688 ) )
break;
V_61 = 0 ;
break;
}
case V_691 : {
struct V_692 V_693 ;
V_61 = - V_408 ;
if ( F_297 ( & V_693 , V_688 , sizeof( V_693 ) ) )
break;
V_61 = F_298 ( V_84 , & V_693 ) ;
break;
}
default:
V_61 = - V_694 ;
}
return V_61 ;
}
static void F_299 ( void )
{
int V_5 ;
unsigned int V_695 ;
for ( V_5 = 0 ; V_696 [ V_5 ] ; ++ V_5 ) {
V_695 = V_696 [ V_5 ] ;
F_300 ( ! F_80 ( V_695 ) ) ;
F_301 ( V_695 / 4 , V_627 ) ;
}
}
static int F_302 ( void )
{
int V_5 , V_251 ;
int V_697 = F_257 () ;
struct V_698 * V_698 ;
for ( V_5 = 0 ; V_5 < V_697 ; V_5 ++ ) {
int V_699 = V_5 * V_623 ;
int V_700 = F_303 ( V_699 ) ;
if ( V_17 [ V_699 ] . V_698 )
continue;
V_698 =
F_304 ( sizeof( struct V_698 ) ,
V_379 , V_700 ) ;
if ( ! V_698 )
return - V_386 ;
memset ( V_698 , 0 ,
sizeof( struct V_698 ) ) ;
for ( V_251 = 0 ; V_251 < V_623 ; V_251 ++ ) {
int V_9 = V_699 + V_251 ;
V_17 [ V_9 ] . V_698 = V_698 ;
}
}
return 0 ;
}
static int F_305 ( void )
{
int V_61 ;
V_61 = F_278 () ;
if ( V_61 < 0 )
return - V_673 ;
V_61 = F_302 () ;
if ( V_61 )
return V_61 ;
#ifdef V_15
if ( ! F_306 () -> V_18 . V_19 ) {
struct V_701 * V_702 ;
V_702 = F_307 ( NULL , NULL , L_28 ) ;
if ( ! V_702 ) {
F_36 ( L_29 ) ;
return - V_673 ;
}
}
#endif
V_703 . V_704 = V_705 ;
V_706 = & V_703 ;
F_299 () ;
F_154 () ;
V_61 = F_308 () ;
return V_61 ;
}
static void F_309 ( void )
{
F_262 () ;
V_706 = NULL ;
}
