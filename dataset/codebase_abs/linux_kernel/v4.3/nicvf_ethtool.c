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
static void F_9 ( struct V_5 * V_6 , T_2 * * V_28 , int V_29 )
{
int V_30 , V_31 ;
int V_32 = V_29 * V_33 ;
for ( V_31 = 0 ; V_31 < V_6 -> V_34 -> V_35 ; V_31 ++ ) {
for ( V_30 = 0 ; V_30 < V_36 ; V_30 ++ ) {
sprintf ( * V_28 , L_1 , V_31 + V_32 ,
V_37 [ V_30 ] . V_38 ) ;
* V_28 += V_39 ;
}
}
for ( V_31 = 0 ; V_31 < V_6 -> V_34 -> V_40 ; V_31 ++ ) {
for ( V_30 = 0 ; V_30 < V_36 ; V_30 ++ ) {
sprintf ( * V_28 , L_2 , V_31 + V_32 ,
V_37 [ V_30 ] . V_38 ) ;
* V_28 += V_39 ;
}
}
}
static void F_10 ( struct V_1 * V_2 , T_1 V_41 , T_2 * V_28 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_30 ;
int V_42 ;
if ( V_41 != V_43 )
return;
for ( V_30 = 0 ; V_30 < V_44 ; V_30 ++ ) {
memcpy ( V_28 , V_45 [ V_30 ] . V_38 , V_39 ) ;
V_28 += V_39 ;
}
for ( V_30 = 0 ; V_30 < V_46 ; V_30 ++ ) {
memcpy ( V_28 , V_47 [ V_30 ] . V_38 , V_39 ) ;
V_28 += V_39 ;
}
F_9 ( V_6 , & V_28 , 0 ) ;
for ( V_42 = 0 ; V_42 < V_6 -> V_48 ; V_42 ++ ) {
if ( ! V_6 -> V_49 [ V_42 ] )
continue;
F_9 ( V_6 -> V_49 [ V_42 ] , & V_28 , V_42 + 1 ) ;
}
for ( V_30 = 0 ; V_30 < V_50 ; V_30 ++ ) {
sprintf ( V_28 , L_3 , V_30 ) ;
V_28 += V_39 ;
}
for ( V_30 = 0 ; V_30 < V_51 ; V_30 ++ ) {
sprintf ( V_28 , L_4 , V_30 ) ;
V_28 += V_39 ;
}
}
static int F_11 ( struct V_1 * V_2 , int V_41 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_52 ;
int V_42 ;
if ( V_41 != V_43 )
return - V_53 ;
V_52 = V_36 *
( V_6 -> V_34 -> V_35 + V_6 -> V_34 -> V_40 ) ;
for ( V_42 = 0 ; V_42 < V_6 -> V_48 ; V_42 ++ ) {
struct V_5 * V_54 ;
V_54 = V_6 -> V_49 [ V_42 ] ;
if ( ! V_54 )
continue;
V_52 += V_36 *
( V_54 -> V_34 -> V_35 + V_54 -> V_34 -> V_40 ) ;
}
return V_44 + V_46 +
V_52 +
V_50 + V_51 ;
}
static void F_12 ( struct V_5 * V_6 ,
struct V_55 * V_30 , T_3 * * V_28 )
{
int V_56 , V_31 ;
if ( ! V_6 )
return;
for ( V_31 = 0 ; V_31 < V_6 -> V_34 -> V_35 ; V_31 ++ ) {
F_13 ( V_6 , V_31 ) ;
for ( V_56 = 0 ; V_56 < V_36 ; V_56 ++ )
* ( ( * V_28 ) ++ ) = ( ( T_3 * ) & V_6 -> V_34 -> V_57 [ V_31 ] . V_30 )
[ V_37 [ V_56 ] . V_58 ] ;
}
for ( V_31 = 0 ; V_31 < V_6 -> V_34 -> V_40 ; V_31 ++ ) {
F_14 ( V_6 , V_31 ) ;
for ( V_56 = 0 ; V_56 < V_36 ; V_56 ++ )
* ( ( * V_28 ) ++ ) = ( ( T_3 * ) & V_6 -> V_34 -> V_59 [ V_31 ] . V_30 )
[ V_37 [ V_56 ] . V_58 ] ;
}
}
static void F_15 ( struct V_1 * V_2 ,
struct V_55 * V_30 , T_3 * V_28 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_56 ;
int V_42 ;
F_16 ( V_6 ) ;
F_17 ( V_6 ) ;
for ( V_56 = 0 ; V_56 < V_44 ; V_56 ++ )
* ( V_28 ++ ) = ( ( T_3 * ) & V_6 -> V_60 )
[ V_45 [ V_56 ] . V_58 ] ;
for ( V_56 = 0 ; V_56 < V_46 ; V_56 ++ )
* ( V_28 ++ ) = ( ( T_3 * ) & V_6 -> V_61 )
[ V_47 [ V_56 ] . V_58 ] ;
F_12 ( V_6 , V_30 , & V_28 ) ;
for ( V_42 = 0 ; V_42 < V_6 -> V_48 ; V_42 ++ ) {
if ( ! V_6 -> V_49 [ V_42 ] )
continue;
F_12 ( V_6 -> V_49 [ V_42 ] , V_30 , & V_28 ) ;
}
for ( V_56 = 0 ; V_56 < V_50 ; V_56 ++ )
* ( V_28 ++ ) = V_6 -> V_62 . V_63 [ V_56 ] ;
for ( V_56 = 0 ; V_56 < V_51 ; V_56 ++ )
* ( V_28 ++ ) = V_6 -> V_62 . V_64 [ V_56 ] ;
}
static int F_18 ( struct V_1 * V_65 )
{
return sizeof( T_3 ) * V_66 ;
}
static void F_19 ( struct V_1 * V_65 ,
struct V_67 * V_68 , void * V_69 )
{
struct V_5 * V_6 = F_2 ( V_65 ) ;
T_3 * V_70 = ( T_3 * ) V_69 ;
T_3 V_71 ;
int V_72 , V_73 , V_56 , V_74 ;
int V_75 = 0 ;
V_68 -> V_22 = 0 ;
memset ( V_70 , 0 , V_66 ) ;
V_70 [ V_75 ++ ] = F_20 ( V_6 , V_76 ) ;
for ( V_72 = 0 ; V_72 < V_77 ; V_72 ++ )
V_70 [ V_75 ++ ] = F_20 ( V_6 ,
V_78 | ( V_72 << 3 ) ) ;
V_70 [ V_75 ++ ] = F_20 ( V_6 , V_79 ) ;
V_70 [ V_75 ++ ] = F_20 ( V_6 , V_80 ) ;
V_70 [ V_75 ++ ] = F_20 ( V_6 , V_81 ) ;
V_70 [ V_75 ++ ] = F_20 ( V_6 , V_82 ) ;
V_70 [ V_75 ++ ] = F_20 ( V_6 , V_83 ) ;
for ( V_73 = 0 ; V_73 < V_84 ; V_73 ++ )
V_70 [ V_75 ++ ] = F_20 ( V_6 , V_85 | ( V_73 << 3 ) ) ;
for ( V_56 = 0 ; V_56 < V_86 ; V_56 ++ )
V_70 [ V_75 ++ ] = F_20 ( V_6 ,
V_87 | ( V_56 << 3 ) ) ;
for ( V_75 = 0 ; V_75 < V_88 ; V_75 ++ )
V_70 [ V_75 ++ ] = F_20 ( V_6 ,
V_89 | ( V_56 << 3 ) ) ;
V_70 [ V_75 ++ ] = F_20 ( V_6 , V_90 ) ;
for ( V_74 = 0 ; V_74 < V_91 ; V_74 ++ ) {
V_70 [ V_75 ++ ] = F_21 ( V_6 , V_92 , V_74 ) ;
V_70 [ V_75 ++ ] = F_21 ( V_6 , V_93 , V_74 ) ;
V_70 [ V_75 ++ ] = F_21 ( V_6 , V_94 , V_74 ) ;
V_70 [ V_75 ++ ] = F_21 ( V_6 , V_95 , V_74 ) ;
V_70 [ V_75 ++ ] = F_21 ( V_6 , V_96 , V_74 ) ;
V_70 [ V_75 ++ ] = F_21 ( V_6 , V_97 , V_74 ) ;
V_70 [ V_75 ++ ] = F_21 ( V_6 , V_98 , V_74 ) ;
V_70 [ V_75 ++ ] = F_21 ( V_6 , V_99 , V_74 ) ;
V_70 [ V_75 ++ ] = F_21 ( V_6 , V_100 , V_74 ) ;
V_70 [ V_75 ++ ] = F_21 ( V_6 , V_101 , V_74 ) ;
}
for ( V_74 = 0 ; V_74 < V_33 ; V_74 ++ ) {
V_70 [ V_75 ++ ] = F_21 ( V_6 , V_102 , V_74 ) ;
V_70 [ V_75 ++ ] = F_21 ( V_6 ,
V_103 , V_74 ) ;
V_71 = V_103 | ( 1 << 3 ) ;
V_70 [ V_75 ++ ] = F_21 ( V_6 , V_71 , V_74 ) ;
}
for ( V_74 = 0 ; V_74 < V_104 ; V_74 ++ ) {
V_70 [ V_75 ++ ] = F_21 ( V_6 , V_105 , V_74 ) ;
V_70 [ V_75 ++ ] = F_21 ( V_6 , V_106 , V_74 ) ;
V_70 [ V_75 ++ ] = F_21 ( V_6 , V_107 , V_74 ) ;
V_70 [ V_75 ++ ] = F_21 ( V_6 , V_108 , V_74 ) ;
V_70 [ V_75 ++ ] = F_21 ( V_6 , V_109 , V_74 ) ;
V_70 [ V_75 ++ ] = F_21 ( V_6 , V_110 , V_74 ) ;
V_70 [ V_75 ++ ] = F_21 ( V_6 , V_111 , V_74 ) ;
V_70 [ V_75 ++ ] = F_21 ( V_6 , V_112 , V_74 ) ;
V_70 [ V_75 ++ ] = F_21 ( V_6 , V_113 , V_74 ) ;
V_70 [ V_75 ++ ] = F_21 ( V_6 , V_114 , V_74 ) ;
V_71 = V_114 | ( 1 << 3 ) ;
V_70 [ V_75 ++ ] = F_21 ( V_6 , V_71 , V_74 ) ;
}
for ( V_74 = 0 ; V_74 < V_115 ; V_74 ++ ) {
V_70 [ V_75 ++ ] = F_21 ( V_6 , V_116 , V_74 ) ;
V_70 [ V_75 ++ ] = F_21 ( V_6 , V_117 , V_74 ) ;
V_70 [ V_75 ++ ] = F_21 ( V_6 , V_118 , V_74 ) ;
V_70 [ V_75 ++ ] = F_21 ( V_6 , V_119 , V_74 ) ;
V_70 [ V_75 ++ ] = F_21 ( V_6 , V_120 , V_74 ) ;
V_70 [ V_75 ++ ] = F_21 ( V_6 , V_121 , V_74 ) ;
V_70 [ V_75 ++ ] = F_21 ( V_6 ,
V_122 , V_74 ) ;
V_70 [ V_75 ++ ] = F_21 ( V_6 ,
V_123 , V_74 ) ;
V_71 = V_124 ;
V_70 [ V_75 ++ ] = F_21 ( V_6 , V_71 , V_74 ) ;
}
}
static int F_22 ( struct V_1 * V_2 ,
struct V_125 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_4 -> V_126 = V_6 -> V_127 ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_128 * V_129 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_130 * V_34 = V_6 -> V_34 ;
V_129 -> V_131 = V_132 ;
V_129 -> V_133 = V_34 -> V_134 ;
V_129 -> V_135 = V_136 ;
V_129 -> V_137 = V_34 -> V_138 ;
}
static int F_24 ( struct V_5 * V_6 ,
struct V_139 * V_19 )
{
V_19 -> V_28 = 0 ;
switch ( V_19 -> V_140 ) {
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
V_19 -> V_28 |= V_147 | V_148 ;
case V_149 :
case V_150 :
V_19 -> V_28 |= V_151 | V_152 ;
break;
default:
return - V_53 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_65 ,
struct V_139 * V_19 , T_1 * V_153 )
{
struct V_5 * V_6 = F_2 ( V_65 ) ;
int V_154 = - V_155 ;
switch ( V_19 -> V_4 ) {
case V_156 :
V_19 -> V_28 = V_6 -> V_157 ;
V_154 = 0 ;
break;
case V_158 :
return F_24 ( V_6 , V_19 ) ;
default:
break;
}
return V_154 ;
}
static int F_26 ( struct V_5 * V_6 ,
struct V_139 * V_19 )
{
struct V_159 * V_160 = & V_6 -> V_161 ;
T_3 V_162 = F_20 ( V_6 , V_83 ) ;
if ( ! V_160 -> V_163 )
F_27 ( V_6 -> V_2 ,
L_5 ) ;
F_28 ( V_6 -> V_2 , L_6 ,
V_19 -> V_140 , V_19 -> V_28 ) ;
if ( ! ( V_19 -> V_28 & V_151 ) || ! ( V_19 -> V_28 & V_152 ) )
return - V_53 ;
switch ( V_19 -> V_140 ) {
case V_141 :
case V_142 :
switch ( V_19 -> V_28 & ( V_147 | V_148 ) ) {
case 0 :
V_162 &= ~ ( 1ULL << V_164 ) ;
break;
case ( V_147 | V_148 ) :
V_162 |= ( 1ULL << V_164 ) ;
break;
default:
return - V_53 ;
}
break;
case V_143 :
case V_144 :
switch ( V_19 -> V_28 & ( V_147 | V_148 ) ) {
case 0 :
V_162 &= ~ ( 1ULL << V_165 ) ;
break;
case ( V_147 | V_148 ) :
V_162 |= ( 1ULL << V_165 ) ;
break;
default:
return - V_53 ;
}
break;
case V_145 :
case V_146 :
switch ( V_19 -> V_28 & ( V_147 | V_148 ) ) {
case 0 :
V_162 &= ~ ( 1ULL << V_166 ) ;
break;
case ( V_147 | V_148 ) :
V_162 |= ( 1ULL << V_166 ) ;
break;
default:
return - V_53 ;
}
break;
case V_149 :
case V_150 :
V_162 = V_167 ;
break;
default:
return - V_53 ;
}
F_29 ( V_6 , V_83 , V_162 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_65 , struct V_139 * V_19 )
{
struct V_5 * V_6 = F_2 ( V_65 ) ;
switch ( V_19 -> V_4 ) {
case V_168 :
return F_26 ( V_6 , V_19 ) ;
default:
break;
}
return - V_155 ;
}
static T_1 F_31 ( struct V_1 * V_2 )
{
return V_84 * sizeof( T_3 ) ;
}
static T_1 F_32 ( struct V_1 * V_65 )
{
struct V_5 * V_6 = F_2 ( V_65 ) ;
return V_6 -> V_161 . V_169 ;
}
static int F_33 ( struct V_1 * V_65 , T_1 * V_170 , T_2 * V_171 ,
T_2 * V_172 )
{
struct V_5 * V_6 = F_2 ( V_65 ) ;
struct V_159 * V_160 = & V_6 -> V_161 ;
int V_173 ;
if ( V_170 ) {
for ( V_173 = 0 ; V_173 < V_160 -> V_169 ; V_173 ++ )
V_170 [ V_173 ] = V_160 -> V_174 [ V_173 ] ;
}
if ( V_171 )
memcpy ( V_171 , V_160 -> V_73 , V_84 * sizeof( T_3 ) ) ;
if ( V_172 )
* V_172 = V_175 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_65 , const T_1 * V_170 ,
const T_2 * V_171 , T_2 V_172 )
{
struct V_5 * V_6 = F_2 ( V_65 ) ;
struct V_159 * V_160 = & V_6 -> V_161 ;
int V_173 ;
if ( V_172 != V_176 && V_172 != V_175 )
return - V_155 ;
if ( ! V_160 -> V_163 ) {
F_27 ( V_6 -> V_2 ,
L_7 ) ;
return - V_177 ;
}
if ( V_170 ) {
for ( V_173 = 0 ; V_173 < V_160 -> V_169 ; V_173 ++ )
V_160 -> V_174 [ V_173 ] = V_170 [ V_173 ] ;
}
if ( V_171 ) {
memcpy ( V_160 -> V_73 , V_171 , V_84 * sizeof( T_3 ) ) ;
F_35 ( V_6 ) ;
}
F_36 ( V_6 ) ;
return 0 ;
}
static void F_37 ( struct V_1 * V_65 ,
struct V_178 * V_179 )
{
struct V_5 * V_6 = F_2 ( V_65 ) ;
memset ( V_179 , 0 , sizeof( * V_179 ) ) ;
V_179 -> V_180 = V_6 -> V_181 ;
V_179 -> V_182 = V_6 -> V_181 ;
V_179 -> V_183 = V_6 -> V_157 ;
V_179 -> V_184 = V_6 -> V_185 ;
}
static int F_38 ( struct V_1 * V_65 ,
struct V_178 * V_179 )
{
struct V_5 * V_6 = F_2 ( V_65 ) ;
int V_186 = 0 ;
bool V_187 = F_39 ( V_65 ) ;
int V_188 ;
if ( ! V_179 -> V_183 || ! V_179 -> V_184 )
return - V_53 ;
if ( V_179 -> V_183 > V_6 -> V_181 )
return - V_53 ;
if ( V_179 -> V_184 > V_6 -> V_181 )
return - V_53 ;
if ( V_187 )
F_40 ( V_65 ) ;
V_188 = F_41 ( V_179 -> V_183 , V_179 -> V_184 ) ;
if ( V_188 > V_91 ) {
V_6 -> V_48 = F_42 ( V_188 , V_91 ) ;
V_6 -> V_48 = ( V_6 -> V_48 / V_91 ) - 1 ;
} else {
V_6 -> V_48 = 0 ;
}
V_6 -> V_34 -> V_35 = F_43 ( T_1 , V_179 -> V_183 , V_33 ) ;
V_6 -> V_34 -> V_40 = F_43 ( T_1 , V_179 -> V_184 , V_104 ) ;
V_6 -> V_34 -> V_189 = F_41 ( V_6 -> V_34 -> V_35 , V_6 -> V_34 -> V_40 ) ;
V_6 -> V_157 = V_179 -> V_183 ;
V_6 -> V_185 = V_179 -> V_184 ;
V_186 = F_44 ( V_65 , V_6 -> V_185 , V_6 -> V_157 ) ;
if ( V_186 )
return V_186 ;
if ( V_187 )
F_45 ( V_65 ) ;
F_28 ( V_65 , L_8 ,
V_6 -> V_185 , V_6 -> V_157 ) ;
return V_186 ;
}
void F_46 ( struct V_1 * V_2 )
{
V_2 -> V_190 = & V_191 ;
}
