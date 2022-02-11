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
V_33 -> V_112 = 0 ;
if ( V_33 -> type == V_113 ) {
if ( V_108 -> V_114 -> V_115 . V_116 == 0 )
V_33 -> V_60 = V_117 ;
else
V_33 -> V_60 = V_118 ;
return;
}
F_26 ( V_2 , V_33 ) ;
}
static bool F_36 ( struct V_1 * V_2 ,
struct V_1 * V_119 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_32 * V_33 = & V_14 -> V_16 . V_33 ;
int V_120 = V_33 -> V_121 ;
int V_122 = V_33 -> V_123 ;
int V_124 , V_125 ;
if ( V_120 == 0 && V_122 == 0 ) {
V_120 = V_2 -> V_126 ;
V_122 = V_2 -> V_127 ;
}
if ( V_120 != V_119 -> V_126 || V_122 != V_119 -> V_127 )
return false ;
V_124 = strrchr ( V_2 -> V_128 , '.' ) - V_2 -> V_128 ;
V_125 = strrchr ( V_119 -> V_128 , '.' ) - V_119 -> V_128 ;
if ( V_124 != V_125 || V_124 <= 0 || V_125 <= 0 )
return false ;
return ! strncmp ( V_2 -> V_128 , V_119 -> V_128 , V_124 ) ;
}
static struct V_129 * F_37 ( struct V_1 * V_2 )
{
struct V_129 * V_17 ;
F_27 (data, &wacom_udev_list, list) {
if ( F_36 ( V_2 , V_17 -> V_19 ) ) {
F_38 ( & V_17 -> V_130 ) ;
return V_17 ;
}
}
return NULL ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_129 * V_17 ;
int V_6 = 0 ;
F_40 ( & V_131 ) ;
V_17 = F_37 ( V_2 ) ;
if ( ! V_17 ) {
V_17 = F_16 ( sizeof( struct V_129 ) , V_39 ) ;
if ( ! V_17 ) {
V_6 = - V_92 ;
goto V_132;
}
F_41 ( & V_17 -> V_130 ) ;
V_17 -> V_19 = V_2 ;
F_42 ( & V_17 -> V_133 , & V_134 ) ;
}
V_16 -> V_135 = & V_17 -> V_135 ;
if ( V_16 -> V_33 . V_60 & V_62 )
V_16 -> V_135 -> V_136 = V_2 ;
else if ( V_16 -> V_33 . V_60 & V_61 )
V_16 -> V_135 -> V_59 = V_2 ;
V_132:
F_43 ( & V_131 ) ;
return V_6 ;
}
static void F_44 ( struct V_130 * V_130 )
{
struct V_129 * V_17 =
F_45 ( V_130 , struct V_129 , V_130 ) ;
F_40 ( & V_131 ) ;
F_46 ( & V_17 -> V_133 ) ;
F_43 ( & V_131 ) ;
F_18 ( V_17 ) ;
}
static void F_47 ( struct V_14 * V_14 )
{
struct V_129 * V_17 ;
struct V_16 * V_16 = & V_14 -> V_16 ;
if ( V_16 -> V_135 ) {
V_17 = F_45 ( V_16 -> V_135 , struct V_129 ,
V_135 ) ;
if ( V_16 -> V_135 -> V_136 == V_14 -> V_2 )
V_16 -> V_135 -> V_136 = NULL ;
else if ( V_16 -> V_135 -> V_59 == V_14 -> V_2 )
V_16 -> V_135 -> V_59 = NULL ;
F_48 ( & V_17 -> V_130 , F_44 ) ;
V_16 -> V_135 = NULL ;
}
}
static int F_49 ( struct V_14 * V_14 )
{
unsigned char * V_3 ;
int V_6 ;
unsigned char V_137 = V_138 ;
int V_139 = 9 ;
if ( V_14 -> V_16 . V_122 ) {
V_137 = V_140 ;
V_139 = 13 ;
}
V_3 = F_16 ( V_139 , V_39 ) ;
if ( ! V_3 )
return - V_92 ;
if ( V_14 -> V_16 . V_33 . type >= V_141 &&
V_14 -> V_16 . V_33 . type <= V_142 ) {
int V_143 = V_14 -> V_144 . V_145 [ 0 ] & 0x03 ;
int V_146 = ( ( ( V_14 -> V_144 . V_147 & 0x60 ) >> 5 ) - 1 ) & 0x03 ;
int V_148 = 0 ;
unsigned char V_149 = ( V_148 << 4 ) | ( V_146 << 2 ) | ( V_143 ) ;
V_3 [ 0 ] = V_137 ;
if ( V_14 -> V_16 . V_122 ) {
F_1 ( V_14 -> V_2 , V_41 ,
V_3 , V_139 , V_42 ) ;
V_3 [ 0 ] = V_137 ;
V_3 [ 4 ] = V_149 ;
} else
V_3 [ 1 ] = V_149 ;
}
else {
int V_144 = V_14 -> V_144 . V_145 [ 0 ] | 0x4 ;
if ( V_14 -> V_16 . V_33 . type == V_150 ||
V_14 -> V_16 . V_33 . type == V_151 )
V_144 |= ( V_14 -> V_144 . V_145 [ 1 ] << 4 ) | 0x40 ;
V_3 [ 0 ] = V_137 ;
V_3 [ 1 ] = V_144 ;
V_3 [ 2 ] = V_14 -> V_144 . V_147 ;
V_3 [ 3 ] = V_14 -> V_144 . V_152 ;
V_3 [ 4 ] = V_14 -> V_144 . V_153 ;
}
V_6 = F_4 ( V_14 -> V_2 , V_41 , V_3 , V_139 ,
V_42 ) ;
F_18 ( V_3 ) ;
return V_6 ;
}
static int F_50 ( struct V_14 * V_14 , int V_154 , T_1 V_155 ,
const unsigned V_156 , const void * V_157 )
{
unsigned char * V_3 ;
int V_80 , V_6 ;
const unsigned V_158 = V_156 / 4 ;
V_3 = F_16 ( V_158 + 3 , V_39 ) ;
if ( ! V_3 )
return - V_92 ;
V_3 [ 0 ] = V_159 ;
V_3 [ 1 ] = 1 ;
V_6 = F_4 ( V_14 -> V_2 , V_41 , V_3 , 2 ,
V_42 ) ;
if ( V_6 < 0 )
goto V_132;
V_3 [ 0 ] = V_155 ;
V_3 [ 1 ] = V_154 & 0x07 ;
for ( V_80 = 0 ; V_80 < 4 ; V_80 ++ ) {
V_3 [ 2 ] = V_80 ;
memcpy ( V_3 + 3 , V_157 + V_80 * V_158 , V_158 ) ;
V_6 = F_4 ( V_14 -> V_2 , V_41 ,
V_3 , V_158 + 3 , V_42 ) ;
if ( V_6 < 0 )
break;
}
V_3 [ 0 ] = V_159 ;
V_3 [ 1 ] = 0 ;
F_4 ( V_14 -> V_2 , V_41 , V_3 , 2 ,
V_42 ) ;
V_132:
F_18 ( V_3 ) ;
return V_6 ;
}
static T_3 F_51 ( struct V_160 * V_19 , int V_161 ,
const char * V_3 , T_2 V_162 )
{
struct V_1 * V_2 = F_52 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
unsigned int V_40 ;
int V_163 ;
V_163 = F_53 ( V_3 , 10 , & V_40 ) ;
if ( V_163 )
return V_163 ;
F_40 ( & V_14 -> V_164 ) ;
V_14 -> V_144 . V_145 [ V_161 ] = V_40 & 0x3 ;
V_163 = F_49 ( V_14 ) ;
F_43 ( & V_14 -> V_164 ) ;
return V_163 < 0 ? V_163 : V_162 ;
}
static T_3 F_54 ( struct V_14 * V_14 , T_1 * V_165 ,
const char * V_3 , T_2 V_162 )
{
unsigned int V_89 ;
int V_163 ;
V_163 = F_53 ( V_3 , 10 , & V_89 ) ;
if ( V_163 )
return V_163 ;
F_40 ( & V_14 -> V_164 ) ;
* V_165 = V_89 & 0x7f ;
V_163 = F_49 ( V_14 ) ;
F_43 ( & V_14 -> V_164 ) ;
return V_163 < 0 ? V_163 : V_162 ;
}
static T_3 F_55 ( struct V_160 * V_19 , int V_154 ,
const char * V_3 , T_2 V_162 )
{
struct V_1 * V_2 = F_52 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
int V_163 ;
unsigned V_156 ;
T_1 V_155 ;
if ( V_2 -> V_101 == V_102 ) {
V_156 = 256 ;
V_155 = V_166 ;
} else {
V_156 = 1024 ;
V_155 = V_167 ;
}
if ( V_162 != V_156 )
return - V_94 ;
F_40 ( & V_14 -> V_164 ) ;
V_163 = F_50 ( V_14 , V_154 , V_155 , V_156 , V_3 ) ;
F_43 ( & V_14 -> V_164 ) ;
return V_163 < 0 ? V_163 : V_162 ;
}
static int F_56 ( struct V_14 * V_14 )
{
int error ;
if ( ! ( V_14 -> V_16 . V_33 . V_60 & V_168 ) )
return 0 ;
switch ( V_14 -> V_16 . V_33 . type ) {
case V_169 :
case V_170 :
case V_99 :
case V_171 :
V_14 -> V_144 . V_145 [ 0 ] = 0 ;
V_14 -> V_144 . V_145 [ 1 ] = 0 ;
V_14 -> V_144 . V_147 = 10 ;
V_14 -> V_144 . V_152 = 20 ;
V_14 -> V_144 . V_153 = 10 ;
error = F_57 ( & V_14 -> V_2 -> V_19 . V_172 ,
& V_173 ) ;
break;
case V_151 :
case V_150 :
V_14 -> V_144 . V_145 [ 0 ] = 0 ;
V_14 -> V_144 . V_145 [ 1 ] = 0 ;
V_14 -> V_144 . V_147 = 0 ;
V_14 -> V_144 . V_152 = 0 ;
V_14 -> V_144 . V_153 = 0 ;
error = F_57 ( & V_14 -> V_2 -> V_19 . V_172 ,
& V_174 ) ;
break;
case V_141 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_142 :
V_14 -> V_144 . V_145 [ 0 ] = 0 ;
V_14 -> V_144 . V_145 [ 1 ] = 0 ;
V_14 -> V_144 . V_147 = 32 ;
V_14 -> V_144 . V_152 = 0 ;
V_14 -> V_144 . V_153 = 0 ;
error = F_57 ( & V_14 -> V_2 -> V_19 . V_172 ,
& V_179 ) ;
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
V_14 -> V_180 = true ;
return 0 ;
}
static void F_58 ( struct V_14 * V_14 )
{
if ( ! V_14 -> V_180 )
return;
if ( ! ( V_14 -> V_16 . V_33 . V_60 & V_168 ) )
return;
V_14 -> V_180 = false ;
switch ( V_14 -> V_16 . V_33 . type ) {
case V_169 :
case V_170 :
case V_99 :
case V_171 :
F_59 ( & V_14 -> V_2 -> V_19 . V_172 ,
& V_173 ) ;
break;
case V_151 :
case V_150 :
F_59 ( & V_14 -> V_2 -> V_19 . V_172 ,
& V_174 ) ;
break;
case V_141 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_142 :
F_59 ( & V_14 -> V_2 -> V_19 . V_172 ,
& V_179 ) ;
break;
}
}
static int F_60 ( struct V_181 * V_182 ,
enum V_183 V_184 ,
union V_185 * V_186 )
{
struct V_14 * V_14 = F_61 ( V_182 ) ;
int V_35 = 0 ;
switch ( V_184 ) {
case V_187 :
V_186 -> V_188 = V_14 -> V_16 . V_189 ;
break;
case V_190 :
V_186 -> V_188 = V_191 ;
break;
case V_192 :
V_186 -> V_188 =
V_14 -> V_16 . V_193 ;
break;
case V_194 :
if ( V_14 -> V_16 . V_195 )
V_186 -> V_188 = V_196 ;
else if ( V_14 -> V_16 . V_193 == 100 &&
V_14 -> V_16 . V_197 )
V_186 -> V_188 = V_198 ;
else if ( V_14 -> V_16 . V_197 )
V_186 -> V_188 = V_199 ;
else
V_186 -> V_188 = V_200 ;
break;
default:
V_35 = - V_94 ;
break;
}
return V_35 ;
}
static int F_62 ( struct V_181 * V_182 ,
enum V_183 V_184 ,
union V_185 * V_186 )
{
struct V_14 * V_14 = F_61 ( V_182 ) ;
int V_35 = 0 ;
switch ( V_184 ) {
case V_187 :
case V_201 :
V_186 -> V_188 = V_14 -> V_16 . V_197 ;
break;
case V_190 :
V_186 -> V_188 = V_191 ;
break;
default:
V_35 = - V_94 ;
break;
}
return V_35 ;
}
static int F_63 ( struct V_14 * V_14 )
{
static T_4 V_202 = F_64 ( 0 ) ;
struct V_203 V_204 = { . V_205 = V_14 , } ;
unsigned long V_206 ;
if ( V_14 -> V_16 . V_33 . V_207 & V_208 ) {
struct V_209 * V_210 = & V_14 -> V_211 ;
struct V_209 * V_212 = & V_14 -> V_212 ;
V_206 = F_65 ( & V_202 ) - 1 ;
V_210 -> V_213 = V_214 ;
V_210 -> V_215 = F_66 ( V_214 ) ;
V_210 -> V_216 = F_60 ;
sprintf ( V_14 -> V_16 . V_217 , L_10 , V_206 ) ;
V_210 -> V_218 = V_14 -> V_16 . V_217 ;
V_210 -> type = V_219 ;
V_210 -> V_220 = 0 ;
V_212 -> V_213 = V_221 ;
V_212 -> V_215 = F_66 ( V_221 ) ;
V_212 -> V_216 = F_62 ;
sprintf ( V_14 -> V_16 . V_222 , L_11 , V_206 ) ;
V_212 -> V_218 = V_14 -> V_16 . V_222 ;
V_212 -> type = V_223 ;
V_212 -> V_220 = 0 ;
V_14 -> V_224 = F_67 ( & V_14 -> V_2 -> V_19 ,
& V_14 -> V_211 , & V_204 ) ;
if ( F_68 ( V_14 -> V_224 ) )
return F_69 ( V_14 -> V_224 ) ;
F_70 ( V_14 -> V_224 , & V_14 -> V_2 -> V_19 ) ;
V_14 -> V_225 = F_67 ( & V_14 -> V_2 -> V_19 ,
& V_14 -> V_212 ,
& V_204 ) ;
if ( F_68 ( V_14 -> V_225 ) ) {
F_71 ( V_14 -> V_224 ) ;
return F_69 ( V_14 -> V_225 ) ;
}
F_70 ( V_14 -> V_225 , & V_14 -> V_2 -> V_19 ) ;
}
return 0 ;
}
static void F_72 ( struct V_14 * V_14 )
{
if ( V_14 -> V_224 ) {
F_71 ( V_14 -> V_224 ) ;
V_14 -> V_224 = NULL ;
F_71 ( V_14 -> V_225 ) ;
V_14 -> V_225 = NULL ;
}
}
static T_3 F_73 ( struct V_160 * V_19 ,
struct V_226
* V_227 , char * V_3 )
{
struct V_1 * V_2 = F_52 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
return snprintf ( V_3 , V_228 , L_12 , V_14 -> V_16 . V_98 ) ;
}
static T_3 F_74 ( struct V_160 * V_19 ,
struct V_226 * V_227 ,
const char * V_3 , T_2 V_162 )
{
struct V_1 * V_2 = F_52 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
T_1 V_229 ;
if ( F_75 ( V_3 , 0 , & V_229 ) )
return - V_94 ;
if ( V_229 != 0 && V_229 != 1 )
return - V_94 ;
F_33 ( V_2 , V_229 , & V_14 -> V_16 . V_33 ) ;
return V_162 ;
}
static T_3 F_76 ( struct V_230 * V_172 ,
struct V_231 * V_232 ,
char * V_3 , int V_233 )
{
struct V_160 * V_19 = F_77 ( V_172 -> V_234 ) ;
struct V_1 * V_2 = F_52 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
T_1 V_235 ;
V_235 = V_14 -> V_144 . V_145 [ V_233 ] ;
if ( V_235 >= 0 && V_235 < 3 )
return snprintf ( V_3 , V_228 , L_13 , V_235 ) ;
else
return snprintf ( V_3 , V_228 , L_13 , - 1 ) ;
}
int F_78 ( struct V_14 * V_14 , T_5 V_236 , int V_233 )
{
int error = 0 ;
char * V_3 ;
struct V_16 * V_16 = & V_14 -> V_16 ;
V_16 -> V_236 [ V_233 ] = V_236 ;
V_3 = F_16 ( V_237 , V_39 ) ;
if ( ! V_3 )
return - V_92 ;
snprintf ( V_3 , V_237 , L_14 , V_236 ) ;
V_14 -> V_238 [ V_233 ] . V_218 = V_3 ;
error = F_57 ( V_14 -> V_239 ,
& V_14 -> V_238 [ V_233 ] ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_9 , error ) ;
F_79 ( V_14 -> V_239 ) ;
return error ;
}
return 0 ;
}
void F_80 ( struct V_14 * V_14 , T_5 V_236 )
{
struct V_16 * V_16 = & V_14 -> V_16 ;
int V_80 ;
if ( ! V_236 )
return;
for ( V_80 = 0 ; V_80 < V_240 ; V_80 ++ ) {
if ( V_16 -> V_236 [ V_80 ] == V_236 ) {
V_16 -> V_236 [ V_80 ] = 0 ;
V_14 -> V_144 . V_145 [ V_80 ] = V_241 ;
if ( V_14 -> V_238 [ V_80 ] . V_218 ) {
F_59 ( V_14 -> V_239 ,
& V_14 -> V_238 [ V_80 ] ) ;
F_18 ( V_14 -> V_238 [ V_80 ] . V_218 ) ;
V_14 -> V_238 [ V_80 ] . V_218 = NULL ;
}
}
}
}
static int F_81 ( struct V_14 * V_14 , unsigned char V_242 )
{
const T_2 V_139 = 2 ;
unsigned char * V_3 ;
int V_6 ;
V_3 = F_16 ( V_139 , V_39 ) ;
if ( ! V_3 )
return - V_92 ;
V_3 [ 0 ] = V_243 ;
V_3 [ 1 ] = V_242 ;
V_6 = F_4 ( V_14 -> V_2 , V_244 , V_3 ,
V_139 , V_42 ) ;
F_18 ( V_3 ) ;
return V_6 ;
}
static T_3 F_82 ( struct V_230 * V_172 ,
struct V_231 * V_227 ,
const char * V_3 , T_2 V_162 )
{
unsigned char V_242 = 0 ;
struct V_160 * V_19 = F_77 ( V_172 -> V_234 ) ;
struct V_1 * V_2 = F_52 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
int V_163 ;
if ( ! strncmp ( V_3 , L_15 , 2 ) ) {
V_242 = V_245 ;
} else {
F_83 ( V_14 -> V_2 , L_16 ,
V_3 ) ;
return - 1 ;
}
F_40 ( & V_14 -> V_164 ) ;
V_163 = F_81 ( V_14 , V_242 ) ;
F_43 ( & V_14 -> V_164 ) ;
return V_163 < 0 ? V_163 : V_162 ;
}
static int F_84 ( struct V_14 * V_14 )
{
int error = 0 ;
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
int V_80 ;
if ( V_14 -> V_16 . V_33 . type != V_246 )
return 0 ;
V_14 -> V_238 [ 0 ] = V_247 ;
V_14 -> V_238 [ 1 ] = V_248 ;
V_14 -> V_238 [ 2 ] = V_249 ;
V_14 -> V_238 [ 3 ] = V_250 ;
V_14 -> V_238 [ 4 ] = V_251 ;
V_14 -> V_239 = F_85 ( L_17 ,
& V_14 -> V_2 -> V_19 . V_172 ) ;
if ( ! V_14 -> V_239 )
return - V_92 ;
error = F_86 ( V_14 -> V_239 , V_252 ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_9 , error ) ;
return error ;
}
for ( V_80 = 0 ; V_80 < V_240 ; V_80 ++ ) {
V_14 -> V_144 . V_145 [ V_80 ] = V_241 ;
V_16 -> V_236 [ V_80 ] = 0 ;
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
V_18 -> V_218 = V_16 -> V_33 . V_218 ;
V_18 -> V_128 = V_2 -> V_128 ;
V_18 -> V_19 . V_234 = & V_2 -> V_19 ;
V_18 -> V_253 = F_8 ;
V_18 -> V_254 = F_11 ;
V_18 -> V_255 = V_2 -> V_255 ;
V_18 -> V_40 . V_256 = V_2 -> V_101 ;
V_18 -> V_40 . V_126 = V_2 -> V_126 ;
V_18 -> V_40 . V_127 = V_16 -> V_122 ? V_16 -> V_122 : V_2 -> V_127 ;
V_18 -> V_40 . V_257 = V_2 -> V_257 ;
F_89 ( V_18 , V_14 ) ;
return V_18 ;
}
static void F_90 ( struct V_14 * V_14 )
{
if ( V_14 -> V_16 . V_258 ) {
if ( V_14 -> V_16 . V_259 )
F_91 ( V_14 -> V_16 . V_258 ) ;
else
F_92 ( V_14 -> V_16 . V_258 ) ;
}
if ( V_14 -> V_16 . V_75 ) {
if ( V_14 -> V_16 . V_260 )
F_91 ( V_14 -> V_16 . V_75 ) ;
else
F_92 ( V_14 -> V_16 . V_75 ) ;
}
if ( V_14 -> V_16 . V_261 ) {
if ( V_14 -> V_16 . V_262 )
F_91 ( V_14 -> V_16 . V_261 ) ;
else
F_92 ( V_14 -> V_16 . V_261 ) ;
}
F_79 ( V_14 -> V_239 ) ;
V_14 -> V_16 . V_258 = NULL ;
V_14 -> V_16 . V_75 = NULL ;
V_14 -> V_16 . V_261 = NULL ;
V_14 -> V_16 . V_259 = false ;
V_14 -> V_16 . V_260 = false ;
V_14 -> V_16 . V_262 = false ;
F_58 ( V_14 ) ;
}
static int F_93 ( struct V_14 * V_14 )
{
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
V_16 -> V_258 = F_87 ( V_14 ) ;
V_16 -> V_75 = F_87 ( V_14 ) ;
V_16 -> V_261 = F_87 ( V_14 ) ;
if ( ! V_16 -> V_258 || ! V_16 -> V_75 || ! V_16 -> V_261 ) {
F_90 ( V_14 ) ;
return - V_92 ;
}
V_16 -> V_258 -> V_218 = V_16 -> V_263 ;
V_16 -> V_75 -> V_218 = V_16 -> V_264 ;
V_16 -> V_261 -> V_218 = V_16 -> V_265 ;
return 0 ;
}
static int F_94 ( struct V_14 * V_14 )
{
struct V_18 * V_266 , * V_267 , * V_268 ;
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
int error = 0 ;
V_266 = V_16 -> V_258 ;
V_267 = V_16 -> V_75 ;
V_268 = V_16 -> V_261 ;
if ( ! V_266 || ! V_267 || ! V_268 )
return - V_94 ;
error = F_95 ( V_266 , V_16 ) ;
if ( error ) {
F_92 ( V_266 ) ;
V_16 -> V_258 = NULL ;
V_266 = NULL ;
} else {
error = F_96 ( V_266 ) ;
if ( error )
goto V_269;
V_16 -> V_259 = true ;
}
error = F_97 ( V_267 , V_16 ) ;
if ( error ) {
F_92 ( V_267 ) ;
V_16 -> V_75 = NULL ;
V_267 = NULL ;
} else {
error = F_96 ( V_267 ) ;
if ( error )
goto V_270;
V_16 -> V_260 = true ;
}
error = F_98 ( V_268 , V_16 ) ;
if ( error ) {
F_92 ( V_268 ) ;
V_16 -> V_261 = NULL ;
V_268 = NULL ;
} else {
error = F_96 ( V_268 ) ;
if ( error )
goto V_271;
V_16 -> V_262 = true ;
error = F_56 ( V_14 ) ;
if ( error )
goto V_272;
error = F_84 ( V_14 ) ;
if ( error )
goto V_273;
}
return 0 ;
V_273:
F_58 ( V_14 ) ;
V_272:
F_91 ( V_268 ) ;
V_268 = NULL ;
V_16 -> V_262 = false ;
V_271:
if ( V_267 )
F_91 ( V_267 ) ;
V_16 -> V_75 = NULL ;
V_16 -> V_260 = false ;
V_270:
if ( V_266 )
F_91 ( V_266 ) ;
V_16 -> V_258 = NULL ;
V_16 -> V_259 = false ;
V_269:
return error ;
}
static void F_99 ( struct V_32 * V_33 )
{
if ( V_33 -> V_274 ) {
V_33 -> V_66 = ( V_33 -> V_65 * 100 ) /
V_33 -> V_274 ;
V_33 -> V_71 = ( V_33 -> V_70 * 100 ) /
V_33 -> V_275 ;
}
}
static void F_100 ( struct V_32 * V_33 )
{
if ( ! V_33 -> V_22 ) {
V_33 -> V_22 = 0x11 ;
V_33 -> V_68 = - 3 ;
}
V_33 -> V_274 = F_13 ( V_33 -> V_65 ,
V_33 -> V_66 ,
V_33 -> V_22 ,
V_33 -> V_68 ) ;
V_33 -> V_275 = F_13 ( V_33 -> V_70 ,
V_33 -> V_71 ,
V_33 -> V_22 ,
V_33 -> V_68 ) ;
}
void F_101 ( struct V_276 * V_277 )
{
struct V_14 * V_14 = F_45 ( V_277 , struct V_14 , V_277 ) ;
if ( ( V_14 -> V_16 . V_33 . V_207 & V_208 ) &&
! V_14 -> V_224 ) {
F_63 ( V_14 ) ;
}
else if ( ! ( V_14 -> V_16 . V_33 . V_207 & V_208 ) &&
V_14 -> V_224 ) {
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
T_2 V_278 = F_32 ( V_12 ) ;
if ( V_278 > V_4 )
V_4 = V_278 ;
}
return V_4 ;
}
static void F_103 ( struct V_14 * V_14 , const char * V_279 )
{
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_32 * V_33 = & V_16 -> V_33 ;
char V_218 [ V_280 ] ;
if ( ( V_33 -> type == V_74 ) && ! strcmp ( L_18 , V_33 -> V_218 ) ) {
if ( strstr ( V_14 -> V_2 -> V_218 , L_19 ) ||
strstr ( V_14 -> V_2 -> V_218 , L_20 ) ||
strstr ( V_14 -> V_2 -> V_218 , L_21 ) ) {
F_104 ( V_218 , V_14 -> V_2 -> V_218 , sizeof( V_218 ) ) ;
while ( 1 ) {
char * V_281 = strstr ( V_218 , L_22 ) ;
if ( V_281 == NULL )
break;
memmove ( V_281 , V_281 + 1 , strlen ( V_281 ) ) ;
}
if ( V_218 [ strlen ( V_218 ) - 1 ] == ' ' )
V_218 [ strlen ( V_218 ) - 1 ] = '\0' ;
} else {
snprintf ( V_218 , sizeof( V_218 ) ,
L_23 , V_33 -> V_218 , V_14 -> V_2 -> V_127 ) ;
}
} else {
F_104 ( V_218 , V_33 -> V_218 , sizeof( V_218 ) ) ;
}
snprintf ( V_16 -> V_263 , sizeof( V_16 -> V_263 ) ,
L_24 , V_218 , V_279 ) ;
snprintf ( V_16 -> V_264 , sizeof( V_16 -> V_264 ) ,
L_25 , V_218 , V_279 ) ;
snprintf ( V_16 -> V_265 , sizeof( V_16 -> V_265 ) ,
L_26 , V_218 , V_279 ) ;
}
static int F_105 ( struct V_14 * V_14 , bool V_282 )
{
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_32 * V_33 = & V_16 -> V_33 ;
struct V_1 * V_2 = V_14 -> V_2 ;
int error ;
unsigned int V_283 = V_284 ;
V_33 -> V_285 = F_102 ( V_2 ) ;
if ( V_33 -> V_285 > V_15 )
return - V_94 ;
error = F_93 ( V_14 ) ;
if ( error )
return error ;
if ( V_33 -> type == V_106 ) {
if ( V_33 -> V_285 == V_286 ) {
V_33 -> type = V_74 ;
} else if ( ( V_33 -> V_285 != V_287 ) &&
( V_33 -> V_285 != V_288 ) ) {
error = - V_289 ;
goto V_290;
}
}
F_99 ( V_33 ) ;
F_35 ( V_2 , V_33 ) ;
F_106 ( V_14 ) ;
if ( V_33 -> V_60 == V_118 &&
V_33 -> type != V_113 ) {
error = V_33 -> type == V_74 ? - V_289 : 0 ;
F_107 ( & V_2 -> V_19 , L_27 ,
V_2 -> V_218 ,
error ? L_28 : L_29 ) ;
if ( error )
goto V_291;
V_33 -> V_60 |= V_61 ;
}
F_100 ( V_33 ) ;
F_103 ( V_14 , V_282 ? L_30 : L_31 ) ;
error = F_39 ( V_2 ) ;
if ( error )
goto V_292;
if ( ! ( V_33 -> V_60 & V_117 ) &&
( V_33 -> V_207 & V_208 ) ) {
error = F_63 ( V_14 ) ;
if ( error )
goto V_293;
}
error = F_94 ( V_14 ) ;
if ( error )
goto V_294;
if ( V_33 -> type == V_74 )
V_283 |= V_295 ;
error = F_108 ( V_2 , V_283 ) ;
if ( error ) {
F_3 ( V_2 , L_32 ) ;
goto V_296;
}
if ( ! V_282 ) {
F_34 ( V_2 , V_33 ) ;
}
if ( ( V_33 -> type == V_67 ) &&
( V_33 -> V_60 & V_61 ) ) {
error = - V_289 ;
goto V_296;
}
if ( ( V_33 -> type == V_297 ) &&
( ( V_33 -> V_60 & V_62 ) ||
( V_33 -> V_60 & V_168 ) ) ) {
error = - V_289 ;
goto V_296;
}
if ( V_33 -> V_60 & V_117 )
error = F_10 ( V_2 ) ;
if ( ( V_16 -> V_33 . type == V_298 ||
V_16 -> V_33 . type == V_299 ) &&
( V_16 -> V_33 . V_60 & V_62 ) ) {
V_16 -> V_135 -> V_75 = V_16 -> V_75 ;
}
return 0 ;
V_296:
F_109 ( V_2 ) ;
V_294:
F_90 ( V_14 ) ;
F_72 ( V_14 ) ;
V_293:
F_47 ( V_14 ) ;
V_292:
V_291:
V_290:
F_90 ( V_14 ) ;
return error ;
}
static void F_110 ( struct V_276 * V_277 )
{
struct V_14 * V_14 = F_45 ( V_277 , struct V_14 , V_277 ) ;
struct V_300 * V_301 = V_14 -> V_301 ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_1 * V_302 , * V_303 ;
struct V_14 * V_304 , * V_305 ;
struct V_16 * V_306 , * V_307 ;
int error ;
F_72 ( V_14 ) ;
V_302 = F_111 ( V_301 -> V_308 -> V_309 [ 1 ] ) ;
V_304 = F_6 ( V_302 ) ;
V_306 = & ( V_304 -> V_16 ) ;
F_90 ( V_304 ) ;
V_303 = F_111 ( V_301 -> V_308 -> V_309 [ 2 ] ) ;
V_305 = F_6 ( V_303 ) ;
V_307 = & ( V_305 -> V_16 ) ;
F_90 ( V_305 ) ;
if ( V_16 -> V_122 == 0 ) {
F_83 ( V_14 -> V_2 , L_33 ) ;
V_306 -> V_135 -> type = 0 ;
} else {
const struct V_310 * V_40 = V_311 ;
F_83 ( V_14 -> V_2 , L_34 ,
V_16 -> V_122 ) ;
while ( V_40 -> V_101 ) {
if ( V_40 -> V_126 == V_312 &&
V_40 -> V_127 == V_16 -> V_122 )
break;
V_40 ++ ;
}
if ( ! V_40 -> V_101 ) {
F_83 ( V_14 -> V_2 , L_35 ) ;
return;
}
V_306 -> V_33 =
* ( (struct V_32 * ) V_40 -> V_313 ) ;
V_306 -> V_122 = V_16 -> V_122 ;
F_109 ( V_302 ) ;
error = F_105 ( V_304 , true ) ;
if ( error )
goto V_314;
if ( V_306 -> V_33 . V_38 ||
( V_306 -> V_33 . type >= V_298 &&
V_306 -> V_33 . type <= V_63 ) ) {
V_307 -> V_33 =
* ( (struct V_32 * ) V_40 -> V_313 ) ;
V_307 -> V_122 = V_16 -> V_122 ;
F_109 ( V_303 ) ;
error = F_105 ( V_305 , true ) ;
if ( error )
goto V_314;
}
error = F_63 ( V_14 ) ;
if ( error )
goto V_314;
}
return;
V_314:
F_90 ( V_304 ) ;
F_90 ( V_305 ) ;
return;
}
static int F_112 ( struct V_1 * V_2 ,
const struct V_310 * V_40 )
{
struct V_107 * V_108 = F_113 ( V_2 -> V_19 . V_234 ) ;
struct V_300 * V_19 = F_114 ( V_108 ) ;
struct V_14 * V_14 ;
struct V_16 * V_16 ;
struct V_32 * V_33 ;
int error ;
if ( ! V_40 -> V_313 )
return - V_94 ;
V_2 -> V_207 |= V_315 ;
V_2 -> V_207 &= ~ V_316 ;
V_14 = F_16 ( sizeof( struct V_14 ) , V_39 ) ;
if ( ! V_14 )
return - V_92 ;
F_115 ( V_2 , V_14 ) ;
V_14 -> V_2 = V_2 ;
V_16 = & V_14 -> V_16 ;
V_16 -> V_33 = * ( (struct V_32 * ) V_40 -> V_313 ) ;
V_33 = & V_16 -> V_33 ;
if ( V_33 -> V_317 && V_33 -> V_318 != V_2 -> type ) {
error = - V_289 ;
goto V_319;
}
V_16 -> V_34 . V_46 = - 1 ;
V_16 -> V_52 = - 1 ;
V_14 -> V_301 = V_19 ;
V_14 -> V_108 = V_108 ;
F_116 ( & V_14 -> V_164 ) ;
F_117 ( & V_14 -> V_277 , F_110 ) ;
error = F_118 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_36 ) ;
goto V_320;
}
error = F_105 ( V_14 , false ) ;
if ( error )
goto V_320;
if ( V_2 -> V_101 == V_102 ) {
error = F_119 ( & V_2 -> V_19 , & V_321 ) ;
if ( error )
F_17 ( V_2 ,
L_37 ,
error ) ;
}
return 0 ;
V_319:
V_320:
F_18 ( V_14 ) ;
F_115 ( V_2 , NULL ) ;
return error ;
}
static void F_120 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_32 * V_33 = & V_16 -> V_33 ;
if ( V_33 -> V_60 & V_117 )
F_12 ( V_2 ) ;
F_109 ( V_2 ) ;
F_121 ( & V_14 -> V_277 ) ;
F_90 ( V_14 ) ;
if ( V_2 -> V_101 == V_102 )
F_122 ( & V_2 -> V_19 , & V_321 ) ;
F_72 ( V_14 ) ;
F_47 ( V_14 ) ;
F_115 ( V_2 , NULL ) ;
F_18 ( V_14 ) ;
}
static int F_123 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_32 * V_33 = & V_14 -> V_16 . V_33 ;
F_40 ( & V_14 -> V_164 ) ;
F_34 ( V_2 , V_33 ) ;
F_49 ( V_14 ) ;
F_43 ( & V_14 -> V_164 ) ;
return 0 ;
}
static int F_124 ( struct V_1 * V_2 )
{
return F_123 ( V_2 ) ;
}
