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
unsigned int V_35 = F_16 ( V_31 -> V_36 ) ;
T_1 * V_17 ;
int V_37 ;
int V_38 ;
switch ( V_35 ) {
case V_39 :
if ( ! V_33 -> V_40 ) {
V_17 = F_17 ( 2 , V_41 ) ;
if ( ! V_17 )
break;
V_17 [ 0 ] = V_25 -> V_12 -> V_42 ;
V_37 = F_1 ( V_2 , V_43 ,
V_17 , 2 , V_44 ) ;
if ( V_37 == 2 ) {
V_33 -> V_40 = V_17 [ 1 ] ;
} else {
V_33 -> V_40 = 16 ;
F_18 ( V_2 , L_4
L_5
L_6 ,
V_33 -> V_40 ) ;
}
F_19 ( V_17 ) ;
}
break;
case V_45 :
if ( V_31 -> V_46 >= V_25 -> V_47 ) {
F_20 ( & V_2 -> V_19 , L_7 ) ;
break;
}
V_34 -> V_48 = V_25 -> V_12 -> V_42 ;
V_34 -> V_49 = V_31 -> V_46 ;
break;
case V_50 :
if ( V_25 -> V_12 -> V_42 == 0x0B &&
( V_25 -> V_51 == V_52 ||
V_25 -> V_51 == V_53 ) ) {
V_14 -> V_16 . V_54 = V_25 -> V_12 -> V_42 ;
V_14 -> V_16 . V_55 = 0 ;
}
break;
case V_56 :
V_14 -> V_16 . V_54 = V_25 -> V_12 -> V_42 ;
V_14 -> V_16 . V_55 = 2 ;
break;
case V_57 :
case V_58 :
if ( V_25 -> V_12 -> V_42 == 0x03 &&
( V_25 -> V_51 == V_59 ||
V_25 -> V_51 == V_60 ) ) {
V_14 -> V_16 . V_54 = V_25 -> V_12 -> V_42 ;
V_14 -> V_16 . V_55 = 0 ;
}
break;
case V_61 :
case V_62 :
case V_63 :
case V_64 :
V_38 = F_21 ( V_25 -> V_12 ) ;
V_17 = F_22 ( V_25 -> V_12 , V_41 ) ;
if ( ! V_17 )
break;
V_17 [ 0 ] = V_25 -> V_12 -> V_42 ;
V_37 = F_1 ( V_2 , V_43 ,
V_17 , V_38 , V_44 ) ;
if ( V_37 == V_38 ) {
V_37 = F_23 ( V_2 , V_43 ,
V_17 , V_38 , 0 ) ;
} else {
F_18 ( V_2 , L_8 ,
V_65 ) ;
}
F_19 ( V_17 ) ;
break;
}
}
static void F_24 ( struct V_1 * V_2 ,
struct V_24 * V_25 , struct V_30 * V_31 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_32 * V_33 = & V_14 -> V_16 . V_33 ;
bool V_66 = F_25 ( V_25 ) ;
bool V_67 = F_26 ( V_25 ) ;
if ( V_67 )
V_33 -> V_68 |= V_69 ;
else if ( V_66 )
V_33 -> V_68 |= V_70 ;
else
return;
if ( V_33 -> type > V_71 ) {
if ( V_66 && ! V_33 -> V_40 )
V_33 -> V_40 = 1 ;
}
if ( V_33 -> type == V_72 &&
V_31 -> V_36 == 0x000D0000 &&
V_25 -> V_51 == V_73 &&
V_25 -> V_74 == V_75 ) {
int V_76 = V_31 -> V_46 ;
if ( V_76 - 4 >= 0 && V_76 + 1 < V_25 -> V_77 &&
V_25 -> V_31 [ V_76 - 4 ] . V_36 == V_78 &&
V_25 -> V_31 [ V_76 - 3 ] . V_36 == V_79 &&
V_25 -> V_31 [ V_76 - 2 ] . V_36 == V_80 &&
V_25 -> V_31 [ V_76 - 1 ] . V_36 == V_81 &&
V_25 -> V_31 [ V_76 + 1 ] . V_36 == V_82 ) {
V_31 -> V_36 = V_83 ;
}
}
switch ( V_31 -> V_36 ) {
case V_84 :
V_33 -> V_85 = V_25 -> V_26 ;
if ( V_66 ) {
V_33 -> V_86 = V_25 -> V_27 ;
if ( ( V_33 -> type != V_71 ) &&
( V_33 -> type != V_87 ) ) {
V_33 -> V_22 = V_25 -> V_22 ;
V_33 -> V_88 = V_25 -> V_28 ;
}
}
break;
case V_89 :
V_33 -> V_90 = V_25 -> V_26 ;
if ( V_66 ) {
V_33 -> V_91 = V_25 -> V_27 ;
if ( ( V_33 -> type != V_71 ) &&
( V_33 -> type != V_87 ) ) {
V_33 -> V_22 = V_25 -> V_22 ;
V_33 -> V_88 = V_25 -> V_28 ;
}
}
break;
case V_92 :
if ( V_67 )
V_33 -> V_93 = V_25 -> V_26 ;
break;
}
if ( V_33 -> type == V_72 )
F_27 ( V_2 , V_25 , V_31 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_16 * V_16 = & V_14 -> V_16 ;
if ( V_33 -> type == V_72 ) {
if ( V_16 -> V_94 ) {
if ( V_16 -> V_95 )
V_33 -> V_68 |= V_96 ;
else
V_33 -> V_68 &= ~ V_96 ;
}
if ( V_33 -> V_40 > 1 ) {
if ( V_33 -> V_68 & V_96 )
F_29 ( V_16 -> V_97 ,
V_16 -> V_33 . V_40 ,
V_98 ) ;
else
F_29 ( V_16 -> V_97 ,
V_16 -> V_33 . V_40 ,
V_99 ) ;
}
}
}
static void F_30 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_100 * V_101 ;
struct V_11 * V_102 ;
int V_76 , V_103 ;
V_101 = & V_2 -> V_104 [ V_43 ] ;
F_31 (hreport, &rep_enum->report_list, list) {
for ( V_76 = 0 ; V_76 < V_102 -> V_105 ; V_76 ++ ) {
if ( V_102 -> V_25 [ V_76 ] -> V_47 < 1 )
continue;
for ( V_103 = 0 ; V_103 < V_102 -> V_25 [ V_76 ] -> V_77 ; V_103 ++ ) {
F_15 ( V_2 , V_102 -> V_25 [ V_76 ] ,
V_102 -> V_25 [ V_76 ] -> V_31 + V_103 ) ;
}
}
}
V_101 = & V_2 -> V_104 [ V_106 ] ;
F_31 (hreport, &rep_enum->report_list, list) {
if ( ! V_102 -> V_105 )
continue;
for ( V_76 = 0 ; V_76 < V_102 -> V_105 ; V_76 ++ )
for ( V_103 = 0 ; V_103 < V_102 -> V_25 [ V_76 ] -> V_77 ; V_103 ++ )
F_24 ( V_2 , V_102 -> V_25 [ V_76 ] ,
V_102 -> V_25 [ V_76 ] -> V_31 + V_103 ) ;
}
F_28 ( V_2 , V_33 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_34 * V_34 = & V_14 -> V_16 . V_34 ;
struct V_11 * V_107 ;
struct V_100 * V_108 ;
if ( V_34 -> V_48 < 0 )
return 0 ;
V_108 = & ( V_2 -> V_104 [ V_43 ] ) ;
V_107 = V_108 -> V_109 [ V_34 -> V_48 ] ;
if ( V_107 ) {
V_107 -> V_25 [ 0 ] -> V_110 [ V_34 -> V_49 ] = 2 ;
F_33 ( V_2 , V_107 , V_10 ) ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_16 * V_16 )
{
T_1 * V_111 ;
struct V_11 * V_107 ;
struct V_100 * V_108 ;
int V_112 ;
int error = - V_113 , V_114 = 0 ;
if ( V_16 -> V_54 < 0 )
return 0 ;
V_108 = & ( V_2 -> V_104 [ V_43 ] ) ;
V_107 = V_108 -> V_109 [ V_16 -> V_54 ] ;
if ( ! V_107 )
return - V_115 ;
V_111 = F_22 ( V_107 , V_41 ) ;
if ( ! V_111 )
return - V_113 ;
V_112 = F_21 ( V_107 ) ;
do {
V_111 [ 0 ] = V_16 -> V_54 ;
V_111 [ 1 ] = V_16 -> V_55 ;
error = F_4 ( V_2 , V_43 , V_111 ,
V_112 , 1 ) ;
if ( error >= 0 )
error = F_1 ( V_2 , V_43 ,
V_111 , V_112 , 1 ) ;
} while ( error >= 0 &&
V_111 [ 1 ] != V_16 -> V_54 &&
V_114 ++ < V_116 );
F_19 ( V_111 ) ;
return error < 0 ? error : 0 ;
}
static int F_35 ( struct V_1 * V_2 , T_1 V_117 ,
struct V_32 * V_33 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
int V_37 ;
T_1 V_111 [ 2 ] ;
switch ( V_33 -> type ) {
case V_118 :
V_111 [ 0 ] = 0x03 ;
V_111 [ 1 ] = 0x00 ;
V_37 = F_4 ( V_2 , V_43 , V_111 , 2 ,
3 ) ;
if ( V_37 >= 0 ) {
V_111 [ 0 ] = V_117 == 0 ? 0x05 : 0x06 ;
V_111 [ 1 ] = 0x00 ;
V_37 = F_4 ( V_2 , V_43 ,
V_111 , 2 , 3 ) ;
if ( V_37 >= 0 ) {
V_14 -> V_16 . V_119 = V_117 ;
return 0 ;
}
}
F_18 ( V_2 , L_9 ,
V_111 [ 0 ] , V_37 ) ;
break;
case V_120 :
if ( V_117 == 1 )
V_14 -> V_16 . V_121 &= ~ 0x20 ;
else
V_14 -> V_16 . V_121 |= 0x20 ;
V_111 [ 0 ] = 0x03 ;
V_111 [ 1 ] = V_14 -> V_16 . V_121 ;
V_37 = F_4 ( V_2 , V_43 , V_111 , 2 ,
1 ) ;
if ( V_37 >= 0 )
V_14 -> V_16 . V_119 = V_117 ;
break;
}
return 0 ;
}
static int F_36 ( struct V_14 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_32 * V_33 = & V_16 -> V_33 ;
if ( V_2 -> V_122 == V_123 )
return F_35 ( V_2 , 1 , V_33 ) ;
if ( V_33 -> type != V_72 ) {
if ( V_33 -> V_68 & V_70 ) {
if ( V_33 -> type > V_124 ) {
V_16 -> V_54 = 3 ;
V_16 -> V_55 = 4 ;
} else if ( V_33 -> type == V_125 ) {
V_16 -> V_54 = 18 ;
V_16 -> V_55 = 2 ;
} else if ( V_33 -> type == V_126 ) {
V_16 -> V_54 = 131 ;
V_16 -> V_55 = 2 ;
} else if ( V_33 -> type == V_127 ) {
V_16 -> V_54 = 2 ;
V_16 -> V_55 = 2 ;
}
} else if ( V_33 -> V_68 & V_69 ) {
if ( V_33 -> type <= V_71 ) {
V_16 -> V_54 = 2 ;
V_16 -> V_55 = 2 ;
}
}
}
F_34 ( V_2 , V_16 ) ;
if ( V_33 -> type == V_72 )
return F_32 ( V_2 ) ;
return 0 ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_128 * V_129 = V_14 -> V_129 ;
V_33 -> V_130 = 4 ;
V_33 -> V_131 = 4 ;
V_33 -> V_132 = 0 ;
V_33 -> V_133 = 1 ;
V_33 -> V_134 = 1 ;
if ( V_33 -> type == V_135 ) {
if ( V_129 -> V_136 -> V_137 . V_138 == 0 )
V_33 -> V_68 = V_139 ;
else
V_33 -> V_68 = V_140 ;
return;
}
F_30 ( V_2 , V_33 ) ;
}
static bool F_38 ( struct V_1 * V_141 ,
struct V_1 * V_142 , char V_143 )
{
int V_144 = strrchr ( V_141 -> V_145 , V_143 ) - V_141 -> V_145 ;
int V_146 = strrchr ( V_142 -> V_145 , V_143 ) - V_142 -> V_145 ;
if ( V_144 != V_146 || V_144 <= 0 || V_146 <= 0 )
return false ;
return ! strncmp ( V_141 -> V_145 , V_142 -> V_145 , V_144 ) ;
}
static bool F_39 ( struct V_1 * V_2 ,
struct V_1 * V_147 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_32 * V_33 = & V_14 -> V_16 . V_33 ;
struct V_14 * V_148 = F_6 ( V_147 ) ;
struct V_32 * V_149 = & V_148 -> V_16 . V_33 ;
T_3 V_150 = V_33 -> V_150 ? V_33 -> V_150 : V_2 -> V_151 ;
T_3 V_152 = V_33 -> V_152 ? V_33 -> V_152 : V_2 -> V_153 ;
if ( V_33 -> V_150 != V_154 && V_147 -> V_151 != V_150 )
return false ;
if ( V_33 -> V_152 != V_154 && V_147 -> V_153 != V_152 )
return false ;
if ( V_2 -> V_151 == V_147 -> V_151 && V_2 -> V_153 == V_147 -> V_153 ) {
if ( ! F_38 ( V_2 , V_147 , '/' ) )
return false ;
} else {
if ( ! F_38 ( V_2 , V_147 , '.' ) )
return false ;
}
if ( V_33 -> type != V_72 )
return true ;
if ( ( V_33 -> V_68 & V_96 ) &&
! ( V_149 -> V_68 & V_96 ) )
return false ;
if ( ! ( V_33 -> V_68 & V_96 ) &&
( V_149 -> V_68 & V_96 ) )
return false ;
if ( ( V_33 -> V_68 & V_69 ) &&
! ( V_149 -> V_68 & V_70 ) )
return false ;
if ( ( V_33 -> V_68 & V_70 ) &&
! ( V_149 -> V_68 & V_69 ) )
return false ;
return true ;
}
static struct V_155 * F_40 ( struct V_1 * V_2 )
{
struct V_155 * V_17 ;
F_31 (data, &wacom_udev_list, list) {
if ( F_38 ( V_2 , V_17 -> V_19 , '/' ) )
return V_17 ;
}
F_31 (data, &wacom_udev_list, list) {
if ( F_39 ( V_2 , V_17 -> V_19 ) ) {
F_41 ( & V_17 -> V_156 ) ;
return V_17 ;
}
}
return NULL ;
}
static void F_42 ( struct V_156 * V_156 )
{
struct V_155 * V_17 =
F_43 ( V_156 , struct V_155 , V_156 ) ;
F_44 ( & V_157 ) ;
F_45 ( & V_17 -> V_158 ) ;
F_46 ( & V_157 ) ;
F_19 ( V_17 ) ;
}
static void F_47 ( void * V_159 )
{
struct V_14 * V_14 = V_159 ;
struct V_155 * V_17 ;
struct V_16 * V_16 = & V_14 -> V_16 ;
if ( V_16 -> V_160 ) {
V_17 = F_43 ( V_16 -> V_160 , struct V_155 ,
V_160 ) ;
if ( V_16 -> V_160 -> V_161 == V_14 -> V_2 )
V_16 -> V_160 -> V_161 = NULL ;
else if ( V_16 -> V_160 -> V_67 == V_14 -> V_2 )
V_16 -> V_160 -> V_67 = NULL ;
F_48 ( & V_17 -> V_156 , F_42 ) ;
V_16 -> V_160 = NULL ;
}
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_155 * V_17 ;
int V_6 = 0 ;
F_44 ( & V_157 ) ;
V_17 = F_40 ( V_2 ) ;
if ( ! V_17 ) {
V_17 = F_17 ( sizeof( struct V_155 ) , V_41 ) ;
if ( ! V_17 ) {
V_6 = - V_113 ;
goto V_162;
}
F_50 ( & V_17 -> V_156 ) ;
V_17 -> V_19 = V_2 ;
F_51 ( & V_17 -> V_158 , & V_163 ) ;
}
V_16 -> V_160 = & V_17 -> V_160 ;
V_6 = F_52 ( & V_2 -> V_19 , F_47 , V_14 ) ;
if ( V_6 ) {
F_46 ( & V_157 ) ;
F_47 ( V_14 ) ;
return V_6 ;
}
if ( V_16 -> V_33 . V_68 & V_70 )
V_16 -> V_160 -> V_161 = V_2 ;
else if ( V_16 -> V_33 . V_68 & V_69 )
V_16 -> V_160 -> V_67 = V_2 ;
V_162:
F_46 ( & V_157 ) ;
return V_6 ;
}
static int F_53 ( struct V_14 * V_14 )
{
unsigned char * V_3 ;
int V_6 ;
unsigned char V_164 = V_165 ;
int V_166 = 9 ;
if ( ! V_14 -> V_167 . V_168 )
return - V_169 ;
if ( V_14 -> V_16 . V_170 ) {
V_164 = V_171 ;
V_166 = 13 ;
}
else if ( V_14 -> V_16 . V_33 . type == V_172 ) {
V_164 = V_173 ;
V_166 = 51 ;
}
V_3 = F_17 ( V_166 , V_41 ) ;
if ( ! V_3 )
return - V_113 ;
if ( V_14 -> V_16 . V_33 . type == V_72 ) {
V_3 [ 0 ] = V_174 ;
V_3 [ 1 ] = V_14 -> V_167 . V_175 ;
V_3 [ 2 ] = V_14 -> V_167 . V_168 [ 0 ] . V_176 & 0x03 ;
} else if ( ( V_14 -> V_16 . V_33 . type >= V_177 &&
V_14 -> V_16 . V_33 . type <= V_178 ) ) {
int V_179 = V_14 -> V_167 . V_168 [ 0 ] . V_176 & 0x03 ;
int V_180 = ( ( ( V_14 -> V_167 . V_175 & 0x60 ) >> 5 ) - 1 ) & 0x03 ;
int V_181 = 0 ;
unsigned char V_182 = ( V_181 << 4 ) | ( V_180 << 2 ) | ( V_179 ) ;
V_3 [ 0 ] = V_164 ;
if ( V_14 -> V_16 . V_170 ) {
F_1 ( V_14 -> V_2 , V_43 ,
V_3 , V_166 , V_44 ) ;
V_3 [ 0 ] = V_164 ;
V_3 [ 4 ] = V_182 ;
} else
V_3 [ 1 ] = V_182 ;
}
else if ( V_14 -> V_16 . V_33 . type == V_172 ) {
V_3 [ 0 ] = V_164 ;
V_3 [ 4 ] = 100 ;
V_3 [ 5 ] = 100 ;
V_3 [ 6 ] = 100 ;
V_3 [ 7 ] = 100 ;
V_3 [ 8 ] = 100 ;
V_3 [ 9 ] = V_14 -> V_167 . V_175 ;
V_3 [ 10 ] = V_14 -> V_167 . V_168 [ 0 ] . V_176 & 0x03 ;
}
else {
int V_167 = V_14 -> V_167 . V_168 [ 0 ] . V_176 | 0x4 ;
if ( V_14 -> V_16 . V_33 . type == V_183 ||
V_14 -> V_16 . V_33 . type == V_184 )
V_167 |= ( V_14 -> V_167 . V_168 [ 1 ] . V_176 << 4 ) | 0x40 ;
V_3 [ 0 ] = V_164 ;
V_3 [ 1 ] = V_167 ;
V_3 [ 2 ] = V_14 -> V_167 . V_175 ;
V_3 [ 3 ] = V_14 -> V_167 . V_185 ;
V_3 [ 4 ] = V_14 -> V_167 . V_186 ;
}
V_6 = F_4 ( V_14 -> V_2 , V_43 , V_3 , V_166 ,
V_44 ) ;
F_19 ( V_3 ) ;
return V_6 ;
}
static int F_54 ( struct V_14 * V_14 , int V_187 , T_1 V_188 ,
const unsigned V_189 , const void * V_190 )
{
unsigned char * V_3 ;
int V_76 , V_6 ;
const unsigned V_191 = V_189 / 4 ;
V_3 = F_17 ( V_191 + 3 , V_41 ) ;
if ( ! V_3 )
return - V_113 ;
V_3 [ 0 ] = V_192 ;
V_3 [ 1 ] = 1 ;
V_6 = F_4 ( V_14 -> V_2 , V_43 , V_3 , 2 ,
V_44 ) ;
if ( V_6 < 0 )
goto V_162;
V_3 [ 0 ] = V_188 ;
V_3 [ 1 ] = V_187 & 0x07 ;
for ( V_76 = 0 ; V_76 < 4 ; V_76 ++ ) {
V_3 [ 2 ] = V_76 ;
memcpy ( V_3 + 3 , V_190 + V_76 * V_191 , V_191 ) ;
V_6 = F_4 ( V_14 -> V_2 , V_43 ,
V_3 , V_191 + 3 , V_44 ) ;
if ( V_6 < 0 )
break;
}
V_3 [ 0 ] = V_192 ;
V_3 [ 1 ] = 0 ;
F_4 ( V_14 -> V_2 , V_43 , V_3 , 2 ,
V_44 ) ;
V_162:
F_19 ( V_3 ) ;
return V_6 ;
}
static T_4 F_55 ( struct V_193 * V_19 , int V_194 ,
const char * V_3 , T_2 V_195 )
{
struct V_1 * V_2 = F_56 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
unsigned int V_42 ;
int V_196 ;
V_196 = F_57 ( V_3 , 10 , & V_42 ) ;
if ( V_196 )
return V_196 ;
F_44 ( & V_14 -> V_197 ) ;
V_14 -> V_167 . V_168 [ V_194 ] . V_176 = V_42 & 0x3 ;
V_196 = F_53 ( V_14 ) ;
F_46 ( & V_14 -> V_197 ) ;
return V_196 < 0 ? V_196 : V_195 ;
}
static T_4 F_58 ( struct V_14 * V_14 , T_1 * V_198 ,
const char * V_3 , T_2 V_195 )
{
unsigned int V_110 ;
int V_196 ;
V_196 = F_57 ( V_3 , 10 , & V_110 ) ;
if ( V_196 )
return V_196 ;
F_44 ( & V_14 -> V_197 ) ;
* V_198 = V_110 & 0x7f ;
V_196 = F_53 ( V_14 ) ;
F_46 ( & V_14 -> V_197 ) ;
return V_196 < 0 ? V_196 : V_195 ;
}
static T_4 F_59 ( struct V_193 * V_19 , int V_187 ,
const char * V_3 , T_2 V_195 )
{
struct V_1 * V_2 = F_56 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
int V_196 ;
unsigned V_189 ;
T_1 V_188 ;
if ( V_2 -> V_122 == V_123 ) {
V_189 = 256 ;
V_188 = V_199 ;
} else {
V_189 = 1024 ;
V_188 = V_200 ;
}
if ( V_195 != V_189 )
return - V_115 ;
F_44 ( & V_14 -> V_197 ) ;
V_196 = F_54 ( V_14 , V_187 , V_188 , V_189 , V_3 ) ;
F_46 ( & V_14 -> V_197 ) ;
return V_196 < 0 ? V_196 : V_195 ;
}
static void F_60 ( struct V_193 * V_19 , void * V_159 )
{
struct V_201 * V_202 = V_159 ;
struct V_203 * V_204 = V_202 -> V_205 ;
F_61 ( V_19 , L_10 ,
V_65 , V_202 -> V_206 -> V_207 ) ;
F_62 ( V_204 , V_202 -> V_206 ) ;
}
static int F_63 ( struct V_14 * V_14 ,
struct V_203 * V_205 ,
struct V_208 * V_206 )
{
struct V_201 * V_202 ;
int error ;
V_202 = F_64 ( F_60 ,
sizeof( struct V_201 ) ,
V_41 ) ;
if ( ! V_202 )
return - V_113 ;
V_202 -> V_206 = V_206 ;
V_202 -> V_205 = V_205 ;
error = F_65 ( V_202 -> V_205 , V_206 ) ;
if ( error )
return error ;
F_66 ( & V_14 -> V_2 -> V_19 , V_202 ) ;
return 0 ;
}
static int F_67 ( struct V_14 * V_14 ,
struct V_208 * V_206 )
{
return F_63 ( V_14 , & V_14 -> V_2 -> V_19 . V_204 ,
V_206 ) ;
}
enum V_209 F_68 ( struct V_210 * V_167 )
{
struct V_14 * V_14 = V_167 -> V_14 ;
if ( V_14 -> V_167 . V_211 )
return V_167 -> V_185 * V_212 / V_14 -> V_167 . V_211 ;
if ( V_14 -> V_167 . V_213 )
return V_167 -> V_175 * V_212 / V_14 -> V_167 . V_213 ;
return V_212 ;
}
static enum V_209 F_69 ( struct V_214 * V_215 )
{
struct V_210 * V_167 = F_43 ( V_215 , struct V_210 , V_215 ) ;
struct V_14 * V_14 = V_167 -> V_14 ;
if ( V_14 -> V_167 . V_168 [ V_167 -> V_206 ] . V_176 != V_167 -> V_42 )
return V_216 ;
return F_68 ( V_167 ) ;
}
static int F_70 ( struct V_214 * V_215 ,
enum V_209 V_217 )
{
struct V_210 * V_167 = F_43 ( V_215 , struct V_210 , V_215 ) ;
struct V_14 * V_14 = V_167 -> V_14 ;
int error ;
F_44 ( & V_14 -> V_197 ) ;
if ( ! V_14 -> V_167 . V_168 || ( V_217 == V_216 &&
V_14 -> V_167 . V_168 [ V_167 -> V_206 ] . V_176 != V_167 -> V_42 ) ) {
error = 0 ;
goto V_162;
}
V_167 -> V_175 = V_14 -> V_167 . V_175 = V_14 -> V_167 . V_213 * V_217 / V_212 ;
V_167 -> V_185 = V_14 -> V_167 . V_185 = V_14 -> V_167 . V_211 * V_217 / V_212 ;
V_14 -> V_167 . V_168 [ V_167 -> V_206 ] . V_176 = V_167 -> V_42 ;
error = F_53 ( V_14 ) ;
V_162:
F_46 ( & V_14 -> V_197 ) ;
return error ;
}
static void F_71 ( struct V_214 * V_215 ,
enum V_209 V_217 )
{
}
static int F_72 ( struct V_193 * V_19 , struct V_14 * V_14 ,
struct V_210 * V_167 , unsigned int V_206 ,
unsigned int V_42 , bool V_218 )
{
int error ;
char * V_207 ;
V_207 = F_73 ( V_19 , V_41 ,
L_11 ,
F_74 ( V_19 ) ,
V_206 ,
V_42 ) ;
if ( ! V_207 )
return - V_113 ;
if ( ! V_218 ) {
V_167 -> V_219 . V_207 = V_207 ;
error = F_75 ( V_19 , & V_167 -> V_219 ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_12 ,
V_167 -> V_215 . V_207 , error ) ;
return error ;
}
}
V_167 -> V_206 = V_206 ;
V_167 -> V_42 = V_42 ;
V_167 -> V_14 = V_14 ;
V_167 -> V_175 = V_14 -> V_167 . V_175 ;
V_167 -> V_185 = V_14 -> V_167 . V_185 ;
V_167 -> V_215 . V_207 = V_207 ;
V_167 -> V_215 . V_220 = V_212 ;
V_167 -> V_215 . V_221 = V_222 ;
V_167 -> V_215 . V_223 = F_69 ;
if ( ! V_218 ) {
V_167 -> V_215 . V_224 = F_70 ;
V_167 -> V_215 . V_225 = V_167 -> V_215 . V_207 ;
} else {
V_167 -> V_215 . V_226 = F_71 ;
}
error = F_76 ( V_19 , & V_167 -> V_215 ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_13 ,
V_167 -> V_215 . V_207 , error ) ;
V_167 -> V_215 . V_207 = NULL ;
return error ;
}
return 0 ;
}
static void F_77 ( void * V_17 )
{
struct V_227 * V_206 = V_17 ;
F_78 ( V_206 -> V_19 , V_206 ) ;
}
static int F_79 ( struct V_193 * V_19 ,
struct V_14 * V_14 ,
int V_228 , int V_195 ,
bool V_218 )
{
struct V_210 * V_229 ;
int V_76 , error ;
if ( V_228 >= V_14 -> V_167 . V_195 || V_195 <= 0 )
return - V_115 ;
if ( ! F_80 ( V_19 , & V_14 -> V_167 . V_168 [ V_228 ] , V_41 ) )
return - V_113 ;
V_229 = F_81 ( V_19 , sizeof( struct V_210 ) * V_195 , V_41 ) ;
if ( ! V_229 ) {
error = - V_113 ;
goto V_196;
}
V_14 -> V_167 . V_168 [ V_228 ] . V_229 = V_229 ;
V_14 -> V_167 . V_168 [ V_228 ] . V_195 = V_195 ;
for ( V_76 = 0 ; V_76 < V_195 ; V_76 ++ ) {
error = F_72 ( V_19 , V_14 , & V_229 [ V_76 ] ,
V_228 , V_76 , V_218 ) ;
if ( error )
goto V_196;
}
V_14 -> V_167 . V_168 [ V_228 ] . V_19 = V_19 ;
F_82 ( V_19 , & V_14 -> V_167 . V_168 [ V_228 ] ) ;
error = F_83 ( & V_14 -> V_2 -> V_19 ,
F_77 ,
& V_14 -> V_167 . V_168 [ V_228 ] ) ;
if ( error )
return error ;
return 0 ;
V_196:
F_78 ( V_19 , & V_14 -> V_167 . V_168 [ V_228 ] ) ;
return error ;
}
struct V_210 * F_84 ( struct V_14 * V_14 , unsigned int V_228 ,
unsigned int V_42 )
{
struct V_227 * V_206 ;
if ( V_228 >= V_14 -> V_167 . V_195 )
return NULL ;
V_206 = & V_14 -> V_167 . V_168 [ V_228 ] ;
if ( ! V_206 -> V_229 )
return NULL ;
V_42 %= V_206 -> V_195 ;
return & V_206 -> V_229 [ V_42 ] ;
}
struct V_210 * F_85 ( struct V_14 * V_14 , struct V_210 * V_230 )
{
struct V_210 * V_231 ;
int V_206 , V_232 ;
if ( ! V_14 || ! V_230 )
return NULL ;
V_206 = V_230 -> V_206 ;
V_232 = V_230 -> V_42 ;
do {
V_231 = F_84 ( V_14 , V_206 , ++ V_232 ) ;
if ( ! V_231 || V_231 == V_230 )
return V_231 ;
} while ( V_231 -> V_215 . V_219 != & V_231 -> V_219 );
return V_231 ;
}
static void F_86 ( void * V_17 )
{
struct V_14 * V_14 = V_17 ;
V_14 -> V_167 . V_168 = NULL ;
V_14 -> V_167 . V_195 = 0 ;
}
static int F_87 ( struct V_14 * V_14 , int V_195 )
{
struct V_193 * V_19 = & V_14 -> V_2 -> V_19 ;
struct V_227 * V_168 ;
int error ;
V_168 = F_81 ( V_19 , sizeof( struct V_227 ) * V_195 ,
V_41 ) ;
if ( ! V_168 )
return - V_113 ;
error = F_83 ( V_19 , F_86 , V_14 ) ;
if ( error )
return error ;
V_14 -> V_167 . V_168 = V_168 ;
V_14 -> V_167 . V_195 = V_195 ;
return 0 ;
}
static int F_88 ( struct V_14 * V_14 , int V_233 ,
int V_234 , bool V_218 )
{
struct V_193 * V_19 ;
int V_76 , error ;
if ( ! V_14 -> V_16 . V_235 )
return - V_115 ;
V_19 = & V_14 -> V_16 . V_235 -> V_19 ;
error = F_87 ( V_14 , V_233 ) ;
if ( error )
return error ;
for ( V_76 = 0 ; V_76 < V_233 ; V_76 ++ ) {
error = F_79 ( V_19 , V_14 , V_76 ,
V_234 ,
V_218 ) ;
if ( error )
return error ;
}
return 0 ;
}
int F_89 ( struct V_14 * V_14 )
{
int error ;
if ( ! ( V_14 -> V_16 . V_33 . V_68 & V_236 ) )
return 0 ;
switch ( V_14 -> V_16 . V_33 . type ) {
case V_72 :
if ( ! V_14 -> V_237 )
return 0 ;
V_14 -> V_167 . V_175 = 100 ;
V_14 -> V_167 . V_213 = 100 ;
error = F_88 ( V_14 , 1 , 4 , false ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_14 , error ) ;
return error ;
}
error = F_67 ( V_14 ,
& V_238 ) ;
break;
case V_239 :
case V_240 :
case V_120 :
case V_241 :
V_14 -> V_167 . V_175 = 10 ;
V_14 -> V_167 . V_185 = 20 ;
V_14 -> V_167 . V_213 = 127 ;
V_14 -> V_167 . V_211 = 127 ;
V_14 -> V_167 . V_186 = 10 ;
error = F_88 ( V_14 , 1 , 4 , false ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_14 , error ) ;
return error ;
}
error = F_67 ( V_14 ,
& V_242 ) ;
break;
case V_184 :
case V_183 :
V_14 -> V_167 . V_175 = 0 ;
V_14 -> V_167 . V_185 = 0 ;
V_14 -> V_167 . V_186 = 0 ;
error = F_88 ( V_14 , 2 , 4 , false ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_14 , error ) ;
return error ;
}
error = F_67 ( V_14 ,
& V_243 ) ;
break;
case V_177 :
case V_244 :
case V_245 :
case V_246 :
case V_247 :
case V_178 :
V_14 -> V_167 . V_175 = 32 ;
V_14 -> V_167 . V_213 = 96 ;
error = F_88 ( V_14 , 1 , 4 , false ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_14 , error ) ;
return error ;
}
error = F_67 ( V_14 ,
& V_248 ) ;
break;
case V_172 :
V_14 -> V_167 . V_175 = 50 ;
V_14 -> V_167 . V_213 = 100 ;
error = F_88 ( V_14 , 1 , 4 , false ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_14 , error ) ;
return error ;
}
return 0 ;
case V_249 :
V_14 -> V_167 . V_175 = 255 ;
V_14 -> V_167 . V_213 = 255 ;
error = F_87 ( V_14 , 5 ) ;
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
return 0 ;
}
static void F_90 ( struct V_250 * V_251 )
{
struct V_14 * V_14 = F_43 ( V_251 , struct V_14 , V_252 . V_251 ) ;
F_36 ( V_14 ) ;
F_53 ( V_14 ) ;
}
static void F_91 ( struct V_14 * V_14 )
{
F_92 ( & V_14 -> V_252 , F_93 ( 1000 ) ) ;
}
static int F_94 ( struct V_253 * V_254 ,
enum V_255 V_256 ,
union V_257 * V_258 )
{
struct V_259 * V_260 = F_95 ( V_254 ) ;
int V_37 = 0 ;
switch ( V_256 ) {
case V_261 :
V_258 -> V_262 = V_260 -> V_14 -> V_16 . V_207 ;
break;
case V_263 :
V_258 -> V_264 = V_260 -> V_265 ;
break;
case V_266 :
V_258 -> V_264 = V_267 ;
break;
case V_268 :
V_258 -> V_264 = V_260 -> V_269 ;
break;
case V_270 :
if ( V_260 -> V_271 )
V_258 -> V_264 = V_272 ;
else if ( V_260 -> V_269 == 100 &&
V_260 -> V_273 )
V_258 -> V_264 = V_274 ;
else if ( V_260 -> V_273 )
V_258 -> V_264 = V_275 ;
else
V_258 -> V_264 = V_276 ;
break;
default:
V_37 = - V_115 ;
break;
}
return V_37 ;
}
static int F_96 ( struct V_14 * V_14 ,
struct V_259 * V_260 )
{
static T_5 V_277 = F_97 ( 0 ) ;
struct V_193 * V_19 = & V_14 -> V_2 -> V_19 ;
struct V_278 V_279 = { . V_280 = V_260 , } ;
struct V_253 * V_281 ;
struct V_282 * V_283 = & V_260 -> V_283 ;
unsigned long V_38 ;
int error ;
if ( ! F_80 ( V_19 , V_283 , V_41 ) )
return - V_113 ;
V_260 -> V_14 = V_14 ;
V_38 = F_98 ( & V_277 ) - 1 ;
V_283 -> V_284 = V_285 ;
V_283 -> V_286 = F_99 ( V_285 ) ;
V_283 -> V_287 = F_94 ;
sprintf ( V_260 -> V_288 , L_16 , V_38 ) ;
V_283 -> V_207 = V_260 -> V_288 ;
V_283 -> type = V_289 ;
V_283 -> V_290 = 0 ;
V_281 = F_100 ( V_19 , V_283 , & V_279 ) ;
if ( F_101 ( V_281 ) ) {
error = F_102 ( V_281 ) ;
goto V_196;
}
F_103 ( V_281 , & V_14 -> V_2 -> V_19 ) ;
V_260 -> V_260 = V_281 ;
F_82 ( V_19 , V_283 ) ;
return 0 ;
V_196:
F_78 ( V_19 , V_283 ) ;
return error ;
}
static int F_104 ( struct V_14 * V_14 )
{
if ( V_14 -> V_16 . V_33 . V_291 & V_292 )
return F_96 ( V_14 , & V_14 -> V_260 ) ;
return 0 ;
}
static void F_105 ( struct V_14 * V_14 )
{
if ( V_14 -> V_260 . V_260 ) {
F_78 ( & V_14 -> V_2 -> V_19 ,
& V_14 -> V_260 . V_283 ) ;
V_14 -> V_260 . V_260 = NULL ;
}
}
static T_4 F_106 ( struct V_193 * V_19 ,
struct V_293
* V_294 , char * V_3 )
{
struct V_1 * V_2 = F_56 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
return snprintf ( V_3 , V_295 , L_17 , V_14 -> V_16 . V_119 ) ;
}
static T_4 F_107 ( struct V_193 * V_19 ,
struct V_293 * V_294 ,
const char * V_3 , T_2 V_195 )
{
struct V_1 * V_2 = F_56 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
T_1 V_296 ;
if ( F_108 ( V_3 , 0 , & V_296 ) )
return - V_115 ;
if ( V_296 != 0 && V_296 != 1 )
return - V_115 ;
F_35 ( V_2 , V_296 , & V_14 -> V_16 . V_33 ) ;
return V_195 ;
}
static T_4 F_109 ( struct V_203 * V_204 ,
struct V_297 * V_298 ,
char * V_3 , int V_299 )
{
struct V_193 * V_19 = F_110 ( V_204 -> V_300 ) ;
struct V_1 * V_2 = F_56 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
T_1 V_301 ;
V_301 = V_14 -> V_167 . V_168 [ V_299 ] . V_176 ;
if ( V_301 >= 0 && V_301 < 3 )
return snprintf ( V_3 , V_295 , L_18 , V_301 ) ;
else
return snprintf ( V_3 , V_295 , L_18 , - 1 ) ;
}
static int F_111 ( struct V_14 * V_14 , T_3 V_302 ,
int V_299 )
{
int error = 0 ;
struct V_303 * V_304 = V_14 -> V_304 ;
V_304 -> V_305 [ V_299 ] . V_206 . V_207 = F_73 ( & V_14 -> V_2 -> V_19 ,
V_41 ,
L_19 , V_302 ) ;
if ( ! V_304 -> V_305 [ V_299 ] . V_206 . V_207 )
return - V_113 ;
error = F_63 ( V_14 , V_304 -> V_306 ,
& V_304 -> V_305 [ V_299 ] . V_206 ) ;
if ( error ) {
V_304 -> V_305 [ V_299 ] . V_206 . V_207 = NULL ;
F_3 ( V_14 -> V_2 ,
L_15 , error ) ;
return error ;
}
return 0 ;
}
static int F_112 ( struct V_14 * V_14 , unsigned char V_307 )
{
const T_2 V_166 = 2 ;
unsigned char * V_3 ;
int V_6 ;
V_3 = F_17 ( V_166 , V_41 ) ;
if ( ! V_3 )
return - V_113 ;
V_3 [ 0 ] = V_308 ;
V_3 [ 1 ] = V_307 ;
V_6 = F_4 ( V_14 -> V_2 , V_309 , V_3 ,
V_166 , V_44 ) ;
F_19 ( V_3 ) ;
return V_6 ;
}
static T_4 F_113 ( struct V_203 * V_204 ,
struct V_297 * V_294 ,
const char * V_3 , T_2 V_195 )
{
unsigned char V_307 = 0 ;
struct V_193 * V_19 = F_110 ( V_204 -> V_300 ) ;
struct V_1 * V_2 = F_56 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
int V_196 ;
if ( ! strncmp ( V_3 , L_20 , 2 ) ) {
V_307 = V_310 ;
} else {
F_114 ( V_14 -> V_2 , L_21 ,
V_3 ) ;
return - 1 ;
}
F_44 ( & V_14 -> V_197 ) ;
V_196 = F_112 ( V_14 , V_307 ) ;
F_46 ( & V_14 -> V_197 ) ;
return V_196 < 0 ? V_196 : V_195 ;
}
static void F_115 ( void * V_17 )
{
struct V_14 * V_14 = V_17 ;
struct V_303 * V_304 = V_14 -> V_304 ;
if ( ! V_304 )
return;
F_116 ( V_304 -> V_306 ) ;
F_117 ( & V_304 -> V_311 ) ;
V_14 -> V_304 = NULL ;
}
static int F_118 ( struct V_14 * V_14 )
{
int error = 0 ;
struct V_303 * V_304 ;
int V_76 ;
if ( V_14 -> V_16 . V_33 . type != V_249 )
return 0 ;
V_304 = F_81 ( & V_14 -> V_2 -> V_19 , sizeof( * V_14 -> V_304 ) ,
V_41 ) ;
if ( ! V_304 )
return - V_113 ;
V_14 -> V_304 = V_304 ;
F_119 ( & V_304 -> V_312 ) ;
error = F_120 ( & V_304 -> V_311 ,
5 * sizeof( struct V_313 ) ,
V_41 ) ;
if ( error ) {
F_3 ( V_14 -> V_2 , L_22 ) ;
return - V_113 ;
}
V_304 -> V_305 [ 0 ] . V_206 = V_314 ;
V_304 -> V_305 [ 1 ] . V_206 = V_315 ;
V_304 -> V_305 [ 2 ] . V_206 = V_316 ;
V_304 -> V_305 [ 3 ] . V_206 = V_317 ;
V_304 -> V_305 [ 4 ] . V_206 = V_318 ;
V_304 -> V_306 = F_121 ( L_23 ,
& V_14 -> V_2 -> V_19 . V_204 ) ;
if ( ! V_304 -> V_306 )
return - V_113 ;
error = F_122 ( V_304 -> V_306 , V_319 ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_15 , error ) ;
return error ;
}
for ( V_76 = 0 ; V_76 < V_320 ; V_76 ++ ) {
V_14 -> V_167 . V_168 [ V_76 ] . V_176 = V_321 ;
V_304 -> V_305 [ V_76 ] . V_302 = 0 ;
}
error = F_83 ( & V_14 -> V_2 -> V_19 ,
F_115 , V_14 ) ;
if ( error )
return error ;
return 0 ;
}
static struct V_18 * F_123 ( struct V_14 * V_14 )
{
struct V_18 * V_18 ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
V_18 = F_124 ( & V_2 -> V_19 ) ;
if ( ! V_18 )
return NULL ;
V_18 -> V_207 = V_16 -> V_33 . V_207 ;
V_18 -> V_145 = V_2 -> V_145 ;
V_18 -> V_19 . V_300 = & V_2 -> V_19 ;
V_18 -> V_322 = F_8 ;
V_18 -> V_323 = F_11 ;
V_18 -> V_324 = V_2 -> V_324 ;
V_18 -> V_42 . V_325 = V_2 -> V_122 ;
V_18 -> V_42 . V_151 = V_2 -> V_151 ;
V_18 -> V_42 . V_153 = V_16 -> V_170 ? V_16 -> V_170 : V_2 -> V_153 ;
V_18 -> V_42 . V_326 = V_2 -> V_326 ;
F_125 ( V_18 , V_14 ) ;
return V_18 ;
}
static int F_126 ( struct V_14 * V_14 )
{
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
V_16 -> V_327 = F_123 ( V_14 ) ;
V_16 -> V_97 = F_123 ( V_14 ) ;
V_16 -> V_235 = F_123 ( V_14 ) ;
if ( ! V_16 -> V_327 ||
! V_16 -> V_97 ||
! V_16 -> V_235 )
return - V_113 ;
V_16 -> V_327 -> V_207 = V_16 -> V_328 ;
V_16 -> V_97 -> V_207 = V_16 -> V_329 ;
V_16 -> V_235 -> V_207 = V_16 -> V_330 ;
return 0 ;
}
static int F_127 ( struct V_14 * V_14 )
{
struct V_18 * V_331 , * V_332 , * V_333 ;
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
int error = 0 ;
V_331 = V_16 -> V_327 ;
V_332 = V_16 -> V_97 ;
V_333 = V_16 -> V_235 ;
if ( ! V_331 || ! V_332 || ! V_333 )
return - V_115 ;
error = F_128 ( V_331 , V_16 ) ;
if ( error ) {
F_129 ( V_331 ) ;
V_16 -> V_327 = NULL ;
V_331 = NULL ;
} else {
error = F_130 ( V_331 ) ;
if ( error )
goto V_334;
}
error = F_131 ( V_332 , V_16 ) ;
if ( error ) {
F_129 ( V_332 ) ;
V_16 -> V_97 = NULL ;
V_332 = NULL ;
} else {
error = F_130 ( V_332 ) ;
if ( error )
goto V_334;
}
error = F_132 ( V_333 , V_16 ) ;
if ( error ) {
F_129 ( V_333 ) ;
V_16 -> V_235 = NULL ;
V_333 = NULL ;
} else {
error = F_130 ( V_333 ) ;
if ( error )
goto V_334;
}
return 0 ;
V_334:
V_16 -> V_235 = NULL ;
V_16 -> V_97 = NULL ;
V_16 -> V_327 = NULL ;
return error ;
}
static void F_133 ( struct V_32 * V_33 )
{
if ( V_33 -> V_335 ) {
V_33 -> V_86 = ( V_33 -> V_85 * 100 ) /
V_33 -> V_335 ;
V_33 -> V_91 = ( V_33 -> V_90 * 100 ) /
V_33 -> V_336 ;
}
}
static void F_134 ( struct V_32 * V_33 )
{
if ( ! V_33 -> V_22 ) {
V_33 -> V_22 = 0x11 ;
V_33 -> V_88 = - 3 ;
}
V_33 -> V_335 = F_13 ( V_33 -> V_85 ,
V_33 -> V_86 ,
V_33 -> V_22 ,
V_33 -> V_88 ) ;
V_33 -> V_336 = F_13 ( V_33 -> V_90 ,
V_33 -> V_91 ,
V_33 -> V_22 ,
V_33 -> V_88 ) ;
}
void F_135 ( struct V_250 * V_251 )
{
struct V_14 * V_14 = F_43 ( V_251 , struct V_14 , V_337 ) ;
if ( ( V_14 -> V_16 . V_33 . V_291 & V_292 ) &&
! V_14 -> V_260 . V_260 ) {
F_104 ( V_14 ) ;
}
else if ( ! ( V_14 -> V_16 . V_33 . V_291 & V_292 ) &&
V_14 -> V_260 . V_260 ) {
F_105 ( V_14 ) ;
}
}
static T_2 F_136 ( struct V_1 * V_2 )
{
struct V_100 * V_104 ;
struct V_11 * V_12 ;
T_2 V_4 = 0 ;
V_104 = V_2 -> V_104 + V_106 ;
F_31 (report, &report_enum->report_list, list) {
T_2 V_338 = F_21 ( V_12 ) ;
if ( V_338 > V_4 )
V_4 = V_338 ;
}
return V_4 ;
}
static void F_137 ( struct V_14 * V_14 , const char * V_339 )
{
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_32 * V_33 = & V_16 -> V_33 ;
char V_207 [ V_340 ] ;
if ( ( V_33 -> type == V_72 ) && ! strcmp ( L_24 , V_33 -> V_207 ) ) {
if ( strstr ( V_14 -> V_2 -> V_207 , L_25 ) ||
strstr ( V_14 -> V_2 -> V_207 , L_26 ) ||
strstr ( V_14 -> V_2 -> V_207 , L_27 ) ) {
F_138 ( V_207 , V_14 -> V_2 -> V_207 , sizeof( V_207 ) ) ;
while ( 1 ) {
char * V_341 = strstr ( V_207 , L_28 ) ;
if ( V_341 == NULL )
break;
memmove ( V_341 , V_341 + 1 , strlen ( V_341 ) ) ;
}
if ( strstr ( V_207 , L_29 ) == V_207 ) {
int V_38 = strlen ( V_207 ) ;
int V_342 = strlen ( L_30 ) ;
memmove ( V_207 , V_207 + V_342 , V_38 - V_342 + 1 ) ;
}
if ( strstr ( V_207 , L_31 ) == V_207 ) {
int V_38 = strlen ( V_207 ) ;
int V_342 = strlen ( L_32 ) ;
memmove ( V_207 , V_207 + V_342 , V_38 - V_342 + 1 ) ;
}
if ( V_207 [ strlen ( V_207 ) - 1 ] == ' ' )
V_207 [ strlen ( V_207 ) - 1 ] = '\0' ;
} else {
snprintf ( V_207 , sizeof( V_207 ) ,
L_33 , V_33 -> V_207 , V_14 -> V_2 -> V_153 ) ;
}
} else {
F_138 ( V_207 , V_33 -> V_207 , sizeof( V_207 ) ) ;
}
snprintf ( V_16 -> V_207 , sizeof( V_16 -> V_207 ) , L_34 ,
V_207 , V_339 ) ;
snprintf ( V_16 -> V_328 , sizeof( V_16 -> V_328 ) ,
L_35 , V_207 , V_339 ) ;
snprintf ( V_16 -> V_329 , sizeof( V_16 -> V_329 ) ,
L_36 , V_207 , V_339 ) ;
snprintf ( V_16 -> V_330 , sizeof( V_16 -> V_330 ) ,
L_37 , V_207 , V_339 ) ;
}
static void F_139 ( struct V_14 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
if ( ! V_14 -> V_343 )
return;
F_78 ( & V_2 -> V_19 , V_14 ) ;
V_14 -> V_343 = false ;
V_14 -> V_16 . V_327 = NULL ;
V_14 -> V_16 . V_97 = NULL ;
V_14 -> V_16 . V_235 = NULL ;
}
static void F_140 ( struct V_16 * V_16 )
{
if ( V_16 -> V_33 . V_68 & V_70 ) {
V_16 -> V_160 -> type = V_16 -> V_33 . type ;
V_16 -> V_160 -> V_97 = V_16 -> V_97 ;
}
if ( V_16 -> V_344 ) {
V_16 -> V_160 -> V_344 = true ;
V_16 -> V_160 -> V_345 = true ;
}
if ( V_16 -> V_160 -> V_344 &&
V_16 -> V_160 -> V_97 ) {
F_141 ( V_346 , V_16 -> V_160 -> V_97 -> V_347 ) ;
F_142 ( V_16 -> V_160 -> V_97 , V_346 ,
V_348 ) ;
}
}
static int F_143 ( struct V_14 * V_14 , bool V_349 )
{
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_32 * V_33 = & V_16 -> V_33 ;
struct V_1 * V_2 = V_14 -> V_2 ;
int error ;
unsigned int V_350 = V_351 ;
V_33 -> V_352 = F_136 ( V_2 ) ;
if ( V_33 -> V_352 > V_15 )
return - V_115 ;
if ( ! F_80 ( & V_2 -> V_19 , V_14 , V_41 ) )
return - V_113 ;
V_14 -> V_343 = true ;
error = F_126 ( V_14 ) ;
if ( error )
goto V_334;
if ( V_33 -> type == V_127 ) {
if ( V_33 -> V_352 == V_353 ) {
V_33 -> type = V_72 ;
} else if ( ( V_33 -> V_352 != V_354 ) &&
( V_33 -> V_352 != V_355 ) ) {
error = - V_356 ;
goto V_334;
}
}
F_133 ( V_33 ) ;
F_37 ( V_2 , V_33 ) ;
F_144 ( V_14 ) ;
if ( V_33 -> V_68 == V_140 &&
V_33 -> type != V_135 ) {
error = V_33 -> type == V_72 ? - V_356 : 0 ;
F_145 ( & V_2 -> V_19 , L_38 ,
V_2 -> V_207 ,
error ? L_39 : L_40 ) ;
if ( error )
goto V_334;
V_33 -> V_68 |= V_69 ;
}
F_134 ( V_33 ) ;
F_137 ( V_14 , V_349 ? L_41 : L_42 ) ;
if ( ( V_33 -> type == V_357 ) &&
( ( V_33 -> V_68 & V_70 ) ||
( V_33 -> V_68 & V_236 ) ) ) {
error = - V_356 ;
goto V_334;
}
error = F_49 ( V_2 ) ;
if ( error )
goto V_334;
if ( ! ( V_33 -> V_68 & V_139 ) &&
( V_33 -> V_291 & V_292 ) ) {
error = F_104 ( V_14 ) ;
if ( error )
goto V_334;
}
error = F_127 ( V_14 ) ;
if ( error )
goto V_334;
if ( V_14 -> V_16 . V_33 . V_68 & V_236 ) {
error = F_89 ( V_14 ) ;
if ( error )
goto V_334;
error = F_118 ( V_14 ) ;
if ( error )
goto V_334;
}
if ( V_33 -> type == V_72 )
V_350 |= V_358 ;
error = F_146 ( V_2 , V_350 ) ;
if ( error ) {
F_3 ( V_2 , L_43 ) ;
goto V_334;
}
if ( ! V_349 ) {
F_91 ( V_14 ) ;
}
if ( ( V_33 -> type == V_87 ) &&
( V_33 -> V_68 & V_69 ) ) {
F_147 ( & V_14 -> V_252 ) ;
F_36 ( V_14 ) ;
error = - V_356 ;
goto V_359;
}
if ( V_33 -> V_68 & V_139 )
error = F_10 ( V_2 ) ;
F_140 ( V_16 ) ;
F_82 ( & V_2 -> V_19 , V_14 ) ;
return 0 ;
V_359:
F_148 ( V_2 ) ;
V_334:
F_139 ( V_14 ) ;
return error ;
}
static void F_149 ( struct V_250 * V_251 )
{
struct V_14 * V_14 = F_43 ( V_251 , struct V_14 , V_360 ) ;
struct V_361 * V_362 = V_14 -> V_362 ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_1 * V_363 , * V_364 ;
struct V_14 * V_365 , * V_366 ;
struct V_16 * V_367 , * V_368 ;
int error ;
F_105 ( V_14 ) ;
V_363 = F_150 ( V_362 -> V_369 -> V_370 [ 1 ] ) ;
V_365 = F_6 ( V_363 ) ;
V_367 = & ( V_365 -> V_16 ) ;
F_139 ( V_365 ) ;
V_364 = F_150 ( V_362 -> V_369 -> V_370 [ 2 ] ) ;
V_366 = F_6 ( V_364 ) ;
V_368 = & ( V_366 -> V_16 ) ;
F_139 ( V_366 ) ;
if ( V_16 -> V_170 == 0 ) {
F_114 ( V_14 -> V_2 , L_44 ) ;
} else {
const struct V_371 * V_42 = V_372 ;
F_114 ( V_14 -> V_2 , L_45 ,
V_16 -> V_170 ) ;
while ( V_42 -> V_122 ) {
if ( V_42 -> V_151 == V_373 &&
V_42 -> V_153 == V_16 -> V_170 )
break;
V_42 ++ ;
}
if ( ! V_42 -> V_122 ) {
F_114 ( V_14 -> V_2 , L_46 ) ;
return;
}
V_367 -> V_33 =
* ( (struct V_32 * ) V_42 -> V_374 ) ;
V_367 -> V_170 = V_16 -> V_170 ;
F_148 ( V_363 ) ;
error = F_143 ( V_365 , true ) ;
if ( error )
goto V_334;
if ( V_367 -> V_33 . V_40 ||
( V_367 -> V_33 . type >= V_375 &&
V_367 -> V_33 . type <= V_71 ) ) {
V_368 -> V_33 =
* ( (struct V_32 * ) V_42 -> V_374 ) ;
V_368 -> V_170 = V_16 -> V_170 ;
F_148 ( V_364 ) ;
error = F_143 ( V_366 , true ) ;
if ( error )
goto V_334;
}
F_138 ( V_16 -> V_207 , V_367 -> V_207 ,
sizeof( V_16 -> V_207 ) ) ;
error = F_104 ( V_14 ) ;
if ( error )
goto V_334;
}
return;
V_334:
F_139 ( V_365 ) ;
F_139 ( V_366 ) ;
return;
}
static void F_151 ( struct V_14 * V_14 , unsigned int V_299 )
{
struct V_303 * V_304 = V_14 -> V_304 ;
T_6 V_302 = V_304 -> V_305 [ V_299 ] . V_302 ;
int V_76 ;
unsigned long V_221 ;
F_152 ( & V_304 -> V_312 , V_221 ) ;
V_304 -> V_305 [ V_299 ] . V_376 = false ;
F_153 ( & V_304 -> V_312 , V_221 ) ;
if ( V_304 -> V_305 [ V_299 ] . V_260 . V_260 )
F_78 ( & V_14 -> V_2 -> V_19 ,
& V_304 -> V_305 [ V_299 ] . V_260 . V_283 ) ;
if ( V_304 -> V_305 [ V_299 ] . V_206 . V_207 )
F_78 ( & V_14 -> V_2 -> V_19 ,
& V_304 -> V_305 [ V_299 ] ) ;
for ( V_76 = 0 ; V_76 < V_320 ; V_76 ++ ) {
if ( V_304 -> V_305 [ V_76 ] . V_302 == V_302 ) {
V_304 -> V_305 [ V_76 ] . V_302 = 0 ;
V_304 -> V_305 [ V_76 ] . V_206 . V_207 = NULL ;
V_304 -> V_305 [ V_76 ] . V_376 = false ;
V_304 -> V_305 [ V_76 ] . V_260 . V_260 = NULL ;
V_14 -> V_167 . V_168 [ V_76 ] . V_176 = V_321 ;
}
}
}
static int F_154 ( struct V_14 * V_14 , T_6 V_302 ,
unsigned int V_299 )
{
struct V_303 * V_304 = V_14 -> V_304 ;
struct V_193 * V_19 = & V_14 -> V_2 -> V_19 ;
int error , V_377 ;
for ( V_377 = 0 ; V_377 < V_320 ; V_377 ++ ) {
if ( V_304 -> V_305 [ V_377 ] . V_302 == V_302 )
break;
}
if ( V_377 < V_320 ) {
V_304 -> V_305 [ V_299 ] . V_302 = V_302 ;
return 0 ;
}
if ( ! F_80 ( V_19 , & V_304 -> V_305 [ V_299 ] , V_41 ) )
return - V_113 ;
error = F_111 ( V_14 , V_302 , V_299 ) ;
if ( error )
goto V_334;
V_304 -> V_305 [ V_299 ] . V_378 = F_123 ( V_14 ) ;
if ( ! V_304 -> V_305 [ V_299 ] . V_378 ) {
error = - V_113 ;
goto V_334;
}
V_304 -> V_305 [ V_299 ] . V_378 -> V_324 = V_304 -> V_305 [ V_299 ] . V_206 . V_207 ;
V_304 -> V_305 [ V_299 ] . V_378 -> V_207 = V_14 -> V_16 . V_330 ;
if ( ! V_304 -> V_305 [ V_299 ] . V_378 -> V_207 ) {
error = - V_115 ;
goto V_334;
}
error = F_132 ( V_304 -> V_305 [ V_299 ] . V_378 ,
& V_14 -> V_16 ) ;
if ( error )
goto V_334;
V_304 -> V_305 [ V_299 ] . V_302 = V_302 ;
error = F_130 ( V_304 -> V_305 [ V_299 ] . V_378 ) ;
if ( error )
goto V_334;
error = F_79 (
& V_304 -> V_305 [ V_299 ] . V_378 -> V_19 ,
V_14 , V_299 , 3 , true ) ;
if ( error )
goto V_334;
V_304 -> V_305 [ V_299 ] . V_376 = true ;
F_82 ( V_19 , & V_304 -> V_305 [ V_299 ] ) ;
return 0 ;
V_334:
F_78 ( V_19 , & V_304 -> V_305 [ V_299 ] ) ;
V_304 -> V_305 [ V_299 ] . V_302 = 0 ;
return error ;
}
static int F_155 ( struct V_14 * V_14 , int V_299 )
{
struct V_303 * V_304 = V_14 -> V_304 ;
int error ;
if ( ! V_304 -> V_305 [ V_299 ] . V_376 )
return 0 ;
if ( V_304 -> V_305 [ V_299 ] . V_260 . V_260 )
return 0 ;
if ( V_14 -> V_167 . V_168 [ V_299 ] . V_176 == V_321 )
return 0 ;
error = F_96 ( V_14 ,
& V_14 -> V_304 -> V_305 [ V_299 ] . V_260 ) ;
if ( error )
return error ;
return 0 ;
}
static void F_156 ( struct V_250 * V_251 )
{
struct V_14 * V_14 = F_43 ( V_251 , struct V_14 , V_379 ) ;
struct V_303 * V_304 = V_14 -> V_304 ;
struct V_313 V_17 ;
unsigned long V_221 ;
unsigned int V_195 ;
T_6 V_302 ;
int V_76 ;
F_152 ( & V_304 -> V_312 , V_221 ) ;
V_195 = F_157 ( & V_304 -> V_311 , & V_17 , sizeof( V_17 ) ) ;
if ( V_195 != sizeof( V_17 ) ) {
F_3 ( V_14 -> V_2 ,
L_47 ) ;
F_153 ( & V_304 -> V_312 , V_221 ) ;
return;
}
if ( ! F_158 ( & V_304 -> V_311 ) )
F_159 ( & V_14 -> V_16 , V_380 ) ;
F_153 ( & V_304 -> V_312 , V_221 ) ;
for ( V_76 = 0 ; V_76 < V_320 ; V_76 ++ ) {
V_302 = V_17 . V_304 [ V_76 ] . V_302 ;
if ( V_17 . V_304 [ V_76 ] . V_381 ) {
if ( V_304 -> V_305 [ V_76 ] . V_302 == V_302 ) {
F_155 ( V_14 , V_76 ) ;
continue;
}
if ( V_304 -> V_305 [ V_76 ] . V_302 )
F_151 ( V_14 , V_76 ) ;
F_154 ( V_14 , V_302 , V_76 ) ;
} else if ( V_304 -> V_305 [ V_76 ] . V_302 ) {
F_151 ( V_14 , V_76 ) ;
}
}
}
static void F_160 ( struct V_250 * V_251 )
{
struct V_14 * V_14 = F_43 ( V_251 , struct V_14 , V_382 ) ;
struct V_383 * V_160 = V_14 -> V_16 . V_160 ;
struct V_14 * V_365 = NULL ;
struct V_14 * V_366 = NULL ;
bool V_384 = V_14 -> V_16 . V_95 ;
int error = 0 ;
if ( V_160 -> V_67 ) {
V_365 = F_6 ( V_160 -> V_67 ) ;
F_139 ( V_365 ) ;
F_148 ( V_365 -> V_2 ) ;
V_365 -> V_16 . V_94 = true ;
V_365 -> V_16 . V_95 = V_384 ;
}
if ( V_160 -> V_161 ) {
V_366 = F_6 ( V_160 -> V_161 ) ;
F_139 ( V_366 ) ;
F_148 ( V_366 -> V_2 ) ;
V_366 -> V_16 . V_94 = true ;
V_366 -> V_16 . V_95 = V_384 ;
}
if ( V_365 ) {
error = F_143 ( V_365 , false ) ;
if ( error )
return;
}
if ( V_366 ) {
error = F_143 ( V_366 , false ) ;
if ( error )
return;
}
return;
}
static int F_161 ( struct V_1 * V_2 ,
const struct V_371 * V_42 )
{
struct V_128 * V_129 = F_162 ( V_2 -> V_19 . V_300 ) ;
struct V_361 * V_19 = F_163 ( V_129 ) ;
struct V_14 * V_14 ;
struct V_16 * V_16 ;
struct V_32 * V_33 ;
int error ;
if ( ! V_42 -> V_374 )
return - V_115 ;
V_2 -> V_291 |= V_385 ;
V_2 -> V_291 &= ~ V_386 ;
V_14 = F_81 ( & V_2 -> V_19 , sizeof( struct V_14 ) , V_41 ) ;
if ( ! V_14 )
return - V_113 ;
F_164 ( V_2 , V_14 ) ;
V_14 -> V_2 = V_2 ;
V_16 = & V_14 -> V_16 ;
V_16 -> V_33 = * ( (struct V_32 * ) V_42 -> V_374 ) ;
V_33 = & V_16 -> V_33 ;
if ( V_33 -> V_387 && V_33 -> V_388 != V_2 -> type ) {
error = - V_356 ;
goto V_334;
}
V_16 -> V_34 . V_48 = - 1 ;
V_16 -> V_54 = - 1 ;
V_14 -> V_362 = V_19 ;
V_14 -> V_129 = V_129 ;
F_165 ( & V_14 -> V_197 ) ;
F_166 ( & V_14 -> V_252 , F_90 ) ;
F_167 ( & V_14 -> V_360 , F_149 ) ;
F_167 ( & V_14 -> V_337 , F_135 ) ;
F_167 ( & V_14 -> V_379 , F_156 ) ;
F_167 ( & V_14 -> V_382 , F_160 ) ;
error = F_168 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_48 ) ;
goto V_334;
}
error = F_143 ( V_14 , false ) ;
if ( error )
goto V_334;
if ( V_2 -> V_122 == V_123 ) {
error = F_169 ( & V_2 -> V_19 , & V_389 ) ;
if ( error )
F_18 ( V_2 ,
L_49 ,
error ) ;
}
return 0 ;
V_334:
F_164 ( V_2 , NULL ) ;
return error ;
}
static void F_170 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_32 * V_33 = & V_16 -> V_33 ;
if ( V_33 -> V_68 & V_139 )
F_12 ( V_2 ) ;
F_148 ( V_2 ) ;
F_147 ( & V_14 -> V_252 ) ;
F_171 ( & V_14 -> V_360 ) ;
F_171 ( & V_14 -> V_337 ) ;
F_171 ( & V_14 -> V_379 ) ;
F_171 ( & V_14 -> V_382 ) ;
if ( V_2 -> V_122 == V_123 )
F_172 ( & V_2 -> V_19 , & V_389 ) ;
F_86 ( V_14 ) ;
if ( V_14 -> V_16 . V_33 . type != V_249 )
F_139 ( V_14 ) ;
F_164 ( V_2 , NULL ) ;
}
static int F_173 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
F_44 ( & V_14 -> V_197 ) ;
F_36 ( V_14 ) ;
F_53 ( V_14 ) ;
F_46 ( & V_14 -> V_197 ) ;
return 0 ;
}
static int F_174 ( struct V_1 * V_2 )
{
return F_173 ( V_2 ) ;
}
