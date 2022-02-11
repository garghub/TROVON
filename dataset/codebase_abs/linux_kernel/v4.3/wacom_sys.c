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
} while ( error >= 0 && V_82 [ 1 ] != V_81 && V_84 ++ < V_85 );
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
if ( V_100 -> V_105 -> V_106 . V_107 == 0 )
V_33 -> V_50 = V_108 ;
else
V_33 -> V_50 = V_109 ;
return;
}
F_26 ( V_2 , V_33 ) ;
}
static bool F_34 ( struct V_1 * V_2 ,
struct V_1 * V_110 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_32 * V_33 = & V_14 -> V_16 . V_33 ;
int V_111 = V_33 -> V_112 ;
int V_113 = V_33 -> V_114 ;
int V_115 , V_116 ;
if ( V_111 == 0 && V_113 == 0 ) {
V_111 = V_2 -> V_117 ;
V_113 = V_2 -> V_118 ;
}
if ( V_111 != V_110 -> V_117 || V_113 != V_110 -> V_118 )
return false ;
V_115 = strrchr ( V_2 -> V_119 , '.' ) - V_2 -> V_119 ;
V_116 = strrchr ( V_110 -> V_119 , '.' ) - V_110 -> V_119 ;
if ( V_115 != V_116 || V_115 <= 0 || V_116 <= 0 )
return false ;
return ! strncmp ( V_2 -> V_119 , V_110 -> V_119 , V_115 ) ;
}
static struct V_120 * F_35 ( struct V_1 * V_2 )
{
struct V_120 * V_17 ;
F_27 (data, &wacom_udev_list, list) {
if ( F_34 ( V_2 , V_17 -> V_19 ) ) {
F_36 ( & V_17 -> V_121 ) ;
return V_17 ;
}
}
return NULL ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_120 * V_17 ;
int V_6 = 0 ;
F_38 ( & V_122 ) ;
V_17 = F_35 ( V_2 ) ;
if ( ! V_17 ) {
V_17 = F_16 ( sizeof( struct V_120 ) , V_39 ) ;
if ( ! V_17 ) {
V_6 = - V_83 ;
goto V_123;
}
F_39 ( & V_17 -> V_121 ) ;
V_17 -> V_19 = V_2 ;
F_40 ( & V_17 -> V_124 , & V_125 ) ;
}
V_16 -> V_126 = & V_17 -> V_126 ;
if ( V_16 -> V_33 . V_50 & V_52 )
V_16 -> V_126 -> V_127 = V_2 ;
else if ( V_16 -> V_33 . V_50 & V_51 )
V_16 -> V_126 -> V_49 = V_2 ;
V_123:
F_41 ( & V_122 ) ;
return V_6 ;
}
static void F_42 ( struct V_121 * V_121 )
{
struct V_120 * V_17 =
F_43 ( V_121 , struct V_120 , V_121 ) ;
F_38 ( & V_122 ) ;
F_44 ( & V_17 -> V_124 ) ;
F_41 ( & V_122 ) ;
F_18 ( V_17 ) ;
}
static void F_45 ( struct V_14 * V_14 )
{
struct V_120 * V_17 ;
struct V_16 * V_16 = & V_14 -> V_16 ;
if ( V_16 -> V_126 ) {
V_17 = F_43 ( V_16 -> V_126 , struct V_120 ,
V_126 ) ;
if ( V_16 -> V_126 -> V_127 == V_14 -> V_2 )
V_16 -> V_126 -> V_127 = NULL ;
else if ( V_16 -> V_126 -> V_49 == V_14 -> V_2 )
V_16 -> V_126 -> V_49 = NULL ;
F_46 ( & V_17 -> V_121 , F_42 ) ;
V_16 -> V_126 = NULL ;
}
}
static int F_47 ( struct V_14 * V_14 )
{
unsigned char * V_3 ;
int V_6 ;
unsigned char V_79 = V_128 ;
int V_129 = 9 ;
if ( V_14 -> V_16 . V_113 ) {
V_79 = V_130 ;
V_129 = 13 ;
}
V_3 = F_16 ( V_129 , V_39 ) ;
if ( ! V_3 )
return - V_83 ;
if ( V_14 -> V_16 . V_33 . type >= V_131 &&
V_14 -> V_16 . V_33 . type <= V_132 ) {
int V_133 = V_14 -> V_134 . V_135 [ 0 ] & 0x03 ;
int V_136 = ( ( ( V_14 -> V_134 . V_137 & 0x60 ) >> 5 ) - 1 ) & 0x03 ;
int V_138 = 0 ;
unsigned char V_139 = ( V_138 << 4 ) | ( V_136 << 2 ) | ( V_133 ) ;
V_3 [ 0 ] = V_79 ;
if ( V_14 -> V_16 . V_113 ) {
F_1 ( V_14 -> V_2 , V_41 ,
V_3 , V_129 , V_42 ) ;
V_3 [ 0 ] = V_79 ;
V_3 [ 4 ] = V_139 ;
} else
V_3 [ 1 ] = V_139 ;
}
else {
int V_134 = V_14 -> V_134 . V_135 [ 0 ] | 0x4 ;
if ( V_14 -> V_16 . V_33 . type == V_140 ||
V_14 -> V_16 . V_33 . type == V_141 )
V_134 |= ( V_14 -> V_134 . V_135 [ 1 ] << 4 ) | 0x40 ;
V_3 [ 0 ] = V_79 ;
V_3 [ 1 ] = V_134 ;
V_3 [ 2 ] = V_14 -> V_134 . V_137 ;
V_3 [ 3 ] = V_14 -> V_134 . V_142 ;
V_3 [ 4 ] = V_14 -> V_134 . V_143 ;
}
V_6 = F_4 ( V_14 -> V_2 , V_41 , V_3 , V_129 ,
V_42 ) ;
F_18 ( V_3 ) ;
return V_6 ;
}
static int F_48 ( struct V_14 * V_14 , int V_144 , T_1 V_145 ,
const unsigned V_146 , const void * V_147 )
{
unsigned char * V_3 ;
int V_69 , V_6 ;
const unsigned V_148 = V_146 / 4 ;
V_3 = F_16 ( V_148 + 3 , V_39 ) ;
if ( ! V_3 )
return - V_83 ;
V_3 [ 0 ] = V_149 ;
V_3 [ 1 ] = 1 ;
V_6 = F_4 ( V_14 -> V_2 , V_41 , V_3 , 2 ,
V_42 ) ;
if ( V_6 < 0 )
goto V_123;
V_3 [ 0 ] = V_145 ;
V_3 [ 1 ] = V_144 & 0x07 ;
for ( V_69 = 0 ; V_69 < 4 ; V_69 ++ ) {
V_3 [ 2 ] = V_69 ;
memcpy ( V_3 + 3 , V_147 + V_69 * V_148 , V_148 ) ;
V_6 = F_4 ( V_14 -> V_2 , V_41 ,
V_3 , V_148 + 3 , V_42 ) ;
if ( V_6 < 0 )
break;
}
V_3 [ 0 ] = V_149 ;
V_3 [ 1 ] = 0 ;
F_4 ( V_14 -> V_2 , V_41 , V_3 , 2 ,
V_42 ) ;
V_123:
F_18 ( V_3 ) ;
return V_6 ;
}
static T_3 F_49 ( struct V_150 * V_19 , int V_151 ,
const char * V_3 , T_2 V_152 )
{
struct V_1 * V_2 = F_43 ( V_19 , struct V_1 , V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
unsigned int V_40 ;
int V_153 ;
V_153 = F_50 ( V_3 , 10 , & V_40 ) ;
if ( V_153 )
return V_153 ;
F_38 ( & V_14 -> V_154 ) ;
V_14 -> V_134 . V_135 [ V_151 ] = V_40 & 0x3 ;
V_153 = F_47 ( V_14 ) ;
F_41 ( & V_14 -> V_154 ) ;
return V_153 < 0 ? V_153 : V_152 ;
}
static T_3 F_51 ( struct V_14 * V_14 , T_1 * V_155 ,
const char * V_3 , T_2 V_152 )
{
unsigned int V_78 ;
int V_153 ;
V_153 = F_50 ( V_3 , 10 , & V_78 ) ;
if ( V_153 )
return V_153 ;
F_38 ( & V_14 -> V_154 ) ;
* V_155 = V_78 & 0x7f ;
V_153 = F_47 ( V_14 ) ;
F_41 ( & V_14 -> V_154 ) ;
return V_153 < 0 ? V_153 : V_152 ;
}
static T_3 F_52 ( struct V_150 * V_19 , int V_144 ,
const char * V_3 , T_2 V_152 )
{
struct V_1 * V_2 = F_43 ( V_19 , struct V_1 , V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
int V_153 ;
unsigned V_146 ;
T_1 V_145 ;
if ( V_2 -> V_91 == V_92 ) {
V_146 = 256 ;
V_145 = V_156 ;
} else {
V_146 = 1024 ;
V_145 = V_157 ;
}
if ( V_152 != V_146 )
return - V_158 ;
F_38 ( & V_14 -> V_154 ) ;
V_153 = F_48 ( V_14 , V_144 , V_145 , V_146 , V_3 ) ;
F_41 ( & V_14 -> V_154 ) ;
return V_153 < 0 ? V_153 : V_152 ;
}
static int F_53 ( struct V_14 * V_14 )
{
int error ;
if ( ! ( V_14 -> V_16 . V_33 . V_50 & V_159 ) )
return 0 ;
switch ( V_14 -> V_16 . V_33 . type ) {
case V_160 :
case V_161 :
case V_89 :
case V_162 :
V_14 -> V_134 . V_135 [ 0 ] = 0 ;
V_14 -> V_134 . V_135 [ 1 ] = 0 ;
V_14 -> V_134 . V_137 = 10 ;
V_14 -> V_134 . V_142 = 20 ;
V_14 -> V_134 . V_143 = 10 ;
error = F_54 ( & V_14 -> V_2 -> V_19 . V_163 ,
& V_164 ) ;
break;
case V_141 :
case V_140 :
V_14 -> V_134 . V_135 [ 0 ] = 0 ;
V_14 -> V_134 . V_135 [ 1 ] = 0 ;
V_14 -> V_134 . V_137 = 0 ;
V_14 -> V_134 . V_142 = 0 ;
V_14 -> V_134 . V_143 = 0 ;
error = F_54 ( & V_14 -> V_2 -> V_19 . V_163 ,
& V_165 ) ;
break;
case V_131 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_132 :
V_14 -> V_134 . V_135 [ 0 ] = 0 ;
V_14 -> V_134 . V_135 [ 1 ] = 0 ;
V_14 -> V_134 . V_137 = 32 ;
V_14 -> V_134 . V_142 = 0 ;
V_14 -> V_134 . V_143 = 0 ;
error = F_54 ( & V_14 -> V_2 -> V_19 . V_163 ,
& V_170 ) ;
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
V_14 -> V_171 = true ;
return 0 ;
}
static void F_55 ( struct V_14 * V_14 )
{
if ( ! V_14 -> V_171 )
return;
if ( ! ( V_14 -> V_16 . V_33 . V_50 & V_159 ) )
return;
V_14 -> V_171 = false ;
switch ( V_14 -> V_16 . V_33 . type ) {
case V_160 :
case V_161 :
case V_89 :
case V_162 :
F_56 ( & V_14 -> V_2 -> V_19 . V_163 ,
& V_164 ) ;
break;
case V_141 :
case V_140 :
F_56 ( & V_14 -> V_2 -> V_19 . V_163 ,
& V_165 ) ;
break;
case V_131 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_132 :
F_56 ( & V_14 -> V_2 -> V_19 . V_163 ,
& V_170 ) ;
break;
}
}
static int F_57 ( struct V_172 * V_173 ,
enum V_174 V_175 ,
union V_176 * V_177 )
{
struct V_14 * V_14 = F_58 ( V_173 ) ;
int V_35 = 0 ;
switch ( V_175 ) {
case V_178 :
V_177 -> V_179 = V_14 -> V_16 . V_180 ;
break;
case V_181 :
V_177 -> V_179 = V_182 ;
break;
case V_183 :
V_177 -> V_179 =
V_14 -> V_16 . V_184 ;
break;
case V_185 :
if ( V_14 -> V_16 . V_186 )
V_177 -> V_179 = V_187 ;
else if ( V_14 -> V_16 . V_184 == 100 &&
V_14 -> V_16 . V_188 )
V_177 -> V_179 = V_189 ;
else if ( V_14 -> V_16 . V_188 )
V_177 -> V_179 = V_190 ;
else
V_177 -> V_179 = V_191 ;
break;
default:
V_35 = - V_158 ;
break;
}
return V_35 ;
}
static int F_59 ( struct V_172 * V_173 ,
enum V_174 V_175 ,
union V_176 * V_177 )
{
struct V_14 * V_14 = F_58 ( V_173 ) ;
int V_35 = 0 ;
switch ( V_175 ) {
case V_178 :
case V_192 :
V_177 -> V_179 = V_14 -> V_16 . V_188 ;
break;
case V_181 :
V_177 -> V_179 = V_182 ;
break;
default:
V_35 = - V_158 ;
break;
}
return V_35 ;
}
static int F_60 ( struct V_14 * V_14 )
{
static T_4 V_193 = F_61 ( 0 ) ;
struct V_194 V_195 = { . V_196 = V_14 , } ;
unsigned long V_197 ;
if ( V_14 -> V_16 . V_33 . V_198 & V_199 ) {
struct V_200 * V_201 = & V_14 -> V_202 ;
struct V_200 * V_203 = & V_14 -> V_203 ;
V_197 = F_62 ( & V_193 ) - 1 ;
V_201 -> V_204 = V_205 ;
V_201 -> V_206 = F_63 ( V_205 ) ;
V_201 -> V_207 = F_57 ;
sprintf ( V_14 -> V_16 . V_208 , L_10 , V_197 ) ;
V_201 -> V_209 = V_14 -> V_16 . V_208 ;
V_201 -> type = V_210 ;
V_201 -> V_211 = 0 ;
V_203 -> V_204 = V_212 ;
V_203 -> V_206 = F_63 ( V_212 ) ;
V_203 -> V_207 = F_59 ;
sprintf ( V_14 -> V_16 . V_213 , L_11 , V_197 ) ;
V_203 -> V_209 = V_14 -> V_16 . V_213 ;
V_203 -> type = V_214 ;
V_203 -> V_211 = 0 ;
V_14 -> V_215 = F_64 ( & V_14 -> V_2 -> V_19 ,
& V_14 -> V_202 , & V_195 ) ;
if ( F_65 ( V_14 -> V_215 ) )
return F_66 ( V_14 -> V_215 ) ;
F_67 ( V_14 -> V_215 , & V_14 -> V_2 -> V_19 ) ;
V_14 -> V_216 = F_64 ( & V_14 -> V_2 -> V_19 ,
& V_14 -> V_203 ,
& V_195 ) ;
if ( F_65 ( V_14 -> V_216 ) ) {
F_68 ( V_14 -> V_215 ) ;
return F_66 ( V_14 -> V_216 ) ;
}
F_67 ( V_14 -> V_216 , & V_14 -> V_2 -> V_19 ) ;
}
return 0 ;
}
static void F_69 ( struct V_14 * V_14 )
{
if ( V_14 -> V_215 ) {
F_68 ( V_14 -> V_215 ) ;
V_14 -> V_215 = NULL ;
F_68 ( V_14 -> V_216 ) ;
V_14 -> V_216 = NULL ;
}
}
static T_3 F_70 ( struct V_150 * V_19 ,
struct V_217
* V_218 , char * V_3 )
{
struct V_1 * V_2 = F_43 ( V_19 , struct V_1 , V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
return snprintf ( V_3 , V_219 , L_12 , V_14 -> V_16 . V_88 ) ;
}
static T_3 F_71 ( struct V_150 * V_19 ,
struct V_217 * V_218 ,
const char * V_3 , T_2 V_152 )
{
struct V_1 * V_2 = F_43 ( V_19 , struct V_1 , V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
T_1 V_220 ;
if ( F_72 ( V_3 , 0 , & V_220 ) )
return - V_158 ;
if ( V_220 != 0 && V_220 != 1 )
return - V_158 ;
F_31 ( V_2 , V_220 , & V_14 -> V_16 . V_33 ) ;
return V_152 ;
}
static T_3 F_73 ( struct V_221 * V_163 ,
struct V_222 * V_223 ,
char * V_3 , int V_224 )
{
struct V_150 * V_19 = F_43 ( V_163 -> V_225 , struct V_150 , V_163 ) ;
struct V_1 * V_2 = F_43 ( V_19 , struct V_1 , V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
T_1 V_81 ;
V_81 = V_14 -> V_134 . V_135 [ V_224 ] ;
if ( V_81 >= 0 && V_81 < 3 )
return snprintf ( V_3 , V_219 , L_13 , V_81 ) ;
else
return snprintf ( V_3 , V_219 , L_13 , - 1 ) ;
}
int F_74 ( struct V_14 * V_14 , T_5 V_226 , int V_224 )
{
int error = 0 ;
char * V_3 ;
struct V_16 * V_16 = & V_14 -> V_16 ;
V_16 -> V_226 [ V_224 ] = V_226 ;
V_3 = F_16 ( V_227 , V_39 ) ;
if ( ! V_3 )
return - V_83 ;
snprintf ( V_3 , V_227 , L_14 , V_226 ) ;
V_14 -> V_228 [ V_224 ] . V_209 = V_3 ;
error = F_54 ( V_14 -> V_229 ,
& V_14 -> V_228 [ V_224 ] ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_9 , error ) ;
F_75 ( V_14 -> V_229 ) ;
return error ;
}
return 0 ;
}
void F_76 ( struct V_14 * V_14 , T_5 V_226 )
{
struct V_16 * V_16 = & V_14 -> V_16 ;
int V_69 ;
if ( ! V_226 )
return;
for ( V_69 = 0 ; V_69 < V_230 ; V_69 ++ ) {
if ( V_16 -> V_226 [ V_69 ] == V_226 ) {
V_16 -> V_226 [ V_69 ] = 0 ;
V_14 -> V_134 . V_135 [ V_69 ] = V_231 ;
if ( V_14 -> V_228 [ V_69 ] . V_209 ) {
F_56 ( V_14 -> V_229 ,
& V_14 -> V_228 [ V_69 ] ) ;
F_18 ( V_14 -> V_228 [ V_69 ] . V_209 ) ;
V_14 -> V_228 [ V_69 ] . V_209 = NULL ;
}
}
}
}
static int F_77 ( struct V_14 * V_14 , unsigned char V_232 )
{
const T_2 V_129 = 2 ;
unsigned char * V_3 ;
int V_6 ;
V_3 = F_16 ( V_129 , V_39 ) ;
if ( ! V_3 )
return - V_83 ;
V_3 [ 0 ] = V_233 ;
V_3 [ 1 ] = V_232 ;
V_6 = F_4 ( V_14 -> V_2 , V_234 , V_3 ,
V_129 , V_42 ) ;
F_18 ( V_3 ) ;
return V_6 ;
}
static T_3 F_78 ( struct V_221 * V_163 ,
struct V_222 * V_218 ,
const char * V_3 , T_2 V_152 )
{
unsigned char V_232 = 0 ;
struct V_150 * V_19 = F_43 ( V_163 -> V_225 , struct V_150 , V_163 ) ;
struct V_1 * V_2 = F_43 ( V_19 , struct V_1 , V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
int V_153 ;
if ( ! strncmp ( V_3 , L_15 , 2 ) ) {
V_232 = V_235 ;
} else {
F_79 ( V_14 -> V_2 , L_16 ,
V_3 ) ;
return - 1 ;
}
F_38 ( & V_14 -> V_154 ) ;
V_153 = F_77 ( V_14 , V_232 ) ;
F_41 ( & V_14 -> V_154 ) ;
return V_153 < 0 ? V_153 : V_152 ;
}
static int F_80 ( struct V_14 * V_14 )
{
int error = 0 ;
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
int V_69 ;
if ( V_14 -> V_16 . V_33 . type != V_236 )
return 0 ;
V_14 -> V_228 [ 0 ] = V_237 ;
V_14 -> V_228 [ 1 ] = V_238 ;
V_14 -> V_228 [ 2 ] = V_239 ;
V_14 -> V_228 [ 3 ] = V_240 ;
V_14 -> V_228 [ 4 ] = V_241 ;
V_14 -> V_229 = F_81 ( L_17 ,
& V_14 -> V_2 -> V_19 . V_163 ) ;
if ( ! V_14 -> V_229 )
return - V_83 ;
error = F_82 ( V_14 -> V_229 , V_242 ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_9 , error ) ;
return error ;
}
for ( V_69 = 0 ; V_69 < V_230 ; V_69 ++ ) {
V_14 -> V_134 . V_135 [ V_69 ] = V_231 ;
V_16 -> V_226 [ V_69 ] = 0 ;
}
return 0 ;
}
static struct V_18 * F_83 ( struct V_14 * V_14 )
{
struct V_18 * V_18 ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
V_18 = F_84 () ;
if ( ! V_18 )
return NULL ;
V_18 -> V_209 = V_16 -> V_33 . V_209 ;
V_18 -> V_119 = V_2 -> V_119 ;
V_18 -> V_19 . V_225 = & V_2 -> V_19 ;
V_18 -> V_243 = F_8 ;
V_18 -> V_244 = F_11 ;
V_18 -> V_245 = V_2 -> V_245 ;
V_18 -> V_40 . V_246 = V_2 -> V_91 ;
V_18 -> V_40 . V_117 = V_2 -> V_117 ;
V_18 -> V_40 . V_118 = V_16 -> V_113 ? V_16 -> V_113 : V_2 -> V_118 ;
V_18 -> V_40 . V_247 = V_2 -> V_247 ;
F_85 ( V_18 , V_14 ) ;
return V_18 ;
}
static void F_86 ( struct V_14 * V_14 )
{
if ( V_14 -> V_16 . V_248 ) {
if ( V_14 -> V_16 . V_249 )
F_87 ( V_14 -> V_16 . V_248 ) ;
else
F_88 ( V_14 -> V_16 . V_248 ) ;
}
if ( V_14 -> V_16 . V_64 ) {
if ( V_14 -> V_16 . V_250 )
F_87 ( V_14 -> V_16 . V_64 ) ;
else
F_88 ( V_14 -> V_16 . V_64 ) ;
}
if ( V_14 -> V_16 . V_251 ) {
if ( V_14 -> V_16 . V_252 )
F_87 ( V_14 -> V_16 . V_251 ) ;
else
F_88 ( V_14 -> V_16 . V_251 ) ;
}
if ( V_14 -> V_229 )
F_75 ( V_14 -> V_229 ) ;
V_14 -> V_16 . V_248 = NULL ;
V_14 -> V_16 . V_64 = NULL ;
V_14 -> V_16 . V_251 = NULL ;
F_55 ( V_14 ) ;
}
static int F_89 ( struct V_14 * V_14 )
{
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
V_16 -> V_248 = F_83 ( V_14 ) ;
V_16 -> V_64 = F_83 ( V_14 ) ;
V_16 -> V_251 = F_83 ( V_14 ) ;
if ( ! V_16 -> V_248 || ! V_16 -> V_64 || ! V_16 -> V_251 ) {
F_86 ( V_14 ) ;
return - V_83 ;
}
V_16 -> V_248 -> V_209 = V_16 -> V_253 ;
V_16 -> V_64 -> V_209 = V_16 -> V_254 ;
V_16 -> V_251 -> V_209 = V_16 -> V_255 ;
return 0 ;
}
static int F_90 ( struct V_14 * V_14 )
{
struct V_18 * V_256 , * V_257 , * V_258 ;
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
int error = 0 ;
V_256 = V_16 -> V_248 ;
V_257 = V_16 -> V_64 ;
V_258 = V_16 -> V_251 ;
if ( ! V_256 || ! V_257 || ! V_258 )
return - V_158 ;
error = F_91 ( V_256 , V_16 ) ;
if ( error ) {
F_88 ( V_256 ) ;
V_16 -> V_248 = NULL ;
V_256 = NULL ;
} else {
error = F_92 ( V_256 ) ;
if ( error )
goto V_259;
V_16 -> V_249 = true ;
}
error = F_93 ( V_257 , V_16 ) ;
if ( error ) {
F_88 ( V_257 ) ;
V_16 -> V_64 = NULL ;
V_257 = NULL ;
} else {
error = F_92 ( V_257 ) ;
if ( error )
goto V_260;
V_16 -> V_250 = true ;
}
error = F_94 ( V_258 , V_16 ) ;
if ( error ) {
F_88 ( V_258 ) ;
V_16 -> V_251 = NULL ;
V_258 = NULL ;
} else {
error = F_92 ( V_258 ) ;
if ( error )
goto V_261;
V_16 -> V_252 = true ;
error = F_53 ( V_14 ) ;
if ( error )
goto V_262;
error = F_80 ( V_14 ) ;
if ( error )
goto V_263;
}
return 0 ;
V_263:
F_55 ( V_14 ) ;
V_262:
F_87 ( V_258 ) ;
V_258 = NULL ;
V_16 -> V_252 = false ;
V_261:
if ( V_257 )
F_87 ( V_257 ) ;
V_16 -> V_64 = NULL ;
V_16 -> V_250 = false ;
V_260:
if ( V_256 )
F_87 ( V_256 ) ;
V_16 -> V_248 = NULL ;
V_16 -> V_249 = false ;
V_259:
return error ;
}
static void F_95 ( struct V_32 * V_33 )
{
if ( V_33 -> V_264 ) {
V_33 -> V_56 = ( V_33 -> V_55 * 100 ) /
V_33 -> V_264 ;
V_33 -> V_60 = ( V_33 -> V_59 * 100 ) /
V_33 -> V_265 ;
}
}
static void F_96 ( struct V_32 * V_33 )
{
if ( ! V_33 -> V_22 ) {
V_33 -> V_22 = 0x11 ;
V_33 -> V_57 = - 3 ;
}
V_33 -> V_264 = F_13 ( V_33 -> V_55 ,
V_33 -> V_56 ,
V_33 -> V_22 ,
V_33 -> V_57 ) ;
V_33 -> V_265 = F_13 ( V_33 -> V_59 ,
V_33 -> V_60 ,
V_33 -> V_22 ,
V_33 -> V_57 ) ;
}
static void F_97 ( struct V_266 * V_267 )
{
struct V_14 * V_14 = F_43 ( V_267 , struct V_14 , V_267 ) ;
struct V_268 * V_269 = V_14 -> V_269 ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_1 * V_270 , * V_271 ;
struct V_14 * V_272 , * V_273 ;
struct V_16 * V_274 , * V_275 ;
int error ;
F_69 ( V_14 ) ;
V_270 = F_98 ( V_269 -> V_276 -> V_277 [ 1 ] ) ;
V_272 = F_6 ( V_270 ) ;
V_274 = & ( V_272 -> V_16 ) ;
F_86 ( V_272 ) ;
V_271 = F_98 ( V_269 -> V_276 -> V_277 [ 2 ] ) ;
V_273 = F_6 ( V_271 ) ;
V_275 = & ( V_273 -> V_16 ) ;
F_86 ( V_273 ) ;
if ( V_16 -> V_113 == 0 ) {
F_79 ( V_14 -> V_2 , L_18 ) ;
V_274 -> V_126 -> type = 0 ;
} else {
const struct V_278 * V_40 = V_279 ;
F_79 ( V_14 -> V_2 , L_19 ,
V_16 -> V_113 ) ;
while ( V_40 -> V_91 ) {
if ( V_40 -> V_117 == V_280 &&
V_40 -> V_118 == V_16 -> V_113 )
break;
V_40 ++ ;
}
if ( ! V_40 -> V_91 ) {
F_79 ( V_14 -> V_2 , L_20 ) ;
return;
}
V_274 -> V_33 =
* ( (struct V_32 * ) V_40 -> V_281 ) ;
V_274 -> V_33 . V_50 |= V_51 ;
if ( V_274 -> V_33 . type != V_282 &&
V_274 -> V_33 . type != V_53 )
V_274 -> V_33 . V_50 |= V_159 ;
F_95 ( & V_274 -> V_33 ) ;
F_96 ( & V_274 -> V_33 ) ;
snprintf ( V_274 -> V_253 , V_283 , L_21 ,
V_274 -> V_33 . V_209 ) ;
snprintf ( V_274 -> V_255 , V_283 , L_22 ,
V_274 -> V_33 . V_209 ) ;
V_274 -> V_126 -> V_38 = V_274 -> V_33 . V_38 ;
V_274 -> V_126 -> type = V_274 -> V_33 . type ;
V_274 -> V_113 = V_16 -> V_113 ;
error = F_89 ( V_272 ) ||
F_90 ( V_272 ) ;
if ( error )
goto V_284;
if ( V_274 -> V_33 . V_38 ||
V_274 -> V_33 . type == V_282 ) {
V_275 -> V_33 =
* ( (struct V_32 * ) V_40 -> V_281 ) ;
V_275 -> V_33 . V_285 = V_286 ;
F_95 ( & V_275 -> V_33 ) ;
V_275 -> V_33 . V_55 = V_275 -> V_33 . V_59 = 4096 ;
F_96 ( & V_275 -> V_33 ) ;
snprintf ( V_275 -> V_254 , V_283 ,
L_23 , V_275 -> V_33 . V_209 ) ;
snprintf ( V_275 -> V_255 , V_283 ,
L_22 , V_275 -> V_33 . V_209 ) ;
if ( V_274 -> V_33 . V_38 )
V_275 -> V_33 . V_50 |= V_52 ;
if ( V_274 -> V_33 . type == V_282 ||
V_274 -> V_33 . type == V_53 )
V_275 -> V_33 . V_50 |= V_159 ;
V_275 -> V_113 = V_16 -> V_113 ;
error = F_89 ( V_273 ) ||
F_90 ( V_273 ) ;
if ( error )
goto V_284;
if ( V_274 -> V_33 . type == V_282 &&
V_274 -> V_33 . V_38 )
V_16 -> V_126 -> V_64 = V_275 -> V_64 ;
}
error = F_60 ( V_14 ) ;
if ( error )
goto V_284;
}
return;
V_284:
F_86 ( V_272 ) ;
F_86 ( V_273 ) ;
return;
}
void F_99 ( struct V_266 * V_267 )
{
struct V_14 * V_14 = F_43 ( V_267 , struct V_14 , V_267 ) ;
if ( ( V_14 -> V_16 . V_33 . V_198 & V_199 ) &&
! V_14 -> V_215 ) {
F_60 ( V_14 ) ;
}
else if ( ! ( V_14 -> V_16 . V_33 . V_198 & V_199 ) &&
V_14 -> V_215 ) {
F_69 ( V_14 ) ;
}
}
static T_2 F_100 ( struct V_1 * V_2 )
{
struct V_66 * V_71 ;
struct V_11 * V_12 ;
T_2 V_4 = 0 ;
V_71 = V_2 -> V_71 + V_74 ;
F_27 (report, &report_enum->report_list, list) {
T_2 V_287 = F_101 ( V_12 ) ;
if ( V_287 > V_4 )
V_4 = V_287 ;
}
return V_4 ;
}
static void F_102 ( struct V_14 * V_14 )
{
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_32 * V_33 = & V_16 -> V_33 ;
char V_209 [ V_283 ] ;
if ( ( V_33 -> type == V_63 ) && ! strcmp ( L_24 , V_33 -> V_209 ) ) {
if ( strstr ( V_14 -> V_2 -> V_209 , L_25 ) ||
strstr ( V_14 -> V_2 -> V_209 , L_26 ) ||
strstr ( V_14 -> V_2 -> V_209 , L_27 ) ) {
F_103 ( V_209 , V_14 -> V_2 -> V_209 , sizeof( V_209 ) ) ;
while ( 1 ) {
char * V_288 = strstr ( V_209 , L_28 ) ;
if ( V_288 == NULL )
break;
memmove ( V_288 , V_288 + 1 , strlen ( V_288 ) ) ;
}
if ( V_209 [ strlen ( V_209 ) - 1 ] == ' ' )
V_209 [ strlen ( V_209 ) - 1 ] = '\0' ;
} else {
snprintf ( V_209 , sizeof( V_209 ) ,
L_29 , V_33 -> V_209 , V_14 -> V_2 -> V_118 ) ;
}
} else {
F_103 ( V_209 , V_33 -> V_209 , sizeof( V_209 ) ) ;
}
snprintf ( V_16 -> V_253 , sizeof( V_16 -> V_253 ) ,
L_30 , V_209 ) ;
snprintf ( V_16 -> V_254 , sizeof( V_16 -> V_254 ) ,
L_31 , V_209 ) ;
snprintf ( V_16 -> V_255 , sizeof( V_16 -> V_255 ) ,
L_32 , V_209 ) ;
}
static int F_104 ( struct V_1 * V_2 ,
const struct V_278 * V_40 )
{
struct V_99 * V_100 = F_105 ( V_2 -> V_19 . V_225 ) ;
struct V_268 * V_19 = F_106 ( V_100 ) ;
struct V_14 * V_14 ;
struct V_16 * V_16 ;
struct V_32 * V_33 ;
int error ;
unsigned int V_289 = V_290 ;
if ( ! V_40 -> V_281 )
return - V_158 ;
V_2 -> V_198 |= V_291 ;
V_2 -> V_198 &= ~ V_292 ;
V_14 = F_16 ( sizeof( struct V_14 ) , V_39 ) ;
if ( ! V_14 )
return - V_83 ;
F_107 ( V_2 , V_14 ) ;
V_14 -> V_2 = V_2 ;
error = F_108 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_33 ) ;
goto V_293;
}
V_16 = & V_14 -> V_16 ;
V_16 -> V_33 = * ( (struct V_32 * ) V_40 -> V_281 ) ;
V_33 = & V_16 -> V_33 ;
V_33 -> V_285 = F_100 ( V_2 ) ;
if ( V_33 -> V_285 > V_15 ) {
error = - V_158 ;
goto V_294;
}
if ( V_33 -> V_295 && V_33 -> V_296 != V_2 -> type ) {
error = - V_297 ;
goto V_298;
}
V_14 -> V_269 = V_19 ;
V_14 -> V_100 = V_100 ;
F_109 ( & V_14 -> V_154 ) ;
F_110 ( & V_14 -> V_267 , F_97 ) ;
error = F_89 ( V_14 ) ;
if ( error )
goto V_299;
if ( V_33 -> type == V_97 ) {
if ( V_33 -> V_285 == V_300 ) {
V_33 -> type = V_63 ;
} else if ( ( V_33 -> V_285 != V_301 ) &&
( V_33 -> V_285 != V_302 ) ) {
error = - V_297 ;
goto V_303;
}
}
F_95 ( V_33 ) ;
F_33 ( V_2 , V_33 ) ;
F_111 ( V_14 ) ;
if ( V_33 -> V_50 == V_109 &&
V_33 -> type != V_98 ) {
error = V_33 -> type == V_63 ? - V_297 : 0 ;
F_112 ( & V_2 -> V_19 , L_34 ,
V_2 -> V_209 ,
error ? L_35 : L_36 ) ;
if ( error )
goto V_303;
V_33 -> V_50 |= V_51 ;
}
F_96 ( V_33 ) ;
F_102 ( V_14 ) ;
error = F_37 ( V_2 ) ;
if ( error )
goto V_303;
if ( ! ( V_33 -> V_50 & V_108 ) &&
( V_33 -> V_198 & V_199 ) ) {
error = F_60 ( V_14 ) ;
if ( error )
goto V_304;
}
error = F_90 ( V_14 ) ;
if ( error )
goto V_305;
if ( V_2 -> V_91 == V_92 ) {
error = F_113 ( & V_2 -> V_19 , & V_306 ) ;
if ( error )
F_17 ( V_2 ,
L_37 ,
error ) ;
}
if ( V_33 -> type == V_63 )
V_289 |= V_307 ;
error = F_114 ( V_2 , V_289 ) ;
if ( error ) {
F_3 ( V_2 , L_38 ) ;
goto V_308;
}
F_32 ( V_2 , V_33 ) ;
if ( V_33 -> V_50 & V_108 )
error = F_10 ( V_2 ) ;
if ( V_16 -> V_33 . type == V_282 &&
V_16 -> V_33 . V_50 & V_52 ) {
V_16 -> V_126 -> V_64 = V_16 -> V_64 ;
}
return 0 ;
V_308:
if ( V_2 -> V_91 == V_92 )
F_115 ( & V_2 -> V_19 , & V_306 ) ;
V_305:
F_86 ( V_14 ) ;
F_69 ( V_14 ) ;
V_304:
F_45 ( V_14 ) ;
V_303:
F_86 ( V_14 ) ;
V_299:
V_298:
V_294:
V_293:
F_18 ( V_14 ) ;
F_107 ( V_2 , NULL ) ;
return error ;
}
static void F_116 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
F_117 ( V_2 ) ;
F_118 ( & V_14 -> V_267 ) ;
F_86 ( V_14 ) ;
if ( V_2 -> V_91 == V_92 )
F_115 ( & V_2 -> V_19 , & V_306 ) ;
F_69 ( V_14 ) ;
F_45 ( V_14 ) ;
F_107 ( V_2 , NULL ) ;
F_18 ( V_14 ) ;
}
static int F_119 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_32 * V_33 = & V_14 -> V_16 . V_33 ;
F_38 ( & V_14 -> V_154 ) ;
F_32 ( V_2 , V_33 ) ;
F_47 ( V_14 ) ;
F_41 ( & V_14 -> V_154 ) ;
return 0 ;
}
static int F_120 ( struct V_1 * V_2 )
{
return F_119 ( V_2 ) ;
}
