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
V_34 = F_19 ( V_35 , 0 ) ;
if ( ! V_34 )
return - V_36 ;
F_3 ( V_37 ) ;
V_37 = F_19 ( V_38 , 0 ) ;
if ( V_37 )
return 0 ;
F_20 ( V_34 ) ;
V_34 = NULL ;
return - V_36 ;
}
static void F_21 ( void )
{
F_3 ( ! V_37 ) ;
F_20 ( V_37 ) ;
V_37 = NULL ;
F_3 ( ! V_34 ) ;
F_20 ( V_34 ) ;
V_34 = NULL ;
}
static void F_22 ( void )
{
if ( V_39 ) {
F_23 ( V_39 ) ;
V_39 = NULL ;
}
F_3 ( V_40 == NULL ) ;
F_24 ( V_40 ) ;
V_40 = NULL ;
F_21 () ;
}
int F_25 ( void )
{
if ( F_18 () )
return - V_36 ;
F_3 ( V_40 != NULL ) ;
V_40 = F_26 ( 0 ) ;
F_27 ( V_40 ) ;
V_39 = F_28 ( L_4 , V_41 , 0 ) ;
if ( V_39 )
return 0 ;
F_29 ( L_5 ) ;
F_22 () ;
return - V_36 ;
}
void F_30 ( void )
{
F_3 ( V_39 == NULL ) ;
F_22 () ;
}
void F_31 ( void )
{
F_32 ( V_39 ) ;
}
static void F_33 ( struct V_7 * V_8 )
{
int V_42 ;
V_42 = F_34 ( & V_8 -> V_43 , V_44 ) ;
if ( F_35 ( V_42 != V_45 ) )
F_36 ( L_6 , V_46 , V_42 ) ;
F_37 ( L_7 , V_46 , V_8 , V_42 ,
V_44 ) ;
}
static void F_38 ( struct V_7 * V_8 )
{
int V_42 ;
V_42 = F_34 ( & V_8 -> V_43 , V_47 ) ;
if ( F_35 ( V_42 != V_44 ) )
F_36 ( L_6 , V_46 , V_42 ) ;
F_37 ( L_7 , V_46 , V_8 , V_42 ,
V_47 ) ;
}
static void F_39 ( struct V_7 * V_8 )
{
int V_42 ;
V_42 = F_34 ( & V_8 -> V_43 , V_48 ) ;
if ( F_35 ( V_42 != V_47 ) )
F_36 ( L_6 , V_46 , V_42 ) ;
F_37 ( L_7 , V_46 , V_8 , V_42 ,
V_48 ) ;
}
static void F_40 ( struct V_7 * V_8 )
{
int V_42 ;
V_42 = F_34 ( & V_8 -> V_43 , V_49 ) ;
if ( F_35 ( V_42 != V_47 &&
V_42 != V_48 &&
V_42 != V_49 ) )
F_36 ( L_6 , V_46 , V_42 ) ;
F_37 ( L_7 , V_46 , V_8 , V_42 ,
V_49 ) ;
}
static void F_41 ( struct V_7 * V_8 )
{
int V_42 ;
V_42 = F_34 ( & V_8 -> V_43 , V_44 ) ;
if ( F_35 ( V_42 != V_48 &&
V_42 != V_49 &&
V_42 != V_47 &&
V_42 != V_44 ) )
F_36 ( L_6 , V_46 , V_42 ) ;
F_37 ( L_7 , V_46 , V_8 , V_42 ,
V_44 ) ;
}
static void F_42 ( struct V_50 * V_51 )
{
struct V_7 * V_8 = V_51 -> V_52 ;
if ( F_43 ( & V_8 -> V_30 -> V_53 ) ) {
return;
}
if ( V_51 -> V_54 != V_55 ) {
F_37 ( L_8 , V_46 ,
V_8 , V_8 -> V_56 ) ;
F_44 ( V_8 ) ;
}
}
static void F_45 ( struct V_50 * V_51 )
{
struct V_7 * V_8 = V_51 -> V_52 ;
if ( F_7 ( V_8 , V_4 ) ) {
if ( F_46 ( V_51 ) ) {
F_37 ( L_9 , V_46 , V_8 ) ;
F_4 ( V_57 , & V_51 -> V_58 -> V_9 ) ;
F_44 ( V_8 ) ;
}
} else {
F_37 ( L_10 , V_46 , V_8 ) ;
}
}
static void F_47 ( struct V_50 * V_51 )
{
struct V_7 * V_8 = V_51 -> V_52 ;
F_37 ( L_11 , V_46 ,
V_8 , V_8 -> V_56 , V_51 -> V_54 ) ;
switch ( V_51 -> V_54 ) {
case V_59 :
F_37 ( L_12 , V_46 ) ;
case V_55 :
F_37 ( L_13 , V_46 ) ;
F_40 ( V_8 ) ;
F_5 ( V_8 , V_5 ) ;
F_44 ( V_8 ) ;
break;
case V_60 :
F_37 ( L_14 , V_46 ) ;
F_39 ( V_8 ) ;
F_44 ( V_8 ) ;
break;
default:
break;
}
}
static void F_48 ( struct V_61 * V_50 ,
struct V_7 * V_8 )
{
struct V_50 * V_51 = V_50 -> V_51 ;
V_51 -> V_52 = V_8 ;
V_51 -> V_62 = F_42 ;
V_51 -> V_63 = F_45 ;
V_51 -> V_64 = F_47 ;
}
static int F_49 ( struct V_7 * V_8 )
{
struct V_10 * V_65 = & V_8 -> V_66 . V_67 ;
struct V_61 * V_50 ;
int V_68 ;
F_3 ( V_8 -> V_50 ) ;
V_68 = F_50 ( F_51 ( & V_8 -> V_30 -> V_69 ) , V_65 -> V_21 ,
V_70 , V_71 , & V_50 ) ;
if ( V_68 )
return V_68 ;
V_50 -> V_51 -> V_72 = V_73 ;
#ifdef F_52
F_53 ( & V_50 -> V_51 -> V_74 , & V_75 ) ;
#endif
F_48 ( V_50 , V_8 ) ;
F_37 ( L_15 , F_13 ( & V_8 -> V_66 . V_67 ) ) ;
F_38 ( V_8 ) ;
V_68 = V_50 -> V_76 -> V_77 ( V_50 , (struct V_78 * ) V_65 , sizeof( * V_65 ) ,
V_79 ) ;
if ( V_68 == - V_80 ) {
F_37 ( L_16 ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_50 -> V_51 -> V_54 ) ;
} else if ( V_68 < 0 ) {
F_29 ( L_17 ,
F_13 ( & V_8 -> V_66 . V_67 ) , V_68 ) ;
F_54 ( V_50 ) ;
return V_68 ;
}
if ( F_55 ( F_56 ( V_8 -> V_30 ) , V_81 ) ) {
int V_82 = 1 ;
V_68 = F_57 ( V_50 , V_83 , V_81 ,
( char * ) & V_82 , sizeof( V_82 ) ) ;
if ( V_68 )
F_29 ( L_18 ,
V_68 ) ;
}
V_8 -> V_50 = V_50 ;
return 0 ;
}
static int F_58 ( struct V_61 * V_50 , void * V_84 , T_1 V_85 )
{
struct V_86 V_87 = { V_84 , V_85 } ;
struct V_88 V_89 = { . V_90 = V_91 | V_92 } ;
int V_93 ;
V_93 = F_59 ( V_50 , & V_89 , & V_87 , 1 , V_85 , V_89 . V_90 ) ;
if ( V_93 == - V_94 )
V_93 = 0 ;
return V_93 ;
}
static int F_60 ( struct V_61 * V_50 , struct V_95 * V_95 ,
int V_96 , T_1 V_97 )
{
void * V_98 ;
int V_68 ;
F_3 ( V_96 + V_97 > V_99 ) ;
V_98 = F_61 ( V_95 ) ;
F_3 ( ! V_98 ) ;
V_68 = F_58 ( V_50 , V_98 + V_96 , V_97 ) ;
F_62 ( V_95 ) ;
return V_68 ;
}
static int F_63 ( struct V_61 * V_50 , struct V_86 * V_87 ,
T_1 V_100 , T_1 V_85 , int V_101 )
{
struct V_88 V_89 = { . V_90 = V_91 | V_92 } ;
int V_93 ;
if ( V_101 )
V_89 . V_90 |= V_102 ;
else
V_89 . V_90 |= V_103 ;
V_93 = F_64 ( V_50 , & V_89 , V_87 , V_100 , V_85 ) ;
if ( V_93 == - V_94 )
V_93 = 0 ;
return V_93 ;
}
static int F_65 ( struct V_61 * V_50 , struct V_95 * V_95 ,
int V_104 , T_1 V_105 , bool V_101 )
{
int V_9 = V_91 | V_92 | ( V_101 ? V_102 : V_103 ) ;
int V_68 ;
V_68 = F_66 ( V_50 , V_95 , V_104 , V_105 , V_9 ) ;
if ( V_68 == - V_94 )
V_68 = 0 ;
return V_68 ;
}
static int F_67 ( struct V_61 * V_50 , struct V_95 * V_95 ,
int V_104 , T_1 V_105 , bool V_101 )
{
int V_68 ;
struct V_86 V_87 ;
if ( F_68 ( V_95 ) >= 1 )
return F_65 ( V_50 , V_95 , V_104 , V_105 , V_101 ) ;
V_87 . V_106 = F_61 ( V_95 ) + V_104 ;
V_87 . V_107 = V_105 ;
V_68 = F_63 ( V_50 , & V_87 , 1 , V_105 , V_101 ) ;
F_62 ( V_95 ) ;
return V_68 ;
}
static int F_69 ( struct V_7 * V_8 )
{
int V_108 = 0 ;
F_37 ( L_19 , V_8 , V_8 -> V_50 ) ;
if ( V_8 -> V_50 ) {
V_108 = V_8 -> V_50 -> V_76 -> V_109 ( V_8 -> V_50 , V_110 ) ;
F_54 ( V_8 -> V_50 ) ;
V_8 -> V_50 = NULL ;
}
F_2 ( V_8 , V_5 ) ;
F_41 ( V_8 ) ;
return V_108 ;
}
static void F_70 ( struct V_35 * V_89 )
{
F_71 ( & V_89 -> V_111 ) ;
F_72 ( V_89 ) ;
}
static void F_73 ( struct V_111 * V_112 )
{
while ( ! F_74 ( V_112 ) ) {
struct V_35 * V_89 = F_75 ( V_112 , struct V_35 ,
V_111 ) ;
F_70 ( V_89 ) ;
}
}
static void F_76 ( struct V_7 * V_8 )
{
F_37 ( L_20 , V_8 ) ;
F_73 ( & V_8 -> V_113 ) ;
F_73 ( & V_8 -> V_114 ) ;
if ( V_8 -> V_115 ) {
F_3 ( V_8 -> V_115 -> V_8 != V_8 ) ;
F_72 ( V_8 -> V_115 ) ;
V_8 -> V_115 = NULL ;
}
V_8 -> V_116 = 0 ;
V_8 -> V_117 = 0 ;
if ( V_8 -> V_118 ) {
F_3 ( V_8 -> V_118 -> V_8 != V_8 ) ;
F_72 ( V_8 -> V_118 ) ;
V_8 -> V_118 = NULL ;
}
V_8 -> V_119 = 0 ;
V_8 -> V_120 = 0 ;
V_8 -> V_121 = 0 ;
}
void F_77 ( struct V_7 * V_8 )
{
F_78 ( & V_8 -> V_122 ) ;
F_37 ( L_21 , V_8 ,
F_13 ( & V_8 -> V_66 . V_67 ) ) ;
V_8 -> V_56 = V_123 ;
F_2 ( V_8 , V_2 ) ;
F_2 ( V_8 , V_3 ) ;
F_2 ( V_8 , V_4 ) ;
F_2 ( V_8 , V_6 ) ;
F_76 ( V_8 ) ;
V_8 -> V_124 = 0 ;
F_79 ( V_8 ) ;
F_69 ( V_8 ) ;
F_80 ( & V_8 -> V_122 ) ;
}
void F_81 ( struct V_7 * V_8 ,
T_2 V_125 , T_3 V_126 ,
struct V_127 * V_33 )
{
F_78 ( & V_8 -> V_122 ) ;
F_37 ( L_22 , V_8 , F_13 ( & V_33 -> V_67 ) ) ;
F_35 ( V_8 -> V_56 != V_123 ) ;
V_8 -> V_56 = V_128 ;
V_8 -> V_129 . type = ( T_2 ) V_125 ;
V_8 -> V_129 . V_130 = F_82 ( V_126 ) ;
memcpy ( & V_8 -> V_66 , V_33 , sizeof( * V_33 ) ) ;
V_8 -> V_131 = 0 ;
F_80 ( & V_8 -> V_122 ) ;
F_44 ( V_8 ) ;
}
bool F_83 ( struct V_7 * V_8 )
{
return V_8 -> V_116 > 0 ;
}
void F_84 ( struct V_7 * V_8 , void * V_132 ,
const struct V_133 * V_76 ,
struct V_29 * V_30 )
{
F_37 ( L_23 , V_8 ) ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> V_132 = V_132 ;
V_8 -> V_76 = V_76 ;
V_8 -> V_30 = V_30 ;
F_33 ( V_8 ) ;
F_85 ( & V_8 -> V_122 ) ;
F_86 ( & V_8 -> V_113 ) ;
F_86 ( & V_8 -> V_114 ) ;
F_87 ( & V_8 -> V_134 , V_135 ) ;
V_8 -> V_56 = V_123 ;
}
static T_4 F_88 ( struct V_29 * V_30 , T_4 V_136 )
{
T_4 V_68 ;
F_89 ( & V_30 -> V_137 ) ;
if ( V_30 -> V_138 < V_136 )
V_30 -> V_138 = V_136 ;
V_68 = ++ V_30 -> V_138 ;
F_90 ( & V_30 -> V_137 ) ;
return V_68 ;
}
static void F_91 ( struct V_7 * V_8 )
{
F_3 ( V_8 -> V_121 ) ;
V_8 -> V_139 = 0 ;
V_8 -> V_140 = 0 ;
V_8 -> V_141 = & V_8 -> V_142 [ 0 ] ;
}
static void F_92 ( struct V_7 * V_8 ,
T_1 V_105 , void * V_143 )
{
int V_144 = V_8 -> V_139 ;
F_3 ( V_8 -> V_121 ) ;
F_3 ( V_144 >= F_93 ( V_8 -> V_142 ) ) ;
V_8 -> V_142 [ V_144 ] . V_107 = V_105 ;
V_8 -> V_142 [ V_144 ] . V_106 = V_143 ;
V_8 -> V_139 ++ ;
V_8 -> V_140 += V_105 ;
}
static int F_94 ( struct V_7 * V_8 )
{
int V_145 = V_8 -> V_141 - V_8 -> V_142 ;
int V_146 = 0 ;
if ( V_8 -> V_140 > 0 ) {
V_146 = V_8 -> V_142 [ V_145 + V_8 -> V_139 - 1 ] . V_107 ;
F_3 ( V_8 -> V_140 < V_146 ) ;
F_3 ( ! V_8 -> V_139 ) ;
V_8 -> V_140 -= V_146 ;
V_8 -> V_139 -- ;
}
return V_146 ;
}
static void F_95 ( struct V_147 * V_148 ,
T_1 V_97 )
{
struct V_38 * V_143 = V_148 -> V_143 ;
struct V_149 * V_149 ;
F_3 ( V_143 -> type != V_150 ) ;
V_149 = V_143 -> V_149 ;
F_3 ( ! V_149 ) ;
V_148 -> V_151 = F_96 ( V_97 , V_143 -> V_152 ) ;
V_148 -> V_149 = V_149 ;
V_148 -> V_153 = V_149 -> V_154 ;
V_148 -> V_155 =
V_148 -> V_151 <= F_97 ( V_149 , V_148 -> V_153 ) ;
}
static struct V_95 * F_98 ( struct V_147 * V_148 ,
T_1 * V_96 ,
T_1 * V_97 )
{
struct V_38 * V_143 = V_148 -> V_143 ;
struct V_149 * V_149 ;
struct V_156 V_156 ;
F_3 ( V_143 -> type != V_150 ) ;
V_149 = V_148 -> V_149 ;
F_3 ( ! V_149 ) ;
V_156 = F_99 ( V_149 , V_148 -> V_153 ) ;
* V_96 = ( T_1 ) V_156 . V_157 ;
F_3 ( * V_96 >= V_99 ) ;
if ( V_148 -> V_155 )
* V_97 = V_148 -> V_151 ;
else
* V_97 = ( T_1 ) V_156 . V_158 ;
F_3 ( * V_97 > V_148 -> V_151 ) ;
F_3 ( * V_96 + * V_97 > V_99 ) ;
return V_156 . V_159 ;
}
static bool F_100 ( struct V_147 * V_148 ,
T_1 V_160 )
{
struct V_149 * V_149 ;
struct V_156 V_156 ;
F_3 ( V_148 -> V_143 -> type != V_150 ) ;
V_149 = V_148 -> V_149 ;
F_3 ( ! V_149 ) ;
V_156 = F_99 ( V_149 , V_148 -> V_153 ) ;
F_3 ( V_148 -> V_151 < V_160 ) ;
V_148 -> V_151 -= V_160 ;
F_101 ( V_149 , & V_148 -> V_153 , V_160 ) ;
if ( V_160 < V_156 . V_158 )
return false ;
if ( ! V_148 -> V_153 . V_161 ) {
V_149 = V_149 -> V_162 ;
V_148 -> V_149 = V_149 ;
if ( V_149 )
V_148 -> V_153 = V_149 -> V_154 ;
else
memset ( & V_148 -> V_153 , 0 ,
sizeof( V_148 -> V_153 ) ) ;
}
if ( ! V_148 -> V_155 ) {
F_3 ( ! V_148 -> V_151 ) ;
F_3 ( ! V_149 ) ;
if ( V_148 -> V_151 <= F_97 ( V_149 , V_148 -> V_153 ) )
V_148 -> V_155 = true ;
}
return true ;
}
static void F_102 ( struct V_147 * V_148 ,
T_1 V_97 )
{
struct V_38 * V_143 = V_148 -> V_143 ;
int F_68 ;
F_3 ( V_143 -> type != V_163 ) ;
F_3 ( ! V_143 -> V_164 ) ;
F_3 ( ! V_143 -> V_97 ) ;
V_148 -> V_151 = F_96 ( V_97 , V_143 -> V_97 ) ;
F_68 = F_103 ( V_143 -> V_165 , ( V_166 ) V_143 -> V_97 ) ;
V_148 -> V_96 = V_143 -> V_165 & ~ V_167 ;
V_148 -> V_168 = 0 ;
F_3 ( F_68 > ( int ) V_169 ) ;
V_148 -> F_68 = ( unsigned short ) F_68 ;
F_3 ( V_97 > V_170 - V_148 -> V_96 ) ;
V_148 -> V_155 = V_148 -> V_96 + V_148 -> V_151 <= V_99 ;
}
static struct V_95 *
F_104 ( struct V_147 * V_148 ,
T_1 * V_96 , T_1 * V_97 )
{
struct V_38 * V_143 = V_148 -> V_143 ;
F_3 ( V_143 -> type != V_163 ) ;
F_3 ( V_148 -> V_168 >= V_148 -> F_68 ) ;
F_3 ( V_148 -> V_96 >= V_99 ) ;
* V_96 = V_148 -> V_96 ;
if ( V_148 -> V_155 )
* V_97 = V_148 -> V_151 ;
else
* V_97 = V_99 - * V_96 ;
return V_143 -> V_164 [ V_148 -> V_168 ] ;
}
static bool F_105 ( struct V_147 * V_148 ,
T_1 V_160 )
{
F_3 ( V_148 -> V_143 -> type != V_163 ) ;
F_3 ( V_148 -> V_96 + V_160 > V_99 ) ;
V_148 -> V_151 -= V_160 ;
V_148 -> V_96 = ( V_148 -> V_96 + V_160 ) & ~ V_167 ;
if ( ! V_160 || V_148 -> V_96 )
return false ;
if ( ! V_148 -> V_151 )
return false ;
F_3 ( V_148 -> V_168 >= V_148 -> F_68 ) ;
V_148 -> V_168 ++ ;
V_148 -> V_155 = V_148 -> V_151 <= V_99 ;
return true ;
}
static void
F_106 ( struct V_147 * V_148 ,
T_1 V_97 )
{
struct V_38 * V_143 = V_148 -> V_143 ;
struct V_171 * V_172 ;
struct V_95 * V_95 ;
F_3 ( V_143 -> type != V_173 ) ;
V_172 = V_143 -> V_172 ;
F_3 ( ! V_172 ) ;
if ( ! V_97 )
return;
F_3 ( F_74 ( & V_172 -> V_112 ) ) ;
V_95 = F_75 ( & V_172 -> V_112 , struct V_95 , V_174 ) ;
V_148 -> V_151 = F_96 ( V_97 , V_172 -> V_97 ) ;
V_148 -> V_95 = V_95 ;
V_148 -> V_104 = 0 ;
V_148 -> V_155 = V_148 -> V_151 <= V_99 ;
}
static struct V_95 *
F_107 ( struct V_147 * V_148 ,
T_1 * V_96 , T_1 * V_97 )
{
struct V_38 * V_143 = V_148 -> V_143 ;
struct V_171 * V_172 ;
F_3 ( V_143 -> type != V_173 ) ;
V_172 = V_143 -> V_172 ;
F_3 ( ! V_172 ) ;
F_3 ( ! V_148 -> V_95 ) ;
F_3 ( V_148 -> V_104 + V_148 -> V_151 != V_172 -> V_97 ) ;
* V_96 = V_148 -> V_104 & ~ V_167 ;
if ( V_148 -> V_155 )
* V_97 = V_148 -> V_151 ;
else
* V_97 = V_99 - * V_96 ;
return V_148 -> V_95 ;
}
static bool F_108 ( struct V_147 * V_148 ,
T_1 V_160 )
{
struct V_38 * V_143 = V_148 -> V_143 ;
struct V_171 * V_172 ;
F_3 ( V_143 -> type != V_173 ) ;
V_172 = V_143 -> V_172 ;
F_3 ( ! V_172 ) ;
F_3 ( V_148 -> V_104 + V_148 -> V_151 != V_172 -> V_97 ) ;
F_3 ( ( V_148 -> V_104 & ~ V_167 ) + V_160 > V_99 ) ;
V_148 -> V_151 -= V_160 ;
V_148 -> V_104 += V_160 ;
if ( ! V_160 || V_148 -> V_104 & ~ V_167 )
return false ;
if ( ! V_148 -> V_151 )
return false ;
F_3 ( F_109 ( & V_148 -> V_95 -> V_174 , & V_172 -> V_112 ) ) ;
V_148 -> V_95 = F_110 ( V_148 -> V_95 , V_174 ) ;
V_148 -> V_155 = V_148 -> V_151 <= V_99 ;
return true ;
}
static void F_111 ( struct V_147 * V_148 )
{
T_1 V_97 = V_148 -> V_175 ;
switch ( V_148 -> V_143 -> type ) {
case V_173 :
F_106 ( V_148 , V_97 ) ;
break;
case V_163 :
F_102 ( V_148 , V_97 ) ;
break;
#ifdef F_112
case V_150 :
F_95 ( V_148 , V_97 ) ;
break;
#endif
case V_176 :
default:
break;
}
V_148 -> V_177 = true ;
}
static void F_113 ( struct V_35 * V_89 , T_1 V_97 )
{
struct V_147 * V_148 = & V_89 -> V_148 ;
struct V_38 * V_143 ;
F_3 ( ! V_97 ) ;
F_3 ( V_97 > V_89 -> V_178 ) ;
F_3 ( F_74 ( & V_89 -> V_143 ) ) ;
V_148 -> V_179 = & V_89 -> V_143 ;
V_148 -> V_175 = V_97 ;
V_143 = F_75 ( & V_89 -> V_143 , struct V_38 , V_180 ) ;
V_148 -> V_143 = V_143 ;
F_111 ( V_148 ) ;
}
static struct V_95 * F_114 ( struct V_147 * V_148 ,
T_1 * V_96 , T_1 * V_97 ,
bool * V_155 )
{
struct V_95 * V_95 ;
switch ( V_148 -> V_143 -> type ) {
case V_173 :
V_95 = F_107 ( V_148 , V_96 , V_97 ) ;
break;
case V_163 :
V_95 = F_104 ( V_148 , V_96 , V_97 ) ;
break;
#ifdef F_112
case V_150 :
V_95 = F_98 ( V_148 , V_96 , V_97 ) ;
break;
#endif
case V_176 :
default:
V_95 = NULL ;
break;
}
F_3 ( ! V_95 ) ;
F_3 ( * V_96 + * V_97 > V_99 ) ;
F_3 ( ! * V_97 ) ;
if ( V_155 )
* V_155 = V_148 -> V_155 ;
return V_95 ;
}
static bool F_115 ( struct V_147 * V_148 ,
T_1 V_160 )
{
bool V_181 ;
F_3 ( V_160 > V_148 -> V_151 ) ;
switch ( V_148 -> V_143 -> type ) {
case V_173 :
V_181 = F_108 ( V_148 , V_160 ) ;
break;
case V_163 :
V_181 = F_105 ( V_148 , V_160 ) ;
break;
#ifdef F_112
case V_150 :
V_181 = F_100 ( V_148 , V_160 ) ;
break;
#endif
case V_176 :
default:
F_116 () ;
break;
}
V_148 -> V_175 -= V_160 ;
if ( ! V_148 -> V_151 && V_148 -> V_175 ) {
F_35 ( ! V_148 -> V_155 ) ;
F_3 ( F_109 ( & V_148 -> V_143 -> V_180 , V_148 -> V_179 ) ) ;
V_148 -> V_143 = F_110 ( V_148 -> V_143 , V_180 ) ;
F_111 ( V_148 ) ;
V_181 = true ;
}
V_148 -> V_177 = V_181 ;
return V_181 ;
}
static T_1 F_117 ( struct V_7 * V_8 )
{
return ( V_8 -> V_182 & V_183 ) ?
sizeof( struct V_184 ) :
sizeof( struct V_185 ) ;
}
static void F_118 ( struct V_35 * V_89 , T_4 V_186 )
{
F_3 ( ! V_89 ) ;
F_3 ( ! V_186 ) ;
F_113 ( V_89 , ( T_1 ) V_186 ) ;
}
static void F_119 ( struct V_7 * V_8 )
{
struct V_35 * V_187 = V_8 -> V_118 ;
V_187 -> V_188 . V_9 |= V_189 ;
F_37 ( L_24 , V_8 ) ;
F_92 ( V_8 , F_117 ( V_8 ) , & V_187 -> V_188 ) ;
if ( V_8 -> V_182 & V_183 ) {
if ( V_8 -> V_76 -> V_190 )
V_8 -> V_76 -> V_190 ( V_187 ) ;
else
V_187 -> V_188 . V_191 = 0 ;
} else {
V_187 -> V_192 . V_9 = V_187 -> V_188 . V_9 ;
}
V_8 -> V_193 = V_187 -> V_194 ;
V_8 -> V_195 = true ;
}
static void F_120 ( struct V_7 * V_8 )
{
struct V_35 * V_187 ;
T_4 V_196 ;
F_91 ( V_8 ) ;
V_8 -> V_195 = false ;
if ( V_8 -> V_119 > V_8 -> V_120 ) {
V_8 -> V_120 = V_8 -> V_119 ;
F_92 ( V_8 , sizeof ( V_197 ) , & V_197 ) ;
V_8 -> V_198 = F_82 ( V_8 -> V_120 ) ;
F_92 ( V_8 , sizeof ( V_8 -> V_198 ) ,
& V_8 -> V_198 ) ;
}
F_3 ( F_74 ( & V_8 -> V_113 ) ) ;
V_187 = F_75 ( & V_8 -> V_113 , struct V_35 , V_111 ) ;
V_8 -> V_118 = V_187 ;
F_3 ( V_187 -> V_8 != V_8 ) ;
F_121 ( V_187 ) ;
F_122 ( & V_187 -> V_111 , & V_8 -> V_114 ) ;
if ( V_187 -> V_199 ) {
V_187 -> V_200 . V_201 = F_82 ( ++ V_8 -> V_117 ) ;
V_187 -> V_199 = false ;
}
F_35 ( V_187 -> V_178 != F_123 ( V_187 -> V_200 . V_186 ) ) ;
F_37 ( L_25 ,
V_187 , V_8 -> V_117 , F_124 ( V_187 -> V_200 . type ) ,
F_123 ( V_187 -> V_200 . V_202 ) , F_123 ( V_187 -> V_200 . V_203 ) ,
V_187 -> V_178 ) ;
F_3 ( F_123 ( V_187 -> V_200 . V_202 ) != V_187 -> V_204 . V_107 ) ;
F_92 ( V_8 , sizeof ( V_205 ) , & V_205 ) ;
F_92 ( V_8 , sizeof( V_8 -> V_206 ) , & V_8 -> V_206 ) ;
F_92 ( V_8 , V_187 -> V_204 . V_107 , V_187 -> V_204 . V_106 ) ;
if ( V_187 -> V_207 )
F_92 ( V_8 , V_187 -> V_207 -> V_208 . V_107 ,
V_187 -> V_207 -> V_208 . V_106 ) ;
V_196 = F_125 ( 0 , & V_187 -> V_200 , F_126 ( struct V_209 , V_196 ) ) ;
V_8 -> V_118 -> V_200 . V_196 = F_127 ( V_196 ) ;
memcpy ( & V_8 -> V_206 , & V_8 -> V_118 -> V_200 , sizeof( V_8 -> V_206 ) ) ;
V_196 = F_125 ( 0 , V_187 -> V_204 . V_106 , V_187 -> V_204 . V_107 ) ;
V_8 -> V_118 -> V_188 . V_210 = F_127 ( V_196 ) ;
if ( V_187 -> V_207 ) {
V_196 = F_125 ( 0 , V_187 -> V_207 -> V_208 . V_106 ,
V_187 -> V_207 -> V_208 . V_107 ) ;
V_8 -> V_118 -> V_188 . V_211 = F_127 ( V_196 ) ;
} else
V_8 -> V_118 -> V_188 . V_211 = 0 ;
F_37 ( L_26 , V_46 ,
F_123 ( V_8 -> V_118 -> V_188 . V_210 ) ,
F_123 ( V_8 -> V_118 -> V_188 . V_211 ) ) ;
V_8 -> V_118 -> V_188 . V_9 = 0 ;
V_8 -> V_118 -> V_188 . V_212 = 0 ;
if ( V_187 -> V_178 ) {
F_118 ( V_8 -> V_118 , V_187 -> V_178 ) ;
V_8 -> V_193 = 1 ;
} else {
F_119 ( V_8 ) ;
}
F_5 ( V_8 , V_4 ) ;
}
static void F_128 ( struct V_7 * V_8 )
{
F_37 ( L_27 , V_8 ,
V_8 -> V_120 , V_8 -> V_119 ) ;
V_8 -> V_120 = V_8 -> V_119 ;
F_91 ( V_8 ) ;
F_92 ( V_8 , sizeof ( V_197 ) , & V_197 ) ;
V_8 -> V_198 = F_82 ( V_8 -> V_120 ) ;
F_92 ( V_8 , sizeof ( V_8 -> V_198 ) ,
& V_8 -> V_198 ) ;
V_8 -> V_193 = 1 ;
F_5 ( V_8 , V_4 ) ;
}
static void F_129 ( struct V_7 * V_8 )
{
F_37 ( L_28 , V_8 ,
V_8 -> V_120 , V_8 -> V_119 ) ;
V_8 -> V_120 = V_8 -> V_119 ;
F_91 ( V_8 ) ;
V_8 -> V_198 = F_82 ( V_8 -> V_120 ) ;
F_92 ( V_8 , sizeof ( V_8 -> V_198 ) ,
& V_8 -> V_198 ) ;
F_5 ( V_8 , V_4 ) ;
}
static void F_130 ( struct V_7 * V_8 )
{
F_37 ( L_29 , V_8 ) ;
F_91 ( V_8 ) ;
if ( V_8 -> V_182 & V_213 ) {
struct V_214 V_215 = V_216 ;
F_92 ( V_8 , sizeof( V_217 ) , & V_217 ) ;
F_131 ( & V_8 -> V_218 , & V_215 ) ;
F_92 ( V_8 , sizeof( V_8 -> V_218 ) ,
& V_8 -> V_218 ) ;
} else {
F_92 ( V_8 , sizeof( V_219 ) , & V_219 ) ;
}
F_5 ( V_8 , V_4 ) ;
}
static struct V_220 * F_132 ( struct V_7 * V_8 ,
int * V_221 )
{
struct V_220 * V_222 ;
if ( ! V_8 -> V_76 -> V_223 ) {
V_8 -> V_224 . V_225 = V_226 ;
V_8 -> V_224 . V_227 = 0 ;
return NULL ;
}
V_222 = V_8 -> V_76 -> V_223 ( V_8 , V_221 , V_8 -> V_228 ) ;
if ( F_133 ( V_222 ) )
return V_222 ;
V_8 -> V_229 = V_222 -> V_230 ;
V_8 -> V_231 = V_222 -> V_232 ;
return V_222 ;
}
static void F_134 ( struct V_7 * V_8 )
{
F_92 ( V_8 , strlen ( V_233 ) , V_233 ) ;
F_92 ( V_8 , sizeof ( V_8 -> V_30 -> V_31 ) ,
& V_8 -> V_30 -> V_31 ) ;
V_8 -> V_193 = 0 ;
F_5 ( V_8 , V_4 ) ;
}
static int F_135 ( struct V_7 * V_8 )
{
unsigned int V_138 = F_88 ( V_8 -> V_30 , 0 ) ;
int V_234 ;
int V_221 ;
struct V_220 * V_222 ;
switch ( V_8 -> V_129 . type ) {
case V_235 :
V_234 = V_236 ;
break;
case V_237 :
V_234 = V_238 ;
break;
case V_239 :
V_234 = V_240 ;
break;
default:
F_116 () ;
}
F_37 ( L_30 , V_8 ,
V_8 -> V_116 , V_138 , V_234 ) ;
V_8 -> V_224 . V_241 =
F_82 ( F_56 ( V_8 -> V_30 ) -> V_242 ) ;
V_8 -> V_224 . V_243 = F_127 ( V_244 ) ;
V_8 -> V_224 . V_116 = F_127 ( V_8 -> V_116 ) ;
V_8 -> V_224 . V_138 = F_127 ( V_138 ) ;
V_8 -> V_224 . V_245 = F_127 ( V_234 ) ;
V_8 -> V_224 . V_9 = 0 ;
V_221 = V_226 ;
V_222 = F_132 ( V_8 , & V_221 ) ;
if ( F_133 ( V_222 ) )
return F_136 ( V_222 ) ;
V_8 -> V_224 . V_225 = F_127 ( V_221 ) ;
V_8 -> V_224 . V_227 = V_222 ?
F_127 ( V_222 -> V_246 ) : 0 ;
F_92 ( V_8 , sizeof ( V_8 -> V_224 ) ,
& V_8 -> V_224 ) ;
if ( V_222 && V_222 -> V_246 )
F_92 ( V_8 , V_222 -> V_246 ,
V_222 -> V_247 ) ;
V_8 -> V_193 = 0 ;
F_5 ( V_8 , V_4 ) ;
return 0 ;
}
static int F_137 ( struct V_7 * V_8 )
{
int V_68 ;
F_37 ( L_31 , V_8 , V_8 -> V_140 ) ;
while ( V_8 -> V_140 > 0 ) {
V_68 = F_63 ( V_8 -> V_50 , V_8 -> V_141 ,
V_8 -> V_139 , V_8 -> V_140 ,
V_8 -> V_193 ) ;
if ( V_68 <= 0 )
goto V_248;
V_8 -> V_140 -= V_68 ;
if ( V_8 -> V_140 == 0 )
break;
while ( V_68 >= V_8 -> V_141 -> V_107 ) {
F_3 ( ! V_8 -> V_139 ) ;
V_68 -= V_8 -> V_141 -> V_107 ;
V_8 -> V_141 ++ ;
V_8 -> V_139 -- ;
}
if ( V_68 ) {
V_8 -> V_141 -> V_107 -= V_68 ;
V_8 -> V_141 -> V_106 += V_68 ;
}
}
V_8 -> V_139 = 0 ;
V_68 = 1 ;
V_248:
F_37 ( L_32 , V_8 ,
V_8 -> V_140 , V_8 -> V_139 , V_68 ) ;
return V_68 ;
}
static T_4 F_138 ( T_4 V_196 , struct V_95 * V_95 ,
unsigned int V_96 ,
unsigned int V_97 )
{
char * V_98 ;
V_98 = F_61 ( V_95 ) ;
F_3 ( V_98 == NULL ) ;
V_196 = F_125 ( V_196 , V_98 + V_96 , V_97 ) ;
F_62 ( V_95 ) ;
return V_196 ;
}
static int F_139 ( struct V_7 * V_8 )
{
struct V_35 * V_89 = V_8 -> V_118 ;
struct V_147 * V_148 = & V_89 -> V_148 ;
bool V_249 = ! F_55 ( F_56 ( V_8 -> V_30 ) , V_250 ) ;
T_4 V_196 ;
F_37 ( L_33 , V_46 , V_8 , V_89 ) ;
if ( F_74 ( & V_89 -> V_143 ) )
return - V_251 ;
V_196 = V_249 ? F_123 ( V_89 -> V_188 . V_212 ) : 0 ;
while ( V_148 -> V_151 ) {
struct V_95 * V_95 ;
T_1 V_96 ;
T_1 V_97 ;
bool V_155 ;
bool V_177 ;
int V_68 ;
V_95 = F_114 ( V_148 , & V_96 , & V_97 ,
& V_155 ) ;
V_68 = F_67 ( V_8 -> V_50 , V_95 , V_96 ,
V_97 , ! V_155 ) ;
if ( V_68 <= 0 ) {
if ( V_249 )
V_89 -> V_188 . V_212 = F_127 ( V_196 ) ;
return V_68 ;
}
if ( V_249 && V_148 -> V_177 )
V_196 = F_138 ( V_196 , V_95 , V_96 , V_97 ) ;
V_177 = F_115 ( V_148 , ( T_1 ) V_68 ) ;
}
F_37 ( L_34 , V_46 , V_8 , V_89 ) ;
if ( V_249 )
V_89 -> V_188 . V_212 = F_127 ( V_196 ) ;
else
V_89 -> V_188 . V_9 |= V_252 ;
F_91 ( V_8 ) ;
F_119 ( V_8 ) ;
return 1 ;
}
static int F_140 ( struct V_7 * V_8 )
{
int V_68 ;
F_37 ( L_35 , V_46 , V_8 , V_8 -> V_121 ) ;
while ( V_8 -> V_121 > 0 ) {
T_1 V_105 = F_96 ( V_8 -> V_121 , ( int ) V_99 ) ;
V_68 = F_67 ( V_8 -> V_50 , V_40 , 0 , V_105 , true ) ;
if ( V_68 <= 0 )
goto V_248;
V_8 -> V_121 -= V_68 ;
}
V_68 = 1 ;
V_248:
return V_68 ;
}
static void F_141 ( struct V_7 * V_8 )
{
F_37 ( L_36 , V_8 ) ;
V_8 -> V_253 = 0 ;
}
static void F_142 ( struct V_7 * V_8 )
{
F_37 ( L_37 , V_8 ) ;
V_8 -> V_253 = 0 ;
}
static void F_143 ( struct V_7 * V_8 )
{
F_37 ( L_38 , V_8 ) ;
V_8 -> V_253 = 0 ;
}
static void F_144 ( struct V_7 * V_8 )
{
F_37 ( L_39 , V_8 ) ;
V_8 -> V_253 = 0 ;
V_8 -> V_254 = V_255 ;
}
static void F_145 ( struct V_7 * V_8 )
{
F_37 ( L_40 , V_8 ) ;
V_8 -> V_253 = 0 ;
V_8 -> V_254 = V_256 ;
}
static void F_146 ( struct V_7 * V_8 )
{
F_37 ( L_41 , V_8 ) ;
V_8 -> V_253 = 0 ;
}
static int F_147 ( struct V_7 * V_8 )
{
F_37 ( L_42 , V_8 ) ;
F_3 ( V_8 -> V_115 != NULL ) ;
V_8 -> V_253 = 0 ;
V_8 -> V_257 = V_8 -> V_258 = V_8 -> V_259 = 0 ;
return 0 ;
}
static int F_148 ( struct V_7 * V_8 ,
int V_260 , int V_105 , void * V_261 )
{
while ( V_8 -> V_253 < V_260 ) {
int V_262 = V_260 - V_8 -> V_253 ;
int V_263 = V_105 - V_262 ;
int V_68 = F_58 ( V_8 -> V_50 , V_261 + V_263 , V_262 ) ;
if ( V_68 <= 0 )
return V_68 ;
V_8 -> V_253 += V_68 ;
}
return 1 ;
}
static int F_149 ( struct V_7 * V_8 )
{
int V_105 ;
int V_260 ;
int V_68 ;
F_37 ( L_43 , V_8 , V_8 -> V_253 ) ;
V_105 = strlen ( V_233 ) ;
V_260 = V_105 ;
V_68 = F_148 ( V_8 , V_260 , V_105 , V_8 -> V_264 ) ;
if ( V_68 <= 0 )
goto V_248;
V_105 = sizeof ( V_8 -> V_265 ) ;
V_260 += V_105 ;
V_68 = F_148 ( V_8 , V_260 , V_105 , & V_8 -> V_265 ) ;
if ( V_68 <= 0 )
goto V_248;
V_105 = sizeof ( V_8 -> V_266 ) ;
V_260 += V_105 ;
V_68 = F_148 ( V_8 , V_260 , V_105 , & V_8 -> V_266 ) ;
if ( V_68 <= 0 )
goto V_248;
V_248:
return V_68 ;
}
static int F_150 ( struct V_7 * V_8 )
{
int V_105 ;
int V_260 ;
int V_68 ;
F_37 ( L_44 , V_8 , V_8 -> V_253 ) ;
V_105 = sizeof ( V_8 -> V_267 ) ;
V_260 = V_105 ;
V_68 = F_148 ( V_8 , V_260 , V_105 , & V_8 -> V_267 ) ;
if ( V_68 <= 0 )
goto V_248;
V_105 = F_123 ( V_8 -> V_267 . V_227 ) ;
V_260 += V_105 ;
V_68 = F_148 ( V_8 , V_260 , V_105 , V_8 -> V_229 ) ;
if ( V_68 <= 0 )
goto V_248;
F_37 ( L_45 ,
V_8 , ( int ) V_8 -> V_267 . V_268 ,
F_123 ( V_8 -> V_267 . V_116 ) ,
F_123 ( V_8 -> V_267 . V_138 ) ) ;
V_248:
return V_68 ;
}
static int F_151 ( struct V_7 * V_8 )
{
if ( memcmp ( V_8 -> V_264 , V_233 , strlen ( V_233 ) ) ) {
F_29 ( L_46 ,
F_13 ( & V_8 -> V_66 . V_67 ) ) ;
V_8 -> V_269 = L_47 ;
return - 1 ;
}
return 0 ;
}
static bool F_152 ( struct V_10 * V_11 )
{
struct V_67 * V_33 = & ( (struct V_14 * ) V_11 ) -> V_24 ;
struct V_270 * V_271 = & ( (struct V_16 * ) V_11 ) -> V_27 ;
switch ( V_11 -> V_21 ) {
case V_22 :
return V_33 -> V_272 == F_153 ( V_273 ) ;
case V_26 :
return F_154 ( V_271 ) ;
default:
return true ;
}
}
static int F_155 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_21 ) {
case V_22 :
return F_15 ( ( (struct V_14 * ) V_11 ) -> V_25 ) ;
case V_26 :
return F_15 ( ( (struct V_16 * ) V_11 ) -> V_28 ) ;
}
return 0 ;
}
static void F_156 ( struct V_10 * V_11 , int V_274 )
{
switch ( V_11 -> V_21 ) {
case V_22 :
( (struct V_14 * ) V_11 ) -> V_25 = F_157 ( V_274 ) ;
break;
case V_26 :
( (struct V_16 * ) V_11 ) -> V_28 = F_157 ( V_274 ) ;
break;
}
}
static int F_158 ( const char * V_275 , T_1 V_85 , struct V_10 * V_11 ,
char V_276 , const char * * V_277 )
{
struct V_14 * V_15 = (struct V_14 * ) V_11 ;
struct V_16 * V_17 = (struct V_16 * ) V_11 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
if ( F_159 ( V_275 , V_85 , ( V_278 * ) & V_15 -> V_24 . V_272 , V_276 , V_277 ) ) {
V_11 -> V_21 = V_22 ;
return 0 ;
}
if ( F_160 ( V_275 , V_85 , ( V_278 * ) & V_17 -> V_27 . V_279 , V_276 , V_277 ) ) {
V_11 -> V_21 = V_26 ;
return 0 ;
}
return - V_251 ;
}
static int F_161 ( const char * V_280 , T_1 V_281 ,
struct V_10 * V_11 , char V_276 , const char * * V_277 )
{
const char * V_260 , * V_282 ;
char * V_283 , * V_284 = NULL ;
int V_285 , V_68 ;
V_282 = memchr ( V_280 , V_276 , V_281 ) ;
V_283 = memchr ( V_280 , ':' , V_281 ) ;
if ( V_282 && V_283 )
V_260 = V_282 < V_283 ? V_282 : V_283 ;
else if ( ! V_282 && V_283 )
V_260 = V_283 ;
else {
V_260 = V_282 ;
if ( ! V_260 )
V_260 = V_280 + V_281 ;
}
if ( V_260 <= V_280 )
return - V_251 ;
V_285 = F_162 ( NULL , V_280 , V_260 - V_280 , NULL , & V_284 , NULL ) ;
if ( V_285 > 0 )
V_68 = F_158 ( V_284 , V_285 , V_11 , - 1 , NULL ) ;
else
V_68 = - V_286 ;
F_163 ( V_284 ) ;
* V_277 = V_260 ;
F_164 ( L_48 , ( int ) ( V_260 - V_280 ) , V_280 ,
V_68 , V_68 ? L_49 : F_13 ( V_11 ) ) ;
return V_68 ;
}
static inline int F_161 ( const char * V_280 , T_1 V_281 ,
struct V_10 * V_11 , char V_276 , const char * * V_277 )
{
return - V_251 ;
}
static int F_165 ( const char * V_280 , T_1 V_281 ,
struct V_10 * V_11 , char V_276 , const char * * V_277 )
{
int V_68 ;
V_68 = F_158 ( V_280 , V_281 , V_11 , V_276 , V_277 ) ;
if ( V_68 )
V_68 = F_161 ( V_280 , V_281 , V_11 , V_276 , V_277 ) ;
return V_68 ;
}
int F_166 ( const char * V_287 , const char * V_260 ,
struct V_127 * V_33 ,
int V_288 , int * V_289 )
{
int V_12 , V_68 = - V_251 ;
const char * V_274 = V_287 ;
F_37 ( L_50 , ( int ) ( V_260 - V_287 ) , V_287 ) ;
for ( V_12 = 0 ; V_12 < V_288 ; V_12 ++ ) {
const char * V_277 ;
struct V_10 * V_11 = & V_33 [ V_12 ] . V_67 ;
int V_290 ;
char V_276 = ',' ;
if ( * V_274 == '[' ) {
V_276 = ']' ;
V_274 ++ ;
}
V_68 = F_165 ( V_274 , V_260 - V_274 , V_11 , V_276 , & V_277 ) ;
if ( V_68 )
goto V_291;
V_68 = - V_251 ;
V_274 = V_277 ;
if ( V_276 == ']' ) {
if ( * V_274 != ']' ) {
F_37 ( L_51 ) ;
goto V_291;
}
V_274 ++ ;
}
if ( V_274 < V_260 && * V_274 == ':' ) {
V_290 = 0 ;
V_274 ++ ;
while ( V_274 < V_260 && * V_274 >= '0' && * V_274 <= '9' ) {
V_290 = ( V_290 * 10 ) + ( * V_274 - '0' ) ;
V_274 ++ ;
}
if ( V_290 == 0 )
V_290 = V_292 ;
else if ( V_290 > 65535 )
goto V_291;
} else {
V_290 = V_292 ;
}
F_156 ( V_11 , V_290 ) ;
F_37 ( L_52 , F_13 ( V_11 ) ) ;
if ( V_274 == V_260 )
break;
if ( * V_274 != ',' )
goto V_291;
V_274 ++ ;
}
if ( V_274 != V_260 )
goto V_291;
if ( V_289 )
* V_289 = V_12 + 1 ;
return 0 ;
V_291:
F_29 ( L_53 , ( int ) ( V_260 - V_287 ) , V_287 ) ;
return V_68 ;
}
static int F_167 ( struct V_7 * V_8 )
{
F_37 ( L_54 , V_8 ) ;
if ( F_151 ( V_8 ) < 0 )
return - 1 ;
F_168 ( & V_8 -> V_265 ) ;
F_168 ( & V_8 -> V_266 ) ;
if ( memcmp ( & V_8 -> V_66 , & V_8 -> V_265 ,
sizeof( V_8 -> V_66 ) ) != 0 &&
! ( F_152 ( & V_8 -> V_265 . V_67 ) &&
V_8 -> V_265 . V_293 == V_8 -> V_66 . V_293 ) ) {
F_169 ( L_55 ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
( int ) F_123 ( V_8 -> V_66 . V_293 ) ,
F_13 ( & V_8 -> V_265 . V_67 ) ,
( int ) F_123 ( V_8 -> V_265 . V_293 ) ) ;
V_8 -> V_269 = L_56 ;
return - 1 ;
}
if ( F_152 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ) ) {
int V_290 = F_155 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ) ;
memcpy ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ,
& V_8 -> V_266 . V_67 ,
sizeof( V_8 -> V_266 . V_67 ) ) ;
F_156 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 , V_290 ) ;
F_16 ( V_8 -> V_30 ) ;
F_37 ( L_57 ,
F_13 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ) ) ;
}
return 0 ;
}
static int F_170 ( struct V_7 * V_8 )
{
V_166 V_294 = F_56 ( V_8 -> V_30 ) -> V_242 ;
V_166 V_295 = F_56 ( V_8 -> V_30 ) -> V_296 ;
V_166 V_297 = F_171 (
F_172 ( V_8 -> V_267 . V_241 ) ) ;
int V_68 ;
F_37 ( L_58 , V_8 , ( int ) V_8 -> V_254 ) ;
if ( V_8 -> V_229 ) {
V_68 = V_8 -> V_76 -> V_298 ( V_8 ) ;
if ( V_68 < 0 ) {
V_8 -> V_269 = L_59 ;
return V_68 ;
}
}
switch ( V_8 -> V_267 . V_268 ) {
case V_299 :
F_29 ( L_60
L_61 ,
F_173 ( V_8 -> V_129 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_294 , V_297 , V_297 & ~ V_294 ) ;
V_8 -> V_269 = L_62 ;
F_76 ( V_8 ) ;
return - 1 ;
case V_300 :
F_29 ( L_63
L_64 ,
F_173 ( V_8 -> V_129 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
F_123 ( V_8 -> V_224 . V_245 ) ,
F_123 ( V_8 -> V_267 . V_245 ) ) ;
V_8 -> V_269 = L_65 ;
F_76 ( V_8 ) ;
return - 1 ;
case V_301 :
V_8 -> V_228 ++ ;
F_37 ( L_66 , V_8 ,
V_8 -> V_228 ) ;
if ( V_8 -> V_228 == 2 ) {
V_8 -> V_269 = L_67 ;
return - 1 ;
}
F_91 ( V_8 ) ;
V_68 = F_135 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_142 ( V_8 ) ;
break;
case V_302 :
F_37 ( L_68 ,
F_123 ( V_8 -> V_267 . V_116 ) ) ;
F_29 ( L_69 ,
F_173 ( V_8 -> V_129 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ) ;
F_76 ( V_8 ) ;
F_91 ( V_8 ) ;
V_68 = F_135 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_142 ( V_8 ) ;
F_80 ( & V_8 -> V_122 ) ;
F_164 ( L_70 , F_173 ( V_8 -> V_129 ) ) ;
if ( V_8 -> V_76 -> V_303 )
V_8 -> V_76 -> V_303 ( V_8 ) ;
F_78 ( & V_8 -> V_122 ) ;
if ( V_8 -> V_56 != V_304 )
return - V_94 ;
break;
case V_305 :
F_37 ( L_71 ,
F_123 ( V_8 -> V_224 . V_116 ) ,
F_123 ( V_8 -> V_267 . V_116 ) ) ;
V_8 -> V_116 = F_123 ( V_8 -> V_267 . V_116 ) ;
F_91 ( V_8 ) ;
V_68 = F_135 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_142 ( V_8 ) ;
break;
case V_306 :
F_37 ( L_72 ,
V_8 -> V_124 ,
F_123 ( V_8 -> V_267 . V_138 ) ) ;
F_88 ( V_8 -> V_30 ,
F_123 ( V_8 -> V_267 . V_138 ) ) ;
F_91 ( V_8 ) ;
V_68 = F_135 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_142 ( V_8 ) ;
break;
case V_255 :
case V_256 :
if ( V_295 & ~ V_297 ) {
F_29 ( L_73
L_74 ,
F_173 ( V_8 -> V_129 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_295 , V_297 , V_295 & ~ V_297 ) ;
V_8 -> V_269 = L_62 ;
F_76 ( V_8 ) ;
return - 1 ;
}
F_35 ( V_8 -> V_56 != V_304 ) ;
V_8 -> V_56 = V_307 ;
V_8 -> V_228 = 0 ;
V_8 -> V_124 = F_123 ( V_8 -> V_267 . V_138 ) ;
V_8 -> V_116 ++ ;
V_8 -> V_182 = V_297 ;
F_37 ( L_75 ,
V_8 -> V_124 ,
F_123 ( V_8 -> V_267 . V_116 ) ,
V_8 -> V_116 ) ;
F_35 ( V_8 -> V_116 !=
F_123 ( V_8 -> V_267 . V_116 ) ) ;
if ( V_8 -> V_267 . V_9 & V_308 )
F_5 ( V_8 , V_2 ) ;
V_8 -> V_131 = 0 ;
if ( V_8 -> V_267 . V_268 == V_255 ) {
F_129 ( V_8 ) ;
F_144 ( V_8 ) ;
} else {
F_145 ( V_8 ) ;
}
break;
case V_309 :
V_8 -> V_269 = L_76 ;
return - 1 ;
default:
V_8 -> V_269 = L_77 ;
return - 1 ;
}
return 0 ;
}
static int F_174 ( struct V_7 * V_8 )
{
int V_105 = sizeof ( V_8 -> V_310 ) ;
int V_260 = V_105 ;
return F_148 ( V_8 , V_260 , V_105 , & V_8 -> V_310 ) ;
}
static void F_175 ( struct V_7 * V_8 )
{
struct V_35 * V_187 ;
V_166 V_311 = F_172 ( V_8 -> V_310 ) ;
V_166 V_201 ;
while ( ! F_74 ( & V_8 -> V_114 ) ) {
V_187 = F_75 ( & V_8 -> V_114 , struct V_35 ,
V_111 ) ;
V_201 = F_172 ( V_187 -> V_200 . V_201 ) ;
if ( V_201 > V_311 )
break;
F_37 ( L_78 , V_201 ,
F_124 ( V_187 -> V_200 . type ) , V_187 ) ;
V_187 -> V_312 = V_313 ;
F_70 ( V_187 ) ;
}
F_145 ( V_8 ) ;
}
static int F_176 ( struct V_7 * V_8 ,
struct V_86 * V_314 ,
unsigned int V_315 , T_4 * V_196 )
{
int V_68 , V_262 ;
F_3 ( ! V_314 ) ;
while ( V_314 -> V_107 < V_315 ) {
F_3 ( V_314 -> V_106 == NULL ) ;
V_262 = V_315 - V_314 -> V_107 ;
V_68 = F_58 ( V_8 -> V_50 , ( char * ) V_314 -> V_106 +
V_314 -> V_107 , V_262 ) ;
if ( V_68 <= 0 )
return V_68 ;
V_314 -> V_107 += V_68 ;
}
if ( V_314 -> V_107 == V_315 )
* V_196 = F_125 ( 0 , V_314 -> V_106 , V_314 -> V_107 ) ;
return 1 ;
}
static int F_177 ( struct V_7 * V_8 )
{
struct V_35 * V_89 = V_8 -> V_115 ;
struct V_147 * V_148 = & V_89 -> V_148 ;
bool V_249 = ! F_55 ( F_56 ( V_8 -> V_30 ) , V_250 ) ;
struct V_95 * V_95 ;
T_1 V_96 ;
T_1 V_97 ;
T_4 V_196 = 0 ;
int V_68 ;
F_3 ( ! V_89 ) ;
if ( F_74 ( & V_89 -> V_143 ) )
return - V_316 ;
if ( V_249 )
V_196 = V_8 -> V_259 ;
while ( V_148 -> V_151 ) {
V_95 = F_114 ( V_148 , & V_96 , & V_97 , NULL ) ;
V_68 = F_60 ( V_8 -> V_50 , V_95 , V_96 , V_97 ) ;
if ( V_68 <= 0 ) {
if ( V_249 )
V_8 -> V_259 = V_196 ;
return V_68 ;
}
if ( V_249 )
V_196 = F_138 ( V_196 , V_95 , V_96 , V_68 ) ;
( void ) F_115 ( V_148 , ( T_1 ) V_68 ) ;
}
if ( V_249 )
V_8 -> V_259 = V_196 ;
return 1 ;
}
static int F_178 ( struct V_7 * V_8 )
{
struct V_35 * V_187 = V_8 -> V_115 ;
int V_105 ;
int V_260 ;
int V_68 ;
unsigned int V_202 , V_203 , V_186 ;
bool V_249 = ! F_55 ( F_56 ( V_8 -> V_30 ) , V_250 ) ;
bool V_317 = ( V_8 -> V_182 & V_183 ) ;
V_166 V_201 ;
T_4 V_196 ;
F_37 ( L_79 , V_8 , V_187 ) ;
V_105 = sizeof ( V_8 -> V_318 ) ;
V_260 = V_105 ;
V_68 = F_148 ( V_8 , V_260 , V_105 , & V_8 -> V_318 ) ;
if ( V_68 <= 0 )
return V_68 ;
V_196 = F_125 ( 0 , & V_8 -> V_318 , F_126 ( struct V_209 , V_196 ) ) ;
if ( F_127 ( V_196 ) != V_8 -> V_318 . V_196 ) {
F_29 ( L_80 ,
V_196 , V_8 -> V_318 . V_196 ) ;
return - V_319 ;
}
V_202 = F_123 ( V_8 -> V_318 . V_202 ) ;
if ( V_202 > V_320 )
return - V_316 ;
V_203 = F_123 ( V_8 -> V_318 . V_203 ) ;
if ( V_203 > V_321 )
return - V_316 ;
V_186 = F_123 ( V_8 -> V_318 . V_186 ) ;
if ( V_186 > V_322 )
return - V_316 ;
V_201 = F_172 ( V_8 -> V_318 . V_201 ) ;
if ( ( V_323 ) V_201 - ( V_323 ) V_8 -> V_119 < 1 ) {
F_164 ( L_81 ,
F_173 ( V_8 -> V_129 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_201 , V_8 -> V_119 + 1 ) ;
V_8 -> V_253 = - V_202 - V_203 - V_186 -
F_117 ( V_8 ) ;
V_8 -> V_254 = V_256 ;
return 1 ;
} else if ( ( V_323 ) V_201 - ( V_323 ) V_8 -> V_119 > 1 ) {
F_29 ( L_82 ,
V_201 , V_8 -> V_119 + 1 ) ;
V_8 -> V_269 = L_83 ;
return - V_324 ;
}
if ( ! V_8 -> V_115 ) {
int V_146 = 0 ;
F_37 ( L_84 , V_8 -> V_318 . type ,
V_202 , V_186 ) ;
V_68 = F_179 ( V_8 , & V_146 ) ;
if ( V_68 < 0 )
return V_68 ;
F_3 ( ! V_8 -> V_115 ^ V_146 ) ;
if ( V_146 ) {
F_37 ( L_85 ) ;
V_8 -> V_253 = - V_202 - V_203 - V_186 -
F_117 ( V_8 ) ;
V_8 -> V_254 = V_256 ;
V_8 -> V_119 ++ ;
return 1 ;
}
F_3 ( ! V_8 -> V_115 ) ;
F_3 ( V_8 -> V_115 -> V_8 != V_8 ) ;
V_187 = V_8 -> V_115 ;
V_187 -> V_204 . V_107 = 0 ;
if ( V_187 -> V_207 )
V_187 -> V_207 -> V_208 . V_107 = 0 ;
if ( V_186 )
F_118 ( V_8 -> V_115 , V_186 ) ;
}
V_68 = F_176 ( V_8 , & V_187 -> V_204 , V_202 ,
& V_8 -> V_257 ) ;
if ( V_68 <= 0 )
return V_68 ;
if ( V_187 -> V_207 ) {
V_68 = F_176 ( V_8 , & V_187 -> V_207 -> V_208 ,
V_203 ,
& V_8 -> V_258 ) ;
if ( V_68 <= 0 )
return V_68 ;
}
if ( V_186 ) {
V_68 = F_177 ( V_8 ) ;
if ( V_68 <= 0 )
return V_68 ;
}
V_105 = F_117 ( V_8 ) ;
V_260 += V_105 ;
V_68 = F_148 ( V_8 , V_260 , V_105 , & V_187 -> V_188 ) ;
if ( V_68 <= 0 )
return V_68 ;
if ( ! V_317 ) {
V_187 -> V_188 . V_9 = V_187 -> V_192 . V_9 ;
V_187 -> V_188 . V_191 = 0 ;
}
F_37 ( L_86 ,
V_187 , V_202 , V_187 -> V_188 . V_210 , V_203 ,
V_187 -> V_188 . V_211 , V_186 , V_187 -> V_188 . V_212 ) ;
if ( V_8 -> V_257 != F_123 ( V_187 -> V_188 . V_210 ) ) {
F_29 ( L_87 ,
V_187 , V_8 -> V_257 , V_187 -> V_188 . V_210 ) ;
return - V_319 ;
}
if ( V_8 -> V_258 != F_123 ( V_187 -> V_188 . V_211 ) ) {
F_29 ( L_88 ,
V_187 , V_8 -> V_258 , V_187 -> V_188 . V_211 ) ;
return - V_319 ;
}
if ( V_249 &&
( V_187 -> V_188 . V_9 & V_252 ) == 0 &&
V_8 -> V_259 != F_123 ( V_187 -> V_188 . V_212 ) ) {
F_29 ( L_89 , V_187 ,
V_8 -> V_259 , F_123 ( V_187 -> V_188 . V_212 ) ) ;
return - V_319 ;
}
if ( V_317 && V_8 -> V_76 -> V_325 &&
V_8 -> V_76 -> V_325 ( V_187 ) ) {
F_29 ( L_90 , V_187 ) ;
return - V_319 ;
}
return 1 ;
}
static void F_180 ( struct V_7 * V_8 )
{
struct V_35 * V_89 = V_8 -> V_115 ;
F_3 ( V_8 -> V_115 -> V_8 != V_8 ) ;
V_8 -> V_115 = NULL ;
if ( V_8 -> V_129 . type == 0 )
V_8 -> V_129 = V_89 -> V_200 . V_326 ;
V_8 -> V_119 ++ ;
F_80 ( & V_8 -> V_122 ) ;
F_37 ( L_91 ,
V_89 , F_172 ( V_89 -> V_200 . V_201 ) ,
F_173 ( V_89 -> V_200 . V_326 ) ,
F_124 ( V_89 -> V_200 . type ) ,
F_181 ( F_124 ( V_89 -> V_200 . type ) ) ,
F_123 ( V_89 -> V_200 . V_202 ) ,
F_123 ( V_89 -> V_200 . V_186 ) ,
V_8 -> V_257 , V_8 -> V_258 , V_8 -> V_259 ) ;
V_8 -> V_76 -> V_327 ( V_8 , V_89 ) ;
F_78 ( & V_8 -> V_122 ) ;
}
static int F_182 ( struct V_7 * V_8 )
{
struct V_328 V_329 ;
T_1 V_105 = sizeof( V_329 ) ;
int V_68 = F_148 ( V_8 , V_105 , V_105 , & V_329 ) ;
if ( V_68 <= 0 )
return V_68 ;
F_183 ( & V_8 -> V_330 , & V_329 ) ;
F_145 ( V_8 ) ;
return 1 ;
}
static int F_184 ( struct V_7 * V_8 )
{
int V_68 = 1 ;
F_37 ( L_92 , V_8 , V_8 -> V_56 ) ;
V_101:
F_37 ( L_93 , V_8 -> V_140 ) ;
if ( V_8 -> V_56 == V_128 ) {
F_3 ( V_8 -> V_50 ) ;
V_8 -> V_56 = V_331 ;
F_91 ( V_8 ) ;
F_134 ( V_8 ) ;
F_141 ( V_8 ) ;
F_3 ( V_8 -> V_115 ) ;
V_8 -> V_254 = V_256 ;
F_37 ( L_94 ,
V_8 , V_8 -> V_56 ) ;
V_68 = F_49 ( V_8 ) ;
if ( V_68 < 0 ) {
V_8 -> V_269 = L_95 ;
goto V_248;
}
}
V_332:
if ( V_8 -> V_139 ) {
V_68 = F_137 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_248;
}
if ( V_8 -> V_121 ) {
V_68 = F_140 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_248;
}
if ( V_8 -> V_118 ) {
if ( V_8 -> V_195 ) {
F_72 ( V_8 -> V_118 ) ;
V_8 -> V_118 = NULL ;
goto V_333;
}
V_68 = F_139 ( V_8 ) ;
if ( V_68 == 1 )
goto V_332;
if ( V_68 == 0 )
goto V_248;
if ( V_68 < 0 ) {
F_37 ( L_96 ,
V_68 ) ;
goto V_248;
}
}
V_333:
if ( V_8 -> V_56 == V_307 ) {
if ( F_9 ( V_8 , V_3 ) ) {
F_130 ( V_8 ) ;
goto V_101;
}
if ( ! F_74 ( & V_8 -> V_113 ) ) {
F_120 ( V_8 ) ;
goto V_101;
}
if ( V_8 -> V_119 > V_8 -> V_120 ) {
F_128 ( V_8 ) ;
goto V_101;
}
}
F_2 ( V_8 , V_4 ) ;
F_37 ( L_97 ) ;
V_68 = 0 ;
V_248:
F_37 ( L_98 , V_8 , V_68 ) ;
return V_68 ;
}
static int F_185 ( struct V_7 * V_8 )
{
int V_68 = - 1 ;
V_101:
F_37 ( L_99 , V_8 , V_8 -> V_56 ) ;
if ( V_8 -> V_56 != V_331 &&
V_8 -> V_56 != V_304 &&
V_8 -> V_56 != V_307 )
return 0 ;
F_3 ( ! V_8 -> V_50 ) ;
F_37 ( L_100 , ( int ) V_8 -> V_254 ,
V_8 -> V_253 ) ;
if ( V_8 -> V_56 == V_331 ) {
F_37 ( L_101 ) ;
V_68 = F_149 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_248;
V_68 = F_167 ( V_8 ) ;
if ( V_68 < 0 )
goto V_248;
V_8 -> V_56 = V_304 ;
V_68 = F_135 ( V_8 ) ;
if ( V_68 < 0 )
goto V_248;
F_142 ( V_8 ) ;
goto V_248;
}
if ( V_8 -> V_56 == V_304 ) {
F_37 ( L_102 ) ;
V_68 = F_150 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_248;
V_68 = F_170 ( V_8 ) ;
if ( V_68 < 0 )
goto V_248;
goto V_101;
}
F_35 ( V_8 -> V_56 != V_307 ) ;
if ( V_8 -> V_253 < 0 ) {
static char V_84 [ V_334 ] ;
int V_146 = F_96 ( ( int ) sizeof ( V_84 ) , - V_8 -> V_253 ) ;
F_37 ( L_103 , V_146 , - V_8 -> V_253 ) ;
V_68 = F_58 ( V_8 -> V_50 , V_84 , V_146 ) ;
if ( V_68 <= 0 )
goto V_248;
V_8 -> V_253 += V_68 ;
if ( V_8 -> V_253 )
goto V_101;
}
if ( V_8 -> V_254 == V_256 ) {
V_68 = F_58 ( V_8 -> V_50 , & V_8 -> V_254 , 1 ) ;
if ( V_68 <= 0 )
goto V_248;
F_37 ( L_104 , ( int ) V_8 -> V_254 ) ;
switch ( V_8 -> V_254 ) {
case V_335 :
F_147 ( V_8 ) ;
break;
case V_336 :
F_143 ( V_8 ) ;
break;
case V_337 :
F_146 ( V_8 ) ;
break;
case V_338 :
F_69 ( V_8 ) ;
V_8 -> V_56 = V_123 ;
goto V_248;
default:
goto V_339;
}
}
if ( V_8 -> V_254 == V_335 ) {
V_68 = F_178 ( V_8 ) ;
if ( V_68 <= 0 ) {
switch ( V_68 ) {
case - V_319 :
V_8 -> V_269 = L_105 ;
case - V_324 :
V_68 = - V_316 ;
break;
case - V_316 :
V_8 -> V_269 = L_106 ;
break;
}
goto V_248;
}
if ( V_8 -> V_254 == V_256 )
goto V_101;
F_180 ( V_8 ) ;
if ( V_8 -> V_56 == V_307 )
F_145 ( V_8 ) ;
goto V_101;
}
if ( V_8 -> V_254 == V_336 ||
V_8 -> V_254 == V_255 ) {
V_68 = F_174 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_248;
F_175 ( V_8 ) ;
goto V_101;
}
if ( V_8 -> V_254 == V_337 ) {
V_68 = F_182 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_248;
goto V_101;
}
V_248:
F_37 ( L_107 , V_8 , V_68 ) ;
return V_68 ;
V_339:
F_29 ( L_108 , ( int ) V_8 -> V_254 ) ;
V_8 -> V_269 = L_109 ;
V_68 = - 1 ;
goto V_248;
}
static int F_186 ( struct V_7 * V_8 , unsigned long V_131 )
{
if ( ! V_8 -> V_76 -> V_340 ( V_8 ) ) {
F_37 ( L_110 , V_46 , V_8 ) ;
return - V_341 ;
}
if ( ! F_187 ( V_39 , & V_8 -> V_134 , V_131 ) ) {
F_37 ( L_111 , V_46 , V_8 ) ;
V_8 -> V_76 -> V_342 ( V_8 ) ;
return - V_343 ;
}
F_37 ( L_112 , V_46 , V_8 , V_131 ) ;
return 0 ;
}
static void F_44 ( struct V_7 * V_8 )
{
( void ) F_186 ( V_8 , 0 ) ;
}
static void F_79 ( struct V_7 * V_8 )
{
if ( F_188 ( & V_8 -> V_134 ) ) {
F_37 ( L_113 , V_46 , V_8 ) ;
V_8 -> V_76 -> V_342 ( V_8 ) ;
}
}
static bool F_189 ( struct V_7 * V_8 )
{
if ( ! F_9 ( V_8 , V_5 ) )
return false ;
#define CASE ( T_5 ) \
case CON_STATE_ ## x: \
con->error_msg = "socket closed (con state " #x ")"; \
break;
switch ( V_8 -> V_56 ) {
CASE ( V_344 ) ;
CASE ( V_345 ) ;
CASE ( V_346 ) ;
CASE ( V_347 ) ;
CASE ( V_348 ) ;
CASE ( V_349 ) ;
default:
F_169 ( L_114 ,
V_46 , V_8 , V_8 -> V_56 ) ;
V_8 -> V_269 = L_115 ;
F_116 () ;
break;
}
#undef CASE
return true ;
}
static bool F_190 ( struct V_7 * V_8 )
{
int V_68 ;
if ( ! F_9 ( V_8 , V_6 ) )
return false ;
V_68 = F_186 ( V_8 , F_191 ( V_8 -> V_131 ) ) ;
if ( V_68 ) {
F_37 ( L_116 , V_46 ,
V_8 , V_8 -> V_131 ) ;
F_3 ( V_68 == - V_341 ) ;
F_5 ( V_8 , V_6 ) ;
}
return true ;
}
static void F_192 ( struct V_7 * V_8 )
{
F_37 ( L_113 , V_46 , V_8 ) ;
if ( V_8 -> V_228 ) {
F_37 ( L_117 , V_8 -> V_228 ) ;
if ( V_8 -> V_76 -> V_350 )
V_8 -> V_76 -> V_350 ( V_8 ) ;
V_8 -> V_228 = 0 ;
}
if ( V_8 -> V_76 -> V_351 )
V_8 -> V_76 -> V_351 ( V_8 ) ;
}
static void V_135 ( struct V_352 * V_134 )
{
struct V_7 * V_8 = F_193 ( V_134 , struct V_7 ,
V_134 . V_134 ) ;
bool V_351 ;
F_78 ( & V_8 -> V_122 ) ;
while ( true ) {
int V_68 ;
if ( ( V_351 = F_189 ( V_8 ) ) ) {
F_37 ( L_118 , V_46 , V_8 ) ;
break;
}
if ( F_190 ( V_8 ) ) {
F_37 ( L_119 , V_46 , V_8 ) ;
break;
}
if ( V_8 -> V_56 == V_353 ) {
F_37 ( L_120 , V_46 , V_8 ) ;
break;
}
if ( V_8 -> V_56 == V_123 ) {
F_37 ( L_121 , V_46 , V_8 ) ;
F_3 ( V_8 -> V_50 ) ;
break;
}
if ( V_8 -> V_56 == V_128 ) {
F_37 ( L_122 , V_46 , V_8 ) ;
F_3 ( V_8 -> V_50 ) ;
}
V_68 = F_185 ( V_8 ) ;
if ( V_68 < 0 ) {
if ( V_68 == - V_94 )
continue;
if ( ! V_8 -> V_269 )
V_8 -> V_269 = L_123 ;
V_351 = true ;
break;
}
V_68 = F_184 ( V_8 ) ;
if ( V_68 < 0 ) {
if ( V_68 == - V_94 )
continue;
if ( ! V_8 -> V_269 )
V_8 -> V_269 = L_124 ;
V_351 = true ;
}
break;
}
if ( V_351 )
F_194 ( V_8 ) ;
F_80 ( & V_8 -> V_122 ) ;
if ( V_351 )
F_192 ( V_8 ) ;
V_8 -> V_76 -> V_342 ( V_8 ) ;
}
static void F_194 ( struct V_7 * V_8 )
{
F_37 ( L_125 ,
V_8 , V_8 -> V_56 , F_13 ( & V_8 -> V_66 . V_67 ) ) ;
F_169 ( L_126 , F_173 ( V_8 -> V_129 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) , V_8 -> V_269 ) ;
V_8 -> V_269 = NULL ;
F_35 ( V_8 -> V_56 != V_331 &&
V_8 -> V_56 != V_304 &&
V_8 -> V_56 != V_307 ) ;
F_69 ( V_8 ) ;
if ( F_7 ( V_8 , V_2 ) ) {
F_37 ( L_127 ) ;
V_8 -> V_56 = V_123 ;
return;
}
if ( V_8 -> V_115 ) {
F_3 ( V_8 -> V_115 -> V_8 != V_8 ) ;
F_72 ( V_8 -> V_115 ) ;
V_8 -> V_115 = NULL ;
}
F_195 ( & V_8 -> V_114 , & V_8 -> V_113 ) ;
if ( F_74 ( & V_8 -> V_113 ) &&
! F_7 ( V_8 , V_3 ) ) {
F_37 ( L_128 , V_8 ) ;
F_2 ( V_8 , V_4 ) ;
V_8 -> V_56 = V_353 ;
} else {
V_8 -> V_56 = V_128 ;
if ( V_8 -> V_131 == 0 )
V_8 -> V_131 = V_354 ;
else if ( V_8 -> V_131 < V_355 )
V_8 -> V_131 *= 2 ;
F_5 ( V_8 , V_6 ) ;
F_44 ( V_8 ) ;
}
}
void F_196 ( struct V_29 * V_30 ,
struct V_127 * V_356 )
{
F_197 ( & V_30 -> V_137 ) ;
if ( V_356 )
V_30 -> V_32 . V_33 = * V_356 ;
V_30 -> V_32 . V_33 . type = 0 ;
F_198 ( & V_30 -> V_32 . V_33 . V_293 , sizeof( V_30 -> V_32 . V_33 . V_293 ) ) ;
F_16 ( V_30 ) ;
F_199 ( & V_30 -> V_53 , 0 ) ;
F_200 ( & V_30 -> V_69 , F_201 ( V_357 -> V_358 -> V_359 ) ) ;
F_37 ( L_113 , V_46 , V_30 ) ;
}
void F_202 ( struct V_29 * V_30 )
{
F_203 ( F_51 ( & V_30 -> V_69 ) ) ;
}
static void F_204 ( struct V_35 * V_89 , struct V_7 * V_8 )
{
if ( V_89 -> V_8 )
V_89 -> V_8 -> V_76 -> V_342 ( V_89 -> V_8 ) ;
V_89 -> V_8 = V_8 ? V_8 -> V_76 -> V_340 ( V_8 ) : NULL ;
F_3 ( V_89 -> V_8 != V_8 ) ;
}
static void F_205 ( struct V_7 * V_8 )
{
if ( V_8 -> V_56 == V_353 ) {
F_37 ( L_129 , V_8 ) ;
V_8 -> V_56 = V_128 ;
V_8 -> V_116 ++ ;
F_35 ( F_7 ( V_8 , V_4 ) ) ;
F_35 ( F_7 ( V_8 , V_3 ) ) ;
}
}
void F_206 ( struct V_7 * V_8 , struct V_35 * V_89 )
{
V_89 -> V_200 . V_326 = V_8 -> V_30 -> V_32 . V_280 ;
F_3 ( V_89 -> V_204 . V_107 != F_123 ( V_89 -> V_200 . V_202 ) ) ;
V_89 -> V_199 = true ;
F_78 ( & V_8 -> V_122 ) ;
if ( V_8 -> V_56 == V_123 ) {
F_37 ( L_130 , V_8 , V_89 ) ;
F_72 ( V_89 ) ;
F_80 ( & V_8 -> V_122 ) ;
return;
}
F_204 ( V_89 , V_8 ) ;
F_3 ( ! F_74 ( & V_89 -> V_111 ) ) ;
F_207 ( & V_89 -> V_111 , & V_8 -> V_113 ) ;
F_37 ( L_131 , V_89 ,
F_173 ( V_8 -> V_129 ) , F_124 ( V_89 -> V_200 . type ) ,
F_181 ( F_124 ( V_89 -> V_200 . type ) ) ,
F_123 ( V_89 -> V_200 . V_202 ) ,
F_123 ( V_89 -> V_200 . V_203 ) ,
F_123 ( V_89 -> V_200 . V_186 ) ) ;
F_205 ( V_8 ) ;
F_80 ( & V_8 -> V_122 ) ;
if ( F_11 ( V_8 , V_4 ) == 0 )
F_44 ( V_8 ) ;
}
void F_208 ( struct V_35 * V_89 )
{
struct V_7 * V_8 = V_89 -> V_8 ;
if ( ! V_8 ) {
F_37 ( L_132 , V_46 , V_89 ) ;
return;
}
F_78 ( & V_8 -> V_122 ) ;
if ( ! F_74 ( & V_89 -> V_111 ) ) {
F_37 ( L_133 , V_46 , V_8 , V_89 ) ;
F_71 ( & V_89 -> V_111 ) ;
V_89 -> V_200 . V_201 = 0 ;
F_72 ( V_89 ) ;
}
if ( V_8 -> V_118 == V_89 ) {
F_3 ( V_8 -> V_121 ) ;
if ( V_8 -> V_195 ) {
V_8 -> V_121 += F_94 ( V_8 ) ;
} else {
F_3 ( ! V_89 -> V_178 ) ;
V_8 -> V_121 += F_117 ( V_8 ) ;
}
if ( V_89 -> V_178 )
V_8 -> V_121 += V_89 -> V_148 . V_175 ;
if ( V_89 -> V_207 )
V_8 -> V_121 += F_94 ( V_8 ) ;
V_8 -> V_121 += F_94 ( V_8 ) ;
F_37 ( L_134 ,
V_46 , V_8 , V_89 , V_8 -> V_140 , V_8 -> V_121 ) ;
V_89 -> V_200 . V_201 = 0 ;
V_8 -> V_118 = NULL ;
F_72 ( V_89 ) ;
}
F_80 ( & V_8 -> V_122 ) ;
}
void F_209 ( struct V_35 * V_89 )
{
struct V_7 * V_8 = V_89 -> V_8 ;
if ( ! V_8 ) {
F_37 ( L_132 , V_46 , V_89 ) ;
return;
}
F_78 ( & V_8 -> V_122 ) ;
if ( V_8 -> V_115 == V_89 ) {
unsigned int V_202 = F_123 ( V_8 -> V_318 . V_202 ) ;
unsigned int V_203 = F_123 ( V_8 -> V_318 . V_203 ) ;
unsigned int V_186 = F_123 ( V_8 -> V_318 . V_186 ) ;
F_37 ( L_135 , V_46 , V_8 , V_89 ) ;
V_8 -> V_253 = V_8 -> V_253 -
sizeof( struct V_209 ) -
V_202 -
V_203 -
V_186 -
sizeof( struct V_184 ) ;
F_72 ( V_8 -> V_115 ) ;
V_8 -> V_115 = NULL ;
V_8 -> V_254 = V_256 ;
V_8 -> V_119 ++ ;
} else {
F_37 ( L_136 ,
V_46 , V_8 , V_8 -> V_115 , V_89 ) ;
}
F_80 ( & V_8 -> V_122 ) ;
}
void F_210 ( struct V_7 * V_8 )
{
F_37 ( L_137 , V_8 ) ;
F_78 ( & V_8 -> V_122 ) ;
F_205 ( V_8 ) ;
F_80 ( & V_8 -> V_122 ) ;
if ( F_11 ( V_8 , V_3 ) == 0 &&
F_11 ( V_8 , V_4 ) == 0 )
F_44 ( V_8 ) ;
}
bool F_211 ( struct V_7 * V_8 ,
unsigned long V_360 )
{
if ( V_360 > 0 &&
( V_8 -> V_182 & V_213 ) ) {
struct V_214 V_215 = V_216 ;
struct V_214 V_361 ;
F_212 ( V_360 , & V_361 ) ;
V_361 = F_213 ( V_8 -> V_330 , V_361 ) ;
return F_214 ( & V_215 , & V_361 ) >= 0 ;
}
return false ;
}
static struct V_38 * F_215 ( enum V_362 type )
{
struct V_38 * V_143 ;
if ( F_35 ( ! F_216 ( type ) ) )
return NULL ;
V_143 = F_217 ( V_37 , V_73 ) ;
if ( V_143 )
V_143 -> type = type ;
F_86 ( & V_143 -> V_180 ) ;
return V_143 ;
}
static void F_218 ( struct V_38 * V_143 )
{
if ( ! V_143 )
return;
F_35 ( ! F_74 ( & V_143 -> V_180 ) ) ;
if ( V_143 -> type == V_173 )
F_219 ( V_143 -> V_172 ) ;
F_220 ( V_37 , V_143 ) ;
}
void F_221 ( struct V_35 * V_89 , struct V_95 * * V_164 ,
T_1 V_97 , T_1 V_165 )
{
struct V_38 * V_143 ;
F_3 ( ! V_164 ) ;
F_3 ( ! V_97 ) ;
V_143 = F_215 ( V_163 ) ;
F_3 ( ! V_143 ) ;
V_143 -> V_164 = V_164 ;
V_143 -> V_97 = V_97 ;
V_143 -> V_165 = V_165 & ~ V_167 ;
F_207 ( & V_143 -> V_180 , & V_89 -> V_143 ) ;
V_89 -> V_178 += V_97 ;
}
void F_222 ( struct V_35 * V_89 ,
struct V_171 * V_172 )
{
struct V_38 * V_143 ;
F_3 ( ! V_172 ) ;
F_3 ( ! V_172 -> V_97 ) ;
V_143 = F_215 ( V_173 ) ;
F_3 ( ! V_143 ) ;
V_143 -> V_172 = V_172 ;
F_207 ( & V_143 -> V_180 , & V_89 -> V_143 ) ;
V_89 -> V_178 += V_172 -> V_97 ;
}
void F_223 ( struct V_35 * V_89 , struct V_149 * V_149 ,
T_1 V_97 )
{
struct V_38 * V_143 ;
F_3 ( ! V_149 ) ;
V_143 = F_215 ( V_150 ) ;
F_3 ( ! V_143 ) ;
V_143 -> V_149 = V_149 ;
V_143 -> V_152 = V_97 ;
F_207 ( & V_143 -> V_180 , & V_89 -> V_143 ) ;
V_89 -> V_178 += V_97 ;
}
struct V_35 * F_224 ( int type , int V_202 , T_6 V_9 ,
bool V_363 )
{
struct V_35 * V_187 ;
V_187 = F_217 ( V_34 , V_9 ) ;
if ( V_187 == NULL )
goto V_248;
V_187 -> V_200 . type = F_225 ( type ) ;
V_187 -> V_200 . V_364 = F_225 ( V_365 ) ;
V_187 -> V_200 . V_202 = F_127 ( V_202 ) ;
F_86 ( & V_187 -> V_111 ) ;
F_226 ( & V_187 -> V_366 ) ;
F_86 ( & V_187 -> V_143 ) ;
if ( V_202 ) {
V_187 -> V_204 . V_106 = F_227 ( V_202 , V_9 ) ;
if ( V_187 -> V_204 . V_106 == NULL ) {
F_37 ( L_138 ,
V_202 ) ;
goto V_367;
}
} else {
V_187 -> V_204 . V_106 = NULL ;
}
V_187 -> V_368 = V_187 -> V_204 . V_107 = V_202 ;
F_37 ( L_139 , V_187 , V_202 ) ;
return V_187 ;
V_367:
F_72 ( V_187 ) ;
V_248:
if ( ! V_363 ) {
F_29 ( L_140 , type ,
V_202 ) ;
F_35 ( 1 ) ;
} else {
F_37 ( L_140 , type ,
V_202 ) ;
}
return NULL ;
}
static int F_228 ( struct V_7 * V_8 , struct V_35 * V_89 )
{
int type = F_124 ( V_89 -> V_200 . type ) ;
int V_203 = F_123 ( V_89 -> V_200 . V_203 ) ;
F_37 ( L_141 , V_89 , type ,
F_181 ( type ) , V_203 ) ;
F_3 ( ! V_203 ) ;
F_3 ( V_89 -> V_207 ) ;
V_89 -> V_207 = F_229 ( V_203 , V_73 ) ;
if ( ! V_89 -> V_207 )
return - V_36 ;
return 0 ;
}
static int F_179 ( struct V_7 * V_8 , int * V_146 )
{
struct V_209 * V_200 = & V_8 -> V_318 ;
int V_203 = F_123 ( V_200 -> V_203 ) ;
struct V_35 * V_89 ;
int V_68 = 0 ;
F_3 ( V_8 -> V_115 != NULL ) ;
F_3 ( ! V_8 -> V_76 -> V_369 ) ;
F_80 ( & V_8 -> V_122 ) ;
V_89 = V_8 -> V_76 -> V_369 ( V_8 , V_200 , V_146 ) ;
F_78 ( & V_8 -> V_122 ) ;
if ( V_8 -> V_56 != V_307 ) {
if ( V_89 )
F_72 ( V_89 ) ;
return - V_94 ;
}
if ( V_89 ) {
F_3 ( * V_146 ) ;
F_204 ( V_89 , V_8 ) ;
V_8 -> V_115 = V_89 ;
} else {
if ( * V_146 )
return 0 ;
V_8 -> V_269 = L_142 ;
return - V_36 ;
}
memcpy ( & V_8 -> V_115 -> V_200 , & V_8 -> V_318 , sizeof( V_8 -> V_318 ) ) ;
if ( V_203 && ! V_8 -> V_115 -> V_207 ) {
V_68 = F_228 ( V_8 , V_8 -> V_115 ) ;
if ( V_68 < 0 ) {
F_72 ( V_8 -> V_115 ) ;
V_8 -> V_115 = NULL ;
}
}
return V_68 ;
}
static void F_230 ( struct V_35 * V_187 )
{
F_37 ( L_113 , V_46 , V_187 ) ;
F_231 ( V_187 -> V_204 . V_106 ) ;
F_220 ( V_34 , V_187 ) ;
}
static void F_232 ( struct V_366 * V_366 )
{
struct V_35 * V_187 = F_193 ( V_366 , struct V_35 , V_366 ) ;
struct V_38 * V_143 , * V_370 ;
F_37 ( L_113 , V_46 , V_187 ) ;
F_35 ( ! F_74 ( & V_187 -> V_111 ) ) ;
F_204 ( V_187 , NULL ) ;
if ( V_187 -> V_207 ) {
F_233 ( V_187 -> V_207 ) ;
V_187 -> V_207 = NULL ;
}
F_234 (data, next, &m->data, links) {
F_71 ( & V_143 -> V_180 ) ;
F_218 ( V_143 ) ;
}
V_187 -> V_178 = 0 ;
if ( V_187 -> V_371 )
F_235 ( V_187 -> V_371 , V_187 ) ;
else
F_230 ( V_187 ) ;
}
struct V_35 * F_121 ( struct V_35 * V_89 )
{
F_37 ( L_143 , V_46 , V_89 ,
F_43 ( & V_89 -> V_366 . V_372 ) ) ;
F_236 ( & V_89 -> V_366 ) ;
return V_89 ;
}
void F_72 ( struct V_35 * V_89 )
{
F_37 ( L_143 , V_46 , V_89 ,
F_43 ( & V_89 -> V_366 . V_372 ) ) ;
F_237 ( & V_89 -> V_366 , F_232 ) ;
}
void F_238 ( struct V_35 * V_89 )
{
F_239 ( L_144 , V_89 ,
V_89 -> V_368 , V_89 -> V_178 ) ;
F_240 ( V_373 , L_145 ,
V_374 , 16 , 1 ,
& V_89 -> V_200 , sizeof( V_89 -> V_200 ) , true ) ;
F_240 ( V_373 , L_146 ,
V_374 , 16 , 1 ,
V_89 -> V_204 . V_106 , V_89 -> V_204 . V_107 , true ) ;
if ( V_89 -> V_207 )
F_240 ( V_373 , L_147 ,
V_374 , 16 , 1 ,
V_89 -> V_207 -> V_208 . V_106 ,
V_89 -> V_207 -> V_208 . V_107 , true ) ;
F_240 ( V_373 , L_148 ,
V_374 , 16 , 1 ,
& V_89 -> V_188 , sizeof( V_89 -> V_188 ) , true ) ;
}
