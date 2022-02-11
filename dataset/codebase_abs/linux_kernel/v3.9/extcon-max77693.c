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
time << V_12 ,
V_13 ) ;
if ( V_4 ) {
F_3 ( V_2 -> V_14 , L_1 ) ;
return - V_15 ;
}
break;
default:
F_3 ( V_2 -> V_14 , L_2 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_17 , bool V_18 )
{
int V_4 = 0 ;
T_1 V_19 , V_20 = 0 ;
if ( V_18 )
V_19 = V_17 ;
else
V_19 = V_21 ;
V_4 = F_2 ( V_2 -> V_9 -> V_10 ,
V_22 , V_19 , V_23 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_14 , L_3 ) ;
return - V_15 ;
}
if ( V_18 )
V_20 |= V_24 ;
else
V_20 |= V_25 ;
V_4 = F_2 ( V_2 -> V_9 -> V_10 ,
V_26 , V_20 ,
V_25 | V_24 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_14 , L_3 ) ;
return - V_15 ;
}
F_5 ( V_2 -> V_14 ,
L_4 ,
V_19 , V_20 , V_18 ? L_5 : L_6 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
enum V_27 V_28 , bool * V_18 )
{
int V_29 = 0 ;
int V_30 ;
int V_31 ;
int V_32 ;
int V_33 ;
int V_34 ;
switch ( V_28 ) {
case V_35 :
V_30 = V_2 -> V_36 [ 0 ] & V_37 ;
V_30 >>= V_38 ;
if ( V_30 == V_39 ) {
* V_18 = false ;
V_29 = V_2 -> V_40 ;
V_2 -> V_40 = V_39 ;
} else {
* V_18 = true ;
V_29 = V_2 -> V_40 = V_30 ;
}
break;
case V_41 :
V_30 = V_2 -> V_36 [ 0 ] & V_37 ;
V_30 >>= V_38 ;
if ( V_30 == V_39 ) {
* V_18 = false ;
V_29 = V_2 -> V_42 ;
V_2 -> V_42 = V_39 ;
} else {
* V_18 = true ;
V_32 = V_2 -> V_36 [ 0 ] & V_43 ;
V_32 >>= V_44 ;
V_31 = V_2 -> V_36 [ 0 ] & V_45 ;
V_31 >>= V_46 ;
V_33 = V_2 -> V_36 [ 1 ] & V_47 ;
V_33 >>= V_48 ;
V_29 = ( ( 0x1 << 8 )
| ( V_33 << 2 )
| ( V_32 << 1 )
| V_31 ) ;
V_2 -> V_40 = V_30 ;
V_2 -> V_42 = V_29 ;
}
break;
case V_49 :
V_34 = V_2 -> V_36 [ 1 ] & V_50 ;
V_34 >>= V_51 ;
if ( V_34 == V_52 ) {
* V_18 = false ;
V_29 = V_2 -> V_53 ;
V_2 -> V_53 = V_52 ;
} else {
* V_18 = true ;
V_29 = V_2 -> V_53 = V_34 ;
}
break;
case V_54 :
V_30 = V_2 -> V_36 [ 0 ] & V_37 ;
V_30 >>= V_38 ;
V_34 = V_2 -> V_36 [ 1 ] & V_50 ;
V_34 >>= V_51 ;
if ( V_30 == V_39
&& V_34 == V_52 )
* V_18 = false ;
else
* V_18 = true ;
V_33 = V_2 -> V_36 [ 1 ] & V_47 ;
V_33 >>= V_48 ;
V_29 = V_33 ;
break;
default:
F_3 ( V_2 -> V_14 , L_7 , V_28 ) ;
V_29 = - V_16 ;
break;
}
return V_29 ;
}
static int F_7 ( struct V_1 * V_2 ,
int V_29 , bool V_18 )
{
int V_4 = 0 ;
int V_33 ;
bool V_55 ;
char V_56 [ V_57 ] ;
F_5 ( V_2 -> V_14 ,
L_8 ,
V_18 ? L_5 : L_6 , V_29 ) ;
switch ( V_29 ) {
case V_58 :
V_33 = F_6 ( V_2 ,
V_54 , & V_55 ) ;
if ( V_18 && ! V_33 ) {
F_8 ( V_2 -> V_14 ,
L_9 ) ;
return 0 ;
}
V_4 = F_4 ( V_2 , V_2 -> V_59 , V_18 ) ;
if ( V_4 < 0 )
return V_4 ;
F_9 ( V_2 -> V_60 , L_10 , V_18 ) ;
F_9 ( V_2 -> V_60 , L_11 , V_18 ) ;
goto V_61;
case V_62 :
strcpy ( V_56 , L_12 ) ;
break;
case V_63 :
strcpy ( V_56 , L_13 ) ;
break;
case V_64 :
strcpy ( V_56 , L_14 ) ;
if ( ! V_18 )
F_9 ( V_2 -> V_60 , L_15 , false ) ;
break;
default:
F_3 ( V_2 -> V_14 , L_16 ,
V_18 ? L_5 : L_6 ) ;
return - V_16 ;
}
V_4 = F_4 ( V_2 , V_65 , V_18 ) ;
if ( V_4 < 0 )
return V_4 ;
F_9 ( V_2 -> V_60 , V_56 , V_18 ) ;
V_61:
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
int V_66 , bool V_18 )
{
struct V_67 * V_68 = V_2 -> V_68 ;
unsigned int V_69 ;
switch ( V_66 ) {
case V_70 - 1
... V_70 + 1 :
V_69 = V_71 ;
break;
case V_72 - 1
... V_72 + 1 :
V_69 = V_73 ;
break;
case V_74 :
V_69 = V_75 ;
break;
case V_76 :
V_69 = V_77 ;
break;
case V_78 - 1
... V_78 + 1 :
V_69 = V_79 ;
break;
default:
F_3 ( V_2 -> V_14 ,
L_17 ,
V_18 ? L_18 : L_19 , V_66 ) ;
return - V_16 ;
}
F_11 ( V_68 , V_80 , V_69 , V_18 ) ;
F_12 ( V_68 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_81 ;
int V_4 = 0 ;
bool V_18 ;
V_81 = F_6 ( V_2 ,
V_41 , & V_18 ) ;
switch ( V_81 ) {
case V_82 :
case V_83 :
V_4 = F_4 ( V_2 , V_84 , V_18 ) ;
if ( V_4 < 0 )
return V_4 ;
F_9 ( V_2 -> V_60 , L_20 , V_18 ) ;
break;
case V_85 :
V_4 = F_4 ( V_2 , V_65 , V_18 ) ;
if ( V_4 < 0 )
return V_4 ;
F_9 ( V_2 -> V_60 ,
L_21 , V_18 ) ;
break;
case V_86 :
case V_87 :
F_9 ( V_2 -> V_60 , L_11 , V_18 ) ;
break;
default:
F_3 ( V_2 -> V_14 , L_22 ,
V_18 ? L_5 : L_6 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
int V_29 , bool V_18 )
{
char V_88 [ 32 ] ;
int V_4 = 0 ;
T_1 V_89 = V_21 ;
F_5 ( V_2 -> V_14 ,
L_8 ,
V_18 ? L_5 : L_6 , V_29 ) ;
switch ( V_29 ) {
case V_90 :
strcpy ( V_88 , L_23 ) ;
V_89 = V_84 ;
break;
case V_91 :
strcpy ( V_88 , L_24 ) ;
V_89 = V_84 ;
break;
case V_92 :
strcpy ( V_88 , L_25 ) ;
V_89 = V_93 ;
break;
default:
F_3 ( V_2 -> V_14 , L_26 ,
V_18 ? L_5 : L_6 ) ;
return - V_16 ;
}
V_4 = F_4 ( V_2 , V_89 , V_18 ) ;
if ( V_4 < 0 )
return V_4 ;
F_9 ( V_2 -> V_60 , V_88 , V_18 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_29 ;
int V_66 ;
bool V_18 ;
int V_4 = 0 ;
V_29 = F_6 ( V_2 ,
V_35 , & V_18 ) ;
F_5 ( V_2 -> V_14 ,
L_27 ,
V_18 ? L_5 : L_6 , V_29 ,
V_2 -> V_40 ) ;
switch ( V_29 ) {
case V_94 :
F_13 ( V_2 ) ;
break;
case V_90 :
case V_91 :
case V_92 :
V_4 = F_14 ( V_2 , V_29 , V_18 ) ;
if ( V_4 < 0 )
return V_4 ;
break;
case V_58 :
case V_62 :
case V_63 :
case V_64 :
V_4 = F_7 ( V_2 , V_29 , V_18 ) ;
if ( V_4 < 0 )
return V_4 ;
break;
case V_70 :
case V_72 :
case V_74 :
case V_76 :
case V_78 :
if ( V_18 )
V_66 = V_2 -> V_95 = V_29 ;
else
V_66 = V_2 -> V_95 ;
V_4 = F_10 ( V_2 , V_66 ,
V_18 ) ;
if ( V_4 < 0 )
return V_4 ;
break;
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
case V_113 :
F_5 ( V_2 -> V_14 ,
L_28 ,
V_18 ? L_5 : L_6 , V_29 ) ;
return - V_15 ;
default:
F_3 ( V_2 -> V_14 ,
L_29 ,
V_18 ? L_5 : L_6 , V_29 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_34 ;
int V_81 ;
int V_29 ;
bool V_18 ;
bool V_55 ;
int V_4 = 0 ;
V_34 = F_6 ( V_2 ,
V_49 , & V_18 ) ;
F_5 ( V_2 -> V_14 ,
L_30 ,
V_18 ? L_5 : L_6 ,
V_34 , V_2 -> V_53 ) ;
switch ( V_34 ) {
case V_114 :
case V_115 :
case V_52 :
V_81 = F_6 ( V_2 ,
V_41 ,
& V_55 ) ;
switch ( V_81 ) {
case V_86 :
case V_87 :
F_9 ( V_2 -> V_60 , L_31 , V_18 ) ;
if ( ! V_55 )
F_9 ( V_2 -> V_60 , L_11 , V_55 ) ;
break;
}
V_29 = F_6 ( V_2 ,
V_35 ,
& V_55 ) ;
switch ( V_29 ) {
case V_64 :
F_9 ( V_2 -> V_60 , L_15 , V_18 ) ;
if ( ! V_55 )
F_9 ( V_2 -> V_60 , L_14 , V_55 ) ;
break;
case V_58 :
V_4 = F_4 ( V_2 , V_2 -> V_59 , V_18 ) ;
if ( V_4 < 0 )
return V_4 ;
F_9 ( V_2 -> V_60 , L_10 , V_18 ) ;
F_9 ( V_2 -> V_60 , L_11 , V_18 ) ;
break;
}
switch ( V_34 ) {
case V_52 :
break;
case V_114 :
V_4 = F_4 ( V_2 , V_2 -> V_59 , V_18 ) ;
if ( V_4 < 0 )
return V_4 ;
F_9 ( V_2 -> V_60 , L_15 , V_18 ) ;
break;
case V_115 :
F_9 ( V_2 -> V_60 , L_32 , V_18 ) ;
break;
}
break;
case V_116 :
F_9 ( V_2 -> V_60 ,
L_33 , V_18 ) ;
break;
case V_117 :
F_9 ( V_2 -> V_60 , L_34 , V_18 ) ;
break;
case V_118 :
F_9 ( V_2 -> V_60 , L_35 , V_18 ) ;
break;
case V_119 :
break;
default:
F_3 ( V_2 -> V_14 ,
L_36 ,
V_18 ? L_5 : L_6 , V_34 ) ;
return - V_16 ;
}
return 0 ;
}
static void F_17 ( struct V_120 * V_121 )
{
struct V_1 * V_2 = F_18 ( V_121 ,
struct V_1 , V_122 ) ;
int V_123 = - 1 ;
int V_124 , V_4 = 0 ;
if ( ! V_2 -> V_60 )
return;
F_19 ( & V_2 -> V_125 ) ;
for ( V_124 = 0 ; V_124 < F_20 ( V_126 ) ; V_124 ++ )
if ( V_2 -> V_127 == V_126 [ V_124 ] . V_128 )
V_123 = V_126 [ V_124 ] . V_127 ;
V_4 = F_21 ( V_2 -> V_9 -> V_10 ,
V_129 , 2 , V_2 -> V_36 ) ;
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
int V_30 ;
int V_34 ;
bool V_18 ;
F_19 ( & V_2 -> V_125 ) ;
V_4 = F_21 ( V_2 -> V_9 -> V_10 ,
V_129 , 2 , V_2 -> V_36 ) ;
if ( V_4 ) {
F_3 ( V_2 -> V_14 , L_37 ) ;
F_22 ( & V_2 -> V_125 ) ;
return - V_16 ;
}
V_30 = F_6 ( V_2 , V_35 ,
& V_18 ) ;
if ( V_18 && V_30 != V_39 ) {
V_4 = F_15 ( V_2 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_14 , L_40 ) ;
F_22 ( & V_2 -> V_125 ) ;
return V_4 ;
}
}
V_34 = F_6 ( V_2 , V_49 ,
& V_18 ) ;
if ( V_18 && V_34 != V_52 ) {
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
T_1 V_159 ;
V_2 = F_31 ( & V_150 -> V_14 , sizeof( struct V_1 ) ,
V_160 ) ;
if ( ! V_2 ) {
F_3 ( & V_150 -> V_14 , L_42 ) ;
return - V_161 ;
}
V_2 -> V_14 = & V_150 -> V_14 ;
V_2 -> V_9 = V_9 ;
if ( V_2 -> V_9 -> V_10 ) {
F_32 ( & V_150 -> V_14 , L_43 ) ;
} else {
V_2 -> V_9 -> V_10 = F_33 (
V_2 -> V_9 -> V_162 ,
& V_163 ) ;
if ( F_34 ( V_2 -> V_9 -> V_10 ) ) {
V_4 = F_35 ( V_2 -> V_9 -> V_10 ) ;
F_3 ( V_9 -> V_14 ,
L_44 , V_4 ) ;
return V_4 ;
}
}
V_2 -> V_68 = F_36 ( & V_150 -> V_14 ) ;
if ( ! V_2 -> V_68 ) {
F_3 ( & V_150 -> V_14 , L_45 , V_164 ) ;
return - V_161 ;
}
V_2 -> V_68 -> V_165 = L_46 ;
V_2 -> V_68 -> V_166 = L_47 ;
V_2 -> V_68 -> V_14 . V_152 = & V_150 -> V_14 ;
F_37 ( V_167 , V_2 -> V_68 -> V_168 ) ;
F_38 ( V_2 -> V_68 , V_80 , V_77 ) ;
F_38 ( V_2 -> V_68 , V_80 , V_75 ) ;
F_38 ( V_2 -> V_68 , V_80 , V_79 ) ;
F_38 ( V_2 -> V_68 , V_80 , V_71 ) ;
F_38 ( V_2 -> V_68 , V_80 , V_73 ) ;
V_4 = F_39 ( V_2 -> V_68 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_150 -> V_14 , L_48 ,
V_4 ) ;
return V_4 ;
}
F_40 ( V_150 , V_2 ) ;
F_41 ( & V_2 -> V_125 ) ;
F_42 ( & V_2 -> V_122 , F_17 ) ;
for ( V_124 = 0 ; V_124 < F_20 ( V_126 ) ; V_124 ++ ) {
struct V_169 * V_170 = & V_126 [ V_124 ] ;
unsigned int V_128 = 0 ;
V_128 = F_43 ( V_9 -> V_171 , V_170 -> V_127 ) ;
if ( ! V_128 ) {
V_4 = - V_16 ;
goto V_172;
}
V_170 -> V_128 = V_128 ;
V_4 = F_44 ( V_128 , NULL ,
F_23 ,
V_173 ,
V_170 -> V_165 , V_2 ) ;
if ( V_4 ) {
F_3 ( & V_150 -> V_14 ,
L_49
L_50 ,
V_170 -> V_127 , V_4 ) ;
goto V_172;
}
}
V_2 -> V_60 = F_31 ( & V_150 -> V_14 , sizeof( struct V_174 ) ,
V_160 ) ;
if ( ! V_2 -> V_60 ) {
F_3 ( & V_150 -> V_14 , L_51 ) ;
V_4 = - V_161 ;
goto V_172;
}
V_2 -> V_60 -> V_165 = V_175 ;
V_2 -> V_60 -> V_176 = V_177 ;
V_4 = F_45 ( V_2 -> V_60 , NULL ) ;
if ( V_4 ) {
F_3 ( & V_150 -> V_14 , L_52 ) ;
goto V_172;
}
if ( V_154 -> V_178 ) {
V_156 = V_154 -> V_178 -> V_156 ;
V_157 = V_154 -> V_178 -> V_157 ;
} else {
V_156 = V_179 ;
V_157 = F_20 ( V_179 ) ;
}
for ( V_124 = 0 ; V_124 < V_157 ; V_124 ++ ) {
enum V_180 V_181
= V_182 ;
F_46 ( V_2 -> V_9 -> V_10 ,
V_156 [ V_124 ] . V_183 ,
V_156 [ V_124 ] . V_146 ) ;
switch ( V_156 [ V_124 ] . V_183 ) {
case V_184 :
V_181 = V_185 ;
break;
case V_186 :
V_181 = V_187 ;
break;
case V_188 :
V_181 = V_189 ;
break;
}
if ( V_181 < V_182 )
V_2 -> V_9 -> V_190 [ V_181 ]
= V_156 [ V_124 ] . V_146 ;
}
if ( V_154 -> V_178 ) {
struct V_191 * V_192 = V_154 -> V_178 ;
if ( V_192 -> V_193 )
V_2 -> V_193 = V_192 -> V_193 ;
else
V_2 -> V_193 = V_93 ;
if ( V_192 -> V_59 )
V_2 -> V_59 = V_192 -> V_59 ;
else
V_2 -> V_59 = V_84 ;
if ( V_192 -> V_194 )
V_158 =
F_47 ( V_192 -> V_194 ) ;
else
V_158 = F_47 ( V_195 ) ;
} else {
V_2 -> V_59 = V_84 ;
V_2 -> V_193 = V_93 ;
V_158 = F_47 ( V_195 ) ;
}
F_4 ( V_2 , V_2 -> V_193 , true ) ;
V_4 = F_48 ( V_2 -> V_9 -> V_10 ,
V_196 , & V_159 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_150 -> V_14 , L_53 ) ;
goto V_197;
}
F_5 ( V_2 -> V_14 , L_54 , V_159 ) ;
F_1 ( V_2 , V_7 ) ;
F_49 ( & V_2 -> V_148 , F_26 ) ;
F_50 ( & V_2 -> V_148 , V_158 ) ;
return V_4 ;
V_197:
F_51 ( V_2 -> V_60 ) ;
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
F_56 ( V_2 -> V_68 ) ;
F_51 ( V_2 -> V_60 ) ;
return 0 ;
}
