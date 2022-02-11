static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 * * V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
if ( V_4 -> V_8 )
sprintf ( * V_5 , L_1 ,
F_2 ( V_2 , V_4 ) ,
V_9 [ V_6 ] . string ) ;
else
sprintf ( * V_5 , L_2 , V_4 -> V_10 ,
V_9 [ V_6 ] . string ) ;
* V_5 += V_11 ;
}
}
static void F_3 ( struct V_1 * V_2 ,
struct V_12 * V_13 , T_1 * * V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_14 ; V_6 ++ ) {
sprintf ( * V_5 , L_2 , V_13 -> V_15 ,
V_16 [ V_6 ] . string ) ;
* V_5 += V_11 ;
}
}
static bool F_4 ( struct V_1 * V_2 , int V_17 )
{
return ( F_5 ( V_2 ) && F_6 ( V_17 ) ) ||
( F_7 ( V_2 ) && F_8 ( V_17 ) ) ||
( F_9 ( V_2 ) && F_10 ( V_17 ) ) ;
}
static void F_11 ( struct V_1 * V_2 , T_1 * V_5 )
{
struct V_18 * V_19 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < F_12 ( V_2 ) ; V_6 ++ ) {
V_19 = & V_2 -> V_20 [ V_6 ] ;
if ( V_19 -> type & V_21 )
F_3 ( V_2 , V_19 -> V_13 , & V_5 ) ;
if ( V_19 -> type & V_22 )
F_1 ( V_2 , V_19 -> V_23 , & V_5 ) ;
if ( V_19 -> type & V_24 )
F_1 ( V_2 , V_19 -> V_4 , & V_5 ) ;
}
for ( V_6 = 0 ; V_6 < V_25 ; V_6 ++ ) {
if ( F_4 ( V_2 , V_6 ) )
continue;
strcpy ( V_5 , V_26 [ V_6 ] . string ) ;
V_5 += V_11 ;
}
}
static void F_13 ( struct V_27 * V_28 , T_2 V_29 , T_1 * V_5 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
switch ( V_29 ) {
case V_30 :
F_11 ( V_2 , V_5 ) ;
break;
case V_31 :
memcpy ( V_5 , V_32 ,
V_11 * V_33 ) ;
break;
case V_34 :
memcpy ( V_5 , V_35 ,
V_11 * V_36 ) ;
break;
default:
F_15 ( V_2 , V_37 ,
L_3 , V_29 ) ;
}
}
static void F_16 ( struct V_3 * V_4 , T_3 * * V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
* * V_5 = * ( ( T_3 * ) ( ( ( void * ) V_4 ) + V_9 [ V_6 ] . V_38 ) ) ;
( * V_5 ) ++ ;
}
}
static void F_17 ( struct V_12 * V_13 , T_3 * * V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_14 ; V_6 ++ ) {
* * V_5 = * ( ( T_3 * ) ( ( ( void * ) V_13 ) + V_16 [ V_6 ] . V_38 ) ) ;
( * V_5 ) ++ ;
}
}
static void F_18 ( struct V_27 * V_28 ,
struct V_39 * V_40 , T_3 * V_5 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
struct V_18 * V_19 ;
int V_6 ;
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
for ( V_6 = 0 ; V_6 < F_12 ( V_2 ) ; V_6 ++ ) {
V_19 = & V_2 -> V_20 [ V_6 ] ;
if ( V_19 -> type & V_21 )
F_17 ( V_19 -> V_13 , & V_5 ) ;
if ( V_19 -> type & V_22 )
F_16 ( V_19 -> V_23 , & V_5 ) ;
if ( V_19 -> type & V_24 )
F_16 ( V_19 -> V_4 , & V_5 ) ;
}
for ( V_6 = 0 ; V_6 < V_25 ; V_6 ++ ) {
if ( F_4 ( V_2 , V_6 ) )
continue;
* V_5 = * ( ( T_3 * ) ( ( ( void * ) & V_2 -> V_40 ) +
V_26 [ V_6 ] . V_38 ) ) ;
V_5 ++ ;
}
F_21 ( V_2 ) ;
}
static int F_22 ( struct V_27 * V_28 , int V_29 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_41 = V_25 , V_6 ;
switch ( V_29 ) {
case V_30 :
for ( V_6 = 0 ; V_6 < V_25 ; V_6 ++ )
if ( F_4 ( V_2 , V_6 ) )
V_41 -- ;
V_41 += F_23 ( V_2 ) * V_7 ;
V_41 += F_24 ( V_2 ) * V_14 ;
if ( V_2 -> V_42 )
V_41 += F_24 ( V_2 ) * V_7 ;
return V_41 ;
case V_31 :
return V_33 ;
case V_34 :
if ( ! F_5 ( V_2 ) )
return V_36 ;
else
return 0 ;
default:
F_15 ( V_2 , V_37 ,
L_3 , V_29 ) ;
return - V_43 ;
}
}
static T_2 F_25 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
return ( ! ! ( V_2 -> V_44 . V_45 . V_46 > 1 ) ) << V_47 ;
}
static int F_26 ( struct V_27 * V_28 ,
struct V_48 * V_49 )
{
struct V_50 * V_51 = & V_49 -> V_51 ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
struct V_52 V_53 ;
F_20 ( V_2 ) ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_2 -> V_54 -> V_45 -> V_55 ( V_2 -> V_56 , & V_53 ) ;
F_27 ( V_49 , V_57 ) ;
F_28 (current_link.supported_caps, cmd, supported)
F_27 ( V_49 , V_58 ) ;
F_28 (current_link.advertised_caps, cmd, advertising)
F_27 ( V_49 , V_59 ) ;
F_28 (current_link.lp_caps, cmd, lp_advertising)
if ( ( V_2 -> V_60 == V_61 ) && ( V_53 . V_62 ) ) {
V_51 -> V_63 = V_53 . V_63 ;
V_51 -> V_64 = V_53 . V_64 ;
} else {
V_51 -> V_63 = V_65 ;
V_51 -> V_64 = V_66 ;
}
F_21 ( V_2 ) ;
V_51 -> V_67 = V_53 . V_67 ;
V_51 -> V_68 = ( V_53 . V_68 ) ? V_69 :
V_70 ;
return 0 ;
}
static int F_29 ( struct V_27 * V_28 ,
const struct V_48 * V_49 )
{
const struct V_50 * V_51 = & V_49 -> V_51 ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
struct V_52 V_53 ;
struct V_71 V_72 ;
if ( ! V_2 -> V_54 || ! V_2 -> V_54 -> V_45 -> V_73 ( V_2 -> V_56 ) ) {
F_30 ( V_2 , L_4 ) ;
return - V_74 ;
}
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_2 -> V_54 -> V_45 -> V_55 ( V_2 -> V_56 , & V_53 ) ;
V_72 . V_75 |= V_76 ;
V_72 . V_75 |= V_77 ;
if ( V_51 -> V_68 == V_69 ) {
if ( ! ( V_53 . V_78 & V_79 ) ) {
F_30 ( V_2 , L_5 ) ;
return - V_74 ;
}
V_72 . V_68 = true ;
V_72 . V_80 = 0 ;
F_31 (params.adv_speeds, cmd, advertising)
} else {
V_72 . V_75 |= V_81 ;
V_72 . V_68 = false ;
V_72 . V_80 = V_51 -> V_63 ;
switch ( V_51 -> V_63 ) {
case V_82 :
if ( ! ( V_53 . V_78 &
V_83 ) ) {
F_30 ( V_2 , L_6 ) ;
return - V_43 ;
}
V_72 . V_84 = V_83 ;
break;
case V_85 :
if ( ! ( V_53 . V_78 &
V_86 ) ) {
F_30 ( V_2 , L_7 ) ;
return - V_43 ;
}
V_72 . V_84 = V_86 ;
break;
case V_87 :
if ( ! ( V_53 . V_78 &
V_88 ) ) {
F_30 ( V_2 , L_8 ) ;
return - V_43 ;
}
V_72 . V_84 = V_88 ;
break;
case V_89 :
if ( ! ( V_53 . V_78 &
V_90 ) ) {
F_30 ( V_2 , L_9 ) ;
return - V_43 ;
}
V_72 . V_84 = V_90 ;
break;
case V_91 :
if ( ! ( V_53 . V_78 &
V_92 ) ) {
F_30 ( V_2 , L_10 ) ;
return - V_43 ;
}
V_72 . V_84 = V_92 ;
break;
case V_93 :
if ( ! ( V_53 . V_78 &
V_94 ) ) {
F_30 ( V_2 , L_11 ) ;
return - V_43 ;
}
V_72 . V_84 = V_94 ;
break;
default:
F_30 ( V_2 , L_12 , V_51 -> V_63 ) ;
return - V_43 ;
}
}
V_72 . V_62 = true ;
V_2 -> V_54 -> V_45 -> V_95 ( V_2 -> V_56 , & V_72 ) ;
return 0 ;
}
static void F_32 ( struct V_27 * V_96 ,
struct V_97 * V_98 )
{
char V_99 [ V_100 ] , V_101 [ V_100 ] ;
struct V_1 * V_2 = F_14 ( V_96 ) ;
F_33 ( V_98 -> V_102 , L_13 , sizeof( V_98 -> V_102 ) ) ;
F_33 ( V_98 -> V_103 , V_104 , sizeof( V_98 -> V_103 ) ) ;
snprintf ( V_101 , V_100 , L_14 ,
V_2 -> V_44 . V_45 . V_105 ,
V_2 -> V_44 . V_45 . V_106 ,
V_2 -> V_44 . V_45 . V_107 ,
V_2 -> V_44 . V_45 . V_108 ) ;
snprintf ( V_99 , V_100 , L_14 ,
( V_2 -> V_44 . V_45 . V_109 >> 24 ) & 0xFF ,
( V_2 -> V_44 . V_45 . V_109 >> 16 ) & 0xFF ,
( V_2 -> V_44 . V_45 . V_109 >> 8 ) & 0xFF ,
V_2 -> V_44 . V_45 . V_109 & 0xFF ) ;
if ( ( strlen ( V_101 ) + strlen ( V_99 ) + strlen ( L_15 ) ) <
sizeof( V_98 -> V_110 ) ) {
snprintf ( V_98 -> V_110 , sizeof( V_98 -> V_110 ) ,
L_16 , V_99 , V_101 ) ;
} else {
snprintf ( V_98 -> V_110 , sizeof( V_98 -> V_110 ) ,
L_17 , V_99 , V_101 ) ;
}
F_33 ( V_98 -> V_111 , F_34 ( V_2 -> V_112 ) , sizeof( V_98 -> V_111 ) ) ;
}
static void F_35 ( struct V_27 * V_96 , struct V_113 * V_114 )
{
struct V_1 * V_2 = F_14 ( V_96 ) ;
if ( V_2 -> V_44 . V_45 . V_115 ) {
V_114 -> V_57 = V_116 ;
V_114 -> V_117 = V_2 -> V_118 ? V_116 : 0 ;
}
}
static int F_36 ( struct V_27 * V_96 , struct V_113 * V_114 )
{
struct V_1 * V_2 = F_14 ( V_96 ) ;
bool V_119 ;
int V_120 ;
if ( V_114 -> V_117 & ~ V_116 ) {
F_30 ( V_2 ,
L_18 ) ;
return - V_43 ;
}
V_119 = ! ! ( V_114 -> V_117 & V_116 ) ;
if ( V_119 == V_2 -> V_118 )
return 0 ;
if ( ! V_2 -> V_44 . V_45 . V_115 ) {
F_30 ( V_2 , L_19 ) ;
return - V_43 ;
}
V_120 = V_2 -> V_54 -> V_45 -> V_121 ( V_2 -> V_56 , V_119 ) ;
if ( ! V_120 )
V_2 -> V_118 = V_119 ;
return V_120 ;
}
static T_2 F_37 ( struct V_27 * V_96 )
{
struct V_1 * V_2 = F_14 ( V_96 ) ;
return ( ( T_2 ) V_2 -> V_122 << V_123 ) | V_2 -> V_124 ;
}
static void F_38 ( struct V_27 * V_96 , T_2 V_125 )
{
struct V_1 * V_2 = F_14 ( V_96 ) ;
T_2 V_124 = 0 ;
T_1 V_122 = 0 ;
F_39 ( V_125 , & V_124 , & V_122 ) ;
V_2 -> V_122 = V_122 ;
V_2 -> V_124 = V_124 ;
V_2 -> V_54 -> V_45 -> V_126 ( V_2 -> V_56 ,
V_124 , V_122 ) ;
}
static int F_40 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
struct V_52 V_53 ;
struct V_71 V_127 ;
if ( ! V_2 -> V_54 || ! V_2 -> V_54 -> V_45 -> V_73 ( V_2 -> V_56 ) ) {
F_30 ( V_2 , L_4 ) ;
return - V_74 ;
}
if ( ! F_41 ( V_28 ) )
return 0 ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_2 -> V_54 -> V_45 -> V_55 ( V_2 -> V_56 , & V_53 ) ;
if ( ! V_53 . V_62 )
return 0 ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
V_127 . V_62 = false ;
V_2 -> V_54 -> V_45 -> V_95 ( V_2 -> V_56 , & V_127 ) ;
V_127 . V_62 = true ;
V_2 -> V_54 -> V_45 -> V_95 ( V_2 -> V_56 , & V_127 ) ;
return 0 ;
}
static T_2 F_42 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
struct V_52 V_53 ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_2 -> V_54 -> V_45 -> V_55 ( V_2 -> V_56 , & V_53 ) ;
return V_53 . V_62 ;
}
static int F_43 ( struct V_27 * V_28 ,
struct V_128 * V_129 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
T_4 V_130 , V_131 ;
memset ( V_129 , 0 , sizeof( struct V_128 ) ) ;
V_2 -> V_54 -> V_45 -> V_132 ( V_2 -> V_56 , & V_130 , & V_131 ) ;
V_129 -> V_133 = V_130 ;
V_129 -> V_134 = V_131 ;
return 0 ;
}
static int F_44 ( struct V_27 * V_28 ,
struct V_128 * V_129 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_6 , V_120 = 0 ;
T_4 V_130 , V_131 , V_135 ;
if ( ! F_41 ( V_28 ) ) {
F_30 ( V_2 , L_20 ) ;
return - V_43 ;
}
if ( V_129 -> V_133 > V_136 ||
V_129 -> V_134 > V_136 ) {
F_30 ( V_2 ,
L_21 ,
V_129 -> V_133 > V_136 ? L_22
: L_23 ,
V_136 ) ;
return - V_43 ;
}
V_130 = ( T_4 ) V_129 -> V_133 ;
V_131 = ( T_4 ) V_129 -> V_134 ;
F_45 (i) {
V_135 = V_2 -> V_20 [ V_6 ] . V_137 -> V_138 ;
V_120 = V_2 -> V_54 -> V_45 -> V_139 ( V_2 -> V_56 , V_130 , V_131 ,
( T_4 ) V_6 , V_135 ) ;
if ( V_120 ) {
F_30 ( V_2 , L_24 , V_120 ) ;
return V_120 ;
}
}
return V_120 ;
}
static void F_46 ( struct V_27 * V_28 ,
struct V_140 * V_141 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
V_141 -> V_142 = V_143 ;
V_141 -> V_144 = V_2 -> V_145 ;
V_141 -> V_146 = V_147 ;
V_141 -> V_148 = V_2 -> V_149 ;
}
static int F_47 ( struct V_27 * V_28 ,
struct V_140 * V_141 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
F_15 ( V_2 , ( V_150 | V_151 ) ,
L_25 ,
V_141 -> V_144 , V_141 -> V_148 ) ;
if ( V_141 -> V_144 > V_143 ||
V_141 -> V_144 < V_152 ||
V_141 -> V_148 > V_147 ||
V_141 -> V_148 < V_153 ) {
F_15 ( V_2 , ( V_150 | V_151 ) ,
L_26 ,
V_152 , V_143 ,
V_153 , V_147 ) ;
return - V_43 ;
}
V_2 -> V_145 = V_141 -> V_144 ;
V_2 -> V_149 = V_141 -> V_148 ;
F_48 ( V_2 , NULL , false ) ;
return 0 ;
}
static void F_49 ( struct V_27 * V_28 ,
struct V_154 * V_155 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
struct V_52 V_53 ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_2 -> V_54 -> V_45 -> V_55 ( V_2 -> V_56 , & V_53 ) ;
if ( V_53 . V_156 & V_157 )
V_155 -> V_68 = true ;
if ( V_53 . V_156 & V_158 )
V_155 -> V_159 = true ;
if ( V_53 . V_156 & V_160 )
V_155 -> V_161 = true ;
F_15 ( V_2 , V_37 ,
L_27 ,
V_155 -> V_49 , V_155 -> V_68 , V_155 -> V_159 ,
V_155 -> V_161 ) ;
}
static int F_50 ( struct V_27 * V_28 ,
struct V_154 * V_155 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
struct V_71 V_72 ;
struct V_52 V_53 ;
if ( ! V_2 -> V_54 || ! V_2 -> V_54 -> V_45 -> V_73 ( V_2 -> V_56 ) ) {
F_30 ( V_2 ,
L_28 ) ;
return - V_74 ;
}
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_2 -> V_54 -> V_45 -> V_55 ( V_2 -> V_56 , & V_53 ) ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . V_75 |= V_162 ;
if ( V_155 -> V_68 ) {
if ( ! ( V_53 . V_78 & V_79 ) ) {
F_30 ( V_2 , L_29 ) ;
return - V_43 ;
}
V_72 . V_156 |= V_157 ;
}
if ( V_155 -> V_159 )
V_72 . V_156 |= V_158 ;
if ( V_155 -> V_161 )
V_72 . V_156 |= V_160 ;
V_72 . V_62 = true ;
V_2 -> V_54 -> V_45 -> V_95 ( V_2 -> V_56 , & V_72 ) ;
return 0 ;
}
static void F_51 ( struct V_27 * V_96 ,
struct V_163 * V_164 , void * V_165 )
{
struct V_1 * V_2 = F_14 ( V_96 ) ;
V_164 -> V_103 = 0 ;
memset ( V_165 , 0 , V_164 -> V_166 ) ;
if ( V_2 -> V_54 && V_2 -> V_54 -> V_45 )
V_2 -> V_54 -> V_45 -> V_167 ( V_2 -> V_56 , V_165 ) ;
}
static int F_52 ( struct V_27 * V_96 )
{
struct V_1 * V_2 = F_14 ( V_96 ) ;
if ( V_2 -> V_54 && V_2 -> V_54 -> V_45 )
return V_2 -> V_54 -> V_45 -> V_168 ( V_2 -> V_56 ) ;
else
return - V_43 ;
}
static void F_53 ( struct V_1 * V_2 ,
struct V_169 * args )
{
V_2 -> V_96 -> V_170 = args -> V_171 . V_170 ;
}
int F_54 ( struct V_27 * V_96 , int V_172 )
{
struct V_1 * V_2 = F_14 ( V_96 ) ;
struct V_169 args ;
F_15 ( V_2 , ( V_150 | V_151 ) ,
L_30 , V_172 ) ;
args . V_171 . V_170 = V_172 ;
args . V_173 = & F_53 ;
F_48 ( V_2 , & args , false ) ;
V_2 -> V_54 -> V_45 -> V_174 ( V_2 -> V_56 , V_172 ) ;
return 0 ;
}
static void F_55 ( struct V_27 * V_28 ,
struct V_175 * V_176 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
V_176 -> V_177 = F_56 ( V_2 ) ;
V_176 -> V_178 = F_56 ( V_2 ) ;
V_176 -> V_179 = F_56 ( V_2 ) ;
V_176 -> V_180 = F_12 ( V_2 ) - V_2 -> V_181 -
V_2 -> V_182 ;
V_176 -> V_183 = V_2 -> V_181 ;
V_176 -> V_184 = V_2 -> V_182 ;
}
static int F_57 ( struct V_27 * V_28 ,
struct V_175 * V_176 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
T_2 V_185 ;
F_15 ( V_2 , ( V_150 | V_151 ) ,
L_31 ,
V_176 -> V_184 , V_176 -> V_183 ,
V_176 -> V_186 , V_176 -> V_180 ) ;
V_185 = V_176 -> V_184 + V_176 -> V_183 +
V_176 -> V_180 ;
if ( V_176 -> V_186 ) {
F_15 ( V_2 , ( V_150 | V_151 ) ,
L_32 ) ;
return - V_43 ;
}
if ( ! ( V_176 -> V_180 || ( V_176 -> V_184 &&
V_176 -> V_183 ) ) ) {
F_15 ( V_2 , ( V_150 | V_151 ) ,
L_33 ) ;
return - V_43 ;
}
if ( V_185 > F_56 ( V_2 ) ) {
F_15 ( V_2 , ( V_150 | V_151 ) ,
L_34 ,
V_185 , F_56 ( V_2 ) ) ;
return - V_43 ;
}
if ( ( V_185 == F_12 ( V_2 ) ) &&
( V_176 -> V_183 == V_2 -> V_181 ) &&
( V_176 -> V_184 == V_2 -> V_182 ) ) {
F_15 ( V_2 , ( V_150 | V_151 ) ,
L_35 ) ;
return 0 ;
}
if ( ( V_185 % V_2 -> V_44 . V_45 . V_46 ) ||
( V_176 -> V_183 % V_2 -> V_44 . V_45 . V_46 ) ||
( V_176 -> V_184 % V_2 -> V_44 . V_45 . V_46 ) ) {
F_15 ( V_2 , ( V_150 | V_151 ) ,
L_36 ,
V_2 -> V_44 . V_45 . V_46 ) ;
return - V_43 ;
}
V_2 -> V_187 = V_185 ;
V_2 -> V_188 = V_176 -> V_183 ;
V_2 -> V_189 = V_176 -> V_184 ;
if ( ( V_2 -> V_187 - V_2 -> V_188 ) != F_24 ( V_2 ) ) {
V_2 -> V_190 &= ~ V_191 ;
memset ( V_2 -> V_192 , 0 , sizeof( V_2 -> V_192 ) ) ;
}
F_48 ( V_2 , NULL , false ) ;
return 0 ;
}
static int F_58 ( struct V_27 * V_28 ,
struct V_193 * V_98 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
return F_59 ( V_2 , V_98 ) ;
}
static int F_60 ( struct V_27 * V_28 ,
enum V_194 V_60 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
T_1 V_195 = 0 ;
switch ( V_60 ) {
case V_196 :
return 1 ;
case V_197 :
V_195 = V_198 ;
break;
case V_199 :
V_195 = V_200 ;
break;
case V_201 :
V_195 = V_202 ;
break;
}
V_2 -> V_54 -> V_45 -> V_203 ( V_2 -> V_56 , V_195 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , struct V_204 * V_98 )
{
V_98 -> V_205 = V_206 | V_207 ;
switch ( V_98 -> V_208 ) {
case V_209 :
case V_210 :
V_98 -> V_205 |= V_211 | V_212 ;
break;
case V_213 :
if ( V_2 -> V_214 & V_215 )
V_98 -> V_205 |= V_211 | V_212 ;
break;
case V_216 :
if ( V_2 -> V_214 & V_217 )
V_98 -> V_205 |= V_211 | V_212 ;
break;
case V_218 :
case V_219 :
break;
default:
V_98 -> V_205 = 0 ;
break;
}
return 0 ;
}
static int F_62 ( struct V_27 * V_28 , struct V_204 * V_98 ,
T_2 * T_5 V_220 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
switch ( V_98 -> V_49 ) {
case V_221 :
V_98 -> V_205 = F_24 ( V_2 ) ;
return 0 ;
case V_222 :
return F_61 ( V_2 , V_98 ) ;
default:
F_63 ( V_2 , L_37 ) ;
return - V_74 ;
}
}
static int F_64 ( struct V_1 * V_2 , struct V_204 * V_98 )
{
struct V_223 * V_224 ;
T_1 V_225 = 0 , V_226 = 0 ;
int V_120 = 0 ;
F_15 ( V_2 , V_37 ,
L_38 ,
V_98 -> V_208 , V_98 -> V_205 ) ;
switch ( V_98 -> V_208 ) {
case V_209 :
case V_210 :
if ( V_98 -> V_205 ^ ( V_206 | V_207 |
V_211 | V_212 ) ) {
F_30 ( V_2 , L_37 ) ;
return - V_43 ;
}
return 0 ;
case V_213 :
if ( V_98 -> V_205 == ( V_206 | V_207 |
V_211 | V_212 ) ) {
V_225 = V_215 ;
F_15 ( V_2 , V_37 ,
L_39 ) ;
} else if ( V_98 -> V_205 == ( V_206 | V_207 ) ) {
V_226 = V_215 ;
F_15 ( V_2 , V_37 ,
L_40 ) ;
} else {
return - V_43 ;
}
break;
case V_216 :
if ( V_98 -> V_205 == ( V_206 | V_207 |
V_211 | V_212 ) ) {
V_225 = V_217 ;
F_15 ( V_2 , V_37 ,
L_39 ) ;
} else if ( V_98 -> V_205 == ( V_206 | V_207 ) ) {
V_226 = V_217 ;
F_15 ( V_2 , V_37 ,
L_40 ) ;
} else {
return - V_43 ;
}
break;
case V_218 :
case V_219 :
if ( V_98 -> V_205 ^ ( V_206 | V_207 ) ) {
F_30 ( V_2 , L_37 ) ;
return - V_43 ;
}
return 0 ;
case V_227 :
case V_228 :
case V_229 :
case V_230 :
case V_231 :
case V_232 :
case V_233 :
case V_234 :
case V_235 :
case V_236 :
if ( V_98 -> V_205 ) {
F_30 ( V_2 , L_37 ) ;
return - V_43 ;
}
return 0 ;
default:
return - V_43 ;
}
if ( V_2 -> V_214 == ( ( V_2 -> V_214 & ~ V_226 ) | V_225 ) )
return 0 ;
V_2 -> V_214 = ( ( V_2 -> V_214 & ~ V_226 ) | V_225 ) ;
V_2 -> V_190 |= V_237 ;
F_20 ( V_2 ) ;
if ( V_2 -> V_60 == V_61 ) {
V_224 = F_65 ( sizeof( * V_224 ) ) ;
if ( ! V_224 ) {
F_21 ( V_2 ) ;
return - V_238 ;
}
F_66 ( V_2 , & V_224 -> V_239 ,
& V_224 -> V_240 ) ;
V_120 = V_2 -> V_54 -> V_241 ( V_2 -> V_56 , V_224 ) ;
F_67 ( V_224 ) ;
}
F_21 ( V_2 ) ;
return V_120 ;
}
static int F_68 ( struct V_27 * V_28 , struct V_204 * V_98 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
switch ( V_98 -> V_49 ) {
case V_242 :
return F_64 ( V_2 , V_98 ) ;
default:
F_30 ( V_2 , L_37 ) ;
return - V_74 ;
}
}
static T_2 F_69 ( struct V_27 * V_28 )
{
return V_243 ;
}
static T_2 F_70 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
return sizeof( V_2 -> V_244 ) ;
}
static int F_71 ( struct V_27 * V_28 , T_2 * V_245 , T_1 * V_246 , T_1 * V_247 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_6 ;
if ( V_247 )
* V_247 = V_248 ;
if ( ! V_245 )
return 0 ;
for ( V_6 = 0 ; V_6 < V_243 ; V_6 ++ )
V_245 [ V_6 ] = V_2 -> V_192 [ V_6 ] ;
if ( V_246 )
memcpy ( V_246 , V_2 -> V_244 , F_70 ( V_28 ) ) ;
return 0 ;
}
static int F_72 ( struct V_27 * V_28 , const T_2 * V_245 ,
const T_1 * V_246 , const T_1 V_247 )
{
struct V_223 * V_224 ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_6 , V_120 = 0 ;
if ( V_2 -> V_44 . V_45 . V_46 > 1 ) {
F_30 ( V_2 ,
L_41 ) ;
return - V_74 ;
}
if ( V_247 != V_249 && V_247 != V_248 )
return - V_74 ;
if ( ! V_245 && ! V_246 )
return 0 ;
if ( V_245 ) {
for ( V_6 = 0 ; V_6 < V_243 ; V_6 ++ )
V_2 -> V_192 [ V_6 ] = V_245 [ V_6 ] ;
V_2 -> V_190 |= V_191 ;
}
if ( V_246 ) {
memcpy ( & V_2 -> V_244 , V_246 , F_70 ( V_28 ) ) ;
V_2 -> V_190 |= V_250 ;
}
F_20 ( V_2 ) ;
if ( V_2 -> V_60 == V_61 ) {
V_224 = F_65 ( sizeof( * V_224 ) ) ;
if ( ! V_224 ) {
F_21 ( V_2 ) ;
return - V_238 ;
}
F_66 ( V_2 , & V_224 -> V_239 ,
& V_224 -> V_240 ) ;
V_120 = V_2 -> V_54 -> V_241 ( V_2 -> V_56 , V_224 ) ;
F_67 ( V_224 ) ;
}
F_21 ( V_2 ) ;
return V_120 ;
}
static void F_73 ( struct V_1 * V_2 )
{
int V_6 ;
if ( ! F_41 ( V_2 -> V_96 ) )
return;
F_45 (i) {
F_74 ( V_2 -> V_20 [ V_6 ] . V_137 , V_251 , 1 ) ;
F_75 ( & V_2 -> V_20 [ V_6 ] . V_252 ) ;
}
}
static void F_76 ( struct V_1 * V_2 )
{
int V_6 ;
F_45 (i) {
F_77 ( & V_2 -> V_20 [ V_6 ] . V_252 ) ;
F_74 ( V_2 -> V_20 [ V_6 ] . V_137 , V_253 , 0 ) ;
}
}
static int F_78 ( struct V_1 * V_2 ,
struct V_254 * V_255 )
{
struct V_3 * V_4 = NULL ;
struct V_256 * V_257 ;
T_6 V_258 ;
int V_6 , V_259 ;
T_4 V_260 ;
F_45 (i) {
if ( V_2 -> V_20 [ V_6 ] . type & V_24 ) {
V_4 = V_2 -> V_20 [ V_6 ] . V_4 ;
break;
}
}
if ( ! V_4 ) {
F_79 ( V_2 , L_42 ) ;
return - 1 ;
}
V_259 = V_4 -> V_261 ;
V_4 -> V_262 . V_263 [ V_259 ] . V_255 = V_255 ;
V_257 = F_80 ( & V_4 -> V_264 ) ;
memset ( V_257 , 0 , sizeof( * V_257 ) ) ;
V_260 = 1 << V_265 ;
V_257 -> V_205 . V_266 . V_267 = V_260 ;
V_260 = V_255 -> V_166 & V_268 ;
V_260 = V_260 << V_269 ;
V_257 -> V_205 . V_267 |= F_81 ( V_260 ) ;
V_258 = F_82 ( & V_2 -> V_112 -> V_28 , V_255 -> V_205 ,
F_83 ( V_255 ) , V_270 ) ;
if ( F_84 ( F_85 ( & V_2 -> V_112 -> V_28 , V_258 ) ) ) {
F_79 ( V_2 , L_43 ) ;
return - V_238 ;
}
F_86 ( V_257 , V_258 , F_83 ( V_255 ) ) ;
V_257 -> V_205 . V_271 = 1 ;
V_4 -> V_261 = ( V_4 -> V_261 + 1 ) % V_4 -> V_272 ;
V_260 = F_87 ( & V_4 -> V_264 ) ;
V_4 -> V_273 . V_205 . V_274 = F_81 ( V_260 ) ;
F_88 () ;
F_89 () ;
F_90 ( V_4 -> V_273 . V_275 , V_4 -> V_276 ) ;
F_91 () ;
for ( V_6 = 0 ; V_6 < V_277 ; V_6 ++ ) {
if ( F_92 ( V_4 ) )
break;
F_93 ( 100 , 200 ) ;
}
if ( ! F_92 ( V_4 ) ) {
F_79 ( V_2 , L_44 ) ;
return - 1 ;
}
V_257 = (struct V_256 * ) F_94 ( & V_4 -> V_264 ) ;
F_95 ( & V_2 -> V_112 -> V_28 , F_96 ( V_257 ) ,
F_97 ( V_257 ) , V_270 ) ;
V_4 -> V_278 = ( V_4 -> V_278 + 1 ) % V_4 -> V_272 ;
V_4 -> V_262 . V_263 [ V_259 ] . V_255 = NULL ;
return 0 ;
}
static int F_98 ( struct V_1 * V_2 )
{
T_4 V_279 , V_280 , V_281 , V_166 ;
struct V_282 * V_283 ;
struct V_12 * V_13 = NULL ;
struct V_284 * V_284 ;
union V_285 * V_286 ;
int V_6 , V_287 , V_120 = 0 ;
T_1 * V_288 ;
F_45 (i) {
if ( V_2 -> V_20 [ V_6 ] . type & V_21 ) {
V_13 = V_2 -> V_20 [ V_6 ] . V_13 ;
break;
}
}
if ( ! V_13 ) {
F_79 ( V_2 , L_45 ) ;
return - 1 ;
}
for ( V_287 = 0 ; V_287 < V_277 ; V_287 ++ ) {
if ( ! F_99 ( V_13 ) ) {
F_93 ( 100 , 200 ) ;
continue;
}
V_279 = F_100 ( * V_13 -> V_289 ) ;
V_280 = F_101 ( & V_13 -> V_290 ) ;
F_102 () ;
V_286 = (union V_285 * ) F_94 ( & V_13 -> V_290 ) ;
V_281 = V_13 -> V_291 & V_143 ;
V_284 = & V_13 -> V_292 [ V_281 ] ;
V_283 = & V_286 -> V_293 ;
V_166 = F_100 ( V_283 -> V_294 ) ;
V_288 = ( T_1 * ) ( F_103 ( V_284 -> V_205 ) +
V_283 -> V_295 +
V_284 -> V_296 ) ;
if ( F_104 ( V_288 , V_2 -> V_96 -> V_297 ) &&
F_104 ( V_288 + V_298 ,
V_2 -> V_96 -> V_297 ) ) {
for ( V_6 = V_299 ; V_6 < V_166 ; V_6 ++ )
if ( V_288 [ V_6 ] != ( unsigned char ) ( V_6 & 0xff ) ) {
V_120 = - 1 ;
break;
}
F_105 ( V_13 , 1 ) ;
F_106 ( & V_13 -> V_290 ) ;
break;
}
F_30 ( V_2 , L_46 ) ;
F_105 ( V_13 , 1 ) ;
F_106 ( & V_13 -> V_290 ) ;
}
if ( V_287 == V_277 ) {
F_79 ( V_2 , L_47 ) ;
return - 1 ;
}
F_107 ( V_2 , V_13 ) ;
return V_120 ;
}
static int F_108 ( struct V_1 * V_2 , T_2 V_300 )
{
struct V_71 V_127 ;
struct V_254 * V_255 = NULL ;
int V_120 = 0 , V_6 ;
T_2 V_301 ;
T_1 * V_302 ;
if ( ! F_41 ( V_2 -> V_96 ) ) {
F_79 ( V_2 , L_20 ) ;
return - V_43 ;
}
F_76 ( V_2 ) ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
V_127 . V_62 = true ;
V_127 . V_75 = V_303 ;
V_127 . V_300 = V_300 ;
V_2 -> V_54 -> V_45 -> V_95 ( V_2 -> V_56 , & V_127 ) ;
F_109 ( 500 ) ;
V_301 = V_2 -> V_96 -> V_170 + V_299 ;
V_255 = F_110 ( V_2 -> V_96 , V_301 ) ;
if ( ! V_255 ) {
F_30 ( V_2 , L_48 ) ;
V_120 = - V_238 ;
goto V_304;
}
V_302 = F_111 ( V_255 , V_301 ) ;
F_112 ( V_302 , V_2 -> V_96 -> V_297 ) ;
F_112 ( V_302 + V_298 , V_2 -> V_96 -> V_297 ) ;
memset ( V_302 + ( 2 * V_298 ) , 0x77 , ( V_299 - ( 2 * V_298 ) ) ) ;
for ( V_6 = V_299 ; V_6 < V_301 ; V_6 ++ )
V_302 [ V_6 ] = ( unsigned char ) ( V_6 & 0xff ) ;
V_120 = F_78 ( V_2 , V_255 ) ;
if ( V_120 )
goto V_304;
V_120 = F_98 ( V_2 ) ;
if ( V_120 )
goto V_304;
F_15 ( V_2 , V_305 , L_49 ) ;
V_304:
F_113 ( V_255 ) ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
V_127 . V_62 = true ;
V_127 . V_75 = V_303 ;
V_127 . V_300 = V_306 ;
V_2 -> V_54 -> V_45 -> V_95 ( V_2 -> V_56 , & V_127 ) ;
F_109 ( 500 ) ;
F_73 ( V_2 ) ;
return V_120 ;
}
static void F_114 ( struct V_27 * V_28 ,
struct V_307 * V_308 , T_3 * V_5 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
F_15 ( V_2 , V_37 ,
L_50 ,
( V_308 -> V_309 & V_310 ) ,
( V_308 -> V_309 & V_311 ) >> 2 ) ;
memset ( V_5 , 0 , sizeof( T_3 ) * V_36 ) ;
if ( V_308 -> V_309 & V_310 ) {
if ( F_108 ( V_2 ,
V_312 ) ) {
V_5 [ V_313 ] = 1 ;
V_308 -> V_309 |= V_314 ;
}
}
if ( V_2 -> V_54 -> V_45 -> V_315 -> V_316 ( V_2 -> V_56 ) ) {
V_5 [ V_317 ] = 1 ;
V_308 -> V_309 |= V_314 ;
}
if ( V_2 -> V_54 -> V_45 -> V_315 -> V_318 ( V_2 -> V_56 ) ) {
V_5 [ V_319 ] = 1 ;
V_308 -> V_309 |= V_314 ;
}
if ( V_2 -> V_54 -> V_45 -> V_315 -> V_320 ( V_2 -> V_56 ) ) {
V_5 [ V_321 ] = 1 ;
V_308 -> V_309 |= V_314 ;
}
if ( V_2 -> V_54 -> V_45 -> V_315 -> V_322 ( V_2 -> V_56 ) ) {
V_5 [ V_323 ] = 1 ;
V_308 -> V_309 |= V_314 ;
}
if ( V_2 -> V_54 -> V_45 -> V_315 -> V_324 ( V_2 -> V_56 ) ) {
V_5 [ V_325 ] = 1 ;
V_308 -> V_309 |= V_314 ;
}
}
static int F_115 ( struct V_27 * V_28 ,
const struct V_326 * V_327 ,
const void * V_205 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
T_2 V_260 ;
switch ( V_327 -> V_328 ) {
case V_329 :
V_260 = * ( T_2 * ) V_205 ;
if ( V_260 < V_330 || V_260 > V_331 ) {
F_15 ( V_2 , V_37 ,
L_51 ,
V_330 , V_331 ) ;
return - V_43 ;
}
V_2 -> V_332 = * ( T_2 * ) V_205 ;
break;
default:
return - V_74 ;
}
return 0 ;
}
static int F_116 ( struct V_27 * V_28 ,
const struct V_326 * V_327 , void * V_205 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
switch ( V_327 -> V_328 ) {
case V_329 :
* ( T_2 * ) V_205 = V_2 -> V_332 ;
break;
default:
return - V_74 ;
}
return 0 ;
}
void F_117 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
if ( F_5 ( V_2 ) )
V_28 -> V_333 = & V_334 ;
else
V_28 -> V_333 = & V_335 ;
}
