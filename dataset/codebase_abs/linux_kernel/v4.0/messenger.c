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
V_8 -> V_80 = L_20 ;
return V_68 ;
}
if ( V_8 -> V_30 -> V_81 ) {
int V_82 = 1 ;
V_68 = F_56 ( V_50 , V_83 , V_84 ,
( char * ) & V_82 , sizeof( V_82 ) ) ;
if ( V_68 )
F_31 ( L_21 ,
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
F_25 ( V_96 ) ;
return V_68 ;
}
static int F_61 ( struct V_61 * V_50 , struct V_87 * V_88 ,
T_1 V_101 , T_1 V_86 , int V_102 )
{
struct V_89 V_90 = { . V_91 = V_92 | V_93 } ;
int V_94 ;
if ( V_102 )
V_90 . V_91 |= V_103 ;
else
V_90 . V_91 |= V_104 ;
V_94 = F_62 ( V_50 , & V_90 , V_88 , V_101 , V_86 ) ;
if ( V_94 == - V_95 )
V_94 = 0 ;
return V_94 ;
}
static int F_63 ( struct V_61 * V_50 , struct V_96 * V_96 ,
int V_105 , T_1 V_106 , bool V_102 )
{
int V_9 = V_92 | V_93 | ( V_102 ? V_103 : V_104 ) ;
int V_68 ;
V_68 = F_64 ( V_50 , V_96 , V_105 , V_106 , V_9 ) ;
if ( V_68 == - V_95 )
V_68 = 0 ;
return V_68 ;
}
static int F_65 ( struct V_61 * V_50 , struct V_96 * V_96 ,
int V_105 , T_1 V_106 , bool V_102 )
{
int V_68 ;
struct V_87 V_88 ;
if ( F_66 ( V_96 ) >= 1 )
return F_63 ( V_50 , V_96 , V_105 , V_106 , V_102 ) ;
V_88 . V_107 = F_60 ( V_96 ) + V_105 ;
V_88 . V_108 = V_106 ;
V_68 = F_61 ( V_50 , & V_88 , 1 , V_106 , V_102 ) ;
F_25 ( V_96 ) ;
return V_68 ;
}
static int F_67 ( struct V_7 * V_8 )
{
int V_109 = 0 ;
F_39 ( L_22 , V_8 , V_8 -> V_50 ) ;
if ( V_8 -> V_50 ) {
V_109 = V_8 -> V_50 -> V_75 -> V_110 ( V_8 -> V_50 , V_111 ) ;
F_55 ( V_8 -> V_50 ) ;
V_8 -> V_50 = NULL ;
}
F_2 ( V_8 , V_5 ) ;
F_43 ( V_8 ) ;
return V_109 ;
}
static void F_68 ( struct V_35 * V_90 )
{
F_69 ( & V_90 -> V_112 ) ;
F_3 ( V_90 -> V_8 == NULL ) ;
V_90 -> V_8 -> V_75 -> V_113 ( V_90 -> V_8 ) ;
V_90 -> V_8 = NULL ;
F_70 ( V_90 ) ;
}
static void F_71 ( struct V_112 * V_114 )
{
while ( ! F_72 ( V_114 ) ) {
struct V_35 * V_90 = F_73 ( V_114 , struct V_35 ,
V_112 ) ;
F_68 ( V_90 ) ;
}
}
static void F_74 ( struct V_7 * V_8 )
{
F_39 ( L_23 , V_8 ) ;
F_71 ( & V_8 -> V_115 ) ;
F_71 ( & V_8 -> V_116 ) ;
if ( V_8 -> V_117 ) {
F_3 ( V_8 -> V_117 -> V_8 != V_8 ) ;
V_8 -> V_117 -> V_8 = NULL ;
F_70 ( V_8 -> V_117 ) ;
V_8 -> V_117 = NULL ;
V_8 -> V_75 -> V_113 ( V_8 ) ;
}
V_8 -> V_118 = 0 ;
V_8 -> V_119 = 0 ;
if ( V_8 -> V_120 ) {
F_70 ( V_8 -> V_120 ) ;
V_8 -> V_120 = NULL ;
}
V_8 -> V_121 = 0 ;
V_8 -> V_122 = 0 ;
}
void F_75 ( struct V_7 * V_8 )
{
F_76 ( & V_8 -> V_123 ) ;
F_39 ( L_24 , V_8 ,
F_13 ( & V_8 -> V_66 . V_67 ) ) ;
V_8 -> V_56 = V_124 ;
F_2 ( V_8 , V_2 ) ;
F_2 ( V_8 , V_3 ) ;
F_2 ( V_8 , V_4 ) ;
F_2 ( V_8 , V_6 ) ;
F_74 ( V_8 ) ;
V_8 -> V_125 = 0 ;
F_77 ( V_8 ) ;
F_67 ( V_8 ) ;
F_78 ( & V_8 -> V_123 ) ;
}
void F_79 ( struct V_7 * V_8 ,
T_2 V_126 , T_3 V_127 ,
struct V_128 * V_33 )
{
F_76 ( & V_8 -> V_123 ) ;
F_39 ( L_25 , V_8 , F_13 ( & V_33 -> V_67 ) ) ;
F_37 ( V_8 -> V_56 != V_124 ) ;
V_8 -> V_56 = V_129 ;
V_8 -> V_130 . type = ( T_2 ) V_126 ;
V_8 -> V_130 . V_131 = F_80 ( V_127 ) ;
memcpy ( & V_8 -> V_66 , V_33 , sizeof( * V_33 ) ) ;
V_8 -> V_132 = 0 ;
F_78 ( & V_8 -> V_123 ) ;
F_46 ( V_8 ) ;
}
bool F_81 ( struct V_7 * V_8 )
{
return V_8 -> V_118 > 0 ;
}
void F_82 ( struct V_7 * V_8 , void * V_133 ,
const struct V_134 * V_75 ,
struct V_29 * V_30 )
{
F_39 ( L_26 , V_8 ) ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> V_133 = V_133 ;
V_8 -> V_75 = V_75 ;
V_8 -> V_30 = V_30 ;
F_35 ( V_8 ) ;
F_83 ( & V_8 -> V_123 ) ;
F_84 ( & V_8 -> V_115 ) ;
F_84 ( & V_8 -> V_116 ) ;
F_85 ( & V_8 -> V_135 , V_136 ) ;
V_8 -> V_56 = V_124 ;
}
static T_4 F_86 ( struct V_29 * V_30 , T_4 V_137 )
{
T_4 V_68 ;
F_87 ( & V_30 -> V_138 ) ;
if ( V_30 -> V_139 < V_137 )
V_30 -> V_139 = V_137 ;
V_68 = ++ V_30 -> V_139 ;
F_88 ( & V_30 -> V_138 ) ;
return V_68 ;
}
static void F_89 ( struct V_7 * V_8 )
{
V_8 -> V_140 = 0 ;
V_8 -> V_141 = 0 ;
V_8 -> V_142 = & V_8 -> V_143 [ 0 ] ;
}
static void F_90 ( struct V_7 * V_8 ,
T_1 V_106 , void * V_144 )
{
int V_145 ;
V_145 = V_8 -> V_140 ;
F_3 ( V_145 >= F_91 ( V_8 -> V_143 ) ) ;
V_8 -> V_143 [ V_145 ] . V_108 = V_106 ;
V_8 -> V_143 [ V_145 ] . V_107 = V_144 ;
V_8 -> V_140 ++ ;
V_8 -> V_141 += V_106 ;
}
static void F_92 ( struct V_146 * V_147 ,
T_1 V_98 )
{
struct V_38 * V_144 = V_147 -> V_144 ;
struct V_148 * V_148 ;
F_3 ( V_144 -> type != V_149 ) ;
V_148 = V_144 -> V_148 ;
F_3 ( ! V_148 ) ;
V_147 -> V_150 = F_93 ( V_98 , V_144 -> V_151 ) ;
V_147 -> V_148 = V_148 ;
V_147 -> V_152 = V_148 -> V_153 ;
V_147 -> V_154 =
V_147 -> V_150 <= F_94 ( V_148 , V_147 -> V_152 ) ;
}
static struct V_96 * F_95 ( struct V_146 * V_147 ,
T_1 * V_97 ,
T_1 * V_98 )
{
struct V_38 * V_144 = V_147 -> V_144 ;
struct V_148 * V_148 ;
struct V_155 V_155 ;
F_3 ( V_144 -> type != V_149 ) ;
V_148 = V_147 -> V_148 ;
F_3 ( ! V_148 ) ;
V_155 = F_96 ( V_148 , V_147 -> V_152 ) ;
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
static bool F_97 ( struct V_146 * V_147 ,
T_1 V_159 )
{
struct V_148 * V_148 ;
struct V_155 V_155 ;
F_3 ( V_147 -> V_144 -> type != V_149 ) ;
V_148 = V_147 -> V_148 ;
F_3 ( ! V_148 ) ;
V_155 = F_96 ( V_148 , V_147 -> V_152 ) ;
F_3 ( V_147 -> V_150 < V_159 ) ;
V_147 -> V_150 -= V_159 ;
F_98 ( V_148 , & V_147 -> V_152 , V_159 ) ;
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
if ( V_147 -> V_150 <= F_94 ( V_148 , V_147 -> V_152 ) )
V_147 -> V_154 = true ;
}
return true ;
}
static void F_99 ( struct V_146 * V_147 ,
T_1 V_98 )
{
struct V_38 * V_144 = V_147 -> V_144 ;
int F_66 ;
F_3 ( V_144 -> type != V_162 ) ;
F_3 ( ! V_144 -> V_163 ) ;
F_3 ( ! V_144 -> V_98 ) ;
V_147 -> V_150 = F_93 ( V_98 , V_144 -> V_98 ) ;
F_66 = F_100 ( V_144 -> V_164 , ( V_165 ) V_144 -> V_98 ) ;
V_147 -> V_97 = V_144 -> V_164 & ~ V_166 ;
V_147 -> V_167 = 0 ;
F_3 ( F_66 > ( int ) V_168 ) ;
V_147 -> F_66 = ( unsigned short ) F_66 ;
F_3 ( V_98 > V_169 - V_147 -> V_97 ) ;
V_147 -> V_154 = V_147 -> V_97 + V_147 -> V_150 <= V_100 ;
}
static struct V_96 *
F_101 ( struct V_146 * V_147 ,
T_1 * V_97 , T_1 * V_98 )
{
struct V_38 * V_144 = V_147 -> V_144 ;
F_3 ( V_144 -> type != V_162 ) ;
F_3 ( V_147 -> V_167 >= V_147 -> F_66 ) ;
F_3 ( V_147 -> V_97 >= V_100 ) ;
* V_97 = V_147 -> V_97 ;
if ( V_147 -> V_154 )
* V_98 = V_147 -> V_150 ;
else
* V_98 = V_100 - * V_97 ;
return V_144 -> V_163 [ V_147 -> V_167 ] ;
}
static bool F_102 ( struct V_146 * V_147 ,
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
F_3 ( V_147 -> V_167 >= V_147 -> F_66 ) ;
V_147 -> V_167 ++ ;
V_147 -> V_154 = V_147 -> V_150 <= V_100 ;
return true ;
}
static void
F_103 ( struct V_146 * V_147 ,
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
F_3 ( F_72 ( & V_171 -> V_114 ) ) ;
V_96 = F_73 ( & V_171 -> V_114 , struct V_96 , V_173 ) ;
V_147 -> V_150 = F_93 ( V_98 , V_171 -> V_98 ) ;
V_147 -> V_96 = V_96 ;
V_147 -> V_105 = 0 ;
V_147 -> V_154 = V_147 -> V_150 <= V_100 ;
}
static struct V_96 *
F_104 ( struct V_146 * V_147 ,
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
static bool F_105 ( struct V_146 * V_147 ,
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
F_3 ( F_106 ( & V_147 -> V_96 -> V_173 , & V_171 -> V_114 ) ) ;
V_147 -> V_96 = F_107 ( V_147 -> V_96 , V_173 ) ;
V_147 -> V_154 = V_147 -> V_150 <= V_100 ;
return true ;
}
static void F_108 ( struct V_146 * V_147 )
{
T_1 V_98 = V_147 -> V_174 ;
switch ( V_147 -> V_144 -> type ) {
case V_172 :
F_103 ( V_147 , V_98 ) ;
break;
case V_162 :
F_99 ( V_147 , V_98 ) ;
break;
#ifdef F_109
case V_149 :
F_92 ( V_147 , V_98 ) ;
break;
#endif
case V_175 :
default:
break;
}
V_147 -> V_176 = true ;
}
static void F_110 ( struct V_35 * V_90 , T_1 V_98 )
{
struct V_146 * V_147 = & V_90 -> V_147 ;
struct V_38 * V_144 ;
F_3 ( ! V_98 ) ;
F_3 ( V_98 > V_90 -> V_177 ) ;
F_3 ( F_72 ( & V_90 -> V_144 ) ) ;
V_147 -> V_178 = & V_90 -> V_144 ;
V_147 -> V_174 = V_98 ;
V_144 = F_73 ( & V_90 -> V_144 , struct V_38 , V_179 ) ;
V_147 -> V_144 = V_144 ;
F_108 ( V_147 ) ;
}
static struct V_96 * F_111 ( struct V_146 * V_147 ,
T_1 * V_97 , T_1 * V_98 ,
bool * V_154 )
{
struct V_96 * V_96 ;
switch ( V_147 -> V_144 -> type ) {
case V_172 :
V_96 = F_104 ( V_147 , V_97 , V_98 ) ;
break;
case V_162 :
V_96 = F_101 ( V_147 , V_97 , V_98 ) ;
break;
#ifdef F_109
case V_149 :
V_96 = F_95 ( V_147 , V_97 , V_98 ) ;
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
static bool F_112 ( struct V_146 * V_147 ,
T_1 V_159 )
{
bool V_180 ;
F_3 ( V_159 > V_147 -> V_150 ) ;
switch ( V_147 -> V_144 -> type ) {
case V_172 :
V_180 = F_105 ( V_147 , V_159 ) ;
break;
case V_162 :
V_180 = F_102 ( V_147 , V_159 ) ;
break;
#ifdef F_109
case V_149 :
V_180 = F_97 ( V_147 , V_159 ) ;
break;
#endif
case V_175 :
default:
F_113 () ;
break;
}
V_147 -> V_174 -= V_159 ;
if ( ! V_147 -> V_150 && V_147 -> V_174 ) {
F_37 ( ! V_147 -> V_154 ) ;
F_3 ( F_106 ( & V_147 -> V_144 -> V_179 , V_147 -> V_178 ) ) ;
V_147 -> V_144 = F_107 ( V_147 -> V_144 , V_179 ) ;
F_108 ( V_147 ) ;
V_180 = true ;
}
V_147 -> V_176 = V_180 ;
return V_180 ;
}
static void F_114 ( struct V_35 * V_90 , T_4 V_181 )
{
F_3 ( ! V_90 ) ;
F_3 ( ! V_181 ) ;
F_110 ( V_90 , ( T_1 ) V_181 ) ;
}
static void F_115 ( struct V_7 * V_8 )
{
struct V_35 * V_182 = V_8 -> V_120 ;
int V_183 = V_8 -> V_140 ;
V_182 -> V_184 . V_9 |= V_185 ;
F_39 ( L_27 , V_8 ) ;
V_8 -> V_186 = true ;
V_8 -> V_143 [ V_183 ] . V_107 = & V_182 -> V_184 ;
if ( V_8 -> V_187 & V_188 ) {
if ( V_8 -> V_75 -> V_189 )
V_8 -> V_75 -> V_189 ( V_8 , V_182 ) ;
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
static void F_116 ( struct V_7 * V_8 )
{
struct V_35 * V_182 ;
T_4 V_195 ;
F_89 ( V_8 ) ;
V_8 -> V_186 = true ;
V_8 -> V_194 = false ;
if ( V_8 -> V_121 > V_8 -> V_122 ) {
V_8 -> V_122 = V_8 -> V_121 ;
F_90 ( V_8 , sizeof ( V_196 ) , & V_196 ) ;
V_8 -> V_197 = F_80 ( V_8 -> V_122 ) ;
F_90 ( V_8 , sizeof ( V_8 -> V_197 ) ,
& V_8 -> V_197 ) ;
}
F_3 ( F_72 ( & V_8 -> V_115 ) ) ;
V_182 = F_73 ( & V_8 -> V_115 , struct V_35 , V_112 ) ;
V_8 -> V_120 = V_182 ;
F_3 ( V_182 -> V_8 != V_8 ) ;
F_117 ( V_182 ) ;
F_118 ( & V_182 -> V_112 , & V_8 -> V_116 ) ;
if ( V_182 -> V_198 ) {
V_182 -> V_199 . V_200 = F_80 ( ++ V_8 -> V_119 ) ;
V_182 -> V_198 = false ;
}
F_37 ( V_182 -> V_177 != F_119 ( V_182 -> V_199 . V_181 ) ) ;
F_39 ( L_28 ,
V_182 , V_8 -> V_119 , F_120 ( V_182 -> V_199 . type ) ,
F_119 ( V_182 -> V_199 . V_201 ) , F_119 ( V_182 -> V_199 . V_202 ) ,
V_182 -> V_177 ) ;
F_3 ( F_119 ( V_182 -> V_199 . V_201 ) != V_182 -> V_203 . V_108 ) ;
F_90 ( V_8 , sizeof ( V_204 ) , & V_204 ) ;
F_90 ( V_8 , sizeof ( V_182 -> V_199 ) , & V_182 -> V_199 ) ;
F_90 ( V_8 , V_182 -> V_203 . V_108 , V_182 -> V_203 . V_107 ) ;
if ( V_182 -> V_205 )
F_90 ( V_8 , V_182 -> V_205 -> V_206 . V_108 ,
V_182 -> V_205 -> V_206 . V_107 ) ;
V_195 = F_121 ( 0 , & V_182 -> V_199 , F_122 ( struct V_207 , V_195 ) ) ;
V_8 -> V_120 -> V_199 . V_195 = F_123 ( V_195 ) ;
V_8 -> V_120 -> V_184 . V_9 = 0 ;
V_195 = F_121 ( 0 , V_182 -> V_203 . V_107 , V_182 -> V_203 . V_108 ) ;
V_8 -> V_120 -> V_184 . V_208 = F_123 ( V_195 ) ;
if ( V_182 -> V_205 ) {
V_195 = F_121 ( 0 , V_182 -> V_205 -> V_206 . V_107 ,
V_182 -> V_205 -> V_206 . V_108 ) ;
V_8 -> V_120 -> V_184 . V_209 = F_123 ( V_195 ) ;
} else
V_8 -> V_120 -> V_184 . V_209 = 0 ;
F_39 ( L_29 , V_46 ,
F_119 ( V_8 -> V_120 -> V_184 . V_208 ) ,
F_119 ( V_8 -> V_120 -> V_184 . V_209 ) ) ;
V_8 -> V_120 -> V_184 . V_210 = 0 ;
if ( V_182 -> V_177 ) {
F_114 ( V_8 -> V_120 , V_182 -> V_177 ) ;
V_8 -> V_192 = 1 ;
} else {
F_115 ( V_8 ) ;
}
F_5 ( V_8 , V_4 ) ;
}
static void F_124 ( struct V_7 * V_8 )
{
F_39 ( L_30 , V_8 ,
V_8 -> V_122 , V_8 -> V_121 ) ;
V_8 -> V_122 = V_8 -> V_121 ;
F_89 ( V_8 ) ;
F_90 ( V_8 , sizeof ( V_196 ) , & V_196 ) ;
V_8 -> V_197 = F_80 ( V_8 -> V_122 ) ;
F_90 ( V_8 , sizeof ( V_8 -> V_197 ) ,
& V_8 -> V_197 ) ;
V_8 -> V_192 = 1 ;
F_5 ( V_8 , V_4 ) ;
}
static void F_125 ( struct V_7 * V_8 )
{
F_39 ( L_31 , V_8 ,
V_8 -> V_122 , V_8 -> V_121 ) ;
V_8 -> V_122 = V_8 -> V_121 ;
F_89 ( V_8 ) ;
V_8 -> V_197 = F_80 ( V_8 -> V_122 ) ;
F_90 ( V_8 , sizeof ( V_8 -> V_197 ) ,
& V_8 -> V_197 ) ;
F_5 ( V_8 , V_4 ) ;
}
static void F_126 ( struct V_7 * V_8 )
{
F_39 ( L_32 , V_8 ) ;
F_89 ( V_8 ) ;
F_90 ( V_8 , sizeof ( V_211 ) , & V_211 ) ;
F_5 ( V_8 , V_4 ) ;
}
static struct V_212 * F_127 ( struct V_7 * V_8 ,
int * V_213 )
{
struct V_212 * V_214 ;
if ( ! V_8 -> V_75 -> V_215 ) {
V_8 -> V_216 . V_217 = V_218 ;
V_8 -> V_216 . V_219 = 0 ;
return NULL ;
}
F_78 ( & V_8 -> V_123 ) ;
V_214 = V_8 -> V_75 -> V_215 ( V_8 , V_213 , V_8 -> V_220 ) ;
F_76 ( & V_8 -> V_123 ) ;
if ( F_128 ( V_214 ) )
return V_214 ;
if ( V_8 -> V_56 != V_221 )
return F_129 ( - V_95 ) ;
V_8 -> V_222 = V_214 -> V_223 ;
V_8 -> V_224 = V_214 -> V_225 ;
return V_214 ;
}
static void F_130 ( struct V_7 * V_8 )
{
F_90 ( V_8 , strlen ( V_226 ) , V_226 ) ;
F_90 ( V_8 , sizeof ( V_8 -> V_30 -> V_31 ) ,
& V_8 -> V_30 -> V_31 ) ;
V_8 -> V_192 = 0 ;
F_5 ( V_8 , V_4 ) ;
}
static int F_131 ( struct V_7 * V_8 )
{
unsigned int V_139 = F_86 ( V_8 -> V_30 , 0 ) ;
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
F_113 () ;
}
F_39 ( L_33 , V_8 ,
V_8 -> V_118 , V_139 , V_227 ) ;
V_8 -> V_216 . V_234 = F_80 ( V_8 -> V_30 -> V_235 ) ;
V_8 -> V_216 . V_236 = F_123 ( V_237 ) ;
V_8 -> V_216 . V_118 = F_123 ( V_8 -> V_118 ) ;
V_8 -> V_216 . V_139 = F_123 ( V_139 ) ;
V_8 -> V_216 . V_238 = F_123 ( V_227 ) ;
V_8 -> V_216 . V_9 = 0 ;
V_213 = V_218 ;
V_214 = F_127 ( V_8 , & V_213 ) ;
if ( F_128 ( V_214 ) )
return F_132 ( V_214 ) ;
V_8 -> V_216 . V_217 = F_123 ( V_213 ) ;
V_8 -> V_216 . V_219 = V_214 ?
F_123 ( V_214 -> V_239 ) : 0 ;
F_90 ( V_8 , sizeof ( V_8 -> V_216 ) ,
& V_8 -> V_216 ) ;
if ( V_214 && V_214 -> V_239 )
F_90 ( V_8 , V_214 -> V_239 ,
V_214 -> V_240 ) ;
V_8 -> V_192 = 0 ;
F_5 ( V_8 , V_4 ) ;
return 0 ;
}
static int F_133 ( struct V_7 * V_8 )
{
int V_68 ;
F_39 ( L_34 , V_8 , V_8 -> V_141 ) ;
while ( V_8 -> V_141 > 0 ) {
V_68 = F_61 ( V_8 -> V_50 , V_8 -> V_142 ,
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
F_39 ( L_35 , V_8 ,
V_8 -> V_141 , V_8 -> V_140 , V_68 ) ;
return V_68 ;
}
static T_4 F_134 ( T_4 V_195 , struct V_96 * V_96 ,
unsigned int V_97 ,
unsigned int V_98 )
{
char * V_99 ;
V_99 = F_60 ( V_96 ) ;
F_3 ( V_99 == NULL ) ;
V_195 = F_121 ( V_195 , V_99 + V_97 , V_98 ) ;
F_25 ( V_96 ) ;
return V_195 ;
}
static int F_135 ( struct V_7 * V_8 )
{
struct V_35 * V_90 = V_8 -> V_120 ;
struct V_146 * V_147 = & V_90 -> V_147 ;
bool V_242 = ! V_8 -> V_30 -> V_243 ;
T_4 V_195 ;
F_39 ( L_36 , V_46 , V_8 , V_90 ) ;
if ( F_72 ( & V_90 -> V_144 ) )
return - V_244 ;
V_195 = V_242 ? F_119 ( V_90 -> V_184 . V_210 ) : 0 ;
while ( V_147 -> V_150 ) {
struct V_96 * V_96 ;
T_1 V_97 ;
T_1 V_98 ;
bool V_154 ;
bool V_176 ;
int V_68 ;
V_96 = F_111 ( & V_90 -> V_147 , & V_97 , & V_98 ,
& V_154 ) ;
V_68 = F_65 ( V_8 -> V_50 , V_96 , V_97 ,
V_98 , V_154 ) ;
if ( V_68 <= 0 ) {
if ( V_242 )
V_90 -> V_184 . V_210 = F_123 ( V_195 ) ;
return V_68 ;
}
if ( V_242 && V_147 -> V_176 )
V_195 = F_134 ( V_195 , V_96 , V_97 , V_98 ) ;
V_176 = F_112 ( & V_90 -> V_147 , ( T_1 ) V_68 ) ;
}
F_39 ( L_37 , V_46 , V_8 , V_90 ) ;
if ( V_242 )
V_90 -> V_184 . V_210 = F_123 ( V_195 ) ;
else
V_90 -> V_184 . V_9 |= V_245 ;
F_89 ( V_8 ) ;
F_115 ( V_8 ) ;
return 1 ;
}
static int F_136 ( struct V_7 * V_8 )
{
int V_68 ;
while ( V_8 -> V_246 > 0 ) {
T_1 V_106 = F_93 ( V_8 -> V_246 , ( int ) V_247 ) ;
V_68 = F_65 ( V_8 -> V_50 , V_40 , 0 , V_106 , true ) ;
if ( V_68 <= 0 )
goto V_241;
V_8 -> V_246 -= V_68 ;
}
V_68 = 1 ;
V_241:
return V_68 ;
}
static void F_137 ( struct V_7 * V_8 )
{
F_39 ( L_38 , V_8 ) ;
V_8 -> V_248 = 0 ;
}
static void F_138 ( struct V_7 * V_8 )
{
F_39 ( L_39 , V_8 ) ;
V_8 -> V_248 = 0 ;
}
static void F_139 ( struct V_7 * V_8 )
{
F_39 ( L_40 , V_8 ) ;
V_8 -> V_248 = 0 ;
}
static void F_140 ( struct V_7 * V_8 )
{
F_39 ( L_41 , V_8 ) ;
V_8 -> V_248 = 0 ;
V_8 -> V_249 = V_250 ;
}
static void F_141 ( struct V_7 * V_8 )
{
F_39 ( L_42 , V_8 ) ;
V_8 -> V_248 = 0 ;
V_8 -> V_249 = V_251 ;
}
static int F_142 ( struct V_7 * V_8 )
{
F_39 ( L_43 , V_8 ) ;
F_3 ( V_8 -> V_117 != NULL ) ;
V_8 -> V_248 = 0 ;
V_8 -> V_252 = V_8 -> V_253 = V_8 -> V_254 = 0 ;
return 0 ;
}
static int F_143 ( struct V_7 * V_8 ,
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
static int F_144 ( struct V_7 * V_8 )
{
int V_106 ;
int V_255 ;
int V_68 ;
F_39 ( L_44 , V_8 , V_8 -> V_248 ) ;
V_106 = strlen ( V_226 ) ;
V_255 = V_106 ;
V_68 = F_143 ( V_8 , V_255 , V_106 , V_8 -> V_259 ) ;
if ( V_68 <= 0 )
goto V_241;
V_106 = sizeof ( V_8 -> V_260 ) ;
V_255 += V_106 ;
V_68 = F_143 ( V_8 , V_255 , V_106 , & V_8 -> V_260 ) ;
if ( V_68 <= 0 )
goto V_241;
V_106 = sizeof ( V_8 -> V_261 ) ;
V_255 += V_106 ;
V_68 = F_143 ( V_8 , V_255 , V_106 , & V_8 -> V_261 ) ;
if ( V_68 <= 0 )
goto V_241;
V_241:
return V_68 ;
}
static int F_145 ( struct V_7 * V_8 )
{
int V_106 ;
int V_255 ;
int V_68 ;
F_39 ( L_45 , V_8 , V_8 -> V_248 ) ;
V_106 = sizeof ( V_8 -> V_262 ) ;
V_255 = V_106 ;
V_68 = F_143 ( V_8 , V_255 , V_106 , & V_8 -> V_262 ) ;
if ( V_68 <= 0 )
goto V_241;
V_106 = F_119 ( V_8 -> V_262 . V_219 ) ;
V_255 += V_106 ;
V_68 = F_143 ( V_8 , V_255 , V_106 , V_8 -> V_222 ) ;
if ( V_68 <= 0 )
goto V_241;
F_39 ( L_46 ,
V_8 , ( int ) V_8 -> V_262 . V_263 ,
F_119 ( V_8 -> V_262 . V_118 ) ,
F_119 ( V_8 -> V_262 . V_139 ) ) ;
V_241:
return V_68 ;
}
static int F_146 ( struct V_7 * V_8 )
{
if ( memcmp ( V_8 -> V_259 , V_226 , strlen ( V_226 ) ) ) {
F_31 ( L_47 ,
F_13 ( & V_8 -> V_66 . V_67 ) ) ;
V_8 -> V_80 = L_48 ;
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
static int F_151 ( const char * V_267 , T_1 V_86 , struct V_10 * V_11 ,
char V_268 , const char * * V_269 )
{
struct V_14 * V_15 = (struct V_14 * ) V_11 ;
struct V_16 * V_17 = (struct V_16 * ) V_11 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
if ( F_152 ( V_267 , V_86 , ( V_270 * ) & V_15 -> V_24 . V_264 , V_268 , V_269 ) ) {
V_11 -> V_21 = V_22 ;
return 0 ;
}
if ( F_153 ( V_267 , V_86 , ( V_270 * ) & V_17 -> V_27 . V_271 , V_268 , V_269 ) ) {
V_11 -> V_21 = V_26 ;
return 0 ;
}
return - V_244 ;
}
static int F_154 ( const char * V_272 , T_1 V_273 ,
struct V_10 * V_11 , char V_268 , const char * * V_269 )
{
const char * V_255 , * V_274 ;
char * V_275 , * V_276 = NULL ;
int V_277 , V_68 ;
V_274 = memchr ( V_272 , V_268 , V_273 ) ;
V_275 = memchr ( V_272 , ':' , V_273 ) ;
if ( V_274 && V_275 )
V_255 = V_274 < V_275 ? V_274 : V_275 ;
else if ( ! V_274 && V_275 )
V_255 = V_275 ;
else {
V_255 = V_274 ;
if ( ! V_255 )
V_255 = V_272 + V_273 ;
}
if ( V_255 <= V_272 )
return - V_244 ;
V_277 = F_155 ( NULL , V_272 , V_255 - V_272 , NULL , & V_276 , NULL ) ;
if ( V_277 > 0 )
V_68 = F_151 ( V_276 , V_277 , V_11 , - 1 , NULL ) ;
else
V_68 = - V_278 ;
F_156 ( V_276 ) ;
* V_269 = V_255 ;
F_157 ( L_49 , ( int ) ( V_255 - V_272 ) , V_272 ,
V_68 , V_68 ? L_50 : F_13 ( V_11 ) ) ;
return V_68 ;
}
static inline int F_154 ( const char * V_272 , T_1 V_273 ,
struct V_10 * V_11 , char V_268 , const char * * V_269 )
{
return - V_244 ;
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
int F_159 ( const char * V_279 , const char * V_255 ,
struct V_128 * V_33 ,
int V_280 , int * V_281 )
{
int V_12 , V_68 = - V_244 ;
const char * V_266 = V_279 ;
F_39 ( L_51 , ( int ) ( V_255 - V_279 ) , V_279 ) ;
for ( V_12 = 0 ; V_12 < V_280 ; V_12 ++ ) {
const char * V_269 ;
struct V_10 * V_11 = & V_33 [ V_12 ] . V_67 ;
int V_282 ;
char V_268 = ',' ;
if ( * V_266 == '[' ) {
V_268 = ']' ;
V_266 ++ ;
}
V_68 = F_158 ( V_266 , V_255 - V_266 , V_11 , V_268 , & V_269 ) ;
if ( V_68 )
goto V_283;
V_68 = - V_244 ;
V_266 = V_269 ;
if ( V_268 == ']' ) {
if ( * V_266 != ']' ) {
F_39 ( L_52 ) ;
goto V_283;
}
V_266 ++ ;
}
if ( V_266 < V_255 && * V_266 == ':' ) {
V_282 = 0 ;
V_266 ++ ;
while ( V_266 < V_255 && * V_266 >= '0' && * V_266 <= '9' ) {
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
F_39 ( L_53 , F_13 ( V_11 ) ) ;
if ( V_266 == V_255 )
break;
if ( * V_266 != ',' )
goto V_283;
V_266 ++ ;
}
if ( V_266 != V_255 )
goto V_283;
if ( V_281 )
* V_281 = V_12 + 1 ;
return 0 ;
V_283:
F_31 ( L_54 , ( int ) ( V_255 - V_279 ) , V_279 ) ;
return V_68 ;
}
static int F_160 ( struct V_7 * V_8 )
{
F_39 ( L_55 , V_8 ) ;
if ( F_146 ( V_8 ) < 0 )
return - 1 ;
F_161 ( & V_8 -> V_260 ) ;
F_161 ( & V_8 -> V_261 ) ;
if ( memcmp ( & V_8 -> V_66 , & V_8 -> V_260 ,
sizeof( V_8 -> V_66 ) ) != 0 &&
! ( F_147 ( & V_8 -> V_260 . V_67 ) &&
V_8 -> V_260 . V_285 == V_8 -> V_66 . V_285 ) ) {
F_162 ( L_56 ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
( int ) F_119 ( V_8 -> V_66 . V_285 ) ,
F_13 ( & V_8 -> V_260 . V_67 ) ,
( int ) F_119 ( V_8 -> V_260 . V_285 ) ) ;
V_8 -> V_80 = L_57 ;
return - 1 ;
}
if ( F_147 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ) ) {
int V_282 = F_148 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ) ;
memcpy ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ,
& V_8 -> V_261 . V_67 ,
sizeof( V_8 -> V_261 . V_67 ) ) ;
F_149 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 , V_282 ) ;
F_16 ( V_8 -> V_30 ) ;
F_39 ( L_58 ,
F_13 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ) ) ;
}
return 0 ;
}
static int F_163 ( struct V_7 * V_8 )
{
V_165 V_286 = V_8 -> V_30 -> V_235 ;
V_165 V_287 = V_8 -> V_30 -> V_288 ;
V_165 V_289 = F_164 (
F_165 ( V_8 -> V_262 . V_234 ) ) ;
int V_68 ;
F_39 ( L_59 , V_8 , ( int ) V_8 -> V_249 ) ;
switch ( V_8 -> V_262 . V_263 ) {
case V_290 :
F_31 ( L_60
L_61 ,
F_166 ( V_8 -> V_130 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_286 , V_289 , V_289 & ~ V_286 ) ;
V_8 -> V_80 = L_62 ;
F_74 ( V_8 ) ;
return - 1 ;
case V_291 :
F_31 ( L_63
L_64 ,
F_166 ( V_8 -> V_130 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
F_119 ( V_8 -> V_216 . V_238 ) ,
F_119 ( V_8 -> V_262 . V_238 ) ) ;
V_8 -> V_80 = L_65 ;
F_74 ( V_8 ) ;
return - 1 ;
case V_292 :
V_8 -> V_220 ++ ;
F_39 ( L_66 , V_8 ,
V_8 -> V_220 ) ;
if ( V_8 -> V_220 == 2 ) {
V_8 -> V_80 = L_67 ;
return - 1 ;
}
F_89 ( V_8 ) ;
V_68 = F_131 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_138 ( V_8 ) ;
break;
case V_293 :
F_39 ( L_68 ,
F_119 ( V_8 -> V_262 . V_118 ) ) ;
F_31 ( L_69 ,
F_166 ( V_8 -> V_130 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ) ;
F_74 ( V_8 ) ;
F_89 ( V_8 ) ;
V_68 = F_131 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_138 ( V_8 ) ;
F_78 ( & V_8 -> V_123 ) ;
F_157 ( L_70 , F_166 ( V_8 -> V_130 ) ) ;
if ( V_8 -> V_75 -> V_294 )
V_8 -> V_75 -> V_294 ( V_8 ) ;
F_76 ( & V_8 -> V_123 ) ;
if ( V_8 -> V_56 != V_221 )
return - V_95 ;
break;
case V_295 :
F_39 ( L_71 ,
F_119 ( V_8 -> V_216 . V_118 ) ,
F_119 ( V_8 -> V_262 . V_118 ) ) ;
V_8 -> V_118 = F_119 ( V_8 -> V_262 . V_118 ) ;
F_89 ( V_8 ) ;
V_68 = F_131 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_138 ( V_8 ) ;
break;
case V_296 :
F_39 ( L_72 ,
V_8 -> V_125 ,
F_119 ( V_8 -> V_262 . V_139 ) ) ;
F_86 ( V_8 -> V_30 ,
F_119 ( V_8 -> V_262 . V_139 ) ) ;
F_89 ( V_8 ) ;
V_68 = F_131 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_138 ( V_8 ) ;
break;
case V_250 :
case V_251 :
if ( V_287 & ~ V_289 ) {
F_31 ( L_73
L_74 ,
F_166 ( V_8 -> V_130 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_287 , V_289 , V_287 & ~ V_289 ) ;
V_8 -> V_80 = L_62 ;
F_74 ( V_8 ) ;
return - 1 ;
}
F_37 ( V_8 -> V_56 != V_221 ) ;
V_8 -> V_56 = V_297 ;
V_8 -> V_220 = 0 ;
V_8 -> V_125 = F_119 ( V_8 -> V_262 . V_139 ) ;
V_8 -> V_118 ++ ;
V_8 -> V_187 = V_289 ;
F_39 ( L_75 ,
V_8 -> V_125 ,
F_119 ( V_8 -> V_262 . V_118 ) ,
V_8 -> V_118 ) ;
F_37 ( V_8 -> V_118 !=
F_119 ( V_8 -> V_262 . V_118 ) ) ;
if ( V_8 -> V_262 . V_9 & V_298 )
F_5 ( V_8 , V_2 ) ;
V_8 -> V_132 = 0 ;
if ( V_8 -> V_262 . V_263 == V_250 ) {
F_125 ( V_8 ) ;
F_140 ( V_8 ) ;
} else {
F_141 ( V_8 ) ;
}
break;
case V_299 :
F_31 ( L_76 ) ;
V_8 -> V_80 = L_77 ;
return - 1 ;
default:
F_31 ( L_78 ) ;
V_8 -> V_80 = L_79 ;
return - 1 ;
}
return 0 ;
}
static int F_167 ( struct V_7 * V_8 )
{
int V_106 = sizeof ( V_8 -> V_300 ) ;
int V_255 = V_106 ;
return F_143 ( V_8 , V_255 , V_106 , & V_8 -> V_300 ) ;
}
static void F_168 ( struct V_7 * V_8 )
{
struct V_35 * V_182 ;
V_165 V_301 = F_165 ( V_8 -> V_300 ) ;
V_165 V_200 ;
while ( ! F_72 ( & V_8 -> V_116 ) ) {
V_182 = F_73 ( & V_8 -> V_116 , struct V_35 ,
V_112 ) ;
V_200 = F_165 ( V_182 -> V_199 . V_200 ) ;
if ( V_200 > V_301 )
break;
F_39 ( L_80 , V_200 ,
F_120 ( V_182 -> V_199 . type ) , V_182 ) ;
V_182 -> V_302 = V_303 ;
F_68 ( V_182 ) ;
}
F_141 ( V_8 ) ;
}
static int F_169 ( struct V_7 * V_8 ,
struct V_87 * V_304 ,
unsigned int V_305 , T_4 * V_195 )
{
int V_68 , V_257 ;
F_3 ( ! V_304 ) ;
while ( V_304 -> V_108 < V_305 ) {
F_3 ( V_304 -> V_107 == NULL ) ;
V_257 = V_305 - V_304 -> V_108 ;
V_68 = F_57 ( V_8 -> V_50 , ( char * ) V_304 -> V_107 +
V_304 -> V_108 , V_257 ) ;
if ( V_68 <= 0 )
return V_68 ;
V_304 -> V_108 += V_68 ;
}
if ( V_304 -> V_108 == V_305 )
* V_195 = F_121 ( 0 , V_304 -> V_107 , V_304 -> V_108 ) ;
return 1 ;
}
static int F_170 ( struct V_7 * V_8 )
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
if ( F_72 ( & V_90 -> V_144 ) )
return - V_306 ;
if ( V_242 )
V_195 = V_8 -> V_254 ;
while ( V_147 -> V_150 ) {
V_96 = F_111 ( & V_90 -> V_147 , & V_97 , & V_98 ,
NULL ) ;
V_68 = F_59 ( V_8 -> V_50 , V_96 , V_97 , V_98 ) ;
if ( V_68 <= 0 ) {
if ( V_242 )
V_8 -> V_254 = V_195 ;
return V_68 ;
}
if ( V_242 )
V_195 = F_134 ( V_195 , V_96 , V_97 , V_68 ) ;
( void ) F_112 ( & V_90 -> V_147 , ( T_1 ) V_68 ) ;
}
if ( V_242 )
V_8 -> V_254 = V_195 ;
return 1 ;
}
static int F_171 ( struct V_7 * V_8 )
{
struct V_35 * V_182 = V_8 -> V_117 ;
int V_106 ;
int V_255 ;
int V_68 ;
unsigned int V_201 , V_202 , V_181 ;
bool V_242 = ! V_8 -> V_30 -> V_243 ;
bool V_307 = ( V_8 -> V_187 & V_188 ) ;
V_165 V_200 ;
T_4 V_195 ;
F_39 ( L_81 , V_8 , V_182 ) ;
V_106 = sizeof ( V_8 -> V_308 ) ;
V_255 = V_106 ;
V_68 = F_143 ( V_8 , V_255 , V_106 , & V_8 -> V_308 ) ;
if ( V_68 <= 0 )
return V_68 ;
V_195 = F_121 ( 0 , & V_8 -> V_308 , F_122 ( struct V_207 , V_195 ) ) ;
if ( F_123 ( V_195 ) != V_8 -> V_308 . V_195 ) {
F_31 ( L_82
L_83 ,
V_195 , V_8 -> V_308 . V_195 ) ;
return - V_309 ;
}
V_201 = F_119 ( V_8 -> V_308 . V_201 ) ;
if ( V_201 > V_310 )
return - V_306 ;
V_202 = F_119 ( V_8 -> V_308 . V_202 ) ;
if ( V_202 > V_311 )
return - V_306 ;
V_181 = F_119 ( V_8 -> V_308 . V_181 ) ;
if ( V_181 > V_312 )
return - V_306 ;
V_200 = F_165 ( V_8 -> V_308 . V_200 ) ;
if ( ( V_313 ) V_200 - ( V_313 ) V_8 -> V_121 < 1 ) {
F_157 ( L_84 ,
F_166 ( V_8 -> V_130 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_200 , V_8 -> V_121 + 1 ) ;
V_8 -> V_248 = - V_201 - V_202 - V_181 -
sizeof( V_182 -> V_184 ) ;
V_8 -> V_249 = V_251 ;
return 0 ;
} else if ( ( V_313 ) V_200 - ( V_313 ) V_8 -> V_121 > 1 ) {
F_31 ( L_85 ,
V_200 , V_8 -> V_121 + 1 ) ;
V_8 -> V_80 = L_86 ;
return - V_309 ;
}
if ( ! V_8 -> V_117 ) {
int V_314 = 0 ;
F_39 ( L_87 , V_8 -> V_308 . type ,
V_201 , V_181 ) ;
V_68 = F_172 ( V_8 , & V_314 ) ;
if ( V_68 < 0 )
return V_68 ;
F_3 ( ! V_8 -> V_117 ^ V_314 ) ;
if ( V_8 -> V_117 && V_181 > V_8 -> V_117 -> V_177 ) {
F_162 ( L_88 ,
V_46 , V_181 , V_8 -> V_117 -> V_177 ) ;
F_70 ( V_8 -> V_117 ) ;
V_8 -> V_117 = NULL ;
V_314 = 1 ;
}
if ( V_314 ) {
F_39 ( L_89 ) ;
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
F_114 ( V_8 -> V_117 , V_181 ) ;
}
V_68 = F_169 ( V_8 , & V_182 -> V_203 , V_201 ,
& V_8 -> V_252 ) ;
if ( V_68 <= 0 )
return V_68 ;
if ( V_182 -> V_205 ) {
V_68 = F_169 ( V_8 , & V_182 -> V_205 -> V_206 ,
V_202 ,
& V_8 -> V_253 ) ;
if ( V_68 <= 0 )
return V_68 ;
}
if ( V_181 ) {
V_68 = F_170 ( V_8 ) ;
if ( V_68 <= 0 )
return V_68 ;
}
if ( V_307 )
V_106 = sizeof( V_182 -> V_184 ) ;
else
V_106 = sizeof( V_182 -> V_191 ) ;
V_255 += V_106 ;
V_68 = F_143 ( V_8 , V_255 , V_106 , & V_182 -> V_184 ) ;
if ( V_68 <= 0 )
return V_68 ;
if ( ! V_307 ) {
V_182 -> V_184 . V_9 = V_182 -> V_191 . V_9 ;
V_182 -> V_184 . V_190 = 0 ;
}
F_39 ( L_90 ,
V_182 , V_201 , V_182 -> V_184 . V_208 , V_202 ,
V_182 -> V_184 . V_209 , V_181 , V_182 -> V_184 . V_210 ) ;
if ( V_8 -> V_252 != F_119 ( V_182 -> V_184 . V_208 ) ) {
F_31 ( L_91 ,
V_182 , V_8 -> V_252 , V_182 -> V_184 . V_208 ) ;
return - V_309 ;
}
if ( V_8 -> V_253 != F_119 ( V_182 -> V_184 . V_209 ) ) {
F_31 ( L_92 ,
V_182 , V_8 -> V_253 , V_182 -> V_184 . V_209 ) ;
return - V_309 ;
}
if ( V_242 &&
( V_182 -> V_184 . V_9 & V_245 ) == 0 &&
V_8 -> V_254 != F_119 ( V_182 -> V_184 . V_210 ) ) {
F_31 ( L_93 , V_182 ,
V_8 -> V_254 , F_119 ( V_182 -> V_184 . V_210 ) ) ;
return - V_309 ;
}
if ( V_307 && V_8 -> V_75 -> V_315 &&
V_8 -> V_75 -> V_315 ( V_8 , V_182 ) ) {
F_31 ( L_94 , V_182 ) ;
return - V_309 ;
}
return 1 ;
}
static void F_173 ( struct V_7 * V_8 )
{
struct V_35 * V_90 ;
F_3 ( V_8 -> V_117 -> V_8 != V_8 ) ;
V_8 -> V_117 -> V_8 = NULL ;
V_90 = V_8 -> V_117 ;
V_8 -> V_117 = NULL ;
V_8 -> V_75 -> V_113 ( V_8 ) ;
if ( V_8 -> V_130 . type == 0 )
V_8 -> V_130 = V_90 -> V_199 . V_316 ;
V_8 -> V_121 ++ ;
F_78 ( & V_8 -> V_123 ) ;
F_39 ( L_95 ,
V_90 , F_165 ( V_90 -> V_199 . V_200 ) ,
F_166 ( V_90 -> V_199 . V_316 ) ,
F_120 ( V_90 -> V_199 . type ) ,
F_174 ( F_120 ( V_90 -> V_199 . type ) ) ,
F_119 ( V_90 -> V_199 . V_201 ) ,
F_119 ( V_90 -> V_199 . V_181 ) ,
V_8 -> V_252 , V_8 -> V_253 , V_8 -> V_254 ) ;
V_8 -> V_75 -> V_317 ( V_8 , V_90 ) ;
F_76 ( & V_8 -> V_123 ) ;
}
static int F_175 ( struct V_7 * V_8 )
{
int V_68 = 1 ;
F_39 ( L_96 , V_8 , V_8 -> V_56 ) ;
V_102:
F_39 ( L_97 , V_8 -> V_141 ) ;
if ( V_8 -> V_56 == V_129 ) {
F_3 ( V_8 -> V_50 ) ;
V_8 -> V_56 = V_318 ;
F_89 ( V_8 ) ;
F_130 ( V_8 ) ;
F_137 ( V_8 ) ;
F_3 ( V_8 -> V_117 ) ;
V_8 -> V_249 = V_251 ;
F_39 ( L_98 ,
V_8 , V_8 -> V_56 ) ;
V_68 = F_51 ( V_8 ) ;
if ( V_68 < 0 ) {
V_8 -> V_80 = L_20 ;
goto V_241;
}
}
V_319:
if ( V_8 -> V_246 ) {
V_68 = F_136 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_241;
}
if ( V_8 -> V_140 ) {
V_68 = F_133 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_241;
}
if ( V_8 -> V_120 ) {
if ( V_8 -> V_194 ) {
F_70 ( V_8 -> V_120 ) ;
V_8 -> V_120 = NULL ;
goto V_320;
}
V_68 = F_135 ( V_8 ) ;
if ( V_68 == 1 )
goto V_319;
if ( V_68 == 0 )
goto V_241;
if ( V_68 < 0 ) {
F_39 ( L_99 ,
V_68 ) ;
goto V_241;
}
}
V_320:
if ( V_8 -> V_56 == V_297 ) {
if ( ! F_72 ( & V_8 -> V_115 ) ) {
F_116 ( V_8 ) ;
goto V_102;
}
if ( V_8 -> V_121 > V_8 -> V_122 ) {
F_124 ( V_8 ) ;
goto V_102;
}
if ( F_9 ( V_8 , V_3 ) ) {
F_126 ( V_8 ) ;
goto V_102;
}
}
F_2 ( V_8 , V_4 ) ;
F_39 ( L_100 ) ;
V_68 = 0 ;
V_241:
F_39 ( L_101 , V_8 , V_68 ) ;
return V_68 ;
}
static int F_176 ( struct V_7 * V_8 )
{
int V_68 = - 1 ;
V_102:
F_39 ( L_102 , V_8 , V_8 -> V_56 ) ;
if ( V_8 -> V_56 != V_318 &&
V_8 -> V_56 != V_221 &&
V_8 -> V_56 != V_297 )
return 0 ;
F_3 ( ! V_8 -> V_50 ) ;
F_39 ( L_103 , ( int ) V_8 -> V_249 ,
V_8 -> V_248 ) ;
if ( V_8 -> V_56 == V_318 ) {
F_39 ( L_104 ) ;
V_68 = F_144 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_241;
V_68 = F_160 ( V_8 ) ;
if ( V_68 < 0 )
goto V_241;
V_8 -> V_56 = V_221 ;
V_68 = F_131 ( V_8 ) ;
if ( V_68 < 0 )
goto V_241;
F_138 ( V_8 ) ;
goto V_241;
}
if ( V_8 -> V_56 == V_221 ) {
F_39 ( L_105 ) ;
V_68 = F_145 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_241;
V_68 = F_163 ( V_8 ) ;
if ( V_68 < 0 )
goto V_241;
goto V_102;
}
F_37 ( V_8 -> V_56 != V_297 ) ;
if ( V_8 -> V_248 < 0 ) {
static char V_85 [ V_321 ] ;
int V_314 = F_93 ( ( int ) sizeof ( V_85 ) , - V_8 -> V_248 ) ;
F_39 ( L_106 , V_314 , - V_8 -> V_248 ) ;
V_68 = F_57 ( V_8 -> V_50 , V_85 , V_314 ) ;
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
F_39 ( L_107 , ( int ) V_8 -> V_249 ) ;
switch ( V_8 -> V_249 ) {
case V_322 :
F_142 ( V_8 ) ;
break;
case V_323 :
F_139 ( V_8 ) ;
break;
case V_324 :
F_67 ( V_8 ) ;
V_8 -> V_56 = V_124 ;
goto V_241;
default:
goto V_325;
}
}
if ( V_8 -> V_249 == V_322 ) {
V_68 = F_171 ( V_8 ) ;
if ( V_68 <= 0 ) {
switch ( V_68 ) {
case - V_309 :
V_8 -> V_80 = L_108 ;
V_68 = - V_306 ;
break;
case - V_306 :
V_8 -> V_80 = L_109 ;
break;
}
goto V_241;
}
if ( V_8 -> V_249 == V_251 )
goto V_102;
F_173 ( V_8 ) ;
if ( V_8 -> V_56 == V_297 )
F_141 ( V_8 ) ;
goto V_102;
}
if ( V_8 -> V_249 == V_323 ||
V_8 -> V_249 == V_250 ) {
V_68 = F_167 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_241;
F_168 ( V_8 ) ;
goto V_102;
}
V_241:
F_39 ( L_110 , V_8 , V_68 ) ;
return V_68 ;
V_325:
F_31 ( L_111 , ( int ) V_8 -> V_249 ) ;
V_8 -> V_80 = L_112 ;
V_68 = - 1 ;
goto V_241;
}
static int F_177 ( struct V_7 * V_8 , unsigned long V_132 )
{
if ( ! V_8 -> V_75 -> V_326 ( V_8 ) ) {
F_39 ( L_113 , V_46 , V_8 ) ;
return - V_327 ;
}
if ( ! F_178 ( V_39 , & V_8 -> V_135 , V_132 ) ) {
F_39 ( L_114 , V_46 , V_8 ) ;
V_8 -> V_75 -> V_113 ( V_8 ) ;
return - V_328 ;
}
F_39 ( L_115 , V_46 , V_8 , V_132 ) ;
return 0 ;
}
static void F_46 ( struct V_7 * V_8 )
{
( void ) F_177 ( V_8 , 0 ) ;
}
static void F_77 ( struct V_7 * V_8 )
{
if ( F_179 ( & V_8 -> V_135 ) ) {
F_39 ( L_116 , V_46 , V_8 ) ;
V_8 -> V_75 -> V_113 ( V_8 ) ;
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
CASE ( V_329 ) ;
CASE ( V_330 ) ;
CASE ( V_331 ) ;
CASE ( V_332 ) ;
CASE ( V_333 ) ;
CASE ( V_334 ) ;
default:
F_162 ( L_117 ,
V_46 , V_8 , V_8 -> V_56 ) ;
V_8 -> V_80 = L_118 ;
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
V_68 = F_177 ( V_8 , F_182 ( V_8 -> V_132 ) ) ;
if ( V_68 ) {
F_39 ( L_119 , V_46 ,
V_8 , V_8 -> V_132 ) ;
F_3 ( V_68 == - V_327 ) ;
F_5 ( V_8 , V_6 ) ;
}
return true ;
}
static void F_183 ( struct V_7 * V_8 )
{
if ( V_8 -> V_220 && V_8 -> V_75 -> V_335 ) {
F_39 ( L_120 ) ;
V_8 -> V_75 -> V_335 ( V_8 ) ;
}
if ( V_8 -> V_75 -> V_336 )
V_8 -> V_75 -> V_336 ( V_8 ) ;
}
static void V_136 ( struct V_337 * V_135 )
{
struct V_7 * V_8 = F_184 ( V_135 , struct V_7 ,
V_135 . V_135 ) ;
bool V_336 ;
F_76 ( & V_8 -> V_123 ) ;
while ( true ) {
int V_68 ;
if ( ( V_336 = F_180 ( V_8 ) ) ) {
F_39 ( L_121 , V_46 , V_8 ) ;
break;
}
if ( F_181 ( V_8 ) ) {
F_39 ( L_122 , V_46 , V_8 ) ;
break;
}
if ( V_8 -> V_56 == V_338 ) {
F_39 ( L_123 , V_46 , V_8 ) ;
break;
}
if ( V_8 -> V_56 == V_124 ) {
F_39 ( L_124 , V_46 , V_8 ) ;
F_3 ( V_8 -> V_50 ) ;
break;
}
if ( V_8 -> V_56 == V_129 ) {
F_39 ( L_125 , V_46 , V_8 ) ;
F_3 ( V_8 -> V_50 ) ;
}
V_68 = F_176 ( V_8 ) ;
if ( V_68 < 0 ) {
if ( V_68 == - V_95 )
continue;
V_8 -> V_80 = L_126 ;
V_336 = true ;
break;
}
V_68 = F_175 ( V_8 ) ;
if ( V_68 < 0 ) {
if ( V_68 == - V_95 )
continue;
V_8 -> V_80 = L_127 ;
V_336 = true ;
}
break;
}
if ( V_336 )
F_185 ( V_8 ) ;
F_78 ( & V_8 -> V_123 ) ;
if ( V_336 )
F_183 ( V_8 ) ;
V_8 -> V_75 -> V_113 ( V_8 ) ;
}
static void F_185 ( struct V_7 * V_8 )
{
F_162 ( L_128 , F_166 ( V_8 -> V_130 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) , V_8 -> V_80 ) ;
F_39 ( L_129 ,
V_8 , V_8 -> V_56 , F_13 ( & V_8 -> V_66 . V_67 ) ) ;
F_37 ( V_8 -> V_56 != V_318 &&
V_8 -> V_56 != V_221 &&
V_8 -> V_56 != V_297 ) ;
F_67 ( V_8 ) ;
if ( F_7 ( V_8 , V_2 ) ) {
F_39 ( L_130 ) ;
V_8 -> V_56 = V_124 ;
return;
}
if ( V_8 -> V_117 ) {
F_3 ( V_8 -> V_117 -> V_8 != V_8 ) ;
V_8 -> V_117 -> V_8 = NULL ;
F_70 ( V_8 -> V_117 ) ;
V_8 -> V_117 = NULL ;
V_8 -> V_75 -> V_113 ( V_8 ) ;
}
F_186 ( & V_8 -> V_116 , & V_8 -> V_115 ) ;
if ( F_72 ( & V_8 -> V_115 ) &&
! F_7 ( V_8 , V_3 ) ) {
F_39 ( L_131 , V_8 ) ;
F_2 ( V_8 , V_4 ) ;
V_8 -> V_56 = V_338 ;
} else {
V_8 -> V_56 = V_129 ;
if ( V_8 -> V_132 == 0 )
V_8 -> V_132 = V_339 ;
else if ( V_8 -> V_132 < V_340 )
V_8 -> V_132 *= 2 ;
F_5 ( V_8 , V_6 ) ;
F_46 ( V_8 ) ;
}
}
void F_187 ( struct V_29 * V_30 ,
struct V_128 * V_341 ,
V_165 V_235 ,
V_165 V_288 ,
bool V_243 ,
bool V_81 )
{
V_30 -> V_235 = V_235 ;
V_30 -> V_288 = V_288 ;
F_188 ( & V_30 -> V_138 ) ;
if ( V_341 )
V_30 -> V_32 . V_33 = * V_341 ;
V_30 -> V_32 . V_33 . type = 0 ;
F_189 ( & V_30 -> V_32 . V_33 . V_285 , sizeof( V_30 -> V_32 . V_33 . V_285 ) ) ;
F_16 ( V_30 ) ;
V_30 -> V_243 = V_243 ;
V_30 -> V_81 = V_81 ;
F_190 ( & V_30 -> V_53 , 0 ) ;
F_39 ( L_116 , V_46 , V_30 ) ;
}
static void F_191 ( struct V_7 * V_8 )
{
if ( V_8 -> V_56 == V_338 ) {
F_39 ( L_132 , V_8 ) ;
V_8 -> V_56 = V_129 ;
V_8 -> V_118 ++ ;
F_37 ( F_7 ( V_8 , V_4 ) ) ;
F_37 ( F_7 ( V_8 , V_3 ) ) ;
}
}
void F_192 ( struct V_7 * V_8 , struct V_35 * V_90 )
{
V_90 -> V_199 . V_316 = V_8 -> V_30 -> V_32 . V_272 ;
F_3 ( V_90 -> V_203 . V_108 != F_119 ( V_90 -> V_199 . V_201 ) ) ;
V_90 -> V_198 = true ;
F_76 ( & V_8 -> V_123 ) ;
if ( V_8 -> V_56 == V_124 ) {
F_39 ( L_133 , V_8 , V_90 ) ;
F_70 ( V_90 ) ;
F_78 ( & V_8 -> V_123 ) ;
return;
}
F_3 ( V_90 -> V_8 != NULL ) ;
V_90 -> V_8 = V_8 -> V_75 -> V_326 ( V_8 ) ;
F_3 ( V_90 -> V_8 == NULL ) ;
F_3 ( ! F_72 ( & V_90 -> V_112 ) ) ;
F_193 ( & V_90 -> V_112 , & V_8 -> V_115 ) ;
F_39 ( L_134 , V_90 ,
F_166 ( V_8 -> V_130 ) , F_120 ( V_90 -> V_199 . type ) ,
F_174 ( F_120 ( V_90 -> V_199 . type ) ) ,
F_119 ( V_90 -> V_199 . V_201 ) ,
F_119 ( V_90 -> V_199 . V_202 ) ,
F_119 ( V_90 -> V_199 . V_181 ) ) ;
F_191 ( V_8 ) ;
F_78 ( & V_8 -> V_123 ) ;
if ( F_11 ( V_8 , V_4 ) == 0 )
F_46 ( V_8 ) ;
}
void F_194 ( struct V_35 * V_90 )
{
struct V_7 * V_8 = V_90 -> V_8 ;
if ( ! V_8 )
return;
F_76 ( & V_8 -> V_123 ) ;
if ( ! F_72 ( & V_90 -> V_112 ) ) {
F_39 ( L_135 , V_46 , V_8 , V_90 ) ;
F_69 ( & V_90 -> V_112 ) ;
F_3 ( V_90 -> V_8 == NULL ) ;
V_90 -> V_8 -> V_75 -> V_113 ( V_90 -> V_8 ) ;
V_90 -> V_8 = NULL ;
V_90 -> V_199 . V_200 = 0 ;
F_70 ( V_90 ) ;
}
if ( V_8 -> V_120 == V_90 ) {
F_39 ( L_136 , V_46 , V_8 , V_90 ) ;
V_8 -> V_120 = NULL ;
if ( V_8 -> V_186 ) {
V_8 -> V_246 = V_8 -> V_141 ;
V_8 -> V_186 = false ;
}
V_90 -> V_199 . V_200 = 0 ;
F_70 ( V_90 ) ;
}
F_78 ( & V_8 -> V_123 ) ;
}
void F_195 ( struct V_35 * V_90 )
{
struct V_7 * V_8 ;
F_3 ( V_90 == NULL ) ;
if ( ! V_90 -> V_8 ) {
F_39 ( L_137 , V_46 , V_90 ) ;
return;
}
V_8 = V_90 -> V_8 ;
F_76 ( & V_8 -> V_123 ) ;
if ( V_8 -> V_117 == V_90 ) {
unsigned int V_201 = F_119 ( V_8 -> V_308 . V_201 ) ;
unsigned int V_202 = F_119 ( V_8 -> V_308 . V_202 ) ;
unsigned int V_181 = F_119 ( V_8 -> V_308 . V_181 ) ;
F_39 ( L_138 , V_46 , V_8 , V_90 ) ;
V_8 -> V_248 = V_8 -> V_248 -
sizeof( struct V_207 ) -
V_201 -
V_202 -
V_181 -
sizeof( struct V_342 ) ;
F_70 ( V_8 -> V_117 ) ;
V_8 -> V_117 = NULL ;
V_8 -> V_249 = V_251 ;
V_8 -> V_121 ++ ;
} else {
F_39 ( L_139 ,
V_46 , V_8 , V_8 -> V_117 , V_90 ) ;
}
F_78 ( & V_8 -> V_123 ) ;
}
void F_196 ( struct V_7 * V_8 )
{
F_39 ( L_140 , V_8 ) ;
F_76 ( & V_8 -> V_123 ) ;
F_191 ( V_8 ) ;
F_78 ( & V_8 -> V_123 ) ;
if ( F_11 ( V_8 , V_3 ) == 0 &&
F_11 ( V_8 , V_4 ) == 0 )
F_46 ( V_8 ) ;
}
static struct V_38 * F_197 ( enum V_343 type )
{
struct V_38 * V_144 ;
if ( F_37 ( ! F_198 ( type ) ) )
return NULL ;
V_144 = F_199 ( V_37 , V_72 ) ;
if ( V_144 )
V_144 -> type = type ;
F_84 ( & V_144 -> V_179 ) ;
return V_144 ;
}
static void F_200 ( struct V_38 * V_144 )
{
if ( ! V_144 )
return;
F_37 ( ! F_72 ( & V_144 -> V_179 ) ) ;
if ( V_144 -> type == V_172 )
F_201 ( V_144 -> V_171 ) ;
F_202 ( V_37 , V_144 ) ;
}
void F_203 ( struct V_35 * V_90 , struct V_96 * * V_163 ,
T_1 V_98 , T_1 V_164 )
{
struct V_38 * V_144 ;
F_3 ( ! V_163 ) ;
F_3 ( ! V_98 ) ;
V_144 = F_197 ( V_162 ) ;
F_3 ( ! V_144 ) ;
V_144 -> V_163 = V_163 ;
V_144 -> V_98 = V_98 ;
V_144 -> V_164 = V_164 & ~ V_166 ;
F_193 ( & V_144 -> V_179 , & V_90 -> V_144 ) ;
V_90 -> V_177 += V_98 ;
}
void F_204 ( struct V_35 * V_90 ,
struct V_170 * V_171 )
{
struct V_38 * V_144 ;
F_3 ( ! V_171 ) ;
F_3 ( ! V_171 -> V_98 ) ;
V_144 = F_197 ( V_172 ) ;
F_3 ( ! V_144 ) ;
V_144 -> V_171 = V_171 ;
F_193 ( & V_144 -> V_179 , & V_90 -> V_144 ) ;
V_90 -> V_177 += V_171 -> V_98 ;
}
void F_205 ( struct V_35 * V_90 , struct V_148 * V_148 ,
T_1 V_98 )
{
struct V_38 * V_144 ;
F_3 ( ! V_148 ) ;
V_144 = F_197 ( V_149 ) ;
F_3 ( ! V_144 ) ;
V_144 -> V_148 = V_148 ;
V_144 -> V_151 = V_98 ;
F_193 ( & V_144 -> V_179 , & V_90 -> V_144 ) ;
V_90 -> V_177 += V_98 ;
}
struct V_35 * F_206 ( int type , int V_201 , T_6 V_9 ,
bool V_344 )
{
struct V_35 * V_182 ;
V_182 = F_199 ( V_34 , V_9 ) ;
if ( V_182 == NULL )
goto V_241;
V_182 -> V_199 . type = F_207 ( type ) ;
V_182 -> V_199 . V_345 = F_207 ( V_346 ) ;
V_182 -> V_199 . V_201 = F_123 ( V_201 ) ;
F_84 ( & V_182 -> V_112 ) ;
F_208 ( & V_182 -> V_347 ) ;
F_84 ( & V_182 -> V_144 ) ;
if ( V_201 ) {
V_182 -> V_203 . V_107 = F_209 ( V_201 , V_9 ) ;
if ( V_182 -> V_203 . V_107 == NULL ) {
F_39 ( L_141 ,
V_201 ) ;
goto V_348;
}
} else {
V_182 -> V_203 . V_107 = NULL ;
}
V_182 -> V_349 = V_182 -> V_203 . V_108 = V_201 ;
F_39 ( L_142 , V_182 , V_201 ) ;
return V_182 ;
V_348:
F_70 ( V_182 ) ;
V_241:
if ( ! V_344 ) {
F_31 ( L_143 , type ,
V_201 ) ;
F_37 ( 1 ) ;
} else {
F_39 ( L_143 , type ,
V_201 ) ;
}
return NULL ;
}
static int F_210 ( struct V_7 * V_8 , struct V_35 * V_90 )
{
int type = F_120 ( V_90 -> V_199 . type ) ;
int V_202 = F_119 ( V_90 -> V_199 . V_202 ) ;
F_39 ( L_144 , V_90 , type ,
F_174 ( type ) , V_202 ) ;
F_3 ( ! V_202 ) ;
F_3 ( V_90 -> V_205 ) ;
V_90 -> V_205 = F_211 ( V_202 , V_72 ) ;
if ( ! V_90 -> V_205 )
return - V_36 ;
return 0 ;
}
static int F_172 ( struct V_7 * V_8 , int * V_314 )
{
struct V_207 * V_199 = & V_8 -> V_308 ;
int V_202 = F_119 ( V_199 -> V_202 ) ;
struct V_35 * V_90 ;
int V_68 = 0 ;
F_3 ( V_8 -> V_117 != NULL ) ;
F_3 ( ! V_8 -> V_75 -> V_350 ) ;
F_78 ( & V_8 -> V_123 ) ;
V_90 = V_8 -> V_75 -> V_350 ( V_8 , V_199 , V_314 ) ;
F_76 ( & V_8 -> V_123 ) ;
if ( V_8 -> V_56 != V_297 ) {
if ( V_90 )
F_70 ( V_90 ) ;
return - V_95 ;
}
if ( V_90 ) {
F_3 ( * V_314 ) ;
V_8 -> V_117 = V_90 ;
V_8 -> V_117 -> V_8 = V_8 -> V_75 -> V_326 ( V_8 ) ;
F_3 ( V_8 -> V_117 -> V_8 == NULL ) ;
} else {
if ( * V_314 )
return 0 ;
V_8 -> V_80 = L_145 ;
return - V_36 ;
}
memcpy ( & V_8 -> V_117 -> V_199 , & V_8 -> V_308 , sizeof( V_8 -> V_308 ) ) ;
if ( V_202 && ! V_8 -> V_117 -> V_205 ) {
V_68 = F_210 ( V_8 , V_8 -> V_117 ) ;
if ( V_68 < 0 ) {
F_70 ( V_8 -> V_117 ) ;
V_8 -> V_117 = NULL ;
}
}
return V_68 ;
}
static void F_212 ( struct V_35 * V_182 )
{
F_39 ( L_116 , V_46 , V_182 ) ;
F_213 ( V_182 -> V_203 . V_107 ) ;
F_202 ( V_34 , V_182 ) ;
}
static void F_214 ( struct V_347 * V_347 )
{
struct V_35 * V_182 = F_184 ( V_347 , struct V_35 , V_347 ) ;
F_215 ( V_144 ) ;
struct V_112 * V_179 ;
struct V_112 * V_351 ;
F_39 ( L_116 , V_46 , V_182 ) ;
F_37 ( ! F_72 ( & V_182 -> V_112 ) ) ;
if ( V_182 -> V_205 ) {
F_216 ( V_182 -> V_205 ) ;
V_182 -> V_205 = NULL ;
}
F_186 ( & V_182 -> V_144 , & V_144 ) ;
F_217 (links, next, &data) {
struct V_38 * V_144 ;
V_144 = F_218 ( V_179 , struct V_38 , V_179 ) ;
F_69 ( V_179 ) ;
F_200 ( V_144 ) ;
}
V_182 -> V_177 = 0 ;
if ( V_182 -> V_352 )
F_219 ( V_182 -> V_352 , V_182 ) ;
else
F_212 ( V_182 ) ;
}
struct V_35 * F_117 ( struct V_35 * V_90 )
{
F_39 ( L_146 , V_46 , V_90 ,
F_45 ( & V_90 -> V_347 . V_353 ) ) ;
F_220 ( & V_90 -> V_347 ) ;
return V_90 ;
}
void F_70 ( struct V_35 * V_90 )
{
F_39 ( L_146 , V_46 , V_90 ,
F_45 ( & V_90 -> V_347 . V_353 ) ) ;
F_221 ( & V_90 -> V_347 , F_214 ) ;
}
void F_222 ( struct V_35 * V_90 )
{
F_223 ( L_147 , V_90 ,
V_90 -> V_349 , V_90 -> V_177 ) ;
F_224 ( V_354 , L_148 ,
V_355 , 16 , 1 ,
& V_90 -> V_199 , sizeof( V_90 -> V_199 ) , true ) ;
F_224 ( V_354 , L_149 ,
V_355 , 16 , 1 ,
V_90 -> V_203 . V_107 , V_90 -> V_203 . V_108 , true ) ;
if ( V_90 -> V_205 )
F_224 ( V_354 , L_150 ,
V_355 , 16 , 1 ,
V_90 -> V_205 -> V_206 . V_107 ,
V_90 -> V_205 -> V_206 . V_108 , true ) ;
F_224 ( V_354 , L_151 ,
V_355 , 16 , 1 ,
& V_90 -> V_184 , sizeof( V_90 -> V_184 ) , true ) ;
}
