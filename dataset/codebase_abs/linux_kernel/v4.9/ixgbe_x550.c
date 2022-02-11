static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_2 ( V_2 ) ;
if ( V_4 -> V_7 . V_8 ( V_2 ) != V_9 )
V_6 -> V_7 . V_10 = NULL ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
T_2 V_11 = F_4 ( V_2 , V_12 ) ;
if ( V_2 -> V_13 . V_14 ) {
V_11 &= ~ ( V_15 | V_16 ) ;
V_11 |= V_17 ;
}
V_11 &= ~ ( V_18 | V_19 ) ;
F_5 ( V_2 , V_12 , V_11 ) ;
F_6 ( V_2 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 , T_3 V_20 , T_3 * V_21 )
{
return V_2 -> V_6 . V_7 . V_22 ( V_2 , V_23 , V_20 ,
V_21 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 , T_3 V_20 , T_3 V_21 )
{
return V_2 -> V_6 . V_7 . V_24 ( V_2 , V_23 , V_20 ,
V_21 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 , T_4 V_20 , T_4 * V_21 )
{
T_1 V_25 ;
V_25 = F_10 ( V_2 , V_20 , V_26 , V_21 ) ;
if ( V_25 )
F_11 ( V_2 , L_1 , V_25 ) ;
return V_25 ;
}
static T_1 F_12 ( struct V_1 * V_2 , T_4 V_20 , T_4 V_21 )
{
T_1 V_25 ;
V_25 = F_13 ( V_2 , V_20 , V_26 ,
V_21 ) ;
if ( V_25 )
F_11 ( V_2 , L_1 , V_25 ) ;
return V_25 ;
}
static T_1 F_14 ( struct V_1 * V_2 )
{
T_1 V_25 ;
T_2 V_27 ;
T_3 V_21 ;
T_4 V_20 ;
V_25 = F_9 ( V_2 , V_28 , & V_20 ) ;
if ( V_25 )
return V_25 ;
V_20 |= V_29 ;
V_25 = F_12 ( V_2 , V_28 , V_20 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_9 ( V_2 , V_30 , & V_20 ) ;
if ( V_25 )
return V_25 ;
V_20 &= ~ V_29 ;
V_25 = F_12 ( V_2 , V_30 , V_20 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_9 ( V_2 , V_28 , & V_20 ) ;
if ( V_25 )
return V_25 ;
V_20 &= ~ V_29 ;
V_25 = F_12 ( V_2 , V_28 , V_20 ) ;
if ( V_25 )
return V_25 ;
F_15 ( V_31 , V_31 + 100 ) ;
V_25 = F_9 ( V_2 , V_28 , & V_20 ) ;
if ( V_25 )
return V_25 ;
V_20 |= V_29 ;
V_25 = F_12 ( V_2 , V_28 , V_20 ) ;
if ( V_25 )
return V_25 ;
F_16 ( V_32 ) ;
for ( V_27 = 0 ; V_27 < V_33 ; V_27 ++ ) {
V_25 = F_7 ( V_2 , V_34 ,
& V_21 ) ;
if ( ! V_25 && V_21 == V_35 )
break;
F_16 ( V_36 ) ;
}
if ( V_27 == V_33 ) {
F_11 ( V_2 , L_2 ) ;
return V_37 ;
}
V_25 = F_7 ( V_2 , V_38 , & V_21 ) ;
if ( V_25 || ! ( V_21 & V_35 ) ) {
F_11 ( V_2 , L_3 ) ;
return V_37 ;
}
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
T_2 V_39 = V_2 -> V_6 . V_40 ;
T_1 V_25 ;
T_3 V_21 ;
T_4 V_27 ;
for ( V_27 = 0 ; V_27 < V_33 ; V_27 ++ ) {
V_25 = V_2 -> V_4 . V_7 . V_41 ( V_2 , V_39 ) ;
if ( V_25 ) {
F_11 ( V_2 , L_4 , V_25 ) ;
F_16 ( V_36 ) ;
continue;
}
V_25 = F_7 ( V_2 , V_42 , & V_21 ) ;
if ( ! V_25 && V_21 == V_43 )
goto V_44;
if ( V_25 || V_21 != V_45 )
break;
V_2 -> V_4 . V_7 . V_46 ( V_2 , V_39 ) ;
F_16 ( V_36 ) ;
}
if ( V_27 == V_33 ) {
V_25 = V_2 -> V_4 . V_7 . V_41 ( V_2 , V_39 ) ;
if ( V_25 ) {
F_11 ( V_2 , L_4 , V_25 ) ;
return;
}
}
V_25 = F_14 ( V_2 ) ;
if ( V_25 ) {
F_11 ( V_2 , L_5 , V_25 ) ;
goto V_44;
}
F_8 ( V_2 , V_42 ,
V_45 ) ;
V_2 -> V_4 . V_7 . V_46 ( V_2 , V_39 ) ;
F_15 ( 10000 , 12000 ) ;
V_25 = V_2 -> V_4 . V_7 . V_41 ( V_2 , V_39 ) ;
if ( V_25 ) {
F_11 ( V_2 , L_6 , V_25 ) ;
return;
}
V_25 = F_8 ( V_2 , V_42 ,
V_43 ) ;
V_44:
V_2 -> V_4 . V_7 . V_46 ( V_2 , V_39 ) ;
F_16 ( V_2 -> V_47 . V_48 ) ;
}
static T_1 F_18 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_49 ) {
case V_50 :
if ( V_2 -> V_13 . V_14 )
V_2 -> V_6 . V_40 = V_51 ;
else
V_2 -> V_6 . V_40 = V_52 ;
return F_19 ( V_2 ) ;
case V_53 :
V_2 -> V_6 . V_40 = V_54 ;
F_3 ( V_2 ) ;
F_17 ( V_2 ) ;
case V_55 :
return F_19 ( V_2 ) ;
case V_56 :
V_2 -> V_6 . type = V_57 ;
break;
case V_58 :
case V_59 :
case V_60 :
V_2 -> V_6 . type = V_61 ;
break;
case V_62 :
if ( V_2 -> V_13 . V_14 )
V_2 -> V_6 . V_40 = V_51 ;
else
V_2 -> V_6 . V_40 = V_52 ;
case V_63 :
case V_64 :
return F_20 ( V_2 ) ;
default:
break;
}
return 0 ;
}
static T_1 F_21 ( struct V_1 * V_2 , T_2 V_65 ,
T_2 V_66 , T_3 * V_67 )
{
return V_68 ;
}
static T_1 F_22 ( struct V_1 * V_2 , T_2 V_65 ,
T_2 V_66 , T_3 V_67 )
{
return V_68 ;
}
static T_1 F_23 ( struct V_1 * V_2 )
{
struct V_69 * V_47 = & V_2 -> V_47 ;
T_2 V_70 ;
T_3 V_71 ;
if ( V_47 -> type == V_72 ) {
V_47 -> V_48 = 10 ;
V_47 -> type = V_73 ;
V_70 = F_4 ( V_2 , F_24 ( V_2 ) ) ;
V_71 = ( T_3 ) ( ( V_70 & V_74 ) >>
V_75 ) ;
V_47 -> V_76 = F_25 ( V_71 +
V_77 ) ;
F_26 ( V_2 , L_7 ,
V_47 -> type , V_47 -> V_76 ) ;
}
return 0 ;
}
static T_1 F_27 ( struct V_1 * V_2 , T_2 * V_78 )
{
T_2 V_79 , V_80 ;
for ( V_79 = 0 ; V_79 < V_81 ; V_79 ++ ) {
V_80 = F_4 ( V_2 , V_82 ) ;
if ( ! ( V_80 & V_83 ) )
break;
F_28 ( 10 ) ;
}
if ( V_78 )
* V_78 = V_80 ;
if ( V_79 == V_81 ) {
F_26 ( V_2 , L_8 ) ;
return V_37 ;
}
return 0 ;
}
static T_1 F_29 ( struct V_1 * V_2 , T_2 V_65 ,
T_2 V_66 , T_2 * V_84 )
{
T_2 V_85 = V_51 | V_52 ;
T_2 V_80 , error ;
T_1 V_86 ;
V_86 = V_2 -> V_4 . V_7 . V_41 ( V_2 , V_85 ) ;
if ( V_86 )
return V_86 ;
V_86 = F_27 ( V_2 , NULL ) ;
if ( V_86 )
goto V_44;
V_80 = ( ( V_65 << V_87 ) |
( V_66 << V_88 ) ) ;
F_5 ( V_2 , V_82 , V_80 ) ;
V_86 = F_27 ( V_2 , & V_80 ) ;
if ( ( V_80 & V_89 ) != 0 ) {
error = ( V_80 & V_90 ) >>
V_91 ;
F_26 ( V_2 , L_9 , error ) ;
return V_37 ;
}
if ( ! V_86 )
* V_84 = F_4 ( V_2 , V_92 ) ;
V_44:
V_2 -> V_4 . V_7 . V_46 ( V_2 , V_85 ) ;
return V_86 ;
}
static T_1 F_30 ( struct V_1 * V_2 )
{
struct V_93 V_94 ;
T_1 V_25 ;
V_94 . V_95 . V_96 = V_97 ;
V_94 . V_95 . V_98 = V_99 ;
V_94 . V_95 . V_100 . V_101 = 0 ;
V_94 . V_95 . V_102 = V_103 ;
V_94 . V_104 = V_2 -> V_13 . V_14 ;
V_94 . V_105 = V_106 ;
V_94 . V_107 = 0 ;
V_25 = F_31 ( V_2 , & V_94 , sizeof( V_94 ) ,
V_108 ,
true ) ;
if ( V_25 )
return V_25 ;
if ( V_94 . V_95 . V_100 . V_109 == V_110 )
return 0 ;
if ( V_94 . V_95 . V_100 . V_109 != V_111 )
return V_112 ;
return V_113 ;
}
static T_1 F_32 ( struct V_1 * V_2 )
{
struct V_93 V_94 ;
T_1 V_25 ;
V_94 . V_95 . V_96 = V_97 ;
V_94 . V_95 . V_98 = V_99 ;
V_94 . V_95 . V_100 . V_101 = 0 ;
V_94 . V_95 . V_102 = V_103 ;
V_94 . V_104 = V_2 -> V_13 . V_14 ;
V_94 . V_105 = V_114 ;
V_94 . V_107 = 0 ;
V_25 = F_31 ( V_2 , & V_94 , sizeof( V_94 ) ,
V_108 ,
true ) ;
if ( V_25 )
return V_25 ;
if ( V_94 . V_95 . V_100 . V_109 == V_110 )
return 0 ;
return V_112 ;
}
static T_1 F_33 ( struct V_1 * V_2 , T_2 V_65 ,
T_5 T_2 V_66 ,
T_2 V_84 )
{
struct V_115 V_116 ;
memset ( & V_116 , 0 , sizeof( V_116 ) ) ;
V_116 . V_95 . V_96 = V_117 ;
V_116 . V_95 . V_98 = V_118 ;
V_116 . V_95 . V_102 = V_103 ;
V_116 . V_104 = V_2 -> V_13 . V_14 ;
V_116 . V_105 = V_119 ;
V_116 . V_120 = F_34 ( V_65 ) ;
V_116 . V_121 = F_35 ( V_84 ) ;
return F_31 ( V_2 , & V_116 , sizeof( V_116 ) ,
V_108 , false ) ;
}
static T_1 F_36 ( struct V_1 * V_2 , T_2 V_65 ,
T_5 T_2 V_66 ,
T_2 * V_84 )
{
union {
struct V_115 V_96 ;
struct V_122 V_123 ;
} V_124 ;
T_1 V_25 ;
memset ( & V_124 , 0 , sizeof( V_124 ) ) ;
V_124 . V_96 . V_95 . V_96 = V_117 ;
V_124 . V_96 . V_95 . V_98 = V_118 ;
V_124 . V_96 . V_95 . V_102 = V_103 ;
V_124 . V_96 . V_104 = V_2 -> V_13 . V_14 ;
V_124 . V_96 . V_105 = V_125 ;
V_124 . V_96 . V_120 = F_34 ( V_65 ) ;
V_25 = F_31 ( V_2 , & V_124 . V_96 , sizeof( V_124 . V_96 ) ,
V_108 , true ) ;
* V_84 = F_37 ( V_124 . V_123 . V_126 ) ;
return V_25 ;
}
static T_1 F_38 ( struct V_1 * V_2 , T_3 V_127 ,
T_3 * V_84 )
{
T_1 V_25 ;
struct V_128 V_129 ;
V_129 . V_95 . V_130 . V_96 = V_131 ;
V_129 . V_95 . V_130 . V_132 = 0 ;
V_129 . V_95 . V_130 . V_133 = V_134 ;
V_129 . V_95 . V_130 . V_102 = V_103 ;
V_129 . V_120 = F_35 ( V_127 * 2 ) ;
V_129 . V_135 = F_34 ( sizeof( T_3 ) ) ;
V_25 = F_31 ( V_2 , & V_129 , sizeof( V_129 ) ,
V_108 , false ) ;
if ( V_25 )
return V_25 ;
* V_84 = ( T_3 ) F_39 ( V_2 , V_136 ,
V_137 ) ;
return 0 ;
}
static T_1 F_40 ( struct V_1 * V_2 ,
T_3 V_127 , T_3 V_138 , T_3 * V_84 )
{
struct V_128 V_129 ;
T_2 V_139 = 0 ;
T_3 V_140 ;
T_1 V_25 ;
T_2 V_79 ;
V_25 = V_2 -> V_4 . V_7 . V_41 ( V_2 , V_141 ) ;
if ( V_25 ) {
F_26 ( V_2 , L_10 ) ;
return V_25 ;
}
while ( V_138 ) {
if ( V_138 > V_142 / 2 )
V_140 = V_142 / 2 ;
else
V_140 = V_138 ;
V_129 . V_95 . V_130 . V_96 = V_131 ;
V_129 . V_95 . V_130 . V_132 = 0 ;
V_129 . V_95 . V_130 . V_133 = V_134 ;
V_129 . V_95 . V_130 . V_102 = V_103 ;
V_129 . V_120 = F_35 ( ( V_127 + V_139 ) * 2 ) ;
V_129 . V_135 = F_34 ( V_140 * 2 ) ;
V_25 = F_31 ( V_2 , & V_129 ,
sizeof( V_129 ) ,
V_108 ,
false ) ;
if ( V_25 ) {
F_26 ( V_2 , L_11 ) ;
goto V_44;
}
for ( V_79 = 0 ; V_79 < V_140 ; V_79 ++ ) {
T_2 V_20 = V_136 + ( V_137 << 2 ) +
2 * V_79 ;
T_2 V_21 = F_4 ( V_2 , V_20 ) ;
V_84 [ V_139 ] = ( T_3 ) ( V_21 & 0xffff ) ;
V_139 ++ ;
V_79 ++ ;
if ( V_79 < V_140 ) {
V_21 >>= 16 ;
V_84 [ V_139 ] = ( T_3 ) ( V_21 & 0xffff ) ;
V_139 ++ ;
}
}
V_138 -= V_140 ;
}
V_44:
V_2 -> V_4 . V_7 . V_46 ( V_2 , V_141 ) ;
return V_25 ;
}
static T_1 F_41 ( struct V_1 * V_2 , T_3 V_143 ,
T_3 V_144 , T_3 * V_145 , T_3 * V_129 ,
T_2 V_146 )
{
T_3 V_147 [ 256 ] ;
T_1 V_25 ;
T_3 V_135 , V_148 , V_79 , V_149 ;
T_3 * V_150 ;
V_148 = sizeof( V_147 ) / sizeof( V_147 [ 0 ] ) ;
if ( ! V_129 ) {
V_25 = F_40 ( V_2 , V_143 , V_148 , V_147 ) ;
if ( V_25 ) {
F_26 ( V_2 , L_12 ) ;
return V_25 ;
}
V_150 = V_147 ;
} else {
if ( V_146 < V_143 )
return V_151 ;
V_150 = & V_129 [ V_143 ] ;
}
if ( V_144 ) {
V_149 = 0 ;
V_135 = V_144 ;
} else {
V_149 = 1 ;
V_135 = V_150 [ 0 ] ;
if ( V_135 == 0xFFFF || V_135 == 0 ||
( V_143 + V_135 ) >= V_2 -> V_47 . V_76 )
return 0 ;
}
if ( V_129 && ( ( T_2 ) V_149 + ( T_2 ) V_135 > V_146 ) )
return V_151 ;
for ( V_79 = V_149 ; V_135 ; V_79 ++ , V_135 -- ) {
if ( V_79 == V_148 && ! V_129 ) {
V_143 += V_148 ;
V_79 = 0 ;
if ( V_135 < V_148 )
V_148 = V_135 ;
V_25 = F_40 ( V_2 , V_143 ,
V_148 , V_147 ) ;
if ( V_25 ) {
F_26 ( V_2 , L_12 ) ;
return V_25 ;
}
}
* V_145 += V_150 [ V_79 ] ;
}
return 0 ;
}
static T_1 F_42 ( struct V_1 * V_2 , T_3 * V_129 ,
T_2 V_146 )
{
T_3 V_152 [ V_153 + 1 ] ;
T_3 * V_150 ;
T_1 V_25 ;
T_3 V_102 = 0 ;
T_3 V_154 , V_79 , V_144 ;
V_2 -> V_47 . V_7 . V_155 ( V_2 ) ;
if ( ! V_129 ) {
V_25 = F_40 ( V_2 , 0 ,
V_153 + 1 ,
V_152 ) ;
if ( V_25 ) {
F_26 ( V_2 , L_12 ) ;
return V_25 ;
}
V_150 = V_152 ;
} else {
if ( V_146 < V_153 )
return V_151 ;
V_150 = V_129 ;
}
for ( V_79 = 0 ; V_79 <= V_153 ; V_79 ++ )
if ( V_79 != V_156 )
V_102 += V_150 [ V_79 ] ;
for ( V_79 = V_157 ; V_79 < V_158 ; V_79 ++ ) {
if ( V_79 == V_159 || V_79 == V_160 )
continue;
V_154 = V_150 [ V_79 ] ;
if ( V_154 == 0xFFFF || V_154 == 0 ||
V_154 >= V_2 -> V_47 . V_76 )
continue;
switch ( V_79 ) {
case V_161 :
V_144 = V_162 ;
break;
case V_163 :
case V_164 :
V_144 = V_165 ;
break;
default:
V_144 = 0 ;
break;
}
V_25 = F_41 ( V_2 , V_154 , V_144 , & V_102 ,
V_129 , V_146 ) ;
if ( V_25 )
return V_25 ;
}
V_102 = ( T_3 ) V_166 - V_102 ;
return ( T_1 ) V_102 ;
}
static T_1 F_43 ( struct V_1 * V_2 )
{
return F_42 ( V_2 , NULL , 0 ) ;
}
static T_1 F_44 ( struct V_1 * V_2 , T_3 V_127 , T_3 * V_84 )
{
T_1 V_25 = 0 ;
if ( V_2 -> V_4 . V_7 . V_41 ( V_2 , V_141 ) == 0 ) {
V_25 = F_38 ( V_2 , V_127 , V_84 ) ;
V_2 -> V_4 . V_7 . V_46 ( V_2 , V_141 ) ;
} else {
V_25 = V_167 ;
}
return V_25 ;
}
static T_1 F_45 ( struct V_1 * V_2 ,
T_3 * V_168 )
{
T_1 V_25 ;
T_3 V_102 ;
T_3 V_169 = 0 ;
V_25 = V_2 -> V_47 . V_7 . V_170 ( V_2 , 0 , & V_102 ) ;
if ( V_25 ) {
F_26 ( V_2 , L_13 ) ;
return V_25 ;
}
V_25 = V_2 -> V_47 . V_7 . V_171 ( V_2 ) ;
if ( V_25 < 0 )
return V_25 ;
V_102 = ( T_3 ) ( V_25 & 0xffff ) ;
V_25 = F_44 ( V_2 , V_156 ,
& V_169 ) ;
if ( V_25 )
return V_25 ;
if ( V_169 != V_102 ) {
V_25 = V_172 ;
F_26 ( V_2 , L_14 ) ;
}
if ( V_168 )
* V_168 = V_102 ;
return V_25 ;
}
static T_1 F_46 ( struct V_1 * V_2 , T_3 V_127 ,
T_3 V_84 )
{
T_1 V_25 ;
struct V_173 V_129 ;
V_129 . V_95 . V_130 . V_96 = V_174 ;
V_129 . V_95 . V_130 . V_132 = 0 ;
V_129 . V_95 . V_130 . V_133 = V_175 ;
V_129 . V_95 . V_130 . V_102 = V_103 ;
V_129 . V_135 = F_34 ( sizeof( T_3 ) ) ;
V_129 . V_84 = V_84 ;
V_129 . V_120 = F_35 ( V_127 * 2 ) ;
V_25 = F_31 ( V_2 , & V_129 , sizeof( V_129 ) ,
V_108 , false ) ;
return V_25 ;
}
static T_1 F_47 ( struct V_1 * V_2 , T_3 V_127 , T_3 V_84 )
{
T_1 V_25 = 0 ;
if ( V_2 -> V_4 . V_7 . V_41 ( V_2 , V_141 ) == 0 ) {
V_25 = F_46 ( V_2 , V_127 , V_84 ) ;
V_2 -> V_4 . V_7 . V_46 ( V_2 , V_141 ) ;
} else {
F_26 ( V_2 , L_15 ) ;
V_25 = V_167 ;
}
return V_25 ;
}
static T_1 F_48 ( struct V_1 * V_2 )
{
T_1 V_25 = 0 ;
union V_176 V_129 ;
V_129 . V_130 . V_96 = V_177 ;
V_129 . V_130 . V_132 = 0 ;
V_129 . V_130 . V_133 = V_178 ;
V_129 . V_130 . V_102 = V_103 ;
V_25 = F_31 ( V_2 , & V_129 , sizeof( V_129 ) ,
V_108 , false ) ;
return V_25 ;
}
static T_1 F_49 ( struct V_1 * V_2 )
{
V_2 -> V_13 . type = V_179 ;
V_2 -> V_13 . V_180 = V_181 ;
V_2 -> V_13 . V_182 = V_183 ;
V_2 -> V_4 . V_7 . V_184 ( V_2 ) ;
return 0 ;
}
static void F_50 ( struct V_1 * V_2 )
{
T_2 V_185 , V_186 ;
T_1 V_25 ;
struct V_187 V_188 ;
V_185 = F_4 ( V_2 , V_189 ) ;
if ( V_185 & V_190 ) {
V_186 = F_4 ( V_2 , V_191 ) ;
if ( V_186 & V_192 ) {
V_186 &= ~ V_192 ;
F_5 ( V_2 , V_191 , V_186 ) ;
V_2 -> V_4 . V_193 = true ;
} else {
V_2 -> V_4 . V_193 = false ;
}
V_188 . V_95 . V_96 = V_194 ;
V_188 . V_95 . V_98 = V_195 ;
V_188 . V_95 . V_102 = V_103 ;
V_188 . V_104 = V_2 -> V_13 . V_14 ;
V_25 = F_31 ( V_2 , & V_188 ,
sizeof( struct V_187 ) ,
V_108 , true ) ;
if ( V_25 ) {
V_185 = F_4 ( V_2 , V_189 ) ;
if ( V_185 & V_190 ) {
V_185 &= ~ V_190 ;
F_5 ( V_2 , V_189 , V_185 ) ;
}
}
}
}
static T_1 F_51 ( struct V_1 * V_2 )
{
T_1 V_25 ;
T_3 V_102 = 0 ;
V_25 = F_44 ( V_2 , 0 , & V_102 ) ;
if ( V_25 ) {
F_26 ( V_2 , L_13 ) ;
return V_25 ;
}
V_25 = F_43 ( V_2 ) ;
if ( V_25 < 0 )
return V_25 ;
V_102 = ( T_3 ) ( V_25 & 0xffff ) ;
V_25 = F_47 ( V_2 , V_156 ,
V_102 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_48 ( V_2 ) ;
return V_25 ;
}
static T_1 F_52 ( struct V_1 * V_2 ,
T_3 V_127 , T_3 V_138 ,
T_3 * V_84 )
{
T_1 V_25 = 0 ;
T_2 V_79 = 0 ;
V_25 = V_2 -> V_4 . V_7 . V_41 ( V_2 , V_141 ) ;
if ( V_25 ) {
F_26 ( V_2 , L_16 ) ;
return V_25 ;
}
for ( V_79 = 0 ; V_79 < V_138 ; V_79 ++ ) {
V_25 = F_46 ( V_2 , V_127 + V_79 ,
V_84 [ V_79 ] ) ;
if ( V_25 ) {
F_26 ( V_2 , L_17 ) ;
break;
}
}
V_2 -> V_4 . V_7 . V_46 ( V_2 , V_141 ) ;
return V_25 ;
}
static T_1 F_53 ( struct V_1 * V_2 , T_2 V_65 ,
T_2 V_66 , T_2 V_84 )
{
T_2 V_85 = V_51 | V_52 ;
T_2 V_80 , error ;
T_1 V_86 ;
V_86 = V_2 -> V_4 . V_7 . V_41 ( V_2 , V_85 ) ;
if ( V_86 )
return V_86 ;
V_86 = F_27 ( V_2 , NULL ) ;
if ( V_86 )
goto V_44;
V_80 = ( ( V_65 << V_87 ) |
( V_66 << V_88 ) ) ;
F_5 ( V_2 , V_82 , V_80 ) ;
F_5 ( V_2 , V_92 , V_84 ) ;
V_86 = F_27 ( V_2 , & V_80 ) ;
if ( ( V_80 & V_89 ) != 0 ) {
error = ( V_80 & V_90 ) >>
V_91 ;
F_26 ( V_2 , L_18 , error ) ;
return V_37 ;
}
V_44:
V_2 -> V_4 . V_7 . V_46 ( V_2 , V_85 ) ;
return V_86 ;
}
static T_1 F_54 ( struct V_1 * V_2 , T_6 * V_182 )
{
T_1 V_25 ;
T_2 V_196 ;
V_25 = F_29 ( V_2 ,
F_55 ( V_2 -> V_13 . V_14 ) ,
V_197 , & V_196 ) ;
if ( V_25 )
return V_25 ;
V_196 &= ~ V_198 ;
V_196 &= ~ V_199 ;
switch ( * V_182 ) {
case V_200 :
V_196 |= V_201 ;
break;
case V_202 :
V_196 |= V_203 ;
break;
default:
return V_204 ;
}
V_25 = F_53 ( V_2 ,
F_55 ( V_2 -> V_13 . V_14 ) ,
V_197 , V_196 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_29 ( V_2 ,
F_56 ( V_2 -> V_13 . V_14 ) ,
V_197 , & V_196 ) ;
if ( V_25 )
return V_25 ;
V_196 |= V_205 ;
V_25 = F_53 ( V_2 ,
F_56 ( V_2 -> V_13 . V_14 ) ,
V_197 , V_196 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_29 ( V_2 ,
F_57 ( V_2 -> V_13 . V_14 ) ,
V_197 , & V_196 ) ;
if ( V_25 )
return V_25 ;
V_196 &= ~ V_206 ;
V_196 &= ~ V_207 ;
V_196 &= ~ V_208 ;
V_25 = F_53 ( V_2 ,
F_57 ( V_2 -> V_13 . V_14 ) ,
V_197 , V_196 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_29 ( V_2 ,
F_58 ( V_2 -> V_13 . V_14 ) ,
V_197 , & V_196 ) ;
if ( V_25 )
return V_25 ;
V_196 &= ~ V_206 ;
V_196 &= ~ V_207 ;
V_196 &= ~ V_208 ;
V_25 = F_53 ( V_2 ,
F_58 ( V_2 -> V_13 . V_14 ) ,
V_197 , V_196 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_29 ( V_2 ,
F_59 ( V_2 -> V_13 . V_14 ) ,
V_197 , & V_196 ) ;
if ( V_25 )
return V_25 ;
V_196 |= V_209 ;
V_196 |= V_210 ;
V_196 |= V_211 ;
V_196 |= V_212 ;
V_25 = F_53 ( V_2 ,
F_59 ( V_2 -> V_13 . V_14 ) ,
V_197 , V_196 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_29 ( V_2 ,
F_55 ( V_2 -> V_13 . V_14 ) ,
V_197 , & V_196 ) ;
if ( V_25 )
return V_25 ;
V_196 |= V_213 ;
V_25 = F_53 ( V_2 ,
F_55 ( V_2 -> V_13 . V_14 ) ,
V_197 , V_196 ) ;
return V_25 ;
}
static T_1 F_60 ( struct V_1 * V_2 , bool * V_214 )
{
switch ( V_2 -> V_6 . V_215 ) {
case V_216 :
return V_217 ;
case V_218 :
case V_219 :
* V_214 = true ;
break;
case V_220 :
case V_221 :
case V_222 :
case V_223 :
case V_224 :
case V_225 :
case V_226 :
case V_227 :
* V_214 = false ;
break;
case V_228 :
case V_229 :
case V_230 :
default:
return V_231 ;
}
return 0 ;
}
static T_1
F_61 ( struct V_1 * V_2 ,
T_6 V_182 ,
T_5 bool V_232 )
{
T_1 V_25 ;
T_3 V_233 , V_21 ;
bool V_234 = false ;
V_25 = F_60 ( V_2 , & V_234 ) ;
if ( V_25 == V_217 )
return 0 ;
if ( V_25 )
return V_25 ;
if ( ! ( V_2 -> V_6 . V_235 & V_236 ) ) {
V_233 = V_237 + ( V_2 -> V_13 . V_14 << 12 ) ;
V_21 = V_238 ;
V_25 = F_62 ( V_2 , V_23 ,
V_233 , V_21 ) ;
if ( V_25 )
goto V_239;
V_233 = V_240 + ( V_2 -> V_13 . V_14 << 12 ) ;
V_21 = ( V_241 << 1 ) | 1 ;
V_25 = F_62 ( V_2 , V_23 ,
V_233 , V_21 ) ;
if ( V_25 )
goto V_239;
V_233 = V_242 + ( V_2 -> V_13 . V_14 << 12 ) ;
V_21 = V_182 & V_200 ?
V_238 : V_243 ;
V_25 = F_62 ( V_2 , V_23 ,
V_233 , V_21 ) ;
if ( V_25 )
goto V_239;
V_233 = V_244 + ( V_2 -> V_13 . V_14 << 12 ) ;
if ( V_234 )
V_21 = ( V_245 << 1 ) | 1 ;
else
V_21 = ( V_241 << 1 ) | 1 ;
V_25 = F_62 ( V_2 , V_23 ,
V_233 , V_21 ) ;
if ( V_25 )
goto V_239;
V_25 = F_54 ( V_2 , & V_182 ) ;
if ( V_25 ) {
F_26 ( V_2 , L_19 , V_25 ) ;
return V_25 ;
}
} else {
V_25 = F_63 ( V_2 , V_182 ) ;
if ( V_25 ) {
F_26 ( V_2 , L_20 , V_25 ) ;
return V_25 ;
}
V_233 = V_240 + ( V_2 -> V_13 . V_14 << 12 ) ;
if ( V_234 )
V_21 = ( V_245 << 1 ) | 1 ;
else
V_21 = ( V_241 << 1 ) | 1 ;
V_25 = F_62 ( V_2 , V_23 ,
V_233 , V_21 ) ;
if ( V_25 )
goto V_239;
}
return 0 ;
V_239:
F_26 ( V_2 , L_21 , V_25 ) ;
return V_25 ;
}
static T_1
F_64 ( struct V_1 * V_2 , T_6 V_182 ,
T_5 bool V_232 )
{
bool V_234 = false ;
T_2 V_246 ;
T_1 V_247 ;
V_247 = F_60 ( V_2 , & V_234 ) ;
if ( V_247 == V_217 )
return 0 ;
if ( ! V_247 )
return V_247 ;
V_247 = V_2 -> V_4 . V_7 . V_248 ( V_2 ,
F_65 ( V_2 -> V_13 . V_14 ) ,
V_197 ,
& V_246 ) ;
if ( V_247 )
return V_247 ;
if ( V_234 ) {
V_246 &= ~ V_249 ;
V_246 |= V_250 ;
} else {
V_246 |= V_249 ;
V_246 &= ~ V_250 ;
}
V_247 = V_2 -> V_4 . V_7 . V_251 ( V_2 ,
F_65 ( V_2 -> V_13 . V_14 ) ,
V_197 ,
V_246 ) ;
if ( V_247 )
return V_247 ;
return F_54 ( V_2 , & V_182 ) ;
}
static T_1
F_66 ( struct V_1 * V_2 , T_6 V_182 ,
T_5 bool V_232 )
{
T_2 V_252 , V_253 ;
bool V_234 = false ;
T_3 V_254 ;
T_1 V_247 ;
V_247 = F_60 ( V_2 , & V_234 ) ;
if ( V_247 == V_217 )
return 0 ;
if ( ! V_247 )
return V_247 ;
F_63 ( V_2 , V_182 ) ;
if ( V_2 -> V_6 . V_255 . V_256 == V_257 )
return V_258 ;
V_247 = V_2 -> V_6 . V_7 . V_259 ( V_2 , V_260 ,
V_261 , & V_254 ) ;
if ( V_247 )
return V_247 ;
if ( V_254 == V_262 )
V_253 = ( V_2 -> V_13 . V_14 +
( V_2 -> V_13 . V_263 << 1 ) ) << 12 ;
else
V_253 = V_2 -> V_13 . V_14 << 12 ;
V_252 = V_240 + V_253 ;
if ( V_234 )
V_254 = ( V_245 << 1 ) | 1 ;
else
V_254 = ( V_241 << 1 ) | 1 ;
return V_2 -> V_6 . V_7 . V_264 ( V_2 , V_252 , V_261 ,
V_254 ) ;
}
static T_1 F_67 ( struct V_1 * V_2 ,
T_6 V_182 ,
bool V_265 )
{
T_1 V_25 ;
T_6 V_266 ;
if ( V_182 & V_200 )
V_266 = V_200 ;
else
V_266 = V_202 ;
if ( ! ( V_2 -> V_6 . V_235 & V_236 ) ) {
V_25 = F_54 ( V_2 , & V_266 ) ;
if ( V_25 )
return V_25 ;
}
return V_2 -> V_6 . V_7 . V_267 ( V_2 , V_182 , V_265 ) ;
}
static T_1 F_68 ( struct V_1 * V_2 ,
T_6 * V_182 ,
bool * V_268 ,
bool V_269 )
{
T_2 V_25 ;
T_3 V_270 ;
if ( V_2 -> V_4 . V_7 . V_8 ( V_2 ) != V_9 )
return V_271 ;
V_25 = F_69 ( V_2 , V_182 , V_268 ,
V_269 ) ;
if ( V_25 || ! ( * V_268 ) )
return V_25 ;
V_25 = V_2 -> V_6 . V_7 . V_259 ( V_2 , V_272 ,
V_273 ,
& V_270 ) ;
if ( V_25 )
return V_25 ;
if ( ! ( V_270 & V_274 ) )
* V_268 = false ;
return 0 ;
}
static T_1
F_70 ( struct V_1 * V_2 , T_5 T_6 V_182 ,
T_5 bool V_232 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_2 V_275 , V_276 ;
T_1 V_247 ;
V_247 = V_4 -> V_7 . V_248 ( V_2 ,
F_55 ( V_2 -> V_13 . V_14 ) ,
V_197 , & V_275 ) ;
if ( V_247 )
return V_247 ;
V_275 &= ~ V_198 ;
V_275 &= ~ V_199 ;
V_275 |= V_277 ;
V_275 |= V_278 ;
V_275 |= V_203 ;
V_247 = V_4 -> V_7 . V_251 ( V_2 ,
F_55 ( V_2 -> V_13 . V_14 ) ,
V_197 , V_275 ) ;
if ( V_247 )
return V_247 ;
V_247 = V_4 -> V_7 . V_248 ( V_2 ,
F_71 ( V_2 -> V_13 . V_14 ) ,
V_197 , & V_276 ) ;
if ( V_247 )
return V_247 ;
V_276 |= V_279 ;
V_276 |= V_280 ;
V_247 = V_4 -> V_7 . V_251 ( V_2 ,
F_71 ( V_2 -> V_13 . V_14 ) ,
V_197 , V_276 ) ;
if ( V_247 )
return V_247 ;
V_275 |= V_213 ;
V_247 = V_4 -> V_7 . V_251 ( V_2 ,
F_55 ( V_2 -> V_13 . V_14 ) ,
V_197 , V_275 ) ;
return V_247 ;
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
V_4 -> V_7 . V_281 = V_282 ;
switch ( V_4 -> V_7 . V_8 ( V_2 ) ) {
case V_283 :
V_4 -> V_7 . V_284 = NULL ;
V_4 -> V_7 . V_285 = NULL ;
V_4 -> V_7 . V_286 = NULL ;
V_4 -> V_7 . V_287 = V_288 ;
switch ( V_2 -> V_49 ) {
case V_55 :
V_4 -> V_7 . V_289 = F_64 ;
break;
case V_50 :
V_4 -> V_7 . V_289 =
F_66 ;
break;
default:
V_4 -> V_7 . V_289 =
F_61 ;
break;
}
V_4 -> V_7 . V_290 =
V_291 ;
break;
case V_9 :
V_4 -> V_7 . V_287 = F_67 ;
V_4 -> V_7 . V_281 = V_292 ;
V_4 -> V_7 . V_293 = F_68 ;
return;
case V_294 :
if ( V_2 -> V_49 == V_295 ||
V_2 -> V_49 == V_296 )
V_4 -> V_7 . V_287 = F_70 ;
break;
default:
break;
}
}
static T_1 F_73 ( struct V_1 * V_2 )
{
T_1 V_25 ;
bool V_214 ;
V_25 = F_60 ( V_2 , & V_214 ) ;
if ( V_25 )
return V_25 ;
F_72 ( V_2 ) ;
V_2 -> V_6 . V_7 . V_297 = NULL ;
return 0 ;
}
static T_1 F_74 ( struct V_1 * V_2 ,
T_6 * V_182 ,
bool * V_298 )
{
if ( V_2 -> V_6 . V_299 == V_283 ) {
* V_298 = false ;
if ( V_2 -> V_6 . V_215 == V_224 ||
V_2 -> V_6 . V_215 == V_225 ) {
* V_182 = V_202 ;
return 0 ;
}
if ( V_2 -> V_6 . V_300 )
* V_182 = V_200 |
V_202 ;
else
* V_182 = V_200 ;
} else {
* V_182 = V_200 |
V_202 ;
* V_298 = true ;
}
return 0 ;
}
static T_1 F_75 ( struct V_1 * V_2 , bool * V_301 )
{
T_2 V_25 ;
T_3 V_20 ;
* V_301 = false ;
V_25 = V_2 -> V_6 . V_7 . V_259 ( V_2 , V_302 ,
V_303 ,
& V_20 ) ;
if ( V_25 || ! ( V_20 & V_304 ) )
return V_25 ;
V_25 = V_2 -> V_6 . V_7 . V_259 ( V_2 , V_305 ,
V_303 ,
& V_20 ) ;
if ( V_25 || ! ( V_20 & ( V_306 |
V_307 ) ) )
return V_25 ;
V_25 = V_2 -> V_6 . V_7 . V_259 ( V_2 , V_308 ,
V_303 ,
& V_20 ) ;
if ( V_25 )
return V_25 ;
if ( V_20 & V_309 ) {
F_76 ( V_2 , false ) ;
return V_310 ;
}
if ( V_20 & V_311 ) {
V_25 = V_2 -> V_6 . V_7 . V_259 ( V_2 , V_312 ,
V_303 ,
& V_20 ) ;
if ( V_25 )
return V_25 ;
if ( V_20 == V_313 ) {
F_76 ( V_2 , false ) ;
return V_310 ;
}
}
V_25 = V_2 -> V_6 . V_7 . V_259 ( V_2 , V_302 ,
V_273 , & V_20 ) ;
if ( V_25 || ! ( V_20 & V_314 ) )
return V_25 ;
V_25 = V_2 -> V_6 . V_7 . V_259 ( V_2 , V_315 ,
V_273 , & V_20 ) ;
if ( V_25 )
return V_25 ;
if ( V_20 & V_316 )
* V_301 = true ;
return 0 ;
}
static T_1 F_77 ( struct V_1 * V_2 )
{
T_2 V_25 ;
T_3 V_20 ;
bool V_301 ;
V_25 = F_75 ( V_2 , & V_301 ) ;
V_25 = V_2 -> V_6 . V_7 . V_259 ( V_2 , V_317 ,
V_273 , & V_20 ) ;
if ( V_25 )
return V_25 ;
V_20 |= V_318 ;
V_25 = V_2 -> V_6 . V_7 . V_264 ( V_2 , V_317 ,
V_273 , V_20 ) ;
if ( V_25 )
return V_25 ;
V_25 = V_2 -> V_6 . V_7 . V_259 ( V_2 , V_319 ,
V_303 ,
& V_20 ) ;
if ( V_25 )
return V_25 ;
V_20 |= ( V_320 |
V_321 ) ;
V_25 = V_2 -> V_6 . V_7 . V_264 ( V_2 , V_319 ,
V_303 ,
V_20 ) ;
if ( V_25 )
return V_25 ;
V_25 = V_2 -> V_6 . V_7 . V_259 ( V_2 , V_322 ,
V_303 ,
& V_20 ) ;
if ( V_25 )
return V_25 ;
V_20 |= ( V_306 |
V_307 ) ;
V_25 = V_2 -> V_6 . V_7 . V_264 ( V_2 , V_322 ,
V_303 ,
V_20 ) ;
if ( V_25 )
return V_25 ;
V_25 = V_2 -> V_6 . V_7 . V_259 ( V_2 , V_323 ,
V_303 ,
& V_20 ) ;
if ( V_25 )
return V_25 ;
V_20 |= V_304 ;
V_25 = V_2 -> V_6 . V_7 . V_264 ( V_2 , V_323 ,
V_303 ,
V_20 ) ;
return V_25 ;
}
static T_1 F_78 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
bool V_301 ;
T_2 V_25 ;
V_25 = F_75 ( V_2 , & V_301 ) ;
if ( V_25 )
return V_25 ;
if ( V_301 && V_6 -> V_7 . V_324 )
return V_6 -> V_7 . V_324 ( V_2 ) ;
return 0 ;
}
static T_1 F_63 ( struct V_1 * V_2 ,
T_6 V_182 )
{
T_1 V_25 ;
T_2 V_196 ;
V_25 = V_2 -> V_4 . V_7 . V_248 ( V_2 ,
F_55 ( V_2 -> V_13 . V_14 ) ,
V_197 , & V_196 ) ;
if ( V_25 )
return V_25 ;
V_196 |= V_198 ;
V_196 &= ~ ( V_325 |
V_326 ) ;
V_196 &= ~ ( V_327 |
V_328 ) ;
if ( V_182 & V_200 )
V_196 |= V_327 ;
if ( V_182 & V_202 )
V_196 |= V_328 ;
V_196 |= V_213 ;
V_25 = V_2 -> V_4 . V_7 . V_251 ( V_2 ,
F_55 ( V_2 -> V_13 . V_14 ) ,
V_197 , V_196 ) ;
return V_25 ;
}
static T_1 F_79 ( struct V_1 * V_2 )
{
T_1 V_25 ;
T_2 V_196 ;
V_25 = V_2 -> V_4 . V_7 . V_248 ( V_2 , V_329 ,
V_330 +
V_2 -> V_13 . V_14 , & V_196 ) ;
if ( V_25 )
return V_25 ;
V_196 &= ~ ( V_331 |
V_332 ) ;
V_196 |= V_333 ;
if ( V_2 -> V_6 . V_334 & V_200 )
V_196 |= V_331 ;
if ( V_2 -> V_6 . V_334 & V_202 )
V_196 |= V_332 ;
V_196 |= V_335 ;
V_25 = V_2 -> V_4 . V_7 . V_251 ( V_2 , V_329 ,
V_330 +
V_2 -> V_13 . V_14 , V_196 ) ;
return V_25 ;
}
static T_1 F_80 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 . type != V_336 )
return 0 ;
return F_63 ( V_2 , V_2 -> V_6 . V_334 ) ;
}
static T_1 F_81 ( struct V_1 * V_2 , bool * V_268 )
{
T_2 V_86 ;
T_3 V_270 ;
* V_268 = false ;
V_86 = V_2 -> V_6 . V_7 . V_259 ( V_2 , V_272 ,
V_273 ,
& V_270 ) ;
if ( V_86 )
return V_86 ;
V_86 = V_2 -> V_6 . V_7 . V_259 ( V_2 , V_272 ,
V_273 ,
& V_270 ) ;
if ( V_86 )
return V_86 ;
* V_268 = ! ! ( V_270 & V_274 ) ;
return 0 ;
}
static T_1 F_82 ( struct V_1 * V_2 )
{
T_6 V_266 ;
bool V_268 ;
T_2 V_25 ;
T_3 V_182 ;
if ( V_2 -> V_4 . V_7 . V_8 ( V_2 ) != V_9 )
return V_271 ;
if ( V_2 -> V_6 . V_235 & V_236 ) {
V_182 = V_200 |
V_202 ;
return F_63 ( V_2 , V_182 ) ;
}
V_25 = F_81 ( V_2 , & V_268 ) ;
if ( V_25 )
return V_25 ;
if ( ! V_268 )
return 0 ;
V_25 = V_2 -> V_6 . V_7 . V_259 ( V_2 , V_337 ,
V_273 ,
& V_182 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_81 ( V_2 , & V_268 ) ;
if ( V_25 )
return V_25 ;
if ( ! V_268 )
return 0 ;
V_182 &= V_338 ;
switch ( V_182 ) {
case V_339 :
V_266 = V_200 ;
break;
case V_340 :
V_266 = V_202 ;
break;
default:
return V_341 ;
}
return F_54 ( V_2 , & V_266 ) ;
}
static T_1 F_83 ( struct V_1 * V_2 )
{
T_1 V_25 ;
V_25 = F_84 ( V_2 ) ;
if ( V_25 )
return V_25 ;
return F_77 ( V_2 ) ;
}
static T_1 F_85 ( struct V_1 * V_2 , T_2 V_342 )
{
T_3 V_67 ;
if ( V_342 >= V_343 )
return V_151 ;
V_2 -> V_6 . V_7 . V_259 ( V_2 , V_344 + V_342 ,
V_303 , & V_67 ) ;
V_67 |= V_345 ;
V_2 -> V_6 . V_7 . V_264 ( V_2 , V_344 + V_342 ,
V_303 , V_67 ) ;
return 0 ;
}
static T_1 F_86 ( struct V_1 * V_2 , T_2 V_342 )
{
T_3 V_67 ;
if ( V_342 >= V_343 )
return V_151 ;
V_2 -> V_6 . V_7 . V_259 ( V_2 , V_344 + V_342 ,
V_303 , & V_67 ) ;
V_67 &= ~ V_345 ;
V_2 -> V_6 . V_7 . V_264 ( V_2 , V_344 + V_342 ,
V_303 , V_67 ) ;
return 0 ;
}
static T_1 F_87 ( struct V_1 * V_2 ,
T_6 * V_346 )
{
T_3 V_347 ;
T_1 V_25 ;
T_3 V_348 = V_2 -> V_47 . V_349 ;
* V_346 = V_350 ;
V_25 = V_2 -> V_6 . V_7 . V_259 ( V_2 , V_351 ,
V_273 ,
& V_347 ) ;
if ( V_25 )
return V_25 ;
if ( V_347 & V_352 ) {
* V_346 = V_202 ;
return V_25 ;
}
if ( ( V_2 -> V_13 . V_14 && ( V_348 & V_353 ) ) ||
( V_348 & V_354 ) )
return V_25 ;
* V_346 = V_200 ;
return V_25 ;
}
static T_1 V_282 ( struct V_1 * V_2 )
{
bool V_355 , V_356 ;
T_2 V_196 ;
T_1 V_247 ;
if ( V_2 -> V_357 . V_358 && V_2 -> V_357 . V_359 == V_360 ) {
F_11 ( V_2 , L_22 ) ;
return V_341 ;
}
if ( V_2 -> V_357 . V_359 == V_361 )
V_2 -> V_357 . V_359 = V_362 ;
switch ( V_2 -> V_357 . V_359 ) {
case V_363 :
V_355 = false ;
V_356 = false ;
break;
case V_364 :
V_355 = false ;
V_356 = true ;
break;
case V_360 :
case V_362 :
V_355 = true ;
V_356 = true ;
break;
default:
F_11 ( V_2 , L_23 ) ;
return V_271 ;
}
if ( V_2 -> V_49 != V_58 &&
V_2 -> V_49 != V_59 &&
V_2 -> V_49 != V_60 )
return 0 ;
V_247 = V_2 -> V_4 . V_7 . V_248 ( V_2 ,
F_88 ( V_2 -> V_13 . V_14 ) ,
V_197 ,
& V_196 ) ;
if ( V_247 )
return V_247 ;
V_196 &= ~ ( V_365 |
V_366 ) ;
if ( V_355 )
V_196 |= V_365 ;
if ( V_356 )
V_196 |= V_366 ;
V_247 = V_2 -> V_4 . V_7 . V_251 ( V_2 ,
F_88 ( V_2 -> V_13 . V_14 ) ,
V_197 ,
V_196 ) ;
V_2 -> V_357 . V_367 = true ;
return V_247 ;
}
static T_1 F_89 ( struct V_1 * V_2 )
{
T_3 V_368 , V_369 , V_182 ;
T_1 V_25 ;
T_6 V_346 ;
T_2 V_370 ;
bool V_268 ;
if ( F_90 ( V_2 ) )
return 0 ;
V_25 = F_81 ( V_2 , & V_268 ) ;
if ( V_25 )
return V_25 ;
V_25 = V_2 -> V_47 . V_7 . V_170 ( V_2 , V_371 ,
& V_2 -> V_47 . V_349 ) ;
if ( V_25 )
return V_25 ;
if ( ! V_268 || ! ( V_2 -> V_47 . V_349 & V_372 ) ||
! ( V_2 -> V_373 || F_91 ( V_2 ) ) )
return F_76 ( V_2 , false ) ;
V_25 = F_87 ( V_2 , & V_346 ) ;
if ( V_25 )
return V_25 ;
if ( V_346 == V_350 )
return F_76 ( V_2 , false ) ;
V_25 = V_2 -> V_6 . V_7 . V_259 ( V_2 , V_337 ,
V_273 ,
& V_182 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_81 ( V_2 , & V_268 ) ;
if ( V_25 )
return F_76 ( V_2 , false ) ;
V_182 &= V_374 ;
if ( ( ( V_182 == V_375 ) &&
( V_346 == V_202 ) ) ||
( ( V_182 == V_376 ) &&
( V_346 == V_200 ) ) )
return V_25 ;
V_25 = V_2 -> V_6 . V_7 . V_259 ( V_2 , V_377 ,
V_273 ,
& V_369 ) ;
if ( V_25 )
return V_25 ;
V_25 = V_2 -> V_6 . V_7 . V_259 ( V_2 , V_378 ,
V_273 ,
& V_368 ) ;
if ( V_25 )
return V_25 ;
V_25 = V_2 -> V_6 . V_7 . V_259 ( V_2 ,
V_379 ,
V_273 ,
& V_369 ) ;
if ( V_25 )
return V_25 ;
V_370 = V_2 -> V_6 . V_334 ;
V_25 = V_2 -> V_4 . V_7 . V_287 ( V_2 , V_346 , false ) ;
V_2 -> V_6 . V_334 = V_370 ;
return V_25 ;
}
static void F_92 ( struct V_1 * V_2 )
{
V_2 -> V_6 . V_235 = F_4 ( V_2 , V_380 ) ;
if ( V_2 -> V_4 . type == V_381 &&
V_2 -> V_6 . V_235 & V_382 ) {
V_2 -> V_6 . V_255 . V_256 = ( V_2 -> V_6 . V_235 &
V_383 ) >>
V_384 ;
}
}
static T_1 F_93 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_385 ;
V_2 -> V_4 . V_7 . V_184 ( V_2 ) ;
F_92 ( V_2 ) ;
if ( V_2 -> V_4 . V_7 . V_8 ( V_2 ) == V_283 ) {
V_6 -> V_40 = V_54 ;
F_3 ( V_2 ) ;
}
V_385 = V_6 -> V_7 . V_386 ( V_2 ) ;
F_72 ( V_2 ) ;
if ( V_6 -> V_215 != V_228 )
V_6 -> V_7 . V_297 = NULL ;
switch ( V_2 -> V_6 . type ) {
case V_57 :
V_6 -> V_7 . V_287 = F_79 ;
V_6 -> V_7 . V_259 = F_21 ;
V_6 -> V_7 . V_264 = F_22 ;
break;
case V_61 :
V_6 -> V_7 . V_287 = F_80 ;
V_6 -> V_7 . V_259 = F_21 ;
V_6 -> V_7 . V_264 = F_22 ;
break;
case V_387 :
V_6 -> V_235 = F_4 ( V_2 , V_380 ) ;
V_6 -> V_7 . V_324 =
F_82 ;
if ( V_2 -> V_4 . type == V_336 &&
! ( F_4 ( V_2 , F_94 ( 0 ) ) &
V_388 ) )
V_6 -> V_7 . V_389 = F_89 ;
V_6 -> V_7 . V_390 = F_78 ;
V_6 -> V_7 . V_297 = F_83 ;
break;
default:
break;
}
return V_385 ;
}
static enum V_391 F_95 ( struct V_1 * V_2 )
{
enum V_391 V_299 ;
switch ( V_2 -> V_49 ) {
case V_295 :
case V_296 :
V_2 -> V_6 . type = V_392 ;
case V_58 :
case V_56 :
case V_59 :
case V_60 :
V_299 = V_294 ;
break;
case V_53 :
case V_50 :
case V_55 :
V_299 = V_283 ;
break;
case V_63 :
case V_64 :
case V_62 :
V_299 = V_9 ;
break;
default:
V_299 = V_393 ;
break;
}
return V_299 ;
}
static T_1 F_96 ( struct V_1 * V_2 )
{
T_1 V_25 ;
T_3 V_20 ;
V_25 = V_2 -> V_6 . V_7 . V_259 ( V_2 ,
V_394 ,
V_395 ,
& V_20 ) ;
if ( V_25 )
return V_25 ;
if ( V_20 & V_396 ) {
V_25 = V_2 -> V_6 . V_7 . V_259 ( V_2 ,
V_397 ,
V_303 ,
& V_20 ) ;
if ( V_25 )
return V_25 ;
V_20 &= ~ V_398 ;
V_25 = V_2 -> V_6 . V_7 . V_264 ( V_2 ,
V_397 ,
V_303 ,
V_20 ) ;
if ( V_25 )
return V_25 ;
}
return V_25 ;
}
static void F_97 ( struct V_1 * V_2 )
{
T_2 V_399 ;
switch ( V_2 -> V_49 ) {
case V_64 :
case V_295 :
case V_296 :
case V_62 :
case V_50 :
V_399 = F_4 ( V_2 , V_400 ) ;
V_399 &= ~ V_401 ;
F_5 ( V_2 , V_400 , V_399 ) ;
break;
default:
break;
}
}
static T_1 F_98 ( struct V_1 * V_2 )
{
T_6 V_402 ;
T_1 V_25 ;
T_2 V_78 = 0 ;
T_2 V_79 ;
bool V_268 = false ;
V_25 = V_2 -> V_4 . V_7 . V_403 ( V_2 ) ;
if ( V_25 )
return V_25 ;
F_99 ( V_2 ) ;
V_25 = V_2 -> V_6 . V_7 . V_404 ( V_2 ) ;
if ( V_2 -> V_6 . type == V_387 ) {
V_25 = F_96 ( V_2 ) ;
if ( V_25 )
return V_25 ;
}
if ( V_2 -> V_6 . V_405 ) {
V_25 = V_2 -> V_4 . V_7 . V_406 ( V_2 ) ;
V_2 -> V_6 . V_405 = false ;
}
if ( ! V_2 -> V_6 . V_407 && V_2 -> V_6 . V_7 . V_297 )
V_2 -> V_6 . V_7 . V_297 ( V_2 ) ;
V_408:
V_78 = V_409 ;
if ( ! V_2 -> V_410 ) {
V_2 -> V_4 . V_7 . V_293 ( V_2 , & V_402 , & V_268 , false ) ;
if ( V_268 )
V_78 = V_411 ;
}
V_78 |= F_4 ( V_2 , V_412 ) ;
F_5 ( V_2 , V_412 , V_78 ) ;
F_6 ( V_2 ) ;
F_15 ( 1000 , 1200 ) ;
for ( V_79 = 0 ; V_79 < 10 ; V_79 ++ ) {
V_78 = F_4 ( V_2 , V_412 ) ;
if ( ! ( V_78 & V_413 ) )
break;
F_28 ( 1 ) ;
}
if ( V_78 & V_413 ) {
V_25 = V_414 ;
F_26 ( V_2 , L_24 ) ;
}
F_16 ( 50 ) ;
if ( V_2 -> V_4 . V_415 & V_416 ) {
V_2 -> V_4 . V_415 &= ~ V_416 ;
goto V_408;
}
V_2 -> V_4 . V_7 . V_417 ( V_2 , V_2 -> V_4 . V_418 ) ;
V_2 -> V_4 . V_419 = 128 ;
V_2 -> V_4 . V_7 . V_420 ( V_2 ) ;
F_97 ( V_2 ) ;
if ( V_2 -> V_49 == V_53 )
F_3 ( V_2 ) ;
return V_25 ;
}
static void F_100 ( struct V_1 * V_2 ,
bool V_421 , int V_422 )
{
int V_423 = V_422 >> 3 ;
int V_424 = V_422 % 8 + V_425 ;
T_2 V_426 ;
V_426 = F_4 ( V_2 , F_101 ( V_423 ) ) ;
if ( V_421 )
V_426 |= F_25 ( V_424 ) ;
else
V_426 &= ~ F_25 ( V_424 ) ;
F_5 ( V_2 , F_101 ( V_423 ) , V_426 ) ;
}
static void F_102 ( struct V_1 * V_2 ,
bool V_421 ,
unsigned int V_427 )
{
T_7 V_428 ;
if ( V_427 > 63 )
return;
V_428 = ( T_7 ) F_4 ( V_2 , V_429 ) ;
V_428 |= ( T_7 ) F_4 ( V_2 , V_430 ) << 32 ;
if ( V_421 )
V_428 |= ( 1ULL << V_427 ) ;
else
V_428 &= ~ ( 1ULL << V_427 ) ;
F_5 ( V_2 , V_429 , ( T_2 ) V_428 ) ;
F_5 ( V_2 , V_430 , ( T_2 ) ( V_428 >> 32 ) ) ;
}
static void F_103 ( struct V_1 * V_2 , T_4 V_431 )
{
T_2 V_11 ;
if ( ! V_2 -> V_13 . V_14 )
return;
V_11 = F_4 ( V_2 , V_12 ) ;
if ( V_431 )
V_11 |= V_16 ;
else
V_11 &= ~ V_16 ;
F_5 ( V_2 , V_12 , V_11 ) ;
F_6 ( V_2 ) ;
}
static T_1 F_104 ( struct V_1 * V_2 , T_2 V_432 )
{
T_1 V_25 ;
V_25 = F_105 ( V_2 , V_432 ) ;
if ( V_25 )
return V_25 ;
if ( V_432 & V_433 )
F_103 ( V_2 , 1 ) ;
return 0 ;
}
static void F_106 ( struct V_1 * V_2 , T_2 V_432 )
{
if ( V_432 & V_433 )
F_103 ( V_2 , 0 ) ;
F_107 ( V_2 , V_432 ) ;
}
static T_1 F_108 ( struct V_1 * V_2 , T_2 V_432 )
{
T_2 V_434 = V_432 & ~ V_435 ;
int V_436 = V_437 ;
T_1 V_25 ;
while ( -- V_436 ) {
V_25 = 0 ;
if ( V_434 )
V_25 = F_105 ( V_2 , V_434 ) ;
if ( V_25 )
return V_25 ;
if ( ! ( V_432 & V_435 ) )
return 0 ;
V_25 = F_30 ( V_2 ) ;
if ( ! V_25 )
return 0 ;
if ( V_434 )
F_107 ( V_2 , V_434 ) ;
if ( V_25 != V_113 )
return V_25 ;
F_16 ( V_438 ) ;
}
return V_25 ;
}
static void F_109 ( struct V_1 * V_2 , T_2 V_432 )
{
T_2 V_434 = V_432 & ~ V_435 ;
if ( V_432 & V_435 )
F_32 ( V_2 ) ;
if ( V_434 )
F_107 ( V_2 , V_434 ) ;
}
static T_1 F_110 ( struct V_1 * V_2 , T_2 V_65 ,
T_2 V_66 , T_3 * V_67 )
{
T_2 V_432 = V_2 -> V_6 . V_40 | V_435 ;
T_1 V_25 ;
if ( V_2 -> V_4 . V_7 . V_41 ( V_2 , V_432 ) )
return V_167 ;
V_25 = V_2 -> V_6 . V_7 . V_439 ( V_2 , V_65 , V_66 , V_67 ) ;
V_2 -> V_4 . V_7 . V_46 ( V_2 , V_432 ) ;
return V_25 ;
}
static T_1 F_111 ( struct V_1 * V_2 , T_2 V_65 ,
T_2 V_66 , T_3 V_67 )
{
T_2 V_432 = V_2 -> V_6 . V_40 | V_435 ;
T_1 V_25 ;
if ( V_2 -> V_4 . V_7 . V_41 ( V_2 , V_432 ) )
return V_167 ;
V_25 = F_112 ( V_2 , V_65 , V_66 , V_67 ) ;
V_2 -> V_4 . V_7 . V_46 ( V_2 , V_432 ) ;
return V_25 ;
}
