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
int V_36 ;
switch ( V_31 -> V_37 ) {
case V_38 :
if ( ! V_33 -> V_39 ) {
V_17 = F_16 ( 2 , V_40 ) ;
if ( ! V_17 )
break;
V_17 [ 0 ] = V_25 -> V_12 -> V_41 ;
V_35 = F_1 ( V_2 , V_42 ,
V_17 , 2 , V_43 ) ;
if ( V_35 == 2 ) {
V_33 -> V_39 = V_17 [ 1 ] ;
} else {
V_33 -> V_39 = 16 ;
F_17 ( V_2 , L_4
L_5
L_6 ,
V_33 -> V_39 ) ;
}
F_18 ( V_17 ) ;
}
break;
case V_44 :
if ( V_31 -> V_45 >= V_25 -> V_46 ) {
F_19 ( & V_2 -> V_19 , L_7 ) ;
break;
}
V_34 -> V_47 = V_25 -> V_12 -> V_41 ;
V_34 -> V_48 = V_31 -> V_45 ;
break;
case V_49 :
if ( V_25 -> V_12 -> V_41 == 0x0B &&
( V_25 -> V_50 == V_51 ||
V_25 -> V_50 == V_52 ) ) {
V_14 -> V_16 . V_53 = V_25 -> V_12 -> V_41 ;
V_14 -> V_16 . V_54 = 0 ;
}
break;
case V_55 :
V_14 -> V_16 . V_53 = V_25 -> V_12 -> V_41 ;
V_14 -> V_16 . V_54 = 2 ;
break;
case V_56 :
case V_57 :
if ( V_25 -> V_12 -> V_41 == 0x03 &&
( V_25 -> V_50 == V_58 ||
V_25 -> V_50 == V_59 ) ) {
V_14 -> V_16 . V_53 = V_25 -> V_12 -> V_41 ;
V_14 -> V_16 . V_54 = 0 ;
}
break;
case V_60 :
case V_61 :
case V_62 :
case V_63 :
V_36 = F_20 ( V_25 -> V_12 ) ;
V_17 = F_21 ( V_25 -> V_12 , V_40 ) ;
if ( ! V_17 )
break;
V_17 [ 0 ] = V_25 -> V_12 -> V_41 ;
V_35 = F_1 ( V_2 , V_42 ,
V_17 , V_36 , V_43 ) ;
if ( V_35 == V_36 ) {
V_35 = F_22 ( V_2 , V_42 ,
V_17 , V_36 , 0 ) ;
} else {
F_17 ( V_2 , L_8 ,
V_64 ) ;
}
F_18 ( V_17 ) ;
break;
}
}
static void F_23 ( struct V_1 * V_2 ,
struct V_24 * V_25 , struct V_30 * V_31 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_32 * V_33 = & V_14 -> V_16 . V_33 ;
bool V_65 = F_24 ( V_25 ) ;
bool V_66 = F_25 ( V_25 ) ;
if ( V_66 )
V_33 -> V_67 |= V_68 ;
else if ( V_65 )
V_33 -> V_67 |= V_69 ;
else
return;
if ( V_33 -> type > V_70 ) {
if ( V_65 && ! V_33 -> V_39 )
V_33 -> V_39 = 1 ;
}
if ( V_33 -> type == V_71 &&
V_31 -> V_37 == 0x000D0000 &&
V_25 -> V_50 == V_72 &&
V_25 -> V_73 == V_74 ) {
int V_75 = V_31 -> V_45 ;
if ( V_75 - 4 >= 0 && V_75 + 1 < V_25 -> V_76 &&
V_25 -> V_31 [ V_75 - 4 ] . V_37 == V_77 &&
V_25 -> V_31 [ V_75 - 3 ] . V_37 == V_78 &&
V_25 -> V_31 [ V_75 - 2 ] . V_37 == V_79 &&
V_25 -> V_31 [ V_75 - 1 ] . V_37 == V_80 &&
V_25 -> V_31 [ V_75 + 1 ] . V_37 == V_81 ) {
V_31 -> V_37 = V_82 ;
}
}
switch ( V_31 -> V_37 ) {
case V_83 :
V_33 -> V_84 = V_25 -> V_26 ;
if ( V_65 ) {
V_33 -> V_85 = V_25 -> V_27 ;
if ( ( V_33 -> type != V_70 ) &&
( V_33 -> type != V_86 ) ) {
V_33 -> V_22 = V_25 -> V_22 ;
V_33 -> V_87 = V_25 -> V_28 ;
}
}
break;
case V_88 :
V_33 -> V_89 = V_25 -> V_26 ;
if ( V_65 ) {
V_33 -> V_90 = V_25 -> V_27 ;
if ( ( V_33 -> type != V_70 ) &&
( V_33 -> type != V_86 ) ) {
V_33 -> V_22 = V_25 -> V_22 ;
V_33 -> V_87 = V_25 -> V_28 ;
}
}
break;
case V_91 :
if ( V_66 )
V_33 -> V_92 = V_25 -> V_26 ;
break;
}
if ( V_33 -> type == V_71 )
F_26 ( V_2 , V_25 , V_31 ) ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_16 * V_16 = & V_14 -> V_16 ;
if ( V_33 -> type == V_71 ) {
if ( V_33 -> V_39 > 1 ) {
F_28 ( V_16 -> V_93 , V_16 -> V_33 . V_39 ,
V_94 ) ;
}
}
}
static void F_29 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_95 * V_96 ;
struct V_11 * V_97 ;
int V_75 , V_98 ;
V_96 = & V_2 -> V_99 [ V_42 ] ;
F_30 (hreport, &rep_enum->report_list, list) {
for ( V_75 = 0 ; V_75 < V_97 -> V_100 ; V_75 ++ ) {
if ( V_97 -> V_25 [ V_75 ] -> V_46 < 1 )
continue;
for ( V_98 = 0 ; V_98 < V_97 -> V_25 [ V_75 ] -> V_76 ; V_98 ++ ) {
F_15 ( V_2 , V_97 -> V_25 [ V_75 ] ,
V_97 -> V_25 [ V_75 ] -> V_31 + V_98 ) ;
}
}
}
V_96 = & V_2 -> V_99 [ V_101 ] ;
F_30 (hreport, &rep_enum->report_list, list) {
if ( ! V_97 -> V_100 )
continue;
for ( V_75 = 0 ; V_75 < V_97 -> V_100 ; V_75 ++ )
for ( V_98 = 0 ; V_98 < V_97 -> V_25 [ V_75 ] -> V_76 ; V_98 ++ )
F_23 ( V_2 , V_97 -> V_25 [ V_75 ] ,
V_97 -> V_25 [ V_75 ] -> V_31 + V_98 ) ;
}
F_27 ( V_2 , V_33 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_34 * V_34 = & V_14 -> V_16 . V_34 ;
struct V_11 * V_102 ;
struct V_95 * V_103 ;
if ( V_34 -> V_47 < 0 )
return 0 ;
V_103 = & ( V_2 -> V_99 [ V_42 ] ) ;
V_102 = V_103 -> V_104 [ V_34 -> V_47 ] ;
if ( V_102 ) {
V_102 -> V_25 [ 0 ] -> V_105 [ V_34 -> V_48 ] = 2 ;
F_32 ( V_2 , V_102 , V_10 ) ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_16 * V_16 )
{
T_1 * V_106 ;
struct V_11 * V_102 ;
struct V_95 * V_103 ;
int V_107 ;
int error = - V_108 , V_109 = 0 ;
if ( V_16 -> V_53 < 0 )
return 0 ;
V_103 = & ( V_2 -> V_99 [ V_42 ] ) ;
V_102 = V_103 -> V_104 [ V_16 -> V_53 ] ;
if ( ! V_102 )
return - V_110 ;
V_106 = F_21 ( V_102 , V_40 ) ;
if ( ! V_106 )
return - V_108 ;
V_107 = F_20 ( V_102 ) ;
do {
V_106 [ 0 ] = V_16 -> V_53 ;
V_106 [ 1 ] = V_16 -> V_54 ;
error = F_4 ( V_2 , V_42 , V_106 ,
V_107 , 1 ) ;
if ( error >= 0 )
error = F_1 ( V_2 , V_42 ,
V_106 , V_107 , 1 ) ;
} while ( error >= 0 &&
V_106 [ 1 ] != V_16 -> V_53 &&
V_109 ++ < V_111 );
F_18 ( V_106 ) ;
return error < 0 ? error : 0 ;
}
static int F_34 ( struct V_1 * V_2 , T_1 V_112 ,
struct V_32 * V_33 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
int V_35 ;
T_1 V_106 [ 2 ] ;
switch ( V_33 -> type ) {
case V_113 :
V_106 [ 0 ] = 0x03 ;
V_106 [ 1 ] = 0x00 ;
V_35 = F_4 ( V_2 , V_42 , V_106 , 2 ,
3 ) ;
if ( V_35 >= 0 ) {
V_106 [ 0 ] = V_112 == 0 ? 0x05 : 0x06 ;
V_106 [ 1 ] = 0x00 ;
V_35 = F_4 ( V_2 , V_42 ,
V_106 , 2 , 3 ) ;
if ( V_35 >= 0 ) {
V_14 -> V_16 . V_114 = V_112 ;
return 0 ;
}
}
F_17 ( V_2 , L_9 ,
V_106 [ 0 ] , V_35 ) ;
break;
case V_115 :
if ( V_112 == 1 )
V_14 -> V_16 . V_116 &= ~ 0x20 ;
else
V_14 -> V_16 . V_116 |= 0x20 ;
V_106 [ 0 ] = 0x03 ;
V_106 [ 1 ] = V_14 -> V_16 . V_116 ;
V_35 = F_4 ( V_2 , V_42 , V_106 , 2 ,
1 ) ;
if ( V_35 >= 0 )
V_14 -> V_16 . V_114 = V_112 ;
break;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_16 * V_16 = & V_14 -> V_16 ;
if ( V_2 -> V_117 == V_118 )
return F_34 ( V_2 , 1 , V_33 ) ;
if ( V_33 -> type != V_71 ) {
if ( V_33 -> V_67 & V_69 ) {
if ( V_33 -> type > V_119 ) {
V_16 -> V_53 = 3 ;
V_16 -> V_54 = 4 ;
} else if ( V_33 -> type == V_120 ) {
V_16 -> V_53 = 18 ;
V_16 -> V_54 = 2 ;
} else if ( V_33 -> type == V_121 ) {
V_16 -> V_53 = 131 ;
V_16 -> V_54 = 2 ;
} else if ( V_33 -> type == V_122 ) {
V_16 -> V_53 = 2 ;
V_16 -> V_54 = 2 ;
}
} else if ( V_33 -> V_67 & V_68 ) {
if ( V_33 -> type <= V_70 ) {
V_16 -> V_53 = 2 ;
V_16 -> V_54 = 2 ;
}
}
}
F_33 ( V_2 , V_16 ) ;
if ( V_33 -> type == V_71 )
return F_31 ( V_2 ) ;
return 0 ;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_123 * V_124 = V_14 -> V_124 ;
V_33 -> V_125 = 4 ;
V_33 -> V_126 = 4 ;
V_33 -> V_127 = 0 ;
V_33 -> V_128 = 1 ;
V_33 -> V_129 = 1 ;
if ( V_33 -> type == V_130 ) {
if ( V_124 -> V_131 -> V_132 . V_133 == 0 )
V_33 -> V_67 = V_134 ;
else
V_33 -> V_67 = V_135 ;
return;
}
F_29 ( V_2 , V_33 ) ;
}
static bool F_37 ( struct V_1 * V_136 ,
struct V_1 * V_137 , char V_138 )
{
int V_139 = strrchr ( V_136 -> V_140 , V_138 ) - V_136 -> V_140 ;
int V_141 = strrchr ( V_137 -> V_140 , V_138 ) - V_137 -> V_140 ;
if ( V_139 != V_141 || V_139 <= 0 || V_141 <= 0 )
return false ;
return ! strncmp ( V_136 -> V_140 , V_137 -> V_140 , V_139 ) ;
}
static bool F_38 ( struct V_1 * V_2 ,
struct V_1 * V_142 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_32 * V_33 = & V_14 -> V_16 . V_33 ;
struct V_14 * V_143 = F_6 ( V_142 ) ;
struct V_32 * V_144 = & V_143 -> V_16 . V_33 ;
T_3 V_145 = V_33 -> V_145 ? V_33 -> V_145 : V_2 -> V_146 ;
T_3 V_147 = V_33 -> V_147 ? V_33 -> V_147 : V_2 -> V_148 ;
if ( V_33 -> V_145 != V_149 && V_142 -> V_146 != V_145 )
return false ;
if ( V_33 -> V_147 != V_149 && V_142 -> V_148 != V_147 )
return false ;
if ( V_2 -> V_146 == V_142 -> V_146 && V_2 -> V_148 == V_142 -> V_148 ) {
if ( ! F_37 ( V_2 , V_142 , '/' ) )
return false ;
} else {
if ( ! F_37 ( V_2 , V_142 , '.' ) )
return false ;
}
if ( V_33 -> type != V_71 )
return true ;
if ( ( V_33 -> V_67 & V_150 ) &&
! ( V_144 -> V_67 & V_150 ) )
return false ;
if ( ! ( V_33 -> V_67 & V_150 ) &&
( V_144 -> V_67 & V_150 ) )
return false ;
if ( ( V_33 -> V_67 & V_68 ) &&
! ( V_144 -> V_67 & V_69 ) )
return false ;
if ( ( V_33 -> V_67 & V_69 ) &&
! ( V_144 -> V_67 & V_68 ) )
return false ;
return true ;
}
static struct V_151 * F_39 ( struct V_1 * V_2 )
{
struct V_151 * V_17 ;
F_30 (data, &wacom_udev_list, list) {
if ( F_37 ( V_2 , V_17 -> V_19 , '/' ) )
return V_17 ;
}
F_30 (data, &wacom_udev_list, list) {
if ( F_38 ( V_2 , V_17 -> V_19 ) ) {
F_40 ( & V_17 -> V_152 ) ;
return V_17 ;
}
}
return NULL ;
}
static void F_41 ( struct V_152 * V_152 )
{
struct V_151 * V_17 =
F_42 ( V_152 , struct V_151 , V_152 ) ;
F_43 ( & V_153 ) ;
F_44 ( & V_17 -> V_154 ) ;
F_45 ( & V_153 ) ;
F_18 ( V_17 ) ;
}
static void F_46 ( void * V_155 )
{
struct V_14 * V_14 = V_155 ;
struct V_151 * V_17 ;
struct V_16 * V_16 = & V_14 -> V_16 ;
if ( V_16 -> V_156 ) {
V_17 = F_42 ( V_16 -> V_156 , struct V_151 ,
V_156 ) ;
if ( V_16 -> V_156 -> V_157 == V_14 -> V_2 )
V_16 -> V_156 -> V_157 = NULL ;
else if ( V_16 -> V_156 -> V_66 == V_14 -> V_2 )
V_16 -> V_156 -> V_66 = NULL ;
F_47 ( & V_17 -> V_152 , F_41 ) ;
V_16 -> V_156 = NULL ;
}
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_151 * V_17 ;
int V_6 = 0 ;
F_43 ( & V_153 ) ;
V_17 = F_39 ( V_2 ) ;
if ( ! V_17 ) {
V_17 = F_16 ( sizeof( struct V_151 ) , V_40 ) ;
if ( ! V_17 ) {
V_6 = - V_108 ;
goto V_158;
}
F_49 ( & V_17 -> V_152 ) ;
V_17 -> V_19 = V_2 ;
F_50 ( & V_17 -> V_154 , & V_159 ) ;
}
V_16 -> V_156 = & V_17 -> V_156 ;
V_6 = F_51 ( & V_2 -> V_19 , F_46 , V_14 ) ;
if ( V_6 ) {
F_45 ( & V_153 ) ;
F_46 ( V_14 ) ;
return V_6 ;
}
if ( V_16 -> V_33 . V_67 & V_69 )
V_16 -> V_156 -> V_157 = V_2 ;
else if ( V_16 -> V_33 . V_67 & V_68 )
V_16 -> V_156 -> V_66 = V_2 ;
V_158:
F_45 ( & V_153 ) ;
return V_6 ;
}
static int F_52 ( struct V_14 * V_14 )
{
unsigned char * V_3 ;
int V_6 ;
unsigned char V_160 = V_161 ;
int V_162 = 9 ;
if ( ! F_6 ( V_14 -> V_2 ) )
return - V_163 ;
if ( ! V_14 -> V_164 . V_165 )
return - V_166 ;
if ( V_14 -> V_16 . V_167 ) {
V_160 = V_168 ;
V_162 = 13 ;
}
V_3 = F_16 ( V_162 , V_40 ) ;
if ( ! V_3 )
return - V_108 ;
if ( V_14 -> V_16 . V_33 . type >= V_169 &&
V_14 -> V_16 . V_33 . type <= V_170 ) {
int V_171 = V_14 -> V_164 . V_165 [ 0 ] . V_172 & 0x03 ;
int V_173 = ( ( ( V_14 -> V_164 . V_174 & 0x60 ) >> 5 ) - 1 ) & 0x03 ;
int V_175 = 0 ;
unsigned char V_176 = ( V_175 << 4 ) | ( V_173 << 2 ) | ( V_171 ) ;
V_3 [ 0 ] = V_160 ;
if ( V_14 -> V_16 . V_167 ) {
F_1 ( V_14 -> V_2 , V_42 ,
V_3 , V_162 , V_43 ) ;
V_3 [ 0 ] = V_160 ;
V_3 [ 4 ] = V_176 ;
} else
V_3 [ 1 ] = V_176 ;
}
else {
int V_164 = V_14 -> V_164 . V_165 [ 0 ] . V_172 | 0x4 ;
if ( V_14 -> V_16 . V_33 . type == V_177 ||
V_14 -> V_16 . V_33 . type == V_178 )
V_164 |= ( V_14 -> V_164 . V_165 [ 1 ] . V_172 << 4 ) | 0x40 ;
V_3 [ 0 ] = V_160 ;
V_3 [ 1 ] = V_164 ;
V_3 [ 2 ] = V_14 -> V_164 . V_174 ;
V_3 [ 3 ] = V_14 -> V_164 . V_179 ;
V_3 [ 4 ] = V_14 -> V_164 . V_180 ;
}
V_6 = F_4 ( V_14 -> V_2 , V_42 , V_3 , V_162 ,
V_43 ) ;
F_18 ( V_3 ) ;
return V_6 ;
}
static int F_53 ( struct V_14 * V_14 , int V_181 , T_1 V_182 ,
const unsigned V_183 , const void * V_184 )
{
unsigned char * V_3 ;
int V_75 , V_6 ;
const unsigned V_185 = V_183 / 4 ;
V_3 = F_16 ( V_185 + 3 , V_40 ) ;
if ( ! V_3 )
return - V_108 ;
V_3 [ 0 ] = V_186 ;
V_3 [ 1 ] = 1 ;
V_6 = F_4 ( V_14 -> V_2 , V_42 , V_3 , 2 ,
V_43 ) ;
if ( V_6 < 0 )
goto V_158;
V_3 [ 0 ] = V_182 ;
V_3 [ 1 ] = V_181 & 0x07 ;
for ( V_75 = 0 ; V_75 < 4 ; V_75 ++ ) {
V_3 [ 2 ] = V_75 ;
memcpy ( V_3 + 3 , V_184 + V_75 * V_185 , V_185 ) ;
V_6 = F_4 ( V_14 -> V_2 , V_42 ,
V_3 , V_185 + 3 , V_43 ) ;
if ( V_6 < 0 )
break;
}
V_3 [ 0 ] = V_186 ;
V_3 [ 1 ] = 0 ;
F_4 ( V_14 -> V_2 , V_42 , V_3 , 2 ,
V_43 ) ;
V_158:
F_18 ( V_3 ) ;
return V_6 ;
}
static T_4 F_54 ( struct V_187 * V_19 , int V_188 ,
const char * V_3 , T_2 V_189 )
{
struct V_1 * V_2 = F_55 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
unsigned int V_41 ;
int V_190 ;
V_190 = F_56 ( V_3 , 10 , & V_41 ) ;
if ( V_190 )
return V_190 ;
F_43 ( & V_14 -> V_191 ) ;
V_14 -> V_164 . V_165 [ V_188 ] . V_172 = V_41 & 0x3 ;
V_190 = F_52 ( V_14 ) ;
F_45 ( & V_14 -> V_191 ) ;
return V_190 < 0 ? V_190 : V_189 ;
}
static T_4 F_57 ( struct V_14 * V_14 , T_1 * V_192 ,
const char * V_3 , T_2 V_189 )
{
unsigned int V_105 ;
int V_190 ;
V_190 = F_56 ( V_3 , 10 , & V_105 ) ;
if ( V_190 )
return V_190 ;
F_43 ( & V_14 -> V_191 ) ;
* V_192 = V_105 & 0x7f ;
V_190 = F_52 ( V_14 ) ;
F_45 ( & V_14 -> V_191 ) ;
return V_190 < 0 ? V_190 : V_189 ;
}
static T_4 F_58 ( struct V_187 * V_19 , int V_181 ,
const char * V_3 , T_2 V_189 )
{
struct V_1 * V_2 = F_55 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
int V_190 ;
unsigned V_183 ;
T_1 V_182 ;
if ( V_2 -> V_117 == V_118 ) {
V_183 = 256 ;
V_182 = V_193 ;
} else {
V_183 = 1024 ;
V_182 = V_194 ;
}
if ( V_189 != V_183 )
return - V_110 ;
F_43 ( & V_14 -> V_191 ) ;
V_190 = F_53 ( V_14 , V_181 , V_182 , V_183 , V_3 ) ;
F_45 ( & V_14 -> V_191 ) ;
return V_190 < 0 ? V_190 : V_189 ;
}
static void F_59 ( struct V_187 * V_19 , void * V_155 )
{
struct V_195 * V_196 = V_155 ;
struct V_197 * V_198 = V_196 -> V_199 ;
F_60 ( V_19 , L_10 ,
V_64 , V_196 -> V_200 -> V_201 ) ;
F_61 ( V_198 , V_196 -> V_200 ) ;
}
static int F_62 ( struct V_14 * V_14 ,
struct V_197 * V_199 ,
struct V_202 * V_200 )
{
struct V_195 * V_196 ;
int error ;
V_196 = F_63 ( F_59 ,
sizeof( struct V_195 ) ,
V_40 ) ;
if ( ! V_196 )
return - V_108 ;
V_196 -> V_200 = V_200 ;
V_196 -> V_199 = V_199 ;
error = F_64 ( V_196 -> V_199 , V_200 ) ;
if ( error )
return error ;
F_65 ( & V_14 -> V_2 -> V_19 , V_196 ) ;
return 0 ;
}
static int F_66 ( struct V_14 * V_14 ,
struct V_202 * V_200 )
{
return F_62 ( V_14 , & V_14 -> V_2 -> V_19 . V_198 ,
V_200 ) ;
}
enum V_203 F_67 ( struct V_204 * V_164 )
{
struct V_14 * V_14 = V_164 -> V_14 ;
if ( V_14 -> V_164 . V_205 )
return V_164 -> V_179 * V_206 / V_14 -> V_164 . V_205 ;
if ( V_14 -> V_164 . V_207 )
return V_164 -> V_174 * V_206 / V_14 -> V_164 . V_207 ;
return V_206 ;
}
static enum V_203 F_68 ( struct V_208 * V_209 )
{
struct V_204 * V_164 = F_42 ( V_209 , struct V_204 , V_209 ) ;
struct V_14 * V_14 = V_164 -> V_14 ;
if ( V_14 -> V_164 . V_165 [ V_164 -> V_200 ] . V_172 != V_164 -> V_41 )
return V_210 ;
return F_67 ( V_164 ) ;
}
static int F_69 ( struct V_208 * V_209 ,
enum V_203 V_211 )
{
struct V_204 * V_164 = F_42 ( V_209 , struct V_204 , V_209 ) ;
struct V_14 * V_14 = V_164 -> V_14 ;
int error ;
F_43 ( & V_14 -> V_191 ) ;
if ( ! V_14 -> V_164 . V_165 || ( V_211 == V_210 &&
V_14 -> V_164 . V_165 [ V_164 -> V_200 ] . V_172 != V_164 -> V_41 ) ) {
error = 0 ;
goto V_158;
}
V_164 -> V_174 = V_14 -> V_164 . V_174 = V_14 -> V_164 . V_207 * V_211 / V_206 ;
V_164 -> V_179 = V_14 -> V_164 . V_179 = V_14 -> V_164 . V_205 * V_211 / V_206 ;
V_14 -> V_164 . V_165 [ V_164 -> V_200 ] . V_172 = V_164 -> V_41 ;
error = F_52 ( V_14 ) ;
V_158:
F_45 ( & V_14 -> V_191 ) ;
return error ;
}
static void F_70 ( struct V_208 * V_209 ,
enum V_203 V_211 )
{
}
static int F_71 ( struct V_187 * V_19 , struct V_14 * V_14 ,
struct V_204 * V_164 , unsigned int V_200 ,
unsigned int V_41 , bool V_212 )
{
int error ;
char * V_201 ;
V_201 = F_72 ( V_19 , V_40 ,
L_11 ,
F_73 ( V_19 ) ,
V_200 ,
V_41 ) ;
if ( ! V_201 )
return - V_108 ;
if ( ! V_212 ) {
V_164 -> V_213 . V_201 = V_201 ;
error = F_74 ( V_19 , & V_164 -> V_213 ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_12 ,
V_164 -> V_209 . V_201 , error ) ;
return error ;
}
}
V_164 -> V_200 = V_200 ;
V_164 -> V_41 = V_41 ;
V_164 -> V_14 = V_14 ;
V_164 -> V_174 = V_14 -> V_164 . V_174 ;
V_164 -> V_179 = V_14 -> V_164 . V_179 ;
V_164 -> V_209 . V_201 = V_201 ;
V_164 -> V_209 . V_214 = V_206 ;
V_164 -> V_209 . V_215 = V_216 ;
V_164 -> V_209 . V_217 = F_68 ;
if ( ! V_212 ) {
V_164 -> V_209 . V_218 = F_69 ;
V_164 -> V_209 . V_219 = V_164 -> V_209 . V_201 ;
} else {
V_164 -> V_209 . V_220 = F_70 ;
}
error = F_75 ( V_19 , & V_164 -> V_209 ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_13 ,
V_164 -> V_209 . V_201 , error ) ;
V_164 -> V_209 . V_201 = NULL ;
return error ;
}
return 0 ;
}
static void F_76 ( void * V_17 )
{
struct V_221 * V_200 = V_17 ;
F_77 ( V_200 -> V_19 , V_200 ) ;
}
static int F_78 ( struct V_187 * V_19 ,
struct V_14 * V_14 ,
int V_222 , int V_189 ,
bool V_212 )
{
struct V_204 * V_223 ;
int V_75 , error ;
if ( V_222 >= V_14 -> V_164 . V_189 || V_189 <= 0 )
return - V_110 ;
if ( ! F_79 ( V_19 , & V_14 -> V_164 . V_165 [ V_222 ] , V_40 ) )
return - V_108 ;
V_223 = F_80 ( V_19 , sizeof( struct V_204 ) * V_189 , V_40 ) ;
if ( ! V_223 ) {
error = - V_108 ;
goto V_190;
}
V_14 -> V_164 . V_165 [ V_222 ] . V_223 = V_223 ;
V_14 -> V_164 . V_165 [ V_222 ] . V_189 = V_189 ;
for ( V_75 = 0 ; V_75 < V_189 ; V_75 ++ ) {
error = F_71 ( V_19 , V_14 , & V_223 [ V_75 ] ,
V_222 , V_75 , V_212 ) ;
if ( error )
goto V_190;
}
V_14 -> V_164 . V_165 [ V_222 ] . V_19 = V_19 ;
F_81 ( V_19 , & V_14 -> V_164 . V_165 [ V_222 ] ) ;
error = F_82 ( & V_14 -> V_2 -> V_19 ,
F_76 ,
& V_14 -> V_164 . V_165 [ V_222 ] ) ;
if ( error )
return error ;
return 0 ;
V_190:
F_77 ( V_19 , & V_14 -> V_164 . V_165 [ V_222 ] ) ;
return error ;
}
struct V_204 * F_83 ( struct V_14 * V_14 , unsigned int V_222 ,
unsigned int V_41 )
{
struct V_221 * V_200 ;
if ( V_222 >= V_14 -> V_164 . V_189 )
return NULL ;
V_200 = & V_14 -> V_164 . V_165 [ V_222 ] ;
if ( ! V_200 -> V_223 )
return NULL ;
V_41 %= V_200 -> V_189 ;
return & V_200 -> V_223 [ V_41 ] ;
}
struct V_204 * F_84 ( struct V_14 * V_14 , struct V_204 * V_224 )
{
struct V_204 * V_225 ;
int V_200 , V_226 ;
if ( ! V_14 || ! V_224 )
return NULL ;
V_200 = V_224 -> V_200 ;
V_226 = V_224 -> V_41 ;
do {
V_225 = F_83 ( V_14 , V_200 , ++ V_226 ) ;
if ( ! V_225 || V_225 == V_224 )
return V_225 ;
} while ( V_225 -> V_209 . V_213 != & V_225 -> V_213 );
return V_225 ;
}
static void F_85 ( void * V_17 )
{
struct V_14 * V_14 = V_17 ;
V_14 -> V_164 . V_165 = NULL ;
V_14 -> V_164 . V_189 = 0 ;
}
static int F_86 ( struct V_14 * V_14 , int V_189 )
{
struct V_187 * V_19 = & V_14 -> V_2 -> V_19 ;
struct V_221 * V_165 ;
int error ;
V_165 = F_80 ( V_19 , sizeof( struct V_221 ) * V_189 ,
V_40 ) ;
if ( ! V_165 )
return - V_108 ;
error = F_82 ( V_19 , F_85 , V_14 ) ;
if ( error )
return error ;
V_14 -> V_164 . V_165 = V_165 ;
V_14 -> V_164 . V_189 = V_189 ;
return 0 ;
}
static int F_87 ( struct V_14 * V_14 , int V_227 ,
int V_228 , bool V_212 )
{
struct V_187 * V_19 ;
int V_75 , error ;
if ( ! V_14 -> V_16 . V_229 )
return - V_110 ;
V_19 = & V_14 -> V_16 . V_229 -> V_19 ;
error = F_86 ( V_14 , V_227 ) ;
if ( error )
return error ;
for ( V_75 = 0 ; V_75 < V_227 ; V_75 ++ ) {
error = F_78 ( V_19 , V_14 , V_75 ,
V_228 ,
V_212 ) ;
if ( error )
return error ;
}
return 0 ;
}
static int F_88 ( struct V_14 * V_14 )
{
int error ;
if ( ! ( V_14 -> V_16 . V_33 . V_67 & V_230 ) )
return 0 ;
switch ( V_14 -> V_16 . V_33 . type ) {
case V_231 :
case V_232 :
case V_115 :
case V_233 :
V_14 -> V_164 . V_174 = 10 ;
V_14 -> V_164 . V_179 = 20 ;
V_14 -> V_164 . V_207 = 127 ;
V_14 -> V_164 . V_205 = 127 ;
V_14 -> V_164 . V_180 = 10 ;
error = F_87 ( V_14 , 1 , 4 , false ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_14 , error ) ;
return error ;
}
error = F_66 ( V_14 ,
& V_234 ) ;
break;
case V_178 :
case V_177 :
V_14 -> V_164 . V_174 = 0 ;
V_14 -> V_164 . V_179 = 0 ;
V_14 -> V_164 . V_180 = 0 ;
error = F_87 ( V_14 , 2 , 4 , false ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_14 , error ) ;
return error ;
}
error = F_66 ( V_14 ,
& V_235 ) ;
break;
case V_169 :
case V_236 :
case V_237 :
case V_238 :
case V_239 :
case V_170 :
V_14 -> V_164 . V_174 = 32 ;
V_14 -> V_164 . V_207 = 96 ;
error = F_87 ( V_14 , 1 , 4 , false ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_14 , error ) ;
return error ;
}
error = F_66 ( V_14 ,
& V_240 ) ;
break;
case V_241 :
V_14 -> V_164 . V_174 = 255 ;
V_14 -> V_164 . V_207 = 255 ;
error = F_86 ( V_14 , 5 ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_14 , error ) ;
return error ;
}
return 0 ;
default:
return 0 ;
}
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_15 , error ) ;
return error ;
}
F_52 ( V_14 ) ;
return 0 ;
}
static int F_89 ( struct V_242 * V_243 ,
enum V_244 V_245 ,
union V_246 * V_247 )
{
struct V_248 * V_249 = F_90 ( V_243 ) ;
int V_35 = 0 ;
switch ( V_245 ) {
case V_250 :
V_247 -> V_251 = V_249 -> V_14 -> V_16 . V_201 ;
break;
case V_252 :
V_247 -> V_253 = V_249 -> V_254 ;
break;
case V_255 :
V_247 -> V_253 = V_256 ;
break;
case V_257 :
V_247 -> V_253 = V_249 -> V_258 ;
break;
case V_259 :
if ( V_249 -> V_260 )
V_247 -> V_253 = V_261 ;
else if ( V_249 -> V_258 == 100 &&
V_249 -> V_262 )
V_247 -> V_253 = V_263 ;
else if ( V_249 -> V_262 )
V_247 -> V_253 = V_264 ;
else
V_247 -> V_253 = V_265 ;
break;
default:
V_35 = - V_110 ;
break;
}
return V_35 ;
}
static int F_91 ( struct V_14 * V_14 ,
struct V_248 * V_249 )
{
static T_5 V_266 = F_92 ( 0 ) ;
struct V_187 * V_19 = & V_14 -> V_2 -> V_19 ;
struct V_267 V_268 = { . V_269 = V_249 , } ;
struct V_242 * V_270 ;
struct V_271 * V_272 = & V_249 -> V_272 ;
unsigned long V_36 ;
int error ;
if ( ! F_79 ( V_19 , V_272 , V_40 ) )
return - V_108 ;
V_249 -> V_14 = V_14 ;
V_36 = F_93 ( & V_266 ) - 1 ;
V_272 -> V_273 = V_274 ;
V_272 -> V_275 = F_94 ( V_274 ) ;
V_272 -> V_276 = F_89 ;
sprintf ( V_249 -> V_277 , L_16 , V_36 ) ;
V_272 -> V_201 = V_249 -> V_277 ;
V_272 -> type = V_278 ;
V_272 -> V_279 = 0 ;
V_270 = F_95 ( V_19 , V_272 , & V_268 ) ;
if ( F_96 ( V_270 ) ) {
error = F_97 ( V_270 ) ;
goto V_190;
}
F_98 ( V_270 , & V_14 -> V_2 -> V_19 ) ;
V_249 -> V_249 = V_270 ;
F_81 ( V_19 , V_272 ) ;
return 0 ;
V_190:
F_77 ( V_19 , V_272 ) ;
return error ;
}
static int F_99 ( struct V_14 * V_14 )
{
if ( V_14 -> V_16 . V_33 . V_280 & V_281 )
return F_91 ( V_14 , & V_14 -> V_249 ) ;
return 0 ;
}
static void F_100 ( struct V_14 * V_14 )
{
if ( V_14 -> V_249 . V_249 ) {
F_77 ( & V_14 -> V_2 -> V_19 ,
& V_14 -> V_249 . V_272 ) ;
V_14 -> V_249 . V_249 = NULL ;
}
}
static T_4 F_101 ( struct V_187 * V_19 ,
struct V_282
* V_283 , char * V_3 )
{
struct V_1 * V_2 = F_55 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
return snprintf ( V_3 , V_284 , L_17 , V_14 -> V_16 . V_114 ) ;
}
static T_4 F_102 ( struct V_187 * V_19 ,
struct V_282 * V_283 ,
const char * V_3 , T_2 V_189 )
{
struct V_1 * V_2 = F_55 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
T_1 V_285 ;
if ( F_103 ( V_3 , 0 , & V_285 ) )
return - V_110 ;
if ( V_285 != 0 && V_285 != 1 )
return - V_110 ;
F_34 ( V_2 , V_285 , & V_14 -> V_16 . V_33 ) ;
return V_189 ;
}
static T_4 F_104 ( struct V_197 * V_198 ,
struct V_286 * V_287 ,
char * V_3 , int V_288 )
{
struct V_187 * V_19 = F_105 ( V_198 -> V_289 ) ;
struct V_1 * V_2 = F_55 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
T_1 V_290 ;
V_290 = V_14 -> V_164 . V_165 [ V_288 ] . V_172 ;
if ( V_290 >= 0 && V_290 < 3 )
return snprintf ( V_3 , V_284 , L_18 , V_290 ) ;
else
return snprintf ( V_3 , V_284 , L_18 , - 1 ) ;
}
static int F_106 ( struct V_14 * V_14 , T_3 V_291 ,
int V_288 )
{
int error = 0 ;
struct V_292 * V_293 = V_14 -> V_293 ;
V_293 -> V_294 [ V_288 ] . V_200 . V_201 = F_72 ( & V_14 -> V_2 -> V_19 ,
V_40 ,
L_19 , V_291 ) ;
if ( ! V_293 -> V_294 [ V_288 ] . V_200 . V_201 )
return - V_108 ;
error = F_62 ( V_14 , V_293 -> V_295 ,
& V_293 -> V_294 [ V_288 ] . V_200 ) ;
if ( error ) {
V_293 -> V_294 [ V_288 ] . V_200 . V_201 = NULL ;
F_3 ( V_14 -> V_2 ,
L_15 , error ) ;
return error ;
}
return 0 ;
}
static int F_107 ( struct V_14 * V_14 , unsigned char V_296 )
{
const T_2 V_162 = 2 ;
unsigned char * V_3 ;
int V_6 ;
V_3 = F_16 ( V_162 , V_40 ) ;
if ( ! V_3 )
return - V_108 ;
V_3 [ 0 ] = V_297 ;
V_3 [ 1 ] = V_296 ;
V_6 = F_4 ( V_14 -> V_2 , V_298 , V_3 ,
V_162 , V_43 ) ;
F_18 ( V_3 ) ;
return V_6 ;
}
static T_4 F_108 ( struct V_197 * V_198 ,
struct V_286 * V_283 ,
const char * V_3 , T_2 V_189 )
{
unsigned char V_296 = 0 ;
struct V_187 * V_19 = F_105 ( V_198 -> V_289 ) ;
struct V_1 * V_2 = F_55 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
int V_190 ;
if ( ! strncmp ( V_3 , L_20 , 2 ) ) {
V_296 = V_299 ;
} else {
F_109 ( V_14 -> V_2 , L_21 ,
V_3 ) ;
return - 1 ;
}
F_43 ( & V_14 -> V_191 ) ;
V_190 = F_107 ( V_14 , V_296 ) ;
F_45 ( & V_14 -> V_191 ) ;
return V_190 < 0 ? V_190 : V_189 ;
}
static void F_110 ( void * V_17 )
{
struct V_14 * V_14 = V_17 ;
struct V_292 * V_293 = V_14 -> V_293 ;
if ( ! V_293 )
return;
F_111 ( V_293 -> V_295 ) ;
F_112 ( & V_293 -> V_300 ) ;
V_14 -> V_293 = NULL ;
}
static int F_113 ( struct V_14 * V_14 )
{
int error = 0 ;
struct V_292 * V_293 ;
int V_75 ;
if ( V_14 -> V_16 . V_33 . type != V_241 )
return 0 ;
V_293 = F_80 ( & V_14 -> V_2 -> V_19 , sizeof( * V_14 -> V_293 ) ,
V_40 ) ;
if ( ! V_293 )
return - V_108 ;
V_14 -> V_293 = V_293 ;
F_114 ( & V_293 -> V_301 ) ;
error = F_115 ( & V_293 -> V_300 ,
5 * sizeof( struct V_302 ) ,
V_40 ) ;
if ( error ) {
F_3 ( V_14 -> V_2 , L_22 ) ;
return - V_108 ;
}
V_293 -> V_294 [ 0 ] . V_200 = V_303 ;
V_293 -> V_294 [ 1 ] . V_200 = V_304 ;
V_293 -> V_294 [ 2 ] . V_200 = V_305 ;
V_293 -> V_294 [ 3 ] . V_200 = V_306 ;
V_293 -> V_294 [ 4 ] . V_200 = V_307 ;
V_293 -> V_295 = F_116 ( L_23 ,
& V_14 -> V_2 -> V_19 . V_198 ) ;
if ( ! V_293 -> V_295 )
return - V_108 ;
error = F_117 ( V_293 -> V_295 , V_308 ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_15 , error ) ;
return error ;
}
for ( V_75 = 0 ; V_75 < V_309 ; V_75 ++ ) {
V_14 -> V_164 . V_165 [ V_75 ] . V_172 = V_310 ;
V_293 -> V_294 [ V_75 ] . V_291 = 0 ;
}
error = F_82 ( & V_14 -> V_2 -> V_19 ,
F_110 , V_14 ) ;
if ( error )
return error ;
return 0 ;
}
static struct V_18 * F_118 ( struct V_14 * V_14 )
{
struct V_18 * V_18 ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
V_18 = F_119 ( & V_2 -> V_19 ) ;
if ( ! V_18 )
return NULL ;
V_18 -> V_201 = V_16 -> V_33 . V_201 ;
V_18 -> V_140 = V_2 -> V_140 ;
V_18 -> V_19 . V_289 = & V_2 -> V_19 ;
V_18 -> V_311 = F_8 ;
V_18 -> V_312 = F_11 ;
V_18 -> V_313 = V_2 -> V_313 ;
V_18 -> V_41 . V_314 = V_2 -> V_117 ;
V_18 -> V_41 . V_146 = V_2 -> V_146 ;
V_18 -> V_41 . V_148 = V_16 -> V_167 ? V_16 -> V_167 : V_2 -> V_148 ;
V_18 -> V_41 . V_315 = V_2 -> V_315 ;
F_120 ( V_18 , V_14 ) ;
return V_18 ;
}
static int F_121 ( struct V_14 * V_14 )
{
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
V_16 -> V_316 = F_118 ( V_14 ) ;
V_16 -> V_93 = F_118 ( V_14 ) ;
V_16 -> V_229 = F_118 ( V_14 ) ;
if ( ! V_16 -> V_316 ||
! V_16 -> V_93 ||
! V_16 -> V_229 )
return - V_108 ;
V_16 -> V_316 -> V_201 = V_16 -> V_317 ;
V_16 -> V_93 -> V_201 = V_16 -> V_318 ;
V_16 -> V_229 -> V_201 = V_16 -> V_319 ;
return 0 ;
}
static int F_122 ( struct V_14 * V_14 )
{
struct V_18 * V_320 , * V_321 , * V_322 ;
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
int error = 0 ;
V_320 = V_16 -> V_316 ;
V_321 = V_16 -> V_93 ;
V_322 = V_16 -> V_229 ;
if ( ! V_320 || ! V_321 || ! V_322 )
return - V_110 ;
error = F_123 ( V_320 , V_16 ) ;
if ( error ) {
F_124 ( V_320 ) ;
V_16 -> V_316 = NULL ;
V_320 = NULL ;
} else {
error = F_125 ( V_320 ) ;
if ( error )
goto V_323;
}
error = F_126 ( V_321 , V_16 ) ;
if ( error ) {
F_124 ( V_321 ) ;
V_16 -> V_93 = NULL ;
V_321 = NULL ;
} else {
error = F_125 ( V_321 ) ;
if ( error )
goto V_323;
}
error = F_127 ( V_322 , V_16 ) ;
if ( error ) {
F_124 ( V_322 ) ;
V_16 -> V_229 = NULL ;
V_322 = NULL ;
} else {
error = F_125 ( V_322 ) ;
if ( error )
goto V_323;
}
return 0 ;
V_323:
V_16 -> V_229 = NULL ;
V_16 -> V_93 = NULL ;
V_16 -> V_316 = NULL ;
return error ;
}
static void F_128 ( struct V_32 * V_33 )
{
if ( V_33 -> V_324 ) {
V_33 -> V_85 = ( V_33 -> V_84 * 100 ) /
V_33 -> V_324 ;
V_33 -> V_90 = ( V_33 -> V_89 * 100 ) /
V_33 -> V_325 ;
}
}
static void F_129 ( struct V_32 * V_33 )
{
if ( ! V_33 -> V_22 ) {
V_33 -> V_22 = 0x11 ;
V_33 -> V_87 = - 3 ;
}
V_33 -> V_324 = F_13 ( V_33 -> V_84 ,
V_33 -> V_85 ,
V_33 -> V_22 ,
V_33 -> V_87 ) ;
V_33 -> V_325 = F_13 ( V_33 -> V_89 ,
V_33 -> V_90 ,
V_33 -> V_22 ,
V_33 -> V_87 ) ;
}
void F_130 ( struct V_326 * V_327 )
{
struct V_14 * V_14 = F_42 ( V_327 , struct V_14 , V_328 ) ;
if ( ( V_14 -> V_16 . V_33 . V_280 & V_281 ) &&
! V_14 -> V_249 . V_249 ) {
F_99 ( V_14 ) ;
}
else if ( ! ( V_14 -> V_16 . V_33 . V_280 & V_281 ) &&
V_14 -> V_249 . V_249 ) {
F_100 ( V_14 ) ;
}
}
static T_2 F_131 ( struct V_1 * V_2 )
{
struct V_95 * V_99 ;
struct V_11 * V_12 ;
T_2 V_4 = 0 ;
V_99 = V_2 -> V_99 + V_101 ;
F_30 (report, &report_enum->report_list, list) {
T_2 V_329 = F_20 ( V_12 ) ;
if ( V_329 > V_4 )
V_4 = V_329 ;
}
return V_4 ;
}
static void F_132 ( struct V_14 * V_14 , const char * V_330 )
{
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_32 * V_33 = & V_16 -> V_33 ;
char V_201 [ V_331 ] ;
if ( ( V_33 -> type == V_71 ) && ! strcmp ( L_24 , V_33 -> V_201 ) ) {
if ( strstr ( V_14 -> V_2 -> V_201 , L_25 ) ||
strstr ( V_14 -> V_2 -> V_201 , L_26 ) ||
strstr ( V_14 -> V_2 -> V_201 , L_27 ) ) {
F_133 ( V_201 , V_14 -> V_2 -> V_201 , sizeof( V_201 ) ) ;
while ( 1 ) {
char * V_332 = strstr ( V_201 , L_28 ) ;
if ( V_332 == NULL )
break;
memmove ( V_332 , V_332 + 1 , strlen ( V_332 ) ) ;
}
if ( strstr ( V_201 , L_29 ) == V_201 ) {
int V_36 = strlen ( V_201 ) ;
int V_333 = strlen ( L_30 ) ;
memmove ( V_201 , V_201 + V_333 , V_36 - V_333 + 1 ) ;
}
if ( strstr ( V_201 , L_31 ) == V_201 ) {
int V_36 = strlen ( V_201 ) ;
int V_333 = strlen ( L_32 ) ;
memmove ( V_201 , V_201 + V_333 , V_36 - V_333 + 1 ) ;
}
if ( V_201 [ strlen ( V_201 ) - 1 ] == ' ' )
V_201 [ strlen ( V_201 ) - 1 ] = '\0' ;
} else {
snprintf ( V_201 , sizeof( V_201 ) ,
L_33 , V_33 -> V_201 , V_14 -> V_2 -> V_148 ) ;
}
} else {
F_133 ( V_201 , V_33 -> V_201 , sizeof( V_201 ) ) ;
}
snprintf ( V_16 -> V_201 , sizeof( V_16 -> V_201 ) , L_34 ,
V_201 , V_330 ) ;
snprintf ( V_16 -> V_317 , sizeof( V_16 -> V_317 ) ,
L_35 , V_201 , V_330 ) ;
snprintf ( V_16 -> V_318 , sizeof( V_16 -> V_318 ) ,
L_36 , V_201 , V_330 ) ;
snprintf ( V_16 -> V_319 , sizeof( V_16 -> V_319 ) ,
L_37 , V_201 , V_330 ) ;
}
static void F_134 ( struct V_14 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
if ( ! V_14 -> V_334 )
return;
F_77 ( & V_2 -> V_19 , V_14 ) ;
V_14 -> V_334 = false ;
V_14 -> V_16 . V_316 = NULL ;
V_14 -> V_16 . V_93 = NULL ;
V_14 -> V_16 . V_229 = NULL ;
}
static int F_135 ( struct V_14 * V_14 , bool V_335 )
{
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_32 * V_33 = & V_16 -> V_33 ;
struct V_1 * V_2 = V_14 -> V_2 ;
int error ;
unsigned int V_336 = V_337 ;
V_33 -> V_338 = F_131 ( V_2 ) ;
if ( V_33 -> V_338 > V_15 )
return - V_110 ;
if ( ! F_79 ( & V_2 -> V_19 , V_14 , V_40 ) )
return - V_108 ;
V_14 -> V_334 = true ;
error = F_121 ( V_14 ) ;
if ( error )
goto V_323;
if ( V_33 -> type == V_122 ) {
if ( V_33 -> V_338 == V_339 ) {
V_33 -> type = V_71 ;
} else if ( ( V_33 -> V_338 != V_340 ) &&
( V_33 -> V_338 != V_341 ) ) {
error = - V_163 ;
goto V_323;
}
}
F_128 ( V_33 ) ;
F_36 ( V_2 , V_33 ) ;
F_136 ( V_14 ) ;
if ( V_33 -> V_67 == V_135 &&
V_33 -> type != V_130 ) {
error = V_33 -> type == V_71 ? - V_163 : 0 ;
F_137 ( & V_2 -> V_19 , L_38 ,
V_2 -> V_201 ,
error ? L_39 : L_40 ) ;
if ( error )
goto V_323;
V_33 -> V_67 |= V_68 ;
}
F_129 ( V_33 ) ;
F_132 ( V_14 , V_335 ? L_41 : L_42 ) ;
error = F_48 ( V_2 ) ;
if ( error )
goto V_323;
if ( ! ( V_33 -> V_67 & V_134 ) &&
( V_33 -> V_280 & V_281 ) ) {
error = F_99 ( V_14 ) ;
if ( error )
goto V_323;
}
error = F_122 ( V_14 ) ;
if ( error )
goto V_323;
if ( V_14 -> V_16 . V_33 . V_67 & V_230 ) {
error = F_88 ( V_14 ) ;
if ( error )
goto V_323;
error = F_113 ( V_14 ) ;
if ( error )
goto V_323;
}
if ( V_33 -> type == V_71 )
V_336 |= V_342 ;
error = F_138 ( V_2 , V_336 ) ;
if ( error ) {
F_3 ( V_2 , L_43 ) ;
goto V_323;
}
if ( ! V_335 ) {
F_35 ( V_2 , V_33 ) ;
}
if ( ( V_33 -> type == V_86 ) &&
( V_33 -> V_67 & V_68 ) ) {
error = - V_163 ;
goto V_343;
}
if ( ( V_33 -> type == V_344 ) &&
( ( V_33 -> V_67 & V_69 ) ||
( V_33 -> V_67 & V_230 ) ) ) {
error = - V_163 ;
goto V_343;
}
if ( V_33 -> V_67 & V_134 )
error = F_10 ( V_2 ) ;
if ( ( V_16 -> V_33 . type == V_345 ||
V_16 -> V_33 . type == V_346 ) &&
( V_16 -> V_33 . V_67 & V_69 ) ) {
V_16 -> V_156 -> type = V_16 -> V_33 . type ;
V_16 -> V_156 -> V_93 = V_16 -> V_93 ;
}
F_81 ( & V_2 -> V_19 , V_14 ) ;
return 0 ;
V_343:
F_139 ( V_2 ) ;
V_323:
F_134 ( V_14 ) ;
return error ;
}
static void F_140 ( struct V_326 * V_327 )
{
struct V_14 * V_14 = F_42 ( V_327 , struct V_14 , V_347 ) ;
struct V_348 * V_349 = V_14 -> V_349 ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_1 * V_350 , * V_351 ;
struct V_14 * V_352 , * V_353 ;
struct V_16 * V_354 , * V_355 ;
int error ;
F_100 ( V_14 ) ;
V_350 = F_141 ( V_349 -> V_356 -> V_357 [ 1 ] ) ;
V_352 = F_6 ( V_350 ) ;
V_354 = & ( V_352 -> V_16 ) ;
F_134 ( V_352 ) ;
V_351 = F_141 ( V_349 -> V_356 -> V_357 [ 2 ] ) ;
V_353 = F_6 ( V_351 ) ;
V_355 = & ( V_353 -> V_16 ) ;
F_134 ( V_353 ) ;
if ( V_16 -> V_167 == 0 ) {
F_109 ( V_14 -> V_2 , L_44 ) ;
} else {
const struct V_358 * V_41 = V_359 ;
F_109 ( V_14 -> V_2 , L_45 ,
V_16 -> V_167 ) ;
while ( V_41 -> V_117 ) {
if ( V_41 -> V_146 == V_360 &&
V_41 -> V_148 == V_16 -> V_167 )
break;
V_41 ++ ;
}
if ( ! V_41 -> V_117 ) {
F_109 ( V_14 -> V_2 , L_46 ) ;
return;
}
V_354 -> V_33 =
* ( (struct V_32 * ) V_41 -> V_361 ) ;
V_354 -> V_167 = V_16 -> V_167 ;
F_139 ( V_350 ) ;
error = F_135 ( V_352 , true ) ;
if ( error )
goto V_323;
if ( V_354 -> V_33 . V_39 ||
( V_354 -> V_33 . type >= V_345 &&
V_354 -> V_33 . type <= V_70 ) ) {
V_355 -> V_33 =
* ( (struct V_32 * ) V_41 -> V_361 ) ;
V_355 -> V_167 = V_16 -> V_167 ;
F_139 ( V_351 ) ;
error = F_135 ( V_353 , true ) ;
if ( error )
goto V_323;
}
F_133 ( V_16 -> V_201 , V_354 -> V_201 ,
sizeof( V_16 -> V_201 ) ) ;
error = F_99 ( V_14 ) ;
if ( error )
goto V_323;
}
return;
V_323:
F_134 ( V_352 ) ;
F_134 ( V_353 ) ;
return;
}
static void F_142 ( struct V_14 * V_14 , unsigned int V_288 )
{
struct V_292 * V_293 = V_14 -> V_293 ;
T_6 V_291 = V_293 -> V_294 [ V_288 ] . V_291 ;
int V_75 ;
unsigned long V_215 ;
F_143 ( & V_293 -> V_301 , V_215 ) ;
V_293 -> V_294 [ V_288 ] . V_362 = false ;
F_144 ( & V_293 -> V_301 , V_215 ) ;
if ( V_293 -> V_294 [ V_288 ] . V_249 . V_249 )
F_77 ( & V_14 -> V_2 -> V_19 ,
& V_293 -> V_294 [ V_288 ] . V_249 . V_272 ) ;
if ( V_293 -> V_294 [ V_288 ] . V_200 . V_201 )
F_77 ( & V_14 -> V_2 -> V_19 ,
& V_293 -> V_294 [ V_288 ] ) ;
for ( V_75 = 0 ; V_75 < V_309 ; V_75 ++ ) {
if ( V_293 -> V_294 [ V_75 ] . V_291 == V_291 ) {
V_293 -> V_294 [ V_75 ] . V_291 = 0 ;
V_293 -> V_294 [ V_75 ] . V_200 . V_201 = NULL ;
V_293 -> V_294 [ V_75 ] . V_362 = false ;
V_293 -> V_294 [ V_75 ] . V_249 . V_249 = NULL ;
V_14 -> V_164 . V_165 [ V_75 ] . V_172 = V_310 ;
}
}
}
static int F_145 ( struct V_14 * V_14 , T_6 V_291 ,
unsigned int V_288 )
{
struct V_292 * V_293 = V_14 -> V_293 ;
struct V_187 * V_19 = & V_14 -> V_2 -> V_19 ;
int error , V_363 ;
for ( V_363 = 0 ; V_363 < V_309 ; V_363 ++ ) {
if ( V_293 -> V_294 [ V_363 ] . V_291 == V_291 )
break;
}
if ( V_363 < V_309 ) {
V_293 -> V_294 [ V_288 ] . V_291 = V_291 ;
return 0 ;
}
if ( ! F_79 ( V_19 , & V_293 -> V_294 [ V_288 ] , V_40 ) )
return - V_108 ;
error = F_106 ( V_14 , V_291 , V_288 ) ;
if ( error )
goto V_323;
V_293 -> V_294 [ V_288 ] . V_364 = F_118 ( V_14 ) ;
if ( ! V_293 -> V_294 [ V_288 ] . V_364 ) {
error = - V_108 ;
goto V_323;
}
V_293 -> V_294 [ V_288 ] . V_364 -> V_313 = V_293 -> V_294 [ V_288 ] . V_200 . V_201 ;
V_293 -> V_294 [ V_288 ] . V_364 -> V_201 = V_14 -> V_16 . V_319 ;
if ( ! V_293 -> V_294 [ V_288 ] . V_364 -> V_201 ) {
error = - V_110 ;
goto V_323;
}
error = F_127 ( V_293 -> V_294 [ V_288 ] . V_364 ,
& V_14 -> V_16 ) ;
if ( error )
goto V_323;
V_293 -> V_294 [ V_288 ] . V_291 = V_291 ;
error = F_125 ( V_293 -> V_294 [ V_288 ] . V_364 ) ;
if ( error )
goto V_323;
error = F_78 (
& V_293 -> V_294 [ V_288 ] . V_364 -> V_19 ,
V_14 , V_288 , 3 , true ) ;
if ( error )
goto V_323;
V_293 -> V_294 [ V_288 ] . V_362 = true ;
F_81 ( V_19 , & V_293 -> V_294 [ V_288 ] ) ;
return 0 ;
V_323:
F_77 ( V_19 , & V_293 -> V_294 [ V_288 ] ) ;
V_293 -> V_294 [ V_288 ] . V_291 = 0 ;
return error ;
}
static int F_146 ( struct V_14 * V_14 , int V_288 )
{
struct V_292 * V_293 = V_14 -> V_293 ;
int error ;
if ( ! V_293 -> V_294 [ V_288 ] . V_362 )
return 0 ;
if ( V_293 -> V_294 [ V_288 ] . V_249 . V_249 )
return 0 ;
if ( V_14 -> V_164 . V_165 [ V_288 ] . V_172 == V_310 )
return 0 ;
error = F_91 ( V_14 ,
& V_14 -> V_293 -> V_294 [ V_288 ] . V_249 ) ;
if ( error )
return error ;
return 0 ;
}
static void F_147 ( struct V_326 * V_327 )
{
struct V_14 * V_14 = F_42 ( V_327 , struct V_14 , V_365 ) ;
struct V_292 * V_293 = V_14 -> V_293 ;
struct V_302 V_17 ;
unsigned long V_215 ;
unsigned int V_189 ;
T_6 V_291 ;
int V_75 ;
F_143 ( & V_293 -> V_301 , V_215 ) ;
V_189 = F_148 ( & V_293 -> V_300 , & V_17 , sizeof( V_17 ) ) ;
if ( V_189 != sizeof( V_17 ) ) {
F_3 ( V_14 -> V_2 ,
L_47 ) ;
F_144 ( & V_293 -> V_301 , V_215 ) ;
return;
}
if ( ! F_149 ( & V_293 -> V_300 ) )
F_150 ( & V_14 -> V_16 , V_366 ) ;
F_144 ( & V_293 -> V_301 , V_215 ) ;
for ( V_75 = 0 ; V_75 < V_309 ; V_75 ++ ) {
V_291 = V_17 . V_293 [ V_75 ] . V_291 ;
if ( V_17 . V_293 [ V_75 ] . V_367 ) {
if ( V_293 -> V_294 [ V_75 ] . V_291 == V_291 ) {
F_146 ( V_14 , V_75 ) ;
continue;
}
if ( V_293 -> V_294 [ V_75 ] . V_291 )
F_142 ( V_14 , V_75 ) ;
F_145 ( V_14 , V_291 , V_75 ) ;
} else if ( V_293 -> V_294 [ V_75 ] . V_291 ) {
F_142 ( V_14 , V_75 ) ;
}
}
}
static int F_151 ( struct V_1 * V_2 ,
const struct V_358 * V_41 )
{
struct V_123 * V_124 = F_152 ( V_2 -> V_19 . V_289 ) ;
struct V_348 * V_19 = F_153 ( V_124 ) ;
struct V_14 * V_14 ;
struct V_16 * V_16 ;
struct V_32 * V_33 ;
int error ;
if ( ! V_41 -> V_361 )
return - V_110 ;
V_2 -> V_280 |= V_368 ;
V_2 -> V_280 &= ~ V_369 ;
V_14 = F_80 ( & V_2 -> V_19 , sizeof( struct V_14 ) , V_40 ) ;
if ( ! V_14 )
return - V_108 ;
F_154 ( V_2 , V_14 ) ;
V_14 -> V_2 = V_2 ;
V_16 = & V_14 -> V_16 ;
V_16 -> V_33 = * ( (struct V_32 * ) V_41 -> V_361 ) ;
V_33 = & V_16 -> V_33 ;
if ( V_33 -> V_370 && V_33 -> V_371 != V_2 -> type ) {
error = - V_163 ;
goto V_323;
}
V_16 -> V_34 . V_47 = - 1 ;
V_16 -> V_53 = - 1 ;
V_14 -> V_349 = V_19 ;
V_14 -> V_124 = V_124 ;
F_155 ( & V_14 -> V_191 ) ;
F_156 ( & V_14 -> V_347 , F_140 ) ;
F_156 ( & V_14 -> V_328 , F_130 ) ;
F_156 ( & V_14 -> V_365 , F_147 ) ;
error = F_157 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_48 ) ;
goto V_323;
}
error = F_135 ( V_14 , false ) ;
if ( error )
goto V_323;
if ( V_2 -> V_117 == V_118 ) {
error = F_158 ( & V_2 -> V_19 , & V_372 ) ;
if ( error )
F_17 ( V_2 ,
L_49 ,
error ) ;
}
return 0 ;
V_323:
F_154 ( V_2 , NULL ) ;
return error ;
}
static void F_159 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_32 * V_33 = & V_16 -> V_33 ;
if ( V_33 -> V_67 & V_134 )
F_12 ( V_2 ) ;
F_139 ( V_2 ) ;
F_160 ( & V_14 -> V_347 ) ;
F_160 ( & V_14 -> V_328 ) ;
F_160 ( & V_14 -> V_365 ) ;
if ( V_2 -> V_117 == V_118 )
F_161 ( & V_2 -> V_19 , & V_372 ) ;
F_154 ( V_2 , NULL ) ;
}
static int F_162 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_32 * V_33 = & V_14 -> V_16 . V_33 ;
F_43 ( & V_14 -> V_191 ) ;
F_35 ( V_2 , V_33 ) ;
F_52 ( V_14 ) ;
F_45 ( & V_14 -> V_191 ) ;
return 0 ;
}
static int F_163 ( struct V_1 * V_2 )
{
return F_162 ( V_2 ) ;
}
