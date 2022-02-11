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
int V_6 ;
F_9 ( & V_14 -> V_20 ) ;
V_6 = F_10 ( V_14 -> V_2 ) ;
F_11 ( & V_14 -> V_20 ) ;
return V_6 ;
}
static void F_12 ( struct V_18 * V_19 )
{
struct V_14 * V_14 = F_8 ( V_19 ) ;
F_9 ( & V_14 -> V_20 ) ;
F_13 ( V_14 -> V_2 ) ;
F_11 ( & V_14 -> V_20 ) ;
}
static int F_14 ( int V_21 , int V_22 ,
unsigned V_23 , int V_24 )
{
struct V_25 V_26 = {
. V_27 = V_21 ,
. V_28 = V_22 ,
. V_23 = V_23 ,
. V_29 = V_24 ,
} ;
return F_15 ( & V_26 , V_30 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_25 * V_26 , struct V_31 * V_32 )
{
struct V_14 * V_14 = F_5 ( V_2 ) ;
struct V_33 * V_34 = & V_14 -> V_16 . V_34 ;
struct V_35 * V_35 = & V_14 -> V_16 . V_35 ;
T_1 * V_17 ;
int V_36 ;
switch ( V_32 -> V_37 ) {
case V_38 :
if ( ! V_34 -> V_39 ) {
V_17 = F_17 ( 2 , V_40 ) ;
if ( ! V_17 )
break;
V_17 [ 0 ] = V_26 -> V_12 -> V_41 ;
V_36 = F_1 ( V_2 , V_42 ,
V_17 , 2 , 0 ) ;
if ( V_36 == 2 )
V_34 -> V_39 = V_17 [ 1 ] ;
F_18 ( V_17 ) ;
}
break;
case V_43 :
if ( V_32 -> V_44 >= V_26 -> V_45 ) {
F_19 ( & V_2 -> V_19 , L_1 ) ;
break;
}
V_35 -> V_46 = V_26 -> V_12 -> V_41 ;
V_35 -> V_47 = V_32 -> V_44 ;
break;
}
}
static void F_20 ( struct V_1 * V_2 ,
struct V_25 * V_26 , struct V_31 * V_32 )
{
struct V_14 * V_14 = F_5 ( V_2 ) ;
struct V_33 * V_34 = & V_14 -> V_16 . V_34 ;
bool V_48 = ( V_26 -> V_49 == V_50 ) ||
( V_26 -> V_51 == V_50 ) ;
bool V_52 = ( V_26 -> V_49 == V_53 ) ||
( V_26 -> V_51 == V_53 ) ;
if ( ! V_52 && ! V_48 )
return;
if ( V_48 && ! V_34 -> V_39 )
V_34 -> V_39 = 1 ;
switch ( V_32 -> V_37 ) {
case V_54 :
V_34 -> V_55 = V_26 -> V_27 ;
if ( V_48 ) {
V_34 -> V_56 = V_57 ;
V_34 -> V_58 = V_26 -> V_28 ;
if ( V_34 -> type != V_59 ) {
V_34 -> V_23 = V_26 -> V_23 ;
V_34 -> V_60 = V_26 -> V_29 ;
}
} else {
V_34 -> V_56 = V_61 ;
}
break;
case V_62 :
V_34 -> V_63 = V_26 -> V_27 ;
if ( V_48 ) {
V_34 -> V_64 = V_26 -> V_28 ;
if ( V_34 -> type != V_59 ) {
V_34 -> V_23 = V_26 -> V_23 ;
V_34 -> V_60 = V_26 -> V_29 ;
}
}
break;
case V_65 :
if ( V_52 )
V_34 -> V_66 = V_26 -> V_27 ;
break;
}
if ( V_34 -> type == V_67 )
F_21 ( V_2 , V_26 , V_32 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_68 * V_69 ;
struct V_11 * V_70 ;
int V_71 , V_72 ;
V_69 = & V_2 -> V_73 [ V_42 ] ;
F_23 (hreport, &rep_enum->report_list, list) {
for ( V_71 = 0 ; V_71 < V_70 -> V_74 ; V_71 ++ ) {
if ( V_70 -> V_26 [ V_71 ] -> V_45 < 1 )
continue;
for ( V_72 = 0 ; V_72 < V_70 -> V_26 [ V_71 ] -> V_75 ; V_72 ++ ) {
F_16 ( V_2 , V_70 -> V_26 [ V_71 ] ,
V_70 -> V_26 [ V_71 ] -> V_32 + V_72 ) ;
}
}
}
V_69 = & V_2 -> V_73 [ V_76 ] ;
F_23 (hreport, &rep_enum->report_list, list) {
if ( ! V_70 -> V_74 )
continue;
for ( V_71 = 0 ; V_71 < V_70 -> V_74 ; V_71 ++ )
for ( V_72 = 0 ; V_72 < V_70 -> V_26 [ V_71 ] -> V_75 ; V_72 ++ )
F_20 ( V_2 , V_70 -> V_26 [ V_71 ] ,
V_70 -> V_26 [ V_71 ] -> V_32 + V_72 ) ;
}
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_5 ( V_2 ) ;
struct V_35 * V_35 = & V_14 -> V_16 . V_35 ;
struct V_11 * V_77 ;
struct V_68 * V_78 ;
if ( V_35 -> V_46 < 0 )
return 0 ;
V_78 = & ( V_2 -> V_73 [ V_42 ] ) ;
V_77 = V_78 -> V_79 [ V_35 -> V_46 ] ;
if ( V_77 ) {
V_77 -> V_26 [ 0 ] -> V_80 [ V_35 -> V_47 ] = 2 ;
F_25 ( V_2 , V_77 , V_10 ) ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , int V_81 ,
int V_82 , int V_83 )
{
unsigned char * V_84 ;
int error = - V_85 , V_86 = 0 ;
V_84 = F_17 ( V_82 , V_40 ) ;
if ( ! V_84 )
return error ;
do {
V_84 [ 0 ] = V_81 ;
V_84 [ 1 ] = V_83 ;
error = F_3 ( V_2 , V_42 , V_84 ,
V_82 , 1 ) ;
if ( error >= 0 )
error = F_1 ( V_2 , V_42 ,
V_84 , V_82 , 1 ) ;
} while ( ( error < 0 || V_84 [ 1 ] != V_83 ) && V_86 ++ < V_87 );
F_18 ( V_84 ) ;
return error < 0 ? error : 0 ;
}
static int F_27 ( struct V_1 * V_2 , T_1 V_88 ,
struct V_33 * V_34 )
{
struct V_14 * V_14 = F_5 ( V_2 ) ;
int V_36 ;
T_1 V_84 [ 2 ] ;
switch ( V_34 -> type ) {
case V_89 :
V_84 [ 0 ] = 0x03 ;
V_84 [ 1 ] = 0x00 ;
V_36 = F_3 ( V_2 , V_42 , V_84 , 2 ,
3 ) ;
if ( V_36 >= 0 ) {
V_84 [ 0 ] = V_88 == 0 ? 0x05 : 0x06 ;
V_84 [ 1 ] = 0x00 ;
V_36 = F_3 ( V_2 , V_42 ,
V_84 , 2 , 3 ) ;
if ( V_36 >= 0 ) {
V_14 -> V_16 . V_90 = V_88 ;
return 0 ;
}
}
F_28 ( V_2 , L_2 ,
V_84 [ 0 ] , V_36 ) ;
break;
case V_91 :
if ( V_88 == 1 )
V_14 -> V_16 . V_92 &= ~ 0x20 ;
else
V_14 -> V_16 . V_92 |= 0x20 ;
V_84 [ 0 ] = 0x03 ;
V_84 [ 1 ] = V_14 -> V_16 . V_92 ;
V_36 = F_3 ( V_2 , V_42 , V_84 , 2 ,
1 ) ;
if ( V_36 >= 0 )
V_14 -> V_16 . V_90 = V_88 ;
break;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
if ( V_2 -> V_93 == V_94 )
return F_27 ( V_2 , 1 , V_34 ) ;
if ( V_34 -> type == V_67 )
return F_24 ( V_2 ) ;
if ( V_34 -> V_56 == V_57 ) {
if ( V_34 -> type > V_95 ) {
return F_26 ( V_2 , 3 , 4 , 4 ) ;
}
else if ( V_34 -> type == V_96 || V_34 -> type == V_97 ) {
return F_26 ( V_2 , 18 , 3 , 2 ) ;
}
} else if ( V_34 -> V_56 == V_61 ) {
if ( V_34 -> type <= V_59 && V_34 -> type != V_98 ) {
return F_26 ( V_2 , 2 , 2 , 2 ) ;
}
}
return 0 ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_14 * V_14 = F_5 ( V_2 ) ;
struct V_99 * V_100 = V_14 -> V_100 ;
V_34 -> V_56 = V_61 ;
V_34 -> V_101 = 4 ;
V_34 -> V_102 = 4 ;
V_34 -> V_103 = 0 ;
V_34 -> V_104 = 0 ;
if ( V_34 -> type == V_98 ) {
if ( V_100 -> V_105 -> V_106 . V_107 == 0 ) {
V_34 -> V_56 = 0 ;
} else if ( V_100 -> V_105 -> V_106 . V_107 == 2 ) {
V_34 -> V_56 = V_57 ;
V_34 -> V_108 = V_109 ;
}
}
if ( V_34 -> type < V_59 )
return;
F_22 ( V_2 , V_34 ) ;
}
static bool F_31 ( struct V_1 * V_2 ,
struct V_1 * V_110 )
{
struct V_14 * V_14 = F_5 ( V_2 ) ;
struct V_33 * V_34 = & V_14 -> V_16 . V_34 ;
int V_111 = V_34 -> V_112 ;
int V_113 = V_34 -> V_114 ;
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
static struct V_120 * F_32 ( struct V_1 * V_2 )
{
struct V_120 * V_17 ;
F_23 (data, &wacom_udev_list, list) {
if ( F_31 ( V_2 , V_17 -> V_19 ) ) {
F_33 ( & V_17 -> V_121 ) ;
return V_17 ;
}
}
return NULL ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_5 ( V_2 ) ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_120 * V_17 ;
int V_6 = 0 ;
F_9 ( & V_122 ) ;
V_17 = F_32 ( V_2 ) ;
if ( ! V_17 ) {
V_17 = F_17 ( sizeof( struct V_120 ) , V_40 ) ;
if ( ! V_17 ) {
V_6 = - V_85 ;
goto V_123;
}
F_35 ( & V_17 -> V_121 ) ;
V_17 -> V_19 = V_2 ;
F_36 ( & V_17 -> V_124 , & V_125 ) ;
}
V_16 -> V_126 = & V_17 -> V_126 ;
V_123:
F_11 ( & V_122 ) ;
return V_6 ;
}
static void F_37 ( struct V_121 * V_121 )
{
struct V_120 * V_17 =
F_38 ( V_121 , struct V_120 , V_121 ) ;
F_9 ( & V_122 ) ;
F_39 ( & V_17 -> V_124 ) ;
F_11 ( & V_122 ) ;
F_18 ( V_17 ) ;
}
static void F_40 ( struct V_16 * V_14 )
{
struct V_120 * V_17 ;
if ( V_14 -> V_126 ) {
V_17 = F_38 ( V_14 -> V_126 , struct V_120 , V_126 ) ;
F_41 ( & V_17 -> V_121 , F_37 ) ;
V_14 -> V_126 = NULL ;
}
}
static int F_42 ( struct V_14 * V_14 )
{
unsigned char * V_3 ;
int V_6 ;
unsigned char V_81 = V_127 ;
int V_128 = 9 ;
if ( V_14 -> V_16 . V_113 ) {
V_81 = V_129 ;
V_128 = 13 ;
}
V_3 = F_17 ( V_128 , V_40 ) ;
if ( ! V_3 )
return - V_85 ;
if ( V_14 -> V_16 . V_34 . type >= V_130 &&
V_14 -> V_16 . V_34 . type <= V_131 ) {
int V_132 = V_14 -> V_133 . V_134 [ 0 ] & 0x03 ;
int V_135 = ( ( ( V_14 -> V_133 . V_136 & 0x60 ) >> 5 ) - 1 ) & 0x03 ;
int V_137 = 0 ;
unsigned char V_138 = ( V_137 << 4 ) | ( V_135 << 2 ) | ( V_132 ) ;
V_3 [ 0 ] = V_81 ;
if ( V_14 -> V_16 . V_113 ) {
F_1 ( V_14 -> V_2 , V_42 ,
V_3 , V_128 , V_139 ) ;
V_3 [ 0 ] = V_81 ;
V_3 [ 4 ] = V_138 ;
} else
V_3 [ 1 ] = V_138 ;
}
else {
int V_133 = V_14 -> V_133 . V_134 [ 0 ] | 0x4 ;
if ( V_14 -> V_16 . V_34 . type == V_140 ||
V_14 -> V_16 . V_34 . type == V_141 )
V_133 |= ( V_14 -> V_133 . V_134 [ 1 ] << 4 ) | 0x40 ;
V_3 [ 0 ] = V_81 ;
V_3 [ 1 ] = V_133 ;
V_3 [ 2 ] = V_14 -> V_133 . V_136 ;
V_3 [ 3 ] = V_14 -> V_133 . V_142 ;
V_3 [ 4 ] = V_14 -> V_133 . V_143 ;
}
V_6 = F_3 ( V_14 -> V_2 , V_42 , V_3 , V_128 ,
V_139 ) ;
F_18 ( V_3 ) ;
return V_6 ;
}
static int F_43 ( struct V_14 * V_14 , int V_144 , T_1 V_145 ,
const unsigned V_146 , const void * V_147 )
{
unsigned char * V_3 ;
int V_71 , V_6 ;
const unsigned V_148 = V_146 / 4 ;
V_3 = F_17 ( V_148 + 3 , V_40 ) ;
if ( ! V_3 )
return - V_85 ;
V_3 [ 0 ] = V_149 ;
V_3 [ 1 ] = 1 ;
V_6 = F_3 ( V_14 -> V_2 , V_42 , V_3 , 2 ,
V_139 ) ;
if ( V_6 < 0 )
goto V_123;
V_3 [ 0 ] = V_145 ;
V_3 [ 1 ] = V_144 & 0x07 ;
for ( V_71 = 0 ; V_71 < 4 ; V_71 ++ ) {
V_3 [ 2 ] = V_71 ;
memcpy ( V_3 + 3 , V_147 + V_71 * V_148 , V_148 ) ;
V_6 = F_3 ( V_14 -> V_2 , V_42 ,
V_3 , V_148 + 3 , V_139 ) ;
if ( V_6 < 0 )
break;
}
V_3 [ 0 ] = V_149 ;
V_3 [ 1 ] = 0 ;
F_3 ( V_14 -> V_2 , V_42 , V_3 , 2 ,
V_139 ) ;
V_123:
F_18 ( V_3 ) ;
return V_6 ;
}
static T_3 F_44 ( struct V_150 * V_19 , int V_151 ,
const char * V_3 , T_2 V_152 )
{
struct V_1 * V_2 = F_38 ( V_19 , struct V_1 , V_19 ) ;
struct V_14 * V_14 = F_5 ( V_2 ) ;
unsigned int V_41 ;
int V_153 ;
V_153 = F_45 ( V_3 , 10 , & V_41 ) ;
if ( V_153 )
return V_153 ;
F_9 ( & V_14 -> V_20 ) ;
V_14 -> V_133 . V_134 [ V_151 ] = V_41 & 0x3 ;
V_153 = F_42 ( V_14 ) ;
F_11 ( & V_14 -> V_20 ) ;
return V_153 < 0 ? V_153 : V_152 ;
}
static T_3 F_46 ( struct V_14 * V_14 , T_1 * V_154 ,
const char * V_3 , T_2 V_152 )
{
unsigned int V_80 ;
int V_153 ;
V_153 = F_45 ( V_3 , 10 , & V_80 ) ;
if ( V_153 )
return V_153 ;
F_9 ( & V_14 -> V_20 ) ;
* V_154 = V_80 & 0x7f ;
V_153 = F_42 ( V_14 ) ;
F_11 ( & V_14 -> V_20 ) ;
return V_153 < 0 ? V_153 : V_152 ;
}
static T_3 F_47 ( struct V_150 * V_19 , int V_144 ,
const char * V_3 , T_2 V_152 )
{
struct V_1 * V_2 = F_38 ( V_19 , struct V_1 , V_19 ) ;
struct V_14 * V_14 = F_5 ( V_2 ) ;
int V_153 ;
unsigned V_146 ;
T_1 V_145 ;
if ( V_2 -> V_93 == V_94 ) {
V_146 = 256 ;
V_145 = V_155 ;
} else {
V_146 = 1024 ;
V_145 = V_156 ;
}
if ( V_152 != V_146 )
return - V_157 ;
F_9 ( & V_14 -> V_20 ) ;
V_153 = F_43 ( V_14 , V_144 , V_145 , V_146 , V_3 ) ;
F_11 ( & V_14 -> V_20 ) ;
return V_153 < 0 ? V_153 : V_152 ;
}
static int F_48 ( struct V_14 * V_14 )
{
int error ;
switch ( V_14 -> V_16 . V_34 . type ) {
case V_158 :
case V_159 :
case V_91 :
case V_160 :
V_14 -> V_133 . V_134 [ 0 ] = 0 ;
V_14 -> V_133 . V_134 [ 1 ] = 0 ;
V_14 -> V_133 . V_136 = 10 ;
V_14 -> V_133 . V_142 = 20 ;
V_14 -> V_133 . V_143 = 10 ;
error = F_49 ( & V_14 -> V_2 -> V_19 . V_161 ,
& V_162 ) ;
break;
case V_141 :
case V_140 :
V_14 -> V_133 . V_134 [ 0 ] = 0 ;
V_14 -> V_133 . V_134 [ 1 ] = 0 ;
V_14 -> V_133 . V_136 = 0 ;
V_14 -> V_133 . V_142 = 0 ;
V_14 -> V_133 . V_143 = 0 ;
error = F_49 ( & V_14 -> V_2 -> V_19 . V_161 ,
& V_163 ) ;
break;
case V_130 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_131 :
if ( V_14 -> V_16 . V_34 . V_56 == V_61 ) {
V_14 -> V_133 . V_134 [ 0 ] = 0 ;
V_14 -> V_133 . V_134 [ 1 ] = 0 ;
V_14 -> V_133 . V_136 = 32 ;
V_14 -> V_133 . V_142 = 0 ;
V_14 -> V_133 . V_143 = 0 ;
error = F_49 ( & V_14 -> V_2 -> V_19 . V_161 ,
& V_168 ) ;
} else
return 0 ;
break;
default:
return 0 ;
}
if ( error ) {
F_50 ( V_14 -> V_2 ,
L_3 , error ) ;
return error ;
}
F_42 ( V_14 ) ;
V_14 -> V_169 = true ;
return 0 ;
}
static void F_51 ( struct V_14 * V_14 )
{
if ( ! V_14 -> V_169 )
return;
V_14 -> V_169 = false ;
switch ( V_14 -> V_16 . V_34 . type ) {
case V_158 :
case V_159 :
case V_91 :
case V_160 :
F_52 ( & V_14 -> V_2 -> V_19 . V_161 ,
& V_162 ) ;
break;
case V_141 :
case V_140 :
F_52 ( & V_14 -> V_2 -> V_19 . V_161 ,
& V_163 ) ;
break;
case V_130 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_131 :
if ( V_14 -> V_16 . V_34 . V_56 == V_61 )
F_52 ( & V_14 -> V_2 -> V_19 . V_161 ,
& V_168 ) ;
break;
}
}
static int F_53 ( struct V_170 * V_171 ,
enum V_172 V_173 ,
union V_174 * V_175 )
{
struct V_14 * V_14 = F_38 ( V_171 , struct V_14 , V_176 ) ;
int V_36 = 0 ;
switch ( V_173 ) {
case V_177 :
V_175 -> V_178 = V_179 ;
break;
case V_180 :
V_175 -> V_178 =
V_14 -> V_16 . V_181 ;
break;
case V_182 :
if ( V_14 -> V_16 . V_183 )
V_175 -> V_178 = V_184 ;
else if ( V_14 -> V_16 . V_181 == 100 &&
V_14 -> V_16 . V_185 )
V_175 -> V_178 = V_186 ;
else
V_175 -> V_178 = V_187 ;
break;
default:
V_36 = - V_157 ;
break;
}
return V_36 ;
}
static int F_54 ( struct V_170 * V_171 ,
enum V_172 V_173 ,
union V_174 * V_175 )
{
struct V_14 * V_14 = F_38 ( V_171 , struct V_14 , V_188 ) ;
int V_36 = 0 ;
switch ( V_173 ) {
case V_189 :
case V_190 :
V_175 -> V_178 = V_14 -> V_16 . V_185 ;
break;
case V_177 :
V_175 -> V_178 = V_179 ;
break;
default:
V_36 = - V_157 ;
break;
}
return V_36 ;
}
static int F_55 ( struct V_14 * V_14 )
{
static T_4 V_191 = F_56 ( 0 ) ;
int error ;
unsigned long V_192 ;
if ( V_14 -> V_16 . V_34 . V_193 & V_194 ) {
V_192 = F_57 ( & V_191 ) - 1 ;
V_14 -> V_176 . V_195 = V_196 ;
V_14 -> V_176 . V_197 = F_58 ( V_196 ) ;
V_14 -> V_176 . V_198 = F_53 ;
sprintf ( V_14 -> V_16 . V_199 , L_4 , V_192 ) ;
V_14 -> V_176 . V_200 = V_14 -> V_16 . V_199 ;
V_14 -> V_176 . type = V_201 ;
V_14 -> V_176 . V_202 = 0 ;
V_14 -> V_188 . V_195 = V_203 ;
V_14 -> V_188 . V_197 = F_58 ( V_203 ) ;
V_14 -> V_188 . V_198 = F_54 ;
sprintf ( V_14 -> V_16 . V_204 , L_5 , V_192 ) ;
V_14 -> V_188 . V_200 = V_14 -> V_16 . V_204 ;
V_14 -> V_188 . type = V_205 ;
V_14 -> V_188 . V_202 = 0 ;
error = F_59 ( & V_14 -> V_2 -> V_19 ,
& V_14 -> V_176 ) ;
if ( error )
return error ;
F_60 ( & V_14 -> V_176 , & V_14 -> V_2 -> V_19 ) ;
error = F_59 ( & V_14 -> V_2 -> V_19 , & V_14 -> V_188 ) ;
if ( error ) {
F_61 ( & V_14 -> V_176 ) ;
return error ;
}
F_60 ( & V_14 -> V_188 , & V_14 -> V_2 -> V_19 ) ;
}
return 0 ;
}
static void F_62 ( struct V_14 * V_14 )
{
if ( ( V_14 -> V_16 . V_34 . V_193 & V_194 ) &&
V_14 -> V_176 . V_19 ) {
F_61 ( & V_14 -> V_176 ) ;
V_14 -> V_176 . V_19 = NULL ;
F_61 ( & V_14 -> V_188 ) ;
V_14 -> V_188 . V_19 = NULL ;
}
}
static T_3 F_63 ( struct V_150 * V_19 ,
struct V_206
* V_207 , char * V_3 )
{
struct V_1 * V_2 = F_38 ( V_19 , struct V_1 , V_19 ) ;
struct V_14 * V_14 = F_5 ( V_2 ) ;
return snprintf ( V_3 , V_208 , L_6 , V_14 -> V_16 . V_90 ) ;
}
static T_3 F_64 ( struct V_150 * V_19 ,
struct V_206 * V_207 ,
const char * V_3 , T_2 V_152 )
{
struct V_1 * V_2 = F_38 ( V_19 , struct V_1 , V_19 ) ;
struct V_14 * V_14 = F_5 ( V_2 ) ;
T_1 V_209 ;
if ( F_65 ( V_3 , 0 , & V_209 ) )
return - V_157 ;
if ( V_209 != 0 && V_209 != 1 )
return - V_157 ;
F_27 ( V_2 , V_209 , & V_14 -> V_16 . V_34 ) ;
return V_152 ;
}
static struct V_18 * F_66 ( struct V_14 * V_14 )
{
struct V_18 * V_18 ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
V_18 = F_67 () ;
if ( ! V_18 )
return NULL ;
V_18 -> V_200 = V_16 -> V_200 ;
V_18 -> V_119 = V_2 -> V_119 ;
V_18 -> V_19 . V_210 = & V_2 -> V_19 ;
V_18 -> V_211 = F_7 ;
V_18 -> V_212 = F_12 ;
V_18 -> V_213 = V_2 -> V_213 ;
V_18 -> V_41 . V_214 = V_2 -> V_93 ;
V_18 -> V_41 . V_117 = V_2 -> V_117 ;
V_18 -> V_41 . V_118 = V_16 -> V_113 ? V_16 -> V_113 : V_2 -> V_118 ;
V_18 -> V_41 . V_215 = V_2 -> V_215 ;
F_68 ( V_18 , V_14 ) ;
return V_18 ;
}
static void F_69 ( struct V_14 * V_14 )
{
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
if ( V_16 -> V_216 )
F_70 ( V_16 -> V_216 ) ;
if ( V_16 -> V_217 )
F_70 ( V_16 -> V_217 ) ;
V_16 -> V_216 = NULL ;
V_16 -> V_217 = NULL ;
}
static int F_71 ( struct V_14 * V_14 )
{
struct V_18 * V_18 , * V_218 ;
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
V_18 = F_66 ( V_14 ) ;
V_218 = F_66 ( V_14 ) ;
if ( ! V_18 || ! V_218 ) {
F_69 ( V_14 ) ;
return - V_85 ;
}
V_16 -> V_216 = V_18 ;
V_16 -> V_217 = V_218 ;
V_16 -> V_217 -> V_200 = V_16 -> V_219 ;
return 0 ;
}
static void F_72 ( struct V_14 * V_14 )
{
if ( V_14 -> V_16 . V_216 ) {
if ( V_14 -> V_16 . V_220 )
F_73 ( V_14 -> V_16 . V_216 ) ;
else
F_70 ( V_14 -> V_16 . V_216 ) ;
}
if ( V_14 -> V_16 . V_217 ) {
if ( V_14 -> V_16 . V_220 )
F_73 ( V_14 -> V_16 . V_217 ) ;
else
F_70 ( V_14 -> V_16 . V_217 ) ;
}
V_14 -> V_16 . V_216 = NULL ;
V_14 -> V_16 . V_217 = NULL ;
F_51 ( V_14 ) ;
}
static int F_74 ( struct V_14 * V_14 )
{
struct V_18 * V_18 , * V_218 ;
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
int error ;
V_18 = V_16 -> V_216 ;
V_218 = V_16 -> V_217 ;
if ( ! V_18 || ! V_218 )
return - V_157 ;
error = F_75 ( V_18 , V_16 ) ;
if ( error )
return error ;
error = F_76 ( V_18 ) ;
if ( error )
return error ;
error = F_77 ( V_218 , V_16 ) ;
if ( error ) {
F_70 ( V_218 ) ;
V_16 -> V_217 = NULL ;
V_218 = NULL ;
} else {
error = F_76 ( V_218 ) ;
if ( error )
goto V_221;
error = F_48 ( V_14 ) ;
if ( error )
goto V_222;
}
V_16 -> V_220 = true ;
return 0 ;
V_222:
F_73 ( V_218 ) ;
V_218 = NULL ;
V_221:
F_73 ( V_18 ) ;
V_16 -> V_216 = NULL ;
return error ;
}
static void F_78 ( struct V_223 * V_224 )
{
struct V_14 * V_14 = F_38 ( V_224 , struct V_14 , V_224 ) ;
struct V_225 * V_226 = V_14 -> V_226 ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_1 * V_227 , * V_228 ;
struct V_14 * V_229 , * V_230 ;
struct V_16 * V_231 , * V_232 ;
int error ;
F_62 ( V_14 ) ;
V_227 = F_79 ( V_226 -> V_233 -> V_234 [ 1 ] ) ;
V_229 = F_5 ( V_227 ) ;
V_231 = & ( V_229 -> V_16 ) ;
F_72 ( V_229 ) ;
V_228 = F_79 ( V_226 -> V_233 -> V_234 [ 2 ] ) ;
V_230 = F_5 ( V_228 ) ;
V_232 = & ( V_230 -> V_16 ) ;
F_72 ( V_230 ) ;
if ( V_16 -> V_113 == 0 ) {
F_80 ( V_14 -> V_2 , L_7 ) ;
V_231 -> V_126 -> type = 0 ;
} else {
const struct V_235 * V_41 = V_236 ;
F_80 ( V_14 -> V_2 , L_8 ,
V_16 -> V_113 ) ;
while ( V_41 -> V_93 ) {
if ( V_41 -> V_117 == V_237 &&
V_41 -> V_118 == V_16 -> V_113 )
break;
V_41 ++ ;
}
if ( ! V_41 -> V_93 ) {
F_80 ( V_14 -> V_2 , L_9 ) ;
return;
}
V_231 -> V_34 =
* ( (struct V_33 * ) V_41 -> V_238 ) ;
V_231 -> V_34 . V_56 = V_61 ;
snprintf ( V_231 -> V_200 , V_239 , L_10 ,
V_231 -> V_34 . V_200 ) ;
snprintf ( V_231 -> V_219 , V_239 , L_11 ,
V_231 -> V_34 . V_200 ) ;
V_231 -> V_126 -> V_39 = V_231 -> V_34 . V_39 ;
V_231 -> V_126 -> type = V_231 -> V_34 . type ;
V_231 -> V_113 = V_16 -> V_113 ;
error = F_71 ( V_229 ) ||
F_74 ( V_229 ) ;
if ( error )
goto V_240;
if ( V_231 -> V_34 . V_39 ||
V_231 -> V_34 . type == V_241 ) {
V_232 -> V_34 =
* ( (struct V_33 * ) V_41 -> V_238 ) ;
V_232 -> V_34 . V_108 = V_109 ;
V_232 -> V_34 . V_56 = V_57 ;
V_232 -> V_34 . V_55 = V_232 -> V_34 . V_63 = 4096 ;
if ( V_232 -> V_34 . V_39 )
snprintf ( V_232 -> V_200 , V_239 ,
L_12 , V_232 -> V_34 . V_200 ) ;
else
snprintf ( V_232 -> V_200 , V_239 ,
L_11 , V_232 -> V_34 . V_200 ) ;
snprintf ( V_232 -> V_219 , V_239 ,
L_11 , V_232 -> V_34 . V_200 ) ;
V_232 -> V_113 = V_16 -> V_113 ;
error = F_71 ( V_230 ) ||
F_74 ( V_230 ) ;
if ( error )
goto V_240;
if ( V_231 -> V_34 . type == V_241 &&
V_231 -> V_34 . V_39 )
V_16 -> V_126 -> V_242 = V_232 -> V_216 ;
}
error = F_55 ( V_14 ) ;
if ( error )
goto V_240;
}
return;
V_240:
F_72 ( V_229 ) ;
F_72 ( V_230 ) ;
return;
}
static void F_81 ( struct V_33 * V_34 )
{
if ( V_34 -> V_243 ) {
V_34 -> V_58 = ( V_34 -> V_55 * 100 ) /
V_34 -> V_243 ;
V_34 -> V_64 = ( V_34 -> V_63 * 100 ) /
V_34 -> V_244 ;
}
}
static void F_82 ( struct V_33 * V_34 )
{
V_34 -> V_243 = F_14 ( V_34 -> V_55 ,
V_34 -> V_58 ,
V_34 -> V_23 ,
V_34 -> V_60 ) ;
V_34 -> V_244 = F_14 ( V_34 -> V_63 ,
V_34 -> V_64 ,
V_34 -> V_23 ,
V_34 -> V_60 ) ;
}
static int F_83 ( struct V_11 * V_12 )
{
return ( ( V_12 -> V_4 - 1 ) >> 3 ) + 1 + ( V_12 -> V_41 > 0 ) ;
}
static T_2 F_84 ( struct V_1 * V_2 )
{
struct V_68 * V_73 ;
struct V_11 * V_12 ;
T_2 V_4 = 0 ;
V_73 = V_2 -> V_73 + V_76 ;
F_23 (report, &report_enum->report_list, list) {
T_2 V_245 = F_83 ( V_12 ) ;
if ( V_245 > V_4 )
V_4 = V_245 ;
}
return V_4 ;
}
static int F_85 ( struct V_1 * V_2 ,
const struct V_235 * V_41 )
{
struct V_99 * V_100 = F_86 ( V_2 -> V_19 . V_210 ) ;
struct V_225 * V_19 = F_87 ( V_100 ) ;
struct V_14 * V_14 ;
struct V_16 * V_16 ;
struct V_33 * V_34 ;
int error ;
unsigned int V_246 = V_247 ;
if ( ! V_41 -> V_238 )
return - V_157 ;
V_2 -> V_193 |= V_248 ;
V_14 = F_17 ( sizeof( struct V_14 ) , V_40 ) ;
if ( ! V_14 )
return - V_85 ;
F_88 ( V_2 , V_14 ) ;
V_14 -> V_2 = V_2 ;
error = F_89 ( V_2 ) ;
if ( error ) {
F_50 ( V_2 , L_13 ) ;
goto V_249;
}
V_16 = & V_14 -> V_16 ;
V_16 -> V_34 = * ( (struct V_33 * ) V_41 -> V_238 ) ;
V_34 = & V_16 -> V_34 ;
V_34 -> V_108 = F_84 ( V_2 ) ;
if ( V_34 -> V_108 > V_15 ) {
error = - V_157 ;
goto V_250;
}
if ( V_34 -> V_251 && V_34 -> V_252 != V_2 -> type ) {
error = - V_253 ;
goto V_254;
}
V_14 -> V_226 = V_19 ;
V_14 -> V_100 = V_100 ;
F_90 ( & V_14 -> V_20 ) ;
F_91 ( & V_14 -> V_224 , F_78 ) ;
if ( ! ( V_34 -> V_193 & V_255 ) ) {
error = F_71 ( V_14 ) ;
if ( error )
goto V_256;
}
F_81 ( V_34 ) ;
F_30 ( V_2 , V_34 ) ;
if ( V_34 -> type >= V_130 && V_34 -> type <= V_241 ) {
if ( V_34 -> V_108 == V_109 ) {
V_34 -> V_56 = V_57 ;
V_34 -> V_55 = 4096 ;
V_34 -> V_63 = 4096 ;
} else {
V_34 -> V_56 = V_61 ;
}
}
if ( ( V_34 -> type == V_59 ) &&
( V_34 -> V_108 == V_109 ) &&
( V_34 -> V_56 == V_61 ) ) {
V_34 -> V_56 = V_57 ;
V_34 -> V_55 = 4096 ;
V_34 -> V_63 = 4096 ;
}
if ( V_2 -> V_93 == V_94 )
V_34 -> V_193 |= V_194 ;
F_92 ( V_34 ) ;
if ( ! V_34 -> V_23 ) {
V_34 -> V_23 = 0x11 ;
V_34 -> V_60 = - 3 ;
}
F_82 ( V_34 ) ;
F_93 ( V_16 -> V_200 , V_34 -> V_200 , sizeof( V_16 -> V_200 ) ) ;
snprintf ( V_16 -> V_219 , sizeof( V_16 -> V_219 ) ,
L_14 , V_34 -> V_200 ) ;
if ( V_34 -> V_193 & V_257 ) {
if ( V_34 -> V_56 != V_57 )
F_94 ( V_16 -> V_200 , L_15 , V_239 ) ;
else if ( V_34 -> V_39 )
F_94 ( V_16 -> V_200 , L_16 , V_239 ) ;
else
F_94 ( V_16 -> V_200 , L_17 , V_239 ) ;
error = F_34 ( V_2 ) ;
if ( error )
goto V_258;
}
if ( ! ( V_34 -> V_193 & V_259 ) &&
( V_34 -> V_193 & V_194 ) ) {
error = F_55 ( V_14 ) ;
if ( error )
goto V_260;
}
if ( ! ( V_34 -> V_193 & V_255 ) ) {
error = F_74 ( V_14 ) ;
if ( error )
goto V_261;
}
if ( V_2 -> V_93 == V_94 ) {
error = F_95 ( & V_2 -> V_19 , & V_262 ) ;
if ( error )
F_28 ( V_2 ,
L_18 ,
error ) ;
}
if ( V_34 -> type == V_67 )
V_246 |= V_263 ;
error = F_96 ( V_2 , V_246 ) ;
if ( error ) {
F_50 ( V_2 , L_19 ) ;
goto V_264;
}
F_29 ( V_2 , V_34 ) ;
if ( V_34 -> V_193 & V_259 )
error = F_10 ( V_2 ) ;
if ( V_16 -> V_34 . type == V_241 && V_16 -> V_34 . V_39 ) {
if ( V_16 -> V_34 . V_56 == V_57 )
V_16 -> V_126 -> V_242 = V_16 -> V_216 ;
}
return 0 ;
V_264:
if ( V_2 -> V_93 == V_94 )
F_97 ( & V_2 -> V_19 , & V_262 ) ;
V_261:
F_72 ( V_14 ) ;
F_62 ( V_14 ) ;
V_260:
F_40 ( V_16 ) ;
V_258:
F_72 ( V_14 ) ;
V_256:
V_254:
V_250:
V_249:
F_18 ( V_14 ) ;
F_88 ( V_2 , NULL ) ;
return error ;
}
static void F_98 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_5 ( V_2 ) ;
F_99 ( V_2 ) ;
F_100 ( & V_14 -> V_224 ) ;
F_72 ( V_14 ) ;
if ( V_2 -> V_93 == V_94 )
F_97 ( & V_2 -> V_19 , & V_262 ) ;
F_62 ( V_14 ) ;
F_40 ( & V_14 -> V_16 ) ;
F_88 ( V_2 , NULL ) ;
F_18 ( V_14 ) ;
}
static int F_101 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_5 ( V_2 ) ;
struct V_33 * V_34 = & V_14 -> V_16 . V_34 ;
F_9 ( & V_14 -> V_20 ) ;
F_29 ( V_2 , V_34 ) ;
F_42 ( V_14 ) ;
F_11 ( & V_14 -> V_20 ) ;
return 0 ;
}
static int F_102 ( struct V_1 * V_2 )
{
return F_101 ( V_2 ) ;
}
