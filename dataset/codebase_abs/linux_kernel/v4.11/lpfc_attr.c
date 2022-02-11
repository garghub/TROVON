static void
F_1 ( int V_1 , char V_2 [] )
{
int V_3 , V_4 ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
V_4 = ( V_1 & 0xf ) ;
if ( V_4 <= 9 )
V_2 [ 7 - V_3 ] = 0x30 + V_4 ;
else
V_2 [ 7 - V_3 ] = 0x61 + V_4 - 10 ;
V_1 = ( V_1 >> 4 ) ;
}
V_2 [ 8 ] = 0 ;
return;
}
static T_1
F_2 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
return snprintf ( V_9 , V_10 , V_11 L_1 ) ;
}
static T_1
F_3 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_19 & V_20 )
return snprintf ( V_9 , V_10 , L_2 ) ;
else
return snprintf ( V_9 , V_10 , L_3 ) ;
}
static T_1
F_5 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = F_6 ( V_13 ) ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
char * V_31 ;
int V_32 = 0 ;
if ( ! ( V_18 -> V_33 & V_34 ) ) {
V_32 += snprintf ( V_9 , V_10 , L_4 ) ;
return V_32 ;
}
if ( V_18 -> V_35 ) {
if ( ! V_18 -> V_36 ) {
V_32 = snprintf ( V_9 , V_10 ,
L_5 ,
F_7 ( V_15 -> V_37 . V_38 . V_39 ) ) ;
return V_32 ;
}
if ( V_18 -> V_36 -> V_40 )
V_31 = L_6 ;
else
V_31 = L_7 ;
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_8 ,
V_31 ) ;
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_9 ,
L_10 ,
V_18 -> V_41 ,
F_7 ( V_15 -> V_37 . V_38 . V_39 ) ,
F_7 ( V_15 -> V_42 . V_38 . V_39 ) ,
V_18 -> V_36 -> V_40 ) ;
V_32 += snprintf ( V_9 + V_32 , V_10 ,
L_11 ) ;
V_22 = (struct V_21 * ) V_18 -> V_36 -> V_43 ;
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_12 ,
F_8 ( & V_22 -> V_44 ) ,
F_8 ( & V_22 -> V_45 ) ,
F_8 ( & V_22 -> V_46 ) ) ;
if ( F_8 ( & V_22 -> V_44 ) !=
F_8 ( & V_22 -> V_47 ) ) {
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_13 ,
F_8 ( & V_22 -> V_44 ) ,
F_8 ( & V_22 -> V_47 ) ) ;
}
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_14 ,
F_8 ( & V_22 -> V_48 ) ,
F_8 ( & V_22 -> V_49 ) ,
F_8 ( & V_22 -> V_50 ) ,
F_8 ( & V_22 -> V_51 ) ) ;
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_15 ,
F_8 ( & V_22 -> V_52 ) ,
F_8 ( & V_22 -> V_53 ) ) ;
if ( F_8 ( & V_22 -> V_52 ) !=
F_8 ( & V_22 -> V_54 ) ) {
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_16 ,
F_8 ( & V_22 -> V_52 ) ,
F_8 ( & V_22 -> V_54 ) ) ;
}
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_17 ,
F_8 ( & V_22 -> V_55 ) ,
F_8 ( & V_22 -> V_56 ) ,
F_8 ( & V_22 -> V_57 ) ,
F_8 ( & V_22 -> V_58 ) ) ;
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_18 ,
F_8 ( & V_22 -> V_59 ) ,
F_8 ( & V_22 -> V_60 ) ) ;
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_19 ,
F_8 ( & V_22 -> V_61 ) ,
F_8 ( & V_22 -> V_62 ) ,
F_8 ( & V_22 -> V_63 ) ) ;
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_20 ,
F_8 ( & V_22 -> V_64 ) ,
F_8 ( & V_22 -> V_65 ) ,
F_8 ( & V_22 -> V_66 ) ) ;
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 , L_1 ) ;
return V_32 ;
}
V_24 = V_15 -> V_24 ;
if ( ! V_24 ) {
V_32 = snprintf ( V_9 , V_10 ,
L_21 ,
F_7 ( V_15 -> V_37 . V_38 . V_39 ) ) ;
return V_32 ;
}
V_32 = snprintf ( V_9 , V_10 , L_22 ) ;
F_9 ( V_13 -> V_67 ) ;
V_26 = (struct V_25 * ) V_24 -> V_43 ;
if ( V_24 -> V_40 )
V_31 = L_23 ;
else
V_31 = L_24 ;
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_25 ,
L_26 ,
V_18 -> V_41 ,
F_7 ( V_15 -> V_37 . V_38 . V_39 ) ,
F_7 ( V_15 -> V_42 . V_38 . V_39 ) ,
V_24 -> V_40 , V_31 ) ;
F_10 (rport, &lport->rport_list, list) {
V_30 = V_28 -> V_68 ;
switch ( V_30 -> V_69 ) {
case V_70 :
V_31 = L_23 ;
break;
case V_71 :
V_31 = L_24 ;
break;
default:
V_31 = L_27 ;
break;
}
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_28 ) ;
if ( V_18 -> V_41 >= 10 )
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 , L_29 ) ;
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 , L_30 ,
V_30 -> V_72 ) ;
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 , L_31 ,
V_30 -> V_73 ) ;
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 , L_32 ,
V_30 -> V_40 ) ;
switch ( V_30 -> V_74 ) {
case V_75 :
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_33 ) ;
break;
case V_76 :
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_34 ) ;
break;
case V_77 :
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_35 ) ;
break;
default:
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_36 ,
V_30 -> V_74 ) ;
break;
}
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 , L_37 , V_31 ) ;
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 , L_1 ) ;
}
F_11 ( V_13 -> V_67 ) ;
V_32 += snprintf ( V_9 + V_32 , V_10 , L_38 ) ;
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_39 ,
V_18 -> V_78 ,
V_18 -> V_79 ) ;
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_40 ,
V_18 -> V_80 ,
V_18 -> V_81 ,
V_18 -> V_82 ) ;
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_41 , V_18 -> V_83 ) ;
return V_32 ;
}
static T_1
F_12 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_84 )
if ( V_18 -> V_85 & V_86 )
return snprintf ( V_9 , V_10 , L_42 ) ;
else
return snprintf ( V_9 , V_10 ,
L_43 ) ;
else
return snprintf ( V_9 , V_10 ,
L_44 ) ;
}
static T_1
F_13 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_45 ,
( unsigned long long ) V_18 -> V_87 ) ;
}
static T_1
F_14 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_45 ,
( unsigned long long ) V_18 -> V_88 ) ;
}
static T_1
F_15 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_45 ,
( unsigned long long ) V_18 -> V_89 ) ;
}
static T_1
F_16 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_90 = F_4 ( V_6 ) ;
return snprintf ( V_9 , V_10 , L_46 , F_17 ( V_90 ) ) ;
}
static T_1
F_18 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_46 , V_18 -> V_91 ) ;
}
static T_1
F_19 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_47 , V_18 -> V_92 ) ;
}
static T_1
F_20 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_46 , V_18 -> V_93 ) ;
}
static T_1
F_21 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_46 , V_18 -> V_94 ) ;
}
static T_1
F_22 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_46 , V_18 -> V_95 ) ;
}
static T_1
F_23 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_47 ,
( V_18 -> V_96 . V_97 & V_98 ) ) ;
}
static T_1
F_24 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_46 , V_18 -> V_99 ) ;
}
static T_1
F_25 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_100 ;
T_3 V_101 ;
char V_102 [ V_103 ] ;
int V_32 ;
F_26 ( V_18 , V_102 , 1 ) ;
V_100 = V_18 -> V_104 . V_105 . V_100 ;
V_101 = V_18 -> V_104 . V_105 . V_101 ;
if ( V_18 -> V_106 < V_107 )
V_32 = snprintf ( V_9 , V_10 , L_48 ,
V_102 , V_18 -> V_106 ) ;
else
V_32 = snprintf ( V_9 , V_10 , L_49 ,
V_102 , V_18 -> V_106 , V_100 , V_101 ) ;
return V_32 ;
}
static T_1
F_27 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
char V_2 [ 9 ] ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_4 * V_108 = & V_18 -> V_109 ;
F_1 ( V_108 -> V_110 . V_111 , V_2 ) ;
return snprintf ( V_9 , V_10 , L_46 , V_2 ) ;
}
static T_1
F_28 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
char V_102 [ V_103 ] ;
if ( V_18 -> V_106 < V_107 )
return snprintf ( V_9 , V_10 , L_46 , V_18 -> V_112 ) ;
F_26 ( V_18 , V_102 , 1 ) ;
return snprintf ( V_9 , V_10 , L_46 , V_102 ) ;
}
static T_1
F_29 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_32 = 0 ;
switch ( V_18 -> V_113 ) {
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
if ( V_18 -> V_19 & V_120 )
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_50 ) ;
else
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_51 ) ;
break;
case V_121 :
case V_122 :
case V_123 :
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 , L_52 ) ;
switch ( V_15 -> V_69 ) {
case V_124 :
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_53 ) ;
break;
case V_125 :
case V_126 :
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_54 ) ;
break;
case V_132 :
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 , L_55 ) ;
break;
case V_133 :
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 , L_56 ) ;
break;
case V_134 :
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_57 ) ;
break;
}
if ( V_18 -> V_96 . V_97 & V_98 )
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_58 ) ;
else if ( V_18 -> V_135 == V_136 ) {
if ( V_15 -> V_137 & V_138 )
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_59 ) ;
else
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_60 ) ;
} else {
if ( V_15 -> V_137 & V_139 )
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_61 ) ;
else
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_62 ) ;
}
}
return V_32 ;
}
static T_1
F_30 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_106 < V_107 )
return snprintf ( V_9 , V_10 , L_63 ) ;
if ( V_18 -> V_104 . V_140 . V_141 == V_142 ) {
if ( V_18 -> V_104 . V_140 . V_143 == V_144 )
return snprintf ( V_9 , V_10 , L_64 ) ;
if ( V_18 -> V_104 . V_140 . V_143 == V_145 )
return snprintf ( V_9 , V_10 , L_63 ) ;
}
return snprintf ( V_9 , V_10 , L_65 ) ;
}
static T_1
F_31 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_47 ,
V_18 -> V_104 . V_105 . V_146 ) ;
}
static T_1
F_32 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_147 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_148 = - V_149 ;
if ( ( strncmp ( V_9 , L_66 , sizeof( L_66 ) - 1 ) == 0 ) &&
( V_18 -> V_113 == V_118 ) )
V_148 = V_18 -> V_150 ( V_18 , V_151 ) ;
else if ( ( strncmp ( V_9 , L_67 , sizeof( L_67 ) - 1 ) == 0 ) &&
( V_18 -> V_113 >= V_121 ) )
V_148 = V_18 -> V_152 ( V_18 , V_151 ) ;
if ( V_148 == 0 )
return strlen ( V_9 ) ;
else
return V_148 ;
}
static T_1
F_33 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
return snprintf ( V_9 , V_10 , L_47 ,
V_15 -> V_153 + V_15 -> V_154 ) ;
}
static int
F_34 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_6 * V_155 ;
int V_156 = V_157 ;
if ( ( V_15 -> V_137 & V_158 ) ||
( V_18 -> V_96 . V_97 & V_159 ) )
return - V_160 ;
V_155 = F_35 ( V_18 -> V_161 , V_162 ) ;
if ( ! V_155 )
return - V_163 ;
memset ( ( void * ) V_155 , 0 , sizeof ( T_6 ) ) ;
V_155 -> V_38 . V_164 . V_165 = V_166 ;
V_155 -> V_38 . V_164 . V_167 = V_168 ;
V_156 = F_36 ( V_18 , V_155 , V_169 * 2 ) ;
if ( ( V_156 == V_170 ) &&
( V_155 -> V_38 . V_164 . V_171 == 0 ||
V_155 -> V_38 . V_164 . V_171 == V_172 ) ) {
memset ( ( void * ) V_155 , 0 , sizeof ( T_6 ) ) ;
F_37 ( V_18 , V_155 , V_18 -> V_173 ,
V_18 -> V_174 ) ;
V_156 = F_36 ( V_18 , V_155 ,
V_18 -> V_175 * 2 ) ;
if ( ( V_156 == V_170 ) &&
( V_155 -> V_38 . V_164 . V_171 == V_176 ) )
F_38 ( V_18 , V_177 , V_178 | V_179 ,
L_68
L_69 ) ;
}
F_39 ( V_18 ) ;
if ( V_156 != V_180 )
F_40 ( V_155 , V_18 -> V_161 ) ;
if ( V_156 == V_157 )
return - V_181 ;
return 0 ;
}
int
F_41 ( struct V_17 * V_18 , struct V_182 * V_183 , T_7 * V_184 )
{
int V_185 = 0 ;
F_9 ( V_184 ) ;
while ( ! F_42 ( V_183 ) ) {
F_11 ( V_184 ) ;
F_43 ( 20 ) ;
if ( V_185 ++ > 250 ) {
F_38 ( V_18 , V_186 , V_187 ,
L_70 ,
L_71 ,
L_72 ) ;
return 0 ;
}
F_9 ( V_184 ) ;
}
F_11 ( V_184 ) ;
return 1 ;
}
static int
F_44 ( struct V_17 * V_18 , T_2 type )
{
struct V_188 V_189 ;
struct V_190 * V_191 = NULL ;
struct V_192 * V_193 ;
struct V_194 * V_195 ;
int V_148 = 0 ;
int V_3 ;
int V_196 ;
F_45 ( & V_189 ) ;
V_196 = F_46 ( V_18 , & V_148 , & V_189 ,
V_197 ) ;
if ( V_196 == 0 )
return - V_163 ;
F_47 ( & V_189 ) ;
if ( V_148 != 0 )
return - V_181 ;
V_195 = & V_18 -> V_96 ;
if ( V_18 -> V_106 != V_107 ) {
for ( V_3 = 0 ; V_3 < V_195 -> V_198 ; V_3 ++ ) {
V_193 = & V_195 -> V_199 [ V_3 ] ;
if ( ! F_41 ( V_18 , & V_193 -> V_200 ,
& V_18 -> V_201 ) )
goto V_202;
}
} else {
F_10 (qp, &phba->sli4_hba.lpfc_wq_list, wq_list) {
V_193 = V_191 -> V_193 ;
if ( ! V_193 )
continue;
if ( ! F_41 ( V_18 , & V_193 -> V_200 ,
& V_193 -> V_203 ) )
goto V_202;
}
}
V_202:
F_45 ( & V_189 ) ;
V_196 = F_46 ( V_18 , & V_148 , & V_189 , type ) ;
if ( V_196 == 0 )
return - V_163 ;
F_47 ( & V_189 ) ;
if ( V_148 != 0 )
return - V_181 ;
return 0 ;
}
int
F_48 ( struct V_17 * V_18 )
{
struct V_188 V_189 ;
int V_148 = 0 ;
int V_196 ;
if ( ! V_18 -> V_204 )
return - V_205 ;
if ( ! ( V_18 -> V_206 -> V_137 & V_158 ) ) {
V_148 = F_44 ( V_18 , V_207 ) ;
if ( V_148 != 0 )
return V_148 ;
}
F_45 ( & V_189 ) ;
V_196 = F_46 ( V_18 , & V_148 , & V_189 ,
V_208 ) ;
if ( V_196 == 0 )
return - V_163 ;
F_47 ( & V_189 ) ;
if ( V_148 != 0 )
return - V_181 ;
return 0 ;
}
static T_1
F_49 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_147 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_148 = - V_149 ;
if ( ! V_18 -> V_204 )
return - V_205 ;
if ( strncmp ( V_9 , L_73 , sizeof( L_73 ) - 1 ) == 0 )
V_148 = V_18 -> F_48 ( V_18 ) ;
if ( V_148 == 0 )
return strlen ( V_9 ) ;
else
return V_148 ;
}
int
F_50 ( struct V_17 * V_18 )
{
struct V_209 V_210 = { 0 } ;
int V_3 ;
F_43 ( 100 ) ;
F_51 ( V_18 -> V_104 . V_38 . V_211 . V_212 ,
& V_210 . V_213 ) ;
if ( ! F_52 ( V_214 , & V_210 ) &&
! F_52 ( V_215 , & V_210 ) )
return - V_160 ;
for ( V_3 = 0 ; V_3 < V_216 ; V_3 ++ ) {
F_43 ( 10 ) ;
F_51 ( V_18 -> V_104 . V_38 . V_211 . V_212 ,
& V_210 . V_213 ) ;
if ( ! F_52 ( V_215 , & V_210 ) )
continue;
if ( ! F_52 ( V_214 , & V_210 ) )
continue;
if ( ! F_52 ( V_217 , & V_210 ) )
continue;
break;
}
if ( V_3 < V_216 )
return 0 ;
else
return - V_181 ;
}
static T_1
F_53 ( struct V_17 * V_18 , T_2 V_218 )
{
struct V_188 V_189 ;
struct V_219 * V_220 = V_18 -> V_221 ;
T_2 V_222 ;
T_2 V_223 ;
T_2 V_224 ;
int V_148 = 0 , V_196 = 0 ;
int V_225 = 1 , V_226 ;
if ( ! V_18 -> V_204 )
return - V_205 ;
if ( ( V_18 -> V_106 < V_107 ) ||
( F_52 ( V_227 , & V_18 -> V_104 . V_228 ) !=
V_229 ) )
return - V_160 ;
V_222 = V_18 -> V_206 -> V_137 ;
V_223 = V_18 -> V_230 ;
if ( V_18 -> V_230 ) {
F_54 ( V_220 ) ;
V_18 -> V_230 = 0 ;
}
if ( V_218 == V_231 )
V_18 -> V_19 |= V_232 ;
V_148 = F_44 ( V_18 , V_207 ) ;
if ( V_148 != 0 ) {
V_18 -> V_19 &= ~ V_232 ;
return V_148 ;
}
F_43 ( 100 ) ;
V_224 = F_55 ( V_18 -> V_104 . V_233 +
V_234 ) ;
if ( V_218 == V_231 )
V_224 |= V_235 ;
else if ( V_218 == V_236 )
V_224 |= V_237 ;
else if ( V_218 == V_238 )
V_224 |= V_239 ;
F_56 ( V_224 , V_18 -> V_104 . V_233 +
V_234 ) ;
F_55 ( V_18 -> V_104 . V_233 + V_234 ) ;
V_196 = F_50 ( V_18 ) ;
if ( V_196 == - V_160 ) {
F_38 ( V_18 , V_177 , V_179 ,
L_74
L_75 , V_224 ) ;
} else if ( V_196 == - V_181 ) {
F_38 ( V_18 , V_177 , V_179 ,
L_76
L_75 , V_224 ) ;
return V_196 ;
}
if ( V_222 & V_158 )
goto V_202;
F_45 ( & V_189 ) ;
V_225 = F_46 ( V_18 , & V_148 , & V_189 ,
V_208 ) ;
if ( ! V_225 )
goto V_202;
F_47 ( & V_189 ) ;
V_202:
if ( V_223 ) {
V_226 =
F_57 ( V_18 , V_223 ) ;
if ( ! V_226 )
V_18 -> V_230 = V_223 ;
}
if ( ! V_196 ) {
if ( ! V_225 )
V_196 = - V_163 ;
else if ( V_148 )
V_196 = - V_181 ;
}
return V_196 ;
}
static T_1
F_58 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_47 , V_18 -> V_240 ) ;
}
static T_1
F_59 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
char * V_241 ;
if ( V_18 -> V_113 == V_119 )
V_241 = L_77 ;
else if ( V_18 -> V_113 == V_115 )
V_241 = L_78 ;
else if ( V_18 -> V_113 == V_116 )
V_241 = L_79 ;
else
V_241 = L_80 ;
return snprintf ( V_9 , V_10 , L_46 , V_241 ) ;
}
static T_1
F_60 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_147 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_188 V_189 ;
char * V_242 = NULL ;
int V_148 = 0 ;
int V_196 ;
if ( ! V_18 -> V_204 ) {
V_148 = - V_205 ;
goto V_243;
}
F_61 ( V_15 , V_177 , V_187 ,
L_81 , V_9 ) ;
F_45 ( & V_189 ) ;
if( strncmp ( V_9 , L_80 , sizeof( L_80 ) - 1 ) == 0 ) {
V_196 = F_46 ( V_18 , & V_148 , & V_189 ,
V_208 ) ;
if ( V_196 == 0 ) {
V_148 = - V_163 ;
goto V_243;
}
F_47 ( & V_189 ) ;
} else if ( strncmp ( V_9 , L_79 , sizeof( L_79 ) - 1 ) == 0 )
V_148 = F_44 ( V_18 , V_207 ) ;
else if ( strncmp ( V_9 , L_82 , sizeof( L_82 ) - 1 ) == 0 )
if ( V_18 -> V_106 == V_107 )
V_148 = - V_149 ;
else
V_148 = F_44 ( V_18 , V_244 ) ;
else if ( strncmp ( V_9 , L_77 , sizeof( L_77 ) - 1 ) == 0 )
if ( V_18 -> V_106 == V_107 )
V_148 = - V_149 ;
else
V_148 = F_44 ( V_18 , V_245 ) ;
else if ( strncmp ( V_9 , L_83 , sizeof( L_83 ) - 1 ) == 0 )
V_148 = F_53 ( V_18 , V_231 ) ;
else if ( strncmp ( V_9 , L_84 , sizeof( L_84 ) - 1 ) == 0 )
V_148 = F_53 ( V_18 , V_236 ) ;
else if ( strncmp ( V_9 , L_85 , sizeof( L_85 ) - 1 ) == 0 )
V_148 = F_53 ( V_18 , V_238 ) ;
else
V_148 = - V_149 ;
V_243:
if ( ! V_148 )
return strlen ( V_9 ) ;
else {
V_242 = strchr ( V_9 , '\n' ) ;
if ( V_242 )
* V_242 = '\0' ;
F_61 ( V_15 , V_177 , V_187 ,
L_86
L_87 ,
V_9 , V_148 , V_18 -> V_206 -> V_137 ) ;
return V_148 ;
}
}
static int
F_62 ( struct V_17 * V_18 ,
T_2 * V_246 , T_2 * V_247 ,
T_2 * V_248 , T_2 * V_249 ,
T_2 * V_250 , T_2 * V_251 )
{
struct V_252 * V_253 ;
T_6 * V_155 ;
T_8 * V_254 ;
int V_196 = 0 ;
T_2 V_255 ;
if ( V_18 -> V_113 < V_118 ||
! V_18 -> V_161 ||
( V_18 -> V_96 . V_97 & V_256 ) == 0 )
return 0 ;
if ( V_18 -> V_96 . V_97 & V_159 )
return 0 ;
V_155 = F_35 ( V_18 -> V_161 , V_162 ) ;
if ( ! V_155 )
return 0 ;
memset ( V_155 , 0 , sizeof ( T_6 ) ) ;
V_254 = & V_155 -> V_38 . V_164 ;
V_254 -> V_165 = V_257 ;
V_254 -> V_167 = V_168 ;
V_155 -> V_258 = NULL ;
if ( V_18 -> V_206 -> V_137 & V_158 )
V_196 = V_259 ;
else
V_196 = F_36 ( V_18 , V_155 , V_18 -> V_175 * 2 ) ;
if ( V_196 != V_170 ) {
if ( V_196 != V_180 )
F_40 ( V_155 , V_18 -> V_161 ) ;
return 0 ;
}
if ( V_18 -> V_106 == V_107 ) {
V_253 = & V_155 -> V_38 . V_260 . V_261 . V_253 ;
if ( V_248 )
* V_248 = F_52 ( V_262 , V_253 ) ;
if ( V_249 )
* V_249 = F_52 ( V_262 , V_253 ) -
V_18 -> V_104 . V_263 . V_264 ;
if ( V_246 )
* V_246 = F_52 ( V_265 , V_253 ) ;
if ( V_247 )
* V_247 = F_52 ( V_265 , V_253 ) -
V_18 -> V_104 . V_263 . V_266 ;
V_255 = ( F_52 ( V_267 , V_253 ) > 0 ) ?
( F_52 ( V_267 , V_253 ) - 1 ) : 0 ;
if ( V_250 )
* V_250 = V_255 ;
if ( V_251 )
* V_251 = V_255 - V_18 -> V_104 . V_263 . V_268 ;
} else {
if ( V_248 )
* V_248 = V_254 -> V_261 . V_269 . V_270 ;
if ( V_249 )
* V_249 = V_254 -> V_261 . V_269 . V_271 ;
if ( V_246 )
* V_246 = V_254 -> V_261 . V_269 . V_272 ;
if ( V_247 )
* V_247 = V_254 -> V_261 . V_269 . V_273 ;
if ( V_250 )
* V_250 = V_254 -> V_261 . V_269 . V_255 ;
if ( V_251 )
* V_251 = V_254 -> V_261 . V_269 . V_274 ;
}
F_40 ( V_155 , V_18 -> V_161 ) ;
return 1 ;
}
static T_1
F_63 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_185 ;
if ( F_62 ( V_18 , NULL , NULL , & V_185 , NULL , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_47 , V_185 ) ;
return snprintf ( V_9 , V_10 , L_57 ) ;
}
static T_1
F_64 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_185 , V_275 ;
if ( F_62 ( V_18 , NULL , NULL , & V_185 , & V_275 , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_47 , ( V_185 - V_275 ) ) ;
return snprintf ( V_9 , V_10 , L_57 ) ;
}
static T_1
F_65 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_185 ;
if ( F_62 ( V_18 , & V_185 , NULL , NULL , NULL , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_47 , V_185 ) ;
return snprintf ( V_9 , V_10 , L_57 ) ;
}
static T_1
F_66 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_185 , V_275 ;
if ( F_62 ( V_18 , & V_185 , & V_275 , NULL , NULL , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_47 , ( V_185 - V_275 ) ) ;
return snprintf ( V_9 , V_10 , L_57 ) ;
}
static T_1
F_67 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_185 ;
if ( F_62 ( V_18 , NULL , NULL , NULL , NULL , & V_185 , NULL ) )
return snprintf ( V_9 , V_10 , L_47 , V_185 ) ;
return snprintf ( V_9 , V_10 , L_57 ) ;
}
static T_1
F_68 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_185 , V_275 ;
if ( F_62 ( V_18 , NULL , NULL , NULL , NULL , & V_185 , & V_275 ) )
return snprintf ( V_9 , V_10 , L_47 , ( V_185 - V_275 ) ) ;
return snprintf ( V_9 , V_10 , L_57 ) ;
}
static T_1
F_69 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( ! ( V_18 -> V_255 ) )
return snprintf ( V_9 , V_10 , L_88 ) ;
if ( V_15 -> V_276 == V_277 )
return snprintf ( V_9 , V_10 , L_89 ) ;
return snprintf ( V_9 , V_10 , L_90 , V_15 -> V_278 ) ;
}
static T_1
F_70 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_91 , V_18 -> V_279 ) ;
}
static T_1
F_71 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_147 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_280 ;
T_2 V_281 ;
int V_282 = 0 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_149 ;
if ( sscanf ( V_9 , L_92 , & V_282 ) != 1 )
return - V_149 ;
if ( ( V_282 & 0x3 ) != V_282 )
return - V_149 ;
if ( V_18 -> V_106 == V_107 )
V_282 = 0 ;
F_61 ( V_15 , V_177 , V_187 ,
L_93 ,
V_18 -> V_279 , V_282 ) ;
F_9 ( & V_18 -> V_201 ) ;
V_281 = V_18 -> V_279 ;
if ( V_282 & V_283 ) {
if ( ( V_282 & V_284 ) &&
! ( V_281 & V_284 ) ) {
if ( F_51 ( V_18 -> V_285 , & V_280 ) ) {
F_11 ( & V_18 -> V_201 ) ;
return - V_149 ;
}
V_280 &= ~ ( V_286 << V_287 ) ;
F_56 ( V_280 , V_18 -> V_285 ) ;
F_55 ( V_18 -> V_285 ) ;
F_72 ( V_18 ) ;
}
} else if ( V_282 != 0x0 ) {
F_11 ( & V_18 -> V_201 ) ;
return - V_149 ;
}
if ( ! ( V_282 & V_284 ) &&
( V_281 & V_284 ) )
{
F_11 ( & V_18 -> V_201 ) ;
F_73 ( & V_18 -> V_288 ) ;
F_9 ( & V_18 -> V_201 ) ;
if ( F_51 ( V_18 -> V_285 , & V_280 ) ) {
F_11 ( & V_18 -> V_201 ) ;
return - V_149 ;
}
V_280 |= ( V_286 << V_287 ) ;
F_56 ( V_280 , V_18 -> V_285 ) ;
F_55 ( V_18 -> V_285 ) ;
}
V_18 -> V_279 = V_282 ;
F_11 ( & V_18 -> V_201 ) ;
return strlen ( V_9 ) ;
}
static T_1
F_74 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_47 , V_18 -> V_289 ) ;
}
static T_1
F_75 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_47 , V_18 -> V_290 ) ;
}
static T_1
F_76 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_94 ,
( V_18 -> V_291 ) ? L_95 : L_96 ,
( V_18 -> V_85 & V_292 ) ?
L_97 : L_98 ) ;
}
static T_1
F_77 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_9 V_293 ;
V_293 = F_78 ( V_18 ) ;
return snprintf ( V_9 , V_10 , L_47 , V_293 ) ;
}
static inline bool F_79 ( T_10 V_282 , T_10 V_294 , T_10 V_295 )
{
return V_282 >= V_294 && V_282 <= V_295 ;
}
static T_5
F_80 ( const char * V_9 , T_5 V_185 , char V_39 [] )
{
unsigned int V_3 , V_4 ;
if ( V_9 [ V_185 - 1 ] == '\n' )
V_185 -- ;
if ( ( V_185 < 16 ) || ( V_185 > 18 ) || ( ( V_185 == 17 ) && ( * V_9 ++ != 'x' ) ) ||
( ( V_185 == 18 ) && ( ( * V_9 ++ != '0' ) || ( * V_9 ++ != 'x' ) ) ) )
return - V_149 ;
memset ( V_39 , 0 , V_296 ) ;
for ( V_3 = 0 , V_4 = 0 ; V_3 < 16 ; V_3 ++ ) {
if ( ( * V_9 >= 'a' ) && ( * V_9 <= 'f' ) )
V_4 = ( ( V_4 << 4 ) | ( ( * V_9 ++ - 'a' ) + 10 ) ) ;
else if ( ( * V_9 >= 'A' ) && ( * V_9 <= 'F' ) )
V_4 = ( ( V_4 << 4 ) | ( ( * V_9 ++ - 'A' ) + 10 ) ) ;
else if ( ( * V_9 >= '0' ) && ( * V_9 <= '9' ) )
V_4 = ( ( V_4 << 4 ) | ( * V_9 ++ - '0' ) ) ;
else
return - V_149 ;
if ( V_3 % 2 ) {
V_39 [ V_3 / 2 ] = V_4 & 0xff ;
V_4 = 0 ;
}
}
return 0 ;
}
static T_1
F_81 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_147 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
unsigned int V_185 = V_147 ;
if ( V_9 [ V_185 - 1 ] == '\n' )
V_185 -- ;
if ( ( V_185 != strlen ( V_297 ) ) ||
( strncmp ( V_9 , V_297 , strlen ( V_297 ) ) != 0 ) )
return - V_149 ;
V_18 -> V_298 = 1 ;
F_82 ( V_186 , & V_18 -> V_221 -> V_6 ,
L_99 ,
V_18 -> V_41 ) ;
F_82 ( V_186 , & V_18 -> V_221 -> V_6 ,
L_100 ) ;
return V_147 ;
}
static T_1
F_83 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_101 ,
( unsigned long long ) V_18 -> V_299 ) ;
}
static T_1
F_84 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_147 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_188 V_189 ;
int V_300 = 0 , V_301 = 0 ;
unsigned int V_185 = V_147 ;
T_11 V_302 [ V_296 ] ;
int V_196 ;
if ( ! V_18 -> V_204 )
return - V_205 ;
F_9 ( & V_18 -> V_201 ) ;
if ( V_18 -> V_303 == V_304 ) {
F_11 ( & V_18 -> V_201 ) ;
return - V_205 ;
}
F_11 ( & V_18 -> V_201 ) ;
if ( V_9 [ V_185 - 1 ] == '\n' )
V_185 -- ;
if ( ! V_18 -> V_298 )
return - V_149 ;
V_18 -> V_298 = 0 ;
V_196 = F_80 ( V_9 , V_185 , V_302 ) ;
if ( V_196 ) {
V_18 -> V_298 = 1 ;
return V_196 ;
}
V_18 -> V_299 = F_7 ( V_302 ) ;
F_85 ( V_13 ) = V_18 -> V_299 ;
if ( V_18 -> V_305 )
F_86 ( V_13 ) = V_18 -> V_305 ;
F_82 ( V_306 , & V_18 -> V_221 -> V_6 ,
L_102 , V_18 -> V_41 ) ;
V_300 = F_44 ( V_18 , V_207 ) ;
if ( V_300 )
F_38 ( V_18 , V_177 , V_187 ,
L_103
L_104 , V_300 ) ;
F_45 ( & V_189 ) ;
V_196 = F_46 ( V_18 , & V_301 , & V_189 ,
V_208 ) ;
if ( V_196 == 0 )
return - V_163 ;
F_47 ( & V_189 ) ;
if ( V_301 )
F_38 ( V_18 , V_177 , V_187 ,
L_105
L_104 , V_301 ) ;
return ( V_300 || V_301 ) ? - V_181 : V_147 ;
}
static T_1
F_87 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_101 ,
( unsigned long long ) V_18 -> V_305 ) ;
}
static T_1
F_88 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_147 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
unsigned int V_185 = V_147 ;
T_11 V_307 [ V_296 ] ;
int V_196 ;
if ( V_9 [ V_185 - 1 ] == '\n' )
V_185 -- ;
if ( ! V_18 -> V_298 )
return - V_149 ;
V_196 = F_80 ( V_9 , V_185 , V_307 ) ;
if ( V_196 ) {
return V_196 ;
}
V_18 -> V_305 = F_7 ( V_307 ) ;
F_82 ( V_306 , & V_18 -> V_221 -> V_6 ,
L_106
L_107 , V_18 -> V_41 ) ;
return V_147 ;
}
static T_1
F_89 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_101 ,
F_7 ( V_18 -> V_308 ) ) ;
}
static T_1
F_90 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_147 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
unsigned int V_185 = V_147 ;
T_3 V_302 [ V_296 ] ;
int V_196 ;
if ( ! V_18 -> V_309 )
return - V_160 ;
if ( V_9 [ V_185 - 1 ] == '\n' )
V_185 -- ;
V_196 = F_80 ( V_9 , V_185 , V_302 ) ;
if ( V_196 )
return V_196 ;
memcpy ( V_18 -> V_308 , V_302 , ( 8 * sizeof( T_3 ) ) ) ;
memcpy ( V_18 -> V_104 . V_310 , V_302 , ( 8 * sizeof( T_3 ) ) ) ;
if ( F_7 ( V_302 ) == 0 )
V_18 -> V_311 |= V_312 ;
else
V_18 -> V_311 &= ~ V_312 ;
V_18 -> V_311 &= ~ V_313 ;
V_18 -> V_104 . V_314 = V_315 ;
return V_147 ;
}
static T_1
F_91 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_47 , V_18 -> V_316 ) ;
}
static T_1
F_92 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_147 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
unsigned int V_185 = V_147 ;
unsigned long V_282 ;
int V_317 ;
if ( ! V_18 -> V_309 )
return - V_160 ;
if ( V_9 [ V_185 - 1 ] == '\n' )
V_185 -- ;
V_317 = F_93 ( V_9 , 0 , & V_282 ) ;
if ( V_317 || ( V_282 > 0x7f ) )
return - V_149 ;
if ( V_282 )
V_18 -> V_316 = ( T_3 ) V_282 ;
else
V_18 -> V_316 = V_18 -> V_318 ;
return V_147 ;
}
static T_1
F_94 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_101 ,
F_7 ( V_18 -> V_319 ) ) ;
}
static T_1
F_95 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_147 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
unsigned int V_185 = V_147 ;
T_3 V_302 [ V_296 ] ;
int V_196 ;
if ( ! V_18 -> V_309 )
return - V_160 ;
if ( V_9 [ V_185 - 1 ] == '\n' )
V_185 -- ;
V_196 = F_80 ( V_9 , V_185 , V_302 ) ;
if ( V_196 )
return V_196 ;
memcpy ( V_18 -> V_319 , V_302 , ( 8 * sizeof( T_3 ) ) ) ;
memcpy ( V_18 -> V_104 . V_320 , V_302 , ( 8 * sizeof( T_3 ) ) ) ;
if ( F_7 ( V_302 ) == 0 )
V_18 -> V_311 |= V_321 ;
else
V_18 -> V_311 &= ~ V_321 ;
V_18 -> V_311 &= ~ V_313 ;
if ( V_18 -> V_316 == 0 )
V_18 -> V_316 = V_18 -> V_318 ;
V_18 -> V_104 . V_314 = V_315 ;
return V_147 ;
}
static T_1
F_96 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_47 , V_18 -> V_322 ) ;
}
static T_1
F_97 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_147 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
int V_282 = 0 ;
if ( ! V_18 -> V_309 )
return - V_160 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_149 ;
if ( sscanf ( V_9 , L_92 , & V_282 ) != 1 )
return - V_149 ;
if ( ( V_282 != 0 ) && ( V_282 != 1 ) )
return - V_149 ;
V_18 -> V_322 = V_282 ;
return strlen ( V_9 ) ;
}
static T_1
F_98 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
if ( ! ( V_18 -> V_311 & V_313 ) )
return - V_323 ;
return snprintf ( V_9 , V_10 , L_47 , V_18 -> V_324 ) ;
}
static T_5
F_99 ( struct V_17 * V_18 , T_3 V_325 [] ,
T_3 V_326 [] , T_12 V_327 ,
T_2 V_328 , T_3 V_329 )
{
int V_196 = 0 ;
if ( ! V_18 -> V_309 )
return - V_160 ;
if ( V_328 ) {
if ( ! F_100 ( V_18 , (struct V_330 * ) V_325 ,
(struct V_330 * ) V_326 ,
V_327 , V_329 ) )
V_196 = - V_163 ;
} else {
F_101 ( V_18 , (struct V_330 * ) V_325 ,
(struct V_330 * ) V_326 , V_327 , V_329 ) ;
}
return V_196 ;
}
static T_12
F_102 ( struct V_17 * V_18 , T_3 V_325 [] ,
T_3 V_326 [] , T_2 * V_331 ,
T_2 * V_332 )
{
T_12 V_333 ;
if ( F_103 ( ! V_18 ) || ! V_325 || ! V_326 )
return V_334 ;
if ( F_104 ( V_18 , (struct V_330 * )
V_18 -> V_104 . V_320 ,
(struct V_330 * )
V_18 -> V_104 . V_310 ,
& V_18 -> V_104 . V_314 ,
(struct V_330 * ) V_325 ,
(struct V_330 * ) V_326 ,
& V_333 , V_331 , V_332 ) )
return V_333 ;
else
return V_334 ;
}
static T_1
F_105 ( struct V_17 * V_18 , T_3 V_325 [] ,
T_3 V_326 [] , T_12 V_327 ,
T_2 V_328 , T_3 V_329 )
{
int V_196 ;
V_196 = F_99 ( V_18 , V_325 , V_326 , V_327 ,
V_328 , V_329 ) ;
return V_196 ;
}
static T_1
F_106 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
T_12 V_335 ;
int V_32 = 0 ;
if ( ! V_18 -> V_309 )
return - V_160 ;
if ( F_7 ( V_18 -> V_319 ) == 0 )
if ( ! ( V_18 -> V_311 & V_321 ) )
return - V_323 ;
if ( F_7 ( V_18 -> V_308 ) == 0 )
if ( ! ( V_18 -> V_311 & V_312 ) )
return - V_323 ;
V_335 = F_102 ( V_18 , V_18 -> V_319 ,
V_18 -> V_308 ,
& V_18 -> V_324 ,
& V_18 -> V_316 ) ;
if ( V_335 != V_334 )
V_18 -> V_311 |= V_313 ;
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 , L_108 , V_335 ) ;
return V_32 ;
}
static T_1
F_107 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_147 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
T_12 V_336 ;
T_2 V_329 ;
T_1 V_196 ;
if ( ! V_18 -> V_309 )
return - V_160 ;
if ( F_7 ( V_18 -> V_319 ) == 0 )
return - V_323 ;
if ( F_7 ( V_18 -> V_308 ) == 0 )
return - V_323 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_149 ;
if ( sscanf ( V_9 , L_108 , & V_336 ) != 1 )
return - V_149 ;
V_329 = V_18 -> V_316 ;
if ( V_329 == 0 )
V_329 = V_18 -> V_318 ;
F_38 ( V_18 , V_337 , V_187 ,
L_109
L_110 ,
F_7 ( V_18 -> V_319 ) ,
F_7 ( V_18 -> V_308 ) , V_336 ,
V_329 , V_18 -> V_322 ) ;
V_196 = F_105 ( V_18 , V_18 -> V_319 ,
V_18 -> V_308 , V_336 ,
V_18 -> V_322 , V_329 ) ;
if ( V_196 )
return V_196 ;
return V_147 ;
}
static T_1
F_108 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_47 , V_18 -> V_338 ) ;
}
static T_1
F_109 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
struct V_192 * V_193 = F_110 ( V_18 ) ;
return snprintf ( V_9 , V_10 , L_47 , V_193 -> V_339 ) ;
}
static T_1
F_111 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
struct V_192 * V_193 = F_110 ( V_18 ) ;
return snprintf ( V_9 , V_10 , L_47 , V_193 -> V_340 ) ;
}
static T_1
F_112 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
return snprintf ( V_9 , V_10 , L_47 , V_15 -> V_341 ) ;
}
static int
F_113 ( struct V_14 * V_15 , int V_282 )
{
if ( V_15 -> V_341 != V_342 ) {
V_15 -> V_343 = V_15 -> V_341 ;
if ( V_282 != V_342 )
F_61 ( V_15 , V_177 , V_187 ,
L_111
L_112
L_113 ) ;
return 0 ;
}
if ( V_282 >= V_344 && V_282 <= V_345 ) {
V_15 -> V_343 = V_282 ;
V_15 -> V_341 = V_282 ;
return 0 ;
}
F_61 ( V_15 , V_177 , V_187 ,
L_114
L_115 ,
V_282 , V_344 , V_345 ) ;
V_15 -> V_343 = V_342 ;
return - V_149 ;
}
static void
F_114 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
struct V_346 * V_347 ;
V_13 = F_115 ( V_15 ) ;
F_9 ( V_13 -> V_67 ) ;
F_10 (ndlp, &vport->fc_nodes, nlp_listp)
if ( F_116 ( V_347 ) && V_347 -> V_28 )
V_347 -> V_28 -> V_348 = V_15 -> V_341 ;
F_11 ( V_13 -> V_67 ) ;
}
static int
F_117 ( struct V_14 * V_15 , int V_282 )
{
if ( V_15 -> V_349 ||
( V_350 != V_342 ) ) {
F_61 ( V_15 , V_177 , V_187 ,
L_116
L_117 ) ;
return 0 ;
}
if ( V_282 >= V_344 && V_282 <= V_345 ) {
V_15 -> V_343 = V_282 ;
V_15 -> V_341 = V_282 ;
F_118 ( F_115 ( V_15 ) ) = V_282 ;
F_114 ( V_15 ) ;
return 0 ;
}
F_61 ( V_15 , V_177 , V_187 ,
L_118
L_119 ,
V_282 , V_344 , V_345 ) ;
return - V_149 ;
}
static int
F_119 ( struct V_14 * V_15 , int V_282 )
{
if ( V_282 >= V_344 && V_282 <= V_345 ) {
V_15 -> V_343 = V_282 ;
V_15 -> V_341 = V_282 ;
V_15 -> V_349 = 1 ;
F_118 ( F_115 ( V_15 ) ) = V_282 ;
F_114 ( V_15 ) ;
return 0 ;
}
F_61 ( V_15 , V_177 , V_187 ,
L_120
L_119 ,
V_282 , V_344 , V_345 ) ;
return - V_149 ;
}
static int
F_120 ( struct V_14 * V_15 , int V_282 )
{
if ( V_282 < 0 || V_282 > 1 ) {
F_61 ( V_15 , V_177 , V_187 ,
L_121
L_122 ,
V_282 ) ;
V_15 -> V_351 = 1 ;
return - V_149 ;
}
if ( V_15 -> V_276 == V_277 ) {
V_15 -> V_351 = 0 ;
return 0 ;
}
V_15 -> V_351 = V_282 ;
return 0 ;
}
static int
F_121 ( struct V_14 * V_15 , int V_282 )
{
if ( V_282 < 0 || V_282 > 1 ) {
F_61 ( V_15 , V_177 , V_187 ,
L_123
L_122 ,
V_282 ) ;
V_15 -> V_351 = 1 ;
return - V_149 ;
}
if ( V_15 -> V_276 == V_277 && V_282 != 0 ) {
F_61 ( V_15 , V_177 , V_187 ,
L_124
L_125 ) ;
V_15 -> V_351 = 0 ;
return 0 ;
}
V_15 -> V_351 = V_282 ;
return 0 ;
}
static T_1
F_122 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_147 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_282 = 0 ;
int V_352 = 0 ;
const char * V_353 = V_9 ;
int V_354 ;
T_2 V_355 ;
if ( ! strncmp ( V_9 , L_126 , strlen ( L_126 ) ) ) {
V_352 = 1 ;
V_353 = & V_9 [ strlen ( L_126 ) ] ;
}
if ( ! isdigit ( V_353 [ 0 ] ) )
return - V_149 ;
if ( sscanf ( V_353 , L_92 , & V_282 ) != 1 )
return - V_149 ;
if ( V_282 >= 0 && V_282 <= 6 ) {
V_355 = V_18 -> V_173 ;
if ( V_18 -> V_174 == V_356 &&
V_282 == 4 ) {
F_61 ( V_15 , V_177 , V_187 ,
L_127 ,
V_282 ) ;
return - V_149 ;
}
if ( V_18 -> V_221 -> V_5 == V_357 &&
V_282 == 4 ) {
F_61 ( V_15 , V_177 , V_187 ,
L_128 ) ;
return - V_149 ;
}
V_18 -> V_173 = V_282 ;
if ( V_352 )
return strlen ( V_9 ) ;
F_61 ( V_15 , V_177 , V_187 ,
L_129 ,
V_355 , V_282 ) ;
if ( V_355 != V_282 && V_18 -> V_106 == V_107 )
V_18 -> V_358 = 1 ;
V_354 = F_34 ( F_115 ( V_18 -> V_206 ) ) ;
if ( V_354 ) {
V_18 -> V_173 = V_355 ;
return - V_149 ;
} else
return strlen ( V_9 ) ;
}
F_38 ( V_18 , V_177 , V_187 ,
L_130
L_131 ,
V_18 -> V_41 , V_282 ) ;
return - V_149 ;
}
static T_1
F_123 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
if ( V_15 -> V_359 & V_360 )
sprintf ( V_9 , L_2 ) ;
else
sprintf ( V_9 , L_3 ) ;
return strlen ( V_9 ) ;
}
static T_1
F_124 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_147 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
#define F_125 1024
static char V_361 [ F_125 ] ;
unsigned long V_3 ;
char * V_362 , * V_363 ;
struct V_14 * * V_364 ;
struct V_12 * V_365 ;
char * V_366 , * V_367 , * V_368 ;
unsigned long V_369 , V_370 , V_371 ;
if ( ! strncmp ( V_9 , L_132 , strlen ( L_132 ) ) ) {
if ( strlen ( V_9 ) > ( F_125 - 1 ) )
return - V_149 ;
strncpy ( V_361 , V_9 , F_125 ) ;
V_362 = & V_361 [ 0 ] ;
V_363 = F_126 ( & V_362 , L_133 ) ;
if ( ! V_363 )
return - V_149 ;
V_366 = F_126 ( & V_362 , L_133 ) ;
if ( ! V_366 )
return - V_149 ;
if ( ! strncmp ( V_366 , L_134 , strlen ( L_134 ) ) )
V_371 = V_372 ;
else if ( ! strncmp ( V_366 , L_135 , strlen ( L_135 ) ) )
V_371 = V_373 ;
else
return - V_149 ;
V_367 = F_126 ( & V_362 , L_133 ) ;
if ( ! V_367 )
return - V_149 ;
V_369 = F_127 ( V_367 , NULL , 0 ) ;
V_368 = F_126 ( & V_362 , L_133 ) ;
if ( ! V_368 )
return - V_149 ;
V_370 = F_127 ( V_368 , NULL , 0 ) ;
if ( ! V_370 )
return - V_149 ;
V_364 = F_128 ( V_18 ) ;
if ( V_364 == NULL )
return - V_163 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_374 && V_364 [ V_3 ] != NULL ; V_3 ++ ) {
V_365 = F_115 ( V_364 [ V_3 ] ) ;
F_9 ( V_365 -> V_67 ) ;
V_364 [ V_3 ] -> V_375 = 1 ;
if ( V_364 [ V_3 ] -> V_376 )
F_129 ( V_364 [ V_3 ] ) ;
F_11 ( V_365 -> V_67 ) ;
}
V_18 -> V_371 = V_371 ;
V_18 -> V_377 = V_369 ;
V_18 -> V_378 = V_370 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_374 && V_364 [ V_3 ] != NULL ; V_3 ++ ) {
V_365 = F_115 ( V_364 [ V_3 ] ) ;
F_9 ( V_365 -> V_67 ) ;
V_364 [ V_3 ] -> V_375 = 0 ;
F_11 ( V_365 -> V_67 ) ;
}
F_130 ( V_18 , V_364 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_136 , strlen ( L_136 ) ) ) {
V_364 = F_128 ( V_18 ) ;
if ( V_364 == NULL )
return - V_163 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_374 && V_364 [ V_3 ] != NULL ; V_3 ++ ) {
V_365 = F_115 ( V_364 [ V_3 ] ) ;
F_9 ( V_13 -> V_67 ) ;
V_364 [ V_3 ] -> V_375 = 1 ;
F_131 ( V_15 ) ;
V_15 -> V_376 = 0 ;
V_364 [ V_3 ] -> V_375 = 0 ;
F_11 ( V_13 -> V_67 ) ;
}
F_130 ( V_18 , V_364 ) ;
V_18 -> V_371 = V_379 ;
V_18 -> V_377 = 0 ;
V_18 -> V_378 = 0 ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_137 , strlen ( L_137 ) ) ) {
if ( V_18 -> V_371 == V_379 )
return - V_149 ;
F_9 ( V_13 -> V_67 ) ;
if ( V_15 -> V_376 ) {
F_11 ( V_13 -> V_67 ) ;
return strlen ( V_9 ) ;
}
F_132 ( V_15 ) ;
V_15 -> V_376 = 1 ;
F_11 ( V_13 -> V_67 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_138 , strlen ( L_138 ) ) ) {
F_9 ( V_13 -> V_67 ) ;
if ( V_15 -> V_376 == 0 ) {
F_11 ( V_13 -> V_67 ) ;
return strlen ( V_9 ) ;
}
F_131 ( V_15 ) ;
V_15 -> V_376 = 0 ;
F_11 ( V_13 -> V_67 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_139 , strlen ( L_139 ) ) ) {
if ( ( V_18 -> V_371 == V_379 )
|| ! V_15 -> V_376 )
return strlen ( V_9 ) ;
F_9 ( V_13 -> V_67 ) ;
V_15 -> V_375 = 1 ;
F_129 ( V_15 ) ;
V_15 -> V_375 = 0 ;
F_11 ( V_13 -> V_67 ) ;
return strlen ( V_9 ) ;
}
return - V_149 ;
}
static T_1
F_133 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_380 = 0 ;
int V_3 ;
char * V_371 ;
unsigned long V_381 ;
switch ( V_18 -> V_371 ) {
case V_372 :
V_371 = L_134 ;
break;
case V_373 :
V_371 = L_135 ;
break;
default:
V_371 = L_140 ;
break;
}
sprintf ( & V_9 [ V_380 ] , L_141
L_142
L_143 ,
V_15 -> V_376 , V_15 -> V_375 ,
V_371 , V_18 -> V_377 , V_18 -> V_378 ) ;
V_380 = strlen ( V_9 ) ;
if ( V_18 -> V_371 != V_379 ) {
for ( V_3 = 0 ; V_3 < V_382 ; V_3 ++ ) {
if ( V_18 -> V_371 == V_372 )
V_381 = V_18 -> V_377 +
V_18 -> V_378 * V_3 ;
else
V_381 = V_18 -> V_377 +
( 1 << V_3 ) * V_18 -> V_378 ;
if ( V_380 + 10 > V_10 )
break;
sprintf ( & V_9 [ V_380 ] , L_144 , V_381 ) ;
V_380 = strlen ( V_9 ) ;
}
}
sprintf ( & V_9 [ V_380 ] , L_1 ) ;
return strlen ( V_9 ) ;
}
static T_1
F_134 ( struct V_383 * V_384 , struct V_385 * V_386 ,
struct V_387 * V_388 ,
char * V_9 , T_13 V_389 , T_5 V_147 )
{
struct V_5 * V_6 = F_135 ( V_386 , struct V_5 ,
V_386 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_3 = 0 , V_380 = 0 ;
unsigned long V_390 ;
struct V_346 * V_347 = NULL ;
V_390 = ( unsigned long ) V_389 /
V_391 ;
if ( ! V_15 -> V_376 || V_15 -> V_375
|| ( V_18 -> V_371 == V_379 ) )
return 0 ;
F_9 ( V_13 -> V_67 ) ;
F_10 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_116 ( V_347 ) || ! V_347 -> V_392 )
continue;
if ( V_390 > 0 ) {
V_390 -- ;
continue;
}
if ( ( V_380 + V_391 )
> V_147 )
break;
if ( ! V_347 -> V_392 )
continue;
sprintf ( & V_9 [ V_380 ] , L_145 ,
V_347 -> V_393 . V_38 . V_39 [ 0 ] ,
V_347 -> V_393 . V_38 . V_39 [ 1 ] ,
V_347 -> V_393 . V_38 . V_39 [ 2 ] ,
V_347 -> V_393 . V_38 . V_39 [ 3 ] ,
V_347 -> V_393 . V_38 . V_39 [ 4 ] ,
V_347 -> V_393 . V_38 . V_39 [ 5 ] ,
V_347 -> V_393 . V_38 . V_39 [ 6 ] ,
V_347 -> V_393 . V_38 . V_39 [ 7 ] ) ;
V_380 = strlen ( V_9 ) ;
for ( V_3 = 0 ; V_3 < V_382 ; V_3 ++ ) {
sprintf ( & V_9 [ V_380 ] , L_146 ,
V_347 -> V_392 [ V_3 ] . V_394 ) ;
V_380 = strlen ( V_9 ) ;
}
sprintf ( & V_9 [ V_380 ] , L_1 ) ;
V_380 = strlen ( V_9 ) ;
}
F_11 ( V_13 -> V_67 ) ;
return V_380 ;
}
static T_1
F_136 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_147 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_282 = V_395 ;
int V_352 = 0 ;
const char * V_353 = V_9 ;
int V_354 ;
T_2 V_355 , V_100 ;
V_100 = F_52 ( V_227 , & V_18 -> V_104 . V_228 ) ;
if ( V_100 == V_229 &&
V_18 -> V_19 & V_396 )
return - V_160 ;
if ( ! strncmp ( V_9 , L_126 , strlen ( L_126 ) ) ) {
V_352 = 1 ;
V_353 = & V_9 [ strlen ( L_126 ) ] ;
}
if ( ! isdigit ( V_353 [ 0 ] ) )
return - V_149 ;
if ( sscanf ( V_353 , L_92 , & V_282 ) != 1 )
return - V_149 ;
F_61 ( V_15 , V_177 , V_187 ,
L_147 ,
V_18 -> V_174 , V_282 , V_352 ? L_148 : L_149 ) ;
if ( ( ( V_282 == V_397 ) && ! ( V_18 -> V_398 & V_399 ) ) ||
( ( V_282 == V_400 ) && ! ( V_18 -> V_398 & V_401 ) ) ||
( ( V_282 == V_402 ) && ! ( V_18 -> V_398 & V_403 ) ) ||
( ( V_282 == V_404 ) && ! ( V_18 -> V_398 & V_405 ) ) ||
( ( V_282 == V_406 ) && ! ( V_18 -> V_398 & V_407 ) ) ||
( ( V_282 == V_356 ) && ! ( V_18 -> V_398 & V_408 ) ) ||
( ( V_282 == V_409 ) && ! ( V_18 -> V_398 & V_410 ) ) ) {
F_38 ( V_18 , V_177 , V_187 ,
L_150
L_151 ,
V_282 ) ;
return - V_149 ;
}
if ( V_282 == V_356 &&
V_18 -> V_135 == V_136 ) {
F_38 ( V_18 , V_177 , V_187 ,
L_152
L_153 ,
V_282 ) ;
return - V_149 ;
}
if ( ( V_282 >= 0 ) && ( V_282 <= V_411 ) &&
( V_412 & ( 1 << V_282 ) ) ) {
V_355 = V_18 -> V_174 ;
V_18 -> V_174 = V_282 ;
if ( V_352 )
return strlen ( V_9 ) ;
V_354 = F_34 ( F_115 ( V_18 -> V_206 ) ) ;
if ( V_354 ) {
V_18 -> V_174 = V_355 ;
return - V_149 ;
} else
return strlen ( V_9 ) ;
}
F_38 ( V_18 , V_177 , V_187 ,
L_154
L_155 V_413 L_156 , V_282 ) ;
return - V_149 ;
}
static int
F_137 ( struct V_17 * V_18 , int V_282 )
{
if ( V_282 == V_356 && V_18 -> V_173 == 4 ) {
F_38 ( V_18 , V_177 , V_187 ,
L_157
L_158 ,
V_282 ) ;
V_18 -> V_173 = 0 ;
}
if ( ( V_282 >= 0 ) && ( V_282 <= V_411 ) &&
( V_412 & ( 1 << V_282 ) ) ) {
V_18 -> V_174 = V_282 ;
return 0 ;
}
F_38 ( V_18 , V_177 , V_187 ,
L_159
L_160
L_161 V_413 L_156 , V_282 ) ;
V_18 -> V_174 = V_395 ;
return - V_149 ;
}
static T_1
F_138 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_147 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_282 = 0 , V_196 = - V_149 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_149 ;
if ( sscanf ( V_9 , L_92 , & V_282 ) != 1 )
return - V_149 ;
switch ( V_282 ) {
case 0 :
if ( V_18 -> V_19 & V_414 ) {
V_196 = F_139 ( V_18 -> V_221 ) ;
if ( ! V_196 ) {
F_9 ( & V_18 -> V_201 ) ;
V_18 -> V_19 &= ~ V_414 ;
F_11 ( & V_18 -> V_201 ) ;
V_18 -> V_415 = 0 ;
V_196 = strlen ( V_9 ) ;
} else
V_196 = - V_160 ;
} else {
V_18 -> V_415 = 0 ;
V_196 = strlen ( V_9 ) ;
}
break;
case 1 :
if ( ! ( V_18 -> V_19 & V_414 ) ) {
V_196 = F_140 ( V_18 -> V_221 ) ;
if ( ! V_196 ) {
F_9 ( & V_18 -> V_201 ) ;
V_18 -> V_19 |= V_414 ;
F_11 ( & V_18 -> V_201 ) ;
V_18 -> V_415 = 1 ;
V_196 = strlen ( V_9 ) ;
} else
V_196 = - V_160 ;
} else {
V_18 -> V_415 = 1 ;
V_196 = strlen ( V_9 ) ;
}
break;
default:
V_196 = - V_149 ;
break;
}
return V_196 ;
}
static T_1
F_141 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_147 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_282 , V_196 = - 1 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_149 ;
if ( sscanf ( V_9 , L_92 , & V_282 ) != 1 )
return - V_149 ;
if ( V_282 != 1 )
return - V_149 ;
if ( V_18 -> V_19 & V_414 )
V_196 = F_142 ( V_18 -> V_221 ) ;
if ( V_196 == 0 )
return strlen ( V_9 ) ;
else
return - V_160 ;
}
static T_1
F_143 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_147 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_219 * V_220 = V_18 -> V_221 ;
int V_282 = 0 , V_196 = - V_149 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_149 ;
if ( sscanf ( V_9 , L_92 , & V_282 ) != 1 )
return - V_149 ;
if ( V_282 < 0 )
return - V_149 ;
if ( V_282 == 0 ) {
if ( V_18 -> V_230 > 0 ) {
F_54 ( V_220 ) ;
V_18 -> V_230 = 0 ;
}
return strlen ( V_9 ) ;
}
if ( V_18 -> V_230 > 0 ) {
F_38 ( V_18 , V_177 , V_187 ,
L_162
L_163 ,
V_18 -> V_230 ) ;
return - V_416 ;
}
if ( V_282 <= V_417 )
V_18 -> V_230 = V_282 ;
else {
F_38 ( V_18 , V_177 , V_187 ,
L_164
L_165 , V_282 ) ;
return - V_149 ;
}
V_196 = F_57 ( V_18 , V_18 -> V_230 ) ;
if ( V_196 ) {
V_18 -> V_230 = 0 ;
V_196 = - V_160 ;
} else
V_196 = strlen ( V_9 ) ;
return V_196 ;
}
static T_1
F_144 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 , T_5 V_147 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_282 = 0 , V_196 = - V_149 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_149 ;
if ( sscanf ( V_9 , L_92 , & V_282 ) != 1 )
return - V_149 ;
if ( V_282 != 1 )
return - V_149 ;
V_196 = F_145 ( V_18 , V_418 ) ;
if ( V_196 )
V_196 = - V_160 ;
else
V_196 = strlen ( V_9 ) ;
return V_196 ;
}
static int
F_146 ( struct V_17 * V_18 , int V_282 )
{
if ( V_282 >= 0 && V_282 <= 1 ) {
V_18 -> V_419 = V_282 ;
return 0 ;
}
return - V_149 ;
}
static T_1
F_147 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_147 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_282 = 0 , V_3 ;
if ( V_18 -> V_106 != V_107 )
return - V_149 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_149 ;
if ( sscanf ( V_9 , L_92 , & V_282 ) != 1 )
return - V_149 ;
if ( V_282 && ( V_282 < V_420 || V_282 > V_421 ) )
return - V_149 ;
V_18 -> V_422 = ( T_2 ) V_282 ;
for ( V_3 = 0 ; V_3 < V_18 -> V_423 ; V_3 += V_424 )
F_148 ( V_18 , V_3 ) ;
return strlen ( V_9 ) ;
}
static int
F_149 ( struct V_17 * V_18 , int V_282 )
{
if ( V_18 -> V_106 != V_107 ) {
V_18 -> V_422 = 0 ;
return 0 ;
}
if ( ( V_282 >= V_420 && V_282 <= V_421 ) ||
( V_282 == 0 ) ) {
V_18 -> V_422 = V_282 ;
return 0 ;
}
F_38 ( V_18 , V_177 , V_187 ,
L_166 ,
V_282 ) ;
V_18 -> V_422 = V_425 ;
return 0 ;
}
static T_1
F_150 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_426 * V_427 ;
int V_32 = 0 ;
if ( ( V_18 -> V_106 != V_107 ) ||
( V_18 -> V_428 != V_429 ) )
return V_32 ;
switch ( V_18 -> V_430 ) {
case 0 :
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_167 ,
V_18 -> V_430 ) ;
return V_32 ;
case 1 :
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_168
L_169 ,
V_18 -> V_430 ,
V_18 -> V_104 . V_431 ) ;
break;
case 2 :
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_170
L_169 ,
V_18 -> V_430 ,
V_18 -> V_104 . V_431 ) ;
break;
}
while ( V_18 -> V_104 . V_432 < V_18 -> V_104 . V_433 ) {
V_427 = & V_18 -> V_104 . V_434 [ V_18 -> V_104 . V_432 ] ;
if ( V_427 -> V_435 == V_436 )
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_171
L_172 ,
V_18 -> V_104 . V_432 ,
V_427 -> V_437 , V_427 -> V_438 ,
V_427 -> V_439 ) ;
else
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_171
L_173 ,
V_18 -> V_104 . V_432 ,
V_427 -> V_437 , V_427 -> V_438 ,
V_427 -> V_439 , V_427 -> V_435 ) ;
V_18 -> V_104 . V_432 ++ ;
if ( V_18 -> V_104 . V_432 <
V_18 -> V_104 . V_433 &&
( V_32 >= ( V_10 - 64 ) ) ) {
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 , L_174 ) ;
break;
}
}
if ( V_18 -> V_104 . V_432 == V_18 -> V_104 . V_433 )
V_18 -> V_104 . V_432 = 0 ;
return V_32 ;
}
static T_1
F_151 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_147 )
{
int V_148 = - V_149 ;
return V_148 ;
}
static int
F_152 ( struct V_17 * V_18 , int V_282 )
{
if ( V_18 -> V_106 != V_107 ) {
V_18 -> V_430 = 0 ;
return 0 ;
}
if ( V_282 >= V_440 && V_282 <= V_441 ) {
V_18 -> V_430 = V_282 ;
return 0 ;
}
F_38 ( V_18 , V_177 , V_187 ,
L_175
L_176 , V_282 ) ;
V_18 -> V_430 = V_442 ;
return 0 ;
}
static int
F_153 ( struct V_14 * V_15 , int V_282 )
{
struct V_12 * V_13 = F_115 ( V_15 ) ;
struct V_346 * V_347 , * V_443 ;
if ( V_282 == V_15 -> V_444 )
return 0 ;
if ( ( V_282 < 0 ) || ( V_282 > 60000 ) )
return - V_149 ;
V_15 -> V_444 = V_282 ;
F_9 ( V_13 -> V_67 ) ;
F_154 (ndlp, next_ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_116 ( V_347 ) )
continue;
if ( V_347 -> V_445 == V_446 )
continue;
V_347 -> V_447 = V_15 -> V_448 ;
}
F_11 ( V_13 -> V_67 ) ;
return 0 ;
}
static T_1
F_155 ( struct V_383 * V_384 , struct V_385 * V_386 ,
struct V_387 * V_388 ,
char * V_9 , T_13 V_389 , T_5 V_147 )
{
T_5 V_449 ;
struct V_5 * V_6 = F_135 ( V_386 , struct V_5 , V_386 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_106 >= V_107 )
return - V_160 ;
if ( ( V_389 + V_147 ) > V_450 )
return - V_451 ;
if ( V_147 <= V_452 )
return 0 ;
if ( V_389 % 4 || V_147 % 4 || ( unsigned long ) V_9 % 4 )
return - V_149 ;
if ( memcmp ( V_9 , V_453 , V_452 ) )
return - V_149 ;
if ( ! ( V_15 -> V_137 & V_158 ) )
return - V_160 ;
F_9 ( & V_18 -> V_201 ) ;
for ( V_449 = 0 ; V_449 < V_147 - V_452 ;
V_449 += sizeof( T_2 ) )
F_56 ( * ( ( T_2 * ) ( V_9 + V_449 + V_452 ) ) ,
V_18 -> V_454 + V_389 + V_449 ) ;
F_11 ( & V_18 -> V_201 ) ;
return V_147 ;
}
static T_1
F_156 ( struct V_383 * V_384 , struct V_385 * V_386 ,
struct V_387 * V_388 ,
char * V_9 , T_13 V_389 , T_5 V_147 )
{
T_5 V_449 ;
T_2 * V_455 ;
struct V_5 * V_6 = F_135 ( V_386 , struct V_5 , V_386 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_106 >= V_107 )
return - V_160 ;
if ( V_389 > V_450 )
return - V_451 ;
if ( ( V_389 + V_147 ) > V_450 )
V_147 = V_450 - V_389 ;
if ( V_147 == 0 ) return 0 ;
if ( V_389 % 4 || V_147 % 4 || ( unsigned long ) V_9 % 4 )
return - V_149 ;
F_9 ( & V_18 -> V_201 ) ;
for ( V_449 = 0 ; V_449 < V_147 ; V_449 += sizeof( T_2 ) ) {
V_455 = ( T_2 * ) ( V_9 + V_449 ) ;
* V_455 = F_55 ( V_18 -> V_454 + V_389 + V_449 ) ;
}
F_11 ( & V_18 -> V_201 ) ;
return V_147 ;
}
static T_1
F_157 ( struct V_383 * V_384 , struct V_385 * V_386 ,
struct V_387 * V_388 ,
char * V_9 , T_13 V_389 , T_5 V_147 )
{
return - V_160 ;
}
static T_1
F_158 ( struct V_383 * V_384 , struct V_385 * V_386 ,
struct V_387 * V_388 ,
char * V_9 , T_13 V_389 , T_5 V_147 )
{
return - V_160 ;
}
int
F_159 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = F_115 ( V_15 ) ;
int error ;
error = F_160 ( & V_13 -> V_456 . V_386 ,
& V_457 ) ;
if ( error || V_15 -> V_276 == V_458 )
goto V_202;
error = F_160 ( & V_13 -> V_456 . V_386 ,
& V_459 ) ;
if ( error )
goto V_460;
error = F_160 ( & V_13 -> V_456 . V_386 ,
& V_461 ) ;
if ( error )
goto V_462;
return 0 ;
V_462:
F_161 ( & V_13 -> V_456 . V_386 , & V_459 ) ;
V_460:
F_161 ( & V_13 -> V_456 . V_386 ,
& V_457 ) ;
V_202:
return error ;
}
void
F_162 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = F_115 ( V_15 ) ;
F_161 ( & V_13 -> V_456 . V_386 ,
& V_457 ) ;
if ( V_15 -> V_276 == V_458 )
return;
F_161 ( & V_13 -> V_456 . V_386 , & V_461 ) ;
F_161 ( & V_13 -> V_456 . V_386 , & V_459 ) ;
}
static void
F_163 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
F_164 ( V_15 , F_165 ( V_13 ) ,
sizeof F_165 ( V_13 ) ) ;
}
static void
F_166 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
F_167 ( V_13 ) = V_15 -> V_463 ;
}
static void
F_168 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_9 ( V_13 -> V_67 ) ;
if ( V_15 -> V_276 == V_458 ) {
F_169 ( V_13 ) = V_464 ;
} else if ( F_170 ( V_18 ) ) {
if ( V_18 -> V_135 == V_136 ) {
if ( V_15 -> V_137 & V_138 )
F_169 ( V_13 ) = V_465 ;
else
F_169 ( V_13 ) = V_466 ;
} else {
if ( V_15 -> V_137 & V_139 )
F_169 ( V_13 ) = V_467 ;
else
F_169 ( V_13 ) = V_468 ;
}
} else
F_169 ( V_13 ) = V_469 ;
F_11 ( V_13 -> V_67 ) ;
}
static void
F_171 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_9 ( V_13 -> V_67 ) ;
if ( V_15 -> V_137 & V_158 )
F_172 ( V_13 ) = V_470 ;
else {
switch ( V_18 -> V_113 ) {
case V_114 :
case V_118 :
F_172 ( V_13 ) = V_471 ;
break;
case V_121 :
case V_122 :
case V_123 :
if ( V_15 -> V_69 < V_132 )
F_172 ( V_13 ) =
V_472 ;
else
F_172 ( V_13 ) =
V_473 ;
break;
case V_119 :
F_172 ( V_13 ) = V_474 ;
break;
default:
F_172 ( V_13 ) = V_475 ;
break;
}
}
F_11 ( V_13 -> V_67 ) ;
}
static void
F_173 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_9 ( V_13 -> V_67 ) ;
if ( ( F_170 ( V_18 ) ) && ( ! ( V_18 -> V_19 & V_476 ) ) ) {
switch( V_18 -> V_477 ) {
case V_478 :
F_174 ( V_13 ) = V_479 ;
break;
case V_480 :
F_174 ( V_13 ) = V_481 ;
break;
case V_482 :
F_174 ( V_13 ) = V_483 ;
break;
case V_484 :
F_174 ( V_13 ) = V_485 ;
break;
case V_486 :
F_174 ( V_13 ) = V_487 ;
break;
case V_488 :
F_174 ( V_13 ) = V_489 ;
break;
case V_490 :
F_174 ( V_13 ) = V_491 ;
break;
default:
F_174 ( V_13 ) = V_492 ;
break;
}
} else
F_174 ( V_13 ) = V_492 ;
F_11 ( V_13 -> V_67 ) ;
}
static void
F_175 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_14 V_73 ;
F_9 ( V_13 -> V_67 ) ;
if ( ( V_15 -> V_69 > V_126 ) &&
( ( V_15 -> V_137 & V_139 ) ||
( ( V_18 -> V_135 == V_136 ) &&
( V_15 -> V_137 & V_138 ) ) ) )
V_73 = F_7 ( V_18 -> V_493 . V_494 . V_38 . V_39 ) ;
else
V_73 = 0 ;
F_11 ( V_13 -> V_67 ) ;
F_176 ( V_13 ) = V_73 ;
}
static struct V_495 *
F_177 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_194 * V_195 = & V_18 -> V_96 ;
struct V_495 * V_496 = & V_18 -> V_497 ;
struct V_498 * V_499 = & V_195 -> V_500 ;
T_6 * V_155 ;
T_8 * V_254 ;
unsigned long V_501 ;
int V_196 = 0 ;
if ( V_18 -> V_113 < V_118 ||
! V_18 -> V_161 ||
( V_18 -> V_96 . V_97 & V_256 ) == 0 )
return NULL ;
if ( V_18 -> V_96 . V_97 & V_159 )
return NULL ;
V_155 = F_35 ( V_18 -> V_161 , V_162 ) ;
if ( ! V_155 )
return NULL ;
memset ( V_155 , 0 , sizeof ( T_6 ) ) ;
V_254 = & V_155 -> V_38 . V_164 ;
V_254 -> V_165 = V_502 ;
V_254 -> V_167 = V_168 ;
V_155 -> V_258 = NULL ;
V_155 -> V_15 = V_15 ;
if ( V_15 -> V_137 & V_158 )
V_196 = F_178 ( V_18 , V_155 , V_503 ) ;
else
V_196 = F_36 ( V_18 , V_155 , V_18 -> V_175 * 2 ) ;
if ( V_196 != V_170 ) {
if ( V_196 != V_180 )
F_40 ( V_155 , V_18 -> V_161 ) ;
return NULL ;
}
memset ( V_496 , 0 , sizeof ( struct V_495 ) ) ;
V_496 -> V_504 = V_254 -> V_261 . V_505 . V_506 ;
V_496 -> V_507 = ( T_12 )
( ( T_12 ) V_254 -> V_261 . V_505 . V_508
* ( T_12 ) 256 ) ;
V_496 -> V_509 = V_254 -> V_261 . V_505 . V_510 ;
V_496 -> V_511 = ( T_12 )
( ( T_12 ) V_254 -> V_261 . V_505 . V_512
* ( T_12 ) 256 ) ;
memset ( V_155 , 0 , sizeof ( T_6 ) ) ;
V_254 -> V_165 = V_513 ;
V_254 -> V_167 = V_168 ;
V_155 -> V_258 = NULL ;
V_155 -> V_15 = V_15 ;
if ( V_15 -> V_137 & V_158 )
V_196 = F_178 ( V_18 , V_155 , V_503 ) ;
else
V_196 = F_36 ( V_18 , V_155 , V_18 -> V_175 * 2 ) ;
if ( V_196 != V_170 ) {
if ( V_196 != V_180 )
F_40 ( V_155 , V_18 -> V_161 ) ;
return NULL ;
}
V_496 -> V_514 = V_254 -> V_261 . V_515 . V_516 ;
V_496 -> V_517 = V_254 -> V_261 . V_515 . V_518 ;
V_496 -> V_519 = V_254 -> V_261 . V_515 . V_520 ;
V_496 -> V_521 = V_254 -> V_261 . V_515 . V_522 ;
V_496 -> V_523 = V_254 -> V_261 . V_515 . V_524 ;
V_496 -> V_525 = V_254 -> V_261 . V_515 . V_526 ;
V_496 -> V_527 = V_254 -> V_261 . V_515 . V_526 ;
V_496 -> V_514 -= V_499 -> V_514 ;
V_496 -> V_517 -= V_499 -> V_517 ;
V_496 -> V_519 -= V_499 -> V_519 ;
V_496 -> V_521 -= V_499 -> V_521 ;
V_496 -> V_523 -= V_499 -> V_523 ;
V_496 -> V_525 -= V_499 -> V_525 ;
V_496 -> V_527 -= V_499 -> V_527 ;
if ( V_18 -> V_19 & V_476 ) {
V_496 -> V_528 = - 1 ;
V_496 -> V_529 = ( V_18 -> V_530 >> 1 ) ;
V_496 -> V_529 -= V_499 -> V_530 ;
} else if ( V_18 -> V_135 == V_136 ) {
V_496 -> V_528 = ( V_18 -> V_531 >> 1 ) ;
V_496 -> V_528 -= V_499 -> V_530 ;
V_496 -> V_529 = - 1 ;
} else {
V_496 -> V_528 = - 1 ;
V_496 -> V_529 = ( V_18 -> V_531 >> 1 ) ;
V_496 -> V_529 -= V_499 -> V_530 ;
}
V_496 -> V_532 = - 1 ;
V_501 = F_179 () ;
if ( V_501 < V_195 -> V_533 )
V_496 -> V_534 = V_501 +
( ( unsigned long ) - 1 - V_195 -> V_533 ) ;
else
V_496 -> V_534 = V_501 - V_195 -> V_533 ;
F_40 ( V_155 , V_18 -> V_161 ) ;
return V_496 ;
}
static void
F_180 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_194 * V_195 = & V_18 -> V_96 ;
struct V_498 * V_499 = & V_195 -> V_500 ;
T_6 * V_155 ;
T_8 * V_254 ;
int V_196 = 0 ;
if ( V_18 -> V_96 . V_97 & V_159 )
return;
V_155 = F_35 ( V_18 -> V_161 , V_162 ) ;
if ( ! V_155 )
return;
memset ( V_155 , 0 , sizeof( T_6 ) ) ;
V_254 = & V_155 -> V_38 . V_164 ;
V_254 -> V_165 = V_502 ;
V_254 -> V_167 = V_168 ;
V_254 -> V_261 . V_535 [ 0 ] = 0x1 ;
V_155 -> V_258 = NULL ;
V_155 -> V_15 = V_15 ;
if ( ( V_15 -> V_137 & V_158 ) ||
( ! ( V_195 -> V_97 & V_256 ) ) )
V_196 = F_178 ( V_18 , V_155 , V_503 ) ;
else
V_196 = F_36 ( V_18 , V_155 , V_18 -> V_175 * 2 ) ;
if ( V_196 != V_170 ) {
if ( V_196 != V_180 )
F_40 ( V_155 , V_18 -> V_161 ) ;
return;
}
memset ( V_155 , 0 , sizeof( T_6 ) ) ;
V_254 -> V_165 = V_513 ;
V_254 -> V_167 = V_168 ;
V_155 -> V_258 = NULL ;
V_155 -> V_15 = V_15 ;
if ( ( V_15 -> V_137 & V_158 ) ||
( ! ( V_195 -> V_97 & V_256 ) ) )
V_196 = F_178 ( V_18 , V_155 , V_503 ) ;
else
V_196 = F_36 ( V_18 , V_155 , V_18 -> V_175 * 2 ) ;
if ( V_196 != V_170 ) {
if ( V_196 != V_180 )
F_40 ( V_155 , V_18 -> V_161 ) ;
return;
}
V_499 -> V_514 = V_254 -> V_261 . V_515 . V_516 ;
V_499 -> V_517 = V_254 -> V_261 . V_515 . V_518 ;
V_499 -> V_519 = V_254 -> V_261 . V_515 . V_520 ;
V_499 -> V_521 = V_254 -> V_261 . V_515 . V_522 ;
V_499 -> V_523 = V_254 -> V_261 . V_515 . V_524 ;
V_499 -> V_525 = V_254 -> V_261 . V_515 . V_526 ;
V_499 -> V_527 = V_254 -> V_261 . V_515 . V_526 ;
if ( V_18 -> V_19 & V_476 )
V_499 -> V_530 = ( V_18 -> V_530 >> 1 ) ;
else
V_499 -> V_530 = ( V_18 -> V_531 >> 1 ) ;
V_195 -> V_533 = F_179 () ;
F_40 ( V_155 , V_18 -> V_161 ) ;
return;
}
static struct V_346 *
F_181 ( struct V_536 * V_537 )
{
struct V_12 * V_13 = F_182 ( V_537 -> V_6 . V_538 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_346 * V_347 ;
F_9 ( V_13 -> V_67 ) ;
F_10 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( F_116 ( V_347 ) &&
V_347 -> V_445 == V_539 &&
V_537 -> V_540 == V_347 -> V_541 ) {
F_11 ( V_13 -> V_67 ) ;
return V_347 ;
}
}
F_11 ( V_13 -> V_67 ) ;
return NULL ;
}
static void
F_183 ( struct V_536 * V_537 )
{
struct V_346 * V_347 = F_181 ( V_537 ) ;
F_184 ( V_537 ) = V_347 ? V_347 -> V_542 : - 1 ;
}
static void
F_185 ( struct V_536 * V_537 )
{
struct V_346 * V_347 = F_181 ( V_537 ) ;
F_186 ( V_537 ) =
V_347 ? F_7 ( V_347 -> V_543 . V_38 . V_39 ) : 0 ;
}
static void
F_187 ( struct V_536 * V_537 )
{
struct V_346 * V_347 = F_181 ( V_537 ) ;
F_188 ( V_537 ) =
V_347 ? F_7 ( V_347 -> V_393 . V_38 . V_39 ) : 0 ;
}
static void
F_189 ( struct V_544 * V_28 , T_2 V_545 )
{
if ( V_545 )
V_28 -> V_348 = V_545 ;
else
V_28 -> V_348 = 1 ;
}
static void
F_190 ( struct V_546 * V_546 )
{
struct V_14 * V_15 = * (struct V_14 * * ) V_546 -> V_547 ;
if ( V_15 -> V_69 == V_132 )
F_191 ( V_15 , V_548 , 0 , 0 ) ;
}
static void
F_192 ( struct V_17 * V_18 , T_2 V_549 )
{
V_18 -> V_550 = V_549 ;
}
void
F_193 ( struct V_17 * V_18 )
{
F_194 ( V_18 , V_551 ) ;
F_195 ( V_18 , V_552 ) ;
F_196 ( V_18 , V_553 ) ;
F_197 ( V_18 , V_554 ) ;
F_198 ( V_18 , V_555 ) ;
F_199 ( V_18 , V_556 ) ;
F_200 ( V_18 , V_557 ) ;
F_201 ( V_18 , V_558 ) ;
F_202 ( V_18 , V_559 ) ;
F_137 ( V_18 , V_560 ) ;
F_203 ( V_18 , V_561 ) ;
F_204 ( V_18 , V_562 ) ;
F_205 ( V_18 , V_563 ) ;
F_206 ( V_18 , V_564 ) ;
F_207 ( V_18 , V_565 ) ;
F_208 ( V_18 , V_566 ) ;
F_209 ( V_18 , V_567 ) ;
F_210 ( V_18 , V_568 ) ;
F_211 ( V_18 , V_569 ) ;
F_149 ( V_18 , V_570 ) ;
F_152 ( V_18 , V_571 ) ;
F_212 ( V_18 , V_572 ) ;
F_213 ( V_18 , V_573 ) ;
F_214 ( V_18 , V_574 ) ;
if ( V_18 -> V_106 != V_107 )
V_18 -> V_575 = 0 ;
F_215 ( V_18 , V_576 ) ;
memset ( V_18 -> V_308 , 0 , ( 8 * sizeof( T_3 ) ) ) ;
memset ( V_18 -> V_319 , 0 , ( 8 * sizeof( T_3 ) ) ) ;
V_18 -> V_322 = 0 ;
V_18 -> V_324 = 0 ;
V_18 -> V_311 = 0 ;
V_18 -> V_316 = 0 ;
F_216 ( V_18 , V_577 ) ;
F_217 ( V_18 , V_578 ) ;
F_218 ( V_18 , V_579 ) ;
if ( V_18 -> V_106 == V_107 )
V_18 -> V_279 = 0 ;
else
V_18 -> V_279 = V_580 ;
F_219 ( V_18 , V_581 ) ;
F_220 ( V_18 , V_582 ) ;
F_221 ( V_18 , V_583 ) ;
F_222 ( V_18 , V_584 ) ;
F_223 ( V_18 , V_585 ) ;
F_224 ( V_18 , V_586 ) ;
F_225 ( V_18 , V_587 ) ;
F_226 ( V_18 , V_588 ) ;
if ( V_18 -> V_106 != V_107 ) {
V_18 -> V_35 = 0 ;
V_18 -> V_33 = V_589 ;
} else {
if ( ! ( V_18 -> V_33 & V_589 ) )
V_18 -> V_33 |= V_589 ;
}
if ( V_18 -> V_590 == 0 )
V_18 -> V_590 = V_18 -> V_104 . V_433 ;
if ( V_18 -> V_591 == 0 )
V_18 -> V_591 = V_18 -> V_104 . V_433 ;
if ( V_18 -> V_33 == V_34 )
V_18 -> V_590 = 0 ;
if ( V_18 -> V_33 == V_589 )
V_18 -> V_591 = 0 ;
if ( V_18 -> V_590 > V_18 -> V_591 )
V_18 -> V_423 = V_18 -> V_590 ;
else
V_18 -> V_423 = V_18 -> V_591 ;
V_18 -> V_305 = 0L ;
V_18 -> V_299 = 0L ;
F_227 ( V_18 , V_592 ) ;
F_228 ( V_18 , V_593 ) ;
F_229 ( V_18 , V_594 ) ;
F_192 ( V_18 , V_595 ) ;
F_230 ( V_18 , V_596 ) ;
F_231 ( V_18 , V_597 ) ;
F_146 ( V_18 , V_598 ) ;
F_232 ( V_18 , V_599 ) ;
F_233 ( V_18 , V_600 ) ;
F_234 ( V_18 , V_601 ) ;
F_235 ( V_18 , V_602 ) ;
V_18 -> V_291 = 1 ;
F_236 ( V_18 , V_603 ) ;
return;
}
void
F_237 ( struct V_17 * V_18 )
{
if ( V_18 -> V_591 > V_18 -> V_104 . V_433 )
V_18 -> V_591 = V_18 -> V_104 . V_433 ;
if ( V_18 -> V_590 > V_18 -> V_104 . V_433 )
V_18 -> V_590 = V_18 -> V_104 . V_433 ;
if ( V_18 -> V_33 & V_34 &&
V_18 -> V_35 ) {
V_18 -> V_33 &= ~ V_589 ;
V_18 -> V_590 = 0 ;
F_38 ( V_18 , V_337 , V_604 ,
L_177 ,
L_178 ,
V_18 -> V_605 ,
V_18 -> V_606 ,
V_607 ) ;
if ( V_18 -> V_605 == 0 )
V_18 -> V_606 = 0 ;
else {
if ( V_18 -> V_606 > V_607 )
V_18 -> V_606 = V_607 ;
}
if ( V_18 -> V_608 > V_18 -> V_591 ) {
V_18 -> V_608 = V_18 -> V_591 ;
F_38 ( V_18 , V_177 , V_604 ,
L_179 ,
V_18 -> V_608 ) ;
}
} else {
V_18 -> V_35 = 0 ;
V_18 -> V_608 = 0 ;
V_18 -> V_609 = 0 ;
V_18 -> V_606 = 0 ;
}
if ( V_18 -> V_590 > V_18 -> V_591 )
V_18 -> V_423 = V_18 -> V_590 ;
else
V_18 -> V_423 = V_18 -> V_591 ;
}
void
F_238 ( struct V_14 * V_15 )
{
F_239 ( V_15 , V_595 ) ;
F_240 ( V_15 , V_610 ) ;
F_241 ( V_15 , V_611 ) ;
F_242 ( V_15 , V_350 ) ;
F_113 ( V_15 , V_612 ) ;
F_243 ( V_15 , V_613 ) ;
F_120 ( V_15 , V_614 ) ;
F_244 ( V_15 , V_615 ) ;
F_245 ( V_15 , V_616 ) ;
F_246 ( V_15 , V_617 ) ;
F_247 ( V_15 , V_618 ) ;
F_248 ( V_15 , V_619 ) ;
F_249 ( V_15 , V_620 ) ;
F_250 ( V_15 , V_621 ) ;
F_251 ( V_15 , V_622 ) ;
return;
}
