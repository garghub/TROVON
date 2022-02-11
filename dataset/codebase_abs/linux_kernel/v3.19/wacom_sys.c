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
bool V_47 = ( V_25 -> V_48 == V_49 ) ||
( V_25 -> V_50 == V_49 ) ;
bool V_51 = ( V_25 -> V_48 == V_52 ) ||
( V_25 -> V_50 == V_52 ) ;
if ( ! V_51 && ! V_47 )
return;
if ( V_33 -> type != V_53 ) {
if ( V_47 && ! V_33 -> V_38 )
V_33 -> V_38 = 1 ;
}
switch ( V_31 -> V_36 ) {
case V_54 :
V_33 -> V_55 = V_25 -> V_26 ;
if ( V_47 ) {
V_33 -> V_56 = V_57 ;
V_33 -> V_58 = V_25 -> V_27 ;
if ( V_33 -> type != V_53 ) {
V_33 -> V_22 = V_25 -> V_22 ;
V_33 -> V_59 = V_25 -> V_28 ;
}
} else {
V_33 -> V_56 = V_60 ;
}
break;
case V_61 :
V_33 -> V_62 = V_25 -> V_26 ;
if ( V_47 ) {
V_33 -> V_63 = V_25 -> V_27 ;
if ( V_33 -> type != V_53 ) {
V_33 -> V_22 = V_25 -> V_22 ;
V_33 -> V_59 = V_25 -> V_28 ;
}
}
break;
case V_64 :
if ( V_51 )
V_33 -> V_65 = V_25 -> V_26 ;
break;
}
if ( V_33 -> type == V_66 )
F_19 ( V_2 , V_25 , V_31 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_14 * V_14 = F_5 ( V_2 ) ;
struct V_16 * V_16 = & V_14 -> V_16 ;
if ( V_33 -> type == V_66 ) {
if ( V_33 -> V_38 > 1 ) {
F_21 ( V_16 -> V_67 , V_16 -> V_33 . V_38 ,
V_68 ) ;
}
}
}
static void F_22 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_69 * V_70 ;
struct V_11 * V_71 ;
int V_72 , V_73 ;
V_70 = & V_2 -> V_74 [ V_41 ] ;
F_23 (hreport, &rep_enum->report_list, list) {
for ( V_72 = 0 ; V_72 < V_71 -> V_75 ; V_72 ++ ) {
if ( V_71 -> V_25 [ V_72 ] -> V_44 < 1 )
continue;
for ( V_73 = 0 ; V_73 < V_71 -> V_25 [ V_72 ] -> V_76 ; V_73 ++ ) {
F_14 ( V_2 , V_71 -> V_25 [ V_72 ] ,
V_71 -> V_25 [ V_72 ] -> V_31 + V_73 ) ;
}
}
}
V_70 = & V_2 -> V_74 [ V_77 ] ;
F_23 (hreport, &rep_enum->report_list, list) {
if ( ! V_71 -> V_75 )
continue;
for ( V_72 = 0 ; V_72 < V_71 -> V_75 ; V_72 ++ )
for ( V_73 = 0 ; V_73 < V_71 -> V_25 [ V_72 ] -> V_76 ; V_73 ++ )
F_18 ( V_2 , V_71 -> V_25 [ V_72 ] ,
V_71 -> V_25 [ V_72 ] -> V_31 + V_73 ) ;
}
F_20 ( V_2 , V_33 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_5 ( V_2 ) ;
struct V_34 * V_34 = & V_14 -> V_16 . V_34 ;
struct V_11 * V_78 ;
struct V_69 * V_79 ;
if ( V_34 -> V_45 < 0 )
return 0 ;
V_79 = & ( V_2 -> V_74 [ V_41 ] ) ;
V_78 = V_79 -> V_80 [ V_34 -> V_45 ] ;
if ( V_78 ) {
V_78 -> V_25 [ 0 ] -> V_81 [ V_34 -> V_46 ] = 2 ;
F_25 ( V_2 , V_78 , V_10 ) ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , int V_82 ,
int V_83 , int V_84 )
{
unsigned char * V_85 ;
int error = - V_86 , V_87 = 0 ;
V_85 = F_15 ( V_83 , V_39 ) ;
if ( ! V_85 )
return error ;
do {
V_85 [ 0 ] = V_82 ;
V_85 [ 1 ] = V_84 ;
error = F_3 ( V_2 , V_41 , V_85 ,
V_83 , 1 ) ;
if ( error >= 0 )
error = F_1 ( V_2 , V_41 ,
V_85 , V_83 , 1 ) ;
} while ( ( error < 0 || V_85 [ 1 ] != V_84 ) && V_87 ++ < V_88 );
F_16 ( V_85 ) ;
return error < 0 ? error : 0 ;
}
static int F_27 ( struct V_1 * V_2 , T_1 V_89 ,
struct V_32 * V_33 )
{
struct V_14 * V_14 = F_5 ( V_2 ) ;
int V_35 ;
T_1 V_85 [ 2 ] ;
switch ( V_33 -> type ) {
case V_90 :
V_85 [ 0 ] = 0x03 ;
V_85 [ 1 ] = 0x00 ;
V_35 = F_3 ( V_2 , V_41 , V_85 , 2 ,
3 ) ;
if ( V_35 >= 0 ) {
V_85 [ 0 ] = V_89 == 0 ? 0x05 : 0x06 ;
V_85 [ 1 ] = 0x00 ;
V_35 = F_3 ( V_2 , V_41 ,
V_85 , 2 , 3 ) ;
if ( V_35 >= 0 ) {
V_14 -> V_16 . V_91 = V_89 ;
return 0 ;
}
}
F_28 ( V_2 , L_2 ,
V_85 [ 0 ] , V_35 ) ;
break;
case V_92 :
if ( V_89 == 1 )
V_14 -> V_16 . V_93 &= ~ 0x20 ;
else
V_14 -> V_16 . V_93 |= 0x20 ;
V_85 [ 0 ] = 0x03 ;
V_85 [ 1 ] = V_14 -> V_16 . V_93 ;
V_35 = F_3 ( V_2 , V_41 , V_85 , 2 ,
1 ) ;
if ( V_35 >= 0 )
V_14 -> V_16 . V_91 = V_89 ;
break;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
if ( V_2 -> V_94 == V_95 )
return F_27 ( V_2 , 1 , V_33 ) ;
if ( V_33 -> type == V_66 )
return F_24 ( V_2 ) ;
if ( V_33 -> V_56 == V_57 ) {
if ( V_33 -> type > V_96 ) {
return F_26 ( V_2 , 3 , 4 , 4 ) ;
}
else if ( V_33 -> type == V_97 || V_33 -> type == V_98 ) {
return F_26 ( V_2 , 18 , 3 , 2 ) ;
}
} else if ( V_33 -> V_56 == V_60 ) {
if ( V_33 -> type <= V_53 && V_33 -> type != V_99 ) {
return F_26 ( V_2 , 2 , 2 , 2 ) ;
}
}
return 0 ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_14 * V_14 = F_5 ( V_2 ) ;
struct V_100 * V_101 = V_14 -> V_101 ;
V_33 -> V_56 = V_60 ;
V_33 -> V_102 = 4 ;
V_33 -> V_103 = 4 ;
V_33 -> V_104 = 0 ;
V_33 -> V_105 = 0 ;
if ( V_33 -> type == V_99 ) {
if ( V_101 -> V_106 -> V_107 . V_108 == 0 ) {
V_33 -> V_56 = 0 ;
} else if ( V_101 -> V_106 -> V_107 . V_108 == 2 ) {
V_33 -> V_56 = V_57 ;
V_33 -> V_109 = V_110 ;
}
}
if ( V_33 -> type < V_53 )
return;
F_22 ( V_2 , V_33 ) ;
}
static bool F_31 ( struct V_1 * V_2 ,
struct V_1 * V_111 )
{
struct V_14 * V_14 = F_5 ( V_2 ) ;
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
static struct V_121 * F_32 ( struct V_1 * V_2 )
{
struct V_121 * V_17 ;
F_23 (data, &wacom_udev_list, list) {
if ( F_31 ( V_2 , V_17 -> V_19 ) ) {
F_33 ( & V_17 -> V_122 ) ;
return V_17 ;
}
}
return NULL ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_5 ( V_2 ) ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_121 * V_17 ;
int V_6 = 0 ;
F_35 ( & V_123 ) ;
V_17 = F_32 ( V_2 ) ;
if ( ! V_17 ) {
V_17 = F_15 ( sizeof( struct V_121 ) , V_39 ) ;
if ( ! V_17 ) {
V_6 = - V_86 ;
goto V_124;
}
F_36 ( & V_17 -> V_122 ) ;
V_17 -> V_19 = V_2 ;
F_37 ( & V_17 -> V_125 , & V_126 ) ;
}
V_16 -> V_127 = & V_17 -> V_127 ;
V_124:
F_38 ( & V_123 ) ;
return V_6 ;
}
static void F_39 ( struct V_122 * V_122 )
{
struct V_121 * V_17 =
F_40 ( V_122 , struct V_121 , V_122 ) ;
F_35 ( & V_123 ) ;
F_41 ( & V_17 -> V_125 ) ;
F_38 ( & V_123 ) ;
F_16 ( V_17 ) ;
}
static void F_42 ( struct V_16 * V_14 )
{
struct V_121 * V_17 ;
if ( V_14 -> V_127 ) {
V_17 = F_40 ( V_14 -> V_127 , struct V_121 , V_127 ) ;
F_43 ( & V_17 -> V_122 , F_39 ) ;
V_14 -> V_127 = NULL ;
}
}
static int F_44 ( struct V_14 * V_14 )
{
unsigned char * V_3 ;
int V_6 ;
unsigned char V_82 = V_128 ;
int V_129 = 9 ;
if ( V_14 -> V_16 . V_114 ) {
V_82 = V_130 ;
V_129 = 13 ;
}
V_3 = F_15 ( V_129 , V_39 ) ;
if ( ! V_3 )
return - V_86 ;
if ( V_14 -> V_16 . V_33 . type >= V_131 &&
V_14 -> V_16 . V_33 . type <= V_132 ) {
int V_133 = V_14 -> V_134 . V_135 [ 0 ] & 0x03 ;
int V_136 = ( ( ( V_14 -> V_134 . V_137 & 0x60 ) >> 5 ) - 1 ) & 0x03 ;
int V_138 = 0 ;
unsigned char V_139 = ( V_138 << 4 ) | ( V_136 << 2 ) | ( V_133 ) ;
V_3 [ 0 ] = V_82 ;
if ( V_14 -> V_16 . V_114 ) {
F_1 ( V_14 -> V_2 , V_41 ,
V_3 , V_129 , V_140 ) ;
V_3 [ 0 ] = V_82 ;
V_3 [ 4 ] = V_139 ;
} else
V_3 [ 1 ] = V_139 ;
}
else {
int V_134 = V_14 -> V_134 . V_135 [ 0 ] | 0x4 ;
if ( V_14 -> V_16 . V_33 . type == V_141 ||
V_14 -> V_16 . V_33 . type == V_142 )
V_134 |= ( V_14 -> V_134 . V_135 [ 1 ] << 4 ) | 0x40 ;
V_3 [ 0 ] = V_82 ;
V_3 [ 1 ] = V_134 ;
V_3 [ 2 ] = V_14 -> V_134 . V_137 ;
V_3 [ 3 ] = V_14 -> V_134 . V_143 ;
V_3 [ 4 ] = V_14 -> V_134 . V_144 ;
}
V_6 = F_3 ( V_14 -> V_2 , V_41 , V_3 , V_129 ,
V_140 ) ;
F_16 ( V_3 ) ;
return V_6 ;
}
static int F_45 ( struct V_14 * V_14 , int V_145 , T_1 V_146 ,
const unsigned V_147 , const void * V_148 )
{
unsigned char * V_3 ;
int V_72 , V_6 ;
const unsigned V_149 = V_147 / 4 ;
V_3 = F_15 ( V_149 + 3 , V_39 ) ;
if ( ! V_3 )
return - V_86 ;
V_3 [ 0 ] = V_150 ;
V_3 [ 1 ] = 1 ;
V_6 = F_3 ( V_14 -> V_2 , V_41 , V_3 , 2 ,
V_140 ) ;
if ( V_6 < 0 )
goto V_124;
V_3 [ 0 ] = V_146 ;
V_3 [ 1 ] = V_145 & 0x07 ;
for ( V_72 = 0 ; V_72 < 4 ; V_72 ++ ) {
V_3 [ 2 ] = V_72 ;
memcpy ( V_3 + 3 , V_148 + V_72 * V_149 , V_149 ) ;
V_6 = F_3 ( V_14 -> V_2 , V_41 ,
V_3 , V_149 + 3 , V_140 ) ;
if ( V_6 < 0 )
break;
}
V_3 [ 0 ] = V_150 ;
V_3 [ 1 ] = 0 ;
F_3 ( V_14 -> V_2 , V_41 , V_3 , 2 ,
V_140 ) ;
V_124:
F_16 ( V_3 ) ;
return V_6 ;
}
static T_3 F_46 ( struct V_151 * V_19 , int V_152 ,
const char * V_3 , T_2 V_153 )
{
struct V_1 * V_2 = F_40 ( V_19 , struct V_1 , V_19 ) ;
struct V_14 * V_14 = F_5 ( V_2 ) ;
unsigned int V_40 ;
int V_154 ;
V_154 = F_47 ( V_3 , 10 , & V_40 ) ;
if ( V_154 )
return V_154 ;
F_35 ( & V_14 -> V_155 ) ;
V_14 -> V_134 . V_135 [ V_152 ] = V_40 & 0x3 ;
V_154 = F_44 ( V_14 ) ;
F_38 ( & V_14 -> V_155 ) ;
return V_154 < 0 ? V_154 : V_153 ;
}
static T_3 F_48 ( struct V_14 * V_14 , T_1 * V_156 ,
const char * V_3 , T_2 V_153 )
{
unsigned int V_81 ;
int V_154 ;
V_154 = F_47 ( V_3 , 10 , & V_81 ) ;
if ( V_154 )
return V_154 ;
F_35 ( & V_14 -> V_155 ) ;
* V_156 = V_81 & 0x7f ;
V_154 = F_44 ( V_14 ) ;
F_38 ( & V_14 -> V_155 ) ;
return V_154 < 0 ? V_154 : V_153 ;
}
static T_3 F_49 ( struct V_151 * V_19 , int V_145 ,
const char * V_3 , T_2 V_153 )
{
struct V_1 * V_2 = F_40 ( V_19 , struct V_1 , V_19 ) ;
struct V_14 * V_14 = F_5 ( V_2 ) ;
int V_154 ;
unsigned V_147 ;
T_1 V_146 ;
if ( V_2 -> V_94 == V_95 ) {
V_147 = 256 ;
V_146 = V_157 ;
} else {
V_147 = 1024 ;
V_146 = V_158 ;
}
if ( V_153 != V_147 )
return - V_159 ;
F_35 ( & V_14 -> V_155 ) ;
V_154 = F_45 ( V_14 , V_145 , V_146 , V_147 , V_3 ) ;
F_38 ( & V_14 -> V_155 ) ;
return V_154 < 0 ? V_154 : V_153 ;
}
static int F_50 ( struct V_14 * V_14 )
{
int error ;
switch ( V_14 -> V_16 . V_33 . type ) {
case V_160 :
case V_161 :
case V_92 :
case V_162 :
V_14 -> V_134 . V_135 [ 0 ] = 0 ;
V_14 -> V_134 . V_135 [ 1 ] = 0 ;
V_14 -> V_134 . V_137 = 10 ;
V_14 -> V_134 . V_143 = 20 ;
V_14 -> V_134 . V_144 = 10 ;
error = F_51 ( & V_14 -> V_2 -> V_19 . V_163 ,
& V_164 ) ;
break;
case V_142 :
case V_141 :
V_14 -> V_134 . V_135 [ 0 ] = 0 ;
V_14 -> V_134 . V_135 [ 1 ] = 0 ;
V_14 -> V_134 . V_137 = 0 ;
V_14 -> V_134 . V_143 = 0 ;
V_14 -> V_134 . V_144 = 0 ;
error = F_51 ( & V_14 -> V_2 -> V_19 . V_163 ,
& V_165 ) ;
break;
case V_131 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_132 :
if ( V_14 -> V_16 . V_33 . V_56 == V_60 ) {
V_14 -> V_134 . V_135 [ 0 ] = 0 ;
V_14 -> V_134 . V_135 [ 1 ] = 0 ;
V_14 -> V_134 . V_137 = 32 ;
V_14 -> V_134 . V_143 = 0 ;
V_14 -> V_134 . V_144 = 0 ;
error = F_51 ( & V_14 -> V_2 -> V_19 . V_163 ,
& V_170 ) ;
} else
return 0 ;
break;
default:
return 0 ;
}
if ( error ) {
F_52 ( V_14 -> V_2 ,
L_3 , error ) ;
return error ;
}
F_44 ( V_14 ) ;
V_14 -> V_171 = true ;
return 0 ;
}
static void F_53 ( struct V_14 * V_14 )
{
if ( ! V_14 -> V_171 )
return;
V_14 -> V_171 = false ;
switch ( V_14 -> V_16 . V_33 . type ) {
case V_160 :
case V_161 :
case V_92 :
case V_162 :
F_54 ( & V_14 -> V_2 -> V_19 . V_163 ,
& V_164 ) ;
break;
case V_142 :
case V_141 :
F_54 ( & V_14 -> V_2 -> V_19 . V_163 ,
& V_165 ) ;
break;
case V_131 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_132 :
if ( V_14 -> V_16 . V_33 . V_56 == V_60 )
F_54 ( & V_14 -> V_2 -> V_19 . V_163 ,
& V_170 ) ;
break;
}
}
static int F_55 ( struct V_172 * V_173 ,
enum V_174 V_175 ,
union V_176 * V_177 )
{
struct V_14 * V_14 = F_40 ( V_173 , struct V_14 , V_178 ) ;
int V_35 = 0 ;
switch ( V_175 ) {
case V_179 :
V_177 -> V_180 = V_181 ;
break;
case V_182 :
V_177 -> V_180 =
V_14 -> V_16 . V_183 ;
break;
case V_184 :
if ( V_14 -> V_16 . V_185 )
V_177 -> V_180 = V_186 ;
else if ( V_14 -> V_16 . V_183 == 100 &&
V_14 -> V_16 . V_187 )
V_177 -> V_180 = V_188 ;
else
V_177 -> V_180 = V_189 ;
break;
default:
V_35 = - V_159 ;
break;
}
return V_35 ;
}
static int F_56 ( struct V_172 * V_173 ,
enum V_174 V_175 ,
union V_176 * V_177 )
{
struct V_14 * V_14 = F_40 ( V_173 , struct V_14 , V_190 ) ;
int V_35 = 0 ;
switch ( V_175 ) {
case V_191 :
case V_192 :
V_177 -> V_180 = V_14 -> V_16 . V_187 ;
break;
case V_179 :
V_177 -> V_180 = V_181 ;
break;
default:
V_35 = - V_159 ;
break;
}
return V_35 ;
}
static int F_57 ( struct V_14 * V_14 )
{
static T_4 V_193 = F_58 ( 0 ) ;
int error ;
unsigned long V_194 ;
if ( V_14 -> V_16 . V_33 . V_195 & V_196 ) {
V_194 = F_59 ( & V_193 ) - 1 ;
V_14 -> V_178 . V_197 = V_198 ;
V_14 -> V_178 . V_199 = F_60 ( V_198 ) ;
V_14 -> V_178 . V_200 = F_55 ;
sprintf ( V_14 -> V_16 . V_201 , L_4 , V_194 ) ;
V_14 -> V_178 . V_202 = V_14 -> V_16 . V_201 ;
V_14 -> V_178 . type = V_203 ;
V_14 -> V_178 . V_204 = 0 ;
V_14 -> V_190 . V_197 = V_205 ;
V_14 -> V_190 . V_199 = F_60 ( V_205 ) ;
V_14 -> V_190 . V_200 = F_56 ;
sprintf ( V_14 -> V_16 . V_206 , L_5 , V_194 ) ;
V_14 -> V_190 . V_202 = V_14 -> V_16 . V_206 ;
V_14 -> V_190 . type = V_207 ;
V_14 -> V_190 . V_204 = 0 ;
error = F_61 ( & V_14 -> V_2 -> V_19 ,
& V_14 -> V_178 ) ;
if ( error )
return error ;
F_62 ( & V_14 -> V_178 , & V_14 -> V_2 -> V_19 ) ;
error = F_61 ( & V_14 -> V_2 -> V_19 , & V_14 -> V_190 ) ;
if ( error ) {
F_63 ( & V_14 -> V_178 ) ;
return error ;
}
F_62 ( & V_14 -> V_190 , & V_14 -> V_2 -> V_19 ) ;
}
return 0 ;
}
static void F_64 ( struct V_14 * V_14 )
{
if ( ( V_14 -> V_16 . V_33 . V_195 & V_196 ) &&
V_14 -> V_178 . V_19 ) {
F_63 ( & V_14 -> V_178 ) ;
V_14 -> V_178 . V_19 = NULL ;
F_63 ( & V_14 -> V_190 ) ;
V_14 -> V_190 . V_19 = NULL ;
}
}
static T_3 F_65 ( struct V_151 * V_19 ,
struct V_208
* V_209 , char * V_3 )
{
struct V_1 * V_2 = F_40 ( V_19 , struct V_1 , V_19 ) ;
struct V_14 * V_14 = F_5 ( V_2 ) ;
return snprintf ( V_3 , V_210 , L_6 , V_14 -> V_16 . V_91 ) ;
}
static T_3 F_66 ( struct V_151 * V_19 ,
struct V_208 * V_209 ,
const char * V_3 , T_2 V_153 )
{
struct V_1 * V_2 = F_40 ( V_19 , struct V_1 , V_19 ) ;
struct V_14 * V_14 = F_5 ( V_2 ) ;
T_1 V_211 ;
if ( F_67 ( V_3 , 0 , & V_211 ) )
return - V_159 ;
if ( V_211 != 0 && V_211 != 1 )
return - V_159 ;
F_27 ( V_2 , V_211 , & V_14 -> V_16 . V_33 ) ;
return V_153 ;
}
static struct V_18 * F_68 ( struct V_14 * V_14 )
{
struct V_18 * V_18 ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
V_18 = F_69 () ;
if ( ! V_18 )
return NULL ;
V_18 -> V_202 = V_16 -> V_202 ;
V_18 -> V_120 = V_2 -> V_120 ;
V_18 -> V_19 . V_212 = & V_2 -> V_19 ;
V_18 -> V_213 = F_7 ;
V_18 -> V_214 = F_10 ;
V_18 -> V_215 = V_2 -> V_215 ;
V_18 -> V_40 . V_216 = V_2 -> V_94 ;
V_18 -> V_40 . V_118 = V_2 -> V_118 ;
V_18 -> V_40 . V_119 = V_16 -> V_114 ? V_16 -> V_114 : V_2 -> V_119 ;
V_18 -> V_40 . V_217 = V_2 -> V_217 ;
F_70 ( V_18 , V_14 ) ;
return V_18 ;
}
static void F_71 ( struct V_14 * V_14 )
{
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
if ( V_16 -> V_67 )
F_72 ( V_16 -> V_67 ) ;
if ( V_16 -> V_218 )
F_72 ( V_16 -> V_218 ) ;
V_16 -> V_67 = NULL ;
V_16 -> V_218 = NULL ;
}
static int F_73 ( struct V_14 * V_14 )
{
struct V_18 * V_18 , * V_219 ;
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
V_18 = F_68 ( V_14 ) ;
V_219 = F_68 ( V_14 ) ;
if ( ! V_18 || ! V_219 ) {
F_71 ( V_14 ) ;
return - V_86 ;
}
V_16 -> V_67 = V_18 ;
V_16 -> V_218 = V_219 ;
V_16 -> V_218 -> V_202 = V_16 -> V_220 ;
return 0 ;
}
static void F_74 ( struct V_14 * V_14 )
{
if ( V_14 -> V_16 . V_67 ) {
if ( V_14 -> V_16 . V_221 )
F_75 ( V_14 -> V_16 . V_67 ) ;
else
F_72 ( V_14 -> V_16 . V_67 ) ;
}
if ( V_14 -> V_16 . V_218 ) {
if ( V_14 -> V_16 . V_222 )
F_75 ( V_14 -> V_16 . V_218 ) ;
else
F_72 ( V_14 -> V_16 . V_218 ) ;
}
V_14 -> V_16 . V_67 = NULL ;
V_14 -> V_16 . V_218 = NULL ;
F_53 ( V_14 ) ;
}
static int F_76 ( struct V_14 * V_14 )
{
struct V_18 * V_18 , * V_219 ;
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
int error ;
V_18 = V_16 -> V_67 ;
V_219 = V_16 -> V_218 ;
if ( ! V_18 || ! V_219 )
return - V_159 ;
error = F_77 ( V_18 , V_16 ) ;
if ( ! error ) {
error = F_78 ( V_18 ) ;
if ( error )
return error ;
V_16 -> V_221 = true ;
}
error = F_79 ( V_219 , V_16 ) ;
if ( error ) {
F_72 ( V_219 ) ;
V_16 -> V_218 = NULL ;
V_219 = NULL ;
} else {
error = F_78 ( V_219 ) ;
if ( error )
goto V_223;
V_16 -> V_222 = true ;
error = F_50 ( V_14 ) ;
if ( error )
goto V_224;
}
return 0 ;
V_224:
F_75 ( V_219 ) ;
V_219 = NULL ;
V_16 -> V_222 = false ;
V_223:
F_75 ( V_18 ) ;
V_16 -> V_67 = NULL ;
V_16 -> V_221 = false ;
return error ;
}
static void F_80 ( struct V_225 * V_226 )
{
struct V_14 * V_14 = F_40 ( V_226 , struct V_14 , V_226 ) ;
struct V_227 * V_228 = V_14 -> V_228 ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_1 * V_229 , * V_230 ;
struct V_14 * V_231 , * V_232 ;
struct V_16 * V_233 , * V_234 ;
int error ;
F_64 ( V_14 ) ;
V_229 = F_81 ( V_228 -> V_235 -> V_236 [ 1 ] ) ;
V_231 = F_5 ( V_229 ) ;
V_233 = & ( V_231 -> V_16 ) ;
F_74 ( V_231 ) ;
V_230 = F_81 ( V_228 -> V_235 -> V_236 [ 2 ] ) ;
V_232 = F_5 ( V_230 ) ;
V_234 = & ( V_232 -> V_16 ) ;
F_74 ( V_232 ) ;
if ( V_16 -> V_114 == 0 ) {
F_82 ( V_14 -> V_2 , L_7 ) ;
V_233 -> V_127 -> type = 0 ;
} else {
const struct V_237 * V_40 = V_238 ;
F_82 ( V_14 -> V_2 , L_8 ,
V_16 -> V_114 ) ;
while ( V_40 -> V_94 ) {
if ( V_40 -> V_118 == V_239 &&
V_40 -> V_119 == V_16 -> V_114 )
break;
V_40 ++ ;
}
if ( ! V_40 -> V_94 ) {
F_82 ( V_14 -> V_2 , L_9 ) ;
return;
}
V_233 -> V_33 =
* ( (struct V_32 * ) V_40 -> V_240 ) ;
V_233 -> V_33 . V_56 = V_60 ;
snprintf ( V_233 -> V_202 , V_241 , L_10 ,
V_233 -> V_33 . V_202 ) ;
snprintf ( V_233 -> V_220 , V_241 , L_11 ,
V_233 -> V_33 . V_202 ) ;
V_233 -> V_127 -> V_38 = V_233 -> V_33 . V_38 ;
V_233 -> V_127 -> type = V_233 -> V_33 . type ;
V_233 -> V_114 = V_16 -> V_114 ;
error = F_73 ( V_231 ) ||
F_76 ( V_231 ) ;
if ( error )
goto V_242;
if ( V_233 -> V_33 . V_38 ||
V_233 -> V_33 . type == V_243 ) {
V_234 -> V_33 =
* ( (struct V_32 * ) V_40 -> V_240 ) ;
V_234 -> V_33 . V_109 = V_110 ;
V_234 -> V_33 . V_56 = V_57 ;
V_234 -> V_33 . V_55 = V_234 -> V_33 . V_62 = 4096 ;
if ( V_234 -> V_33 . V_38 )
snprintf ( V_234 -> V_202 , V_241 ,
L_12 , V_234 -> V_33 . V_202 ) ;
else
snprintf ( V_234 -> V_202 , V_241 ,
L_11 , V_234 -> V_33 . V_202 ) ;
snprintf ( V_234 -> V_220 , V_241 ,
L_11 , V_234 -> V_33 . V_202 ) ;
V_234 -> V_114 = V_16 -> V_114 ;
error = F_73 ( V_232 ) ||
F_76 ( V_232 ) ;
if ( error )
goto V_242;
if ( V_233 -> V_33 . type == V_243 &&
V_233 -> V_33 . V_38 )
V_16 -> V_127 -> V_244 = V_234 -> V_67 ;
}
error = F_57 ( V_14 ) ;
if ( error )
goto V_242;
}
return;
V_242:
F_74 ( V_231 ) ;
F_74 ( V_232 ) ;
return;
}
static void F_83 ( struct V_32 * V_33 )
{
if ( V_33 -> V_245 ) {
V_33 -> V_58 = ( V_33 -> V_55 * 100 ) /
V_33 -> V_245 ;
V_33 -> V_63 = ( V_33 -> V_62 * 100 ) /
V_33 -> V_246 ;
}
}
static void F_84 ( struct V_32 * V_33 )
{
V_33 -> V_245 = F_12 ( V_33 -> V_55 ,
V_33 -> V_58 ,
V_33 -> V_22 ,
V_33 -> V_59 ) ;
V_33 -> V_246 = F_12 ( V_33 -> V_62 ,
V_33 -> V_63 ,
V_33 -> V_22 ,
V_33 -> V_59 ) ;
}
static T_2 F_85 ( struct V_1 * V_2 )
{
struct V_69 * V_74 ;
struct V_11 * V_12 ;
T_2 V_4 = 0 ;
V_74 = V_2 -> V_74 + V_77 ;
F_23 (report, &report_enum->report_list, list) {
T_2 V_247 = F_86 ( V_12 ) ;
if ( V_247 > V_4 )
V_4 = V_247 ;
}
return V_4 ;
}
static int F_87 ( struct V_1 * V_2 ,
const struct V_237 * V_40 )
{
struct V_100 * V_101 = F_88 ( V_2 -> V_19 . V_212 ) ;
struct V_227 * V_19 = F_89 ( V_101 ) ;
struct V_14 * V_14 ;
struct V_16 * V_16 ;
struct V_32 * V_33 ;
int error ;
unsigned int V_248 = V_249 ;
if ( ! V_40 -> V_240 )
return - V_159 ;
V_2 -> V_195 |= V_250 ;
V_14 = F_15 ( sizeof( struct V_14 ) , V_39 ) ;
if ( ! V_14 )
return - V_86 ;
F_90 ( V_2 , V_14 ) ;
V_14 -> V_2 = V_2 ;
error = F_91 ( V_2 ) ;
if ( error ) {
F_52 ( V_2 , L_13 ) ;
goto V_251;
}
V_16 = & V_14 -> V_16 ;
V_16 -> V_33 = * ( (struct V_32 * ) V_40 -> V_240 ) ;
V_33 = & V_16 -> V_33 ;
V_33 -> V_109 = F_85 ( V_2 ) ;
if ( V_33 -> V_109 > V_15 ) {
error = - V_159 ;
goto V_252;
}
if ( V_33 -> V_253 && V_33 -> V_254 != V_2 -> type ) {
error = - V_255 ;
goto V_256;
}
V_14 -> V_228 = V_19 ;
V_14 -> V_101 = V_101 ;
F_92 ( & V_14 -> V_155 ) ;
F_93 ( & V_14 -> V_226 , F_80 ) ;
if ( ! ( V_33 -> V_195 & V_257 ) ) {
error = F_73 ( V_14 ) ;
if ( error )
goto V_258;
}
F_83 ( V_33 ) ;
F_30 ( V_2 , V_33 ) ;
if ( V_33 -> type >= V_131 && V_33 -> type <= V_243 ) {
if ( V_33 -> V_109 == V_110 ) {
V_33 -> V_56 = V_57 ;
V_33 -> V_55 = 4096 ;
V_33 -> V_62 = 4096 ;
} else {
V_33 -> V_56 = V_60 ;
}
}
if ( ( V_33 -> type == V_53 ) &&
( V_33 -> V_109 == V_110 ) &&
( V_33 -> V_56 == V_60 ) ) {
V_33 -> V_56 = V_57 ;
V_33 -> V_55 = 4096 ;
V_33 -> V_62 = 4096 ;
}
if ( V_2 -> V_94 == V_95 )
V_33 -> V_195 |= V_196 ;
F_94 ( V_33 ) ;
if ( ! V_33 -> V_22 ) {
V_33 -> V_22 = 0x11 ;
V_33 -> V_59 = - 3 ;
}
F_84 ( V_33 ) ;
F_95 ( V_16 -> V_202 , V_33 -> V_202 , sizeof( V_16 -> V_202 ) ) ;
snprintf ( V_16 -> V_220 , sizeof( V_16 -> V_220 ) ,
L_14 , V_33 -> V_202 ) ;
if ( V_33 -> V_195 & V_259 ) {
if ( V_33 -> V_56 != V_57 )
F_96 ( V_16 -> V_202 , L_15 , V_241 ) ;
else if ( V_33 -> V_38 )
F_96 ( V_16 -> V_202 , L_16 , V_241 ) ;
else
F_96 ( V_16 -> V_202 , L_17 , V_241 ) ;
error = F_34 ( V_2 ) ;
if ( error )
goto V_260;
}
if ( ! ( V_33 -> V_195 & V_261 ) &&
( V_33 -> V_195 & V_196 ) ) {
error = F_57 ( V_14 ) ;
if ( error )
goto V_262;
}
if ( ! ( V_33 -> V_195 & V_257 ) ) {
error = F_76 ( V_14 ) ;
if ( error )
goto V_263;
}
if ( V_2 -> V_94 == V_95 ) {
error = F_97 ( & V_2 -> V_19 , & V_264 ) ;
if ( error )
F_28 ( V_2 ,
L_18 ,
error ) ;
}
if ( V_33 -> type == V_66 )
V_248 |= V_265 ;
error = F_98 ( V_2 , V_248 ) ;
if ( error ) {
F_52 ( V_2 , L_19 ) ;
goto V_266;
}
F_29 ( V_2 , V_33 ) ;
if ( V_33 -> V_195 & V_261 )
error = F_9 ( V_2 ) ;
if ( V_16 -> V_33 . type == V_243 && V_16 -> V_33 . V_38 ) {
if ( V_16 -> V_33 . V_56 == V_57 )
V_16 -> V_127 -> V_244 = V_16 -> V_67 ;
}
return 0 ;
V_266:
if ( V_2 -> V_94 == V_95 )
F_99 ( & V_2 -> V_19 , & V_264 ) ;
V_263:
F_74 ( V_14 ) ;
F_64 ( V_14 ) ;
V_262:
F_42 ( V_16 ) ;
V_260:
F_74 ( V_14 ) ;
V_258:
V_256:
V_252:
V_251:
F_16 ( V_14 ) ;
F_90 ( V_2 , NULL ) ;
return error ;
}
static void F_100 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_5 ( V_2 ) ;
F_101 ( V_2 ) ;
F_102 ( & V_14 -> V_226 ) ;
F_74 ( V_14 ) ;
if ( V_2 -> V_94 == V_95 )
F_99 ( & V_2 -> V_19 , & V_264 ) ;
F_64 ( V_14 ) ;
F_42 ( & V_14 -> V_16 ) ;
F_90 ( V_2 , NULL ) ;
F_16 ( V_14 ) ;
}
static int F_103 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_5 ( V_2 ) ;
struct V_32 * V_33 = & V_14 -> V_16 . V_33 ;
F_35 ( & V_14 -> V_155 ) ;
F_29 ( V_2 , V_33 ) ;
F_44 ( V_14 ) ;
F_38 ( & V_14 -> V_155 ) ;
return 0 ;
}
static int F_104 ( struct V_1 * V_2 )
{
return F_103 ( V_2 ) ;
}
