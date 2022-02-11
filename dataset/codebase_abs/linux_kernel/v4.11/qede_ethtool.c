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
static void F_4 ( struct V_1 * V_2 , T_1 * V_5 )
{
struct V_17 * V_18 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < F_5 ( V_2 ) ; V_6 ++ ) {
V_18 = & V_2 -> V_19 [ V_6 ] ;
if ( V_18 -> type & V_20 )
F_3 ( V_2 , V_18 -> V_13 , & V_5 ) ;
if ( V_18 -> type & V_21 )
F_1 ( V_2 , V_18 -> V_22 , & V_5 ) ;
if ( V_18 -> type & V_23 )
F_1 ( V_2 , V_18 -> V_4 , & V_5 ) ;
}
for ( V_6 = 0 ; V_6 < V_24 ; V_6 ++ ) {
if ( F_6 ( V_2 ) && V_25 [ V_6 ] . V_26 )
continue;
strcpy ( V_5 , V_25 [ V_6 ] . string ) ;
V_5 += V_11 ;
}
}
static void F_7 ( struct V_27 * V_28 , T_2 V_29 , T_1 * V_5 )
{
struct V_1 * V_2 = F_8 ( V_28 ) ;
switch ( V_29 ) {
case V_30 :
F_4 ( V_2 , V_5 ) ;
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
F_9 ( V_2 , V_37 ,
L_3 , V_29 ) ;
}
}
static void F_10 ( struct V_3 * V_4 , T_3 * * V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
* * V_5 = * ( ( T_3 * ) ( ( ( void * ) V_4 ) + V_9 [ V_6 ] . V_38 ) ) ;
( * V_5 ) ++ ;
}
}
static void F_11 ( struct V_12 * V_13 , T_3 * * V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_14 ; V_6 ++ ) {
* * V_5 = * ( ( T_3 * ) ( ( ( void * ) V_13 ) + V_16 [ V_6 ] . V_38 ) ) ;
( * V_5 ) ++ ;
}
}
static void F_12 ( struct V_27 * V_28 ,
struct V_39 * V_40 , T_3 * V_5 )
{
struct V_1 * V_2 = F_8 ( V_28 ) ;
struct V_17 * V_18 ;
int V_6 ;
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
for ( V_6 = 0 ; V_6 < F_5 ( V_2 ) ; V_6 ++ ) {
V_18 = & V_2 -> V_19 [ V_6 ] ;
if ( V_18 -> type & V_20 )
F_11 ( V_18 -> V_13 , & V_5 ) ;
if ( V_18 -> type & V_21 )
F_10 ( V_18 -> V_22 , & V_5 ) ;
if ( V_18 -> type & V_23 )
F_10 ( V_18 -> V_4 , & V_5 ) ;
}
for ( V_6 = 0 ; V_6 < V_24 ; V_6 ++ ) {
if ( F_6 ( V_2 ) && V_25 [ V_6 ] . V_26 )
continue;
* V_5 = * ( ( T_3 * ) ( ( ( void * ) & V_2 -> V_40 ) +
V_25 [ V_6 ] . V_38 ) ) ;
V_5 ++ ;
}
F_15 ( V_2 ) ;
}
static int F_16 ( struct V_27 * V_28 , int V_29 )
{
struct V_1 * V_2 = F_8 ( V_28 ) ;
int V_41 = V_24 ;
switch ( V_29 ) {
case V_30 :
if ( F_6 ( V_2 ) ) {
int V_6 ;
for ( V_6 = 0 ; V_6 < V_24 ; V_6 ++ )
if ( V_25 [ V_6 ] . V_26 )
V_41 -- ;
}
V_41 += F_17 ( V_2 ) * V_7 ;
V_41 += F_18 ( V_2 ) * V_14 ;
if ( V_2 -> V_42 )
V_41 += F_18 ( V_2 ) * V_7 ;
return V_41 ;
case V_31 :
return V_33 ;
case V_34 :
if ( ! F_6 ( V_2 ) )
return V_36 ;
else
return 0 ;
default:
F_9 ( V_2 , V_37 ,
L_3 , V_29 ) ;
return - V_43 ;
}
}
static T_2 F_19 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_8 ( V_28 ) ;
return ( ! ! ( V_2 -> V_44 . V_45 . V_46 > 1 ) ) << V_47 ;
}
static int F_20 ( struct V_27 * V_28 ,
struct V_48 * V_49 )
{
struct V_50 * V_51 = & V_49 -> V_51 ;
struct V_1 * V_2 = F_8 ( V_28 ) ;
struct V_52 V_53 ;
F_14 ( V_2 ) ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_2 -> V_54 -> V_45 -> V_55 ( V_2 -> V_56 , & V_53 ) ;
F_21 ( V_49 , V_57 ) ;
F_22 (current_link.supported_caps, cmd, supported)
F_21 ( V_49 , V_58 ) ;
F_22 (current_link.advertised_caps, cmd, advertising)
F_21 ( V_49 , V_59 ) ;
F_22 (current_link.lp_caps, cmd, lp_advertising)
if ( ( V_2 -> V_60 == V_61 ) && ( V_53 . V_62 ) ) {
V_51 -> V_63 = V_53 . V_63 ;
V_51 -> V_64 = V_53 . V_64 ;
} else {
V_51 -> V_63 = V_65 ;
V_51 -> V_64 = V_66 ;
}
F_15 ( V_2 ) ;
V_51 -> V_67 = V_53 . V_67 ;
V_51 -> V_68 = ( V_53 . V_68 ) ? V_69 :
V_70 ;
return 0 ;
}
static int F_23 ( struct V_27 * V_28 ,
const struct V_48 * V_49 )
{
const struct V_50 * V_51 = & V_49 -> V_51 ;
struct V_1 * V_2 = F_8 ( V_28 ) ;
struct V_52 V_53 ;
struct V_71 V_72 ;
if ( ! V_2 -> V_54 || ! V_2 -> V_54 -> V_45 -> V_73 ( V_2 -> V_56 ) ) {
F_24 ( V_2 , L_4 ) ;
return - V_74 ;
}
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_2 -> V_54 -> V_45 -> V_55 ( V_2 -> V_56 , & V_53 ) ;
V_72 . V_75 |= V_76 ;
V_72 . V_75 |= V_77 ;
if ( V_51 -> V_68 == V_69 ) {
V_72 . V_68 = true ;
V_72 . V_78 = 0 ;
F_25 (params.adv_speeds, cmd, advertising)
} else {
V_72 . V_75 |= V_79 ;
V_72 . V_68 = false ;
V_72 . V_78 = V_51 -> V_63 ;
switch ( V_51 -> V_63 ) {
case V_80 :
if ( ! ( V_53 . V_81 &
V_82 ) ) {
F_24 ( V_2 , L_5 ) ;
return - V_43 ;
}
V_72 . V_83 = V_82 ;
break;
case V_84 :
if ( ! ( V_53 . V_81 &
V_85 ) ) {
F_24 ( V_2 , L_6 ) ;
return - V_43 ;
}
V_72 . V_83 = V_85 ;
break;
case V_86 :
if ( ! ( V_53 . V_81 &
V_87 ) ) {
F_24 ( V_2 , L_7 ) ;
return - V_43 ;
}
V_72 . V_83 = V_87 ;
break;
case V_88 :
if ( ! ( V_53 . V_81 &
V_89 ) ) {
F_24 ( V_2 , L_8 ) ;
return - V_43 ;
}
V_72 . V_83 = V_89 ;
break;
case V_90 :
if ( ! ( V_53 . V_81 &
V_91 ) ) {
F_24 ( V_2 , L_9 ) ;
return - V_43 ;
}
V_72 . V_83 = V_91 ;
break;
default:
F_24 ( V_2 , L_10 , V_51 -> V_63 ) ;
return - V_43 ;
}
}
V_72 . V_62 = true ;
V_2 -> V_54 -> V_45 -> V_92 ( V_2 -> V_56 , & V_72 ) ;
return 0 ;
}
static void F_26 ( struct V_27 * V_93 ,
struct V_94 * V_95 )
{
char V_96 [ V_97 ] , V_98 [ V_97 ] ;
struct V_1 * V_2 = F_8 ( V_93 ) ;
F_27 ( V_95 -> V_99 , L_11 , sizeof( V_95 -> V_99 ) ) ;
F_27 ( V_95 -> V_100 , V_101 , sizeof( V_95 -> V_100 ) ) ;
snprintf ( V_98 , V_97 , L_12 ,
V_2 -> V_44 . V_45 . V_102 ,
V_2 -> V_44 . V_45 . V_103 ,
V_2 -> V_44 . V_45 . V_104 ,
V_2 -> V_44 . V_45 . V_105 ) ;
snprintf ( V_96 , V_97 , L_12 ,
( V_2 -> V_44 . V_45 . V_106 >> 24 ) & 0xFF ,
( V_2 -> V_44 . V_45 . V_106 >> 16 ) & 0xFF ,
( V_2 -> V_44 . V_45 . V_106 >> 8 ) & 0xFF ,
V_2 -> V_44 . V_45 . V_106 & 0xFF ) ;
if ( ( strlen ( V_98 ) + strlen ( V_96 ) + strlen ( L_13 ) ) <
sizeof( V_95 -> V_107 ) ) {
snprintf ( V_95 -> V_107 , sizeof( V_95 -> V_107 ) ,
L_14 , V_96 , V_98 ) ;
} else {
snprintf ( V_95 -> V_107 , sizeof( V_95 -> V_107 ) ,
L_15 , V_96 , V_98 ) ;
}
F_27 ( V_95 -> V_108 , F_28 ( V_2 -> V_109 ) , sizeof( V_95 -> V_108 ) ) ;
}
static void F_29 ( struct V_27 * V_93 , struct V_110 * V_111 )
{
struct V_1 * V_2 = F_8 ( V_93 ) ;
if ( V_2 -> V_44 . V_45 . V_112 ) {
V_111 -> V_57 = V_113 ;
V_111 -> V_114 = V_2 -> V_115 ? V_113 : 0 ;
}
}
static int F_30 ( struct V_27 * V_93 , struct V_110 * V_111 )
{
struct V_1 * V_2 = F_8 ( V_93 ) ;
bool V_116 ;
int V_117 ;
if ( V_111 -> V_114 & ~ V_113 ) {
F_24 ( V_2 ,
L_16 ) ;
return - V_43 ;
}
V_116 = ! ! ( V_111 -> V_114 & V_113 ) ;
if ( V_116 == V_2 -> V_115 )
return 0 ;
if ( ! V_2 -> V_44 . V_45 . V_112 ) {
F_24 ( V_2 , L_17 ) ;
return - V_43 ;
}
V_117 = V_2 -> V_54 -> V_45 -> V_118 ( V_2 -> V_56 , V_116 ) ;
if ( ! V_117 )
V_2 -> V_115 = V_116 ;
return V_117 ;
}
static T_2 F_31 ( struct V_27 * V_93 )
{
struct V_1 * V_2 = F_8 ( V_93 ) ;
return ( ( T_2 ) V_2 -> V_119 << V_120 ) | V_2 -> V_121 ;
}
static void F_32 ( struct V_27 * V_93 , T_2 V_122 )
{
struct V_1 * V_2 = F_8 ( V_93 ) ;
T_2 V_121 = 0 ;
T_1 V_119 = 0 ;
F_33 ( V_122 , & V_121 , & V_119 ) ;
V_2 -> V_119 = V_119 ;
V_2 -> V_121 = V_121 ;
V_2 -> V_54 -> V_45 -> V_123 ( V_2 -> V_56 ,
V_121 , V_119 ) ;
}
static int F_34 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_8 ( V_28 ) ;
struct V_52 V_53 ;
struct V_71 V_124 ;
if ( ! V_2 -> V_54 || ! V_2 -> V_54 -> V_45 -> V_73 ( V_2 -> V_56 ) ) {
F_24 ( V_2 , L_4 ) ;
return - V_74 ;
}
if ( ! F_35 ( V_28 ) )
return 0 ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_2 -> V_54 -> V_45 -> V_55 ( V_2 -> V_56 , & V_53 ) ;
if ( ! V_53 . V_62 )
return 0 ;
memset ( & V_124 , 0 , sizeof( V_124 ) ) ;
V_124 . V_62 = false ;
V_2 -> V_54 -> V_45 -> V_92 ( V_2 -> V_56 , & V_124 ) ;
V_124 . V_62 = true ;
V_2 -> V_54 -> V_45 -> V_92 ( V_2 -> V_56 , & V_124 ) ;
return 0 ;
}
static T_2 F_36 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_8 ( V_28 ) ;
struct V_52 V_53 ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_2 -> V_54 -> V_45 -> V_55 ( V_2 -> V_56 , & V_53 ) ;
return V_53 . V_62 ;
}
static int F_37 ( struct V_27 * V_28 ,
struct V_125 * V_126 )
{
struct V_1 * V_2 = F_8 ( V_28 ) ;
T_4 V_127 , V_128 ;
memset ( V_126 , 0 , sizeof( struct V_125 ) ) ;
V_2 -> V_54 -> V_45 -> V_129 ( V_2 -> V_56 , & V_127 , & V_128 ) ;
V_126 -> V_130 = V_127 ;
V_126 -> V_131 = V_128 ;
return 0 ;
}
static int F_38 ( struct V_27 * V_28 ,
struct V_125 * V_126 )
{
struct V_1 * V_2 = F_8 ( V_28 ) ;
int V_6 , V_117 = 0 ;
T_4 V_127 , V_128 ;
T_1 V_132 ;
if ( ! F_35 ( V_28 ) ) {
F_24 ( V_2 , L_18 ) ;
return - V_43 ;
}
if ( V_126 -> V_130 > V_133 ||
V_126 -> V_131 > V_133 ) {
F_24 ( V_2 ,
L_19 ,
V_126 -> V_130 > V_133 ? L_20
: L_21 ,
V_133 ) ;
return - V_43 ;
}
V_127 = ( T_4 ) V_126 -> V_130 ;
V_128 = ( T_4 ) V_126 -> V_131 ;
F_39 (i) {
V_132 = V_2 -> V_19 [ V_6 ] . V_134 -> V_135 ;
V_117 = V_2 -> V_54 -> V_45 -> V_136 ( V_2 -> V_56 , V_127 , V_128 ,
( T_1 ) V_6 , V_132 ) ;
if ( V_117 ) {
F_24 ( V_2 , L_22 , V_117 ) ;
return V_117 ;
}
}
return V_117 ;
}
static void F_40 ( struct V_27 * V_28 ,
struct V_137 * V_138 )
{
struct V_1 * V_2 = F_8 ( V_28 ) ;
V_138 -> V_139 = V_140 ;
V_138 -> V_141 = V_2 -> V_142 ;
V_138 -> V_143 = V_144 ;
V_138 -> V_145 = V_2 -> V_146 ;
}
static int F_41 ( struct V_27 * V_28 ,
struct V_137 * V_138 )
{
struct V_1 * V_2 = F_8 ( V_28 ) ;
F_9 ( V_2 , ( V_147 | V_148 ) ,
L_23 ,
V_138 -> V_141 , V_138 -> V_145 ) ;
if ( V_138 -> V_141 > V_140 ||
V_138 -> V_141 < V_149 ||
V_138 -> V_145 > V_144 ||
V_138 -> V_145 < V_150 ) {
F_9 ( V_2 , ( V_147 | V_148 ) ,
L_24 ,
V_149 , V_140 ,
V_150 , V_144 ) ;
return - V_43 ;
}
V_2 -> V_142 = V_138 -> V_141 ;
V_2 -> V_146 = V_138 -> V_145 ;
F_42 ( V_2 , NULL , false ) ;
return 0 ;
}
static void F_43 ( struct V_27 * V_28 ,
struct V_151 * V_152 )
{
struct V_1 * V_2 = F_8 ( V_28 ) ;
struct V_52 V_53 ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_2 -> V_54 -> V_45 -> V_55 ( V_2 -> V_56 , & V_53 ) ;
if ( V_53 . V_153 & V_154 )
V_152 -> V_68 = true ;
if ( V_53 . V_153 & V_155 )
V_152 -> V_156 = true ;
if ( V_53 . V_153 & V_157 )
V_152 -> V_158 = true ;
F_9 ( V_2 , V_37 ,
L_25 ,
V_152 -> V_49 , V_152 -> V_68 , V_152 -> V_156 ,
V_152 -> V_158 ) ;
}
static int F_44 ( struct V_27 * V_28 ,
struct V_151 * V_152 )
{
struct V_1 * V_2 = F_8 ( V_28 ) ;
struct V_71 V_72 ;
struct V_52 V_53 ;
if ( ! V_2 -> V_54 || ! V_2 -> V_54 -> V_45 -> V_73 ( V_2 -> V_56 ) ) {
F_24 ( V_2 ,
L_26 ) ;
return - V_74 ;
}
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_2 -> V_54 -> V_45 -> V_55 ( V_2 -> V_56 , & V_53 ) ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . V_75 |= V_159 ;
if ( V_152 -> V_68 ) {
if ( ! ( V_53 . V_81 & V_160 ) ) {
F_24 ( V_2 , L_27 ) ;
return - V_43 ;
}
V_72 . V_153 |= V_154 ;
}
if ( V_152 -> V_156 )
V_72 . V_153 |= V_155 ;
if ( V_152 -> V_158 )
V_72 . V_153 |= V_157 ;
V_72 . V_62 = true ;
V_2 -> V_54 -> V_45 -> V_92 ( V_2 -> V_56 , & V_72 ) ;
return 0 ;
}
static void F_45 ( struct V_27 * V_93 ,
struct V_161 * V_162 , void * V_163 )
{
struct V_1 * V_2 = F_8 ( V_93 ) ;
V_162 -> V_100 = 0 ;
memset ( V_163 , 0 , V_162 -> V_164 ) ;
if ( V_2 -> V_54 && V_2 -> V_54 -> V_45 )
V_2 -> V_54 -> V_45 -> V_165 ( V_2 -> V_56 , V_163 ) ;
}
static int F_46 ( struct V_27 * V_93 )
{
struct V_1 * V_2 = F_8 ( V_93 ) ;
if ( V_2 -> V_54 && V_2 -> V_54 -> V_45 )
return V_2 -> V_54 -> V_45 -> V_166 ( V_2 -> V_56 ) ;
else
return - V_43 ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_167 * args )
{
V_2 -> V_93 -> V_168 = args -> V_169 . V_168 ;
}
int F_48 ( struct V_27 * V_93 , int V_170 )
{
struct V_1 * V_2 = F_8 ( V_93 ) ;
struct V_167 args ;
F_9 ( V_2 , ( V_147 | V_148 ) ,
L_28 , V_170 ) ;
args . V_169 . V_168 = V_170 ;
args . V_171 = & F_47 ;
F_42 ( V_2 , & args , false ) ;
V_2 -> V_54 -> V_45 -> V_172 ( V_2 -> V_56 , V_170 ) ;
return 0 ;
}
static void F_49 ( struct V_27 * V_28 ,
struct V_173 * V_174 )
{
struct V_1 * V_2 = F_8 ( V_28 ) ;
V_174 -> V_175 = F_50 ( V_2 ) ;
V_174 -> V_176 = F_50 ( V_2 ) ;
V_174 -> V_177 = F_50 ( V_2 ) ;
V_174 -> V_178 = F_5 ( V_2 ) - V_2 -> V_179 -
V_2 -> V_180 ;
V_174 -> V_181 = V_2 -> V_179 ;
V_174 -> V_182 = V_2 -> V_180 ;
}
static int F_51 ( struct V_27 * V_28 ,
struct V_173 * V_174 )
{
struct V_1 * V_2 = F_8 ( V_28 ) ;
T_2 V_183 ;
F_9 ( V_2 , ( V_147 | V_148 ) ,
L_29 ,
V_174 -> V_182 , V_174 -> V_181 ,
V_174 -> V_184 , V_174 -> V_178 ) ;
V_183 = V_174 -> V_182 + V_174 -> V_181 +
V_174 -> V_178 ;
if ( V_174 -> V_184 ) {
F_9 ( V_2 , ( V_147 | V_148 ) ,
L_30 ) ;
return - V_43 ;
}
if ( ! ( V_174 -> V_178 || ( V_174 -> V_182 &&
V_174 -> V_181 ) ) ) {
F_9 ( V_2 , ( V_147 | V_148 ) ,
L_31 ) ;
return - V_43 ;
}
if ( V_183 > F_50 ( V_2 ) ) {
F_9 ( V_2 , ( V_147 | V_148 ) ,
L_32 ,
V_183 , F_50 ( V_2 ) ) ;
return - V_43 ;
}
if ( ( V_183 == F_5 ( V_2 ) ) &&
( V_174 -> V_181 == V_2 -> V_179 ) &&
( V_174 -> V_182 == V_2 -> V_180 ) ) {
F_9 ( V_2 , ( V_147 | V_148 ) ,
L_33 ) ;
return 0 ;
}
if ( ( V_183 % V_2 -> V_44 . V_45 . V_46 ) ||
( V_174 -> V_181 % V_2 -> V_44 . V_45 . V_46 ) ||
( V_174 -> V_182 % V_2 -> V_44 . V_45 . V_46 ) ) {
F_9 ( V_2 , ( V_147 | V_148 ) ,
L_34 ,
V_2 -> V_44 . V_45 . V_46 ) ;
return - V_43 ;
}
V_2 -> V_185 = V_183 ;
V_2 -> V_186 = V_174 -> V_181 ;
V_2 -> V_187 = V_174 -> V_182 ;
if ( ( V_2 -> V_185 - V_2 -> V_186 ) != F_18 ( V_2 ) ) {
V_2 -> V_188 &= ~ V_189 ;
memset ( V_2 -> V_190 , 0 , sizeof( V_2 -> V_190 ) ) ;
}
F_42 ( V_2 , NULL , false ) ;
return 0 ;
}
static int F_52 ( struct V_27 * V_28 ,
struct V_191 * V_95 )
{
struct V_1 * V_2 = F_8 ( V_28 ) ;
return F_53 ( V_2 , V_95 ) ;
}
static int F_54 ( struct V_27 * V_28 ,
enum V_192 V_60 )
{
struct V_1 * V_2 = F_8 ( V_28 ) ;
T_1 V_193 = 0 ;
switch ( V_60 ) {
case V_194 :
return 1 ;
case V_195 :
V_193 = V_196 ;
break;
case V_197 :
V_193 = V_198 ;
break;
case V_199 :
V_193 = V_200 ;
break;
}
V_2 -> V_54 -> V_45 -> V_201 ( V_2 -> V_56 , V_193 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 , struct V_202 * V_95 )
{
V_95 -> V_203 = V_204 | V_205 ;
switch ( V_95 -> V_206 ) {
case V_207 :
case V_208 :
V_95 -> V_203 |= V_209 | V_210 ;
break;
case V_211 :
if ( V_2 -> V_212 & V_213 )
V_95 -> V_203 |= V_209 | V_210 ;
break;
case V_214 :
if ( V_2 -> V_212 & V_215 )
V_95 -> V_203 |= V_209 | V_210 ;
break;
case V_216 :
case V_217 :
break;
default:
V_95 -> V_203 = 0 ;
break;
}
return 0 ;
}
static int F_56 ( struct V_27 * V_28 , struct V_202 * V_95 ,
T_2 * T_5 V_218 )
{
struct V_1 * V_2 = F_8 ( V_28 ) ;
switch ( V_95 -> V_49 ) {
case V_219 :
V_95 -> V_203 = F_18 ( V_2 ) ;
return 0 ;
case V_220 :
return F_55 ( V_2 , V_95 ) ;
default:
F_57 ( V_2 , L_35 ) ;
return - V_74 ;
}
}
static int F_58 ( struct V_1 * V_2 , struct V_202 * V_95 )
{
struct V_221 * V_222 ;
T_1 V_223 = 0 , V_224 = 0 ;
int V_117 = 0 ;
F_9 ( V_2 , V_37 ,
L_36 ,
V_95 -> V_206 , V_95 -> V_203 ) ;
switch ( V_95 -> V_206 ) {
case V_207 :
case V_208 :
if ( V_95 -> V_203 ^ ( V_204 | V_205 |
V_209 | V_210 ) ) {
F_24 ( V_2 , L_35 ) ;
return - V_43 ;
}
return 0 ;
case V_211 :
if ( V_95 -> V_203 == ( V_204 | V_205 |
V_209 | V_210 ) ) {
V_223 = V_213 ;
F_9 ( V_2 , V_37 ,
L_37 ) ;
} else if ( V_95 -> V_203 == ( V_204 | V_205 ) ) {
V_224 = V_213 ;
F_9 ( V_2 , V_37 ,
L_38 ) ;
} else {
return - V_43 ;
}
break;
case V_214 :
if ( V_95 -> V_203 == ( V_204 | V_205 |
V_209 | V_210 ) ) {
V_223 = V_215 ;
F_9 ( V_2 , V_37 ,
L_37 ) ;
} else if ( V_95 -> V_203 == ( V_204 | V_205 ) ) {
V_224 = V_215 ;
F_9 ( V_2 , V_37 ,
L_38 ) ;
} else {
return - V_43 ;
}
break;
case V_216 :
case V_217 :
if ( V_95 -> V_203 ^ ( V_204 | V_205 ) ) {
F_24 ( V_2 , L_35 ) ;
return - V_43 ;
}
return 0 ;
case V_225 :
case V_226 :
case V_227 :
case V_228 :
case V_229 :
case V_230 :
case V_231 :
case V_232 :
case V_233 :
case V_234 :
if ( V_95 -> V_203 ) {
F_24 ( V_2 , L_35 ) ;
return - V_43 ;
}
return 0 ;
default:
return - V_43 ;
}
if ( V_2 -> V_212 == ( ( V_2 -> V_212 & ~ V_224 ) | V_223 ) )
return 0 ;
V_2 -> V_212 = ( ( V_2 -> V_212 & ~ V_224 ) | V_223 ) ;
V_2 -> V_188 |= V_235 ;
F_14 ( V_2 ) ;
if ( V_2 -> V_60 == V_61 ) {
V_222 = F_59 ( sizeof( * V_222 ) ) ;
if ( ! V_222 ) {
F_15 ( V_2 ) ;
return - V_236 ;
}
F_60 ( V_2 , & V_222 -> V_237 ,
& V_222 -> V_238 ) ;
V_117 = V_2 -> V_54 -> V_239 ( V_2 -> V_56 , V_222 ) ;
F_61 ( V_222 ) ;
}
F_15 ( V_2 ) ;
return V_117 ;
}
static int F_62 ( struct V_27 * V_28 , struct V_202 * V_95 )
{
struct V_1 * V_2 = F_8 ( V_28 ) ;
switch ( V_95 -> V_49 ) {
case V_240 :
return F_58 ( V_2 , V_95 ) ;
default:
F_24 ( V_2 , L_35 ) ;
return - V_74 ;
}
}
static T_2 F_63 ( struct V_27 * V_28 )
{
return V_241 ;
}
static T_2 F_64 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_8 ( V_28 ) ;
return sizeof( V_2 -> V_242 ) ;
}
static int F_65 ( struct V_27 * V_28 , T_2 * V_243 , T_1 * V_244 , T_1 * V_245 )
{
struct V_1 * V_2 = F_8 ( V_28 ) ;
int V_6 ;
if ( V_245 )
* V_245 = V_246 ;
if ( ! V_243 )
return 0 ;
for ( V_6 = 0 ; V_6 < V_241 ; V_6 ++ )
V_243 [ V_6 ] = V_2 -> V_190 [ V_6 ] ;
if ( V_244 )
memcpy ( V_244 , V_2 -> V_242 , F_64 ( V_28 ) ) ;
return 0 ;
}
static int F_66 ( struct V_27 * V_28 , const T_2 * V_243 ,
const T_1 * V_244 , const T_1 V_245 )
{
struct V_221 * V_222 ;
struct V_1 * V_2 = F_8 ( V_28 ) ;
int V_6 , V_117 = 0 ;
if ( V_2 -> V_44 . V_45 . V_46 > 1 ) {
F_24 ( V_2 ,
L_39 ) ;
return - V_74 ;
}
if ( V_245 != V_247 && V_245 != V_246 )
return - V_74 ;
if ( ! V_243 && ! V_244 )
return 0 ;
if ( V_243 ) {
for ( V_6 = 0 ; V_6 < V_241 ; V_6 ++ )
V_2 -> V_190 [ V_6 ] = V_243 [ V_6 ] ;
V_2 -> V_188 |= V_189 ;
}
if ( V_244 ) {
memcpy ( & V_2 -> V_242 , V_244 , F_64 ( V_28 ) ) ;
V_2 -> V_188 |= V_248 ;
}
F_14 ( V_2 ) ;
if ( V_2 -> V_60 == V_61 ) {
V_222 = F_59 ( sizeof( * V_222 ) ) ;
if ( ! V_222 ) {
F_15 ( V_2 ) ;
return - V_236 ;
}
F_60 ( V_2 , & V_222 -> V_237 ,
& V_222 -> V_238 ) ;
V_117 = V_2 -> V_54 -> V_239 ( V_2 -> V_56 , V_222 ) ;
F_61 ( V_222 ) ;
}
F_15 ( V_2 ) ;
return V_117 ;
}
static void F_67 ( struct V_1 * V_2 )
{
int V_6 ;
if ( ! F_35 ( V_2 -> V_93 ) )
return;
F_39 (i) {
F_68 ( V_2 -> V_19 [ V_6 ] . V_134 , V_249 , 1 ) ;
F_69 ( & V_2 -> V_19 [ V_6 ] . V_250 ) ;
}
}
static void F_70 ( struct V_1 * V_2 )
{
int V_6 ;
F_39 (i) {
F_71 ( & V_2 -> V_19 [ V_6 ] . V_250 ) ;
F_68 ( V_2 -> V_19 [ V_6 ] . V_134 , V_251 , 0 ) ;
}
}
static int F_72 ( struct V_1 * V_2 ,
struct V_252 * V_253 )
{
struct V_3 * V_4 = NULL ;
struct V_254 * V_255 ;
T_6 V_256 ;
int V_6 , V_257 , V_258 ;
F_39 (i) {
if ( V_2 -> V_19 [ V_6 ] . type & V_23 ) {
V_4 = V_2 -> V_19 [ V_6 ] . V_4 ;
break;
}
}
if ( ! V_4 ) {
F_73 ( V_2 , L_40 ) ;
return - 1 ;
}
V_257 = V_4 -> V_259 & V_144 ;
V_4 -> V_260 . V_261 [ V_257 ] . V_253 = V_253 ;
V_255 = F_74 ( & V_4 -> V_262 ) ;
memset ( V_255 , 0 , sizeof( * V_255 ) ) ;
V_258 = 1 << V_263 ;
V_255 -> V_203 . V_264 . V_265 = V_258 ;
V_258 = V_253 -> V_164 & V_266 ;
V_255 -> V_203 . V_265 |= ( V_258 << V_267 ) ;
V_256 = F_75 ( & V_2 -> V_109 -> V_28 , V_253 -> V_203 ,
F_76 ( V_253 ) , V_268 ) ;
if ( F_77 ( F_78 ( & V_2 -> V_109 -> V_28 , V_256 ) ) ) {
F_73 ( V_2 , L_41 ) ;
return - V_236 ;
}
F_79 ( V_255 , V_256 , F_76 ( V_253 ) ) ;
V_255 -> V_203 . V_269 = 1 ;
V_4 -> V_259 ++ ;
V_258 = F_80 ( F_81 ( & V_4 -> V_262 ) ) ;
V_4 -> V_270 . V_203 . V_271 = V_258 ;
F_82 () ;
F_83 () ;
F_84 ( V_4 -> V_270 . V_272 , V_4 -> V_273 ) ;
F_85 () ;
for ( V_6 = 0 ; V_6 < V_274 ; V_6 ++ ) {
if ( F_86 ( V_4 ) )
break;
F_87 ( 100 , 200 ) ;
}
if ( ! F_86 ( V_4 ) ) {
F_73 ( V_2 , L_42 ) ;
return - 1 ;
}
V_255 = (struct V_254 * ) F_88 ( & V_4 -> V_262 ) ;
F_89 ( & V_2 -> V_109 -> V_28 , F_90 ( V_255 ) ,
F_91 ( V_255 ) , V_268 ) ;
V_4 -> V_275 ++ ;
V_4 -> V_260 . V_261 [ V_257 ] . V_253 = NULL ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 )
{
T_4 V_276 , V_277 , V_278 , V_164 ;
struct V_279 * V_280 ;
struct V_12 * V_13 = NULL ;
struct V_281 * V_281 ;
union V_282 * V_283 ;
int V_6 , V_284 , V_117 = 0 ;
T_1 * V_285 ;
F_39 (i) {
if ( V_2 -> V_19 [ V_6 ] . type & V_20 ) {
V_13 = V_2 -> V_19 [ V_6 ] . V_13 ;
break;
}
}
if ( ! V_13 ) {
F_73 ( V_2 , L_43 ) ;
return - 1 ;
}
for ( V_284 = 0 ; V_284 < V_274 ; V_284 ++ ) {
if ( ! F_93 ( V_13 ) ) {
F_87 ( 100 , 200 ) ;
continue;
}
V_276 = F_94 ( * V_13 -> V_286 ) ;
V_277 = F_95 ( & V_13 -> V_287 ) ;
F_96 () ;
V_283 = (union V_282 * ) F_88 ( & V_13 -> V_287 ) ;
V_278 = V_13 -> V_288 & V_140 ;
V_281 = & V_13 -> V_289 [ V_278 ] ;
V_280 = & V_283 -> V_290 ;
V_164 = F_94 ( V_280 -> V_291 ) ;
V_285 = ( T_1 * ) ( F_97 ( V_281 -> V_203 ) +
V_280 -> V_292 +
V_281 -> V_293 ) ;
if ( F_98 ( V_285 , V_2 -> V_93 -> V_294 ) &&
F_98 ( V_285 + V_295 ,
V_2 -> V_93 -> V_294 ) ) {
for ( V_6 = V_296 ; V_6 < V_164 ; V_6 ++ )
if ( V_285 [ V_6 ] != ( unsigned char ) ( V_6 & 0xff ) ) {
V_117 = - 1 ;
break;
}
F_99 ( V_13 , 1 ) ;
F_100 ( & V_13 -> V_287 ) ;
break;
}
F_24 ( V_2 , L_44 ) ;
F_99 ( V_13 , 1 ) ;
F_100 ( & V_13 -> V_287 ) ;
}
if ( V_284 == V_274 ) {
F_73 ( V_2 , L_45 ) ;
return - 1 ;
}
F_101 ( V_2 , V_13 ) ;
return V_117 ;
}
static int F_102 ( struct V_1 * V_2 , T_2 V_297 )
{
struct V_71 V_124 ;
struct V_252 * V_253 = NULL ;
int V_117 = 0 , V_6 ;
T_2 V_298 ;
T_1 * V_299 ;
if ( ! F_35 ( V_2 -> V_93 ) ) {
F_73 ( V_2 , L_18 ) ;
return - V_43 ;
}
F_70 ( V_2 ) ;
memset ( & V_124 , 0 , sizeof( V_124 ) ) ;
V_124 . V_62 = true ;
V_124 . V_75 = V_300 ;
V_124 . V_297 = V_297 ;
V_2 -> V_54 -> V_45 -> V_92 ( V_2 -> V_56 , & V_124 ) ;
F_103 ( 500 ) ;
V_298 = V_2 -> V_93 -> V_168 + V_296 ;
V_253 = F_104 ( V_2 -> V_93 , V_298 ) ;
if ( ! V_253 ) {
F_24 ( V_2 , L_46 ) ;
V_117 = - V_236 ;
goto V_301;
}
V_299 = F_105 ( V_253 , V_298 ) ;
F_106 ( V_299 , V_2 -> V_93 -> V_294 ) ;
F_106 ( V_299 + V_295 , V_2 -> V_93 -> V_294 ) ;
memset ( V_299 + ( 2 * V_295 ) , 0x77 , ( V_296 - ( 2 * V_295 ) ) ) ;
for ( V_6 = V_296 ; V_6 < V_298 ; V_6 ++ )
V_299 [ V_6 ] = ( unsigned char ) ( V_6 & 0xff ) ;
V_117 = F_72 ( V_2 , V_253 ) ;
if ( V_117 )
goto V_301;
V_117 = F_92 ( V_2 ) ;
if ( V_117 )
goto V_301;
F_9 ( V_2 , V_302 , L_47 ) ;
V_301:
F_107 ( V_253 ) ;
memset ( & V_124 , 0 , sizeof( V_124 ) ) ;
V_124 . V_62 = true ;
V_124 . V_75 = V_300 ;
V_124 . V_297 = V_303 ;
V_2 -> V_54 -> V_45 -> V_92 ( V_2 -> V_56 , & V_124 ) ;
F_103 ( 500 ) ;
F_67 ( V_2 ) ;
return V_117 ;
}
static void F_108 ( struct V_27 * V_28 ,
struct V_304 * V_305 , T_3 * V_5 )
{
struct V_1 * V_2 = F_8 ( V_28 ) ;
F_9 ( V_2 , V_37 ,
L_48 ,
( V_305 -> V_306 & V_307 ) ,
( V_305 -> V_306 & V_308 ) >> 2 ) ;
memset ( V_5 , 0 , sizeof( T_3 ) * V_36 ) ;
if ( V_305 -> V_306 & V_307 ) {
if ( F_102 ( V_2 ,
V_309 ) ) {
V_5 [ V_310 ] = 1 ;
V_305 -> V_306 |= V_311 ;
}
}
if ( V_2 -> V_54 -> V_45 -> V_312 -> V_313 ( V_2 -> V_56 ) ) {
V_5 [ V_314 ] = 1 ;
V_305 -> V_306 |= V_311 ;
}
if ( V_2 -> V_54 -> V_45 -> V_312 -> V_315 ( V_2 -> V_56 ) ) {
V_5 [ V_316 ] = 1 ;
V_305 -> V_306 |= V_311 ;
}
if ( V_2 -> V_54 -> V_45 -> V_312 -> V_317 ( V_2 -> V_56 ) ) {
V_5 [ V_318 ] = 1 ;
V_305 -> V_306 |= V_311 ;
}
if ( V_2 -> V_54 -> V_45 -> V_312 -> V_319 ( V_2 -> V_56 ) ) {
V_5 [ V_320 ] = 1 ;
V_305 -> V_306 |= V_311 ;
}
if ( V_2 -> V_54 -> V_45 -> V_312 -> V_321 ( V_2 -> V_56 ) ) {
V_5 [ V_322 ] = 1 ;
V_305 -> V_306 |= V_311 ;
}
}
static int F_109 ( struct V_27 * V_28 ,
const struct V_323 * V_324 ,
const void * V_203 )
{
struct V_1 * V_2 = F_8 ( V_28 ) ;
T_2 V_258 ;
switch ( V_324 -> V_325 ) {
case V_326 :
V_258 = * ( T_2 * ) V_203 ;
if ( V_258 < V_327 || V_258 > V_328 ) {
F_9 ( V_2 , V_37 ,
L_49 ,
V_327 , V_328 ) ;
return - V_43 ;
}
V_2 -> V_329 = * ( T_2 * ) V_203 ;
break;
default:
return - V_74 ;
}
return 0 ;
}
static int F_110 ( struct V_27 * V_28 ,
const struct V_323 * V_324 , void * V_203 )
{
struct V_1 * V_2 = F_8 ( V_28 ) ;
switch ( V_324 -> V_325 ) {
case V_326 :
* ( T_2 * ) V_203 = V_2 -> V_329 ;
break;
default:
return - V_74 ;
}
return 0 ;
}
void F_111 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_8 ( V_28 ) ;
if ( F_6 ( V_2 ) )
V_28 -> V_330 = & V_331 ;
else
V_28 -> V_330 = & V_332 ;
}
