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
case V_63 :
return F_20 ( V_2 ) ;
default:
break;
}
return 0 ;
}
static T_1 F_21 ( struct V_1 * V_2 , T_2 V_64 ,
T_2 V_65 , T_3 * V_66 )
{
return V_67 ;
}
static T_1 F_22 ( struct V_1 * V_2 , T_2 V_64 ,
T_2 V_65 , T_3 V_66 )
{
return V_67 ;
}
static T_1 F_23 ( struct V_1 * V_2 )
{
struct V_68 * V_47 = & V_2 -> V_47 ;
T_2 V_69 ;
T_3 V_70 ;
if ( V_47 -> type == V_71 ) {
V_47 -> V_48 = 10 ;
V_47 -> type = V_72 ;
V_69 = F_4 ( V_2 , F_24 ( V_2 ) ) ;
V_70 = ( T_3 ) ( ( V_69 & V_73 ) >>
V_74 ) ;
V_47 -> V_75 = F_25 ( V_70 +
V_76 ) ;
F_26 ( V_2 , L_7 ,
V_47 -> type , V_47 -> V_75 ) ;
}
return 0 ;
}
static T_1 F_27 ( struct V_1 * V_2 , T_2 * V_77 )
{
T_2 V_78 , V_79 ;
for ( V_78 = 0 ; V_78 < V_80 ; V_78 ++ ) {
V_79 = F_4 ( V_2 , V_81 ) ;
if ( ! ( V_79 & V_82 ) )
break;
F_28 ( 10 ) ;
}
if ( V_77 )
* V_77 = V_79 ;
if ( V_78 == V_80 ) {
F_26 ( V_2 , L_8 ) ;
return V_37 ;
}
return 0 ;
}
static T_1 F_29 ( struct V_1 * V_2 , T_2 V_64 ,
T_2 V_65 , T_2 * V_83 )
{
T_2 V_84 = V_51 | V_52 ;
T_2 V_79 , error ;
T_1 V_85 ;
V_85 = V_2 -> V_4 . V_7 . V_41 ( V_2 , V_84 ) ;
if ( V_85 )
return V_85 ;
V_85 = F_27 ( V_2 , NULL ) ;
if ( V_85 )
goto V_44;
V_79 = ( ( V_64 << V_86 ) |
( V_65 << V_87 ) ) ;
F_5 ( V_2 , V_81 , V_79 ) ;
V_85 = F_27 ( V_2 , & V_79 ) ;
if ( ( V_79 & V_88 ) != 0 ) {
error = ( V_79 & V_89 ) >>
V_90 ;
F_26 ( V_2 , L_9 , error ) ;
return V_37 ;
}
if ( ! V_85 )
* V_83 = F_4 ( V_2 , V_91 ) ;
V_44:
V_2 -> V_4 . V_7 . V_46 ( V_2 , V_84 ) ;
return V_85 ;
}
static T_1 F_30 ( struct V_1 * V_2 )
{
struct V_92 V_93 ;
T_1 V_25 ;
V_93 . V_94 . V_95 = V_96 ;
V_93 . V_94 . V_97 = V_98 ;
V_93 . V_94 . V_99 . V_100 = 0 ;
V_93 . V_94 . V_101 = V_102 ;
V_93 . V_103 = V_2 -> V_13 . V_14 ;
V_93 . V_104 = V_105 ;
V_93 . V_106 = 0 ;
V_25 = F_31 ( V_2 , & V_93 , sizeof( V_93 ) ,
V_107 ,
true ) ;
if ( V_25 )
return V_25 ;
if ( V_93 . V_94 . V_99 . V_108 == V_109 )
return 0 ;
if ( V_93 . V_94 . V_99 . V_108 != V_110 )
return V_111 ;
return V_112 ;
}
static T_1 F_32 ( struct V_1 * V_2 )
{
struct V_92 V_93 ;
T_1 V_25 ;
V_93 . V_94 . V_95 = V_96 ;
V_93 . V_94 . V_97 = V_98 ;
V_93 . V_94 . V_99 . V_100 = 0 ;
V_93 . V_94 . V_101 = V_102 ;
V_93 . V_103 = V_2 -> V_13 . V_14 ;
V_93 . V_104 = V_113 ;
V_93 . V_106 = 0 ;
V_25 = F_31 ( V_2 , & V_93 , sizeof( V_93 ) ,
V_107 ,
true ) ;
if ( V_25 )
return V_25 ;
if ( V_93 . V_94 . V_99 . V_108 == V_109 )
return 0 ;
return V_111 ;
}
static T_1 F_33 ( struct V_1 * V_2 , T_2 V_64 ,
T_5 T_2 V_65 ,
T_2 V_83 )
{
struct V_114 V_115 ;
memset ( & V_115 , 0 , sizeof( V_115 ) ) ;
V_115 . V_94 . V_95 = V_116 ;
V_115 . V_94 . V_97 = V_117 ;
V_115 . V_94 . V_101 = V_102 ;
V_115 . V_103 = V_2 -> V_13 . V_14 ;
V_115 . V_104 = V_118 ;
V_115 . V_119 = F_34 ( V_64 ) ;
V_115 . V_120 = F_35 ( V_83 ) ;
return F_31 ( V_2 , & V_115 , sizeof( V_115 ) ,
V_107 , false ) ;
}
static T_1 F_36 ( struct V_1 * V_2 , T_2 V_64 ,
T_5 T_2 V_65 ,
T_2 * V_83 )
{
union {
struct V_114 V_95 ;
struct V_121 V_122 ;
} V_123 ;
T_1 V_25 ;
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
V_123 . V_95 . V_94 . V_95 = V_116 ;
V_123 . V_95 . V_94 . V_97 = V_117 ;
V_123 . V_95 . V_94 . V_101 = V_102 ;
V_123 . V_95 . V_103 = V_2 -> V_13 . V_14 ;
V_123 . V_95 . V_104 = V_124 ;
V_123 . V_95 . V_119 = F_34 ( V_64 ) ;
V_25 = F_31 ( V_2 , & V_123 . V_95 , sizeof( V_123 . V_95 ) ,
V_107 , true ) ;
* V_83 = F_37 ( V_123 . V_122 . V_125 ) ;
return V_25 ;
}
static T_1 F_38 ( struct V_1 * V_2 , T_3 V_126 ,
T_3 * V_83 )
{
T_1 V_25 ;
struct V_127 V_128 ;
V_128 . V_94 . V_129 . V_95 = V_130 ;
V_128 . V_94 . V_129 . V_131 = 0 ;
V_128 . V_94 . V_129 . V_132 = V_133 ;
V_128 . V_94 . V_129 . V_101 = V_102 ;
V_128 . V_119 = F_35 ( V_126 * 2 ) ;
V_128 . V_134 = F_34 ( sizeof( T_3 ) ) ;
V_25 = F_31 ( V_2 , & V_128 , sizeof( V_128 ) ,
V_107 , false ) ;
if ( V_25 )
return V_25 ;
* V_83 = ( T_3 ) F_39 ( V_2 , V_135 ,
V_136 ) ;
return 0 ;
}
static T_1 F_40 ( struct V_1 * V_2 ,
T_3 V_126 , T_3 V_137 , T_3 * V_83 )
{
struct V_127 V_128 ;
T_2 V_138 = 0 ;
T_3 V_139 ;
T_1 V_25 ;
T_2 V_78 ;
V_25 = V_2 -> V_4 . V_7 . V_41 ( V_2 , V_140 ) ;
if ( V_25 ) {
F_26 ( V_2 , L_10 ) ;
return V_25 ;
}
while ( V_137 ) {
if ( V_137 > V_141 / 2 )
V_139 = V_141 / 2 ;
else
V_139 = V_137 ;
V_128 . V_94 . V_129 . V_95 = V_130 ;
V_128 . V_94 . V_129 . V_131 = 0 ;
V_128 . V_94 . V_129 . V_132 = V_133 ;
V_128 . V_94 . V_129 . V_101 = V_102 ;
V_128 . V_119 = F_35 ( ( V_126 + V_138 ) * 2 ) ;
V_128 . V_134 = F_34 ( V_139 * 2 ) ;
V_25 = F_31 ( V_2 , & V_128 ,
sizeof( V_128 ) ,
V_107 ,
false ) ;
if ( V_25 ) {
F_26 ( V_2 , L_11 ) ;
goto V_44;
}
for ( V_78 = 0 ; V_78 < V_139 ; V_78 ++ ) {
T_2 V_20 = V_135 + ( V_136 << 2 ) +
2 * V_78 ;
T_2 V_21 = F_4 ( V_2 , V_20 ) ;
V_83 [ V_138 ] = ( T_3 ) ( V_21 & 0xffff ) ;
V_138 ++ ;
V_78 ++ ;
if ( V_78 < V_139 ) {
V_21 >>= 16 ;
V_83 [ V_138 ] = ( T_3 ) ( V_21 & 0xffff ) ;
V_138 ++ ;
}
}
V_137 -= V_139 ;
}
V_44:
V_2 -> V_4 . V_7 . V_46 ( V_2 , V_140 ) ;
return V_25 ;
}
static T_1 F_41 ( struct V_1 * V_2 , T_3 V_142 ,
T_3 V_143 , T_3 * V_144 , T_3 * V_128 ,
T_2 V_145 )
{
T_3 V_146 [ 256 ] ;
T_1 V_25 ;
T_3 V_134 , V_147 , V_78 , V_148 ;
T_3 * V_149 ;
V_147 = sizeof( V_146 ) / sizeof( V_146 [ 0 ] ) ;
if ( ! V_128 ) {
V_25 = F_40 ( V_2 , V_142 , V_147 , V_146 ) ;
if ( V_25 ) {
F_26 ( V_2 , L_12 ) ;
return V_25 ;
}
V_149 = V_146 ;
} else {
if ( V_145 < V_142 )
return V_150 ;
V_149 = & V_128 [ V_142 ] ;
}
if ( V_143 ) {
V_148 = 0 ;
V_134 = V_143 ;
} else {
V_148 = 1 ;
V_134 = V_149 [ 0 ] ;
if ( V_134 == 0xFFFF || V_134 == 0 ||
( V_142 + V_134 ) >= V_2 -> V_47 . V_75 )
return 0 ;
}
if ( V_128 && ( ( T_2 ) V_148 + ( T_2 ) V_134 > V_145 ) )
return V_150 ;
for ( V_78 = V_148 ; V_134 ; V_78 ++ , V_134 -- ) {
if ( V_78 == V_147 && ! V_128 ) {
V_142 += V_147 ;
V_78 = 0 ;
if ( V_134 < V_147 )
V_147 = V_134 ;
V_25 = F_40 ( V_2 , V_142 ,
V_147 , V_146 ) ;
if ( V_25 ) {
F_26 ( V_2 , L_12 ) ;
return V_25 ;
}
}
* V_144 += V_149 [ V_78 ] ;
}
return 0 ;
}
static T_1 F_42 ( struct V_1 * V_2 , T_3 * V_128 ,
T_2 V_145 )
{
T_3 V_151 [ V_152 + 1 ] ;
T_3 * V_149 ;
T_1 V_25 ;
T_3 V_101 = 0 ;
T_3 V_153 , V_78 , V_143 ;
V_2 -> V_47 . V_7 . V_154 ( V_2 ) ;
if ( ! V_128 ) {
V_25 = F_40 ( V_2 , 0 ,
V_152 + 1 ,
V_151 ) ;
if ( V_25 ) {
F_26 ( V_2 , L_12 ) ;
return V_25 ;
}
V_149 = V_151 ;
} else {
if ( V_145 < V_152 )
return V_150 ;
V_149 = V_128 ;
}
for ( V_78 = 0 ; V_78 <= V_152 ; V_78 ++ )
if ( V_78 != V_155 )
V_101 += V_149 [ V_78 ] ;
for ( V_78 = V_156 ; V_78 < V_157 ; V_78 ++ ) {
if ( V_78 == V_158 || V_78 == V_159 )
continue;
V_153 = V_149 [ V_78 ] ;
if ( V_153 == 0xFFFF || V_153 == 0 ||
V_153 >= V_2 -> V_47 . V_75 )
continue;
switch ( V_78 ) {
case V_160 :
V_143 = V_161 ;
break;
case V_162 :
case V_163 :
V_143 = V_164 ;
break;
default:
V_143 = 0 ;
break;
}
V_25 = F_41 ( V_2 , V_153 , V_143 , & V_101 ,
V_128 , V_145 ) ;
if ( V_25 )
return V_25 ;
}
V_101 = ( T_3 ) V_165 - V_101 ;
return ( T_1 ) V_101 ;
}
static T_1 F_43 ( struct V_1 * V_2 )
{
return F_42 ( V_2 , NULL , 0 ) ;
}
static T_1 F_44 ( struct V_1 * V_2 , T_3 V_126 , T_3 * V_83 )
{
T_1 V_25 = 0 ;
if ( V_2 -> V_4 . V_7 . V_41 ( V_2 , V_140 ) == 0 ) {
V_25 = F_38 ( V_2 , V_126 , V_83 ) ;
V_2 -> V_4 . V_7 . V_46 ( V_2 , V_140 ) ;
} else {
V_25 = V_166 ;
}
return V_25 ;
}
static T_1 F_45 ( struct V_1 * V_2 ,
T_3 * V_167 )
{
T_1 V_25 ;
T_3 V_101 ;
T_3 V_168 = 0 ;
V_25 = V_2 -> V_47 . V_7 . V_169 ( V_2 , 0 , & V_101 ) ;
if ( V_25 ) {
F_26 ( V_2 , L_13 ) ;
return V_25 ;
}
V_25 = V_2 -> V_47 . V_7 . V_170 ( V_2 ) ;
if ( V_25 < 0 )
return V_25 ;
V_101 = ( T_3 ) ( V_25 & 0xffff ) ;
V_25 = F_44 ( V_2 , V_155 ,
& V_168 ) ;
if ( V_25 )
return V_25 ;
if ( V_168 != V_101 ) {
V_25 = V_171 ;
F_26 ( V_2 , L_14 ) ;
}
if ( V_167 )
* V_167 = V_101 ;
return V_25 ;
}
static T_1 F_46 ( struct V_1 * V_2 , T_3 V_126 ,
T_3 V_83 )
{
T_1 V_25 ;
struct V_172 V_128 ;
V_128 . V_94 . V_129 . V_95 = V_173 ;
V_128 . V_94 . V_129 . V_131 = 0 ;
V_128 . V_94 . V_129 . V_132 = V_174 ;
V_128 . V_94 . V_129 . V_101 = V_102 ;
V_128 . V_134 = F_34 ( sizeof( T_3 ) ) ;
V_128 . V_83 = V_83 ;
V_128 . V_119 = F_35 ( V_126 * 2 ) ;
V_25 = F_31 ( V_2 , & V_128 , sizeof( V_128 ) ,
V_107 , false ) ;
return V_25 ;
}
static T_1 F_47 ( struct V_1 * V_2 , T_3 V_126 , T_3 V_83 )
{
T_1 V_25 = 0 ;
if ( V_2 -> V_4 . V_7 . V_41 ( V_2 , V_140 ) == 0 ) {
V_25 = F_46 ( V_2 , V_126 , V_83 ) ;
V_2 -> V_4 . V_7 . V_46 ( V_2 , V_140 ) ;
} else {
F_26 ( V_2 , L_15 ) ;
V_25 = V_166 ;
}
return V_25 ;
}
static T_1 F_48 ( struct V_1 * V_2 )
{
T_1 V_25 = 0 ;
union V_175 V_128 ;
V_128 . V_129 . V_95 = V_176 ;
V_128 . V_129 . V_131 = 0 ;
V_128 . V_129 . V_132 = V_177 ;
V_128 . V_129 . V_101 = V_102 ;
V_25 = F_31 ( V_2 , & V_128 , sizeof( V_128 ) ,
V_107 , false ) ;
return V_25 ;
}
static T_1 F_49 ( struct V_1 * V_2 )
{
V_2 -> V_13 . type = V_178 ;
V_2 -> V_13 . V_179 = V_180 ;
V_2 -> V_13 . V_181 = V_182 ;
V_2 -> V_4 . V_7 . V_183 ( V_2 ) ;
return 0 ;
}
static void F_50 ( struct V_1 * V_2 )
{
T_2 V_184 , V_185 ;
T_1 V_25 ;
struct V_186 V_187 ;
V_184 = F_4 ( V_2 , V_188 ) ;
if ( V_184 & V_189 ) {
V_185 = F_4 ( V_2 , V_190 ) ;
if ( V_185 & V_191 ) {
V_185 &= ~ V_191 ;
F_5 ( V_2 , V_190 , V_185 ) ;
V_2 -> V_4 . V_192 = true ;
} else {
V_2 -> V_4 . V_192 = false ;
}
V_187 . V_94 . V_95 = V_193 ;
V_187 . V_94 . V_97 = V_194 ;
V_187 . V_94 . V_101 = V_102 ;
V_187 . V_103 = V_2 -> V_13 . V_14 ;
V_25 = F_31 ( V_2 , & V_187 ,
sizeof( struct V_186 ) ,
V_107 , true ) ;
if ( V_25 ) {
V_184 = F_4 ( V_2 , V_188 ) ;
if ( V_184 & V_189 ) {
V_184 &= ~ V_189 ;
F_5 ( V_2 , V_188 , V_184 ) ;
}
}
}
}
static T_1 F_51 ( struct V_1 * V_2 )
{
T_1 V_25 ;
T_3 V_101 = 0 ;
V_25 = F_44 ( V_2 , 0 , & V_101 ) ;
if ( V_25 ) {
F_26 ( V_2 , L_13 ) ;
return V_25 ;
}
V_25 = F_43 ( V_2 ) ;
if ( V_25 < 0 )
return V_25 ;
V_101 = ( T_3 ) ( V_25 & 0xffff ) ;
V_25 = F_47 ( V_2 , V_155 ,
V_101 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_48 ( V_2 ) ;
return V_25 ;
}
static T_1 F_52 ( struct V_1 * V_2 ,
T_3 V_126 , T_3 V_137 ,
T_3 * V_83 )
{
T_1 V_25 = 0 ;
T_2 V_78 = 0 ;
V_25 = V_2 -> V_4 . V_7 . V_41 ( V_2 , V_140 ) ;
if ( V_25 ) {
F_26 ( V_2 , L_16 ) ;
return V_25 ;
}
for ( V_78 = 0 ; V_78 < V_137 ; V_78 ++ ) {
V_25 = F_46 ( V_2 , V_126 + V_78 ,
V_83 [ V_78 ] ) ;
if ( V_25 ) {
F_26 ( V_2 , L_17 ) ;
break;
}
}
V_2 -> V_4 . V_7 . V_46 ( V_2 , V_140 ) ;
return V_25 ;
}
static T_1 F_53 ( struct V_1 * V_2 , T_2 V_64 ,
T_2 V_65 , T_2 V_83 )
{
T_2 V_84 = V_51 | V_52 ;
T_2 V_79 , error ;
T_1 V_85 ;
V_85 = V_2 -> V_4 . V_7 . V_41 ( V_2 , V_84 ) ;
if ( V_85 )
return V_85 ;
V_85 = F_27 ( V_2 , NULL ) ;
if ( V_85 )
goto V_44;
V_79 = ( ( V_64 << V_86 ) |
( V_65 << V_87 ) ) ;
F_5 ( V_2 , V_81 , V_79 ) ;
F_5 ( V_2 , V_91 , V_83 ) ;
V_85 = F_27 ( V_2 , & V_79 ) ;
if ( ( V_79 & V_88 ) != 0 ) {
error = ( V_79 & V_89 ) >>
V_90 ;
F_26 ( V_2 , L_18 , error ) ;
return V_37 ;
}
V_44:
V_2 -> V_4 . V_7 . V_46 ( V_2 , V_84 ) ;
return V_85 ;
}
static T_1 F_54 ( struct V_1 * V_2 , T_6 * V_181 )
{
T_1 V_25 ;
T_2 V_195 ;
V_25 = F_29 ( V_2 ,
F_55 ( V_2 -> V_13 . V_14 ) ,
V_196 , & V_195 ) ;
if ( V_25 )
return V_25 ;
V_195 &= ~ V_197 ;
V_195 &= ~ V_198 ;
switch ( * V_181 ) {
case V_199 :
V_195 |= V_200 ;
break;
case V_201 :
V_195 |= V_202 ;
break;
default:
return V_203 ;
}
V_25 = F_53 ( V_2 ,
F_55 ( V_2 -> V_13 . V_14 ) ,
V_196 , V_195 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_29 ( V_2 ,
F_56 ( V_2 -> V_13 . V_14 ) ,
V_196 , & V_195 ) ;
if ( V_25 )
return V_25 ;
V_195 |= V_204 ;
V_25 = F_53 ( V_2 ,
F_56 ( V_2 -> V_13 . V_14 ) ,
V_196 , V_195 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_29 ( V_2 ,
F_57 ( V_2 -> V_13 . V_14 ) ,
V_196 , & V_195 ) ;
if ( V_25 )
return V_25 ;
V_195 &= ~ V_205 ;
V_195 &= ~ V_206 ;
V_195 &= ~ V_207 ;
V_25 = F_53 ( V_2 ,
F_57 ( V_2 -> V_13 . V_14 ) ,
V_196 , V_195 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_29 ( V_2 ,
F_58 ( V_2 -> V_13 . V_14 ) ,
V_196 , & V_195 ) ;
if ( V_25 )
return V_25 ;
V_195 &= ~ V_205 ;
V_195 &= ~ V_206 ;
V_195 &= ~ V_207 ;
V_25 = F_53 ( V_2 ,
F_58 ( V_2 -> V_13 . V_14 ) ,
V_196 , V_195 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_29 ( V_2 ,
F_59 ( V_2 -> V_13 . V_14 ) ,
V_196 , & V_195 ) ;
if ( V_25 )
return V_25 ;
V_195 |= V_208 ;
V_195 |= V_209 ;
V_195 |= V_210 ;
V_195 |= V_211 ;
V_25 = F_53 ( V_2 ,
F_59 ( V_2 -> V_13 . V_14 ) ,
V_196 , V_195 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_29 ( V_2 ,
F_55 ( V_2 -> V_13 . V_14 ) ,
V_196 , & V_195 ) ;
if ( V_25 )
return V_25 ;
V_195 |= V_212 ;
V_25 = F_53 ( V_2 ,
F_55 ( V_2 -> V_13 . V_14 ) ,
V_196 , V_195 ) ;
return V_25 ;
}
static T_1 F_60 ( struct V_1 * V_2 , bool * V_213 )
{
switch ( V_2 -> V_6 . V_214 ) {
case V_215 :
return V_216 ;
case V_217 :
case V_218 :
* V_213 = true ;
break;
case V_219 :
case V_220 :
case V_221 :
case V_222 :
case V_223 :
case V_224 :
case V_225 :
case V_226 :
* V_213 = false ;
break;
case V_227 :
case V_228 :
case V_229 :
default:
return V_230 ;
}
return 0 ;
}
static T_1
F_61 ( struct V_1 * V_2 ,
T_6 V_181 ,
T_5 bool V_231 )
{
T_1 V_25 ;
T_3 V_232 , V_21 ;
bool V_233 = false ;
V_25 = F_60 ( V_2 , & V_233 ) ;
if ( V_25 == V_216 )
return 0 ;
if ( V_25 )
return V_25 ;
if ( ! ( V_2 -> V_6 . V_234 & V_235 ) ) {
V_232 = V_236 + ( V_2 -> V_13 . V_14 << 12 ) ;
V_21 = V_237 ;
V_25 = F_62 ( V_2 , V_23 ,
V_232 , V_21 ) ;
if ( V_25 )
goto V_238;
V_232 = V_239 + ( V_2 -> V_13 . V_14 << 12 ) ;
V_21 = ( V_240 << 1 ) | 1 ;
V_25 = F_62 ( V_2 , V_23 ,
V_232 , V_21 ) ;
if ( V_25 )
goto V_238;
V_232 = V_241 + ( V_2 -> V_13 . V_14 << 12 ) ;
V_21 = V_181 & V_199 ?
V_237 : V_242 ;
V_25 = F_62 ( V_2 , V_23 ,
V_232 , V_21 ) ;
if ( V_25 )
goto V_238;
V_232 = V_243 + ( V_2 -> V_13 . V_14 << 12 ) ;
if ( V_233 )
V_21 = ( V_244 << 1 ) | 1 ;
else
V_21 = ( V_240 << 1 ) | 1 ;
V_25 = F_62 ( V_2 , V_23 ,
V_232 , V_21 ) ;
if ( V_25 )
goto V_238;
V_25 = F_54 ( V_2 , & V_181 ) ;
if ( V_25 ) {
F_26 ( V_2 , L_19 , V_25 ) ;
return V_25 ;
}
} else {
V_25 = F_63 ( V_2 , V_181 ) ;
if ( V_25 ) {
F_26 ( V_2 , L_20 , V_25 ) ;
return V_25 ;
}
V_232 = V_239 + ( V_2 -> V_13 . V_14 << 12 ) ;
if ( V_233 )
V_21 = ( V_244 << 1 ) | 1 ;
else
V_21 = ( V_240 << 1 ) | 1 ;
V_25 = F_62 ( V_2 , V_23 ,
V_232 , V_21 ) ;
if ( V_25 )
goto V_238;
}
return 0 ;
V_238:
F_26 ( V_2 , L_21 , V_25 ) ;
return V_25 ;
}
static T_1
F_64 ( struct V_1 * V_2 , T_6 V_181 ,
T_5 bool V_231 )
{
bool V_233 = false ;
T_2 V_245 ;
T_1 V_246 ;
V_246 = F_60 ( V_2 , & V_233 ) ;
if ( V_246 == V_216 )
return 0 ;
if ( ! V_246 )
return V_246 ;
V_246 = V_2 -> V_4 . V_7 . V_247 ( V_2 ,
F_65 ( V_2 -> V_13 . V_14 ) ,
V_196 ,
& V_245 ) ;
if ( V_246 )
return V_246 ;
if ( V_233 ) {
V_245 &= ~ V_248 ;
V_245 |= V_249 ;
} else {
V_245 |= V_248 ;
V_245 &= ~ V_249 ;
}
V_246 = V_2 -> V_4 . V_7 . V_250 ( V_2 ,
F_65 ( V_2 -> V_13 . V_14 ) ,
V_196 ,
V_245 ) ;
if ( V_246 )
return V_246 ;
return F_54 ( V_2 , & V_181 ) ;
}
static T_1
F_66 ( struct V_1 * V_2 , T_6 V_181 ,
T_5 bool V_231 )
{
T_2 V_251 , V_252 ;
bool V_233 = false ;
T_3 V_253 ;
T_1 V_246 ;
V_246 = F_60 ( V_2 , & V_233 ) ;
if ( V_246 == V_216 )
return 0 ;
if ( ! V_246 )
return V_246 ;
F_63 ( V_2 , V_181 ) ;
if ( ! V_2 -> V_6 . V_254 . V_255 || V_2 -> V_6 . V_254 . V_255 == 0xFFFF )
return V_256 ;
V_246 = V_2 -> V_6 . V_7 . V_257 ( V_2 , V_258 ,
V_259 , & V_253 ) ;
if ( V_246 )
return V_246 ;
if ( V_253 == V_260 )
V_252 = ( V_2 -> V_13 . V_14 +
( V_2 -> V_13 . V_261 << 1 ) ) << 12 ;
else
V_252 = V_2 -> V_13 . V_14 << 12 ;
V_251 = V_239 + V_252 ;
if ( V_233 )
V_253 = ( V_244 << 1 ) | 1 ;
else
V_253 = ( V_240 << 1 ) | 1 ;
return V_2 -> V_6 . V_7 . V_262 ( V_2 , V_251 , V_259 ,
V_253 ) ;
}
static T_1 F_67 ( struct V_1 * V_2 ,
T_6 V_181 ,
bool V_263 )
{
T_1 V_25 ;
T_6 V_264 ;
if ( V_181 & V_199 )
V_264 = V_199 ;
else
V_264 = V_201 ;
if ( ! ( V_2 -> V_6 . V_234 & V_235 ) ) {
V_25 = F_54 ( V_2 , & V_264 ) ;
if ( V_25 )
return V_25 ;
}
return V_2 -> V_6 . V_7 . V_265 ( V_2 , V_181 , V_263 ) ;
}
static T_1 F_68 ( struct V_1 * V_2 ,
T_6 * V_181 ,
bool * V_266 ,
bool V_267 )
{
T_2 V_25 ;
T_3 V_268 ;
if ( V_2 -> V_4 . V_7 . V_8 ( V_2 ) != V_9 )
return V_269 ;
V_25 = F_69 ( V_2 , V_181 , V_266 ,
V_267 ) ;
if ( V_25 || ! ( * V_266 ) )
return V_25 ;
V_25 = V_2 -> V_6 . V_7 . V_257 ( V_2 , V_270 ,
V_271 ,
& V_268 ) ;
if ( V_25 )
return V_25 ;
if ( ! ( V_268 & V_272 ) )
* V_266 = false ;
return 0 ;
}
static T_1
F_70 ( struct V_1 * V_2 , T_5 T_6 V_181 ,
T_5 bool V_231 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_2 V_273 , V_274 ;
T_1 V_246 ;
V_246 = V_4 -> V_7 . V_247 ( V_2 ,
F_55 ( V_2 -> V_13 . V_14 ) ,
V_196 , & V_273 ) ;
if ( V_246 )
return V_246 ;
V_273 &= ~ V_197 ;
V_273 &= ~ V_198 ;
V_273 |= V_275 ;
V_273 |= V_276 ;
V_273 |= V_202 ;
V_246 = V_4 -> V_7 . V_250 ( V_2 ,
F_55 ( V_2 -> V_13 . V_14 ) ,
V_196 , V_273 ) ;
if ( V_246 )
return V_246 ;
V_246 = V_4 -> V_7 . V_247 ( V_2 ,
F_71 ( V_2 -> V_13 . V_14 ) ,
V_196 , & V_274 ) ;
if ( V_246 )
return V_246 ;
V_274 |= V_277 ;
V_274 |= V_278 ;
V_246 = V_4 -> V_7 . V_250 ( V_2 ,
F_71 ( V_2 -> V_13 . V_14 ) ,
V_196 , V_274 ) ;
if ( V_246 )
return V_246 ;
V_273 |= V_212 ;
V_246 = V_4 -> V_7 . V_250 ( V_2 ,
F_55 ( V_2 -> V_13 . V_14 ) ,
V_196 , V_273 ) ;
return V_246 ;
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
switch ( V_4 -> V_7 . V_8 ( V_2 ) ) {
case V_279 :
V_4 -> V_7 . V_280 = NULL ;
V_4 -> V_7 . V_281 = NULL ;
V_4 -> V_7 . V_282 = NULL ;
V_4 -> V_7 . V_283 = V_284 ;
V_4 -> V_7 . V_285 = V_286 ;
switch ( V_2 -> V_49 ) {
case V_55 :
V_4 -> V_7 . V_287 = F_64 ;
break;
case V_50 :
V_4 -> V_7 . V_287 =
F_66 ;
break;
default:
V_4 -> V_7 . V_287 =
F_61 ;
break;
}
V_4 -> V_7 . V_288 =
V_289 ;
break;
case V_9 :
V_4 -> V_7 . V_283 = F_67 ;
V_4 -> V_7 . V_285 = V_290 ;
V_4 -> V_7 . V_291 = F_68 ;
return;
case V_292 :
if ( V_2 -> V_49 == V_293 ||
V_2 -> V_49 == V_294 )
V_4 -> V_7 . V_283 = F_70 ;
break;
default:
V_4 -> V_7 . V_285 = V_286 ;
break;
}
}
static T_1 F_73 ( struct V_1 * V_2 )
{
T_1 V_25 ;
bool V_213 ;
V_25 = F_60 ( V_2 , & V_213 ) ;
if ( V_25 )
return V_25 ;
F_72 ( V_2 ) ;
V_2 -> V_6 . V_7 . V_295 = NULL ;
return 0 ;
}
static T_1 F_74 ( struct V_1 * V_2 ,
T_6 * V_181 ,
bool * V_296 )
{
if ( V_2 -> V_6 . V_297 == V_279 ) {
* V_296 = false ;
if ( V_2 -> V_6 . V_214 == V_223 ||
V_2 -> V_6 . V_214 == V_224 ) {
* V_181 = V_201 ;
return 0 ;
}
if ( V_2 -> V_6 . V_298 )
* V_181 = V_199 |
V_201 ;
else
* V_181 = V_199 ;
} else {
* V_181 = V_199 |
V_201 ;
* V_296 = true ;
}
return 0 ;
}
static T_1 F_75 ( struct V_1 * V_2 , bool * V_299 )
{
T_2 V_25 ;
T_3 V_20 ;
* V_299 = false ;
V_25 = V_2 -> V_6 . V_7 . V_257 ( V_2 , V_300 ,
V_301 ,
& V_20 ) ;
if ( V_25 || ! ( V_20 & V_302 ) )
return V_25 ;
V_25 = V_2 -> V_6 . V_7 . V_257 ( V_2 , V_303 ,
V_301 ,
& V_20 ) ;
if ( V_25 || ! ( V_20 & ( V_304 |
V_305 ) ) )
return V_25 ;
V_25 = V_2 -> V_6 . V_7 . V_257 ( V_2 , V_306 ,
V_301 ,
& V_20 ) ;
if ( V_25 )
return V_25 ;
if ( V_20 & V_307 ) {
F_76 ( V_2 , false ) ;
return V_308 ;
}
if ( V_20 & V_309 ) {
V_25 = V_2 -> V_6 . V_7 . V_257 ( V_2 , V_310 ,
V_301 ,
& V_20 ) ;
if ( V_25 )
return V_25 ;
if ( V_20 == V_311 ) {
F_76 ( V_2 , false ) ;
return V_308 ;
}
}
V_25 = V_2 -> V_6 . V_7 . V_257 ( V_2 , V_300 ,
V_271 , & V_20 ) ;
if ( V_25 || ! ( V_20 & V_312 ) )
return V_25 ;
V_25 = V_2 -> V_6 . V_7 . V_257 ( V_2 , V_313 ,
V_271 , & V_20 ) ;
if ( V_25 )
return V_25 ;
if ( V_20 & V_314 )
* V_299 = true ;
return 0 ;
}
static T_1 F_77 ( struct V_1 * V_2 )
{
T_2 V_25 ;
T_3 V_20 ;
bool V_299 ;
V_25 = F_75 ( V_2 , & V_299 ) ;
V_25 = V_2 -> V_6 . V_7 . V_257 ( V_2 , V_315 ,
V_271 , & V_20 ) ;
if ( V_25 )
return V_25 ;
V_20 |= V_316 ;
V_25 = V_2 -> V_6 . V_7 . V_262 ( V_2 , V_315 ,
V_271 , V_20 ) ;
if ( V_25 )
return V_25 ;
V_25 = V_2 -> V_6 . V_7 . V_257 ( V_2 , V_317 ,
V_301 ,
& V_20 ) ;
if ( V_25 )
return V_25 ;
V_20 |= ( V_318 |
V_319 ) ;
V_25 = V_2 -> V_6 . V_7 . V_262 ( V_2 , V_317 ,
V_301 ,
V_20 ) ;
if ( V_25 )
return V_25 ;
V_25 = V_2 -> V_6 . V_7 . V_257 ( V_2 , V_320 ,
V_301 ,
& V_20 ) ;
if ( V_25 )
return V_25 ;
V_20 |= ( V_304 |
V_305 ) ;
V_25 = V_2 -> V_6 . V_7 . V_262 ( V_2 , V_320 ,
V_301 ,
V_20 ) ;
if ( V_25 )
return V_25 ;
V_25 = V_2 -> V_6 . V_7 . V_257 ( V_2 , V_321 ,
V_301 ,
& V_20 ) ;
if ( V_25 )
return V_25 ;
V_20 |= V_302 ;
V_25 = V_2 -> V_6 . V_7 . V_262 ( V_2 , V_321 ,
V_301 ,
V_20 ) ;
return V_25 ;
}
static T_1 F_78 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
bool V_299 ;
T_2 V_25 ;
V_25 = F_75 ( V_2 , & V_299 ) ;
if ( V_25 )
return V_25 ;
if ( V_299 && V_6 -> V_7 . V_322 )
return V_6 -> V_7 . V_322 ( V_2 ) ;
return 0 ;
}
static T_1 F_63 ( struct V_1 * V_2 ,
T_6 V_181 )
{
T_1 V_25 ;
T_2 V_195 ;
V_25 = V_2 -> V_4 . V_7 . V_247 ( V_2 ,
F_55 ( V_2 -> V_13 . V_14 ) ,
V_196 , & V_195 ) ;
if ( V_25 )
return V_25 ;
V_195 |= V_197 ;
V_195 &= ~ ( V_323 |
V_324 ) ;
V_195 &= ~ ( V_325 |
V_326 ) ;
if ( V_181 & V_199 )
V_195 |= V_325 ;
if ( V_181 & V_201 )
V_195 |= V_326 ;
V_195 |= V_212 ;
V_25 = V_2 -> V_4 . V_7 . V_250 ( V_2 ,
F_55 ( V_2 -> V_13 . V_14 ) ,
V_196 , V_195 ) ;
return V_25 ;
}
static T_1 F_79 ( struct V_1 * V_2 )
{
T_1 V_25 ;
T_2 V_195 ;
V_25 = V_2 -> V_4 . V_7 . V_247 ( V_2 , V_327 ,
V_328 +
V_2 -> V_13 . V_14 , & V_195 ) ;
if ( V_25 )
return V_25 ;
V_195 &= ~ ( V_329 |
V_330 ) ;
V_195 |= V_331 ;
if ( V_2 -> V_6 . V_332 & V_199 )
V_195 |= V_329 ;
if ( V_2 -> V_6 . V_332 & V_201 )
V_195 |= V_330 ;
V_195 |= V_333 ;
V_25 = V_2 -> V_4 . V_7 . V_250 ( V_2 , V_327 ,
V_328 +
V_2 -> V_13 . V_14 , V_195 ) ;
return V_25 ;
}
static T_1 F_80 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 . type != V_334 )
return 0 ;
return F_63 ( V_2 , V_2 -> V_6 . V_332 ) ;
}
static T_1 F_81 ( struct V_1 * V_2 , bool * V_266 )
{
T_2 V_85 ;
T_3 V_268 ;
* V_266 = false ;
V_85 = V_2 -> V_6 . V_7 . V_257 ( V_2 , V_270 ,
V_271 ,
& V_268 ) ;
if ( V_85 )
return V_85 ;
V_85 = V_2 -> V_6 . V_7 . V_257 ( V_2 , V_270 ,
V_271 ,
& V_268 ) ;
if ( V_85 )
return V_85 ;
* V_266 = ! ! ( V_268 & V_272 ) ;
return 0 ;
}
static T_1 F_82 ( struct V_1 * V_2 )
{
T_6 V_264 ;
bool V_266 ;
T_2 V_25 ;
T_3 V_181 ;
if ( V_2 -> V_4 . V_7 . V_8 ( V_2 ) != V_9 )
return V_269 ;
if ( V_2 -> V_6 . V_234 & V_235 ) {
V_181 = V_199 |
V_201 ;
return F_63 ( V_2 , V_181 ) ;
}
V_25 = F_81 ( V_2 , & V_266 ) ;
if ( V_25 )
return V_25 ;
if ( ! V_266 )
return 0 ;
V_25 = V_2 -> V_6 . V_7 . V_257 ( V_2 , V_335 ,
V_271 ,
& V_181 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_81 ( V_2 , & V_266 ) ;
if ( V_25 )
return V_25 ;
if ( ! V_266 )
return 0 ;
V_181 &= V_336 ;
switch ( V_181 ) {
case V_337 :
V_264 = V_199 ;
break;
case V_338 :
V_264 = V_201 ;
break;
default:
return V_339 ;
}
return F_54 ( V_2 , & V_264 ) ;
}
static T_1 F_83 ( struct V_1 * V_2 )
{
T_1 V_25 ;
V_25 = F_84 ( V_2 ) ;
if ( V_25 )
return V_25 ;
return F_77 ( V_2 ) ;
}
static T_1 F_85 ( struct V_1 * V_2 ,
T_6 * V_340 )
{
T_3 V_341 ;
T_1 V_25 ;
T_3 V_342 = V_2 -> V_47 . V_343 ;
* V_340 = V_344 ;
V_25 = V_2 -> V_6 . V_7 . V_257 ( V_2 , V_345 ,
V_271 ,
& V_341 ) ;
if ( V_25 )
return V_25 ;
if ( V_341 & V_346 ) {
* V_340 = V_201 ;
return V_25 ;
}
if ( ( V_2 -> V_13 . V_14 && ( V_342 & V_347 ) ) ||
( V_342 & V_348 ) )
return V_25 ;
* V_340 = V_199 ;
return V_25 ;
}
static T_1 V_286 ( struct V_1 * V_2 )
{
bool V_349 , V_350 ;
T_2 V_195 ;
T_1 V_246 ;
if ( V_2 -> V_351 . V_352 && V_2 -> V_351 . V_353 == V_354 ) {
F_11 ( V_2 , L_22 ) ;
return V_339 ;
}
if ( V_2 -> V_351 . V_353 == V_355 )
V_2 -> V_351 . V_353 = V_356 ;
switch ( V_2 -> V_351 . V_353 ) {
case V_357 :
V_349 = false ;
V_350 = false ;
break;
case V_358 :
V_349 = false ;
V_350 = true ;
break;
case V_354 :
case V_356 :
V_349 = true ;
V_350 = true ;
break;
default:
F_11 ( V_2 , L_23 ) ;
return V_269 ;
}
if ( V_2 -> V_49 != V_58 &&
V_2 -> V_49 != V_59 &&
V_2 -> V_49 != V_60 )
return 0 ;
V_246 = V_2 -> V_4 . V_7 . V_247 ( V_2 ,
F_86 ( V_2 -> V_13 . V_14 ) ,
V_196 ,
& V_195 ) ;
if ( V_246 )
return V_246 ;
V_195 &= ~ ( V_359 |
V_360 ) ;
if ( V_349 )
V_195 |= V_359 ;
if ( V_350 )
V_195 |= V_360 ;
V_246 = V_2 -> V_4 . V_7 . V_250 ( V_2 ,
F_86 ( V_2 -> V_13 . V_14 ) ,
V_196 ,
V_195 ) ;
V_2 -> V_351 . V_361 = true ;
return V_246 ;
}
static T_1 F_87 ( struct V_1 * V_2 )
{
T_3 V_362 , V_363 , V_181 ;
T_1 V_25 ;
T_6 V_340 ;
T_2 V_364 ;
bool V_266 ;
if ( F_88 ( V_2 ) )
return 0 ;
V_25 = F_81 ( V_2 , & V_266 ) ;
if ( V_25 )
return V_25 ;
V_25 = V_2 -> V_47 . V_7 . V_169 ( V_2 , V_365 ,
& V_2 -> V_47 . V_343 ) ;
if ( V_25 )
return V_25 ;
if ( ! V_266 || ! ( V_2 -> V_47 . V_343 & V_366 ) ||
! ( V_2 -> V_367 || F_89 ( V_2 ) ) )
return F_76 ( V_2 , false ) ;
V_25 = F_85 ( V_2 , & V_340 ) ;
if ( V_25 )
return V_25 ;
if ( V_340 == V_344 )
return F_76 ( V_2 , false ) ;
V_25 = V_2 -> V_6 . V_7 . V_257 ( V_2 , V_335 ,
V_271 ,
& V_181 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_81 ( V_2 , & V_266 ) ;
if ( V_25 )
return F_76 ( V_2 , false ) ;
V_181 &= V_368 ;
if ( ( ( V_181 == V_369 ) &&
( V_340 == V_201 ) ) ||
( ( V_181 == V_370 ) &&
( V_340 == V_199 ) ) )
return V_25 ;
V_25 = V_2 -> V_6 . V_7 . V_257 ( V_2 , V_371 ,
V_271 ,
& V_363 ) ;
if ( V_25 )
return V_25 ;
V_25 = V_2 -> V_6 . V_7 . V_257 ( V_2 , V_372 ,
V_271 ,
& V_362 ) ;
if ( V_25 )
return V_25 ;
V_25 = V_2 -> V_6 . V_7 . V_257 ( V_2 ,
V_373 ,
V_271 ,
& V_363 ) ;
if ( V_25 )
return V_25 ;
V_364 = V_2 -> V_6 . V_332 ;
V_25 = V_2 -> V_4 . V_7 . V_283 ( V_2 , V_340 , false ) ;
V_2 -> V_6 . V_332 = V_364 ;
return V_25 ;
}
static void F_90 ( struct V_1 * V_2 )
{
V_2 -> V_6 . V_234 = F_4 ( V_2 , V_374 ) ;
if ( ! V_2 -> V_6 . V_234 ) {
if ( V_2 -> V_4 . type == V_375 ) {
struct V_376 * V_377 = V_2 -> V_378 ;
F_91 ( V_379 , L_24 ) ;
}
return;
}
V_2 -> V_6 . V_254 . V_255 = ( V_2 -> V_6 . V_234 &
V_380 ) >>
V_381 ;
}
static T_1 F_92 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_382 ;
V_2 -> V_4 . V_7 . V_183 ( V_2 ) ;
F_90 ( V_2 ) ;
if ( V_2 -> V_4 . V_7 . V_8 ( V_2 ) == V_279 ) {
V_6 -> V_40 = V_54 ;
F_3 ( V_2 ) ;
}
V_382 = V_6 -> V_7 . V_383 ( V_2 ) ;
F_72 ( V_2 ) ;
if ( V_6 -> V_214 != V_227 )
V_6 -> V_7 . V_295 = NULL ;
switch ( V_2 -> V_6 . type ) {
case V_57 :
V_6 -> V_7 . V_283 = F_79 ;
V_6 -> V_7 . V_257 = F_21 ;
V_6 -> V_7 . V_262 = F_22 ;
break;
case V_61 :
V_6 -> V_7 . V_283 = F_80 ;
V_6 -> V_7 . V_257 = F_21 ;
V_6 -> V_7 . V_262 = F_22 ;
break;
case V_384 :
V_6 -> V_234 = F_4 ( V_2 , V_374 ) ;
V_6 -> V_7 . V_322 =
F_82 ;
if ( V_2 -> V_4 . type == V_334 &&
! ( F_4 ( V_2 , F_93 ( 0 ) ) &
V_385 ) )
V_6 -> V_7 . V_386 = F_87 ;
V_6 -> V_7 . V_387 = F_78 ;
V_6 -> V_7 . V_295 = F_83 ;
break;
default:
break;
}
return V_382 ;
}
static enum V_388 F_94 ( struct V_1 * V_2 )
{
enum V_388 V_297 ;
switch ( V_2 -> V_49 ) {
case V_293 :
case V_294 :
V_2 -> V_6 . type = V_389 ;
case V_58 :
case V_56 :
case V_59 :
case V_60 :
V_297 = V_292 ;
break;
case V_53 :
case V_50 :
case V_55 :
V_297 = V_279 ;
break;
case V_62 :
case V_63 :
V_297 = V_9 ;
break;
default:
V_297 = V_390 ;
break;
}
return V_297 ;
}
static T_1 F_95 ( struct V_1 * V_2 )
{
T_1 V_25 ;
T_3 V_20 ;
V_25 = V_2 -> V_6 . V_7 . V_257 ( V_2 ,
V_391 ,
V_392 ,
& V_20 ) ;
if ( V_25 )
return V_25 ;
if ( V_20 & V_393 ) {
V_25 = V_2 -> V_6 . V_7 . V_257 ( V_2 ,
V_394 ,
V_301 ,
& V_20 ) ;
if ( V_25 )
return V_25 ;
V_20 &= ~ V_395 ;
V_25 = V_2 -> V_6 . V_7 . V_262 ( V_2 ,
V_394 ,
V_301 ,
V_20 ) ;
if ( V_25 )
return V_25 ;
}
return V_25 ;
}
static void F_96 ( struct V_1 * V_2 )
{
T_2 V_396 ;
switch ( V_2 -> V_49 ) {
case V_63 :
case V_50 :
V_396 = F_4 ( V_2 , V_397 ) ;
V_396 &= ~ V_398 ;
F_5 ( V_2 , V_397 , V_396 ) ;
break;
default:
break;
}
}
static T_1 F_97 ( struct V_1 * V_2 )
{
T_6 V_399 ;
T_1 V_25 ;
T_2 V_77 = 0 ;
T_2 V_78 ;
bool V_266 = false ;
V_25 = V_2 -> V_4 . V_7 . V_400 ( V_2 ) ;
if ( V_25 )
return V_25 ;
F_98 ( V_2 ) ;
V_25 = V_2 -> V_6 . V_7 . V_401 ( V_2 ) ;
if ( V_2 -> V_6 . type == V_384 ) {
V_25 = F_95 ( V_2 ) ;
if ( V_25 )
return V_25 ;
}
if ( V_2 -> V_6 . V_402 ) {
V_25 = V_2 -> V_4 . V_7 . V_403 ( V_2 ) ;
V_2 -> V_6 . V_402 = false ;
}
if ( ! V_2 -> V_6 . V_404 && V_2 -> V_6 . V_7 . V_295 )
V_2 -> V_6 . V_7 . V_295 ( V_2 ) ;
V_405:
V_77 = V_406 ;
if ( ! V_2 -> V_407 ) {
V_2 -> V_4 . V_7 . V_291 ( V_2 , & V_399 , & V_266 , false ) ;
if ( V_266 )
V_77 = V_408 ;
}
V_77 |= F_4 ( V_2 , V_409 ) ;
F_5 ( V_2 , V_409 , V_77 ) ;
F_6 ( V_2 ) ;
F_15 ( 1000 , 1200 ) ;
for ( V_78 = 0 ; V_78 < 10 ; V_78 ++ ) {
V_77 = F_4 ( V_2 , V_409 ) ;
if ( ! ( V_77 & V_410 ) )
break;
F_28 ( 1 ) ;
}
if ( V_77 & V_410 ) {
V_25 = V_411 ;
F_26 ( V_2 , L_25 ) ;
}
F_16 ( 50 ) ;
if ( V_2 -> V_4 . V_412 & V_413 ) {
V_2 -> V_4 . V_412 &= ~ V_413 ;
goto V_405;
}
V_2 -> V_4 . V_7 . V_414 ( V_2 , V_2 -> V_4 . V_415 ) ;
V_2 -> V_4 . V_416 = 128 ;
V_2 -> V_4 . V_7 . V_417 ( V_2 ) ;
F_96 ( V_2 ) ;
if ( V_2 -> V_49 == V_53 )
F_3 ( V_2 ) ;
return V_25 ;
}
static void F_99 ( struct V_1 * V_2 ,
bool V_418 , int V_419 )
{
int V_420 = V_419 >> 3 ;
int V_421 = V_419 % 8 + V_422 ;
T_2 V_423 ;
V_423 = F_4 ( V_2 , F_100 ( V_420 ) ) ;
if ( V_418 )
V_423 |= F_25 ( V_421 ) ;
else
V_423 &= ~ F_25 ( V_421 ) ;
F_5 ( V_2 , F_100 ( V_420 ) , V_423 ) ;
}
static void F_101 ( struct V_1 * V_2 ,
bool V_418 ,
unsigned int V_424 )
{
T_7 V_425 ;
if ( V_424 > 63 )
return;
V_425 = ( T_7 ) F_4 ( V_2 , V_426 ) ;
V_425 |= ( T_7 ) F_4 ( V_2 , V_427 ) << 32 ;
if ( V_418 )
V_425 |= ( 1ULL << V_424 ) ;
else
V_425 &= ~ ( 1ULL << V_424 ) ;
F_5 ( V_2 , V_426 , ( T_2 ) V_425 ) ;
F_5 ( V_2 , V_427 , ( T_2 ) ( V_425 >> 32 ) ) ;
}
static void F_102 ( struct V_1 * V_2 , T_4 V_428 )
{
T_2 V_11 ;
if ( ! V_2 -> V_13 . V_14 )
return;
V_11 = F_4 ( V_2 , V_12 ) ;
if ( V_428 )
V_11 |= V_16 ;
else
V_11 &= ~ V_16 ;
F_5 ( V_2 , V_12 , V_11 ) ;
F_6 ( V_2 ) ;
}
static T_1 F_103 ( struct V_1 * V_2 , T_2 V_429 )
{
T_1 V_25 ;
V_25 = F_104 ( V_2 , V_429 ) ;
if ( V_25 )
return V_25 ;
if ( V_429 & V_430 )
F_102 ( V_2 , 1 ) ;
return 0 ;
}
static void F_105 ( struct V_1 * V_2 , T_2 V_429 )
{
if ( V_429 & V_430 )
F_102 ( V_2 , 0 ) ;
F_106 ( V_2 , V_429 ) ;
}
static T_1 F_107 ( struct V_1 * V_2 , T_2 V_429 )
{
T_2 V_431 = V_429 & ~ V_432 ;
int V_433 = V_434 ;
T_1 V_25 ;
while ( -- V_433 ) {
V_25 = 0 ;
if ( V_431 )
V_25 = F_104 ( V_2 , V_431 ) ;
if ( V_25 )
return V_25 ;
if ( ! ( V_429 & V_432 ) )
return 0 ;
V_25 = F_30 ( V_2 ) ;
if ( ! V_25 )
return 0 ;
if ( V_431 )
F_106 ( V_2 , V_431 ) ;
if ( V_25 != V_112 )
return V_25 ;
F_16 ( V_435 ) ;
}
return V_25 ;
}
static void F_108 ( struct V_1 * V_2 , T_2 V_429 )
{
T_2 V_431 = V_429 & ~ V_432 ;
if ( V_429 & V_432 )
F_32 ( V_2 ) ;
if ( V_431 )
F_106 ( V_2 , V_431 ) ;
}
static T_1 F_109 ( struct V_1 * V_2 , T_2 V_64 ,
T_2 V_65 , T_3 * V_66 )
{
T_2 V_429 = V_2 -> V_6 . V_40 | V_432 ;
T_1 V_25 ;
if ( V_2 -> V_4 . V_7 . V_41 ( V_2 , V_429 ) )
return V_166 ;
V_25 = V_2 -> V_6 . V_7 . V_436 ( V_2 , V_64 , V_65 , V_66 ) ;
V_2 -> V_4 . V_7 . V_46 ( V_2 , V_429 ) ;
return V_25 ;
}
static T_1 F_110 ( struct V_1 * V_2 , T_2 V_64 ,
T_2 V_65 , T_3 V_66 )
{
T_2 V_429 = V_2 -> V_6 . V_40 | V_432 ;
T_1 V_25 ;
if ( V_2 -> V_4 . V_7 . V_41 ( V_2 , V_429 ) )
return V_166 ;
V_25 = F_111 ( V_2 , V_64 , V_65 , V_66 ) ;
V_2 -> V_4 . V_7 . V_46 ( V_2 , V_429 ) ;
return V_25 ;
}
