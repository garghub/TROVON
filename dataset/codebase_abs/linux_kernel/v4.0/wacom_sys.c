static int F_1 ( struct V_1 * V_2 , T_1 type , T_1 * V_3 ,
T_2 V_4 , unsigned int V_5 )
{
int V_6 ;
do {
V_6 = F_2 ( V_2 , V_3 [ 0 ] , V_3 , V_4 , type ,
V_7 ) ;
} while ( ( V_6 == - V_8 || V_6 == - V_9 ) && -- V_5 );
return V_6 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 type , T_1 * V_3 ,
T_2 V_4 , unsigned int V_5 )
{
int V_6 ;
do {
V_6 = F_2 ( V_2 , V_3 [ 0 ] , V_3 , V_4 , type ,
V_10 ) ;
} while ( ( V_6 == - V_8 || V_6 == - V_9 ) && -- V_5 );
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_11 * V_12 ,
T_1 * V_13 , int V_4 )
{
struct V_14 * V_14 = F_5 ( V_2 ) ;
if ( V_4 > V_15 )
return 1 ;
memcpy ( V_14 -> V_16 . V_17 , V_13 , V_4 ) ;
F_6 ( & V_14 -> V_16 , V_4 ) ;
return 0 ;
}
static int F_7 ( struct V_18 * V_19 )
{
struct V_14 * V_14 = F_8 ( V_19 ) ;
return F_9 ( V_14 -> V_2 ) ;
}
static void F_10 ( struct V_18 * V_19 )
{
struct V_14 * V_14 = F_8 ( V_19 ) ;
F_11 ( V_14 -> V_2 ) ;
}
static int F_12 ( int V_20 , int V_21 ,
unsigned V_22 , int V_23 )
{
struct V_24 V_25 = {
. V_26 = V_20 ,
. V_27 = V_21 ,
. V_22 = V_22 ,
. V_28 = V_23 ,
} ;
return F_13 ( & V_25 , V_29 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_24 * V_25 , struct V_30 * V_31 )
{
struct V_14 * V_14 = F_5 ( V_2 ) ;
struct V_32 * V_33 = & V_14 -> V_16 . V_33 ;
struct V_34 * V_34 = & V_14 -> V_16 . V_34 ;
T_1 * V_17 ;
int V_35 ;
switch ( V_31 -> V_36 ) {
case V_37 :
if ( ! V_33 -> V_38 ) {
V_17 = F_15 ( 2 , V_39 ) ;
if ( ! V_17 )
break;
V_17 [ 0 ] = V_25 -> V_12 -> V_40 ;
V_35 = F_1 ( V_2 , V_41 ,
V_17 , 2 , 0 ) ;
if ( V_35 == 2 )
V_33 -> V_38 = V_17 [ 1 ] ;
F_16 ( V_17 ) ;
}
break;
case V_42 :
if ( V_31 -> V_43 >= V_25 -> V_44 ) {
F_17 ( & V_2 -> V_19 , L_1 ) ;
break;
}
V_34 -> V_45 = V_25 -> V_12 -> V_40 ;
V_34 -> V_46 = V_31 -> V_43 ;
break;
}
}
static void F_18 ( struct V_1 * V_2 ,
struct V_24 * V_25 , struct V_30 * V_31 )
{
struct V_14 * V_14 = F_5 ( V_2 ) ;
struct V_32 * V_33 = & V_14 -> V_16 . V_33 ;
bool V_47 = F_19 ( V_25 ) ;
bool V_48 = F_20 ( V_25 ) ;
if ( ! V_48 && ! V_47 )
return;
if ( V_33 -> type != V_49 ) {
if ( V_47 && ! V_33 -> V_38 )
V_33 -> V_38 = 1 ;
}
switch ( V_31 -> V_36 ) {
case V_50 :
V_33 -> V_51 = V_25 -> V_26 ;
if ( V_47 ) {
V_33 -> V_52 = V_53 ;
V_33 -> V_54 = V_25 -> V_27 ;
if ( V_33 -> type != V_49 ) {
V_33 -> V_22 = V_25 -> V_22 ;
V_33 -> V_55 = V_25 -> V_28 ;
}
} else {
V_33 -> V_52 = V_56 ;
}
break;
case V_57 :
V_33 -> V_58 = V_25 -> V_26 ;
if ( V_47 ) {
V_33 -> V_59 = V_25 -> V_27 ;
if ( V_33 -> type != V_49 ) {
V_33 -> V_22 = V_25 -> V_22 ;
V_33 -> V_55 = V_25 -> V_28 ;
}
}
break;
case V_60 :
if ( V_48 )
V_33 -> V_61 = V_25 -> V_26 ;
break;
}
if ( V_33 -> type == V_62 )
F_21 ( V_2 , V_25 , V_31 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_14 * V_14 = F_5 ( V_2 ) ;
struct V_16 * V_16 = & V_14 -> V_16 ;
if ( V_33 -> type == V_62 ) {
if ( V_33 -> V_38 > 1 ) {
F_23 ( V_16 -> V_63 , V_16 -> V_33 . V_38 ,
V_64 ) ;
}
}
}
static void F_24 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_65 * V_66 ;
struct V_11 * V_67 ;
int V_68 , V_69 ;
V_66 = & V_2 -> V_70 [ V_41 ] ;
F_25 (hreport, &rep_enum->report_list, list) {
for ( V_68 = 0 ; V_68 < V_67 -> V_71 ; V_68 ++ ) {
if ( V_67 -> V_25 [ V_68 ] -> V_44 < 1 )
continue;
for ( V_69 = 0 ; V_69 < V_67 -> V_25 [ V_68 ] -> V_72 ; V_69 ++ ) {
F_14 ( V_2 , V_67 -> V_25 [ V_68 ] ,
V_67 -> V_25 [ V_68 ] -> V_31 + V_69 ) ;
}
}
}
V_66 = & V_2 -> V_70 [ V_73 ] ;
F_25 (hreport, &rep_enum->report_list, list) {
if ( ! V_67 -> V_71 )
continue;
for ( V_68 = 0 ; V_68 < V_67 -> V_71 ; V_68 ++ )
for ( V_69 = 0 ; V_69 < V_67 -> V_25 [ V_68 ] -> V_72 ; V_69 ++ )
F_18 ( V_2 , V_67 -> V_25 [ V_68 ] ,
V_67 -> V_25 [ V_68 ] -> V_31 + V_69 ) ;
}
F_22 ( V_2 , V_33 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_5 ( V_2 ) ;
struct V_34 * V_34 = & V_14 -> V_16 . V_34 ;
struct V_11 * V_74 ;
struct V_65 * V_75 ;
if ( V_34 -> V_45 < 0 )
return 0 ;
V_75 = & ( V_2 -> V_70 [ V_41 ] ) ;
V_74 = V_75 -> V_76 [ V_34 -> V_45 ] ;
if ( V_74 ) {
V_74 -> V_25 [ 0 ] -> V_77 [ V_34 -> V_46 ] = 2 ;
F_27 ( V_2 , V_74 , V_10 ) ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , int V_78 ,
int V_79 , int V_80 )
{
unsigned char * V_81 ;
int error = - V_82 , V_83 = 0 ;
V_81 = F_15 ( V_79 , V_39 ) ;
if ( ! V_81 )
return error ;
do {
V_81 [ 0 ] = V_78 ;
V_81 [ 1 ] = V_80 ;
error = F_3 ( V_2 , V_41 , V_81 ,
V_79 , 1 ) ;
if ( error >= 0 )
error = F_1 ( V_2 , V_41 ,
V_81 , V_79 , 1 ) ;
} while ( ( error < 0 || V_81 [ 1 ] != V_80 ) && V_83 ++ < V_84 );
F_16 ( V_81 ) ;
return error < 0 ? error : 0 ;
}
static int F_29 ( struct V_1 * V_2 , T_1 V_85 ,
struct V_32 * V_33 )
{
struct V_14 * V_14 = F_5 ( V_2 ) ;
int V_35 ;
T_1 V_81 [ 2 ] ;
switch ( V_33 -> type ) {
case V_86 :
V_81 [ 0 ] = 0x03 ;
V_81 [ 1 ] = 0x00 ;
V_35 = F_3 ( V_2 , V_41 , V_81 , 2 ,
3 ) ;
if ( V_35 >= 0 ) {
V_81 [ 0 ] = V_85 == 0 ? 0x05 : 0x06 ;
V_81 [ 1 ] = 0x00 ;
V_35 = F_3 ( V_2 , V_41 ,
V_81 , 2 , 3 ) ;
if ( V_35 >= 0 ) {
V_14 -> V_16 . V_87 = V_85 ;
return 0 ;
}
}
F_30 ( V_2 , L_2 ,
V_81 [ 0 ] , V_35 ) ;
break;
case V_88 :
if ( V_85 == 1 )
V_14 -> V_16 . V_89 &= ~ 0x20 ;
else
V_14 -> V_16 . V_89 |= 0x20 ;
V_81 [ 0 ] = 0x03 ;
V_81 [ 1 ] = V_14 -> V_16 . V_89 ;
V_35 = F_3 ( V_2 , V_41 , V_81 , 2 ,
1 ) ;
if ( V_35 >= 0 )
V_14 -> V_16 . V_87 = V_85 ;
break;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
if ( V_2 -> V_90 == V_91 )
return F_29 ( V_2 , 1 , V_33 ) ;
if ( V_33 -> type == V_62 )
return F_26 ( V_2 ) ;
if ( V_33 -> V_52 == V_53 ) {
if ( V_33 -> type > V_92 ) {
return F_28 ( V_2 , 3 , 4 , 4 ) ;
}
else if ( V_33 -> type == V_93 || V_33 -> type == V_94 ) {
return F_28 ( V_2 , 18 , 3 , 2 ) ;
}
else if ( V_33 -> type == V_95 ) {
return F_28 ( V_2 , 131 , 3 , 2 ) ;
}
} else if ( V_33 -> V_52 == V_56 ) {
if ( V_33 -> type <= V_49 && V_33 -> type != V_96 ) {
return F_28 ( V_2 , 2 , 2 , 2 ) ;
}
}
return 0 ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_14 * V_14 = F_5 ( V_2 ) ;
struct V_97 * V_98 = V_14 -> V_98 ;
V_33 -> V_52 = V_56 ;
V_33 -> V_99 = 4 ;
V_33 -> V_100 = 4 ;
V_33 -> V_101 = 0 ;
V_33 -> V_102 = 0 ;
if ( V_33 -> type == V_96 ) {
if ( V_98 -> V_103 -> V_104 . V_105 == 0 ) {
V_33 -> V_52 = 0 ;
} else if ( V_98 -> V_103 -> V_104 . V_105 == 2 ) {
V_33 -> V_52 = V_53 ;
V_33 -> V_106 = V_107 ;
}
}
if ( V_33 -> type < V_49 )
return;
F_24 ( V_2 , V_33 ) ;
}
static bool F_33 ( struct V_1 * V_2 ,
struct V_1 * V_108 )
{
struct V_14 * V_14 = F_5 ( V_2 ) ;
struct V_32 * V_33 = & V_14 -> V_16 . V_33 ;
int V_109 = V_33 -> V_110 ;
int V_111 = V_33 -> V_112 ;
int V_113 , V_114 ;
if ( V_109 == 0 && V_111 == 0 ) {
V_109 = V_2 -> V_115 ;
V_111 = V_2 -> V_116 ;
}
if ( V_109 != V_108 -> V_115 || V_111 != V_108 -> V_116 )
return false ;
V_113 = strrchr ( V_2 -> V_117 , '.' ) - V_2 -> V_117 ;
V_114 = strrchr ( V_108 -> V_117 , '.' ) - V_108 -> V_117 ;
if ( V_113 != V_114 || V_113 <= 0 || V_114 <= 0 )
return false ;
return ! strncmp ( V_2 -> V_117 , V_108 -> V_117 , V_113 ) ;
}
static struct V_118 * F_34 ( struct V_1 * V_2 )
{
struct V_118 * V_17 ;
F_25 (data, &wacom_udev_list, list) {
if ( F_33 ( V_2 , V_17 -> V_19 ) ) {
F_35 ( & V_17 -> V_119 ) ;
return V_17 ;
}
}
return NULL ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_5 ( V_2 ) ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_118 * V_17 ;
int V_6 = 0 ;
F_37 ( & V_120 ) ;
V_17 = F_34 ( V_2 ) ;
if ( ! V_17 ) {
V_17 = F_15 ( sizeof( struct V_118 ) , V_39 ) ;
if ( ! V_17 ) {
V_6 = - V_82 ;
goto V_121;
}
F_38 ( & V_17 -> V_119 ) ;
V_17 -> V_19 = V_2 ;
F_39 ( & V_17 -> V_122 , & V_123 ) ;
}
V_16 -> V_124 = & V_17 -> V_124 ;
V_121:
F_40 ( & V_120 ) ;
return V_6 ;
}
static void F_41 ( struct V_119 * V_119 )
{
struct V_118 * V_17 =
F_42 ( V_119 , struct V_118 , V_119 ) ;
F_37 ( & V_120 ) ;
F_43 ( & V_17 -> V_122 ) ;
F_40 ( & V_120 ) ;
F_16 ( V_17 ) ;
}
static void F_44 ( struct V_16 * V_14 )
{
struct V_118 * V_17 ;
if ( V_14 -> V_124 ) {
V_17 = F_42 ( V_14 -> V_124 , struct V_118 , V_124 ) ;
F_45 ( & V_17 -> V_119 , F_41 ) ;
V_14 -> V_124 = NULL ;
}
}
static int F_46 ( struct V_14 * V_14 )
{
unsigned char * V_3 ;
int V_6 ;
unsigned char V_78 = V_125 ;
int V_126 = 9 ;
if ( V_14 -> V_16 . V_111 ) {
V_78 = V_127 ;
V_126 = 13 ;
}
V_3 = F_15 ( V_126 , V_39 ) ;
if ( ! V_3 )
return - V_82 ;
if ( V_14 -> V_16 . V_33 . type >= V_128 &&
V_14 -> V_16 . V_33 . type <= V_129 ) {
int V_130 = V_14 -> V_131 . V_132 [ 0 ] & 0x03 ;
int V_133 = ( ( ( V_14 -> V_131 . V_134 & 0x60 ) >> 5 ) - 1 ) & 0x03 ;
int V_135 = 0 ;
unsigned char V_136 = ( V_135 << 4 ) | ( V_133 << 2 ) | ( V_130 ) ;
V_3 [ 0 ] = V_78 ;
if ( V_14 -> V_16 . V_111 ) {
F_1 ( V_14 -> V_2 , V_41 ,
V_3 , V_126 , V_137 ) ;
V_3 [ 0 ] = V_78 ;
V_3 [ 4 ] = V_136 ;
} else
V_3 [ 1 ] = V_136 ;
}
else {
int V_131 = V_14 -> V_131 . V_132 [ 0 ] | 0x4 ;
if ( V_14 -> V_16 . V_33 . type == V_138 ||
V_14 -> V_16 . V_33 . type == V_139 )
V_131 |= ( V_14 -> V_131 . V_132 [ 1 ] << 4 ) | 0x40 ;
V_3 [ 0 ] = V_78 ;
V_3 [ 1 ] = V_131 ;
V_3 [ 2 ] = V_14 -> V_131 . V_134 ;
V_3 [ 3 ] = V_14 -> V_131 . V_140 ;
V_3 [ 4 ] = V_14 -> V_131 . V_141 ;
}
V_6 = F_3 ( V_14 -> V_2 , V_41 , V_3 , V_126 ,
V_137 ) ;
F_16 ( V_3 ) ;
return V_6 ;
}
static int F_47 ( struct V_14 * V_14 , int V_142 , T_1 V_143 ,
const unsigned V_144 , const void * V_145 )
{
unsigned char * V_3 ;
int V_68 , V_6 ;
const unsigned V_146 = V_144 / 4 ;
V_3 = F_15 ( V_146 + 3 , V_39 ) ;
if ( ! V_3 )
return - V_82 ;
V_3 [ 0 ] = V_147 ;
V_3 [ 1 ] = 1 ;
V_6 = F_3 ( V_14 -> V_2 , V_41 , V_3 , 2 ,
V_137 ) ;
if ( V_6 < 0 )
goto V_121;
V_3 [ 0 ] = V_143 ;
V_3 [ 1 ] = V_142 & 0x07 ;
for ( V_68 = 0 ; V_68 < 4 ; V_68 ++ ) {
V_3 [ 2 ] = V_68 ;
memcpy ( V_3 + 3 , V_145 + V_68 * V_146 , V_146 ) ;
V_6 = F_3 ( V_14 -> V_2 , V_41 ,
V_3 , V_146 + 3 , V_137 ) ;
if ( V_6 < 0 )
break;
}
V_3 [ 0 ] = V_147 ;
V_3 [ 1 ] = 0 ;
F_3 ( V_14 -> V_2 , V_41 , V_3 , 2 ,
V_137 ) ;
V_121:
F_16 ( V_3 ) ;
return V_6 ;
}
static T_3 F_48 ( struct V_148 * V_19 , int V_149 ,
const char * V_3 , T_2 V_150 )
{
struct V_1 * V_2 = F_42 ( V_19 , struct V_1 , V_19 ) ;
struct V_14 * V_14 = F_5 ( V_2 ) ;
unsigned int V_40 ;
int V_151 ;
V_151 = F_49 ( V_3 , 10 , & V_40 ) ;
if ( V_151 )
return V_151 ;
F_37 ( & V_14 -> V_152 ) ;
V_14 -> V_131 . V_132 [ V_149 ] = V_40 & 0x3 ;
V_151 = F_46 ( V_14 ) ;
F_40 ( & V_14 -> V_152 ) ;
return V_151 < 0 ? V_151 : V_150 ;
}
static T_3 F_50 ( struct V_14 * V_14 , T_1 * V_153 ,
const char * V_3 , T_2 V_150 )
{
unsigned int V_77 ;
int V_151 ;
V_151 = F_49 ( V_3 , 10 , & V_77 ) ;
if ( V_151 )
return V_151 ;
F_37 ( & V_14 -> V_152 ) ;
* V_153 = V_77 & 0x7f ;
V_151 = F_46 ( V_14 ) ;
F_40 ( & V_14 -> V_152 ) ;
return V_151 < 0 ? V_151 : V_150 ;
}
static T_3 F_51 ( struct V_148 * V_19 , int V_142 ,
const char * V_3 , T_2 V_150 )
{
struct V_1 * V_2 = F_42 ( V_19 , struct V_1 , V_19 ) ;
struct V_14 * V_14 = F_5 ( V_2 ) ;
int V_151 ;
unsigned V_144 ;
T_1 V_143 ;
if ( V_2 -> V_90 == V_91 ) {
V_144 = 256 ;
V_143 = V_154 ;
} else {
V_144 = 1024 ;
V_143 = V_155 ;
}
if ( V_150 != V_144 )
return - V_156 ;
F_37 ( & V_14 -> V_152 ) ;
V_151 = F_47 ( V_14 , V_142 , V_143 , V_144 , V_3 ) ;
F_40 ( & V_14 -> V_152 ) ;
return V_151 < 0 ? V_151 : V_150 ;
}
static int F_52 ( struct V_14 * V_14 )
{
int error ;
switch ( V_14 -> V_16 . V_33 . type ) {
case V_157 :
case V_158 :
case V_88 :
case V_159 :
V_14 -> V_131 . V_132 [ 0 ] = 0 ;
V_14 -> V_131 . V_132 [ 1 ] = 0 ;
V_14 -> V_131 . V_134 = 10 ;
V_14 -> V_131 . V_140 = 20 ;
V_14 -> V_131 . V_141 = 10 ;
error = F_53 ( & V_14 -> V_2 -> V_19 . V_160 ,
& V_161 ) ;
break;
case V_139 :
case V_138 :
V_14 -> V_131 . V_132 [ 0 ] = 0 ;
V_14 -> V_131 . V_132 [ 1 ] = 0 ;
V_14 -> V_131 . V_134 = 0 ;
V_14 -> V_131 . V_140 = 0 ;
V_14 -> V_131 . V_141 = 0 ;
error = F_53 ( & V_14 -> V_2 -> V_19 . V_160 ,
& V_162 ) ;
break;
case V_128 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_129 :
if ( V_14 -> V_16 . V_33 . V_52 == V_56 ) {
V_14 -> V_131 . V_132 [ 0 ] = 0 ;
V_14 -> V_131 . V_132 [ 1 ] = 0 ;
V_14 -> V_131 . V_134 = 32 ;
V_14 -> V_131 . V_140 = 0 ;
V_14 -> V_131 . V_141 = 0 ;
error = F_53 ( & V_14 -> V_2 -> V_19 . V_160 ,
& V_167 ) ;
} else
return 0 ;
break;
default:
return 0 ;
}
if ( error ) {
F_54 ( V_14 -> V_2 ,
L_3 , error ) ;
return error ;
}
F_46 ( V_14 ) ;
V_14 -> V_168 = true ;
return 0 ;
}
static void F_55 ( struct V_14 * V_14 )
{
if ( ! V_14 -> V_168 )
return;
V_14 -> V_168 = false ;
switch ( V_14 -> V_16 . V_33 . type ) {
case V_157 :
case V_158 :
case V_88 :
case V_159 :
F_56 ( & V_14 -> V_2 -> V_19 . V_160 ,
& V_161 ) ;
break;
case V_139 :
case V_138 :
F_56 ( & V_14 -> V_2 -> V_19 . V_160 ,
& V_162 ) ;
break;
case V_128 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_129 :
if ( V_14 -> V_16 . V_33 . V_52 == V_56 )
F_56 ( & V_14 -> V_2 -> V_19 . V_160 ,
& V_167 ) ;
break;
}
}
static int F_57 ( struct V_169 * V_170 ,
enum V_171 V_172 ,
union V_173 * V_174 )
{
struct V_14 * V_14 = F_42 ( V_170 , struct V_14 , V_175 ) ;
int V_35 = 0 ;
switch ( V_172 ) {
case V_176 :
V_174 -> V_177 = V_178 ;
break;
case V_179 :
V_174 -> V_177 =
V_14 -> V_16 . V_180 ;
break;
case V_181 :
if ( V_14 -> V_16 . V_182 )
V_174 -> V_177 = V_183 ;
else if ( V_14 -> V_16 . V_180 == 100 &&
V_14 -> V_16 . V_184 )
V_174 -> V_177 = V_185 ;
else
V_174 -> V_177 = V_186 ;
break;
default:
V_35 = - V_156 ;
break;
}
return V_35 ;
}
static int F_58 ( struct V_169 * V_170 ,
enum V_171 V_172 ,
union V_173 * V_174 )
{
struct V_14 * V_14 = F_42 ( V_170 , struct V_14 , V_187 ) ;
int V_35 = 0 ;
switch ( V_172 ) {
case V_188 :
case V_189 :
V_174 -> V_177 = V_14 -> V_16 . V_184 ;
break;
case V_176 :
V_174 -> V_177 = V_178 ;
break;
default:
V_35 = - V_156 ;
break;
}
return V_35 ;
}
static int F_59 ( struct V_14 * V_14 )
{
static T_4 V_190 = F_60 ( 0 ) ;
int error ;
unsigned long V_191 ;
if ( V_14 -> V_16 . V_33 . V_192 & V_193 ) {
V_191 = F_61 ( & V_190 ) - 1 ;
V_14 -> V_175 . V_194 = V_195 ;
V_14 -> V_175 . V_196 = F_62 ( V_195 ) ;
V_14 -> V_175 . V_197 = F_57 ;
sprintf ( V_14 -> V_16 . V_198 , L_4 , V_191 ) ;
V_14 -> V_175 . V_199 = V_14 -> V_16 . V_198 ;
V_14 -> V_175 . type = V_200 ;
V_14 -> V_175 . V_201 = 0 ;
V_14 -> V_187 . V_194 = V_202 ;
V_14 -> V_187 . V_196 = F_62 ( V_202 ) ;
V_14 -> V_187 . V_197 = F_58 ;
sprintf ( V_14 -> V_16 . V_203 , L_5 , V_191 ) ;
V_14 -> V_187 . V_199 = V_14 -> V_16 . V_203 ;
V_14 -> V_187 . type = V_204 ;
V_14 -> V_187 . V_201 = 0 ;
error = F_63 ( & V_14 -> V_2 -> V_19 ,
& V_14 -> V_175 ) ;
if ( error )
return error ;
F_64 ( & V_14 -> V_175 , & V_14 -> V_2 -> V_19 ) ;
error = F_63 ( & V_14 -> V_2 -> V_19 , & V_14 -> V_187 ) ;
if ( error ) {
F_65 ( & V_14 -> V_175 ) ;
return error ;
}
F_64 ( & V_14 -> V_187 , & V_14 -> V_2 -> V_19 ) ;
}
return 0 ;
}
static void F_66 ( struct V_14 * V_14 )
{
if ( ( V_14 -> V_16 . V_33 . V_192 & V_193 ) &&
V_14 -> V_175 . V_19 ) {
F_65 ( & V_14 -> V_175 ) ;
V_14 -> V_175 . V_19 = NULL ;
F_65 ( & V_14 -> V_187 ) ;
V_14 -> V_187 . V_19 = NULL ;
}
}
static T_3 F_67 ( struct V_148 * V_19 ,
struct V_205
* V_206 , char * V_3 )
{
struct V_1 * V_2 = F_42 ( V_19 , struct V_1 , V_19 ) ;
struct V_14 * V_14 = F_5 ( V_2 ) ;
return snprintf ( V_3 , V_207 , L_6 , V_14 -> V_16 . V_87 ) ;
}
static T_3 F_68 ( struct V_148 * V_19 ,
struct V_205 * V_206 ,
const char * V_3 , T_2 V_150 )
{
struct V_1 * V_2 = F_42 ( V_19 , struct V_1 , V_19 ) ;
struct V_14 * V_14 = F_5 ( V_2 ) ;
T_1 V_208 ;
if ( F_69 ( V_3 , 0 , & V_208 ) )
return - V_156 ;
if ( V_208 != 0 && V_208 != 1 )
return - V_156 ;
F_29 ( V_2 , V_208 , & V_14 -> V_16 . V_33 ) ;
return V_150 ;
}
static struct V_18 * F_70 ( struct V_14 * V_14 )
{
struct V_18 * V_18 ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
V_18 = F_71 () ;
if ( ! V_18 )
return NULL ;
V_18 -> V_199 = V_16 -> V_199 ;
V_18 -> V_117 = V_2 -> V_117 ;
V_18 -> V_19 . V_209 = & V_2 -> V_19 ;
V_18 -> V_210 = F_7 ;
V_18 -> V_211 = F_10 ;
V_18 -> V_212 = V_2 -> V_212 ;
V_18 -> V_40 . V_213 = V_2 -> V_90 ;
V_18 -> V_40 . V_115 = V_2 -> V_115 ;
V_18 -> V_40 . V_116 = V_16 -> V_111 ? V_16 -> V_111 : V_2 -> V_116 ;
V_18 -> V_40 . V_214 = V_2 -> V_214 ;
F_72 ( V_18 , V_14 ) ;
return V_18 ;
}
static void F_73 ( struct V_14 * V_14 )
{
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
if ( V_16 -> V_63 )
F_74 ( V_16 -> V_63 ) ;
if ( V_16 -> V_215 )
F_74 ( V_16 -> V_215 ) ;
V_16 -> V_63 = NULL ;
V_16 -> V_215 = NULL ;
}
static int F_75 ( struct V_14 * V_14 )
{
struct V_18 * V_18 , * V_216 ;
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
V_18 = F_70 ( V_14 ) ;
V_216 = F_70 ( V_14 ) ;
if ( ! V_18 || ! V_216 ) {
F_73 ( V_14 ) ;
return - V_82 ;
}
V_16 -> V_63 = V_18 ;
V_16 -> V_215 = V_216 ;
V_16 -> V_215 -> V_199 = V_16 -> V_217 ;
return 0 ;
}
static void F_76 ( struct V_14 * V_14 )
{
if ( V_14 -> V_16 . V_63 ) {
if ( V_14 -> V_16 . V_218 )
F_77 ( V_14 -> V_16 . V_63 ) ;
else
F_74 ( V_14 -> V_16 . V_63 ) ;
}
if ( V_14 -> V_16 . V_215 ) {
if ( V_14 -> V_16 . V_219 )
F_77 ( V_14 -> V_16 . V_215 ) ;
else
F_74 ( V_14 -> V_16 . V_215 ) ;
}
V_14 -> V_16 . V_63 = NULL ;
V_14 -> V_16 . V_215 = NULL ;
F_55 ( V_14 ) ;
}
static int F_78 ( struct V_14 * V_14 )
{
struct V_18 * V_18 , * V_216 ;
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
int error ;
V_18 = V_16 -> V_63 ;
V_216 = V_16 -> V_215 ;
if ( ! V_18 || ! V_216 )
return - V_156 ;
error = F_79 ( V_18 , V_16 ) ;
if ( ! error ) {
error = F_80 ( V_18 ) ;
if ( error )
return error ;
V_16 -> V_218 = true ;
}
error = F_81 ( V_216 , V_16 ) ;
if ( error ) {
F_74 ( V_216 ) ;
V_16 -> V_215 = NULL ;
V_216 = NULL ;
} else {
error = F_80 ( V_216 ) ;
if ( error )
goto V_220;
V_16 -> V_219 = true ;
error = F_52 ( V_14 ) ;
if ( error )
goto V_221;
}
return 0 ;
V_221:
F_77 ( V_216 ) ;
V_216 = NULL ;
V_16 -> V_219 = false ;
V_220:
F_77 ( V_18 ) ;
V_16 -> V_63 = NULL ;
V_16 -> V_218 = false ;
return error ;
}
static void F_82 ( struct V_222 * V_223 )
{
struct V_14 * V_14 = F_42 ( V_223 , struct V_14 , V_223 ) ;
struct V_224 * V_225 = V_14 -> V_225 ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_1 * V_226 , * V_227 ;
struct V_14 * V_228 , * V_229 ;
struct V_16 * V_230 , * V_231 ;
int error ;
F_66 ( V_14 ) ;
V_226 = F_83 ( V_225 -> V_232 -> V_233 [ 1 ] ) ;
V_228 = F_5 ( V_226 ) ;
V_230 = & ( V_228 -> V_16 ) ;
F_76 ( V_228 ) ;
V_227 = F_83 ( V_225 -> V_232 -> V_233 [ 2 ] ) ;
V_229 = F_5 ( V_227 ) ;
V_231 = & ( V_229 -> V_16 ) ;
F_76 ( V_229 ) ;
if ( V_16 -> V_111 == 0 ) {
F_84 ( V_14 -> V_2 , L_7 ) ;
V_230 -> V_124 -> type = 0 ;
} else {
const struct V_234 * V_40 = V_235 ;
F_84 ( V_14 -> V_2 , L_8 ,
V_16 -> V_111 ) ;
while ( V_40 -> V_90 ) {
if ( V_40 -> V_115 == V_236 &&
V_40 -> V_116 == V_16 -> V_111 )
break;
V_40 ++ ;
}
if ( ! V_40 -> V_90 ) {
F_84 ( V_14 -> V_2 , L_9 ) ;
return;
}
V_230 -> V_33 =
* ( (struct V_32 * ) V_40 -> V_237 ) ;
V_230 -> V_33 . V_52 = V_56 ;
snprintf ( V_230 -> V_199 , V_238 , L_10 ,
V_230 -> V_33 . V_199 ) ;
snprintf ( V_230 -> V_217 , V_238 , L_11 ,
V_230 -> V_33 . V_199 ) ;
V_230 -> V_124 -> V_38 = V_230 -> V_33 . V_38 ;
V_230 -> V_124 -> type = V_230 -> V_33 . type ;
V_230 -> V_111 = V_16 -> V_111 ;
error = F_75 ( V_228 ) ||
F_78 ( V_228 ) ;
if ( error )
goto V_239;
if ( V_230 -> V_33 . V_38 ||
V_230 -> V_33 . type == V_240 ) {
V_231 -> V_33 =
* ( (struct V_32 * ) V_40 -> V_237 ) ;
V_231 -> V_33 . V_106 = V_107 ;
V_231 -> V_33 . V_52 = V_53 ;
V_231 -> V_33 . V_51 = V_231 -> V_33 . V_58 = 4096 ;
if ( V_231 -> V_33 . V_38 )
snprintf ( V_231 -> V_199 , V_238 ,
L_12 , V_231 -> V_33 . V_199 ) ;
else
snprintf ( V_231 -> V_199 , V_238 ,
L_11 , V_231 -> V_33 . V_199 ) ;
snprintf ( V_231 -> V_217 , V_238 ,
L_11 , V_231 -> V_33 . V_199 ) ;
V_231 -> V_111 = V_16 -> V_111 ;
error = F_75 ( V_229 ) ||
F_78 ( V_229 ) ;
if ( error )
goto V_239;
if ( V_230 -> V_33 . type == V_240 &&
V_230 -> V_33 . V_38 )
V_16 -> V_124 -> V_241 = V_231 -> V_63 ;
}
error = F_59 ( V_14 ) ;
if ( error )
goto V_239;
}
return;
V_239:
F_76 ( V_228 ) ;
F_76 ( V_229 ) ;
return;
}
static void F_85 ( struct V_32 * V_33 )
{
if ( V_33 -> V_242 ) {
V_33 -> V_54 = ( V_33 -> V_51 * 100 ) /
V_33 -> V_242 ;
V_33 -> V_59 = ( V_33 -> V_58 * 100 ) /
V_33 -> V_243 ;
}
}
static void F_86 ( struct V_32 * V_33 )
{
V_33 -> V_242 = F_12 ( V_33 -> V_51 ,
V_33 -> V_54 ,
V_33 -> V_22 ,
V_33 -> V_55 ) ;
V_33 -> V_243 = F_12 ( V_33 -> V_58 ,
V_33 -> V_59 ,
V_33 -> V_22 ,
V_33 -> V_55 ) ;
}
static T_2 F_87 ( struct V_1 * V_2 )
{
struct V_65 * V_70 ;
struct V_11 * V_12 ;
T_2 V_4 = 0 ;
V_70 = V_2 -> V_70 + V_73 ;
F_25 (report, &report_enum->report_list, list) {
T_2 V_244 = F_88 ( V_12 ) ;
if ( V_244 > V_4 )
V_4 = V_244 ;
}
return V_4 ;
}
static int F_89 ( struct V_1 * V_2 ,
const struct V_234 * V_40 )
{
struct V_97 * V_98 = F_90 ( V_2 -> V_19 . V_209 ) ;
struct V_224 * V_19 = F_91 ( V_98 ) ;
struct V_14 * V_14 ;
struct V_16 * V_16 ;
struct V_32 * V_33 ;
int error ;
unsigned int V_245 = V_246 ;
if ( ! V_40 -> V_237 )
return - V_156 ;
V_2 -> V_192 |= V_247 ;
V_14 = F_15 ( sizeof( struct V_14 ) , V_39 ) ;
if ( ! V_14 )
return - V_82 ;
F_92 ( V_2 , V_14 ) ;
V_14 -> V_2 = V_2 ;
error = F_93 ( V_2 ) ;
if ( error ) {
F_54 ( V_2 , L_13 ) ;
goto V_248;
}
V_16 = & V_14 -> V_16 ;
V_16 -> V_33 = * ( (struct V_32 * ) V_40 -> V_237 ) ;
V_33 = & V_16 -> V_33 ;
V_33 -> V_106 = F_87 ( V_2 ) ;
if ( V_33 -> V_106 > V_15 ) {
error = - V_156 ;
goto V_249;
}
if ( V_33 -> V_250 && V_33 -> V_251 != V_2 -> type ) {
error = - V_252 ;
goto V_253;
}
V_14 -> V_225 = V_19 ;
V_14 -> V_98 = V_98 ;
F_94 ( & V_14 -> V_152 ) ;
F_95 ( & V_14 -> V_223 , F_82 ) ;
if ( ! ( V_33 -> V_192 & V_254 ) ) {
error = F_75 ( V_14 ) ;
if ( error )
goto V_255;
}
F_85 ( V_33 ) ;
F_32 ( V_2 , V_33 ) ;
if ( V_33 -> type >= V_128 && V_33 -> type <= V_240 ) {
if ( V_33 -> V_106 == V_107 ) {
V_33 -> V_52 = V_53 ;
V_33 -> V_51 = 4096 ;
V_33 -> V_58 = 4096 ;
} else {
V_33 -> V_52 = V_56 ;
}
}
if ( ( V_33 -> type == V_49 ) &&
( V_33 -> V_106 == V_107 ) &&
( V_33 -> V_52 == V_56 ) ) {
V_33 -> V_52 = V_53 ;
V_33 -> V_51 = 4096 ;
V_33 -> V_58 = 4096 ;
}
if ( V_2 -> V_90 == V_91 )
V_33 -> V_192 |= V_193 ;
F_96 ( V_33 ) ;
if ( ! V_33 -> V_22 ) {
V_33 -> V_22 = 0x11 ;
V_33 -> V_55 = - 3 ;
}
F_86 ( V_33 ) ;
F_97 ( V_16 -> V_199 , V_33 -> V_199 , sizeof( V_16 -> V_199 ) ) ;
snprintf ( V_16 -> V_217 , sizeof( V_16 -> V_217 ) ,
L_14 , V_33 -> V_199 ) ;
if ( V_33 -> V_192 & V_256 ) {
if ( V_33 -> V_52 != V_53 )
F_98 ( V_16 -> V_199 , L_15 , V_238 ) ;
else if ( V_33 -> V_38 )
F_98 ( V_16 -> V_199 , L_16 , V_238 ) ;
else
F_98 ( V_16 -> V_199 , L_17 , V_238 ) ;
error = F_36 ( V_2 ) ;
if ( error )
goto V_257;
}
if ( ! ( V_33 -> V_192 & V_258 ) &&
( V_33 -> V_192 & V_193 ) ) {
error = F_59 ( V_14 ) ;
if ( error )
goto V_259;
}
if ( ! ( V_33 -> V_192 & V_254 ) ) {
error = F_78 ( V_14 ) ;
if ( error )
goto V_260;
}
if ( V_2 -> V_90 == V_91 ) {
error = F_99 ( & V_2 -> V_19 , & V_261 ) ;
if ( error )
F_30 ( V_2 ,
L_18 ,
error ) ;
}
if ( V_33 -> type == V_62 )
V_245 |= V_262 ;
error = F_100 ( V_2 , V_245 ) ;
if ( error ) {
F_54 ( V_2 , L_19 ) ;
goto V_263;
}
F_31 ( V_2 , V_33 ) ;
if ( V_33 -> V_192 & V_258 )
error = F_9 ( V_2 ) ;
if ( V_16 -> V_33 . type == V_240 && V_16 -> V_33 . V_38 ) {
if ( V_16 -> V_33 . V_52 == V_53 )
V_16 -> V_124 -> V_241 = V_16 -> V_63 ;
}
return 0 ;
V_263:
if ( V_2 -> V_90 == V_91 )
F_101 ( & V_2 -> V_19 , & V_261 ) ;
V_260:
F_76 ( V_14 ) ;
F_66 ( V_14 ) ;
V_259:
F_44 ( V_16 ) ;
V_257:
F_76 ( V_14 ) ;
V_255:
V_253:
V_249:
V_248:
F_16 ( V_14 ) ;
F_92 ( V_2 , NULL ) ;
return error ;
}
static void F_102 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_5 ( V_2 ) ;
F_103 ( V_2 ) ;
F_104 ( & V_14 -> V_223 ) ;
F_76 ( V_14 ) ;
if ( V_2 -> V_90 == V_91 )
F_101 ( & V_2 -> V_19 , & V_261 ) ;
F_66 ( V_14 ) ;
F_44 ( & V_14 -> V_16 ) ;
F_92 ( V_2 , NULL ) ;
F_16 ( V_14 ) ;
}
static int F_105 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_5 ( V_2 ) ;
struct V_32 * V_33 = & V_14 -> V_16 . V_33 ;
F_37 ( & V_14 -> V_152 ) ;
F_31 ( V_2 , V_33 ) ;
F_46 ( V_14 ) ;
F_40 ( & V_14 -> V_152 ) ;
return 0 ;
}
static int F_106 ( struct V_1 * V_2 )
{
return F_105 ( V_2 ) ;
}
