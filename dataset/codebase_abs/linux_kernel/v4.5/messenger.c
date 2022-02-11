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
F_3 ( V_40 == NULL ) ;
F_25 ( V_40 ) ;
V_40 = NULL ;
F_22 () ;
}
int F_26 ( void )
{
if ( F_18 () )
return - V_36 ;
F_3 ( V_40 != NULL ) ;
V_40 = F_27 ( 0 ) ;
F_28 ( V_40 ) ;
V_39 = F_29 ( L_6 , V_41 , 0 ) ;
if ( V_39 )
return 0 ;
F_30 ( L_7 ) ;
F_23 () ;
return - V_36 ;
}
void F_31 ( void )
{
F_3 ( V_39 == NULL ) ;
F_23 () ;
}
void F_32 ( void )
{
F_33 ( V_39 ) ;
}
static void F_34 ( struct V_7 * V_8 )
{
int V_42 ;
V_42 = F_35 ( & V_8 -> V_43 , V_44 ) ;
if ( F_36 ( V_42 != V_45 ) )
F_37 ( L_8 , V_46 , V_42 ) ;
F_38 ( L_9 , V_46 , V_8 , V_42 ,
V_44 ) ;
}
static void F_39 ( struct V_7 * V_8 )
{
int V_42 ;
V_42 = F_35 ( & V_8 -> V_43 , V_47 ) ;
if ( F_36 ( V_42 != V_44 ) )
F_37 ( L_8 , V_46 , V_42 ) ;
F_38 ( L_9 , V_46 , V_8 , V_42 ,
V_47 ) ;
}
static void F_40 ( struct V_7 * V_8 )
{
int V_42 ;
V_42 = F_35 ( & V_8 -> V_43 , V_48 ) ;
if ( F_36 ( V_42 != V_47 ) )
F_37 ( L_8 , V_46 , V_42 ) ;
F_38 ( L_9 , V_46 , V_8 , V_42 ,
V_48 ) ;
}
static void F_41 ( struct V_7 * V_8 )
{
int V_42 ;
V_42 = F_35 ( & V_8 -> V_43 , V_49 ) ;
if ( F_36 ( V_42 != V_47 &&
V_42 != V_48 &&
V_42 != V_49 ) )
F_37 ( L_8 , V_46 , V_42 ) ;
F_38 ( L_9 , V_46 , V_8 , V_42 ,
V_49 ) ;
}
static void F_42 ( struct V_7 * V_8 )
{
int V_42 ;
V_42 = F_35 ( & V_8 -> V_43 , V_44 ) ;
if ( F_36 ( V_42 != V_48 &&
V_42 != V_49 &&
V_42 != V_47 &&
V_42 != V_44 ) )
F_37 ( L_8 , V_46 , V_42 ) ;
F_38 ( L_9 , V_46 , V_8 , V_42 ,
V_44 ) ;
}
static void F_43 ( struct V_50 * V_51 )
{
struct V_7 * V_8 = V_51 -> V_52 ;
if ( F_44 ( & V_8 -> V_30 -> V_53 ) ) {
return;
}
if ( V_51 -> V_54 != V_55 ) {
F_38 ( L_10 , V_46 ,
V_8 , V_8 -> V_56 ) ;
F_45 ( V_8 ) ;
}
}
static void F_46 ( struct V_50 * V_51 )
{
struct V_7 * V_8 = V_51 -> V_52 ;
if ( F_7 ( V_8 , V_4 ) ) {
if ( F_47 ( V_51 ) ) {
F_38 ( L_11 , V_46 , V_8 ) ;
F_4 ( V_57 , & V_51 -> V_58 -> V_9 ) ;
F_45 ( V_8 ) ;
}
} else {
F_38 ( L_12 , V_46 , V_8 ) ;
}
}
static void F_48 ( struct V_50 * V_51 )
{
struct V_7 * V_8 = V_51 -> V_52 ;
F_38 ( L_13 , V_46 ,
V_8 , V_8 -> V_56 , V_51 -> V_54 ) ;
switch ( V_51 -> V_54 ) {
case V_59 :
F_38 ( L_14 , V_46 ) ;
case V_55 :
F_38 ( L_15 , V_46 ) ;
F_41 ( V_8 ) ;
F_5 ( V_8 , V_5 ) ;
F_45 ( V_8 ) ;
break;
case V_60 :
F_38 ( L_16 , V_46 ) ;
F_40 ( V_8 ) ;
F_45 ( V_8 ) ;
break;
default:
break;
}
}
static void F_49 ( struct V_61 * V_50 ,
struct V_7 * V_8 )
{
struct V_50 * V_51 = V_50 -> V_51 ;
V_51 -> V_52 = V_8 ;
V_51 -> V_62 = F_43 ;
V_51 -> V_63 = F_46 ;
V_51 -> V_64 = F_48 ;
}
static int F_50 ( struct V_7 * V_8 )
{
struct V_10 * V_65 = & V_8 -> V_66 . V_67 ;
struct V_61 * V_50 ;
int V_68 ;
F_3 ( V_8 -> V_50 ) ;
V_68 = F_51 ( F_52 ( & V_8 -> V_30 -> V_69 ) , V_65 -> V_21 ,
V_70 , V_71 , & V_50 ) ;
if ( V_68 )
return V_68 ;
V_50 -> V_51 -> V_72 = V_73 ;
#ifdef F_53
F_54 ( & V_50 -> V_51 -> V_74 , & V_75 ) ;
#endif
F_49 ( V_50 , V_8 ) ;
F_38 ( L_17 , F_13 ( & V_8 -> V_66 . V_67 ) ) ;
F_39 ( V_8 ) ;
V_68 = V_50 -> V_76 -> V_77 ( V_50 , (struct V_78 * ) V_65 , sizeof( * V_65 ) ,
V_79 ) ;
if ( V_68 == - V_80 ) {
F_38 ( L_18 ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_50 -> V_51 -> V_54 ) ;
} else if ( V_68 < 0 ) {
F_30 ( L_19 ,
F_13 ( & V_8 -> V_66 . V_67 ) , V_68 ) ;
F_55 ( V_50 ) ;
return V_68 ;
}
if ( F_56 ( F_57 ( V_8 -> V_30 ) , V_81 ) ) {
int V_82 = 1 ;
V_68 = F_58 ( V_50 , V_83 , V_81 ,
( char * ) & V_82 , sizeof( V_82 ) ) ;
if ( V_68 )
F_30 ( L_20 ,
V_68 ) ;
}
V_8 -> V_50 = V_50 ;
return 0 ;
}
static int F_59 ( struct V_61 * V_50 , void * V_84 , T_1 V_85 )
{
struct V_86 V_87 = { V_84 , V_85 } ;
struct V_88 V_89 = { . V_90 = V_91 | V_92 } ;
int V_93 ;
V_93 = F_60 ( V_50 , & V_89 , & V_87 , 1 , V_85 , V_89 . V_90 ) ;
if ( V_93 == - V_94 )
V_93 = 0 ;
return V_93 ;
}
static int F_61 ( struct V_61 * V_50 , struct V_95 * V_95 ,
int V_96 , T_1 V_97 )
{
void * V_98 ;
int V_68 ;
F_3 ( V_96 + V_97 > V_99 ) ;
V_98 = F_62 ( V_95 ) ;
F_3 ( ! V_98 ) ;
V_68 = F_59 ( V_50 , V_98 + V_96 , V_97 ) ;
F_63 ( V_95 ) ;
return V_68 ;
}
static int F_64 ( struct V_61 * V_50 , struct V_86 * V_87 ,
T_1 V_100 , T_1 V_85 , int V_101 )
{
struct V_88 V_89 = { . V_90 = V_91 | V_92 } ;
int V_93 ;
if ( V_101 )
V_89 . V_90 |= V_102 ;
else
V_89 . V_90 |= V_103 ;
V_93 = F_65 ( V_50 , & V_89 , V_87 , V_100 , V_85 ) ;
if ( V_93 == - V_94 )
V_93 = 0 ;
return V_93 ;
}
static int F_66 ( struct V_61 * V_50 , struct V_95 * V_95 ,
int V_104 , T_1 V_105 , bool V_101 )
{
int V_9 = V_91 | V_92 | ( V_101 ? V_102 : V_103 ) ;
int V_68 ;
V_68 = F_67 ( V_50 , V_95 , V_104 , V_105 , V_9 ) ;
if ( V_68 == - V_94 )
V_68 = 0 ;
return V_68 ;
}
static int F_68 ( struct V_61 * V_50 , struct V_95 * V_95 ,
int V_104 , T_1 V_105 , bool V_101 )
{
int V_68 ;
struct V_86 V_87 ;
if ( F_69 ( V_95 ) >= 1 )
return F_66 ( V_50 , V_95 , V_104 , V_105 , V_101 ) ;
V_87 . V_106 = F_62 ( V_95 ) + V_104 ;
V_87 . V_107 = V_105 ;
V_68 = F_64 ( V_50 , & V_87 , 1 , V_105 , V_101 ) ;
F_63 ( V_95 ) ;
return V_68 ;
}
static int F_70 ( struct V_7 * V_8 )
{
int V_108 = 0 ;
F_38 ( L_21 , V_8 , V_8 -> V_50 ) ;
if ( V_8 -> V_50 ) {
V_108 = V_8 -> V_50 -> V_76 -> V_109 ( V_8 -> V_50 , V_110 ) ;
F_55 ( V_8 -> V_50 ) ;
V_8 -> V_50 = NULL ;
}
F_2 ( V_8 , V_5 ) ;
F_42 ( V_8 ) ;
return V_108 ;
}
static void F_71 ( struct V_35 * V_89 )
{
F_72 ( & V_89 -> V_111 ) ;
F_73 ( V_89 ) ;
}
static void F_74 ( struct V_111 * V_112 )
{
while ( ! F_75 ( V_112 ) ) {
struct V_35 * V_89 = F_76 ( V_112 , struct V_35 ,
V_111 ) ;
F_71 ( V_89 ) ;
}
}
static void F_77 ( struct V_7 * V_8 )
{
F_38 ( L_22 , V_8 ) ;
F_74 ( & V_8 -> V_113 ) ;
F_74 ( & V_8 -> V_114 ) ;
if ( V_8 -> V_115 ) {
F_3 ( V_8 -> V_115 -> V_8 != V_8 ) ;
F_73 ( V_8 -> V_115 ) ;
V_8 -> V_115 = NULL ;
}
V_8 -> V_116 = 0 ;
V_8 -> V_117 = 0 ;
if ( V_8 -> V_118 ) {
F_3 ( V_8 -> V_118 -> V_8 != V_8 ) ;
F_73 ( V_8 -> V_118 ) ;
V_8 -> V_118 = NULL ;
}
V_8 -> V_119 = 0 ;
V_8 -> V_120 = 0 ;
V_8 -> V_121 = 0 ;
}
void F_78 ( struct V_7 * V_8 )
{
F_79 ( & V_8 -> V_122 ) ;
F_38 ( L_23 , V_8 ,
F_13 ( & V_8 -> V_66 . V_67 ) ) ;
V_8 -> V_56 = V_123 ;
F_2 ( V_8 , V_2 ) ;
F_2 ( V_8 , V_3 ) ;
F_2 ( V_8 , V_4 ) ;
F_2 ( V_8 , V_6 ) ;
F_77 ( V_8 ) ;
V_8 -> V_124 = 0 ;
F_80 ( V_8 ) ;
F_70 ( V_8 ) ;
F_81 ( & V_8 -> V_122 ) ;
}
void F_82 ( struct V_7 * V_8 ,
T_2 V_125 , T_3 V_126 ,
struct V_127 * V_33 )
{
F_79 ( & V_8 -> V_122 ) ;
F_38 ( L_24 , V_8 , F_13 ( & V_33 -> V_67 ) ) ;
F_36 ( V_8 -> V_56 != V_123 ) ;
V_8 -> V_56 = V_128 ;
V_8 -> V_129 . type = ( T_2 ) V_125 ;
V_8 -> V_129 . V_130 = F_83 ( V_126 ) ;
memcpy ( & V_8 -> V_66 , V_33 , sizeof( * V_33 ) ) ;
V_8 -> V_131 = 0 ;
F_81 ( & V_8 -> V_122 ) ;
F_45 ( V_8 ) ;
}
bool F_84 ( struct V_7 * V_8 )
{
return V_8 -> V_116 > 0 ;
}
void F_85 ( struct V_7 * V_8 , void * V_132 ,
const struct V_133 * V_76 ,
struct V_29 * V_30 )
{
F_38 ( L_25 , V_8 ) ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> V_132 = V_132 ;
V_8 -> V_76 = V_76 ;
V_8 -> V_30 = V_30 ;
F_34 ( V_8 ) ;
F_86 ( & V_8 -> V_122 ) ;
F_87 ( & V_8 -> V_113 ) ;
F_87 ( & V_8 -> V_114 ) ;
F_88 ( & V_8 -> V_134 , V_135 ) ;
V_8 -> V_56 = V_123 ;
}
static T_4 F_89 ( struct V_29 * V_30 , T_4 V_136 )
{
T_4 V_68 ;
F_90 ( & V_30 -> V_137 ) ;
if ( V_30 -> V_138 < V_136 )
V_30 -> V_138 = V_136 ;
V_68 = ++ V_30 -> V_138 ;
F_91 ( & V_30 -> V_137 ) ;
return V_68 ;
}
static void F_92 ( struct V_7 * V_8 )
{
F_3 ( V_8 -> V_121 ) ;
V_8 -> V_139 = 0 ;
V_8 -> V_140 = 0 ;
V_8 -> V_141 = & V_8 -> V_142 [ 0 ] ;
}
static void F_93 ( struct V_7 * V_8 ,
T_1 V_105 , void * V_143 )
{
int V_144 = V_8 -> V_139 ;
F_3 ( V_8 -> V_121 ) ;
F_3 ( V_144 >= F_94 ( V_8 -> V_142 ) ) ;
V_8 -> V_142 [ V_144 ] . V_107 = V_105 ;
V_8 -> V_142 [ V_144 ] . V_106 = V_143 ;
V_8 -> V_139 ++ ;
V_8 -> V_140 += V_105 ;
}
static int F_95 ( struct V_7 * V_8 )
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
static void F_96 ( struct V_147 * V_148 ,
T_1 V_97 )
{
struct V_38 * V_143 = V_148 -> V_143 ;
struct V_149 * V_149 ;
F_3 ( V_143 -> type != V_150 ) ;
V_149 = V_143 -> V_149 ;
F_3 ( ! V_149 ) ;
V_148 -> V_151 = F_97 ( V_97 , V_143 -> V_152 ) ;
V_148 -> V_149 = V_149 ;
V_148 -> V_153 = V_149 -> V_154 ;
V_148 -> V_155 =
V_148 -> V_151 <= F_98 ( V_149 , V_148 -> V_153 ) ;
}
static struct V_95 * F_99 ( struct V_147 * V_148 ,
T_1 * V_96 ,
T_1 * V_97 )
{
struct V_38 * V_143 = V_148 -> V_143 ;
struct V_149 * V_149 ;
struct V_156 V_156 ;
F_3 ( V_143 -> type != V_150 ) ;
V_149 = V_148 -> V_149 ;
F_3 ( ! V_149 ) ;
V_156 = F_100 ( V_149 , V_148 -> V_153 ) ;
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
static bool F_101 ( struct V_147 * V_148 ,
T_1 V_160 )
{
struct V_149 * V_149 ;
struct V_156 V_156 ;
F_3 ( V_148 -> V_143 -> type != V_150 ) ;
V_149 = V_148 -> V_149 ;
F_3 ( ! V_149 ) ;
V_156 = F_100 ( V_149 , V_148 -> V_153 ) ;
F_3 ( V_148 -> V_151 < V_160 ) ;
V_148 -> V_151 -= V_160 ;
F_102 ( V_149 , & V_148 -> V_153 , V_160 ) ;
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
if ( V_148 -> V_151 <= F_98 ( V_149 , V_148 -> V_153 ) )
V_148 -> V_155 = true ;
}
return true ;
}
static void F_103 ( struct V_147 * V_148 ,
T_1 V_97 )
{
struct V_38 * V_143 = V_148 -> V_143 ;
int F_69 ;
F_3 ( V_143 -> type != V_163 ) ;
F_3 ( ! V_143 -> V_164 ) ;
F_3 ( ! V_143 -> V_97 ) ;
V_148 -> V_151 = F_97 ( V_97 , V_143 -> V_97 ) ;
F_69 = F_104 ( V_143 -> V_165 , ( V_166 ) V_143 -> V_97 ) ;
V_148 -> V_96 = V_143 -> V_165 & ~ V_167 ;
V_148 -> V_168 = 0 ;
F_3 ( F_69 > ( int ) V_169 ) ;
V_148 -> F_69 = ( unsigned short ) F_69 ;
F_3 ( V_97 > V_170 - V_148 -> V_96 ) ;
V_148 -> V_155 = V_148 -> V_96 + V_148 -> V_151 <= V_99 ;
}
static struct V_95 *
F_105 ( struct V_147 * V_148 ,
T_1 * V_96 , T_1 * V_97 )
{
struct V_38 * V_143 = V_148 -> V_143 ;
F_3 ( V_143 -> type != V_163 ) ;
F_3 ( V_148 -> V_168 >= V_148 -> F_69 ) ;
F_3 ( V_148 -> V_96 >= V_99 ) ;
* V_96 = V_148 -> V_96 ;
if ( V_148 -> V_155 )
* V_97 = V_148 -> V_151 ;
else
* V_97 = V_99 - * V_96 ;
return V_143 -> V_164 [ V_148 -> V_168 ] ;
}
static bool F_106 ( struct V_147 * V_148 ,
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
F_3 ( V_148 -> V_168 >= V_148 -> F_69 ) ;
V_148 -> V_168 ++ ;
V_148 -> V_155 = V_148 -> V_151 <= V_99 ;
return true ;
}
static void
F_107 ( struct V_147 * V_148 ,
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
F_3 ( F_75 ( & V_172 -> V_112 ) ) ;
V_95 = F_76 ( & V_172 -> V_112 , struct V_95 , V_174 ) ;
V_148 -> V_151 = F_97 ( V_97 , V_172 -> V_97 ) ;
V_148 -> V_95 = V_95 ;
V_148 -> V_104 = 0 ;
V_148 -> V_155 = V_148 -> V_151 <= V_99 ;
}
static struct V_95 *
F_108 ( struct V_147 * V_148 ,
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
static bool F_109 ( struct V_147 * V_148 ,
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
F_3 ( F_110 ( & V_148 -> V_95 -> V_174 , & V_172 -> V_112 ) ) ;
V_148 -> V_95 = F_111 ( V_148 -> V_95 , V_174 ) ;
V_148 -> V_155 = V_148 -> V_151 <= V_99 ;
return true ;
}
static void F_112 ( struct V_147 * V_148 )
{
T_1 V_97 = V_148 -> V_175 ;
switch ( V_148 -> V_143 -> type ) {
case V_173 :
F_107 ( V_148 , V_97 ) ;
break;
case V_163 :
F_103 ( V_148 , V_97 ) ;
break;
#ifdef F_113
case V_150 :
F_96 ( V_148 , V_97 ) ;
break;
#endif
case V_176 :
default:
break;
}
V_148 -> V_177 = true ;
}
static void F_114 ( struct V_35 * V_89 , T_1 V_97 )
{
struct V_147 * V_148 = & V_89 -> V_148 ;
struct V_38 * V_143 ;
F_3 ( ! V_97 ) ;
F_3 ( V_97 > V_89 -> V_178 ) ;
F_3 ( F_75 ( & V_89 -> V_143 ) ) ;
V_148 -> V_179 = & V_89 -> V_143 ;
V_148 -> V_175 = V_97 ;
V_143 = F_76 ( & V_89 -> V_143 , struct V_38 , V_180 ) ;
V_148 -> V_143 = V_143 ;
F_112 ( V_148 ) ;
}
static struct V_95 * F_115 ( struct V_147 * V_148 ,
T_1 * V_96 , T_1 * V_97 ,
bool * V_155 )
{
struct V_95 * V_95 ;
switch ( V_148 -> V_143 -> type ) {
case V_173 :
V_95 = F_108 ( V_148 , V_96 , V_97 ) ;
break;
case V_163 :
V_95 = F_105 ( V_148 , V_96 , V_97 ) ;
break;
#ifdef F_113
case V_150 :
V_95 = F_99 ( V_148 , V_96 , V_97 ) ;
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
static bool F_116 ( struct V_147 * V_148 ,
T_1 V_160 )
{
bool V_181 ;
F_3 ( V_160 > V_148 -> V_151 ) ;
switch ( V_148 -> V_143 -> type ) {
case V_173 :
V_181 = F_109 ( V_148 , V_160 ) ;
break;
case V_163 :
V_181 = F_106 ( V_148 , V_160 ) ;
break;
#ifdef F_113
case V_150 :
V_181 = F_101 ( V_148 , V_160 ) ;
break;
#endif
case V_176 :
default:
F_117 () ;
break;
}
V_148 -> V_175 -= V_160 ;
if ( ! V_148 -> V_151 && V_148 -> V_175 ) {
F_36 ( ! V_148 -> V_155 ) ;
F_3 ( F_110 ( & V_148 -> V_143 -> V_180 , V_148 -> V_179 ) ) ;
V_148 -> V_143 = F_111 ( V_148 -> V_143 , V_180 ) ;
F_112 ( V_148 ) ;
V_181 = true ;
}
V_148 -> V_177 = V_181 ;
return V_181 ;
}
static T_1 F_118 ( struct V_7 * V_8 )
{
return ( V_8 -> V_182 & V_183 ) ?
sizeof( struct V_184 ) :
sizeof( struct V_185 ) ;
}
static void F_119 ( struct V_35 * V_89 , T_4 V_186 )
{
F_3 ( ! V_89 ) ;
F_3 ( ! V_186 ) ;
F_114 ( V_89 , ( T_1 ) V_186 ) ;
}
static void F_120 ( struct V_7 * V_8 )
{
struct V_35 * V_187 = V_8 -> V_118 ;
int V_188 = V_8 -> V_139 ;
V_187 -> V_189 . V_9 |= V_190 ;
F_38 ( L_26 , V_8 ) ;
V_8 -> V_142 [ V_188 ] . V_106 = & V_187 -> V_189 ;
if ( V_8 -> V_182 & V_183 ) {
if ( V_8 -> V_76 -> V_191 )
V_8 -> V_76 -> V_191 ( V_187 ) ;
else
V_187 -> V_189 . V_192 = 0 ;
V_8 -> V_142 [ V_188 ] . V_107 = sizeof( V_187 -> V_189 ) ;
V_8 -> V_140 += sizeof( V_187 -> V_189 ) ;
} else {
V_187 -> V_193 . V_9 = V_187 -> V_189 . V_9 ;
V_8 -> V_142 [ V_188 ] . V_107 = sizeof( V_187 -> V_193 ) ;
V_8 -> V_140 += sizeof( V_187 -> V_193 ) ;
}
V_8 -> V_139 ++ ;
V_8 -> V_194 = V_187 -> V_195 ;
V_8 -> V_196 = true ;
}
static void F_121 ( struct V_7 * V_8 )
{
struct V_35 * V_187 ;
T_4 V_197 ;
F_92 ( V_8 ) ;
V_8 -> V_196 = false ;
if ( V_8 -> V_119 > V_8 -> V_120 ) {
V_8 -> V_120 = V_8 -> V_119 ;
F_93 ( V_8 , sizeof ( V_198 ) , & V_198 ) ;
V_8 -> V_199 = F_83 ( V_8 -> V_120 ) ;
F_93 ( V_8 , sizeof ( V_8 -> V_199 ) ,
& V_8 -> V_199 ) ;
}
F_3 ( F_75 ( & V_8 -> V_113 ) ) ;
V_187 = F_76 ( & V_8 -> V_113 , struct V_35 , V_111 ) ;
V_8 -> V_118 = V_187 ;
F_3 ( V_187 -> V_8 != V_8 ) ;
F_122 ( V_187 ) ;
F_123 ( & V_187 -> V_111 , & V_8 -> V_114 ) ;
if ( V_187 -> V_200 ) {
V_187 -> V_201 . V_202 = F_83 ( ++ V_8 -> V_117 ) ;
V_187 -> V_200 = false ;
}
F_36 ( V_187 -> V_178 != F_124 ( V_187 -> V_201 . V_186 ) ) ;
F_38 ( L_27 ,
V_187 , V_8 -> V_117 , F_125 ( V_187 -> V_201 . type ) ,
F_124 ( V_187 -> V_201 . V_203 ) , F_124 ( V_187 -> V_201 . V_204 ) ,
V_187 -> V_178 ) ;
F_3 ( F_124 ( V_187 -> V_201 . V_203 ) != V_187 -> V_205 . V_107 ) ;
F_93 ( V_8 , sizeof ( V_206 ) , & V_206 ) ;
F_93 ( V_8 , sizeof( V_8 -> V_207 ) , & V_8 -> V_207 ) ;
F_93 ( V_8 , V_187 -> V_205 . V_107 , V_187 -> V_205 . V_106 ) ;
if ( V_187 -> V_208 )
F_93 ( V_8 , V_187 -> V_208 -> V_209 . V_107 ,
V_187 -> V_208 -> V_209 . V_106 ) ;
V_197 = F_126 ( 0 , & V_187 -> V_201 , F_127 ( struct V_210 , V_197 ) ) ;
V_8 -> V_118 -> V_201 . V_197 = F_128 ( V_197 ) ;
memcpy ( & V_8 -> V_207 , & V_8 -> V_118 -> V_201 , sizeof( V_8 -> V_207 ) ) ;
V_197 = F_126 ( 0 , V_187 -> V_205 . V_106 , V_187 -> V_205 . V_107 ) ;
V_8 -> V_118 -> V_189 . V_211 = F_128 ( V_197 ) ;
if ( V_187 -> V_208 ) {
V_197 = F_126 ( 0 , V_187 -> V_208 -> V_209 . V_106 ,
V_187 -> V_208 -> V_209 . V_107 ) ;
V_8 -> V_118 -> V_189 . V_212 = F_128 ( V_197 ) ;
} else
V_8 -> V_118 -> V_189 . V_212 = 0 ;
F_38 ( L_28 , V_46 ,
F_124 ( V_8 -> V_118 -> V_189 . V_211 ) ,
F_124 ( V_8 -> V_118 -> V_189 . V_212 ) ) ;
V_8 -> V_118 -> V_189 . V_9 = 0 ;
V_8 -> V_118 -> V_189 . V_213 = 0 ;
if ( V_187 -> V_178 ) {
F_119 ( V_8 -> V_118 , V_187 -> V_178 ) ;
V_8 -> V_194 = 1 ;
} else {
F_120 ( V_8 ) ;
}
F_5 ( V_8 , V_4 ) ;
}
static void F_129 ( struct V_7 * V_8 )
{
F_38 ( L_29 , V_8 ,
V_8 -> V_120 , V_8 -> V_119 ) ;
V_8 -> V_120 = V_8 -> V_119 ;
F_92 ( V_8 ) ;
F_93 ( V_8 , sizeof ( V_198 ) , & V_198 ) ;
V_8 -> V_199 = F_83 ( V_8 -> V_120 ) ;
F_93 ( V_8 , sizeof ( V_8 -> V_199 ) ,
& V_8 -> V_199 ) ;
V_8 -> V_194 = 1 ;
F_5 ( V_8 , V_4 ) ;
}
static void F_130 ( struct V_7 * V_8 )
{
F_38 ( L_30 , V_8 ,
V_8 -> V_120 , V_8 -> V_119 ) ;
V_8 -> V_120 = V_8 -> V_119 ;
F_92 ( V_8 ) ;
V_8 -> V_199 = F_83 ( V_8 -> V_120 ) ;
F_93 ( V_8 , sizeof ( V_8 -> V_199 ) ,
& V_8 -> V_199 ) ;
F_5 ( V_8 , V_4 ) ;
}
static void F_131 ( struct V_7 * V_8 )
{
F_38 ( L_31 , V_8 ) ;
F_92 ( V_8 ) ;
if ( V_8 -> V_182 & V_214 ) {
struct V_215 V_216 = V_217 ;
F_93 ( V_8 , sizeof( V_218 ) , & V_218 ) ;
F_132 ( & V_8 -> V_219 , & V_216 ) ;
F_93 ( V_8 , sizeof( V_8 -> V_219 ) ,
& V_8 -> V_219 ) ;
} else {
F_93 ( V_8 , sizeof( V_220 ) , & V_220 ) ;
}
F_5 ( V_8 , V_4 ) ;
}
static struct V_221 * F_133 ( struct V_7 * V_8 ,
int * V_222 )
{
struct V_221 * V_223 ;
if ( ! V_8 -> V_76 -> V_224 ) {
V_8 -> V_225 . V_226 = V_227 ;
V_8 -> V_225 . V_228 = 0 ;
return NULL ;
}
F_81 ( & V_8 -> V_122 ) ;
V_223 = V_8 -> V_76 -> V_224 ( V_8 , V_222 , V_8 -> V_229 ) ;
F_79 ( & V_8 -> V_122 ) ;
if ( F_134 ( V_223 ) )
return V_223 ;
if ( V_8 -> V_56 != V_230 )
return F_135 ( - V_94 ) ;
V_8 -> V_231 = V_223 -> V_232 ;
V_8 -> V_233 = V_223 -> V_234 ;
return V_223 ;
}
static void F_136 ( struct V_7 * V_8 )
{
F_93 ( V_8 , strlen ( V_235 ) , V_235 ) ;
F_93 ( V_8 , sizeof ( V_8 -> V_30 -> V_31 ) ,
& V_8 -> V_30 -> V_31 ) ;
V_8 -> V_194 = 0 ;
F_5 ( V_8 , V_4 ) ;
}
static int F_137 ( struct V_7 * V_8 )
{
unsigned int V_138 = F_89 ( V_8 -> V_30 , 0 ) ;
int V_236 ;
int V_222 ;
struct V_221 * V_223 ;
switch ( V_8 -> V_129 . type ) {
case V_237 :
V_236 = V_238 ;
break;
case V_239 :
V_236 = V_240 ;
break;
case V_241 :
V_236 = V_242 ;
break;
default:
F_117 () ;
}
F_38 ( L_32 , V_8 ,
V_8 -> V_116 , V_138 , V_236 ) ;
V_8 -> V_225 . V_243 =
F_83 ( F_57 ( V_8 -> V_30 ) -> V_244 ) ;
V_8 -> V_225 . V_245 = F_128 ( V_246 ) ;
V_8 -> V_225 . V_116 = F_128 ( V_8 -> V_116 ) ;
V_8 -> V_225 . V_138 = F_128 ( V_138 ) ;
V_8 -> V_225 . V_247 = F_128 ( V_236 ) ;
V_8 -> V_225 . V_9 = 0 ;
V_222 = V_227 ;
V_223 = F_133 ( V_8 , & V_222 ) ;
if ( F_134 ( V_223 ) )
return F_138 ( V_223 ) ;
V_8 -> V_225 . V_226 = F_128 ( V_222 ) ;
V_8 -> V_225 . V_228 = V_223 ?
F_128 ( V_223 -> V_248 ) : 0 ;
F_93 ( V_8 , sizeof ( V_8 -> V_225 ) ,
& V_8 -> V_225 ) ;
if ( V_223 && V_223 -> V_248 )
F_93 ( V_8 , V_223 -> V_248 ,
V_223 -> V_249 ) ;
V_8 -> V_194 = 0 ;
F_5 ( V_8 , V_4 ) ;
return 0 ;
}
static int F_139 ( struct V_7 * V_8 )
{
int V_68 ;
F_38 ( L_33 , V_8 , V_8 -> V_140 ) ;
while ( V_8 -> V_140 > 0 ) {
V_68 = F_64 ( V_8 -> V_50 , V_8 -> V_141 ,
V_8 -> V_139 , V_8 -> V_140 ,
V_8 -> V_194 ) ;
if ( V_68 <= 0 )
goto V_250;
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
V_250:
F_38 ( L_34 , V_8 ,
V_8 -> V_140 , V_8 -> V_139 , V_68 ) ;
return V_68 ;
}
static T_4 F_140 ( T_4 V_197 , struct V_95 * V_95 ,
unsigned int V_96 ,
unsigned int V_97 )
{
char * V_98 ;
V_98 = F_62 ( V_95 ) ;
F_3 ( V_98 == NULL ) ;
V_197 = F_126 ( V_197 , V_98 + V_96 , V_97 ) ;
F_63 ( V_95 ) ;
return V_197 ;
}
static int F_141 ( struct V_7 * V_8 )
{
struct V_35 * V_89 = V_8 -> V_118 ;
struct V_147 * V_148 = & V_89 -> V_148 ;
bool V_251 = ! F_56 ( F_57 ( V_8 -> V_30 ) , V_252 ) ;
T_4 V_197 ;
F_38 ( L_35 , V_46 , V_8 , V_89 ) ;
if ( F_75 ( & V_89 -> V_143 ) )
return - V_253 ;
V_197 = V_251 ? F_124 ( V_89 -> V_189 . V_213 ) : 0 ;
while ( V_148 -> V_151 ) {
struct V_95 * V_95 ;
T_1 V_96 ;
T_1 V_97 ;
bool V_155 ;
bool V_177 ;
int V_68 ;
V_95 = F_115 ( V_148 , & V_96 , & V_97 ,
& V_155 ) ;
V_68 = F_68 ( V_8 -> V_50 , V_95 , V_96 ,
V_97 , ! V_155 ) ;
if ( V_68 <= 0 ) {
if ( V_251 )
V_89 -> V_189 . V_213 = F_128 ( V_197 ) ;
return V_68 ;
}
if ( V_251 && V_148 -> V_177 )
V_197 = F_140 ( V_197 , V_95 , V_96 , V_97 ) ;
V_177 = F_116 ( V_148 , ( T_1 ) V_68 ) ;
}
F_38 ( L_36 , V_46 , V_8 , V_89 ) ;
if ( V_251 )
V_89 -> V_189 . V_213 = F_128 ( V_197 ) ;
else
V_89 -> V_189 . V_9 |= V_254 ;
F_92 ( V_8 ) ;
F_120 ( V_8 ) ;
return 1 ;
}
static int F_142 ( struct V_7 * V_8 )
{
int V_68 ;
F_38 ( L_37 , V_46 , V_8 , V_8 -> V_121 ) ;
while ( V_8 -> V_121 > 0 ) {
T_1 V_105 = F_97 ( V_8 -> V_121 , ( int ) V_255 ) ;
V_68 = F_68 ( V_8 -> V_50 , V_40 , 0 , V_105 , true ) ;
if ( V_68 <= 0 )
goto V_250;
V_8 -> V_121 -= V_68 ;
}
V_68 = 1 ;
V_250:
return V_68 ;
}
static void F_143 ( struct V_7 * V_8 )
{
F_38 ( L_38 , V_8 ) ;
V_8 -> V_256 = 0 ;
}
static void F_144 ( struct V_7 * V_8 )
{
F_38 ( L_39 , V_8 ) ;
V_8 -> V_256 = 0 ;
}
static void F_145 ( struct V_7 * V_8 )
{
F_38 ( L_40 , V_8 ) ;
V_8 -> V_256 = 0 ;
}
static void F_146 ( struct V_7 * V_8 )
{
F_38 ( L_41 , V_8 ) ;
V_8 -> V_256 = 0 ;
V_8 -> V_257 = V_258 ;
}
static void F_147 ( struct V_7 * V_8 )
{
F_38 ( L_42 , V_8 ) ;
V_8 -> V_256 = 0 ;
V_8 -> V_257 = V_259 ;
}
static void F_148 ( struct V_7 * V_8 )
{
F_38 ( L_43 , V_8 ) ;
V_8 -> V_256 = 0 ;
}
static int F_149 ( struct V_7 * V_8 )
{
F_38 ( L_44 , V_8 ) ;
F_3 ( V_8 -> V_115 != NULL ) ;
V_8 -> V_256 = 0 ;
V_8 -> V_260 = V_8 -> V_261 = V_8 -> V_262 = 0 ;
return 0 ;
}
static int F_150 ( struct V_7 * V_8 ,
int V_263 , int V_105 , void * V_264 )
{
while ( V_8 -> V_256 < V_263 ) {
int V_265 = V_263 - V_8 -> V_256 ;
int V_266 = V_105 - V_265 ;
int V_68 = F_59 ( V_8 -> V_50 , V_264 + V_266 , V_265 ) ;
if ( V_68 <= 0 )
return V_68 ;
V_8 -> V_256 += V_68 ;
}
return 1 ;
}
static int F_151 ( struct V_7 * V_8 )
{
int V_105 ;
int V_263 ;
int V_68 ;
F_38 ( L_45 , V_8 , V_8 -> V_256 ) ;
V_105 = strlen ( V_235 ) ;
V_263 = V_105 ;
V_68 = F_150 ( V_8 , V_263 , V_105 , V_8 -> V_267 ) ;
if ( V_68 <= 0 )
goto V_250;
V_105 = sizeof ( V_8 -> V_268 ) ;
V_263 += V_105 ;
V_68 = F_150 ( V_8 , V_263 , V_105 , & V_8 -> V_268 ) ;
if ( V_68 <= 0 )
goto V_250;
V_105 = sizeof ( V_8 -> V_269 ) ;
V_263 += V_105 ;
V_68 = F_150 ( V_8 , V_263 , V_105 , & V_8 -> V_269 ) ;
if ( V_68 <= 0 )
goto V_250;
V_250:
return V_68 ;
}
static int F_152 ( struct V_7 * V_8 )
{
int V_105 ;
int V_263 ;
int V_68 ;
F_38 ( L_46 , V_8 , V_8 -> V_256 ) ;
V_105 = sizeof ( V_8 -> V_270 ) ;
V_263 = V_105 ;
V_68 = F_150 ( V_8 , V_263 , V_105 , & V_8 -> V_270 ) ;
if ( V_68 <= 0 )
goto V_250;
V_105 = F_124 ( V_8 -> V_270 . V_228 ) ;
V_263 += V_105 ;
V_68 = F_150 ( V_8 , V_263 , V_105 , V_8 -> V_231 ) ;
if ( V_68 <= 0 )
goto V_250;
F_38 ( L_47 ,
V_8 , ( int ) V_8 -> V_270 . V_271 ,
F_124 ( V_8 -> V_270 . V_116 ) ,
F_124 ( V_8 -> V_270 . V_138 ) ) ;
V_250:
return V_68 ;
}
static int F_153 ( struct V_7 * V_8 )
{
if ( memcmp ( V_8 -> V_267 , V_235 , strlen ( V_235 ) ) ) {
F_30 ( L_48 ,
F_13 ( & V_8 -> V_66 . V_67 ) ) ;
V_8 -> V_272 = L_49 ;
return - 1 ;
}
return 0 ;
}
static bool F_154 ( struct V_10 * V_11 )
{
struct V_67 * V_33 = & ( (struct V_14 * ) V_11 ) -> V_24 ;
struct V_273 * V_274 = & ( (struct V_16 * ) V_11 ) -> V_27 ;
switch ( V_11 -> V_21 ) {
case V_22 :
return V_33 -> V_275 == F_155 ( V_276 ) ;
case V_26 :
return F_156 ( V_274 ) ;
default:
return true ;
}
}
static int F_157 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_21 ) {
case V_22 :
return F_15 ( ( (struct V_14 * ) V_11 ) -> V_25 ) ;
case V_26 :
return F_15 ( ( (struct V_16 * ) V_11 ) -> V_28 ) ;
}
return 0 ;
}
static void F_158 ( struct V_10 * V_11 , int V_277 )
{
switch ( V_11 -> V_21 ) {
case V_22 :
( (struct V_14 * ) V_11 ) -> V_25 = F_159 ( V_277 ) ;
break;
case V_26 :
( (struct V_16 * ) V_11 ) -> V_28 = F_159 ( V_277 ) ;
break;
}
}
static int F_160 ( const char * V_278 , T_1 V_85 , struct V_10 * V_11 ,
char V_279 , const char * * V_280 )
{
struct V_14 * V_15 = (struct V_14 * ) V_11 ;
struct V_16 * V_17 = (struct V_16 * ) V_11 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
if ( F_161 ( V_278 , V_85 , ( V_281 * ) & V_15 -> V_24 . V_275 , V_279 , V_280 ) ) {
V_11 -> V_21 = V_22 ;
return 0 ;
}
if ( F_162 ( V_278 , V_85 , ( V_281 * ) & V_17 -> V_27 . V_282 , V_279 , V_280 ) ) {
V_11 -> V_21 = V_26 ;
return 0 ;
}
return - V_253 ;
}
static int F_163 ( const char * V_283 , T_1 V_284 ,
struct V_10 * V_11 , char V_279 , const char * * V_280 )
{
const char * V_263 , * V_285 ;
char * V_286 , * V_287 = NULL ;
int V_288 , V_68 ;
V_285 = memchr ( V_283 , V_279 , V_284 ) ;
V_286 = memchr ( V_283 , ':' , V_284 ) ;
if ( V_285 && V_286 )
V_263 = V_285 < V_286 ? V_285 : V_286 ;
else if ( ! V_285 && V_286 )
V_263 = V_286 ;
else {
V_263 = V_285 ;
if ( ! V_263 )
V_263 = V_283 + V_284 ;
}
if ( V_263 <= V_283 )
return - V_253 ;
V_288 = F_164 ( NULL , V_283 , V_263 - V_283 , NULL , & V_287 , NULL ) ;
if ( V_288 > 0 )
V_68 = F_160 ( V_287 , V_288 , V_11 , - 1 , NULL ) ;
else
V_68 = - V_289 ;
F_165 ( V_287 ) ;
* V_280 = V_263 ;
F_166 ( L_50 , ( int ) ( V_263 - V_283 ) , V_283 ,
V_68 , V_68 ? L_51 : F_13 ( V_11 ) ) ;
return V_68 ;
}
static inline int F_163 ( const char * V_283 , T_1 V_284 ,
struct V_10 * V_11 , char V_279 , const char * * V_280 )
{
return - V_253 ;
}
static int F_167 ( const char * V_283 , T_1 V_284 ,
struct V_10 * V_11 , char V_279 , const char * * V_280 )
{
int V_68 ;
V_68 = F_160 ( V_283 , V_284 , V_11 , V_279 , V_280 ) ;
if ( V_68 )
V_68 = F_163 ( V_283 , V_284 , V_11 , V_279 , V_280 ) ;
return V_68 ;
}
int F_168 ( const char * V_290 , const char * V_263 ,
struct V_127 * V_33 ,
int V_291 , int * V_292 )
{
int V_12 , V_68 = - V_253 ;
const char * V_277 = V_290 ;
F_38 ( L_52 , ( int ) ( V_263 - V_290 ) , V_290 ) ;
for ( V_12 = 0 ; V_12 < V_291 ; V_12 ++ ) {
const char * V_280 ;
struct V_10 * V_11 = & V_33 [ V_12 ] . V_67 ;
int V_293 ;
char V_279 = ',' ;
if ( * V_277 == '[' ) {
V_279 = ']' ;
V_277 ++ ;
}
V_68 = F_167 ( V_277 , V_263 - V_277 , V_11 , V_279 , & V_280 ) ;
if ( V_68 )
goto V_294;
V_68 = - V_253 ;
V_277 = V_280 ;
if ( V_279 == ']' ) {
if ( * V_277 != ']' ) {
F_38 ( L_53 ) ;
goto V_294;
}
V_277 ++ ;
}
if ( V_277 < V_263 && * V_277 == ':' ) {
V_293 = 0 ;
V_277 ++ ;
while ( V_277 < V_263 && * V_277 >= '0' && * V_277 <= '9' ) {
V_293 = ( V_293 * 10 ) + ( * V_277 - '0' ) ;
V_277 ++ ;
}
if ( V_293 == 0 )
V_293 = V_295 ;
else if ( V_293 > 65535 )
goto V_294;
} else {
V_293 = V_295 ;
}
F_158 ( V_11 , V_293 ) ;
F_38 ( L_54 , F_13 ( V_11 ) ) ;
if ( V_277 == V_263 )
break;
if ( * V_277 != ',' )
goto V_294;
V_277 ++ ;
}
if ( V_277 != V_263 )
goto V_294;
if ( V_292 )
* V_292 = V_12 + 1 ;
return 0 ;
V_294:
F_30 ( L_55 , ( int ) ( V_263 - V_290 ) , V_290 ) ;
return V_68 ;
}
static int F_169 ( struct V_7 * V_8 )
{
F_38 ( L_56 , V_8 ) ;
if ( F_153 ( V_8 ) < 0 )
return - 1 ;
F_170 ( & V_8 -> V_268 ) ;
F_170 ( & V_8 -> V_269 ) ;
if ( memcmp ( & V_8 -> V_66 , & V_8 -> V_268 ,
sizeof( V_8 -> V_66 ) ) != 0 &&
! ( F_154 ( & V_8 -> V_268 . V_67 ) &&
V_8 -> V_268 . V_296 == V_8 -> V_66 . V_296 ) ) {
F_171 ( L_57 ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
( int ) F_124 ( V_8 -> V_66 . V_296 ) ,
F_13 ( & V_8 -> V_268 . V_67 ) ,
( int ) F_124 ( V_8 -> V_268 . V_296 ) ) ;
V_8 -> V_272 = L_58 ;
return - 1 ;
}
if ( F_154 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ) ) {
int V_293 = F_157 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ) ;
memcpy ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ,
& V_8 -> V_269 . V_67 ,
sizeof( V_8 -> V_269 . V_67 ) ) ;
F_158 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 , V_293 ) ;
F_16 ( V_8 -> V_30 ) ;
F_38 ( L_59 ,
F_13 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ) ) ;
}
return 0 ;
}
static int F_172 ( struct V_7 * V_8 )
{
V_166 V_297 = F_57 ( V_8 -> V_30 ) -> V_244 ;
V_166 V_298 = F_57 ( V_8 -> V_30 ) -> V_299 ;
V_166 V_300 = F_173 (
F_174 ( V_8 -> V_270 . V_243 ) ) ;
int V_68 ;
F_38 ( L_60 , V_8 , ( int ) V_8 -> V_257 ) ;
switch ( V_8 -> V_270 . V_271 ) {
case V_301 :
F_30 ( L_61
L_62 ,
F_175 ( V_8 -> V_129 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_297 , V_300 , V_300 & ~ V_297 ) ;
V_8 -> V_272 = L_63 ;
F_77 ( V_8 ) ;
return - 1 ;
case V_302 :
F_30 ( L_64
L_65 ,
F_175 ( V_8 -> V_129 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
F_124 ( V_8 -> V_225 . V_247 ) ,
F_124 ( V_8 -> V_270 . V_247 ) ) ;
V_8 -> V_272 = L_66 ;
F_77 ( V_8 ) ;
return - 1 ;
case V_303 :
V_8 -> V_229 ++ ;
F_38 ( L_67 , V_8 ,
V_8 -> V_229 ) ;
if ( V_8 -> V_229 == 2 ) {
V_8 -> V_272 = L_68 ;
return - 1 ;
}
F_92 ( V_8 ) ;
V_68 = F_137 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_144 ( V_8 ) ;
break;
case V_304 :
F_38 ( L_69 ,
F_124 ( V_8 -> V_270 . V_116 ) ) ;
F_30 ( L_70 ,
F_175 ( V_8 -> V_129 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ) ;
F_77 ( V_8 ) ;
F_92 ( V_8 ) ;
V_68 = F_137 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_144 ( V_8 ) ;
F_81 ( & V_8 -> V_122 ) ;
F_166 ( L_71 , F_175 ( V_8 -> V_129 ) ) ;
if ( V_8 -> V_76 -> V_305 )
V_8 -> V_76 -> V_305 ( V_8 ) ;
F_79 ( & V_8 -> V_122 ) ;
if ( V_8 -> V_56 != V_230 )
return - V_94 ;
break;
case V_306 :
F_38 ( L_72 ,
F_124 ( V_8 -> V_225 . V_116 ) ,
F_124 ( V_8 -> V_270 . V_116 ) ) ;
V_8 -> V_116 = F_124 ( V_8 -> V_270 . V_116 ) ;
F_92 ( V_8 ) ;
V_68 = F_137 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_144 ( V_8 ) ;
break;
case V_307 :
F_38 ( L_73 ,
V_8 -> V_124 ,
F_124 ( V_8 -> V_270 . V_138 ) ) ;
F_89 ( V_8 -> V_30 ,
F_124 ( V_8 -> V_270 . V_138 ) ) ;
F_92 ( V_8 ) ;
V_68 = F_137 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_144 ( V_8 ) ;
break;
case V_258 :
case V_259 :
if ( V_298 & ~ V_300 ) {
F_30 ( L_74
L_75 ,
F_175 ( V_8 -> V_129 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_298 , V_300 , V_298 & ~ V_300 ) ;
V_8 -> V_272 = L_63 ;
F_77 ( V_8 ) ;
return - 1 ;
}
F_36 ( V_8 -> V_56 != V_230 ) ;
V_8 -> V_56 = V_308 ;
V_8 -> V_229 = 0 ;
V_8 -> V_124 = F_124 ( V_8 -> V_270 . V_138 ) ;
V_8 -> V_116 ++ ;
V_8 -> V_182 = V_300 ;
F_38 ( L_76 ,
V_8 -> V_124 ,
F_124 ( V_8 -> V_270 . V_116 ) ,
V_8 -> V_116 ) ;
F_36 ( V_8 -> V_116 !=
F_124 ( V_8 -> V_270 . V_116 ) ) ;
if ( V_8 -> V_270 . V_9 & V_309 )
F_5 ( V_8 , V_2 ) ;
V_8 -> V_131 = 0 ;
if ( V_8 -> V_270 . V_271 == V_258 ) {
F_130 ( V_8 ) ;
F_146 ( V_8 ) ;
} else {
F_147 ( V_8 ) ;
}
break;
case V_310 :
V_8 -> V_272 = L_77 ;
return - 1 ;
default:
V_8 -> V_272 = L_78 ;
return - 1 ;
}
return 0 ;
}
static int F_176 ( struct V_7 * V_8 )
{
int V_105 = sizeof ( V_8 -> V_311 ) ;
int V_263 = V_105 ;
return F_150 ( V_8 , V_263 , V_105 , & V_8 -> V_311 ) ;
}
static void F_177 ( struct V_7 * V_8 )
{
struct V_35 * V_187 ;
V_166 V_312 = F_174 ( V_8 -> V_311 ) ;
V_166 V_202 ;
while ( ! F_75 ( & V_8 -> V_114 ) ) {
V_187 = F_76 ( & V_8 -> V_114 , struct V_35 ,
V_111 ) ;
V_202 = F_174 ( V_187 -> V_201 . V_202 ) ;
if ( V_202 > V_312 )
break;
F_38 ( L_79 , V_202 ,
F_125 ( V_187 -> V_201 . type ) , V_187 ) ;
V_187 -> V_313 = V_314 ;
F_71 ( V_187 ) ;
}
F_147 ( V_8 ) ;
}
static int F_178 ( struct V_7 * V_8 ,
struct V_86 * V_315 ,
unsigned int V_316 , T_4 * V_197 )
{
int V_68 , V_265 ;
F_3 ( ! V_315 ) ;
while ( V_315 -> V_107 < V_316 ) {
F_3 ( V_315 -> V_106 == NULL ) ;
V_265 = V_316 - V_315 -> V_107 ;
V_68 = F_59 ( V_8 -> V_50 , ( char * ) V_315 -> V_106 +
V_315 -> V_107 , V_265 ) ;
if ( V_68 <= 0 )
return V_68 ;
V_315 -> V_107 += V_68 ;
}
if ( V_315 -> V_107 == V_316 )
* V_197 = F_126 ( 0 , V_315 -> V_106 , V_315 -> V_107 ) ;
return 1 ;
}
static int F_179 ( struct V_7 * V_8 )
{
struct V_35 * V_89 = V_8 -> V_115 ;
struct V_147 * V_148 = & V_89 -> V_148 ;
bool V_251 = ! F_56 ( F_57 ( V_8 -> V_30 ) , V_252 ) ;
struct V_95 * V_95 ;
T_1 V_96 ;
T_1 V_97 ;
T_4 V_197 = 0 ;
int V_68 ;
F_3 ( ! V_89 ) ;
if ( F_75 ( & V_89 -> V_143 ) )
return - V_317 ;
if ( V_251 )
V_197 = V_8 -> V_262 ;
while ( V_148 -> V_151 ) {
V_95 = F_115 ( V_148 , & V_96 , & V_97 , NULL ) ;
V_68 = F_61 ( V_8 -> V_50 , V_95 , V_96 , V_97 ) ;
if ( V_68 <= 0 ) {
if ( V_251 )
V_8 -> V_262 = V_197 ;
return V_68 ;
}
if ( V_251 )
V_197 = F_140 ( V_197 , V_95 , V_96 , V_68 ) ;
( void ) F_116 ( V_148 , ( T_1 ) V_68 ) ;
}
if ( V_251 )
V_8 -> V_262 = V_197 ;
return 1 ;
}
static int F_180 ( struct V_7 * V_8 )
{
struct V_35 * V_187 = V_8 -> V_115 ;
int V_105 ;
int V_263 ;
int V_68 ;
unsigned int V_203 , V_204 , V_186 ;
bool V_251 = ! F_56 ( F_57 ( V_8 -> V_30 ) , V_252 ) ;
bool V_318 = ( V_8 -> V_182 & V_183 ) ;
V_166 V_202 ;
T_4 V_197 ;
F_38 ( L_80 , V_8 , V_187 ) ;
V_105 = sizeof ( V_8 -> V_319 ) ;
V_263 = V_105 ;
V_68 = F_150 ( V_8 , V_263 , V_105 , & V_8 -> V_319 ) ;
if ( V_68 <= 0 )
return V_68 ;
V_197 = F_126 ( 0 , & V_8 -> V_319 , F_127 ( struct V_210 , V_197 ) ) ;
if ( F_128 ( V_197 ) != V_8 -> V_319 . V_197 ) {
F_30 ( L_81 ,
V_197 , V_8 -> V_319 . V_197 ) ;
return - V_320 ;
}
V_203 = F_124 ( V_8 -> V_319 . V_203 ) ;
if ( V_203 > V_321 )
return - V_317 ;
V_204 = F_124 ( V_8 -> V_319 . V_204 ) ;
if ( V_204 > V_322 )
return - V_317 ;
V_186 = F_124 ( V_8 -> V_319 . V_186 ) ;
if ( V_186 > V_323 )
return - V_317 ;
V_202 = F_174 ( V_8 -> V_319 . V_202 ) ;
if ( ( V_324 ) V_202 - ( V_324 ) V_8 -> V_119 < 1 ) {
F_166 ( L_82 ,
F_175 ( V_8 -> V_129 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_202 , V_8 -> V_119 + 1 ) ;
V_8 -> V_256 = - V_203 - V_204 - V_186 -
F_118 ( V_8 ) ;
V_8 -> V_257 = V_259 ;
return 1 ;
} else if ( ( V_324 ) V_202 - ( V_324 ) V_8 -> V_119 > 1 ) {
F_30 ( L_83 ,
V_202 , V_8 -> V_119 + 1 ) ;
V_8 -> V_272 = L_84 ;
return - V_325 ;
}
if ( ! V_8 -> V_115 ) {
int V_146 = 0 ;
F_38 ( L_85 , V_8 -> V_319 . type ,
V_203 , V_186 ) ;
V_68 = F_181 ( V_8 , & V_146 ) ;
if ( V_68 < 0 )
return V_68 ;
F_3 ( ! V_8 -> V_115 ^ V_146 ) ;
if ( V_146 ) {
F_38 ( L_86 ) ;
V_8 -> V_256 = - V_203 - V_204 - V_186 -
F_118 ( V_8 ) ;
V_8 -> V_257 = V_259 ;
V_8 -> V_119 ++ ;
return 1 ;
}
F_3 ( ! V_8 -> V_115 ) ;
F_3 ( V_8 -> V_115 -> V_8 != V_8 ) ;
V_187 = V_8 -> V_115 ;
V_187 -> V_205 . V_107 = 0 ;
if ( V_187 -> V_208 )
V_187 -> V_208 -> V_209 . V_107 = 0 ;
if ( V_186 )
F_119 ( V_8 -> V_115 , V_186 ) ;
}
V_68 = F_178 ( V_8 , & V_187 -> V_205 , V_203 ,
& V_8 -> V_260 ) ;
if ( V_68 <= 0 )
return V_68 ;
if ( V_187 -> V_208 ) {
V_68 = F_178 ( V_8 , & V_187 -> V_208 -> V_209 ,
V_204 ,
& V_8 -> V_261 ) ;
if ( V_68 <= 0 )
return V_68 ;
}
if ( V_186 ) {
V_68 = F_179 ( V_8 ) ;
if ( V_68 <= 0 )
return V_68 ;
}
if ( V_318 )
V_105 = sizeof( V_187 -> V_189 ) ;
else
V_105 = sizeof( V_187 -> V_193 ) ;
V_263 += V_105 ;
V_68 = F_150 ( V_8 , V_263 , V_105 , & V_187 -> V_189 ) ;
if ( V_68 <= 0 )
return V_68 ;
if ( ! V_318 ) {
V_187 -> V_189 . V_9 = V_187 -> V_193 . V_9 ;
V_187 -> V_189 . V_192 = 0 ;
}
F_38 ( L_87 ,
V_187 , V_203 , V_187 -> V_189 . V_211 , V_204 ,
V_187 -> V_189 . V_212 , V_186 , V_187 -> V_189 . V_213 ) ;
if ( V_8 -> V_260 != F_124 ( V_187 -> V_189 . V_211 ) ) {
F_30 ( L_88 ,
V_187 , V_8 -> V_260 , V_187 -> V_189 . V_211 ) ;
return - V_320 ;
}
if ( V_8 -> V_261 != F_124 ( V_187 -> V_189 . V_212 ) ) {
F_30 ( L_89 ,
V_187 , V_8 -> V_261 , V_187 -> V_189 . V_212 ) ;
return - V_320 ;
}
if ( V_251 &&
( V_187 -> V_189 . V_9 & V_254 ) == 0 &&
V_8 -> V_262 != F_124 ( V_187 -> V_189 . V_213 ) ) {
F_30 ( L_90 , V_187 ,
V_8 -> V_262 , F_124 ( V_187 -> V_189 . V_213 ) ) ;
return - V_320 ;
}
if ( V_318 && V_8 -> V_76 -> V_326 &&
V_8 -> V_76 -> V_326 ( V_187 ) ) {
F_30 ( L_91 , V_187 ) ;
return - V_320 ;
}
return 1 ;
}
static void F_182 ( struct V_7 * V_8 )
{
struct V_35 * V_89 = V_8 -> V_115 ;
F_3 ( V_8 -> V_115 -> V_8 != V_8 ) ;
V_8 -> V_115 = NULL ;
if ( V_8 -> V_129 . type == 0 )
V_8 -> V_129 = V_89 -> V_201 . V_327 ;
V_8 -> V_119 ++ ;
F_81 ( & V_8 -> V_122 ) ;
F_38 ( L_92 ,
V_89 , F_174 ( V_89 -> V_201 . V_202 ) ,
F_175 ( V_89 -> V_201 . V_327 ) ,
F_125 ( V_89 -> V_201 . type ) ,
F_183 ( F_125 ( V_89 -> V_201 . type ) ) ,
F_124 ( V_89 -> V_201 . V_203 ) ,
F_124 ( V_89 -> V_201 . V_186 ) ,
V_8 -> V_260 , V_8 -> V_261 , V_8 -> V_262 ) ;
V_8 -> V_76 -> V_328 ( V_8 , V_89 ) ;
F_79 ( & V_8 -> V_122 ) ;
}
static int F_184 ( struct V_7 * V_8 )
{
struct V_329 V_330 ;
T_1 V_105 = sizeof( V_330 ) ;
int V_68 = F_150 ( V_8 , V_105 , V_105 , & V_330 ) ;
if ( V_68 <= 0 )
return V_68 ;
F_185 ( & V_8 -> V_331 , & V_330 ) ;
F_147 ( V_8 ) ;
return 1 ;
}
static int F_186 ( struct V_7 * V_8 )
{
int V_68 = 1 ;
F_38 ( L_93 , V_8 , V_8 -> V_56 ) ;
V_101:
F_38 ( L_94 , V_8 -> V_140 ) ;
if ( V_8 -> V_56 == V_128 ) {
F_3 ( V_8 -> V_50 ) ;
V_8 -> V_56 = V_332 ;
F_92 ( V_8 ) ;
F_136 ( V_8 ) ;
F_143 ( V_8 ) ;
F_3 ( V_8 -> V_115 ) ;
V_8 -> V_257 = V_259 ;
F_38 ( L_95 ,
V_8 , V_8 -> V_56 ) ;
V_68 = F_50 ( V_8 ) ;
if ( V_68 < 0 ) {
V_8 -> V_272 = L_96 ;
goto V_250;
}
}
V_333:
if ( V_8 -> V_139 ) {
V_68 = F_139 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_250;
}
if ( V_8 -> V_121 ) {
V_68 = F_142 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_250;
}
if ( V_8 -> V_118 ) {
if ( V_8 -> V_196 ) {
F_73 ( V_8 -> V_118 ) ;
V_8 -> V_118 = NULL ;
goto V_334;
}
V_68 = F_141 ( V_8 ) ;
if ( V_68 == 1 )
goto V_333;
if ( V_68 == 0 )
goto V_250;
if ( V_68 < 0 ) {
F_38 ( L_97 ,
V_68 ) ;
goto V_250;
}
}
V_334:
if ( V_8 -> V_56 == V_308 ) {
if ( F_9 ( V_8 , V_3 ) ) {
F_131 ( V_8 ) ;
goto V_101;
}
if ( ! F_75 ( & V_8 -> V_113 ) ) {
F_121 ( V_8 ) ;
goto V_101;
}
if ( V_8 -> V_119 > V_8 -> V_120 ) {
F_129 ( V_8 ) ;
goto V_101;
}
}
F_2 ( V_8 , V_4 ) ;
F_38 ( L_98 ) ;
V_68 = 0 ;
V_250:
F_38 ( L_99 , V_8 , V_68 ) ;
return V_68 ;
}
static int F_187 ( struct V_7 * V_8 )
{
int V_68 = - 1 ;
V_101:
F_38 ( L_100 , V_8 , V_8 -> V_56 ) ;
if ( V_8 -> V_56 != V_332 &&
V_8 -> V_56 != V_230 &&
V_8 -> V_56 != V_308 )
return 0 ;
F_3 ( ! V_8 -> V_50 ) ;
F_38 ( L_101 , ( int ) V_8 -> V_257 ,
V_8 -> V_256 ) ;
if ( V_8 -> V_56 == V_332 ) {
F_38 ( L_102 ) ;
V_68 = F_151 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_250;
V_68 = F_169 ( V_8 ) ;
if ( V_68 < 0 )
goto V_250;
V_8 -> V_56 = V_230 ;
V_68 = F_137 ( V_8 ) ;
if ( V_68 < 0 )
goto V_250;
F_144 ( V_8 ) ;
goto V_250;
}
if ( V_8 -> V_56 == V_230 ) {
F_38 ( L_103 ) ;
V_68 = F_152 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_250;
V_68 = F_172 ( V_8 ) ;
if ( V_68 < 0 )
goto V_250;
goto V_101;
}
F_36 ( V_8 -> V_56 != V_308 ) ;
if ( V_8 -> V_256 < 0 ) {
static char V_84 [ V_335 ] ;
int V_146 = F_97 ( ( int ) sizeof ( V_84 ) , - V_8 -> V_256 ) ;
F_38 ( L_104 , V_146 , - V_8 -> V_256 ) ;
V_68 = F_59 ( V_8 -> V_50 , V_84 , V_146 ) ;
if ( V_68 <= 0 )
goto V_250;
V_8 -> V_256 += V_68 ;
if ( V_8 -> V_256 )
goto V_101;
}
if ( V_8 -> V_257 == V_259 ) {
V_68 = F_59 ( V_8 -> V_50 , & V_8 -> V_257 , 1 ) ;
if ( V_68 <= 0 )
goto V_250;
F_38 ( L_105 , ( int ) V_8 -> V_257 ) ;
switch ( V_8 -> V_257 ) {
case V_336 :
F_149 ( V_8 ) ;
break;
case V_337 :
F_145 ( V_8 ) ;
break;
case V_338 :
F_148 ( V_8 ) ;
break;
case V_339 :
F_70 ( V_8 ) ;
V_8 -> V_56 = V_123 ;
goto V_250;
default:
goto V_340;
}
}
if ( V_8 -> V_257 == V_336 ) {
V_68 = F_180 ( V_8 ) ;
if ( V_68 <= 0 ) {
switch ( V_68 ) {
case - V_320 :
V_8 -> V_272 = L_106 ;
case - V_325 :
V_68 = - V_317 ;
break;
case - V_317 :
V_8 -> V_272 = L_107 ;
break;
}
goto V_250;
}
if ( V_8 -> V_257 == V_259 )
goto V_101;
F_182 ( V_8 ) ;
if ( V_8 -> V_56 == V_308 )
F_147 ( V_8 ) ;
goto V_101;
}
if ( V_8 -> V_257 == V_337 ||
V_8 -> V_257 == V_258 ) {
V_68 = F_176 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_250;
F_177 ( V_8 ) ;
goto V_101;
}
if ( V_8 -> V_257 == V_338 ) {
V_68 = F_184 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_250;
goto V_101;
}
V_250:
F_38 ( L_108 , V_8 , V_68 ) ;
return V_68 ;
V_340:
F_30 ( L_109 , ( int ) V_8 -> V_257 ) ;
V_8 -> V_272 = L_110 ;
V_68 = - 1 ;
goto V_250;
}
static int F_188 ( struct V_7 * V_8 , unsigned long V_131 )
{
if ( ! V_8 -> V_76 -> V_341 ( V_8 ) ) {
F_38 ( L_111 , V_46 , V_8 ) ;
return - V_342 ;
}
if ( ! F_189 ( V_39 , & V_8 -> V_134 , V_131 ) ) {
F_38 ( L_112 , V_46 , V_8 ) ;
V_8 -> V_76 -> V_343 ( V_8 ) ;
return - V_344 ;
}
F_38 ( L_113 , V_46 , V_8 , V_131 ) ;
return 0 ;
}
static void F_45 ( struct V_7 * V_8 )
{
( void ) F_188 ( V_8 , 0 ) ;
}
static void F_80 ( struct V_7 * V_8 )
{
if ( F_190 ( & V_8 -> V_134 ) ) {
F_38 ( L_114 , V_46 , V_8 ) ;
V_8 -> V_76 -> V_343 ( V_8 ) ;
}
}
static bool F_191 ( struct V_7 * V_8 )
{
if ( ! F_9 ( V_8 , V_5 ) )
return false ;
#define CASE ( T_5 ) \
case CON_STATE_ ## x: \
con->error_msg = "socket closed (con state " #x ")"; \
break;
switch ( V_8 -> V_56 ) {
CASE ( V_345 ) ;
CASE ( V_346 ) ;
CASE ( V_347 ) ;
CASE ( V_348 ) ;
CASE ( V_349 ) ;
CASE ( V_350 ) ;
default:
F_171 ( L_115 ,
V_46 , V_8 , V_8 -> V_56 ) ;
V_8 -> V_272 = L_116 ;
F_117 () ;
break;
}
#undef CASE
return true ;
}
static bool F_192 ( struct V_7 * V_8 )
{
int V_68 ;
if ( ! F_9 ( V_8 , V_6 ) )
return false ;
V_68 = F_188 ( V_8 , F_193 ( V_8 -> V_131 ) ) ;
if ( V_68 ) {
F_38 ( L_117 , V_46 ,
V_8 , V_8 -> V_131 ) ;
F_3 ( V_68 == - V_342 ) ;
F_5 ( V_8 , V_6 ) ;
}
return true ;
}
static void F_194 ( struct V_7 * V_8 )
{
F_38 ( L_114 , V_46 , V_8 ) ;
if ( V_8 -> V_229 ) {
F_38 ( L_118 , V_8 -> V_229 ) ;
if ( V_8 -> V_76 -> V_351 )
V_8 -> V_76 -> V_351 ( V_8 ) ;
V_8 -> V_229 = 0 ;
}
if ( V_8 -> V_76 -> V_352 )
V_8 -> V_76 -> V_352 ( V_8 ) ;
}
static void V_135 ( struct V_353 * V_134 )
{
struct V_7 * V_8 = F_195 ( V_134 , struct V_7 ,
V_134 . V_134 ) ;
bool V_352 ;
F_79 ( & V_8 -> V_122 ) ;
while ( true ) {
int V_68 ;
if ( ( V_352 = F_191 ( V_8 ) ) ) {
F_38 ( L_119 , V_46 , V_8 ) ;
break;
}
if ( F_192 ( V_8 ) ) {
F_38 ( L_120 , V_46 , V_8 ) ;
break;
}
if ( V_8 -> V_56 == V_354 ) {
F_38 ( L_121 , V_46 , V_8 ) ;
break;
}
if ( V_8 -> V_56 == V_123 ) {
F_38 ( L_122 , V_46 , V_8 ) ;
F_3 ( V_8 -> V_50 ) ;
break;
}
if ( V_8 -> V_56 == V_128 ) {
F_38 ( L_123 , V_46 , V_8 ) ;
F_3 ( V_8 -> V_50 ) ;
}
V_68 = F_187 ( V_8 ) ;
if ( V_68 < 0 ) {
if ( V_68 == - V_94 )
continue;
if ( ! V_8 -> V_272 )
V_8 -> V_272 = L_124 ;
V_352 = true ;
break;
}
V_68 = F_186 ( V_8 ) ;
if ( V_68 < 0 ) {
if ( V_68 == - V_94 )
continue;
if ( ! V_8 -> V_272 )
V_8 -> V_272 = L_125 ;
V_352 = true ;
}
break;
}
if ( V_352 )
F_196 ( V_8 ) ;
F_81 ( & V_8 -> V_122 ) ;
if ( V_352 )
F_194 ( V_8 ) ;
V_8 -> V_76 -> V_343 ( V_8 ) ;
}
static void F_196 ( struct V_7 * V_8 )
{
F_38 ( L_126 ,
V_8 , V_8 -> V_56 , F_13 ( & V_8 -> V_66 . V_67 ) ) ;
F_171 ( L_127 , F_175 ( V_8 -> V_129 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) , V_8 -> V_272 ) ;
V_8 -> V_272 = NULL ;
F_36 ( V_8 -> V_56 != V_332 &&
V_8 -> V_56 != V_230 &&
V_8 -> V_56 != V_308 ) ;
F_70 ( V_8 ) ;
if ( F_7 ( V_8 , V_2 ) ) {
F_38 ( L_128 ) ;
V_8 -> V_56 = V_123 ;
return;
}
if ( V_8 -> V_115 ) {
F_3 ( V_8 -> V_115 -> V_8 != V_8 ) ;
F_73 ( V_8 -> V_115 ) ;
V_8 -> V_115 = NULL ;
}
F_197 ( & V_8 -> V_114 , & V_8 -> V_113 ) ;
if ( F_75 ( & V_8 -> V_113 ) &&
! F_7 ( V_8 , V_3 ) ) {
F_38 ( L_129 , V_8 ) ;
F_2 ( V_8 , V_4 ) ;
V_8 -> V_56 = V_354 ;
} else {
V_8 -> V_56 = V_128 ;
if ( V_8 -> V_131 == 0 )
V_8 -> V_131 = V_355 ;
else if ( V_8 -> V_131 < V_356 )
V_8 -> V_131 *= 2 ;
F_5 ( V_8 , V_6 ) ;
F_45 ( V_8 ) ;
}
}
void F_198 ( struct V_29 * V_30 ,
struct V_127 * V_357 )
{
F_199 ( & V_30 -> V_137 ) ;
if ( V_357 )
V_30 -> V_32 . V_33 = * V_357 ;
V_30 -> V_32 . V_33 . type = 0 ;
F_200 ( & V_30 -> V_32 . V_33 . V_296 , sizeof( V_30 -> V_32 . V_33 . V_296 ) ) ;
F_16 ( V_30 ) ;
F_201 ( & V_30 -> V_53 , 0 ) ;
F_202 ( & V_30 -> V_69 , F_203 ( V_358 -> V_359 -> V_360 ) ) ;
F_38 ( L_114 , V_46 , V_30 ) ;
}
void F_204 ( struct V_29 * V_30 )
{
F_205 ( F_52 ( & V_30 -> V_69 ) ) ;
}
static void F_206 ( struct V_35 * V_89 , struct V_7 * V_8 )
{
if ( V_89 -> V_8 )
V_89 -> V_8 -> V_76 -> V_343 ( V_89 -> V_8 ) ;
V_89 -> V_8 = V_8 ? V_8 -> V_76 -> V_341 ( V_8 ) : NULL ;
F_3 ( V_89 -> V_8 != V_8 ) ;
}
static void F_207 ( struct V_7 * V_8 )
{
if ( V_8 -> V_56 == V_354 ) {
F_38 ( L_130 , V_8 ) ;
V_8 -> V_56 = V_128 ;
V_8 -> V_116 ++ ;
F_36 ( F_7 ( V_8 , V_4 ) ) ;
F_36 ( F_7 ( V_8 , V_3 ) ) ;
}
}
void F_208 ( struct V_7 * V_8 , struct V_35 * V_89 )
{
V_89 -> V_201 . V_327 = V_8 -> V_30 -> V_32 . V_283 ;
F_3 ( V_89 -> V_205 . V_107 != F_124 ( V_89 -> V_201 . V_203 ) ) ;
V_89 -> V_200 = true ;
F_79 ( & V_8 -> V_122 ) ;
if ( V_8 -> V_56 == V_123 ) {
F_38 ( L_131 , V_8 , V_89 ) ;
F_73 ( V_89 ) ;
F_81 ( & V_8 -> V_122 ) ;
return;
}
F_206 ( V_89 , V_8 ) ;
F_3 ( ! F_75 ( & V_89 -> V_111 ) ) ;
F_209 ( & V_89 -> V_111 , & V_8 -> V_113 ) ;
F_38 ( L_132 , V_89 ,
F_175 ( V_8 -> V_129 ) , F_125 ( V_89 -> V_201 . type ) ,
F_183 ( F_125 ( V_89 -> V_201 . type ) ) ,
F_124 ( V_89 -> V_201 . V_203 ) ,
F_124 ( V_89 -> V_201 . V_204 ) ,
F_124 ( V_89 -> V_201 . V_186 ) ) ;
F_207 ( V_8 ) ;
F_81 ( & V_8 -> V_122 ) ;
if ( F_11 ( V_8 , V_4 ) == 0 )
F_45 ( V_8 ) ;
}
void F_210 ( struct V_35 * V_89 )
{
struct V_7 * V_8 = V_89 -> V_8 ;
if ( ! V_8 ) {
F_38 ( L_133 , V_46 , V_89 ) ;
return;
}
F_79 ( & V_8 -> V_122 ) ;
if ( ! F_75 ( & V_89 -> V_111 ) ) {
F_38 ( L_134 , V_46 , V_8 , V_89 ) ;
F_72 ( & V_89 -> V_111 ) ;
V_89 -> V_201 . V_202 = 0 ;
F_73 ( V_89 ) ;
}
if ( V_8 -> V_118 == V_89 ) {
F_3 ( V_8 -> V_121 ) ;
if ( V_8 -> V_196 ) {
V_8 -> V_121 += F_95 ( V_8 ) ;
} else {
F_3 ( ! V_89 -> V_178 ) ;
if ( V_8 -> V_182 & V_183 )
V_8 -> V_121 += sizeof( V_89 -> V_189 ) ;
else
V_8 -> V_121 += sizeof( V_89 -> V_193 ) ;
}
if ( V_89 -> V_178 )
V_8 -> V_121 += V_89 -> V_148 . V_175 ;
if ( V_89 -> V_208 )
V_8 -> V_121 += F_95 ( V_8 ) ;
V_8 -> V_121 += F_95 ( V_8 ) ;
F_38 ( L_135 ,
V_46 , V_8 , V_89 , V_8 -> V_140 , V_8 -> V_121 ) ;
V_89 -> V_201 . V_202 = 0 ;
V_8 -> V_118 = NULL ;
F_73 ( V_89 ) ;
}
F_81 ( & V_8 -> V_122 ) ;
}
void F_211 ( struct V_35 * V_89 )
{
struct V_7 * V_8 = V_89 -> V_8 ;
if ( ! V_8 ) {
F_38 ( L_133 , V_46 , V_89 ) ;
return;
}
F_79 ( & V_8 -> V_122 ) ;
if ( V_8 -> V_115 == V_89 ) {
unsigned int V_203 = F_124 ( V_8 -> V_319 . V_203 ) ;
unsigned int V_204 = F_124 ( V_8 -> V_319 . V_204 ) ;
unsigned int V_186 = F_124 ( V_8 -> V_319 . V_186 ) ;
F_38 ( L_136 , V_46 , V_8 , V_89 ) ;
V_8 -> V_256 = V_8 -> V_256 -
sizeof( struct V_210 ) -
V_203 -
V_204 -
V_186 -
sizeof( struct V_184 ) ;
F_73 ( V_8 -> V_115 ) ;
V_8 -> V_115 = NULL ;
V_8 -> V_257 = V_259 ;
V_8 -> V_119 ++ ;
} else {
F_38 ( L_137 ,
V_46 , V_8 , V_8 -> V_115 , V_89 ) ;
}
F_81 ( & V_8 -> V_122 ) ;
}
void F_212 ( struct V_7 * V_8 )
{
F_38 ( L_138 , V_8 ) ;
F_79 ( & V_8 -> V_122 ) ;
F_207 ( V_8 ) ;
F_81 ( & V_8 -> V_122 ) ;
if ( F_11 ( V_8 , V_3 ) == 0 &&
F_11 ( V_8 , V_4 ) == 0 )
F_45 ( V_8 ) ;
}
bool F_213 ( struct V_7 * V_8 ,
unsigned long V_361 )
{
if ( V_361 > 0 &&
( V_8 -> V_182 & V_214 ) ) {
struct V_215 V_216 = V_217 ;
struct V_215 V_362 ;
F_214 ( V_361 , & V_362 ) ;
V_362 = F_215 ( V_8 -> V_331 , V_362 ) ;
return F_216 ( & V_216 , & V_362 ) >= 0 ;
}
return false ;
}
static struct V_38 * F_217 ( enum V_363 type )
{
struct V_38 * V_143 ;
if ( F_36 ( ! F_218 ( type ) ) )
return NULL ;
V_143 = F_219 ( V_37 , V_73 ) ;
if ( V_143 )
V_143 -> type = type ;
F_87 ( & V_143 -> V_180 ) ;
return V_143 ;
}
static void F_220 ( struct V_38 * V_143 )
{
if ( ! V_143 )
return;
F_36 ( ! F_75 ( & V_143 -> V_180 ) ) ;
if ( V_143 -> type == V_173 )
F_221 ( V_143 -> V_172 ) ;
F_222 ( V_37 , V_143 ) ;
}
void F_223 ( struct V_35 * V_89 , struct V_95 * * V_164 ,
T_1 V_97 , T_1 V_165 )
{
struct V_38 * V_143 ;
F_3 ( ! V_164 ) ;
F_3 ( ! V_97 ) ;
V_143 = F_217 ( V_163 ) ;
F_3 ( ! V_143 ) ;
V_143 -> V_164 = V_164 ;
V_143 -> V_97 = V_97 ;
V_143 -> V_165 = V_165 & ~ V_167 ;
F_209 ( & V_143 -> V_180 , & V_89 -> V_143 ) ;
V_89 -> V_178 += V_97 ;
}
void F_224 ( struct V_35 * V_89 ,
struct V_171 * V_172 )
{
struct V_38 * V_143 ;
F_3 ( ! V_172 ) ;
F_3 ( ! V_172 -> V_97 ) ;
V_143 = F_217 ( V_173 ) ;
F_3 ( ! V_143 ) ;
V_143 -> V_172 = V_172 ;
F_209 ( & V_143 -> V_180 , & V_89 -> V_143 ) ;
V_89 -> V_178 += V_172 -> V_97 ;
}
void F_225 ( struct V_35 * V_89 , struct V_149 * V_149 ,
T_1 V_97 )
{
struct V_38 * V_143 ;
F_3 ( ! V_149 ) ;
V_143 = F_217 ( V_150 ) ;
F_3 ( ! V_143 ) ;
V_143 -> V_149 = V_149 ;
V_143 -> V_152 = V_97 ;
F_209 ( & V_143 -> V_180 , & V_89 -> V_143 ) ;
V_89 -> V_178 += V_97 ;
}
struct V_35 * F_226 ( int type , int V_203 , T_6 V_9 ,
bool V_364 )
{
struct V_35 * V_187 ;
V_187 = F_219 ( V_34 , V_9 ) ;
if ( V_187 == NULL )
goto V_250;
V_187 -> V_201 . type = F_227 ( type ) ;
V_187 -> V_201 . V_365 = F_227 ( V_366 ) ;
V_187 -> V_201 . V_203 = F_128 ( V_203 ) ;
F_87 ( & V_187 -> V_111 ) ;
F_228 ( & V_187 -> V_367 ) ;
F_87 ( & V_187 -> V_143 ) ;
if ( V_203 ) {
V_187 -> V_205 . V_106 = F_229 ( V_203 , V_9 ) ;
if ( V_187 -> V_205 . V_106 == NULL ) {
F_38 ( L_139 ,
V_203 ) ;
goto V_368;
}
} else {
V_187 -> V_205 . V_106 = NULL ;
}
V_187 -> V_369 = V_187 -> V_205 . V_107 = V_203 ;
F_38 ( L_140 , V_187 , V_203 ) ;
return V_187 ;
V_368:
F_73 ( V_187 ) ;
V_250:
if ( ! V_364 ) {
F_30 ( L_141 , type ,
V_203 ) ;
F_36 ( 1 ) ;
} else {
F_38 ( L_141 , type ,
V_203 ) ;
}
return NULL ;
}
static int F_230 ( struct V_7 * V_8 , struct V_35 * V_89 )
{
int type = F_125 ( V_89 -> V_201 . type ) ;
int V_204 = F_124 ( V_89 -> V_201 . V_204 ) ;
F_38 ( L_142 , V_89 , type ,
F_183 ( type ) , V_204 ) ;
F_3 ( ! V_204 ) ;
F_3 ( V_89 -> V_208 ) ;
V_89 -> V_208 = F_231 ( V_204 , V_73 ) ;
if ( ! V_89 -> V_208 )
return - V_36 ;
return 0 ;
}
static int F_181 ( struct V_7 * V_8 , int * V_146 )
{
struct V_210 * V_201 = & V_8 -> V_319 ;
int V_204 = F_124 ( V_201 -> V_204 ) ;
struct V_35 * V_89 ;
int V_68 = 0 ;
F_3 ( V_8 -> V_115 != NULL ) ;
F_3 ( ! V_8 -> V_76 -> V_370 ) ;
F_81 ( & V_8 -> V_122 ) ;
V_89 = V_8 -> V_76 -> V_370 ( V_8 , V_201 , V_146 ) ;
F_79 ( & V_8 -> V_122 ) ;
if ( V_8 -> V_56 != V_308 ) {
if ( V_89 )
F_73 ( V_89 ) ;
return - V_94 ;
}
if ( V_89 ) {
F_3 ( * V_146 ) ;
F_206 ( V_89 , V_8 ) ;
V_8 -> V_115 = V_89 ;
} else {
if ( * V_146 )
return 0 ;
V_8 -> V_272 = L_143 ;
return - V_36 ;
}
memcpy ( & V_8 -> V_115 -> V_201 , & V_8 -> V_319 , sizeof( V_8 -> V_319 ) ) ;
if ( V_204 && ! V_8 -> V_115 -> V_208 ) {
V_68 = F_230 ( V_8 , V_8 -> V_115 ) ;
if ( V_68 < 0 ) {
F_73 ( V_8 -> V_115 ) ;
V_8 -> V_115 = NULL ;
}
}
return V_68 ;
}
static void F_232 ( struct V_35 * V_187 )
{
F_38 ( L_114 , V_46 , V_187 ) ;
F_233 ( V_187 -> V_205 . V_106 ) ;
F_222 ( V_34 , V_187 ) ;
}
static void F_234 ( struct V_367 * V_367 )
{
struct V_35 * V_187 = F_195 ( V_367 , struct V_35 , V_367 ) ;
struct V_38 * V_143 , * V_371 ;
F_38 ( L_114 , V_46 , V_187 ) ;
F_36 ( ! F_75 ( & V_187 -> V_111 ) ) ;
F_206 ( V_187 , NULL ) ;
if ( V_187 -> V_208 ) {
F_235 ( V_187 -> V_208 ) ;
V_187 -> V_208 = NULL ;
}
F_236 (data, next, &m->data, links) {
F_72 ( & V_143 -> V_180 ) ;
F_220 ( V_143 ) ;
}
V_187 -> V_178 = 0 ;
if ( V_187 -> V_372 )
F_237 ( V_187 -> V_372 , V_187 ) ;
else
F_232 ( V_187 ) ;
}
struct V_35 * F_122 ( struct V_35 * V_89 )
{
F_38 ( L_144 , V_46 , V_89 ,
F_44 ( & V_89 -> V_367 . V_373 ) ) ;
F_238 ( & V_89 -> V_367 ) ;
return V_89 ;
}
void F_73 ( struct V_35 * V_89 )
{
F_38 ( L_144 , V_46 , V_89 ,
F_44 ( & V_89 -> V_367 . V_373 ) ) ;
F_239 ( & V_89 -> V_367 , F_234 ) ;
}
void F_240 ( struct V_35 * V_89 )
{
F_241 ( L_145 , V_89 ,
V_89 -> V_369 , V_89 -> V_178 ) ;
F_242 ( V_374 , L_146 ,
V_375 , 16 , 1 ,
& V_89 -> V_201 , sizeof( V_89 -> V_201 ) , true ) ;
F_242 ( V_374 , L_147 ,
V_375 , 16 , 1 ,
V_89 -> V_205 . V_106 , V_89 -> V_205 . V_107 , true ) ;
if ( V_89 -> V_208 )
F_242 ( V_374 , L_148 ,
V_375 , 16 , 1 ,
V_89 -> V_208 -> V_209 . V_106 ,
V_89 -> V_208 -> V_209 . V_107 , true ) ;
F_242 ( V_374 , L_149 ,
V_375 , 16 , 1 ,
& V_89 -> V_189 , sizeof( V_89 -> V_189 ) , true ) ;
}
