static int F_1 ( struct V_1 * V_2 , T_1 type , T_1 V_3 ,
void * V_4 , T_2 V_5 , unsigned int V_6 )
{
int V_7 ;
do {
V_7 = F_2 ( V_2 , V_3 , V_4 , V_5 , type ,
V_8 ) ;
} while ( ( V_7 == - V_9 || V_7 == - V_10 ) && -- V_6 );
return V_7 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 type , T_1 * V_4 ,
T_2 V_5 , unsigned int V_6 )
{
int V_7 ;
do {
V_7 = F_2 ( V_2 , V_4 [ 0 ] , V_4 , V_5 , type ,
V_11 ) ;
} while ( ( V_7 == - V_9 || V_7 == - V_10 ) && -- V_6 );
return V_7 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_12 * V_13 ,
T_1 * V_14 , int V_5 )
{
struct V_15 * V_15 = F_5 ( V_2 ) ;
if ( V_5 > V_16 )
return 1 ;
memcpy ( V_15 -> V_17 . V_18 , V_14 , V_5 ) ;
F_6 ( & V_15 -> V_17 , V_5 ) ;
return 0 ;
}
static int F_7 ( struct V_19 * V_20 )
{
struct V_15 * V_15 = F_8 ( V_20 ) ;
int V_7 ;
F_9 ( & V_15 -> V_21 ) ;
V_7 = F_10 ( V_15 -> V_2 ) ;
F_11 ( & V_15 -> V_21 ) ;
return V_7 ;
}
static void F_12 ( struct V_19 * V_20 )
{
struct V_15 * V_15 = F_8 ( V_20 ) ;
F_9 ( & V_15 -> V_21 ) ;
F_13 ( V_15 -> V_2 ) ;
F_11 ( & V_15 -> V_21 ) ;
}
static int F_14 ( int V_22 , int V_23 ,
unsigned V_24 , int V_25 )
{
struct V_26 V_27 = {
. V_28 = V_22 ,
. V_29 = V_23 ,
. V_24 = V_24 ,
. V_30 = V_25 ,
} ;
return F_15 ( & V_27 , V_31 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_26 * V_27 , struct V_32 * V_33 )
{
struct V_15 * V_15 = F_5 ( V_2 ) ;
struct V_34 * V_35 = & V_15 -> V_17 . V_35 ;
switch ( V_33 -> V_36 ) {
case V_37 :
if ( ! V_35 -> V_38 )
V_35 -> V_38 = V_27 -> V_39 [ 0 ] ;
break;
}
}
static void F_17 ( struct V_1 * V_2 ,
struct V_26 * V_27 , struct V_32 * V_33 )
{
struct V_15 * V_15 = F_5 ( V_2 ) ;
struct V_34 * V_35 = & V_15 -> V_17 . V_35 ;
bool V_40 = ( V_27 -> V_41 == V_42 ) ||
( V_27 -> V_43 == V_42 ) ;
bool V_44 = ( V_27 -> V_41 == V_45 ) ||
( V_27 -> V_43 == V_45 ) ;
if ( ! V_44 && ! V_40 )
return;
if ( V_40 && ! V_35 -> V_38 )
V_35 -> V_38 = 1 ;
switch ( V_33 -> V_36 ) {
case V_46 :
V_35 -> V_47 = V_27 -> V_28 ;
if ( V_40 ) {
V_35 -> V_48 = V_49 ;
V_35 -> V_50 = V_27 -> V_29 ;
if ( V_35 -> type != V_51 ) {
V_35 -> V_24 = V_27 -> V_24 ;
V_35 -> V_52 = V_27 -> V_30 ;
}
} else {
V_35 -> V_48 = V_53 ;
}
break;
case V_54 :
V_35 -> V_55 = V_27 -> V_28 ;
if ( V_40 ) {
V_35 -> V_56 = V_27 -> V_29 ;
if ( V_35 -> type != V_51 ) {
V_35 -> V_24 = V_27 -> V_24 ;
V_35 -> V_52 = V_27 -> V_30 ;
}
}
break;
case V_57 :
if ( V_44 )
V_35 -> V_58 = V_27 -> V_28 ;
break;
}
}
static void F_18 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
struct V_59 * V_60 ;
struct V_12 * V_61 ;
int V_62 , V_63 ;
V_60 = & V_2 -> V_64 [ V_65 ] ;
F_19 (hreport, &rep_enum->report_list, list) {
for ( V_62 = 0 ; V_62 < V_61 -> V_66 ; V_62 ++ ) {
if ( V_61 -> V_27 [ V_62 ] -> V_67 < 1 )
continue;
for ( V_63 = 0 ; V_63 < V_61 -> V_27 [ V_62 ] -> V_68 ; V_63 ++ ) {
F_16 ( V_2 , V_61 -> V_27 [ V_62 ] ,
V_61 -> V_27 [ V_62 ] -> V_33 + V_63 ) ;
}
}
}
V_60 = & V_2 -> V_64 [ V_69 ] ;
F_19 (hreport, &rep_enum->report_list, list) {
if ( ! V_61 -> V_66 )
continue;
for ( V_62 = 0 ; V_62 < V_61 -> V_66 ; V_62 ++ )
for ( V_63 = 0 ; V_63 < V_61 -> V_27 [ V_62 ] -> V_68 ; V_63 ++ )
F_17 ( V_2 , V_61 -> V_27 [ V_62 ] ,
V_61 -> V_27 [ V_62 ] -> V_33 + V_63 ) ;
}
}
static int F_20 ( struct V_1 * V_2 , int V_70 ,
int V_71 , int V_72 )
{
unsigned char * V_73 ;
int error = - V_74 , V_75 = 0 ;
V_73 = F_21 ( V_71 , V_76 ) ;
if ( ! V_73 )
return error ;
do {
V_73 [ 0 ] = V_70 ;
V_73 [ 1 ] = V_72 ;
error = F_3 ( V_2 , V_65 , V_73 ,
V_71 , 1 ) ;
if ( error >= 0 )
error = F_1 ( V_2 , V_65 ,
V_70 , V_73 , V_71 , 1 ) ;
} while ( ( error < 0 || V_73 [ 1 ] != V_72 ) && V_75 ++ < V_77 );
F_22 ( V_73 ) ;
return error < 0 ? error : 0 ;
}
static int F_23 ( struct V_1 * V_2 , T_1 V_78 ,
struct V_34 * V_35 )
{
struct V_15 * V_15 = F_5 ( V_2 ) ;
int V_79 ;
T_1 V_73 [ 2 ] ;
switch ( V_35 -> type ) {
case V_80 :
V_73 [ 0 ] = 0x03 ;
V_73 [ 1 ] = 0x00 ;
V_79 = F_3 ( V_2 , V_65 , V_73 , 2 ,
3 ) ;
if ( V_79 >= 0 ) {
V_73 [ 0 ] = V_78 == 0 ? 0x05 : 0x06 ;
V_73 [ 1 ] = 0x00 ;
V_79 = F_3 ( V_2 , V_65 ,
V_73 , 2 , 3 ) ;
if ( V_79 >= 0 ) {
V_15 -> V_17 . V_81 = V_78 ;
return 0 ;
}
}
F_24 ( V_2 , L_1 ,
V_73 [ 0 ] , V_79 ) ;
break;
case V_82 :
if ( V_78 == 1 )
V_15 -> V_17 . V_83 &= ~ 0x20 ;
else
V_15 -> V_17 . V_83 |= 0x20 ;
V_73 [ 0 ] = 0x03 ;
V_73 [ 1 ] = V_15 -> V_17 . V_83 ;
V_79 = F_3 ( V_2 , V_65 , V_73 , 2 ,
1 ) ;
if ( V_79 >= 0 )
V_15 -> V_17 . V_81 = V_78 ;
break;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
if ( V_2 -> V_84 == V_85 )
return F_23 ( V_2 , 1 , V_35 ) ;
if ( V_35 -> V_48 == V_49 ) {
if ( V_35 -> type > V_86 ) {
return F_20 ( V_2 , 3 , 4 , 4 ) ;
}
else if ( V_35 -> type == V_87 || V_35 -> type == V_88 ) {
return F_20 ( V_2 , 18 , 3 , 2 ) ;
}
} else if ( V_35 -> V_48 == V_53 ) {
if ( V_35 -> type <= V_51 && V_35 -> type != V_89 ) {
return F_20 ( V_2 , 2 , 2 , 2 ) ;
}
}
return 0 ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
struct V_15 * V_15 = F_5 ( V_2 ) ;
struct V_90 * V_91 = V_15 -> V_91 ;
V_35 -> V_48 = V_53 ;
V_35 -> V_92 = 4 ;
V_35 -> V_93 = 4 ;
V_35 -> V_94 = 0 ;
V_35 -> V_95 = 0 ;
if ( V_35 -> type == V_89 ) {
if ( V_91 -> V_96 -> V_97 . V_98 == 0 ) {
V_35 -> V_48 = 0 ;
} else if ( V_91 -> V_96 -> V_97 . V_98 == 2 ) {
V_35 -> V_48 = V_49 ;
V_35 -> V_99 = V_100 ;
}
}
if ( V_35 -> type < V_51 )
return;
F_18 ( V_2 , V_35 ) ;
}
static bool F_27 ( struct V_1 * V_2 ,
struct V_1 * V_101 )
{
struct V_15 * V_15 = F_5 ( V_2 ) ;
struct V_34 * V_35 = & V_15 -> V_17 . V_35 ;
int V_102 = V_35 -> V_103 ;
int V_104 = V_35 -> V_105 ;
int V_106 , V_107 ;
if ( V_102 == 0 && V_104 == 0 ) {
V_102 = V_2 -> V_108 ;
V_104 = V_2 -> V_109 ;
}
if ( V_102 != V_101 -> V_108 || V_104 != V_101 -> V_109 )
return false ;
V_106 = strrchr ( V_2 -> V_110 , '.' ) - V_2 -> V_110 ;
V_107 = strrchr ( V_101 -> V_110 , '.' ) - V_101 -> V_110 ;
if ( V_106 != V_107 || V_106 <= 0 || V_107 <= 0 )
return false ;
return ! strncmp ( V_2 -> V_110 , V_101 -> V_110 , V_106 ) ;
}
static struct V_111 * F_28 ( struct V_1 * V_2 )
{
struct V_111 * V_18 ;
F_19 (data, &wacom_udev_list, list) {
if ( F_27 ( V_2 , V_18 -> V_20 ) ) {
F_29 ( & V_18 -> V_112 ) ;
return V_18 ;
}
}
return NULL ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_15 * V_15 = F_5 ( V_2 ) ;
struct V_17 * V_17 = & V_15 -> V_17 ;
struct V_111 * V_18 ;
int V_7 = 0 ;
F_9 ( & V_113 ) ;
V_18 = F_28 ( V_2 ) ;
if ( ! V_18 ) {
V_18 = F_21 ( sizeof( struct V_111 ) , V_76 ) ;
if ( ! V_18 ) {
V_7 = - V_74 ;
goto V_114;
}
F_31 ( & V_18 -> V_112 ) ;
V_18 -> V_20 = V_2 ;
F_32 ( & V_18 -> V_115 , & V_116 ) ;
}
V_17 -> V_117 = & V_18 -> V_117 ;
V_114:
F_11 ( & V_113 ) ;
return V_7 ;
}
static void F_33 ( struct V_112 * V_112 )
{
struct V_111 * V_18 =
F_34 ( V_112 , struct V_111 , V_112 ) ;
F_9 ( & V_113 ) ;
F_35 ( & V_18 -> V_115 ) ;
F_11 ( & V_113 ) ;
F_22 ( V_18 ) ;
}
static void F_36 ( struct V_17 * V_15 )
{
struct V_111 * V_18 ;
if ( V_15 -> V_117 ) {
V_18 = F_34 ( V_15 -> V_117 , struct V_111 , V_117 ) ;
F_37 ( & V_18 -> V_112 , F_33 ) ;
V_15 -> V_117 = NULL ;
}
}
static int F_38 ( struct V_15 * V_15 )
{
unsigned char * V_4 ;
int V_7 ;
V_4 = F_21 ( 9 , V_76 ) ;
if ( ! V_4 )
return - V_74 ;
if ( V_15 -> V_17 . V_35 . type >= V_118 &&
V_15 -> V_17 . V_35 . type <= V_119 ) {
int V_120 = V_15 -> V_121 . V_122 [ 0 ] & 0x03 ;
int V_123 = ( ( ( V_15 -> V_121 . V_124 & 0x60 ) >> 5 ) - 1 ) & 0x03 ;
int V_125 = 0 ;
V_4 [ 0 ] = V_126 ;
V_4 [ 1 ] = ( V_125 << 4 ) | ( V_123 << 2 ) | ( V_120 ) ;
}
else {
int V_121 = V_15 -> V_121 . V_122 [ 0 ] | 0x4 ;
if ( V_15 -> V_17 . V_35 . type == V_127 ||
V_15 -> V_17 . V_35 . type == V_128 )
V_121 |= ( V_15 -> V_121 . V_122 [ 1 ] << 4 ) | 0x40 ;
V_4 [ 0 ] = V_126 ;
V_4 [ 1 ] = V_121 ;
V_4 [ 2 ] = V_15 -> V_121 . V_124 ;
V_4 [ 3 ] = V_15 -> V_121 . V_129 ;
V_4 [ 4 ] = V_15 -> V_121 . V_130 ;
}
V_7 = F_3 ( V_15 -> V_2 , V_65 , V_4 , 9 ,
V_131 ) ;
F_22 ( V_4 ) ;
return V_7 ;
}
static int F_39 ( struct V_15 * V_15 , int V_132 , T_1 V_133 ,
const unsigned V_134 , const void * V_135 )
{
unsigned char * V_4 ;
int V_62 , V_7 ;
const unsigned V_136 = V_134 / 4 ;
V_4 = F_21 ( V_136 + 3 , V_76 ) ;
if ( ! V_4 )
return - V_74 ;
V_4 [ 0 ] = V_137 ;
V_4 [ 1 ] = 1 ;
V_7 = F_3 ( V_15 -> V_2 , V_65 , V_4 , 2 ,
V_131 ) ;
if ( V_7 < 0 )
goto V_114;
V_4 [ 0 ] = V_133 ;
V_4 [ 1 ] = V_132 & 0x07 ;
for ( V_62 = 0 ; V_62 < 4 ; V_62 ++ ) {
V_4 [ 2 ] = V_62 ;
memcpy ( V_4 + 3 , V_135 + V_62 * V_136 , V_136 ) ;
V_7 = F_3 ( V_15 -> V_2 , V_65 ,
V_4 , V_136 + 3 , V_131 ) ;
if ( V_7 < 0 )
break;
}
V_4 [ 0 ] = V_137 ;
V_4 [ 1 ] = 0 ;
F_3 ( V_15 -> V_2 , V_65 , V_4 , 2 ,
V_131 ) ;
V_114:
F_22 ( V_4 ) ;
return V_7 ;
}
static T_3 F_40 ( struct V_138 * V_20 , int V_139 ,
const char * V_4 , T_2 V_140 )
{
struct V_1 * V_2 = F_34 ( V_20 , struct V_1 , V_20 ) ;
struct V_15 * V_15 = F_5 ( V_2 ) ;
unsigned int V_3 ;
int V_141 ;
V_141 = F_41 ( V_4 , 10 , & V_3 ) ;
if ( V_141 )
return V_141 ;
F_9 ( & V_15 -> V_21 ) ;
V_15 -> V_121 . V_122 [ V_139 ] = V_3 & 0x3 ;
V_141 = F_38 ( V_15 ) ;
F_11 ( & V_15 -> V_21 ) ;
return V_141 < 0 ? V_141 : V_140 ;
}
static T_3 F_42 ( struct V_15 * V_15 , T_1 * V_142 ,
const char * V_4 , T_2 V_140 )
{
unsigned int V_39 ;
int V_141 ;
V_141 = F_41 ( V_4 , 10 , & V_39 ) ;
if ( V_141 )
return V_141 ;
F_9 ( & V_15 -> V_21 ) ;
* V_142 = V_39 & 0x7f ;
V_141 = F_38 ( V_15 ) ;
F_11 ( & V_15 -> V_21 ) ;
return V_141 < 0 ? V_141 : V_140 ;
}
static T_3 F_43 ( struct V_138 * V_20 , int V_132 ,
const char * V_4 , T_2 V_140 )
{
struct V_1 * V_2 = F_34 ( V_20 , struct V_1 , V_20 ) ;
struct V_15 * V_15 = F_5 ( V_2 ) ;
int V_141 ;
unsigned V_134 ;
T_1 V_133 ;
if ( V_2 -> V_84 == V_85 ) {
V_134 = 256 ;
V_133 = V_143 ;
} else {
V_134 = 1024 ;
V_133 = V_144 ;
}
if ( V_140 != V_134 )
return - V_145 ;
F_9 ( & V_15 -> V_21 ) ;
V_141 = F_39 ( V_15 , V_132 , V_133 , V_134 , V_4 ) ;
F_11 ( & V_15 -> V_21 ) ;
return V_141 < 0 ? V_141 : V_140 ;
}
static int F_44 ( struct V_15 * V_15 )
{
int error ;
switch ( V_15 -> V_17 . V_35 . type ) {
case V_146 :
case V_147 :
case V_82 :
case V_148 :
V_15 -> V_121 . V_122 [ 0 ] = 0 ;
V_15 -> V_121 . V_122 [ 1 ] = 0 ;
V_15 -> V_121 . V_124 = 10 ;
V_15 -> V_121 . V_129 = 20 ;
V_15 -> V_121 . V_130 = 10 ;
error = F_45 ( & V_15 -> V_2 -> V_20 . V_149 ,
& V_150 ) ;
break;
case V_128 :
case V_127 :
V_15 -> V_121 . V_122 [ 0 ] = 0 ;
V_15 -> V_121 . V_122 [ 1 ] = 0 ;
V_15 -> V_121 . V_124 = 0 ;
V_15 -> V_121 . V_129 = 0 ;
V_15 -> V_121 . V_130 = 0 ;
error = F_45 ( & V_15 -> V_2 -> V_20 . V_149 ,
& V_151 ) ;
break;
case V_118 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_119 :
if ( V_15 -> V_17 . V_35 . V_48 == V_53 ) {
V_15 -> V_121 . V_122 [ 0 ] = 0 ;
V_15 -> V_121 . V_122 [ 1 ] = 0 ;
V_15 -> V_121 . V_124 = 32 ;
V_15 -> V_121 . V_129 = 0 ;
V_15 -> V_121 . V_130 = 0 ;
error = F_45 ( & V_15 -> V_2 -> V_20 . V_149 ,
& V_156 ) ;
} else
return 0 ;
break;
default:
return 0 ;
}
if ( error ) {
F_46 ( V_15 -> V_2 ,
L_2 , error ) ;
return error ;
}
F_38 ( V_15 ) ;
V_15 -> V_157 = true ;
return 0 ;
}
static void F_47 ( struct V_15 * V_15 )
{
if ( ! V_15 -> V_157 )
return;
V_15 -> V_157 = false ;
switch ( V_15 -> V_17 . V_35 . type ) {
case V_146 :
case V_147 :
case V_82 :
case V_148 :
F_48 ( & V_15 -> V_2 -> V_20 . V_149 ,
& V_150 ) ;
break;
case V_128 :
case V_127 :
F_48 ( & V_15 -> V_2 -> V_20 . V_149 ,
& V_151 ) ;
break;
case V_118 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_119 :
if ( V_15 -> V_17 . V_35 . V_48 == V_53 )
F_48 ( & V_15 -> V_2 -> V_20 . V_149 ,
& V_156 ) ;
break;
}
}
static int F_49 ( struct V_158 * V_159 ,
enum V_160 V_161 ,
union V_162 * V_163 )
{
struct V_15 * V_15 = F_34 ( V_159 , struct V_15 , V_164 ) ;
int V_79 = 0 ;
switch ( V_161 ) {
case V_165 :
V_163 -> V_166 = V_167 ;
break;
case V_168 :
V_163 -> V_166 =
V_15 -> V_17 . V_169 ;
break;
case V_170 :
if ( V_15 -> V_17 . V_171 )
V_163 -> V_166 = V_172 ;
else if ( V_15 -> V_17 . V_169 == 100 &&
V_15 -> V_17 . V_173 )
V_163 -> V_166 = V_174 ;
else
V_163 -> V_166 = V_175 ;
break;
default:
V_79 = - V_145 ;
break;
}
return V_79 ;
}
static int F_50 ( struct V_158 * V_159 ,
enum V_160 V_161 ,
union V_162 * V_163 )
{
struct V_15 * V_15 = F_34 ( V_159 , struct V_15 , V_176 ) ;
int V_79 = 0 ;
switch ( V_161 ) {
case V_177 :
case V_178 :
V_163 -> V_166 = V_15 -> V_17 . V_173 ;
break;
case V_165 :
V_163 -> V_166 = V_167 ;
break;
default:
V_79 = - V_145 ;
break;
}
return V_79 ;
}
static int F_51 ( struct V_15 * V_15 )
{
static T_4 V_179 = F_52 ( 0 ) ;
int error ;
unsigned long V_180 ;
if ( V_15 -> V_17 . V_35 . V_181 & V_182 ) {
V_180 = F_53 ( & V_179 ) - 1 ;
V_15 -> V_164 . V_183 = V_184 ;
V_15 -> V_164 . V_185 = F_54 ( V_184 ) ;
V_15 -> V_164 . V_186 = F_49 ;
sprintf ( V_15 -> V_17 . V_187 , L_3 , V_180 ) ;
V_15 -> V_164 . V_188 = V_15 -> V_17 . V_187 ;
V_15 -> V_164 . type = V_189 ;
V_15 -> V_164 . V_190 = 0 ;
V_15 -> V_176 . V_183 = V_191 ;
V_15 -> V_176 . V_185 = F_54 ( V_191 ) ;
V_15 -> V_176 . V_186 = F_50 ;
sprintf ( V_15 -> V_17 . V_192 , L_4 , V_180 ) ;
V_15 -> V_176 . V_188 = V_15 -> V_17 . V_192 ;
V_15 -> V_176 . type = V_193 ;
V_15 -> V_176 . V_190 = 0 ;
error = F_55 ( & V_15 -> V_2 -> V_20 ,
& V_15 -> V_164 ) ;
if ( error )
return error ;
F_56 ( & V_15 -> V_164 , & V_15 -> V_2 -> V_20 ) ;
error = F_55 ( & V_15 -> V_2 -> V_20 , & V_15 -> V_176 ) ;
if ( error ) {
F_57 ( & V_15 -> V_164 ) ;
return error ;
}
F_56 ( & V_15 -> V_176 , & V_15 -> V_2 -> V_20 ) ;
}
return 0 ;
}
static void F_58 ( struct V_15 * V_15 )
{
if ( ( V_15 -> V_17 . V_35 . V_181 & V_182 ) &&
V_15 -> V_164 . V_20 ) {
F_57 ( & V_15 -> V_164 ) ;
V_15 -> V_164 . V_20 = NULL ;
F_57 ( & V_15 -> V_176 ) ;
V_15 -> V_176 . V_20 = NULL ;
}
}
static T_3 F_59 ( struct V_138 * V_20 ,
struct V_194
* V_195 , char * V_4 )
{
struct V_1 * V_2 = F_34 ( V_20 , struct V_1 , V_20 ) ;
struct V_15 * V_15 = F_5 ( V_2 ) ;
return snprintf ( V_4 , V_196 , L_5 , V_15 -> V_17 . V_81 ) ;
}
static T_3 F_60 ( struct V_138 * V_20 ,
struct V_194 * V_195 ,
const char * V_4 , T_2 V_140 )
{
struct V_1 * V_2 = F_34 ( V_20 , struct V_1 , V_20 ) ;
struct V_15 * V_15 = F_5 ( V_2 ) ;
T_1 V_197 ;
if ( F_61 ( V_4 , 0 , & V_197 ) )
return - V_145 ;
if ( V_197 != 0 && V_197 != 1 )
return - V_145 ;
F_23 ( V_2 , V_197 , & V_15 -> V_17 . V_35 ) ;
return V_140 ;
}
static struct V_19 * F_62 ( struct V_15 * V_15 )
{
struct V_19 * V_19 ;
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_17 * V_17 = & ( V_15 -> V_17 ) ;
V_19 = F_63 () ;
if ( ! V_19 )
return NULL ;
V_19 -> V_188 = V_17 -> V_188 ;
V_19 -> V_110 = V_2 -> V_110 ;
V_19 -> V_20 . V_198 = & V_2 -> V_20 ;
V_19 -> V_199 = F_7 ;
V_19 -> V_200 = F_12 ;
V_19 -> V_201 = V_2 -> V_201 ;
V_19 -> V_3 . V_202 = V_2 -> V_84 ;
V_19 -> V_3 . V_108 = V_2 -> V_108 ;
V_19 -> V_3 . V_109 = V_2 -> V_109 ;
V_19 -> V_3 . V_203 = V_2 -> V_203 ;
F_64 ( V_19 , V_15 ) ;
return V_19 ;
}
static void F_65 ( struct V_15 * V_15 )
{
if ( V_15 -> V_17 . V_204 )
F_66 ( V_15 -> V_17 . V_204 ) ;
if ( V_15 -> V_17 . V_205 )
F_66 ( V_15 -> V_17 . V_205 ) ;
V_15 -> V_17 . V_204 = NULL ;
V_15 -> V_17 . V_205 = NULL ;
}
static int F_67 ( struct V_15 * V_15 )
{
struct V_19 * V_19 , * V_206 ;
struct V_17 * V_17 = & ( V_15 -> V_17 ) ;
int error ;
V_19 = F_62 ( V_15 ) ;
V_206 = F_62 ( V_15 ) ;
if ( ! V_19 || ! V_206 ) {
error = - V_74 ;
goto V_207;
}
V_17 -> V_204 = V_19 ;
V_17 -> V_205 = V_206 ;
V_17 -> V_205 -> V_188 = V_17 -> V_208 ;
error = F_68 ( V_19 , V_17 ) ;
if ( error )
goto V_209;
error = F_69 ( V_19 ) ;
if ( error )
goto V_209;
error = F_70 ( V_206 , V_17 ) ;
if ( error ) {
F_71 ( V_206 ) ;
V_17 -> V_205 = NULL ;
V_206 = NULL ;
} else {
error = F_69 ( V_206 ) ;
if ( error )
goto V_210;
}
return 0 ;
V_210:
F_66 ( V_19 ) ;
V_19 = NULL ;
V_209:
V_17 -> V_204 = NULL ;
V_17 -> V_205 = NULL ;
V_207:
if ( V_19 )
F_71 ( V_19 ) ;
if ( V_206 )
F_71 ( V_206 ) ;
return error ;
}
static void F_72 ( struct V_211 * V_212 )
{
struct V_15 * V_15 = F_34 ( V_212 , struct V_15 , V_212 ) ;
struct V_213 * V_214 = V_15 -> V_214 ;
struct V_17 * V_17 = & V_15 -> V_17 ;
struct V_1 * V_215 , * V_216 ;
struct V_15 * V_217 , * V_218 ;
struct V_17 * V_219 , * V_220 ;
int error ;
F_58 ( V_15 ) ;
V_215 = F_73 ( V_214 -> V_221 -> V_222 [ 1 ] ) ;
V_217 = F_5 ( V_215 ) ;
V_219 = & ( V_217 -> V_17 ) ;
F_65 ( V_217 ) ;
V_216 = F_73 ( V_214 -> V_221 -> V_222 [ 2 ] ) ;
V_218 = F_5 ( V_216 ) ;
V_220 = & ( V_218 -> V_17 ) ;
F_65 ( V_218 ) ;
if ( V_17 -> V_104 == 0 ) {
F_74 ( V_15 -> V_2 , L_6 ) ;
V_219 -> V_117 -> type = 0 ;
} else {
const struct V_223 * V_3 = V_224 ;
F_74 ( V_15 -> V_2 , L_7 ,
V_17 -> V_104 ) ;
while ( V_3 -> V_84 ) {
if ( V_3 -> V_108 == V_225 &&
V_3 -> V_109 == V_17 -> V_104 )
break;
V_3 ++ ;
}
if ( ! V_3 -> V_84 ) {
F_74 ( V_15 -> V_2 , L_8 ) ;
return;
}
V_219 -> V_35 =
* ( (struct V_34 * ) V_3 -> V_226 ) ;
V_219 -> V_35 . V_48 = V_53 ;
snprintf ( V_219 -> V_188 , V_227 , L_9 ,
V_219 -> V_35 . V_188 ) ;
snprintf ( V_219 -> V_208 , V_227 , L_10 ,
V_219 -> V_35 . V_188 ) ;
V_219 -> V_117 -> V_38 = V_219 -> V_35 . V_38 ;
V_219 -> V_117 -> type = V_219 -> V_35 . type ;
error = F_67 ( V_217 ) ;
if ( error )
goto V_228;
if ( V_219 -> V_35 . V_38 ||
V_219 -> V_35 . type == V_229 ) {
V_220 -> V_35 =
* ( (struct V_34 * ) V_3 -> V_226 ) ;
V_220 -> V_35 . V_99 = V_100 ;
V_220 -> V_35 . V_48 = V_49 ;
V_220 -> V_35 . V_47 = V_220 -> V_35 . V_55 = 4096 ;
if ( V_220 -> V_35 . V_38 )
snprintf ( V_220 -> V_188 , V_227 ,
L_11 , V_220 -> V_35 . V_188 ) ;
else
snprintf ( V_220 -> V_188 , V_227 ,
L_10 , V_220 -> V_35 . V_188 ) ;
snprintf ( V_220 -> V_208 , V_227 ,
L_10 , V_220 -> V_35 . V_188 ) ;
error = F_67 ( V_218 ) ;
if ( error )
goto V_228;
if ( V_219 -> V_35 . type == V_229 &&
V_219 -> V_35 . V_38 )
V_17 -> V_117 -> V_230 = V_220 -> V_204 ;
}
error = F_51 ( V_15 ) ;
if ( error )
goto V_228;
}
return;
V_228:
F_65 ( V_217 ) ;
F_65 ( V_218 ) ;
return;
}
static void F_75 ( struct V_34 * V_35 )
{
if ( V_35 -> V_231 ) {
V_35 -> V_50 = ( V_35 -> V_47 * 100 ) /
V_35 -> V_231 ;
V_35 -> V_56 = ( V_35 -> V_55 * 100 ) /
V_35 -> V_232 ;
}
}
static void F_76 ( struct V_34 * V_35 )
{
V_35 -> V_231 = F_14 ( V_35 -> V_47 ,
V_35 -> V_50 ,
V_35 -> V_24 ,
V_35 -> V_52 ) ;
V_35 -> V_232 = F_14 ( V_35 -> V_55 ,
V_35 -> V_56 ,
V_35 -> V_24 ,
V_35 -> V_52 ) ;
}
static int F_77 ( struct V_12 * V_13 )
{
return ( ( V_13 -> V_5 - 1 ) >> 3 ) + 1 + ( V_13 -> V_3 > 0 ) ;
}
static T_2 F_78 ( struct V_1 * V_2 )
{
struct V_59 * V_64 ;
struct V_12 * V_13 ;
T_2 V_5 = 0 ;
V_64 = V_2 -> V_64 + V_69 ;
F_19 (report, &report_enum->report_list, list) {
T_2 V_233 = F_77 ( V_13 ) ;
if ( V_233 > V_5 )
V_5 = V_233 ;
}
return V_5 ;
}
static int F_79 ( struct V_1 * V_2 ,
const struct V_223 * V_3 )
{
struct V_90 * V_91 = F_80 ( V_2 -> V_20 . V_198 ) ;
struct V_213 * V_20 = F_81 ( V_91 ) ;
struct V_15 * V_15 ;
struct V_17 * V_17 ;
struct V_34 * V_35 ;
int error ;
if ( ! V_3 -> V_226 )
return - V_145 ;
V_15 = F_21 ( sizeof( struct V_15 ) , V_76 ) ;
if ( ! V_15 )
return - V_74 ;
F_82 ( V_2 , V_15 ) ;
V_15 -> V_2 = V_2 ;
error = F_83 ( V_2 ) ;
if ( error ) {
F_46 ( V_2 , L_12 ) ;
goto V_207;
}
V_17 = & V_15 -> V_17 ;
V_17 -> V_35 = * ( (struct V_34 * ) V_3 -> V_226 ) ;
V_35 = & V_17 -> V_35 ;
V_35 -> V_99 = F_78 ( V_2 ) ;
if ( V_35 -> V_99 > V_16 ) {
error = - V_145 ;
goto V_207;
}
if ( V_35 -> V_234 && V_35 -> V_235 != V_2 -> type ) {
error = - V_236 ;
goto V_207;
}
V_15 -> V_214 = V_20 ;
V_15 -> V_91 = V_91 ;
F_84 ( & V_15 -> V_21 ) ;
F_85 ( & V_15 -> V_212 , F_72 ) ;
F_75 ( V_35 ) ;
F_26 ( V_2 , V_35 ) ;
if ( V_35 -> type >= V_118 && V_35 -> type <= V_229 ) {
if ( V_35 -> V_99 == V_100 ) {
V_35 -> V_48 = V_49 ;
V_35 -> V_47 = 4096 ;
V_35 -> V_55 = 4096 ;
} else {
V_35 -> V_48 = V_53 ;
}
}
if ( ( V_35 -> type == V_51 ) &&
( V_35 -> V_99 == V_100 ) &&
( V_35 -> V_48 == V_53 ) ) {
V_35 -> V_48 = V_49 ;
V_35 -> V_47 = 4096 ;
V_35 -> V_55 = 4096 ;
}
if ( V_2 -> V_84 == V_85 )
V_35 -> V_181 |= V_182 ;
F_86 ( V_35 ) ;
if ( ! V_35 -> V_24 ) {
V_35 -> V_24 = 0x11 ;
V_35 -> V_52 = - 3 ;
}
F_76 ( V_35 ) ;
F_87 ( V_17 -> V_188 , V_35 -> V_188 , sizeof( V_17 -> V_188 ) ) ;
snprintf ( V_17 -> V_208 , sizeof( V_17 -> V_208 ) ,
L_13 , V_35 -> V_188 ) ;
if ( V_35 -> V_181 & V_237 ) {
if ( V_35 -> V_48 != V_49 )
F_88 ( V_17 -> V_188 , L_14 , V_227 ) ;
else if ( V_35 -> V_38 )
F_88 ( V_17 -> V_188 , L_15 , V_227 ) ;
else
F_88 ( V_17 -> V_188 , L_16 , V_227 ) ;
error = F_30 ( V_2 ) ;
if ( error )
goto V_207;
}
error = F_44 ( V_15 ) ;
if ( error )
goto V_209;
if ( ! ( V_35 -> V_181 & V_238 ) &&
( V_35 -> V_181 & V_182 ) ) {
error = F_51 ( V_15 ) ;
if ( error )
goto V_210;
}
if ( ! ( V_35 -> V_181 & V_239 ) ) {
error = F_67 ( V_15 ) ;
if ( error )
goto V_240;
}
if ( V_2 -> V_84 == V_85 ) {
error = F_89 ( & V_2 -> V_20 , & V_241 ) ;
if ( error )
F_24 ( V_2 ,
L_17 ,
error ) ;
}
F_25 ( V_2 , V_35 ) ;
error = F_90 ( V_2 , V_242 ) ;
if ( error ) {
F_46 ( V_2 , L_18 ) ;
goto V_243;
}
if ( V_35 -> V_181 & V_238 )
error = F_10 ( V_2 ) ;
if ( V_17 -> V_35 . type == V_229 && V_17 -> V_35 . V_38 ) {
if ( V_17 -> V_35 . V_48 == V_49 )
V_17 -> V_117 -> V_230 = V_17 -> V_204 ;
}
return 0 ;
V_243: if ( V_2 -> V_84 == V_85 )
F_91 ( & V_2 -> V_20 , & V_241 ) ;
F_65 ( V_15 ) ;
V_240: F_58 ( V_15 ) ;
V_210: F_47 ( V_15 ) ;
V_209: F_36 ( V_17 ) ;
V_207: F_22 ( V_15 ) ;
F_82 ( V_2 , NULL ) ;
return error ;
}
static void F_92 ( struct V_1 * V_2 )
{
struct V_15 * V_15 = F_5 ( V_2 ) ;
F_93 ( V_2 ) ;
F_94 ( & V_15 -> V_212 ) ;
F_65 ( V_15 ) ;
if ( V_2 -> V_84 == V_85 )
F_91 ( & V_2 -> V_20 , & V_241 ) ;
F_58 ( V_15 ) ;
F_47 ( V_15 ) ;
F_36 ( & V_15 -> V_17 ) ;
F_82 ( V_2 , NULL ) ;
F_22 ( V_15 ) ;
}
static int F_95 ( struct V_1 * V_2 )
{
struct V_15 * V_15 = F_5 ( V_2 ) ;
struct V_34 * V_35 = & V_15 -> V_17 . V_35 ;
F_9 ( & V_15 -> V_21 ) ;
F_25 ( V_2 , V_35 ) ;
F_38 ( V_15 ) ;
F_11 ( & V_15 -> V_21 ) ;
return 0 ;
}
static int F_96 ( struct V_1 * V_2 )
{
return F_95 ( V_2 ) ;
}
