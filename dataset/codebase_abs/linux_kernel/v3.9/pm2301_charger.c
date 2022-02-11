static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 )
return;
F_2 ( V_2 -> V_5 , 1 ) ;
return;
}
static void F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 )
return;
F_2 ( V_2 -> V_5 , 0 ) ;
return;
}
static int F_4 ( struct V_1 * V_2 , int V_6 , T_1 * V_7 )
{
int V_8 ;
F_5 ( & V_2 -> V_9 ) ;
F_1 ( V_2 ) ;
V_8 = F_6 ( V_2 -> V_10 . V_11 , V_6 ,
1 , V_7 ) ;
if ( V_8 < 0 )
F_7 ( V_2 -> V_12 , L_1 , V_6 ) ;
else
V_8 = 0 ;
F_3 ( V_2 ) ;
F_8 ( & V_2 -> V_9 ) ;
return V_8 ;
}
static int F_9 ( struct V_1 * V_2 , int V_6 , T_1 V_7 )
{
int V_8 ;
F_5 ( & V_2 -> V_9 ) ;
F_1 ( V_2 ) ;
V_8 = F_10 ( V_2 -> V_10 . V_11 , V_6 ,
1 , & V_7 ) ;
if ( V_8 < 0 )
F_7 ( V_2 -> V_12 , L_2 , V_6 ) ;
else
V_8 = 0 ;
F_3 ( V_2 ) ;
F_8 ( & V_2 -> V_9 ) ;
return V_8 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_8 ;
V_8 = F_9 ( V_2 , V_13 ,
( V_14 | V_15 ) ) ;
return V_8 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_8 ;
V_8 = F_9 ( V_2 , V_13 ,
( V_16 | V_17 ) ) ;
return V_8 ;
}
static int F_13 ( struct V_1 * V_2 , int V_7 )
{
F_14 ( V_2 -> V_18 , & V_2 -> V_19 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , int V_7 )
{
F_14 ( V_2 -> V_18 , & V_2 -> V_19 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , int V_7 )
{
int V_8 = 0 ;
V_2 -> V_20 ++ ;
if ( V_2 -> V_20 < 4 ) {
V_8 = F_11 ( V_2 ) ;
goto V_21;
} else {
V_2 -> V_20 = 0 ;
F_7 ( V_2 -> V_12 , L_3 ) ;
V_2 -> V_22 . V_23 = true ;
F_17 ( & V_2 -> V_24 . V_25 ) ;
}
V_21:
return V_8 ;
}
static int F_18 ( struct V_1 * V_2 , int V_7 )
{
F_19 ( V_2 -> V_12 , L_4 ) ;
V_2 -> V_3 . V_26 = true ;
F_17 ( & V_2 -> V_24 . V_25 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , int V_7 )
{
switch ( V_7 ) {
case V_27 :
F_19 ( V_2 -> V_12 , L_5 ) ;
break;
case V_28 :
F_19 ( V_2 -> V_12 , L_6 ) ;
break;
default:
F_7 ( V_2 -> V_12 , L_7 ) ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , int V_7 )
{
F_19 ( V_2 -> V_12 , L_8 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , T_1 * V_7 )
{
int V_8 ;
V_8 = F_4 ( V_2 , V_29 , V_7 ) ;
if ( V_8 < 0 ) {
F_7 ( V_2 -> V_12 , L_9 ) ;
goto V_21;
}
* V_7 &= ( V_30 | V_31 ) ;
V_21:
return V_8 ;
}
static int F_23 ( struct V_1 * V_2 , int V_7 )
{
int V_8 ;
T_1 V_32 ;
V_8 = F_22 ( V_2 , & V_32 ) ;
if ( ( V_8 == 0 ) && V_32 ) {
V_2 -> V_3 . V_4 = 1 ;
V_2 -> V_33 = true ;
F_14 ( V_2 -> V_18 , & V_2 -> V_34 ) ;
}
return V_8 ;
}
static int F_24 ( struct V_1 * V_2 ,
int V_7 )
{
V_2 -> V_3 . V_4 = 0 ;
F_14 ( V_2 -> V_18 , & V_2 -> V_34 ) ;
return 0 ;
}
static int F_25 ( void * V_35 , int V_7 )
{
struct V_1 * V_2 = V_35 ;
int V_8 = 0 ;
if ( V_7 & ( V_27 | V_28 ) ) {
V_8 = F_20 ( V_2 , V_7 &
( V_27 | V_28 ) ) ;
}
if ( V_7 & V_36 ) {
V_8 = F_21 ( V_2 ,
V_36 ) ;
}
return V_8 ;
}
static int F_26 ( void * V_35 , int V_7 )
{
struct V_1 * V_2 = V_35 ;
int V_8 = 0 ;
if ( V_7 & ( V_37 | V_38 ) ) {
F_19 ( V_2 -> V_12 , L_10 ) ;
V_8 = F_23 ( V_2 , V_7 &
( V_37 | V_38 ) ) ;
}
if ( V_7 &
( V_39 | V_40 ) ) {
F_19 ( V_2 -> V_12 , L_11 ) ;
V_8 = F_24 ( V_2 , V_7 &
( V_39 |
V_40 ) ) ;
}
return V_8 ;
}
static int F_27 ( void * V_35 , int V_7 )
{
struct V_1 * V_2 = V_35 ;
int V_8 = 0 ;
if ( V_7 & V_41 )
V_8 = F_18 ( V_2 , V_7 ) ;
if ( V_7 & ( V_42 |
V_43 | V_44 ) ) {
F_19 ( V_2 -> V_12 ,
L_12 ) ;
}
return V_8 ;
}
static int F_28 ( void * V_35 , int V_7 )
{
struct V_1 * V_2 = V_35 ;
int V_8 = 0 ;
if ( V_7 & ( V_45 ) ) {
F_19 ( V_2 -> V_12 ,
L_13 ) ;
}
if ( V_7 & ( V_46 ) ) {
F_19 ( V_2 -> V_12 ,
L_14 ) ;
}
if ( V_7 & ( V_47 ) ) {
F_19 ( V_2 -> V_12 , L_15 ) ;
}
if ( V_7 & ( V_48 ) ) {
F_19 ( V_2 -> V_12 , L_16 ) ;
}
if ( V_7 & ( V_49 | V_50 ) ) {
V_2 -> V_51 = V_52 ;
V_8 = F_16 ( V_2 , V_7 &
( V_49 | V_50 ) ) ;
F_19 ( V_2 -> V_12 , L_17 ) ;
}
if ( V_7 & ( V_53 |
V_54 ) ) {
V_8 = F_13 ( V_2 , V_7 &
( V_53 |
V_54 ) ) ;
F_19 ( V_2 -> V_12 , L_18 ) ;
}
return V_8 ;
}
static int F_29 ( void * V_35 , int V_7 )
{
struct V_1 * V_2 = V_35 ;
int V_8 = 0 ;
if ( V_7 & V_55 ) {
V_2 -> V_51 = V_56 ;
V_8 = F_16 ( V_2 , V_7 &
V_55 ) ;
F_19 ( V_2 -> V_12 , L_19 ) ;
}
if ( V_7 & ( V_57 |
V_58 |
V_59 |
V_60 ) ) {
F_19 ( V_2 -> V_12 , L_20 ) ;
V_8 = F_15 ( V_2 , V_7 &
( V_57 |
V_58 |
V_59 |
V_60 ) ) ;
}
return V_8 ;
}
static int F_30 ( void * V_35 , int V_7 )
{
struct V_1 * V_2 = V_35 ;
int V_8 = 0 ;
if ( V_7 & ( V_61 | V_62 ) ) {
F_19 ( V_2 -> V_12 , L_21 ) ;
}
if ( V_7 & ( V_63 |
V_64 |
V_65 |
V_66 ) ) {
F_19 ( V_2 -> V_12 , L_22 ) ;
}
return V_8 ;
}
static T_2 F_31 ( int V_67 , void * V_68 )
{
struct V_1 * V_2 = V_68 ;
struct V_69 * V_70 = V_2 -> V_71 ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_73 ; V_72 ++ ) {
F_4 ( V_2 ,
V_74 [ V_72 ] ,
& ( V_70 -> V_6 [ V_72 ] ) ) ;
if ( V_70 -> V_6 [ V_72 ] > 0 )
V_70 -> V_75 [ V_72 ] ( V_2 , V_70 -> V_6 [ V_72 ] ) ;
}
return V_76 ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_8 = 0 ;
T_1 V_7 ;
if ( V_2 -> V_3 . V_4 && V_2 -> V_3 . V_77 ) {
V_8 = F_4 ( V_2 , V_78 , & V_7 ) ;
if ( V_8 < 0 ) {
F_7 ( V_2 -> V_12 , L_23 , V_79 ) ;
goto V_21;
}
if ( V_7 & V_80 )
V_8 = V_81 ;
else
V_8 = V_82 ;
}
V_21:
return V_8 ;
}
static int F_33 ( int V_83 )
{
int V_72 ;
if ( V_83 < V_84 [ 0 ] )
return 0 ;
for ( V_72 = 1 ; V_72 < F_34 ( V_84 ) ; V_72 ++ ) {
if ( V_83 < V_84 [ V_72 ] )
return ( V_72 - 1 ) ;
}
V_72 = F_34 ( V_84 ) - 1 ;
if ( V_83 == V_84 [ V_72 ] )
return V_72 ;
else
return - V_85 ;
}
static int F_35 ( int V_83 )
{
int V_72 ;
if ( V_83 < V_86 [ 0 ] )
return 0 ;
for ( V_72 = 1 ; V_72 < F_34 ( V_86 ) ; V_72 ++ ) {
if ( V_83 < V_86 [ V_72 ] )
return V_72 - 1 ;
}
V_72 = F_34 ( V_86 ) - 1 ;
if ( V_83 == V_86 [ V_72 ] )
return V_72 ;
else
return - V_85 ;
}
static int F_36 ( struct V_87 * V_88 ,
int V_89 )
{
int V_8 ;
int V_90 ;
struct V_1 * V_2 ;
T_1 V_7 ;
if ( V_88 -> V_25 . type == V_91 )
V_2 = F_37 ( V_88 ) ;
else
return - V_92 ;
V_90 = F_33 ( V_89 ) ;
if ( V_90 < 0 ) {
F_7 ( V_2 -> V_12 ,
L_24 ) ;
return - V_92 ;
}
V_8 = F_4 ( V_2 , V_93 , & V_7 ) ;
if ( V_8 >= 0 ) {
V_7 &= ~ V_94 ;
V_7 |= V_90 ;
V_8 = F_9 ( V_2 , V_93 , V_7 ) ;
if ( V_8 < 0 ) {
F_7 ( V_2 -> V_12 ,
L_25 , V_79 ) ;
}
}
else
F_7 ( V_2 -> V_12 , L_26 , V_79 ) ;
return V_8 ;
}
static int F_38 ( struct V_95 * V_25 ,
enum V_96 V_97 ,
union V_98 * V_7 )
{
struct V_1 * V_2 ;
V_2 = F_37 ( F_39 ( V_25 ) ) ;
switch ( V_97 ) {
case V_99 :
if ( V_2 -> V_22 . V_100 )
V_7 -> V_101 = V_102 ;
else if ( V_2 -> V_3 . V_26 )
V_7 -> V_101 = V_103 ;
else if ( V_2 -> V_22 . V_104 )
V_7 -> V_101 = V_105 ;
else
V_7 -> V_101 = V_106 ;
break;
case V_107 :
V_7 -> V_101 = V_2 -> V_3 . V_77 ;
break;
case V_108 :
V_7 -> V_101 = V_2 -> V_3 . V_4 ;
break;
case V_109 :
V_2 -> V_3 . V_110 = F_32 ( V_2 ) ;
V_7 -> V_101 = V_2 -> V_3 . V_110 ;
break;
default:
return - V_85 ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_8 = 0 ;
V_8 = F_9 ( V_2 , V_111 ,
( V_112 | V_113 ) ) ;
if( V_8 < 0 )
return V_8 ;
V_8 = F_9 ( V_2 , V_114 ,
V_115 ) ;
V_8 = F_9 ( V_2 , V_116 ,
V_117 ) ;
V_8 = F_9 ( V_2 , V_93 ,
( V_118 |
V_119 |
V_120 ) ) ;
V_8 = F_9 ( V_2 , V_121 ,
( V_122 | V_123 ) ) ;
V_8 = F_9 ( V_2 , V_124 ,
V_125 ) ;
V_8 = F_9 ( V_2 , V_126 ,
( V_127 | V_128 |
V_129 |
V_130 ) ) ;
V_8 = F_9 ( V_2 , V_131 ,
V_132 ) ;
V_8 = F_9 ( V_2 , V_133 ,
V_134 ) ;
V_8 = F_9 ( V_2 , V_135 ,
( V_136 | V_137 |
V_138 ) ) ;
V_8 = F_9 ( V_2 , V_139 ,
( V_140 | V_141 |
V_142 ) ) ;
V_8 = F_9 ( V_2 , V_143 ,
V_144 ) ;
V_8 = F_9 ( V_2 , V_145 ,
V_146 ) ;
return V_8 ;
}
static int F_41 ( struct V_87 * V_88 ,
int V_147 , int V_148 , int V_149 )
{
int V_8 ;
int V_150 ;
int V_90 ;
T_1 V_7 ;
struct V_1 * V_2 = F_37 ( V_88 ) ;
if ( V_147 ) {
if ( ! V_2 -> V_3 . V_4 ) {
F_19 ( V_2 -> V_12 , L_27 ) ;
return - V_92 ;
}
F_19 ( V_2 -> V_12 , L_28 , V_148 , V_149 ) ;
if ( ! V_2 -> V_151 ) {
F_42 ( V_2 -> V_152 ) ;
V_2 -> V_151 = true ;
}
V_8 = F_40 ( V_2 ) ;
if ( V_8 < 0 ) {
F_7 ( V_2 -> V_12 , L_29 ,
V_79 ) ;
goto V_153;
}
V_150 = F_35 ( V_148 ) ;
V_90 = F_33 ( V_149 ) ;
if ( V_150 < 0 || V_90 < 0 ) {
F_7 ( V_2 -> V_12 ,
L_30
L_31 ) ;
return - V_92 ;
}
V_8 = F_4 ( V_2 , V_124 , & V_7 ) ;
if ( V_8 < 0 ) {
F_7 ( V_2 -> V_12 , L_23 , V_79 ) ;
goto V_153;
}
V_7 &= ~ V_154 ;
V_7 |= V_150 ;
V_8 = F_9 ( V_2 , V_124 , V_7 ) ;
if ( V_8 < 0 ) {
F_7 ( V_2 -> V_12 , L_32 , V_79 ) ;
goto V_153;
}
V_8 = F_4 ( V_2 , V_93 , & V_7 ) ;
if ( V_8 < 0 ) {
F_7 ( V_2 -> V_12 , L_23 , V_79 ) ;
goto V_153;
}
V_7 &= ~ V_94 ;
V_7 |= V_90 ;
V_8 = F_9 ( V_2 , V_93 , V_7 ) ;
if ( V_8 < 0 ) {
F_7 ( V_2 -> V_12 , L_32 , V_79 ) ;
goto V_153;
}
if ( ! V_2 -> V_155 -> V_156 ) {
V_8 = F_4 ( V_2 , V_145 , & V_7 ) ;
if ( V_8 < 0 ) {
F_7 ( V_2 -> V_12 , L_23 ,
V_79 ) ;
goto V_153;
}
V_7 |= V_157 ;
V_8 = F_9 ( V_2 , V_145 , V_7 ) ;
if ( V_8 < 0 ) {
F_7 ( V_2 -> V_12 , L_32 ,
V_79 ) ;
goto V_153;
}
}
V_8 = F_11 ( V_2 ) ;
if ( V_8 < 0 ) {
F_7 ( V_2 -> V_12 , L_33
L_34 ) ;
goto V_153;
}
V_2 -> V_3 . V_77 = 1 ;
} else {
V_2 -> V_3 . V_77 = 0 ;
V_2 -> V_3 . V_26 = false ;
if ( V_2 -> V_151 ) {
F_43 ( V_2 -> V_152 ) ;
V_2 -> V_151 = false ;
}
V_8 = F_12 ( V_2 ) ;
if ( V_8 < 0 ) {
F_7 ( V_2 -> V_12 , L_35
L_34 ) ;
goto V_153;
}
F_19 ( V_2 -> V_12 , L_36 L_37 ) ;
}
F_17 ( & V_2 -> V_24 . V_25 ) ;
V_153:
return V_8 ;
}
static int F_44 ( struct V_87 * V_88 )
{
int V_8 ;
struct V_1 * V_2 ;
if ( V_88 -> V_25 . type == V_91 )
V_2 = F_37 ( V_88 ) ;
else
return - V_92 ;
V_8 = F_9 ( V_2 , V_158 , V_159 ) ;
if ( V_8 )
F_7 ( V_2 -> V_12 , L_38 ) ;
return V_8 ;
}
static void F_45 ( struct V_160 * V_161 )
{
struct V_1 * V_2 = F_46 ( V_161 ,
struct V_1 , V_34 ) ;
F_17 ( & V_2 -> V_24 . V_25 ) ;
F_47 ( & V_2 -> V_24 . V_25 . V_12 -> V_162 , NULL , L_39 ) ;
}
static void F_48 (
struct V_160 * V_161 )
{
}
static int F_49 ( struct V_163 * V_163 )
{
return 0 ;
}
static int F_50 ( struct V_163 * V_163 ,
T_3 V_164 )
{
return 0 ;
}
static int T_4 F_51 ( struct V_163 * V_163 ,
const struct V_165 * V_166 )
{
struct V_167 * V_168 = V_163 -> V_12 . V_169 ;
struct V_1 * V_2 ;
int V_8 = 0 ;
T_1 V_7 ;
V_2 = F_52 ( sizeof( struct V_1 ) , V_170 ) ;
if ( ! V_2 ) {
F_7 ( V_2 -> V_12 , L_40 ) ;
return - V_171 ;
}
V_2 -> V_12 = & V_163 -> V_12 ;
V_2 -> V_172 = F_53 ( L_41 ) ;
V_2 -> V_71 = & V_173 ;
if ( ! V_168 -> V_174 ) {
F_7 ( V_2 -> V_12 , L_42 ) ;
V_8 = - V_85 ;
goto V_175;
}
V_2 -> V_176 = V_168 -> V_174 ;
if ( ! V_168 -> V_177 ) {
F_7 ( V_2 -> V_12 , L_43 ) ;
V_8 = - V_85 ;
goto V_175;
}
V_2 -> V_155 = V_168 -> V_177 ;
if ( ! V_2 -> V_176 -> V_178 ) {
F_7 ( V_2 -> V_12 , L_44 ) ;
V_8 = - V_85 ;
goto V_175;
}
V_2 -> V_5 = V_2 -> V_176 -> V_178 ;
if ( ! F_54 ( V_163 -> V_179 ,
V_180 |
V_181 ) ) {
V_8 = - V_182 ;
F_55 ( V_2 -> V_12 , L_45 ) ;
goto V_175;
}
V_2 -> V_10 . V_11 = V_163 ;
V_2 -> V_10 . V_183 = (struct V_165 * ) V_166 ;
F_56 ( V_163 , V_2 ) ;
V_2 -> V_24 . V_25 . V_184 = V_2 -> V_176 -> V_185 ;
V_2 -> V_24 . V_25 . type = V_91 ;
V_2 -> V_24 . V_25 . V_186 = V_187 ;
V_2 -> V_24 . V_25 . V_188 = F_34 ( V_187 ) ;
V_2 -> V_24 . V_25 . V_189 = F_38 ;
V_2 -> V_24 . V_25 . V_190 = V_2 -> V_176 -> V_190 ;
V_2 -> V_24 . V_25 . V_191 = V_2 -> V_176 -> V_191 ;
V_2 -> V_24 . V_192 . V_147 = & F_41 ;
V_2 -> V_24 . V_192 . V_193 = & F_44 ;
V_2 -> V_24 . V_192 . V_194 = & F_36 ;
V_2 -> V_24 . V_195 = V_86 [
F_34 ( V_86 ) - 1 ] ;
V_2 -> V_24 . V_196 = V_84 [
F_34 ( V_84 ) - 1 ] ;
V_2 -> V_24 . V_197 = V_198 ;
V_2 -> V_24 . V_199 = true ;
V_2 -> V_24 . V_200 = true ;
V_2 -> V_18 =
F_57 ( L_46 ) ;
if ( V_2 -> V_18 == NULL ) {
F_7 ( V_2 -> V_12 , L_47 ) ;
goto V_175;
}
F_58 ( & V_2 -> V_34 , F_45 ) ;
F_58 ( & V_2 -> V_19 ,
F_48 ) ;
V_2 -> V_152 = F_59 ( V_2 -> V_12 , L_48 ) ;
if ( F_60 ( V_2 -> V_152 ) ) {
V_8 = F_61 ( V_2 -> V_152 ) ;
F_7 ( V_2 -> V_12 , L_49 ) ;
goto V_201;
}
V_8 = F_62 ( V_2 -> V_12 , & V_2 -> V_24 . V_25 ) ;
if ( V_8 ) {
F_7 ( V_2 -> V_12 , L_50 ) ;
goto V_202;
}
V_8 = F_63 ( V_2 -> V_176 -> V_203 , NULL ,
V_204 [ 0 ] . V_205 ,
V_2 -> V_176 -> V_206 ,
V_204 [ 0 ] . V_184 , V_2 ) ;
if ( V_8 != 0 ) {
F_7 ( V_2 -> V_12 , L_51 ,
V_204 [ 0 ] . V_184 , V_2 -> V_176 -> V_203 , V_8 ) ;
goto V_207;
}
F_64 ( & V_2 -> V_9 ) ;
V_8 = F_65 ( V_2 -> V_5 , L_52 ) ;
if ( V_8 < 0 ) {
F_7 ( V_2 -> V_12 , L_53 ) ;
goto V_207;
}
V_8 = F_66 ( V_2 -> V_5 , 0 ) ;
if ( V_8 < 0 ) {
F_7 ( V_2 -> V_12 , L_54 ) ;
goto V_208;
}
V_8 = F_22 ( V_2 , & V_7 ) ;
if ( ( V_8 == 0 ) && V_7 ) {
V_2 -> V_3 . V_4 = 1 ;
V_2 -> V_33 = true ;
F_17 ( & V_2 -> V_24 . V_25 ) ;
F_47 ( & V_2 -> V_24 . V_25 . V_12 -> V_162 , NULL , L_39 ) ;
}
return 0 ;
V_208:
F_67 ( V_2 -> V_5 ) ;
V_207:
F_68 ( & V_2 -> V_24 . V_25 ) ;
V_202:
F_69 ( V_2 -> V_152 ) ;
V_201:
F_70 ( V_2 -> V_18 ) ;
V_175:
F_71 ( V_2 ) ;
return V_8 ;
}
static int T_5 F_72 ( struct V_163 * V_163 )
{
struct V_1 * V_2 = F_73 ( V_163 ) ;
F_41 ( & V_2 -> V_24 , false , 0 , 0 ) ;
F_74 ( V_2 -> V_176 -> V_203 , V_2 ) ;
F_70 ( V_2 -> V_18 ) ;
F_75 () ;
F_69 ( V_2 -> V_152 ) ;
F_68 ( & V_2 -> V_24 . V_25 ) ;
F_67 ( V_2 -> V_5 ) ;
F_71 ( V_2 ) ;
return 0 ;
}
static int T_6 F_76 ( void )
{
return F_77 ( & V_209 ) ;
}
static void T_7 F_78 ( void )
{
F_79 ( & V_209 ) ;
}
