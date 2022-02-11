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
int V_59 ;
int V_45 ;
F_17 ( V_6 ) ;
F_18 ( V_6 ) ;
for ( V_59 = 0 ; V_59 < V_47 ; V_59 ++ )
* ( V_31 ++ ) = ( ( T_3 * ) & V_6 -> V_63 )
[ V_48 [ V_59 ] . V_61 ] ;
for ( V_59 = 0 ; V_59 < V_49 ; V_59 ++ )
* ( V_31 ++ ) = ( ( T_3 * ) & V_6 -> V_64 )
[ V_50 [ V_59 ] . V_61 ] ;
F_13 ( V_6 , V_33 , & V_31 ) ;
for ( V_45 = 0 ; V_45 < V_6 -> V_51 ; V_45 ++ ) {
if ( ! V_6 -> V_52 [ V_45 ] )
continue;
F_13 ( V_6 -> V_52 [ V_45 ] , V_33 , & V_31 ) ;
}
for ( V_59 = 0 ; V_59 < V_53 ; V_59 ++ )
* ( V_31 ++ ) = V_6 -> V_65 . V_66 [ V_59 ] ;
for ( V_59 = 0 ; V_59 < V_54 ; V_59 ++ )
* ( V_31 ++ ) = V_6 -> V_65 . V_67 [ V_59 ] ;
}
static int F_19 ( struct V_1 * V_68 )
{
return sizeof( T_3 ) * V_69 ;
}
static void F_20 ( struct V_1 * V_68 ,
struct V_70 * V_71 , void * V_72 )
{
struct V_5 * V_6 = F_2 ( V_68 ) ;
T_3 * V_73 = ( T_3 * ) V_72 ;
T_3 V_74 ;
int V_75 , V_76 , V_59 , V_77 ;
int V_78 = 0 ;
V_71 -> V_25 = 0 ;
memset ( V_73 , 0 , V_69 ) ;
V_73 [ V_78 ++ ] = F_21 ( V_6 , V_79 ) ;
for ( V_75 = 0 ; V_75 < V_80 ; V_75 ++ )
V_73 [ V_78 ++ ] = F_21 ( V_6 ,
V_81 | ( V_75 << 3 ) ) ;
V_73 [ V_78 ++ ] = F_21 ( V_6 , V_82 ) ;
V_73 [ V_78 ++ ] = F_21 ( V_6 , V_83 ) ;
V_73 [ V_78 ++ ] = F_21 ( V_6 , V_84 ) ;
V_73 [ V_78 ++ ] = F_21 ( V_6 , V_85 ) ;
V_73 [ V_78 ++ ] = F_21 ( V_6 , V_86 ) ;
for ( V_76 = 0 ; V_76 < V_87 ; V_76 ++ )
V_73 [ V_78 ++ ] = F_21 ( V_6 , V_88 | ( V_76 << 3 ) ) ;
for ( V_59 = 0 ; V_59 < V_89 ; V_59 ++ )
V_73 [ V_78 ++ ] = F_21 ( V_6 ,
V_90 | ( V_59 << 3 ) ) ;
for ( V_78 = 0 ; V_78 < V_91 ; V_78 ++ )
V_73 [ V_78 ++ ] = F_21 ( V_6 ,
V_92 | ( V_59 << 3 ) ) ;
V_73 [ V_78 ++ ] = F_21 ( V_6 , V_93 ) ;
for ( V_77 = 0 ; V_77 < V_94 ; V_77 ++ ) {
V_73 [ V_78 ++ ] = F_22 ( V_6 , V_95 , V_77 ) ;
V_73 [ V_78 ++ ] = F_22 ( V_6 , V_96 , V_77 ) ;
V_73 [ V_78 ++ ] = F_22 ( V_6 , V_97 , V_77 ) ;
V_73 [ V_78 ++ ] = F_22 ( V_6 , V_98 , V_77 ) ;
V_73 [ V_78 ++ ] = F_22 ( V_6 , V_99 , V_77 ) ;
V_73 [ V_78 ++ ] = F_22 ( V_6 , V_100 , V_77 ) ;
V_73 [ V_78 ++ ] = F_22 ( V_6 , V_101 , V_77 ) ;
V_73 [ V_78 ++ ] = F_22 ( V_6 , V_102 , V_77 ) ;
V_73 [ V_78 ++ ] = F_22 ( V_6 , V_103 , V_77 ) ;
V_73 [ V_78 ++ ] = F_22 ( V_6 , V_104 , V_77 ) ;
}
for ( V_77 = 0 ; V_77 < V_36 ; V_77 ++ ) {
V_73 [ V_78 ++ ] = F_22 ( V_6 , V_105 , V_77 ) ;
V_73 [ V_78 ++ ] = F_22 ( V_6 ,
V_106 , V_77 ) ;
V_74 = V_106 | ( 1 << 3 ) ;
V_73 [ V_78 ++ ] = F_22 ( V_6 , V_74 , V_77 ) ;
}
for ( V_77 = 0 ; V_77 < V_107 ; V_77 ++ ) {
V_73 [ V_78 ++ ] = F_22 ( V_6 , V_108 , V_77 ) ;
V_73 [ V_78 ++ ] = F_22 ( V_6 , V_109 , V_77 ) ;
V_73 [ V_78 ++ ] = F_22 ( V_6 , V_110 , V_77 ) ;
V_73 [ V_78 ++ ] = F_22 ( V_6 , V_111 , V_77 ) ;
V_73 [ V_78 ++ ] = F_22 ( V_6 , V_112 , V_77 ) ;
V_73 [ V_78 ++ ] = F_22 ( V_6 , V_113 , V_77 ) ;
V_73 [ V_78 ++ ] = F_22 ( V_6 , V_114 , V_77 ) ;
V_73 [ V_78 ++ ] = F_22 ( V_6 , V_115 , V_77 ) ;
V_73 [ V_78 ++ ] = 0 ;
V_73 [ V_78 ++ ] = F_22 ( V_6 , V_116 , V_77 ) ;
V_74 = V_116 | ( 1 << 3 ) ;
V_73 [ V_78 ++ ] = F_22 ( V_6 , V_74 , V_77 ) ;
}
for ( V_77 = 0 ; V_77 < V_117 ; V_77 ++ ) {
V_73 [ V_78 ++ ] = F_22 ( V_6 , V_118 , V_77 ) ;
V_73 [ V_78 ++ ] = F_22 ( V_6 , V_119 , V_77 ) ;
V_73 [ V_78 ++ ] = F_22 ( V_6 , V_120 , V_77 ) ;
V_73 [ V_78 ++ ] = F_22 ( V_6 , V_121 , V_77 ) ;
V_73 [ V_78 ++ ] = F_22 ( V_6 , V_122 , V_77 ) ;
V_73 [ V_78 ++ ] = F_22 ( V_6 , V_123 , V_77 ) ;
V_73 [ V_78 ++ ] = F_22 ( V_6 ,
V_124 , V_77 ) ;
V_73 [ V_78 ++ ] = F_22 ( V_6 ,
V_125 , V_77 ) ;
V_74 = V_126 ;
V_73 [ V_78 ++ ] = F_22 ( V_6 , V_74 , V_77 ) ;
}
}
static int F_23 ( struct V_1 * V_2 ,
struct V_127 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_4 -> V_128 = V_6 -> V_129 ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_130 * V_131 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_132 * V_37 = V_6 -> V_37 ;
V_131 -> V_133 = V_134 ;
V_131 -> V_135 = V_37 -> V_136 ;
V_131 -> V_137 = V_138 ;
V_131 -> V_139 = V_37 -> V_140 ;
}
static int F_25 ( struct V_5 * V_6 ,
struct V_141 * V_22 )
{
V_22 -> V_31 = 0 ;
switch ( V_22 -> V_142 ) {
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
V_22 -> V_31 |= V_149 | V_150 ;
case V_151 :
case V_152 :
V_22 -> V_31 |= V_153 | V_154 ;
break;
default:
return - V_56 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_68 ,
struct V_141 * V_22 , T_1 * V_155 )
{
struct V_5 * V_6 = F_2 ( V_68 ) ;
int V_156 = - V_157 ;
switch ( V_22 -> V_4 ) {
case V_158 :
V_22 -> V_31 = V_6 -> V_159 ;
V_156 = 0 ;
break;
case V_160 :
return F_25 ( V_6 , V_22 ) ;
default:
break;
}
return V_156 ;
}
static int F_27 ( struct V_5 * V_6 ,
struct V_141 * V_22 )
{
struct V_161 * V_162 = & V_6 -> V_163 ;
T_3 V_164 = F_21 ( V_6 , V_86 ) ;
if ( ! V_162 -> V_165 )
F_28 ( V_6 -> V_2 ,
L_5 ) ;
F_29 ( V_6 -> V_2 , L_6 ,
V_22 -> V_142 , V_22 -> V_31 ) ;
if ( ! ( V_22 -> V_31 & V_153 ) || ! ( V_22 -> V_31 & V_154 ) )
return - V_56 ;
switch ( V_22 -> V_142 ) {
case V_143 :
case V_144 :
switch ( V_22 -> V_31 & ( V_149 | V_150 ) ) {
case 0 :
V_164 &= ~ ( 1ULL << V_166 ) ;
break;
case ( V_149 | V_150 ) :
V_164 |= ( 1ULL << V_166 ) ;
break;
default:
return - V_56 ;
}
break;
case V_145 :
case V_146 :
switch ( V_22 -> V_31 & ( V_149 | V_150 ) ) {
case 0 :
V_164 &= ~ ( 1ULL << V_167 ) ;
break;
case ( V_149 | V_150 ) :
V_164 |= ( 1ULL << V_167 ) ;
break;
default:
return - V_56 ;
}
break;
case V_147 :
case V_148 :
switch ( V_22 -> V_31 & ( V_149 | V_150 ) ) {
case 0 :
V_164 &= ~ ( 1ULL << V_168 ) ;
break;
case ( V_149 | V_150 ) :
V_164 |= ( 1ULL << V_168 ) ;
break;
default:
return - V_56 ;
}
break;
case V_151 :
case V_152 :
V_164 = V_169 ;
break;
default:
return - V_56 ;
}
F_30 ( V_6 , V_86 , V_164 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_68 , struct V_141 * V_22 )
{
struct V_5 * V_6 = F_2 ( V_68 ) ;
switch ( V_22 -> V_4 ) {
case V_170 :
return F_27 ( V_6 , V_22 ) ;
default:
break;
}
return - V_157 ;
}
static T_1 F_32 ( struct V_1 * V_2 )
{
return V_87 * sizeof( T_3 ) ;
}
static T_1 F_33 ( struct V_1 * V_68 )
{
struct V_5 * V_6 = F_2 ( V_68 ) ;
return V_6 -> V_163 . V_171 ;
}
static int F_34 ( struct V_1 * V_68 , T_1 * V_172 , T_2 * V_173 ,
T_2 * V_174 )
{
struct V_5 * V_6 = F_2 ( V_68 ) ;
struct V_161 * V_162 = & V_6 -> V_163 ;
int V_175 ;
if ( V_172 ) {
for ( V_175 = 0 ; V_175 < V_162 -> V_171 ; V_175 ++ )
V_172 [ V_175 ] = V_162 -> V_176 [ V_175 ] ;
}
if ( V_173 )
memcpy ( V_173 , V_162 -> V_76 , V_87 * sizeof( T_3 ) ) ;
if ( V_174 )
* V_174 = V_177 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_68 , const T_1 * V_172 ,
const T_2 * V_173 , T_2 V_174 )
{
struct V_5 * V_6 = F_2 ( V_68 ) ;
struct V_161 * V_162 = & V_6 -> V_163 ;
int V_175 ;
if ( V_174 != V_178 && V_174 != V_177 )
return - V_157 ;
if ( ! V_162 -> V_165 ) {
F_28 ( V_6 -> V_2 ,
L_7 ) ;
return - V_179 ;
}
if ( V_172 ) {
for ( V_175 = 0 ; V_175 < V_162 -> V_171 ; V_175 ++ )
V_162 -> V_176 [ V_175 ] = V_172 [ V_175 ] ;
}
if ( V_173 ) {
memcpy ( V_162 -> V_76 , V_173 , V_87 * sizeof( T_3 ) ) ;
F_36 ( V_6 ) ;
}
F_37 ( V_6 ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_68 ,
struct V_180 * V_181 )
{
struct V_5 * V_6 = F_2 ( V_68 ) ;
memset ( V_181 , 0 , sizeof( * V_181 ) ) ;
V_181 -> V_182 = V_6 -> V_183 ;
V_181 -> V_184 = V_6 -> V_183 ;
V_181 -> V_185 = V_6 -> V_159 ;
V_181 -> V_186 = V_6 -> V_187 ;
}
static int F_39 ( struct V_1 * V_68 ,
struct V_180 * V_181 )
{
struct V_5 * V_6 = F_2 ( V_68 ) ;
int V_188 = 0 ;
bool V_189 = F_40 ( V_68 ) ;
int V_190 ;
if ( ! V_181 -> V_185 || ! V_181 -> V_186 )
return - V_56 ;
if ( V_181 -> V_185 > V_6 -> V_183 )
return - V_56 ;
if ( V_181 -> V_186 > V_6 -> V_183 )
return - V_56 ;
if ( V_189 )
F_41 ( V_68 ) ;
V_190 = F_42 ( V_181 -> V_185 , V_181 -> V_186 ) ;
if ( V_190 > V_94 ) {
V_6 -> V_51 = F_43 ( V_190 , V_94 ) ;
V_6 -> V_51 = ( V_6 -> V_51 / V_94 ) - 1 ;
} else {
V_6 -> V_51 = 0 ;
}
V_6 -> V_37 -> V_38 = F_44 ( T_1 , V_181 -> V_185 , V_36 ) ;
V_6 -> V_37 -> V_43 = F_44 ( T_1 , V_181 -> V_186 , V_107 ) ;
V_6 -> V_37 -> V_191 = F_42 ( V_6 -> V_37 -> V_38 , V_6 -> V_37 -> V_43 ) ;
V_6 -> V_159 = V_181 -> V_185 ;
V_6 -> V_187 = V_181 -> V_186 ;
V_188 = F_45 ( V_68 , V_6 -> V_187 , V_6 -> V_159 ) ;
if ( V_188 )
return V_188 ;
if ( V_189 )
F_46 ( V_68 ) ;
F_29 ( V_68 , L_8 ,
V_6 -> V_187 , V_6 -> V_159 ) ;
return V_188 ;
}
void F_47 ( struct V_1 * V_2 )
{
V_2 -> V_192 = & V_193 ;
}
