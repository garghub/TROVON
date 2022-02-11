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
if ( V_14 -> V_2 )
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
static bool F_36 ( struct V_1 * V_120 ,
struct V_1 * V_121 , char V_122 )
{
int V_123 = strrchr ( V_120 -> V_124 , V_122 ) - V_120 -> V_124 ;
int V_125 = strrchr ( V_121 -> V_124 , V_122 ) - V_121 -> V_124 ;
if ( V_123 != V_125 || V_123 <= 0 || V_125 <= 0 )
return false ;
return ! strncmp ( V_120 -> V_124 , V_121 -> V_124 , V_123 ) ;
}
static bool F_37 ( struct V_1 * V_2 ,
struct V_1 * V_126 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_32 * V_33 = & V_14 -> V_16 . V_33 ;
struct V_14 * V_127 = F_6 ( V_126 ) ;
struct V_32 * V_128 = & V_127 -> V_16 . V_33 ;
T_3 V_129 = V_33 -> V_129 ? V_33 -> V_129 : V_2 -> V_130 ;
T_3 V_131 = V_33 -> V_131 ? V_33 -> V_131 : V_2 -> V_132 ;
if ( V_33 -> V_129 != V_133 && V_126 -> V_130 != V_129 )
return false ;
if ( V_33 -> V_131 != V_133 && V_126 -> V_132 != V_131 )
return false ;
if ( V_2 -> V_130 == V_126 -> V_130 && V_2 -> V_132 == V_126 -> V_132 ) {
if ( ! F_36 ( V_2 , V_126 , '/' ) )
return false ;
} else {
if ( ! F_36 ( V_2 , V_126 , '.' ) )
return false ;
}
if ( V_33 -> type != V_74 )
return true ;
if ( ( V_33 -> V_60 & V_134 ) &&
! ( V_128 -> V_60 & V_134 ) )
return false ;
if ( ! ( V_33 -> V_60 & V_134 ) &&
( V_128 -> V_60 & V_134 ) )
return false ;
if ( ( V_33 -> V_60 & V_61 ) &&
! ( V_128 -> V_60 & V_62 ) )
return false ;
if ( ( V_33 -> V_60 & V_62 ) &&
! ( V_128 -> V_60 & V_61 ) )
return false ;
return true ;
}
static struct V_135 * F_38 ( struct V_1 * V_2 )
{
struct V_135 * V_17 ;
F_27 (data, &wacom_udev_list, list) {
if ( F_36 ( V_2 , V_17 -> V_19 , '/' ) )
return V_17 ;
}
F_27 (data, &wacom_udev_list, list) {
if ( F_37 ( V_2 , V_17 -> V_19 ) ) {
F_39 ( & V_17 -> V_136 ) ;
return V_17 ;
}
}
return NULL ;
}
static void F_40 ( struct V_136 * V_136 )
{
struct V_135 * V_17 =
F_41 ( V_136 , struct V_135 , V_136 ) ;
F_42 ( & V_137 ) ;
F_43 ( & V_17 -> V_138 ) ;
F_44 ( & V_137 ) ;
F_18 ( V_17 ) ;
}
static void F_45 ( void * V_139 )
{
struct V_14 * V_14 = V_139 ;
struct V_135 * V_17 ;
struct V_16 * V_16 = & V_14 -> V_16 ;
if ( V_16 -> V_140 ) {
V_17 = F_41 ( V_16 -> V_140 , struct V_135 ,
V_140 ) ;
if ( V_16 -> V_140 -> V_141 == V_14 -> V_2 )
V_16 -> V_140 -> V_141 = NULL ;
else if ( V_16 -> V_140 -> V_59 == V_14 -> V_2 )
V_16 -> V_140 -> V_59 = NULL ;
F_46 ( & V_17 -> V_136 , F_40 ) ;
V_16 -> V_140 = NULL ;
}
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_135 * V_17 ;
int V_6 = 0 ;
F_42 ( & V_137 ) ;
V_17 = F_38 ( V_2 ) ;
if ( ! V_17 ) {
V_17 = F_16 ( sizeof( struct V_135 ) , V_39 ) ;
if ( ! V_17 ) {
V_6 = - V_92 ;
goto V_142;
}
F_48 ( & V_17 -> V_136 ) ;
V_17 -> V_19 = V_2 ;
F_49 ( & V_17 -> V_138 , & V_143 ) ;
}
V_16 -> V_140 = & V_17 -> V_140 ;
V_6 = F_50 ( & V_2 -> V_19 , F_45 , V_14 ) ;
if ( V_6 ) {
F_44 ( & V_137 ) ;
F_45 ( V_14 ) ;
return V_6 ;
}
if ( V_16 -> V_33 . V_60 & V_62 )
V_16 -> V_140 -> V_141 = V_2 ;
else if ( V_16 -> V_33 . V_60 & V_61 )
V_16 -> V_140 -> V_59 = V_2 ;
V_142:
F_44 ( & V_137 ) ;
return V_6 ;
}
static int F_51 ( struct V_14 * V_14 )
{
unsigned char * V_3 ;
int V_6 ;
unsigned char V_144 = V_145 ;
int V_146 = 9 ;
if ( ! F_6 ( V_14 -> V_2 ) )
return - V_147 ;
if ( ! V_14 -> V_148 . V_149 )
return - V_150 ;
if ( V_14 -> V_16 . V_151 ) {
V_144 = V_152 ;
V_146 = 13 ;
}
V_3 = F_16 ( V_146 , V_39 ) ;
if ( ! V_3 )
return - V_92 ;
if ( V_14 -> V_16 . V_33 . type >= V_153 &&
V_14 -> V_16 . V_33 . type <= V_154 ) {
int V_155 = V_14 -> V_148 . V_149 [ 0 ] . V_156 & 0x03 ;
int V_157 = ( ( ( V_14 -> V_148 . V_158 & 0x60 ) >> 5 ) - 1 ) & 0x03 ;
int V_159 = 0 ;
unsigned char V_160 = ( V_159 << 4 ) | ( V_157 << 2 ) | ( V_155 ) ;
V_3 [ 0 ] = V_144 ;
if ( V_14 -> V_16 . V_151 ) {
F_1 ( V_14 -> V_2 , V_41 ,
V_3 , V_146 , V_42 ) ;
V_3 [ 0 ] = V_144 ;
V_3 [ 4 ] = V_160 ;
} else
V_3 [ 1 ] = V_160 ;
}
else {
int V_148 = V_14 -> V_148 . V_149 [ 0 ] . V_156 | 0x4 ;
if ( V_14 -> V_16 . V_33 . type == V_161 ||
V_14 -> V_16 . V_33 . type == V_162 )
V_148 |= ( V_14 -> V_148 . V_149 [ 1 ] . V_156 << 4 ) | 0x40 ;
V_3 [ 0 ] = V_144 ;
V_3 [ 1 ] = V_148 ;
V_3 [ 2 ] = V_14 -> V_148 . V_158 ;
V_3 [ 3 ] = V_14 -> V_148 . V_163 ;
V_3 [ 4 ] = V_14 -> V_148 . V_164 ;
}
V_6 = F_4 ( V_14 -> V_2 , V_41 , V_3 , V_146 ,
V_42 ) ;
F_18 ( V_3 ) ;
return V_6 ;
}
static int F_52 ( struct V_14 * V_14 , int V_165 , T_1 V_166 ,
const unsigned V_167 , const void * V_168 )
{
unsigned char * V_3 ;
int V_80 , V_6 ;
const unsigned V_169 = V_167 / 4 ;
V_3 = F_16 ( V_169 + 3 , V_39 ) ;
if ( ! V_3 )
return - V_92 ;
V_3 [ 0 ] = V_170 ;
V_3 [ 1 ] = 1 ;
V_6 = F_4 ( V_14 -> V_2 , V_41 , V_3 , 2 ,
V_42 ) ;
if ( V_6 < 0 )
goto V_142;
V_3 [ 0 ] = V_166 ;
V_3 [ 1 ] = V_165 & 0x07 ;
for ( V_80 = 0 ; V_80 < 4 ; V_80 ++ ) {
V_3 [ 2 ] = V_80 ;
memcpy ( V_3 + 3 , V_168 + V_80 * V_169 , V_169 ) ;
V_6 = F_4 ( V_14 -> V_2 , V_41 ,
V_3 , V_169 + 3 , V_42 ) ;
if ( V_6 < 0 )
break;
}
V_3 [ 0 ] = V_170 ;
V_3 [ 1 ] = 0 ;
F_4 ( V_14 -> V_2 , V_41 , V_3 , 2 ,
V_42 ) ;
V_142:
F_18 ( V_3 ) ;
return V_6 ;
}
static T_4 F_53 ( struct V_171 * V_19 , int V_172 ,
const char * V_3 , T_2 V_173 )
{
struct V_1 * V_2 = F_54 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
unsigned int V_40 ;
int V_174 ;
V_174 = F_55 ( V_3 , 10 , & V_40 ) ;
if ( V_174 )
return V_174 ;
F_42 ( & V_14 -> V_175 ) ;
V_14 -> V_148 . V_149 [ V_172 ] . V_156 = V_40 & 0x3 ;
V_174 = F_51 ( V_14 ) ;
F_44 ( & V_14 -> V_175 ) ;
return V_174 < 0 ? V_174 : V_173 ;
}
static T_4 F_56 ( struct V_14 * V_14 , T_1 * V_176 ,
const char * V_3 , T_2 V_173 )
{
unsigned int V_89 ;
int V_174 ;
V_174 = F_55 ( V_3 , 10 , & V_89 ) ;
if ( V_174 )
return V_174 ;
F_42 ( & V_14 -> V_175 ) ;
* V_176 = V_89 & 0x7f ;
V_174 = F_51 ( V_14 ) ;
F_44 ( & V_14 -> V_175 ) ;
return V_174 < 0 ? V_174 : V_173 ;
}
static T_4 F_57 ( struct V_171 * V_19 , int V_165 ,
const char * V_3 , T_2 V_173 )
{
struct V_1 * V_2 = F_54 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
int V_174 ;
unsigned V_167 ;
T_1 V_166 ;
if ( V_2 -> V_101 == V_102 ) {
V_167 = 256 ;
V_166 = V_177 ;
} else {
V_167 = 1024 ;
V_166 = V_178 ;
}
if ( V_173 != V_167 )
return - V_94 ;
F_42 ( & V_14 -> V_175 ) ;
V_174 = F_52 ( V_14 , V_165 , V_166 , V_167 , V_3 ) ;
F_44 ( & V_14 -> V_175 ) ;
return V_174 < 0 ? V_174 : V_173 ;
}
static void F_58 ( struct V_171 * V_19 , void * V_139 )
{
struct V_179 * V_180 = V_139 ;
struct V_181 * V_182 = V_180 -> V_183 ;
F_59 ( V_19 , L_9 ,
V_184 , V_180 -> V_185 -> V_186 ) ;
F_60 ( V_182 , V_180 -> V_185 ) ;
}
static int F_61 ( struct V_14 * V_14 ,
struct V_181 * V_183 ,
struct V_187 * V_185 )
{
struct V_179 * V_180 ;
int error ;
V_180 = F_62 ( F_58 ,
sizeof( struct V_179 ) ,
V_39 ) ;
if ( ! V_180 )
return - V_92 ;
V_180 -> V_185 = V_185 ;
V_180 -> V_183 = V_183 ;
error = F_63 ( V_180 -> V_183 , V_185 ) ;
if ( error )
return error ;
F_64 ( & V_14 -> V_2 -> V_19 , V_180 ) ;
return 0 ;
}
static int F_65 ( struct V_14 * V_14 ,
struct V_187 * V_185 )
{
return F_61 ( V_14 , & V_14 -> V_2 -> V_19 . V_182 ,
V_185 ) ;
}
enum V_188 F_66 ( struct V_189 * V_148 )
{
struct V_14 * V_14 = V_148 -> V_14 ;
if ( V_14 -> V_148 . V_190 )
return V_148 -> V_163 * V_191 / V_14 -> V_148 . V_190 ;
if ( V_14 -> V_148 . V_192 )
return V_148 -> V_158 * V_191 / V_14 -> V_148 . V_192 ;
return V_191 ;
}
static enum V_188 F_67 ( struct V_193 * V_194 )
{
struct V_189 * V_148 = F_41 ( V_194 , struct V_189 , V_194 ) ;
struct V_14 * V_14 = V_148 -> V_14 ;
if ( V_14 -> V_148 . V_149 [ V_148 -> V_185 ] . V_156 != V_148 -> V_40 )
return V_195 ;
return F_66 ( V_148 ) ;
}
static int F_68 ( struct V_193 * V_194 ,
enum V_188 V_196 )
{
struct V_189 * V_148 = F_41 ( V_194 , struct V_189 , V_194 ) ;
struct V_14 * V_14 = V_148 -> V_14 ;
int error ;
F_42 ( & V_14 -> V_175 ) ;
if ( ! V_14 -> V_148 . V_149 || ( V_196 == V_195 &&
V_14 -> V_148 . V_149 [ V_148 -> V_185 ] . V_156 != V_148 -> V_40 ) ) {
error = 0 ;
goto V_142;
}
V_148 -> V_158 = V_14 -> V_148 . V_158 = V_14 -> V_148 . V_192 * V_196 / V_191 ;
V_148 -> V_163 = V_14 -> V_148 . V_163 = V_14 -> V_148 . V_190 * V_196 / V_191 ;
V_14 -> V_148 . V_149 [ V_148 -> V_185 ] . V_156 = V_148 -> V_40 ;
error = F_51 ( V_14 ) ;
V_142:
F_44 ( & V_14 -> V_175 ) ;
return error ;
}
static void F_69 ( struct V_193 * V_194 ,
enum V_188 V_196 )
{
}
static int F_70 ( struct V_171 * V_19 , struct V_14 * V_14 ,
struct V_189 * V_148 , unsigned int V_185 ,
unsigned int V_40 , bool V_197 )
{
int error ;
char * V_186 ;
V_186 = F_71 ( V_19 , V_39 ,
L_10 ,
F_72 ( V_19 ) ,
V_185 ,
V_40 ) ;
if ( ! V_186 )
return - V_92 ;
if ( ! V_197 ) {
V_148 -> V_198 . V_186 = V_186 ;
error = F_73 ( V_19 , & V_148 -> V_198 ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_11 ,
V_148 -> V_194 . V_186 , error ) ;
return error ;
}
}
V_148 -> V_185 = V_185 ;
V_148 -> V_40 = V_40 ;
V_148 -> V_14 = V_14 ;
V_148 -> V_158 = V_14 -> V_148 . V_158 ;
V_148 -> V_163 = V_14 -> V_148 . V_163 ;
V_148 -> V_194 . V_186 = V_186 ;
V_148 -> V_194 . V_199 = V_191 ;
V_148 -> V_194 . V_200 = V_201 ;
V_148 -> V_194 . V_202 = F_67 ;
if ( ! V_197 ) {
V_148 -> V_194 . V_203 = F_68 ;
V_148 -> V_194 . V_204 = V_148 -> V_194 . V_186 ;
} else {
V_148 -> V_194 . V_205 = F_69 ;
}
error = F_74 ( V_19 , & V_148 -> V_194 ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_12 ,
V_148 -> V_194 . V_186 , error ) ;
V_148 -> V_194 . V_186 = NULL ;
return error ;
}
return 0 ;
}
static void F_75 ( void * V_17 )
{
struct V_206 * V_185 = V_17 ;
F_76 ( V_185 -> V_19 , V_185 ) ;
}
static int F_77 ( struct V_171 * V_19 ,
struct V_14 * V_14 ,
int V_207 , int V_173 ,
bool V_197 )
{
struct V_189 * V_208 ;
int V_80 , error ;
if ( V_207 >= V_14 -> V_148 . V_173 || V_173 <= 0 )
return - V_94 ;
if ( ! F_78 ( V_19 , & V_14 -> V_148 . V_149 [ V_207 ] , V_39 ) )
return - V_92 ;
V_208 = F_79 ( V_19 , sizeof( struct V_189 ) * V_173 , V_39 ) ;
if ( ! V_208 ) {
error = - V_92 ;
goto V_174;
}
V_14 -> V_148 . V_149 [ V_207 ] . V_208 = V_208 ;
V_14 -> V_148 . V_149 [ V_207 ] . V_173 = V_173 ;
for ( V_80 = 0 ; V_80 < V_173 ; V_80 ++ ) {
error = F_70 ( V_19 , V_14 , & V_208 [ V_80 ] ,
V_207 , V_80 , V_197 ) ;
if ( error )
goto V_174;
}
V_14 -> V_148 . V_149 [ V_207 ] . V_19 = V_19 ;
F_80 ( V_19 , & V_14 -> V_148 . V_149 [ V_207 ] ) ;
error = F_81 ( & V_14 -> V_2 -> V_19 ,
F_75 ,
& V_14 -> V_148 . V_149 [ V_207 ] ) ;
if ( error )
return error ;
return 0 ;
V_174:
F_76 ( V_19 , & V_14 -> V_148 . V_149 [ V_207 ] ) ;
return error ;
}
struct V_189 * F_82 ( struct V_14 * V_14 , unsigned int V_207 ,
unsigned int V_40 )
{
struct V_206 * V_185 ;
if ( V_207 >= V_14 -> V_148 . V_173 )
return NULL ;
V_185 = & V_14 -> V_148 . V_149 [ V_207 ] ;
if ( ! V_185 -> V_208 )
return NULL ;
V_40 %= V_185 -> V_173 ;
return & V_185 -> V_208 [ V_40 ] ;
}
struct V_189 * F_83 ( struct V_14 * V_14 , struct V_189 * V_209 )
{
struct V_189 * V_210 ;
int V_185 , V_211 ;
if ( ! V_14 || ! V_209 )
return NULL ;
V_185 = V_209 -> V_185 ;
V_211 = V_209 -> V_40 ;
do {
V_210 = F_82 ( V_14 , V_185 , ++ V_211 ) ;
if ( ! V_210 || V_210 == V_209 )
return V_210 ;
} while ( V_210 -> V_194 . V_198 != & V_210 -> V_198 );
return V_210 ;
}
static void F_84 ( void * V_17 )
{
struct V_14 * V_14 = V_17 ;
V_14 -> V_148 . V_149 = NULL ;
V_14 -> V_148 . V_173 = 0 ;
}
static int F_85 ( struct V_14 * V_14 , int V_173 )
{
struct V_171 * V_19 = & V_14 -> V_2 -> V_19 ;
struct V_206 * V_149 ;
int error ;
V_149 = F_79 ( V_19 , sizeof( struct V_206 ) * V_173 ,
V_39 ) ;
if ( ! V_149 )
return - V_92 ;
error = F_81 ( V_19 , F_84 , V_14 ) ;
if ( error )
return error ;
V_14 -> V_148 . V_149 = V_149 ;
V_14 -> V_148 . V_173 = V_173 ;
return 0 ;
}
static int F_86 ( struct V_14 * V_14 , int V_212 ,
int V_213 , bool V_197 )
{
struct V_171 * V_19 ;
int V_80 , error ;
if ( ! V_14 -> V_16 . V_214 )
return - V_94 ;
V_19 = & V_14 -> V_16 . V_214 -> V_19 ;
error = F_85 ( V_14 , V_212 ) ;
if ( error )
return error ;
for ( V_80 = 0 ; V_80 < V_212 ; V_80 ++ ) {
error = F_77 ( V_19 , V_14 , V_80 ,
V_213 ,
V_197 ) ;
if ( error )
return error ;
}
return 0 ;
}
static int F_87 ( struct V_14 * V_14 )
{
int error ;
if ( ! ( V_14 -> V_16 . V_33 . V_60 & V_215 ) )
return 0 ;
switch ( V_14 -> V_16 . V_33 . type ) {
case V_216 :
case V_217 :
case V_99 :
case V_218 :
V_14 -> V_148 . V_158 = 10 ;
V_14 -> V_148 . V_163 = 20 ;
V_14 -> V_148 . V_192 = 127 ;
V_14 -> V_148 . V_190 = 127 ;
V_14 -> V_148 . V_164 = 10 ;
error = F_86 ( V_14 , 1 , 4 , false ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_13 , error ) ;
return error ;
}
error = F_65 ( V_14 ,
& V_219 ) ;
break;
case V_162 :
case V_161 :
V_14 -> V_148 . V_158 = 0 ;
V_14 -> V_148 . V_163 = 0 ;
V_14 -> V_148 . V_164 = 0 ;
error = F_86 ( V_14 , 2 , 4 , false ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_13 , error ) ;
return error ;
}
error = F_65 ( V_14 ,
& V_220 ) ;
break;
case V_153 :
case V_221 :
case V_222 :
case V_223 :
case V_224 :
case V_154 :
V_14 -> V_148 . V_158 = 32 ;
V_14 -> V_148 . V_192 = 96 ;
error = F_86 ( V_14 , 1 , 4 , false ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_13 , error ) ;
return error ;
}
error = F_65 ( V_14 ,
& V_225 ) ;
break;
case V_226 :
V_14 -> V_148 . V_158 = 255 ;
V_14 -> V_148 . V_192 = 255 ;
error = F_85 ( V_14 , 5 ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_13 , error ) ;
return error ;
}
return 0 ;
default:
return 0 ;
}
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_14 , error ) ;
return error ;
}
F_51 ( V_14 ) ;
return 0 ;
}
static int F_88 ( struct V_227 * V_228 ,
enum V_229 V_230 ,
union V_231 * V_232 )
{
struct V_233 * V_234 = F_89 ( V_228 ) ;
int V_35 = 0 ;
switch ( V_230 ) {
case V_235 :
V_232 -> V_236 = V_234 -> V_14 -> V_16 . V_186 ;
break;
case V_237 :
V_232 -> V_238 = V_234 -> V_239 ;
break;
case V_240 :
V_232 -> V_238 = V_241 ;
break;
case V_242 :
V_232 -> V_238 = V_234 -> V_243 ;
break;
case V_244 :
if ( V_234 -> V_245 )
V_232 -> V_238 = V_246 ;
else if ( V_234 -> V_243 == 100 &&
V_234 -> V_247 )
V_232 -> V_238 = V_248 ;
else if ( V_234 -> V_247 )
V_232 -> V_238 = V_249 ;
else
V_232 -> V_238 = V_250 ;
break;
default:
V_35 = - V_94 ;
break;
}
return V_35 ;
}
static int F_90 ( struct V_14 * V_14 ,
struct V_233 * V_234 )
{
static T_5 V_251 = F_91 ( 0 ) ;
struct V_171 * V_19 = & V_14 -> V_2 -> V_19 ;
struct V_252 V_253 = { . V_254 = V_234 , } ;
struct V_227 * V_255 ;
struct V_256 * V_257 = & V_234 -> V_257 ;
unsigned long V_258 ;
int error ;
if ( ! F_78 ( V_19 , V_257 , V_39 ) )
return - V_92 ;
V_234 -> V_14 = V_14 ;
V_258 = F_92 ( & V_251 ) - 1 ;
V_257 -> V_259 = V_260 ;
V_257 -> V_261 = F_93 ( V_260 ) ;
V_257 -> V_262 = F_88 ;
sprintf ( V_234 -> V_263 , L_15 , V_258 ) ;
V_257 -> V_186 = V_234 -> V_263 ;
V_257 -> type = V_264 ;
V_257 -> V_265 = 0 ;
V_255 = F_94 ( V_19 , V_257 , & V_253 ) ;
if ( F_95 ( V_255 ) ) {
error = F_96 ( V_255 ) ;
goto V_174;
}
F_97 ( V_255 , & V_14 -> V_2 -> V_19 ) ;
V_234 -> V_234 = V_255 ;
F_80 ( V_19 , V_257 ) ;
return 0 ;
V_174:
F_76 ( V_19 , V_257 ) ;
return error ;
}
static int F_98 ( struct V_14 * V_14 )
{
if ( V_14 -> V_16 . V_33 . V_266 & V_267 )
return F_90 ( V_14 , & V_14 -> V_234 ) ;
return 0 ;
}
static void F_99 ( struct V_14 * V_14 )
{
if ( V_14 -> V_234 . V_234 ) {
F_76 ( & V_14 -> V_2 -> V_19 ,
& V_14 -> V_234 . V_257 ) ;
V_14 -> V_234 . V_234 = NULL ;
}
}
static T_4 F_100 ( struct V_171 * V_19 ,
struct V_268
* V_269 , char * V_3 )
{
struct V_1 * V_2 = F_54 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
return snprintf ( V_3 , V_270 , L_16 , V_14 -> V_16 . V_98 ) ;
}
static T_4 F_101 ( struct V_171 * V_19 ,
struct V_268 * V_269 ,
const char * V_3 , T_2 V_173 )
{
struct V_1 * V_2 = F_54 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
T_1 V_271 ;
if ( F_102 ( V_3 , 0 , & V_271 ) )
return - V_94 ;
if ( V_271 != 0 && V_271 != 1 )
return - V_94 ;
F_33 ( V_2 , V_271 , & V_14 -> V_16 . V_33 ) ;
return V_173 ;
}
static T_4 F_103 ( struct V_181 * V_182 ,
struct V_272 * V_273 ,
char * V_3 , int V_274 )
{
struct V_171 * V_19 = F_104 ( V_182 -> V_275 ) ;
struct V_1 * V_2 = F_54 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
T_1 V_276 ;
V_276 = V_14 -> V_148 . V_149 [ V_274 ] . V_156 ;
if ( V_276 >= 0 && V_276 < 3 )
return snprintf ( V_3 , V_270 , L_17 , V_276 ) ;
else
return snprintf ( V_3 , V_270 , L_17 , - 1 ) ;
}
static int F_105 ( struct V_14 * V_14 , T_3 V_277 ,
int V_274 )
{
int error = 0 ;
struct V_278 * V_279 = V_14 -> V_279 ;
V_279 -> V_280 [ V_274 ] . V_185 . V_186 = F_71 ( & V_14 -> V_2 -> V_19 ,
V_39 ,
L_18 , V_277 ) ;
if ( ! V_279 -> V_280 [ V_274 ] . V_185 . V_186 )
return - V_92 ;
error = F_61 ( V_14 , V_279 -> V_281 ,
& V_279 -> V_280 [ V_274 ] . V_185 ) ;
if ( error ) {
V_279 -> V_280 [ V_274 ] . V_185 . V_186 = NULL ;
F_3 ( V_14 -> V_2 ,
L_14 , error ) ;
return error ;
}
return 0 ;
}
static int F_106 ( struct V_14 * V_14 , unsigned char V_282 )
{
const T_2 V_146 = 2 ;
unsigned char * V_3 ;
int V_6 ;
V_3 = F_16 ( V_146 , V_39 ) ;
if ( ! V_3 )
return - V_92 ;
V_3 [ 0 ] = V_283 ;
V_3 [ 1 ] = V_282 ;
V_6 = F_4 ( V_14 -> V_2 , V_284 , V_3 ,
V_146 , V_42 ) ;
F_18 ( V_3 ) ;
return V_6 ;
}
static T_4 F_107 ( struct V_181 * V_182 ,
struct V_272 * V_269 ,
const char * V_3 , T_2 V_173 )
{
unsigned char V_282 = 0 ;
struct V_171 * V_19 = F_104 ( V_182 -> V_275 ) ;
struct V_1 * V_2 = F_54 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
int V_174 ;
if ( ! strncmp ( V_3 , L_19 , 2 ) ) {
V_282 = V_285 ;
} else {
F_108 ( V_14 -> V_2 , L_20 ,
V_3 ) ;
return - 1 ;
}
F_42 ( & V_14 -> V_175 ) ;
V_174 = F_106 ( V_14 , V_282 ) ;
F_44 ( & V_14 -> V_175 ) ;
return V_174 < 0 ? V_174 : V_173 ;
}
static void F_109 ( void * V_17 )
{
struct V_14 * V_14 = V_17 ;
struct V_278 * V_279 = V_14 -> V_279 ;
if ( ! V_279 )
return;
F_110 ( V_279 -> V_281 ) ;
F_111 ( & V_279 -> V_286 ) ;
V_14 -> V_279 = NULL ;
}
static int F_112 ( struct V_14 * V_14 )
{
int error = 0 ;
struct V_278 * V_279 ;
int V_80 ;
if ( V_14 -> V_16 . V_33 . type != V_226 )
return 0 ;
V_279 = F_79 ( & V_14 -> V_2 -> V_19 , sizeof( * V_14 -> V_279 ) ,
V_39 ) ;
if ( ! V_279 )
return - V_92 ;
V_14 -> V_279 = V_279 ;
F_113 ( & V_279 -> V_287 ) ;
error = F_114 ( & V_279 -> V_286 ,
5 * sizeof( struct V_288 ) ,
V_39 ) ;
if ( error ) {
F_3 ( V_14 -> V_2 , L_21 ) ;
return - V_92 ;
}
V_279 -> V_280 [ 0 ] . V_185 = V_289 ;
V_279 -> V_280 [ 1 ] . V_185 = V_290 ;
V_279 -> V_280 [ 2 ] . V_185 = V_291 ;
V_279 -> V_280 [ 3 ] . V_185 = V_292 ;
V_279 -> V_280 [ 4 ] . V_185 = V_293 ;
V_279 -> V_281 = F_115 ( L_22 ,
& V_14 -> V_2 -> V_19 . V_182 ) ;
if ( ! V_279 -> V_281 )
return - V_92 ;
error = F_116 ( V_279 -> V_281 , V_294 ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_14 , error ) ;
return error ;
}
for ( V_80 = 0 ; V_80 < V_295 ; V_80 ++ ) {
V_14 -> V_148 . V_149 [ V_80 ] . V_156 = V_296 ;
V_279 -> V_280 [ V_80 ] . V_277 = 0 ;
}
error = F_81 ( & V_14 -> V_2 -> V_19 ,
F_109 , V_14 ) ;
if ( error )
return error ;
return 0 ;
}
static struct V_18 * F_117 ( struct V_14 * V_14 )
{
struct V_18 * V_18 ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
V_18 = F_118 ( & V_2 -> V_19 ) ;
if ( ! V_18 )
return NULL ;
V_18 -> V_186 = V_16 -> V_33 . V_186 ;
V_18 -> V_124 = V_2 -> V_124 ;
V_18 -> V_19 . V_275 = & V_2 -> V_19 ;
V_18 -> V_297 = F_8 ;
V_18 -> V_298 = F_11 ;
V_18 -> V_299 = V_2 -> V_299 ;
V_18 -> V_40 . V_300 = V_2 -> V_101 ;
V_18 -> V_40 . V_130 = V_2 -> V_130 ;
V_18 -> V_40 . V_132 = V_16 -> V_151 ? V_16 -> V_151 : V_2 -> V_132 ;
V_18 -> V_40 . V_301 = V_2 -> V_301 ;
F_119 ( V_18 , V_14 ) ;
return V_18 ;
}
static int F_120 ( struct V_14 * V_14 )
{
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
V_16 -> V_302 = F_117 ( V_14 ) ;
V_16 -> V_75 = F_117 ( V_14 ) ;
V_16 -> V_214 = F_117 ( V_14 ) ;
if ( ! V_16 -> V_302 ||
! V_16 -> V_75 ||
! V_16 -> V_214 )
return - V_92 ;
V_16 -> V_302 -> V_186 = V_16 -> V_303 ;
V_16 -> V_75 -> V_186 = V_16 -> V_304 ;
V_16 -> V_214 -> V_186 = V_16 -> V_305 ;
return 0 ;
}
static int F_121 ( struct V_14 * V_14 )
{
struct V_18 * V_306 , * V_307 , * V_308 ;
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
int error = 0 ;
V_306 = V_16 -> V_302 ;
V_307 = V_16 -> V_75 ;
V_308 = V_16 -> V_214 ;
if ( ! V_306 || ! V_307 || ! V_308 )
return - V_94 ;
error = F_122 ( V_306 , V_16 ) ;
if ( error ) {
F_123 ( V_306 ) ;
V_16 -> V_302 = NULL ;
V_306 = NULL ;
} else {
error = F_124 ( V_306 ) ;
if ( error )
goto V_309;
}
error = F_125 ( V_307 , V_16 ) ;
if ( error ) {
F_123 ( V_307 ) ;
V_16 -> V_75 = NULL ;
V_307 = NULL ;
} else {
error = F_124 ( V_307 ) ;
if ( error )
goto V_309;
}
error = F_126 ( V_308 , V_16 ) ;
if ( error ) {
F_123 ( V_308 ) ;
V_16 -> V_214 = NULL ;
V_308 = NULL ;
} else {
error = F_124 ( V_308 ) ;
if ( error )
goto V_309;
}
return 0 ;
V_309:
V_16 -> V_214 = NULL ;
V_16 -> V_75 = NULL ;
V_16 -> V_302 = NULL ;
return error ;
}
static void F_127 ( struct V_32 * V_33 )
{
if ( V_33 -> V_310 ) {
V_33 -> V_66 = ( V_33 -> V_65 * 100 ) /
V_33 -> V_310 ;
V_33 -> V_71 = ( V_33 -> V_70 * 100 ) /
V_33 -> V_311 ;
}
}
static void F_128 ( struct V_32 * V_33 )
{
if ( ! V_33 -> V_22 ) {
V_33 -> V_22 = 0x11 ;
V_33 -> V_68 = - 3 ;
}
V_33 -> V_310 = F_13 ( V_33 -> V_65 ,
V_33 -> V_66 ,
V_33 -> V_22 ,
V_33 -> V_68 ) ;
V_33 -> V_311 = F_13 ( V_33 -> V_70 ,
V_33 -> V_71 ,
V_33 -> V_22 ,
V_33 -> V_68 ) ;
}
void F_129 ( struct V_312 * V_313 )
{
struct V_14 * V_14 = F_41 ( V_313 , struct V_14 , V_314 ) ;
if ( ( V_14 -> V_16 . V_33 . V_266 & V_267 ) &&
! V_14 -> V_234 . V_234 ) {
F_98 ( V_14 ) ;
}
else if ( ! ( V_14 -> V_16 . V_33 . V_266 & V_267 ) &&
V_14 -> V_234 . V_234 ) {
F_99 ( V_14 ) ;
}
}
static T_2 F_130 ( struct V_1 * V_2 )
{
struct V_77 * V_82 ;
struct V_11 * V_12 ;
T_2 V_4 = 0 ;
V_82 = V_2 -> V_82 + V_85 ;
F_27 (report, &report_enum->report_list, list) {
T_2 V_315 = F_32 ( V_12 ) ;
if ( V_315 > V_4 )
V_4 = V_315 ;
}
return V_4 ;
}
static void F_131 ( struct V_14 * V_14 , const char * V_316 )
{
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_32 * V_33 = & V_16 -> V_33 ;
char V_186 [ V_317 ] ;
if ( ( V_33 -> type == V_74 ) && ! strcmp ( L_23 , V_33 -> V_186 ) ) {
if ( strstr ( V_14 -> V_2 -> V_186 , L_24 ) ||
strstr ( V_14 -> V_2 -> V_186 , L_25 ) ||
strstr ( V_14 -> V_2 -> V_186 , L_26 ) ) {
F_132 ( V_186 , V_14 -> V_2 -> V_186 , sizeof( V_186 ) ) ;
while ( 1 ) {
char * V_318 = strstr ( V_186 , L_27 ) ;
if ( V_318 == NULL )
break;
memmove ( V_318 , V_318 + 1 , strlen ( V_318 ) ) ;
}
if ( V_186 [ strlen ( V_186 ) - 1 ] == ' ' )
V_186 [ strlen ( V_186 ) - 1 ] = '\0' ;
} else {
snprintf ( V_186 , sizeof( V_186 ) ,
L_28 , V_33 -> V_186 , V_14 -> V_2 -> V_132 ) ;
}
} else {
F_132 ( V_186 , V_33 -> V_186 , sizeof( V_186 ) ) ;
}
snprintf ( V_16 -> V_186 , sizeof( V_16 -> V_186 ) , L_29 ,
V_186 , V_316 ) ;
snprintf ( V_16 -> V_303 , sizeof( V_16 -> V_303 ) ,
L_30 , V_186 , V_316 ) ;
snprintf ( V_16 -> V_304 , sizeof( V_16 -> V_304 ) ,
L_31 , V_186 , V_316 ) ;
snprintf ( V_16 -> V_305 , sizeof( V_16 -> V_305 ) ,
L_32 , V_186 , V_316 ) ;
}
static void F_133 ( struct V_14 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
if ( ! V_14 -> V_319 )
return;
F_76 ( & V_2 -> V_19 , V_14 ) ;
V_14 -> V_319 = false ;
V_14 -> V_16 . V_302 = NULL ;
V_14 -> V_16 . V_75 = NULL ;
V_14 -> V_16 . V_214 = NULL ;
}
static int F_134 ( struct V_14 * V_14 , bool V_320 )
{
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_32 * V_33 = & V_16 -> V_33 ;
struct V_1 * V_2 = V_14 -> V_2 ;
int error ;
unsigned int V_321 = V_322 ;
V_33 -> V_323 = F_130 ( V_2 ) ;
if ( V_33 -> V_323 > V_15 )
return - V_94 ;
if ( ! F_78 ( & V_2 -> V_19 , V_14 , V_39 ) )
return - V_92 ;
V_14 -> V_319 = true ;
error = F_120 ( V_14 ) ;
if ( error )
goto V_309;
if ( V_33 -> type == V_106 ) {
if ( V_33 -> V_323 == V_324 ) {
V_33 -> type = V_74 ;
} else if ( ( V_33 -> V_323 != V_325 ) &&
( V_33 -> V_323 != V_326 ) ) {
error = - V_147 ;
goto V_309;
}
}
F_127 ( V_33 ) ;
F_35 ( V_2 , V_33 ) ;
F_135 ( V_14 ) ;
if ( V_33 -> V_60 == V_119 &&
V_33 -> type != V_114 ) {
error = V_33 -> type == V_74 ? - V_147 : 0 ;
F_136 ( & V_2 -> V_19 , L_33 ,
V_2 -> V_186 ,
error ? L_34 : L_35 ) ;
if ( error )
goto V_309;
V_33 -> V_60 |= V_61 ;
}
F_128 ( V_33 ) ;
F_131 ( V_14 , V_320 ? L_36 : L_37 ) ;
error = F_47 ( V_2 ) ;
if ( error )
goto V_309;
if ( ! ( V_33 -> V_60 & V_118 ) &&
( V_33 -> V_266 & V_267 ) ) {
error = F_98 ( V_14 ) ;
if ( error )
goto V_309;
}
error = F_121 ( V_14 ) ;
if ( error )
goto V_309;
if ( V_14 -> V_16 . V_33 . V_60 & V_215 ) {
error = F_87 ( V_14 ) ;
if ( error )
goto V_309;
error = F_112 ( V_14 ) ;
if ( error )
goto V_309;
}
if ( V_33 -> type == V_74 )
V_321 |= V_327 ;
error = F_137 ( V_2 , V_321 ) ;
if ( error ) {
F_3 ( V_2 , L_38 ) ;
goto V_309;
}
if ( ! V_320 ) {
F_34 ( V_2 , V_33 ) ;
}
if ( ( V_33 -> type == V_67 ) &&
( V_33 -> V_60 & V_61 ) ) {
error = - V_147 ;
goto V_328;
}
if ( ( V_33 -> type == V_329 ) &&
( ( V_33 -> V_60 & V_62 ) ||
( V_33 -> V_60 & V_215 ) ) ) {
error = - V_147 ;
goto V_328;
}
if ( V_33 -> V_60 & V_118 )
error = F_10 ( V_2 ) ;
if ( ( V_16 -> V_33 . type == V_330 ||
V_16 -> V_33 . type == V_331 ) &&
( V_16 -> V_33 . V_60 & V_62 ) ) {
V_16 -> V_140 -> type = V_16 -> V_33 . type ;
V_16 -> V_140 -> V_75 = V_16 -> V_75 ;
}
F_80 ( & V_2 -> V_19 , V_14 ) ;
return 0 ;
V_328:
F_138 ( V_2 ) ;
V_309:
F_133 ( V_14 ) ;
return error ;
}
static void F_139 ( struct V_312 * V_313 )
{
struct V_14 * V_14 = F_41 ( V_313 , struct V_14 , V_332 ) ;
struct V_333 * V_334 = V_14 -> V_334 ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_1 * V_335 , * V_336 ;
struct V_14 * V_337 , * V_338 ;
struct V_16 * V_339 , * V_340 ;
int error ;
F_99 ( V_14 ) ;
V_335 = F_140 ( V_334 -> V_341 -> V_342 [ 1 ] ) ;
V_337 = F_6 ( V_335 ) ;
V_339 = & ( V_337 -> V_16 ) ;
F_133 ( V_337 ) ;
V_336 = F_140 ( V_334 -> V_341 -> V_342 [ 2 ] ) ;
V_338 = F_6 ( V_336 ) ;
V_340 = & ( V_338 -> V_16 ) ;
F_133 ( V_338 ) ;
if ( V_16 -> V_151 == 0 ) {
F_108 ( V_14 -> V_2 , L_39 ) ;
} else {
const struct V_343 * V_40 = V_344 ;
F_108 ( V_14 -> V_2 , L_40 ,
V_16 -> V_151 ) ;
while ( V_40 -> V_101 ) {
if ( V_40 -> V_130 == V_345 &&
V_40 -> V_132 == V_16 -> V_151 )
break;
V_40 ++ ;
}
if ( ! V_40 -> V_101 ) {
F_108 ( V_14 -> V_2 , L_41 ) ;
return;
}
V_339 -> V_33 =
* ( (struct V_32 * ) V_40 -> V_346 ) ;
V_339 -> V_151 = V_16 -> V_151 ;
F_138 ( V_335 ) ;
error = F_134 ( V_337 , true ) ;
if ( error )
goto V_309;
if ( V_339 -> V_33 . V_38 ||
( V_339 -> V_33 . type >= V_330 &&
V_339 -> V_33 . type <= V_63 ) ) {
V_340 -> V_33 =
* ( (struct V_32 * ) V_40 -> V_346 ) ;
V_340 -> V_151 = V_16 -> V_151 ;
F_138 ( V_336 ) ;
error = F_134 ( V_338 , true ) ;
if ( error )
goto V_309;
}
F_132 ( V_16 -> V_186 , V_339 -> V_186 ,
sizeof( V_16 -> V_186 ) ) ;
error = F_98 ( V_14 ) ;
if ( error )
goto V_309;
}
return;
V_309:
F_133 ( V_337 ) ;
F_133 ( V_338 ) ;
return;
}
static void F_141 ( struct V_14 * V_14 , unsigned int V_274 )
{
struct V_278 * V_279 = V_14 -> V_279 ;
T_6 V_277 = V_279 -> V_280 [ V_274 ] . V_277 ;
int V_80 ;
unsigned long V_200 ;
F_142 ( & V_279 -> V_287 , V_200 ) ;
V_279 -> V_280 [ V_274 ] . V_347 = false ;
F_143 ( & V_279 -> V_287 , V_200 ) ;
if ( V_279 -> V_280 [ V_274 ] . V_234 . V_234 )
F_76 ( & V_14 -> V_2 -> V_19 ,
& V_279 -> V_280 [ V_274 ] . V_234 . V_257 ) ;
if ( V_279 -> V_280 [ V_274 ] . V_185 . V_186 )
F_76 ( & V_14 -> V_2 -> V_19 ,
& V_279 -> V_280 [ V_274 ] ) ;
for ( V_80 = 0 ; V_80 < V_295 ; V_80 ++ ) {
if ( V_279 -> V_280 [ V_80 ] . V_277 == V_277 ) {
V_279 -> V_280 [ V_80 ] . V_277 = 0 ;
V_279 -> V_280 [ V_80 ] . V_185 . V_186 = NULL ;
V_279 -> V_280 [ V_80 ] . V_347 = false ;
V_279 -> V_280 [ V_80 ] . V_234 . V_234 = NULL ;
V_14 -> V_148 . V_149 [ V_80 ] . V_156 = V_296 ;
}
}
}
static int F_144 ( struct V_14 * V_14 , T_6 V_277 ,
unsigned int V_274 )
{
struct V_278 * V_279 = V_14 -> V_279 ;
struct V_171 * V_19 = & V_14 -> V_2 -> V_19 ;
int error , V_348 ;
for ( V_348 = 0 ; V_348 < V_295 ; V_348 ++ ) {
if ( V_279 -> V_280 [ V_348 ] . V_277 == V_277 )
break;
}
if ( V_348 < V_295 ) {
V_279 -> V_280 [ V_274 ] . V_277 = V_277 ;
return 0 ;
}
if ( ! F_78 ( V_19 , & V_279 -> V_280 [ V_274 ] , V_39 ) )
return - V_92 ;
error = F_105 ( V_14 , V_277 , V_274 ) ;
if ( error )
goto V_309;
V_279 -> V_280 [ V_274 ] . V_349 = F_117 ( V_14 ) ;
if ( ! V_279 -> V_280 [ V_274 ] . V_349 ) {
error = - V_92 ;
goto V_309;
}
V_279 -> V_280 [ V_274 ] . V_349 -> V_299 = V_279 -> V_280 [ V_274 ] . V_185 . V_186 ;
V_279 -> V_280 [ V_274 ] . V_349 -> V_186 = V_14 -> V_16 . V_305 ;
if ( ! V_279 -> V_280 [ V_274 ] . V_349 -> V_186 ) {
error = - V_94 ;
goto V_309;
}
error = F_126 ( V_279 -> V_280 [ V_274 ] . V_349 ,
& V_14 -> V_16 ) ;
if ( error )
goto V_309;
V_279 -> V_280 [ V_274 ] . V_277 = V_277 ;
error = F_124 ( V_279 -> V_280 [ V_274 ] . V_349 ) ;
if ( error )
goto V_309;
error = F_77 (
& V_279 -> V_280 [ V_274 ] . V_349 -> V_19 ,
V_14 , V_274 , 3 , true ) ;
if ( error )
goto V_309;
V_279 -> V_280 [ V_274 ] . V_347 = true ;
F_80 ( V_19 , & V_279 -> V_280 [ V_274 ] ) ;
return 0 ;
V_309:
F_76 ( V_19 , & V_279 -> V_280 [ V_274 ] ) ;
V_279 -> V_280 [ V_274 ] . V_277 = 0 ;
return error ;
}
static int F_145 ( struct V_14 * V_14 , int V_274 )
{
struct V_278 * V_279 = V_14 -> V_279 ;
int error ;
if ( ! V_279 -> V_280 [ V_274 ] . V_347 )
return 0 ;
if ( V_279 -> V_280 [ V_274 ] . V_234 . V_234 )
return 0 ;
if ( V_14 -> V_148 . V_149 [ V_274 ] . V_156 == V_296 )
return 0 ;
error = F_90 ( V_14 ,
& V_14 -> V_279 -> V_280 [ V_274 ] . V_234 ) ;
if ( error )
return error ;
return 0 ;
}
static void F_146 ( struct V_312 * V_313 )
{
struct V_14 * V_14 = F_41 ( V_313 , struct V_14 , V_350 ) ;
struct V_278 * V_279 = V_14 -> V_279 ;
struct V_288 V_17 ;
unsigned long V_200 ;
unsigned int V_173 ;
T_6 V_277 ;
int V_80 ;
F_142 ( & V_279 -> V_287 , V_200 ) ;
V_173 = F_147 ( & V_279 -> V_286 , & V_17 , sizeof( V_17 ) ) ;
if ( V_173 != sizeof( V_17 ) ) {
F_3 ( V_14 -> V_2 ,
L_42 ) ;
F_143 ( & V_279 -> V_287 , V_200 ) ;
return;
}
if ( ! F_148 ( & V_279 -> V_286 ) )
F_149 ( & V_14 -> V_16 , V_351 ) ;
F_143 ( & V_279 -> V_287 , V_200 ) ;
for ( V_80 = 0 ; V_80 < V_295 ; V_80 ++ ) {
V_277 = V_17 . V_279 [ V_80 ] . V_277 ;
if ( V_17 . V_279 [ V_80 ] . V_352 ) {
if ( V_279 -> V_280 [ V_80 ] . V_277 == V_277 ) {
F_145 ( V_14 , V_80 ) ;
continue;
}
if ( V_279 -> V_280 [ V_80 ] . V_277 )
F_141 ( V_14 , V_80 ) ;
F_144 ( V_14 , V_277 , V_80 ) ;
} else if ( V_279 -> V_280 [ V_80 ] . V_277 ) {
F_141 ( V_14 , V_80 ) ;
}
}
}
static int F_150 ( struct V_1 * V_2 ,
const struct V_343 * V_40 )
{
struct V_107 * V_108 = F_151 ( V_2 -> V_19 . V_275 ) ;
struct V_333 * V_19 = F_152 ( V_108 ) ;
struct V_14 * V_14 ;
struct V_16 * V_16 ;
struct V_32 * V_33 ;
int error ;
if ( ! V_40 -> V_346 )
return - V_94 ;
V_2 -> V_266 |= V_353 ;
V_2 -> V_266 &= ~ V_354 ;
V_14 = F_79 ( & V_2 -> V_19 , sizeof( struct V_14 ) , V_39 ) ;
if ( ! V_14 )
return - V_92 ;
F_153 ( V_2 , V_14 ) ;
V_14 -> V_2 = V_2 ;
V_16 = & V_14 -> V_16 ;
V_16 -> V_33 = * ( (struct V_32 * ) V_40 -> V_346 ) ;
V_33 = & V_16 -> V_33 ;
if ( V_33 -> V_355 && V_33 -> V_356 != V_2 -> type ) {
error = - V_147 ;
goto V_309;
}
V_16 -> V_34 . V_46 = - 1 ;
V_16 -> V_52 = - 1 ;
V_14 -> V_334 = V_19 ;
V_14 -> V_108 = V_108 ;
F_154 ( & V_14 -> V_175 ) ;
F_155 ( & V_14 -> V_332 , F_139 ) ;
F_155 ( & V_14 -> V_314 , F_129 ) ;
F_155 ( & V_14 -> V_350 , F_146 ) ;
error = F_156 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_43 ) ;
goto V_309;
}
error = F_134 ( V_14 , false ) ;
if ( error )
goto V_309;
if ( V_2 -> V_101 == V_102 ) {
error = F_157 ( & V_2 -> V_19 , & V_357 ) ;
if ( error )
F_17 ( V_2 ,
L_44 ,
error ) ;
}
return 0 ;
V_309:
F_153 ( V_2 , NULL ) ;
return error ;
}
static void F_158 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_32 * V_33 = & V_16 -> V_33 ;
if ( V_33 -> V_60 & V_118 )
F_12 ( V_2 ) ;
F_138 ( V_2 ) ;
F_159 ( & V_14 -> V_332 ) ;
F_159 ( & V_14 -> V_314 ) ;
F_159 ( & V_14 -> V_350 ) ;
if ( V_2 -> V_101 == V_102 )
F_160 ( & V_2 -> V_19 , & V_357 ) ;
F_153 ( V_2 , NULL ) ;
}
static int F_161 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_32 * V_33 = & V_14 -> V_16 . V_33 ;
F_42 ( & V_14 -> V_175 ) ;
F_34 ( V_2 , V_33 ) ;
F_51 ( V_14 ) ;
F_44 ( & V_14 -> V_175 ) ;
return 0 ;
}
static int F_162 ( struct V_1 * V_2 )
{
return F_161 ( V_2 ) ;
}
