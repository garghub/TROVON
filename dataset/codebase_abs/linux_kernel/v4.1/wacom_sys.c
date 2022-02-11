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
else if ( V_33 -> type == V_96 ) {
return F_28 ( V_2 , 2 , 2 , 2 ) ;
}
} else if ( V_33 -> V_52 == V_56 ) {
if ( V_33 -> type <= V_49 && V_33 -> type != V_97 ) {
return F_28 ( V_2 , 2 , 2 , 2 ) ;
}
}
return 0 ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_14 * V_14 = F_5 ( V_2 ) ;
struct V_98 * V_99 = V_14 -> V_99 ;
V_33 -> V_52 = V_56 ;
V_33 -> V_100 = 4 ;
V_33 -> V_101 = 4 ;
V_33 -> V_102 = 0 ;
V_33 -> V_103 = 0 ;
if ( V_33 -> type == V_97 ) {
if ( V_99 -> V_104 -> V_105 . V_106 == 0 ) {
V_33 -> V_52 = 0 ;
} else if ( V_99 -> V_104 -> V_105 . V_106 == 2 ) {
V_33 -> V_52 = V_53 ;
V_33 -> V_107 = V_108 ;
}
}
if ( V_33 -> type < V_49 )
return;
F_24 ( V_2 , V_33 ) ;
}
static bool F_33 ( struct V_1 * V_2 ,
struct V_1 * V_109 )
{
struct V_14 * V_14 = F_5 ( V_2 ) ;
struct V_32 * V_33 = & V_14 -> V_16 . V_33 ;
int V_110 = V_33 -> V_111 ;
int V_112 = V_33 -> V_113 ;
int V_114 , V_115 ;
if ( V_110 == 0 && V_112 == 0 ) {
V_110 = V_2 -> V_116 ;
V_112 = V_2 -> V_117 ;
}
if ( V_110 != V_109 -> V_116 || V_112 != V_109 -> V_117 )
return false ;
V_114 = strrchr ( V_2 -> V_118 , '.' ) - V_2 -> V_118 ;
V_115 = strrchr ( V_109 -> V_118 , '.' ) - V_109 -> V_118 ;
if ( V_114 != V_115 || V_114 <= 0 || V_115 <= 0 )
return false ;
return ! strncmp ( V_2 -> V_118 , V_109 -> V_118 , V_114 ) ;
}
static struct V_119 * F_34 ( struct V_1 * V_2 )
{
struct V_119 * V_17 ;
F_25 (data, &wacom_udev_list, list) {
if ( F_33 ( V_2 , V_17 -> V_19 ) ) {
F_35 ( & V_17 -> V_120 ) ;
return V_17 ;
}
}
return NULL ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_5 ( V_2 ) ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_119 * V_17 ;
int V_6 = 0 ;
F_37 ( & V_121 ) ;
V_17 = F_34 ( V_2 ) ;
if ( ! V_17 ) {
V_17 = F_15 ( sizeof( struct V_119 ) , V_39 ) ;
if ( ! V_17 ) {
V_6 = - V_82 ;
goto V_122;
}
F_38 ( & V_17 -> V_120 ) ;
V_17 -> V_19 = V_2 ;
F_39 ( & V_17 -> V_123 , & V_124 ) ;
}
V_16 -> V_125 = & V_17 -> V_125 ;
if ( V_16 -> V_33 . V_52 == V_53 )
V_16 -> V_125 -> V_126 = V_2 ;
else if ( V_16 -> V_33 . V_52 == V_56 )
V_16 -> V_125 -> V_48 = V_2 ;
V_122:
F_40 ( & V_121 ) ;
return V_6 ;
}
static void F_41 ( struct V_120 * V_120 )
{
struct V_119 * V_17 =
F_42 ( V_120 , struct V_119 , V_120 ) ;
F_37 ( & V_121 ) ;
F_43 ( & V_17 -> V_123 ) ;
F_40 ( & V_121 ) ;
F_16 ( V_17 ) ;
}
static void F_44 ( struct V_14 * V_14 )
{
struct V_119 * V_17 ;
struct V_16 * V_16 = & V_14 -> V_16 ;
if ( V_16 -> V_125 ) {
V_17 = F_42 ( V_16 -> V_125 , struct V_119 ,
V_125 ) ;
if ( V_16 -> V_125 -> V_126 == V_14 -> V_2 )
V_16 -> V_125 -> V_126 = NULL ;
else if ( V_16 -> V_125 -> V_48 == V_14 -> V_2 )
V_16 -> V_125 -> V_48 = NULL ;
F_45 ( & V_17 -> V_120 , F_41 ) ;
V_16 -> V_125 = NULL ;
}
}
static int F_46 ( struct V_14 * V_14 )
{
unsigned char * V_3 ;
int V_6 ;
unsigned char V_78 = V_127 ;
int V_128 = 9 ;
if ( V_14 -> V_16 . V_112 ) {
V_78 = V_129 ;
V_128 = 13 ;
}
V_3 = F_15 ( V_128 , V_39 ) ;
if ( ! V_3 )
return - V_82 ;
if ( V_14 -> V_16 . V_33 . type >= V_130 &&
V_14 -> V_16 . V_33 . type <= V_131 ) {
int V_132 = V_14 -> V_133 . V_134 [ 0 ] & 0x03 ;
int V_135 = ( ( ( V_14 -> V_133 . V_136 & 0x60 ) >> 5 ) - 1 ) & 0x03 ;
int V_137 = 0 ;
unsigned char V_138 = ( V_137 << 4 ) | ( V_135 << 2 ) | ( V_132 ) ;
V_3 [ 0 ] = V_78 ;
if ( V_14 -> V_16 . V_112 ) {
F_1 ( V_14 -> V_2 , V_41 ,
V_3 , V_128 , V_139 ) ;
V_3 [ 0 ] = V_78 ;
V_3 [ 4 ] = V_138 ;
} else
V_3 [ 1 ] = V_138 ;
}
else {
int V_133 = V_14 -> V_133 . V_134 [ 0 ] | 0x4 ;
if ( V_14 -> V_16 . V_33 . type == V_140 ||
V_14 -> V_16 . V_33 . type == V_141 )
V_133 |= ( V_14 -> V_133 . V_134 [ 1 ] << 4 ) | 0x40 ;
V_3 [ 0 ] = V_78 ;
V_3 [ 1 ] = V_133 ;
V_3 [ 2 ] = V_14 -> V_133 . V_136 ;
V_3 [ 3 ] = V_14 -> V_133 . V_142 ;
V_3 [ 4 ] = V_14 -> V_133 . V_143 ;
}
V_6 = F_3 ( V_14 -> V_2 , V_41 , V_3 , V_128 ,
V_139 ) ;
F_16 ( V_3 ) ;
return V_6 ;
}
static int F_47 ( struct V_14 * V_14 , int V_144 , T_1 V_145 ,
const unsigned V_146 , const void * V_147 )
{
unsigned char * V_3 ;
int V_68 , V_6 ;
const unsigned V_148 = V_146 / 4 ;
V_3 = F_15 ( V_148 + 3 , V_39 ) ;
if ( ! V_3 )
return - V_82 ;
V_3 [ 0 ] = V_149 ;
V_3 [ 1 ] = 1 ;
V_6 = F_3 ( V_14 -> V_2 , V_41 , V_3 , 2 ,
V_139 ) ;
if ( V_6 < 0 )
goto V_122;
V_3 [ 0 ] = V_145 ;
V_3 [ 1 ] = V_144 & 0x07 ;
for ( V_68 = 0 ; V_68 < 4 ; V_68 ++ ) {
V_3 [ 2 ] = V_68 ;
memcpy ( V_3 + 3 , V_147 + V_68 * V_148 , V_148 ) ;
V_6 = F_3 ( V_14 -> V_2 , V_41 ,
V_3 , V_148 + 3 , V_139 ) ;
if ( V_6 < 0 )
break;
}
V_3 [ 0 ] = V_149 ;
V_3 [ 1 ] = 0 ;
F_3 ( V_14 -> V_2 , V_41 , V_3 , 2 ,
V_139 ) ;
V_122:
F_16 ( V_3 ) ;
return V_6 ;
}
static T_3 F_48 ( struct V_150 * V_19 , int V_151 ,
const char * V_3 , T_2 V_152 )
{
struct V_1 * V_2 = F_42 ( V_19 , struct V_1 , V_19 ) ;
struct V_14 * V_14 = F_5 ( V_2 ) ;
unsigned int V_40 ;
int V_153 ;
V_153 = F_49 ( V_3 , 10 , & V_40 ) ;
if ( V_153 )
return V_153 ;
F_37 ( & V_14 -> V_154 ) ;
V_14 -> V_133 . V_134 [ V_151 ] = V_40 & 0x3 ;
V_153 = F_46 ( V_14 ) ;
F_40 ( & V_14 -> V_154 ) ;
return V_153 < 0 ? V_153 : V_152 ;
}
static T_3 F_50 ( struct V_14 * V_14 , T_1 * V_155 ,
const char * V_3 , T_2 V_152 )
{
unsigned int V_77 ;
int V_153 ;
V_153 = F_49 ( V_3 , 10 , & V_77 ) ;
if ( V_153 )
return V_153 ;
F_37 ( & V_14 -> V_154 ) ;
* V_155 = V_77 & 0x7f ;
V_153 = F_46 ( V_14 ) ;
F_40 ( & V_14 -> V_154 ) ;
return V_153 < 0 ? V_153 : V_152 ;
}
static T_3 F_51 ( struct V_150 * V_19 , int V_144 ,
const char * V_3 , T_2 V_152 )
{
struct V_1 * V_2 = F_42 ( V_19 , struct V_1 , V_19 ) ;
struct V_14 * V_14 = F_5 ( V_2 ) ;
int V_153 ;
unsigned V_146 ;
T_1 V_145 ;
if ( V_2 -> V_90 == V_91 ) {
V_146 = 256 ;
V_145 = V_156 ;
} else {
V_146 = 1024 ;
V_145 = V_157 ;
}
if ( V_152 != V_146 )
return - V_158 ;
F_37 ( & V_14 -> V_154 ) ;
V_153 = F_47 ( V_14 , V_144 , V_145 , V_146 , V_3 ) ;
F_40 ( & V_14 -> V_154 ) ;
return V_153 < 0 ? V_153 : V_152 ;
}
static int F_52 ( struct V_14 * V_14 )
{
int error ;
switch ( V_14 -> V_16 . V_33 . type ) {
case V_159 :
case V_160 :
case V_88 :
case V_161 :
V_14 -> V_133 . V_134 [ 0 ] = 0 ;
V_14 -> V_133 . V_134 [ 1 ] = 0 ;
V_14 -> V_133 . V_136 = 10 ;
V_14 -> V_133 . V_142 = 20 ;
V_14 -> V_133 . V_143 = 10 ;
error = F_53 ( & V_14 -> V_2 -> V_19 . V_162 ,
& V_163 ) ;
break;
case V_141 :
case V_140 :
V_14 -> V_133 . V_134 [ 0 ] = 0 ;
V_14 -> V_133 . V_134 [ 1 ] = 0 ;
V_14 -> V_133 . V_136 = 0 ;
V_14 -> V_133 . V_142 = 0 ;
V_14 -> V_133 . V_143 = 0 ;
error = F_53 ( & V_14 -> V_2 -> V_19 . V_162 ,
& V_164 ) ;
break;
case V_130 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_131 :
if ( V_14 -> V_16 . V_33 . V_52 == V_56 ) {
V_14 -> V_133 . V_134 [ 0 ] = 0 ;
V_14 -> V_133 . V_134 [ 1 ] = 0 ;
V_14 -> V_133 . V_136 = 32 ;
V_14 -> V_133 . V_142 = 0 ;
V_14 -> V_133 . V_143 = 0 ;
error = F_53 ( & V_14 -> V_2 -> V_19 . V_162 ,
& V_169 ) ;
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
V_14 -> V_170 = true ;
return 0 ;
}
static void F_55 ( struct V_14 * V_14 )
{
if ( ! V_14 -> V_170 )
return;
V_14 -> V_170 = false ;
switch ( V_14 -> V_16 . V_33 . type ) {
case V_159 :
case V_160 :
case V_88 :
case V_161 :
F_56 ( & V_14 -> V_2 -> V_19 . V_162 ,
& V_163 ) ;
break;
case V_141 :
case V_140 :
F_56 ( & V_14 -> V_2 -> V_19 . V_162 ,
& V_164 ) ;
break;
case V_130 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_131 :
if ( V_14 -> V_16 . V_33 . V_52 == V_56 )
F_56 ( & V_14 -> V_2 -> V_19 . V_162 ,
& V_169 ) ;
break;
}
}
static int F_57 ( struct V_171 * V_172 ,
enum V_173 V_174 ,
union V_175 * V_176 )
{
struct V_14 * V_14 = F_58 ( V_172 ) ;
int V_35 = 0 ;
switch ( V_174 ) {
case V_177 :
V_176 -> V_178 = V_14 -> V_16 . V_179 ;
break;
case V_180 :
V_176 -> V_178 = V_181 ;
break;
case V_182 :
V_176 -> V_178 =
V_14 -> V_16 . V_183 ;
break;
case V_184 :
if ( V_14 -> V_16 . V_185 )
V_176 -> V_178 = V_186 ;
else if ( V_14 -> V_16 . V_183 == 100 &&
V_14 -> V_16 . V_187 )
V_176 -> V_178 = V_188 ;
else if ( V_14 -> V_16 . V_187 )
V_176 -> V_178 = V_189 ;
else
V_176 -> V_178 = V_190 ;
break;
default:
V_35 = - V_158 ;
break;
}
return V_35 ;
}
static int F_59 ( struct V_171 * V_172 ,
enum V_173 V_174 ,
union V_175 * V_176 )
{
struct V_14 * V_14 = F_58 ( V_172 ) ;
int V_35 = 0 ;
switch ( V_174 ) {
case V_177 :
case V_191 :
V_176 -> V_178 = V_14 -> V_16 . V_187 ;
break;
case V_180 :
V_176 -> V_178 = V_181 ;
break;
default:
V_35 = - V_158 ;
break;
}
return V_35 ;
}
static int F_60 ( struct V_14 * V_14 )
{
static T_4 V_192 = F_61 ( 0 ) ;
struct V_193 V_194 = { . V_195 = V_14 , } ;
unsigned long V_196 ;
if ( V_14 -> V_16 . V_33 . V_197 & V_198 ) {
struct V_199 * V_200 = & V_14 -> V_201 ;
struct V_199 * V_202 = & V_14 -> V_202 ;
V_196 = F_62 ( & V_192 ) - 1 ;
V_200 -> V_203 = V_204 ;
V_200 -> V_205 = F_63 ( V_204 ) ;
V_200 -> V_206 = F_57 ;
sprintf ( V_14 -> V_16 . V_207 , L_4 , V_196 ) ;
V_200 -> V_208 = V_14 -> V_16 . V_207 ;
V_200 -> type = V_209 ;
V_200 -> V_210 = 0 ;
V_202 -> V_203 = V_211 ;
V_202 -> V_205 = F_63 ( V_211 ) ;
V_202 -> V_206 = F_59 ;
sprintf ( V_14 -> V_16 . V_212 , L_5 , V_196 ) ;
V_202 -> V_208 = V_14 -> V_16 . V_212 ;
V_202 -> type = V_213 ;
V_202 -> V_210 = 0 ;
V_14 -> V_214 = F_64 ( & V_14 -> V_2 -> V_19 ,
& V_14 -> V_201 , & V_194 ) ;
if ( F_65 ( V_14 -> V_214 ) )
return F_66 ( V_14 -> V_214 ) ;
F_67 ( V_14 -> V_214 , & V_14 -> V_2 -> V_19 ) ;
V_14 -> V_215 = F_64 ( & V_14 -> V_2 -> V_19 ,
& V_14 -> V_202 ,
& V_194 ) ;
if ( F_65 ( V_14 -> V_215 ) ) {
F_68 ( V_14 -> V_214 ) ;
return F_66 ( V_14 -> V_215 ) ;
}
F_67 ( V_14 -> V_215 , & V_14 -> V_2 -> V_19 ) ;
}
return 0 ;
}
static void F_69 ( struct V_14 * V_14 )
{
if ( V_14 -> V_214 ) {
F_68 ( V_14 -> V_214 ) ;
V_14 -> V_214 = NULL ;
F_68 ( V_14 -> V_215 ) ;
V_14 -> V_215 = NULL ;
}
}
static T_3 F_70 ( struct V_150 * V_19 ,
struct V_216
* V_217 , char * V_3 )
{
struct V_1 * V_2 = F_42 ( V_19 , struct V_1 , V_19 ) ;
struct V_14 * V_14 = F_5 ( V_2 ) ;
return snprintf ( V_3 , V_218 , L_6 , V_14 -> V_16 . V_87 ) ;
}
static T_3 F_71 ( struct V_150 * V_19 ,
struct V_216 * V_217 ,
const char * V_3 , T_2 V_152 )
{
struct V_1 * V_2 = F_42 ( V_19 , struct V_1 , V_19 ) ;
struct V_14 * V_14 = F_5 ( V_2 ) ;
T_1 V_219 ;
if ( F_72 ( V_3 , 0 , & V_219 ) )
return - V_158 ;
if ( V_219 != 0 && V_219 != 1 )
return - V_158 ;
F_29 ( V_2 , V_219 , & V_14 -> V_16 . V_33 ) ;
return V_152 ;
}
static struct V_18 * F_73 ( struct V_14 * V_14 )
{
struct V_18 * V_18 ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
V_18 = F_74 () ;
if ( ! V_18 )
return NULL ;
V_18 -> V_208 = V_16 -> V_208 ;
V_18 -> V_118 = V_2 -> V_118 ;
V_18 -> V_19 . V_220 = & V_2 -> V_19 ;
V_18 -> V_221 = F_7 ;
V_18 -> V_222 = F_10 ;
V_18 -> V_223 = V_2 -> V_223 ;
V_18 -> V_40 . V_224 = V_2 -> V_90 ;
V_18 -> V_40 . V_116 = V_2 -> V_116 ;
V_18 -> V_40 . V_117 = V_16 -> V_112 ? V_16 -> V_112 : V_2 -> V_117 ;
V_18 -> V_40 . V_225 = V_2 -> V_225 ;
F_75 ( V_18 , V_14 ) ;
return V_18 ;
}
static void F_76 ( struct V_14 * V_14 )
{
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
if ( V_16 -> V_63 )
F_77 ( V_16 -> V_63 ) ;
if ( V_16 -> V_226 )
F_77 ( V_16 -> V_226 ) ;
V_16 -> V_63 = NULL ;
V_16 -> V_226 = NULL ;
}
static int F_78 ( struct V_14 * V_14 )
{
struct V_18 * V_18 , * V_227 ;
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
V_18 = F_73 ( V_14 ) ;
V_227 = F_73 ( V_14 ) ;
if ( ! V_18 || ! V_227 ) {
F_76 ( V_14 ) ;
return - V_82 ;
}
V_16 -> V_63 = V_18 ;
V_16 -> V_226 = V_227 ;
V_16 -> V_226 -> V_208 = V_16 -> V_228 ;
return 0 ;
}
static void F_79 ( struct V_14 * V_14 )
{
if ( V_14 -> V_16 . V_63 ) {
if ( V_14 -> V_16 . V_229 )
F_80 ( V_14 -> V_16 . V_63 ) ;
else
F_77 ( V_14 -> V_16 . V_63 ) ;
}
if ( V_14 -> V_16 . V_226 ) {
if ( V_14 -> V_16 . V_230 )
F_80 ( V_14 -> V_16 . V_226 ) ;
else
F_77 ( V_14 -> V_16 . V_226 ) ;
}
V_14 -> V_16 . V_63 = NULL ;
V_14 -> V_16 . V_226 = NULL ;
F_55 ( V_14 ) ;
}
static int F_81 ( struct V_14 * V_14 )
{
struct V_18 * V_18 , * V_227 ;
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
int error ;
V_18 = V_16 -> V_63 ;
V_227 = V_16 -> V_226 ;
if ( ! V_18 || ! V_227 )
return - V_158 ;
error = F_82 ( V_18 , V_16 ) ;
if ( ! error ) {
error = F_83 ( V_18 ) ;
if ( error )
return error ;
V_16 -> V_229 = true ;
}
error = F_84 ( V_227 , V_16 ) ;
if ( error ) {
F_77 ( V_227 ) ;
V_16 -> V_226 = NULL ;
V_227 = NULL ;
} else {
error = F_83 ( V_227 ) ;
if ( error )
goto V_231;
V_16 -> V_230 = true ;
error = F_52 ( V_14 ) ;
if ( error )
goto V_232;
}
return 0 ;
V_232:
F_80 ( V_227 ) ;
V_227 = NULL ;
V_16 -> V_230 = false ;
V_231:
F_80 ( V_18 ) ;
V_16 -> V_63 = NULL ;
V_16 -> V_229 = false ;
return error ;
}
static void F_85 ( struct V_233 * V_234 )
{
struct V_14 * V_14 = F_42 ( V_234 , struct V_14 , V_234 ) ;
struct V_235 * V_236 = V_14 -> V_236 ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_1 * V_237 , * V_238 ;
struct V_14 * V_239 , * V_240 ;
struct V_16 * V_241 , * V_242 ;
int error ;
F_69 ( V_14 ) ;
V_237 = F_86 ( V_236 -> V_243 -> V_244 [ 1 ] ) ;
V_239 = F_5 ( V_237 ) ;
V_241 = & ( V_239 -> V_16 ) ;
F_79 ( V_239 ) ;
V_238 = F_86 ( V_236 -> V_243 -> V_244 [ 2 ] ) ;
V_240 = F_5 ( V_238 ) ;
V_242 = & ( V_240 -> V_16 ) ;
F_79 ( V_240 ) ;
if ( V_16 -> V_112 == 0 ) {
F_87 ( V_14 -> V_2 , L_7 ) ;
V_241 -> V_125 -> type = 0 ;
} else {
const struct V_245 * V_40 = V_246 ;
F_87 ( V_14 -> V_2 , L_8 ,
V_16 -> V_112 ) ;
while ( V_40 -> V_90 ) {
if ( V_40 -> V_116 == V_247 &&
V_40 -> V_117 == V_16 -> V_112 )
break;
V_40 ++ ;
}
if ( ! V_40 -> V_90 ) {
F_87 ( V_14 -> V_2 , L_9 ) ;
return;
}
V_241 -> V_33 =
* ( (struct V_32 * ) V_40 -> V_248 ) ;
V_241 -> V_33 . V_52 = V_56 ;
snprintf ( V_241 -> V_208 , V_249 , L_10 ,
V_241 -> V_33 . V_208 ) ;
snprintf ( V_241 -> V_228 , V_249 , L_11 ,
V_241 -> V_33 . V_208 ) ;
V_241 -> V_125 -> V_38 = V_241 -> V_33 . V_38 ;
V_241 -> V_125 -> type = V_241 -> V_33 . type ;
V_241 -> V_112 = V_16 -> V_112 ;
error = F_78 ( V_239 ) ||
F_81 ( V_239 ) ;
if ( error )
goto V_250;
if ( V_241 -> V_33 . V_38 ||
V_241 -> V_33 . type == V_251 ) {
V_242 -> V_33 =
* ( (struct V_32 * ) V_40 -> V_248 ) ;
V_242 -> V_33 . V_107 = V_108 ;
V_242 -> V_33 . V_52 = V_53 ;
V_242 -> V_33 . V_51 = V_242 -> V_33 . V_58 = 4096 ;
if ( V_242 -> V_33 . V_38 )
snprintf ( V_242 -> V_208 , V_249 ,
L_12 , V_242 -> V_33 . V_208 ) ;
else
snprintf ( V_242 -> V_208 , V_249 ,
L_11 , V_242 -> V_33 . V_208 ) ;
snprintf ( V_242 -> V_228 , V_249 ,
L_11 , V_242 -> V_33 . V_208 ) ;
V_242 -> V_112 = V_16 -> V_112 ;
error = F_78 ( V_240 ) ||
F_81 ( V_240 ) ;
if ( error )
goto V_250;
if ( V_241 -> V_33 . type == V_251 &&
V_241 -> V_33 . V_38 )
V_16 -> V_125 -> V_252 = V_242 -> V_63 ;
}
error = F_60 ( V_14 ) ;
if ( error )
goto V_250;
}
return;
V_250:
F_79 ( V_239 ) ;
F_79 ( V_240 ) ;
return;
}
void F_88 ( struct V_233 * V_234 )
{
struct V_14 * V_14 = F_42 ( V_234 , struct V_14 , V_234 ) ;
if ( ( V_14 -> V_16 . V_33 . V_197 & V_198 ) &&
! V_14 -> V_214 ) {
F_60 ( V_14 ) ;
}
else if ( ! ( V_14 -> V_16 . V_33 . V_197 & V_198 ) &&
V_14 -> V_214 ) {
F_69 ( V_14 ) ;
}
}
static void F_89 ( struct V_32 * V_33 )
{
if ( V_33 -> V_253 ) {
V_33 -> V_54 = ( V_33 -> V_51 * 100 ) /
V_33 -> V_253 ;
V_33 -> V_59 = ( V_33 -> V_58 * 100 ) /
V_33 -> V_254 ;
}
}
static void F_90 ( struct V_32 * V_33 )
{
V_33 -> V_253 = F_12 ( V_33 -> V_51 ,
V_33 -> V_54 ,
V_33 -> V_22 ,
V_33 -> V_55 ) ;
V_33 -> V_254 = F_12 ( V_33 -> V_58 ,
V_33 -> V_59 ,
V_33 -> V_22 ,
V_33 -> V_55 ) ;
}
static T_2 F_91 ( struct V_1 * V_2 )
{
struct V_65 * V_70 ;
struct V_11 * V_12 ;
T_2 V_4 = 0 ;
V_70 = V_2 -> V_70 + V_73 ;
F_25 (report, &report_enum->report_list, list) {
T_2 V_255 = F_92 ( V_12 ) ;
if ( V_255 > V_4 )
V_4 = V_255 ;
}
return V_4 ;
}
static int F_93 ( struct V_1 * V_2 ,
const struct V_245 * V_40 )
{
struct V_98 * V_99 = F_94 ( V_2 -> V_19 . V_220 ) ;
struct V_235 * V_19 = F_95 ( V_99 ) ;
struct V_14 * V_14 ;
struct V_16 * V_16 ;
struct V_32 * V_33 ;
int error ;
unsigned int V_256 = V_257 ;
if ( ! V_40 -> V_248 )
return - V_158 ;
V_2 -> V_197 |= V_258 ;
V_2 -> V_197 &= ~ V_259 ;
V_14 = F_15 ( sizeof( struct V_14 ) , V_39 ) ;
if ( ! V_14 )
return - V_82 ;
F_96 ( V_2 , V_14 ) ;
V_14 -> V_2 = V_2 ;
error = F_97 ( V_2 ) ;
if ( error ) {
F_54 ( V_2 , L_13 ) ;
goto V_260;
}
V_16 = & V_14 -> V_16 ;
V_16 -> V_33 = * ( (struct V_32 * ) V_40 -> V_248 ) ;
V_33 = & V_16 -> V_33 ;
V_33 -> V_107 = F_91 ( V_2 ) ;
if ( V_33 -> V_107 > V_15 ) {
error = - V_158 ;
goto V_261;
}
if ( V_33 -> V_262 && V_33 -> V_263 != V_2 -> type ) {
error = - V_264 ;
goto V_265;
}
V_14 -> V_236 = V_19 ;
V_14 -> V_99 = V_99 ;
F_98 ( & V_14 -> V_154 ) ;
F_99 ( & V_14 -> V_234 , F_85 ) ;
if ( ! ( V_33 -> V_197 & V_266 ) ) {
error = F_78 ( V_14 ) ;
if ( error )
goto V_267;
}
if ( V_33 -> type == V_96 ) {
if ( V_33 -> V_107 == V_268 ) {
V_33 -> type = V_62 ;
} else if ( ( V_33 -> V_107 != V_269 ) &&
( V_33 -> V_107 != V_270 ) ) {
error = - V_264 ;
goto V_271;
}
}
F_89 ( V_33 ) ;
F_32 ( V_2 , V_33 ) ;
if ( V_33 -> type >= V_130 && V_33 -> type <= V_251 ) {
if ( V_33 -> V_107 == V_108 ) {
V_33 -> V_52 = V_53 ;
V_33 -> V_51 = 4096 ;
V_33 -> V_58 = 4096 ;
} else {
V_33 -> V_52 = V_56 ;
}
}
if ( ( V_33 -> type == V_49 ) &&
( V_33 -> V_107 == V_108 ) &&
( V_33 -> V_52 == V_56 ) ) {
V_33 -> V_52 = V_53 ;
V_33 -> V_51 = 4096 ;
V_33 -> V_58 = 4096 ;
}
if ( V_33 -> type == V_96 )
V_33 -> V_52 = V_53 ;
if ( V_2 -> V_90 == V_91 )
V_33 -> V_197 |= V_198 ;
F_100 ( V_33 ) ;
if ( ! V_33 -> V_22 ) {
V_33 -> V_22 = 0x11 ;
V_33 -> V_55 = - 3 ;
}
F_90 ( V_33 ) ;
F_101 ( V_16 -> V_208 , V_33 -> V_208 , sizeof( V_16 -> V_208 ) ) ;
snprintf ( V_16 -> V_228 , sizeof( V_16 -> V_228 ) ,
L_14 , V_33 -> V_208 ) ;
if ( V_33 -> V_52 != V_53 )
F_102 ( V_16 -> V_208 , L_15 , V_249 ) ;
else if ( V_33 -> V_38 )
F_102 ( V_16 -> V_208 , L_16 , V_249 ) ;
else
F_102 ( V_16 -> V_208 , L_17 , V_249 ) ;
error = F_36 ( V_2 ) ;
if ( error )
goto V_271;
if ( ! ( V_33 -> V_197 & V_272 ) &&
( V_33 -> V_197 & V_198 ) ) {
error = F_60 ( V_14 ) ;
if ( error )
goto V_273;
}
if ( ! ( V_33 -> V_197 & V_266 ) ) {
error = F_81 ( V_14 ) ;
if ( error )
goto V_274;
}
if ( V_2 -> V_90 == V_91 ) {
error = F_103 ( & V_2 -> V_19 , & V_275 ) ;
if ( error )
F_30 ( V_2 ,
L_18 ,
error ) ;
}
if ( V_33 -> type == V_62 )
V_256 |= V_276 ;
error = F_104 ( V_2 , V_256 ) ;
if ( error ) {
F_54 ( V_2 , L_19 ) ;
goto V_277;
}
F_31 ( V_2 , V_33 ) ;
if ( V_33 -> V_197 & V_272 )
error = F_9 ( V_2 ) ;
if ( V_16 -> V_33 . type == V_251 && V_16 -> V_33 . V_38 ) {
if ( V_16 -> V_33 . V_52 == V_53 )
V_16 -> V_125 -> V_252 = V_16 -> V_63 ;
}
return 0 ;
V_277:
if ( V_2 -> V_90 == V_91 )
F_105 ( & V_2 -> V_19 , & V_275 ) ;
V_274:
F_79 ( V_14 ) ;
F_69 ( V_14 ) ;
V_273:
F_44 ( V_14 ) ;
V_271:
F_79 ( V_14 ) ;
V_267:
V_265:
V_261:
V_260:
F_16 ( V_14 ) ;
F_96 ( V_2 , NULL ) ;
return error ;
}
static void F_106 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_5 ( V_2 ) ;
F_107 ( V_2 ) ;
F_108 ( & V_14 -> V_234 ) ;
F_79 ( V_14 ) ;
if ( V_2 -> V_90 == V_91 )
F_105 ( & V_2 -> V_19 , & V_275 ) ;
F_69 ( V_14 ) ;
F_44 ( V_14 ) ;
F_96 ( V_2 , NULL ) ;
F_16 ( V_14 ) ;
}
static int F_109 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_5 ( V_2 ) ;
struct V_32 * V_33 = & V_14 -> V_16 . V_33 ;
F_37 ( & V_14 -> V_154 ) ;
F_31 ( V_2 , V_33 ) ;
F_46 ( V_14 ) ;
F_40 ( & V_14 -> V_154 ) ;
return 0 ;
}
static int F_110 ( struct V_1 * V_2 )
{
return F_109 ( V_2 ) ;
}
