static void F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
int V_4 , V_5 , V_6 ;
for ( V_4 = 0 , V_5 = 0 ; V_4 < V_7 ; V_4 ++ ) {
if ( F_2 ( V_2 ) && V_8 [ V_4 ] . V_9 )
continue;
strcpy ( V_3 + V_5 * V_10 ,
V_8 [ V_4 ] . string ) ;
V_5 ++ ;
}
for ( V_6 = 0 ; V_6 < V_11 ; V_6 ++ , V_5 ++ )
strcpy ( V_3 + V_5 * V_10 ,
V_12 [ V_6 ] . string ) ;
}
static void F_3 ( struct V_13 * V_14 , T_2 V_15 , T_1 * V_3 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
switch ( V_15 ) {
case V_16 :
F_1 ( V_2 , V_3 ) ;
break;
case V_17 :
memcpy ( V_3 , V_18 ,
V_10 * V_19 ) ;
break;
case V_20 :
memcpy ( V_3 , V_21 ,
V_10 * V_22 ) ;
break;
default:
F_5 ( V_2 , V_23 ,
L_1 , V_15 ) ;
}
}
static void F_6 ( struct V_13 * V_14 ,
struct V_24 * V_25 , T_3 * V_3 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
int V_26 , V_27 = 0 ;
int V_28 ;
F_7 ( V_2 ) ;
F_8 ( & V_2 -> V_29 ) ;
for ( V_26 = 0 ; V_26 < V_7 ; V_26 ++ ) {
if ( F_2 ( V_2 ) && V_8 [ V_26 ] . V_9 )
continue;
V_3 [ V_27 ++ ] = F_9 ( V_2 , V_26 ) ;
}
for ( V_26 = 0 ; V_26 < V_11 ; V_26 ++ ) {
V_3 [ V_27 ] = 0 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_30 ; V_28 ++ )
V_3 [ V_27 ] += F_10 ( V_2 , V_26 , V_28 ) ;
V_27 ++ ;
}
F_11 ( & V_2 -> V_29 ) ;
}
static int F_12 ( struct V_13 * V_14 , int V_15 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
int V_31 = V_7 ;
switch ( V_15 ) {
case V_16 :
if ( F_2 ( V_2 ) ) {
int V_4 ;
for ( V_4 = 0 ; V_4 < V_7 ; V_4 ++ )
if ( V_8 [ V_4 ] . V_9 )
V_31 -- ;
}
return V_31 + V_11 ;
case V_17 :
return V_19 ;
case V_20 :
if ( ! F_2 ( V_2 ) )
return V_22 ;
else
return 0 ;
default:
F_5 ( V_2 , V_23 ,
L_1 , V_15 ) ;
return - V_32 ;
}
}
static T_2 F_13 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
return ( ! ! ( V_2 -> V_33 . V_34 . V_35 > 1 ) ) << V_36 ;
}
static int F_14 ( struct V_13 * V_14 , struct V_37 * V_38 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
struct V_39 V_40 ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_2 -> V_41 -> V_34 -> V_42 ( V_2 -> V_43 , & V_40 ) ;
V_38 -> V_44 = V_40 . V_45 ;
V_38 -> V_46 = V_40 . V_47 ;
if ( ( V_2 -> V_48 == V_49 ) && ( V_40 . V_50 ) ) {
F_15 ( V_38 , V_40 . V_51 ) ;
V_38 -> V_52 = V_40 . V_52 ;
} else {
V_38 -> V_52 = V_53 ;
F_15 ( V_38 , V_54 ) ;
}
V_38 -> V_55 = V_40 . V_55 ;
V_38 -> V_56 = ( V_40 . V_56 ) ? V_57 :
V_58 ;
V_38 -> V_59 = V_40 . V_60 ;
return 0 ;
}
static int F_16 ( struct V_13 * V_14 , struct V_37 * V_38 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
struct V_39 V_40 ;
struct V_61 V_62 ;
T_2 V_51 ;
if ( ! V_2 -> V_41 || ! V_2 -> V_41 -> V_34 -> V_63 ( V_2 -> V_43 ) ) {
F_17 ( V_2 ,
L_2 ) ;
return - V_64 ;
}
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
V_2 -> V_41 -> V_34 -> V_42 ( V_2 -> V_43 , & V_40 ) ;
V_51 = F_18 ( V_38 ) ;
V_62 . V_65 |= V_66 ;
V_62 . V_65 |= V_67 ;
if ( V_38 -> V_56 == V_57 ) {
V_62 . V_56 = true ;
V_62 . V_68 = 0 ;
V_62 . V_69 = V_38 -> V_46 ;
} else {
V_62 . V_65 |= V_70 ;
V_62 . V_56 = false ;
V_62 . V_68 = V_51 ;
switch ( V_51 ) {
case V_71 :
if ( ! ( V_40 . V_45 &
V_72 ) ) {
F_17 ( V_2 , L_3 ) ;
return - V_32 ;
}
V_62 . V_69 = V_72 ;
break;
case V_73 :
if ( ! ( V_40 . V_45 &
V_74 ) ) {
F_17 ( V_2 , L_4 ) ;
return - V_32 ;
}
V_62 . V_69 = V_74 ;
break;
default:
F_17 ( V_2 , L_5 , V_51 ) ;
return - V_32 ;
}
}
V_62 . V_50 = true ;
V_2 -> V_41 -> V_34 -> V_75 ( V_2 -> V_43 , & V_62 ) ;
return 0 ;
}
static void F_19 ( struct V_13 * V_76 ,
struct V_77 * V_78 )
{
char V_79 [ V_80 ] , V_81 [ V_80 ] ;
struct V_1 * V_2 = F_4 ( V_76 ) ;
F_20 ( V_78 -> V_82 , L_6 , sizeof( V_78 -> V_82 ) ) ;
F_20 ( V_78 -> V_83 , V_84 , sizeof( V_78 -> V_83 ) ) ;
snprintf ( V_81 , V_80 , L_7 ,
V_2 -> V_33 . V_34 . V_85 ,
V_2 -> V_33 . V_34 . V_86 ,
V_2 -> V_33 . V_34 . V_87 ,
V_2 -> V_33 . V_34 . V_88 ) ;
snprintf ( V_79 , V_80 , L_7 ,
( V_2 -> V_33 . V_34 . V_89 >> 24 ) & 0xFF ,
( V_2 -> V_33 . V_34 . V_89 >> 16 ) & 0xFF ,
( V_2 -> V_33 . V_34 . V_89 >> 8 ) & 0xFF ,
V_2 -> V_33 . V_34 . V_89 & 0xFF ) ;
if ( ( strlen ( V_81 ) + strlen ( V_79 ) + strlen ( L_8 ) ) <
sizeof( V_78 -> V_90 ) ) {
snprintf ( V_78 -> V_90 , sizeof( V_78 -> V_90 ) ,
L_9 , V_79 , V_81 ) ;
} else {
snprintf ( V_78 -> V_90 , sizeof( V_78 -> V_90 ) ,
L_10 , V_79 , V_81 ) ;
}
F_20 ( V_78 -> V_91 , F_21 ( V_2 -> V_92 ) , sizeof( V_78 -> V_91 ) ) ;
}
static T_2 F_22 ( struct V_13 * V_76 )
{
struct V_1 * V_2 = F_4 ( V_76 ) ;
return ( ( T_2 ) V_2 -> V_93 << V_94 ) |
V_2 -> V_95 ;
}
static void F_23 ( struct V_13 * V_76 , T_2 V_96 )
{
struct V_1 * V_2 = F_4 ( V_76 ) ;
T_2 V_95 = 0 ;
T_1 V_93 = 0 ;
F_24 ( V_96 , & V_95 , & V_93 ) ;
V_2 -> V_93 = V_93 ;
V_2 -> V_95 = V_95 ;
V_2 -> V_41 -> V_34 -> V_97 ( V_2 -> V_43 ,
V_95 , V_93 ) ;
}
static int F_25 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
struct V_39 V_40 ;
struct V_61 V_98 ;
if ( ! V_2 -> V_41 || ! V_2 -> V_41 -> V_34 -> V_63 ( V_2 -> V_43 ) ) {
F_17 ( V_2 ,
L_2 ) ;
return - V_64 ;
}
if ( ! F_26 ( V_14 ) )
return 0 ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_2 -> V_41 -> V_34 -> V_42 ( V_2 -> V_43 , & V_40 ) ;
if ( ! V_40 . V_50 )
return 0 ;
memset ( & V_98 , 0 , sizeof( V_98 ) ) ;
V_98 . V_50 = false ;
V_2 -> V_41 -> V_34 -> V_75 ( V_2 -> V_43 , & V_98 ) ;
V_98 . V_50 = true ;
V_2 -> V_41 -> V_34 -> V_75 ( V_2 -> V_43 , & V_98 ) ;
return 0 ;
}
static T_2 F_27 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
struct V_39 V_40 ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_2 -> V_41 -> V_34 -> V_42 ( V_2 -> V_43 , & V_40 ) ;
return V_40 . V_50 ;
}
static int F_28 ( struct V_13 * V_14 ,
struct V_99 * V_100 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
T_4 V_101 , V_102 ;
memset ( V_100 , 0 , sizeof( struct V_99 ) ) ;
V_2 -> V_41 -> V_34 -> V_103 ( V_2 -> V_43 , & V_101 , & V_102 ) ;
V_100 -> V_104 = V_101 ;
V_100 -> V_105 = V_102 ;
return 0 ;
}
static int F_29 ( struct V_13 * V_14 ,
struct V_99 * V_100 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
int V_4 , V_106 = 0 ;
T_4 V_101 , V_102 ;
T_1 V_107 ;
if ( ! F_26 ( V_14 ) ) {
F_17 ( V_2 , L_11 ) ;
return - V_32 ;
}
if ( V_100 -> V_104 > V_108 ||
V_100 -> V_105 > V_108 ) {
F_17 ( V_2 ,
L_12 ,
V_100 -> V_104 > V_108 ? L_13
: L_14 ,
V_108 ) ;
return - V_32 ;
}
V_101 = ( T_4 ) V_100 -> V_104 ;
V_102 = ( T_4 ) V_100 -> V_105 ;
F_30 (i) {
V_107 = V_2 -> V_109 [ V_4 ] . V_110 -> V_111 ;
V_106 = V_2 -> V_41 -> V_34 -> V_112 ( V_2 -> V_43 , V_101 , V_102 ,
( T_1 ) V_4 , V_107 ) ;
if ( V_106 ) {
F_17 ( V_2 , L_15 , V_106 ) ;
return V_106 ;
}
}
return V_106 ;
}
static void F_31 ( struct V_13 * V_14 ,
struct V_113 * V_114 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
V_114 -> V_115 = V_116 ;
V_114 -> V_117 = V_2 -> V_118 ;
V_114 -> V_119 = V_120 ;
V_114 -> V_121 = V_2 -> V_122 ;
}
static int F_32 ( struct V_13 * V_14 ,
struct V_113 * V_114 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
F_5 ( V_2 , ( V_123 | V_124 ) ,
L_16 ,
V_114 -> V_117 , V_114 -> V_121 ) ;
if ( V_114 -> V_117 > V_116 ||
V_114 -> V_117 < V_125 ||
V_114 -> V_121 > V_120 ||
V_114 -> V_121 < V_126 ) {
F_5 ( V_2 , ( V_123 | V_124 ) ,
L_17 ,
V_125 , V_116 ,
V_126 , V_120 ) ;
return - V_32 ;
}
V_2 -> V_118 = V_114 -> V_117 ;
V_2 -> V_122 = V_114 -> V_121 ;
if ( F_26 ( V_2 -> V_76 ) )
F_33 ( V_2 , NULL , NULL ) ;
return 0 ;
}
static void F_34 ( struct V_13 * V_14 ,
struct V_127 * V_128 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
struct V_39 V_40 ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_2 -> V_41 -> V_34 -> V_42 ( V_2 -> V_43 , & V_40 ) ;
if ( V_40 . V_129 & V_130 )
V_128 -> V_56 = true ;
if ( V_40 . V_129 & V_131 )
V_128 -> V_132 = true ;
if ( V_40 . V_129 & V_133 )
V_128 -> V_134 = true ;
F_5 ( V_2 , V_23 ,
L_18 ,
V_128 -> V_38 , V_128 -> V_56 , V_128 -> V_132 ,
V_128 -> V_134 ) ;
}
static int F_35 ( struct V_13 * V_14 ,
struct V_127 * V_128 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
struct V_61 V_62 ;
struct V_39 V_40 ;
if ( ! V_2 -> V_41 || ! V_2 -> V_41 -> V_34 -> V_63 ( V_2 -> V_43 ) ) {
F_17 ( V_2 ,
L_19 ) ;
return - V_64 ;
}
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_2 -> V_41 -> V_34 -> V_42 ( V_2 -> V_43 , & V_40 ) ;
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
V_62 . V_65 |= V_135 ;
if ( V_128 -> V_56 ) {
if ( ! ( V_40 . V_45 & V_136 ) ) {
F_17 ( V_2 , L_20 ) ;
return - V_32 ;
}
V_62 . V_129 |= V_130 ;
}
if ( V_128 -> V_132 )
V_62 . V_129 |= V_131 ;
if ( V_128 -> V_134 )
V_62 . V_129 |= V_133 ;
V_62 . V_50 = true ;
V_2 -> V_41 -> V_34 -> V_75 ( V_2 -> V_43 , & V_62 ) ;
return 0 ;
}
static void F_36 ( struct V_1 * V_2 , union V_137 * args )
{
V_2 -> V_76 -> V_138 = args -> V_138 ;
}
int F_37 ( struct V_13 * V_76 , int V_139 )
{
struct V_1 * V_2 = F_4 ( V_76 ) ;
union V_137 args ;
if ( ( V_139 > V_140 ) ||
( ( V_139 + V_141 ) < V_142 ) ) {
F_38 ( V_2 , L_21 ) ;
return - V_32 ;
}
F_5 ( V_2 , ( V_123 | V_124 ) ,
L_22 , V_139 ) ;
args . V_138 = V_139 ;
if ( F_26 ( V_2 -> V_76 ) )
F_33 ( V_2 , & F_36 , & args ) ;
F_36 ( V_2 , & args ) ;
return 0 ;
}
static void F_39 ( struct V_13 * V_14 ,
struct V_143 * V_144 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
V_144 -> V_145 = F_40 ( V_2 ) ;
V_144 -> V_146 = F_41 ( V_2 ) ;
}
static int F_42 ( struct V_13 * V_14 ,
struct V_143 * V_144 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
F_5 ( V_2 , ( V_123 | V_124 ) ,
L_23 ,
V_144 -> V_147 , V_144 -> V_148 ,
V_144 -> V_149 , V_144 -> V_146 ) ;
if ( V_144 -> V_147 || V_144 -> V_148 ||
V_144 -> V_149 || ( V_144 -> V_146 == 0 ) ||
( V_144 -> V_146 > F_40 ( V_2 ) ) ) {
F_5 ( V_2 , ( V_123 | V_124 ) ,
L_24 ) ;
return - V_32 ;
}
if ( V_144 -> V_146 == F_41 ( V_2 ) ) {
F_5 ( V_2 , ( V_123 | V_124 ) ,
L_25 ) ;
return 0 ;
}
if ( V_144 -> V_146 % V_2 -> V_33 . V_34 . V_35 ) {
F_5 ( V_2 , ( V_123 | V_124 ) ,
L_26 ,
V_2 -> V_33 . V_34 . V_35 ) ;
return - V_32 ;
}
V_2 -> V_150 = V_144 -> V_146 ;
if ( F_26 ( V_14 ) )
F_33 ( V_2 , NULL , NULL ) ;
return 0 ;
}
static int F_43 ( struct V_13 * V_14 ,
enum V_151 V_48 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
T_1 V_152 = 0 ;
switch ( V_48 ) {
case V_153 :
return 1 ;
case V_154 :
V_152 = V_155 ;
break;
case V_156 :
V_152 = V_157 ;
break;
case V_158 :
V_152 = V_159 ;
break;
}
V_2 -> V_41 -> V_34 -> V_160 ( V_2 -> V_43 , V_152 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , struct V_161 * V_78 )
{
V_78 -> V_162 = V_163 | V_164 ;
switch ( V_78 -> V_165 ) {
case V_166 :
case V_167 :
V_78 -> V_162 |= V_168 | V_169 ;
break;
case V_170 :
if ( V_2 -> V_171 . V_172 & V_173 )
V_78 -> V_162 |= V_168 | V_169 ;
break;
case V_174 :
if ( V_2 -> V_171 . V_172 & V_175 )
V_78 -> V_162 |= V_168 | V_169 ;
break;
case V_176 :
case V_177 :
break;
default:
V_78 -> V_162 = 0 ;
break;
}
return 0 ;
}
static int F_45 ( struct V_13 * V_14 , struct V_161 * V_78 ,
T_2 * T_5 V_178 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
switch ( V_78 -> V_38 ) {
case V_179 :
V_78 -> V_162 = V_2 -> V_30 ;
return 0 ;
case V_180 :
return F_44 ( V_2 , V_78 ) ;
default:
F_38 ( V_2 , L_27 ) ;
return - V_64 ;
}
}
static int F_46 ( struct V_1 * V_2 , struct V_161 * V_78 )
{
struct V_181 V_182 ;
T_1 V_183 = 0 , V_184 = 0 ;
F_5 ( V_2 , V_23 ,
L_28 ,
V_78 -> V_165 , V_78 -> V_162 ) ;
switch ( V_78 -> V_165 ) {
case V_166 :
case V_167 :
if ( V_78 -> V_162 ^ ( V_163 | V_164 |
V_168 | V_169 ) ) {
F_17 ( V_2 , L_27 ) ;
return - V_32 ;
}
return 0 ;
case V_170 :
if ( V_78 -> V_162 == ( V_163 | V_164 |
V_168 | V_169 ) ) {
V_183 = V_173 ;
F_5 ( V_2 , V_23 ,
L_29 ) ;
} else if ( V_78 -> V_162 == ( V_163 | V_164 ) ) {
V_184 = V_173 ;
F_5 ( V_2 , V_23 ,
L_30 ) ;
} else {
return - V_32 ;
}
break;
case V_174 :
if ( V_78 -> V_162 == ( V_163 | V_164 |
V_168 | V_169 ) ) {
V_183 = V_175 ;
F_5 ( V_2 , V_23 ,
L_29 ) ;
} else if ( V_78 -> V_162 == ( V_163 | V_164 ) ) {
V_184 = V_175 ;
F_5 ( V_2 , V_23 ,
L_30 ) ;
} else {
return - V_32 ;
}
break;
case V_176 :
case V_177 :
if ( V_78 -> V_162 ^ ( V_163 | V_164 ) ) {
F_17 ( V_2 , L_27 ) ;
return - V_32 ;
}
return 0 ;
case V_185 :
case V_186 :
case V_187 :
case V_188 :
case V_189 :
case V_190 :
case V_191 :
case V_192 :
case V_193 :
case V_194 :
if ( V_78 -> V_162 ) {
F_17 ( V_2 , L_27 ) ;
return - V_32 ;
}
return 0 ;
default:
return - V_32 ;
}
if ( V_2 -> V_171 . V_172 == ( ( V_2 -> V_171 . V_172 &
~ V_184 ) | V_183 ) )
return 0 ;
V_2 -> V_171 . V_172 = ( V_2 -> V_171 . V_172 & ~ V_184 ) |
V_183 ;
V_2 -> V_195 |= V_196 ;
if ( F_26 ( V_2 -> V_76 ) ) {
memset ( & V_182 , 0 , sizeof( V_182 ) ) ;
V_182 . V_197 = 1 ;
V_182 . V_198 = 0 ;
memcpy ( & V_182 . V_171 , & V_2 -> V_171 ,
sizeof( V_182 . V_171 ) ) ;
return V_2 -> V_41 -> V_199 ( V_2 -> V_43 ,
& V_182 ) ;
}
return 0 ;
}
static int F_47 ( struct V_13 * V_14 , struct V_161 * V_78 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
switch ( V_78 -> V_38 ) {
case V_200 :
return F_46 ( V_2 , V_78 ) ;
default:
F_17 ( V_2 , L_27 ) ;
return - V_64 ;
}
}
static T_2 F_48 ( struct V_13 * V_14 )
{
return V_201 ;
}
static T_2 F_49 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
return sizeof( V_2 -> V_171 . V_202 ) ;
}
static int F_50 ( struct V_13 * V_14 , T_2 * V_203 , T_1 * V_204 , T_1 * V_205 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
int V_4 ;
if ( V_205 )
* V_205 = V_206 ;
if ( ! V_203 )
return 0 ;
for ( V_4 = 0 ; V_4 < V_201 ; V_4 ++ )
V_203 [ V_4 ] = V_2 -> V_171 . V_207 [ V_4 ] ;
if ( V_204 )
memcpy ( V_204 , V_2 -> V_171 . V_202 ,
F_49 ( V_14 ) ) ;
return 0 ;
}
static int F_51 ( struct V_13 * V_14 , const T_2 * V_203 ,
const T_1 * V_204 , const T_1 V_205 )
{
struct V_181 V_182 ;
struct V_1 * V_2 = F_4 ( V_14 ) ;
int V_4 ;
if ( V_205 != V_208 && V_205 != V_206 )
return - V_64 ;
if ( ! V_203 && ! V_204 )
return 0 ;
if ( V_203 ) {
for ( V_4 = 0 ; V_4 < V_201 ; V_4 ++ )
V_2 -> V_171 . V_207 [ V_4 ] = V_203 [ V_4 ] ;
V_2 -> V_195 |= V_209 ;
}
if ( V_204 ) {
memcpy ( & V_2 -> V_171 . V_202 , V_204 ,
F_49 ( V_14 ) ) ;
V_2 -> V_195 |= V_210 ;
}
if ( F_26 ( V_2 -> V_76 ) ) {
memset ( & V_182 , 0 , sizeof( V_182 ) ) ;
V_182 . V_197 = 1 ;
V_182 . V_198 = 0 ;
memcpy ( & V_182 . V_171 , & V_2 -> V_171 ,
sizeof( V_182 . V_171 ) ) ;
return V_2 -> V_41 -> V_199 ( V_2 -> V_43 ,
& V_182 ) ;
}
return 0 ;
}
static void F_52 ( struct V_1 * V_2 )
{
int V_4 ;
if ( ! F_26 ( V_2 -> V_76 ) )
return;
F_30 (i) {
F_53 ( V_2 -> V_109 [ V_4 ] . V_110 , V_211 , 1 ) ;
F_54 ( & V_2 -> V_109 [ V_4 ] . V_212 ) ;
}
}
static void F_55 ( struct V_1 * V_2 )
{
int V_4 ;
F_30 (i) {
F_56 ( & V_2 -> V_109 [ V_4 ] . V_212 ) ;
F_53 ( V_2 -> V_109 [ V_4 ] . V_110 , V_213 , 0 ) ;
}
}
static int F_57 ( struct V_1 * V_2 ,
struct V_214 * V_215 )
{
struct V_216 * V_217 = & V_2 -> V_109 [ 0 ] . V_218 [ 0 ] ;
struct V_219 * V_220 ;
T_6 V_221 ;
int V_4 , V_222 , V_223 ;
V_222 = V_217 -> V_224 & V_120 ;
V_217 -> V_225 [ V_222 ] . V_215 = V_215 ;
V_220 = F_58 ( & V_217 -> V_226 ) ;
memset ( V_220 , 0 , sizeof( * V_220 ) ) ;
V_223 = 1 << V_227 ;
V_220 -> V_162 . V_228 . V_229 = V_223 ;
V_223 = V_215 -> V_230 & V_231 ;
V_220 -> V_162 . V_229 |= ( V_223 << V_232 ) ;
V_221 = F_59 ( & V_2 -> V_92 -> V_14 , V_215 -> V_162 ,
F_60 ( V_215 ) , V_233 ) ;
if ( F_61 ( F_62 ( & V_2 -> V_92 -> V_14 , V_221 ) ) ) {
F_63 ( V_2 , L_31 ) ;
return - V_234 ;
}
F_64 ( V_220 , V_221 , F_60 ( V_215 ) ) ;
V_220 -> V_162 . V_235 = 1 ;
V_217 -> V_224 ++ ;
V_223 = F_65 ( F_66 ( & V_217 -> V_226 ) ) ;
V_217 -> V_236 . V_162 . V_237 = V_223 ;
F_67 () ;
F_68 () ;
F_69 ( V_217 -> V_236 . V_238 , V_217 -> V_239 ) ;
F_70 () ;
for ( V_4 = 0 ; V_4 < V_240 ; V_4 ++ ) {
if ( F_71 ( V_217 ) )
break;
F_72 ( 100 , 200 ) ;
}
if ( ! F_71 ( V_217 ) ) {
F_63 ( V_2 , L_32 ) ;
return - 1 ;
}
V_220 = (struct V_219 * ) F_73 ( & V_217 -> V_226 ) ;
F_74 ( & V_2 -> V_92 -> V_14 , F_75 ( V_220 ) ,
F_76 ( V_220 ) , V_233 ) ;
V_217 -> V_241 ++ ;
V_217 -> V_225 [ V_222 ] . V_215 = NULL ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_242 * V_243 = V_2 -> V_109 [ 0 ] . V_243 ;
T_4 V_244 , V_245 , V_246 , V_230 ;
struct V_247 * V_248 ;
struct V_249 * V_249 ;
union V_250 * V_251 ;
T_1 * V_252 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_240 ; V_4 ++ ) {
if ( F_78 ( V_243 ) )
break;
F_72 ( 100 , 200 ) ;
}
if ( ! F_78 ( V_243 ) ) {
F_63 ( V_2 , L_33 ) ;
return - 1 ;
}
V_244 = F_79 ( * V_243 -> V_253 ) ;
V_245 = F_80 ( & V_243 -> V_254 ) ;
F_81 () ;
V_251 = (union V_250 * ) F_73 ( & V_243 -> V_254 ) ;
V_246 = V_243 -> V_255 & V_116 ;
V_249 = & V_243 -> V_256 [ V_246 ] ;
V_248 = & V_251 -> V_257 ;
V_230 = F_79 ( V_248 -> V_258 ) ;
V_252 = ( T_1 * ) ( F_82 ( V_249 -> V_162 ) +
V_248 -> V_259 + V_249 -> V_260 ) ;
for ( V_4 = V_141 ; V_4 < V_230 ; V_4 ++ )
if ( V_252 [ V_4 ] != ( unsigned char ) ( V_4 & 0xff ) ) {
F_63 ( V_2 , L_34 ) ;
F_83 ( V_243 , V_2 , 1 ) ;
return - 1 ;
}
F_83 ( V_243 , V_2 , 1 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 , T_2 V_261 )
{
struct V_61 V_98 ;
struct V_214 * V_215 = NULL ;
int V_106 = 0 , V_4 ;
T_2 V_262 ;
T_1 * V_263 ;
if ( ! F_26 ( V_2 -> V_76 ) ) {
F_63 ( V_2 , L_11 ) ;
return - V_32 ;
}
F_55 ( V_2 ) ;
memset ( & V_98 , 0 , sizeof( V_98 ) ) ;
V_98 . V_50 = true ;
V_98 . V_65 = V_264 ;
V_98 . V_261 = V_261 ;
V_2 -> V_41 -> V_34 -> V_75 ( V_2 -> V_43 , & V_98 ) ;
F_85 ( 500 ) ;
V_262 = V_2 -> V_76 -> V_138 + V_141 ;
V_215 = F_86 ( V_2 -> V_76 , V_262 ) ;
if ( ! V_215 ) {
F_17 ( V_2 , L_35 ) ;
V_106 = - V_234 ;
goto V_265;
}
V_263 = F_87 ( V_215 , V_262 ) ;
F_88 ( V_263 , V_2 -> V_76 -> V_266 ) ;
F_88 ( V_263 + V_267 , V_2 -> V_76 -> V_266 ) ;
memset ( V_263 + ( 2 * V_267 ) , 0x77 , ( V_141 - ( 2 * V_267 ) ) ) ;
for ( V_4 = V_141 ; V_4 < V_262 ; V_4 ++ )
V_263 [ V_4 ] = ( unsigned char ) ( V_4 & 0xff ) ;
V_106 = F_57 ( V_2 , V_215 ) ;
if ( V_106 )
goto V_265;
V_106 = F_77 ( V_2 ) ;
if ( V_106 )
goto V_265;
F_5 ( V_2 , V_268 , L_36 ) ;
V_265:
F_89 ( V_215 ) ;
memset ( & V_98 , 0 , sizeof( V_98 ) ) ;
V_98 . V_50 = true ;
V_98 . V_65 = V_264 ;
V_98 . V_261 = V_269 ;
V_2 -> V_41 -> V_34 -> V_75 ( V_2 -> V_43 , & V_98 ) ;
F_85 ( 500 ) ;
F_52 ( V_2 ) ;
return V_106 ;
}
static void F_90 ( struct V_13 * V_14 ,
struct V_270 * V_271 , T_3 * V_3 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
F_5 ( V_2 , V_23 ,
L_37 ,
( V_271 -> V_272 & V_273 ) ,
( V_271 -> V_272 & V_274 ) >> 2 ) ;
memset ( V_3 , 0 , sizeof( T_3 ) * V_22 ) ;
if ( V_271 -> V_272 & V_273 ) {
if ( F_84 ( V_2 ,
V_275 ) ) {
V_3 [ V_276 ] = 1 ;
V_271 -> V_272 |= V_277 ;
}
}
if ( V_2 -> V_41 -> V_34 -> V_278 -> V_279 ( V_2 -> V_43 ) ) {
V_3 [ V_280 ] = 1 ;
V_271 -> V_272 |= V_277 ;
}
if ( V_2 -> V_41 -> V_34 -> V_278 -> V_281 ( V_2 -> V_43 ) ) {
V_3 [ V_282 ] = 1 ;
V_271 -> V_272 |= V_277 ;
}
if ( V_2 -> V_41 -> V_34 -> V_278 -> V_283 ( V_2 -> V_43 ) ) {
V_3 [ V_284 ] = 1 ;
V_271 -> V_272 |= V_277 ;
}
if ( V_2 -> V_41 -> V_34 -> V_278 -> V_285 ( V_2 -> V_43 ) ) {
V_3 [ V_286 ] = 1 ;
V_271 -> V_272 |= V_277 ;
}
}
static int F_91 ( struct V_13 * V_14 ,
const struct V_287 * V_288 ,
const void * V_162 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
T_2 V_223 ;
switch ( V_288 -> V_289 ) {
case V_290 :
V_223 = * ( T_2 * ) V_162 ;
if ( V_223 < V_291 || V_223 > V_292 ) {
F_5 ( V_2 , V_23 ,
L_38 ,
V_291 , V_292 ) ;
return - V_32 ;
}
V_2 -> V_293 = * ( T_2 * ) V_162 ;
break;
default:
return - V_64 ;
}
return 0 ;
}
static int F_92 ( struct V_13 * V_14 ,
const struct V_287 * V_288 , void * V_162 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
switch ( V_288 -> V_289 ) {
case V_290 :
* ( T_2 * ) V_162 = V_2 -> V_293 ;
break;
default:
return - V_64 ;
}
return 0 ;
}
void F_93 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
if ( F_2 ( V_2 ) )
V_14 -> V_294 = & V_295 ;
else
V_14 -> V_294 = & V_296 ;
}
