static int F_1 ( struct V_1 * V_1 , T_1 V_2 , T_2 V_3 , T_2 * V_4 )
{
struct V_5 * V_6 = F_2 ( & V_1 -> V_7 ) ;
struct V_8 V_9 [ 2 ] ;
T_3 * V_10 ;
int V_11 ;
T_2 V_12 = 0 ;
T_1 V_13 = F_3 ( V_2 ) ;
if ( V_3 > 4 )
return - V_14 ;
V_10 = ( T_3 * ) & V_12 ;
V_9 [ 0 ] . V_15 = V_6 -> V_15 ;
V_9 [ 0 ] . V_16 = 0 ;
V_9 [ 0 ] . V_3 = 2 ;
V_9 [ 0 ] . V_17 = ( T_3 * ) & V_13 ;
V_9 [ 1 ] . V_15 = V_6 -> V_15 ;
V_9 [ 1 ] . V_16 = V_18 ;
V_9 [ 1 ] . V_3 = V_3 ;
V_9 [ 1 ] . V_17 = & V_10 [ 4 - V_3 ] ;
V_11 = F_4 ( V_6 -> V_19 , V_9 , F_5 ( V_9 ) ) ;
if ( V_11 != F_5 ( V_9 ) )
return - V_20 ;
* V_4 = F_6 ( V_12 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_1 , T_1 V_2 , T_2 V_3 , T_2 V_4 )
{
struct V_5 * V_6 = F_2 ( & V_1 -> V_7 ) ;
int V_21 , V_22 ;
T_3 V_17 [ 6 ] , * V_23 ;
if ( V_3 > 4 )
return - V_14 ;
V_17 [ 0 ] = V_2 >> 8 ;
V_17 [ 1 ] = V_2 & 0xff ;
V_4 = F_8 ( V_4 ) ;
V_23 = ( T_3 * ) & V_4 ;
V_21 = 2 ;
V_22 = 4 - V_3 ;
while ( V_22 < 4 )
V_17 [ V_21 ++ ] = V_23 [ V_22 ++ ] ;
if ( F_9 ( V_6 , V_17 , V_3 + 2 ) != V_3 + 2 )
return - V_20 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_1 ,
const struct V_24 * V_25 , T_2 V_3 )
{
struct V_5 * V_6 = F_2 ( & V_1 -> V_7 ) ;
int V_11 ;
T_2 V_26 ;
for ( V_26 = 0 ; V_26 < V_3 ; V_26 ++ ) {
V_11 = F_7 ( V_1 , V_25 [ V_26 ] . V_27 , 1 ,
V_25 [ V_26 ] . V_4 ) ;
if ( V_11 ) {
F_11 (
& V_6 -> V_28 ,
L_1 ,
V_25 [ V_26 ] . V_27 , V_11 ) ;
return V_11 ;
}
}
return 0 ;
}
static int F_12 ( struct V_1 * V_1 ,
const struct V_29 * V_30 )
{
return F_10 ( V_1 , V_30 -> V_25 , V_30 -> V_31 ) ;
}
static int F_13 ( struct V_32 * V_7 , struct V_33 * V_34 )
{
struct V_1 * V_1 = F_14 ( V_7 ) ;
struct V_35 * V_36 = F_15 ( V_7 ,
V_34 -> V_37 ,
0 ) ;
F_16 ( & V_1 -> V_38 ) ;
V_36 -> V_39 = V_1 -> V_40 -> V_39 ;
V_36 -> V_41 = V_1 -> V_40 -> V_41 ;
V_36 -> V_42 = V_43 ;
V_36 -> V_44 = V_45 ;
F_17 ( & V_1 -> V_38 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_1 , T_2 V_46 )
{
int V_11 ;
V_11 = F_7 ( V_1 , V_47 ,
V_48 , V_46 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_7 ( V_1 , V_49 ,
V_48 , V_46 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_7 ( V_1 , V_50 ,
V_48 , V_46 ) ;
return V_11 ;
}
static int F_19 ( struct V_1 * V_1 , T_2 V_51 )
{
int V_11 ;
T_2 V_4 ;
V_11 = F_1 ( V_1 , V_52 ,
V_53 , & V_4 ) ;
if ( V_11 )
return V_11 ;
if ( V_51 ) {
V_4 &= V_54 ;
V_4 |= ( V_51 - 1 ) | V_55 ;
} else {
V_4 &= ~ V_55 ;
}
return F_7 ( V_1 , V_52 ,
V_53 , V_4 ) ;
}
static int F_20 ( struct V_56 * V_57 )
{
struct V_1 * V_1 = F_21 ( V_57 -> V_58 ,
struct V_1 , V_59 ) ;
struct V_5 * V_6 = F_2 ( & V_1 -> V_7 ) ;
T_4 V_60 ;
int V_11 ;
switch ( V_57 -> V_61 ) {
case V_62 :
V_60 = V_1 -> V_40 -> V_41 + V_57 -> V_4 - 8 ;
F_22 ( V_1 -> V_63 ,
V_1 -> V_63 -> V_64 ,
V_60 , V_1 -> V_63 -> V_65 , V_60 ) ;
break;
} ;
if ( F_23 ( & V_6 -> V_28 ) <= 0 )
return 0 ;
V_11 = 0 ;
switch ( V_57 -> V_61 ) {
case V_66 :
V_11 = F_7 ( V_1 , V_67 ,
V_48 , V_57 -> V_4 ) ;
break;
case V_68 :
V_11 = F_18 ( V_1 , V_57 -> V_4 ) ;
break;
case V_69 :
V_11 = F_7 ( V_1 , V_70 ,
V_71 ,
V_57 -> V_4 << 4 ) ;
break;
case V_62 :
V_11 = F_7 ( V_1 , V_72 ,
V_48 ,
V_1 -> V_40 -> V_41
+ V_57 -> V_4 ) ;
break;
case V_73 :
V_11 = F_19 ( V_1 , V_57 -> V_4 ) ;
break;
default:
F_24 ( & V_6 -> V_28 ,
L_2 ,
V_57 -> V_61 , V_57 -> V_4 ) ;
break;
} ;
F_25 ( & V_6 -> V_28 ) ;
return V_11 ;
}
static int F_26 ( struct V_32 * V_7 ,
struct V_74 * V_75 ,
struct V_76 * V_42 )
{
if ( V_42 -> V_77 > 0 )
return - V_14 ;
V_42 -> V_42 = V_43 ;
return 0 ;
}
static int F_27 ( struct V_32 * V_7 ,
struct V_74 * V_75 ,
struct V_78 * V_79 )
{
if ( V_79 -> V_77 >= F_5 ( V_80 ) )
return - V_14 ;
if ( V_79 -> V_42 != V_43 )
return - V_14 ;
V_79 -> V_81 = V_80 [ V_79 -> V_77 ] . V_39 ;
V_79 -> V_82 = V_79 -> V_81 ;
V_79 -> V_83 = V_80 [ V_79 -> V_77 ] . V_41 ;
V_79 -> V_84 = V_79 -> V_83 ;
return 0 ;
}
static void F_28 ( const struct V_85 * V_86 ,
struct V_87 * V_88 )
{
V_88 -> V_89 . V_39 = V_86 -> V_39 ;
V_88 -> V_89 . V_41 = V_86 -> V_41 ;
V_88 -> V_89 . V_42 = V_43 ;
V_88 -> V_89 . V_44 = V_45 ;
}
static int F_29 ( struct V_1 * V_1 ,
struct V_74 * V_75 ,
struct V_87 * V_88 )
{
struct V_35 * V_90 ;
struct V_32 * V_7 = & V_1 -> V_7 ;
if ( V_88 -> V_91 == V_92 ) {
V_90 = F_15 ( V_7 , V_75 , V_88 -> V_37 ) ;
V_88 -> V_89 = * V_90 ;
} else {
F_28 ( V_1 -> V_40 , V_88 ) ;
}
return 0 ;
}
static int F_30 ( struct V_32 * V_7 ,
struct V_74 * V_75 ,
struct V_87 * V_88 )
{
struct V_1 * V_1 = F_14 ( V_7 ) ;
int V_11 ;
F_16 ( & V_1 -> V_38 ) ;
V_11 = F_29 ( V_1 , V_75 , V_88 ) ;
F_17 ( & V_1 -> V_38 ) ;
return V_11 ;
}
static int
F_31 ( const struct V_85 * V_86 ,
struct V_35 * V_90 )
{
return abs ( V_86 -> V_39 - V_90 -> V_39 ) +
abs ( V_86 -> V_41 - V_90 -> V_41 ) ;
}
static const struct V_85 *
F_32 ( struct V_1 * V_1 ,
struct V_87 * V_88 )
{
int V_26 , V_93 , V_94 = 0 , V_95 = - 1 ;
struct V_35 * V_90 = & V_88 -> V_89 ;
for ( V_26 = 0 ; V_26 < F_5 ( V_80 ) ; V_26 ++ ) {
V_93 = F_31 ( & V_80 [ V_26 ] ,
V_90 ) ;
if ( V_95 == - 1 || V_93 < V_95 ) {
V_95 = V_93 ;
V_94 = V_26 ;
}
}
return & V_80 [ V_94 ] ;
}
static int
F_33 ( struct V_32 * V_7 ,
struct V_74 * V_75 ,
struct V_87 * V_88 )
{
struct V_1 * V_1 = F_14 ( V_7 ) ;
const struct V_85 * V_86 ;
struct V_35 * V_90 ;
T_5 V_96 ;
T_5 V_97 ;
T_4 V_98 ;
F_16 ( & V_1 -> V_38 ) ;
if ( V_88 -> V_89 . V_42 != V_43 )
V_88 -> V_89 . V_42 = V_43 ;
V_86 = F_32 ( V_1 , V_88 ) ;
F_28 ( V_86 , V_88 ) ;
if ( V_88 -> V_91 == V_92 ) {
V_90 = F_15 ( V_7 , V_75 , V_88 -> V_37 ) ;
* V_90 = V_88 -> V_89 ;
} else {
V_1 -> V_40 = V_86 ;
F_34 ( V_1 -> V_99 , V_86 -> V_100 ) ;
F_35 (
V_1 -> V_101 ,
V_102 [ V_86 -> V_100 ] . V_101 ) ;
V_96 = V_1 -> V_40 -> V_103 -
V_1 -> V_40 -> V_41 ;
V_97 = V_1 -> V_40 -> V_104 -
V_1 -> V_40 -> V_41 ;
F_22 (
V_1 -> V_105 , V_97 ,
V_106 - V_1 -> V_40 -> V_41 , 1 ,
V_96 ) ;
F_34 ( V_1 -> V_105 , V_96 ) ;
V_98 =
V_102 [ V_86 -> V_100 ] . V_107
- V_1 -> V_40 -> V_39 ;
F_22 ( V_1 -> V_108 , V_98 ,
V_98 , 1 , V_98 ) ;
}
F_17 ( & V_1 -> V_38 ) ;
return 0 ;
}
static int F_36 ( struct V_32 * V_7 , T_2 * V_109 )
{
* V_109 = V_110 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_2 ( & V_1 -> V_7 ) ;
const struct V_29 * V_111 ;
int V_11 , V_100 ;
V_11 = F_7 ( V_1 , V_112 ,
V_53 , V_113 ) ;
if ( V_11 ) {
F_38 ( & V_6 -> V_28 , L_3 ,
V_114 ) ;
return V_11 ;
}
V_100 = V_1 -> V_40 -> V_100 ;
V_111 = & V_102 [ V_100 ] . V_111 ;
V_11 = F_12 ( V_1 , V_111 ) ;
if ( V_11 ) {
F_38 ( & V_6 -> V_28 , L_4 , V_114 ) ;
return V_11 ;
}
V_111 = & V_1 -> V_40 -> V_111 ;
V_11 = F_12 ( V_1 , V_111 ) ;
if ( V_11 ) {
F_38 ( & V_6 -> V_28 , L_5 , V_114 ) ;
return V_11 ;
}
V_11 = F_39 ( V_1 -> V_7 . V_59 ) ;
if ( V_11 )
return V_11 ;
return F_7 ( V_1 , V_115 ,
V_53 ,
V_116 ) ;
}
static int F_40 ( struct V_1 * V_1 )
{
return F_7 ( V_1 , V_115 ,
V_53 , V_117 ) ;
}
static int F_41 ( struct V_32 * V_7 , int V_118 )
{
struct V_1 * V_1 = F_14 ( V_7 ) ;
struct V_5 * V_6 = F_2 ( V_7 ) ;
int V_11 = 0 ;
F_16 ( & V_1 -> V_38 ) ;
if ( V_1 -> V_119 == V_118 ) {
F_17 ( & V_1 -> V_38 ) ;
return 0 ;
}
if ( V_118 ) {
V_11 = F_42 ( & V_6 -> V_28 ) ;
if ( V_11 < 0 ) {
F_43 ( & V_6 -> V_28 ) ;
goto V_120;
}
V_11 = F_37 ( V_1 ) ;
if ( V_11 )
goto V_121;
} else {
F_40 ( V_1 ) ;
F_25 ( & V_6 -> V_28 ) ;
}
V_1 -> V_119 = V_118 ;
F_17 ( & V_1 -> V_38 ) ;
return V_11 ;
V_121:
F_25 ( & V_6 -> V_28 ) ;
V_120:
F_17 ( & V_1 -> V_38 ) ;
return V_11 ;
}
static int T_6 F_44 ( struct V_122 * V_28 )
{
struct V_5 * V_6 = F_45 ( V_28 ) ;
struct V_32 * V_7 = F_46 ( V_6 ) ;
struct V_1 * V_1 = F_14 ( V_7 ) ;
if ( V_1 -> V_119 )
F_40 ( V_1 ) ;
return 0 ;
}
static int T_6 F_47 ( struct V_122 * V_28 )
{
struct V_5 * V_6 = F_45 ( V_28 ) ;
struct V_32 * V_7 = F_46 ( V_6 ) ;
struct V_1 * V_1 = F_14 ( V_7 ) ;
int V_11 ;
if ( V_1 -> V_119 ) {
V_11 = F_37 ( V_1 ) ;
if ( V_11 )
goto error;
}
return 0 ;
error:
F_40 ( V_1 ) ;
V_1 -> V_119 = 0 ;
return V_11 ;
}
static int F_48 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_2 ( & V_1 -> V_7 ) ;
int V_11 ;
T_2 V_4 ;
V_11 = F_1 ( V_1 , V_123 ,
V_71 , & V_4 ) ;
if ( V_11 )
return V_11 ;
if ( V_4 != V_124 ) {
F_38 ( & V_6 -> V_28 , L_6 ,
V_124 , V_4 ) ;
return - V_20 ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_2 ( & V_1 -> V_7 ) ;
struct V_125 * V_126 ;
T_4 V_127 ;
T_4 V_96 ;
T_4 V_97 ;
int V_11 ;
V_126 = & V_1 -> V_59 ;
V_11 = F_50 ( V_126 , 8 ) ;
if ( V_11 )
return V_11 ;
F_51 ( & V_1 -> V_38 ) ;
V_126 -> V_128 = & V_1 -> V_38 ;
V_1 -> V_99 = F_52 ( V_126 ,
& V_129 ,
V_130 ,
V_131 - 1 ,
0 ,
V_132 ) ;
V_1 -> V_99 -> V_16 |= V_133 ;
V_1 -> V_101 = F_53 ( V_126 , & V_129 ,
V_134 , 0 ,
V_102 [ 0 ] . V_101 , 1 ,
V_102 [ 0 ] . V_101 ) ;
V_96 = V_1 -> V_40 -> V_103 - V_1 -> V_40 -> V_41 ;
V_97 = V_1 -> V_40 -> V_104 - V_1 -> V_40 -> V_41 ;
V_1 -> V_105 = F_53 (
V_126 , & V_129 , V_62 ,
V_97 ,
V_106 - V_1 -> V_40 -> V_41 , 1 ,
V_96 ) ;
V_1 -> V_108 = F_53 (
V_126 , & V_129 , V_135 ,
V_136 - V_1 -> V_40 -> V_39 ,
V_136 - V_1 -> V_40 -> V_39 ,
1 ,
V_136 - V_1 -> V_40 -> V_39 ) ;
V_1 -> V_108 -> V_16 |= V_133 ;
V_127 = V_1 -> V_40 -> V_103 - 8 ;
V_1 -> V_63 = F_53 (
V_126 , & V_129 ,
V_69 , V_137 ,
V_127 , V_138 ,
V_139 ) ;
F_53 ( V_126 , & V_129 , V_66 ,
V_140 , V_141 ,
V_142 , V_143 ) ;
F_53 ( V_126 , & V_129 , V_68 ,
V_144 , V_145 ,
V_146 , V_147 ) ;
F_54 ( V_126 , & V_129 ,
V_73 ,
F_5 ( V_148 ) - 1 ,
0 , 0 , V_148 ) ;
if ( V_126 -> error ) {
V_11 = V_126 -> error ;
F_38 ( & V_6 -> V_28 , L_7 ,
V_114 , V_11 ) ;
goto error;
}
V_1 -> V_7 . V_59 = V_126 ;
return 0 ;
error:
F_55 ( V_126 ) ;
F_56 ( & V_1 -> V_38 ) ;
return V_11 ;
}
static void F_57 ( struct V_1 * V_1 )
{
F_55 ( V_1 -> V_7 . V_59 ) ;
F_56 ( & V_1 -> V_38 ) ;
}
static int F_58 ( struct V_5 * V_6 ,
const struct V_149 * V_150 )
{
struct V_1 * V_1 ;
int V_11 ;
T_2 V_4 = 0 ;
F_59 ( & V_6 -> V_28 , L_8 , & V_4 ) ;
if ( V_4 != 19200000 )
return - V_14 ;
V_1 = F_60 ( & V_6 -> V_28 , sizeof( * V_1 ) , V_151 ) ;
if ( ! V_1 )
return - V_152 ;
F_61 ( & V_1 -> V_7 , V_6 , & V_153 ) ;
V_11 = F_48 ( V_1 ) ;
if ( V_11 ) {
F_38 ( & V_6 -> V_28 , L_9 , V_11 ) ;
return V_11 ;
}
V_1 -> V_40 = & V_80 [ 0 ] ;
V_11 = F_49 ( V_1 ) ;
if ( V_11 )
return V_11 ;
V_1 -> V_7 . V_154 = & V_155 ;
V_1 -> V_7 . V_16 |= V_156 ;
V_1 -> V_7 . V_157 . V_158 = & V_159 ;
V_1 -> V_7 . V_157 . V_160 = V_161 ;
V_1 -> V_37 . V_16 = V_162 ;
V_11 = F_62 ( & V_1 -> V_7 . V_157 , 1 , & V_1 -> V_37 ) ;
if ( V_11 ) {
F_38 ( & V_6 -> V_28 , L_10 , V_114 , V_11 ) ;
goto V_163;
}
V_11 = F_63 ( & V_1 -> V_7 ) ;
if ( V_11 < 0 )
goto V_164;
F_64 ( & V_6 -> V_28 ) ;
F_65 ( & V_6 -> V_28 ) ;
F_66 ( & V_6 -> V_28 ) ;
F_25 ( & V_6 -> V_28 ) ;
return 0 ;
V_164:
F_67 ( & V_1 -> V_7 . V_157 ) ;
V_163:
F_57 ( V_1 ) ;
F_38 ( & V_6 -> V_28 , L_10 , V_114 , V_11 ) ;
return V_11 ;
}
static int F_68 ( struct V_5 * V_6 )
{
struct V_32 * V_7 = F_46 ( V_6 ) ;
struct V_1 * V_1 = F_14 ( V_7 ) ;
F_69 ( V_7 ) ;
F_67 ( & V_7 -> V_157 ) ;
F_57 ( V_1 ) ;
F_42 ( & V_6 -> V_28 ) ;
F_70 ( & V_6 -> V_28 ) ;
F_71 ( & V_6 -> V_28 ) ;
F_43 ( & V_6 -> V_28 ) ;
return 0 ;
}
