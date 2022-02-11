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
V_12 ,
time << V_13 ) ;
if ( V_4 ) {
F_3 ( V_2 -> V_14 , L_1 ) ;
return V_4 ;
}
break;
default:
F_3 ( V_2 -> V_14 , L_2 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_16 , bool V_17 )
{
int V_4 = 0 ;
unsigned int V_18 , V_19 = 0 ;
if ( V_17 )
V_18 = V_16 ;
else
V_18 = V_20 ;
V_4 = F_2 ( V_2 -> V_9 -> V_10 ,
V_21 , V_22 , V_18 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_14 , L_3 ) ;
return V_4 ;
}
if ( V_17 )
V_19 |= V_23 ;
else
V_19 |= V_24 ;
V_4 = F_2 ( V_2 -> V_9 -> V_10 ,
V_25 ,
V_24 | V_23 , V_19 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_14 , L_3 ) ;
return V_4 ;
}
F_5 ( V_2 -> V_14 ,
L_4 ,
V_18 , V_19 , V_17 ? L_5 : L_6 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
enum V_26 V_27 , bool * V_17 )
{
int V_28 = 0 ;
int V_29 ;
int V_30 ;
int V_31 ;
int V_32 ;
int V_33 ;
switch ( V_27 ) {
case V_34 :
V_29 = V_2 -> V_35 [ 0 ] & V_36 ;
V_29 >>= V_37 ;
if ( V_29 == V_38 ) {
* V_17 = false ;
V_28 = V_2 -> V_39 ;
V_2 -> V_39 = V_38 ;
} else {
* V_17 = true ;
V_28 = V_2 -> V_39 = V_29 ;
}
break;
case V_40 :
V_29 = V_2 -> V_35 [ 0 ] & V_36 ;
V_29 >>= V_37 ;
if ( V_29 == V_38 ) {
* V_17 = false ;
V_28 = V_2 -> V_41 ;
V_2 -> V_41 = V_38 ;
} else {
* V_17 = true ;
V_31 = V_2 -> V_35 [ 0 ] & V_42 ;
V_31 >>= V_43 ;
V_30 = V_2 -> V_35 [ 0 ] & V_44 ;
V_30 >>= V_45 ;
V_32 = V_2 -> V_35 [ 1 ] & V_46 ;
V_32 >>= V_47 ;
V_28 = ( ( 0x1 << 8 )
| ( V_32 << 2 )
| ( V_31 << 1 )
| V_30 ) ;
V_2 -> V_39 = V_29 ;
V_2 -> V_41 = V_28 ;
}
break;
case V_48 :
V_33 = V_2 -> V_35 [ 1 ] & V_49 ;
V_33 >>= V_50 ;
if ( V_33 == V_51 ) {
* V_17 = false ;
V_28 = V_2 -> V_52 ;
V_2 -> V_52 = V_51 ;
} else {
* V_17 = true ;
V_28 = V_2 -> V_52 = V_33 ;
}
break;
case V_53 :
V_29 = V_2 -> V_35 [ 0 ] & V_36 ;
V_29 >>= V_37 ;
V_33 = V_2 -> V_35 [ 1 ] & V_49 ;
V_33 >>= V_50 ;
if ( V_29 == V_38
&& V_33 == V_51 )
* V_17 = false ;
else
* V_17 = true ;
V_32 = V_2 -> V_35 [ 1 ] & V_46 ;
V_32 >>= V_47 ;
V_28 = V_32 ;
break;
default:
F_3 ( V_2 -> V_14 , L_7 , V_27 ) ;
V_28 = - V_15 ;
break;
}
return V_28 ;
}
static int F_7 ( struct V_1 * V_2 ,
int V_28 , bool V_17 )
{
int V_4 = 0 ;
int V_32 ;
bool V_54 ;
char V_55 [ V_56 ] ;
F_5 ( V_2 -> V_14 ,
L_8 ,
V_17 ? L_5 : L_6 , V_28 ) ;
switch ( V_28 ) {
case V_57 :
V_32 = F_6 ( V_2 ,
V_53 , & V_54 ) ;
if ( V_17 && ! V_32 ) {
F_8 ( V_2 -> V_14 ,
L_9 ) ;
return 0 ;
}
V_4 = F_4 ( V_2 , V_2 -> V_58 , V_17 ) ;
if ( V_4 < 0 )
return V_4 ;
F_9 ( V_2 -> V_59 , L_10 , V_17 ) ;
F_9 ( V_2 -> V_59 , L_11 , V_17 ) ;
goto V_60;
case V_61 :
strcpy ( V_55 , L_12 ) ;
break;
case V_62 :
strcpy ( V_55 , L_13 ) ;
break;
case V_63 :
strcpy ( V_55 , L_14 ) ;
if ( ! V_17 )
F_9 ( V_2 -> V_59 , L_15 , false ) ;
break;
default:
F_3 ( V_2 -> V_14 , L_16 ,
V_17 ? L_5 : L_6 ) ;
return - V_15 ;
}
V_4 = F_4 ( V_2 , V_64 , V_17 ) ;
if ( V_4 < 0 )
return V_4 ;
F_9 ( V_2 -> V_59 , V_55 , V_17 ) ;
V_60:
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
int V_65 , bool V_17 )
{
struct V_66 * V_67 = V_2 -> V_67 ;
unsigned int V_68 ;
switch ( V_65 ) {
case V_69 - 1
... V_69 + 1 :
V_68 = V_70 ;
break;
case V_71 - 1
... V_71 + 1 :
V_68 = V_72 ;
break;
case V_73 :
V_68 = V_74 ;
break;
case V_75 :
V_68 = V_76 ;
break;
case V_77 - 1
... V_77 + 1 :
V_68 = V_78 ;
break;
default:
F_3 ( V_2 -> V_14 ,
L_17 ,
V_17 ? L_18 : L_19 , V_65 ) ;
return - V_15 ;
}
F_11 ( V_67 , V_79 , V_68 , V_17 ) ;
F_12 ( V_67 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_80 ;
int V_4 = 0 ;
bool V_17 ;
V_80 = F_6 ( V_2 ,
V_40 , & V_17 ) ;
switch ( V_80 ) {
case V_81 :
case V_82 :
V_4 = F_4 ( V_2 , V_83 , V_17 ) ;
if ( V_4 < 0 )
return V_4 ;
F_9 ( V_2 -> V_59 , L_20 , V_17 ) ;
break;
case V_84 :
V_4 = F_4 ( V_2 , V_64 , V_17 ) ;
if ( V_4 < 0 )
return V_4 ;
F_9 ( V_2 -> V_59 ,
L_21 , V_17 ) ;
break;
case V_85 :
case V_86 :
F_9 ( V_2 -> V_59 , L_11 , V_17 ) ;
break;
default:
F_3 ( V_2 -> V_14 , L_22 ,
V_17 ? L_5 : L_6 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
int V_28 , bool V_17 )
{
char V_87 [ 32 ] ;
int V_4 = 0 ;
T_1 V_88 = V_20 ;
F_5 ( V_2 -> V_14 ,
L_8 ,
V_17 ? L_5 : L_6 , V_28 ) ;
switch ( V_28 ) {
case V_89 :
strcpy ( V_87 , L_23 ) ;
V_88 = V_83 ;
break;
case V_90 :
strcpy ( V_87 , L_24 ) ;
V_88 = V_83 ;
break;
case V_91 :
strcpy ( V_87 , L_25 ) ;
V_88 = V_92 ;
break;
default:
F_3 ( V_2 -> V_14 , L_26 ,
V_17 ? L_5 : L_6 ) ;
return - V_15 ;
}
V_4 = F_4 ( V_2 , V_88 , V_17 ) ;
if ( V_4 < 0 )
return V_4 ;
F_9 ( V_2 -> V_59 , V_87 , V_17 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_28 ;
int V_65 ;
bool V_17 ;
int V_4 = 0 ;
V_28 = F_6 ( V_2 ,
V_34 , & V_17 ) ;
F_5 ( V_2 -> V_14 ,
L_27 ,
V_17 ? L_5 : L_6 , V_28 ,
V_2 -> V_39 ) ;
switch ( V_28 ) {
case V_93 :
F_13 ( V_2 ) ;
break;
case V_89 :
case V_90 :
case V_91 :
V_4 = F_14 ( V_2 , V_28 , V_17 ) ;
if ( V_4 < 0 )
return V_4 ;
break;
case V_57 :
case V_61 :
case V_62 :
case V_63 :
V_4 = F_7 ( V_2 , V_28 , V_17 ) ;
if ( V_4 < 0 )
return V_4 ;
break;
case V_69 :
case V_71 :
case V_73 :
case V_75 :
case V_77 :
if ( V_17 )
V_65 = V_2 -> V_94 = V_28 ;
else
V_65 = V_2 -> V_94 ;
V_4 = F_10 ( V_2 , V_65 ,
V_17 ) ;
if ( V_4 < 0 )
return V_4 ;
break;
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
case V_112 :
F_5 ( V_2 -> V_14 ,
L_28 ,
V_17 ? L_5 : L_6 , V_28 ) ;
return - V_113 ;
default:
F_3 ( V_2 -> V_14 ,
L_29 ,
V_17 ? L_5 : L_6 , V_28 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_33 ;
int V_80 ;
int V_28 ;
bool V_17 ;
bool V_54 ;
int V_4 = 0 ;
V_33 = F_6 ( V_2 ,
V_48 , & V_17 ) ;
F_5 ( V_2 -> V_14 ,
L_30 ,
V_17 ? L_5 : L_6 ,
V_33 , V_2 -> V_52 ) ;
switch ( V_33 ) {
case V_114 :
case V_115 :
case V_51 :
V_80 = F_6 ( V_2 ,
V_40 ,
& V_54 ) ;
switch ( V_80 ) {
case V_85 :
case V_86 :
F_9 ( V_2 -> V_59 , L_31 , V_17 ) ;
if ( ! V_54 )
F_9 ( V_2 -> V_59 ,
L_11 , V_54 ) ;
break;
}
V_28 = F_6 ( V_2 ,
V_34 ,
& V_54 ) ;
switch ( V_28 ) {
case V_63 :
F_9 ( V_2 -> V_59 , L_15 , V_17 ) ;
if ( ! V_54 )
F_9 ( V_2 -> V_59 , L_14 ,
V_54 ) ;
break;
case V_57 :
V_4 = F_4 ( V_2 , V_2 -> V_58 ,
V_17 ) ;
if ( V_4 < 0 )
return V_4 ;
F_9 ( V_2 -> V_59 , L_10 ,
V_17 ) ;
F_9 ( V_2 -> V_59 , L_11 , V_17 ) ;
break;
}
switch ( V_33 ) {
case V_51 :
break;
case V_114 :
V_4 = F_4 ( V_2 , V_2 -> V_58 ,
V_17 ) ;
if ( V_4 < 0 )
return V_4 ;
F_9 ( V_2 -> V_59 , L_15 , V_17 ) ;
break;
case V_115 :
F_9 ( V_2 -> V_59 , L_32 , V_17 ) ;
break;
}
break;
case V_116 :
F_9 ( V_2 -> V_59 ,
L_33 , V_17 ) ;
break;
case V_117 :
F_9 ( V_2 -> V_59 , L_34 , V_17 ) ;
break;
case V_118 :
F_9 ( V_2 -> V_59 , L_35 , V_17 ) ;
break;
case V_119 :
break;
default:
F_3 ( V_2 -> V_14 ,
L_36 ,
V_17 ? L_5 : L_6 , V_33 ) ;
return - V_15 ;
}
return 0 ;
}
static void F_17 ( struct V_120 * V_121 )
{
struct V_1 * V_2 = F_18 ( V_121 ,
struct V_1 , V_122 ) ;
int V_123 = - 1 ;
int V_124 , V_4 = 0 ;
if ( ! V_2 -> V_59 )
return;
F_19 ( & V_2 -> V_125 ) ;
for ( V_124 = 0 ; V_124 < F_20 ( V_126 ) ; V_124 ++ )
if ( V_2 -> V_127 == V_126 [ V_124 ] . V_128 )
V_123 = V_126 [ V_124 ] . V_127 ;
V_4 = F_21 ( V_2 -> V_9 -> V_10 ,
V_129 , V_2 -> V_35 , 2 ) ;
if ( V_4 ) {
F_3 ( V_2 -> V_14 , L_37 ) ;
F_22 ( & V_2 -> V_125 ) ;
return;
}
switch ( V_123 ) {
case V_130 :
case V_131 :
case V_132 :
case V_133 :
V_4 = F_15 ( V_2 ) ;
break;
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
V_4 = F_16 ( V_2 ) ;
break;
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
break;
default:
F_3 ( V_2 -> V_14 , L_38 ,
V_123 ) ;
F_22 ( & V_2 -> V_125 ) ;
return;
}
if ( V_4 < 0 )
F_3 ( V_2 -> V_14 , L_39 ) ;
F_22 ( & V_2 -> V_125 ) ;
return;
}
static T_2 F_23 ( int V_127 , void * V_146 )
{
struct V_1 * V_2 = V_146 ;
V_2 -> V_127 = V_127 ;
F_24 ( & V_2 -> V_122 ) ;
return V_147 ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_4 = 0 ;
int V_29 ;
int V_33 ;
bool V_17 ;
F_19 ( & V_2 -> V_125 ) ;
V_4 = F_21 ( V_2 -> V_9 -> V_10 ,
V_129 , V_2 -> V_35 , 2 ) ;
if ( V_4 ) {
F_3 ( V_2 -> V_14 , L_37 ) ;
F_22 ( & V_2 -> V_125 ) ;
return V_4 ;
}
V_29 = F_6 ( V_2 , V_34 ,
& V_17 ) ;
if ( V_17 && V_29 != V_38 ) {
V_4 = F_15 ( V_2 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_14 , L_40 ) ;
F_22 ( & V_2 -> V_125 ) ;
return V_4 ;
}
}
V_33 = F_6 ( V_2 , V_48 ,
& V_17 ) ;
if ( V_17 && V_33 != V_51 ) {
V_4 = F_16 ( V_2 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_14 , L_41 ) ;
F_22 ( & V_2 -> V_125 ) ;
return V_4 ;
}
}
F_22 ( & V_2 -> V_125 ) ;
return 0 ;
}
static void F_26 ( struct V_120 * V_121 )
{
struct V_1 * V_2 = F_18 ( F_27 ( V_121 ) ,
struct V_1 , V_148 ) ;
F_25 ( V_2 ) ;
}
static int F_28 ( struct V_149 * V_150 )
{
struct V_151 * V_9 = F_29 ( V_150 -> V_14 . V_152 ) ;
struct V_153 * V_154 = F_30 ( V_9 -> V_14 ) ;
struct V_1 * V_2 ;
struct V_155 * V_156 ;
int V_157 ;
int V_158 ;
int V_4 ;
int V_124 ;
unsigned int V_159 ;
V_2 = F_31 ( & V_150 -> V_14 , sizeof( struct V_1 ) ,
V_160 ) ;
if ( ! V_2 )
return - V_161 ;
V_2 -> V_14 = & V_150 -> V_14 ;
V_2 -> V_9 = V_9 ;
if ( V_2 -> V_9 -> V_10 ) {
F_32 ( & V_150 -> V_14 , L_42 ) ;
} else {
V_2 -> V_9 -> V_10 = F_33 (
V_2 -> V_9 -> V_162 ,
& V_163 ) ;
if ( F_34 ( V_2 -> V_9 -> V_10 ) ) {
V_4 = F_35 ( V_2 -> V_9 -> V_10 ) ;
F_3 ( V_9 -> V_14 ,
L_43 , V_4 ) ;
return V_4 ;
}
}
V_2 -> V_67 = F_36 ( & V_150 -> V_14 ) ;
if ( ! V_2 -> V_67 ) {
F_3 ( & V_150 -> V_14 , L_44 , V_164 ) ;
return - V_161 ;
}
V_2 -> V_67 -> V_165 = L_45 ;
V_2 -> V_67 -> V_166 = L_46 ;
V_2 -> V_67 -> V_14 . V_152 = & V_150 -> V_14 ;
F_37 ( V_167 , V_2 -> V_67 -> V_168 ) ;
F_38 ( V_2 -> V_67 , V_79 , V_76 ) ;
F_38 ( V_2 -> V_67 , V_79 , V_74 ) ;
F_38 ( V_2 -> V_67 , V_79 , V_78 ) ;
F_38 ( V_2 -> V_67 , V_79 , V_70 ) ;
F_38 ( V_2 -> V_67 , V_79 , V_72 ) ;
V_4 = F_39 ( V_2 -> V_67 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_150 -> V_14 , L_47 ,
V_4 ) ;
return V_4 ;
}
F_40 ( V_150 , V_2 ) ;
F_41 ( & V_2 -> V_125 ) ;
F_42 ( & V_2 -> V_122 , F_17 ) ;
for ( V_124 = 0 ; V_124 < F_20 ( V_126 ) ; V_124 ++ ) {
struct V_169 * V_170 = & V_126 [ V_124 ] ;
unsigned int V_128 = 0 ;
V_128 = F_43 ( V_9 -> V_171 ,
V_170 -> V_127 ) ;
if ( ! V_128 ) {
V_4 = - V_15 ;
goto V_172;
}
V_170 -> V_128 = V_128 ;
V_4 = F_44 ( V_128 , NULL ,
F_23 ,
V_173 ,
V_170 -> V_165 , V_2 ) ;
if ( V_4 ) {
F_3 ( & V_150 -> V_14 ,
L_48
L_49 ,
V_170 -> V_127 , V_4 ) ;
goto V_172;
}
}
V_2 -> V_59 = F_45 ( & V_150 -> V_14 ,
V_174 ) ;
if ( F_34 ( V_2 -> V_59 ) ) {
F_3 ( & V_150 -> V_14 , L_50 ) ;
V_4 = - V_161 ;
goto V_172;
}
V_2 -> V_59 -> V_165 = V_175 ;
V_4 = F_46 ( & V_150 -> V_14 , V_2 -> V_59 ) ;
if ( V_4 ) {
F_3 ( & V_150 -> V_14 , L_51 ) ;
goto V_172;
}
if ( V_154 && V_154 -> V_176 ) {
V_156 = V_154 -> V_176 -> V_156 ;
V_157 = V_154 -> V_176 -> V_157 ;
} else {
V_156 = V_177 ;
V_157 = F_20 ( V_177 ) ;
}
for ( V_124 = 0 ; V_124 < V_157 ; V_124 ++ ) {
enum V_178 V_179
= V_180 ;
F_47 ( V_2 -> V_9 -> V_10 ,
V_156 [ V_124 ] . V_181 ,
V_156 [ V_124 ] . V_146 ) ;
switch ( V_156 [ V_124 ] . V_181 ) {
case V_182 :
V_179 = V_183 ;
break;
case V_184 :
V_179 = V_185 ;
break;
case V_186 :
V_179 = V_187 ;
break;
}
if ( V_179 < V_180 )
V_2 -> V_9 -> V_188 [ V_179 ]
= V_156 [ V_124 ] . V_146 ;
}
if ( V_154 && V_154 -> V_176 ) {
struct V_189 * V_190
= V_154 -> V_176 ;
if ( V_190 -> V_191 )
V_2 -> V_191 = V_190 -> V_191 ;
else
V_2 -> V_191 = V_92 ;
if ( V_190 -> V_58 )
V_2 -> V_58 = V_190 -> V_58 ;
else
V_2 -> V_58 = V_83 ;
if ( V_190 -> V_192 )
V_158 =
F_48 ( V_190 -> V_192 ) ;
else
V_158 = F_48 ( V_193 ) ;
} else {
V_2 -> V_58 = V_83 ;
V_2 -> V_191 = V_92 ;
V_158 = F_48 ( V_193 ) ;
}
F_4 ( V_2 , V_2 -> V_191 , true ) ;
V_4 = F_49 ( V_2 -> V_9 -> V_10 ,
V_194 , & V_159 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_150 -> V_14 , L_52 ) ;
goto V_172;
}
F_5 ( V_2 -> V_14 , L_53 , V_159 ) ;
F_1 ( V_2 , V_7 ) ;
F_50 ( & V_2 -> V_148 , F_26 ) ;
F_51 ( V_195 , & V_2 -> V_148 ,
V_158 ) ;
return V_4 ;
V_172:
while ( -- V_124 >= 0 )
F_52 ( V_126 [ V_124 ] . V_128 , V_2 ) ;
return V_4 ;
}
static int F_53 ( struct V_149 * V_150 )
{
struct V_1 * V_2 = F_54 ( V_150 ) ;
int V_124 ;
for ( V_124 = 0 ; V_124 < F_20 ( V_126 ) ; V_124 ++ )
F_52 ( V_126 [ V_124 ] . V_128 , V_2 ) ;
F_55 ( & V_2 -> V_122 ) ;
F_56 ( V_2 -> V_67 ) ;
return 0 ;
}
