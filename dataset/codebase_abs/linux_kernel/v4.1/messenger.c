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
V_39 = F_30 ( L_6 , V_41 , 0 ) ;
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
int V_42 ;
V_42 = F_36 ( & V_8 -> V_43 , V_44 ) ;
if ( F_37 ( V_42 != V_45 ) )
F_38 ( L_8 , V_46 , V_42 ) ;
F_39 ( L_9 , V_46 , V_8 , V_42 ,
V_44 ) ;
}
static void F_40 ( struct V_7 * V_8 )
{
int V_42 ;
V_42 = F_36 ( & V_8 -> V_43 , V_47 ) ;
if ( F_37 ( V_42 != V_44 ) )
F_38 ( L_8 , V_46 , V_42 ) ;
F_39 ( L_9 , V_46 , V_8 , V_42 ,
V_47 ) ;
}
static void F_41 ( struct V_7 * V_8 )
{
int V_42 ;
V_42 = F_36 ( & V_8 -> V_43 , V_48 ) ;
if ( F_37 ( V_42 != V_47 ) )
F_38 ( L_8 , V_46 , V_42 ) ;
F_39 ( L_9 , V_46 , V_8 , V_42 ,
V_48 ) ;
}
static void F_42 ( struct V_7 * V_8 )
{
int V_42 ;
V_42 = F_36 ( & V_8 -> V_43 , V_49 ) ;
if ( F_37 ( V_42 != V_47 &&
V_42 != V_48 &&
V_42 != V_49 ) )
F_38 ( L_8 , V_46 , V_42 ) ;
F_39 ( L_9 , V_46 , V_8 , V_42 ,
V_49 ) ;
}
static void F_43 ( struct V_7 * V_8 )
{
int V_42 ;
V_42 = F_36 ( & V_8 -> V_43 , V_44 ) ;
if ( F_37 ( V_42 != V_48 &&
V_42 != V_49 &&
V_42 != V_47 &&
V_42 != V_44 ) )
F_38 ( L_8 , V_46 , V_42 ) ;
F_39 ( L_9 , V_46 , V_8 , V_42 ,
V_44 ) ;
}
static void F_44 ( struct V_50 * V_51 )
{
struct V_7 * V_8 = V_51 -> V_52 ;
if ( F_45 ( & V_8 -> V_30 -> V_53 ) ) {
return;
}
if ( V_51 -> V_54 != V_55 ) {
F_39 ( L_10 , V_46 ,
V_8 , V_8 -> V_56 ) ;
F_46 ( V_8 ) ;
}
}
static void F_47 ( struct V_50 * V_51 )
{
struct V_7 * V_8 = V_51 -> V_52 ;
if ( F_7 ( V_8 , V_4 ) ) {
if ( F_48 ( V_51 ) ) {
F_39 ( L_11 , V_46 , V_8 ) ;
F_4 ( V_57 , & V_51 -> V_58 -> V_9 ) ;
F_46 ( V_8 ) ;
}
} else {
F_39 ( L_12 , V_46 , V_8 ) ;
}
}
static void F_49 ( struct V_50 * V_51 )
{
struct V_7 * V_8 = V_51 -> V_52 ;
F_39 ( L_13 , V_46 ,
V_8 , V_8 -> V_56 , V_51 -> V_54 ) ;
switch ( V_51 -> V_54 ) {
case V_59 :
F_39 ( L_14 , V_46 ) ;
case V_55 :
F_39 ( L_15 , V_46 ) ;
F_42 ( V_8 ) ;
F_5 ( V_8 , V_5 ) ;
F_46 ( V_8 ) ;
break;
case V_60 :
F_39 ( L_16 , V_46 ) ;
F_41 ( V_8 ) ;
F_46 ( V_8 ) ;
break;
default:
break;
}
}
static void F_50 ( struct V_61 * V_50 ,
struct V_7 * V_8 )
{
struct V_50 * V_51 = V_50 -> V_51 ;
V_51 -> V_52 = V_8 ;
V_51 -> V_62 = F_44 ;
V_51 -> V_63 = F_47 ;
V_51 -> V_64 = F_49 ;
}
static int F_51 ( struct V_7 * V_8 )
{
struct V_10 * V_65 = & V_8 -> V_66 . V_67 ;
struct V_61 * V_50 ;
int V_68 ;
F_3 ( V_8 -> V_50 ) ;
V_68 = F_52 ( V_8 -> V_66 . V_67 . V_21 , V_69 ,
V_70 , & V_50 ) ;
if ( V_68 )
return V_68 ;
V_50 -> V_51 -> V_71 = V_72 ;
#ifdef F_53
F_54 ( & V_50 -> V_51 -> V_73 , & V_74 ) ;
#endif
F_50 ( V_50 , V_8 ) ;
F_39 ( L_17 , F_13 ( & V_8 -> V_66 . V_67 ) ) ;
F_40 ( V_8 ) ;
V_68 = V_50 -> V_75 -> V_76 ( V_50 , (struct V_77 * ) V_65 , sizeof( * V_65 ) ,
V_78 ) ;
if ( V_68 == - V_79 ) {
F_39 ( L_18 ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_50 -> V_51 -> V_54 ) ;
} else if ( V_68 < 0 ) {
F_31 ( L_19 ,
F_13 ( & V_8 -> V_66 . V_67 ) , V_68 ) ;
F_55 ( V_50 ) ;
return V_68 ;
}
if ( V_8 -> V_30 -> V_80 ) {
int V_81 = 1 ;
V_68 = F_56 ( V_50 , V_82 , V_83 ,
( char * ) & V_81 , sizeof( V_81 ) ) ;
if ( V_68 )
F_31 ( L_20 ,
V_68 ) ;
}
V_8 -> V_50 = V_50 ;
return 0 ;
}
static int F_57 ( struct V_61 * V_50 , void * V_84 , T_1 V_85 )
{
struct V_86 V_87 = { V_84 , V_85 } ;
struct V_88 V_89 = { . V_90 = V_91 | V_92 } ;
int V_93 ;
V_93 = F_58 ( V_50 , & V_89 , & V_87 , 1 , V_85 , V_89 . V_90 ) ;
if ( V_93 == - V_94 )
V_93 = 0 ;
return V_93 ;
}
static int F_59 ( struct V_61 * V_50 , struct V_95 * V_95 ,
int V_96 , T_1 V_97 )
{
void * V_98 ;
int V_68 ;
F_3 ( V_96 + V_97 > V_99 ) ;
V_98 = F_60 ( V_95 ) ;
F_3 ( ! V_98 ) ;
V_68 = F_57 ( V_50 , V_98 + V_96 , V_97 ) ;
F_25 ( V_95 ) ;
return V_68 ;
}
static int F_61 ( struct V_61 * V_50 , struct V_86 * V_87 ,
T_1 V_100 , T_1 V_85 , int V_101 )
{
struct V_88 V_89 = { . V_90 = V_91 | V_92 } ;
int V_93 ;
if ( V_101 )
V_89 . V_90 |= V_102 ;
else
V_89 . V_90 |= V_103 ;
V_93 = F_62 ( V_50 , & V_89 , V_87 , V_100 , V_85 ) ;
if ( V_93 == - V_94 )
V_93 = 0 ;
return V_93 ;
}
static int F_63 ( struct V_61 * V_50 , struct V_95 * V_95 ,
int V_104 , T_1 V_105 , bool V_101 )
{
int V_9 = V_91 | V_92 | ( V_101 ? V_102 : V_103 ) ;
int V_68 ;
V_68 = F_64 ( V_50 , V_95 , V_104 , V_105 , V_9 ) ;
if ( V_68 == - V_94 )
V_68 = 0 ;
return V_68 ;
}
static int F_65 ( struct V_61 * V_50 , struct V_95 * V_95 ,
int V_104 , T_1 V_105 , bool V_101 )
{
int V_68 ;
struct V_86 V_87 ;
if ( F_66 ( V_95 ) >= 1 )
return F_63 ( V_50 , V_95 , V_104 , V_105 , V_101 ) ;
V_87 . V_106 = F_60 ( V_95 ) + V_104 ;
V_87 . V_107 = V_105 ;
V_68 = F_61 ( V_50 , & V_87 , 1 , V_105 , V_101 ) ;
F_25 ( V_95 ) ;
return V_68 ;
}
static int F_67 ( struct V_7 * V_8 )
{
int V_108 = 0 ;
F_39 ( L_21 , V_8 , V_8 -> V_50 ) ;
if ( V_8 -> V_50 ) {
V_108 = V_8 -> V_50 -> V_75 -> V_109 ( V_8 -> V_50 , V_110 ) ;
F_55 ( V_8 -> V_50 ) ;
V_8 -> V_50 = NULL ;
}
F_2 ( V_8 , V_5 ) ;
F_43 ( V_8 ) ;
return V_108 ;
}
static void F_68 ( struct V_35 * V_89 )
{
F_69 ( & V_89 -> V_111 ) ;
F_3 ( V_89 -> V_8 == NULL ) ;
V_89 -> V_8 -> V_75 -> V_112 ( V_89 -> V_8 ) ;
V_89 -> V_8 = NULL ;
F_70 ( V_89 ) ;
}
static void F_71 ( struct V_111 * V_113 )
{
while ( ! F_72 ( V_113 ) ) {
struct V_35 * V_89 = F_73 ( V_113 , struct V_35 ,
V_111 ) ;
F_68 ( V_89 ) ;
}
}
static void F_74 ( struct V_7 * V_8 )
{
F_39 ( L_22 , V_8 ) ;
F_71 ( & V_8 -> V_114 ) ;
F_71 ( & V_8 -> V_115 ) ;
if ( V_8 -> V_116 ) {
F_3 ( V_8 -> V_116 -> V_8 != V_8 ) ;
V_8 -> V_116 -> V_8 = NULL ;
F_70 ( V_8 -> V_116 ) ;
V_8 -> V_116 = NULL ;
V_8 -> V_75 -> V_112 ( V_8 ) ;
}
V_8 -> V_117 = 0 ;
V_8 -> V_118 = 0 ;
if ( V_8 -> V_119 ) {
F_70 ( V_8 -> V_119 ) ;
V_8 -> V_119 = NULL ;
}
V_8 -> V_120 = 0 ;
V_8 -> V_121 = 0 ;
}
void F_75 ( struct V_7 * V_8 )
{
F_76 ( & V_8 -> V_122 ) ;
F_39 ( L_23 , V_8 ,
F_13 ( & V_8 -> V_66 . V_67 ) ) ;
V_8 -> V_56 = V_123 ;
F_2 ( V_8 , V_2 ) ;
F_2 ( V_8 , V_3 ) ;
F_2 ( V_8 , V_4 ) ;
F_2 ( V_8 , V_6 ) ;
F_74 ( V_8 ) ;
V_8 -> V_124 = 0 ;
F_77 ( V_8 ) ;
F_67 ( V_8 ) ;
F_78 ( & V_8 -> V_122 ) ;
}
void F_79 ( struct V_7 * V_8 ,
T_2 V_125 , T_3 V_126 ,
struct V_127 * V_33 )
{
F_76 ( & V_8 -> V_122 ) ;
F_39 ( L_24 , V_8 , F_13 ( & V_33 -> V_67 ) ) ;
F_37 ( V_8 -> V_56 != V_123 ) ;
V_8 -> V_56 = V_128 ;
V_8 -> V_129 . type = ( T_2 ) V_125 ;
V_8 -> V_129 . V_130 = F_80 ( V_126 ) ;
memcpy ( & V_8 -> V_66 , V_33 , sizeof( * V_33 ) ) ;
V_8 -> V_131 = 0 ;
F_78 ( & V_8 -> V_122 ) ;
F_46 ( V_8 ) ;
}
bool F_81 ( struct V_7 * V_8 )
{
return V_8 -> V_117 > 0 ;
}
void F_82 ( struct V_7 * V_8 , void * V_132 ,
const struct V_133 * V_75 ,
struct V_29 * V_30 )
{
F_39 ( L_25 , V_8 ) ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> V_132 = V_132 ;
V_8 -> V_75 = V_75 ;
V_8 -> V_30 = V_30 ;
F_35 ( V_8 ) ;
F_83 ( & V_8 -> V_122 ) ;
F_84 ( & V_8 -> V_114 ) ;
F_84 ( & V_8 -> V_115 ) ;
F_85 ( & V_8 -> V_134 , V_135 ) ;
V_8 -> V_56 = V_123 ;
}
static T_4 F_86 ( struct V_29 * V_30 , T_4 V_136 )
{
T_4 V_68 ;
F_87 ( & V_30 -> V_137 ) ;
if ( V_30 -> V_138 < V_136 )
V_30 -> V_138 = V_136 ;
V_68 = ++ V_30 -> V_138 ;
F_88 ( & V_30 -> V_137 ) ;
return V_68 ;
}
static void F_89 ( struct V_7 * V_8 )
{
V_8 -> V_139 = 0 ;
V_8 -> V_140 = 0 ;
V_8 -> V_141 = & V_8 -> V_142 [ 0 ] ;
}
static void F_90 ( struct V_7 * V_8 ,
T_1 V_105 , void * V_143 )
{
int V_144 ;
V_144 = V_8 -> V_139 ;
F_3 ( V_144 >= F_91 ( V_8 -> V_142 ) ) ;
V_8 -> V_142 [ V_144 ] . V_107 = V_105 ;
V_8 -> V_142 [ V_144 ] . V_106 = V_143 ;
V_8 -> V_139 ++ ;
V_8 -> V_140 += V_105 ;
}
static void F_92 ( struct V_145 * V_146 ,
T_1 V_97 )
{
struct V_38 * V_143 = V_146 -> V_143 ;
struct V_147 * V_147 ;
F_3 ( V_143 -> type != V_148 ) ;
V_147 = V_143 -> V_147 ;
F_3 ( ! V_147 ) ;
V_146 -> V_149 = F_93 ( V_97 , V_143 -> V_150 ) ;
V_146 -> V_147 = V_147 ;
V_146 -> V_151 = V_147 -> V_152 ;
V_146 -> V_153 =
V_146 -> V_149 <= F_94 ( V_147 , V_146 -> V_151 ) ;
}
static struct V_95 * F_95 ( struct V_145 * V_146 ,
T_1 * V_96 ,
T_1 * V_97 )
{
struct V_38 * V_143 = V_146 -> V_143 ;
struct V_147 * V_147 ;
struct V_154 V_154 ;
F_3 ( V_143 -> type != V_148 ) ;
V_147 = V_146 -> V_147 ;
F_3 ( ! V_147 ) ;
V_154 = F_96 ( V_147 , V_146 -> V_151 ) ;
* V_96 = ( T_1 ) V_154 . V_155 ;
F_3 ( * V_96 >= V_99 ) ;
if ( V_146 -> V_153 )
* V_97 = V_146 -> V_149 ;
else
* V_97 = ( T_1 ) V_154 . V_156 ;
F_3 ( * V_97 > V_146 -> V_149 ) ;
F_3 ( * V_96 + * V_97 > V_99 ) ;
return V_154 . V_157 ;
}
static bool F_97 ( struct V_145 * V_146 ,
T_1 V_158 )
{
struct V_147 * V_147 ;
struct V_154 V_154 ;
F_3 ( V_146 -> V_143 -> type != V_148 ) ;
V_147 = V_146 -> V_147 ;
F_3 ( ! V_147 ) ;
V_154 = F_96 ( V_147 , V_146 -> V_151 ) ;
F_3 ( V_146 -> V_149 < V_158 ) ;
V_146 -> V_149 -= V_158 ;
F_98 ( V_147 , & V_146 -> V_151 , V_158 ) ;
if ( V_158 < V_154 . V_156 )
return false ;
if ( ! V_146 -> V_151 . V_159 ) {
V_147 = V_147 -> V_160 ;
V_146 -> V_147 = V_147 ;
if ( V_147 )
V_146 -> V_151 = V_147 -> V_152 ;
else
memset ( & V_146 -> V_151 , 0 ,
sizeof( V_146 -> V_151 ) ) ;
}
if ( ! V_146 -> V_153 ) {
F_3 ( ! V_146 -> V_149 ) ;
F_3 ( ! V_147 ) ;
if ( V_146 -> V_149 <= F_94 ( V_147 , V_146 -> V_151 ) )
V_146 -> V_153 = true ;
}
return true ;
}
static void F_99 ( struct V_145 * V_146 ,
T_1 V_97 )
{
struct V_38 * V_143 = V_146 -> V_143 ;
int F_66 ;
F_3 ( V_143 -> type != V_161 ) ;
F_3 ( ! V_143 -> V_162 ) ;
F_3 ( ! V_143 -> V_97 ) ;
V_146 -> V_149 = F_93 ( V_97 , V_143 -> V_97 ) ;
F_66 = F_100 ( V_143 -> V_163 , ( V_164 ) V_143 -> V_97 ) ;
V_146 -> V_96 = V_143 -> V_163 & ~ V_165 ;
V_146 -> V_166 = 0 ;
F_3 ( F_66 > ( int ) V_167 ) ;
V_146 -> F_66 = ( unsigned short ) F_66 ;
F_3 ( V_97 > V_168 - V_146 -> V_96 ) ;
V_146 -> V_153 = V_146 -> V_96 + V_146 -> V_149 <= V_99 ;
}
static struct V_95 *
F_101 ( struct V_145 * V_146 ,
T_1 * V_96 , T_1 * V_97 )
{
struct V_38 * V_143 = V_146 -> V_143 ;
F_3 ( V_143 -> type != V_161 ) ;
F_3 ( V_146 -> V_166 >= V_146 -> F_66 ) ;
F_3 ( V_146 -> V_96 >= V_99 ) ;
* V_96 = V_146 -> V_96 ;
if ( V_146 -> V_153 )
* V_97 = V_146 -> V_149 ;
else
* V_97 = V_99 - * V_96 ;
return V_143 -> V_162 [ V_146 -> V_166 ] ;
}
static bool F_102 ( struct V_145 * V_146 ,
T_1 V_158 )
{
F_3 ( V_146 -> V_143 -> type != V_161 ) ;
F_3 ( V_146 -> V_96 + V_158 > V_99 ) ;
V_146 -> V_149 -= V_158 ;
V_146 -> V_96 = ( V_146 -> V_96 + V_158 ) & ~ V_165 ;
if ( ! V_158 || V_146 -> V_96 )
return false ;
if ( ! V_146 -> V_149 )
return false ;
F_3 ( V_146 -> V_166 >= V_146 -> F_66 ) ;
V_146 -> V_166 ++ ;
V_146 -> V_153 = V_146 -> V_149 <= V_99 ;
return true ;
}
static void
F_103 ( struct V_145 * V_146 ,
T_1 V_97 )
{
struct V_38 * V_143 = V_146 -> V_143 ;
struct V_169 * V_170 ;
struct V_95 * V_95 ;
F_3 ( V_143 -> type != V_171 ) ;
V_170 = V_143 -> V_170 ;
F_3 ( ! V_170 ) ;
if ( ! V_97 )
return;
F_3 ( F_72 ( & V_170 -> V_113 ) ) ;
V_95 = F_73 ( & V_170 -> V_113 , struct V_95 , V_172 ) ;
V_146 -> V_149 = F_93 ( V_97 , V_170 -> V_97 ) ;
V_146 -> V_95 = V_95 ;
V_146 -> V_104 = 0 ;
V_146 -> V_153 = V_146 -> V_149 <= V_99 ;
}
static struct V_95 *
F_104 ( struct V_145 * V_146 ,
T_1 * V_96 , T_1 * V_97 )
{
struct V_38 * V_143 = V_146 -> V_143 ;
struct V_169 * V_170 ;
F_3 ( V_143 -> type != V_171 ) ;
V_170 = V_143 -> V_170 ;
F_3 ( ! V_170 ) ;
F_3 ( ! V_146 -> V_95 ) ;
F_3 ( V_146 -> V_104 + V_146 -> V_149 != V_170 -> V_97 ) ;
* V_96 = V_146 -> V_104 & ~ V_165 ;
if ( V_146 -> V_153 )
* V_97 = V_146 -> V_149 ;
else
* V_97 = V_99 - * V_96 ;
return V_146 -> V_95 ;
}
static bool F_105 ( struct V_145 * V_146 ,
T_1 V_158 )
{
struct V_38 * V_143 = V_146 -> V_143 ;
struct V_169 * V_170 ;
F_3 ( V_143 -> type != V_171 ) ;
V_170 = V_143 -> V_170 ;
F_3 ( ! V_170 ) ;
F_3 ( V_146 -> V_104 + V_146 -> V_149 != V_170 -> V_97 ) ;
F_3 ( ( V_146 -> V_104 & ~ V_165 ) + V_158 > V_99 ) ;
V_146 -> V_149 -= V_158 ;
V_146 -> V_104 += V_158 ;
if ( ! V_158 || V_146 -> V_104 & ~ V_165 )
return false ;
if ( ! V_146 -> V_149 )
return false ;
F_3 ( F_106 ( & V_146 -> V_95 -> V_172 , & V_170 -> V_113 ) ) ;
V_146 -> V_95 = F_107 ( V_146 -> V_95 , V_172 ) ;
V_146 -> V_153 = V_146 -> V_149 <= V_99 ;
return true ;
}
static void F_108 ( struct V_145 * V_146 )
{
T_1 V_97 = V_146 -> V_173 ;
switch ( V_146 -> V_143 -> type ) {
case V_171 :
F_103 ( V_146 , V_97 ) ;
break;
case V_161 :
F_99 ( V_146 , V_97 ) ;
break;
#ifdef F_109
case V_148 :
F_92 ( V_146 , V_97 ) ;
break;
#endif
case V_174 :
default:
break;
}
V_146 -> V_175 = true ;
}
static void F_110 ( struct V_35 * V_89 , T_1 V_97 )
{
struct V_145 * V_146 = & V_89 -> V_146 ;
struct V_38 * V_143 ;
F_3 ( ! V_97 ) ;
F_3 ( V_97 > V_89 -> V_176 ) ;
F_3 ( F_72 ( & V_89 -> V_143 ) ) ;
V_146 -> V_177 = & V_89 -> V_143 ;
V_146 -> V_173 = V_97 ;
V_143 = F_73 ( & V_89 -> V_143 , struct V_38 , V_178 ) ;
V_146 -> V_143 = V_143 ;
F_108 ( V_146 ) ;
}
static struct V_95 * F_111 ( struct V_145 * V_146 ,
T_1 * V_96 , T_1 * V_97 ,
bool * V_153 )
{
struct V_95 * V_95 ;
switch ( V_146 -> V_143 -> type ) {
case V_171 :
V_95 = F_104 ( V_146 , V_96 , V_97 ) ;
break;
case V_161 :
V_95 = F_101 ( V_146 , V_96 , V_97 ) ;
break;
#ifdef F_109
case V_148 :
V_95 = F_95 ( V_146 , V_96 , V_97 ) ;
break;
#endif
case V_174 :
default:
V_95 = NULL ;
break;
}
F_3 ( ! V_95 ) ;
F_3 ( * V_96 + * V_97 > V_99 ) ;
F_3 ( ! * V_97 ) ;
if ( V_153 )
* V_153 = V_146 -> V_153 ;
return V_95 ;
}
static bool F_112 ( struct V_145 * V_146 ,
T_1 V_158 )
{
bool V_179 ;
F_3 ( V_158 > V_146 -> V_149 ) ;
switch ( V_146 -> V_143 -> type ) {
case V_171 :
V_179 = F_105 ( V_146 , V_158 ) ;
break;
case V_161 :
V_179 = F_102 ( V_146 , V_158 ) ;
break;
#ifdef F_109
case V_148 :
V_179 = F_97 ( V_146 , V_158 ) ;
break;
#endif
case V_174 :
default:
F_113 () ;
break;
}
V_146 -> V_173 -= V_158 ;
if ( ! V_146 -> V_149 && V_146 -> V_173 ) {
F_37 ( ! V_146 -> V_153 ) ;
F_3 ( F_106 ( & V_146 -> V_143 -> V_178 , V_146 -> V_177 ) ) ;
V_146 -> V_143 = F_107 ( V_146 -> V_143 , V_178 ) ;
F_108 ( V_146 ) ;
V_179 = true ;
}
V_146 -> V_175 = V_179 ;
return V_179 ;
}
static void F_114 ( struct V_35 * V_89 , T_4 V_180 )
{
F_3 ( ! V_89 ) ;
F_3 ( ! V_180 ) ;
F_110 ( V_89 , ( T_1 ) V_180 ) ;
}
static void F_115 ( struct V_7 * V_8 )
{
struct V_35 * V_181 = V_8 -> V_119 ;
int V_182 = V_8 -> V_139 ;
V_181 -> V_183 . V_9 |= V_184 ;
F_39 ( L_26 , V_8 ) ;
V_8 -> V_185 = true ;
V_8 -> V_142 [ V_182 ] . V_106 = & V_181 -> V_183 ;
if ( V_8 -> V_186 & V_187 ) {
if ( V_8 -> V_75 -> V_188 )
V_8 -> V_75 -> V_188 ( V_8 , V_181 ) ;
else
V_181 -> V_183 . V_189 = 0 ;
V_8 -> V_142 [ V_182 ] . V_107 = sizeof( V_181 -> V_183 ) ;
V_8 -> V_140 += sizeof( V_181 -> V_183 ) ;
} else {
V_181 -> V_190 . V_9 = V_181 -> V_183 . V_9 ;
V_8 -> V_142 [ V_182 ] . V_107 = sizeof( V_181 -> V_190 ) ;
V_8 -> V_140 += sizeof( V_181 -> V_190 ) ;
}
V_8 -> V_139 ++ ;
V_8 -> V_191 = V_181 -> V_192 ;
V_8 -> V_193 = true ;
}
static void F_116 ( struct V_7 * V_8 )
{
struct V_35 * V_181 ;
T_4 V_194 ;
F_89 ( V_8 ) ;
V_8 -> V_185 = true ;
V_8 -> V_193 = false ;
if ( V_8 -> V_120 > V_8 -> V_121 ) {
V_8 -> V_121 = V_8 -> V_120 ;
F_90 ( V_8 , sizeof ( V_195 ) , & V_195 ) ;
V_8 -> V_196 = F_80 ( V_8 -> V_121 ) ;
F_90 ( V_8 , sizeof ( V_8 -> V_196 ) ,
& V_8 -> V_196 ) ;
}
F_3 ( F_72 ( & V_8 -> V_114 ) ) ;
V_181 = F_73 ( & V_8 -> V_114 , struct V_35 , V_111 ) ;
V_8 -> V_119 = V_181 ;
F_3 ( V_181 -> V_8 != V_8 ) ;
F_117 ( V_181 ) ;
F_118 ( & V_181 -> V_111 , & V_8 -> V_115 ) ;
if ( V_181 -> V_197 ) {
V_181 -> V_198 . V_199 = F_80 ( ++ V_8 -> V_118 ) ;
V_181 -> V_197 = false ;
}
F_37 ( V_181 -> V_176 != F_119 ( V_181 -> V_198 . V_180 ) ) ;
F_39 ( L_27 ,
V_181 , V_8 -> V_118 , F_120 ( V_181 -> V_198 . type ) ,
F_119 ( V_181 -> V_198 . V_200 ) , F_119 ( V_181 -> V_198 . V_201 ) ,
V_181 -> V_176 ) ;
F_3 ( F_119 ( V_181 -> V_198 . V_200 ) != V_181 -> V_202 . V_107 ) ;
F_90 ( V_8 , sizeof ( V_203 ) , & V_203 ) ;
F_90 ( V_8 , sizeof ( V_181 -> V_198 ) , & V_181 -> V_198 ) ;
F_90 ( V_8 , V_181 -> V_202 . V_107 , V_181 -> V_202 . V_106 ) ;
if ( V_181 -> V_204 )
F_90 ( V_8 , V_181 -> V_204 -> V_205 . V_107 ,
V_181 -> V_204 -> V_205 . V_106 ) ;
V_194 = F_121 ( 0 , & V_181 -> V_198 , F_122 ( struct V_206 , V_194 ) ) ;
V_8 -> V_119 -> V_198 . V_194 = F_123 ( V_194 ) ;
V_8 -> V_119 -> V_183 . V_9 = 0 ;
V_194 = F_121 ( 0 , V_181 -> V_202 . V_106 , V_181 -> V_202 . V_107 ) ;
V_8 -> V_119 -> V_183 . V_207 = F_123 ( V_194 ) ;
if ( V_181 -> V_204 ) {
V_194 = F_121 ( 0 , V_181 -> V_204 -> V_205 . V_106 ,
V_181 -> V_204 -> V_205 . V_107 ) ;
V_8 -> V_119 -> V_183 . V_208 = F_123 ( V_194 ) ;
} else
V_8 -> V_119 -> V_183 . V_208 = 0 ;
F_39 ( L_28 , V_46 ,
F_119 ( V_8 -> V_119 -> V_183 . V_207 ) ,
F_119 ( V_8 -> V_119 -> V_183 . V_208 ) ) ;
V_8 -> V_119 -> V_183 . V_209 = 0 ;
if ( V_181 -> V_176 ) {
F_114 ( V_8 -> V_119 , V_181 -> V_176 ) ;
V_8 -> V_191 = 1 ;
} else {
F_115 ( V_8 ) ;
}
F_5 ( V_8 , V_4 ) ;
}
static void F_124 ( struct V_7 * V_8 )
{
F_39 ( L_29 , V_8 ,
V_8 -> V_121 , V_8 -> V_120 ) ;
V_8 -> V_121 = V_8 -> V_120 ;
F_89 ( V_8 ) ;
F_90 ( V_8 , sizeof ( V_195 ) , & V_195 ) ;
V_8 -> V_196 = F_80 ( V_8 -> V_121 ) ;
F_90 ( V_8 , sizeof ( V_8 -> V_196 ) ,
& V_8 -> V_196 ) ;
V_8 -> V_191 = 1 ;
F_5 ( V_8 , V_4 ) ;
}
static void F_125 ( struct V_7 * V_8 )
{
F_39 ( L_30 , V_8 ,
V_8 -> V_121 , V_8 -> V_120 ) ;
V_8 -> V_121 = V_8 -> V_120 ;
F_89 ( V_8 ) ;
V_8 -> V_196 = F_80 ( V_8 -> V_121 ) ;
F_90 ( V_8 , sizeof ( V_8 -> V_196 ) ,
& V_8 -> V_196 ) ;
F_5 ( V_8 , V_4 ) ;
}
static void F_126 ( struct V_7 * V_8 )
{
F_39 ( L_31 , V_8 ) ;
F_89 ( V_8 ) ;
F_90 ( V_8 , sizeof ( V_210 ) , & V_210 ) ;
F_5 ( V_8 , V_4 ) ;
}
static struct V_211 * F_127 ( struct V_7 * V_8 ,
int * V_212 )
{
struct V_211 * V_213 ;
if ( ! V_8 -> V_75 -> V_214 ) {
V_8 -> V_215 . V_216 = V_217 ;
V_8 -> V_215 . V_218 = 0 ;
return NULL ;
}
F_78 ( & V_8 -> V_122 ) ;
V_213 = V_8 -> V_75 -> V_214 ( V_8 , V_212 , V_8 -> V_219 ) ;
F_76 ( & V_8 -> V_122 ) ;
if ( F_128 ( V_213 ) )
return V_213 ;
if ( V_8 -> V_56 != V_220 )
return F_129 ( - V_94 ) ;
V_8 -> V_221 = V_213 -> V_222 ;
V_8 -> V_223 = V_213 -> V_224 ;
return V_213 ;
}
static void F_130 ( struct V_7 * V_8 )
{
F_90 ( V_8 , strlen ( V_225 ) , V_225 ) ;
F_90 ( V_8 , sizeof ( V_8 -> V_30 -> V_31 ) ,
& V_8 -> V_30 -> V_31 ) ;
V_8 -> V_191 = 0 ;
F_5 ( V_8 , V_4 ) ;
}
static int F_131 ( struct V_7 * V_8 )
{
unsigned int V_138 = F_86 ( V_8 -> V_30 , 0 ) ;
int V_226 ;
int V_212 ;
struct V_211 * V_213 ;
switch ( V_8 -> V_129 . type ) {
case V_227 :
V_226 = V_228 ;
break;
case V_229 :
V_226 = V_230 ;
break;
case V_231 :
V_226 = V_232 ;
break;
default:
F_113 () ;
}
F_39 ( L_32 , V_8 ,
V_8 -> V_117 , V_138 , V_226 ) ;
V_8 -> V_215 . V_233 = F_80 ( V_8 -> V_30 -> V_234 ) ;
V_8 -> V_215 . V_235 = F_123 ( V_236 ) ;
V_8 -> V_215 . V_117 = F_123 ( V_8 -> V_117 ) ;
V_8 -> V_215 . V_138 = F_123 ( V_138 ) ;
V_8 -> V_215 . V_237 = F_123 ( V_226 ) ;
V_8 -> V_215 . V_9 = 0 ;
V_212 = V_217 ;
V_213 = F_127 ( V_8 , & V_212 ) ;
if ( F_128 ( V_213 ) )
return F_132 ( V_213 ) ;
V_8 -> V_215 . V_216 = F_123 ( V_212 ) ;
V_8 -> V_215 . V_218 = V_213 ?
F_123 ( V_213 -> V_238 ) : 0 ;
F_90 ( V_8 , sizeof ( V_8 -> V_215 ) ,
& V_8 -> V_215 ) ;
if ( V_213 && V_213 -> V_238 )
F_90 ( V_8 , V_213 -> V_238 ,
V_213 -> V_239 ) ;
V_8 -> V_191 = 0 ;
F_5 ( V_8 , V_4 ) ;
return 0 ;
}
static int F_133 ( struct V_7 * V_8 )
{
int V_68 ;
F_39 ( L_33 , V_8 , V_8 -> V_140 ) ;
while ( V_8 -> V_140 > 0 ) {
V_68 = F_61 ( V_8 -> V_50 , V_8 -> V_141 ,
V_8 -> V_139 , V_8 -> V_140 ,
V_8 -> V_191 ) ;
if ( V_68 <= 0 )
goto V_240;
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
V_8 -> V_185 = false ;
V_68 = 1 ;
V_240:
F_39 ( L_34 , V_8 ,
V_8 -> V_140 , V_8 -> V_139 , V_68 ) ;
return V_68 ;
}
static T_4 F_134 ( T_4 V_194 , struct V_95 * V_95 ,
unsigned int V_96 ,
unsigned int V_97 )
{
char * V_98 ;
V_98 = F_60 ( V_95 ) ;
F_3 ( V_98 == NULL ) ;
V_194 = F_121 ( V_194 , V_98 + V_96 , V_97 ) ;
F_25 ( V_95 ) ;
return V_194 ;
}
static int F_135 ( struct V_7 * V_8 )
{
struct V_35 * V_89 = V_8 -> V_119 ;
struct V_145 * V_146 = & V_89 -> V_146 ;
bool V_241 = ! V_8 -> V_30 -> V_242 ;
T_4 V_194 ;
F_39 ( L_35 , V_46 , V_8 , V_89 ) ;
if ( F_72 ( & V_89 -> V_143 ) )
return - V_243 ;
V_194 = V_241 ? F_119 ( V_89 -> V_183 . V_209 ) : 0 ;
while ( V_146 -> V_149 ) {
struct V_95 * V_95 ;
T_1 V_96 ;
T_1 V_97 ;
bool V_153 ;
bool V_175 ;
int V_68 ;
V_95 = F_111 ( & V_89 -> V_146 , & V_96 , & V_97 ,
& V_153 ) ;
V_68 = F_65 ( V_8 -> V_50 , V_95 , V_96 ,
V_97 , V_153 ) ;
if ( V_68 <= 0 ) {
if ( V_241 )
V_89 -> V_183 . V_209 = F_123 ( V_194 ) ;
return V_68 ;
}
if ( V_241 && V_146 -> V_175 )
V_194 = F_134 ( V_194 , V_95 , V_96 , V_97 ) ;
V_175 = F_112 ( & V_89 -> V_146 , ( T_1 ) V_68 ) ;
}
F_39 ( L_36 , V_46 , V_8 , V_89 ) ;
if ( V_241 )
V_89 -> V_183 . V_209 = F_123 ( V_194 ) ;
else
V_89 -> V_183 . V_9 |= V_244 ;
F_89 ( V_8 ) ;
F_115 ( V_8 ) ;
return 1 ;
}
static int F_136 ( struct V_7 * V_8 )
{
int V_68 ;
while ( V_8 -> V_245 > 0 ) {
T_1 V_105 = F_93 ( V_8 -> V_245 , ( int ) V_246 ) ;
V_68 = F_65 ( V_8 -> V_50 , V_40 , 0 , V_105 , true ) ;
if ( V_68 <= 0 )
goto V_240;
V_8 -> V_245 -= V_68 ;
}
V_68 = 1 ;
V_240:
return V_68 ;
}
static void F_137 ( struct V_7 * V_8 )
{
F_39 ( L_37 , V_8 ) ;
V_8 -> V_247 = 0 ;
}
static void F_138 ( struct V_7 * V_8 )
{
F_39 ( L_38 , V_8 ) ;
V_8 -> V_247 = 0 ;
}
static void F_139 ( struct V_7 * V_8 )
{
F_39 ( L_39 , V_8 ) ;
V_8 -> V_247 = 0 ;
}
static void F_140 ( struct V_7 * V_8 )
{
F_39 ( L_40 , V_8 ) ;
V_8 -> V_247 = 0 ;
V_8 -> V_248 = V_249 ;
}
static void F_141 ( struct V_7 * V_8 )
{
F_39 ( L_41 , V_8 ) ;
V_8 -> V_247 = 0 ;
V_8 -> V_248 = V_250 ;
}
static int F_142 ( struct V_7 * V_8 )
{
F_39 ( L_42 , V_8 ) ;
F_3 ( V_8 -> V_116 != NULL ) ;
V_8 -> V_247 = 0 ;
V_8 -> V_251 = V_8 -> V_252 = V_8 -> V_253 = 0 ;
return 0 ;
}
static int F_143 ( struct V_7 * V_8 ,
int V_254 , int V_105 , void * V_255 )
{
while ( V_8 -> V_247 < V_254 ) {
int V_256 = V_254 - V_8 -> V_247 ;
int V_257 = V_105 - V_256 ;
int V_68 = F_57 ( V_8 -> V_50 , V_255 + V_257 , V_256 ) ;
if ( V_68 <= 0 )
return V_68 ;
V_8 -> V_247 += V_68 ;
}
return 1 ;
}
static int F_144 ( struct V_7 * V_8 )
{
int V_105 ;
int V_254 ;
int V_68 ;
F_39 ( L_43 , V_8 , V_8 -> V_247 ) ;
V_105 = strlen ( V_225 ) ;
V_254 = V_105 ;
V_68 = F_143 ( V_8 , V_254 , V_105 , V_8 -> V_258 ) ;
if ( V_68 <= 0 )
goto V_240;
V_105 = sizeof ( V_8 -> V_259 ) ;
V_254 += V_105 ;
V_68 = F_143 ( V_8 , V_254 , V_105 , & V_8 -> V_259 ) ;
if ( V_68 <= 0 )
goto V_240;
V_105 = sizeof ( V_8 -> V_260 ) ;
V_254 += V_105 ;
V_68 = F_143 ( V_8 , V_254 , V_105 , & V_8 -> V_260 ) ;
if ( V_68 <= 0 )
goto V_240;
V_240:
return V_68 ;
}
static int F_145 ( struct V_7 * V_8 )
{
int V_105 ;
int V_254 ;
int V_68 ;
F_39 ( L_44 , V_8 , V_8 -> V_247 ) ;
V_105 = sizeof ( V_8 -> V_261 ) ;
V_254 = V_105 ;
V_68 = F_143 ( V_8 , V_254 , V_105 , & V_8 -> V_261 ) ;
if ( V_68 <= 0 )
goto V_240;
V_105 = F_119 ( V_8 -> V_261 . V_218 ) ;
V_254 += V_105 ;
V_68 = F_143 ( V_8 , V_254 , V_105 , V_8 -> V_221 ) ;
if ( V_68 <= 0 )
goto V_240;
F_39 ( L_45 ,
V_8 , ( int ) V_8 -> V_261 . V_262 ,
F_119 ( V_8 -> V_261 . V_117 ) ,
F_119 ( V_8 -> V_261 . V_138 ) ) ;
V_240:
return V_68 ;
}
static int F_146 ( struct V_7 * V_8 )
{
if ( memcmp ( V_8 -> V_258 , V_225 , strlen ( V_225 ) ) ) {
F_31 ( L_46 ,
F_13 ( & V_8 -> V_66 . V_67 ) ) ;
V_8 -> V_263 = L_47 ;
return - 1 ;
}
return 0 ;
}
static bool F_147 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_21 ) {
case V_22 :
return ( (struct V_14 * ) V_11 ) -> V_24 . V_264 == 0 ;
case V_26 :
return
( (struct V_16 * ) V_11 ) -> V_27 . V_265 [ 0 ] == 0 &&
( (struct V_16 * ) V_11 ) -> V_27 . V_265 [ 1 ] == 0 &&
( (struct V_16 * ) V_11 ) -> V_27 . V_265 [ 2 ] == 0 &&
( (struct V_16 * ) V_11 ) -> V_27 . V_265 [ 3 ] == 0 ;
}
return false ;
}
static int F_148 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_21 ) {
case V_22 :
return F_15 ( ( (struct V_14 * ) V_11 ) -> V_25 ) ;
case V_26 :
return F_15 ( ( (struct V_16 * ) V_11 ) -> V_28 ) ;
}
return 0 ;
}
static void F_149 ( struct V_10 * V_11 , int V_266 )
{
switch ( V_11 -> V_21 ) {
case V_22 :
( (struct V_14 * ) V_11 ) -> V_25 = F_150 ( V_266 ) ;
break;
case V_26 :
( (struct V_16 * ) V_11 ) -> V_28 = F_150 ( V_266 ) ;
break;
}
}
static int F_151 ( const char * V_267 , T_1 V_85 , struct V_10 * V_11 ,
char V_268 , const char * * V_269 )
{
struct V_14 * V_15 = (struct V_14 * ) V_11 ;
struct V_16 * V_17 = (struct V_16 * ) V_11 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
if ( F_152 ( V_267 , V_85 , ( V_270 * ) & V_15 -> V_24 . V_264 , V_268 , V_269 ) ) {
V_11 -> V_21 = V_22 ;
return 0 ;
}
if ( F_153 ( V_267 , V_85 , ( V_270 * ) & V_17 -> V_27 . V_271 , V_268 , V_269 ) ) {
V_11 -> V_21 = V_26 ;
return 0 ;
}
return - V_243 ;
}
static int F_154 ( const char * V_272 , T_1 V_273 ,
struct V_10 * V_11 , char V_268 , const char * * V_269 )
{
const char * V_254 , * V_274 ;
char * V_275 , * V_276 = NULL ;
int V_277 , V_68 ;
V_274 = memchr ( V_272 , V_268 , V_273 ) ;
V_275 = memchr ( V_272 , ':' , V_273 ) ;
if ( V_274 && V_275 )
V_254 = V_274 < V_275 ? V_274 : V_275 ;
else if ( ! V_274 && V_275 )
V_254 = V_275 ;
else {
V_254 = V_274 ;
if ( ! V_254 )
V_254 = V_272 + V_273 ;
}
if ( V_254 <= V_272 )
return - V_243 ;
V_277 = F_155 ( NULL , V_272 , V_254 - V_272 , NULL , & V_276 , NULL ) ;
if ( V_277 > 0 )
V_68 = F_151 ( V_276 , V_277 , V_11 , - 1 , NULL ) ;
else
V_68 = - V_278 ;
F_156 ( V_276 ) ;
* V_269 = V_254 ;
F_157 ( L_48 , ( int ) ( V_254 - V_272 ) , V_272 ,
V_68 , V_68 ? L_49 : F_13 ( V_11 ) ) ;
return V_68 ;
}
static inline int F_154 ( const char * V_272 , T_1 V_273 ,
struct V_10 * V_11 , char V_268 , const char * * V_269 )
{
return - V_243 ;
}
static int F_158 ( const char * V_272 , T_1 V_273 ,
struct V_10 * V_11 , char V_268 , const char * * V_269 )
{
int V_68 ;
V_68 = F_151 ( V_272 , V_273 , V_11 , V_268 , V_269 ) ;
if ( V_68 )
V_68 = F_154 ( V_272 , V_273 , V_11 , V_268 , V_269 ) ;
return V_68 ;
}
int F_159 ( const char * V_279 , const char * V_254 ,
struct V_127 * V_33 ,
int V_280 , int * V_281 )
{
int V_12 , V_68 = - V_243 ;
const char * V_266 = V_279 ;
F_39 ( L_50 , ( int ) ( V_254 - V_279 ) , V_279 ) ;
for ( V_12 = 0 ; V_12 < V_280 ; V_12 ++ ) {
const char * V_269 ;
struct V_10 * V_11 = & V_33 [ V_12 ] . V_67 ;
int V_282 ;
char V_268 = ',' ;
if ( * V_266 == '[' ) {
V_268 = ']' ;
V_266 ++ ;
}
V_68 = F_158 ( V_266 , V_254 - V_266 , V_11 , V_268 , & V_269 ) ;
if ( V_68 )
goto V_283;
V_68 = - V_243 ;
V_266 = V_269 ;
if ( V_268 == ']' ) {
if ( * V_266 != ']' ) {
F_39 ( L_51 ) ;
goto V_283;
}
V_266 ++ ;
}
if ( V_266 < V_254 && * V_266 == ':' ) {
V_282 = 0 ;
V_266 ++ ;
while ( V_266 < V_254 && * V_266 >= '0' && * V_266 <= '9' ) {
V_282 = ( V_282 * 10 ) + ( * V_266 - '0' ) ;
V_266 ++ ;
}
if ( V_282 == 0 )
V_282 = V_284 ;
else if ( V_282 > 65535 )
goto V_283;
} else {
V_282 = V_284 ;
}
F_149 ( V_11 , V_282 ) ;
F_39 ( L_52 , F_13 ( V_11 ) ) ;
if ( V_266 == V_254 )
break;
if ( * V_266 != ',' )
goto V_283;
V_266 ++ ;
}
if ( V_266 != V_254 )
goto V_283;
if ( V_281 )
* V_281 = V_12 + 1 ;
return 0 ;
V_283:
F_31 ( L_53 , ( int ) ( V_254 - V_279 ) , V_279 ) ;
return V_68 ;
}
static int F_160 ( struct V_7 * V_8 )
{
F_39 ( L_54 , V_8 ) ;
if ( F_146 ( V_8 ) < 0 )
return - 1 ;
F_161 ( & V_8 -> V_259 ) ;
F_161 ( & V_8 -> V_260 ) ;
if ( memcmp ( & V_8 -> V_66 , & V_8 -> V_259 ,
sizeof( V_8 -> V_66 ) ) != 0 &&
! ( F_147 ( & V_8 -> V_259 . V_67 ) &&
V_8 -> V_259 . V_285 == V_8 -> V_66 . V_285 ) ) {
F_162 ( L_55 ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
( int ) F_119 ( V_8 -> V_66 . V_285 ) ,
F_13 ( & V_8 -> V_259 . V_67 ) ,
( int ) F_119 ( V_8 -> V_259 . V_285 ) ) ;
V_8 -> V_263 = L_56 ;
return - 1 ;
}
if ( F_147 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ) ) {
int V_282 = F_148 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ) ;
memcpy ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ,
& V_8 -> V_260 . V_67 ,
sizeof( V_8 -> V_260 . V_67 ) ) ;
F_149 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 , V_282 ) ;
F_16 ( V_8 -> V_30 ) ;
F_39 ( L_57 ,
F_13 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ) ) ;
}
return 0 ;
}
static int F_163 ( struct V_7 * V_8 )
{
V_164 V_286 = V_8 -> V_30 -> V_234 ;
V_164 V_287 = V_8 -> V_30 -> V_288 ;
V_164 V_289 = F_164 (
F_165 ( V_8 -> V_261 . V_233 ) ) ;
int V_68 ;
F_39 ( L_58 , V_8 , ( int ) V_8 -> V_248 ) ;
switch ( V_8 -> V_261 . V_262 ) {
case V_290 :
F_31 ( L_59
L_60 ,
F_166 ( V_8 -> V_129 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_286 , V_289 , V_289 & ~ V_286 ) ;
V_8 -> V_263 = L_61 ;
F_74 ( V_8 ) ;
return - 1 ;
case V_291 :
F_31 ( L_62
L_63 ,
F_166 ( V_8 -> V_129 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
F_119 ( V_8 -> V_215 . V_237 ) ,
F_119 ( V_8 -> V_261 . V_237 ) ) ;
V_8 -> V_263 = L_64 ;
F_74 ( V_8 ) ;
return - 1 ;
case V_292 :
V_8 -> V_219 ++ ;
F_39 ( L_65 , V_8 ,
V_8 -> V_219 ) ;
if ( V_8 -> V_219 == 2 ) {
V_8 -> V_263 = L_66 ;
return - 1 ;
}
F_89 ( V_8 ) ;
V_68 = F_131 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_138 ( V_8 ) ;
break;
case V_293 :
F_39 ( L_67 ,
F_119 ( V_8 -> V_261 . V_117 ) ) ;
F_31 ( L_68 ,
F_166 ( V_8 -> V_129 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ) ;
F_74 ( V_8 ) ;
F_89 ( V_8 ) ;
V_68 = F_131 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_138 ( V_8 ) ;
F_78 ( & V_8 -> V_122 ) ;
F_157 ( L_69 , F_166 ( V_8 -> V_129 ) ) ;
if ( V_8 -> V_75 -> V_294 )
V_8 -> V_75 -> V_294 ( V_8 ) ;
F_76 ( & V_8 -> V_122 ) ;
if ( V_8 -> V_56 != V_220 )
return - V_94 ;
break;
case V_295 :
F_39 ( L_70 ,
F_119 ( V_8 -> V_215 . V_117 ) ,
F_119 ( V_8 -> V_261 . V_117 ) ) ;
V_8 -> V_117 = F_119 ( V_8 -> V_261 . V_117 ) ;
F_89 ( V_8 ) ;
V_68 = F_131 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_138 ( V_8 ) ;
break;
case V_296 :
F_39 ( L_71 ,
V_8 -> V_124 ,
F_119 ( V_8 -> V_261 . V_138 ) ) ;
F_86 ( V_8 -> V_30 ,
F_119 ( V_8 -> V_261 . V_138 ) ) ;
F_89 ( V_8 ) ;
V_68 = F_131 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_138 ( V_8 ) ;
break;
case V_249 :
case V_250 :
if ( V_287 & ~ V_289 ) {
F_31 ( L_72
L_73 ,
F_166 ( V_8 -> V_129 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_287 , V_289 , V_287 & ~ V_289 ) ;
V_8 -> V_263 = L_61 ;
F_74 ( V_8 ) ;
return - 1 ;
}
F_37 ( V_8 -> V_56 != V_220 ) ;
V_8 -> V_56 = V_297 ;
V_8 -> V_219 = 0 ;
V_8 -> V_124 = F_119 ( V_8 -> V_261 . V_138 ) ;
V_8 -> V_117 ++ ;
V_8 -> V_186 = V_289 ;
F_39 ( L_74 ,
V_8 -> V_124 ,
F_119 ( V_8 -> V_261 . V_117 ) ,
V_8 -> V_117 ) ;
F_37 ( V_8 -> V_117 !=
F_119 ( V_8 -> V_261 . V_117 ) ) ;
if ( V_8 -> V_261 . V_9 & V_298 )
F_5 ( V_8 , V_2 ) ;
V_8 -> V_131 = 0 ;
if ( V_8 -> V_261 . V_262 == V_249 ) {
F_125 ( V_8 ) ;
F_140 ( V_8 ) ;
} else {
F_141 ( V_8 ) ;
}
break;
case V_299 :
V_8 -> V_263 = L_75 ;
return - 1 ;
default:
V_8 -> V_263 = L_76 ;
return - 1 ;
}
return 0 ;
}
static int F_167 ( struct V_7 * V_8 )
{
int V_105 = sizeof ( V_8 -> V_300 ) ;
int V_254 = V_105 ;
return F_143 ( V_8 , V_254 , V_105 , & V_8 -> V_300 ) ;
}
static void F_168 ( struct V_7 * V_8 )
{
struct V_35 * V_181 ;
V_164 V_301 = F_165 ( V_8 -> V_300 ) ;
V_164 V_199 ;
while ( ! F_72 ( & V_8 -> V_115 ) ) {
V_181 = F_73 ( & V_8 -> V_115 , struct V_35 ,
V_111 ) ;
V_199 = F_165 ( V_181 -> V_198 . V_199 ) ;
if ( V_199 > V_301 )
break;
F_39 ( L_77 , V_199 ,
F_120 ( V_181 -> V_198 . type ) , V_181 ) ;
V_181 -> V_302 = V_303 ;
F_68 ( V_181 ) ;
}
F_141 ( V_8 ) ;
}
static int F_169 ( struct V_7 * V_8 ,
struct V_86 * V_304 ,
unsigned int V_305 , T_4 * V_194 )
{
int V_68 , V_256 ;
F_3 ( ! V_304 ) ;
while ( V_304 -> V_107 < V_305 ) {
F_3 ( V_304 -> V_106 == NULL ) ;
V_256 = V_305 - V_304 -> V_107 ;
V_68 = F_57 ( V_8 -> V_50 , ( char * ) V_304 -> V_106 +
V_304 -> V_107 , V_256 ) ;
if ( V_68 <= 0 )
return V_68 ;
V_304 -> V_107 += V_68 ;
}
if ( V_304 -> V_107 == V_305 )
* V_194 = F_121 ( 0 , V_304 -> V_106 , V_304 -> V_107 ) ;
return 1 ;
}
static int F_170 ( struct V_7 * V_8 )
{
struct V_35 * V_89 = V_8 -> V_116 ;
struct V_145 * V_146 = & V_89 -> V_146 ;
const bool V_241 = ! V_8 -> V_30 -> V_242 ;
struct V_95 * V_95 ;
T_1 V_96 ;
T_1 V_97 ;
T_4 V_194 = 0 ;
int V_68 ;
F_3 ( ! V_89 ) ;
if ( F_72 ( & V_89 -> V_143 ) )
return - V_306 ;
if ( V_241 )
V_194 = V_8 -> V_253 ;
while ( V_146 -> V_149 ) {
V_95 = F_111 ( & V_89 -> V_146 , & V_96 , & V_97 ,
NULL ) ;
V_68 = F_59 ( V_8 -> V_50 , V_95 , V_96 , V_97 ) ;
if ( V_68 <= 0 ) {
if ( V_241 )
V_8 -> V_253 = V_194 ;
return V_68 ;
}
if ( V_241 )
V_194 = F_134 ( V_194 , V_95 , V_96 , V_68 ) ;
( void ) F_112 ( & V_89 -> V_146 , ( T_1 ) V_68 ) ;
}
if ( V_241 )
V_8 -> V_253 = V_194 ;
return 1 ;
}
static int F_171 ( struct V_7 * V_8 )
{
struct V_35 * V_181 = V_8 -> V_116 ;
int V_105 ;
int V_254 ;
int V_68 ;
unsigned int V_200 , V_201 , V_180 ;
bool V_241 = ! V_8 -> V_30 -> V_242 ;
bool V_307 = ( V_8 -> V_186 & V_187 ) ;
V_164 V_199 ;
T_4 V_194 ;
F_39 ( L_78 , V_8 , V_181 ) ;
V_105 = sizeof ( V_8 -> V_308 ) ;
V_254 = V_105 ;
V_68 = F_143 ( V_8 , V_254 , V_105 , & V_8 -> V_308 ) ;
if ( V_68 <= 0 )
return V_68 ;
V_194 = F_121 ( 0 , & V_8 -> V_308 , F_122 ( struct V_206 , V_194 ) ) ;
if ( F_123 ( V_194 ) != V_8 -> V_308 . V_194 ) {
F_31 ( L_79 ,
V_194 , V_8 -> V_308 . V_194 ) ;
return - V_309 ;
}
V_200 = F_119 ( V_8 -> V_308 . V_200 ) ;
if ( V_200 > V_310 )
return - V_306 ;
V_201 = F_119 ( V_8 -> V_308 . V_201 ) ;
if ( V_201 > V_311 )
return - V_306 ;
V_180 = F_119 ( V_8 -> V_308 . V_180 ) ;
if ( V_180 > V_312 )
return - V_306 ;
V_199 = F_165 ( V_8 -> V_308 . V_199 ) ;
if ( ( V_313 ) V_199 - ( V_313 ) V_8 -> V_120 < 1 ) {
F_157 ( L_80 ,
F_166 ( V_8 -> V_129 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_199 , V_8 -> V_120 + 1 ) ;
V_8 -> V_247 = - V_200 - V_201 - V_180 -
sizeof( V_181 -> V_183 ) ;
V_8 -> V_248 = V_250 ;
return 0 ;
} else if ( ( V_313 ) V_199 - ( V_313 ) V_8 -> V_120 > 1 ) {
F_31 ( L_81 ,
V_199 , V_8 -> V_120 + 1 ) ;
V_8 -> V_263 = L_82 ;
return - V_314 ;
}
if ( ! V_8 -> V_116 ) {
int V_315 = 0 ;
F_39 ( L_83 , V_8 -> V_308 . type ,
V_200 , V_180 ) ;
V_68 = F_172 ( V_8 , & V_315 ) ;
if ( V_68 < 0 )
return V_68 ;
F_3 ( ! V_8 -> V_116 ^ V_315 ) ;
if ( V_8 -> V_116 && V_180 > V_8 -> V_116 -> V_176 ) {
F_162 ( L_84 ,
V_46 , V_180 , V_8 -> V_116 -> V_176 ) ;
F_70 ( V_8 -> V_116 ) ;
V_8 -> V_116 = NULL ;
V_315 = 1 ;
}
if ( V_315 ) {
F_39 ( L_85 ) ;
V_8 -> V_247 = - V_200 - V_201 - V_180 -
sizeof( V_181 -> V_183 ) ;
V_8 -> V_248 = V_250 ;
V_8 -> V_120 ++ ;
return 0 ;
}
F_3 ( ! V_8 -> V_116 ) ;
F_3 ( V_8 -> V_116 -> V_8 != V_8 ) ;
V_181 = V_8 -> V_116 ;
V_181 -> V_202 . V_107 = 0 ;
if ( V_181 -> V_204 )
V_181 -> V_204 -> V_205 . V_107 = 0 ;
if ( V_180 )
F_114 ( V_8 -> V_116 , V_180 ) ;
}
V_68 = F_169 ( V_8 , & V_181 -> V_202 , V_200 ,
& V_8 -> V_251 ) ;
if ( V_68 <= 0 )
return V_68 ;
if ( V_181 -> V_204 ) {
V_68 = F_169 ( V_8 , & V_181 -> V_204 -> V_205 ,
V_201 ,
& V_8 -> V_252 ) ;
if ( V_68 <= 0 )
return V_68 ;
}
if ( V_180 ) {
V_68 = F_170 ( V_8 ) ;
if ( V_68 <= 0 )
return V_68 ;
}
if ( V_307 )
V_105 = sizeof( V_181 -> V_183 ) ;
else
V_105 = sizeof( V_181 -> V_190 ) ;
V_254 += V_105 ;
V_68 = F_143 ( V_8 , V_254 , V_105 , & V_181 -> V_183 ) ;
if ( V_68 <= 0 )
return V_68 ;
if ( ! V_307 ) {
V_181 -> V_183 . V_9 = V_181 -> V_190 . V_9 ;
V_181 -> V_183 . V_189 = 0 ;
}
F_39 ( L_86 ,
V_181 , V_200 , V_181 -> V_183 . V_207 , V_201 ,
V_181 -> V_183 . V_208 , V_180 , V_181 -> V_183 . V_209 ) ;
if ( V_8 -> V_251 != F_119 ( V_181 -> V_183 . V_207 ) ) {
F_31 ( L_87 ,
V_181 , V_8 -> V_251 , V_181 -> V_183 . V_207 ) ;
return - V_309 ;
}
if ( V_8 -> V_252 != F_119 ( V_181 -> V_183 . V_208 ) ) {
F_31 ( L_88 ,
V_181 , V_8 -> V_252 , V_181 -> V_183 . V_208 ) ;
return - V_309 ;
}
if ( V_241 &&
( V_181 -> V_183 . V_9 & V_244 ) == 0 &&
V_8 -> V_253 != F_119 ( V_181 -> V_183 . V_209 ) ) {
F_31 ( L_89 , V_181 ,
V_8 -> V_253 , F_119 ( V_181 -> V_183 . V_209 ) ) ;
return - V_309 ;
}
if ( V_307 && V_8 -> V_75 -> V_316 &&
V_8 -> V_75 -> V_316 ( V_8 , V_181 ) ) {
F_31 ( L_90 , V_181 ) ;
return - V_309 ;
}
return 1 ;
}
static void F_173 ( struct V_7 * V_8 )
{
struct V_35 * V_89 ;
F_3 ( V_8 -> V_116 -> V_8 != V_8 ) ;
V_8 -> V_116 -> V_8 = NULL ;
V_89 = V_8 -> V_116 ;
V_8 -> V_116 = NULL ;
V_8 -> V_75 -> V_112 ( V_8 ) ;
if ( V_8 -> V_129 . type == 0 )
V_8 -> V_129 = V_89 -> V_198 . V_317 ;
V_8 -> V_120 ++ ;
F_78 ( & V_8 -> V_122 ) ;
F_39 ( L_91 ,
V_89 , F_165 ( V_89 -> V_198 . V_199 ) ,
F_166 ( V_89 -> V_198 . V_317 ) ,
F_120 ( V_89 -> V_198 . type ) ,
F_174 ( F_120 ( V_89 -> V_198 . type ) ) ,
F_119 ( V_89 -> V_198 . V_200 ) ,
F_119 ( V_89 -> V_198 . V_180 ) ,
V_8 -> V_251 , V_8 -> V_252 , V_8 -> V_253 ) ;
V_8 -> V_75 -> V_318 ( V_8 , V_89 ) ;
F_76 ( & V_8 -> V_122 ) ;
}
static int F_175 ( struct V_7 * V_8 )
{
int V_68 = 1 ;
F_39 ( L_92 , V_8 , V_8 -> V_56 ) ;
V_101:
F_39 ( L_93 , V_8 -> V_140 ) ;
if ( V_8 -> V_56 == V_128 ) {
F_3 ( V_8 -> V_50 ) ;
V_8 -> V_56 = V_319 ;
F_89 ( V_8 ) ;
F_130 ( V_8 ) ;
F_137 ( V_8 ) ;
F_3 ( V_8 -> V_116 ) ;
V_8 -> V_248 = V_250 ;
F_39 ( L_94 ,
V_8 , V_8 -> V_56 ) ;
V_68 = F_51 ( V_8 ) ;
if ( V_68 < 0 ) {
V_8 -> V_263 = L_95 ;
goto V_240;
}
}
V_320:
if ( V_8 -> V_245 ) {
V_68 = F_136 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_240;
}
if ( V_8 -> V_139 ) {
V_68 = F_133 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_240;
}
if ( V_8 -> V_119 ) {
if ( V_8 -> V_193 ) {
F_70 ( V_8 -> V_119 ) ;
V_8 -> V_119 = NULL ;
goto V_321;
}
V_68 = F_135 ( V_8 ) ;
if ( V_68 == 1 )
goto V_320;
if ( V_68 == 0 )
goto V_240;
if ( V_68 < 0 ) {
F_39 ( L_96 ,
V_68 ) ;
goto V_240;
}
}
V_321:
if ( V_8 -> V_56 == V_297 ) {
if ( ! F_72 ( & V_8 -> V_114 ) ) {
F_116 ( V_8 ) ;
goto V_101;
}
if ( V_8 -> V_120 > V_8 -> V_121 ) {
F_124 ( V_8 ) ;
goto V_101;
}
if ( F_9 ( V_8 , V_3 ) ) {
F_126 ( V_8 ) ;
goto V_101;
}
}
F_2 ( V_8 , V_4 ) ;
F_39 ( L_97 ) ;
V_68 = 0 ;
V_240:
F_39 ( L_98 , V_8 , V_68 ) ;
return V_68 ;
}
static int F_176 ( struct V_7 * V_8 )
{
int V_68 = - 1 ;
V_101:
F_39 ( L_99 , V_8 , V_8 -> V_56 ) ;
if ( V_8 -> V_56 != V_319 &&
V_8 -> V_56 != V_220 &&
V_8 -> V_56 != V_297 )
return 0 ;
F_3 ( ! V_8 -> V_50 ) ;
F_39 ( L_100 , ( int ) V_8 -> V_248 ,
V_8 -> V_247 ) ;
if ( V_8 -> V_56 == V_319 ) {
F_39 ( L_101 ) ;
V_68 = F_144 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_240;
V_68 = F_160 ( V_8 ) ;
if ( V_68 < 0 )
goto V_240;
V_8 -> V_56 = V_220 ;
V_68 = F_131 ( V_8 ) ;
if ( V_68 < 0 )
goto V_240;
F_138 ( V_8 ) ;
goto V_240;
}
if ( V_8 -> V_56 == V_220 ) {
F_39 ( L_102 ) ;
V_68 = F_145 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_240;
V_68 = F_163 ( V_8 ) ;
if ( V_68 < 0 )
goto V_240;
goto V_101;
}
F_37 ( V_8 -> V_56 != V_297 ) ;
if ( V_8 -> V_247 < 0 ) {
static char V_84 [ V_322 ] ;
int V_315 = F_93 ( ( int ) sizeof ( V_84 ) , - V_8 -> V_247 ) ;
F_39 ( L_103 , V_315 , - V_8 -> V_247 ) ;
V_68 = F_57 ( V_8 -> V_50 , V_84 , V_315 ) ;
if ( V_68 <= 0 )
goto V_240;
V_8 -> V_247 += V_68 ;
if ( V_8 -> V_247 )
goto V_101;
}
if ( V_8 -> V_248 == V_250 ) {
V_68 = F_57 ( V_8 -> V_50 , & V_8 -> V_248 , 1 ) ;
if ( V_68 <= 0 )
goto V_240;
F_39 ( L_104 , ( int ) V_8 -> V_248 ) ;
switch ( V_8 -> V_248 ) {
case V_323 :
F_142 ( V_8 ) ;
break;
case V_324 :
F_139 ( V_8 ) ;
break;
case V_325 :
F_67 ( V_8 ) ;
V_8 -> V_56 = V_123 ;
goto V_240;
default:
goto V_326;
}
}
if ( V_8 -> V_248 == V_323 ) {
V_68 = F_171 ( V_8 ) ;
if ( V_68 <= 0 ) {
switch ( V_68 ) {
case - V_309 :
V_8 -> V_263 = L_105 ;
case - V_314 :
V_68 = - V_306 ;
break;
case - V_306 :
V_8 -> V_263 = L_106 ;
break;
}
goto V_240;
}
if ( V_8 -> V_248 == V_250 )
goto V_101;
F_173 ( V_8 ) ;
if ( V_8 -> V_56 == V_297 )
F_141 ( V_8 ) ;
goto V_101;
}
if ( V_8 -> V_248 == V_324 ||
V_8 -> V_248 == V_249 ) {
V_68 = F_167 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_240;
F_168 ( V_8 ) ;
goto V_101;
}
V_240:
F_39 ( L_107 , V_8 , V_68 ) ;
return V_68 ;
V_326:
F_31 ( L_108 , ( int ) V_8 -> V_248 ) ;
V_8 -> V_263 = L_109 ;
V_68 = - 1 ;
goto V_240;
}
static int F_177 ( struct V_7 * V_8 , unsigned long V_131 )
{
if ( ! V_8 -> V_75 -> V_327 ( V_8 ) ) {
F_39 ( L_110 , V_46 , V_8 ) ;
return - V_328 ;
}
if ( ! F_178 ( V_39 , & V_8 -> V_134 , V_131 ) ) {
F_39 ( L_111 , V_46 , V_8 ) ;
V_8 -> V_75 -> V_112 ( V_8 ) ;
return - V_329 ;
}
F_39 ( L_112 , V_46 , V_8 , V_131 ) ;
return 0 ;
}
static void F_46 ( struct V_7 * V_8 )
{
( void ) F_177 ( V_8 , 0 ) ;
}
static void F_77 ( struct V_7 * V_8 )
{
if ( F_179 ( & V_8 -> V_134 ) ) {
F_39 ( L_113 , V_46 , V_8 ) ;
V_8 -> V_75 -> V_112 ( V_8 ) ;
}
}
static bool F_180 ( struct V_7 * V_8 )
{
if ( ! F_9 ( V_8 , V_5 ) )
return false ;
#define CASE ( T_5 ) \
case CON_STATE_ ## x: \
con->error_msg = "socket closed (con state " #x ")"; \
break;
switch ( V_8 -> V_56 ) {
CASE ( V_330 ) ;
CASE ( V_331 ) ;
CASE ( V_332 ) ;
CASE ( V_333 ) ;
CASE ( V_334 ) ;
CASE ( V_335 ) ;
default:
F_162 ( L_114 ,
V_46 , V_8 , V_8 -> V_56 ) ;
V_8 -> V_263 = L_115 ;
F_113 () ;
break;
}
#undef CASE
return true ;
}
static bool F_181 ( struct V_7 * V_8 )
{
int V_68 ;
if ( ! F_9 ( V_8 , V_6 ) )
return false ;
V_68 = F_177 ( V_8 , F_182 ( V_8 -> V_131 ) ) ;
if ( V_68 ) {
F_39 ( L_116 , V_46 ,
V_8 , V_8 -> V_131 ) ;
F_3 ( V_68 == - V_328 ) ;
F_5 ( V_8 , V_6 ) ;
}
return true ;
}
static void F_183 ( struct V_7 * V_8 )
{
if ( V_8 -> V_219 && V_8 -> V_75 -> V_336 ) {
F_39 ( L_117 ) ;
V_8 -> V_75 -> V_336 ( V_8 ) ;
}
if ( V_8 -> V_75 -> V_337 )
V_8 -> V_75 -> V_337 ( V_8 ) ;
}
static void V_135 ( struct V_338 * V_134 )
{
struct V_7 * V_8 = F_184 ( V_134 , struct V_7 ,
V_134 . V_134 ) ;
bool V_337 ;
F_76 ( & V_8 -> V_122 ) ;
while ( true ) {
int V_68 ;
if ( ( V_337 = F_180 ( V_8 ) ) ) {
F_39 ( L_118 , V_46 , V_8 ) ;
break;
}
if ( F_181 ( V_8 ) ) {
F_39 ( L_119 , V_46 , V_8 ) ;
break;
}
if ( V_8 -> V_56 == V_339 ) {
F_39 ( L_120 , V_46 , V_8 ) ;
break;
}
if ( V_8 -> V_56 == V_123 ) {
F_39 ( L_121 , V_46 , V_8 ) ;
F_3 ( V_8 -> V_50 ) ;
break;
}
if ( V_8 -> V_56 == V_128 ) {
F_39 ( L_122 , V_46 , V_8 ) ;
F_3 ( V_8 -> V_50 ) ;
}
V_68 = F_176 ( V_8 ) ;
if ( V_68 < 0 ) {
if ( V_68 == - V_94 )
continue;
if ( ! V_8 -> V_263 )
V_8 -> V_263 = L_123 ;
V_337 = true ;
break;
}
V_68 = F_175 ( V_8 ) ;
if ( V_68 < 0 ) {
if ( V_68 == - V_94 )
continue;
if ( ! V_8 -> V_263 )
V_8 -> V_263 = L_124 ;
V_337 = true ;
}
break;
}
if ( V_337 )
F_185 ( V_8 ) ;
F_78 ( & V_8 -> V_122 ) ;
if ( V_337 )
F_183 ( V_8 ) ;
V_8 -> V_75 -> V_112 ( V_8 ) ;
}
static void F_185 ( struct V_7 * V_8 )
{
F_39 ( L_125 ,
V_8 , V_8 -> V_56 , F_13 ( & V_8 -> V_66 . V_67 ) ) ;
F_162 ( L_126 , F_166 ( V_8 -> V_129 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) , V_8 -> V_263 ) ;
V_8 -> V_263 = NULL ;
F_37 ( V_8 -> V_56 != V_319 &&
V_8 -> V_56 != V_220 &&
V_8 -> V_56 != V_297 ) ;
F_67 ( V_8 ) ;
if ( F_7 ( V_8 , V_2 ) ) {
F_39 ( L_127 ) ;
V_8 -> V_56 = V_123 ;
return;
}
if ( V_8 -> V_116 ) {
F_3 ( V_8 -> V_116 -> V_8 != V_8 ) ;
V_8 -> V_116 -> V_8 = NULL ;
F_70 ( V_8 -> V_116 ) ;
V_8 -> V_116 = NULL ;
V_8 -> V_75 -> V_112 ( V_8 ) ;
}
F_186 ( & V_8 -> V_115 , & V_8 -> V_114 ) ;
if ( F_72 ( & V_8 -> V_114 ) &&
! F_7 ( V_8 , V_3 ) ) {
F_39 ( L_128 , V_8 ) ;
F_2 ( V_8 , V_4 ) ;
V_8 -> V_56 = V_339 ;
} else {
V_8 -> V_56 = V_128 ;
if ( V_8 -> V_131 == 0 )
V_8 -> V_131 = V_340 ;
else if ( V_8 -> V_131 < V_341 )
V_8 -> V_131 *= 2 ;
F_5 ( V_8 , V_6 ) ;
F_46 ( V_8 ) ;
}
}
void F_187 ( struct V_29 * V_30 ,
struct V_127 * V_342 ,
V_164 V_234 ,
V_164 V_288 ,
bool V_242 ,
bool V_80 )
{
V_30 -> V_234 = V_234 ;
V_30 -> V_288 = V_288 ;
F_188 ( & V_30 -> V_137 ) ;
if ( V_342 )
V_30 -> V_32 . V_33 = * V_342 ;
V_30 -> V_32 . V_33 . type = 0 ;
F_189 ( & V_30 -> V_32 . V_33 . V_285 , sizeof( V_30 -> V_32 . V_33 . V_285 ) ) ;
F_16 ( V_30 ) ;
V_30 -> V_242 = V_242 ;
V_30 -> V_80 = V_80 ;
F_190 ( & V_30 -> V_53 , 0 ) ;
F_39 ( L_113 , V_46 , V_30 ) ;
}
static void F_191 ( struct V_7 * V_8 )
{
if ( V_8 -> V_56 == V_339 ) {
F_39 ( L_129 , V_8 ) ;
V_8 -> V_56 = V_128 ;
V_8 -> V_117 ++ ;
F_37 ( F_7 ( V_8 , V_4 ) ) ;
F_37 ( F_7 ( V_8 , V_3 ) ) ;
}
}
void F_192 ( struct V_7 * V_8 , struct V_35 * V_89 )
{
V_89 -> V_198 . V_317 = V_8 -> V_30 -> V_32 . V_272 ;
F_3 ( V_89 -> V_202 . V_107 != F_119 ( V_89 -> V_198 . V_200 ) ) ;
V_89 -> V_197 = true ;
F_76 ( & V_8 -> V_122 ) ;
if ( V_8 -> V_56 == V_123 ) {
F_39 ( L_130 , V_8 , V_89 ) ;
F_70 ( V_89 ) ;
F_78 ( & V_8 -> V_122 ) ;
return;
}
F_3 ( V_89 -> V_8 != NULL ) ;
V_89 -> V_8 = V_8 -> V_75 -> V_327 ( V_8 ) ;
F_3 ( V_89 -> V_8 == NULL ) ;
F_3 ( ! F_72 ( & V_89 -> V_111 ) ) ;
F_193 ( & V_89 -> V_111 , & V_8 -> V_114 ) ;
F_39 ( L_131 , V_89 ,
F_166 ( V_8 -> V_129 ) , F_120 ( V_89 -> V_198 . type ) ,
F_174 ( F_120 ( V_89 -> V_198 . type ) ) ,
F_119 ( V_89 -> V_198 . V_200 ) ,
F_119 ( V_89 -> V_198 . V_201 ) ,
F_119 ( V_89 -> V_198 . V_180 ) ) ;
F_191 ( V_8 ) ;
F_78 ( & V_8 -> V_122 ) ;
if ( F_11 ( V_8 , V_4 ) == 0 )
F_46 ( V_8 ) ;
}
void F_194 ( struct V_35 * V_89 )
{
struct V_7 * V_8 = V_89 -> V_8 ;
if ( ! V_8 )
return;
F_76 ( & V_8 -> V_122 ) ;
if ( ! F_72 ( & V_89 -> V_111 ) ) {
F_39 ( L_132 , V_46 , V_8 , V_89 ) ;
F_69 ( & V_89 -> V_111 ) ;
F_3 ( V_89 -> V_8 == NULL ) ;
V_89 -> V_8 -> V_75 -> V_112 ( V_89 -> V_8 ) ;
V_89 -> V_8 = NULL ;
V_89 -> V_198 . V_199 = 0 ;
F_70 ( V_89 ) ;
}
if ( V_8 -> V_119 == V_89 ) {
F_39 ( L_133 , V_46 , V_8 , V_89 ) ;
V_8 -> V_119 = NULL ;
if ( V_8 -> V_185 ) {
V_8 -> V_245 = V_8 -> V_140 ;
V_8 -> V_185 = false ;
}
V_89 -> V_198 . V_199 = 0 ;
F_70 ( V_89 ) ;
}
F_78 ( & V_8 -> V_122 ) ;
}
void F_195 ( struct V_35 * V_89 )
{
struct V_7 * V_8 ;
F_3 ( V_89 == NULL ) ;
if ( ! V_89 -> V_8 ) {
F_39 ( L_134 , V_46 , V_89 ) ;
return;
}
V_8 = V_89 -> V_8 ;
F_76 ( & V_8 -> V_122 ) ;
if ( V_8 -> V_116 == V_89 ) {
unsigned int V_200 = F_119 ( V_8 -> V_308 . V_200 ) ;
unsigned int V_201 = F_119 ( V_8 -> V_308 . V_201 ) ;
unsigned int V_180 = F_119 ( V_8 -> V_308 . V_180 ) ;
F_39 ( L_135 , V_46 , V_8 , V_89 ) ;
V_8 -> V_247 = V_8 -> V_247 -
sizeof( struct V_206 ) -
V_200 -
V_201 -
V_180 -
sizeof( struct V_343 ) ;
F_70 ( V_8 -> V_116 ) ;
V_8 -> V_116 = NULL ;
V_8 -> V_248 = V_250 ;
V_8 -> V_120 ++ ;
} else {
F_39 ( L_136 ,
V_46 , V_8 , V_8 -> V_116 , V_89 ) ;
}
F_78 ( & V_8 -> V_122 ) ;
}
void F_196 ( struct V_7 * V_8 )
{
F_39 ( L_137 , V_8 ) ;
F_76 ( & V_8 -> V_122 ) ;
F_191 ( V_8 ) ;
F_78 ( & V_8 -> V_122 ) ;
if ( F_11 ( V_8 , V_3 ) == 0 &&
F_11 ( V_8 , V_4 ) == 0 )
F_46 ( V_8 ) ;
}
static struct V_38 * F_197 ( enum V_344 type )
{
struct V_38 * V_143 ;
if ( F_37 ( ! F_198 ( type ) ) )
return NULL ;
V_143 = F_199 ( V_37 , V_72 ) ;
if ( V_143 )
V_143 -> type = type ;
F_84 ( & V_143 -> V_178 ) ;
return V_143 ;
}
static void F_200 ( struct V_38 * V_143 )
{
if ( ! V_143 )
return;
F_37 ( ! F_72 ( & V_143 -> V_178 ) ) ;
if ( V_143 -> type == V_171 )
F_201 ( V_143 -> V_170 ) ;
F_202 ( V_37 , V_143 ) ;
}
void F_203 ( struct V_35 * V_89 , struct V_95 * * V_162 ,
T_1 V_97 , T_1 V_163 )
{
struct V_38 * V_143 ;
F_3 ( ! V_162 ) ;
F_3 ( ! V_97 ) ;
V_143 = F_197 ( V_161 ) ;
F_3 ( ! V_143 ) ;
V_143 -> V_162 = V_162 ;
V_143 -> V_97 = V_97 ;
V_143 -> V_163 = V_163 & ~ V_165 ;
F_193 ( & V_143 -> V_178 , & V_89 -> V_143 ) ;
V_89 -> V_176 += V_97 ;
}
void F_204 ( struct V_35 * V_89 ,
struct V_169 * V_170 )
{
struct V_38 * V_143 ;
F_3 ( ! V_170 ) ;
F_3 ( ! V_170 -> V_97 ) ;
V_143 = F_197 ( V_171 ) ;
F_3 ( ! V_143 ) ;
V_143 -> V_170 = V_170 ;
F_193 ( & V_143 -> V_178 , & V_89 -> V_143 ) ;
V_89 -> V_176 += V_170 -> V_97 ;
}
void F_205 ( struct V_35 * V_89 , struct V_147 * V_147 ,
T_1 V_97 )
{
struct V_38 * V_143 ;
F_3 ( ! V_147 ) ;
V_143 = F_197 ( V_148 ) ;
F_3 ( ! V_143 ) ;
V_143 -> V_147 = V_147 ;
V_143 -> V_150 = V_97 ;
F_193 ( & V_143 -> V_178 , & V_89 -> V_143 ) ;
V_89 -> V_176 += V_97 ;
}
struct V_35 * F_206 ( int type , int V_200 , T_6 V_9 ,
bool V_345 )
{
struct V_35 * V_181 ;
V_181 = F_199 ( V_34 , V_9 ) ;
if ( V_181 == NULL )
goto V_240;
V_181 -> V_198 . type = F_207 ( type ) ;
V_181 -> V_198 . V_346 = F_207 ( V_347 ) ;
V_181 -> V_198 . V_200 = F_123 ( V_200 ) ;
F_84 ( & V_181 -> V_111 ) ;
F_208 ( & V_181 -> V_348 ) ;
F_84 ( & V_181 -> V_143 ) ;
if ( V_200 ) {
V_181 -> V_202 . V_106 = F_209 ( V_200 , V_9 ) ;
if ( V_181 -> V_202 . V_106 == NULL ) {
F_39 ( L_138 ,
V_200 ) ;
goto V_349;
}
} else {
V_181 -> V_202 . V_106 = NULL ;
}
V_181 -> V_350 = V_181 -> V_202 . V_107 = V_200 ;
F_39 ( L_139 , V_181 , V_200 ) ;
return V_181 ;
V_349:
F_70 ( V_181 ) ;
V_240:
if ( ! V_345 ) {
F_31 ( L_140 , type ,
V_200 ) ;
F_37 ( 1 ) ;
} else {
F_39 ( L_140 , type ,
V_200 ) ;
}
return NULL ;
}
static int F_210 ( struct V_7 * V_8 , struct V_35 * V_89 )
{
int type = F_120 ( V_89 -> V_198 . type ) ;
int V_201 = F_119 ( V_89 -> V_198 . V_201 ) ;
F_39 ( L_141 , V_89 , type ,
F_174 ( type ) , V_201 ) ;
F_3 ( ! V_201 ) ;
F_3 ( V_89 -> V_204 ) ;
V_89 -> V_204 = F_211 ( V_201 , V_72 ) ;
if ( ! V_89 -> V_204 )
return - V_36 ;
return 0 ;
}
static int F_172 ( struct V_7 * V_8 , int * V_315 )
{
struct V_206 * V_198 = & V_8 -> V_308 ;
int V_201 = F_119 ( V_198 -> V_201 ) ;
struct V_35 * V_89 ;
int V_68 = 0 ;
F_3 ( V_8 -> V_116 != NULL ) ;
F_3 ( ! V_8 -> V_75 -> V_351 ) ;
F_78 ( & V_8 -> V_122 ) ;
V_89 = V_8 -> V_75 -> V_351 ( V_8 , V_198 , V_315 ) ;
F_76 ( & V_8 -> V_122 ) ;
if ( V_8 -> V_56 != V_297 ) {
if ( V_89 )
F_70 ( V_89 ) ;
return - V_94 ;
}
if ( V_89 ) {
F_3 ( * V_315 ) ;
V_8 -> V_116 = V_89 ;
V_8 -> V_116 -> V_8 = V_8 -> V_75 -> V_327 ( V_8 ) ;
F_3 ( V_8 -> V_116 -> V_8 == NULL ) ;
} else {
if ( * V_315 )
return 0 ;
V_8 -> V_263 = L_142 ;
return - V_36 ;
}
memcpy ( & V_8 -> V_116 -> V_198 , & V_8 -> V_308 , sizeof( V_8 -> V_308 ) ) ;
if ( V_201 && ! V_8 -> V_116 -> V_204 ) {
V_68 = F_210 ( V_8 , V_8 -> V_116 ) ;
if ( V_68 < 0 ) {
F_70 ( V_8 -> V_116 ) ;
V_8 -> V_116 = NULL ;
}
}
return V_68 ;
}
static void F_212 ( struct V_35 * V_181 )
{
F_39 ( L_113 , V_46 , V_181 ) ;
F_213 ( V_181 -> V_202 . V_106 ) ;
F_202 ( V_34 , V_181 ) ;
}
static void F_214 ( struct V_348 * V_348 )
{
struct V_35 * V_181 = F_184 ( V_348 , struct V_35 , V_348 ) ;
F_215 ( V_143 ) ;
struct V_111 * V_178 ;
struct V_111 * V_352 ;
F_39 ( L_113 , V_46 , V_181 ) ;
F_37 ( ! F_72 ( & V_181 -> V_111 ) ) ;
if ( V_181 -> V_204 ) {
F_216 ( V_181 -> V_204 ) ;
V_181 -> V_204 = NULL ;
}
F_186 ( & V_181 -> V_143 , & V_143 ) ;
F_217 (links, next, &data) {
struct V_38 * V_143 ;
V_143 = F_218 ( V_178 , struct V_38 , V_178 ) ;
F_69 ( V_178 ) ;
F_200 ( V_143 ) ;
}
V_181 -> V_176 = 0 ;
if ( V_181 -> V_353 )
F_219 ( V_181 -> V_353 , V_181 ) ;
else
F_212 ( V_181 ) ;
}
struct V_35 * F_117 ( struct V_35 * V_89 )
{
F_39 ( L_143 , V_46 , V_89 ,
F_45 ( & V_89 -> V_348 . V_354 ) ) ;
F_220 ( & V_89 -> V_348 ) ;
return V_89 ;
}
void F_70 ( struct V_35 * V_89 )
{
F_39 ( L_143 , V_46 , V_89 ,
F_45 ( & V_89 -> V_348 . V_354 ) ) ;
F_221 ( & V_89 -> V_348 , F_214 ) ;
}
void F_222 ( struct V_35 * V_89 )
{
F_223 ( L_144 , V_89 ,
V_89 -> V_350 , V_89 -> V_176 ) ;
F_224 ( V_355 , L_145 ,
V_356 , 16 , 1 ,
& V_89 -> V_198 , sizeof( V_89 -> V_198 ) , true ) ;
F_224 ( V_355 , L_146 ,
V_356 , 16 , 1 ,
V_89 -> V_202 . V_106 , V_89 -> V_202 . V_107 , true ) ;
if ( V_89 -> V_204 )
F_224 ( V_355 , L_147 ,
V_356 , 16 , 1 ,
V_89 -> V_204 -> V_205 . V_106 ,
V_89 -> V_204 -> V_205 . V_107 , true ) ;
F_224 ( V_355 , L_148 ,
V_356 , 16 , 1 ,
& V_89 -> V_183 , sizeof( V_89 -> V_183 ) , true ) ;
}
