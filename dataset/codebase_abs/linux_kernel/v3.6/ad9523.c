static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 V_7 ;
int V_8 ;
struct V_9 V_10 [] = {
{
. V_11 = & V_5 -> V_12 [ 0 ] . V_13 [ 2 ] ,
. V_14 = 2 ,
} , {
. V_15 = & V_5 -> V_12 [ 1 ] . V_13 [ 4 - F_3 ( V_3 ) ] ,
. V_14 = F_3 ( V_3 ) ,
} ,
} ;
F_4 ( & V_7 ) ;
F_5 ( & V_10 [ 0 ] , & V_7 ) ;
F_5 ( & V_10 [ 1 ] , & V_7 ) ;
V_5 -> V_12 [ 0 ] . V_16 = F_6 ( V_17 |
F_7 ( F_3 ( V_3 ) ) |
F_8 ( V_3 ) ) ;
V_8 = F_9 ( V_5 -> V_18 , & V_7 ) ;
if ( V_8 < 0 )
F_10 ( & V_2 -> V_19 , L_1 , V_8 ) ;
else
V_8 = F_11 ( V_5 -> V_12 [ 1 ] . V_16 ) & ( 0xFFFFFF >>
( 8 * ( 3 - F_3 ( V_3 ) ) ) ) ;
return V_8 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned V_3 , unsigned V_20 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 V_7 ;
int V_8 ;
struct V_9 V_10 [] = {
{
. V_11 = & V_5 -> V_12 [ 0 ] . V_13 [ 2 ] ,
. V_14 = 2 ,
} , {
. V_11 = & V_5 -> V_12 [ 1 ] . V_13 [ 4 - F_3 ( V_3 ) ] ,
. V_14 = F_3 ( V_3 ) ,
} ,
} ;
F_4 ( & V_7 ) ;
F_5 ( & V_10 [ 0 ] , & V_7 ) ;
F_5 ( & V_10 [ 1 ] , & V_7 ) ;
V_5 -> V_12 [ 0 ] . V_16 = F_6 ( V_21 |
F_7 ( F_3 ( V_3 ) ) |
F_8 ( V_3 ) ) ;
V_5 -> V_12 [ 1 ] . V_16 = F_6 ( V_20 ) ;
V_8 = F_9 ( V_5 -> V_18 , & V_7 ) ;
if ( V_8 < 0 )
F_10 ( & V_2 -> V_19 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_13 ( struct V_1 * V_2 )
{
return F_12 ( V_2 , V_22 , V_23 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned V_24 , unsigned V_25 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_8 ;
unsigned V_26 ;
switch ( V_24 ) {
case 0 ... 3 :
V_8 = F_1 ( V_2 , V_27 ) ;
if ( V_8 < 0 )
break;
V_26 = V_28 << V_24 ;
if ( V_25 ) {
V_8 |= V_26 ;
V_25 = 2 ;
} else {
V_8 &= ~ V_26 ;
}
V_8 = F_12 ( V_2 ,
V_27 , V_8 ) ;
break;
case 4 ... 6 :
V_8 = F_1 ( V_2 , V_29 ) ;
if ( V_8 < 0 )
break;
V_26 = V_30 << ( V_24 - 4 ) ;
if ( V_25 )
V_8 |= V_26 ;
else
V_8 &= ~ V_26 ;
V_8 = F_12 ( V_2 , V_29 , V_8 ) ;
break;
case 7 ... 9 :
V_8 = F_1 ( V_2 , V_27 ) ;
if ( V_8 < 0 )
break;
V_26 = V_31 << ( V_24 - 7 ) ;
if ( V_25 )
V_8 |= V_26 ;
else
V_8 &= ~ V_26 ;
V_8 = F_12 ( V_2 ,
V_27 , V_8 ) ;
break;
default:
return 0 ;
}
V_5 -> V_32 [ V_24 ] = V_25 ;
return V_8 ;
}
static int F_15 ( struct V_1 * V_2 ,
unsigned V_24 , unsigned long V_33 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
long V_34 , V_35 ;
bool V_36 ;
switch ( V_24 ) {
case 0 ... 3 :
V_36 = ( V_33 == V_5 -> V_37 [ V_38 ] ) ;
break;
case 4 ... 9 :
V_34 = V_5 -> V_37 [ V_39 ] / V_33 ;
V_35 = V_5 -> V_37 [ V_40 ] / V_33 ;
V_34 *= V_33 ;
V_35 *= V_33 ;
V_36 = ( abs ( V_34 - V_33 ) > abs ( V_35 - V_33 ) ) ;
break;
default:
return 0 ;
}
return F_14 ( V_2 , V_24 , V_36 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_8 , V_41 ;
V_8 = F_12 ( V_2 , V_42 ,
V_43 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_12 ( V_2 , V_44 ,
V_45 ) ;
if ( V_8 < 0 )
return V_8 ;
V_41 = 4 ;
do {
F_17 ( 16 ) ;
V_8 = F_1 ( V_2 ,
V_46 ) ;
if ( V_8 < 0 )
return V_8 ;
} while ( ( V_8 & V_47 ) && V_41 -- );
V_8 = F_12 ( V_2 , V_42 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_1 ( V_2 , V_48 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 & V_49 ) {
F_10 ( & V_2 -> V_19 , L_3 ) ;
V_8 = - V_50 ;
}
return V_8 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_8 , V_41 ;
V_8 = F_1 ( V_2 , V_51 ) ;
if ( V_8 < 0 )
return V_8 ;
V_41 = V_8 ;
V_41 |= V_52 ;
V_8 = F_12 ( V_2 , V_51 , V_41 ) ;
if ( V_8 < 0 )
return V_8 ;
F_13 ( V_2 ) ;
V_41 &= ~ V_52 ;
V_8 = F_12 ( V_2 , V_51 , V_41 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_13 ( V_2 ) ;
}
static T_1 F_19 ( struct V_53 * V_19 ,
struct V_54 * V_55 ,
const char * V_56 , T_2 V_14 )
{
struct V_1 * V_2 = F_20 ( V_19 ) ;
struct V_57 * V_58 = F_21 ( V_55 ) ;
bool V_59 ;
int V_8 ;
V_8 = F_22 ( V_56 , & V_59 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( ! V_59 )
return 0 ;
F_23 ( & V_2 -> V_60 ) ;
switch ( ( V_61 ) V_58 -> V_62 ) {
case V_63 :
V_8 = F_18 ( V_2 ) ;
break;
case V_64 :
V_8 = F_16 ( V_2 ) ;
break;
default:
V_8 = - V_65 ;
}
F_24 ( & V_2 -> V_60 ) ;
return V_8 ? V_8 : V_14 ;
}
static T_1 F_25 ( struct V_53 * V_19 ,
struct V_54 * V_55 ,
char * V_56 )
{
struct V_1 * V_2 = F_20 ( V_19 ) ;
struct V_57 * V_58 = F_21 ( V_55 ) ;
int V_8 ;
F_23 ( & V_2 -> V_60 ) ;
V_8 = F_1 ( V_2 , V_66 ) ;
if ( V_8 >= 0 ) {
V_8 = sprintf ( V_56 , L_4 , ! ! ( V_8 & ( 1 <<
( V_61 ) V_58 -> V_62 ) ) ) ;
}
F_24 ( & V_2 -> V_60 ) ;
return V_8 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_67 const * V_68 ,
int * V_20 ,
int * V_69 ,
long V_7 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned V_70 ;
int V_8 ;
F_23 ( & V_2 -> V_60 ) ;
V_8 = F_1 ( V_2 , F_27 ( V_68 -> V_71 ) ) ;
F_24 ( & V_2 -> V_60 ) ;
if ( V_8 < 0 )
return V_8 ;
switch ( V_7 ) {
case V_72 :
* V_20 = ! ( V_8 & V_73 ) ;
return V_74 ;
case V_75 :
* V_20 = V_5 -> V_37 [ V_5 -> V_32 [ V_68 -> V_71 ] ] /
F_28 ( V_8 ) ;
return V_74 ;
case V_76 :
V_70 = ( F_29 ( V_8 ) * 3141592 ) /
F_28 ( V_8 ) ;
* V_20 = V_70 / 1000000 ;
* V_69 = ( V_70 % 1000000 ) * 10 ;
return V_77 ;
default:
return - V_78 ;
}
}
static int F_30 ( struct V_1 * V_2 ,
struct V_67 const * V_68 ,
int V_20 ,
int V_69 ,
long V_26 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned V_79 ;
int V_8 , V_41 , V_70 ;
F_23 ( & V_2 -> V_60 ) ;
V_8 = F_1 ( V_2 , F_27 ( V_68 -> V_71 ) ) ;
if ( V_8 < 0 )
goto V_25;
V_79 = V_8 ;
switch ( V_26 ) {
case V_72 :
if ( V_20 )
V_79 &= ~ V_73 ;
else
V_79 |= V_73 ;
break;
case V_75 :
if ( V_20 <= 0 ) {
V_8 = - V_78 ;
goto V_25;
}
V_8 = F_15 ( V_2 , V_68 -> V_71 , V_20 ) ;
if ( V_8 < 0 )
goto V_25;
V_41 = V_5 -> V_37 [ V_5 -> V_32 [ V_68 -> V_71 ] ] / V_20 ;
V_41 = F_31 ( V_41 , 1 , 1024 ) ;
V_79 &= ~ ( 0x3FF << 8 ) ;
V_79 |= F_32 ( V_41 ) ;
break;
case V_76 :
V_70 = V_20 * 1000000 + V_69 % 1000000 ;
V_41 = ( V_70 * F_28 ( V_8 ) ) / 3141592 ;
V_41 = F_31 ( V_41 , 0 , 63 ) ;
V_79 &= ~ F_33 ( ~ 0 ) ;
V_79 |= F_33 ( V_41 ) ;
break;
default:
V_8 = - V_78 ;
goto V_25;
}
V_8 = F_12 ( V_2 , F_27 ( V_68 -> V_71 ) ,
V_79 ) ;
if ( V_8 < 0 )
goto V_25;
F_13 ( V_2 ) ;
V_25:
F_24 ( & V_2 -> V_60 ) ;
return V_8 ;
}
static int F_34 ( struct V_1 * V_2 ,
unsigned V_79 , unsigned V_80 ,
unsigned * V_81 )
{
int V_8 ;
F_23 ( & V_2 -> V_60 ) ;
if ( V_81 == NULL ) {
V_8 = F_12 ( V_2 , V_79 | V_82 , V_80 ) ;
F_13 ( V_2 ) ;
} else {
V_8 = F_1 ( V_2 , V_79 | V_82 ) ;
if ( V_8 < 0 )
goto V_83;
* V_81 = V_8 ;
V_8 = 0 ;
}
V_83:
F_24 ( & V_2 -> V_60 ) ;
return V_8 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_84 * V_85 = V_5 -> V_85 ;
struct V_86 * V_68 ;
unsigned long V_87 = 0 ;
int V_8 , V_88 ;
V_8 = F_12 ( V_2 , V_89 ,
V_90 |
( V_5 -> V_18 -> V_91 & V_92 ? 0 :
V_93 ) ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_12 ( V_2 , V_94 ,
V_95 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_13 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_12 ( V_2 , V_96 ,
V_85 -> V_97 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_12 ( V_2 , V_98 ,
V_85 -> V_99 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_12 ( V_2 , V_100 ,
V_85 -> V_101 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_12 ( V_2 , V_102 ,
F_36 ( V_85 ->
V_103 ) |
V_104 |
V_105 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_12 ( V_2 , V_106 ,
F_37 ( V_107 , V_108 ) |
F_37 ( V_109 , V_110 ) |
F_37 ( V_111 , V_112 ) |
F_37 ( V_113 ,
V_114 ) |
F_37 ( V_107 , V_115 ) |
F_37 ( V_109 , V_116 ) ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_12 ( V_2 , V_117 ,
F_37 ( V_118 , V_119 ) |
F_37 ( V_120 ,
V_121 ) |
F_37 ( V_122 ,
V_123 ) |
F_37 ( V_124 , V_125 ) |
F_37 ( V_126 , V_127 ) |
F_37 ( V_128 , V_129 ) ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_12 ( V_2 , V_130 ,
V_131 |
F_38 ( V_85 -> V_132 ) ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_12 ( V_2 , V_133 ,
F_39 ( V_85 -> V_134 ) ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_12 ( V_2 , V_135 ,
F_40 ( V_85 ->
V_136 ) ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_12 ( V_2 , V_137 ,
F_41 ( V_85 -> V_138 ) |
F_42 ( V_85 -> V_139 ) ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_12 ( V_2 , V_140 ,
V_141 |
V_142 |
F_37 ( V_143 , V_144 ) ) ;
if ( V_8 < 0 )
return V_8 ;
V_5 -> V_145 = ( V_85 -> V_146 * ( V_85 -> V_143 ? 2 : 1 )
/ V_85 -> V_147 ) * F_43 ( V_85 ->
V_138 , V_85 -> V_139 ) ;
V_8 = F_12 ( V_2 , V_148 ,
V_149 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_12 ( V_2 , V_150 ,
F_44 ( V_85 -> V_151 ) |
F_45 ( V_85 -> V_152 ) |
F_46 ( V_151 , 0 ,
V_153 ) |
F_46 ( V_152 , 0 ,
V_154 ) ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_85 -> V_151 )
V_5 -> V_37 [ V_39 ] =
V_5 -> V_145 / V_85 -> V_151 ;
if ( V_85 -> V_152 )
V_5 -> V_37 [ V_40 ] =
V_5 -> V_145 / V_85 -> V_152 ;
V_5 -> V_37 [ V_38 ] = V_85 -> V_146 ;
V_8 = F_12 ( V_2 , V_155 ,
F_47 ( V_85 -> V_147 ) ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_12 ( V_2 , V_156 ,
F_48 ( V_85 -> V_157 ) |
F_49 ( V_85 -> V_158 ) |
F_50 ( V_85 -> V_159 ) |
F_37 ( V_160 ,
V_161 ) ) ;
if ( V_8 < 0 )
return V_8 ;
for ( V_88 = 0 ; V_88 < V_85 -> V_162 ; V_88 ++ ) {
V_68 = & V_85 -> V_163 [ V_88 ] ;
if ( V_68 -> V_164 < V_165 ) {
F_51 ( V_68 -> V_164 , & V_87 ) ;
V_8 = F_12 ( V_2 ,
F_27 ( V_68 -> V_164 ) ,
F_52 ( V_68 -> V_166 ) |
F_32 ( V_68 -> V_167 ) |
F_33 ( V_68 -> V_168 ) |
( V_68 -> V_169 ?
V_170 : 0 ) |
( V_68 -> V_171 ?
V_172 : 0 ) |
( V_68 -> V_173 ?
V_174 : 0 ) |
( V_68 -> V_175 ?
V_73 : 0 ) ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_14 ( V_2 , V_68 -> V_164 ,
V_68 -> V_176 ) ;
if ( V_8 < 0 )
return V_8 ;
V_5 -> V_177 [ V_88 ] . type = V_178 ;
V_5 -> V_177 [ V_88 ] . V_179 = 1 ;
V_5 -> V_177 [ V_88 ] . V_180 = 1 ;
V_5 -> V_177 [ V_88 ] . V_71 = V_68 -> V_164 ;
V_5 -> V_177 [ V_88 ] . V_181 =
V_68 -> V_182 ;
V_5 -> V_177 [ V_88 ] . V_183 =
V_184 |
V_185 |
V_186 ;
}
}
F_53 (i, &active_mask, AD9523_NUM_CHAN)
F_12 ( V_2 ,
F_27 ( V_88 ) ,
F_52 ( V_187 ) |
V_73 ) ;
V_8 = F_12 ( V_2 , V_188 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_12 ( V_2 , V_51 ,
V_189 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_13 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static int T_3 F_54 ( struct V_190 * V_18 )
{
struct V_84 * V_85 = V_18 -> V_19 . V_191 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
int V_8 ;
if ( ! V_85 ) {
F_10 ( & V_18 -> V_19 , L_5 ) ;
return - V_78 ;
}
V_2 = F_55 ( sizeof( * V_5 ) ) ;
if ( V_2 == NULL )
return - V_192 ;
V_5 = F_2 ( V_2 ) ;
V_5 -> V_79 = F_56 ( & V_18 -> V_19 , L_6 ) ;
if ( ! F_57 ( V_5 -> V_79 ) ) {
V_8 = F_58 ( V_5 -> V_79 ) ;
if ( V_8 )
goto V_193;
}
F_59 ( V_18 , V_2 ) ;
V_5 -> V_18 = V_18 ;
V_5 -> V_85 = V_85 ;
V_2 -> V_19 . V_194 = & V_18 -> V_19 ;
V_2 -> V_195 = ( V_85 -> V_195 [ 0 ] != 0 ) ? V_85 -> V_195 :
F_60 ( V_18 ) -> V_195 ;
V_2 -> V_196 = & V_197 ;
V_2 -> V_198 = V_199 ;
V_2 -> V_163 = V_5 -> V_177 ;
V_2 -> V_162 = V_85 -> V_162 ;
V_8 = F_35 ( V_2 ) ;
if ( V_8 < 0 )
goto V_200;
V_8 = F_61 ( V_2 ) ;
if ( V_8 )
goto V_200;
F_62 ( & V_18 -> V_19 , L_7 , V_2 -> V_195 ) ;
return 0 ;
V_200:
if ( ! F_57 ( V_5 -> V_79 ) )
F_63 ( V_5 -> V_79 ) ;
V_193:
if ( ! F_57 ( V_5 -> V_79 ) )
F_64 ( V_5 -> V_79 ) ;
F_65 ( V_2 ) ;
return V_8 ;
}
static int T_4 F_66 ( struct V_190 * V_18 )
{
struct V_1 * V_2 = F_67 ( V_18 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_68 ( V_2 ) ;
if ( ! F_57 ( V_5 -> V_79 ) ) {
F_63 ( V_5 -> V_79 ) ;
F_64 ( V_5 -> V_79 ) ;
}
F_65 ( V_2 ) ;
return 0 ;
}
