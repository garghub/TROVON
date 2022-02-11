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
V_40 = NULL ;
}
int F_26 ( void )
{
F_3 ( V_40 != NULL ) ;
V_40 = F_27 ( 0 ) ;
F_28 ( V_40 ) ;
if ( F_18 () )
return - V_36 ;
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
if ( V_8 -> V_30 -> V_81 ) {
int V_82 = 1 ;
V_68 = F_56 ( V_50 , V_83 , V_84 ,
( char * ) & V_82 , sizeof( V_82 ) ) ;
if ( V_68 )
F_30 ( L_20 ,
V_68 ) ;
}
V_8 -> V_50 = V_50 ;
return 0 ;
}
static int F_57 ( struct V_61 * V_50 , void * V_85 , T_1 V_86 )
{
struct V_87 V_88 = { V_85 , V_86 } ;
struct V_89 V_90 = { . V_91 = V_92 | V_93 } ;
int V_94 ;
V_94 = F_58 ( V_50 , & V_90 , & V_88 , 1 , V_86 , V_90 . V_91 ) ;
if ( V_94 == - V_95 )
V_94 = 0 ;
return V_94 ;
}
static int F_59 ( struct V_61 * V_50 , struct V_96 * V_96 ,
int V_97 , T_1 V_98 )
{
void * V_99 ;
int V_68 ;
F_3 ( V_97 + V_98 > V_100 ) ;
V_99 = F_60 ( V_96 ) ;
F_3 ( ! V_99 ) ;
V_68 = F_57 ( V_50 , V_99 + V_97 , V_98 ) ;
F_61 ( V_96 ) ;
return V_68 ;
}
static int F_62 ( struct V_61 * V_50 , struct V_87 * V_88 ,
T_1 V_101 , T_1 V_86 , int V_102 )
{
struct V_89 V_90 = { . V_91 = V_92 | V_93 } ;
int V_94 ;
if ( V_102 )
V_90 . V_91 |= V_103 ;
else
V_90 . V_91 |= V_104 ;
V_94 = F_63 ( V_50 , & V_90 , V_88 , V_101 , V_86 ) ;
if ( V_94 == - V_95 )
V_94 = 0 ;
return V_94 ;
}
static int F_64 ( struct V_61 * V_50 , struct V_96 * V_96 ,
int V_105 , T_1 V_106 , bool V_102 )
{
int V_9 = V_92 | V_93 | ( V_102 ? V_103 : V_104 ) ;
int V_68 ;
V_68 = F_65 ( V_50 , V_96 , V_105 , V_106 , V_9 ) ;
if ( V_68 == - V_95 )
V_68 = 0 ;
return V_68 ;
}
static int F_66 ( struct V_61 * V_50 , struct V_96 * V_96 ,
int V_105 , T_1 V_106 , bool V_102 )
{
int V_68 ;
struct V_87 V_88 ;
if ( F_67 ( V_96 ) >= 1 )
return F_64 ( V_50 , V_96 , V_105 , V_106 , V_102 ) ;
V_88 . V_107 = F_60 ( V_96 ) + V_105 ;
V_88 . V_108 = V_106 ;
V_68 = F_62 ( V_50 , & V_88 , 1 , V_106 , V_102 ) ;
F_61 ( V_96 ) ;
return V_68 ;
}
static int F_68 ( struct V_7 * V_8 )
{
int V_109 = 0 ;
F_38 ( L_21 , V_8 , V_8 -> V_50 ) ;
if ( V_8 -> V_50 ) {
V_109 = V_8 -> V_50 -> V_76 -> V_110 ( V_8 -> V_50 , V_111 ) ;
F_55 ( V_8 -> V_50 ) ;
V_8 -> V_50 = NULL ;
}
F_2 ( V_8 , V_5 ) ;
F_42 ( V_8 ) ;
return V_109 ;
}
static void F_69 ( struct V_35 * V_90 )
{
F_70 ( & V_90 -> V_112 ) ;
F_3 ( V_90 -> V_8 == NULL ) ;
V_90 -> V_8 -> V_76 -> V_113 ( V_90 -> V_8 ) ;
V_90 -> V_8 = NULL ;
F_71 ( V_90 ) ;
}
static void F_72 ( struct V_112 * V_114 )
{
while ( ! F_73 ( V_114 ) ) {
struct V_35 * V_90 = F_74 ( V_114 , struct V_35 ,
V_112 ) ;
F_69 ( V_90 ) ;
}
}
static void F_75 ( struct V_7 * V_8 )
{
F_38 ( L_22 , V_8 ) ;
F_72 ( & V_8 -> V_115 ) ;
F_72 ( & V_8 -> V_116 ) ;
if ( V_8 -> V_117 ) {
F_3 ( V_8 -> V_117 -> V_8 != V_8 ) ;
V_8 -> V_117 -> V_8 = NULL ;
F_71 ( V_8 -> V_117 ) ;
V_8 -> V_117 = NULL ;
V_8 -> V_76 -> V_113 ( V_8 ) ;
}
V_8 -> V_118 = 0 ;
V_8 -> V_119 = 0 ;
if ( V_8 -> V_120 ) {
F_71 ( V_8 -> V_120 ) ;
V_8 -> V_120 = NULL ;
}
V_8 -> V_121 = 0 ;
V_8 -> V_122 = 0 ;
}
void F_76 ( struct V_7 * V_8 )
{
F_77 ( & V_8 -> V_123 ) ;
F_38 ( L_23 , V_8 ,
F_13 ( & V_8 -> V_66 . V_67 ) ) ;
V_8 -> V_56 = V_124 ;
F_2 ( V_8 , V_2 ) ;
F_2 ( V_8 , V_3 ) ;
F_2 ( V_8 , V_4 ) ;
F_2 ( V_8 , V_6 ) ;
F_75 ( V_8 ) ;
V_8 -> V_125 = 0 ;
F_78 ( V_8 ) ;
F_68 ( V_8 ) ;
F_79 ( & V_8 -> V_123 ) ;
}
void F_80 ( struct V_7 * V_8 ,
T_2 V_126 , T_3 V_127 ,
struct V_128 * V_33 )
{
F_77 ( & V_8 -> V_123 ) ;
F_38 ( L_24 , V_8 , F_13 ( & V_33 -> V_67 ) ) ;
F_36 ( V_8 -> V_56 != V_124 ) ;
V_8 -> V_56 = V_129 ;
V_8 -> V_130 . type = ( T_2 ) V_126 ;
V_8 -> V_130 . V_131 = F_81 ( V_127 ) ;
memcpy ( & V_8 -> V_66 , V_33 , sizeof( * V_33 ) ) ;
V_8 -> V_132 = 0 ;
F_79 ( & V_8 -> V_123 ) ;
F_45 ( V_8 ) ;
}
bool F_82 ( struct V_7 * V_8 )
{
return V_8 -> V_118 > 0 ;
}
void F_83 ( struct V_7 * V_8 , void * V_133 ,
const struct V_134 * V_76 ,
struct V_29 * V_30 )
{
F_38 ( L_25 , V_8 ) ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> V_133 = V_133 ;
V_8 -> V_76 = V_76 ;
V_8 -> V_30 = V_30 ;
F_34 ( V_8 ) ;
F_84 ( & V_8 -> V_123 ) ;
F_85 ( & V_8 -> V_115 ) ;
F_85 ( & V_8 -> V_116 ) ;
F_86 ( & V_8 -> V_135 , V_136 ) ;
V_8 -> V_56 = V_124 ;
}
static T_4 F_87 ( struct V_29 * V_30 , T_4 V_137 )
{
T_4 V_68 ;
F_88 ( & V_30 -> V_138 ) ;
if ( V_30 -> V_139 < V_137 )
V_30 -> V_139 = V_137 ;
V_68 = ++ V_30 -> V_139 ;
F_89 ( & V_30 -> V_138 ) ;
return V_68 ;
}
static void F_90 ( struct V_7 * V_8 )
{
V_8 -> V_140 = 0 ;
V_8 -> V_141 = 0 ;
V_8 -> V_142 = & V_8 -> V_143 [ 0 ] ;
}
static void F_91 ( struct V_7 * V_8 ,
T_1 V_106 , void * V_144 )
{
int V_145 ;
V_145 = V_8 -> V_140 ;
F_3 ( V_145 >= F_92 ( V_8 -> V_143 ) ) ;
V_8 -> V_143 [ V_145 ] . V_108 = V_106 ;
V_8 -> V_143 [ V_145 ] . V_107 = V_144 ;
V_8 -> V_140 ++ ;
V_8 -> V_141 += V_106 ;
}
static void F_93 ( struct V_146 * V_147 ,
T_1 V_98 )
{
struct V_38 * V_144 = V_147 -> V_144 ;
struct V_148 * V_148 ;
F_3 ( V_144 -> type != V_149 ) ;
V_148 = V_144 -> V_148 ;
F_3 ( ! V_148 ) ;
V_147 -> V_150 = F_94 ( V_98 , V_144 -> V_151 ) ;
V_147 -> V_148 = V_148 ;
V_147 -> V_152 = V_148 -> V_153 ;
V_147 -> V_154 =
V_147 -> V_150 <= F_95 ( V_148 , V_147 -> V_152 ) ;
}
static struct V_96 * F_96 ( struct V_146 * V_147 ,
T_1 * V_97 ,
T_1 * V_98 )
{
struct V_38 * V_144 = V_147 -> V_144 ;
struct V_148 * V_148 ;
struct V_155 V_155 ;
F_3 ( V_144 -> type != V_149 ) ;
V_148 = V_147 -> V_148 ;
F_3 ( ! V_148 ) ;
V_155 = F_97 ( V_148 , V_147 -> V_152 ) ;
* V_97 = ( T_1 ) V_155 . V_156 ;
F_3 ( * V_97 >= V_100 ) ;
if ( V_147 -> V_154 )
* V_98 = V_147 -> V_150 ;
else
* V_98 = ( T_1 ) V_155 . V_157 ;
F_3 ( * V_98 > V_147 -> V_150 ) ;
F_3 ( * V_97 + * V_98 > V_100 ) ;
return V_155 . V_158 ;
}
static bool F_98 ( struct V_146 * V_147 ,
T_1 V_159 )
{
struct V_148 * V_148 ;
struct V_155 V_155 ;
F_3 ( V_147 -> V_144 -> type != V_149 ) ;
V_148 = V_147 -> V_148 ;
F_3 ( ! V_148 ) ;
V_155 = F_97 ( V_148 , V_147 -> V_152 ) ;
F_3 ( V_147 -> V_150 < V_159 ) ;
V_147 -> V_150 -= V_159 ;
F_99 ( V_148 , & V_147 -> V_152 , V_159 ) ;
if ( V_159 < V_155 . V_157 )
return false ;
if ( ! V_147 -> V_152 . V_160 ) {
V_148 = V_148 -> V_161 ;
V_147 -> V_148 = V_148 ;
if ( V_148 )
V_147 -> V_152 = V_148 -> V_153 ;
else
memset ( & V_147 -> V_152 , 0 ,
sizeof( V_147 -> V_152 ) ) ;
}
if ( ! V_147 -> V_154 ) {
F_3 ( ! V_147 -> V_150 ) ;
F_3 ( ! V_148 ) ;
if ( V_147 -> V_150 <= F_95 ( V_148 , V_147 -> V_152 ) )
V_147 -> V_154 = true ;
}
return true ;
}
static void F_100 ( struct V_146 * V_147 ,
T_1 V_98 )
{
struct V_38 * V_144 = V_147 -> V_144 ;
int F_67 ;
F_3 ( V_144 -> type != V_162 ) ;
F_3 ( ! V_144 -> V_163 ) ;
F_3 ( ! V_144 -> V_98 ) ;
V_147 -> V_150 = F_94 ( V_98 , V_144 -> V_98 ) ;
F_67 = F_101 ( V_144 -> V_164 , ( V_165 ) V_144 -> V_98 ) ;
V_147 -> V_97 = V_144 -> V_164 & ~ V_166 ;
V_147 -> V_167 = 0 ;
F_3 ( F_67 > ( int ) V_168 ) ;
V_147 -> F_67 = ( unsigned short ) F_67 ;
F_3 ( V_98 > V_169 - V_147 -> V_97 ) ;
V_147 -> V_154 = V_147 -> V_97 + V_147 -> V_150 <= V_100 ;
}
static struct V_96 *
F_102 ( struct V_146 * V_147 ,
T_1 * V_97 , T_1 * V_98 )
{
struct V_38 * V_144 = V_147 -> V_144 ;
F_3 ( V_144 -> type != V_162 ) ;
F_3 ( V_147 -> V_167 >= V_147 -> F_67 ) ;
F_3 ( V_147 -> V_97 >= V_100 ) ;
* V_97 = V_147 -> V_97 ;
if ( V_147 -> V_154 )
* V_98 = V_147 -> V_150 ;
else
* V_98 = V_100 - * V_97 ;
return V_144 -> V_163 [ V_147 -> V_167 ] ;
}
static bool F_103 ( struct V_146 * V_147 ,
T_1 V_159 )
{
F_3 ( V_147 -> V_144 -> type != V_162 ) ;
F_3 ( V_147 -> V_97 + V_159 > V_100 ) ;
V_147 -> V_150 -= V_159 ;
V_147 -> V_97 = ( V_147 -> V_97 + V_159 ) & ~ V_166 ;
if ( ! V_159 || V_147 -> V_97 )
return false ;
if ( ! V_147 -> V_150 )
return false ;
F_3 ( V_147 -> V_167 >= V_147 -> F_67 ) ;
V_147 -> V_167 ++ ;
V_147 -> V_154 = V_147 -> V_150 <= V_100 ;
return true ;
}
static void
F_104 ( struct V_146 * V_147 ,
T_1 V_98 )
{
struct V_38 * V_144 = V_147 -> V_144 ;
struct V_170 * V_171 ;
struct V_96 * V_96 ;
F_3 ( V_144 -> type != V_172 ) ;
V_171 = V_144 -> V_171 ;
F_3 ( ! V_171 ) ;
if ( ! V_98 )
return;
F_3 ( F_73 ( & V_171 -> V_114 ) ) ;
V_96 = F_74 ( & V_171 -> V_114 , struct V_96 , V_173 ) ;
V_147 -> V_150 = F_94 ( V_98 , V_171 -> V_98 ) ;
V_147 -> V_96 = V_96 ;
V_147 -> V_105 = 0 ;
V_147 -> V_154 = V_147 -> V_150 <= V_100 ;
}
static struct V_96 *
F_105 ( struct V_146 * V_147 ,
T_1 * V_97 , T_1 * V_98 )
{
struct V_38 * V_144 = V_147 -> V_144 ;
struct V_170 * V_171 ;
F_3 ( V_144 -> type != V_172 ) ;
V_171 = V_144 -> V_171 ;
F_3 ( ! V_171 ) ;
F_3 ( ! V_147 -> V_96 ) ;
F_3 ( V_147 -> V_105 + V_147 -> V_150 != V_171 -> V_98 ) ;
* V_97 = V_147 -> V_105 & ~ V_166 ;
if ( V_147 -> V_154 )
* V_98 = V_147 -> V_150 ;
else
* V_98 = V_100 - * V_97 ;
return V_147 -> V_96 ;
}
static bool F_106 ( struct V_146 * V_147 ,
T_1 V_159 )
{
struct V_38 * V_144 = V_147 -> V_144 ;
struct V_170 * V_171 ;
F_3 ( V_144 -> type != V_172 ) ;
V_171 = V_144 -> V_171 ;
F_3 ( ! V_171 ) ;
F_3 ( V_147 -> V_105 + V_147 -> V_150 != V_171 -> V_98 ) ;
F_3 ( ( V_147 -> V_105 & ~ V_166 ) + V_159 > V_100 ) ;
V_147 -> V_150 -= V_159 ;
V_147 -> V_105 += V_159 ;
if ( ! V_159 || V_147 -> V_105 & ~ V_166 )
return false ;
if ( ! V_147 -> V_150 )
return false ;
F_3 ( F_107 ( & V_147 -> V_96 -> V_173 , & V_171 -> V_114 ) ) ;
V_147 -> V_96 = F_108 ( V_147 -> V_96 , V_173 ) ;
V_147 -> V_154 = V_147 -> V_150 <= V_100 ;
return true ;
}
static void F_109 ( struct V_146 * V_147 )
{
T_1 V_98 = V_147 -> V_174 ;
switch ( V_147 -> V_144 -> type ) {
case V_172 :
F_104 ( V_147 , V_98 ) ;
break;
case V_162 :
F_100 ( V_147 , V_98 ) ;
break;
#ifdef F_110
case V_149 :
F_93 ( V_147 , V_98 ) ;
break;
#endif
case V_175 :
default:
break;
}
V_147 -> V_176 = true ;
}
static void F_111 ( struct V_35 * V_90 , T_1 V_98 )
{
struct V_146 * V_147 = & V_90 -> V_147 ;
struct V_38 * V_144 ;
F_3 ( ! V_98 ) ;
F_3 ( V_98 > V_90 -> V_177 ) ;
F_3 ( F_73 ( & V_90 -> V_144 ) ) ;
V_147 -> V_178 = & V_90 -> V_144 ;
V_147 -> V_174 = V_98 ;
V_144 = F_74 ( & V_90 -> V_144 , struct V_38 , V_179 ) ;
V_147 -> V_144 = V_144 ;
F_109 ( V_147 ) ;
}
static struct V_96 * F_112 ( struct V_146 * V_147 ,
T_1 * V_97 , T_1 * V_98 ,
bool * V_154 )
{
struct V_96 * V_96 ;
switch ( V_147 -> V_144 -> type ) {
case V_172 :
V_96 = F_105 ( V_147 , V_97 , V_98 ) ;
break;
case V_162 :
V_96 = F_102 ( V_147 , V_97 , V_98 ) ;
break;
#ifdef F_110
case V_149 :
V_96 = F_96 ( V_147 , V_97 , V_98 ) ;
break;
#endif
case V_175 :
default:
V_96 = NULL ;
break;
}
F_3 ( ! V_96 ) ;
F_3 ( * V_97 + * V_98 > V_100 ) ;
F_3 ( ! * V_98 ) ;
if ( V_154 )
* V_154 = V_147 -> V_154 ;
return V_96 ;
}
static bool F_113 ( struct V_146 * V_147 ,
T_1 V_159 )
{
bool V_180 ;
F_3 ( V_159 > V_147 -> V_150 ) ;
switch ( V_147 -> V_144 -> type ) {
case V_172 :
V_180 = F_106 ( V_147 , V_159 ) ;
break;
case V_162 :
V_180 = F_103 ( V_147 , V_159 ) ;
break;
#ifdef F_110
case V_149 :
V_180 = F_98 ( V_147 , V_159 ) ;
break;
#endif
case V_175 :
default:
F_114 () ;
break;
}
V_147 -> V_174 -= V_159 ;
if ( ! V_147 -> V_150 && V_147 -> V_174 ) {
F_36 ( ! V_147 -> V_154 ) ;
F_3 ( F_107 ( & V_147 -> V_144 -> V_179 , V_147 -> V_178 ) ) ;
V_147 -> V_144 = F_108 ( V_147 -> V_144 , V_179 ) ;
F_109 ( V_147 ) ;
V_180 = true ;
}
V_147 -> V_176 = V_180 ;
return V_180 ;
}
static void F_115 ( struct V_35 * V_90 , T_4 V_181 )
{
F_3 ( ! V_90 ) ;
F_3 ( ! V_181 ) ;
F_111 ( V_90 , ( T_1 ) V_181 ) ;
}
static void F_116 ( struct V_7 * V_8 )
{
struct V_35 * V_182 = V_8 -> V_120 ;
int V_183 = V_8 -> V_140 ;
V_182 -> V_184 . V_9 |= V_185 ;
F_38 ( L_26 , V_8 ) ;
V_8 -> V_186 = true ;
V_8 -> V_143 [ V_183 ] . V_107 = & V_182 -> V_184 ;
if ( V_8 -> V_187 & V_188 ) {
if ( V_8 -> V_76 -> V_189 )
V_8 -> V_76 -> V_189 ( V_8 , V_182 ) ;
else
V_182 -> V_184 . V_190 = 0 ;
V_8 -> V_143 [ V_183 ] . V_108 = sizeof( V_182 -> V_184 ) ;
V_8 -> V_141 += sizeof( V_182 -> V_184 ) ;
} else {
V_182 -> V_191 . V_9 = V_182 -> V_184 . V_9 ;
V_8 -> V_143 [ V_183 ] . V_108 = sizeof( V_182 -> V_191 ) ;
V_8 -> V_141 += sizeof( V_182 -> V_191 ) ;
}
V_8 -> V_140 ++ ;
V_8 -> V_192 = V_182 -> V_193 ;
V_8 -> V_194 = true ;
}
static void F_117 ( struct V_7 * V_8 )
{
struct V_35 * V_182 ;
T_4 V_195 ;
F_90 ( V_8 ) ;
V_8 -> V_186 = true ;
V_8 -> V_194 = false ;
if ( V_8 -> V_121 > V_8 -> V_122 ) {
V_8 -> V_122 = V_8 -> V_121 ;
F_91 ( V_8 , sizeof ( V_196 ) , & V_196 ) ;
V_8 -> V_197 = F_81 ( V_8 -> V_122 ) ;
F_91 ( V_8 , sizeof ( V_8 -> V_197 ) ,
& V_8 -> V_197 ) ;
}
F_3 ( F_73 ( & V_8 -> V_115 ) ) ;
V_182 = F_74 ( & V_8 -> V_115 , struct V_35 , V_112 ) ;
V_8 -> V_120 = V_182 ;
F_3 ( V_182 -> V_8 != V_8 ) ;
F_118 ( V_182 ) ;
F_119 ( & V_182 -> V_112 , & V_8 -> V_116 ) ;
if ( V_182 -> V_198 ) {
V_182 -> V_199 . V_200 = F_81 ( ++ V_8 -> V_119 ) ;
V_182 -> V_198 = false ;
}
F_36 ( V_182 -> V_177 != F_120 ( V_182 -> V_199 . V_181 ) ) ;
F_38 ( L_27 ,
V_182 , V_8 -> V_119 , F_121 ( V_182 -> V_199 . type ) ,
F_120 ( V_182 -> V_199 . V_201 ) , F_120 ( V_182 -> V_199 . V_202 ) ,
V_182 -> V_177 ) ;
F_3 ( F_120 ( V_182 -> V_199 . V_201 ) != V_182 -> V_203 . V_108 ) ;
F_91 ( V_8 , sizeof ( V_204 ) , & V_204 ) ;
F_91 ( V_8 , sizeof ( V_182 -> V_199 ) , & V_182 -> V_199 ) ;
F_91 ( V_8 , V_182 -> V_203 . V_108 , V_182 -> V_203 . V_107 ) ;
if ( V_182 -> V_205 )
F_91 ( V_8 , V_182 -> V_205 -> V_206 . V_108 ,
V_182 -> V_205 -> V_206 . V_107 ) ;
V_195 = F_122 ( 0 , & V_182 -> V_199 , F_123 ( struct V_207 , V_195 ) ) ;
V_8 -> V_120 -> V_199 . V_195 = F_124 ( V_195 ) ;
V_8 -> V_120 -> V_184 . V_9 = 0 ;
V_195 = F_122 ( 0 , V_182 -> V_203 . V_107 , V_182 -> V_203 . V_108 ) ;
V_8 -> V_120 -> V_184 . V_208 = F_124 ( V_195 ) ;
if ( V_182 -> V_205 ) {
V_195 = F_122 ( 0 , V_182 -> V_205 -> V_206 . V_107 ,
V_182 -> V_205 -> V_206 . V_108 ) ;
V_8 -> V_120 -> V_184 . V_209 = F_124 ( V_195 ) ;
} else
V_8 -> V_120 -> V_184 . V_209 = 0 ;
F_38 ( L_28 , V_46 ,
F_120 ( V_8 -> V_120 -> V_184 . V_208 ) ,
F_120 ( V_8 -> V_120 -> V_184 . V_209 ) ) ;
V_8 -> V_120 -> V_184 . V_210 = 0 ;
if ( V_182 -> V_177 ) {
F_115 ( V_8 -> V_120 , V_182 -> V_177 ) ;
V_8 -> V_192 = 1 ;
} else {
F_116 ( V_8 ) ;
}
F_5 ( V_8 , V_4 ) ;
}
static void F_125 ( struct V_7 * V_8 )
{
F_38 ( L_29 , V_8 ,
V_8 -> V_122 , V_8 -> V_121 ) ;
V_8 -> V_122 = V_8 -> V_121 ;
F_90 ( V_8 ) ;
F_91 ( V_8 , sizeof ( V_196 ) , & V_196 ) ;
V_8 -> V_197 = F_81 ( V_8 -> V_122 ) ;
F_91 ( V_8 , sizeof ( V_8 -> V_197 ) ,
& V_8 -> V_197 ) ;
V_8 -> V_192 = 1 ;
F_5 ( V_8 , V_4 ) ;
}
static void F_126 ( struct V_7 * V_8 )
{
F_38 ( L_30 , V_8 ,
V_8 -> V_122 , V_8 -> V_121 ) ;
V_8 -> V_122 = V_8 -> V_121 ;
F_90 ( V_8 ) ;
V_8 -> V_197 = F_81 ( V_8 -> V_122 ) ;
F_91 ( V_8 , sizeof ( V_8 -> V_197 ) ,
& V_8 -> V_197 ) ;
F_5 ( V_8 , V_4 ) ;
}
static void F_127 ( struct V_7 * V_8 )
{
F_38 ( L_31 , V_8 ) ;
F_90 ( V_8 ) ;
F_91 ( V_8 , sizeof ( V_211 ) , & V_211 ) ;
F_5 ( V_8 , V_4 ) ;
}
static struct V_212 * F_128 ( struct V_7 * V_8 ,
int * V_213 )
{
struct V_212 * V_214 ;
if ( ! V_8 -> V_76 -> V_215 ) {
V_8 -> V_216 . V_217 = V_218 ;
V_8 -> V_216 . V_219 = 0 ;
return NULL ;
}
F_79 ( & V_8 -> V_123 ) ;
V_214 = V_8 -> V_76 -> V_215 ( V_8 , V_213 , V_8 -> V_220 ) ;
F_77 ( & V_8 -> V_123 ) ;
if ( F_129 ( V_214 ) )
return V_214 ;
if ( V_8 -> V_56 != V_221 )
return F_130 ( - V_95 ) ;
V_8 -> V_222 = V_214 -> V_223 ;
V_8 -> V_224 = V_214 -> V_225 ;
return V_214 ;
}
static void F_131 ( struct V_7 * V_8 )
{
F_91 ( V_8 , strlen ( V_226 ) , V_226 ) ;
F_91 ( V_8 , sizeof ( V_8 -> V_30 -> V_31 ) ,
& V_8 -> V_30 -> V_31 ) ;
V_8 -> V_192 = 0 ;
F_5 ( V_8 , V_4 ) ;
}
static int F_132 ( struct V_7 * V_8 )
{
unsigned int V_139 = F_87 ( V_8 -> V_30 , 0 ) ;
int V_227 ;
int V_213 ;
struct V_212 * V_214 ;
switch ( V_8 -> V_130 . type ) {
case V_228 :
V_227 = V_229 ;
break;
case V_230 :
V_227 = V_231 ;
break;
case V_232 :
V_227 = V_233 ;
break;
default:
F_114 () ;
}
F_38 ( L_32 , V_8 ,
V_8 -> V_118 , V_139 , V_227 ) ;
V_8 -> V_216 . V_234 = F_81 ( V_8 -> V_30 -> V_235 ) ;
V_8 -> V_216 . V_236 = F_124 ( V_237 ) ;
V_8 -> V_216 . V_118 = F_124 ( V_8 -> V_118 ) ;
V_8 -> V_216 . V_139 = F_124 ( V_139 ) ;
V_8 -> V_216 . V_238 = F_124 ( V_227 ) ;
V_8 -> V_216 . V_9 = 0 ;
V_213 = V_218 ;
V_214 = F_128 ( V_8 , & V_213 ) ;
if ( F_129 ( V_214 ) )
return F_133 ( V_214 ) ;
V_8 -> V_216 . V_217 = F_124 ( V_213 ) ;
V_8 -> V_216 . V_219 = V_214 ?
F_124 ( V_214 -> V_239 ) : 0 ;
F_91 ( V_8 , sizeof ( V_8 -> V_216 ) ,
& V_8 -> V_216 ) ;
if ( V_214 && V_214 -> V_239 )
F_91 ( V_8 , V_214 -> V_239 ,
V_214 -> V_240 ) ;
V_8 -> V_192 = 0 ;
F_5 ( V_8 , V_4 ) ;
return 0 ;
}
static int F_134 ( struct V_7 * V_8 )
{
int V_68 ;
F_38 ( L_33 , V_8 , V_8 -> V_141 ) ;
while ( V_8 -> V_141 > 0 ) {
V_68 = F_62 ( V_8 -> V_50 , V_8 -> V_142 ,
V_8 -> V_140 , V_8 -> V_141 ,
V_8 -> V_192 ) ;
if ( V_68 <= 0 )
goto V_241;
V_8 -> V_141 -= V_68 ;
if ( V_8 -> V_141 == 0 )
break;
while ( V_68 >= V_8 -> V_142 -> V_108 ) {
F_3 ( ! V_8 -> V_140 ) ;
V_68 -= V_8 -> V_142 -> V_108 ;
V_8 -> V_142 ++ ;
V_8 -> V_140 -- ;
}
if ( V_68 ) {
V_8 -> V_142 -> V_108 -= V_68 ;
V_8 -> V_142 -> V_107 += V_68 ;
}
}
V_8 -> V_140 = 0 ;
V_8 -> V_186 = false ;
V_68 = 1 ;
V_241:
F_38 ( L_34 , V_8 ,
V_8 -> V_141 , V_8 -> V_140 , V_68 ) ;
return V_68 ;
}
static T_4 F_135 ( T_4 V_195 , struct V_96 * V_96 ,
unsigned int V_97 ,
unsigned int V_98 )
{
char * V_99 ;
V_99 = F_60 ( V_96 ) ;
F_3 ( V_99 == NULL ) ;
V_195 = F_122 ( V_195 , V_99 + V_97 , V_98 ) ;
F_61 ( V_96 ) ;
return V_195 ;
}
static int F_136 ( struct V_7 * V_8 )
{
struct V_35 * V_90 = V_8 -> V_120 ;
struct V_146 * V_147 = & V_90 -> V_147 ;
bool V_242 = ! V_8 -> V_30 -> V_243 ;
T_4 V_195 ;
F_38 ( L_35 , V_46 , V_8 , V_90 ) ;
if ( F_73 ( & V_90 -> V_144 ) )
return - V_244 ;
V_195 = V_242 ? F_120 ( V_90 -> V_184 . V_210 ) : 0 ;
while ( V_147 -> V_150 ) {
struct V_96 * V_96 ;
T_1 V_97 ;
T_1 V_98 ;
bool V_154 ;
bool V_176 ;
int V_68 ;
V_96 = F_112 ( & V_90 -> V_147 , & V_97 , & V_98 ,
& V_154 ) ;
V_68 = F_66 ( V_8 -> V_50 , V_96 , V_97 ,
V_98 , ! V_154 ) ;
if ( V_68 <= 0 ) {
if ( V_242 )
V_90 -> V_184 . V_210 = F_124 ( V_195 ) ;
return V_68 ;
}
if ( V_242 && V_147 -> V_176 )
V_195 = F_135 ( V_195 , V_96 , V_97 , V_98 ) ;
V_176 = F_113 ( & V_90 -> V_147 , ( T_1 ) V_68 ) ;
}
F_38 ( L_36 , V_46 , V_8 , V_90 ) ;
if ( V_242 )
V_90 -> V_184 . V_210 = F_124 ( V_195 ) ;
else
V_90 -> V_184 . V_9 |= V_245 ;
F_90 ( V_8 ) ;
F_116 ( V_8 ) ;
return 1 ;
}
static int F_137 ( struct V_7 * V_8 )
{
int V_68 ;
while ( V_8 -> V_246 > 0 ) {
T_1 V_106 = F_94 ( V_8 -> V_246 , ( int ) V_247 ) ;
V_68 = F_66 ( V_8 -> V_50 , V_40 , 0 , V_106 , true ) ;
if ( V_68 <= 0 )
goto V_241;
V_8 -> V_246 -= V_68 ;
}
V_68 = 1 ;
V_241:
return V_68 ;
}
static void F_138 ( struct V_7 * V_8 )
{
F_38 ( L_37 , V_8 ) ;
V_8 -> V_248 = 0 ;
}
static void F_139 ( struct V_7 * V_8 )
{
F_38 ( L_38 , V_8 ) ;
V_8 -> V_248 = 0 ;
}
static void F_140 ( struct V_7 * V_8 )
{
F_38 ( L_39 , V_8 ) ;
V_8 -> V_248 = 0 ;
}
static void F_141 ( struct V_7 * V_8 )
{
F_38 ( L_40 , V_8 ) ;
V_8 -> V_248 = 0 ;
V_8 -> V_249 = V_250 ;
}
static void F_142 ( struct V_7 * V_8 )
{
F_38 ( L_41 , V_8 ) ;
V_8 -> V_248 = 0 ;
V_8 -> V_249 = V_251 ;
}
static int F_143 ( struct V_7 * V_8 )
{
F_38 ( L_42 , V_8 ) ;
F_3 ( V_8 -> V_117 != NULL ) ;
V_8 -> V_248 = 0 ;
V_8 -> V_252 = V_8 -> V_253 = V_8 -> V_254 = 0 ;
return 0 ;
}
static int F_144 ( struct V_7 * V_8 ,
int V_255 , int V_106 , void * V_256 )
{
while ( V_8 -> V_248 < V_255 ) {
int V_257 = V_255 - V_8 -> V_248 ;
int V_258 = V_106 - V_257 ;
int V_68 = F_57 ( V_8 -> V_50 , V_256 + V_258 , V_257 ) ;
if ( V_68 <= 0 )
return V_68 ;
V_8 -> V_248 += V_68 ;
}
return 1 ;
}
static int F_145 ( struct V_7 * V_8 )
{
int V_106 ;
int V_255 ;
int V_68 ;
F_38 ( L_43 , V_8 , V_8 -> V_248 ) ;
V_106 = strlen ( V_226 ) ;
V_255 = V_106 ;
V_68 = F_144 ( V_8 , V_255 , V_106 , V_8 -> V_259 ) ;
if ( V_68 <= 0 )
goto V_241;
V_106 = sizeof ( V_8 -> V_260 ) ;
V_255 += V_106 ;
V_68 = F_144 ( V_8 , V_255 , V_106 , & V_8 -> V_260 ) ;
if ( V_68 <= 0 )
goto V_241;
V_106 = sizeof ( V_8 -> V_261 ) ;
V_255 += V_106 ;
V_68 = F_144 ( V_8 , V_255 , V_106 , & V_8 -> V_261 ) ;
if ( V_68 <= 0 )
goto V_241;
V_241:
return V_68 ;
}
static int F_146 ( struct V_7 * V_8 )
{
int V_106 ;
int V_255 ;
int V_68 ;
F_38 ( L_44 , V_8 , V_8 -> V_248 ) ;
V_106 = sizeof ( V_8 -> V_262 ) ;
V_255 = V_106 ;
V_68 = F_144 ( V_8 , V_255 , V_106 , & V_8 -> V_262 ) ;
if ( V_68 <= 0 )
goto V_241;
V_106 = F_120 ( V_8 -> V_262 . V_219 ) ;
V_255 += V_106 ;
V_68 = F_144 ( V_8 , V_255 , V_106 , V_8 -> V_222 ) ;
if ( V_68 <= 0 )
goto V_241;
F_38 ( L_45 ,
V_8 , ( int ) V_8 -> V_262 . V_263 ,
F_120 ( V_8 -> V_262 . V_118 ) ,
F_120 ( V_8 -> V_262 . V_139 ) ) ;
V_241:
return V_68 ;
}
static int F_147 ( struct V_7 * V_8 )
{
if ( memcmp ( V_8 -> V_259 , V_226 , strlen ( V_226 ) ) ) {
F_30 ( L_46 ,
F_13 ( & V_8 -> V_66 . V_67 ) ) ;
V_8 -> V_264 = L_47 ;
return - 1 ;
}
return 0 ;
}
static bool F_148 ( struct V_10 * V_11 )
{
struct V_67 * V_33 = & ( (struct V_14 * ) V_11 ) -> V_24 ;
struct V_265 * V_266 = & ( (struct V_16 * ) V_11 ) -> V_27 ;
switch ( V_11 -> V_21 ) {
case V_22 :
return V_33 -> V_267 == F_149 ( V_268 ) ;
case V_26 :
return F_150 ( V_266 ) ;
default:
return true ;
}
}
static int F_151 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_21 ) {
case V_22 :
return F_15 ( ( (struct V_14 * ) V_11 ) -> V_25 ) ;
case V_26 :
return F_15 ( ( (struct V_16 * ) V_11 ) -> V_28 ) ;
}
return 0 ;
}
static void F_152 ( struct V_10 * V_11 , int V_269 )
{
switch ( V_11 -> V_21 ) {
case V_22 :
( (struct V_14 * ) V_11 ) -> V_25 = F_153 ( V_269 ) ;
break;
case V_26 :
( (struct V_16 * ) V_11 ) -> V_28 = F_153 ( V_269 ) ;
break;
}
}
static int F_154 ( const char * V_270 , T_1 V_86 , struct V_10 * V_11 ,
char V_271 , const char * * V_272 )
{
struct V_14 * V_15 = (struct V_14 * ) V_11 ;
struct V_16 * V_17 = (struct V_16 * ) V_11 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
if ( F_155 ( V_270 , V_86 , ( V_273 * ) & V_15 -> V_24 . V_267 , V_271 , V_272 ) ) {
V_11 -> V_21 = V_22 ;
return 0 ;
}
if ( F_156 ( V_270 , V_86 , ( V_273 * ) & V_17 -> V_27 . V_274 , V_271 , V_272 ) ) {
V_11 -> V_21 = V_26 ;
return 0 ;
}
return - V_244 ;
}
static int F_157 ( const char * V_275 , T_1 V_276 ,
struct V_10 * V_11 , char V_271 , const char * * V_272 )
{
const char * V_255 , * V_277 ;
char * V_278 , * V_279 = NULL ;
int V_280 , V_68 ;
V_277 = memchr ( V_275 , V_271 , V_276 ) ;
V_278 = memchr ( V_275 , ':' , V_276 ) ;
if ( V_277 && V_278 )
V_255 = V_277 < V_278 ? V_277 : V_278 ;
else if ( ! V_277 && V_278 )
V_255 = V_278 ;
else {
V_255 = V_277 ;
if ( ! V_255 )
V_255 = V_275 + V_276 ;
}
if ( V_255 <= V_275 )
return - V_244 ;
V_280 = F_158 ( NULL , V_275 , V_255 - V_275 , NULL , & V_279 , NULL ) ;
if ( V_280 > 0 )
V_68 = F_154 ( V_279 , V_280 , V_11 , - 1 , NULL ) ;
else
V_68 = - V_281 ;
F_159 ( V_279 ) ;
* V_272 = V_255 ;
F_160 ( L_48 , ( int ) ( V_255 - V_275 ) , V_275 ,
V_68 , V_68 ? L_49 : F_13 ( V_11 ) ) ;
return V_68 ;
}
static inline int F_157 ( const char * V_275 , T_1 V_276 ,
struct V_10 * V_11 , char V_271 , const char * * V_272 )
{
return - V_244 ;
}
static int F_161 ( const char * V_275 , T_1 V_276 ,
struct V_10 * V_11 , char V_271 , const char * * V_272 )
{
int V_68 ;
V_68 = F_154 ( V_275 , V_276 , V_11 , V_271 , V_272 ) ;
if ( V_68 )
V_68 = F_157 ( V_275 , V_276 , V_11 , V_271 , V_272 ) ;
return V_68 ;
}
int F_162 ( const char * V_282 , const char * V_255 ,
struct V_128 * V_33 ,
int V_283 , int * V_284 )
{
int V_12 , V_68 = - V_244 ;
const char * V_269 = V_282 ;
F_38 ( L_50 , ( int ) ( V_255 - V_282 ) , V_282 ) ;
for ( V_12 = 0 ; V_12 < V_283 ; V_12 ++ ) {
const char * V_272 ;
struct V_10 * V_11 = & V_33 [ V_12 ] . V_67 ;
int V_285 ;
char V_271 = ',' ;
if ( * V_269 == '[' ) {
V_271 = ']' ;
V_269 ++ ;
}
V_68 = F_161 ( V_269 , V_255 - V_269 , V_11 , V_271 , & V_272 ) ;
if ( V_68 )
goto V_286;
V_68 = - V_244 ;
V_269 = V_272 ;
if ( V_271 == ']' ) {
if ( * V_269 != ']' ) {
F_38 ( L_51 ) ;
goto V_286;
}
V_269 ++ ;
}
if ( V_269 < V_255 && * V_269 == ':' ) {
V_285 = 0 ;
V_269 ++ ;
while ( V_269 < V_255 && * V_269 >= '0' && * V_269 <= '9' ) {
V_285 = ( V_285 * 10 ) + ( * V_269 - '0' ) ;
V_269 ++ ;
}
if ( V_285 == 0 )
V_285 = V_287 ;
else if ( V_285 > 65535 )
goto V_286;
} else {
V_285 = V_287 ;
}
F_152 ( V_11 , V_285 ) ;
F_38 ( L_52 , F_13 ( V_11 ) ) ;
if ( V_269 == V_255 )
break;
if ( * V_269 != ',' )
goto V_286;
V_269 ++ ;
}
if ( V_269 != V_255 )
goto V_286;
if ( V_284 )
* V_284 = V_12 + 1 ;
return 0 ;
V_286:
F_30 ( L_53 , ( int ) ( V_255 - V_282 ) , V_282 ) ;
return V_68 ;
}
static int F_163 ( struct V_7 * V_8 )
{
F_38 ( L_54 , V_8 ) ;
if ( F_147 ( V_8 ) < 0 )
return - 1 ;
F_164 ( & V_8 -> V_260 ) ;
F_164 ( & V_8 -> V_261 ) ;
if ( memcmp ( & V_8 -> V_66 , & V_8 -> V_260 ,
sizeof( V_8 -> V_66 ) ) != 0 &&
! ( F_148 ( & V_8 -> V_260 . V_67 ) &&
V_8 -> V_260 . V_288 == V_8 -> V_66 . V_288 ) ) {
F_165 ( L_55 ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
( int ) F_120 ( V_8 -> V_66 . V_288 ) ,
F_13 ( & V_8 -> V_260 . V_67 ) ,
( int ) F_120 ( V_8 -> V_260 . V_288 ) ) ;
V_8 -> V_264 = L_56 ;
return - 1 ;
}
if ( F_148 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ) ) {
int V_285 = F_151 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ) ;
memcpy ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ,
& V_8 -> V_261 . V_67 ,
sizeof( V_8 -> V_261 . V_67 ) ) ;
F_152 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 , V_285 ) ;
F_16 ( V_8 -> V_30 ) ;
F_38 ( L_57 ,
F_13 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ) ) ;
}
return 0 ;
}
static int F_166 ( struct V_7 * V_8 )
{
V_165 V_289 = V_8 -> V_30 -> V_235 ;
V_165 V_290 = V_8 -> V_30 -> V_291 ;
V_165 V_292 = F_167 (
F_168 ( V_8 -> V_262 . V_234 ) ) ;
int V_68 ;
F_38 ( L_58 , V_8 , ( int ) V_8 -> V_249 ) ;
switch ( V_8 -> V_262 . V_263 ) {
case V_293 :
F_30 ( L_59
L_60 ,
F_169 ( V_8 -> V_130 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_289 , V_292 , V_292 & ~ V_289 ) ;
V_8 -> V_264 = L_61 ;
F_75 ( V_8 ) ;
return - 1 ;
case V_294 :
F_30 ( L_62
L_63 ,
F_169 ( V_8 -> V_130 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
F_120 ( V_8 -> V_216 . V_238 ) ,
F_120 ( V_8 -> V_262 . V_238 ) ) ;
V_8 -> V_264 = L_64 ;
F_75 ( V_8 ) ;
return - 1 ;
case V_295 :
V_8 -> V_220 ++ ;
F_38 ( L_65 , V_8 ,
V_8 -> V_220 ) ;
if ( V_8 -> V_220 == 2 ) {
V_8 -> V_264 = L_66 ;
return - 1 ;
}
F_90 ( V_8 ) ;
V_68 = F_132 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_139 ( V_8 ) ;
break;
case V_296 :
F_38 ( L_67 ,
F_120 ( V_8 -> V_262 . V_118 ) ) ;
F_30 ( L_68 ,
F_169 ( V_8 -> V_130 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ) ;
F_75 ( V_8 ) ;
F_90 ( V_8 ) ;
V_68 = F_132 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_139 ( V_8 ) ;
F_79 ( & V_8 -> V_123 ) ;
F_160 ( L_69 , F_169 ( V_8 -> V_130 ) ) ;
if ( V_8 -> V_76 -> V_297 )
V_8 -> V_76 -> V_297 ( V_8 ) ;
F_77 ( & V_8 -> V_123 ) ;
if ( V_8 -> V_56 != V_221 )
return - V_95 ;
break;
case V_298 :
F_38 ( L_70 ,
F_120 ( V_8 -> V_216 . V_118 ) ,
F_120 ( V_8 -> V_262 . V_118 ) ) ;
V_8 -> V_118 = F_120 ( V_8 -> V_262 . V_118 ) ;
F_90 ( V_8 ) ;
V_68 = F_132 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_139 ( V_8 ) ;
break;
case V_299 :
F_38 ( L_71 ,
V_8 -> V_125 ,
F_120 ( V_8 -> V_262 . V_139 ) ) ;
F_87 ( V_8 -> V_30 ,
F_120 ( V_8 -> V_262 . V_139 ) ) ;
F_90 ( V_8 ) ;
V_68 = F_132 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_139 ( V_8 ) ;
break;
case V_250 :
case V_251 :
if ( V_290 & ~ V_292 ) {
F_30 ( L_72
L_73 ,
F_169 ( V_8 -> V_130 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_290 , V_292 , V_290 & ~ V_292 ) ;
V_8 -> V_264 = L_61 ;
F_75 ( V_8 ) ;
return - 1 ;
}
F_36 ( V_8 -> V_56 != V_221 ) ;
V_8 -> V_56 = V_300 ;
V_8 -> V_220 = 0 ;
V_8 -> V_125 = F_120 ( V_8 -> V_262 . V_139 ) ;
V_8 -> V_118 ++ ;
V_8 -> V_187 = V_292 ;
F_38 ( L_74 ,
V_8 -> V_125 ,
F_120 ( V_8 -> V_262 . V_118 ) ,
V_8 -> V_118 ) ;
F_36 ( V_8 -> V_118 !=
F_120 ( V_8 -> V_262 . V_118 ) ) ;
if ( V_8 -> V_262 . V_9 & V_301 )
F_5 ( V_8 , V_2 ) ;
V_8 -> V_132 = 0 ;
if ( V_8 -> V_262 . V_263 == V_250 ) {
F_126 ( V_8 ) ;
F_141 ( V_8 ) ;
} else {
F_142 ( V_8 ) ;
}
break;
case V_302 :
V_8 -> V_264 = L_75 ;
return - 1 ;
default:
V_8 -> V_264 = L_76 ;
return - 1 ;
}
return 0 ;
}
static int F_170 ( struct V_7 * V_8 )
{
int V_106 = sizeof ( V_8 -> V_303 ) ;
int V_255 = V_106 ;
return F_144 ( V_8 , V_255 , V_106 , & V_8 -> V_303 ) ;
}
static void F_171 ( struct V_7 * V_8 )
{
struct V_35 * V_182 ;
V_165 V_304 = F_168 ( V_8 -> V_303 ) ;
V_165 V_200 ;
while ( ! F_73 ( & V_8 -> V_116 ) ) {
V_182 = F_74 ( & V_8 -> V_116 , struct V_35 ,
V_112 ) ;
V_200 = F_168 ( V_182 -> V_199 . V_200 ) ;
if ( V_200 > V_304 )
break;
F_38 ( L_77 , V_200 ,
F_121 ( V_182 -> V_199 . type ) , V_182 ) ;
V_182 -> V_305 = V_306 ;
F_69 ( V_182 ) ;
}
F_142 ( V_8 ) ;
}
static int F_172 ( struct V_7 * V_8 ,
struct V_87 * V_307 ,
unsigned int V_308 , T_4 * V_195 )
{
int V_68 , V_257 ;
F_3 ( ! V_307 ) ;
while ( V_307 -> V_108 < V_308 ) {
F_3 ( V_307 -> V_107 == NULL ) ;
V_257 = V_308 - V_307 -> V_108 ;
V_68 = F_57 ( V_8 -> V_50 , ( char * ) V_307 -> V_107 +
V_307 -> V_108 , V_257 ) ;
if ( V_68 <= 0 )
return V_68 ;
V_307 -> V_108 += V_68 ;
}
if ( V_307 -> V_108 == V_308 )
* V_195 = F_122 ( 0 , V_307 -> V_107 , V_307 -> V_108 ) ;
return 1 ;
}
static int F_173 ( struct V_7 * V_8 )
{
struct V_35 * V_90 = V_8 -> V_117 ;
struct V_146 * V_147 = & V_90 -> V_147 ;
const bool V_242 = ! V_8 -> V_30 -> V_243 ;
struct V_96 * V_96 ;
T_1 V_97 ;
T_1 V_98 ;
T_4 V_195 = 0 ;
int V_68 ;
F_3 ( ! V_90 ) ;
if ( F_73 ( & V_90 -> V_144 ) )
return - V_309 ;
if ( V_242 )
V_195 = V_8 -> V_254 ;
while ( V_147 -> V_150 ) {
V_96 = F_112 ( & V_90 -> V_147 , & V_97 , & V_98 ,
NULL ) ;
V_68 = F_59 ( V_8 -> V_50 , V_96 , V_97 , V_98 ) ;
if ( V_68 <= 0 ) {
if ( V_242 )
V_8 -> V_254 = V_195 ;
return V_68 ;
}
if ( V_242 )
V_195 = F_135 ( V_195 , V_96 , V_97 , V_68 ) ;
( void ) F_113 ( & V_90 -> V_147 , ( T_1 ) V_68 ) ;
}
if ( V_242 )
V_8 -> V_254 = V_195 ;
return 1 ;
}
static int F_174 ( struct V_7 * V_8 )
{
struct V_35 * V_182 = V_8 -> V_117 ;
int V_106 ;
int V_255 ;
int V_68 ;
unsigned int V_201 , V_202 , V_181 ;
bool V_242 = ! V_8 -> V_30 -> V_243 ;
bool V_310 = ( V_8 -> V_187 & V_188 ) ;
V_165 V_200 ;
T_4 V_195 ;
F_38 ( L_78 , V_8 , V_182 ) ;
V_106 = sizeof ( V_8 -> V_311 ) ;
V_255 = V_106 ;
V_68 = F_144 ( V_8 , V_255 , V_106 , & V_8 -> V_311 ) ;
if ( V_68 <= 0 )
return V_68 ;
V_195 = F_122 ( 0 , & V_8 -> V_311 , F_123 ( struct V_207 , V_195 ) ) ;
if ( F_124 ( V_195 ) != V_8 -> V_311 . V_195 ) {
F_30 ( L_79 ,
V_195 , V_8 -> V_311 . V_195 ) ;
return - V_312 ;
}
V_201 = F_120 ( V_8 -> V_311 . V_201 ) ;
if ( V_201 > V_313 )
return - V_309 ;
V_202 = F_120 ( V_8 -> V_311 . V_202 ) ;
if ( V_202 > V_314 )
return - V_309 ;
V_181 = F_120 ( V_8 -> V_311 . V_181 ) ;
if ( V_181 > V_315 )
return - V_309 ;
V_200 = F_168 ( V_8 -> V_311 . V_200 ) ;
if ( ( V_316 ) V_200 - ( V_316 ) V_8 -> V_121 < 1 ) {
F_160 ( L_80 ,
F_169 ( V_8 -> V_130 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_200 , V_8 -> V_121 + 1 ) ;
V_8 -> V_248 = - V_201 - V_202 - V_181 -
sizeof( V_182 -> V_184 ) ;
V_8 -> V_249 = V_251 ;
return 0 ;
} else if ( ( V_316 ) V_200 - ( V_316 ) V_8 -> V_121 > 1 ) {
F_30 ( L_81 ,
V_200 , V_8 -> V_121 + 1 ) ;
V_8 -> V_264 = L_82 ;
return - V_317 ;
}
if ( ! V_8 -> V_117 ) {
int V_318 = 0 ;
F_38 ( L_83 , V_8 -> V_311 . type ,
V_201 , V_181 ) ;
V_68 = F_175 ( V_8 , & V_318 ) ;
if ( V_68 < 0 )
return V_68 ;
F_3 ( ! V_8 -> V_117 ^ V_318 ) ;
if ( V_8 -> V_117 && V_181 > V_8 -> V_117 -> V_177 ) {
F_165 ( L_84 ,
V_46 , V_181 , V_8 -> V_117 -> V_177 ) ;
F_71 ( V_8 -> V_117 ) ;
V_8 -> V_117 = NULL ;
V_318 = 1 ;
}
if ( V_318 ) {
F_38 ( L_85 ) ;
V_8 -> V_248 = - V_201 - V_202 - V_181 -
sizeof( V_182 -> V_184 ) ;
V_8 -> V_249 = V_251 ;
V_8 -> V_121 ++ ;
return 0 ;
}
F_3 ( ! V_8 -> V_117 ) ;
F_3 ( V_8 -> V_117 -> V_8 != V_8 ) ;
V_182 = V_8 -> V_117 ;
V_182 -> V_203 . V_108 = 0 ;
if ( V_182 -> V_205 )
V_182 -> V_205 -> V_206 . V_108 = 0 ;
if ( V_181 )
F_115 ( V_8 -> V_117 , V_181 ) ;
}
V_68 = F_172 ( V_8 , & V_182 -> V_203 , V_201 ,
& V_8 -> V_252 ) ;
if ( V_68 <= 0 )
return V_68 ;
if ( V_182 -> V_205 ) {
V_68 = F_172 ( V_8 , & V_182 -> V_205 -> V_206 ,
V_202 ,
& V_8 -> V_253 ) ;
if ( V_68 <= 0 )
return V_68 ;
}
if ( V_181 ) {
V_68 = F_173 ( V_8 ) ;
if ( V_68 <= 0 )
return V_68 ;
}
if ( V_310 )
V_106 = sizeof( V_182 -> V_184 ) ;
else
V_106 = sizeof( V_182 -> V_191 ) ;
V_255 += V_106 ;
V_68 = F_144 ( V_8 , V_255 , V_106 , & V_182 -> V_184 ) ;
if ( V_68 <= 0 )
return V_68 ;
if ( ! V_310 ) {
V_182 -> V_184 . V_9 = V_182 -> V_191 . V_9 ;
V_182 -> V_184 . V_190 = 0 ;
}
F_38 ( L_86 ,
V_182 , V_201 , V_182 -> V_184 . V_208 , V_202 ,
V_182 -> V_184 . V_209 , V_181 , V_182 -> V_184 . V_210 ) ;
if ( V_8 -> V_252 != F_120 ( V_182 -> V_184 . V_208 ) ) {
F_30 ( L_87 ,
V_182 , V_8 -> V_252 , V_182 -> V_184 . V_208 ) ;
return - V_312 ;
}
if ( V_8 -> V_253 != F_120 ( V_182 -> V_184 . V_209 ) ) {
F_30 ( L_88 ,
V_182 , V_8 -> V_253 , V_182 -> V_184 . V_209 ) ;
return - V_312 ;
}
if ( V_242 &&
( V_182 -> V_184 . V_9 & V_245 ) == 0 &&
V_8 -> V_254 != F_120 ( V_182 -> V_184 . V_210 ) ) {
F_30 ( L_89 , V_182 ,
V_8 -> V_254 , F_120 ( V_182 -> V_184 . V_210 ) ) ;
return - V_312 ;
}
if ( V_310 && V_8 -> V_76 -> V_319 &&
V_8 -> V_76 -> V_319 ( V_8 , V_182 ) ) {
F_30 ( L_90 , V_182 ) ;
return - V_312 ;
}
return 1 ;
}
static void F_176 ( struct V_7 * V_8 )
{
struct V_35 * V_90 ;
F_3 ( V_8 -> V_117 -> V_8 != V_8 ) ;
V_8 -> V_117 -> V_8 = NULL ;
V_90 = V_8 -> V_117 ;
V_8 -> V_117 = NULL ;
V_8 -> V_76 -> V_113 ( V_8 ) ;
if ( V_8 -> V_130 . type == 0 )
V_8 -> V_130 = V_90 -> V_199 . V_320 ;
V_8 -> V_121 ++ ;
F_79 ( & V_8 -> V_123 ) ;
F_38 ( L_91 ,
V_90 , F_168 ( V_90 -> V_199 . V_200 ) ,
F_169 ( V_90 -> V_199 . V_320 ) ,
F_121 ( V_90 -> V_199 . type ) ,
F_177 ( F_121 ( V_90 -> V_199 . type ) ) ,
F_120 ( V_90 -> V_199 . V_201 ) ,
F_120 ( V_90 -> V_199 . V_181 ) ,
V_8 -> V_252 , V_8 -> V_253 , V_8 -> V_254 ) ;
V_8 -> V_76 -> V_321 ( V_8 , V_90 ) ;
F_77 ( & V_8 -> V_123 ) ;
}
static int F_178 ( struct V_7 * V_8 )
{
int V_68 = 1 ;
F_38 ( L_92 , V_8 , V_8 -> V_56 ) ;
V_102:
F_38 ( L_93 , V_8 -> V_141 ) ;
if ( V_8 -> V_56 == V_129 ) {
F_3 ( V_8 -> V_50 ) ;
V_8 -> V_56 = V_322 ;
F_90 ( V_8 ) ;
F_131 ( V_8 ) ;
F_138 ( V_8 ) ;
F_3 ( V_8 -> V_117 ) ;
V_8 -> V_249 = V_251 ;
F_38 ( L_94 ,
V_8 , V_8 -> V_56 ) ;
V_68 = F_50 ( V_8 ) ;
if ( V_68 < 0 ) {
V_8 -> V_264 = L_95 ;
goto V_241;
}
}
V_323:
if ( V_8 -> V_246 ) {
V_68 = F_137 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_241;
}
if ( V_8 -> V_140 ) {
V_68 = F_134 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_241;
}
if ( V_8 -> V_120 ) {
if ( V_8 -> V_194 ) {
F_71 ( V_8 -> V_120 ) ;
V_8 -> V_120 = NULL ;
goto V_324;
}
V_68 = F_136 ( V_8 ) ;
if ( V_68 == 1 )
goto V_323;
if ( V_68 == 0 )
goto V_241;
if ( V_68 < 0 ) {
F_38 ( L_96 ,
V_68 ) ;
goto V_241;
}
}
V_324:
if ( V_8 -> V_56 == V_300 ) {
if ( ! F_73 ( & V_8 -> V_115 ) ) {
F_117 ( V_8 ) ;
goto V_102;
}
if ( V_8 -> V_121 > V_8 -> V_122 ) {
F_125 ( V_8 ) ;
goto V_102;
}
if ( F_9 ( V_8 , V_3 ) ) {
F_127 ( V_8 ) ;
goto V_102;
}
}
F_2 ( V_8 , V_4 ) ;
F_38 ( L_97 ) ;
V_68 = 0 ;
V_241:
F_38 ( L_98 , V_8 , V_68 ) ;
return V_68 ;
}
static int F_179 ( struct V_7 * V_8 )
{
int V_68 = - 1 ;
V_102:
F_38 ( L_99 , V_8 , V_8 -> V_56 ) ;
if ( V_8 -> V_56 != V_322 &&
V_8 -> V_56 != V_221 &&
V_8 -> V_56 != V_300 )
return 0 ;
F_3 ( ! V_8 -> V_50 ) ;
F_38 ( L_100 , ( int ) V_8 -> V_249 ,
V_8 -> V_248 ) ;
if ( V_8 -> V_56 == V_322 ) {
F_38 ( L_101 ) ;
V_68 = F_145 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_241;
V_68 = F_163 ( V_8 ) ;
if ( V_68 < 0 )
goto V_241;
V_8 -> V_56 = V_221 ;
V_68 = F_132 ( V_8 ) ;
if ( V_68 < 0 )
goto V_241;
F_139 ( V_8 ) ;
goto V_241;
}
if ( V_8 -> V_56 == V_221 ) {
F_38 ( L_102 ) ;
V_68 = F_146 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_241;
V_68 = F_166 ( V_8 ) ;
if ( V_68 < 0 )
goto V_241;
goto V_102;
}
F_36 ( V_8 -> V_56 != V_300 ) ;
if ( V_8 -> V_248 < 0 ) {
static char V_85 [ V_325 ] ;
int V_318 = F_94 ( ( int ) sizeof ( V_85 ) , - V_8 -> V_248 ) ;
F_38 ( L_103 , V_318 , - V_8 -> V_248 ) ;
V_68 = F_57 ( V_8 -> V_50 , V_85 , V_318 ) ;
if ( V_68 <= 0 )
goto V_241;
V_8 -> V_248 += V_68 ;
if ( V_8 -> V_248 )
goto V_102;
}
if ( V_8 -> V_249 == V_251 ) {
V_68 = F_57 ( V_8 -> V_50 , & V_8 -> V_249 , 1 ) ;
if ( V_68 <= 0 )
goto V_241;
F_38 ( L_104 , ( int ) V_8 -> V_249 ) ;
switch ( V_8 -> V_249 ) {
case V_326 :
F_143 ( V_8 ) ;
break;
case V_327 :
F_140 ( V_8 ) ;
break;
case V_328 :
F_68 ( V_8 ) ;
V_8 -> V_56 = V_124 ;
goto V_241;
default:
goto V_329;
}
}
if ( V_8 -> V_249 == V_326 ) {
V_68 = F_174 ( V_8 ) ;
if ( V_68 <= 0 ) {
switch ( V_68 ) {
case - V_312 :
V_8 -> V_264 = L_105 ;
case - V_317 :
V_68 = - V_309 ;
break;
case - V_309 :
V_8 -> V_264 = L_106 ;
break;
}
goto V_241;
}
if ( V_8 -> V_249 == V_251 )
goto V_102;
F_176 ( V_8 ) ;
if ( V_8 -> V_56 == V_300 )
F_142 ( V_8 ) ;
goto V_102;
}
if ( V_8 -> V_249 == V_327 ||
V_8 -> V_249 == V_250 ) {
V_68 = F_170 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_241;
F_171 ( V_8 ) ;
goto V_102;
}
V_241:
F_38 ( L_107 , V_8 , V_68 ) ;
return V_68 ;
V_329:
F_30 ( L_108 , ( int ) V_8 -> V_249 ) ;
V_8 -> V_264 = L_109 ;
V_68 = - 1 ;
goto V_241;
}
static int F_180 ( struct V_7 * V_8 , unsigned long V_132 )
{
if ( ! V_8 -> V_76 -> V_330 ( V_8 ) ) {
F_38 ( L_110 , V_46 , V_8 ) ;
return - V_331 ;
}
if ( ! F_181 ( V_39 , & V_8 -> V_135 , V_132 ) ) {
F_38 ( L_111 , V_46 , V_8 ) ;
V_8 -> V_76 -> V_113 ( V_8 ) ;
return - V_332 ;
}
F_38 ( L_112 , V_46 , V_8 , V_132 ) ;
return 0 ;
}
static void F_45 ( struct V_7 * V_8 )
{
( void ) F_180 ( V_8 , 0 ) ;
}
static void F_78 ( struct V_7 * V_8 )
{
if ( F_182 ( & V_8 -> V_135 ) ) {
F_38 ( L_113 , V_46 , V_8 ) ;
V_8 -> V_76 -> V_113 ( V_8 ) ;
}
}
static bool F_183 ( struct V_7 * V_8 )
{
if ( ! F_9 ( V_8 , V_5 ) )
return false ;
#define CASE ( T_5 ) \
case CON_STATE_ ## x: \
con->error_msg = "socket closed (con state " #x ")"; \
break;
switch ( V_8 -> V_56 ) {
CASE ( V_333 ) ;
CASE ( V_334 ) ;
CASE ( V_335 ) ;
CASE ( V_336 ) ;
CASE ( V_337 ) ;
CASE ( V_338 ) ;
default:
F_165 ( L_114 ,
V_46 , V_8 , V_8 -> V_56 ) ;
V_8 -> V_264 = L_115 ;
F_114 () ;
break;
}
#undef CASE
return true ;
}
static bool F_184 ( struct V_7 * V_8 )
{
int V_68 ;
if ( ! F_9 ( V_8 , V_6 ) )
return false ;
V_68 = F_180 ( V_8 , F_185 ( V_8 -> V_132 ) ) ;
if ( V_68 ) {
F_38 ( L_116 , V_46 ,
V_8 , V_8 -> V_132 ) ;
F_3 ( V_68 == - V_331 ) ;
F_5 ( V_8 , V_6 ) ;
}
return true ;
}
static void F_186 ( struct V_7 * V_8 )
{
if ( V_8 -> V_220 && V_8 -> V_76 -> V_339 ) {
F_38 ( L_117 ) ;
V_8 -> V_76 -> V_339 ( V_8 ) ;
}
if ( V_8 -> V_76 -> V_340 )
V_8 -> V_76 -> V_340 ( V_8 ) ;
}
static void V_136 ( struct V_341 * V_135 )
{
struct V_7 * V_8 = F_187 ( V_135 , struct V_7 ,
V_135 . V_135 ) ;
bool V_340 ;
F_77 ( & V_8 -> V_123 ) ;
while ( true ) {
int V_68 ;
if ( ( V_340 = F_183 ( V_8 ) ) ) {
F_38 ( L_118 , V_46 , V_8 ) ;
break;
}
if ( F_184 ( V_8 ) ) {
F_38 ( L_119 , V_46 , V_8 ) ;
break;
}
if ( V_8 -> V_56 == V_342 ) {
F_38 ( L_120 , V_46 , V_8 ) ;
break;
}
if ( V_8 -> V_56 == V_124 ) {
F_38 ( L_121 , V_46 , V_8 ) ;
F_3 ( V_8 -> V_50 ) ;
break;
}
if ( V_8 -> V_56 == V_129 ) {
F_38 ( L_122 , V_46 , V_8 ) ;
F_3 ( V_8 -> V_50 ) ;
}
V_68 = F_179 ( V_8 ) ;
if ( V_68 < 0 ) {
if ( V_68 == - V_95 )
continue;
if ( ! V_8 -> V_264 )
V_8 -> V_264 = L_123 ;
V_340 = true ;
break;
}
V_68 = F_178 ( V_8 ) ;
if ( V_68 < 0 ) {
if ( V_68 == - V_95 )
continue;
if ( ! V_8 -> V_264 )
V_8 -> V_264 = L_124 ;
V_340 = true ;
}
break;
}
if ( V_340 )
F_188 ( V_8 ) ;
F_79 ( & V_8 -> V_123 ) ;
if ( V_340 )
F_186 ( V_8 ) ;
V_8 -> V_76 -> V_113 ( V_8 ) ;
}
static void F_188 ( struct V_7 * V_8 )
{
F_38 ( L_125 ,
V_8 , V_8 -> V_56 , F_13 ( & V_8 -> V_66 . V_67 ) ) ;
F_165 ( L_126 , F_169 ( V_8 -> V_130 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) , V_8 -> V_264 ) ;
V_8 -> V_264 = NULL ;
F_36 ( V_8 -> V_56 != V_322 &&
V_8 -> V_56 != V_221 &&
V_8 -> V_56 != V_300 ) ;
F_68 ( V_8 ) ;
if ( F_7 ( V_8 , V_2 ) ) {
F_38 ( L_127 ) ;
V_8 -> V_56 = V_124 ;
return;
}
if ( V_8 -> V_117 ) {
F_3 ( V_8 -> V_117 -> V_8 != V_8 ) ;
V_8 -> V_117 -> V_8 = NULL ;
F_71 ( V_8 -> V_117 ) ;
V_8 -> V_117 = NULL ;
V_8 -> V_76 -> V_113 ( V_8 ) ;
}
F_189 ( & V_8 -> V_116 , & V_8 -> V_115 ) ;
if ( F_73 ( & V_8 -> V_115 ) &&
! F_7 ( V_8 , V_3 ) ) {
F_38 ( L_128 , V_8 ) ;
F_2 ( V_8 , V_4 ) ;
V_8 -> V_56 = V_342 ;
} else {
V_8 -> V_56 = V_129 ;
if ( V_8 -> V_132 == 0 )
V_8 -> V_132 = V_343 ;
else if ( V_8 -> V_132 < V_344 )
V_8 -> V_132 *= 2 ;
F_5 ( V_8 , V_6 ) ;
F_45 ( V_8 ) ;
}
}
void F_190 ( struct V_29 * V_30 ,
struct V_128 * V_345 ,
V_165 V_235 ,
V_165 V_291 ,
bool V_243 ,
bool V_81 )
{
V_30 -> V_235 = V_235 ;
V_30 -> V_291 = V_291 ;
F_191 ( & V_30 -> V_138 ) ;
if ( V_345 )
V_30 -> V_32 . V_33 = * V_345 ;
V_30 -> V_32 . V_33 . type = 0 ;
F_192 ( & V_30 -> V_32 . V_33 . V_288 , sizeof( V_30 -> V_32 . V_33 . V_288 ) ) ;
F_16 ( V_30 ) ;
V_30 -> V_243 = V_243 ;
V_30 -> V_81 = V_81 ;
F_193 ( & V_30 -> V_53 , 0 ) ;
F_194 ( & V_30 -> V_69 , F_195 ( V_346 -> V_347 -> V_348 ) ) ;
F_38 ( L_113 , V_46 , V_30 ) ;
}
void F_196 ( struct V_29 * V_30 )
{
F_197 ( F_52 ( & V_30 -> V_69 ) ) ;
}
static void F_198 ( struct V_7 * V_8 )
{
if ( V_8 -> V_56 == V_342 ) {
F_38 ( L_129 , V_8 ) ;
V_8 -> V_56 = V_129 ;
V_8 -> V_118 ++ ;
F_36 ( F_7 ( V_8 , V_4 ) ) ;
F_36 ( F_7 ( V_8 , V_3 ) ) ;
}
}
void F_199 ( struct V_7 * V_8 , struct V_35 * V_90 )
{
V_90 -> V_199 . V_320 = V_8 -> V_30 -> V_32 . V_275 ;
F_3 ( V_90 -> V_203 . V_108 != F_120 ( V_90 -> V_199 . V_201 ) ) ;
V_90 -> V_198 = true ;
F_77 ( & V_8 -> V_123 ) ;
if ( V_8 -> V_56 == V_124 ) {
F_38 ( L_130 , V_8 , V_90 ) ;
F_71 ( V_90 ) ;
F_79 ( & V_8 -> V_123 ) ;
return;
}
F_3 ( V_90 -> V_8 != NULL ) ;
V_90 -> V_8 = V_8 -> V_76 -> V_330 ( V_8 ) ;
F_3 ( V_90 -> V_8 == NULL ) ;
F_3 ( ! F_73 ( & V_90 -> V_112 ) ) ;
F_200 ( & V_90 -> V_112 , & V_8 -> V_115 ) ;
F_38 ( L_131 , V_90 ,
F_169 ( V_8 -> V_130 ) , F_121 ( V_90 -> V_199 . type ) ,
F_177 ( F_121 ( V_90 -> V_199 . type ) ) ,
F_120 ( V_90 -> V_199 . V_201 ) ,
F_120 ( V_90 -> V_199 . V_202 ) ,
F_120 ( V_90 -> V_199 . V_181 ) ) ;
F_198 ( V_8 ) ;
F_79 ( & V_8 -> V_123 ) ;
if ( F_11 ( V_8 , V_4 ) == 0 )
F_45 ( V_8 ) ;
}
void F_201 ( struct V_35 * V_90 )
{
struct V_7 * V_8 = V_90 -> V_8 ;
if ( ! V_8 )
return;
F_77 ( & V_8 -> V_123 ) ;
if ( ! F_73 ( & V_90 -> V_112 ) ) {
F_38 ( L_132 , V_46 , V_8 , V_90 ) ;
F_70 ( & V_90 -> V_112 ) ;
F_3 ( V_90 -> V_8 == NULL ) ;
V_90 -> V_8 -> V_76 -> V_113 ( V_90 -> V_8 ) ;
V_90 -> V_8 = NULL ;
V_90 -> V_199 . V_200 = 0 ;
F_71 ( V_90 ) ;
}
if ( V_8 -> V_120 == V_90 ) {
F_38 ( L_133 , V_46 , V_8 , V_90 ) ;
V_8 -> V_120 = NULL ;
if ( V_8 -> V_186 ) {
V_8 -> V_246 = V_8 -> V_141 ;
V_8 -> V_186 = false ;
}
V_90 -> V_199 . V_200 = 0 ;
F_71 ( V_90 ) ;
}
F_79 ( & V_8 -> V_123 ) ;
}
void F_202 ( struct V_35 * V_90 )
{
struct V_7 * V_8 ;
F_3 ( V_90 == NULL ) ;
if ( ! V_90 -> V_8 ) {
F_38 ( L_134 , V_46 , V_90 ) ;
return;
}
V_8 = V_90 -> V_8 ;
F_77 ( & V_8 -> V_123 ) ;
if ( V_8 -> V_117 == V_90 ) {
unsigned int V_201 = F_120 ( V_8 -> V_311 . V_201 ) ;
unsigned int V_202 = F_120 ( V_8 -> V_311 . V_202 ) ;
unsigned int V_181 = F_120 ( V_8 -> V_311 . V_181 ) ;
F_38 ( L_135 , V_46 , V_8 , V_90 ) ;
V_8 -> V_248 = V_8 -> V_248 -
sizeof( struct V_207 ) -
V_201 -
V_202 -
V_181 -
sizeof( struct V_349 ) ;
F_71 ( V_8 -> V_117 ) ;
V_8 -> V_117 = NULL ;
V_8 -> V_249 = V_251 ;
V_8 -> V_121 ++ ;
} else {
F_38 ( L_136 ,
V_46 , V_8 , V_8 -> V_117 , V_90 ) ;
}
F_79 ( & V_8 -> V_123 ) ;
}
void F_203 ( struct V_7 * V_8 )
{
F_38 ( L_137 , V_8 ) ;
F_77 ( & V_8 -> V_123 ) ;
F_198 ( V_8 ) ;
F_79 ( & V_8 -> V_123 ) ;
if ( F_11 ( V_8 , V_3 ) == 0 &&
F_11 ( V_8 , V_4 ) == 0 )
F_45 ( V_8 ) ;
}
static struct V_38 * F_204 ( enum V_350 type )
{
struct V_38 * V_144 ;
if ( F_36 ( ! F_205 ( type ) ) )
return NULL ;
V_144 = F_206 ( V_37 , V_73 ) ;
if ( V_144 )
V_144 -> type = type ;
F_85 ( & V_144 -> V_179 ) ;
return V_144 ;
}
static void F_207 ( struct V_38 * V_144 )
{
if ( ! V_144 )
return;
F_36 ( ! F_73 ( & V_144 -> V_179 ) ) ;
if ( V_144 -> type == V_172 )
F_208 ( V_144 -> V_171 ) ;
F_209 ( V_37 , V_144 ) ;
}
void F_210 ( struct V_35 * V_90 , struct V_96 * * V_163 ,
T_1 V_98 , T_1 V_164 )
{
struct V_38 * V_144 ;
F_3 ( ! V_163 ) ;
F_3 ( ! V_98 ) ;
V_144 = F_204 ( V_162 ) ;
F_3 ( ! V_144 ) ;
V_144 -> V_163 = V_163 ;
V_144 -> V_98 = V_98 ;
V_144 -> V_164 = V_164 & ~ V_166 ;
F_200 ( & V_144 -> V_179 , & V_90 -> V_144 ) ;
V_90 -> V_177 += V_98 ;
}
void F_211 ( struct V_35 * V_90 ,
struct V_170 * V_171 )
{
struct V_38 * V_144 ;
F_3 ( ! V_171 ) ;
F_3 ( ! V_171 -> V_98 ) ;
V_144 = F_204 ( V_172 ) ;
F_3 ( ! V_144 ) ;
V_144 -> V_171 = V_171 ;
F_200 ( & V_144 -> V_179 , & V_90 -> V_144 ) ;
V_90 -> V_177 += V_171 -> V_98 ;
}
void F_212 ( struct V_35 * V_90 , struct V_148 * V_148 ,
T_1 V_98 )
{
struct V_38 * V_144 ;
F_3 ( ! V_148 ) ;
V_144 = F_204 ( V_149 ) ;
F_3 ( ! V_144 ) ;
V_144 -> V_148 = V_148 ;
V_144 -> V_151 = V_98 ;
F_200 ( & V_144 -> V_179 , & V_90 -> V_144 ) ;
V_90 -> V_177 += V_98 ;
}
struct V_35 * F_213 ( int type , int V_201 , T_6 V_9 ,
bool V_351 )
{
struct V_35 * V_182 ;
V_182 = F_206 ( V_34 , V_9 ) ;
if ( V_182 == NULL )
goto V_241;
V_182 -> V_199 . type = F_214 ( type ) ;
V_182 -> V_199 . V_352 = F_214 ( V_353 ) ;
V_182 -> V_199 . V_201 = F_124 ( V_201 ) ;
F_85 ( & V_182 -> V_112 ) ;
F_215 ( & V_182 -> V_354 ) ;
F_85 ( & V_182 -> V_144 ) ;
if ( V_201 ) {
V_182 -> V_203 . V_107 = F_216 ( V_201 , V_9 ) ;
if ( V_182 -> V_203 . V_107 == NULL ) {
F_38 ( L_138 ,
V_201 ) ;
goto V_355;
}
} else {
V_182 -> V_203 . V_107 = NULL ;
}
V_182 -> V_356 = V_182 -> V_203 . V_108 = V_201 ;
F_38 ( L_139 , V_182 , V_201 ) ;
return V_182 ;
V_355:
F_71 ( V_182 ) ;
V_241:
if ( ! V_351 ) {
F_30 ( L_140 , type ,
V_201 ) ;
F_36 ( 1 ) ;
} else {
F_38 ( L_140 , type ,
V_201 ) ;
}
return NULL ;
}
static int F_217 ( struct V_7 * V_8 , struct V_35 * V_90 )
{
int type = F_121 ( V_90 -> V_199 . type ) ;
int V_202 = F_120 ( V_90 -> V_199 . V_202 ) ;
F_38 ( L_141 , V_90 , type ,
F_177 ( type ) , V_202 ) ;
F_3 ( ! V_202 ) ;
F_3 ( V_90 -> V_205 ) ;
V_90 -> V_205 = F_218 ( V_202 , V_73 ) ;
if ( ! V_90 -> V_205 )
return - V_36 ;
return 0 ;
}
static int F_175 ( struct V_7 * V_8 , int * V_318 )
{
struct V_207 * V_199 = & V_8 -> V_311 ;
int V_202 = F_120 ( V_199 -> V_202 ) ;
struct V_35 * V_90 ;
int V_68 = 0 ;
F_3 ( V_8 -> V_117 != NULL ) ;
F_3 ( ! V_8 -> V_76 -> V_357 ) ;
F_79 ( & V_8 -> V_123 ) ;
V_90 = V_8 -> V_76 -> V_357 ( V_8 , V_199 , V_318 ) ;
F_77 ( & V_8 -> V_123 ) ;
if ( V_8 -> V_56 != V_300 ) {
if ( V_90 )
F_71 ( V_90 ) ;
return - V_95 ;
}
if ( V_90 ) {
F_3 ( * V_318 ) ;
V_8 -> V_117 = V_90 ;
V_8 -> V_117 -> V_8 = V_8 -> V_76 -> V_330 ( V_8 ) ;
F_3 ( V_8 -> V_117 -> V_8 == NULL ) ;
} else {
if ( * V_318 )
return 0 ;
V_8 -> V_264 = L_142 ;
return - V_36 ;
}
memcpy ( & V_8 -> V_117 -> V_199 , & V_8 -> V_311 , sizeof( V_8 -> V_311 ) ) ;
if ( V_202 && ! V_8 -> V_117 -> V_205 ) {
V_68 = F_217 ( V_8 , V_8 -> V_117 ) ;
if ( V_68 < 0 ) {
F_71 ( V_8 -> V_117 ) ;
V_8 -> V_117 = NULL ;
}
}
return V_68 ;
}
static void F_219 ( struct V_35 * V_182 )
{
F_38 ( L_113 , V_46 , V_182 ) ;
F_220 ( V_182 -> V_203 . V_107 ) ;
F_209 ( V_34 , V_182 ) ;
}
static void F_221 ( struct V_354 * V_354 )
{
struct V_35 * V_182 = F_187 ( V_354 , struct V_35 , V_354 ) ;
F_222 ( V_144 ) ;
struct V_112 * V_179 ;
struct V_112 * V_358 ;
F_38 ( L_113 , V_46 , V_182 ) ;
F_36 ( ! F_73 ( & V_182 -> V_112 ) ) ;
if ( V_182 -> V_205 ) {
F_223 ( V_182 -> V_205 ) ;
V_182 -> V_205 = NULL ;
}
F_189 ( & V_182 -> V_144 , & V_144 ) ;
F_224 (links, next, &data) {
struct V_38 * V_144 ;
V_144 = F_225 ( V_179 , struct V_38 , V_179 ) ;
F_70 ( V_179 ) ;
F_207 ( V_144 ) ;
}
V_182 -> V_177 = 0 ;
if ( V_182 -> V_359 )
F_226 ( V_182 -> V_359 , V_182 ) ;
else
F_219 ( V_182 ) ;
}
struct V_35 * F_118 ( struct V_35 * V_90 )
{
F_38 ( L_143 , V_46 , V_90 ,
F_44 ( & V_90 -> V_354 . V_360 ) ) ;
F_227 ( & V_90 -> V_354 ) ;
return V_90 ;
}
void F_71 ( struct V_35 * V_90 )
{
F_38 ( L_143 , V_46 , V_90 ,
F_44 ( & V_90 -> V_354 . V_360 ) ) ;
F_228 ( & V_90 -> V_354 , F_221 ) ;
}
void F_229 ( struct V_35 * V_90 )
{
F_230 ( L_144 , V_90 ,
V_90 -> V_356 , V_90 -> V_177 ) ;
F_231 ( V_361 , L_145 ,
V_362 , 16 , 1 ,
& V_90 -> V_199 , sizeof( V_90 -> V_199 ) , true ) ;
F_231 ( V_361 , L_146 ,
V_362 , 16 , 1 ,
V_90 -> V_203 . V_107 , V_90 -> V_203 . V_108 , true ) ;
if ( V_90 -> V_205 )
F_231 ( V_361 , L_147 ,
V_362 , 16 , 1 ,
V_90 -> V_205 -> V_206 . V_107 ,
V_90 -> V_205 -> V_206 . V_108 , true ) ;
F_231 ( V_361 , L_148 ,
V_362 , 16 , 1 ,
& V_90 -> V_184 , sizeof( V_90 -> V_184 ) , true ) ;
}
