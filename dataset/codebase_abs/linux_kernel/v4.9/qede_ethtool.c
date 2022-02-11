static void F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
int V_4 , V_5 , V_6 ;
for ( V_4 = 0 , V_6 = 0 ; V_4 < F_2 ( V_2 ) ; V_4 ++ ) {
int V_7 ;
if ( V_2 -> V_8 [ V_4 ] . type & V_9 ) {
for ( V_5 = 0 ; V_5 < V_10 ; V_5 ++ )
sprintf ( V_3 + ( V_6 + V_5 ) * V_11 ,
L_1 , V_4 ,
V_12 [ V_5 ] . string ) ;
V_6 += V_10 ;
}
if ( V_2 -> V_8 [ V_4 ] . type & V_13 ) {
for ( V_7 = 0 ; V_7 < V_2 -> V_14 ; V_7 ++ ) {
for ( V_5 = 0 ; V_5 < V_15 ; V_5 ++ )
sprintf ( V_3 + ( V_6 + V_5 ) *
V_11 ,
L_2 , V_4 , V_7 ,
V_16 [ V_5 ] . string ) ;
V_6 += V_15 ;
}
}
}
for ( V_4 = 0 , V_5 = 0 ; V_4 < V_17 ; V_4 ++ ) {
if ( F_3 ( V_2 ) && V_18 [ V_4 ] . V_19 )
continue;
strcpy ( V_3 + ( V_6 + V_5 ) * V_11 ,
V_18 [ V_4 ] . string ) ;
V_5 ++ ;
}
}
static void F_4 ( struct V_20 * V_21 , T_2 V_22 , T_1 * V_3 )
{
struct V_1 * V_2 = F_5 ( V_21 ) ;
switch ( V_22 ) {
case V_23 :
F_1 ( V_2 , V_3 ) ;
break;
case V_24 :
memcpy ( V_3 , V_25 ,
V_11 * V_26 ) ;
break;
case V_27 :
memcpy ( V_3 , V_28 ,
V_11 * V_29 ) ;
break;
default:
F_6 ( V_2 , V_30 ,
L_3 , V_22 ) ;
}
}
static void F_7 ( struct V_20 * V_21 ,
struct V_31 * V_32 , T_3 * V_3 )
{
struct V_1 * V_2 = F_5 ( V_21 ) ;
int V_33 , V_34 = 0 ;
int V_35 ;
F_8 ( V_2 ) ;
F_9 ( & V_2 -> V_36 ) ;
for ( V_35 = 0 ; V_35 < F_2 ( V_2 ) ; V_35 ++ ) {
int V_7 ;
if ( V_2 -> V_8 [ V_35 ] . type & V_9 ) {
for ( V_33 = 0 ; V_33 < V_10 ; V_33 ++ )
V_3 [ V_34 ++ ] = F_10 ( V_2 , V_33 , V_35 ) ;
}
if ( V_2 -> V_8 [ V_35 ] . type & V_13 ) {
for ( V_7 = 0 ; V_7 < V_2 -> V_14 ; V_7 ++ ) {
for ( V_33 = 0 ; V_33 < V_15 ; V_33 ++ )
V_3 [ V_34 ++ ] = F_11 ( V_2 ,
V_33 ,
V_35 , V_7 ) ;
}
}
}
for ( V_33 = 0 ; V_33 < V_17 ; V_33 ++ ) {
if ( F_3 ( V_2 ) && V_18 [ V_33 ] . V_19 )
continue;
V_3 [ V_34 ++ ] = F_12 ( V_2 , V_33 ) ;
}
F_13 ( & V_2 -> V_36 ) ;
}
static int F_14 ( struct V_20 * V_21 , int V_22 )
{
struct V_1 * V_2 = F_5 ( V_21 ) ;
int V_37 = V_17 ;
switch ( V_22 ) {
case V_23 :
if ( F_3 ( V_2 ) ) {
int V_4 ;
for ( V_4 = 0 ; V_4 < V_17 ; V_4 ++ )
if ( V_18 [ V_4 ] . V_19 )
V_37 -- ;
}
return V_37 + F_15 ( V_2 ) * V_10 +
F_16 ( V_2 ) * V_15 * V_2 -> V_14 ;
case V_24 :
return V_26 ;
case V_27 :
if ( ! F_3 ( V_2 ) )
return V_29 ;
else
return 0 ;
default:
F_6 ( V_2 , V_30 ,
L_3 , V_22 ) ;
return - V_38 ;
}
}
static T_2 F_17 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_5 ( V_21 ) ;
return ( ! ! ( V_2 -> V_39 . V_40 . V_41 > 1 ) ) << V_42 ;
}
static int F_18 ( struct V_20 * V_21 ,
struct V_43 * V_44 )
{
struct V_45 * V_46 = & V_44 -> V_46 ;
struct V_1 * V_2 = F_5 ( V_21 ) ;
struct V_47 V_48 ;
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
V_2 -> V_49 -> V_40 -> V_50 ( V_2 -> V_51 , & V_48 ) ;
F_19 ( V_44 , V_52 ) ;
F_20 (current_link.supported_caps, cmd, supported)
F_19 ( V_44 , V_53 ) ;
F_20 (current_link.advertised_caps, cmd, advertising)
F_19 ( V_44 , V_54 ) ;
F_20 (current_link.lp_caps, cmd, lp_advertising)
if ( ( V_2 -> V_55 == V_56 ) && ( V_48 . V_57 ) ) {
V_46 -> V_58 = V_48 . V_58 ;
V_46 -> V_59 = V_48 . V_59 ;
} else {
V_46 -> V_58 = V_60 ;
V_46 -> V_59 = V_61 ;
}
V_46 -> V_62 = V_48 . V_62 ;
V_46 -> V_63 = ( V_48 . V_63 ) ? V_64 :
V_65 ;
return 0 ;
}
static int F_21 ( struct V_20 * V_21 ,
const struct V_43 * V_44 )
{
const struct V_45 * V_46 = & V_44 -> V_46 ;
struct V_1 * V_2 = F_5 ( V_21 ) ;
struct V_47 V_48 ;
struct V_66 V_67 ;
if ( ! V_2 -> V_49 || ! V_2 -> V_49 -> V_40 -> V_68 ( V_2 -> V_51 ) ) {
F_22 ( V_2 , L_4 ) ;
return - V_69 ;
}
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
V_2 -> V_49 -> V_40 -> V_50 ( V_2 -> V_51 , & V_48 ) ;
V_67 . V_70 |= V_71 ;
V_67 . V_70 |= V_72 ;
if ( V_46 -> V_63 == V_64 ) {
V_67 . V_63 = true ;
V_67 . V_73 = 0 ;
F_23 (params.adv_speeds, cmd, advertising)
} else {
V_67 . V_70 |= V_74 ;
V_67 . V_63 = false ;
V_67 . V_73 = V_46 -> V_58 ;
switch ( V_46 -> V_58 ) {
case V_75 :
if ( ! ( V_48 . V_76 &
V_77 ) ) {
F_22 ( V_2 , L_5 ) ;
return - V_38 ;
}
V_67 . V_78 = V_77 ;
break;
case V_79 :
if ( ! ( V_48 . V_76 &
V_80 ) ) {
F_22 ( V_2 , L_6 ) ;
return - V_38 ;
}
V_67 . V_78 = V_80 ;
break;
case V_81 :
if ( ! ( V_48 . V_76 &
V_82 ) ) {
F_22 ( V_2 , L_7 ) ;
return - V_38 ;
}
V_67 . V_78 = V_82 ;
break;
case V_83 :
if ( ! ( V_48 . V_76 &
V_84 ) ) {
F_22 ( V_2 , L_8 ) ;
return - V_38 ;
}
V_67 . V_78 = V_84 ;
break;
case V_85 :
if ( ! ( V_48 . V_76 &
V_86 ) ) {
F_22 ( V_2 , L_9 ) ;
return - V_38 ;
}
V_67 . V_78 = V_86 ;
break;
default:
F_22 ( V_2 , L_10 , V_46 -> V_58 ) ;
return - V_38 ;
}
}
V_67 . V_57 = true ;
V_2 -> V_49 -> V_40 -> V_87 ( V_2 -> V_51 , & V_67 ) ;
return 0 ;
}
static void F_24 ( struct V_20 * V_88 ,
struct V_89 * V_90 )
{
char V_91 [ V_92 ] , V_93 [ V_92 ] ;
struct V_1 * V_2 = F_5 ( V_88 ) ;
F_25 ( V_90 -> V_94 , L_11 , sizeof( V_90 -> V_94 ) ) ;
F_25 ( V_90 -> V_95 , V_96 , sizeof( V_90 -> V_95 ) ) ;
snprintf ( V_93 , V_92 , L_12 ,
V_2 -> V_39 . V_40 . V_97 ,
V_2 -> V_39 . V_40 . V_98 ,
V_2 -> V_39 . V_40 . V_99 ,
V_2 -> V_39 . V_40 . V_100 ) ;
snprintf ( V_91 , V_92 , L_12 ,
( V_2 -> V_39 . V_40 . V_101 >> 24 ) & 0xFF ,
( V_2 -> V_39 . V_40 . V_101 >> 16 ) & 0xFF ,
( V_2 -> V_39 . V_40 . V_101 >> 8 ) & 0xFF ,
V_2 -> V_39 . V_40 . V_101 & 0xFF ) ;
if ( ( strlen ( V_93 ) + strlen ( V_91 ) + strlen ( L_13 ) ) <
sizeof( V_90 -> V_102 ) ) {
snprintf ( V_90 -> V_102 , sizeof( V_90 -> V_102 ) ,
L_14 , V_91 , V_93 ) ;
} else {
snprintf ( V_90 -> V_102 , sizeof( V_90 -> V_102 ) ,
L_15 , V_91 , V_93 ) ;
}
F_25 ( V_90 -> V_103 , F_26 ( V_2 -> V_104 ) , sizeof( V_90 -> V_103 ) ) ;
}
static T_2 F_27 ( struct V_20 * V_88 )
{
struct V_1 * V_2 = F_5 ( V_88 ) ;
return ( ( T_2 ) V_2 -> V_105 << V_106 ) | V_2 -> V_107 ;
}
static void F_28 ( struct V_20 * V_88 , T_2 V_108 )
{
struct V_1 * V_2 = F_5 ( V_88 ) ;
T_2 V_107 = 0 ;
T_1 V_105 = 0 ;
F_29 ( V_108 , & V_107 , & V_105 ) ;
V_2 -> V_105 = V_105 ;
V_2 -> V_107 = V_107 ;
V_2 -> V_49 -> V_40 -> V_109 ( V_2 -> V_51 ,
V_107 , V_105 ) ;
}
static int F_30 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_5 ( V_21 ) ;
struct V_47 V_48 ;
struct V_66 V_110 ;
if ( ! V_2 -> V_49 || ! V_2 -> V_49 -> V_40 -> V_68 ( V_2 -> V_51 ) ) {
F_22 ( V_2 , L_4 ) ;
return - V_69 ;
}
if ( ! F_31 ( V_21 ) )
return 0 ;
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
V_2 -> V_49 -> V_40 -> V_50 ( V_2 -> V_51 , & V_48 ) ;
if ( ! V_48 . V_57 )
return 0 ;
memset ( & V_110 , 0 , sizeof( V_110 ) ) ;
V_110 . V_57 = false ;
V_2 -> V_49 -> V_40 -> V_87 ( V_2 -> V_51 , & V_110 ) ;
V_110 . V_57 = true ;
V_2 -> V_49 -> V_40 -> V_87 ( V_2 -> V_51 , & V_110 ) ;
return 0 ;
}
static T_2 F_32 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_5 ( V_21 ) ;
struct V_47 V_48 ;
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
V_2 -> V_49 -> V_40 -> V_50 ( V_2 -> V_51 , & V_48 ) ;
return V_48 . V_57 ;
}
static int F_33 ( struct V_20 * V_21 ,
struct V_111 * V_112 )
{
struct V_1 * V_2 = F_5 ( V_21 ) ;
T_4 V_113 , V_114 ;
memset ( V_112 , 0 , sizeof( struct V_111 ) ) ;
V_2 -> V_49 -> V_40 -> V_115 ( V_2 -> V_51 , & V_113 , & V_114 ) ;
V_112 -> V_116 = V_113 ;
V_112 -> V_117 = V_114 ;
return 0 ;
}
static int F_34 ( struct V_20 * V_21 ,
struct V_111 * V_112 )
{
struct V_1 * V_2 = F_5 ( V_21 ) ;
int V_4 , V_118 = 0 ;
T_4 V_113 , V_114 ;
T_1 V_119 ;
if ( ! F_31 ( V_21 ) ) {
F_22 ( V_2 , L_16 ) ;
return - V_38 ;
}
if ( V_112 -> V_116 > V_120 ||
V_112 -> V_117 > V_120 ) {
F_22 ( V_2 ,
L_17 ,
V_112 -> V_116 > V_120 ? L_18
: L_19 ,
V_120 ) ;
return - V_38 ;
}
V_113 = ( T_4 ) V_112 -> V_116 ;
V_114 = ( T_4 ) V_112 -> V_117 ;
F_35 (i) {
V_119 = V_2 -> V_8 [ V_4 ] . V_121 -> V_122 ;
V_118 = V_2 -> V_49 -> V_40 -> V_123 ( V_2 -> V_51 , V_113 , V_114 ,
( T_1 ) V_4 , V_119 ) ;
if ( V_118 ) {
F_22 ( V_2 , L_20 , V_118 ) ;
return V_118 ;
}
}
return V_118 ;
}
static void F_36 ( struct V_20 * V_21 ,
struct V_124 * V_125 )
{
struct V_1 * V_2 = F_5 ( V_21 ) ;
V_125 -> V_126 = V_127 ;
V_125 -> V_128 = V_2 -> V_129 ;
V_125 -> V_130 = V_131 ;
V_125 -> V_132 = V_2 -> V_133 ;
}
static int F_37 ( struct V_20 * V_21 ,
struct V_124 * V_125 )
{
struct V_1 * V_2 = F_5 ( V_21 ) ;
F_6 ( V_2 , ( V_134 | V_135 ) ,
L_21 ,
V_125 -> V_128 , V_125 -> V_132 ) ;
if ( V_125 -> V_128 > V_127 ||
V_125 -> V_128 < V_136 ||
V_125 -> V_132 > V_131 ||
V_125 -> V_132 < V_137 ) {
F_6 ( V_2 , ( V_134 | V_135 ) ,
L_22 ,
V_136 , V_127 ,
V_137 , V_131 ) ;
return - V_38 ;
}
V_2 -> V_129 = V_125 -> V_128 ;
V_2 -> V_133 = V_125 -> V_132 ;
if ( F_31 ( V_2 -> V_88 ) )
F_38 ( V_2 , NULL , NULL ) ;
return 0 ;
}
static void F_39 ( struct V_20 * V_21 ,
struct V_138 * V_139 )
{
struct V_1 * V_2 = F_5 ( V_21 ) ;
struct V_47 V_48 ;
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
V_2 -> V_49 -> V_40 -> V_50 ( V_2 -> V_51 , & V_48 ) ;
if ( V_48 . V_140 & V_141 )
V_139 -> V_63 = true ;
if ( V_48 . V_140 & V_142 )
V_139 -> V_143 = true ;
if ( V_48 . V_140 & V_144 )
V_139 -> V_145 = true ;
F_6 ( V_2 , V_30 ,
L_23 ,
V_139 -> V_44 , V_139 -> V_63 , V_139 -> V_143 ,
V_139 -> V_145 ) ;
}
static int F_40 ( struct V_20 * V_21 ,
struct V_138 * V_139 )
{
struct V_1 * V_2 = F_5 ( V_21 ) ;
struct V_66 V_67 ;
struct V_47 V_48 ;
if ( ! V_2 -> V_49 || ! V_2 -> V_49 -> V_40 -> V_68 ( V_2 -> V_51 ) ) {
F_22 ( V_2 ,
L_24 ) ;
return - V_69 ;
}
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
V_2 -> V_49 -> V_40 -> V_50 ( V_2 -> V_51 , & V_48 ) ;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
V_67 . V_70 |= V_146 ;
if ( V_139 -> V_63 ) {
if ( ! ( V_48 . V_76 & V_147 ) ) {
F_22 ( V_2 , L_25 ) ;
return - V_38 ;
}
V_67 . V_140 |= V_141 ;
}
if ( V_139 -> V_143 )
V_67 . V_140 |= V_142 ;
if ( V_139 -> V_145 )
V_67 . V_140 |= V_144 ;
V_67 . V_57 = true ;
V_2 -> V_49 -> V_40 -> V_87 ( V_2 -> V_51 , & V_67 ) ;
return 0 ;
}
static void F_41 ( struct V_20 * V_88 ,
struct V_148 * V_149 , void * V_150 )
{
struct V_1 * V_2 = F_5 ( V_88 ) ;
V_149 -> V_95 = 0 ;
memset ( V_150 , 0 , V_149 -> V_151 ) ;
if ( V_2 -> V_49 && V_2 -> V_49 -> V_40 )
V_2 -> V_49 -> V_40 -> V_152 ( V_2 -> V_51 , V_150 ) ;
}
static int F_42 ( struct V_20 * V_88 )
{
struct V_1 * V_2 = F_5 ( V_88 ) ;
if ( V_2 -> V_49 && V_2 -> V_49 -> V_40 )
return V_2 -> V_49 -> V_40 -> V_153 ( V_2 -> V_51 ) ;
else
return - V_38 ;
}
static void F_43 ( struct V_1 * V_2 , union V_154 * args )
{
V_2 -> V_88 -> V_155 = args -> V_155 ;
}
int F_44 ( struct V_20 * V_88 , int V_156 )
{
struct V_1 * V_2 = F_5 ( V_88 ) ;
union V_154 args ;
if ( ( V_156 > V_157 ) ||
( ( V_156 + V_158 ) < V_159 ) ) {
F_45 ( V_2 , L_26 ) ;
return - V_38 ;
}
F_6 ( V_2 , ( V_134 | V_135 ) ,
L_27 , V_156 ) ;
args . V_155 = V_156 ;
if ( F_31 ( V_2 -> V_88 ) )
F_38 ( V_2 , & F_43 , & args ) ;
F_43 ( V_2 , & args ) ;
return 0 ;
}
static void F_46 ( struct V_20 * V_21 ,
struct V_160 * V_161 )
{
struct V_1 * V_2 = F_5 ( V_21 ) ;
V_161 -> V_162 = F_47 ( V_2 ) ;
V_161 -> V_163 = F_47 ( V_2 ) ;
V_161 -> V_164 = F_47 ( V_2 ) ;
V_161 -> V_165 = F_2 ( V_2 ) - V_2 -> V_166 -
V_2 -> V_167 ;
V_161 -> V_168 = V_2 -> V_166 ;
V_161 -> V_169 = V_2 -> V_167 ;
}
static int F_48 ( struct V_20 * V_21 ,
struct V_160 * V_161 )
{
struct V_1 * V_2 = F_5 ( V_21 ) ;
T_2 V_170 ;
F_6 ( V_2 , ( V_134 | V_135 ) ,
L_28 ,
V_161 -> V_169 , V_161 -> V_168 ,
V_161 -> V_171 , V_161 -> V_165 ) ;
V_170 = V_161 -> V_169 + V_161 -> V_168 +
V_161 -> V_165 ;
if ( V_161 -> V_171 ) {
F_6 ( V_2 , ( V_134 | V_135 ) ,
L_29 ) ;
return - V_38 ;
}
if ( ! ( V_161 -> V_165 || ( V_161 -> V_169 &&
V_161 -> V_168 ) ) ) {
F_6 ( V_2 , ( V_134 | V_135 ) ,
L_30 ) ;
return - V_38 ;
}
if ( V_170 > F_47 ( V_2 ) ) {
F_6 ( V_2 , ( V_134 | V_135 ) ,
L_31 ,
V_170 , F_47 ( V_2 ) ) ;
return - V_38 ;
}
if ( ( V_170 == F_2 ( V_2 ) ) &&
( V_161 -> V_168 == V_2 -> V_166 ) &&
( V_161 -> V_169 == V_2 -> V_167 ) ) {
F_6 ( V_2 , ( V_134 | V_135 ) ,
L_32 ) ;
return 0 ;
}
if ( ( V_170 % V_2 -> V_39 . V_40 . V_41 ) ||
( V_161 -> V_168 % V_2 -> V_39 . V_40 . V_41 ) ||
( V_161 -> V_169 % V_2 -> V_39 . V_40 . V_41 ) ) {
F_6 ( V_2 , ( V_134 | V_135 ) ,
L_33 ,
V_2 -> V_39 . V_40 . V_41 ) ;
return - V_38 ;
}
V_2 -> V_172 = V_170 ;
V_2 -> V_173 = V_161 -> V_168 ;
V_2 -> V_174 = V_161 -> V_169 ;
if ( ( V_2 -> V_172 - V_2 -> V_173 ) != F_15 ( V_2 ) ) {
V_2 -> V_175 &= ~ V_176 ;
memset ( & V_2 -> V_177 . V_178 , 0 ,
sizeof( V_2 -> V_177 . V_178 ) ) ;
}
if ( F_31 ( V_21 ) )
F_38 ( V_2 , NULL , NULL ) ;
return 0 ;
}
static int F_49 ( struct V_20 * V_21 ,
enum V_179 V_55 )
{
struct V_1 * V_2 = F_5 ( V_21 ) ;
T_1 V_180 = 0 ;
switch ( V_55 ) {
case V_181 :
return 1 ;
case V_182 :
V_180 = V_183 ;
break;
case V_184 :
V_180 = V_185 ;
break;
case V_186 :
V_180 = V_187 ;
break;
}
V_2 -> V_49 -> V_40 -> V_188 ( V_2 -> V_51 , V_180 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , struct V_189 * V_90 )
{
V_90 -> V_190 = V_191 | V_192 ;
switch ( V_90 -> V_193 ) {
case V_194 :
case V_195 :
V_90 -> V_190 |= V_196 | V_197 ;
break;
case V_198 :
if ( V_2 -> V_177 . V_199 & V_200 )
V_90 -> V_190 |= V_196 | V_197 ;
break;
case V_201 :
if ( V_2 -> V_177 . V_199 & V_202 )
V_90 -> V_190 |= V_196 | V_197 ;
break;
case V_203 :
case V_204 :
break;
default:
V_90 -> V_190 = 0 ;
break;
}
return 0 ;
}
static int F_51 ( struct V_20 * V_21 , struct V_189 * V_90 ,
T_2 * T_5 V_205 )
{
struct V_1 * V_2 = F_5 ( V_21 ) ;
switch ( V_90 -> V_44 ) {
case V_206 :
V_90 -> V_190 = F_15 ( V_2 ) ;
return 0 ;
case V_207 :
return F_50 ( V_2 , V_90 ) ;
default:
F_45 ( V_2 , L_34 ) ;
return - V_69 ;
}
}
static int F_52 ( struct V_1 * V_2 , struct V_189 * V_90 )
{
struct V_208 V_209 ;
T_1 V_210 = 0 , V_211 = 0 ;
F_6 ( V_2 , V_30 ,
L_35 ,
V_90 -> V_193 , V_90 -> V_190 ) ;
switch ( V_90 -> V_193 ) {
case V_194 :
case V_195 :
if ( V_90 -> V_190 ^ ( V_191 | V_192 |
V_196 | V_197 ) ) {
F_22 ( V_2 , L_34 ) ;
return - V_38 ;
}
return 0 ;
case V_198 :
if ( V_90 -> V_190 == ( V_191 | V_192 |
V_196 | V_197 ) ) {
V_210 = V_200 ;
F_6 ( V_2 , V_30 ,
L_36 ) ;
} else if ( V_90 -> V_190 == ( V_191 | V_192 ) ) {
V_211 = V_200 ;
F_6 ( V_2 , V_30 ,
L_37 ) ;
} else {
return - V_38 ;
}
break;
case V_201 :
if ( V_90 -> V_190 == ( V_191 | V_192 |
V_196 | V_197 ) ) {
V_210 = V_202 ;
F_6 ( V_2 , V_30 ,
L_36 ) ;
} else if ( V_90 -> V_190 == ( V_191 | V_192 ) ) {
V_211 = V_202 ;
F_6 ( V_2 , V_30 ,
L_37 ) ;
} else {
return - V_38 ;
}
break;
case V_203 :
case V_204 :
if ( V_90 -> V_190 ^ ( V_191 | V_192 ) ) {
F_22 ( V_2 , L_34 ) ;
return - V_38 ;
}
return 0 ;
case V_212 :
case V_213 :
case V_214 :
case V_215 :
case V_216 :
case V_217 :
case V_218 :
case V_219 :
case V_220 :
case V_221 :
if ( V_90 -> V_190 ) {
F_22 ( V_2 , L_34 ) ;
return - V_38 ;
}
return 0 ;
default:
return - V_38 ;
}
if ( V_2 -> V_177 . V_199 == ( ( V_2 -> V_177 . V_199 &
~ V_211 ) | V_210 ) )
return 0 ;
V_2 -> V_177 . V_199 = ( V_2 -> V_177 . V_199 & ~ V_211 ) |
V_210 ;
V_2 -> V_175 |= V_222 ;
if ( F_31 ( V_2 -> V_88 ) ) {
memset ( & V_209 , 0 , sizeof( V_209 ) ) ;
V_209 . V_223 = 1 ;
V_209 . V_224 = 0 ;
memcpy ( & V_209 . V_177 , & V_2 -> V_177 ,
sizeof( V_209 . V_177 ) ) ;
return V_2 -> V_49 -> V_225 ( V_2 -> V_51 ,
& V_209 ) ;
}
return 0 ;
}
static int F_53 ( struct V_20 * V_21 , struct V_189 * V_90 )
{
struct V_1 * V_2 = F_5 ( V_21 ) ;
switch ( V_90 -> V_44 ) {
case V_226 :
return F_52 ( V_2 , V_90 ) ;
default:
F_22 ( V_2 , L_34 ) ;
return - V_69 ;
}
}
static T_2 F_54 ( struct V_20 * V_21 )
{
return V_227 ;
}
static T_2 F_55 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_5 ( V_21 ) ;
return sizeof( V_2 -> V_177 . V_228 ) ;
}
static int F_56 ( struct V_20 * V_21 , T_2 * V_229 , T_1 * V_230 , T_1 * V_231 )
{
struct V_1 * V_2 = F_5 ( V_21 ) ;
int V_4 ;
if ( V_231 )
* V_231 = V_232 ;
if ( ! V_229 )
return 0 ;
for ( V_4 = 0 ; V_4 < V_227 ; V_4 ++ )
V_229 [ V_4 ] = V_2 -> V_177 . V_178 [ V_4 ] ;
if ( V_230 )
memcpy ( V_230 , V_2 -> V_177 . V_228 ,
F_55 ( V_21 ) ) ;
return 0 ;
}
static int F_57 ( struct V_20 * V_21 , const T_2 * V_229 ,
const T_1 * V_230 , const T_1 V_231 )
{
struct V_208 V_209 ;
struct V_1 * V_2 = F_5 ( V_21 ) ;
int V_4 ;
if ( V_2 -> V_39 . V_40 . V_41 > 1 ) {
F_22 ( V_2 ,
L_38 ) ;
return - V_69 ;
}
if ( V_231 != V_233 && V_231 != V_232 )
return - V_69 ;
if ( ! V_229 && ! V_230 )
return 0 ;
if ( V_229 ) {
for ( V_4 = 0 ; V_4 < V_227 ; V_4 ++ )
V_2 -> V_177 . V_178 [ V_4 ] = V_229 [ V_4 ] ;
V_2 -> V_175 |= V_176 ;
}
if ( V_230 ) {
memcpy ( & V_2 -> V_177 . V_228 , V_230 ,
F_55 ( V_21 ) ) ;
V_2 -> V_175 |= V_234 ;
}
if ( F_31 ( V_2 -> V_88 ) ) {
memset ( & V_209 , 0 , sizeof( V_209 ) ) ;
V_209 . V_223 = 1 ;
V_209 . V_224 = 0 ;
memcpy ( & V_209 . V_177 , & V_2 -> V_177 ,
sizeof( V_209 . V_177 ) ) ;
return V_2 -> V_49 -> V_225 ( V_2 -> V_51 ,
& V_209 ) ;
}
return 0 ;
}
static void F_58 ( struct V_1 * V_2 )
{
int V_4 ;
if ( ! F_31 ( V_2 -> V_88 ) )
return;
F_35 (i) {
F_59 ( V_2 -> V_8 [ V_4 ] . V_121 , V_235 , 1 ) ;
F_60 ( & V_2 -> V_8 [ V_4 ] . V_236 ) ;
}
}
static void F_61 ( struct V_1 * V_2 )
{
int V_4 ;
F_35 (i) {
F_62 ( & V_2 -> V_8 [ V_4 ] . V_236 ) ;
F_59 ( V_2 -> V_8 [ V_4 ] . V_121 , V_237 , 0 ) ;
}
}
static int F_63 ( struct V_1 * V_2 ,
struct V_238 * V_239 )
{
struct V_240 * V_241 = NULL ;
struct V_242 * V_243 ;
T_6 V_244 ;
int V_4 , V_245 , V_246 ;
F_35 (i) {
if ( V_2 -> V_8 [ V_4 ] . type & V_13 ) {
V_241 = V_2 -> V_8 [ V_4 ] . V_247 ;
break;
}
}
if ( ! V_241 ) {
F_64 ( V_2 , L_39 ) ;
return - 1 ;
}
V_245 = V_241 -> V_248 & V_131 ;
V_241 -> V_249 [ V_245 ] . V_239 = V_239 ;
V_243 = F_65 ( & V_241 -> V_250 ) ;
memset ( V_243 , 0 , sizeof( * V_243 ) ) ;
V_246 = 1 << V_251 ;
V_243 -> V_190 . V_252 . V_253 = V_246 ;
V_246 = V_239 -> V_151 & V_254 ;
V_243 -> V_190 . V_253 |= ( V_246 << V_255 ) ;
V_244 = F_66 ( & V_2 -> V_104 -> V_21 , V_239 -> V_190 ,
F_67 ( V_239 ) , V_256 ) ;
if ( F_68 ( F_69 ( & V_2 -> V_104 -> V_21 , V_244 ) ) ) {
F_64 ( V_2 , L_40 ) ;
return - V_257 ;
}
F_70 ( V_243 , V_244 , F_67 ( V_239 ) ) ;
V_243 -> V_190 . V_258 = 1 ;
V_241 -> V_248 ++ ;
V_246 = F_71 ( F_72 ( & V_241 -> V_250 ) ) ;
V_241 -> V_259 . V_190 . V_260 = V_246 ;
F_73 () ;
F_74 () ;
F_75 ( V_241 -> V_259 . V_261 , V_241 -> V_262 ) ;
F_76 () ;
for ( V_4 = 0 ; V_4 < V_263 ; V_4 ++ ) {
if ( F_77 ( V_241 ) )
break;
F_78 ( 100 , 200 ) ;
}
if ( ! F_77 ( V_241 ) ) {
F_64 ( V_2 , L_41 ) ;
return - 1 ;
}
V_243 = (struct V_242 * ) F_79 ( & V_241 -> V_250 ) ;
F_80 ( & V_2 -> V_104 -> V_21 , F_81 ( V_243 ) ,
F_82 ( V_243 ) , V_256 ) ;
V_241 -> V_264 ++ ;
V_241 -> V_249 [ V_245 ] . V_239 = NULL ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 )
{
T_4 V_265 , V_266 , V_267 , V_151 ;
struct V_268 * V_269 ;
struct V_270 * V_271 = NULL ;
struct V_272 * V_272 ;
union V_273 * V_274 ;
int V_4 , V_118 = 0 ;
T_1 * V_275 ;
F_35 (i) {
if ( V_2 -> V_8 [ V_4 ] . type & V_9 ) {
V_271 = V_2 -> V_8 [ V_4 ] . V_271 ;
break;
}
}
if ( ! V_271 ) {
F_64 ( V_2 , L_42 ) ;
return - 1 ;
}
for ( V_4 = 0 ; V_4 < V_263 ; V_4 ++ ) {
if ( ! F_84 ( V_271 ) ) {
F_78 ( 100 , 200 ) ;
continue;
}
V_265 = F_85 ( * V_271 -> V_276 ) ;
V_266 = F_86 ( & V_271 -> V_277 ) ;
F_87 () ;
V_274 = (union V_273 * ) F_79 ( & V_271 -> V_277 ) ;
V_267 = V_271 -> V_278 & V_127 ;
V_272 = & V_271 -> V_279 [ V_267 ] ;
V_269 = & V_274 -> V_280 ;
V_151 = F_85 ( V_269 -> V_281 ) ;
V_275 = ( T_1 * ) ( F_88 ( V_272 -> V_190 ) +
V_269 -> V_282 +
V_272 -> V_283 ) ;
if ( F_89 ( V_275 , V_2 -> V_88 -> V_284 ) &&
F_89 ( V_275 + V_285 ,
V_2 -> V_88 -> V_284 ) ) {
for ( V_4 = V_158 ; V_4 < V_151 ; V_4 ++ )
if ( V_275 [ V_4 ] != ( unsigned char ) ( V_4 & 0xff ) ) {
V_118 = - 1 ;
break;
}
F_90 ( V_271 , V_2 , 1 ) ;
F_91 ( & V_271 -> V_277 ) ;
break;
}
F_22 ( V_2 , L_43 ) ;
F_90 ( V_271 , V_2 , 1 ) ;
F_91 ( & V_271 -> V_277 ) ;
}
if ( V_4 == V_263 ) {
F_64 ( V_2 , L_44 ) ;
return - 1 ;
}
F_92 ( V_2 , V_271 ) ;
return V_118 ;
}
static int F_93 ( struct V_1 * V_2 , T_2 V_286 )
{
struct V_66 V_110 ;
struct V_238 * V_239 = NULL ;
int V_118 = 0 , V_4 ;
T_2 V_287 ;
T_1 * V_288 ;
if ( ! F_31 ( V_2 -> V_88 ) ) {
F_64 ( V_2 , L_16 ) ;
return - V_38 ;
}
F_61 ( V_2 ) ;
memset ( & V_110 , 0 , sizeof( V_110 ) ) ;
V_110 . V_57 = true ;
V_110 . V_70 = V_289 ;
V_110 . V_286 = V_286 ;
V_2 -> V_49 -> V_40 -> V_87 ( V_2 -> V_51 , & V_110 ) ;
F_94 ( 500 ) ;
V_287 = V_2 -> V_88 -> V_155 + V_158 ;
V_239 = F_95 ( V_2 -> V_88 , V_287 ) ;
if ( ! V_239 ) {
F_22 ( V_2 , L_45 ) ;
V_118 = - V_257 ;
goto V_290;
}
V_288 = F_96 ( V_239 , V_287 ) ;
F_97 ( V_288 , V_2 -> V_88 -> V_284 ) ;
F_97 ( V_288 + V_285 , V_2 -> V_88 -> V_284 ) ;
memset ( V_288 + ( 2 * V_285 ) , 0x77 , ( V_158 - ( 2 * V_285 ) ) ) ;
for ( V_4 = V_158 ; V_4 < V_287 ; V_4 ++ )
V_288 [ V_4 ] = ( unsigned char ) ( V_4 & 0xff ) ;
V_118 = F_63 ( V_2 , V_239 ) ;
if ( V_118 )
goto V_290;
V_118 = F_83 ( V_2 ) ;
if ( V_118 )
goto V_290;
F_6 ( V_2 , V_291 , L_46 ) ;
V_290:
F_98 ( V_239 ) ;
memset ( & V_110 , 0 , sizeof( V_110 ) ) ;
V_110 . V_57 = true ;
V_110 . V_70 = V_289 ;
V_110 . V_286 = V_292 ;
V_2 -> V_49 -> V_40 -> V_87 ( V_2 -> V_51 , & V_110 ) ;
F_94 ( 500 ) ;
F_58 ( V_2 ) ;
return V_118 ;
}
static void F_99 ( struct V_20 * V_21 ,
struct V_293 * V_294 , T_3 * V_3 )
{
struct V_1 * V_2 = F_5 ( V_21 ) ;
F_6 ( V_2 , V_30 ,
L_47 ,
( V_294 -> V_295 & V_296 ) ,
( V_294 -> V_295 & V_297 ) >> 2 ) ;
memset ( V_3 , 0 , sizeof( T_3 ) * V_29 ) ;
if ( V_294 -> V_295 & V_296 ) {
if ( F_93 ( V_2 ,
V_298 ) ) {
V_3 [ V_299 ] = 1 ;
V_294 -> V_295 |= V_300 ;
}
}
if ( V_2 -> V_49 -> V_40 -> V_301 -> V_302 ( V_2 -> V_51 ) ) {
V_3 [ V_303 ] = 1 ;
V_294 -> V_295 |= V_300 ;
}
if ( V_2 -> V_49 -> V_40 -> V_301 -> V_304 ( V_2 -> V_51 ) ) {
V_3 [ V_305 ] = 1 ;
V_294 -> V_295 |= V_300 ;
}
if ( V_2 -> V_49 -> V_40 -> V_301 -> V_306 ( V_2 -> V_51 ) ) {
V_3 [ V_307 ] = 1 ;
V_294 -> V_295 |= V_300 ;
}
if ( V_2 -> V_49 -> V_40 -> V_301 -> V_308 ( V_2 -> V_51 ) ) {
V_3 [ V_309 ] = 1 ;
V_294 -> V_295 |= V_300 ;
}
}
static int F_100 ( struct V_20 * V_21 ,
const struct V_310 * V_311 ,
const void * V_190 )
{
struct V_1 * V_2 = F_5 ( V_21 ) ;
T_2 V_246 ;
switch ( V_311 -> V_312 ) {
case V_313 :
V_246 = * ( T_2 * ) V_190 ;
if ( V_246 < V_314 || V_246 > V_315 ) {
F_6 ( V_2 , V_30 ,
L_48 ,
V_314 , V_315 ) ;
return - V_38 ;
}
V_2 -> V_316 = * ( T_2 * ) V_190 ;
break;
default:
return - V_69 ;
}
return 0 ;
}
static int F_101 ( struct V_20 * V_21 ,
const struct V_310 * V_311 , void * V_190 )
{
struct V_1 * V_2 = F_5 ( V_21 ) ;
switch ( V_311 -> V_312 ) {
case V_313 :
* ( T_2 * ) V_190 = V_2 -> V_316 ;
break;
default:
return - V_69 ;
}
return 0 ;
}
void F_102 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_5 ( V_21 ) ;
if ( F_3 ( V_2 ) )
V_21 -> V_317 = & V_318 ;
else
V_21 -> V_317 = & V_319 ;
}
