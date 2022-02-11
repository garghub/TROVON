static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_4 -> V_7 = 0 ;
V_4 -> V_8 = V_9 ;
if ( ! V_6 -> V_10 ) {
V_4 -> V_11 = V_12 ;
F_3 ( V_4 , V_13 ) ;
return 0 ;
}
if ( V_6 -> V_14 <= 1000 ) {
V_4 -> V_15 = V_16 ;
V_4 -> V_17 = V_18 ;
} else {
V_4 -> V_15 = V_19 ;
V_4 -> V_17 = V_20 ;
}
V_4 -> V_11 = V_6 -> V_11 ;
F_3 ( V_4 , V_6 -> V_14 ) ;
return 0 ;
}
static T_1 F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_10 ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_6 ( V_22 -> V_23 , V_24 , sizeof( V_22 -> V_23 ) ) ;
F_6 ( V_22 -> V_25 , V_26 , sizeof( V_22 -> V_25 ) ) ;
F_6 ( V_22 -> V_27 , F_7 ( V_6 -> V_28 ) , sizeof( V_22 -> V_27 ) ) ;
}
static T_1 F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_29 ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_30 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_29 = V_30 ;
}
static void F_10 ( struct V_5 * V_6 , T_2 * * V_31 , int V_32 )
{
int V_33 , V_34 ;
int V_35 = V_32 * V_36 ;
for ( V_34 = 0 ; V_34 < V_6 -> V_37 -> V_38 ; V_34 ++ ) {
for ( V_33 = 0 ; V_33 < V_39 ; V_33 ++ ) {
sprintf ( * V_31 , L_1 , V_34 + V_35 ,
V_40 [ V_33 ] . V_41 ) ;
* V_31 += V_42 ;
}
}
for ( V_34 = 0 ; V_34 < V_6 -> V_37 -> V_43 ; V_34 ++ ) {
for ( V_33 = 0 ; V_33 < V_39 ; V_33 ++ ) {
sprintf ( * V_31 , L_2 , V_34 + V_35 ,
V_40 [ V_33 ] . V_41 ) ;
* V_31 += V_42 ;
}
}
}
static void F_11 ( struct V_1 * V_2 , T_1 V_44 , T_2 * V_31 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_33 ;
int V_45 ;
if ( V_44 != V_46 )
return;
for ( V_33 = 0 ; V_33 < V_47 ; V_33 ++ ) {
memcpy ( V_31 , V_48 [ V_33 ] . V_41 , V_42 ) ;
V_31 += V_42 ;
}
for ( V_33 = 0 ; V_33 < V_49 ; V_33 ++ ) {
memcpy ( V_31 , V_50 [ V_33 ] . V_41 , V_42 ) ;
V_31 += V_42 ;
}
F_10 ( V_6 , & V_31 , 0 ) ;
for ( V_45 = 0 ; V_45 < V_6 -> V_51 ; V_45 ++ ) {
if ( ! V_6 -> V_52 [ V_45 ] )
continue;
F_10 ( V_6 -> V_52 [ V_45 ] , & V_31 , V_45 + 1 ) ;
}
for ( V_33 = 0 ; V_33 < V_53 ; V_33 ++ ) {
sprintf ( V_31 , L_3 , V_33 ) ;
V_31 += V_42 ;
}
for ( V_33 = 0 ; V_33 < V_54 ; V_33 ++ ) {
sprintf ( V_31 , L_4 , V_33 ) ;
V_31 += V_42 ;
}
}
static int F_12 ( struct V_1 * V_2 , int V_44 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_55 ;
int V_45 ;
if ( V_44 != V_46 )
return - V_56 ;
V_55 = V_39 *
( V_6 -> V_37 -> V_38 + V_6 -> V_37 -> V_43 ) ;
for ( V_45 = 0 ; V_45 < V_6 -> V_51 ; V_45 ++ ) {
struct V_5 * V_57 ;
V_57 = V_6 -> V_52 [ V_45 ] ;
if ( ! V_57 )
continue;
V_55 += V_39 *
( V_57 -> V_37 -> V_38 + V_57 -> V_37 -> V_43 ) ;
}
return V_47 + V_49 +
V_55 +
V_53 + V_54 ;
}
static void F_13 ( struct V_5 * V_6 ,
struct V_58 * V_33 , T_3 * * V_31 )
{
int V_59 , V_34 ;
if ( ! V_6 )
return;
for ( V_34 = 0 ; V_34 < V_6 -> V_37 -> V_38 ; V_34 ++ ) {
F_14 ( V_6 , V_34 ) ;
for ( V_59 = 0 ; V_59 < V_39 ; V_59 ++ )
* ( ( * V_31 ) ++ ) = ( ( T_3 * ) & V_6 -> V_37 -> V_60 [ V_34 ] . V_33 )
[ V_40 [ V_59 ] . V_61 ] ;
}
for ( V_34 = 0 ; V_34 < V_6 -> V_37 -> V_43 ; V_34 ++ ) {
F_15 ( V_6 , V_34 ) ;
for ( V_59 = 0 ; V_59 < V_39 ; V_59 ++ )
* ( ( * V_31 ) ++ ) = ( ( T_3 * ) & V_6 -> V_37 -> V_62 [ V_34 ] . V_33 )
[ V_40 [ V_59 ] . V_61 ] ;
}
}
static void F_16 ( struct V_1 * V_2 ,
struct V_58 * V_33 , T_3 * V_31 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_59 , V_63 ;
int V_45 , V_64 ;
F_17 ( V_6 ) ;
F_18 ( V_6 ) ;
for ( V_59 = 0 ; V_59 < V_47 ; V_59 ++ )
* ( V_31 ++ ) = ( ( T_3 * ) & V_6 -> V_65 )
[ V_48 [ V_59 ] . V_61 ] ;
for ( V_59 = 0 ; V_59 < V_49 ; V_59 ++ ) {
V_63 = 0 ;
F_19 (cpu)
V_63 += ( ( T_3 * ) F_20 ( V_6 -> V_66 , V_64 ) )
[ V_50 [ V_59 ] . V_61 ] ;
* ( V_31 ++ ) = V_63 ;
}
F_13 ( V_6 , V_33 , & V_31 ) ;
for ( V_45 = 0 ; V_45 < V_6 -> V_51 ; V_45 ++ ) {
if ( ! V_6 -> V_52 [ V_45 ] )
continue;
F_13 ( V_6 -> V_52 [ V_45 ] , V_33 , & V_31 ) ;
}
for ( V_59 = 0 ; V_59 < V_53 ; V_59 ++ )
* ( V_31 ++ ) = V_6 -> V_67 . V_68 [ V_59 ] ;
for ( V_59 = 0 ; V_59 < V_54 ; V_59 ++ )
* ( V_31 ++ ) = V_6 -> V_67 . V_69 [ V_59 ] ;
}
static int F_21 ( struct V_1 * V_70 )
{
return sizeof( T_3 ) * V_71 ;
}
static void F_22 ( struct V_1 * V_70 ,
struct V_72 * V_73 , void * V_74 )
{
struct V_5 * V_6 = F_2 ( V_70 ) ;
T_3 * V_75 = ( T_3 * ) V_74 ;
T_3 V_76 ;
int V_77 , V_78 , V_59 , V_79 ;
int V_80 = 0 ;
V_73 -> V_25 = 0 ;
memset ( V_75 , 0 , V_71 ) ;
V_75 [ V_80 ++ ] = F_23 ( V_6 , V_81 ) ;
for ( V_77 = 0 ; V_77 < V_82 ; V_77 ++ )
V_75 [ V_80 ++ ] = F_23 ( V_6 ,
V_83 | ( V_77 << 3 ) ) ;
V_75 [ V_80 ++ ] = F_23 ( V_6 , V_84 ) ;
V_75 [ V_80 ++ ] = F_23 ( V_6 , V_85 ) ;
V_75 [ V_80 ++ ] = F_23 ( V_6 , V_86 ) ;
V_75 [ V_80 ++ ] = F_23 ( V_6 , V_87 ) ;
V_75 [ V_80 ++ ] = F_23 ( V_6 , V_88 ) ;
for ( V_78 = 0 ; V_78 < V_89 ; V_78 ++ )
V_75 [ V_80 ++ ] = F_23 ( V_6 , V_90 | ( V_78 << 3 ) ) ;
for ( V_59 = 0 ; V_59 < V_91 ; V_59 ++ )
V_75 [ V_80 ++ ] = F_23 ( V_6 ,
V_92 | ( V_59 << 3 ) ) ;
for ( V_80 = 0 ; V_80 < V_93 ; V_80 ++ )
V_75 [ V_80 ++ ] = F_23 ( V_6 ,
V_94 | ( V_59 << 3 ) ) ;
V_75 [ V_80 ++ ] = F_23 ( V_6 , V_95 ) ;
for ( V_79 = 0 ; V_79 < V_96 ; V_79 ++ ) {
V_75 [ V_80 ++ ] = F_24 ( V_6 , V_97 , V_79 ) ;
V_75 [ V_80 ++ ] = F_24 ( V_6 , V_98 , V_79 ) ;
V_75 [ V_80 ++ ] = F_24 ( V_6 , V_99 , V_79 ) ;
V_75 [ V_80 ++ ] = F_24 ( V_6 , V_100 , V_79 ) ;
V_75 [ V_80 ++ ] = F_24 ( V_6 , V_101 , V_79 ) ;
V_75 [ V_80 ++ ] = F_24 ( V_6 , V_102 , V_79 ) ;
V_75 [ V_80 ++ ] = F_24 ( V_6 , V_103 , V_79 ) ;
V_75 [ V_80 ++ ] = F_24 ( V_6 , V_104 , V_79 ) ;
V_75 [ V_80 ++ ] = F_24 ( V_6 , V_105 , V_79 ) ;
V_75 [ V_80 ++ ] = F_24 ( V_6 , V_106 , V_79 ) ;
}
for ( V_79 = 0 ; V_79 < V_36 ; V_79 ++ ) {
V_75 [ V_80 ++ ] = F_24 ( V_6 , V_107 , V_79 ) ;
V_75 [ V_80 ++ ] = F_24 ( V_6 ,
V_108 , V_79 ) ;
V_76 = V_108 | ( 1 << 3 ) ;
V_75 [ V_80 ++ ] = F_24 ( V_6 , V_76 , V_79 ) ;
}
for ( V_79 = 0 ; V_79 < V_109 ; V_79 ++ ) {
V_75 [ V_80 ++ ] = F_24 ( V_6 , V_110 , V_79 ) ;
V_75 [ V_80 ++ ] = F_24 ( V_6 , V_111 , V_79 ) ;
V_75 [ V_80 ++ ] = F_24 ( V_6 , V_112 , V_79 ) ;
V_75 [ V_80 ++ ] = F_24 ( V_6 , V_113 , V_79 ) ;
V_75 [ V_80 ++ ] = F_24 ( V_6 , V_114 , V_79 ) ;
V_75 [ V_80 ++ ] = F_24 ( V_6 , V_115 , V_79 ) ;
V_75 [ V_80 ++ ] = F_24 ( V_6 , V_116 , V_79 ) ;
V_75 [ V_80 ++ ] = F_24 ( V_6 , V_117 , V_79 ) ;
V_75 [ V_80 ++ ] = 0 ;
V_75 [ V_80 ++ ] = F_24 ( V_6 , V_118 , V_79 ) ;
V_76 = V_118 | ( 1 << 3 ) ;
V_75 [ V_80 ++ ] = F_24 ( V_6 , V_76 , V_79 ) ;
}
for ( V_79 = 0 ; V_79 < V_119 ; V_79 ++ ) {
V_75 [ V_80 ++ ] = F_24 ( V_6 , V_120 , V_79 ) ;
V_75 [ V_80 ++ ] = F_24 ( V_6 , V_121 , V_79 ) ;
V_75 [ V_80 ++ ] = F_24 ( V_6 , V_122 , V_79 ) ;
V_75 [ V_80 ++ ] = F_24 ( V_6 , V_123 , V_79 ) ;
V_75 [ V_80 ++ ] = F_24 ( V_6 , V_124 , V_79 ) ;
V_75 [ V_80 ++ ] = F_24 ( V_6 , V_125 , V_79 ) ;
V_75 [ V_80 ++ ] = F_24 ( V_6 ,
V_126 , V_79 ) ;
V_75 [ V_80 ++ ] = F_24 ( V_6 ,
V_127 , V_79 ) ;
V_76 = V_128 ;
V_75 [ V_80 ++ ] = F_24 ( V_6 , V_76 , V_79 ) ;
}
}
static int F_25 ( struct V_1 * V_2 ,
struct V_129 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_4 -> V_130 = V_6 -> V_131 ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_132 * V_133 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_134 * V_37 = V_6 -> V_37 ;
V_133 -> V_135 = V_136 ;
V_133 -> V_137 = V_37 -> V_138 ;
V_133 -> V_139 = V_140 ;
V_133 -> V_141 = V_37 -> V_142 ;
}
static int F_27 ( struct V_5 * V_6 ,
struct V_143 * V_22 )
{
V_22 -> V_31 = 0 ;
switch ( V_22 -> V_144 ) {
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
V_22 -> V_31 |= V_151 | V_152 ;
case V_153 :
case V_154 :
V_22 -> V_31 |= V_155 | V_156 ;
break;
default:
return - V_56 ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_70 ,
struct V_143 * V_22 , T_1 * V_157 )
{
struct V_5 * V_6 = F_2 ( V_70 ) ;
int V_158 = - V_159 ;
switch ( V_22 -> V_4 ) {
case V_160 :
V_22 -> V_31 = V_6 -> V_161 ;
V_158 = 0 ;
break;
case V_162 :
return F_27 ( V_6 , V_22 ) ;
default:
break;
}
return V_158 ;
}
static int F_29 ( struct V_5 * V_6 ,
struct V_143 * V_22 )
{
struct V_163 * V_164 = & V_6 -> V_165 ;
T_3 V_166 = F_23 ( V_6 , V_88 ) ;
if ( ! V_164 -> V_167 )
F_30 ( V_6 -> V_2 ,
L_5 ) ;
F_31 ( V_6 -> V_2 , L_6 ,
V_22 -> V_144 , V_22 -> V_31 ) ;
if ( ! ( V_22 -> V_31 & V_155 ) || ! ( V_22 -> V_31 & V_156 ) )
return - V_56 ;
switch ( V_22 -> V_144 ) {
case V_145 :
case V_146 :
switch ( V_22 -> V_31 & ( V_151 | V_152 ) ) {
case 0 :
V_166 &= ~ ( 1ULL << V_168 ) ;
break;
case ( V_151 | V_152 ) :
V_166 |= ( 1ULL << V_168 ) ;
break;
default:
return - V_56 ;
}
break;
case V_147 :
case V_148 :
switch ( V_22 -> V_31 & ( V_151 | V_152 ) ) {
case 0 :
V_166 &= ~ ( 1ULL << V_169 ) ;
break;
case ( V_151 | V_152 ) :
V_166 |= ( 1ULL << V_169 ) ;
break;
default:
return - V_56 ;
}
break;
case V_149 :
case V_150 :
switch ( V_22 -> V_31 & ( V_151 | V_152 ) ) {
case 0 :
V_166 &= ~ ( 1ULL << V_170 ) ;
break;
case ( V_151 | V_152 ) :
V_166 |= ( 1ULL << V_170 ) ;
break;
default:
return - V_56 ;
}
break;
case V_153 :
case V_154 :
V_166 = V_171 ;
break;
default:
return - V_56 ;
}
F_32 ( V_6 , V_88 , V_166 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_70 , struct V_143 * V_22 )
{
struct V_5 * V_6 = F_2 ( V_70 ) ;
switch ( V_22 -> V_4 ) {
case V_172 :
return F_29 ( V_6 , V_22 ) ;
default:
break;
}
return - V_159 ;
}
static T_1 F_34 ( struct V_1 * V_2 )
{
return V_89 * sizeof( T_3 ) ;
}
static T_1 F_35 ( struct V_1 * V_70 )
{
struct V_5 * V_6 = F_2 ( V_70 ) ;
return V_6 -> V_165 . V_173 ;
}
static int F_36 ( struct V_1 * V_70 , T_1 * V_174 , T_2 * V_175 ,
T_2 * V_176 )
{
struct V_5 * V_6 = F_2 ( V_70 ) ;
struct V_163 * V_164 = & V_6 -> V_165 ;
int V_177 ;
if ( V_174 ) {
for ( V_177 = 0 ; V_177 < V_164 -> V_173 ; V_177 ++ )
V_174 [ V_177 ] = V_164 -> V_178 [ V_177 ] ;
}
if ( V_175 )
memcpy ( V_175 , V_164 -> V_78 , V_89 * sizeof( T_3 ) ) ;
if ( V_176 )
* V_176 = V_179 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_70 , const T_1 * V_174 ,
const T_2 * V_175 , T_2 V_176 )
{
struct V_5 * V_6 = F_2 ( V_70 ) ;
struct V_163 * V_164 = & V_6 -> V_165 ;
int V_177 ;
if ( V_176 != V_180 && V_176 != V_179 )
return - V_159 ;
if ( ! V_164 -> V_167 ) {
F_30 ( V_6 -> V_2 ,
L_7 ) ;
return - V_181 ;
}
if ( V_174 ) {
for ( V_177 = 0 ; V_177 < V_164 -> V_173 ; V_177 ++ )
V_164 -> V_178 [ V_177 ] = V_174 [ V_177 ] ;
}
if ( V_175 ) {
memcpy ( V_164 -> V_78 , V_175 , V_89 * sizeof( T_3 ) ) ;
F_38 ( V_6 ) ;
}
F_39 ( V_6 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_70 ,
struct V_182 * V_183 )
{
struct V_5 * V_6 = F_2 ( V_70 ) ;
memset ( V_183 , 0 , sizeof( * V_183 ) ) ;
V_183 -> V_184 = V_6 -> V_185 ;
V_183 -> V_186 = V_6 -> V_185 ;
V_183 -> V_187 = V_6 -> V_161 ;
V_183 -> V_188 = V_6 -> V_189 ;
}
static int F_41 ( struct V_1 * V_70 ,
struct V_182 * V_183 )
{
struct V_5 * V_6 = F_2 ( V_70 ) ;
int V_190 = 0 ;
bool V_191 = F_42 ( V_70 ) ;
int V_192 ;
if ( ! V_183 -> V_187 || ! V_183 -> V_188 )
return - V_56 ;
if ( V_183 -> V_187 > V_6 -> V_185 )
return - V_56 ;
if ( V_183 -> V_188 > V_6 -> V_185 )
return - V_56 ;
if ( V_191 )
F_43 ( V_70 ) ;
V_192 = F_44 ( V_183 -> V_187 , V_183 -> V_188 ) ;
if ( V_192 > V_96 ) {
V_6 -> V_51 = F_45 ( V_192 , V_96 ) ;
V_6 -> V_51 = ( V_6 -> V_51 / V_96 ) - 1 ;
} else {
V_6 -> V_51 = 0 ;
}
V_6 -> V_37 -> V_38 = F_46 ( T_1 , V_183 -> V_187 , V_36 ) ;
V_6 -> V_37 -> V_43 = F_46 ( T_1 , V_183 -> V_188 , V_109 ) ;
V_6 -> V_37 -> V_193 = F_44 ( V_6 -> V_37 -> V_38 , V_6 -> V_37 -> V_43 ) ;
V_6 -> V_161 = V_183 -> V_187 ;
V_6 -> V_189 = V_183 -> V_188 ;
V_190 = F_47 ( V_70 , V_6 -> V_189 , V_6 -> V_161 ) ;
if ( V_190 )
return V_190 ;
if ( V_191 )
F_48 ( V_70 ) ;
F_31 ( V_70 , L_8 ,
V_6 -> V_189 , V_6 -> V_161 ) ;
return V_190 ;
}
void F_49 ( struct V_1 * V_2 )
{
V_2 -> V_194 = & V_195 ;
}
