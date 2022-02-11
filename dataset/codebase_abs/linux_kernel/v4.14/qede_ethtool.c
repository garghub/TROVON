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
void * V_130 = NULL , * V_131 = NULL ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
T_4 V_132 , V_133 , V_6 , V_120 = 0 ;
struct V_18 * V_19 ;
V_132 = V_134 ;
V_133 = V_135 ;
memset ( V_129 , 0 , sizeof( struct V_128 ) ) ;
F_20 ( V_2 ) ;
if ( V_2 -> V_60 == V_61 ) {
F_44 (i) {
V_19 = & V_2 -> V_20 [ V_6 ] ;
if ( V_19 -> type & V_21 ) {
V_130 = V_19 -> V_13 -> V_136 ;
break;
}
}
V_120 = V_2 -> V_54 -> V_137 ( V_2 -> V_56 , & V_132 , V_130 ) ;
if ( V_120 ) {
F_30 ( V_2 , L_20 ) ;
goto V_138;
}
F_44 (i) {
V_19 = & V_2 -> V_20 [ V_6 ] ;
if ( V_19 -> type & V_24 ) {
V_131 = V_19 -> V_4 -> V_136 ;
break;
}
}
V_120 = V_2 -> V_54 -> V_137 ( V_2 -> V_56 , & V_133 , V_131 ) ;
if ( V_120 )
F_30 ( V_2 , L_21 ) ;
}
V_138:
F_21 ( V_2 ) ;
V_129 -> V_139 = V_132 ;
V_129 -> V_140 = V_133 ;
return V_120 ;
}
static int F_45 ( struct V_27 * V_28 ,
struct V_128 * V_129 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
struct V_18 * V_19 ;
int V_6 , V_120 = 0 ;
T_4 V_141 , V_142 ;
if ( ! F_41 ( V_28 ) ) {
F_30 ( V_2 , L_22 ) ;
return - V_43 ;
}
if ( V_129 -> V_139 > V_143 ||
V_129 -> V_140 > V_143 ) {
F_30 ( V_2 ,
L_23 ,
V_129 -> V_139 > V_143 ? L_24 :
L_25 , V_143 ) ;
return - V_43 ;
}
V_141 = ( T_4 ) V_129 -> V_139 ;
V_142 = ( T_4 ) V_129 -> V_140 ;
F_44 (i) {
V_19 = & V_2 -> V_20 [ V_6 ] ;
if ( V_2 -> V_20 [ V_6 ] . type & V_21 ) {
V_120 = V_2 -> V_54 -> V_45 -> V_144 ( V_2 -> V_56 ,
V_141 , 0 ,
V_19 -> V_13 -> V_136 ) ;
if ( V_120 ) {
F_30 ( V_2 ,
L_26 , V_120 ) ;
return V_120 ;
}
}
if ( V_2 -> V_20 [ V_6 ] . type & V_24 ) {
V_120 = V_2 -> V_54 -> V_45 -> V_144 ( V_2 -> V_56 ,
0 , V_142 ,
V_19 -> V_4 -> V_136 ) ;
if ( V_120 ) {
F_30 ( V_2 ,
L_27 , V_120 ) ;
return V_120 ;
}
}
}
return V_120 ;
}
static void F_46 ( struct V_27 * V_28 ,
struct V_145 * V_146 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
V_146 -> V_147 = V_148 ;
V_146 -> V_149 = V_2 -> V_150 ;
V_146 -> V_151 = V_152 ;
V_146 -> V_153 = V_2 -> V_154 ;
}
static int F_47 ( struct V_27 * V_28 ,
struct V_145 * V_146 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
F_15 ( V_2 , ( V_155 | V_156 ) ,
L_28 ,
V_146 -> V_149 , V_146 -> V_153 ) ;
if ( V_146 -> V_149 > V_148 ||
V_146 -> V_149 < V_157 ||
V_146 -> V_153 > V_152 ||
V_146 -> V_153 < V_158 ) {
F_15 ( V_2 , ( V_155 | V_156 ) ,
L_29 ,
V_157 , V_148 ,
V_158 , V_152 ) ;
return - V_43 ;
}
V_2 -> V_150 = V_146 -> V_149 ;
V_2 -> V_154 = V_146 -> V_153 ;
F_48 ( V_2 , NULL , false ) ;
return 0 ;
}
static void F_49 ( struct V_27 * V_28 ,
struct V_159 * V_160 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
struct V_52 V_53 ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_2 -> V_54 -> V_45 -> V_55 ( V_2 -> V_56 , & V_53 ) ;
if ( V_53 . V_161 & V_162 )
V_160 -> V_68 = true ;
if ( V_53 . V_161 & V_163 )
V_160 -> V_164 = true ;
if ( V_53 . V_161 & V_165 )
V_160 -> V_166 = true ;
F_15 ( V_2 , V_37 ,
L_30 ,
V_160 -> V_49 , V_160 -> V_68 , V_160 -> V_164 ,
V_160 -> V_166 ) ;
}
static int F_50 ( struct V_27 * V_28 ,
struct V_159 * V_160 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
struct V_71 V_72 ;
struct V_52 V_53 ;
if ( ! V_2 -> V_54 || ! V_2 -> V_54 -> V_45 -> V_73 ( V_2 -> V_56 ) ) {
F_30 ( V_2 ,
L_31 ) ;
return - V_74 ;
}
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_2 -> V_54 -> V_45 -> V_55 ( V_2 -> V_56 , & V_53 ) ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . V_75 |= V_167 ;
if ( V_160 -> V_68 ) {
if ( ! ( V_53 . V_78 & V_79 ) ) {
F_30 ( V_2 , L_32 ) ;
return - V_43 ;
}
V_72 . V_161 |= V_162 ;
}
if ( V_160 -> V_164 )
V_72 . V_161 |= V_163 ;
if ( V_160 -> V_166 )
V_72 . V_161 |= V_165 ;
V_72 . V_62 = true ;
V_2 -> V_54 -> V_45 -> V_95 ( V_2 -> V_56 , & V_72 ) ;
return 0 ;
}
static void F_51 ( struct V_27 * V_96 ,
struct V_168 * V_169 , void * V_170 )
{
struct V_1 * V_2 = F_14 ( V_96 ) ;
V_169 -> V_103 = 0 ;
memset ( V_170 , 0 , V_169 -> V_171 ) ;
if ( V_2 -> V_54 && V_2 -> V_54 -> V_45 )
V_2 -> V_54 -> V_45 -> V_172 ( V_2 -> V_56 , V_170 ) ;
}
static int F_52 ( struct V_27 * V_96 )
{
struct V_1 * V_2 = F_14 ( V_96 ) ;
if ( V_2 -> V_54 && V_2 -> V_54 -> V_45 )
return V_2 -> V_54 -> V_45 -> V_173 ( V_2 -> V_56 ) ;
else
return - V_43 ;
}
static void F_53 ( struct V_1 * V_2 ,
struct V_174 * args )
{
V_2 -> V_96 -> V_175 = args -> V_176 . V_175 ;
}
int F_54 ( struct V_27 * V_96 , int V_177 )
{
struct V_1 * V_2 = F_14 ( V_96 ) ;
struct V_174 args ;
F_15 ( V_2 , ( V_155 | V_156 ) ,
L_33 , V_177 ) ;
args . V_176 . V_175 = V_177 ;
args . V_178 = & F_53 ;
F_48 ( V_2 , & args , false ) ;
V_2 -> V_54 -> V_45 -> V_179 ( V_2 -> V_56 , V_177 ) ;
return 0 ;
}
static void F_55 ( struct V_27 * V_28 ,
struct V_180 * V_181 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
V_181 -> V_182 = F_56 ( V_2 ) ;
V_181 -> V_183 = F_56 ( V_2 ) ;
V_181 -> V_184 = F_56 ( V_2 ) ;
V_181 -> V_185 = F_12 ( V_2 ) - V_2 -> V_186 -
V_2 -> V_187 ;
V_181 -> V_188 = V_2 -> V_186 ;
V_181 -> V_189 = V_2 -> V_187 ;
}
static int F_57 ( struct V_27 * V_28 ,
struct V_180 * V_181 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
T_2 V_190 ;
F_15 ( V_2 , ( V_155 | V_156 ) ,
L_34 ,
V_181 -> V_189 , V_181 -> V_188 ,
V_181 -> V_191 , V_181 -> V_185 ) ;
V_190 = V_181 -> V_189 + V_181 -> V_188 +
V_181 -> V_185 ;
if ( V_181 -> V_191 ) {
F_15 ( V_2 , ( V_155 | V_156 ) ,
L_35 ) ;
return - V_43 ;
}
if ( ! ( V_181 -> V_185 || ( V_181 -> V_189 &&
V_181 -> V_188 ) ) ) {
F_15 ( V_2 , ( V_155 | V_156 ) ,
L_36 ) ;
return - V_43 ;
}
if ( V_190 > F_56 ( V_2 ) ) {
F_15 ( V_2 , ( V_155 | V_156 ) ,
L_37 ,
V_190 , F_56 ( V_2 ) ) ;
return - V_43 ;
}
if ( ( V_190 == F_12 ( V_2 ) ) &&
( V_181 -> V_188 == V_2 -> V_186 ) &&
( V_181 -> V_189 == V_2 -> V_187 ) ) {
F_15 ( V_2 , ( V_155 | V_156 ) ,
L_38 ) ;
return 0 ;
}
if ( ( V_190 % V_2 -> V_44 . V_45 . V_46 ) ||
( V_181 -> V_188 % V_2 -> V_44 . V_45 . V_46 ) ||
( V_181 -> V_189 % V_2 -> V_44 . V_45 . V_46 ) ) {
F_15 ( V_2 , ( V_155 | V_156 ) ,
L_39 ,
V_2 -> V_44 . V_45 . V_46 ) ;
return - V_43 ;
}
V_2 -> V_192 = V_190 ;
V_2 -> V_193 = V_181 -> V_188 ;
V_2 -> V_194 = V_181 -> V_189 ;
if ( ( V_2 -> V_192 - V_2 -> V_193 ) != F_24 ( V_2 ) ) {
V_2 -> V_195 &= ~ V_196 ;
memset ( V_2 -> V_197 , 0 , sizeof( V_2 -> V_197 ) ) ;
}
F_48 ( V_2 , NULL , false ) ;
return 0 ;
}
static int F_58 ( struct V_27 * V_28 ,
struct V_198 * V_98 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
return F_59 ( V_2 , V_98 ) ;
}
static int F_60 ( struct V_27 * V_28 ,
enum V_199 V_60 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
T_1 V_200 = 0 ;
switch ( V_60 ) {
case V_201 :
return 1 ;
case V_202 :
V_200 = V_203 ;
break;
case V_204 :
V_200 = V_205 ;
break;
case V_206 :
V_200 = V_207 ;
break;
}
V_2 -> V_54 -> V_45 -> V_208 ( V_2 -> V_56 , V_200 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , struct V_209 * V_98 )
{
V_98 -> V_210 = V_211 | V_212 ;
switch ( V_98 -> V_213 ) {
case V_214 :
case V_215 :
V_98 -> V_210 |= V_216 | V_217 ;
break;
case V_218 :
if ( V_2 -> V_219 & V_220 )
V_98 -> V_210 |= V_216 | V_217 ;
break;
case V_221 :
if ( V_2 -> V_219 & V_222 )
V_98 -> V_210 |= V_216 | V_217 ;
break;
case V_223 :
case V_224 :
break;
default:
V_98 -> V_210 = 0 ;
break;
}
return 0 ;
}
static int F_62 ( struct V_27 * V_28 , struct V_209 * V_98 ,
T_2 * V_225 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_120 = 0 ;
switch ( V_98 -> V_49 ) {
case V_226 :
V_98 -> V_210 = F_24 ( V_2 ) ;
break;
case V_227 :
V_120 = F_61 ( V_2 , V_98 ) ;
break;
case V_228 :
V_98 -> V_229 = F_63 ( V_2 ) ;
V_98 -> V_210 = V_230 ;
break;
case V_231 :
V_120 = F_64 ( V_2 , V_98 ) ;
break;
case V_232 :
V_120 = F_65 ( V_2 , V_98 , V_225 ) ;
break;
default:
F_66 ( V_2 , L_40 ) ;
V_120 = - V_74 ;
}
return V_120 ;
}
static int F_67 ( struct V_1 * V_2 , struct V_209 * V_98 )
{
struct V_233 * V_234 ;
T_1 V_235 = 0 , V_236 = 0 ;
int V_120 = 0 ;
F_15 ( V_2 , V_37 ,
L_41 ,
V_98 -> V_213 , V_98 -> V_210 ) ;
switch ( V_98 -> V_213 ) {
case V_214 :
case V_215 :
if ( V_98 -> V_210 ^ ( V_211 | V_212 |
V_216 | V_217 ) ) {
F_30 ( V_2 , L_40 ) ;
return - V_43 ;
}
return 0 ;
case V_218 :
if ( V_98 -> V_210 == ( V_211 | V_212 |
V_216 | V_217 ) ) {
V_235 = V_220 ;
F_15 ( V_2 , V_37 ,
L_42 ) ;
} else if ( V_98 -> V_210 == ( V_211 | V_212 ) ) {
V_236 = V_220 ;
F_15 ( V_2 , V_37 ,
L_43 ) ;
} else {
return - V_43 ;
}
break;
case V_221 :
if ( V_98 -> V_210 == ( V_211 | V_212 |
V_216 | V_217 ) ) {
V_235 = V_222 ;
F_15 ( V_2 , V_37 ,
L_42 ) ;
} else if ( V_98 -> V_210 == ( V_211 | V_212 ) ) {
V_236 = V_222 ;
F_15 ( V_2 , V_37 ,
L_43 ) ;
} else {
return - V_43 ;
}
break;
case V_223 :
case V_224 :
if ( V_98 -> V_210 ^ ( V_211 | V_212 ) ) {
F_30 ( V_2 , L_40 ) ;
return - V_43 ;
}
return 0 ;
case V_237 :
case V_238 :
case V_239 :
case V_240 :
case V_241 :
case V_242 :
case V_243 :
case V_244 :
case V_245 :
case V_246 :
if ( V_98 -> V_210 ) {
F_30 ( V_2 , L_40 ) ;
return - V_43 ;
}
return 0 ;
default:
return - V_43 ;
}
if ( V_2 -> V_219 == ( ( V_2 -> V_219 & ~ V_236 ) | V_235 ) )
return 0 ;
V_2 -> V_219 = ( ( V_2 -> V_219 & ~ V_236 ) | V_235 ) ;
V_2 -> V_195 |= V_247 ;
F_20 ( V_2 ) ;
if ( V_2 -> V_60 == V_61 ) {
V_234 = F_68 ( sizeof( * V_234 ) ) ;
if ( ! V_234 ) {
F_21 ( V_2 ) ;
return - V_248 ;
}
F_69 ( V_2 , & V_234 -> V_249 ,
& V_234 -> V_250 ) ;
V_120 = V_2 -> V_54 -> V_251 ( V_2 -> V_56 , V_234 ) ;
F_70 ( V_234 ) ;
}
F_21 ( V_2 ) ;
return V_120 ;
}
static int F_71 ( struct V_27 * V_28 , struct V_209 * V_98 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_120 ;
switch ( V_98 -> V_49 ) {
case V_252 :
V_120 = F_67 ( V_2 , V_98 ) ;
break;
case V_253 :
V_120 = F_72 ( V_2 , V_98 ) ;
break;
case V_254 :
V_120 = F_73 ( V_2 , V_98 ) ;
break;
default:
F_30 ( V_2 , L_40 ) ;
V_120 = - V_74 ;
}
return V_120 ;
}
static T_2 F_74 ( struct V_27 * V_28 )
{
return V_255 ;
}
static T_2 F_75 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
return sizeof( V_2 -> V_256 ) ;
}
static int F_76 ( struct V_27 * V_28 , T_2 * V_257 , T_1 * V_258 , T_1 * V_259 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_6 ;
if ( V_259 )
* V_259 = V_260 ;
if ( ! V_257 )
return 0 ;
for ( V_6 = 0 ; V_6 < V_255 ; V_6 ++ )
V_257 [ V_6 ] = V_2 -> V_197 [ V_6 ] ;
if ( V_258 )
memcpy ( V_258 , V_2 -> V_256 , F_75 ( V_28 ) ) ;
return 0 ;
}
static int F_77 ( struct V_27 * V_28 , const T_2 * V_257 ,
const T_1 * V_258 , const T_1 V_259 )
{
struct V_233 * V_234 ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_6 , V_120 = 0 ;
if ( V_2 -> V_44 . V_45 . V_46 > 1 ) {
F_30 ( V_2 ,
L_44 ) ;
return - V_74 ;
}
if ( V_259 != V_261 && V_259 != V_260 )
return - V_74 ;
if ( ! V_257 && ! V_258 )
return 0 ;
if ( V_257 ) {
for ( V_6 = 0 ; V_6 < V_255 ; V_6 ++ )
V_2 -> V_197 [ V_6 ] = V_257 [ V_6 ] ;
V_2 -> V_195 |= V_196 ;
}
if ( V_258 ) {
memcpy ( & V_2 -> V_256 , V_258 , F_75 ( V_28 ) ) ;
V_2 -> V_195 |= V_262 ;
}
F_20 ( V_2 ) ;
if ( V_2 -> V_60 == V_61 ) {
V_234 = F_68 ( sizeof( * V_234 ) ) ;
if ( ! V_234 ) {
F_21 ( V_2 ) ;
return - V_248 ;
}
F_69 ( V_2 , & V_234 -> V_249 ,
& V_234 -> V_250 ) ;
V_120 = V_2 -> V_54 -> V_251 ( V_2 -> V_56 , V_234 ) ;
F_70 ( V_234 ) ;
}
F_21 ( V_2 ) ;
return V_120 ;
}
static void F_78 ( struct V_1 * V_2 )
{
int V_6 ;
if ( ! F_41 ( V_2 -> V_96 ) )
return;
F_44 (i) {
F_79 ( V_2 -> V_20 [ V_6 ] . V_263 , V_264 , 1 ) ;
F_80 ( & V_2 -> V_20 [ V_6 ] . V_265 ) ;
}
}
static void F_81 ( struct V_1 * V_2 )
{
int V_6 ;
F_44 (i) {
F_82 ( & V_2 -> V_20 [ V_6 ] . V_265 ) ;
F_79 ( V_2 -> V_20 [ V_6 ] . V_263 , V_266 , 0 ) ;
}
}
static int F_83 ( struct V_1 * V_2 ,
struct V_267 * V_268 )
{
struct V_3 * V_4 = NULL ;
struct V_269 * V_270 ;
T_5 V_271 ;
int V_6 , V_272 ;
T_4 V_273 ;
F_44 (i) {
if ( V_2 -> V_20 [ V_6 ] . type & V_24 ) {
V_4 = V_2 -> V_20 [ V_6 ] . V_4 ;
break;
}
}
if ( ! V_4 ) {
F_84 ( V_2 , L_45 ) ;
return - 1 ;
}
V_272 = V_4 -> V_274 ;
V_4 -> V_275 . V_276 [ V_272 ] . V_268 = V_268 ;
V_270 = F_85 ( & V_4 -> V_277 ) ;
memset ( V_270 , 0 , sizeof( * V_270 ) ) ;
V_273 = 1 << V_278 ;
V_270 -> V_210 . V_279 . V_280 = V_273 ;
V_273 = V_268 -> V_171 & V_281 ;
V_273 = V_273 << V_282 ;
V_270 -> V_210 . V_280 |= F_86 ( V_273 ) ;
V_271 = F_87 ( & V_2 -> V_112 -> V_28 , V_268 -> V_210 ,
F_88 ( V_268 ) , V_283 ) ;
if ( F_89 ( F_90 ( & V_2 -> V_112 -> V_28 , V_271 ) ) ) {
F_84 ( V_2 , L_46 ) ;
return - V_248 ;
}
F_91 ( V_270 , V_271 , F_88 ( V_268 ) ) ;
V_270 -> V_210 . V_284 = 1 ;
V_4 -> V_274 = ( V_4 -> V_274 + 1 ) % V_4 -> V_285 ;
V_273 = F_92 ( & V_4 -> V_277 ) ;
V_4 -> V_286 . V_210 . V_287 = F_86 ( V_273 ) ;
F_93 () ;
F_94 () ;
F_95 ( V_4 -> V_286 . V_288 , V_4 -> V_289 ) ;
F_96 () ;
for ( V_6 = 0 ; V_6 < V_290 ; V_6 ++ ) {
if ( F_97 ( V_4 ) )
break;
F_98 ( 100 , 200 ) ;
}
if ( ! F_97 ( V_4 ) ) {
F_84 ( V_2 , L_47 ) ;
return - 1 ;
}
V_270 = (struct V_269 * ) F_99 ( & V_4 -> V_277 ) ;
F_100 ( & V_2 -> V_112 -> V_28 , F_101 ( V_270 ) ,
F_102 ( V_270 ) , V_283 ) ;
V_4 -> V_291 = ( V_4 -> V_291 + 1 ) % V_4 -> V_285 ;
V_4 -> V_275 . V_276 [ V_272 ] . V_268 = NULL ;
return 0 ;
}
static int F_103 ( struct V_1 * V_2 )
{
T_4 V_292 , V_293 , V_294 , V_171 ;
struct V_295 * V_296 ;
struct V_12 * V_13 = NULL ;
struct V_297 * V_297 ;
union V_298 * V_299 ;
int V_6 , V_300 , V_120 = 0 ;
T_1 * V_301 ;
F_44 (i) {
if ( V_2 -> V_20 [ V_6 ] . type & V_21 ) {
V_13 = V_2 -> V_20 [ V_6 ] . V_13 ;
break;
}
}
if ( ! V_13 ) {
F_84 ( V_2 , L_48 ) ;
return - 1 ;
}
for ( V_300 = 0 ; V_300 < V_290 ; V_300 ++ ) {
if ( ! F_104 ( V_13 ) ) {
F_98 ( 100 , 200 ) ;
continue;
}
V_292 = F_105 ( * V_13 -> V_302 ) ;
V_293 = F_106 ( & V_13 -> V_303 ) ;
F_107 () ;
V_299 = (union V_298 * ) F_99 ( & V_13 -> V_303 ) ;
V_294 = V_13 -> V_304 & V_148 ;
V_297 = & V_13 -> V_305 [ V_294 ] ;
V_296 = & V_299 -> V_306 ;
V_171 = F_105 ( V_296 -> V_307 ) ;
V_301 = ( T_1 * ) ( F_108 ( V_297 -> V_210 ) +
V_296 -> V_308 +
V_297 -> V_309 ) ;
if ( F_109 ( V_301 , V_2 -> V_96 -> V_310 ) &&
F_109 ( V_301 + V_311 ,
V_2 -> V_96 -> V_310 ) ) {
for ( V_6 = V_312 ; V_6 < V_171 ; V_6 ++ )
if ( V_301 [ V_6 ] != ( unsigned char ) ( V_6 & 0xff ) ) {
V_120 = - 1 ;
break;
}
F_110 ( V_13 , 1 ) ;
F_111 ( & V_13 -> V_303 ) ;
break;
}
F_30 ( V_2 , L_49 ) ;
F_110 ( V_13 , 1 ) ;
F_111 ( & V_13 -> V_303 ) ;
}
if ( V_300 == V_290 ) {
F_84 ( V_2 , L_50 ) ;
return - 1 ;
}
F_112 ( V_2 , V_13 ) ;
return V_120 ;
}
static int F_113 ( struct V_1 * V_2 , T_2 V_313 )
{
struct V_71 V_127 ;
struct V_267 * V_268 = NULL ;
int V_120 = 0 , V_6 ;
T_2 V_314 ;
T_1 * V_315 ;
if ( ! F_41 ( V_2 -> V_96 ) ) {
F_84 ( V_2 , L_22 ) ;
return - V_43 ;
}
F_81 ( V_2 ) ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
V_127 . V_62 = true ;
V_127 . V_75 = V_316 ;
V_127 . V_313 = V_313 ;
V_2 -> V_54 -> V_45 -> V_95 ( V_2 -> V_56 , & V_127 ) ;
F_114 ( 500 ) ;
V_314 = V_2 -> V_96 -> V_175 + V_312 ;
V_268 = F_115 ( V_2 -> V_96 , V_314 ) ;
if ( ! V_268 ) {
F_30 ( V_2 , L_51 ) ;
V_120 = - V_248 ;
goto V_317;
}
V_315 = F_116 ( V_268 , V_314 ) ;
F_117 ( V_315 , V_2 -> V_96 -> V_310 ) ;
F_117 ( V_315 + V_311 , V_2 -> V_96 -> V_310 ) ;
memset ( V_315 + ( 2 * V_311 ) , 0x77 , ( V_312 - ( 2 * V_311 ) ) ) ;
for ( V_6 = V_312 ; V_6 < V_314 ; V_6 ++ )
V_315 [ V_6 ] = ( unsigned char ) ( V_6 & 0xff ) ;
V_120 = F_83 ( V_2 , V_268 ) ;
if ( V_120 )
goto V_317;
V_120 = F_103 ( V_2 ) ;
if ( V_120 )
goto V_317;
F_15 ( V_2 , V_318 , L_52 ) ;
V_317:
F_118 ( V_268 ) ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
V_127 . V_62 = true ;
V_127 . V_75 = V_316 ;
V_127 . V_313 = V_319 ;
V_2 -> V_54 -> V_45 -> V_95 ( V_2 -> V_56 , & V_127 ) ;
F_114 ( 500 ) ;
F_78 ( V_2 ) ;
return V_120 ;
}
static void F_119 ( struct V_27 * V_28 ,
struct V_320 * V_321 , T_3 * V_5 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
F_15 ( V_2 , V_37 ,
L_53 ,
( V_321 -> V_322 & V_323 ) ,
( V_321 -> V_322 & V_324 ) >> 2 ) ;
memset ( V_5 , 0 , sizeof( T_3 ) * V_36 ) ;
if ( V_321 -> V_322 & V_323 ) {
if ( F_113 ( V_2 ,
V_325 ) ) {
V_5 [ V_326 ] = 1 ;
V_321 -> V_322 |= V_327 ;
}
}
if ( V_2 -> V_54 -> V_45 -> V_328 -> V_329 ( V_2 -> V_56 ) ) {
V_5 [ V_330 ] = 1 ;
V_321 -> V_322 |= V_327 ;
}
if ( V_2 -> V_54 -> V_45 -> V_328 -> V_331 ( V_2 -> V_56 ) ) {
V_5 [ V_332 ] = 1 ;
V_321 -> V_322 |= V_327 ;
}
if ( V_2 -> V_54 -> V_45 -> V_328 -> V_333 ( V_2 -> V_56 ) ) {
V_5 [ V_334 ] = 1 ;
V_321 -> V_322 |= V_327 ;
}
if ( V_2 -> V_54 -> V_45 -> V_328 -> V_335 ( V_2 -> V_56 ) ) {
V_5 [ V_336 ] = 1 ;
V_321 -> V_322 |= V_327 ;
}
if ( V_2 -> V_54 -> V_45 -> V_328 -> V_337 ( V_2 -> V_56 ) ) {
V_5 [ V_338 ] = 1 ;
V_321 -> V_322 |= V_327 ;
}
}
static int F_120 ( struct V_27 * V_28 ,
const struct V_339 * V_340 ,
const void * V_210 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
T_2 V_273 ;
switch ( V_340 -> V_341 ) {
case V_342 :
V_273 = * ( T_2 * ) V_210 ;
if ( V_273 < V_343 || V_273 > V_344 ) {
F_15 ( V_2 , V_37 ,
L_54 ,
V_343 , V_344 ) ;
return - V_43 ;
}
V_2 -> V_345 = * ( T_2 * ) V_210 ;
break;
default:
return - V_74 ;
}
return 0 ;
}
static int F_121 ( struct V_27 * V_28 ,
const struct V_339 * V_340 , void * V_210 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
switch ( V_340 -> V_341 ) {
case V_342 :
* ( T_2 * ) V_210 = V_2 -> V_345 ;
break;
default:
return - V_74 ;
}
return 0 ;
}
static int F_122 ( struct V_27 * V_28 , struct V_346 * V_347 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
struct V_52 V_53 ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_2 -> V_54 -> V_45 -> V_55 ( V_2 -> V_56 , & V_53 ) ;
if ( ! V_53 . V_348 ) {
F_30 ( V_2 , L_55 ) ;
return - V_74 ;
}
if ( V_53 . V_349 . V_350 & V_351 )
V_347 -> V_352 = V_353 ;
if ( V_53 . V_349 . V_350 & V_354 )
V_347 -> V_352 |= V_355 ;
if ( V_53 . V_356 & V_351 )
V_347 -> V_57 = V_353 ;
if ( V_53 . V_356 & V_354 )
V_347 -> V_57 |= V_355 ;
if ( V_53 . V_349 . V_357 & V_351 )
V_347 -> V_358 = V_353 ;
if ( V_53 . V_349 . V_357 & V_354 )
V_347 -> V_358 |= V_355 ;
V_347 -> V_359 = V_53 . V_349 . V_359 ;
V_347 -> V_360 = V_53 . V_349 . V_361 ;
V_347 -> V_362 = V_53 . V_349 . V_363 ;
V_347 -> V_364 = V_53 . V_364 ;
return 0 ;
}
static int F_123 ( struct V_27 * V_28 , struct V_346 * V_347 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
struct V_52 V_53 ;
struct V_71 V_72 ;
if ( ! V_2 -> V_54 -> V_45 -> V_73 ( V_2 -> V_56 ) ) {
F_30 ( V_2 , L_4 ) ;
return - V_74 ;
}
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_2 -> V_54 -> V_45 -> V_55 ( V_2 -> V_56 , & V_53 ) ;
if ( ! V_53 . V_348 ) {
F_30 ( V_2 , L_55 ) ;
return - V_74 ;
}
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . V_75 |= V_365 ;
if ( ! ( V_347 -> V_352 & ( V_353 |
V_355 ) ) ||
( ( V_347 -> V_352 & ( V_353 |
V_355 ) ) !=
V_347 -> V_352 ) ) {
F_15 ( V_2 , V_37 ,
L_56 ,
V_347 -> V_352 ) ;
return - V_43 ;
}
if ( V_347 -> V_352 & V_353 )
V_72 . V_349 . V_350 = V_351 ;
if ( V_347 -> V_352 & V_355 )
V_72 . V_349 . V_350 |= V_354 ;
V_72 . V_349 . V_361 = V_347 -> V_360 ;
V_72 . V_349 . V_363 = V_347 -> V_362 ;
V_72 . V_349 . V_359 = V_347 -> V_359 ;
V_72 . V_62 = true ;
V_2 -> V_54 -> V_45 -> V_95 ( V_2 -> V_56 , & V_72 ) ;
return 0 ;
}
void F_124 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
if ( F_5 ( V_2 ) )
V_28 -> V_366 = & V_367 ;
else
V_28 -> V_366 = & V_368 ;
}
