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
if ( V_8 -> V_187 & V_211 ) {
struct V_212 V_213 = V_214 ;
F_91 ( V_8 , sizeof( V_215 ) , & V_215 ) ;
F_128 ( & V_8 -> V_216 , & V_213 ) ;
F_91 ( V_8 , sizeof( V_8 -> V_216 ) ,
& V_8 -> V_216 ) ;
} else {
F_91 ( V_8 , sizeof( V_217 ) , & V_217 ) ;
}
F_5 ( V_8 , V_4 ) ;
}
static struct V_218 * F_129 ( struct V_7 * V_8 ,
int * V_219 )
{
struct V_218 * V_220 ;
if ( ! V_8 -> V_76 -> V_221 ) {
V_8 -> V_222 . V_223 = V_224 ;
V_8 -> V_222 . V_225 = 0 ;
return NULL ;
}
F_79 ( & V_8 -> V_123 ) ;
V_220 = V_8 -> V_76 -> V_221 ( V_8 , V_219 , V_8 -> V_226 ) ;
F_77 ( & V_8 -> V_123 ) ;
if ( F_130 ( V_220 ) )
return V_220 ;
if ( V_8 -> V_56 != V_227 )
return F_131 ( - V_95 ) ;
V_8 -> V_228 = V_220 -> V_229 ;
V_8 -> V_230 = V_220 -> V_231 ;
return V_220 ;
}
static void F_132 ( struct V_7 * V_8 )
{
F_91 ( V_8 , strlen ( V_232 ) , V_232 ) ;
F_91 ( V_8 , sizeof ( V_8 -> V_30 -> V_31 ) ,
& V_8 -> V_30 -> V_31 ) ;
V_8 -> V_192 = 0 ;
F_5 ( V_8 , V_4 ) ;
}
static int F_133 ( struct V_7 * V_8 )
{
unsigned int V_139 = F_87 ( V_8 -> V_30 , 0 ) ;
int V_233 ;
int V_219 ;
struct V_218 * V_220 ;
switch ( V_8 -> V_130 . type ) {
case V_234 :
V_233 = V_235 ;
break;
case V_236 :
V_233 = V_237 ;
break;
case V_238 :
V_233 = V_239 ;
break;
default:
F_114 () ;
}
F_38 ( L_32 , V_8 ,
V_8 -> V_118 , V_139 , V_233 ) ;
V_8 -> V_222 . V_240 = F_81 ( V_8 -> V_30 -> V_241 ) ;
V_8 -> V_222 . V_242 = F_124 ( V_243 ) ;
V_8 -> V_222 . V_118 = F_124 ( V_8 -> V_118 ) ;
V_8 -> V_222 . V_139 = F_124 ( V_139 ) ;
V_8 -> V_222 . V_244 = F_124 ( V_233 ) ;
V_8 -> V_222 . V_9 = 0 ;
V_219 = V_224 ;
V_220 = F_129 ( V_8 , & V_219 ) ;
if ( F_130 ( V_220 ) )
return F_134 ( V_220 ) ;
V_8 -> V_222 . V_223 = F_124 ( V_219 ) ;
V_8 -> V_222 . V_225 = V_220 ?
F_124 ( V_220 -> V_245 ) : 0 ;
F_91 ( V_8 , sizeof ( V_8 -> V_222 ) ,
& V_8 -> V_222 ) ;
if ( V_220 && V_220 -> V_245 )
F_91 ( V_8 , V_220 -> V_245 ,
V_220 -> V_246 ) ;
V_8 -> V_192 = 0 ;
F_5 ( V_8 , V_4 ) ;
return 0 ;
}
static int F_135 ( struct V_7 * V_8 )
{
int V_68 ;
F_38 ( L_33 , V_8 , V_8 -> V_141 ) ;
while ( V_8 -> V_141 > 0 ) {
V_68 = F_62 ( V_8 -> V_50 , V_8 -> V_142 ,
V_8 -> V_140 , V_8 -> V_141 ,
V_8 -> V_192 ) ;
if ( V_68 <= 0 )
goto V_247;
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
V_247:
F_38 ( L_34 , V_8 ,
V_8 -> V_141 , V_8 -> V_140 , V_68 ) ;
return V_68 ;
}
static T_4 F_136 ( T_4 V_195 , struct V_96 * V_96 ,
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
static int F_137 ( struct V_7 * V_8 )
{
struct V_35 * V_90 = V_8 -> V_120 ;
struct V_146 * V_147 = & V_90 -> V_147 ;
bool V_248 = ! V_8 -> V_30 -> V_249 ;
T_4 V_195 ;
F_38 ( L_35 , V_46 , V_8 , V_90 ) ;
if ( F_73 ( & V_90 -> V_144 ) )
return - V_250 ;
V_195 = V_248 ? F_120 ( V_90 -> V_184 . V_210 ) : 0 ;
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
if ( V_248 )
V_90 -> V_184 . V_210 = F_124 ( V_195 ) ;
return V_68 ;
}
if ( V_248 && V_147 -> V_176 )
V_195 = F_136 ( V_195 , V_96 , V_97 , V_98 ) ;
V_176 = F_113 ( & V_90 -> V_147 , ( T_1 ) V_68 ) ;
}
F_38 ( L_36 , V_46 , V_8 , V_90 ) ;
if ( V_248 )
V_90 -> V_184 . V_210 = F_124 ( V_195 ) ;
else
V_90 -> V_184 . V_9 |= V_251 ;
F_90 ( V_8 ) ;
F_116 ( V_8 ) ;
return 1 ;
}
static int F_138 ( struct V_7 * V_8 )
{
int V_68 ;
while ( V_8 -> V_252 > 0 ) {
T_1 V_106 = F_94 ( V_8 -> V_252 , ( int ) V_253 ) ;
V_68 = F_66 ( V_8 -> V_50 , V_40 , 0 , V_106 , true ) ;
if ( V_68 <= 0 )
goto V_247;
V_8 -> V_252 -= V_68 ;
}
V_68 = 1 ;
V_247:
return V_68 ;
}
static void F_139 ( struct V_7 * V_8 )
{
F_38 ( L_37 , V_8 ) ;
V_8 -> V_254 = 0 ;
}
static void F_140 ( struct V_7 * V_8 )
{
F_38 ( L_38 , V_8 ) ;
V_8 -> V_254 = 0 ;
}
static void F_141 ( struct V_7 * V_8 )
{
F_38 ( L_39 , V_8 ) ;
V_8 -> V_254 = 0 ;
}
static void F_142 ( struct V_7 * V_8 )
{
F_38 ( L_40 , V_8 ) ;
V_8 -> V_254 = 0 ;
V_8 -> V_255 = V_256 ;
}
static void F_143 ( struct V_7 * V_8 )
{
F_38 ( L_41 , V_8 ) ;
V_8 -> V_254 = 0 ;
V_8 -> V_255 = V_257 ;
}
static void F_144 ( struct V_7 * V_8 )
{
F_38 ( L_42 , V_8 ) ;
V_8 -> V_254 = 0 ;
}
static int F_145 ( struct V_7 * V_8 )
{
F_38 ( L_43 , V_8 ) ;
F_3 ( V_8 -> V_117 != NULL ) ;
V_8 -> V_254 = 0 ;
V_8 -> V_258 = V_8 -> V_259 = V_8 -> V_260 = 0 ;
return 0 ;
}
static int F_146 ( struct V_7 * V_8 ,
int V_261 , int V_106 , void * V_262 )
{
while ( V_8 -> V_254 < V_261 ) {
int V_263 = V_261 - V_8 -> V_254 ;
int V_264 = V_106 - V_263 ;
int V_68 = F_57 ( V_8 -> V_50 , V_262 + V_264 , V_263 ) ;
if ( V_68 <= 0 )
return V_68 ;
V_8 -> V_254 += V_68 ;
}
return 1 ;
}
static int F_147 ( struct V_7 * V_8 )
{
int V_106 ;
int V_261 ;
int V_68 ;
F_38 ( L_44 , V_8 , V_8 -> V_254 ) ;
V_106 = strlen ( V_232 ) ;
V_261 = V_106 ;
V_68 = F_146 ( V_8 , V_261 , V_106 , V_8 -> V_265 ) ;
if ( V_68 <= 0 )
goto V_247;
V_106 = sizeof ( V_8 -> V_266 ) ;
V_261 += V_106 ;
V_68 = F_146 ( V_8 , V_261 , V_106 , & V_8 -> V_266 ) ;
if ( V_68 <= 0 )
goto V_247;
V_106 = sizeof ( V_8 -> V_267 ) ;
V_261 += V_106 ;
V_68 = F_146 ( V_8 , V_261 , V_106 , & V_8 -> V_267 ) ;
if ( V_68 <= 0 )
goto V_247;
V_247:
return V_68 ;
}
static int F_148 ( struct V_7 * V_8 )
{
int V_106 ;
int V_261 ;
int V_68 ;
F_38 ( L_45 , V_8 , V_8 -> V_254 ) ;
V_106 = sizeof ( V_8 -> V_268 ) ;
V_261 = V_106 ;
V_68 = F_146 ( V_8 , V_261 , V_106 , & V_8 -> V_268 ) ;
if ( V_68 <= 0 )
goto V_247;
V_106 = F_120 ( V_8 -> V_268 . V_225 ) ;
V_261 += V_106 ;
V_68 = F_146 ( V_8 , V_261 , V_106 , V_8 -> V_228 ) ;
if ( V_68 <= 0 )
goto V_247;
F_38 ( L_46 ,
V_8 , ( int ) V_8 -> V_268 . V_269 ,
F_120 ( V_8 -> V_268 . V_118 ) ,
F_120 ( V_8 -> V_268 . V_139 ) ) ;
V_247:
return V_68 ;
}
static int F_149 ( struct V_7 * V_8 )
{
if ( memcmp ( V_8 -> V_265 , V_232 , strlen ( V_232 ) ) ) {
F_30 ( L_47 ,
F_13 ( & V_8 -> V_66 . V_67 ) ) ;
V_8 -> V_270 = L_48 ;
return - 1 ;
}
return 0 ;
}
static bool F_150 ( struct V_10 * V_11 )
{
struct V_67 * V_33 = & ( (struct V_14 * ) V_11 ) -> V_24 ;
struct V_271 * V_272 = & ( (struct V_16 * ) V_11 ) -> V_27 ;
switch ( V_11 -> V_21 ) {
case V_22 :
return V_33 -> V_273 == F_151 ( V_274 ) ;
case V_26 :
return F_152 ( V_272 ) ;
default:
return true ;
}
}
static int F_153 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_21 ) {
case V_22 :
return F_15 ( ( (struct V_14 * ) V_11 ) -> V_25 ) ;
case V_26 :
return F_15 ( ( (struct V_16 * ) V_11 ) -> V_28 ) ;
}
return 0 ;
}
static void F_154 ( struct V_10 * V_11 , int V_275 )
{
switch ( V_11 -> V_21 ) {
case V_22 :
( (struct V_14 * ) V_11 ) -> V_25 = F_155 ( V_275 ) ;
break;
case V_26 :
( (struct V_16 * ) V_11 ) -> V_28 = F_155 ( V_275 ) ;
break;
}
}
static int F_156 ( const char * V_276 , T_1 V_86 , struct V_10 * V_11 ,
char V_277 , const char * * V_278 )
{
struct V_14 * V_15 = (struct V_14 * ) V_11 ;
struct V_16 * V_17 = (struct V_16 * ) V_11 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
if ( F_157 ( V_276 , V_86 , ( V_279 * ) & V_15 -> V_24 . V_273 , V_277 , V_278 ) ) {
V_11 -> V_21 = V_22 ;
return 0 ;
}
if ( F_158 ( V_276 , V_86 , ( V_279 * ) & V_17 -> V_27 . V_280 , V_277 , V_278 ) ) {
V_11 -> V_21 = V_26 ;
return 0 ;
}
return - V_250 ;
}
static int F_159 ( const char * V_281 , T_1 V_282 ,
struct V_10 * V_11 , char V_277 , const char * * V_278 )
{
const char * V_261 , * V_283 ;
char * V_284 , * V_285 = NULL ;
int V_286 , V_68 ;
V_283 = memchr ( V_281 , V_277 , V_282 ) ;
V_284 = memchr ( V_281 , ':' , V_282 ) ;
if ( V_283 && V_284 )
V_261 = V_283 < V_284 ? V_283 : V_284 ;
else if ( ! V_283 && V_284 )
V_261 = V_284 ;
else {
V_261 = V_283 ;
if ( ! V_261 )
V_261 = V_281 + V_282 ;
}
if ( V_261 <= V_281 )
return - V_250 ;
V_286 = F_160 ( NULL , V_281 , V_261 - V_281 , NULL , & V_285 , NULL ) ;
if ( V_286 > 0 )
V_68 = F_156 ( V_285 , V_286 , V_11 , - 1 , NULL ) ;
else
V_68 = - V_287 ;
F_161 ( V_285 ) ;
* V_278 = V_261 ;
F_162 ( L_49 , ( int ) ( V_261 - V_281 ) , V_281 ,
V_68 , V_68 ? L_50 : F_13 ( V_11 ) ) ;
return V_68 ;
}
static inline int F_159 ( const char * V_281 , T_1 V_282 ,
struct V_10 * V_11 , char V_277 , const char * * V_278 )
{
return - V_250 ;
}
static int F_163 ( const char * V_281 , T_1 V_282 ,
struct V_10 * V_11 , char V_277 , const char * * V_278 )
{
int V_68 ;
V_68 = F_156 ( V_281 , V_282 , V_11 , V_277 , V_278 ) ;
if ( V_68 )
V_68 = F_159 ( V_281 , V_282 , V_11 , V_277 , V_278 ) ;
return V_68 ;
}
int F_164 ( const char * V_288 , const char * V_261 ,
struct V_128 * V_33 ,
int V_289 , int * V_290 )
{
int V_12 , V_68 = - V_250 ;
const char * V_275 = V_288 ;
F_38 ( L_51 , ( int ) ( V_261 - V_288 ) , V_288 ) ;
for ( V_12 = 0 ; V_12 < V_289 ; V_12 ++ ) {
const char * V_278 ;
struct V_10 * V_11 = & V_33 [ V_12 ] . V_67 ;
int V_291 ;
char V_277 = ',' ;
if ( * V_275 == '[' ) {
V_277 = ']' ;
V_275 ++ ;
}
V_68 = F_163 ( V_275 , V_261 - V_275 , V_11 , V_277 , & V_278 ) ;
if ( V_68 )
goto V_292;
V_68 = - V_250 ;
V_275 = V_278 ;
if ( V_277 == ']' ) {
if ( * V_275 != ']' ) {
F_38 ( L_52 ) ;
goto V_292;
}
V_275 ++ ;
}
if ( V_275 < V_261 && * V_275 == ':' ) {
V_291 = 0 ;
V_275 ++ ;
while ( V_275 < V_261 && * V_275 >= '0' && * V_275 <= '9' ) {
V_291 = ( V_291 * 10 ) + ( * V_275 - '0' ) ;
V_275 ++ ;
}
if ( V_291 == 0 )
V_291 = V_293 ;
else if ( V_291 > 65535 )
goto V_292;
} else {
V_291 = V_293 ;
}
F_154 ( V_11 , V_291 ) ;
F_38 ( L_53 , F_13 ( V_11 ) ) ;
if ( V_275 == V_261 )
break;
if ( * V_275 != ',' )
goto V_292;
V_275 ++ ;
}
if ( V_275 != V_261 )
goto V_292;
if ( V_290 )
* V_290 = V_12 + 1 ;
return 0 ;
V_292:
F_30 ( L_54 , ( int ) ( V_261 - V_288 ) , V_288 ) ;
return V_68 ;
}
static int F_165 ( struct V_7 * V_8 )
{
F_38 ( L_55 , V_8 ) ;
if ( F_149 ( V_8 ) < 0 )
return - 1 ;
F_166 ( & V_8 -> V_266 ) ;
F_166 ( & V_8 -> V_267 ) ;
if ( memcmp ( & V_8 -> V_66 , & V_8 -> V_266 ,
sizeof( V_8 -> V_66 ) ) != 0 &&
! ( F_150 ( & V_8 -> V_266 . V_67 ) &&
V_8 -> V_266 . V_294 == V_8 -> V_66 . V_294 ) ) {
F_167 ( L_56 ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
( int ) F_120 ( V_8 -> V_66 . V_294 ) ,
F_13 ( & V_8 -> V_266 . V_67 ) ,
( int ) F_120 ( V_8 -> V_266 . V_294 ) ) ;
V_8 -> V_270 = L_57 ;
return - 1 ;
}
if ( F_150 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ) ) {
int V_291 = F_153 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ) ;
memcpy ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ,
& V_8 -> V_267 . V_67 ,
sizeof( V_8 -> V_267 . V_67 ) ) ;
F_154 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 , V_291 ) ;
F_16 ( V_8 -> V_30 ) ;
F_38 ( L_58 ,
F_13 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ) ) ;
}
return 0 ;
}
static int F_168 ( struct V_7 * V_8 )
{
V_165 V_295 = V_8 -> V_30 -> V_241 ;
V_165 V_296 = V_8 -> V_30 -> V_297 ;
V_165 V_298 = F_169 (
F_170 ( V_8 -> V_268 . V_240 ) ) ;
int V_68 ;
F_38 ( L_59 , V_8 , ( int ) V_8 -> V_255 ) ;
switch ( V_8 -> V_268 . V_269 ) {
case V_299 :
F_30 ( L_60
L_61 ,
F_171 ( V_8 -> V_130 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_295 , V_298 , V_298 & ~ V_295 ) ;
V_8 -> V_270 = L_62 ;
F_75 ( V_8 ) ;
return - 1 ;
case V_300 :
F_30 ( L_63
L_64 ,
F_171 ( V_8 -> V_130 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
F_120 ( V_8 -> V_222 . V_244 ) ,
F_120 ( V_8 -> V_268 . V_244 ) ) ;
V_8 -> V_270 = L_65 ;
F_75 ( V_8 ) ;
return - 1 ;
case V_301 :
V_8 -> V_226 ++ ;
F_38 ( L_66 , V_8 ,
V_8 -> V_226 ) ;
if ( V_8 -> V_226 == 2 ) {
V_8 -> V_270 = L_67 ;
return - 1 ;
}
F_90 ( V_8 ) ;
V_68 = F_133 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_140 ( V_8 ) ;
break;
case V_302 :
F_38 ( L_68 ,
F_120 ( V_8 -> V_268 . V_118 ) ) ;
F_30 ( L_69 ,
F_171 ( V_8 -> V_130 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ) ;
F_75 ( V_8 ) ;
F_90 ( V_8 ) ;
V_68 = F_133 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_140 ( V_8 ) ;
F_79 ( & V_8 -> V_123 ) ;
F_162 ( L_70 , F_171 ( V_8 -> V_130 ) ) ;
if ( V_8 -> V_76 -> V_303 )
V_8 -> V_76 -> V_303 ( V_8 ) ;
F_77 ( & V_8 -> V_123 ) ;
if ( V_8 -> V_56 != V_227 )
return - V_95 ;
break;
case V_304 :
F_38 ( L_71 ,
F_120 ( V_8 -> V_222 . V_118 ) ,
F_120 ( V_8 -> V_268 . V_118 ) ) ;
V_8 -> V_118 = F_120 ( V_8 -> V_268 . V_118 ) ;
F_90 ( V_8 ) ;
V_68 = F_133 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_140 ( V_8 ) ;
break;
case V_305 :
F_38 ( L_72 ,
V_8 -> V_125 ,
F_120 ( V_8 -> V_268 . V_139 ) ) ;
F_87 ( V_8 -> V_30 ,
F_120 ( V_8 -> V_268 . V_139 ) ) ;
F_90 ( V_8 ) ;
V_68 = F_133 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_140 ( V_8 ) ;
break;
case V_256 :
case V_257 :
if ( V_296 & ~ V_298 ) {
F_30 ( L_73
L_74 ,
F_171 ( V_8 -> V_130 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_296 , V_298 , V_296 & ~ V_298 ) ;
V_8 -> V_270 = L_62 ;
F_75 ( V_8 ) ;
return - 1 ;
}
F_36 ( V_8 -> V_56 != V_227 ) ;
V_8 -> V_56 = V_306 ;
V_8 -> V_226 = 0 ;
V_8 -> V_125 = F_120 ( V_8 -> V_268 . V_139 ) ;
V_8 -> V_118 ++ ;
V_8 -> V_187 = V_298 ;
F_38 ( L_75 ,
V_8 -> V_125 ,
F_120 ( V_8 -> V_268 . V_118 ) ,
V_8 -> V_118 ) ;
F_36 ( V_8 -> V_118 !=
F_120 ( V_8 -> V_268 . V_118 ) ) ;
if ( V_8 -> V_268 . V_9 & V_307 )
F_5 ( V_8 , V_2 ) ;
V_8 -> V_132 = 0 ;
if ( V_8 -> V_268 . V_269 == V_256 ) {
F_126 ( V_8 ) ;
F_142 ( V_8 ) ;
} else {
F_143 ( V_8 ) ;
}
break;
case V_308 :
V_8 -> V_270 = L_76 ;
return - 1 ;
default:
V_8 -> V_270 = L_77 ;
return - 1 ;
}
return 0 ;
}
static int F_172 ( struct V_7 * V_8 )
{
int V_106 = sizeof ( V_8 -> V_309 ) ;
int V_261 = V_106 ;
return F_146 ( V_8 , V_261 , V_106 , & V_8 -> V_309 ) ;
}
static void F_173 ( struct V_7 * V_8 )
{
struct V_35 * V_182 ;
V_165 V_310 = F_170 ( V_8 -> V_309 ) ;
V_165 V_200 ;
while ( ! F_73 ( & V_8 -> V_116 ) ) {
V_182 = F_74 ( & V_8 -> V_116 , struct V_35 ,
V_112 ) ;
V_200 = F_170 ( V_182 -> V_199 . V_200 ) ;
if ( V_200 > V_310 )
break;
F_38 ( L_78 , V_200 ,
F_121 ( V_182 -> V_199 . type ) , V_182 ) ;
V_182 -> V_311 = V_312 ;
F_69 ( V_182 ) ;
}
F_143 ( V_8 ) ;
}
static int F_174 ( struct V_7 * V_8 ,
struct V_87 * V_313 ,
unsigned int V_314 , T_4 * V_195 )
{
int V_68 , V_263 ;
F_3 ( ! V_313 ) ;
while ( V_313 -> V_108 < V_314 ) {
F_3 ( V_313 -> V_107 == NULL ) ;
V_263 = V_314 - V_313 -> V_108 ;
V_68 = F_57 ( V_8 -> V_50 , ( char * ) V_313 -> V_107 +
V_313 -> V_108 , V_263 ) ;
if ( V_68 <= 0 )
return V_68 ;
V_313 -> V_108 += V_68 ;
}
if ( V_313 -> V_108 == V_314 )
* V_195 = F_122 ( 0 , V_313 -> V_107 , V_313 -> V_108 ) ;
return 1 ;
}
static int F_175 ( struct V_7 * V_8 )
{
struct V_35 * V_90 = V_8 -> V_117 ;
struct V_146 * V_147 = & V_90 -> V_147 ;
const bool V_248 = ! V_8 -> V_30 -> V_249 ;
struct V_96 * V_96 ;
T_1 V_97 ;
T_1 V_98 ;
T_4 V_195 = 0 ;
int V_68 ;
F_3 ( ! V_90 ) ;
if ( F_73 ( & V_90 -> V_144 ) )
return - V_315 ;
if ( V_248 )
V_195 = V_8 -> V_260 ;
while ( V_147 -> V_150 ) {
V_96 = F_112 ( & V_90 -> V_147 , & V_97 , & V_98 ,
NULL ) ;
V_68 = F_59 ( V_8 -> V_50 , V_96 , V_97 , V_98 ) ;
if ( V_68 <= 0 ) {
if ( V_248 )
V_8 -> V_260 = V_195 ;
return V_68 ;
}
if ( V_248 )
V_195 = F_136 ( V_195 , V_96 , V_97 , V_68 ) ;
( void ) F_113 ( & V_90 -> V_147 , ( T_1 ) V_68 ) ;
}
if ( V_248 )
V_8 -> V_260 = V_195 ;
return 1 ;
}
static int F_176 ( struct V_7 * V_8 )
{
struct V_35 * V_182 = V_8 -> V_117 ;
int V_106 ;
int V_261 ;
int V_68 ;
unsigned int V_201 , V_202 , V_181 ;
bool V_248 = ! V_8 -> V_30 -> V_249 ;
bool V_316 = ( V_8 -> V_187 & V_188 ) ;
V_165 V_200 ;
T_4 V_195 ;
F_38 ( L_79 , V_8 , V_182 ) ;
V_106 = sizeof ( V_8 -> V_317 ) ;
V_261 = V_106 ;
V_68 = F_146 ( V_8 , V_261 , V_106 , & V_8 -> V_317 ) ;
if ( V_68 <= 0 )
return V_68 ;
V_195 = F_122 ( 0 , & V_8 -> V_317 , F_123 ( struct V_207 , V_195 ) ) ;
if ( F_124 ( V_195 ) != V_8 -> V_317 . V_195 ) {
F_30 ( L_80 ,
V_195 , V_8 -> V_317 . V_195 ) ;
return - V_318 ;
}
V_201 = F_120 ( V_8 -> V_317 . V_201 ) ;
if ( V_201 > V_319 )
return - V_315 ;
V_202 = F_120 ( V_8 -> V_317 . V_202 ) ;
if ( V_202 > V_320 )
return - V_315 ;
V_181 = F_120 ( V_8 -> V_317 . V_181 ) ;
if ( V_181 > V_321 )
return - V_315 ;
V_200 = F_170 ( V_8 -> V_317 . V_200 ) ;
if ( ( V_322 ) V_200 - ( V_322 ) V_8 -> V_121 < 1 ) {
F_162 ( L_81 ,
F_171 ( V_8 -> V_130 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_200 , V_8 -> V_121 + 1 ) ;
V_8 -> V_254 = - V_201 - V_202 - V_181 -
sizeof( V_182 -> V_184 ) ;
V_8 -> V_255 = V_257 ;
return 0 ;
} else if ( ( V_322 ) V_200 - ( V_322 ) V_8 -> V_121 > 1 ) {
F_30 ( L_82 ,
V_200 , V_8 -> V_121 + 1 ) ;
V_8 -> V_270 = L_83 ;
return - V_323 ;
}
if ( ! V_8 -> V_117 ) {
int V_324 = 0 ;
F_38 ( L_84 , V_8 -> V_317 . type ,
V_201 , V_181 ) ;
V_68 = F_177 ( V_8 , & V_324 ) ;
if ( V_68 < 0 )
return V_68 ;
F_3 ( ! V_8 -> V_117 ^ V_324 ) ;
if ( V_324 ) {
F_38 ( L_85 ) ;
V_8 -> V_254 = - V_201 - V_202 - V_181 -
sizeof( V_182 -> V_184 ) ;
V_8 -> V_255 = V_257 ;
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
V_68 = F_174 ( V_8 , & V_182 -> V_203 , V_201 ,
& V_8 -> V_258 ) ;
if ( V_68 <= 0 )
return V_68 ;
if ( V_182 -> V_205 ) {
V_68 = F_174 ( V_8 , & V_182 -> V_205 -> V_206 ,
V_202 ,
& V_8 -> V_259 ) ;
if ( V_68 <= 0 )
return V_68 ;
}
if ( V_181 ) {
V_68 = F_175 ( V_8 ) ;
if ( V_68 <= 0 )
return V_68 ;
}
if ( V_316 )
V_106 = sizeof( V_182 -> V_184 ) ;
else
V_106 = sizeof( V_182 -> V_191 ) ;
V_261 += V_106 ;
V_68 = F_146 ( V_8 , V_261 , V_106 , & V_182 -> V_184 ) ;
if ( V_68 <= 0 )
return V_68 ;
if ( ! V_316 ) {
V_182 -> V_184 . V_9 = V_182 -> V_191 . V_9 ;
V_182 -> V_184 . V_190 = 0 ;
}
F_38 ( L_86 ,
V_182 , V_201 , V_182 -> V_184 . V_208 , V_202 ,
V_182 -> V_184 . V_209 , V_181 , V_182 -> V_184 . V_210 ) ;
if ( V_8 -> V_258 != F_120 ( V_182 -> V_184 . V_208 ) ) {
F_30 ( L_87 ,
V_182 , V_8 -> V_258 , V_182 -> V_184 . V_208 ) ;
return - V_318 ;
}
if ( V_8 -> V_259 != F_120 ( V_182 -> V_184 . V_209 ) ) {
F_30 ( L_88 ,
V_182 , V_8 -> V_259 , V_182 -> V_184 . V_209 ) ;
return - V_318 ;
}
if ( V_248 &&
( V_182 -> V_184 . V_9 & V_251 ) == 0 &&
V_8 -> V_260 != F_120 ( V_182 -> V_184 . V_210 ) ) {
F_30 ( L_89 , V_182 ,
V_8 -> V_260 , F_120 ( V_182 -> V_184 . V_210 ) ) ;
return - V_318 ;
}
if ( V_316 && V_8 -> V_76 -> V_325 &&
V_8 -> V_76 -> V_325 ( V_8 , V_182 ) ) {
F_30 ( L_90 , V_182 ) ;
return - V_318 ;
}
return 1 ;
}
static void F_178 ( struct V_7 * V_8 )
{
struct V_35 * V_90 ;
F_3 ( V_8 -> V_117 -> V_8 != V_8 ) ;
V_8 -> V_117 -> V_8 = NULL ;
V_90 = V_8 -> V_117 ;
V_8 -> V_117 = NULL ;
V_8 -> V_76 -> V_113 ( V_8 ) ;
if ( V_8 -> V_130 . type == 0 )
V_8 -> V_130 = V_90 -> V_199 . V_326 ;
V_8 -> V_121 ++ ;
F_79 ( & V_8 -> V_123 ) ;
F_38 ( L_91 ,
V_90 , F_170 ( V_90 -> V_199 . V_200 ) ,
F_171 ( V_90 -> V_199 . V_326 ) ,
F_121 ( V_90 -> V_199 . type ) ,
F_179 ( F_121 ( V_90 -> V_199 . type ) ) ,
F_120 ( V_90 -> V_199 . V_201 ) ,
F_120 ( V_90 -> V_199 . V_181 ) ,
V_8 -> V_258 , V_8 -> V_259 , V_8 -> V_260 ) ;
V_8 -> V_76 -> V_327 ( V_8 , V_90 ) ;
F_77 ( & V_8 -> V_123 ) ;
}
static int F_180 ( struct V_7 * V_8 )
{
struct V_328 V_329 ;
T_1 V_106 = sizeof( V_329 ) ;
int V_68 = F_146 ( V_8 , V_106 , V_106 , & V_329 ) ;
if ( V_68 <= 0 )
return V_68 ;
F_181 ( & V_8 -> V_330 , & V_329 ) ;
F_143 ( V_8 ) ;
return 1 ;
}
static int F_182 ( struct V_7 * V_8 )
{
int V_68 = 1 ;
F_38 ( L_92 , V_8 , V_8 -> V_56 ) ;
V_102:
F_38 ( L_93 , V_8 -> V_141 ) ;
if ( V_8 -> V_56 == V_129 ) {
F_3 ( V_8 -> V_50 ) ;
V_8 -> V_56 = V_331 ;
F_90 ( V_8 ) ;
F_132 ( V_8 ) ;
F_139 ( V_8 ) ;
F_3 ( V_8 -> V_117 ) ;
V_8 -> V_255 = V_257 ;
F_38 ( L_94 ,
V_8 , V_8 -> V_56 ) ;
V_68 = F_50 ( V_8 ) ;
if ( V_68 < 0 ) {
V_8 -> V_270 = L_95 ;
goto V_247;
}
}
V_332:
if ( V_8 -> V_252 ) {
V_68 = F_138 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_247;
}
if ( V_8 -> V_140 ) {
V_68 = F_135 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_247;
}
if ( V_8 -> V_120 ) {
if ( V_8 -> V_194 ) {
F_71 ( V_8 -> V_120 ) ;
V_8 -> V_120 = NULL ;
goto V_333;
}
V_68 = F_137 ( V_8 ) ;
if ( V_68 == 1 )
goto V_332;
if ( V_68 == 0 )
goto V_247;
if ( V_68 < 0 ) {
F_38 ( L_96 ,
V_68 ) ;
goto V_247;
}
}
V_333:
if ( V_8 -> V_56 == V_306 ) {
if ( F_9 ( V_8 , V_3 ) ) {
F_127 ( V_8 ) ;
goto V_102;
}
if ( ! F_73 ( & V_8 -> V_115 ) ) {
F_117 ( V_8 ) ;
goto V_102;
}
if ( V_8 -> V_121 > V_8 -> V_122 ) {
F_125 ( V_8 ) ;
goto V_102;
}
}
F_2 ( V_8 , V_4 ) ;
F_38 ( L_97 ) ;
V_68 = 0 ;
V_247:
F_38 ( L_98 , V_8 , V_68 ) ;
return V_68 ;
}
static int F_183 ( struct V_7 * V_8 )
{
int V_68 = - 1 ;
V_102:
F_38 ( L_99 , V_8 , V_8 -> V_56 ) ;
if ( V_8 -> V_56 != V_331 &&
V_8 -> V_56 != V_227 &&
V_8 -> V_56 != V_306 )
return 0 ;
F_3 ( ! V_8 -> V_50 ) ;
F_38 ( L_100 , ( int ) V_8 -> V_255 ,
V_8 -> V_254 ) ;
if ( V_8 -> V_56 == V_331 ) {
F_38 ( L_101 ) ;
V_68 = F_147 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_247;
V_68 = F_165 ( V_8 ) ;
if ( V_68 < 0 )
goto V_247;
V_8 -> V_56 = V_227 ;
V_68 = F_133 ( V_8 ) ;
if ( V_68 < 0 )
goto V_247;
F_140 ( V_8 ) ;
goto V_247;
}
if ( V_8 -> V_56 == V_227 ) {
F_38 ( L_102 ) ;
V_68 = F_148 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_247;
V_68 = F_168 ( V_8 ) ;
if ( V_68 < 0 )
goto V_247;
goto V_102;
}
F_36 ( V_8 -> V_56 != V_306 ) ;
if ( V_8 -> V_254 < 0 ) {
static char V_85 [ V_334 ] ;
int V_324 = F_94 ( ( int ) sizeof ( V_85 ) , - V_8 -> V_254 ) ;
F_38 ( L_103 , V_324 , - V_8 -> V_254 ) ;
V_68 = F_57 ( V_8 -> V_50 , V_85 , V_324 ) ;
if ( V_68 <= 0 )
goto V_247;
V_8 -> V_254 += V_68 ;
if ( V_8 -> V_254 )
goto V_102;
}
if ( V_8 -> V_255 == V_257 ) {
V_68 = F_57 ( V_8 -> V_50 , & V_8 -> V_255 , 1 ) ;
if ( V_68 <= 0 )
goto V_247;
F_38 ( L_104 , ( int ) V_8 -> V_255 ) ;
switch ( V_8 -> V_255 ) {
case V_335 :
F_145 ( V_8 ) ;
break;
case V_336 :
F_141 ( V_8 ) ;
break;
case V_337 :
F_144 ( V_8 ) ;
break;
case V_338 :
F_68 ( V_8 ) ;
V_8 -> V_56 = V_124 ;
goto V_247;
default:
goto V_339;
}
}
if ( V_8 -> V_255 == V_335 ) {
V_68 = F_176 ( V_8 ) ;
if ( V_68 <= 0 ) {
switch ( V_68 ) {
case - V_318 :
V_8 -> V_270 = L_105 ;
case - V_323 :
V_68 = - V_315 ;
break;
case - V_315 :
V_8 -> V_270 = L_106 ;
break;
}
goto V_247;
}
if ( V_8 -> V_255 == V_257 )
goto V_102;
F_178 ( V_8 ) ;
if ( V_8 -> V_56 == V_306 )
F_143 ( V_8 ) ;
goto V_102;
}
if ( V_8 -> V_255 == V_336 ||
V_8 -> V_255 == V_256 ) {
V_68 = F_172 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_247;
F_173 ( V_8 ) ;
goto V_102;
}
if ( V_8 -> V_255 == V_337 ) {
V_68 = F_180 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_247;
goto V_102;
}
V_247:
F_38 ( L_107 , V_8 , V_68 ) ;
return V_68 ;
V_339:
F_30 ( L_108 , ( int ) V_8 -> V_255 ) ;
V_8 -> V_270 = L_109 ;
V_68 = - 1 ;
goto V_247;
}
static int F_184 ( struct V_7 * V_8 , unsigned long V_132 )
{
if ( ! V_8 -> V_76 -> V_340 ( V_8 ) ) {
F_38 ( L_110 , V_46 , V_8 ) ;
return - V_341 ;
}
if ( ! F_185 ( V_39 , & V_8 -> V_135 , V_132 ) ) {
F_38 ( L_111 , V_46 , V_8 ) ;
V_8 -> V_76 -> V_113 ( V_8 ) ;
return - V_342 ;
}
F_38 ( L_112 , V_46 , V_8 , V_132 ) ;
return 0 ;
}
static void F_45 ( struct V_7 * V_8 )
{
( void ) F_184 ( V_8 , 0 ) ;
}
static void F_78 ( struct V_7 * V_8 )
{
if ( F_186 ( & V_8 -> V_135 ) ) {
F_38 ( L_113 , V_46 , V_8 ) ;
V_8 -> V_76 -> V_113 ( V_8 ) ;
}
}
static bool F_187 ( struct V_7 * V_8 )
{
if ( ! F_9 ( V_8 , V_5 ) )
return false ;
#define CASE ( T_5 ) \
case CON_STATE_ ## x: \
con->error_msg = "socket closed (con state " #x ")"; \
break;
switch ( V_8 -> V_56 ) {
CASE ( V_343 ) ;
CASE ( V_344 ) ;
CASE ( V_345 ) ;
CASE ( V_346 ) ;
CASE ( V_347 ) ;
CASE ( V_348 ) ;
default:
F_167 ( L_114 ,
V_46 , V_8 , V_8 -> V_56 ) ;
V_8 -> V_270 = L_115 ;
F_114 () ;
break;
}
#undef CASE
return true ;
}
static bool F_188 ( struct V_7 * V_8 )
{
int V_68 ;
if ( ! F_9 ( V_8 , V_6 ) )
return false ;
V_68 = F_184 ( V_8 , F_189 ( V_8 -> V_132 ) ) ;
if ( V_68 ) {
F_38 ( L_116 , V_46 ,
V_8 , V_8 -> V_132 ) ;
F_3 ( V_68 == - V_341 ) ;
F_5 ( V_8 , V_6 ) ;
}
return true ;
}
static void F_190 ( struct V_7 * V_8 )
{
if ( V_8 -> V_226 && V_8 -> V_76 -> V_349 ) {
F_38 ( L_117 ) ;
V_8 -> V_76 -> V_349 ( V_8 ) ;
}
if ( V_8 -> V_76 -> V_350 )
V_8 -> V_76 -> V_350 ( V_8 ) ;
}
static void V_136 ( struct V_351 * V_135 )
{
struct V_7 * V_8 = F_191 ( V_135 , struct V_7 ,
V_135 . V_135 ) ;
bool V_350 ;
F_77 ( & V_8 -> V_123 ) ;
while ( true ) {
int V_68 ;
if ( ( V_350 = F_187 ( V_8 ) ) ) {
F_38 ( L_118 , V_46 , V_8 ) ;
break;
}
if ( F_188 ( V_8 ) ) {
F_38 ( L_119 , V_46 , V_8 ) ;
break;
}
if ( V_8 -> V_56 == V_352 ) {
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
V_68 = F_183 ( V_8 ) ;
if ( V_68 < 0 ) {
if ( V_68 == - V_95 )
continue;
if ( ! V_8 -> V_270 )
V_8 -> V_270 = L_123 ;
V_350 = true ;
break;
}
V_68 = F_182 ( V_8 ) ;
if ( V_68 < 0 ) {
if ( V_68 == - V_95 )
continue;
if ( ! V_8 -> V_270 )
V_8 -> V_270 = L_124 ;
V_350 = true ;
}
break;
}
if ( V_350 )
F_192 ( V_8 ) ;
F_79 ( & V_8 -> V_123 ) ;
if ( V_350 )
F_190 ( V_8 ) ;
V_8 -> V_76 -> V_113 ( V_8 ) ;
}
static void F_192 ( struct V_7 * V_8 )
{
F_38 ( L_125 ,
V_8 , V_8 -> V_56 , F_13 ( & V_8 -> V_66 . V_67 ) ) ;
F_167 ( L_126 , F_171 ( V_8 -> V_130 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) , V_8 -> V_270 ) ;
V_8 -> V_270 = NULL ;
F_36 ( V_8 -> V_56 != V_331 &&
V_8 -> V_56 != V_227 &&
V_8 -> V_56 != V_306 ) ;
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
F_193 ( & V_8 -> V_116 , & V_8 -> V_115 ) ;
if ( F_73 ( & V_8 -> V_115 ) &&
! F_7 ( V_8 , V_3 ) ) {
F_38 ( L_128 , V_8 ) ;
F_2 ( V_8 , V_4 ) ;
V_8 -> V_56 = V_352 ;
} else {
V_8 -> V_56 = V_129 ;
if ( V_8 -> V_132 == 0 )
V_8 -> V_132 = V_353 ;
else if ( V_8 -> V_132 < V_354 )
V_8 -> V_132 *= 2 ;
F_5 ( V_8 , V_6 ) ;
F_45 ( V_8 ) ;
}
}
void F_194 ( struct V_29 * V_30 ,
struct V_128 * V_355 ,
V_165 V_241 ,
V_165 V_297 ,
bool V_249 ,
bool V_81 )
{
V_30 -> V_241 = V_241 ;
V_30 -> V_297 = V_297 ;
F_195 ( & V_30 -> V_138 ) ;
if ( V_355 )
V_30 -> V_32 . V_33 = * V_355 ;
V_30 -> V_32 . V_33 . type = 0 ;
F_196 ( & V_30 -> V_32 . V_33 . V_294 , sizeof( V_30 -> V_32 . V_33 . V_294 ) ) ;
F_16 ( V_30 ) ;
V_30 -> V_249 = V_249 ;
V_30 -> V_81 = V_81 ;
F_197 ( & V_30 -> V_53 , 0 ) ;
F_198 ( & V_30 -> V_69 , F_199 ( V_356 -> V_357 -> V_358 ) ) ;
F_38 ( L_113 , V_46 , V_30 ) ;
}
void F_200 ( struct V_29 * V_30 )
{
F_201 ( F_52 ( & V_30 -> V_69 ) ) ;
}
static void F_202 ( struct V_7 * V_8 )
{
if ( V_8 -> V_56 == V_352 ) {
F_38 ( L_129 , V_8 ) ;
V_8 -> V_56 = V_129 ;
V_8 -> V_118 ++ ;
F_36 ( F_7 ( V_8 , V_4 ) ) ;
F_36 ( F_7 ( V_8 , V_3 ) ) ;
}
}
void F_203 ( struct V_7 * V_8 , struct V_35 * V_90 )
{
V_90 -> V_199 . V_326 = V_8 -> V_30 -> V_32 . V_281 ;
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
V_90 -> V_8 = V_8 -> V_76 -> V_340 ( V_8 ) ;
F_3 ( V_90 -> V_8 == NULL ) ;
F_3 ( ! F_73 ( & V_90 -> V_112 ) ) ;
F_204 ( & V_90 -> V_112 , & V_8 -> V_115 ) ;
F_38 ( L_131 , V_90 ,
F_171 ( V_8 -> V_130 ) , F_121 ( V_90 -> V_199 . type ) ,
F_179 ( F_121 ( V_90 -> V_199 . type ) ) ,
F_120 ( V_90 -> V_199 . V_201 ) ,
F_120 ( V_90 -> V_199 . V_202 ) ,
F_120 ( V_90 -> V_199 . V_181 ) ) ;
F_202 ( V_8 ) ;
F_79 ( & V_8 -> V_123 ) ;
if ( F_11 ( V_8 , V_4 ) == 0 )
F_45 ( V_8 ) ;
}
void F_205 ( struct V_35 * V_90 )
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
V_8 -> V_252 = V_8 -> V_141 ;
V_8 -> V_186 = false ;
}
V_90 -> V_199 . V_200 = 0 ;
F_71 ( V_90 ) ;
}
F_79 ( & V_8 -> V_123 ) ;
}
void F_206 ( struct V_35 * V_90 )
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
unsigned int V_201 = F_120 ( V_8 -> V_317 . V_201 ) ;
unsigned int V_202 = F_120 ( V_8 -> V_317 . V_202 ) ;
unsigned int V_181 = F_120 ( V_8 -> V_317 . V_181 ) ;
F_38 ( L_135 , V_46 , V_8 , V_90 ) ;
V_8 -> V_254 = V_8 -> V_254 -
sizeof( struct V_207 ) -
V_201 -
V_202 -
V_181 -
sizeof( struct V_359 ) ;
F_71 ( V_8 -> V_117 ) ;
V_8 -> V_117 = NULL ;
V_8 -> V_255 = V_257 ;
V_8 -> V_121 ++ ;
} else {
F_38 ( L_136 ,
V_46 , V_8 , V_8 -> V_117 , V_90 ) ;
}
F_79 ( & V_8 -> V_123 ) ;
}
void F_207 ( struct V_7 * V_8 )
{
F_38 ( L_137 , V_8 ) ;
F_77 ( & V_8 -> V_123 ) ;
F_202 ( V_8 ) ;
F_79 ( & V_8 -> V_123 ) ;
if ( F_11 ( V_8 , V_3 ) == 0 &&
F_11 ( V_8 , V_4 ) == 0 )
F_45 ( V_8 ) ;
}
bool F_208 ( struct V_7 * V_8 ,
unsigned long V_360 )
{
if ( V_360 > 0 &&
( V_8 -> V_187 & V_211 ) ) {
struct V_212 V_213 = V_214 ;
struct V_212 V_361 ;
F_209 ( V_360 , & V_361 ) ;
V_361 = F_210 ( V_8 -> V_330 , V_361 ) ;
return F_211 ( & V_213 , & V_361 ) >= 0 ;
}
return false ;
}
static struct V_38 * F_212 ( enum V_362 type )
{
struct V_38 * V_144 ;
if ( F_36 ( ! F_213 ( type ) ) )
return NULL ;
V_144 = F_214 ( V_37 , V_73 ) ;
if ( V_144 )
V_144 -> type = type ;
F_85 ( & V_144 -> V_179 ) ;
return V_144 ;
}
static void F_215 ( struct V_38 * V_144 )
{
if ( ! V_144 )
return;
F_36 ( ! F_73 ( & V_144 -> V_179 ) ) ;
if ( V_144 -> type == V_172 )
F_216 ( V_144 -> V_171 ) ;
F_217 ( V_37 , V_144 ) ;
}
void F_218 ( struct V_35 * V_90 , struct V_96 * * V_163 ,
T_1 V_98 , T_1 V_164 )
{
struct V_38 * V_144 ;
F_3 ( ! V_163 ) ;
F_3 ( ! V_98 ) ;
V_144 = F_212 ( V_162 ) ;
F_3 ( ! V_144 ) ;
V_144 -> V_163 = V_163 ;
V_144 -> V_98 = V_98 ;
V_144 -> V_164 = V_164 & ~ V_166 ;
F_204 ( & V_144 -> V_179 , & V_90 -> V_144 ) ;
V_90 -> V_177 += V_98 ;
}
void F_219 ( struct V_35 * V_90 ,
struct V_170 * V_171 )
{
struct V_38 * V_144 ;
F_3 ( ! V_171 ) ;
F_3 ( ! V_171 -> V_98 ) ;
V_144 = F_212 ( V_172 ) ;
F_3 ( ! V_144 ) ;
V_144 -> V_171 = V_171 ;
F_204 ( & V_144 -> V_179 , & V_90 -> V_144 ) ;
V_90 -> V_177 += V_171 -> V_98 ;
}
void F_220 ( struct V_35 * V_90 , struct V_148 * V_148 ,
T_1 V_98 )
{
struct V_38 * V_144 ;
F_3 ( ! V_148 ) ;
V_144 = F_212 ( V_149 ) ;
F_3 ( ! V_144 ) ;
V_144 -> V_148 = V_148 ;
V_144 -> V_151 = V_98 ;
F_204 ( & V_144 -> V_179 , & V_90 -> V_144 ) ;
V_90 -> V_177 += V_98 ;
}
struct V_35 * F_221 ( int type , int V_201 , T_6 V_9 ,
bool V_363 )
{
struct V_35 * V_182 ;
V_182 = F_214 ( V_34 , V_9 ) ;
if ( V_182 == NULL )
goto V_247;
V_182 -> V_199 . type = F_222 ( type ) ;
V_182 -> V_199 . V_364 = F_222 ( V_365 ) ;
V_182 -> V_199 . V_201 = F_124 ( V_201 ) ;
F_85 ( & V_182 -> V_112 ) ;
F_223 ( & V_182 -> V_366 ) ;
F_85 ( & V_182 -> V_144 ) ;
if ( V_201 ) {
V_182 -> V_203 . V_107 = F_224 ( V_201 , V_9 ) ;
if ( V_182 -> V_203 . V_107 == NULL ) {
F_38 ( L_138 ,
V_201 ) ;
goto V_367;
}
} else {
V_182 -> V_203 . V_107 = NULL ;
}
V_182 -> V_368 = V_182 -> V_203 . V_108 = V_201 ;
F_38 ( L_139 , V_182 , V_201 ) ;
return V_182 ;
V_367:
F_71 ( V_182 ) ;
V_247:
if ( ! V_363 ) {
F_30 ( L_140 , type ,
V_201 ) ;
F_36 ( 1 ) ;
} else {
F_38 ( L_140 , type ,
V_201 ) ;
}
return NULL ;
}
static int F_225 ( struct V_7 * V_8 , struct V_35 * V_90 )
{
int type = F_121 ( V_90 -> V_199 . type ) ;
int V_202 = F_120 ( V_90 -> V_199 . V_202 ) ;
F_38 ( L_141 , V_90 , type ,
F_179 ( type ) , V_202 ) ;
F_3 ( ! V_202 ) ;
F_3 ( V_90 -> V_205 ) ;
V_90 -> V_205 = F_226 ( V_202 , V_73 ) ;
if ( ! V_90 -> V_205 )
return - V_36 ;
return 0 ;
}
static int F_177 ( struct V_7 * V_8 , int * V_324 )
{
struct V_207 * V_199 = & V_8 -> V_317 ;
int V_202 = F_120 ( V_199 -> V_202 ) ;
struct V_35 * V_90 ;
int V_68 = 0 ;
F_3 ( V_8 -> V_117 != NULL ) ;
F_3 ( ! V_8 -> V_76 -> V_369 ) ;
F_79 ( & V_8 -> V_123 ) ;
V_90 = V_8 -> V_76 -> V_369 ( V_8 , V_199 , V_324 ) ;
F_77 ( & V_8 -> V_123 ) ;
if ( V_8 -> V_56 != V_306 ) {
if ( V_90 )
F_71 ( V_90 ) ;
return - V_95 ;
}
if ( V_90 ) {
F_3 ( * V_324 ) ;
V_8 -> V_117 = V_90 ;
V_8 -> V_117 -> V_8 = V_8 -> V_76 -> V_340 ( V_8 ) ;
F_3 ( V_8 -> V_117 -> V_8 == NULL ) ;
} else {
if ( * V_324 )
return 0 ;
V_8 -> V_270 = L_142 ;
return - V_36 ;
}
memcpy ( & V_8 -> V_117 -> V_199 , & V_8 -> V_317 , sizeof( V_8 -> V_317 ) ) ;
if ( V_202 && ! V_8 -> V_117 -> V_205 ) {
V_68 = F_225 ( V_8 , V_8 -> V_117 ) ;
if ( V_68 < 0 ) {
F_71 ( V_8 -> V_117 ) ;
V_8 -> V_117 = NULL ;
}
}
return V_68 ;
}
static void F_227 ( struct V_35 * V_182 )
{
F_38 ( L_113 , V_46 , V_182 ) ;
F_228 ( V_182 -> V_203 . V_107 ) ;
F_217 ( V_34 , V_182 ) ;
}
static void F_229 ( struct V_366 * V_366 )
{
struct V_35 * V_182 = F_191 ( V_366 , struct V_35 , V_366 ) ;
F_230 ( V_144 ) ;
struct V_112 * V_179 ;
struct V_112 * V_370 ;
F_38 ( L_113 , V_46 , V_182 ) ;
F_36 ( ! F_73 ( & V_182 -> V_112 ) ) ;
if ( V_182 -> V_205 ) {
F_231 ( V_182 -> V_205 ) ;
V_182 -> V_205 = NULL ;
}
F_193 ( & V_182 -> V_144 , & V_144 ) ;
F_232 (links, next, &data) {
struct V_38 * V_144 ;
V_144 = F_233 ( V_179 , struct V_38 , V_179 ) ;
F_70 ( V_179 ) ;
F_215 ( V_144 ) ;
}
V_182 -> V_177 = 0 ;
if ( V_182 -> V_371 )
F_234 ( V_182 -> V_371 , V_182 ) ;
else
F_227 ( V_182 ) ;
}
struct V_35 * F_118 ( struct V_35 * V_90 )
{
F_38 ( L_143 , V_46 , V_90 ,
F_44 ( & V_90 -> V_366 . V_372 ) ) ;
F_235 ( & V_90 -> V_366 ) ;
return V_90 ;
}
void F_71 ( struct V_35 * V_90 )
{
F_38 ( L_143 , V_46 , V_90 ,
F_44 ( & V_90 -> V_366 . V_372 ) ) ;
F_236 ( & V_90 -> V_366 , F_229 ) ;
}
void F_237 ( struct V_35 * V_90 )
{
F_238 ( L_144 , V_90 ,
V_90 -> V_368 , V_90 -> V_177 ) ;
F_239 ( V_373 , L_145 ,
V_374 , 16 , 1 ,
& V_90 -> V_199 , sizeof( V_90 -> V_199 ) , true ) ;
F_239 ( V_373 , L_146 ,
V_374 , 16 , 1 ,
V_90 -> V_203 . V_107 , V_90 -> V_203 . V_108 , true ) ;
if ( V_90 -> V_205 )
F_239 ( V_373 , L_147 ,
V_374 , 16 , 1 ,
V_90 -> V_205 -> V_206 . V_107 ,
V_90 -> V_205 -> V_206 . V_108 , true ) ;
F_239 ( V_373 , L_148 ,
V_374 , 16 , 1 ,
& V_90 -> V_184 , sizeof( V_90 -> V_184 ) , true ) ;
}
