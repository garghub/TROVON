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
F_3 ( ! V_144 -> V_146 ) ;
V_143 -> V_147 = F_90 ( V_94 , V_138 -> V_148 ) ;
V_143 -> V_144 = V_144 ;
V_143 -> V_149 = 0 ;
V_143 -> V_150 = 0 ;
V_143 -> V_151 = V_94 <= V_144 -> V_152 [ 0 ] . V_153 ;
}
static struct V_92 * F_91 ( struct V_142 * V_143 ,
T_1 * V_93 ,
T_1 * V_94 )
{
struct V_38 * V_138 = V_143 -> V_138 ;
struct V_144 * V_144 ;
struct V_154 * V_154 ;
unsigned int V_139 ;
F_3 ( V_138 -> type != V_145 ) ;
V_144 = V_143 -> V_144 ;
F_3 ( ! V_144 ) ;
V_139 = V_143 -> V_149 ;
F_3 ( V_139 >= ( unsigned int ) V_144 -> V_146 ) ;
V_154 = & V_144 -> V_152 [ V_139 ] ;
F_3 ( V_143 -> V_150 >= V_154 -> V_153 ) ;
* V_93 = ( T_1 ) ( V_154 -> V_155 + V_143 -> V_150 ) ;
F_3 ( * V_93 >= V_96 ) ;
if ( V_143 -> V_151 )
* V_94 = V_143 -> V_147 ;
else
* V_94 = ( T_1 ) ( V_154 -> V_153 - V_143 -> V_150 ) ;
F_3 ( * V_94 > V_143 -> V_147 ) ;
F_3 ( * V_93 + * V_94 > V_96 ) ;
return V_154 -> V_156 ;
}
static bool F_92 ( struct V_142 * V_143 ,
T_1 V_157 )
{
struct V_144 * V_144 ;
struct V_154 * V_154 ;
unsigned int V_139 ;
F_3 ( V_143 -> V_138 -> type != V_145 ) ;
V_144 = V_143 -> V_144 ;
F_3 ( ! V_144 ) ;
V_139 = V_143 -> V_149 ;
F_3 ( V_139 >= ( unsigned int ) V_144 -> V_146 ) ;
V_154 = & V_144 -> V_152 [ V_139 ] ;
F_3 ( V_143 -> V_147 < V_157 ) ;
V_143 -> V_147 -= V_157 ;
V_143 -> V_150 += V_157 ;
if ( V_143 -> V_150 < V_154 -> V_153 )
return false ;
F_3 ( V_143 -> V_150 != V_154 -> V_153 ) ;
if ( ++ V_139 == ( unsigned int ) V_144 -> V_146 ) {
V_144 = V_144 -> V_158 ;
V_139 = 0 ;
}
V_143 -> V_144 = V_144 ;
V_143 -> V_149 = V_139 ;
V_143 -> V_150 = 0 ;
if ( ! V_143 -> V_151 ) {
F_3 ( ! V_143 -> V_147 ) ;
F_3 ( ! V_144 ) ;
if ( V_143 -> V_147 <= V_144 -> V_152 [ V_139 ] . V_153 )
V_143 -> V_151 = true ;
}
return true ;
}
static void F_93 ( struct V_142 * V_143 ,
T_1 V_94 )
{
struct V_38 * V_138 = V_143 -> V_138 ;
int V_159 ;
F_3 ( V_138 -> type != V_160 ) ;
F_3 ( ! V_138 -> V_161 ) ;
F_3 ( ! V_138 -> V_94 ) ;
V_143 -> V_147 = F_90 ( V_94 , V_138 -> V_94 ) ;
V_159 = F_94 ( V_138 -> V_162 , ( V_163 ) V_138 -> V_94 ) ;
V_143 -> V_93 = V_138 -> V_162 & ~ V_164 ;
V_143 -> V_165 = 0 ;
F_3 ( V_159 > ( int ) V_166 ) ;
V_143 -> V_159 = ( unsigned short ) V_159 ;
F_3 ( V_94 > V_167 - V_143 -> V_93 ) ;
V_143 -> V_151 = ( T_1 ) V_143 -> V_93 + V_94 <= V_96 ;
}
static struct V_92 *
F_95 ( struct V_142 * V_143 ,
T_1 * V_93 , T_1 * V_94 )
{
struct V_38 * V_138 = V_143 -> V_138 ;
F_3 ( V_138 -> type != V_160 ) ;
F_3 ( V_143 -> V_165 >= V_143 -> V_159 ) ;
F_3 ( V_143 -> V_93 >= V_96 ) ;
* V_93 = V_143 -> V_93 ;
if ( V_143 -> V_151 )
* V_94 = V_143 -> V_147 ;
else
* V_94 = V_96 - * V_93 ;
return V_138 -> V_161 [ V_143 -> V_165 ] ;
}
static bool F_96 ( struct V_142 * V_143 ,
T_1 V_157 )
{
F_3 ( V_143 -> V_138 -> type != V_160 ) ;
F_3 ( V_143 -> V_93 + V_157 > V_96 ) ;
V_143 -> V_147 -= V_157 ;
V_143 -> V_93 = ( V_143 -> V_93 + V_157 ) & ~ V_164 ;
if ( ! V_157 || V_143 -> V_93 )
return false ;
F_3 ( V_143 -> V_165 >= V_143 -> V_159 ) ;
V_143 -> V_165 ++ ;
V_143 -> V_151 = V_143 -> V_147 <= V_96 ;
return true ;
}
static void
F_97 ( struct V_142 * V_143 ,
T_1 V_94 )
{
struct V_38 * V_138 = V_143 -> V_138 ;
struct V_168 * V_169 ;
struct V_92 * V_92 ;
F_3 ( V_138 -> type != V_170 ) ;
V_169 = V_138 -> V_169 ;
F_3 ( ! V_169 ) ;
if ( ! V_94 )
return;
F_3 ( F_69 ( & V_169 -> V_108 ) ) ;
V_92 = F_70 ( & V_169 -> V_108 , struct V_92 , V_171 ) ;
V_143 -> V_147 = F_90 ( V_94 , V_169 -> V_94 ) ;
V_143 -> V_92 = V_92 ;
V_143 -> V_101 = 0 ;
V_143 -> V_151 = V_143 -> V_147 <= V_96 ;
}
static struct V_92 *
F_98 ( struct V_142 * V_143 ,
T_1 * V_93 , T_1 * V_94 )
{
struct V_38 * V_138 = V_143 -> V_138 ;
struct V_168 * V_169 ;
F_3 ( V_138 -> type != V_170 ) ;
V_169 = V_138 -> V_169 ;
F_3 ( ! V_169 ) ;
F_3 ( ! V_143 -> V_92 ) ;
F_3 ( V_143 -> V_101 + V_143 -> V_147 != V_169 -> V_94 ) ;
* V_93 = V_143 -> V_101 & ~ V_164 ;
if ( V_143 -> V_151 )
* V_94 = V_143 -> V_147 ;
else
* V_94 = V_96 - * V_93 ;
return V_143 -> V_92 ;
}
static bool F_99 ( struct V_142 * V_143 ,
T_1 V_157 )
{
struct V_38 * V_138 = V_143 -> V_138 ;
struct V_168 * V_169 ;
F_3 ( V_138 -> type != V_170 ) ;
V_169 = V_138 -> V_169 ;
F_3 ( ! V_169 ) ;
F_3 ( V_143 -> V_101 + V_143 -> V_147 != V_169 -> V_94 ) ;
F_3 ( ( V_143 -> V_101 & ~ V_164 ) + V_157 > V_96 ) ;
V_143 -> V_147 -= V_157 ;
V_143 -> V_101 += V_157 ;
if ( ! V_157 || V_143 -> V_101 & ~ V_164 )
return false ;
F_3 ( F_100 ( & V_143 -> V_92 -> V_171 , & V_169 -> V_108 ) ) ;
V_143 -> V_92 = F_101 ( V_143 -> V_92 , V_171 ) ;
V_143 -> V_151 = V_143 -> V_147 <= V_96 ;
return true ;
}
static void F_102 ( struct V_142 * V_143 )
{
T_1 V_94 = V_143 -> V_172 ;
switch ( V_143 -> V_138 -> type ) {
case V_170 :
F_97 ( V_143 , V_94 ) ;
break;
case V_160 :
F_93 ( V_143 , V_94 ) ;
break;
#ifdef F_103
case V_145 :
F_89 ( V_143 , V_94 ) ;
break;
#endif
case V_173 :
default:
break;
}
V_143 -> V_174 = true ;
}
static void F_104 ( struct V_35 * V_86 , T_1 V_94 )
{
struct V_142 * V_143 = & V_86 -> V_143 ;
struct V_38 * V_138 ;
F_3 ( ! V_94 ) ;
F_3 ( V_94 > V_86 -> V_175 ) ;
F_3 ( F_69 ( & V_86 -> V_138 ) ) ;
V_143 -> V_176 = & V_86 -> V_138 ;
V_143 -> V_172 = V_94 ;
V_138 = F_70 ( & V_86 -> V_138 , struct V_38 , V_177 ) ;
V_143 -> V_138 = V_138 ;
F_102 ( V_143 ) ;
}
static struct V_92 * F_105 ( struct V_142 * V_143 ,
T_1 * V_93 , T_1 * V_94 ,
bool * V_151 )
{
struct V_92 * V_92 ;
switch ( V_143 -> V_138 -> type ) {
case V_170 :
V_92 = F_98 ( V_143 , V_93 , V_94 ) ;
break;
case V_160 :
V_92 = F_95 ( V_143 , V_93 , V_94 ) ;
break;
#ifdef F_103
case V_145 :
V_92 = F_91 ( V_143 , V_93 , V_94 ) ;
break;
#endif
case V_173 :
default:
V_92 = NULL ;
break;
}
F_3 ( ! V_92 ) ;
F_3 ( * V_93 + * V_94 > V_96 ) ;
F_3 ( ! * V_94 ) ;
if ( V_151 )
* V_151 = V_143 -> V_151 ;
return V_92 ;
}
static bool F_106 ( struct V_142 * V_143 ,
T_1 V_157 )
{
bool V_178 ;
F_3 ( V_157 > V_143 -> V_147 ) ;
switch ( V_143 -> V_138 -> type ) {
case V_170 :
V_178 = F_99 ( V_143 , V_157 ) ;
break;
case V_160 :
V_178 = F_96 ( V_143 , V_157 ) ;
break;
#ifdef F_103
case V_145 :
V_178 = F_92 ( V_143 , V_157 ) ;
break;
#endif
case V_173 :
default:
F_107 () ;
break;
}
V_143 -> V_172 -= V_157 ;
if ( ! V_143 -> V_147 && V_143 -> V_172 ) {
F_37 ( ! V_143 -> V_151 ) ;
F_3 ( F_100 ( & V_143 -> V_138 -> V_177 , V_143 -> V_176 ) ) ;
V_143 -> V_138 = F_101 ( V_143 -> V_138 , V_177 ) ;
F_102 ( V_143 ) ;
V_178 = true ;
}
V_143 -> V_174 = V_178 ;
return V_178 ;
}
static void F_108 ( struct V_35 * V_86 , T_4 V_179 )
{
F_3 ( ! V_86 ) ;
F_3 ( ! V_179 ) ;
F_104 ( V_86 , ( T_1 ) V_179 ) ;
}
static void F_109 ( struct V_7 * V_8 )
{
struct V_35 * V_180 = V_8 -> V_114 ;
int V_181 = V_8 -> V_134 ;
V_180 -> V_182 . V_9 |= V_183 ;
F_39 ( L_26 , V_8 ) ;
V_8 -> V_184 = true ;
V_8 -> V_137 [ V_181 ] . V_141 = & V_180 -> V_182 ;
V_8 -> V_137 [ V_181 ] . V_140 = sizeof( V_180 -> V_182 ) ;
V_8 -> V_135 += sizeof( V_180 -> V_182 ) ;
V_8 -> V_134 ++ ;
V_8 -> V_185 = V_180 -> V_186 ;
V_8 -> V_187 = true ;
}
static void F_110 ( struct V_7 * V_8 )
{
struct V_35 * V_180 ;
T_4 V_188 ;
F_86 ( V_8 ) ;
V_8 -> V_184 = true ;
V_8 -> V_187 = false ;
if ( V_8 -> V_115 > V_8 -> V_116 ) {
V_8 -> V_116 = V_8 -> V_115 ;
F_87 ( V_8 , sizeof ( V_189 ) , & V_189 ) ;
V_8 -> V_190 = F_77 ( V_8 -> V_116 ) ;
F_87 ( V_8 , sizeof ( V_8 -> V_190 ) ,
& V_8 -> V_190 ) ;
}
F_3 ( F_69 ( & V_8 -> V_109 ) ) ;
V_180 = F_70 ( & V_8 -> V_109 , struct V_35 , V_106 ) ;
V_8 -> V_114 = V_180 ;
F_3 ( V_180 -> V_8 != V_8 ) ;
F_111 ( V_180 ) ;
F_112 ( & V_180 -> V_106 , & V_8 -> V_110 ) ;
if ( V_180 -> V_191 ) {
V_180 -> V_192 . V_193 = F_77 ( ++ V_8 -> V_113 ) ;
V_180 -> V_191 = false ;
}
F_37 ( V_180 -> V_175 != F_113 ( V_180 -> V_192 . V_179 ) ) ;
F_39 ( L_27 ,
V_180 , V_8 -> V_113 , F_114 ( V_180 -> V_192 . type ) ,
F_113 ( V_180 -> V_192 . V_194 ) , F_113 ( V_180 -> V_192 . V_195 ) ,
V_180 -> V_175 ) ;
F_3 ( F_113 ( V_180 -> V_192 . V_194 ) != V_180 -> V_196 . V_140 ) ;
F_87 ( V_8 , sizeof ( V_197 ) , & V_197 ) ;
F_87 ( V_8 , sizeof ( V_180 -> V_192 ) , & V_180 -> V_192 ) ;
F_87 ( V_8 , V_180 -> V_196 . V_140 , V_180 -> V_196 . V_141 ) ;
if ( V_180 -> V_198 )
F_87 ( V_8 , V_180 -> V_198 -> V_199 . V_140 ,
V_180 -> V_198 -> V_199 . V_141 ) ;
V_188 = F_115 ( 0 , & V_180 -> V_192 , F_116 ( struct V_200 , V_188 ) ) ;
V_8 -> V_114 -> V_192 . V_188 = F_117 ( V_188 ) ;
V_8 -> V_114 -> V_182 . V_9 = 0 ;
V_188 = F_115 ( 0 , V_180 -> V_196 . V_141 , V_180 -> V_196 . V_140 ) ;
V_8 -> V_114 -> V_182 . V_201 = F_117 ( V_188 ) ;
if ( V_180 -> V_198 ) {
V_188 = F_115 ( 0 , V_180 -> V_198 -> V_199 . V_141 ,
V_180 -> V_198 -> V_199 . V_140 ) ;
V_8 -> V_114 -> V_182 . V_202 = F_117 ( V_188 ) ;
} else
V_8 -> V_114 -> V_182 . V_202 = 0 ;
F_39 ( L_28 , V_45 ,
F_113 ( V_8 -> V_114 -> V_182 . V_201 ) ,
F_113 ( V_8 -> V_114 -> V_182 . V_202 ) ) ;
V_8 -> V_114 -> V_182 . V_203 = 0 ;
if ( V_180 -> V_175 ) {
F_108 ( V_8 -> V_114 , V_180 -> V_175 ) ;
V_8 -> V_185 = 1 ;
} else {
F_109 ( V_8 ) ;
}
F_5 ( V_8 , V_4 ) ;
}
static void F_118 ( struct V_7 * V_8 )
{
F_39 ( L_29 , V_8 ,
V_8 -> V_116 , V_8 -> V_115 ) ;
V_8 -> V_116 = V_8 -> V_115 ;
F_86 ( V_8 ) ;
F_87 ( V_8 , sizeof ( V_189 ) , & V_189 ) ;
V_8 -> V_190 = F_77 ( V_8 -> V_116 ) ;
F_87 ( V_8 , sizeof ( V_8 -> V_190 ) ,
& V_8 -> V_190 ) ;
V_8 -> V_185 = 1 ;
F_5 ( V_8 , V_4 ) ;
}
static void F_119 ( struct V_7 * V_8 )
{
F_39 ( L_30 , V_8 ,
V_8 -> V_116 , V_8 -> V_115 ) ;
V_8 -> V_116 = V_8 -> V_115 ;
F_86 ( V_8 ) ;
V_8 -> V_190 = F_77 ( V_8 -> V_116 ) ;
F_87 ( V_8 , sizeof ( V_8 -> V_190 ) ,
& V_8 -> V_190 ) ;
F_5 ( V_8 , V_4 ) ;
}
static void F_120 ( struct V_7 * V_8 )
{
F_39 ( L_31 , V_8 ) ;
F_86 ( V_8 ) ;
F_87 ( V_8 , sizeof ( V_204 ) , & V_204 ) ;
F_5 ( V_8 , V_4 ) ;
}
static struct V_205 * F_121 ( struct V_7 * V_8 ,
int * V_206 )
{
struct V_205 * V_207 ;
if ( ! V_8 -> V_75 -> V_208 ) {
V_8 -> V_209 . V_210 = V_211 ;
V_8 -> V_209 . V_212 = 0 ;
return NULL ;
}
F_75 ( & V_8 -> V_117 ) ;
V_207 = V_8 -> V_75 -> V_208 ( V_8 , V_206 , V_8 -> V_213 ) ;
F_73 ( & V_8 -> V_117 ) ;
if ( F_122 ( V_207 ) )
return V_207 ;
if ( V_8 -> V_56 != V_214 )
return F_123 ( - V_91 ) ;
V_8 -> V_215 = V_207 -> V_216 ;
V_8 -> V_217 = V_207 -> V_218 ;
return V_207 ;
}
static void F_124 ( struct V_7 * V_8 )
{
F_87 ( V_8 , strlen ( V_219 ) , V_219 ) ;
F_87 ( V_8 , sizeof ( V_8 -> V_30 -> V_31 ) ,
& V_8 -> V_30 -> V_31 ) ;
V_8 -> V_185 = 0 ;
F_5 ( V_8 , V_4 ) ;
}
static int F_125 ( struct V_7 * V_8 )
{
unsigned int V_133 = F_83 ( V_8 -> V_30 , 0 ) ;
int V_220 ;
int V_206 ;
struct V_205 * V_207 ;
switch ( V_8 -> V_125 . type ) {
case V_221 :
V_220 = V_222 ;
break;
case V_223 :
V_220 = V_224 ;
break;
case V_225 :
V_220 = V_226 ;
break;
default:
F_107 () ;
}
F_39 ( L_32 , V_8 ,
V_8 -> V_112 , V_133 , V_220 ) ;
V_8 -> V_209 . V_227 = F_77 ( V_8 -> V_30 -> V_228 ) ;
V_8 -> V_209 . V_229 = F_117 ( V_230 ) ;
V_8 -> V_209 . V_112 = F_117 ( V_8 -> V_112 ) ;
V_8 -> V_209 . V_133 = F_117 ( V_133 ) ;
V_8 -> V_209 . V_231 = F_117 ( V_220 ) ;
V_8 -> V_209 . V_9 = 0 ;
V_206 = V_211 ;
V_207 = F_121 ( V_8 , & V_206 ) ;
if ( F_122 ( V_207 ) )
return F_126 ( V_207 ) ;
V_8 -> V_209 . V_210 = F_117 ( V_206 ) ;
V_8 -> V_209 . V_212 = V_207 ?
F_117 ( V_207 -> V_232 ) : 0 ;
F_87 ( V_8 , sizeof ( V_8 -> V_209 ) ,
& V_8 -> V_209 ) ;
if ( V_207 && V_207 -> V_232 )
F_87 ( V_8 , V_207 -> V_232 ,
V_207 -> V_233 ) ;
V_8 -> V_185 = 0 ;
F_5 ( V_8 , V_4 ) ;
return 0 ;
}
static int F_127 ( struct V_7 * V_8 )
{
int V_68 ;
F_39 ( L_33 , V_8 , V_8 -> V_135 ) ;
while ( V_8 -> V_135 > 0 ) {
V_68 = F_60 ( V_8 -> V_49 , V_8 -> V_136 ,
V_8 -> V_134 , V_8 -> V_135 ,
V_8 -> V_185 ) ;
if ( V_68 <= 0 )
goto V_234;
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
V_8 -> V_184 = false ;
V_68 = 1 ;
V_234:
F_39 ( L_34 , V_8 ,
V_8 -> V_135 , V_8 -> V_134 , V_68 ) ;
return V_68 ;
}
static T_4 F_128 ( T_4 V_188 , struct V_92 * V_92 ,
unsigned int V_93 ,
unsigned int V_94 )
{
char * V_95 ;
V_95 = F_59 ( V_92 ) ;
F_3 ( V_95 == NULL ) ;
V_188 = F_115 ( V_188 , V_95 + V_93 , V_94 ) ;
F_25 ( V_92 ) ;
return V_188 ;
}
static int F_129 ( struct V_7 * V_8 )
{
struct V_35 * V_86 = V_8 -> V_114 ;
struct V_142 * V_143 = & V_86 -> V_143 ;
bool V_235 = ! V_8 -> V_30 -> V_236 ;
T_4 V_188 ;
F_39 ( L_35 , V_45 , V_8 , V_86 ) ;
if ( F_69 ( & V_86 -> V_138 ) )
return - V_237 ;
V_188 = V_235 ? F_113 ( V_86 -> V_182 . V_203 ) : 0 ;
while ( V_143 -> V_147 ) {
struct V_92 * V_92 ;
T_1 V_93 ;
T_1 V_94 ;
bool V_151 ;
bool V_174 ;
int V_68 ;
V_92 = F_105 ( & V_86 -> V_143 , & V_93 , & V_94 ,
& V_151 ) ;
V_68 = F_62 ( V_8 -> V_49 , V_92 , V_93 ,
V_94 , V_151 ) ;
if ( V_68 <= 0 ) {
if ( V_235 )
V_86 -> V_182 . V_203 = F_117 ( V_188 ) ;
return V_68 ;
}
if ( V_235 && V_143 -> V_174 )
V_188 = F_128 ( V_188 , V_92 , V_93 , V_94 ) ;
V_174 = F_106 ( & V_86 -> V_143 , ( T_1 ) V_68 ) ;
}
F_39 ( L_36 , V_45 , V_8 , V_86 ) ;
if ( V_235 )
V_86 -> V_182 . V_203 = F_117 ( V_188 ) ;
else
V_86 -> V_182 . V_9 |= V_238 ;
F_86 ( V_8 ) ;
F_109 ( V_8 ) ;
return 1 ;
}
static int F_130 ( struct V_7 * V_8 )
{
int V_68 ;
while ( V_8 -> V_239 > 0 ) {
T_1 V_102 = F_90 ( V_8 -> V_239 , ( int ) V_240 ) ;
V_68 = F_62 ( V_8 -> V_49 , V_40 , 0 , V_102 , true ) ;
if ( V_68 <= 0 )
goto V_234;
V_8 -> V_239 -= V_68 ;
}
V_68 = 1 ;
V_234:
return V_68 ;
}
static void F_131 ( struct V_7 * V_8 )
{
F_39 ( L_37 , V_8 ) ;
V_8 -> V_241 = 0 ;
}
static void F_132 ( struct V_7 * V_8 )
{
F_39 ( L_38 , V_8 ) ;
V_8 -> V_241 = 0 ;
}
static void F_133 ( struct V_7 * V_8 )
{
F_39 ( L_39 , V_8 ) ;
V_8 -> V_241 = 0 ;
}
static void F_134 ( struct V_7 * V_8 )
{
F_39 ( L_40 , V_8 ) ;
V_8 -> V_241 = 0 ;
V_8 -> V_242 = V_243 ;
}
static void F_135 ( struct V_7 * V_8 )
{
F_39 ( L_41 , V_8 ) ;
V_8 -> V_241 = 0 ;
V_8 -> V_242 = V_244 ;
}
static int F_136 ( struct V_7 * V_8 )
{
F_39 ( L_42 , V_8 ) ;
F_3 ( V_8 -> V_111 != NULL ) ;
V_8 -> V_241 = 0 ;
V_8 -> V_245 = V_8 -> V_246 = V_8 -> V_247 = 0 ;
return 0 ;
}
static int F_137 ( struct V_7 * V_8 ,
int V_248 , int V_102 , void * V_249 )
{
while ( V_8 -> V_241 < V_248 ) {
int V_250 = V_248 - V_8 -> V_241 ;
int V_251 = V_102 - V_250 ;
int V_68 = F_56 ( V_8 -> V_49 , V_249 + V_251 , V_250 ) ;
if ( V_68 <= 0 )
return V_68 ;
V_8 -> V_241 += V_68 ;
}
return 1 ;
}
static int F_138 ( struct V_7 * V_8 )
{
int V_102 ;
int V_248 ;
int V_68 ;
F_39 ( L_43 , V_8 , V_8 -> V_241 ) ;
V_102 = strlen ( V_219 ) ;
V_248 = V_102 ;
V_68 = F_137 ( V_8 , V_248 , V_102 , V_8 -> V_252 ) ;
if ( V_68 <= 0 )
goto V_234;
V_102 = sizeof ( V_8 -> V_253 ) ;
V_248 += V_102 ;
V_68 = F_137 ( V_8 , V_248 , V_102 , & V_8 -> V_253 ) ;
if ( V_68 <= 0 )
goto V_234;
V_102 = sizeof ( V_8 -> V_254 ) ;
V_248 += V_102 ;
V_68 = F_137 ( V_8 , V_248 , V_102 , & V_8 -> V_254 ) ;
if ( V_68 <= 0 )
goto V_234;
V_234:
return V_68 ;
}
static int F_139 ( struct V_7 * V_8 )
{
int V_102 ;
int V_248 ;
int V_68 ;
F_39 ( L_44 , V_8 , V_8 -> V_241 ) ;
V_102 = sizeof ( V_8 -> V_255 ) ;
V_248 = V_102 ;
V_68 = F_137 ( V_8 , V_248 , V_102 , & V_8 -> V_255 ) ;
if ( V_68 <= 0 )
goto V_234;
V_102 = F_113 ( V_8 -> V_255 . V_212 ) ;
V_248 += V_102 ;
V_68 = F_137 ( V_8 , V_248 , V_102 , V_8 -> V_215 ) ;
if ( V_68 <= 0 )
goto V_234;
F_39 ( L_45 ,
V_8 , ( int ) V_8 -> V_255 . V_256 ,
F_113 ( V_8 -> V_255 . V_112 ) ,
F_113 ( V_8 -> V_255 . V_133 ) ) ;
V_234:
return V_68 ;
}
static int F_140 ( struct V_7 * V_8 )
{
if ( memcmp ( V_8 -> V_252 , V_219 , strlen ( V_219 ) ) ) {
F_31 ( L_46 ,
F_13 ( & V_8 -> V_66 . V_67 ) ) ;
V_8 -> V_80 = L_47 ;
return - 1 ;
}
return 0 ;
}
static bool F_141 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_21 ) {
case V_22 :
return ( (struct V_14 * ) V_11 ) -> V_24 . V_257 == 0 ;
case V_26 :
return
( (struct V_16 * ) V_11 ) -> V_27 . V_258 [ 0 ] == 0 &&
( (struct V_16 * ) V_11 ) -> V_27 . V_258 [ 1 ] == 0 &&
( (struct V_16 * ) V_11 ) -> V_27 . V_258 [ 2 ] == 0 &&
( (struct V_16 * ) V_11 ) -> V_27 . V_258 [ 3 ] == 0 ;
}
return false ;
}
static int F_142 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_21 ) {
case V_22 :
return F_15 ( ( (struct V_14 * ) V_11 ) -> V_25 ) ;
case V_26 :
return F_15 ( ( (struct V_16 * ) V_11 ) -> V_28 ) ;
}
return 0 ;
}
static void F_143 ( struct V_10 * V_11 , int V_259 )
{
switch ( V_11 -> V_21 ) {
case V_22 :
( (struct V_14 * ) V_11 ) -> V_25 = F_144 ( V_259 ) ;
break;
case V_26 :
( (struct V_16 * ) V_11 ) -> V_28 = F_144 ( V_259 ) ;
break;
}
}
static int F_145 ( const char * V_260 , T_1 V_82 , struct V_10 * V_11 ,
char V_261 , const char * * V_262 )
{
struct V_14 * V_15 = (struct V_14 * ) V_11 ;
struct V_16 * V_17 = (struct V_16 * ) V_11 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
if ( F_146 ( V_260 , V_82 , ( V_263 * ) & V_15 -> V_24 . V_257 , V_261 , V_262 ) ) {
V_11 -> V_21 = V_22 ;
return 0 ;
}
if ( F_147 ( V_260 , V_82 , ( V_263 * ) & V_17 -> V_27 . V_264 , V_261 , V_262 ) ) {
V_11 -> V_21 = V_26 ;
return 0 ;
}
return - V_237 ;
}
static int F_148 ( const char * V_265 , T_1 V_266 ,
struct V_10 * V_11 , char V_261 , const char * * V_262 )
{
const char * V_248 , * V_267 ;
char * V_268 , * V_269 = NULL ;
int V_270 , V_68 ;
V_267 = memchr ( V_265 , V_261 , V_266 ) ;
V_268 = memchr ( V_265 , ':' , V_266 ) ;
if ( V_267 && V_268 )
V_248 = V_267 < V_268 ? V_267 : V_268 ;
else if ( ! V_267 && V_268 )
V_248 = V_268 ;
else {
V_248 = V_267 ;
if ( ! V_248 )
V_248 = V_265 + V_266 ;
}
if ( V_248 <= V_265 )
return - V_237 ;
V_270 = F_149 ( NULL , V_265 , V_248 - V_265 , NULL , & V_269 , NULL ) ;
if ( V_270 > 0 )
V_68 = F_145 ( V_269 , V_270 , V_11 , - 1 , NULL ) ;
else
V_68 = - V_271 ;
F_150 ( V_269 ) ;
* V_262 = V_248 ;
F_151 ( L_48 , ( int ) ( V_248 - V_265 ) , V_265 ,
V_68 , V_68 ? L_49 : F_13 ( V_11 ) ) ;
return V_68 ;
}
static inline int F_148 ( const char * V_265 , T_1 V_266 ,
struct V_10 * V_11 , char V_261 , const char * * V_262 )
{
return - V_237 ;
}
static int F_152 ( const char * V_265 , T_1 V_266 ,
struct V_10 * V_11 , char V_261 , const char * * V_262 )
{
int V_68 ;
V_68 = F_145 ( V_265 , V_266 , V_11 , V_261 , V_262 ) ;
if ( V_68 )
V_68 = F_148 ( V_265 , V_266 , V_11 , V_261 , V_262 ) ;
return V_68 ;
}
int F_153 ( const char * V_272 , const char * V_248 ,
struct V_123 * V_33 ,
int V_273 , int * V_274 )
{
int V_12 , V_68 = - V_237 ;
const char * V_259 = V_272 ;
F_39 ( L_50 , ( int ) ( V_248 - V_272 ) , V_272 ) ;
for ( V_12 = 0 ; V_12 < V_273 ; V_12 ++ ) {
const char * V_262 ;
struct V_10 * V_11 = & V_33 [ V_12 ] . V_67 ;
int V_275 ;
char V_261 = ',' ;
if ( * V_259 == '[' ) {
V_261 = ']' ;
V_259 ++ ;
}
V_68 = F_152 ( V_259 , V_248 - V_259 , V_11 , V_261 , & V_262 ) ;
if ( V_68 )
goto V_276;
V_68 = - V_237 ;
V_259 = V_262 ;
if ( V_261 == ']' ) {
if ( * V_259 != ']' ) {
F_39 ( L_51 ) ;
goto V_276;
}
V_259 ++ ;
}
if ( V_259 < V_248 && * V_259 == ':' ) {
V_275 = 0 ;
V_259 ++ ;
while ( V_259 < V_248 && * V_259 >= '0' && * V_259 <= '9' ) {
V_275 = ( V_275 * 10 ) + ( * V_259 - '0' ) ;
V_259 ++ ;
}
if ( V_275 > 65535 || V_275 == 0 )
goto V_276;
} else {
V_275 = V_277 ;
}
F_143 ( V_11 , V_275 ) ;
F_39 ( L_52 , F_13 ( V_11 ) ) ;
if ( V_259 == V_248 )
break;
if ( * V_259 != ',' )
goto V_276;
V_259 ++ ;
}
if ( V_259 != V_248 )
goto V_276;
if ( V_274 )
* V_274 = V_12 + 1 ;
return 0 ;
V_276:
F_31 ( L_53 , ( int ) ( V_248 - V_272 ) , V_272 ) ;
return V_68 ;
}
static int F_154 ( struct V_7 * V_8 )
{
F_39 ( L_54 , V_8 ) ;
if ( F_140 ( V_8 ) < 0 )
return - 1 ;
F_155 ( & V_8 -> V_253 ) ;
F_155 ( & V_8 -> V_254 ) ;
if ( memcmp ( & V_8 -> V_66 , & V_8 -> V_253 ,
sizeof( V_8 -> V_66 ) ) != 0 &&
! ( F_141 ( & V_8 -> V_253 . V_67 ) &&
V_8 -> V_253 . V_278 == V_8 -> V_66 . V_278 ) ) {
F_156 ( L_55 ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
( int ) F_113 ( V_8 -> V_66 . V_278 ) ,
F_13 ( & V_8 -> V_253 . V_67 ) ,
( int ) F_113 ( V_8 -> V_253 . V_278 ) ) ;
V_8 -> V_80 = L_56 ;
return - 1 ;
}
if ( F_141 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ) ) {
int V_275 = F_142 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ) ;
memcpy ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ,
& V_8 -> V_254 . V_67 ,
sizeof( V_8 -> V_254 . V_67 ) ) ;
F_143 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 , V_275 ) ;
F_16 ( V_8 -> V_30 ) ;
F_39 ( L_57 ,
F_13 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ) ) ;
}
return 0 ;
}
static int F_157 ( struct V_7 * V_8 )
{
V_163 V_279 = V_8 -> V_30 -> V_228 ;
V_163 V_280 = V_8 -> V_30 -> V_281 ;
V_163 V_282 = F_158 ( V_8 -> V_255 . V_227 ) ;
int V_68 ;
F_39 ( L_58 , V_8 , ( int ) V_8 -> V_242 ) ;
switch ( V_8 -> V_255 . V_256 ) {
case V_283 :
F_31 ( L_59
L_60 ,
F_159 ( V_8 -> V_125 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_279 , V_282 , V_282 & ~ V_279 ) ;
V_8 -> V_80 = L_61 ;
F_71 ( V_8 ) ;
return - 1 ;
case V_284 :
F_31 ( L_62
L_63 ,
F_159 ( V_8 -> V_125 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
F_113 ( V_8 -> V_209 . V_231 ) ,
F_113 ( V_8 -> V_255 . V_231 ) ) ;
V_8 -> V_80 = L_64 ;
F_71 ( V_8 ) ;
return - 1 ;
case V_285 :
V_8 -> V_213 ++ ;
F_39 ( L_65 , V_8 ,
V_8 -> V_213 ) ;
if ( V_8 -> V_213 == 2 ) {
V_8 -> V_80 = L_66 ;
return - 1 ;
}
F_86 ( V_8 ) ;
V_68 = F_125 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_132 ( V_8 ) ;
break;
case V_286 :
F_39 ( L_67 ,
F_113 ( V_8 -> V_255 . V_112 ) ) ;
F_31 ( L_68 ,
F_159 ( V_8 -> V_125 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ) ;
F_71 ( V_8 ) ;
F_86 ( V_8 ) ;
V_68 = F_125 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_132 ( V_8 ) ;
F_75 ( & V_8 -> V_117 ) ;
F_151 ( L_69 , F_159 ( V_8 -> V_125 ) ) ;
if ( V_8 -> V_75 -> V_287 )
V_8 -> V_75 -> V_287 ( V_8 ) ;
F_73 ( & V_8 -> V_117 ) ;
if ( V_8 -> V_56 != V_214 )
return - V_91 ;
break;
case V_288 :
F_39 ( L_70 ,
F_113 ( V_8 -> V_209 . V_112 ) ,
F_113 ( V_8 -> V_255 . V_112 ) ) ;
V_8 -> V_112 = F_113 ( V_8 -> V_255 . V_112 ) ;
F_86 ( V_8 ) ;
V_68 = F_125 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_132 ( V_8 ) ;
break;
case V_289 :
F_39 ( L_71 ,
V_8 -> V_119 ,
F_113 ( V_8 -> V_255 . V_133 ) ) ;
F_83 ( V_8 -> V_30 ,
F_113 ( V_8 -> V_255 . V_133 ) ) ;
F_86 ( V_8 ) ;
V_68 = F_125 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_132 ( V_8 ) ;
break;
case V_243 :
case V_244 :
if ( V_280 & ~ V_282 ) {
F_31 ( L_72
L_73 ,
F_159 ( V_8 -> V_125 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_280 , V_282 , V_280 & ~ V_282 ) ;
V_8 -> V_80 = L_61 ;
F_71 ( V_8 ) ;
return - 1 ;
}
F_37 ( V_8 -> V_56 != V_214 ) ;
V_8 -> V_56 = V_290 ;
V_8 -> V_213 = 0 ;
V_8 -> V_119 = F_113 ( V_8 -> V_255 . V_133 ) ;
V_8 -> V_112 ++ ;
V_8 -> V_291 = V_282 ;
F_39 ( L_74 ,
V_8 -> V_119 ,
F_113 ( V_8 -> V_255 . V_112 ) ,
V_8 -> V_112 ) ;
F_37 ( V_8 -> V_112 !=
F_113 ( V_8 -> V_255 . V_112 ) ) ;
if ( V_8 -> V_255 . V_9 & V_292 )
F_5 ( V_8 , V_2 ) ;
V_8 -> V_127 = 0 ;
if ( V_8 -> V_255 . V_256 == V_243 ) {
F_119 ( V_8 ) ;
F_134 ( V_8 ) ;
} else {
F_135 ( V_8 ) ;
}
break;
case V_293 :
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
static int F_160 ( struct V_7 * V_8 )
{
int V_102 = sizeof ( V_8 -> V_294 ) ;
int V_248 = V_102 ;
return F_137 ( V_8 , V_248 , V_102 , & V_8 -> V_294 ) ;
}
static void F_161 ( struct V_7 * V_8 )
{
struct V_35 * V_180 ;
V_163 V_295 = F_158 ( V_8 -> V_294 ) ;
V_163 V_193 ;
while ( ! F_69 ( & V_8 -> V_110 ) ) {
V_180 = F_70 ( & V_8 -> V_110 , struct V_35 ,
V_106 ) ;
V_193 = F_158 ( V_180 -> V_192 . V_193 ) ;
if ( V_193 > V_295 )
break;
F_39 ( L_79 , V_193 ,
F_114 ( V_180 -> V_192 . type ) , V_180 ) ;
V_180 -> V_296 = V_297 ;
F_65 ( V_180 ) ;
}
F_135 ( V_8 ) ;
}
static int F_162 ( struct V_7 * V_8 ,
struct V_83 * V_298 ,
unsigned int V_299 , T_4 * V_188 )
{
int V_68 , V_250 ;
F_3 ( ! V_298 ) ;
while ( V_298 -> V_140 < V_299 ) {
F_3 ( V_298 -> V_141 == NULL ) ;
V_250 = V_299 - V_298 -> V_140 ;
V_68 = F_56 ( V_8 -> V_49 , ( char * ) V_298 -> V_141 +
V_298 -> V_140 , V_250 ) ;
if ( V_68 <= 0 )
return V_68 ;
V_298 -> V_140 += V_68 ;
}
if ( V_298 -> V_140 == V_299 )
* V_188 = F_115 ( 0 , V_298 -> V_141 , V_298 -> V_140 ) ;
return 1 ;
}
static int F_163 ( struct V_7 * V_8 )
{
struct V_35 * V_86 = V_8 -> V_111 ;
struct V_142 * V_143 = & V_86 -> V_143 ;
const bool V_235 = ! V_8 -> V_30 -> V_236 ;
struct V_92 * V_92 ;
T_1 V_93 ;
T_1 V_94 ;
T_4 V_188 = 0 ;
int V_68 ;
F_3 ( ! V_86 ) ;
if ( F_69 ( & V_86 -> V_138 ) )
return - V_300 ;
if ( V_235 )
V_188 = V_8 -> V_247 ;
while ( V_143 -> V_147 ) {
V_92 = F_105 ( & V_86 -> V_143 , & V_93 , & V_94 ,
NULL ) ;
V_68 = F_58 ( V_8 -> V_49 , V_92 , V_93 , V_94 ) ;
if ( V_68 <= 0 ) {
if ( V_235 )
V_8 -> V_247 = V_188 ;
return V_68 ;
}
if ( V_235 )
V_188 = F_128 ( V_188 , V_92 , V_93 , V_68 ) ;
( void ) F_106 ( & V_86 -> V_143 , ( T_1 ) V_68 ) ;
}
if ( V_235 )
V_8 -> V_247 = V_188 ;
return 1 ;
}
static int F_164 ( struct V_7 * V_8 )
{
struct V_35 * V_180 = V_8 -> V_111 ;
int V_102 ;
int V_248 ;
int V_68 ;
unsigned int V_194 , V_195 , V_179 ;
bool V_235 = ! V_8 -> V_30 -> V_236 ;
V_163 V_193 ;
T_4 V_188 ;
F_39 ( L_80 , V_8 , V_180 ) ;
V_102 = sizeof ( V_8 -> V_301 ) ;
V_248 = V_102 ;
V_68 = F_137 ( V_8 , V_248 , V_102 , & V_8 -> V_301 ) ;
if ( V_68 <= 0 )
return V_68 ;
V_188 = F_115 ( 0 , & V_8 -> V_301 , F_116 ( struct V_200 , V_188 ) ) ;
if ( F_117 ( V_188 ) != V_8 -> V_301 . V_188 ) {
F_31 ( L_81
L_82 ,
V_188 , V_8 -> V_301 . V_188 ) ;
return - V_302 ;
}
V_194 = F_113 ( V_8 -> V_301 . V_194 ) ;
if ( V_194 > V_303 )
return - V_300 ;
V_195 = F_113 ( V_8 -> V_301 . V_195 ) ;
if ( V_195 > V_304 )
return - V_300 ;
V_179 = F_113 ( V_8 -> V_301 . V_179 ) ;
if ( V_179 > V_305 )
return - V_300 ;
V_193 = F_158 ( V_8 -> V_301 . V_193 ) ;
if ( ( V_306 ) V_193 - ( V_306 ) V_8 -> V_115 < 1 ) {
F_151 ( L_83 ,
F_159 ( V_8 -> V_125 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_193 , V_8 -> V_115 + 1 ) ;
V_8 -> V_241 = - V_194 - V_195 - V_179 -
sizeof( V_180 -> V_182 ) ;
V_8 -> V_242 = V_244 ;
return 0 ;
} else if ( ( V_306 ) V_193 - ( V_306 ) V_8 -> V_115 > 1 ) {
F_31 ( L_84 ,
V_193 , V_8 -> V_115 + 1 ) ;
V_8 -> V_80 = L_85 ;
return - V_302 ;
}
if ( ! V_8 -> V_111 ) {
int V_307 = 0 ;
F_39 ( L_86 , V_8 -> V_301 . type ,
V_194 , V_179 ) ;
V_68 = F_165 ( V_8 , & V_307 ) ;
if ( V_68 < 0 )
return V_68 ;
F_3 ( ! V_8 -> V_111 ^ V_307 ) ;
if ( V_8 -> V_111 && V_179 > V_8 -> V_111 -> V_175 ) {
F_156 ( L_87 ,
V_45 , V_179 , V_8 -> V_111 -> V_175 ) ;
F_67 ( V_8 -> V_111 ) ;
V_8 -> V_111 = NULL ;
V_307 = 1 ;
}
if ( V_307 ) {
F_39 ( L_88 ) ;
V_8 -> V_241 = - V_194 - V_195 - V_179 -
sizeof( V_180 -> V_182 ) ;
V_8 -> V_242 = V_244 ;
V_8 -> V_115 ++ ;
return 0 ;
}
F_3 ( ! V_8 -> V_111 ) ;
F_3 ( V_8 -> V_111 -> V_8 != V_8 ) ;
V_180 = V_8 -> V_111 ;
V_180 -> V_196 . V_140 = 0 ;
if ( V_180 -> V_198 )
V_180 -> V_198 -> V_199 . V_140 = 0 ;
if ( V_179 )
F_108 ( V_8 -> V_111 , V_179 ) ;
}
V_68 = F_162 ( V_8 , & V_180 -> V_196 , V_194 ,
& V_8 -> V_245 ) ;
if ( V_68 <= 0 )
return V_68 ;
if ( V_180 -> V_198 ) {
V_68 = F_162 ( V_8 , & V_180 -> V_198 -> V_199 ,
V_195 ,
& V_8 -> V_246 ) ;
if ( V_68 <= 0 )
return V_68 ;
}
if ( V_179 ) {
V_68 = F_163 ( V_8 ) ;
if ( V_68 <= 0 )
return V_68 ;
}
V_102 = sizeof ( V_180 -> V_182 ) ;
V_248 += V_102 ;
V_68 = F_137 ( V_8 , V_248 , V_102 , & V_180 -> V_182 ) ;
if ( V_68 <= 0 )
return V_68 ;
F_39 ( L_89 ,
V_180 , V_194 , V_180 -> V_182 . V_201 , V_195 ,
V_180 -> V_182 . V_202 , V_179 , V_180 -> V_182 . V_203 ) ;
if ( V_8 -> V_245 != F_113 ( V_180 -> V_182 . V_201 ) ) {
F_31 ( L_90 ,
V_180 , V_8 -> V_245 , V_180 -> V_182 . V_201 ) ;
return - V_302 ;
}
if ( V_8 -> V_246 != F_113 ( V_180 -> V_182 . V_202 ) ) {
F_31 ( L_91 ,
V_180 , V_8 -> V_246 , V_180 -> V_182 . V_202 ) ;
return - V_302 ;
}
if ( V_235 &&
( V_180 -> V_182 . V_9 & V_238 ) == 0 &&
V_8 -> V_247 != F_113 ( V_180 -> V_182 . V_203 ) ) {
F_31 ( L_92 , V_180 ,
V_8 -> V_247 , F_113 ( V_180 -> V_182 . V_203 ) ) ;
return - V_302 ;
}
return 1 ;
}
static void F_166 ( struct V_7 * V_8 )
{
struct V_35 * V_86 ;
F_3 ( V_8 -> V_111 -> V_8 != V_8 ) ;
V_8 -> V_111 -> V_8 = NULL ;
V_86 = V_8 -> V_111 ;
V_8 -> V_111 = NULL ;
V_8 -> V_75 -> V_107 ( V_8 ) ;
if ( V_8 -> V_125 . type == 0 )
V_8 -> V_125 = V_86 -> V_192 . V_308 ;
V_8 -> V_115 ++ ;
F_75 ( & V_8 -> V_117 ) ;
F_39 ( L_93 ,
V_86 , F_158 ( V_86 -> V_192 . V_193 ) ,
F_159 ( V_86 -> V_192 . V_308 ) ,
F_114 ( V_86 -> V_192 . type ) ,
F_167 ( F_114 ( V_86 -> V_192 . type ) ) ,
F_113 ( V_86 -> V_192 . V_194 ) ,
F_113 ( V_86 -> V_192 . V_179 ) ,
V_8 -> V_245 , V_8 -> V_246 , V_8 -> V_247 ) ;
V_8 -> V_75 -> V_309 ( V_8 , V_86 ) ;
F_73 ( & V_8 -> V_117 ) ;
}
static int F_168 ( struct V_7 * V_8 )
{
int V_68 = 1 ;
F_39 ( L_94 , V_8 , V_8 -> V_56 ) ;
V_98:
F_39 ( L_95 , V_8 -> V_135 ) ;
if ( V_8 -> V_56 == V_124 ) {
F_3 ( V_8 -> V_49 ) ;
V_8 -> V_56 = V_310 ;
F_86 ( V_8 ) ;
F_124 ( V_8 ) ;
F_131 ( V_8 ) ;
F_3 ( V_8 -> V_111 ) ;
V_8 -> V_242 = V_244 ;
F_39 ( L_96 ,
V_8 , V_8 -> V_56 ) ;
V_68 = F_51 ( V_8 ) ;
if ( V_68 < 0 ) {
V_8 -> V_80 = L_20 ;
goto V_234;
}
}
V_311:
if ( V_8 -> V_239 ) {
V_68 = F_130 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_234;
}
if ( V_8 -> V_134 ) {
V_68 = F_127 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_234;
}
if ( V_8 -> V_114 ) {
if ( V_8 -> V_187 ) {
F_67 ( V_8 -> V_114 ) ;
V_8 -> V_114 = NULL ;
goto V_312;
}
V_68 = F_129 ( V_8 ) ;
if ( V_68 == 1 )
goto V_311;
if ( V_68 == 0 )
goto V_234;
if ( V_68 < 0 ) {
F_39 ( L_97 ,
V_68 ) ;
goto V_234;
}
}
V_312:
if ( V_8 -> V_56 == V_290 ) {
if ( ! F_69 ( & V_8 -> V_109 ) ) {
F_110 ( V_8 ) ;
goto V_98;
}
if ( V_8 -> V_115 > V_8 -> V_116 ) {
F_118 ( V_8 ) ;
goto V_98;
}
if ( F_9 ( V_8 , V_3 ) ) {
F_120 ( V_8 ) ;
goto V_98;
}
}
F_2 ( V_8 , V_4 ) ;
F_39 ( L_98 ) ;
V_68 = 0 ;
V_234:
F_39 ( L_99 , V_8 , V_68 ) ;
return V_68 ;
}
static int F_169 ( struct V_7 * V_8 )
{
int V_68 = - 1 ;
V_98:
F_39 ( L_100 , V_8 , V_8 -> V_56 ) ;
if ( V_8 -> V_56 != V_310 &&
V_8 -> V_56 != V_214 &&
V_8 -> V_56 != V_290 )
return 0 ;
F_3 ( ! V_8 -> V_49 ) ;
F_39 ( L_101 , ( int ) V_8 -> V_242 ,
V_8 -> V_241 ) ;
if ( V_8 -> V_56 == V_310 ) {
F_39 ( L_102 ) ;
V_68 = F_138 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_234;
V_68 = F_154 ( V_8 ) ;
if ( V_68 < 0 )
goto V_234;
V_8 -> V_56 = V_214 ;
V_68 = F_125 ( V_8 ) ;
if ( V_68 < 0 )
goto V_234;
F_132 ( V_8 ) ;
goto V_234;
}
if ( V_8 -> V_56 == V_214 ) {
F_39 ( L_103 ) ;
V_68 = F_139 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_234;
V_68 = F_157 ( V_8 ) ;
if ( V_68 < 0 )
goto V_234;
goto V_98;
}
F_37 ( V_8 -> V_56 != V_290 ) ;
if ( V_8 -> V_241 < 0 ) {
static char V_81 [ V_313 ] ;
int V_307 = F_90 ( ( int ) sizeof ( V_81 ) , - V_8 -> V_241 ) ;
F_39 ( L_104 , V_307 , - V_8 -> V_241 ) ;
V_68 = F_56 ( V_8 -> V_49 , V_81 , V_307 ) ;
if ( V_68 <= 0 )
goto V_234;
V_8 -> V_241 += V_68 ;
if ( V_8 -> V_241 )
goto V_98;
}
if ( V_8 -> V_242 == V_244 ) {
V_68 = F_56 ( V_8 -> V_49 , & V_8 -> V_242 , 1 ) ;
if ( V_68 <= 0 )
goto V_234;
F_39 ( L_105 , ( int ) V_8 -> V_242 ) ;
switch ( V_8 -> V_242 ) {
case V_314 :
F_136 ( V_8 ) ;
break;
case V_315 :
F_133 ( V_8 ) ;
break;
case V_316 :
F_64 ( V_8 ) ;
V_8 -> V_56 = V_118 ;
goto V_234;
default:
goto V_317;
}
}
if ( V_8 -> V_242 == V_314 ) {
V_68 = F_164 ( V_8 ) ;
if ( V_68 <= 0 ) {
switch ( V_68 ) {
case - V_302 :
V_8 -> V_80 = L_106 ;
V_68 = - V_300 ;
break;
case - V_300 :
V_8 -> V_80 = L_107 ;
break;
}
goto V_234;
}
if ( V_8 -> V_242 == V_244 )
goto V_98;
F_166 ( V_8 ) ;
if ( V_8 -> V_56 == V_290 )
F_135 ( V_8 ) ;
goto V_98;
}
if ( V_8 -> V_242 == V_315 ||
V_8 -> V_242 == V_243 ) {
V_68 = F_160 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_234;
F_161 ( V_8 ) ;
goto V_98;
}
V_234:
F_39 ( L_108 , V_8 , V_68 ) ;
return V_68 ;
V_317:
F_31 ( L_109 , ( int ) V_8 -> V_242 ) ;
V_8 -> V_80 = L_110 ;
V_68 = - 1 ;
goto V_234;
}
static int F_170 ( struct V_7 * V_8 , unsigned long V_127 )
{
if ( ! V_8 -> V_75 -> V_318 ( V_8 ) ) {
F_39 ( L_111 , V_45 , V_8 ) ;
return - V_319 ;
}
if ( ! F_171 ( V_39 , & V_8 -> V_120 , V_127 ) ) {
F_39 ( L_112 , V_45 , V_8 ) ;
V_8 -> V_75 -> V_107 ( V_8 ) ;
return - V_320 ;
}
F_39 ( L_113 , V_45 , V_8 , V_127 ) ;
return 0 ;
}
static void F_46 ( struct V_7 * V_8 )
{
( void ) F_170 ( V_8 , 0 ) ;
}
static bool F_172 ( struct V_7 * V_8 )
{
if ( ! F_9 ( V_8 , V_5 ) )
return false ;
#define CASE ( T_5 ) \
case CON_STATE_ ## x: \
con->error_msg = "socket closed (con state " #x ")"; \
break;
switch ( V_8 -> V_56 ) {
CASE ( V_321 ) ;
CASE ( V_322 ) ;
CASE ( V_323 ) ;
CASE ( V_324 ) ;
CASE ( V_325 ) ;
CASE ( V_326 ) ;
default:
F_156 ( L_114 ,
V_45 , V_8 , V_8 -> V_56 ) ;
V_8 -> V_80 = L_115 ;
F_107 () ;
break;
}
#undef CASE
return true ;
}
static bool F_173 ( struct V_7 * V_8 )
{
int V_68 ;
if ( ! F_9 ( V_8 , V_6 ) )
return false ;
V_68 = F_170 ( V_8 , F_174 ( V_8 -> V_127 ) ) ;
if ( V_68 ) {
F_39 ( L_116 , V_45 ,
V_8 , V_8 -> V_127 ) ;
F_3 ( V_68 == - V_319 ) ;
F_5 ( V_8 , V_6 ) ;
}
return true ;
}
static void F_175 ( struct V_7 * V_8 )
{
if ( V_8 -> V_213 && V_8 -> V_75 -> V_327 ) {
F_39 ( L_117 ) ;
V_8 -> V_75 -> V_327 ( V_8 ) ;
}
if ( V_8 -> V_75 -> V_328 )
V_8 -> V_75 -> V_328 ( V_8 ) ;
}
static void V_130 ( struct V_329 * V_120 )
{
struct V_7 * V_8 = F_176 ( V_120 , struct V_7 ,
V_120 . V_120 ) ;
bool V_328 ;
F_73 ( & V_8 -> V_117 ) ;
while ( true ) {
int V_68 ;
if ( ( V_328 = F_172 ( V_8 ) ) ) {
F_39 ( L_118 , V_45 , V_8 ) ;
break;
}
if ( F_173 ( V_8 ) ) {
F_39 ( L_119 , V_45 , V_8 ) ;
break;
}
if ( V_8 -> V_56 == V_330 ) {
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
V_68 = F_169 ( V_8 ) ;
if ( V_68 < 0 ) {
if ( V_68 == - V_91 )
continue;
V_8 -> V_80 = L_123 ;
V_328 = true ;
break;
}
V_68 = F_168 ( V_8 ) ;
if ( V_68 < 0 ) {
if ( V_68 == - V_91 )
continue;
V_8 -> V_80 = L_124 ;
V_328 = true ;
}
break;
}
if ( V_328 )
F_177 ( V_8 ) ;
F_75 ( & V_8 -> V_117 ) ;
if ( V_328 )
F_175 ( V_8 ) ;
V_8 -> V_75 -> V_107 ( V_8 ) ;
}
static void F_177 ( struct V_7 * V_8 )
{
F_156 ( L_125 , F_159 ( V_8 -> V_125 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) , V_8 -> V_80 ) ;
F_39 ( L_126 ,
V_8 , V_8 -> V_56 , F_13 ( & V_8 -> V_66 . V_67 ) ) ;
F_37 ( V_8 -> V_56 != V_310 &&
V_8 -> V_56 != V_214 &&
V_8 -> V_56 != V_290 ) ;
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
F_178 ( & V_8 -> V_110 , & V_8 -> V_109 ) ;
if ( F_69 ( & V_8 -> V_109 ) &&
! F_7 ( V_8 , V_3 ) ) {
F_39 ( L_128 , V_8 ) ;
F_2 ( V_8 , V_4 ) ;
V_8 -> V_56 = V_330 ;
} else {
V_8 -> V_56 = V_124 ;
if ( V_8 -> V_127 == 0 )
V_8 -> V_127 = V_331 ;
else if ( V_8 -> V_127 < V_332 )
V_8 -> V_127 *= 2 ;
F_5 ( V_8 , V_6 ) ;
F_46 ( V_8 ) ;
}
}
void F_179 ( struct V_29 * V_30 ,
struct V_123 * V_333 ,
T_4 V_228 ,
T_4 V_281 ,
bool V_236 )
{
V_30 -> V_228 = V_228 ;
V_30 -> V_281 = V_281 ;
F_180 ( & V_30 -> V_132 ) ;
if ( V_333 )
V_30 -> V_32 . V_33 = * V_333 ;
V_30 -> V_32 . V_33 . type = 0 ;
F_181 ( & V_30 -> V_32 . V_33 . V_278 , sizeof( V_30 -> V_32 . V_33 . V_278 ) ) ;
F_16 ( V_30 ) ;
V_30 -> V_236 = V_236 ;
F_182 ( & V_30 -> V_53 , 0 ) ;
F_39 ( L_129 , V_45 , V_30 ) ;
}
static void F_183 ( struct V_7 * V_8 )
{
if ( V_8 -> V_56 == V_330 ) {
F_39 ( L_130 , V_8 ) ;
V_8 -> V_56 = V_124 ;
V_8 -> V_112 ++ ;
F_37 ( F_7 ( V_8 , V_4 ) ) ;
F_37 ( F_7 ( V_8 , V_3 ) ) ;
}
}
void F_184 ( struct V_7 * V_8 , struct V_35 * V_86 )
{
V_86 -> V_192 . V_308 = V_8 -> V_30 -> V_32 . V_265 ;
F_3 ( V_86 -> V_196 . V_140 != F_113 ( V_86 -> V_192 . V_194 ) ) ;
V_86 -> V_191 = true ;
F_73 ( & V_8 -> V_117 ) ;
if ( V_8 -> V_56 == V_118 ) {
F_39 ( L_131 , V_8 , V_86 ) ;
F_67 ( V_86 ) ;
F_75 ( & V_8 -> V_117 ) ;
return;
}
F_3 ( V_86 -> V_8 != NULL ) ;
V_86 -> V_8 = V_8 -> V_75 -> V_318 ( V_8 ) ;
F_3 ( V_86 -> V_8 == NULL ) ;
F_3 ( ! F_69 ( & V_86 -> V_106 ) ) ;
F_185 ( & V_86 -> V_106 , & V_8 -> V_109 ) ;
F_39 ( L_132 , V_86 ,
F_159 ( V_8 -> V_125 ) , F_114 ( V_86 -> V_192 . type ) ,
F_167 ( F_114 ( V_86 -> V_192 . type ) ) ,
F_113 ( V_86 -> V_192 . V_194 ) ,
F_113 ( V_86 -> V_192 . V_195 ) ,
F_113 ( V_86 -> V_192 . V_179 ) ) ;
F_183 ( V_8 ) ;
F_75 ( & V_8 -> V_117 ) ;
if ( F_11 ( V_8 , V_4 ) == 0 )
F_46 ( V_8 ) ;
}
void F_186 ( struct V_35 * V_86 )
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
V_86 -> V_192 . V_193 = 0 ;
F_67 ( V_86 ) ;
}
if ( V_8 -> V_114 == V_86 ) {
F_39 ( L_134 , V_45 , V_8 , V_86 ) ;
V_8 -> V_114 = NULL ;
if ( V_8 -> V_184 ) {
V_8 -> V_239 = V_8 -> V_135 ;
V_8 -> V_184 = false ;
}
V_86 -> V_192 . V_193 = 0 ;
F_67 ( V_86 ) ;
}
F_75 ( & V_8 -> V_117 ) ;
}
void F_187 ( struct V_35 * V_86 )
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
unsigned int V_194 = F_113 ( V_8 -> V_301 . V_194 ) ;
unsigned int V_195 = F_113 ( V_8 -> V_301 . V_195 ) ;
unsigned int V_179 = F_113 ( V_8 -> V_301 . V_179 ) ;
F_39 ( L_136 , V_45 , V_8 , V_86 ) ;
V_8 -> V_241 = V_8 -> V_241 -
sizeof( struct V_200 ) -
V_194 -
V_195 -
V_179 -
sizeof( struct V_334 ) ;
F_67 ( V_8 -> V_111 ) ;
V_8 -> V_111 = NULL ;
V_8 -> V_242 = V_244 ;
V_8 -> V_115 ++ ;
} else {
F_39 ( L_137 ,
V_45 , V_8 , V_8 -> V_111 , V_86 ) ;
}
F_75 ( & V_8 -> V_117 ) ;
}
void F_188 ( struct V_7 * V_8 )
{
F_39 ( L_138 , V_8 ) ;
F_73 ( & V_8 -> V_117 ) ;
F_183 ( V_8 ) ;
F_75 ( & V_8 -> V_117 ) ;
if ( F_11 ( V_8 , V_3 ) == 0 &&
F_11 ( V_8 , V_4 ) == 0 )
F_46 ( V_8 ) ;
}
static struct V_38 * F_189 ( enum V_335 type )
{
struct V_38 * V_138 ;
if ( F_37 ( ! F_190 ( type ) ) )
return NULL ;
V_138 = F_191 ( V_37 , V_72 ) ;
if ( V_138 )
V_138 -> type = type ;
F_81 ( & V_138 -> V_177 ) ;
return V_138 ;
}
static void F_192 ( struct V_38 * V_138 )
{
if ( ! V_138 )
return;
F_37 ( ! F_69 ( & V_138 -> V_177 ) ) ;
if ( V_138 -> type == V_170 ) {
F_193 ( V_138 -> V_169 ) ;
F_150 ( V_138 -> V_169 ) ;
}
F_194 ( V_37 , V_138 ) ;
}
void F_195 ( struct V_35 * V_86 , struct V_92 * * V_161 ,
T_1 V_94 , T_1 V_162 )
{
struct V_38 * V_138 ;
F_3 ( ! V_161 ) ;
F_3 ( ! V_94 ) ;
V_138 = F_189 ( V_160 ) ;
F_3 ( ! V_138 ) ;
V_138 -> V_161 = V_161 ;
V_138 -> V_94 = V_94 ;
V_138 -> V_162 = V_162 & ~ V_164 ;
F_185 ( & V_138 -> V_177 , & V_86 -> V_138 ) ;
V_86 -> V_175 += V_94 ;
}
void F_196 ( struct V_35 * V_86 ,
struct V_168 * V_169 )
{
struct V_38 * V_138 ;
F_3 ( ! V_169 ) ;
F_3 ( ! V_169 -> V_94 ) ;
V_138 = F_189 ( V_170 ) ;
F_3 ( ! V_138 ) ;
V_138 -> V_169 = V_169 ;
F_185 ( & V_138 -> V_177 , & V_86 -> V_138 ) ;
V_86 -> V_175 += V_169 -> V_94 ;
}
void F_197 ( struct V_35 * V_86 , struct V_144 * V_144 ,
T_1 V_94 )
{
struct V_38 * V_138 ;
F_3 ( ! V_144 ) ;
V_138 = F_189 ( V_145 ) ;
F_3 ( ! V_138 ) ;
V_138 -> V_144 = V_144 ;
V_138 -> V_148 = V_94 ;
F_185 ( & V_138 -> V_177 , & V_86 -> V_138 ) ;
V_86 -> V_175 += V_94 ;
}
struct V_35 * F_198 ( int type , int V_194 , T_6 V_9 ,
bool V_336 )
{
struct V_35 * V_180 ;
V_180 = F_191 ( V_34 , V_9 ) ;
if ( V_180 == NULL )
goto V_234;
V_180 -> V_192 . type = F_199 ( type ) ;
V_180 -> V_192 . V_337 = F_199 ( V_338 ) ;
V_180 -> V_192 . V_194 = F_117 ( V_194 ) ;
F_81 ( & V_180 -> V_106 ) ;
F_200 ( & V_180 -> V_339 ) ;
F_81 ( & V_180 -> V_138 ) ;
V_180 -> V_340 = V_194 ;
if ( V_194 ) {
if ( V_194 > V_240 ) {
V_180 -> V_196 . V_141 = F_201 ( V_194 , V_9 ,
V_341 ) ;
V_180 -> V_342 = true ;
} else {
V_180 -> V_196 . V_141 = F_202 ( V_194 , V_9 ) ;
}
if ( V_180 -> V_196 . V_141 == NULL ) {
F_39 ( L_139 ,
V_194 ) ;
goto V_343;
}
} else {
V_180 -> V_196 . V_141 = NULL ;
}
V_180 -> V_196 . V_140 = V_194 ;
F_39 ( L_140 , V_180 , V_194 ) ;
return V_180 ;
V_343:
F_67 ( V_180 ) ;
V_234:
if ( ! V_336 ) {
F_31 ( L_141 , type ,
V_194 ) ;
F_37 ( 1 ) ;
} else {
F_39 ( L_141 , type ,
V_194 ) ;
}
return NULL ;
}
static int F_203 ( struct V_7 * V_8 , struct V_35 * V_86 )
{
int type = F_114 ( V_86 -> V_192 . type ) ;
int V_195 = F_113 ( V_86 -> V_192 . V_195 ) ;
F_39 ( L_142 , V_86 , type ,
F_167 ( type ) , V_195 ) ;
F_3 ( ! V_195 ) ;
F_3 ( V_86 -> V_198 ) ;
V_86 -> V_198 = F_204 ( V_195 , V_72 ) ;
if ( ! V_86 -> V_198 )
return - V_36 ;
return 0 ;
}
static int F_165 ( struct V_7 * V_8 , int * V_307 )
{
struct V_200 * V_192 = & V_8 -> V_301 ;
int V_195 = F_113 ( V_192 -> V_195 ) ;
struct V_35 * V_86 ;
int V_68 = 0 ;
F_3 ( V_8 -> V_111 != NULL ) ;
F_3 ( ! V_8 -> V_75 -> V_344 ) ;
F_75 ( & V_8 -> V_117 ) ;
V_86 = V_8 -> V_75 -> V_344 ( V_8 , V_192 , V_307 ) ;
F_73 ( & V_8 -> V_117 ) ;
if ( V_8 -> V_56 != V_290 ) {
if ( V_86 )
F_67 ( V_86 ) ;
return - V_91 ;
}
if ( V_86 ) {
F_3 ( * V_307 ) ;
V_8 -> V_111 = V_86 ;
V_8 -> V_111 -> V_8 = V_8 -> V_75 -> V_318 ( V_8 ) ;
F_3 ( V_8 -> V_111 -> V_8 == NULL ) ;
} else {
if ( * V_307 )
return 0 ;
V_8 -> V_80 = L_143 ;
return - V_36 ;
}
memcpy ( & V_8 -> V_111 -> V_192 , & V_8 -> V_301 , sizeof( V_8 -> V_301 ) ) ;
if ( V_195 && ! V_8 -> V_111 -> V_198 ) {
V_68 = F_203 ( V_8 , V_8 -> V_111 ) ;
if ( V_68 < 0 ) {
F_67 ( V_8 -> V_111 ) ;
V_8 -> V_111 = NULL ;
}
}
return V_68 ;
}
void F_205 ( struct V_35 * V_180 )
{
F_39 ( L_144 , V_180 ) ;
if ( V_180 -> V_342 )
F_206 ( V_180 -> V_196 . V_141 ) ;
else
F_150 ( V_180 -> V_196 . V_141 ) ;
F_194 ( V_34 , V_180 ) ;
}
void F_207 ( struct V_339 * V_339 )
{
struct V_35 * V_180 = F_176 ( V_339 , struct V_35 , V_339 ) ;
F_208 ( V_138 ) ;
struct V_106 * V_177 ;
struct V_106 * V_345 ;
F_39 ( L_145 , V_180 ) ;
F_37 ( ! F_69 ( & V_180 -> V_106 ) ) ;
if ( V_180 -> V_198 ) {
F_209 ( V_180 -> V_198 ) ;
V_180 -> V_198 = NULL ;
}
F_178 ( & V_180 -> V_138 , & V_138 ) ;
F_210 (links, next, &data) {
struct V_38 * V_138 ;
V_138 = F_211 ( V_177 , struct V_38 , V_177 ) ;
F_66 ( V_177 ) ;
F_192 ( V_138 ) ;
}
V_180 -> V_175 = 0 ;
if ( V_180 -> V_346 )
F_212 ( V_180 -> V_346 , V_180 ) ;
else
F_205 ( V_180 ) ;
}
void F_213 ( struct V_35 * V_86 )
{
F_214 ( L_146 , V_86 ,
V_86 -> V_340 , V_86 -> V_175 ) ;
F_215 ( V_347 , L_147 ,
V_348 , 16 , 1 ,
& V_86 -> V_192 , sizeof( V_86 -> V_192 ) , true ) ;
F_215 ( V_347 , L_148 ,
V_348 , 16 , 1 ,
V_86 -> V_196 . V_141 , V_86 -> V_196 . V_140 , true ) ;
if ( V_86 -> V_198 )
F_215 ( V_347 , L_149 ,
V_348 , 16 , 1 ,
V_86 -> V_198 -> V_199 . V_141 ,
V_86 -> V_198 -> V_199 . V_140 , true ) ;
F_215 ( V_347 , L_150 ,
V_348 , 16 , 1 ,
& V_86 -> V_182 , sizeof( V_86 -> V_182 ) , true ) ;
}
