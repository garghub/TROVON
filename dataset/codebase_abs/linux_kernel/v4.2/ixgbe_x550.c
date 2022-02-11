static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 , V_4 ) ;
if ( V_2 -> V_5 . V_6 ) {
V_3 &= ~ ( V_7 | V_8 ) ;
V_3 |= V_9 ;
}
V_3 &= ~ ( V_10 | V_11 ) ;
F_3 ( V_2 , V_4 , V_3 ) ;
F_4 ( V_2 ) ;
}
static T_2 F_5 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_12 ) {
case V_13 :
V_2 -> V_14 . V_15 = V_16 ;
F_1 ( V_2 ) ;
return F_6 ( V_2 ) ;
case V_17 :
V_2 -> V_14 . type = V_18 ;
break;
case V_19 :
V_2 -> V_14 . type = V_20 ;
break;
case V_21 :
case V_22 :
return F_7 ( V_2 ) ;
default:
break;
}
return 0 ;
}
static T_2 F_8 ( struct V_1 * V_2 , T_1 V_23 ,
T_1 V_24 , T_3 * V_25 )
{
return V_26 ;
}
static T_2 F_9 ( struct V_1 * V_2 , T_1 V_23 ,
T_1 V_24 , T_3 V_25 )
{
return V_26 ;
}
static T_2 F_10 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = & V_2 -> V_28 ;
T_1 V_29 ;
T_3 V_30 ;
if ( V_28 -> type == V_31 ) {
V_28 -> V_32 = 10 ;
V_28 -> type = V_33 ;
V_29 = F_2 ( V_2 , F_11 ( V_2 ) ) ;
V_30 = ( T_3 ) ( ( V_29 & V_34 ) >>
V_35 ) ;
V_28 -> V_36 = 1 << ( V_30 +
V_37 ) ;
F_12 ( V_2 , L_1 ,
V_28 -> type , V_28 -> V_36 ) ;
}
return 0 ;
}
static T_2 F_13 ( struct V_1 * V_2 , T_1 * V_38 )
{
T_1 V_39 , V_40 ;
for ( V_39 = 0 ; V_39 < V_41 ; V_39 ++ ) {
V_40 = F_2 ( V_2 , V_42 ) ;
if ( ! ( V_40 & V_43 ) )
break;
F_14 ( 10 , 20 ) ;
}
if ( V_38 )
* V_38 = V_40 ;
if ( V_39 == V_41 ) {
F_12 ( V_2 , L_2 ) ;
return V_44 ;
}
return 0 ;
}
static T_2 F_15 ( struct V_1 * V_2 , T_1 V_23 ,
T_1 V_24 , T_1 * V_45 )
{
T_1 V_46 = V_47 | V_48 ;
T_1 V_40 , error ;
T_2 V_49 ;
V_49 = V_2 -> V_50 . V_51 . V_52 ( V_2 , V_46 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_13 ( V_2 , NULL ) ;
if ( V_49 )
goto V_53;
V_40 = ( ( V_23 << V_54 ) |
( V_24 << V_55 ) ) ;
F_3 ( V_2 , V_42 , V_40 ) ;
V_49 = F_13 ( V_2 , & V_40 ) ;
if ( ( V_40 & V_56 ) != 0 ) {
error = ( V_40 & V_57 ) >>
V_58 ;
F_12 ( V_2 , L_3 , error ) ;
return V_44 ;
}
if ( ! V_49 )
* V_45 = F_2 ( V_2 , V_59 ) ;
V_53:
V_2 -> V_50 . V_51 . V_60 ( V_2 , V_46 ) ;
return V_49 ;
}
static T_2 F_16 ( struct V_1 * V_2 , T_3 V_61 ,
T_3 * V_45 )
{
T_2 V_62 ;
struct V_63 V_64 ;
V_64 . V_65 . V_66 . V_67 = V_68 ;
V_64 . V_65 . V_66 . V_69 = 0 ;
V_64 . V_65 . V_66 . V_70 = V_71 ;
V_64 . V_65 . V_66 . V_72 = V_73 ;
V_64 . V_74 = F_17 ( V_61 * 2 ) ;
V_64 . V_75 = F_18 ( sizeof( T_3 ) ) ;
V_62 = F_19 ( V_2 , ( T_1 * ) & V_64 ,
sizeof( V_64 ) ,
V_76 , false ) ;
if ( V_62 )
return V_62 ;
* V_45 = ( T_3 ) F_20 ( V_2 , V_77 ,
V_78 ) ;
return 0 ;
}
static T_2 F_21 ( struct V_1 * V_2 ,
T_3 V_61 , T_3 V_79 , T_3 * V_45 )
{
struct V_63 V_64 ;
T_1 V_80 = 0 ;
T_3 V_81 ;
T_2 V_62 ;
T_1 V_39 ;
V_62 = V_2 -> V_50 . V_51 . V_52 ( V_2 , V_82 ) ;
if ( V_62 ) {
F_12 ( V_2 , L_4 ) ;
return V_62 ;
}
while ( V_79 ) {
if ( V_79 > V_83 / 2 )
V_81 = V_83 / 2 ;
else
V_81 = V_79 ;
V_64 . V_65 . V_66 . V_67 = V_68 ;
V_64 . V_65 . V_66 . V_69 = 0 ;
V_64 . V_65 . V_66 . V_70 = V_71 ;
V_64 . V_65 . V_66 . V_72 = V_73 ;
V_64 . V_74 = F_17 ( ( V_61 + V_80 ) * 2 ) ;
V_64 . V_75 = F_18 ( V_81 * 2 ) ;
V_62 = F_19 ( V_2 , ( T_1 * ) & V_64 ,
sizeof( V_64 ) ,
V_76 ,
false ) ;
if ( V_62 ) {
F_12 ( V_2 , L_5 ) ;
goto V_53;
}
for ( V_39 = 0 ; V_39 < V_81 ; V_39 ++ ) {
T_1 V_84 = V_77 + ( V_78 << 2 ) +
2 * V_39 ;
T_1 V_85 = F_2 ( V_2 , V_84 ) ;
V_45 [ V_80 ] = ( T_3 ) ( V_85 & 0xffff ) ;
V_80 ++ ;
V_39 ++ ;
if ( V_39 < V_81 ) {
V_85 >>= 16 ;
V_45 [ V_80 ] = ( T_3 ) ( V_85 & 0xffff ) ;
V_80 ++ ;
}
}
V_79 -= V_81 ;
}
V_53:
V_2 -> V_50 . V_51 . V_60 ( V_2 , V_82 ) ;
return V_62 ;
}
static T_2 F_22 ( struct V_1 * V_2 , T_3 V_86 ,
T_3 V_87 , T_3 * V_88 , T_3 * V_64 ,
T_1 V_89 )
{
T_3 V_90 [ 256 ] ;
T_2 V_62 ;
T_3 V_75 , V_91 , V_39 , V_92 ;
T_3 * V_93 ;
V_91 = sizeof( V_90 ) / sizeof( V_90 [ 0 ] ) ;
if ( ! V_64 ) {
V_62 = F_21 ( V_2 , V_86 , V_91 , V_90 ) ;
if ( V_62 ) {
F_12 ( V_2 , L_6 ) ;
return V_62 ;
}
V_93 = V_90 ;
} else {
if ( V_89 < V_86 )
return V_94 ;
V_93 = & V_64 [ V_86 ] ;
}
if ( V_87 ) {
V_92 = 0 ;
V_75 = V_87 ;
} else {
V_92 = 1 ;
V_75 = V_93 [ 0 ] ;
if ( V_75 == 0xFFFF || V_75 == 0 ||
( V_86 + V_75 ) >= V_2 -> V_28 . V_36 )
return 0 ;
}
if ( V_64 && ( ( T_1 ) V_92 + ( T_1 ) V_75 > V_89 ) )
return V_94 ;
for ( V_39 = V_92 ; V_75 ; V_39 ++ , V_75 -- ) {
if ( V_39 == V_91 && ! V_64 ) {
V_86 += V_91 ;
V_39 = 0 ;
if ( V_75 < V_91 )
V_91 = V_75 ;
V_62 = F_21 ( V_2 , V_86 ,
V_91 , V_90 ) ;
if ( V_62 ) {
F_12 ( V_2 , L_6 ) ;
return V_62 ;
}
}
* V_88 += V_93 [ V_39 ] ;
}
return 0 ;
}
static T_2 F_23 ( struct V_1 * V_2 , T_3 * V_64 ,
T_1 V_89 )
{
T_3 V_95 [ V_96 + 1 ] ;
T_3 * V_93 ;
T_2 V_62 ;
T_3 V_72 = 0 ;
T_3 V_97 , V_39 , V_87 ;
V_2 -> V_28 . V_51 . V_98 ( V_2 ) ;
if ( ! V_64 ) {
V_62 = F_21 ( V_2 , 0 ,
V_96 + 1 ,
V_95 ) ;
if ( V_62 ) {
F_12 ( V_2 , L_6 ) ;
return V_62 ;
}
V_93 = V_95 ;
} else {
if ( V_89 < V_96 )
return V_94 ;
V_93 = V_64 ;
}
for ( V_39 = 0 ; V_39 <= V_96 ; V_39 ++ )
if ( V_39 != V_99 )
V_72 += V_93 [ V_39 ] ;
for ( V_39 = V_100 ; V_39 < V_101 ; V_39 ++ ) {
if ( V_39 == V_102 || V_39 == V_103 )
continue;
V_97 = V_93 [ V_39 ] ;
if ( V_97 == 0xFFFF || V_97 == 0 ||
V_97 >= V_2 -> V_28 . V_36 )
continue;
switch ( V_39 ) {
case V_104 :
V_87 = V_105 ;
break;
case V_106 :
case V_107 :
V_87 = V_108 ;
break;
default:
V_87 = 0 ;
break;
}
V_62 = F_22 ( V_2 , V_97 , V_87 , & V_72 ,
V_64 , V_89 ) ;
if ( V_62 )
return V_62 ;
}
V_72 = ( T_3 ) V_109 - V_72 ;
return ( T_2 ) V_72 ;
}
static T_2 F_24 ( struct V_1 * V_2 )
{
return F_23 ( V_2 , NULL , 0 ) ;
}
static T_2 F_25 ( struct V_1 * V_2 , T_3 V_61 , T_3 * V_45 )
{
T_2 V_62 = 0 ;
if ( V_2 -> V_50 . V_51 . V_52 ( V_2 , V_82 ) == 0 ) {
V_62 = F_16 ( V_2 , V_61 , V_45 ) ;
V_2 -> V_50 . V_51 . V_60 ( V_2 , V_82 ) ;
} else {
V_62 = V_110 ;
}
return V_62 ;
}
static T_2 F_26 ( struct V_1 * V_2 ,
T_3 * V_111 )
{
T_2 V_62 ;
T_3 V_72 ;
T_3 V_112 = 0 ;
V_62 = V_2 -> V_28 . V_51 . V_113 ( V_2 , 0 , & V_72 ) ;
if ( V_62 ) {
F_12 ( V_2 , L_7 ) ;
return V_62 ;
}
V_62 = V_2 -> V_28 . V_51 . V_114 ( V_2 ) ;
if ( V_62 < 0 )
return V_62 ;
V_72 = ( T_3 ) ( V_62 & 0xffff ) ;
V_62 = F_25 ( V_2 , V_99 ,
& V_112 ) ;
if ( V_62 )
return V_62 ;
if ( V_112 != V_72 ) {
V_62 = V_115 ;
F_12 ( V_2 , L_8 ) ;
}
if ( V_111 )
* V_111 = V_72 ;
return V_62 ;
}
static T_2 F_27 ( struct V_1 * V_2 , T_3 V_61 ,
T_3 V_45 )
{
T_2 V_62 ;
struct V_116 V_64 ;
V_64 . V_65 . V_66 . V_67 = V_117 ;
V_64 . V_65 . V_66 . V_69 = 0 ;
V_64 . V_65 . V_66 . V_70 = V_118 ;
V_64 . V_65 . V_66 . V_72 = V_73 ;
V_64 . V_75 = F_18 ( sizeof( T_3 ) ) ;
V_64 . V_45 = V_45 ;
V_64 . V_74 = F_17 ( V_61 * 2 ) ;
V_62 = F_19 ( V_2 , ( T_1 * ) & V_64 ,
sizeof( V_64 ) ,
V_76 , false ) ;
return V_62 ;
}
static T_2 F_28 ( struct V_1 * V_2 , T_3 V_61 , T_3 V_45 )
{
T_2 V_62 = 0 ;
if ( V_2 -> V_50 . V_51 . V_52 ( V_2 , V_82 ) == 0 ) {
V_62 = F_27 ( V_2 , V_61 , V_45 ) ;
V_2 -> V_50 . V_51 . V_60 ( V_2 , V_82 ) ;
} else {
F_12 ( V_2 , L_9 ) ;
V_62 = V_110 ;
}
return V_62 ;
}
static T_2 F_29 ( struct V_1 * V_2 )
{
T_2 V_62 = 0 ;
union V_119 V_64 ;
V_64 . V_66 . V_67 = V_120 ;
V_64 . V_66 . V_69 = 0 ;
V_64 . V_66 . V_70 = V_121 ;
V_64 . V_66 . V_72 = V_73 ;
V_62 = F_19 ( V_2 , ( T_1 * ) & V_64 ,
sizeof( V_64 ) ,
V_76 , false ) ;
return V_62 ;
}
static void F_30 ( struct V_1 * V_2 )
{
T_1 V_122 , V_123 ;
T_2 V_62 ;
struct V_124 V_125 ;
V_122 = F_2 ( V_2 , V_126 ) ;
if ( V_122 & V_127 ) {
V_123 = F_2 ( V_2 , V_128 ) ;
if ( V_123 & V_129 ) {
V_123 &= ~ V_129 ;
F_3 ( V_2 , V_128 , V_123 ) ;
V_2 -> V_50 . V_130 = true ;
} else {
V_2 -> V_50 . V_130 = false ;
}
V_125 . V_65 . V_67 = V_131 ;
V_125 . V_65 . V_132 = V_133 ;
V_125 . V_65 . V_72 = V_73 ;
V_125 . V_134 = ( V_135 ) V_2 -> V_5 . V_6 ;
V_62 = F_19 ( V_2 , ( T_1 * ) & V_125 ,
sizeof( struct V_124 ) ,
V_76 , true ) ;
if ( V_62 ) {
V_122 = F_2 ( V_2 , V_126 ) ;
if ( V_122 & V_127 ) {
V_122 &= ~ V_127 ;
F_3 ( V_2 , V_126 , V_122 ) ;
}
}
}
}
static T_2 F_31 ( struct V_1 * V_2 )
{
T_2 V_62 ;
T_3 V_72 = 0 ;
V_62 = F_25 ( V_2 , 0 , & V_72 ) ;
if ( V_62 ) {
F_12 ( V_2 , L_7 ) ;
return V_62 ;
}
V_62 = F_24 ( V_2 ) ;
if ( V_62 < 0 )
return V_62 ;
V_72 = ( T_3 ) ( V_62 & 0xffff ) ;
V_62 = F_28 ( V_2 , V_99 ,
V_72 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_29 ( V_2 ) ;
return V_62 ;
}
static T_2 F_32 ( struct V_1 * V_2 ,
T_3 V_61 , T_3 V_79 ,
T_3 * V_45 )
{
T_2 V_62 = 0 ;
T_1 V_39 = 0 ;
V_62 = V_2 -> V_50 . V_51 . V_52 ( V_2 , V_82 ) ;
if ( V_62 ) {
F_12 ( V_2 , L_10 ) ;
return V_62 ;
}
for ( V_39 = 0 ; V_39 < V_79 ; V_39 ++ ) {
V_62 = F_27 ( V_2 , V_61 + V_39 ,
V_45 [ V_39 ] ) ;
if ( V_62 ) {
F_12 ( V_2 , L_11 ) ;
break;
}
}
V_2 -> V_50 . V_51 . V_60 ( V_2 , V_82 ) ;
return V_62 ;
}
static T_2 F_33 ( struct V_1 * V_2 , T_1 V_23 ,
T_1 V_24 , T_1 V_45 )
{
T_1 V_46 = V_47 | V_48 ;
T_1 V_40 , error ;
T_2 V_49 ;
V_49 = V_2 -> V_50 . V_51 . V_52 ( V_2 , V_46 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_13 ( V_2 , NULL ) ;
if ( V_49 )
goto V_53;
V_40 = ( ( V_23 << V_54 ) |
( V_24 << V_55 ) ) ;
F_3 ( V_2 , V_42 , V_40 ) ;
F_3 ( V_2 , V_59 , V_45 ) ;
V_49 = F_13 ( V_2 , & V_40 ) ;
if ( ( V_40 & V_56 ) != 0 ) {
error = ( V_40 & V_57 ) >>
V_58 ;
F_12 ( V_2 , L_12 , error ) ;
return V_44 ;
}
V_53:
V_2 -> V_50 . V_51 . V_60 ( V_2 , V_46 ) ;
return V_49 ;
}
static T_2 F_34 ( struct V_1 * V_2 , T_4 * V_136 )
{
T_2 V_62 ;
T_1 V_137 ;
V_62 = F_15 ( V_2 ,
F_35 ( V_2 -> V_5 . V_6 ) ,
V_138 , & V_137 ) ;
if ( V_62 )
return V_62 ;
V_137 &= ~ V_139 ;
V_137 &= ~ V_140 ;
switch ( * V_136 ) {
case V_141 :
V_137 |= V_142 ;
break;
case V_143 :
V_137 |= V_144 ;
break;
default:
return V_145 ;
}
V_62 = F_33 ( V_2 ,
F_35 ( V_2 -> V_5 . V_6 ) ,
V_138 , V_137 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_15 ( V_2 ,
F_36 ( V_2 -> V_5 . V_6 ) ,
V_138 , & V_137 ) ;
if ( V_62 )
return V_62 ;
V_137 |= V_146 ;
V_62 = F_33 ( V_2 ,
F_36 ( V_2 -> V_5 . V_6 ) ,
V_138 , V_137 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_15 ( V_2 ,
F_37 ( V_2 -> V_5 . V_6 ) ,
V_138 , & V_137 ) ;
if ( V_62 )
return V_62 ;
V_137 &= ~ V_147 ;
V_137 &= ~ V_148 ;
V_137 &= ~ V_149 ;
V_62 = F_33 ( V_2 ,
F_37 ( V_2 -> V_5 . V_6 ) ,
V_138 , V_137 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_15 ( V_2 ,
F_38 ( V_2 -> V_5 . V_6 ) ,
V_138 , & V_137 ) ;
if ( V_62 )
return V_62 ;
V_137 &= ~ V_147 ;
V_137 &= ~ V_148 ;
V_137 &= ~ V_149 ;
V_62 = F_33 ( V_2 ,
F_38 ( V_2 -> V_5 . V_6 ) ,
V_138 , V_137 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_15 ( V_2 ,
F_39 ( V_2 -> V_5 . V_6 ) ,
V_138 , & V_137 ) ;
if ( V_62 )
return V_62 ;
V_137 |= V_150 ;
V_137 |= V_151 ;
V_137 |= V_152 ;
V_137 |= V_153 ;
V_62 = F_33 ( V_2 ,
F_39 ( V_2 -> V_5 . V_6 ) ,
V_138 , V_137 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_15 ( V_2 ,
F_35 ( V_2 -> V_5 . V_6 ) ,
V_138 , & V_137 ) ;
if ( V_62 )
return V_62 ;
V_137 |= V_154 ;
V_62 = F_33 ( V_2 ,
F_35 ( V_2 -> V_5 . V_6 ) ,
V_138 , V_137 ) ;
return V_62 ;
}
static T_2 F_40 ( struct V_1 * V_2 ,
T_4 V_136 ,
bool V_155 )
{
T_2 V_62 ;
T_4 V_156 ;
if ( V_136 & V_141 )
V_156 = V_141 ;
else
V_156 = V_143 ;
if ( ! ( V_2 -> V_14 . V_157 & V_158 ) ) {
V_62 = F_34 ( V_2 , & V_156 ) ;
if ( V_62 )
return V_62 ;
}
return V_2 -> V_14 . V_51 . V_159 ( V_2 , V_136 , V_155 ) ;
}
static T_2 F_41 ( struct V_1 * V_2 ,
T_4 * V_136 ,
bool * V_160 ,
bool V_161 )
{
T_1 V_62 ;
T_3 V_162 ;
if ( V_2 -> V_50 . V_51 . V_163 ( V_2 ) != V_164 )
return V_165 ;
V_62 = F_42 ( V_2 , V_136 , V_160 ,
V_161 ) ;
if ( V_62 || ! ( * V_160 ) )
return V_62 ;
V_62 = V_2 -> V_14 . V_51 . V_166 ( V_2 , V_167 ,
V_168 ,
& V_162 ) ;
if ( V_62 )
return V_62 ;
if ( ! ( V_162 & V_169 ) )
* V_160 = false ;
return 0 ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_170 * V_50 = & V_2 -> V_50 ;
switch ( V_50 -> V_51 . V_163 ( V_2 ) ) {
case V_171 :
V_50 -> V_51 . V_172 = NULL ;
V_50 -> V_51 . V_173 = NULL ;
V_50 -> V_51 . V_174 = NULL ;
break;
case V_164 :
V_50 -> V_51 . V_175 = F_40 ;
V_50 -> V_51 . V_176 = F_41 ;
break;
default:
break;
}
}
static T_2 F_44 ( struct V_1 * V_2 )
{
bool V_177 ;
T_3 V_178 , V_179 ;
T_2 V_180 ;
switch ( V_2 -> V_14 . V_181 ) {
case V_182 :
return 0 ;
case V_183 :
return V_184 ;
case V_185 :
case V_186 :
V_177 = true ;
break;
case V_187 :
case V_188 :
case V_189 :
case V_190 :
case V_191 :
case V_192 :
V_177 = false ;
break;
default:
return V_193 ;
}
F_43 ( V_2 ) ;
V_2 -> V_14 . V_51 . V_194 = NULL ;
V_178 = V_195 + ( V_2 -> V_5 . V_6 << 12 ) ;
if ( V_177 )
V_179 = ( V_196 << 1 ) | 0x1 ;
else
V_179 = ( V_197 << 1 ) | 0x1 ;
V_180 = V_2 -> V_14 . V_51 . V_198 ( V_2 , V_199 , V_178 ,
V_179 ) ;
if ( V_180 )
V_180 = V_2 -> V_14 . V_51 . V_198 ( V_2 , 0x80 , V_178 ,
V_179 ) ;
return V_180 ;
}
static T_2 F_45 ( struct V_1 * V_2 ,
T_4 * V_136 ,
bool * V_200 )
{
if ( V_2 -> V_14 . V_201 == V_171 ) {
* V_200 = false ;
if ( V_2 -> V_14 . V_181 == V_191 ||
V_2 -> V_14 . V_181 == V_192 ) {
* V_136 = V_143 ;
return 0 ;
}
if ( V_2 -> V_14 . V_202 )
* V_136 = V_141 |
V_143 ;
else
* V_136 = V_141 ;
} else {
* V_136 = V_141 |
V_143 ;
* V_200 = true ;
}
return 0 ;
}
static T_2 F_46 ( struct V_1 * V_2 , bool * V_203 )
{
T_1 V_62 ;
T_3 V_84 ;
* V_203 = false ;
V_62 = V_2 -> V_14 . V_51 . V_166 ( V_2 , V_204 ,
V_205 ,
& V_84 ) ;
if ( V_62 || ! ( V_84 & V_206 ) )
return V_62 ;
V_62 = V_2 -> V_14 . V_51 . V_166 ( V_2 , V_207 ,
V_205 ,
& V_84 ) ;
if ( V_62 || ! ( V_84 & ( V_208 |
V_209 ) ) )
return V_62 ;
V_62 = V_2 -> V_14 . V_51 . V_166 ( V_2 , V_210 ,
V_205 ,
& V_84 ) ;
if ( V_62 )
return V_62 ;
if ( V_84 & V_211 ) {
F_47 ( V_2 , false ) ;
return V_212 ;
}
V_62 = V_2 -> V_14 . V_51 . V_166 ( V_2 , V_204 ,
V_168 , & V_84 ) ;
if ( V_62 || ! ( V_84 & V_213 ) )
return V_62 ;
V_62 = V_2 -> V_14 . V_51 . V_166 ( V_2 , V_214 ,
V_168 , & V_84 ) ;
if ( V_62 )
return V_62 ;
if ( V_84 & V_215 )
* V_203 = true ;
return 0 ;
}
static T_2 F_48 ( struct V_1 * V_2 )
{
T_1 V_62 ;
T_3 V_84 ;
bool V_203 ;
V_62 = F_46 ( V_2 , & V_203 ) ;
V_62 = V_2 -> V_14 . V_51 . V_166 ( V_2 , V_216 ,
V_168 , & V_84 ) ;
if ( V_62 )
return V_62 ;
V_84 |= V_217 ;
V_62 = V_2 -> V_14 . V_51 . V_218 ( V_2 , V_216 ,
V_168 , V_84 ) ;
if ( V_62 )
return V_62 ;
V_62 = V_2 -> V_14 . V_51 . V_166 ( V_2 , V_219 ,
V_205 ,
& V_84 ) ;
if ( V_62 )
return V_62 ;
V_84 |= V_220 ;
V_62 = V_2 -> V_14 . V_51 . V_218 ( V_2 , V_219 ,
V_205 ,
V_84 ) ;
if ( V_62 )
return V_62 ;
V_62 = V_2 -> V_14 . V_51 . V_166 ( V_2 , V_221 ,
V_205 ,
& V_84 ) ;
if ( V_62 )
return V_62 ;
V_84 |= ( V_208 |
V_209 ) ;
V_62 = V_2 -> V_14 . V_51 . V_218 ( V_2 , V_221 ,
V_205 ,
V_84 ) ;
if ( V_62 )
return V_62 ;
V_62 = V_2 -> V_14 . V_51 . V_166 ( V_2 , V_222 ,
V_205 ,
& V_84 ) ;
if ( V_62 )
return V_62 ;
V_84 |= V_206 ;
V_62 = V_2 -> V_14 . V_51 . V_218 ( V_2 , V_222 ,
V_205 ,
V_84 ) ;
return V_62 ;
}
static T_2 F_49 ( struct V_1 * V_2 )
{
struct V_223 * V_14 = & V_2 -> V_14 ;
bool V_203 ;
T_1 V_62 ;
V_62 = F_46 ( V_2 , & V_203 ) ;
if ( V_62 )
return V_62 ;
if ( V_203 )
return V_14 -> V_51 . V_224 ( V_2 ) ;
return 0 ;
}
static T_2 F_50 ( struct V_1 * V_2 ,
T_4 V_136 )
{
T_2 V_62 ;
T_1 V_137 ;
V_62 = F_15 ( V_2 ,
F_35 ( V_2 -> V_5 . V_6 ) ,
V_138 , & V_137 ) ;
if ( V_62 )
return V_62 ;
V_137 |= V_139 ;
V_137 &= ~ ( V_225 |
V_226 ) ;
V_137 &= ~ ( V_227 |
V_228 ) ;
if ( V_136 & V_141 )
V_137 |= V_227 ;
if ( V_136 & V_143 )
V_137 |= V_228 ;
V_137 |= V_154 ;
V_62 = F_33 ( V_2 ,
F_35 ( V_2 -> V_5 . V_6 ) ,
V_138 , V_137 ) ;
return V_62 ;
}
static T_2 F_51 ( struct V_1 * V_2 )
{
T_2 V_62 ;
T_1 V_137 ;
V_62 = F_15 ( V_2 , V_229 ,
V_230 +
V_2 -> V_5 . V_6 , & V_137 ) ;
if ( V_62 )
return V_62 ;
V_137 &= ~ ( V_231 |
V_232 ) ;
V_137 |= V_233 ;
if ( V_2 -> V_14 . V_234 & V_141 )
V_137 |= V_231 ;
if ( V_2 -> V_14 . V_234 & V_143 )
V_137 |= V_232 ;
V_137 |= V_235 ;
V_62 = F_33 ( V_2 , V_229 ,
V_230 +
V_2 -> V_5 . V_6 , V_137 ) ;
return V_62 ;
}
static T_2 F_52 ( struct V_1 * V_2 )
{
return F_50 ( V_2 , V_2 -> V_14 . V_234 ) ;
}
static T_2 F_53 ( struct V_1 * V_2 , bool * V_160 )
{
T_1 V_49 ;
T_3 V_162 ;
* V_160 = false ;
V_49 = V_2 -> V_14 . V_51 . V_166 ( V_2 , V_167 ,
V_168 ,
& V_162 ) ;
if ( V_49 )
return V_49 ;
V_49 = V_2 -> V_14 . V_51 . V_166 ( V_2 , V_167 ,
V_168 ,
& V_162 ) ;
if ( V_49 )
return V_49 ;
* V_160 = ! ! ( V_162 & V_169 ) ;
return 0 ;
}
static T_2 F_54 ( struct V_1 * V_2 )
{
T_4 V_156 ;
bool V_160 ;
T_1 V_62 ;
T_3 V_136 ;
if ( V_2 -> V_50 . V_51 . V_163 ( V_2 ) != V_164 )
return V_165 ;
V_62 = F_53 ( V_2 , & V_160 ) ;
if ( V_62 )
return V_62 ;
if ( ! V_160 )
return 0 ;
V_62 = V_2 -> V_14 . V_51 . V_166 ( V_2 , V_236 ,
V_168 ,
& V_136 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_53 ( V_2 , & V_160 ) ;
if ( V_62 )
return V_62 ;
if ( ! V_160 )
return 0 ;
V_136 &= V_237 ;
switch ( V_136 ) {
case V_238 :
V_156 = V_141 ;
break;
case V_239 :
V_156 = V_143 ;
break;
default:
return V_240 ;
}
return F_34 ( V_2 , & V_156 ) ;
}
static T_2 F_55 ( struct V_1 * V_2 )
{
T_2 V_62 ;
V_62 = F_56 ( V_2 ) ;
if ( V_62 )
return V_62 ;
return F_48 ( V_2 ) ;
}
static T_2 F_57 ( struct V_1 * V_2 )
{
struct V_223 * V_14 = & V_2 -> V_14 ;
T_4 V_136 ;
T_2 V_180 ;
V_2 -> V_50 . V_51 . V_241 ( V_2 ) ;
if ( V_2 -> V_50 . V_51 . V_163 ( V_2 ) == V_171 ) {
V_14 -> V_15 = V_16 ;
F_1 ( V_2 ) ;
V_14 -> V_157 = F_2 ( V_2 , V_242 ) ;
if ( V_14 -> V_157 & V_158 ) {
V_136 = V_141 |
V_143 ;
V_180 = F_50 ( V_2 , V_136 ) ;
}
}
V_180 = V_14 -> V_51 . V_243 ( V_2 ) ;
F_43 ( V_2 ) ;
if ( V_14 -> V_181 != V_182 )
V_14 -> V_51 . V_194 = NULL ;
switch ( V_2 -> V_14 . type ) {
case V_18 :
V_14 -> V_51 . V_175 = F_51 ;
V_14 -> V_51 . V_166 = F_8 ;
V_14 -> V_51 . V_218 = F_9 ;
break;
case V_20 :
V_14 -> V_51 . V_175 = F_52 ;
V_14 -> V_51 . V_166 = F_8 ;
V_14 -> V_51 . V_218 = F_9 ;
break;
case V_244 :
V_14 -> V_157 = F_2 ( V_2 , V_242 ) ;
if ( ! ( V_14 -> V_157 & V_158 ) ) {
V_14 -> V_51 . V_224 =
F_54 ;
} else {
V_136 = V_141 |
V_143 ;
V_180 = F_50 ( V_2 , V_136 ) ;
}
V_14 -> V_51 . V_245 = F_49 ;
V_14 -> V_51 . V_194 = F_55 ;
break;
default:
break;
}
return V_180 ;
}
static enum V_246 F_58 ( struct V_1 * V_2 )
{
enum V_246 V_201 ;
switch ( V_2 -> V_12 ) {
case V_19 :
case V_17 :
V_201 = V_247 ;
break;
case V_13 :
V_201 = V_171 ;
break;
case V_21 :
case V_22 :
V_201 = V_164 ;
break;
default:
V_201 = V_248 ;
break;
}
return V_201 ;
}
static T_2 F_59 ( struct V_1 * V_2 )
{
T_2 V_62 ;
T_3 V_84 ;
V_62 = V_2 -> V_14 . V_51 . V_166 ( V_2 ,
V_249 ,
V_250 ,
& V_84 ) ;
if ( V_62 )
return V_62 ;
if ( V_84 & V_251 ) {
V_62 = V_2 -> V_14 . V_51 . V_166 ( V_2 ,
V_252 ,
V_205 ,
& V_84 ) ;
if ( V_62 )
return V_62 ;
V_84 &= ~ V_253 ;
V_62 = V_2 -> V_14 . V_51 . V_218 ( V_2 ,
V_252 ,
V_205 ,
V_84 ) ;
if ( V_62 )
return V_62 ;
}
return V_62 ;
}
static T_2 F_60 ( struct V_1 * V_2 )
{
T_4 V_254 ;
T_2 V_62 ;
T_1 V_38 = 0 ;
T_1 V_39 ;
T_1 V_255 ;
bool V_160 = false ;
V_62 = V_2 -> V_50 . V_51 . V_256 ( V_2 ) ;
if ( V_62 )
return V_62 ;
F_61 ( V_2 ) ;
V_62 = V_2 -> V_14 . V_51 . V_257 ( V_2 ) ;
if ( V_2 -> V_14 . type == V_244 ) {
V_62 = F_59 ( V_2 ) ;
if ( V_62 )
return V_62 ;
}
if ( V_2 -> V_14 . V_258 ) {
V_62 = V_2 -> V_50 . V_51 . V_259 ( V_2 ) ;
V_2 -> V_14 . V_258 = false ;
}
if ( ! V_2 -> V_14 . V_260 && V_2 -> V_14 . V_51 . V_194 )
V_2 -> V_14 . V_51 . V_194 ( V_2 ) ;
V_261:
V_38 = V_262 ;
if ( ! V_2 -> V_263 ) {
V_2 -> V_50 . V_51 . V_176 ( V_2 , & V_254 , & V_160 , false ) ;
if ( V_160 )
V_38 = V_264 ;
}
V_38 |= F_2 ( V_2 , V_265 ) ;
F_3 ( V_2 , V_265 , V_38 ) ;
F_4 ( V_2 ) ;
for ( V_39 = 0 ; V_39 < 10 ; V_39 ++ ) {
F_62 ( 1 ) ;
V_38 = F_2 ( V_2 , V_265 ) ;
if ( ! ( V_38 & V_266 ) )
break;
}
if ( V_38 & V_266 ) {
V_62 = V_267 ;
F_12 ( V_2 , L_13 ) ;
}
F_63 ( 50 ) ;
if ( V_2 -> V_50 . V_268 & V_269 ) {
V_2 -> V_50 . V_268 &= ~ V_269 ;
goto V_261;
}
V_2 -> V_50 . V_51 . V_270 ( V_2 , V_2 -> V_50 . V_271 ) ;
V_2 -> V_50 . V_272 = 128 ;
V_2 -> V_50 . V_51 . V_273 ( V_2 ) ;
if ( V_2 -> V_12 == V_22 ) {
V_255 = F_2 ( V_2 , V_274 ) ;
V_255 &= ~ V_275 ;
F_3 ( V_2 , V_274 , V_255 ) ;
}
if ( V_2 -> V_12 == V_13 )
F_1 ( V_2 ) ;
return V_62 ;
}
static void F_64 ( struct V_1 * V_2 ,
bool V_276 , int V_277 )
{
int V_278 = V_277 >> 3 ;
int V_279 = V_277 % 8 + V_280 ;
T_1 V_281 ;
V_281 = F_2 ( V_2 , F_65 ( V_278 ) ) ;
if ( V_276 )
V_281 |= ( 1 << V_279 ) ;
else
V_281 &= ~ ( 1 << V_279 ) ;
F_3 ( V_2 , F_65 ( V_278 ) , V_281 ) ;
}
static void F_66 ( struct V_1 * V_2 ,
bool V_276 ,
unsigned int V_282 )
{
T_5 V_283 ;
if ( V_282 > 63 )
return;
V_283 = ( T_5 ) F_2 ( V_2 , V_284 ) ;
V_283 |= ( T_5 ) F_2 ( V_2 , V_285 ) << 32 ;
if ( V_276 )
V_283 |= ( 1ULL << V_282 ) ;
else
V_283 &= ~ ( 1ULL << V_282 ) ;
F_3 ( V_2 , V_284 , ( T_1 ) V_283 ) ;
F_3 ( V_2 , V_285 , ( T_1 ) ( V_283 >> 32 ) ) ;
}
