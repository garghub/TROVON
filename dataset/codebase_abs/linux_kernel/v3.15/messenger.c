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
static void F_44 ( struct V_49 * V_50 )
{
struct V_7 * V_8 = V_50 -> V_51 ;
if ( F_45 ( & V_8 -> V_30 -> V_52 ) ) {
return;
}
if ( V_50 -> V_53 != V_54 ) {
F_39 ( L_10 , V_45 ,
V_8 , V_8 -> V_55 ) ;
F_46 ( V_8 ) ;
}
}
static void F_47 ( struct V_49 * V_50 )
{
struct V_7 * V_8 = V_50 -> V_51 ;
if ( F_7 ( V_8 , V_4 ) ) {
if ( F_48 ( V_50 ) ) {
F_39 ( L_11 , V_45 , V_8 ) ;
F_4 ( V_56 , & V_50 -> V_57 -> V_9 ) ;
F_46 ( V_8 ) ;
}
} else {
F_39 ( L_12 , V_45 , V_8 ) ;
}
}
static void F_49 ( struct V_49 * V_50 )
{
struct V_7 * V_8 = V_50 -> V_51 ;
F_39 ( L_13 , V_45 ,
V_8 , V_8 -> V_55 , V_50 -> V_53 ) ;
switch ( V_50 -> V_53 ) {
case V_58 :
F_39 ( L_14 , V_45 ) ;
case V_54 :
F_39 ( L_15 , V_45 ) ;
F_42 ( V_8 ) ;
F_5 ( V_8 , V_5 ) ;
F_46 ( V_8 ) ;
break;
case V_59 :
F_39 ( L_16 , V_45 ) ;
F_41 ( V_8 ) ;
F_46 ( V_8 ) ;
break;
default:
break;
}
}
static void F_50 ( struct V_60 * V_49 ,
struct V_7 * V_8 )
{
struct V_49 * V_50 = V_49 -> V_50 ;
V_50 -> V_51 = V_8 ;
V_50 -> V_61 = F_44 ;
V_50 -> V_62 = F_47 ;
V_50 -> V_63 = F_49 ;
}
static int F_51 ( struct V_7 * V_8 )
{
struct V_10 * V_64 = & V_8 -> V_65 . V_66 ;
struct V_60 * V_49 ;
int V_67 ;
F_3 ( V_8 -> V_49 ) ;
V_67 = F_52 ( V_8 -> V_65 . V_66 . V_21 , V_68 ,
V_69 , & V_49 ) ;
if ( V_67 )
return V_67 ;
V_49 -> V_50 -> V_70 = V_71 ;
#ifdef F_53
F_54 ( & V_49 -> V_50 -> V_72 , & V_73 ) ;
#endif
F_50 ( V_49 , V_8 ) ;
F_39 ( L_17 , F_13 ( & V_8 -> V_65 . V_66 ) ) ;
F_40 ( V_8 ) ;
V_67 = V_49 -> V_74 -> V_75 ( V_49 , (struct V_76 * ) V_64 , sizeof( * V_64 ) ,
V_77 ) ;
if ( V_67 == - V_78 ) {
F_39 ( L_18 ,
F_13 ( & V_8 -> V_65 . V_66 ) ,
V_49 -> V_50 -> V_53 ) ;
} else if ( V_67 < 0 ) {
F_31 ( L_19 ,
F_13 ( & V_8 -> V_65 . V_66 ) , V_67 ) ;
F_55 ( V_49 ) ;
V_8 -> V_79 = L_20 ;
return V_67 ;
}
V_8 -> V_49 = V_49 ;
return 0 ;
}
static int F_56 ( struct V_60 * V_49 , void * V_80 , T_1 V_81 )
{
struct V_82 V_83 = { V_80 , V_81 } ;
struct V_84 V_85 = { . V_86 = V_87 | V_88 } ;
int V_89 ;
V_89 = F_57 ( V_49 , & V_85 , & V_83 , 1 , V_81 , V_85 . V_86 ) ;
if ( V_89 == - V_90 )
V_89 = 0 ;
return V_89 ;
}
static int F_58 ( struct V_60 * V_49 , struct V_91 * V_91 ,
int V_92 , T_1 V_93 )
{
void * V_94 ;
int V_67 ;
F_3 ( V_92 + V_93 > V_95 ) ;
V_94 = F_59 ( V_91 ) ;
F_3 ( ! V_94 ) ;
V_67 = F_56 ( V_49 , V_94 + V_92 , V_93 ) ;
F_25 ( V_91 ) ;
return V_67 ;
}
static int F_60 ( struct V_60 * V_49 , struct V_82 * V_83 ,
T_1 V_96 , T_1 V_81 , int V_97 )
{
struct V_84 V_85 = { . V_86 = V_87 | V_88 } ;
int V_89 ;
if ( V_97 )
V_85 . V_86 |= V_98 ;
else
V_85 . V_86 |= V_99 ;
V_89 = F_61 ( V_49 , & V_85 , V_83 , V_96 , V_81 ) ;
if ( V_89 == - V_90 )
V_89 = 0 ;
return V_89 ;
}
static int F_62 ( struct V_60 * V_49 , struct V_91 * V_91 ,
int V_100 , T_1 V_101 , bool V_97 )
{
int V_9 = V_87 | V_88 | ( V_97 ? V_98 : V_99 ) ;
int V_67 ;
V_67 = F_63 ( V_49 , V_91 , V_100 , V_101 , V_9 ) ;
if ( V_67 == - V_90 )
V_67 = 0 ;
return V_67 ;
}
static int F_64 ( struct V_60 * V_49 , struct V_91 * V_91 ,
int V_100 , T_1 V_101 , bool V_97 )
{
int V_67 ;
struct V_82 V_83 ;
if ( F_65 ( V_91 ) >= 1 )
return F_62 ( V_49 , V_91 , V_100 , V_101 , V_97 ) ;
V_83 . V_102 = F_59 ( V_91 ) + V_100 ;
V_83 . V_103 = V_101 ;
V_67 = F_60 ( V_49 , & V_83 , 1 , V_101 , V_97 ) ;
F_25 ( V_91 ) ;
return V_67 ;
}
static int F_66 ( struct V_7 * V_8 )
{
int V_104 = 0 ;
F_39 ( L_21 , V_8 , V_8 -> V_49 ) ;
if ( V_8 -> V_49 ) {
V_104 = V_8 -> V_49 -> V_74 -> V_105 ( V_8 -> V_49 , V_106 ) ;
F_55 ( V_8 -> V_49 ) ;
V_8 -> V_49 = NULL ;
}
F_2 ( V_8 , V_5 ) ;
F_43 ( V_8 ) ;
return V_104 ;
}
static void F_67 ( struct V_35 * V_85 )
{
F_68 ( & V_85 -> V_107 ) ;
F_3 ( V_85 -> V_8 == NULL ) ;
V_85 -> V_8 -> V_74 -> V_108 ( V_85 -> V_8 ) ;
V_85 -> V_8 = NULL ;
F_69 ( V_85 ) ;
}
static void F_70 ( struct V_107 * V_109 )
{
while ( ! F_71 ( V_109 ) ) {
struct V_35 * V_85 = F_72 ( V_109 , struct V_35 ,
V_107 ) ;
F_67 ( V_85 ) ;
}
}
static void F_73 ( struct V_7 * V_8 )
{
F_39 ( L_22 , V_8 ) ;
F_70 ( & V_8 -> V_110 ) ;
F_70 ( & V_8 -> V_111 ) ;
if ( V_8 -> V_112 ) {
F_3 ( V_8 -> V_112 -> V_8 != V_8 ) ;
V_8 -> V_112 -> V_8 = NULL ;
F_69 ( V_8 -> V_112 ) ;
V_8 -> V_112 = NULL ;
V_8 -> V_74 -> V_108 ( V_8 ) ;
}
V_8 -> V_113 = 0 ;
V_8 -> V_114 = 0 ;
if ( V_8 -> V_115 ) {
F_69 ( V_8 -> V_115 ) ;
V_8 -> V_115 = NULL ;
}
V_8 -> V_116 = 0 ;
V_8 -> V_117 = 0 ;
}
void F_74 ( struct V_7 * V_8 )
{
F_75 ( & V_8 -> V_118 ) ;
F_39 ( L_23 , V_8 ,
F_13 ( & V_8 -> V_65 . V_66 ) ) ;
V_8 -> V_55 = V_119 ;
F_2 ( V_8 , V_2 ) ;
F_2 ( V_8 , V_3 ) ;
F_2 ( V_8 , V_4 ) ;
F_2 ( V_8 , V_6 ) ;
F_73 ( V_8 ) ;
V_8 -> V_120 = 0 ;
F_76 ( & V_8 -> V_121 ) ;
F_66 ( V_8 ) ;
F_77 ( & V_8 -> V_118 ) ;
}
void F_78 ( struct V_7 * V_8 ,
T_2 V_122 , T_3 V_123 ,
struct V_124 * V_33 )
{
F_75 ( & V_8 -> V_118 ) ;
F_39 ( L_24 , V_8 , F_13 ( & V_33 -> V_66 ) ) ;
F_37 ( V_8 -> V_55 != V_119 ) ;
V_8 -> V_55 = V_125 ;
V_8 -> V_126 . type = ( T_2 ) V_122 ;
V_8 -> V_126 . V_127 = F_79 ( V_123 ) ;
memcpy ( & V_8 -> V_65 , V_33 , sizeof( * V_33 ) ) ;
V_8 -> V_128 = 0 ;
F_77 ( & V_8 -> V_118 ) ;
F_46 ( V_8 ) ;
}
bool F_80 ( struct V_7 * V_8 )
{
return V_8 -> V_113 > 0 ;
}
void F_81 ( struct V_7 * V_8 , void * V_129 ,
const struct V_130 * V_74 ,
struct V_29 * V_30 )
{
F_39 ( L_25 , V_8 ) ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> V_129 = V_129 ;
V_8 -> V_74 = V_74 ;
V_8 -> V_30 = V_30 ;
F_35 ( V_8 ) ;
F_82 ( & V_8 -> V_118 ) ;
F_83 ( & V_8 -> V_110 ) ;
F_83 ( & V_8 -> V_111 ) ;
F_84 ( & V_8 -> V_121 , V_131 ) ;
V_8 -> V_55 = V_119 ;
}
static T_4 F_85 ( struct V_29 * V_30 , T_4 V_132 )
{
T_4 V_67 ;
F_86 ( & V_30 -> V_133 ) ;
if ( V_30 -> V_134 < V_132 )
V_30 -> V_134 = V_132 ;
V_67 = ++ V_30 -> V_134 ;
F_87 ( & V_30 -> V_133 ) ;
return V_67 ;
}
static void F_88 ( struct V_7 * V_8 )
{
V_8 -> V_135 = 0 ;
V_8 -> V_136 = 0 ;
V_8 -> V_137 = & V_8 -> V_138 [ 0 ] ;
}
static void F_89 ( struct V_7 * V_8 ,
T_1 V_101 , void * V_139 )
{
int V_140 ;
V_140 = V_8 -> V_135 ;
F_3 ( V_140 >= F_90 ( V_8 -> V_138 ) ) ;
V_8 -> V_138 [ V_140 ] . V_103 = V_101 ;
V_8 -> V_138 [ V_140 ] . V_102 = V_139 ;
V_8 -> V_135 ++ ;
V_8 -> V_136 += V_101 ;
}
static void F_91 ( struct V_141 * V_142 ,
T_1 V_93 )
{
struct V_38 * V_139 = V_142 -> V_139 ;
struct V_143 * V_143 ;
F_3 ( V_139 -> type != V_144 ) ;
V_143 = V_139 -> V_143 ;
F_3 ( ! V_143 ) ;
V_142 -> V_145 = F_92 ( V_93 , V_139 -> V_146 ) ;
V_142 -> V_143 = V_143 ;
V_142 -> V_147 = V_143 -> V_148 ;
V_142 -> V_149 =
V_142 -> V_145 <= F_93 ( V_143 , V_142 -> V_147 ) ;
}
static struct V_91 * F_94 ( struct V_141 * V_142 ,
T_1 * V_92 ,
T_1 * V_93 )
{
struct V_38 * V_139 = V_142 -> V_139 ;
struct V_143 * V_143 ;
struct V_150 V_150 ;
F_3 ( V_139 -> type != V_144 ) ;
V_143 = V_142 -> V_143 ;
F_3 ( ! V_143 ) ;
V_150 = F_95 ( V_143 , V_142 -> V_147 ) ;
* V_92 = ( T_1 ) V_150 . V_151 ;
F_3 ( * V_92 >= V_95 ) ;
if ( V_142 -> V_149 )
* V_93 = V_142 -> V_145 ;
else
* V_93 = ( T_1 ) V_150 . V_152 ;
F_3 ( * V_93 > V_142 -> V_145 ) ;
F_3 ( * V_92 + * V_93 > V_95 ) ;
return V_150 . V_153 ;
}
static bool F_96 ( struct V_141 * V_142 ,
T_1 V_154 )
{
struct V_143 * V_143 ;
struct V_150 V_150 ;
F_3 ( V_142 -> V_139 -> type != V_144 ) ;
V_143 = V_142 -> V_143 ;
F_3 ( ! V_143 ) ;
V_150 = F_95 ( V_143 , V_142 -> V_147 ) ;
F_3 ( V_142 -> V_145 < V_154 ) ;
V_142 -> V_145 -= V_154 ;
F_97 ( V_143 , & V_142 -> V_147 , V_154 ) ;
if ( V_154 < V_150 . V_152 )
return false ;
if ( ! V_142 -> V_147 . V_155 ) {
V_143 = V_143 -> V_156 ;
V_142 -> V_143 = V_143 ;
if ( V_143 )
V_142 -> V_147 = V_143 -> V_148 ;
else
memset ( & V_142 -> V_147 , 0 ,
sizeof( V_142 -> V_147 ) ) ;
}
if ( ! V_142 -> V_149 ) {
F_3 ( ! V_142 -> V_145 ) ;
F_3 ( ! V_143 ) ;
if ( V_142 -> V_145 <= F_93 ( V_143 , V_142 -> V_147 ) )
V_142 -> V_149 = true ;
}
return true ;
}
static void F_98 ( struct V_141 * V_142 ,
T_1 V_93 )
{
struct V_38 * V_139 = V_142 -> V_139 ;
int F_65 ;
F_3 ( V_139 -> type != V_157 ) ;
F_3 ( ! V_139 -> V_158 ) ;
F_3 ( ! V_139 -> V_93 ) ;
V_142 -> V_145 = F_92 ( V_93 , V_139 -> V_93 ) ;
F_65 = F_99 ( V_139 -> V_159 , ( V_160 ) V_139 -> V_93 ) ;
V_142 -> V_92 = V_139 -> V_159 & ~ V_161 ;
V_142 -> V_162 = 0 ;
F_3 ( F_65 > ( int ) V_163 ) ;
V_142 -> F_65 = ( unsigned short ) F_65 ;
F_3 ( V_93 > V_164 - V_142 -> V_92 ) ;
V_142 -> V_149 = ( T_1 ) V_142 -> V_92 + V_93 <= V_95 ;
}
static struct V_91 *
F_100 ( struct V_141 * V_142 ,
T_1 * V_92 , T_1 * V_93 )
{
struct V_38 * V_139 = V_142 -> V_139 ;
F_3 ( V_139 -> type != V_157 ) ;
F_3 ( V_142 -> V_162 >= V_142 -> F_65 ) ;
F_3 ( V_142 -> V_92 >= V_95 ) ;
* V_92 = V_142 -> V_92 ;
if ( V_142 -> V_149 )
* V_93 = V_142 -> V_145 ;
else
* V_93 = V_95 - * V_92 ;
return V_139 -> V_158 [ V_142 -> V_162 ] ;
}
static bool F_101 ( struct V_141 * V_142 ,
T_1 V_154 )
{
F_3 ( V_142 -> V_139 -> type != V_157 ) ;
F_3 ( V_142 -> V_92 + V_154 > V_95 ) ;
V_142 -> V_145 -= V_154 ;
V_142 -> V_92 = ( V_142 -> V_92 + V_154 ) & ~ V_161 ;
if ( ! V_154 || V_142 -> V_92 )
return false ;
if ( ! V_142 -> V_145 )
return false ;
F_3 ( V_142 -> V_162 >= V_142 -> F_65 ) ;
V_142 -> V_162 ++ ;
V_142 -> V_149 = V_142 -> V_145 <= V_95 ;
return true ;
}
static void
F_102 ( struct V_141 * V_142 ,
T_1 V_93 )
{
struct V_38 * V_139 = V_142 -> V_139 ;
struct V_165 * V_166 ;
struct V_91 * V_91 ;
F_3 ( V_139 -> type != V_167 ) ;
V_166 = V_139 -> V_166 ;
F_3 ( ! V_166 ) ;
if ( ! V_93 )
return;
F_3 ( F_71 ( & V_166 -> V_109 ) ) ;
V_91 = F_72 ( & V_166 -> V_109 , struct V_91 , V_168 ) ;
V_142 -> V_145 = F_92 ( V_93 , V_166 -> V_93 ) ;
V_142 -> V_91 = V_91 ;
V_142 -> V_100 = 0 ;
V_142 -> V_149 = V_142 -> V_145 <= V_95 ;
}
static struct V_91 *
F_103 ( struct V_141 * V_142 ,
T_1 * V_92 , T_1 * V_93 )
{
struct V_38 * V_139 = V_142 -> V_139 ;
struct V_165 * V_166 ;
F_3 ( V_139 -> type != V_167 ) ;
V_166 = V_139 -> V_166 ;
F_3 ( ! V_166 ) ;
F_3 ( ! V_142 -> V_91 ) ;
F_3 ( V_142 -> V_100 + V_142 -> V_145 != V_166 -> V_93 ) ;
* V_92 = V_142 -> V_100 & ~ V_161 ;
if ( V_142 -> V_149 )
* V_93 = V_142 -> V_145 ;
else
* V_93 = V_95 - * V_92 ;
return V_142 -> V_91 ;
}
static bool F_104 ( struct V_141 * V_142 ,
T_1 V_154 )
{
struct V_38 * V_139 = V_142 -> V_139 ;
struct V_165 * V_166 ;
F_3 ( V_139 -> type != V_167 ) ;
V_166 = V_139 -> V_166 ;
F_3 ( ! V_166 ) ;
F_3 ( V_142 -> V_100 + V_142 -> V_145 != V_166 -> V_93 ) ;
F_3 ( ( V_142 -> V_100 & ~ V_161 ) + V_154 > V_95 ) ;
V_142 -> V_145 -= V_154 ;
V_142 -> V_100 += V_154 ;
if ( ! V_154 || V_142 -> V_100 & ~ V_161 )
return false ;
if ( ! V_142 -> V_145 )
return false ;
F_3 ( F_105 ( & V_142 -> V_91 -> V_168 , & V_166 -> V_109 ) ) ;
V_142 -> V_91 = F_106 ( V_142 -> V_91 , V_168 ) ;
V_142 -> V_149 = V_142 -> V_145 <= V_95 ;
return true ;
}
static void F_107 ( struct V_141 * V_142 )
{
T_1 V_93 = V_142 -> V_169 ;
switch ( V_142 -> V_139 -> type ) {
case V_167 :
F_102 ( V_142 , V_93 ) ;
break;
case V_157 :
F_98 ( V_142 , V_93 ) ;
break;
#ifdef F_108
case V_144 :
F_91 ( V_142 , V_93 ) ;
break;
#endif
case V_170 :
default:
break;
}
V_142 -> V_171 = true ;
}
static void F_109 ( struct V_35 * V_85 , T_1 V_93 )
{
struct V_141 * V_142 = & V_85 -> V_142 ;
struct V_38 * V_139 ;
F_3 ( ! V_93 ) ;
F_3 ( V_93 > V_85 -> V_172 ) ;
F_3 ( F_71 ( & V_85 -> V_139 ) ) ;
V_142 -> V_173 = & V_85 -> V_139 ;
V_142 -> V_169 = V_93 ;
V_139 = F_72 ( & V_85 -> V_139 , struct V_38 , V_174 ) ;
V_142 -> V_139 = V_139 ;
F_107 ( V_142 ) ;
}
static struct V_91 * F_110 ( struct V_141 * V_142 ,
T_1 * V_92 , T_1 * V_93 ,
bool * V_149 )
{
struct V_91 * V_91 ;
switch ( V_142 -> V_139 -> type ) {
case V_167 :
V_91 = F_103 ( V_142 , V_92 , V_93 ) ;
break;
case V_157 :
V_91 = F_100 ( V_142 , V_92 , V_93 ) ;
break;
#ifdef F_108
case V_144 :
V_91 = F_94 ( V_142 , V_92 , V_93 ) ;
break;
#endif
case V_170 :
default:
V_91 = NULL ;
break;
}
F_3 ( ! V_91 ) ;
F_3 ( * V_92 + * V_93 > V_95 ) ;
F_3 ( ! * V_93 ) ;
if ( V_149 )
* V_149 = V_142 -> V_149 ;
return V_91 ;
}
static bool F_111 ( struct V_141 * V_142 ,
T_1 V_154 )
{
bool V_175 ;
F_3 ( V_154 > V_142 -> V_145 ) ;
switch ( V_142 -> V_139 -> type ) {
case V_167 :
V_175 = F_104 ( V_142 , V_154 ) ;
break;
case V_157 :
V_175 = F_101 ( V_142 , V_154 ) ;
break;
#ifdef F_108
case V_144 :
V_175 = F_96 ( V_142 , V_154 ) ;
break;
#endif
case V_170 :
default:
F_112 () ;
break;
}
V_142 -> V_169 -= V_154 ;
if ( ! V_142 -> V_145 && V_142 -> V_169 ) {
F_37 ( ! V_142 -> V_149 ) ;
F_3 ( F_105 ( & V_142 -> V_139 -> V_174 , V_142 -> V_173 ) ) ;
V_142 -> V_139 = F_106 ( V_142 -> V_139 , V_174 ) ;
F_107 ( V_142 ) ;
V_175 = true ;
}
V_142 -> V_171 = V_175 ;
return V_175 ;
}
static void F_113 ( struct V_35 * V_85 , T_4 V_176 )
{
F_3 ( ! V_85 ) ;
F_3 ( ! V_176 ) ;
F_109 ( V_85 , ( T_1 ) V_176 ) ;
}
static void F_114 ( struct V_7 * V_8 )
{
struct V_35 * V_177 = V_8 -> V_115 ;
int V_178 = V_8 -> V_135 ;
V_177 -> V_179 . V_9 |= V_180 ;
F_39 ( L_26 , V_8 ) ;
V_8 -> V_181 = true ;
V_8 -> V_138 [ V_178 ] . V_102 = & V_177 -> V_179 ;
V_8 -> V_138 [ V_178 ] . V_103 = sizeof( V_177 -> V_179 ) ;
V_8 -> V_136 += sizeof( V_177 -> V_179 ) ;
V_8 -> V_135 ++ ;
V_8 -> V_182 = V_177 -> V_183 ;
V_8 -> V_184 = true ;
}
static void F_115 ( struct V_7 * V_8 )
{
struct V_35 * V_177 ;
T_4 V_185 ;
F_88 ( V_8 ) ;
V_8 -> V_181 = true ;
V_8 -> V_184 = false ;
if ( V_8 -> V_116 > V_8 -> V_117 ) {
V_8 -> V_117 = V_8 -> V_116 ;
F_89 ( V_8 , sizeof ( V_186 ) , & V_186 ) ;
V_8 -> V_187 = F_79 ( V_8 -> V_117 ) ;
F_89 ( V_8 , sizeof ( V_8 -> V_187 ) ,
& V_8 -> V_187 ) ;
}
F_3 ( F_71 ( & V_8 -> V_110 ) ) ;
V_177 = F_72 ( & V_8 -> V_110 , struct V_35 , V_107 ) ;
V_8 -> V_115 = V_177 ;
F_3 ( V_177 -> V_8 != V_8 ) ;
F_116 ( V_177 ) ;
F_117 ( & V_177 -> V_107 , & V_8 -> V_111 ) ;
if ( V_177 -> V_188 ) {
V_177 -> V_189 . V_190 = F_79 ( ++ V_8 -> V_114 ) ;
V_177 -> V_188 = false ;
}
F_37 ( V_177 -> V_172 != F_118 ( V_177 -> V_189 . V_176 ) ) ;
F_39 ( L_27 ,
V_177 , V_8 -> V_114 , F_119 ( V_177 -> V_189 . type ) ,
F_118 ( V_177 -> V_189 . V_191 ) , F_118 ( V_177 -> V_189 . V_192 ) ,
V_177 -> V_172 ) ;
F_3 ( F_118 ( V_177 -> V_189 . V_191 ) != V_177 -> V_193 . V_103 ) ;
F_89 ( V_8 , sizeof ( V_194 ) , & V_194 ) ;
F_89 ( V_8 , sizeof ( V_177 -> V_189 ) , & V_177 -> V_189 ) ;
F_89 ( V_8 , V_177 -> V_193 . V_103 , V_177 -> V_193 . V_102 ) ;
if ( V_177 -> V_195 )
F_89 ( V_8 , V_177 -> V_195 -> V_196 . V_103 ,
V_177 -> V_195 -> V_196 . V_102 ) ;
V_185 = F_120 ( 0 , & V_177 -> V_189 , F_121 ( struct V_197 , V_185 ) ) ;
V_8 -> V_115 -> V_189 . V_185 = F_122 ( V_185 ) ;
V_8 -> V_115 -> V_179 . V_9 = 0 ;
V_185 = F_120 ( 0 , V_177 -> V_193 . V_102 , V_177 -> V_193 . V_103 ) ;
V_8 -> V_115 -> V_179 . V_198 = F_122 ( V_185 ) ;
if ( V_177 -> V_195 ) {
V_185 = F_120 ( 0 , V_177 -> V_195 -> V_196 . V_102 ,
V_177 -> V_195 -> V_196 . V_103 ) ;
V_8 -> V_115 -> V_179 . V_199 = F_122 ( V_185 ) ;
} else
V_8 -> V_115 -> V_179 . V_199 = 0 ;
F_39 ( L_28 , V_45 ,
F_118 ( V_8 -> V_115 -> V_179 . V_198 ) ,
F_118 ( V_8 -> V_115 -> V_179 . V_199 ) ) ;
V_8 -> V_115 -> V_179 . V_200 = 0 ;
if ( V_177 -> V_172 ) {
F_113 ( V_8 -> V_115 , V_177 -> V_172 ) ;
V_8 -> V_182 = 1 ;
} else {
F_114 ( V_8 ) ;
}
F_5 ( V_8 , V_4 ) ;
}
static void F_123 ( struct V_7 * V_8 )
{
F_39 ( L_29 , V_8 ,
V_8 -> V_117 , V_8 -> V_116 ) ;
V_8 -> V_117 = V_8 -> V_116 ;
F_88 ( V_8 ) ;
F_89 ( V_8 , sizeof ( V_186 ) , & V_186 ) ;
V_8 -> V_187 = F_79 ( V_8 -> V_117 ) ;
F_89 ( V_8 , sizeof ( V_8 -> V_187 ) ,
& V_8 -> V_187 ) ;
V_8 -> V_182 = 1 ;
F_5 ( V_8 , V_4 ) ;
}
static void F_124 ( struct V_7 * V_8 )
{
F_39 ( L_30 , V_8 ,
V_8 -> V_117 , V_8 -> V_116 ) ;
V_8 -> V_117 = V_8 -> V_116 ;
F_88 ( V_8 ) ;
V_8 -> V_187 = F_79 ( V_8 -> V_117 ) ;
F_89 ( V_8 , sizeof ( V_8 -> V_187 ) ,
& V_8 -> V_187 ) ;
F_5 ( V_8 , V_4 ) ;
}
static void F_125 ( struct V_7 * V_8 )
{
F_39 ( L_31 , V_8 ) ;
F_88 ( V_8 ) ;
F_89 ( V_8 , sizeof ( V_201 ) , & V_201 ) ;
F_5 ( V_8 , V_4 ) ;
}
static struct V_202 * F_126 ( struct V_7 * V_8 ,
int * V_203 )
{
struct V_202 * V_204 ;
if ( ! V_8 -> V_74 -> V_205 ) {
V_8 -> V_206 . V_207 = V_208 ;
V_8 -> V_206 . V_209 = 0 ;
return NULL ;
}
F_77 ( & V_8 -> V_118 ) ;
V_204 = V_8 -> V_74 -> V_205 ( V_8 , V_203 , V_8 -> V_210 ) ;
F_75 ( & V_8 -> V_118 ) ;
if ( F_127 ( V_204 ) )
return V_204 ;
if ( V_8 -> V_55 != V_211 )
return F_128 ( - V_90 ) ;
V_8 -> V_212 = V_204 -> V_213 ;
V_8 -> V_214 = V_204 -> V_215 ;
return V_204 ;
}
static void F_129 ( struct V_7 * V_8 )
{
F_89 ( V_8 , strlen ( V_216 ) , V_216 ) ;
F_89 ( V_8 , sizeof ( V_8 -> V_30 -> V_31 ) ,
& V_8 -> V_30 -> V_31 ) ;
V_8 -> V_182 = 0 ;
F_5 ( V_8 , V_4 ) ;
}
static int F_130 ( struct V_7 * V_8 )
{
unsigned int V_134 = F_85 ( V_8 -> V_30 , 0 ) ;
int V_217 ;
int V_203 ;
struct V_202 * V_204 ;
switch ( V_8 -> V_126 . type ) {
case V_218 :
V_217 = V_219 ;
break;
case V_220 :
V_217 = V_221 ;
break;
case V_222 :
V_217 = V_223 ;
break;
default:
F_112 () ;
}
F_39 ( L_32 , V_8 ,
V_8 -> V_113 , V_134 , V_217 ) ;
V_8 -> V_206 . V_224 = F_79 ( V_8 -> V_30 -> V_225 ) ;
V_8 -> V_206 . V_226 = F_122 ( V_227 ) ;
V_8 -> V_206 . V_113 = F_122 ( V_8 -> V_113 ) ;
V_8 -> V_206 . V_134 = F_122 ( V_134 ) ;
V_8 -> V_206 . V_228 = F_122 ( V_217 ) ;
V_8 -> V_206 . V_9 = 0 ;
V_203 = V_208 ;
V_204 = F_126 ( V_8 , & V_203 ) ;
if ( F_127 ( V_204 ) )
return F_131 ( V_204 ) ;
V_8 -> V_206 . V_207 = F_122 ( V_203 ) ;
V_8 -> V_206 . V_209 = V_204 ?
F_122 ( V_204 -> V_229 ) : 0 ;
F_89 ( V_8 , sizeof ( V_8 -> V_206 ) ,
& V_8 -> V_206 ) ;
if ( V_204 && V_204 -> V_229 )
F_89 ( V_8 , V_204 -> V_229 ,
V_204 -> V_230 ) ;
V_8 -> V_182 = 0 ;
F_5 ( V_8 , V_4 ) ;
return 0 ;
}
static int F_132 ( struct V_7 * V_8 )
{
int V_67 ;
F_39 ( L_33 , V_8 , V_8 -> V_136 ) ;
while ( V_8 -> V_136 > 0 ) {
V_67 = F_60 ( V_8 -> V_49 , V_8 -> V_137 ,
V_8 -> V_135 , V_8 -> V_136 ,
V_8 -> V_182 ) ;
if ( V_67 <= 0 )
goto V_231;
V_8 -> V_136 -= V_67 ;
if ( V_8 -> V_136 == 0 )
break;
while ( V_67 >= V_8 -> V_137 -> V_103 ) {
F_3 ( ! V_8 -> V_135 ) ;
V_67 -= V_8 -> V_137 -> V_103 ;
V_8 -> V_137 ++ ;
V_8 -> V_135 -- ;
}
if ( V_67 ) {
V_8 -> V_137 -> V_103 -= V_67 ;
V_8 -> V_137 -> V_102 += V_67 ;
}
}
V_8 -> V_135 = 0 ;
V_8 -> V_181 = false ;
V_67 = 1 ;
V_231:
F_39 ( L_34 , V_8 ,
V_8 -> V_136 , V_8 -> V_135 , V_67 ) ;
return V_67 ;
}
static T_4 F_133 ( T_4 V_185 , struct V_91 * V_91 ,
unsigned int V_92 ,
unsigned int V_93 )
{
char * V_94 ;
V_94 = F_59 ( V_91 ) ;
F_3 ( V_94 == NULL ) ;
V_185 = F_120 ( V_185 , V_94 + V_92 , V_93 ) ;
F_25 ( V_91 ) ;
return V_185 ;
}
static int F_134 ( struct V_7 * V_8 )
{
struct V_35 * V_85 = V_8 -> V_115 ;
struct V_141 * V_142 = & V_85 -> V_142 ;
bool V_232 = ! V_8 -> V_30 -> V_233 ;
T_4 V_185 ;
F_39 ( L_35 , V_45 , V_8 , V_85 ) ;
if ( F_71 ( & V_85 -> V_139 ) )
return - V_234 ;
V_185 = V_232 ? F_118 ( V_85 -> V_179 . V_200 ) : 0 ;
while ( V_142 -> V_145 ) {
struct V_91 * V_91 ;
T_1 V_92 ;
T_1 V_93 ;
bool V_149 ;
bool V_171 ;
int V_67 ;
V_91 = F_110 ( & V_85 -> V_142 , & V_92 , & V_93 ,
& V_149 ) ;
V_67 = F_64 ( V_8 -> V_49 , V_91 , V_92 ,
V_93 , V_149 ) ;
if ( V_67 <= 0 ) {
if ( V_232 )
V_85 -> V_179 . V_200 = F_122 ( V_185 ) ;
return V_67 ;
}
if ( V_232 && V_142 -> V_171 )
V_185 = F_133 ( V_185 , V_91 , V_92 , V_93 ) ;
V_171 = F_111 ( & V_85 -> V_142 , ( T_1 ) V_67 ) ;
}
F_39 ( L_36 , V_45 , V_8 , V_85 ) ;
if ( V_232 )
V_85 -> V_179 . V_200 = F_122 ( V_185 ) ;
else
V_85 -> V_179 . V_9 |= V_235 ;
F_88 ( V_8 ) ;
F_114 ( V_8 ) ;
return 1 ;
}
static int F_135 ( struct V_7 * V_8 )
{
int V_67 ;
while ( V_8 -> V_236 > 0 ) {
T_1 V_101 = F_92 ( V_8 -> V_236 , ( int ) V_237 ) ;
V_67 = F_64 ( V_8 -> V_49 , V_40 , 0 , V_101 , true ) ;
if ( V_67 <= 0 )
goto V_231;
V_8 -> V_236 -= V_67 ;
}
V_67 = 1 ;
V_231:
return V_67 ;
}
static void F_136 ( struct V_7 * V_8 )
{
F_39 ( L_37 , V_8 ) ;
V_8 -> V_238 = 0 ;
}
static void F_137 ( struct V_7 * V_8 )
{
F_39 ( L_38 , V_8 ) ;
V_8 -> V_238 = 0 ;
}
static void F_138 ( struct V_7 * V_8 )
{
F_39 ( L_39 , V_8 ) ;
V_8 -> V_238 = 0 ;
}
static void F_139 ( struct V_7 * V_8 )
{
F_39 ( L_40 , V_8 ) ;
V_8 -> V_238 = 0 ;
V_8 -> V_239 = V_240 ;
}
static void F_140 ( struct V_7 * V_8 )
{
F_39 ( L_41 , V_8 ) ;
V_8 -> V_238 = 0 ;
V_8 -> V_239 = V_241 ;
}
static int F_141 ( struct V_7 * V_8 )
{
F_39 ( L_42 , V_8 ) ;
F_3 ( V_8 -> V_112 != NULL ) ;
V_8 -> V_238 = 0 ;
V_8 -> V_242 = V_8 -> V_243 = V_8 -> V_244 = 0 ;
return 0 ;
}
static int F_142 ( struct V_7 * V_8 ,
int V_245 , int V_101 , void * V_246 )
{
while ( V_8 -> V_238 < V_245 ) {
int V_247 = V_245 - V_8 -> V_238 ;
int V_248 = V_101 - V_247 ;
int V_67 = F_56 ( V_8 -> V_49 , V_246 + V_248 , V_247 ) ;
if ( V_67 <= 0 )
return V_67 ;
V_8 -> V_238 += V_67 ;
}
return 1 ;
}
static int F_143 ( struct V_7 * V_8 )
{
int V_101 ;
int V_245 ;
int V_67 ;
F_39 ( L_43 , V_8 , V_8 -> V_238 ) ;
V_101 = strlen ( V_216 ) ;
V_245 = V_101 ;
V_67 = F_142 ( V_8 , V_245 , V_101 , V_8 -> V_249 ) ;
if ( V_67 <= 0 )
goto V_231;
V_101 = sizeof ( V_8 -> V_250 ) ;
V_245 += V_101 ;
V_67 = F_142 ( V_8 , V_245 , V_101 , & V_8 -> V_250 ) ;
if ( V_67 <= 0 )
goto V_231;
V_101 = sizeof ( V_8 -> V_251 ) ;
V_245 += V_101 ;
V_67 = F_142 ( V_8 , V_245 , V_101 , & V_8 -> V_251 ) ;
if ( V_67 <= 0 )
goto V_231;
V_231:
return V_67 ;
}
static int F_144 ( struct V_7 * V_8 )
{
int V_101 ;
int V_245 ;
int V_67 ;
F_39 ( L_44 , V_8 , V_8 -> V_238 ) ;
V_101 = sizeof ( V_8 -> V_252 ) ;
V_245 = V_101 ;
V_67 = F_142 ( V_8 , V_245 , V_101 , & V_8 -> V_252 ) ;
if ( V_67 <= 0 )
goto V_231;
V_101 = F_118 ( V_8 -> V_252 . V_209 ) ;
V_245 += V_101 ;
V_67 = F_142 ( V_8 , V_245 , V_101 , V_8 -> V_212 ) ;
if ( V_67 <= 0 )
goto V_231;
F_39 ( L_45 ,
V_8 , ( int ) V_8 -> V_252 . V_253 ,
F_118 ( V_8 -> V_252 . V_113 ) ,
F_118 ( V_8 -> V_252 . V_134 ) ) ;
V_231:
return V_67 ;
}
static int F_145 ( struct V_7 * V_8 )
{
if ( memcmp ( V_8 -> V_249 , V_216 , strlen ( V_216 ) ) ) {
F_31 ( L_46 ,
F_13 ( & V_8 -> V_65 . V_66 ) ) ;
V_8 -> V_79 = L_47 ;
return - 1 ;
}
return 0 ;
}
static bool F_146 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_21 ) {
case V_22 :
return ( (struct V_14 * ) V_11 ) -> V_24 . V_254 == 0 ;
case V_26 :
return
( (struct V_16 * ) V_11 ) -> V_27 . V_255 [ 0 ] == 0 &&
( (struct V_16 * ) V_11 ) -> V_27 . V_255 [ 1 ] == 0 &&
( (struct V_16 * ) V_11 ) -> V_27 . V_255 [ 2 ] == 0 &&
( (struct V_16 * ) V_11 ) -> V_27 . V_255 [ 3 ] == 0 ;
}
return false ;
}
static int F_147 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_21 ) {
case V_22 :
return F_15 ( ( (struct V_14 * ) V_11 ) -> V_25 ) ;
case V_26 :
return F_15 ( ( (struct V_16 * ) V_11 ) -> V_28 ) ;
}
return 0 ;
}
static void F_148 ( struct V_10 * V_11 , int V_256 )
{
switch ( V_11 -> V_21 ) {
case V_22 :
( (struct V_14 * ) V_11 ) -> V_25 = F_149 ( V_256 ) ;
break;
case V_26 :
( (struct V_16 * ) V_11 ) -> V_28 = F_149 ( V_256 ) ;
break;
}
}
static int F_150 ( const char * V_257 , T_1 V_81 , struct V_10 * V_11 ,
char V_258 , const char * * V_259 )
{
struct V_14 * V_15 = (struct V_14 * ) V_11 ;
struct V_16 * V_17 = (struct V_16 * ) V_11 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
if ( F_151 ( V_257 , V_81 , ( V_260 * ) & V_15 -> V_24 . V_254 , V_258 , V_259 ) ) {
V_11 -> V_21 = V_22 ;
return 0 ;
}
if ( F_152 ( V_257 , V_81 , ( V_260 * ) & V_17 -> V_27 . V_261 , V_258 , V_259 ) ) {
V_11 -> V_21 = V_26 ;
return 0 ;
}
return - V_234 ;
}
static int F_153 ( const char * V_262 , T_1 V_263 ,
struct V_10 * V_11 , char V_258 , const char * * V_259 )
{
const char * V_245 , * V_264 ;
char * V_265 , * V_266 = NULL ;
int V_267 , V_67 ;
V_264 = memchr ( V_262 , V_258 , V_263 ) ;
V_265 = memchr ( V_262 , ':' , V_263 ) ;
if ( V_264 && V_265 )
V_245 = V_264 < V_265 ? V_264 : V_265 ;
else if ( ! V_264 && V_265 )
V_245 = V_265 ;
else {
V_245 = V_264 ;
if ( ! V_245 )
V_245 = V_262 + V_263 ;
}
if ( V_245 <= V_262 )
return - V_234 ;
V_267 = F_154 ( NULL , V_262 , V_245 - V_262 , NULL , & V_266 , NULL ) ;
if ( V_267 > 0 )
V_67 = F_150 ( V_266 , V_267 , V_11 , - 1 , NULL ) ;
else
V_67 = - V_268 ;
F_155 ( V_266 ) ;
* V_259 = V_245 ;
F_156 ( L_48 , ( int ) ( V_245 - V_262 ) , V_262 ,
V_67 , V_67 ? L_49 : F_13 ( V_11 ) ) ;
return V_67 ;
}
static inline int F_153 ( const char * V_262 , T_1 V_263 ,
struct V_10 * V_11 , char V_258 , const char * * V_259 )
{
return - V_234 ;
}
static int F_157 ( const char * V_262 , T_1 V_263 ,
struct V_10 * V_11 , char V_258 , const char * * V_259 )
{
int V_67 ;
V_67 = F_150 ( V_262 , V_263 , V_11 , V_258 , V_259 ) ;
if ( V_67 )
V_67 = F_153 ( V_262 , V_263 , V_11 , V_258 , V_259 ) ;
return V_67 ;
}
int F_158 ( const char * V_269 , const char * V_245 ,
struct V_124 * V_33 ,
int V_270 , int * V_271 )
{
int V_12 , V_67 = - V_234 ;
const char * V_256 = V_269 ;
F_39 ( L_50 , ( int ) ( V_245 - V_269 ) , V_269 ) ;
for ( V_12 = 0 ; V_12 < V_270 ; V_12 ++ ) {
const char * V_259 ;
struct V_10 * V_11 = & V_33 [ V_12 ] . V_66 ;
int V_272 ;
char V_258 = ',' ;
if ( * V_256 == '[' ) {
V_258 = ']' ;
V_256 ++ ;
}
V_67 = F_157 ( V_256 , V_245 - V_256 , V_11 , V_258 , & V_259 ) ;
if ( V_67 )
goto V_273;
V_67 = - V_234 ;
V_256 = V_259 ;
if ( V_258 == ']' ) {
if ( * V_256 != ']' ) {
F_39 ( L_51 ) ;
goto V_273;
}
V_256 ++ ;
}
if ( V_256 < V_245 && * V_256 == ':' ) {
V_272 = 0 ;
V_256 ++ ;
while ( V_256 < V_245 && * V_256 >= '0' && * V_256 <= '9' ) {
V_272 = ( V_272 * 10 ) + ( * V_256 - '0' ) ;
V_256 ++ ;
}
if ( V_272 == 0 )
V_272 = V_274 ;
else if ( V_272 > 65535 )
goto V_273;
} else {
V_272 = V_274 ;
}
F_148 ( V_11 , V_272 ) ;
F_39 ( L_52 , F_13 ( V_11 ) ) ;
if ( V_256 == V_245 )
break;
if ( * V_256 != ',' )
goto V_273;
V_256 ++ ;
}
if ( V_256 != V_245 )
goto V_273;
if ( V_271 )
* V_271 = V_12 + 1 ;
return 0 ;
V_273:
F_31 ( L_53 , ( int ) ( V_245 - V_269 ) , V_269 ) ;
return V_67 ;
}
static int F_159 ( struct V_7 * V_8 )
{
F_39 ( L_54 , V_8 ) ;
if ( F_145 ( V_8 ) < 0 )
return - 1 ;
F_160 ( & V_8 -> V_250 ) ;
F_160 ( & V_8 -> V_251 ) ;
if ( memcmp ( & V_8 -> V_65 , & V_8 -> V_250 ,
sizeof( V_8 -> V_65 ) ) != 0 &&
! ( F_146 ( & V_8 -> V_250 . V_66 ) &&
V_8 -> V_250 . V_275 == V_8 -> V_65 . V_275 ) ) {
F_161 ( L_55 ,
F_13 ( & V_8 -> V_65 . V_66 ) ,
( int ) F_118 ( V_8 -> V_65 . V_275 ) ,
F_13 ( & V_8 -> V_250 . V_66 ) ,
( int ) F_118 ( V_8 -> V_250 . V_275 ) ) ;
V_8 -> V_79 = L_56 ;
return - 1 ;
}
if ( F_146 ( & V_8 -> V_30 -> V_32 . V_33 . V_66 ) ) {
int V_272 = F_147 ( & V_8 -> V_30 -> V_32 . V_33 . V_66 ) ;
memcpy ( & V_8 -> V_30 -> V_32 . V_33 . V_66 ,
& V_8 -> V_251 . V_66 ,
sizeof( V_8 -> V_251 . V_66 ) ) ;
F_148 ( & V_8 -> V_30 -> V_32 . V_33 . V_66 , V_272 ) ;
F_16 ( V_8 -> V_30 ) ;
F_39 ( L_57 ,
F_13 ( & V_8 -> V_30 -> V_32 . V_33 . V_66 ) ) ;
}
return 0 ;
}
static int F_162 ( struct V_7 * V_8 )
{
V_160 V_276 = V_8 -> V_30 -> V_225 ;
V_160 V_277 = V_8 -> V_30 -> V_278 ;
V_160 V_279 = F_163 (
F_164 ( V_8 -> V_252 . V_224 ) ) ;
int V_67 ;
F_39 ( L_58 , V_8 , ( int ) V_8 -> V_239 ) ;
switch ( V_8 -> V_252 . V_253 ) {
case V_280 :
F_31 ( L_59
L_60 ,
F_165 ( V_8 -> V_126 ) ,
F_13 ( & V_8 -> V_65 . V_66 ) ,
V_276 , V_279 , V_279 & ~ V_276 ) ;
V_8 -> V_79 = L_61 ;
F_73 ( V_8 ) ;
return - 1 ;
case V_281 :
F_31 ( L_62
L_63 ,
F_165 ( V_8 -> V_126 ) ,
F_13 ( & V_8 -> V_65 . V_66 ) ,
F_118 ( V_8 -> V_206 . V_228 ) ,
F_118 ( V_8 -> V_252 . V_228 ) ) ;
V_8 -> V_79 = L_64 ;
F_73 ( V_8 ) ;
return - 1 ;
case V_282 :
V_8 -> V_210 ++ ;
F_39 ( L_65 , V_8 ,
V_8 -> V_210 ) ;
if ( V_8 -> V_210 == 2 ) {
V_8 -> V_79 = L_66 ;
return - 1 ;
}
F_88 ( V_8 ) ;
V_67 = F_130 ( V_8 ) ;
if ( V_67 < 0 )
return V_67 ;
F_137 ( V_8 ) ;
break;
case V_283 :
F_39 ( L_67 ,
F_118 ( V_8 -> V_252 . V_113 ) ) ;
F_31 ( L_68 ,
F_165 ( V_8 -> V_126 ) ,
F_13 ( & V_8 -> V_65 . V_66 ) ) ;
F_73 ( V_8 ) ;
F_88 ( V_8 ) ;
V_67 = F_130 ( V_8 ) ;
if ( V_67 < 0 )
return V_67 ;
F_137 ( V_8 ) ;
F_77 ( & V_8 -> V_118 ) ;
F_156 ( L_69 , F_165 ( V_8 -> V_126 ) ) ;
if ( V_8 -> V_74 -> V_284 )
V_8 -> V_74 -> V_284 ( V_8 ) ;
F_75 ( & V_8 -> V_118 ) ;
if ( V_8 -> V_55 != V_211 )
return - V_90 ;
break;
case V_285 :
F_39 ( L_70 ,
F_118 ( V_8 -> V_206 . V_113 ) ,
F_118 ( V_8 -> V_252 . V_113 ) ) ;
V_8 -> V_113 = F_118 ( V_8 -> V_252 . V_113 ) ;
F_88 ( V_8 ) ;
V_67 = F_130 ( V_8 ) ;
if ( V_67 < 0 )
return V_67 ;
F_137 ( V_8 ) ;
break;
case V_286 :
F_39 ( L_71 ,
V_8 -> V_120 ,
F_118 ( V_8 -> V_252 . V_134 ) ) ;
F_85 ( V_8 -> V_30 ,
F_118 ( V_8 -> V_252 . V_134 ) ) ;
F_88 ( V_8 ) ;
V_67 = F_130 ( V_8 ) ;
if ( V_67 < 0 )
return V_67 ;
F_137 ( V_8 ) ;
break;
case V_240 :
case V_241 :
if ( V_277 & ~ V_279 ) {
F_31 ( L_72
L_73 ,
F_165 ( V_8 -> V_126 ) ,
F_13 ( & V_8 -> V_65 . V_66 ) ,
V_277 , V_279 , V_277 & ~ V_279 ) ;
V_8 -> V_79 = L_61 ;
F_73 ( V_8 ) ;
return - 1 ;
}
F_37 ( V_8 -> V_55 != V_211 ) ;
V_8 -> V_55 = V_287 ;
V_8 -> V_210 = 0 ;
V_8 -> V_120 = F_118 ( V_8 -> V_252 . V_134 ) ;
V_8 -> V_113 ++ ;
V_8 -> V_288 = V_279 ;
F_39 ( L_74 ,
V_8 -> V_120 ,
F_118 ( V_8 -> V_252 . V_113 ) ,
V_8 -> V_113 ) ;
F_37 ( V_8 -> V_113 !=
F_118 ( V_8 -> V_252 . V_113 ) ) ;
if ( V_8 -> V_252 . V_9 & V_289 )
F_5 ( V_8 , V_2 ) ;
V_8 -> V_128 = 0 ;
if ( V_8 -> V_252 . V_253 == V_240 ) {
F_124 ( V_8 ) ;
F_139 ( V_8 ) ;
} else {
F_140 ( V_8 ) ;
}
break;
case V_290 :
F_31 ( L_75 ) ;
V_8 -> V_79 = L_76 ;
return - 1 ;
default:
F_31 ( L_77 ) ;
V_8 -> V_79 = L_78 ;
return - 1 ;
}
return 0 ;
}
static int F_166 ( struct V_7 * V_8 )
{
int V_101 = sizeof ( V_8 -> V_291 ) ;
int V_245 = V_101 ;
return F_142 ( V_8 , V_245 , V_101 , & V_8 -> V_291 ) ;
}
static void F_167 ( struct V_7 * V_8 )
{
struct V_35 * V_177 ;
V_160 V_292 = F_164 ( V_8 -> V_291 ) ;
V_160 V_190 ;
while ( ! F_71 ( & V_8 -> V_111 ) ) {
V_177 = F_72 ( & V_8 -> V_111 , struct V_35 ,
V_107 ) ;
V_190 = F_164 ( V_177 -> V_189 . V_190 ) ;
if ( V_190 > V_292 )
break;
F_39 ( L_79 , V_190 ,
F_119 ( V_177 -> V_189 . type ) , V_177 ) ;
V_177 -> V_293 = V_294 ;
F_67 ( V_177 ) ;
}
F_140 ( V_8 ) ;
}
static int F_168 ( struct V_7 * V_8 ,
struct V_82 * V_295 ,
unsigned int V_296 , T_4 * V_185 )
{
int V_67 , V_247 ;
F_3 ( ! V_295 ) ;
while ( V_295 -> V_103 < V_296 ) {
F_3 ( V_295 -> V_102 == NULL ) ;
V_247 = V_296 - V_295 -> V_103 ;
V_67 = F_56 ( V_8 -> V_49 , ( char * ) V_295 -> V_102 +
V_295 -> V_103 , V_247 ) ;
if ( V_67 <= 0 )
return V_67 ;
V_295 -> V_103 += V_67 ;
}
if ( V_295 -> V_103 == V_296 )
* V_185 = F_120 ( 0 , V_295 -> V_102 , V_295 -> V_103 ) ;
return 1 ;
}
static int F_169 ( struct V_7 * V_8 )
{
struct V_35 * V_85 = V_8 -> V_112 ;
struct V_141 * V_142 = & V_85 -> V_142 ;
const bool V_232 = ! V_8 -> V_30 -> V_233 ;
struct V_91 * V_91 ;
T_1 V_92 ;
T_1 V_93 ;
T_4 V_185 = 0 ;
int V_67 ;
F_3 ( ! V_85 ) ;
if ( F_71 ( & V_85 -> V_139 ) )
return - V_297 ;
if ( V_232 )
V_185 = V_8 -> V_244 ;
while ( V_142 -> V_145 ) {
V_91 = F_110 ( & V_85 -> V_142 , & V_92 , & V_93 ,
NULL ) ;
V_67 = F_58 ( V_8 -> V_49 , V_91 , V_92 , V_93 ) ;
if ( V_67 <= 0 ) {
if ( V_232 )
V_8 -> V_244 = V_185 ;
return V_67 ;
}
if ( V_232 )
V_185 = F_133 ( V_185 , V_91 , V_92 , V_67 ) ;
( void ) F_111 ( & V_85 -> V_142 , ( T_1 ) V_67 ) ;
}
if ( V_232 )
V_8 -> V_244 = V_185 ;
return 1 ;
}
static int F_170 ( struct V_7 * V_8 )
{
struct V_35 * V_177 = V_8 -> V_112 ;
int V_101 ;
int V_245 ;
int V_67 ;
unsigned int V_191 , V_192 , V_176 ;
bool V_232 = ! V_8 -> V_30 -> V_233 ;
V_160 V_190 ;
T_4 V_185 ;
F_39 ( L_80 , V_8 , V_177 ) ;
V_101 = sizeof ( V_8 -> V_298 ) ;
V_245 = V_101 ;
V_67 = F_142 ( V_8 , V_245 , V_101 , & V_8 -> V_298 ) ;
if ( V_67 <= 0 )
return V_67 ;
V_185 = F_120 ( 0 , & V_8 -> V_298 , F_121 ( struct V_197 , V_185 ) ) ;
if ( F_122 ( V_185 ) != V_8 -> V_298 . V_185 ) {
F_31 ( L_81
L_82 ,
V_185 , V_8 -> V_298 . V_185 ) ;
return - V_299 ;
}
V_191 = F_118 ( V_8 -> V_298 . V_191 ) ;
if ( V_191 > V_300 )
return - V_297 ;
V_192 = F_118 ( V_8 -> V_298 . V_192 ) ;
if ( V_192 > V_301 )
return - V_297 ;
V_176 = F_118 ( V_8 -> V_298 . V_176 ) ;
if ( V_176 > V_302 )
return - V_297 ;
V_190 = F_164 ( V_8 -> V_298 . V_190 ) ;
if ( ( V_303 ) V_190 - ( V_303 ) V_8 -> V_116 < 1 ) {
F_156 ( L_83 ,
F_165 ( V_8 -> V_126 ) ,
F_13 ( & V_8 -> V_65 . V_66 ) ,
V_190 , V_8 -> V_116 + 1 ) ;
V_8 -> V_238 = - V_191 - V_192 - V_176 -
sizeof( V_177 -> V_179 ) ;
V_8 -> V_239 = V_241 ;
return 0 ;
} else if ( ( V_303 ) V_190 - ( V_303 ) V_8 -> V_116 > 1 ) {
F_31 ( L_84 ,
V_190 , V_8 -> V_116 + 1 ) ;
V_8 -> V_79 = L_85 ;
return - V_299 ;
}
if ( ! V_8 -> V_112 ) {
int V_304 = 0 ;
F_39 ( L_86 , V_8 -> V_298 . type ,
V_191 , V_176 ) ;
V_67 = F_171 ( V_8 , & V_304 ) ;
if ( V_67 < 0 )
return V_67 ;
F_3 ( ! V_8 -> V_112 ^ V_304 ) ;
if ( V_8 -> V_112 && V_176 > V_8 -> V_112 -> V_172 ) {
F_161 ( L_87 ,
V_45 , V_176 , V_8 -> V_112 -> V_172 ) ;
F_69 ( V_8 -> V_112 ) ;
V_8 -> V_112 = NULL ;
V_304 = 1 ;
}
if ( V_304 ) {
F_39 ( L_88 ) ;
V_8 -> V_238 = - V_191 - V_192 - V_176 -
sizeof( V_177 -> V_179 ) ;
V_8 -> V_239 = V_241 ;
V_8 -> V_116 ++ ;
return 0 ;
}
F_3 ( ! V_8 -> V_112 ) ;
F_3 ( V_8 -> V_112 -> V_8 != V_8 ) ;
V_177 = V_8 -> V_112 ;
V_177 -> V_193 . V_103 = 0 ;
if ( V_177 -> V_195 )
V_177 -> V_195 -> V_196 . V_103 = 0 ;
if ( V_176 )
F_113 ( V_8 -> V_112 , V_176 ) ;
}
V_67 = F_168 ( V_8 , & V_177 -> V_193 , V_191 ,
& V_8 -> V_242 ) ;
if ( V_67 <= 0 )
return V_67 ;
if ( V_177 -> V_195 ) {
V_67 = F_168 ( V_8 , & V_177 -> V_195 -> V_196 ,
V_192 ,
& V_8 -> V_243 ) ;
if ( V_67 <= 0 )
return V_67 ;
}
if ( V_176 ) {
V_67 = F_169 ( V_8 ) ;
if ( V_67 <= 0 )
return V_67 ;
}
V_101 = sizeof ( V_177 -> V_179 ) ;
V_245 += V_101 ;
V_67 = F_142 ( V_8 , V_245 , V_101 , & V_177 -> V_179 ) ;
if ( V_67 <= 0 )
return V_67 ;
F_39 ( L_89 ,
V_177 , V_191 , V_177 -> V_179 . V_198 , V_192 ,
V_177 -> V_179 . V_199 , V_176 , V_177 -> V_179 . V_200 ) ;
if ( V_8 -> V_242 != F_118 ( V_177 -> V_179 . V_198 ) ) {
F_31 ( L_90 ,
V_177 , V_8 -> V_242 , V_177 -> V_179 . V_198 ) ;
return - V_299 ;
}
if ( V_8 -> V_243 != F_118 ( V_177 -> V_179 . V_199 ) ) {
F_31 ( L_91 ,
V_177 , V_8 -> V_243 , V_177 -> V_179 . V_199 ) ;
return - V_299 ;
}
if ( V_232 &&
( V_177 -> V_179 . V_9 & V_235 ) == 0 &&
V_8 -> V_244 != F_118 ( V_177 -> V_179 . V_200 ) ) {
F_31 ( L_92 , V_177 ,
V_8 -> V_244 , F_118 ( V_177 -> V_179 . V_200 ) ) ;
return - V_299 ;
}
return 1 ;
}
static void F_172 ( struct V_7 * V_8 )
{
struct V_35 * V_85 ;
F_3 ( V_8 -> V_112 -> V_8 != V_8 ) ;
V_8 -> V_112 -> V_8 = NULL ;
V_85 = V_8 -> V_112 ;
V_8 -> V_112 = NULL ;
V_8 -> V_74 -> V_108 ( V_8 ) ;
if ( V_8 -> V_126 . type == 0 )
V_8 -> V_126 = V_85 -> V_189 . V_305 ;
V_8 -> V_116 ++ ;
F_77 ( & V_8 -> V_118 ) ;
F_39 ( L_93 ,
V_85 , F_164 ( V_85 -> V_189 . V_190 ) ,
F_165 ( V_85 -> V_189 . V_305 ) ,
F_119 ( V_85 -> V_189 . type ) ,
F_173 ( F_119 ( V_85 -> V_189 . type ) ) ,
F_118 ( V_85 -> V_189 . V_191 ) ,
F_118 ( V_85 -> V_189 . V_176 ) ,
V_8 -> V_242 , V_8 -> V_243 , V_8 -> V_244 ) ;
V_8 -> V_74 -> V_306 ( V_8 , V_85 ) ;
F_75 ( & V_8 -> V_118 ) ;
}
static int F_174 ( struct V_7 * V_8 )
{
int V_67 = 1 ;
F_39 ( L_94 , V_8 , V_8 -> V_55 ) ;
V_97:
F_39 ( L_95 , V_8 -> V_136 ) ;
if ( V_8 -> V_55 == V_125 ) {
F_3 ( V_8 -> V_49 ) ;
V_8 -> V_55 = V_307 ;
F_88 ( V_8 ) ;
F_129 ( V_8 ) ;
F_136 ( V_8 ) ;
F_3 ( V_8 -> V_112 ) ;
V_8 -> V_239 = V_241 ;
F_39 ( L_96 ,
V_8 , V_8 -> V_55 ) ;
V_67 = F_51 ( V_8 ) ;
if ( V_67 < 0 ) {
V_8 -> V_79 = L_20 ;
goto V_231;
}
}
V_308:
if ( V_8 -> V_236 ) {
V_67 = F_135 ( V_8 ) ;
if ( V_67 <= 0 )
goto V_231;
}
if ( V_8 -> V_135 ) {
V_67 = F_132 ( V_8 ) ;
if ( V_67 <= 0 )
goto V_231;
}
if ( V_8 -> V_115 ) {
if ( V_8 -> V_184 ) {
F_69 ( V_8 -> V_115 ) ;
V_8 -> V_115 = NULL ;
goto V_309;
}
V_67 = F_134 ( V_8 ) ;
if ( V_67 == 1 )
goto V_308;
if ( V_67 == 0 )
goto V_231;
if ( V_67 < 0 ) {
F_39 ( L_97 ,
V_67 ) ;
goto V_231;
}
}
V_309:
if ( V_8 -> V_55 == V_287 ) {
if ( ! F_71 ( & V_8 -> V_110 ) ) {
F_115 ( V_8 ) ;
goto V_97;
}
if ( V_8 -> V_116 > V_8 -> V_117 ) {
F_123 ( V_8 ) ;
goto V_97;
}
if ( F_9 ( V_8 , V_3 ) ) {
F_125 ( V_8 ) ;
goto V_97;
}
}
F_2 ( V_8 , V_4 ) ;
F_39 ( L_98 ) ;
V_67 = 0 ;
V_231:
F_39 ( L_99 , V_8 , V_67 ) ;
return V_67 ;
}
static int F_175 ( struct V_7 * V_8 )
{
int V_67 = - 1 ;
V_97:
F_39 ( L_100 , V_8 , V_8 -> V_55 ) ;
if ( V_8 -> V_55 != V_307 &&
V_8 -> V_55 != V_211 &&
V_8 -> V_55 != V_287 )
return 0 ;
F_3 ( ! V_8 -> V_49 ) ;
F_39 ( L_101 , ( int ) V_8 -> V_239 ,
V_8 -> V_238 ) ;
if ( V_8 -> V_55 == V_307 ) {
F_39 ( L_102 ) ;
V_67 = F_143 ( V_8 ) ;
if ( V_67 <= 0 )
goto V_231;
V_67 = F_159 ( V_8 ) ;
if ( V_67 < 0 )
goto V_231;
V_8 -> V_55 = V_211 ;
V_67 = F_130 ( V_8 ) ;
if ( V_67 < 0 )
goto V_231;
F_137 ( V_8 ) ;
goto V_231;
}
if ( V_8 -> V_55 == V_211 ) {
F_39 ( L_103 ) ;
V_67 = F_144 ( V_8 ) ;
if ( V_67 <= 0 )
goto V_231;
V_67 = F_162 ( V_8 ) ;
if ( V_67 < 0 )
goto V_231;
goto V_97;
}
F_37 ( V_8 -> V_55 != V_287 ) ;
if ( V_8 -> V_238 < 0 ) {
static char V_80 [ V_310 ] ;
int V_304 = F_92 ( ( int ) sizeof ( V_80 ) , - V_8 -> V_238 ) ;
F_39 ( L_104 , V_304 , - V_8 -> V_238 ) ;
V_67 = F_56 ( V_8 -> V_49 , V_80 , V_304 ) ;
if ( V_67 <= 0 )
goto V_231;
V_8 -> V_238 += V_67 ;
if ( V_8 -> V_238 )
goto V_97;
}
if ( V_8 -> V_239 == V_241 ) {
V_67 = F_56 ( V_8 -> V_49 , & V_8 -> V_239 , 1 ) ;
if ( V_67 <= 0 )
goto V_231;
F_39 ( L_105 , ( int ) V_8 -> V_239 ) ;
switch ( V_8 -> V_239 ) {
case V_311 :
F_141 ( V_8 ) ;
break;
case V_312 :
F_138 ( V_8 ) ;
break;
case V_313 :
F_66 ( V_8 ) ;
V_8 -> V_55 = V_119 ;
goto V_231;
default:
goto V_314;
}
}
if ( V_8 -> V_239 == V_311 ) {
V_67 = F_170 ( V_8 ) ;
if ( V_67 <= 0 ) {
switch ( V_67 ) {
case - V_299 :
V_8 -> V_79 = L_106 ;
V_67 = - V_297 ;
break;
case - V_297 :
V_8 -> V_79 = L_107 ;
break;
}
goto V_231;
}
if ( V_8 -> V_239 == V_241 )
goto V_97;
F_172 ( V_8 ) ;
if ( V_8 -> V_55 == V_287 )
F_140 ( V_8 ) ;
goto V_97;
}
if ( V_8 -> V_239 == V_312 ||
V_8 -> V_239 == V_240 ) {
V_67 = F_166 ( V_8 ) ;
if ( V_67 <= 0 )
goto V_231;
F_167 ( V_8 ) ;
goto V_97;
}
V_231:
F_39 ( L_108 , V_8 , V_67 ) ;
return V_67 ;
V_314:
F_31 ( L_109 , ( int ) V_8 -> V_239 ) ;
V_8 -> V_79 = L_110 ;
V_67 = - 1 ;
goto V_231;
}
static int F_176 ( struct V_7 * V_8 , unsigned long V_128 )
{
if ( ! V_8 -> V_74 -> V_315 ( V_8 ) ) {
F_39 ( L_111 , V_45 , V_8 ) ;
return - V_316 ;
}
if ( ! F_177 ( V_39 , & V_8 -> V_121 , V_128 ) ) {
F_39 ( L_112 , V_45 , V_8 ) ;
V_8 -> V_74 -> V_108 ( V_8 ) ;
return - V_317 ;
}
F_39 ( L_113 , V_45 , V_8 , V_128 ) ;
return 0 ;
}
static void F_46 ( struct V_7 * V_8 )
{
( void ) F_176 ( V_8 , 0 ) ;
}
static bool F_178 ( struct V_7 * V_8 )
{
if ( ! F_9 ( V_8 , V_5 ) )
return false ;
#define CASE ( T_5 ) \
case CON_STATE_ ## x: \
con->error_msg = "socket closed (con state " #x ")"; \
break;
switch ( V_8 -> V_55 ) {
CASE ( V_318 ) ;
CASE ( V_319 ) ;
CASE ( V_320 ) ;
CASE ( V_321 ) ;
CASE ( V_322 ) ;
CASE ( V_323 ) ;
default:
F_161 ( L_114 ,
V_45 , V_8 , V_8 -> V_55 ) ;
V_8 -> V_79 = L_115 ;
F_112 () ;
break;
}
#undef CASE
return true ;
}
static bool F_179 ( struct V_7 * V_8 )
{
int V_67 ;
if ( ! F_9 ( V_8 , V_6 ) )
return false ;
V_67 = F_176 ( V_8 , F_180 ( V_8 -> V_128 ) ) ;
if ( V_67 ) {
F_39 ( L_116 , V_45 ,
V_8 , V_8 -> V_128 ) ;
F_3 ( V_67 == - V_316 ) ;
F_5 ( V_8 , V_6 ) ;
}
return true ;
}
static void F_181 ( struct V_7 * V_8 )
{
if ( V_8 -> V_210 && V_8 -> V_74 -> V_324 ) {
F_39 ( L_117 ) ;
V_8 -> V_74 -> V_324 ( V_8 ) ;
}
if ( V_8 -> V_74 -> V_325 )
V_8 -> V_74 -> V_325 ( V_8 ) ;
}
static void V_131 ( struct V_326 * V_121 )
{
struct V_7 * V_8 = F_182 ( V_121 , struct V_7 ,
V_121 . V_121 ) ;
bool V_325 ;
F_75 ( & V_8 -> V_118 ) ;
while ( true ) {
int V_67 ;
if ( ( V_325 = F_178 ( V_8 ) ) ) {
F_39 ( L_118 , V_45 , V_8 ) ;
break;
}
if ( F_179 ( V_8 ) ) {
F_39 ( L_119 , V_45 , V_8 ) ;
break;
}
if ( V_8 -> V_55 == V_327 ) {
F_39 ( L_120 , V_45 , V_8 ) ;
break;
}
if ( V_8 -> V_55 == V_119 ) {
F_39 ( L_121 , V_45 , V_8 ) ;
F_3 ( V_8 -> V_49 ) ;
break;
}
if ( V_8 -> V_55 == V_125 ) {
F_39 ( L_122 , V_45 , V_8 ) ;
F_3 ( V_8 -> V_49 ) ;
}
V_67 = F_175 ( V_8 ) ;
if ( V_67 < 0 ) {
if ( V_67 == - V_90 )
continue;
V_8 -> V_79 = L_123 ;
V_325 = true ;
break;
}
V_67 = F_174 ( V_8 ) ;
if ( V_67 < 0 ) {
if ( V_67 == - V_90 )
continue;
V_8 -> V_79 = L_124 ;
V_325 = true ;
}
break;
}
if ( V_325 )
F_183 ( V_8 ) ;
F_77 ( & V_8 -> V_118 ) ;
if ( V_325 )
F_181 ( V_8 ) ;
V_8 -> V_74 -> V_108 ( V_8 ) ;
}
static void F_183 ( struct V_7 * V_8 )
{
F_161 ( L_125 , F_165 ( V_8 -> V_126 ) ,
F_13 ( & V_8 -> V_65 . V_66 ) , V_8 -> V_79 ) ;
F_39 ( L_126 ,
V_8 , V_8 -> V_55 , F_13 ( & V_8 -> V_65 . V_66 ) ) ;
F_37 ( V_8 -> V_55 != V_307 &&
V_8 -> V_55 != V_211 &&
V_8 -> V_55 != V_287 ) ;
F_66 ( V_8 ) ;
if ( F_7 ( V_8 , V_2 ) ) {
F_39 ( L_127 ) ;
V_8 -> V_55 = V_119 ;
return;
}
if ( V_8 -> V_112 ) {
F_3 ( V_8 -> V_112 -> V_8 != V_8 ) ;
V_8 -> V_112 -> V_8 = NULL ;
F_69 ( V_8 -> V_112 ) ;
V_8 -> V_112 = NULL ;
V_8 -> V_74 -> V_108 ( V_8 ) ;
}
F_184 ( & V_8 -> V_111 , & V_8 -> V_110 ) ;
if ( F_71 ( & V_8 -> V_110 ) &&
! F_7 ( V_8 , V_3 ) ) {
F_39 ( L_128 , V_8 ) ;
F_2 ( V_8 , V_4 ) ;
V_8 -> V_55 = V_327 ;
} else {
V_8 -> V_55 = V_125 ;
if ( V_8 -> V_128 == 0 )
V_8 -> V_128 = V_328 ;
else if ( V_8 -> V_128 < V_329 )
V_8 -> V_128 *= 2 ;
F_5 ( V_8 , V_6 ) ;
F_46 ( V_8 ) ;
}
}
void F_185 ( struct V_29 * V_30 ,
struct V_124 * V_330 ,
V_160 V_225 ,
V_160 V_278 ,
bool V_233 )
{
V_30 -> V_225 = V_225 ;
V_30 -> V_278 = V_278 ;
F_186 ( & V_30 -> V_133 ) ;
if ( V_330 )
V_30 -> V_32 . V_33 = * V_330 ;
V_30 -> V_32 . V_33 . type = 0 ;
F_187 ( & V_30 -> V_32 . V_33 . V_275 , sizeof( V_30 -> V_32 . V_33 . V_275 ) ) ;
F_16 ( V_30 ) ;
V_30 -> V_233 = V_233 ;
F_188 ( & V_30 -> V_52 , 0 ) ;
F_39 ( L_129 , V_45 , V_30 ) ;
}
static void F_189 ( struct V_7 * V_8 )
{
if ( V_8 -> V_55 == V_327 ) {
F_39 ( L_130 , V_8 ) ;
V_8 -> V_55 = V_125 ;
V_8 -> V_113 ++ ;
F_37 ( F_7 ( V_8 , V_4 ) ) ;
F_37 ( F_7 ( V_8 , V_3 ) ) ;
}
}
void F_190 ( struct V_7 * V_8 , struct V_35 * V_85 )
{
V_85 -> V_189 . V_305 = V_8 -> V_30 -> V_32 . V_262 ;
F_3 ( V_85 -> V_193 . V_103 != F_118 ( V_85 -> V_189 . V_191 ) ) ;
V_85 -> V_188 = true ;
F_75 ( & V_8 -> V_118 ) ;
if ( V_8 -> V_55 == V_119 ) {
F_39 ( L_131 , V_8 , V_85 ) ;
F_69 ( V_85 ) ;
F_77 ( & V_8 -> V_118 ) ;
return;
}
F_3 ( V_85 -> V_8 != NULL ) ;
V_85 -> V_8 = V_8 -> V_74 -> V_315 ( V_8 ) ;
F_3 ( V_85 -> V_8 == NULL ) ;
F_3 ( ! F_71 ( & V_85 -> V_107 ) ) ;
F_191 ( & V_85 -> V_107 , & V_8 -> V_110 ) ;
F_39 ( L_132 , V_85 ,
F_165 ( V_8 -> V_126 ) , F_119 ( V_85 -> V_189 . type ) ,
F_173 ( F_119 ( V_85 -> V_189 . type ) ) ,
F_118 ( V_85 -> V_189 . V_191 ) ,
F_118 ( V_85 -> V_189 . V_192 ) ,
F_118 ( V_85 -> V_189 . V_176 ) ) ;
F_189 ( V_8 ) ;
F_77 ( & V_8 -> V_118 ) ;
if ( F_11 ( V_8 , V_4 ) == 0 )
F_46 ( V_8 ) ;
}
void F_192 ( struct V_35 * V_85 )
{
struct V_7 * V_8 = V_85 -> V_8 ;
if ( ! V_8 )
return;
F_75 ( & V_8 -> V_118 ) ;
if ( ! F_71 ( & V_85 -> V_107 ) ) {
F_39 ( L_133 , V_45 , V_8 , V_85 ) ;
F_68 ( & V_85 -> V_107 ) ;
F_3 ( V_85 -> V_8 == NULL ) ;
V_85 -> V_8 -> V_74 -> V_108 ( V_85 -> V_8 ) ;
V_85 -> V_8 = NULL ;
V_85 -> V_189 . V_190 = 0 ;
F_69 ( V_85 ) ;
}
if ( V_8 -> V_115 == V_85 ) {
F_39 ( L_134 , V_45 , V_8 , V_85 ) ;
V_8 -> V_115 = NULL ;
if ( V_8 -> V_181 ) {
V_8 -> V_236 = V_8 -> V_136 ;
V_8 -> V_181 = false ;
}
V_85 -> V_189 . V_190 = 0 ;
F_69 ( V_85 ) ;
}
F_77 ( & V_8 -> V_118 ) ;
}
void F_193 ( struct V_35 * V_85 )
{
struct V_7 * V_8 ;
F_3 ( V_85 == NULL ) ;
if ( ! V_85 -> V_8 ) {
F_39 ( L_135 , V_45 , V_85 ) ;
return;
}
V_8 = V_85 -> V_8 ;
F_75 ( & V_8 -> V_118 ) ;
if ( V_8 -> V_112 == V_85 ) {
unsigned int V_191 = F_118 ( V_8 -> V_298 . V_191 ) ;
unsigned int V_192 = F_118 ( V_8 -> V_298 . V_192 ) ;
unsigned int V_176 = F_118 ( V_8 -> V_298 . V_176 ) ;
F_39 ( L_136 , V_45 , V_8 , V_85 ) ;
V_8 -> V_238 = V_8 -> V_238 -
sizeof( struct V_197 ) -
V_191 -
V_192 -
V_176 -
sizeof( struct V_331 ) ;
F_69 ( V_8 -> V_112 ) ;
V_8 -> V_112 = NULL ;
V_8 -> V_239 = V_241 ;
V_8 -> V_116 ++ ;
} else {
F_39 ( L_137 ,
V_45 , V_8 , V_8 -> V_112 , V_85 ) ;
}
F_77 ( & V_8 -> V_118 ) ;
}
void F_194 ( struct V_7 * V_8 )
{
F_39 ( L_138 , V_8 ) ;
F_75 ( & V_8 -> V_118 ) ;
F_189 ( V_8 ) ;
F_77 ( & V_8 -> V_118 ) ;
if ( F_11 ( V_8 , V_3 ) == 0 &&
F_11 ( V_8 , V_4 ) == 0 )
F_46 ( V_8 ) ;
}
static struct V_38 * F_195 ( enum V_332 type )
{
struct V_38 * V_139 ;
if ( F_37 ( ! F_196 ( type ) ) )
return NULL ;
V_139 = F_197 ( V_37 , V_71 ) ;
if ( V_139 )
V_139 -> type = type ;
F_83 ( & V_139 -> V_174 ) ;
return V_139 ;
}
static void F_198 ( struct V_38 * V_139 )
{
if ( ! V_139 )
return;
F_37 ( ! F_71 ( & V_139 -> V_174 ) ) ;
if ( V_139 -> type == V_167 ) {
F_199 ( V_139 -> V_166 ) ;
F_155 ( V_139 -> V_166 ) ;
}
F_200 ( V_37 , V_139 ) ;
}
void F_201 ( struct V_35 * V_85 , struct V_91 * * V_158 ,
T_1 V_93 , T_1 V_159 )
{
struct V_38 * V_139 ;
F_3 ( ! V_158 ) ;
F_3 ( ! V_93 ) ;
V_139 = F_195 ( V_157 ) ;
F_3 ( ! V_139 ) ;
V_139 -> V_158 = V_158 ;
V_139 -> V_93 = V_93 ;
V_139 -> V_159 = V_159 & ~ V_161 ;
F_191 ( & V_139 -> V_174 , & V_85 -> V_139 ) ;
V_85 -> V_172 += V_93 ;
}
void F_202 ( struct V_35 * V_85 ,
struct V_165 * V_166 )
{
struct V_38 * V_139 ;
F_3 ( ! V_166 ) ;
F_3 ( ! V_166 -> V_93 ) ;
V_139 = F_195 ( V_167 ) ;
F_3 ( ! V_139 ) ;
V_139 -> V_166 = V_166 ;
F_191 ( & V_139 -> V_174 , & V_85 -> V_139 ) ;
V_85 -> V_172 += V_166 -> V_93 ;
}
void F_203 ( struct V_35 * V_85 , struct V_143 * V_143 ,
T_1 V_93 )
{
struct V_38 * V_139 ;
F_3 ( ! V_143 ) ;
V_139 = F_195 ( V_144 ) ;
F_3 ( ! V_139 ) ;
V_139 -> V_143 = V_143 ;
V_139 -> V_146 = V_93 ;
F_191 ( & V_139 -> V_174 , & V_85 -> V_139 ) ;
V_85 -> V_172 += V_93 ;
}
struct V_35 * F_204 ( int type , int V_191 , T_6 V_9 ,
bool V_333 )
{
struct V_35 * V_177 ;
V_177 = F_197 ( V_34 , V_9 ) ;
if ( V_177 == NULL )
goto V_231;
V_177 -> V_189 . type = F_205 ( type ) ;
V_177 -> V_189 . V_334 = F_205 ( V_335 ) ;
V_177 -> V_189 . V_191 = F_122 ( V_191 ) ;
F_83 ( & V_177 -> V_107 ) ;
F_206 ( & V_177 -> V_336 ) ;
F_83 ( & V_177 -> V_139 ) ;
if ( V_191 ) {
V_177 -> V_193 . V_102 = F_207 ( V_191 , V_9 ) ;
if ( V_177 -> V_193 . V_102 == NULL ) {
F_39 ( L_139 ,
V_191 ) ;
goto V_337;
}
} else {
V_177 -> V_193 . V_102 = NULL ;
}
V_177 -> V_338 = V_177 -> V_193 . V_103 = V_191 ;
F_39 ( L_140 , V_177 , V_191 ) ;
return V_177 ;
V_337:
F_69 ( V_177 ) ;
V_231:
if ( ! V_333 ) {
F_31 ( L_141 , type ,
V_191 ) ;
F_37 ( 1 ) ;
} else {
F_39 ( L_141 , type ,
V_191 ) ;
}
return NULL ;
}
static int F_208 ( struct V_7 * V_8 , struct V_35 * V_85 )
{
int type = F_119 ( V_85 -> V_189 . type ) ;
int V_192 = F_118 ( V_85 -> V_189 . V_192 ) ;
F_39 ( L_142 , V_85 , type ,
F_173 ( type ) , V_192 ) ;
F_3 ( ! V_192 ) ;
F_3 ( V_85 -> V_195 ) ;
V_85 -> V_195 = F_209 ( V_192 , V_71 ) ;
if ( ! V_85 -> V_195 )
return - V_36 ;
return 0 ;
}
static int F_171 ( struct V_7 * V_8 , int * V_304 )
{
struct V_197 * V_189 = & V_8 -> V_298 ;
int V_192 = F_118 ( V_189 -> V_192 ) ;
struct V_35 * V_85 ;
int V_67 = 0 ;
F_3 ( V_8 -> V_112 != NULL ) ;
F_3 ( ! V_8 -> V_74 -> V_339 ) ;
F_77 ( & V_8 -> V_118 ) ;
V_85 = V_8 -> V_74 -> V_339 ( V_8 , V_189 , V_304 ) ;
F_75 ( & V_8 -> V_118 ) ;
if ( V_8 -> V_55 != V_287 ) {
if ( V_85 )
F_69 ( V_85 ) ;
return - V_90 ;
}
if ( V_85 ) {
F_3 ( * V_304 ) ;
V_8 -> V_112 = V_85 ;
V_8 -> V_112 -> V_8 = V_8 -> V_74 -> V_315 ( V_8 ) ;
F_3 ( V_8 -> V_112 -> V_8 == NULL ) ;
} else {
if ( * V_304 )
return 0 ;
V_8 -> V_79 = L_143 ;
return - V_36 ;
}
memcpy ( & V_8 -> V_112 -> V_189 , & V_8 -> V_298 , sizeof( V_8 -> V_298 ) ) ;
if ( V_192 && ! V_8 -> V_112 -> V_195 ) {
V_67 = F_208 ( V_8 , V_8 -> V_112 ) ;
if ( V_67 < 0 ) {
F_69 ( V_8 -> V_112 ) ;
V_8 -> V_112 = NULL ;
}
}
return V_67 ;
}
void F_210 ( struct V_35 * V_177 )
{
F_39 ( L_144 , V_177 ) ;
F_211 ( V_177 -> V_193 . V_102 ) ;
F_200 ( V_34 , V_177 ) ;
}
void F_212 ( struct V_336 * V_336 )
{
struct V_35 * V_177 = F_182 ( V_336 , struct V_35 , V_336 ) ;
F_213 ( V_139 ) ;
struct V_107 * V_174 ;
struct V_107 * V_340 ;
F_39 ( L_145 , V_177 ) ;
F_37 ( ! F_71 ( & V_177 -> V_107 ) ) ;
if ( V_177 -> V_195 ) {
F_214 ( V_177 -> V_195 ) ;
V_177 -> V_195 = NULL ;
}
F_184 ( & V_177 -> V_139 , & V_139 ) ;
F_215 (links, next, &data) {
struct V_38 * V_139 ;
V_139 = F_216 ( V_174 , struct V_38 , V_174 ) ;
F_68 ( V_174 ) ;
F_198 ( V_139 ) ;
}
V_177 -> V_172 = 0 ;
if ( V_177 -> V_341 )
F_217 ( V_177 -> V_341 , V_177 ) ;
else
F_210 ( V_177 ) ;
}
void F_218 ( struct V_35 * V_85 )
{
F_219 ( L_146 , V_85 ,
V_85 -> V_338 , V_85 -> V_172 ) ;
F_220 ( V_342 , L_147 ,
V_343 , 16 , 1 ,
& V_85 -> V_189 , sizeof( V_85 -> V_189 ) , true ) ;
F_220 ( V_342 , L_148 ,
V_343 , 16 , 1 ,
V_85 -> V_193 . V_102 , V_85 -> V_193 . V_103 , true ) ;
if ( V_85 -> V_195 )
F_220 ( V_342 , L_149 ,
V_343 , 16 , 1 ,
V_85 -> V_195 -> V_196 . V_102 ,
V_85 -> V_195 -> V_196 . V_103 , true ) ;
F_220 ( V_342 , L_150 ,
V_343 , 16 , 1 ,
& V_85 -> V_179 , sizeof( V_85 -> V_179 ) , true ) ;
}
