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
static int
F_39 ( struct V_17 * V_18 )
{
struct V_126 V_127 ;
int V_3 ;
F_40 ( V_18 -> V_128 . V_90 . V_129 . V_130 ,
& V_127 . V_131 ) ;
for ( V_3 = 0 ; V_3 < V_132 ; V_3 ++ ) {
F_36 ( 10 ) ;
F_40 ( V_18 -> V_128 . V_90 . V_129 . V_130 ,
& V_127 . V_131 ) ;
if ( ! F_41 ( V_133 , & V_127 ) )
continue;
if ( ! F_41 ( V_134 , & V_127 ) )
continue;
if ( ! F_41 ( V_135 , & V_127 ) )
continue;
break;
}
if ( V_3 < V_132 )
return 0 ;
else
return - V_108 ;
}
static T_1
F_42 ( struct V_17 * V_18 , T_5 V_136 )
{
struct V_109 V_110 ;
struct V_137 * V_138 = V_18 -> V_139 ;
T_5 V_140 ;
int V_74 = 0 ;
int V_116 ;
if ( ! V_18 -> V_123 )
return - V_108 ;
if ( ( V_18 -> V_38 < V_141 ) ||
( F_41 ( V_142 , & V_18 -> V_128 . V_143 ) !=
V_144 ) )
return - V_86 ;
if ( ! V_138 -> V_145 )
return - V_86 ;
if ( V_18 -> V_146 ) {
F_43 ( V_138 ) ;
V_18 -> V_146 = 0 ;
}
V_74 = F_32 ( V_18 , V_124 ) ;
if ( V_74 != 0 )
return V_74 ;
F_36 ( 100 ) ;
V_140 = F_44 ( V_18 -> V_128 . V_147 +
V_148 ) ;
if ( V_136 == V_149 )
V_140 |= V_150 ;
else if ( V_136 == V_151 )
V_140 |= V_152 ;
else if ( V_136 == V_153 )
V_140 |= V_154 ;
F_45 ( V_140 , V_18 -> V_128 . V_147 +
V_148 ) ;
F_44 ( V_18 -> V_128 . V_147 + V_148 ) ;
V_116 = F_39 ( V_18 ) ;
if ( V_116 )
return - V_108 ;
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
F_46 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_155 ) ;
}
static T_1
F_47 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
char * V_156 ;
if ( V_18 -> V_45 == V_51 )
V_156 = L_31 ;
else if ( V_18 -> V_45 == V_47 )
V_156 = L_32 ;
else if ( V_18 -> V_45 == V_48 )
V_156 = L_33 ;
else
V_156 = L_34 ;
return snprintf ( V_9 , V_10 , L_8 , V_156 ) ;
}
static T_1
F_48 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_73 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_109 V_110 ;
int V_74 = 0 ;
int V_116 ;
if ( ! V_18 -> V_123 )
return - V_157 ;
F_49 ( V_15 , V_104 , V_122 ,
L_35 , V_9 ) ;
F_33 ( & V_110 ) ;
if( strncmp ( V_9 , L_34 , sizeof( L_34 ) - 1 ) == 0 ) {
V_116 = F_34 ( V_18 , & V_74 , & V_110 ,
V_125 ) ;
if ( V_116 == 0 )
return - V_89 ;
F_35 ( & V_110 ) ;
} else if ( strncmp ( V_9 , L_33 , sizeof( L_33 ) - 1 ) == 0 )
V_74 = F_32 ( V_18 , V_124 ) ;
else if ( strncmp ( V_9 , L_36 , sizeof( L_36 ) - 1 ) == 0 )
if ( V_18 -> V_38 == V_141 )
return - V_75 ;
else
V_74 = F_32 ( V_18 , V_158 ) ;
else if ( strncmp ( V_9 , L_31 , sizeof( L_31 ) - 1 ) == 0 )
if ( V_18 -> V_38 == V_141 )
return - V_75 ;
else
V_74 = F_32 ( V_18 , V_159 ) ;
else if ( strncmp ( V_9 , L_37 , sizeof( L_37 ) - 1 ) == 0 )
V_74 = F_42 ( V_18 , V_149 ) ;
else if ( strncmp ( V_9 , L_38 , sizeof( L_38 ) - 1 ) == 0 )
V_74 = F_42 ( V_18 , V_151 ) ;
else if ( strncmp ( V_9 , L_39 , sizeof( L_39 ) - 1 ) == 0 )
V_74 = F_42 ( V_18 , V_153 ) ;
else
return - V_75 ;
if ( ! V_74 )
return strlen ( V_9 ) ;
else
return - V_108 ;
}
static int
F_50 ( struct V_17 * V_18 ,
T_5 * V_160 , T_5 * V_161 ,
T_5 * V_162 , T_5 * V_163 ,
T_5 * V_164 , T_5 * V_165 )
{
struct V_166 * V_167 ;
T_4 * V_81 ;
T_6 * V_168 ;
int V_116 = 0 ;
T_5 V_169 ;
if ( V_18 -> V_45 < V_50 ||
! V_18 -> V_87 ||
( V_18 -> V_33 . V_34 & V_170 ) == 0 )
return 0 ;
if ( V_18 -> V_33 . V_34 & V_85 )
return 0 ;
V_81 = F_26 ( V_18 -> V_87 , V_88 ) ;
if ( ! V_81 )
return 0 ;
memset ( V_81 , 0 , sizeof ( T_4 ) ) ;
V_168 = & V_81 -> V_90 . V_91 ;
V_168 -> V_92 = V_171 ;
V_168 -> V_94 = V_95 ;
V_81 -> V_172 = NULL ;
if ( V_18 -> V_173 -> V_70 & V_84 )
V_116 = V_174 ;
else
V_116 = F_27 ( V_18 , V_81 , V_18 -> V_102 * 2 ) ;
if ( V_116 != V_97 ) {
if ( V_116 != V_107 )
F_31 ( V_81 , V_18 -> V_87 ) ;
return 0 ;
}
if ( V_18 -> V_38 == V_141 ) {
V_167 = & V_81 -> V_90 . V_175 . V_176 . V_167 ;
if ( V_162 )
* V_162 = F_41 ( V_177 , V_167 ) ;
if ( V_163 )
* V_163 = F_41 ( V_177 , V_167 ) -
V_18 -> V_128 . V_178 . V_179 ;
if ( V_160 )
* V_160 = F_41 ( V_180 , V_167 ) ;
if ( V_161 )
* V_161 = F_41 ( V_180 , V_167 ) -
V_18 -> V_128 . V_178 . V_181 ;
V_169 = ( F_41 ( V_182 , V_167 ) > 0 ) ?
( F_41 ( V_182 , V_167 ) - 1 ) : 0 ;
if ( V_164 )
* V_164 = V_169 ;
if ( V_165 )
* V_165 = V_169 - V_18 -> V_128 . V_178 . V_183 ;
} else {
if ( V_162 )
* V_162 = V_168 -> V_176 . V_184 . V_185 ;
if ( V_163 )
* V_163 = V_168 -> V_176 . V_184 . V_186 ;
if ( V_160 )
* V_160 = V_168 -> V_176 . V_184 . V_187 ;
if ( V_161 )
* V_161 = V_168 -> V_176 . V_184 . V_188 ;
if ( V_164 )
* V_164 = V_168 -> V_176 . V_184 . V_169 ;
if ( V_165 )
* V_165 = V_168 -> V_176 . V_184 . V_189 ;
}
F_31 ( V_81 , V_18 -> V_87 ) ;
return 1 ;
}
static T_1
F_51 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_5 V_115 ;
if ( F_50 ( V_18 , NULL , NULL , & V_115 , NULL , NULL , NULL ) )
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
T_5 V_115 , V_190 ;
if ( F_50 ( V_18 , NULL , NULL , & V_115 , & V_190 , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_9 , ( V_115 - V_190 ) ) ;
return snprintf ( V_9 , V_10 , L_18 ) ;
}
static T_1
F_53 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_5 V_115 ;
if ( F_50 ( V_18 , & V_115 , NULL , NULL , NULL , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_9 , V_115 ) ;
return snprintf ( V_9 , V_10 , L_18 ) ;
}
static T_1
F_54 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_5 V_115 , V_190 ;
if ( F_50 ( V_18 , & V_115 , & V_190 , NULL , NULL , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_9 , ( V_115 - V_190 ) ) ;
return snprintf ( V_9 , V_10 , L_18 ) ;
}
static T_1
F_55 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_5 V_115 ;
if ( F_50 ( V_18 , NULL , NULL , NULL , NULL , & V_115 , NULL ) )
return snprintf ( V_9 , V_10 , L_9 , V_115 ) ;
return snprintf ( V_9 , V_10 , L_18 ) ;
}
static T_1
F_56 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_5 V_115 , V_190 ;
if ( F_50 ( V_18 , NULL , NULL , NULL , NULL , & V_115 , & V_190 ) )
return snprintf ( V_9 , V_10 , L_9 , ( V_115 - V_190 ) ) ;
return snprintf ( V_9 , V_10 , L_18 ) ;
}
static T_1
F_57 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( ! ( V_18 -> V_169 ) )
return snprintf ( V_9 , V_10 , L_40 ) ;
if ( V_15 -> V_191 == V_192 )
return snprintf ( V_9 , V_10 , L_41 ) ;
return snprintf ( V_9 , V_10 , L_42 , V_15 -> V_193 ) ;
}
static T_1
F_58 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_43 , V_18 -> V_194 ) ;
}
static T_1
F_59 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_73 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_5 V_195 ;
T_5 V_196 ;
int V_197 = 0 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_75 ;
if ( sscanf ( V_9 , L_44 , & V_197 ) != 1 )
return - V_75 ;
if ( ( V_197 & 0x3 ) != V_197 )
return - V_75 ;
if ( V_18 -> V_38 == V_141 )
V_197 = 0 ;
F_49 ( V_15 , V_104 , V_122 ,
L_45 ,
V_18 -> V_194 , V_197 ) ;
F_60 ( & V_18 -> V_198 ) ;
V_196 = V_18 -> V_194 ;
if ( V_197 & V_199 ) {
if ( ( V_197 & V_200 ) &&
! ( V_196 & V_200 ) ) {
if ( F_40 ( V_18 -> V_201 , & V_195 ) ) {
F_61 ( & V_18 -> V_198 ) ;
return - V_75 ;
}
V_195 &= ~ ( V_202 << V_203 ) ;
F_45 ( V_195 , V_18 -> V_201 ) ;
F_44 ( V_18 -> V_201 ) ;
F_62 ( V_18 ) ;
}
} else if ( V_197 != 0x0 ) {
F_61 ( & V_18 -> V_198 ) ;
return - V_75 ;
}
if ( ! ( V_197 & V_200 ) &&
( V_196 & V_200 ) )
{
F_61 ( & V_18 -> V_198 ) ;
F_63 ( & V_18 -> V_204 ) ;
F_60 ( & V_18 -> V_198 ) ;
if ( F_40 ( V_18 -> V_201 , & V_195 ) ) {
F_61 ( & V_18 -> V_198 ) ;
return - V_75 ;
}
V_195 |= ( V_202 << V_203 ) ;
F_45 ( V_195 , V_18 -> V_201 ) ;
F_44 ( V_18 -> V_201 ) ;
}
V_18 -> V_194 = V_197 ;
F_61 ( & V_18 -> V_198 ) ;
return strlen ( V_9 ) ;
}
static T_1
F_64 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_205 ) ;
}
static T_1
F_65 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_206 ) ;
}
static T_1
F_66 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_46 ,
( V_18 -> V_207 ) ? L_47 : L_48 ,
( V_18 -> V_22 & V_208 ) ?
L_49 : L_50 ) ;
}
static T_1
F_67 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_7 V_209 ;
V_209 = F_68 ( V_18 ) ;
return snprintf ( V_9 , V_10 , L_9 , V_209 ) ;
}
static T_1
F_69 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_73 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
unsigned int V_115 = V_73 ;
if ( V_9 [ V_115 - 1 ] == '\n' )
V_115 -- ;
if ( ( V_115 != strlen ( V_210 ) ) ||
( strncmp ( V_9 , V_210 , strlen ( V_210 ) ) != 0 ) )
return - V_75 ;
V_18 -> V_211 = 1 ;
return V_73 ;
}
static T_1
F_70 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_51 ,
( unsigned long long ) V_18 -> V_212 ) ;
}
static T_1
F_71 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_73 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_109 V_110 ;
int V_213 = 0 , V_214 = 0 ;
unsigned int V_3 , V_4 , V_115 = V_73 ;
T_8 V_215 [ 8 ] ;
int V_116 ;
if ( ! V_18 -> V_123 )
return - V_157 ;
F_60 ( & V_18 -> V_198 ) ;
if ( V_18 -> V_216 == V_217 ) {
F_61 ( & V_18 -> V_198 ) ;
return - V_157 ;
}
F_61 ( & V_18 -> V_198 ) ;
if ( V_9 [ V_115 - 1 ] == '\n' )
V_115 -- ;
if ( ! V_18 -> V_211 || ( V_115 < 16 ) || ( V_115 > 18 ) ||
( ( V_115 == 17 ) && ( * V_9 ++ != 'x' ) ) ||
( ( V_115 == 18 ) && ( ( * V_9 ++ != '0' ) || ( * V_9 ++ != 'x' ) ) ) )
return - V_75 ;
V_18 -> V_211 = 0 ;
memset ( V_215 , 0 , sizeof( V_215 ) ) ;
for ( V_3 = 0 , V_4 = 0 ; V_3 < 16 ; V_3 ++ ) {
int V_218 ;
V_218 = F_72 ( * V_9 ++ ) ;
if ( V_218 >= 0 )
V_4 = ( V_4 << 4 ) | V_218 ;
else
return - V_75 ;
if ( V_3 % 2 ) {
V_215 [ V_3 / 2 ] = V_4 & 0xff ;
V_4 = 0 ;
}
}
V_18 -> V_212 = F_73 ( V_215 ) ;
F_74 ( V_13 ) = V_18 -> V_212 ;
if ( V_18 -> V_219 )
F_75 ( V_13 ) = V_18 -> V_219 ;
F_76 ( V_220 , & V_18 -> V_139 -> V_6 ,
L_52 , V_18 -> V_221 ) ;
V_213 = F_32 ( V_18 , V_124 ) ;
if ( V_213 )
F_29 ( V_18 , V_104 , V_122 ,
L_53
L_54 , V_213 ) ;
F_33 ( & V_110 ) ;
V_116 = F_34 ( V_18 , & V_214 , & V_110 ,
V_125 ) ;
if ( V_116 == 0 )
return - V_89 ;
F_35 ( & V_110 ) ;
if ( V_214 )
F_29 ( V_18 , V_104 , V_122 ,
L_55
L_54 , V_214 ) ;
return ( V_213 || V_214 ) ? - V_108 : V_73 ;
}
static T_1
F_77 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_51 ,
( unsigned long long ) V_18 -> V_219 ) ;
}
static T_1
F_78 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_73 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
unsigned int V_3 , V_4 , V_115 = V_73 ;
T_8 V_222 [ 8 ] ;
if ( V_9 [ V_115 - 1 ] == '\n' )
V_115 -- ;
if ( ! V_18 -> V_211 || ( V_115 < 16 ) || ( V_115 > 18 ) ||
( ( V_115 == 17 ) && ( * V_9 ++ != 'x' ) ) ||
( ( V_115 == 18 ) && ( ( * V_9 ++ != '0' ) || ( * V_9 ++ != 'x' ) ) ) )
return - V_75 ;
memset ( V_222 , 0 , sizeof( V_222 ) ) ;
for ( V_3 = 0 , V_4 = 0 ; V_3 < 16 ; V_3 ++ ) {
int V_218 ;
V_218 = F_72 ( * V_9 ++ ) ;
if ( V_218 >= 0 )
V_4 = ( V_4 << 4 ) | V_218 ;
else
return - V_75 ;
if ( V_3 % 2 ) {
V_222 [ V_3 / 2 ] = V_4 & 0xff ;
V_4 = 0 ;
}
}
V_18 -> V_219 = F_73 ( V_222 ) ;
F_76 ( V_220 , & V_18 -> V_139 -> V_6 ,
L_56
L_57 , V_18 -> V_221 ) ;
return V_73 ;
}
static T_1
F_79 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_223 ) ;
}
static T_1
F_80 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 ,
V_18 -> V_33 . V_119 [ V_224 ] . V_225 ) ;
}
static T_1
F_81 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 ,
V_18 -> V_33 . V_119 [ V_224 ] . V_226 ) ;
}
static T_1
F_82 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
return snprintf ( V_9 , V_10 , L_9 , V_15 -> V_227 ) ;
}
static int
F_83 ( struct V_14 * V_15 , int V_197 )
{
if ( V_15 -> V_227 != V_228 ) {
V_15 -> V_229 = V_15 -> V_227 ;
if ( V_197 != V_228 )
F_49 ( V_15 , V_104 , V_122 ,
L_58
L_59
L_60 ) ;
return 0 ;
}
if ( V_197 >= V_230 && V_197 <= V_231 ) {
V_15 -> V_229 = V_197 ;
V_15 -> V_227 = V_197 ;
return 0 ;
}
F_49 ( V_15 , V_104 , V_122 ,
L_61
L_62 ,
V_197 , V_230 , V_231 ) ;
V_15 -> V_229 = V_228 ;
return - V_75 ;
}
static void
F_84 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
struct V_232 * V_233 ;
V_13 = F_85 ( V_15 ) ;
F_60 ( V_13 -> V_234 ) ;
F_86 (ndlp, &vport->fc_nodes, nlp_listp)
if ( F_87 ( V_233 ) && V_233 -> V_235 )
V_233 -> V_235 -> V_236 = V_15 -> V_227 ;
F_61 ( V_13 -> V_234 ) ;
}
static int
F_88 ( struct V_14 * V_15 , int V_197 )
{
if ( V_15 -> V_237 ||
( V_238 != V_228 ) ) {
F_49 ( V_15 , V_104 , V_122 ,
L_63
L_64 ) ;
return 0 ;
}
if ( V_197 >= V_230 && V_197 <= V_231 ) {
V_15 -> V_229 = V_197 ;
V_15 -> V_227 = V_197 ;
F_89 ( F_85 ( V_15 ) ) = V_197 ;
F_84 ( V_15 ) ;
return 0 ;
}
F_49 ( V_15 , V_104 , V_122 ,
L_65
L_66 ,
V_197 , V_230 , V_231 ) ;
return - V_75 ;
}
static int
F_90 ( struct V_14 * V_15 , int V_197 )
{
if ( V_197 >= V_230 && V_197 <= V_231 ) {
V_15 -> V_229 = V_197 ;
V_15 -> V_227 = V_197 ;
V_15 -> V_237 = 1 ;
F_89 ( F_85 ( V_15 ) ) = V_197 ;
F_84 ( V_15 ) ;
return 0 ;
}
F_49 ( V_15 , V_104 , V_122 ,
L_67
L_62 ,
V_197 , V_230 , V_231 ) ;
return - V_75 ;
}
static int
F_91 ( struct V_14 * V_15 , int V_197 )
{
if ( V_197 < 0 || V_197 > 1 ) {
F_49 ( V_15 , V_104 , V_122 ,
L_68
L_69 ,
V_197 ) ;
V_15 -> V_239 = 1 ;
return - V_75 ;
}
if ( V_15 -> V_191 == V_192 ) {
V_15 -> V_239 = 0 ;
return 0 ;
}
V_15 -> V_239 = V_197 ;
return 0 ;
}
static int
F_92 ( struct V_14 * V_15 , int V_197 )
{
if ( V_197 < 0 || V_197 > 1 ) {
F_49 ( V_15 , V_104 , V_122 ,
L_70
L_69 ,
V_197 ) ;
V_15 -> V_239 = 1 ;
return - V_75 ;
}
if ( V_15 -> V_191 == V_192 && V_197 != 0 ) {
F_49 ( V_15 , V_104 , V_122 ,
L_71
L_72 ) ;
V_15 -> V_239 = 0 ;
return 0 ;
}
V_15 -> V_239 = V_197 ;
return 0 ;
}
static T_1
F_93 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_73 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_197 = 0 ;
int V_240 = 0 ;
const char * V_241 = V_9 ;
int V_242 ;
T_5 V_243 ;
if ( ! strncmp ( V_9 , L_73 , strlen ( L_73 ) ) ) {
V_240 = 1 ;
V_241 = & V_9 [ strlen ( L_73 ) ] ;
}
if ( ! isdigit ( V_241 [ 0 ] ) )
return - V_75 ;
if ( sscanf ( V_241 , L_44 , & V_197 ) != 1 )
return - V_75 ;
if ( V_197 >= 0 && V_197 <= 6 ) {
V_243 = V_18 -> V_100 ;
V_18 -> V_100 = V_197 ;
if ( V_240 )
return strlen ( V_9 ) ;
F_49 ( V_15 , V_104 , V_122 ,
L_74 ,
V_243 , V_197 ) ;
V_242 = F_25 ( F_85 ( V_18 -> V_173 ) ) ;
if ( V_242 ) {
V_18 -> V_100 = V_243 ;
return - V_75 ;
} else
return strlen ( V_9 ) ;
}
F_29 ( V_18 , V_104 , V_122 ,
L_75
L_76 ,
V_18 -> V_221 , V_197 ) ;
return - V_75 ;
}
static T_1
F_94 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
if ( V_15 -> V_244 & V_245 )
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
static char V_246 [ F_96 ] ;
unsigned long V_3 ;
char * V_247 , * V_248 ;
struct V_14 * * V_249 ;
struct V_12 * V_250 ;
char * V_251 , * V_252 , * V_253 ;
unsigned long V_254 , V_255 , V_256 ;
if ( ! strncmp ( V_9 , L_77 , strlen ( L_77 ) ) ) {
if ( strlen ( V_9 ) > ( F_96 - 1 ) )
return - V_75 ;
strcpy ( V_246 , V_9 ) ;
V_247 = & V_246 [ 0 ] ;
V_248 = F_97 ( & V_247 , L_78 ) ;
if ( ! V_248 )
return - V_75 ;
V_251 = F_97 ( & V_247 , L_78 ) ;
if ( ! V_251 )
return - V_75 ;
if ( ! strncmp ( V_251 , L_79 , strlen ( L_79 ) ) )
V_256 = V_257 ;
else if ( ! strncmp ( V_251 , L_80 , strlen ( L_80 ) ) )
V_256 = V_258 ;
else
return - V_75 ;
V_252 = F_97 ( & V_247 , L_78 ) ;
if ( ! V_252 )
return - V_75 ;
V_254 = F_98 ( V_252 , NULL , 0 ) ;
V_253 = F_97 ( & V_247 , L_78 ) ;
if ( ! V_253 )
return - V_75 ;
V_255 = F_98 ( V_253 , NULL , 0 ) ;
if ( ! V_255 )
return - V_75 ;
V_249 = F_99 ( V_18 ) ;
if ( V_249 == NULL )
return - V_89 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_259 && V_249 [ V_3 ] != NULL ; V_3 ++ ) {
V_250 = F_85 ( V_249 [ V_3 ] ) ;
F_60 ( V_250 -> V_234 ) ;
V_249 [ V_3 ] -> V_260 = 1 ;
if ( V_249 [ V_3 ] -> V_261 )
F_100 ( V_249 [ V_3 ] ) ;
F_61 ( V_250 -> V_234 ) ;
}
V_18 -> V_256 = V_256 ;
V_18 -> V_262 = V_254 ;
V_18 -> V_263 = V_255 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_259 && V_249 [ V_3 ] != NULL ; V_3 ++ ) {
V_250 = F_85 ( V_249 [ V_3 ] ) ;
F_60 ( V_250 -> V_234 ) ;
V_249 [ V_3 ] -> V_260 = 0 ;
F_61 ( V_250 -> V_234 ) ;
}
F_101 ( V_18 , V_249 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_81 , strlen ( L_81 ) ) ) {
V_249 = F_99 ( V_18 ) ;
if ( V_249 == NULL )
return - V_89 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_259 && V_249 [ V_3 ] != NULL ; V_3 ++ ) {
V_250 = F_85 ( V_249 [ V_3 ] ) ;
F_60 ( V_13 -> V_234 ) ;
V_249 [ V_3 ] -> V_260 = 1 ;
F_102 ( V_15 ) ;
V_15 -> V_261 = 0 ;
V_249 [ V_3 ] -> V_260 = 0 ;
F_61 ( V_13 -> V_234 ) ;
}
F_101 ( V_18 , V_249 ) ;
V_18 -> V_256 = V_264 ;
V_18 -> V_262 = 0 ;
V_18 -> V_263 = 0 ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_82 , strlen ( L_82 ) ) ) {
if ( V_18 -> V_256 == V_264 )
return - V_75 ;
F_60 ( V_13 -> V_234 ) ;
if ( V_15 -> V_261 ) {
F_61 ( V_13 -> V_234 ) ;
return strlen ( V_9 ) ;
}
F_103 ( V_15 ) ;
V_15 -> V_261 = 1 ;
F_61 ( V_13 -> V_234 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_83 , strlen ( L_83 ) ) ) {
F_60 ( V_13 -> V_234 ) ;
if ( V_15 -> V_261 == 0 ) {
F_61 ( V_13 -> V_234 ) ;
return strlen ( V_9 ) ;
}
F_102 ( V_15 ) ;
V_15 -> V_261 = 0 ;
F_61 ( V_13 -> V_234 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_84 , strlen ( L_84 ) ) ) {
if ( ( V_18 -> V_256 == V_264 )
|| ! V_15 -> V_261 )
return strlen ( V_9 ) ;
F_60 ( V_13 -> V_234 ) ;
V_15 -> V_260 = 1 ;
F_100 ( V_15 ) ;
V_15 -> V_260 = 0 ;
F_61 ( V_13 -> V_234 ) ;
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
int V_265 = 0 ;
int V_3 ;
char * V_256 ;
unsigned long V_266 ;
switch ( V_18 -> V_256 ) {
case V_257 :
V_256 = L_79 ;
break;
case V_258 :
V_256 = L_80 ;
break;
default:
V_256 = L_85 ;
break;
}
sprintf ( & V_9 [ V_265 ] , L_86
L_87
L_88 ,
V_15 -> V_261 , V_15 -> V_260 ,
V_256 , V_18 -> V_262 , V_18 -> V_263 ) ;
V_265 = strlen ( V_9 ) ;
if ( V_18 -> V_256 != V_264 ) {
for ( V_3 = 0 ; V_3 < V_267 ; V_3 ++ ) {
if ( V_18 -> V_256 == V_257 )
V_266 = V_18 -> V_262 +
V_18 -> V_263 * V_3 ;
else
V_266 = V_18 -> V_262 +
( 1 << V_3 ) * V_18 -> V_263 ;
if ( V_265 + 10 > V_10 )
break;
sprintf ( & V_9 [ V_265 ] , L_89 , V_266 ) ;
V_265 = strlen ( V_9 ) ;
}
}
sprintf ( & V_9 [ V_265 ] , L_1 ) ;
return strlen ( V_9 ) ;
}
static T_1
F_105 ( struct V_268 * V_269 , struct V_270 * V_271 ,
struct V_272 * V_273 ,
char * V_9 , T_9 V_274 , T_3 V_73 )
{
struct V_5 * V_6 = F_106 ( V_271 , struct V_5 ,
V_271 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_3 = 0 , V_265 = 0 ;
unsigned long V_275 ;
struct V_232 * V_233 = NULL ;
V_275 = ( unsigned long ) V_274 /
V_276 ;
if ( ! V_15 -> V_261 || V_15 -> V_260
|| ( V_18 -> V_256 == V_264 ) )
return 0 ;
F_60 ( V_13 -> V_234 ) ;
F_86 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_87 ( V_233 ) || ! V_233 -> V_277 )
continue;
if ( V_275 > 0 ) {
V_275 -- ;
continue;
}
if ( ( V_265 + V_276 )
> V_73 )
break;
if ( ! V_233 -> V_277 )
continue;
sprintf ( & V_9 [ V_265 ] , L_90 ,
V_233 -> V_278 . V_90 . V_279 [ 0 ] ,
V_233 -> V_278 . V_90 . V_279 [ 1 ] ,
V_233 -> V_278 . V_90 . V_279 [ 2 ] ,
V_233 -> V_278 . V_90 . V_279 [ 3 ] ,
V_233 -> V_278 . V_90 . V_279 [ 4 ] ,
V_233 -> V_278 . V_90 . V_279 [ 5 ] ,
V_233 -> V_278 . V_90 . V_279 [ 6 ] ,
V_233 -> V_278 . V_90 . V_279 [ 7 ] ) ;
V_265 = strlen ( V_9 ) ;
for ( V_3 = 0 ; V_3 < V_267 ; V_3 ++ ) {
sprintf ( & V_9 [ V_265 ] , L_91 ,
V_233 -> V_277 [ V_3 ] . V_280 ) ;
V_265 = strlen ( V_9 ) ;
}
sprintf ( & V_9 [ V_265 ] , L_1 ) ;
V_265 = strlen ( V_9 ) ;
}
F_61 ( V_13 -> V_234 ) ;
return V_265 ;
}
static T_1
F_107 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_73 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_197 = V_281 ;
int V_240 = 0 ;
const char * V_241 = V_9 ;
int V_242 ;
T_5 V_243 ;
if ( ! strncmp ( V_9 , L_73 , strlen ( L_73 ) ) ) {
V_240 = 1 ;
V_241 = & V_9 [ strlen ( L_73 ) ] ;
}
if ( ! isdigit ( V_241 [ 0 ] ) )
return - V_75 ;
if ( sscanf ( V_241 , L_44 , & V_197 ) != 1 )
return - V_75 ;
F_49 ( V_15 , V_104 , V_122 ,
L_92 ,
V_18 -> V_101 , V_197 , V_240 ? L_93 : L_94 ) ;
if ( ( ( V_197 == V_282 ) && ! ( V_18 -> V_283 & V_284 ) ) ||
( ( V_197 == V_285 ) && ! ( V_18 -> V_283 & V_286 ) ) ||
( ( V_197 == V_287 ) && ! ( V_18 -> V_283 & V_288 ) ) ||
( ( V_197 == V_289 ) && ! ( V_18 -> V_283 & V_290 ) ) ||
( ( V_197 == V_291 ) && ! ( V_18 -> V_283 & V_292 ) ) ||
( ( V_197 == V_293 ) && ! ( V_18 -> V_283 & V_294 ) ) ) {
F_29 ( V_18 , V_104 , V_122 ,
L_95
L_96 ,
V_197 ) ;
return - V_75 ;
}
if ( ( V_197 >= 0 ) && ( V_197 <= V_295 ) &&
( V_296 & ( 1 << V_197 ) ) ) {
V_243 = V_18 -> V_101 ;
V_18 -> V_101 = V_197 ;
if ( V_240 )
return strlen ( V_9 ) ;
V_242 = F_25 ( F_85 ( V_18 -> V_173 ) ) ;
if ( V_242 ) {
V_18 -> V_101 = V_243 ;
return - V_75 ;
} else
return strlen ( V_9 ) ;
}
F_29 ( V_18 , V_104 , V_122 ,
L_97
L_98 V_297 L_99 , V_197 ) ;
return - V_75 ;
}
static int
F_108 ( struct V_17 * V_18 , int V_197 )
{
if ( ( V_197 >= 0 ) && ( V_197 <= V_295 ) &&
( V_296 & ( 1 << V_197 ) ) ) {
V_18 -> V_101 = V_197 ;
return 0 ;
}
F_29 ( V_18 , V_104 , V_122 ,
L_100
L_101
L_102 V_297 L_99 , V_197 ) ;
V_18 -> V_101 = V_281 ;
return - V_75 ;
}
static T_1
F_109 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_73 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_197 = 0 , V_116 = - V_75 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_75 ;
if ( sscanf ( V_9 , L_44 , & V_197 ) != 1 )
return - V_75 ;
switch ( V_197 ) {
case 0 :
if ( V_18 -> V_19 & V_298 ) {
V_116 = F_110 ( V_18 -> V_139 ) ;
if ( ! V_116 ) {
F_60 ( & V_18 -> V_198 ) ;
V_18 -> V_19 &= ~ V_298 ;
F_61 ( & V_18 -> V_198 ) ;
V_18 -> V_299 = 0 ;
V_116 = strlen ( V_9 ) ;
} else
V_116 = - V_86 ;
} else {
V_18 -> V_299 = 0 ;
V_116 = strlen ( V_9 ) ;
}
break;
case 1 :
if ( ! ( V_18 -> V_19 & V_298 ) ) {
V_116 = F_111 ( V_18 -> V_139 ) ;
if ( ! V_116 ) {
F_60 ( & V_18 -> V_198 ) ;
V_18 -> V_19 |= V_298 ;
F_61 ( & V_18 -> V_198 ) ;
V_18 -> V_299 = 1 ;
V_116 = strlen ( V_9 ) ;
} else
V_116 = - V_86 ;
} else {
V_18 -> V_299 = 1 ;
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
F_112 ( struct V_17 * V_18 , int V_197 )
{
if ( V_197 == 0 || V_197 == 1 ) {
V_18 -> V_299 = V_197 ;
return 0 ;
}
F_29 ( V_18 , V_104 , V_122 ,
L_103
L_104
L_105 , V_197 ) ;
V_18 -> V_299 = 1 ;
return - V_75 ;
}
static T_1
F_113 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_73 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_197 , V_116 = - 1 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_75 ;
if ( sscanf ( V_9 , L_44 , & V_197 ) != 1 )
return - V_75 ;
if ( V_197 != 1 )
return - V_75 ;
if ( V_18 -> V_19 & V_298 )
V_116 = F_114 ( V_18 -> V_139 ) ;
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
struct V_137 * V_138 = V_18 -> V_139 ;
int V_197 = 0 , V_116 = - V_75 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_75 ;
if ( sscanf ( V_9 , L_44 , & V_197 ) != 1 )
return - V_75 ;
if ( V_197 < 0 )
return - V_75 ;
if ( V_197 == 0 ) {
if ( V_18 -> V_146 > 0 ) {
F_43 ( V_138 ) ;
V_18 -> V_146 = 0 ;
}
return strlen ( V_9 ) ;
}
if ( V_18 -> V_146 > 0 ) {
F_29 ( V_18 , V_104 , V_122 ,
L_106
L_107 ,
V_18 -> V_146 ) ;
return - V_300 ;
}
if ( V_197 <= V_301 )
V_18 -> V_146 = V_197 ;
else {
F_29 ( V_18 , V_104 , V_122 ,
L_108
L_109 , V_197 ) ;
return - V_75 ;
}
V_116 = F_116 ( V_18 , V_18 -> V_146 ) ;
if ( V_116 ) {
V_18 -> V_146 = 0 ;
V_116 = - V_86 ;
} else
V_116 = strlen ( V_9 ) ;
return V_116 ;
}
static int
F_117 ( struct V_17 * V_18 , int V_197 )
{
if ( V_197 >= 0 && V_197 <= V_301 ) {
V_18 -> V_146 = V_197 ;
return 0 ;
}
F_29 ( V_18 , V_104 , V_122 ,
L_110
L_109 , V_197 ) ;
return - V_75 ;
}
static int
F_118 ( struct V_14 * V_15 , int V_197 )
{
struct V_12 * V_13 = F_85 ( V_15 ) ;
struct V_232 * V_233 , * V_302 ;
if ( V_197 == V_15 -> V_303 )
return 0 ;
if ( ( V_197 < 0 ) || ( V_197 > 60000 ) )
return - V_75 ;
V_15 -> V_303 = V_197 ;
F_60 ( V_13 -> V_234 ) ;
F_119 (ndlp, next_ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_87 ( V_233 ) )
continue;
if ( V_233 -> V_304 == V_305 )
continue;
V_233 -> V_306 = V_15 -> V_307 ;
}
F_61 ( V_13 -> V_234 ) ;
return 0 ;
}
static T_1
F_120 ( struct V_268 * V_269 , struct V_270 * V_271 ,
struct V_272 * V_273 ,
char * V_9 , T_9 V_274 , T_3 V_73 )
{
T_3 V_308 ;
struct V_5 * V_6 = F_106 ( V_271 , struct V_5 , V_271 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_38 >= V_141 )
return - V_86 ;
if ( ( V_274 + V_73 ) > V_309 )
return - V_310 ;
if ( V_73 == 0 ) return 0 ;
if ( V_274 % 4 || V_73 % 4 || ( unsigned long ) V_9 % 4 )
return - V_75 ;
if ( ! ( V_15 -> V_70 & V_84 ) ) {
return - V_86 ;
}
F_60 ( & V_18 -> V_198 ) ;
for ( V_308 = 0 ; V_308 < V_73 ; V_308 += sizeof( T_5 ) )
F_45 ( * ( ( T_5 * ) ( V_9 + V_308 ) ) ,
V_18 -> V_311 + V_274 + V_308 ) ;
F_61 ( & V_18 -> V_198 ) ;
return V_73 ;
}
static T_1
F_121 ( struct V_268 * V_269 , struct V_270 * V_271 ,
struct V_272 * V_273 ,
char * V_9 , T_9 V_274 , T_3 V_73 )
{
T_3 V_308 ;
T_5 * V_312 ;
struct V_5 * V_6 = F_106 ( V_271 , struct V_5 , V_271 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_38 >= V_141 )
return - V_86 ;
if ( V_274 > V_309 )
return - V_310 ;
if ( ( V_274 + V_73 ) > V_309 )
V_73 = V_309 - V_274 ;
if ( V_73 == 0 ) return 0 ;
if ( V_274 % 4 || V_73 % 4 || ( unsigned long ) V_9 % 4 )
return - V_75 ;
F_60 ( & V_18 -> V_198 ) ;
for ( V_308 = 0 ; V_308 < V_73 ; V_308 += sizeof( T_5 ) ) {
V_312 = ( T_5 * ) ( V_9 + V_308 ) ;
* V_312 = F_44 ( V_18 -> V_311 + V_274 + V_308 ) ;
}
F_61 ( & V_18 -> V_198 ) ;
return V_73 ;
}
static void
F_122 ( struct V_17 * V_18 )
{
V_18 -> V_313 . V_156 = V_314 ;
V_18 -> V_313 . V_315 = 0 ;
if ( V_18 -> V_313 . V_316 ) {
F_31 ( V_18 -> V_313 . V_316 ,
V_18 -> V_87 ) ;
V_18 -> V_313 . V_316 = NULL ;
}
}
static T_1
F_123 ( struct V_268 * V_269 , struct V_270 * V_271 ,
struct V_272 * V_273 ,
char * V_9 , T_9 V_274 , T_3 V_73 )
{
struct V_5 * V_6 = F_106 ( V_271 , struct V_5 , V_271 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_317 * V_316 = NULL ;
if ( ( V_73 + V_274 ) > V_318 )
return - V_310 ;
if ( V_274 % 4 || V_73 % 4 || ( unsigned long ) V_9 % 4 )
return - V_75 ;
if ( V_73 == 0 )
return 0 ;
if ( V_274 == 0 ) {
V_316 = F_26 ( V_18 -> V_87 , V_88 ) ;
if ( ! V_316 )
return - V_89 ;
memset ( V_316 , 0 , sizeof ( T_4 ) ) ;
}
F_60 ( & V_18 -> V_198 ) ;
if ( V_274 == 0 ) {
if ( V_18 -> V_313 . V_316 )
F_31 ( V_316 , V_18 -> V_87 ) ;
else
V_18 -> V_313 . V_316 = V_316 ;
V_18 -> V_313 . V_156 = V_319 ;
} else {
if ( V_18 -> V_313 . V_156 != V_319 ||
V_18 -> V_313 . V_315 != V_274 ||
V_18 -> V_313 . V_316 == NULL ) {
F_122 ( V_18 ) ;
F_61 ( & V_18 -> V_198 ) ;
return - V_320 ;
}
}
memcpy ( ( V_321 * ) & V_18 -> V_313 . V_316 -> V_90 . V_91 + V_274 ,
V_9 , V_73 ) ;
V_18 -> V_313 . V_315 = V_274 + V_73 ;
F_61 ( & V_18 -> V_198 ) ;
return V_73 ;
}
static T_1
F_124 ( struct V_268 * V_269 , struct V_270 * V_271 ,
struct V_272 * V_273 ,
char * V_9 , T_9 V_274 , T_3 V_73 )
{
struct V_5 * V_6 = F_106 ( V_271 , struct V_5 , V_271 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_116 ;
T_6 * V_168 ;
if ( V_274 > V_318 )
return - V_310 ;
if ( ( V_73 + V_274 ) > V_318 )
V_73 = V_318 - V_274 ;
if ( V_274 % 4 || V_73 % 4 || ( unsigned long ) V_9 % 4 )
return - V_75 ;
if ( V_274 && V_73 == 0 )
return 0 ;
F_60 ( & V_18 -> V_198 ) ;
if ( V_18 -> V_216 == V_217 ) {
F_122 ( V_18 ) ;
F_61 ( & V_18 -> V_198 ) ;
return - V_157 ;
}
if ( V_274 == 0 &&
V_18 -> V_313 . V_156 == V_319 &&
V_18 -> V_313 . V_315 >= 2 * sizeof( T_5 ) ) {
V_168 = & V_18 -> V_313 . V_316 -> V_90 . V_91 ;
switch ( V_168 -> V_92 ) {
case V_322 :
case V_93 :
case V_323 :
case V_324 :
case V_325 :
case V_326 :
case V_327 :
case V_328 :
case V_329 :
case V_330 :
case V_331 :
case V_332 :
if ( ! ( V_15 -> V_70 & V_84 ) ) {
F_125 ( V_121 L_111
L_112 ,
V_168 -> V_92 ) ;
F_122 ( V_18 ) ;
F_61 ( & V_18 -> V_198 ) ;
return - V_86 ;
}
case V_333 :
case V_334 :
case V_335 :
case V_336 :
case V_171 :
case V_337 :
case V_338 :
case V_339 :
case V_340 :
case V_341 :
case V_342 :
case V_343 :
case V_344 :
case V_345 :
case V_346 :
case V_347 :
case V_348 :
case V_349 :
case V_350 :
case V_351 :
case V_352 :
case V_353 :
break;
case V_354 :
case V_355 :
if ( V_18 -> V_356 == V_357 ) {
F_125 ( V_121 L_111
L_113 , V_168 -> V_92 ) ;
F_122 ( V_18 ) ;
F_61 ( & V_18 -> V_198 ) ;
return - V_86 ;
}
break;
case V_358 :
case V_359 :
case V_360 :
case V_361 :
case V_362 :
case V_363 :
F_125 ( V_121 L_114 ,
V_168 -> V_92 ) ;
F_122 ( V_18 ) ;
F_61 ( & V_18 -> V_198 ) ;
return - V_86 ;
default:
F_125 ( V_121 L_115 ,
V_168 -> V_92 ) ;
F_122 ( V_18 ) ;
F_61 ( & V_18 -> V_198 ) ;
return - V_86 ;
}
if ( V_18 -> V_173 -> V_364 &&
V_168 -> V_92 != V_342 &&
V_168 -> V_92 != V_330 &&
V_168 -> V_92 != V_334 &&
V_168 -> V_92 != V_351 )
F_29 ( V_18 , V_121 , V_105 ,
L_116
L_117 ,
V_168 -> V_92 ) ;
V_18 -> V_313 . V_316 -> V_15 = V_15 ;
if ( V_18 -> V_33 . V_34 & V_85 ) {
F_122 ( V_18 ) ;
F_61 ( & V_18 -> V_198 ) ;
return - V_320 ;
}
if ( ( V_15 -> V_70 & V_84 ) ||
( ! ( V_18 -> V_33 . V_34 & V_170 ) ) ) {
F_61 ( & V_18 -> V_198 ) ;
V_116 = F_126 ( V_18 ,
V_18 -> V_313 . V_316 ,
V_365 ) ;
F_60 ( & V_18 -> V_198 ) ;
} else {
F_61 ( & V_18 -> V_198 ) ;
V_116 = F_27 ( V_18 ,
V_18 -> V_313 . V_316 ,
F_127 ( V_18 , V_168 -> V_92 ) * V_366 ) ;
F_60 ( & V_18 -> V_198 ) ;
}
if ( V_116 != V_97 ) {
if ( V_116 == V_107 ) {
V_18 -> V_313 . V_316 = NULL ;
}
F_122 ( V_18 ) ;
F_61 ( & V_18 -> V_198 ) ;
return ( V_116 == V_107 ) ? - V_367 : - V_368 ;
}
V_18 -> V_313 . V_156 = V_369 ;
}
else if ( V_18 -> V_313 . V_315 != V_274 ||
V_18 -> V_313 . V_156 != V_369 ) {
F_125 ( V_121 L_118 ) ;
F_122 ( V_18 ) ;
F_61 ( & V_18 -> V_198 ) ;
return - V_320 ;
}
memcpy ( V_9 , ( V_321 * ) & V_168 + V_274 , V_73 ) ;
V_18 -> V_313 . V_315 = V_274 + V_73 ;
if ( V_18 -> V_313 . V_315 == V_318 )
F_122 ( V_18 ) ;
F_61 ( & V_18 -> V_198 ) ;
return V_73 ;
}
int
F_128 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = F_85 ( V_15 ) ;
int error ;
error = F_129 ( & V_13 -> V_370 . V_271 ,
& V_371 ) ;
if ( error || V_15 -> V_191 == V_372 )
goto V_373;
error = F_129 ( & V_13 -> V_370 . V_271 ,
& V_374 ) ;
if ( error )
goto V_375;
error = F_129 ( & V_13 -> V_370 . V_271 ,
& V_376 ) ;
if ( error )
goto V_377;
return 0 ;
V_377:
F_130 ( & V_13 -> V_370 . V_271 , & V_374 ) ;
V_375:
F_130 ( & V_13 -> V_370 . V_271 ,
& V_371 ) ;
V_373:
return error ;
}
void
F_131 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = F_85 ( V_15 ) ;
F_130 ( & V_13 -> V_370 . V_271 ,
& V_371 ) ;
if ( V_15 -> V_191 == V_372 )
return;
F_130 ( & V_13 -> V_370 . V_271 , & V_376 ) ;
F_130 ( & V_13 -> V_370 . V_271 , & V_374 ) ;
}
static void
F_132 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
F_133 ( V_13 ) = V_15 -> V_378 ;
}
static void
F_134 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_60 ( V_13 -> V_234 ) ;
if ( V_15 -> V_191 == V_372 ) {
F_135 ( V_13 ) = V_379 ;
} else if ( F_136 ( V_18 ) ) {
if ( V_18 -> V_68 == V_69 ) {
if ( V_15 -> V_70 & V_71 )
F_135 ( V_13 ) = V_380 ;
else
F_135 ( V_13 ) = V_381 ;
} else {
if ( V_15 -> V_70 & V_72 )
F_135 ( V_13 ) = V_382 ;
else
F_135 ( V_13 ) = V_383 ;
}
} else
F_135 ( V_13 ) = V_384 ;
F_61 ( V_13 -> V_234 ) ;
}
static void
F_137 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_60 ( V_13 -> V_234 ) ;
if ( V_15 -> V_70 & V_84 )
F_138 ( V_13 ) = V_385 ;
else {
switch ( V_18 -> V_45 ) {
case V_46 :
case V_50 :
F_138 ( V_13 ) = V_386 ;
break;
case V_53 :
case V_54 :
case V_55 :
F_138 ( V_13 ) = V_387 ;
break;
case V_51 :
F_138 ( V_13 ) = V_388 ;
break;
default:
F_138 ( V_13 ) = V_389 ;
break;
}
}
F_61 ( V_13 -> V_234 ) ;
}
static void
F_139 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_60 ( V_13 -> V_234 ) ;
if ( F_136 ( V_18 ) ) {
switch( V_18 -> V_390 ) {
case V_391 :
F_140 ( V_13 ) = V_392 ;
break;
case V_393 :
F_140 ( V_13 ) = V_394 ;
break;
case V_395 :
F_140 ( V_13 ) = V_396 ;
break;
case V_397 :
F_140 ( V_13 ) = V_398 ;
break;
case V_399 :
F_140 ( V_13 ) = V_400 ;
break;
case V_401 :
F_140 ( V_13 ) = V_402 ;
break;
default:
F_140 ( V_13 ) = V_403 ;
break;
}
} else
F_140 ( V_13 ) = V_403 ;
F_61 ( V_13 -> V_234 ) ;
}
static void
F_141 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_10 V_404 ;
F_60 ( V_13 -> V_234 ) ;
if ( ( V_15 -> V_70 & V_72 ) ||
( ( V_18 -> V_68 == V_69 ) &&
( V_15 -> V_70 & V_71 ) ) )
V_404 = F_73 ( V_18 -> V_405 . V_406 . V_90 . V_279 ) ;
else
V_404 = 0 ;
F_61 ( V_13 -> V_234 ) ;
F_142 ( V_13 ) = V_404 ;
}
static struct V_407 *
F_143 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_113 * V_114 = & V_18 -> V_33 ;
struct V_407 * V_408 = & V_18 -> V_409 ;
struct V_410 * V_411 = & V_114 -> V_412 ;
T_4 * V_81 ;
T_6 * V_168 ;
unsigned long V_413 ;
int V_116 = 0 ;
if ( V_18 -> V_45 < V_50 ||
! V_18 -> V_87 ||
( V_18 -> V_33 . V_34 & V_170 ) == 0 )
return NULL ;
if ( V_18 -> V_33 . V_34 & V_85 )
return NULL ;
V_81 = F_26 ( V_18 -> V_87 , V_88 ) ;
if ( ! V_81 )
return NULL ;
memset ( V_81 , 0 , sizeof ( T_4 ) ) ;
V_168 = & V_81 -> V_90 . V_91 ;
V_168 -> V_92 = V_338 ;
V_168 -> V_94 = V_95 ;
V_81 -> V_172 = NULL ;
V_81 -> V_15 = V_15 ;
if ( V_15 -> V_70 & V_84 )
V_116 = F_126 ( V_18 , V_81 , V_365 ) ;
else
V_116 = F_27 ( V_18 , V_81 , V_18 -> V_102 * 2 ) ;
if ( V_116 != V_97 ) {
if ( V_116 != V_107 )
F_31 ( V_81 , V_18 -> V_87 ) ;
return NULL ;
}
memset ( V_408 , 0 , sizeof ( struct V_407 ) ) ;
V_408 -> V_414 = V_168 -> V_176 . V_415 . V_416 ;
V_408 -> V_417 = ( V_168 -> V_176 . V_415 . V_418 * 256 ) ;
V_408 -> V_419 = V_168 -> V_176 . V_415 . V_420 ;
V_408 -> V_421 = ( V_168 -> V_176 . V_415 . V_422 * 256 ) ;
memset ( V_81 , 0 , sizeof ( T_4 ) ) ;
V_168 -> V_92 = V_341 ;
V_168 -> V_94 = V_95 ;
V_81 -> V_172 = NULL ;
V_81 -> V_15 = V_15 ;
if ( V_15 -> V_70 & V_84 )
V_116 = F_126 ( V_18 , V_81 , V_365 ) ;
else
V_116 = F_27 ( V_18 , V_81 , V_18 -> V_102 * 2 ) ;
if ( V_116 != V_97 ) {
if ( V_116 != V_107 )
F_31 ( V_81 , V_18 -> V_87 ) ;
return NULL ;
}
V_408 -> V_423 = V_168 -> V_176 . V_424 . V_425 ;
V_408 -> V_426 = V_168 -> V_176 . V_424 . V_427 ;
V_408 -> V_428 = V_168 -> V_176 . V_424 . V_429 ;
V_408 -> V_430 = V_168 -> V_176 . V_424 . V_431 ;
V_408 -> V_432 = V_168 -> V_176 . V_424 . V_433 ;
V_408 -> V_434 = V_168 -> V_176 . V_424 . V_435 ;
V_408 -> V_436 = V_168 -> V_176 . V_424 . V_435 ;
V_408 -> V_423 -= V_411 -> V_423 ;
V_408 -> V_426 -= V_411 -> V_426 ;
V_408 -> V_428 -= V_411 -> V_428 ;
V_408 -> V_430 -= V_411 -> V_430 ;
V_408 -> V_432 -= V_411 -> V_432 ;
V_408 -> V_434 -= V_411 -> V_434 ;
V_408 -> V_436 -= V_411 -> V_436 ;
if ( V_18 -> V_19 & V_437 ) {
V_408 -> V_438 = - 1 ;
V_408 -> V_439 = ( V_18 -> V_440 >> 1 ) ;
V_408 -> V_439 -= V_411 -> V_440 ;
} else if ( V_18 -> V_68 == V_69 ) {
V_408 -> V_438 = ( V_18 -> V_441 >> 1 ) ;
V_408 -> V_438 -= V_411 -> V_440 ;
V_408 -> V_439 = - 1 ;
} else {
V_408 -> V_438 = - 1 ;
V_408 -> V_439 = ( V_18 -> V_441 >> 1 ) ;
V_408 -> V_439 -= V_411 -> V_440 ;
}
V_408 -> V_442 = - 1 ;
V_413 = F_144 () ;
if ( V_413 < V_114 -> V_443 )
V_408 -> V_444 = V_413 +
( ( unsigned long ) - 1 - V_114 -> V_443 ) ;
else
V_408 -> V_444 = V_413 - V_114 -> V_443 ;
F_31 ( V_81 , V_18 -> V_87 ) ;
return V_408 ;
}
static void
F_145 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_113 * V_114 = & V_18 -> V_33 ;
struct V_410 * V_411 = & V_114 -> V_412 ;
T_4 * V_81 ;
T_6 * V_168 ;
int V_116 = 0 ;
if ( V_18 -> V_33 . V_34 & V_85 )
return;
V_81 = F_26 ( V_18 -> V_87 , V_88 ) ;
if ( ! V_81 )
return;
memset ( V_81 , 0 , sizeof( T_4 ) ) ;
V_168 = & V_81 -> V_90 . V_91 ;
V_168 -> V_92 = V_338 ;
V_168 -> V_94 = V_95 ;
V_168 -> V_176 . V_445 [ 0 ] = 0x1 ;
V_81 -> V_172 = NULL ;
V_81 -> V_15 = V_15 ;
if ( ( V_15 -> V_70 & V_84 ) ||
( ! ( V_114 -> V_34 & V_170 ) ) )
V_116 = F_126 ( V_18 , V_81 , V_365 ) ;
else
V_116 = F_27 ( V_18 , V_81 , V_18 -> V_102 * 2 ) ;
if ( V_116 != V_97 ) {
if ( V_116 != V_107 )
F_31 ( V_81 , V_18 -> V_87 ) ;
return;
}
memset ( V_81 , 0 , sizeof( T_4 ) ) ;
V_168 -> V_92 = V_341 ;
V_168 -> V_94 = V_95 ;
V_81 -> V_172 = NULL ;
V_81 -> V_15 = V_15 ;
if ( ( V_15 -> V_70 & V_84 ) ||
( ! ( V_114 -> V_34 & V_170 ) ) )
V_116 = F_126 ( V_18 , V_81 , V_365 ) ;
else
V_116 = F_27 ( V_18 , V_81 , V_18 -> V_102 * 2 ) ;
if ( V_116 != V_97 ) {
if ( V_116 != V_107 )
F_31 ( V_81 , V_18 -> V_87 ) ;
return;
}
V_411 -> V_423 = V_168 -> V_176 . V_424 . V_425 ;
V_411 -> V_426 = V_168 -> V_176 . V_424 . V_427 ;
V_411 -> V_428 = V_168 -> V_176 . V_424 . V_429 ;
V_411 -> V_430 = V_168 -> V_176 . V_424 . V_431 ;
V_411 -> V_432 = V_168 -> V_176 . V_424 . V_433 ;
V_411 -> V_434 = V_168 -> V_176 . V_424 . V_435 ;
V_411 -> V_436 = V_168 -> V_176 . V_424 . V_435 ;
if ( V_18 -> V_19 & V_437 )
V_411 -> V_440 = ( V_18 -> V_440 >> 1 ) ;
else
V_411 -> V_440 = ( V_18 -> V_441 >> 1 ) ;
V_114 -> V_443 = F_144 () ;
F_31 ( V_81 , V_18 -> V_87 ) ;
return;
}
static struct V_232 *
F_146 ( struct V_446 * V_447 )
{
struct V_12 * V_13 = F_147 ( V_447 -> V_6 . V_448 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_232 * V_233 ;
F_60 ( V_13 -> V_234 ) ;
F_86 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( F_87 ( V_233 ) &&
V_233 -> V_304 == V_449 &&
V_447 -> V_450 == V_233 -> V_451 ) {
F_61 ( V_13 -> V_234 ) ;
return V_233 ;
}
}
F_61 ( V_13 -> V_234 ) ;
return NULL ;
}
static void
F_148 ( struct V_446 * V_447 )
{
struct V_232 * V_233 = F_146 ( V_447 ) ;
F_149 ( V_447 ) = V_233 ? V_233 -> V_452 : - 1 ;
}
static void
F_150 ( struct V_446 * V_447 )
{
struct V_232 * V_233 = F_146 ( V_447 ) ;
F_151 ( V_447 ) =
V_233 ? F_73 ( V_233 -> V_453 . V_90 . V_279 ) : 0 ;
}
static void
F_152 ( struct V_446 * V_447 )
{
struct V_232 * V_233 = F_146 ( V_447 ) ;
F_153 ( V_447 ) =
V_233 ? F_73 ( V_233 -> V_278 . V_90 . V_279 ) : 0 ;
}
static void
F_154 ( struct V_454 * V_235 , T_5 V_455 )
{
if ( V_455 )
V_235 -> V_236 = V_455 ;
else
V_235 -> V_236 = 1 ;
}
static void
F_155 ( struct V_456 * V_456 )
{
struct V_14 * V_15 = * (struct V_14 * * ) V_456 -> V_457 ;
if ( V_15 -> V_56 == V_65 )
F_156 ( V_15 , V_458 , 0 , 0 ) ;
}
static void
F_157 ( struct V_17 * V_18 , T_5 V_459 )
{
V_18 -> V_460 = V_459 ;
}
void
F_158 ( struct V_17 * V_18 )
{
F_159 ( V_18 , V_461 ) ;
F_160 ( V_18 , V_462 ) ;
F_161 ( V_18 , V_463 ) ;
F_162 ( V_18 , V_464 ) ;
F_163 ( V_18 , V_465 ) ;
F_164 ( V_18 , V_466 ) ;
F_165 ( V_18 , V_467 ) ;
F_108 ( V_18 , V_468 ) ;
F_166 ( V_18 , V_469 ) ;
F_167 ( V_18 , V_470 ) ;
F_168 ( V_18 , V_471 ) ;
F_169 ( V_18 , V_472 ) ;
F_170 ( V_18 , V_473 ) ;
F_171 ( V_18 , V_474 ) ;
F_172 ( V_18 , V_475 ) ;
F_173 ( V_18 , V_476 ) ;
F_174 ( V_18 , V_477 ) ;
F_175 ( V_18 , V_478 ) ;
F_176 ( V_18 , V_479 ) ;
if ( V_18 -> V_38 == V_141 )
V_18 -> V_194 = 0 ;
else
V_18 -> V_194 = V_480 ;
V_18 -> V_219 = 0L ;
V_18 -> V_212 = 0L ;
F_177 ( V_18 , V_481 ) ;
F_178 ( V_18 , V_482 ) ;
F_179 ( V_18 , V_483 ) ;
F_157 ( V_18 , V_484 ) ;
F_112 ( V_18 , V_485 ) ;
F_117 ( V_18 , V_486 ) ;
F_180 ( V_18 , V_487 ) ;
F_181 ( V_18 , V_488 ) ;
V_18 -> V_207 = 1 ;
return;
}
void
F_182 ( struct V_14 * V_15 )
{
F_183 ( V_15 , V_484 ) ;
F_184 ( V_15 , V_489 ) ;
F_185 ( V_15 , V_490 ) ;
F_186 ( V_15 , V_238 ) ;
F_83 ( V_15 , V_491 ) ;
F_187 ( V_15 , V_492 ) ;
F_91 ( V_15 , V_493 ) ;
F_188 ( V_15 , V_494 ) ;
F_189 ( V_15 , V_495 ) ;
F_190 ( V_15 , V_496 ) ;
F_191 ( V_15 , V_497 ) ;
F_192 ( V_15 , V_498 ) ;
F_193 ( V_15 , V_499 ) ;
F_194 ( V_15 , V_500 ) ;
F_195 ( V_15 , V_501 ) ;
return;
}
