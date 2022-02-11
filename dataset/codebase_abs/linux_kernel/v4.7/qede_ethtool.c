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
static void F_28 ( struct V_13 * V_14 ,
struct V_99 * V_100 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
V_100 -> V_101 = V_102 ;
V_100 -> V_103 = V_2 -> V_104 ;
V_100 -> V_105 = V_106 ;
V_100 -> V_107 = V_2 -> V_108 ;
}
static int F_29 ( struct V_13 * V_14 ,
struct V_99 * V_100 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
F_5 ( V_2 , ( V_109 | V_110 ) ,
L_11 ,
V_100 -> V_103 , V_100 -> V_107 ) ;
if ( V_100 -> V_103 > V_102 ||
V_100 -> V_103 < V_111 ||
V_100 -> V_107 > V_106 ||
V_100 -> V_107 < V_112 ) {
F_5 ( V_2 , ( V_109 | V_110 ) ,
L_12 ,
V_111 , V_102 ,
V_112 , V_106 ) ;
return - V_32 ;
}
V_2 -> V_104 = V_100 -> V_103 ;
V_2 -> V_108 = V_100 -> V_107 ;
if ( F_26 ( V_2 -> V_76 ) )
F_30 ( V_2 , NULL , NULL ) ;
return 0 ;
}
static void F_31 ( struct V_13 * V_14 ,
struct V_113 * V_114 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
struct V_39 V_40 ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_2 -> V_41 -> V_34 -> V_42 ( V_2 -> V_43 , & V_40 ) ;
if ( V_40 . V_115 & V_116 )
V_114 -> V_56 = true ;
if ( V_40 . V_115 & V_117 )
V_114 -> V_118 = true ;
if ( V_40 . V_115 & V_119 )
V_114 -> V_120 = true ;
F_5 ( V_2 , V_23 ,
L_13 ,
V_114 -> V_38 , V_114 -> V_56 , V_114 -> V_118 ,
V_114 -> V_120 ) ;
}
static int F_32 ( struct V_13 * V_14 ,
struct V_113 * V_114 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
struct V_61 V_62 ;
struct V_39 V_40 ;
if ( ! V_2 -> V_41 || ! V_2 -> V_41 -> V_34 -> V_63 ( V_2 -> V_43 ) ) {
F_17 ( V_2 ,
L_14 ) ;
return - V_64 ;
}
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_2 -> V_41 -> V_34 -> V_42 ( V_2 -> V_43 , & V_40 ) ;
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
V_62 . V_65 |= V_121 ;
if ( V_114 -> V_56 ) {
if ( ! ( V_40 . V_45 & V_122 ) ) {
F_17 ( V_2 , L_15 ) ;
return - V_32 ;
}
V_62 . V_115 |= V_116 ;
}
if ( V_114 -> V_118 )
V_62 . V_115 |= V_117 ;
if ( V_114 -> V_120 )
V_62 . V_115 |= V_119 ;
V_62 . V_50 = true ;
V_2 -> V_41 -> V_34 -> V_75 ( V_2 -> V_43 , & V_62 ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 , union V_123 * args )
{
V_2 -> V_76 -> V_124 = args -> V_124 ;
}
int F_34 ( struct V_13 * V_76 , int V_125 )
{
struct V_1 * V_2 = F_4 ( V_76 ) ;
union V_123 args ;
if ( ( V_125 > V_126 ) ||
( ( V_125 + V_127 ) < V_128 ) ) {
F_35 ( V_2 , L_16 ) ;
return - V_32 ;
}
F_5 ( V_2 , ( V_109 | V_110 ) ,
L_17 , V_125 ) ;
args . V_124 = V_125 ;
if ( F_26 ( V_2 -> V_76 ) )
F_30 ( V_2 , & F_33 , & args ) ;
F_33 ( V_2 , & args ) ;
return 0 ;
}
static void F_36 ( struct V_13 * V_14 ,
struct V_129 * V_130 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
V_130 -> V_131 = F_37 ( V_2 ) ;
V_130 -> V_132 = F_38 ( V_2 ) ;
}
static int F_39 ( struct V_13 * V_14 ,
struct V_129 * V_130 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
F_5 ( V_2 , ( V_109 | V_110 ) ,
L_18 ,
V_130 -> V_133 , V_130 -> V_134 ,
V_130 -> V_135 , V_130 -> V_132 ) ;
if ( V_130 -> V_133 || V_130 -> V_134 ||
V_130 -> V_135 || ( V_130 -> V_132 == 0 ) ||
( V_130 -> V_132 > F_37 ( V_2 ) ) ) {
F_5 ( V_2 , ( V_109 | V_110 ) ,
L_19 ) ;
return - V_32 ;
}
if ( V_130 -> V_132 == F_38 ( V_2 ) ) {
F_5 ( V_2 , ( V_109 | V_110 ) ,
L_20 ) ;
return 0 ;
}
if ( V_130 -> V_132 % V_2 -> V_33 . V_34 . V_35 ) {
F_5 ( V_2 , ( V_109 | V_110 ) ,
L_21 ,
V_2 -> V_33 . V_34 . V_35 ) ;
return - V_32 ;
}
V_2 -> V_136 = V_130 -> V_132 ;
if ( F_26 ( V_14 ) )
F_30 ( V_2 , NULL , NULL ) ;
return 0 ;
}
static int F_40 ( struct V_13 * V_14 ,
enum V_137 V_48 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
T_1 V_138 = 0 ;
switch ( V_48 ) {
case V_139 :
return 1 ;
case V_140 :
V_138 = V_141 ;
break;
case V_142 :
V_138 = V_143 ;
break;
case V_144 :
V_138 = V_145 ;
break;
}
V_2 -> V_41 -> V_34 -> V_146 ( V_2 -> V_43 , V_138 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , struct V_147 * V_78 )
{
V_78 -> V_148 = V_149 | V_150 ;
switch ( V_78 -> V_151 ) {
case V_152 :
case V_153 :
V_78 -> V_148 |= V_154 | V_155 ;
break;
case V_156 :
if ( V_2 -> V_157 . V_158 & V_159 )
V_78 -> V_148 |= V_154 | V_155 ;
break;
case V_160 :
if ( V_2 -> V_157 . V_158 & V_161 )
V_78 -> V_148 |= V_154 | V_155 ;
break;
case V_162 :
case V_163 :
break;
default:
V_78 -> V_148 = 0 ;
break;
}
return 0 ;
}
static int F_42 ( struct V_13 * V_14 , struct V_147 * V_78 ,
T_2 * T_4 V_164 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
switch ( V_78 -> V_38 ) {
case V_165 :
V_78 -> V_148 = V_2 -> V_30 ;
return 0 ;
case V_166 :
return F_41 ( V_2 , V_78 ) ;
default:
F_35 ( V_2 , L_22 ) ;
return - V_64 ;
}
}
static int F_43 ( struct V_1 * V_2 , struct V_147 * V_78 )
{
struct V_167 V_168 ;
T_1 V_169 = 0 , V_170 = 0 ;
F_5 ( V_2 , V_23 ,
L_23 ,
V_78 -> V_151 , V_78 -> V_148 ) ;
switch ( V_78 -> V_151 ) {
case V_152 :
case V_153 :
if ( V_78 -> V_148 ^ ( V_149 | V_150 |
V_154 | V_155 ) ) {
F_17 ( V_2 , L_22 ) ;
return - V_32 ;
}
return 0 ;
case V_156 :
if ( V_78 -> V_148 == ( V_149 | V_150 |
V_154 | V_155 ) ) {
V_169 = V_159 ;
F_5 ( V_2 , V_23 ,
L_24 ) ;
} else if ( V_78 -> V_148 == ( V_149 | V_150 ) ) {
V_170 = V_159 ;
F_5 ( V_2 , V_23 ,
L_25 ) ;
} else {
return - V_32 ;
}
break;
case V_160 :
if ( V_78 -> V_148 == ( V_149 | V_150 |
V_154 | V_155 ) ) {
V_169 = V_161 ;
F_5 ( V_2 , V_23 ,
L_24 ) ;
} else if ( V_78 -> V_148 == ( V_149 | V_150 ) ) {
V_170 = V_161 ;
F_5 ( V_2 , V_23 ,
L_25 ) ;
} else {
return - V_32 ;
}
break;
case V_162 :
case V_163 :
if ( V_78 -> V_148 ^ ( V_149 | V_150 ) ) {
F_17 ( V_2 , L_22 ) ;
return - V_32 ;
}
return 0 ;
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
if ( V_78 -> V_148 ) {
F_17 ( V_2 , L_22 ) ;
return - V_32 ;
}
return 0 ;
default:
return - V_32 ;
}
if ( V_2 -> V_157 . V_158 == ( ( V_2 -> V_157 . V_158 &
~ V_170 ) | V_169 ) )
return 0 ;
V_2 -> V_157 . V_158 = ( V_2 -> V_157 . V_158 & ~ V_170 ) |
V_169 ;
V_2 -> V_181 |= V_182 ;
if ( F_26 ( V_2 -> V_76 ) ) {
memset ( & V_168 , 0 , sizeof( V_168 ) ) ;
V_168 . V_183 = 1 ;
V_168 . V_184 = 0 ;
memcpy ( & V_168 . V_157 , & V_2 -> V_157 ,
sizeof( V_168 . V_157 ) ) ;
return V_2 -> V_41 -> V_185 ( V_2 -> V_43 ,
& V_168 ) ;
}
return 0 ;
}
static int F_44 ( struct V_13 * V_14 , struct V_147 * V_78 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
switch ( V_78 -> V_38 ) {
case V_186 :
return F_43 ( V_2 , V_78 ) ;
default:
F_17 ( V_2 , L_22 ) ;
return - V_64 ;
}
}
static T_2 F_45 ( struct V_13 * V_14 )
{
return V_187 ;
}
static T_2 F_46 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
return sizeof( V_2 -> V_157 . V_188 ) ;
}
static int F_47 ( struct V_13 * V_14 , T_2 * V_189 , T_1 * V_190 , T_1 * V_191 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
int V_4 ;
if ( V_191 )
* V_191 = V_192 ;
if ( ! V_189 )
return 0 ;
for ( V_4 = 0 ; V_4 < V_187 ; V_4 ++ )
V_189 [ V_4 ] = V_2 -> V_157 . V_193 [ V_4 ] ;
if ( V_190 )
memcpy ( V_190 , V_2 -> V_157 . V_188 ,
F_46 ( V_14 ) ) ;
return 0 ;
}
static int F_48 ( struct V_13 * V_14 , const T_2 * V_189 ,
const T_1 * V_190 , const T_1 V_191 )
{
struct V_167 V_168 ;
struct V_1 * V_2 = F_4 ( V_14 ) ;
int V_4 ;
if ( V_191 != V_194 && V_191 != V_192 )
return - V_64 ;
if ( ! V_189 && ! V_190 )
return 0 ;
if ( V_189 ) {
for ( V_4 = 0 ; V_4 < V_187 ; V_4 ++ )
V_2 -> V_157 . V_193 [ V_4 ] = V_189 [ V_4 ] ;
V_2 -> V_181 |= V_195 ;
}
if ( V_190 ) {
memcpy ( & V_2 -> V_157 . V_188 , V_190 ,
F_46 ( V_14 ) ) ;
V_2 -> V_181 |= V_196 ;
}
if ( F_26 ( V_2 -> V_76 ) ) {
memset ( & V_168 , 0 , sizeof( V_168 ) ) ;
V_168 . V_183 = 1 ;
V_168 . V_184 = 0 ;
memcpy ( & V_168 . V_157 , & V_2 -> V_157 ,
sizeof( V_168 . V_157 ) ) ;
return V_2 -> V_41 -> V_185 ( V_2 -> V_43 ,
& V_168 ) ;
}
return 0 ;
}
static void F_49 ( struct V_1 * V_2 )
{
int V_4 ;
if ( ! F_26 ( V_2 -> V_76 ) )
return;
F_50 (i) {
F_51 ( V_2 -> V_197 [ V_4 ] . V_198 , V_199 , 1 ) ;
F_52 ( & V_2 -> V_197 [ V_4 ] . V_200 ) ;
}
}
static void F_53 ( struct V_1 * V_2 )
{
int V_4 ;
F_50 (i) {
F_54 ( & V_2 -> V_197 [ V_4 ] . V_200 ) ;
F_51 ( V_2 -> V_197 [ V_4 ] . V_198 , V_201 , 0 ) ;
}
}
static int F_55 ( struct V_1 * V_2 ,
struct V_202 * V_203 )
{
struct V_204 * V_205 = & V_2 -> V_197 [ 0 ] . V_206 [ 0 ] ;
struct V_207 * V_208 ;
T_5 V_209 ;
int V_4 , V_210 , V_211 ;
V_210 = V_205 -> V_212 & V_106 ;
V_205 -> V_213 [ V_210 ] . V_203 = V_203 ;
V_208 = F_56 ( & V_205 -> V_214 ) ;
memset ( V_208 , 0 , sizeof( * V_208 ) ) ;
V_211 = 1 << V_215 ;
V_208 -> V_148 . V_216 . V_217 = V_211 ;
V_209 = F_57 ( & V_2 -> V_92 -> V_14 , V_203 -> V_148 ,
F_58 ( V_203 ) , V_218 ) ;
if ( F_59 ( F_60 ( & V_2 -> V_92 -> V_14 , V_209 ) ) ) {
F_61 ( V_2 , L_26 ) ;
return - V_219 ;
}
F_62 ( V_208 , V_209 , F_58 ( V_203 ) ) ;
V_208 -> V_148 . V_220 = 1 ;
V_205 -> V_212 ++ ;
V_211 = F_63 ( F_64 ( & V_205 -> V_214 ) ) ;
V_205 -> V_221 . V_148 . V_222 = V_211 ;
F_65 () ;
F_66 () ;
F_67 ( V_205 -> V_221 . V_223 , V_205 -> V_224 ) ;
F_68 () ;
for ( V_4 = 0 ; V_4 < V_225 ; V_4 ++ ) {
if ( F_69 ( V_205 ) )
break;
F_70 ( 100 , 200 ) ;
}
if ( ! F_69 ( V_205 ) ) {
F_61 ( V_2 , L_27 ) ;
return - 1 ;
}
V_208 = (struct V_207 * ) F_71 ( & V_205 -> V_214 ) ;
F_72 ( & V_2 -> V_92 -> V_14 , F_73 ( V_208 ) ,
F_74 ( V_208 ) , V_218 ) ;
V_205 -> V_226 ++ ;
V_205 -> V_213 [ V_210 ] . V_203 = NULL ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_227 * V_228 = V_2 -> V_197 [ 0 ] . V_228 ;
T_6 V_229 , V_230 , V_231 , V_232 ;
struct V_233 * V_234 ;
struct V_235 * V_235 ;
union V_236 * V_237 ;
T_1 * V_238 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_225 ; V_4 ++ ) {
if ( F_76 ( V_228 ) )
break;
F_70 ( 100 , 200 ) ;
}
if ( ! F_76 ( V_228 ) ) {
F_61 ( V_2 , L_28 ) ;
return - 1 ;
}
V_229 = F_77 ( * V_228 -> V_239 ) ;
V_230 = F_78 ( & V_228 -> V_240 ) ;
F_79 () ;
V_237 = (union V_236 * ) F_71 ( & V_228 -> V_240 ) ;
V_231 = V_228 -> V_241 & V_102 ;
V_235 = & V_228 -> V_242 [ V_231 ] ;
V_234 = & V_237 -> V_243 ;
V_232 = F_77 ( V_234 -> V_244 ) ;
V_238 = ( T_1 * ) ( F_80 ( V_235 -> V_148 ) +
V_234 -> V_245 + V_235 -> V_246 ) ;
for ( V_4 = V_127 ; V_4 < V_232 ; V_4 ++ )
if ( V_238 [ V_4 ] != ( unsigned char ) ( V_4 & 0xff ) ) {
F_61 ( V_2 , L_29 ) ;
F_81 ( V_228 , V_2 , 1 ) ;
return - 1 ;
}
F_81 ( V_228 , V_2 , 1 ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 , T_2 V_247 )
{
struct V_61 V_98 ;
struct V_202 * V_203 = NULL ;
int V_248 = 0 , V_4 ;
T_2 V_249 ;
T_1 * V_250 ;
if ( ! F_26 ( V_2 -> V_76 ) ) {
F_61 ( V_2 , L_30 ) ;
return - V_32 ;
}
F_53 ( V_2 ) ;
memset ( & V_98 , 0 , sizeof( V_98 ) ) ;
V_98 . V_50 = true ;
V_98 . V_65 = V_251 ;
V_98 . V_247 = V_247 ;
V_2 -> V_41 -> V_34 -> V_75 ( V_2 -> V_43 , & V_98 ) ;
F_83 ( 500 ) ;
V_249 = V_2 -> V_76 -> V_124 + V_127 ;
V_203 = F_84 ( V_2 -> V_76 , V_249 ) ;
if ( ! V_203 ) {
F_17 ( V_2 , L_31 ) ;
V_248 = - V_219 ;
goto V_252;
}
V_250 = F_85 ( V_203 , V_249 ) ;
F_86 ( V_250 , V_2 -> V_76 -> V_253 ) ;
F_86 ( V_250 + V_254 , V_2 -> V_76 -> V_253 ) ;
memset ( V_250 + ( 2 * V_254 ) , 0x77 , ( V_127 - ( 2 * V_254 ) ) ) ;
for ( V_4 = V_127 ; V_4 < V_249 ; V_4 ++ )
V_250 [ V_4 ] = ( unsigned char ) ( V_4 & 0xff ) ;
V_248 = F_55 ( V_2 , V_203 ) ;
if ( V_248 )
goto V_252;
V_248 = F_75 ( V_2 ) ;
if ( V_248 )
goto V_252;
F_5 ( V_2 , V_255 , L_32 ) ;
V_252:
F_87 ( V_203 ) ;
memset ( & V_98 , 0 , sizeof( V_98 ) ) ;
V_98 . V_50 = true ;
V_98 . V_65 = V_251 ;
V_98 . V_247 = V_256 ;
V_2 -> V_41 -> V_34 -> V_75 ( V_2 -> V_43 , & V_98 ) ;
F_83 ( 500 ) ;
F_49 ( V_2 ) ;
return V_248 ;
}
static void F_88 ( struct V_13 * V_14 ,
struct V_257 * V_258 , T_3 * V_3 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
F_5 ( V_2 , V_23 ,
L_33 ,
( V_258 -> V_259 & V_260 ) ,
( V_258 -> V_259 & V_261 ) >> 2 ) ;
memset ( V_3 , 0 , sizeof( T_3 ) * V_22 ) ;
if ( V_258 -> V_259 & V_260 ) {
if ( F_82 ( V_2 ,
V_262 ) ) {
V_3 [ V_263 ] = 1 ;
V_258 -> V_259 |= V_264 ;
}
}
if ( V_2 -> V_41 -> V_34 -> V_265 -> V_266 ( V_2 -> V_43 ) ) {
V_3 [ V_267 ] = 1 ;
V_258 -> V_259 |= V_264 ;
}
if ( V_2 -> V_41 -> V_34 -> V_265 -> V_268 ( V_2 -> V_43 ) ) {
V_3 [ V_269 ] = 1 ;
V_258 -> V_259 |= V_264 ;
}
if ( V_2 -> V_41 -> V_34 -> V_265 -> V_270 ( V_2 -> V_43 ) ) {
V_3 [ V_271 ] = 1 ;
V_258 -> V_259 |= V_264 ;
}
if ( V_2 -> V_41 -> V_34 -> V_265 -> V_272 ( V_2 -> V_43 ) ) {
V_3 [ V_273 ] = 1 ;
V_258 -> V_259 |= V_264 ;
}
}
void F_89 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
if ( F_2 ( V_2 ) )
V_14 -> V_274 = & V_275 ;
else
V_14 -> V_274 = & V_276 ;
}
