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
return - V_124 ;
V_74 = F_32 ( V_18 , V_125 ) ;
if ( V_74 != 0 )
return V_74 ;
F_33 ( & V_110 ) ;
V_116 = F_34 ( V_18 , & V_74 , & V_110 ,
V_126 ) ;
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
if ( ! V_18 -> V_123 )
return - V_124 ;
if ( strncmp ( V_9 , L_30 , sizeof( L_30 ) - 1 ) == 0 )
V_74 = V_18 -> F_37 ( V_18 ) ;
if ( V_74 == 0 )
return strlen ( V_9 ) ;
else
return V_74 ;
}
int
F_39 ( struct V_17 * V_18 )
{
struct V_127 V_128 = { 0 } ;
int V_3 ;
F_36 ( 100 ) ;
F_40 ( V_18 -> V_129 . V_90 . V_130 . V_131 ,
& V_128 . V_132 ) ;
if ( ! F_41 ( V_133 , & V_128 ) &&
! F_41 ( V_134 , & V_128 ) )
return - V_86 ;
for ( V_3 = 0 ; V_3 < V_135 ; V_3 ++ ) {
F_36 ( 10 ) ;
F_40 ( V_18 -> V_129 . V_90 . V_130 . V_131 ,
& V_128 . V_132 ) ;
if ( ! F_41 ( V_134 , & V_128 ) )
continue;
if ( ! F_41 ( V_133 , & V_128 ) )
continue;
if ( ! F_41 ( V_136 , & V_128 ) )
continue;
break;
}
if ( V_3 < V_135 )
return 0 ;
else
return - V_108 ;
}
static T_1
F_42 ( struct V_17 * V_18 , T_5 V_137 )
{
struct V_109 V_110 ;
struct V_138 * V_139 = V_18 -> V_140 ;
T_5 V_141 ;
int V_74 = 0 ;
int V_116 ;
if ( ! V_18 -> V_123 )
return - V_124 ;
if ( ( V_18 -> V_38 < V_142 ) ||
( F_41 ( V_143 , & V_18 -> V_129 . V_144 ) !=
V_145 ) )
return - V_86 ;
if ( V_18 -> V_146 ) {
F_43 ( V_139 ) ;
V_18 -> V_146 = 0 ;
}
V_74 = F_32 ( V_18 , V_125 ) ;
if ( V_74 != 0 )
return V_74 ;
F_36 ( 100 ) ;
V_141 = F_44 ( V_18 -> V_129 . V_147 +
V_148 ) ;
if ( V_137 == V_149 )
V_141 |= V_150 ;
else if ( V_137 == V_151 )
V_141 |= V_152 ;
else if ( V_137 == V_153 )
V_141 |= V_154 ;
F_45 ( V_141 , V_18 -> V_129 . V_147 +
V_148 ) ;
F_44 ( V_18 -> V_129 . V_147 + V_148 ) ;
V_116 = F_39 ( V_18 ) ;
if ( V_116 )
return V_116 ;
F_33 ( & V_110 ) ;
V_116 = F_34 ( V_18 , & V_74 , & V_110 ,
V_126 ) ;
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
return - V_124 ;
F_49 ( V_15 , V_104 , V_122 ,
L_35 , V_9 ) ;
F_33 ( & V_110 ) ;
if( strncmp ( V_9 , L_34 , sizeof( L_34 ) - 1 ) == 0 ) {
V_116 = F_34 ( V_18 , & V_74 , & V_110 ,
V_126 ) ;
if ( V_116 == 0 )
return - V_89 ;
F_35 ( & V_110 ) ;
} else if ( strncmp ( V_9 , L_33 , sizeof( L_33 ) - 1 ) == 0 )
V_74 = F_32 ( V_18 , V_125 ) ;
else if ( strncmp ( V_9 , L_36 , sizeof( L_36 ) - 1 ) == 0 )
if ( V_18 -> V_38 == V_142 )
return - V_75 ;
else
V_74 = F_32 ( V_18 , V_157 ) ;
else if ( strncmp ( V_9 , L_31 , sizeof( L_31 ) - 1 ) == 0 )
if ( V_18 -> V_38 == V_142 )
return - V_75 ;
else
V_74 = F_32 ( V_18 , V_158 ) ;
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
return V_74 ;
}
static int
F_50 ( struct V_17 * V_18 ,
T_5 * V_159 , T_5 * V_160 ,
T_5 * V_161 , T_5 * V_162 ,
T_5 * V_163 , T_5 * V_164 )
{
struct V_165 * V_166 ;
T_4 * V_81 ;
T_6 * V_167 ;
int V_116 = 0 ;
T_5 V_168 ;
if ( V_18 -> V_45 < V_50 ||
! V_18 -> V_87 ||
( V_18 -> V_33 . V_34 & V_169 ) == 0 )
return 0 ;
if ( V_18 -> V_33 . V_34 & V_85 )
return 0 ;
V_81 = F_26 ( V_18 -> V_87 , V_88 ) ;
if ( ! V_81 )
return 0 ;
memset ( V_81 , 0 , sizeof ( T_4 ) ) ;
V_167 = & V_81 -> V_90 . V_91 ;
V_167 -> V_92 = V_170 ;
V_167 -> V_94 = V_95 ;
V_81 -> V_171 = NULL ;
if ( V_18 -> V_172 -> V_70 & V_84 )
V_116 = V_173 ;
else
V_116 = F_27 ( V_18 , V_81 , V_18 -> V_102 * 2 ) ;
if ( V_116 != V_97 ) {
if ( V_116 != V_107 )
F_31 ( V_81 , V_18 -> V_87 ) ;
return 0 ;
}
if ( V_18 -> V_38 == V_142 ) {
V_166 = & V_81 -> V_90 . V_174 . V_175 . V_166 ;
if ( V_161 )
* V_161 = F_41 ( V_176 , V_166 ) ;
if ( V_162 )
* V_162 = F_41 ( V_176 , V_166 ) -
V_18 -> V_129 . V_177 . V_178 ;
if ( V_159 )
* V_159 = F_41 ( V_179 , V_166 ) ;
if ( V_160 )
* V_160 = F_41 ( V_179 , V_166 ) -
V_18 -> V_129 . V_177 . V_180 ;
V_168 = ( F_41 ( V_181 , V_166 ) > 0 ) ?
( F_41 ( V_181 , V_166 ) - 1 ) : 0 ;
if ( V_163 )
* V_163 = V_168 ;
if ( V_164 )
* V_164 = V_168 - V_18 -> V_129 . V_177 . V_182 ;
} else {
if ( V_161 )
* V_161 = V_167 -> V_175 . V_183 . V_184 ;
if ( V_162 )
* V_162 = V_167 -> V_175 . V_183 . V_185 ;
if ( V_159 )
* V_159 = V_167 -> V_175 . V_183 . V_186 ;
if ( V_160 )
* V_160 = V_167 -> V_175 . V_183 . V_187 ;
if ( V_163 )
* V_163 = V_167 -> V_175 . V_183 . V_168 ;
if ( V_164 )
* V_164 = V_167 -> V_175 . V_183 . V_188 ;
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
T_5 V_115 , V_189 ;
if ( F_50 ( V_18 , NULL , NULL , & V_115 , & V_189 , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_9 , ( V_115 - V_189 ) ) ;
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
T_5 V_115 , V_189 ;
if ( F_50 ( V_18 , & V_115 , & V_189 , NULL , NULL , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_9 , ( V_115 - V_189 ) ) ;
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
T_5 V_115 , V_189 ;
if ( F_50 ( V_18 , NULL , NULL , NULL , NULL , & V_115 , & V_189 ) )
return snprintf ( V_9 , V_10 , L_9 , ( V_115 - V_189 ) ) ;
return snprintf ( V_9 , V_10 , L_18 ) ;
}
static T_1
F_57 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( ! ( V_18 -> V_168 ) )
return snprintf ( V_9 , V_10 , L_40 ) ;
if ( V_15 -> V_190 == V_191 )
return snprintf ( V_9 , V_10 , L_41 ) ;
return snprintf ( V_9 , V_10 , L_42 , V_15 -> V_192 ) ;
}
static T_1
F_58 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_43 , V_18 -> V_193 ) ;
}
static T_1
F_59 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_73 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_5 V_194 ;
T_5 V_195 ;
int V_196 = 0 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_75 ;
if ( sscanf ( V_9 , L_44 , & V_196 ) != 1 )
return - V_75 ;
if ( ( V_196 & 0x3 ) != V_196 )
return - V_75 ;
if ( V_18 -> V_38 == V_142 )
V_196 = 0 ;
F_49 ( V_15 , V_104 , V_122 ,
L_45 ,
V_18 -> V_193 , V_196 ) ;
F_60 ( & V_18 -> V_197 ) ;
V_195 = V_18 -> V_193 ;
if ( V_196 & V_198 ) {
if ( ( V_196 & V_199 ) &&
! ( V_195 & V_199 ) ) {
if ( F_40 ( V_18 -> V_200 , & V_194 ) ) {
F_61 ( & V_18 -> V_197 ) ;
return - V_75 ;
}
V_194 &= ~ ( V_201 << V_202 ) ;
F_45 ( V_194 , V_18 -> V_200 ) ;
F_44 ( V_18 -> V_200 ) ;
F_62 ( V_18 ) ;
}
} else if ( V_196 != 0x0 ) {
F_61 ( & V_18 -> V_197 ) ;
return - V_75 ;
}
if ( ! ( V_196 & V_199 ) &&
( V_195 & V_199 ) )
{
F_61 ( & V_18 -> V_197 ) ;
F_63 ( & V_18 -> V_203 ) ;
F_60 ( & V_18 -> V_197 ) ;
if ( F_40 ( V_18 -> V_200 , & V_194 ) ) {
F_61 ( & V_18 -> V_197 ) ;
return - V_75 ;
}
V_194 |= ( V_201 << V_202 ) ;
F_45 ( V_194 , V_18 -> V_200 ) ;
F_44 ( V_18 -> V_200 ) ;
}
V_18 -> V_193 = V_196 ;
F_61 ( & V_18 -> V_197 ) ;
return strlen ( V_9 ) ;
}
static T_1
F_64 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_204 ) ;
}
static T_1
F_65 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_205 ) ;
}
static T_1
F_66 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_46 ,
( V_18 -> V_206 ) ? L_47 : L_48 ,
( V_18 -> V_22 & V_207 ) ?
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
T_7 V_208 ;
V_208 = F_68 ( V_18 ) ;
return snprintf ( V_9 , V_10 , L_9 , V_208 ) ;
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
if ( ( V_115 != strlen ( V_209 ) ) ||
( strncmp ( V_9 , V_209 , strlen ( V_209 ) ) != 0 ) )
return - V_75 ;
V_18 -> V_210 = 1 ;
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
( unsigned long long ) V_18 -> V_211 ) ;
}
static T_1
F_71 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_73 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_109 V_110 ;
int V_212 = 0 , V_213 = 0 ;
unsigned int V_3 , V_4 , V_115 = V_73 ;
T_8 V_214 [ 8 ] ;
int V_116 ;
if ( ! V_18 -> V_123 )
return - V_124 ;
F_60 ( & V_18 -> V_197 ) ;
if ( V_18 -> V_215 == V_216 ) {
F_61 ( & V_18 -> V_197 ) ;
return - V_124 ;
}
F_61 ( & V_18 -> V_197 ) ;
if ( V_9 [ V_115 - 1 ] == '\n' )
V_115 -- ;
if ( ! V_18 -> V_210 || ( V_115 < 16 ) || ( V_115 > 18 ) ||
( ( V_115 == 17 ) && ( * V_9 ++ != 'x' ) ) ||
( ( V_115 == 18 ) && ( ( * V_9 ++ != '0' ) || ( * V_9 ++ != 'x' ) ) ) )
return - V_75 ;
V_18 -> V_210 = 0 ;
memset ( V_214 , 0 , sizeof( V_214 ) ) ;
for ( V_3 = 0 , V_4 = 0 ; V_3 < 16 ; V_3 ++ ) {
int V_217 ;
V_217 = F_72 ( * V_9 ++ ) ;
if ( V_217 >= 0 )
V_4 = ( V_4 << 4 ) | V_217 ;
else
return - V_75 ;
if ( V_3 % 2 ) {
V_214 [ V_3 / 2 ] = V_4 & 0xff ;
V_4 = 0 ;
}
}
V_18 -> V_211 = F_73 ( V_214 ) ;
F_74 ( V_13 ) = V_18 -> V_211 ;
if ( V_18 -> V_218 )
F_75 ( V_13 ) = V_18 -> V_218 ;
F_76 ( V_219 , & V_18 -> V_140 -> V_6 ,
L_52 , V_18 -> V_220 ) ;
V_212 = F_32 ( V_18 , V_125 ) ;
if ( V_212 )
F_29 ( V_18 , V_104 , V_122 ,
L_53
L_54 , V_212 ) ;
F_33 ( & V_110 ) ;
V_116 = F_34 ( V_18 , & V_213 , & V_110 ,
V_126 ) ;
if ( V_116 == 0 )
return - V_89 ;
F_35 ( & V_110 ) ;
if ( V_213 )
F_29 ( V_18 , V_104 , V_122 ,
L_55
L_54 , V_213 ) ;
return ( V_212 || V_213 ) ? - V_108 : V_73 ;
}
static T_1
F_77 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_51 ,
( unsigned long long ) V_18 -> V_218 ) ;
}
static T_1
F_78 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_73 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
unsigned int V_3 , V_4 , V_115 = V_73 ;
T_8 V_221 [ 8 ] ;
if ( V_9 [ V_115 - 1 ] == '\n' )
V_115 -- ;
if ( ! V_18 -> V_210 || ( V_115 < 16 ) || ( V_115 > 18 ) ||
( ( V_115 == 17 ) && ( * V_9 ++ != 'x' ) ) ||
( ( V_115 == 18 ) && ( ( * V_9 ++ != '0' ) || ( * V_9 ++ != 'x' ) ) ) )
return - V_75 ;
memset ( V_221 , 0 , sizeof( V_221 ) ) ;
for ( V_3 = 0 , V_4 = 0 ; V_3 < 16 ; V_3 ++ ) {
int V_217 ;
V_217 = F_72 ( * V_9 ++ ) ;
if ( V_217 >= 0 )
V_4 = ( V_4 << 4 ) | V_217 ;
else
return - V_75 ;
if ( V_3 % 2 ) {
V_221 [ V_3 / 2 ] = V_4 & 0xff ;
V_4 = 0 ;
}
}
V_18 -> V_218 = F_73 ( V_221 ) ;
F_76 ( V_219 , & V_18 -> V_140 -> V_6 ,
L_56
L_57 , V_18 -> V_220 ) ;
return V_73 ;
}
static T_1
F_79 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_222 ) ;
}
static T_1
F_80 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 ,
V_18 -> V_33 . V_119 [ V_223 ] . V_224 ) ;
}
static T_1
F_81 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 ,
V_18 -> V_33 . V_119 [ V_223 ] . V_225 ) ;
}
static T_1
F_82 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
return snprintf ( V_9 , V_10 , L_9 , V_15 -> V_226 ) ;
}
static int
F_83 ( struct V_14 * V_15 , int V_196 )
{
if ( V_15 -> V_226 != V_227 ) {
V_15 -> V_228 = V_15 -> V_226 ;
if ( V_196 != V_227 )
F_49 ( V_15 , V_104 , V_122 ,
L_58
L_59
L_60 ) ;
return 0 ;
}
if ( V_196 >= V_229 && V_196 <= V_230 ) {
V_15 -> V_228 = V_196 ;
V_15 -> V_226 = V_196 ;
return 0 ;
}
F_49 ( V_15 , V_104 , V_122 ,
L_61
L_62 ,
V_196 , V_229 , V_230 ) ;
V_15 -> V_228 = V_227 ;
return - V_75 ;
}
static void
F_84 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
struct V_231 * V_232 ;
V_13 = F_85 ( V_15 ) ;
F_60 ( V_13 -> V_233 ) ;
F_86 (ndlp, &vport->fc_nodes, nlp_listp)
if ( F_87 ( V_232 ) && V_232 -> V_234 )
V_232 -> V_234 -> V_235 = V_15 -> V_226 ;
F_61 ( V_13 -> V_233 ) ;
}
static int
F_88 ( struct V_14 * V_15 , int V_196 )
{
if ( V_15 -> V_236 ||
( V_237 != V_227 ) ) {
F_49 ( V_15 , V_104 , V_122 ,
L_63
L_64 ) ;
return 0 ;
}
if ( V_196 >= V_229 && V_196 <= V_230 ) {
V_15 -> V_228 = V_196 ;
V_15 -> V_226 = V_196 ;
F_89 ( F_85 ( V_15 ) ) = V_196 ;
F_84 ( V_15 ) ;
return 0 ;
}
F_49 ( V_15 , V_104 , V_122 ,
L_65
L_66 ,
V_196 , V_229 , V_230 ) ;
return - V_75 ;
}
static int
F_90 ( struct V_14 * V_15 , int V_196 )
{
if ( V_196 >= V_229 && V_196 <= V_230 ) {
V_15 -> V_228 = V_196 ;
V_15 -> V_226 = V_196 ;
V_15 -> V_236 = 1 ;
F_89 ( F_85 ( V_15 ) ) = V_196 ;
F_84 ( V_15 ) ;
return 0 ;
}
F_49 ( V_15 , V_104 , V_122 ,
L_67
L_62 ,
V_196 , V_229 , V_230 ) ;
return - V_75 ;
}
static int
F_91 ( struct V_14 * V_15 , int V_196 )
{
if ( V_196 < 0 || V_196 > 1 ) {
F_49 ( V_15 , V_104 , V_122 ,
L_68
L_69 ,
V_196 ) ;
V_15 -> V_238 = 1 ;
return - V_75 ;
}
if ( V_15 -> V_190 == V_191 ) {
V_15 -> V_238 = 0 ;
return 0 ;
}
V_15 -> V_238 = V_196 ;
return 0 ;
}
static int
F_92 ( struct V_14 * V_15 , int V_196 )
{
if ( V_196 < 0 || V_196 > 1 ) {
F_49 ( V_15 , V_104 , V_122 ,
L_70
L_69 ,
V_196 ) ;
V_15 -> V_238 = 1 ;
return - V_75 ;
}
if ( V_15 -> V_190 == V_191 && V_196 != 0 ) {
F_49 ( V_15 , V_104 , V_122 ,
L_71
L_72 ) ;
V_15 -> V_238 = 0 ;
return 0 ;
}
V_15 -> V_238 = V_196 ;
return 0 ;
}
static T_1
F_93 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_73 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_196 = 0 ;
int V_239 = 0 ;
const char * V_240 = V_9 ;
int V_241 ;
T_5 V_242 ;
if ( ! strncmp ( V_9 , L_73 , strlen ( L_73 ) ) ) {
V_239 = 1 ;
V_240 = & V_9 [ strlen ( L_73 ) ] ;
}
if ( ! isdigit ( V_240 [ 0 ] ) )
return - V_75 ;
if ( sscanf ( V_240 , L_44 , & V_196 ) != 1 )
return - V_75 ;
if ( V_196 >= 0 && V_196 <= 6 ) {
V_242 = V_18 -> V_100 ;
V_18 -> V_100 = V_196 ;
if ( V_239 )
return strlen ( V_9 ) ;
F_49 ( V_15 , V_104 , V_122 ,
L_74 ,
V_242 , V_196 ) ;
V_241 = F_25 ( F_85 ( V_18 -> V_172 ) ) ;
if ( V_241 ) {
V_18 -> V_100 = V_242 ;
return - V_75 ;
} else
return strlen ( V_9 ) ;
}
F_29 ( V_18 , V_104 , V_122 ,
L_75
L_76 ,
V_18 -> V_220 , V_196 ) ;
return - V_75 ;
}
static T_1
F_94 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
if ( V_15 -> V_243 & V_244 )
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
static char V_245 [ F_96 ] ;
unsigned long V_3 ;
char * V_246 , * V_247 ;
struct V_14 * * V_248 ;
struct V_12 * V_249 ;
char * V_250 , * V_251 , * V_252 ;
unsigned long V_253 , V_254 , V_255 ;
if ( ! strncmp ( V_9 , L_77 , strlen ( L_77 ) ) ) {
if ( strlen ( V_9 ) > ( F_96 - 1 ) )
return - V_75 ;
strcpy ( V_245 , V_9 ) ;
V_246 = & V_245 [ 0 ] ;
V_247 = F_97 ( & V_246 , L_78 ) ;
if ( ! V_247 )
return - V_75 ;
V_250 = F_97 ( & V_246 , L_78 ) ;
if ( ! V_250 )
return - V_75 ;
if ( ! strncmp ( V_250 , L_79 , strlen ( L_79 ) ) )
V_255 = V_256 ;
else if ( ! strncmp ( V_250 , L_80 , strlen ( L_80 ) ) )
V_255 = V_257 ;
else
return - V_75 ;
V_251 = F_97 ( & V_246 , L_78 ) ;
if ( ! V_251 )
return - V_75 ;
V_253 = F_98 ( V_251 , NULL , 0 ) ;
V_252 = F_97 ( & V_246 , L_78 ) ;
if ( ! V_252 )
return - V_75 ;
V_254 = F_98 ( V_252 , NULL , 0 ) ;
if ( ! V_254 )
return - V_75 ;
V_248 = F_99 ( V_18 ) ;
if ( V_248 == NULL )
return - V_89 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_258 && V_248 [ V_3 ] != NULL ; V_3 ++ ) {
V_249 = F_85 ( V_248 [ V_3 ] ) ;
F_60 ( V_249 -> V_233 ) ;
V_248 [ V_3 ] -> V_259 = 1 ;
if ( V_248 [ V_3 ] -> V_260 )
F_100 ( V_248 [ V_3 ] ) ;
F_61 ( V_249 -> V_233 ) ;
}
V_18 -> V_255 = V_255 ;
V_18 -> V_261 = V_253 ;
V_18 -> V_262 = V_254 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_258 && V_248 [ V_3 ] != NULL ; V_3 ++ ) {
V_249 = F_85 ( V_248 [ V_3 ] ) ;
F_60 ( V_249 -> V_233 ) ;
V_248 [ V_3 ] -> V_259 = 0 ;
F_61 ( V_249 -> V_233 ) ;
}
F_101 ( V_18 , V_248 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_81 , strlen ( L_81 ) ) ) {
V_248 = F_99 ( V_18 ) ;
if ( V_248 == NULL )
return - V_89 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_258 && V_248 [ V_3 ] != NULL ; V_3 ++ ) {
V_249 = F_85 ( V_248 [ V_3 ] ) ;
F_60 ( V_13 -> V_233 ) ;
V_248 [ V_3 ] -> V_259 = 1 ;
F_102 ( V_15 ) ;
V_15 -> V_260 = 0 ;
V_248 [ V_3 ] -> V_259 = 0 ;
F_61 ( V_13 -> V_233 ) ;
}
F_101 ( V_18 , V_248 ) ;
V_18 -> V_255 = V_263 ;
V_18 -> V_261 = 0 ;
V_18 -> V_262 = 0 ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_82 , strlen ( L_82 ) ) ) {
if ( V_18 -> V_255 == V_263 )
return - V_75 ;
F_60 ( V_13 -> V_233 ) ;
if ( V_15 -> V_260 ) {
F_61 ( V_13 -> V_233 ) ;
return strlen ( V_9 ) ;
}
F_103 ( V_15 ) ;
V_15 -> V_260 = 1 ;
F_61 ( V_13 -> V_233 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_83 , strlen ( L_83 ) ) ) {
F_60 ( V_13 -> V_233 ) ;
if ( V_15 -> V_260 == 0 ) {
F_61 ( V_13 -> V_233 ) ;
return strlen ( V_9 ) ;
}
F_102 ( V_15 ) ;
V_15 -> V_260 = 0 ;
F_61 ( V_13 -> V_233 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_84 , strlen ( L_84 ) ) ) {
if ( ( V_18 -> V_255 == V_263 )
|| ! V_15 -> V_260 )
return strlen ( V_9 ) ;
F_60 ( V_13 -> V_233 ) ;
V_15 -> V_259 = 1 ;
F_100 ( V_15 ) ;
V_15 -> V_259 = 0 ;
F_61 ( V_13 -> V_233 ) ;
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
int V_264 = 0 ;
int V_3 ;
char * V_255 ;
unsigned long V_265 ;
switch ( V_18 -> V_255 ) {
case V_256 :
V_255 = L_79 ;
break;
case V_257 :
V_255 = L_80 ;
break;
default:
V_255 = L_85 ;
break;
}
sprintf ( & V_9 [ V_264 ] , L_86
L_87
L_88 ,
V_15 -> V_260 , V_15 -> V_259 ,
V_255 , V_18 -> V_261 , V_18 -> V_262 ) ;
V_264 = strlen ( V_9 ) ;
if ( V_18 -> V_255 != V_263 ) {
for ( V_3 = 0 ; V_3 < V_266 ; V_3 ++ ) {
if ( V_18 -> V_255 == V_256 )
V_265 = V_18 -> V_261 +
V_18 -> V_262 * V_3 ;
else
V_265 = V_18 -> V_261 +
( 1 << V_3 ) * V_18 -> V_262 ;
if ( V_264 + 10 > V_10 )
break;
sprintf ( & V_9 [ V_264 ] , L_89 , V_265 ) ;
V_264 = strlen ( V_9 ) ;
}
}
sprintf ( & V_9 [ V_264 ] , L_1 ) ;
return strlen ( V_9 ) ;
}
static T_1
F_105 ( struct V_267 * V_268 , struct V_269 * V_270 ,
struct V_271 * V_272 ,
char * V_9 , T_9 V_273 , T_3 V_73 )
{
struct V_5 * V_6 = F_106 ( V_270 , struct V_5 ,
V_270 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_3 = 0 , V_264 = 0 ;
unsigned long V_274 ;
struct V_231 * V_232 = NULL ;
V_274 = ( unsigned long ) V_273 /
V_275 ;
if ( ! V_15 -> V_260 || V_15 -> V_259
|| ( V_18 -> V_255 == V_263 ) )
return 0 ;
F_60 ( V_13 -> V_233 ) ;
F_86 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_87 ( V_232 ) || ! V_232 -> V_276 )
continue;
if ( V_274 > 0 ) {
V_274 -- ;
continue;
}
if ( ( V_264 + V_275 )
> V_73 )
break;
if ( ! V_232 -> V_276 )
continue;
sprintf ( & V_9 [ V_264 ] , L_90 ,
V_232 -> V_277 . V_90 . V_278 [ 0 ] ,
V_232 -> V_277 . V_90 . V_278 [ 1 ] ,
V_232 -> V_277 . V_90 . V_278 [ 2 ] ,
V_232 -> V_277 . V_90 . V_278 [ 3 ] ,
V_232 -> V_277 . V_90 . V_278 [ 4 ] ,
V_232 -> V_277 . V_90 . V_278 [ 5 ] ,
V_232 -> V_277 . V_90 . V_278 [ 6 ] ,
V_232 -> V_277 . V_90 . V_278 [ 7 ] ) ;
V_264 = strlen ( V_9 ) ;
for ( V_3 = 0 ; V_3 < V_266 ; V_3 ++ ) {
sprintf ( & V_9 [ V_264 ] , L_91 ,
V_232 -> V_276 [ V_3 ] . V_279 ) ;
V_264 = strlen ( V_9 ) ;
}
sprintf ( & V_9 [ V_264 ] , L_1 ) ;
V_264 = strlen ( V_9 ) ;
}
F_61 ( V_13 -> V_233 ) ;
return V_264 ;
}
static T_1
F_107 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_73 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_196 = V_280 ;
int V_239 = 0 ;
const char * V_240 = V_9 ;
int V_241 ;
T_5 V_242 ;
if ( ! strncmp ( V_9 , L_73 , strlen ( L_73 ) ) ) {
V_239 = 1 ;
V_240 = & V_9 [ strlen ( L_73 ) ] ;
}
if ( ! isdigit ( V_240 [ 0 ] ) )
return - V_75 ;
if ( sscanf ( V_240 , L_44 , & V_196 ) != 1 )
return - V_75 ;
F_49 ( V_15 , V_104 , V_122 ,
L_92 ,
V_18 -> V_101 , V_196 , V_239 ? L_93 : L_94 ) ;
if ( ( ( V_196 == V_281 ) && ! ( V_18 -> V_282 & V_283 ) ) ||
( ( V_196 == V_284 ) && ! ( V_18 -> V_282 & V_285 ) ) ||
( ( V_196 == V_286 ) && ! ( V_18 -> V_282 & V_287 ) ) ||
( ( V_196 == V_288 ) && ! ( V_18 -> V_282 & V_289 ) ) ||
( ( V_196 == V_290 ) && ! ( V_18 -> V_282 & V_291 ) ) ||
( ( V_196 == V_292 ) && ! ( V_18 -> V_282 & V_293 ) ) ) {
F_29 ( V_18 , V_104 , V_122 ,
L_95
L_96 ,
V_196 ) ;
return - V_75 ;
}
if ( ( V_196 >= 0 ) && ( V_196 <= V_294 ) &&
( V_295 & ( 1 << V_196 ) ) ) {
V_242 = V_18 -> V_101 ;
V_18 -> V_101 = V_196 ;
if ( V_239 )
return strlen ( V_9 ) ;
V_241 = F_25 ( F_85 ( V_18 -> V_172 ) ) ;
if ( V_241 ) {
V_18 -> V_101 = V_242 ;
return - V_75 ;
} else
return strlen ( V_9 ) ;
}
F_29 ( V_18 , V_104 , V_122 ,
L_97
L_98 V_296 L_99 , V_196 ) ;
return - V_75 ;
}
static int
F_108 ( struct V_17 * V_18 , int V_196 )
{
if ( ( V_196 >= 0 ) && ( V_196 <= V_294 ) &&
( V_295 & ( 1 << V_196 ) ) ) {
V_18 -> V_101 = V_196 ;
return 0 ;
}
F_29 ( V_18 , V_104 , V_122 ,
L_100
L_101
L_102 V_296 L_99 , V_196 ) ;
V_18 -> V_101 = V_280 ;
return - V_75 ;
}
static T_1
F_109 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_73 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_196 = 0 , V_116 = - V_75 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_75 ;
if ( sscanf ( V_9 , L_44 , & V_196 ) != 1 )
return - V_75 ;
switch ( V_196 ) {
case 0 :
if ( V_18 -> V_19 & V_297 ) {
V_116 = F_110 ( V_18 -> V_140 ) ;
if ( ! V_116 ) {
F_60 ( & V_18 -> V_197 ) ;
V_18 -> V_19 &= ~ V_297 ;
F_61 ( & V_18 -> V_197 ) ;
V_18 -> V_298 = 0 ;
V_116 = strlen ( V_9 ) ;
} else
V_116 = - V_86 ;
} else {
V_18 -> V_298 = 0 ;
V_116 = strlen ( V_9 ) ;
}
break;
case 1 :
if ( ! ( V_18 -> V_19 & V_297 ) ) {
V_116 = F_111 ( V_18 -> V_140 ) ;
if ( ! V_116 ) {
F_60 ( & V_18 -> V_197 ) ;
V_18 -> V_19 |= V_297 ;
F_61 ( & V_18 -> V_197 ) ;
V_18 -> V_298 = 1 ;
V_116 = strlen ( V_9 ) ;
} else
V_116 = - V_86 ;
} else {
V_18 -> V_298 = 1 ;
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
F_112 ( struct V_17 * V_18 , int V_196 )
{
if ( V_196 == 0 || V_196 == 1 ) {
V_18 -> V_298 = V_196 ;
return 0 ;
}
F_29 ( V_18 , V_104 , V_122 ,
L_103
L_104
L_105 , V_196 ) ;
V_18 -> V_298 = 1 ;
return - V_75 ;
}
static T_1
F_113 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_73 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_196 , V_116 = - 1 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_75 ;
if ( sscanf ( V_9 , L_44 , & V_196 ) != 1 )
return - V_75 ;
if ( V_196 != 1 )
return - V_75 ;
if ( V_18 -> V_19 & V_297 )
V_116 = F_114 ( V_18 -> V_140 ) ;
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
struct V_138 * V_139 = V_18 -> V_140 ;
int V_196 = 0 , V_116 = - V_75 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_75 ;
if ( sscanf ( V_9 , L_44 , & V_196 ) != 1 )
return - V_75 ;
if ( V_196 < 0 )
return - V_75 ;
if ( V_196 == 0 ) {
if ( V_18 -> V_146 > 0 ) {
F_43 ( V_139 ) ;
V_18 -> V_146 = 0 ;
}
return strlen ( V_9 ) ;
}
if ( V_18 -> V_146 > 0 ) {
F_29 ( V_18 , V_104 , V_122 ,
L_106
L_107 ,
V_18 -> V_146 ) ;
return - V_299 ;
}
if ( V_196 <= V_300 )
V_18 -> V_146 = V_196 ;
else {
F_29 ( V_18 , V_104 , V_122 ,
L_108
L_109 , V_196 ) ;
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
F_117 ( struct V_17 * V_18 , int V_196 )
{
if ( V_196 >= 0 && V_196 <= V_300 ) {
V_18 -> V_146 = V_196 ;
return 0 ;
}
F_29 ( V_18 , V_104 , V_122 ,
L_110
L_109 , V_196 ) ;
return - V_75 ;
}
static int
F_118 ( struct V_14 * V_15 , int V_196 )
{
struct V_12 * V_13 = F_85 ( V_15 ) ;
struct V_231 * V_232 , * V_301 ;
if ( V_196 == V_15 -> V_302 )
return 0 ;
if ( ( V_196 < 0 ) || ( V_196 > 60000 ) )
return - V_75 ;
V_15 -> V_302 = V_196 ;
F_60 ( V_13 -> V_233 ) ;
F_119 (ndlp, next_ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_87 ( V_232 ) )
continue;
if ( V_232 -> V_303 == V_304 )
continue;
V_232 -> V_305 = V_15 -> V_306 ;
}
F_61 ( V_13 -> V_233 ) ;
return 0 ;
}
static T_1
F_120 ( struct V_267 * V_268 , struct V_269 * V_270 ,
struct V_271 * V_272 ,
char * V_9 , T_9 V_273 , T_3 V_73 )
{
T_3 V_307 ;
struct V_5 * V_6 = F_106 ( V_270 , struct V_5 , V_270 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_38 >= V_142 )
return - V_86 ;
if ( ( V_273 + V_73 ) > V_308 )
return - V_309 ;
if ( V_73 <= V_310 )
return 0 ;
if ( V_273 % 4 || V_73 % 4 || ( unsigned long ) V_9 % 4 )
return - V_75 ;
if ( memcmp ( V_9 , V_311 , V_310 ) )
return - V_75 ;
if ( ! ( V_15 -> V_70 & V_84 ) )
return - V_86 ;
F_60 ( & V_18 -> V_197 ) ;
for ( V_307 = 0 ; V_307 < V_73 - V_310 ;
V_307 += sizeof( T_5 ) )
F_45 ( * ( ( T_5 * ) ( V_9 + V_307 + V_310 ) ) ,
V_18 -> V_312 + V_273 + V_307 ) ;
F_61 ( & V_18 -> V_197 ) ;
return V_73 ;
}
static T_1
F_121 ( struct V_267 * V_268 , struct V_269 * V_270 ,
struct V_271 * V_272 ,
char * V_9 , T_9 V_273 , T_3 V_73 )
{
T_3 V_307 ;
T_5 * V_313 ;
struct V_5 * V_6 = F_106 ( V_270 , struct V_5 , V_270 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_38 >= V_142 )
return - V_86 ;
if ( V_273 > V_308 )
return - V_309 ;
if ( ( V_273 + V_73 ) > V_308 )
V_73 = V_308 - V_273 ;
if ( V_73 == 0 ) return 0 ;
if ( V_273 % 4 || V_73 % 4 || ( unsigned long ) V_9 % 4 )
return - V_75 ;
F_60 ( & V_18 -> V_197 ) ;
for ( V_307 = 0 ; V_307 < V_73 ; V_307 += sizeof( T_5 ) ) {
V_313 = ( T_5 * ) ( V_9 + V_307 ) ;
* V_313 = F_44 ( V_18 -> V_312 + V_273 + V_307 ) ;
}
F_61 ( & V_18 -> V_197 ) ;
return V_73 ;
}
static void
F_122 ( struct V_17 * V_18 )
{
V_18 -> V_314 . V_156 = V_315 ;
V_18 -> V_314 . V_316 = 0 ;
if ( V_18 -> V_314 . V_317 ) {
F_31 ( V_18 -> V_314 . V_317 ,
V_18 -> V_87 ) ;
V_18 -> V_314 . V_317 = NULL ;
}
}
static T_1
F_123 ( struct V_267 * V_268 , struct V_269 * V_270 ,
struct V_271 * V_272 ,
char * V_9 , T_9 V_273 , T_3 V_73 )
{
struct V_5 * V_6 = F_106 ( V_270 , struct V_5 , V_270 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_318 * V_317 = NULL ;
if ( ( V_73 + V_273 ) > V_319 )
return - V_309 ;
if ( V_273 % 4 || V_73 % 4 || ( unsigned long ) V_9 % 4 )
return - V_75 ;
if ( V_73 == 0 )
return 0 ;
if ( V_273 == 0 ) {
V_317 = F_26 ( V_18 -> V_87 , V_88 ) ;
if ( ! V_317 )
return - V_89 ;
memset ( V_317 , 0 , sizeof ( T_4 ) ) ;
}
F_60 ( & V_18 -> V_197 ) ;
if ( V_273 == 0 ) {
if ( V_18 -> V_314 . V_317 )
F_31 ( V_317 , V_18 -> V_87 ) ;
else
V_18 -> V_314 . V_317 = V_317 ;
V_18 -> V_314 . V_156 = V_320 ;
} else {
if ( V_18 -> V_314 . V_156 != V_320 ||
V_18 -> V_314 . V_316 != V_273 ||
V_18 -> V_314 . V_317 == NULL ) {
F_122 ( V_18 ) ;
F_61 ( & V_18 -> V_197 ) ;
return - V_321 ;
}
}
memcpy ( ( V_322 * ) & V_18 -> V_314 . V_317 -> V_90 . V_91 + V_273 ,
V_9 , V_73 ) ;
V_18 -> V_314 . V_316 = V_273 + V_73 ;
F_61 ( & V_18 -> V_197 ) ;
return V_73 ;
}
static T_1
F_124 ( struct V_267 * V_268 , struct V_269 * V_270 ,
struct V_271 * V_272 ,
char * V_9 , T_9 V_273 , T_3 V_73 )
{
struct V_5 * V_6 = F_106 ( V_270 , struct V_5 , V_270 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_4 * V_323 ;
T_6 * V_167 ;
T_5 V_324 ;
int V_116 ;
if ( V_273 > V_319 )
return - V_309 ;
if ( ( V_73 + V_273 ) > V_319 )
V_73 = V_319 - V_273 ;
if ( V_273 % 4 || V_73 % 4 || ( unsigned long ) V_9 % 4 )
return - V_75 ;
if ( V_273 && V_73 == 0 )
return 0 ;
F_60 ( & V_18 -> V_197 ) ;
if ( V_18 -> V_215 == V_216 ) {
F_122 ( V_18 ) ;
F_61 ( & V_18 -> V_197 ) ;
return - V_124 ;
}
if ( V_273 == 0 &&
V_18 -> V_314 . V_156 == V_320 &&
V_18 -> V_314 . V_316 >= 2 * sizeof( T_5 ) ) {
V_323 = ( T_4 * ) & V_18 -> V_314 . V_317 ;
V_167 = & V_323 -> V_90 . V_91 ;
switch ( V_167 -> V_92 ) {
case V_325 :
case V_93 :
case V_326 :
case V_327 :
case V_328 :
case V_329 :
case V_330 :
case V_331 :
case V_332 :
case V_333 :
case V_334 :
case V_335 :
if ( ! ( V_15 -> V_70 & V_84 ) ) {
F_125 ( V_121 L_111
L_112 ,
V_167 -> V_92 ) ;
F_122 ( V_18 ) ;
F_61 ( & V_18 -> V_197 ) ;
return - V_86 ;
}
case V_336 :
case V_337 :
case V_338 :
case V_339 :
case V_170 :
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
case V_354 :
case V_355 :
case V_356 :
break;
case V_357 :
case V_358 :
if ( V_18 -> V_359 == V_360 ) {
F_125 ( V_121 L_111
L_113 , V_167 -> V_92 ) ;
F_122 ( V_18 ) ;
F_61 ( & V_18 -> V_197 ) ;
return - V_86 ;
}
break;
case V_361 :
case V_362 :
case V_363 :
case V_364 :
case V_365 :
case V_366 :
F_125 ( V_121 L_114 ,
V_167 -> V_92 ) ;
F_122 ( V_18 ) ;
F_61 ( & V_18 -> V_197 ) ;
return - V_86 ;
default:
F_125 ( V_121 L_115 ,
V_167 -> V_92 ) ;
F_122 ( V_18 ) ;
F_61 ( & V_18 -> V_197 ) ;
return - V_86 ;
}
if ( V_18 -> V_172 -> V_367 &&
V_167 -> V_92 != V_345 &&
V_167 -> V_92 != V_333 &&
V_167 -> V_92 != V_337 &&
V_167 -> V_92 != V_354 )
F_29 ( V_18 , V_121 , V_105 ,
L_116
L_117 ,
V_167 -> V_92 ) ;
V_18 -> V_314 . V_317 -> V_15 = V_15 ;
if ( V_18 -> V_33 . V_34 & V_85 ) {
F_122 ( V_18 ) ;
F_61 ( & V_18 -> V_197 ) ;
return - V_321 ;
}
if ( ( V_15 -> V_70 & V_84 ) ||
( ! ( V_18 -> V_33 . V_34 & V_169 ) ) ) {
F_61 ( & V_18 -> V_197 ) ;
V_116 = F_126 ( V_18 ,
V_18 -> V_314 . V_317 ,
V_368 ) ;
F_60 ( & V_18 -> V_197 ) ;
} else {
F_61 ( & V_18 -> V_197 ) ;
V_324 = F_127 ( V_18 , V_323 ) ;
V_116 = F_27 ( V_18 , V_323 , V_324 ) ;
F_60 ( & V_18 -> V_197 ) ;
}
if ( V_116 != V_97 ) {
if ( V_116 == V_107 ) {
V_18 -> V_314 . V_317 = NULL ;
}
F_122 ( V_18 ) ;
F_61 ( & V_18 -> V_197 ) ;
return ( V_116 == V_107 ) ? - V_369 : - V_370 ;
}
V_18 -> V_314 . V_156 = V_371 ;
}
else if ( V_18 -> V_314 . V_316 != V_273 ||
V_18 -> V_314 . V_156 != V_371 ) {
F_125 ( V_121 L_118 ) ;
F_122 ( V_18 ) ;
F_61 ( & V_18 -> V_197 ) ;
return - V_321 ;
}
memcpy ( V_9 , ( V_322 * ) & V_167 + V_273 , V_73 ) ;
V_18 -> V_314 . V_316 = V_273 + V_73 ;
if ( V_18 -> V_314 . V_316 == V_319 )
F_122 ( V_18 ) ;
F_61 ( & V_18 -> V_197 ) ;
return V_73 ;
}
int
F_128 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = F_85 ( V_15 ) ;
int error ;
error = F_129 ( & V_13 -> V_372 . V_270 ,
& V_373 ) ;
if ( error || V_15 -> V_190 == V_374 )
goto V_375;
error = F_129 ( & V_13 -> V_372 . V_270 ,
& V_376 ) ;
if ( error )
goto V_377;
error = F_129 ( & V_13 -> V_372 . V_270 ,
& V_378 ) ;
if ( error )
goto V_379;
return 0 ;
V_379:
F_130 ( & V_13 -> V_372 . V_270 , & V_376 ) ;
V_377:
F_130 ( & V_13 -> V_372 . V_270 ,
& V_373 ) ;
V_375:
return error ;
}
void
F_131 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = F_85 ( V_15 ) ;
F_130 ( & V_13 -> V_372 . V_270 ,
& V_373 ) ;
if ( V_15 -> V_190 == V_374 )
return;
F_130 ( & V_13 -> V_372 . V_270 , & V_378 ) ;
F_130 ( & V_13 -> V_372 . V_270 , & V_376 ) ;
}
static void
F_132 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
F_133 ( V_13 ) = V_15 -> V_380 ;
}
static void
F_134 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_60 ( V_13 -> V_233 ) ;
if ( V_15 -> V_190 == V_374 ) {
F_135 ( V_13 ) = V_381 ;
} else if ( F_136 ( V_18 ) ) {
if ( V_18 -> V_68 == V_69 ) {
if ( V_15 -> V_70 & V_71 )
F_135 ( V_13 ) = V_382 ;
else
F_135 ( V_13 ) = V_383 ;
} else {
if ( V_15 -> V_70 & V_72 )
F_135 ( V_13 ) = V_384 ;
else
F_135 ( V_13 ) = V_385 ;
}
} else
F_135 ( V_13 ) = V_386 ;
F_61 ( V_13 -> V_233 ) ;
}
static void
F_137 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_60 ( V_13 -> V_233 ) ;
if ( V_15 -> V_70 & V_84 )
F_138 ( V_13 ) = V_387 ;
else {
switch ( V_18 -> V_45 ) {
case V_46 :
case V_50 :
F_138 ( V_13 ) = V_388 ;
break;
case V_53 :
case V_54 :
case V_55 :
F_138 ( V_13 ) = V_389 ;
break;
case V_51 :
F_138 ( V_13 ) = V_390 ;
break;
default:
F_138 ( V_13 ) = V_391 ;
break;
}
}
F_61 ( V_13 -> V_233 ) ;
}
static void
F_139 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_60 ( V_13 -> V_233 ) ;
if ( F_136 ( V_18 ) ) {
switch( V_18 -> V_392 ) {
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
case V_403 :
F_140 ( V_13 ) = V_404 ;
break;
default:
F_140 ( V_13 ) = V_405 ;
break;
}
} else
F_140 ( V_13 ) = V_405 ;
F_61 ( V_13 -> V_233 ) ;
}
static void
F_141 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_10 V_406 ;
F_60 ( V_13 -> V_233 ) ;
if ( ( V_15 -> V_56 > V_59 ) &&
( ( V_15 -> V_70 & V_72 ) ||
( ( V_18 -> V_68 == V_69 ) &&
( V_15 -> V_70 & V_71 ) ) ) )
V_406 = F_73 ( V_18 -> V_407 . V_408 . V_90 . V_278 ) ;
else
V_406 = 0 ;
F_61 ( V_13 -> V_233 ) ;
F_142 ( V_13 ) = V_406 ;
}
static struct V_409 *
F_143 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_113 * V_114 = & V_18 -> V_33 ;
struct V_409 * V_410 = & V_18 -> V_411 ;
struct V_412 * V_413 = & V_114 -> V_414 ;
T_4 * V_81 ;
T_6 * V_167 ;
unsigned long V_415 ;
int V_116 = 0 ;
if ( V_18 -> V_45 < V_50 ||
! V_18 -> V_87 ||
( V_18 -> V_33 . V_34 & V_169 ) == 0 )
return NULL ;
if ( V_18 -> V_33 . V_34 & V_85 )
return NULL ;
V_81 = F_26 ( V_18 -> V_87 , V_88 ) ;
if ( ! V_81 )
return NULL ;
memset ( V_81 , 0 , sizeof ( T_4 ) ) ;
V_167 = & V_81 -> V_90 . V_91 ;
V_167 -> V_92 = V_341 ;
V_167 -> V_94 = V_95 ;
V_81 -> V_171 = NULL ;
V_81 -> V_15 = V_15 ;
if ( V_15 -> V_70 & V_84 )
V_116 = F_126 ( V_18 , V_81 , V_368 ) ;
else
V_116 = F_27 ( V_18 , V_81 , V_18 -> V_102 * 2 ) ;
if ( V_116 != V_97 ) {
if ( V_116 != V_107 )
F_31 ( V_81 , V_18 -> V_87 ) ;
return NULL ;
}
memset ( V_410 , 0 , sizeof ( struct V_409 ) ) ;
V_410 -> V_416 = V_167 -> V_175 . V_417 . V_418 ;
V_410 -> V_419 = ( V_420 )
( ( V_420 ) V_167 -> V_175 . V_417 . V_421
* ( V_420 ) 256 ) ;
V_410 -> V_422 = V_167 -> V_175 . V_417 . V_423 ;
V_410 -> V_424 = ( V_420 )
( ( V_420 ) V_167 -> V_175 . V_417 . V_425
* ( V_420 ) 256 ) ;
memset ( V_81 , 0 , sizeof ( T_4 ) ) ;
V_167 -> V_92 = V_344 ;
V_167 -> V_94 = V_95 ;
V_81 -> V_171 = NULL ;
V_81 -> V_15 = V_15 ;
if ( V_15 -> V_70 & V_84 )
V_116 = F_126 ( V_18 , V_81 , V_368 ) ;
else
V_116 = F_27 ( V_18 , V_81 , V_18 -> V_102 * 2 ) ;
if ( V_116 != V_97 ) {
if ( V_116 != V_107 )
F_31 ( V_81 , V_18 -> V_87 ) ;
return NULL ;
}
V_410 -> V_426 = V_167 -> V_175 . V_427 . V_428 ;
V_410 -> V_429 = V_167 -> V_175 . V_427 . V_430 ;
V_410 -> V_431 = V_167 -> V_175 . V_427 . V_432 ;
V_410 -> V_433 = V_167 -> V_175 . V_427 . V_434 ;
V_410 -> V_435 = V_167 -> V_175 . V_427 . V_436 ;
V_410 -> V_437 = V_167 -> V_175 . V_427 . V_438 ;
V_410 -> V_439 = V_167 -> V_175 . V_427 . V_438 ;
V_410 -> V_426 -= V_413 -> V_426 ;
V_410 -> V_429 -= V_413 -> V_429 ;
V_410 -> V_431 -= V_413 -> V_431 ;
V_410 -> V_433 -= V_413 -> V_433 ;
V_410 -> V_435 -= V_413 -> V_435 ;
V_410 -> V_437 -= V_413 -> V_437 ;
V_410 -> V_439 -= V_413 -> V_439 ;
if ( V_18 -> V_19 & V_440 ) {
V_410 -> V_441 = - 1 ;
V_410 -> V_442 = ( V_18 -> V_443 >> 1 ) ;
V_410 -> V_442 -= V_413 -> V_443 ;
} else if ( V_18 -> V_68 == V_69 ) {
V_410 -> V_441 = ( V_18 -> V_444 >> 1 ) ;
V_410 -> V_441 -= V_413 -> V_443 ;
V_410 -> V_442 = - 1 ;
} else {
V_410 -> V_441 = - 1 ;
V_410 -> V_442 = ( V_18 -> V_444 >> 1 ) ;
V_410 -> V_442 -= V_413 -> V_443 ;
}
V_410 -> V_445 = - 1 ;
V_415 = F_144 () ;
if ( V_415 < V_114 -> V_446 )
V_410 -> V_447 = V_415 +
( ( unsigned long ) - 1 - V_114 -> V_446 ) ;
else
V_410 -> V_447 = V_415 - V_114 -> V_446 ;
F_31 ( V_81 , V_18 -> V_87 ) ;
return V_410 ;
}
static void
F_145 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_113 * V_114 = & V_18 -> V_33 ;
struct V_412 * V_413 = & V_114 -> V_414 ;
T_4 * V_81 ;
T_6 * V_167 ;
int V_116 = 0 ;
if ( V_18 -> V_33 . V_34 & V_85 )
return;
V_81 = F_26 ( V_18 -> V_87 , V_88 ) ;
if ( ! V_81 )
return;
memset ( V_81 , 0 , sizeof( T_4 ) ) ;
V_167 = & V_81 -> V_90 . V_91 ;
V_167 -> V_92 = V_341 ;
V_167 -> V_94 = V_95 ;
V_167 -> V_175 . V_448 [ 0 ] = 0x1 ;
V_81 -> V_171 = NULL ;
V_81 -> V_15 = V_15 ;
if ( ( V_15 -> V_70 & V_84 ) ||
( ! ( V_114 -> V_34 & V_169 ) ) )
V_116 = F_126 ( V_18 , V_81 , V_368 ) ;
else
V_116 = F_27 ( V_18 , V_81 , V_18 -> V_102 * 2 ) ;
if ( V_116 != V_97 ) {
if ( V_116 != V_107 )
F_31 ( V_81 , V_18 -> V_87 ) ;
return;
}
memset ( V_81 , 0 , sizeof( T_4 ) ) ;
V_167 -> V_92 = V_344 ;
V_167 -> V_94 = V_95 ;
V_81 -> V_171 = NULL ;
V_81 -> V_15 = V_15 ;
if ( ( V_15 -> V_70 & V_84 ) ||
( ! ( V_114 -> V_34 & V_169 ) ) )
V_116 = F_126 ( V_18 , V_81 , V_368 ) ;
else
V_116 = F_27 ( V_18 , V_81 , V_18 -> V_102 * 2 ) ;
if ( V_116 != V_97 ) {
if ( V_116 != V_107 )
F_31 ( V_81 , V_18 -> V_87 ) ;
return;
}
V_413 -> V_426 = V_167 -> V_175 . V_427 . V_428 ;
V_413 -> V_429 = V_167 -> V_175 . V_427 . V_430 ;
V_413 -> V_431 = V_167 -> V_175 . V_427 . V_432 ;
V_413 -> V_433 = V_167 -> V_175 . V_427 . V_434 ;
V_413 -> V_435 = V_167 -> V_175 . V_427 . V_436 ;
V_413 -> V_437 = V_167 -> V_175 . V_427 . V_438 ;
V_413 -> V_439 = V_167 -> V_175 . V_427 . V_438 ;
if ( V_18 -> V_19 & V_440 )
V_413 -> V_443 = ( V_18 -> V_443 >> 1 ) ;
else
V_413 -> V_443 = ( V_18 -> V_444 >> 1 ) ;
V_114 -> V_446 = F_144 () ;
F_31 ( V_81 , V_18 -> V_87 ) ;
return;
}
static struct V_231 *
F_146 ( struct V_449 * V_450 )
{
struct V_12 * V_13 = F_147 ( V_450 -> V_6 . V_451 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_231 * V_232 ;
F_60 ( V_13 -> V_233 ) ;
F_86 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( F_87 ( V_232 ) &&
V_232 -> V_303 == V_452 &&
V_450 -> V_453 == V_232 -> V_454 ) {
F_61 ( V_13 -> V_233 ) ;
return V_232 ;
}
}
F_61 ( V_13 -> V_233 ) ;
return NULL ;
}
static void
F_148 ( struct V_449 * V_450 )
{
struct V_231 * V_232 = F_146 ( V_450 ) ;
F_149 ( V_450 ) = V_232 ? V_232 -> V_455 : - 1 ;
}
static void
F_150 ( struct V_449 * V_450 )
{
struct V_231 * V_232 = F_146 ( V_450 ) ;
F_151 ( V_450 ) =
V_232 ? F_73 ( V_232 -> V_456 . V_90 . V_278 ) : 0 ;
}
static void
F_152 ( struct V_449 * V_450 )
{
struct V_231 * V_232 = F_146 ( V_450 ) ;
F_153 ( V_450 ) =
V_232 ? F_73 ( V_232 -> V_277 . V_90 . V_278 ) : 0 ;
}
static void
F_154 ( struct V_457 * V_234 , T_5 V_458 )
{
if ( V_458 )
V_234 -> V_235 = V_458 ;
else
V_234 -> V_235 = 1 ;
}
static void
F_155 ( struct V_459 * V_459 )
{
struct V_14 * V_15 = * (struct V_14 * * ) V_459 -> V_460 ;
if ( V_15 -> V_56 == V_65 )
F_156 ( V_15 , V_461 , 0 , 0 ) ;
}
static void
F_157 ( struct V_17 * V_18 , T_5 V_462 )
{
V_18 -> V_463 = V_462 ;
}
void
F_158 ( struct V_17 * V_18 )
{
F_159 ( V_18 , V_464 ) ;
F_160 ( V_18 , V_465 ) ;
F_161 ( V_18 , V_466 ) ;
F_162 ( V_18 , V_467 ) ;
F_163 ( V_18 , V_468 ) ;
F_164 ( V_18 , V_469 ) ;
F_165 ( V_18 , V_470 ) ;
F_108 ( V_18 , V_471 ) ;
F_166 ( V_18 , V_472 ) ;
F_167 ( V_18 , V_473 ) ;
F_168 ( V_18 , V_474 ) ;
F_169 ( V_18 , V_475 ) ;
F_170 ( V_18 , V_476 ) ;
F_171 ( V_18 , V_477 ) ;
F_172 ( V_18 , V_478 ) ;
F_173 ( V_18 , V_479 ) ;
F_174 ( V_18 , V_480 ) ;
F_175 ( V_18 , V_481 ) ;
F_176 ( V_18 , V_482 ) ;
if ( V_18 -> V_38 == V_142 )
V_18 -> V_193 = 0 ;
else
V_18 -> V_193 = V_483 ;
V_18 -> V_218 = 0L ;
V_18 -> V_211 = 0L ;
F_177 ( V_18 , V_484 ) ;
F_178 ( V_18 , V_485 ) ;
F_179 ( V_18 , V_486 ) ;
F_157 ( V_18 , V_487 ) ;
F_112 ( V_18 , V_488 ) ;
F_117 ( V_18 , V_489 ) ;
F_180 ( V_18 , V_490 ) ;
F_181 ( V_18 , V_491 ) ;
V_18 -> V_206 = 1 ;
return;
}
void
F_182 ( struct V_14 * V_15 )
{
F_183 ( V_15 , V_487 ) ;
F_184 ( V_15 , V_492 ) ;
F_185 ( V_15 , V_493 ) ;
F_186 ( V_15 , V_237 ) ;
F_83 ( V_15 , V_494 ) ;
F_187 ( V_15 , V_495 ) ;
F_91 ( V_15 , V_496 ) ;
F_188 ( V_15 , V_497 ) ;
F_189 ( V_15 , V_498 ) ;
F_190 ( V_15 , V_499 ) ;
F_191 ( V_15 , V_500 ) ;
F_192 ( V_15 , V_501 ) ;
F_193 ( V_15 , V_502 ) ;
F_194 ( V_15 , V_503 ) ;
F_195 ( V_15 , V_504 ) ;
return;
}
