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
char V_37 [ 32 ] ;
F_19 ( V_18 , V_37 , 1 ) ;
return snprintf ( V_9 , V_10 , L_10 , V_37 , V_18 -> V_38 ) ;
}
static T_1
F_20 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
char V_2 [ 9 ] ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 * V_39 = & V_18 -> V_40 ;
F_1 ( V_39 -> V_41 . V_42 , V_2 ) ;
return snprintf ( V_9 , V_10 , L_8 , V_2 ) ;
}
static T_1
F_21 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_8 , V_18 -> V_43 ) ;
}
static T_1
F_22 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_44 = 0 ;
switch ( V_18 -> V_45 ) {
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
if ( V_18 -> V_19 & V_52 )
V_44 += snprintf ( V_9 + V_44 , V_10 - V_44 ,
L_11 ) ;
else
V_44 += snprintf ( V_9 + V_44 , V_10 - V_44 ,
L_12 ) ;
break;
case V_53 :
case V_54 :
case V_55 :
V_44 += snprintf ( V_9 + V_44 , V_10 - V_44 , L_13 ) ;
switch ( V_15 -> V_56 ) {
case V_57 :
V_44 += snprintf ( V_9 + V_44 , V_10 - V_44 ,
L_14 ) ;
break;
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
V_44 += snprintf ( V_9 + V_44 , V_10 - V_44 ,
L_15 ) ;
break;
case V_65 :
V_44 += snprintf ( V_9 + V_44 , V_10 - V_44 , L_16 ) ;
break;
case V_66 :
V_44 += snprintf ( V_9 + V_44 , V_10 - V_44 , L_17 ) ;
break;
case V_67 :
V_44 += snprintf ( V_9 + V_44 , V_10 - V_44 ,
L_18 ) ;
break;
}
if ( V_18 -> V_33 . V_34 & V_35 )
V_44 += snprintf ( V_9 + V_44 , V_10 - V_44 ,
L_19 ) ;
else if ( V_18 -> V_68 == V_69 ) {
if ( V_15 -> V_70 & V_71 )
V_44 += snprintf ( V_9 + V_44 , V_10 - V_44 ,
L_20 ) ;
else
V_44 += snprintf ( V_9 + V_44 , V_10 - V_44 ,
L_21 ) ;
} else {
if ( V_15 -> V_70 & V_72 )
V_44 += snprintf ( V_9 + V_44 , V_10 - V_44 ,
L_22 ) ;
else
V_44 += snprintf ( V_9 + V_44 , V_10 - V_44 ,
L_23 ) ;
}
}
return V_44 ;
}
static T_1
F_23 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_73 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_74 = - V_75 ;
if ( ( strncmp ( V_9 , L_24 , sizeof( L_24 ) - 1 ) == 0 ) &&
( V_18 -> V_45 == V_50 ) )
V_74 = V_18 -> V_76 ( V_18 , V_77 ) ;
else if ( ( strncmp ( V_9 , L_25 , sizeof( L_25 ) - 1 ) == 0 ) &&
( V_18 -> V_45 >= V_53 ) )
V_74 = V_18 -> V_78 ( V_18 , V_77 ) ;
if ( V_74 == 0 )
return strlen ( V_9 ) ;
else
return V_74 ;
}
static T_1
F_24 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
return snprintf ( V_9 , V_10 , L_9 ,
V_15 -> V_79 + V_15 -> V_80 ) ;
}
static int
F_25 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_4 * V_81 ;
int V_82 = V_83 ;
if ( ( V_15 -> V_70 & V_84 ) ||
( V_18 -> V_33 . V_34 & V_85 ) )
return - V_86 ;
V_81 = F_26 ( V_18 -> V_87 , V_88 ) ;
if ( ! V_81 )
return - V_89 ;
memset ( ( void * ) V_81 , 0 , sizeof ( T_4 ) ) ;
V_81 -> V_90 . V_91 . V_92 = V_93 ;
V_81 -> V_90 . V_91 . V_94 = V_95 ;
V_82 = F_27 ( V_18 , V_81 , V_96 * 2 ) ;
if ( ( V_82 == V_97 ) &&
( V_81 -> V_90 . V_91 . V_98 == 0 ||
V_81 -> V_90 . V_91 . V_98 == V_99 ) ) {
memset ( ( void * ) V_81 , 0 , sizeof ( T_4 ) ) ;
F_28 ( V_18 , V_81 , V_18 -> V_100 ,
V_18 -> V_101 ) ;
V_82 = F_27 ( V_18 , V_81 ,
V_18 -> V_102 * 2 ) ;
if ( ( V_82 == V_97 ) &&
( V_81 -> V_90 . V_91 . V_98 == V_103 ) )
F_29 ( V_18 , V_104 , V_105 | V_106 ,
L_26
L_27 ) ;
}
F_30 ( V_18 ) ;
if ( V_82 != V_107 )
F_31 ( V_81 , V_18 -> V_87 ) ;
if ( V_82 == V_83 )
return - V_108 ;
return 0 ;
}
static int
F_32 ( struct V_17 * V_18 , T_5 type )
{
struct V_109 V_110 ;
struct V_111 * V_112 ;
struct V_113 * V_114 ;
int V_74 = 0 ;
int V_115 = 0 ;
int V_3 ;
int V_116 ;
F_33 ( & V_110 ) ;
V_116 = F_34 ( V_18 , & V_74 , & V_110 ,
V_117 ) ;
if ( V_116 == 0 )
return - V_89 ;
F_35 ( & V_110 ) ;
if ( V_74 != 0 )
return - V_108 ;
V_114 = & V_18 -> V_33 ;
for ( V_3 = 0 ; V_3 < V_114 -> V_118 ; V_3 ++ ) {
V_112 = & V_114 -> V_119 [ V_3 ] ;
while ( V_112 -> V_120 ) {
F_36 ( 10 ) ;
if ( V_115 ++ > 500 ) {
F_29 ( V_18 ,
V_121 , V_122 ,
L_28
L_29 ) ;
break;
}
}
}
F_33 ( & V_110 ) ;
V_116 = F_34 ( V_18 , & V_74 , & V_110 , type ) ;
if ( V_116 == 0 )
return - V_89 ;
F_35 ( & V_110 ) ;
if ( V_74 != 0 )
return - V_108 ;
return 0 ;
}
int
F_37 ( struct V_17 * V_18 )
{
struct V_109 V_110 ;
int V_74 = 0 ;
int V_116 ;
if ( ! V_18 -> V_123 )
return - V_108 ;
V_74 = F_32 ( V_18 , V_124 ) ;
if ( V_74 != 0 )
return V_74 ;
F_33 ( & V_110 ) ;
V_116 = F_34 ( V_18 , & V_74 , & V_110 ,
V_125 ) ;
if ( V_116 == 0 )
return - V_89 ;
F_35 ( & V_110 ) ;
if ( V_74 != 0 )
return - V_108 ;
return 0 ;
}
static T_1
F_38 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_73 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_74 = - V_75 ;
if ( strncmp ( V_9 , L_30 , sizeof( L_30 ) - 1 ) == 0 )
V_74 = V_18 -> F_37 ( V_18 ) ;
if ( V_74 == 0 )
return strlen ( V_9 ) ;
else
return V_74 ;
}
static T_1
F_39 ( struct V_17 * V_18 , T_5 V_126 )
{
struct V_109 V_110 ;
T_5 V_127 ;
int V_74 = 0 ;
int V_116 ;
if ( ! V_18 -> V_123 )
return - V_108 ;
if ( ( V_18 -> V_38 < V_128 ) ||
( F_40 ( V_129 , & V_18 -> V_130 . V_131 ) !=
V_132 ) )
return - V_86 ;
V_74 = F_32 ( V_18 , V_124 ) ;
if ( V_74 != 0 )
return V_74 ;
F_36 ( 100 ) ;
V_127 = F_41 ( V_18 -> V_130 . V_133 +
V_134 ) ;
if ( V_126 == V_135 )
V_127 |= V_136 ;
else if ( V_126 == V_137 )
V_127 |= V_138 ;
else if ( V_126 == V_139 )
V_127 |= V_140 ;
F_42 ( V_127 , V_18 -> V_130 . V_133 +
V_134 ) ;
F_41 ( V_18 -> V_130 . V_133 + V_134 ) ;
F_36 ( 100 ) ;
F_33 ( & V_110 ) ;
V_116 = F_34 ( V_18 , & V_74 , & V_110 ,
V_125 ) ;
if ( V_116 == 0 )
return - V_89 ;
F_35 ( & V_110 ) ;
if ( V_74 != 0 )
return - V_108 ;
return 0 ;
}
static T_1
F_43 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_141 ) ;
}
static T_1
F_44 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
char * V_142 ;
if ( V_18 -> V_45 == V_51 )
V_142 = L_31 ;
else if ( V_18 -> V_45 == V_47 )
V_142 = L_32 ;
else if ( V_18 -> V_45 == V_48 )
V_142 = L_33 ;
else
V_142 = L_34 ;
return snprintf ( V_9 , V_10 , L_8 , V_142 ) ;
}
static T_1
F_45 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_73 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_109 V_110 ;
int V_74 = 0 ;
int V_116 ;
if ( ! V_18 -> V_123 )
return - V_143 ;
F_33 ( & V_110 ) ;
if( strncmp ( V_9 , L_34 , sizeof( L_34 ) - 1 ) == 0 ) {
V_116 = F_34 ( V_18 , & V_74 , & V_110 ,
V_125 ) ;
if ( V_116 == 0 )
return - V_89 ;
F_35 ( & V_110 ) ;
} else if ( strncmp ( V_9 , L_33 , sizeof( L_33 ) - 1 ) == 0 )
V_74 = F_32 ( V_18 , V_124 ) ;
else if ( strncmp ( V_9 , L_35 , sizeof( L_35 ) - 1 ) == 0 )
if ( V_18 -> V_38 == V_128 )
return - V_75 ;
else
V_74 = F_32 ( V_18 , V_144 ) ;
else if ( strncmp ( V_9 , L_31 , sizeof( L_31 ) - 1 ) == 0 )
if ( V_18 -> V_38 == V_128 )
return - V_75 ;
else
V_74 = F_32 ( V_18 , V_145 ) ;
else if ( strncmp ( V_9 , L_36 , sizeof( L_36 ) - 1 ) == 0 )
V_74 = F_39 ( V_18 , V_135 ) ;
else if ( strncmp ( V_9 , L_37 , sizeof( L_37 ) - 1 ) == 0 )
V_74 = F_39 ( V_18 , V_137 ) ;
else if ( strncmp ( V_9 , L_38 , sizeof( L_38 ) - 1 ) == 0 )
V_74 = F_39 ( V_18 , V_139 ) ;
else
return - V_75 ;
if ( ! V_74 )
return strlen ( V_9 ) ;
else
return - V_108 ;
}
static int
F_46 ( struct V_17 * V_18 ,
T_5 * V_146 , T_5 * V_147 ,
T_5 * V_148 , T_5 * V_149 ,
T_5 * V_150 , T_5 * V_151 )
{
struct V_152 * V_153 ;
T_4 * V_81 ;
T_6 * V_154 ;
int V_116 = 0 ;
T_5 V_155 ;
if ( V_18 -> V_45 < V_50 ||
! V_18 -> V_87 ||
( V_18 -> V_33 . V_34 & V_156 ) == 0 )
return 0 ;
if ( V_18 -> V_33 . V_34 & V_85 )
return 0 ;
V_81 = F_26 ( V_18 -> V_87 , V_88 ) ;
if ( ! V_81 )
return 0 ;
memset ( V_81 , 0 , sizeof ( T_4 ) ) ;
V_154 = & V_81 -> V_90 . V_91 ;
V_154 -> V_92 = V_157 ;
V_154 -> V_94 = V_95 ;
V_81 -> V_158 = NULL ;
if ( V_18 -> V_159 -> V_70 & V_84 )
V_116 = V_160 ;
else
V_116 = F_27 ( V_18 , V_81 , V_18 -> V_102 * 2 ) ;
if ( V_116 != V_97 ) {
if ( V_116 != V_107 )
F_31 ( V_81 , V_18 -> V_87 ) ;
return 0 ;
}
if ( V_18 -> V_38 == V_128 ) {
V_153 = & V_81 -> V_90 . V_161 . V_162 . V_153 ;
if ( V_148 )
* V_148 = F_40 ( V_163 , V_153 ) ;
if ( V_149 )
* V_149 = F_40 ( V_163 , V_153 ) -
V_18 -> V_130 . V_164 . V_165 ;
if ( V_146 )
* V_146 = F_40 ( V_166 , V_153 ) ;
if ( V_147 )
* V_147 = F_40 ( V_166 , V_153 ) -
V_18 -> V_130 . V_164 . V_167 ;
V_155 = ( F_40 ( V_168 , V_153 ) > 0 ) ?
( F_40 ( V_168 , V_153 ) - 1 ) : 0 ;
if ( V_150 )
* V_150 = V_155 ;
if ( V_151 )
* V_151 = V_155 - V_18 -> V_130 . V_164 . V_169 ;
} else {
if ( V_148 )
* V_148 = V_154 -> V_162 . V_170 . V_171 ;
if ( V_149 )
* V_149 = V_154 -> V_162 . V_170 . V_172 ;
if ( V_146 )
* V_146 = V_154 -> V_162 . V_170 . V_173 ;
if ( V_147 )
* V_147 = V_154 -> V_162 . V_170 . V_174 ;
if ( V_150 )
* V_150 = V_154 -> V_162 . V_170 . V_155 ;
if ( V_151 )
* V_151 = V_154 -> V_162 . V_170 . V_175 ;
}
F_31 ( V_81 , V_18 -> V_87 ) ;
return 1 ;
}
static T_1
F_47 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_5 V_115 ;
if ( F_46 ( V_18 , NULL , NULL , & V_115 , NULL , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_9 , V_115 ) ;
return snprintf ( V_9 , V_10 , L_18 ) ;
}
static T_1
F_48 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_5 V_115 , V_176 ;
if ( F_46 ( V_18 , NULL , NULL , & V_115 , & V_176 , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_9 , ( V_115 - V_176 ) ) ;
return snprintf ( V_9 , V_10 , L_18 ) ;
}
static T_1
F_49 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_5 V_115 ;
if ( F_46 ( V_18 , & V_115 , NULL , NULL , NULL , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_9 , V_115 ) ;
return snprintf ( V_9 , V_10 , L_18 ) ;
}
static T_1
F_50 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_5 V_115 , V_176 ;
if ( F_46 ( V_18 , & V_115 , & V_176 , NULL , NULL , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_9 , ( V_115 - V_176 ) ) ;
return snprintf ( V_9 , V_10 , L_18 ) ;
}
static T_1
F_51 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_5 V_115 ;
if ( F_46 ( V_18 , NULL , NULL , NULL , NULL , & V_115 , NULL ) )
return snprintf ( V_9 , V_10 , L_9 , V_115 ) ;
return snprintf ( V_9 , V_10 , L_18 ) ;
}
static T_1
F_52 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_5 V_115 , V_176 ;
if ( F_46 ( V_18 , NULL , NULL , NULL , NULL , & V_115 , & V_176 ) )
return snprintf ( V_9 , V_10 , L_9 , ( V_115 - V_176 ) ) ;
return snprintf ( V_9 , V_10 , L_18 ) ;
}
static T_1
F_53 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( ! ( V_18 -> V_155 ) )
return snprintf ( V_9 , V_10 , L_39 ) ;
if ( V_15 -> V_177 == V_178 )
return snprintf ( V_9 , V_10 , L_40 ) ;
return snprintf ( V_9 , V_10 , L_41 , V_15 -> V_179 ) ;
}
static T_1
F_54 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_42 , V_18 -> V_180 ) ;
}
static T_1
F_55 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_73 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_5 V_181 ;
T_5 V_182 ;
int V_183 = 0 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_75 ;
if ( sscanf ( V_9 , L_43 , & V_183 ) != 1 )
return - V_75 ;
if ( ( V_183 & 0x3 ) != V_183 )
return - V_75 ;
if ( V_18 -> V_38 == V_128 )
V_183 = 0 ;
F_56 ( & V_18 -> V_184 ) ;
V_182 = V_18 -> V_180 ;
if ( V_183 & V_185 ) {
if ( ( V_183 & V_186 ) &&
! ( V_182 & V_186 ) ) {
if ( F_57 ( V_18 -> V_187 , & V_181 ) ) {
F_58 ( & V_18 -> V_184 ) ;
return - V_75 ;
}
V_181 &= ~ ( V_188 << V_189 ) ;
F_42 ( V_181 , V_18 -> V_187 ) ;
F_41 ( V_18 -> V_187 ) ;
F_59 ( V_18 ) ;
}
} else if ( V_183 != 0x0 ) {
F_58 ( & V_18 -> V_184 ) ;
return - V_75 ;
}
if ( ! ( V_183 & V_186 ) &&
( V_182 & V_186 ) )
{
F_58 ( & V_18 -> V_184 ) ;
F_60 ( & V_18 -> V_190 ) ;
F_56 ( & V_18 -> V_184 ) ;
if ( F_57 ( V_18 -> V_187 , & V_181 ) ) {
F_58 ( & V_18 -> V_184 ) ;
return - V_75 ;
}
V_181 |= ( V_188 << V_189 ) ;
F_42 ( V_181 , V_18 -> V_187 ) ;
F_41 ( V_18 -> V_187 ) ;
}
V_18 -> V_180 = V_183 ;
F_58 ( & V_18 -> V_184 ) ;
return strlen ( V_9 ) ;
}
static T_1
F_61 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_191 ) ;
}
static T_1
F_62 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_192 ) ;
}
static T_1
F_63 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_44 ,
( V_18 -> V_193 ) ? L_45 : L_46 ,
( V_18 -> V_22 & V_194 ) ?
L_47 : L_48 ) ;
}
static T_1
F_64 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_195 * V_196 = V_18 -> V_197 ;
union V_198 * V_199 ;
T_5 V_200 , V_201 ;
T_4 * V_202 ;
struct V_203 * V_204 ;
struct V_205 * V_206 ;
T_5 V_207 ;
T_5 V_208 ;
int V_209 , V_116 , V_3 ;
if ( ( V_18 -> V_38 < V_128 ) ||
( F_40 ( V_129 , & V_18 -> V_130 . V_131 ) !=
V_132 ) )
return - V_86 ;
if ( ! V_196 -> V_210 )
return snprintf ( V_9 , V_10 , L_9 , 0 ) ;
V_202 = ( T_4 * ) F_26 ( V_18 -> V_87 , V_88 ) ;
if ( ! V_202 )
return - V_89 ;
V_209 = ( sizeof( struct V_203 ) -
sizeof( struct V_211 ) ) ;
F_65 ( V_18 , V_202 , V_212 ,
V_213 ,
V_209 , V_214 ) ;
V_199 = (union V_198 * )
& V_202 -> V_90 . V_161 . V_162 . V_215 . V_216 . V_217 ;
F_66 ( V_218 , & V_199 -> V_219 ,
V_18 -> V_130 . V_220 . V_221 + 1 ) ;
V_204 = & V_202 -> V_90 . V_161 . V_162 . V_204 ;
F_66 ( V_222 , & V_204 -> V_90 . V_219 ,
V_223 ) ;
V_116 = F_27 ( V_18 , V_202 ,
F_67 ( V_18 , V_224 ) ) ;
if ( V_116 != V_107 ) {
V_200 = F_40 ( V_225 , & V_199 -> V_226 ) ;
V_201 = F_40 ( V_227 ,
& V_199 -> V_226 ) ;
if ( V_200 || V_201 || V_116 )
goto V_228;
} else
goto V_228;
V_208 = V_204 -> V_90 . V_226 . V_229 . V_230 ;
for ( V_3 = 0 ; V_3 < V_231 ; V_3 ++ ) {
V_206 = (struct V_205 * )
& V_204 -> V_90 . V_226 . V_229 . V_206 [ V_3 ] ;
if ( V_232 ==
F_40 ( V_233 , V_206 ) ) {
V_207 = F_40 ( V_234 ,
V_206 ) ;
break;
}
}
if ( V_3 < V_231 ) {
if ( V_116 != V_107 )
F_31 ( V_202 , V_18 -> V_87 ) ;
return snprintf ( V_9 , V_10 , L_9 , V_207 ) ;
}
V_228:
if ( V_116 != V_107 )
F_31 ( V_202 , V_18 -> V_87 ) ;
return - V_108 ;
}
static T_1
F_68 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_73 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
unsigned int V_115 = V_73 ;
if ( V_9 [ V_115 - 1 ] == '\n' )
V_115 -- ;
if ( ( V_115 != strlen ( V_235 ) ) ||
( strncmp ( V_9 , V_235 , strlen ( V_235 ) ) != 0 ) )
return - V_75 ;
V_18 -> V_236 = 1 ;
return V_73 ;
}
static T_1
F_69 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_49 ,
( unsigned long long ) V_18 -> V_237 ) ;
}
static T_1
F_70 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_73 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_109 V_110 ;
int V_238 = 0 , V_239 = 0 ;
unsigned int V_3 , V_4 , V_115 = V_73 ;
T_7 V_240 [ 8 ] ;
int V_116 ;
if ( ! V_18 -> V_123 )
return - V_143 ;
F_56 ( & V_18 -> V_184 ) ;
if ( V_18 -> V_241 == V_242 ) {
F_58 ( & V_18 -> V_184 ) ;
return - V_143 ;
}
F_58 ( & V_18 -> V_184 ) ;
if ( V_9 [ V_115 - 1 ] == '\n' )
V_115 -- ;
if ( ! V_18 -> V_236 || ( V_115 < 16 ) || ( V_115 > 18 ) ||
( ( V_115 == 17 ) && ( * V_9 ++ != 'x' ) ) ||
( ( V_115 == 18 ) && ( ( * V_9 ++ != '0' ) || ( * V_9 ++ != 'x' ) ) ) )
return - V_75 ;
V_18 -> V_236 = 0 ;
memset ( V_240 , 0 , sizeof( V_240 ) ) ;
for ( V_3 = 0 , V_4 = 0 ; V_3 < 16 ; V_3 ++ ) {
int V_243 ;
V_243 = F_71 ( * V_9 ++ ) ;
if ( V_243 >= 0 )
V_4 = ( V_4 << 4 ) | V_243 ;
else
return - V_75 ;
if ( V_3 % 2 ) {
V_240 [ V_3 / 2 ] = V_4 & 0xff ;
V_4 = 0 ;
}
}
V_18 -> V_237 = F_72 ( V_240 ) ;
F_73 ( V_13 ) = V_18 -> V_237 ;
if ( V_18 -> V_244 )
F_74 ( V_13 ) = V_18 -> V_244 ;
F_75 ( V_245 , & V_18 -> V_197 -> V_6 ,
L_50 , V_18 -> V_246 ) ;
V_238 = F_32 ( V_18 , V_124 ) ;
if ( V_238 )
F_29 ( V_18 , V_104 , V_122 ,
L_51
L_52 , V_238 ) ;
F_33 ( & V_110 ) ;
V_116 = F_34 ( V_18 , & V_239 , & V_110 ,
V_125 ) ;
if ( V_116 == 0 )
return - V_89 ;
F_35 ( & V_110 ) ;
if ( V_239 )
F_29 ( V_18 , V_104 , V_122 ,
L_53
L_52 , V_239 ) ;
return ( V_238 || V_239 ) ? - V_108 : V_73 ;
}
static T_1
F_76 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_49 ,
( unsigned long long ) V_18 -> V_244 ) ;
}
static T_1
F_77 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_73 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
unsigned int V_3 , V_4 , V_115 = V_73 ;
T_7 V_247 [ 8 ] ;
if ( V_9 [ V_115 - 1 ] == '\n' )
V_115 -- ;
if ( ! V_18 -> V_236 || ( V_115 < 16 ) || ( V_115 > 18 ) ||
( ( V_115 == 17 ) && ( * V_9 ++ != 'x' ) ) ||
( ( V_115 == 18 ) && ( ( * V_9 ++ != '0' ) || ( * V_9 ++ != 'x' ) ) ) )
return - V_75 ;
memset ( V_247 , 0 , sizeof( V_247 ) ) ;
for ( V_3 = 0 , V_4 = 0 ; V_3 < 16 ; V_3 ++ ) {
int V_243 ;
V_243 = F_71 ( * V_9 ++ ) ;
if ( V_243 >= 0 )
V_4 = ( V_4 << 4 ) | V_243 ;
else
return - V_75 ;
if ( V_3 % 2 ) {
V_247 [ V_3 / 2 ] = V_4 & 0xff ;
V_4 = 0 ;
}
}
V_18 -> V_244 = F_72 ( V_247 ) ;
F_75 ( V_245 , & V_18 -> V_197 -> V_6 ,
L_54
L_55 , V_18 -> V_246 ) ;
return V_73 ;
}
static T_1
F_78 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_248 ) ;
}
static T_1
F_79 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 ,
V_18 -> V_33 . V_119 [ V_249 ] . V_250 ) ;
}
static T_1
F_80 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 ,
V_18 -> V_33 . V_119 [ V_249 ] . V_251 ) ;
}
static T_1
F_81 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
return snprintf ( V_9 , V_10 , L_9 , V_15 -> V_252 ) ;
}
static int
F_82 ( struct V_14 * V_15 , int V_183 )
{
if ( V_15 -> V_252 != V_253 ) {
V_15 -> V_254 = V_15 -> V_252 ;
if ( V_183 != V_253 )
F_83 ( V_15 , V_104 , V_122 ,
L_56
L_57
L_58 ) ;
return 0 ;
}
if ( V_183 >= V_255 && V_183 <= V_256 ) {
V_15 -> V_254 = V_183 ;
V_15 -> V_252 = V_183 ;
return 0 ;
}
F_83 ( V_15 , V_104 , V_122 ,
L_59
L_60 ,
V_183 , V_255 , V_256 ) ;
V_15 -> V_254 = V_253 ;
return - V_75 ;
}
static void
F_84 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
struct V_257 * V_258 ;
V_13 = F_85 ( V_15 ) ;
F_56 ( V_13 -> V_259 ) ;
F_86 (ndlp, &vport->fc_nodes, nlp_listp)
if ( F_87 ( V_258 ) && V_258 -> V_260 )
V_258 -> V_260 -> V_261 = V_15 -> V_252 ;
F_58 ( V_13 -> V_259 ) ;
}
static int
F_88 ( struct V_14 * V_15 , int V_183 )
{
if ( V_15 -> V_262 ||
( V_263 != V_253 ) ) {
F_83 ( V_15 , V_104 , V_122 ,
L_61
L_62 ) ;
return 0 ;
}
if ( V_183 >= V_255 && V_183 <= V_256 ) {
V_15 -> V_254 = V_183 ;
V_15 -> V_252 = V_183 ;
F_89 ( F_85 ( V_15 ) ) = V_183 ;
F_84 ( V_15 ) ;
return 0 ;
}
F_83 ( V_15 , V_104 , V_122 ,
L_63
L_64 ,
V_183 , V_255 , V_256 ) ;
return - V_75 ;
}
static int
F_90 ( struct V_14 * V_15 , int V_183 )
{
if ( V_183 >= V_255 && V_183 <= V_256 ) {
V_15 -> V_254 = V_183 ;
V_15 -> V_252 = V_183 ;
V_15 -> V_262 = 1 ;
F_89 ( F_85 ( V_15 ) ) = V_183 ;
F_84 ( V_15 ) ;
return 0 ;
}
F_83 ( V_15 , V_104 , V_122 ,
L_65
L_60 ,
V_183 , V_255 , V_256 ) ;
return - V_75 ;
}
static int
F_91 ( struct V_14 * V_15 , int V_183 )
{
if ( V_183 < 0 || V_183 > 1 ) {
F_83 ( V_15 , V_104 , V_122 ,
L_66
L_67 ,
V_183 ) ;
V_15 -> V_264 = 1 ;
return - V_75 ;
}
if ( V_15 -> V_177 == V_178 ) {
V_15 -> V_264 = 0 ;
return 0 ;
}
V_15 -> V_264 = V_183 ;
return 0 ;
}
static int
F_92 ( struct V_14 * V_15 , int V_183 )
{
if ( V_183 < 0 || V_183 > 1 ) {
F_83 ( V_15 , V_104 , V_122 ,
L_68
L_67 ,
V_183 ) ;
V_15 -> V_264 = 1 ;
return - V_75 ;
}
if ( V_15 -> V_177 == V_178 && V_183 != 0 ) {
F_83 ( V_15 , V_104 , V_122 ,
L_69
L_70 ) ;
V_15 -> V_264 = 0 ;
return 0 ;
}
V_15 -> V_264 = V_183 ;
return 0 ;
}
static T_1
F_93 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_73 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_183 = 0 ;
int V_265 = 0 ;
const char * V_266 = V_9 ;
int V_267 ;
T_5 V_268 ;
if ( ! strncmp ( V_9 , L_71 , strlen ( L_71 ) ) ) {
V_265 = 1 ;
V_266 = & V_9 [ strlen ( L_71 ) ] ;
}
if ( ! isdigit ( V_266 [ 0 ] ) )
return - V_75 ;
if ( sscanf ( V_266 , L_43 , & V_183 ) != 1 )
return - V_75 ;
if ( V_183 >= 0 && V_183 <= 6 ) {
V_268 = V_18 -> V_100 ;
V_18 -> V_100 = V_183 ;
if ( V_265 )
return strlen ( V_9 ) ;
V_267 = F_25 ( F_85 ( V_18 -> V_159 ) ) ;
if ( V_267 ) {
V_18 -> V_100 = V_268 ;
return - V_75 ;
} else
return strlen ( V_9 ) ;
}
F_29 ( V_18 , V_104 , V_122 ,
L_72
L_73 ,
V_18 -> V_246 , V_183 ) ;
return - V_75 ;
}
static T_1
F_94 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
if ( V_15 -> V_269 & V_270 )
sprintf ( V_9 , L_2 ) ;
else
sprintf ( V_9 , L_3 ) ;
return strlen ( V_9 ) ;
}
static T_1
F_95 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_73 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
#define F_96 1024
static char V_271 [ F_96 ] ;
unsigned long V_3 ;
char * V_272 , * V_273 ;
struct V_14 * * V_274 ;
struct V_12 * V_275 ;
char * V_276 , * V_277 , * V_278 ;
unsigned long V_279 , V_280 , V_281 ;
if ( ! strncmp ( V_9 , L_74 , strlen ( L_74 ) ) ) {
if ( strlen ( V_9 ) > ( F_96 - 1 ) )
return - V_75 ;
strcpy ( V_271 , V_9 ) ;
V_272 = & V_271 [ 0 ] ;
V_273 = F_97 ( & V_272 , L_75 ) ;
if ( ! V_273 )
return - V_75 ;
V_276 = F_97 ( & V_272 , L_75 ) ;
if ( ! V_276 )
return - V_75 ;
if ( ! strncmp ( V_276 , L_76 , strlen ( L_76 ) ) )
V_281 = V_282 ;
else if ( ! strncmp ( V_276 , L_77 , strlen ( L_77 ) ) )
V_281 = V_283 ;
else
return - V_75 ;
V_277 = F_97 ( & V_272 , L_75 ) ;
if ( ! V_277 )
return - V_75 ;
V_279 = F_98 ( V_277 , NULL , 0 ) ;
V_278 = F_97 ( & V_272 , L_75 ) ;
if ( ! V_278 )
return - V_75 ;
V_280 = F_98 ( V_278 , NULL , 0 ) ;
if ( ! V_280 )
return - V_75 ;
V_274 = F_99 ( V_18 ) ;
if ( V_274 == NULL )
return - V_89 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_284 && V_274 [ V_3 ] != NULL ; V_3 ++ ) {
V_275 = F_85 ( V_274 [ V_3 ] ) ;
F_56 ( V_275 -> V_259 ) ;
V_274 [ V_3 ] -> V_285 = 1 ;
if ( V_274 [ V_3 ] -> V_286 )
F_100 ( V_274 [ V_3 ] ) ;
F_58 ( V_275 -> V_259 ) ;
}
V_18 -> V_281 = V_281 ;
V_18 -> V_287 = V_279 ;
V_18 -> V_288 = V_280 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_284 && V_274 [ V_3 ] != NULL ; V_3 ++ ) {
V_275 = F_85 ( V_274 [ V_3 ] ) ;
F_56 ( V_275 -> V_259 ) ;
V_274 [ V_3 ] -> V_285 = 0 ;
F_58 ( V_275 -> V_259 ) ;
}
F_101 ( V_18 , V_274 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_78 , strlen ( L_78 ) ) ) {
V_274 = F_99 ( V_18 ) ;
if ( V_274 == NULL )
return - V_89 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_284 && V_274 [ V_3 ] != NULL ; V_3 ++ ) {
V_275 = F_85 ( V_274 [ V_3 ] ) ;
F_56 ( V_13 -> V_259 ) ;
V_274 [ V_3 ] -> V_285 = 1 ;
F_102 ( V_15 ) ;
V_15 -> V_286 = 0 ;
V_274 [ V_3 ] -> V_285 = 0 ;
F_58 ( V_13 -> V_259 ) ;
}
F_101 ( V_18 , V_274 ) ;
V_18 -> V_281 = V_289 ;
V_18 -> V_287 = 0 ;
V_18 -> V_288 = 0 ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_79 , strlen ( L_79 ) ) ) {
if ( V_18 -> V_281 == V_289 )
return - V_75 ;
F_56 ( V_13 -> V_259 ) ;
if ( V_15 -> V_286 ) {
F_58 ( V_13 -> V_259 ) ;
return strlen ( V_9 ) ;
}
F_103 ( V_15 ) ;
V_15 -> V_286 = 1 ;
F_58 ( V_13 -> V_259 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_80 , strlen ( L_80 ) ) ) {
F_56 ( V_13 -> V_259 ) ;
if ( V_15 -> V_286 == 0 ) {
F_58 ( V_13 -> V_259 ) ;
return strlen ( V_9 ) ;
}
F_102 ( V_15 ) ;
V_15 -> V_286 = 0 ;
F_58 ( V_13 -> V_259 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_81 , strlen ( L_81 ) ) ) {
if ( ( V_18 -> V_281 == V_289 )
|| ! V_15 -> V_286 )
return strlen ( V_9 ) ;
F_56 ( V_13 -> V_259 ) ;
V_15 -> V_285 = 1 ;
F_100 ( V_15 ) ;
V_15 -> V_285 = 0 ;
F_58 ( V_13 -> V_259 ) ;
return strlen ( V_9 ) ;
}
return - V_75 ;
}
static T_1
F_104 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_290 = 0 ;
int V_3 ;
char * V_281 ;
unsigned long V_291 ;
switch ( V_18 -> V_281 ) {
case V_282 :
V_281 = L_76 ;
break;
case V_283 :
V_281 = L_77 ;
break;
default:
V_281 = L_82 ;
break;
}
sprintf ( & V_9 [ V_290 ] , L_83
L_84
L_85 ,
V_15 -> V_286 , V_15 -> V_285 ,
V_281 , V_18 -> V_287 , V_18 -> V_288 ) ;
V_290 = strlen ( V_9 ) ;
if ( V_18 -> V_281 != V_289 ) {
for ( V_3 = 0 ; V_3 < V_292 ; V_3 ++ ) {
if ( V_18 -> V_281 == V_282 )
V_291 = V_18 -> V_287 +
V_18 -> V_288 * V_3 ;
else
V_291 = V_18 -> V_287 +
( 1 << V_3 ) * V_18 -> V_288 ;
if ( V_290 + 10 > V_10 )
break;
sprintf ( & V_9 [ V_290 ] , L_86 , V_291 ) ;
V_290 = strlen ( V_9 ) ;
}
}
sprintf ( & V_9 [ V_290 ] , L_1 ) ;
return strlen ( V_9 ) ;
}
static T_1
F_105 ( struct V_293 * V_294 , struct V_295 * V_296 ,
struct V_297 * V_298 ,
char * V_9 , T_8 V_299 , T_3 V_73 )
{
struct V_5 * V_6 = F_106 ( V_296 , struct V_5 ,
V_296 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_3 = 0 , V_290 = 0 ;
unsigned long V_300 ;
struct V_257 * V_258 = NULL ;
V_300 = ( unsigned long ) V_299 /
V_301 ;
if ( ! V_15 -> V_286 || V_15 -> V_285
|| ( V_18 -> V_281 == V_289 ) )
return 0 ;
F_56 ( V_13 -> V_259 ) ;
F_86 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_87 ( V_258 ) || ! V_258 -> V_302 )
continue;
if ( V_300 > 0 ) {
V_300 -- ;
continue;
}
if ( ( V_290 + V_301 )
> V_73 )
break;
if ( ! V_258 -> V_302 )
continue;
sprintf ( & V_9 [ V_290 ] , L_87 ,
V_258 -> V_303 . V_90 . V_304 [ 0 ] ,
V_258 -> V_303 . V_90 . V_304 [ 1 ] ,
V_258 -> V_303 . V_90 . V_304 [ 2 ] ,
V_258 -> V_303 . V_90 . V_304 [ 3 ] ,
V_258 -> V_303 . V_90 . V_304 [ 4 ] ,
V_258 -> V_303 . V_90 . V_304 [ 5 ] ,
V_258 -> V_303 . V_90 . V_304 [ 6 ] ,
V_258 -> V_303 . V_90 . V_304 [ 7 ] ) ;
V_290 = strlen ( V_9 ) ;
for ( V_3 = 0 ; V_3 < V_292 ; V_3 ++ ) {
sprintf ( & V_9 [ V_290 ] , L_88 ,
V_258 -> V_302 [ V_3 ] . V_305 ) ;
V_290 = strlen ( V_9 ) ;
}
sprintf ( & V_9 [ V_290 ] , L_1 ) ;
V_290 = strlen ( V_9 ) ;
}
F_58 ( V_13 -> V_259 ) ;
return V_290 ;
}
static T_1
F_107 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_73 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_183 = V_306 ;
int V_265 = 0 ;
const char * V_266 = V_9 ;
int V_267 ;
T_5 V_268 ;
if ( ! strncmp ( V_9 , L_71 , strlen ( L_71 ) ) ) {
V_265 = 1 ;
V_266 = & V_9 [ strlen ( L_71 ) ] ;
}
if ( ! isdigit ( V_266 [ 0 ] ) )
return - V_75 ;
if ( sscanf ( V_266 , L_43 , & V_183 ) != 1 )
return - V_75 ;
if ( ( ( V_183 == V_307 ) && ! ( V_18 -> V_308 & V_309 ) ) ||
( ( V_183 == V_310 ) && ! ( V_18 -> V_308 & V_311 ) ) ||
( ( V_183 == V_312 ) && ! ( V_18 -> V_308 & V_313 ) ) ||
( ( V_183 == V_314 ) && ! ( V_18 -> V_308 & V_315 ) ) ||
( ( V_183 == V_316 ) && ! ( V_18 -> V_308 & V_317 ) ) ||
( ( V_183 == V_318 ) && ! ( V_18 -> V_308 & V_319 ) ) ) {
F_29 ( V_18 , V_104 , V_122 ,
L_89
L_90 ,
V_183 ) ;
return - V_75 ;
}
if ( ( V_183 >= 0 ) && ( V_183 <= V_320 ) &&
( V_321 & ( 1 << V_183 ) ) ) {
V_268 = V_18 -> V_101 ;
V_18 -> V_101 = V_183 ;
if ( V_265 )
return strlen ( V_9 ) ;
V_267 = F_25 ( F_85 ( V_18 -> V_159 ) ) ;
if ( V_267 ) {
V_18 -> V_101 = V_268 ;
return - V_75 ;
} else
return strlen ( V_9 ) ;
}
F_29 ( V_18 , V_104 , V_122 ,
L_91
L_92 V_322 L_93 , V_183 ) ;
return - V_75 ;
}
static int
F_108 ( struct V_17 * V_18 , int V_183 )
{
if ( ( V_183 >= 0 ) && ( V_183 <= V_320 ) &&
( V_321 & ( 1 << V_183 ) ) ) {
V_18 -> V_101 = V_183 ;
return 0 ;
}
F_29 ( V_18 , V_104 , V_122 ,
L_94
L_95
L_96 V_322 L_93 , V_183 ) ;
V_18 -> V_101 = V_306 ;
return - V_75 ;
}
static T_1
F_109 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_73 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_183 = 0 , V_116 = - V_75 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_75 ;
if ( sscanf ( V_9 , L_43 , & V_183 ) != 1 )
return - V_75 ;
switch ( V_183 ) {
case 0 :
if ( V_18 -> V_19 & V_323 ) {
V_116 = F_110 ( V_18 -> V_197 ) ;
if ( ! V_116 ) {
F_56 ( & V_18 -> V_184 ) ;
V_18 -> V_19 &= ~ V_323 ;
F_58 ( & V_18 -> V_184 ) ;
V_18 -> V_324 = 0 ;
V_116 = strlen ( V_9 ) ;
} else
V_116 = - V_86 ;
} else {
V_18 -> V_324 = 0 ;
V_116 = strlen ( V_9 ) ;
}
break;
case 1 :
if ( ! ( V_18 -> V_19 & V_323 ) ) {
V_116 = F_111 ( V_18 -> V_197 ) ;
if ( ! V_116 ) {
F_56 ( & V_18 -> V_184 ) ;
V_18 -> V_19 |= V_323 ;
F_58 ( & V_18 -> V_184 ) ;
V_18 -> V_324 = 1 ;
V_116 = strlen ( V_9 ) ;
} else
V_116 = - V_86 ;
} else {
V_18 -> V_324 = 1 ;
V_116 = strlen ( V_9 ) ;
}
break;
default:
V_116 = - V_75 ;
break;
}
return V_116 ;
}
static int
F_112 ( struct V_17 * V_18 , int V_183 )
{
if ( V_183 == 0 || V_183 == 1 ) {
V_18 -> V_324 = V_183 ;
return 0 ;
}
F_29 ( V_18 , V_104 , V_122 ,
L_97
L_98
L_99 , V_183 ) ;
V_18 -> V_324 = 1 ;
return - V_75 ;
}
static T_1
F_113 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_73 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_183 , V_116 = - 1 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_75 ;
if ( sscanf ( V_9 , L_43 , & V_183 ) != 1 )
return - V_75 ;
if ( V_183 != 1 )
return - V_75 ;
if ( V_18 -> V_19 & V_323 )
V_116 = F_114 ( V_18 -> V_197 ) ;
if ( V_116 == 0 )
return strlen ( V_9 ) ;
else
return - V_86 ;
}
static T_1
F_115 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_73 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_195 * V_196 = V_18 -> V_197 ;
int V_183 = 0 , V_116 = - V_75 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_75 ;
if ( sscanf ( V_9 , L_43 , & V_183 ) != 1 )
return - V_75 ;
if ( V_183 < 0 )
return - V_75 ;
if ( V_183 == 0 ) {
if ( V_18 -> V_325 > 0 ) {
F_116 ( V_196 ) ;
V_18 -> V_325 = 0 ;
}
return strlen ( V_9 ) ;
}
if ( V_18 -> V_325 > 0 ) {
F_29 ( V_18 , V_104 , V_122 ,
L_100
L_101 ,
V_18 -> V_325 ) ;
return - V_326 ;
}
if ( V_183 <= V_327 )
V_18 -> V_325 = V_183 ;
else {
F_29 ( V_18 , V_104 , V_122 ,
L_102
L_103 , V_183 ) ;
return - V_75 ;
}
V_116 = F_117 ( V_18 , V_18 -> V_325 ) ;
if ( V_116 ) {
V_18 -> V_325 = 0 ;
V_116 = - V_86 ;
} else
V_116 = strlen ( V_9 ) ;
return V_116 ;
}
static int
F_118 ( struct V_17 * V_18 , int V_183 )
{
if ( V_183 >= 0 && V_183 <= V_327 ) {
V_18 -> V_325 = V_183 ;
return 0 ;
}
F_29 ( V_18 , V_104 , V_122 ,
L_104
L_103 , V_183 ) ;
return - V_75 ;
}
static int
F_119 ( struct V_14 * V_15 , int V_183 )
{
struct V_12 * V_13 = F_85 ( V_15 ) ;
struct V_257 * V_258 , * V_328 ;
if ( V_183 == V_15 -> V_329 )
return 0 ;
if ( ( V_183 < 0 ) || ( V_183 > 60000 ) )
return - V_75 ;
V_15 -> V_329 = V_183 ;
F_56 ( V_13 -> V_259 ) ;
F_120 (ndlp, next_ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_87 ( V_258 ) )
continue;
if ( V_258 -> V_330 == V_331 )
continue;
V_258 -> V_332 = V_15 -> V_333 ;
}
F_58 ( V_13 -> V_259 ) ;
return 0 ;
}
static T_1
F_121 ( struct V_293 * V_294 , struct V_295 * V_296 ,
struct V_297 * V_298 ,
char * V_9 , T_8 V_299 , T_3 V_73 )
{
T_3 V_334 ;
struct V_5 * V_6 = F_106 ( V_296 , struct V_5 , V_296 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_38 >= V_128 )
return - V_86 ;
if ( ( V_299 + V_73 ) > V_335 )
return - V_336 ;
if ( V_73 == 0 ) return 0 ;
if ( V_299 % 4 || V_73 % 4 || ( unsigned long ) V_9 % 4 )
return - V_75 ;
if ( ! ( V_15 -> V_70 & V_84 ) ) {
return - V_86 ;
}
F_56 ( & V_18 -> V_184 ) ;
for ( V_334 = 0 ; V_334 < V_73 ; V_334 += sizeof( T_5 ) )
F_42 ( * ( ( T_5 * ) ( V_9 + V_334 ) ) ,
V_18 -> V_337 + V_299 + V_334 ) ;
F_58 ( & V_18 -> V_184 ) ;
return V_73 ;
}
static T_1
F_122 ( struct V_293 * V_294 , struct V_295 * V_296 ,
struct V_297 * V_298 ,
char * V_9 , T_8 V_299 , T_3 V_73 )
{
T_3 V_334 ;
T_5 * V_338 ;
struct V_5 * V_6 = F_106 ( V_296 , struct V_5 , V_296 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_38 >= V_128 )
return - V_86 ;
if ( V_299 > V_335 )
return - V_336 ;
if ( ( V_299 + V_73 ) > V_335 )
V_73 = V_335 - V_299 ;
if ( V_73 == 0 ) return 0 ;
if ( V_299 % 4 || V_73 % 4 || ( unsigned long ) V_9 % 4 )
return - V_75 ;
F_56 ( & V_18 -> V_184 ) ;
for ( V_334 = 0 ; V_334 < V_73 ; V_334 += sizeof( T_5 ) ) {
V_338 = ( T_5 * ) ( V_9 + V_334 ) ;
* V_338 = F_41 ( V_18 -> V_337 + V_299 + V_334 ) ;
}
F_58 ( & V_18 -> V_184 ) ;
return V_73 ;
}
static void
F_123 ( struct V_17 * V_18 )
{
V_18 -> V_339 . V_142 = V_340 ;
V_18 -> V_339 . V_341 = 0 ;
if ( V_18 -> V_339 . V_342 ) {
F_31 ( V_18 -> V_339 . V_342 ,
V_18 -> V_87 ) ;
V_18 -> V_339 . V_342 = NULL ;
}
}
static T_1
F_124 ( struct V_293 * V_294 , struct V_295 * V_296 ,
struct V_297 * V_298 ,
char * V_9 , T_8 V_299 , T_3 V_73 )
{
struct V_5 * V_6 = F_106 ( V_296 , struct V_5 , V_296 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_343 * V_342 = NULL ;
if ( ( V_73 + V_299 ) > V_344 )
return - V_336 ;
if ( V_299 % 4 || V_73 % 4 || ( unsigned long ) V_9 % 4 )
return - V_75 ;
if ( V_73 == 0 )
return 0 ;
if ( V_299 == 0 ) {
V_342 = F_26 ( V_18 -> V_87 , V_88 ) ;
if ( ! V_342 )
return - V_89 ;
memset ( V_342 , 0 , sizeof ( T_4 ) ) ;
}
F_56 ( & V_18 -> V_184 ) ;
if ( V_299 == 0 ) {
if ( V_18 -> V_339 . V_342 )
F_31 ( V_342 , V_18 -> V_87 ) ;
else
V_18 -> V_339 . V_342 = V_342 ;
V_18 -> V_339 . V_142 = V_345 ;
} else {
if ( V_18 -> V_339 . V_142 != V_345 ||
V_18 -> V_339 . V_341 != V_299 ||
V_18 -> V_339 . V_342 == NULL ) {
F_123 ( V_18 ) ;
F_58 ( & V_18 -> V_184 ) ;
return - V_346 ;
}
}
memcpy ( ( V_347 * ) & V_18 -> V_339 . V_342 -> V_90 . V_91 + V_299 ,
V_9 , V_73 ) ;
V_18 -> V_339 . V_341 = V_299 + V_73 ;
F_58 ( & V_18 -> V_184 ) ;
return V_73 ;
}
static T_1
F_125 ( struct V_293 * V_294 , struct V_295 * V_296 ,
struct V_297 * V_298 ,
char * V_9 , T_8 V_299 , T_3 V_73 )
{
struct V_5 * V_6 = F_106 ( V_296 , struct V_5 , V_296 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_116 ;
T_6 * V_154 ;
if ( V_299 > V_344 )
return - V_336 ;
if ( ( V_73 + V_299 ) > V_344 )
V_73 = V_344 - V_299 ;
if ( V_299 % 4 || V_73 % 4 || ( unsigned long ) V_9 % 4 )
return - V_75 ;
if ( V_299 && V_73 == 0 )
return 0 ;
F_56 ( & V_18 -> V_184 ) ;
if ( V_18 -> V_241 == V_242 ) {
F_123 ( V_18 ) ;
F_58 ( & V_18 -> V_184 ) ;
return - V_143 ;
}
if ( V_299 == 0 &&
V_18 -> V_339 . V_142 == V_345 &&
V_18 -> V_339 . V_341 >= 2 * sizeof( T_5 ) ) {
V_154 = & V_18 -> V_339 . V_342 -> V_90 . V_91 ;
switch ( V_154 -> V_92 ) {
case V_348 :
case V_93 :
case V_349 :
case V_350 :
case V_351 :
case V_352 :
case V_353 :
case V_354 :
case V_355 :
case V_356 :
case V_357 :
case V_358 :
if ( ! ( V_15 -> V_70 & V_84 ) ) {
F_126 ( V_121 L_105
L_106 ,
V_154 -> V_92 ) ;
F_123 ( V_18 ) ;
F_58 ( & V_18 -> V_184 ) ;
return - V_86 ;
}
case V_359 :
case V_360 :
case V_361 :
case V_362 :
case V_157 :
case V_363 :
case V_364 :
case V_365 :
case V_366 :
case V_367 :
case V_368 :
case V_369 :
case V_370 :
case V_371 :
case V_372 :
case V_373 :
case V_374 :
case V_375 :
case V_376 :
case V_377 :
case V_378 :
case V_379 :
break;
case V_380 :
case V_381 :
if ( V_18 -> V_382 == V_383 ) {
F_126 ( V_121 L_105
L_107 , V_154 -> V_92 ) ;
F_123 ( V_18 ) ;
F_58 ( & V_18 -> V_184 ) ;
return - V_86 ;
}
break;
case V_384 :
case V_385 :
case V_386 :
case V_387 :
case V_388 :
case V_389 :
F_126 ( V_121 L_108 ,
V_154 -> V_92 ) ;
F_123 ( V_18 ) ;
F_58 ( & V_18 -> V_184 ) ;
return - V_86 ;
default:
F_126 ( V_121 L_109 ,
V_154 -> V_92 ) ;
F_123 ( V_18 ) ;
F_58 ( & V_18 -> V_184 ) ;
return - V_86 ;
}
if ( V_18 -> V_159 -> V_390 &&
V_154 -> V_92 != V_368 &&
V_154 -> V_92 != V_356 &&
V_154 -> V_92 != V_360 &&
V_154 -> V_92 != V_377 )
F_29 ( V_18 , V_121 , V_105 ,
L_110
L_111 ,
V_154 -> V_92 ) ;
V_18 -> V_339 . V_342 -> V_15 = V_15 ;
if ( V_18 -> V_33 . V_34 & V_85 ) {
F_123 ( V_18 ) ;
F_58 ( & V_18 -> V_184 ) ;
return - V_346 ;
}
if ( ( V_15 -> V_70 & V_84 ) ||
( ! ( V_18 -> V_33 . V_34 & V_156 ) ) ) {
F_58 ( & V_18 -> V_184 ) ;
V_116 = F_127 ( V_18 ,
V_18 -> V_339 . V_342 ,
V_391 ) ;
F_56 ( & V_18 -> V_184 ) ;
} else {
F_58 ( & V_18 -> V_184 ) ;
V_116 = F_27 ( V_18 ,
V_18 -> V_339 . V_342 ,
F_67 ( V_18 , V_154 -> V_92 ) * V_392 ) ;
F_56 ( & V_18 -> V_184 ) ;
}
if ( V_116 != V_97 ) {
if ( V_116 == V_107 ) {
V_18 -> V_339 . V_342 = NULL ;
}
F_123 ( V_18 ) ;
F_58 ( & V_18 -> V_184 ) ;
return ( V_116 == V_107 ) ? - V_393 : - V_394 ;
}
V_18 -> V_339 . V_142 = V_395 ;
}
else if ( V_18 -> V_339 . V_341 != V_299 ||
V_18 -> V_339 . V_142 != V_395 ) {
F_126 ( V_121 L_112 ) ;
F_123 ( V_18 ) ;
F_58 ( & V_18 -> V_184 ) ;
return - V_346 ;
}
memcpy ( V_9 , ( V_347 * ) & V_154 + V_299 , V_73 ) ;
V_18 -> V_339 . V_341 = V_299 + V_73 ;
if ( V_18 -> V_339 . V_341 == V_344 )
F_123 ( V_18 ) ;
F_58 ( & V_18 -> V_184 ) ;
return V_73 ;
}
int
F_128 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = F_85 ( V_15 ) ;
int error ;
error = F_129 ( & V_13 -> V_396 . V_296 ,
& V_397 ) ;
if ( error || V_15 -> V_177 == V_398 )
goto V_399;
error = F_129 ( & V_13 -> V_396 . V_296 ,
& V_400 ) ;
if ( error )
goto V_401;
error = F_129 ( & V_13 -> V_396 . V_296 ,
& V_402 ) ;
if ( error )
goto V_403;
return 0 ;
V_403:
F_130 ( & V_13 -> V_396 . V_296 , & V_400 ) ;
V_401:
F_130 ( & V_13 -> V_396 . V_296 ,
& V_397 ) ;
V_399:
return error ;
}
void
F_131 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = F_85 ( V_15 ) ;
F_130 ( & V_13 -> V_396 . V_296 ,
& V_397 ) ;
if ( V_15 -> V_177 == V_398 )
return;
F_130 ( & V_13 -> V_396 . V_296 , & V_402 ) ;
F_130 ( & V_13 -> V_396 . V_296 , & V_400 ) ;
}
static void
F_132 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
F_133 ( V_13 ) = V_15 -> V_404 ;
}
static void
F_134 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_56 ( V_13 -> V_259 ) ;
if ( V_15 -> V_177 == V_398 ) {
F_135 ( V_13 ) = V_405 ;
} else if ( F_136 ( V_18 ) ) {
if ( V_18 -> V_68 == V_69 ) {
if ( V_15 -> V_70 & V_71 )
F_135 ( V_13 ) = V_406 ;
else
F_135 ( V_13 ) = V_407 ;
} else {
if ( V_15 -> V_70 & V_72 )
F_135 ( V_13 ) = V_408 ;
else
F_135 ( V_13 ) = V_409 ;
}
} else
F_135 ( V_13 ) = V_410 ;
F_58 ( V_13 -> V_259 ) ;
}
static void
F_137 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_56 ( V_13 -> V_259 ) ;
if ( V_15 -> V_70 & V_84 )
F_138 ( V_13 ) = V_411 ;
else {
switch ( V_18 -> V_45 ) {
case V_46 :
case V_50 :
F_138 ( V_13 ) = V_412 ;
break;
case V_53 :
case V_54 :
case V_55 :
F_138 ( V_13 ) = V_413 ;
break;
case V_51 :
F_138 ( V_13 ) = V_414 ;
break;
default:
F_138 ( V_13 ) = V_415 ;
break;
}
}
F_58 ( V_13 -> V_259 ) ;
}
static void
F_139 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_56 ( V_13 -> V_259 ) ;
if ( F_136 ( V_18 ) ) {
switch( V_18 -> V_416 ) {
case V_417 :
F_140 ( V_13 ) = V_418 ;
break;
case V_419 :
F_140 ( V_13 ) = V_420 ;
break;
case V_421 :
F_140 ( V_13 ) = V_422 ;
break;
case V_423 :
F_140 ( V_13 ) = V_424 ;
break;
case V_425 :
F_140 ( V_13 ) = V_426 ;
break;
case V_427 :
F_140 ( V_13 ) = V_428 ;
break;
default:
F_140 ( V_13 ) = V_429 ;
break;
}
} else
F_140 ( V_13 ) = V_429 ;
F_58 ( V_13 -> V_259 ) ;
}
static void
F_141 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_9 V_430 ;
F_56 ( V_13 -> V_259 ) ;
if ( ( V_15 -> V_70 & V_72 ) ||
( ( V_18 -> V_68 == V_69 ) &&
( V_15 -> V_70 & V_71 ) ) )
V_430 = F_72 ( V_18 -> V_431 . V_432 . V_90 . V_304 ) ;
else
V_430 = 0 ;
F_58 ( V_13 -> V_259 ) ;
F_142 ( V_13 ) = V_430 ;
}
static struct V_433 *
F_143 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_113 * V_114 = & V_18 -> V_33 ;
struct V_433 * V_434 = & V_18 -> V_435 ;
struct V_436 * V_437 = & V_114 -> V_438 ;
T_4 * V_81 ;
T_6 * V_154 ;
unsigned long V_439 ;
int V_116 = 0 ;
if ( V_18 -> V_45 < V_50 ||
! V_18 -> V_87 ||
( V_18 -> V_33 . V_34 & V_156 ) == 0 )
return NULL ;
if ( V_18 -> V_33 . V_34 & V_85 )
return NULL ;
V_81 = F_26 ( V_18 -> V_87 , V_88 ) ;
if ( ! V_81 )
return NULL ;
memset ( V_81 , 0 , sizeof ( T_4 ) ) ;
V_154 = & V_81 -> V_90 . V_91 ;
V_154 -> V_92 = V_364 ;
V_154 -> V_94 = V_95 ;
V_81 -> V_158 = NULL ;
V_81 -> V_15 = V_15 ;
if ( V_15 -> V_70 & V_84 )
V_116 = F_127 ( V_18 , V_81 , V_391 ) ;
else
V_116 = F_27 ( V_18 , V_81 , V_18 -> V_102 * 2 ) ;
if ( V_116 != V_97 ) {
if ( V_116 != V_107 )
F_31 ( V_81 , V_18 -> V_87 ) ;
return NULL ;
}
memset ( V_434 , 0 , sizeof ( struct V_433 ) ) ;
V_434 -> V_440 = V_154 -> V_162 . V_441 . V_442 ;
V_434 -> V_443 = ( V_154 -> V_162 . V_441 . V_444 * 256 ) ;
V_434 -> V_445 = V_154 -> V_162 . V_441 . V_446 ;
V_434 -> V_447 = ( V_154 -> V_162 . V_441 . V_448 * 256 ) ;
memset ( V_81 , 0 , sizeof ( T_4 ) ) ;
V_154 -> V_92 = V_367 ;
V_154 -> V_94 = V_95 ;
V_81 -> V_158 = NULL ;
V_81 -> V_15 = V_15 ;
if ( V_15 -> V_70 & V_84 )
V_116 = F_127 ( V_18 , V_81 , V_391 ) ;
else
V_116 = F_27 ( V_18 , V_81 , V_18 -> V_102 * 2 ) ;
if ( V_116 != V_97 ) {
if ( V_116 != V_107 )
F_31 ( V_81 , V_18 -> V_87 ) ;
return NULL ;
}
V_434 -> V_449 = V_154 -> V_162 . V_450 . V_451 ;
V_434 -> V_452 = V_154 -> V_162 . V_450 . V_453 ;
V_434 -> V_454 = V_154 -> V_162 . V_450 . V_455 ;
V_434 -> V_456 = V_154 -> V_162 . V_450 . V_457 ;
V_434 -> V_458 = V_154 -> V_162 . V_450 . V_459 ;
V_434 -> V_460 = V_154 -> V_162 . V_450 . V_461 ;
V_434 -> V_462 = V_154 -> V_162 . V_450 . V_461 ;
V_434 -> V_449 -= V_437 -> V_449 ;
V_434 -> V_452 -= V_437 -> V_452 ;
V_434 -> V_454 -= V_437 -> V_454 ;
V_434 -> V_456 -= V_437 -> V_456 ;
V_434 -> V_458 -= V_437 -> V_458 ;
V_434 -> V_460 -= V_437 -> V_460 ;
V_434 -> V_462 -= V_437 -> V_462 ;
if ( V_18 -> V_19 & V_463 ) {
V_434 -> V_464 = - 1 ;
V_434 -> V_465 = ( V_18 -> V_466 >> 1 ) ;
V_434 -> V_465 -= V_437 -> V_466 ;
} else if ( V_18 -> V_68 == V_69 ) {
V_434 -> V_464 = ( V_18 -> V_467 >> 1 ) ;
V_434 -> V_464 -= V_437 -> V_466 ;
V_434 -> V_465 = - 1 ;
} else {
V_434 -> V_464 = - 1 ;
V_434 -> V_465 = ( V_18 -> V_467 >> 1 ) ;
V_434 -> V_465 -= V_437 -> V_466 ;
}
V_434 -> V_468 = - 1 ;
V_439 = F_144 () ;
if ( V_439 < V_114 -> V_469 )
V_434 -> V_470 = V_439 +
( ( unsigned long ) - 1 - V_114 -> V_469 ) ;
else
V_434 -> V_470 = V_439 - V_114 -> V_469 ;
F_31 ( V_81 , V_18 -> V_87 ) ;
return V_434 ;
}
static void
F_145 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_113 * V_114 = & V_18 -> V_33 ;
struct V_436 * V_437 = & V_114 -> V_438 ;
T_4 * V_81 ;
T_6 * V_154 ;
int V_116 = 0 ;
if ( V_18 -> V_33 . V_34 & V_85 )
return;
V_81 = F_26 ( V_18 -> V_87 , V_88 ) ;
if ( ! V_81 )
return;
memset ( V_81 , 0 , sizeof( T_4 ) ) ;
V_154 = & V_81 -> V_90 . V_91 ;
V_154 -> V_92 = V_364 ;
V_154 -> V_94 = V_95 ;
V_154 -> V_162 . V_471 [ 0 ] = 0x1 ;
V_81 -> V_158 = NULL ;
V_81 -> V_15 = V_15 ;
if ( ( V_15 -> V_70 & V_84 ) ||
( ! ( V_114 -> V_34 & V_156 ) ) )
V_116 = F_127 ( V_18 , V_81 , V_391 ) ;
else
V_116 = F_27 ( V_18 , V_81 , V_18 -> V_102 * 2 ) ;
if ( V_116 != V_97 ) {
if ( V_116 != V_107 )
F_31 ( V_81 , V_18 -> V_87 ) ;
return;
}
memset ( V_81 , 0 , sizeof( T_4 ) ) ;
V_154 -> V_92 = V_367 ;
V_154 -> V_94 = V_95 ;
V_81 -> V_158 = NULL ;
V_81 -> V_15 = V_15 ;
if ( ( V_15 -> V_70 & V_84 ) ||
( ! ( V_114 -> V_34 & V_156 ) ) )
V_116 = F_127 ( V_18 , V_81 , V_391 ) ;
else
V_116 = F_27 ( V_18 , V_81 , V_18 -> V_102 * 2 ) ;
if ( V_116 != V_97 ) {
if ( V_116 != V_107 )
F_31 ( V_81 , V_18 -> V_87 ) ;
return;
}
V_437 -> V_449 = V_154 -> V_162 . V_450 . V_451 ;
V_437 -> V_452 = V_154 -> V_162 . V_450 . V_453 ;
V_437 -> V_454 = V_154 -> V_162 . V_450 . V_455 ;
V_437 -> V_456 = V_154 -> V_162 . V_450 . V_457 ;
V_437 -> V_458 = V_154 -> V_162 . V_450 . V_459 ;
V_437 -> V_460 = V_154 -> V_162 . V_450 . V_461 ;
V_437 -> V_462 = V_154 -> V_162 . V_450 . V_461 ;
if ( V_18 -> V_19 & V_463 )
V_437 -> V_466 = ( V_18 -> V_466 >> 1 ) ;
else
V_437 -> V_466 = ( V_18 -> V_467 >> 1 ) ;
V_114 -> V_469 = F_144 () ;
F_31 ( V_81 , V_18 -> V_87 ) ;
return;
}
static struct V_257 *
F_146 ( struct V_472 * V_473 )
{
struct V_12 * V_13 = F_147 ( V_473 -> V_6 . V_474 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_257 * V_258 ;
F_56 ( V_13 -> V_259 ) ;
F_86 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( F_87 ( V_258 ) &&
V_258 -> V_330 == V_475 &&
V_473 -> V_476 == V_258 -> V_477 ) {
F_58 ( V_13 -> V_259 ) ;
return V_258 ;
}
}
F_58 ( V_13 -> V_259 ) ;
return NULL ;
}
static void
F_148 ( struct V_472 * V_473 )
{
struct V_257 * V_258 = F_146 ( V_473 ) ;
F_149 ( V_473 ) = V_258 ? V_258 -> V_478 : - 1 ;
}
static void
F_150 ( struct V_472 * V_473 )
{
struct V_257 * V_258 = F_146 ( V_473 ) ;
F_151 ( V_473 ) =
V_258 ? F_72 ( V_258 -> V_479 . V_90 . V_304 ) : 0 ;
}
static void
F_152 ( struct V_472 * V_473 )
{
struct V_257 * V_258 = F_146 ( V_473 ) ;
F_153 ( V_473 ) =
V_258 ? F_72 ( V_258 -> V_303 . V_90 . V_304 ) : 0 ;
}
static void
F_154 ( struct V_480 * V_260 , T_5 V_481 )
{
if ( V_481 )
V_260 -> V_261 = V_481 ;
else
V_260 -> V_261 = 1 ;
}
static void
F_155 ( struct V_482 * V_482 )
{
struct V_14 * V_15 = * (struct V_14 * * ) V_482 -> V_483 ;
if ( V_15 -> V_56 == V_65 )
F_156 ( V_15 , V_484 , 0 , 0 ) ;
}
static void
F_157 ( struct V_17 * V_18 , T_5 V_485 )
{
V_18 -> V_486 = V_485 ;
}
void
F_158 ( struct V_17 * V_18 )
{
F_159 ( V_18 , V_487 ) ;
F_160 ( V_18 , V_488 ) ;
F_161 ( V_18 , V_489 ) ;
F_162 ( V_18 , V_490 ) ;
F_163 ( V_18 , V_491 ) ;
F_164 ( V_18 , V_492 ) ;
F_165 ( V_18 , V_493 ) ;
F_108 ( V_18 , V_494 ) ;
F_166 ( V_18 , V_495 ) ;
F_167 ( V_18 , V_496 ) ;
F_168 ( V_18 , V_497 ) ;
F_169 ( V_18 , V_498 ) ;
F_170 ( V_18 , V_499 ) ;
F_171 ( V_18 , V_500 ) ;
F_172 ( V_18 , V_501 ) ;
F_173 ( V_18 , V_502 ) ;
F_174 ( V_18 , V_503 ) ;
F_175 ( V_18 , V_504 ) ;
if ( V_18 -> V_38 == V_128 )
V_18 -> V_180 = 0 ;
else
V_18 -> V_180 = V_505 ;
V_18 -> V_244 = 0L ;
V_18 -> V_237 = 0L ;
F_176 ( V_18 , V_506 ) ;
F_177 ( V_18 , V_507 ) ;
F_178 ( V_18 , V_508 ) ;
F_157 ( V_18 , V_509 ) ;
F_112 ( V_18 , V_510 ) ;
F_118 ( V_18 , V_511 ) ;
F_179 ( V_18 , V_512 ) ;
F_180 ( V_18 , V_513 ) ;
V_18 -> V_193 = 1 ;
return;
}
void
F_181 ( struct V_14 * V_15 )
{
F_182 ( V_15 , V_509 ) ;
F_183 ( V_15 , V_514 ) ;
F_184 ( V_15 , V_515 ) ;
F_185 ( V_15 , V_263 ) ;
F_82 ( V_15 , V_516 ) ;
F_186 ( V_15 , V_517 ) ;
F_91 ( V_15 , V_518 ) ;
F_187 ( V_15 , V_519 ) ;
F_188 ( V_15 , V_520 ) ;
F_189 ( V_15 , V_521 ) ;
F_190 ( V_15 , V_522 ) ;
F_191 ( V_15 , V_523 ) ;
F_192 ( V_15 , V_524 ) ;
F_193 ( V_15 , V_525 ) ;
F_194 ( V_15 , V_526 ) ;
return;
}
