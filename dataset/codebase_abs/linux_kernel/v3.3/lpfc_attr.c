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
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_21 )
if ( V_18 -> V_22 & V_23 )
return snprintf ( V_9 , V_10 , L_4 ) ;
else
return snprintf ( V_9 , V_10 ,
L_5 ) ;
else
return snprintf ( V_9 , V_10 ,
L_6 ) ;
}
static T_1
F_6 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_7 ,
( unsigned long long ) V_18 -> V_24 ) ;
}
static T_1
F_7 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_7 ,
( unsigned long long ) V_18 -> V_25 ) ;
}
static T_1
F_8 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_7 ,
( unsigned long long ) V_18 -> V_26 ) ;
}
static T_1
F_9 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_27 = F_4 ( V_6 ) ;
return snprintf ( V_9 , V_10 , L_8 , F_10 ( V_27 ) ) ;
}
static T_1
F_11 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_8 , V_18 -> V_28 ) ;
}
static T_1
F_12 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_29 ) ;
}
static T_1
F_13 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_8 , V_18 -> V_30 ) ;
}
static T_1
F_14 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_8 , V_18 -> V_31 ) ;
}
static T_1
F_15 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_8 , V_18 -> V_32 ) ;
}
static T_1
F_16 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 ,
( V_18 -> V_33 . V_34 & V_35 ) ) ;
}
static T_1
F_17 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_8 , V_18 -> V_36 ) ;
}
static T_1
F_18 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_37 ;
T_3 V_38 ;
char V_39 [ 32 ] ;
int V_40 ;
F_19 ( V_18 , V_39 , 1 ) ;
V_37 = V_18 -> V_41 . V_42 . V_37 ;
V_38 = V_18 -> V_41 . V_42 . V_38 ;
if ( V_18 -> V_43 < V_44 )
V_40 = snprintf ( V_9 , V_10 , L_10 ,
V_39 , V_18 -> V_43 ) ;
else
V_40 = snprintf ( V_9 , V_10 , L_11 ,
V_39 , V_18 -> V_43 , V_37 , V_38 ) ;
return V_40 ;
}
static T_1
F_20 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
char V_2 [ 9 ] ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_4 * V_45 = & V_18 -> V_46 ;
F_1 ( V_45 -> V_47 . V_48 , V_2 ) ;
return snprintf ( V_9 , V_10 , L_8 , V_2 ) ;
}
static T_1
F_21 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_8 , V_18 -> V_49 ) ;
}
static T_1
F_22 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_40 = 0 ;
switch ( V_18 -> V_50 ) {
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
if ( V_18 -> V_19 & V_57 )
V_40 += snprintf ( V_9 + V_40 , V_10 - V_40 ,
L_12 ) ;
else
V_40 += snprintf ( V_9 + V_40 , V_10 - V_40 ,
L_13 ) ;
break;
case V_58 :
case V_59 :
case V_60 :
V_40 += snprintf ( V_9 + V_40 , V_10 - V_40 , L_14 ) ;
switch ( V_15 -> V_61 ) {
case V_62 :
V_40 += snprintf ( V_9 + V_40 , V_10 - V_40 ,
L_15 ) ;
break;
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
V_40 += snprintf ( V_9 + V_40 , V_10 - V_40 ,
L_16 ) ;
break;
case V_70 :
V_40 += snprintf ( V_9 + V_40 , V_10 - V_40 , L_17 ) ;
break;
case V_71 :
V_40 += snprintf ( V_9 + V_40 , V_10 - V_40 , L_18 ) ;
break;
case V_72 :
V_40 += snprintf ( V_9 + V_40 , V_10 - V_40 ,
L_19 ) ;
break;
}
if ( V_18 -> V_33 . V_34 & V_35 )
V_40 += snprintf ( V_9 + V_40 , V_10 - V_40 ,
L_20 ) ;
else if ( V_18 -> V_73 == V_74 ) {
if ( V_15 -> V_75 & V_76 )
V_40 += snprintf ( V_9 + V_40 , V_10 - V_40 ,
L_21 ) ;
else
V_40 += snprintf ( V_9 + V_40 , V_10 - V_40 ,
L_22 ) ;
} else {
if ( V_15 -> V_75 & V_77 )
V_40 += snprintf ( V_9 + V_40 , V_10 - V_40 ,
L_23 ) ;
else
V_40 += snprintf ( V_9 + V_40 , V_10 - V_40 ,
L_24 ) ;
}
}
return V_40 ;
}
static T_1
F_23 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_43 < V_44 )
return snprintf ( V_9 , V_10 , L_25 ) ;
if ( V_18 -> V_41 . V_78 . V_79 == V_80 ) {
if ( V_18 -> V_41 . V_78 . V_81 == V_82 )
return snprintf ( V_9 , V_10 , L_26 ) ;
if ( V_18 -> V_41 . V_78 . V_81 == V_83 )
return snprintf ( V_9 , V_10 , L_25 ) ;
}
return snprintf ( V_9 , V_10 , L_27 ) ;
}
static T_1
F_24 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_84 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_85 = - V_86 ;
if ( ( strncmp ( V_9 , L_28 , sizeof( L_28 ) - 1 ) == 0 ) &&
( V_18 -> V_50 == V_55 ) )
V_85 = V_18 -> V_87 ( V_18 , V_88 ) ;
else if ( ( strncmp ( V_9 , L_29 , sizeof( L_29 ) - 1 ) == 0 ) &&
( V_18 -> V_50 >= V_58 ) )
V_85 = V_18 -> V_89 ( V_18 , V_88 ) ;
if ( V_85 == 0 )
return strlen ( V_9 ) ;
else
return V_85 ;
}
static T_1
F_25 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
return snprintf ( V_9 , V_10 , L_9 ,
V_15 -> V_90 + V_15 -> V_91 ) ;
}
static int
F_26 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_6 * V_92 ;
int V_93 = V_94 ;
if ( ( V_15 -> V_75 & V_95 ) ||
( V_18 -> V_33 . V_34 & V_96 ) )
return - V_97 ;
V_92 = F_27 ( V_18 -> V_98 , V_99 ) ;
if ( ! V_92 )
return - V_100 ;
memset ( ( void * ) V_92 , 0 , sizeof ( T_6 ) ) ;
V_92 -> V_101 . V_102 . V_103 = V_104 ;
V_92 -> V_101 . V_102 . V_105 = V_106 ;
V_93 = F_28 ( V_18 , V_92 , V_107 * 2 ) ;
if ( ( V_93 == V_108 ) &&
( V_92 -> V_101 . V_102 . V_109 == 0 ||
V_92 -> V_101 . V_102 . V_109 == V_110 ) ) {
memset ( ( void * ) V_92 , 0 , sizeof ( T_6 ) ) ;
F_29 ( V_18 , V_92 , V_18 -> V_111 ,
V_18 -> V_112 ) ;
V_93 = F_28 ( V_18 , V_92 ,
V_18 -> V_113 * 2 ) ;
if ( ( V_93 == V_108 ) &&
( V_92 -> V_101 . V_102 . V_109 == V_114 ) )
F_30 ( V_18 , V_115 , V_116 | V_117 ,
L_30
L_31 ) ;
}
F_31 ( V_18 ) ;
if ( V_93 != V_118 )
F_32 ( V_92 , V_18 -> V_98 ) ;
if ( V_93 == V_94 )
return - V_119 ;
return 0 ;
}
static int
F_33 ( struct V_17 * V_18 , T_2 type )
{
struct V_120 V_121 ;
struct V_122 * V_123 ;
struct V_124 * V_125 ;
int V_85 = 0 ;
int V_126 = 0 ;
int V_3 ;
int V_127 ;
F_34 ( & V_121 ) ;
V_127 = F_35 ( V_18 , & V_85 , & V_121 ,
V_128 ) ;
if ( V_127 == 0 )
return - V_100 ;
F_36 ( & V_121 ) ;
if ( V_85 != 0 )
return - V_119 ;
V_125 = & V_18 -> V_33 ;
for ( V_3 = 0 ; V_3 < V_125 -> V_129 ; V_3 ++ ) {
V_123 = & V_125 -> V_130 [ V_3 ] ;
while ( V_123 -> V_131 ) {
F_37 ( 10 ) ;
if ( V_126 ++ > 500 ) {
F_30 ( V_18 ,
V_132 , V_133 ,
L_32
L_33 ) ;
break;
}
}
}
F_34 ( & V_121 ) ;
V_127 = F_35 ( V_18 , & V_85 , & V_121 , type ) ;
if ( V_127 == 0 )
return - V_100 ;
F_36 ( & V_121 ) ;
if ( V_85 != 0 )
return - V_119 ;
return 0 ;
}
int
F_38 ( struct V_17 * V_18 )
{
struct V_120 V_121 ;
int V_85 = 0 ;
int V_127 ;
if ( ! V_18 -> V_134 )
return - V_135 ;
V_85 = F_33 ( V_18 , V_136 ) ;
if ( V_85 != 0 )
return V_85 ;
F_34 ( & V_121 ) ;
V_127 = F_35 ( V_18 , & V_85 , & V_121 ,
V_137 ) ;
if ( V_127 == 0 )
return - V_100 ;
F_36 ( & V_121 ) ;
if ( V_85 != 0 )
return - V_119 ;
return 0 ;
}
static T_1
F_39 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_84 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_85 = - V_86 ;
if ( ! V_18 -> V_134 )
return - V_135 ;
if ( strncmp ( V_9 , L_34 , sizeof( L_34 ) - 1 ) == 0 )
V_85 = V_18 -> F_38 ( V_18 ) ;
if ( V_85 == 0 )
return strlen ( V_9 ) ;
else
return V_85 ;
}
int
F_40 ( struct V_17 * V_18 )
{
struct V_138 V_139 = { 0 } ;
int V_3 ;
F_37 ( 100 ) ;
F_41 ( V_18 -> V_41 . V_101 . V_140 . V_141 ,
& V_139 . V_142 ) ;
if ( ! F_42 ( V_143 , & V_139 ) &&
! F_42 ( V_144 , & V_139 ) )
return - V_97 ;
for ( V_3 = 0 ; V_3 < V_145 ; V_3 ++ ) {
F_37 ( 10 ) ;
F_41 ( V_18 -> V_41 . V_101 . V_140 . V_141 ,
& V_139 . V_142 ) ;
if ( ! F_42 ( V_144 , & V_139 ) )
continue;
if ( ! F_42 ( V_143 , & V_139 ) )
continue;
if ( ! F_42 ( V_146 , & V_139 ) )
continue;
break;
}
if ( V_3 < V_145 )
return 0 ;
else
return - V_119 ;
}
static T_1
F_43 ( struct V_17 * V_18 , T_2 V_147 )
{
struct V_120 V_121 ;
struct V_148 * V_149 = V_18 -> V_150 ;
T_2 V_151 ;
T_2 V_152 ;
T_2 V_153 ;
int V_85 = 0 , V_127 = 0 ;
int V_154 = 1 , V_155 ;
if ( ! V_18 -> V_134 )
return - V_135 ;
if ( ( V_18 -> V_43 < V_44 ) ||
( F_42 ( V_156 , & V_18 -> V_41 . V_157 ) !=
V_158 ) )
return - V_97 ;
V_151 = V_18 -> V_159 -> V_75 ;
V_152 = V_18 -> V_160 ;
if ( V_18 -> V_160 ) {
F_44 ( V_149 ) ;
V_18 -> V_160 = 0 ;
}
V_85 = F_33 ( V_18 , V_136 ) ;
if ( V_85 != 0 )
return V_85 ;
F_37 ( 100 ) ;
V_153 = F_45 ( V_18 -> V_41 . V_161 +
V_162 ) ;
if ( V_147 == V_163 )
V_153 |= V_164 ;
else if ( V_147 == V_165 )
V_153 |= V_166 ;
else if ( V_147 == V_167 )
V_153 |= V_168 ;
F_46 ( V_153 , V_18 -> V_41 . V_161 +
V_162 ) ;
F_45 ( V_18 -> V_41 . V_161 + V_162 ) ;
V_127 = F_40 ( V_18 ) ;
if ( V_127 == - V_97 ) {
if ( V_151 & V_95 )
goto V_169;
} else if ( V_127 == - V_119 ) {
return V_127 ;
}
if ( V_151 & V_95 )
goto V_169;
F_34 ( & V_121 ) ;
V_154 = F_35 ( V_18 , & V_85 , & V_121 ,
V_137 ) ;
if ( ! V_154 )
goto V_169;
F_36 ( & V_121 ) ;
V_169:
if ( V_152 ) {
V_155 =
F_47 ( V_18 , V_152 ) ;
if ( ! V_155 )
V_18 -> V_160 = V_152 ;
}
if ( ! V_127 ) {
if ( ! V_154 )
V_127 = - V_100 ;
else if ( V_85 )
V_127 = - V_119 ;
}
return V_127 ;
}
static T_1
F_48 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_170 ) ;
}
static T_1
F_49 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
char * V_171 ;
if ( V_18 -> V_50 == V_56 )
V_171 = L_35 ;
else if ( V_18 -> V_50 == V_52 )
V_171 = L_36 ;
else if ( V_18 -> V_50 == V_53 )
V_171 = L_37 ;
else
V_171 = L_38 ;
return snprintf ( V_9 , V_10 , L_8 , V_171 ) ;
}
static T_1
F_50 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_84 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_120 V_121 ;
char * V_172 = NULL ;
int V_85 = 0 ;
int V_127 ;
if ( ! V_18 -> V_134 ) {
V_85 = - V_135 ;
goto V_173;
}
F_51 ( V_15 , V_115 , V_133 ,
L_39 , V_9 ) ;
F_34 ( & V_121 ) ;
if( strncmp ( V_9 , L_38 , sizeof( L_38 ) - 1 ) == 0 ) {
V_127 = F_35 ( V_18 , & V_85 , & V_121 ,
V_137 ) ;
if ( V_127 == 0 ) {
V_85 = - V_100 ;
goto V_173;
}
F_36 ( & V_121 ) ;
} else if ( strncmp ( V_9 , L_37 , sizeof( L_37 ) - 1 ) == 0 )
V_85 = F_33 ( V_18 , V_136 ) ;
else if ( strncmp ( V_9 , L_40 , sizeof( L_40 ) - 1 ) == 0 )
if ( V_18 -> V_43 == V_44 )
V_85 = - V_86 ;
else
V_85 = F_33 ( V_18 , V_174 ) ;
else if ( strncmp ( V_9 , L_35 , sizeof( L_35 ) - 1 ) == 0 )
if ( V_18 -> V_43 == V_44 )
V_85 = - V_86 ;
else
V_85 = F_33 ( V_18 , V_175 ) ;
else if ( strncmp ( V_9 , L_41 , sizeof( L_41 ) - 1 ) == 0 )
V_85 = F_43 ( V_18 , V_163 ) ;
else if ( strncmp ( V_9 , L_42 , sizeof( L_42 ) - 1 ) == 0 )
V_85 = F_43 ( V_18 , V_165 ) ;
else if ( strncmp ( V_9 , L_43 , sizeof( L_43 ) - 1 ) == 0 )
V_85 = F_43 ( V_18 , V_167 ) ;
else
V_85 = - V_86 ;
V_173:
if ( ! V_85 )
return strlen ( V_9 ) ;
else {
V_172 = strchr ( V_9 , '\n' ) ;
if ( V_172 )
* V_172 = '\0' ;
F_51 ( V_15 , V_115 , V_133 ,
L_44
L_45 ,
V_9 , V_85 , V_18 -> V_159 -> V_75 ) ;
return V_85 ;
}
}
static int
F_52 ( struct V_17 * V_18 ,
T_2 * V_176 , T_2 * V_177 ,
T_2 * V_178 , T_2 * V_179 ,
T_2 * V_180 , T_2 * V_181 )
{
struct V_182 * V_183 ;
T_6 * V_92 ;
T_7 * V_184 ;
int V_127 = 0 ;
T_2 V_185 ;
if ( V_18 -> V_50 < V_55 ||
! V_18 -> V_98 ||
( V_18 -> V_33 . V_34 & V_186 ) == 0 )
return 0 ;
if ( V_18 -> V_33 . V_34 & V_96 )
return 0 ;
V_92 = F_27 ( V_18 -> V_98 , V_99 ) ;
if ( ! V_92 )
return 0 ;
memset ( V_92 , 0 , sizeof ( T_6 ) ) ;
V_184 = & V_92 -> V_101 . V_102 ;
V_184 -> V_103 = V_187 ;
V_184 -> V_105 = V_106 ;
V_92 -> V_188 = NULL ;
if ( V_18 -> V_159 -> V_75 & V_95 )
V_127 = V_189 ;
else
V_127 = F_28 ( V_18 , V_92 , V_18 -> V_113 * 2 ) ;
if ( V_127 != V_108 ) {
if ( V_127 != V_118 )
F_32 ( V_92 , V_18 -> V_98 ) ;
return 0 ;
}
if ( V_18 -> V_43 == V_44 ) {
V_183 = & V_92 -> V_101 . V_190 . V_191 . V_183 ;
if ( V_178 )
* V_178 = F_42 ( V_192 , V_183 ) ;
if ( V_179 )
* V_179 = F_42 ( V_192 , V_183 ) -
V_18 -> V_41 . V_193 . V_194 ;
if ( V_176 )
* V_176 = F_42 ( V_195 , V_183 ) ;
if ( V_177 )
* V_177 = F_42 ( V_195 , V_183 ) -
V_18 -> V_41 . V_193 . V_196 ;
V_185 = ( F_42 ( V_197 , V_183 ) > 0 ) ?
( F_42 ( V_197 , V_183 ) - 1 ) : 0 ;
if ( V_180 )
* V_180 = V_185 ;
if ( V_181 )
* V_181 = V_185 - V_18 -> V_41 . V_193 . V_198 ;
} else {
if ( V_178 )
* V_178 = V_184 -> V_191 . V_199 . V_200 ;
if ( V_179 )
* V_179 = V_184 -> V_191 . V_199 . V_201 ;
if ( V_176 )
* V_176 = V_184 -> V_191 . V_199 . V_202 ;
if ( V_177 )
* V_177 = V_184 -> V_191 . V_199 . V_203 ;
if ( V_180 )
* V_180 = V_184 -> V_191 . V_199 . V_185 ;
if ( V_181 )
* V_181 = V_184 -> V_191 . V_199 . V_204 ;
}
F_32 ( V_92 , V_18 -> V_98 ) ;
return 1 ;
}
static T_1
F_53 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_126 ;
if ( F_52 ( V_18 , NULL , NULL , & V_126 , NULL , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_9 , V_126 ) ;
return snprintf ( V_9 , V_10 , L_19 ) ;
}
static T_1
F_54 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_126 , V_205 ;
if ( F_52 ( V_18 , NULL , NULL , & V_126 , & V_205 , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_9 , ( V_126 - V_205 ) ) ;
return snprintf ( V_9 , V_10 , L_19 ) ;
}
static T_1
F_55 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_126 ;
if ( F_52 ( V_18 , & V_126 , NULL , NULL , NULL , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_9 , V_126 ) ;
return snprintf ( V_9 , V_10 , L_19 ) ;
}
static T_1
F_56 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_126 , V_205 ;
if ( F_52 ( V_18 , & V_126 , & V_205 , NULL , NULL , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_9 , ( V_126 - V_205 ) ) ;
return snprintf ( V_9 , V_10 , L_19 ) ;
}
static T_1
F_57 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_126 ;
if ( F_52 ( V_18 , NULL , NULL , NULL , NULL , & V_126 , NULL ) )
return snprintf ( V_9 , V_10 , L_9 , V_126 ) ;
return snprintf ( V_9 , V_10 , L_19 ) ;
}
static T_1
F_58 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_126 , V_205 ;
if ( F_52 ( V_18 , NULL , NULL , NULL , NULL , & V_126 , & V_205 ) )
return snprintf ( V_9 , V_10 , L_9 , ( V_126 - V_205 ) ) ;
return snprintf ( V_9 , V_10 , L_19 ) ;
}
static T_1
F_59 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( ! ( V_18 -> V_185 ) )
return snprintf ( V_9 , V_10 , L_46 ) ;
if ( V_15 -> V_206 == V_207 )
return snprintf ( V_9 , V_10 , L_47 ) ;
return snprintf ( V_9 , V_10 , L_48 , V_15 -> V_208 ) ;
}
static T_1
F_60 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_49 , V_18 -> V_209 ) ;
}
static T_1
F_61 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_84 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_210 ;
T_2 V_211 ;
int V_212 = 0 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_86 ;
if ( sscanf ( V_9 , L_50 , & V_212 ) != 1 )
return - V_86 ;
if ( ( V_212 & 0x3 ) != V_212 )
return - V_86 ;
if ( V_18 -> V_43 == V_44 )
V_212 = 0 ;
F_51 ( V_15 , V_115 , V_133 ,
L_51 ,
V_18 -> V_209 , V_212 ) ;
F_62 ( & V_18 -> V_213 ) ;
V_211 = V_18 -> V_209 ;
if ( V_212 & V_214 ) {
if ( ( V_212 & V_215 ) &&
! ( V_211 & V_215 ) ) {
if ( F_41 ( V_18 -> V_216 , & V_210 ) ) {
F_63 ( & V_18 -> V_213 ) ;
return - V_86 ;
}
V_210 &= ~ ( V_217 << V_218 ) ;
F_46 ( V_210 , V_18 -> V_216 ) ;
F_45 ( V_18 -> V_216 ) ;
F_64 ( V_18 ) ;
}
} else if ( V_212 != 0x0 ) {
F_63 ( & V_18 -> V_213 ) ;
return - V_86 ;
}
if ( ! ( V_212 & V_215 ) &&
( V_211 & V_215 ) )
{
F_63 ( & V_18 -> V_213 ) ;
F_65 ( & V_18 -> V_219 ) ;
F_62 ( & V_18 -> V_213 ) ;
if ( F_41 ( V_18 -> V_216 , & V_210 ) ) {
F_63 ( & V_18 -> V_213 ) ;
return - V_86 ;
}
V_210 |= ( V_217 << V_218 ) ;
F_46 ( V_210 , V_18 -> V_216 ) ;
F_45 ( V_18 -> V_216 ) ;
}
V_18 -> V_209 = V_212 ;
F_63 ( & V_18 -> V_213 ) ;
return strlen ( V_9 ) ;
}
static T_1
F_66 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_220 ) ;
}
static T_1
F_67 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_221 ) ;
}
static T_1
F_68 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_52 ,
( V_18 -> V_222 ) ? L_53 : L_54 ,
( V_18 -> V_22 & V_223 ) ?
L_55 : L_56 ) ;
}
static T_1
F_69 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_8 V_224 ;
V_224 = F_70 ( V_18 ) ;
return snprintf ( V_9 , V_10 , L_9 , V_224 ) ;
}
static T_1
F_71 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_84 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
unsigned int V_126 = V_84 ;
if ( V_9 [ V_126 - 1 ] == '\n' )
V_126 -- ;
if ( ( V_126 != strlen ( V_225 ) ) ||
( strncmp ( V_9 , V_225 , strlen ( V_225 ) ) != 0 ) )
return - V_86 ;
V_18 -> V_226 = 1 ;
return V_84 ;
}
static T_1
F_72 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_57 ,
( unsigned long long ) V_18 -> V_227 ) ;
}
static T_1
F_73 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_84 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_120 V_121 ;
int V_228 = 0 , V_229 = 0 ;
unsigned int V_3 , V_4 , V_126 = V_84 ;
T_9 V_230 [ 8 ] ;
int V_127 ;
if ( ! V_18 -> V_134 )
return - V_135 ;
F_62 ( & V_18 -> V_213 ) ;
if ( V_18 -> V_231 == V_232 ) {
F_63 ( & V_18 -> V_213 ) ;
return - V_135 ;
}
F_63 ( & V_18 -> V_213 ) ;
if ( V_9 [ V_126 - 1 ] == '\n' )
V_126 -- ;
if ( ! V_18 -> V_226 || ( V_126 < 16 ) || ( V_126 > 18 ) ||
( ( V_126 == 17 ) && ( * V_9 ++ != 'x' ) ) ||
( ( V_126 == 18 ) && ( ( * V_9 ++ != '0' ) || ( * V_9 ++ != 'x' ) ) ) )
return - V_86 ;
V_18 -> V_226 = 0 ;
memset ( V_230 , 0 , sizeof( V_230 ) ) ;
for ( V_3 = 0 , V_4 = 0 ; V_3 < 16 ; V_3 ++ ) {
int V_233 ;
V_233 = F_74 ( * V_9 ++ ) ;
if ( V_233 >= 0 )
V_4 = ( V_4 << 4 ) | V_233 ;
else
return - V_86 ;
if ( V_3 % 2 ) {
V_230 [ V_3 / 2 ] = V_4 & 0xff ;
V_4 = 0 ;
}
}
V_18 -> V_227 = F_75 ( V_230 ) ;
F_76 ( V_13 ) = V_18 -> V_227 ;
if ( V_18 -> V_234 )
F_77 ( V_13 ) = V_18 -> V_234 ;
F_78 ( V_235 , & V_18 -> V_150 -> V_6 ,
L_58 , V_18 -> V_236 ) ;
V_228 = F_33 ( V_18 , V_136 ) ;
if ( V_228 )
F_30 ( V_18 , V_115 , V_133 ,
L_59
L_60 , V_228 ) ;
F_34 ( & V_121 ) ;
V_127 = F_35 ( V_18 , & V_229 , & V_121 ,
V_137 ) ;
if ( V_127 == 0 )
return - V_100 ;
F_36 ( & V_121 ) ;
if ( V_229 )
F_30 ( V_18 , V_115 , V_133 ,
L_61
L_60 , V_229 ) ;
return ( V_228 || V_229 ) ? - V_119 : V_84 ;
}
static T_1
F_79 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_57 ,
( unsigned long long ) V_18 -> V_234 ) ;
}
static T_1
F_80 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_84 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
unsigned int V_3 , V_4 , V_126 = V_84 ;
T_9 V_237 [ 8 ] ;
if ( V_9 [ V_126 - 1 ] == '\n' )
V_126 -- ;
if ( ! V_18 -> V_226 || ( V_126 < 16 ) || ( V_126 > 18 ) ||
( ( V_126 == 17 ) && ( * V_9 ++ != 'x' ) ) ||
( ( V_126 == 18 ) && ( ( * V_9 ++ != '0' ) || ( * V_9 ++ != 'x' ) ) ) )
return - V_86 ;
memset ( V_237 , 0 , sizeof( V_237 ) ) ;
for ( V_3 = 0 , V_4 = 0 ; V_3 < 16 ; V_3 ++ ) {
int V_233 ;
V_233 = F_74 ( * V_9 ++ ) ;
if ( V_233 >= 0 )
V_4 = ( V_4 << 4 ) | V_233 ;
else
return - V_86 ;
if ( V_3 % 2 ) {
V_237 [ V_3 / 2 ] = V_4 & 0xff ;
V_4 = 0 ;
}
}
V_18 -> V_234 = F_75 ( V_237 ) ;
F_78 ( V_235 , & V_18 -> V_150 -> V_6 ,
L_62
L_63 , V_18 -> V_236 ) ;
return V_84 ;
}
static T_1
F_81 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_238 ) ;
}
static T_1
F_82 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 ,
V_18 -> V_33 . V_130 [ V_239 ] . V_240 ) ;
}
static T_1
F_83 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 ,
V_18 -> V_33 . V_130 [ V_239 ] . V_241 ) ;
}
static T_1
F_84 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
return snprintf ( V_9 , V_10 , L_9 , V_15 -> V_242 ) ;
}
static int
F_85 ( struct V_14 * V_15 , int V_212 )
{
if ( V_15 -> V_242 != V_243 ) {
V_15 -> V_244 = V_15 -> V_242 ;
if ( V_212 != V_243 )
F_51 ( V_15 , V_115 , V_133 ,
L_64
L_65
L_66 ) ;
return 0 ;
}
if ( V_212 >= V_245 && V_212 <= V_246 ) {
V_15 -> V_244 = V_212 ;
V_15 -> V_242 = V_212 ;
return 0 ;
}
F_51 ( V_15 , V_115 , V_133 ,
L_67
L_68 ,
V_212 , V_245 , V_246 ) ;
V_15 -> V_244 = V_243 ;
return - V_86 ;
}
static void
F_86 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
struct V_247 * V_248 ;
V_13 = F_87 ( V_15 ) ;
F_62 ( V_13 -> V_249 ) ;
F_88 (ndlp, &vport->fc_nodes, nlp_listp)
if ( F_89 ( V_248 ) && V_248 -> V_250 )
V_248 -> V_250 -> V_251 = V_15 -> V_242 ;
F_63 ( V_13 -> V_249 ) ;
}
static int
F_90 ( struct V_14 * V_15 , int V_212 )
{
if ( V_15 -> V_252 ||
( V_253 != V_243 ) ) {
F_51 ( V_15 , V_115 , V_133 ,
L_69
L_70 ) ;
return 0 ;
}
if ( V_212 >= V_245 && V_212 <= V_246 ) {
V_15 -> V_244 = V_212 ;
V_15 -> V_242 = V_212 ;
F_91 ( F_87 ( V_15 ) ) = V_212 ;
F_86 ( V_15 ) ;
return 0 ;
}
F_51 ( V_15 , V_115 , V_133 ,
L_71
L_72 ,
V_212 , V_245 , V_246 ) ;
return - V_86 ;
}
static int
F_92 ( struct V_14 * V_15 , int V_212 )
{
if ( V_212 >= V_245 && V_212 <= V_246 ) {
V_15 -> V_244 = V_212 ;
V_15 -> V_242 = V_212 ;
V_15 -> V_252 = 1 ;
F_91 ( F_87 ( V_15 ) ) = V_212 ;
F_86 ( V_15 ) ;
return 0 ;
}
F_51 ( V_15 , V_115 , V_133 ,
L_73
L_68 ,
V_212 , V_245 , V_246 ) ;
return - V_86 ;
}
static int
F_93 ( struct V_14 * V_15 , int V_212 )
{
if ( V_212 < 0 || V_212 > 1 ) {
F_51 ( V_15 , V_115 , V_133 ,
L_74
L_75 ,
V_212 ) ;
V_15 -> V_254 = 1 ;
return - V_86 ;
}
if ( V_15 -> V_206 == V_207 ) {
V_15 -> V_254 = 0 ;
return 0 ;
}
V_15 -> V_254 = V_212 ;
return 0 ;
}
static int
F_94 ( struct V_14 * V_15 , int V_212 )
{
if ( V_212 < 0 || V_212 > 1 ) {
F_51 ( V_15 , V_115 , V_133 ,
L_76
L_75 ,
V_212 ) ;
V_15 -> V_254 = 1 ;
return - V_86 ;
}
if ( V_15 -> V_206 == V_207 && V_212 != 0 ) {
F_51 ( V_15 , V_115 , V_133 ,
L_77
L_78 ) ;
V_15 -> V_254 = 0 ;
return 0 ;
}
V_15 -> V_254 = V_212 ;
return 0 ;
}
static T_1
F_95 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_84 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_212 = 0 ;
int V_255 = 0 ;
const char * V_256 = V_9 ;
int V_257 ;
T_2 V_258 ;
if ( ! strncmp ( V_9 , L_79 , strlen ( L_79 ) ) ) {
V_255 = 1 ;
V_256 = & V_9 [ strlen ( L_79 ) ] ;
}
if ( ! isdigit ( V_256 [ 0 ] ) )
return - V_86 ;
if ( sscanf ( V_256 , L_50 , & V_212 ) != 1 )
return - V_86 ;
if ( V_212 >= 0 && V_212 <= 6 ) {
V_258 = V_18 -> V_111 ;
V_18 -> V_111 = V_212 ;
if ( V_18 -> V_112 == V_259 &&
V_212 == 4 ) {
F_51 ( V_15 , V_115 , V_133 ,
L_80 ,
V_18 -> V_112 ) ;
V_18 -> V_111 = V_258 ;
return - V_86 ;
}
if ( V_255 )
return strlen ( V_9 ) ;
F_51 ( V_15 , V_115 , V_133 ,
L_81 ,
V_258 , V_212 ) ;
V_257 = F_26 ( F_87 ( V_18 -> V_159 ) ) ;
if ( V_257 ) {
V_18 -> V_111 = V_258 ;
return - V_86 ;
} else
return strlen ( V_9 ) ;
}
F_30 ( V_18 , V_115 , V_133 ,
L_82
L_83 ,
V_18 -> V_236 , V_212 ) ;
return - V_86 ;
}
static T_1
F_96 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
if ( V_15 -> V_260 & V_261 )
sprintf ( V_9 , L_2 ) ;
else
sprintf ( V_9 , L_3 ) ;
return strlen ( V_9 ) ;
}
static T_1
F_97 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_84 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
#define F_98 1024
static char V_262 [ F_98 ] ;
unsigned long V_3 ;
char * V_263 , * V_264 ;
struct V_14 * * V_265 ;
struct V_12 * V_266 ;
char * V_267 , * V_268 , * V_269 ;
unsigned long V_270 , V_271 , V_272 ;
if ( ! strncmp ( V_9 , L_84 , strlen ( L_84 ) ) ) {
if ( strlen ( V_9 ) > ( F_98 - 1 ) )
return - V_86 ;
strcpy ( V_262 , V_9 ) ;
V_263 = & V_262 [ 0 ] ;
V_264 = F_99 ( & V_263 , L_85 ) ;
if ( ! V_264 )
return - V_86 ;
V_267 = F_99 ( & V_263 , L_85 ) ;
if ( ! V_267 )
return - V_86 ;
if ( ! strncmp ( V_267 , L_86 , strlen ( L_86 ) ) )
V_272 = V_273 ;
else if ( ! strncmp ( V_267 , L_87 , strlen ( L_87 ) ) )
V_272 = V_274 ;
else
return - V_86 ;
V_268 = F_99 ( & V_263 , L_85 ) ;
if ( ! V_268 )
return - V_86 ;
V_270 = F_100 ( V_268 , NULL , 0 ) ;
V_269 = F_99 ( & V_263 , L_85 ) ;
if ( ! V_269 )
return - V_86 ;
V_271 = F_100 ( V_269 , NULL , 0 ) ;
if ( ! V_271 )
return - V_86 ;
V_265 = F_101 ( V_18 ) ;
if ( V_265 == NULL )
return - V_100 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_275 && V_265 [ V_3 ] != NULL ; V_3 ++ ) {
V_266 = F_87 ( V_265 [ V_3 ] ) ;
F_62 ( V_266 -> V_249 ) ;
V_265 [ V_3 ] -> V_276 = 1 ;
if ( V_265 [ V_3 ] -> V_277 )
F_102 ( V_265 [ V_3 ] ) ;
F_63 ( V_266 -> V_249 ) ;
}
V_18 -> V_272 = V_272 ;
V_18 -> V_278 = V_270 ;
V_18 -> V_279 = V_271 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_275 && V_265 [ V_3 ] != NULL ; V_3 ++ ) {
V_266 = F_87 ( V_265 [ V_3 ] ) ;
F_62 ( V_266 -> V_249 ) ;
V_265 [ V_3 ] -> V_276 = 0 ;
F_63 ( V_266 -> V_249 ) ;
}
F_103 ( V_18 , V_265 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_88 , strlen ( L_88 ) ) ) {
V_265 = F_101 ( V_18 ) ;
if ( V_265 == NULL )
return - V_100 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_275 && V_265 [ V_3 ] != NULL ; V_3 ++ ) {
V_266 = F_87 ( V_265 [ V_3 ] ) ;
F_62 ( V_13 -> V_249 ) ;
V_265 [ V_3 ] -> V_276 = 1 ;
F_104 ( V_15 ) ;
V_15 -> V_277 = 0 ;
V_265 [ V_3 ] -> V_276 = 0 ;
F_63 ( V_13 -> V_249 ) ;
}
F_103 ( V_18 , V_265 ) ;
V_18 -> V_272 = V_280 ;
V_18 -> V_278 = 0 ;
V_18 -> V_279 = 0 ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_89 , strlen ( L_89 ) ) ) {
if ( V_18 -> V_272 == V_280 )
return - V_86 ;
F_62 ( V_13 -> V_249 ) ;
if ( V_15 -> V_277 ) {
F_63 ( V_13 -> V_249 ) ;
return strlen ( V_9 ) ;
}
F_105 ( V_15 ) ;
V_15 -> V_277 = 1 ;
F_63 ( V_13 -> V_249 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_90 , strlen ( L_90 ) ) ) {
F_62 ( V_13 -> V_249 ) ;
if ( V_15 -> V_277 == 0 ) {
F_63 ( V_13 -> V_249 ) ;
return strlen ( V_9 ) ;
}
F_104 ( V_15 ) ;
V_15 -> V_277 = 0 ;
F_63 ( V_13 -> V_249 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_91 , strlen ( L_91 ) ) ) {
if ( ( V_18 -> V_272 == V_280 )
|| ! V_15 -> V_277 )
return strlen ( V_9 ) ;
F_62 ( V_13 -> V_249 ) ;
V_15 -> V_276 = 1 ;
F_102 ( V_15 ) ;
V_15 -> V_276 = 0 ;
F_63 ( V_13 -> V_249 ) ;
return strlen ( V_9 ) ;
}
return - V_86 ;
}
static T_1
F_106 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_281 = 0 ;
int V_3 ;
char * V_272 ;
unsigned long V_282 ;
switch ( V_18 -> V_272 ) {
case V_273 :
V_272 = L_86 ;
break;
case V_274 :
V_272 = L_87 ;
break;
default:
V_272 = L_92 ;
break;
}
sprintf ( & V_9 [ V_281 ] , L_93
L_94
L_95 ,
V_15 -> V_277 , V_15 -> V_276 ,
V_272 , V_18 -> V_278 , V_18 -> V_279 ) ;
V_281 = strlen ( V_9 ) ;
if ( V_18 -> V_272 != V_280 ) {
for ( V_3 = 0 ; V_3 < V_283 ; V_3 ++ ) {
if ( V_18 -> V_272 == V_273 )
V_282 = V_18 -> V_278 +
V_18 -> V_279 * V_3 ;
else
V_282 = V_18 -> V_278 +
( 1 << V_3 ) * V_18 -> V_279 ;
if ( V_281 + 10 > V_10 )
break;
sprintf ( & V_9 [ V_281 ] , L_96 , V_282 ) ;
V_281 = strlen ( V_9 ) ;
}
}
sprintf ( & V_9 [ V_281 ] , L_1 ) ;
return strlen ( V_9 ) ;
}
static T_1
F_107 ( struct V_284 * V_285 , struct V_286 * V_287 ,
struct V_288 * V_289 ,
char * V_9 , T_10 V_290 , T_5 V_84 )
{
struct V_5 * V_6 = F_108 ( V_287 , struct V_5 ,
V_287 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_3 = 0 , V_281 = 0 ;
unsigned long V_291 ;
struct V_247 * V_248 = NULL ;
V_291 = ( unsigned long ) V_290 /
V_292 ;
if ( ! V_15 -> V_277 || V_15 -> V_276
|| ( V_18 -> V_272 == V_280 ) )
return 0 ;
F_62 ( V_13 -> V_249 ) ;
F_88 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_89 ( V_248 ) || ! V_248 -> V_293 )
continue;
if ( V_291 > 0 ) {
V_291 -- ;
continue;
}
if ( ( V_281 + V_292 )
> V_84 )
break;
if ( ! V_248 -> V_293 )
continue;
sprintf ( & V_9 [ V_281 ] , L_97 ,
V_248 -> V_294 . V_101 . V_295 [ 0 ] ,
V_248 -> V_294 . V_101 . V_295 [ 1 ] ,
V_248 -> V_294 . V_101 . V_295 [ 2 ] ,
V_248 -> V_294 . V_101 . V_295 [ 3 ] ,
V_248 -> V_294 . V_101 . V_295 [ 4 ] ,
V_248 -> V_294 . V_101 . V_295 [ 5 ] ,
V_248 -> V_294 . V_101 . V_295 [ 6 ] ,
V_248 -> V_294 . V_101 . V_295 [ 7 ] ) ;
V_281 = strlen ( V_9 ) ;
for ( V_3 = 0 ; V_3 < V_283 ; V_3 ++ ) {
sprintf ( & V_9 [ V_281 ] , L_98 ,
V_248 -> V_293 [ V_3 ] . V_296 ) ;
V_281 = strlen ( V_9 ) ;
}
sprintf ( & V_9 [ V_281 ] , L_1 ) ;
V_281 = strlen ( V_9 ) ;
}
F_63 ( V_13 -> V_249 ) ;
return V_281 ;
}
static T_1
F_109 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_84 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_212 = V_297 ;
int V_255 = 0 ;
const char * V_256 = V_9 ;
int V_257 ;
T_2 V_258 ;
if ( ! strncmp ( V_9 , L_79 , strlen ( L_79 ) ) ) {
V_255 = 1 ;
V_256 = & V_9 [ strlen ( L_79 ) ] ;
}
if ( ! isdigit ( V_256 [ 0 ] ) )
return - V_86 ;
if ( sscanf ( V_256 , L_50 , & V_212 ) != 1 )
return - V_86 ;
F_51 ( V_15 , V_115 , V_133 ,
L_99 ,
V_18 -> V_112 , V_212 , V_255 ? L_100 : L_101 ) ;
if ( ( ( V_212 == V_298 ) && ! ( V_18 -> V_299 & V_300 ) ) ||
( ( V_212 == V_301 ) && ! ( V_18 -> V_299 & V_302 ) ) ||
( ( V_212 == V_303 ) && ! ( V_18 -> V_299 & V_304 ) ) ||
( ( V_212 == V_305 ) && ! ( V_18 -> V_299 & V_306 ) ) ||
( ( V_212 == V_307 ) && ! ( V_18 -> V_299 & V_308 ) ) ||
( ( V_212 == V_259 ) && ! ( V_18 -> V_299 & V_309 ) ) ) {
F_30 ( V_18 , V_115 , V_133 ,
L_102
L_103 ,
V_212 ) ;
return - V_86 ;
}
if ( V_212 == V_259 &&
V_18 -> V_73 == V_74 ) {
F_30 ( V_18 , V_115 , V_133 ,
L_104
L_105 ,
V_212 ) ;
return - V_86 ;
}
if ( ( V_212 >= 0 ) && ( V_212 <= V_310 ) &&
( V_311 & ( 1 << V_212 ) ) ) {
V_258 = V_18 -> V_112 ;
V_18 -> V_112 = V_212 ;
if ( V_255 )
return strlen ( V_9 ) ;
V_257 = F_26 ( F_87 ( V_18 -> V_159 ) ) ;
if ( V_257 ) {
V_18 -> V_112 = V_258 ;
return - V_86 ;
} else
return strlen ( V_9 ) ;
}
F_30 ( V_18 , V_115 , V_133 ,
L_106
L_107 V_312 L_108 , V_212 ) ;
return - V_86 ;
}
static int
F_110 ( struct V_17 * V_18 , int V_212 )
{
if ( V_212 == V_259 && V_18 -> V_111 == 4 ) {
F_30 ( V_18 , V_115 , V_133 ,
L_109
L_110 ,
V_212 ) ;
V_18 -> V_111 = 0 ;
}
if ( ( V_212 >= 0 ) && ( V_212 <= V_310 ) &&
( V_311 & ( 1 << V_212 ) ) ) {
V_18 -> V_112 = V_212 ;
return 0 ;
}
F_30 ( V_18 , V_115 , V_133 ,
L_111
L_112
L_113 V_312 L_108 , V_212 ) ;
V_18 -> V_112 = V_297 ;
return - V_86 ;
}
static T_1
F_111 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_84 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_212 = 0 , V_127 = - V_86 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_86 ;
if ( sscanf ( V_9 , L_50 , & V_212 ) != 1 )
return - V_86 ;
switch ( V_212 ) {
case 0 :
if ( V_18 -> V_19 & V_313 ) {
V_127 = F_112 ( V_18 -> V_150 ) ;
if ( ! V_127 ) {
F_62 ( & V_18 -> V_213 ) ;
V_18 -> V_19 &= ~ V_313 ;
F_63 ( & V_18 -> V_213 ) ;
V_18 -> V_314 = 0 ;
V_127 = strlen ( V_9 ) ;
} else
V_127 = - V_97 ;
} else {
V_18 -> V_314 = 0 ;
V_127 = strlen ( V_9 ) ;
}
break;
case 1 :
if ( ! ( V_18 -> V_19 & V_313 ) ) {
V_127 = F_113 ( V_18 -> V_150 ) ;
if ( ! V_127 ) {
F_62 ( & V_18 -> V_213 ) ;
V_18 -> V_19 |= V_313 ;
F_63 ( & V_18 -> V_213 ) ;
V_18 -> V_314 = 1 ;
V_127 = strlen ( V_9 ) ;
} else
V_127 = - V_97 ;
} else {
V_18 -> V_314 = 1 ;
V_127 = strlen ( V_9 ) ;
}
break;
default:
V_127 = - V_86 ;
break;
}
return V_127 ;
}
static int
F_114 ( struct V_17 * V_18 , int V_212 )
{
if ( V_212 == 0 || V_212 == 1 ) {
V_18 -> V_314 = V_212 ;
return 0 ;
}
F_30 ( V_18 , V_115 , V_133 ,
L_114
L_115
L_116 , V_212 ) ;
V_18 -> V_314 = 1 ;
return - V_86 ;
}
static T_1
F_115 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_84 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_212 , V_127 = - 1 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_86 ;
if ( sscanf ( V_9 , L_50 , & V_212 ) != 1 )
return - V_86 ;
if ( V_212 != 1 )
return - V_86 ;
if ( V_18 -> V_19 & V_313 )
V_127 = F_116 ( V_18 -> V_150 ) ;
if ( V_127 == 0 )
return strlen ( V_9 ) ;
else
return - V_97 ;
}
static T_1
F_117 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_84 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_148 * V_149 = V_18 -> V_150 ;
int V_212 = 0 , V_127 = - V_86 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_86 ;
if ( sscanf ( V_9 , L_50 , & V_212 ) != 1 )
return - V_86 ;
if ( V_212 < 0 )
return - V_86 ;
if ( V_212 == 0 ) {
if ( V_18 -> V_160 > 0 ) {
F_44 ( V_149 ) ;
V_18 -> V_160 = 0 ;
}
return strlen ( V_9 ) ;
}
if ( V_18 -> V_160 > 0 ) {
F_30 ( V_18 , V_115 , V_133 ,
L_117
L_118 ,
V_18 -> V_160 ) ;
return - V_315 ;
}
if ( V_212 <= V_316 )
V_18 -> V_160 = V_212 ;
else {
F_30 ( V_18 , V_115 , V_133 ,
L_119
L_120 , V_212 ) ;
return - V_86 ;
}
V_127 = F_47 ( V_18 , V_18 -> V_160 ) ;
if ( V_127 ) {
V_18 -> V_160 = 0 ;
V_127 = - V_97 ;
} else
V_127 = strlen ( V_9 ) ;
return V_127 ;
}
static int
F_118 ( struct V_17 * V_18 , int V_212 )
{
if ( V_212 >= 0 && V_212 <= V_316 ) {
V_18 -> V_160 = V_212 ;
return 0 ;
}
F_30 ( V_18 , V_115 , V_133 ,
L_121
L_120 , V_212 ) ;
return - V_86 ;
}
static int
F_119 ( struct V_14 * V_15 , int V_212 )
{
struct V_12 * V_13 = F_87 ( V_15 ) ;
struct V_247 * V_248 , * V_317 ;
if ( V_212 == V_15 -> V_318 )
return 0 ;
if ( ( V_212 < 0 ) || ( V_212 > 60000 ) )
return - V_86 ;
V_15 -> V_318 = V_212 ;
F_62 ( V_13 -> V_249 ) ;
F_120 (ndlp, next_ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_89 ( V_248 ) )
continue;
if ( V_248 -> V_319 == V_320 )
continue;
V_248 -> V_321 = V_15 -> V_322 ;
}
F_63 ( V_13 -> V_249 ) ;
return 0 ;
}
static T_1
F_121 ( struct V_284 * V_285 , struct V_286 * V_287 ,
struct V_288 * V_289 ,
char * V_9 , T_10 V_290 , T_5 V_84 )
{
T_5 V_323 ;
struct V_5 * V_6 = F_108 ( V_287 , struct V_5 , V_287 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_43 >= V_44 )
return - V_97 ;
if ( ( V_290 + V_84 ) > V_324 )
return - V_325 ;
if ( V_84 <= V_326 )
return 0 ;
if ( V_290 % 4 || V_84 % 4 || ( unsigned long ) V_9 % 4 )
return - V_86 ;
if ( memcmp ( V_9 , V_327 , V_326 ) )
return - V_86 ;
if ( ! ( V_15 -> V_75 & V_95 ) )
return - V_97 ;
F_62 ( & V_18 -> V_213 ) ;
for ( V_323 = 0 ; V_323 < V_84 - V_326 ;
V_323 += sizeof( T_2 ) )
F_46 ( * ( ( T_2 * ) ( V_9 + V_323 + V_326 ) ) ,
V_18 -> V_328 + V_290 + V_323 ) ;
F_63 ( & V_18 -> V_213 ) ;
return V_84 ;
}
static T_1
F_122 ( struct V_284 * V_285 , struct V_286 * V_287 ,
struct V_288 * V_289 ,
char * V_9 , T_10 V_290 , T_5 V_84 )
{
T_5 V_323 ;
T_2 * V_329 ;
struct V_5 * V_6 = F_108 ( V_287 , struct V_5 , V_287 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_43 >= V_44 )
return - V_97 ;
if ( V_290 > V_324 )
return - V_325 ;
if ( ( V_290 + V_84 ) > V_324 )
V_84 = V_324 - V_290 ;
if ( V_84 == 0 ) return 0 ;
if ( V_290 % 4 || V_84 % 4 || ( unsigned long ) V_9 % 4 )
return - V_86 ;
F_62 ( & V_18 -> V_213 ) ;
for ( V_323 = 0 ; V_323 < V_84 ; V_323 += sizeof( T_2 ) ) {
V_329 = ( T_2 * ) ( V_9 + V_323 ) ;
* V_329 = F_45 ( V_18 -> V_328 + V_290 + V_323 ) ;
}
F_63 ( & V_18 -> V_213 ) ;
return V_84 ;
}
static T_1
F_123 ( struct V_284 * V_285 , struct V_286 * V_287 ,
struct V_288 * V_289 ,
char * V_9 , T_10 V_290 , T_5 V_84 )
{
return - V_97 ;
}
static T_1
F_124 ( struct V_284 * V_285 , struct V_286 * V_287 ,
struct V_288 * V_289 ,
char * V_9 , T_10 V_290 , T_5 V_84 )
{
return - V_97 ;
}
int
F_125 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = F_87 ( V_15 ) ;
int error ;
error = F_126 ( & V_13 -> V_330 . V_287 ,
& V_331 ) ;
if ( error || V_15 -> V_206 == V_332 )
goto V_169;
error = F_126 ( & V_13 -> V_330 . V_287 ,
& V_333 ) ;
if ( error )
goto V_334;
error = F_126 ( & V_13 -> V_330 . V_287 ,
& V_335 ) ;
if ( error )
goto V_336;
return 0 ;
V_336:
F_127 ( & V_13 -> V_330 . V_287 , & V_333 ) ;
V_334:
F_127 ( & V_13 -> V_330 . V_287 ,
& V_331 ) ;
V_169:
return error ;
}
void
F_128 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = F_87 ( V_15 ) ;
F_127 ( & V_13 -> V_330 . V_287 ,
& V_331 ) ;
if ( V_15 -> V_206 == V_332 )
return;
F_127 ( & V_13 -> V_330 . V_287 , & V_335 ) ;
F_127 ( & V_13 -> V_330 . V_287 , & V_333 ) ;
}
static void
F_129 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
F_130 ( V_13 ) = V_15 -> V_337 ;
}
static void
F_131 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_62 ( V_13 -> V_249 ) ;
if ( V_15 -> V_206 == V_332 ) {
F_132 ( V_13 ) = V_338 ;
} else if ( F_133 ( V_18 ) ) {
if ( V_18 -> V_73 == V_74 ) {
if ( V_15 -> V_75 & V_76 )
F_132 ( V_13 ) = V_339 ;
else
F_132 ( V_13 ) = V_340 ;
} else {
if ( V_15 -> V_75 & V_77 )
F_132 ( V_13 ) = V_341 ;
else
F_132 ( V_13 ) = V_342 ;
}
} else
F_132 ( V_13 ) = V_343 ;
F_63 ( V_13 -> V_249 ) ;
}
static void
F_134 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_62 ( V_13 -> V_249 ) ;
if ( V_15 -> V_75 & V_95 )
F_135 ( V_13 ) = V_344 ;
else {
switch ( V_18 -> V_50 ) {
case V_51 :
case V_55 :
F_135 ( V_13 ) = V_345 ;
break;
case V_58 :
case V_59 :
case V_60 :
if ( V_15 -> V_61 < V_70 )
F_135 ( V_13 ) =
V_346 ;
else
F_135 ( V_13 ) =
V_347 ;
break;
case V_56 :
F_135 ( V_13 ) = V_348 ;
break;
default:
F_135 ( V_13 ) = V_349 ;
break;
}
}
F_63 ( V_13 -> V_249 ) ;
}
static void
F_136 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_62 ( V_13 -> V_249 ) ;
if ( F_133 ( V_18 ) ) {
switch( V_18 -> V_350 ) {
case V_351 :
F_137 ( V_13 ) = V_352 ;
break;
case V_353 :
F_137 ( V_13 ) = V_354 ;
break;
case V_355 :
F_137 ( V_13 ) = V_356 ;
break;
case V_357 :
F_137 ( V_13 ) = V_358 ;
break;
case V_359 :
F_137 ( V_13 ) = V_360 ;
break;
case V_361 :
F_137 ( V_13 ) = V_362 ;
break;
default:
F_137 ( V_13 ) = V_363 ;
break;
}
} else
F_137 ( V_13 ) = V_363 ;
F_63 ( V_13 -> V_249 ) ;
}
static void
F_138 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_11 V_364 ;
F_62 ( V_13 -> V_249 ) ;
if ( ( V_15 -> V_61 > V_64 ) &&
( ( V_15 -> V_75 & V_77 ) ||
( ( V_18 -> V_73 == V_74 ) &&
( V_15 -> V_75 & V_76 ) ) ) )
V_364 = F_75 ( V_18 -> V_365 . V_366 . V_101 . V_295 ) ;
else
V_364 = 0 ;
F_63 ( V_13 -> V_249 ) ;
F_139 ( V_13 ) = V_364 ;
}
static struct V_367 *
F_140 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_124 * V_125 = & V_18 -> V_33 ;
struct V_367 * V_368 = & V_18 -> V_369 ;
struct V_370 * V_371 = & V_125 -> V_372 ;
T_6 * V_92 ;
T_7 * V_184 ;
unsigned long V_373 ;
int V_127 = 0 ;
if ( V_18 -> V_50 < V_55 ||
! V_18 -> V_98 ||
( V_18 -> V_33 . V_34 & V_186 ) == 0 )
return NULL ;
if ( V_18 -> V_33 . V_34 & V_96 )
return NULL ;
V_92 = F_27 ( V_18 -> V_98 , V_99 ) ;
if ( ! V_92 )
return NULL ;
memset ( V_92 , 0 , sizeof ( T_6 ) ) ;
V_184 = & V_92 -> V_101 . V_102 ;
V_184 -> V_103 = V_374 ;
V_184 -> V_105 = V_106 ;
V_92 -> V_188 = NULL ;
V_92 -> V_15 = V_15 ;
if ( V_15 -> V_75 & V_95 )
V_127 = F_141 ( V_18 , V_92 , V_375 ) ;
else
V_127 = F_28 ( V_18 , V_92 , V_18 -> V_113 * 2 ) ;
if ( V_127 != V_108 ) {
if ( V_127 != V_118 )
F_32 ( V_92 , V_18 -> V_98 ) ;
return NULL ;
}
memset ( V_368 , 0 , sizeof ( struct V_367 ) ) ;
V_368 -> V_376 = V_184 -> V_191 . V_377 . V_378 ;
V_368 -> V_379 = ( V_380 )
( ( V_380 ) V_184 -> V_191 . V_377 . V_381
* ( V_380 ) 256 ) ;
V_368 -> V_382 = V_184 -> V_191 . V_377 . V_383 ;
V_368 -> V_384 = ( V_380 )
( ( V_380 ) V_184 -> V_191 . V_377 . V_385
* ( V_380 ) 256 ) ;
memset ( V_92 , 0 , sizeof ( T_6 ) ) ;
V_184 -> V_103 = V_386 ;
V_184 -> V_105 = V_106 ;
V_92 -> V_188 = NULL ;
V_92 -> V_15 = V_15 ;
if ( V_15 -> V_75 & V_95 )
V_127 = F_141 ( V_18 , V_92 , V_375 ) ;
else
V_127 = F_28 ( V_18 , V_92 , V_18 -> V_113 * 2 ) ;
if ( V_127 != V_108 ) {
if ( V_127 != V_118 )
F_32 ( V_92 , V_18 -> V_98 ) ;
return NULL ;
}
V_368 -> V_387 = V_184 -> V_191 . V_388 . V_389 ;
V_368 -> V_390 = V_184 -> V_191 . V_388 . V_391 ;
V_368 -> V_392 = V_184 -> V_191 . V_388 . V_393 ;
V_368 -> V_394 = V_184 -> V_191 . V_388 . V_395 ;
V_368 -> V_396 = V_184 -> V_191 . V_388 . V_397 ;
V_368 -> V_398 = V_184 -> V_191 . V_388 . V_399 ;
V_368 -> V_400 = V_184 -> V_191 . V_388 . V_399 ;
V_368 -> V_387 -= V_371 -> V_387 ;
V_368 -> V_390 -= V_371 -> V_390 ;
V_368 -> V_392 -= V_371 -> V_392 ;
V_368 -> V_394 -= V_371 -> V_394 ;
V_368 -> V_396 -= V_371 -> V_396 ;
V_368 -> V_398 -= V_371 -> V_398 ;
V_368 -> V_400 -= V_371 -> V_400 ;
if ( V_18 -> V_19 & V_401 ) {
V_368 -> V_402 = - 1 ;
V_368 -> V_403 = ( V_18 -> V_404 >> 1 ) ;
V_368 -> V_403 -= V_371 -> V_404 ;
} else if ( V_18 -> V_73 == V_74 ) {
V_368 -> V_402 = ( V_18 -> V_405 >> 1 ) ;
V_368 -> V_402 -= V_371 -> V_404 ;
V_368 -> V_403 = - 1 ;
} else {
V_368 -> V_402 = - 1 ;
V_368 -> V_403 = ( V_18 -> V_405 >> 1 ) ;
V_368 -> V_403 -= V_371 -> V_404 ;
}
V_368 -> V_406 = - 1 ;
V_373 = F_142 () ;
if ( V_373 < V_125 -> V_407 )
V_368 -> V_408 = V_373 +
( ( unsigned long ) - 1 - V_125 -> V_407 ) ;
else
V_368 -> V_408 = V_373 - V_125 -> V_407 ;
F_32 ( V_92 , V_18 -> V_98 ) ;
return V_368 ;
}
static void
F_143 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_124 * V_125 = & V_18 -> V_33 ;
struct V_370 * V_371 = & V_125 -> V_372 ;
T_6 * V_92 ;
T_7 * V_184 ;
int V_127 = 0 ;
if ( V_18 -> V_33 . V_34 & V_96 )
return;
V_92 = F_27 ( V_18 -> V_98 , V_99 ) ;
if ( ! V_92 )
return;
memset ( V_92 , 0 , sizeof( T_6 ) ) ;
V_184 = & V_92 -> V_101 . V_102 ;
V_184 -> V_103 = V_374 ;
V_184 -> V_105 = V_106 ;
V_184 -> V_191 . V_409 [ 0 ] = 0x1 ;
V_92 -> V_188 = NULL ;
V_92 -> V_15 = V_15 ;
if ( ( V_15 -> V_75 & V_95 ) ||
( ! ( V_125 -> V_34 & V_186 ) ) )
V_127 = F_141 ( V_18 , V_92 , V_375 ) ;
else
V_127 = F_28 ( V_18 , V_92 , V_18 -> V_113 * 2 ) ;
if ( V_127 != V_108 ) {
if ( V_127 != V_118 )
F_32 ( V_92 , V_18 -> V_98 ) ;
return;
}
memset ( V_92 , 0 , sizeof( T_6 ) ) ;
V_184 -> V_103 = V_386 ;
V_184 -> V_105 = V_106 ;
V_92 -> V_188 = NULL ;
V_92 -> V_15 = V_15 ;
if ( ( V_15 -> V_75 & V_95 ) ||
( ! ( V_125 -> V_34 & V_186 ) ) )
V_127 = F_141 ( V_18 , V_92 , V_375 ) ;
else
V_127 = F_28 ( V_18 , V_92 , V_18 -> V_113 * 2 ) ;
if ( V_127 != V_108 ) {
if ( V_127 != V_118 )
F_32 ( V_92 , V_18 -> V_98 ) ;
return;
}
V_371 -> V_387 = V_184 -> V_191 . V_388 . V_389 ;
V_371 -> V_390 = V_184 -> V_191 . V_388 . V_391 ;
V_371 -> V_392 = V_184 -> V_191 . V_388 . V_393 ;
V_371 -> V_394 = V_184 -> V_191 . V_388 . V_395 ;
V_371 -> V_396 = V_184 -> V_191 . V_388 . V_397 ;
V_371 -> V_398 = V_184 -> V_191 . V_388 . V_399 ;
V_371 -> V_400 = V_184 -> V_191 . V_388 . V_399 ;
if ( V_18 -> V_19 & V_401 )
V_371 -> V_404 = ( V_18 -> V_404 >> 1 ) ;
else
V_371 -> V_404 = ( V_18 -> V_405 >> 1 ) ;
V_125 -> V_407 = F_142 () ;
F_32 ( V_92 , V_18 -> V_98 ) ;
return;
}
static struct V_247 *
F_144 ( struct V_410 * V_411 )
{
struct V_12 * V_13 = F_145 ( V_411 -> V_6 . V_412 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_247 * V_248 ;
F_62 ( V_13 -> V_249 ) ;
F_88 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( F_89 ( V_248 ) &&
V_248 -> V_319 == V_413 &&
V_411 -> V_414 == V_248 -> V_415 ) {
F_63 ( V_13 -> V_249 ) ;
return V_248 ;
}
}
F_63 ( V_13 -> V_249 ) ;
return NULL ;
}
static void
F_146 ( struct V_410 * V_411 )
{
struct V_247 * V_248 = F_144 ( V_411 ) ;
F_147 ( V_411 ) = V_248 ? V_248 -> V_416 : - 1 ;
}
static void
F_148 ( struct V_410 * V_411 )
{
struct V_247 * V_248 = F_144 ( V_411 ) ;
F_149 ( V_411 ) =
V_248 ? F_75 ( V_248 -> V_417 . V_101 . V_295 ) : 0 ;
}
static void
F_150 ( struct V_410 * V_411 )
{
struct V_247 * V_248 = F_144 ( V_411 ) ;
F_151 ( V_411 ) =
V_248 ? F_75 ( V_248 -> V_294 . V_101 . V_295 ) : 0 ;
}
static void
F_152 ( struct V_418 * V_250 , T_2 V_419 )
{
if ( V_419 )
V_250 -> V_251 = V_419 ;
else
V_250 -> V_251 = 1 ;
}
static void
F_153 ( struct V_420 * V_420 )
{
struct V_14 * V_15 = * (struct V_14 * * ) V_420 -> V_421 ;
if ( V_15 -> V_61 == V_70 )
F_154 ( V_15 , V_422 , 0 , 0 ) ;
}
static void
F_155 ( struct V_17 * V_18 , T_2 V_423 )
{
V_18 -> V_424 = V_423 ;
}
void
F_156 ( struct V_17 * V_18 )
{
F_157 ( V_18 , V_425 ) ;
F_158 ( V_18 , V_426 ) ;
F_159 ( V_18 , V_427 ) ;
F_160 ( V_18 , V_428 ) ;
F_161 ( V_18 , V_429 ) ;
F_162 ( V_18 , V_430 ) ;
F_163 ( V_18 , V_431 ) ;
F_110 ( V_18 , V_432 ) ;
F_164 ( V_18 , V_433 ) ;
F_165 ( V_18 , V_434 ) ;
F_166 ( V_18 , V_435 ) ;
F_167 ( V_18 , V_436 ) ;
F_168 ( V_18 , V_437 ) ;
F_169 ( V_18 , V_438 ) ;
F_170 ( V_18 , V_439 ) ;
F_171 ( V_18 , V_440 ) ;
F_172 ( V_18 , V_441 ) ;
F_173 ( V_18 , V_442 ) ;
F_174 ( V_18 , V_443 ) ;
if ( V_18 -> V_43 == V_44 )
V_18 -> V_209 = 0 ;
else
V_18 -> V_209 = V_444 ;
V_18 -> V_234 = 0L ;
V_18 -> V_227 = 0L ;
F_175 ( V_18 , V_445 ) ;
F_176 ( V_18 , V_446 ) ;
F_177 ( V_18 , V_447 ) ;
F_155 ( V_18 , V_448 ) ;
F_114 ( V_18 , V_449 ) ;
F_118 ( V_18 , V_450 ) ;
F_178 ( V_18 , V_451 ) ;
F_179 ( V_18 , V_452 ) ;
V_18 -> V_222 = 1 ;
return;
}
void
F_180 ( struct V_14 * V_15 )
{
F_181 ( V_15 , V_448 ) ;
F_182 ( V_15 , V_453 ) ;
F_183 ( V_15 , V_454 ) ;
F_184 ( V_15 , V_253 ) ;
F_85 ( V_15 , V_455 ) ;
F_185 ( V_15 , V_456 ) ;
F_93 ( V_15 , V_457 ) ;
F_186 ( V_15 , V_458 ) ;
F_187 ( V_15 , V_459 ) ;
F_188 ( V_15 , V_460 ) ;
F_189 ( V_15 , V_461 ) ;
F_190 ( V_15 , V_462 ) ;
F_191 ( V_15 , V_463 ) ;
F_192 ( V_15 , V_464 ) ;
F_193 ( V_15 , V_465 ) ;
return;
}
