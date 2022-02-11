static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 ... V_5 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_6 :
return true ;
default:
return false ;
}
}
static int F_3 ( int V_7 , int V_8 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < F_4 ( V_10 ) ; V_9 ++ ) {
if ( V_10 [ V_9 ] . V_7 == V_7 &&
V_10 [ V_9 ] . V_11 == V_8 )
return V_10 [ V_9 ] . V_12 ;
}
return - V_13 ;
}
static int F_5 ( struct V_14 * V_15 ,
int V_16 , unsigned int V_17 , int V_18 )
{
struct V_19 * V_20 = V_15 -> V_20 ;
struct V_21 * V_22 = F_6 ( V_20 ) ;
switch ( V_17 ) {
case V_23 :
case V_24 :
case V_25 :
V_22 -> V_26 = 0 ;
V_22 -> V_27 = 0 ;
break;
case V_28 :
case V_29 :
case V_30 :
V_22 -> V_26 = V_31 ;
V_22 -> V_27 = 0 ;
break;
case V_32 :
case V_33 :
case V_34 :
V_22 -> V_26 = V_31 ;
V_22 -> V_27 = V_35 ;
break;
default:
return - V_13 ;
}
V_22 -> V_7 = V_17 ;
F_7 ( V_20 , V_36 ,
V_37 ,
V_22 -> V_27 ) ;
F_7 ( V_20 , V_36 ,
V_38 ,
V_22 -> V_26 ) ;
return 0 ;
}
static int F_8 ( struct V_14 * V_15 , unsigned int V_39 )
{
struct V_19 * V_20 = V_15 -> V_20 ;
struct V_21 * V_22 = F_6 ( V_20 ) ;
switch ( V_39 & V_40 ) {
case V_41 :
V_22 -> V_42 = V_43 ;
break;
case V_44 :
V_22 -> V_42 = V_45 ;
break;
default:
return - V_13 ;
}
switch ( V_39 & V_46 ) {
case V_47 :
V_22 -> V_48 = V_49 ;
break;
case V_50 :
V_22 -> V_48 = V_51 ;
break;
default:
return - V_13 ;
}
switch ( V_39 & V_52 ) {
case V_53 :
V_22 -> V_54 = 0 ;
break;
case V_55 :
V_22 -> V_54 = V_56 ;
break;
default:
return - V_13 ;
}
F_7 ( V_20 , V_36 ,
V_57 , V_22 -> V_42 ) ;
F_7 ( V_20 , V_58 ,
V_59 , V_22 -> V_48 ) ;
F_7 ( V_20 , V_36 ,
V_60 , V_22 -> V_54 ) ;
return 0 ;
}
static int F_9 ( struct V_14 * V_61 , int V_62 )
{
struct V_19 * V_20 = V_61 -> V_20 ;
if ( V_62 ) {
F_7 ( V_20 , V_63 ,
V_64 |
V_65 |
V_66 |
V_67 |
V_68 |
V_69 ,
V_70 ) ;
F_7 ( V_20 , V_71 ,
V_72 |
V_73 ,
V_70 ) ;
F_7 ( V_20 , V_74 ,
V_75 , V_70 ) ;
F_7 ( V_20 , V_76 ,
V_75 , V_70 ) ;
F_7 ( V_20 , V_77 ,
V_78 , V_70 ) ;
F_7 ( V_20 , V_79 ,
V_78 , V_70 ) ;
} else {
F_7 ( V_20 , V_63 ,
V_64 |
V_65 |
V_66 |
V_67 |
V_68 |
V_69 ,
V_80 ) ;
F_7 ( V_20 , V_71 ,
V_72 |
V_73 ,
V_80 ) ;
F_7 ( V_20 , V_74 ,
V_75 , V_80 ) ;
F_7 ( V_20 , V_76 ,
V_75 , V_80 ) ;
F_7 ( V_20 , V_77 ,
V_78 , V_80 ) ;
F_7 ( V_20 , V_79 ,
V_78 , V_80 ) ;
}
return 0 ;
}
static int F_10 ( struct V_81 * V_82 ,
struct V_83 * V_84 ,
struct V_14 * V_61 )
{
struct V_19 * V_20 = V_61 -> V_20 ;
struct V_21 * V_22 = F_6 ( V_20 ) ;
int V_12 ;
V_12 = F_3 ( V_22 -> V_7 , F_11 ( V_84 ) ) ;
if ( V_12 >= 0 ) {
F_7 ( V_20 , V_85 ,
V_86 , V_12 ) ;
} else {
F_12 ( V_20 -> V_2 , L_1 ) ;
return - V_13 ;
}
return 0 ;
}
static int F_13 ( struct V_19 * V_20 ,
enum V_87 V_88 )
{
struct V_21 * V_22 = F_6 ( V_20 ) ;
int V_89 ;
switch ( V_88 ) {
case V_90 :
break;
case V_91 :
F_7 ( V_20 , V_36 ,
V_92 , 0 ) ;
F_7 ( V_20 , V_93 ,
V_94 , 0 ) ;
break;
case V_95 :
if ( F_14 ( V_20 ) == V_96 ) {
F_15 ( V_22 -> V_97 , false ) ;
F_16 ( V_22 -> V_97 ) ;
V_89 = F_17 ( F_4 ( V_22 -> V_98 ) ,
V_22 -> V_98 ) ;
if ( V_89 != 0 ) {
F_12 ( V_22 -> V_2 ,
L_2 ,
V_89 ) ;
return V_89 ;
}
}
F_7 ( V_20 , V_93 ,
V_94 , 1 ) ;
break;
case V_96 :
F_7 ( V_20 , V_93 ,
V_94 , 1 ) ;
F_7 ( V_20 , V_36 ,
V_92 , 1 ) ;
F_15 ( V_22 -> V_97 , true ) ;
F_18 ( F_4 ( V_22 -> V_98 ) ,
V_22 -> V_98 ) ;
break;
}
return 0 ;
}
static void F_19 ( struct V_99 * V_100 )
{
struct V_21 * V_22 =
F_20 ( V_100 , struct V_21 , V_101 ) ;
struct V_19 * V_20 = V_22 -> V_20 ;
struct V_102 * V_103 = F_21 ( V_20 ) ;
int V_9 ;
int V_104 = 0 ;
int V_105 = 0 ;
if ( V_22 -> V_106 ) {
for ( V_9 = 0 ; V_9 < F_4 ( V_107 ) ; V_9 ++ ) {
if ( abs ( V_22 -> V_106 - V_107 [ V_9 ] ) <
abs ( V_22 -> V_106 - V_107 [ V_105 ] ) )
V_105 = V_9 ;
}
F_22 ( V_20 -> V_2 , L_3 ,
V_107 [ V_105 ] , V_22 -> V_106 ) ;
V_104 = ( V_105 << V_108 ) ;
F_23 ( V_103 , L_4 ) ;
} else {
F_22 ( V_20 -> V_2 , L_5 ) ;
F_24 ( V_103 , L_4 ) ;
}
F_7 ( V_20 , V_109 ,
V_110 , V_104 ) ;
F_25 ( V_103 ) ;
}
static int F_26 ( struct V_111 * V_2 , unsigned int type ,
unsigned int V_112 , int V_113 )
{
struct V_19 * V_20 = F_27 ( V_2 ) ;
struct V_21 * V_22 = F_6 ( V_20 ) ;
F_22 ( V_20 -> V_2 , L_6 , V_112 , V_113 ) ;
switch ( V_112 ) {
case V_114 :
if ( V_113 )
V_113 = 261 ;
case V_115 :
break;
default:
return - 1 ;
}
V_22 -> V_106 = V_113 ;
F_28 ( & V_22 -> V_101 ) ;
return 0 ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
struct V_116 * V_117 ,
const char * V_118 , T_2 V_119 )
{
struct V_21 * V_22 = F_30 ( V_2 ) ;
long int time ;
int V_89 ;
V_89 = F_31 ( V_118 , 10 , & time ) ;
if ( V_89 != 0 )
return V_89 ;
F_32 ( V_22 -> V_120 , V_121 , V_115 , time ) ;
return V_119 ;
}
static void F_33 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = F_6 ( V_20 ) ;
int V_89 ;
V_22 -> V_120 = F_34 ( V_20 -> V_2 ) ;
if ( ! V_22 -> V_120 ) {
F_12 ( V_20 -> V_2 , L_7 ) ;
return;
}
F_35 ( & V_22 -> V_101 , F_19 ) ;
V_22 -> V_106 = 0 ;
V_22 -> V_120 -> V_122 = L_8 ;
V_22 -> V_120 -> V_123 = F_36 ( V_20 -> V_2 ) ;
V_22 -> V_120 -> V_124 . V_125 = V_126 ;
V_22 -> V_120 -> V_127 [ 0 ] = F_37 ( V_121 ) ;
V_22 -> V_120 -> V_128 [ 0 ] = F_37 ( V_114 ) | F_37 ( V_115 ) ;
V_22 -> V_120 -> V_129 = F_26 ;
V_22 -> V_120 -> V_2 . V_130 = V_20 -> V_2 ;
F_38 ( V_22 -> V_120 , V_20 ) ;
V_89 = F_39 ( V_22 -> V_120 ) ;
if ( V_89 != 0 ) {
V_22 -> V_120 = NULL ;
F_12 ( V_20 -> V_2 , L_9 ) ;
}
V_89 = F_40 ( V_20 -> V_2 , & V_131 ) ;
if ( V_89 != 0 ) {
F_12 ( V_20 -> V_2 , L_10 ,
V_89 ) ;
}
}
static void F_41 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = F_6 ( V_20 ) ;
F_42 ( V_20 -> V_2 , & V_131 ) ;
F_43 ( & V_22 -> V_101 ) ;
V_22 -> V_120 = NULL ;
F_7 ( V_20 , V_132 ,
V_133 , 0 ) ;
}
static int F_44 ( struct V_19 * V_20 )
{
F_33 ( V_20 ) ;
return 0 ;
}
static int F_45 ( struct V_19 * V_20 )
{
F_41 ( V_20 ) ;
return 0 ;
}
static int F_46 ( struct V_134 * V_134 ,
struct V_135 * V_136 )
{
struct V_137 * V_138 = V_134 -> V_2 . V_139 ;
T_3 V_140 ;
if ( F_47 ( V_138 , L_11 ) )
V_136 -> V_141 = true ;
if ( F_47 ( V_138 , L_12 ) )
V_136 -> V_142 = true ;
if ( F_47 ( V_138 , L_13 ) )
V_136 -> V_143 = true ;
if ( F_47 ( V_138 , L_14 ) )
V_136 -> V_144 = true ;
if ( F_48 ( V_138 , L_15 , & V_140 ) >= 0 )
V_136 -> V_145 = V_140 ;
if ( F_48 ( V_138 , L_16 , & V_140 ) >= 0 )
V_136 -> V_146 = V_140 ;
if ( F_48 ( V_138 , L_17 , & V_140 ) >= 0 )
V_136 -> V_147 = V_140 ;
if ( F_48 ( V_138 , L_18 , & V_140 ) >= 0 )
V_136 -> V_148 = V_140 ;
if ( F_48 ( V_138 , L_18 , & V_140 ) >= 0 )
V_136 -> V_149 = V_140 ;
V_136 -> V_150 = F_49 ( V_138 , L_19 , 0 ) ;
return 0 ;
}
static int F_50 ( struct V_134 * V_134 ,
const struct V_151 * V_124 )
{
struct V_21 * V_22 ;
struct V_135 * V_136 =
F_51 ( & V_134 -> V_2 ) ;
int V_89 , V_9 ;
unsigned int V_152 = 0 ;
unsigned int V_153 , V_154 ;
unsigned int V_3 ;
V_22 = F_52 ( & V_134 -> V_2 ,
sizeof( struct V_21 ) ,
V_155 ) ;
if ( V_22 == NULL )
return - V_156 ;
V_22 -> V_2 = & V_134 -> V_2 ;
V_22 -> V_97 = F_53 ( V_134 , & V_157 ) ;
if ( F_54 ( V_22 -> V_97 ) ) {
V_89 = F_55 ( V_22 -> V_97 ) ;
F_12 ( & V_134 -> V_2 , L_20 , V_89 ) ;
return V_89 ;
}
if ( V_136 ) {
V_22 -> V_136 = * V_136 ;
} else {
V_136 = F_52 ( & V_134 -> V_2 ,
sizeof( struct V_135 ) ,
V_155 ) ;
if ( ! V_136 ) {
F_12 ( & V_134 -> V_2 ,
L_21 ) ;
return - V_156 ;
}
if ( V_134 -> V_2 . V_139 ) {
V_89 = F_46 ( V_134 ,
& V_22 -> V_136 ) ;
if ( V_89 != 0 )
return V_89 ;
}
V_22 -> V_136 = * V_136 ;
}
if ( V_22 -> V_136 . V_150 ) {
V_89 = F_56 ( V_22 -> V_136 . V_150 ,
V_158 , L_22 ) ;
if ( V_89 < 0 ) {
F_12 ( & V_134 -> V_2 ,
L_23 ,
V_22 -> V_136 . V_150 , V_89 ) ;
return V_89 ;
}
F_57 ( V_22 -> V_136 . V_150 , 0 ) ;
F_57 ( V_22 -> V_136 . V_150 , 1 ) ;
}
F_58 ( V_134 , V_22 ) ;
for ( V_9 = 0 ; V_9 < F_4 ( V_22 -> V_98 ) ; V_9 ++ )
V_22 -> V_98 [ V_9 ] . V_159 = V_160 [ V_9 ] ;
V_89 = F_59 ( & V_134 -> V_2 ,
F_4 ( V_22 -> V_98 ) ,
V_22 -> V_98 ) ;
if ( V_89 != 0 ) {
F_12 ( & V_134 -> V_2 ,
L_24 , V_89 ) ;
return V_89 ;
}
V_89 = F_17 ( F_4 ( V_22 -> V_98 ) ,
V_22 -> V_98 ) ;
if ( V_89 != 0 ) {
F_12 ( & V_134 -> V_2 ,
L_25 , V_89 ) ;
return V_89 ;
}
V_89 = F_60 ( V_22 -> V_97 , V_4 , & V_3 ) ;
V_152 = V_3 & V_161 ;
if ( V_152 != V_162 ) {
F_12 ( & V_134 -> V_2 ,
L_26 ,
V_152 , V_162 ) ;
goto V_163;
}
V_153 = V_3 & V_164 ;
V_154 = V_3 & V_165 ;
F_61 ( & V_134 -> V_2 , L_27 ) ;
F_61 ( & V_134 -> V_2 , L_28 ,
V_153 , V_154 ) ;
if ( V_22 -> V_136 . V_141 )
F_62 ( V_22 -> V_97 , V_166 ,
V_167 ,
V_167 ) ;
if ( V_22 -> V_136 . V_143 )
F_62 ( V_22 -> V_97 , V_166 ,
V_168 ,
V_168 ) ;
if ( V_22 -> V_136 . V_142 )
F_62 ( V_22 -> V_97 , V_166 ,
V_169 ,
V_169 ) ;
if ( V_22 -> V_136 . V_144 )
F_62 ( V_22 -> V_97 , V_166 ,
V_170 ,
V_170 ) ;
if ( V_22 -> V_136 . V_145 )
F_62 ( V_22 -> V_97 , V_171 ,
V_172 ,
V_22 -> V_136 . V_145 ) ;
if ( V_22 -> V_136 . V_146 )
F_62 ( V_22 -> V_97 , V_173 ,
V_174 ,
V_22 -> V_136 . V_146 ) ;
if ( V_22 -> V_136 . V_149 )
F_62 ( V_22 -> V_97 , V_175 ,
V_176 ,
V_22 -> V_136 . V_149 ) ;
if ( V_22 -> V_136 . V_148 )
F_62 ( V_22 -> V_97 , V_175 ,
V_177 ,
V_22 -> V_136 . V_148 ) ;
if ( V_22 -> V_136 . V_147 )
F_62 ( V_22 -> V_97 , V_173 ,
V_178 ,
V_22 -> V_136 . V_147 ) ;
V_89 = F_63 ( & V_134 -> V_2 ,
& V_179 , & V_180 , 1 ) ;
if ( V_89 < 0 )
return V_89 ;
return 0 ;
V_163:
F_18 ( F_4 ( V_22 -> V_98 ) ,
V_22 -> V_98 ) ;
return V_89 ;
}
static int F_64 ( struct V_134 * V_181 )
{
struct V_21 * V_22 = F_65 ( V_181 ) ;
F_66 ( & V_181 -> V_2 ) ;
F_18 ( F_4 ( V_22 -> V_98 ) ,
V_22 -> V_98 ) ;
return 0 ;
}
