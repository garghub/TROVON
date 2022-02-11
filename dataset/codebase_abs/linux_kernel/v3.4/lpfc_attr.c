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
char V_39 [ V_40 ] ;
int V_41 ;
F_19 ( V_18 , V_39 , 1 ) ;
V_37 = V_18 -> V_42 . V_43 . V_37 ;
V_38 = V_18 -> V_42 . V_43 . V_38 ;
if ( V_18 -> V_44 < V_45 )
V_41 = snprintf ( V_9 , V_10 , L_10 ,
V_39 , V_18 -> V_44 ) ;
else
V_41 = snprintf ( V_9 , V_10 , L_11 ,
V_39 , V_18 -> V_44 , V_37 , V_38 ) ;
return V_41 ;
}
static T_1
F_20 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
char V_2 [ 9 ] ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_4 * V_46 = & V_18 -> V_47 ;
F_1 ( V_46 -> V_48 . V_49 , V_2 ) ;
return snprintf ( V_9 , V_10 , L_8 , V_2 ) ;
}
static T_1
F_21 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_8 , V_18 -> V_50 ) ;
}
static T_1
F_22 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_41 = 0 ;
switch ( V_18 -> V_51 ) {
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
if ( V_18 -> V_19 & V_58 )
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_12 ) ;
else
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_13 ) ;
break;
case V_59 :
case V_60 :
case V_61 :
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 , L_14 ) ;
switch ( V_15 -> V_62 ) {
case V_63 :
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_15 ) ;
break;
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_16 ) ;
break;
case V_71 :
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 , L_17 ) ;
break;
case V_72 :
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 , L_18 ) ;
break;
case V_73 :
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_19 ) ;
break;
}
if ( V_18 -> V_33 . V_34 & V_35 )
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_20 ) ;
else if ( V_18 -> V_74 == V_75 ) {
if ( V_15 -> V_76 & V_77 )
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_21 ) ;
else
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_22 ) ;
} else {
if ( V_15 -> V_76 & V_78 )
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_23 ) ;
else
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_24 ) ;
}
}
return V_41 ;
}
static T_1
F_23 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_44 < V_45 )
return snprintf ( V_9 , V_10 , L_25 ) ;
if ( V_18 -> V_42 . V_79 . V_80 == V_81 ) {
if ( V_18 -> V_42 . V_79 . V_82 == V_83 )
return snprintf ( V_9 , V_10 , L_26 ) ;
if ( V_18 -> V_42 . V_79 . V_82 == V_84 )
return snprintf ( V_9 , V_10 , L_25 ) ;
}
return snprintf ( V_9 , V_10 , L_27 ) ;
}
static T_1
F_24 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_85 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_86 = - V_87 ;
if ( ( strncmp ( V_9 , L_28 , sizeof( L_28 ) - 1 ) == 0 ) &&
( V_18 -> V_51 == V_56 ) )
V_86 = V_18 -> V_88 ( V_18 , V_89 ) ;
else if ( ( strncmp ( V_9 , L_29 , sizeof( L_29 ) - 1 ) == 0 ) &&
( V_18 -> V_51 >= V_59 ) )
V_86 = V_18 -> V_90 ( V_18 , V_89 ) ;
if ( V_86 == 0 )
return strlen ( V_9 ) ;
else
return V_86 ;
}
static T_1
F_25 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
return snprintf ( V_9 , V_10 , L_9 ,
V_15 -> V_91 + V_15 -> V_92 ) ;
}
static int
F_26 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_6 * V_93 ;
int V_94 = V_95 ;
if ( ( V_15 -> V_76 & V_96 ) ||
( V_18 -> V_33 . V_34 & V_97 ) )
return - V_98 ;
V_93 = F_27 ( V_18 -> V_99 , V_100 ) ;
if ( ! V_93 )
return - V_101 ;
memset ( ( void * ) V_93 , 0 , sizeof ( T_6 ) ) ;
V_93 -> V_102 . V_103 . V_104 = V_105 ;
V_93 -> V_102 . V_103 . V_106 = V_107 ;
V_94 = F_28 ( V_18 , V_93 , V_108 * 2 ) ;
if ( ( V_94 == V_109 ) &&
( V_93 -> V_102 . V_103 . V_110 == 0 ||
V_93 -> V_102 . V_103 . V_110 == V_111 ) ) {
memset ( ( void * ) V_93 , 0 , sizeof ( T_6 ) ) ;
F_29 ( V_18 , V_93 , V_18 -> V_112 ,
V_18 -> V_113 ) ;
V_94 = F_28 ( V_18 , V_93 ,
V_18 -> V_114 * 2 ) ;
if ( ( V_94 == V_109 ) &&
( V_93 -> V_102 . V_103 . V_110 == V_115 ) )
F_30 ( V_18 , V_116 , V_117 | V_118 ,
L_30
L_31 ) ;
}
F_31 ( V_18 ) ;
if ( V_94 != V_119 )
F_32 ( V_93 , V_18 -> V_99 ) ;
if ( V_94 == V_95 )
return - V_120 ;
return 0 ;
}
static int
F_33 ( struct V_17 * V_18 , T_2 type )
{
struct V_121 V_122 ;
struct V_123 * V_124 ;
struct V_125 * V_126 ;
int V_86 = 0 ;
int V_127 = 0 ;
int V_3 ;
int V_128 ;
F_34 ( & V_122 ) ;
V_128 = F_35 ( V_18 , & V_86 , & V_122 ,
V_129 ) ;
if ( V_128 == 0 )
return - V_101 ;
F_36 ( & V_122 ) ;
if ( V_86 != 0 )
return - V_120 ;
V_126 = & V_18 -> V_33 ;
for ( V_3 = 0 ; V_3 < V_126 -> V_130 ; V_3 ++ ) {
V_124 = & V_126 -> V_131 [ V_3 ] ;
while ( V_124 -> V_132 ) {
F_37 ( 10 ) ;
if ( V_127 ++ > 500 ) {
F_30 ( V_18 ,
V_133 , V_134 ,
L_32
L_33 ) ;
break;
}
}
}
F_34 ( & V_122 ) ;
V_128 = F_35 ( V_18 , & V_86 , & V_122 , type ) ;
if ( V_128 == 0 )
return - V_101 ;
F_36 ( & V_122 ) ;
if ( V_86 != 0 )
return - V_120 ;
return 0 ;
}
int
F_38 ( struct V_17 * V_18 )
{
struct V_121 V_122 ;
int V_86 = 0 ;
int V_128 ;
if ( ! V_18 -> V_135 )
return - V_136 ;
V_86 = F_33 ( V_18 , V_137 ) ;
if ( V_86 != 0 )
return V_86 ;
F_34 ( & V_122 ) ;
V_128 = F_35 ( V_18 , & V_86 , & V_122 ,
V_138 ) ;
if ( V_128 == 0 )
return - V_101 ;
F_36 ( & V_122 ) ;
if ( V_86 != 0 )
return - V_120 ;
return 0 ;
}
static T_1
F_39 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_85 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_86 = - V_87 ;
if ( ! V_18 -> V_135 )
return - V_136 ;
if ( strncmp ( V_9 , L_34 , sizeof( L_34 ) - 1 ) == 0 )
V_86 = V_18 -> F_38 ( V_18 ) ;
if ( V_86 == 0 )
return strlen ( V_9 ) ;
else
return V_86 ;
}
int
F_40 ( struct V_17 * V_18 )
{
struct V_139 V_140 = { 0 } ;
int V_3 ;
F_37 ( 100 ) ;
F_41 ( V_18 -> V_42 . V_102 . V_141 . V_142 ,
& V_140 . V_143 ) ;
if ( ! F_42 ( V_144 , & V_140 ) &&
! F_42 ( V_145 , & V_140 ) )
return - V_98 ;
for ( V_3 = 0 ; V_3 < V_146 ; V_3 ++ ) {
F_37 ( 10 ) ;
F_41 ( V_18 -> V_42 . V_102 . V_141 . V_142 ,
& V_140 . V_143 ) ;
if ( ! F_42 ( V_145 , & V_140 ) )
continue;
if ( ! F_42 ( V_144 , & V_140 ) )
continue;
if ( ! F_42 ( V_147 , & V_140 ) )
continue;
break;
}
if ( V_3 < V_146 )
return 0 ;
else
return - V_120 ;
}
static T_1
F_43 ( struct V_17 * V_18 , T_2 V_148 )
{
struct V_121 V_122 ;
struct V_149 * V_150 = V_18 -> V_151 ;
T_2 V_152 ;
T_2 V_153 ;
T_2 V_154 ;
int V_86 = 0 , V_128 = 0 ;
int V_155 = 1 , V_156 ;
if ( ! V_18 -> V_135 )
return - V_136 ;
if ( ( V_18 -> V_44 < V_45 ) ||
( F_42 ( V_157 , & V_18 -> V_42 . V_158 ) !=
V_159 ) )
return - V_98 ;
V_152 = V_18 -> V_160 -> V_76 ;
V_153 = V_18 -> V_161 ;
if ( V_18 -> V_161 ) {
F_44 ( V_150 ) ;
V_18 -> V_161 = 0 ;
}
V_86 = F_33 ( V_18 , V_137 ) ;
if ( V_86 != 0 )
return V_86 ;
F_37 ( 100 ) ;
V_154 = F_45 ( V_18 -> V_42 . V_162 +
V_163 ) ;
if ( V_148 == V_164 )
V_154 |= V_165 ;
else if ( V_148 == V_166 )
V_154 |= V_167 ;
else if ( V_148 == V_168 )
V_154 |= V_169 ;
F_46 ( V_154 , V_18 -> V_42 . V_162 +
V_163 ) ;
F_45 ( V_18 -> V_42 . V_162 + V_163 ) ;
V_128 = F_40 ( V_18 ) ;
if ( V_128 == - V_98 ) {
F_30 ( V_18 , V_116 , V_118 ,
L_35
L_36 , V_154 ) ;
} else if ( V_128 == - V_120 ) {
F_30 ( V_18 , V_116 , V_118 ,
L_37
L_36 , V_154 ) ;
return V_128 ;
}
if ( V_152 & V_96 )
goto V_170;
F_34 ( & V_122 ) ;
V_155 = F_35 ( V_18 , & V_86 , & V_122 ,
V_138 ) ;
if ( ! V_155 )
goto V_170;
F_36 ( & V_122 ) ;
V_170:
if ( V_153 ) {
V_156 =
F_47 ( V_18 , V_153 ) ;
if ( ! V_156 )
V_18 -> V_161 = V_153 ;
}
if ( ! V_128 ) {
if ( ! V_155 )
V_128 = - V_101 ;
else if ( V_86 )
V_128 = - V_120 ;
}
return V_128 ;
}
static T_1
F_48 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_171 ) ;
}
static T_1
F_49 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
char * V_172 ;
if ( V_18 -> V_51 == V_57 )
V_172 = L_38 ;
else if ( V_18 -> V_51 == V_53 )
V_172 = L_39 ;
else if ( V_18 -> V_51 == V_54 )
V_172 = L_40 ;
else
V_172 = L_41 ;
return snprintf ( V_9 , V_10 , L_8 , V_172 ) ;
}
static T_1
F_50 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_85 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_121 V_122 ;
char * V_173 = NULL ;
int V_86 = 0 ;
int V_128 ;
if ( ! V_18 -> V_135 ) {
V_86 = - V_136 ;
goto V_174;
}
F_51 ( V_15 , V_116 , V_134 ,
L_42 , V_9 ) ;
F_34 ( & V_122 ) ;
if( strncmp ( V_9 , L_41 , sizeof( L_41 ) - 1 ) == 0 ) {
V_128 = F_35 ( V_18 , & V_86 , & V_122 ,
V_138 ) ;
if ( V_128 == 0 ) {
V_86 = - V_101 ;
goto V_174;
}
F_36 ( & V_122 ) ;
} else if ( strncmp ( V_9 , L_40 , sizeof( L_40 ) - 1 ) == 0 )
V_86 = F_33 ( V_18 , V_137 ) ;
else if ( strncmp ( V_9 , L_43 , sizeof( L_43 ) - 1 ) == 0 )
if ( V_18 -> V_44 == V_45 )
V_86 = - V_87 ;
else
V_86 = F_33 ( V_18 , V_175 ) ;
else if ( strncmp ( V_9 , L_38 , sizeof( L_38 ) - 1 ) == 0 )
if ( V_18 -> V_44 == V_45 )
V_86 = - V_87 ;
else
V_86 = F_33 ( V_18 , V_176 ) ;
else if ( strncmp ( V_9 , L_44 , sizeof( L_44 ) - 1 ) == 0 )
V_86 = F_43 ( V_18 , V_164 ) ;
else if ( strncmp ( V_9 , L_45 , sizeof( L_45 ) - 1 ) == 0 )
V_86 = F_43 ( V_18 , V_166 ) ;
else if ( strncmp ( V_9 , L_46 , sizeof( L_46 ) - 1 ) == 0 )
V_86 = F_43 ( V_18 , V_168 ) ;
else
V_86 = - V_87 ;
V_174:
if ( ! V_86 )
return strlen ( V_9 ) ;
else {
V_173 = strchr ( V_9 , '\n' ) ;
if ( V_173 )
* V_173 = '\0' ;
F_51 ( V_15 , V_116 , V_134 ,
L_47
L_48 ,
V_9 , V_86 , V_18 -> V_160 -> V_76 ) ;
return V_86 ;
}
}
static int
F_52 ( struct V_17 * V_18 ,
T_2 * V_177 , T_2 * V_178 ,
T_2 * V_179 , T_2 * V_180 ,
T_2 * V_181 , T_2 * V_182 )
{
struct V_183 * V_184 ;
T_6 * V_93 ;
T_7 * V_185 ;
int V_128 = 0 ;
T_2 V_186 ;
if ( V_18 -> V_51 < V_56 ||
! V_18 -> V_99 ||
( V_18 -> V_33 . V_34 & V_187 ) == 0 )
return 0 ;
if ( V_18 -> V_33 . V_34 & V_97 )
return 0 ;
V_93 = F_27 ( V_18 -> V_99 , V_100 ) ;
if ( ! V_93 )
return 0 ;
memset ( V_93 , 0 , sizeof ( T_6 ) ) ;
V_185 = & V_93 -> V_102 . V_103 ;
V_185 -> V_104 = V_188 ;
V_185 -> V_106 = V_107 ;
V_93 -> V_189 = NULL ;
if ( V_18 -> V_160 -> V_76 & V_96 )
V_128 = V_190 ;
else
V_128 = F_28 ( V_18 , V_93 , V_18 -> V_114 * 2 ) ;
if ( V_128 != V_109 ) {
if ( V_128 != V_119 )
F_32 ( V_93 , V_18 -> V_99 ) ;
return 0 ;
}
if ( V_18 -> V_44 == V_45 ) {
V_184 = & V_93 -> V_102 . V_191 . V_192 . V_184 ;
if ( V_179 )
* V_179 = F_42 ( V_193 , V_184 ) ;
if ( V_180 )
* V_180 = F_42 ( V_193 , V_184 ) -
V_18 -> V_42 . V_194 . V_195 ;
if ( V_177 )
* V_177 = F_42 ( V_196 , V_184 ) ;
if ( V_178 )
* V_178 = F_42 ( V_196 , V_184 ) -
V_18 -> V_42 . V_194 . V_197 ;
V_186 = ( F_42 ( V_198 , V_184 ) > 0 ) ?
( F_42 ( V_198 , V_184 ) - 1 ) : 0 ;
if ( V_181 )
* V_181 = V_186 ;
if ( V_182 )
* V_182 = V_186 - V_18 -> V_42 . V_194 . V_199 ;
} else {
if ( V_179 )
* V_179 = V_185 -> V_192 . V_200 . V_201 ;
if ( V_180 )
* V_180 = V_185 -> V_192 . V_200 . V_202 ;
if ( V_177 )
* V_177 = V_185 -> V_192 . V_200 . V_203 ;
if ( V_178 )
* V_178 = V_185 -> V_192 . V_200 . V_204 ;
if ( V_181 )
* V_181 = V_185 -> V_192 . V_200 . V_186 ;
if ( V_182 )
* V_182 = V_185 -> V_192 . V_200 . V_205 ;
}
F_32 ( V_93 , V_18 -> V_99 ) ;
return 1 ;
}
static T_1
F_53 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_127 ;
if ( F_52 ( V_18 , NULL , NULL , & V_127 , NULL , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_9 , V_127 ) ;
return snprintf ( V_9 , V_10 , L_19 ) ;
}
static T_1
F_54 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_127 , V_206 ;
if ( F_52 ( V_18 , NULL , NULL , & V_127 , & V_206 , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_9 , ( V_127 - V_206 ) ) ;
return snprintf ( V_9 , V_10 , L_19 ) ;
}
static T_1
F_55 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_127 ;
if ( F_52 ( V_18 , & V_127 , NULL , NULL , NULL , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_9 , V_127 ) ;
return snprintf ( V_9 , V_10 , L_19 ) ;
}
static T_1
F_56 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_127 , V_206 ;
if ( F_52 ( V_18 , & V_127 , & V_206 , NULL , NULL , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_9 , ( V_127 - V_206 ) ) ;
return snprintf ( V_9 , V_10 , L_19 ) ;
}
static T_1
F_57 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_127 ;
if ( F_52 ( V_18 , NULL , NULL , NULL , NULL , & V_127 , NULL ) )
return snprintf ( V_9 , V_10 , L_9 , V_127 ) ;
return snprintf ( V_9 , V_10 , L_19 ) ;
}
static T_1
F_58 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_127 , V_206 ;
if ( F_52 ( V_18 , NULL , NULL , NULL , NULL , & V_127 , & V_206 ) )
return snprintf ( V_9 , V_10 , L_9 , ( V_127 - V_206 ) ) ;
return snprintf ( V_9 , V_10 , L_19 ) ;
}
static T_1
F_59 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( ! ( V_18 -> V_186 ) )
return snprintf ( V_9 , V_10 , L_49 ) ;
if ( V_15 -> V_207 == V_208 )
return snprintf ( V_9 , V_10 , L_50 ) ;
return snprintf ( V_9 , V_10 , L_51 , V_15 -> V_209 ) ;
}
static T_1
F_60 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_52 , V_18 -> V_210 ) ;
}
static T_1
F_61 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_85 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_211 ;
T_2 V_212 ;
int V_213 = 0 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_87 ;
if ( sscanf ( V_9 , L_53 , & V_213 ) != 1 )
return - V_87 ;
if ( ( V_213 & 0x3 ) != V_213 )
return - V_87 ;
if ( V_18 -> V_44 == V_45 )
V_213 = 0 ;
F_51 ( V_15 , V_116 , V_134 ,
L_54 ,
V_18 -> V_210 , V_213 ) ;
F_62 ( & V_18 -> V_214 ) ;
V_212 = V_18 -> V_210 ;
if ( V_213 & V_215 ) {
if ( ( V_213 & V_216 ) &&
! ( V_212 & V_216 ) ) {
if ( F_41 ( V_18 -> V_217 , & V_211 ) ) {
F_63 ( & V_18 -> V_214 ) ;
return - V_87 ;
}
V_211 &= ~ ( V_218 << V_219 ) ;
F_46 ( V_211 , V_18 -> V_217 ) ;
F_45 ( V_18 -> V_217 ) ;
F_64 ( V_18 ) ;
}
} else if ( V_213 != 0x0 ) {
F_63 ( & V_18 -> V_214 ) ;
return - V_87 ;
}
if ( ! ( V_213 & V_216 ) &&
( V_212 & V_216 ) )
{
F_63 ( & V_18 -> V_214 ) ;
F_65 ( & V_18 -> V_220 ) ;
F_62 ( & V_18 -> V_214 ) ;
if ( F_41 ( V_18 -> V_217 , & V_211 ) ) {
F_63 ( & V_18 -> V_214 ) ;
return - V_87 ;
}
V_211 |= ( V_218 << V_219 ) ;
F_46 ( V_211 , V_18 -> V_217 ) ;
F_45 ( V_18 -> V_217 ) ;
}
V_18 -> V_210 = V_213 ;
F_63 ( & V_18 -> V_214 ) ;
return strlen ( V_9 ) ;
}
static T_1
F_66 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_221 ) ;
}
static T_1
F_67 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_222 ) ;
}
static T_1
F_68 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_55 ,
( V_18 -> V_223 ) ? L_56 : L_57 ,
( V_18 -> V_22 & V_224 ) ?
L_58 : L_59 ) ;
}
static T_1
F_69 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_8 V_225 ;
V_225 = F_70 ( V_18 ) ;
return snprintf ( V_9 , V_10 , L_9 , V_225 ) ;
}
static T_1
F_71 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_85 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
unsigned int V_127 = V_85 ;
if ( V_9 [ V_127 - 1 ] == '\n' )
V_127 -- ;
if ( ( V_127 != strlen ( V_226 ) ) ||
( strncmp ( V_9 , V_226 , strlen ( V_226 ) ) != 0 ) )
return - V_87 ;
V_18 -> V_227 = 1 ;
return V_85 ;
}
static T_1
F_72 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_60 ,
( unsigned long long ) V_18 -> V_228 ) ;
}
static T_1
F_73 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_85 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_121 V_122 ;
int V_229 = 0 , V_230 = 0 ;
unsigned int V_3 , V_4 , V_127 = V_85 ;
T_9 V_231 [ 8 ] ;
int V_128 ;
if ( ! V_18 -> V_135 )
return - V_136 ;
F_62 ( & V_18 -> V_214 ) ;
if ( V_18 -> V_232 == V_233 ) {
F_63 ( & V_18 -> V_214 ) ;
return - V_136 ;
}
F_63 ( & V_18 -> V_214 ) ;
if ( V_9 [ V_127 - 1 ] == '\n' )
V_127 -- ;
if ( ! V_18 -> V_227 || ( V_127 < 16 ) || ( V_127 > 18 ) ||
( ( V_127 == 17 ) && ( * V_9 ++ != 'x' ) ) ||
( ( V_127 == 18 ) && ( ( * V_9 ++ != '0' ) || ( * V_9 ++ != 'x' ) ) ) )
return - V_87 ;
V_18 -> V_227 = 0 ;
memset ( V_231 , 0 , sizeof( V_231 ) ) ;
for ( V_3 = 0 , V_4 = 0 ; V_3 < 16 ; V_3 ++ ) {
int V_234 ;
V_234 = F_74 ( * V_9 ++ ) ;
if ( V_234 >= 0 )
V_4 = ( V_4 << 4 ) | V_234 ;
else
return - V_87 ;
if ( V_3 % 2 ) {
V_231 [ V_3 / 2 ] = V_4 & 0xff ;
V_4 = 0 ;
}
}
V_18 -> V_228 = F_75 ( V_231 ) ;
F_76 ( V_13 ) = V_18 -> V_228 ;
if ( V_18 -> V_235 )
F_77 ( V_13 ) = V_18 -> V_235 ;
F_78 ( V_236 , & V_18 -> V_151 -> V_6 ,
L_61 , V_18 -> V_237 ) ;
V_229 = F_33 ( V_18 , V_137 ) ;
if ( V_229 )
F_30 ( V_18 , V_116 , V_134 ,
L_62
L_63 , V_229 ) ;
F_34 ( & V_122 ) ;
V_128 = F_35 ( V_18 , & V_230 , & V_122 ,
V_138 ) ;
if ( V_128 == 0 )
return - V_101 ;
F_36 ( & V_122 ) ;
if ( V_230 )
F_30 ( V_18 , V_116 , V_134 ,
L_64
L_63 , V_230 ) ;
return ( V_229 || V_230 ) ? - V_120 : V_85 ;
}
static T_1
F_79 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_60 ,
( unsigned long long ) V_18 -> V_235 ) ;
}
static T_1
F_80 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_85 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
unsigned int V_3 , V_4 , V_127 = V_85 ;
T_9 V_238 [ 8 ] ;
if ( V_9 [ V_127 - 1 ] == '\n' )
V_127 -- ;
if ( ! V_18 -> V_227 || ( V_127 < 16 ) || ( V_127 > 18 ) ||
( ( V_127 == 17 ) && ( * V_9 ++ != 'x' ) ) ||
( ( V_127 == 18 ) && ( ( * V_9 ++ != '0' ) || ( * V_9 ++ != 'x' ) ) ) )
return - V_87 ;
memset ( V_238 , 0 , sizeof( V_238 ) ) ;
for ( V_3 = 0 , V_4 = 0 ; V_3 < 16 ; V_3 ++ ) {
int V_234 ;
V_234 = F_74 ( * V_9 ++ ) ;
if ( V_234 >= 0 )
V_4 = ( V_4 << 4 ) | V_234 ;
else
return - V_87 ;
if ( V_3 % 2 ) {
V_238 [ V_3 / 2 ] = V_4 & 0xff ;
V_4 = 0 ;
}
}
V_18 -> V_235 = F_75 ( V_238 ) ;
F_78 ( V_236 , & V_18 -> V_151 -> V_6 ,
L_65
L_66 , V_18 -> V_237 ) ;
return V_85 ;
}
static T_1
F_81 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_239 ) ;
}
static T_1
F_82 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 ,
V_18 -> V_33 . V_131 [ V_240 ] . V_241 ) ;
}
static T_1
F_83 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 ,
V_18 -> V_33 . V_131 [ V_240 ] . V_242 ) ;
}
static T_1
F_84 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
return snprintf ( V_9 , V_10 , L_9 , V_15 -> V_243 ) ;
}
static int
F_85 ( struct V_14 * V_15 , int V_213 )
{
if ( V_15 -> V_243 != V_244 ) {
V_15 -> V_245 = V_15 -> V_243 ;
if ( V_213 != V_244 )
F_51 ( V_15 , V_116 , V_134 ,
L_67
L_68
L_69 ) ;
return 0 ;
}
if ( V_213 >= V_246 && V_213 <= V_247 ) {
V_15 -> V_245 = V_213 ;
V_15 -> V_243 = V_213 ;
return 0 ;
}
F_51 ( V_15 , V_116 , V_134 ,
L_70
L_71 ,
V_213 , V_246 , V_247 ) ;
V_15 -> V_245 = V_244 ;
return - V_87 ;
}
static void
F_86 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
struct V_248 * V_249 ;
V_13 = F_87 ( V_15 ) ;
F_62 ( V_13 -> V_250 ) ;
F_88 (ndlp, &vport->fc_nodes, nlp_listp)
if ( F_89 ( V_249 ) && V_249 -> V_251 )
V_249 -> V_251 -> V_252 = V_15 -> V_243 ;
F_63 ( V_13 -> V_250 ) ;
}
static int
F_90 ( struct V_14 * V_15 , int V_213 )
{
if ( V_15 -> V_253 ||
( V_254 != V_244 ) ) {
F_51 ( V_15 , V_116 , V_134 ,
L_72
L_73 ) ;
return 0 ;
}
if ( V_213 >= V_246 && V_213 <= V_247 ) {
V_15 -> V_245 = V_213 ;
V_15 -> V_243 = V_213 ;
F_91 ( F_87 ( V_15 ) ) = V_213 ;
F_86 ( V_15 ) ;
return 0 ;
}
F_51 ( V_15 , V_116 , V_134 ,
L_74
L_75 ,
V_213 , V_246 , V_247 ) ;
return - V_87 ;
}
static int
F_92 ( struct V_14 * V_15 , int V_213 )
{
if ( V_213 >= V_246 && V_213 <= V_247 ) {
V_15 -> V_245 = V_213 ;
V_15 -> V_243 = V_213 ;
V_15 -> V_253 = 1 ;
F_91 ( F_87 ( V_15 ) ) = V_213 ;
F_86 ( V_15 ) ;
return 0 ;
}
F_51 ( V_15 , V_116 , V_134 ,
L_76
L_71 ,
V_213 , V_246 , V_247 ) ;
return - V_87 ;
}
static int
F_93 ( struct V_14 * V_15 , int V_213 )
{
if ( V_213 < 0 || V_213 > 1 ) {
F_51 ( V_15 , V_116 , V_134 ,
L_77
L_78 ,
V_213 ) ;
V_15 -> V_255 = 1 ;
return - V_87 ;
}
if ( V_15 -> V_207 == V_208 ) {
V_15 -> V_255 = 0 ;
return 0 ;
}
V_15 -> V_255 = V_213 ;
return 0 ;
}
static int
F_94 ( struct V_14 * V_15 , int V_213 )
{
if ( V_213 < 0 || V_213 > 1 ) {
F_51 ( V_15 , V_116 , V_134 ,
L_79
L_78 ,
V_213 ) ;
V_15 -> V_255 = 1 ;
return - V_87 ;
}
if ( V_15 -> V_207 == V_208 && V_213 != 0 ) {
F_51 ( V_15 , V_116 , V_134 ,
L_80
L_81 ) ;
V_15 -> V_255 = 0 ;
return 0 ;
}
V_15 -> V_255 = V_213 ;
return 0 ;
}
static T_1
F_95 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_85 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_213 = 0 ;
int V_256 = 0 ;
const char * V_257 = V_9 ;
int V_258 ;
T_2 V_259 ;
if ( ! strncmp ( V_9 , L_82 , strlen ( L_82 ) ) ) {
V_256 = 1 ;
V_257 = & V_9 [ strlen ( L_82 ) ] ;
}
if ( ! isdigit ( V_257 [ 0 ] ) )
return - V_87 ;
if ( sscanf ( V_257 , L_53 , & V_213 ) != 1 )
return - V_87 ;
if ( V_213 >= 0 && V_213 <= 6 ) {
V_259 = V_18 -> V_112 ;
V_18 -> V_112 = V_213 ;
if ( V_18 -> V_113 == V_260 &&
V_213 == 4 ) {
F_51 ( V_15 , V_116 , V_134 ,
L_83 ,
V_18 -> V_113 ) ;
V_18 -> V_112 = V_259 ;
return - V_87 ;
}
if ( V_256 )
return strlen ( V_9 ) ;
F_51 ( V_15 , V_116 , V_134 ,
L_84 ,
V_259 , V_213 ) ;
V_258 = F_26 ( F_87 ( V_18 -> V_160 ) ) ;
if ( V_258 ) {
V_18 -> V_112 = V_259 ;
return - V_87 ;
} else
return strlen ( V_9 ) ;
}
F_30 ( V_18 , V_116 , V_134 ,
L_85
L_86 ,
V_18 -> V_237 , V_213 ) ;
return - V_87 ;
}
static T_1
F_96 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
if ( V_15 -> V_261 & V_262 )
sprintf ( V_9 , L_2 ) ;
else
sprintf ( V_9 , L_3 ) ;
return strlen ( V_9 ) ;
}
static T_1
F_97 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_85 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
#define F_98 1024
static char V_263 [ F_98 ] ;
unsigned long V_3 ;
char * V_264 , * V_265 ;
struct V_14 * * V_266 ;
struct V_12 * V_267 ;
char * V_268 , * V_269 , * V_270 ;
unsigned long V_271 , V_272 , V_273 ;
if ( ! strncmp ( V_9 , L_87 , strlen ( L_87 ) ) ) {
if ( strlen ( V_9 ) > ( F_98 - 1 ) )
return - V_87 ;
strcpy ( V_263 , V_9 ) ;
V_264 = & V_263 [ 0 ] ;
V_265 = F_99 ( & V_264 , L_88 ) ;
if ( ! V_265 )
return - V_87 ;
V_268 = F_99 ( & V_264 , L_88 ) ;
if ( ! V_268 )
return - V_87 ;
if ( ! strncmp ( V_268 , L_89 , strlen ( L_89 ) ) )
V_273 = V_274 ;
else if ( ! strncmp ( V_268 , L_90 , strlen ( L_90 ) ) )
V_273 = V_275 ;
else
return - V_87 ;
V_269 = F_99 ( & V_264 , L_88 ) ;
if ( ! V_269 )
return - V_87 ;
V_271 = F_100 ( V_269 , NULL , 0 ) ;
V_270 = F_99 ( & V_264 , L_88 ) ;
if ( ! V_270 )
return - V_87 ;
V_272 = F_100 ( V_270 , NULL , 0 ) ;
if ( ! V_272 )
return - V_87 ;
V_266 = F_101 ( V_18 ) ;
if ( V_266 == NULL )
return - V_101 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_276 && V_266 [ V_3 ] != NULL ; V_3 ++ ) {
V_267 = F_87 ( V_266 [ V_3 ] ) ;
F_62 ( V_267 -> V_250 ) ;
V_266 [ V_3 ] -> V_277 = 1 ;
if ( V_266 [ V_3 ] -> V_278 )
F_102 ( V_266 [ V_3 ] ) ;
F_63 ( V_267 -> V_250 ) ;
}
V_18 -> V_273 = V_273 ;
V_18 -> V_279 = V_271 ;
V_18 -> V_280 = V_272 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_276 && V_266 [ V_3 ] != NULL ; V_3 ++ ) {
V_267 = F_87 ( V_266 [ V_3 ] ) ;
F_62 ( V_267 -> V_250 ) ;
V_266 [ V_3 ] -> V_277 = 0 ;
F_63 ( V_267 -> V_250 ) ;
}
F_103 ( V_18 , V_266 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_91 , strlen ( L_91 ) ) ) {
V_266 = F_101 ( V_18 ) ;
if ( V_266 == NULL )
return - V_101 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_276 && V_266 [ V_3 ] != NULL ; V_3 ++ ) {
V_267 = F_87 ( V_266 [ V_3 ] ) ;
F_62 ( V_13 -> V_250 ) ;
V_266 [ V_3 ] -> V_277 = 1 ;
F_104 ( V_15 ) ;
V_15 -> V_278 = 0 ;
V_266 [ V_3 ] -> V_277 = 0 ;
F_63 ( V_13 -> V_250 ) ;
}
F_103 ( V_18 , V_266 ) ;
V_18 -> V_273 = V_281 ;
V_18 -> V_279 = 0 ;
V_18 -> V_280 = 0 ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_92 , strlen ( L_92 ) ) ) {
if ( V_18 -> V_273 == V_281 )
return - V_87 ;
F_62 ( V_13 -> V_250 ) ;
if ( V_15 -> V_278 ) {
F_63 ( V_13 -> V_250 ) ;
return strlen ( V_9 ) ;
}
F_105 ( V_15 ) ;
V_15 -> V_278 = 1 ;
F_63 ( V_13 -> V_250 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_93 , strlen ( L_93 ) ) ) {
F_62 ( V_13 -> V_250 ) ;
if ( V_15 -> V_278 == 0 ) {
F_63 ( V_13 -> V_250 ) ;
return strlen ( V_9 ) ;
}
F_104 ( V_15 ) ;
V_15 -> V_278 = 0 ;
F_63 ( V_13 -> V_250 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_94 , strlen ( L_94 ) ) ) {
if ( ( V_18 -> V_273 == V_281 )
|| ! V_15 -> V_278 )
return strlen ( V_9 ) ;
F_62 ( V_13 -> V_250 ) ;
V_15 -> V_277 = 1 ;
F_102 ( V_15 ) ;
V_15 -> V_277 = 0 ;
F_63 ( V_13 -> V_250 ) ;
return strlen ( V_9 ) ;
}
return - V_87 ;
}
static T_1
F_106 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_282 = 0 ;
int V_3 ;
char * V_273 ;
unsigned long V_283 ;
switch ( V_18 -> V_273 ) {
case V_274 :
V_273 = L_89 ;
break;
case V_275 :
V_273 = L_90 ;
break;
default:
V_273 = L_95 ;
break;
}
sprintf ( & V_9 [ V_282 ] , L_96
L_97
L_98 ,
V_15 -> V_278 , V_15 -> V_277 ,
V_273 , V_18 -> V_279 , V_18 -> V_280 ) ;
V_282 = strlen ( V_9 ) ;
if ( V_18 -> V_273 != V_281 ) {
for ( V_3 = 0 ; V_3 < V_284 ; V_3 ++ ) {
if ( V_18 -> V_273 == V_274 )
V_283 = V_18 -> V_279 +
V_18 -> V_280 * V_3 ;
else
V_283 = V_18 -> V_279 +
( 1 << V_3 ) * V_18 -> V_280 ;
if ( V_282 + 10 > V_10 )
break;
sprintf ( & V_9 [ V_282 ] , L_99 , V_283 ) ;
V_282 = strlen ( V_9 ) ;
}
}
sprintf ( & V_9 [ V_282 ] , L_1 ) ;
return strlen ( V_9 ) ;
}
static T_1
F_107 ( struct V_285 * V_286 , struct V_287 * V_288 ,
struct V_289 * V_290 ,
char * V_9 , T_10 V_291 , T_5 V_85 )
{
struct V_5 * V_6 = F_108 ( V_288 , struct V_5 ,
V_288 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_3 = 0 , V_282 = 0 ;
unsigned long V_292 ;
struct V_248 * V_249 = NULL ;
V_292 = ( unsigned long ) V_291 /
V_293 ;
if ( ! V_15 -> V_278 || V_15 -> V_277
|| ( V_18 -> V_273 == V_281 ) )
return 0 ;
F_62 ( V_13 -> V_250 ) ;
F_88 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_89 ( V_249 ) || ! V_249 -> V_294 )
continue;
if ( V_292 > 0 ) {
V_292 -- ;
continue;
}
if ( ( V_282 + V_293 )
> V_85 )
break;
if ( ! V_249 -> V_294 )
continue;
sprintf ( & V_9 [ V_282 ] , L_100 ,
V_249 -> V_295 . V_102 . V_296 [ 0 ] ,
V_249 -> V_295 . V_102 . V_296 [ 1 ] ,
V_249 -> V_295 . V_102 . V_296 [ 2 ] ,
V_249 -> V_295 . V_102 . V_296 [ 3 ] ,
V_249 -> V_295 . V_102 . V_296 [ 4 ] ,
V_249 -> V_295 . V_102 . V_296 [ 5 ] ,
V_249 -> V_295 . V_102 . V_296 [ 6 ] ,
V_249 -> V_295 . V_102 . V_296 [ 7 ] ) ;
V_282 = strlen ( V_9 ) ;
for ( V_3 = 0 ; V_3 < V_284 ; V_3 ++ ) {
sprintf ( & V_9 [ V_282 ] , L_101 ,
V_249 -> V_294 [ V_3 ] . V_297 ) ;
V_282 = strlen ( V_9 ) ;
}
sprintf ( & V_9 [ V_282 ] , L_1 ) ;
V_282 = strlen ( V_9 ) ;
}
F_63 ( V_13 -> V_250 ) ;
return V_282 ;
}
static T_1
F_109 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_85 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_213 = V_298 ;
int V_256 = 0 ;
const char * V_257 = V_9 ;
int V_258 ;
T_2 V_259 ;
if ( ! strncmp ( V_9 , L_82 , strlen ( L_82 ) ) ) {
V_256 = 1 ;
V_257 = & V_9 [ strlen ( L_82 ) ] ;
}
if ( ! isdigit ( V_257 [ 0 ] ) )
return - V_87 ;
if ( sscanf ( V_257 , L_53 , & V_213 ) != 1 )
return - V_87 ;
F_51 ( V_15 , V_116 , V_134 ,
L_102 ,
V_18 -> V_113 , V_213 , V_256 ? L_103 : L_104 ) ;
if ( ( ( V_213 == V_299 ) && ! ( V_18 -> V_300 & V_301 ) ) ||
( ( V_213 == V_302 ) && ! ( V_18 -> V_300 & V_303 ) ) ||
( ( V_213 == V_304 ) && ! ( V_18 -> V_300 & V_305 ) ) ||
( ( V_213 == V_306 ) && ! ( V_18 -> V_300 & V_307 ) ) ||
( ( V_213 == V_308 ) && ! ( V_18 -> V_300 & V_309 ) ) ||
( ( V_213 == V_260 ) && ! ( V_18 -> V_300 & V_310 ) ) ) {
F_30 ( V_18 , V_116 , V_134 ,
L_105
L_106 ,
V_213 ) ;
return - V_87 ;
}
if ( V_213 == V_260 &&
V_18 -> V_74 == V_75 ) {
F_30 ( V_18 , V_116 , V_134 ,
L_107
L_108 ,
V_213 ) ;
return - V_87 ;
}
if ( ( V_213 >= 0 ) && ( V_213 <= V_311 ) &&
( V_312 & ( 1 << V_213 ) ) ) {
V_259 = V_18 -> V_113 ;
V_18 -> V_113 = V_213 ;
if ( V_256 )
return strlen ( V_9 ) ;
V_258 = F_26 ( F_87 ( V_18 -> V_160 ) ) ;
if ( V_258 ) {
V_18 -> V_113 = V_259 ;
return - V_87 ;
} else
return strlen ( V_9 ) ;
}
F_30 ( V_18 , V_116 , V_134 ,
L_109
L_110 V_313 L_111 , V_213 ) ;
return - V_87 ;
}
static int
F_110 ( struct V_17 * V_18 , int V_213 )
{
if ( V_213 == V_260 && V_18 -> V_112 == 4 ) {
F_30 ( V_18 , V_116 , V_134 ,
L_112
L_113 ,
V_213 ) ;
V_18 -> V_112 = 0 ;
}
if ( ( V_213 >= 0 ) && ( V_213 <= V_311 ) &&
( V_312 & ( 1 << V_213 ) ) ) {
V_18 -> V_113 = V_213 ;
return 0 ;
}
F_30 ( V_18 , V_116 , V_134 ,
L_114
L_115
L_116 V_313 L_111 , V_213 ) ;
V_18 -> V_113 = V_298 ;
return - V_87 ;
}
static T_1
F_111 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_85 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_213 = 0 , V_128 = - V_87 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_87 ;
if ( sscanf ( V_9 , L_53 , & V_213 ) != 1 )
return - V_87 ;
switch ( V_213 ) {
case 0 :
if ( V_18 -> V_19 & V_314 ) {
V_128 = F_112 ( V_18 -> V_151 ) ;
if ( ! V_128 ) {
F_62 ( & V_18 -> V_214 ) ;
V_18 -> V_19 &= ~ V_314 ;
F_63 ( & V_18 -> V_214 ) ;
V_18 -> V_315 = 0 ;
V_128 = strlen ( V_9 ) ;
} else
V_128 = - V_98 ;
} else {
V_18 -> V_315 = 0 ;
V_128 = strlen ( V_9 ) ;
}
break;
case 1 :
if ( ! ( V_18 -> V_19 & V_314 ) ) {
V_128 = F_113 ( V_18 -> V_151 ) ;
if ( ! V_128 ) {
F_62 ( & V_18 -> V_214 ) ;
V_18 -> V_19 |= V_314 ;
F_63 ( & V_18 -> V_214 ) ;
V_18 -> V_315 = 1 ;
V_128 = strlen ( V_9 ) ;
} else
V_128 = - V_98 ;
} else {
V_18 -> V_315 = 1 ;
V_128 = strlen ( V_9 ) ;
}
break;
default:
V_128 = - V_87 ;
break;
}
return V_128 ;
}
static int
F_114 ( struct V_17 * V_18 , int V_213 )
{
if ( V_213 == 0 || V_213 == 1 ) {
V_18 -> V_315 = V_213 ;
return 0 ;
}
F_30 ( V_18 , V_116 , V_134 ,
L_117
L_118
L_119 , V_213 ) ;
V_18 -> V_315 = 1 ;
return - V_87 ;
}
static T_1
F_115 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_85 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_213 , V_128 = - 1 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_87 ;
if ( sscanf ( V_9 , L_53 , & V_213 ) != 1 )
return - V_87 ;
if ( V_213 != 1 )
return - V_87 ;
if ( V_18 -> V_19 & V_314 )
V_128 = F_116 ( V_18 -> V_151 ) ;
if ( V_128 == 0 )
return strlen ( V_9 ) ;
else
return - V_98 ;
}
static T_1
F_117 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_85 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_149 * V_150 = V_18 -> V_151 ;
int V_213 = 0 , V_128 = - V_87 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_87 ;
if ( sscanf ( V_9 , L_53 , & V_213 ) != 1 )
return - V_87 ;
if ( V_213 < 0 )
return - V_87 ;
if ( V_213 == 0 ) {
if ( V_18 -> V_161 > 0 ) {
F_44 ( V_150 ) ;
V_18 -> V_161 = 0 ;
}
return strlen ( V_9 ) ;
}
if ( V_18 -> V_161 > 0 ) {
F_30 ( V_18 , V_116 , V_134 ,
L_120
L_121 ,
V_18 -> V_161 ) ;
return - V_316 ;
}
if ( V_213 <= V_317 )
V_18 -> V_161 = V_213 ;
else {
F_30 ( V_18 , V_116 , V_134 ,
L_122
L_123 , V_213 ) ;
return - V_87 ;
}
V_128 = F_47 ( V_18 , V_18 -> V_161 ) ;
if ( V_128 ) {
V_18 -> V_161 = 0 ;
V_128 = - V_98 ;
} else
V_128 = strlen ( V_9 ) ;
return V_128 ;
}
static int
F_118 ( struct V_17 * V_18 , int V_213 )
{
if ( V_213 >= 0 && V_213 <= V_317 ) {
V_18 -> V_161 = V_213 ;
return 0 ;
}
F_30 ( V_18 , V_116 , V_134 ,
L_124
L_123 , V_213 ) ;
return - V_87 ;
}
static int
F_119 ( struct V_14 * V_15 , int V_213 )
{
struct V_12 * V_13 = F_87 ( V_15 ) ;
struct V_248 * V_249 , * V_318 ;
if ( V_213 == V_15 -> V_319 )
return 0 ;
if ( ( V_213 < 0 ) || ( V_213 > 60000 ) )
return - V_87 ;
V_15 -> V_319 = V_213 ;
F_62 ( V_13 -> V_250 ) ;
F_120 (ndlp, next_ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_89 ( V_249 ) )
continue;
if ( V_249 -> V_320 == V_321 )
continue;
V_249 -> V_322 = V_15 -> V_323 ;
}
F_63 ( V_13 -> V_250 ) ;
return 0 ;
}
static T_1
F_121 ( struct V_285 * V_286 , struct V_287 * V_288 ,
struct V_289 * V_290 ,
char * V_9 , T_10 V_291 , T_5 V_85 )
{
T_5 V_324 ;
struct V_5 * V_6 = F_108 ( V_288 , struct V_5 , V_288 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_44 >= V_45 )
return - V_98 ;
if ( ( V_291 + V_85 ) > V_325 )
return - V_326 ;
if ( V_85 <= V_327 )
return 0 ;
if ( V_291 % 4 || V_85 % 4 || ( unsigned long ) V_9 % 4 )
return - V_87 ;
if ( memcmp ( V_9 , V_328 , V_327 ) )
return - V_87 ;
if ( ! ( V_15 -> V_76 & V_96 ) )
return - V_98 ;
F_62 ( & V_18 -> V_214 ) ;
for ( V_324 = 0 ; V_324 < V_85 - V_327 ;
V_324 += sizeof( T_2 ) )
F_46 ( * ( ( T_2 * ) ( V_9 + V_324 + V_327 ) ) ,
V_18 -> V_329 + V_291 + V_324 ) ;
F_63 ( & V_18 -> V_214 ) ;
return V_85 ;
}
static T_1
F_122 ( struct V_285 * V_286 , struct V_287 * V_288 ,
struct V_289 * V_290 ,
char * V_9 , T_10 V_291 , T_5 V_85 )
{
T_5 V_324 ;
T_2 * V_330 ;
struct V_5 * V_6 = F_108 ( V_288 , struct V_5 , V_288 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_44 >= V_45 )
return - V_98 ;
if ( V_291 > V_325 )
return - V_326 ;
if ( ( V_291 + V_85 ) > V_325 )
V_85 = V_325 - V_291 ;
if ( V_85 == 0 ) return 0 ;
if ( V_291 % 4 || V_85 % 4 || ( unsigned long ) V_9 % 4 )
return - V_87 ;
F_62 ( & V_18 -> V_214 ) ;
for ( V_324 = 0 ; V_324 < V_85 ; V_324 += sizeof( T_2 ) ) {
V_330 = ( T_2 * ) ( V_9 + V_324 ) ;
* V_330 = F_45 ( V_18 -> V_329 + V_291 + V_324 ) ;
}
F_63 ( & V_18 -> V_214 ) ;
return V_85 ;
}
static T_1
F_123 ( struct V_285 * V_286 , struct V_287 * V_288 ,
struct V_289 * V_290 ,
char * V_9 , T_10 V_291 , T_5 V_85 )
{
return - V_98 ;
}
static T_1
F_124 ( struct V_285 * V_286 , struct V_287 * V_288 ,
struct V_289 * V_290 ,
char * V_9 , T_10 V_291 , T_5 V_85 )
{
return - V_98 ;
}
int
F_125 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = F_87 ( V_15 ) ;
int error ;
error = F_126 ( & V_13 -> V_331 . V_288 ,
& V_332 ) ;
if ( error || V_15 -> V_207 == V_333 )
goto V_170;
error = F_126 ( & V_13 -> V_331 . V_288 ,
& V_334 ) ;
if ( error )
goto V_335;
error = F_126 ( & V_13 -> V_331 . V_288 ,
& V_336 ) ;
if ( error )
goto V_337;
return 0 ;
V_337:
F_127 ( & V_13 -> V_331 . V_288 , & V_334 ) ;
V_335:
F_127 ( & V_13 -> V_331 . V_288 ,
& V_332 ) ;
V_170:
return error ;
}
void
F_128 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = F_87 ( V_15 ) ;
F_127 ( & V_13 -> V_331 . V_288 ,
& V_332 ) ;
if ( V_15 -> V_207 == V_333 )
return;
F_127 ( & V_13 -> V_331 . V_288 , & V_336 ) ;
F_127 ( & V_13 -> V_331 . V_288 , & V_334 ) ;
}
static void
F_129 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
F_130 ( V_13 ) = V_15 -> V_338 ;
}
static void
F_131 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_62 ( V_13 -> V_250 ) ;
if ( V_15 -> V_207 == V_333 ) {
F_132 ( V_13 ) = V_339 ;
} else if ( F_133 ( V_18 ) ) {
if ( V_18 -> V_74 == V_75 ) {
if ( V_15 -> V_76 & V_77 )
F_132 ( V_13 ) = V_340 ;
else
F_132 ( V_13 ) = V_341 ;
} else {
if ( V_15 -> V_76 & V_78 )
F_132 ( V_13 ) = V_342 ;
else
F_132 ( V_13 ) = V_343 ;
}
} else
F_132 ( V_13 ) = V_344 ;
F_63 ( V_13 -> V_250 ) ;
}
static void
F_134 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_62 ( V_13 -> V_250 ) ;
if ( V_15 -> V_76 & V_96 )
F_135 ( V_13 ) = V_345 ;
else {
switch ( V_18 -> V_51 ) {
case V_52 :
case V_56 :
F_135 ( V_13 ) = V_346 ;
break;
case V_59 :
case V_60 :
case V_61 :
if ( V_15 -> V_62 < V_71 )
F_135 ( V_13 ) =
V_347 ;
else
F_135 ( V_13 ) =
V_348 ;
break;
case V_57 :
F_135 ( V_13 ) = V_349 ;
break;
default:
F_135 ( V_13 ) = V_350 ;
break;
}
}
F_63 ( V_13 -> V_250 ) ;
}
static void
F_136 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_62 ( V_13 -> V_250 ) ;
if ( F_133 ( V_18 ) ) {
switch( V_18 -> V_351 ) {
case V_352 :
F_137 ( V_13 ) = V_353 ;
break;
case V_354 :
F_137 ( V_13 ) = V_355 ;
break;
case V_356 :
F_137 ( V_13 ) = V_357 ;
break;
case V_358 :
F_137 ( V_13 ) = V_359 ;
break;
case V_360 :
F_137 ( V_13 ) = V_361 ;
break;
case V_362 :
F_137 ( V_13 ) = V_363 ;
break;
default:
F_137 ( V_13 ) = V_364 ;
break;
}
} else
F_137 ( V_13 ) = V_364 ;
F_63 ( V_13 -> V_250 ) ;
}
static void
F_138 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_11 V_365 ;
F_62 ( V_13 -> V_250 ) ;
if ( ( V_15 -> V_62 > V_65 ) &&
( ( V_15 -> V_76 & V_78 ) ||
( ( V_18 -> V_74 == V_75 ) &&
( V_15 -> V_76 & V_77 ) ) ) )
V_365 = F_75 ( V_18 -> V_366 . V_367 . V_102 . V_296 ) ;
else
V_365 = 0 ;
F_63 ( V_13 -> V_250 ) ;
F_139 ( V_13 ) = V_365 ;
}
static struct V_368 *
F_140 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_125 * V_126 = & V_18 -> V_33 ;
struct V_368 * V_369 = & V_18 -> V_370 ;
struct V_371 * V_372 = & V_126 -> V_373 ;
T_6 * V_93 ;
T_7 * V_185 ;
unsigned long V_374 ;
int V_128 = 0 ;
if ( V_18 -> V_51 < V_56 ||
! V_18 -> V_99 ||
( V_18 -> V_33 . V_34 & V_187 ) == 0 )
return NULL ;
if ( V_18 -> V_33 . V_34 & V_97 )
return NULL ;
V_93 = F_27 ( V_18 -> V_99 , V_100 ) ;
if ( ! V_93 )
return NULL ;
memset ( V_93 , 0 , sizeof ( T_6 ) ) ;
V_185 = & V_93 -> V_102 . V_103 ;
V_185 -> V_104 = V_375 ;
V_185 -> V_106 = V_107 ;
V_93 -> V_189 = NULL ;
V_93 -> V_15 = V_15 ;
if ( V_15 -> V_76 & V_96 )
V_128 = F_141 ( V_18 , V_93 , V_376 ) ;
else
V_128 = F_28 ( V_18 , V_93 , V_18 -> V_114 * 2 ) ;
if ( V_128 != V_109 ) {
if ( V_128 != V_119 )
F_32 ( V_93 , V_18 -> V_99 ) ;
return NULL ;
}
memset ( V_369 , 0 , sizeof ( struct V_368 ) ) ;
V_369 -> V_377 = V_185 -> V_192 . V_378 . V_379 ;
V_369 -> V_380 = ( V_381 )
( ( V_381 ) V_185 -> V_192 . V_378 . V_382
* ( V_381 ) 256 ) ;
V_369 -> V_383 = V_185 -> V_192 . V_378 . V_384 ;
V_369 -> V_385 = ( V_381 )
( ( V_381 ) V_185 -> V_192 . V_378 . V_386
* ( V_381 ) 256 ) ;
memset ( V_93 , 0 , sizeof ( T_6 ) ) ;
V_185 -> V_104 = V_387 ;
V_185 -> V_106 = V_107 ;
V_93 -> V_189 = NULL ;
V_93 -> V_15 = V_15 ;
if ( V_15 -> V_76 & V_96 )
V_128 = F_141 ( V_18 , V_93 , V_376 ) ;
else
V_128 = F_28 ( V_18 , V_93 , V_18 -> V_114 * 2 ) ;
if ( V_128 != V_109 ) {
if ( V_128 != V_119 )
F_32 ( V_93 , V_18 -> V_99 ) ;
return NULL ;
}
V_369 -> V_388 = V_185 -> V_192 . V_389 . V_390 ;
V_369 -> V_391 = V_185 -> V_192 . V_389 . V_392 ;
V_369 -> V_393 = V_185 -> V_192 . V_389 . V_394 ;
V_369 -> V_395 = V_185 -> V_192 . V_389 . V_396 ;
V_369 -> V_397 = V_185 -> V_192 . V_389 . V_398 ;
V_369 -> V_399 = V_185 -> V_192 . V_389 . V_400 ;
V_369 -> V_401 = V_185 -> V_192 . V_389 . V_400 ;
V_369 -> V_388 -= V_372 -> V_388 ;
V_369 -> V_391 -= V_372 -> V_391 ;
V_369 -> V_393 -= V_372 -> V_393 ;
V_369 -> V_395 -= V_372 -> V_395 ;
V_369 -> V_397 -= V_372 -> V_397 ;
V_369 -> V_399 -= V_372 -> V_399 ;
V_369 -> V_401 -= V_372 -> V_401 ;
if ( V_18 -> V_19 & V_402 ) {
V_369 -> V_403 = - 1 ;
V_369 -> V_404 = ( V_18 -> V_405 >> 1 ) ;
V_369 -> V_404 -= V_372 -> V_405 ;
} else if ( V_18 -> V_74 == V_75 ) {
V_369 -> V_403 = ( V_18 -> V_406 >> 1 ) ;
V_369 -> V_403 -= V_372 -> V_405 ;
V_369 -> V_404 = - 1 ;
} else {
V_369 -> V_403 = - 1 ;
V_369 -> V_404 = ( V_18 -> V_406 >> 1 ) ;
V_369 -> V_404 -= V_372 -> V_405 ;
}
V_369 -> V_407 = - 1 ;
V_374 = F_142 () ;
if ( V_374 < V_126 -> V_408 )
V_369 -> V_409 = V_374 +
( ( unsigned long ) - 1 - V_126 -> V_408 ) ;
else
V_369 -> V_409 = V_374 - V_126 -> V_408 ;
F_32 ( V_93 , V_18 -> V_99 ) ;
return V_369 ;
}
static void
F_143 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_125 * V_126 = & V_18 -> V_33 ;
struct V_371 * V_372 = & V_126 -> V_373 ;
T_6 * V_93 ;
T_7 * V_185 ;
int V_128 = 0 ;
if ( V_18 -> V_33 . V_34 & V_97 )
return;
V_93 = F_27 ( V_18 -> V_99 , V_100 ) ;
if ( ! V_93 )
return;
memset ( V_93 , 0 , sizeof( T_6 ) ) ;
V_185 = & V_93 -> V_102 . V_103 ;
V_185 -> V_104 = V_375 ;
V_185 -> V_106 = V_107 ;
V_185 -> V_192 . V_410 [ 0 ] = 0x1 ;
V_93 -> V_189 = NULL ;
V_93 -> V_15 = V_15 ;
if ( ( V_15 -> V_76 & V_96 ) ||
( ! ( V_126 -> V_34 & V_187 ) ) )
V_128 = F_141 ( V_18 , V_93 , V_376 ) ;
else
V_128 = F_28 ( V_18 , V_93 , V_18 -> V_114 * 2 ) ;
if ( V_128 != V_109 ) {
if ( V_128 != V_119 )
F_32 ( V_93 , V_18 -> V_99 ) ;
return;
}
memset ( V_93 , 0 , sizeof( T_6 ) ) ;
V_185 -> V_104 = V_387 ;
V_185 -> V_106 = V_107 ;
V_93 -> V_189 = NULL ;
V_93 -> V_15 = V_15 ;
if ( ( V_15 -> V_76 & V_96 ) ||
( ! ( V_126 -> V_34 & V_187 ) ) )
V_128 = F_141 ( V_18 , V_93 , V_376 ) ;
else
V_128 = F_28 ( V_18 , V_93 , V_18 -> V_114 * 2 ) ;
if ( V_128 != V_109 ) {
if ( V_128 != V_119 )
F_32 ( V_93 , V_18 -> V_99 ) ;
return;
}
V_372 -> V_388 = V_185 -> V_192 . V_389 . V_390 ;
V_372 -> V_391 = V_185 -> V_192 . V_389 . V_392 ;
V_372 -> V_393 = V_185 -> V_192 . V_389 . V_394 ;
V_372 -> V_395 = V_185 -> V_192 . V_389 . V_396 ;
V_372 -> V_397 = V_185 -> V_192 . V_389 . V_398 ;
V_372 -> V_399 = V_185 -> V_192 . V_389 . V_400 ;
V_372 -> V_401 = V_185 -> V_192 . V_389 . V_400 ;
if ( V_18 -> V_19 & V_402 )
V_372 -> V_405 = ( V_18 -> V_405 >> 1 ) ;
else
V_372 -> V_405 = ( V_18 -> V_406 >> 1 ) ;
V_126 -> V_408 = F_142 () ;
F_32 ( V_93 , V_18 -> V_99 ) ;
return;
}
static struct V_248 *
F_144 ( struct V_411 * V_412 )
{
struct V_12 * V_13 = F_145 ( V_412 -> V_6 . V_413 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_248 * V_249 ;
F_62 ( V_13 -> V_250 ) ;
F_88 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( F_89 ( V_249 ) &&
V_249 -> V_320 == V_414 &&
V_412 -> V_415 == V_249 -> V_416 ) {
F_63 ( V_13 -> V_250 ) ;
return V_249 ;
}
}
F_63 ( V_13 -> V_250 ) ;
return NULL ;
}
static void
F_146 ( struct V_411 * V_412 )
{
struct V_248 * V_249 = F_144 ( V_412 ) ;
F_147 ( V_412 ) = V_249 ? V_249 -> V_417 : - 1 ;
}
static void
F_148 ( struct V_411 * V_412 )
{
struct V_248 * V_249 = F_144 ( V_412 ) ;
F_149 ( V_412 ) =
V_249 ? F_75 ( V_249 -> V_418 . V_102 . V_296 ) : 0 ;
}
static void
F_150 ( struct V_411 * V_412 )
{
struct V_248 * V_249 = F_144 ( V_412 ) ;
F_151 ( V_412 ) =
V_249 ? F_75 ( V_249 -> V_295 . V_102 . V_296 ) : 0 ;
}
static void
F_152 ( struct V_419 * V_251 , T_2 V_420 )
{
if ( V_420 )
V_251 -> V_252 = V_420 ;
else
V_251 -> V_252 = 1 ;
}
static void
F_153 ( struct V_421 * V_421 )
{
struct V_14 * V_15 = * (struct V_14 * * ) V_421 -> V_422 ;
if ( V_15 -> V_62 == V_71 )
F_154 ( V_15 , V_423 , 0 , 0 ) ;
}
static void
F_155 ( struct V_17 * V_18 , T_2 V_424 )
{
V_18 -> V_425 = V_424 ;
}
void
F_156 ( struct V_17 * V_18 )
{
F_157 ( V_18 , V_426 ) ;
F_158 ( V_18 , V_427 ) ;
F_159 ( V_18 , V_428 ) ;
F_160 ( V_18 , V_429 ) ;
F_161 ( V_18 , V_430 ) ;
F_162 ( V_18 , V_431 ) ;
F_163 ( V_18 , V_432 ) ;
F_110 ( V_18 , V_433 ) ;
F_164 ( V_18 , V_434 ) ;
F_165 ( V_18 , V_435 ) ;
F_166 ( V_18 , V_436 ) ;
F_167 ( V_18 , V_437 ) ;
F_168 ( V_18 , V_438 ) ;
F_169 ( V_18 , V_439 ) ;
F_170 ( V_18 , V_440 ) ;
F_171 ( V_18 , V_441 ) ;
F_172 ( V_18 , V_442 ) ;
F_173 ( V_18 , V_443 ) ;
F_174 ( V_18 , V_444 ) ;
if ( V_18 -> V_44 == V_45 )
V_18 -> V_210 = 0 ;
else
V_18 -> V_210 = V_445 ;
V_18 -> V_235 = 0L ;
V_18 -> V_228 = 0L ;
F_175 ( V_18 , V_446 ) ;
F_176 ( V_18 , V_447 ) ;
F_177 ( V_18 , V_448 ) ;
F_155 ( V_18 , V_449 ) ;
F_114 ( V_18 , V_450 ) ;
F_118 ( V_18 , V_451 ) ;
F_178 ( V_18 , V_452 ) ;
F_179 ( V_18 , V_453 ) ;
V_18 -> V_223 = 1 ;
return;
}
void
F_180 ( struct V_14 * V_15 )
{
F_181 ( V_15 , V_449 ) ;
F_182 ( V_15 , V_454 ) ;
F_183 ( V_15 , V_455 ) ;
F_184 ( V_15 , V_254 ) ;
F_85 ( V_15 , V_456 ) ;
F_185 ( V_15 , V_457 ) ;
F_93 ( V_15 , V_458 ) ;
F_186 ( V_15 , V_459 ) ;
F_187 ( V_15 , V_460 ) ;
F_188 ( V_15 , V_461 ) ;
F_189 ( V_15 , V_462 ) ;
F_190 ( V_15 , V_463 ) ;
F_191 ( V_15 , V_464 ) ;
F_192 ( V_15 , V_465 ) ;
F_193 ( V_15 , V_466 ) ;
return;
}
