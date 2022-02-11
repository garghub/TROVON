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
}
void F_78 ( struct V_7 * V_8 )
{
F_79 ( & V_8 -> V_121 ) ;
F_38 ( L_23 , V_8 ,
F_13 ( & V_8 -> V_66 . V_67 ) ) ;
V_8 -> V_56 = V_122 ;
F_2 ( V_8 , V_2 ) ;
F_2 ( V_8 , V_3 ) ;
F_2 ( V_8 , V_4 ) ;
F_2 ( V_8 , V_6 ) ;
F_77 ( V_8 ) ;
V_8 -> V_123 = 0 ;
F_80 ( V_8 ) ;
F_70 ( V_8 ) ;
F_81 ( & V_8 -> V_121 ) ;
}
void F_82 ( struct V_7 * V_8 ,
T_2 V_124 , T_3 V_125 ,
struct V_126 * V_33 )
{
F_79 ( & V_8 -> V_121 ) ;
F_38 ( L_24 , V_8 , F_13 ( & V_33 -> V_67 ) ) ;
F_36 ( V_8 -> V_56 != V_122 ) ;
V_8 -> V_56 = V_127 ;
V_8 -> V_128 . type = ( T_2 ) V_124 ;
V_8 -> V_128 . V_129 = F_83 ( V_125 ) ;
memcpy ( & V_8 -> V_66 , V_33 , sizeof( * V_33 ) ) ;
V_8 -> V_130 = 0 ;
F_81 ( & V_8 -> V_121 ) ;
F_45 ( V_8 ) ;
}
bool F_84 ( struct V_7 * V_8 )
{
return V_8 -> V_116 > 0 ;
}
void F_85 ( struct V_7 * V_8 , void * V_131 ,
const struct V_132 * V_76 ,
struct V_29 * V_30 )
{
F_38 ( L_25 , V_8 ) ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> V_131 = V_131 ;
V_8 -> V_76 = V_76 ;
V_8 -> V_30 = V_30 ;
F_34 ( V_8 ) ;
F_86 ( & V_8 -> V_121 ) ;
F_87 ( & V_8 -> V_113 ) ;
F_87 ( & V_8 -> V_114 ) ;
F_88 ( & V_8 -> V_133 , V_134 ) ;
V_8 -> V_56 = V_122 ;
}
static T_4 F_89 ( struct V_29 * V_30 , T_4 V_135 )
{
T_4 V_68 ;
F_90 ( & V_30 -> V_136 ) ;
if ( V_30 -> V_137 < V_135 )
V_30 -> V_137 = V_135 ;
V_68 = ++ V_30 -> V_137 ;
F_91 ( & V_30 -> V_136 ) ;
return V_68 ;
}
static void F_92 ( struct V_7 * V_8 )
{
V_8 -> V_138 = 0 ;
V_8 -> V_139 = 0 ;
V_8 -> V_140 = & V_8 -> V_141 [ 0 ] ;
}
static void F_93 ( struct V_7 * V_8 ,
T_1 V_105 , void * V_142 )
{
int V_143 ;
V_143 = V_8 -> V_138 ;
F_3 ( V_143 >= F_94 ( V_8 -> V_141 ) ) ;
V_8 -> V_141 [ V_143 ] . V_107 = V_105 ;
V_8 -> V_141 [ V_143 ] . V_106 = V_142 ;
V_8 -> V_138 ++ ;
V_8 -> V_139 += V_105 ;
}
static void F_95 ( struct V_144 * V_145 ,
T_1 V_97 )
{
struct V_38 * V_142 = V_145 -> V_142 ;
struct V_146 * V_146 ;
F_3 ( V_142 -> type != V_147 ) ;
V_146 = V_142 -> V_146 ;
F_3 ( ! V_146 ) ;
V_145 -> V_148 = F_96 ( V_97 , V_142 -> V_149 ) ;
V_145 -> V_146 = V_146 ;
V_145 -> V_150 = V_146 -> V_151 ;
V_145 -> V_152 =
V_145 -> V_148 <= F_97 ( V_146 , V_145 -> V_150 ) ;
}
static struct V_95 * F_98 ( struct V_144 * V_145 ,
T_1 * V_96 ,
T_1 * V_97 )
{
struct V_38 * V_142 = V_145 -> V_142 ;
struct V_146 * V_146 ;
struct V_153 V_153 ;
F_3 ( V_142 -> type != V_147 ) ;
V_146 = V_145 -> V_146 ;
F_3 ( ! V_146 ) ;
V_153 = F_99 ( V_146 , V_145 -> V_150 ) ;
* V_96 = ( T_1 ) V_153 . V_154 ;
F_3 ( * V_96 >= V_99 ) ;
if ( V_145 -> V_152 )
* V_97 = V_145 -> V_148 ;
else
* V_97 = ( T_1 ) V_153 . V_155 ;
F_3 ( * V_97 > V_145 -> V_148 ) ;
F_3 ( * V_96 + * V_97 > V_99 ) ;
return V_153 . V_156 ;
}
static bool F_100 ( struct V_144 * V_145 ,
T_1 V_157 )
{
struct V_146 * V_146 ;
struct V_153 V_153 ;
F_3 ( V_145 -> V_142 -> type != V_147 ) ;
V_146 = V_145 -> V_146 ;
F_3 ( ! V_146 ) ;
V_153 = F_99 ( V_146 , V_145 -> V_150 ) ;
F_3 ( V_145 -> V_148 < V_157 ) ;
V_145 -> V_148 -= V_157 ;
F_101 ( V_146 , & V_145 -> V_150 , V_157 ) ;
if ( V_157 < V_153 . V_155 )
return false ;
if ( ! V_145 -> V_150 . V_158 ) {
V_146 = V_146 -> V_159 ;
V_145 -> V_146 = V_146 ;
if ( V_146 )
V_145 -> V_150 = V_146 -> V_151 ;
else
memset ( & V_145 -> V_150 , 0 ,
sizeof( V_145 -> V_150 ) ) ;
}
if ( ! V_145 -> V_152 ) {
F_3 ( ! V_145 -> V_148 ) ;
F_3 ( ! V_146 ) ;
if ( V_145 -> V_148 <= F_97 ( V_146 , V_145 -> V_150 ) )
V_145 -> V_152 = true ;
}
return true ;
}
static void F_102 ( struct V_144 * V_145 ,
T_1 V_97 )
{
struct V_38 * V_142 = V_145 -> V_142 ;
int F_69 ;
F_3 ( V_142 -> type != V_160 ) ;
F_3 ( ! V_142 -> V_161 ) ;
F_3 ( ! V_142 -> V_97 ) ;
V_145 -> V_148 = F_96 ( V_97 , V_142 -> V_97 ) ;
F_69 = F_103 ( V_142 -> V_162 , ( V_163 ) V_142 -> V_97 ) ;
V_145 -> V_96 = V_142 -> V_162 & ~ V_164 ;
V_145 -> V_165 = 0 ;
F_3 ( F_69 > ( int ) V_166 ) ;
V_145 -> F_69 = ( unsigned short ) F_69 ;
F_3 ( V_97 > V_167 - V_145 -> V_96 ) ;
V_145 -> V_152 = V_145 -> V_96 + V_145 -> V_148 <= V_99 ;
}
static struct V_95 *
F_104 ( struct V_144 * V_145 ,
T_1 * V_96 , T_1 * V_97 )
{
struct V_38 * V_142 = V_145 -> V_142 ;
F_3 ( V_142 -> type != V_160 ) ;
F_3 ( V_145 -> V_165 >= V_145 -> F_69 ) ;
F_3 ( V_145 -> V_96 >= V_99 ) ;
* V_96 = V_145 -> V_96 ;
if ( V_145 -> V_152 )
* V_97 = V_145 -> V_148 ;
else
* V_97 = V_99 - * V_96 ;
return V_142 -> V_161 [ V_145 -> V_165 ] ;
}
static bool F_105 ( struct V_144 * V_145 ,
T_1 V_157 )
{
F_3 ( V_145 -> V_142 -> type != V_160 ) ;
F_3 ( V_145 -> V_96 + V_157 > V_99 ) ;
V_145 -> V_148 -= V_157 ;
V_145 -> V_96 = ( V_145 -> V_96 + V_157 ) & ~ V_164 ;
if ( ! V_157 || V_145 -> V_96 )
return false ;
if ( ! V_145 -> V_148 )
return false ;
F_3 ( V_145 -> V_165 >= V_145 -> F_69 ) ;
V_145 -> V_165 ++ ;
V_145 -> V_152 = V_145 -> V_148 <= V_99 ;
return true ;
}
static void
F_106 ( struct V_144 * V_145 ,
T_1 V_97 )
{
struct V_38 * V_142 = V_145 -> V_142 ;
struct V_168 * V_169 ;
struct V_95 * V_95 ;
F_3 ( V_142 -> type != V_170 ) ;
V_169 = V_142 -> V_169 ;
F_3 ( ! V_169 ) ;
if ( ! V_97 )
return;
F_3 ( F_75 ( & V_169 -> V_112 ) ) ;
V_95 = F_76 ( & V_169 -> V_112 , struct V_95 , V_171 ) ;
V_145 -> V_148 = F_96 ( V_97 , V_169 -> V_97 ) ;
V_145 -> V_95 = V_95 ;
V_145 -> V_104 = 0 ;
V_145 -> V_152 = V_145 -> V_148 <= V_99 ;
}
static struct V_95 *
F_107 ( struct V_144 * V_145 ,
T_1 * V_96 , T_1 * V_97 )
{
struct V_38 * V_142 = V_145 -> V_142 ;
struct V_168 * V_169 ;
F_3 ( V_142 -> type != V_170 ) ;
V_169 = V_142 -> V_169 ;
F_3 ( ! V_169 ) ;
F_3 ( ! V_145 -> V_95 ) ;
F_3 ( V_145 -> V_104 + V_145 -> V_148 != V_169 -> V_97 ) ;
* V_96 = V_145 -> V_104 & ~ V_164 ;
if ( V_145 -> V_152 )
* V_97 = V_145 -> V_148 ;
else
* V_97 = V_99 - * V_96 ;
return V_145 -> V_95 ;
}
static bool F_108 ( struct V_144 * V_145 ,
T_1 V_157 )
{
struct V_38 * V_142 = V_145 -> V_142 ;
struct V_168 * V_169 ;
F_3 ( V_142 -> type != V_170 ) ;
V_169 = V_142 -> V_169 ;
F_3 ( ! V_169 ) ;
F_3 ( V_145 -> V_104 + V_145 -> V_148 != V_169 -> V_97 ) ;
F_3 ( ( V_145 -> V_104 & ~ V_164 ) + V_157 > V_99 ) ;
V_145 -> V_148 -= V_157 ;
V_145 -> V_104 += V_157 ;
if ( ! V_157 || V_145 -> V_104 & ~ V_164 )
return false ;
if ( ! V_145 -> V_148 )
return false ;
F_3 ( F_109 ( & V_145 -> V_95 -> V_171 , & V_169 -> V_112 ) ) ;
V_145 -> V_95 = F_110 ( V_145 -> V_95 , V_171 ) ;
V_145 -> V_152 = V_145 -> V_148 <= V_99 ;
return true ;
}
static void F_111 ( struct V_144 * V_145 )
{
T_1 V_97 = V_145 -> V_172 ;
switch ( V_145 -> V_142 -> type ) {
case V_170 :
F_106 ( V_145 , V_97 ) ;
break;
case V_160 :
F_102 ( V_145 , V_97 ) ;
break;
#ifdef F_112
case V_147 :
F_95 ( V_145 , V_97 ) ;
break;
#endif
case V_173 :
default:
break;
}
V_145 -> V_174 = true ;
}
static void F_113 ( struct V_35 * V_89 , T_1 V_97 )
{
struct V_144 * V_145 = & V_89 -> V_145 ;
struct V_38 * V_142 ;
F_3 ( ! V_97 ) ;
F_3 ( V_97 > V_89 -> V_175 ) ;
F_3 ( F_75 ( & V_89 -> V_142 ) ) ;
V_145 -> V_176 = & V_89 -> V_142 ;
V_145 -> V_172 = V_97 ;
V_142 = F_76 ( & V_89 -> V_142 , struct V_38 , V_177 ) ;
V_145 -> V_142 = V_142 ;
F_111 ( V_145 ) ;
}
static struct V_95 * F_114 ( struct V_144 * V_145 ,
T_1 * V_96 , T_1 * V_97 ,
bool * V_152 )
{
struct V_95 * V_95 ;
switch ( V_145 -> V_142 -> type ) {
case V_170 :
V_95 = F_107 ( V_145 , V_96 , V_97 ) ;
break;
case V_160 :
V_95 = F_104 ( V_145 , V_96 , V_97 ) ;
break;
#ifdef F_112
case V_147 :
V_95 = F_98 ( V_145 , V_96 , V_97 ) ;
break;
#endif
case V_173 :
default:
V_95 = NULL ;
break;
}
F_3 ( ! V_95 ) ;
F_3 ( * V_96 + * V_97 > V_99 ) ;
F_3 ( ! * V_97 ) ;
if ( V_152 )
* V_152 = V_145 -> V_152 ;
return V_95 ;
}
static bool F_115 ( struct V_144 * V_145 ,
T_1 V_157 )
{
bool V_178 ;
F_3 ( V_157 > V_145 -> V_148 ) ;
switch ( V_145 -> V_142 -> type ) {
case V_170 :
V_178 = F_108 ( V_145 , V_157 ) ;
break;
case V_160 :
V_178 = F_105 ( V_145 , V_157 ) ;
break;
#ifdef F_112
case V_147 :
V_178 = F_100 ( V_145 , V_157 ) ;
break;
#endif
case V_173 :
default:
F_116 () ;
break;
}
V_145 -> V_172 -= V_157 ;
if ( ! V_145 -> V_148 && V_145 -> V_172 ) {
F_36 ( ! V_145 -> V_152 ) ;
F_3 ( F_109 ( & V_145 -> V_142 -> V_177 , V_145 -> V_176 ) ) ;
V_145 -> V_142 = F_110 ( V_145 -> V_142 , V_177 ) ;
F_111 ( V_145 ) ;
V_178 = true ;
}
V_145 -> V_174 = V_178 ;
return V_178 ;
}
static void F_117 ( struct V_35 * V_89 , T_4 V_179 )
{
F_3 ( ! V_89 ) ;
F_3 ( ! V_179 ) ;
F_113 ( V_89 , ( T_1 ) V_179 ) ;
}
static void F_118 ( struct V_7 * V_8 )
{
struct V_35 * V_180 = V_8 -> V_118 ;
int V_181 = V_8 -> V_138 ;
V_180 -> V_182 . V_9 |= V_183 ;
F_38 ( L_26 , V_8 ) ;
V_8 -> V_184 = true ;
V_8 -> V_141 [ V_181 ] . V_106 = & V_180 -> V_182 ;
if ( V_8 -> V_185 & V_186 ) {
if ( V_8 -> V_76 -> V_187 )
V_8 -> V_76 -> V_187 ( V_180 ) ;
else
V_180 -> V_182 . V_188 = 0 ;
V_8 -> V_141 [ V_181 ] . V_107 = sizeof( V_180 -> V_182 ) ;
V_8 -> V_139 += sizeof( V_180 -> V_182 ) ;
} else {
V_180 -> V_189 . V_9 = V_180 -> V_182 . V_9 ;
V_8 -> V_141 [ V_181 ] . V_107 = sizeof( V_180 -> V_189 ) ;
V_8 -> V_139 += sizeof( V_180 -> V_189 ) ;
}
V_8 -> V_138 ++ ;
V_8 -> V_190 = V_180 -> V_191 ;
V_8 -> V_192 = true ;
}
static void F_119 ( struct V_7 * V_8 )
{
struct V_35 * V_180 ;
T_4 V_193 ;
F_92 ( V_8 ) ;
V_8 -> V_184 = true ;
V_8 -> V_192 = false ;
if ( V_8 -> V_119 > V_8 -> V_120 ) {
V_8 -> V_120 = V_8 -> V_119 ;
F_93 ( V_8 , sizeof ( V_194 ) , & V_194 ) ;
V_8 -> V_195 = F_83 ( V_8 -> V_120 ) ;
F_93 ( V_8 , sizeof ( V_8 -> V_195 ) ,
& V_8 -> V_195 ) ;
}
F_3 ( F_75 ( & V_8 -> V_113 ) ) ;
V_180 = F_76 ( & V_8 -> V_113 , struct V_35 , V_111 ) ;
V_8 -> V_118 = V_180 ;
F_3 ( V_180 -> V_8 != V_8 ) ;
F_120 ( V_180 ) ;
F_121 ( & V_180 -> V_111 , & V_8 -> V_114 ) ;
if ( V_180 -> V_196 ) {
V_180 -> V_197 . V_198 = F_83 ( ++ V_8 -> V_117 ) ;
V_180 -> V_196 = false ;
}
F_36 ( V_180 -> V_175 != F_122 ( V_180 -> V_197 . V_179 ) ) ;
F_38 ( L_27 ,
V_180 , V_8 -> V_117 , F_123 ( V_180 -> V_197 . type ) ,
F_122 ( V_180 -> V_197 . V_199 ) , F_122 ( V_180 -> V_197 . V_200 ) ,
V_180 -> V_175 ) ;
F_3 ( F_122 ( V_180 -> V_197 . V_199 ) != V_180 -> V_201 . V_107 ) ;
F_93 ( V_8 , sizeof ( V_202 ) , & V_202 ) ;
F_93 ( V_8 , sizeof ( V_180 -> V_197 ) , & V_180 -> V_197 ) ;
F_93 ( V_8 , V_180 -> V_201 . V_107 , V_180 -> V_201 . V_106 ) ;
if ( V_180 -> V_203 )
F_93 ( V_8 , V_180 -> V_203 -> V_204 . V_107 ,
V_180 -> V_203 -> V_204 . V_106 ) ;
V_193 = F_124 ( 0 , & V_180 -> V_197 , F_125 ( struct V_205 , V_193 ) ) ;
V_8 -> V_118 -> V_197 . V_193 = F_126 ( V_193 ) ;
V_8 -> V_118 -> V_182 . V_9 = 0 ;
V_193 = F_124 ( 0 , V_180 -> V_201 . V_106 , V_180 -> V_201 . V_107 ) ;
V_8 -> V_118 -> V_182 . V_206 = F_126 ( V_193 ) ;
if ( V_180 -> V_203 ) {
V_193 = F_124 ( 0 , V_180 -> V_203 -> V_204 . V_106 ,
V_180 -> V_203 -> V_204 . V_107 ) ;
V_8 -> V_118 -> V_182 . V_207 = F_126 ( V_193 ) ;
} else
V_8 -> V_118 -> V_182 . V_207 = 0 ;
F_38 ( L_28 , V_46 ,
F_122 ( V_8 -> V_118 -> V_182 . V_206 ) ,
F_122 ( V_8 -> V_118 -> V_182 . V_207 ) ) ;
V_8 -> V_118 -> V_182 . V_208 = 0 ;
if ( V_180 -> V_175 ) {
F_117 ( V_8 -> V_118 , V_180 -> V_175 ) ;
V_8 -> V_190 = 1 ;
} else {
F_118 ( V_8 ) ;
}
F_5 ( V_8 , V_4 ) ;
}
static void F_127 ( struct V_7 * V_8 )
{
F_38 ( L_29 , V_8 ,
V_8 -> V_120 , V_8 -> V_119 ) ;
V_8 -> V_120 = V_8 -> V_119 ;
F_92 ( V_8 ) ;
F_93 ( V_8 , sizeof ( V_194 ) , & V_194 ) ;
V_8 -> V_195 = F_83 ( V_8 -> V_120 ) ;
F_93 ( V_8 , sizeof ( V_8 -> V_195 ) ,
& V_8 -> V_195 ) ;
V_8 -> V_190 = 1 ;
F_5 ( V_8 , V_4 ) ;
}
static void F_128 ( struct V_7 * V_8 )
{
F_38 ( L_30 , V_8 ,
V_8 -> V_120 , V_8 -> V_119 ) ;
V_8 -> V_120 = V_8 -> V_119 ;
F_92 ( V_8 ) ;
V_8 -> V_195 = F_83 ( V_8 -> V_120 ) ;
F_93 ( V_8 , sizeof ( V_8 -> V_195 ) ,
& V_8 -> V_195 ) ;
F_5 ( V_8 , V_4 ) ;
}
static void F_129 ( struct V_7 * V_8 )
{
F_38 ( L_31 , V_8 ) ;
F_92 ( V_8 ) ;
if ( V_8 -> V_185 & V_209 ) {
struct V_210 V_211 = V_212 ;
F_93 ( V_8 , sizeof( V_213 ) , & V_213 ) ;
F_130 ( & V_8 -> V_214 , & V_211 ) ;
F_93 ( V_8 , sizeof( V_8 -> V_214 ) ,
& V_8 -> V_214 ) ;
} else {
F_93 ( V_8 , sizeof( V_215 ) , & V_215 ) ;
}
F_5 ( V_8 , V_4 ) ;
}
static struct V_216 * F_131 ( struct V_7 * V_8 ,
int * V_217 )
{
struct V_216 * V_218 ;
if ( ! V_8 -> V_76 -> V_219 ) {
V_8 -> V_220 . V_221 = V_222 ;
V_8 -> V_220 . V_223 = 0 ;
return NULL ;
}
F_81 ( & V_8 -> V_121 ) ;
V_218 = V_8 -> V_76 -> V_219 ( V_8 , V_217 , V_8 -> V_224 ) ;
F_79 ( & V_8 -> V_121 ) ;
if ( F_132 ( V_218 ) )
return V_218 ;
if ( V_8 -> V_56 != V_225 )
return F_133 ( - V_94 ) ;
V_8 -> V_226 = V_218 -> V_227 ;
V_8 -> V_228 = V_218 -> V_229 ;
return V_218 ;
}
static void F_134 ( struct V_7 * V_8 )
{
F_93 ( V_8 , strlen ( V_230 ) , V_230 ) ;
F_93 ( V_8 , sizeof ( V_8 -> V_30 -> V_31 ) ,
& V_8 -> V_30 -> V_31 ) ;
V_8 -> V_190 = 0 ;
F_5 ( V_8 , V_4 ) ;
}
static int F_135 ( struct V_7 * V_8 )
{
unsigned int V_137 = F_89 ( V_8 -> V_30 , 0 ) ;
int V_231 ;
int V_217 ;
struct V_216 * V_218 ;
switch ( V_8 -> V_128 . type ) {
case V_232 :
V_231 = V_233 ;
break;
case V_234 :
V_231 = V_235 ;
break;
case V_236 :
V_231 = V_237 ;
break;
default:
F_116 () ;
}
F_38 ( L_32 , V_8 ,
V_8 -> V_116 , V_137 , V_231 ) ;
V_8 -> V_220 . V_238 =
F_83 ( F_57 ( V_8 -> V_30 ) -> V_239 ) ;
V_8 -> V_220 . V_240 = F_126 ( V_241 ) ;
V_8 -> V_220 . V_116 = F_126 ( V_8 -> V_116 ) ;
V_8 -> V_220 . V_137 = F_126 ( V_137 ) ;
V_8 -> V_220 . V_242 = F_126 ( V_231 ) ;
V_8 -> V_220 . V_9 = 0 ;
V_217 = V_222 ;
V_218 = F_131 ( V_8 , & V_217 ) ;
if ( F_132 ( V_218 ) )
return F_136 ( V_218 ) ;
V_8 -> V_220 . V_221 = F_126 ( V_217 ) ;
V_8 -> V_220 . V_223 = V_218 ?
F_126 ( V_218 -> V_243 ) : 0 ;
F_93 ( V_8 , sizeof ( V_8 -> V_220 ) ,
& V_8 -> V_220 ) ;
if ( V_218 && V_218 -> V_243 )
F_93 ( V_8 , V_218 -> V_243 ,
V_218 -> V_244 ) ;
V_8 -> V_190 = 0 ;
F_5 ( V_8 , V_4 ) ;
return 0 ;
}
static int F_137 ( struct V_7 * V_8 )
{
int V_68 ;
F_38 ( L_33 , V_8 , V_8 -> V_139 ) ;
while ( V_8 -> V_139 > 0 ) {
V_68 = F_64 ( V_8 -> V_50 , V_8 -> V_140 ,
V_8 -> V_138 , V_8 -> V_139 ,
V_8 -> V_190 ) ;
if ( V_68 <= 0 )
goto V_245;
V_8 -> V_139 -= V_68 ;
if ( V_8 -> V_139 == 0 )
break;
while ( V_68 >= V_8 -> V_140 -> V_107 ) {
F_3 ( ! V_8 -> V_138 ) ;
V_68 -= V_8 -> V_140 -> V_107 ;
V_8 -> V_140 ++ ;
V_8 -> V_138 -- ;
}
if ( V_68 ) {
V_8 -> V_140 -> V_107 -= V_68 ;
V_8 -> V_140 -> V_106 += V_68 ;
}
}
V_8 -> V_138 = 0 ;
V_8 -> V_184 = false ;
V_68 = 1 ;
V_245:
F_38 ( L_34 , V_8 ,
V_8 -> V_139 , V_8 -> V_138 , V_68 ) ;
return V_68 ;
}
static T_4 F_138 ( T_4 V_193 , struct V_95 * V_95 ,
unsigned int V_96 ,
unsigned int V_97 )
{
char * V_98 ;
V_98 = F_62 ( V_95 ) ;
F_3 ( V_98 == NULL ) ;
V_193 = F_124 ( V_193 , V_98 + V_96 , V_97 ) ;
F_63 ( V_95 ) ;
return V_193 ;
}
static int F_139 ( struct V_7 * V_8 )
{
struct V_35 * V_89 = V_8 -> V_118 ;
struct V_144 * V_145 = & V_89 -> V_145 ;
bool V_246 = ! F_56 ( F_57 ( V_8 -> V_30 ) , V_247 ) ;
T_4 V_193 ;
F_38 ( L_35 , V_46 , V_8 , V_89 ) ;
if ( F_75 ( & V_89 -> V_142 ) )
return - V_248 ;
V_193 = V_246 ? F_122 ( V_89 -> V_182 . V_208 ) : 0 ;
while ( V_145 -> V_148 ) {
struct V_95 * V_95 ;
T_1 V_96 ;
T_1 V_97 ;
bool V_152 ;
bool V_174 ;
int V_68 ;
V_95 = F_114 ( V_145 , & V_96 , & V_97 ,
& V_152 ) ;
V_68 = F_68 ( V_8 -> V_50 , V_95 , V_96 ,
V_97 , ! V_152 ) ;
if ( V_68 <= 0 ) {
if ( V_246 )
V_89 -> V_182 . V_208 = F_126 ( V_193 ) ;
return V_68 ;
}
if ( V_246 && V_145 -> V_174 )
V_193 = F_138 ( V_193 , V_95 , V_96 , V_97 ) ;
V_174 = F_115 ( V_145 , ( T_1 ) V_68 ) ;
}
F_38 ( L_36 , V_46 , V_8 , V_89 ) ;
if ( V_246 )
V_89 -> V_182 . V_208 = F_126 ( V_193 ) ;
else
V_89 -> V_182 . V_9 |= V_249 ;
F_92 ( V_8 ) ;
F_118 ( V_8 ) ;
return 1 ;
}
static int F_140 ( struct V_7 * V_8 )
{
int V_68 ;
while ( V_8 -> V_250 > 0 ) {
T_1 V_105 = F_96 ( V_8 -> V_250 , ( int ) V_251 ) ;
V_68 = F_68 ( V_8 -> V_50 , V_40 , 0 , V_105 , true ) ;
if ( V_68 <= 0 )
goto V_245;
V_8 -> V_250 -= V_68 ;
}
V_68 = 1 ;
V_245:
return V_68 ;
}
static void F_141 ( struct V_7 * V_8 )
{
F_38 ( L_37 , V_8 ) ;
V_8 -> V_252 = 0 ;
}
static void F_142 ( struct V_7 * V_8 )
{
F_38 ( L_38 , V_8 ) ;
V_8 -> V_252 = 0 ;
}
static void F_143 ( struct V_7 * V_8 )
{
F_38 ( L_39 , V_8 ) ;
V_8 -> V_252 = 0 ;
}
static void F_144 ( struct V_7 * V_8 )
{
F_38 ( L_40 , V_8 ) ;
V_8 -> V_252 = 0 ;
V_8 -> V_253 = V_254 ;
}
static void F_145 ( struct V_7 * V_8 )
{
F_38 ( L_41 , V_8 ) ;
V_8 -> V_252 = 0 ;
V_8 -> V_253 = V_255 ;
}
static void F_146 ( struct V_7 * V_8 )
{
F_38 ( L_42 , V_8 ) ;
V_8 -> V_252 = 0 ;
}
static int F_147 ( struct V_7 * V_8 )
{
F_38 ( L_43 , V_8 ) ;
F_3 ( V_8 -> V_115 != NULL ) ;
V_8 -> V_252 = 0 ;
V_8 -> V_256 = V_8 -> V_257 = V_8 -> V_258 = 0 ;
return 0 ;
}
static int F_148 ( struct V_7 * V_8 ,
int V_259 , int V_105 , void * V_260 )
{
while ( V_8 -> V_252 < V_259 ) {
int V_261 = V_259 - V_8 -> V_252 ;
int V_262 = V_105 - V_261 ;
int V_68 = F_59 ( V_8 -> V_50 , V_260 + V_262 , V_261 ) ;
if ( V_68 <= 0 )
return V_68 ;
V_8 -> V_252 += V_68 ;
}
return 1 ;
}
static int F_149 ( struct V_7 * V_8 )
{
int V_105 ;
int V_259 ;
int V_68 ;
F_38 ( L_44 , V_8 , V_8 -> V_252 ) ;
V_105 = strlen ( V_230 ) ;
V_259 = V_105 ;
V_68 = F_148 ( V_8 , V_259 , V_105 , V_8 -> V_263 ) ;
if ( V_68 <= 0 )
goto V_245;
V_105 = sizeof ( V_8 -> V_264 ) ;
V_259 += V_105 ;
V_68 = F_148 ( V_8 , V_259 , V_105 , & V_8 -> V_264 ) ;
if ( V_68 <= 0 )
goto V_245;
V_105 = sizeof ( V_8 -> V_265 ) ;
V_259 += V_105 ;
V_68 = F_148 ( V_8 , V_259 , V_105 , & V_8 -> V_265 ) ;
if ( V_68 <= 0 )
goto V_245;
V_245:
return V_68 ;
}
static int F_150 ( struct V_7 * V_8 )
{
int V_105 ;
int V_259 ;
int V_68 ;
F_38 ( L_45 , V_8 , V_8 -> V_252 ) ;
V_105 = sizeof ( V_8 -> V_266 ) ;
V_259 = V_105 ;
V_68 = F_148 ( V_8 , V_259 , V_105 , & V_8 -> V_266 ) ;
if ( V_68 <= 0 )
goto V_245;
V_105 = F_122 ( V_8 -> V_266 . V_223 ) ;
V_259 += V_105 ;
V_68 = F_148 ( V_8 , V_259 , V_105 , V_8 -> V_226 ) ;
if ( V_68 <= 0 )
goto V_245;
F_38 ( L_46 ,
V_8 , ( int ) V_8 -> V_266 . V_267 ,
F_122 ( V_8 -> V_266 . V_116 ) ,
F_122 ( V_8 -> V_266 . V_137 ) ) ;
V_245:
return V_68 ;
}
static int F_151 ( struct V_7 * V_8 )
{
if ( memcmp ( V_8 -> V_263 , V_230 , strlen ( V_230 ) ) ) {
F_30 ( L_47 ,
F_13 ( & V_8 -> V_66 . V_67 ) ) ;
V_8 -> V_268 = L_48 ;
return - 1 ;
}
return 0 ;
}
static bool F_152 ( struct V_10 * V_11 )
{
struct V_67 * V_33 = & ( (struct V_14 * ) V_11 ) -> V_24 ;
struct V_269 * V_270 = & ( (struct V_16 * ) V_11 ) -> V_27 ;
switch ( V_11 -> V_21 ) {
case V_22 :
return V_33 -> V_271 == F_153 ( V_272 ) ;
case V_26 :
return F_154 ( V_270 ) ;
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
static void F_156 ( struct V_10 * V_11 , int V_273 )
{
switch ( V_11 -> V_21 ) {
case V_22 :
( (struct V_14 * ) V_11 ) -> V_25 = F_157 ( V_273 ) ;
break;
case V_26 :
( (struct V_16 * ) V_11 ) -> V_28 = F_157 ( V_273 ) ;
break;
}
}
static int F_158 ( const char * V_274 , T_1 V_85 , struct V_10 * V_11 ,
char V_275 , const char * * V_276 )
{
struct V_14 * V_15 = (struct V_14 * ) V_11 ;
struct V_16 * V_17 = (struct V_16 * ) V_11 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
if ( F_159 ( V_274 , V_85 , ( V_277 * ) & V_15 -> V_24 . V_271 , V_275 , V_276 ) ) {
V_11 -> V_21 = V_22 ;
return 0 ;
}
if ( F_160 ( V_274 , V_85 , ( V_277 * ) & V_17 -> V_27 . V_278 , V_275 , V_276 ) ) {
V_11 -> V_21 = V_26 ;
return 0 ;
}
return - V_248 ;
}
static int F_161 ( const char * V_279 , T_1 V_280 ,
struct V_10 * V_11 , char V_275 , const char * * V_276 )
{
const char * V_259 , * V_281 ;
char * V_282 , * V_283 = NULL ;
int V_284 , V_68 ;
V_281 = memchr ( V_279 , V_275 , V_280 ) ;
V_282 = memchr ( V_279 , ':' , V_280 ) ;
if ( V_281 && V_282 )
V_259 = V_281 < V_282 ? V_281 : V_282 ;
else if ( ! V_281 && V_282 )
V_259 = V_282 ;
else {
V_259 = V_281 ;
if ( ! V_259 )
V_259 = V_279 + V_280 ;
}
if ( V_259 <= V_279 )
return - V_248 ;
V_284 = F_162 ( NULL , V_279 , V_259 - V_279 , NULL , & V_283 , NULL ) ;
if ( V_284 > 0 )
V_68 = F_158 ( V_283 , V_284 , V_11 , - 1 , NULL ) ;
else
V_68 = - V_285 ;
F_163 ( V_283 ) ;
* V_276 = V_259 ;
F_164 ( L_49 , ( int ) ( V_259 - V_279 ) , V_279 ,
V_68 , V_68 ? L_50 : F_13 ( V_11 ) ) ;
return V_68 ;
}
static inline int F_161 ( const char * V_279 , T_1 V_280 ,
struct V_10 * V_11 , char V_275 , const char * * V_276 )
{
return - V_248 ;
}
static int F_165 ( const char * V_279 , T_1 V_280 ,
struct V_10 * V_11 , char V_275 , const char * * V_276 )
{
int V_68 ;
V_68 = F_158 ( V_279 , V_280 , V_11 , V_275 , V_276 ) ;
if ( V_68 )
V_68 = F_161 ( V_279 , V_280 , V_11 , V_275 , V_276 ) ;
return V_68 ;
}
int F_166 ( const char * V_286 , const char * V_259 ,
struct V_126 * V_33 ,
int V_287 , int * V_288 )
{
int V_12 , V_68 = - V_248 ;
const char * V_273 = V_286 ;
F_38 ( L_51 , ( int ) ( V_259 - V_286 ) , V_286 ) ;
for ( V_12 = 0 ; V_12 < V_287 ; V_12 ++ ) {
const char * V_276 ;
struct V_10 * V_11 = & V_33 [ V_12 ] . V_67 ;
int V_289 ;
char V_275 = ',' ;
if ( * V_273 == '[' ) {
V_275 = ']' ;
V_273 ++ ;
}
V_68 = F_165 ( V_273 , V_259 - V_273 , V_11 , V_275 , & V_276 ) ;
if ( V_68 )
goto V_290;
V_68 = - V_248 ;
V_273 = V_276 ;
if ( V_275 == ']' ) {
if ( * V_273 != ']' ) {
F_38 ( L_52 ) ;
goto V_290;
}
V_273 ++ ;
}
if ( V_273 < V_259 && * V_273 == ':' ) {
V_289 = 0 ;
V_273 ++ ;
while ( V_273 < V_259 && * V_273 >= '0' && * V_273 <= '9' ) {
V_289 = ( V_289 * 10 ) + ( * V_273 - '0' ) ;
V_273 ++ ;
}
if ( V_289 == 0 )
V_289 = V_291 ;
else if ( V_289 > 65535 )
goto V_290;
} else {
V_289 = V_291 ;
}
F_156 ( V_11 , V_289 ) ;
F_38 ( L_53 , F_13 ( V_11 ) ) ;
if ( V_273 == V_259 )
break;
if ( * V_273 != ',' )
goto V_290;
V_273 ++ ;
}
if ( V_273 != V_259 )
goto V_290;
if ( V_288 )
* V_288 = V_12 + 1 ;
return 0 ;
V_290:
F_30 ( L_54 , ( int ) ( V_259 - V_286 ) , V_286 ) ;
return V_68 ;
}
static int F_167 ( struct V_7 * V_8 )
{
F_38 ( L_55 , V_8 ) ;
if ( F_151 ( V_8 ) < 0 )
return - 1 ;
F_168 ( & V_8 -> V_264 ) ;
F_168 ( & V_8 -> V_265 ) ;
if ( memcmp ( & V_8 -> V_66 , & V_8 -> V_264 ,
sizeof( V_8 -> V_66 ) ) != 0 &&
! ( F_152 ( & V_8 -> V_264 . V_67 ) &&
V_8 -> V_264 . V_292 == V_8 -> V_66 . V_292 ) ) {
F_169 ( L_56 ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
( int ) F_122 ( V_8 -> V_66 . V_292 ) ,
F_13 ( & V_8 -> V_264 . V_67 ) ,
( int ) F_122 ( V_8 -> V_264 . V_292 ) ) ;
V_8 -> V_268 = L_57 ;
return - 1 ;
}
if ( F_152 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ) ) {
int V_289 = F_155 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ) ;
memcpy ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ,
& V_8 -> V_265 . V_67 ,
sizeof( V_8 -> V_265 . V_67 ) ) ;
F_156 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 , V_289 ) ;
F_16 ( V_8 -> V_30 ) ;
F_38 ( L_58 ,
F_13 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ) ) ;
}
return 0 ;
}
static int F_170 ( struct V_7 * V_8 )
{
V_163 V_293 = F_57 ( V_8 -> V_30 ) -> V_239 ;
V_163 V_294 = F_57 ( V_8 -> V_30 ) -> V_295 ;
V_163 V_296 = F_171 (
F_172 ( V_8 -> V_266 . V_238 ) ) ;
int V_68 ;
F_38 ( L_59 , V_8 , ( int ) V_8 -> V_253 ) ;
switch ( V_8 -> V_266 . V_267 ) {
case V_297 :
F_30 ( L_60
L_61 ,
F_173 ( V_8 -> V_128 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_293 , V_296 , V_296 & ~ V_293 ) ;
V_8 -> V_268 = L_62 ;
F_77 ( V_8 ) ;
return - 1 ;
case V_298 :
F_30 ( L_63
L_64 ,
F_173 ( V_8 -> V_128 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
F_122 ( V_8 -> V_220 . V_242 ) ,
F_122 ( V_8 -> V_266 . V_242 ) ) ;
V_8 -> V_268 = L_65 ;
F_77 ( V_8 ) ;
return - 1 ;
case V_299 :
V_8 -> V_224 ++ ;
F_38 ( L_66 , V_8 ,
V_8 -> V_224 ) ;
if ( V_8 -> V_224 == 2 ) {
V_8 -> V_268 = L_67 ;
return - 1 ;
}
F_92 ( V_8 ) ;
V_68 = F_135 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_142 ( V_8 ) ;
break;
case V_300 :
F_38 ( L_68 ,
F_122 ( V_8 -> V_266 . V_116 ) ) ;
F_30 ( L_69 ,
F_173 ( V_8 -> V_128 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ) ;
F_77 ( V_8 ) ;
F_92 ( V_8 ) ;
V_68 = F_135 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_142 ( V_8 ) ;
F_81 ( & V_8 -> V_121 ) ;
F_164 ( L_70 , F_173 ( V_8 -> V_128 ) ) ;
if ( V_8 -> V_76 -> V_301 )
V_8 -> V_76 -> V_301 ( V_8 ) ;
F_79 ( & V_8 -> V_121 ) ;
if ( V_8 -> V_56 != V_225 )
return - V_94 ;
break;
case V_302 :
F_38 ( L_71 ,
F_122 ( V_8 -> V_220 . V_116 ) ,
F_122 ( V_8 -> V_266 . V_116 ) ) ;
V_8 -> V_116 = F_122 ( V_8 -> V_266 . V_116 ) ;
F_92 ( V_8 ) ;
V_68 = F_135 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_142 ( V_8 ) ;
break;
case V_303 :
F_38 ( L_72 ,
V_8 -> V_123 ,
F_122 ( V_8 -> V_266 . V_137 ) ) ;
F_89 ( V_8 -> V_30 ,
F_122 ( V_8 -> V_266 . V_137 ) ) ;
F_92 ( V_8 ) ;
V_68 = F_135 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_142 ( V_8 ) ;
break;
case V_254 :
case V_255 :
if ( V_294 & ~ V_296 ) {
F_30 ( L_73
L_74 ,
F_173 ( V_8 -> V_128 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_294 , V_296 , V_294 & ~ V_296 ) ;
V_8 -> V_268 = L_62 ;
F_77 ( V_8 ) ;
return - 1 ;
}
F_36 ( V_8 -> V_56 != V_225 ) ;
V_8 -> V_56 = V_304 ;
V_8 -> V_224 = 0 ;
V_8 -> V_123 = F_122 ( V_8 -> V_266 . V_137 ) ;
V_8 -> V_116 ++ ;
V_8 -> V_185 = V_296 ;
F_38 ( L_75 ,
V_8 -> V_123 ,
F_122 ( V_8 -> V_266 . V_116 ) ,
V_8 -> V_116 ) ;
F_36 ( V_8 -> V_116 !=
F_122 ( V_8 -> V_266 . V_116 ) ) ;
if ( V_8 -> V_266 . V_9 & V_305 )
F_5 ( V_8 , V_2 ) ;
V_8 -> V_130 = 0 ;
if ( V_8 -> V_266 . V_267 == V_254 ) {
F_128 ( V_8 ) ;
F_144 ( V_8 ) ;
} else {
F_145 ( V_8 ) ;
}
break;
case V_306 :
V_8 -> V_268 = L_76 ;
return - 1 ;
default:
V_8 -> V_268 = L_77 ;
return - 1 ;
}
return 0 ;
}
static int F_174 ( struct V_7 * V_8 )
{
int V_105 = sizeof ( V_8 -> V_307 ) ;
int V_259 = V_105 ;
return F_148 ( V_8 , V_259 , V_105 , & V_8 -> V_307 ) ;
}
static void F_175 ( struct V_7 * V_8 )
{
struct V_35 * V_180 ;
V_163 V_308 = F_172 ( V_8 -> V_307 ) ;
V_163 V_198 ;
while ( ! F_75 ( & V_8 -> V_114 ) ) {
V_180 = F_76 ( & V_8 -> V_114 , struct V_35 ,
V_111 ) ;
V_198 = F_172 ( V_180 -> V_197 . V_198 ) ;
if ( V_198 > V_308 )
break;
F_38 ( L_78 , V_198 ,
F_123 ( V_180 -> V_197 . type ) , V_180 ) ;
V_180 -> V_309 = V_310 ;
F_71 ( V_180 ) ;
}
F_145 ( V_8 ) ;
}
static int F_176 ( struct V_7 * V_8 ,
struct V_86 * V_311 ,
unsigned int V_312 , T_4 * V_193 )
{
int V_68 , V_261 ;
F_3 ( ! V_311 ) ;
while ( V_311 -> V_107 < V_312 ) {
F_3 ( V_311 -> V_106 == NULL ) ;
V_261 = V_312 - V_311 -> V_107 ;
V_68 = F_59 ( V_8 -> V_50 , ( char * ) V_311 -> V_106 +
V_311 -> V_107 , V_261 ) ;
if ( V_68 <= 0 )
return V_68 ;
V_311 -> V_107 += V_68 ;
}
if ( V_311 -> V_107 == V_312 )
* V_193 = F_124 ( 0 , V_311 -> V_106 , V_311 -> V_107 ) ;
return 1 ;
}
static int F_177 ( struct V_7 * V_8 )
{
struct V_35 * V_89 = V_8 -> V_115 ;
struct V_144 * V_145 = & V_89 -> V_145 ;
bool V_246 = ! F_56 ( F_57 ( V_8 -> V_30 ) , V_247 ) ;
struct V_95 * V_95 ;
T_1 V_96 ;
T_1 V_97 ;
T_4 V_193 = 0 ;
int V_68 ;
F_3 ( ! V_89 ) ;
if ( F_75 ( & V_89 -> V_142 ) )
return - V_313 ;
if ( V_246 )
V_193 = V_8 -> V_258 ;
while ( V_145 -> V_148 ) {
V_95 = F_114 ( V_145 , & V_96 , & V_97 , NULL ) ;
V_68 = F_61 ( V_8 -> V_50 , V_95 , V_96 , V_97 ) ;
if ( V_68 <= 0 ) {
if ( V_246 )
V_8 -> V_258 = V_193 ;
return V_68 ;
}
if ( V_246 )
V_193 = F_138 ( V_193 , V_95 , V_96 , V_68 ) ;
( void ) F_115 ( V_145 , ( T_1 ) V_68 ) ;
}
if ( V_246 )
V_8 -> V_258 = V_193 ;
return 1 ;
}
static int F_178 ( struct V_7 * V_8 )
{
struct V_35 * V_180 = V_8 -> V_115 ;
int V_105 ;
int V_259 ;
int V_68 ;
unsigned int V_199 , V_200 , V_179 ;
bool V_246 = ! F_56 ( F_57 ( V_8 -> V_30 ) , V_247 ) ;
bool V_314 = ( V_8 -> V_185 & V_186 ) ;
V_163 V_198 ;
T_4 V_193 ;
F_38 ( L_79 , V_8 , V_180 ) ;
V_105 = sizeof ( V_8 -> V_315 ) ;
V_259 = V_105 ;
V_68 = F_148 ( V_8 , V_259 , V_105 , & V_8 -> V_315 ) ;
if ( V_68 <= 0 )
return V_68 ;
V_193 = F_124 ( 0 , & V_8 -> V_315 , F_125 ( struct V_205 , V_193 ) ) ;
if ( F_126 ( V_193 ) != V_8 -> V_315 . V_193 ) {
F_30 ( L_80 ,
V_193 , V_8 -> V_315 . V_193 ) ;
return - V_316 ;
}
V_199 = F_122 ( V_8 -> V_315 . V_199 ) ;
if ( V_199 > V_317 )
return - V_313 ;
V_200 = F_122 ( V_8 -> V_315 . V_200 ) ;
if ( V_200 > V_318 )
return - V_313 ;
V_179 = F_122 ( V_8 -> V_315 . V_179 ) ;
if ( V_179 > V_319 )
return - V_313 ;
V_198 = F_172 ( V_8 -> V_315 . V_198 ) ;
if ( ( V_320 ) V_198 - ( V_320 ) V_8 -> V_119 < 1 ) {
F_164 ( L_81 ,
F_173 ( V_8 -> V_128 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_198 , V_8 -> V_119 + 1 ) ;
V_8 -> V_252 = - V_199 - V_200 - V_179 -
sizeof( V_180 -> V_182 ) ;
V_8 -> V_253 = V_255 ;
return 0 ;
} else if ( ( V_320 ) V_198 - ( V_320 ) V_8 -> V_119 > 1 ) {
F_30 ( L_82 ,
V_198 , V_8 -> V_119 + 1 ) ;
V_8 -> V_268 = L_83 ;
return - V_321 ;
}
if ( ! V_8 -> V_115 ) {
int V_322 = 0 ;
F_38 ( L_84 , V_8 -> V_315 . type ,
V_199 , V_179 ) ;
V_68 = F_179 ( V_8 , & V_322 ) ;
if ( V_68 < 0 )
return V_68 ;
F_3 ( ! V_8 -> V_115 ^ V_322 ) ;
if ( V_322 ) {
F_38 ( L_85 ) ;
V_8 -> V_252 = - V_199 - V_200 - V_179 -
sizeof( V_180 -> V_182 ) ;
V_8 -> V_253 = V_255 ;
V_8 -> V_119 ++ ;
return 0 ;
}
F_3 ( ! V_8 -> V_115 ) ;
F_3 ( V_8 -> V_115 -> V_8 != V_8 ) ;
V_180 = V_8 -> V_115 ;
V_180 -> V_201 . V_107 = 0 ;
if ( V_180 -> V_203 )
V_180 -> V_203 -> V_204 . V_107 = 0 ;
if ( V_179 )
F_117 ( V_8 -> V_115 , V_179 ) ;
}
V_68 = F_176 ( V_8 , & V_180 -> V_201 , V_199 ,
& V_8 -> V_256 ) ;
if ( V_68 <= 0 )
return V_68 ;
if ( V_180 -> V_203 ) {
V_68 = F_176 ( V_8 , & V_180 -> V_203 -> V_204 ,
V_200 ,
& V_8 -> V_257 ) ;
if ( V_68 <= 0 )
return V_68 ;
}
if ( V_179 ) {
V_68 = F_177 ( V_8 ) ;
if ( V_68 <= 0 )
return V_68 ;
}
if ( V_314 )
V_105 = sizeof( V_180 -> V_182 ) ;
else
V_105 = sizeof( V_180 -> V_189 ) ;
V_259 += V_105 ;
V_68 = F_148 ( V_8 , V_259 , V_105 , & V_180 -> V_182 ) ;
if ( V_68 <= 0 )
return V_68 ;
if ( ! V_314 ) {
V_180 -> V_182 . V_9 = V_180 -> V_189 . V_9 ;
V_180 -> V_182 . V_188 = 0 ;
}
F_38 ( L_86 ,
V_180 , V_199 , V_180 -> V_182 . V_206 , V_200 ,
V_180 -> V_182 . V_207 , V_179 , V_180 -> V_182 . V_208 ) ;
if ( V_8 -> V_256 != F_122 ( V_180 -> V_182 . V_206 ) ) {
F_30 ( L_87 ,
V_180 , V_8 -> V_256 , V_180 -> V_182 . V_206 ) ;
return - V_316 ;
}
if ( V_8 -> V_257 != F_122 ( V_180 -> V_182 . V_207 ) ) {
F_30 ( L_88 ,
V_180 , V_8 -> V_257 , V_180 -> V_182 . V_207 ) ;
return - V_316 ;
}
if ( V_246 &&
( V_180 -> V_182 . V_9 & V_249 ) == 0 &&
V_8 -> V_258 != F_122 ( V_180 -> V_182 . V_208 ) ) {
F_30 ( L_89 , V_180 ,
V_8 -> V_258 , F_122 ( V_180 -> V_182 . V_208 ) ) ;
return - V_316 ;
}
if ( V_314 && V_8 -> V_76 -> V_323 &&
V_8 -> V_76 -> V_323 ( V_180 ) ) {
F_30 ( L_90 , V_180 ) ;
return - V_316 ;
}
return 1 ;
}
static void F_180 ( struct V_7 * V_8 )
{
struct V_35 * V_89 = V_8 -> V_115 ;
F_3 ( V_8 -> V_115 -> V_8 != V_8 ) ;
V_8 -> V_115 = NULL ;
if ( V_8 -> V_128 . type == 0 )
V_8 -> V_128 = V_89 -> V_197 . V_324 ;
V_8 -> V_119 ++ ;
F_81 ( & V_8 -> V_121 ) ;
F_38 ( L_91 ,
V_89 , F_172 ( V_89 -> V_197 . V_198 ) ,
F_173 ( V_89 -> V_197 . V_324 ) ,
F_123 ( V_89 -> V_197 . type ) ,
F_181 ( F_123 ( V_89 -> V_197 . type ) ) ,
F_122 ( V_89 -> V_197 . V_199 ) ,
F_122 ( V_89 -> V_197 . V_179 ) ,
V_8 -> V_256 , V_8 -> V_257 , V_8 -> V_258 ) ;
V_8 -> V_76 -> V_325 ( V_8 , V_89 ) ;
F_79 ( & V_8 -> V_121 ) ;
}
static int F_182 ( struct V_7 * V_8 )
{
struct V_326 V_327 ;
T_1 V_105 = sizeof( V_327 ) ;
int V_68 = F_148 ( V_8 , V_105 , V_105 , & V_327 ) ;
if ( V_68 <= 0 )
return V_68 ;
F_183 ( & V_8 -> V_328 , & V_327 ) ;
F_145 ( V_8 ) ;
return 1 ;
}
static int F_184 ( struct V_7 * V_8 )
{
int V_68 = 1 ;
F_38 ( L_92 , V_8 , V_8 -> V_56 ) ;
V_101:
F_38 ( L_93 , V_8 -> V_139 ) ;
if ( V_8 -> V_56 == V_127 ) {
F_3 ( V_8 -> V_50 ) ;
V_8 -> V_56 = V_329 ;
F_92 ( V_8 ) ;
F_134 ( V_8 ) ;
F_141 ( V_8 ) ;
F_3 ( V_8 -> V_115 ) ;
V_8 -> V_253 = V_255 ;
F_38 ( L_94 ,
V_8 , V_8 -> V_56 ) ;
V_68 = F_50 ( V_8 ) ;
if ( V_68 < 0 ) {
V_8 -> V_268 = L_95 ;
goto V_245;
}
}
V_330:
if ( V_8 -> V_250 ) {
V_68 = F_140 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_245;
}
if ( V_8 -> V_138 ) {
V_68 = F_137 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_245;
}
if ( V_8 -> V_118 ) {
if ( V_8 -> V_192 ) {
F_73 ( V_8 -> V_118 ) ;
V_8 -> V_118 = NULL ;
goto V_331;
}
V_68 = F_139 ( V_8 ) ;
if ( V_68 == 1 )
goto V_330;
if ( V_68 == 0 )
goto V_245;
if ( V_68 < 0 ) {
F_38 ( L_96 ,
V_68 ) ;
goto V_245;
}
}
V_331:
if ( V_8 -> V_56 == V_304 ) {
if ( F_9 ( V_8 , V_3 ) ) {
F_129 ( V_8 ) ;
goto V_101;
}
if ( ! F_75 ( & V_8 -> V_113 ) ) {
F_119 ( V_8 ) ;
goto V_101;
}
if ( V_8 -> V_119 > V_8 -> V_120 ) {
F_127 ( V_8 ) ;
goto V_101;
}
}
F_2 ( V_8 , V_4 ) ;
F_38 ( L_97 ) ;
V_68 = 0 ;
V_245:
F_38 ( L_98 , V_8 , V_68 ) ;
return V_68 ;
}
static int F_185 ( struct V_7 * V_8 )
{
int V_68 = - 1 ;
V_101:
F_38 ( L_99 , V_8 , V_8 -> V_56 ) ;
if ( V_8 -> V_56 != V_329 &&
V_8 -> V_56 != V_225 &&
V_8 -> V_56 != V_304 )
return 0 ;
F_3 ( ! V_8 -> V_50 ) ;
F_38 ( L_100 , ( int ) V_8 -> V_253 ,
V_8 -> V_252 ) ;
if ( V_8 -> V_56 == V_329 ) {
F_38 ( L_101 ) ;
V_68 = F_149 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_245;
V_68 = F_167 ( V_8 ) ;
if ( V_68 < 0 )
goto V_245;
V_8 -> V_56 = V_225 ;
V_68 = F_135 ( V_8 ) ;
if ( V_68 < 0 )
goto V_245;
F_142 ( V_8 ) ;
goto V_245;
}
if ( V_8 -> V_56 == V_225 ) {
F_38 ( L_102 ) ;
V_68 = F_150 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_245;
V_68 = F_170 ( V_8 ) ;
if ( V_68 < 0 )
goto V_245;
goto V_101;
}
F_36 ( V_8 -> V_56 != V_304 ) ;
if ( V_8 -> V_252 < 0 ) {
static char V_84 [ V_332 ] ;
int V_322 = F_96 ( ( int ) sizeof ( V_84 ) , - V_8 -> V_252 ) ;
F_38 ( L_103 , V_322 , - V_8 -> V_252 ) ;
V_68 = F_59 ( V_8 -> V_50 , V_84 , V_322 ) ;
if ( V_68 <= 0 )
goto V_245;
V_8 -> V_252 += V_68 ;
if ( V_8 -> V_252 )
goto V_101;
}
if ( V_8 -> V_253 == V_255 ) {
V_68 = F_59 ( V_8 -> V_50 , & V_8 -> V_253 , 1 ) ;
if ( V_68 <= 0 )
goto V_245;
F_38 ( L_104 , ( int ) V_8 -> V_253 ) ;
switch ( V_8 -> V_253 ) {
case V_333 :
F_147 ( V_8 ) ;
break;
case V_334 :
F_143 ( V_8 ) ;
break;
case V_335 :
F_146 ( V_8 ) ;
break;
case V_336 :
F_70 ( V_8 ) ;
V_8 -> V_56 = V_122 ;
goto V_245;
default:
goto V_337;
}
}
if ( V_8 -> V_253 == V_333 ) {
V_68 = F_178 ( V_8 ) ;
if ( V_68 <= 0 ) {
switch ( V_68 ) {
case - V_316 :
V_8 -> V_268 = L_105 ;
case - V_321 :
V_68 = - V_313 ;
break;
case - V_313 :
V_8 -> V_268 = L_106 ;
break;
}
goto V_245;
}
if ( V_8 -> V_253 == V_255 )
goto V_101;
F_180 ( V_8 ) ;
if ( V_8 -> V_56 == V_304 )
F_145 ( V_8 ) ;
goto V_101;
}
if ( V_8 -> V_253 == V_334 ||
V_8 -> V_253 == V_254 ) {
V_68 = F_174 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_245;
F_175 ( V_8 ) ;
goto V_101;
}
if ( V_8 -> V_253 == V_335 ) {
V_68 = F_182 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_245;
goto V_101;
}
V_245:
F_38 ( L_107 , V_8 , V_68 ) ;
return V_68 ;
V_337:
F_30 ( L_108 , ( int ) V_8 -> V_253 ) ;
V_8 -> V_268 = L_109 ;
V_68 = - 1 ;
goto V_245;
}
static int F_186 ( struct V_7 * V_8 , unsigned long V_130 )
{
if ( ! V_8 -> V_76 -> V_338 ( V_8 ) ) {
F_38 ( L_110 , V_46 , V_8 ) ;
return - V_339 ;
}
if ( ! F_187 ( V_39 , & V_8 -> V_133 , V_130 ) ) {
F_38 ( L_111 , V_46 , V_8 ) ;
V_8 -> V_76 -> V_340 ( V_8 ) ;
return - V_341 ;
}
F_38 ( L_112 , V_46 , V_8 , V_130 ) ;
return 0 ;
}
static void F_45 ( struct V_7 * V_8 )
{
( void ) F_186 ( V_8 , 0 ) ;
}
static void F_80 ( struct V_7 * V_8 )
{
if ( F_188 ( & V_8 -> V_133 ) ) {
F_38 ( L_113 , V_46 , V_8 ) ;
V_8 -> V_76 -> V_340 ( V_8 ) ;
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
CASE ( V_342 ) ;
CASE ( V_343 ) ;
CASE ( V_344 ) ;
CASE ( V_345 ) ;
CASE ( V_346 ) ;
CASE ( V_347 ) ;
default:
F_169 ( L_114 ,
V_46 , V_8 , V_8 -> V_56 ) ;
V_8 -> V_268 = L_115 ;
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
V_68 = F_186 ( V_8 , F_191 ( V_8 -> V_130 ) ) ;
if ( V_68 ) {
F_38 ( L_116 , V_46 ,
V_8 , V_8 -> V_130 ) ;
F_3 ( V_68 == - V_339 ) ;
F_5 ( V_8 , V_6 ) ;
}
return true ;
}
static void F_192 ( struct V_7 * V_8 )
{
if ( V_8 -> V_224 && V_8 -> V_76 -> V_348 ) {
F_38 ( L_117 ) ;
V_8 -> V_76 -> V_348 ( V_8 ) ;
}
if ( V_8 -> V_76 -> V_349 )
V_8 -> V_76 -> V_349 ( V_8 ) ;
}
static void V_134 ( struct V_350 * V_133 )
{
struct V_7 * V_8 = F_193 ( V_133 , struct V_7 ,
V_133 . V_133 ) ;
bool V_349 ;
F_79 ( & V_8 -> V_121 ) ;
while ( true ) {
int V_68 ;
if ( ( V_349 = F_189 ( V_8 ) ) ) {
F_38 ( L_118 , V_46 , V_8 ) ;
break;
}
if ( F_190 ( V_8 ) ) {
F_38 ( L_119 , V_46 , V_8 ) ;
break;
}
if ( V_8 -> V_56 == V_351 ) {
F_38 ( L_120 , V_46 , V_8 ) ;
break;
}
if ( V_8 -> V_56 == V_122 ) {
F_38 ( L_121 , V_46 , V_8 ) ;
F_3 ( V_8 -> V_50 ) ;
break;
}
if ( V_8 -> V_56 == V_127 ) {
F_38 ( L_122 , V_46 , V_8 ) ;
F_3 ( V_8 -> V_50 ) ;
}
V_68 = F_185 ( V_8 ) ;
if ( V_68 < 0 ) {
if ( V_68 == - V_94 )
continue;
if ( ! V_8 -> V_268 )
V_8 -> V_268 = L_123 ;
V_349 = true ;
break;
}
V_68 = F_184 ( V_8 ) ;
if ( V_68 < 0 ) {
if ( V_68 == - V_94 )
continue;
if ( ! V_8 -> V_268 )
V_8 -> V_268 = L_124 ;
V_349 = true ;
}
break;
}
if ( V_349 )
F_194 ( V_8 ) ;
F_81 ( & V_8 -> V_121 ) ;
if ( V_349 )
F_192 ( V_8 ) ;
V_8 -> V_76 -> V_340 ( V_8 ) ;
}
static void F_194 ( struct V_7 * V_8 )
{
F_38 ( L_125 ,
V_8 , V_8 -> V_56 , F_13 ( & V_8 -> V_66 . V_67 ) ) ;
F_169 ( L_126 , F_173 ( V_8 -> V_128 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) , V_8 -> V_268 ) ;
V_8 -> V_268 = NULL ;
F_36 ( V_8 -> V_56 != V_329 &&
V_8 -> V_56 != V_225 &&
V_8 -> V_56 != V_304 ) ;
F_70 ( V_8 ) ;
if ( F_7 ( V_8 , V_2 ) ) {
F_38 ( L_127 ) ;
V_8 -> V_56 = V_122 ;
return;
}
if ( V_8 -> V_115 ) {
F_3 ( V_8 -> V_115 -> V_8 != V_8 ) ;
F_73 ( V_8 -> V_115 ) ;
V_8 -> V_115 = NULL ;
}
F_195 ( & V_8 -> V_114 , & V_8 -> V_113 ) ;
if ( F_75 ( & V_8 -> V_113 ) &&
! F_7 ( V_8 , V_3 ) ) {
F_38 ( L_128 , V_8 ) ;
F_2 ( V_8 , V_4 ) ;
V_8 -> V_56 = V_351 ;
} else {
V_8 -> V_56 = V_127 ;
if ( V_8 -> V_130 == 0 )
V_8 -> V_130 = V_352 ;
else if ( V_8 -> V_130 < V_353 )
V_8 -> V_130 *= 2 ;
F_5 ( V_8 , V_6 ) ;
F_45 ( V_8 ) ;
}
}
void F_196 ( struct V_29 * V_30 ,
struct V_126 * V_354 )
{
F_197 ( & V_30 -> V_136 ) ;
if ( V_354 )
V_30 -> V_32 . V_33 = * V_354 ;
V_30 -> V_32 . V_33 . type = 0 ;
F_198 ( & V_30 -> V_32 . V_33 . V_292 , sizeof( V_30 -> V_32 . V_33 . V_292 ) ) ;
F_16 ( V_30 ) ;
F_199 ( & V_30 -> V_53 , 0 ) ;
F_200 ( & V_30 -> V_69 , F_201 ( V_355 -> V_356 -> V_357 ) ) ;
F_38 ( L_113 , V_46 , V_30 ) ;
}
void F_202 ( struct V_29 * V_30 )
{
F_203 ( F_52 ( & V_30 -> V_69 ) ) ;
}
static void F_204 ( struct V_35 * V_89 , struct V_7 * V_8 )
{
if ( V_89 -> V_8 )
V_89 -> V_8 -> V_76 -> V_340 ( V_89 -> V_8 ) ;
V_89 -> V_8 = V_8 ? V_8 -> V_76 -> V_338 ( V_8 ) : NULL ;
F_3 ( V_89 -> V_8 != V_8 ) ;
}
static void F_205 ( struct V_7 * V_8 )
{
if ( V_8 -> V_56 == V_351 ) {
F_38 ( L_129 , V_8 ) ;
V_8 -> V_56 = V_127 ;
V_8 -> V_116 ++ ;
F_36 ( F_7 ( V_8 , V_4 ) ) ;
F_36 ( F_7 ( V_8 , V_3 ) ) ;
}
}
void F_206 ( struct V_7 * V_8 , struct V_35 * V_89 )
{
V_89 -> V_197 . V_324 = V_8 -> V_30 -> V_32 . V_279 ;
F_3 ( V_89 -> V_201 . V_107 != F_122 ( V_89 -> V_197 . V_199 ) ) ;
V_89 -> V_196 = true ;
F_79 ( & V_8 -> V_121 ) ;
if ( V_8 -> V_56 == V_122 ) {
F_38 ( L_130 , V_8 , V_89 ) ;
F_73 ( V_89 ) ;
F_81 ( & V_8 -> V_121 ) ;
return;
}
F_204 ( V_89 , V_8 ) ;
F_3 ( ! F_75 ( & V_89 -> V_111 ) ) ;
F_207 ( & V_89 -> V_111 , & V_8 -> V_113 ) ;
F_38 ( L_131 , V_89 ,
F_173 ( V_8 -> V_128 ) , F_123 ( V_89 -> V_197 . type ) ,
F_181 ( F_123 ( V_89 -> V_197 . type ) ) ,
F_122 ( V_89 -> V_197 . V_199 ) ,
F_122 ( V_89 -> V_197 . V_200 ) ,
F_122 ( V_89 -> V_197 . V_179 ) ) ;
F_205 ( V_8 ) ;
F_81 ( & V_8 -> V_121 ) ;
if ( F_11 ( V_8 , V_4 ) == 0 )
F_45 ( V_8 ) ;
}
void F_208 ( struct V_35 * V_89 )
{
struct V_7 * V_8 = V_89 -> V_8 ;
if ( ! V_8 ) {
F_38 ( L_132 , V_46 , V_89 ) ;
return;
}
F_79 ( & V_8 -> V_121 ) ;
if ( ! F_75 ( & V_89 -> V_111 ) ) {
F_38 ( L_133 , V_46 , V_8 , V_89 ) ;
F_72 ( & V_89 -> V_111 ) ;
V_89 -> V_197 . V_198 = 0 ;
F_73 ( V_89 ) ;
}
if ( V_8 -> V_118 == V_89 ) {
F_38 ( L_134 , V_46 , V_8 , V_89 ) ;
V_8 -> V_118 = NULL ;
if ( V_8 -> V_184 ) {
V_8 -> V_250 = V_8 -> V_139 ;
V_8 -> V_184 = false ;
}
V_89 -> V_197 . V_198 = 0 ;
F_73 ( V_89 ) ;
}
F_81 ( & V_8 -> V_121 ) ;
}
void F_209 ( struct V_35 * V_89 )
{
struct V_7 * V_8 = V_89 -> V_8 ;
if ( ! V_8 ) {
F_38 ( L_132 , V_46 , V_89 ) ;
return;
}
F_79 ( & V_8 -> V_121 ) ;
if ( V_8 -> V_115 == V_89 ) {
unsigned int V_199 = F_122 ( V_8 -> V_315 . V_199 ) ;
unsigned int V_200 = F_122 ( V_8 -> V_315 . V_200 ) ;
unsigned int V_179 = F_122 ( V_8 -> V_315 . V_179 ) ;
F_38 ( L_135 , V_46 , V_8 , V_89 ) ;
V_8 -> V_252 = V_8 -> V_252 -
sizeof( struct V_205 ) -
V_199 -
V_200 -
V_179 -
sizeof( struct V_358 ) ;
F_73 ( V_8 -> V_115 ) ;
V_8 -> V_115 = NULL ;
V_8 -> V_253 = V_255 ;
V_8 -> V_119 ++ ;
} else {
F_38 ( L_136 ,
V_46 , V_8 , V_8 -> V_115 , V_89 ) ;
}
F_81 ( & V_8 -> V_121 ) ;
}
void F_210 ( struct V_7 * V_8 )
{
F_38 ( L_137 , V_8 ) ;
F_79 ( & V_8 -> V_121 ) ;
F_205 ( V_8 ) ;
F_81 ( & V_8 -> V_121 ) ;
if ( F_11 ( V_8 , V_3 ) == 0 &&
F_11 ( V_8 , V_4 ) == 0 )
F_45 ( V_8 ) ;
}
bool F_211 ( struct V_7 * V_8 ,
unsigned long V_359 )
{
if ( V_359 > 0 &&
( V_8 -> V_185 & V_209 ) ) {
struct V_210 V_211 = V_212 ;
struct V_210 V_360 ;
F_212 ( V_359 , & V_360 ) ;
V_360 = F_213 ( V_8 -> V_328 , V_360 ) ;
return F_214 ( & V_211 , & V_360 ) >= 0 ;
}
return false ;
}
static struct V_38 * F_215 ( enum V_361 type )
{
struct V_38 * V_142 ;
if ( F_36 ( ! F_216 ( type ) ) )
return NULL ;
V_142 = F_217 ( V_37 , V_73 ) ;
if ( V_142 )
V_142 -> type = type ;
F_87 ( & V_142 -> V_177 ) ;
return V_142 ;
}
static void F_218 ( struct V_38 * V_142 )
{
if ( ! V_142 )
return;
F_36 ( ! F_75 ( & V_142 -> V_177 ) ) ;
if ( V_142 -> type == V_170 )
F_219 ( V_142 -> V_169 ) ;
F_220 ( V_37 , V_142 ) ;
}
void F_221 ( struct V_35 * V_89 , struct V_95 * * V_161 ,
T_1 V_97 , T_1 V_162 )
{
struct V_38 * V_142 ;
F_3 ( ! V_161 ) ;
F_3 ( ! V_97 ) ;
V_142 = F_215 ( V_160 ) ;
F_3 ( ! V_142 ) ;
V_142 -> V_161 = V_161 ;
V_142 -> V_97 = V_97 ;
V_142 -> V_162 = V_162 & ~ V_164 ;
F_207 ( & V_142 -> V_177 , & V_89 -> V_142 ) ;
V_89 -> V_175 += V_97 ;
}
void F_222 ( struct V_35 * V_89 ,
struct V_168 * V_169 )
{
struct V_38 * V_142 ;
F_3 ( ! V_169 ) ;
F_3 ( ! V_169 -> V_97 ) ;
V_142 = F_215 ( V_170 ) ;
F_3 ( ! V_142 ) ;
V_142 -> V_169 = V_169 ;
F_207 ( & V_142 -> V_177 , & V_89 -> V_142 ) ;
V_89 -> V_175 += V_169 -> V_97 ;
}
void F_223 ( struct V_35 * V_89 , struct V_146 * V_146 ,
T_1 V_97 )
{
struct V_38 * V_142 ;
F_3 ( ! V_146 ) ;
V_142 = F_215 ( V_147 ) ;
F_3 ( ! V_142 ) ;
V_142 -> V_146 = V_146 ;
V_142 -> V_149 = V_97 ;
F_207 ( & V_142 -> V_177 , & V_89 -> V_142 ) ;
V_89 -> V_175 += V_97 ;
}
struct V_35 * F_224 ( int type , int V_199 , T_6 V_9 ,
bool V_362 )
{
struct V_35 * V_180 ;
V_180 = F_217 ( V_34 , V_9 ) ;
if ( V_180 == NULL )
goto V_245;
V_180 -> V_197 . type = F_225 ( type ) ;
V_180 -> V_197 . V_363 = F_225 ( V_364 ) ;
V_180 -> V_197 . V_199 = F_126 ( V_199 ) ;
F_87 ( & V_180 -> V_111 ) ;
F_226 ( & V_180 -> V_365 ) ;
F_87 ( & V_180 -> V_142 ) ;
if ( V_199 ) {
V_180 -> V_201 . V_106 = F_227 ( V_199 , V_9 ) ;
if ( V_180 -> V_201 . V_106 == NULL ) {
F_38 ( L_138 ,
V_199 ) ;
goto V_366;
}
} else {
V_180 -> V_201 . V_106 = NULL ;
}
V_180 -> V_367 = V_180 -> V_201 . V_107 = V_199 ;
F_38 ( L_139 , V_180 , V_199 ) ;
return V_180 ;
V_366:
F_73 ( V_180 ) ;
V_245:
if ( ! V_362 ) {
F_30 ( L_140 , type ,
V_199 ) ;
F_36 ( 1 ) ;
} else {
F_38 ( L_140 , type ,
V_199 ) ;
}
return NULL ;
}
static int F_228 ( struct V_7 * V_8 , struct V_35 * V_89 )
{
int type = F_123 ( V_89 -> V_197 . type ) ;
int V_200 = F_122 ( V_89 -> V_197 . V_200 ) ;
F_38 ( L_141 , V_89 , type ,
F_181 ( type ) , V_200 ) ;
F_3 ( ! V_200 ) ;
F_3 ( V_89 -> V_203 ) ;
V_89 -> V_203 = F_229 ( V_200 , V_73 ) ;
if ( ! V_89 -> V_203 )
return - V_36 ;
return 0 ;
}
static int F_179 ( struct V_7 * V_8 , int * V_322 )
{
struct V_205 * V_197 = & V_8 -> V_315 ;
int V_200 = F_122 ( V_197 -> V_200 ) ;
struct V_35 * V_89 ;
int V_68 = 0 ;
F_3 ( V_8 -> V_115 != NULL ) ;
F_3 ( ! V_8 -> V_76 -> V_368 ) ;
F_81 ( & V_8 -> V_121 ) ;
V_89 = V_8 -> V_76 -> V_368 ( V_8 , V_197 , V_322 ) ;
F_79 ( & V_8 -> V_121 ) ;
if ( V_8 -> V_56 != V_304 ) {
if ( V_89 )
F_73 ( V_89 ) ;
return - V_94 ;
}
if ( V_89 ) {
F_3 ( * V_322 ) ;
F_204 ( V_89 , V_8 ) ;
V_8 -> V_115 = V_89 ;
} else {
if ( * V_322 )
return 0 ;
V_8 -> V_268 = L_142 ;
return - V_36 ;
}
memcpy ( & V_8 -> V_115 -> V_197 , & V_8 -> V_315 , sizeof( V_8 -> V_315 ) ) ;
if ( V_200 && ! V_8 -> V_115 -> V_203 ) {
V_68 = F_228 ( V_8 , V_8 -> V_115 ) ;
if ( V_68 < 0 ) {
F_73 ( V_8 -> V_115 ) ;
V_8 -> V_115 = NULL ;
}
}
return V_68 ;
}
static void F_230 ( struct V_35 * V_180 )
{
F_38 ( L_113 , V_46 , V_180 ) ;
F_231 ( V_180 -> V_201 . V_106 ) ;
F_220 ( V_34 , V_180 ) ;
}
static void F_232 ( struct V_365 * V_365 )
{
struct V_35 * V_180 = F_193 ( V_365 , struct V_35 , V_365 ) ;
F_233 ( V_142 ) ;
struct V_111 * V_177 ;
struct V_111 * V_369 ;
F_38 ( L_113 , V_46 , V_180 ) ;
F_36 ( ! F_75 ( & V_180 -> V_111 ) ) ;
F_204 ( V_180 , NULL ) ;
if ( V_180 -> V_203 ) {
F_234 ( V_180 -> V_203 ) ;
V_180 -> V_203 = NULL ;
}
F_195 ( & V_180 -> V_142 , & V_142 ) ;
F_235 (links, next, &data) {
struct V_38 * V_142 ;
V_142 = F_236 ( V_177 , struct V_38 , V_177 ) ;
F_72 ( V_177 ) ;
F_218 ( V_142 ) ;
}
V_180 -> V_175 = 0 ;
if ( V_180 -> V_370 )
F_237 ( V_180 -> V_370 , V_180 ) ;
else
F_230 ( V_180 ) ;
}
struct V_35 * F_120 ( struct V_35 * V_89 )
{
F_38 ( L_143 , V_46 , V_89 ,
F_44 ( & V_89 -> V_365 . V_371 ) ) ;
F_238 ( & V_89 -> V_365 ) ;
return V_89 ;
}
void F_73 ( struct V_35 * V_89 )
{
F_38 ( L_143 , V_46 , V_89 ,
F_44 ( & V_89 -> V_365 . V_371 ) ) ;
F_239 ( & V_89 -> V_365 , F_232 ) ;
}
void F_240 ( struct V_35 * V_89 )
{
F_241 ( L_144 , V_89 ,
V_89 -> V_367 , V_89 -> V_175 ) ;
F_242 ( V_372 , L_145 ,
V_373 , 16 , 1 ,
& V_89 -> V_197 , sizeof( V_89 -> V_197 ) , true ) ;
F_242 ( V_372 , L_146 ,
V_373 , 16 , 1 ,
V_89 -> V_201 . V_106 , V_89 -> V_201 . V_107 , true ) ;
if ( V_89 -> V_203 )
F_242 ( V_372 , L_147 ,
V_373 , 16 , 1 ,
V_89 -> V_203 -> V_204 . V_106 ,
V_89 -> V_203 -> V_204 . V_107 , true ) ;
F_242 ( V_372 , L_148 ,
V_373 , 16 , 1 ,
& V_89 -> V_182 , sizeof( V_89 -> V_182 ) , true ) ;
}
