static T_1 F_1 ( struct V_1 * V_2 )
{
T_2 V_3 = F_2 ( V_2 , V_4 ) ;
switch ( V_2 -> V_5 ) {
case V_6 :
V_2 -> V_7 . V_8 = V_9 ;
if ( V_2 -> V_10 . V_11 ) {
V_3 &= ~ ( V_12 | V_13 ) ;
V_3 |= V_14 ;
}
V_3 &= ~ ( V_15 | V_16 ) ;
F_3 ( V_2 , V_4 , V_3 ) ;
return F_4 ( V_2 ) ;
case V_17 :
V_2 -> V_7 . type = V_18 ;
break;
case V_19 :
V_2 -> V_7 . type = V_20 ;
break;
case V_21 :
case V_22 :
return F_5 ( V_2 ) ;
default:
break;
}
return 0 ;
}
static T_1 F_6 ( struct V_1 * V_2 , T_2 V_23 ,
T_2 V_24 , T_3 * V_25 )
{
return V_26 ;
}
static T_1 F_7 ( struct V_1 * V_2 , T_2 V_23 ,
T_2 V_24 , T_3 V_25 )
{
return V_26 ;
}
static T_1 F_8 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = & V_2 -> V_28 ;
T_2 V_29 ;
T_3 V_30 ;
if ( V_28 -> type == V_31 ) {
V_28 -> V_32 = 10 ;
V_28 -> type = V_33 ;
V_29 = F_2 ( V_2 , V_34 ) ;
V_30 = ( T_3 ) ( ( V_29 & V_35 ) >>
V_36 ) ;
V_28 -> V_37 = 1 << ( V_30 +
V_38 ) ;
F_9 ( V_2 , L_1 ,
V_28 -> type , V_28 -> V_37 ) ;
}
return 0 ;
}
static T_1 F_10 ( struct V_1 * V_2 , T_2 V_23 ,
T_2 V_24 , T_2 * V_39 )
{
T_2 V_40 , V_41 , error ;
V_41 = ( ( V_23 << V_42 ) |
( V_24 << V_43 ) ) ;
F_3 ( V_2 , V_44 , V_41 ) ;
for ( V_40 = 0 ; V_40 < V_45 ; V_40 ++ ) {
F_11 ( 10 , 20 ) ;
V_41 = F_2 ( V_2 , V_44 ) ;
if ( ( V_41 & V_46 ) == 0 )
break;
}
if ( ( V_41 & V_47 ) != 0 ) {
error = ( V_41 & V_48 ) >>
V_49 ;
F_9 ( V_2 , L_2 , error ) ;
return V_50 ;
}
if ( V_40 == V_45 ) {
F_9 ( V_2 , L_3 ) ;
return V_50 ;
}
* V_39 = F_2 ( V_2 , V_51 ) ;
return 0 ;
}
static T_1 F_12 ( struct V_1 * V_2 , T_3 V_52 ,
T_3 * V_39 )
{
T_1 V_53 ;
struct V_54 V_55 ;
V_55 . V_56 . V_57 . V_58 = V_59 ;
V_55 . V_56 . V_57 . V_60 = 0 ;
V_55 . V_56 . V_57 . V_61 = V_62 ;
V_55 . V_56 . V_57 . V_63 = V_64 ;
V_55 . V_65 = F_13 ( V_52 * 2 ) ;
V_55 . V_66 = F_14 ( sizeof( T_3 ) ) ;
V_53 = F_15 ( V_2 , ( T_2 * ) & V_55 ,
sizeof( V_55 ) ,
V_67 , false ) ;
if ( V_53 )
return V_53 ;
* V_39 = ( T_3 ) F_16 ( V_2 , V_68 ,
V_69 ) ;
return 0 ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
T_3 V_52 , T_3 V_70 , T_3 * V_39 )
{
struct V_54 V_55 ;
T_2 V_71 = 0 ;
T_3 V_72 ;
T_1 V_53 ;
T_2 V_40 ;
V_53 = V_2 -> V_73 . V_74 . V_75 ( V_2 , V_76 ) ;
if ( V_53 ) {
F_9 ( V_2 , L_4 ) ;
return V_53 ;
}
while ( V_70 ) {
if ( V_70 > V_77 / 2 )
V_72 = V_77 / 2 ;
else
V_72 = V_70 ;
V_55 . V_56 . V_57 . V_58 = V_59 ;
V_55 . V_56 . V_57 . V_60 = 0 ;
V_55 . V_56 . V_57 . V_61 = V_62 ;
V_55 . V_56 . V_57 . V_63 = V_64 ;
V_55 . V_65 = F_13 ( ( V_52 + V_71 ) * 2 ) ;
V_55 . V_66 = F_14 ( V_72 * 2 ) ;
V_53 = F_15 ( V_2 , ( T_2 * ) & V_55 ,
sizeof( V_55 ) ,
V_67 ,
false ) ;
if ( V_53 ) {
F_9 ( V_2 , L_5 ) ;
goto V_78;
}
for ( V_40 = 0 ; V_40 < V_72 ; V_40 ++ ) {
T_2 V_79 = V_68 + ( V_69 << 2 ) +
2 * V_40 ;
T_2 V_80 = F_2 ( V_2 , V_79 ) ;
V_39 [ V_71 ] = ( T_3 ) ( V_80 & 0xffff ) ;
V_71 ++ ;
V_40 ++ ;
if ( V_40 < V_72 ) {
V_80 >>= 16 ;
V_39 [ V_71 ] = ( T_3 ) ( V_80 & 0xffff ) ;
V_71 ++ ;
}
}
V_70 -= V_72 ;
}
V_78:
V_2 -> V_73 . V_74 . V_81 ( V_2 , V_76 ) ;
return V_53 ;
}
static T_1 F_18 ( struct V_1 * V_2 , T_3 V_82 ,
T_3 V_83 , T_3 * V_84 , T_3 * V_55 ,
T_2 V_85 )
{
T_3 V_86 [ 256 ] ;
T_1 V_53 ;
T_3 V_66 , V_87 , V_40 , V_88 ;
T_3 * V_89 ;
V_87 = sizeof( V_86 ) / sizeof( V_86 [ 0 ] ) ;
if ( ! V_55 ) {
V_53 = F_17 ( V_2 , V_82 , V_87 , V_86 ) ;
if ( V_53 ) {
F_9 ( V_2 , L_6 ) ;
return V_53 ;
}
V_89 = V_86 ;
} else {
if ( V_85 < V_82 )
return V_90 ;
V_89 = & V_55 [ V_82 ] ;
}
if ( V_83 ) {
V_88 = 0 ;
V_66 = V_83 ;
} else {
V_88 = 1 ;
V_66 = V_89 [ 0 ] ;
if ( V_66 == 0xFFFF || V_66 == 0 ||
( V_82 + V_66 ) >= V_2 -> V_28 . V_37 )
return 0 ;
}
if ( V_55 && ( ( T_2 ) V_88 + ( T_2 ) V_66 > V_85 ) )
return V_90 ;
for ( V_40 = V_88 ; V_66 ; V_40 ++ , V_66 -- ) {
if ( V_40 == V_87 && ! V_55 ) {
V_82 += V_87 ;
V_40 = 0 ;
if ( V_66 < V_87 )
V_87 = V_66 ;
V_53 = F_17 ( V_2 , V_82 ,
V_87 , V_86 ) ;
if ( V_53 ) {
F_9 ( V_2 , L_6 ) ;
return V_53 ;
}
}
* V_84 += V_89 [ V_40 ] ;
}
return 0 ;
}
static T_1 F_19 ( struct V_1 * V_2 , T_3 * V_55 ,
T_2 V_85 )
{
T_3 V_91 [ V_92 + 1 ] ;
T_3 * V_89 ;
T_1 V_53 ;
T_3 V_63 = 0 ;
T_3 V_93 , V_40 , V_83 ;
V_2 -> V_28 . V_74 . V_94 ( V_2 ) ;
if ( ! V_55 ) {
V_53 = F_17 ( V_2 , 0 ,
V_92 + 1 ,
V_91 ) ;
if ( V_53 ) {
F_9 ( V_2 , L_6 ) ;
return V_53 ;
}
V_89 = V_91 ;
} else {
if ( V_85 < V_92 )
return V_90 ;
V_89 = V_55 ;
}
for ( V_40 = 0 ; V_40 <= V_92 ; V_40 ++ )
if ( V_40 != V_95 )
V_63 += V_89 [ V_40 ] ;
for ( V_40 = V_96 ; V_40 < V_97 ; V_40 ++ ) {
if ( V_40 == V_98 || V_40 == V_99 )
continue;
V_93 = V_89 [ V_40 ] ;
if ( V_93 == 0xFFFF || V_93 == 0 ||
V_93 >= V_2 -> V_28 . V_37 )
continue;
switch ( V_40 ) {
case V_100 :
V_83 = V_101 ;
break;
case V_102 :
case V_103 :
V_83 = V_104 ;
break;
default:
V_83 = 0 ;
break;
}
V_53 = F_18 ( V_2 , V_93 , V_83 , & V_63 ,
V_55 , V_85 ) ;
if ( V_53 )
return V_53 ;
}
V_63 = ( T_3 ) V_105 - V_63 ;
return ( T_1 ) V_63 ;
}
static T_1 F_20 ( struct V_1 * V_2 )
{
return F_19 ( V_2 , NULL , 0 ) ;
}
static T_1 F_21 ( struct V_1 * V_2 , T_3 V_52 , T_3 * V_39 )
{
T_1 V_53 = 0 ;
if ( V_2 -> V_73 . V_74 . V_75 ( V_2 , V_76 ) == 0 ) {
V_53 = F_12 ( V_2 , V_52 , V_39 ) ;
V_2 -> V_73 . V_74 . V_81 ( V_2 , V_76 ) ;
} else {
V_53 = V_106 ;
}
return V_53 ;
}
static T_1 F_22 ( struct V_1 * V_2 ,
T_3 * V_107 )
{
T_1 V_53 ;
T_3 V_63 ;
T_3 V_108 = 0 ;
V_53 = V_2 -> V_28 . V_74 . V_109 ( V_2 , 0 , & V_63 ) ;
if ( V_53 ) {
F_9 ( V_2 , L_7 ) ;
return V_53 ;
}
V_53 = V_2 -> V_28 . V_74 . V_110 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
V_63 = ( T_3 ) ( V_53 & 0xffff ) ;
V_53 = F_21 ( V_2 , V_95 ,
& V_108 ) ;
if ( V_53 )
return V_53 ;
if ( V_108 != V_63 ) {
V_53 = V_111 ;
F_9 ( V_2 , L_8 ) ;
}
if ( V_107 )
* V_107 = V_63 ;
return V_53 ;
}
static T_1 F_23 ( struct V_1 * V_2 , T_3 V_52 ,
T_3 V_39 )
{
T_1 V_53 ;
struct V_112 V_55 ;
V_55 . V_56 . V_57 . V_58 = V_113 ;
V_55 . V_56 . V_57 . V_60 = 0 ;
V_55 . V_56 . V_57 . V_61 = V_114 ;
V_55 . V_56 . V_57 . V_63 = V_64 ;
V_55 . V_66 = F_14 ( sizeof( T_3 ) ) ;
V_55 . V_39 = V_39 ;
V_55 . V_65 = F_13 ( V_52 * 2 ) ;
V_53 = F_15 ( V_2 , ( T_2 * ) & V_55 ,
sizeof( V_55 ) ,
V_67 , false ) ;
return V_53 ;
}
static T_1 F_24 ( struct V_1 * V_2 , T_3 V_52 , T_3 V_39 )
{
T_1 V_53 = 0 ;
if ( V_2 -> V_73 . V_74 . V_75 ( V_2 , V_76 ) == 0 ) {
V_53 = F_23 ( V_2 , V_52 , V_39 ) ;
V_2 -> V_73 . V_74 . V_81 ( V_2 , V_76 ) ;
} else {
F_9 ( V_2 , L_9 ) ;
V_53 = V_106 ;
}
return V_53 ;
}
static T_1 F_25 ( struct V_1 * V_2 )
{
T_1 V_53 = 0 ;
union V_115 V_55 ;
V_55 . V_57 . V_58 = V_116 ;
V_55 . V_57 . V_60 = 0 ;
V_55 . V_57 . V_61 = V_117 ;
V_55 . V_57 . V_63 = V_64 ;
V_53 = F_15 ( V_2 , ( T_2 * ) & V_55 ,
sizeof( V_55 ) ,
V_67 , false ) ;
return V_53 ;
}
static void F_26 ( struct V_1 * V_2 )
{
T_2 V_118 , V_119 ;
T_1 V_53 ;
struct V_120 V_121 ;
V_118 = F_2 ( V_2 , V_122 ) ;
if ( V_118 & V_123 ) {
V_119 = F_2 ( V_2 , V_124 ) ;
if ( V_119 & V_125 ) {
V_119 &= ~ V_125 ;
F_3 ( V_2 , V_124 , V_119 ) ;
V_2 -> V_73 . V_126 = true ;
} else {
V_2 -> V_73 . V_126 = false ;
}
V_121 . V_56 . V_58 = V_127 ;
V_121 . V_56 . V_128 = V_129 ;
V_121 . V_56 . V_63 = V_64 ;
V_121 . V_130 = ( V_131 ) V_2 -> V_10 . V_11 ;
V_53 = F_15 ( V_2 , ( T_2 * ) & V_121 ,
sizeof( struct V_120 ) ,
V_67 , true ) ;
if ( V_53 ) {
V_118 = F_2 ( V_2 , V_122 ) ;
if ( V_118 & V_123 ) {
V_118 &= ~ V_123 ;
F_3 ( V_2 , V_122 , V_118 ) ;
}
}
}
}
static T_1 F_27 ( struct V_1 * V_2 )
{
T_1 V_53 ;
T_3 V_63 = 0 ;
V_53 = F_21 ( V_2 , 0 , & V_63 ) ;
if ( V_53 ) {
F_9 ( V_2 , L_7 ) ;
return V_53 ;
}
V_53 = F_20 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
V_63 = ( T_3 ) ( V_53 & 0xffff ) ;
V_53 = F_24 ( V_2 , V_95 ,
V_63 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_25 ( V_2 ) ;
return V_53 ;
}
static T_1 F_28 ( struct V_1 * V_2 ,
T_3 V_52 , T_3 V_70 ,
T_3 * V_39 )
{
T_1 V_53 = 0 ;
T_2 V_40 = 0 ;
V_53 = V_2 -> V_73 . V_74 . V_75 ( V_2 , V_76 ) ;
if ( V_53 ) {
F_9 ( V_2 , L_10 ) ;
return V_53 ;
}
for ( V_40 = 0 ; V_40 < V_70 ; V_40 ++ ) {
V_53 = F_23 ( V_2 , V_52 + V_40 ,
V_39 [ V_40 ] ) ;
if ( V_53 ) {
F_9 ( V_2 , L_11 ) ;
break;
}
}
V_2 -> V_73 . V_74 . V_81 ( V_2 , V_76 ) ;
return V_53 ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_132 * V_73 = & V_2 -> V_73 ;
if ( V_2 -> V_5 == V_6 ) {
V_73 -> V_74 . V_133 = NULL ;
V_73 -> V_74 . V_134 = NULL ;
V_73 -> V_74 . V_135 = NULL ;
}
}
static T_1 F_30 ( struct V_1 * V_2 )
{
bool V_136 ;
T_3 V_137 , V_138 ;
T_1 V_139 ;
switch ( V_2 -> V_7 . V_140 ) {
case V_141 :
return 0 ;
case V_142 :
return V_143 ;
case V_144 :
case V_145 :
V_136 = true ;
break;
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
V_136 = false ;
break;
default:
return V_152 ;
}
F_29 ( V_2 ) ;
V_2 -> V_7 . V_74 . V_153 = NULL ;
V_137 = V_154 + ( V_2 -> V_10 . V_11 << 12 ) ;
if ( V_136 )
V_138 = ( V_155 << 1 ) | 0x1 ;
else
V_138 = ( V_156 << 1 ) | 0x1 ;
V_139 = V_2 -> V_7 . V_74 . V_157 ( V_2 , V_158 , V_137 ,
V_138 ) ;
if ( V_139 )
V_139 = V_2 -> V_7 . V_74 . V_157 ( V_2 , 0x80 , V_137 ,
V_138 ) ;
return V_139 ;
}
static T_1 F_31 ( struct V_1 * V_2 ,
T_4 * V_159 ,
bool * V_160 )
{
if ( V_2 -> V_7 . V_161 == V_162 ) {
* V_160 = false ;
if ( V_2 -> V_7 . V_140 == V_150 ||
V_2 -> V_7 . V_140 == V_151 ) {
* V_159 = V_163 ;
return 0 ;
}
if ( V_2 -> V_7 . V_164 )
* V_159 = V_165 |
V_163 ;
else
* V_159 = V_165 ;
} else {
* V_159 = V_165 |
V_163 ;
* V_160 = true ;
}
return 0 ;
}
static T_1 F_32 ( struct V_1 * V_2 , T_2 V_23 ,
T_2 V_24 , T_2 V_39 )
{
T_2 V_40 , V_41 , error ;
V_41 = ( ( V_23 << V_42 ) |
( V_24 << V_43 ) ) ;
F_3 ( V_2 , V_44 , V_41 ) ;
F_3 ( V_2 , V_51 , V_39 ) ;
for ( V_40 = 0 ; V_40 < V_45 ; V_40 ++ ) {
F_11 ( 10 , 20 ) ;
V_41 = F_2 ( V_2 , V_44 ) ;
if ( ( V_41 & V_46 ) == 0 )
break;
}
if ( ( V_41 & V_47 ) != 0 ) {
error = ( V_41 & V_48 ) >>
V_49 ;
F_9 ( V_2 , L_12 , error ) ;
return V_50 ;
}
if ( V_40 == V_45 ) {
F_9 ( V_2 , L_13 ) ;
return V_50 ;
}
return 0 ;
}
static T_1 F_33 ( struct V_1 * V_2 , T_4 * V_159 )
{
T_1 V_53 ;
T_2 V_166 ;
V_53 = F_10 ( V_2 ,
F_34 ( V_2 -> V_10 . V_11 ) ,
V_167 , & V_166 ) ;
if ( V_53 )
return V_53 ;
V_166 &= ~ V_168 ;
V_166 &= ~ V_169 ;
switch ( * V_159 ) {
case V_165 :
V_166 |= V_170 ;
break;
case V_163 :
V_166 |= V_171 ;
break;
default:
return V_172 ;
}
V_53 = F_32 ( V_2 ,
F_35 ( V_2 -> V_10 . V_11 ) ,
V_167 , V_166 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_10 ( V_2 ,
F_35 ( V_2 -> V_10 . V_11 ) ,
V_167 , & V_166 ) ;
if ( V_53 )
return V_53 ;
V_166 |= V_173 ;
V_53 = F_32 ( V_2 ,
F_35 ( V_2 -> V_10 . V_11 ) ,
V_167 , V_166 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_10 ( V_2 ,
F_36 ( V_2 -> V_10 . V_11 ) ,
V_167 , & V_166 ) ;
if ( V_53 )
return V_53 ;
V_166 &= ~ V_174 ;
V_166 &= ~ V_175 ;
V_166 &= ~ V_176 ;
V_53 = F_32 ( V_2 ,
F_36 ( V_2 -> V_10 . V_11 ) ,
V_167 , V_166 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_10 ( V_2 ,
F_37 ( V_2 -> V_10 . V_11 ) ,
V_167 , & V_166 ) ;
if ( V_53 )
return V_53 ;
V_166 &= ~ V_174 ;
V_166 &= ~ V_175 ;
V_166 &= ~ V_176 ;
V_53 = F_32 ( V_2 ,
F_37 ( V_2 -> V_10 . V_11 ) ,
V_167 , V_166 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_10 ( V_2 ,
F_38 ( V_2 -> V_10 . V_11 ) ,
V_167 , & V_166 ) ;
if ( V_53 )
return V_53 ;
V_166 |= V_177 ;
V_166 |= V_178 ;
V_166 |= V_179 ;
V_166 |= V_180 ;
V_53 = F_32 ( V_2 ,
F_38 ( V_2 -> V_10 . V_11 ) ,
V_167 , V_166 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_10 ( V_2 ,
F_34 ( V_2 -> V_10 . V_11 ) ,
V_167 , & V_166 ) ;
if ( V_53 )
return V_53 ;
V_166 |= V_181 ;
V_53 = F_32 ( V_2 ,
F_34 ( V_2 -> V_10 . V_11 ) ,
V_167 , V_166 ) ;
return V_53 ;
}
static T_1 F_39 ( struct V_1 * V_2 )
{
T_1 V_53 ;
T_2 V_166 ;
V_53 = F_10 ( V_2 , V_182 ,
V_183 +
V_2 -> V_10 . V_11 , & V_166 ) ;
if ( V_53 )
return V_53 ;
V_166 &= ~ ( V_184 |
V_185 ) ;
V_166 |= V_186 ;
if ( V_2 -> V_7 . V_187 & V_165 )
V_166 |= V_184 ;
if ( V_2 -> V_7 . V_187 & V_163 )
V_166 |= V_185 ;
V_166 |= V_188 ;
V_53 = F_32 ( V_2 , V_182 ,
V_183 +
V_2 -> V_10 . V_11 , V_166 ) ;
return V_53 ;
}
static T_1 F_40 ( struct V_1 * V_2 )
{
T_1 V_53 ;
T_2 V_166 ;
V_53 = F_10 ( V_2 ,
F_34 ( V_2 -> V_10 . V_11 ) ,
V_167 , & V_166 ) ;
if ( V_53 )
return V_53 ;
V_166 |= V_168 ;
V_166 |= V_189 ;
V_166 |= V_190 ;
V_166 &= ~ ( V_191 |
V_192 ) ;
if ( V_2 -> V_7 . V_187 & V_165 )
V_166 |= V_191 ;
if ( V_2 -> V_7 . V_187 & V_163 )
V_166 |= V_192 ;
V_166 |= V_181 ;
V_53 = F_32 ( V_2 ,
F_34 ( V_2 -> V_10 . V_11 ) ,
V_167 , V_166 ) ;
return V_53 ;
}
static T_1 F_41 ( struct V_1 * V_2 )
{
T_2 V_53 ;
T_3 V_193 , V_194 , V_159 ;
T_4 V_195 ;
V_53 = V_2 -> V_7 . V_74 . V_196 ( V_2 , V_197 ,
V_198 , & V_193 ) ;
if ( V_53 )
return V_53 ;
if ( ! ( V_193 & V_199 ) )
return 0 ;
V_53 = V_2 -> V_7 . V_74 . V_196 ( V_2 , V_200 ,
V_201 ,
& V_194 ) ;
if ( V_53 )
return V_53 ;
V_53 = V_2 -> V_7 . V_74 . V_196 ( V_2 , V_200 ,
V_201 ,
& V_194 ) ;
if ( V_53 )
return V_53 ;
if ( ! ( V_194 & V_202 ) )
return V_203 ;
V_53 = V_2 -> V_7 . V_74 . V_196 ( V_2 , V_204 ,
V_201 ,
& V_159 ) ;
V_159 &= V_205 ;
switch ( V_159 ) {
case V_206 :
V_195 = V_165 ;
break;
case V_207 :
V_195 = V_163 ;
break;
default:
return V_203 ;
}
return F_33 ( V_2 , & V_195 ) ;
}
static T_1 F_42 ( struct V_1 * V_2 )
{
struct V_208 * V_7 = & V_2 -> V_7 ;
T_1 V_139 ;
T_2 V_3 ;
if ( V_2 -> V_5 == V_6 ) {
V_3 = F_2 ( V_2 , V_4 ) ;
V_7 -> V_8 = V_9 ;
if ( V_2 -> V_10 . V_11 ) {
V_3 &= ~ ( V_12 | V_13 ) ;
V_3 |= V_14 ;
}
V_3 &= ~ ( V_15 | V_16 ) ;
F_3 ( V_2 , V_4 , V_3 ) ;
}
V_139 = V_7 -> V_74 . V_209 ( V_2 ) ;
F_29 ( V_2 ) ;
if ( V_7 -> V_140 != V_141 )
V_7 -> V_74 . V_153 = NULL ;
switch ( V_2 -> V_7 . type ) {
case V_18 :
V_7 -> V_74 . V_210 = F_39 ;
V_7 -> V_74 . V_196 = F_6 ;
V_7 -> V_74 . V_211 = F_7 ;
break;
case V_20 :
V_7 -> V_74 . V_210 = F_40 ;
V_7 -> V_74 . V_196 = F_6 ;
V_7 -> V_74 . V_211 = F_7 ;
break;
case V_212 :
V_7 -> V_74 . V_213 = F_41 ;
break;
default:
break;
}
return V_139 ;
}
static enum V_214 F_43 ( struct V_1 * V_2 )
{
enum V_214 V_161 ;
switch ( V_2 -> V_5 ) {
case V_19 :
case V_17 :
V_161 = V_215 ;
break;
case V_6 :
V_161 = V_162 ;
break;
case V_21 :
case V_22 :
V_161 = V_216 ;
break;
default:
V_161 = V_217 ;
break;
}
return V_161 ;
}
static T_1 F_44 ( struct V_1 * V_2 )
{
T_2 V_53 ;
T_3 V_79 ;
T_2 V_218 = 2 ;
do {
if ( V_218 < 1 ) {
F_9 ( V_2 , L_14 ) ;
return V_50 ;
}
V_218 -- ;
V_53 = V_2 -> V_7 . V_74 . V_196 ( V_2 ,
V_219 ,
V_198 ,
& V_79 ) ;
if ( V_53 )
return V_53 ;
} while ( ( V_79 & V_220 ) != 1 );
V_53 = V_2 -> V_7 . V_74 . V_196 ( V_2 ,
V_221 ,
V_222 ,
& V_79 ) ;
if ( V_53 )
return V_53 ;
V_53 = V_2 -> V_7 . V_74 . V_196 ( V_2 ,
V_223 ,
V_198 ,
& V_79 ) ;
if ( V_53 )
return V_53 ;
V_79 &= ~ V_224 ;
V_53 = V_2 -> V_7 . V_74 . V_211 ( V_2 ,
V_223 ,
V_198 ,
V_79 ) ;
if ( V_53 )
return V_53 ;
V_53 = V_2 -> V_7 . V_74 . V_196 ( V_2 ,
V_225 ,
V_222 ,
& V_79 ) ;
if ( V_53 )
return V_53 ;
V_79 &= ~ V_226 ;
V_53 = V_2 -> V_7 . V_74 . V_211 ( V_2 ,
V_225 ,
V_222 ,
V_79 ) ;
return V_53 ;
}
static T_1 F_45 ( struct V_1 * V_2 )
{
T_4 V_227 ;
T_1 V_53 ;
T_2 V_228 = 0 ;
T_2 V_40 ;
bool V_229 = false ;
V_53 = V_2 -> V_73 . V_74 . V_230 ( V_2 ) ;
if ( V_53 )
return V_53 ;
F_46 ( V_2 ) ;
V_53 = V_2 -> V_7 . V_74 . V_231 ( V_2 ) ;
if ( V_2 -> V_7 . type == V_212 ) {
V_53 = F_44 ( V_2 ) ;
if ( V_53 )
return V_53 ;
}
if ( V_2 -> V_7 . V_232 ) {
V_53 = V_2 -> V_73 . V_74 . V_233 ( V_2 ) ;
V_2 -> V_7 . V_232 = false ;
}
if ( ! V_2 -> V_7 . V_234 && V_2 -> V_7 . V_74 . V_153 )
V_2 -> V_7 . V_74 . V_153 ( V_2 ) ;
V_235:
V_228 = V_236 ;
if ( ! V_2 -> V_237 ) {
V_2 -> V_73 . V_74 . V_238 ( V_2 , & V_227 , & V_229 , false ) ;
if ( V_229 )
V_228 = V_239 ;
}
V_228 |= F_2 ( V_2 , V_240 ) ;
F_3 ( V_2 , V_240 , V_228 ) ;
F_47 ( V_2 ) ;
for ( V_40 = 0 ; V_40 < 10 ; V_40 ++ ) {
F_48 ( 1 ) ;
V_228 = F_2 ( V_2 , V_240 ) ;
if ( ! ( V_228 & V_241 ) )
break;
}
if ( V_228 & V_241 ) {
V_53 = V_242 ;
F_9 ( V_2 , L_15 ) ;
}
F_49 ( 50 ) ;
if ( V_2 -> V_73 . V_243 & V_244 ) {
V_2 -> V_73 . V_243 &= ~ V_244 ;
goto V_235;
}
V_2 -> V_73 . V_74 . V_245 ( V_2 , V_2 -> V_73 . V_246 ) ;
V_2 -> V_73 . V_247 = 128 ;
V_2 -> V_73 . V_74 . V_248 ( V_2 ) ;
return V_53 ;
}
static void F_50 ( struct V_1 * V_2 ,
bool V_249 , int V_250 )
{
int V_251 = V_250 >> 3 ;
int V_252 = V_250 % 8 + V_253 ;
T_2 V_254 ;
V_254 = F_2 ( V_2 , F_51 ( V_251 ) ) ;
if ( V_249 )
V_254 |= ( 1 << V_252 ) ;
else
V_254 &= ~ ( 1 << V_252 ) ;
F_3 ( V_2 , F_51 ( V_251 ) , V_254 ) ;
}
static void F_52 ( struct V_1 * V_2 ,
bool V_249 ,
unsigned int V_255 )
{
T_5 V_256 ;
if ( V_255 > 63 )
return;
V_256 = ( T_5 ) F_2 ( V_2 , V_257 ) ;
V_256 |= ( T_5 ) F_2 ( V_2 , V_258 ) << 32 ;
if ( V_249 )
V_256 |= ( 1ULL << V_255 ) ;
else
V_256 &= ~ ( 1ULL << V_255 ) ;
F_3 ( V_2 , V_257 , ( T_2 ) V_256 ) ;
F_3 ( V_2 , V_258 , ( T_2 ) ( V_256 >> 32 ) ) ;
}
