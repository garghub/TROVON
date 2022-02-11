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
default:
F_30 ( V_2 , L_11 , V_51 -> V_63 ) ;
return - V_43 ;
}
}
V_72 . V_62 = true ;
V_2 -> V_54 -> V_45 -> V_93 ( V_2 -> V_56 , & V_72 ) ;
return 0 ;
}
static void F_32 ( struct V_27 * V_94 ,
struct V_95 * V_96 )
{
char V_97 [ V_98 ] , V_99 [ V_98 ] ;
struct V_1 * V_2 = F_14 ( V_94 ) ;
F_33 ( V_96 -> V_100 , L_12 , sizeof( V_96 -> V_100 ) ) ;
F_33 ( V_96 -> V_101 , V_102 , sizeof( V_96 -> V_101 ) ) ;
snprintf ( V_99 , V_98 , L_13 ,
V_2 -> V_44 . V_45 . V_103 ,
V_2 -> V_44 . V_45 . V_104 ,
V_2 -> V_44 . V_45 . V_105 ,
V_2 -> V_44 . V_45 . V_106 ) ;
snprintf ( V_97 , V_98 , L_13 ,
( V_2 -> V_44 . V_45 . V_107 >> 24 ) & 0xFF ,
( V_2 -> V_44 . V_45 . V_107 >> 16 ) & 0xFF ,
( V_2 -> V_44 . V_45 . V_107 >> 8 ) & 0xFF ,
V_2 -> V_44 . V_45 . V_107 & 0xFF ) ;
if ( ( strlen ( V_99 ) + strlen ( V_97 ) + strlen ( L_14 ) ) <
sizeof( V_96 -> V_108 ) ) {
snprintf ( V_96 -> V_108 , sizeof( V_96 -> V_108 ) ,
L_15 , V_97 , V_99 ) ;
} else {
snprintf ( V_96 -> V_108 , sizeof( V_96 -> V_108 ) ,
L_16 , V_97 , V_99 ) ;
}
F_33 ( V_96 -> V_109 , F_34 ( V_2 -> V_110 ) , sizeof( V_96 -> V_109 ) ) ;
}
static void F_35 ( struct V_27 * V_94 , struct V_111 * V_112 )
{
struct V_1 * V_2 = F_14 ( V_94 ) ;
if ( V_2 -> V_44 . V_45 . V_113 ) {
V_112 -> V_57 = V_114 ;
V_112 -> V_115 = V_2 -> V_116 ? V_114 : 0 ;
}
}
static int F_36 ( struct V_27 * V_94 , struct V_111 * V_112 )
{
struct V_1 * V_2 = F_14 ( V_94 ) ;
bool V_117 ;
int V_118 ;
if ( V_112 -> V_115 & ~ V_114 ) {
F_30 ( V_2 ,
L_17 ) ;
return - V_43 ;
}
V_117 = ! ! ( V_112 -> V_115 & V_114 ) ;
if ( V_117 == V_2 -> V_116 )
return 0 ;
if ( ! V_2 -> V_44 . V_45 . V_113 ) {
F_30 ( V_2 , L_18 ) ;
return - V_43 ;
}
V_118 = V_2 -> V_54 -> V_45 -> V_119 ( V_2 -> V_56 , V_117 ) ;
if ( ! V_118 )
V_2 -> V_116 = V_117 ;
return V_118 ;
}
static T_2 F_37 ( struct V_27 * V_94 )
{
struct V_1 * V_2 = F_14 ( V_94 ) ;
return ( ( T_2 ) V_2 -> V_120 << V_121 ) | V_2 -> V_122 ;
}
static void F_38 ( struct V_27 * V_94 , T_2 V_123 )
{
struct V_1 * V_2 = F_14 ( V_94 ) ;
T_2 V_122 = 0 ;
T_1 V_120 = 0 ;
F_39 ( V_123 , & V_122 , & V_120 ) ;
V_2 -> V_120 = V_120 ;
V_2 -> V_122 = V_122 ;
V_2 -> V_54 -> V_45 -> V_124 ( V_2 -> V_56 ,
V_122 , V_120 ) ;
}
static int F_40 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
struct V_52 V_53 ;
struct V_71 V_125 ;
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
memset ( & V_125 , 0 , sizeof( V_125 ) ) ;
V_125 . V_62 = false ;
V_2 -> V_54 -> V_45 -> V_93 ( V_2 -> V_56 , & V_125 ) ;
V_125 . V_62 = true ;
V_2 -> V_54 -> V_45 -> V_93 ( V_2 -> V_56 , & V_125 ) ;
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
struct V_126 * V_127 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
T_4 V_128 , V_129 ;
memset ( V_127 , 0 , sizeof( struct V_126 ) ) ;
V_2 -> V_54 -> V_45 -> V_130 ( V_2 -> V_56 , & V_128 , & V_129 ) ;
V_127 -> V_131 = V_128 ;
V_127 -> V_132 = V_129 ;
return 0 ;
}
static int F_44 ( struct V_27 * V_28 ,
struct V_126 * V_127 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_6 , V_118 = 0 ;
T_4 V_128 , V_129 , V_133 ;
if ( ! F_41 ( V_28 ) ) {
F_30 ( V_2 , L_19 ) ;
return - V_43 ;
}
if ( V_127 -> V_131 > V_134 ||
V_127 -> V_132 > V_134 ) {
F_30 ( V_2 ,
L_20 ,
V_127 -> V_131 > V_134 ? L_21
: L_22 ,
V_134 ) ;
return - V_43 ;
}
V_128 = ( T_4 ) V_127 -> V_131 ;
V_129 = ( T_4 ) V_127 -> V_132 ;
F_45 (i) {
V_133 = V_2 -> V_20 [ V_6 ] . V_135 -> V_136 ;
V_118 = V_2 -> V_54 -> V_45 -> V_137 ( V_2 -> V_56 , V_128 , V_129 ,
( T_4 ) V_6 , V_133 ) ;
if ( V_118 ) {
F_30 ( V_2 , L_23 , V_118 ) ;
return V_118 ;
}
}
return V_118 ;
}
static void F_46 ( struct V_27 * V_28 ,
struct V_138 * V_139 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
V_139 -> V_140 = V_141 ;
V_139 -> V_142 = V_2 -> V_143 ;
V_139 -> V_144 = V_145 ;
V_139 -> V_146 = V_2 -> V_147 ;
}
static int F_47 ( struct V_27 * V_28 ,
struct V_138 * V_139 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
F_15 ( V_2 , ( V_148 | V_149 ) ,
L_24 ,
V_139 -> V_142 , V_139 -> V_146 ) ;
if ( V_139 -> V_142 > V_141 ||
V_139 -> V_142 < V_150 ||
V_139 -> V_146 > V_145 ||
V_139 -> V_146 < V_151 ) {
F_15 ( V_2 , ( V_148 | V_149 ) ,
L_25 ,
V_150 , V_141 ,
V_151 , V_145 ) ;
return - V_43 ;
}
V_2 -> V_143 = V_139 -> V_142 ;
V_2 -> V_147 = V_139 -> V_146 ;
F_48 ( V_2 , NULL , false ) ;
return 0 ;
}
static void F_49 ( struct V_27 * V_28 ,
struct V_152 * V_153 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
struct V_52 V_53 ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_2 -> V_54 -> V_45 -> V_55 ( V_2 -> V_56 , & V_53 ) ;
if ( V_53 . V_154 & V_155 )
V_153 -> V_68 = true ;
if ( V_53 . V_154 & V_156 )
V_153 -> V_157 = true ;
if ( V_53 . V_154 & V_158 )
V_153 -> V_159 = true ;
F_15 ( V_2 , V_37 ,
L_26 ,
V_153 -> V_49 , V_153 -> V_68 , V_153 -> V_157 ,
V_153 -> V_159 ) ;
}
static int F_50 ( struct V_27 * V_28 ,
struct V_152 * V_153 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
struct V_71 V_72 ;
struct V_52 V_53 ;
if ( ! V_2 -> V_54 || ! V_2 -> V_54 -> V_45 -> V_73 ( V_2 -> V_56 ) ) {
F_30 ( V_2 ,
L_27 ) ;
return - V_74 ;
}
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_2 -> V_54 -> V_45 -> V_55 ( V_2 -> V_56 , & V_53 ) ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . V_75 |= V_160 ;
if ( V_153 -> V_68 ) {
if ( ! ( V_53 . V_78 & V_79 ) ) {
F_30 ( V_2 , L_28 ) ;
return - V_43 ;
}
V_72 . V_154 |= V_155 ;
}
if ( V_153 -> V_157 )
V_72 . V_154 |= V_156 ;
if ( V_153 -> V_159 )
V_72 . V_154 |= V_158 ;
V_72 . V_62 = true ;
V_2 -> V_54 -> V_45 -> V_93 ( V_2 -> V_56 , & V_72 ) ;
return 0 ;
}
static void F_51 ( struct V_27 * V_94 ,
struct V_161 * V_162 , void * V_163 )
{
struct V_1 * V_2 = F_14 ( V_94 ) ;
V_162 -> V_101 = 0 ;
memset ( V_163 , 0 , V_162 -> V_164 ) ;
if ( V_2 -> V_54 && V_2 -> V_54 -> V_45 )
V_2 -> V_54 -> V_45 -> V_165 ( V_2 -> V_56 , V_163 ) ;
}
static int F_52 ( struct V_27 * V_94 )
{
struct V_1 * V_2 = F_14 ( V_94 ) ;
if ( V_2 -> V_54 && V_2 -> V_54 -> V_45 )
return V_2 -> V_54 -> V_45 -> V_166 ( V_2 -> V_56 ) ;
else
return - V_43 ;
}
static void F_53 ( struct V_1 * V_2 ,
struct V_167 * args )
{
V_2 -> V_94 -> V_168 = args -> V_169 . V_168 ;
}
int F_54 ( struct V_27 * V_94 , int V_170 )
{
struct V_1 * V_2 = F_14 ( V_94 ) ;
struct V_167 args ;
F_15 ( V_2 , ( V_148 | V_149 ) ,
L_29 , V_170 ) ;
args . V_169 . V_168 = V_170 ;
args . V_171 = & F_53 ;
F_48 ( V_2 , & args , false ) ;
V_2 -> V_54 -> V_45 -> V_172 ( V_2 -> V_56 , V_170 ) ;
return 0 ;
}
static void F_55 ( struct V_27 * V_28 ,
struct V_173 * V_174 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
V_174 -> V_175 = F_56 ( V_2 ) ;
V_174 -> V_176 = F_56 ( V_2 ) ;
V_174 -> V_177 = F_56 ( V_2 ) ;
V_174 -> V_178 = F_12 ( V_2 ) - V_2 -> V_179 -
V_2 -> V_180 ;
V_174 -> V_181 = V_2 -> V_179 ;
V_174 -> V_182 = V_2 -> V_180 ;
}
static int F_57 ( struct V_27 * V_28 ,
struct V_173 * V_174 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
T_2 V_183 ;
F_15 ( V_2 , ( V_148 | V_149 ) ,
L_30 ,
V_174 -> V_182 , V_174 -> V_181 ,
V_174 -> V_184 , V_174 -> V_178 ) ;
V_183 = V_174 -> V_182 + V_174 -> V_181 +
V_174 -> V_178 ;
if ( V_174 -> V_184 ) {
F_15 ( V_2 , ( V_148 | V_149 ) ,
L_31 ) ;
return - V_43 ;
}
if ( ! ( V_174 -> V_178 || ( V_174 -> V_182 &&
V_174 -> V_181 ) ) ) {
F_15 ( V_2 , ( V_148 | V_149 ) ,
L_32 ) ;
return - V_43 ;
}
if ( V_183 > F_56 ( V_2 ) ) {
F_15 ( V_2 , ( V_148 | V_149 ) ,
L_33 ,
V_183 , F_56 ( V_2 ) ) ;
return - V_43 ;
}
if ( ( V_183 == F_12 ( V_2 ) ) &&
( V_174 -> V_181 == V_2 -> V_179 ) &&
( V_174 -> V_182 == V_2 -> V_180 ) ) {
F_15 ( V_2 , ( V_148 | V_149 ) ,
L_34 ) ;
return 0 ;
}
if ( ( V_183 % V_2 -> V_44 . V_45 . V_46 ) ||
( V_174 -> V_181 % V_2 -> V_44 . V_45 . V_46 ) ||
( V_174 -> V_182 % V_2 -> V_44 . V_45 . V_46 ) ) {
F_15 ( V_2 , ( V_148 | V_149 ) ,
L_35 ,
V_2 -> V_44 . V_45 . V_46 ) ;
return - V_43 ;
}
V_2 -> V_185 = V_183 ;
V_2 -> V_186 = V_174 -> V_181 ;
V_2 -> V_187 = V_174 -> V_182 ;
if ( ( V_2 -> V_185 - V_2 -> V_186 ) != F_24 ( V_2 ) ) {
V_2 -> V_188 &= ~ V_189 ;
memset ( V_2 -> V_190 , 0 , sizeof( V_2 -> V_190 ) ) ;
}
F_48 ( V_2 , NULL , false ) ;
return 0 ;
}
static int F_58 ( struct V_27 * V_28 ,
struct V_191 * V_96 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
return F_59 ( V_2 , V_96 ) ;
}
static int F_60 ( struct V_27 * V_28 ,
enum V_192 V_60 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
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
static int F_61 ( struct V_1 * V_2 , struct V_202 * V_96 )
{
V_96 -> V_203 = V_204 | V_205 ;
switch ( V_96 -> V_206 ) {
case V_207 :
case V_208 :
V_96 -> V_203 |= V_209 | V_210 ;
break;
case V_211 :
if ( V_2 -> V_212 & V_213 )
V_96 -> V_203 |= V_209 | V_210 ;
break;
case V_214 :
if ( V_2 -> V_212 & V_215 )
V_96 -> V_203 |= V_209 | V_210 ;
break;
case V_216 :
case V_217 :
break;
default:
V_96 -> V_203 = 0 ;
break;
}
return 0 ;
}
static int F_62 ( struct V_27 * V_28 , struct V_202 * V_96 ,
T_2 * T_5 V_218 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
switch ( V_96 -> V_49 ) {
case V_219 :
V_96 -> V_203 = F_24 ( V_2 ) ;
return 0 ;
case V_220 :
return F_61 ( V_2 , V_96 ) ;
default:
F_63 ( V_2 , L_36 ) ;
return - V_74 ;
}
}
static int F_64 ( struct V_1 * V_2 , struct V_202 * V_96 )
{
struct V_221 * V_222 ;
T_1 V_223 = 0 , V_224 = 0 ;
int V_118 = 0 ;
F_15 ( V_2 , V_37 ,
L_37 ,
V_96 -> V_206 , V_96 -> V_203 ) ;
switch ( V_96 -> V_206 ) {
case V_207 :
case V_208 :
if ( V_96 -> V_203 ^ ( V_204 | V_205 |
V_209 | V_210 ) ) {
F_30 ( V_2 , L_36 ) ;
return - V_43 ;
}
return 0 ;
case V_211 :
if ( V_96 -> V_203 == ( V_204 | V_205 |
V_209 | V_210 ) ) {
V_223 = V_213 ;
F_15 ( V_2 , V_37 ,
L_38 ) ;
} else if ( V_96 -> V_203 == ( V_204 | V_205 ) ) {
V_224 = V_213 ;
F_15 ( V_2 , V_37 ,
L_39 ) ;
} else {
return - V_43 ;
}
break;
case V_214 :
if ( V_96 -> V_203 == ( V_204 | V_205 |
V_209 | V_210 ) ) {
V_223 = V_215 ;
F_15 ( V_2 , V_37 ,
L_38 ) ;
} else if ( V_96 -> V_203 == ( V_204 | V_205 ) ) {
V_224 = V_215 ;
F_15 ( V_2 , V_37 ,
L_39 ) ;
} else {
return - V_43 ;
}
break;
case V_216 :
case V_217 :
if ( V_96 -> V_203 ^ ( V_204 | V_205 ) ) {
F_30 ( V_2 , L_36 ) ;
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
if ( V_96 -> V_203 ) {
F_30 ( V_2 , L_36 ) ;
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
F_20 ( V_2 ) ;
if ( V_2 -> V_60 == V_61 ) {
V_222 = F_65 ( sizeof( * V_222 ) ) ;
if ( ! V_222 ) {
F_21 ( V_2 ) ;
return - V_236 ;
}
F_66 ( V_2 , & V_222 -> V_237 ,
& V_222 -> V_238 ) ;
V_118 = V_2 -> V_54 -> V_239 ( V_2 -> V_56 , V_222 ) ;
F_67 ( V_222 ) ;
}
F_21 ( V_2 ) ;
return V_118 ;
}
static int F_68 ( struct V_27 * V_28 , struct V_202 * V_96 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
switch ( V_96 -> V_49 ) {
case V_240 :
return F_64 ( V_2 , V_96 ) ;
default:
F_30 ( V_2 , L_36 ) ;
return - V_74 ;
}
}
static T_2 F_69 ( struct V_27 * V_28 )
{
return V_241 ;
}
static T_2 F_70 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
return sizeof( V_2 -> V_242 ) ;
}
static int F_71 ( struct V_27 * V_28 , T_2 * V_243 , T_1 * V_244 , T_1 * V_245 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_6 ;
if ( V_245 )
* V_245 = V_246 ;
if ( ! V_243 )
return 0 ;
for ( V_6 = 0 ; V_6 < V_241 ; V_6 ++ )
V_243 [ V_6 ] = V_2 -> V_190 [ V_6 ] ;
if ( V_244 )
memcpy ( V_244 , V_2 -> V_242 , F_70 ( V_28 ) ) ;
return 0 ;
}
static int F_72 ( struct V_27 * V_28 , const T_2 * V_243 ,
const T_1 * V_244 , const T_1 V_245 )
{
struct V_221 * V_222 ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_6 , V_118 = 0 ;
if ( V_2 -> V_44 . V_45 . V_46 > 1 ) {
F_30 ( V_2 ,
L_40 ) ;
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
memcpy ( & V_2 -> V_242 , V_244 , F_70 ( V_28 ) ) ;
V_2 -> V_188 |= V_248 ;
}
F_20 ( V_2 ) ;
if ( V_2 -> V_60 == V_61 ) {
V_222 = F_65 ( sizeof( * V_222 ) ) ;
if ( ! V_222 ) {
F_21 ( V_2 ) ;
return - V_236 ;
}
F_66 ( V_2 , & V_222 -> V_237 ,
& V_222 -> V_238 ) ;
V_118 = V_2 -> V_54 -> V_239 ( V_2 -> V_56 , V_222 ) ;
F_67 ( V_222 ) ;
}
F_21 ( V_2 ) ;
return V_118 ;
}
static void F_73 ( struct V_1 * V_2 )
{
int V_6 ;
if ( ! F_41 ( V_2 -> V_94 ) )
return;
F_45 (i) {
F_74 ( V_2 -> V_20 [ V_6 ] . V_135 , V_249 , 1 ) ;
F_75 ( & V_2 -> V_20 [ V_6 ] . V_250 ) ;
}
}
static void F_76 ( struct V_1 * V_2 )
{
int V_6 ;
F_45 (i) {
F_77 ( & V_2 -> V_20 [ V_6 ] . V_250 ) ;
F_74 ( V_2 -> V_20 [ V_6 ] . V_135 , V_251 , 0 ) ;
}
}
static int F_78 ( struct V_1 * V_2 ,
struct V_252 * V_253 )
{
struct V_3 * V_4 = NULL ;
struct V_254 * V_255 ;
T_6 V_256 ;
int V_6 , V_257 , V_258 ;
F_45 (i) {
if ( V_2 -> V_20 [ V_6 ] . type & V_24 ) {
V_4 = V_2 -> V_20 [ V_6 ] . V_4 ;
break;
}
}
if ( ! V_4 ) {
F_79 ( V_2 , L_41 ) ;
return - 1 ;
}
V_257 = V_4 -> V_259 & V_145 ;
V_4 -> V_260 . V_261 [ V_257 ] . V_253 = V_253 ;
V_255 = F_80 ( & V_4 -> V_262 ) ;
memset ( V_255 , 0 , sizeof( * V_255 ) ) ;
V_258 = 1 << V_263 ;
V_255 -> V_203 . V_264 . V_265 = V_258 ;
V_258 = V_253 -> V_164 & V_266 ;
V_255 -> V_203 . V_265 |= ( V_258 << V_267 ) ;
V_256 = F_81 ( & V_2 -> V_110 -> V_28 , V_253 -> V_203 ,
F_82 ( V_253 ) , V_268 ) ;
if ( F_83 ( F_84 ( & V_2 -> V_110 -> V_28 , V_256 ) ) ) {
F_79 ( V_2 , L_42 ) ;
return - V_236 ;
}
F_85 ( V_255 , V_256 , F_82 ( V_253 ) ) ;
V_255 -> V_203 . V_269 = 1 ;
V_4 -> V_259 ++ ;
V_258 = F_86 ( F_87 ( & V_4 -> V_262 ) ) ;
V_4 -> V_270 . V_203 . V_271 = V_258 ;
F_88 () ;
F_89 () ;
F_90 ( V_4 -> V_270 . V_272 , V_4 -> V_273 ) ;
F_91 () ;
for ( V_6 = 0 ; V_6 < V_274 ; V_6 ++ ) {
if ( F_92 ( V_4 ) )
break;
F_93 ( 100 , 200 ) ;
}
if ( ! F_92 ( V_4 ) ) {
F_79 ( V_2 , L_43 ) ;
return - 1 ;
}
V_255 = (struct V_254 * ) F_94 ( & V_4 -> V_262 ) ;
F_95 ( & V_2 -> V_110 -> V_28 , F_96 ( V_255 ) ,
F_97 ( V_255 ) , V_268 ) ;
V_4 -> V_275 ++ ;
V_4 -> V_260 . V_261 [ V_257 ] . V_253 = NULL ;
return 0 ;
}
static int F_98 ( struct V_1 * V_2 )
{
T_4 V_276 , V_277 , V_278 , V_164 ;
struct V_279 * V_280 ;
struct V_12 * V_13 = NULL ;
struct V_281 * V_281 ;
union V_282 * V_283 ;
int V_6 , V_284 , V_118 = 0 ;
T_1 * V_285 ;
F_45 (i) {
if ( V_2 -> V_20 [ V_6 ] . type & V_21 ) {
V_13 = V_2 -> V_20 [ V_6 ] . V_13 ;
break;
}
}
if ( ! V_13 ) {
F_79 ( V_2 , L_44 ) ;
return - 1 ;
}
for ( V_284 = 0 ; V_284 < V_274 ; V_284 ++ ) {
if ( ! F_99 ( V_13 ) ) {
F_93 ( 100 , 200 ) ;
continue;
}
V_276 = F_100 ( * V_13 -> V_286 ) ;
V_277 = F_101 ( & V_13 -> V_287 ) ;
F_102 () ;
V_283 = (union V_282 * ) F_94 ( & V_13 -> V_287 ) ;
V_278 = V_13 -> V_288 & V_141 ;
V_281 = & V_13 -> V_289 [ V_278 ] ;
V_280 = & V_283 -> V_290 ;
V_164 = F_100 ( V_280 -> V_291 ) ;
V_285 = ( T_1 * ) ( F_103 ( V_281 -> V_203 ) +
V_280 -> V_292 +
V_281 -> V_293 ) ;
if ( F_104 ( V_285 , V_2 -> V_94 -> V_294 ) &&
F_104 ( V_285 + V_295 ,
V_2 -> V_94 -> V_294 ) ) {
for ( V_6 = V_296 ; V_6 < V_164 ; V_6 ++ )
if ( V_285 [ V_6 ] != ( unsigned char ) ( V_6 & 0xff ) ) {
V_118 = - 1 ;
break;
}
F_105 ( V_13 , 1 ) ;
F_106 ( & V_13 -> V_287 ) ;
break;
}
F_30 ( V_2 , L_45 ) ;
F_105 ( V_13 , 1 ) ;
F_106 ( & V_13 -> V_287 ) ;
}
if ( V_284 == V_274 ) {
F_79 ( V_2 , L_46 ) ;
return - 1 ;
}
F_107 ( V_2 , V_13 ) ;
return V_118 ;
}
static int F_108 ( struct V_1 * V_2 , T_2 V_297 )
{
struct V_71 V_125 ;
struct V_252 * V_253 = NULL ;
int V_118 = 0 , V_6 ;
T_2 V_298 ;
T_1 * V_299 ;
if ( ! F_41 ( V_2 -> V_94 ) ) {
F_79 ( V_2 , L_19 ) ;
return - V_43 ;
}
F_76 ( V_2 ) ;
memset ( & V_125 , 0 , sizeof( V_125 ) ) ;
V_125 . V_62 = true ;
V_125 . V_75 = V_300 ;
V_125 . V_297 = V_297 ;
V_2 -> V_54 -> V_45 -> V_93 ( V_2 -> V_56 , & V_125 ) ;
F_109 ( 500 ) ;
V_298 = V_2 -> V_94 -> V_168 + V_296 ;
V_253 = F_110 ( V_2 -> V_94 , V_298 ) ;
if ( ! V_253 ) {
F_30 ( V_2 , L_47 ) ;
V_118 = - V_236 ;
goto V_301;
}
V_299 = F_111 ( V_253 , V_298 ) ;
F_112 ( V_299 , V_2 -> V_94 -> V_294 ) ;
F_112 ( V_299 + V_295 , V_2 -> V_94 -> V_294 ) ;
memset ( V_299 + ( 2 * V_295 ) , 0x77 , ( V_296 - ( 2 * V_295 ) ) ) ;
for ( V_6 = V_296 ; V_6 < V_298 ; V_6 ++ )
V_299 [ V_6 ] = ( unsigned char ) ( V_6 & 0xff ) ;
V_118 = F_78 ( V_2 , V_253 ) ;
if ( V_118 )
goto V_301;
V_118 = F_98 ( V_2 ) ;
if ( V_118 )
goto V_301;
F_15 ( V_2 , V_302 , L_48 ) ;
V_301:
F_113 ( V_253 ) ;
memset ( & V_125 , 0 , sizeof( V_125 ) ) ;
V_125 . V_62 = true ;
V_125 . V_75 = V_300 ;
V_125 . V_297 = V_303 ;
V_2 -> V_54 -> V_45 -> V_93 ( V_2 -> V_56 , & V_125 ) ;
F_109 ( 500 ) ;
F_73 ( V_2 ) ;
return V_118 ;
}
static void F_114 ( struct V_27 * V_28 ,
struct V_304 * V_305 , T_3 * V_5 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
F_15 ( V_2 , V_37 ,
L_49 ,
( V_305 -> V_306 & V_307 ) ,
( V_305 -> V_306 & V_308 ) >> 2 ) ;
memset ( V_5 , 0 , sizeof( T_3 ) * V_36 ) ;
if ( V_305 -> V_306 & V_307 ) {
if ( F_108 ( V_2 ,
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
static int F_115 ( struct V_27 * V_28 ,
const struct V_323 * V_324 ,
const void * V_203 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
T_2 V_258 ;
switch ( V_324 -> V_325 ) {
case V_326 :
V_258 = * ( T_2 * ) V_203 ;
if ( V_258 < V_327 || V_258 > V_328 ) {
F_15 ( V_2 , V_37 ,
L_50 ,
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
static int F_116 ( struct V_27 * V_28 ,
const struct V_323 * V_324 , void * V_203 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
switch ( V_324 -> V_325 ) {
case V_326 :
* ( T_2 * ) V_203 = V_2 -> V_329 ;
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
V_28 -> V_330 = & V_331 ;
else
V_28 -> V_330 = & V_332 ;
}
