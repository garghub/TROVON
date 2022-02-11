static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_2 , V_5 ,
V_6 |
V_7 ,
V_8
| V_9 ) ;
if ( V_4 -> V_10 ) {
F_4 ( V_2 , V_11 ,
F_5 ( V_4 -> V_10 ) ) ;
if ( V_4 -> V_10 >= 2700 )
F_6 ( 50 ) ;
}
F_3 ( V_2 , V_5 ,
V_6 |
V_7 , 0 ) ;
}
static int F_7 ( struct V_1
* V_2 , int V_12 ,
int V_13 , unsigned int V_14 )
{
switch ( V_12 ) {
case V_15 :
F_1 ( V_2 ) ;
F_3 ( V_2 , V_16 ,
V_17 , V_14 ) ;
break;
}
return 0 ;
}
static int F_8 ( struct V_1
* V_2 , int V_12 ,
int V_13 , T_1 V_14 )
{
switch ( V_12 ) {
case V_18 :
F_3 ( V_2 , V_19 ,
V_20 ,
V_21 ) ;
F_3 ( V_2 , V_13 , V_22 , 0 ) ;
F_3 ( V_2 , V_16 ,
V_23 ,
V_24 ) ;
break;
case V_15 :
F_1 ( V_2 ) ;
F_3 ( V_2 , V_16 ,
V_17 , V_14 ) ;
break;
}
return 0 ;
}
static int F_9 ( struct
V_25
* V_26 , struct V_27
* V_28 , int V_12 )
{
struct V_1 * V_2 = F_10 ( V_26 -> V_29 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_7 ( V_2 , V_12 , V_26 -> V_13 ,
V_4 -> V_30 ) ;
}
static int F_11 ( struct
V_25
* V_26 , struct V_27
* V_28 , int V_12 )
{
struct V_1 * V_2 = F_10 ( V_26 -> V_29 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_7 ( V_2 , V_12 , V_26 -> V_13 ,
V_4 -> V_31 ) ;
}
static int F_12 ( struct
V_25
* V_26 , struct V_27
* V_28 , int V_12 )
{
struct V_1 * V_2 = F_10 ( V_26 -> V_29 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_8 ( V_2 , V_12 , V_26 -> V_13 ,
V_4 -> V_30 ) ;
}
static void F_13 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_1 V_32 = 0 ;
T_1 V_33 ;
F_4 ( V_2 , V_34 ,
V_35 |
V_36 |
V_37 |
V_38 ) ;
if ( V_4 -> V_39 )
V_32 |= V_40 ;
if ( V_4 -> V_41 )
V_32 |= V_42 ;
F_4 ( V_2 , V_43 ,
V_44 |
V_45 |
V_32 |
V_46 ) ;
F_4 ( V_2 , V_47 ,
V_48 |
V_49 ) ;
F_3 ( V_2 , V_50 ,
V_51 ,
V_52 ) ;
V_33 = V_53 ;
if ( V_4 -> V_54 )
V_33 |= V_55 | V_56 ;
F_3 ( V_2 , V_57 , V_33 , 0 ) ;
F_3 ( V_2 , V_58 , V_33 , V_33 ) ;
V_4 -> V_59 = false ;
V_4 -> V_60 = true ;
}
static int F_14 ( struct V_3 * V_61 ,
bool V_62 )
{
struct V_1 * V_2 = V_61 -> V_2 ;
T_1 V_63 , V_64 , V_65 , V_66 ;
int * V_67 , V_68 ;
if ( ! V_62 ) {
F_3 ( V_2 , V_19 ,
V_20 ,
V_21 ) ;
F_3 ( V_2 , V_69 ,
V_70 ,
0 ) ;
F_3 ( V_2 , V_71 ,
V_72 ,
V_73 ) ;
}
F_3 ( V_2 , V_71 ,
V_74 ,
V_75 ) ;
if ( V_62 )
V_67 = & V_61 -> V_76 [ 0 ] ;
else
V_67 = & V_61 -> V_77 [ 0 ] ;
V_66 = V_78 ;
for ( V_68 = 0 ; V_68 < V_79 ; V_68 ++ ) {
V_63 = ( V_67 [ V_68 ] / 100 ) ;
V_64 = ( ( V_67 [ V_68 ] % 100 ) / 12 ) ;
V_65 = ( V_63 << V_80 ) |
( V_64 << V_81 ) ;
F_3 ( V_2 , V_66 ,
V_82 ,
V_65 ) ;
V_66 ++ ;
}
return 0 ;
}
static int F_15 ( struct
V_25
* V_26 , struct V_27
* V_28 , int V_12 )
{
struct V_1 * V_2 = F_10 ( V_26 -> V_29 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_12 ) {
case V_15 :
F_14 ( V_4 , true ) ;
break;
case V_83 :
F_14 ( V_4 , false ) ;
break;
}
return F_8 ( V_2 , V_12 , V_26 -> V_13 ,
V_4 -> V_31 ) ;
}
static int F_16 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
int V_12 )
{
struct V_1 * V_2 = F_10 ( V_26 -> V_29 ) ;
T_2 V_84 = V_85 ;
T_3 V_86 ;
if ( V_26 -> V_13 == V_87 )
V_86 = 5 ;
else
V_86 = 4 ;
switch ( V_12 ) {
case V_18 :
if ( V_26 -> V_13 == V_88 )
F_3 ( V_2 , V_5 ,
V_89 ,
V_90 ) ;
F_17 ( 10000 , 10010 ) ;
F_3 ( V_2 , V_84 , 1 << V_86 ,
1 << V_86 ) ;
switch ( V_26 -> V_13 ) {
case V_87 :
F_3 ( V_2 , V_91 ,
V_92 ,
V_93 ) ;
break;
case V_88 :
case V_94 :
F_3 ( V_2 , V_95 ,
V_96 ,
V_97 ) ;
break;
}
break;
case V_15 :
F_17 ( 12000 , 12010 ) ;
F_3 ( V_2 , V_84 , 1 << V_86 , 0x00 ) ;
break;
case V_83 :
switch ( V_26 -> V_13 ) {
case V_87 :
F_3 ( V_2 , V_91 ,
V_92 ,
V_98 ) ;
break;
case V_88 :
F_3 ( V_2 , V_5 ,
V_89 , 0 ) ;
case V_94 :
F_3 ( V_2 , V_95 ,
V_96 ,
V_99 ) ;
break;
}
break;
}
return 0 ;
}
static int F_18 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
int V_12 )
{
struct V_1 * V_2 = F_10 ( V_26 -> V_29 ) ;
switch ( V_12 ) {
case V_18 :
F_3 ( V_2 , V_100 ,
V_101 |
V_102 |
V_103 |
V_104 ,
V_105 |
V_106 |
V_107 |
V_108 ) ;
F_3 ( V_2 , V_109 ,
V_110 ,
V_111 ) ;
break;
case V_15 :
F_3 ( V_2 , V_112 ,
V_113 ,
V_114 ) ;
F_3 ( V_2 , V_26 -> V_13 ,
V_115 ,
V_116 ) ;
break;
case V_83 :
F_3 ( V_2 , V_100 ,
V_101 |
V_102 |
V_103 |
V_104 , 0 ) ;
F_3 ( V_2 , V_117 ,
V_118 ,
V_119 ) ;
F_3 ( V_2 , V_109 ,
V_110 , 0 ) ;
break;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_61 = F_20 ( V_2 -> V_120 ) ;
int V_121 , V_13 ;
V_121 = F_21 ( F_22 ( V_61 -> V_122 ) , V_61 -> V_122 ) ;
if ( V_121 != 0 ) {
F_23 ( V_2 -> V_120 , L_1 , V_121 ) ;
return V_121 ;
}
F_24 ( V_2 , V_61 ) ;
V_61 -> V_123 = F_25 ( V_2 , V_124 ) ;
V_61 -> V_125 = F_25 ( V_2 , V_126 ) ;
F_26 ( V_2 -> V_120 , L_2 ,
V_61 -> V_123 , V_61 -> V_125 ) ;
F_4 ( V_2 , V_127 , 0x01 ) ;
F_4 ( V_2 , V_128 , 0x01 ) ;
for ( V_13 = 0 ; V_13 < F_22 ( V_129 ) ; V_13 ++ )
F_4 ( V_2 , V_129 [ V_13 ] . V_13 ,
V_129 [ V_13 ] . V_130 ) ;
V_61 -> V_2 = V_2 ;
F_3 ( V_2 , V_131 ,
V_132 ,
V_133 ) ;
F_13 ( V_61 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_61 = F_20 ( V_2 -> V_120 ) ;
F_3 ( V_2 , V_131 ,
V_132 , 0 ) ;
return F_28 ( F_22 ( V_61 -> V_122 ) ,
V_61 -> V_122 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_134 * V_135 ,
void * V_136 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_135 = V_135 ;
return 0 ;
}
static struct V_137 * F_30 ( struct V_138 * V_120 )
{
return F_31 ( V_120 -> V_139 , NULL ) ;
}
static T_4 F_32 ( int V_140 , void * V_141 )
{
struct V_3 * V_61 = V_141 ;
if ( V_61 -> V_60 ) {
struct V_1 * V_2 = V_61 -> V_2 ;
T_1 V_142 = F_25 ( V_2 , V_143 ) ;
if ( ( V_142 != - 1 ) && ! ( V_142 & V_144 ) )
V_61 -> V_59 = false ;
} else {
F_33 ( V_61 -> V_135 , 0 , V_145 ) ;
}
return V_146 ;
}
static T_4 F_34 ( int V_140 , void * V_141 )
{
struct V_3 * V_61 = V_141 ;
struct V_1 * V_2 = V_61 -> V_2 ;
T_1 V_147 ;
V_147 = F_25 ( V_2 , V_143 ) &
V_144 ;
switch ( V_147 ) {
case 0xf :
F_33 ( V_61 -> V_135 , V_148 , V_145 ) ;
break;
case 0x7 :
F_33 ( V_61 -> V_135 , V_149 , V_145 ) ;
break;
case 0x3 :
F_33 ( V_61 -> V_135 , V_150 , V_145 ) ;
break;
case 0x1 :
F_33 ( V_61 -> V_135 , V_151 , V_145 ) ;
break;
case 0x0 :
if ( V_61 -> V_60 )
V_61 -> V_59 = true ;
else
F_33 ( V_61 -> V_135 ,
V_152 , V_145 ) ;
break;
default:
F_23 ( V_2 -> V_120 ,
L_3 , V_147 ) ;
break;
}
return V_146 ;
}
static T_4 F_35 ( int V_140 , void * V_141 )
{
struct V_3 * V_61 = V_141 ;
struct V_1 * V_2 = V_61 -> V_2 ;
bool V_153 = false ;
if ( F_25 ( V_2 , V_34 ) &
V_154 )
V_153 = true ;
F_3 ( V_2 , V_34 ,
V_154 ,
( ! V_153 << V_155 ) ) ;
if ( V_153 ) {
bool V_156 = false ;
if ( F_25 ( V_2 , V_69 ) &
V_157 )
V_156 = true ;
F_14 ( V_61 , V_156 ) ;
if ( V_61 -> V_59 )
F_33 ( V_61 -> V_135 ,
V_158 , V_159 ) ;
else
F_33 ( V_61 -> V_135 ,
V_160 , V_159 ) ;
V_61 -> V_60 = false ;
} else {
F_33 ( V_61 -> V_135 , 0 , V_159 ) ;
V_61 -> V_60 = true ;
V_61 -> V_59 = false ;
}
return V_146 ;
}
static int F_36 ( struct V_138 * V_120 ,
struct V_3 * V_61 )
{
int V_161 ;
if ( F_37 ( V_120 -> V_162 , L_4 ) )
V_61 -> V_30 = V_163 ;
else
V_61 -> V_30 = V_164 ;
if ( F_37 ( V_120 -> V_162 , L_5 ) )
V_61 -> V_31 = V_163 ;
else
V_61 -> V_31 = V_164 ;
F_38 ( V_120 -> V_162 , L_6 ,
& V_61 -> V_10 ) ;
if ( F_37 ( V_120 -> V_162 ,
L_7 ) )
V_61 -> V_39 = true ;
else
V_61 -> V_39 = false ;
if ( F_37 ( V_120 -> V_162 ,
L_8 ) )
V_61 -> V_41 = true ;
else
V_61 -> V_41 = false ;
V_61 -> V_54 = true ;
V_161 = F_39 ( V_120 -> V_162 ,
L_9 ,
& V_61 -> V_77 [ 0 ] ,
V_79 ) ;
if ( V_161 < 0 ) {
V_61 -> V_54 = false ;
} else {
V_161 = F_39 ( V_120 -> V_162 ,
L_10 ,
& V_61 -> V_76 [ 0 ] ,
V_79 ) ;
if ( V_161 < 0 )
V_61 -> V_54 = false ;
}
if ( ! V_61 -> V_54 )
F_23 ( V_120 ,
L_11 ) ;
return 0 ;
}
static int F_40 ( struct V_165 * V_166 )
{
struct V_3 * V_61 ;
struct V_138 * V_120 = & V_166 -> V_120 ;
int V_167 , V_68 , V_140 ;
V_61 = F_41 ( V_120 , sizeof( * V_61 ) , V_168 ) ;
if ( ! V_61 )
return - V_169 ;
V_167 = F_36 ( V_120 , V_61 ) ;
if ( V_167 < 0 )
return V_167 ;
V_61 -> V_170 = F_42 ( V_120 , L_12 ) ;
if ( F_43 ( V_61 -> V_170 ) ) {
F_23 ( V_120 , L_13 ) ;
return F_44 ( V_61 -> V_170 ) ;
}
for ( V_68 = 0 ; V_68 < F_22 ( V_171 ) ; V_68 ++ )
V_61 -> V_122 [ V_68 ] . V_172 = V_171 [ V_68 ] ;
V_167 = F_45 ( V_120 , F_22 ( V_61 -> V_122 ) ,
V_61 -> V_122 ) ;
if ( V_167 ) {
F_23 ( V_120 , L_14 , V_167 ) ;
return V_167 ;
}
V_167 = F_46 ( V_61 -> V_170 ) ;
if ( V_167 < 0 ) {
F_23 ( V_120 , L_15 , V_167 ) ;
return V_167 ;
}
V_140 = F_47 ( V_166 , L_16 ) ;
if ( V_140 < 0 ) {
F_23 ( V_120 , L_17 ) ;
return V_140 ;
}
V_167 = F_48 ( V_120 , V_140 , F_35 ,
V_173 | V_174 |
V_175 ,
L_18 , V_61 ) ;
if ( V_167 )
F_23 ( V_120 , L_19 ) ;
if ( V_61 -> V_54 ) {
V_140 = F_47 ( V_166 , L_20 ) ;
if ( V_140 < 0 ) {
F_23 ( V_120 , L_21 ) ;
return V_140 ;
}
V_167 = F_48 ( V_120 , V_140 , F_34 ,
V_173 |
V_174 | V_175 ,
L_22 , V_61 ) ;
if ( V_167 )
F_23 ( V_120 , L_23 ) ;
V_140 = F_47 ( V_166 , L_24 ) ;
if ( V_140 < 0 ) {
F_23 ( V_120 , L_25 ) ;
return V_140 ;
}
V_167 = F_48 ( V_120 , V_140 , F_32 ,
V_173 |
V_174 | V_175 ,
L_26 , V_61 ) ;
if ( V_167 )
F_23 ( V_120 , L_27 ) ;
}
F_49 ( V_120 , V_61 ) ;
return F_50 ( V_120 , & V_176 ,
V_177 ,
F_22 ( V_177 ) ) ;
}
static int F_51 ( struct V_165 * V_166 )
{
struct V_3 * V_61 = F_20 ( & V_166 -> V_120 ) ;
F_52 ( & V_166 -> V_120 ) ;
F_53 ( V_61 -> V_170 ) ;
return 0 ;
}
