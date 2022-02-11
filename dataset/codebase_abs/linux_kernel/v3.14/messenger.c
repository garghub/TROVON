static bool F_1 ( unsigned long V_1 )
{
switch ( V_1 ) {
case V_2 :
case V_3 :
case V_4 :
case V_5 :
case V_6 :
return true ;
default:
return false ;
}
}
static void F_2 ( struct V_7 * V_8 , unsigned long V_1 )
{
F_3 ( ! F_1 ( V_1 ) ) ;
F_4 ( V_1 , & V_8 -> V_9 ) ;
}
static void F_5 ( struct V_7 * V_8 , unsigned long V_1 )
{
F_3 ( ! F_1 ( V_1 ) ) ;
F_6 ( V_1 , & V_8 -> V_9 ) ;
}
static bool F_7 ( struct V_7 * V_8 , unsigned long V_1 )
{
F_3 ( ! F_1 ( V_1 ) ) ;
return F_8 ( V_1 , & V_8 -> V_9 ) ;
}
static bool F_9 ( struct V_7 * V_8 ,
unsigned long V_1 )
{
F_3 ( ! F_1 ( V_1 ) ) ;
return F_10 ( V_1 , & V_8 -> V_9 ) ;
}
static bool F_11 ( struct V_7 * V_8 ,
unsigned long V_1 )
{
F_3 ( ! F_1 ( V_1 ) ) ;
return F_12 ( V_1 , & V_8 -> V_9 ) ;
}
const char * F_13 ( const struct V_10 * V_11 )
{
int V_12 ;
char * V_13 ;
struct V_14 * V_15 = (struct V_14 * ) V_11 ;
struct V_16 * V_17 = (struct V_16 * ) V_11 ;
V_12 = F_14 ( & V_18 ) & V_19 ;
V_13 = V_20 [ V_12 ] ;
switch ( V_11 -> V_21 ) {
case V_22 :
snprintf ( V_13 , V_23 , L_1 , & V_15 -> V_24 ,
F_15 ( V_15 -> V_25 ) ) ;
break;
case V_26 :
snprintf ( V_13 , V_23 , L_2 , & V_17 -> V_27 ,
F_15 ( V_17 -> V_28 ) ) ;
break;
default:
snprintf ( V_13 , V_23 , L_3 ,
V_11 -> V_21 ) ;
}
return V_13 ;
}
static void F_16 ( struct V_29 * V_30 )
{
memcpy ( & V_30 -> V_31 , & V_30 -> V_32 . V_33 , sizeof( V_30 -> V_31 ) ) ;
F_17 ( & V_30 -> V_31 ) ;
}
static int F_18 ( void )
{
F_3 ( V_34 ) ;
V_34 = F_19 ( L_4 ,
sizeof ( struct V_35 ) ,
F_20 ( struct V_35 ) , 0 , NULL ) ;
if ( ! V_34 )
return - V_36 ;
F_3 ( V_37 ) ;
V_37 = F_19 ( L_5 ,
sizeof ( struct V_38 ) ,
F_20 ( struct V_38 ) ,
0 , NULL ) ;
if ( V_37 )
return 0 ;
F_21 ( V_34 ) ;
V_34 = NULL ;
return - V_36 ;
}
static void F_22 ( void )
{
F_3 ( ! V_37 ) ;
F_21 ( V_37 ) ;
V_37 = NULL ;
F_3 ( ! V_34 ) ;
F_21 ( V_34 ) ;
V_34 = NULL ;
}
static void F_23 ( void )
{
if ( V_39 ) {
F_24 ( V_39 ) ;
V_39 = NULL ;
}
F_22 () ;
F_3 ( V_40 == NULL ) ;
F_25 ( V_40 ) ;
F_26 ( V_40 ) ;
V_40 = NULL ;
}
int F_27 ( void )
{
F_3 ( V_40 != NULL ) ;
V_40 = F_28 ( 0 ) ;
F_29 ( V_40 ) ;
if ( F_18 () )
return - V_36 ;
V_39 = F_30 ( L_6 , 0 , 0 ) ;
if ( V_39 )
return 0 ;
F_31 ( L_7 ) ;
F_23 () ;
return - V_36 ;
}
void F_32 ( void )
{
F_3 ( V_39 == NULL ) ;
F_23 () ;
}
void F_33 ( void )
{
F_34 ( V_39 ) ;
}
static void F_35 ( struct V_7 * V_8 )
{
int V_41 ;
V_41 = F_36 ( & V_8 -> V_42 , V_43 ) ;
if ( F_37 ( V_41 != V_44 ) )
F_38 ( L_8 , V_45 , V_41 ) ;
F_39 ( L_9 , V_45 , V_8 , V_41 ,
V_43 ) ;
}
static void F_40 ( struct V_7 * V_8 )
{
int V_41 ;
V_41 = F_36 ( & V_8 -> V_42 , V_46 ) ;
if ( F_37 ( V_41 != V_43 ) )
F_38 ( L_8 , V_45 , V_41 ) ;
F_39 ( L_9 , V_45 , V_8 , V_41 ,
V_46 ) ;
}
static void F_41 ( struct V_7 * V_8 )
{
int V_41 ;
V_41 = F_36 ( & V_8 -> V_42 , V_47 ) ;
if ( F_37 ( V_41 != V_46 ) )
F_38 ( L_8 , V_45 , V_41 ) ;
F_39 ( L_9 , V_45 , V_8 , V_41 ,
V_47 ) ;
}
static void F_42 ( struct V_7 * V_8 )
{
int V_41 ;
V_41 = F_36 ( & V_8 -> V_42 , V_48 ) ;
if ( F_37 ( V_41 != V_46 &&
V_41 != V_47 &&
V_41 != V_48 ) )
F_38 ( L_8 , V_45 , V_41 ) ;
F_39 ( L_9 , V_45 , V_8 , V_41 ,
V_48 ) ;
}
static void F_43 ( struct V_7 * V_8 )
{
int V_41 ;
V_41 = F_36 ( & V_8 -> V_42 , V_43 ) ;
if ( F_37 ( V_41 != V_47 &&
V_41 != V_48 &&
V_41 != V_46 &&
V_41 != V_43 ) )
F_38 ( L_8 , V_45 , V_41 ) ;
F_39 ( L_9 , V_45 , V_8 , V_41 ,
V_43 ) ;
}
static void F_44 ( struct V_49 * V_50 , int V_51 )
{
struct V_7 * V_8 = V_50 -> V_52 ;
if ( F_45 ( & V_8 -> V_30 -> V_53 ) ) {
return;
}
if ( V_50 -> V_54 != V_55 ) {
F_39 ( L_10 , V_45 ,
V_8 , V_8 -> V_56 ) ;
F_46 ( V_8 ) ;
}
}
static void F_47 ( struct V_49 * V_50 )
{
struct V_7 * V_8 = V_50 -> V_52 ;
if ( F_7 ( V_8 , V_4 ) ) {
if ( F_48 ( V_50 ) ) {
F_39 ( L_11 , V_45 , V_8 ) ;
F_4 ( V_57 , & V_50 -> V_58 -> V_9 ) ;
F_46 ( V_8 ) ;
}
} else {
F_39 ( L_12 , V_45 , V_8 ) ;
}
}
static void F_49 ( struct V_49 * V_50 )
{
struct V_7 * V_8 = V_50 -> V_52 ;
F_39 ( L_13 , V_45 ,
V_8 , V_8 -> V_56 , V_50 -> V_54 ) ;
switch ( V_50 -> V_54 ) {
case V_59 :
F_39 ( L_14 , V_45 ) ;
case V_55 :
F_39 ( L_15 , V_45 ) ;
F_42 ( V_8 ) ;
F_5 ( V_8 , V_5 ) ;
F_46 ( V_8 ) ;
break;
case V_60 :
F_39 ( L_16 , V_45 ) ;
F_41 ( V_8 ) ;
F_46 ( V_8 ) ;
break;
default:
break;
}
}
static void F_50 ( struct V_61 * V_49 ,
struct V_7 * V_8 )
{
struct V_49 * V_50 = V_49 -> V_50 ;
V_50 -> V_52 = V_8 ;
V_50 -> V_62 = F_44 ;
V_50 -> V_63 = F_47 ;
V_50 -> V_64 = F_49 ;
}
static int F_51 ( struct V_7 * V_8 )
{
struct V_10 * V_65 = & V_8 -> V_66 . V_67 ;
struct V_61 * V_49 ;
int V_68 ;
F_3 ( V_8 -> V_49 ) ;
V_68 = F_52 ( V_8 -> V_66 . V_67 . V_21 , V_69 ,
V_70 , & V_49 ) ;
if ( V_68 )
return V_68 ;
V_49 -> V_50 -> V_71 = V_72 ;
#ifdef F_53
F_54 ( & V_49 -> V_50 -> V_73 , & V_74 ) ;
#endif
F_50 ( V_49 , V_8 ) ;
F_39 ( L_17 , F_13 ( & V_8 -> V_66 . V_67 ) ) ;
F_40 ( V_8 ) ;
V_68 = V_49 -> V_75 -> V_76 ( V_49 , (struct V_77 * ) V_65 , sizeof( * V_65 ) ,
V_78 ) ;
if ( V_68 == - V_79 ) {
F_39 ( L_18 ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_49 -> V_50 -> V_54 ) ;
} else if ( V_68 < 0 ) {
F_31 ( L_19 ,
F_13 ( & V_8 -> V_66 . V_67 ) , V_68 ) ;
F_55 ( V_49 ) ;
V_8 -> V_80 = L_20 ;
return V_68 ;
}
V_8 -> V_49 = V_49 ;
return 0 ;
}
static int F_56 ( struct V_61 * V_49 , void * V_81 , T_1 V_82 )
{
struct V_83 V_84 = { V_81 , V_82 } ;
struct V_85 V_86 = { . V_87 = V_88 | V_89 } ;
int V_90 ;
V_90 = F_57 ( V_49 , & V_86 , & V_84 , 1 , V_82 , V_86 . V_87 ) ;
if ( V_90 == - V_91 )
V_90 = 0 ;
return V_90 ;
}
static int F_58 ( struct V_61 * V_49 , struct V_92 * V_92 ,
int V_93 , T_1 V_94 )
{
void * V_95 ;
int V_68 ;
F_3 ( V_93 + V_94 > V_96 ) ;
V_95 = F_59 ( V_92 ) ;
F_3 ( ! V_95 ) ;
V_68 = F_56 ( V_49 , V_95 + V_93 , V_94 ) ;
F_25 ( V_92 ) ;
return V_68 ;
}
static int F_60 ( struct V_61 * V_49 , struct V_83 * V_84 ,
T_1 V_97 , T_1 V_82 , int V_98 )
{
struct V_85 V_86 = { . V_87 = V_88 | V_89 } ;
int V_90 ;
if ( V_98 )
V_86 . V_87 |= V_99 ;
else
V_86 . V_87 |= V_100 ;
V_90 = F_61 ( V_49 , & V_86 , V_84 , V_97 , V_82 ) ;
if ( V_90 == - V_91 )
V_90 = 0 ;
return V_90 ;
}
static int F_62 ( struct V_61 * V_49 , struct V_92 * V_92 ,
int V_101 , T_1 V_102 , bool V_98 )
{
int V_9 = V_88 | V_89 | ( V_98 ? V_99 : V_100 ) ;
int V_68 ;
V_68 = F_63 ( V_49 , V_92 , V_101 , V_102 , V_9 ) ;
if ( V_68 == - V_91 )
V_68 = 0 ;
return V_68 ;
}
static int F_64 ( struct V_7 * V_8 )
{
int V_103 = 0 ;
F_39 ( L_21 , V_8 , V_8 -> V_49 ) ;
if ( V_8 -> V_49 ) {
V_103 = V_8 -> V_49 -> V_75 -> V_104 ( V_8 -> V_49 , V_105 ) ;
F_55 ( V_8 -> V_49 ) ;
V_8 -> V_49 = NULL ;
}
F_2 ( V_8 , V_5 ) ;
F_43 ( V_8 ) ;
return V_103 ;
}
static void F_65 ( struct V_35 * V_86 )
{
F_66 ( & V_86 -> V_106 ) ;
F_3 ( V_86 -> V_8 == NULL ) ;
V_86 -> V_8 -> V_75 -> V_107 ( V_86 -> V_8 ) ;
V_86 -> V_8 = NULL ;
F_67 ( V_86 ) ;
}
static void F_68 ( struct V_106 * V_108 )
{
while ( ! F_69 ( V_108 ) ) {
struct V_35 * V_86 = F_70 ( V_108 , struct V_35 ,
V_106 ) ;
F_65 ( V_86 ) ;
}
}
static void F_71 ( struct V_7 * V_8 )
{
F_39 ( L_22 , V_8 ) ;
F_68 ( & V_8 -> V_109 ) ;
F_68 ( & V_8 -> V_110 ) ;
if ( V_8 -> V_111 ) {
F_3 ( V_8 -> V_111 -> V_8 != V_8 ) ;
V_8 -> V_111 -> V_8 = NULL ;
F_67 ( V_8 -> V_111 ) ;
V_8 -> V_111 = NULL ;
V_8 -> V_75 -> V_107 ( V_8 ) ;
}
V_8 -> V_112 = 0 ;
V_8 -> V_113 = 0 ;
if ( V_8 -> V_114 ) {
F_67 ( V_8 -> V_114 ) ;
V_8 -> V_114 = NULL ;
}
V_8 -> V_115 = 0 ;
V_8 -> V_116 = 0 ;
}
void F_72 ( struct V_7 * V_8 )
{
F_73 ( & V_8 -> V_117 ) ;
F_39 ( L_23 , V_8 ,
F_13 ( & V_8 -> V_66 . V_67 ) ) ;
V_8 -> V_56 = V_118 ;
F_2 ( V_8 , V_2 ) ;
F_2 ( V_8 , V_3 ) ;
F_2 ( V_8 , V_4 ) ;
F_2 ( V_8 , V_6 ) ;
F_71 ( V_8 ) ;
V_8 -> V_119 = 0 ;
F_74 ( & V_8 -> V_120 ) ;
F_64 ( V_8 ) ;
F_75 ( & V_8 -> V_117 ) ;
}
void F_76 ( struct V_7 * V_8 ,
T_2 V_121 , T_3 V_122 ,
struct V_123 * V_33 )
{
F_73 ( & V_8 -> V_117 ) ;
F_39 ( L_24 , V_8 , F_13 ( & V_33 -> V_67 ) ) ;
F_37 ( V_8 -> V_56 != V_118 ) ;
V_8 -> V_56 = V_124 ;
V_8 -> V_125 . type = ( T_2 ) V_121 ;
V_8 -> V_125 . V_126 = F_77 ( V_122 ) ;
memcpy ( & V_8 -> V_66 , V_33 , sizeof( * V_33 ) ) ;
V_8 -> V_127 = 0 ;
F_75 ( & V_8 -> V_117 ) ;
F_46 ( V_8 ) ;
}
bool F_78 ( struct V_7 * V_8 )
{
return V_8 -> V_112 > 0 ;
}
void F_79 ( struct V_7 * V_8 , void * V_128 ,
const struct V_129 * V_75 ,
struct V_29 * V_30 )
{
F_39 ( L_25 , V_8 ) ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> V_128 = V_128 ;
V_8 -> V_75 = V_75 ;
V_8 -> V_30 = V_30 ;
F_35 ( V_8 ) ;
F_80 ( & V_8 -> V_117 ) ;
F_81 ( & V_8 -> V_109 ) ;
F_81 ( & V_8 -> V_110 ) ;
F_82 ( & V_8 -> V_120 , V_130 ) ;
V_8 -> V_56 = V_118 ;
}
static T_4 F_83 ( struct V_29 * V_30 , T_4 V_131 )
{
T_4 V_68 ;
F_84 ( & V_30 -> V_132 ) ;
if ( V_30 -> V_133 < V_131 )
V_30 -> V_133 = V_131 ;
V_68 = ++ V_30 -> V_133 ;
F_85 ( & V_30 -> V_132 ) ;
return V_68 ;
}
static void F_86 ( struct V_7 * V_8 )
{
V_8 -> V_134 = 0 ;
V_8 -> V_135 = 0 ;
V_8 -> V_136 = & V_8 -> V_137 [ 0 ] ;
}
static void F_87 ( struct V_7 * V_8 ,
T_1 V_102 , void * V_138 )
{
int V_139 ;
V_139 = V_8 -> V_134 ;
F_3 ( V_139 >= F_88 ( V_8 -> V_137 ) ) ;
V_8 -> V_137 [ V_139 ] . V_140 = V_102 ;
V_8 -> V_137 [ V_139 ] . V_141 = V_138 ;
V_8 -> V_134 ++ ;
V_8 -> V_135 += V_102 ;
}
static void F_89 ( struct V_142 * V_143 ,
T_1 V_94 )
{
struct V_38 * V_138 = V_143 -> V_138 ;
struct V_144 * V_144 ;
F_3 ( V_138 -> type != V_145 ) ;
V_144 = V_138 -> V_144 ;
F_3 ( ! V_144 ) ;
V_143 -> V_146 = F_90 ( V_94 , V_138 -> V_147 ) ;
V_143 -> V_144 = V_144 ;
V_143 -> V_148 = V_144 -> V_149 ;
V_143 -> V_150 =
V_143 -> V_146 <= F_91 ( V_144 , V_143 -> V_148 ) ;
}
static struct V_92 * F_92 ( struct V_142 * V_143 ,
T_1 * V_93 ,
T_1 * V_94 )
{
struct V_38 * V_138 = V_143 -> V_138 ;
struct V_144 * V_144 ;
struct V_151 V_151 ;
F_3 ( V_138 -> type != V_145 ) ;
V_144 = V_143 -> V_144 ;
F_3 ( ! V_144 ) ;
V_151 = F_93 ( V_144 , V_143 -> V_148 ) ;
* V_93 = ( T_1 ) V_151 . V_152 ;
F_3 ( * V_93 >= V_96 ) ;
if ( V_143 -> V_150 )
* V_94 = V_143 -> V_146 ;
else
* V_94 = ( T_1 ) V_151 . V_153 ;
F_3 ( * V_94 > V_143 -> V_146 ) ;
F_3 ( * V_93 + * V_94 > V_96 ) ;
return V_151 . V_154 ;
}
static bool F_94 ( struct V_142 * V_143 ,
T_1 V_155 )
{
struct V_144 * V_144 ;
struct V_151 V_151 ;
F_3 ( V_143 -> V_138 -> type != V_145 ) ;
V_144 = V_143 -> V_144 ;
F_3 ( ! V_144 ) ;
V_151 = F_93 ( V_144 , V_143 -> V_148 ) ;
F_3 ( V_143 -> V_146 < V_155 ) ;
V_143 -> V_146 -= V_155 ;
F_95 ( V_144 , & V_143 -> V_148 , V_155 ) ;
if ( V_155 < V_151 . V_153 )
return false ;
if ( ! V_143 -> V_148 . V_156 ) {
V_144 = V_144 -> V_157 ;
V_143 -> V_144 = V_144 ;
if ( V_144 )
V_143 -> V_148 = V_144 -> V_149 ;
else
memset ( & V_143 -> V_148 , 0 ,
sizeof( V_143 -> V_148 ) ) ;
}
if ( ! V_143 -> V_150 ) {
F_3 ( ! V_143 -> V_146 ) ;
F_3 ( ! V_144 ) ;
if ( V_143 -> V_146 <= F_91 ( V_144 , V_143 -> V_148 ) )
V_143 -> V_150 = true ;
}
return true ;
}
static void F_96 ( struct V_142 * V_143 ,
T_1 V_94 )
{
struct V_38 * V_138 = V_143 -> V_138 ;
int V_158 ;
F_3 ( V_138 -> type != V_159 ) ;
F_3 ( ! V_138 -> V_160 ) ;
F_3 ( ! V_138 -> V_94 ) ;
V_143 -> V_146 = F_90 ( V_94 , V_138 -> V_94 ) ;
V_158 = F_97 ( V_138 -> V_161 , ( V_162 ) V_138 -> V_94 ) ;
V_143 -> V_93 = V_138 -> V_161 & ~ V_163 ;
V_143 -> V_164 = 0 ;
F_3 ( V_158 > ( int ) V_165 ) ;
V_143 -> V_158 = ( unsigned short ) V_158 ;
F_3 ( V_94 > V_166 - V_143 -> V_93 ) ;
V_143 -> V_150 = ( T_1 ) V_143 -> V_93 + V_94 <= V_96 ;
}
static struct V_92 *
F_98 ( struct V_142 * V_143 ,
T_1 * V_93 , T_1 * V_94 )
{
struct V_38 * V_138 = V_143 -> V_138 ;
F_3 ( V_138 -> type != V_159 ) ;
F_3 ( V_143 -> V_164 >= V_143 -> V_158 ) ;
F_3 ( V_143 -> V_93 >= V_96 ) ;
* V_93 = V_143 -> V_93 ;
if ( V_143 -> V_150 )
* V_94 = V_143 -> V_146 ;
else
* V_94 = V_96 - * V_93 ;
return V_138 -> V_160 [ V_143 -> V_164 ] ;
}
static bool F_99 ( struct V_142 * V_143 ,
T_1 V_155 )
{
F_3 ( V_143 -> V_138 -> type != V_159 ) ;
F_3 ( V_143 -> V_93 + V_155 > V_96 ) ;
V_143 -> V_146 -= V_155 ;
V_143 -> V_93 = ( V_143 -> V_93 + V_155 ) & ~ V_163 ;
if ( ! V_155 || V_143 -> V_93 )
return false ;
F_3 ( V_143 -> V_164 >= V_143 -> V_158 ) ;
V_143 -> V_164 ++ ;
V_143 -> V_150 = V_143 -> V_146 <= V_96 ;
return true ;
}
static void
F_100 ( struct V_142 * V_143 ,
T_1 V_94 )
{
struct V_38 * V_138 = V_143 -> V_138 ;
struct V_167 * V_168 ;
struct V_92 * V_92 ;
F_3 ( V_138 -> type != V_169 ) ;
V_168 = V_138 -> V_168 ;
F_3 ( ! V_168 ) ;
if ( ! V_94 )
return;
F_3 ( F_69 ( & V_168 -> V_108 ) ) ;
V_92 = F_70 ( & V_168 -> V_108 , struct V_92 , V_170 ) ;
V_143 -> V_146 = F_90 ( V_94 , V_168 -> V_94 ) ;
V_143 -> V_92 = V_92 ;
V_143 -> V_101 = 0 ;
V_143 -> V_150 = V_143 -> V_146 <= V_96 ;
}
static struct V_92 *
F_101 ( struct V_142 * V_143 ,
T_1 * V_93 , T_1 * V_94 )
{
struct V_38 * V_138 = V_143 -> V_138 ;
struct V_167 * V_168 ;
F_3 ( V_138 -> type != V_169 ) ;
V_168 = V_138 -> V_168 ;
F_3 ( ! V_168 ) ;
F_3 ( ! V_143 -> V_92 ) ;
F_3 ( V_143 -> V_101 + V_143 -> V_146 != V_168 -> V_94 ) ;
* V_93 = V_143 -> V_101 & ~ V_163 ;
if ( V_143 -> V_150 )
* V_94 = V_143 -> V_146 ;
else
* V_94 = V_96 - * V_93 ;
return V_143 -> V_92 ;
}
static bool F_102 ( struct V_142 * V_143 ,
T_1 V_155 )
{
struct V_38 * V_138 = V_143 -> V_138 ;
struct V_167 * V_168 ;
F_3 ( V_138 -> type != V_169 ) ;
V_168 = V_138 -> V_168 ;
F_3 ( ! V_168 ) ;
F_3 ( V_143 -> V_101 + V_143 -> V_146 != V_168 -> V_94 ) ;
F_3 ( ( V_143 -> V_101 & ~ V_163 ) + V_155 > V_96 ) ;
V_143 -> V_146 -= V_155 ;
V_143 -> V_101 += V_155 ;
if ( ! V_155 || V_143 -> V_101 & ~ V_163 )
return false ;
F_3 ( F_103 ( & V_143 -> V_92 -> V_170 , & V_168 -> V_108 ) ) ;
V_143 -> V_92 = F_104 ( V_143 -> V_92 , V_170 ) ;
V_143 -> V_150 = V_143 -> V_146 <= V_96 ;
return true ;
}
static void F_105 ( struct V_142 * V_143 )
{
T_1 V_94 = V_143 -> V_171 ;
switch ( V_143 -> V_138 -> type ) {
case V_169 :
F_100 ( V_143 , V_94 ) ;
break;
case V_159 :
F_96 ( V_143 , V_94 ) ;
break;
#ifdef F_106
case V_145 :
F_89 ( V_143 , V_94 ) ;
break;
#endif
case V_172 :
default:
break;
}
V_143 -> V_173 = true ;
}
static void F_107 ( struct V_35 * V_86 , T_1 V_94 )
{
struct V_142 * V_143 = & V_86 -> V_143 ;
struct V_38 * V_138 ;
F_3 ( ! V_94 ) ;
F_3 ( V_94 > V_86 -> V_174 ) ;
F_3 ( F_69 ( & V_86 -> V_138 ) ) ;
V_143 -> V_175 = & V_86 -> V_138 ;
V_143 -> V_171 = V_94 ;
V_138 = F_70 ( & V_86 -> V_138 , struct V_38 , V_176 ) ;
V_143 -> V_138 = V_138 ;
F_105 ( V_143 ) ;
}
static struct V_92 * F_108 ( struct V_142 * V_143 ,
T_1 * V_93 , T_1 * V_94 ,
bool * V_150 )
{
struct V_92 * V_92 ;
switch ( V_143 -> V_138 -> type ) {
case V_169 :
V_92 = F_101 ( V_143 , V_93 , V_94 ) ;
break;
case V_159 :
V_92 = F_98 ( V_143 , V_93 , V_94 ) ;
break;
#ifdef F_106
case V_145 :
V_92 = F_92 ( V_143 , V_93 , V_94 ) ;
break;
#endif
case V_172 :
default:
V_92 = NULL ;
break;
}
F_3 ( ! V_92 ) ;
F_3 ( * V_93 + * V_94 > V_96 ) ;
F_3 ( ! * V_94 ) ;
if ( V_150 )
* V_150 = V_143 -> V_150 ;
return V_92 ;
}
static bool F_109 ( struct V_142 * V_143 ,
T_1 V_155 )
{
bool V_177 ;
F_3 ( V_155 > V_143 -> V_146 ) ;
switch ( V_143 -> V_138 -> type ) {
case V_169 :
V_177 = F_102 ( V_143 , V_155 ) ;
break;
case V_159 :
V_177 = F_99 ( V_143 , V_155 ) ;
break;
#ifdef F_106
case V_145 :
V_177 = F_94 ( V_143 , V_155 ) ;
break;
#endif
case V_172 :
default:
F_110 () ;
break;
}
V_143 -> V_171 -= V_155 ;
if ( ! V_143 -> V_146 && V_143 -> V_171 ) {
F_37 ( ! V_143 -> V_150 ) ;
F_3 ( F_103 ( & V_143 -> V_138 -> V_176 , V_143 -> V_175 ) ) ;
V_143 -> V_138 = F_104 ( V_143 -> V_138 , V_176 ) ;
F_105 ( V_143 ) ;
V_177 = true ;
}
V_143 -> V_173 = V_177 ;
return V_177 ;
}
static void F_111 ( struct V_35 * V_86 , T_4 V_178 )
{
F_3 ( ! V_86 ) ;
F_3 ( ! V_178 ) ;
F_107 ( V_86 , ( T_1 ) V_178 ) ;
}
static void F_112 ( struct V_7 * V_8 )
{
struct V_35 * V_179 = V_8 -> V_114 ;
int V_180 = V_8 -> V_134 ;
V_179 -> V_181 . V_9 |= V_182 ;
F_39 ( L_26 , V_8 ) ;
V_8 -> V_183 = true ;
V_8 -> V_137 [ V_180 ] . V_141 = & V_179 -> V_181 ;
V_8 -> V_137 [ V_180 ] . V_140 = sizeof( V_179 -> V_181 ) ;
V_8 -> V_135 += sizeof( V_179 -> V_181 ) ;
V_8 -> V_134 ++ ;
V_8 -> V_184 = V_179 -> V_185 ;
V_8 -> V_186 = true ;
}
static void F_113 ( struct V_7 * V_8 )
{
struct V_35 * V_179 ;
T_4 V_187 ;
F_86 ( V_8 ) ;
V_8 -> V_183 = true ;
V_8 -> V_186 = false ;
if ( V_8 -> V_115 > V_8 -> V_116 ) {
V_8 -> V_116 = V_8 -> V_115 ;
F_87 ( V_8 , sizeof ( V_188 ) , & V_188 ) ;
V_8 -> V_189 = F_77 ( V_8 -> V_116 ) ;
F_87 ( V_8 , sizeof ( V_8 -> V_189 ) ,
& V_8 -> V_189 ) ;
}
F_3 ( F_69 ( & V_8 -> V_109 ) ) ;
V_179 = F_70 ( & V_8 -> V_109 , struct V_35 , V_106 ) ;
V_8 -> V_114 = V_179 ;
F_3 ( V_179 -> V_8 != V_8 ) ;
F_114 ( V_179 ) ;
F_115 ( & V_179 -> V_106 , & V_8 -> V_110 ) ;
if ( V_179 -> V_190 ) {
V_179 -> V_191 . V_192 = F_77 ( ++ V_8 -> V_113 ) ;
V_179 -> V_190 = false ;
}
F_37 ( V_179 -> V_174 != F_116 ( V_179 -> V_191 . V_178 ) ) ;
F_39 ( L_27 ,
V_179 , V_8 -> V_113 , F_117 ( V_179 -> V_191 . type ) ,
F_116 ( V_179 -> V_191 . V_193 ) , F_116 ( V_179 -> V_191 . V_194 ) ,
V_179 -> V_174 ) ;
F_3 ( F_116 ( V_179 -> V_191 . V_193 ) != V_179 -> V_195 . V_140 ) ;
F_87 ( V_8 , sizeof ( V_196 ) , & V_196 ) ;
F_87 ( V_8 , sizeof ( V_179 -> V_191 ) , & V_179 -> V_191 ) ;
F_87 ( V_8 , V_179 -> V_195 . V_140 , V_179 -> V_195 . V_141 ) ;
if ( V_179 -> V_197 )
F_87 ( V_8 , V_179 -> V_197 -> V_198 . V_140 ,
V_179 -> V_197 -> V_198 . V_141 ) ;
V_187 = F_118 ( 0 , & V_179 -> V_191 , F_119 ( struct V_199 , V_187 ) ) ;
V_8 -> V_114 -> V_191 . V_187 = F_120 ( V_187 ) ;
V_8 -> V_114 -> V_181 . V_9 = 0 ;
V_187 = F_118 ( 0 , V_179 -> V_195 . V_141 , V_179 -> V_195 . V_140 ) ;
V_8 -> V_114 -> V_181 . V_200 = F_120 ( V_187 ) ;
if ( V_179 -> V_197 ) {
V_187 = F_118 ( 0 , V_179 -> V_197 -> V_198 . V_141 ,
V_179 -> V_197 -> V_198 . V_140 ) ;
V_8 -> V_114 -> V_181 . V_201 = F_120 ( V_187 ) ;
} else
V_8 -> V_114 -> V_181 . V_201 = 0 ;
F_39 ( L_28 , V_45 ,
F_116 ( V_8 -> V_114 -> V_181 . V_200 ) ,
F_116 ( V_8 -> V_114 -> V_181 . V_201 ) ) ;
V_8 -> V_114 -> V_181 . V_202 = 0 ;
if ( V_179 -> V_174 ) {
F_111 ( V_8 -> V_114 , V_179 -> V_174 ) ;
V_8 -> V_184 = 1 ;
} else {
F_112 ( V_8 ) ;
}
F_5 ( V_8 , V_4 ) ;
}
static void F_121 ( struct V_7 * V_8 )
{
F_39 ( L_29 , V_8 ,
V_8 -> V_116 , V_8 -> V_115 ) ;
V_8 -> V_116 = V_8 -> V_115 ;
F_86 ( V_8 ) ;
F_87 ( V_8 , sizeof ( V_188 ) , & V_188 ) ;
V_8 -> V_189 = F_77 ( V_8 -> V_116 ) ;
F_87 ( V_8 , sizeof ( V_8 -> V_189 ) ,
& V_8 -> V_189 ) ;
V_8 -> V_184 = 1 ;
F_5 ( V_8 , V_4 ) ;
}
static void F_122 ( struct V_7 * V_8 )
{
F_39 ( L_30 , V_8 ,
V_8 -> V_116 , V_8 -> V_115 ) ;
V_8 -> V_116 = V_8 -> V_115 ;
F_86 ( V_8 ) ;
V_8 -> V_189 = F_77 ( V_8 -> V_116 ) ;
F_87 ( V_8 , sizeof ( V_8 -> V_189 ) ,
& V_8 -> V_189 ) ;
F_5 ( V_8 , V_4 ) ;
}
static void F_123 ( struct V_7 * V_8 )
{
F_39 ( L_31 , V_8 ) ;
F_86 ( V_8 ) ;
F_87 ( V_8 , sizeof ( V_203 ) , & V_203 ) ;
F_5 ( V_8 , V_4 ) ;
}
static struct V_204 * F_124 ( struct V_7 * V_8 ,
int * V_205 )
{
struct V_204 * V_206 ;
if ( ! V_8 -> V_75 -> V_207 ) {
V_8 -> V_208 . V_209 = V_210 ;
V_8 -> V_208 . V_211 = 0 ;
return NULL ;
}
F_75 ( & V_8 -> V_117 ) ;
V_206 = V_8 -> V_75 -> V_207 ( V_8 , V_205 , V_8 -> V_212 ) ;
F_73 ( & V_8 -> V_117 ) ;
if ( F_125 ( V_206 ) )
return V_206 ;
if ( V_8 -> V_56 != V_213 )
return F_126 ( - V_91 ) ;
V_8 -> V_214 = V_206 -> V_215 ;
V_8 -> V_216 = V_206 -> V_217 ;
return V_206 ;
}
static void F_127 ( struct V_7 * V_8 )
{
F_87 ( V_8 , strlen ( V_218 ) , V_218 ) ;
F_87 ( V_8 , sizeof ( V_8 -> V_30 -> V_31 ) ,
& V_8 -> V_30 -> V_31 ) ;
V_8 -> V_184 = 0 ;
F_5 ( V_8 , V_4 ) ;
}
static int F_128 ( struct V_7 * V_8 )
{
unsigned int V_133 = F_83 ( V_8 -> V_30 , 0 ) ;
int V_219 ;
int V_205 ;
struct V_204 * V_206 ;
switch ( V_8 -> V_125 . type ) {
case V_220 :
V_219 = V_221 ;
break;
case V_222 :
V_219 = V_223 ;
break;
case V_224 :
V_219 = V_225 ;
break;
default:
F_110 () ;
}
F_39 ( L_32 , V_8 ,
V_8 -> V_112 , V_133 , V_219 ) ;
V_8 -> V_208 . V_226 = F_77 ( V_8 -> V_30 -> V_227 ) ;
V_8 -> V_208 . V_228 = F_120 ( V_229 ) ;
V_8 -> V_208 . V_112 = F_120 ( V_8 -> V_112 ) ;
V_8 -> V_208 . V_133 = F_120 ( V_133 ) ;
V_8 -> V_208 . V_230 = F_120 ( V_219 ) ;
V_8 -> V_208 . V_9 = 0 ;
V_205 = V_210 ;
V_206 = F_124 ( V_8 , & V_205 ) ;
if ( F_125 ( V_206 ) )
return F_129 ( V_206 ) ;
V_8 -> V_208 . V_209 = F_120 ( V_205 ) ;
V_8 -> V_208 . V_211 = V_206 ?
F_120 ( V_206 -> V_231 ) : 0 ;
F_87 ( V_8 , sizeof ( V_8 -> V_208 ) ,
& V_8 -> V_208 ) ;
if ( V_206 && V_206 -> V_231 )
F_87 ( V_8 , V_206 -> V_231 ,
V_206 -> V_232 ) ;
V_8 -> V_184 = 0 ;
F_5 ( V_8 , V_4 ) ;
return 0 ;
}
static int F_130 ( struct V_7 * V_8 )
{
int V_68 ;
F_39 ( L_33 , V_8 , V_8 -> V_135 ) ;
while ( V_8 -> V_135 > 0 ) {
V_68 = F_60 ( V_8 -> V_49 , V_8 -> V_136 ,
V_8 -> V_134 , V_8 -> V_135 ,
V_8 -> V_184 ) ;
if ( V_68 <= 0 )
goto V_233;
V_8 -> V_135 -= V_68 ;
if ( V_8 -> V_135 == 0 )
break;
while ( V_68 >= V_8 -> V_136 -> V_140 ) {
F_3 ( ! V_8 -> V_134 ) ;
V_68 -= V_8 -> V_136 -> V_140 ;
V_8 -> V_136 ++ ;
V_8 -> V_134 -- ;
}
if ( V_68 ) {
V_8 -> V_136 -> V_140 -= V_68 ;
V_8 -> V_136 -> V_141 += V_68 ;
}
}
V_8 -> V_134 = 0 ;
V_8 -> V_183 = false ;
V_68 = 1 ;
V_233:
F_39 ( L_34 , V_8 ,
V_8 -> V_135 , V_8 -> V_134 , V_68 ) ;
return V_68 ;
}
static T_4 F_131 ( T_4 V_187 , struct V_92 * V_92 ,
unsigned int V_93 ,
unsigned int V_94 )
{
char * V_95 ;
V_95 = F_59 ( V_92 ) ;
F_3 ( V_95 == NULL ) ;
V_187 = F_118 ( V_187 , V_95 + V_93 , V_94 ) ;
F_25 ( V_92 ) ;
return V_187 ;
}
static int F_132 ( struct V_7 * V_8 )
{
struct V_35 * V_86 = V_8 -> V_114 ;
struct V_142 * V_143 = & V_86 -> V_143 ;
bool V_234 = ! V_8 -> V_30 -> V_235 ;
T_4 V_187 ;
F_39 ( L_35 , V_45 , V_8 , V_86 ) ;
if ( F_69 ( & V_86 -> V_138 ) )
return - V_236 ;
V_187 = V_234 ? F_116 ( V_86 -> V_181 . V_202 ) : 0 ;
while ( V_143 -> V_146 ) {
struct V_92 * V_92 ;
T_1 V_93 ;
T_1 V_94 ;
bool V_150 ;
bool V_173 ;
int V_68 ;
V_92 = F_108 ( & V_86 -> V_143 , & V_93 , & V_94 ,
& V_150 ) ;
V_68 = F_62 ( V_8 -> V_49 , V_92 , V_93 ,
V_94 , V_150 ) ;
if ( V_68 <= 0 ) {
if ( V_234 )
V_86 -> V_181 . V_202 = F_120 ( V_187 ) ;
return V_68 ;
}
if ( V_234 && V_143 -> V_173 )
V_187 = F_131 ( V_187 , V_92 , V_93 , V_94 ) ;
V_173 = F_109 ( & V_86 -> V_143 , ( T_1 ) V_68 ) ;
}
F_39 ( L_36 , V_45 , V_8 , V_86 ) ;
if ( V_234 )
V_86 -> V_181 . V_202 = F_120 ( V_187 ) ;
else
V_86 -> V_181 . V_9 |= V_237 ;
F_86 ( V_8 ) ;
F_112 ( V_8 ) ;
return 1 ;
}
static int F_133 ( struct V_7 * V_8 )
{
int V_68 ;
while ( V_8 -> V_238 > 0 ) {
T_1 V_102 = F_90 ( V_8 -> V_238 , ( int ) V_239 ) ;
V_68 = F_62 ( V_8 -> V_49 , V_40 , 0 , V_102 , true ) ;
if ( V_68 <= 0 )
goto V_233;
V_8 -> V_238 -= V_68 ;
}
V_68 = 1 ;
V_233:
return V_68 ;
}
static void F_134 ( struct V_7 * V_8 )
{
F_39 ( L_37 , V_8 ) ;
V_8 -> V_240 = 0 ;
}
static void F_135 ( struct V_7 * V_8 )
{
F_39 ( L_38 , V_8 ) ;
V_8 -> V_240 = 0 ;
}
static void F_136 ( struct V_7 * V_8 )
{
F_39 ( L_39 , V_8 ) ;
V_8 -> V_240 = 0 ;
}
static void F_137 ( struct V_7 * V_8 )
{
F_39 ( L_40 , V_8 ) ;
V_8 -> V_240 = 0 ;
V_8 -> V_241 = V_242 ;
}
static void F_138 ( struct V_7 * V_8 )
{
F_39 ( L_41 , V_8 ) ;
V_8 -> V_240 = 0 ;
V_8 -> V_241 = V_243 ;
}
static int F_139 ( struct V_7 * V_8 )
{
F_39 ( L_42 , V_8 ) ;
F_3 ( V_8 -> V_111 != NULL ) ;
V_8 -> V_240 = 0 ;
V_8 -> V_244 = V_8 -> V_245 = V_8 -> V_246 = 0 ;
return 0 ;
}
static int F_140 ( struct V_7 * V_8 ,
int V_247 , int V_102 , void * V_248 )
{
while ( V_8 -> V_240 < V_247 ) {
int V_249 = V_247 - V_8 -> V_240 ;
int V_250 = V_102 - V_249 ;
int V_68 = F_56 ( V_8 -> V_49 , V_248 + V_250 , V_249 ) ;
if ( V_68 <= 0 )
return V_68 ;
V_8 -> V_240 += V_68 ;
}
return 1 ;
}
static int F_141 ( struct V_7 * V_8 )
{
int V_102 ;
int V_247 ;
int V_68 ;
F_39 ( L_43 , V_8 , V_8 -> V_240 ) ;
V_102 = strlen ( V_218 ) ;
V_247 = V_102 ;
V_68 = F_140 ( V_8 , V_247 , V_102 , V_8 -> V_251 ) ;
if ( V_68 <= 0 )
goto V_233;
V_102 = sizeof ( V_8 -> V_252 ) ;
V_247 += V_102 ;
V_68 = F_140 ( V_8 , V_247 , V_102 , & V_8 -> V_252 ) ;
if ( V_68 <= 0 )
goto V_233;
V_102 = sizeof ( V_8 -> V_253 ) ;
V_247 += V_102 ;
V_68 = F_140 ( V_8 , V_247 , V_102 , & V_8 -> V_253 ) ;
if ( V_68 <= 0 )
goto V_233;
V_233:
return V_68 ;
}
static int F_142 ( struct V_7 * V_8 )
{
int V_102 ;
int V_247 ;
int V_68 ;
F_39 ( L_44 , V_8 , V_8 -> V_240 ) ;
V_102 = sizeof ( V_8 -> V_254 ) ;
V_247 = V_102 ;
V_68 = F_140 ( V_8 , V_247 , V_102 , & V_8 -> V_254 ) ;
if ( V_68 <= 0 )
goto V_233;
V_102 = F_116 ( V_8 -> V_254 . V_211 ) ;
V_247 += V_102 ;
V_68 = F_140 ( V_8 , V_247 , V_102 , V_8 -> V_214 ) ;
if ( V_68 <= 0 )
goto V_233;
F_39 ( L_45 ,
V_8 , ( int ) V_8 -> V_254 . V_255 ,
F_116 ( V_8 -> V_254 . V_112 ) ,
F_116 ( V_8 -> V_254 . V_133 ) ) ;
V_233:
return V_68 ;
}
static int F_143 ( struct V_7 * V_8 )
{
if ( memcmp ( V_8 -> V_251 , V_218 , strlen ( V_218 ) ) ) {
F_31 ( L_46 ,
F_13 ( & V_8 -> V_66 . V_67 ) ) ;
V_8 -> V_80 = L_47 ;
return - 1 ;
}
return 0 ;
}
static bool F_144 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_21 ) {
case V_22 :
return ( (struct V_14 * ) V_11 ) -> V_24 . V_256 == 0 ;
case V_26 :
return
( (struct V_16 * ) V_11 ) -> V_27 . V_257 [ 0 ] == 0 &&
( (struct V_16 * ) V_11 ) -> V_27 . V_257 [ 1 ] == 0 &&
( (struct V_16 * ) V_11 ) -> V_27 . V_257 [ 2 ] == 0 &&
( (struct V_16 * ) V_11 ) -> V_27 . V_257 [ 3 ] == 0 ;
}
return false ;
}
static int F_145 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_21 ) {
case V_22 :
return F_15 ( ( (struct V_14 * ) V_11 ) -> V_25 ) ;
case V_26 :
return F_15 ( ( (struct V_16 * ) V_11 ) -> V_28 ) ;
}
return 0 ;
}
static void F_146 ( struct V_10 * V_11 , int V_258 )
{
switch ( V_11 -> V_21 ) {
case V_22 :
( (struct V_14 * ) V_11 ) -> V_25 = F_147 ( V_258 ) ;
break;
case V_26 :
( (struct V_16 * ) V_11 ) -> V_28 = F_147 ( V_258 ) ;
break;
}
}
static int F_148 ( const char * V_259 , T_1 V_82 , struct V_10 * V_11 ,
char V_260 , const char * * V_261 )
{
struct V_14 * V_15 = (struct V_14 * ) V_11 ;
struct V_16 * V_17 = (struct V_16 * ) V_11 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
if ( F_149 ( V_259 , V_82 , ( V_262 * ) & V_15 -> V_24 . V_256 , V_260 , V_261 ) ) {
V_11 -> V_21 = V_22 ;
return 0 ;
}
if ( F_150 ( V_259 , V_82 , ( V_262 * ) & V_17 -> V_27 . V_263 , V_260 , V_261 ) ) {
V_11 -> V_21 = V_26 ;
return 0 ;
}
return - V_236 ;
}
static int F_151 ( const char * V_264 , T_1 V_265 ,
struct V_10 * V_11 , char V_260 , const char * * V_261 )
{
const char * V_247 , * V_266 ;
char * V_267 , * V_268 = NULL ;
int V_269 , V_68 ;
V_266 = memchr ( V_264 , V_260 , V_265 ) ;
V_267 = memchr ( V_264 , ':' , V_265 ) ;
if ( V_266 && V_267 )
V_247 = V_266 < V_267 ? V_266 : V_267 ;
else if ( ! V_266 && V_267 )
V_247 = V_267 ;
else {
V_247 = V_266 ;
if ( ! V_247 )
V_247 = V_264 + V_265 ;
}
if ( V_247 <= V_264 )
return - V_236 ;
V_269 = F_152 ( NULL , V_264 , V_247 - V_264 , NULL , & V_268 , NULL ) ;
if ( V_269 > 0 )
V_68 = F_148 ( V_268 , V_269 , V_11 , - 1 , NULL ) ;
else
V_68 = - V_270 ;
F_153 ( V_268 ) ;
* V_261 = V_247 ;
F_154 ( L_48 , ( int ) ( V_247 - V_264 ) , V_264 ,
V_68 , V_68 ? L_49 : F_13 ( V_11 ) ) ;
return V_68 ;
}
static inline int F_151 ( const char * V_264 , T_1 V_265 ,
struct V_10 * V_11 , char V_260 , const char * * V_261 )
{
return - V_236 ;
}
static int F_155 ( const char * V_264 , T_1 V_265 ,
struct V_10 * V_11 , char V_260 , const char * * V_261 )
{
int V_68 ;
V_68 = F_148 ( V_264 , V_265 , V_11 , V_260 , V_261 ) ;
if ( V_68 )
V_68 = F_151 ( V_264 , V_265 , V_11 , V_260 , V_261 ) ;
return V_68 ;
}
int F_156 ( const char * V_271 , const char * V_247 ,
struct V_123 * V_33 ,
int V_272 , int * V_273 )
{
int V_12 , V_68 = - V_236 ;
const char * V_258 = V_271 ;
F_39 ( L_50 , ( int ) ( V_247 - V_271 ) , V_271 ) ;
for ( V_12 = 0 ; V_12 < V_272 ; V_12 ++ ) {
const char * V_261 ;
struct V_10 * V_11 = & V_33 [ V_12 ] . V_67 ;
int V_274 ;
char V_260 = ',' ;
if ( * V_258 == '[' ) {
V_260 = ']' ;
V_258 ++ ;
}
V_68 = F_155 ( V_258 , V_247 - V_258 , V_11 , V_260 , & V_261 ) ;
if ( V_68 )
goto V_275;
V_68 = - V_236 ;
V_258 = V_261 ;
if ( V_260 == ']' ) {
if ( * V_258 != ']' ) {
F_39 ( L_51 ) ;
goto V_275;
}
V_258 ++ ;
}
if ( V_258 < V_247 && * V_258 == ':' ) {
V_274 = 0 ;
V_258 ++ ;
while ( V_258 < V_247 && * V_258 >= '0' && * V_258 <= '9' ) {
V_274 = ( V_274 * 10 ) + ( * V_258 - '0' ) ;
V_258 ++ ;
}
if ( V_274 == 0 )
V_274 = V_276 ;
else if ( V_274 > 65535 )
goto V_275;
} else {
V_274 = V_276 ;
}
F_146 ( V_11 , V_274 ) ;
F_39 ( L_52 , F_13 ( V_11 ) ) ;
if ( V_258 == V_247 )
break;
if ( * V_258 != ',' )
goto V_275;
V_258 ++ ;
}
if ( V_258 != V_247 )
goto V_275;
if ( V_273 )
* V_273 = V_12 + 1 ;
return 0 ;
V_275:
F_31 ( L_53 , ( int ) ( V_247 - V_271 ) , V_271 ) ;
return V_68 ;
}
static int F_157 ( struct V_7 * V_8 )
{
F_39 ( L_54 , V_8 ) ;
if ( F_143 ( V_8 ) < 0 )
return - 1 ;
F_158 ( & V_8 -> V_252 ) ;
F_158 ( & V_8 -> V_253 ) ;
if ( memcmp ( & V_8 -> V_66 , & V_8 -> V_252 ,
sizeof( V_8 -> V_66 ) ) != 0 &&
! ( F_144 ( & V_8 -> V_252 . V_67 ) &&
V_8 -> V_252 . V_277 == V_8 -> V_66 . V_277 ) ) {
F_159 ( L_55 ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
( int ) F_116 ( V_8 -> V_66 . V_277 ) ,
F_13 ( & V_8 -> V_252 . V_67 ) ,
( int ) F_116 ( V_8 -> V_252 . V_277 ) ) ;
V_8 -> V_80 = L_56 ;
return - 1 ;
}
if ( F_144 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ) ) {
int V_274 = F_145 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ) ;
memcpy ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ,
& V_8 -> V_253 . V_67 ,
sizeof( V_8 -> V_253 . V_67 ) ) ;
F_146 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 , V_274 ) ;
F_16 ( V_8 -> V_30 ) ;
F_39 ( L_57 ,
F_13 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ) ) ;
}
return 0 ;
}
static int F_160 ( struct V_7 * V_8 )
{
V_162 V_278 = V_8 -> V_30 -> V_227 ;
V_162 V_279 = V_8 -> V_30 -> V_280 ;
V_162 V_281 = F_161 (
F_162 ( V_8 -> V_254 . V_226 ) ) ;
int V_68 ;
F_39 ( L_58 , V_8 , ( int ) V_8 -> V_241 ) ;
switch ( V_8 -> V_254 . V_255 ) {
case V_282 :
F_31 ( L_59
L_60 ,
F_163 ( V_8 -> V_125 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_278 , V_281 , V_281 & ~ V_278 ) ;
V_8 -> V_80 = L_61 ;
F_71 ( V_8 ) ;
return - 1 ;
case V_283 :
F_31 ( L_62
L_63 ,
F_163 ( V_8 -> V_125 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
F_116 ( V_8 -> V_208 . V_230 ) ,
F_116 ( V_8 -> V_254 . V_230 ) ) ;
V_8 -> V_80 = L_64 ;
F_71 ( V_8 ) ;
return - 1 ;
case V_284 :
V_8 -> V_212 ++ ;
F_39 ( L_65 , V_8 ,
V_8 -> V_212 ) ;
if ( V_8 -> V_212 == 2 ) {
V_8 -> V_80 = L_66 ;
return - 1 ;
}
F_86 ( V_8 ) ;
V_68 = F_128 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_135 ( V_8 ) ;
break;
case V_285 :
F_39 ( L_67 ,
F_116 ( V_8 -> V_254 . V_112 ) ) ;
F_31 ( L_68 ,
F_163 ( V_8 -> V_125 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ) ;
F_71 ( V_8 ) ;
F_86 ( V_8 ) ;
V_68 = F_128 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_135 ( V_8 ) ;
F_75 ( & V_8 -> V_117 ) ;
F_154 ( L_69 , F_163 ( V_8 -> V_125 ) ) ;
if ( V_8 -> V_75 -> V_286 )
V_8 -> V_75 -> V_286 ( V_8 ) ;
F_73 ( & V_8 -> V_117 ) ;
if ( V_8 -> V_56 != V_213 )
return - V_91 ;
break;
case V_287 :
F_39 ( L_70 ,
F_116 ( V_8 -> V_208 . V_112 ) ,
F_116 ( V_8 -> V_254 . V_112 ) ) ;
V_8 -> V_112 = F_116 ( V_8 -> V_254 . V_112 ) ;
F_86 ( V_8 ) ;
V_68 = F_128 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_135 ( V_8 ) ;
break;
case V_288 :
F_39 ( L_71 ,
V_8 -> V_119 ,
F_116 ( V_8 -> V_254 . V_133 ) ) ;
F_83 ( V_8 -> V_30 ,
F_116 ( V_8 -> V_254 . V_133 ) ) ;
F_86 ( V_8 ) ;
V_68 = F_128 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_135 ( V_8 ) ;
break;
case V_242 :
case V_243 :
if ( V_279 & ~ V_281 ) {
F_31 ( L_72
L_73 ,
F_163 ( V_8 -> V_125 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_279 , V_281 , V_279 & ~ V_281 ) ;
V_8 -> V_80 = L_61 ;
F_71 ( V_8 ) ;
return - 1 ;
}
F_37 ( V_8 -> V_56 != V_213 ) ;
V_8 -> V_56 = V_289 ;
V_8 -> V_212 = 0 ;
V_8 -> V_119 = F_116 ( V_8 -> V_254 . V_133 ) ;
V_8 -> V_112 ++ ;
V_8 -> V_290 = V_281 ;
F_39 ( L_74 ,
V_8 -> V_119 ,
F_116 ( V_8 -> V_254 . V_112 ) ,
V_8 -> V_112 ) ;
F_37 ( V_8 -> V_112 !=
F_116 ( V_8 -> V_254 . V_112 ) ) ;
if ( V_8 -> V_254 . V_9 & V_291 )
F_5 ( V_8 , V_2 ) ;
V_8 -> V_127 = 0 ;
if ( V_8 -> V_254 . V_255 == V_242 ) {
F_122 ( V_8 ) ;
F_137 ( V_8 ) ;
} else {
F_138 ( V_8 ) ;
}
break;
case V_292 :
F_31 ( L_75 ) ;
V_8 -> V_80 = L_76 ;
return - 1 ;
default:
F_31 ( L_77 ) ;
V_8 -> V_80 = L_78 ;
return - 1 ;
}
return 0 ;
}
static int F_164 ( struct V_7 * V_8 )
{
int V_102 = sizeof ( V_8 -> V_293 ) ;
int V_247 = V_102 ;
return F_140 ( V_8 , V_247 , V_102 , & V_8 -> V_293 ) ;
}
static void F_165 ( struct V_7 * V_8 )
{
struct V_35 * V_179 ;
V_162 V_294 = F_162 ( V_8 -> V_293 ) ;
V_162 V_192 ;
while ( ! F_69 ( & V_8 -> V_110 ) ) {
V_179 = F_70 ( & V_8 -> V_110 , struct V_35 ,
V_106 ) ;
V_192 = F_162 ( V_179 -> V_191 . V_192 ) ;
if ( V_192 > V_294 )
break;
F_39 ( L_79 , V_192 ,
F_117 ( V_179 -> V_191 . type ) , V_179 ) ;
V_179 -> V_295 = V_296 ;
F_65 ( V_179 ) ;
}
F_138 ( V_8 ) ;
}
static int F_166 ( struct V_7 * V_8 ,
struct V_83 * V_297 ,
unsigned int V_298 , T_4 * V_187 )
{
int V_68 , V_249 ;
F_3 ( ! V_297 ) ;
while ( V_297 -> V_140 < V_298 ) {
F_3 ( V_297 -> V_141 == NULL ) ;
V_249 = V_298 - V_297 -> V_140 ;
V_68 = F_56 ( V_8 -> V_49 , ( char * ) V_297 -> V_141 +
V_297 -> V_140 , V_249 ) ;
if ( V_68 <= 0 )
return V_68 ;
V_297 -> V_140 += V_68 ;
}
if ( V_297 -> V_140 == V_298 )
* V_187 = F_118 ( 0 , V_297 -> V_141 , V_297 -> V_140 ) ;
return 1 ;
}
static int F_167 ( struct V_7 * V_8 )
{
struct V_35 * V_86 = V_8 -> V_111 ;
struct V_142 * V_143 = & V_86 -> V_143 ;
const bool V_234 = ! V_8 -> V_30 -> V_235 ;
struct V_92 * V_92 ;
T_1 V_93 ;
T_1 V_94 ;
T_4 V_187 = 0 ;
int V_68 ;
F_3 ( ! V_86 ) ;
if ( F_69 ( & V_86 -> V_138 ) )
return - V_299 ;
if ( V_234 )
V_187 = V_8 -> V_246 ;
while ( V_143 -> V_146 ) {
V_92 = F_108 ( & V_86 -> V_143 , & V_93 , & V_94 ,
NULL ) ;
V_68 = F_58 ( V_8 -> V_49 , V_92 , V_93 , V_94 ) ;
if ( V_68 <= 0 ) {
if ( V_234 )
V_8 -> V_246 = V_187 ;
return V_68 ;
}
if ( V_234 )
V_187 = F_131 ( V_187 , V_92 , V_93 , V_68 ) ;
( void ) F_109 ( & V_86 -> V_143 , ( T_1 ) V_68 ) ;
}
if ( V_234 )
V_8 -> V_246 = V_187 ;
return 1 ;
}
static int F_168 ( struct V_7 * V_8 )
{
struct V_35 * V_179 = V_8 -> V_111 ;
int V_102 ;
int V_247 ;
int V_68 ;
unsigned int V_193 , V_194 , V_178 ;
bool V_234 = ! V_8 -> V_30 -> V_235 ;
V_162 V_192 ;
T_4 V_187 ;
F_39 ( L_80 , V_8 , V_179 ) ;
V_102 = sizeof ( V_8 -> V_300 ) ;
V_247 = V_102 ;
V_68 = F_140 ( V_8 , V_247 , V_102 , & V_8 -> V_300 ) ;
if ( V_68 <= 0 )
return V_68 ;
V_187 = F_118 ( 0 , & V_8 -> V_300 , F_119 ( struct V_199 , V_187 ) ) ;
if ( F_120 ( V_187 ) != V_8 -> V_300 . V_187 ) {
F_31 ( L_81
L_82 ,
V_187 , V_8 -> V_300 . V_187 ) ;
return - V_301 ;
}
V_193 = F_116 ( V_8 -> V_300 . V_193 ) ;
if ( V_193 > V_302 )
return - V_299 ;
V_194 = F_116 ( V_8 -> V_300 . V_194 ) ;
if ( V_194 > V_303 )
return - V_299 ;
V_178 = F_116 ( V_8 -> V_300 . V_178 ) ;
if ( V_178 > V_304 )
return - V_299 ;
V_192 = F_162 ( V_8 -> V_300 . V_192 ) ;
if ( ( V_305 ) V_192 - ( V_305 ) V_8 -> V_115 < 1 ) {
F_154 ( L_83 ,
F_163 ( V_8 -> V_125 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_192 , V_8 -> V_115 + 1 ) ;
V_8 -> V_240 = - V_193 - V_194 - V_178 -
sizeof( V_179 -> V_181 ) ;
V_8 -> V_241 = V_243 ;
return 0 ;
} else if ( ( V_305 ) V_192 - ( V_305 ) V_8 -> V_115 > 1 ) {
F_31 ( L_84 ,
V_192 , V_8 -> V_115 + 1 ) ;
V_8 -> V_80 = L_85 ;
return - V_301 ;
}
if ( ! V_8 -> V_111 ) {
int V_306 = 0 ;
F_39 ( L_86 , V_8 -> V_300 . type ,
V_193 , V_178 ) ;
V_68 = F_169 ( V_8 , & V_306 ) ;
if ( V_68 < 0 )
return V_68 ;
F_3 ( ! V_8 -> V_111 ^ V_306 ) ;
if ( V_8 -> V_111 && V_178 > V_8 -> V_111 -> V_174 ) {
F_159 ( L_87 ,
V_45 , V_178 , V_8 -> V_111 -> V_174 ) ;
F_67 ( V_8 -> V_111 ) ;
V_8 -> V_111 = NULL ;
V_306 = 1 ;
}
if ( V_306 ) {
F_39 ( L_88 ) ;
V_8 -> V_240 = - V_193 - V_194 - V_178 -
sizeof( V_179 -> V_181 ) ;
V_8 -> V_241 = V_243 ;
V_8 -> V_115 ++ ;
return 0 ;
}
F_3 ( ! V_8 -> V_111 ) ;
F_3 ( V_8 -> V_111 -> V_8 != V_8 ) ;
V_179 = V_8 -> V_111 ;
V_179 -> V_195 . V_140 = 0 ;
if ( V_179 -> V_197 )
V_179 -> V_197 -> V_198 . V_140 = 0 ;
if ( V_178 )
F_111 ( V_8 -> V_111 , V_178 ) ;
}
V_68 = F_166 ( V_8 , & V_179 -> V_195 , V_193 ,
& V_8 -> V_244 ) ;
if ( V_68 <= 0 )
return V_68 ;
if ( V_179 -> V_197 ) {
V_68 = F_166 ( V_8 , & V_179 -> V_197 -> V_198 ,
V_194 ,
& V_8 -> V_245 ) ;
if ( V_68 <= 0 )
return V_68 ;
}
if ( V_178 ) {
V_68 = F_167 ( V_8 ) ;
if ( V_68 <= 0 )
return V_68 ;
}
V_102 = sizeof ( V_179 -> V_181 ) ;
V_247 += V_102 ;
V_68 = F_140 ( V_8 , V_247 , V_102 , & V_179 -> V_181 ) ;
if ( V_68 <= 0 )
return V_68 ;
F_39 ( L_89 ,
V_179 , V_193 , V_179 -> V_181 . V_200 , V_194 ,
V_179 -> V_181 . V_201 , V_178 , V_179 -> V_181 . V_202 ) ;
if ( V_8 -> V_244 != F_116 ( V_179 -> V_181 . V_200 ) ) {
F_31 ( L_90 ,
V_179 , V_8 -> V_244 , V_179 -> V_181 . V_200 ) ;
return - V_301 ;
}
if ( V_8 -> V_245 != F_116 ( V_179 -> V_181 . V_201 ) ) {
F_31 ( L_91 ,
V_179 , V_8 -> V_245 , V_179 -> V_181 . V_201 ) ;
return - V_301 ;
}
if ( V_234 &&
( V_179 -> V_181 . V_9 & V_237 ) == 0 &&
V_8 -> V_246 != F_116 ( V_179 -> V_181 . V_202 ) ) {
F_31 ( L_92 , V_179 ,
V_8 -> V_246 , F_116 ( V_179 -> V_181 . V_202 ) ) ;
return - V_301 ;
}
return 1 ;
}
static void F_170 ( struct V_7 * V_8 )
{
struct V_35 * V_86 ;
F_3 ( V_8 -> V_111 -> V_8 != V_8 ) ;
V_8 -> V_111 -> V_8 = NULL ;
V_86 = V_8 -> V_111 ;
V_8 -> V_111 = NULL ;
V_8 -> V_75 -> V_107 ( V_8 ) ;
if ( V_8 -> V_125 . type == 0 )
V_8 -> V_125 = V_86 -> V_191 . V_307 ;
V_8 -> V_115 ++ ;
F_75 ( & V_8 -> V_117 ) ;
F_39 ( L_93 ,
V_86 , F_162 ( V_86 -> V_191 . V_192 ) ,
F_163 ( V_86 -> V_191 . V_307 ) ,
F_117 ( V_86 -> V_191 . type ) ,
F_171 ( F_117 ( V_86 -> V_191 . type ) ) ,
F_116 ( V_86 -> V_191 . V_193 ) ,
F_116 ( V_86 -> V_191 . V_178 ) ,
V_8 -> V_244 , V_8 -> V_245 , V_8 -> V_246 ) ;
V_8 -> V_75 -> V_308 ( V_8 , V_86 ) ;
F_73 ( & V_8 -> V_117 ) ;
}
static int F_172 ( struct V_7 * V_8 )
{
int V_68 = 1 ;
F_39 ( L_94 , V_8 , V_8 -> V_56 ) ;
V_98:
F_39 ( L_95 , V_8 -> V_135 ) ;
if ( V_8 -> V_56 == V_124 ) {
F_3 ( V_8 -> V_49 ) ;
V_8 -> V_56 = V_309 ;
F_86 ( V_8 ) ;
F_127 ( V_8 ) ;
F_134 ( V_8 ) ;
F_3 ( V_8 -> V_111 ) ;
V_8 -> V_241 = V_243 ;
F_39 ( L_96 ,
V_8 , V_8 -> V_56 ) ;
V_68 = F_51 ( V_8 ) ;
if ( V_68 < 0 ) {
V_8 -> V_80 = L_20 ;
goto V_233;
}
}
V_310:
if ( V_8 -> V_238 ) {
V_68 = F_133 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_233;
}
if ( V_8 -> V_134 ) {
V_68 = F_130 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_233;
}
if ( V_8 -> V_114 ) {
if ( V_8 -> V_186 ) {
F_67 ( V_8 -> V_114 ) ;
V_8 -> V_114 = NULL ;
goto V_311;
}
V_68 = F_132 ( V_8 ) ;
if ( V_68 == 1 )
goto V_310;
if ( V_68 == 0 )
goto V_233;
if ( V_68 < 0 ) {
F_39 ( L_97 ,
V_68 ) ;
goto V_233;
}
}
V_311:
if ( V_8 -> V_56 == V_289 ) {
if ( ! F_69 ( & V_8 -> V_109 ) ) {
F_113 ( V_8 ) ;
goto V_98;
}
if ( V_8 -> V_115 > V_8 -> V_116 ) {
F_121 ( V_8 ) ;
goto V_98;
}
if ( F_9 ( V_8 , V_3 ) ) {
F_123 ( V_8 ) ;
goto V_98;
}
}
F_2 ( V_8 , V_4 ) ;
F_39 ( L_98 ) ;
V_68 = 0 ;
V_233:
F_39 ( L_99 , V_8 , V_68 ) ;
return V_68 ;
}
static int F_173 ( struct V_7 * V_8 )
{
int V_68 = - 1 ;
V_98:
F_39 ( L_100 , V_8 , V_8 -> V_56 ) ;
if ( V_8 -> V_56 != V_309 &&
V_8 -> V_56 != V_213 &&
V_8 -> V_56 != V_289 )
return 0 ;
F_3 ( ! V_8 -> V_49 ) ;
F_39 ( L_101 , ( int ) V_8 -> V_241 ,
V_8 -> V_240 ) ;
if ( V_8 -> V_56 == V_309 ) {
F_39 ( L_102 ) ;
V_68 = F_141 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_233;
V_68 = F_157 ( V_8 ) ;
if ( V_68 < 0 )
goto V_233;
V_8 -> V_56 = V_213 ;
V_68 = F_128 ( V_8 ) ;
if ( V_68 < 0 )
goto V_233;
F_135 ( V_8 ) ;
goto V_233;
}
if ( V_8 -> V_56 == V_213 ) {
F_39 ( L_103 ) ;
V_68 = F_142 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_233;
V_68 = F_160 ( V_8 ) ;
if ( V_68 < 0 )
goto V_233;
goto V_98;
}
F_37 ( V_8 -> V_56 != V_289 ) ;
if ( V_8 -> V_240 < 0 ) {
static char V_81 [ V_312 ] ;
int V_306 = F_90 ( ( int ) sizeof ( V_81 ) , - V_8 -> V_240 ) ;
F_39 ( L_104 , V_306 , - V_8 -> V_240 ) ;
V_68 = F_56 ( V_8 -> V_49 , V_81 , V_306 ) ;
if ( V_68 <= 0 )
goto V_233;
V_8 -> V_240 += V_68 ;
if ( V_8 -> V_240 )
goto V_98;
}
if ( V_8 -> V_241 == V_243 ) {
V_68 = F_56 ( V_8 -> V_49 , & V_8 -> V_241 , 1 ) ;
if ( V_68 <= 0 )
goto V_233;
F_39 ( L_105 , ( int ) V_8 -> V_241 ) ;
switch ( V_8 -> V_241 ) {
case V_313 :
F_139 ( V_8 ) ;
break;
case V_314 :
F_136 ( V_8 ) ;
break;
case V_315 :
F_64 ( V_8 ) ;
V_8 -> V_56 = V_118 ;
goto V_233;
default:
goto V_316;
}
}
if ( V_8 -> V_241 == V_313 ) {
V_68 = F_168 ( V_8 ) ;
if ( V_68 <= 0 ) {
switch ( V_68 ) {
case - V_301 :
V_8 -> V_80 = L_106 ;
V_68 = - V_299 ;
break;
case - V_299 :
V_8 -> V_80 = L_107 ;
break;
}
goto V_233;
}
if ( V_8 -> V_241 == V_243 )
goto V_98;
F_170 ( V_8 ) ;
if ( V_8 -> V_56 == V_289 )
F_138 ( V_8 ) ;
goto V_98;
}
if ( V_8 -> V_241 == V_314 ||
V_8 -> V_241 == V_242 ) {
V_68 = F_164 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_233;
F_165 ( V_8 ) ;
goto V_98;
}
V_233:
F_39 ( L_108 , V_8 , V_68 ) ;
return V_68 ;
V_316:
F_31 ( L_109 , ( int ) V_8 -> V_241 ) ;
V_8 -> V_80 = L_110 ;
V_68 = - 1 ;
goto V_233;
}
static int F_174 ( struct V_7 * V_8 , unsigned long V_127 )
{
if ( ! V_8 -> V_75 -> V_317 ( V_8 ) ) {
F_39 ( L_111 , V_45 , V_8 ) ;
return - V_318 ;
}
if ( ! F_175 ( V_39 , & V_8 -> V_120 , V_127 ) ) {
F_39 ( L_112 , V_45 , V_8 ) ;
V_8 -> V_75 -> V_107 ( V_8 ) ;
return - V_319 ;
}
F_39 ( L_113 , V_45 , V_8 , V_127 ) ;
return 0 ;
}
static void F_46 ( struct V_7 * V_8 )
{
( void ) F_174 ( V_8 , 0 ) ;
}
static bool F_176 ( struct V_7 * V_8 )
{
if ( ! F_9 ( V_8 , V_5 ) )
return false ;
#define CASE ( T_5 ) \
case CON_STATE_ ## x: \
con->error_msg = "socket closed (con state " #x ")"; \
break;
switch ( V_8 -> V_56 ) {
CASE ( V_320 ) ;
CASE ( V_321 ) ;
CASE ( V_322 ) ;
CASE ( V_323 ) ;
CASE ( V_324 ) ;
CASE ( V_325 ) ;
default:
F_159 ( L_114 ,
V_45 , V_8 , V_8 -> V_56 ) ;
V_8 -> V_80 = L_115 ;
F_110 () ;
break;
}
#undef CASE
return true ;
}
static bool F_177 ( struct V_7 * V_8 )
{
int V_68 ;
if ( ! F_9 ( V_8 , V_6 ) )
return false ;
V_68 = F_174 ( V_8 , F_178 ( V_8 -> V_127 ) ) ;
if ( V_68 ) {
F_39 ( L_116 , V_45 ,
V_8 , V_8 -> V_127 ) ;
F_3 ( V_68 == - V_318 ) ;
F_5 ( V_8 , V_6 ) ;
}
return true ;
}
static void F_179 ( struct V_7 * V_8 )
{
if ( V_8 -> V_212 && V_8 -> V_75 -> V_326 ) {
F_39 ( L_117 ) ;
V_8 -> V_75 -> V_326 ( V_8 ) ;
}
if ( V_8 -> V_75 -> V_327 )
V_8 -> V_75 -> V_327 ( V_8 ) ;
}
static void V_130 ( struct V_328 * V_120 )
{
struct V_7 * V_8 = F_180 ( V_120 , struct V_7 ,
V_120 . V_120 ) ;
bool V_327 ;
F_73 ( & V_8 -> V_117 ) ;
while ( true ) {
int V_68 ;
if ( ( V_327 = F_176 ( V_8 ) ) ) {
F_39 ( L_118 , V_45 , V_8 ) ;
break;
}
if ( F_177 ( V_8 ) ) {
F_39 ( L_119 , V_45 , V_8 ) ;
break;
}
if ( V_8 -> V_56 == V_329 ) {
F_39 ( L_120 , V_45 , V_8 ) ;
break;
}
if ( V_8 -> V_56 == V_118 ) {
F_39 ( L_121 , V_45 , V_8 ) ;
F_3 ( V_8 -> V_49 ) ;
break;
}
if ( V_8 -> V_56 == V_124 ) {
F_39 ( L_122 , V_45 , V_8 ) ;
F_3 ( V_8 -> V_49 ) ;
}
V_68 = F_173 ( V_8 ) ;
if ( V_68 < 0 ) {
if ( V_68 == - V_91 )
continue;
V_8 -> V_80 = L_123 ;
V_327 = true ;
break;
}
V_68 = F_172 ( V_8 ) ;
if ( V_68 < 0 ) {
if ( V_68 == - V_91 )
continue;
V_8 -> V_80 = L_124 ;
V_327 = true ;
}
break;
}
if ( V_327 )
F_181 ( V_8 ) ;
F_75 ( & V_8 -> V_117 ) ;
if ( V_327 )
F_179 ( V_8 ) ;
V_8 -> V_75 -> V_107 ( V_8 ) ;
}
static void F_181 ( struct V_7 * V_8 )
{
F_159 ( L_125 , F_163 ( V_8 -> V_125 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) , V_8 -> V_80 ) ;
F_39 ( L_126 ,
V_8 , V_8 -> V_56 , F_13 ( & V_8 -> V_66 . V_67 ) ) ;
F_37 ( V_8 -> V_56 != V_309 &&
V_8 -> V_56 != V_213 &&
V_8 -> V_56 != V_289 ) ;
F_64 ( V_8 ) ;
if ( F_7 ( V_8 , V_2 ) ) {
F_39 ( L_127 ) ;
V_8 -> V_56 = V_118 ;
return;
}
if ( V_8 -> V_111 ) {
F_3 ( V_8 -> V_111 -> V_8 != V_8 ) ;
V_8 -> V_111 -> V_8 = NULL ;
F_67 ( V_8 -> V_111 ) ;
V_8 -> V_111 = NULL ;
V_8 -> V_75 -> V_107 ( V_8 ) ;
}
F_182 ( & V_8 -> V_110 , & V_8 -> V_109 ) ;
if ( F_69 ( & V_8 -> V_109 ) &&
! F_7 ( V_8 , V_3 ) ) {
F_39 ( L_128 , V_8 ) ;
F_2 ( V_8 , V_4 ) ;
V_8 -> V_56 = V_329 ;
} else {
V_8 -> V_56 = V_124 ;
if ( V_8 -> V_127 == 0 )
V_8 -> V_127 = V_330 ;
else if ( V_8 -> V_127 < V_331 )
V_8 -> V_127 *= 2 ;
F_5 ( V_8 , V_6 ) ;
F_46 ( V_8 ) ;
}
}
void F_183 ( struct V_29 * V_30 ,
struct V_123 * V_332 ,
V_162 V_227 ,
V_162 V_280 ,
bool V_235 )
{
V_30 -> V_227 = V_227 ;
V_30 -> V_280 = V_280 ;
F_184 ( & V_30 -> V_132 ) ;
if ( V_332 )
V_30 -> V_32 . V_33 = * V_332 ;
V_30 -> V_32 . V_33 . type = 0 ;
F_185 ( & V_30 -> V_32 . V_33 . V_277 , sizeof( V_30 -> V_32 . V_33 . V_277 ) ) ;
F_16 ( V_30 ) ;
V_30 -> V_235 = V_235 ;
F_186 ( & V_30 -> V_53 , 0 ) ;
F_39 ( L_129 , V_45 , V_30 ) ;
}
static void F_187 ( struct V_7 * V_8 )
{
if ( V_8 -> V_56 == V_329 ) {
F_39 ( L_130 , V_8 ) ;
V_8 -> V_56 = V_124 ;
V_8 -> V_112 ++ ;
F_37 ( F_7 ( V_8 , V_4 ) ) ;
F_37 ( F_7 ( V_8 , V_3 ) ) ;
}
}
void F_188 ( struct V_7 * V_8 , struct V_35 * V_86 )
{
V_86 -> V_191 . V_307 = V_8 -> V_30 -> V_32 . V_264 ;
F_3 ( V_86 -> V_195 . V_140 != F_116 ( V_86 -> V_191 . V_193 ) ) ;
V_86 -> V_190 = true ;
F_73 ( & V_8 -> V_117 ) ;
if ( V_8 -> V_56 == V_118 ) {
F_39 ( L_131 , V_8 , V_86 ) ;
F_67 ( V_86 ) ;
F_75 ( & V_8 -> V_117 ) ;
return;
}
F_3 ( V_86 -> V_8 != NULL ) ;
V_86 -> V_8 = V_8 -> V_75 -> V_317 ( V_8 ) ;
F_3 ( V_86 -> V_8 == NULL ) ;
F_3 ( ! F_69 ( & V_86 -> V_106 ) ) ;
F_189 ( & V_86 -> V_106 , & V_8 -> V_109 ) ;
F_39 ( L_132 , V_86 ,
F_163 ( V_8 -> V_125 ) , F_117 ( V_86 -> V_191 . type ) ,
F_171 ( F_117 ( V_86 -> V_191 . type ) ) ,
F_116 ( V_86 -> V_191 . V_193 ) ,
F_116 ( V_86 -> V_191 . V_194 ) ,
F_116 ( V_86 -> V_191 . V_178 ) ) ;
F_187 ( V_8 ) ;
F_75 ( & V_8 -> V_117 ) ;
if ( F_11 ( V_8 , V_4 ) == 0 )
F_46 ( V_8 ) ;
}
void F_190 ( struct V_35 * V_86 )
{
struct V_7 * V_8 = V_86 -> V_8 ;
if ( ! V_8 )
return;
F_73 ( & V_8 -> V_117 ) ;
if ( ! F_69 ( & V_86 -> V_106 ) ) {
F_39 ( L_133 , V_45 , V_8 , V_86 ) ;
F_66 ( & V_86 -> V_106 ) ;
F_3 ( V_86 -> V_8 == NULL ) ;
V_86 -> V_8 -> V_75 -> V_107 ( V_86 -> V_8 ) ;
V_86 -> V_8 = NULL ;
V_86 -> V_191 . V_192 = 0 ;
F_67 ( V_86 ) ;
}
if ( V_8 -> V_114 == V_86 ) {
F_39 ( L_134 , V_45 , V_8 , V_86 ) ;
V_8 -> V_114 = NULL ;
if ( V_8 -> V_183 ) {
V_8 -> V_238 = V_8 -> V_135 ;
V_8 -> V_183 = false ;
}
V_86 -> V_191 . V_192 = 0 ;
F_67 ( V_86 ) ;
}
F_75 ( & V_8 -> V_117 ) ;
}
void F_191 ( struct V_35 * V_86 )
{
struct V_7 * V_8 ;
F_3 ( V_86 == NULL ) ;
if ( ! V_86 -> V_8 ) {
F_39 ( L_135 , V_45 , V_86 ) ;
return;
}
V_8 = V_86 -> V_8 ;
F_73 ( & V_8 -> V_117 ) ;
if ( V_8 -> V_111 == V_86 ) {
unsigned int V_193 = F_116 ( V_8 -> V_300 . V_193 ) ;
unsigned int V_194 = F_116 ( V_8 -> V_300 . V_194 ) ;
unsigned int V_178 = F_116 ( V_8 -> V_300 . V_178 ) ;
F_39 ( L_136 , V_45 , V_8 , V_86 ) ;
V_8 -> V_240 = V_8 -> V_240 -
sizeof( struct V_199 ) -
V_193 -
V_194 -
V_178 -
sizeof( struct V_333 ) ;
F_67 ( V_8 -> V_111 ) ;
V_8 -> V_111 = NULL ;
V_8 -> V_241 = V_243 ;
V_8 -> V_115 ++ ;
} else {
F_39 ( L_137 ,
V_45 , V_8 , V_8 -> V_111 , V_86 ) ;
}
F_75 ( & V_8 -> V_117 ) ;
}
void F_192 ( struct V_7 * V_8 )
{
F_39 ( L_138 , V_8 ) ;
F_73 ( & V_8 -> V_117 ) ;
F_187 ( V_8 ) ;
F_75 ( & V_8 -> V_117 ) ;
if ( F_11 ( V_8 , V_3 ) == 0 &&
F_11 ( V_8 , V_4 ) == 0 )
F_46 ( V_8 ) ;
}
static struct V_38 * F_193 ( enum V_334 type )
{
struct V_38 * V_138 ;
if ( F_37 ( ! F_194 ( type ) ) )
return NULL ;
V_138 = F_195 ( V_37 , V_72 ) ;
if ( V_138 )
V_138 -> type = type ;
F_81 ( & V_138 -> V_176 ) ;
return V_138 ;
}
static void F_196 ( struct V_38 * V_138 )
{
if ( ! V_138 )
return;
F_37 ( ! F_69 ( & V_138 -> V_176 ) ) ;
if ( V_138 -> type == V_169 ) {
F_197 ( V_138 -> V_168 ) ;
F_153 ( V_138 -> V_168 ) ;
}
F_198 ( V_37 , V_138 ) ;
}
void F_199 ( struct V_35 * V_86 , struct V_92 * * V_160 ,
T_1 V_94 , T_1 V_161 )
{
struct V_38 * V_138 ;
F_3 ( ! V_160 ) ;
F_3 ( ! V_94 ) ;
V_138 = F_193 ( V_159 ) ;
F_3 ( ! V_138 ) ;
V_138 -> V_160 = V_160 ;
V_138 -> V_94 = V_94 ;
V_138 -> V_161 = V_161 & ~ V_163 ;
F_189 ( & V_138 -> V_176 , & V_86 -> V_138 ) ;
V_86 -> V_174 += V_94 ;
}
void F_200 ( struct V_35 * V_86 ,
struct V_167 * V_168 )
{
struct V_38 * V_138 ;
F_3 ( ! V_168 ) ;
F_3 ( ! V_168 -> V_94 ) ;
V_138 = F_193 ( V_169 ) ;
F_3 ( ! V_138 ) ;
V_138 -> V_168 = V_168 ;
F_189 ( & V_138 -> V_176 , & V_86 -> V_138 ) ;
V_86 -> V_174 += V_168 -> V_94 ;
}
void F_201 ( struct V_35 * V_86 , struct V_144 * V_144 ,
T_1 V_94 )
{
struct V_38 * V_138 ;
F_3 ( ! V_144 ) ;
V_138 = F_193 ( V_145 ) ;
F_3 ( ! V_138 ) ;
V_138 -> V_144 = V_144 ;
V_138 -> V_147 = V_94 ;
F_189 ( & V_138 -> V_176 , & V_86 -> V_138 ) ;
V_86 -> V_174 += V_94 ;
}
struct V_35 * F_202 ( int type , int V_193 , T_6 V_9 ,
bool V_335 )
{
struct V_35 * V_179 ;
V_179 = F_195 ( V_34 , V_9 ) ;
if ( V_179 == NULL )
goto V_233;
V_179 -> V_191 . type = F_203 ( type ) ;
V_179 -> V_191 . V_336 = F_203 ( V_337 ) ;
V_179 -> V_191 . V_193 = F_120 ( V_193 ) ;
F_81 ( & V_179 -> V_106 ) ;
F_204 ( & V_179 -> V_338 ) ;
F_81 ( & V_179 -> V_138 ) ;
if ( V_193 ) {
V_179 -> V_195 . V_141 = F_205 ( V_193 , V_9 ) ;
if ( V_179 -> V_195 . V_141 == NULL ) {
F_39 ( L_139 ,
V_193 ) ;
goto V_339;
}
} else {
V_179 -> V_195 . V_141 = NULL ;
}
V_179 -> V_340 = V_179 -> V_195 . V_140 = V_193 ;
F_39 ( L_140 , V_179 , V_193 ) ;
return V_179 ;
V_339:
F_67 ( V_179 ) ;
V_233:
if ( ! V_335 ) {
F_31 ( L_141 , type ,
V_193 ) ;
F_37 ( 1 ) ;
} else {
F_39 ( L_141 , type ,
V_193 ) ;
}
return NULL ;
}
static int F_206 ( struct V_7 * V_8 , struct V_35 * V_86 )
{
int type = F_117 ( V_86 -> V_191 . type ) ;
int V_194 = F_116 ( V_86 -> V_191 . V_194 ) ;
F_39 ( L_142 , V_86 , type ,
F_171 ( type ) , V_194 ) ;
F_3 ( ! V_194 ) ;
F_3 ( V_86 -> V_197 ) ;
V_86 -> V_197 = F_207 ( V_194 , V_72 ) ;
if ( ! V_86 -> V_197 )
return - V_36 ;
return 0 ;
}
static int F_169 ( struct V_7 * V_8 , int * V_306 )
{
struct V_199 * V_191 = & V_8 -> V_300 ;
int V_194 = F_116 ( V_191 -> V_194 ) ;
struct V_35 * V_86 ;
int V_68 = 0 ;
F_3 ( V_8 -> V_111 != NULL ) ;
F_3 ( ! V_8 -> V_75 -> V_341 ) ;
F_75 ( & V_8 -> V_117 ) ;
V_86 = V_8 -> V_75 -> V_341 ( V_8 , V_191 , V_306 ) ;
F_73 ( & V_8 -> V_117 ) ;
if ( V_8 -> V_56 != V_289 ) {
if ( V_86 )
F_67 ( V_86 ) ;
return - V_91 ;
}
if ( V_86 ) {
F_3 ( * V_306 ) ;
V_8 -> V_111 = V_86 ;
V_8 -> V_111 -> V_8 = V_8 -> V_75 -> V_317 ( V_8 ) ;
F_3 ( V_8 -> V_111 -> V_8 == NULL ) ;
} else {
if ( * V_306 )
return 0 ;
V_8 -> V_80 = L_143 ;
return - V_36 ;
}
memcpy ( & V_8 -> V_111 -> V_191 , & V_8 -> V_300 , sizeof( V_8 -> V_300 ) ) ;
if ( V_194 && ! V_8 -> V_111 -> V_197 ) {
V_68 = F_206 ( V_8 , V_8 -> V_111 ) ;
if ( V_68 < 0 ) {
F_67 ( V_8 -> V_111 ) ;
V_8 -> V_111 = NULL ;
}
}
return V_68 ;
}
void F_208 ( struct V_35 * V_179 )
{
F_39 ( L_144 , V_179 ) ;
F_209 ( V_179 -> V_195 . V_141 ) ;
F_198 ( V_34 , V_179 ) ;
}
void F_210 ( struct V_338 * V_338 )
{
struct V_35 * V_179 = F_180 ( V_338 , struct V_35 , V_338 ) ;
F_211 ( V_138 ) ;
struct V_106 * V_176 ;
struct V_106 * V_342 ;
F_39 ( L_145 , V_179 ) ;
F_37 ( ! F_69 ( & V_179 -> V_106 ) ) ;
if ( V_179 -> V_197 ) {
F_212 ( V_179 -> V_197 ) ;
V_179 -> V_197 = NULL ;
}
F_182 ( & V_179 -> V_138 , & V_138 ) ;
F_213 (links, next, &data) {
struct V_38 * V_138 ;
V_138 = F_214 ( V_176 , struct V_38 , V_176 ) ;
F_66 ( V_176 ) ;
F_196 ( V_138 ) ;
}
V_179 -> V_174 = 0 ;
if ( V_179 -> V_343 )
F_215 ( V_179 -> V_343 , V_179 ) ;
else
F_208 ( V_179 ) ;
}
void F_216 ( struct V_35 * V_86 )
{
F_217 ( L_146 , V_86 ,
V_86 -> V_340 , V_86 -> V_174 ) ;
F_218 ( V_344 , L_147 ,
V_345 , 16 , 1 ,
& V_86 -> V_191 , sizeof( V_86 -> V_191 ) , true ) ;
F_218 ( V_344 , L_148 ,
V_345 , 16 , 1 ,
V_86 -> V_195 . V_141 , V_86 -> V_195 . V_140 , true ) ;
if ( V_86 -> V_197 )
F_218 ( V_344 , L_149 ,
V_345 , 16 , 1 ,
V_86 -> V_197 -> V_198 . V_141 ,
V_86 -> V_197 -> V_198 . V_140 , true ) ;
F_218 ( V_344 , L_150 ,
V_345 , 16 , 1 ,
& V_86 -> V_181 , sizeof( V_86 -> V_181 ) , true ) ;
}
