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
unsigned int V_68 ;
int V_69 ;
F_3 ( V_8 -> V_50 ) ;
V_68 = F_50 () ;
V_69 = F_51 ( F_52 ( & V_8 -> V_30 -> V_70 ) , V_65 -> V_21 ,
V_71 , V_72 , & V_50 ) ;
F_53 ( V_68 ) ;
if ( V_69 )
return V_69 ;
V_50 -> V_51 -> V_73 = V_74 ;
#ifdef F_54
F_55 ( & V_50 -> V_51 -> V_75 , & V_76 ) ;
#endif
F_48 ( V_50 , V_8 ) ;
F_37 ( L_15 , F_13 ( & V_8 -> V_66 . V_67 ) ) ;
F_38 ( V_8 ) ;
V_69 = V_50 -> V_77 -> V_78 ( V_50 , (struct V_79 * ) V_65 , sizeof( * V_65 ) ,
V_80 ) ;
if ( V_69 == - V_81 ) {
F_37 ( L_16 ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_50 -> V_51 -> V_54 ) ;
} else if ( V_69 < 0 ) {
F_29 ( L_17 ,
F_13 ( & V_8 -> V_66 . V_67 ) , V_69 ) ;
F_56 ( V_50 ) ;
return V_69 ;
}
if ( F_57 ( F_58 ( V_8 -> V_30 ) , V_82 ) ) {
int V_83 = 1 ;
V_69 = F_59 ( V_50 , V_84 , V_82 ,
( char * ) & V_83 , sizeof( V_83 ) ) ;
if ( V_69 )
F_29 ( L_18 ,
V_69 ) ;
}
V_8 -> V_50 = V_50 ;
return 0 ;
}
static int F_60 ( struct V_61 * V_50 , void * V_85 , T_1 V_86 )
{
struct V_87 V_88 = { V_85 , V_86 } ;
struct V_89 V_90 = { . V_91 = V_92 | V_93 } ;
int V_94 ;
F_61 ( & V_90 . V_95 , V_96 | V_97 , & V_88 , 1 , V_86 ) ;
V_94 = F_62 ( V_50 , & V_90 , V_90 . V_91 ) ;
if ( V_94 == - V_98 )
V_94 = 0 ;
return V_94 ;
}
static int F_63 ( struct V_61 * V_50 , struct V_99 * V_99 ,
int V_100 , T_1 V_101 )
{
struct V_102 V_103 = {
. V_104 = V_99 ,
. V_105 = V_100 ,
. V_106 = V_101
} ;
struct V_89 V_90 = { . V_91 = V_92 | V_93 } ;
int V_94 ;
F_3 ( V_100 + V_101 > V_107 ) ;
F_64 ( & V_90 . V_95 , V_96 | V_108 , & V_103 , 1 , V_101 ) ;
V_94 = F_62 ( V_50 , & V_90 , V_90 . V_91 ) ;
if ( V_94 == - V_98 )
V_94 = 0 ;
return V_94 ;
}
static int F_65 ( struct V_61 * V_50 , struct V_87 * V_88 ,
T_1 V_109 , T_1 V_86 , int V_110 )
{
struct V_89 V_90 = { . V_91 = V_92 | V_93 } ;
int V_94 ;
if ( V_110 )
V_90 . V_91 |= V_111 ;
else
V_90 . V_91 |= V_112 ;
V_94 = F_66 ( V_50 , & V_90 , V_88 , V_109 , V_86 ) ;
if ( V_94 == - V_98 )
V_94 = 0 ;
return V_94 ;
}
static int F_67 ( struct V_61 * V_50 , struct V_99 * V_99 ,
int V_113 , T_1 V_114 , bool V_110 )
{
int V_9 = V_92 | V_93 | ( V_110 ? V_111 : V_112 ) ;
int V_69 ;
V_69 = F_68 ( V_50 , V_99 , V_113 , V_114 , V_9 ) ;
if ( V_69 == - V_98 )
V_69 = 0 ;
return V_69 ;
}
static int F_69 ( struct V_61 * V_50 , struct V_99 * V_99 ,
int V_113 , T_1 V_114 , bool V_110 )
{
struct V_89 V_90 = { . V_91 = V_92 | V_93 } ;
struct V_102 V_103 ;
int V_69 ;
if ( F_70 ( V_99 ) >= 1 )
return F_67 ( V_50 , V_99 , V_113 , V_114 , V_110 ) ;
V_103 . V_104 = V_99 ;
V_103 . V_105 = V_113 ;
V_103 . V_106 = V_114 ;
if ( V_110 )
V_90 . V_91 |= V_111 ;
else
V_90 . V_91 |= V_112 ;
F_64 ( & V_90 . V_95 , V_115 | V_108 , & V_103 , 1 , V_114 ) ;
V_69 = F_71 ( V_50 , & V_90 ) ;
if ( V_69 == - V_98 )
V_69 = 0 ;
return V_69 ;
}
static int F_72 ( struct V_7 * V_8 )
{
int V_116 = 0 ;
F_37 ( L_19 , V_8 , V_8 -> V_50 ) ;
if ( V_8 -> V_50 ) {
V_116 = V_8 -> V_50 -> V_77 -> V_117 ( V_8 -> V_50 , V_118 ) ;
F_56 ( V_8 -> V_50 ) ;
V_8 -> V_50 = NULL ;
}
F_2 ( V_8 , V_5 ) ;
F_41 ( V_8 ) ;
return V_116 ;
}
static void F_73 ( struct V_35 * V_90 )
{
F_74 ( & V_90 -> V_119 ) ;
F_75 ( V_90 ) ;
}
static void F_76 ( struct V_119 * V_120 )
{
while ( ! F_77 ( V_120 ) ) {
struct V_35 * V_90 = F_78 ( V_120 , struct V_35 ,
V_119 ) ;
F_73 ( V_90 ) ;
}
}
static void F_79 ( struct V_7 * V_8 )
{
F_37 ( L_20 , V_8 ) ;
F_76 ( & V_8 -> V_121 ) ;
F_76 ( & V_8 -> V_122 ) ;
if ( V_8 -> V_123 ) {
F_3 ( V_8 -> V_123 -> V_8 != V_8 ) ;
F_75 ( V_8 -> V_123 ) ;
V_8 -> V_123 = NULL ;
}
V_8 -> V_124 = 0 ;
V_8 -> V_125 = 0 ;
if ( V_8 -> V_126 ) {
F_3 ( V_8 -> V_126 -> V_8 != V_8 ) ;
F_75 ( V_8 -> V_126 ) ;
V_8 -> V_126 = NULL ;
}
V_8 -> V_127 = 0 ;
V_8 -> V_128 = 0 ;
V_8 -> V_129 = 0 ;
}
void F_80 ( struct V_7 * V_8 )
{
F_81 ( & V_8 -> V_130 ) ;
F_37 ( L_21 , V_8 ,
F_13 ( & V_8 -> V_66 . V_67 ) ) ;
V_8 -> V_56 = V_131 ;
F_2 ( V_8 , V_2 ) ;
F_2 ( V_8 , V_3 ) ;
F_2 ( V_8 , V_4 ) ;
F_2 ( V_8 , V_6 ) ;
F_79 ( V_8 ) ;
V_8 -> V_132 = 0 ;
F_82 ( V_8 ) ;
F_72 ( V_8 ) ;
F_83 ( & V_8 -> V_130 ) ;
}
void F_84 ( struct V_7 * V_8 ,
T_2 V_133 , T_3 V_134 ,
struct V_135 * V_33 )
{
F_81 ( & V_8 -> V_130 ) ;
F_37 ( L_22 , V_8 , F_13 ( & V_33 -> V_67 ) ) ;
F_35 ( V_8 -> V_56 != V_131 ) ;
V_8 -> V_56 = V_136 ;
V_8 -> V_137 . type = ( T_2 ) V_133 ;
V_8 -> V_137 . V_138 = F_85 ( V_134 ) ;
memcpy ( & V_8 -> V_66 , V_33 , sizeof( * V_33 ) ) ;
V_8 -> V_139 = 0 ;
F_83 ( & V_8 -> V_130 ) ;
F_44 ( V_8 ) ;
}
bool F_86 ( struct V_7 * V_8 )
{
return V_8 -> V_124 > 0 ;
}
void F_87 ( struct V_7 * V_8 , void * V_140 ,
const struct V_141 * V_77 ,
struct V_29 * V_30 )
{
F_37 ( L_23 , V_8 ) ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> V_140 = V_140 ;
V_8 -> V_77 = V_77 ;
V_8 -> V_30 = V_30 ;
F_33 ( V_8 ) ;
F_88 ( & V_8 -> V_130 ) ;
F_89 ( & V_8 -> V_121 ) ;
F_89 ( & V_8 -> V_122 ) ;
F_90 ( & V_8 -> V_142 , V_143 ) ;
V_8 -> V_56 = V_131 ;
}
static T_4 F_91 ( struct V_29 * V_30 , T_4 V_144 )
{
T_4 V_69 ;
F_92 ( & V_30 -> V_145 ) ;
if ( V_30 -> V_146 < V_144 )
V_30 -> V_146 = V_144 ;
V_69 = ++ V_30 -> V_146 ;
F_93 ( & V_30 -> V_145 ) ;
return V_69 ;
}
static void F_94 ( struct V_7 * V_8 )
{
F_3 ( V_8 -> V_129 ) ;
V_8 -> V_147 = 0 ;
V_8 -> V_148 = 0 ;
V_8 -> V_149 = & V_8 -> V_150 [ 0 ] ;
}
static void F_95 ( struct V_7 * V_8 ,
T_1 V_114 , void * V_151 )
{
int V_152 = V_8 -> V_147 ;
F_3 ( V_8 -> V_129 ) ;
F_3 ( V_152 >= F_96 ( V_8 -> V_150 ) ) ;
V_8 -> V_150 [ V_152 ] . V_153 = V_114 ;
V_8 -> V_150 [ V_152 ] . V_154 = V_151 ;
V_8 -> V_147 ++ ;
V_8 -> V_148 += V_114 ;
}
static int F_97 ( struct V_7 * V_8 )
{
int V_155 = V_8 -> V_149 - V_8 -> V_150 ;
int V_156 = 0 ;
if ( V_8 -> V_148 > 0 ) {
V_156 = V_8 -> V_150 [ V_155 + V_8 -> V_147 - 1 ] . V_153 ;
F_3 ( V_8 -> V_148 < V_156 ) ;
F_3 ( ! V_8 -> V_147 ) ;
V_8 -> V_148 -= V_156 ;
V_8 -> V_147 -- ;
}
return V_156 ;
}
static void F_98 ( struct V_157 * V_158 ,
T_1 V_101 )
{
struct V_38 * V_151 = V_158 -> V_151 ;
struct V_159 * V_159 ;
F_3 ( V_151 -> type != V_160 ) ;
V_159 = V_151 -> V_159 ;
F_3 ( ! V_159 ) ;
V_158 -> V_161 = F_99 ( V_101 , V_151 -> V_162 ) ;
V_158 -> V_159 = V_159 ;
V_158 -> V_163 = V_159 -> V_164 ;
V_158 -> V_165 =
V_158 -> V_161 <= F_100 ( V_159 , V_158 -> V_163 ) ;
}
static struct V_99 * F_101 ( struct V_157 * V_158 ,
T_1 * V_100 ,
T_1 * V_101 )
{
struct V_38 * V_151 = V_158 -> V_151 ;
struct V_159 * V_159 ;
struct V_102 V_102 ;
F_3 ( V_151 -> type != V_160 ) ;
V_159 = V_158 -> V_159 ;
F_3 ( ! V_159 ) ;
V_102 = F_102 ( V_159 , V_158 -> V_163 ) ;
* V_100 = ( T_1 ) V_102 . V_105 ;
F_3 ( * V_100 >= V_107 ) ;
if ( V_158 -> V_165 )
* V_101 = V_158 -> V_161 ;
else
* V_101 = ( T_1 ) V_102 . V_106 ;
F_3 ( * V_101 > V_158 -> V_161 ) ;
F_3 ( * V_100 + * V_101 > V_107 ) ;
return V_102 . V_104 ;
}
static bool F_103 ( struct V_157 * V_158 ,
T_1 V_166 )
{
struct V_159 * V_159 ;
struct V_102 V_102 ;
F_3 ( V_158 -> V_151 -> type != V_160 ) ;
V_159 = V_158 -> V_159 ;
F_3 ( ! V_159 ) ;
V_102 = F_102 ( V_159 , V_158 -> V_163 ) ;
F_3 ( V_158 -> V_161 < V_166 ) ;
V_158 -> V_161 -= V_166 ;
F_104 ( V_159 , & V_158 -> V_163 , V_166 ) ;
if ( V_166 < V_102 . V_106 )
return false ;
if ( ! V_158 -> V_163 . V_167 ) {
V_159 = V_159 -> V_168 ;
V_158 -> V_159 = V_159 ;
if ( V_159 )
V_158 -> V_163 = V_159 -> V_164 ;
else
memset ( & V_158 -> V_163 , 0 ,
sizeof( V_158 -> V_163 ) ) ;
}
if ( ! V_158 -> V_165 ) {
F_3 ( ! V_158 -> V_161 ) ;
F_3 ( ! V_159 ) ;
if ( V_158 -> V_161 <= F_100 ( V_159 , V_158 -> V_163 ) )
V_158 -> V_165 = true ;
}
return true ;
}
static void F_105 ( struct V_157 * V_158 ,
T_1 V_101 )
{
struct V_38 * V_151 = V_158 -> V_151 ;
int F_70 ;
F_3 ( V_151 -> type != V_169 ) ;
F_3 ( ! V_151 -> V_170 ) ;
F_3 ( ! V_151 -> V_101 ) ;
V_158 -> V_161 = F_99 ( V_101 , V_151 -> V_101 ) ;
F_70 = F_106 ( V_151 -> V_171 , ( V_172 ) V_151 -> V_101 ) ;
V_158 -> V_100 = V_151 -> V_171 & ~ V_173 ;
V_158 -> V_174 = 0 ;
F_3 ( F_70 > ( int ) V_175 ) ;
V_158 -> F_70 = ( unsigned short ) F_70 ;
F_3 ( V_101 > V_176 - V_158 -> V_100 ) ;
V_158 -> V_165 = V_158 -> V_100 + V_158 -> V_161 <= V_107 ;
}
static struct V_99 *
F_107 ( struct V_157 * V_158 ,
T_1 * V_100 , T_1 * V_101 )
{
struct V_38 * V_151 = V_158 -> V_151 ;
F_3 ( V_151 -> type != V_169 ) ;
F_3 ( V_158 -> V_174 >= V_158 -> F_70 ) ;
F_3 ( V_158 -> V_100 >= V_107 ) ;
* V_100 = V_158 -> V_100 ;
if ( V_158 -> V_165 )
* V_101 = V_158 -> V_161 ;
else
* V_101 = V_107 - * V_100 ;
return V_151 -> V_170 [ V_158 -> V_174 ] ;
}
static bool F_108 ( struct V_157 * V_158 ,
T_1 V_166 )
{
F_3 ( V_158 -> V_151 -> type != V_169 ) ;
F_3 ( V_158 -> V_100 + V_166 > V_107 ) ;
V_158 -> V_161 -= V_166 ;
V_158 -> V_100 = ( V_158 -> V_100 + V_166 ) & ~ V_173 ;
if ( ! V_166 || V_158 -> V_100 )
return false ;
if ( ! V_158 -> V_161 )
return false ;
F_3 ( V_158 -> V_174 >= V_158 -> F_70 ) ;
V_158 -> V_174 ++ ;
V_158 -> V_165 = V_158 -> V_161 <= V_107 ;
return true ;
}
static void
F_109 ( struct V_157 * V_158 ,
T_1 V_101 )
{
struct V_38 * V_151 = V_158 -> V_151 ;
struct V_177 * V_178 ;
struct V_99 * V_99 ;
F_3 ( V_151 -> type != V_179 ) ;
V_178 = V_151 -> V_178 ;
F_3 ( ! V_178 ) ;
if ( ! V_101 )
return;
F_3 ( F_77 ( & V_178 -> V_120 ) ) ;
V_99 = F_78 ( & V_178 -> V_120 , struct V_99 , V_180 ) ;
V_158 -> V_161 = F_99 ( V_101 , V_178 -> V_101 ) ;
V_158 -> V_99 = V_99 ;
V_158 -> V_113 = 0 ;
V_158 -> V_165 = V_158 -> V_161 <= V_107 ;
}
static struct V_99 *
F_110 ( struct V_157 * V_158 ,
T_1 * V_100 , T_1 * V_101 )
{
struct V_38 * V_151 = V_158 -> V_151 ;
struct V_177 * V_178 ;
F_3 ( V_151 -> type != V_179 ) ;
V_178 = V_151 -> V_178 ;
F_3 ( ! V_178 ) ;
F_3 ( ! V_158 -> V_99 ) ;
F_3 ( V_158 -> V_113 + V_158 -> V_161 != V_178 -> V_101 ) ;
* V_100 = V_158 -> V_113 & ~ V_173 ;
if ( V_158 -> V_165 )
* V_101 = V_158 -> V_161 ;
else
* V_101 = V_107 - * V_100 ;
return V_158 -> V_99 ;
}
static bool F_111 ( struct V_157 * V_158 ,
T_1 V_166 )
{
struct V_38 * V_151 = V_158 -> V_151 ;
struct V_177 * V_178 ;
F_3 ( V_151 -> type != V_179 ) ;
V_178 = V_151 -> V_178 ;
F_3 ( ! V_178 ) ;
F_3 ( V_158 -> V_113 + V_158 -> V_161 != V_178 -> V_101 ) ;
F_3 ( ( V_158 -> V_113 & ~ V_173 ) + V_166 > V_107 ) ;
V_158 -> V_161 -= V_166 ;
V_158 -> V_113 += V_166 ;
if ( ! V_166 || V_158 -> V_113 & ~ V_173 )
return false ;
if ( ! V_158 -> V_161 )
return false ;
F_3 ( F_112 ( & V_158 -> V_99 -> V_180 , & V_178 -> V_120 ) ) ;
V_158 -> V_99 = F_113 ( V_158 -> V_99 , V_180 ) ;
V_158 -> V_165 = V_158 -> V_161 <= V_107 ;
return true ;
}
static void F_114 ( struct V_157 * V_158 )
{
T_1 V_101 = V_158 -> V_181 ;
switch ( V_158 -> V_151 -> type ) {
case V_179 :
F_109 ( V_158 , V_101 ) ;
break;
case V_169 :
F_105 ( V_158 , V_101 ) ;
break;
#ifdef F_115
case V_160 :
F_98 ( V_158 , V_101 ) ;
break;
#endif
case V_182 :
default:
break;
}
V_158 -> V_183 = true ;
}
static void F_116 ( struct V_35 * V_90 , T_1 V_101 )
{
struct V_157 * V_158 = & V_90 -> V_158 ;
struct V_38 * V_151 ;
F_3 ( ! V_101 ) ;
F_3 ( V_101 > V_90 -> V_184 ) ;
F_3 ( F_77 ( & V_90 -> V_151 ) ) ;
V_158 -> V_185 = & V_90 -> V_151 ;
V_158 -> V_181 = V_101 ;
V_151 = F_78 ( & V_90 -> V_151 , struct V_38 , V_186 ) ;
V_158 -> V_151 = V_151 ;
F_114 ( V_158 ) ;
}
static struct V_99 * F_117 ( struct V_157 * V_158 ,
T_1 * V_100 , T_1 * V_101 ,
bool * V_165 )
{
struct V_99 * V_99 ;
switch ( V_158 -> V_151 -> type ) {
case V_179 :
V_99 = F_110 ( V_158 , V_100 , V_101 ) ;
break;
case V_169 :
V_99 = F_107 ( V_158 , V_100 , V_101 ) ;
break;
#ifdef F_115
case V_160 :
V_99 = F_101 ( V_158 , V_100 , V_101 ) ;
break;
#endif
case V_182 :
default:
V_99 = NULL ;
break;
}
F_3 ( ! V_99 ) ;
F_3 ( * V_100 + * V_101 > V_107 ) ;
F_3 ( ! * V_101 ) ;
if ( V_165 )
* V_165 = V_158 -> V_165 ;
return V_99 ;
}
static void F_118 ( struct V_157 * V_158 ,
T_1 V_166 )
{
bool V_187 ;
F_3 ( V_166 > V_158 -> V_161 ) ;
switch ( V_158 -> V_151 -> type ) {
case V_179 :
V_187 = F_111 ( V_158 , V_166 ) ;
break;
case V_169 :
V_187 = F_108 ( V_158 , V_166 ) ;
break;
#ifdef F_115
case V_160 :
V_187 = F_103 ( V_158 , V_166 ) ;
break;
#endif
case V_182 :
default:
F_119 () ;
break;
}
V_158 -> V_181 -= V_166 ;
if ( ! V_158 -> V_161 && V_158 -> V_181 ) {
F_35 ( ! V_158 -> V_165 ) ;
F_3 ( F_112 ( & V_158 -> V_151 -> V_186 , V_158 -> V_185 ) ) ;
V_158 -> V_151 = F_113 ( V_158 -> V_151 , V_186 ) ;
F_114 ( V_158 ) ;
V_187 = true ;
}
V_158 -> V_183 = V_187 ;
}
static T_1 F_120 ( struct V_7 * V_8 )
{
return ( V_8 -> V_188 & V_189 ) ?
sizeof( struct V_190 ) :
sizeof( struct V_191 ) ;
}
static void F_121 ( struct V_35 * V_90 , T_4 V_192 )
{
F_3 ( ! V_90 ) ;
F_3 ( ! V_192 ) ;
F_116 ( V_90 , ( T_1 ) V_192 ) ;
}
static void F_122 ( struct V_7 * V_8 )
{
struct V_35 * V_193 = V_8 -> V_126 ;
V_193 -> V_194 . V_9 |= V_195 ;
F_37 ( L_24 , V_8 ) ;
F_95 ( V_8 , F_120 ( V_8 ) , & V_193 -> V_194 ) ;
if ( V_8 -> V_188 & V_189 ) {
if ( V_8 -> V_77 -> V_196 )
V_8 -> V_77 -> V_196 ( V_193 ) ;
else
V_193 -> V_194 . V_197 = 0 ;
} else {
V_193 -> V_198 . V_9 = V_193 -> V_194 . V_9 ;
}
V_8 -> V_199 = V_193 -> V_200 ;
V_8 -> V_201 = true ;
}
static void F_123 ( struct V_7 * V_8 )
{
struct V_35 * V_193 ;
T_4 V_202 ;
F_94 ( V_8 ) ;
V_8 -> V_201 = false ;
if ( V_8 -> V_127 > V_8 -> V_128 ) {
V_8 -> V_128 = V_8 -> V_127 ;
F_95 ( V_8 , sizeof ( V_203 ) , & V_203 ) ;
V_8 -> V_204 = F_85 ( V_8 -> V_128 ) ;
F_95 ( V_8 , sizeof ( V_8 -> V_204 ) ,
& V_8 -> V_204 ) ;
}
F_3 ( F_77 ( & V_8 -> V_121 ) ) ;
V_193 = F_78 ( & V_8 -> V_121 , struct V_35 , V_119 ) ;
V_8 -> V_126 = V_193 ;
F_3 ( V_193 -> V_8 != V_8 ) ;
F_124 ( V_193 ) ;
F_125 ( & V_193 -> V_119 , & V_8 -> V_122 ) ;
if ( V_193 -> V_205 ) {
V_193 -> V_206 . V_207 = F_85 ( ++ V_8 -> V_125 ) ;
V_193 -> V_205 = false ;
}
F_35 ( V_193 -> V_184 != F_126 ( V_193 -> V_206 . V_192 ) ) ;
F_37 ( L_25 ,
V_193 , V_8 -> V_125 , F_127 ( V_193 -> V_206 . type ) ,
F_126 ( V_193 -> V_206 . V_208 ) , F_126 ( V_193 -> V_206 . V_209 ) ,
V_193 -> V_184 ) ;
F_3 ( F_126 ( V_193 -> V_206 . V_208 ) != V_193 -> V_210 . V_153 ) ;
F_95 ( V_8 , sizeof ( V_211 ) , & V_211 ) ;
F_95 ( V_8 , sizeof( V_8 -> V_212 ) , & V_8 -> V_212 ) ;
F_95 ( V_8 , V_193 -> V_210 . V_153 , V_193 -> V_210 . V_154 ) ;
if ( V_193 -> V_213 )
F_95 ( V_8 , V_193 -> V_213 -> V_214 . V_153 ,
V_193 -> V_213 -> V_214 . V_154 ) ;
V_202 = F_128 ( 0 , & V_193 -> V_206 , F_129 ( struct V_215 , V_202 ) ) ;
V_8 -> V_126 -> V_206 . V_202 = F_130 ( V_202 ) ;
memcpy ( & V_8 -> V_212 , & V_8 -> V_126 -> V_206 , sizeof( V_8 -> V_212 ) ) ;
V_202 = F_128 ( 0 , V_193 -> V_210 . V_154 , V_193 -> V_210 . V_153 ) ;
V_8 -> V_126 -> V_194 . V_216 = F_130 ( V_202 ) ;
if ( V_193 -> V_213 ) {
V_202 = F_128 ( 0 , V_193 -> V_213 -> V_214 . V_154 ,
V_193 -> V_213 -> V_214 . V_153 ) ;
V_8 -> V_126 -> V_194 . V_217 = F_130 ( V_202 ) ;
} else
V_8 -> V_126 -> V_194 . V_217 = 0 ;
F_37 ( L_26 , V_46 ,
F_126 ( V_8 -> V_126 -> V_194 . V_216 ) ,
F_126 ( V_8 -> V_126 -> V_194 . V_217 ) ) ;
V_8 -> V_126 -> V_194 . V_9 = 0 ;
V_8 -> V_126 -> V_194 . V_218 = 0 ;
if ( V_193 -> V_184 ) {
F_121 ( V_8 -> V_126 , V_193 -> V_184 ) ;
V_8 -> V_199 = 1 ;
} else {
F_122 ( V_8 ) ;
}
F_5 ( V_8 , V_4 ) ;
}
static void F_131 ( struct V_7 * V_8 )
{
F_37 ( L_27 , V_8 ,
V_8 -> V_128 , V_8 -> V_127 ) ;
V_8 -> V_128 = V_8 -> V_127 ;
F_94 ( V_8 ) ;
F_95 ( V_8 , sizeof ( V_203 ) , & V_203 ) ;
V_8 -> V_204 = F_85 ( V_8 -> V_128 ) ;
F_95 ( V_8 , sizeof ( V_8 -> V_204 ) ,
& V_8 -> V_204 ) ;
V_8 -> V_199 = 1 ;
F_5 ( V_8 , V_4 ) ;
}
static void F_132 ( struct V_7 * V_8 )
{
F_37 ( L_28 , V_8 ,
V_8 -> V_128 , V_8 -> V_127 ) ;
V_8 -> V_128 = V_8 -> V_127 ;
F_94 ( V_8 ) ;
V_8 -> V_204 = F_85 ( V_8 -> V_128 ) ;
F_95 ( V_8 , sizeof ( V_8 -> V_204 ) ,
& V_8 -> V_204 ) ;
F_5 ( V_8 , V_4 ) ;
}
static void F_133 ( struct V_7 * V_8 )
{
F_37 ( L_29 , V_8 ) ;
F_94 ( V_8 ) ;
if ( V_8 -> V_188 & V_219 ) {
struct V_220 V_221 ;
F_134 ( & V_221 ) ;
F_95 ( V_8 , sizeof( V_222 ) , & V_222 ) ;
F_135 ( & V_8 -> V_223 , & V_221 ) ;
F_95 ( V_8 , sizeof( V_8 -> V_223 ) ,
& V_8 -> V_223 ) ;
} else {
F_95 ( V_8 , sizeof( V_224 ) , & V_224 ) ;
}
F_5 ( V_8 , V_4 ) ;
}
static struct V_225 * F_136 ( struct V_7 * V_8 ,
int * V_226 )
{
struct V_225 * V_227 ;
if ( ! V_8 -> V_77 -> V_228 ) {
V_8 -> V_229 . V_230 = V_231 ;
V_8 -> V_229 . V_232 = 0 ;
return NULL ;
}
V_227 = V_8 -> V_77 -> V_228 ( V_8 , V_226 , V_8 -> V_233 ) ;
if ( F_137 ( V_227 ) )
return V_227 ;
V_8 -> V_234 = V_227 -> V_235 ;
V_8 -> V_236 = V_227 -> V_237 ;
return V_227 ;
}
static void F_138 ( struct V_7 * V_8 )
{
F_95 ( V_8 , strlen ( V_238 ) , V_238 ) ;
F_95 ( V_8 , sizeof ( V_8 -> V_30 -> V_31 ) ,
& V_8 -> V_30 -> V_31 ) ;
V_8 -> V_199 = 0 ;
F_5 ( V_8 , V_4 ) ;
}
static int F_139 ( struct V_7 * V_8 )
{
unsigned int V_146 = F_91 ( V_8 -> V_30 , 0 ) ;
int V_239 ;
int V_226 ;
struct V_225 * V_227 ;
switch ( V_8 -> V_137 . type ) {
case V_240 :
V_239 = V_241 ;
break;
case V_242 :
V_239 = V_243 ;
break;
case V_244 :
V_239 = V_245 ;
break;
default:
F_119 () ;
}
F_37 ( L_30 , V_8 ,
V_8 -> V_124 , V_146 , V_239 ) ;
V_8 -> V_229 . V_246 =
F_85 ( F_58 ( V_8 -> V_30 ) -> V_247 ) ;
V_8 -> V_229 . V_248 = F_130 ( V_249 ) ;
V_8 -> V_229 . V_124 = F_130 ( V_8 -> V_124 ) ;
V_8 -> V_229 . V_146 = F_130 ( V_146 ) ;
V_8 -> V_229 . V_250 = F_130 ( V_239 ) ;
V_8 -> V_229 . V_9 = 0 ;
V_226 = V_231 ;
V_227 = F_136 ( V_8 , & V_226 ) ;
if ( F_137 ( V_227 ) )
return F_140 ( V_227 ) ;
V_8 -> V_229 . V_230 = F_130 ( V_226 ) ;
V_8 -> V_229 . V_232 = V_227 ?
F_130 ( V_227 -> V_251 ) : 0 ;
F_95 ( V_8 , sizeof ( V_8 -> V_229 ) ,
& V_8 -> V_229 ) ;
if ( V_227 && V_227 -> V_251 )
F_95 ( V_8 , V_227 -> V_251 ,
V_227 -> V_252 ) ;
V_8 -> V_199 = 0 ;
F_5 ( V_8 , V_4 ) ;
return 0 ;
}
static int F_141 ( struct V_7 * V_8 )
{
int V_69 ;
F_37 ( L_31 , V_8 , V_8 -> V_148 ) ;
while ( V_8 -> V_148 > 0 ) {
V_69 = F_65 ( V_8 -> V_50 , V_8 -> V_149 ,
V_8 -> V_147 , V_8 -> V_148 ,
V_8 -> V_199 ) ;
if ( V_69 <= 0 )
goto V_253;
V_8 -> V_148 -= V_69 ;
if ( V_8 -> V_148 == 0 )
break;
while ( V_69 >= V_8 -> V_149 -> V_153 ) {
F_3 ( ! V_8 -> V_147 ) ;
V_69 -= V_8 -> V_149 -> V_153 ;
V_8 -> V_149 ++ ;
V_8 -> V_147 -- ;
}
if ( V_69 ) {
V_8 -> V_149 -> V_153 -= V_69 ;
V_8 -> V_149 -> V_154 += V_69 ;
}
}
V_8 -> V_147 = 0 ;
V_69 = 1 ;
V_253:
F_37 ( L_32 , V_8 ,
V_8 -> V_148 , V_8 -> V_147 , V_69 ) ;
return V_69 ;
}
static T_4 F_142 ( T_4 V_202 , struct V_99 * V_99 ,
unsigned int V_100 ,
unsigned int V_101 )
{
char * V_254 ;
V_254 = F_143 ( V_99 ) ;
F_3 ( V_254 == NULL ) ;
V_202 = F_128 ( V_202 , V_254 + V_100 , V_101 ) ;
F_144 ( V_99 ) ;
return V_202 ;
}
static int F_145 ( struct V_7 * V_8 )
{
struct V_35 * V_90 = V_8 -> V_126 ;
struct V_157 * V_158 = & V_90 -> V_158 ;
bool V_255 = ! F_57 ( F_58 ( V_8 -> V_30 ) , V_256 ) ;
T_4 V_202 ;
F_37 ( L_33 , V_46 , V_8 , V_90 ) ;
if ( F_77 ( & V_90 -> V_151 ) )
return - V_257 ;
V_202 = V_255 ? F_126 ( V_90 -> V_194 . V_218 ) : 0 ;
while ( V_158 -> V_161 ) {
struct V_99 * V_99 ;
T_1 V_100 ;
T_1 V_101 ;
bool V_165 ;
int V_69 ;
V_99 = F_117 ( V_158 , & V_100 , & V_101 ,
& V_165 ) ;
V_69 = F_69 ( V_8 -> V_50 , V_99 , V_100 ,
V_101 , ! V_165 ) ;
if ( V_69 <= 0 ) {
if ( V_255 )
V_90 -> V_194 . V_218 = F_130 ( V_202 ) ;
return V_69 ;
}
if ( V_255 && V_158 -> V_183 )
V_202 = F_142 ( V_202 , V_99 , V_100 , V_101 ) ;
F_118 ( V_158 , ( T_1 ) V_69 ) ;
}
F_37 ( L_34 , V_46 , V_8 , V_90 ) ;
if ( V_255 )
V_90 -> V_194 . V_218 = F_130 ( V_202 ) ;
else
V_90 -> V_194 . V_9 |= V_258 ;
F_94 ( V_8 ) ;
F_122 ( V_8 ) ;
return 1 ;
}
static int F_146 ( struct V_7 * V_8 )
{
int V_69 ;
F_37 ( L_35 , V_46 , V_8 , V_8 -> V_129 ) ;
while ( V_8 -> V_129 > 0 ) {
T_1 V_114 = F_99 ( V_8 -> V_129 , ( int ) V_107 ) ;
V_69 = F_69 ( V_8 -> V_50 , V_40 , 0 , V_114 , true ) ;
if ( V_69 <= 0 )
goto V_253;
V_8 -> V_129 -= V_69 ;
}
V_69 = 1 ;
V_253:
return V_69 ;
}
static void F_147 ( struct V_7 * V_8 )
{
F_37 ( L_36 , V_8 ) ;
V_8 -> V_259 = 0 ;
}
static void F_148 ( struct V_7 * V_8 )
{
F_37 ( L_37 , V_8 ) ;
V_8 -> V_259 = 0 ;
}
static void F_149 ( struct V_7 * V_8 )
{
F_37 ( L_38 , V_8 ) ;
V_8 -> V_259 = 0 ;
}
static void F_150 ( struct V_7 * V_8 )
{
F_37 ( L_39 , V_8 ) ;
V_8 -> V_259 = 0 ;
V_8 -> V_260 = V_261 ;
}
static void F_151 ( struct V_7 * V_8 )
{
F_37 ( L_40 , V_8 ) ;
V_8 -> V_259 = 0 ;
V_8 -> V_260 = V_262 ;
}
static void F_152 ( struct V_7 * V_8 )
{
F_37 ( L_41 , V_8 ) ;
V_8 -> V_259 = 0 ;
}
static int F_153 ( struct V_7 * V_8 )
{
F_37 ( L_42 , V_8 ) ;
F_3 ( V_8 -> V_123 != NULL ) ;
V_8 -> V_259 = 0 ;
V_8 -> V_263 = V_8 -> V_264 = V_8 -> V_265 = 0 ;
return 0 ;
}
static int F_154 ( struct V_7 * V_8 ,
int V_266 , int V_114 , void * V_267 )
{
while ( V_8 -> V_259 < V_266 ) {
int V_268 = V_266 - V_8 -> V_259 ;
int V_269 = V_114 - V_268 ;
int V_69 = F_60 ( V_8 -> V_50 , V_267 + V_269 , V_268 ) ;
if ( V_69 <= 0 )
return V_69 ;
V_8 -> V_259 += V_69 ;
}
return 1 ;
}
static int F_155 ( struct V_7 * V_8 )
{
int V_114 ;
int V_266 ;
int V_69 ;
F_37 ( L_43 , V_8 , V_8 -> V_259 ) ;
V_114 = strlen ( V_238 ) ;
V_266 = V_114 ;
V_69 = F_154 ( V_8 , V_266 , V_114 , V_8 -> V_270 ) ;
if ( V_69 <= 0 )
goto V_253;
V_114 = sizeof ( V_8 -> V_271 ) ;
V_266 += V_114 ;
V_69 = F_154 ( V_8 , V_266 , V_114 , & V_8 -> V_271 ) ;
if ( V_69 <= 0 )
goto V_253;
V_114 = sizeof ( V_8 -> V_272 ) ;
V_266 += V_114 ;
V_69 = F_154 ( V_8 , V_266 , V_114 , & V_8 -> V_272 ) ;
if ( V_69 <= 0 )
goto V_253;
V_253:
return V_69 ;
}
static int F_156 ( struct V_7 * V_8 )
{
int V_114 ;
int V_266 ;
int V_69 ;
F_37 ( L_44 , V_8 , V_8 -> V_259 ) ;
V_114 = sizeof ( V_8 -> V_273 ) ;
V_266 = V_114 ;
V_69 = F_154 ( V_8 , V_266 , V_114 , & V_8 -> V_273 ) ;
if ( V_69 <= 0 )
goto V_253;
V_114 = F_126 ( V_8 -> V_273 . V_232 ) ;
V_266 += V_114 ;
V_69 = F_154 ( V_8 , V_266 , V_114 , V_8 -> V_234 ) ;
if ( V_69 <= 0 )
goto V_253;
F_37 ( L_45 ,
V_8 , ( int ) V_8 -> V_273 . V_274 ,
F_126 ( V_8 -> V_273 . V_124 ) ,
F_126 ( V_8 -> V_273 . V_146 ) ) ;
V_253:
return V_69 ;
}
static int F_157 ( struct V_7 * V_8 )
{
if ( memcmp ( V_8 -> V_270 , V_238 , strlen ( V_238 ) ) ) {
F_29 ( L_46 ,
F_13 ( & V_8 -> V_66 . V_67 ) ) ;
V_8 -> V_275 = L_47 ;
return - 1 ;
}
return 0 ;
}
static bool F_158 ( struct V_10 * V_11 )
{
struct V_67 * V_33 = & ( (struct V_14 * ) V_11 ) -> V_24 ;
struct V_276 * V_277 = & ( (struct V_16 * ) V_11 ) -> V_27 ;
switch ( V_11 -> V_21 ) {
case V_22 :
return V_33 -> V_278 == F_159 ( V_279 ) ;
case V_26 :
return F_160 ( V_277 ) ;
default:
return true ;
}
}
static int F_161 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_21 ) {
case V_22 :
return F_15 ( ( (struct V_14 * ) V_11 ) -> V_25 ) ;
case V_26 :
return F_15 ( ( (struct V_16 * ) V_11 ) -> V_28 ) ;
}
return 0 ;
}
static void F_162 ( struct V_10 * V_11 , int V_280 )
{
switch ( V_11 -> V_21 ) {
case V_22 :
( (struct V_14 * ) V_11 ) -> V_25 = F_163 ( V_280 ) ;
break;
case V_26 :
( (struct V_16 * ) V_11 ) -> V_28 = F_163 ( V_280 ) ;
break;
}
}
static int F_164 ( const char * V_281 , T_1 V_86 , struct V_10 * V_11 ,
char V_282 , const char * * V_283 )
{
struct V_14 * V_15 = (struct V_14 * ) V_11 ;
struct V_16 * V_17 = (struct V_16 * ) V_11 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
if ( F_165 ( V_281 , V_86 , ( V_284 * ) & V_15 -> V_24 . V_278 , V_282 , V_283 ) ) {
V_11 -> V_21 = V_22 ;
return 0 ;
}
if ( F_166 ( V_281 , V_86 , ( V_284 * ) & V_17 -> V_27 . V_285 , V_282 , V_283 ) ) {
V_11 -> V_21 = V_26 ;
return 0 ;
}
return - V_257 ;
}
static int F_167 ( const char * V_286 , T_1 V_287 ,
struct V_10 * V_11 , char V_282 , const char * * V_283 )
{
const char * V_266 , * V_288 ;
char * V_289 , * V_290 = NULL ;
int V_291 , V_69 ;
V_288 = memchr ( V_286 , V_282 , V_287 ) ;
V_289 = memchr ( V_286 , ':' , V_287 ) ;
if ( V_288 && V_289 )
V_266 = V_288 < V_289 ? V_288 : V_289 ;
else if ( ! V_288 && V_289 )
V_266 = V_289 ;
else {
V_266 = V_288 ;
if ( ! V_266 )
V_266 = V_286 + V_287 ;
}
if ( V_266 <= V_286 )
return - V_257 ;
V_291 = F_168 ( NULL , V_286 , V_266 - V_286 , NULL , & V_290 , NULL ) ;
if ( V_291 > 0 )
V_69 = F_164 ( V_290 , V_291 , V_11 , - 1 , NULL ) ;
else
V_69 = - V_292 ;
F_169 ( V_290 ) ;
* V_283 = V_266 ;
F_170 ( L_48 , ( int ) ( V_266 - V_286 ) , V_286 ,
V_69 , V_69 ? L_49 : F_13 ( V_11 ) ) ;
return V_69 ;
}
static inline int F_167 ( const char * V_286 , T_1 V_287 ,
struct V_10 * V_11 , char V_282 , const char * * V_283 )
{
return - V_257 ;
}
static int F_171 ( const char * V_286 , T_1 V_287 ,
struct V_10 * V_11 , char V_282 , const char * * V_283 )
{
int V_69 ;
V_69 = F_164 ( V_286 , V_287 , V_11 , V_282 , V_283 ) ;
if ( V_69 )
V_69 = F_167 ( V_286 , V_287 , V_11 , V_282 , V_283 ) ;
return V_69 ;
}
int F_172 ( const char * V_293 , const char * V_266 ,
struct V_135 * V_33 ,
int V_294 , int * V_295 )
{
int V_12 , V_69 = - V_257 ;
const char * V_280 = V_293 ;
F_37 ( L_50 , ( int ) ( V_266 - V_293 ) , V_293 ) ;
for ( V_12 = 0 ; V_12 < V_294 ; V_12 ++ ) {
const char * V_283 ;
struct V_10 * V_11 = & V_33 [ V_12 ] . V_67 ;
int V_296 ;
char V_282 = ',' ;
if ( * V_280 == '[' ) {
V_282 = ']' ;
V_280 ++ ;
}
V_69 = F_171 ( V_280 , V_266 - V_280 , V_11 , V_282 , & V_283 ) ;
if ( V_69 )
goto V_297;
V_69 = - V_257 ;
V_280 = V_283 ;
if ( V_282 == ']' ) {
if ( * V_280 != ']' ) {
F_37 ( L_51 ) ;
goto V_297;
}
V_280 ++ ;
}
if ( V_280 < V_266 && * V_280 == ':' ) {
V_296 = 0 ;
V_280 ++ ;
while ( V_280 < V_266 && * V_280 >= '0' && * V_280 <= '9' ) {
V_296 = ( V_296 * 10 ) + ( * V_280 - '0' ) ;
V_280 ++ ;
}
if ( V_296 == 0 )
V_296 = V_298 ;
else if ( V_296 > 65535 )
goto V_297;
} else {
V_296 = V_298 ;
}
F_162 ( V_11 , V_296 ) ;
F_37 ( L_52 , F_13 ( V_11 ) ) ;
if ( V_280 == V_266 )
break;
if ( * V_280 != ',' )
goto V_297;
V_280 ++ ;
}
if ( V_280 != V_266 )
goto V_297;
if ( V_295 )
* V_295 = V_12 + 1 ;
return 0 ;
V_297:
F_29 ( L_53 , ( int ) ( V_266 - V_293 ) , V_293 ) ;
return V_69 ;
}
static int F_173 ( struct V_7 * V_8 )
{
F_37 ( L_54 , V_8 ) ;
if ( F_157 ( V_8 ) < 0 )
return - 1 ;
F_174 ( & V_8 -> V_271 ) ;
F_174 ( & V_8 -> V_272 ) ;
if ( memcmp ( & V_8 -> V_66 , & V_8 -> V_271 ,
sizeof( V_8 -> V_66 ) ) != 0 &&
! ( F_158 ( & V_8 -> V_271 . V_67 ) &&
V_8 -> V_271 . V_299 == V_8 -> V_66 . V_299 ) ) {
F_175 ( L_55 ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
( int ) F_126 ( V_8 -> V_66 . V_299 ) ,
F_13 ( & V_8 -> V_271 . V_67 ) ,
( int ) F_126 ( V_8 -> V_271 . V_299 ) ) ;
V_8 -> V_275 = L_56 ;
return - 1 ;
}
if ( F_158 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ) ) {
int V_296 = F_161 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ) ;
memcpy ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ,
& V_8 -> V_272 . V_67 ,
sizeof( V_8 -> V_272 . V_67 ) ) ;
F_162 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 , V_296 ) ;
F_16 ( V_8 -> V_30 ) ;
F_37 ( L_57 ,
F_13 ( & V_8 -> V_30 -> V_32 . V_33 . V_67 ) ) ;
}
return 0 ;
}
static int F_176 ( struct V_7 * V_8 )
{
V_172 V_300 = F_58 ( V_8 -> V_30 ) -> V_247 ;
V_172 V_301 = F_58 ( V_8 -> V_30 ) -> V_302 ;
V_172 V_303 = F_177 (
F_178 ( V_8 -> V_273 . V_246 ) ) ;
int V_69 ;
F_37 ( L_58 , V_8 , ( int ) V_8 -> V_260 ) ;
if ( V_8 -> V_234 ) {
V_69 = V_8 -> V_77 -> V_304 ( V_8 ) ;
if ( V_69 < 0 ) {
V_8 -> V_275 = L_59 ;
return V_69 ;
}
}
switch ( V_8 -> V_273 . V_274 ) {
case V_305 :
F_29 ( L_60
L_61 ,
F_179 ( V_8 -> V_137 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_300 , V_303 , V_303 & ~ V_300 ) ;
V_8 -> V_275 = L_62 ;
F_79 ( V_8 ) ;
return - 1 ;
case V_306 :
F_29 ( L_63
L_64 ,
F_179 ( V_8 -> V_137 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
F_126 ( V_8 -> V_229 . V_250 ) ,
F_126 ( V_8 -> V_273 . V_250 ) ) ;
V_8 -> V_275 = L_65 ;
F_79 ( V_8 ) ;
return - 1 ;
case V_307 :
V_8 -> V_233 ++ ;
F_37 ( L_66 , V_8 ,
V_8 -> V_233 ) ;
if ( V_8 -> V_233 == 2 ) {
V_8 -> V_275 = L_67 ;
return - 1 ;
}
F_94 ( V_8 ) ;
V_69 = F_139 ( V_8 ) ;
if ( V_69 < 0 )
return V_69 ;
F_148 ( V_8 ) ;
break;
case V_308 :
F_37 ( L_68 ,
F_126 ( V_8 -> V_273 . V_124 ) ) ;
F_29 ( L_69 ,
F_179 ( V_8 -> V_137 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ) ;
F_79 ( V_8 ) ;
F_94 ( V_8 ) ;
V_69 = F_139 ( V_8 ) ;
if ( V_69 < 0 )
return V_69 ;
F_148 ( V_8 ) ;
F_83 ( & V_8 -> V_130 ) ;
F_170 ( L_70 , F_179 ( V_8 -> V_137 ) ) ;
if ( V_8 -> V_77 -> V_309 )
V_8 -> V_77 -> V_309 ( V_8 ) ;
F_81 ( & V_8 -> V_130 ) ;
if ( V_8 -> V_56 != V_310 )
return - V_98 ;
break;
case V_311 :
F_37 ( L_71 ,
F_126 ( V_8 -> V_229 . V_124 ) ,
F_126 ( V_8 -> V_273 . V_124 ) ) ;
V_8 -> V_124 = F_126 ( V_8 -> V_273 . V_124 ) ;
F_94 ( V_8 ) ;
V_69 = F_139 ( V_8 ) ;
if ( V_69 < 0 )
return V_69 ;
F_148 ( V_8 ) ;
break;
case V_312 :
F_37 ( L_72 ,
V_8 -> V_132 ,
F_126 ( V_8 -> V_273 . V_146 ) ) ;
F_91 ( V_8 -> V_30 ,
F_126 ( V_8 -> V_273 . V_146 ) ) ;
F_94 ( V_8 ) ;
V_69 = F_139 ( V_8 ) ;
if ( V_69 < 0 )
return V_69 ;
F_148 ( V_8 ) ;
break;
case V_261 :
case V_262 :
if ( V_301 & ~ V_303 ) {
F_29 ( L_73
L_74 ,
F_179 ( V_8 -> V_137 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_301 , V_303 , V_301 & ~ V_303 ) ;
V_8 -> V_275 = L_62 ;
F_79 ( V_8 ) ;
return - 1 ;
}
F_35 ( V_8 -> V_56 != V_310 ) ;
V_8 -> V_56 = V_313 ;
V_8 -> V_233 = 0 ;
V_8 -> V_132 = F_126 ( V_8 -> V_273 . V_146 ) ;
V_8 -> V_124 ++ ;
V_8 -> V_188 = V_303 ;
F_37 ( L_75 ,
V_8 -> V_132 ,
F_126 ( V_8 -> V_273 . V_124 ) ,
V_8 -> V_124 ) ;
F_35 ( V_8 -> V_124 !=
F_126 ( V_8 -> V_273 . V_124 ) ) ;
if ( V_8 -> V_273 . V_9 & V_314 )
F_5 ( V_8 , V_2 ) ;
V_8 -> V_139 = 0 ;
if ( V_8 -> V_273 . V_274 == V_261 ) {
F_132 ( V_8 ) ;
F_150 ( V_8 ) ;
} else {
F_151 ( V_8 ) ;
}
break;
case V_315 :
V_8 -> V_275 = L_76 ;
return - 1 ;
default:
V_8 -> V_275 = L_77 ;
return - 1 ;
}
return 0 ;
}
static int F_180 ( struct V_7 * V_8 )
{
int V_114 = sizeof ( V_8 -> V_316 ) ;
int V_266 = V_114 ;
return F_154 ( V_8 , V_266 , V_114 , & V_8 -> V_316 ) ;
}
static void F_181 ( struct V_7 * V_8 )
{
struct V_35 * V_193 ;
V_172 V_317 = F_178 ( V_8 -> V_316 ) ;
V_172 V_207 ;
bool V_318 = ( V_8 -> V_260 == V_261 ) ;
struct V_119 * V_319 = V_318 ? & V_8 -> V_121 : & V_8 -> V_122 ;
while ( ! F_77 ( V_319 ) ) {
V_193 = F_78 ( V_319 , struct V_35 , V_119 ) ;
if ( V_318 && V_193 -> V_205 )
break;
V_207 = F_178 ( V_193 -> V_206 . V_207 ) ;
if ( V_207 > V_317 )
break;
F_37 ( L_78 , V_207 ,
F_127 ( V_193 -> V_206 . type ) , V_193 ) ;
V_193 -> V_320 = V_321 ;
F_73 ( V_193 ) ;
}
F_151 ( V_8 ) ;
}
static int F_182 ( struct V_7 * V_8 ,
struct V_87 * V_322 ,
unsigned int V_323 , T_4 * V_202 )
{
int V_69 , V_268 ;
F_3 ( ! V_322 ) ;
while ( V_322 -> V_153 < V_323 ) {
F_3 ( V_322 -> V_154 == NULL ) ;
V_268 = V_323 - V_322 -> V_153 ;
V_69 = F_60 ( V_8 -> V_50 , ( char * ) V_322 -> V_154 +
V_322 -> V_153 , V_268 ) ;
if ( V_69 <= 0 )
return V_69 ;
V_322 -> V_153 += V_69 ;
}
if ( V_322 -> V_153 == V_323 )
* V_202 = F_128 ( 0 , V_322 -> V_154 , V_322 -> V_153 ) ;
return 1 ;
}
static int F_183 ( struct V_7 * V_8 )
{
struct V_35 * V_90 = V_8 -> V_123 ;
struct V_157 * V_158 = & V_90 -> V_158 ;
bool V_255 = ! F_57 ( F_58 ( V_8 -> V_30 ) , V_256 ) ;
struct V_99 * V_99 ;
T_1 V_100 ;
T_1 V_101 ;
T_4 V_202 = 0 ;
int V_69 ;
F_3 ( ! V_90 ) ;
if ( F_77 ( & V_90 -> V_151 ) )
return - V_324 ;
if ( V_255 )
V_202 = V_8 -> V_265 ;
while ( V_158 -> V_161 ) {
V_99 = F_117 ( V_158 , & V_100 , & V_101 , NULL ) ;
V_69 = F_63 ( V_8 -> V_50 , V_99 , V_100 , V_101 ) ;
if ( V_69 <= 0 ) {
if ( V_255 )
V_8 -> V_265 = V_202 ;
return V_69 ;
}
if ( V_255 )
V_202 = F_142 ( V_202 , V_99 , V_100 , V_69 ) ;
F_118 ( V_158 , ( T_1 ) V_69 ) ;
}
if ( V_255 )
V_8 -> V_265 = V_202 ;
return 1 ;
}
static int F_184 ( struct V_7 * V_8 )
{
struct V_35 * V_193 = V_8 -> V_123 ;
int V_114 ;
int V_266 ;
int V_69 ;
unsigned int V_208 , V_209 , V_192 ;
bool V_255 = ! F_57 ( F_58 ( V_8 -> V_30 ) , V_256 ) ;
bool V_325 = ( V_8 -> V_188 & V_189 ) ;
V_172 V_207 ;
T_4 V_202 ;
F_37 ( L_79 , V_8 , V_193 ) ;
V_114 = sizeof ( V_8 -> V_326 ) ;
V_266 = V_114 ;
V_69 = F_154 ( V_8 , V_266 , V_114 , & V_8 -> V_326 ) ;
if ( V_69 <= 0 )
return V_69 ;
V_202 = F_128 ( 0 , & V_8 -> V_326 , F_129 ( struct V_215 , V_202 ) ) ;
if ( F_130 ( V_202 ) != V_8 -> V_326 . V_202 ) {
F_29 ( L_80 ,
V_202 , V_8 -> V_326 . V_202 ) ;
return - V_327 ;
}
V_208 = F_126 ( V_8 -> V_326 . V_208 ) ;
if ( V_208 > V_328 )
return - V_324 ;
V_209 = F_126 ( V_8 -> V_326 . V_209 ) ;
if ( V_209 > V_329 )
return - V_324 ;
V_192 = F_126 ( V_8 -> V_326 . V_192 ) ;
if ( V_192 > V_330 )
return - V_324 ;
V_207 = F_178 ( V_8 -> V_326 . V_207 ) ;
if ( ( V_331 ) V_207 - ( V_331 ) V_8 -> V_127 < 1 ) {
F_170 ( L_81 ,
F_179 ( V_8 -> V_137 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) ,
V_207 , V_8 -> V_127 + 1 ) ;
V_8 -> V_259 = - V_208 - V_209 - V_192 -
F_120 ( V_8 ) ;
V_8 -> V_260 = V_262 ;
return 1 ;
} else if ( ( V_331 ) V_207 - ( V_331 ) V_8 -> V_127 > 1 ) {
F_29 ( L_82 ,
V_207 , V_8 -> V_127 + 1 ) ;
V_8 -> V_275 = L_83 ;
return - V_332 ;
}
if ( ! V_8 -> V_123 ) {
int V_156 = 0 ;
F_37 ( L_84 , V_8 -> V_326 . type ,
V_208 , V_192 ) ;
V_69 = F_185 ( V_8 , & V_156 ) ;
if ( V_69 < 0 )
return V_69 ;
F_3 ( ! V_8 -> V_123 ^ V_156 ) ;
if ( V_156 ) {
F_37 ( L_85 ) ;
V_8 -> V_259 = - V_208 - V_209 - V_192 -
F_120 ( V_8 ) ;
V_8 -> V_260 = V_262 ;
V_8 -> V_127 ++ ;
return 1 ;
}
F_3 ( ! V_8 -> V_123 ) ;
F_3 ( V_8 -> V_123 -> V_8 != V_8 ) ;
V_193 = V_8 -> V_123 ;
V_193 -> V_210 . V_153 = 0 ;
if ( V_193 -> V_213 )
V_193 -> V_213 -> V_214 . V_153 = 0 ;
if ( V_192 )
F_121 ( V_8 -> V_123 , V_192 ) ;
}
V_69 = F_182 ( V_8 , & V_193 -> V_210 , V_208 ,
& V_8 -> V_263 ) ;
if ( V_69 <= 0 )
return V_69 ;
if ( V_193 -> V_213 ) {
V_69 = F_182 ( V_8 , & V_193 -> V_213 -> V_214 ,
V_209 ,
& V_8 -> V_264 ) ;
if ( V_69 <= 0 )
return V_69 ;
}
if ( V_192 ) {
V_69 = F_183 ( V_8 ) ;
if ( V_69 <= 0 )
return V_69 ;
}
V_114 = F_120 ( V_8 ) ;
V_266 += V_114 ;
V_69 = F_154 ( V_8 , V_266 , V_114 , & V_193 -> V_194 ) ;
if ( V_69 <= 0 )
return V_69 ;
if ( ! V_325 ) {
V_193 -> V_194 . V_9 = V_193 -> V_198 . V_9 ;
V_193 -> V_194 . V_197 = 0 ;
}
F_37 ( L_86 ,
V_193 , V_208 , V_193 -> V_194 . V_216 , V_209 ,
V_193 -> V_194 . V_217 , V_192 , V_193 -> V_194 . V_218 ) ;
if ( V_8 -> V_263 != F_126 ( V_193 -> V_194 . V_216 ) ) {
F_29 ( L_87 ,
V_193 , V_8 -> V_263 , V_193 -> V_194 . V_216 ) ;
return - V_327 ;
}
if ( V_8 -> V_264 != F_126 ( V_193 -> V_194 . V_217 ) ) {
F_29 ( L_88 ,
V_193 , V_8 -> V_264 , V_193 -> V_194 . V_217 ) ;
return - V_327 ;
}
if ( V_255 &&
( V_193 -> V_194 . V_9 & V_258 ) == 0 &&
V_8 -> V_265 != F_126 ( V_193 -> V_194 . V_218 ) ) {
F_29 ( L_89 , V_193 ,
V_8 -> V_265 , F_126 ( V_193 -> V_194 . V_218 ) ) ;
return - V_327 ;
}
if ( V_325 && V_8 -> V_77 -> V_333 &&
V_8 -> V_77 -> V_333 ( V_193 ) ) {
F_29 ( L_90 , V_193 ) ;
return - V_327 ;
}
return 1 ;
}
static void F_186 ( struct V_7 * V_8 )
{
struct V_35 * V_90 = V_8 -> V_123 ;
F_3 ( V_8 -> V_123 -> V_8 != V_8 ) ;
V_8 -> V_123 = NULL ;
if ( V_8 -> V_137 . type == 0 )
V_8 -> V_137 = V_90 -> V_206 . V_334 ;
V_8 -> V_127 ++ ;
F_83 ( & V_8 -> V_130 ) ;
F_37 ( L_91 ,
V_90 , F_178 ( V_90 -> V_206 . V_207 ) ,
F_179 ( V_90 -> V_206 . V_334 ) ,
F_127 ( V_90 -> V_206 . type ) ,
F_187 ( F_127 ( V_90 -> V_206 . type ) ) ,
F_126 ( V_90 -> V_206 . V_208 ) ,
F_126 ( V_90 -> V_206 . V_192 ) ,
V_8 -> V_263 , V_8 -> V_264 , V_8 -> V_265 ) ;
V_8 -> V_77 -> V_335 ( V_8 , V_90 ) ;
F_81 ( & V_8 -> V_130 ) ;
}
static int F_188 ( struct V_7 * V_8 )
{
struct V_336 V_337 ;
T_1 V_114 = sizeof( V_337 ) ;
int V_69 = F_154 ( V_8 , V_114 , V_114 , & V_337 ) ;
if ( V_69 <= 0 )
return V_69 ;
F_189 ( & V_8 -> V_338 , & V_337 ) ;
F_151 ( V_8 ) ;
return 1 ;
}
static int F_190 ( struct V_7 * V_8 )
{
int V_69 = 1 ;
F_37 ( L_92 , V_8 , V_8 -> V_56 ) ;
V_110:
F_37 ( L_93 , V_8 -> V_148 ) ;
if ( V_8 -> V_56 == V_136 ) {
F_3 ( V_8 -> V_50 ) ;
V_8 -> V_56 = V_339 ;
F_94 ( V_8 ) ;
F_138 ( V_8 ) ;
F_147 ( V_8 ) ;
F_3 ( V_8 -> V_123 ) ;
V_8 -> V_260 = V_262 ;
F_37 ( L_94 ,
V_8 , V_8 -> V_56 ) ;
V_69 = F_49 ( V_8 ) ;
if ( V_69 < 0 ) {
V_8 -> V_275 = L_95 ;
goto V_253;
}
}
V_340:
if ( V_8 -> V_147 ) {
V_69 = F_141 ( V_8 ) ;
if ( V_69 <= 0 )
goto V_253;
}
if ( V_8 -> V_129 ) {
V_69 = F_146 ( V_8 ) ;
if ( V_69 <= 0 )
goto V_253;
}
if ( V_8 -> V_126 ) {
if ( V_8 -> V_201 ) {
F_75 ( V_8 -> V_126 ) ;
V_8 -> V_126 = NULL ;
goto V_341;
}
V_69 = F_145 ( V_8 ) ;
if ( V_69 == 1 )
goto V_340;
if ( V_69 == 0 )
goto V_253;
if ( V_69 < 0 ) {
F_37 ( L_96 ,
V_69 ) ;
goto V_253;
}
}
V_341:
if ( V_8 -> V_56 == V_313 ) {
if ( F_9 ( V_8 , V_3 ) ) {
F_133 ( V_8 ) ;
goto V_110;
}
if ( ! F_77 ( & V_8 -> V_121 ) ) {
F_123 ( V_8 ) ;
goto V_110;
}
if ( V_8 -> V_127 > V_8 -> V_128 ) {
F_131 ( V_8 ) ;
goto V_110;
}
}
F_2 ( V_8 , V_4 ) ;
F_37 ( L_97 ) ;
V_69 = 0 ;
V_253:
F_37 ( L_98 , V_8 , V_69 ) ;
return V_69 ;
}
static int F_191 ( struct V_7 * V_8 )
{
int V_69 = - 1 ;
V_110:
F_37 ( L_99 , V_8 , V_8 -> V_56 ) ;
if ( V_8 -> V_56 != V_339 &&
V_8 -> V_56 != V_310 &&
V_8 -> V_56 != V_313 )
return 0 ;
F_3 ( ! V_8 -> V_50 ) ;
F_37 ( L_100 , ( int ) V_8 -> V_260 ,
V_8 -> V_259 ) ;
if ( V_8 -> V_56 == V_339 ) {
F_37 ( L_101 ) ;
V_69 = F_155 ( V_8 ) ;
if ( V_69 <= 0 )
goto V_253;
V_69 = F_173 ( V_8 ) ;
if ( V_69 < 0 )
goto V_253;
V_8 -> V_56 = V_310 ;
V_69 = F_139 ( V_8 ) ;
if ( V_69 < 0 )
goto V_253;
F_148 ( V_8 ) ;
goto V_253;
}
if ( V_8 -> V_56 == V_310 ) {
F_37 ( L_102 ) ;
V_69 = F_156 ( V_8 ) ;
if ( V_69 <= 0 )
goto V_253;
V_69 = F_176 ( V_8 ) ;
if ( V_69 < 0 )
goto V_253;
goto V_110;
}
F_35 ( V_8 -> V_56 != V_313 ) ;
if ( V_8 -> V_259 < 0 ) {
static char V_85 [ V_342 ] ;
int V_156 = F_99 ( ( int ) sizeof ( V_85 ) , - V_8 -> V_259 ) ;
F_37 ( L_103 , V_156 , - V_8 -> V_259 ) ;
V_69 = F_60 ( V_8 -> V_50 , V_85 , V_156 ) ;
if ( V_69 <= 0 )
goto V_253;
V_8 -> V_259 += V_69 ;
if ( V_8 -> V_259 )
goto V_110;
}
if ( V_8 -> V_260 == V_262 ) {
V_69 = F_60 ( V_8 -> V_50 , & V_8 -> V_260 , 1 ) ;
if ( V_69 <= 0 )
goto V_253;
F_37 ( L_104 , ( int ) V_8 -> V_260 ) ;
switch ( V_8 -> V_260 ) {
case V_343 :
F_153 ( V_8 ) ;
break;
case V_344 :
F_149 ( V_8 ) ;
break;
case V_345 :
F_152 ( V_8 ) ;
break;
case V_346 :
F_72 ( V_8 ) ;
V_8 -> V_56 = V_131 ;
goto V_253;
default:
goto V_347;
}
}
if ( V_8 -> V_260 == V_343 ) {
V_69 = F_184 ( V_8 ) ;
if ( V_69 <= 0 ) {
switch ( V_69 ) {
case - V_327 :
V_8 -> V_275 = L_105 ;
case - V_332 :
V_69 = - V_324 ;
break;
case - V_324 :
V_8 -> V_275 = L_106 ;
break;
}
goto V_253;
}
if ( V_8 -> V_260 == V_262 )
goto V_110;
F_186 ( V_8 ) ;
if ( V_8 -> V_56 == V_313 )
F_151 ( V_8 ) ;
goto V_110;
}
if ( V_8 -> V_260 == V_344 ||
V_8 -> V_260 == V_261 ) {
V_69 = F_180 ( V_8 ) ;
if ( V_69 <= 0 )
goto V_253;
F_181 ( V_8 ) ;
goto V_110;
}
if ( V_8 -> V_260 == V_345 ) {
V_69 = F_188 ( V_8 ) ;
if ( V_69 <= 0 )
goto V_253;
goto V_110;
}
V_253:
F_37 ( L_107 , V_8 , V_69 ) ;
return V_69 ;
V_347:
F_29 ( L_108 , ( int ) V_8 -> V_260 ) ;
V_8 -> V_275 = L_109 ;
V_69 = - 1 ;
goto V_253;
}
static int F_192 ( struct V_7 * V_8 , unsigned long V_139 )
{
if ( ! V_8 -> V_77 -> V_348 ( V_8 ) ) {
F_37 ( L_110 , V_46 , V_8 ) ;
return - V_349 ;
}
if ( ! F_193 ( V_39 , & V_8 -> V_142 , V_139 ) ) {
F_37 ( L_111 , V_46 , V_8 ) ;
V_8 -> V_77 -> V_350 ( V_8 ) ;
return - V_351 ;
}
F_37 ( L_112 , V_46 , V_8 , V_139 ) ;
return 0 ;
}
static void F_44 ( struct V_7 * V_8 )
{
( void ) F_192 ( V_8 , 0 ) ;
}
static void F_82 ( struct V_7 * V_8 )
{
if ( F_194 ( & V_8 -> V_142 ) ) {
F_37 ( L_113 , V_46 , V_8 ) ;
V_8 -> V_77 -> V_350 ( V_8 ) ;
}
}
static bool F_195 ( struct V_7 * V_8 )
{
if ( ! F_9 ( V_8 , V_5 ) )
return false ;
#define CASE ( T_5 ) \
case CON_STATE_ ## x: \
con->error_msg = "socket closed (con state " #x ")"; \
break;
switch ( V_8 -> V_56 ) {
CASE ( V_352 ) ;
CASE ( V_353 ) ;
CASE ( V_354 ) ;
CASE ( V_355 ) ;
CASE ( V_356 ) ;
CASE ( V_357 ) ;
default:
F_175 ( L_114 ,
V_46 , V_8 , V_8 -> V_56 ) ;
V_8 -> V_275 = L_115 ;
F_119 () ;
break;
}
#undef CASE
return true ;
}
static bool F_196 ( struct V_7 * V_8 )
{
int V_69 ;
if ( ! F_9 ( V_8 , V_6 ) )
return false ;
V_69 = F_192 ( V_8 , F_197 ( V_8 -> V_139 ) ) ;
if ( V_69 ) {
F_37 ( L_116 , V_46 ,
V_8 , V_8 -> V_139 ) ;
F_3 ( V_69 == - V_349 ) ;
F_5 ( V_8 , V_6 ) ;
}
return true ;
}
static void F_198 ( struct V_7 * V_8 )
{
F_37 ( L_113 , V_46 , V_8 ) ;
if ( V_8 -> V_233 ) {
F_37 ( L_117 , V_8 -> V_233 ) ;
if ( V_8 -> V_77 -> V_358 )
V_8 -> V_77 -> V_358 ( V_8 ) ;
V_8 -> V_233 = 0 ;
}
if ( V_8 -> V_77 -> V_359 )
V_8 -> V_77 -> V_359 ( V_8 ) ;
}
static void V_143 ( struct V_360 * V_142 )
{
struct V_7 * V_8 = F_199 ( V_142 , struct V_7 ,
V_142 . V_142 ) ;
bool V_359 ;
F_81 ( & V_8 -> V_130 ) ;
while ( true ) {
int V_69 ;
if ( ( V_359 = F_195 ( V_8 ) ) ) {
F_37 ( L_118 , V_46 , V_8 ) ;
break;
}
if ( F_196 ( V_8 ) ) {
F_37 ( L_119 , V_46 , V_8 ) ;
break;
}
if ( V_8 -> V_56 == V_361 ) {
F_37 ( L_120 , V_46 , V_8 ) ;
break;
}
if ( V_8 -> V_56 == V_131 ) {
F_37 ( L_121 , V_46 , V_8 ) ;
F_3 ( V_8 -> V_50 ) ;
break;
}
if ( V_8 -> V_56 == V_136 ) {
F_37 ( L_122 , V_46 , V_8 ) ;
F_3 ( V_8 -> V_50 ) ;
}
V_69 = F_191 ( V_8 ) ;
if ( V_69 < 0 ) {
if ( V_69 == - V_98 )
continue;
if ( ! V_8 -> V_275 )
V_8 -> V_275 = L_123 ;
V_359 = true ;
break;
}
V_69 = F_190 ( V_8 ) ;
if ( V_69 < 0 ) {
if ( V_69 == - V_98 )
continue;
if ( ! V_8 -> V_275 )
V_8 -> V_275 = L_124 ;
V_359 = true ;
}
break;
}
if ( V_359 )
F_200 ( V_8 ) ;
F_83 ( & V_8 -> V_130 ) ;
if ( V_359 )
F_198 ( V_8 ) ;
V_8 -> V_77 -> V_350 ( V_8 ) ;
}
static void F_200 ( struct V_7 * V_8 )
{
F_37 ( L_125 ,
V_8 , V_8 -> V_56 , F_13 ( & V_8 -> V_66 . V_67 ) ) ;
F_175 ( L_126 , F_179 ( V_8 -> V_137 ) ,
F_13 ( & V_8 -> V_66 . V_67 ) , V_8 -> V_275 ) ;
V_8 -> V_275 = NULL ;
F_35 ( V_8 -> V_56 != V_339 &&
V_8 -> V_56 != V_310 &&
V_8 -> V_56 != V_313 ) ;
F_72 ( V_8 ) ;
if ( F_7 ( V_8 , V_2 ) ) {
F_37 ( L_127 ) ;
V_8 -> V_56 = V_131 ;
return;
}
if ( V_8 -> V_123 ) {
F_3 ( V_8 -> V_123 -> V_8 != V_8 ) ;
F_75 ( V_8 -> V_123 ) ;
V_8 -> V_123 = NULL ;
}
F_201 ( & V_8 -> V_122 , & V_8 -> V_121 ) ;
if ( F_77 ( & V_8 -> V_121 ) &&
! F_7 ( V_8 , V_3 ) ) {
F_37 ( L_128 , V_8 ) ;
F_2 ( V_8 , V_4 ) ;
V_8 -> V_56 = V_361 ;
} else {
V_8 -> V_56 = V_136 ;
if ( V_8 -> V_139 == 0 )
V_8 -> V_139 = V_362 ;
else if ( V_8 -> V_139 < V_363 )
V_8 -> V_139 *= 2 ;
F_5 ( V_8 , V_6 ) ;
F_44 ( V_8 ) ;
}
}
void F_202 ( struct V_29 * V_30 ,
struct V_135 * V_364 )
{
F_203 ( & V_30 -> V_145 ) ;
if ( V_364 )
V_30 -> V_32 . V_33 = * V_364 ;
V_30 -> V_32 . V_33 . type = 0 ;
F_204 ( & V_30 -> V_32 . V_33 . V_299 , sizeof( V_30 -> V_32 . V_33 . V_299 ) ) ;
F_16 ( V_30 ) ;
F_205 ( & V_30 -> V_53 , 0 ) ;
F_206 ( & V_30 -> V_70 , F_207 ( V_365 -> V_366 -> V_367 ) ) ;
F_37 ( L_113 , V_46 , V_30 ) ;
}
void F_208 ( struct V_29 * V_30 )
{
F_209 ( F_52 ( & V_30 -> V_70 ) ) ;
}
static void F_210 ( struct V_35 * V_90 , struct V_7 * V_8 )
{
if ( V_90 -> V_8 )
V_90 -> V_8 -> V_77 -> V_350 ( V_90 -> V_8 ) ;
V_90 -> V_8 = V_8 ? V_8 -> V_77 -> V_348 ( V_8 ) : NULL ;
F_3 ( V_90 -> V_8 != V_8 ) ;
}
static void F_211 ( struct V_7 * V_8 )
{
if ( V_8 -> V_56 == V_361 ) {
F_37 ( L_129 , V_8 ) ;
V_8 -> V_56 = V_136 ;
V_8 -> V_124 ++ ;
F_35 ( F_7 ( V_8 , V_4 ) ) ;
F_35 ( F_7 ( V_8 , V_3 ) ) ;
}
}
void F_212 ( struct V_7 * V_8 , struct V_35 * V_90 )
{
V_90 -> V_206 . V_334 = V_8 -> V_30 -> V_32 . V_286 ;
F_3 ( V_90 -> V_210 . V_153 != F_126 ( V_90 -> V_206 . V_208 ) ) ;
V_90 -> V_205 = true ;
F_81 ( & V_8 -> V_130 ) ;
if ( V_8 -> V_56 == V_131 ) {
F_37 ( L_130 , V_8 , V_90 ) ;
F_75 ( V_90 ) ;
F_83 ( & V_8 -> V_130 ) ;
return;
}
F_210 ( V_90 , V_8 ) ;
F_3 ( ! F_77 ( & V_90 -> V_119 ) ) ;
F_213 ( & V_90 -> V_119 , & V_8 -> V_121 ) ;
F_37 ( L_131 , V_90 ,
F_179 ( V_8 -> V_137 ) , F_127 ( V_90 -> V_206 . type ) ,
F_187 ( F_127 ( V_90 -> V_206 . type ) ) ,
F_126 ( V_90 -> V_206 . V_208 ) ,
F_126 ( V_90 -> V_206 . V_209 ) ,
F_126 ( V_90 -> V_206 . V_192 ) ) ;
F_211 ( V_8 ) ;
F_83 ( & V_8 -> V_130 ) ;
if ( F_11 ( V_8 , V_4 ) == 0 )
F_44 ( V_8 ) ;
}
void F_214 ( struct V_35 * V_90 )
{
struct V_7 * V_8 = V_90 -> V_8 ;
if ( ! V_8 ) {
F_37 ( L_132 , V_46 , V_90 ) ;
return;
}
F_81 ( & V_8 -> V_130 ) ;
if ( ! F_77 ( & V_90 -> V_119 ) ) {
F_37 ( L_133 , V_46 , V_8 , V_90 ) ;
F_74 ( & V_90 -> V_119 ) ;
V_90 -> V_206 . V_207 = 0 ;
F_75 ( V_90 ) ;
}
if ( V_8 -> V_126 == V_90 ) {
F_3 ( V_8 -> V_129 ) ;
if ( V_8 -> V_201 ) {
V_8 -> V_129 += F_97 ( V_8 ) ;
} else {
F_3 ( ! V_90 -> V_184 ) ;
V_8 -> V_129 += F_120 ( V_8 ) ;
}
if ( V_90 -> V_184 )
V_8 -> V_129 += V_90 -> V_158 . V_181 ;
if ( V_90 -> V_213 )
V_8 -> V_129 += F_97 ( V_8 ) ;
V_8 -> V_129 += F_97 ( V_8 ) ;
F_37 ( L_134 ,
V_46 , V_8 , V_90 , V_8 -> V_148 , V_8 -> V_129 ) ;
V_90 -> V_206 . V_207 = 0 ;
V_8 -> V_126 = NULL ;
F_75 ( V_90 ) ;
}
F_83 ( & V_8 -> V_130 ) ;
}
void F_215 ( struct V_35 * V_90 )
{
struct V_7 * V_8 = V_90 -> V_8 ;
if ( ! V_8 ) {
F_37 ( L_132 , V_46 , V_90 ) ;
return;
}
F_81 ( & V_8 -> V_130 ) ;
if ( V_8 -> V_123 == V_90 ) {
unsigned int V_208 = F_126 ( V_8 -> V_326 . V_208 ) ;
unsigned int V_209 = F_126 ( V_8 -> V_326 . V_209 ) ;
unsigned int V_192 = F_126 ( V_8 -> V_326 . V_192 ) ;
F_37 ( L_135 , V_46 , V_8 , V_90 ) ;
V_8 -> V_259 = V_8 -> V_259 -
sizeof( struct V_215 ) -
V_208 -
V_209 -
V_192 -
sizeof( struct V_190 ) ;
F_75 ( V_8 -> V_123 ) ;
V_8 -> V_123 = NULL ;
V_8 -> V_260 = V_262 ;
V_8 -> V_127 ++ ;
} else {
F_37 ( L_136 ,
V_46 , V_8 , V_8 -> V_123 , V_90 ) ;
}
F_83 ( & V_8 -> V_130 ) ;
}
void F_216 ( struct V_7 * V_8 )
{
F_37 ( L_137 , V_8 ) ;
F_81 ( & V_8 -> V_130 ) ;
F_211 ( V_8 ) ;
F_83 ( & V_8 -> V_130 ) ;
if ( F_11 ( V_8 , V_3 ) == 0 &&
F_11 ( V_8 , V_4 ) == 0 )
F_44 ( V_8 ) ;
}
bool F_217 ( struct V_7 * V_8 ,
unsigned long V_368 )
{
if ( V_368 > 0 &&
( V_8 -> V_188 & V_219 ) ) {
struct V_220 V_221 ;
struct V_220 V_369 ;
F_134 ( & V_221 ) ;
F_218 ( V_368 , & V_369 ) ;
V_369 = F_219 ( V_8 -> V_338 , V_369 ) ;
return F_220 ( & V_221 , & V_369 ) >= 0 ;
}
return false ;
}
static struct V_38 * F_221 ( enum V_370 type )
{
struct V_38 * V_151 ;
if ( F_35 ( ! F_222 ( type ) ) )
return NULL ;
V_151 = F_223 ( V_37 , V_74 ) ;
if ( V_151 )
V_151 -> type = type ;
F_89 ( & V_151 -> V_186 ) ;
return V_151 ;
}
static void F_224 ( struct V_38 * V_151 )
{
if ( ! V_151 )
return;
F_35 ( ! F_77 ( & V_151 -> V_186 ) ) ;
if ( V_151 -> type == V_179 )
F_225 ( V_151 -> V_178 ) ;
F_226 ( V_37 , V_151 ) ;
}
void F_227 ( struct V_35 * V_90 , struct V_99 * * V_170 ,
T_1 V_101 , T_1 V_171 )
{
struct V_38 * V_151 ;
F_3 ( ! V_170 ) ;
F_3 ( ! V_101 ) ;
V_151 = F_221 ( V_169 ) ;
F_3 ( ! V_151 ) ;
V_151 -> V_170 = V_170 ;
V_151 -> V_101 = V_101 ;
V_151 -> V_171 = V_171 & ~ V_173 ;
F_213 ( & V_151 -> V_186 , & V_90 -> V_151 ) ;
V_90 -> V_184 += V_101 ;
}
void F_228 ( struct V_35 * V_90 ,
struct V_177 * V_178 )
{
struct V_38 * V_151 ;
F_3 ( ! V_178 ) ;
F_3 ( ! V_178 -> V_101 ) ;
V_151 = F_221 ( V_179 ) ;
F_3 ( ! V_151 ) ;
V_151 -> V_178 = V_178 ;
F_213 ( & V_151 -> V_186 , & V_90 -> V_151 ) ;
V_90 -> V_184 += V_178 -> V_101 ;
}
void F_229 ( struct V_35 * V_90 , struct V_159 * V_159 ,
T_1 V_101 )
{
struct V_38 * V_151 ;
F_3 ( ! V_159 ) ;
V_151 = F_221 ( V_160 ) ;
F_3 ( ! V_151 ) ;
V_151 -> V_159 = V_159 ;
V_151 -> V_162 = V_101 ;
F_213 ( & V_151 -> V_186 , & V_90 -> V_151 ) ;
V_90 -> V_184 += V_101 ;
}
struct V_35 * F_230 ( int type , int V_208 , T_6 V_9 ,
bool V_371 )
{
struct V_35 * V_193 ;
V_193 = F_223 ( V_34 , V_9 ) ;
if ( V_193 == NULL )
goto V_253;
V_193 -> V_206 . type = F_231 ( type ) ;
V_193 -> V_206 . V_372 = F_231 ( V_373 ) ;
V_193 -> V_206 . V_208 = F_130 ( V_208 ) ;
F_89 ( & V_193 -> V_119 ) ;
F_232 ( & V_193 -> V_374 ) ;
F_89 ( & V_193 -> V_151 ) ;
if ( V_208 ) {
V_193 -> V_210 . V_154 = F_233 ( V_208 , V_9 ) ;
if ( V_193 -> V_210 . V_154 == NULL ) {
F_37 ( L_138 ,
V_208 ) ;
goto V_375;
}
} else {
V_193 -> V_210 . V_154 = NULL ;
}
V_193 -> V_376 = V_193 -> V_210 . V_153 = V_208 ;
F_37 ( L_139 , V_193 , V_208 ) ;
return V_193 ;
V_375:
F_75 ( V_193 ) ;
V_253:
if ( ! V_371 ) {
F_29 ( L_140 , type ,
V_208 ) ;
F_35 ( 1 ) ;
} else {
F_37 ( L_140 , type ,
V_208 ) ;
}
return NULL ;
}
static int F_234 ( struct V_7 * V_8 , struct V_35 * V_90 )
{
int type = F_127 ( V_90 -> V_206 . type ) ;
int V_209 = F_126 ( V_90 -> V_206 . V_209 ) ;
F_37 ( L_141 , V_90 , type ,
F_187 ( type ) , V_209 ) ;
F_3 ( ! V_209 ) ;
F_3 ( V_90 -> V_213 ) ;
V_90 -> V_213 = F_235 ( V_209 , V_74 ) ;
if ( ! V_90 -> V_213 )
return - V_36 ;
return 0 ;
}
static int F_185 ( struct V_7 * V_8 , int * V_156 )
{
struct V_215 * V_206 = & V_8 -> V_326 ;
int V_209 = F_126 ( V_206 -> V_209 ) ;
struct V_35 * V_90 ;
int V_69 = 0 ;
F_3 ( V_8 -> V_123 != NULL ) ;
F_3 ( ! V_8 -> V_77 -> V_377 ) ;
F_83 ( & V_8 -> V_130 ) ;
V_90 = V_8 -> V_77 -> V_377 ( V_8 , V_206 , V_156 ) ;
F_81 ( & V_8 -> V_130 ) ;
if ( V_8 -> V_56 != V_313 ) {
if ( V_90 )
F_75 ( V_90 ) ;
return - V_98 ;
}
if ( V_90 ) {
F_3 ( * V_156 ) ;
F_210 ( V_90 , V_8 ) ;
V_8 -> V_123 = V_90 ;
} else {
if ( * V_156 )
return 0 ;
V_8 -> V_275 = L_142 ;
return - V_36 ;
}
memcpy ( & V_8 -> V_123 -> V_206 , & V_8 -> V_326 , sizeof( V_8 -> V_326 ) ) ;
if ( V_209 && ! V_8 -> V_123 -> V_213 ) {
V_69 = F_234 ( V_8 , V_8 -> V_123 ) ;
if ( V_69 < 0 ) {
F_75 ( V_8 -> V_123 ) ;
V_8 -> V_123 = NULL ;
}
}
return V_69 ;
}
static void F_236 ( struct V_35 * V_193 )
{
F_37 ( L_113 , V_46 , V_193 ) ;
F_237 ( V_193 -> V_210 . V_154 ) ;
F_226 ( V_34 , V_193 ) ;
}
static void F_238 ( struct V_374 * V_374 )
{
struct V_35 * V_193 = F_199 ( V_374 , struct V_35 , V_374 ) ;
struct V_38 * V_151 , * V_378 ;
F_37 ( L_113 , V_46 , V_193 ) ;
F_35 ( ! F_77 ( & V_193 -> V_119 ) ) ;
F_210 ( V_193 , NULL ) ;
if ( V_193 -> V_213 ) {
F_239 ( V_193 -> V_213 ) ;
V_193 -> V_213 = NULL ;
}
F_240 (data, next, &m->data, links) {
F_74 ( & V_151 -> V_186 ) ;
F_224 ( V_151 ) ;
}
V_193 -> V_184 = 0 ;
if ( V_193 -> V_379 )
F_241 ( V_193 -> V_379 , V_193 ) ;
else
F_236 ( V_193 ) ;
}
struct V_35 * F_124 ( struct V_35 * V_90 )
{
F_37 ( L_143 , V_46 , V_90 ,
F_242 ( & V_90 -> V_374 ) ) ;
F_243 ( & V_90 -> V_374 ) ;
return V_90 ;
}
void F_75 ( struct V_35 * V_90 )
{
F_37 ( L_143 , V_46 , V_90 ,
F_242 ( & V_90 -> V_374 ) ) ;
F_244 ( & V_90 -> V_374 , F_238 ) ;
}
void F_245 ( struct V_35 * V_90 )
{
F_246 ( L_144 , V_90 ,
V_90 -> V_376 , V_90 -> V_184 ) ;
F_247 ( V_380 , L_145 ,
V_381 , 16 , 1 ,
& V_90 -> V_206 , sizeof( V_90 -> V_206 ) , true ) ;
F_247 ( V_380 , L_146 ,
V_381 , 16 , 1 ,
V_90 -> V_210 . V_154 , V_90 -> V_210 . V_153 , true ) ;
if ( V_90 -> V_213 )
F_247 ( V_380 , L_147 ,
V_381 , 16 , 1 ,
V_90 -> V_213 -> V_214 . V_154 ,
V_90 -> V_213 -> V_214 . V_153 , true ) ;
F_247 ( V_380 , L_148 ,
V_381 , 16 , 1 ,
& V_90 -> V_194 , sizeof( V_90 -> V_194 ) , true ) ;
}
