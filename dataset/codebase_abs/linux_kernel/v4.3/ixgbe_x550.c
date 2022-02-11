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
static T_1 F_7 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_20 ) {
case V_21 :
V_2 -> V_6 . V_22 = V_23 ;
F_3 ( V_2 ) ;
return F_8 ( V_2 ) ;
case V_24 :
V_2 -> V_6 . type = V_25 ;
break;
case V_26 :
V_2 -> V_6 . type = V_27 ;
break;
case V_28 :
case V_29 :
return F_9 ( V_2 ) ;
default:
break;
}
return 0 ;
}
static T_1 F_10 ( struct V_1 * V_2 , T_2 V_30 ,
T_2 V_31 , T_3 * V_32 )
{
return V_33 ;
}
static T_1 F_11 ( struct V_1 * V_2 , T_2 V_30 ,
T_2 V_31 , T_3 V_32 )
{
return V_33 ;
}
static T_1 F_12 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = & V_2 -> V_35 ;
T_2 V_36 ;
T_3 V_37 ;
if ( V_35 -> type == V_38 ) {
V_35 -> V_39 = 10 ;
V_35 -> type = V_40 ;
V_36 = F_4 ( V_2 , F_13 ( V_2 ) ) ;
V_37 = ( T_3 ) ( ( V_36 & V_41 ) >>
V_42 ) ;
V_35 -> V_43 = 1 << ( V_37 +
V_44 ) ;
F_14 ( V_2 , L_1 ,
V_35 -> type , V_35 -> V_43 ) ;
}
return 0 ;
}
static T_1 F_15 ( struct V_1 * V_2 , T_2 * V_45 )
{
T_2 V_46 , V_47 ;
for ( V_46 = 0 ; V_46 < V_48 ; V_46 ++ ) {
V_47 = F_4 ( V_2 , V_49 ) ;
if ( ! ( V_47 & V_50 ) )
break;
F_16 ( 10 , 20 ) ;
}
if ( V_45 )
* V_45 = V_47 ;
if ( V_46 == V_48 ) {
F_14 ( V_2 , L_2 ) ;
return V_51 ;
}
return 0 ;
}
static T_1 F_17 ( struct V_1 * V_2 , T_2 V_30 ,
T_2 V_31 , T_2 * V_52 )
{
T_2 V_53 = V_54 | V_55 ;
T_2 V_47 , error ;
T_1 V_56 ;
V_56 = V_2 -> V_4 . V_7 . V_57 ( V_2 , V_53 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_15 ( V_2 , NULL ) ;
if ( V_56 )
goto V_58;
V_47 = ( ( V_30 << V_59 ) |
( V_31 << V_60 ) ) ;
F_5 ( V_2 , V_49 , V_47 ) ;
V_56 = F_15 ( V_2 , & V_47 ) ;
if ( ( V_47 & V_61 ) != 0 ) {
error = ( V_47 & V_62 ) >>
V_63 ;
F_14 ( V_2 , L_3 , error ) ;
return V_51 ;
}
if ( ! V_56 )
* V_52 = F_4 ( V_2 , V_64 ) ;
V_58:
V_2 -> V_4 . V_7 . V_65 ( V_2 , V_53 ) ;
return V_56 ;
}
static T_1 F_18 ( struct V_1 * V_2 , T_3 V_66 ,
T_3 * V_52 )
{
T_1 V_67 ;
struct V_68 V_69 ;
V_69 . V_70 . V_71 . V_72 = V_73 ;
V_69 . V_70 . V_71 . V_74 = 0 ;
V_69 . V_70 . V_71 . V_75 = V_76 ;
V_69 . V_70 . V_71 . V_77 = V_78 ;
V_69 . V_79 = F_19 ( V_66 * 2 ) ;
V_69 . V_80 = F_20 ( sizeof( T_3 ) ) ;
V_67 = F_21 ( V_2 , ( T_2 * ) & V_69 ,
sizeof( V_69 ) ,
V_81 , false ) ;
if ( V_67 )
return V_67 ;
* V_52 = ( T_3 ) F_22 ( V_2 , V_82 ,
V_83 ) ;
return 0 ;
}
static T_1 F_23 ( struct V_1 * V_2 ,
T_3 V_66 , T_3 V_84 , T_3 * V_52 )
{
struct V_68 V_69 ;
T_2 V_85 = 0 ;
T_3 V_86 ;
T_1 V_67 ;
T_2 V_46 ;
V_67 = V_2 -> V_4 . V_7 . V_57 ( V_2 , V_87 ) ;
if ( V_67 ) {
F_14 ( V_2 , L_4 ) ;
return V_67 ;
}
while ( V_84 ) {
if ( V_84 > V_88 / 2 )
V_86 = V_88 / 2 ;
else
V_86 = V_84 ;
V_69 . V_70 . V_71 . V_72 = V_73 ;
V_69 . V_70 . V_71 . V_74 = 0 ;
V_69 . V_70 . V_71 . V_75 = V_76 ;
V_69 . V_70 . V_71 . V_77 = V_78 ;
V_69 . V_79 = F_19 ( ( V_66 + V_85 ) * 2 ) ;
V_69 . V_80 = F_20 ( V_86 * 2 ) ;
V_67 = F_21 ( V_2 , ( T_2 * ) & V_69 ,
sizeof( V_69 ) ,
V_81 ,
false ) ;
if ( V_67 ) {
F_14 ( V_2 , L_5 ) ;
goto V_58;
}
for ( V_46 = 0 ; V_46 < V_86 ; V_46 ++ ) {
T_2 V_89 = V_82 + ( V_83 << 2 ) +
2 * V_46 ;
T_2 V_90 = F_4 ( V_2 , V_89 ) ;
V_52 [ V_85 ] = ( T_3 ) ( V_90 & 0xffff ) ;
V_85 ++ ;
V_46 ++ ;
if ( V_46 < V_86 ) {
V_90 >>= 16 ;
V_52 [ V_85 ] = ( T_3 ) ( V_90 & 0xffff ) ;
V_85 ++ ;
}
}
V_84 -= V_86 ;
}
V_58:
V_2 -> V_4 . V_7 . V_65 ( V_2 , V_87 ) ;
return V_67 ;
}
static T_1 F_24 ( struct V_1 * V_2 , T_3 V_91 ,
T_3 V_92 , T_3 * V_93 , T_3 * V_69 ,
T_2 V_94 )
{
T_3 V_95 [ 256 ] ;
T_1 V_67 ;
T_3 V_80 , V_96 , V_46 , V_97 ;
T_3 * V_98 ;
V_96 = sizeof( V_95 ) / sizeof( V_95 [ 0 ] ) ;
if ( ! V_69 ) {
V_67 = F_23 ( V_2 , V_91 , V_96 , V_95 ) ;
if ( V_67 ) {
F_14 ( V_2 , L_6 ) ;
return V_67 ;
}
V_98 = V_95 ;
} else {
if ( V_94 < V_91 )
return V_99 ;
V_98 = & V_69 [ V_91 ] ;
}
if ( V_92 ) {
V_97 = 0 ;
V_80 = V_92 ;
} else {
V_97 = 1 ;
V_80 = V_98 [ 0 ] ;
if ( V_80 == 0xFFFF || V_80 == 0 ||
( V_91 + V_80 ) >= V_2 -> V_35 . V_43 )
return 0 ;
}
if ( V_69 && ( ( T_2 ) V_97 + ( T_2 ) V_80 > V_94 ) )
return V_99 ;
for ( V_46 = V_97 ; V_80 ; V_46 ++ , V_80 -- ) {
if ( V_46 == V_96 && ! V_69 ) {
V_91 += V_96 ;
V_46 = 0 ;
if ( V_80 < V_96 )
V_96 = V_80 ;
V_67 = F_23 ( V_2 , V_91 ,
V_96 , V_95 ) ;
if ( V_67 ) {
F_14 ( V_2 , L_6 ) ;
return V_67 ;
}
}
* V_93 += V_98 [ V_46 ] ;
}
return 0 ;
}
static T_1 F_25 ( struct V_1 * V_2 , T_3 * V_69 ,
T_2 V_94 )
{
T_3 V_100 [ V_101 + 1 ] ;
T_3 * V_98 ;
T_1 V_67 ;
T_3 V_77 = 0 ;
T_3 V_102 , V_46 , V_92 ;
V_2 -> V_35 . V_7 . V_103 ( V_2 ) ;
if ( ! V_69 ) {
V_67 = F_23 ( V_2 , 0 ,
V_101 + 1 ,
V_100 ) ;
if ( V_67 ) {
F_14 ( V_2 , L_6 ) ;
return V_67 ;
}
V_98 = V_100 ;
} else {
if ( V_94 < V_101 )
return V_99 ;
V_98 = V_69 ;
}
for ( V_46 = 0 ; V_46 <= V_101 ; V_46 ++ )
if ( V_46 != V_104 )
V_77 += V_98 [ V_46 ] ;
for ( V_46 = V_105 ; V_46 < V_106 ; V_46 ++ ) {
if ( V_46 == V_107 || V_46 == V_108 )
continue;
V_102 = V_98 [ V_46 ] ;
if ( V_102 == 0xFFFF || V_102 == 0 ||
V_102 >= V_2 -> V_35 . V_43 )
continue;
switch ( V_46 ) {
case V_109 :
V_92 = V_110 ;
break;
case V_111 :
case V_112 :
V_92 = V_113 ;
break;
default:
V_92 = 0 ;
break;
}
V_67 = F_24 ( V_2 , V_102 , V_92 , & V_77 ,
V_69 , V_94 ) ;
if ( V_67 )
return V_67 ;
}
V_77 = ( T_3 ) V_114 - V_77 ;
return ( T_1 ) V_77 ;
}
static T_1 F_26 ( struct V_1 * V_2 )
{
return F_25 ( V_2 , NULL , 0 ) ;
}
static T_1 F_27 ( struct V_1 * V_2 , T_3 V_66 , T_3 * V_52 )
{
T_1 V_67 = 0 ;
if ( V_2 -> V_4 . V_7 . V_57 ( V_2 , V_87 ) == 0 ) {
V_67 = F_18 ( V_2 , V_66 , V_52 ) ;
V_2 -> V_4 . V_7 . V_65 ( V_2 , V_87 ) ;
} else {
V_67 = V_115 ;
}
return V_67 ;
}
static T_1 F_28 ( struct V_1 * V_2 ,
T_3 * V_116 )
{
T_1 V_67 ;
T_3 V_77 ;
T_3 V_117 = 0 ;
V_67 = V_2 -> V_35 . V_7 . V_118 ( V_2 , 0 , & V_77 ) ;
if ( V_67 ) {
F_14 ( V_2 , L_7 ) ;
return V_67 ;
}
V_67 = V_2 -> V_35 . V_7 . V_119 ( V_2 ) ;
if ( V_67 < 0 )
return V_67 ;
V_77 = ( T_3 ) ( V_67 & 0xffff ) ;
V_67 = F_27 ( V_2 , V_104 ,
& V_117 ) ;
if ( V_67 )
return V_67 ;
if ( V_117 != V_77 ) {
V_67 = V_120 ;
F_14 ( V_2 , L_8 ) ;
}
if ( V_116 )
* V_116 = V_77 ;
return V_67 ;
}
static T_1 F_29 ( struct V_1 * V_2 , T_3 V_66 ,
T_3 V_52 )
{
T_1 V_67 ;
struct V_121 V_69 ;
V_69 . V_70 . V_71 . V_72 = V_122 ;
V_69 . V_70 . V_71 . V_74 = 0 ;
V_69 . V_70 . V_71 . V_75 = V_123 ;
V_69 . V_70 . V_71 . V_77 = V_78 ;
V_69 . V_80 = F_20 ( sizeof( T_3 ) ) ;
V_69 . V_52 = V_52 ;
V_69 . V_79 = F_19 ( V_66 * 2 ) ;
V_67 = F_21 ( V_2 , ( T_2 * ) & V_69 ,
sizeof( V_69 ) ,
V_81 , false ) ;
return V_67 ;
}
static T_1 F_30 ( struct V_1 * V_2 , T_3 V_66 , T_3 V_52 )
{
T_1 V_67 = 0 ;
if ( V_2 -> V_4 . V_7 . V_57 ( V_2 , V_87 ) == 0 ) {
V_67 = F_29 ( V_2 , V_66 , V_52 ) ;
V_2 -> V_4 . V_7 . V_65 ( V_2 , V_87 ) ;
} else {
F_14 ( V_2 , L_9 ) ;
V_67 = V_115 ;
}
return V_67 ;
}
static T_1 F_31 ( struct V_1 * V_2 )
{
T_1 V_67 = 0 ;
union V_124 V_69 ;
V_69 . V_71 . V_72 = V_125 ;
V_69 . V_71 . V_74 = 0 ;
V_69 . V_71 . V_75 = V_126 ;
V_69 . V_71 . V_77 = V_78 ;
V_67 = F_21 ( V_2 , ( T_2 * ) & V_69 ,
sizeof( V_69 ) ,
V_81 , false ) ;
return V_67 ;
}
static T_1 F_32 ( struct V_1 * V_2 )
{
V_2 -> V_13 . type = V_127 ;
V_2 -> V_13 . V_128 = V_129 ;
V_2 -> V_13 . V_130 = V_131 ;
V_2 -> V_4 . V_7 . V_132 ( V_2 ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
T_2 V_133 , V_134 ;
T_1 V_67 ;
struct V_135 V_136 ;
V_133 = F_4 ( V_2 , V_137 ) ;
if ( V_133 & V_138 ) {
V_134 = F_4 ( V_2 , V_139 ) ;
if ( V_134 & V_140 ) {
V_134 &= ~ V_140 ;
F_5 ( V_2 , V_139 , V_134 ) ;
V_2 -> V_4 . V_141 = true ;
} else {
V_2 -> V_4 . V_141 = false ;
}
V_136 . V_70 . V_72 = V_142 ;
V_136 . V_70 . V_143 = V_144 ;
V_136 . V_70 . V_77 = V_78 ;
V_136 . V_145 = ( V_146 ) V_2 -> V_13 . V_14 ;
V_67 = F_21 ( V_2 , ( T_2 * ) & V_136 ,
sizeof( struct V_135 ) ,
V_81 , true ) ;
if ( V_67 ) {
V_133 = F_4 ( V_2 , V_137 ) ;
if ( V_133 & V_138 ) {
V_133 &= ~ V_138 ;
F_5 ( V_2 , V_137 , V_133 ) ;
}
}
}
}
static T_1 F_34 ( struct V_1 * V_2 )
{
T_1 V_67 ;
T_3 V_77 = 0 ;
V_67 = F_27 ( V_2 , 0 , & V_77 ) ;
if ( V_67 ) {
F_14 ( V_2 , L_7 ) ;
return V_67 ;
}
V_67 = F_26 ( V_2 ) ;
if ( V_67 < 0 )
return V_67 ;
V_77 = ( T_3 ) ( V_67 & 0xffff ) ;
V_67 = F_30 ( V_2 , V_104 ,
V_77 ) ;
if ( V_67 )
return V_67 ;
V_67 = F_31 ( V_2 ) ;
return V_67 ;
}
static T_1 F_35 ( struct V_1 * V_2 ,
T_3 V_66 , T_3 V_84 ,
T_3 * V_52 )
{
T_1 V_67 = 0 ;
T_2 V_46 = 0 ;
V_67 = V_2 -> V_4 . V_7 . V_57 ( V_2 , V_87 ) ;
if ( V_67 ) {
F_14 ( V_2 , L_10 ) ;
return V_67 ;
}
for ( V_46 = 0 ; V_46 < V_84 ; V_46 ++ ) {
V_67 = F_29 ( V_2 , V_66 + V_46 ,
V_52 [ V_46 ] ) ;
if ( V_67 ) {
F_14 ( V_2 , L_11 ) ;
break;
}
}
V_2 -> V_4 . V_7 . V_65 ( V_2 , V_87 ) ;
return V_67 ;
}
static T_1 F_36 ( struct V_1 * V_2 , T_2 V_30 ,
T_2 V_31 , T_2 V_52 )
{
T_2 V_53 = V_54 | V_55 ;
T_2 V_47 , error ;
T_1 V_56 ;
V_56 = V_2 -> V_4 . V_7 . V_57 ( V_2 , V_53 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_15 ( V_2 , NULL ) ;
if ( V_56 )
goto V_58;
V_47 = ( ( V_30 << V_59 ) |
( V_31 << V_60 ) ) ;
F_5 ( V_2 , V_49 , V_47 ) ;
F_5 ( V_2 , V_64 , V_52 ) ;
V_56 = F_15 ( V_2 , & V_47 ) ;
if ( ( V_47 & V_61 ) != 0 ) {
error = ( V_47 & V_62 ) >>
V_63 ;
F_14 ( V_2 , L_12 , error ) ;
return V_51 ;
}
V_58:
V_2 -> V_4 . V_7 . V_65 ( V_2 , V_53 ) ;
return V_56 ;
}
static T_1 F_37 ( struct V_1 * V_2 , T_4 * V_130 )
{
T_1 V_67 ;
T_2 V_147 ;
V_67 = F_17 ( V_2 ,
F_38 ( V_2 -> V_13 . V_14 ) ,
V_148 , & V_147 ) ;
if ( V_67 )
return V_67 ;
V_147 &= ~ V_149 ;
V_147 &= ~ V_150 ;
switch ( * V_130 ) {
case V_151 :
V_147 |= V_152 ;
break;
case V_153 :
V_147 |= V_154 ;
break;
default:
return V_155 ;
}
V_67 = F_36 ( V_2 ,
F_38 ( V_2 -> V_13 . V_14 ) ,
V_148 , V_147 ) ;
if ( V_67 )
return V_67 ;
V_67 = F_17 ( V_2 ,
F_39 ( V_2 -> V_13 . V_14 ) ,
V_148 , & V_147 ) ;
if ( V_67 )
return V_67 ;
V_147 |= V_156 ;
V_67 = F_36 ( V_2 ,
F_39 ( V_2 -> V_13 . V_14 ) ,
V_148 , V_147 ) ;
if ( V_67 )
return V_67 ;
V_67 = F_17 ( V_2 ,
F_40 ( V_2 -> V_13 . V_14 ) ,
V_148 , & V_147 ) ;
if ( V_67 )
return V_67 ;
V_147 &= ~ V_157 ;
V_147 &= ~ V_158 ;
V_147 &= ~ V_159 ;
V_67 = F_36 ( V_2 ,
F_40 ( V_2 -> V_13 . V_14 ) ,
V_148 , V_147 ) ;
if ( V_67 )
return V_67 ;
V_67 = F_17 ( V_2 ,
F_41 ( V_2 -> V_13 . V_14 ) ,
V_148 , & V_147 ) ;
if ( V_67 )
return V_67 ;
V_147 &= ~ V_157 ;
V_147 &= ~ V_158 ;
V_147 &= ~ V_159 ;
V_67 = F_36 ( V_2 ,
F_41 ( V_2 -> V_13 . V_14 ) ,
V_148 , V_147 ) ;
if ( V_67 )
return V_67 ;
V_67 = F_17 ( V_2 ,
F_42 ( V_2 -> V_13 . V_14 ) ,
V_148 , & V_147 ) ;
if ( V_67 )
return V_67 ;
V_147 |= V_160 ;
V_147 |= V_161 ;
V_147 |= V_162 ;
V_147 |= V_163 ;
V_67 = F_36 ( V_2 ,
F_42 ( V_2 -> V_13 . V_14 ) ,
V_148 , V_147 ) ;
if ( V_67 )
return V_67 ;
V_67 = F_17 ( V_2 ,
F_38 ( V_2 -> V_13 . V_14 ) ,
V_148 , & V_147 ) ;
if ( V_67 )
return V_67 ;
V_147 |= V_164 ;
V_67 = F_36 ( V_2 ,
F_38 ( V_2 -> V_13 . V_14 ) ,
V_148 , V_147 ) ;
return V_67 ;
}
static T_1 F_43 ( struct V_1 * V_2 ,
T_4 V_130 ,
bool V_165 )
{
T_1 V_67 ;
T_4 V_166 ;
if ( V_130 & V_151 )
V_166 = V_151 ;
else
V_166 = V_153 ;
if ( ! ( V_2 -> V_6 . V_167 & V_168 ) ) {
V_67 = F_37 ( V_2 , & V_166 ) ;
if ( V_67 )
return V_67 ;
}
return V_2 -> V_6 . V_7 . V_169 ( V_2 , V_130 , V_165 ) ;
}
static T_1 F_44 ( struct V_1 * V_2 ,
T_4 * V_130 ,
bool * V_170 ,
bool V_171 )
{
T_2 V_67 ;
T_3 V_172 ;
if ( V_2 -> V_4 . V_7 . V_8 ( V_2 ) != V_9 )
return V_173 ;
V_67 = F_45 ( V_2 , V_130 , V_170 ,
V_171 ) ;
if ( V_67 || ! ( * V_170 ) )
return V_67 ;
V_67 = V_2 -> V_6 . V_7 . V_174 ( V_2 , V_175 ,
V_176 ,
& V_172 ) ;
if ( V_67 )
return V_67 ;
if ( ! ( V_172 & V_177 ) )
* V_170 = false ;
return 0 ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
switch ( V_4 -> V_7 . V_8 ( V_2 ) ) {
case V_178 :
V_4 -> V_7 . V_179 = NULL ;
V_4 -> V_7 . V_180 = NULL ;
V_4 -> V_7 . V_181 = NULL ;
break;
case V_9 :
V_4 -> V_7 . V_182 = F_43 ;
V_4 -> V_7 . V_183 = F_44 ;
break;
default:
break;
}
}
static T_1 F_47 ( struct V_1 * V_2 )
{
bool V_184 ;
T_3 V_185 , V_186 ;
T_1 V_187 ;
switch ( V_2 -> V_6 . V_188 ) {
case V_189 :
return 0 ;
case V_190 :
return V_191 ;
case V_192 :
case V_193 :
V_184 = true ;
break;
case V_194 :
case V_195 :
case V_196 :
case V_197 :
case V_198 :
case V_199 :
V_184 = false ;
break;
default:
return V_200 ;
}
F_46 ( V_2 ) ;
V_2 -> V_6 . V_7 . V_201 = NULL ;
V_185 = V_202 + ( V_2 -> V_13 . V_14 << 12 ) ;
if ( V_184 )
V_186 = ( V_203 << 1 ) | 0x1 ;
else
V_186 = ( V_204 << 1 ) | 0x1 ;
V_187 = V_2 -> V_6 . V_7 . V_205 ( V_2 , V_206 , V_185 ,
V_186 ) ;
if ( V_187 )
V_187 = V_2 -> V_6 . V_7 . V_205 ( V_2 , 0x80 , V_185 ,
V_186 ) ;
return V_187 ;
}
static T_1 F_48 ( struct V_1 * V_2 ,
T_4 * V_130 ,
bool * V_207 )
{
if ( V_2 -> V_6 . V_208 == V_178 ) {
* V_207 = false ;
if ( V_2 -> V_6 . V_188 == V_198 ||
V_2 -> V_6 . V_188 == V_199 ) {
* V_130 = V_153 ;
return 0 ;
}
if ( V_2 -> V_6 . V_209 )
* V_130 = V_151 |
V_153 ;
else
* V_130 = V_151 ;
} else {
* V_130 = V_151 |
V_153 ;
* V_207 = true ;
}
return 0 ;
}
static T_1 F_49 ( struct V_1 * V_2 , bool * V_210 )
{
T_2 V_67 ;
T_3 V_89 ;
* V_210 = false ;
V_67 = V_2 -> V_6 . V_7 . V_174 ( V_2 , V_211 ,
V_212 ,
& V_89 ) ;
if ( V_67 || ! ( V_89 & V_213 ) )
return V_67 ;
V_67 = V_2 -> V_6 . V_7 . V_174 ( V_2 , V_214 ,
V_212 ,
& V_89 ) ;
if ( V_67 || ! ( V_89 & ( V_215 |
V_216 ) ) )
return V_67 ;
V_67 = V_2 -> V_6 . V_7 . V_174 ( V_2 , V_217 ,
V_212 ,
& V_89 ) ;
if ( V_67 )
return V_67 ;
if ( V_89 & V_218 ) {
F_50 ( V_2 , false ) ;
return V_219 ;
}
V_67 = V_2 -> V_6 . V_7 . V_174 ( V_2 , V_211 ,
V_176 , & V_89 ) ;
if ( V_67 || ! ( V_89 & V_220 ) )
return V_67 ;
V_67 = V_2 -> V_6 . V_7 . V_174 ( V_2 , V_221 ,
V_176 , & V_89 ) ;
if ( V_67 )
return V_67 ;
if ( V_89 & V_222 )
* V_210 = true ;
return 0 ;
}
static T_1 F_51 ( struct V_1 * V_2 )
{
T_2 V_67 ;
T_3 V_89 ;
bool V_210 ;
V_67 = F_49 ( V_2 , & V_210 ) ;
V_67 = V_2 -> V_6 . V_7 . V_174 ( V_2 , V_223 ,
V_176 , & V_89 ) ;
if ( V_67 )
return V_67 ;
V_89 |= V_224 ;
V_67 = V_2 -> V_6 . V_7 . V_225 ( V_2 , V_223 ,
V_176 , V_89 ) ;
if ( V_67 )
return V_67 ;
V_67 = V_2 -> V_6 . V_7 . V_174 ( V_2 , V_226 ,
V_212 ,
& V_89 ) ;
if ( V_67 )
return V_67 ;
V_89 |= V_227 ;
V_67 = V_2 -> V_6 . V_7 . V_225 ( V_2 , V_226 ,
V_212 ,
V_89 ) ;
if ( V_67 )
return V_67 ;
V_67 = V_2 -> V_6 . V_7 . V_174 ( V_2 , V_228 ,
V_212 ,
& V_89 ) ;
if ( V_67 )
return V_67 ;
V_89 |= ( V_215 |
V_216 ) ;
V_67 = V_2 -> V_6 . V_7 . V_225 ( V_2 , V_228 ,
V_212 ,
V_89 ) ;
if ( V_67 )
return V_67 ;
V_67 = V_2 -> V_6 . V_7 . V_174 ( V_2 , V_229 ,
V_212 ,
& V_89 ) ;
if ( V_67 )
return V_67 ;
V_89 |= V_213 ;
V_67 = V_2 -> V_6 . V_7 . V_225 ( V_2 , V_229 ,
V_212 ,
V_89 ) ;
return V_67 ;
}
static T_1 F_52 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
bool V_210 ;
T_2 V_67 ;
V_67 = F_49 ( V_2 , & V_210 ) ;
if ( V_67 )
return V_67 ;
if ( V_210 )
return V_6 -> V_7 . V_230 ( V_2 ) ;
return 0 ;
}
static T_1 F_53 ( struct V_1 * V_2 ,
T_4 V_130 )
{
T_1 V_67 ;
T_2 V_147 ;
V_67 = F_17 ( V_2 ,
F_38 ( V_2 -> V_13 . V_14 ) ,
V_148 , & V_147 ) ;
if ( V_67 )
return V_67 ;
V_147 |= V_149 ;
V_147 &= ~ ( V_231 |
V_232 ) ;
V_147 &= ~ ( V_233 |
V_234 ) ;
if ( V_130 & V_151 )
V_147 |= V_233 ;
if ( V_130 & V_153 )
V_147 |= V_234 ;
V_147 |= V_164 ;
V_67 = F_36 ( V_2 ,
F_38 ( V_2 -> V_13 . V_14 ) ,
V_148 , V_147 ) ;
return V_67 ;
}
static T_1 F_54 ( struct V_1 * V_2 )
{
T_1 V_67 ;
T_2 V_147 ;
V_67 = F_17 ( V_2 , V_235 ,
V_236 +
V_2 -> V_13 . V_14 , & V_147 ) ;
if ( V_67 )
return V_67 ;
V_147 &= ~ ( V_237 |
V_238 ) ;
V_147 |= V_239 ;
if ( V_2 -> V_6 . V_240 & V_151 )
V_147 |= V_237 ;
if ( V_2 -> V_6 . V_240 & V_153 )
V_147 |= V_238 ;
V_147 |= V_241 ;
V_67 = F_36 ( V_2 , V_235 ,
V_236 +
V_2 -> V_13 . V_14 , V_147 ) ;
return V_67 ;
}
static T_1 F_55 ( struct V_1 * V_2 )
{
return F_53 ( V_2 , V_2 -> V_6 . V_240 ) ;
}
static T_1 F_56 ( struct V_1 * V_2 , bool * V_170 )
{
T_2 V_56 ;
T_3 V_172 ;
* V_170 = false ;
V_56 = V_2 -> V_6 . V_7 . V_174 ( V_2 , V_175 ,
V_176 ,
& V_172 ) ;
if ( V_56 )
return V_56 ;
V_56 = V_2 -> V_6 . V_7 . V_174 ( V_2 , V_175 ,
V_176 ,
& V_172 ) ;
if ( V_56 )
return V_56 ;
* V_170 = ! ! ( V_172 & V_177 ) ;
return 0 ;
}
static T_1 F_57 ( struct V_1 * V_2 )
{
T_4 V_166 ;
bool V_170 ;
T_2 V_67 ;
T_3 V_130 ;
if ( V_2 -> V_4 . V_7 . V_8 ( V_2 ) != V_9 )
return V_173 ;
V_67 = F_56 ( V_2 , & V_170 ) ;
if ( V_67 )
return V_67 ;
if ( ! V_170 )
return 0 ;
V_67 = V_2 -> V_6 . V_7 . V_174 ( V_2 , V_242 ,
V_176 ,
& V_130 ) ;
if ( V_67 )
return V_67 ;
V_67 = F_56 ( V_2 , & V_170 ) ;
if ( V_67 )
return V_67 ;
if ( ! V_170 )
return 0 ;
V_130 &= V_243 ;
switch ( V_130 ) {
case V_244 :
V_166 = V_151 ;
break;
case V_245 :
V_166 = V_153 ;
break;
default:
return V_246 ;
}
return F_37 ( V_2 , & V_166 ) ;
}
static T_1 F_58 ( struct V_1 * V_2 )
{
T_1 V_67 ;
V_67 = F_59 ( V_2 ) ;
if ( V_67 )
return V_67 ;
return F_51 ( V_2 ) ;
}
static T_1 F_60 ( struct V_1 * V_2 ,
T_4 * V_247 )
{
T_3 V_248 ;
T_1 V_67 ;
T_3 V_249 = V_2 -> V_35 . V_250 ;
* V_247 = V_251 ;
V_67 = V_2 -> V_6 . V_7 . V_174 ( V_2 , V_252 ,
V_176 ,
& V_248 ) ;
if ( V_67 )
return V_67 ;
if ( V_248 & V_253 ) {
* V_247 = V_153 ;
return V_67 ;
}
if ( ( V_2 -> V_13 . V_14 && ( V_249 & V_254 ) ) ||
( V_249 & V_255 ) )
return V_67 ;
* V_247 = V_151 ;
return V_67 ;
}
static T_1 F_61 ( struct V_1 * V_2 )
{
T_3 V_256 , V_257 , V_130 ;
T_1 V_67 ;
T_4 V_247 ;
T_2 V_258 ;
bool V_170 ;
if ( V_259 & F_4 ( V_2 , F_62 ( 0 ) ) )
return 0 ;
if ( F_63 ( V_2 ) )
return 0 ;
V_67 = F_56 ( V_2 , & V_170 ) ;
if ( V_67 )
return V_67 ;
V_67 = V_2 -> V_35 . V_7 . V_118 ( V_2 , V_260 ,
& V_2 -> V_35 . V_250 ) ;
if ( V_67 )
return V_67 ;
if ( ! V_170 || ! ( V_2 -> V_35 . V_250 & V_261 ) ||
! ( V_2 -> V_262 || F_64 ( V_2 ) ) )
return F_50 ( V_2 , false ) ;
V_67 = F_60 ( V_2 , & V_247 ) ;
if ( V_67 )
return V_67 ;
if ( V_247 == V_251 )
return F_50 ( V_2 , false ) ;
V_67 = V_2 -> V_6 . V_7 . V_174 ( V_2 , V_242 ,
V_176 ,
& V_130 ) ;
if ( V_67 )
return V_67 ;
V_67 = F_56 ( V_2 , & V_170 ) ;
if ( V_67 )
return F_50 ( V_2 , false ) ;
V_130 &= V_263 ;
if ( ( ( V_130 == V_264 ) &&
( V_247 == V_153 ) ) ||
( ( V_130 == V_265 ) &&
( V_247 == V_151 ) ) )
return V_67 ;
V_67 = V_2 -> V_6 . V_7 . V_174 ( V_2 , V_266 ,
V_176 ,
& V_257 ) ;
if ( V_67 )
return V_67 ;
V_67 = V_2 -> V_6 . V_7 . V_174 ( V_2 , V_267 ,
V_176 ,
& V_256 ) ;
if ( V_67 )
return V_67 ;
V_67 = V_2 -> V_6 . V_7 . V_174 ( V_2 ,
V_268 ,
V_176 ,
& V_257 ) ;
if ( V_67 )
return V_67 ;
V_258 = V_2 -> V_6 . V_240 ;
V_67 = V_2 -> V_4 . V_7 . V_182 ( V_2 , V_247 , false ) ;
V_2 -> V_6 . V_240 = V_258 ;
return V_67 ;
}
static T_1 F_65 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_4 V_130 ;
T_1 V_187 ;
V_2 -> V_4 . V_7 . V_132 ( V_2 ) ;
if ( V_2 -> V_4 . V_7 . V_8 ( V_2 ) == V_178 ) {
V_6 -> V_22 = V_23 ;
F_3 ( V_2 ) ;
V_6 -> V_167 = F_4 ( V_2 , V_269 ) ;
if ( V_6 -> V_167 & V_168 ) {
V_130 = V_151 |
V_153 ;
V_187 = F_53 ( V_2 , V_130 ) ;
}
}
V_187 = V_6 -> V_7 . V_270 ( V_2 ) ;
F_46 ( V_2 ) ;
if ( V_6 -> V_188 != V_189 )
V_6 -> V_7 . V_201 = NULL ;
switch ( V_2 -> V_6 . type ) {
case V_25 :
V_6 -> V_7 . V_182 = F_54 ;
V_6 -> V_7 . V_174 = F_10 ;
V_6 -> V_7 . V_225 = F_11 ;
break;
case V_27 :
V_6 -> V_7 . V_182 = F_55 ;
V_6 -> V_7 . V_174 = F_10 ;
V_6 -> V_7 . V_225 = F_11 ;
break;
case V_271 :
V_6 -> V_167 = F_4 ( V_2 , V_269 ) ;
if ( ! ( V_6 -> V_167 & V_168 ) ) {
V_6 -> V_7 . V_230 =
F_57 ;
} else {
V_130 = V_151 |
V_153 ;
V_187 = F_53 ( V_2 , V_130 ) ;
}
if ( ! ( V_259 & F_4 ( V_2 ,
F_62 ( 0 ) ) ) )
V_6 -> V_7 . V_272 = F_61 ;
V_6 -> V_7 . V_273 = F_52 ;
V_6 -> V_7 . V_201 = F_58 ;
break;
default:
break;
}
return V_187 ;
}
static enum V_274 F_66 ( struct V_1 * V_2 )
{
enum V_274 V_208 ;
switch ( V_2 -> V_20 ) {
case V_26 :
case V_24 :
V_208 = V_275 ;
break;
case V_21 :
V_208 = V_178 ;
break;
case V_28 :
case V_29 :
V_208 = V_9 ;
break;
default:
V_208 = V_276 ;
break;
}
return V_208 ;
}
static T_1 F_67 ( struct V_1 * V_2 )
{
T_1 V_67 ;
T_3 V_89 ;
V_67 = V_2 -> V_6 . V_7 . V_174 ( V_2 ,
V_277 ,
V_278 ,
& V_89 ) ;
if ( V_67 )
return V_67 ;
if ( V_89 & V_279 ) {
V_67 = V_2 -> V_6 . V_7 . V_174 ( V_2 ,
V_280 ,
V_212 ,
& V_89 ) ;
if ( V_67 )
return V_67 ;
V_89 &= ~ V_281 ;
V_67 = V_2 -> V_6 . V_7 . V_225 ( V_2 ,
V_280 ,
V_212 ,
V_89 ) ;
if ( V_67 )
return V_67 ;
}
return V_67 ;
}
static T_1 F_68 ( struct V_1 * V_2 )
{
T_4 V_282 ;
T_1 V_67 ;
T_2 V_45 = 0 ;
T_2 V_46 ;
T_2 V_283 ;
bool V_170 = false ;
V_67 = V_2 -> V_4 . V_7 . V_284 ( V_2 ) ;
if ( V_67 )
return V_67 ;
F_69 ( V_2 ) ;
V_67 = V_2 -> V_6 . V_7 . V_285 ( V_2 ) ;
if ( V_2 -> V_6 . type == V_271 ) {
V_67 = F_67 ( V_2 ) ;
if ( V_67 )
return V_67 ;
}
if ( V_2 -> V_6 . V_286 ) {
V_67 = V_2 -> V_4 . V_7 . V_287 ( V_2 ) ;
V_2 -> V_6 . V_286 = false ;
}
if ( ! V_2 -> V_6 . V_288 && V_2 -> V_6 . V_7 . V_201 )
V_2 -> V_6 . V_7 . V_201 ( V_2 ) ;
V_289:
V_45 = V_290 ;
if ( ! V_2 -> V_291 ) {
V_2 -> V_4 . V_7 . V_183 ( V_2 , & V_282 , & V_170 , false ) ;
if ( V_170 )
V_45 = V_292 ;
}
V_45 |= F_4 ( V_2 , V_293 ) ;
F_5 ( V_2 , V_293 , V_45 ) ;
F_6 ( V_2 ) ;
for ( V_46 = 0 ; V_46 < 10 ; V_46 ++ ) {
F_70 ( 1 ) ;
V_45 = F_4 ( V_2 , V_293 ) ;
if ( ! ( V_45 & V_294 ) )
break;
}
if ( V_45 & V_294 ) {
V_67 = V_295 ;
F_14 ( V_2 , L_13 ) ;
}
F_71 ( 50 ) ;
if ( V_2 -> V_4 . V_296 & V_297 ) {
V_2 -> V_4 . V_296 &= ~ V_297 ;
goto V_289;
}
V_2 -> V_4 . V_7 . V_298 ( V_2 , V_2 -> V_4 . V_299 ) ;
V_2 -> V_4 . V_300 = 128 ;
V_2 -> V_4 . V_7 . V_301 ( V_2 ) ;
if ( V_2 -> V_20 == V_29 ) {
V_283 = F_4 ( V_2 , V_302 ) ;
V_283 &= ~ V_303 ;
F_5 ( V_2 , V_302 , V_283 ) ;
}
if ( V_2 -> V_20 == V_21 )
F_3 ( V_2 ) ;
return V_67 ;
}
static void F_72 ( struct V_1 * V_2 ,
bool V_304 , int V_305 )
{
int V_306 = V_305 >> 3 ;
int V_307 = V_305 % 8 + V_308 ;
T_2 V_309 ;
V_309 = F_4 ( V_2 , F_73 ( V_306 ) ) ;
if ( V_304 )
V_309 |= ( 1 << V_307 ) ;
else
V_309 &= ~ ( 1 << V_307 ) ;
F_5 ( V_2 , F_73 ( V_306 ) , V_309 ) ;
}
static void F_74 ( struct V_1 * V_2 ,
bool V_304 ,
unsigned int V_310 )
{
T_5 V_311 ;
if ( V_310 > 63 )
return;
V_311 = ( T_5 ) F_4 ( V_2 , V_312 ) ;
V_311 |= ( T_5 ) F_4 ( V_2 , V_313 ) << 32 ;
if ( V_304 )
V_311 |= ( 1ULL << V_310 ) ;
else
V_311 &= ~ ( 1ULL << V_310 ) ;
F_5 ( V_2 , V_312 , ( T_2 ) V_311 ) ;
F_5 ( V_2 , V_313 , ( T_2 ) ( V_311 >> 32 ) ) ;
}
