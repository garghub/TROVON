static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
struct V_7 V_8 [] = {
{
. V_9 = & V_5 -> V_10 [ 0 ] . V_11 [ 2 ] ,
. V_12 = 2 ,
} , {
. V_13 = & V_5 -> V_10 [ 1 ] . V_11 [ 4 - F_3 ( V_3 ) ] ,
. V_12 = F_3 ( V_3 ) ,
} ,
} ;
V_5 -> V_10 [ 0 ] . V_14 = F_4 ( V_15 |
F_5 ( F_3 ( V_3 ) ) |
F_6 ( V_3 ) ) ;
V_6 = F_7 ( V_5 -> V_16 , V_8 , F_8 ( V_8 ) ) ;
if ( V_6 < 0 )
F_9 ( & V_2 -> V_17 , L_1 , V_6 ) ;
else
V_6 = F_10 ( V_5 -> V_10 [ 1 ] . V_14 ) & ( 0xFFFFFF >>
( 8 * ( 3 - F_3 ( V_3 ) ) ) ) ;
return V_6 ;
}
static int F_11 ( struct V_1 * V_2 , unsigned V_3 , unsigned V_18 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
struct V_7 V_8 [] = {
{
. V_9 = & V_5 -> V_10 [ 0 ] . V_11 [ 2 ] ,
. V_12 = 2 ,
} , {
. V_9 = & V_5 -> V_10 [ 1 ] . V_11 [ 4 - F_3 ( V_3 ) ] ,
. V_12 = F_3 ( V_3 ) ,
} ,
} ;
V_5 -> V_10 [ 0 ] . V_14 = F_4 ( V_19 |
F_5 ( F_3 ( V_3 ) ) |
F_6 ( V_3 ) ) ;
V_5 -> V_10 [ 1 ] . V_14 = F_4 ( V_18 ) ;
V_6 = F_7 ( V_5 -> V_16 , V_8 , F_8 ( V_8 ) ) ;
if ( V_6 < 0 )
F_9 ( & V_2 -> V_17 , L_2 , V_6 ) ;
return V_6 ;
}
static int F_12 ( struct V_1 * V_2 )
{
return F_11 ( V_2 , V_20 , V_21 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
unsigned V_22 , unsigned V_23 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
unsigned V_24 ;
switch ( V_22 ) {
case 0 ... 3 :
V_6 = F_1 ( V_2 , V_25 ) ;
if ( V_6 < 0 )
break;
V_24 = V_26 << V_22 ;
if ( V_23 ) {
V_6 |= V_24 ;
V_23 = 2 ;
} else {
V_6 &= ~ V_24 ;
}
V_6 = F_11 ( V_2 ,
V_25 , V_6 ) ;
break;
case 4 ... 6 :
V_6 = F_1 ( V_2 , V_27 ) ;
if ( V_6 < 0 )
break;
V_24 = V_28 << ( V_22 - 4 ) ;
if ( V_23 )
V_6 |= V_24 ;
else
V_6 &= ~ V_24 ;
V_6 = F_11 ( V_2 , V_27 , V_6 ) ;
break;
case 7 ... 9 :
V_6 = F_1 ( V_2 , V_25 ) ;
if ( V_6 < 0 )
break;
V_24 = V_29 << ( V_22 - 7 ) ;
if ( V_23 )
V_6 |= V_24 ;
else
V_6 &= ~ V_24 ;
V_6 = F_11 ( V_2 ,
V_25 , V_6 ) ;
break;
default:
return 0 ;
}
V_5 -> V_30 [ V_22 ] = V_23 ;
return V_6 ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned V_22 , unsigned long V_31 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
long V_32 , V_33 ;
bool V_34 ;
switch ( V_22 ) {
case 0 ... 3 :
V_34 = ( V_31 == V_5 -> V_35 [ V_36 ] ) ;
break;
case 4 ... 9 :
V_32 = V_5 -> V_35 [ V_37 ] / V_31 ;
V_33 = V_5 -> V_35 [ V_38 ] / V_31 ;
V_32 *= V_31 ;
V_33 *= V_31 ;
V_34 = ( abs ( V_32 - V_31 ) > abs ( V_33 - V_31 ) ) ;
break;
default:
return 0 ;
}
return F_13 ( V_2 , V_22 , V_34 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_6 , V_39 ;
V_6 = F_11 ( V_2 , V_40 ,
V_41 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , V_42 ,
V_43 ) ;
if ( V_6 < 0 )
return V_6 ;
V_39 = 4 ;
do {
F_16 ( 16 ) ;
V_6 = F_1 ( V_2 ,
V_44 ) ;
if ( V_6 < 0 )
return V_6 ;
} while ( ( V_6 & V_45 ) && V_39 -- );
V_6 = F_11 ( V_2 , V_40 , 0 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_1 ( V_2 , V_46 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_6 & V_47 ) {
F_9 ( & V_2 -> V_17 , L_3 ) ;
V_6 = - V_48 ;
}
return V_6 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_6 , V_39 ;
V_6 = F_1 ( V_2 , V_49 ) ;
if ( V_6 < 0 )
return V_6 ;
V_39 = V_6 ;
V_39 |= V_50 ;
V_6 = F_11 ( V_2 , V_49 , V_39 ) ;
if ( V_6 < 0 )
return V_6 ;
F_12 ( V_2 ) ;
V_39 &= ~ V_50 ;
V_6 = F_11 ( V_2 , V_49 , V_39 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_12 ( V_2 ) ;
}
static T_1 F_18 ( struct V_51 * V_17 ,
struct V_52 * V_53 ,
const char * V_54 , T_2 V_12 )
{
struct V_1 * V_2 = F_19 ( V_17 ) ;
struct V_55 * V_56 = F_20 ( V_53 ) ;
bool V_57 ;
int V_6 ;
V_6 = F_21 ( V_54 , & V_57 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( ! V_57 )
return 0 ;
F_22 ( & V_2 -> V_58 ) ;
switch ( ( V_59 ) V_56 -> V_60 ) {
case V_61 :
V_6 = F_17 ( V_2 ) ;
break;
case V_62 :
V_6 = F_15 ( V_2 ) ;
break;
default:
V_6 = - V_63 ;
}
F_23 ( & V_2 -> V_58 ) ;
return V_6 ? V_6 : V_12 ;
}
static T_1 F_24 ( struct V_51 * V_17 ,
struct V_52 * V_53 ,
char * V_54 )
{
struct V_1 * V_2 = F_19 ( V_17 ) ;
struct V_55 * V_56 = F_20 ( V_53 ) ;
int V_6 ;
F_22 ( & V_2 -> V_58 ) ;
V_6 = F_1 ( V_2 , V_64 ) ;
if ( V_6 >= 0 ) {
V_6 = sprintf ( V_54 , L_4 , ! ! ( V_6 & ( 1 <<
( V_59 ) V_56 -> V_60 ) ) ) ;
}
F_23 ( & V_2 -> V_58 ) ;
return V_6 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_65 const * V_66 ,
int * V_18 ,
int * V_67 ,
long V_68 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned V_69 ;
int V_6 ;
F_22 ( & V_2 -> V_58 ) ;
V_6 = F_1 ( V_2 , F_26 ( V_66 -> V_70 ) ) ;
F_23 ( & V_2 -> V_58 ) ;
if ( V_6 < 0 )
return V_6 ;
switch ( V_68 ) {
case V_71 :
* V_18 = ! ( V_6 & V_72 ) ;
return V_73 ;
case V_74 :
* V_18 = V_5 -> V_35 [ V_5 -> V_30 [ V_66 -> V_70 ] ] /
F_27 ( V_6 ) ;
return V_73 ;
case V_75 :
V_69 = ( F_28 ( V_6 ) * 3141592 ) /
F_27 ( V_6 ) ;
* V_18 = V_69 / 1000000 ;
* V_67 = ( V_69 % 1000000 ) * 10 ;
return V_76 ;
default:
return - V_77 ;
}
}
static int F_29 ( struct V_1 * V_2 ,
struct V_65 const * V_66 ,
int V_18 ,
int V_67 ,
long V_24 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned V_78 ;
int V_6 , V_39 , V_69 ;
F_22 ( & V_2 -> V_58 ) ;
V_6 = F_1 ( V_2 , F_26 ( V_66 -> V_70 ) ) ;
if ( V_6 < 0 )
goto V_23;
V_78 = V_6 ;
switch ( V_24 ) {
case V_71 :
if ( V_18 )
V_78 &= ~ V_72 ;
else
V_78 |= V_72 ;
break;
case V_74 :
if ( V_18 <= 0 ) {
V_6 = - V_77 ;
goto V_23;
}
V_6 = F_14 ( V_2 , V_66 -> V_70 , V_18 ) ;
if ( V_6 < 0 )
goto V_23;
V_39 = V_5 -> V_35 [ V_5 -> V_30 [ V_66 -> V_70 ] ] / V_18 ;
V_39 = F_30 ( V_39 , 1 , 1024 ) ;
V_78 &= ~ ( 0x3FF << 8 ) ;
V_78 |= F_31 ( V_39 ) ;
break;
case V_75 :
V_69 = V_18 * 1000000 + V_67 % 1000000 ;
V_39 = ( V_69 * F_27 ( V_6 ) ) / 3141592 ;
V_39 = F_30 ( V_39 , 0 , 63 ) ;
V_78 &= ~ F_32 ( ~ 0 ) ;
V_78 |= F_32 ( V_39 ) ;
break;
default:
V_6 = - V_77 ;
goto V_23;
}
V_6 = F_11 ( V_2 , F_26 ( V_66 -> V_70 ) ,
V_78 ) ;
if ( V_6 < 0 )
goto V_23;
F_12 ( V_2 ) ;
V_23:
F_23 ( & V_2 -> V_58 ) ;
return V_6 ;
}
static int F_33 ( struct V_1 * V_2 ,
unsigned V_78 , unsigned V_79 ,
unsigned * V_80 )
{
int V_6 ;
F_22 ( & V_2 -> V_58 ) ;
if ( V_80 == NULL ) {
V_6 = F_11 ( V_2 , V_78 | V_81 , V_79 ) ;
F_12 ( V_2 ) ;
} else {
V_6 = F_1 ( V_2 , V_78 | V_81 ) ;
if ( V_6 < 0 )
goto V_82;
* V_80 = V_6 ;
V_6 = 0 ;
}
V_82:
F_23 ( & V_2 -> V_58 ) ;
return V_6 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_83 * V_84 = V_5 -> V_84 ;
struct V_85 * V_66 ;
unsigned long V_86 = 0 ;
int V_6 , V_87 ;
V_6 = F_11 ( V_2 , V_88 ,
V_89 |
( V_5 -> V_16 -> V_90 & V_91 ? 0 :
V_92 ) ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , V_93 ,
V_94 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_12 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , V_95 ,
V_84 -> V_96 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , V_97 ,
V_84 -> V_98 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , V_99 ,
V_84 -> V_100 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , V_101 ,
F_35 ( V_84 ->
V_102 ) |
V_103 |
V_104 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , V_105 ,
F_36 ( V_106 , V_107 ) |
F_36 ( V_108 , V_109 ) |
F_36 ( V_110 , V_111 ) |
F_36 ( V_112 ,
V_113 ) |
F_36 ( V_106 , V_114 ) |
F_36 ( V_108 , V_115 ) ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , V_116 ,
F_36 ( V_117 , V_118 ) |
F_36 ( V_119 ,
V_120 ) |
F_36 ( V_121 ,
V_122 ) |
F_36 ( V_123 , V_124 ) |
F_36 ( V_125 , V_126 ) |
F_36 ( V_127 , V_128 ) ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , V_129 ,
V_130 |
F_37 ( V_84 -> V_131 ) ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , V_132 ,
F_38 ( V_84 -> V_133 ) ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , V_134 ,
F_39 ( V_84 ->
V_135 ) ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , V_136 ,
F_40 ( V_84 -> V_137 ) |
F_41 ( V_84 -> V_138 ) ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , V_139 ,
V_140 |
V_141 |
F_36 ( V_142 , V_143 ) ) ;
if ( V_6 < 0 )
return V_6 ;
V_5 -> V_144 = ( V_84 -> V_145 * ( V_84 -> V_142 ? 2 : 1 )
/ V_84 -> V_146 ) * F_42 ( V_84 ->
V_137 , V_84 -> V_138 ) ;
V_6 = F_11 ( V_2 , V_147 ,
V_148 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , V_149 ,
F_43 ( V_84 -> V_150 ) |
F_44 ( V_84 -> V_151 ) |
F_45 ( V_150 , 0 ,
V_152 ) |
F_45 ( V_151 , 0 ,
V_153 ) ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_84 -> V_150 )
V_5 -> V_35 [ V_37 ] =
V_5 -> V_144 / V_84 -> V_150 ;
if ( V_84 -> V_151 )
V_5 -> V_35 [ V_38 ] =
V_5 -> V_144 / V_84 -> V_151 ;
V_5 -> V_35 [ V_36 ] = V_84 -> V_145 ;
V_6 = F_11 ( V_2 , V_154 ,
F_46 ( V_84 -> V_146 ) ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , V_155 ,
F_47 ( V_84 -> V_156 ) |
F_48 ( V_84 -> V_157 ) |
F_49 ( V_84 -> V_158 ) |
F_36 ( V_159 ,
V_160 ) ) ;
if ( V_6 < 0 )
return V_6 ;
for ( V_87 = 0 ; V_87 < V_84 -> V_161 ; V_87 ++ ) {
V_66 = & V_84 -> V_162 [ V_87 ] ;
if ( V_66 -> V_163 < V_164 ) {
F_50 ( V_66 -> V_163 , & V_86 ) ;
V_6 = F_11 ( V_2 ,
F_26 ( V_66 -> V_163 ) ,
F_51 ( V_66 -> V_165 ) |
F_31 ( V_66 -> V_166 ) |
F_32 ( V_66 -> V_167 ) |
( V_66 -> V_168 ?
V_169 : 0 ) |
( V_66 -> V_170 ?
V_171 : 0 ) |
( V_66 -> V_172 ?
V_173 : 0 ) |
( V_66 -> V_174 ?
V_72 : 0 ) ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_13 ( V_2 , V_66 -> V_163 ,
V_66 -> V_175 ) ;
if ( V_6 < 0 )
return V_6 ;
V_5 -> V_176 [ V_87 ] . type = V_177 ;
V_5 -> V_176 [ V_87 ] . V_178 = 1 ;
V_5 -> V_176 [ V_87 ] . V_179 = 1 ;
V_5 -> V_176 [ V_87 ] . V_70 = V_66 -> V_163 ;
V_5 -> V_176 [ V_87 ] . V_180 =
V_66 -> V_181 ;
V_5 -> V_176 [ V_87 ] . V_182 =
F_52 ( V_71 ) |
F_52 ( V_75 ) |
F_52 ( V_74 ) ;
}
}
F_53 (i, &active_mask, AD9523_NUM_CHAN)
F_11 ( V_2 ,
F_26 ( V_87 ) ,
F_51 ( V_183 ) |
V_72 ) ;
V_6 = F_11 ( V_2 , V_184 , 0 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , V_49 ,
V_185 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_12 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_54 ( struct V_186 * V_16 )
{
struct V_83 * V_84 = V_16 -> V_17 . V_187 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
int V_6 ;
if ( ! V_84 ) {
F_9 ( & V_16 -> V_17 , L_5 ) ;
return - V_77 ;
}
V_2 = F_55 ( & V_16 -> V_17 , sizeof( * V_5 ) ) ;
if ( V_2 == NULL )
return - V_188 ;
V_5 = F_2 ( V_2 ) ;
V_5 -> V_78 = F_56 ( & V_16 -> V_17 , L_6 ) ;
if ( ! F_57 ( V_5 -> V_78 ) ) {
V_6 = F_58 ( V_5 -> V_78 ) ;
if ( V_6 )
return V_6 ;
}
F_59 ( V_16 , V_2 ) ;
V_5 -> V_16 = V_16 ;
V_5 -> V_84 = V_84 ;
V_2 -> V_17 . V_189 = & V_16 -> V_17 ;
V_2 -> V_190 = ( V_84 -> V_190 [ 0 ] != 0 ) ? V_84 -> V_190 :
F_60 ( V_16 ) -> V_190 ;
V_2 -> V_191 = & V_192 ;
V_2 -> V_193 = V_194 ;
V_2 -> V_162 = V_5 -> V_176 ;
V_2 -> V_161 = V_84 -> V_161 ;
V_6 = F_34 ( V_2 ) ;
if ( V_6 < 0 )
goto V_195;
V_6 = F_61 ( V_2 ) ;
if ( V_6 )
goto V_195;
F_62 ( & V_16 -> V_17 , L_7 , V_2 -> V_190 ) ;
return 0 ;
V_195:
if ( ! F_57 ( V_5 -> V_78 ) )
F_63 ( V_5 -> V_78 ) ;
return V_6 ;
}
static int F_64 ( struct V_186 * V_16 )
{
struct V_1 * V_2 = F_65 ( V_16 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_66 ( V_2 ) ;
if ( ! F_57 ( V_5 -> V_78 ) )
F_63 ( V_5 -> V_78 ) ;
return 0 ;
}
