static const struct V_1 * F_1 ( struct V_2 * V_3 ,
int V_4 )
{
const struct V_1 * V_5 ;
if ( F_2 ( V_3 , V_6 ) )
V_5 = & V_7 [ V_8 ] ;
else
V_5 = & V_7 [ V_9 ] ;
return V_5 ;
}
static void F_3 ( int V_4 , struct V_10 * clock )
{
clock -> V_11 = 5 * ( clock -> V_12 + 2 ) + ( clock -> V_13 + 2 ) ;
clock -> V_14 = clock -> V_15 * clock -> V_16 ;
clock -> V_17 = V_4 * clock -> V_11 / ( clock -> V_18 + 2 ) ;
clock -> V_19 = clock -> V_17 / clock -> V_14 ;
}
static int F_4 ( struct V_20 * V_21 )
{
T_1 V_22 ;
V_22 = F_5 ( V_23 ) ;
if ( ( V_22 & V_24 ) == 0 )
return - 1 ;
return 1 ;
}
static int F_6 ( struct V_2 * V_3 ,
struct V_25 * V_26 ,
struct V_25 * V_27 ,
int V_28 , int V_29 ,
struct V_30 * V_31 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_34 ;
struct V_35 * V_35 = F_7 ( V_3 ) ;
struct V_36 * V_37 = V_3 -> V_38 ;
int V_39 = V_35 -> V_39 ;
const struct V_40 * V_41 = & V_33 -> V_42 [ V_39 ] ;
int V_4 ;
struct V_10 clock ;
T_1 V_43 = 0 , V_44 = 0 , V_45 , V_46 ;
bool V_47 , V_48 = false ;
bool V_49 = false , V_50 = false ;
struct V_51 * V_52 = & V_21 -> V_52 ;
struct V_53 * V_54 ;
const struct V_1 * V_5 ;
if ( V_3 -> V_55 == NULL ) {
V_37 -> V_56 ( V_3 , V_28 , V_29 , V_31 ) ;
return 0 ;
}
F_8 (connector, &mode_config->connector_list, head) {
struct V_57 * V_57 = F_9 ( V_54 ) ;
if ( ! V_54 -> V_58
|| V_54 -> V_58 -> V_3 != V_3 )
continue;
switch ( V_57 -> type ) {
case V_6 :
V_49 = true ;
break;
case V_59 :
V_48 = true ;
break;
case V_60 :
V_50 = true ;
break;
}
}
V_4 = 96000 ;
V_5 = V_35 -> V_61 -> V_5 ( V_3 , V_4 ) ;
V_47 = V_5 -> V_62 ( V_5 , V_3 , V_27 -> clock , V_4 ,
& clock ) ;
if ( ! V_47 ) {
F_10 ( L_1 ,
V_27 -> clock , clock . V_19 ) ;
return 0 ;
}
V_44 = clock . V_18 << 16 | clock . V_12 << 8 | clock . V_13 ;
V_43 = V_63 ;
if ( V_49 ) {
V_43 |= V_64 ;
V_43 |= V_65 ;
} else
V_43 |= V_66 ;
if ( V_48 ) {
int V_67 =
V_27 -> clock / V_26 -> clock ;
V_43 |= V_65 ;
V_43 |=
( V_67 - 1 ) << V_68 ;
}
V_43 |= ( 1 << ( clock . V_15 - 1 ) ) << 16 ;
switch ( clock . V_16 ) {
case 5 :
V_43 |= V_69 ;
break;
case 7 :
V_43 |= V_70 ;
break;
case 10 :
V_43 |= V_71 ;
break;
case 14 :
V_43 |= V_72 ;
break;
}
if ( V_50 ) {
V_43 |= 3 ;
}
V_43 |= V_73 ;
V_46 = F_5 ( V_41 -> V_74 ) ;
V_45 = V_75 ;
if ( V_39 == 0 )
V_45 |= V_76 ;
else
V_45 |= V_77 ;
V_45 |= V_78 ;
V_46 |= V_79 ;
V_43 |= V_80 ;
if ( F_4 ( V_21 ) == V_39 )
F_11 ( V_23 , 0 ) ;
F_12 ( V_26 ) ;
if ( V_43 & V_80 ) {
F_11 ( V_41 -> V_81 , V_44 ) ;
F_11 ( V_41 -> V_43 , V_43 & ~ V_80 ) ;
F_5 ( V_41 -> V_43 ) ;
F_13 ( 150 ) ;
}
if ( V_49 ) {
T_1 V_82 = F_5 ( V_83 ) ;
V_82 &= ~ V_84 ;
if ( V_39 == 1 )
V_82 |= V_84 ;
V_82 |= V_85 | V_86 ;
V_82 &= ~ ( V_87 | V_88 ) ;
if ( clock . V_16 == 7 )
V_82 |= V_87 | V_88 ;
F_11 ( V_83 , V_82 ) ;
F_5 ( V_83 ) ;
}
F_11 ( V_41 -> V_81 , V_44 ) ;
F_11 ( V_41 -> V_43 , V_43 ) ;
F_5 ( V_41 -> V_43 ) ;
F_13 ( 150 ) ;
F_11 ( V_41 -> V_43 , V_43 ) ;
F_5 ( V_41 -> V_43 ) ;
F_13 ( 150 ) ;
F_11 ( V_41 -> V_89 , ( V_27 -> V_90 - 1 ) |
( ( V_27 -> V_91 - 1 ) << 16 ) ) ;
F_11 ( V_41 -> V_92 , ( V_27 -> V_93 - 1 ) |
( ( V_27 -> V_94 - 1 ) << 16 ) ) ;
F_11 ( V_41 -> V_95 , ( V_27 -> V_96 - 1 ) |
( ( V_27 -> V_97 - 1 ) << 16 ) ) ;
F_11 ( V_41 -> V_98 , ( V_27 -> V_99 - 1 ) |
( ( V_27 -> V_100 - 1 ) << 16 ) ) ;
F_11 ( V_41 -> V_101 , ( V_27 -> V_102 - 1 ) |
( ( V_27 -> V_103 - 1 ) << 16 ) ) ;
F_11 ( V_41 -> V_104 , ( V_27 -> V_105 - 1 ) |
( ( V_27 -> V_106 - 1 ) << 16 ) ) ;
F_11 ( V_41 -> V_107 ,
( ( V_26 -> V_108 - 1 ) << 16 ) | ( V_26 -> V_109 - 1 ) ) ;
F_11 ( V_41 -> V_110 , 0 ) ;
F_11 ( V_41 -> V_111 ,
( ( V_26 -> V_109 - 1 ) << 16 ) | ( V_26 -> V_108 - 1 ) ) ;
F_11 ( V_41 -> V_74 , V_46 ) ;
F_5 ( V_41 -> V_74 ) ;
F_14 ( V_21 ) ;
F_11 ( V_41 -> V_112 , V_45 ) ;
V_37 -> V_56 ( V_3 , V_28 , V_29 , V_31 ) ;
F_14 ( V_21 ) ;
return 0 ;
}
static int F_15 ( struct V_20 * V_21 ,
struct V_2 * V_3 )
{
struct V_35 * V_35 = F_7 ( V_3 ) ;
struct V_32 * V_33 = V_21 -> V_34 ;
int V_39 = V_35 -> V_39 ;
const struct V_40 * V_41 = & V_33 -> V_42 [ V_39 ] ;
T_1 V_43 ;
T_1 V_44 ;
struct V_10 clock ;
bool V_49 ;
struct V_113 * V_14 = & V_33 -> V_114 . V_39 [ V_39 ] ;
if ( F_16 ( V_21 , false ) ) {
V_43 = F_5 ( V_41 -> V_43 ) ;
if ( ( V_43 & V_115 ) == 0 )
V_44 = F_5 ( V_41 -> V_81 ) ;
else
V_44 = F_5 ( V_41 -> V_116 ) ;
V_49 = ( V_39 == 1 ) && ( F_5 ( V_83 ) & V_85 ) ;
F_17 ( V_21 ) ;
} else {
V_43 = V_14 -> V_43 ;
if ( ( V_43 & V_115 ) == 0 )
V_44 = V_14 -> V_81 ;
else
V_44 = V_14 -> V_116 ;
V_49 = ( V_39 == 1 ) && ( V_33 -> V_114 . V_117 . V_118 &
V_85 ) ;
}
clock . V_12 = ( V_44 & V_119 ) >> V_120 ;
clock . V_13 = ( V_44 & V_121 ) >> V_122 ;
clock . V_18 = ( V_44 & V_123 ) >> V_124 ;
if ( V_49 ) {
clock . V_15 =
F_18 ( ( V_43 &
V_125 ) >>
V_126 ) ;
clock . V_16 = 14 ;
if ( ( V_43 & V_127 ) ==
V_128 ) {
F_3 ( 66000 , & clock ) ;
} else
F_3 ( 48000 , & clock ) ;
} else {
if ( V_43 & V_129 )
clock . V_15 = 2 ;
else {
clock . V_15 =
( ( V_43 &
V_130 ) >>
V_126 ) + 2 ;
}
if ( V_43 & V_131 )
clock . V_16 = 4 ;
else
clock . V_16 = 2 ;
F_3 ( 48000 , & clock ) ;
}
return clock . V_19 ;
}
struct V_25 * F_19 ( struct V_20 * V_21 ,
struct V_2 * V_3 )
{
struct V_35 * V_35 = F_7 ( V_3 ) ;
int V_39 = V_35 -> V_39 ;
struct V_25 * V_26 ;
int V_132 ;
int V_95 ;
int V_133 ;
int V_104 ;
struct V_32 * V_33 = V_21 -> V_34 ;
struct V_113 * V_14 = & V_33 -> V_114 . V_39 [ V_39 ] ;
const struct V_40 * V_41 = & V_33 -> V_42 [ V_39 ] ;
if ( F_16 ( V_21 , false ) ) {
V_132 = F_5 ( V_41 -> V_89 ) ;
V_95 = F_5 ( V_41 -> V_95 ) ;
V_133 = F_5 ( V_41 -> V_98 ) ;
V_104 = F_5 ( V_41 -> V_104 ) ;
F_17 ( V_21 ) ;
} else {
V_132 = V_14 -> V_89 ;
V_95 = V_14 -> V_95 ;
V_133 = V_14 -> V_98 ;
V_104 = V_14 -> V_104 ;
}
V_26 = F_20 ( sizeof( * V_26 ) , V_134 ) ;
if ( ! V_26 )
return NULL ;
V_26 -> clock = F_15 ( V_21 , V_3 ) ;
V_26 -> V_109 = ( V_132 & 0xffff ) + 1 ;
V_26 -> V_89 = ( ( V_132 & 0xffff0000 ) >> 16 ) + 1 ;
V_26 -> V_135 = ( V_95 & 0xffff ) + 1 ;
V_26 -> V_136 = ( ( V_95 & 0xffff0000 ) >> 16 ) + 1 ;
V_26 -> V_108 = ( V_133 & 0xffff ) + 1 ;
V_26 -> V_98 = ( ( V_133 & 0xffff0000 ) >> 16 ) + 1 ;
V_26 -> V_137 = ( V_104 & 0xffff ) + 1 ;
V_26 -> V_138 = ( ( V_104 & 0xffff0000 ) >> 16 ) + 1 ;
F_21 ( V_26 ) ;
F_22 ( V_26 , 0 ) ;
return V_26 ;
}
static void F_23 ( struct V_20 * V_21 ,
struct V_35 * V_35 )
{
struct V_32 * V_33 = V_21 -> V_34 ;
T_1 V_139 [ 3 ] = { V_140 , V_141 , V_142 } ;
T_1 V_143 [ 3 ] = { V_144 , V_145 , V_146 } ;
struct V_147 * V_148 ;
if ( V_33 -> V_149 -> V_150 ) {
V_148 = F_24 ( V_21 , 4 * V_151 , L_2 , 1 ) ;
if ( ! V_148 ) {
V_35 -> V_148 = NULL ;
goto V_152;
}
V_35 -> V_148 = V_148 ;
V_35 -> V_153 = V_33 -> V_154 +
V_148 -> V_155 ;
} else {
V_35 -> V_148 = NULL ;
}
V_152:
F_11 ( V_139 [ V_35 -> V_39 ] , 0 ) ;
F_11 ( V_143 [ V_35 -> V_39 ] , 0 ) ;
}
void F_25 ( struct V_20 * V_21 , int V_39 ,
struct V_156 * V_157 )
{
struct V_32 * V_33 = V_21 -> V_34 ;
struct V_35 * V_35 ;
int V_158 ;
T_2 * V_159 , * V_160 , * V_161 ;
V_35 = F_20 ( sizeof( struct V_35 ) +
( V_162 * sizeof( struct V_53 * ) ) ,
V_134 ) ;
if ( V_35 == NULL )
return;
V_35 -> V_163 =
F_20 ( sizeof( struct V_164 ) , V_134 ) ;
if ( ! V_35 -> V_163 ) {
F_26 ( V_21 -> V_21 , L_3 ) ;
F_27 ( V_35 ) ;
return;
}
F_28 ( V_21 , & V_35 -> V_143 , V_33 -> V_149 -> V_37 ) ;
V_35 -> V_61 = V_33 -> V_149 -> V_61 ;
F_29 ( & V_35 -> V_143 , 256 ) ;
V_35 -> V_39 = V_39 ;
V_35 -> V_165 = V_39 ;
V_159 = V_35 -> V_143 . V_166 ;
V_160 = V_159 + 256 ;
V_161 = V_160 + 256 ;
for ( V_158 = 0 ; V_158 < 256 ; V_158 ++ ) {
V_35 -> V_167 [ V_158 ] = V_158 ;
V_35 -> V_168 [ V_158 ] = V_158 ;
V_35 -> V_169 [ V_158 ] = V_158 ;
V_159 [ V_158 ] = V_158 << 8 ;
V_160 [ V_158 ] = V_158 << 8 ;
V_161 [ V_158 ] = V_158 << 8 ;
V_35 -> V_170 [ V_158 ] = 0 ;
}
V_35 -> V_157 = V_157 ;
V_35 -> V_153 = 0 ;
F_30 ( & V_35 -> V_143 ,
V_33 -> V_149 -> V_171 ) ;
V_35 -> V_172 . V_3 = & V_35 -> V_143 ;
F_31 ( V_39 >= F_32 ( V_33 -> V_173 ) ||
V_33 -> V_173 [ V_35 -> V_165 ] != NULL ) ;
V_33 -> V_173 [ V_35 -> V_165 ] = & V_35 -> V_143 ;
V_33 -> V_174 [ V_35 -> V_39 ] = & V_35 -> V_143 ;
V_35 -> V_172 . V_175 = (struct V_53 * * ) ( V_35 + 1 ) ;
V_35 -> V_172 . V_176 = 0 ;
F_23 ( V_21 , V_35 ) ;
V_35 -> V_177 = true ;
}
int F_33 ( struct V_20 * V_21 , void * V_178 ,
struct V_179 * V_180 )
{
struct V_32 * V_33 = V_21 -> V_34 ;
struct V_181 * V_182 = V_178 ;
struct V_183 * V_184 ;
struct V_35 * V_3 ;
if ( ! V_33 ) {
F_26 ( V_21 -> V_21 , L_4 ) ;
return - V_185 ;
}
V_184 = F_34 ( V_21 , V_182 -> V_186 ,
V_187 ) ;
if ( ! V_184 ) {
F_26 ( V_21 -> V_21 , L_5 ) ;
return - V_188 ;
}
V_3 = F_7 ( F_35 ( V_184 ) ) ;
V_182 -> V_39 = V_3 -> V_39 ;
return 0 ;
}
struct V_2 * F_36 ( struct V_20 * V_21 , int V_39 )
{
struct V_2 * V_3 = NULL ;
F_8 (crtc, &dev->mode_config.crtc_list, head) {
struct V_35 * V_35 = F_7 ( V_3 ) ;
if ( V_35 -> V_39 == V_39 )
break;
}
return V_3 ;
}
int F_37 ( struct V_20 * V_21 , int V_189 )
{
int V_190 = 0 ;
struct V_53 * V_54 ;
int V_191 = 0 ;
F_8 (connector, &dev->mode_config.connector_list,
head) {
struct V_57 * V_57 = F_9 ( V_54 ) ;
if ( V_189 & ( 1 << V_57 -> type ) )
V_190 |= ( 1 << V_191 ) ;
V_191 ++ ;
}
return V_190 ;
}
