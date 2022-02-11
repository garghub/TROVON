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
V_50 -> V_51 -> V_71 = V_72 | V_73 ;
#ifdef F_53
F_54 ( & V_50 -> V_51 -> V_74 , & V_75 ) ;
#endif
F_50 ( V_50 , V_8 ) ;
F_39 ( L_17 , F_13 ( & V_8 -> V_66 . V_67 ) ) ;
F_40 ( V_8 ) ;
V_68 = V_50 -> V_76 -> V_77 ( V_50 , (struct V_78 * ) V_65 , sizeof( * V_65 ) ,
V_79 ) ;
if ( V_68 == - V_80 ) {
F_39 ( L_18 ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_50 -> V_51 -> V_54 ) ;
} else if ( V_68 < 0 ) {
F_31 ( L_19 ,
F_13 ( & V_8 -> V_66 . V_67 ) , V_68 ) ;
F_55 ( V_50 ) ;
V_8 -> V_81 = L_20 ;
return V_68 ;
}
F_56 ( V_50 -> V_51 ) ;
V_8 -> V_50 = V_50 ;
return 0 ;
}
static int F_57 ( struct V_61 * V_50 , void * V_82 , T_1 V_83 )
{
struct V_84 V_85 = { V_82 , V_83 } ;
struct V_86 V_87 = { . V_88 = V_89 | V_90 } ;
int V_91 ;
V_91 = F_58 ( V_50 , & V_87 , & V_85 , 1 , V_83 , V_87 . V_88 ) ;
if ( V_91 == - V_92 )
V_91 = 0 ;
return V_91 ;
}
static int F_59 ( struct V_61 * V_50 , struct V_93 * V_93 ,
int V_94 , T_1 V_95 )
{
void * V_96 ;
int V_68 ;
F_3 ( V_94 + V_95 > V_97 ) ;
V_96 = F_60 ( V_93 ) ;
F_3 ( ! V_96 ) ;
V_68 = F_57 ( V_50 , V_96 + V_94 , V_95 ) ;
F_25 ( V_93 ) ;
return V_68 ;
}
static int F_61 ( struct V_61 * V_50 , struct V_84 * V_85 ,
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
static int F_63 ( struct V_61 * V_50 , struct V_93 * V_93 ,
int V_102 , T_1 V_103 , bool V_99 )
{
int V_9 = V_89 | V_90 | ( V_99 ? V_100 : V_101 ) ;
int V_68 ;
V_68 = F_64 ( V_50 , V_93 , V_102 , V_103 , V_9 ) ;
if ( V_68 == - V_92 )
V_68 = 0 ;
return V_68 ;
}
static int F_65 ( struct V_61 * V_50 , struct V_93 * V_93 ,
int V_102 , T_1 V_103 , bool V_99 )
{
int V_68 ;
struct V_84 V_85 ;
if ( F_66 ( V_93 ) >= 1 )
return F_63 ( V_50 , V_93 , V_102 , V_103 , V_99 ) ;
V_85 . V_104 = F_60 ( V_93 ) + V_102 ;
V_85 . V_105 = V_103 ;
V_68 = F_61 ( V_50 , & V_85 , 1 , V_103 , V_99 ) ;
F_25 ( V_93 ) ;
return V_68 ;
}
static int F_67 ( struct V_7 * V_8 )
{
int V_106 = 0 ;
F_39 ( L_21 , V_8 , V_8 -> V_50 ) ;
if ( V_8 -> V_50 ) {
V_106 = V_8 -> V_50 -> V_76 -> V_107 ( V_8 -> V_50 , V_108 ) ;
F_55 ( V_8 -> V_50 ) ;
V_8 -> V_50 = NULL ;
}
F_2 ( V_8 , V_5 ) ;
F_43 ( V_8 ) ;
return V_106 ;
}
static void F_68 ( struct V_35 * V_87 )
{
F_69 ( & V_87 -> V_109 ) ;
F_3 ( V_87 -> V_8 == NULL ) ;
V_87 -> V_8 -> V_76 -> V_110 ( V_87 -> V_8 ) ;
V_87 -> V_8 = NULL ;
F_70 ( V_87 ) ;
}
static void F_71 ( struct V_109 * V_111 )
{
while ( ! F_72 ( V_111 ) ) {
struct V_35 * V_87 = F_73 ( V_111 , struct V_35 ,
V_109 ) ;
F_68 ( V_87 ) ;
}
}
static void F_74 ( struct V_7 * V_8 )
{
F_39 ( L_22 , V_8 ) ;
F_71 ( & V_8 -> V_112 ) ;
F_71 ( & V_8 -> V_113 ) ;
if ( V_8 -> V_114 ) {
F_3 ( V_8 -> V_114 -> V_8 != V_8 ) ;
V_8 -> V_114 -> V_8 = NULL ;
F_70 ( V_8 -> V_114 ) ;
V_8 -> V_114 = NULL ;
V_8 -> V_76 -> V_110 ( V_8 ) ;
}
V_8 -> V_115 = 0 ;
V_8 -> V_116 = 0 ;
if ( V_8 -> V_117 ) {
F_70 ( V_8 -> V_117 ) ;
V_8 -> V_117 = NULL ;
}
V_8 -> V_118 = 0 ;
V_8 -> V_119 = 0 ;
}
void F_75 ( struct V_7 * V_8 )
{
F_76 ( & V_8 -> V_120 ) ;
F_39 ( L_23 , V_8 ,
F_13 ( & V_8 -> V_66 . V_67 ) ) ;
V_8 -> V_56 = V_121 ;
F_2 ( V_8 , V_2 ) ;
F_2 ( V_8 , V_3 ) ;
F_2 ( V_8 , V_4 ) ;
F_2 ( V_8 , V_6 ) ;
F_74 ( V_8 ) ;
V_8 -> V_122 = 0 ;
F_77 ( V_8 ) ;
F_67 ( V_8 ) ;
F_78 ( & V_8 -> V_120 ) ;
}
void F_79 ( struct V_7 * V_8 ,
T_2 V_123 , T_3 V_124 ,
struct V_125 * V_33 )
{
F_76 ( & V_8 -> V_120 ) ;
F_39 ( L_24 , V_8 , F_13 ( & V_33 -> V_67 ) ) ;
F_37 ( V_8 -> V_56 != V_121 ) ;
V_8 -> V_56 = V_126 ;
V_8 -> V_127 . type = ( T_2 ) V_123 ;
V_8 -> V_127 . V_128 = F_80 ( V_124 ) ;
memcpy ( & V_8 -> V_66 , V_33 , sizeof( * V_33 ) ) ;
V_8 -> V_129 = 0 ;
F_78 ( & V_8 -> V_120 ) ;
F_46 ( V_8 ) ;
}
bool F_81 ( struct V_7 * V_8 )
{
return V_8 -> V_115 > 0 ;
}
void F_82 ( struct V_7 * V_8 , void * V_130 ,
const struct V_131 * V_76 ,
struct V_29 * V_30 )
{
F_39 ( L_25 , V_8 ) ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> V_130 = V_130 ;
V_8 -> V_76 = V_76 ;
V_8 -> V_30 = V_30 ;
F_35 ( V_8 ) ;
F_83 ( & V_8 -> V_120 ) ;
F_84 ( & V_8 -> V_112 ) ;
F_84 ( & V_8 -> V_113 ) ;
F_85 ( & V_8 -> V_132 , V_133 ) ;
V_8 -> V_56 = V_121 ;
}
static T_4 F_86 ( struct V_29 * V_30 , T_4 V_134 )
{
T_4 V_68 ;
F_87 ( & V_30 -> V_135 ) ;
if ( V_30 -> V_136 < V_134 )
V_30 -> V_136 = V_134 ;
V_68 = ++ V_30 -> V_136 ;
F_88 ( & V_30 -> V_135 ) ;
return V_68 ;
}
static void F_89 ( struct V_7 * V_8 )
{
V_8 -> V_137 = 0 ;
V_8 -> V_138 = 0 ;
V_8 -> V_139 = & V_8 -> V_140 [ 0 ] ;
}
static void F_90 ( struct V_7 * V_8 ,
T_1 V_103 , void * V_141 )
{
int V_142 ;
V_142 = V_8 -> V_137 ;
F_3 ( V_142 >= F_91 ( V_8 -> V_140 ) ) ;
V_8 -> V_140 [ V_142 ] . V_105 = V_103 ;
V_8 -> V_140 [ V_142 ] . V_104 = V_141 ;
V_8 -> V_137 ++ ;
V_8 -> V_138 += V_103 ;
}
static void F_92 ( struct V_143 * V_144 ,
T_1 V_95 )
{
struct V_38 * V_141 = V_144 -> V_141 ;
struct V_145 * V_145 ;
F_3 ( V_141 -> type != V_146 ) ;
V_145 = V_141 -> V_145 ;
F_3 ( ! V_145 ) ;
V_144 -> V_147 = F_93 ( V_95 , V_141 -> V_148 ) ;
V_144 -> V_145 = V_145 ;
V_144 -> V_149 = V_145 -> V_150 ;
V_144 -> V_151 =
V_144 -> V_147 <= F_94 ( V_145 , V_144 -> V_149 ) ;
}
static struct V_93 * F_95 ( struct V_143 * V_144 ,
T_1 * V_94 ,
T_1 * V_95 )
{
struct V_38 * V_141 = V_144 -> V_141 ;
struct V_145 * V_145 ;
struct V_152 V_152 ;
F_3 ( V_141 -> type != V_146 ) ;
V_145 = V_144 -> V_145 ;
F_3 ( ! V_145 ) ;
V_152 = F_96 ( V_145 , V_144 -> V_149 ) ;
* V_94 = ( T_1 ) V_152 . V_153 ;
F_3 ( * V_94 >= V_97 ) ;
if ( V_144 -> V_151 )
* V_95 = V_144 -> V_147 ;
else
* V_95 = ( T_1 ) V_152 . V_154 ;
F_3 ( * V_95 > V_144 -> V_147 ) ;
F_3 ( * V_94 + * V_95 > V_97 ) ;
return V_152 . V_155 ;
}
static bool F_97 ( struct V_143 * V_144 ,
T_1 V_156 )
{
struct V_145 * V_145 ;
struct V_152 V_152 ;
F_3 ( V_144 -> V_141 -> type != V_146 ) ;
V_145 = V_144 -> V_145 ;
F_3 ( ! V_145 ) ;
V_152 = F_96 ( V_145 , V_144 -> V_149 ) ;
F_3 ( V_144 -> V_147 < V_156 ) ;
V_144 -> V_147 -= V_156 ;
F_98 ( V_145 , & V_144 -> V_149 , V_156 ) ;
if ( V_156 < V_152 . V_154 )
return false ;
if ( ! V_144 -> V_149 . V_157 ) {
V_145 = V_145 -> V_158 ;
V_144 -> V_145 = V_145 ;
if ( V_145 )
V_144 -> V_149 = V_145 -> V_150 ;
else
memset ( & V_144 -> V_149 , 0 ,
sizeof( V_144 -> V_149 ) ) ;
}
if ( ! V_144 -> V_151 ) {
F_3 ( ! V_144 -> V_147 ) ;
F_3 ( ! V_145 ) ;
if ( V_144 -> V_147 <= F_94 ( V_145 , V_144 -> V_149 ) )
V_144 -> V_151 = true ;
}
return true ;
}
static void F_99 ( struct V_143 * V_144 ,
T_1 V_95 )
{
struct V_38 * V_141 = V_144 -> V_141 ;
int F_66 ;
F_3 ( V_141 -> type != V_159 ) ;
F_3 ( ! V_141 -> V_160 ) ;
F_3 ( ! V_141 -> V_95 ) ;
V_144 -> V_147 = F_93 ( V_95 , V_141 -> V_95 ) ;
F_66 = F_100 ( V_141 -> V_161 , ( V_162 ) V_141 -> V_95 ) ;
V_144 -> V_94 = V_141 -> V_161 & ~ V_163 ;
V_144 -> V_164 = 0 ;
F_3 ( F_66 > ( int ) V_165 ) ;
V_144 -> F_66 = ( unsigned short ) F_66 ;
F_3 ( V_95 > V_166 - V_144 -> V_94 ) ;
V_144 -> V_151 = V_144 -> V_94 + V_144 -> V_147 <= V_97 ;
}
static struct V_93 *
F_101 ( struct V_143 * V_144 ,
T_1 * V_94 , T_1 * V_95 )
{
struct V_38 * V_141 = V_144 -> V_141 ;
F_3 ( V_141 -> type != V_159 ) ;
F_3 ( V_144 -> V_164 >= V_144 -> F_66 ) ;
F_3 ( V_144 -> V_94 >= V_97 ) ;
* V_94 = V_144 -> V_94 ;
if ( V_144 -> V_151 )
* V_95 = V_144 -> V_147 ;
else
* V_95 = V_97 - * V_94 ;
return V_141 -> V_160 [ V_144 -> V_164 ] ;
}
static bool F_102 ( struct V_143 * V_144 ,
T_1 V_156 )
{
F_3 ( V_144 -> V_141 -> type != V_159 ) ;
F_3 ( V_144 -> V_94 + V_156 > V_97 ) ;
V_144 -> V_147 -= V_156 ;
V_144 -> V_94 = ( V_144 -> V_94 + V_156 ) & ~ V_163 ;
if ( ! V_156 || V_144 -> V_94 )
return false ;
if ( ! V_144 -> V_147 )
return false ;
F_3 ( V_144 -> V_164 >= V_144 -> F_66 ) ;
V_144 -> V_164 ++ ;
V_144 -> V_151 = V_144 -> V_147 <= V_97 ;
return true ;
}
static void
F_103 ( struct V_143 * V_144 ,
T_1 V_95 )
{
struct V_38 * V_141 = V_144 -> V_141 ;
struct V_167 * V_168 ;
struct V_93 * V_93 ;
F_3 ( V_141 -> type != V_169 ) ;
V_168 = V_141 -> V_168 ;
F_3 ( ! V_168 ) ;
if ( ! V_95 )
return;
F_3 ( F_72 ( & V_168 -> V_111 ) ) ;
V_93 = F_73 ( & V_168 -> V_111 , struct V_93 , V_170 ) ;
V_144 -> V_147 = F_93 ( V_95 , V_168 -> V_95 ) ;
V_144 -> V_93 = V_93 ;
V_144 -> V_102 = 0 ;
V_144 -> V_151 = V_144 -> V_147 <= V_97 ;
}
static struct V_93 *
F_104 ( struct V_143 * V_144 ,
T_1 * V_94 , T_1 * V_95 )
{
struct V_38 * V_141 = V_144 -> V_141 ;
struct V_167 * V_168 ;
F_3 ( V_141 -> type != V_169 ) ;
V_168 = V_141 -> V_168 ;
F_3 ( ! V_168 ) ;
F_3 ( ! V_144 -> V_93 ) ;
F_3 ( V_144 -> V_102 + V_144 -> V_147 != V_168 -> V_95 ) ;
* V_94 = V_144 -> V_102 & ~ V_163 ;
if ( V_144 -> V_151 )
* V_95 = V_144 -> V_147 ;
else
* V_95 = V_97 - * V_94 ;
return V_144 -> V_93 ;
}
static bool F_105 ( struct V_143 * V_144 ,
T_1 V_156 )
{
struct V_38 * V_141 = V_144 -> V_141 ;
struct V_167 * V_168 ;
F_3 ( V_141 -> type != V_169 ) ;
V_168 = V_141 -> V_168 ;
F_3 ( ! V_168 ) ;
F_3 ( V_144 -> V_102 + V_144 -> V_147 != V_168 -> V_95 ) ;
F_3 ( ( V_144 -> V_102 & ~ V_163 ) + V_156 > V_97 ) ;
V_144 -> V_147 -= V_156 ;
V_144 -> V_102 += V_156 ;
if ( ! V_156 || V_144 -> V_102 & ~ V_163 )
return false ;
if ( ! V_144 -> V_147 )
return false ;
F_3 ( F_106 ( & V_144 -> V_93 -> V_170 , & V_168 -> V_111 ) ) ;
V_144 -> V_93 = F_107 ( V_144 -> V_93 , V_170 ) ;
V_144 -> V_151 = V_144 -> V_147 <= V_97 ;
return true ;
}
static void F_108 ( struct V_143 * V_144 )
{
T_1 V_95 = V_144 -> V_171 ;
switch ( V_144 -> V_141 -> type ) {
case V_169 :
F_103 ( V_144 , V_95 ) ;
break;
case V_159 :
F_99 ( V_144 , V_95 ) ;
break;
#ifdef F_109
case V_146 :
F_92 ( V_144 , V_95 ) ;
break;
#endif
case V_172 :
default:
break;
}
V_144 -> V_173 = true ;
}
static void F_110 ( struct V_35 * V_87 , T_1 V_95 )
{
struct V_143 * V_144 = & V_87 -> V_144 ;
struct V_38 * V_141 ;
F_3 ( ! V_95 ) ;
F_3 ( V_95 > V_87 -> V_174 ) ;
F_3 ( F_72 ( & V_87 -> V_141 ) ) ;
V_144 -> V_175 = & V_87 -> V_141 ;
V_144 -> V_171 = V_95 ;
V_141 = F_73 ( & V_87 -> V_141 , struct V_38 , V_176 ) ;
V_144 -> V_141 = V_141 ;
F_108 ( V_144 ) ;
}
static struct V_93 * F_111 ( struct V_143 * V_144 ,
T_1 * V_94 , T_1 * V_95 ,
bool * V_151 )
{
struct V_93 * V_93 ;
switch ( V_144 -> V_141 -> type ) {
case V_169 :
V_93 = F_104 ( V_144 , V_94 , V_95 ) ;
break;
case V_159 :
V_93 = F_101 ( V_144 , V_94 , V_95 ) ;
break;
#ifdef F_109
case V_146 :
V_93 = F_95 ( V_144 , V_94 , V_95 ) ;
break;
#endif
case V_172 :
default:
V_93 = NULL ;
break;
}
F_3 ( ! V_93 ) ;
F_3 ( * V_94 + * V_95 > V_97 ) ;
F_3 ( ! * V_95 ) ;
if ( V_151 )
* V_151 = V_144 -> V_151 ;
return V_93 ;
}
static bool F_112 ( struct V_143 * V_144 ,
T_1 V_156 )
{
bool V_177 ;
F_3 ( V_156 > V_144 -> V_147 ) ;
switch ( V_144 -> V_141 -> type ) {
case V_169 :
V_177 = F_105 ( V_144 , V_156 ) ;
break;
case V_159 :
V_177 = F_102 ( V_144 , V_156 ) ;
break;
#ifdef F_109
case V_146 :
V_177 = F_97 ( V_144 , V_156 ) ;
break;
#endif
case V_172 :
default:
F_113 () ;
break;
}
V_144 -> V_171 -= V_156 ;
if ( ! V_144 -> V_147 && V_144 -> V_171 ) {
F_37 ( ! V_144 -> V_151 ) ;
F_3 ( F_106 ( & V_144 -> V_141 -> V_176 , V_144 -> V_175 ) ) ;
V_144 -> V_141 = F_107 ( V_144 -> V_141 , V_176 ) ;
F_108 ( V_144 ) ;
V_177 = true ;
}
V_144 -> V_173 = V_177 ;
return V_177 ;
}
static void F_114 ( struct V_35 * V_87 , T_4 V_178 )
{
F_3 ( ! V_87 ) ;
F_3 ( ! V_178 ) ;
F_110 ( V_87 , ( T_1 ) V_178 ) ;
}
static void F_115 ( struct V_7 * V_8 )
{
struct V_35 * V_179 = V_8 -> V_117 ;
int V_180 = V_8 -> V_137 ;
V_179 -> V_181 . V_9 |= V_182 ;
F_39 ( L_26 , V_8 ) ;
V_8 -> V_183 = true ;
V_8 -> V_140 [ V_180 ] . V_104 = & V_179 -> V_181 ;
if ( V_8 -> V_184 & V_185 ) {
if ( V_8 -> V_76 -> V_186 )
V_8 -> V_76 -> V_186 ( V_8 , V_179 ) ;
else
V_179 -> V_181 . V_187 = 0 ;
V_8 -> V_140 [ V_180 ] . V_105 = sizeof( V_179 -> V_181 ) ;
V_8 -> V_138 += sizeof( V_179 -> V_181 ) ;
} else {
V_179 -> V_188 . V_9 = V_179 -> V_181 . V_9 ;
V_8 -> V_140 [ V_180 ] . V_105 = sizeof( V_179 -> V_188 ) ;
V_8 -> V_138 += sizeof( V_179 -> V_188 ) ;
}
V_8 -> V_137 ++ ;
V_8 -> V_189 = V_179 -> V_190 ;
V_8 -> V_191 = true ;
}
static void F_116 ( struct V_7 * V_8 )
{
struct V_35 * V_179 ;
T_4 V_192 ;
F_89 ( V_8 ) ;
V_8 -> V_183 = true ;
V_8 -> V_191 = false ;
if ( V_8 -> V_118 > V_8 -> V_119 ) {
V_8 -> V_119 = V_8 -> V_118 ;
F_90 ( V_8 , sizeof ( V_193 ) , & V_193 ) ;
V_8 -> V_194 = F_80 ( V_8 -> V_119 ) ;
F_90 ( V_8 , sizeof ( V_8 -> V_194 ) ,
& V_8 -> V_194 ) ;
}
F_3 ( F_72 ( & V_8 -> V_112 ) ) ;
V_179 = F_73 ( & V_8 -> V_112 , struct V_35 , V_109 ) ;
V_8 -> V_117 = V_179 ;
F_3 ( V_179 -> V_8 != V_8 ) ;
F_117 ( V_179 ) ;
F_118 ( & V_179 -> V_109 , & V_8 -> V_113 ) ;
if ( V_179 -> V_195 ) {
V_179 -> V_196 . V_197 = F_80 ( ++ V_8 -> V_116 ) ;
V_179 -> V_195 = false ;
}
F_37 ( V_179 -> V_174 != F_119 ( V_179 -> V_196 . V_178 ) ) ;
F_39 ( L_27 ,
V_179 , V_8 -> V_116 , F_120 ( V_179 -> V_196 . type ) ,
F_119 ( V_179 -> V_196 . V_198 ) , F_119 ( V_179 -> V_196 . V_199 ) ,
V_179 -> V_174 ) ;
F_3 ( F_119 ( V_179 -> V_196 . V_198 ) != V_179 -> V_200 . V_105 ) ;
F_90 ( V_8 , sizeof ( V_201 ) , & V_201 ) ;
F_90 ( V_8 , sizeof ( V_179 -> V_196 ) , & V_179 -> V_196 ) ;
F_90 ( V_8 , V_179 -> V_200 . V_105 , V_179 -> V_200 . V_104 ) ;
if ( V_179 -> V_202 )
F_90 ( V_8 , V_179 -> V_202 -> V_203 . V_105 ,
V_179 -> V_202 -> V_203 . V_104 ) ;
V_192 = F_121 ( 0 , & V_179 -> V_196 , F_122 ( struct V_204 , V_192 ) ) ;
V_8 -> V_117 -> V_196 . V_192 = F_123 ( V_192 ) ;
V_8 -> V_117 -> V_181 . V_9 = 0 ;
V_192 = F_121 ( 0 , V_179 -> V_200 . V_104 , V_179 -> V_200 . V_105 ) ;
V_8 -> V_117 -> V_181 . V_205 = F_123 ( V_192 ) ;
if ( V_179 -> V_202 ) {
V_192 = F_121 ( 0 , V_179 -> V_202 -> V_203 . V_104 ,
V_179 -> V_202 -> V_203 . V_105 ) ;
V_8 -> V_117 -> V_181 . V_206 = F_123 ( V_192 ) ;
} else
V_8 -> V_117 -> V_181 . V_206 = 0 ;
F_39 ( L_28 , V_46 ,
F_119 ( V_8 -> V_117 -> V_181 . V_205 ) ,
F_119 ( V_8 -> V_117 -> V_181 . V_206 ) ) ;
V_8 -> V_117 -> V_181 . V_207 = 0 ;
if ( V_179 -> V_174 ) {
F_114 ( V_8 -> V_117 , V_179 -> V_174 ) ;
V_8 -> V_189 = 1 ;
} else {
F_115 ( V_8 ) ;
}
F_5 ( V_8 , V_4 ) ;
}
static void F_124 ( struct V_7 * V_8 )
{
F_39 ( L_29 , V_8 ,
V_8 -> V_119 , V_8 -> V_118 ) ;
V_8 -> V_119 = V_8 -> V_118 ;
F_89 ( V_8 ) ;
F_90 ( V_8 , sizeof ( V_193 ) , & V_193 ) ;
V_8 -> V_194 = F_80 ( V_8 -> V_119 ) ;
F_90 ( V_8 , sizeof ( V_8 -> V_194 ) ,
& V_8 -> V_194 ) ;
V_8 -> V_189 = 1 ;
F_5 ( V_8 , V_4 ) ;
}
static void F_125 ( struct V_7 * V_8 )
{
F_39 ( L_30 , V_8 ,
V_8 -> V_119 , V_8 -> V_118 ) ;
V_8 -> V_119 = V_8 -> V_118 ;
F_89 ( V_8 ) ;
V_8 -> V_194 = F_80 ( V_8 -> V_119 ) ;
F_90 ( V_8 , sizeof ( V_8 -> V_194 ) ,
& V_8 -> V_194 ) ;
F_5 ( V_8 , V_4 ) ;
}
static void F_126 ( struct V_7 * V_8 )
{
F_39 ( L_31 , V_8 ) ;
F_89 ( V_8 ) ;
F_90 ( V_8 , sizeof ( V_208 ) , & V_208 ) ;
F_5 ( V_8 , V_4 ) ;
}
static struct V_209 * F_127 ( struct V_7 * V_8 ,
int * V_210 )
{
struct V_209 * V_211 ;
if ( ! V_8 -> V_76 -> V_212 ) {
V_8 -> V_213 . V_214 = V_215 ;
V_8 -> V_213 . V_216 = 0 ;
return NULL ;
}
F_78 ( & V_8 -> V_120 ) ;
V_211 = V_8 -> V_76 -> V_212 ( V_8 , V_210 , V_8 -> V_217 ) ;
F_76 ( & V_8 -> V_120 ) ;
if ( F_128 ( V_211 ) )
return V_211 ;
if ( V_8 -> V_56 != V_218 )
return F_129 ( - V_92 ) ;
V_8 -> V_219 = V_211 -> V_220 ;
V_8 -> V_221 = V_211 -> V_222 ;
return V_211 ;
}
static void F_130 ( struct V_7 * V_8 )
{
F_90 ( V_8 , strlen ( V_223 ) , V_223 ) ;
F_90 ( V_8 , sizeof ( V_8 -> V_30 -> V_31 ) ,
& V_8 -> V_30 -> V_31 ) ;
V_8 -> V_189 = 0 ;
F_5 ( V_8 , V_4 ) ;
}
static int F_131 ( struct V_7 * V_8 )
{
unsigned int V_136 = F_86 ( V_8 -> V_30 , 0 ) ;
int V_224 ;
int V_210 ;
struct V_209 * V_211 ;
switch ( V_8 -> V_127 . type ) {
case V_225 :
V_224 = V_226 ;
break;
case V_227 :
V_224 = V_228 ;
break;
case V_229 :
V_224 = V_230 ;
break;
default:
F_113 () ;
}
F_39 ( L_32 , V_8 ,
V_8 -> V_115 , V_136 , V_224 ) ;
V_8 -> V_213 . V_231 = F_80 ( V_8 -> V_30 -> V_232 ) ;
V_8 -> V_213 . V_233 = F_123 ( V_234 ) ;
V_8 -> V_213 . V_115 = F_123 ( V_8 -> V_115 ) ;
V_8 -> V_213 . V_136 = F_123 ( V_136 ) ;
V_8 -> V_213 . V_235 = F_123 ( V_224 ) ;
V_8 -> V_213 . V_9 = 0 ;
V_210 = V_215 ;
V_211 = F_127 ( V_8 , & V_210 ) ;
if ( F_128 ( V_211 ) )
return F_132 ( V_211 ) ;
V_8 -> V_213 . V_214 = F_123 ( V_210 ) ;
V_8 -> V_213 . V_216 = V_211 ?
F_123 ( V_211 -> V_236 ) : 0 ;
F_90 ( V_8 , sizeof ( V_8 -> V_213 ) ,
& V_8 -> V_213 ) ;
if ( V_211 && V_211 -> V_236 )
F_90 ( V_8 , V_211 -> V_236 ,
V_211 -> V_237 ) ;
V_8 -> V_189 = 0 ;
F_5 ( V_8 , V_4 ) ;
return 0 ;
}
static int F_133 ( struct V_7 * V_8 )
{
int V_68 ;
F_39 ( L_33 , V_8 , V_8 -> V_138 ) ;
while ( V_8 -> V_138 > 0 ) {
V_68 = F_61 ( V_8 -> V_50 , V_8 -> V_139 ,
V_8 -> V_137 , V_8 -> V_138 ,
V_8 -> V_189 ) ;
if ( V_68 <= 0 )
goto V_238;
V_8 -> V_138 -= V_68 ;
if ( V_8 -> V_138 == 0 )
break;
while ( V_68 >= V_8 -> V_139 -> V_105 ) {
F_3 ( ! V_8 -> V_137 ) ;
V_68 -= V_8 -> V_139 -> V_105 ;
V_8 -> V_139 ++ ;
V_8 -> V_137 -- ;
}
if ( V_68 ) {
V_8 -> V_139 -> V_105 -= V_68 ;
V_8 -> V_139 -> V_104 += V_68 ;
}
}
V_8 -> V_137 = 0 ;
V_8 -> V_183 = false ;
V_68 = 1 ;
V_238:
F_39 ( L_34 , V_8 ,
V_8 -> V_138 , V_8 -> V_137 , V_68 ) ;
return V_68 ;
}
static T_4 F_134 ( T_4 V_192 , struct V_93 * V_93 ,
unsigned int V_94 ,
unsigned int V_95 )
{
char * V_96 ;
V_96 = F_60 ( V_93 ) ;
F_3 ( V_96 == NULL ) ;
V_192 = F_121 ( V_192 , V_96 + V_94 , V_95 ) ;
F_25 ( V_93 ) ;
return V_192 ;
}
static int F_135 ( struct V_7 * V_8 )
{
struct V_35 * V_87 = V_8 -> V_117 ;
struct V_143 * V_144 = & V_87 -> V_144 ;
bool V_239 = ! V_8 -> V_30 -> V_240 ;
T_4 V_192 ;
F_39 ( L_35 , V_46 , V_8 , V_87 ) ;
if ( F_72 ( & V_87 -> V_141 ) )
return - V_241 ;
V_192 = V_239 ? F_119 ( V_87 -> V_181 . V_207 ) : 0 ;
while ( V_144 -> V_147 ) {
struct V_93 * V_93 ;
T_1 V_94 ;
T_1 V_95 ;
bool V_151 ;
bool V_173 ;
int V_68 ;
V_93 = F_111 ( & V_87 -> V_144 , & V_94 , & V_95 ,
& V_151 ) ;
V_68 = F_65 ( V_8 -> V_50 , V_93 , V_94 ,
V_95 , V_151 ) ;
if ( V_68 <= 0 ) {
if ( V_239 )
V_87 -> V_181 . V_207 = F_123 ( V_192 ) ;
return V_68 ;
}
if ( V_239 && V_144 -> V_173 )
V_192 = F_134 ( V_192 , V_93 , V_94 , V_95 ) ;
V_173 = F_112 ( & V_87 -> V_144 , ( T_1 ) V_68 ) ;
}
F_39 ( L_36 , V_46 , V_8 , V_87 ) ;
if ( V_239 )
V_87 -> V_181 . V_207 = F_123 ( V_192 ) ;
else
V_87 -> V_181 . V_9 |= V_242 ;
F_89 ( V_8 ) ;
F_115 ( V_8 ) ;
return 1 ;
}
static int F_136 ( struct V_7 * V_8 )
{
int V_68 ;
while ( V_8 -> V_243 > 0 ) {
T_1 V_103 = F_93 ( V_8 -> V_243 , ( int ) V_244 ) ;
V_68 = F_65 ( V_8 -> V_50 , V_40 , 0 , V_103 , true ) ;
if ( V_68 <= 0 )
goto V_238;
V_8 -> V_243 -= V_68 ;
}
V_68 = 1 ;
V_238:
return V_68 ;
}
static void F_137 ( struct V_7 * V_8 )
{
F_39 ( L_37 , V_8 ) ;
V_8 -> V_245 = 0 ;
}
static void F_138 ( struct V_7 * V_8 )
{
F_39 ( L_38 , V_8 ) ;
V_8 -> V_245 = 0 ;
}
static void F_139 ( struct V_7 * V_8 )
{
F_39 ( L_39 , V_8 ) ;
V_8 -> V_245 = 0 ;
}
static void F_140 ( struct V_7 * V_8 )
{
F_39 ( L_40 , V_8 ) ;
V_8 -> V_245 = 0 ;
V_8 -> V_246 = V_247 ;
}
static void F_141 ( struct V_7 * V_8 )
{
F_39 ( L_41 , V_8 ) ;
V_8 -> V_245 = 0 ;
V_8 -> V_246 = V_248 ;
}
static int F_142 ( struct V_7 * V_8 )
{
F_39 ( L_42 , V_8 ) ;
F_3 ( V_8 -> V_114 != NULL ) ;
V_8 -> V_245 = 0 ;
V_8 -> V_249 = V_8 -> V_250 = V_8 -> V_251 = 0 ;
return 0 ;
}
static int F_143 ( struct V_7 * V_8 ,
int V_252 , int V_103 , void * V_253 )
{
while ( V_8 -> V_245 < V_252 ) {
int V_254 = V_252 - V_8 -> V_245 ;
int V_255 = V_103 - V_254 ;
int V_68 = F_57 ( V_8 -> V_50 , V_253 + V_255 , V_254 ) ;
if ( V_68 <= 0 )
return V_68 ;
V_8 -> V_245 += V_68 ;
}
return 1 ;
}
static int F_144 ( struct V_7 * V_8 )
{
int V_103 ;
int V_252 ;
int V_68 ;
F_39 ( L_43 , V_8 , V_8 -> V_245 ) ;
V_103 = strlen ( V_223 ) ;
V_252 = V_103 ;
V_68 = F_143 ( V_8 , V_252 , V_103 , V_8 -> V_256 ) ;
if ( V_68 <= 0 )
goto V_238;
V_103 = sizeof ( V_8 -> V_257 ) ;
V_252 += V_103 ;
V_68 = F_143 ( V_8 , V_252 , V_103 , & V_8 -> V_257 ) ;
if ( V_68 <= 0 )
goto V_238;
V_103 = sizeof ( V_8 -> V_258 ) ;
V_252 += V_103 ;
V_68 = F_143 ( V_8 , V_252 , V_103 , & V_8 -> V_258 ) ;
if ( V_68 <= 0 )
goto V_238;
V_238:
return V_68 ;
}
static int F_145 ( struct V_7 * V_8 )
{
int V_103 ;
int V_252 ;
int V_68 ;
F_39 ( L_44 , V_8 , V_8 -> V_245 ) ;
V_103 = sizeof ( V_8 -> V_259 ) ;
V_252 = V_103 ;
V_68 = F_143 ( V_8 , V_252 , V_103 , & V_8 -> V_259 ) ;
if ( V_68 <= 0 )
goto V_238;
V_103 = F_119 ( V_8 -> V_259 . V_216 ) ;
V_252 += V_103 ;
V_68 = F_143 ( V_8 , V_252 , V_103 , V_8 -> V_219 ) ;
if ( V_68 <= 0 )
goto V_238;
F_39 ( L_45 ,
V_8 , ( int ) V_8 -> V_259 . V_260 ,
F_119 ( V_8 -> V_259 . V_115 ) ,
F_119 ( V_8 -> V_259 . V_136 ) ) ;
V_238:
return V_68 ;
}
static int F_146 ( struct V_7 * V_8 )
{
if ( memcmp ( V_8 -> V_256 , V_223 , strlen ( V_223 ) ) ) {
F_31 ( L_46 ,
F_13 ( & V_8 -> V_66 . V_67 ) ) ;
V_8 -> V_81 = L_47 ;
return - 1 ;
}
return 0 ;
}
static bool F_147 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_21 ) {
case V_22 :
return ( (struct V_14 * ) V_11 ) -> V_24 . V_261 == 0 ;
case V_26 :
return
( (struct V_16 * ) V_11 ) -> V_27 . V_262 [ 0 ] == 0 &&
( (struct V_16 * ) V_11 ) -> V_27 . V_262 [ 1 ] == 0 &&
( (struct V_16 * ) V_11 ) -> V_27 . V_262 [ 2 ] == 0 &&
( (struct V_16 * ) V_11 ) -> V_27 . V_262 [ 3 ] == 0 ;
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
static void F_149 ( struct V_10 * V_11 , int V_263 )
{
switch ( V_11 -> V_21 ) {
case V_22 :
( (struct V_14 * ) V_11 ) -> V_25 = F_150 ( V_263 ) ;
break;
case V_26 :
( (struct V_16 * ) V_11 ) -> V_28 = F_150 ( V_263 ) ;
break;
}
}
static int F_151 ( const char * V_264 , T_1 V_83 , struct V_10 * V_11 ,
char V_265 , const char * * V_266 )
{
struct V_14 * V_15 = (struct V_14 * ) V_11 ;
struct V_16 * V_17 = (struct V_16 * ) V_11 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
if ( F_152 ( V_264 , V_83 , ( V_267 * ) & V_15 -> V_24 . V_261 , V_265 , V_266 ) ) {
V_11 -> V_21 = V_22 ;
return 0 ;
}
if ( F_153 ( V_264 , V_83 , ( V_267 * ) & V_17 -> V_27 . V_268 , V_265 , V_266 ) ) {
V_11 -> V_21 = V_26 ;
return 0 ;
}
return - V_241 ;
}
static int F_154 ( const char * V_269 , T_1 V_270 ,
struct V_10 * V_11 , char V_265 , const char * * V_266 )
{
const char * V_252 , * V_271 ;
char * V_272 , * V_273 = NULL ;
int V_274 , V_68 ;
V_271 = memchr ( V_269 , V_265 , V_270 ) ;
V_272 = memchr ( V_269 , ':' , V_270 ) ;
if ( V_271 && V_272 )
V_252 = V_271 < V_272 ? V_271 : V_272 ;
else if ( ! V_271 && V_272 )
V_252 = V_272 ;
else {
V_252 = V_271 ;
if ( ! V_252 )
V_252 = V_269 + V_270 ;
}
if ( V_252 <= V_269 )
return - V_241 ;
V_274 = F_155 ( NULL , V_269 , V_252 - V_269 , NULL , & V_273 , NULL ) ;
if ( V_274 > 0 )
V_68 = F_151 ( V_273 , V_274 , V_11 , - 1 , NULL ) ;
else
V_68 = - V_275 ;
F_156 ( V_273 ) ;
* V_266 = V_252 ;
F_157 ( L_48 , ( int ) ( V_252 - V_269 ) , V_269 ,
V_68 , V_68 ? L_49 : F_13 ( V_11 ) ) ;
return V_68 ;
}
static inline int F_154 ( const char * V_269 , T_1 V_270 ,
struct V_10 * V_11 , char V_265 , const char * * V_266 )
{
return - V_241 ;
}
static int F_158 ( const char * V_269 , T_1 V_270 ,
struct V_10 * V_11 , char V_265 , const char * * V_266 )
{
int V_68 ;
V_68 = F_151 ( V_269 , V_270 , V_11 , V_265 , V_266 ) ;
if ( V_68 )
V_68 = F_154 ( V_269 , V_270 , V_11 , V_265 , V_266 ) ;
return V_68 ;
}
int F_159 ( const char * V_276 , const char * V_252 ,
struct V_125 * V_33 ,
int V_277 , int * V_278 )
{
int V_12 , V_68 = - V_241 ;
const char * V_263 = V_276 ;
F_39 ( L_50 , ( int ) ( V_252 - V_276 ) , V_276 ) ;
for ( V_12 = 0 ; V_12 < V_277 ; V_12 ++ ) {
const char * V_266 ;
struct V_10 * V_11 = & V_33 [ V_12 ] . V_67 ;
int V_279 ;
char V_265 = ',' ;
if ( * V_263 == '[' ) {
V_265 = ']' ;
V_263 ++ ;
}
V_68 = F_158 ( V_263 , V_252 - V_263 , V_11 , V_265 , & V_266 ) ;
if ( V_68 )
goto V_280;
V_68 = - V_241 ;
V_263 = V_266 ;
if ( V_265 == ']' ) {
if ( * V_263 != ']' ) {
F_39 ( L_51 ) ;
goto V_280;
}
V_263 ++ ;
}
if ( V_263 < V_252 && * V_263 == ':' ) {
V_279 = 0 ;
V_263 ++ ;
while ( V_263 < V_252 && * V_263 >= '0' && * V_263 <= '9' ) {
V_279 = ( V_279 * 10 ) + ( * V_263 - '0' ) ;
V_263 ++ ;
}
if ( V_279 == 0 )
V_279 = V_281 ;
else if ( V_279 > 65535 )
goto V_280;
} else {
V_279 = V_281 ;
}
F_149 ( V_11 , V_279 ) ;
F_39 ( L_52 , F_13 ( V_11 ) ) ;
if ( V_263 == V_252 )
break;
if ( * V_263 != ',' )
goto V_280;
V_263 ++ ;
}
if ( V_263 != V_252 )
goto V_280;
if ( V_278 )
* V_278 = V_12 + 1 ;
return 0 ;
V_280:
F_31 ( L_53 , ( int ) ( V_252 - V_276 ) , V_276 ) ;
return V_68 ;
}
static int F_160 ( struct V_7 * V_8 )
{
F_39 ( L_54 , V_8 ) ;
if ( F_146 ( V_8 ) < 0 )
return - 1 ;
F_161 ( & V_8 -> V_257 ) ;
F_161 ( & V_8 -> V_258 ) ;
if ( memcmp ( & V_8 -> V_66 , & V_8 -> V_257 ,
sizeof( V_8 -> V_66 ) ) != 0 &&
! ( F_147 ( & V_8 -> V_257 . V_67 ) &&
V_8 -> V_257 . V_282 == V_8 -> V_66 . V_282 ) ) {
F_162 ( L_55 ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
( int ) F_119 ( V_8 -> V_66 . V_282 ) ,
F_13 ( & V_8 -> V_257 . V_67 ) ,
( int ) F_119 ( V_8 -> V_257 . V_282 ) ) ;
V_8 -> V_81 = L_56 ;
return - 1 ;
}
if ( F_147 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ) ) {
int V_279 = F_148 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ) ;
memcpy ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ,
& V_8 -> V_258 . V_67 ,
sizeof( V_8 -> V_258 . V_67 ) ) ;
F_149 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 , V_279 ) ;
F_16 ( V_8 -> V_30 ) ;
F_39 ( L_57 ,
F_13 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ) ) ;
}
return 0 ;
}
static int F_163 ( struct V_7 * V_8 )
{
V_162 V_283 = V_8 -> V_30 -> V_232 ;
V_162 V_284 = V_8 -> V_30 -> V_285 ;
V_162 V_286 = F_164 (
F_165 ( V_8 -> V_259 . V_231 ) ) ;
int V_68 ;
F_39 ( L_58 , V_8 , ( int ) V_8 -> V_246 ) ;
switch ( V_8 -> V_259 . V_260 ) {
case V_287 :
F_31 ( L_59
L_60 ,
F_166 ( V_8 -> V_127 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_283 , V_286 , V_286 & ~ V_283 ) ;
V_8 -> V_81 = L_61 ;
F_74 ( V_8 ) ;
return - 1 ;
case V_288 :
F_31 ( L_62
L_63 ,
F_166 ( V_8 -> V_127 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
F_119 ( V_8 -> V_213 . V_235 ) ,
F_119 ( V_8 -> V_259 . V_235 ) ) ;
V_8 -> V_81 = L_64 ;
F_74 ( V_8 ) ;
return - 1 ;
case V_289 :
V_8 -> V_217 ++ ;
F_39 ( L_65 , V_8 ,
V_8 -> V_217 ) ;
if ( V_8 -> V_217 == 2 ) {
V_8 -> V_81 = L_66 ;
return - 1 ;
}
F_89 ( V_8 ) ;
V_68 = F_131 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_138 ( V_8 ) ;
break;
case V_290 :
F_39 ( L_67 ,
F_119 ( V_8 -> V_259 . V_115 ) ) ;
F_31 ( L_68 ,
F_166 ( V_8 -> V_127 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ) ;
F_74 ( V_8 ) ;
F_89 ( V_8 ) ;
V_68 = F_131 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_138 ( V_8 ) ;
F_78 ( & V_8 -> V_120 ) ;
F_157 ( L_69 , F_166 ( V_8 -> V_127 ) ) ;
if ( V_8 -> V_76 -> V_291 )
V_8 -> V_76 -> V_291 ( V_8 ) ;
F_76 ( & V_8 -> V_120 ) ;
if ( V_8 -> V_56 != V_218 )
return - V_92 ;
break;
case V_292 :
F_39 ( L_70 ,
F_119 ( V_8 -> V_213 . V_115 ) ,
F_119 ( V_8 -> V_259 . V_115 ) ) ;
V_8 -> V_115 = F_119 ( V_8 -> V_259 . V_115 ) ;
F_89 ( V_8 ) ;
V_68 = F_131 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_138 ( V_8 ) ;
break;
case V_293 :
F_39 ( L_71 ,
V_8 -> V_122 ,
F_119 ( V_8 -> V_259 . V_136 ) ) ;
F_86 ( V_8 -> V_30 ,
F_119 ( V_8 -> V_259 . V_136 ) ) ;
F_89 ( V_8 ) ;
V_68 = F_131 ( V_8 ) ;
if ( V_68 < 0 )
return V_68 ;
F_138 ( V_8 ) ;
break;
case V_247 :
case V_248 :
if ( V_284 & ~ V_286 ) {
F_31 ( L_72
L_73 ,
F_166 ( V_8 -> V_127 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_284 , V_286 , V_284 & ~ V_286 ) ;
V_8 -> V_81 = L_61 ;
F_74 ( V_8 ) ;
return - 1 ;
}
F_37 ( V_8 -> V_56 != V_218 ) ;
V_8 -> V_56 = V_294 ;
V_8 -> V_217 = 0 ;
V_8 -> V_122 = F_119 ( V_8 -> V_259 . V_136 ) ;
V_8 -> V_115 ++ ;
V_8 -> V_184 = V_286 ;
F_39 ( L_74 ,
V_8 -> V_122 ,
F_119 ( V_8 -> V_259 . V_115 ) ,
V_8 -> V_115 ) ;
F_37 ( V_8 -> V_115 !=
F_119 ( V_8 -> V_259 . V_115 ) ) ;
if ( V_8 -> V_259 . V_9 & V_295 )
F_5 ( V_8 , V_2 ) ;
V_8 -> V_129 = 0 ;
if ( V_8 -> V_259 . V_260 == V_247 ) {
F_125 ( V_8 ) ;
F_140 ( V_8 ) ;
} else {
F_141 ( V_8 ) ;
}
break;
case V_296 :
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
static int F_167 ( struct V_7 * V_8 )
{
int V_103 = sizeof ( V_8 -> V_297 ) ;
int V_252 = V_103 ;
return F_143 ( V_8 , V_252 , V_103 , & V_8 -> V_297 ) ;
}
static void F_168 ( struct V_7 * V_8 )
{
struct V_35 * V_179 ;
V_162 V_298 = F_165 ( V_8 -> V_297 ) ;
V_162 V_197 ;
while ( ! F_72 ( & V_8 -> V_113 ) ) {
V_179 = F_73 ( & V_8 -> V_113 , struct V_35 ,
V_109 ) ;
V_197 = F_165 ( V_179 -> V_196 . V_197 ) ;
if ( V_197 > V_298 )
break;
F_39 ( L_79 , V_197 ,
F_120 ( V_179 -> V_196 . type ) , V_179 ) ;
V_179 -> V_299 = V_300 ;
F_68 ( V_179 ) ;
}
F_141 ( V_8 ) ;
}
static int F_169 ( struct V_7 * V_8 ,
struct V_84 * V_301 ,
unsigned int V_302 , T_4 * V_192 )
{
int V_68 , V_254 ;
F_3 ( ! V_301 ) ;
while ( V_301 -> V_105 < V_302 ) {
F_3 ( V_301 -> V_104 == NULL ) ;
V_254 = V_302 - V_301 -> V_105 ;
V_68 = F_57 ( V_8 -> V_50 , ( char * ) V_301 -> V_104 +
V_301 -> V_105 , V_254 ) ;
if ( V_68 <= 0 )
return V_68 ;
V_301 -> V_105 += V_68 ;
}
if ( V_301 -> V_105 == V_302 )
* V_192 = F_121 ( 0 , V_301 -> V_104 , V_301 -> V_105 ) ;
return 1 ;
}
static int F_170 ( struct V_7 * V_8 )
{
struct V_35 * V_87 = V_8 -> V_114 ;
struct V_143 * V_144 = & V_87 -> V_144 ;
const bool V_239 = ! V_8 -> V_30 -> V_240 ;
struct V_93 * V_93 ;
T_1 V_94 ;
T_1 V_95 ;
T_4 V_192 = 0 ;
int V_68 ;
F_3 ( ! V_87 ) ;
if ( F_72 ( & V_87 -> V_141 ) )
return - V_303 ;
if ( V_239 )
V_192 = V_8 -> V_251 ;
while ( V_144 -> V_147 ) {
V_93 = F_111 ( & V_87 -> V_144 , & V_94 , & V_95 ,
NULL ) ;
V_68 = F_59 ( V_8 -> V_50 , V_93 , V_94 , V_95 ) ;
if ( V_68 <= 0 ) {
if ( V_239 )
V_8 -> V_251 = V_192 ;
return V_68 ;
}
if ( V_239 )
V_192 = F_134 ( V_192 , V_93 , V_94 , V_68 ) ;
( void ) F_112 ( & V_87 -> V_144 , ( T_1 ) V_68 ) ;
}
if ( V_239 )
V_8 -> V_251 = V_192 ;
return 1 ;
}
static int F_171 ( struct V_7 * V_8 )
{
struct V_35 * V_179 = V_8 -> V_114 ;
int V_103 ;
int V_252 ;
int V_68 ;
unsigned int V_198 , V_199 , V_178 ;
bool V_239 = ! V_8 -> V_30 -> V_240 ;
bool V_304 = ( V_8 -> V_184 & V_185 ) ;
V_162 V_197 ;
T_4 V_192 ;
F_39 ( L_80 , V_8 , V_179 ) ;
V_103 = sizeof ( V_8 -> V_305 ) ;
V_252 = V_103 ;
V_68 = F_143 ( V_8 , V_252 , V_103 , & V_8 -> V_305 ) ;
if ( V_68 <= 0 )
return V_68 ;
V_192 = F_121 ( 0 , & V_8 -> V_305 , F_122 ( struct V_204 , V_192 ) ) ;
if ( F_123 ( V_192 ) != V_8 -> V_305 . V_192 ) {
F_31 ( L_81
L_82 ,
V_192 , V_8 -> V_305 . V_192 ) ;
return - V_306 ;
}
V_198 = F_119 ( V_8 -> V_305 . V_198 ) ;
if ( V_198 > V_307 )
return - V_303 ;
V_199 = F_119 ( V_8 -> V_305 . V_199 ) ;
if ( V_199 > V_308 )
return - V_303 ;
V_178 = F_119 ( V_8 -> V_305 . V_178 ) ;
if ( V_178 > V_309 )
return - V_303 ;
V_197 = F_165 ( V_8 -> V_305 . V_197 ) ;
if ( ( V_310 ) V_197 - ( V_310 ) V_8 -> V_118 < 1 ) {
F_157 ( L_83 ,
F_166 ( V_8 -> V_127 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_197 , V_8 -> V_118 + 1 ) ;
V_8 -> V_245 = - V_198 - V_199 - V_178 -
sizeof( V_179 -> V_181 ) ;
V_8 -> V_246 = V_248 ;
return 0 ;
} else if ( ( V_310 ) V_197 - ( V_310 ) V_8 -> V_118 > 1 ) {
F_31 ( L_84 ,
V_197 , V_8 -> V_118 + 1 ) ;
V_8 -> V_81 = L_85 ;
return - V_306 ;
}
if ( ! V_8 -> V_114 ) {
int V_311 = 0 ;
F_39 ( L_86 , V_8 -> V_305 . type ,
V_198 , V_178 ) ;
V_68 = F_172 ( V_8 , & V_311 ) ;
if ( V_68 < 0 )
return V_68 ;
F_3 ( ! V_8 -> V_114 ^ V_311 ) ;
if ( V_8 -> V_114 && V_178 > V_8 -> V_114 -> V_174 ) {
F_162 ( L_87 ,
V_46 , V_178 , V_8 -> V_114 -> V_174 ) ;
F_70 ( V_8 -> V_114 ) ;
V_8 -> V_114 = NULL ;
V_311 = 1 ;
}
if ( V_311 ) {
F_39 ( L_88 ) ;
V_8 -> V_245 = - V_198 - V_199 - V_178 -
sizeof( V_179 -> V_181 ) ;
V_8 -> V_246 = V_248 ;
V_8 -> V_118 ++ ;
return 0 ;
}
F_3 ( ! V_8 -> V_114 ) ;
F_3 ( V_8 -> V_114 -> V_8 != V_8 ) ;
V_179 = V_8 -> V_114 ;
V_179 -> V_200 . V_105 = 0 ;
if ( V_179 -> V_202 )
V_179 -> V_202 -> V_203 . V_105 = 0 ;
if ( V_178 )
F_114 ( V_8 -> V_114 , V_178 ) ;
}
V_68 = F_169 ( V_8 , & V_179 -> V_200 , V_198 ,
& V_8 -> V_249 ) ;
if ( V_68 <= 0 )
return V_68 ;
if ( V_179 -> V_202 ) {
V_68 = F_169 ( V_8 , & V_179 -> V_202 -> V_203 ,
V_199 ,
& V_8 -> V_250 ) ;
if ( V_68 <= 0 )
return V_68 ;
}
if ( V_178 ) {
V_68 = F_170 ( V_8 ) ;
if ( V_68 <= 0 )
return V_68 ;
}
if ( V_304 )
V_103 = sizeof( V_179 -> V_181 ) ;
else
V_103 = sizeof( V_179 -> V_188 ) ;
V_252 += V_103 ;
V_68 = F_143 ( V_8 , V_252 , V_103 , & V_179 -> V_181 ) ;
if ( V_68 <= 0 )
return V_68 ;
if ( ! V_304 ) {
V_179 -> V_181 . V_9 = V_179 -> V_188 . V_9 ;
V_179 -> V_181 . V_187 = 0 ;
}
F_39 ( L_89 ,
V_179 , V_198 , V_179 -> V_181 . V_205 , V_199 ,
V_179 -> V_181 . V_206 , V_178 , V_179 -> V_181 . V_207 ) ;
if ( V_8 -> V_249 != F_119 ( V_179 -> V_181 . V_205 ) ) {
F_31 ( L_90 ,
V_179 , V_8 -> V_249 , V_179 -> V_181 . V_205 ) ;
return - V_306 ;
}
if ( V_8 -> V_250 != F_119 ( V_179 -> V_181 . V_206 ) ) {
F_31 ( L_91 ,
V_179 , V_8 -> V_250 , V_179 -> V_181 . V_206 ) ;
return - V_306 ;
}
if ( V_239 &&
( V_179 -> V_181 . V_9 & V_242 ) == 0 &&
V_8 -> V_251 != F_119 ( V_179 -> V_181 . V_207 ) ) {
F_31 ( L_92 , V_179 ,
V_8 -> V_251 , F_119 ( V_179 -> V_181 . V_207 ) ) ;
return - V_306 ;
}
if ( V_304 && V_8 -> V_76 -> V_312 &&
V_8 -> V_76 -> V_312 ( V_8 , V_179 ) ) {
F_31 ( L_93 , V_179 ) ;
return - V_306 ;
}
return 1 ;
}
static void F_173 ( struct V_7 * V_8 )
{
struct V_35 * V_87 ;
F_3 ( V_8 -> V_114 -> V_8 != V_8 ) ;
V_8 -> V_114 -> V_8 = NULL ;
V_87 = V_8 -> V_114 ;
V_8 -> V_114 = NULL ;
V_8 -> V_76 -> V_110 ( V_8 ) ;
if ( V_8 -> V_127 . type == 0 )
V_8 -> V_127 = V_87 -> V_196 . V_313 ;
V_8 -> V_118 ++ ;
F_78 ( & V_8 -> V_120 ) ;
F_39 ( L_94 ,
V_87 , F_165 ( V_87 -> V_196 . V_197 ) ,
F_166 ( V_87 -> V_196 . V_313 ) ,
F_120 ( V_87 -> V_196 . type ) ,
F_174 ( F_120 ( V_87 -> V_196 . type ) ) ,
F_119 ( V_87 -> V_196 . V_198 ) ,
F_119 ( V_87 -> V_196 . V_178 ) ,
V_8 -> V_249 , V_8 -> V_250 , V_8 -> V_251 ) ;
V_8 -> V_76 -> V_314 ( V_8 , V_87 ) ;
F_76 ( & V_8 -> V_120 ) ;
}
static int F_175 ( struct V_7 * V_8 )
{
int V_68 = 1 ;
F_39 ( L_95 , V_8 , V_8 -> V_56 ) ;
V_99:
F_39 ( L_96 , V_8 -> V_138 ) ;
if ( V_8 -> V_56 == V_126 ) {
F_3 ( V_8 -> V_50 ) ;
V_8 -> V_56 = V_315 ;
F_89 ( V_8 ) ;
F_130 ( V_8 ) ;
F_137 ( V_8 ) ;
F_3 ( V_8 -> V_114 ) ;
V_8 -> V_246 = V_248 ;
F_39 ( L_97 ,
V_8 , V_8 -> V_56 ) ;
V_68 = F_51 ( V_8 ) ;
if ( V_68 < 0 ) {
V_8 -> V_81 = L_20 ;
goto V_238;
}
}
V_316:
if ( V_8 -> V_243 ) {
V_68 = F_136 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_238;
}
if ( V_8 -> V_137 ) {
V_68 = F_133 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_238;
}
if ( V_8 -> V_117 ) {
if ( V_8 -> V_191 ) {
F_70 ( V_8 -> V_117 ) ;
V_8 -> V_117 = NULL ;
goto V_317;
}
V_68 = F_135 ( V_8 ) ;
if ( V_68 == 1 )
goto V_316;
if ( V_68 == 0 )
goto V_238;
if ( V_68 < 0 ) {
F_39 ( L_98 ,
V_68 ) ;
goto V_238;
}
}
V_317:
if ( V_8 -> V_56 == V_294 ) {
if ( ! F_72 ( & V_8 -> V_112 ) ) {
F_116 ( V_8 ) ;
goto V_99;
}
if ( V_8 -> V_118 > V_8 -> V_119 ) {
F_124 ( V_8 ) ;
goto V_99;
}
if ( F_9 ( V_8 , V_3 ) ) {
F_126 ( V_8 ) ;
goto V_99;
}
}
F_2 ( V_8 , V_4 ) ;
F_39 ( L_99 ) ;
V_68 = 0 ;
V_238:
F_39 ( L_100 , V_8 , V_68 ) ;
return V_68 ;
}
static int F_176 ( struct V_7 * V_8 )
{
int V_68 = - 1 ;
V_99:
F_39 ( L_101 , V_8 , V_8 -> V_56 ) ;
if ( V_8 -> V_56 != V_315 &&
V_8 -> V_56 != V_218 &&
V_8 -> V_56 != V_294 )
return 0 ;
F_3 ( ! V_8 -> V_50 ) ;
F_39 ( L_102 , ( int ) V_8 -> V_246 ,
V_8 -> V_245 ) ;
if ( V_8 -> V_56 == V_315 ) {
F_39 ( L_103 ) ;
V_68 = F_144 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_238;
V_68 = F_160 ( V_8 ) ;
if ( V_68 < 0 )
goto V_238;
V_8 -> V_56 = V_218 ;
V_68 = F_131 ( V_8 ) ;
if ( V_68 < 0 )
goto V_238;
F_138 ( V_8 ) ;
goto V_238;
}
if ( V_8 -> V_56 == V_218 ) {
F_39 ( L_104 ) ;
V_68 = F_145 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_238;
V_68 = F_163 ( V_8 ) ;
if ( V_68 < 0 )
goto V_238;
goto V_99;
}
F_37 ( V_8 -> V_56 != V_294 ) ;
if ( V_8 -> V_245 < 0 ) {
static char V_82 [ V_318 ] ;
int V_311 = F_93 ( ( int ) sizeof ( V_82 ) , - V_8 -> V_245 ) ;
F_39 ( L_105 , V_311 , - V_8 -> V_245 ) ;
V_68 = F_57 ( V_8 -> V_50 , V_82 , V_311 ) ;
if ( V_68 <= 0 )
goto V_238;
V_8 -> V_245 += V_68 ;
if ( V_8 -> V_245 )
goto V_99;
}
if ( V_8 -> V_246 == V_248 ) {
V_68 = F_57 ( V_8 -> V_50 , & V_8 -> V_246 , 1 ) ;
if ( V_68 <= 0 )
goto V_238;
F_39 ( L_106 , ( int ) V_8 -> V_246 ) ;
switch ( V_8 -> V_246 ) {
case V_319 :
F_142 ( V_8 ) ;
break;
case V_320 :
F_139 ( V_8 ) ;
break;
case V_321 :
F_67 ( V_8 ) ;
V_8 -> V_56 = V_121 ;
goto V_238;
default:
goto V_322;
}
}
if ( V_8 -> V_246 == V_319 ) {
V_68 = F_171 ( V_8 ) ;
if ( V_68 <= 0 ) {
switch ( V_68 ) {
case - V_306 :
V_8 -> V_81 = L_107 ;
V_68 = - V_303 ;
break;
case - V_303 :
V_8 -> V_81 = L_108 ;
break;
}
goto V_238;
}
if ( V_8 -> V_246 == V_248 )
goto V_99;
F_173 ( V_8 ) ;
if ( V_8 -> V_56 == V_294 )
F_141 ( V_8 ) ;
goto V_99;
}
if ( V_8 -> V_246 == V_320 ||
V_8 -> V_246 == V_247 ) {
V_68 = F_167 ( V_8 ) ;
if ( V_68 <= 0 )
goto V_238;
F_168 ( V_8 ) ;
goto V_99;
}
V_238:
F_39 ( L_109 , V_8 , V_68 ) ;
return V_68 ;
V_322:
F_31 ( L_110 , ( int ) V_8 -> V_246 ) ;
V_8 -> V_81 = L_111 ;
V_68 = - 1 ;
goto V_238;
}
static int F_177 ( struct V_7 * V_8 , unsigned long V_129 )
{
if ( ! V_8 -> V_76 -> V_323 ( V_8 ) ) {
F_39 ( L_112 , V_46 , V_8 ) ;
return - V_324 ;
}
if ( ! F_178 ( V_39 , & V_8 -> V_132 , V_129 ) ) {
F_39 ( L_113 , V_46 , V_8 ) ;
V_8 -> V_76 -> V_110 ( V_8 ) ;
return - V_325 ;
}
F_39 ( L_114 , V_46 , V_8 , V_129 ) ;
return 0 ;
}
static void F_46 ( struct V_7 * V_8 )
{
( void ) F_177 ( V_8 , 0 ) ;
}
static void F_77 ( struct V_7 * V_8 )
{
if ( F_179 ( & V_8 -> V_132 ) ) {
F_39 ( L_115 , V_46 , V_8 ) ;
V_8 -> V_76 -> V_110 ( V_8 ) ;
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
CASE ( V_326 ) ;
CASE ( V_327 ) ;
CASE ( V_328 ) ;
CASE ( V_329 ) ;
CASE ( V_330 ) ;
CASE ( V_331 ) ;
default:
F_162 ( L_116 ,
V_46 , V_8 , V_8 -> V_56 ) ;
V_8 -> V_81 = L_117 ;
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
V_68 = F_177 ( V_8 , F_182 ( V_8 -> V_129 ) ) ;
if ( V_68 ) {
F_39 ( L_118 , V_46 ,
V_8 , V_8 -> V_129 ) ;
F_3 ( V_68 == - V_324 ) ;
F_5 ( V_8 , V_6 ) ;
}
return true ;
}
static void F_183 ( struct V_7 * V_8 )
{
if ( V_8 -> V_217 && V_8 -> V_76 -> V_332 ) {
F_39 ( L_119 ) ;
V_8 -> V_76 -> V_332 ( V_8 ) ;
}
if ( V_8 -> V_76 -> V_333 )
V_8 -> V_76 -> V_333 ( V_8 ) ;
}
static void V_133 ( struct V_334 * V_132 )
{
struct V_7 * V_8 = F_184 ( V_132 , struct V_7 ,
V_132 . V_132 ) ;
unsigned long V_335 = V_336 -> V_9 ;
bool V_333 ;
V_336 -> V_9 |= V_337 ;
F_76 ( & V_8 -> V_120 ) ;
while ( true ) {
int V_68 ;
if ( ( V_333 = F_180 ( V_8 ) ) ) {
F_39 ( L_120 , V_46 , V_8 ) ;
break;
}
if ( F_181 ( V_8 ) ) {
F_39 ( L_121 , V_46 , V_8 ) ;
break;
}
if ( V_8 -> V_56 == V_338 ) {
F_39 ( L_122 , V_46 , V_8 ) ;
break;
}
if ( V_8 -> V_56 == V_121 ) {
F_39 ( L_123 , V_46 , V_8 ) ;
F_3 ( V_8 -> V_50 ) ;
break;
}
if ( V_8 -> V_56 == V_126 ) {
F_39 ( L_124 , V_46 , V_8 ) ;
F_3 ( V_8 -> V_50 ) ;
}
V_68 = F_176 ( V_8 ) ;
if ( V_68 < 0 ) {
if ( V_68 == - V_92 )
continue;
V_8 -> V_81 = L_125 ;
V_333 = true ;
break;
}
V_68 = F_175 ( V_8 ) ;
if ( V_68 < 0 ) {
if ( V_68 == - V_92 )
continue;
V_8 -> V_81 = L_126 ;
V_333 = true ;
}
break;
}
if ( V_333 )
F_185 ( V_8 ) ;
F_78 ( & V_8 -> V_120 ) ;
if ( V_333 )
F_183 ( V_8 ) ;
V_8 -> V_76 -> V_110 ( V_8 ) ;
F_186 ( V_336 , V_335 , V_337 ) ;
}
static void F_185 ( struct V_7 * V_8 )
{
F_162 ( L_127 , F_166 ( V_8 -> V_127 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) , V_8 -> V_81 ) ;
F_39 ( L_128 ,
V_8 , V_8 -> V_56 , F_13 ( & V_8 -> V_66 . V_67 ) ) ;
F_37 ( V_8 -> V_56 != V_315 &&
V_8 -> V_56 != V_218 &&
V_8 -> V_56 != V_294 ) ;
F_67 ( V_8 ) ;
if ( F_7 ( V_8 , V_2 ) ) {
F_39 ( L_129 ) ;
V_8 -> V_56 = V_121 ;
return;
}
if ( V_8 -> V_114 ) {
F_3 ( V_8 -> V_114 -> V_8 != V_8 ) ;
V_8 -> V_114 -> V_8 = NULL ;
F_70 ( V_8 -> V_114 ) ;
V_8 -> V_114 = NULL ;
V_8 -> V_76 -> V_110 ( V_8 ) ;
}
F_187 ( & V_8 -> V_113 , & V_8 -> V_112 ) ;
if ( F_72 ( & V_8 -> V_112 ) &&
! F_7 ( V_8 , V_3 ) ) {
F_39 ( L_130 , V_8 ) ;
F_2 ( V_8 , V_4 ) ;
V_8 -> V_56 = V_338 ;
} else {
V_8 -> V_56 = V_126 ;
if ( V_8 -> V_129 == 0 )
V_8 -> V_129 = V_339 ;
else if ( V_8 -> V_129 < V_340 )
V_8 -> V_129 *= 2 ;
F_5 ( V_8 , V_6 ) ;
F_46 ( V_8 ) ;
}
}
void F_188 ( struct V_29 * V_30 ,
struct V_125 * V_341 ,
V_162 V_232 ,
V_162 V_285 ,
bool V_240 )
{
V_30 -> V_232 = V_232 ;
V_30 -> V_285 = V_285 ;
F_189 ( & V_30 -> V_135 ) ;
if ( V_341 )
V_30 -> V_32 . V_33 = * V_341 ;
V_30 -> V_32 . V_33 . type = 0 ;
F_190 ( & V_30 -> V_32 . V_33 . V_282 , sizeof( V_30 -> V_32 . V_33 . V_282 ) ) ;
F_16 ( V_30 ) ;
V_30 -> V_240 = V_240 ;
F_191 ( & V_30 -> V_53 , 0 ) ;
F_39 ( L_115 , V_46 , V_30 ) ;
}
static void F_192 ( struct V_7 * V_8 )
{
if ( V_8 -> V_56 == V_338 ) {
F_39 ( L_131 , V_8 ) ;
V_8 -> V_56 = V_126 ;
V_8 -> V_115 ++ ;
F_37 ( F_7 ( V_8 , V_4 ) ) ;
F_37 ( F_7 ( V_8 , V_3 ) ) ;
}
}
void F_193 ( struct V_7 * V_8 , struct V_35 * V_87 )
{
V_87 -> V_196 . V_313 = V_8 -> V_30 -> V_32 . V_269 ;
F_3 ( V_87 -> V_200 . V_105 != F_119 ( V_87 -> V_196 . V_198 ) ) ;
V_87 -> V_195 = true ;
F_76 ( & V_8 -> V_120 ) ;
if ( V_8 -> V_56 == V_121 ) {
F_39 ( L_132 , V_8 , V_87 ) ;
F_70 ( V_87 ) ;
F_78 ( & V_8 -> V_120 ) ;
return;
}
F_3 ( V_87 -> V_8 != NULL ) ;
V_87 -> V_8 = V_8 -> V_76 -> V_323 ( V_8 ) ;
F_3 ( V_87 -> V_8 == NULL ) ;
F_3 ( ! F_72 ( & V_87 -> V_109 ) ) ;
F_194 ( & V_87 -> V_109 , & V_8 -> V_112 ) ;
F_39 ( L_133 , V_87 ,
F_166 ( V_8 -> V_127 ) , F_120 ( V_87 -> V_196 . type ) ,
F_174 ( F_120 ( V_87 -> V_196 . type ) ) ,
F_119 ( V_87 -> V_196 . V_198 ) ,
F_119 ( V_87 -> V_196 . V_199 ) ,
F_119 ( V_87 -> V_196 . V_178 ) ) ;
F_192 ( V_8 ) ;
F_78 ( & V_8 -> V_120 ) ;
if ( F_11 ( V_8 , V_4 ) == 0 )
F_46 ( V_8 ) ;
}
void F_195 ( struct V_35 * V_87 )
{
struct V_7 * V_8 = V_87 -> V_8 ;
if ( ! V_8 )
return;
F_76 ( & V_8 -> V_120 ) ;
if ( ! F_72 ( & V_87 -> V_109 ) ) {
F_39 ( L_134 , V_46 , V_8 , V_87 ) ;
F_69 ( & V_87 -> V_109 ) ;
F_3 ( V_87 -> V_8 == NULL ) ;
V_87 -> V_8 -> V_76 -> V_110 ( V_87 -> V_8 ) ;
V_87 -> V_8 = NULL ;
V_87 -> V_196 . V_197 = 0 ;
F_70 ( V_87 ) ;
}
if ( V_8 -> V_117 == V_87 ) {
F_39 ( L_135 , V_46 , V_8 , V_87 ) ;
V_8 -> V_117 = NULL ;
if ( V_8 -> V_183 ) {
V_8 -> V_243 = V_8 -> V_138 ;
V_8 -> V_183 = false ;
}
V_87 -> V_196 . V_197 = 0 ;
F_70 ( V_87 ) ;
}
F_78 ( & V_8 -> V_120 ) ;
}
void F_196 ( struct V_35 * V_87 )
{
struct V_7 * V_8 ;
F_3 ( V_87 == NULL ) ;
if ( ! V_87 -> V_8 ) {
F_39 ( L_136 , V_46 , V_87 ) ;
return;
}
V_8 = V_87 -> V_8 ;
F_76 ( & V_8 -> V_120 ) ;
if ( V_8 -> V_114 == V_87 ) {
unsigned int V_198 = F_119 ( V_8 -> V_305 . V_198 ) ;
unsigned int V_199 = F_119 ( V_8 -> V_305 . V_199 ) ;
unsigned int V_178 = F_119 ( V_8 -> V_305 . V_178 ) ;
F_39 ( L_137 , V_46 , V_8 , V_87 ) ;
V_8 -> V_245 = V_8 -> V_245 -
sizeof( struct V_204 ) -
V_198 -
V_199 -
V_178 -
sizeof( struct V_342 ) ;
F_70 ( V_8 -> V_114 ) ;
V_8 -> V_114 = NULL ;
V_8 -> V_246 = V_248 ;
V_8 -> V_118 ++ ;
} else {
F_39 ( L_138 ,
V_46 , V_8 , V_8 -> V_114 , V_87 ) ;
}
F_78 ( & V_8 -> V_120 ) ;
}
void F_197 ( struct V_7 * V_8 )
{
F_39 ( L_139 , V_8 ) ;
F_76 ( & V_8 -> V_120 ) ;
F_192 ( V_8 ) ;
F_78 ( & V_8 -> V_120 ) ;
if ( F_11 ( V_8 , V_3 ) == 0 &&
F_11 ( V_8 , V_4 ) == 0 )
F_46 ( V_8 ) ;
}
static struct V_38 * F_198 ( enum V_343 type )
{
struct V_38 * V_141 ;
if ( F_37 ( ! F_199 ( type ) ) )
return NULL ;
V_141 = F_200 ( V_37 , V_72 ) ;
if ( V_141 )
V_141 -> type = type ;
F_84 ( & V_141 -> V_176 ) ;
return V_141 ;
}
static void F_201 ( struct V_38 * V_141 )
{
if ( ! V_141 )
return;
F_37 ( ! F_72 ( & V_141 -> V_176 ) ) ;
if ( V_141 -> type == V_169 )
F_202 ( V_141 -> V_168 ) ;
F_203 ( V_37 , V_141 ) ;
}
void F_204 ( struct V_35 * V_87 , struct V_93 * * V_160 ,
T_1 V_95 , T_1 V_161 )
{
struct V_38 * V_141 ;
F_3 ( ! V_160 ) ;
F_3 ( ! V_95 ) ;
V_141 = F_198 ( V_159 ) ;
F_3 ( ! V_141 ) ;
V_141 -> V_160 = V_160 ;
V_141 -> V_95 = V_95 ;
V_141 -> V_161 = V_161 & ~ V_163 ;
F_194 ( & V_141 -> V_176 , & V_87 -> V_141 ) ;
V_87 -> V_174 += V_95 ;
}
void F_205 ( struct V_35 * V_87 ,
struct V_167 * V_168 )
{
struct V_38 * V_141 ;
F_3 ( ! V_168 ) ;
F_3 ( ! V_168 -> V_95 ) ;
V_141 = F_198 ( V_169 ) ;
F_3 ( ! V_141 ) ;
V_141 -> V_168 = V_168 ;
F_194 ( & V_141 -> V_176 , & V_87 -> V_141 ) ;
V_87 -> V_174 += V_168 -> V_95 ;
}
void F_206 ( struct V_35 * V_87 , struct V_145 * V_145 ,
T_1 V_95 )
{
struct V_38 * V_141 ;
F_3 ( ! V_145 ) ;
V_141 = F_198 ( V_146 ) ;
F_3 ( ! V_141 ) ;
V_141 -> V_145 = V_145 ;
V_141 -> V_148 = V_95 ;
F_194 ( & V_141 -> V_176 , & V_87 -> V_141 ) ;
V_87 -> V_174 += V_95 ;
}
struct V_35 * F_207 ( int type , int V_198 , T_6 V_9 ,
bool V_344 )
{
struct V_35 * V_179 ;
V_179 = F_200 ( V_34 , V_9 ) ;
if ( V_179 == NULL )
goto V_238;
V_179 -> V_196 . type = F_208 ( type ) ;
V_179 -> V_196 . V_345 = F_208 ( V_346 ) ;
V_179 -> V_196 . V_198 = F_123 ( V_198 ) ;
F_84 ( & V_179 -> V_109 ) ;
F_209 ( & V_179 -> V_347 ) ;
F_84 ( & V_179 -> V_141 ) ;
if ( V_198 ) {
V_179 -> V_200 . V_104 = F_210 ( V_198 , V_9 ) ;
if ( V_179 -> V_200 . V_104 == NULL ) {
F_39 ( L_140 ,
V_198 ) ;
goto V_348;
}
} else {
V_179 -> V_200 . V_104 = NULL ;
}
V_179 -> V_349 = V_179 -> V_200 . V_105 = V_198 ;
F_39 ( L_141 , V_179 , V_198 ) ;
return V_179 ;
V_348:
F_70 ( V_179 ) ;
V_238:
if ( ! V_344 ) {
F_31 ( L_142 , type ,
V_198 ) ;
F_37 ( 1 ) ;
} else {
F_39 ( L_142 , type ,
V_198 ) ;
}
return NULL ;
}
static int F_211 ( struct V_7 * V_8 , struct V_35 * V_87 )
{
int type = F_120 ( V_87 -> V_196 . type ) ;
int V_199 = F_119 ( V_87 -> V_196 . V_199 ) ;
F_39 ( L_143 , V_87 , type ,
F_174 ( type ) , V_199 ) ;
F_3 ( ! V_199 ) ;
F_3 ( V_87 -> V_202 ) ;
V_87 -> V_202 = F_212 ( V_199 , V_72 ) ;
if ( ! V_87 -> V_202 )
return - V_36 ;
return 0 ;
}
static int F_172 ( struct V_7 * V_8 , int * V_311 )
{
struct V_204 * V_196 = & V_8 -> V_305 ;
int V_199 = F_119 ( V_196 -> V_199 ) ;
struct V_35 * V_87 ;
int V_68 = 0 ;
F_3 ( V_8 -> V_114 != NULL ) ;
F_3 ( ! V_8 -> V_76 -> V_350 ) ;
F_78 ( & V_8 -> V_120 ) ;
V_87 = V_8 -> V_76 -> V_350 ( V_8 , V_196 , V_311 ) ;
F_76 ( & V_8 -> V_120 ) ;
if ( V_8 -> V_56 != V_294 ) {
if ( V_87 )
F_70 ( V_87 ) ;
return - V_92 ;
}
if ( V_87 ) {
F_3 ( * V_311 ) ;
V_8 -> V_114 = V_87 ;
V_8 -> V_114 -> V_8 = V_8 -> V_76 -> V_323 ( V_8 ) ;
F_3 ( V_8 -> V_114 -> V_8 == NULL ) ;
} else {
if ( * V_311 )
return 0 ;
V_8 -> V_81 = L_144 ;
return - V_36 ;
}
memcpy ( & V_8 -> V_114 -> V_196 , & V_8 -> V_305 , sizeof( V_8 -> V_305 ) ) ;
if ( V_199 && ! V_8 -> V_114 -> V_202 ) {
V_68 = F_211 ( V_8 , V_8 -> V_114 ) ;
if ( V_68 < 0 ) {
F_70 ( V_8 -> V_114 ) ;
V_8 -> V_114 = NULL ;
}
}
return V_68 ;
}
static void F_213 ( struct V_35 * V_179 )
{
F_39 ( L_115 , V_46 , V_179 ) ;
F_214 ( V_179 -> V_200 . V_104 ) ;
F_203 ( V_34 , V_179 ) ;
}
static void F_215 ( struct V_347 * V_347 )
{
struct V_35 * V_179 = F_184 ( V_347 , struct V_35 , V_347 ) ;
F_216 ( V_141 ) ;
struct V_109 * V_176 ;
struct V_109 * V_351 ;
F_39 ( L_115 , V_46 , V_179 ) ;
F_37 ( ! F_72 ( & V_179 -> V_109 ) ) ;
if ( V_179 -> V_202 ) {
F_217 ( V_179 -> V_202 ) ;
V_179 -> V_202 = NULL ;
}
F_187 ( & V_179 -> V_141 , & V_141 ) ;
F_218 (links, next, &data) {
struct V_38 * V_141 ;
V_141 = F_219 ( V_176 , struct V_38 , V_176 ) ;
F_69 ( V_176 ) ;
F_201 ( V_141 ) ;
}
V_179 -> V_174 = 0 ;
if ( V_179 -> V_352 )
F_220 ( V_179 -> V_352 , V_179 ) ;
else
F_213 ( V_179 ) ;
}
struct V_35 * F_117 ( struct V_35 * V_87 )
{
F_39 ( L_145 , V_46 , V_87 ,
F_45 ( & V_87 -> V_347 . V_353 ) ) ;
F_221 ( & V_87 -> V_347 ) ;
return V_87 ;
}
void F_70 ( struct V_35 * V_87 )
{
F_39 ( L_145 , V_46 , V_87 ,
F_45 ( & V_87 -> V_347 . V_353 ) ) ;
F_222 ( & V_87 -> V_347 , F_215 ) ;
}
void F_223 ( struct V_35 * V_87 )
{
F_224 ( L_146 , V_87 ,
V_87 -> V_349 , V_87 -> V_174 ) ;
F_225 ( V_354 , L_147 ,
V_355 , 16 , 1 ,
& V_87 -> V_196 , sizeof( V_87 -> V_196 ) , true ) ;
F_225 ( V_354 , L_148 ,
V_355 , 16 , 1 ,
V_87 -> V_200 . V_104 , V_87 -> V_200 . V_105 , true ) ;
if ( V_87 -> V_202 )
F_225 ( V_354 , L_149 ,
V_355 , 16 , 1 ,
V_87 -> V_202 -> V_203 . V_104 ,
V_87 -> V_202 -> V_203 . V_105 , true ) ;
F_225 ( V_354 , L_150 ,
V_355 , 16 , 1 ,
& V_87 -> V_181 , sizeof( V_87 -> V_181 ) , true ) ;
}
