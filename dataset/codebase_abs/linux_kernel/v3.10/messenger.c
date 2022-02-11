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
static void F_44 ( struct V_50 * V_51 , int V_52 )
{
struct V_7 * V_8 = V_51 -> V_53 ;
if ( F_45 ( & V_8 -> V_30 -> V_54 ) ) {
return;
}
if ( V_51 -> V_55 != V_56 ) {
F_39 ( L_10 , V_46 ,
V_8 , V_8 -> V_57 ) ;
F_46 ( V_8 ) ;
}
}
static void F_47 ( struct V_50 * V_51 )
{
struct V_7 * V_8 = V_51 -> V_53 ;
if ( F_7 ( V_8 , V_4 ) ) {
if ( F_48 ( V_51 ) >= F_49 ( V_51 ) ) {
F_39 ( L_11 , V_46 , V_8 ) ;
F_4 ( V_58 , & V_51 -> V_59 -> V_9 ) ;
F_46 ( V_8 ) ;
}
} else {
F_39 ( L_12 , V_46 , V_8 ) ;
}
}
static void F_50 ( struct V_50 * V_51 )
{
struct V_7 * V_8 = V_51 -> V_53 ;
F_39 ( L_13 , V_46 ,
V_8 , V_8 -> V_57 , V_51 -> V_55 ) ;
switch ( V_51 -> V_55 ) {
case V_60 :
F_39 ( L_14 , V_46 ) ;
case V_56 :
F_39 ( L_15 , V_46 ) ;
F_42 ( V_8 ) ;
F_5 ( V_8 , V_5 ) ;
F_46 ( V_8 ) ;
break;
case V_61 :
F_39 ( L_16 , V_46 ) ;
F_41 ( V_8 ) ;
F_46 ( V_8 ) ;
break;
default:
break;
}
}
static void F_51 ( struct V_62 * V_50 ,
struct V_7 * V_8 )
{
struct V_50 * V_51 = V_50 -> V_51 ;
V_51 -> V_53 = V_8 ;
V_51 -> V_63 = F_44 ;
V_51 -> V_64 = F_47 ;
V_51 -> V_65 = F_50 ;
}
static int F_52 ( struct V_7 * V_8 )
{
struct V_10 * V_66 = & V_8 -> V_67 . V_68 ;
struct V_62 * V_50 ;
int V_69 ;
F_3 ( V_8 -> V_50 ) ;
V_69 = F_53 ( V_8 -> V_67 . V_68 . V_21 , V_70 ,
V_71 , & V_50 ) ;
if ( V_69 )
return V_69 ;
V_50 -> V_51 -> V_72 = V_73 ;
#ifdef F_54
F_55 ( & V_50 -> V_51 -> V_74 , & V_75 ) ;
#endif
F_51 ( V_50 , V_8 ) ;
F_39 ( L_17 , F_13 ( & V_8 -> V_67 . V_68 ) ) ;
F_40 ( V_8 ) ;
V_69 = V_50 -> V_76 -> V_77 ( V_50 , (struct V_78 * ) V_66 , sizeof( * V_66 ) ,
V_79 ) ;
if ( V_69 == - V_80 ) {
F_39 ( L_18 ,
F_13 ( & V_8 -> V_67 . V_68 ) ,
V_50 -> V_51 -> V_55 ) ;
} else if ( V_69 < 0 ) {
F_31 ( L_19 ,
F_13 ( & V_8 -> V_67 . V_68 ) , V_69 ) ;
F_56 ( V_50 ) ;
V_8 -> V_81 = L_20 ;
return V_69 ;
}
V_8 -> V_50 = V_50 ;
return 0 ;
}
static int F_57 ( struct V_62 * V_50 , void * V_82 , T_1 V_83 )
{
struct V_84 V_85 = { V_82 , V_83 } ;
struct V_86 V_87 = { . V_88 = V_89 | V_90 } ;
int V_91 ;
V_91 = F_58 ( V_50 , & V_87 , & V_85 , 1 , V_83 , V_87 . V_88 ) ;
if ( V_91 == - V_92 )
V_91 = 0 ;
return V_91 ;
}
static int F_59 ( struct V_62 * V_50 , struct V_93 * V_93 ,
int V_94 , T_1 V_95 )
{
void * V_96 ;
int V_69 ;
F_3 ( V_94 + V_95 > V_97 ) ;
V_96 = F_60 ( V_93 ) ;
F_3 ( ! V_96 ) ;
V_69 = F_57 ( V_50 , V_96 + V_94 , V_95 ) ;
F_25 ( V_93 ) ;
return V_69 ;
}
static int F_61 ( struct V_62 * V_50 , struct V_84 * V_85 ,
T_1 V_98 , T_1 V_83 , int V_99 )
{
struct V_86 V_87 = { . V_88 = V_89 | V_90 } ;
int V_91 ;
if ( V_99 )
V_87 . V_88 |= V_100 ;
else
V_87 . V_88 |= V_101 ;
V_91 = F_62 ( V_50 , & V_87 , V_85 , V_98 , V_83 ) ;
if ( V_91 == - V_92 )
V_91 = 0 ;
return V_91 ;
}
static int F_63 ( struct V_62 * V_50 , struct V_93 * V_93 ,
int V_102 , T_1 V_103 , bool V_99 )
{
int V_9 = V_89 | V_90 | ( V_99 ? V_100 : V_101 ) ;
int V_69 ;
V_69 = F_64 ( V_50 , V_93 , V_102 , V_103 , V_9 ) ;
if ( V_69 == - V_92 )
V_69 = 0 ;
return V_69 ;
}
static int F_65 ( struct V_7 * V_8 )
{
int V_104 = 0 ;
F_39 ( L_21 , V_8 , V_8 -> V_50 ) ;
if ( V_8 -> V_50 ) {
V_104 = V_8 -> V_50 -> V_76 -> V_105 ( V_8 -> V_50 , V_106 ) ;
F_56 ( V_8 -> V_50 ) ;
V_8 -> V_50 = NULL ;
}
F_2 ( V_8 , V_5 ) ;
F_43 ( V_8 ) ;
return V_104 ;
}
static void F_66 ( struct V_35 * V_87 )
{
F_67 ( & V_87 -> V_107 ) ;
F_3 ( V_87 -> V_8 == NULL ) ;
V_87 -> V_8 -> V_76 -> V_108 ( V_87 -> V_8 ) ;
V_87 -> V_8 = NULL ;
F_68 ( V_87 ) ;
}
static void F_69 ( struct V_107 * V_109 )
{
while ( ! F_70 ( V_109 ) ) {
struct V_35 * V_87 = F_71 ( V_109 , struct V_35 ,
V_107 ) ;
F_66 ( V_87 ) ;
}
}
static void F_72 ( struct V_7 * V_8 )
{
F_39 ( L_22 , V_8 ) ;
F_69 ( & V_8 -> V_110 ) ;
F_69 ( & V_8 -> V_111 ) ;
if ( V_8 -> V_112 ) {
F_3 ( V_8 -> V_112 -> V_8 != V_8 ) ;
V_8 -> V_112 -> V_8 = NULL ;
F_68 ( V_8 -> V_112 ) ;
V_8 -> V_112 = NULL ;
V_8 -> V_76 -> V_108 ( V_8 ) ;
}
V_8 -> V_113 = 0 ;
V_8 -> V_114 = 0 ;
if ( V_8 -> V_115 ) {
F_68 ( V_8 -> V_115 ) ;
V_8 -> V_115 = NULL ;
}
V_8 -> V_116 = 0 ;
V_8 -> V_117 = 0 ;
}
void F_73 ( struct V_7 * V_8 )
{
F_74 ( & V_8 -> V_118 ) ;
F_39 ( L_23 , V_8 ,
F_13 ( & V_8 -> V_67 . V_68 ) ) ;
V_8 -> V_57 = V_119 ;
F_2 ( V_8 , V_2 ) ;
F_2 ( V_8 , V_3 ) ;
F_2 ( V_8 , V_4 ) ;
F_2 ( V_8 , V_6 ) ;
F_72 ( V_8 ) ;
V_8 -> V_120 = 0 ;
F_75 ( & V_8 -> V_121 ) ;
F_65 ( V_8 ) ;
F_76 ( & V_8 -> V_118 ) ;
}
void F_77 ( struct V_7 * V_8 ,
T_2 V_122 , T_3 V_123 ,
struct V_124 * V_33 )
{
F_74 ( & V_8 -> V_118 ) ;
F_39 ( L_24 , V_8 , F_13 ( & V_33 -> V_68 ) ) ;
F_37 ( V_8 -> V_57 != V_119 ) ;
V_8 -> V_57 = V_125 ;
V_8 -> V_126 . type = ( T_2 ) V_122 ;
V_8 -> V_126 . V_127 = F_78 ( V_123 ) ;
memcpy ( & V_8 -> V_67 , V_33 , sizeof( * V_33 ) ) ;
V_8 -> V_128 = 0 ;
F_76 ( & V_8 -> V_118 ) ;
F_46 ( V_8 ) ;
}
bool F_79 ( struct V_7 * V_8 )
{
return V_8 -> V_113 > 0 ;
}
void F_80 ( struct V_7 * V_8 , void * V_129 ,
const struct V_130 * V_76 ,
struct V_29 * V_30 )
{
F_39 ( L_25 , V_8 ) ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> V_129 = V_129 ;
V_8 -> V_76 = V_76 ;
V_8 -> V_30 = V_30 ;
F_35 ( V_8 ) ;
F_81 ( & V_8 -> V_118 ) ;
F_82 ( & V_8 -> V_110 ) ;
F_82 ( & V_8 -> V_111 ) ;
F_83 ( & V_8 -> V_121 , V_131 ) ;
V_8 -> V_57 = V_119 ;
}
static T_4 F_84 ( struct V_29 * V_30 , T_4 V_132 )
{
T_4 V_69 ;
F_85 ( & V_30 -> V_133 ) ;
if ( V_30 -> V_134 < V_132 )
V_30 -> V_134 = V_132 ;
V_69 = ++ V_30 -> V_134 ;
F_86 ( & V_30 -> V_133 ) ;
return V_69 ;
}
static void F_87 ( struct V_7 * V_8 )
{
V_8 -> V_135 = 0 ;
V_8 -> V_136 = 0 ;
V_8 -> V_137 = & V_8 -> V_138 [ 0 ] ;
}
static void F_88 ( struct V_7 * V_8 ,
T_1 V_103 , void * V_139 )
{
int V_140 ;
V_140 = V_8 -> V_135 ;
F_3 ( V_140 >= F_89 ( V_8 -> V_138 ) ) ;
V_8 -> V_138 [ V_140 ] . V_141 = V_103 ;
V_8 -> V_138 [ V_140 ] . V_142 = V_139 ;
V_8 -> V_135 ++ ;
V_8 -> V_136 += V_103 ;
}
static void F_90 ( struct V_143 * V_144 ,
T_1 V_95 )
{
struct V_38 * V_139 = V_144 -> V_139 ;
struct V_145 * V_145 ;
F_3 ( V_139 -> type != V_146 ) ;
V_145 = V_139 -> V_145 ;
F_3 ( ! V_145 ) ;
F_3 ( ! V_145 -> V_147 ) ;
V_144 -> V_148 = F_91 ( V_95 , V_139 -> V_149 ) ;
V_144 -> V_145 = V_145 ;
V_144 -> V_150 = 0 ;
V_144 -> V_151 = 0 ;
V_144 -> V_152 = V_95 <= V_145 -> V_153 [ 0 ] . V_154 ;
}
static struct V_93 * F_92 ( struct V_143 * V_144 ,
T_1 * V_94 ,
T_1 * V_95 )
{
struct V_38 * V_139 = V_144 -> V_139 ;
struct V_145 * V_145 ;
struct V_155 * V_155 ;
unsigned int V_140 ;
F_3 ( V_139 -> type != V_146 ) ;
V_145 = V_144 -> V_145 ;
F_3 ( ! V_145 ) ;
V_140 = V_144 -> V_150 ;
F_3 ( V_140 >= ( unsigned int ) V_145 -> V_147 ) ;
V_155 = & V_145 -> V_153 [ V_140 ] ;
F_3 ( V_144 -> V_151 >= V_155 -> V_154 ) ;
* V_94 = ( T_1 ) ( V_155 -> V_156 + V_144 -> V_151 ) ;
F_3 ( * V_94 >= V_97 ) ;
if ( V_144 -> V_152 )
* V_95 = V_144 -> V_148 ;
else
* V_95 = ( T_1 ) ( V_155 -> V_154 - V_144 -> V_151 ) ;
F_3 ( * V_95 > V_144 -> V_148 ) ;
F_3 ( * V_94 + * V_95 > V_97 ) ;
return V_155 -> V_157 ;
}
static bool F_93 ( struct V_143 * V_144 ,
T_1 V_158 )
{
struct V_145 * V_145 ;
struct V_155 * V_155 ;
unsigned int V_140 ;
F_3 ( V_144 -> V_139 -> type != V_146 ) ;
V_145 = V_144 -> V_145 ;
F_3 ( ! V_145 ) ;
V_140 = V_144 -> V_150 ;
F_3 ( V_140 >= ( unsigned int ) V_145 -> V_147 ) ;
V_155 = & V_145 -> V_153 [ V_140 ] ;
F_3 ( V_144 -> V_148 < V_158 ) ;
V_144 -> V_148 -= V_158 ;
V_144 -> V_151 += V_158 ;
if ( V_144 -> V_151 < V_155 -> V_154 )
return false ;
F_3 ( V_144 -> V_151 != V_155 -> V_154 ) ;
if ( ++ V_140 == ( unsigned int ) V_145 -> V_147 ) {
V_145 = V_145 -> V_159 ;
V_140 = 0 ;
}
V_144 -> V_145 = V_145 ;
V_144 -> V_150 = V_140 ;
V_144 -> V_151 = 0 ;
if ( ! V_144 -> V_152 ) {
F_3 ( ! V_144 -> V_148 ) ;
F_3 ( ! V_145 ) ;
if ( V_144 -> V_148 <= V_145 -> V_153 [ V_140 ] . V_154 )
V_144 -> V_152 = true ;
}
return true ;
}
static void F_94 ( struct V_143 * V_144 ,
T_1 V_95 )
{
struct V_38 * V_139 = V_144 -> V_139 ;
int V_160 ;
F_3 ( V_139 -> type != V_161 ) ;
F_3 ( ! V_139 -> V_162 ) ;
F_3 ( ! V_139 -> V_95 ) ;
V_144 -> V_148 = F_91 ( V_95 , V_139 -> V_95 ) ;
V_160 = F_95 ( V_139 -> V_163 , ( V_164 ) V_139 -> V_95 ) ;
V_144 -> V_94 = V_139 -> V_163 & ~ V_165 ;
V_144 -> V_166 = 0 ;
F_3 ( V_160 > ( int ) V_167 ) ;
V_144 -> V_160 = ( unsigned short ) V_160 ;
F_3 ( V_95 > V_168 - V_144 -> V_94 ) ;
V_144 -> V_152 = ( T_1 ) V_144 -> V_94 + V_95 <= V_97 ;
}
static struct V_93 *
F_96 ( struct V_143 * V_144 ,
T_1 * V_94 , T_1 * V_95 )
{
struct V_38 * V_139 = V_144 -> V_139 ;
F_3 ( V_139 -> type != V_161 ) ;
F_3 ( V_144 -> V_166 >= V_144 -> V_160 ) ;
F_3 ( V_144 -> V_94 >= V_97 ) ;
* V_94 = V_144 -> V_94 ;
if ( V_144 -> V_152 )
* V_95 = V_144 -> V_148 ;
else
* V_95 = V_97 - * V_94 ;
return V_139 -> V_162 [ V_144 -> V_166 ] ;
}
static bool F_97 ( struct V_143 * V_144 ,
T_1 V_158 )
{
F_3 ( V_144 -> V_139 -> type != V_161 ) ;
F_3 ( V_144 -> V_94 + V_158 > V_97 ) ;
V_144 -> V_148 -= V_158 ;
V_144 -> V_94 = ( V_144 -> V_94 + V_158 ) & ~ V_165 ;
if ( ! V_158 || V_144 -> V_94 )
return false ;
F_3 ( V_144 -> V_166 >= V_144 -> V_160 ) ;
V_144 -> V_166 ++ ;
V_144 -> V_152 = V_144 -> V_148 <= V_97 ;
return true ;
}
static void
F_98 ( struct V_143 * V_144 ,
T_1 V_95 )
{
struct V_38 * V_139 = V_144 -> V_139 ;
struct V_169 * V_170 ;
struct V_93 * V_93 ;
F_3 ( V_139 -> type != V_171 ) ;
V_170 = V_139 -> V_170 ;
F_3 ( ! V_170 ) ;
if ( ! V_95 )
return;
F_3 ( F_70 ( & V_170 -> V_109 ) ) ;
V_93 = F_71 ( & V_170 -> V_109 , struct V_93 , V_172 ) ;
V_144 -> V_148 = F_91 ( V_95 , V_170 -> V_95 ) ;
V_144 -> V_93 = V_93 ;
V_144 -> V_102 = 0 ;
V_144 -> V_152 = V_144 -> V_148 <= V_97 ;
}
static struct V_93 *
F_99 ( struct V_143 * V_144 ,
T_1 * V_94 , T_1 * V_95 )
{
struct V_38 * V_139 = V_144 -> V_139 ;
struct V_169 * V_170 ;
F_3 ( V_139 -> type != V_171 ) ;
V_170 = V_139 -> V_170 ;
F_3 ( ! V_170 ) ;
F_3 ( ! V_144 -> V_93 ) ;
F_3 ( V_144 -> V_102 + V_144 -> V_148 != V_170 -> V_95 ) ;
* V_94 = V_144 -> V_102 & ~ V_165 ;
if ( V_144 -> V_152 )
* V_95 = V_144 -> V_148 ;
else
* V_95 = V_97 - * V_94 ;
return V_144 -> V_93 ;
}
static bool F_100 ( struct V_143 * V_144 ,
T_1 V_158 )
{
struct V_38 * V_139 = V_144 -> V_139 ;
struct V_169 * V_170 ;
F_3 ( V_139 -> type != V_171 ) ;
V_170 = V_139 -> V_170 ;
F_3 ( ! V_170 ) ;
F_3 ( V_144 -> V_102 + V_144 -> V_148 != V_170 -> V_95 ) ;
F_3 ( ( V_144 -> V_102 & ~ V_165 ) + V_158 > V_97 ) ;
V_144 -> V_148 -= V_158 ;
V_144 -> V_102 += V_158 ;
if ( ! V_158 || V_144 -> V_102 & ~ V_165 )
return false ;
F_3 ( F_101 ( & V_144 -> V_93 -> V_172 , & V_170 -> V_109 ) ) ;
V_144 -> V_93 = F_102 ( V_144 -> V_93 , V_172 ) ;
V_144 -> V_152 = V_144 -> V_148 <= V_97 ;
return true ;
}
static void F_103 ( struct V_143 * V_144 )
{
T_1 V_95 = V_144 -> V_173 ;
switch ( V_144 -> V_139 -> type ) {
case V_171 :
F_98 ( V_144 , V_95 ) ;
break;
case V_161 :
F_94 ( V_144 , V_95 ) ;
break;
#ifdef F_104
case V_146 :
F_90 ( V_144 , V_95 ) ;
break;
#endif
case V_174 :
default:
break;
}
V_144 -> V_175 = true ;
}
static void F_105 ( struct V_35 * V_87 , T_1 V_95 )
{
struct V_143 * V_144 = & V_87 -> V_144 ;
struct V_38 * V_139 ;
F_3 ( ! V_95 ) ;
F_3 ( V_95 > V_87 -> V_176 ) ;
F_3 ( F_70 ( & V_87 -> V_139 ) ) ;
V_144 -> V_177 = & V_87 -> V_139 ;
V_144 -> V_173 = V_95 ;
V_139 = F_71 ( & V_87 -> V_139 , struct V_38 , V_178 ) ;
V_144 -> V_139 = V_139 ;
F_103 ( V_144 ) ;
}
static struct V_93 * F_106 ( struct V_143 * V_144 ,
T_1 * V_94 , T_1 * V_95 ,
bool * V_152 )
{
struct V_93 * V_93 ;
switch ( V_144 -> V_139 -> type ) {
case V_171 :
V_93 = F_99 ( V_144 , V_94 , V_95 ) ;
break;
case V_161 :
V_93 = F_96 ( V_144 , V_94 , V_95 ) ;
break;
#ifdef F_104
case V_146 :
V_93 = F_92 ( V_144 , V_94 , V_95 ) ;
break;
#endif
case V_174 :
default:
V_93 = NULL ;
break;
}
F_3 ( ! V_93 ) ;
F_3 ( * V_94 + * V_95 > V_97 ) ;
F_3 ( ! * V_95 ) ;
if ( V_152 )
* V_152 = V_144 -> V_152 ;
return V_93 ;
}
static bool F_107 ( struct V_143 * V_144 ,
T_1 V_158 )
{
bool V_179 ;
F_3 ( V_158 > V_144 -> V_148 ) ;
switch ( V_144 -> V_139 -> type ) {
case V_171 :
V_179 = F_100 ( V_144 , V_158 ) ;
break;
case V_161 :
V_179 = F_97 ( V_144 , V_158 ) ;
break;
#ifdef F_104
case V_146 :
V_179 = F_93 ( V_144 , V_158 ) ;
break;
#endif
case V_174 :
default:
F_108 () ;
break;
}
V_144 -> V_173 -= V_158 ;
if ( ! V_144 -> V_148 && V_144 -> V_173 ) {
F_37 ( ! V_144 -> V_152 ) ;
F_3 ( F_101 ( & V_144 -> V_139 -> V_178 , V_144 -> V_177 ) ) ;
V_144 -> V_139 = F_102 ( V_144 -> V_139 , V_178 ) ;
F_103 ( V_144 ) ;
V_179 = true ;
}
V_144 -> V_175 = V_179 ;
return V_179 ;
}
static void F_109 ( struct V_35 * V_87 , T_4 V_180 )
{
F_3 ( ! V_87 ) ;
F_3 ( ! V_180 ) ;
F_105 ( V_87 , ( T_1 ) V_180 ) ;
}
static void F_110 ( struct V_7 * V_8 )
{
struct V_35 * V_181 = V_8 -> V_115 ;
int V_182 = V_8 -> V_135 ;
V_181 -> V_183 . V_9 |= V_184 ;
F_39 ( L_26 , V_8 ) ;
V_8 -> V_185 = true ;
V_8 -> V_138 [ V_182 ] . V_142 = & V_181 -> V_183 ;
V_8 -> V_138 [ V_182 ] . V_141 = sizeof( V_181 -> V_183 ) ;
V_8 -> V_136 += sizeof( V_181 -> V_183 ) ;
V_8 -> V_135 ++ ;
V_8 -> V_186 = V_181 -> V_187 ;
V_8 -> V_188 = true ;
}
static void F_111 ( struct V_7 * V_8 )
{
struct V_35 * V_181 ;
T_4 V_189 ;
F_87 ( V_8 ) ;
V_8 -> V_185 = true ;
V_8 -> V_188 = false ;
if ( V_8 -> V_116 > V_8 -> V_117 ) {
V_8 -> V_117 = V_8 -> V_116 ;
F_88 ( V_8 , sizeof ( V_190 ) , & V_190 ) ;
V_8 -> V_191 = F_78 ( V_8 -> V_117 ) ;
F_88 ( V_8 , sizeof ( V_8 -> V_191 ) ,
& V_8 -> V_191 ) ;
}
F_3 ( F_70 ( & V_8 -> V_110 ) ) ;
V_181 = F_71 ( & V_8 -> V_110 , struct V_35 , V_107 ) ;
V_8 -> V_115 = V_181 ;
F_3 ( V_181 -> V_8 != V_8 ) ;
F_112 ( V_181 ) ;
F_113 ( & V_181 -> V_107 , & V_8 -> V_111 ) ;
if ( V_181 -> V_192 ) {
V_181 -> V_193 . V_194 = F_78 ( ++ V_8 -> V_114 ) ;
V_181 -> V_192 = false ;
}
F_37 ( V_181 -> V_176 != F_114 ( V_181 -> V_193 . V_180 ) ) ;
F_39 ( L_27 ,
V_181 , V_8 -> V_114 , F_115 ( V_181 -> V_193 . type ) ,
F_114 ( V_181 -> V_193 . V_195 ) , F_114 ( V_181 -> V_193 . V_196 ) ,
V_181 -> V_176 ) ;
F_3 ( F_114 ( V_181 -> V_193 . V_195 ) != V_181 -> V_197 . V_141 ) ;
F_88 ( V_8 , sizeof ( V_198 ) , & V_198 ) ;
F_88 ( V_8 , sizeof ( V_181 -> V_193 ) , & V_181 -> V_193 ) ;
F_88 ( V_8 , V_181 -> V_197 . V_141 , V_181 -> V_197 . V_142 ) ;
if ( V_181 -> V_199 )
F_88 ( V_8 , V_181 -> V_199 -> V_200 . V_141 ,
V_181 -> V_199 -> V_200 . V_142 ) ;
V_189 = F_116 ( 0 , & V_181 -> V_193 , F_117 ( struct V_201 , V_189 ) ) ;
V_8 -> V_115 -> V_193 . V_189 = F_118 ( V_189 ) ;
V_8 -> V_115 -> V_183 . V_9 = 0 ;
V_189 = F_116 ( 0 , V_181 -> V_197 . V_142 , V_181 -> V_197 . V_141 ) ;
V_8 -> V_115 -> V_183 . V_202 = F_118 ( V_189 ) ;
if ( V_181 -> V_199 ) {
V_189 = F_116 ( 0 , V_181 -> V_199 -> V_200 . V_142 ,
V_181 -> V_199 -> V_200 . V_141 ) ;
V_8 -> V_115 -> V_183 . V_203 = F_118 ( V_189 ) ;
} else
V_8 -> V_115 -> V_183 . V_203 = 0 ;
F_39 ( L_28 , V_46 ,
F_114 ( V_8 -> V_115 -> V_183 . V_202 ) ,
F_114 ( V_8 -> V_115 -> V_183 . V_203 ) ) ;
V_8 -> V_115 -> V_183 . V_204 = 0 ;
if ( V_181 -> V_176 ) {
F_109 ( V_8 -> V_115 , V_181 -> V_176 ) ;
V_8 -> V_186 = 1 ;
} else {
F_110 ( V_8 ) ;
}
F_5 ( V_8 , V_4 ) ;
}
static void F_119 ( struct V_7 * V_8 )
{
F_39 ( L_29 , V_8 ,
V_8 -> V_117 , V_8 -> V_116 ) ;
V_8 -> V_117 = V_8 -> V_116 ;
F_87 ( V_8 ) ;
F_88 ( V_8 , sizeof ( V_190 ) , & V_190 ) ;
V_8 -> V_191 = F_78 ( V_8 -> V_117 ) ;
F_88 ( V_8 , sizeof ( V_8 -> V_191 ) ,
& V_8 -> V_191 ) ;
V_8 -> V_186 = 1 ;
F_5 ( V_8 , V_4 ) ;
}
static void F_120 ( struct V_7 * V_8 )
{
F_39 ( L_30 , V_8 ,
V_8 -> V_117 , V_8 -> V_116 ) ;
V_8 -> V_117 = V_8 -> V_116 ;
F_87 ( V_8 ) ;
V_8 -> V_191 = F_78 ( V_8 -> V_117 ) ;
F_88 ( V_8 , sizeof ( V_8 -> V_191 ) ,
& V_8 -> V_191 ) ;
F_5 ( V_8 , V_4 ) ;
}
static void F_121 ( struct V_7 * V_8 )
{
F_39 ( L_31 , V_8 ) ;
F_87 ( V_8 ) ;
F_88 ( V_8 , sizeof ( V_205 ) , & V_205 ) ;
F_5 ( V_8 , V_4 ) ;
}
static struct V_206 * F_122 ( struct V_7 * V_8 ,
int * V_207 )
{
struct V_206 * V_208 ;
if ( ! V_8 -> V_76 -> V_209 ) {
V_8 -> V_210 . V_211 = V_212 ;
V_8 -> V_210 . V_213 = 0 ;
return NULL ;
}
F_76 ( & V_8 -> V_118 ) ;
V_208 = V_8 -> V_76 -> V_209 ( V_8 , V_207 , V_8 -> V_214 ) ;
F_74 ( & V_8 -> V_118 ) ;
if ( F_123 ( V_208 ) )
return V_208 ;
if ( V_8 -> V_57 != V_215 )
return F_124 ( - V_92 ) ;
V_8 -> V_216 = V_208 -> V_217 ;
V_8 -> V_218 = V_208 -> V_219 ;
return V_208 ;
}
static void F_125 ( struct V_7 * V_8 )
{
F_88 ( V_8 , strlen ( V_220 ) , V_220 ) ;
F_88 ( V_8 , sizeof ( V_8 -> V_30 -> V_31 ) ,
& V_8 -> V_30 -> V_31 ) ;
V_8 -> V_186 = 0 ;
F_5 ( V_8 , V_4 ) ;
}
static int F_126 ( struct V_7 * V_8 )
{
unsigned int V_134 = F_84 ( V_8 -> V_30 , 0 ) ;
int V_221 ;
int V_207 ;
struct V_206 * V_208 ;
switch ( V_8 -> V_126 . type ) {
case V_222 :
V_221 = V_223 ;
break;
case V_224 :
V_221 = V_225 ;
break;
case V_226 :
V_221 = V_227 ;
break;
default:
F_108 () ;
}
F_39 ( L_32 , V_8 ,
V_8 -> V_113 , V_134 , V_221 ) ;
V_8 -> V_210 . V_228 = F_78 ( V_8 -> V_30 -> V_229 ) ;
V_8 -> V_210 . V_230 = F_118 ( V_231 ) ;
V_8 -> V_210 . V_113 = F_118 ( V_8 -> V_113 ) ;
V_8 -> V_210 . V_134 = F_118 ( V_134 ) ;
V_8 -> V_210 . V_232 = F_118 ( V_221 ) ;
V_8 -> V_210 . V_9 = 0 ;
V_207 = V_212 ;
V_208 = F_122 ( V_8 , & V_207 ) ;
if ( F_123 ( V_208 ) )
return F_127 ( V_208 ) ;
V_8 -> V_210 . V_211 = F_118 ( V_207 ) ;
V_8 -> V_210 . V_213 = V_208 ?
F_118 ( V_208 -> V_233 ) : 0 ;
F_88 ( V_8 , sizeof ( V_8 -> V_210 ) ,
& V_8 -> V_210 ) ;
if ( V_208 && V_208 -> V_233 )
F_88 ( V_8 , V_208 -> V_233 ,
V_208 -> V_234 ) ;
V_8 -> V_186 = 0 ;
F_5 ( V_8 , V_4 ) ;
return 0 ;
}
static int F_128 ( struct V_7 * V_8 )
{
int V_69 ;
F_39 ( L_33 , V_8 , V_8 -> V_136 ) ;
while ( V_8 -> V_136 > 0 ) {
V_69 = F_61 ( V_8 -> V_50 , V_8 -> V_137 ,
V_8 -> V_135 , V_8 -> V_136 ,
V_8 -> V_186 ) ;
if ( V_69 <= 0 )
goto V_235;
V_8 -> V_136 -= V_69 ;
if ( V_8 -> V_136 == 0 )
break;
while ( V_69 >= V_8 -> V_137 -> V_141 ) {
F_3 ( ! V_8 -> V_135 ) ;
V_69 -= V_8 -> V_137 -> V_141 ;
V_8 -> V_137 ++ ;
V_8 -> V_135 -- ;
}
if ( V_69 ) {
V_8 -> V_137 -> V_141 -= V_69 ;
V_8 -> V_137 -> V_142 += V_69 ;
}
}
V_8 -> V_135 = 0 ;
V_8 -> V_185 = false ;
V_69 = 1 ;
V_235:
F_39 ( L_34 , V_8 ,
V_8 -> V_136 , V_8 -> V_135 , V_69 ) ;
return V_69 ;
}
static T_4 F_129 ( T_4 V_189 , struct V_93 * V_93 ,
unsigned int V_94 ,
unsigned int V_95 )
{
char * V_96 ;
V_96 = F_60 ( V_93 ) ;
F_3 ( V_96 == NULL ) ;
V_189 = F_116 ( V_189 , V_96 + V_94 , V_95 ) ;
F_25 ( V_93 ) ;
return V_189 ;
}
static int F_130 ( struct V_7 * V_8 )
{
struct V_35 * V_87 = V_8 -> V_115 ;
struct V_143 * V_144 = & V_87 -> V_144 ;
bool V_236 = ! V_8 -> V_30 -> V_237 ;
T_4 V_189 ;
F_39 ( L_35 , V_46 , V_8 , V_87 ) ;
if ( F_70 ( & V_87 -> V_139 ) )
return - V_238 ;
V_189 = V_236 ? F_114 ( V_87 -> V_183 . V_204 ) : 0 ;
while ( V_144 -> V_148 ) {
struct V_93 * V_93 ;
T_1 V_94 ;
T_1 V_95 ;
bool V_152 ;
bool V_175 ;
int V_69 ;
V_93 = F_106 ( & V_87 -> V_144 , & V_94 , & V_95 ,
& V_152 ) ;
V_69 = F_63 ( V_8 -> V_50 , V_93 , V_94 ,
V_95 , V_152 ) ;
if ( V_69 <= 0 ) {
if ( V_236 )
V_87 -> V_183 . V_204 = F_118 ( V_189 ) ;
return V_69 ;
}
if ( V_236 && V_144 -> V_175 )
V_189 = F_129 ( V_189 , V_93 , V_94 , V_95 ) ;
V_175 = F_107 ( & V_87 -> V_144 , ( T_1 ) V_69 ) ;
}
F_39 ( L_36 , V_46 , V_8 , V_87 ) ;
if ( V_236 )
V_87 -> V_183 . V_204 = F_118 ( V_189 ) ;
else
V_87 -> V_183 . V_9 |= V_239 ;
F_87 ( V_8 ) ;
F_110 ( V_8 ) ;
return 1 ;
}
static int F_131 ( struct V_7 * V_8 )
{
int V_69 ;
while ( V_8 -> V_240 > 0 ) {
T_1 V_103 = F_91 ( V_8 -> V_240 , ( int ) V_241 ) ;
V_69 = F_63 ( V_8 -> V_50 , V_40 , 0 , V_103 , true ) ;
if ( V_69 <= 0 )
goto V_235;
V_8 -> V_240 -= V_69 ;
}
V_69 = 1 ;
V_235:
return V_69 ;
}
static void F_132 ( struct V_7 * V_8 )
{
F_39 ( L_37 , V_8 ) ;
V_8 -> V_242 = 0 ;
}
static void F_133 ( struct V_7 * V_8 )
{
F_39 ( L_38 , V_8 ) ;
V_8 -> V_242 = 0 ;
}
static void F_134 ( struct V_7 * V_8 )
{
F_39 ( L_39 , V_8 ) ;
V_8 -> V_242 = 0 ;
}
static void F_135 ( struct V_7 * V_8 )
{
F_39 ( L_40 , V_8 ) ;
V_8 -> V_242 = 0 ;
V_8 -> V_243 = V_244 ;
}
static void F_136 ( struct V_7 * V_8 )
{
F_39 ( L_41 , V_8 ) ;
V_8 -> V_242 = 0 ;
V_8 -> V_243 = V_245 ;
}
static int F_137 ( struct V_7 * V_8 )
{
F_39 ( L_42 , V_8 ) ;
F_3 ( V_8 -> V_112 != NULL ) ;
V_8 -> V_242 = 0 ;
V_8 -> V_246 = V_8 -> V_247 = V_8 -> V_248 = 0 ;
return 0 ;
}
static int F_138 ( struct V_7 * V_8 ,
int V_249 , int V_103 , void * V_250 )
{
while ( V_8 -> V_242 < V_249 ) {
int V_251 = V_249 - V_8 -> V_242 ;
int V_252 = V_103 - V_251 ;
int V_69 = F_57 ( V_8 -> V_50 , V_250 + V_252 , V_251 ) ;
if ( V_69 <= 0 )
return V_69 ;
V_8 -> V_242 += V_69 ;
}
return 1 ;
}
static int F_139 ( struct V_7 * V_8 )
{
int V_103 ;
int V_249 ;
int V_69 ;
F_39 ( L_43 , V_8 , V_8 -> V_242 ) ;
V_103 = strlen ( V_220 ) ;
V_249 = V_103 ;
V_69 = F_138 ( V_8 , V_249 , V_103 , V_8 -> V_253 ) ;
if ( V_69 <= 0 )
goto V_235;
V_103 = sizeof ( V_8 -> V_254 ) ;
V_249 += V_103 ;
V_69 = F_138 ( V_8 , V_249 , V_103 , & V_8 -> V_254 ) ;
if ( V_69 <= 0 )
goto V_235;
V_103 = sizeof ( V_8 -> V_255 ) ;
V_249 += V_103 ;
V_69 = F_138 ( V_8 , V_249 , V_103 , & V_8 -> V_255 ) ;
if ( V_69 <= 0 )
goto V_235;
V_235:
return V_69 ;
}
static int F_140 ( struct V_7 * V_8 )
{
int V_103 ;
int V_249 ;
int V_69 ;
F_39 ( L_44 , V_8 , V_8 -> V_242 ) ;
V_103 = sizeof ( V_8 -> V_256 ) ;
V_249 = V_103 ;
V_69 = F_138 ( V_8 , V_249 , V_103 , & V_8 -> V_256 ) ;
if ( V_69 <= 0 )
goto V_235;
V_103 = F_114 ( V_8 -> V_256 . V_213 ) ;
V_249 += V_103 ;
V_69 = F_138 ( V_8 , V_249 , V_103 , V_8 -> V_216 ) ;
if ( V_69 <= 0 )
goto V_235;
F_39 ( L_45 ,
V_8 , ( int ) V_8 -> V_256 . V_257 ,
F_114 ( V_8 -> V_256 . V_113 ) ,
F_114 ( V_8 -> V_256 . V_134 ) ) ;
V_235:
return V_69 ;
}
static int F_141 ( struct V_7 * V_8 )
{
if ( memcmp ( V_8 -> V_253 , V_220 , strlen ( V_220 ) ) ) {
F_31 ( L_46 ,
F_13 ( & V_8 -> V_67 . V_68 ) ) ;
V_8 -> V_81 = L_47 ;
return - 1 ;
}
return 0 ;
}
static bool F_142 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_21 ) {
case V_22 :
return ( (struct V_14 * ) V_11 ) -> V_24 . V_258 == 0 ;
case V_26 :
return
( (struct V_16 * ) V_11 ) -> V_27 . V_259 [ 0 ] == 0 &&
( (struct V_16 * ) V_11 ) -> V_27 . V_259 [ 1 ] == 0 &&
( (struct V_16 * ) V_11 ) -> V_27 . V_259 [ 2 ] == 0 &&
( (struct V_16 * ) V_11 ) -> V_27 . V_259 [ 3 ] == 0 ;
}
return false ;
}
static int F_143 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_21 ) {
case V_22 :
return F_15 ( ( (struct V_14 * ) V_11 ) -> V_25 ) ;
case V_26 :
return F_15 ( ( (struct V_16 * ) V_11 ) -> V_28 ) ;
}
return 0 ;
}
static void F_144 ( struct V_10 * V_11 , int V_260 )
{
switch ( V_11 -> V_21 ) {
case V_22 :
( (struct V_14 * ) V_11 ) -> V_25 = F_145 ( V_260 ) ;
break;
case V_26 :
( (struct V_16 * ) V_11 ) -> V_28 = F_145 ( V_260 ) ;
break;
}
}
static int F_146 ( const char * V_261 , T_1 V_83 , struct V_10 * V_11 ,
char V_262 , const char * * V_263 )
{
struct V_14 * V_15 = (struct V_14 * ) V_11 ;
struct V_16 * V_17 = (struct V_16 * ) V_11 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
if ( F_147 ( V_261 , V_83 , ( V_264 * ) & V_15 -> V_24 . V_258 , V_262 , V_263 ) ) {
V_11 -> V_21 = V_22 ;
return 0 ;
}
if ( F_148 ( V_261 , V_83 , ( V_264 * ) & V_17 -> V_27 . V_265 , V_262 , V_263 ) ) {
V_11 -> V_21 = V_26 ;
return 0 ;
}
return - V_238 ;
}
static int F_149 ( const char * V_266 , T_1 V_267 ,
struct V_10 * V_11 , char V_262 , const char * * V_263 )
{
const char * V_249 , * V_268 ;
char * V_269 , * V_270 = NULL ;
int V_271 , V_69 ;
V_268 = memchr ( V_266 , V_262 , V_267 ) ;
V_269 = memchr ( V_266 , ':' , V_267 ) ;
if ( V_268 && V_269 )
V_249 = V_268 < V_269 ? V_268 : V_269 ;
else if ( ! V_268 && V_269 )
V_249 = V_269 ;
else {
V_249 = V_268 ;
if ( ! V_249 )
V_249 = V_266 + V_267 ;
}
if ( V_249 <= V_266 )
return - V_238 ;
V_271 = F_150 ( NULL , V_266 , V_249 - V_266 , NULL , & V_270 , NULL ) ;
if ( V_271 > 0 )
V_69 = F_146 ( V_270 , V_271 , V_11 , - 1 , NULL ) ;
else
V_69 = - V_272 ;
F_151 ( V_270 ) ;
* V_263 = V_249 ;
F_152 ( L_48 , ( int ) ( V_249 - V_266 ) , V_266 ,
V_69 , V_69 ? L_49 : F_13 ( V_11 ) ) ;
return V_69 ;
}
static inline int F_149 ( const char * V_266 , T_1 V_267 ,
struct V_10 * V_11 , char V_262 , const char * * V_263 )
{
return - V_238 ;
}
static int F_153 ( const char * V_266 , T_1 V_267 ,
struct V_10 * V_11 , char V_262 , const char * * V_263 )
{
int V_69 ;
V_69 = F_146 ( V_266 , V_267 , V_11 , V_262 , V_263 ) ;
if ( V_69 )
V_69 = F_149 ( V_266 , V_267 , V_11 , V_262 , V_263 ) ;
return V_69 ;
}
int F_154 ( const char * V_273 , const char * V_249 ,
struct V_124 * V_33 ,
int V_274 , int * V_275 )
{
int V_12 , V_69 = - V_238 ;
const char * V_260 = V_273 ;
F_39 ( L_50 , ( int ) ( V_249 - V_273 ) , V_273 ) ;
for ( V_12 = 0 ; V_12 < V_274 ; V_12 ++ ) {
const char * V_263 ;
struct V_10 * V_11 = & V_33 [ V_12 ] . V_68 ;
int V_276 ;
char V_262 = ',' ;
if ( * V_260 == '[' ) {
V_262 = ']' ;
V_260 ++ ;
}
V_69 = F_153 ( V_260 , V_249 - V_260 , V_11 , V_262 , & V_263 ) ;
if ( V_69 )
goto V_277;
V_69 = - V_238 ;
V_260 = V_263 ;
if ( V_262 == ']' ) {
if ( * V_260 != ']' ) {
F_39 ( L_51 ) ;
goto V_277;
}
V_260 ++ ;
}
if ( V_260 < V_249 && * V_260 == ':' ) {
V_276 = 0 ;
V_260 ++ ;
while ( V_260 < V_249 && * V_260 >= '0' && * V_260 <= '9' ) {
V_276 = ( V_276 * 10 ) + ( * V_260 - '0' ) ;
V_260 ++ ;
}
if ( V_276 > 65535 || V_276 == 0 )
goto V_277;
} else {
V_276 = V_278 ;
}
F_144 ( V_11 , V_276 ) ;
F_39 ( L_52 , F_13 ( V_11 ) ) ;
if ( V_260 == V_249 )
break;
if ( * V_260 != ',' )
goto V_277;
V_260 ++ ;
}
if ( V_260 != V_249 )
goto V_277;
if ( V_275 )
* V_275 = V_12 + 1 ;
return 0 ;
V_277:
F_31 ( L_53 , ( int ) ( V_249 - V_273 ) , V_273 ) ;
return V_69 ;
}
static int F_155 ( struct V_7 * V_8 )
{
F_39 ( L_54 , V_8 ) ;
if ( F_141 ( V_8 ) < 0 )
return - 1 ;
F_156 ( & V_8 -> V_254 ) ;
F_156 ( & V_8 -> V_255 ) ;
if ( memcmp ( & V_8 -> V_67 , & V_8 -> V_254 ,
sizeof( V_8 -> V_67 ) ) != 0 &&
! ( F_142 ( & V_8 -> V_254 . V_68 ) &&
V_8 -> V_254 . V_279 == V_8 -> V_67 . V_279 ) ) {
F_157 ( L_55 ,
F_13 ( & V_8 -> V_67 . V_68 ) ,
( int ) F_114 ( V_8 -> V_67 . V_279 ) ,
F_13 ( & V_8 -> V_254 . V_68 ) ,
( int ) F_114 ( V_8 -> V_254 . V_279 ) ) ;
V_8 -> V_81 = L_56 ;
return - 1 ;
}
if ( F_142 ( & V_8 -> V_30 -> V_32 . V_33 . V_68 ) ) {
int V_276 = F_143 ( & V_8 -> V_30 -> V_32 . V_33 . V_68 ) ;
memcpy ( & V_8 -> V_30 -> V_32 . V_33 . V_68 ,
& V_8 -> V_255 . V_68 ,
sizeof( V_8 -> V_255 . V_68 ) ) ;
F_144 ( & V_8 -> V_30 -> V_32 . V_33 . V_68 , V_276 ) ;
F_16 ( V_8 -> V_30 ) ;
F_39 ( L_57 ,
F_13 ( & V_8 -> V_30 -> V_32 . V_33 . V_68 ) ) ;
}
return 0 ;
}
static int F_158 ( struct V_7 * V_8 )
{
V_164 V_280 = V_8 -> V_30 -> V_229 ;
V_164 V_281 = V_8 -> V_30 -> V_282 ;
V_164 V_283 = F_159 ( V_8 -> V_256 . V_228 ) ;
int V_69 ;
F_39 ( L_58 , V_8 , ( int ) V_8 -> V_243 ) ;
switch ( V_8 -> V_256 . V_257 ) {
case V_284 :
F_31 ( L_59
L_60 ,
F_160 ( V_8 -> V_126 ) ,
F_13 ( & V_8 -> V_67 . V_68 ) ,
V_280 , V_283 , V_283 & ~ V_280 ) ;
V_8 -> V_81 = L_61 ;
F_72 ( V_8 ) ;
return - 1 ;
case V_285 :
F_31 ( L_62
L_63 ,
F_160 ( V_8 -> V_126 ) ,
F_13 ( & V_8 -> V_67 . V_68 ) ,
F_114 ( V_8 -> V_210 . V_232 ) ,
F_114 ( V_8 -> V_256 . V_232 ) ) ;
V_8 -> V_81 = L_64 ;
F_72 ( V_8 ) ;
return - 1 ;
case V_286 :
V_8 -> V_214 ++ ;
F_39 ( L_65 , V_8 ,
V_8 -> V_214 ) ;
if ( V_8 -> V_214 == 2 ) {
V_8 -> V_81 = L_66 ;
return - 1 ;
}
F_87 ( V_8 ) ;
V_69 = F_126 ( V_8 ) ;
if ( V_69 < 0 )
return V_69 ;
F_133 ( V_8 ) ;
break;
case V_287 :
F_39 ( L_67 ,
F_114 ( V_8 -> V_256 . V_113 ) ) ;
F_31 ( L_68 ,
F_160 ( V_8 -> V_126 ) ,
F_13 ( & V_8 -> V_67 . V_68 ) ) ;
F_72 ( V_8 ) ;
F_87 ( V_8 ) ;
V_69 = F_126 ( V_8 ) ;
if ( V_69 < 0 )
return V_69 ;
F_133 ( V_8 ) ;
F_76 ( & V_8 -> V_118 ) ;
F_152 ( L_69 , F_160 ( V_8 -> V_126 ) ) ;
if ( V_8 -> V_76 -> V_288 )
V_8 -> V_76 -> V_288 ( V_8 ) ;
F_74 ( & V_8 -> V_118 ) ;
if ( V_8 -> V_57 != V_215 )
return - V_92 ;
break;
case V_289 :
F_39 ( L_70 ,
F_114 ( V_8 -> V_210 . V_113 ) ,
F_114 ( V_8 -> V_256 . V_113 ) ) ;
V_8 -> V_113 = F_114 ( V_8 -> V_256 . V_113 ) ;
F_87 ( V_8 ) ;
V_69 = F_126 ( V_8 ) ;
if ( V_69 < 0 )
return V_69 ;
F_133 ( V_8 ) ;
break;
case V_290 :
F_39 ( L_71 ,
V_8 -> V_120 ,
F_114 ( V_8 -> V_256 . V_134 ) ) ;
F_84 ( V_8 -> V_30 ,
F_114 ( V_8 -> V_256 . V_134 ) ) ;
F_87 ( V_8 ) ;
V_69 = F_126 ( V_8 ) ;
if ( V_69 < 0 )
return V_69 ;
F_133 ( V_8 ) ;
break;
case V_244 :
case V_245 :
if ( V_281 & ~ V_283 ) {
F_31 ( L_72
L_73 ,
F_160 ( V_8 -> V_126 ) ,
F_13 ( & V_8 -> V_67 . V_68 ) ,
V_281 , V_283 , V_281 & ~ V_283 ) ;
V_8 -> V_81 = L_61 ;
F_72 ( V_8 ) ;
return - 1 ;
}
F_37 ( V_8 -> V_57 != V_215 ) ;
V_8 -> V_57 = V_291 ;
V_8 -> V_214 = 0 ;
V_8 -> V_120 = F_114 ( V_8 -> V_256 . V_134 ) ;
V_8 -> V_113 ++ ;
V_8 -> V_292 = V_283 ;
F_39 ( L_74 ,
V_8 -> V_120 ,
F_114 ( V_8 -> V_256 . V_113 ) ,
V_8 -> V_113 ) ;
F_37 ( V_8 -> V_113 !=
F_114 ( V_8 -> V_256 . V_113 ) ) ;
if ( V_8 -> V_256 . V_9 & V_293 )
F_5 ( V_8 , V_2 ) ;
V_8 -> V_128 = 0 ;
if ( V_8 -> V_256 . V_257 == V_244 ) {
F_120 ( V_8 ) ;
F_135 ( V_8 ) ;
} else {
F_136 ( V_8 ) ;
}
break;
case V_294 :
F_31 ( L_75 ) ;
V_8 -> V_81 = L_76 ;
return - 1 ;
default:
F_31 ( L_77 ) ;
V_8 -> V_81 = L_78 ;
return - 1 ;
}
return 0 ;
}
static int F_161 ( struct V_7 * V_8 )
{
int V_103 = sizeof ( V_8 -> V_295 ) ;
int V_249 = V_103 ;
return F_138 ( V_8 , V_249 , V_103 , & V_8 -> V_295 ) ;
}
static void F_162 ( struct V_7 * V_8 )
{
struct V_35 * V_181 ;
V_164 V_296 = F_159 ( V_8 -> V_295 ) ;
V_164 V_194 ;
while ( ! F_70 ( & V_8 -> V_111 ) ) {
V_181 = F_71 ( & V_8 -> V_111 , struct V_35 ,
V_107 ) ;
V_194 = F_159 ( V_181 -> V_193 . V_194 ) ;
if ( V_194 > V_296 )
break;
F_39 ( L_79 , V_194 ,
F_115 ( V_181 -> V_193 . type ) , V_181 ) ;
V_181 -> V_297 = V_298 ;
F_66 ( V_181 ) ;
}
F_136 ( V_8 ) ;
}
static int F_163 ( struct V_7 * V_8 ,
struct V_84 * V_299 ,
unsigned int V_300 , T_4 * V_189 )
{
int V_69 , V_251 ;
F_3 ( ! V_299 ) ;
while ( V_299 -> V_141 < V_300 ) {
F_3 ( V_299 -> V_142 == NULL ) ;
V_251 = V_300 - V_299 -> V_141 ;
V_69 = F_57 ( V_8 -> V_50 , ( char * ) V_299 -> V_142 +
V_299 -> V_141 , V_251 ) ;
if ( V_69 <= 0 )
return V_69 ;
V_299 -> V_141 += V_69 ;
}
if ( V_299 -> V_141 == V_300 )
* V_189 = F_116 ( 0 , V_299 -> V_142 , V_299 -> V_141 ) ;
return 1 ;
}
static int F_164 ( struct V_7 * V_8 )
{
struct V_35 * V_87 = V_8 -> V_112 ;
struct V_143 * V_144 = & V_87 -> V_144 ;
const bool V_236 = ! V_8 -> V_30 -> V_237 ;
struct V_93 * V_93 ;
T_1 V_94 ;
T_1 V_95 ;
T_4 V_189 = 0 ;
int V_69 ;
F_3 ( ! V_87 ) ;
if ( F_70 ( & V_87 -> V_139 ) )
return - V_301 ;
if ( V_236 )
V_189 = V_8 -> V_248 ;
while ( V_144 -> V_148 ) {
V_93 = F_106 ( & V_87 -> V_144 , & V_94 , & V_95 ,
NULL ) ;
V_69 = F_59 ( V_8 -> V_50 , V_93 , V_94 , V_95 ) ;
if ( V_69 <= 0 ) {
if ( V_236 )
V_8 -> V_248 = V_189 ;
return V_69 ;
}
if ( V_236 )
V_189 = F_129 ( V_189 , V_93 , V_94 , V_69 ) ;
( void ) F_107 ( & V_87 -> V_144 , ( T_1 ) V_69 ) ;
}
if ( V_236 )
V_8 -> V_248 = V_189 ;
return 1 ;
}
static int F_165 ( struct V_7 * V_8 )
{
struct V_35 * V_181 = V_8 -> V_112 ;
int V_103 ;
int V_249 ;
int V_69 ;
unsigned int V_195 , V_196 , V_180 ;
bool V_236 = ! V_8 -> V_30 -> V_237 ;
V_164 V_194 ;
T_4 V_189 ;
F_39 ( L_80 , V_8 , V_181 ) ;
V_103 = sizeof ( V_8 -> V_302 ) ;
V_249 = V_103 ;
V_69 = F_138 ( V_8 , V_249 , V_103 , & V_8 -> V_302 ) ;
if ( V_69 <= 0 )
return V_69 ;
V_189 = F_116 ( 0 , & V_8 -> V_302 , F_117 ( struct V_201 , V_189 ) ) ;
if ( F_118 ( V_189 ) != V_8 -> V_302 . V_189 ) {
F_31 ( L_81
L_82 ,
V_189 , V_8 -> V_302 . V_189 ) ;
return - V_303 ;
}
V_195 = F_114 ( V_8 -> V_302 . V_195 ) ;
if ( V_195 > V_304 )
return - V_301 ;
V_196 = F_114 ( V_8 -> V_302 . V_196 ) ;
if ( V_196 > V_305 )
return - V_301 ;
V_180 = F_114 ( V_8 -> V_302 . V_180 ) ;
if ( V_180 > V_306 )
return - V_301 ;
V_194 = F_159 ( V_8 -> V_302 . V_194 ) ;
if ( ( V_307 ) V_194 - ( V_307 ) V_8 -> V_116 < 1 ) {
F_152 ( L_83 ,
F_160 ( V_8 -> V_126 ) ,
F_13 ( & V_8 -> V_67 . V_68 ) ,
V_194 , V_8 -> V_116 + 1 ) ;
V_8 -> V_242 = - V_195 - V_196 - V_180 -
sizeof( V_181 -> V_183 ) ;
V_8 -> V_243 = V_245 ;
return 0 ;
} else if ( ( V_307 ) V_194 - ( V_307 ) V_8 -> V_116 > 1 ) {
F_31 ( L_84 ,
V_194 , V_8 -> V_116 + 1 ) ;
V_8 -> V_81 = L_85 ;
return - V_303 ;
}
if ( ! V_8 -> V_112 ) {
int V_308 = 0 ;
F_39 ( L_86 , V_8 -> V_302 . type ,
V_195 , V_180 ) ;
V_69 = F_166 ( V_8 , & V_308 ) ;
if ( V_69 < 0 )
return V_69 ;
F_3 ( ! V_8 -> V_112 ^ V_308 ) ;
if ( V_8 -> V_112 && V_180 > V_8 -> V_112 -> V_176 ) {
F_157 ( L_87 ,
V_46 , V_180 , V_8 -> V_112 -> V_176 ) ;
F_68 ( V_8 -> V_112 ) ;
V_8 -> V_112 = NULL ;
V_308 = 1 ;
}
if ( V_308 ) {
F_39 ( L_88 ) ;
V_8 -> V_242 = - V_195 - V_196 - V_180 -
sizeof( V_181 -> V_183 ) ;
V_8 -> V_243 = V_245 ;
V_8 -> V_116 ++ ;
return 0 ;
}
F_3 ( ! V_8 -> V_112 ) ;
F_3 ( V_8 -> V_112 -> V_8 != V_8 ) ;
V_181 = V_8 -> V_112 ;
V_181 -> V_197 . V_141 = 0 ;
if ( V_181 -> V_199 )
V_181 -> V_199 -> V_200 . V_141 = 0 ;
if ( V_180 )
F_109 ( V_8 -> V_112 , V_180 ) ;
}
V_69 = F_163 ( V_8 , & V_181 -> V_197 , V_195 ,
& V_8 -> V_246 ) ;
if ( V_69 <= 0 )
return V_69 ;
if ( V_181 -> V_199 ) {
V_69 = F_163 ( V_8 , & V_181 -> V_199 -> V_200 ,
V_196 ,
& V_8 -> V_247 ) ;
if ( V_69 <= 0 )
return V_69 ;
}
if ( V_180 ) {
V_69 = F_164 ( V_8 ) ;
if ( V_69 <= 0 )
return V_69 ;
}
V_103 = sizeof ( V_181 -> V_183 ) ;
V_249 += V_103 ;
V_69 = F_138 ( V_8 , V_249 , V_103 , & V_181 -> V_183 ) ;
if ( V_69 <= 0 )
return V_69 ;
F_39 ( L_89 ,
V_181 , V_195 , V_181 -> V_183 . V_202 , V_196 ,
V_181 -> V_183 . V_203 , V_180 , V_181 -> V_183 . V_204 ) ;
if ( V_8 -> V_246 != F_114 ( V_181 -> V_183 . V_202 ) ) {
F_31 ( L_90 ,
V_181 , V_8 -> V_246 , V_181 -> V_183 . V_202 ) ;
return - V_303 ;
}
if ( V_8 -> V_247 != F_114 ( V_181 -> V_183 . V_203 ) ) {
F_31 ( L_91 ,
V_181 , V_8 -> V_247 , V_181 -> V_183 . V_203 ) ;
return - V_303 ;
}
if ( V_236 &&
( V_181 -> V_183 . V_9 & V_239 ) == 0 &&
V_8 -> V_248 != F_114 ( V_181 -> V_183 . V_204 ) ) {
F_31 ( L_92 , V_181 ,
V_8 -> V_248 , F_114 ( V_181 -> V_183 . V_204 ) ) ;
return - V_303 ;
}
return 1 ;
}
static void F_167 ( struct V_7 * V_8 )
{
struct V_35 * V_87 ;
F_3 ( V_8 -> V_112 -> V_8 != V_8 ) ;
V_8 -> V_112 -> V_8 = NULL ;
V_87 = V_8 -> V_112 ;
V_8 -> V_112 = NULL ;
V_8 -> V_76 -> V_108 ( V_8 ) ;
if ( V_8 -> V_126 . type == 0 )
V_8 -> V_126 = V_87 -> V_193 . V_309 ;
V_8 -> V_116 ++ ;
F_76 ( & V_8 -> V_118 ) ;
F_39 ( L_93 ,
V_87 , F_159 ( V_87 -> V_193 . V_194 ) ,
F_160 ( V_87 -> V_193 . V_309 ) ,
F_115 ( V_87 -> V_193 . type ) ,
F_168 ( F_115 ( V_87 -> V_193 . type ) ) ,
F_114 ( V_87 -> V_193 . V_195 ) ,
F_114 ( V_87 -> V_193 . V_180 ) ,
V_8 -> V_246 , V_8 -> V_247 , V_8 -> V_248 ) ;
V_8 -> V_76 -> V_310 ( V_8 , V_87 ) ;
F_74 ( & V_8 -> V_118 ) ;
}
static int F_169 ( struct V_7 * V_8 )
{
int V_69 = 1 ;
F_39 ( L_94 , V_8 , V_8 -> V_57 ) ;
V_99:
F_39 ( L_95 , V_8 -> V_136 ) ;
if ( V_8 -> V_57 == V_125 ) {
F_3 ( V_8 -> V_50 ) ;
V_8 -> V_57 = V_311 ;
F_87 ( V_8 ) ;
F_125 ( V_8 ) ;
F_132 ( V_8 ) ;
F_3 ( V_8 -> V_112 ) ;
V_8 -> V_243 = V_245 ;
F_39 ( L_96 ,
V_8 , V_8 -> V_57 ) ;
V_69 = F_52 ( V_8 ) ;
if ( V_69 < 0 ) {
V_8 -> V_81 = L_20 ;
goto V_235;
}
}
V_312:
if ( V_8 -> V_240 ) {
V_69 = F_131 ( V_8 ) ;
if ( V_69 <= 0 )
goto V_235;
}
if ( V_8 -> V_135 ) {
V_69 = F_128 ( V_8 ) ;
if ( V_69 <= 0 )
goto V_235;
}
if ( V_8 -> V_115 ) {
if ( V_8 -> V_188 ) {
F_68 ( V_8 -> V_115 ) ;
V_8 -> V_115 = NULL ;
goto V_313;
}
V_69 = F_130 ( V_8 ) ;
if ( V_69 == 1 )
goto V_312;
if ( V_69 == 0 )
goto V_235;
if ( V_69 < 0 ) {
F_39 ( L_97 ,
V_69 ) ;
goto V_235;
}
}
V_313:
if ( V_8 -> V_57 == V_291 ) {
if ( ! F_70 ( & V_8 -> V_110 ) ) {
F_111 ( V_8 ) ;
goto V_99;
}
if ( V_8 -> V_116 > V_8 -> V_117 ) {
F_119 ( V_8 ) ;
goto V_99;
}
if ( F_9 ( V_8 , V_3 ) ) {
F_121 ( V_8 ) ;
goto V_99;
}
}
F_2 ( V_8 , V_4 ) ;
F_39 ( L_98 ) ;
V_69 = 0 ;
V_235:
F_39 ( L_99 , V_8 , V_69 ) ;
return V_69 ;
}
static int F_170 ( struct V_7 * V_8 )
{
int V_69 = - 1 ;
V_99:
F_39 ( L_100 , V_8 , V_8 -> V_57 ) ;
if ( V_8 -> V_57 != V_311 &&
V_8 -> V_57 != V_215 &&
V_8 -> V_57 != V_291 )
return 0 ;
F_3 ( ! V_8 -> V_50 ) ;
F_39 ( L_101 , ( int ) V_8 -> V_243 ,
V_8 -> V_242 ) ;
if ( V_8 -> V_57 == V_311 ) {
F_39 ( L_102 ) ;
V_69 = F_139 ( V_8 ) ;
if ( V_69 <= 0 )
goto V_235;
V_69 = F_155 ( V_8 ) ;
if ( V_69 < 0 )
goto V_235;
V_8 -> V_57 = V_215 ;
V_69 = F_126 ( V_8 ) ;
if ( V_69 < 0 )
goto V_235;
F_133 ( V_8 ) ;
goto V_235;
}
if ( V_8 -> V_57 == V_215 ) {
F_39 ( L_103 ) ;
V_69 = F_140 ( V_8 ) ;
if ( V_69 <= 0 )
goto V_235;
V_69 = F_158 ( V_8 ) ;
if ( V_69 < 0 )
goto V_235;
goto V_99;
}
F_37 ( V_8 -> V_57 != V_291 ) ;
if ( V_8 -> V_242 < 0 ) {
static char V_82 [ V_314 ] ;
int V_308 = F_91 ( ( int ) sizeof ( V_82 ) , - V_8 -> V_242 ) ;
F_39 ( L_104 , V_308 , - V_8 -> V_242 ) ;
V_69 = F_57 ( V_8 -> V_50 , V_82 , V_308 ) ;
if ( V_69 <= 0 )
goto V_235;
V_8 -> V_242 += V_69 ;
if ( V_8 -> V_242 )
goto V_99;
}
if ( V_8 -> V_243 == V_245 ) {
V_69 = F_57 ( V_8 -> V_50 , & V_8 -> V_243 , 1 ) ;
if ( V_69 <= 0 )
goto V_235;
F_39 ( L_105 , ( int ) V_8 -> V_243 ) ;
switch ( V_8 -> V_243 ) {
case V_315 :
F_137 ( V_8 ) ;
break;
case V_316 :
F_134 ( V_8 ) ;
break;
case V_317 :
F_65 ( V_8 ) ;
V_8 -> V_57 = V_119 ;
goto V_235;
default:
goto V_318;
}
}
if ( V_8 -> V_243 == V_315 ) {
V_69 = F_165 ( V_8 ) ;
if ( V_69 <= 0 ) {
switch ( V_69 ) {
case - V_303 :
V_8 -> V_81 = L_106 ;
V_69 = - V_301 ;
break;
case - V_301 :
V_8 -> V_81 = L_107 ;
break;
}
goto V_235;
}
if ( V_8 -> V_243 == V_245 )
goto V_99;
F_167 ( V_8 ) ;
if ( V_8 -> V_57 == V_291 )
F_136 ( V_8 ) ;
goto V_99;
}
if ( V_8 -> V_243 == V_316 ||
V_8 -> V_243 == V_244 ) {
V_69 = F_161 ( V_8 ) ;
if ( V_69 <= 0 )
goto V_235;
F_162 ( V_8 ) ;
goto V_99;
}
V_235:
F_39 ( L_108 , V_8 , V_69 ) ;
return V_69 ;
V_318:
F_31 ( L_109 , ( int ) V_8 -> V_243 ) ;
V_8 -> V_81 = L_110 ;
V_69 = - 1 ;
goto V_235;
}
static int F_171 ( struct V_7 * V_8 , unsigned long V_128 )
{
if ( ! V_8 -> V_76 -> V_319 ( V_8 ) ) {
F_39 ( L_111 , V_46 , V_8 ) ;
return - V_320 ;
}
if ( ! F_172 ( V_39 , & V_8 -> V_121 , V_128 ) ) {
F_39 ( L_112 , V_46 , V_8 ) ;
V_8 -> V_76 -> V_108 ( V_8 ) ;
return - V_321 ;
}
F_39 ( L_113 , V_46 , V_8 , V_128 ) ;
return 0 ;
}
static void F_46 ( struct V_7 * V_8 )
{
( void ) F_171 ( V_8 , 0 ) ;
}
static bool F_173 ( struct V_7 * V_8 )
{
if ( ! F_9 ( V_8 , V_5 ) )
return false ;
#define CASE ( T_5 ) \
case CON_STATE_ ## x: \
con->error_msg = "socket closed (con state " #x ")"; \
break;
switch ( V_8 -> V_57 ) {
CASE ( V_322 ) ;
CASE ( V_323 ) ;
CASE ( V_324 ) ;
CASE ( V_325 ) ;
CASE ( V_326 ) ;
CASE ( V_327 ) ;
default:
F_157 ( L_114 ,
V_46 , V_8 , V_8 -> V_57 ) ;
V_8 -> V_81 = L_115 ;
F_108 () ;
break;
}
#undef CASE
return true ;
}
static bool F_174 ( struct V_7 * V_8 )
{
int V_69 ;
if ( ! F_9 ( V_8 , V_6 ) )
return false ;
V_69 = F_171 ( V_8 , F_175 ( V_8 -> V_128 ) ) ;
if ( V_69 ) {
F_39 ( L_116 , V_46 ,
V_8 , V_8 -> V_128 ) ;
F_3 ( V_69 == - V_320 ) ;
F_5 ( V_8 , V_6 ) ;
}
return true ;
}
static void F_176 ( struct V_7 * V_8 )
{
if ( V_8 -> V_214 && V_8 -> V_76 -> V_328 ) {
F_39 ( L_117 ) ;
V_8 -> V_76 -> V_328 ( V_8 ) ;
}
if ( V_8 -> V_76 -> V_329 )
V_8 -> V_76 -> V_329 ( V_8 ) ;
}
static void V_131 ( struct V_330 * V_121 )
{
struct V_7 * V_8 = F_177 ( V_121 , struct V_7 ,
V_121 . V_121 ) ;
bool V_329 ;
F_74 ( & V_8 -> V_118 ) ;
while ( true ) {
int V_69 ;
if ( ( V_329 = F_173 ( V_8 ) ) ) {
F_39 ( L_118 , V_46 , V_8 ) ;
break;
}
if ( F_174 ( V_8 ) ) {
F_39 ( L_119 , V_46 , V_8 ) ;
break;
}
if ( V_8 -> V_57 == V_331 ) {
F_39 ( L_120 , V_46 , V_8 ) ;
break;
}
if ( V_8 -> V_57 == V_119 ) {
F_39 ( L_121 , V_46 , V_8 ) ;
F_3 ( V_8 -> V_50 ) ;
break;
}
if ( V_8 -> V_57 == V_125 ) {
F_39 ( L_122 , V_46 , V_8 ) ;
F_3 ( V_8 -> V_50 ) ;
}
V_69 = F_170 ( V_8 ) ;
if ( V_69 < 0 ) {
if ( V_69 == - V_92 )
continue;
V_8 -> V_81 = L_123 ;
V_329 = true ;
break;
}
V_69 = F_169 ( V_8 ) ;
if ( V_69 < 0 ) {
if ( V_69 == - V_92 )
continue;
V_8 -> V_81 = L_124 ;
V_329 = true ;
}
break;
}
if ( V_329 )
F_178 ( V_8 ) ;
F_76 ( & V_8 -> V_118 ) ;
if ( V_329 )
F_176 ( V_8 ) ;
V_8 -> V_76 -> V_108 ( V_8 ) ;
}
static void F_178 ( struct V_7 * V_8 )
{
F_157 ( L_125 , F_160 ( V_8 -> V_126 ) ,
F_13 ( & V_8 -> V_67 . V_68 ) , V_8 -> V_81 ) ;
F_39 ( L_126 ,
V_8 , V_8 -> V_57 , F_13 ( & V_8 -> V_67 . V_68 ) ) ;
F_37 ( V_8 -> V_57 != V_311 &&
V_8 -> V_57 != V_215 &&
V_8 -> V_57 != V_291 ) ;
F_65 ( V_8 ) ;
if ( F_7 ( V_8 , V_2 ) ) {
F_39 ( L_127 ) ;
V_8 -> V_57 = V_119 ;
return;
}
if ( V_8 -> V_112 ) {
F_3 ( V_8 -> V_112 -> V_8 != V_8 ) ;
V_8 -> V_112 -> V_8 = NULL ;
F_68 ( V_8 -> V_112 ) ;
V_8 -> V_112 = NULL ;
V_8 -> V_76 -> V_108 ( V_8 ) ;
}
F_179 ( & V_8 -> V_111 , & V_8 -> V_110 ) ;
if ( F_70 ( & V_8 -> V_110 ) &&
! F_7 ( V_8 , V_3 ) ) {
F_39 ( L_128 , V_8 ) ;
F_2 ( V_8 , V_4 ) ;
V_8 -> V_57 = V_331 ;
} else {
V_8 -> V_57 = V_125 ;
if ( V_8 -> V_128 == 0 )
V_8 -> V_128 = V_332 ;
else if ( V_8 -> V_128 < V_333 )
V_8 -> V_128 *= 2 ;
F_5 ( V_8 , V_6 ) ;
F_46 ( V_8 ) ;
}
}
void F_180 ( struct V_29 * V_30 ,
struct V_124 * V_334 ,
T_4 V_229 ,
T_4 V_282 ,
bool V_237 )
{
V_30 -> V_229 = V_229 ;
V_30 -> V_282 = V_282 ;
F_181 ( & V_30 -> V_133 ) ;
if ( V_334 )
V_30 -> V_32 . V_33 = * V_334 ;
V_30 -> V_32 . V_33 . type = 0 ;
F_182 ( & V_30 -> V_32 . V_33 . V_279 , sizeof( V_30 -> V_32 . V_33 . V_279 ) ) ;
F_16 ( V_30 ) ;
V_30 -> V_237 = V_237 ;
F_183 ( & V_30 -> V_54 , 0 ) ;
F_39 ( L_129 , V_46 , V_30 ) ;
}
static void F_184 ( struct V_7 * V_8 )
{
if ( V_8 -> V_57 == V_331 ) {
F_39 ( L_130 , V_8 ) ;
V_8 -> V_57 = V_125 ;
V_8 -> V_113 ++ ;
F_37 ( F_7 ( V_8 , V_4 ) ) ;
F_37 ( F_7 ( V_8 , V_3 ) ) ;
}
}
void F_185 ( struct V_7 * V_8 , struct V_35 * V_87 )
{
V_87 -> V_193 . V_309 = V_8 -> V_30 -> V_32 . V_266 ;
F_3 ( V_87 -> V_197 . V_141 != F_114 ( V_87 -> V_193 . V_195 ) ) ;
V_87 -> V_192 = true ;
F_74 ( & V_8 -> V_118 ) ;
if ( V_8 -> V_57 == V_119 ) {
F_39 ( L_131 , V_8 , V_87 ) ;
F_68 ( V_87 ) ;
F_76 ( & V_8 -> V_118 ) ;
return;
}
F_3 ( V_87 -> V_8 != NULL ) ;
V_87 -> V_8 = V_8 -> V_76 -> V_319 ( V_8 ) ;
F_3 ( V_87 -> V_8 == NULL ) ;
F_3 ( ! F_70 ( & V_87 -> V_107 ) ) ;
F_186 ( & V_87 -> V_107 , & V_8 -> V_110 ) ;
F_39 ( L_132 , V_87 ,
F_160 ( V_8 -> V_126 ) , F_115 ( V_87 -> V_193 . type ) ,
F_168 ( F_115 ( V_87 -> V_193 . type ) ) ,
F_114 ( V_87 -> V_193 . V_195 ) ,
F_114 ( V_87 -> V_193 . V_196 ) ,
F_114 ( V_87 -> V_193 . V_180 ) ) ;
F_184 ( V_8 ) ;
F_76 ( & V_8 -> V_118 ) ;
if ( F_11 ( V_8 , V_4 ) == 0 )
F_46 ( V_8 ) ;
}
void F_187 ( struct V_35 * V_87 )
{
struct V_7 * V_8 = V_87 -> V_8 ;
if ( ! V_8 )
return;
F_74 ( & V_8 -> V_118 ) ;
if ( ! F_70 ( & V_87 -> V_107 ) ) {
F_39 ( L_133 , V_46 , V_8 , V_87 ) ;
F_67 ( & V_87 -> V_107 ) ;
F_3 ( V_87 -> V_8 == NULL ) ;
V_87 -> V_8 -> V_76 -> V_108 ( V_87 -> V_8 ) ;
V_87 -> V_8 = NULL ;
V_87 -> V_193 . V_194 = 0 ;
F_68 ( V_87 ) ;
}
if ( V_8 -> V_115 == V_87 ) {
F_39 ( L_134 , V_46 , V_8 , V_87 ) ;
V_8 -> V_115 = NULL ;
if ( V_8 -> V_185 ) {
V_8 -> V_240 = V_8 -> V_136 ;
V_8 -> V_185 = false ;
}
V_87 -> V_193 . V_194 = 0 ;
F_68 ( V_87 ) ;
}
F_76 ( & V_8 -> V_118 ) ;
}
void F_188 ( struct V_35 * V_87 )
{
struct V_7 * V_8 ;
F_3 ( V_87 == NULL ) ;
if ( ! V_87 -> V_8 ) {
F_39 ( L_135 , V_46 , V_87 ) ;
return;
}
V_8 = V_87 -> V_8 ;
F_74 ( & V_8 -> V_118 ) ;
if ( V_8 -> V_112 == V_87 ) {
unsigned int V_195 = F_114 ( V_8 -> V_302 . V_195 ) ;
unsigned int V_196 = F_114 ( V_8 -> V_302 . V_196 ) ;
unsigned int V_180 = F_114 ( V_8 -> V_302 . V_180 ) ;
F_39 ( L_136 , V_46 , V_8 , V_87 ) ;
V_8 -> V_242 = V_8 -> V_242 -
sizeof( struct V_201 ) -
V_195 -
V_196 -
V_180 -
sizeof( struct V_335 ) ;
F_68 ( V_8 -> V_112 ) ;
V_8 -> V_112 = NULL ;
V_8 -> V_243 = V_245 ;
V_8 -> V_116 ++ ;
} else {
F_39 ( L_137 ,
V_46 , V_8 , V_8 -> V_112 , V_87 ) ;
}
F_76 ( & V_8 -> V_118 ) ;
}
void F_189 ( struct V_7 * V_8 )
{
F_39 ( L_138 , V_8 ) ;
F_74 ( & V_8 -> V_118 ) ;
F_184 ( V_8 ) ;
F_76 ( & V_8 -> V_118 ) ;
if ( F_11 ( V_8 , V_3 ) == 0 &&
F_11 ( V_8 , V_4 ) == 0 )
F_46 ( V_8 ) ;
}
static struct V_38 * F_190 ( enum V_336 type )
{
struct V_38 * V_139 ;
if ( F_37 ( ! F_191 ( type ) ) )
return NULL ;
V_139 = F_192 ( V_37 , V_73 ) ;
if ( V_139 )
V_139 -> type = type ;
F_82 ( & V_139 -> V_178 ) ;
return V_139 ;
}
static void F_193 ( struct V_38 * V_139 )
{
if ( ! V_139 )
return;
F_37 ( ! F_70 ( & V_139 -> V_178 ) ) ;
if ( V_139 -> type == V_171 ) {
F_194 ( V_139 -> V_170 ) ;
F_151 ( V_139 -> V_170 ) ;
}
F_195 ( V_37 , V_139 ) ;
}
void F_196 ( struct V_35 * V_87 , struct V_93 * * V_162 ,
T_1 V_95 , T_1 V_163 )
{
struct V_38 * V_139 ;
F_3 ( ! V_162 ) ;
F_3 ( ! V_95 ) ;
V_139 = F_190 ( V_161 ) ;
F_3 ( ! V_139 ) ;
V_139 -> V_162 = V_162 ;
V_139 -> V_95 = V_95 ;
V_139 -> V_163 = V_163 & ~ V_165 ;
F_186 ( & V_139 -> V_178 , & V_87 -> V_139 ) ;
V_87 -> V_176 += V_95 ;
}
void F_197 ( struct V_35 * V_87 ,
struct V_169 * V_170 )
{
struct V_38 * V_139 ;
F_3 ( ! V_170 ) ;
F_3 ( ! V_170 -> V_95 ) ;
V_139 = F_190 ( V_171 ) ;
F_3 ( ! V_139 ) ;
V_139 -> V_170 = V_170 ;
F_186 ( & V_139 -> V_178 , & V_87 -> V_139 ) ;
V_87 -> V_176 += V_170 -> V_95 ;
}
void F_198 ( struct V_35 * V_87 , struct V_145 * V_145 ,
T_1 V_95 )
{
struct V_38 * V_139 ;
F_3 ( ! V_145 ) ;
V_139 = F_190 ( V_146 ) ;
F_3 ( ! V_139 ) ;
V_139 -> V_145 = V_145 ;
V_139 -> V_149 = V_95 ;
F_186 ( & V_139 -> V_178 , & V_87 -> V_139 ) ;
V_87 -> V_176 += V_95 ;
}
struct V_35 * F_199 ( int type , int V_195 , T_6 V_9 ,
bool V_337 )
{
struct V_35 * V_181 ;
V_181 = F_192 ( V_34 , V_9 ) ;
if ( V_181 == NULL )
goto V_235;
V_181 -> V_193 . type = F_200 ( type ) ;
V_181 -> V_193 . V_338 = F_200 ( V_339 ) ;
V_181 -> V_193 . V_195 = F_118 ( V_195 ) ;
F_82 ( & V_181 -> V_107 ) ;
F_201 ( & V_181 -> V_340 ) ;
F_82 ( & V_181 -> V_139 ) ;
V_181 -> V_341 = V_195 ;
if ( V_195 ) {
if ( V_195 > V_241 ) {
V_181 -> V_197 . V_142 = F_202 ( V_195 , V_9 ,
V_342 ) ;
V_181 -> V_343 = true ;
} else {
V_181 -> V_197 . V_142 = F_203 ( V_195 , V_9 ) ;
}
if ( V_181 -> V_197 . V_142 == NULL ) {
F_39 ( L_139 ,
V_195 ) ;
goto V_344;
}
} else {
V_181 -> V_197 . V_142 = NULL ;
}
V_181 -> V_197 . V_141 = V_195 ;
F_39 ( L_140 , V_181 , V_195 ) ;
return V_181 ;
V_344:
F_68 ( V_181 ) ;
V_235:
if ( ! V_337 ) {
F_31 ( L_141 , type ,
V_195 ) ;
F_37 ( 1 ) ;
} else {
F_39 ( L_141 , type ,
V_195 ) ;
}
return NULL ;
}
static int F_204 ( struct V_7 * V_8 , struct V_35 * V_87 )
{
int type = F_115 ( V_87 -> V_193 . type ) ;
int V_196 = F_114 ( V_87 -> V_193 . V_196 ) ;
F_39 ( L_142 , V_87 , type ,
F_168 ( type ) , V_196 ) ;
F_3 ( ! V_196 ) ;
F_3 ( V_87 -> V_199 ) ;
V_87 -> V_199 = F_205 ( V_196 , V_73 ) ;
if ( ! V_87 -> V_199 )
return - V_36 ;
return 0 ;
}
static int F_166 ( struct V_7 * V_8 , int * V_308 )
{
struct V_201 * V_193 = & V_8 -> V_302 ;
int V_196 = F_114 ( V_193 -> V_196 ) ;
struct V_35 * V_87 ;
int V_69 = 0 ;
F_3 ( V_8 -> V_112 != NULL ) ;
F_3 ( ! V_8 -> V_76 -> V_345 ) ;
F_76 ( & V_8 -> V_118 ) ;
V_87 = V_8 -> V_76 -> V_345 ( V_8 , V_193 , V_308 ) ;
F_74 ( & V_8 -> V_118 ) ;
if ( V_8 -> V_57 != V_291 ) {
if ( V_87 )
F_68 ( V_87 ) ;
return - V_92 ;
}
if ( V_87 ) {
F_3 ( * V_308 ) ;
V_8 -> V_112 = V_87 ;
V_8 -> V_112 -> V_8 = V_8 -> V_76 -> V_319 ( V_8 ) ;
F_3 ( V_8 -> V_112 -> V_8 == NULL ) ;
} else {
if ( * V_308 )
return 0 ;
V_8 -> V_81 = L_143 ;
return - V_36 ;
}
memcpy ( & V_8 -> V_112 -> V_193 , & V_8 -> V_302 , sizeof( V_8 -> V_302 ) ) ;
if ( V_196 && ! V_8 -> V_112 -> V_199 ) {
V_69 = F_204 ( V_8 , V_8 -> V_112 ) ;
if ( V_69 < 0 ) {
F_68 ( V_8 -> V_112 ) ;
V_8 -> V_112 = NULL ;
}
}
return V_69 ;
}
void F_206 ( struct V_35 * V_181 )
{
F_39 ( L_144 , V_181 ) ;
if ( V_181 -> V_343 )
F_207 ( V_181 -> V_197 . V_142 ) ;
else
F_151 ( V_181 -> V_197 . V_142 ) ;
F_195 ( V_34 , V_181 ) ;
}
void F_208 ( struct V_340 * V_340 )
{
struct V_35 * V_181 = F_177 ( V_340 , struct V_35 , V_340 ) ;
F_209 ( V_139 ) ;
struct V_107 * V_178 ;
struct V_107 * V_346 ;
F_39 ( L_145 , V_181 ) ;
F_37 ( ! F_70 ( & V_181 -> V_107 ) ) ;
if ( V_181 -> V_199 ) {
F_210 ( V_181 -> V_199 ) ;
V_181 -> V_199 = NULL ;
}
F_179 ( & V_181 -> V_139 , & V_139 ) ;
F_211 (links, next, &data) {
struct V_38 * V_139 ;
V_139 = F_212 ( V_178 , struct V_38 , V_178 ) ;
F_67 ( V_178 ) ;
F_193 ( V_139 ) ;
}
V_181 -> V_176 = 0 ;
if ( V_181 -> V_347 )
F_213 ( V_181 -> V_347 , V_181 ) ;
else
F_206 ( V_181 ) ;
}
void F_214 ( struct V_35 * V_87 )
{
F_215 ( L_146 , V_87 ,
V_87 -> V_341 , V_87 -> V_176 ) ;
F_216 ( V_348 , L_147 ,
V_349 , 16 , 1 ,
& V_87 -> V_193 , sizeof( V_87 -> V_193 ) , true ) ;
F_216 ( V_348 , L_148 ,
V_349 , 16 , 1 ,
V_87 -> V_197 . V_142 , V_87 -> V_197 . V_141 , true ) ;
if ( V_87 -> V_199 )
F_216 ( V_348 , L_149 ,
V_349 , 16 , 1 ,
V_87 -> V_199 -> V_200 . V_142 ,
V_87 -> V_199 -> V_200 . V_141 , true ) ;
F_216 ( V_348 , L_150 ,
V_349 , 16 , 1 ,
& V_87 -> V_183 , sizeof( V_87 -> V_183 ) , true ) ;
}
