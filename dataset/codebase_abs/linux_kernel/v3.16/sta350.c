static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = V_2 -> V_6 >> 16 ;
V_4 -> type = V_7 ;
V_4 -> V_8 = 3 * V_5 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_2 ) ;
struct V_13 * V_14 = F_4 ( V_12 ) ;
int V_5 = V_2 -> V_6 >> 16 ;
int V_15 = V_2 -> V_6 & 0xffff ;
unsigned int V_16 , V_17 ;
int V_18 , V_19 = 0 ;
F_5 ( & V_14 -> V_20 ) ;
F_6 ( V_14 -> V_21 , V_22 , & V_16 ) ;
V_16 &= 0xf0 ;
F_7 ( V_14 -> V_21 , V_22 , V_16 ) ;
F_7 ( V_14 -> V_21 , V_23 , V_15 ) ;
if ( V_5 == 1 ) {
F_7 ( V_14 -> V_21 , V_22 , V_16 | 0x04 ) ;
} else if ( V_5 == 5 ) {
F_7 ( V_14 -> V_21 , V_22 , V_16 | 0x08 ) ;
} else {
V_19 = - V_24 ;
goto V_25;
}
for ( V_18 = 0 ; V_18 < 3 * V_5 ; V_18 ++ ) {
F_6 ( V_14 -> V_21 , V_26 + V_18 , & V_17 ) ;
V_10 -> V_27 . V_28 . V_29 [ V_18 ] = V_17 ;
}
V_25:
F_8 ( & V_14 -> V_20 ) ;
return V_19 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_2 ) ;
struct V_13 * V_14 = F_4 ( V_12 ) ;
int V_5 = V_2 -> V_6 >> 16 ;
int V_15 = V_2 -> V_6 & 0xffff ;
unsigned int V_16 ;
int V_18 ;
F_6 ( V_14 -> V_21 , V_22 , & V_16 ) ;
V_16 &= 0xf0 ;
F_7 ( V_14 -> V_21 , V_22 , V_16 ) ;
F_7 ( V_14 -> V_21 , V_23 , V_15 ) ;
for ( V_18 = 0 ; V_18 < V_5 && ( V_15 + V_18 < V_30 ) ; V_18 ++ )
V_14 -> V_31 [ V_15 + V_18 ] =
( V_10 -> V_27 . V_28 . V_29 [ 3 * V_18 ] << 16 )
| ( V_10 -> V_27 . V_28 . V_29 [ 3 * V_18 + 1 ] << 8 )
| ( V_10 -> V_27 . V_28 . V_29 [ 3 * V_18 + 2 ] ) ;
for ( V_18 = 0 ; V_18 < 3 * V_5 ; V_18 ++ )
F_7 ( V_14 -> V_21 , V_26 + V_18 ,
V_10 -> V_27 . V_28 . V_29 [ V_18 ] ) ;
if ( V_5 == 1 )
F_7 ( V_14 -> V_21 , V_22 , V_16 | 0x01 ) ;
else if ( V_5 == 5 )
F_7 ( V_14 -> V_21 , V_22 , V_16 | 0x02 ) ;
else
return - V_24 ;
return 0 ;
}
static int F_10 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_4 ( V_12 ) ;
unsigned int V_16 ;
int V_18 ;
F_6 ( V_14 -> V_21 , V_22 , & V_16 ) ;
V_16 &= 0xf0 ;
for ( V_18 = 0 ; V_18 < V_30 ; V_18 ++ ) {
F_7 ( V_14 -> V_21 , V_23 , V_18 ) ;
F_7 ( V_14 -> V_21 , V_26 ,
( V_14 -> V_31 [ V_18 ] >> 16 ) & 0xff ) ;
F_7 ( V_14 -> V_21 , V_32 ,
( V_14 -> V_31 [ V_18 ] >> 8 ) & 0xff ) ;
F_7 ( V_14 -> V_21 , V_33 ,
( V_14 -> V_31 [ V_18 ] ) & 0xff ) ;
F_7 ( V_14 -> V_21 , V_22 , V_16 ) ;
F_7 ( V_14 -> V_21 , V_22 , V_16 | 0x01 ) ;
}
return 0 ;
}
static int F_11 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_4 ( V_12 ) ;
unsigned int V_34 ;
int V_35 ;
F_6 ( V_14 -> V_21 , V_22 , & V_34 ) ;
F_7 ( V_14 -> V_21 , V_36 , V_34 | V_37 ) ;
F_10 ( V_12 ) ;
V_35 = F_12 ( V_14 -> V_21 ) ;
F_7 ( V_14 -> V_21 , V_36 , V_34 ) ;
return V_35 ;
}
static int F_13 ( struct V_38 * V_39 ,
int V_40 , unsigned int V_41 , int V_42 )
{
struct V_11 * V_12 = V_39 -> V_12 ;
struct V_13 * V_14 = F_4 ( V_12 ) ;
F_14 ( V_12 -> V_43 , L_1 , V_41 ) ;
V_14 -> V_44 = V_41 ;
return 0 ;
}
static int F_15 ( struct V_38 * V_39 ,
unsigned int V_45 )
{
struct V_11 * V_12 = V_39 -> V_12 ;
struct V_13 * V_14 = F_4 ( V_12 ) ;
unsigned int V_46 = 0 ;
switch ( V_45 & V_47 ) {
case V_48 :
break;
default:
return - V_24 ;
}
switch ( V_45 & V_49 ) {
case V_50 :
case V_51 :
case V_52 :
V_14 -> V_53 = V_45 & V_49 ;
break;
default:
return - V_24 ;
}
switch ( V_45 & V_54 ) {
case V_55 :
V_46 |= V_56 ;
break;
case V_57 :
V_46 |= V_58 ;
break;
default:
return - V_24 ;
}
return F_16 ( V_14 -> V_21 , V_59 ,
V_58 | V_56 , V_46 ) ;
}
static int F_17 ( struct V_60 * V_61 ,
struct V_62 * V_63 ,
struct V_38 * V_64 )
{
struct V_11 * V_12 = V_64 -> V_12 ;
struct V_13 * V_14 = F_4 ( V_12 ) ;
int V_18 , V_65 = - V_24 , V_66 = - V_24 ;
unsigned int V_67 , V_46 ;
unsigned int V_68 , V_69 ;
int V_19 ;
if ( ! V_14 -> V_44 ) {
F_18 ( V_12 -> V_43 ,
L_2 ) ;
return - V_70 ;
}
V_68 = F_19 ( V_63 ) ;
V_69 = V_14 -> V_44 / V_68 ;
F_14 ( V_12 -> V_43 , L_3 , V_68 , V_69 ) ;
for ( V_18 = 0 ; V_18 < F_20 ( V_71 ) ; V_18 ++ ) {
if ( V_71 [ V_18 ] . V_72 == V_68 ) {
V_66 = V_71 [ V_18 ] . V_66 ;
break;
}
}
if ( V_66 < 0 ) {
F_18 ( V_12 -> V_43 , L_4 , V_68 ) ;
return - V_24 ;
}
for ( V_18 = 0 ; V_18 < 6 ; V_18 ++ ) {
if ( V_73 [ V_66 ] [ V_18 ] == V_69 ) {
V_65 = V_18 ;
break;
}
}
if ( V_65 < 0 ) {
F_18 ( V_12 -> V_43 , L_5 , V_69 ) ;
return - V_24 ;
}
V_67 = ( V_66 << V_74 ) |
( V_65 << V_75 ) ;
V_46 = 0 ;
switch ( F_21 ( V_63 ) ) {
case 24 :
F_14 ( V_12 -> V_43 , L_6 ) ;
case 32 :
F_14 ( V_12 -> V_43 , L_7 ) ;
switch ( V_14 -> V_53 ) {
case V_50 :
V_46 |= 0x0 ;
break;
case V_52 :
V_46 |= 0x1 ;
break;
case V_51 :
V_46 |= 0x2 ;
break;
}
break;
case 20 :
F_14 ( V_12 -> V_43 , L_8 ) ;
switch ( V_14 -> V_53 ) {
case V_50 :
V_46 |= 0x4 ;
break;
case V_52 :
V_46 |= 0x5 ;
break;
case V_51 :
V_46 |= 0x6 ;
break;
}
break;
case 18 :
F_14 ( V_12 -> V_43 , L_9 ) ;
switch ( V_14 -> V_53 ) {
case V_50 :
V_46 |= 0x8 ;
break;
case V_52 :
V_46 |= 0x9 ;
break;
case V_51 :
V_46 |= 0xa ;
break;
}
break;
case 16 :
F_14 ( V_12 -> V_43 , L_10 ) ;
switch ( V_14 -> V_53 ) {
case V_50 :
V_46 |= 0x0 ;
break;
case V_52 :
V_46 |= 0xd ;
break;
case V_51 :
V_46 |= 0xe ;
break;
}
break;
default:
return - V_24 ;
}
V_19 = F_16 ( V_14 -> V_21 , V_76 ,
V_77 | V_78 ,
V_67 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_16 ( V_14 -> V_21 , V_59 ,
V_79 | V_80 ,
V_46 ) ;
if ( V_19 < 0 )
return V_19 ;
return 0 ;
}
static int F_22 ( struct V_13 * V_14 )
{
if ( V_14 -> V_81 )
F_23 ( V_14 -> V_81 , 1 ) ;
if ( V_14 -> V_82 ) {
F_23 ( V_14 -> V_82 , 0 ) ;
F_24 ( 1 ) ;
F_23 ( V_14 -> V_82 , 1 ) ;
F_24 ( 1 ) ;
}
return 0 ;
}
static int F_25 ( struct V_11 * V_12 ,
enum V_83 V_84 )
{
struct V_13 * V_14 = F_4 ( V_12 ) ;
int V_19 ;
F_14 ( V_12 -> V_43 , L_11 , V_84 ) ;
switch ( V_84 ) {
case V_85 :
break;
case V_86 :
F_16 ( V_14 -> V_21 , V_87 ,
V_88 | V_89 ,
V_88 | V_89 ) ;
break;
case V_90 :
if ( V_12 -> V_91 . V_92 == V_93 ) {
V_19 = F_26 (
F_20 ( V_14 -> V_94 ) ,
V_14 -> V_94 ) ;
if ( V_19 < 0 ) {
F_18 ( V_12 -> V_43 ,
L_12 ,
V_19 ) ;
return V_19 ;
}
F_22 ( V_14 ) ;
F_11 ( V_12 ) ;
}
F_16 ( V_14 -> V_21 , V_87 ,
V_88 | V_89 ,
0 ) ;
break;
case V_93 :
F_16 ( V_14 -> V_21 , V_87 ,
V_88 | V_89 , 0 ) ;
if ( V_14 -> V_81 )
F_23 ( V_14 -> V_81 , 0 ) ;
if ( V_14 -> V_82 )
F_23 ( V_14 -> V_82 , 0 ) ;
F_27 ( F_20 ( V_14 -> V_94 ) ,
V_14 -> V_94 ) ;
break;
}
V_12 -> V_91 . V_92 = V_84 ;
return 0 ;
}
static int F_28 ( struct V_11 * V_12 )
{
F_25 ( V_12 , V_93 ) ;
return 0 ;
}
static int F_29 ( struct V_11 * V_12 )
{
F_25 ( V_12 , V_90 ) ;
return 0 ;
}
static int F_30 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_4 ( V_12 ) ;
struct V_95 * V_96 = V_14 -> V_96 ;
int V_18 , V_19 = 0 , V_97 = 0 ;
V_19 = F_26 ( F_20 ( V_14 -> V_94 ) ,
V_14 -> V_94 ) ;
if ( V_19 < 0 ) {
F_18 ( V_12 -> V_43 , L_12 , V_19 ) ;
return V_19 ;
}
V_19 = F_22 ( V_14 ) ;
if ( V_19 < 0 ) {
F_18 ( V_12 -> V_43 , L_13 ) ;
return V_19 ;
}
if ( ! V_96 -> V_98 )
V_97 |= V_99 ;
if ( ! V_96 -> V_100 )
V_97 |= V_101 ;
if ( ! V_96 -> V_102 )
V_97 |= V_103 ;
F_16 ( V_14 -> V_21 , V_76 ,
V_99 | V_101 |
V_103 ,
V_97 ) ;
F_16 ( V_14 -> V_21 , V_104 ,
V_105 ,
V_96 -> V_106
<< V_107 ) ;
F_16 ( V_14 -> V_21 , V_104 ,
V_108 ,
V_96 -> V_109
<< V_110 ) ;
F_16 ( V_14 -> V_21 ,
V_104 ,
V_111 ,
V_96 -> V_112 ?
V_111 : 0 ) ;
F_16 ( V_14 -> V_21 , V_113 ,
V_114 ,
V_96 -> V_115 ?
V_114 : 0 ) ;
F_16 ( V_14 -> V_21 , V_113 ,
V_116 ,
V_96 -> V_117 ?
V_116 : 0 ) ;
F_16 ( V_14 -> V_21 , V_113 ,
V_118 ,
V_96 -> V_119 ?
V_118 : 0 ) ;
F_16 ( V_14 -> V_21 , V_113 ,
V_120 ,
V_96 -> V_121 ?
V_120 : 0 ) ;
F_16 ( V_14 -> V_21 , V_113 ,
V_122 ,
V_96 -> V_123 ?
V_122 : 0 ) ;
F_16 ( V_14 -> V_21 , V_87 ,
V_124 ,
V_96 -> V_125 ?
V_124 : 0 ) ;
F_16 ( V_14 -> V_21 , V_87 ,
V_126 ,
V_96 -> V_127
<< V_128 ) ;
F_16 ( V_14 -> V_21 , V_129 ,
V_130 ,
V_96 -> V_131
<< V_132 ) ;
F_16 ( V_14 -> V_21 , V_133 ,
V_130 ,
V_96 -> V_134
<< V_132 ) ;
F_16 ( V_14 -> V_21 , V_135 ,
V_130 ,
V_96 -> V_136
<< V_132 ) ;
F_16 ( V_14 -> V_21 , V_137 ,
V_138 ,
V_96 -> V_139 ?
V_138 : 0 ) ;
F_16 ( V_14 -> V_21 , V_137 ,
V_140 ,
V_96 -> V_141 ?
V_140 : 0 ) ;
F_16 ( V_14 -> V_21 , V_137 ,
V_142 ,
V_96 -> V_143 ?
V_142 : 0 ) ;
F_16 ( V_14 -> V_21 , V_137 ,
V_144 ,
V_96 -> V_145 ?
V_144 : 0 ) ;
F_16 ( V_14 -> V_21 , V_146 ,
V_147 ,
V_96 -> V_148
<< V_149 ) ;
for ( V_18 = 4 ; V_18 <= 49 ; V_18 += 5 )
V_14 -> V_31 [ V_18 ] = 0x400000 ;
for ( V_18 = 50 ; V_18 <= 54 ; V_18 ++ )
V_14 -> V_31 [ V_18 ] = 0x7fffff ;
V_14 -> V_31 [ 55 ] = 0x5a9df7 ;
V_14 -> V_31 [ 56 ] = 0x7fffff ;
V_14 -> V_31 [ 59 ] = 0x7fffff ;
V_14 -> V_31 [ 60 ] = 0x400000 ;
V_14 -> V_31 [ 61 ] = 0x400000 ;
F_25 ( V_12 , V_90 ) ;
F_27 ( F_20 ( V_14 -> V_94 ) , V_14 -> V_94 ) ;
return 0 ;
}
static int F_31 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_4 ( V_12 ) ;
F_25 ( V_12 , V_93 ) ;
F_27 ( F_20 ( V_14 -> V_94 ) , V_14 -> V_94 ) ;
return 0 ;
}
static int F_32 ( struct V_150 * V_43 , struct V_13 * V_14 )
{
struct V_151 * V_152 = V_43 -> V_153 ;
struct V_95 * V_96 ;
const char * V_154 ;
T_1 V_155 ;
T_2 V_156 ;
V_96 = F_33 ( V_43 , sizeof( * V_96 ) , V_157 ) ;
if ( ! V_96 )
return - V_158 ;
F_34 ( V_152 , L_14 ,
& V_96 -> V_127 ) ;
F_34 ( V_152 , L_15 ,
& V_96 -> V_131 ) ;
F_34 ( V_152 , L_16 ,
& V_96 -> V_134 ) ;
F_34 ( V_152 , L_17 ,
& V_96 -> V_136 ) ;
if ( F_35 ( V_152 , L_18 , NULL ) )
V_96 -> V_98 = 1 ;
if ( F_35 ( V_152 , L_19 , NULL ) )
V_96 -> V_100 = 1 ;
if ( F_35 ( V_152 , L_20 , NULL ) )
V_96 -> V_102 = 1 ;
V_96 -> V_106 = V_159 ;
if ( ! F_36 ( V_152 , L_21 ,
& V_154 ) ) {
int V_18 , V_160 = - V_24 ;
for ( V_18 = 0 ; V_18 < F_20 ( V_161 ) ; V_18 ++ )
if ( ! strcasecmp ( V_154 , V_161 [ V_18 ] ) )
V_160 = V_18 ;
if ( V_160 < 0 )
F_37 ( V_43 , L_22 ,
V_154 ) ;
else
V_96 -> V_106 = V_160 ;
}
V_155 = 140 ;
F_38 ( V_152 , L_23 , & V_155 ) ;
V_96 -> V_109 = F_39 ( T_1 , V_155 , 0 , 300 ) / 20 ;
if ( F_35 ( V_152 , L_24 , NULL ) )
V_96 -> V_112 = 1 ;
if ( F_35 ( V_152 , L_25 , NULL ) )
V_96 -> V_115 = 1 ;
if ( F_35 ( V_152 , L_26 , NULL ) )
V_96 -> V_117 = 1 ;
if ( F_35 ( V_152 , L_27 , NULL ) )
V_96 -> V_119 = 1 ;
if ( F_35 ( V_152 , L_28 , NULL ) )
V_96 -> V_121 = 1 ;
if ( F_35 ( V_152 , L_29 , NULL ) )
V_96 -> V_123 = 1 ;
if ( F_35 ( V_152 , L_30 , NULL ) )
V_96 -> V_125 = 1 ;
if ( F_35 ( V_152 , L_31 , NULL ) )
V_96 -> V_139 = 1 ;
if ( F_35 ( V_152 , L_32 , NULL ) )
V_96 -> V_141 = 1 ;
if ( F_35 ( V_152 , L_33 , NULL ) )
V_96 -> V_143 = 1 ;
if ( F_35 ( V_152 , L_34 , NULL ) )
V_96 -> V_145 = 1 ;
if ( ! F_34 ( V_152 , L_35 , & V_156 ) ) {
if ( F_40 ( V_156 ) && V_156 >= 1 && V_156 <= 128 )
V_96 -> V_148 = F_41 ( V_156 ) ;
else
F_37 ( V_43 , L_36 ,
V_156 ) ;
}
V_14 -> V_96 = V_96 ;
return 0 ;
}
static int F_42 ( struct V_162 * V_163 ,
const struct V_164 * V_165 )
{
struct V_150 * V_43 = & V_163 -> V_43 ;
struct V_13 * V_14 ;
int V_19 , V_18 ;
V_14 = F_33 ( V_43 , sizeof( struct V_13 ) , V_157 ) ;
if ( ! V_14 )
return - V_158 ;
F_43 ( & V_14 -> V_20 ) ;
V_14 -> V_96 = F_44 ( V_43 ) ;
#ifdef F_45
if ( V_43 -> V_153 ) {
V_19 = F_32 ( V_43 , V_14 ) ;
if ( V_19 < 0 )
return V_19 ;
}
#endif
V_14 -> V_82 = F_46 ( V_43 , L_37 ) ;
if ( F_47 ( V_14 -> V_82 ) ) {
V_19 = F_48 ( V_14 -> V_82 ) ;
if ( V_19 != - V_166 && V_19 != - V_167 )
return V_19 ;
V_14 -> V_82 = NULL ;
} else {
F_49 ( V_14 -> V_82 , 0 ) ;
}
V_14 -> V_81 = F_46 ( V_43 , L_38 ) ;
if ( F_47 ( V_14 -> V_81 ) ) {
V_19 = F_48 ( V_14 -> V_81 ) ;
if ( V_19 != - V_166 && V_19 != - V_167 )
return V_19 ;
V_14 -> V_81 = NULL ;
} else {
F_49 ( V_14 -> V_81 , 0 ) ;
}
for ( V_18 = 0 ; V_18 < F_20 ( V_14 -> V_94 ) ; V_18 ++ )
V_14 -> V_94 [ V_18 ] . V_168 = V_169 [ V_18 ] ;
V_19 = F_50 ( V_43 , F_20 ( V_14 -> V_94 ) ,
V_14 -> V_94 ) ;
if ( V_19 < 0 ) {
F_18 ( V_43 , L_39 , V_19 ) ;
return V_19 ;
}
V_14 -> V_21 = F_51 ( V_163 , & V_170 ) ;
if ( F_47 ( V_14 -> V_21 ) ) {
V_19 = F_48 ( V_14 -> V_21 ) ;
F_18 ( V_43 , L_40 , V_19 ) ;
return V_19 ;
}
F_52 ( V_163 , V_14 ) ;
V_19 = F_53 ( V_43 , & V_171 , & V_172 , 1 ) ;
if ( V_19 < 0 )
F_18 ( V_43 , L_41 , V_19 ) ;
return V_19 ;
}
static int F_54 ( struct V_162 * V_173 )
{
F_55 ( & V_173 -> V_43 ) ;
return 0 ;
}
