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
case V_48 :
if ( V_25 -> V_12 -> V_40 == 0x0B &&
( V_25 -> V_49 == V_50 ||
V_25 -> V_49 == V_51 ) ) {
V_14 -> V_16 . V_52 = V_25 -> V_12 -> V_40 ;
V_14 -> V_16 . V_53 = 0 ;
}
break;
case V_54 :
case V_55 :
if ( V_25 -> V_12 -> V_40 == 0x03 &&
( V_25 -> V_49 == V_56 ||
V_25 -> V_49 == V_57 ) ) {
V_14 -> V_16 . V_52 = V_25 -> V_12 -> V_40 ;
V_14 -> V_16 . V_53 = 0 ;
}
break;
}
}
static void F_20 ( struct V_1 * V_2 ,
struct V_24 * V_25 , struct V_30 * V_31 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_32 * V_33 = & V_14 -> V_16 . V_33 ;
bool V_58 = F_21 ( V_25 ) ;
bool V_59 = F_22 ( V_25 ) ;
if ( V_59 )
V_33 -> V_60 |= V_61 ;
else if ( V_58 )
V_33 -> V_60 |= V_62 ;
else
return;
if ( V_33 -> type > V_63 ) {
if ( V_58 && ! V_33 -> V_38 )
V_33 -> V_38 = 1 ;
}
switch ( V_31 -> V_36 ) {
case V_64 :
V_33 -> V_65 = V_25 -> V_26 ;
if ( V_58 ) {
V_33 -> V_66 = V_25 -> V_27 ;
if ( ( V_33 -> type != V_63 ) &&
( V_33 -> type != V_67 ) ) {
V_33 -> V_22 = V_25 -> V_22 ;
V_33 -> V_68 = V_25 -> V_28 ;
}
}
break;
case V_69 :
V_33 -> V_70 = V_25 -> V_26 ;
if ( V_58 ) {
V_33 -> V_71 = V_25 -> V_27 ;
if ( ( V_33 -> type != V_63 ) &&
( V_33 -> type != V_67 ) ) {
V_33 -> V_22 = V_25 -> V_22 ;
V_33 -> V_68 = V_25 -> V_28 ;
}
}
break;
case V_72 :
if ( V_59 )
V_33 -> V_73 = V_25 -> V_26 ;
break;
}
if ( V_33 -> type == V_74 )
F_23 ( V_2 , V_25 , V_31 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_16 * V_16 = & V_14 -> V_16 ;
if ( V_33 -> type == V_74 ) {
if ( V_33 -> V_38 > 1 ) {
F_25 ( V_16 -> V_75 , V_16 -> V_33 . V_38 ,
V_76 ) ;
}
}
}
static void F_26 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_77 * V_78 ;
struct V_11 * V_79 ;
int V_80 , V_81 ;
V_78 = & V_2 -> V_82 [ V_41 ] ;
F_27 (hreport, &rep_enum->report_list, list) {
for ( V_80 = 0 ; V_80 < V_79 -> V_83 ; V_80 ++ ) {
if ( V_79 -> V_25 [ V_80 ] -> V_45 < 1 )
continue;
for ( V_81 = 0 ; V_81 < V_79 -> V_25 [ V_80 ] -> V_84 ; V_81 ++ ) {
F_15 ( V_2 , V_79 -> V_25 [ V_80 ] ,
V_79 -> V_25 [ V_80 ] -> V_31 + V_81 ) ;
}
}
}
V_78 = & V_2 -> V_82 [ V_85 ] ;
F_27 (hreport, &rep_enum->report_list, list) {
if ( ! V_79 -> V_83 )
continue;
for ( V_80 = 0 ; V_80 < V_79 -> V_83 ; V_80 ++ )
for ( V_81 = 0 ; V_81 < V_79 -> V_25 [ V_80 ] -> V_84 ; V_81 ++ )
F_20 ( V_2 , V_79 -> V_25 [ V_80 ] ,
V_79 -> V_25 [ V_80 ] -> V_31 + V_81 ) ;
}
F_24 ( V_2 , V_33 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_34 * V_34 = & V_14 -> V_16 . V_34 ;
struct V_11 * V_86 ;
struct V_77 * V_87 ;
if ( V_34 -> V_46 < 0 )
return 0 ;
V_87 = & ( V_2 -> V_82 [ V_41 ] ) ;
V_86 = V_87 -> V_88 [ V_34 -> V_46 ] ;
if ( V_86 ) {
V_86 -> V_25 [ 0 ] -> V_89 [ V_34 -> V_47 ] = 2 ;
F_29 ( V_2 , V_86 , V_10 ) ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_16 * V_16 )
{
T_1 * V_90 ;
struct V_11 * V_86 ;
struct V_77 * V_87 ;
int V_91 ;
int error = - V_92 , V_93 = 0 ;
if ( V_16 -> V_52 < 0 )
return 0 ;
V_87 = & ( V_2 -> V_82 [ V_41 ] ) ;
V_86 = V_87 -> V_88 [ V_16 -> V_52 ] ;
if ( ! V_86 )
return - V_94 ;
V_90 = F_31 ( V_86 , V_39 ) ;
if ( ! V_90 )
return - V_92 ;
V_91 = F_32 ( V_86 ) ;
do {
V_90 [ 0 ] = V_16 -> V_52 ;
V_90 [ 1 ] = V_16 -> V_53 ;
error = F_4 ( V_2 , V_41 , V_90 ,
V_91 , 1 ) ;
if ( error >= 0 )
error = F_1 ( V_2 , V_41 ,
V_90 , V_91 , 1 ) ;
} while ( error >= 0 &&
V_90 [ 1 ] != V_16 -> V_52 &&
V_93 ++ < V_95 );
F_18 ( V_90 ) ;
return error < 0 ? error : 0 ;
}
static int F_33 ( struct V_1 * V_2 , T_1 V_96 ,
struct V_32 * V_33 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
int V_35 ;
T_1 V_90 [ 2 ] ;
switch ( V_33 -> type ) {
case V_97 :
V_90 [ 0 ] = 0x03 ;
V_90 [ 1 ] = 0x00 ;
V_35 = F_4 ( V_2 , V_41 , V_90 , 2 ,
3 ) ;
if ( V_35 >= 0 ) {
V_90 [ 0 ] = V_96 == 0 ? 0x05 : 0x06 ;
V_90 [ 1 ] = 0x00 ;
V_35 = F_4 ( V_2 , V_41 ,
V_90 , 2 , 3 ) ;
if ( V_35 >= 0 ) {
V_14 -> V_16 . V_98 = V_96 ;
return 0 ;
}
}
F_17 ( V_2 , L_8 ,
V_90 [ 0 ] , V_35 ) ;
break;
case V_99 :
if ( V_96 == 1 )
V_14 -> V_16 . V_100 &= ~ 0x20 ;
else
V_14 -> V_16 . V_100 |= 0x20 ;
V_90 [ 0 ] = 0x03 ;
V_90 [ 1 ] = V_14 -> V_16 . V_100 ;
V_35 = F_4 ( V_2 , V_41 , V_90 , 2 ,
1 ) ;
if ( V_35 >= 0 )
V_14 -> V_16 . V_98 = V_96 ;
break;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_16 * V_16 = & V_14 -> V_16 ;
if ( V_2 -> V_101 == V_102 )
return F_33 ( V_2 , 1 , V_33 ) ;
if ( V_33 -> type != V_74 ) {
if ( V_33 -> V_60 & V_62 ) {
if ( V_33 -> type > V_103 ) {
V_16 -> V_52 = 3 ;
V_16 -> V_53 = 4 ;
} else if ( V_33 -> type == V_104 ) {
V_16 -> V_52 = 18 ;
V_16 -> V_53 = 2 ;
} else if ( V_33 -> type == V_105 ) {
V_16 -> V_52 = 131 ;
V_16 -> V_53 = 2 ;
} else if ( V_33 -> type == V_106 ) {
V_16 -> V_52 = 2 ;
V_16 -> V_53 = 2 ;
}
} else if ( V_33 -> V_60 & V_61 ) {
if ( V_33 -> type <= V_63 ) {
V_16 -> V_52 = 2 ;
V_16 -> V_53 = 2 ;
}
}
}
F_30 ( V_2 , V_16 ) ;
if ( V_33 -> type == V_74 )
return F_28 ( V_2 ) ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_107 * V_108 = V_14 -> V_108 ;
V_33 -> V_109 = 4 ;
V_33 -> V_110 = 4 ;
V_33 -> V_111 = 0 ;
V_33 -> V_112 = 1 ;
V_33 -> V_113 = 1 ;
if ( V_33 -> type == V_114 ) {
if ( V_108 -> V_115 -> V_116 . V_117 == 0 )
V_33 -> V_60 = V_118 ;
else
V_33 -> V_60 = V_119 ;
return;
}
F_26 ( V_2 , V_33 ) ;
}
static bool F_36 ( struct V_1 * V_2 ,
struct V_1 * V_120 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_32 * V_33 = & V_14 -> V_16 . V_33 ;
int V_121 = V_33 -> V_122 ;
int V_123 = V_33 -> V_124 ;
int V_125 , V_126 ;
if ( V_121 == 0 && V_123 == 0 ) {
V_121 = V_2 -> V_127 ;
V_123 = V_2 -> V_128 ;
}
if ( V_121 != V_120 -> V_127 || V_123 != V_120 -> V_128 )
return false ;
V_125 = strrchr ( V_2 -> V_129 , '.' ) - V_2 -> V_129 ;
V_126 = strrchr ( V_120 -> V_129 , '.' ) - V_120 -> V_129 ;
if ( V_125 != V_126 || V_125 <= 0 || V_126 <= 0 )
return false ;
return ! strncmp ( V_2 -> V_129 , V_120 -> V_129 , V_125 ) ;
}
static struct V_130 * F_37 ( struct V_1 * V_2 )
{
struct V_130 * V_17 ;
F_27 (data, &wacom_udev_list, list) {
if ( F_36 ( V_2 , V_17 -> V_19 ) ) {
F_38 ( & V_17 -> V_131 ) ;
return V_17 ;
}
}
return NULL ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_130 * V_17 ;
int V_6 = 0 ;
F_40 ( & V_132 ) ;
V_17 = F_37 ( V_2 ) ;
if ( ! V_17 ) {
V_17 = F_16 ( sizeof( struct V_130 ) , V_39 ) ;
if ( ! V_17 ) {
V_6 = - V_92 ;
goto V_133;
}
F_41 ( & V_17 -> V_131 ) ;
V_17 -> V_19 = V_2 ;
F_42 ( & V_17 -> V_134 , & V_135 ) ;
}
V_16 -> V_136 = & V_17 -> V_136 ;
if ( V_16 -> V_33 . V_60 & V_62 )
V_16 -> V_136 -> V_137 = V_2 ;
else if ( V_16 -> V_33 . V_60 & V_61 )
V_16 -> V_136 -> V_59 = V_2 ;
V_133:
F_43 ( & V_132 ) ;
return V_6 ;
}
static void F_44 ( struct V_131 * V_131 )
{
struct V_130 * V_17 =
F_45 ( V_131 , struct V_130 , V_131 ) ;
F_40 ( & V_132 ) ;
F_46 ( & V_17 -> V_134 ) ;
F_43 ( & V_132 ) ;
F_18 ( V_17 ) ;
}
static void F_47 ( struct V_14 * V_14 )
{
struct V_130 * V_17 ;
struct V_16 * V_16 = & V_14 -> V_16 ;
if ( V_16 -> V_136 ) {
V_17 = F_45 ( V_16 -> V_136 , struct V_130 ,
V_136 ) ;
if ( V_16 -> V_136 -> V_137 == V_14 -> V_2 )
V_16 -> V_136 -> V_137 = NULL ;
else if ( V_16 -> V_136 -> V_59 == V_14 -> V_2 )
V_16 -> V_136 -> V_59 = NULL ;
F_48 ( & V_17 -> V_131 , F_44 ) ;
V_16 -> V_136 = NULL ;
}
}
static int F_49 ( struct V_14 * V_14 )
{
unsigned char * V_3 ;
int V_6 ;
unsigned char V_138 = V_139 ;
int V_140 = 9 ;
if ( V_14 -> V_16 . V_123 ) {
V_138 = V_141 ;
V_140 = 13 ;
}
V_3 = F_16 ( V_140 , V_39 ) ;
if ( ! V_3 )
return - V_92 ;
if ( V_14 -> V_16 . V_33 . type >= V_142 &&
V_14 -> V_16 . V_33 . type <= V_143 ) {
int V_144 = V_14 -> V_145 . V_146 [ 0 ] & 0x03 ;
int V_147 = ( ( ( V_14 -> V_145 . V_148 & 0x60 ) >> 5 ) - 1 ) & 0x03 ;
int V_149 = 0 ;
unsigned char V_150 = ( V_149 << 4 ) | ( V_147 << 2 ) | ( V_144 ) ;
V_3 [ 0 ] = V_138 ;
if ( V_14 -> V_16 . V_123 ) {
F_1 ( V_14 -> V_2 , V_41 ,
V_3 , V_140 , V_42 ) ;
V_3 [ 0 ] = V_138 ;
V_3 [ 4 ] = V_150 ;
} else
V_3 [ 1 ] = V_150 ;
}
else {
int V_145 = V_14 -> V_145 . V_146 [ 0 ] | 0x4 ;
if ( V_14 -> V_16 . V_33 . type == V_151 ||
V_14 -> V_16 . V_33 . type == V_152 )
V_145 |= ( V_14 -> V_145 . V_146 [ 1 ] << 4 ) | 0x40 ;
V_3 [ 0 ] = V_138 ;
V_3 [ 1 ] = V_145 ;
V_3 [ 2 ] = V_14 -> V_145 . V_148 ;
V_3 [ 3 ] = V_14 -> V_145 . V_153 ;
V_3 [ 4 ] = V_14 -> V_145 . V_154 ;
}
V_6 = F_4 ( V_14 -> V_2 , V_41 , V_3 , V_140 ,
V_42 ) ;
F_18 ( V_3 ) ;
return V_6 ;
}
static int F_50 ( struct V_14 * V_14 , int V_155 , T_1 V_156 ,
const unsigned V_157 , const void * V_158 )
{
unsigned char * V_3 ;
int V_80 , V_6 ;
const unsigned V_159 = V_157 / 4 ;
V_3 = F_16 ( V_159 + 3 , V_39 ) ;
if ( ! V_3 )
return - V_92 ;
V_3 [ 0 ] = V_160 ;
V_3 [ 1 ] = 1 ;
V_6 = F_4 ( V_14 -> V_2 , V_41 , V_3 , 2 ,
V_42 ) ;
if ( V_6 < 0 )
goto V_133;
V_3 [ 0 ] = V_156 ;
V_3 [ 1 ] = V_155 & 0x07 ;
for ( V_80 = 0 ; V_80 < 4 ; V_80 ++ ) {
V_3 [ 2 ] = V_80 ;
memcpy ( V_3 + 3 , V_158 + V_80 * V_159 , V_159 ) ;
V_6 = F_4 ( V_14 -> V_2 , V_41 ,
V_3 , V_159 + 3 , V_42 ) ;
if ( V_6 < 0 )
break;
}
V_3 [ 0 ] = V_160 ;
V_3 [ 1 ] = 0 ;
F_4 ( V_14 -> V_2 , V_41 , V_3 , 2 ,
V_42 ) ;
V_133:
F_18 ( V_3 ) ;
return V_6 ;
}
static T_3 F_51 ( struct V_161 * V_19 , int V_162 ,
const char * V_3 , T_2 V_163 )
{
struct V_1 * V_2 = F_52 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
unsigned int V_40 ;
int V_164 ;
V_164 = F_53 ( V_3 , 10 , & V_40 ) ;
if ( V_164 )
return V_164 ;
F_40 ( & V_14 -> V_165 ) ;
V_14 -> V_145 . V_146 [ V_162 ] = V_40 & 0x3 ;
V_164 = F_49 ( V_14 ) ;
F_43 ( & V_14 -> V_165 ) ;
return V_164 < 0 ? V_164 : V_163 ;
}
static T_3 F_54 ( struct V_14 * V_14 , T_1 * V_166 ,
const char * V_3 , T_2 V_163 )
{
unsigned int V_89 ;
int V_164 ;
V_164 = F_53 ( V_3 , 10 , & V_89 ) ;
if ( V_164 )
return V_164 ;
F_40 ( & V_14 -> V_165 ) ;
* V_166 = V_89 & 0x7f ;
V_164 = F_49 ( V_14 ) ;
F_43 ( & V_14 -> V_165 ) ;
return V_164 < 0 ? V_164 : V_163 ;
}
static T_3 F_55 ( struct V_161 * V_19 , int V_155 ,
const char * V_3 , T_2 V_163 )
{
struct V_1 * V_2 = F_52 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
int V_164 ;
unsigned V_157 ;
T_1 V_156 ;
if ( V_2 -> V_101 == V_102 ) {
V_157 = 256 ;
V_156 = V_167 ;
} else {
V_157 = 1024 ;
V_156 = V_168 ;
}
if ( V_163 != V_157 )
return - V_94 ;
F_40 ( & V_14 -> V_165 ) ;
V_164 = F_50 ( V_14 , V_155 , V_156 , V_157 , V_3 ) ;
F_43 ( & V_14 -> V_165 ) ;
return V_164 < 0 ? V_164 : V_163 ;
}
static int F_56 ( struct V_14 * V_14 )
{
int error ;
if ( ! ( V_14 -> V_16 . V_33 . V_60 & V_169 ) )
return 0 ;
switch ( V_14 -> V_16 . V_33 . type ) {
case V_170 :
case V_171 :
case V_99 :
case V_172 :
V_14 -> V_145 . V_146 [ 0 ] = 0 ;
V_14 -> V_145 . V_146 [ 1 ] = 0 ;
V_14 -> V_145 . V_148 = 10 ;
V_14 -> V_145 . V_153 = 20 ;
V_14 -> V_145 . V_154 = 10 ;
error = F_57 ( & V_14 -> V_2 -> V_19 . V_173 ,
& V_174 ) ;
break;
case V_152 :
case V_151 :
V_14 -> V_145 . V_146 [ 0 ] = 0 ;
V_14 -> V_145 . V_146 [ 1 ] = 0 ;
V_14 -> V_145 . V_148 = 0 ;
V_14 -> V_145 . V_153 = 0 ;
V_14 -> V_145 . V_154 = 0 ;
error = F_57 ( & V_14 -> V_2 -> V_19 . V_173 ,
& V_175 ) ;
break;
case V_142 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_143 :
V_14 -> V_145 . V_146 [ 0 ] = 0 ;
V_14 -> V_145 . V_146 [ 1 ] = 0 ;
V_14 -> V_145 . V_148 = 32 ;
V_14 -> V_145 . V_153 = 0 ;
V_14 -> V_145 . V_154 = 0 ;
error = F_57 ( & V_14 -> V_2 -> V_19 . V_173 ,
& V_180 ) ;
break;
default:
return 0 ;
}
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_9 , error ) ;
return error ;
}
F_49 ( V_14 ) ;
V_14 -> V_181 = true ;
return 0 ;
}
static void F_58 ( struct V_14 * V_14 )
{
if ( ! V_14 -> V_181 )
return;
if ( ! ( V_14 -> V_16 . V_33 . V_60 & V_169 ) )
return;
V_14 -> V_181 = false ;
switch ( V_14 -> V_16 . V_33 . type ) {
case V_170 :
case V_171 :
case V_99 :
case V_172 :
F_59 ( & V_14 -> V_2 -> V_19 . V_173 ,
& V_174 ) ;
break;
case V_152 :
case V_151 :
F_59 ( & V_14 -> V_2 -> V_19 . V_173 ,
& V_175 ) ;
break;
case V_142 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_143 :
F_59 ( & V_14 -> V_2 -> V_19 . V_173 ,
& V_180 ) ;
break;
}
}
static int F_60 ( struct V_182 * V_183 ,
enum V_184 V_185 ,
union V_186 * V_187 )
{
struct V_14 * V_14 = F_61 ( V_183 ) ;
int V_35 = 0 ;
switch ( V_185 ) {
case V_188 :
V_187 -> V_189 = V_14 -> V_16 . V_190 ;
break;
case V_191 :
V_187 -> V_189 = V_192 ;
break;
case V_193 :
V_187 -> V_189 =
V_14 -> V_16 . V_194 ;
break;
case V_195 :
if ( V_14 -> V_16 . V_196 )
V_187 -> V_189 = V_197 ;
else if ( V_14 -> V_16 . V_194 == 100 &&
V_14 -> V_16 . V_198 )
V_187 -> V_189 = V_199 ;
else if ( V_14 -> V_16 . V_198 )
V_187 -> V_189 = V_200 ;
else
V_187 -> V_189 = V_201 ;
break;
default:
V_35 = - V_94 ;
break;
}
return V_35 ;
}
static int F_62 ( struct V_182 * V_183 ,
enum V_184 V_185 ,
union V_186 * V_187 )
{
struct V_14 * V_14 = F_61 ( V_183 ) ;
int V_35 = 0 ;
switch ( V_185 ) {
case V_188 :
case V_202 :
V_187 -> V_189 = V_14 -> V_16 . V_198 ;
break;
case V_191 :
V_187 -> V_189 = V_192 ;
break;
default:
V_35 = - V_94 ;
break;
}
return V_35 ;
}
static int F_63 ( struct V_14 * V_14 )
{
static T_4 V_203 = F_64 ( 0 ) ;
struct V_204 V_205 = { . V_206 = V_14 , } ;
unsigned long V_207 ;
if ( V_14 -> V_16 . V_33 . V_208 & V_209 ) {
struct V_210 * V_211 = & V_14 -> V_212 ;
struct V_210 * V_213 = & V_14 -> V_213 ;
V_207 = F_65 ( & V_203 ) - 1 ;
V_211 -> V_214 = V_215 ;
V_211 -> V_216 = F_66 ( V_215 ) ;
V_211 -> V_217 = F_60 ;
sprintf ( V_14 -> V_16 . V_218 , L_10 , V_207 ) ;
V_211 -> V_219 = V_14 -> V_16 . V_218 ;
V_211 -> type = V_220 ;
V_211 -> V_221 = 0 ;
V_213 -> V_214 = V_222 ;
V_213 -> V_216 = F_66 ( V_222 ) ;
V_213 -> V_217 = F_62 ;
sprintf ( V_14 -> V_16 . V_223 , L_11 , V_207 ) ;
V_213 -> V_219 = V_14 -> V_16 . V_223 ;
V_213 -> type = V_224 ;
V_213 -> V_221 = 0 ;
V_14 -> V_225 = F_67 ( & V_14 -> V_2 -> V_19 ,
& V_14 -> V_212 , & V_205 ) ;
if ( F_68 ( V_14 -> V_225 ) )
return F_69 ( V_14 -> V_225 ) ;
F_70 ( V_14 -> V_225 , & V_14 -> V_2 -> V_19 ) ;
V_14 -> V_226 = F_67 ( & V_14 -> V_2 -> V_19 ,
& V_14 -> V_213 ,
& V_205 ) ;
if ( F_68 ( V_14 -> V_226 ) ) {
F_71 ( V_14 -> V_225 ) ;
return F_69 ( V_14 -> V_226 ) ;
}
F_70 ( V_14 -> V_226 , & V_14 -> V_2 -> V_19 ) ;
}
return 0 ;
}
static void F_72 ( struct V_14 * V_14 )
{
if ( V_14 -> V_225 ) {
F_71 ( V_14 -> V_225 ) ;
V_14 -> V_225 = NULL ;
F_71 ( V_14 -> V_226 ) ;
V_14 -> V_226 = NULL ;
}
}
static T_3 F_73 ( struct V_161 * V_19 ,
struct V_227
* V_228 , char * V_3 )
{
struct V_1 * V_2 = F_52 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
return snprintf ( V_3 , V_229 , L_12 , V_14 -> V_16 . V_98 ) ;
}
static T_3 F_74 ( struct V_161 * V_19 ,
struct V_227 * V_228 ,
const char * V_3 , T_2 V_163 )
{
struct V_1 * V_2 = F_52 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
T_1 V_230 ;
if ( F_75 ( V_3 , 0 , & V_230 ) )
return - V_94 ;
if ( V_230 != 0 && V_230 != 1 )
return - V_94 ;
F_33 ( V_2 , V_230 , & V_14 -> V_16 . V_33 ) ;
return V_163 ;
}
static T_3 F_76 ( struct V_231 * V_173 ,
struct V_232 * V_233 ,
char * V_3 , int V_234 )
{
struct V_161 * V_19 = F_77 ( V_173 -> V_235 ) ;
struct V_1 * V_2 = F_52 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
T_1 V_236 ;
V_236 = V_14 -> V_145 . V_146 [ V_234 ] ;
if ( V_236 >= 0 && V_236 < 3 )
return snprintf ( V_3 , V_229 , L_13 , V_236 ) ;
else
return snprintf ( V_3 , V_229 , L_13 , - 1 ) ;
}
int F_78 ( struct V_14 * V_14 , T_5 V_237 , int V_234 )
{
int error = 0 ;
char * V_3 ;
struct V_16 * V_16 = & V_14 -> V_16 ;
V_16 -> V_237 [ V_234 ] = V_237 ;
V_3 = F_16 ( V_238 , V_39 ) ;
if ( ! V_3 )
return - V_92 ;
snprintf ( V_3 , V_238 , L_14 , V_237 ) ;
V_14 -> V_239 [ V_234 ] . V_219 = V_3 ;
error = F_57 ( V_14 -> V_240 ,
& V_14 -> V_239 [ V_234 ] ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_9 , error ) ;
F_79 ( V_14 -> V_240 ) ;
return error ;
}
return 0 ;
}
void F_80 ( struct V_14 * V_14 , T_5 V_237 )
{
struct V_16 * V_16 = & V_14 -> V_16 ;
int V_80 ;
if ( ! V_237 )
return;
for ( V_80 = 0 ; V_80 < V_241 ; V_80 ++ ) {
if ( V_16 -> V_237 [ V_80 ] == V_237 ) {
V_16 -> V_237 [ V_80 ] = 0 ;
V_14 -> V_145 . V_146 [ V_80 ] = V_242 ;
if ( V_14 -> V_239 [ V_80 ] . V_219 ) {
F_59 ( V_14 -> V_240 ,
& V_14 -> V_239 [ V_80 ] ) ;
F_18 ( V_14 -> V_239 [ V_80 ] . V_219 ) ;
V_14 -> V_239 [ V_80 ] . V_219 = NULL ;
}
}
}
}
static int F_81 ( struct V_14 * V_14 , unsigned char V_243 )
{
const T_2 V_140 = 2 ;
unsigned char * V_3 ;
int V_6 ;
V_3 = F_16 ( V_140 , V_39 ) ;
if ( ! V_3 )
return - V_92 ;
V_3 [ 0 ] = V_244 ;
V_3 [ 1 ] = V_243 ;
V_6 = F_4 ( V_14 -> V_2 , V_245 , V_3 ,
V_140 , V_42 ) ;
F_18 ( V_3 ) ;
return V_6 ;
}
static T_3 F_82 ( struct V_231 * V_173 ,
struct V_232 * V_228 ,
const char * V_3 , T_2 V_163 )
{
unsigned char V_243 = 0 ;
struct V_161 * V_19 = F_77 ( V_173 -> V_235 ) ;
struct V_1 * V_2 = F_52 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
int V_164 ;
if ( ! strncmp ( V_3 , L_15 , 2 ) ) {
V_243 = V_246 ;
} else {
F_83 ( V_14 -> V_2 , L_16 ,
V_3 ) ;
return - 1 ;
}
F_40 ( & V_14 -> V_165 ) ;
V_164 = F_81 ( V_14 , V_243 ) ;
F_43 ( & V_14 -> V_165 ) ;
return V_164 < 0 ? V_164 : V_163 ;
}
static int F_84 ( struct V_14 * V_14 )
{
int error = 0 ;
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
int V_80 ;
if ( V_14 -> V_16 . V_33 . type != V_247 )
return 0 ;
V_14 -> V_239 [ 0 ] = V_248 ;
V_14 -> V_239 [ 1 ] = V_249 ;
V_14 -> V_239 [ 2 ] = V_250 ;
V_14 -> V_239 [ 3 ] = V_251 ;
V_14 -> V_239 [ 4 ] = V_252 ;
V_14 -> V_240 = F_85 ( L_17 ,
& V_14 -> V_2 -> V_19 . V_173 ) ;
if ( ! V_14 -> V_240 )
return - V_92 ;
error = F_86 ( V_14 -> V_240 , V_253 ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_9 , error ) ;
return error ;
}
for ( V_80 = 0 ; V_80 < V_241 ; V_80 ++ ) {
V_14 -> V_145 . V_146 [ V_80 ] = V_242 ;
V_16 -> V_237 [ V_80 ] = 0 ;
}
return 0 ;
}
static struct V_18 * F_87 ( struct V_14 * V_14 )
{
struct V_18 * V_18 ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
V_18 = F_88 () ;
if ( ! V_18 )
return NULL ;
V_18 -> V_219 = V_16 -> V_33 . V_219 ;
V_18 -> V_129 = V_2 -> V_129 ;
V_18 -> V_19 . V_235 = & V_2 -> V_19 ;
V_18 -> V_254 = F_8 ;
V_18 -> V_255 = F_11 ;
V_18 -> V_256 = V_2 -> V_256 ;
V_18 -> V_40 . V_257 = V_2 -> V_101 ;
V_18 -> V_40 . V_127 = V_2 -> V_127 ;
V_18 -> V_40 . V_128 = V_16 -> V_123 ? V_16 -> V_123 : V_2 -> V_128 ;
V_18 -> V_40 . V_258 = V_2 -> V_258 ;
F_89 ( V_18 , V_14 ) ;
return V_18 ;
}
static void F_90 ( struct V_14 * V_14 )
{
if ( V_14 -> V_16 . V_259 ) {
if ( V_14 -> V_16 . V_260 )
F_91 ( V_14 -> V_16 . V_259 ) ;
else
F_92 ( V_14 -> V_16 . V_259 ) ;
}
if ( V_14 -> V_16 . V_75 ) {
if ( V_14 -> V_16 . V_261 )
F_91 ( V_14 -> V_16 . V_75 ) ;
else
F_92 ( V_14 -> V_16 . V_75 ) ;
}
if ( V_14 -> V_16 . V_262 ) {
if ( V_14 -> V_16 . V_263 )
F_91 ( V_14 -> V_16 . V_262 ) ;
else
F_92 ( V_14 -> V_16 . V_262 ) ;
}
F_79 ( V_14 -> V_240 ) ;
V_14 -> V_16 . V_259 = NULL ;
V_14 -> V_16 . V_75 = NULL ;
V_14 -> V_16 . V_262 = NULL ;
V_14 -> V_16 . V_260 = false ;
V_14 -> V_16 . V_261 = false ;
V_14 -> V_16 . V_263 = false ;
F_58 ( V_14 ) ;
}
static int F_93 ( struct V_14 * V_14 )
{
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
V_16 -> V_259 = F_87 ( V_14 ) ;
V_16 -> V_75 = F_87 ( V_14 ) ;
V_16 -> V_262 = F_87 ( V_14 ) ;
if ( ! V_16 -> V_259 || ! V_16 -> V_75 || ! V_16 -> V_262 ) {
F_90 ( V_14 ) ;
return - V_92 ;
}
V_16 -> V_259 -> V_219 = V_16 -> V_264 ;
V_16 -> V_75 -> V_219 = V_16 -> V_265 ;
V_16 -> V_262 -> V_219 = V_16 -> V_266 ;
return 0 ;
}
static int F_94 ( struct V_14 * V_14 )
{
struct V_18 * V_267 , * V_268 , * V_269 ;
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
int error = 0 ;
V_267 = V_16 -> V_259 ;
V_268 = V_16 -> V_75 ;
V_269 = V_16 -> V_262 ;
if ( ! V_267 || ! V_268 || ! V_269 )
return - V_94 ;
error = F_95 ( V_267 , V_16 ) ;
if ( error ) {
F_92 ( V_267 ) ;
V_16 -> V_259 = NULL ;
V_267 = NULL ;
} else {
error = F_96 ( V_267 ) ;
if ( error )
goto V_270;
V_16 -> V_260 = true ;
}
error = F_97 ( V_268 , V_16 ) ;
if ( error ) {
F_92 ( V_268 ) ;
V_16 -> V_75 = NULL ;
V_268 = NULL ;
} else {
error = F_96 ( V_268 ) ;
if ( error )
goto V_271;
V_16 -> V_261 = true ;
}
error = F_98 ( V_269 , V_16 ) ;
if ( error ) {
F_92 ( V_269 ) ;
V_16 -> V_262 = NULL ;
V_269 = NULL ;
} else {
error = F_96 ( V_269 ) ;
if ( error )
goto V_272;
V_16 -> V_263 = true ;
error = F_56 ( V_14 ) ;
if ( error )
goto V_273;
error = F_84 ( V_14 ) ;
if ( error )
goto V_274;
}
return 0 ;
V_274:
F_58 ( V_14 ) ;
V_273:
F_91 ( V_269 ) ;
V_269 = NULL ;
V_16 -> V_263 = false ;
V_272:
if ( V_268 )
F_91 ( V_268 ) ;
V_16 -> V_75 = NULL ;
V_16 -> V_261 = false ;
V_271:
if ( V_267 )
F_91 ( V_267 ) ;
V_16 -> V_259 = NULL ;
V_16 -> V_260 = false ;
V_270:
return error ;
}
static void F_99 ( struct V_32 * V_33 )
{
if ( V_33 -> V_275 ) {
V_33 -> V_66 = ( V_33 -> V_65 * 100 ) /
V_33 -> V_275 ;
V_33 -> V_71 = ( V_33 -> V_70 * 100 ) /
V_33 -> V_276 ;
}
}
static void F_100 ( struct V_32 * V_33 )
{
if ( ! V_33 -> V_22 ) {
V_33 -> V_22 = 0x11 ;
V_33 -> V_68 = - 3 ;
}
V_33 -> V_275 = F_13 ( V_33 -> V_65 ,
V_33 -> V_66 ,
V_33 -> V_22 ,
V_33 -> V_68 ) ;
V_33 -> V_276 = F_13 ( V_33 -> V_70 ,
V_33 -> V_71 ,
V_33 -> V_22 ,
V_33 -> V_68 ) ;
}
void F_101 ( struct V_277 * V_278 )
{
struct V_14 * V_14 = F_45 ( V_278 , struct V_14 , V_278 ) ;
if ( ( V_14 -> V_16 . V_33 . V_208 & V_209 ) &&
! V_14 -> V_225 ) {
F_63 ( V_14 ) ;
}
else if ( ! ( V_14 -> V_16 . V_33 . V_208 & V_209 ) &&
V_14 -> V_225 ) {
F_72 ( V_14 ) ;
}
}
static T_2 F_102 ( struct V_1 * V_2 )
{
struct V_77 * V_82 ;
struct V_11 * V_12 ;
T_2 V_4 = 0 ;
V_82 = V_2 -> V_82 + V_85 ;
F_27 (report, &report_enum->report_list, list) {
T_2 V_279 = F_32 ( V_12 ) ;
if ( V_279 > V_4 )
V_4 = V_279 ;
}
return V_4 ;
}
static void F_103 ( struct V_14 * V_14 , const char * V_280 )
{
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_32 * V_33 = & V_16 -> V_33 ;
char V_219 [ V_281 ] ;
if ( ( V_33 -> type == V_74 ) && ! strcmp ( L_18 , V_33 -> V_219 ) ) {
if ( strstr ( V_14 -> V_2 -> V_219 , L_19 ) ||
strstr ( V_14 -> V_2 -> V_219 , L_20 ) ||
strstr ( V_14 -> V_2 -> V_219 , L_21 ) ) {
F_104 ( V_219 , V_14 -> V_2 -> V_219 , sizeof( V_219 ) ) ;
while ( 1 ) {
char * V_282 = strstr ( V_219 , L_22 ) ;
if ( V_282 == NULL )
break;
memmove ( V_282 , V_282 + 1 , strlen ( V_282 ) ) ;
}
if ( V_219 [ strlen ( V_219 ) - 1 ] == ' ' )
V_219 [ strlen ( V_219 ) - 1 ] = '\0' ;
} else {
snprintf ( V_219 , sizeof( V_219 ) ,
L_23 , V_33 -> V_219 , V_14 -> V_2 -> V_128 ) ;
}
} else {
F_104 ( V_219 , V_33 -> V_219 , sizeof( V_219 ) ) ;
}
snprintf ( V_16 -> V_264 , sizeof( V_16 -> V_264 ) ,
L_24 , V_219 , V_280 ) ;
snprintf ( V_16 -> V_265 , sizeof( V_16 -> V_265 ) ,
L_25 , V_219 , V_280 ) ;
snprintf ( V_16 -> V_266 , sizeof( V_16 -> V_266 ) ,
L_26 , V_219 , V_280 ) ;
}
static int F_105 ( struct V_14 * V_14 , bool V_283 )
{
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_32 * V_33 = & V_16 -> V_33 ;
struct V_1 * V_2 = V_14 -> V_2 ;
int error ;
unsigned int V_284 = V_285 ;
V_33 -> V_286 = F_102 ( V_2 ) ;
if ( V_33 -> V_286 > V_15 )
return - V_94 ;
error = F_93 ( V_14 ) ;
if ( error )
return error ;
if ( V_33 -> type == V_106 ) {
if ( V_33 -> V_286 == V_287 ) {
V_33 -> type = V_74 ;
} else if ( ( V_33 -> V_286 != V_288 ) &&
( V_33 -> V_286 != V_289 ) ) {
error = - V_290 ;
goto V_291;
}
}
F_99 ( V_33 ) ;
F_35 ( V_2 , V_33 ) ;
F_106 ( V_14 ) ;
if ( V_33 -> V_60 == V_119 &&
V_33 -> type != V_114 ) {
error = V_33 -> type == V_74 ? - V_290 : 0 ;
F_107 ( & V_2 -> V_19 , L_27 ,
V_2 -> V_219 ,
error ? L_28 : L_29 ) ;
if ( error )
goto V_292;
V_33 -> V_60 |= V_61 ;
}
F_100 ( V_33 ) ;
F_103 ( V_14 , V_283 ? L_30 : L_31 ) ;
error = F_39 ( V_2 ) ;
if ( error )
goto V_293;
if ( ! ( V_33 -> V_60 & V_118 ) &&
( V_33 -> V_208 & V_209 ) ) {
error = F_63 ( V_14 ) ;
if ( error )
goto V_294;
}
error = F_94 ( V_14 ) ;
if ( error )
goto V_295;
if ( V_33 -> type == V_74 )
V_284 |= V_296 ;
error = F_108 ( V_2 , V_284 ) ;
if ( error ) {
F_3 ( V_2 , L_32 ) ;
goto V_297;
}
if ( ! V_283 ) {
F_34 ( V_2 , V_33 ) ;
}
if ( ( V_33 -> type == V_67 ) &&
( V_33 -> V_60 & V_61 ) ) {
error = - V_290 ;
goto V_297;
}
if ( ( V_33 -> type == V_298 ) &&
( ( V_33 -> V_60 & V_62 ) ||
( V_33 -> V_60 & V_169 ) ) ) {
error = - V_290 ;
goto V_297;
}
if ( V_33 -> V_60 & V_118 )
error = F_10 ( V_2 ) ;
if ( ( V_16 -> V_33 . type == V_299 ||
V_16 -> V_33 . type == V_300 ) &&
( V_16 -> V_33 . V_60 & V_62 ) ) {
V_16 -> V_136 -> V_75 = V_16 -> V_75 ;
}
return 0 ;
V_297:
F_109 ( V_2 ) ;
V_295:
F_90 ( V_14 ) ;
F_72 ( V_14 ) ;
V_294:
F_47 ( V_14 ) ;
V_293:
V_292:
V_291:
F_90 ( V_14 ) ;
return error ;
}
static void F_110 ( struct V_277 * V_278 )
{
struct V_14 * V_14 = F_45 ( V_278 , struct V_14 , V_278 ) ;
struct V_301 * V_302 = V_14 -> V_302 ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_1 * V_303 , * V_304 ;
struct V_14 * V_305 , * V_306 ;
struct V_16 * V_307 , * V_308 ;
int error ;
F_72 ( V_14 ) ;
V_303 = F_111 ( V_302 -> V_309 -> V_310 [ 1 ] ) ;
V_305 = F_6 ( V_303 ) ;
V_307 = & ( V_305 -> V_16 ) ;
F_90 ( V_305 ) ;
V_304 = F_111 ( V_302 -> V_309 -> V_310 [ 2 ] ) ;
V_306 = F_6 ( V_304 ) ;
V_308 = & ( V_306 -> V_16 ) ;
F_90 ( V_306 ) ;
if ( V_16 -> V_123 == 0 ) {
F_83 ( V_14 -> V_2 , L_33 ) ;
V_307 -> V_136 -> type = 0 ;
} else {
const struct V_311 * V_40 = V_312 ;
F_83 ( V_14 -> V_2 , L_34 ,
V_16 -> V_123 ) ;
while ( V_40 -> V_101 ) {
if ( V_40 -> V_127 == V_313 &&
V_40 -> V_128 == V_16 -> V_123 )
break;
V_40 ++ ;
}
if ( ! V_40 -> V_101 ) {
F_83 ( V_14 -> V_2 , L_35 ) ;
return;
}
V_307 -> V_33 =
* ( (struct V_32 * ) V_40 -> V_314 ) ;
V_307 -> V_123 = V_16 -> V_123 ;
F_109 ( V_303 ) ;
error = F_105 ( V_305 , true ) ;
if ( error )
goto V_315;
if ( V_307 -> V_33 . V_38 ||
( V_307 -> V_33 . type >= V_299 &&
V_307 -> V_33 . type <= V_63 ) ) {
V_308 -> V_33 =
* ( (struct V_32 * ) V_40 -> V_314 ) ;
V_308 -> V_123 = V_16 -> V_123 ;
F_109 ( V_304 ) ;
error = F_105 ( V_306 , true ) ;
if ( error )
goto V_315;
}
error = F_63 ( V_14 ) ;
if ( error )
goto V_315;
}
return;
V_315:
F_90 ( V_305 ) ;
F_90 ( V_306 ) ;
return;
}
static int F_112 ( struct V_1 * V_2 ,
const struct V_311 * V_40 )
{
struct V_107 * V_108 = F_113 ( V_2 -> V_19 . V_235 ) ;
struct V_301 * V_19 = F_114 ( V_108 ) ;
struct V_14 * V_14 ;
struct V_16 * V_16 ;
struct V_32 * V_33 ;
int error ;
if ( ! V_40 -> V_314 )
return - V_94 ;
V_2 -> V_208 |= V_316 ;
V_2 -> V_208 &= ~ V_317 ;
V_14 = F_16 ( sizeof( struct V_14 ) , V_39 ) ;
if ( ! V_14 )
return - V_92 ;
F_115 ( V_2 , V_14 ) ;
V_14 -> V_2 = V_2 ;
V_16 = & V_14 -> V_16 ;
V_16 -> V_33 = * ( (struct V_32 * ) V_40 -> V_314 ) ;
V_33 = & V_16 -> V_33 ;
if ( V_33 -> V_318 && V_33 -> V_319 != V_2 -> type ) {
error = - V_290 ;
goto V_320;
}
V_16 -> V_34 . V_46 = - 1 ;
V_16 -> V_52 = - 1 ;
V_14 -> V_302 = V_19 ;
V_14 -> V_108 = V_108 ;
F_116 ( & V_14 -> V_165 ) ;
F_117 ( & V_14 -> V_278 , F_110 ) ;
error = F_118 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_36 ) ;
goto V_321;
}
error = F_105 ( V_14 , false ) ;
if ( error )
goto V_321;
if ( V_2 -> V_101 == V_102 ) {
error = F_119 ( & V_2 -> V_19 , & V_322 ) ;
if ( error )
F_17 ( V_2 ,
L_37 ,
error ) ;
}
return 0 ;
V_320:
V_321:
F_18 ( V_14 ) ;
F_115 ( V_2 , NULL ) ;
return error ;
}
static void F_120 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_32 * V_33 = & V_16 -> V_33 ;
if ( V_33 -> V_60 & V_118 )
F_12 ( V_2 ) ;
F_109 ( V_2 ) ;
F_121 ( & V_14 -> V_278 ) ;
F_90 ( V_14 ) ;
if ( V_2 -> V_101 == V_102 )
F_122 ( & V_2 -> V_19 , & V_322 ) ;
F_72 ( V_14 ) ;
F_47 ( V_14 ) ;
F_115 ( V_2 , NULL ) ;
F_18 ( V_14 ) ;
}
static int F_123 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_32 * V_33 = & V_14 -> V_16 . V_33 ;
F_40 ( & V_14 -> V_165 ) ;
F_34 ( V_2 , V_33 ) ;
F_49 ( V_14 ) ;
F_43 ( & V_14 -> V_165 ) ;
return 0 ;
}
static int F_124 ( struct V_1 * V_2 )
{
return F_123 ( V_2 ) ;
}
