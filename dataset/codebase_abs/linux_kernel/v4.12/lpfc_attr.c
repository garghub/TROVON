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
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
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
F_8 ( & V_22 -> V_53 ) ,
F_8 ( & V_22 -> V_54 ) ) ;
if ( F_8 ( & V_22 -> V_52 ) !=
F_8 ( & V_22 -> V_55 ) ) {
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_16 ,
F_8 ( & V_22 -> V_52 ) ,
F_8 ( & V_22 -> V_55 ) ) ;
}
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_17
L_18 ,
F_8 ( & V_22 -> V_56 ) ,
F_8 ( & V_22 -> V_57 ) ,
F_8 ( & V_22 -> V_58 ) ,
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
F_8 ( & V_22 -> V_65 ) ) ;
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_21 ,
F_8 ( & V_22 -> V_66 ) ,
F_8 ( & V_22 -> V_67 ) ,
F_8 ( & V_22 -> V_68 ) ,
F_8 ( & V_22 -> V_69 ) ) ;
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_22 ,
V_18 -> V_70 . V_71 ,
V_18 -> V_70 . V_72 ,
V_18 -> V_70 . V_73 ) ;
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 , L_1 ) ;
return V_32 ;
}
V_24 = V_15 -> V_24 ;
if ( ! V_24 ) {
V_32 = snprintf ( V_9 , V_10 ,
L_23 ,
F_7 ( V_15 -> V_37 . V_38 . V_39 ) ) ;
return V_32 ;
}
V_32 = snprintf ( V_9 , V_10 , L_24 ) ;
F_9 ( V_13 -> V_74 ) ;
V_26 = (struct V_25 * ) V_24 -> V_43 ;
if ( V_24 -> V_40 )
V_31 = L_25 ;
else
V_31 = L_26 ;
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_27 ,
L_28 ,
V_18 -> V_41 ,
F_7 ( V_15 -> V_37 . V_38 . V_39 ) ,
F_7 ( V_15 -> V_42 . V_38 . V_39 ) ,
V_24 -> V_40 , V_31 ) ;
F_10 (rport, &lport->rport_list, list) {
V_30 = V_28 -> V_75 ;
switch ( V_30 -> V_76 ) {
case V_77 :
V_31 = L_25 ;
break;
case V_78 :
V_31 = L_26 ;
break;
default:
V_31 = L_29 ;
break;
}
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_30 ) ;
if ( V_18 -> V_41 >= 10 )
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 , L_31 ) ;
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 , L_32 ,
V_30 -> V_79 ) ;
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 , L_33 ,
V_30 -> V_80 ) ;
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 , L_34 ,
V_30 -> V_40 ) ;
switch ( V_30 -> V_81 ) {
case V_82 :
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_35 ) ;
break;
case V_83 :
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_36 ) ;
break;
case V_84 :
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_37 ) ;
break;
default:
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_38 ,
V_30 -> V_81 ) ;
break;
}
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 , L_39 , V_31 ) ;
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 , L_1 ) ;
}
F_11 ( V_13 -> V_74 ) ;
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 , L_40 ) ;
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_41 ,
V_18 -> V_85 ,
V_18 -> V_86 ) ;
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_42 ,
V_18 -> V_87 ,
V_18 -> V_88 ,
V_18 -> V_89 ) ;
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_43 , V_18 -> V_90 ) ;
return V_32 ;
}
static T_1
F_12 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_91 )
if ( V_18 -> V_92 & V_93 )
return snprintf ( V_9 , V_10 , L_44 ) ;
else
return snprintf ( V_9 , V_10 ,
L_45 ) ;
else
return snprintf ( V_9 , V_10 ,
L_46 ) ;
}
static T_1
F_13 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_47 ,
( unsigned long long ) V_18 -> V_94 ) ;
}
static T_1
F_14 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_47 ,
( unsigned long long ) V_18 -> V_95 ) ;
}
static T_1
F_15 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_47 ,
( unsigned long long ) V_18 -> V_96 ) ;
}
static T_1
F_16 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_97 = F_4 ( V_6 ) ;
return snprintf ( V_9 , V_10 , L_48 , F_17 ( V_97 ) ) ;
}
static T_1
F_18 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_48 , V_18 -> V_98 ) ;
}
static T_1
F_19 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_49 , V_18 -> V_99 ) ;
}
static T_1
F_20 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_48 , V_18 -> V_100 ) ;
}
static T_1
F_21 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_48 , V_18 -> V_101 ) ;
}
static T_1
F_22 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_48 , V_18 -> V_102 ) ;
}
static T_1
F_23 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_49 ,
( V_18 -> V_103 . V_104 & V_105 ) ) ;
}
static T_1
F_24 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_48 , V_18 -> V_106 ) ;
}
static T_1
F_25 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_107 ;
T_3 V_108 ;
char V_109 [ V_110 ] ;
int V_32 ;
F_26 ( V_18 , V_109 , 1 ) ;
V_107 = V_18 -> V_70 . V_111 . V_107 ;
V_108 = V_18 -> V_70 . V_111 . V_108 ;
if ( V_18 -> V_112 < V_113 )
V_32 = snprintf ( V_9 , V_10 , L_50 ,
V_109 , V_18 -> V_112 ) ;
else
V_32 = snprintf ( V_9 , V_10 , L_51 ,
V_109 , V_18 -> V_112 , V_107 , V_108 ) ;
return V_32 ;
}
static T_1
F_27 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
char V_2 [ 9 ] ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_4 * V_114 = & V_18 -> V_115 ;
F_1 ( V_114 -> V_116 . V_117 , V_2 ) ;
return snprintf ( V_9 , V_10 , L_48 , V_2 ) ;
}
static T_1
F_28 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
char V_109 [ V_110 ] ;
if ( V_18 -> V_112 < V_113 )
return snprintf ( V_9 , V_10 , L_48 , V_18 -> V_118 ) ;
F_26 ( V_18 , V_109 , 1 ) ;
return snprintf ( V_9 , V_10 , L_48 , V_109 ) ;
}
static T_1
F_29 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_32 = 0 ;
switch ( V_18 -> V_119 ) {
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
if ( V_18 -> V_19 & V_126 )
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_52 ) ;
else
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_53 ) ;
break;
case V_127 :
case V_128 :
case V_129 :
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 , L_54 ) ;
switch ( V_15 -> V_76 ) {
case V_130 :
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_55 ) ;
break;
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_56 ) ;
break;
case V_138 :
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 , L_57 ) ;
break;
case V_139 :
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 , L_58 ) ;
break;
case V_140 :
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_59 ) ;
break;
}
if ( V_18 -> V_103 . V_104 & V_105 )
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_60 ) ;
else if ( V_18 -> V_141 == V_142 ) {
if ( V_15 -> V_143 & V_144 )
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_61 ) ;
else
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_62 ) ;
} else {
if ( V_15 -> V_143 & V_145 )
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_63 ) ;
else
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_64 ) ;
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
if ( V_18 -> V_112 < V_113 )
return snprintf ( V_9 , V_10 , L_65 ) ;
if ( V_18 -> V_70 . V_146 . V_147 == V_148 ) {
if ( V_18 -> V_70 . V_146 . V_149 == V_150 )
return snprintf ( V_9 , V_10 , L_66 ) ;
if ( V_18 -> V_70 . V_146 . V_149 == V_151 )
return snprintf ( V_9 , V_10 , L_65 ) ;
}
return snprintf ( V_9 , V_10 , L_67 ) ;
}
static T_1
F_31 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_49 ,
V_18 -> V_70 . V_111 . V_152 ) ;
}
static T_1
F_32 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_153 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_154 = - V_155 ;
if ( ( strncmp ( V_9 , L_68 , sizeof( L_68 ) - 1 ) == 0 ) &&
( V_18 -> V_119 == V_124 ) )
V_154 = V_18 -> V_156 ( V_18 , V_157 ) ;
else if ( ( strncmp ( V_9 , L_69 , sizeof( L_69 ) - 1 ) == 0 ) &&
( V_18 -> V_119 >= V_127 ) )
V_154 = V_18 -> V_158 ( V_18 , V_157 ) ;
if ( V_154 == 0 )
return strlen ( V_9 ) ;
else
return V_154 ;
}
static T_1
F_33 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
return snprintf ( V_9 , V_10 , L_49 ,
V_15 -> V_159 + V_15 -> V_160 ) ;
}
static int
F_34 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_6 * V_161 ;
int V_162 = V_163 ;
if ( ( V_15 -> V_143 & V_164 ) ||
( V_18 -> V_103 . V_104 & V_165 ) )
return - V_166 ;
V_161 = F_35 ( V_18 -> V_167 , V_168 ) ;
if ( ! V_161 )
return - V_169 ;
memset ( ( void * ) V_161 , 0 , sizeof ( T_6 ) ) ;
V_161 -> V_38 . V_170 . V_171 = V_172 ;
V_161 -> V_38 . V_170 . V_173 = V_174 ;
V_162 = F_36 ( V_18 , V_161 , V_175 * 2 ) ;
if ( ( V_162 == V_176 ) &&
( V_161 -> V_38 . V_170 . V_177 == 0 ||
V_161 -> V_38 . V_170 . V_177 == V_178 ) ) {
memset ( ( void * ) V_161 , 0 , sizeof ( T_6 ) ) ;
F_37 ( V_18 , V_161 , V_18 -> V_179 ,
V_18 -> V_180 ) ;
V_162 = F_36 ( V_18 , V_161 ,
V_18 -> V_181 * 2 ) ;
if ( ( V_162 == V_176 ) &&
( V_161 -> V_38 . V_170 . V_177 == V_182 ) )
F_38 ( V_18 , V_183 , V_184 | V_185 ,
L_70
L_71 ) ;
}
F_39 ( V_18 ) ;
if ( V_162 != V_186 )
F_40 ( V_161 , V_18 -> V_167 ) ;
if ( V_162 == V_163 )
return - V_187 ;
return 0 ;
}
int
F_41 ( struct V_17 * V_18 , struct V_188 * V_189 , T_7 * V_190 )
{
int V_191 = 0 ;
F_9 ( V_190 ) ;
while ( ! F_42 ( V_189 ) ) {
F_11 ( V_190 ) ;
F_43 ( 20 ) ;
if ( V_191 ++ > 250 ) {
F_38 ( V_18 , V_192 , V_193 ,
L_72 ,
L_73 ,
L_74 ) ;
return 0 ;
}
F_9 ( V_190 ) ;
}
F_11 ( V_190 ) ;
return 1 ;
}
static int
F_44 ( struct V_17 * V_18 , T_2 type )
{
struct V_194 V_195 ;
struct V_196 * V_197 = NULL ;
struct V_198 * V_199 ;
struct V_200 * V_201 ;
int V_154 = 0 ;
int V_3 ;
int V_202 ;
F_45 ( & V_195 ) ;
V_202 = F_46 ( V_18 , & V_154 , & V_195 ,
V_203 ) ;
if ( V_202 == 0 )
return - V_169 ;
F_47 ( & V_195 ) ;
if ( V_154 != 0 )
return - V_187 ;
V_201 = & V_18 -> V_103 ;
if ( V_18 -> V_112 != V_113 ) {
for ( V_3 = 0 ; V_3 < V_201 -> V_204 ; V_3 ++ ) {
V_199 = & V_201 -> V_205 [ V_3 ] ;
if ( ! F_41 ( V_18 , & V_199 -> V_206 ,
& V_18 -> V_207 ) )
goto V_208;
}
} else {
F_10 (qp, &phba->sli4_hba.lpfc_wq_list, wq_list) {
V_199 = V_197 -> V_199 ;
if ( ! V_199 )
continue;
if ( ! F_41 ( V_18 , & V_199 -> V_206 ,
& V_199 -> V_209 ) )
goto V_208;
}
}
V_208:
F_45 ( & V_195 ) ;
V_202 = F_46 ( V_18 , & V_154 , & V_195 , type ) ;
if ( V_202 == 0 )
return - V_169 ;
F_47 ( & V_195 ) ;
if ( V_154 != 0 )
return - V_187 ;
return 0 ;
}
int
F_48 ( struct V_17 * V_18 )
{
struct V_194 V_195 ;
int V_154 = 0 ;
int V_202 ;
if ( ! V_18 -> V_210 )
return - V_211 ;
if ( ! ( V_18 -> V_212 -> V_143 & V_164 ) ) {
V_154 = F_44 ( V_18 , V_213 ) ;
if ( V_154 != 0 )
return V_154 ;
}
F_45 ( & V_195 ) ;
V_202 = F_46 ( V_18 , & V_154 , & V_195 ,
V_214 ) ;
if ( V_202 == 0 )
return - V_169 ;
F_47 ( & V_195 ) ;
if ( V_154 != 0 )
return - V_187 ;
return 0 ;
}
static T_1
F_49 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_153 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_154 = - V_155 ;
if ( ! V_18 -> V_210 )
return - V_211 ;
if ( strncmp ( V_9 , L_75 , sizeof( L_75 ) - 1 ) == 0 )
V_154 = V_18 -> F_48 ( V_18 ) ;
if ( V_154 == 0 )
return strlen ( V_9 ) ;
else
return V_154 ;
}
int
F_50 ( struct V_17 * V_18 )
{
struct V_215 V_216 = { 0 } ;
int V_3 ;
F_43 ( 100 ) ;
F_51 ( V_18 -> V_70 . V_38 . V_217 . V_218 ,
& V_216 . V_219 ) ;
if ( ! F_52 ( V_220 , & V_216 ) &&
! F_52 ( V_221 , & V_216 ) )
return - V_166 ;
for ( V_3 = 0 ; V_3 < V_222 ; V_3 ++ ) {
F_43 ( 10 ) ;
F_51 ( V_18 -> V_70 . V_38 . V_217 . V_218 ,
& V_216 . V_219 ) ;
if ( ! F_52 ( V_221 , & V_216 ) )
continue;
if ( ! F_52 ( V_220 , & V_216 ) )
continue;
if ( ! F_52 ( V_223 , & V_216 ) )
continue;
break;
}
if ( V_3 < V_222 )
return 0 ;
else
return - V_187 ;
}
static T_1
F_53 ( struct V_17 * V_18 , T_2 V_224 )
{
struct V_194 V_195 ;
struct V_225 * V_226 = V_18 -> V_227 ;
T_2 V_228 ;
T_2 V_229 ;
T_2 V_230 ;
int V_154 = 0 , V_202 = 0 ;
int V_231 = 1 , V_232 ;
if ( ! V_18 -> V_210 )
return - V_211 ;
if ( ( V_18 -> V_112 < V_113 ) ||
( F_52 ( V_233 , & V_18 -> V_70 . V_234 ) !=
V_235 ) )
return - V_166 ;
V_228 = V_18 -> V_212 -> V_143 ;
V_229 = V_18 -> V_236 ;
if ( V_18 -> V_236 ) {
F_54 ( V_226 ) ;
V_18 -> V_236 = 0 ;
}
if ( V_224 == V_237 )
V_18 -> V_19 |= V_238 ;
V_154 = F_44 ( V_18 , V_213 ) ;
if ( V_154 != 0 ) {
V_18 -> V_19 &= ~ V_238 ;
return V_154 ;
}
F_43 ( 100 ) ;
V_230 = F_55 ( V_18 -> V_70 . V_239 +
V_240 ) ;
if ( V_224 == V_237 )
V_230 |= V_241 ;
else if ( V_224 == V_242 )
V_230 |= V_243 ;
else if ( V_224 == V_244 )
V_230 |= V_245 ;
F_56 ( V_230 , V_18 -> V_70 . V_239 +
V_240 ) ;
F_55 ( V_18 -> V_70 . V_239 + V_240 ) ;
V_202 = F_50 ( V_18 ) ;
if ( V_202 == - V_166 ) {
F_38 ( V_18 , V_183 , V_185 ,
L_76
L_77 , V_230 ) ;
} else if ( V_202 == - V_187 ) {
F_38 ( V_18 , V_183 , V_185 ,
L_78
L_77 , V_230 ) ;
return V_202 ;
}
if ( V_228 & V_164 )
goto V_208;
F_45 ( & V_195 ) ;
V_231 = F_46 ( V_18 , & V_154 , & V_195 ,
V_214 ) ;
if ( ! V_231 )
goto V_208;
F_47 ( & V_195 ) ;
V_208:
if ( V_229 ) {
V_232 =
F_57 ( V_18 , V_229 ) ;
if ( ! V_232 )
V_18 -> V_236 = V_229 ;
}
if ( ! V_202 ) {
if ( ! V_231 )
V_202 = - V_169 ;
else if ( V_154 )
V_202 = - V_187 ;
}
return V_202 ;
}
static T_1
F_58 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_49 , V_18 -> V_246 ) ;
}
static T_1
F_59 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
char * V_247 ;
if ( V_18 -> V_119 == V_125 )
V_247 = L_79 ;
else if ( V_18 -> V_119 == V_121 )
V_247 = L_80 ;
else if ( V_18 -> V_119 == V_122 )
V_247 = L_81 ;
else
V_247 = L_82 ;
return snprintf ( V_9 , V_10 , L_48 , V_247 ) ;
}
static T_1
F_60 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_153 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_194 V_195 ;
char * V_248 = NULL ;
int V_154 = 0 ;
int V_202 ;
if ( ! V_18 -> V_210 ) {
V_154 = - V_211 ;
goto V_249;
}
F_61 ( V_15 , V_183 , V_193 ,
L_83 , V_9 ) ;
F_45 ( & V_195 ) ;
if( strncmp ( V_9 , L_82 , sizeof( L_82 ) - 1 ) == 0 ) {
V_202 = F_46 ( V_18 , & V_154 , & V_195 ,
V_214 ) ;
if ( V_202 == 0 ) {
V_154 = - V_169 ;
goto V_249;
}
F_47 ( & V_195 ) ;
} else if ( strncmp ( V_9 , L_81 , sizeof( L_81 ) - 1 ) == 0 )
V_154 = F_44 ( V_18 , V_213 ) ;
else if ( strncmp ( V_9 , L_84 , sizeof( L_84 ) - 1 ) == 0 )
if ( V_18 -> V_112 == V_113 )
V_154 = - V_155 ;
else
V_154 = F_44 ( V_18 , V_250 ) ;
else if ( strncmp ( V_9 , L_79 , sizeof( L_79 ) - 1 ) == 0 )
if ( V_18 -> V_112 == V_113 )
V_154 = - V_155 ;
else
V_154 = F_44 ( V_18 , V_251 ) ;
else if ( strncmp ( V_9 , L_85 , sizeof( L_85 ) - 1 ) == 0 )
V_154 = F_53 ( V_18 , V_237 ) ;
else if ( strncmp ( V_9 , L_86 , sizeof( L_86 ) - 1 ) == 0 )
V_154 = F_53 ( V_18 , V_242 ) ;
else if ( strncmp ( V_9 , L_87 , sizeof( L_87 ) - 1 ) == 0 )
V_154 = F_53 ( V_18 , V_244 ) ;
else
V_154 = - V_155 ;
V_249:
if ( ! V_154 )
return strlen ( V_9 ) ;
else {
V_248 = strchr ( V_9 , '\n' ) ;
if ( V_248 )
* V_248 = '\0' ;
F_61 ( V_15 , V_183 , V_193 ,
L_88
L_89 ,
V_9 , V_154 , V_18 -> V_212 -> V_143 ) ;
return V_154 ;
}
}
static int
F_62 ( struct V_17 * V_18 ,
T_2 * V_252 , T_2 * V_253 ,
T_2 * V_254 , T_2 * V_255 ,
T_2 * V_256 , T_2 * V_257 )
{
struct V_258 * V_259 ;
T_6 * V_161 ;
T_8 * V_260 ;
int V_202 = 0 ;
T_2 V_261 ;
if ( V_18 -> V_119 < V_124 ||
! V_18 -> V_167 ||
( V_18 -> V_103 . V_104 & V_262 ) == 0 )
return 0 ;
if ( V_18 -> V_103 . V_104 & V_165 )
return 0 ;
V_161 = F_35 ( V_18 -> V_167 , V_168 ) ;
if ( ! V_161 )
return 0 ;
memset ( V_161 , 0 , sizeof ( T_6 ) ) ;
V_260 = & V_161 -> V_38 . V_170 ;
V_260 -> V_171 = V_263 ;
V_260 -> V_173 = V_174 ;
V_161 -> V_264 = NULL ;
if ( V_18 -> V_212 -> V_143 & V_164 )
V_202 = V_265 ;
else
V_202 = F_36 ( V_18 , V_161 , V_18 -> V_181 * 2 ) ;
if ( V_202 != V_176 ) {
if ( V_202 != V_186 )
F_40 ( V_161 , V_18 -> V_167 ) ;
return 0 ;
}
if ( V_18 -> V_112 == V_113 ) {
V_259 = & V_161 -> V_38 . V_266 . V_267 . V_259 ;
if ( V_254 )
* V_254 = F_52 ( V_268 , V_259 ) ;
if ( V_255 )
* V_255 = F_52 ( V_268 , V_259 ) -
V_18 -> V_70 . V_269 . V_270 ;
if ( V_252 )
* V_252 = F_52 ( V_271 , V_259 ) ;
if ( V_253 )
* V_253 = F_52 ( V_271 , V_259 ) -
V_18 -> V_70 . V_269 . V_272 ;
V_261 = ( F_52 ( V_273 , V_259 ) > 0 ) ?
( F_52 ( V_273 , V_259 ) - 1 ) : 0 ;
if ( V_256 )
* V_256 = V_261 ;
if ( V_257 )
* V_257 = V_261 - V_18 -> V_70 . V_269 . V_274 ;
} else {
if ( V_254 )
* V_254 = V_260 -> V_267 . V_275 . V_276 ;
if ( V_255 )
* V_255 = V_260 -> V_267 . V_275 . V_277 ;
if ( V_252 )
* V_252 = V_260 -> V_267 . V_275 . V_278 ;
if ( V_253 )
* V_253 = V_260 -> V_267 . V_275 . V_279 ;
if ( V_256 )
* V_256 = V_260 -> V_267 . V_275 . V_261 ;
if ( V_257 )
* V_257 = V_260 -> V_267 . V_275 . V_280 ;
}
F_40 ( V_161 , V_18 -> V_167 ) ;
return 1 ;
}
static T_1
F_63 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_191 ;
if ( F_62 ( V_18 , NULL , NULL , & V_191 , NULL , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_49 , V_191 ) ;
return snprintf ( V_9 , V_10 , L_59 ) ;
}
static T_1
F_64 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_191 , V_281 ;
if ( F_62 ( V_18 , NULL , NULL , & V_191 , & V_281 , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_49 , ( V_191 - V_281 ) ) ;
return snprintf ( V_9 , V_10 , L_59 ) ;
}
static T_1
F_65 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_191 ;
if ( F_62 ( V_18 , & V_191 , NULL , NULL , NULL , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_49 , V_191 ) ;
return snprintf ( V_9 , V_10 , L_59 ) ;
}
static T_1
F_66 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_191 , V_281 ;
if ( F_62 ( V_18 , & V_191 , & V_281 , NULL , NULL , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_49 , ( V_191 - V_281 ) ) ;
return snprintf ( V_9 , V_10 , L_59 ) ;
}
static T_1
F_67 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_191 ;
if ( F_62 ( V_18 , NULL , NULL , NULL , NULL , & V_191 , NULL ) )
return snprintf ( V_9 , V_10 , L_49 , V_191 ) ;
return snprintf ( V_9 , V_10 , L_59 ) ;
}
static T_1
F_68 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_191 , V_281 ;
if ( F_62 ( V_18 , NULL , NULL , NULL , NULL , & V_191 , & V_281 ) )
return snprintf ( V_9 , V_10 , L_49 , ( V_191 - V_281 ) ) ;
return snprintf ( V_9 , V_10 , L_59 ) ;
}
static T_1
F_69 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( ! ( V_18 -> V_261 ) )
return snprintf ( V_9 , V_10 , L_90 ) ;
if ( V_15 -> V_282 == V_283 )
return snprintf ( V_9 , V_10 , L_91 ) ;
return snprintf ( V_9 , V_10 , L_92 , V_15 -> V_284 ) ;
}
static T_1
F_70 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_93 , V_18 -> V_285 ) ;
}
static T_1
F_71 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_153 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_286 ;
T_2 V_287 ;
int V_288 = 0 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_155 ;
if ( sscanf ( V_9 , L_94 , & V_288 ) != 1 )
return - V_155 ;
if ( ( V_288 & 0x3 ) != V_288 )
return - V_155 ;
if ( V_18 -> V_112 == V_113 )
V_288 = 0 ;
F_61 ( V_15 , V_183 , V_193 ,
L_95 ,
V_18 -> V_285 , V_288 ) ;
F_9 ( & V_18 -> V_207 ) ;
V_287 = V_18 -> V_285 ;
if ( V_288 & V_289 ) {
if ( ( V_288 & V_290 ) &&
! ( V_287 & V_290 ) ) {
if ( F_51 ( V_18 -> V_291 , & V_286 ) ) {
F_11 ( & V_18 -> V_207 ) ;
return - V_155 ;
}
V_286 &= ~ ( V_292 << V_293 ) ;
F_56 ( V_286 , V_18 -> V_291 ) ;
F_55 ( V_18 -> V_291 ) ;
F_72 ( V_18 ) ;
}
} else if ( V_288 != 0x0 ) {
F_11 ( & V_18 -> V_207 ) ;
return - V_155 ;
}
if ( ! ( V_288 & V_290 ) &&
( V_287 & V_290 ) )
{
F_11 ( & V_18 -> V_207 ) ;
F_73 ( & V_18 -> V_294 ) ;
F_9 ( & V_18 -> V_207 ) ;
if ( F_51 ( V_18 -> V_291 , & V_286 ) ) {
F_11 ( & V_18 -> V_207 ) ;
return - V_155 ;
}
V_286 |= ( V_292 << V_293 ) ;
F_56 ( V_286 , V_18 -> V_291 ) ;
F_55 ( V_18 -> V_291 ) ;
}
V_18 -> V_285 = V_288 ;
F_11 ( & V_18 -> V_207 ) ;
return strlen ( V_9 ) ;
}
static T_1
F_74 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_49 , V_18 -> V_295 ) ;
}
static T_1
F_75 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_49 , V_18 -> V_296 ) ;
}
static T_1
F_76 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_96 ,
( V_18 -> V_297 ) ? L_97 : L_98 ,
( V_18 -> V_92 & V_298 ) ?
L_99 : L_100 ) ;
}
static T_1
F_77 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_9 V_299 ;
V_299 = F_78 ( V_18 ) ;
return snprintf ( V_9 , V_10 , L_49 , V_299 ) ;
}
static inline bool F_79 ( T_10 V_288 , T_10 V_300 , T_10 V_301 )
{
return V_288 >= V_300 && V_288 <= V_301 ;
}
static T_5
F_80 ( const char * V_9 , T_5 V_191 , char V_39 [] )
{
unsigned int V_3 , V_4 ;
if ( V_9 [ V_191 - 1 ] == '\n' )
V_191 -- ;
if ( ( V_191 < 16 ) || ( V_191 > 18 ) || ( ( V_191 == 17 ) && ( * V_9 ++ != 'x' ) ) ||
( ( V_191 == 18 ) && ( ( * V_9 ++ != '0' ) || ( * V_9 ++ != 'x' ) ) ) )
return - V_155 ;
memset ( V_39 , 0 , V_302 ) ;
for ( V_3 = 0 , V_4 = 0 ; V_3 < 16 ; V_3 ++ ) {
if ( ( * V_9 >= 'a' ) && ( * V_9 <= 'f' ) )
V_4 = ( ( V_4 << 4 ) | ( ( * V_9 ++ - 'a' ) + 10 ) ) ;
else if ( ( * V_9 >= 'A' ) && ( * V_9 <= 'F' ) )
V_4 = ( ( V_4 << 4 ) | ( ( * V_9 ++ - 'A' ) + 10 ) ) ;
else if ( ( * V_9 >= '0' ) && ( * V_9 <= '9' ) )
V_4 = ( ( V_4 << 4 ) | ( * V_9 ++ - '0' ) ) ;
else
return - V_155 ;
if ( V_3 % 2 ) {
V_39 [ V_3 / 2 ] = V_4 & 0xff ;
V_4 = 0 ;
}
}
return 0 ;
}
static T_1
F_81 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_153 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
unsigned int V_191 = V_153 ;
T_3 V_303 = V_15 -> V_304 . V_305 . V_306 ;
T_11 * V_307 = ( T_2 * ) & V_15 -> V_304 . V_267 . V_308 [ 0 ] ;
if ( V_303 == 1 && F_82 ( * V_307 ) == V_309 ) {
F_38 ( V_18 , V_183 , V_193 ,
L_101 V_310 L_102
L_103 ) ;
return - V_155 ;
}
if ( V_9 [ V_191 - 1 ] == '\n' )
V_191 -- ;
if ( ( V_191 != strlen ( V_311 ) ) ||
( strncmp ( V_9 , V_311 , strlen ( V_311 ) ) != 0 ) )
return - V_155 ;
V_18 -> V_312 = 1 ;
F_83 ( V_192 , & V_18 -> V_227 -> V_6 ,
L_104 ,
V_18 -> V_41 ) ;
F_83 ( V_192 , & V_18 -> V_227 -> V_6 ,
L_105 ) ;
return V_153 ;
}
static T_1
F_84 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_106 ,
( unsigned long long ) V_18 -> V_313 ) ;
}
static T_1
F_85 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_153 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_194 V_195 ;
int V_314 = 0 , V_315 = 0 ;
unsigned int V_191 = V_153 ;
T_12 V_316 [ V_302 ] ;
int V_202 ;
if ( ! V_18 -> V_210 )
return - V_211 ;
F_9 ( & V_18 -> V_207 ) ;
if ( V_18 -> V_317 == V_318 ) {
F_11 ( & V_18 -> V_207 ) ;
return - V_211 ;
}
F_11 ( & V_18 -> V_207 ) ;
if ( V_9 [ V_191 - 1 ] == '\n' )
V_191 -- ;
if ( ! V_18 -> V_312 )
return - V_155 ;
V_18 -> V_312 = 0 ;
V_202 = F_80 ( V_9 , V_191 , V_316 ) ;
if ( V_202 ) {
V_18 -> V_312 = 1 ;
return V_202 ;
}
V_18 -> V_313 = F_7 ( V_316 ) ;
F_86 ( V_13 ) = V_18 -> V_313 ;
if ( V_18 -> V_319 )
F_87 ( V_13 ) = V_18 -> V_319 ;
F_83 ( V_320 , & V_18 -> V_227 -> V_6 ,
L_107 , V_18 -> V_41 ) ;
V_314 = F_44 ( V_18 , V_213 ) ;
if ( V_314 )
F_38 ( V_18 , V_183 , V_193 ,
L_108
L_109 , V_314 ) ;
F_45 ( & V_195 ) ;
V_202 = F_46 ( V_18 , & V_315 , & V_195 ,
V_214 ) ;
if ( V_202 == 0 )
return - V_169 ;
F_47 ( & V_195 ) ;
if ( V_315 )
F_38 ( V_18 , V_183 , V_193 ,
L_110
L_109 , V_315 ) ;
return ( V_314 || V_315 ) ? - V_187 : V_153 ;
}
static T_1
F_88 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_106 ,
( unsigned long long ) V_18 -> V_319 ) ;
}
static T_1
F_89 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_153 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
unsigned int V_191 = V_153 ;
T_12 V_321 [ V_302 ] ;
int V_202 ;
if ( V_9 [ V_191 - 1 ] == '\n' )
V_191 -- ;
if ( ! V_18 -> V_312 )
return - V_155 ;
V_202 = F_80 ( V_9 , V_191 , V_321 ) ;
if ( V_202 ) {
return V_202 ;
}
V_18 -> V_319 = F_7 ( V_321 ) ;
F_83 ( V_320 , & V_18 -> V_227 -> V_6 ,
L_111
L_112 , V_18 -> V_41 ) ;
return V_153 ;
}
static T_1
F_90 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_106 ,
F_7 ( V_18 -> V_322 ) ) ;
}
static T_1
F_91 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_153 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
unsigned int V_191 = V_153 ;
T_3 V_316 [ V_302 ] ;
int V_202 ;
if ( ! V_18 -> V_323 )
return - V_166 ;
if ( V_9 [ V_191 - 1 ] == '\n' )
V_191 -- ;
V_202 = F_80 ( V_9 , V_191 , V_316 ) ;
if ( V_202 )
return V_202 ;
memcpy ( V_18 -> V_322 , V_316 , ( 8 * sizeof( T_3 ) ) ) ;
memcpy ( V_18 -> V_70 . V_324 , V_316 , ( 8 * sizeof( T_3 ) ) ) ;
if ( F_7 ( V_316 ) == 0 )
V_18 -> V_325 |= V_326 ;
else
V_18 -> V_325 &= ~ V_326 ;
V_18 -> V_325 &= ~ V_327 ;
V_18 -> V_70 . V_328 = V_329 ;
return V_153 ;
}
static T_1
F_92 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_49 , V_18 -> V_330 ) ;
}
static T_1
F_93 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_153 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
unsigned int V_191 = V_153 ;
unsigned long V_288 ;
int V_331 ;
if ( ! V_18 -> V_323 )
return - V_166 ;
if ( V_9 [ V_191 - 1 ] == '\n' )
V_191 -- ;
V_331 = F_94 ( V_9 , 0 , & V_288 ) ;
if ( V_331 || ( V_288 > 0x7f ) )
return - V_155 ;
if ( V_288 )
V_18 -> V_330 = ( T_3 ) V_288 ;
else
V_18 -> V_330 = V_18 -> V_332 ;
return V_153 ;
}
static T_1
F_95 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_106 ,
F_7 ( V_18 -> V_333 ) ) ;
}
static T_1
F_96 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_153 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
unsigned int V_191 = V_153 ;
T_3 V_316 [ V_302 ] ;
int V_202 ;
if ( ! V_18 -> V_323 )
return - V_166 ;
if ( V_9 [ V_191 - 1 ] == '\n' )
V_191 -- ;
V_202 = F_80 ( V_9 , V_191 , V_316 ) ;
if ( V_202 )
return V_202 ;
memcpy ( V_18 -> V_333 , V_316 , ( 8 * sizeof( T_3 ) ) ) ;
memcpy ( V_18 -> V_70 . V_334 , V_316 , ( 8 * sizeof( T_3 ) ) ) ;
if ( F_7 ( V_316 ) == 0 )
V_18 -> V_325 |= V_335 ;
else
V_18 -> V_325 &= ~ V_335 ;
V_18 -> V_325 &= ~ V_327 ;
if ( V_18 -> V_330 == 0 )
V_18 -> V_330 = V_18 -> V_332 ;
V_18 -> V_70 . V_328 = V_329 ;
return V_153 ;
}
static T_1
F_97 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_49 , V_18 -> V_336 ) ;
}
static T_1
F_98 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_153 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
int V_288 = 0 ;
if ( ! V_18 -> V_323 )
return - V_166 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_155 ;
if ( sscanf ( V_9 , L_94 , & V_288 ) != 1 )
return - V_155 ;
if ( ( V_288 != 0 ) && ( V_288 != 1 ) )
return - V_155 ;
V_18 -> V_336 = V_288 ;
return strlen ( V_9 ) ;
}
static T_1
F_99 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
if ( ! ( V_18 -> V_325 & V_327 ) )
return - V_337 ;
return snprintf ( V_9 , V_10 , L_49 , V_18 -> V_338 ) ;
}
static T_5
F_100 ( struct V_17 * V_18 , T_3 V_339 [] ,
T_3 V_340 [] , T_13 V_341 ,
T_2 V_342 , T_3 V_343 )
{
int V_202 = 0 ;
if ( ! V_18 -> V_323 )
return - V_166 ;
if ( V_342 ) {
if ( ! F_101 ( V_18 , (struct V_344 * ) V_339 ,
(struct V_344 * ) V_340 ,
V_341 , V_343 ) )
V_202 = - V_169 ;
} else {
F_102 ( V_18 , (struct V_344 * ) V_339 ,
(struct V_344 * ) V_340 , V_341 , V_343 ) ;
}
return V_202 ;
}
static T_13
F_103 ( struct V_17 * V_18 , T_3 V_339 [] ,
T_3 V_340 [] , T_2 * V_345 ,
T_2 * V_346 )
{
T_13 V_347 ;
if ( F_104 ( ! V_18 ) || ! V_339 || ! V_340 )
return V_348 ;
if ( F_105 ( V_18 , (struct V_344 * )
V_18 -> V_70 . V_334 ,
(struct V_344 * )
V_18 -> V_70 . V_324 ,
& V_18 -> V_70 . V_328 ,
(struct V_344 * ) V_339 ,
(struct V_344 * ) V_340 ,
& V_347 , V_345 , V_346 ) )
return V_347 ;
else
return V_348 ;
}
static T_1
F_106 ( struct V_17 * V_18 , T_3 V_339 [] ,
T_3 V_340 [] , T_13 V_341 ,
T_2 V_342 , T_3 V_343 )
{
int V_202 ;
V_202 = F_100 ( V_18 , V_339 , V_340 , V_341 ,
V_342 , V_343 ) ;
return V_202 ;
}
static T_1
F_107 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
T_13 V_349 ;
int V_32 = 0 ;
if ( ! V_18 -> V_323 )
return - V_166 ;
if ( F_7 ( V_18 -> V_333 ) == 0 )
if ( ! ( V_18 -> V_325 & V_335 ) )
return - V_337 ;
if ( F_7 ( V_18 -> V_322 ) == 0 )
if ( ! ( V_18 -> V_325 & V_326 ) )
return - V_337 ;
V_349 = F_103 ( V_18 , V_18 -> V_333 ,
V_18 -> V_322 ,
& V_18 -> V_338 ,
& V_18 -> V_330 ) ;
if ( V_349 != V_348 )
V_18 -> V_325 |= V_327 ;
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 , L_113 , V_349 ) ;
return V_32 ;
}
static T_1
F_108 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_153 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
T_13 V_350 ;
T_2 V_343 ;
T_1 V_202 ;
if ( ! V_18 -> V_323 )
return - V_166 ;
if ( F_7 ( V_18 -> V_333 ) == 0 )
return - V_337 ;
if ( F_7 ( V_18 -> V_322 ) == 0 )
return - V_337 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_155 ;
if ( sscanf ( V_9 , L_113 , & V_350 ) != 1 )
return - V_155 ;
V_343 = V_18 -> V_330 ;
if ( V_343 == 0 )
V_343 = V_18 -> V_332 ;
F_38 ( V_18 , V_351 , V_193 ,
L_114
L_115 ,
F_7 ( V_18 -> V_333 ) ,
F_7 ( V_18 -> V_322 ) , V_350 ,
V_343 , V_18 -> V_336 ) ;
V_202 = F_106 ( V_18 , V_18 -> V_333 ,
V_18 -> V_322 , V_350 ,
V_18 -> V_336 , V_343 ) ;
if ( V_202 )
return V_202 ;
return V_153 ;
}
static T_1
F_109 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_49 , V_18 -> V_352 ) ;
}
static T_1
F_110 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
struct V_198 * V_199 = F_111 ( V_18 ) ;
return snprintf ( V_9 , V_10 , L_49 , V_199 -> V_353 ) ;
}
static T_1
F_112 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
struct V_198 * V_199 = F_111 ( V_18 ) ;
return snprintf ( V_9 , V_10 , L_49 , V_199 -> V_354 ) ;
}
static T_1
F_113 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
return snprintf ( V_9 , V_10 , L_49 , V_15 -> V_355 ) ;
}
static int
F_114 ( struct V_14 * V_15 , int V_288 )
{
if ( V_15 -> V_355 != V_356 ) {
V_15 -> V_357 = V_15 -> V_355 ;
if ( V_288 != V_356 )
F_61 ( V_15 , V_183 , V_193 ,
L_116
L_117
L_118 ) ;
return 0 ;
}
if ( V_288 >= V_358 && V_288 <= V_359 ) {
V_15 -> V_357 = V_288 ;
V_15 -> V_355 = V_288 ;
return 0 ;
}
F_61 ( V_15 , V_183 , V_193 ,
L_119
L_120 ,
V_288 , V_358 , V_359 ) ;
V_15 -> V_357 = V_356 ;
return - V_155 ;
}
static void
F_115 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
struct V_360 * V_361 ;
V_13 = F_116 ( V_15 ) ;
F_9 ( V_13 -> V_74 ) ;
F_10 (ndlp, &vport->fc_nodes, nlp_listp)
if ( F_117 ( V_361 ) && V_361 -> V_28 )
V_361 -> V_28 -> V_362 = V_15 -> V_355 ;
F_11 ( V_13 -> V_74 ) ;
}
static int
F_118 ( struct V_14 * V_15 , int V_288 )
{
if ( V_15 -> V_363 ||
( V_364 != V_356 ) ) {
F_61 ( V_15 , V_183 , V_193 ,
L_121
L_122 ) ;
return 0 ;
}
if ( V_288 >= V_358 && V_288 <= V_359 ) {
V_15 -> V_357 = V_288 ;
V_15 -> V_355 = V_288 ;
F_119 ( F_116 ( V_15 ) ) = V_288 ;
F_115 ( V_15 ) ;
return 0 ;
}
F_61 ( V_15 , V_183 , V_193 ,
L_123
L_124 ,
V_288 , V_358 , V_359 ) ;
return - V_155 ;
}
static int
F_120 ( struct V_14 * V_15 , int V_288 )
{
if ( V_288 >= V_358 && V_288 <= V_359 ) {
V_15 -> V_357 = V_288 ;
V_15 -> V_355 = V_288 ;
V_15 -> V_363 = 1 ;
F_119 ( F_116 ( V_15 ) ) = V_288 ;
F_115 ( V_15 ) ;
return 0 ;
}
F_61 ( V_15 , V_183 , V_193 ,
L_125
L_124 ,
V_288 , V_358 , V_359 ) ;
return - V_155 ;
}
static int
F_121 ( struct V_14 * V_15 , int V_288 )
{
if ( V_288 < 0 || V_288 > 1 ) {
F_61 ( V_15 , V_183 , V_193 ,
L_126
L_127 ,
V_288 ) ;
V_15 -> V_365 = 1 ;
return - V_155 ;
}
if ( V_15 -> V_282 == V_283 ) {
V_15 -> V_365 = 0 ;
return 0 ;
}
V_15 -> V_365 = V_288 ;
return 0 ;
}
static int
F_122 ( struct V_14 * V_15 , int V_288 )
{
if ( V_288 < 0 || V_288 > 1 ) {
F_61 ( V_15 , V_183 , V_193 ,
L_128
L_127 ,
V_288 ) ;
V_15 -> V_365 = 1 ;
return - V_155 ;
}
if ( V_15 -> V_282 == V_283 && V_288 != 0 ) {
F_61 ( V_15 , V_183 , V_193 ,
L_129
L_130 ) ;
V_15 -> V_365 = 0 ;
return 0 ;
}
V_15 -> V_365 = V_288 ;
return 0 ;
}
static T_1
F_123 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_153 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_288 = 0 ;
int V_366 = 0 ;
const char * V_367 = V_9 ;
int V_368 ;
T_2 V_369 ;
if ( ! strncmp ( V_9 , L_131 , strlen ( L_131 ) ) ) {
V_366 = 1 ;
V_367 = & V_9 [ strlen ( L_131 ) ] ;
}
if ( ! isdigit ( V_367 [ 0 ] ) )
return - V_155 ;
if ( sscanf ( V_367 , L_94 , & V_288 ) != 1 )
return - V_155 ;
if ( V_288 >= 0 && V_288 <= 6 ) {
V_369 = V_18 -> V_179 ;
if ( V_18 -> V_180 == V_370 &&
V_288 == 4 ) {
F_61 ( V_15 , V_183 , V_193 ,
L_132 ,
V_288 ) ;
return - V_155 ;
}
if ( V_18 -> V_227 -> V_5 == V_371 &&
V_288 == 4 ) {
F_61 ( V_15 , V_183 , V_193 ,
L_133 ) ;
return - V_155 ;
}
V_18 -> V_179 = V_288 ;
if ( V_366 )
return strlen ( V_9 ) ;
F_61 ( V_15 , V_183 , V_193 ,
L_134 ,
V_369 , V_288 ) ;
if ( V_369 != V_288 && V_18 -> V_112 == V_113 )
V_18 -> V_372 = 1 ;
V_368 = F_34 ( F_116 ( V_18 -> V_212 ) ) ;
if ( V_368 ) {
V_18 -> V_179 = V_369 ;
return - V_155 ;
} else
return strlen ( V_9 ) ;
}
F_38 ( V_18 , V_183 , V_193 ,
L_135
L_136 ,
V_18 -> V_41 , V_288 ) ;
return - V_155 ;
}
static T_1
F_124 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
if ( V_15 -> V_373 & V_374 )
sprintf ( V_9 , L_2 ) ;
else
sprintf ( V_9 , L_3 ) ;
return strlen ( V_9 ) ;
}
static T_1
F_125 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_153 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
#define F_126 1024
static char V_375 [ F_126 ] ;
unsigned long V_3 ;
char * V_376 , * V_377 ;
struct V_14 * * V_378 ;
struct V_12 * V_379 ;
char * V_380 , * V_381 , * V_382 ;
unsigned long V_383 , V_384 , V_385 ;
if ( ! strncmp ( V_9 , L_137 , strlen ( L_137 ) ) ) {
if ( strlen ( V_9 ) > ( F_126 - 1 ) )
return - V_155 ;
strncpy ( V_375 , V_9 , F_126 ) ;
V_376 = & V_375 [ 0 ] ;
V_377 = F_127 ( & V_376 , L_138 ) ;
if ( ! V_377 )
return - V_155 ;
V_380 = F_127 ( & V_376 , L_138 ) ;
if ( ! V_380 )
return - V_155 ;
if ( ! strncmp ( V_380 , L_139 , strlen ( L_139 ) ) )
V_385 = V_386 ;
else if ( ! strncmp ( V_380 , L_140 , strlen ( L_140 ) ) )
V_385 = V_387 ;
else
return - V_155 ;
V_381 = F_127 ( & V_376 , L_138 ) ;
if ( ! V_381 )
return - V_155 ;
V_383 = F_128 ( V_381 , NULL , 0 ) ;
V_382 = F_127 ( & V_376 , L_138 ) ;
if ( ! V_382 )
return - V_155 ;
V_384 = F_128 ( V_382 , NULL , 0 ) ;
if ( ! V_384 )
return - V_155 ;
V_378 = F_129 ( V_18 ) ;
if ( V_378 == NULL )
return - V_169 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_388 && V_378 [ V_3 ] != NULL ; V_3 ++ ) {
V_379 = F_116 ( V_378 [ V_3 ] ) ;
F_9 ( V_379 -> V_74 ) ;
V_378 [ V_3 ] -> V_389 = 1 ;
if ( V_378 [ V_3 ] -> V_390 )
F_130 ( V_378 [ V_3 ] ) ;
F_11 ( V_379 -> V_74 ) ;
}
V_18 -> V_385 = V_385 ;
V_18 -> V_391 = V_383 ;
V_18 -> V_392 = V_384 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_388 && V_378 [ V_3 ] != NULL ; V_3 ++ ) {
V_379 = F_116 ( V_378 [ V_3 ] ) ;
F_9 ( V_379 -> V_74 ) ;
V_378 [ V_3 ] -> V_389 = 0 ;
F_11 ( V_379 -> V_74 ) ;
}
F_131 ( V_18 , V_378 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_141 , strlen ( L_141 ) ) ) {
V_378 = F_129 ( V_18 ) ;
if ( V_378 == NULL )
return - V_169 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_388 && V_378 [ V_3 ] != NULL ; V_3 ++ ) {
V_379 = F_116 ( V_378 [ V_3 ] ) ;
F_9 ( V_13 -> V_74 ) ;
V_378 [ V_3 ] -> V_389 = 1 ;
F_132 ( V_15 ) ;
V_15 -> V_390 = 0 ;
V_378 [ V_3 ] -> V_389 = 0 ;
F_11 ( V_13 -> V_74 ) ;
}
F_131 ( V_18 , V_378 ) ;
V_18 -> V_385 = V_393 ;
V_18 -> V_391 = 0 ;
V_18 -> V_392 = 0 ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_142 , strlen ( L_142 ) ) ) {
if ( V_18 -> V_385 == V_393 )
return - V_155 ;
F_9 ( V_13 -> V_74 ) ;
if ( V_15 -> V_390 ) {
F_11 ( V_13 -> V_74 ) ;
return strlen ( V_9 ) ;
}
F_133 ( V_15 ) ;
V_15 -> V_390 = 1 ;
F_11 ( V_13 -> V_74 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_143 , strlen ( L_143 ) ) ) {
F_9 ( V_13 -> V_74 ) ;
if ( V_15 -> V_390 == 0 ) {
F_11 ( V_13 -> V_74 ) ;
return strlen ( V_9 ) ;
}
F_132 ( V_15 ) ;
V_15 -> V_390 = 0 ;
F_11 ( V_13 -> V_74 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_144 , strlen ( L_144 ) ) ) {
if ( ( V_18 -> V_385 == V_393 )
|| ! V_15 -> V_390 )
return strlen ( V_9 ) ;
F_9 ( V_13 -> V_74 ) ;
V_15 -> V_389 = 1 ;
F_130 ( V_15 ) ;
V_15 -> V_389 = 0 ;
F_11 ( V_13 -> V_74 ) ;
return strlen ( V_9 ) ;
}
return - V_155 ;
}
static T_1
F_134 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_394 = 0 ;
int V_3 ;
char * V_385 ;
unsigned long V_395 ;
switch ( V_18 -> V_385 ) {
case V_386 :
V_385 = L_139 ;
break;
case V_387 :
V_385 = L_140 ;
break;
default:
V_385 = L_145 ;
break;
}
sprintf ( & V_9 [ V_394 ] , L_146
L_147
L_148 ,
V_15 -> V_390 , V_15 -> V_389 ,
V_385 , V_18 -> V_391 , V_18 -> V_392 ) ;
V_394 = strlen ( V_9 ) ;
if ( V_18 -> V_385 != V_393 ) {
for ( V_3 = 0 ; V_3 < V_396 ; V_3 ++ ) {
if ( V_18 -> V_385 == V_386 )
V_395 = V_18 -> V_391 +
V_18 -> V_392 * V_3 ;
else
V_395 = V_18 -> V_391 +
( 1 << V_3 ) * V_18 -> V_392 ;
if ( V_394 + 10 > V_10 )
break;
sprintf ( & V_9 [ V_394 ] , L_149 , V_395 ) ;
V_394 = strlen ( V_9 ) ;
}
}
sprintf ( & V_9 [ V_394 ] , L_1 ) ;
return strlen ( V_9 ) ;
}
static T_1
F_135 ( struct V_397 * V_398 , struct V_399 * V_400 ,
struct V_401 * V_402 ,
char * V_9 , T_14 V_403 , T_5 V_153 )
{
struct V_5 * V_6 = F_136 ( V_400 , struct V_5 ,
V_400 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_3 = 0 , V_394 = 0 ;
unsigned long V_404 ;
struct V_360 * V_361 = NULL ;
V_404 = ( unsigned long ) V_403 /
V_405 ;
if ( ! V_15 -> V_390 || V_15 -> V_389
|| ( V_18 -> V_385 == V_393 ) )
return 0 ;
F_9 ( V_13 -> V_74 ) ;
F_10 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_117 ( V_361 ) || ! V_361 -> V_406 )
continue;
if ( V_404 > 0 ) {
V_404 -- ;
continue;
}
if ( ( V_394 + V_405 )
> V_153 )
break;
if ( ! V_361 -> V_406 )
continue;
sprintf ( & V_9 [ V_394 ] , L_150 ,
V_361 -> V_407 . V_38 . V_39 [ 0 ] ,
V_361 -> V_407 . V_38 . V_39 [ 1 ] ,
V_361 -> V_407 . V_38 . V_39 [ 2 ] ,
V_361 -> V_407 . V_38 . V_39 [ 3 ] ,
V_361 -> V_407 . V_38 . V_39 [ 4 ] ,
V_361 -> V_407 . V_38 . V_39 [ 5 ] ,
V_361 -> V_407 . V_38 . V_39 [ 6 ] ,
V_361 -> V_407 . V_38 . V_39 [ 7 ] ) ;
V_394 = strlen ( V_9 ) ;
for ( V_3 = 0 ; V_3 < V_396 ; V_3 ++ ) {
sprintf ( & V_9 [ V_394 ] , L_151 ,
V_361 -> V_406 [ V_3 ] . V_408 ) ;
V_394 = strlen ( V_9 ) ;
}
sprintf ( & V_9 [ V_394 ] , L_1 ) ;
V_394 = strlen ( V_9 ) ;
}
F_11 ( V_13 -> V_74 ) ;
return V_394 ;
}
static T_1
F_137 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_153 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_288 = V_409 ;
int V_366 = 0 ;
const char * V_367 = V_9 ;
int V_368 ;
T_2 V_369 , V_107 ;
V_107 = F_52 ( V_233 , & V_18 -> V_70 . V_234 ) ;
if ( V_107 == V_235 &&
V_18 -> V_19 & V_410 )
return - V_166 ;
if ( ! strncmp ( V_9 , L_131 , strlen ( L_131 ) ) ) {
V_366 = 1 ;
V_367 = & V_9 [ strlen ( L_131 ) ] ;
}
if ( ! isdigit ( V_367 [ 0 ] ) )
return - V_155 ;
if ( sscanf ( V_367 , L_94 , & V_288 ) != 1 )
return - V_155 ;
F_61 ( V_15 , V_183 , V_193 ,
L_152 ,
V_18 -> V_180 , V_288 , V_366 ? L_153 : L_154 ) ;
if ( ( ( V_288 == V_411 ) && ! ( V_18 -> V_412 & V_413 ) ) ||
( ( V_288 == V_414 ) && ! ( V_18 -> V_412 & V_415 ) ) ||
( ( V_288 == V_416 ) && ! ( V_18 -> V_412 & V_417 ) ) ||
( ( V_288 == V_418 ) && ! ( V_18 -> V_412 & V_419 ) ) ||
( ( V_288 == V_420 ) && ! ( V_18 -> V_412 & V_421 ) ) ||
( ( V_288 == V_370 ) && ! ( V_18 -> V_412 & V_422 ) ) ||
( ( V_288 == V_423 ) && ! ( V_18 -> V_412 & V_424 ) ) ) {
F_38 ( V_18 , V_183 , V_193 ,
L_155
L_156 ,
V_288 ) ;
return - V_155 ;
}
if ( V_288 == V_370 &&
V_18 -> V_141 == V_142 ) {
F_38 ( V_18 , V_183 , V_193 ,
L_157
L_158 ,
V_288 ) ;
return - V_155 ;
}
if ( ( V_288 >= 0 ) && ( V_288 <= V_425 ) &&
( V_426 & ( 1 << V_288 ) ) ) {
V_369 = V_18 -> V_180 ;
V_18 -> V_180 = V_288 ;
if ( V_366 )
return strlen ( V_9 ) ;
V_368 = F_34 ( F_116 ( V_18 -> V_212 ) ) ;
if ( V_368 ) {
V_18 -> V_180 = V_369 ;
return - V_155 ;
} else
return strlen ( V_9 ) ;
}
F_38 ( V_18 , V_183 , V_193 ,
L_159
L_160 V_427 L_161 , V_288 ) ;
return - V_155 ;
}
static int
F_138 ( struct V_17 * V_18 , int V_288 )
{
if ( V_288 == V_370 && V_18 -> V_179 == 4 ) {
F_38 ( V_18 , V_183 , V_193 ,
L_162
L_163 ,
V_288 ) ;
V_18 -> V_179 = 0 ;
}
if ( ( V_288 >= 0 ) && ( V_288 <= V_425 ) &&
( V_426 & ( 1 << V_288 ) ) ) {
V_18 -> V_180 = V_288 ;
return 0 ;
}
F_38 ( V_18 , V_183 , V_193 ,
L_164
L_165
L_166 V_427 L_161 , V_288 ) ;
V_18 -> V_180 = V_409 ;
return - V_155 ;
}
static T_1
F_139 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_153 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_288 = 0 , V_202 = - V_155 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_155 ;
if ( sscanf ( V_9 , L_94 , & V_288 ) != 1 )
return - V_155 ;
switch ( V_288 ) {
case 0 :
if ( V_18 -> V_19 & V_428 ) {
V_202 = F_140 ( V_18 -> V_227 ) ;
if ( ! V_202 ) {
F_9 ( & V_18 -> V_207 ) ;
V_18 -> V_19 &= ~ V_428 ;
F_11 ( & V_18 -> V_207 ) ;
V_18 -> V_429 = 0 ;
V_202 = strlen ( V_9 ) ;
} else
V_202 = - V_166 ;
} else {
V_18 -> V_429 = 0 ;
V_202 = strlen ( V_9 ) ;
}
break;
case 1 :
if ( ! ( V_18 -> V_19 & V_428 ) ) {
V_202 = F_141 ( V_18 -> V_227 ) ;
if ( ! V_202 ) {
F_9 ( & V_18 -> V_207 ) ;
V_18 -> V_19 |= V_428 ;
F_11 ( & V_18 -> V_207 ) ;
V_18 -> V_429 = 1 ;
V_202 = strlen ( V_9 ) ;
} else
V_202 = - V_166 ;
} else {
V_18 -> V_429 = 1 ;
V_202 = strlen ( V_9 ) ;
}
break;
default:
V_202 = - V_155 ;
break;
}
return V_202 ;
}
static T_1
F_142 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_153 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_288 , V_202 = - 1 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_155 ;
if ( sscanf ( V_9 , L_94 , & V_288 ) != 1 )
return - V_155 ;
if ( V_288 != 1 )
return - V_155 ;
if ( V_18 -> V_19 & V_428 )
V_202 = F_143 ( V_18 -> V_227 ) ;
if ( V_202 == 0 )
return strlen ( V_9 ) ;
else
return - V_166 ;
}
static T_1
F_144 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_153 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_225 * V_226 = V_18 -> V_227 ;
int V_288 = 0 , V_202 = - V_155 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_155 ;
if ( sscanf ( V_9 , L_94 , & V_288 ) != 1 )
return - V_155 ;
if ( V_288 < 0 )
return - V_155 ;
if ( V_288 == 0 ) {
if ( V_18 -> V_236 > 0 ) {
F_54 ( V_226 ) ;
V_18 -> V_236 = 0 ;
}
return strlen ( V_9 ) ;
}
if ( V_18 -> V_236 > 0 ) {
F_38 ( V_18 , V_183 , V_193 ,
L_167
L_168 ,
V_18 -> V_236 ) ;
return - V_430 ;
}
if ( V_288 <= V_431 )
V_18 -> V_236 = V_288 ;
else {
F_38 ( V_18 , V_183 , V_193 ,
L_169
L_170 , V_288 ) ;
return - V_155 ;
}
V_202 = F_57 ( V_18 , V_18 -> V_236 ) ;
if ( V_202 ) {
V_18 -> V_236 = 0 ;
V_202 = - V_166 ;
} else
V_202 = strlen ( V_9 ) ;
return V_202 ;
}
static T_1
F_145 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 , T_5 V_153 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_288 = 0 , V_202 = - V_155 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_155 ;
if ( sscanf ( V_9 , L_94 , & V_288 ) != 1 )
return - V_155 ;
if ( V_288 != 1 )
return - V_155 ;
V_202 = F_146 ( V_18 , V_432 ) ;
if ( V_202 )
V_202 = - V_166 ;
else
V_202 = strlen ( V_9 ) ;
return V_202 ;
}
static int
F_147 ( struct V_17 * V_18 , int V_288 )
{
if ( V_288 >= 0 && V_288 <= 1 ) {
V_18 -> V_433 = V_288 ;
return 0 ;
}
return - V_155 ;
}
static T_1
F_148 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_153 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_288 = 0 , V_3 ;
if ( V_18 -> V_112 != V_113 )
return - V_155 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_155 ;
if ( sscanf ( V_9 , L_94 , & V_288 ) != 1 )
return - V_155 ;
if ( V_288 && ( V_288 < V_434 || V_288 > V_435 ) )
return - V_155 ;
V_18 -> V_436 = ( T_2 ) V_288 ;
for ( V_3 = 0 ; V_3 < V_18 -> V_437 ; V_3 += V_438 )
F_149 ( V_18 , V_3 ) ;
return strlen ( V_9 ) ;
}
static int
F_150 ( struct V_17 * V_18 , int V_288 )
{
if ( V_18 -> V_112 != V_113 ) {
V_18 -> V_436 = 0 ;
return 0 ;
}
if ( ( V_288 >= V_434 && V_288 <= V_435 ) ||
( V_288 == 0 ) ) {
V_18 -> V_436 = V_288 ;
return 0 ;
}
F_38 ( V_18 , V_183 , V_193 ,
L_171 ,
V_288 ) ;
V_18 -> V_436 = V_439 ;
return 0 ;
}
static T_1
F_151 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_440 * V_441 ;
int V_32 = 0 ;
if ( ( V_18 -> V_112 != V_113 ) ||
( V_18 -> V_442 != V_443 ) )
return V_32 ;
switch ( V_18 -> V_444 ) {
case 0 :
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_172 ,
V_18 -> V_444 ) ;
return V_32 ;
case 1 :
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_173
L_174 ,
V_18 -> V_444 ,
V_18 -> V_70 . V_445 ) ;
break;
case 2 :
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_175
L_174 ,
V_18 -> V_444 ,
V_18 -> V_70 . V_445 ) ;
break;
}
while ( V_18 -> V_70 . V_446 < V_18 -> V_70 . V_447 ) {
V_441 = & V_18 -> V_70 . V_448 [ V_18 -> V_70 . V_446 ] ;
if ( V_441 -> V_449 == V_450 )
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_176
L_177 ,
V_18 -> V_70 . V_446 ,
V_441 -> V_451 , V_441 -> V_452 ,
V_441 -> V_453 ) ;
else
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 ,
L_176
L_178 ,
V_18 -> V_70 . V_446 ,
V_441 -> V_451 , V_441 -> V_452 ,
V_441 -> V_453 , V_441 -> V_449 ) ;
V_18 -> V_70 . V_446 ++ ;
if ( V_18 -> V_70 . V_446 <
V_18 -> V_70 . V_447 &&
( V_32 >= ( V_10 - 64 ) ) ) {
V_32 += snprintf ( V_9 + V_32 , V_10 - V_32 , L_179 ) ;
break;
}
}
if ( V_18 -> V_70 . V_446 == V_18 -> V_70 . V_447 )
V_18 -> V_70 . V_446 = 0 ;
return V_32 ;
}
static T_1
F_152 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_153 )
{
int V_154 = - V_155 ;
return V_154 ;
}
static int
F_153 ( struct V_17 * V_18 , int V_288 )
{
if ( V_18 -> V_112 != V_113 ) {
V_18 -> V_444 = 0 ;
return 0 ;
}
if ( V_288 >= V_454 && V_288 <= V_455 ) {
V_18 -> V_444 = V_288 ;
return 0 ;
}
F_38 ( V_18 , V_183 , V_193 ,
L_180
L_181 , V_288 ) ;
V_18 -> V_444 = V_456 ;
return 0 ;
}
static int
F_154 ( struct V_14 * V_15 , int V_288 )
{
struct V_12 * V_13 = F_116 ( V_15 ) ;
struct V_360 * V_361 , * V_457 ;
if ( V_288 == V_15 -> V_458 )
return 0 ;
if ( ( V_288 < 0 ) || ( V_288 > 60000 ) )
return - V_155 ;
V_15 -> V_458 = V_288 ;
F_9 ( V_13 -> V_74 ) ;
F_155 (ndlp, next_ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_117 ( V_361 ) )
continue;
if ( V_361 -> V_459 == V_460 )
continue;
V_361 -> V_461 = V_15 -> V_462 ;
}
F_11 ( V_13 -> V_74 ) ;
return 0 ;
}
static T_1
F_156 ( struct V_397 * V_398 , struct V_399 * V_400 ,
struct V_401 * V_402 ,
char * V_9 , T_14 V_403 , T_5 V_153 )
{
T_5 V_463 ;
struct V_5 * V_6 = F_136 ( V_400 , struct V_5 , V_400 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_112 >= V_113 )
return - V_166 ;
if ( ( V_403 + V_153 ) > V_464 )
return - V_465 ;
if ( V_153 <= V_466 )
return 0 ;
if ( V_403 % 4 || V_153 % 4 || ( unsigned long ) V_9 % 4 )
return - V_155 ;
if ( memcmp ( V_9 , V_467 , V_466 ) )
return - V_155 ;
if ( ! ( V_15 -> V_143 & V_164 ) )
return - V_166 ;
F_9 ( & V_18 -> V_207 ) ;
for ( V_463 = 0 ; V_463 < V_153 - V_466 ;
V_463 += sizeof( T_2 ) )
F_56 ( * ( ( T_2 * ) ( V_9 + V_463 + V_466 ) ) ,
V_18 -> V_468 + V_403 + V_463 ) ;
F_11 ( & V_18 -> V_207 ) ;
return V_153 ;
}
static T_1
F_157 ( struct V_397 * V_398 , struct V_399 * V_400 ,
struct V_401 * V_402 ,
char * V_9 , T_14 V_403 , T_5 V_153 )
{
T_5 V_463 ;
T_2 * V_469 ;
struct V_5 * V_6 = F_136 ( V_400 , struct V_5 , V_400 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_112 >= V_113 )
return - V_166 ;
if ( V_403 > V_464 )
return - V_465 ;
if ( ( V_403 + V_153 ) > V_464 )
V_153 = V_464 - V_403 ;
if ( V_153 == 0 ) return 0 ;
if ( V_403 % 4 || V_153 % 4 || ( unsigned long ) V_9 % 4 )
return - V_155 ;
F_9 ( & V_18 -> V_207 ) ;
for ( V_463 = 0 ; V_463 < V_153 ; V_463 += sizeof( T_2 ) ) {
V_469 = ( T_2 * ) ( V_9 + V_463 ) ;
* V_469 = F_55 ( V_18 -> V_468 + V_403 + V_463 ) ;
}
F_11 ( & V_18 -> V_207 ) ;
return V_153 ;
}
static T_1
F_158 ( struct V_397 * V_398 , struct V_399 * V_400 ,
struct V_401 * V_402 ,
char * V_9 , T_14 V_403 , T_5 V_153 )
{
return - V_166 ;
}
static T_1
F_159 ( struct V_397 * V_398 , struct V_399 * V_400 ,
struct V_401 * V_402 ,
char * V_9 , T_14 V_403 , T_5 V_153 )
{
return - V_166 ;
}
int
F_160 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = F_116 ( V_15 ) ;
int error ;
error = F_161 ( & V_13 -> V_470 . V_400 ,
& V_471 ) ;
if ( error || V_15 -> V_282 == V_472 )
goto V_208;
error = F_161 ( & V_13 -> V_470 . V_400 ,
& V_473 ) ;
if ( error )
goto V_474;
error = F_161 ( & V_13 -> V_470 . V_400 ,
& V_475 ) ;
if ( error )
goto V_476;
return 0 ;
V_476:
F_162 ( & V_13 -> V_470 . V_400 , & V_473 ) ;
V_474:
F_162 ( & V_13 -> V_470 . V_400 ,
& V_471 ) ;
V_208:
return error ;
}
void
F_163 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = F_116 ( V_15 ) ;
F_162 ( & V_13 -> V_470 . V_400 ,
& V_471 ) ;
if ( V_15 -> V_282 == V_472 )
return;
F_162 ( & V_13 -> V_470 . V_400 , & V_475 ) ;
F_162 ( & V_13 -> V_470 . V_400 , & V_473 ) ;
}
static void
F_164 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
F_165 ( V_15 , F_166 ( V_13 ) ,
sizeof F_166 ( V_13 ) ) ;
}
static void
F_167 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
F_168 ( V_13 ) = V_15 -> V_477 ;
}
static void
F_169 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_9 ( V_13 -> V_74 ) ;
if ( V_15 -> V_282 == V_472 ) {
F_170 ( V_13 ) = V_478 ;
} else if ( F_171 ( V_18 ) ) {
if ( V_18 -> V_141 == V_142 ) {
if ( V_15 -> V_143 & V_144 )
F_170 ( V_13 ) = V_479 ;
else
F_170 ( V_13 ) = V_480 ;
} else {
if ( V_15 -> V_143 & V_145 )
F_170 ( V_13 ) = V_481 ;
else
F_170 ( V_13 ) = V_482 ;
}
} else
F_170 ( V_13 ) = V_483 ;
F_11 ( V_13 -> V_74 ) ;
}
static void
F_172 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_9 ( V_13 -> V_74 ) ;
if ( V_15 -> V_143 & V_164 )
F_173 ( V_13 ) = V_484 ;
else {
switch ( V_18 -> V_119 ) {
case V_120 :
case V_124 :
F_173 ( V_13 ) = V_485 ;
break;
case V_127 :
case V_128 :
case V_129 :
if ( V_15 -> V_76 < V_138 )
F_173 ( V_13 ) =
V_486 ;
else
F_173 ( V_13 ) =
V_487 ;
break;
case V_125 :
F_173 ( V_13 ) = V_488 ;
break;
default:
F_173 ( V_13 ) = V_489 ;
break;
}
}
F_11 ( V_13 -> V_74 ) ;
}
static void
F_174 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_9 ( V_13 -> V_74 ) ;
if ( ( F_171 ( V_18 ) ) && ( ! ( V_18 -> V_19 & V_490 ) ) ) {
switch( V_18 -> V_491 ) {
case V_492 :
F_175 ( V_13 ) = V_493 ;
break;
case V_494 :
F_175 ( V_13 ) = V_495 ;
break;
case V_496 :
F_175 ( V_13 ) = V_497 ;
break;
case V_498 :
F_175 ( V_13 ) = V_499 ;
break;
case V_500 :
F_175 ( V_13 ) = V_501 ;
break;
case V_502 :
F_175 ( V_13 ) = V_503 ;
break;
case V_504 :
F_175 ( V_13 ) = V_505 ;
break;
default:
F_175 ( V_13 ) = V_506 ;
break;
}
} else
F_175 ( V_13 ) = V_506 ;
F_11 ( V_13 -> V_74 ) ;
}
static void
F_176 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_15 V_80 ;
F_9 ( V_13 -> V_74 ) ;
if ( ( V_15 -> V_76 > V_132 ) &&
( ( V_15 -> V_143 & V_145 ) ||
( ( V_18 -> V_141 == V_142 ) &&
( V_15 -> V_143 & V_144 ) ) ) )
V_80 = F_7 ( V_18 -> V_507 . V_508 . V_38 . V_39 ) ;
else
V_80 = 0 ;
F_11 ( V_13 -> V_74 ) ;
F_177 ( V_13 ) = V_80 ;
}
static struct V_509 *
F_178 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_200 * V_201 = & V_18 -> V_103 ;
struct V_509 * V_510 = & V_18 -> V_511 ;
struct V_512 * V_513 = & V_201 -> V_514 ;
T_6 * V_161 ;
T_8 * V_260 ;
unsigned long V_515 ;
int V_202 = 0 ;
if ( V_18 -> V_119 < V_124 ||
! V_18 -> V_167 ||
( V_18 -> V_103 . V_104 & V_262 ) == 0 )
return NULL ;
if ( V_18 -> V_103 . V_104 & V_165 )
return NULL ;
V_161 = F_35 ( V_18 -> V_167 , V_168 ) ;
if ( ! V_161 )
return NULL ;
memset ( V_161 , 0 , sizeof ( T_6 ) ) ;
V_260 = & V_161 -> V_38 . V_170 ;
V_260 -> V_171 = V_516 ;
V_260 -> V_173 = V_174 ;
V_161 -> V_264 = NULL ;
V_161 -> V_15 = V_15 ;
if ( V_15 -> V_143 & V_164 )
V_202 = F_179 ( V_18 , V_161 , V_517 ) ;
else
V_202 = F_36 ( V_18 , V_161 , V_18 -> V_181 * 2 ) ;
if ( V_202 != V_176 ) {
if ( V_202 != V_186 )
F_40 ( V_161 , V_18 -> V_167 ) ;
return NULL ;
}
memset ( V_510 , 0 , sizeof ( struct V_509 ) ) ;
V_510 -> V_518 = V_260 -> V_267 . V_519 . V_520 ;
V_510 -> V_521 = ( T_13 )
( ( T_13 ) V_260 -> V_267 . V_519 . V_522
* ( T_13 ) 256 ) ;
V_510 -> V_523 = V_260 -> V_267 . V_519 . V_524 ;
V_510 -> V_525 = ( T_13 )
( ( T_13 ) V_260 -> V_267 . V_519 . V_526
* ( T_13 ) 256 ) ;
memset ( V_161 , 0 , sizeof ( T_6 ) ) ;
V_260 -> V_171 = V_527 ;
V_260 -> V_173 = V_174 ;
V_161 -> V_264 = NULL ;
V_161 -> V_15 = V_15 ;
if ( V_15 -> V_143 & V_164 )
V_202 = F_179 ( V_18 , V_161 , V_517 ) ;
else
V_202 = F_36 ( V_18 , V_161 , V_18 -> V_181 * 2 ) ;
if ( V_202 != V_176 ) {
if ( V_202 != V_186 )
F_40 ( V_161 , V_18 -> V_167 ) ;
return NULL ;
}
V_510 -> V_528 = V_260 -> V_267 . V_529 . V_530 ;
V_510 -> V_531 = V_260 -> V_267 . V_529 . V_532 ;
V_510 -> V_533 = V_260 -> V_267 . V_529 . V_534 ;
V_510 -> V_535 = V_260 -> V_267 . V_529 . V_536 ;
V_510 -> V_537 = V_260 -> V_267 . V_529 . V_538 ;
V_510 -> V_539 = V_260 -> V_267 . V_529 . V_540 ;
V_510 -> V_541 = V_260 -> V_267 . V_529 . V_540 ;
V_510 -> V_528 -= V_513 -> V_528 ;
V_510 -> V_531 -= V_513 -> V_531 ;
V_510 -> V_533 -= V_513 -> V_533 ;
V_510 -> V_535 -= V_513 -> V_535 ;
V_510 -> V_537 -= V_513 -> V_537 ;
V_510 -> V_539 -= V_513 -> V_539 ;
V_510 -> V_541 -= V_513 -> V_541 ;
if ( V_18 -> V_19 & V_490 ) {
V_510 -> V_542 = - 1 ;
V_510 -> V_543 = ( V_18 -> V_544 >> 1 ) ;
V_510 -> V_543 -= V_513 -> V_544 ;
} else if ( V_18 -> V_141 == V_142 ) {
V_510 -> V_542 = ( V_18 -> V_545 >> 1 ) ;
V_510 -> V_542 -= V_513 -> V_544 ;
V_510 -> V_543 = - 1 ;
} else {
V_510 -> V_542 = - 1 ;
V_510 -> V_543 = ( V_18 -> V_545 >> 1 ) ;
V_510 -> V_543 -= V_513 -> V_544 ;
}
V_510 -> V_546 = - 1 ;
V_515 = F_180 () ;
if ( V_515 < V_201 -> V_547 )
V_510 -> V_548 = V_515 +
( ( unsigned long ) - 1 - V_201 -> V_547 ) ;
else
V_510 -> V_548 = V_515 - V_201 -> V_547 ;
F_40 ( V_161 , V_18 -> V_167 ) ;
return V_510 ;
}
static void
F_181 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_200 * V_201 = & V_18 -> V_103 ;
struct V_512 * V_513 = & V_201 -> V_514 ;
T_6 * V_161 ;
T_8 * V_260 ;
int V_202 = 0 ;
if ( V_18 -> V_103 . V_104 & V_165 )
return;
V_161 = F_35 ( V_18 -> V_167 , V_168 ) ;
if ( ! V_161 )
return;
memset ( V_161 , 0 , sizeof( T_6 ) ) ;
V_260 = & V_161 -> V_38 . V_170 ;
V_260 -> V_171 = V_516 ;
V_260 -> V_173 = V_174 ;
V_260 -> V_267 . V_549 [ 0 ] = 0x1 ;
V_161 -> V_264 = NULL ;
V_161 -> V_15 = V_15 ;
if ( ( V_15 -> V_143 & V_164 ) ||
( ! ( V_201 -> V_104 & V_262 ) ) )
V_202 = F_179 ( V_18 , V_161 , V_517 ) ;
else
V_202 = F_36 ( V_18 , V_161 , V_18 -> V_181 * 2 ) ;
if ( V_202 != V_176 ) {
if ( V_202 != V_186 )
F_40 ( V_161 , V_18 -> V_167 ) ;
return;
}
memset ( V_161 , 0 , sizeof( T_6 ) ) ;
V_260 -> V_171 = V_527 ;
V_260 -> V_173 = V_174 ;
V_161 -> V_264 = NULL ;
V_161 -> V_15 = V_15 ;
if ( ( V_15 -> V_143 & V_164 ) ||
( ! ( V_201 -> V_104 & V_262 ) ) )
V_202 = F_179 ( V_18 , V_161 , V_517 ) ;
else
V_202 = F_36 ( V_18 , V_161 , V_18 -> V_181 * 2 ) ;
if ( V_202 != V_176 ) {
if ( V_202 != V_186 )
F_40 ( V_161 , V_18 -> V_167 ) ;
return;
}
V_513 -> V_528 = V_260 -> V_267 . V_529 . V_530 ;
V_513 -> V_531 = V_260 -> V_267 . V_529 . V_532 ;
V_513 -> V_533 = V_260 -> V_267 . V_529 . V_534 ;
V_513 -> V_535 = V_260 -> V_267 . V_529 . V_536 ;
V_513 -> V_537 = V_260 -> V_267 . V_529 . V_538 ;
V_513 -> V_539 = V_260 -> V_267 . V_529 . V_540 ;
V_513 -> V_541 = V_260 -> V_267 . V_529 . V_540 ;
if ( V_18 -> V_19 & V_490 )
V_513 -> V_544 = ( V_18 -> V_544 >> 1 ) ;
else
V_513 -> V_544 = ( V_18 -> V_545 >> 1 ) ;
V_201 -> V_547 = F_180 () ;
F_40 ( V_161 , V_18 -> V_167 ) ;
return;
}
static struct V_360 *
F_182 ( struct V_550 * V_551 )
{
struct V_12 * V_13 = F_183 ( V_551 -> V_6 . V_552 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_360 * V_361 ;
F_9 ( V_13 -> V_74 ) ;
F_10 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( F_117 ( V_361 ) &&
V_361 -> V_459 == V_553 &&
V_551 -> V_554 == V_361 -> V_555 ) {
F_11 ( V_13 -> V_74 ) ;
return V_361 ;
}
}
F_11 ( V_13 -> V_74 ) ;
return NULL ;
}
static void
F_184 ( struct V_550 * V_551 )
{
struct V_360 * V_361 = F_182 ( V_551 ) ;
F_185 ( V_551 ) = V_361 ? V_361 -> V_556 : - 1 ;
}
static void
F_186 ( struct V_550 * V_551 )
{
struct V_360 * V_361 = F_182 ( V_551 ) ;
F_187 ( V_551 ) =
V_361 ? F_7 ( V_361 -> V_557 . V_38 . V_39 ) : 0 ;
}
static void
F_188 ( struct V_550 * V_551 )
{
struct V_360 * V_361 = F_182 ( V_551 ) ;
F_189 ( V_551 ) =
V_361 ? F_7 ( V_361 -> V_407 . V_38 . V_39 ) : 0 ;
}
static void
F_190 ( struct V_558 * V_28 , T_2 V_559 )
{
if ( V_559 )
V_28 -> V_362 = V_559 ;
else
V_28 -> V_362 = 1 ;
}
static void
F_191 ( struct V_560 * V_560 )
{
struct V_14 * V_15 = * (struct V_14 * * ) V_560 -> V_561 ;
if ( V_15 -> V_76 == V_138 )
F_192 ( V_15 , V_562 , 0 , 0 ) ;
}
static void
F_193 ( struct V_17 * V_18 , T_2 V_563 )
{
V_18 -> V_564 = V_563 ;
}
void
F_194 ( struct V_17 * V_18 )
{
F_195 ( V_18 , V_565 ) ;
F_196 ( V_18 , V_566 ) ;
F_197 ( V_18 , V_567 ) ;
F_198 ( V_18 , V_568 ) ;
F_199 ( V_18 , V_569 ) ;
F_200 ( V_18 , V_570 ) ;
F_201 ( V_18 , V_571 ) ;
F_202 ( V_18 , V_572 ) ;
F_203 ( V_18 , V_573 ) ;
F_138 ( V_18 , V_574 ) ;
F_204 ( V_18 , V_575 ) ;
F_205 ( V_18 , V_576 ) ;
F_206 ( V_18 , V_577 ) ;
F_207 ( V_18 , V_578 ) ;
F_208 ( V_18 , V_579 ) ;
F_209 ( V_18 , V_580 ) ;
F_210 ( V_18 , V_581 ) ;
F_211 ( V_18 , V_582 ) ;
F_212 ( V_18 , V_583 ) ;
F_150 ( V_18 , V_584 ) ;
F_153 ( V_18 , V_585 ) ;
F_213 ( V_18 , V_586 ) ;
F_214 ( V_18 , V_587 ) ;
F_215 ( V_18 , V_588 ) ;
if ( V_18 -> V_112 != V_113 )
V_18 -> V_589 = 0 ;
F_216 ( V_18 , V_590 ) ;
memset ( V_18 -> V_322 , 0 , ( 8 * sizeof( T_3 ) ) ) ;
memset ( V_18 -> V_333 , 0 , ( 8 * sizeof( T_3 ) ) ) ;
V_18 -> V_336 = 0 ;
V_18 -> V_338 = 0 ;
V_18 -> V_325 = 0 ;
V_18 -> V_330 = 0 ;
F_217 ( V_18 , V_591 ) ;
F_218 ( V_18 , V_592 ) ;
F_219 ( V_18 , V_593 ) ;
if ( V_18 -> V_112 == V_113 )
V_18 -> V_285 = 0 ;
else
V_18 -> V_285 = V_594 ;
F_220 ( V_18 , V_595 ) ;
F_221 ( V_18 , V_596 ) ;
F_222 ( V_18 , V_597 ) ;
F_223 ( V_18 , V_598 ) ;
F_224 ( V_18 , V_599 ) ;
F_225 ( V_18 , V_600 ) ;
F_226 ( V_18 , V_601 ) ;
if ( V_18 -> V_112 != V_113 ) {
V_18 -> V_35 = 0 ;
V_18 -> V_33 = V_602 ;
} else {
if ( ! ( V_18 -> V_33 & V_602 ) )
V_18 -> V_33 |= V_602 ;
}
if ( V_18 -> V_603 == 0 )
V_18 -> V_603 = V_18 -> V_70 . V_447 ;
if ( V_18 -> V_604 == 0 )
V_18 -> V_604 = V_18 -> V_70 . V_447 ;
if ( V_18 -> V_33 == V_34 )
V_18 -> V_603 = 0 ;
if ( V_18 -> V_33 == V_602 )
V_18 -> V_604 = 0 ;
if ( V_18 -> V_603 > V_18 -> V_604 )
V_18 -> V_437 = V_18 -> V_603 ;
else
V_18 -> V_437 = V_18 -> V_604 ;
V_18 -> V_319 = 0L ;
V_18 -> V_313 = 0L ;
F_227 ( V_18 , V_605 ) ;
F_228 ( V_18 , V_606 ) ;
F_229 ( V_18 , V_607 ) ;
F_193 ( V_18 , V_608 ) ;
F_230 ( V_18 , V_609 ) ;
F_231 ( V_18 , V_610 ) ;
F_147 ( V_18 , V_611 ) ;
F_232 ( V_18 , V_612 ) ;
F_233 ( V_18 , V_613 ) ;
F_234 ( V_18 , V_614 ) ;
F_235 ( V_18 , V_615 ) ;
V_18 -> V_297 = 1 ;
F_236 ( V_18 , V_616 ) ;
return;
}
void
F_237 ( struct V_17 * V_18 )
{
if ( V_18 -> V_604 > V_18 -> V_70 . V_447 )
V_18 -> V_604 = V_18 -> V_70 . V_447 ;
if ( V_18 -> V_603 > V_18 -> V_70 . V_447 )
V_18 -> V_603 = V_18 -> V_70 . V_447 ;
if ( V_18 -> V_33 & V_34 &&
V_18 -> V_35 ) {
V_18 -> V_33 &= ~ V_602 ;
V_18 -> V_603 = 0 ;
F_38 ( V_18 , V_351 , V_617 ,
L_182 ,
L_183 ,
V_18 -> V_618 ,
V_18 -> V_619 ,
V_620 ) ;
if ( V_18 -> V_618 == 0 )
V_18 -> V_619 = 0 ;
else {
if ( V_18 -> V_619 > V_620 )
V_18 -> V_619 = V_620 ;
}
if ( V_18 -> V_621 > V_18 -> V_604 ) {
V_18 -> V_621 = V_18 -> V_604 ;
F_38 ( V_18 , V_183 , V_617 ,
L_184 ,
V_18 -> V_621 ) ;
}
} else {
V_18 -> V_35 = 0 ;
V_18 -> V_621 = 0 ;
V_18 -> V_619 = 0 ;
}
if ( V_18 -> V_603 > V_18 -> V_604 )
V_18 -> V_437 = V_18 -> V_603 ;
else
V_18 -> V_437 = V_18 -> V_604 ;
}
void
F_238 ( struct V_14 * V_15 )
{
F_239 ( V_15 , V_608 ) ;
F_240 ( V_15 , V_622 ) ;
F_241 ( V_15 , V_623 ) ;
F_242 ( V_15 , V_364 ) ;
F_114 ( V_15 , V_624 ) ;
F_243 ( V_15 , V_625 ) ;
F_121 ( V_15 , V_626 ) ;
F_244 ( V_15 , V_627 ) ;
F_245 ( V_15 , V_628 ) ;
F_246 ( V_15 , V_629 ) ;
F_247 ( V_15 , V_630 ) ;
F_248 ( V_15 , V_631 ) ;
F_249 ( V_15 , V_632 ) ;
F_250 ( V_15 , V_633 ) ;
F_251 ( V_15 , V_634 ) ;
return;
}
