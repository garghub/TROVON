static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_4 -> V_7 = 0 ;
V_4 -> V_8 = V_9 ;
if ( V_6 -> V_10 <= 1000 ) {
V_4 -> V_11 = V_12 ;
V_4 -> V_13 = V_14 ;
} else {
V_4 -> V_11 = V_15 ;
V_4 -> V_13 = V_16 ;
}
V_4 -> V_17 = V_6 -> V_17 ;
F_3 ( V_4 , V_6 -> V_10 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_5 ( V_19 -> V_20 , V_21 , sizeof( V_19 -> V_20 ) ) ;
F_5 ( V_19 -> V_22 , V_23 , sizeof( V_19 -> V_22 ) ) ;
F_5 ( V_19 -> V_24 , F_6 ( V_6 -> V_25 ) , sizeof( V_19 -> V_24 ) ) ;
}
static T_1 F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_26 ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_27 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_26 = V_27 ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_28 , T_2 * V_29 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_30 , V_31 ;
if ( V_28 != V_32 )
return;
for ( V_30 = 0 ; V_30 < V_33 ; V_30 ++ ) {
memcpy ( V_29 , V_34 [ V_30 ] . V_35 , V_36 ) ;
V_29 += V_36 ;
}
for ( V_30 = 0 ; V_30 < V_37 ; V_30 ++ ) {
memcpy ( V_29 , V_38 [ V_30 ] . V_35 , V_36 ) ;
V_29 += V_36 ;
}
for ( V_31 = 0 ; V_31 < V_6 -> V_39 -> V_40 ; V_31 ++ ) {
for ( V_30 = 0 ; V_30 < V_41 ; V_30 ++ ) {
sprintf ( V_29 , L_1 , V_31 ,
V_42 [ V_30 ] . V_35 ) ;
V_29 += V_36 ;
}
}
for ( V_31 = 0 ; V_31 < V_6 -> V_39 -> V_43 ; V_31 ++ ) {
for ( V_30 = 0 ; V_30 < V_41 ; V_30 ++ ) {
sprintf ( V_29 , L_2 , V_31 ,
V_42 [ V_30 ] . V_35 ) ;
V_29 += V_36 ;
}
}
for ( V_30 = 0 ; V_30 < V_44 ; V_30 ++ ) {
sprintf ( V_29 , L_3 , V_30 ) ;
V_29 += V_36 ;
}
for ( V_30 = 0 ; V_30 < V_45 ; V_30 ++ ) {
sprintf ( V_29 , L_4 , V_30 ) ;
V_29 += V_36 ;
}
}
static int F_10 ( struct V_1 * V_2 , int V_28 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_28 != V_32 )
return - V_46 ;
return V_33 + V_37 +
( V_41 *
( V_6 -> V_39 -> V_40 + V_6 -> V_39 -> V_43 ) ) +
V_44 + V_45 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_47 * V_30 , T_3 * V_29 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_48 , V_31 ;
F_12 ( V_6 ) ;
F_13 ( V_6 ) ;
for ( V_48 = 0 ; V_48 < V_33 ; V_48 ++ )
* ( V_29 ++ ) = ( ( T_3 * ) & V_6 -> V_30 )
[ V_34 [ V_48 ] . V_49 ] ;
for ( V_48 = 0 ; V_48 < V_37 ; V_48 ++ )
* ( V_29 ++ ) = ( ( T_3 * ) & V_6 -> V_50 )
[ V_38 [ V_48 ] . V_49 ] ;
for ( V_31 = 0 ; V_31 < V_6 -> V_39 -> V_40 ; V_31 ++ ) {
for ( V_48 = 0 ; V_48 < V_41 ; V_48 ++ )
* ( V_29 ++ ) = ( ( T_3 * ) & V_6 -> V_39 -> V_51 [ V_31 ] . V_30 )
[ V_42 [ V_48 ] . V_49 ] ;
}
for ( V_31 = 0 ; V_31 < V_6 -> V_39 -> V_43 ; V_31 ++ ) {
for ( V_48 = 0 ; V_48 < V_41 ; V_48 ++ )
* ( V_29 ++ ) = ( ( T_3 * ) & V_6 -> V_39 -> V_52 [ V_31 ] . V_30 )
[ V_42 [ V_48 ] . V_49 ] ;
}
for ( V_48 = 0 ; V_48 < V_44 ; V_48 ++ )
* ( V_29 ++ ) = V_6 -> V_53 . V_54 [ V_48 ] ;
for ( V_48 = 0 ; V_48 < V_45 ; V_48 ++ )
* ( V_29 ++ ) = V_6 -> V_53 . V_55 [ V_48 ] ;
}
static int F_14 ( struct V_1 * V_56 )
{
return sizeof( T_3 ) * V_57 ;
}
static void F_15 ( struct V_1 * V_56 ,
struct V_58 * V_59 , void * V_60 )
{
struct V_5 * V_6 = F_2 ( V_56 ) ;
T_3 * V_61 = ( T_3 * ) V_60 ;
T_3 V_62 ;
int V_63 , V_64 , V_48 , V_65 ;
int V_66 = 0 ;
V_59 -> V_22 = 0 ;
memset ( V_61 , 0 , V_57 ) ;
V_61 [ V_66 ++ ] = F_16 ( V_6 , V_67 ) ;
for ( V_63 = 0 ; V_63 < V_68 ; V_63 ++ )
V_61 [ V_66 ++ ] = F_16 ( V_6 ,
V_69 | ( V_63 << 3 ) ) ;
V_61 [ V_66 ++ ] = F_16 ( V_6 , V_70 ) ;
V_61 [ V_66 ++ ] = F_16 ( V_6 , V_71 ) ;
V_61 [ V_66 ++ ] = F_16 ( V_6 , V_72 ) ;
V_61 [ V_66 ++ ] = F_16 ( V_6 , V_73 ) ;
V_61 [ V_66 ++ ] = F_16 ( V_6 , V_74 ) ;
for ( V_64 = 0 ; V_64 < V_75 ; V_64 ++ )
V_61 [ V_66 ++ ] = F_16 ( V_6 , V_76 | ( V_64 << 3 ) ) ;
for ( V_48 = 0 ; V_48 < V_77 ; V_48 ++ )
V_61 [ V_66 ++ ] = F_16 ( V_6 ,
V_78 | ( V_48 << 3 ) ) ;
for ( V_66 = 0 ; V_66 < V_79 ; V_66 ++ )
V_61 [ V_66 ++ ] = F_16 ( V_6 ,
V_80 | ( V_48 << 3 ) ) ;
V_61 [ V_66 ++ ] = F_16 ( V_6 , V_81 ) ;
for ( V_65 = 0 ; V_65 < V_82 ; V_65 ++ ) {
V_61 [ V_66 ++ ] = F_17 ( V_6 , V_83 , V_65 ) ;
V_61 [ V_66 ++ ] = F_17 ( V_6 , V_84 , V_65 ) ;
V_61 [ V_66 ++ ] = F_17 ( V_6 , V_85 , V_65 ) ;
V_61 [ V_66 ++ ] = F_17 ( V_6 , V_86 , V_65 ) ;
V_61 [ V_66 ++ ] = F_17 ( V_6 , V_87 , V_65 ) ;
V_61 [ V_66 ++ ] = F_17 ( V_6 , V_88 , V_65 ) ;
V_61 [ V_66 ++ ] = F_17 ( V_6 , V_89 , V_65 ) ;
V_61 [ V_66 ++ ] = F_17 ( V_6 , V_90 , V_65 ) ;
V_61 [ V_66 ++ ] = F_17 ( V_6 , V_91 , V_65 ) ;
V_61 [ V_66 ++ ] = F_17 ( V_6 , V_92 , V_65 ) ;
}
for ( V_65 = 0 ; V_65 < V_93 ; V_65 ++ ) {
V_61 [ V_66 ++ ] = F_17 ( V_6 , V_94 , V_65 ) ;
V_61 [ V_66 ++ ] = F_17 ( V_6 ,
V_95 , V_65 ) ;
V_62 = V_95 | ( 1 << 3 ) ;
V_61 [ V_66 ++ ] = F_17 ( V_6 , V_62 , V_65 ) ;
}
for ( V_65 = 0 ; V_65 < V_96 ; V_65 ++ ) {
V_61 [ V_66 ++ ] = F_17 ( V_6 , V_97 , V_65 ) ;
V_61 [ V_66 ++ ] = F_17 ( V_6 , V_98 , V_65 ) ;
V_61 [ V_66 ++ ] = F_17 ( V_6 , V_99 , V_65 ) ;
V_61 [ V_66 ++ ] = F_17 ( V_6 , V_100 , V_65 ) ;
V_61 [ V_66 ++ ] = F_17 ( V_6 , V_101 , V_65 ) ;
V_61 [ V_66 ++ ] = F_17 ( V_6 , V_102 , V_65 ) ;
V_61 [ V_66 ++ ] = F_17 ( V_6 , V_103 , V_65 ) ;
V_61 [ V_66 ++ ] = F_17 ( V_6 , V_104 , V_65 ) ;
V_61 [ V_66 ++ ] = F_17 ( V_6 , V_105 , V_65 ) ;
V_61 [ V_66 ++ ] = F_17 ( V_6 , V_106 , V_65 ) ;
V_62 = V_106 | ( 1 << 3 ) ;
V_61 [ V_66 ++ ] = F_17 ( V_6 , V_62 , V_65 ) ;
}
for ( V_65 = 0 ; V_65 < V_107 ; V_65 ++ ) {
V_61 [ V_66 ++ ] = F_17 ( V_6 , V_108 , V_65 ) ;
V_61 [ V_66 ++ ] = F_17 ( V_6 , V_109 , V_65 ) ;
V_61 [ V_66 ++ ] = F_17 ( V_6 , V_110 , V_65 ) ;
V_61 [ V_66 ++ ] = F_17 ( V_6 , V_111 , V_65 ) ;
V_61 [ V_66 ++ ] = F_17 ( V_6 , V_112 , V_65 ) ;
V_61 [ V_66 ++ ] = F_17 ( V_6 , V_113 , V_65 ) ;
V_61 [ V_66 ++ ] = F_17 ( V_6 ,
V_114 , V_65 ) ;
V_61 [ V_66 ++ ] = F_17 ( V_6 ,
V_115 , V_65 ) ;
V_62 = V_116 ;
V_61 [ V_66 ++ ] = F_17 ( V_6 , V_62 , V_65 ) ;
}
}
static int F_18 ( struct V_1 * V_2 ,
struct V_117 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_4 -> V_118 = V_6 -> V_119 ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_120 * V_121 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_122 * V_39 = V_6 -> V_39 ;
V_121 -> V_123 = V_124 ;
V_121 -> V_125 = V_39 -> V_126 ;
V_121 -> V_127 = V_128 ;
V_121 -> V_129 = V_39 -> V_130 ;
}
static int F_20 ( struct V_5 * V_6 ,
struct V_131 * V_19 )
{
V_19 -> V_29 = 0 ;
switch ( V_19 -> V_132 ) {
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
V_19 -> V_29 |= V_139 | V_140 ;
case V_141 :
case V_142 :
V_19 -> V_29 |= V_143 | V_144 ;
break;
default:
return - V_46 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_56 ,
struct V_131 * V_19 , T_1 * V_145 )
{
struct V_5 * V_6 = F_2 ( V_56 ) ;
int V_146 = - V_147 ;
switch ( V_19 -> V_4 ) {
case V_148 :
V_19 -> V_29 = V_6 -> V_39 -> V_40 ;
V_146 = 0 ;
break;
case V_149 :
return F_20 ( V_6 , V_19 ) ;
default:
break;
}
return V_146 ;
}
static int F_22 ( struct V_5 * V_6 ,
struct V_131 * V_19 )
{
struct V_150 * V_151 = & V_6 -> V_152 ;
T_3 V_153 = F_16 ( V_6 , V_74 ) ;
if ( ! V_151 -> V_154 )
F_23 ( V_6 -> V_2 ,
L_5 ) ;
F_24 ( V_6 -> V_2 , L_6 ,
V_19 -> V_132 , V_19 -> V_29 ) ;
if ( ! ( V_19 -> V_29 & V_143 ) || ! ( V_19 -> V_29 & V_144 ) )
return - V_46 ;
switch ( V_19 -> V_132 ) {
case V_133 :
case V_134 :
switch ( V_19 -> V_29 & ( V_139 | V_140 ) ) {
case 0 :
V_153 &= ~ ( 1ULL << V_155 ) ;
break;
case ( V_139 | V_140 ) :
V_153 |= ( 1ULL << V_155 ) ;
break;
default:
return - V_46 ;
}
break;
case V_135 :
case V_136 :
switch ( V_19 -> V_29 & ( V_139 | V_140 ) ) {
case 0 :
V_153 &= ~ ( 1ULL << V_156 ) ;
break;
case ( V_139 | V_140 ) :
V_153 |= ( 1ULL << V_156 ) ;
break;
default:
return - V_46 ;
}
break;
case V_137 :
case V_138 :
switch ( V_19 -> V_29 & ( V_139 | V_140 ) ) {
case 0 :
V_153 &= ~ ( 1ULL << V_157 ) ;
break;
case ( V_139 | V_140 ) :
V_153 |= ( 1ULL << V_157 ) ;
break;
default:
return - V_46 ;
}
break;
case V_141 :
case V_142 :
V_153 = V_158 ;
break;
default:
return - V_46 ;
}
F_25 ( V_6 , V_74 , V_153 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_56 , struct V_131 * V_19 )
{
struct V_5 * V_6 = F_2 ( V_56 ) ;
switch ( V_19 -> V_4 ) {
case V_159 :
return F_22 ( V_6 , V_19 ) ;
default:
break;
}
return - V_147 ;
}
static T_1 F_27 ( struct V_1 * V_2 )
{
return V_75 * sizeof( T_3 ) ;
}
static T_1 F_28 ( struct V_1 * V_56 )
{
struct V_5 * V_6 = F_2 ( V_56 ) ;
return V_6 -> V_152 . V_160 ;
}
static int F_29 ( struct V_1 * V_56 , T_1 * V_161 , T_2 * V_162 ,
T_2 * V_163 )
{
struct V_5 * V_6 = F_2 ( V_56 ) ;
struct V_150 * V_151 = & V_6 -> V_152 ;
int V_164 ;
if ( V_161 ) {
for ( V_164 = 0 ; V_164 < V_151 -> V_160 ; V_164 ++ )
V_161 [ V_164 ] = V_151 -> V_165 [ V_164 ] ;
}
if ( V_162 )
memcpy ( V_162 , V_151 -> V_64 , V_75 * sizeof( T_3 ) ) ;
if ( V_163 )
* V_163 = V_166 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_56 , const T_1 * V_161 ,
const T_2 * V_162 , T_2 V_163 )
{
struct V_5 * V_6 = F_2 ( V_56 ) ;
struct V_150 * V_151 = & V_6 -> V_152 ;
int V_164 ;
if ( ( V_6 -> V_39 -> V_40 <= 1 ) || ( V_6 -> V_167 != V_168 ) ) {
V_151 -> V_154 = false ;
V_151 -> V_169 = 0 ;
return - V_170 ;
}
if ( V_163 != V_171 && V_163 != V_166 )
return - V_147 ;
V_151 -> V_154 = true ;
if ( V_161 ) {
for ( V_164 = 0 ; V_164 < V_151 -> V_160 ; V_164 ++ )
V_151 -> V_165 [ V_164 ] = V_161 [ V_164 ] ;
}
if ( V_162 ) {
memcpy ( V_151 -> V_64 , V_162 , V_75 * sizeof( T_3 ) ) ;
F_31 ( V_6 ) ;
}
F_32 ( V_6 ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_56 ,
struct V_172 * V_173 )
{
struct V_5 * V_6 = F_2 ( V_56 ) ;
memset ( V_173 , 0 , sizeof( * V_173 ) ) ;
V_173 -> V_174 = V_93 ;
V_173 -> V_175 = V_96 ;
V_173 -> V_176 = V_6 -> V_39 -> V_40 ;
V_173 -> V_177 = V_6 -> V_39 -> V_43 ;
}
static int F_34 ( struct V_1 * V_56 ,
struct V_172 * V_173 )
{
struct V_5 * V_6 = F_2 ( V_56 ) ;
int V_178 = 0 ;
bool V_179 = F_35 ( V_56 ) ;
if ( ! V_173 -> V_176 || ! V_173 -> V_177 )
return - V_46 ;
if ( V_173 -> V_176 > V_93 )
return - V_46 ;
if ( V_173 -> V_177 > V_96 )
return - V_46 ;
if ( V_179 )
F_36 ( V_56 ) ;
V_6 -> V_39 -> V_40 = V_173 -> V_176 ;
V_6 -> V_39 -> V_43 = V_173 -> V_177 ;
V_6 -> V_39 -> V_180 = F_37 ( V_6 -> V_39 -> V_40 , V_6 -> V_39 -> V_43 ) ;
V_178 = F_38 ( V_56 , V_6 -> V_39 -> V_43 , V_6 -> V_39 -> V_40 ) ;
if ( V_178 )
return V_178 ;
if ( V_179 )
F_39 ( V_56 ) ;
F_24 ( V_56 , L_7 ,
V_6 -> V_39 -> V_43 , V_6 -> V_39 -> V_40 ) ;
return V_178 ;
}
void F_40 ( struct V_1 * V_2 )
{
V_2 -> V_181 = & V_182 ;
}
