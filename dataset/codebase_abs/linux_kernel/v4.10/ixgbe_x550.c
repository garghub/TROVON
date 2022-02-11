static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
F_2 ( V_2 ) ;
if ( V_4 -> V_9 . V_10 ( V_2 ) != V_11 )
V_6 -> V_9 . V_12 = NULL ;
V_8 -> V_13 = V_14 ;
return 0 ;
}
static T_1 F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_2 ( V_2 ) ;
if ( V_4 -> V_9 . V_10 ( V_2 ) != V_11 )
V_6 -> V_9 . V_12 = NULL ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
T_2 V_15 = F_5 ( V_2 , V_16 ) ;
if ( V_2 -> V_17 . V_18 ) {
V_15 &= ~ ( V_19 | V_20 ) ;
V_15 |= V_21 ;
}
V_15 &= ~ ( V_22 | V_23 ) ;
F_6 ( V_2 , V_16 , V_15 ) ;
F_7 ( V_2 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 , T_3 V_24 , T_3 * V_25 )
{
return V_2 -> V_8 . V_9 . V_26 ( V_2 , V_2 -> V_8 . V_13 , V_24 , V_25 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 , T_3 V_24 , T_3 V_25 )
{
return V_2 -> V_8 . V_9 . V_27 ( V_2 , V_2 -> V_8 . V_13 , V_24 , V_25 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 , T_4 V_24 , T_4 * V_25 )
{
T_1 V_28 ;
V_28 = F_11 ( V_2 , V_24 , V_29 , V_25 ) ;
if ( V_28 )
F_12 ( V_2 , L_1 , V_28 ) ;
return V_28 ;
}
static T_1 F_13 ( struct V_1 * V_2 , T_4 V_24 , T_4 V_25 )
{
T_1 V_28 ;
V_28 = F_14 ( V_2 , V_24 , V_29 ,
V_25 ) ;
if ( V_28 )
F_12 ( V_2 , L_1 , V_28 ) ;
return V_28 ;
}
static T_1 F_15 ( struct V_1 * V_2 )
{
T_1 V_28 ;
T_2 V_30 ;
T_3 V_25 ;
T_4 V_24 ;
V_28 = F_10 ( V_2 , V_31 , & V_24 ) ;
if ( V_28 )
return V_28 ;
V_24 |= V_32 ;
V_28 = F_13 ( V_2 , V_31 , V_24 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_10 ( V_2 , V_33 , & V_24 ) ;
if ( V_28 )
return V_28 ;
V_24 &= ~ V_32 ;
V_28 = F_13 ( V_2 , V_33 , V_24 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_10 ( V_2 , V_31 , & V_24 ) ;
if ( V_28 )
return V_28 ;
V_24 &= ~ V_32 ;
V_28 = F_13 ( V_2 , V_31 , V_24 ) ;
if ( V_28 )
return V_28 ;
F_16 ( V_34 , V_34 + 100 ) ;
V_28 = F_10 ( V_2 , V_31 , & V_24 ) ;
if ( V_28 )
return V_28 ;
V_24 |= V_32 ;
V_28 = F_13 ( V_2 , V_31 , V_24 ) ;
if ( V_28 )
return V_28 ;
F_17 ( V_35 ) ;
for ( V_30 = 0 ; V_30 < V_36 ; V_30 ++ ) {
V_28 = F_8 ( V_2 , V_37 ,
& V_25 ) ;
if ( ! V_28 && V_25 == V_38 )
break;
F_17 ( V_39 ) ;
}
if ( V_30 == V_36 ) {
F_12 ( V_2 , L_2 ) ;
return V_40 ;
}
V_28 = F_8 ( V_2 , V_41 , & V_25 ) ;
if ( V_28 || ! ( V_25 & V_38 ) ) {
F_12 ( V_2 , L_3 ) ;
return V_40 ;
}
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
T_2 V_42 = V_2 -> V_6 . V_43 ;
T_1 V_28 ;
T_3 V_25 ;
T_4 V_30 ;
for ( V_30 = 0 ; V_30 < V_36 ; V_30 ++ ) {
V_28 = V_2 -> V_4 . V_9 . V_44 ( V_2 , V_42 ) ;
if ( V_28 ) {
F_12 ( V_2 , L_4 , V_28 ) ;
F_17 ( V_39 ) ;
continue;
}
V_28 = F_8 ( V_2 , V_45 , & V_25 ) ;
if ( ! V_28 && V_25 == V_46 )
goto V_47;
if ( V_28 || V_25 != V_48 )
break;
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_42 ) ;
F_17 ( V_39 ) ;
}
if ( V_30 == V_36 ) {
V_28 = V_2 -> V_4 . V_9 . V_44 ( V_2 , V_42 ) ;
if ( V_28 ) {
F_12 ( V_2 , L_4 , V_28 ) ;
return;
}
}
V_28 = F_15 ( V_2 ) ;
if ( V_28 ) {
F_12 ( V_2 , L_5 , V_28 ) ;
goto V_47;
}
F_9 ( V_2 , V_45 ,
V_48 ) ;
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_42 ) ;
F_16 ( 10000 , 12000 ) ;
V_28 = V_2 -> V_4 . V_9 . V_44 ( V_2 , V_42 ) ;
if ( V_28 ) {
F_12 ( V_2 , L_6 , V_28 ) ;
return;
}
V_28 = F_9 ( V_2 , V_45 ,
V_46 ) ;
V_47:
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_42 ) ;
F_17 ( V_2 -> V_50 . V_51 ) ;
}
static T_1 F_19 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_52 ) {
case V_53 :
if ( V_2 -> V_17 . V_18 )
V_2 -> V_6 . V_43 = V_54 ;
else
V_2 -> V_6 . V_43 = V_55 ;
return F_20 ( V_2 ) ;
case V_56 :
V_2 -> V_6 . V_43 = V_57 ;
F_4 ( V_2 ) ;
F_18 ( V_2 ) ;
case V_58 :
return F_20 ( V_2 ) ;
case V_59 :
V_2 -> V_6 . type = V_60 ;
break;
case V_61 :
case V_62 :
case V_63 :
V_2 -> V_6 . type = V_64 ;
break;
case V_65 :
if ( V_2 -> V_17 . V_18 )
V_2 -> V_6 . V_43 = V_54 ;
else
V_2 -> V_6 . V_43 = V_55 ;
case V_66 :
case V_67 :
return F_21 ( V_2 ) ;
default:
break;
}
return 0 ;
}
static T_1 F_22 ( struct V_1 * V_2 , T_2 V_68 ,
T_2 V_69 , T_3 * V_70 )
{
return V_71 ;
}
static T_1 F_23 ( struct V_1 * V_2 , T_2 V_68 ,
T_2 V_69 , T_3 V_70 )
{
return V_71 ;
}
static T_1 F_24 ( struct V_1 * V_2 , T_4 V_13 ,
T_3 V_24 , T_3 * V_72 )
{
return F_25 ( V_2 , V_13 , V_24 , V_72 , true ) ;
}
static T_1
F_26 ( struct V_1 * V_2 , T_4 V_13 ,
T_3 V_24 , T_3 * V_72 )
{
return F_25 ( V_2 , V_13 , V_24 , V_72 , false ) ;
}
static T_1 F_27 ( struct V_1 * V_2 ,
T_4 V_13 , T_3 V_24 , T_3 V_72 )
{
return F_28 ( V_2 , V_13 , V_24 , V_72 , true ) ;
}
static T_1
F_29 ( struct V_1 * V_2 ,
T_4 V_13 , T_3 V_24 , T_3 V_72 )
{
return F_28 ( V_2 , V_13 , V_24 , V_72 , false ) ;
}
static T_1 F_30 ( struct V_1 * V_2 )
{
struct V_73 * V_50 = & V_2 -> V_50 ;
T_2 V_74 ;
T_3 V_75 ;
if ( V_50 -> type == V_76 ) {
V_50 -> V_51 = 10 ;
V_50 -> type = V_77 ;
V_74 = F_5 ( V_2 , F_31 ( V_2 ) ) ;
V_75 = ( T_3 ) ( ( V_74 & V_78 ) >>
V_79 ) ;
V_50 -> V_80 = F_32 ( V_75 +
V_81 ) ;
F_33 ( V_2 , L_7 ,
V_50 -> type , V_50 -> V_80 ) ;
}
return 0 ;
}
static T_1 F_34 ( struct V_1 * V_2 , T_2 * V_82 )
{
T_2 V_83 , V_84 ;
for ( V_83 = 0 ; V_83 < V_85 ; V_83 ++ ) {
V_84 = F_5 ( V_2 , V_86 ) ;
if ( ! ( V_84 & V_87 ) )
break;
F_35 ( 10 ) ;
}
if ( V_82 )
* V_82 = V_84 ;
if ( V_83 == V_85 ) {
F_33 ( V_2 , L_8 ) ;
return V_40 ;
}
return 0 ;
}
static T_1 F_36 ( struct V_1 * V_2 , T_2 V_68 ,
T_2 V_69 , T_2 * V_88 )
{
T_2 V_89 = V_54 | V_55 ;
T_2 V_84 , error ;
T_1 V_90 ;
V_90 = V_2 -> V_4 . V_9 . V_44 ( V_2 , V_89 ) ;
if ( V_90 )
return V_90 ;
V_90 = F_34 ( V_2 , NULL ) ;
if ( V_90 )
goto V_47;
V_84 = ( ( V_68 << V_91 ) |
( V_69 << V_92 ) ) ;
F_6 ( V_2 , V_86 , V_84 ) ;
V_90 = F_34 ( V_2 , & V_84 ) ;
if ( ( V_84 & V_93 ) != 0 ) {
error = ( V_84 & V_94 ) >>
V_95 ;
F_33 ( V_2 , L_9 , error ) ;
return V_40 ;
}
if ( ! V_90 )
* V_88 = F_5 ( V_2 , V_96 ) ;
V_47:
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_89 ) ;
return V_90 ;
}
static T_1 F_37 ( struct V_1 * V_2 )
{
struct V_97 V_98 ;
T_1 V_28 ;
V_98 . V_99 . V_100 = V_101 ;
V_98 . V_99 . V_102 = V_103 ;
V_98 . V_99 . V_104 . V_105 = 0 ;
V_98 . V_99 . V_106 = V_107 ;
V_98 . V_108 = V_2 -> V_17 . V_18 ;
V_98 . V_109 = V_110 ;
V_98 . V_111 = 0 ;
V_28 = F_38 ( V_2 , & V_98 , sizeof( V_98 ) ,
V_112 ,
true ) ;
if ( V_28 )
return V_28 ;
if ( V_98 . V_99 . V_104 . V_113 == V_114 )
return 0 ;
if ( V_98 . V_99 . V_104 . V_113 != V_115 )
return V_116 ;
return V_117 ;
}
static T_1 F_39 ( struct V_1 * V_2 )
{
struct V_97 V_98 ;
T_1 V_28 ;
V_98 . V_99 . V_100 = V_101 ;
V_98 . V_99 . V_102 = V_103 ;
V_98 . V_99 . V_104 . V_105 = 0 ;
V_98 . V_99 . V_106 = V_107 ;
V_98 . V_108 = V_2 -> V_17 . V_18 ;
V_98 . V_109 = V_118 ;
V_98 . V_111 = 0 ;
V_28 = F_38 ( V_2 , & V_98 , sizeof( V_98 ) ,
V_112 ,
true ) ;
if ( V_28 )
return V_28 ;
if ( V_98 . V_99 . V_104 . V_113 == V_114 )
return 0 ;
return V_116 ;
}
static T_1 F_40 ( struct V_1 * V_2 , T_2 V_68 ,
T_5 T_2 V_69 ,
T_2 V_88 )
{
struct V_119 V_120 ;
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
V_120 . V_99 . V_100 = V_121 ;
V_120 . V_99 . V_102 = V_122 ;
V_120 . V_99 . V_106 = V_107 ;
V_120 . V_108 = V_2 -> V_17 . V_18 ;
V_120 . V_109 = V_123 ;
V_120 . V_124 = F_41 ( V_68 ) ;
V_120 . V_125 = F_42 ( V_88 ) ;
return F_38 ( V_2 , & V_120 , sizeof( V_120 ) ,
V_112 , false ) ;
}
static T_1 F_43 ( struct V_1 * V_2 , T_2 V_68 ,
T_5 T_2 V_69 ,
T_2 * V_88 )
{
union {
struct V_119 V_100 ;
struct V_126 V_127 ;
} V_128 ;
T_1 V_28 ;
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
V_128 . V_100 . V_99 . V_100 = V_121 ;
V_128 . V_100 . V_99 . V_102 = V_122 ;
V_128 . V_100 . V_99 . V_106 = V_107 ;
V_128 . V_100 . V_108 = V_2 -> V_17 . V_18 ;
V_128 . V_100 . V_109 = V_129 ;
V_128 . V_100 . V_124 = F_41 ( V_68 ) ;
V_28 = F_38 ( V_2 , & V_128 . V_100 , sizeof( V_128 . V_100 ) ,
V_112 , true ) ;
* V_88 = F_44 ( V_128 . V_127 . V_130 ) ;
return V_28 ;
}
static T_1 F_45 ( struct V_1 * V_2 , T_3 V_131 ,
T_3 * V_88 )
{
T_1 V_28 ;
struct V_132 V_133 ;
V_133 . V_99 . V_134 . V_100 = V_135 ;
V_133 . V_99 . V_134 . V_136 = 0 ;
V_133 . V_99 . V_134 . V_137 = V_138 ;
V_133 . V_99 . V_134 . V_106 = V_107 ;
V_133 . V_124 = F_42 ( V_131 * 2 ) ;
V_133 . V_139 = F_41 ( sizeof( T_3 ) ) ;
V_28 = F_38 ( V_2 , & V_133 , sizeof( V_133 ) ,
V_112 , false ) ;
if ( V_28 )
return V_28 ;
* V_88 = ( T_3 ) F_46 ( V_2 , V_140 ,
V_141 ) ;
return 0 ;
}
static T_1 F_47 ( struct V_1 * V_2 ,
T_3 V_131 , T_3 V_142 , T_3 * V_88 )
{
struct V_132 V_133 ;
T_2 V_143 = 0 ;
T_3 V_144 ;
T_1 V_28 ;
T_2 V_83 ;
V_28 = V_2 -> V_4 . V_9 . V_44 ( V_2 , V_145 ) ;
if ( V_28 ) {
F_33 ( V_2 , L_10 ) ;
return V_28 ;
}
while ( V_142 ) {
if ( V_142 > V_146 / 2 )
V_144 = V_146 / 2 ;
else
V_144 = V_142 ;
V_133 . V_99 . V_134 . V_100 = V_135 ;
V_133 . V_99 . V_134 . V_136 = 0 ;
V_133 . V_99 . V_134 . V_137 = V_138 ;
V_133 . V_99 . V_134 . V_106 = V_107 ;
V_133 . V_124 = F_42 ( ( V_131 + V_143 ) * 2 ) ;
V_133 . V_139 = F_41 ( V_144 * 2 ) ;
V_28 = F_38 ( V_2 , & V_133 ,
sizeof( V_133 ) ,
V_112 ,
false ) ;
if ( V_28 ) {
F_33 ( V_2 , L_11 ) ;
goto V_47;
}
for ( V_83 = 0 ; V_83 < V_144 ; V_83 ++ ) {
T_2 V_24 = V_140 + ( V_141 << 2 ) +
2 * V_83 ;
T_2 V_25 = F_5 ( V_2 , V_24 ) ;
V_88 [ V_143 ] = ( T_3 ) ( V_25 & 0xffff ) ;
V_143 ++ ;
V_83 ++ ;
if ( V_83 < V_144 ) {
V_25 >>= 16 ;
V_88 [ V_143 ] = ( T_3 ) ( V_25 & 0xffff ) ;
V_143 ++ ;
}
}
V_142 -= V_144 ;
}
V_47:
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_145 ) ;
return V_28 ;
}
static T_1 F_48 ( struct V_1 * V_2 , T_3 V_147 ,
T_3 V_148 , T_3 * V_149 , T_3 * V_133 ,
T_2 V_150 )
{
T_3 V_151 [ 256 ] ;
T_1 V_28 ;
T_3 V_139 , V_152 , V_83 , V_153 ;
T_3 * V_154 ;
V_152 = sizeof( V_151 ) / sizeof( V_151 [ 0 ] ) ;
if ( ! V_133 ) {
V_28 = F_47 ( V_2 , V_147 , V_152 , V_151 ) ;
if ( V_28 ) {
F_33 ( V_2 , L_12 ) ;
return V_28 ;
}
V_154 = V_151 ;
} else {
if ( V_150 < V_147 )
return V_155 ;
V_154 = & V_133 [ V_147 ] ;
}
if ( V_148 ) {
V_153 = 0 ;
V_139 = V_148 ;
} else {
V_153 = 1 ;
V_139 = V_154 [ 0 ] ;
if ( V_139 == 0xFFFF || V_139 == 0 ||
( V_147 + V_139 ) >= V_2 -> V_50 . V_80 )
return 0 ;
}
if ( V_133 && ( ( T_2 ) V_153 + ( T_2 ) V_139 > V_150 ) )
return V_155 ;
for ( V_83 = V_153 ; V_139 ; V_83 ++ , V_139 -- ) {
if ( V_83 == V_152 && ! V_133 ) {
V_147 += V_152 ;
V_83 = 0 ;
if ( V_139 < V_152 )
V_152 = V_139 ;
V_28 = F_47 ( V_2 , V_147 ,
V_152 , V_151 ) ;
if ( V_28 ) {
F_33 ( V_2 , L_12 ) ;
return V_28 ;
}
}
* V_149 += V_154 [ V_83 ] ;
}
return 0 ;
}
static T_1 F_49 ( struct V_1 * V_2 , T_3 * V_133 ,
T_2 V_150 )
{
T_3 V_156 [ V_157 + 1 ] ;
T_3 * V_154 ;
T_1 V_28 ;
T_3 V_106 = 0 ;
T_3 V_158 , V_83 , V_148 ;
V_2 -> V_50 . V_9 . V_159 ( V_2 ) ;
if ( ! V_133 ) {
V_28 = F_47 ( V_2 , 0 ,
V_157 + 1 ,
V_156 ) ;
if ( V_28 ) {
F_33 ( V_2 , L_12 ) ;
return V_28 ;
}
V_154 = V_156 ;
} else {
if ( V_150 < V_157 )
return V_155 ;
V_154 = V_133 ;
}
for ( V_83 = 0 ; V_83 <= V_157 ; V_83 ++ )
if ( V_83 != V_160 )
V_106 += V_154 [ V_83 ] ;
for ( V_83 = V_161 ; V_83 < V_162 ; V_83 ++ ) {
if ( V_83 == V_163 || V_83 == V_164 )
continue;
V_158 = V_154 [ V_83 ] ;
if ( V_158 == 0xFFFF || V_158 == 0 ||
V_158 >= V_2 -> V_50 . V_80 )
continue;
switch ( V_83 ) {
case V_165 :
V_148 = V_166 ;
break;
case V_167 :
case V_168 :
V_148 = V_169 ;
break;
default:
V_148 = 0 ;
break;
}
V_28 = F_48 ( V_2 , V_158 , V_148 , & V_106 ,
V_133 , V_150 ) ;
if ( V_28 )
return V_28 ;
}
V_106 = ( T_3 ) V_170 - V_106 ;
return ( T_1 ) V_106 ;
}
static T_1 F_50 ( struct V_1 * V_2 )
{
return F_49 ( V_2 , NULL , 0 ) ;
}
static T_1 F_51 ( struct V_1 * V_2 , T_3 V_131 , T_3 * V_88 )
{
T_1 V_28 = 0 ;
if ( V_2 -> V_4 . V_9 . V_44 ( V_2 , V_145 ) == 0 ) {
V_28 = F_45 ( V_2 , V_131 , V_88 ) ;
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_145 ) ;
} else {
V_28 = V_171 ;
}
return V_28 ;
}
static T_1 F_52 ( struct V_1 * V_2 ,
T_3 * V_172 )
{
T_1 V_28 ;
T_3 V_106 ;
T_3 V_173 = 0 ;
V_28 = V_2 -> V_50 . V_9 . V_174 ( V_2 , 0 , & V_106 ) ;
if ( V_28 ) {
F_33 ( V_2 , L_13 ) ;
return V_28 ;
}
V_28 = V_2 -> V_50 . V_9 . V_175 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
V_106 = ( T_3 ) ( V_28 & 0xffff ) ;
V_28 = F_51 ( V_2 , V_160 ,
& V_173 ) ;
if ( V_28 )
return V_28 ;
if ( V_173 != V_106 ) {
V_28 = V_176 ;
F_33 ( V_2 , L_14 ) ;
}
if ( V_172 )
* V_172 = V_106 ;
return V_28 ;
}
static T_1 F_53 ( struct V_1 * V_2 , T_3 V_131 ,
T_3 V_88 )
{
T_1 V_28 ;
struct V_177 V_133 ;
V_133 . V_99 . V_134 . V_100 = V_178 ;
V_133 . V_99 . V_134 . V_136 = 0 ;
V_133 . V_99 . V_134 . V_137 = V_179 ;
V_133 . V_99 . V_134 . V_106 = V_107 ;
V_133 . V_139 = F_41 ( sizeof( T_3 ) ) ;
V_133 . V_88 = V_88 ;
V_133 . V_124 = F_42 ( V_131 * 2 ) ;
V_28 = F_38 ( V_2 , & V_133 , sizeof( V_133 ) ,
V_112 , false ) ;
return V_28 ;
}
static T_1 F_54 ( struct V_1 * V_2 , T_3 V_131 , T_3 V_88 )
{
T_1 V_28 = 0 ;
if ( V_2 -> V_4 . V_9 . V_44 ( V_2 , V_145 ) == 0 ) {
V_28 = F_53 ( V_2 , V_131 , V_88 ) ;
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_145 ) ;
} else {
F_33 ( V_2 , L_15 ) ;
V_28 = V_171 ;
}
return V_28 ;
}
static T_1 F_55 ( struct V_1 * V_2 )
{
T_1 V_28 = 0 ;
union V_180 V_133 ;
V_133 . V_134 . V_100 = V_181 ;
V_133 . V_134 . V_136 = 0 ;
V_133 . V_134 . V_137 = V_182 ;
V_133 . V_134 . V_106 = V_107 ;
V_28 = F_38 ( V_2 , & V_133 , sizeof( V_133 ) ,
V_112 , false ) ;
return V_28 ;
}
static T_1 F_56 ( struct V_1 * V_2 )
{
V_2 -> V_17 . type = V_183 ;
V_2 -> V_17 . V_184 = V_185 ;
V_2 -> V_17 . V_186 = V_187 ;
V_2 -> V_4 . V_9 . V_188 ( V_2 ) ;
return 0 ;
}
static void F_57 ( struct V_1 * V_2 )
{
T_2 V_189 , V_190 ;
T_1 V_28 ;
struct V_191 V_192 ;
V_189 = F_5 ( V_2 , V_193 ) ;
if ( V_189 & V_194 ) {
V_190 = F_5 ( V_2 , V_195 ) ;
if ( V_190 & V_196 ) {
V_190 &= ~ V_196 ;
F_6 ( V_2 , V_195 , V_190 ) ;
V_2 -> V_4 . V_197 = true ;
} else {
V_2 -> V_4 . V_197 = false ;
}
V_192 . V_99 . V_100 = V_198 ;
V_192 . V_99 . V_102 = V_199 ;
V_192 . V_99 . V_106 = V_107 ;
V_192 . V_108 = V_2 -> V_17 . V_18 ;
V_28 = F_38 ( V_2 , & V_192 ,
sizeof( struct V_191 ) ,
V_112 , true ) ;
if ( V_28 ) {
V_189 = F_5 ( V_2 , V_193 ) ;
if ( V_189 & V_194 ) {
V_189 &= ~ V_194 ;
F_6 ( V_2 , V_193 , V_189 ) ;
}
}
}
}
static T_1 F_58 ( struct V_1 * V_2 )
{
T_1 V_28 ;
T_3 V_106 = 0 ;
V_28 = F_51 ( V_2 , 0 , & V_106 ) ;
if ( V_28 ) {
F_33 ( V_2 , L_13 ) ;
return V_28 ;
}
V_28 = F_50 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
V_106 = ( T_3 ) ( V_28 & 0xffff ) ;
V_28 = F_54 ( V_2 , V_160 ,
V_106 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_55 ( V_2 ) ;
return V_28 ;
}
static T_1 F_59 ( struct V_1 * V_2 ,
T_3 V_131 , T_3 V_142 ,
T_3 * V_88 )
{
T_1 V_28 = 0 ;
T_2 V_83 = 0 ;
V_28 = V_2 -> V_4 . V_9 . V_44 ( V_2 , V_145 ) ;
if ( V_28 ) {
F_33 ( V_2 , L_16 ) ;
return V_28 ;
}
for ( V_83 = 0 ; V_83 < V_142 ; V_83 ++ ) {
V_28 = F_53 ( V_2 , V_131 + V_83 ,
V_88 [ V_83 ] ) ;
if ( V_28 ) {
F_33 ( V_2 , L_17 ) ;
break;
}
}
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_145 ) ;
return V_28 ;
}
static T_1 F_60 ( struct V_1 * V_2 , T_2 V_68 ,
T_2 V_69 , T_2 V_88 )
{
T_2 V_89 = V_54 | V_55 ;
T_2 V_84 , error ;
T_1 V_90 ;
V_90 = V_2 -> V_4 . V_9 . V_44 ( V_2 , V_89 ) ;
if ( V_90 )
return V_90 ;
V_90 = F_34 ( V_2 , NULL ) ;
if ( V_90 )
goto V_47;
V_84 = ( ( V_68 << V_91 ) |
( V_69 << V_92 ) ) ;
F_6 ( V_2 , V_86 , V_84 ) ;
F_6 ( V_2 , V_96 , V_88 ) ;
V_90 = F_34 ( V_2 , & V_84 ) ;
if ( ( V_84 & V_93 ) != 0 ) {
error = ( V_84 & V_94 ) >>
V_95 ;
F_33 ( V_2 , L_18 , error ) ;
return V_40 ;
}
V_47:
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_89 ) ;
return V_90 ;
}
static T_1 F_61 ( struct V_1 * V_2 )
{
T_1 V_28 ;
T_2 V_200 ;
V_28 = F_36 ( V_2 ,
F_62 ( V_2 -> V_17 . V_18 ) ,
V_201 , & V_200 ) ;
if ( V_28 )
return V_28 ;
V_200 |= V_202 ;
V_28 = F_60 ( V_2 ,
F_62 ( V_2 -> V_17 . V_18 ) ,
V_201 , V_200 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_36 ( V_2 ,
F_63 ( V_2 -> V_17 . V_18 ) ,
V_201 , & V_200 ) ;
if ( V_28 )
return V_28 ;
V_200 &= ~ V_203 ;
V_200 &= ~ V_204 ;
V_200 &= ~ V_205 ;
V_28 = F_60 ( V_2 ,
F_63 ( V_2 -> V_17 . V_18 ) ,
V_201 , V_200 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_36 ( V_2 ,
F_64 ( V_2 -> V_17 . V_18 ) ,
V_201 , & V_200 ) ;
if ( V_28 )
return V_28 ;
V_200 &= ~ V_203 ;
V_200 &= ~ V_204 ;
V_200 &= ~ V_205 ;
V_28 = F_60 ( V_2 ,
F_64 ( V_2 -> V_17 . V_18 ) ,
V_201 , V_200 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_36 ( V_2 ,
F_65 ( V_2 -> V_17 . V_18 ) ,
V_201 , & V_200 ) ;
if ( V_28 )
return V_28 ;
V_200 |= V_206 ;
V_200 |= V_207 ;
V_200 |= V_208 ;
V_200 |= V_209 ;
V_28 = F_60 ( V_2 ,
F_65 ( V_2 -> V_17 . V_18 ) ,
V_201 , V_200 ) ;
return V_28 ;
}
static T_1 F_66 ( struct V_1 * V_2 )
{
T_1 V_28 ;
T_2 V_210 ;
V_28 = V_2 -> V_4 . V_9 . V_211 ( V_2 ,
F_67 ( V_2 -> V_17 . V_18 ) ,
V_201 , & V_210 ) ;
if ( V_28 ) {
F_33 ( V_2 , L_19 ) ;
return V_28 ;
}
V_210 |= V_212 ;
V_28 = V_2 -> V_4 . V_9 . V_213 ( V_2 ,
F_67 ( V_2 -> V_17 . V_18 ) ,
V_201 , V_210 ) ;
if ( V_2 -> V_4 . type == V_214 ) {
T_2 V_215 ;
V_28 = V_2 -> V_4 . V_9 . V_211 ( V_2 ,
F_68 ( V_2 -> V_17 . V_18 ) ,
V_201 , & V_215 ) ;
if ( V_28 ) {
F_33 ( V_2 , L_19 ) ;
return V_28 ;
}
V_215 |= V_216 ;
V_28 = V_2 -> V_4 . V_9 . V_213 ( V_2 ,
F_68 ( V_2 -> V_17 . V_18 ) ,
V_201 , V_215 ) ;
}
return V_28 ;
}
static T_1 F_69 ( struct V_1 * V_2 , T_6 * V_186 )
{
T_1 V_28 ;
T_2 V_200 ;
V_28 = F_36 ( V_2 ,
F_67 ( V_2 -> V_17 . V_18 ) ,
V_201 , & V_200 ) ;
if ( V_28 )
return V_28 ;
V_200 &= ~ V_217 ;
V_200 &= ~ V_218 ;
switch ( * V_186 ) {
case V_219 :
V_200 |= V_220 ;
break;
case V_221 :
V_200 |= V_222 ;
break;
default:
return V_223 ;
}
V_28 = F_60 ( V_2 ,
F_67 ( V_2 -> V_17 . V_18 ) ,
V_201 , V_200 ) ;
if ( V_28 )
return V_28 ;
if ( V_2 -> V_4 . type == V_224 ) {
V_28 = F_61 ( V_2 ) ;
if ( V_28 )
return V_28 ;
}
V_28 = F_66 ( V_2 ) ;
return V_28 ;
}
static T_1 F_70 ( struct V_1 * V_2 , bool * V_225 )
{
switch ( V_2 -> V_6 . V_226 ) {
case V_227 :
return V_228 ;
case V_229 :
case V_230 :
* V_225 = true ;
break;
case V_231 :
case V_232 :
case V_233 :
case V_234 :
case V_235 :
case V_236 :
case V_237 :
case V_238 :
* V_225 = false ;
break;
case V_239 :
case V_240 :
case V_241 :
default:
return V_242 ;
}
return 0 ;
}
static T_1
F_71 ( struct V_1 * V_2 ,
T_6 V_186 ,
T_5 bool V_243 )
{
T_1 V_28 ;
T_3 V_244 , V_200 ;
bool V_245 = false ;
V_28 = F_70 ( V_2 , & V_245 ) ;
if ( V_28 == V_228 )
return 0 ;
if ( V_28 )
return V_28 ;
F_72 ( V_2 , V_186 ) ;
V_244 = V_246 + ( V_2 -> V_17 . V_18 << 12 ) ;
if ( V_245 )
V_200 = ( V_247 << 1 ) | 0x1 ;
else
V_200 = ( V_248 << 1 ) | 0x1 ;
V_28 = V_2 -> V_8 . V_9 . V_249 ( V_2 , V_2 -> V_8 . V_13 , V_244 ,
V_200 ) ;
return V_28 ;
}
static T_1 F_73 ( struct V_1 * V_2 , T_6 * V_186 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_28 ;
T_2 V_200 ;
V_28 = V_4 -> V_9 . V_211 ( V_2 ,
F_68 ( V_2 -> V_17 . V_18 ) ,
V_201 , & V_200 ) ;
if ( V_28 )
return V_28 ;
V_200 &= ~ V_250 ;
V_200 &= ~ V_251 ;
V_200 &= ~ V_252 ;
V_200 &= ~ V_253 ;
switch ( * V_186 ) {
case V_219 :
V_200 |= V_254 ;
break;
case V_221 :
V_200 |= V_255 ;
break;
default:
return V_223 ;
}
V_28 = V_4 -> V_9 . V_213 ( V_2 ,
F_68 ( V_2 -> V_17 . V_18 ) ,
V_201 , V_200 ) ;
V_28 = F_66 ( V_2 ) ;
return V_28 ;
}
static T_1
F_74 ( struct V_1 * V_2 , T_6 V_186 ,
T_5 bool V_243 )
{
bool V_245 = false ;
T_2 V_256 ;
T_1 V_257 ;
V_257 = F_70 ( V_2 , & V_245 ) ;
if ( V_257 == V_228 )
return 0 ;
if ( ! V_257 )
return V_257 ;
V_257 = V_2 -> V_4 . V_9 . V_211 ( V_2 ,
F_68 ( V_2 -> V_17 . V_18 ) ,
V_201 , & V_256 ) ;
if ( ! V_257 )
return V_257 ;
V_256 &= V_258 ;
if ( ! V_245 )
V_256 |= V_259 ;
V_257 = V_2 -> V_4 . V_9 . V_213 ( V_2 ,
F_68 ( V_2 -> V_17 . V_18 ) ,
V_201 , V_256 ) ;
if ( ! V_257 )
return V_257 ;
return F_73 ( V_2 , & V_186 ) ;
}
static T_1
F_75 ( struct V_1 * V_2 , T_6 V_186 ,
T_5 bool V_243 )
{
T_2 V_244 , V_260 ;
bool V_245 = false ;
T_3 V_261 ;
T_1 V_257 ;
V_257 = F_70 ( V_2 , & V_245 ) ;
if ( V_257 == V_228 )
return 0 ;
if ( ! V_257 )
return V_257 ;
F_72 ( V_2 , V_186 ) ;
if ( V_2 -> V_6 . V_262 . V_263 == V_264 )
return V_265 ;
V_257 = V_2 -> V_6 . V_9 . V_266 ( V_2 , V_267 ,
V_268 , & V_261 ) ;
if ( V_257 )
return V_257 ;
if ( V_261 == V_269 )
V_260 = ( V_2 -> V_17 . V_18 +
( V_2 -> V_17 . V_270 << 1 ) ) << 12 ;
else
V_260 = V_2 -> V_17 . V_18 << 12 ;
V_244 = V_246 + V_260 ;
if ( V_245 )
V_261 = ( V_247 << 1 ) | 1 ;
else
V_261 = ( V_248 << 1 ) | 1 ;
return V_2 -> V_6 . V_9 . V_271 ( V_2 , V_244 , V_268 ,
V_261 ) ;
}
static T_1 F_76 ( struct V_1 * V_2 ,
T_6 V_186 ,
bool V_272 )
{
T_1 V_28 ;
T_6 V_273 ;
if ( V_186 & V_219 )
V_273 = V_219 ;
else
V_273 = V_221 ;
if ( ! ( V_2 -> V_6 . V_274 & V_275 ) ) {
V_28 = F_69 ( V_2 , & V_273 ) ;
if ( V_28 )
return V_28 ;
}
return V_2 -> V_6 . V_9 . V_276 ( V_2 , V_186 , V_272 ) ;
}
static T_1 F_77 ( struct V_1 * V_2 ,
T_6 * V_186 ,
bool * V_277 ,
bool V_278 )
{
T_2 V_28 ;
T_3 V_83 , V_279 ;
if ( V_2 -> V_4 . V_9 . V_10 ( V_2 ) != V_11 )
return V_280 ;
V_28 = F_78 ( V_2 , V_186 , V_277 ,
V_278 ) ;
if ( V_28 || ! ( * V_277 ) )
return V_28 ;
for ( V_83 = 0 ; V_83 < 2 ; V_83 ++ ) {
V_28 = V_2 -> V_6 . V_9 . V_266 ( V_2 , V_281 , V_282 ,
& V_279 ) ;
if ( V_28 )
return V_28 ;
}
if ( ! ( V_279 & V_283 ) )
* V_277 = false ;
return 0 ;
}
static T_1
F_79 ( struct V_1 * V_2 , T_5 T_6 V_186 ,
T_5 bool V_243 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_2 V_284 , V_285 , V_286 ;
T_1 V_287 ;
V_287 = V_4 -> V_9 . V_211 ( V_2 ,
F_67 ( V_2 -> V_17 . V_18 ) ,
V_201 , & V_284 ) ;
if ( V_287 )
return V_287 ;
V_284 &= ~ V_217 ;
V_284 &= ~ V_218 ;
V_284 |= V_288 ;
V_284 |= V_289 ;
V_284 |= V_222 ;
V_287 = V_4 -> V_9 . V_213 ( V_2 ,
F_67 ( V_2 -> V_17 . V_18 ) ,
V_201 , V_284 ) ;
if ( V_287 )
return V_287 ;
V_287 = V_4 -> V_9 . V_211 ( V_2 ,
F_80 ( V_2 -> V_17 . V_18 ) ,
V_201 , & V_285 ) ;
if ( V_287 )
return V_287 ;
V_285 |= V_290 ;
V_285 |= V_291 ;
V_287 = V_4 -> V_9 . V_213 ( V_2 ,
F_80 ( V_2 -> V_17 . V_18 ) ,
V_201 , V_285 ) ;
if ( V_287 )
return V_287 ;
V_287 = V_4 -> V_9 . V_211 ( V_2 ,
F_68 ( V_2 -> V_17 . V_18 ) ,
V_201 , & V_286 ) ;
if ( V_287 )
return V_287 ;
V_287 = V_4 -> V_9 . V_211 ( V_2 ,
F_68 ( V_2 -> V_17 . V_18 ) ,
V_201 , & V_286 ) ;
if ( V_287 )
return V_287 ;
V_286 &= ~ V_253 ;
V_286 |= V_255 ;
V_286 &= ~ V_250 ;
V_286 |= V_252 ;
V_286 |= V_251 ;
V_287 = V_4 -> V_9 . V_213 ( V_2 ,
F_68 ( V_2 -> V_17 . V_18 ) ,
V_201 , V_286 ) ;
if ( V_287 )
return V_287 ;
V_287 = F_66 ( V_2 ) ;
return V_287 ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
switch ( V_4 -> V_9 . V_10 ( V_2 ) ) {
case V_292 :
V_4 -> V_9 . V_293 = NULL ;
V_4 -> V_9 . V_294 = V_295 ;
break;
case V_296 :
V_4 -> V_9 . V_294 = V_297 ;
V_4 -> V_9 . V_293 = V_298 ;
break;
default:
break;
}
}
static void F_82 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
V_4 -> V_9 . V_293 = V_299 ;
switch ( V_4 -> V_9 . V_10 ( V_2 ) ) {
case V_292 :
V_4 -> V_9 . V_300 = NULL ;
V_4 -> V_9 . V_301 = NULL ;
V_4 -> V_9 . V_302 = NULL ;
V_4 -> V_9 . V_303 = V_304 ;
switch ( V_2 -> V_52 ) {
case V_58 :
V_4 -> V_9 . V_305 = F_74 ;
break;
case V_53 :
V_4 -> V_9 . V_305 =
F_75 ;
break;
default:
V_4 -> V_9 . V_305 =
F_71 ;
break;
}
V_4 -> V_9 . V_306 =
V_307 ;
break;
case V_11 :
V_4 -> V_9 . V_303 = F_76 ;
V_4 -> V_9 . V_293 = V_308 ;
V_4 -> V_9 . V_309 = F_77 ;
return;
case V_296 :
if ( V_2 -> V_52 == V_310 ||
V_2 -> V_52 == V_311 )
V_4 -> V_9 . V_303 = F_79 ;
break;
default:
break;
}
if ( V_2 -> V_4 . type == V_214 )
F_81 ( V_2 ) ;
}
static T_1 F_83 ( struct V_1 * V_2 )
{
T_1 V_28 ;
bool V_225 ;
V_28 = F_70 ( V_2 , & V_225 ) ;
if ( V_28 )
return V_28 ;
F_82 ( V_2 ) ;
V_2 -> V_6 . V_9 . V_312 = NULL ;
return 0 ;
}
static T_1 F_84 ( struct V_1 * V_2 ,
T_6 * V_186 ,
bool * V_313 )
{
if ( V_2 -> V_6 . V_314 == V_292 ) {
* V_313 = false ;
if ( V_2 -> V_6 . V_226 == V_235 ||
V_2 -> V_6 . V_226 == V_236 ) {
* V_186 = V_221 ;
return 0 ;
}
if ( V_2 -> V_6 . V_315 )
* V_186 = V_219 |
V_221 ;
else
* V_186 = V_219 ;
} else {
* V_186 = V_219 |
V_221 ;
* V_313 = true ;
}
return 0 ;
}
static T_1 F_85 ( struct V_1 * V_2 , bool * V_316 )
{
T_2 V_28 ;
T_3 V_24 ;
* V_316 = false ;
V_28 = V_2 -> V_6 . V_9 . V_266 ( V_2 , V_317 ,
V_318 ,
& V_24 ) ;
if ( V_28 || ! ( V_24 & V_319 ) )
return V_28 ;
V_28 = V_2 -> V_6 . V_9 . V_266 ( V_2 , V_320 ,
V_318 ,
& V_24 ) ;
if ( V_28 || ! ( V_24 & ( V_321 |
V_322 ) ) )
return V_28 ;
V_28 = V_2 -> V_6 . V_9 . V_266 ( V_2 , V_323 ,
V_318 ,
& V_24 ) ;
if ( V_28 )
return V_28 ;
if ( V_24 & V_324 ) {
F_86 ( V_2 , false ) ;
return V_325 ;
}
if ( V_24 & V_326 ) {
V_28 = V_2 -> V_6 . V_9 . V_266 ( V_2 , V_327 ,
V_318 ,
& V_24 ) ;
if ( V_28 )
return V_28 ;
if ( V_24 == V_328 ) {
F_86 ( V_2 , false ) ;
return V_325 ;
}
}
V_28 = V_2 -> V_6 . V_9 . V_266 ( V_2 , V_317 ,
V_282 , & V_24 ) ;
if ( V_28 || ! ( V_24 & V_329 ) )
return V_28 ;
V_28 = V_2 -> V_6 . V_9 . V_266 ( V_2 , V_330 ,
V_282 , & V_24 ) ;
if ( V_28 )
return V_28 ;
if ( V_24 & V_331 )
* V_316 = true ;
return 0 ;
}
static T_1 F_87 ( struct V_1 * V_2 )
{
T_2 V_28 ;
T_3 V_24 ;
bool V_316 ;
V_28 = F_85 ( V_2 , & V_316 ) ;
V_28 = V_2 -> V_6 . V_9 . V_266 ( V_2 , V_332 ,
V_282 , & V_24 ) ;
if ( V_28 )
return V_28 ;
V_24 |= V_333 ;
V_28 = V_2 -> V_6 . V_9 . V_271 ( V_2 , V_332 ,
V_282 , V_24 ) ;
if ( V_28 )
return V_28 ;
V_28 = V_2 -> V_6 . V_9 . V_266 ( V_2 , V_334 ,
V_318 ,
& V_24 ) ;
if ( V_28 )
return V_28 ;
V_24 |= ( V_335 |
V_336 ) ;
V_28 = V_2 -> V_6 . V_9 . V_271 ( V_2 , V_334 ,
V_318 ,
V_24 ) ;
if ( V_28 )
return V_28 ;
V_28 = V_2 -> V_6 . V_9 . V_266 ( V_2 , V_337 ,
V_318 ,
& V_24 ) ;
if ( V_28 )
return V_28 ;
V_24 |= ( V_321 |
V_322 ) ;
V_28 = V_2 -> V_6 . V_9 . V_271 ( V_2 , V_337 ,
V_318 ,
V_24 ) ;
if ( V_28 )
return V_28 ;
V_28 = V_2 -> V_6 . V_9 . V_266 ( V_2 , V_338 ,
V_318 ,
& V_24 ) ;
if ( V_28 )
return V_28 ;
V_24 |= V_319 ;
V_28 = V_2 -> V_6 . V_9 . V_271 ( V_2 , V_338 ,
V_318 ,
V_24 ) ;
return V_28 ;
}
static T_1 F_88 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
bool V_316 ;
T_2 V_28 ;
V_28 = F_85 ( V_2 , & V_316 ) ;
if ( V_28 )
return V_28 ;
if ( V_316 && V_6 -> V_9 . V_339 )
return V_6 -> V_9 . V_339 ( V_2 ) ;
return 0 ;
}
static T_1 F_72 ( struct V_1 * V_2 ,
T_6 V_186 )
{
T_1 V_28 ;
T_2 V_200 ;
V_28 = V_2 -> V_4 . V_9 . V_211 ( V_2 ,
F_67 ( V_2 -> V_17 . V_18 ) ,
V_201 , & V_200 ) ;
if ( V_28 )
return V_28 ;
V_200 |= V_217 ;
V_200 &= ~ ( V_340 |
V_341 ) ;
V_200 &= ~ ( V_342 |
V_343 ) ;
if ( V_186 & V_219 )
V_200 |= V_342 ;
if ( V_186 & V_221 )
V_200 |= V_343 ;
V_28 = V_2 -> V_4 . V_9 . V_213 ( V_2 ,
F_67 ( V_2 -> V_17 . V_18 ) ,
V_201 , V_200 ) ;
if ( V_2 -> V_4 . type == V_214 ) {
V_28 = V_2 -> V_4 . V_9 . V_211 ( V_2 ,
F_68 ( V_2 -> V_17 . V_18 ) ,
V_201 , & V_200 ) ;
if ( V_28 )
return V_28 ;
V_200 &= ~ V_253 ;
V_200 |= V_344 ;
V_200 |= V_250 ;
V_200 &= ~ V_251 ;
V_200 &= ~ V_252 ;
V_28 = V_2 -> V_4 . V_9 . V_213 ( V_2 ,
F_68 ( V_2 -> V_17 . V_18 ) ,
V_201 , V_200 ) ;
}
return F_66 ( V_2 ) ;
}
static T_1 F_89 ( struct V_1 * V_2 )
{
T_1 V_28 ;
T_2 V_200 ;
V_28 = V_2 -> V_4 . V_9 . V_211 ( V_2 , V_345 ,
V_346 +
V_2 -> V_17 . V_18 , & V_200 ) ;
if ( V_28 )
return V_28 ;
V_200 &= ~ ( V_347 |
V_348 ) ;
V_200 |= V_349 ;
if ( V_2 -> V_6 . V_350 & V_219 )
V_200 |= V_347 ;
if ( V_2 -> V_6 . V_350 & V_221 )
V_200 |= V_348 ;
V_200 |= V_351 ;
V_28 = V_2 -> V_4 . V_9 . V_213 ( V_2 , V_345 ,
V_346 +
V_2 -> V_17 . V_18 , V_200 ) ;
return V_28 ;
}
static T_1 F_90 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 . type != V_224 )
return 0 ;
return F_72 ( V_2 , V_2 -> V_6 . V_350 ) ;
}
static T_1 F_91 ( struct V_1 * V_2 , bool * V_277 )
{
T_2 V_90 ;
T_3 V_279 ;
* V_277 = false ;
V_90 = V_2 -> V_6 . V_9 . V_266 ( V_2 , V_281 , V_282 ,
& V_279 ) ;
if ( V_90 )
return V_90 ;
V_90 = V_2 -> V_6 . V_9 . V_266 ( V_2 , V_281 , V_282 ,
& V_279 ) ;
if ( V_90 )
return V_90 ;
* V_277 = ! ! ( V_279 & V_283 ) ;
return 0 ;
}
static T_1 F_92 ( struct V_1 * V_2 )
{
T_6 V_273 ;
bool V_277 ;
T_2 V_28 ;
T_3 V_186 ;
if ( V_2 -> V_4 . V_9 . V_10 ( V_2 ) != V_11 )
return V_280 ;
if ( V_2 -> V_6 . V_274 & V_275 ) {
V_186 = V_219 |
V_221 ;
return F_72 ( V_2 , V_186 ) ;
}
V_28 = F_91 ( V_2 , & V_277 ) ;
if ( V_28 )
return V_28 ;
if ( ! V_277 )
return 0 ;
V_28 = V_2 -> V_6 . V_9 . V_266 ( V_2 , V_352 ,
V_282 ,
& V_186 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_91 ( V_2 , & V_277 ) ;
if ( V_28 )
return V_28 ;
if ( ! V_277 )
return 0 ;
V_186 &= V_353 ;
switch ( V_186 ) {
case V_354 :
V_273 = V_219 ;
break;
case V_355 :
V_273 = V_221 ;
break;
default:
return V_356 ;
}
return F_69 ( V_2 , & V_273 ) ;
}
static T_1 F_93 ( struct V_1 * V_2 )
{
T_1 V_28 ;
V_28 = F_94 ( V_2 ) ;
if ( V_28 )
return V_28 ;
return F_87 ( V_2 ) ;
}
static T_1 F_95 ( struct V_1 * V_2 , T_2 V_357 )
{
T_3 V_70 ;
if ( V_357 >= V_358 )
return V_155 ;
V_2 -> V_6 . V_9 . V_266 ( V_2 , V_359 + V_357 ,
V_318 , & V_70 ) ;
V_70 |= V_360 ;
V_2 -> V_6 . V_9 . V_271 ( V_2 , V_359 + V_357 ,
V_318 , V_70 ) ;
return 0 ;
}
static T_1 F_96 ( struct V_1 * V_2 , T_2 V_357 )
{
T_3 V_70 ;
if ( V_357 >= V_358 )
return V_155 ;
V_2 -> V_6 . V_9 . V_266 ( V_2 , V_359 + V_357 ,
V_318 , & V_70 ) ;
V_70 &= ~ V_360 ;
V_2 -> V_6 . V_9 . V_271 ( V_2 , V_359 + V_357 ,
V_318 , V_70 ) ;
return 0 ;
}
static T_1 F_97 ( struct V_1 * V_2 ,
T_6 * V_361 )
{
T_3 V_362 ;
T_1 V_28 ;
T_3 V_363 = V_2 -> V_50 . V_364 ;
* V_361 = V_365 ;
V_28 = V_2 -> V_6 . V_9 . V_266 ( V_2 , V_366 ,
V_282 ,
& V_362 ) ;
if ( V_28 )
return V_28 ;
if ( V_362 & V_367 ) {
* V_361 = V_221 ;
return V_28 ;
}
if ( ( V_2 -> V_17 . V_18 && ( V_363 & V_368 ) ) ||
( V_363 & V_369 ) )
return V_28 ;
* V_361 = V_219 ;
return V_28 ;
}
static T_1 V_299 ( struct V_1 * V_2 )
{
bool V_370 , V_371 ;
T_2 V_200 ;
T_1 V_287 ;
if ( V_2 -> V_372 . V_373 && V_2 -> V_372 . V_374 == V_375 ) {
F_12 ( V_2 , L_20 ) ;
return V_356 ;
}
if ( V_2 -> V_372 . V_374 == V_376 )
V_2 -> V_372 . V_374 = V_377 ;
switch ( V_2 -> V_372 . V_374 ) {
case V_378 :
V_370 = false ;
V_371 = false ;
break;
case V_379 :
V_370 = false ;
V_371 = true ;
break;
case V_375 :
case V_377 :
V_370 = true ;
V_371 = true ;
break;
default:
F_12 ( V_2 , L_21 ) ;
return V_280 ;
}
if ( V_2 -> V_52 != V_61 &&
V_2 -> V_52 != V_62 &&
V_2 -> V_52 != V_63 )
return 0 ;
V_287 = V_2 -> V_4 . V_9 . V_211 ( V_2 ,
F_98 ( V_2 -> V_17 . V_18 ) ,
V_201 ,
& V_200 ) ;
if ( V_287 )
return V_287 ;
V_200 &= ~ ( V_380 |
V_381 ) ;
if ( V_370 )
V_200 |= V_380 ;
if ( V_371 )
V_200 |= V_381 ;
V_287 = V_2 -> V_4 . V_9 . V_213 ( V_2 ,
F_98 ( V_2 -> V_17 . V_18 ) ,
V_201 ,
V_200 ) ;
V_2 -> V_372 . V_382 = true ;
return V_287 ;
}
static void V_297 ( struct V_1 * V_2 )
{
T_2 V_383 , V_384 , V_385 ;
T_1 V_28 = V_386 ;
T_6 V_186 ;
bool V_277 ;
if ( V_2 -> V_372 . V_382 ) {
F_12 ( V_2 , L_22 ) ;
goto V_47;
}
V_2 -> V_4 . V_9 . V_309 ( V_2 , & V_186 , & V_277 , false ) ;
if ( ! V_277 ) {
F_12 ( V_2 , L_23 ) ;
goto V_47;
}
V_28 = V_2 -> V_4 . V_9 . V_211 ( V_2 ,
F_99 ( V_2 -> V_17 . V_18 ) ,
V_201 , & V_383 ) ;
if ( V_28 || ( V_383 & V_387 ) == 0 ) {
F_33 ( V_2 , L_24 ) ;
V_28 = V_386 ;
goto V_47;
}
V_28 = V_2 -> V_4 . V_9 . V_211 ( V_2 ,
F_98 ( V_2 -> V_17 . V_18 ) ,
V_201 , & V_385 ) ;
if ( V_28 ) {
F_33 ( V_2 , L_24 ) ;
goto V_47;
}
V_28 = V_2 -> V_4 . V_9 . V_211 ( V_2 ,
F_100 ( V_2 -> V_17 . V_18 ) ,
V_201 , & V_384 ) ;
if ( V_28 ) {
F_33 ( V_2 , L_24 ) ;
goto V_47;
}
V_28 = F_101 ( V_2 , V_385 , V_384 ,
V_380 ,
V_381 ,
V_388 ,
V_389 ) ;
V_47:
if ( ! V_28 ) {
V_2 -> V_372 . V_390 = true ;
} else {
V_2 -> V_372 . V_390 = false ;
V_2 -> V_372 . V_391 = V_2 -> V_372 . V_374 ;
}
}
static void V_295 ( struct V_1 * V_2 )
{
V_2 -> V_372 . V_390 = false ;
V_2 -> V_372 . V_391 = V_2 -> V_372 . V_374 ;
}
static T_1 F_102 ( struct V_1 * V_2 )
{
T_3 V_392 , V_393 , V_186 ;
T_1 V_28 ;
T_6 V_361 ;
T_2 V_394 ;
bool V_277 ;
if ( F_103 ( V_2 ) )
return 0 ;
V_28 = F_91 ( V_2 , & V_277 ) ;
if ( V_28 )
return V_28 ;
V_28 = V_2 -> V_50 . V_9 . V_174 ( V_2 , V_395 ,
& V_2 -> V_50 . V_364 ) ;
if ( V_28 )
return V_28 ;
if ( ! V_277 || ! ( V_2 -> V_50 . V_364 & V_396 ) ||
! ( V_2 -> V_397 || F_104 ( V_2 ) ) )
return F_86 ( V_2 , false ) ;
V_28 = F_97 ( V_2 , & V_361 ) ;
if ( V_28 )
return V_28 ;
if ( V_361 == V_365 )
return F_86 ( V_2 , false ) ;
V_28 = V_2 -> V_6 . V_9 . V_266 ( V_2 , V_352 ,
V_282 ,
& V_186 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_91 ( V_2 , & V_277 ) ;
if ( V_28 )
return F_86 ( V_2 , false ) ;
V_186 &= V_398 ;
if ( ( ( V_186 == V_399 ) &&
( V_361 == V_221 ) ) ||
( ( V_186 == V_400 ) &&
( V_361 == V_219 ) ) )
return V_28 ;
V_28 = V_2 -> V_6 . V_9 . V_266 ( V_2 , V_401 ,
V_282 ,
& V_393 ) ;
if ( V_28 )
return V_28 ;
V_28 = V_2 -> V_6 . V_9 . V_266 ( V_2 , V_402 ,
V_282 ,
& V_392 ) ;
if ( V_28 )
return V_28 ;
V_28 = V_2 -> V_6 . V_9 . V_266 ( V_2 ,
V_403 ,
V_282 ,
& V_393 ) ;
if ( V_28 )
return V_28 ;
V_394 = V_2 -> V_6 . V_350 ;
V_28 = V_2 -> V_4 . V_9 . V_303 ( V_2 , V_361 , false ) ;
V_2 -> V_6 . V_350 = V_394 ;
return V_28 ;
}
static void F_105 ( struct V_1 * V_2 )
{
V_2 -> V_6 . V_274 = F_5 ( V_2 , V_404 ) ;
if ( V_2 -> V_4 . type == V_214 &&
V_2 -> V_6 . V_274 & V_405 ) {
V_2 -> V_6 . V_262 . V_263 = ( V_2 -> V_6 . V_274 &
V_406 ) >>
V_407 ;
}
}
static T_1 F_106 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_257 ;
V_2 -> V_4 . V_9 . V_188 ( V_2 ) ;
F_105 ( V_2 ) ;
if ( V_2 -> V_4 . V_9 . V_10 ( V_2 ) == V_292 ) {
V_6 -> V_43 = V_57 ;
F_4 ( V_2 ) ;
}
V_257 = V_6 -> V_9 . V_408 ( V_2 ) ;
F_82 ( V_2 ) ;
if ( V_6 -> V_226 != V_239 )
V_6 -> V_9 . V_312 = NULL ;
switch ( V_2 -> V_6 . type ) {
case V_60 :
V_6 -> V_9 . V_303 = F_89 ;
V_6 -> V_9 . V_266 = F_22 ;
V_6 -> V_9 . V_271 = F_23 ;
break;
case V_64 :
V_6 -> V_9 . V_303 = F_90 ;
V_6 -> V_9 . V_266 = F_22 ;
V_6 -> V_9 . V_271 = F_23 ;
break;
case V_409 :
V_6 -> V_274 = F_5 ( V_2 , V_404 ) ;
V_6 -> V_9 . V_339 =
F_92 ;
if ( V_2 -> V_4 . type == V_224 &&
! ( F_5 ( V_2 , F_107 ( 0 ) ) &
V_410 ) )
V_6 -> V_9 . V_411 = F_102 ;
V_6 -> V_9 . V_412 = F_88 ;
V_6 -> V_9 . V_312 = F_93 ;
break;
default:
break;
}
return V_257 ;
}
static enum V_413 F_108 ( struct V_1 * V_2 )
{
enum V_413 V_314 ;
switch ( V_2 -> V_52 ) {
case V_310 :
case V_311 :
V_2 -> V_6 . type = V_414 ;
case V_61 :
case V_59 :
case V_62 :
case V_63 :
V_314 = V_296 ;
break;
case V_56 :
case V_53 :
case V_58 :
V_314 = V_292 ;
break;
case V_66 :
case V_67 :
case V_65 :
V_314 = V_11 ;
break;
default:
V_314 = V_415 ;
break;
}
return V_314 ;
}
static T_1 F_109 ( struct V_1 * V_2 )
{
T_1 V_28 ;
T_3 V_24 ;
V_28 = V_2 -> V_6 . V_9 . V_266 ( V_2 ,
V_416 ,
V_417 ,
& V_24 ) ;
if ( V_28 )
return V_28 ;
if ( V_24 & V_418 ) {
V_28 = V_2 -> V_6 . V_9 . V_266 ( V_2 ,
V_419 ,
V_318 ,
& V_24 ) ;
if ( V_28 )
return V_28 ;
V_24 &= ~ V_420 ;
V_28 = V_2 -> V_6 . V_9 . V_271 ( V_2 ,
V_419 ,
V_318 ,
V_24 ) ;
if ( V_28 )
return V_28 ;
}
return V_28 ;
}
static void F_110 ( struct V_1 * V_2 )
{
T_2 V_421 ;
switch ( V_2 -> V_52 ) {
case V_67 :
case V_310 :
case V_311 :
case V_65 :
case V_53 :
V_421 = F_5 ( V_2 , V_422 ) ;
V_421 &= ~ V_423 ;
F_6 ( V_2 , V_422 , V_421 ) ;
break;
default:
break;
}
}
static T_1 F_111 ( struct V_1 * V_2 )
{
T_6 V_424 ;
T_1 V_28 ;
T_2 V_82 = 0 ;
T_2 V_83 ;
bool V_277 = false ;
V_28 = V_2 -> V_4 . V_9 . V_425 ( V_2 ) ;
if ( V_28 )
return V_28 ;
F_112 ( V_2 ) ;
V_28 = V_2 -> V_6 . V_9 . V_426 ( V_2 ) ;
if ( V_2 -> V_6 . type == V_409 ) {
V_28 = F_109 ( V_2 ) ;
if ( V_28 )
return V_28 ;
}
if ( V_2 -> V_6 . V_427 ) {
V_28 = V_2 -> V_4 . V_9 . V_428 ( V_2 ) ;
V_2 -> V_6 . V_427 = false ;
}
if ( ! V_2 -> V_6 . V_429 && V_2 -> V_6 . V_9 . V_312 )
V_2 -> V_6 . V_9 . V_312 ( V_2 ) ;
V_430:
V_82 = V_431 ;
if ( ! V_2 -> V_432 ) {
V_2 -> V_4 . V_9 . V_309 ( V_2 , & V_424 , & V_277 , false ) ;
if ( V_277 )
V_82 = V_433 ;
}
V_82 |= F_5 ( V_2 , V_434 ) ;
F_6 ( V_2 , V_434 , V_82 ) ;
F_7 ( V_2 ) ;
F_16 ( 1000 , 1200 ) ;
for ( V_83 = 0 ; V_83 < 10 ; V_83 ++ ) {
V_82 = F_5 ( V_2 , V_434 ) ;
if ( ! ( V_82 & V_435 ) )
break;
F_35 ( 1 ) ;
}
if ( V_82 & V_435 ) {
V_28 = V_436 ;
F_33 ( V_2 , L_25 ) ;
}
F_17 ( 50 ) ;
if ( V_2 -> V_4 . V_437 & V_438 ) {
V_2 -> V_4 . V_437 &= ~ V_438 ;
goto V_430;
}
V_2 -> V_4 . V_9 . V_439 ( V_2 , V_2 -> V_4 . V_440 ) ;
V_2 -> V_4 . V_441 = 128 ;
V_2 -> V_4 . V_9 . V_442 ( V_2 ) ;
F_110 ( V_2 ) ;
if ( V_2 -> V_52 == V_56 )
F_4 ( V_2 ) ;
return V_28 ;
}
static void F_113 ( struct V_1 * V_2 ,
bool V_443 , int V_444 )
{
int V_445 = V_444 >> 3 ;
int V_446 = V_444 % 8 + V_447 ;
T_2 V_448 ;
V_448 = F_5 ( V_2 , F_114 ( V_445 ) ) ;
if ( V_443 )
V_448 |= F_32 ( V_446 ) ;
else
V_448 &= ~ F_32 ( V_446 ) ;
F_6 ( V_2 , F_114 ( V_445 ) , V_448 ) ;
}
static void F_115 ( struct V_1 * V_2 ,
bool V_443 ,
unsigned int V_449 )
{
T_7 V_450 ;
if ( V_449 > 63 )
return;
V_450 = ( T_7 ) F_5 ( V_2 , V_451 ) ;
V_450 |= ( T_7 ) F_5 ( V_2 , V_452 ) << 32 ;
if ( V_443 )
V_450 |= ( 1ULL << V_449 ) ;
else
V_450 &= ~ ( 1ULL << V_449 ) ;
F_6 ( V_2 , V_451 , ( T_2 ) V_450 ) ;
F_6 ( V_2 , V_452 , ( T_2 ) ( V_450 >> 32 ) ) ;
}
static T_1 V_298 ( struct V_1 * V_2 )
{
T_1 V_28 = 0 ;
T_2 V_453 = 0 ;
if ( V_2 -> V_372 . V_373 && V_2 -> V_372 . V_374 == V_375 ) {
F_12 ( V_2 , L_20 ) ;
return V_356 ;
}
if ( V_2 -> V_372 . V_374 == V_376 )
V_2 -> V_372 . V_374 = V_377 ;
V_28 = V_2 -> V_4 . V_9 . V_211 ( V_2 ,
F_98 ( V_2 -> V_17 . V_18 ) ,
V_201 , & V_453 ) ;
if ( V_28 ) {
F_33 ( V_2 , L_24 ) ;
return V_28 ;
}
switch ( V_2 -> V_372 . V_374 ) {
case V_378 :
V_453 &= ~ ( V_380 |
V_381 ) ;
break;
case V_379 :
V_453 |= V_381 ;
V_453 &= ~ V_380 ;
break;
case V_375 :
case V_377 :
V_453 |= V_380 |
V_381 ;
break;
default:
F_12 ( V_2 , L_21 ) ;
return V_280 ;
}
V_28 = V_2 -> V_4 . V_9 . V_213 ( V_2 ,
F_98 ( V_2 -> V_17 . V_18 ) ,
V_201 , V_453 ) ;
V_28 = F_66 ( V_2 ) ;
return V_28 ;
}
static void F_116 ( struct V_1 * V_2 , T_4 V_454 )
{
T_2 V_15 ;
if ( ! V_2 -> V_17 . V_18 )
return;
V_15 = F_5 ( V_2 , V_16 ) ;
if ( V_454 )
V_15 |= V_20 ;
else
V_15 &= ~ V_20 ;
F_6 ( V_2 , V_16 , V_15 ) ;
F_7 ( V_2 ) ;
}
static T_1 F_117 ( struct V_1 * V_2 , T_2 V_455 )
{
T_1 V_28 ;
V_28 = F_118 ( V_2 , V_455 ) ;
if ( V_28 )
return V_28 ;
if ( V_455 & V_456 )
F_116 ( V_2 , 1 ) ;
return 0 ;
}
static void F_119 ( struct V_1 * V_2 , T_2 V_455 )
{
if ( V_455 & V_456 )
F_116 ( V_2 , 0 ) ;
F_120 ( V_2 , V_455 ) ;
}
static T_1 F_121 ( struct V_1 * V_2 , T_2 V_455 )
{
T_2 V_457 = V_455 & ~ V_458 ;
int V_459 = V_460 ;
T_1 V_28 ;
while ( -- V_459 ) {
V_28 = 0 ;
if ( V_457 )
V_28 = F_118 ( V_2 , V_457 ) ;
if ( V_28 )
return V_28 ;
if ( ! ( V_455 & V_458 ) )
return 0 ;
V_28 = F_37 ( V_2 ) ;
if ( ! V_28 )
return 0 ;
if ( V_457 )
F_120 ( V_2 , V_457 ) ;
if ( V_28 != V_117 )
return V_28 ;
F_17 ( V_461 ) ;
}
return V_28 ;
}
static void F_122 ( struct V_1 * V_2 , T_2 V_455 )
{
T_2 V_457 = V_455 & ~ V_458 ;
if ( V_455 & V_458 )
F_39 ( V_2 ) ;
if ( V_457 )
F_120 ( V_2 , V_457 ) ;
}
static T_1 F_123 ( struct V_1 * V_2 , T_2 V_68 ,
T_2 V_69 , T_3 * V_70 )
{
T_2 V_455 = V_2 -> V_6 . V_43 | V_458 ;
T_1 V_28 ;
if ( V_2 -> V_4 . V_9 . V_44 ( V_2 , V_455 ) )
return V_171 ;
V_28 = V_2 -> V_6 . V_9 . V_462 ( V_2 , V_68 , V_69 , V_70 ) ;
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_455 ) ;
return V_28 ;
}
static T_1 F_124 ( struct V_1 * V_2 , T_2 V_68 ,
T_2 V_69 , T_3 V_70 )
{
T_2 V_455 = V_2 -> V_6 . V_43 | V_458 ;
T_1 V_28 ;
if ( V_2 -> V_4 . V_9 . V_44 ( V_2 , V_455 ) )
return V_171 ;
V_28 = F_125 ( V_2 , V_68 , V_69 , V_70 ) ;
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_455 ) ;
return V_28 ;
}
