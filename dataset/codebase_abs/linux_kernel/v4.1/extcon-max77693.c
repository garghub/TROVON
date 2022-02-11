static int F_1 ( struct V_1 * V_2 ,
enum V_3 time )
{
int V_4 ;
switch ( time ) {
case V_5 :
case V_6 :
case V_7 :
case V_8 :
V_4 = F_2 ( V_2 -> V_9 -> V_10 ,
V_11 ,
time << V_12 ) ;
if ( V_4 ) {
F_3 ( V_2 -> V_13 , L_1 ) ;
return V_4 ;
}
break;
default:
F_3 ( V_2 -> V_13 , L_2 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_15 , bool V_16 )
{
int V_4 = 0 ;
unsigned int V_17 , V_18 = 0 ;
if ( V_16 )
V_17 = V_15 ;
else
V_17 = V_19 ;
V_4 = F_5 ( V_2 -> V_9 -> V_10 ,
V_20 , V_21 , V_17 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_13 , L_3 ) ;
return V_4 ;
}
if ( V_16 )
V_18 |= V_22 ;
else
V_18 |= V_23 ;
V_4 = F_5 ( V_2 -> V_9 -> V_10 ,
V_24 ,
V_23 | V_22 , V_18 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_13 , L_3 ) ;
return V_4 ;
}
F_6 ( V_2 -> V_13 ,
L_4 ,
V_17 , V_18 , V_16 ? L_5 : L_6 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
enum V_25 V_26 , bool * V_16 )
{
int V_27 = 0 ;
int V_28 ;
int V_29 ;
int V_30 ;
int V_31 ;
int V_32 ;
switch ( V_26 ) {
case V_33 :
V_28 = V_2 -> V_34 [ 0 ] & V_35 ;
V_28 >>= V_36 ;
if ( V_28 == V_37 ) {
* V_16 = false ;
V_27 = V_2 -> V_38 ;
V_2 -> V_38 = V_37 ;
} else {
* V_16 = true ;
V_27 = V_2 -> V_38 = V_28 ;
}
break;
case V_39 :
V_28 = V_2 -> V_34 [ 0 ] & V_35 ;
V_28 >>= V_36 ;
if ( V_28 == V_37 ) {
* V_16 = false ;
V_27 = V_2 -> V_40 ;
V_2 -> V_40 = V_37 ;
} else {
* V_16 = true ;
V_30 = V_2 -> V_34 [ 0 ] & V_41 ;
V_30 >>= V_42 ;
V_29 = V_2 -> V_34 [ 0 ] & V_43 ;
V_29 >>= V_44 ;
V_31 = V_2 -> V_34 [ 1 ] & V_45 ;
V_31 >>= V_46 ;
V_27 = ( ( 0x1 << 8 )
| ( V_31 << 2 )
| ( V_30 << 1 )
| V_29 ) ;
V_2 -> V_38 = V_28 ;
V_2 -> V_40 = V_27 ;
}
break;
case V_47 :
V_32 = V_2 -> V_34 [ 1 ] & V_48 ;
V_32 >>= V_49 ;
if ( V_32 == V_50 ) {
* V_16 = false ;
V_27 = V_2 -> V_51 ;
V_2 -> V_51 = V_50 ;
} else {
* V_16 = true ;
V_27 = V_2 -> V_51 = V_32 ;
}
break;
case V_52 :
V_28 = V_2 -> V_34 [ 0 ] & V_35 ;
V_28 >>= V_36 ;
V_32 = V_2 -> V_34 [ 1 ] & V_48 ;
V_32 >>= V_49 ;
if ( V_28 == V_37
&& V_32 == V_50 )
* V_16 = false ;
else
* V_16 = true ;
V_31 = V_2 -> V_34 [ 1 ] & V_45 ;
V_31 >>= V_46 ;
V_27 = V_31 ;
break;
default:
F_3 ( V_2 -> V_13 , L_7 , V_26 ) ;
V_27 = - V_14 ;
break;
}
return V_27 ;
}
static int F_8 ( struct V_1 * V_2 ,
int V_27 , bool V_16 )
{
int V_4 = 0 ;
int V_31 ;
bool V_53 ;
char V_54 [ V_55 ] ;
F_6 ( V_2 -> V_13 ,
L_8 ,
V_16 ? L_5 : L_6 , V_27 ) ;
switch ( V_27 ) {
case V_56 :
V_31 = F_7 ( V_2 ,
V_52 , & V_53 ) ;
if ( V_16 && ! V_31 ) {
F_9 ( V_2 -> V_13 ,
L_9 ) ;
return 0 ;
}
V_4 = F_4 ( V_2 , V_2 -> V_57 , V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
F_10 ( V_2 -> V_58 , L_10 , V_16 ) ;
F_10 ( V_2 -> V_58 , L_11 , V_16 ) ;
goto V_59;
case V_60 :
strcpy ( V_54 , L_12 ) ;
break;
case V_61 :
strcpy ( V_54 , L_13 ) ;
if ( ! V_16 )
F_10 ( V_2 -> V_58 , L_14 , false ) ;
break;
default:
F_3 ( V_2 -> V_13 , L_15 ,
V_16 ? L_5 : L_6 ) ;
return - V_14 ;
}
V_4 = F_4 ( V_2 , V_62 , V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
F_10 ( V_2 -> V_58 , V_54 , V_16 ) ;
V_59:
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
int V_63 , bool V_16 )
{
struct V_64 * V_65 = V_2 -> V_65 ;
unsigned int V_66 ;
switch ( V_63 ) {
case V_67 - 1
... V_67 + 1 :
V_66 = V_68 ;
break;
case V_69 - 1
... V_69 + 1 :
V_66 = V_70 ;
break;
case V_71 :
V_66 = V_72 ;
break;
case V_73 :
V_66 = V_74 ;
break;
case V_75 - 1
... V_75 + 1 :
V_66 = V_76 ;
break;
default:
F_3 ( V_2 -> V_13 ,
L_16 ,
V_16 ? L_17 : L_18 , V_63 ) ;
return - V_14 ;
}
F_12 ( V_65 , V_77 , V_66 , V_16 ) ;
F_13 ( V_65 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_78 ;
int V_4 = 0 ;
bool V_16 ;
V_78 = F_7 ( V_2 ,
V_39 , & V_16 ) ;
switch ( V_78 ) {
case V_79 :
case V_80 :
V_4 = F_4 ( V_2 , V_81 , V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
F_10 ( V_2 -> V_58 , L_19 , V_16 ) ;
break;
case V_82 :
V_4 = F_4 ( V_2 , V_62 , V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
F_10 ( V_2 -> V_58 ,
L_20 , V_16 ) ;
break;
case V_83 :
case V_84 :
F_10 ( V_2 -> V_58 , L_11 , V_16 ) ;
break;
default:
F_3 ( V_2 -> V_13 , L_21 ,
V_16 ? L_5 : L_6 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
int V_27 , bool V_16 )
{
char V_85 [ 32 ] ;
int V_4 = 0 ;
T_1 V_86 = V_19 ;
F_6 ( V_2 -> V_13 ,
L_8 ,
V_16 ? L_5 : L_6 , V_27 ) ;
switch ( V_27 ) {
case V_87 :
strcpy ( V_85 , L_22 ) ;
V_86 = V_81 ;
break;
case V_88 :
strcpy ( V_85 , L_23 ) ;
V_86 = V_81 ;
break;
case V_89 :
strcpy ( V_85 , L_24 ) ;
V_86 = V_90 ;
break;
case V_91 :
strcpy ( V_85 , L_25 ) ;
V_86 = V_90 ;
break;
default:
F_3 ( V_2 -> V_13 , L_26 ,
V_16 ? L_5 : L_6 ) ;
return - V_14 ;
}
V_4 = F_4 ( V_2 , V_86 , V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
F_10 ( V_2 -> V_58 , V_85 , V_16 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_27 ;
int V_63 ;
bool V_16 ;
int V_4 = 0 ;
V_27 = F_7 ( V_2 ,
V_33 , & V_16 ) ;
F_6 ( V_2 -> V_13 ,
L_27 ,
V_16 ? L_5 : L_6 , V_27 ,
V_2 -> V_38 ) ;
switch ( V_27 ) {
case V_92 :
F_14 ( V_2 ) ;
break;
case V_87 :
case V_88 :
case V_89 :
case V_91 :
V_4 = F_15 ( V_2 , V_27 , V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
break;
case V_56 :
case V_60 :
case V_61 :
V_4 = F_8 ( V_2 , V_27 , V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
break;
case V_67 :
case V_69 :
case V_71 :
case V_73 :
case V_75 :
if ( V_16 )
V_63 = V_2 -> V_93 = V_27 ;
else
V_63 = V_2 -> V_93 ;
V_4 = F_11 ( V_2 , V_63 ,
V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
break;
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
F_6 ( V_2 -> V_13 ,
L_28 ,
V_16 ? L_5 : L_6 , V_27 ) ;
return - V_112 ;
default:
F_3 ( V_2 -> V_13 ,
L_29 ,
V_16 ? L_5 : L_6 , V_27 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_32 ;
int V_78 ;
int V_27 ;
bool V_16 ;
bool V_53 ;
int V_4 = 0 ;
V_32 = F_7 ( V_2 ,
V_47 , & V_16 ) ;
F_6 ( V_2 -> V_13 ,
L_30 ,
V_16 ? L_5 : L_6 ,
V_32 , V_2 -> V_51 ) ;
switch ( V_32 ) {
case V_113 :
case V_114 :
case V_50 :
V_78 = F_7 ( V_2 ,
V_39 ,
& V_53 ) ;
switch ( V_78 ) {
case V_83 :
case V_84 :
F_10 ( V_2 -> V_58 , L_31 , V_16 ) ;
if ( ! V_53 )
F_10 ( V_2 -> V_58 ,
L_11 , V_53 ) ;
break;
}
V_27 = F_7 ( V_2 ,
V_33 ,
& V_53 ) ;
switch ( V_27 ) {
case V_61 :
F_10 ( V_2 -> V_58 , L_14 , V_16 ) ;
if ( ! V_53 )
F_10 ( V_2 -> V_58 , L_13 ,
V_53 ) ;
break;
case V_56 :
V_4 = F_4 ( V_2 , V_2 -> V_57 ,
V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
F_10 ( V_2 -> V_58 , L_10 ,
V_16 ) ;
F_10 ( V_2 -> V_58 , L_11 , V_16 ) ;
break;
}
switch ( V_32 ) {
case V_50 :
break;
case V_113 :
V_4 = F_4 ( V_2 , V_2 -> V_57 ,
V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
F_10 ( V_2 -> V_58 , L_14 , V_16 ) ;
break;
case V_114 :
F_10 ( V_2 -> V_58 , L_32 , V_16 ) ;
break;
}
break;
case V_115 :
F_10 ( V_2 -> V_58 ,
L_33 , V_16 ) ;
break;
case V_116 :
F_10 ( V_2 -> V_58 , L_34 , V_16 ) ;
break;
case V_117 :
F_10 ( V_2 -> V_58 , L_35 , V_16 ) ;
break;
case V_118 :
break;
default:
F_3 ( V_2 -> V_13 ,
L_36 ,
V_16 ? L_5 : L_6 , V_32 ) ;
return - V_14 ;
}
return 0 ;
}
static void F_18 ( struct V_119 * V_120 )
{
struct V_1 * V_2 = F_19 ( V_120 ,
struct V_1 , V_121 ) ;
int V_122 = - 1 ;
int V_123 , V_4 = 0 ;
if ( ! V_2 -> V_58 )
return;
F_20 ( & V_2 -> V_124 ) ;
for ( V_123 = 0 ; V_123 < F_21 ( V_125 ) ; V_123 ++ )
if ( V_2 -> V_126 == V_125 [ V_123 ] . V_127 )
V_122 = V_125 [ V_123 ] . V_126 ;
V_4 = F_22 ( V_2 -> V_9 -> V_10 ,
V_128 , V_2 -> V_34 , 2 ) ;
if ( V_4 ) {
F_3 ( V_2 -> V_13 , L_37 ) ;
F_23 ( & V_2 -> V_124 ) ;
return;
}
switch ( V_122 ) {
case V_129 :
case V_130 :
case V_131 :
case V_132 :
V_4 = F_16 ( V_2 ) ;
break;
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
V_4 = F_17 ( V_2 ) ;
break;
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
break;
default:
F_3 ( V_2 -> V_13 , L_38 ,
V_122 ) ;
F_23 ( & V_2 -> V_124 ) ;
return;
}
if ( V_4 < 0 )
F_3 ( V_2 -> V_13 , L_39 ) ;
F_23 ( & V_2 -> V_124 ) ;
}
static T_2 F_24 ( int V_126 , void * V_145 )
{
struct V_1 * V_2 = V_145 ;
V_2 -> V_126 = V_126 ;
F_25 ( & V_2 -> V_121 ) ;
return V_146 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_4 = 0 ;
int V_28 ;
int V_32 ;
bool V_16 ;
F_20 ( & V_2 -> V_124 ) ;
V_4 = F_22 ( V_2 -> V_9 -> V_10 ,
V_128 , V_2 -> V_34 , 2 ) ;
if ( V_4 ) {
F_3 ( V_2 -> V_13 , L_37 ) ;
F_23 ( & V_2 -> V_124 ) ;
return V_4 ;
}
V_28 = F_7 ( V_2 , V_33 ,
& V_16 ) ;
if ( V_16 && V_28 != V_37 ) {
V_4 = F_16 ( V_2 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_13 , L_40 ) ;
F_23 ( & V_2 -> V_124 ) ;
return V_4 ;
}
}
V_32 = F_7 ( V_2 , V_47 ,
& V_16 ) ;
if ( V_16 && V_32 != V_50 ) {
V_4 = F_17 ( V_2 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_13 , L_41 ) ;
F_23 ( & V_2 -> V_124 ) ;
return V_4 ;
}
}
F_23 ( & V_2 -> V_124 ) ;
return 0 ;
}
static void F_27 ( struct V_119 * V_120 )
{
struct V_1 * V_2 = F_19 ( F_28 ( V_120 ) ,
struct V_1 , V_147 ) ;
F_26 ( V_2 ) ;
}
static int F_29 ( struct V_148 * V_149 )
{
struct V_150 * V_9 = F_30 ( V_149 -> V_13 . V_151 ) ;
struct V_152 * V_153 = F_31 ( V_9 -> V_13 ) ;
struct V_1 * V_2 ;
struct V_154 * V_155 ;
int V_156 ;
int V_157 ;
int V_4 ;
int V_123 ;
unsigned int V_158 ;
V_2 = F_32 ( & V_149 -> V_13 , sizeof( struct V_1 ) ,
V_159 ) ;
if ( ! V_2 )
return - V_160 ;
V_2 -> V_13 = & V_149 -> V_13 ;
V_2 -> V_9 = V_9 ;
if ( V_2 -> V_9 -> V_10 ) {
F_33 ( & V_149 -> V_13 , L_42 ) ;
} else {
V_2 -> V_9 -> V_10 = F_34 (
V_2 -> V_9 -> V_161 ,
& V_162 ) ;
if ( F_35 ( V_2 -> V_9 -> V_10 ) ) {
V_4 = F_36 ( V_2 -> V_9 -> V_10 ) ;
F_3 ( V_9 -> V_13 ,
L_43 , V_4 ) ;
return V_4 ;
}
}
V_2 -> V_65 = F_37 ( & V_149 -> V_13 ) ;
if ( ! V_2 -> V_65 ) {
F_3 ( & V_149 -> V_13 , L_44 , V_163 ) ;
return - V_160 ;
}
V_2 -> V_65 -> V_164 = L_45 ;
V_2 -> V_65 -> V_165 = L_46 ;
V_2 -> V_65 -> V_13 . V_151 = & V_149 -> V_13 ;
F_38 ( V_166 , V_2 -> V_65 -> V_167 ) ;
F_39 ( V_2 -> V_65 , V_77 , V_74 ) ;
F_39 ( V_2 -> V_65 , V_77 , V_72 ) ;
F_39 ( V_2 -> V_65 , V_77 , V_76 ) ;
F_39 ( V_2 -> V_65 , V_77 , V_68 ) ;
F_39 ( V_2 -> V_65 , V_77 , V_70 ) ;
V_4 = F_40 ( V_2 -> V_65 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_149 -> V_13 , L_47 ,
V_4 ) ;
return V_4 ;
}
F_41 ( V_149 , V_2 ) ;
F_42 ( & V_2 -> V_124 ) ;
F_43 ( & V_2 -> V_121 , F_18 ) ;
for ( V_123 = 0 ; V_123 < F_21 ( V_125 ) ; V_123 ++ ) {
struct V_168 * V_169 = & V_125 [ V_123 ] ;
unsigned int V_127 = 0 ;
V_127 = F_44 ( V_9 -> V_170 ,
V_169 -> V_126 ) ;
if ( ! V_127 )
return - V_14 ;
V_169 -> V_127 = V_127 ;
V_4 = F_45 ( & V_149 -> V_13 , V_127 , NULL ,
F_24 ,
V_171 ,
V_169 -> V_164 , V_2 ) ;
if ( V_4 ) {
F_3 ( & V_149 -> V_13 ,
L_48 ,
V_169 -> V_126 , V_4 ) ;
return V_4 ;
}
}
V_2 -> V_58 = F_46 ( & V_149 -> V_13 ,
V_172 ) ;
if ( F_35 ( V_2 -> V_58 ) ) {
F_3 ( & V_149 -> V_13 , L_49 ) ;
return - V_160 ;
}
V_2 -> V_58 -> V_164 = V_173 ;
V_4 = F_47 ( & V_149 -> V_13 , V_2 -> V_58 ) ;
if ( V_4 ) {
F_3 ( & V_149 -> V_13 , L_50 ) ;
return V_4 ;
}
if ( V_153 && V_153 -> V_174 ) {
V_155 = V_153 -> V_174 -> V_155 ;
V_156 = V_153 -> V_174 -> V_156 ;
} else {
V_155 = V_175 ;
V_156 = F_21 ( V_175 ) ;
}
for ( V_123 = 0 ; V_123 < V_156 ; V_123 ++ ) {
enum V_176 V_177
= V_178 ;
F_2 ( V_2 -> V_9 -> V_10 ,
V_155 [ V_123 ] . V_179 ,
V_155 [ V_123 ] . V_145 ) ;
switch ( V_155 [ V_123 ] . V_179 ) {
case V_180 :
V_177 = V_181 ;
break;
case V_182 :
V_177 = V_183 ;
break;
case V_184 :
V_177 = V_185 ;
break;
}
if ( V_177 < V_178 )
V_2 -> V_9 -> V_186 [ V_177 ]
= V_155 [ V_123 ] . V_145 ;
}
if ( V_153 && V_153 -> V_174 ) {
struct V_187 * V_188
= V_153 -> V_174 ;
if ( V_188 -> V_189 )
V_2 -> V_189 = V_188 -> V_189 ;
else
V_2 -> V_189 = V_90 ;
if ( V_188 -> V_57 )
V_2 -> V_57 = V_188 -> V_57 ;
else
V_2 -> V_57 = V_81 ;
if ( V_188 -> V_190 )
V_157 =
F_48 ( V_188 -> V_190 ) ;
else
V_157 = F_48 ( V_191 ) ;
} else {
V_2 -> V_57 = V_81 ;
V_2 -> V_189 = V_90 ;
V_157 = F_48 ( V_191 ) ;
}
F_4 ( V_2 , V_2 -> V_189 , true ) ;
V_4 = F_49 ( V_2 -> V_9 -> V_10 ,
V_192 , & V_158 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_149 -> V_13 , L_51 ) ;
return V_4 ;
}
F_6 ( V_2 -> V_13 , L_52 , V_158 ) ;
F_1 ( V_2 , V_7 ) ;
F_50 ( & V_2 -> V_147 , F_27 ) ;
F_51 ( V_193 , & V_2 -> V_147 ,
V_157 ) ;
return V_4 ;
}
static int F_52 ( struct V_148 * V_149 )
{
struct V_1 * V_2 = F_53 ( V_149 ) ;
F_54 ( & V_2 -> V_121 ) ;
F_55 ( V_2 -> V_65 ) ;
return 0 ;
}
