void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( 2 , V_5 , & V_2 -> V_6 ,
L_1 , V_7 , V_3 , V_4 ) ;
F_3 ( V_3 , V_2 -> V_8 + V_4 ) ;
}
unsigned int F_4 ( struct V_1 * V_2 , T_1 V_4 )
{
T_1 V_3 ;
V_3 = F_5 ( V_2 -> V_8 + V_4 ) ;
F_2 ( 2 , V_5 , & V_2 -> V_6 ,
L_1 , V_7 , V_3 , V_4 ) ;
return V_3 ;
}
void F_6 ( struct V_9 * V_10 , struct V_11 * V_12 ,
struct V_13 * V_14 , unsigned int V_15 )
{
T_1 V_16 = F_7 ( V_14 , 0 ) ;
T_1 V_17 , V_18 ;
switch ( V_12 -> V_19 ) {
case V_20 :
case V_21 :
default:
V_17 = V_16 + V_12 -> V_22 * V_12 -> V_23 ;
V_18 = V_17 + V_12 -> V_22 * V_12 -> V_23 / 4 ;
break;
case V_24 :
V_18 = V_16 + V_12 -> V_22 * V_12 -> V_23 ;
V_17 = V_18 + V_12 -> V_22 * V_12 -> V_23 / 4 ;
break;
case V_25 :
V_17 = V_16 + V_12 -> V_22 * V_12 -> V_23 ;
V_18 = V_17 + V_12 -> V_22 * V_12 -> V_23 / 2 ;
}
F_1 ( V_10 -> V_2 , V_16 , V_15 ) ;
F_1 ( V_10 -> V_2 , V_17 , V_15 + 4 ) ;
F_1 ( V_10 -> V_2 , V_18 , V_15 + 8 ) ;
}
static T_1 F_8 ( T_1 V_19 )
{
switch ( V_19 ) {
case V_20 :
case V_21 :
case V_24 :
case V_25 :
return V_21 ;
default:
return V_19 ;
}
}
static const struct V_26 * F_9 ( struct V_1 * V_2 ,
int V_27 , int V_28 )
{
const struct V_26 * V_29 = V_2 -> V_30 -> V_29 ;
int V_31 = V_2 -> V_30 -> V_31 ;
int V_32 ;
V_27 = F_8 ( V_27 ) ;
V_28 = F_8 ( V_28 ) ;
if ( V_27 == V_28 )
return NULL ;
for ( V_32 = 0 ; V_32 < V_31 ; V_32 ++ ) {
if ( V_29 [ V_32 ] . V_27 == V_27 &&
V_29 [ V_32 ] . V_28 == V_28 )
break;
}
if ( V_32 == V_31 )
return NULL ;
return & V_29 [ V_32 ] ;
}
static void F_10 ( struct V_1 * V_2 ,
const struct V_26 * V_33 ,
int * V_34 , int * V_35 )
{
const struct V_26 * V_29 = V_2 -> V_30 -> V_29 ;
int V_31 = V_2 -> V_30 -> V_31 ;
unsigned int V_36 , V_37 ;
int V_32 ;
if ( V_33 ) {
V_36 = V_33 -> V_34 ;
V_37 = V_33 -> V_35 ;
} else {
for ( V_32 = 0 , V_36 = 0 , V_37 = 0 ; V_32 < V_31 ; V_32 ++ ) {
V_36 = F_11 ( V_36 , V_29 [ V_32 ] . V_34 ) ;
V_37 = F_11 ( V_37 , V_29 [ V_32 ] . V_35 ) ;
}
}
if ( V_34 )
* V_34 = V_36 ;
if ( V_35 )
* V_35 = V_37 ;
}
const struct V_38 * F_12 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_13 ( V_40 ) ;
unsigned int V_41 = V_40 - V_2 -> V_42 ;
if ( V_41 >= V_2 -> V_30 -> V_43 )
return NULL ;
return V_2 -> V_30 -> V_44 [ V_41 ] ;
}
const char * F_14 ( int V_45 )
{
static char V_14 [ 9 ] ;
switch ( V_45 ) {
case V_46 :
return L_2 ;
case V_47 :
return L_3 ;
case V_48 :
return L_4 ;
default:
snprintf ( V_14 , sizeof( V_14 ) , L_5 , V_45 ) ;
return V_14 ;
}
}
static int F_15 ( struct V_49 * V_49 , void * V_50 ,
struct V_51 * V_52 )
{
struct V_9 * V_10 = F_16 ( V_50 ) ;
F_17 ( V_52 -> V_53 , V_54 , sizeof( V_52 -> V_53 ) ) ;
F_17 ( V_52 -> V_55 , F_14 ( V_10 -> V_2 -> V_30 -> V_45 ) ,
sizeof( V_52 -> V_55 ) ) ;
F_17 ( V_52 -> V_56 , L_6 V_54 , sizeof( V_52 -> V_56 ) ) ;
V_52 -> V_57 = V_58 | V_59 ;
V_52 -> V_60 = V_52 -> V_57 | V_61 ;
return 0 ;
}
static int F_18 ( struct V_49 * V_49 , void * V_50 ,
struct V_62 * V_63 )
{
struct V_39 * V_40 = F_19 ( V_49 ) ;
const struct V_38 * V_64 = F_12 ( V_40 ) ;
const T_1 * V_65 ;
if ( V_63 -> type == V_66 )
V_65 = V_64 -> V_67 ;
else if ( V_63 -> type == V_68 )
V_65 = V_64 -> V_69 ;
else
return - V_70 ;
if ( V_63 -> V_71 >= V_72 || V_65 [ V_63 -> V_71 ] == 0 )
return - V_70 ;
V_63 -> V_73 = V_65 [ V_63 -> V_71 ] ;
return 0 ;
}
static int F_20 ( struct V_49 * V_49 , void * V_50 ,
struct V_74 * V_63 )
{
struct V_11 * V_12 ;
struct V_9 * V_10 = F_16 ( V_50 ) ;
V_12 = F_21 ( V_10 , V_63 -> type ) ;
if ( ! V_12 )
return - V_70 ;
V_63 -> V_75 . V_76 . V_77 = V_78 ;
V_63 -> V_75 . V_76 . V_73 = V_12 -> V_19 ;
V_63 -> V_75 . V_76 . V_79 = V_12 -> V_79 ;
V_63 -> V_75 . V_76 . V_23 = V_12 -> V_23 ;
V_63 -> V_75 . V_76 . V_22 = V_12 -> V_22 ;
V_63 -> V_75 . V_76 . V_80 = V_12 -> V_80 ;
if ( V_63 -> V_75 . V_76 . V_73 == V_81 )
V_63 -> V_75 . V_76 . V_82 = V_83 ;
else
V_63 -> V_75 . V_76 . V_82 = V_10 -> V_82 ;
return 0 ;
}
static int F_22 ( struct V_9 * V_10 , struct V_74 * V_63 )
{
struct V_11 * V_12 ;
const T_1 * V_65 ;
int V_41 ;
if ( V_63 -> type == V_66 )
V_65 = V_10 -> V_64 -> V_67 ;
else if ( V_63 -> type == V_68 )
V_65 = V_10 -> V_64 -> V_69 ;
else
return - V_70 ;
for ( V_41 = 0 ; V_41 < V_72 ; V_41 ++ ) {
if ( V_65 [ V_41 ] == V_63 -> V_75 . V_76 . V_73 ) {
V_63 -> V_75 . V_76 . V_73 = V_65 [ V_41 ] ;
return 0 ;
}
}
V_12 = F_21 ( V_10 , V_63 -> type ) ;
V_63 -> V_75 . V_76 . V_73 = V_12 -> V_19 ;
return 0 ;
}
static unsigned int F_23 ( struct V_9 * V_10 , T_1 V_80 ,
T_1 V_79 , T_1 V_23 )
{
return F_24 ( F_25 ( V_80 , V_79 * V_23 / 8 ,
V_79 * V_23 * 2 ) , V_84 ) ;
}
static int F_26 ( struct V_9 * V_10 , const struct V_26 * V_33 ,
struct V_74 * V_63 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned int V_34 , V_35 ;
enum V_85 V_77 ;
V_77 = V_63 -> V_75 . V_76 . V_77 ;
if ( V_77 == V_86 )
V_77 = V_78 ;
else if ( V_78 != V_77 )
return - V_70 ;
V_63 -> V_75 . V_76 . V_77 = V_77 ;
F_10 ( V_2 , V_33 , & V_34 , & V_35 ) ;
F_27 ( & V_63 -> V_75 . V_76 . V_79 , V_87 , V_34 , V_88 ,
& V_63 -> V_75 . V_76 . V_23 , V_89 , V_35 , V_90 ,
V_91 ) ;
switch ( V_63 -> V_75 . V_76 . V_73 ) {
case V_20 :
case V_21 :
case V_24 :
V_63 -> V_75 . V_76 . V_22 = F_24 ( V_63 -> V_75 . V_76 . V_79 , 16 ) ;
V_63 -> V_75 . V_76 . V_80 = V_63 -> V_75 . V_76 . V_22 *
V_63 -> V_75 . V_76 . V_23 * 3 / 2 ;
break;
case V_25 :
V_63 -> V_75 . V_76 . V_22 = F_24 ( V_63 -> V_75 . V_76 . V_79 , 16 ) ;
V_63 -> V_75 . V_76 . V_80 = V_63 -> V_75 . V_76 . V_22 *
V_63 -> V_75 . V_76 . V_23 * 2 ;
break;
case V_81 :
V_63 -> V_75 . V_76 . V_82 = V_83 ;
case V_92 :
case V_93 :
V_63 -> V_75 . V_76 . V_22 = 0 ;
V_63 -> V_75 . V_76 . V_80 = F_23 ( V_10 ,
V_63 -> V_75 . V_76 . V_80 ,
V_63 -> V_75 . V_76 . V_79 ,
V_63 -> V_75 . V_76 . V_23 ) ;
break;
default:
F_28 () ;
}
return 0 ;
}
static int F_29 ( struct V_49 * V_49 , void * V_50 ,
struct V_74 * V_63 )
{
struct V_9 * V_10 = F_16 ( V_50 ) ;
const struct V_11 * V_94 ;
const struct V_26 * V_33 ;
struct V_95 * V_96 ;
int V_97 ;
V_97 = F_22 ( V_10 , V_63 ) ;
if ( V_97 < 0 )
return V_97 ;
V_94 = F_21 ( V_10 , V_66 ) ;
V_96 = F_30 ( V_10 -> V_98 . V_99 , V_66 ) ;
if ( F_31 ( V_96 ) ) {
V_63 -> V_75 . V_76 . V_79 = V_94 -> V_79 ;
V_63 -> V_75 . V_76 . V_23 = V_94 -> V_23 ;
}
V_63 -> V_75 . V_76 . V_82 = V_10 -> V_82 ;
V_94 = F_21 ( V_10 , V_66 ) ;
V_33 = F_9 ( V_10 -> V_2 , V_94 -> V_19 ,
V_63 -> V_75 . V_76 . V_73 ) ;
if ( ! V_33 )
return - V_70 ;
V_97 = F_26 ( V_10 , V_33 , V_63 ) ;
if ( V_97 < 0 )
return V_97 ;
if ( V_33 && V_33 -> V_27 == V_92 ) {
V_63 -> V_75 . V_76 . V_79 = V_63 -> V_75 . V_76 . V_79 ;
V_63 -> V_75 . V_76 . V_23 = F_24 ( V_63 -> V_75 . V_76 . V_23 , 16 ) ;
V_63 -> V_75 . V_76 . V_22 = F_24 ( V_63 -> V_75 . V_76 . V_79 , 16 ) ;
V_63 -> V_75 . V_76 . V_80 = V_63 -> V_75 . V_76 . V_22 *
V_63 -> V_75 . V_76 . V_23 * 3 / 2 ;
}
return 0 ;
}
static int F_32 ( struct V_49 * V_49 , void * V_50 ,
struct V_74 * V_63 )
{
struct V_9 * V_10 = F_16 ( V_50 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
const struct V_11 * V_100 ;
const struct V_26 * V_33 ;
int V_97 ;
V_97 = F_22 ( V_10 , V_63 ) ;
if ( V_97 < 0 )
return V_97 ;
switch ( V_63 -> V_75 . V_76 . V_82 ) {
case V_101 :
case V_83 :
break;
default:
if ( V_63 -> V_75 . V_76 . V_73 == V_81 )
V_63 -> V_75 . V_76 . V_82 = V_83 ;
else
V_63 -> V_75 . V_76 . V_82 = V_101 ;
}
V_100 = F_21 ( V_10 , V_68 ) ;
V_33 = F_9 ( V_2 , V_63 -> V_75 . V_76 . V_73 , V_100 -> V_19 ) ;
return F_26 ( V_10 , V_33 , V_63 ) ;
}
static int F_33 ( struct V_9 * V_10 , struct V_74 * V_63 )
{
struct V_11 * V_12 ;
struct V_95 * V_102 ;
V_102 = F_30 ( V_10 -> V_98 . V_99 , V_63 -> type ) ;
if ( ! V_102 )
return - V_70 ;
V_12 = F_21 ( V_10 , V_63 -> type ) ;
if ( ! V_12 )
return - V_70 ;
if ( F_34 ( V_102 ) ) {
F_35 ( & V_10 -> V_2 -> V_6 , L_7 , V_7 ) ;
return - V_103 ;
}
V_12 -> V_19 = V_63 -> V_75 . V_76 . V_73 ;
V_12 -> V_79 = V_63 -> V_75 . V_76 . V_79 ;
V_12 -> V_23 = V_63 -> V_75 . V_76 . V_23 ;
V_12 -> V_22 = V_63 -> V_75 . V_76 . V_22 ;
V_12 -> V_80 = V_63 -> V_75 . V_76 . V_80 ;
V_12 -> V_104 . V_105 = 0 ;
V_12 -> V_104 . V_106 = 0 ;
V_12 -> V_104 . V_79 = V_63 -> V_75 . V_76 . V_79 ;
V_12 -> V_104 . V_23 = V_63 -> V_75 . V_76 . V_23 ;
switch ( V_63 -> V_75 . V_76 . V_73 ) {
case V_20 :
if ( V_63 -> type == V_66 ) {
V_10 -> V_107 = V_108 ;
if ( ! V_109 )
break;
}
case V_21 :
case V_24 :
V_10 -> V_107 = V_110 ;
break;
default:
break;
}
F_2 ( 1 , V_5 , & V_10 -> V_2 -> V_6 ,
L_8 ,
V_63 -> type , V_12 -> V_79 , V_12 -> V_23 , V_12 -> V_19 ) ;
return 0 ;
}
static int F_36 ( struct V_49 * V_49 , void * V_50 ,
struct V_74 * V_63 )
{
struct V_9 * V_10 = F_16 ( V_50 ) ;
int V_97 ;
V_97 = F_29 ( V_49 , V_50 , V_63 ) ;
if ( V_97 )
return V_97 ;
return F_33 ( V_10 , V_63 ) ;
}
static int F_37 ( struct V_49 * V_49 , void * V_50 ,
struct V_74 * V_63 )
{
struct V_9 * V_10 = F_16 ( V_50 ) ;
struct V_74 V_111 ;
int V_97 ;
V_97 = F_32 ( V_49 , V_50 , V_63 ) ;
if ( V_97 )
return V_97 ;
V_97 = F_33 ( V_10 , V_63 ) ;
if ( V_97 )
return V_97 ;
V_10 -> V_82 = V_63 -> V_75 . V_76 . V_82 ;
memset ( & V_111 , 0 , sizeof( V_111 ) ) ;
V_111 . type = V_68 ;
F_20 ( V_49 , V_50 , & V_111 ) ;
V_111 . V_75 . V_76 . V_79 = V_63 -> V_75 . V_76 . V_79 ;
V_111 . V_75 . V_76 . V_23 = V_63 -> V_75 . V_76 . V_23 ;
V_97 = F_29 ( V_49 , V_50 , & V_111 ) ;
if ( V_97 )
return V_97 ;
return F_33 ( V_10 , & V_111 ) ;
}
static int F_38 ( struct V_49 * V_49 , void * V_50 ,
struct V_112 * V_113 )
{
struct V_9 * V_10 = F_16 ( V_50 ) ;
int V_97 ;
V_97 = F_39 ( V_49 , V_10 -> V_98 . V_99 , V_113 ) ;
if ( V_97 )
return V_97 ;
if ( V_113 -> type == V_66 && V_10 -> V_114 -> V_115 )
return V_10 -> V_114 -> V_115 ( V_10 , V_113 ) ;
return 0 ;
}
static int F_40 ( struct V_49 * V_49 , void * V_50 ,
struct V_116 * V_14 )
{
struct V_9 * V_10 = F_16 ( V_50 ) ;
return F_41 ( V_49 , V_10 -> V_98 . V_99 , V_14 ) ;
}
static bool F_42 ( struct V_9 * V_10 ,
struct V_13 * V_14 )
{
struct V_95 * V_96 ;
V_96 = F_30 ( V_10 -> V_98 . V_99 , V_66 ) ;
return ( ( V_10 -> V_117 & V_118 ) &&
( V_14 -> V_119 . V_120 == ( V_10 -> V_121 - 1 ) ) ) ;
}
void F_43 ( struct V_9 * V_10 , struct V_13 * V_14 ,
enum V_122 V_123 )
{
const struct V_124 V_125 = {
. type = V_126
} ;
if ( F_42 ( V_10 , V_14 ) ) {
V_14 -> V_119 . V_127 |= V_128 ;
F_44 ( & V_10 -> V_98 , & V_125 ) ;
}
F_45 ( V_14 , V_123 ) ;
}
static int F_46 ( struct V_49 * V_49 , void * V_98 ,
struct V_129 * V_130 )
{
struct V_9 * V_10 = F_16 ( V_98 ) ;
struct V_11 * V_12 ;
struct V_131 V_132 , * V_133 ;
V_12 = F_21 ( V_10 , V_130 -> type ) ;
if ( ! V_12 )
return - V_70 ;
V_132 . V_105 = 0 ;
V_132 . V_106 = 0 ;
V_132 . V_79 = V_12 -> V_79 ;
V_132 . V_23 = V_12 -> V_23 ;
V_133 = & V_12 -> V_104 ;
switch ( V_130 -> V_134 ) {
case V_135 :
case V_136 :
V_133 = & V_132 ;
case V_137 :
if ( V_130 -> type != V_66 )
return - V_70 ;
break;
case V_138 :
case V_139 :
V_133 = & V_132 ;
case V_140 :
case V_141 :
if ( V_130 -> type != V_68 )
return - V_70 ;
break;
default:
return - V_70 ;
}
V_130 -> V_132 = * V_133 ;
return 0 ;
}
static int F_47 ( struct V_49 * V_49 , void * V_98 ,
struct V_142 * V_143 )
{
if ( V_143 -> V_144 != V_145 )
return - V_70 ;
if ( V_143 -> V_127 & V_146 )
return - V_70 ;
if ( ! ( V_143 -> V_127 & V_147 ) && ( V_143 -> V_148 . V_149 != 0 ) )
return - V_70 ;
return 0 ;
}
static int F_48 ( struct V_49 * V_49 , void * V_98 ,
struct V_142 * V_143 )
{
struct V_9 * V_10 = F_16 ( V_98 ) ;
int V_97 ;
V_97 = F_47 ( V_49 , V_98 , V_143 ) ;
if ( V_97 < 0 )
return V_97 ;
if ( V_10 -> V_150 != V_151 )
return 0 ;
F_49 ( V_10 ) ;
V_10 -> V_152 = false ;
F_50 ( V_10 -> V_98 . V_99 ) ;
return 0 ;
}
static int F_51 ( struct V_49 * V_49 , void * V_98 , struct V_153 * V_154 )
{
struct V_9 * V_10 = F_16 ( V_98 ) ;
struct V_155 * V_156 ;
if ( V_154 -> type != V_66 )
return - V_70 ;
V_154 -> V_157 . V_158 . V_159 = V_160 ;
V_156 = & V_154 -> V_157 . V_158 . V_161 ;
V_156 -> V_162 = V_10 -> V_163 . V_164 & V_165 ;
V_156 -> V_166 = 1 + ( V_10 -> V_163 . V_164 >>
V_167 ) ;
return 0 ;
}
static void F_52 ( struct V_155 * V_161 )
{
struct V_155 V_130 = * V_161 ;
struct V_155 V_168 ;
struct V_155 V_169 = { 1 , 0 } ;
struct V_155 V_170 = { 0 , 1 } ;
unsigned int V_41 , div , V_171 ;
if ( V_130 . V_166 == 0 || V_130 . V_162 / V_130 . V_166 > 65535 ) {
V_161 -> V_166 = 1 ;
V_161 -> V_162 = 65535 ;
return;
}
if ( V_130 . V_162 == 0 || V_130 . V_166 / V_130 . V_162 > 65536 ) {
V_161 -> V_166 = 1 ;
V_161 -> V_162 = 0 ;
return;
}
div = F_53 ( V_130 . V_166 , V_130 . V_162 ) ;
if ( div > 1 ) {
V_130 . V_166 /= div ;
V_130 . V_162 /= div ;
}
if ( V_130 . V_166 <= 65536 && V_130 . V_162 < 65536 ) {
* V_161 = V_130 ;
return;
}
while ( V_170 . V_166 <= 65536 && V_170 . V_162 < 65536 ) {
V_168 = V_169 ;
V_169 = V_170 ;
if ( V_130 . V_166 == 0 )
break;
V_41 = V_130 . V_162 / V_130 . V_166 ;
V_170 . V_166 = V_168 . V_166 + V_41 * V_169 . V_166 ;
V_170 . V_162 = V_168 . V_162 + V_41 * V_170 . V_162 ;
V_171 = V_130 . V_166 ;
V_130 . V_166 = V_130 . V_162 % V_130 . V_166 ;
V_130 . V_162 = V_171 ;
}
* V_161 = V_169 ;
}
static T_2 F_54 ( struct V_155 * V_161 )
{
return ( ( V_161 -> V_166 - 1 ) << V_167 ) |
V_161 -> V_162 ;
}
static int F_55 ( struct V_49 * V_49 , void * V_98 , struct V_153 * V_154 )
{
struct V_9 * V_10 = F_16 ( V_98 ) ;
struct V_155 * V_156 ;
if ( V_154 -> type != V_66 )
return - V_70 ;
V_156 = & V_154 -> V_157 . V_158 . V_161 ;
F_52 ( V_156 ) ;
V_10 -> V_163 . V_164 = F_54 ( V_156 ) ;
return 0 ;
}
static int F_56 ( struct V_172 * V_98 ,
const struct V_173 * V_174 )
{
switch ( V_174 -> type ) {
case V_126 :
return F_57 ( V_98 , V_174 , 0 , NULL ) ;
default:
return F_58 ( V_98 , V_174 ) ;
}
}
static void F_59 ( void * V_175 )
{
struct V_9 * V_10 = V_175 ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_60 ( V_2 -> V_176 , & V_10 -> V_177 ) ;
}
static void F_61 ( struct V_178 * V_179 )
{
struct V_9 * V_10 = F_62 ( V_179 , struct V_9 , V_177 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_97 ;
F_63 ( & V_10 -> V_180 ) ;
F_63 ( & V_2 -> V_181 ) ;
V_97 = V_10 -> V_114 -> V_182 ( V_10 ) ;
if ( V_97 < 0 && V_10 -> V_150 == V_151 ) {
F_64 ( & V_2 -> V_181 ) ;
F_64 ( & V_10 -> V_180 ) ;
return;
}
if ( ! F_65 ( & V_10 -> V_183 ,
F_66 ( 1000 ) ) ) {
F_67 ( & V_2 -> V_184 -> V_2 , L_9 ) ;
V_10 -> V_152 = true ;
F_68 ( V_10 ) ;
} else if ( ! V_10 -> V_185 ) {
V_10 -> V_114 -> V_186 ( V_10 ) ;
}
if ( ( V_10 -> V_185 || ( ! V_10 -> V_187 && ! V_10 -> V_188 ) ) &&
V_10 -> V_114 -> V_189 )
F_60 ( V_2 -> V_176 , & V_10 -> V_189 ) ;
F_64 ( & V_2 -> V_181 ) ;
F_64 ( & V_10 -> V_180 ) ;
F_69 ( V_10 -> V_2 -> V_190 , V_10 -> V_98 . V_99 ) ;
}
static int F_70 ( void * V_175 )
{
struct V_9 * V_10 = V_175 ;
int V_191 = F_71 ( V_10 -> V_98 . V_99 ) ;
if ( ! V_191 && V_10 -> V_150 != V_151 ) {
F_2 ( 1 , V_5 , & V_10 -> V_2 -> V_6 ,
L_10 ) ;
return 0 ;
}
if ( ! F_72 ( V_10 -> V_98 . V_99 ) ) {
F_2 ( 1 , V_5 , & V_10 -> V_2 -> V_6 ,
L_11 ) ;
return 0 ;
}
if ( V_10 -> V_150 == V_151 && V_10 -> V_192 ) {
bool V_193 = V_10 -> V_117 &
V_118 ;
int V_194 = V_10 -> V_194 ;
if ( V_10 -> V_152 && ! V_191 ) {
F_2 ( 1 , V_5 , & V_10 -> V_2 -> V_6 ,
L_12 ,
V_10 -> V_195 ) ;
return 0 ;
}
if ( ! V_193 && ( V_194 + V_191 ) < 2 ) {
F_2 ( 1 , V_5 , & V_10 -> V_2 -> V_6 ,
L_13 ,
V_10 -> V_195 , V_194 , V_191 ) ;
return 0 ;
}
if ( ! V_191 && ! V_193 &&
( F_73 ( V_10 ) < 512 ) ) {
F_2 ( 1 , V_5 , & V_10 -> V_2 -> V_6 ,
L_14 ,
V_10 -> V_195 , F_73 ( V_10 ) ) ;
return 0 ;
}
}
if ( V_10 -> V_185 ) {
F_2 ( 1 , V_5 , & V_10 -> V_2 -> V_6 ,
L_15 ) ;
return 0 ;
}
F_2 ( 1 , V_5 , & V_10 -> V_2 -> V_6 ,
L_16 ) ;
return 1 ;
}
static void F_74 ( void * V_50 )
{
struct V_9 * V_10 = V_50 ;
V_10 -> V_185 = 1 ;
F_2 ( 1 , V_5 , & V_10 -> V_2 -> V_6 ,
L_17 ) ;
}
static void F_75 ( void * V_175 )
{
struct V_9 * V_10 = V_175 ;
struct V_1 * V_196 = V_10 -> V_2 ;
F_63 ( & V_196 -> V_197 ) ;
}
static void F_76 ( void * V_175 )
{
struct V_9 * V_10 = V_175 ;
struct V_1 * V_196 = V_10 -> V_2 ;
F_64 ( & V_196 -> V_197 ) ;
}
static void F_77 ( struct V_9 * V_10 )
{
unsigned int V_34 , V_35 , V_198 , V_199 ;
V_10 -> V_33 = F_9 ( V_10 -> V_2 , V_10 -> V_64 -> V_67 [ 0 ] ,
V_10 -> V_64 -> V_69 [ 0 ] ) ;
V_34 = F_78 ( V_10 -> V_33 -> V_34 , 1920U ) ;
V_35 = F_78 ( V_10 -> V_33 -> V_35 , 1088U ) ;
V_198 = V_34 * V_35 * 3 / 2 ;
V_199 = F_23 ( V_10 , V_198 , V_34 , V_35 ) ;
V_10 -> V_163 . V_200 = V_10 -> V_33 -> V_201 ;
V_10 -> V_82 = V_101 ;
V_10 -> V_163 . V_164 = 30 ;
V_10 -> V_12 [ V_202 ] . V_19 = V_10 -> V_64 -> V_67 [ 0 ] ;
V_10 -> V_12 [ V_203 ] . V_19 = V_10 -> V_64 -> V_69 [ 0 ] ;
V_10 -> V_12 [ V_202 ] . V_79 = V_34 ;
V_10 -> V_12 [ V_202 ] . V_23 = V_35 ;
V_10 -> V_12 [ V_203 ] . V_79 = V_34 ;
V_10 -> V_12 [ V_203 ] . V_23 = V_35 ;
if ( V_10 -> V_33 -> V_27 == V_21 ) {
V_10 -> V_12 [ V_202 ] . V_22 = V_34 ;
V_10 -> V_12 [ V_202 ] . V_80 = V_198 ;
V_10 -> V_12 [ V_203 ] . V_22 = 0 ;
V_10 -> V_12 [ V_203 ] . V_80 = V_199 ;
} else {
V_10 -> V_12 [ V_202 ] . V_22 = 0 ;
V_10 -> V_12 [ V_202 ] . V_80 = V_199 ;
V_10 -> V_12 [ V_203 ] . V_22 = V_34 ;
V_10 -> V_12 [ V_203 ] . V_80 = V_198 ;
}
V_10 -> V_12 [ V_202 ] . V_104 . V_79 = V_34 ;
V_10 -> V_12 [ V_202 ] . V_104 . V_23 = V_35 ;
V_10 -> V_12 [ V_203 ] . V_104 . V_79 = V_34 ;
V_10 -> V_12 [ V_203 ] . V_104 . V_23 = V_35 ;
V_10 -> V_107 = V_110 ;
}
static int F_79 ( struct V_95 * V_102 ,
const struct V_74 * V_75 ,
unsigned int * V_204 , unsigned int * V_205 ,
unsigned int V_206 [] , void * V_207 [] )
{
struct V_9 * V_10 = F_80 ( V_102 ) ;
struct V_11 * V_12 ;
unsigned int V_208 ;
V_12 = F_21 ( V_10 , V_102 -> type ) ;
V_208 = V_12 -> V_80 ;
* V_205 = 1 ;
V_206 [ 0 ] = V_208 ;
V_207 [ 0 ] = V_10 -> V_2 -> V_209 ;
F_2 ( 1 , V_5 , & V_10 -> V_2 -> V_6 ,
L_18 , * V_204 , V_208 ) ;
return 0 ;
}
static int F_81 ( struct V_13 * V_210 )
{
struct V_9 * V_10 = F_80 ( V_210 -> V_95 ) ;
struct V_11 * V_12 ;
V_12 = F_21 ( V_10 , V_210 -> V_95 -> type ) ;
if ( F_82 ( V_210 , 0 ) < V_12 -> V_80 ) {
F_83 ( & V_10 -> V_2 -> V_6 ,
L_19 ,
V_7 , F_82 ( V_210 , 0 ) ,
( long ) V_12 -> V_80 ) ;
return - V_70 ;
}
return 0 ;
}
static void F_84 ( struct V_13 * V_210 )
{
struct V_9 * V_10 = F_80 ( V_210 -> V_95 ) ;
struct V_95 * V_102 = V_210 -> V_95 ;
struct V_11 * V_12 ;
V_12 = F_21 ( V_10 , V_210 -> V_95 -> type ) ;
if ( V_10 -> V_211 . V_208 && V_102 -> type == V_66 ) {
if ( F_85 ( V_210 , 0 ) == 0 )
F_49 ( V_10 ) ;
F_63 ( & V_10 -> V_212 ) ;
F_86 ( V_10 -> V_98 . V_99 , V_210 ) ;
if ( F_31 ( V_210 -> V_95 ) )
F_87 ( V_10 , true ) ;
F_64 ( & V_10 -> V_212 ) ;
} else {
F_86 ( V_10 -> V_98 . V_99 , V_210 ) ;
}
}
int F_88 ( struct V_1 * V_2 , struct V_213 * V_14 ,
T_3 V_208 , const char * V_214 , struct V_215 * V_216 )
{
V_14 -> V_217 = F_89 ( & V_2 -> V_184 -> V_2 , V_208 , & V_14 -> V_218 ,
V_219 ) ;
if ( ! V_14 -> V_217 ) {
F_35 ( & V_2 -> V_6 ,
L_20 ,
V_214 , V_208 ) ;
return - V_220 ;
}
V_14 -> V_208 = V_208 ;
if ( V_214 && V_216 ) {
V_14 -> V_221 . V_3 = V_14 -> V_217 ;
V_14 -> V_221 . V_208 = V_208 ;
V_14 -> V_215 = F_90 ( V_214 , 0644 , V_216 ,
& V_14 -> V_221 ) ;
if ( ! V_14 -> V_215 )
F_91 ( & V_2 -> V_184 -> V_2 ,
L_21 , V_214 ) ;
}
return 0 ;
}
void F_92 ( struct V_1 * V_2 ,
struct V_213 * V_14 )
{
if ( V_14 -> V_217 ) {
F_93 ( & V_2 -> V_184 -> V_2 , V_14 -> V_208 ,
V_14 -> V_217 , V_14 -> V_218 ) ;
V_14 -> V_217 = NULL ;
V_14 -> V_208 = 0 ;
F_94 ( V_14 -> V_215 ) ;
V_14 -> V_215 = NULL ;
}
}
static int F_95 ( struct V_95 * V_222 , unsigned int V_223 )
{
struct V_9 * V_10 = F_80 ( V_222 ) ;
struct V_224 * V_6 = & V_10 -> V_2 -> V_6 ;
struct V_11 * V_94 , * V_100 ;
struct V_13 * V_14 ;
int V_97 = 0 ;
V_94 = F_21 ( V_10 , V_66 ) ;
if ( V_222 -> type == V_66 ) {
if ( V_10 -> V_150 == V_151 && V_10 -> V_192 ) {
F_63 ( & V_10 -> V_212 ) ;
F_87 ( V_10 , false ) ;
F_64 ( & V_10 -> V_212 ) ;
if ( F_73 ( V_10 ) < 512 ) {
V_97 = - V_70 ;
goto V_225;
}
} else {
if ( V_223 < 1 ) {
V_97 = - V_70 ;
goto V_225;
}
}
V_10 -> V_188 = 1 ;
} else {
if ( V_223 < 1 ) {
V_97 = - V_70 ;
goto V_225;
}
V_10 -> V_187 = 1 ;
}
if ( ! ( V_10 -> V_188 & V_10 -> V_187 ) )
return 0 ;
V_100 = F_21 ( V_10 , V_68 ) ;
if ( ( V_94 -> V_79 != V_100 -> V_79 &&
F_24 ( V_94 -> V_79 , 16 ) != V_100 -> V_79 ) ||
( V_94 -> V_23 != V_100 -> V_23 &&
F_24 ( V_94 -> V_23 , 16 ) != V_100 -> V_23 ) ) {
F_35 ( V_6 , L_22 ,
V_94 -> V_79 , V_94 -> V_23 ,
V_100 -> V_79 , V_100 -> V_23 ) ;
V_97 = - V_70 ;
goto V_225;
}
if ( V_10 -> V_150 == V_151 && V_10 -> V_192 )
F_96 ( V_10 -> V_98 . V_99 , true ) ;
V_10 -> V_226 = V_10 -> V_163 . V_227 - 1 ;
V_10 -> V_33 = F_9 ( V_10 -> V_2 , V_94 -> V_19 ,
V_100 -> V_19 ) ;
if ( ! V_10 -> V_33 ) {
F_35 ( V_6 , L_23 ) ;
V_97 = - V_70 ;
goto V_225;
}
if ( V_100 -> V_19 == V_81 )
V_10 -> V_163 . V_227 = 1 ;
V_10 -> V_226 = V_10 -> V_163 . V_227 - 1 ;
V_97 = V_10 -> V_114 -> V_228 ( V_10 ) ;
if ( V_10 -> V_150 == V_151 ) {
if ( V_97 == - V_229 )
return 0 ;
else if ( V_97 < 0 )
goto V_225;
}
return V_97 ;
V_225:
if ( V_222 -> type == V_66 ) {
while ( ( V_14 = F_97 ( V_10 -> V_98 . V_99 ) ) )
F_45 ( V_14 , V_230 ) ;
} else {
while ( ( V_14 = F_98 ( V_10 -> V_98 . V_99 ) ) )
F_45 ( V_14 , V_230 ) ;
}
return V_97 ;
}
static void F_99 ( struct V_95 * V_222 )
{
struct V_9 * V_10 = F_80 ( V_222 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_13 * V_14 ;
unsigned long V_127 ;
bool V_148 ;
V_148 = V_10 -> V_188 && V_10 -> V_187 ;
if ( V_222 -> type == V_66 ) {
F_2 ( 1 , V_5 , & V_2 -> V_6 ,
L_24 , V_7 ) ;
V_10 -> V_188 = 0 ;
F_49 ( V_10 ) ;
V_10 -> V_121 = 0 ;
while ( ( V_14 = F_97 ( V_10 -> V_98 . V_99 ) ) )
F_45 ( V_14 , V_231 ) ;
} else {
F_2 ( 1 , V_5 , & V_2 -> V_6 ,
L_25 , V_7 ) ;
V_10 -> V_187 = 0 ;
V_10 -> V_232 = 0 ;
V_10 -> V_233 = 0 ;
while ( ( V_14 = F_98 ( V_10 -> V_98 . V_99 ) ) )
F_45 ( V_14 , V_231 ) ;
}
if ( V_148 ) {
struct V_234 * V_235 ;
if ( V_10 -> V_114 -> V_189 ) {
F_60 ( V_2 -> V_176 , & V_10 -> V_189 ) ;
F_100 ( & V_10 -> V_189 ) ;
}
F_101 ( & V_10 -> V_236 , V_127 ) ;
while ( ! F_102 ( & V_10 -> V_237 ) ) {
V_235 = F_103 ( & V_10 -> V_237 ,
struct V_234 , V_238 ) ;
F_104 ( & V_235 -> V_238 ) ;
F_105 ( V_235 ) ;
}
V_10 -> V_194 = 0 ;
F_106 ( & V_10 -> V_236 , V_127 ) ;
F_107 ( & V_10 -> V_239 ,
V_10 -> V_211 . V_217 , V_10 -> V_211 . V_208 ) ;
V_10 -> V_240 = 0 ;
V_10 -> V_185 = 0 ;
}
if ( ! V_10 -> V_188 && ! V_10 -> V_187 )
V_10 -> V_117 &= ~ V_118 ;
}
static int F_108 ( struct V_241 * V_242 )
{
struct V_9 * V_10 =
F_62 ( V_242 -> V_243 , struct V_9 , V_244 ) ;
F_2 ( 1 , V_5 , & V_10 -> V_2 -> V_6 ,
L_26 , V_242 -> V_245 , V_242 -> V_246 ) ;
switch ( V_242 -> V_245 ) {
case V_247 :
if ( V_242 -> V_246 )
V_10 -> V_163 . V_248 |= V_249 ;
else
V_10 -> V_163 . V_248 &= ~ V_249 ;
break;
case V_250 :
if ( V_242 -> V_246 )
V_10 -> V_163 . V_248 |= V_251 ;
else
V_10 -> V_163 . V_248 &= ~ V_251 ;
break;
case V_252 :
V_10 -> V_163 . V_253 = V_242 -> V_246 / 1000 ;
break;
case V_254 :
V_10 -> V_163 . V_227 = V_242 -> V_246 ;
break;
case V_255 :
V_10 -> V_163 . V_256 = V_242 -> V_246 ;
break;
case V_257 :
V_10 -> V_163 . V_258 = V_242 -> V_246 ;
break;
case V_259 :
V_10 -> V_163 . V_260 = V_242 -> V_246 ;
break;
case V_261 :
V_10 -> V_163 . V_262 = V_242 -> V_246 ;
break;
case V_263 :
V_10 -> V_163 . V_264 = V_242 -> V_246 ;
break;
case V_265 :
V_10 -> V_163 . V_266 = V_242 -> V_246 ;
break;
case V_267 :
V_10 -> V_163 . V_268 = ( V_242 -> V_246 ==
V_269 ) ;
break;
case V_270 :
V_10 -> V_163 . V_271 = V_242 -> V_246 ;
break;
case V_272 :
V_10 -> V_163 . V_273 = V_242 -> V_246 ;
break;
case V_274 :
V_10 -> V_163 . V_275 = V_242 -> V_246 ;
break;
case V_276 :
V_10 -> V_163 . V_277 = V_242 -> V_246 ;
break;
case V_278 :
V_10 -> V_163 . V_279 = V_242 -> V_246 * 8 ;
break;
case V_280 :
break;
case V_281 :
V_10 -> V_163 . V_282 = V_242 -> V_246 ;
break;
case V_283 :
F_109 ( V_10 , V_242 -> V_246 ) ;
break;
case V_284 :
V_10 -> V_163 . V_285 = V_242 -> V_246 ;
break;
case V_286 :
V_10 -> V_163 . V_287 = V_242 -> V_246 ;
break;
case V_288 :
V_10 -> V_163 . V_289 = F_78 ( V_242 -> V_246 * 8192 , 0x7fffffff ) ;
break;
default:
F_2 ( 1 , V_5 , & V_10 -> V_2 -> V_6 ,
L_27 ,
V_242 -> V_245 , V_242 -> V_246 ) ;
return - V_70 ;
}
return 0 ;
}
static void F_110 ( struct V_9 * V_10 )
{
F_111 ( & V_10 -> V_244 , & V_290 ,
V_252 , 0 , 32767000 , 1000 , 0 ) ;
F_111 ( & V_10 -> V_244 , & V_290 ,
V_254 , 1 , 60 , 1 , 16 ) ;
F_111 ( & V_10 -> V_244 , & V_290 ,
V_255 , 0 , 51 , 1 , 25 ) ;
F_111 ( & V_10 -> V_244 , & V_290 ,
V_257 , 0 , 51 , 1 , 25 ) ;
if ( V_10 -> V_2 -> V_30 -> V_45 != V_48 ) {
F_111 ( & V_10 -> V_244 , & V_290 ,
V_259 , 0 , 51 , 1 , 12 ) ;
}
F_111 ( & V_10 -> V_244 , & V_290 ,
V_261 , 0 , 51 , 1 , 51 ) ;
F_111 ( & V_10 -> V_244 , & V_290 ,
V_263 , 0 , 15 , 1 , 0 ) ;
F_111 ( & V_10 -> V_244 , & V_290 ,
V_265 , 0 , 15 , 1 , 0 ) ;
F_112 ( & V_10 -> V_244 , & V_290 ,
V_267 ,
V_291 , 0x0 ,
V_269 ) ;
F_111 ( & V_10 -> V_244 , & V_290 ,
V_270 , 1 , 31 , 1 , 2 ) ;
F_111 ( & V_10 -> V_244 , & V_290 ,
V_272 , 1 , 31 , 1 , 2 ) ;
F_112 ( & V_10 -> V_244 , & V_290 ,
V_274 ,
V_292 , 0x0 ,
V_293 ) ;
F_111 ( & V_10 -> V_244 , & V_290 ,
V_276 , 1 , 0x3fffffff , 1 , 1 ) ;
F_111 ( & V_10 -> V_244 , & V_290 ,
V_278 , 1 , 0x3fffffff , 1 ,
500 ) ;
F_112 ( & V_10 -> V_244 , & V_290 ,
V_280 ,
V_294 ,
( 1 << V_295 ) ,
V_294 ) ;
F_111 ( & V_10 -> V_244 , & V_290 ,
V_281 , 0 ,
1920 * 1088 / 256 , 1 , 0 ) ;
F_111 ( & V_10 -> V_244 , & V_290 ,
V_286 , 0 , 0x7fff , 1 , 0 ) ;
F_111 ( & V_10 -> V_244 , & V_290 ,
V_288 , 0 , 262144 , 1 , 0 ) ;
}
static void F_113 ( struct V_9 * V_10 )
{
F_111 ( & V_10 -> V_244 , & V_290 ,
V_283 , 5 , 100 , 1 , 50 ) ;
F_111 ( & V_10 -> V_244 , & V_290 ,
V_284 , 0 , 100 , 1 , 0 ) ;
}
static int F_114 ( struct V_9 * V_10 )
{
F_115 ( & V_10 -> V_244 , 2 ) ;
F_111 ( & V_10 -> V_244 , & V_290 ,
V_247 , 0 , 1 , 1 , 0 ) ;
F_111 ( & V_10 -> V_244 , & V_290 ,
V_250 , 0 , 1 , 1 , 0 ) ;
if ( V_10 -> V_150 == V_296 ) {
if ( V_10 -> V_64 -> V_69 [ 0 ] == V_81 )
F_113 ( V_10 ) ;
else
F_110 ( V_10 ) ;
}
if ( V_10 -> V_244 . error ) {
F_35 ( & V_10 -> V_2 -> V_6 ,
L_28 ,
V_10 -> V_244 . error ) ;
return - V_70 ;
}
return F_116 ( & V_10 -> V_244 ) ;
}
static int F_117 ( struct V_9 * V_10 , struct V_95 * V_102 )
{
V_102 -> V_297 = V_10 ;
V_102 -> V_114 = & V_298 ;
V_102 -> V_299 = sizeof( struct V_300 ) ;
V_102 -> V_301 = V_302 ;
V_102 -> V_303 = & V_10 -> V_2 -> V_197 ;
V_102 -> V_304 = 1 ;
return F_118 ( V_102 ) ;
}
int F_119 ( void * V_50 , struct V_95 * V_96 ,
struct V_95 * V_305 )
{
int V_97 ;
V_96 -> type = V_66 ;
V_96 -> V_306 = V_307 | V_308 ;
V_96 -> V_309 = & V_310 ;
V_97 = F_117 ( V_50 , V_96 ) ;
if ( V_97 )
return V_97 ;
V_305 -> type = V_68 ;
V_305 -> V_306 = V_307 | V_308 ;
V_305 -> V_309 = & V_310 ;
return F_117 ( V_50 , V_305 ) ;
}
int F_120 ( void * V_50 , struct V_95 * V_96 ,
struct V_95 * V_305 )
{
int V_97 ;
V_96 -> type = V_66 ;
V_96 -> V_306 = V_307 | V_308 | V_311 ;
V_96 -> V_309 = & V_312 ;
V_97 = F_117 ( V_50 , V_96 ) ;
if ( V_97 )
return V_97 ;
V_305 -> type = V_68 ;
V_305 -> V_306 = V_307 | V_308 ;
V_305 -> V_309 = & V_310 ;
return F_117 ( V_50 , V_305 ) ;
}
static int F_121 ( struct V_1 * V_2 )
{
int V_195 = F_122 ( V_2 -> V_313 ) ;
if ( ( V_195 < 0 ) ||
( V_2 -> V_30 -> V_45 == V_46 && V_195 > V_314 ) )
return - V_103 ;
return V_195 ;
}
static int F_123 ( struct V_49 * V_49 )
{
struct V_39 * V_40 = F_19 ( V_49 ) ;
struct V_1 * V_2 = F_13 ( V_40 ) ;
struct V_9 * V_10 = NULL ;
char * V_214 ;
int V_97 ;
int V_195 ;
V_10 = F_124 ( sizeof( * V_10 ) , V_219 ) ;
if ( ! V_10 )
return - V_220 ;
V_195 = F_121 ( V_2 ) ;
if ( V_195 < 0 ) {
V_97 = V_195 ;
goto V_315;
}
F_125 ( V_195 , & V_2 -> V_313 ) ;
V_214 = F_126 ( V_219 , L_29 , V_195 ) ;
if ( ! V_214 ) {
V_97 = - V_220 ;
goto V_316;
}
V_10 -> V_317 = F_127 ( V_214 , V_2 -> V_318 ) ;
F_105 ( V_214 ) ;
V_10 -> V_64 = F_12 ( V_40 ) ;
V_10 -> V_150 = V_10 -> V_64 -> type ;
V_10 -> V_114 = V_10 -> V_64 -> V_114 ;
V_10 -> V_192 = ! V_10 -> V_64 -> V_319 ;
F_128 ( & V_10 -> V_183 ) ;
F_129 ( & V_10 -> V_177 , F_61 ) ;
if ( V_10 -> V_114 -> V_189 )
F_129 ( & V_10 -> V_189 , V_10 -> V_114 -> V_189 ) ;
F_130 ( & V_10 -> V_98 , F_19 ( V_49 ) ) ;
V_49 -> V_320 = & V_10 -> V_98 ;
F_131 ( & V_10 -> V_98 ) ;
V_10 -> V_2 = V_2 ;
V_10 -> V_195 = V_195 ;
switch ( V_2 -> V_30 -> V_45 ) {
case V_48 :
V_10 -> V_321 = 1 << 12 ;
case V_47 :
V_10 -> V_322 = 0 ;
break;
default:
V_10 -> V_322 = V_195 ;
}
V_97 = F_132 ( & V_2 -> V_184 -> V_2 ) ;
if ( V_97 < 0 ) {
F_35 ( & V_2 -> V_6 , L_30 , V_97 ) ;
goto V_323;
}
V_97 = F_133 ( V_2 -> V_324 ) ;
if ( V_97 )
goto V_325;
V_97 = F_133 ( V_2 -> V_326 ) ;
if ( V_97 )
goto V_327;
F_77 ( V_10 ) ;
V_10 -> V_98 . V_99 = F_134 ( V_2 -> V_190 , V_10 ,
V_10 -> V_114 -> V_328 ) ;
if ( F_135 ( V_10 -> V_98 . V_99 ) ) {
V_97 = F_136 ( V_10 -> V_98 . V_99 ) ;
F_35 ( & V_2 -> V_6 , L_31 ,
V_7 , V_97 ) ;
goto V_329;
}
V_97 = F_114 ( V_10 ) ;
if ( V_97 ) {
F_35 ( & V_2 -> V_6 , L_32 ) ;
goto V_330;
}
V_10 -> V_98 . V_331 = & V_10 -> V_244 ;
F_137 ( & V_10 -> V_212 ) ;
F_137 ( & V_10 -> V_180 ) ;
F_138 ( & V_10 -> V_237 ) ;
F_139 ( & V_10 -> V_236 ) ;
F_75 ( V_10 ) ;
F_140 ( & V_10 -> V_238 , & V_2 -> V_332 ) ;
F_76 ( V_10 ) ;
F_2 ( 1 , V_5 , & V_2 -> V_6 , L_33 ,
V_10 -> V_195 , V_10 ) ;
return 0 ;
V_330:
F_141 ( V_10 -> V_98 . V_99 ) ;
V_329:
F_142 ( V_2 -> V_326 ) ;
V_327:
F_142 ( V_2 -> V_324 ) ;
V_325:
F_143 ( & V_2 -> V_184 -> V_2 ) ;
V_323:
F_144 ( & V_10 -> V_98 ) ;
F_145 ( & V_10 -> V_98 ) ;
F_146 ( V_10 -> V_195 , & V_2 -> V_313 ) ;
V_316:
V_315:
F_105 ( V_10 ) ;
return V_97 ;
}
static int F_147 ( struct V_49 * V_49 )
{
struct V_1 * V_2 = F_148 ( V_49 ) ;
struct V_9 * V_10 = F_16 ( V_49 -> V_320 ) ;
F_2 ( 1 , V_5 , & V_2 -> V_6 , L_34 ,
V_10 ) ;
if ( V_10 -> V_150 == V_151 && V_10 -> V_192 )
F_49 ( V_10 ) ;
F_141 ( V_10 -> V_98 . V_99 ) ;
if ( V_10 -> V_114 -> V_189 ) {
F_60 ( V_2 -> V_176 , & V_10 -> V_189 ) ;
F_100 ( & V_10 -> V_189 ) ;
}
F_75 ( V_10 ) ;
F_104 ( & V_10 -> V_238 ) ;
F_76 ( V_10 ) ;
if ( V_10 -> V_2 -> V_30 -> V_45 == V_46 )
F_92 ( V_2 , & V_10 -> V_333 ) ;
F_149 ( & V_10 -> V_244 ) ;
F_142 ( V_2 -> V_326 ) ;
F_142 ( V_2 -> V_324 ) ;
F_143 ( & V_2 -> V_184 -> V_2 ) ;
F_144 ( & V_10 -> V_98 ) ;
F_145 ( & V_10 -> V_98 ) ;
F_146 ( V_10 -> V_195 , & V_2 -> V_313 ) ;
if ( V_10 -> V_114 -> V_334 )
V_10 -> V_114 -> V_334 ( V_10 ) ;
F_150 ( V_10 -> V_317 ) ;
F_105 ( V_10 ) ;
return 0 ;
}
static int F_151 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_4 * V_335 ;
int V_41 , V_97 ;
V_97 = F_133 ( V_2 -> V_324 ) ;
if ( V_97 )
goto V_325;
V_97 = F_133 ( V_2 -> V_326 ) ;
if ( V_97 )
goto V_327;
if ( V_2 -> V_336 )
F_152 ( V_2 -> V_336 ) ;
V_335 = ( T_4 * ) V_2 -> V_337 . V_217 ;
if ( V_2 -> V_30 -> V_45 == V_46 ) {
for ( V_41 = 0 ; V_41 < ( V_338 / 2 ) ; V_41 ++ ) {
V_3 = F_153 ( V_41 ) |
F_154 ( V_335 [ V_41 ^ 1 ] ) ;
F_1 ( V_2 , V_3 , V_339 ) ;
}
} else {
for ( V_41 = 0 ; V_41 < ( V_338 / 2 ) ; V_41 ++ ) {
V_3 = F_153 ( V_41 ) |
F_154 ( V_335 [ F_155 ( V_41 , 4 ) +
3 - ( V_41 % 4 ) ] ) ;
F_1 ( V_2 , V_3 , V_339 ) ;
}
}
for ( V_41 = 0 ; V_41 < 64 ; V_41 ++ )
F_1 ( V_2 , 0 , V_340 + V_41 * 4 ) ;
if ( V_2 -> V_30 -> V_45 == V_48 ||
V_2 -> V_30 -> V_45 == V_47 ) {
F_1 ( V_2 , V_2 -> V_341 . V_218 ,
V_342 ) ;
F_1 ( V_2 , 0 , V_343 ) ;
} else {
F_1 ( V_2 , V_2 -> V_333 . V_218 ,
V_344 ) ;
}
F_1 ( V_2 , V_2 -> V_337 . V_218 ,
V_340 ) ;
F_1 ( V_2 , 0 , V_345 ) ;
switch ( V_2 -> V_30 -> V_45 ) {
case V_46 :
F_1 ( V_2 , V_346 ,
V_347 ) ;
break;
default:
F_1 ( V_2 , V_348 ,
V_347 ) ;
}
if ( V_2 -> V_30 -> V_45 == V_48 )
F_1 ( V_2 , 1 << 12 , V_349 ) ;
else
F_1 ( V_2 , 0 , V_349 ) ;
if ( V_2 -> V_30 -> V_45 != V_46 )
F_1 ( V_2 , 0 , V_350 ) ;
F_1 ( V_2 , V_351 ,
V_352 ) ;
V_3 = F_4 ( V_2 , V_353 ) ;
V_3 |= V_354 ;
F_1 ( V_2 , V_3 , V_353 ) ;
F_156 ( 10 ) ;
V_3 &= ~ V_354 ;
F_1 ( V_2 , V_3 , V_353 ) ;
F_1 ( V_2 , V_355 , V_345 ) ;
F_142 ( V_2 -> V_326 ) ;
F_142 ( V_2 -> V_324 ) ;
return 0 ;
V_327:
F_142 ( V_2 -> V_324 ) ;
V_325:
return V_97 ;
}
static int F_157 ( struct V_1 * V_2 , int V_41 )
{
struct V_39 * V_42 = & V_2 -> V_42 [ V_41 ] ;
if ( V_41 >= V_2 -> V_30 -> V_43 )
return - V_70 ;
F_17 ( V_42 -> V_214 , V_2 -> V_30 -> V_44 [ V_41 ] -> V_214 , sizeof( V_42 -> V_214 ) ) ;
V_42 -> V_356 = & V_357 ;
V_42 -> V_358 = & V_359 ;
V_42 -> V_334 = V_360 ,
V_42 -> V_303 = & V_2 -> V_197 ;
V_42 -> V_6 = & V_2 -> V_6 ;
V_42 -> V_361 = V_362 ;
F_158 ( V_42 , V_2 ) ;
F_159 ( V_42 , V_363 ) ;
F_159 ( V_42 , V_364 ) ;
F_159 ( V_42 , V_365 ) ;
return F_160 ( V_42 , V_366 , 0 ) ;
}
static void F_161 ( const struct V_367 * V_368 , void * V_369 )
{
struct V_1 * V_2 = V_369 ;
struct V_370 * V_371 = V_2 -> V_184 ;
int V_41 , V_97 ;
if ( ! V_368 ) {
F_35 ( & V_2 -> V_6 , L_35 ) ;
goto V_372;
}
V_97 = F_88 ( V_2 , & V_2 -> V_337 , V_368 -> V_208 , L_36 ,
V_2 -> V_318 ) ;
if ( V_97 < 0 )
goto V_372;
memcpy ( V_2 -> V_337 . V_217 , V_368 -> V_3 , V_368 -> V_208 ) ;
F_162 ( V_368 ) ;
V_97 = F_151 ( V_2 ) ;
if ( V_97 < 0 ) {
F_35 ( & V_2 -> V_6 , L_37 ) ;
goto V_372;
}
V_97 = F_163 ( V_2 ) ;
if ( V_97 < 0 )
goto V_372;
V_2 -> V_209 = F_164 ( & V_371 -> V_2 ) ;
if ( F_135 ( V_2 -> V_209 ) ) {
F_35 ( & V_2 -> V_6 , L_38 ) ;
goto V_372;
}
V_2 -> V_190 = F_165 ( & V_373 ) ;
if ( F_135 ( V_2 -> V_190 ) ) {
F_35 ( & V_2 -> V_6 , L_39 ) ;
goto V_374;
}
for ( V_41 = 0 ; V_41 < V_2 -> V_30 -> V_43 ; V_41 ++ ) {
V_97 = F_157 ( V_2 , V_41 ) ;
if ( V_97 ) {
F_35 ( & V_2 -> V_6 ,
L_40 ,
V_2 -> V_30 -> V_44 [ V_41 ] -> V_214 , V_97 ) ;
goto V_375;
}
}
F_166 ( & V_2 -> V_6 , L_41 ,
V_2 -> V_42 [ 0 ] . V_376 , V_2 -> V_42 [ V_41 - 1 ] . V_376 ) ;
F_143 ( & V_371 -> V_2 ) ;
return;
V_375:
while ( -- V_41 >= 0 )
F_167 ( & V_2 -> V_42 [ V_41 ] ) ;
F_168 ( V_2 -> V_190 ) ;
V_374:
F_169 ( V_2 -> V_209 ) ;
V_372:
F_143 ( & V_371 -> V_2 ) ;
}
static int F_170 ( struct V_1 * V_2 )
{
char * V_368 = V_2 -> V_30 -> V_367 ;
F_171 ( & V_2 -> V_184 -> V_2 , L_42 , V_368 ,
F_14 ( V_2 -> V_30 -> V_45 ) ) ;
return F_172 ( V_377 , true ,
V_368 , & V_2 -> V_184 -> V_2 , V_219 , V_2 , F_161 ) ;
}
static int F_173 ( struct V_370 * V_371 )
{
const struct V_378 * V_379 =
F_174 ( F_175 ( V_380 ) , & V_371 -> V_2 ) ;
const struct V_381 * V_382 ;
struct V_383 * V_384 = V_371 -> V_2 . V_385 ;
struct V_386 * V_387 = V_371 -> V_2 . V_388 ;
struct V_389 * V_390 ;
struct V_1 * V_2 ;
struct V_391 * V_392 ;
int V_97 , V_393 ;
V_2 = F_176 ( & V_371 -> V_2 , sizeof( * V_2 ) , V_219 ) ;
if ( ! V_2 )
return - V_220 ;
V_382 = V_379 ? V_379 -> V_3 : F_177 ( V_371 ) ;
if ( V_379 ) {
V_2 -> V_30 = V_379 -> V_3 ;
} else if ( V_382 ) {
V_2 -> V_30 = & V_394 [ V_382 -> V_395 ] ;
} else {
V_97 = - V_70 ;
goto V_396;
}
F_139 ( & V_2 -> V_397 ) ;
F_138 ( & V_2 -> V_332 ) ;
V_2 -> V_184 = V_371 ;
V_2 -> V_324 = F_178 ( & V_371 -> V_2 , L_43 ) ;
if ( F_135 ( V_2 -> V_324 ) ) {
F_67 ( & V_371 -> V_2 , L_44 ) ;
return F_136 ( V_2 -> V_324 ) ;
}
V_2 -> V_326 = F_178 ( & V_371 -> V_2 , L_45 ) ;
if ( F_135 ( V_2 -> V_326 ) ) {
F_67 ( & V_371 -> V_2 , L_46 ) ;
return F_136 ( V_2 -> V_326 ) ;
}
V_392 = F_179 ( V_371 , V_398 , 0 ) ;
V_2 -> V_8 = F_180 ( & V_371 -> V_2 , V_392 ) ;
if ( F_135 ( V_2 -> V_8 ) )
return F_136 ( V_2 -> V_8 ) ;
V_393 = F_181 ( V_371 , L_47 ) ;
if ( V_393 < 0 )
V_393 = F_182 ( V_371 , 0 ) ;
if ( V_393 < 0 ) {
F_67 ( & V_371 -> V_2 , L_48 ) ;
return V_393 ;
}
V_97 = F_183 ( & V_371 -> V_2 , V_393 , NULL , V_399 ,
V_400 , F_184 ( & V_371 -> V_2 ) , V_2 ) ;
if ( V_97 < 0 ) {
F_67 ( & V_371 -> V_2 , L_49 , V_97 ) ;
return V_97 ;
}
V_2 -> V_336 = F_185 ( & V_371 -> V_2 , NULL ) ;
if ( F_135 ( V_2 -> V_336 ) ) {
V_97 = F_136 ( V_2 -> V_336 ) ;
if ( V_97 == - V_401 || V_97 == - V_402 ) {
V_2 -> V_336 = NULL ;
} else {
F_67 ( & V_371 -> V_2 , L_50 ,
V_97 ) ;
return V_97 ;
}
}
V_390 = F_186 ( V_387 , L_51 , 0 ) ;
if ( ! V_390 && V_384 )
V_390 = F_187 ( V_384 -> V_403 , NULL ) ;
if ( ! V_390 ) {
F_67 ( & V_371 -> V_2 , L_52 ) ;
return - V_220 ;
}
V_2 -> V_404 = V_390 ;
V_97 = F_188 ( & V_371 -> V_2 , & V_2 -> V_6 ) ;
if ( V_97 )
return V_97 ;
F_137 ( & V_2 -> V_197 ) ;
F_137 ( & V_2 -> V_181 ) ;
V_2 -> V_318 = F_127 ( L_53 , NULL ) ;
if ( ! V_2 -> V_318 )
F_91 ( & V_371 -> V_2 , L_54 ) ;
if ( V_2 -> V_30 -> V_45 == V_46 ) {
V_97 = F_88 ( V_2 , & V_2 -> V_333 ,
V_2 -> V_30 -> V_405 , L_55 ,
V_2 -> V_318 ) ;
if ( V_97 < 0 )
goto V_396;
}
if ( V_2 -> V_30 -> V_406 ) {
V_97 = F_88 ( V_2 , & V_2 -> V_341 ,
V_2 -> V_30 -> V_406 , L_56 ,
V_2 -> V_318 ) ;
if ( V_97 < 0 )
goto V_396;
}
V_2 -> V_407 . V_208 = V_2 -> V_30 -> V_408 ;
V_2 -> V_407 . V_217 = F_189 ( V_2 -> V_404 , V_2 -> V_407 . V_208 ,
& V_2 -> V_407 . V_218 ) ;
if ( ! V_2 -> V_407 . V_217 ) {
F_91 ( & V_371 -> V_2 , L_57 ) ;
} else {
memset ( V_2 -> V_407 . V_217 , 0 , V_2 -> V_407 . V_208 ) ;
V_2 -> V_407 . V_221 . V_3 = V_2 -> V_407 . V_217 ;
V_2 -> V_407 . V_221 . V_208 = V_2 -> V_407 . V_208 ;
V_2 -> V_407 . V_215 = F_90 ( L_51 , 0644 ,
V_2 -> V_318 ,
& V_2 -> V_407 . V_221 ) ;
}
V_2 -> V_176 = F_190 ( L_53 , V_409 | V_410 , 1 ) ;
if ( ! V_2 -> V_176 ) {
F_67 ( & V_371 -> V_2 , L_58 ) ;
V_97 = - V_220 ;
goto V_396;
}
F_191 ( V_371 , V_2 ) ;
F_192 ( & V_371 -> V_2 ) ;
F_193 ( & V_371 -> V_2 ) ;
F_194 ( & V_371 -> V_2 ) ;
return F_170 ( V_2 ) ;
V_396:
F_195 ( & V_2 -> V_6 ) ;
return V_97 ;
}
static int F_196 ( struct V_370 * V_371 )
{
struct V_1 * V_2 = F_197 ( V_371 ) ;
int V_41 ;
for ( V_41 = 0 ; V_41 < F_198 ( V_2 -> V_42 ) ; V_41 ++ ) {
if ( F_13 ( & V_2 -> V_42 [ V_41 ] ) )
F_167 ( & V_2 -> V_42 [ V_41 ] ) ;
}
if ( V_2 -> V_190 )
F_168 ( V_2 -> V_190 ) ;
F_199 ( & V_371 -> V_2 ) ;
if ( V_2 -> V_209 )
F_169 ( V_2 -> V_209 ) ;
F_195 ( & V_2 -> V_6 ) ;
F_200 ( V_2 -> V_176 ) ;
if ( V_2 -> V_407 . V_217 )
F_201 ( V_2 -> V_404 , ( unsigned long ) V_2 -> V_407 . V_217 ,
V_2 -> V_407 . V_208 ) ;
F_92 ( V_2 , & V_2 -> V_337 ) ;
F_92 ( V_2 , & V_2 -> V_341 ) ;
F_92 ( V_2 , & V_2 -> V_333 ) ;
F_150 ( V_2 -> V_318 ) ;
return 0 ;
}
static int F_202 ( struct V_411 * V_2 )
{
struct V_1 * V_412 = F_203 ( V_2 ) ;
int V_97 = 0 ;
if ( V_2 -> V_413 && V_412 -> V_337 . V_217 ) {
V_97 = F_151 ( V_412 ) ;
if ( V_97 )
F_35 ( & V_412 -> V_6 , L_37 ) ;
}
return V_97 ;
}
