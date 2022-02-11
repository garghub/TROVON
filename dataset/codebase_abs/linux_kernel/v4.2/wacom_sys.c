static int F_1 ( struct V_1 * V_2 , T_1 type , T_1 * V_3 ,
T_2 V_4 , unsigned int V_5 )
{
int V_6 ;
do {
V_6 = F_2 ( V_2 , V_3 [ 0 ] , V_3 , V_4 , type ,
V_7 ) ;
} while ( ( V_6 == - V_8 || V_6 == - V_9 ) && -- V_5 );
if ( V_6 < 0 )
F_3 ( V_2 , L_1
L_2 , V_6 ) ;
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 type , T_1 * V_3 ,
T_2 V_4 , unsigned int V_5 )
{
int V_6 ;
do {
V_6 = F_2 ( V_2 , V_3 [ 0 ] , V_3 , V_4 , type ,
V_10 ) ;
} while ( ( V_6 == - V_8 || V_6 == - V_9 ) && -- V_5 );
if ( V_6 < 0 )
F_3 ( V_2 , L_3
L_2 , V_6 ) ;
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_11 * V_12 ,
T_1 * V_13 , int V_4 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
if ( V_4 > V_15 )
return 1 ;
memcpy ( V_14 -> V_16 . V_17 , V_13 , V_4 ) ;
F_7 ( & V_14 -> V_16 , V_4 ) ;
return 0 ;
}
static int F_8 ( struct V_18 * V_19 )
{
struct V_14 * V_14 = F_9 ( V_19 ) ;
return F_10 ( V_14 -> V_2 ) ;
}
static void F_11 ( struct V_18 * V_19 )
{
struct V_14 * V_14 = F_9 ( V_19 ) ;
F_12 ( V_14 -> V_2 ) ;
}
static int F_13 ( int V_20 , int V_21 ,
unsigned V_22 , int V_23 )
{
struct V_24 V_25 = {
. V_26 = V_20 ,
. V_27 = V_21 ,
. V_22 = V_22 ,
. V_28 = V_23 ,
} ;
return F_14 ( & V_25 , V_29 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_24 * V_25 , struct V_30 * V_31 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_32 * V_33 = & V_14 -> V_16 . V_33 ;
struct V_34 * V_34 = & V_14 -> V_16 . V_34 ;
T_1 * V_17 ;
int V_35 ;
switch ( V_31 -> V_36 ) {
case V_37 :
if ( ! V_33 -> V_38 ) {
V_17 = F_16 ( 2 , V_39 ) ;
if ( ! V_17 )
break;
V_17 [ 0 ] = V_25 -> V_12 -> V_40 ;
V_35 = F_1 ( V_2 , V_41 ,
V_17 , 2 , V_42 ) ;
if ( V_35 == 2 ) {
V_33 -> V_38 = V_17 [ 1 ] ;
} else {
V_33 -> V_38 = 16 ;
F_17 ( V_2 , L_4
L_5
L_6 ,
V_33 -> V_38 ) ;
}
F_18 ( V_17 ) ;
}
break;
case V_43 :
if ( V_31 -> V_44 >= V_25 -> V_45 ) {
F_19 ( & V_2 -> V_19 , L_7 ) ;
break;
}
V_34 -> V_46 = V_25 -> V_12 -> V_40 ;
V_34 -> V_47 = V_31 -> V_44 ;
break;
}
}
static void F_20 ( struct V_1 * V_2 ,
struct V_24 * V_25 , struct V_30 * V_31 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_32 * V_33 = & V_14 -> V_16 . V_33 ;
bool V_48 = F_21 ( V_25 ) ;
bool V_49 = F_22 ( V_25 ) ;
if ( V_49 )
V_33 -> V_50 |= V_51 ;
else if ( V_48 )
V_33 -> V_50 |= V_52 ;
else
return;
if ( V_33 -> type != V_53 ) {
if ( V_48 && ! V_33 -> V_38 )
V_33 -> V_38 = 1 ;
}
switch ( V_31 -> V_36 ) {
case V_54 :
V_33 -> V_55 = V_25 -> V_26 ;
if ( V_48 ) {
V_33 -> V_56 = V_25 -> V_27 ;
if ( V_33 -> type != V_53 ) {
V_33 -> V_22 = V_25 -> V_22 ;
V_33 -> V_57 = V_25 -> V_28 ;
}
}
break;
case V_58 :
V_33 -> V_59 = V_25 -> V_26 ;
if ( V_48 ) {
V_33 -> V_60 = V_25 -> V_27 ;
if ( V_33 -> type != V_53 ) {
V_33 -> V_22 = V_25 -> V_22 ;
V_33 -> V_57 = V_25 -> V_28 ;
}
}
break;
case V_61 :
if ( V_49 )
V_33 -> V_62 = V_25 -> V_26 ;
break;
}
if ( V_33 -> type == V_63 )
F_23 ( V_2 , V_25 , V_31 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_16 * V_16 = & V_14 -> V_16 ;
if ( V_33 -> type == V_63 ) {
if ( V_33 -> V_38 > 1 ) {
F_25 ( V_16 -> V_64 , V_16 -> V_33 . V_38 ,
V_65 ) ;
}
}
}
static void F_26 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_66 * V_67 ;
struct V_11 * V_68 ;
int V_69 , V_70 ;
V_67 = & V_2 -> V_71 [ V_41 ] ;
F_27 (hreport, &rep_enum->report_list, list) {
for ( V_69 = 0 ; V_69 < V_68 -> V_72 ; V_69 ++ ) {
if ( V_68 -> V_25 [ V_69 ] -> V_45 < 1 )
continue;
for ( V_70 = 0 ; V_70 < V_68 -> V_25 [ V_69 ] -> V_73 ; V_70 ++ ) {
F_15 ( V_2 , V_68 -> V_25 [ V_69 ] ,
V_68 -> V_25 [ V_69 ] -> V_31 + V_70 ) ;
}
}
}
V_67 = & V_2 -> V_71 [ V_74 ] ;
F_27 (hreport, &rep_enum->report_list, list) {
if ( ! V_68 -> V_72 )
continue;
for ( V_69 = 0 ; V_69 < V_68 -> V_72 ; V_69 ++ )
for ( V_70 = 0 ; V_70 < V_68 -> V_25 [ V_69 ] -> V_73 ; V_70 ++ )
F_20 ( V_2 , V_68 -> V_25 [ V_69 ] ,
V_68 -> V_25 [ V_69 ] -> V_31 + V_70 ) ;
}
F_24 ( V_2 , V_33 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_34 * V_34 = & V_14 -> V_16 . V_34 ;
struct V_11 * V_75 ;
struct V_66 * V_76 ;
if ( V_34 -> V_46 < 0 )
return 0 ;
V_76 = & ( V_2 -> V_71 [ V_41 ] ) ;
V_75 = V_76 -> V_77 [ V_34 -> V_46 ] ;
if ( V_75 ) {
V_75 -> V_25 [ 0 ] -> V_78 [ V_34 -> V_47 ] = 2 ;
F_29 ( V_2 , V_75 , V_10 ) ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , int V_79 ,
int V_80 , int V_81 )
{
unsigned char * V_82 ;
int error = - V_83 , V_84 = 0 ;
V_82 = F_16 ( V_80 , V_39 ) ;
if ( ! V_82 )
return error ;
do {
V_82 [ 0 ] = V_79 ;
V_82 [ 1 ] = V_81 ;
error = F_4 ( V_2 , V_41 , V_82 ,
V_80 , 1 ) ;
if ( error >= 0 )
error = F_1 ( V_2 , V_41 ,
V_82 , V_80 , 1 ) ;
} while ( ( error < 0 || V_82 [ 1 ] != V_81 ) && V_84 ++ < V_85 );
F_18 ( V_82 ) ;
return error < 0 ? error : 0 ;
}
static int F_31 ( struct V_1 * V_2 , T_1 V_86 ,
struct V_32 * V_33 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
int V_35 ;
T_1 V_82 [ 2 ] ;
switch ( V_33 -> type ) {
case V_87 :
V_82 [ 0 ] = 0x03 ;
V_82 [ 1 ] = 0x00 ;
V_35 = F_4 ( V_2 , V_41 , V_82 , 2 ,
3 ) ;
if ( V_35 >= 0 ) {
V_82 [ 0 ] = V_86 == 0 ? 0x05 : 0x06 ;
V_82 [ 1 ] = 0x00 ;
V_35 = F_4 ( V_2 , V_41 ,
V_82 , 2 , 3 ) ;
if ( V_35 >= 0 ) {
V_14 -> V_16 . V_88 = V_86 ;
return 0 ;
}
}
F_17 ( V_2 , L_8 ,
V_82 [ 0 ] , V_35 ) ;
break;
case V_89 :
if ( V_86 == 1 )
V_14 -> V_16 . V_90 &= ~ 0x20 ;
else
V_14 -> V_16 . V_90 |= 0x20 ;
V_82 [ 0 ] = 0x03 ;
V_82 [ 1 ] = V_14 -> V_16 . V_90 ;
V_35 = F_4 ( V_2 , V_41 , V_82 , 2 ,
1 ) ;
if ( V_35 >= 0 )
V_14 -> V_16 . V_88 = V_86 ;
break;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
if ( V_2 -> V_91 == V_92 )
return F_31 ( V_2 , 1 , V_33 ) ;
if ( V_33 -> type == V_63 )
return F_28 ( V_2 ) ;
if ( V_33 -> V_50 & V_52 ) {
if ( V_33 -> type > V_93 ) {
return F_30 ( V_2 , 3 , 4 , 4 ) ;
}
else if ( V_33 -> type == V_94 || V_33 -> type == V_95 ) {
return F_30 ( V_2 , 18 , 3 , 2 ) ;
}
else if ( V_33 -> type == V_96 ) {
return F_30 ( V_2 , 131 , 3 , 2 ) ;
}
else if ( V_33 -> type == V_97 ) {
return F_30 ( V_2 , 2 , 2 , 2 ) ;
}
} else if ( V_33 -> V_50 & V_51 ) {
if ( V_33 -> type <= V_53 && V_33 -> type != V_98 ) {
return F_30 ( V_2 , 2 , 2 , 2 ) ;
}
}
return 0 ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_99 * V_100 = V_14 -> V_100 ;
V_33 -> V_101 = 4 ;
V_33 -> V_102 = 4 ;
V_33 -> V_103 = 0 ;
V_33 -> V_104 = 0 ;
if ( V_33 -> type == V_98 ) {
if ( V_100 -> V_105 -> V_106 . V_107 == 0 ) {
V_33 -> V_50 = V_108 ;
} else if ( V_100 -> V_105 -> V_106 . V_107 == 2 ) {
V_33 -> V_50 |= V_52 ;
V_33 -> V_109 = V_110 ;
}
}
F_26 ( V_2 , V_33 ) ;
}
static bool F_34 ( struct V_1 * V_2 ,
struct V_1 * V_111 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_32 * V_33 = & V_14 -> V_16 . V_33 ;
int V_112 = V_33 -> V_113 ;
int V_114 = V_33 -> V_115 ;
int V_116 , V_117 ;
if ( V_112 == 0 && V_114 == 0 ) {
V_112 = V_2 -> V_118 ;
V_114 = V_2 -> V_119 ;
}
if ( V_112 != V_111 -> V_118 || V_114 != V_111 -> V_119 )
return false ;
V_116 = strrchr ( V_2 -> V_120 , '.' ) - V_2 -> V_120 ;
V_117 = strrchr ( V_111 -> V_120 , '.' ) - V_111 -> V_120 ;
if ( V_116 != V_117 || V_116 <= 0 || V_117 <= 0 )
return false ;
return ! strncmp ( V_2 -> V_120 , V_111 -> V_120 , V_116 ) ;
}
static struct V_121 * F_35 ( struct V_1 * V_2 )
{
struct V_121 * V_17 ;
F_27 (data, &wacom_udev_list, list) {
if ( F_34 ( V_2 , V_17 -> V_19 ) ) {
F_36 ( & V_17 -> V_122 ) ;
return V_17 ;
}
}
return NULL ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_121 * V_17 ;
int V_6 = 0 ;
F_38 ( & V_123 ) ;
V_17 = F_35 ( V_2 ) ;
if ( ! V_17 ) {
V_17 = F_16 ( sizeof( struct V_121 ) , V_39 ) ;
if ( ! V_17 ) {
V_6 = - V_83 ;
goto V_124;
}
F_39 ( & V_17 -> V_122 ) ;
V_17 -> V_19 = V_2 ;
F_40 ( & V_17 -> V_125 , & V_126 ) ;
}
V_16 -> V_127 = & V_17 -> V_127 ;
if ( V_16 -> V_33 . V_50 & V_52 )
V_16 -> V_127 -> V_128 = V_2 ;
else if ( V_16 -> V_33 . V_50 & V_51 )
V_16 -> V_127 -> V_49 = V_2 ;
V_124:
F_41 ( & V_123 ) ;
return V_6 ;
}
static void F_42 ( struct V_122 * V_122 )
{
struct V_121 * V_17 =
F_43 ( V_122 , struct V_121 , V_122 ) ;
F_38 ( & V_123 ) ;
F_44 ( & V_17 -> V_125 ) ;
F_41 ( & V_123 ) ;
F_18 ( V_17 ) ;
}
static void F_45 ( struct V_14 * V_14 )
{
struct V_121 * V_17 ;
struct V_16 * V_16 = & V_14 -> V_16 ;
if ( V_16 -> V_127 ) {
V_17 = F_43 ( V_16 -> V_127 , struct V_121 ,
V_127 ) ;
if ( V_16 -> V_127 -> V_128 == V_14 -> V_2 )
V_16 -> V_127 -> V_128 = NULL ;
else if ( V_16 -> V_127 -> V_49 == V_14 -> V_2 )
V_16 -> V_127 -> V_49 = NULL ;
F_46 ( & V_17 -> V_122 , F_42 ) ;
V_16 -> V_127 = NULL ;
}
}
static int F_47 ( struct V_14 * V_14 )
{
unsigned char * V_3 ;
int V_6 ;
unsigned char V_79 = V_129 ;
int V_130 = 9 ;
if ( V_14 -> V_16 . V_114 ) {
V_79 = V_131 ;
V_130 = 13 ;
}
V_3 = F_16 ( V_130 , V_39 ) ;
if ( ! V_3 )
return - V_83 ;
if ( V_14 -> V_16 . V_33 . type >= V_132 &&
V_14 -> V_16 . V_33 . type <= V_133 ) {
int V_134 = V_14 -> V_135 . V_136 [ 0 ] & 0x03 ;
int V_137 = ( ( ( V_14 -> V_135 . V_138 & 0x60 ) >> 5 ) - 1 ) & 0x03 ;
int V_139 = 0 ;
unsigned char V_140 = ( V_139 << 4 ) | ( V_137 << 2 ) | ( V_134 ) ;
V_3 [ 0 ] = V_79 ;
if ( V_14 -> V_16 . V_114 ) {
F_1 ( V_14 -> V_2 , V_41 ,
V_3 , V_130 , V_42 ) ;
V_3 [ 0 ] = V_79 ;
V_3 [ 4 ] = V_140 ;
} else
V_3 [ 1 ] = V_140 ;
}
else {
int V_135 = V_14 -> V_135 . V_136 [ 0 ] | 0x4 ;
if ( V_14 -> V_16 . V_33 . type == V_141 ||
V_14 -> V_16 . V_33 . type == V_142 )
V_135 |= ( V_14 -> V_135 . V_136 [ 1 ] << 4 ) | 0x40 ;
V_3 [ 0 ] = V_79 ;
V_3 [ 1 ] = V_135 ;
V_3 [ 2 ] = V_14 -> V_135 . V_138 ;
V_3 [ 3 ] = V_14 -> V_135 . V_143 ;
V_3 [ 4 ] = V_14 -> V_135 . V_144 ;
}
V_6 = F_4 ( V_14 -> V_2 , V_41 , V_3 , V_130 ,
V_42 ) ;
F_18 ( V_3 ) ;
return V_6 ;
}
static int F_48 ( struct V_14 * V_14 , int V_145 , T_1 V_146 ,
const unsigned V_147 , const void * V_148 )
{
unsigned char * V_3 ;
int V_69 , V_6 ;
const unsigned V_149 = V_147 / 4 ;
V_3 = F_16 ( V_149 + 3 , V_39 ) ;
if ( ! V_3 )
return - V_83 ;
V_3 [ 0 ] = V_150 ;
V_3 [ 1 ] = 1 ;
V_6 = F_4 ( V_14 -> V_2 , V_41 , V_3 , 2 ,
V_42 ) ;
if ( V_6 < 0 )
goto V_124;
V_3 [ 0 ] = V_146 ;
V_3 [ 1 ] = V_145 & 0x07 ;
for ( V_69 = 0 ; V_69 < 4 ; V_69 ++ ) {
V_3 [ 2 ] = V_69 ;
memcpy ( V_3 + 3 , V_148 + V_69 * V_149 , V_149 ) ;
V_6 = F_4 ( V_14 -> V_2 , V_41 ,
V_3 , V_149 + 3 , V_42 ) ;
if ( V_6 < 0 )
break;
}
V_3 [ 0 ] = V_150 ;
V_3 [ 1 ] = 0 ;
F_4 ( V_14 -> V_2 , V_41 , V_3 , 2 ,
V_42 ) ;
V_124:
F_18 ( V_3 ) ;
return V_6 ;
}
static T_3 F_49 ( struct V_151 * V_19 , int V_152 ,
const char * V_3 , T_2 V_153 )
{
struct V_1 * V_2 = F_43 ( V_19 , struct V_1 , V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
unsigned int V_40 ;
int V_154 ;
V_154 = F_50 ( V_3 , 10 , & V_40 ) ;
if ( V_154 )
return V_154 ;
F_38 ( & V_14 -> V_155 ) ;
V_14 -> V_135 . V_136 [ V_152 ] = V_40 & 0x3 ;
V_154 = F_47 ( V_14 ) ;
F_41 ( & V_14 -> V_155 ) ;
return V_154 < 0 ? V_154 : V_153 ;
}
static T_3 F_51 ( struct V_14 * V_14 , T_1 * V_156 ,
const char * V_3 , T_2 V_153 )
{
unsigned int V_78 ;
int V_154 ;
V_154 = F_50 ( V_3 , 10 , & V_78 ) ;
if ( V_154 )
return V_154 ;
F_38 ( & V_14 -> V_155 ) ;
* V_156 = V_78 & 0x7f ;
V_154 = F_47 ( V_14 ) ;
F_41 ( & V_14 -> V_155 ) ;
return V_154 < 0 ? V_154 : V_153 ;
}
static T_3 F_52 ( struct V_151 * V_19 , int V_145 ,
const char * V_3 , T_2 V_153 )
{
struct V_1 * V_2 = F_43 ( V_19 , struct V_1 , V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
int V_154 ;
unsigned V_147 ;
T_1 V_146 ;
if ( V_2 -> V_91 == V_92 ) {
V_147 = 256 ;
V_146 = V_157 ;
} else {
V_147 = 1024 ;
V_146 = V_158 ;
}
if ( V_153 != V_147 )
return - V_159 ;
F_38 ( & V_14 -> V_155 ) ;
V_154 = F_48 ( V_14 , V_145 , V_146 , V_147 , V_3 ) ;
F_41 ( & V_14 -> V_155 ) ;
return V_154 < 0 ? V_154 : V_153 ;
}
static int F_53 ( struct V_14 * V_14 )
{
int error ;
if ( ! ( V_14 -> V_16 . V_33 . V_50 & V_160 ) )
return 0 ;
switch ( V_14 -> V_16 . V_33 . type ) {
case V_161 :
case V_162 :
case V_89 :
case V_163 :
V_14 -> V_135 . V_136 [ 0 ] = 0 ;
V_14 -> V_135 . V_136 [ 1 ] = 0 ;
V_14 -> V_135 . V_138 = 10 ;
V_14 -> V_135 . V_143 = 20 ;
V_14 -> V_135 . V_144 = 10 ;
error = F_54 ( & V_14 -> V_2 -> V_19 . V_164 ,
& V_165 ) ;
break;
case V_142 :
case V_141 :
V_14 -> V_135 . V_136 [ 0 ] = 0 ;
V_14 -> V_135 . V_136 [ 1 ] = 0 ;
V_14 -> V_135 . V_138 = 0 ;
V_14 -> V_135 . V_143 = 0 ;
V_14 -> V_135 . V_144 = 0 ;
error = F_54 ( & V_14 -> V_2 -> V_19 . V_164 ,
& V_166 ) ;
break;
case V_132 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_133 :
V_14 -> V_135 . V_136 [ 0 ] = 0 ;
V_14 -> V_135 . V_136 [ 1 ] = 0 ;
V_14 -> V_135 . V_138 = 32 ;
V_14 -> V_135 . V_143 = 0 ;
V_14 -> V_135 . V_144 = 0 ;
error = F_54 ( & V_14 -> V_2 -> V_19 . V_164 ,
& V_171 ) ;
break;
default:
return 0 ;
}
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_9 , error ) ;
return error ;
}
F_47 ( V_14 ) ;
V_14 -> V_172 = true ;
return 0 ;
}
static void F_55 ( struct V_14 * V_14 )
{
if ( ! V_14 -> V_172 )
return;
if ( ! ( V_14 -> V_16 . V_33 . V_50 & V_160 ) )
return;
V_14 -> V_172 = false ;
switch ( V_14 -> V_16 . V_33 . type ) {
case V_161 :
case V_162 :
case V_89 :
case V_163 :
F_56 ( & V_14 -> V_2 -> V_19 . V_164 ,
& V_165 ) ;
break;
case V_142 :
case V_141 :
F_56 ( & V_14 -> V_2 -> V_19 . V_164 ,
& V_166 ) ;
break;
case V_132 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_133 :
F_56 ( & V_14 -> V_2 -> V_19 . V_164 ,
& V_171 ) ;
break;
}
}
static int F_57 ( struct V_173 * V_174 ,
enum V_175 V_176 ,
union V_177 * V_178 )
{
struct V_14 * V_14 = F_58 ( V_174 ) ;
int V_35 = 0 ;
switch ( V_176 ) {
case V_179 :
V_178 -> V_180 = V_14 -> V_16 . V_181 ;
break;
case V_182 :
V_178 -> V_180 = V_183 ;
break;
case V_184 :
V_178 -> V_180 =
V_14 -> V_16 . V_185 ;
break;
case V_186 :
if ( V_14 -> V_16 . V_187 )
V_178 -> V_180 = V_188 ;
else if ( V_14 -> V_16 . V_185 == 100 &&
V_14 -> V_16 . V_189 )
V_178 -> V_180 = V_190 ;
else if ( V_14 -> V_16 . V_189 )
V_178 -> V_180 = V_191 ;
else
V_178 -> V_180 = V_192 ;
break;
default:
V_35 = - V_159 ;
break;
}
return V_35 ;
}
static int F_59 ( struct V_173 * V_174 ,
enum V_175 V_176 ,
union V_177 * V_178 )
{
struct V_14 * V_14 = F_58 ( V_174 ) ;
int V_35 = 0 ;
switch ( V_176 ) {
case V_179 :
case V_193 :
V_178 -> V_180 = V_14 -> V_16 . V_189 ;
break;
case V_182 :
V_178 -> V_180 = V_183 ;
break;
default:
V_35 = - V_159 ;
break;
}
return V_35 ;
}
static int F_60 ( struct V_14 * V_14 )
{
static T_4 V_194 = F_61 ( 0 ) ;
struct V_195 V_196 = { . V_197 = V_14 , } ;
unsigned long V_198 ;
if ( V_14 -> V_16 . V_33 . V_199 & V_200 ) {
struct V_201 * V_202 = & V_14 -> V_203 ;
struct V_201 * V_204 = & V_14 -> V_204 ;
V_198 = F_62 ( & V_194 ) - 1 ;
V_202 -> V_205 = V_206 ;
V_202 -> V_207 = F_63 ( V_206 ) ;
V_202 -> V_208 = F_57 ;
sprintf ( V_14 -> V_16 . V_209 , L_10 , V_198 ) ;
V_202 -> V_210 = V_14 -> V_16 . V_209 ;
V_202 -> type = V_211 ;
V_202 -> V_212 = 0 ;
V_204 -> V_205 = V_213 ;
V_204 -> V_207 = F_63 ( V_213 ) ;
V_204 -> V_208 = F_59 ;
sprintf ( V_14 -> V_16 . V_214 , L_11 , V_198 ) ;
V_204 -> V_210 = V_14 -> V_16 . V_214 ;
V_204 -> type = V_215 ;
V_204 -> V_212 = 0 ;
V_14 -> V_216 = F_64 ( & V_14 -> V_2 -> V_19 ,
& V_14 -> V_203 , & V_196 ) ;
if ( F_65 ( V_14 -> V_216 ) )
return F_66 ( V_14 -> V_216 ) ;
F_67 ( V_14 -> V_216 , & V_14 -> V_2 -> V_19 ) ;
V_14 -> V_217 = F_64 ( & V_14 -> V_2 -> V_19 ,
& V_14 -> V_204 ,
& V_196 ) ;
if ( F_65 ( V_14 -> V_217 ) ) {
F_68 ( V_14 -> V_216 ) ;
return F_66 ( V_14 -> V_217 ) ;
}
F_67 ( V_14 -> V_217 , & V_14 -> V_2 -> V_19 ) ;
}
return 0 ;
}
static void F_69 ( struct V_14 * V_14 )
{
if ( V_14 -> V_216 ) {
F_68 ( V_14 -> V_216 ) ;
V_14 -> V_216 = NULL ;
F_68 ( V_14 -> V_217 ) ;
V_14 -> V_217 = NULL ;
}
}
static T_3 F_70 ( struct V_151 * V_19 ,
struct V_218
* V_219 , char * V_3 )
{
struct V_1 * V_2 = F_43 ( V_19 , struct V_1 , V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
return snprintf ( V_3 , V_220 , L_12 , V_14 -> V_16 . V_88 ) ;
}
static T_3 F_71 ( struct V_151 * V_19 ,
struct V_218 * V_219 ,
const char * V_3 , T_2 V_153 )
{
struct V_1 * V_2 = F_43 ( V_19 , struct V_1 , V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
T_1 V_221 ;
if ( F_72 ( V_3 , 0 , & V_221 ) )
return - V_159 ;
if ( V_221 != 0 && V_221 != 1 )
return - V_159 ;
F_31 ( V_2 , V_221 , & V_14 -> V_16 . V_33 ) ;
return V_153 ;
}
static struct V_18 * F_73 ( struct V_14 * V_14 )
{
struct V_18 * V_18 ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
V_18 = F_74 () ;
if ( ! V_18 )
return NULL ;
V_18 -> V_210 = V_16 -> V_222 ;
V_18 -> V_120 = V_2 -> V_120 ;
V_18 -> V_19 . V_223 = & V_2 -> V_19 ;
V_18 -> V_224 = F_8 ;
V_18 -> V_225 = F_11 ;
V_18 -> V_226 = V_2 -> V_226 ;
V_18 -> V_40 . V_227 = V_2 -> V_91 ;
V_18 -> V_40 . V_118 = V_2 -> V_118 ;
V_18 -> V_40 . V_119 = V_16 -> V_114 ? V_16 -> V_114 : V_2 -> V_119 ;
V_18 -> V_40 . V_228 = V_2 -> V_228 ;
F_75 ( V_18 , V_14 ) ;
return V_18 ;
}
static void F_76 ( struct V_14 * V_14 )
{
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
if ( V_16 -> V_229 )
F_77 ( V_16 -> V_229 ) ;
if ( V_16 -> V_64 )
F_77 ( V_16 -> V_64 ) ;
if ( V_16 -> V_230 )
F_77 ( V_16 -> V_230 ) ;
V_16 -> V_229 = NULL ;
V_16 -> V_64 = NULL ;
V_16 -> V_230 = NULL ;
}
static int F_78 ( struct V_14 * V_14 )
{
struct V_18 * V_231 , * V_232 , * V_233 ;
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
V_231 = F_73 ( V_14 ) ;
V_232 = F_73 ( V_14 ) ;
V_233 = F_73 ( V_14 ) ;
if ( ! V_231 || ! V_232 || ! V_233 ) {
F_76 ( V_14 ) ;
return - V_83 ;
}
V_16 -> V_229 = V_231 ;
V_16 -> V_64 = V_232 ;
V_16 -> V_64 -> V_210 = V_16 -> V_234 ;
V_16 -> V_230 = V_233 ;
V_16 -> V_230 -> V_210 = V_16 -> V_235 ;
return 0 ;
}
static void F_79 ( struct V_14 * V_14 )
{
if ( V_14 -> V_16 . V_229 ) {
if ( V_14 -> V_16 . V_236 )
F_80 ( V_14 -> V_16 . V_229 ) ;
else
F_77 ( V_14 -> V_16 . V_229 ) ;
}
if ( V_14 -> V_16 . V_64 ) {
if ( V_14 -> V_16 . V_237 )
F_80 ( V_14 -> V_16 . V_64 ) ;
else
F_77 ( V_14 -> V_16 . V_64 ) ;
}
if ( V_14 -> V_16 . V_230 ) {
if ( V_14 -> V_16 . V_238 )
F_80 ( V_14 -> V_16 . V_230 ) ;
else
F_77 ( V_14 -> V_16 . V_230 ) ;
}
V_14 -> V_16 . V_229 = NULL ;
V_14 -> V_16 . V_64 = NULL ;
V_14 -> V_16 . V_230 = NULL ;
F_55 ( V_14 ) ;
}
static int F_81 ( struct V_14 * V_14 )
{
struct V_18 * V_231 , * V_232 , * V_233 ;
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
int error = 0 ;
V_231 = V_16 -> V_229 ;
V_232 = V_16 -> V_64 ;
V_233 = V_16 -> V_230 ;
if ( ! V_231 || ! V_232 || ! V_233 )
return - V_159 ;
error = F_82 ( V_231 , V_16 ) ;
if ( error ) {
F_77 ( V_231 ) ;
V_16 -> V_229 = NULL ;
V_231 = NULL ;
} else {
error = F_83 ( V_231 ) ;
if ( error )
goto V_239;
V_16 -> V_236 = true ;
}
error = F_84 ( V_232 , V_16 ) ;
if ( error ) {
F_77 ( V_232 ) ;
V_16 -> V_64 = NULL ;
V_232 = NULL ;
} else {
error = F_83 ( V_232 ) ;
if ( error )
goto V_240;
V_16 -> V_237 = true ;
}
error = F_85 ( V_233 , V_16 ) ;
if ( error ) {
F_77 ( V_233 ) ;
V_16 -> V_230 = NULL ;
V_233 = NULL ;
} else {
error = F_83 ( V_233 ) ;
if ( error )
goto V_241;
V_16 -> V_238 = true ;
error = F_53 ( V_14 ) ;
if ( error )
goto V_242;
}
return 0 ;
V_242:
F_80 ( V_233 ) ;
V_233 = NULL ;
V_16 -> V_238 = false ;
V_241:
if ( V_232 )
F_80 ( V_232 ) ;
V_16 -> V_64 = NULL ;
V_16 -> V_237 = false ;
V_240:
if ( V_231 )
F_80 ( V_231 ) ;
V_16 -> V_229 = NULL ;
V_16 -> V_236 = false ;
V_239:
return error ;
}
static void F_86 ( struct V_32 * V_33 )
{
if ( V_33 -> V_243 ) {
V_33 -> V_56 = ( V_33 -> V_55 * 100 ) /
V_33 -> V_243 ;
V_33 -> V_60 = ( V_33 -> V_59 * 100 ) /
V_33 -> V_244 ;
}
}
static void F_87 ( struct V_32 * V_33 )
{
if ( ! V_33 -> V_22 ) {
V_33 -> V_22 = 0x11 ;
V_33 -> V_57 = - 3 ;
}
V_33 -> V_243 = F_13 ( V_33 -> V_55 ,
V_33 -> V_56 ,
V_33 -> V_22 ,
V_33 -> V_57 ) ;
V_33 -> V_244 = F_13 ( V_33 -> V_59 ,
V_33 -> V_60 ,
V_33 -> V_22 ,
V_33 -> V_57 ) ;
}
static void F_88 ( struct V_245 * V_246 )
{
struct V_14 * V_14 = F_43 ( V_246 , struct V_14 , V_246 ) ;
struct V_247 * V_248 = V_14 -> V_248 ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_1 * V_249 , * V_250 ;
struct V_14 * V_251 , * V_252 ;
struct V_16 * V_253 , * V_254 ;
int error ;
F_69 ( V_14 ) ;
V_249 = F_89 ( V_248 -> V_255 -> V_256 [ 1 ] ) ;
V_251 = F_6 ( V_249 ) ;
V_253 = & ( V_251 -> V_16 ) ;
F_79 ( V_251 ) ;
V_250 = F_89 ( V_248 -> V_255 -> V_256 [ 2 ] ) ;
V_252 = F_6 ( V_250 ) ;
V_254 = & ( V_252 -> V_16 ) ;
F_79 ( V_252 ) ;
if ( V_16 -> V_114 == 0 ) {
F_90 ( V_14 -> V_2 , L_13 ) ;
V_253 -> V_127 -> type = 0 ;
} else {
const struct V_257 * V_40 = V_258 ;
F_90 ( V_14 -> V_2 , L_14 ,
V_16 -> V_114 ) ;
while ( V_40 -> V_91 ) {
if ( V_40 -> V_118 == V_259 &&
V_40 -> V_119 == V_16 -> V_114 )
break;
V_40 ++ ;
}
if ( ! V_40 -> V_91 ) {
F_90 ( V_14 -> V_2 , L_15 ) ;
return;
}
V_253 -> V_33 =
* ( (struct V_32 * ) V_40 -> V_260 ) ;
V_253 -> V_33 . V_50 |= V_51 ;
if ( V_253 -> V_33 . type != V_261 &&
V_253 -> V_33 . type != V_53 )
V_253 -> V_33 . V_50 |= V_160 ;
F_86 ( & V_253 -> V_33 ) ;
F_87 ( & V_253 -> V_33 ) ;
snprintf ( V_253 -> V_222 , V_262 , L_16 ,
V_253 -> V_33 . V_210 ) ;
snprintf ( V_253 -> V_235 , V_262 , L_17 ,
V_253 -> V_33 . V_210 ) ;
V_253 -> V_127 -> V_38 = V_253 -> V_33 . V_38 ;
V_253 -> V_127 -> type = V_253 -> V_33 . type ;
V_253 -> V_114 = V_16 -> V_114 ;
error = F_78 ( V_251 ) ||
F_81 ( V_251 ) ;
if ( error )
goto V_263;
if ( V_253 -> V_33 . V_38 ||
V_253 -> V_33 . type == V_261 ) {
V_254 -> V_33 =
* ( (struct V_32 * ) V_40 -> V_260 ) ;
V_254 -> V_33 . V_109 = V_110 ;
F_86 ( & V_254 -> V_33 ) ;
V_254 -> V_33 . V_55 = V_254 -> V_33 . V_59 = 4096 ;
F_87 ( & V_254 -> V_33 ) ;
snprintf ( V_254 -> V_234 , V_262 ,
L_18 , V_254 -> V_33 . V_210 ) ;
snprintf ( V_254 -> V_235 , V_262 ,
L_17 , V_254 -> V_33 . V_210 ) ;
if ( V_253 -> V_33 . V_38 )
V_254 -> V_33 . V_50 |= V_52 ;
if ( V_253 -> V_33 . type == V_261 ||
V_253 -> V_33 . type == V_53 )
V_254 -> V_33 . V_50 |= V_160 ;
V_254 -> V_114 = V_16 -> V_114 ;
error = F_78 ( V_252 ) ||
F_81 ( V_252 ) ;
if ( error )
goto V_263;
if ( V_253 -> V_33 . type == V_261 &&
V_253 -> V_33 . V_38 )
V_16 -> V_127 -> V_64 = V_254 -> V_64 ;
}
error = F_60 ( V_14 ) ;
if ( error )
goto V_263;
}
return;
V_263:
F_79 ( V_251 ) ;
F_79 ( V_252 ) ;
return;
}
void F_91 ( struct V_245 * V_246 )
{
struct V_14 * V_14 = F_43 ( V_246 , struct V_14 , V_246 ) ;
if ( ( V_14 -> V_16 . V_33 . V_199 & V_200 ) &&
! V_14 -> V_216 ) {
F_60 ( V_14 ) ;
}
else if ( ! ( V_14 -> V_16 . V_33 . V_199 & V_200 ) &&
V_14 -> V_216 ) {
F_69 ( V_14 ) ;
}
}
static T_2 F_92 ( struct V_1 * V_2 )
{
struct V_66 * V_71 ;
struct V_11 * V_12 ;
T_2 V_4 = 0 ;
V_71 = V_2 -> V_71 + V_74 ;
F_27 (report, &report_enum->report_list, list) {
T_2 V_264 = F_93 ( V_12 ) ;
if ( V_264 > V_4 )
V_4 = V_264 ;
}
return V_4 ;
}
static void F_94 ( struct V_14 * V_14 )
{
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_32 * V_33 = & V_16 -> V_33 ;
char V_210 [ V_262 ] ;
if ( ( V_33 -> type == V_63 ) && ! strcmp ( L_19 , V_33 -> V_210 ) ) {
if ( strstr ( V_14 -> V_2 -> V_210 , L_20 ) ||
strstr ( V_14 -> V_2 -> V_210 , L_21 ) ||
strstr ( V_14 -> V_2 -> V_210 , L_22 ) ) {
F_95 ( V_210 , V_14 -> V_2 -> V_210 , sizeof( V_210 ) ) ;
while ( 1 ) {
char * V_265 = strstr ( V_210 , L_23 ) ;
if ( V_265 == NULL )
break;
memmove ( V_265 , V_265 + 1 , strlen ( V_265 ) ) ;
}
if ( V_210 [ strlen ( V_210 ) - 1 ] == ' ' )
V_210 [ strlen ( V_210 ) - 1 ] = '\0' ;
} else {
snprintf ( V_210 , sizeof( V_210 ) ,
L_24 , V_33 -> V_210 , V_14 -> V_2 -> V_119 ) ;
}
} else {
F_95 ( V_210 , V_33 -> V_210 , sizeof( V_210 ) ) ;
}
snprintf ( V_16 -> V_222 , sizeof( V_16 -> V_222 ) ,
L_25 , V_210 ) ;
snprintf ( V_16 -> V_234 , sizeof( V_16 -> V_234 ) ,
L_26 , V_210 ) ;
snprintf ( V_16 -> V_235 , sizeof( V_16 -> V_235 ) ,
L_27 , V_210 ) ;
}
static int F_96 ( struct V_1 * V_2 ,
const struct V_257 * V_40 )
{
struct V_99 * V_100 = F_97 ( V_2 -> V_19 . V_223 ) ;
struct V_247 * V_19 = F_98 ( V_100 ) ;
struct V_14 * V_14 ;
struct V_16 * V_16 ;
struct V_32 * V_33 ;
int error ;
unsigned int V_266 = V_267 ;
if ( ! V_40 -> V_260 )
return - V_159 ;
V_2 -> V_199 |= V_268 ;
V_2 -> V_199 &= ~ V_269 ;
V_14 = F_16 ( sizeof( struct V_14 ) , V_39 ) ;
if ( ! V_14 )
return - V_83 ;
F_99 ( V_2 , V_14 ) ;
V_14 -> V_2 = V_2 ;
error = F_100 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_28 ) ;
goto V_270;
}
V_16 = & V_14 -> V_16 ;
V_16 -> V_33 = * ( (struct V_32 * ) V_40 -> V_260 ) ;
V_33 = & V_16 -> V_33 ;
V_33 -> V_109 = F_92 ( V_2 ) ;
if ( V_33 -> V_109 > V_15 ) {
error = - V_159 ;
goto V_271;
}
if ( V_33 -> V_272 && V_33 -> V_273 != V_2 -> type ) {
error = - V_274 ;
goto V_275;
}
V_14 -> V_248 = V_19 ;
V_14 -> V_100 = V_100 ;
F_101 ( & V_14 -> V_155 ) ;
F_102 ( & V_14 -> V_246 , F_88 ) ;
if ( ! ( V_33 -> V_199 & V_276 ) ) {
error = F_78 ( V_14 ) ;
if ( error )
goto V_277;
}
if ( V_33 -> type == V_97 ) {
if ( V_33 -> V_109 == V_278 ) {
V_33 -> type = V_63 ;
} else if ( ( V_33 -> V_109 != V_279 ) &&
( V_33 -> V_109 != V_280 ) ) {
error = - V_274 ;
goto V_281;
}
}
F_86 ( V_33 ) ;
F_33 ( V_2 , V_33 ) ;
F_103 ( V_14 ) ;
if ( V_33 -> V_50 == V_108 &&
V_33 -> type != V_98 ) {
error = V_33 -> type == V_63 ? - V_274 : 0 ;
F_104 ( & V_2 -> V_19 , L_29 ,
V_2 -> V_210 ,
error ? L_30 : L_31 ) ;
if ( error )
goto V_281;
V_33 -> V_50 |= V_51 ;
}
F_87 ( V_33 ) ;
F_94 ( V_14 ) ;
error = F_37 ( V_2 ) ;
if ( error )
goto V_281;
if ( ! ( V_33 -> V_199 & V_282 ) &&
( V_33 -> V_199 & V_200 ) ) {
error = F_60 ( V_14 ) ;
if ( error )
goto V_283;
}
if ( ! ( V_33 -> V_199 & V_276 ) ) {
error = F_81 ( V_14 ) ;
if ( error )
goto V_284;
}
if ( V_2 -> V_91 == V_92 ) {
error = F_105 ( & V_2 -> V_19 , & V_285 ) ;
if ( error )
F_17 ( V_2 ,
L_32 ,
error ) ;
}
if ( V_33 -> type == V_63 )
V_266 |= V_286 ;
error = F_106 ( V_2 , V_266 ) ;
if ( error ) {
F_3 ( V_2 , L_33 ) ;
goto V_287;
}
F_32 ( V_2 , V_33 ) ;
if ( V_33 -> V_199 & V_282 )
error = F_10 ( V_2 ) ;
if ( V_16 -> V_33 . type == V_261 &&
V_16 -> V_33 . V_50 & V_52 ) {
V_16 -> V_127 -> V_64 = V_16 -> V_64 ;
}
return 0 ;
V_287:
if ( V_2 -> V_91 == V_92 )
F_107 ( & V_2 -> V_19 , & V_285 ) ;
V_284:
F_79 ( V_14 ) ;
F_69 ( V_14 ) ;
V_283:
F_45 ( V_14 ) ;
V_281:
F_79 ( V_14 ) ;
V_277:
V_275:
V_271:
V_270:
F_18 ( V_14 ) ;
F_99 ( V_2 , NULL ) ;
return error ;
}
static void F_108 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
F_109 ( V_2 ) ;
F_110 ( & V_14 -> V_246 ) ;
F_79 ( V_14 ) ;
if ( V_2 -> V_91 == V_92 )
F_107 ( & V_2 -> V_19 , & V_285 ) ;
F_69 ( V_14 ) ;
F_45 ( V_14 ) ;
F_99 ( V_2 , NULL ) ;
F_18 ( V_14 ) ;
}
static int F_111 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_32 * V_33 = & V_14 -> V_16 . V_33 ;
F_38 ( & V_14 -> V_155 ) ;
F_32 ( V_2 , V_33 ) ;
F_47 ( V_14 ) ;
F_41 ( & V_14 -> V_155 ) ;
return 0 ;
}
static int F_112 ( struct V_1 * V_2 )
{
return F_111 ( V_2 ) ;
}
