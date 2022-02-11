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
if ( F_38 ( V_2 , V_17 -> V_19 , '/' ) ) {
F_41 ( & V_17 -> V_156 ) ;
return V_17 ;
}
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
if ( V_14 -> V_16 . V_33 . type == V_170 )
return - V_169 ;
if ( V_14 -> V_16 . V_171 ) {
V_164 = V_172 ;
V_166 = 13 ;
}
else if ( V_14 -> V_16 . V_33 . type == V_173 ) {
V_164 = V_174 ;
V_166 = 51 ;
}
V_3 = F_17 ( V_166 , V_41 ) ;
if ( ! V_3 )
return - V_113 ;
if ( V_14 -> V_16 . V_33 . type == V_72 ) {
V_3 [ 0 ] = V_175 ;
V_3 [ 1 ] = V_14 -> V_167 . V_176 ;
V_3 [ 2 ] = V_14 -> V_167 . V_168 [ 0 ] . V_177 & 0x03 ;
} else if ( ( V_14 -> V_16 . V_33 . type >= V_178 &&
V_14 -> V_16 . V_33 . type <= V_179 ) ) {
int V_180 = V_14 -> V_167 . V_168 [ 0 ] . V_177 & 0x03 ;
int V_181 = ( ( ( V_14 -> V_167 . V_176 & 0x60 ) >> 5 ) - 1 ) & 0x03 ;
int V_182 = 0 ;
unsigned char V_183 = ( V_182 << 4 ) | ( V_181 << 2 ) | ( V_180 ) ;
V_3 [ 0 ] = V_164 ;
if ( V_14 -> V_16 . V_171 ) {
F_1 ( V_14 -> V_2 , V_43 ,
V_3 , V_166 , V_44 ) ;
V_3 [ 0 ] = V_164 ;
V_3 [ 4 ] = V_183 ;
} else
V_3 [ 1 ] = V_183 ;
}
else if ( V_14 -> V_16 . V_33 . type == V_173 ) {
V_3 [ 0 ] = V_164 ;
V_3 [ 4 ] = 100 ;
V_3 [ 5 ] = 100 ;
V_3 [ 6 ] = 100 ;
V_3 [ 7 ] = 100 ;
V_3 [ 8 ] = 100 ;
V_3 [ 9 ] = V_14 -> V_167 . V_176 ;
V_3 [ 10 ] = V_14 -> V_167 . V_168 [ 0 ] . V_177 & 0x03 ;
}
else {
int V_167 = V_14 -> V_167 . V_168 [ 0 ] . V_177 | 0x4 ;
if ( V_14 -> V_16 . V_33 . type == V_184 ||
V_14 -> V_16 . V_33 . type == V_185 )
V_167 |= ( V_14 -> V_167 . V_168 [ 1 ] . V_177 << 4 ) | 0x40 ;
V_3 [ 0 ] = V_164 ;
V_3 [ 1 ] = V_167 ;
V_3 [ 2 ] = V_14 -> V_167 . V_176 ;
V_3 [ 3 ] = V_14 -> V_167 . V_186 ;
V_3 [ 4 ] = V_14 -> V_167 . V_187 ;
}
V_6 = F_4 ( V_14 -> V_2 , V_43 , V_3 , V_166 ,
V_44 ) ;
F_19 ( V_3 ) ;
return V_6 ;
}
static int F_54 ( struct V_14 * V_14 , int V_188 , T_1 V_189 ,
const unsigned V_190 , const void * V_191 )
{
unsigned char * V_3 ;
int V_76 , V_6 ;
const unsigned V_192 = V_190 / 4 ;
V_3 = F_17 ( V_192 + 3 , V_41 ) ;
if ( ! V_3 )
return - V_113 ;
V_3 [ 0 ] = V_193 ;
V_3 [ 1 ] = 1 ;
V_6 = F_4 ( V_14 -> V_2 , V_43 , V_3 , 2 ,
V_44 ) ;
if ( V_6 < 0 )
goto V_162;
V_3 [ 0 ] = V_189 ;
V_3 [ 1 ] = V_188 & 0x07 ;
for ( V_76 = 0 ; V_76 < 4 ; V_76 ++ ) {
V_3 [ 2 ] = V_76 ;
memcpy ( V_3 + 3 , V_191 + V_76 * V_192 , V_192 ) ;
V_6 = F_4 ( V_14 -> V_2 , V_43 ,
V_3 , V_192 + 3 , V_44 ) ;
if ( V_6 < 0 )
break;
}
V_3 [ 0 ] = V_193 ;
V_3 [ 1 ] = 0 ;
F_4 ( V_14 -> V_2 , V_43 , V_3 , 2 ,
V_44 ) ;
V_162:
F_19 ( V_3 ) ;
return V_6 ;
}
static T_4 F_55 ( struct V_194 * V_19 , int V_195 ,
const char * V_3 , T_2 V_196 )
{
struct V_1 * V_2 = F_56 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
unsigned int V_42 ;
int V_197 ;
V_197 = F_57 ( V_3 , 10 , & V_42 ) ;
if ( V_197 )
return V_197 ;
F_44 ( & V_14 -> V_198 ) ;
V_14 -> V_167 . V_168 [ V_195 ] . V_177 = V_42 & 0x3 ;
V_197 = F_53 ( V_14 ) ;
F_46 ( & V_14 -> V_198 ) ;
return V_197 < 0 ? V_197 : V_196 ;
}
static T_4 F_58 ( struct V_14 * V_14 , T_1 * V_199 ,
const char * V_3 , T_2 V_196 )
{
unsigned int V_110 ;
int V_197 ;
V_197 = F_57 ( V_3 , 10 , & V_110 ) ;
if ( V_197 )
return V_197 ;
F_44 ( & V_14 -> V_198 ) ;
* V_199 = V_110 & 0x7f ;
V_197 = F_53 ( V_14 ) ;
F_46 ( & V_14 -> V_198 ) ;
return V_197 < 0 ? V_197 : V_196 ;
}
static T_4 F_59 ( struct V_194 * V_19 , int V_188 ,
const char * V_3 , T_2 V_196 )
{
struct V_1 * V_2 = F_56 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
int V_197 ;
unsigned V_190 ;
T_1 V_189 ;
if ( V_2 -> V_122 == V_123 ) {
V_190 = 256 ;
V_189 = V_200 ;
} else {
V_190 = 1024 ;
V_189 = V_201 ;
}
if ( V_196 != V_190 )
return - V_115 ;
F_44 ( & V_14 -> V_198 ) ;
V_197 = F_54 ( V_14 , V_188 , V_189 , V_190 , V_3 ) ;
F_46 ( & V_14 -> V_198 ) ;
return V_197 < 0 ? V_197 : V_196 ;
}
static void F_60 ( struct V_194 * V_19 , void * V_159 )
{
struct V_202 * V_203 = V_159 ;
struct V_204 * V_205 = V_203 -> V_206 ;
F_61 ( V_19 , L_10 ,
V_65 , V_203 -> V_207 -> V_208 ) ;
F_62 ( V_205 , V_203 -> V_207 ) ;
}
static int F_63 ( struct V_14 * V_14 ,
struct V_204 * V_206 ,
struct V_209 * V_207 )
{
struct V_202 * V_203 ;
int error ;
V_203 = F_64 ( F_60 ,
sizeof( struct V_202 ) ,
V_41 ) ;
if ( ! V_203 )
return - V_113 ;
V_203 -> V_207 = V_207 ;
V_203 -> V_206 = V_206 ;
error = F_65 ( V_203 -> V_206 , V_207 ) ;
if ( error )
return error ;
F_66 ( & V_14 -> V_2 -> V_19 , V_203 ) ;
return 0 ;
}
static int F_67 ( struct V_14 * V_14 ,
struct V_209 * V_207 )
{
return F_63 ( V_14 , & V_14 -> V_2 -> V_19 . V_205 ,
V_207 ) ;
}
enum V_210 F_68 ( struct V_211 * V_167 )
{
struct V_14 * V_14 = V_167 -> V_14 ;
if ( V_14 -> V_167 . V_212 )
return V_167 -> V_186 * V_213 / V_14 -> V_167 . V_212 ;
if ( V_14 -> V_167 . V_214 )
return V_167 -> V_176 * V_213 / V_14 -> V_167 . V_214 ;
return V_213 ;
}
static enum V_210 F_69 ( struct V_215 * V_216 )
{
struct V_211 * V_167 = F_43 ( V_216 , struct V_211 , V_216 ) ;
struct V_14 * V_14 = V_167 -> V_14 ;
if ( V_14 -> V_167 . V_168 [ V_167 -> V_207 ] . V_177 != V_167 -> V_42 )
return V_217 ;
return F_68 ( V_167 ) ;
}
static int F_70 ( struct V_215 * V_216 ,
enum V_210 V_218 )
{
struct V_211 * V_167 = F_43 ( V_216 , struct V_211 , V_216 ) ;
struct V_14 * V_14 = V_167 -> V_14 ;
int error ;
F_44 ( & V_14 -> V_198 ) ;
if ( ! V_14 -> V_167 . V_168 || ( V_218 == V_217 &&
V_14 -> V_167 . V_168 [ V_167 -> V_207 ] . V_177 != V_167 -> V_42 ) ) {
error = 0 ;
goto V_162;
}
V_167 -> V_176 = V_14 -> V_167 . V_176 = V_14 -> V_167 . V_214 * V_218 / V_213 ;
V_167 -> V_186 = V_14 -> V_167 . V_186 = V_14 -> V_167 . V_212 * V_218 / V_213 ;
V_14 -> V_167 . V_168 [ V_167 -> V_207 ] . V_177 = V_167 -> V_42 ;
error = F_53 ( V_14 ) ;
V_162:
F_46 ( & V_14 -> V_198 ) ;
return error ;
}
static void F_71 ( struct V_215 * V_216 ,
enum V_210 V_218 )
{
}
static int F_72 ( struct V_194 * V_19 , struct V_14 * V_14 ,
struct V_211 * V_167 , unsigned int V_207 ,
unsigned int V_42 , bool V_219 )
{
int error ;
char * V_208 ;
V_208 = F_73 ( V_19 , V_41 ,
L_11 ,
F_74 ( V_19 ) ,
V_207 ,
V_42 ) ;
if ( ! V_208 )
return - V_113 ;
if ( ! V_219 ) {
V_167 -> V_220 . V_208 = V_208 ;
error = F_75 ( V_19 , & V_167 -> V_220 ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_12 ,
V_167 -> V_216 . V_208 , error ) ;
return error ;
}
}
V_167 -> V_207 = V_207 ;
V_167 -> V_42 = V_42 ;
V_167 -> V_14 = V_14 ;
V_167 -> V_176 = V_14 -> V_167 . V_176 ;
V_167 -> V_186 = V_14 -> V_167 . V_186 ;
V_167 -> V_216 . V_208 = V_208 ;
V_167 -> V_216 . V_221 = V_213 ;
V_167 -> V_216 . V_222 = V_223 ;
V_167 -> V_216 . V_224 = F_69 ;
if ( ! V_219 ) {
V_167 -> V_216 . V_225 = F_70 ;
V_167 -> V_216 . V_226 = V_167 -> V_216 . V_208 ;
} else {
V_167 -> V_216 . V_227 = F_71 ;
}
error = F_76 ( V_19 , & V_167 -> V_216 ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_13 ,
V_167 -> V_216 . V_208 , error ) ;
V_167 -> V_216 . V_208 = NULL ;
return error ;
}
return 0 ;
}
static void F_77 ( void * V_17 )
{
struct V_228 * V_207 = V_17 ;
F_78 ( V_207 -> V_19 , V_207 ) ;
}
static int F_79 ( struct V_194 * V_19 ,
struct V_14 * V_14 ,
int V_229 , int V_196 ,
bool V_219 )
{
struct V_211 * V_230 ;
int V_76 , error ;
if ( V_229 >= V_14 -> V_167 . V_196 || V_196 <= 0 )
return - V_115 ;
if ( ! F_80 ( V_19 , & V_14 -> V_167 . V_168 [ V_229 ] , V_41 ) )
return - V_113 ;
V_230 = F_81 ( V_19 , sizeof( struct V_211 ) * V_196 , V_41 ) ;
if ( ! V_230 ) {
error = - V_113 ;
goto V_197;
}
V_14 -> V_167 . V_168 [ V_229 ] . V_230 = V_230 ;
V_14 -> V_167 . V_168 [ V_229 ] . V_196 = V_196 ;
for ( V_76 = 0 ; V_76 < V_196 ; V_76 ++ ) {
error = F_72 ( V_19 , V_14 , & V_230 [ V_76 ] ,
V_229 , V_76 , V_219 ) ;
if ( error )
goto V_197;
}
V_14 -> V_167 . V_168 [ V_229 ] . V_19 = V_19 ;
F_82 ( V_19 , & V_14 -> V_167 . V_168 [ V_229 ] ) ;
error = F_83 ( & V_14 -> V_2 -> V_19 ,
F_77 ,
& V_14 -> V_167 . V_168 [ V_229 ] ) ;
if ( error )
return error ;
return 0 ;
V_197:
F_78 ( V_19 , & V_14 -> V_167 . V_168 [ V_229 ] ) ;
return error ;
}
struct V_211 * F_84 ( struct V_14 * V_14 , unsigned int V_229 ,
unsigned int V_42 )
{
struct V_228 * V_207 ;
if ( V_229 >= V_14 -> V_167 . V_196 )
return NULL ;
V_207 = & V_14 -> V_167 . V_168 [ V_229 ] ;
if ( ! V_207 -> V_230 )
return NULL ;
V_42 %= V_207 -> V_196 ;
return & V_207 -> V_230 [ V_42 ] ;
}
struct V_211 * F_85 ( struct V_14 * V_14 , struct V_211 * V_231 )
{
struct V_211 * V_232 ;
int V_207 , V_233 ;
if ( ! V_14 || ! V_231 )
return NULL ;
V_207 = V_231 -> V_207 ;
V_233 = V_231 -> V_42 ;
do {
V_232 = F_84 ( V_14 , V_207 , ++ V_233 ) ;
if ( ! V_232 || V_232 == V_231 )
return V_232 ;
} while ( V_232 -> V_216 . V_220 != & V_232 -> V_220 );
return V_232 ;
}
static void F_86 ( void * V_17 )
{
struct V_14 * V_14 = V_17 ;
V_14 -> V_167 . V_168 = NULL ;
V_14 -> V_167 . V_196 = 0 ;
}
static int F_87 ( struct V_14 * V_14 , int V_196 )
{
struct V_194 * V_19 = & V_14 -> V_2 -> V_19 ;
struct V_228 * V_168 ;
int error ;
V_168 = F_81 ( V_19 , sizeof( struct V_228 ) * V_196 ,
V_41 ) ;
if ( ! V_168 )
return - V_113 ;
error = F_83 ( V_19 , F_86 , V_14 ) ;
if ( error )
return error ;
V_14 -> V_167 . V_168 = V_168 ;
V_14 -> V_167 . V_196 = V_196 ;
return 0 ;
}
static int F_88 ( struct V_14 * V_14 , int V_234 ,
int V_235 , bool V_219 )
{
struct V_194 * V_19 ;
int V_76 , error ;
if ( ! V_14 -> V_16 . V_236 )
return - V_115 ;
V_19 = & V_14 -> V_16 . V_236 -> V_19 ;
error = F_87 ( V_14 , V_234 ) ;
if ( error )
return error ;
for ( V_76 = 0 ; V_76 < V_234 ; V_76 ++ ) {
error = F_79 ( V_19 , V_14 , V_76 ,
V_235 ,
V_219 ) ;
if ( error )
return error ;
}
return 0 ;
}
int F_89 ( struct V_14 * V_14 )
{
int error ;
if ( ! ( V_14 -> V_16 . V_33 . V_68 & V_237 ) )
return 0 ;
switch ( V_14 -> V_16 . V_33 . type ) {
case V_72 :
if ( ! V_14 -> V_238 )
return 0 ;
V_14 -> V_167 . V_176 = 100 ;
V_14 -> V_167 . V_214 = 100 ;
error = F_88 ( V_14 , 1 , 4 , false ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_14 , error ) ;
return error ;
}
error = F_67 ( V_14 ,
& V_239 ) ;
break;
case V_240 :
case V_241 :
case V_120 :
case V_242 :
V_14 -> V_167 . V_176 = 10 ;
V_14 -> V_167 . V_186 = 20 ;
V_14 -> V_167 . V_214 = 127 ;
V_14 -> V_167 . V_212 = 127 ;
V_14 -> V_167 . V_187 = 10 ;
error = F_88 ( V_14 , 1 , 4 , false ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_14 , error ) ;
return error ;
}
error = F_67 ( V_14 ,
& V_243 ) ;
break;
case V_185 :
case V_184 :
V_14 -> V_167 . V_176 = 0 ;
V_14 -> V_167 . V_186 = 0 ;
V_14 -> V_167 . V_187 = 0 ;
error = F_88 ( V_14 , 2 , 4 , false ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_14 , error ) ;
return error ;
}
error = F_67 ( V_14 ,
& V_244 ) ;
break;
case V_178 :
case V_245 :
case V_246 :
case V_247 :
case V_248 :
case V_179 :
V_14 -> V_167 . V_176 = 32 ;
V_14 -> V_167 . V_214 = 96 ;
error = F_88 ( V_14 , 1 , 4 , false ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_14 , error ) ;
return error ;
}
error = F_67 ( V_14 ,
& V_249 ) ;
break;
case V_173 :
V_14 -> V_167 . V_176 = 50 ;
V_14 -> V_167 . V_214 = 100 ;
error = F_88 ( V_14 , 1 , 4 , false ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_14 , error ) ;
return error ;
}
return 0 ;
case V_170 :
V_14 -> V_167 . V_176 = 255 ;
V_14 -> V_167 . V_214 = 255 ;
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
V_258 -> V_262 = V_260 -> V_14 -> V_16 . V_208 ;
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
if ( V_260 -> V_271 != V_272 )
V_258 -> V_264 = V_260 -> V_271 ;
else if ( V_260 -> V_273 )
V_258 -> V_264 = V_274 ;
else if ( V_260 -> V_269 == 100 &&
V_260 -> V_275 )
V_258 -> V_264 = V_276 ;
else if ( V_260 -> V_275 )
V_258 -> V_264 = V_277 ;
else
V_258 -> V_264 = V_278 ;
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
static T_5 V_279 = F_97 ( 0 ) ;
struct V_194 * V_19 = & V_14 -> V_2 -> V_19 ;
struct V_280 V_281 = { . V_282 = V_260 , } ;
struct V_253 * V_283 ;
struct V_284 * V_285 = & V_260 -> V_285 ;
unsigned long V_38 ;
int error ;
if ( ! F_80 ( V_19 , V_285 , V_41 ) )
return - V_113 ;
V_260 -> V_14 = V_14 ;
V_38 = F_98 ( & V_279 ) - 1 ;
V_285 -> V_286 = V_287 ;
V_285 -> V_288 = F_99 ( V_287 ) ;
V_285 -> V_289 = F_94 ;
sprintf ( V_260 -> V_290 , L_16 , V_38 ) ;
V_285 -> V_208 = V_260 -> V_290 ;
V_285 -> type = V_291 ;
V_285 -> V_292 = 0 ;
V_283 = F_100 ( V_19 , V_285 , & V_281 ) ;
if ( F_101 ( V_283 ) ) {
error = F_102 ( V_283 ) ;
goto V_197;
}
F_103 ( V_283 , & V_14 -> V_2 -> V_19 ) ;
V_260 -> V_260 = V_283 ;
F_82 ( V_19 , V_285 ) ;
return 0 ;
V_197:
F_78 ( V_19 , V_285 ) ;
return error ;
}
static int F_104 ( struct V_14 * V_14 )
{
if ( V_14 -> V_16 . V_33 . V_293 & V_294 )
return F_96 ( V_14 , & V_14 -> V_260 ) ;
return 0 ;
}
static void F_105 ( struct V_14 * V_14 )
{
if ( V_14 -> V_260 . V_260 ) {
F_78 ( & V_14 -> V_2 -> V_19 ,
& V_14 -> V_260 . V_285 ) ;
V_14 -> V_260 . V_260 = NULL ;
}
}
static T_4 F_106 ( struct V_194 * V_19 ,
struct V_295
* V_296 , char * V_3 )
{
struct V_1 * V_2 = F_56 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
return snprintf ( V_3 , V_297 , L_17 , V_14 -> V_16 . V_119 ) ;
}
static T_4 F_107 ( struct V_194 * V_19 ,
struct V_295 * V_296 ,
const char * V_3 , T_2 V_196 )
{
struct V_1 * V_2 = F_56 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
T_1 V_298 ;
if ( F_108 ( V_3 , 0 , & V_298 ) )
return - V_115 ;
if ( V_298 != 0 && V_298 != 1 )
return - V_115 ;
F_35 ( V_2 , V_298 , & V_14 -> V_16 . V_33 ) ;
return V_196 ;
}
static T_4 F_109 ( struct V_204 * V_205 ,
struct V_299 * V_300 ,
char * V_3 , int V_301 )
{
struct V_194 * V_19 = F_110 ( V_205 -> V_302 ) ;
struct V_1 * V_2 = F_56 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
T_1 V_303 ;
V_303 = V_14 -> V_167 . V_168 [ V_301 ] . V_177 ;
return sprintf ( V_3 , L_18 , V_303 < 3 ? V_303 : - 1 ) ;
}
static int F_111 ( struct V_14 * V_14 , T_3 V_304 ,
int V_301 )
{
int error = 0 ;
struct V_305 * V_306 = V_14 -> V_306 ;
V_306 -> V_307 [ V_301 ] . V_207 . V_208 = F_73 ( & V_14 -> V_2 -> V_19 ,
V_41 ,
L_19 , V_304 ) ;
if ( ! V_306 -> V_307 [ V_301 ] . V_207 . V_208 )
return - V_113 ;
error = F_63 ( V_14 , V_306 -> V_308 ,
& V_306 -> V_307 [ V_301 ] . V_207 ) ;
if ( error ) {
V_306 -> V_307 [ V_301 ] . V_207 . V_208 = NULL ;
F_3 ( V_14 -> V_2 ,
L_15 , error ) ;
return error ;
}
return 0 ;
}
static int F_112 ( struct V_14 * V_14 , unsigned char V_309 )
{
const T_2 V_166 = 2 ;
unsigned char * V_3 ;
int V_6 ;
V_3 = F_17 ( V_166 , V_41 ) ;
if ( ! V_3 )
return - V_113 ;
V_3 [ 0 ] = V_310 ;
V_3 [ 1 ] = V_309 ;
V_6 = F_4 ( V_14 -> V_2 , V_311 , V_3 ,
V_166 , V_44 ) ;
F_19 ( V_3 ) ;
return V_6 ;
}
static T_4 F_113 ( struct V_204 * V_205 ,
struct V_299 * V_296 ,
const char * V_3 , T_2 V_196 )
{
unsigned char V_309 = 0 ;
struct V_194 * V_19 = F_110 ( V_205 -> V_302 ) ;
struct V_1 * V_2 = F_56 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
int V_197 ;
if ( ! strncmp ( V_3 , L_20 , 2 ) ) {
V_309 = V_312 ;
} else {
F_114 ( V_14 -> V_2 , L_21 ,
V_3 ) ;
return - 1 ;
}
F_44 ( & V_14 -> V_198 ) ;
V_197 = F_112 ( V_14 , V_309 ) ;
F_46 ( & V_14 -> V_198 ) ;
return V_197 < 0 ? V_197 : V_196 ;
}
static void F_115 ( void * V_17 )
{
struct V_14 * V_14 = V_17 ;
struct V_305 * V_306 = V_14 -> V_306 ;
if ( ! V_306 )
return;
F_116 ( V_306 -> V_308 ) ;
F_117 ( & V_306 -> V_313 ) ;
V_14 -> V_306 = NULL ;
}
static int F_118 ( struct V_14 * V_14 )
{
int error = 0 ;
struct V_305 * V_306 ;
int V_76 ;
if ( V_14 -> V_16 . V_33 . type != V_170 )
return 0 ;
V_306 = F_81 ( & V_14 -> V_2 -> V_19 , sizeof( * V_14 -> V_306 ) ,
V_41 ) ;
if ( ! V_306 )
return - V_113 ;
V_14 -> V_306 = V_306 ;
F_119 ( & V_306 -> V_314 ) ;
error = F_120 ( & V_306 -> V_313 ,
5 * sizeof( struct V_315 ) ,
V_41 ) ;
if ( error ) {
F_3 ( V_14 -> V_2 , L_22 ) ;
return - V_113 ;
}
V_306 -> V_307 [ 0 ] . V_207 = V_316 ;
V_306 -> V_307 [ 1 ] . V_207 = V_317 ;
V_306 -> V_307 [ 2 ] . V_207 = V_318 ;
V_306 -> V_307 [ 3 ] . V_207 = V_319 ;
V_306 -> V_307 [ 4 ] . V_207 = V_320 ;
V_306 -> V_308 = F_121 ( L_23 ,
& V_14 -> V_2 -> V_19 . V_205 ) ;
if ( ! V_306 -> V_308 )
return - V_113 ;
error = F_122 ( V_306 -> V_308 , V_321 ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_15 , error ) ;
return error ;
}
for ( V_76 = 0 ; V_76 < V_322 ; V_76 ++ ) {
V_14 -> V_167 . V_168 [ V_76 ] . V_177 = V_323 ;
V_306 -> V_307 [ V_76 ] . V_304 = 0 ;
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
V_18 -> V_208 = V_16 -> V_33 . V_208 ;
V_18 -> V_145 = V_2 -> V_145 ;
V_18 -> V_19 . V_302 = & V_2 -> V_19 ;
V_18 -> V_324 = F_8 ;
V_18 -> V_325 = F_11 ;
V_18 -> V_326 = V_2 -> V_326 ;
V_18 -> V_42 . V_327 = V_2 -> V_122 ;
V_18 -> V_42 . V_151 = V_2 -> V_151 ;
V_18 -> V_42 . V_153 = V_16 -> V_171 ? V_16 -> V_171 : V_2 -> V_153 ;
V_18 -> V_42 . V_328 = V_2 -> V_328 ;
F_125 ( V_18 , V_14 ) ;
return V_18 ;
}
static int F_126 ( struct V_14 * V_14 )
{
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
V_16 -> V_329 = F_123 ( V_14 ) ;
V_16 -> V_97 = F_123 ( V_14 ) ;
V_16 -> V_236 = F_123 ( V_14 ) ;
if ( ! V_16 -> V_329 ||
! V_16 -> V_97 ||
! V_16 -> V_236 )
return - V_113 ;
V_16 -> V_329 -> V_208 = V_16 -> V_330 ;
V_16 -> V_97 -> V_208 = V_16 -> V_331 ;
V_16 -> V_236 -> V_208 = V_16 -> V_332 ;
return 0 ;
}
static int F_127 ( struct V_14 * V_14 )
{
struct V_18 * V_333 , * V_334 , * V_335 ;
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
int error = 0 ;
V_333 = V_16 -> V_329 ;
V_334 = V_16 -> V_97 ;
V_335 = V_16 -> V_236 ;
if ( ! V_333 || ! V_334 || ! V_335 )
return - V_115 ;
error = F_128 ( V_333 , V_16 ) ;
if ( error ) {
F_129 ( V_333 ) ;
V_16 -> V_329 = NULL ;
V_333 = NULL ;
} else {
error = F_130 ( V_333 ) ;
if ( error )
goto V_336;
}
error = F_131 ( V_334 , V_16 ) ;
if ( error ) {
F_129 ( V_334 ) ;
V_16 -> V_97 = NULL ;
V_334 = NULL ;
} else {
error = F_130 ( V_334 ) ;
if ( error )
goto V_336;
}
error = F_132 ( V_335 , V_16 ) ;
if ( error ) {
F_129 ( V_335 ) ;
V_16 -> V_236 = NULL ;
V_335 = NULL ;
} else {
error = F_130 ( V_335 ) ;
if ( error )
goto V_336;
}
return 0 ;
V_336:
V_16 -> V_236 = NULL ;
V_16 -> V_97 = NULL ;
V_16 -> V_329 = NULL ;
return error ;
}
static void F_133 ( struct V_32 * V_33 )
{
if ( V_33 -> V_337 ) {
V_33 -> V_86 = ( V_33 -> V_85 * 100 ) /
V_33 -> V_337 ;
V_33 -> V_91 = ( V_33 -> V_90 * 100 ) /
V_33 -> V_338 ;
}
}
static void F_134 ( struct V_32 * V_33 )
{
if ( ! V_33 -> V_22 ) {
V_33 -> V_22 = 0x11 ;
V_33 -> V_88 = - 3 ;
}
V_33 -> V_337 = F_13 ( V_33 -> V_85 ,
V_33 -> V_86 ,
V_33 -> V_22 ,
V_33 -> V_88 ) ;
V_33 -> V_338 = F_13 ( V_33 -> V_90 ,
V_33 -> V_91 ,
V_33 -> V_22 ,
V_33 -> V_88 ) ;
}
void F_135 ( struct V_250 * V_251 )
{
struct V_14 * V_14 = F_43 ( V_251 , struct V_14 , V_339 ) ;
if ( ( V_14 -> V_16 . V_33 . V_293 & V_294 ) &&
! V_14 -> V_260 . V_260 ) {
F_104 ( V_14 ) ;
}
else if ( ! ( V_14 -> V_16 . V_33 . V_293 & V_294 ) &&
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
T_2 V_340 = F_21 ( V_12 ) ;
if ( V_340 > V_4 )
V_4 = V_340 ;
}
return V_4 ;
}
static void F_137 ( struct V_14 * V_14 , const char * V_341 )
{
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_32 * V_33 = & V_16 -> V_33 ;
char V_208 [ V_342 ] ;
if ( ( V_33 -> type == V_72 ) && ! strcmp ( L_24 , V_33 -> V_208 ) ) {
char * V_343 = V_14 -> V_2 -> V_208 ;
if ( F_138 ( V_14 -> V_2 , & V_344 ) ) {
struct V_128 * V_129 = F_139 ( V_14 -> V_2 -> V_19 . V_302 ) ;
struct V_345 * V_19 = F_140 ( V_129 ) ;
V_343 = V_19 -> V_153 ;
}
if ( V_14 -> V_2 -> V_122 == V_346 ) {
snprintf ( V_208 , sizeof( V_208 ) , L_25 ,
V_33 -> V_208 , V_14 -> V_2 -> V_153 ) ;
} else if ( strstr ( V_343 , L_26 ) ||
strstr ( V_343 , L_27 ) ||
strstr ( V_343 , L_28 ) ) {
F_141 ( V_208 , V_343 , sizeof( V_208 ) ) ;
} else {
snprintf ( V_208 , sizeof( V_208 ) , L_29 , V_343 ) ;
}
while ( 1 ) {
char * V_347 = strstr ( V_208 , L_30 ) ;
if ( V_347 == NULL )
break;
memmove ( V_347 , V_347 + 1 , strlen ( V_347 ) ) ;
}
if ( V_208 [ strlen ( V_208 ) - 1 ] == ' ' )
V_208 [ strlen ( V_208 ) - 1 ] = '\0' ;
} else {
F_141 ( V_208 , V_33 -> V_208 , sizeof( V_208 ) ) ;
}
snprintf ( V_16 -> V_208 , sizeof( V_16 -> V_208 ) , L_31 ,
V_208 , V_341 ) ;
snprintf ( V_16 -> V_330 , sizeof( V_16 -> V_330 ) ,
L_32 , V_208 , V_341 ) ;
snprintf ( V_16 -> V_331 , sizeof( V_16 -> V_331 ) ,
L_33 , V_208 , V_341 ) ;
snprintf ( V_16 -> V_332 , sizeof( V_16 -> V_332 ) ,
L_34 , V_208 , V_341 ) ;
}
static void F_142 ( struct V_14 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
if ( ! V_14 -> V_348 )
return;
F_78 ( & V_2 -> V_19 , V_14 ) ;
V_14 -> V_348 = false ;
V_14 -> V_16 . V_329 = NULL ;
V_14 -> V_16 . V_97 = NULL ;
V_14 -> V_16 . V_236 = NULL ;
}
static void F_143 ( struct V_16 * V_16 )
{
if ( V_16 -> V_33 . V_68 & V_70 ) {
V_16 -> V_160 -> type = V_16 -> V_33 . type ;
V_16 -> V_160 -> V_97 = V_16 -> V_97 ;
}
if ( V_16 -> V_349 ) {
V_16 -> V_160 -> V_349 = true ;
V_16 -> V_160 -> V_350 = true ;
}
if ( V_16 -> V_160 -> V_349 &&
V_16 -> V_160 -> V_97 ) {
F_144 ( V_351 , V_16 -> V_160 -> V_97 -> V_352 ) ;
F_145 ( V_16 -> V_160 -> V_97 , V_351 ,
V_353 ) ;
}
}
static int F_146 ( struct V_14 * V_14 , bool V_354 )
{
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_32 * V_33 = & V_16 -> V_33 ;
struct V_1 * V_2 = V_14 -> V_2 ;
int error ;
unsigned int V_355 = V_356 ;
V_33 -> V_357 = F_136 ( V_2 ) ;
if ( V_33 -> V_357 > V_15 )
return - V_115 ;
if ( ! F_80 ( & V_2 -> V_19 , V_14 , V_41 ) )
return - V_113 ;
V_14 -> V_348 = true ;
error = F_126 ( V_14 ) ;
if ( error )
goto V_336;
if ( V_33 -> type == V_127 ) {
if ( V_33 -> V_357 == V_358 ) {
V_33 -> type = V_72 ;
} else if ( ( V_33 -> V_357 != V_359 ) &&
( V_33 -> V_357 != V_360 ) ) {
error = - V_361 ;
goto V_336;
}
}
F_133 ( V_33 ) ;
F_37 ( V_2 , V_33 ) ;
F_147 ( V_14 ) ;
if ( V_33 -> V_68 == V_140 &&
V_33 -> type != V_135 ) {
error = V_33 -> type == V_72 ? - V_361 : 0 ;
F_148 ( & V_2 -> V_19 , L_35 ,
V_2 -> V_208 ,
error ? L_36 : L_37 ) ;
if ( error )
goto V_336;
V_33 -> V_68 |= V_69 ;
}
F_134 ( V_33 ) ;
F_137 ( V_14 , V_354 ? L_38 : L_39 ) ;
if ( ( V_33 -> type == V_362 ) &&
( ( V_33 -> V_68 & V_70 ) ||
( V_33 -> V_68 & V_237 ) ) ) {
error = - V_361 ;
goto V_336;
}
error = F_49 ( V_2 ) ;
if ( error )
goto V_336;
if ( ! ( V_33 -> V_68 & V_139 ) &&
( V_33 -> V_293 & V_294 ) ) {
error = F_104 ( V_14 ) ;
if ( error )
goto V_336;
}
error = F_127 ( V_14 ) ;
if ( error )
goto V_336;
if ( V_14 -> V_16 . V_33 . V_68 & V_237 ) {
error = F_89 ( V_14 ) ;
if ( error )
goto V_336;
error = F_118 ( V_14 ) ;
if ( error )
goto V_336;
}
if ( V_33 -> type == V_72 )
V_355 |= V_363 ;
error = F_149 ( V_2 , V_355 ) ;
if ( error ) {
F_3 ( V_2 , L_40 ) ;
goto V_336;
}
if ( ! V_354 ) {
F_91 ( V_14 ) ;
}
if ( ( V_33 -> type == V_87 ) &&
( V_33 -> V_68 & V_69 ) ) {
F_150 ( & V_14 -> V_252 ) ;
F_36 ( V_14 ) ;
error = - V_361 ;
goto V_364;
}
if ( V_33 -> V_68 & V_139 )
error = F_10 ( V_2 ) ;
F_143 ( V_16 ) ;
F_82 ( & V_2 -> V_19 , V_14 ) ;
return 0 ;
V_364:
F_151 ( V_2 ) ;
V_336:
F_142 ( V_14 ) ;
return error ;
}
static void F_152 ( struct V_250 * V_251 )
{
struct V_14 * V_14 = F_43 ( V_251 , struct V_14 , V_365 ) ;
struct V_345 * V_366 = V_14 -> V_366 ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_1 * V_367 , * V_368 ;
struct V_14 * V_369 , * V_370 ;
struct V_16 * V_371 , * V_372 ;
int error ;
F_105 ( V_14 ) ;
V_367 = F_153 ( V_366 -> V_373 -> V_374 [ 1 ] ) ;
V_369 = F_6 ( V_367 ) ;
V_371 = & ( V_369 -> V_16 ) ;
F_142 ( V_369 ) ;
V_368 = F_153 ( V_366 -> V_373 -> V_374 [ 2 ] ) ;
V_370 = F_6 ( V_368 ) ;
V_372 = & ( V_370 -> V_16 ) ;
F_142 ( V_370 ) ;
if ( V_16 -> V_171 == 0 ) {
F_114 ( V_14 -> V_2 , L_41 ) ;
} else {
const struct V_375 * V_42 = V_376 ;
F_114 ( V_14 -> V_2 , L_42 ,
V_16 -> V_171 ) ;
while ( V_42 -> V_122 ) {
if ( V_42 -> V_151 == V_377 &&
V_42 -> V_153 == V_16 -> V_171 )
break;
V_42 ++ ;
}
if ( ! V_42 -> V_122 ) {
F_114 ( V_14 -> V_2 , L_43 ) ;
return;
}
V_371 -> V_33 =
* ( (struct V_32 * ) V_42 -> V_378 ) ;
V_371 -> V_171 = V_16 -> V_171 ;
F_151 ( V_367 ) ;
error = F_146 ( V_369 , true ) ;
if ( error )
goto V_336;
if ( V_371 -> V_33 . V_40 ||
( V_371 -> V_33 . type >= V_379 &&
V_371 -> V_33 . type <= V_71 ) ) {
V_372 -> V_33 =
* ( (struct V_32 * ) V_42 -> V_378 ) ;
V_372 -> V_171 = V_16 -> V_171 ;
F_151 ( V_368 ) ;
error = F_146 ( V_370 , true ) ;
if ( error )
goto V_336;
}
F_141 ( V_16 -> V_208 , V_371 -> V_208 ,
sizeof( V_16 -> V_208 ) ) ;
error = F_104 ( V_14 ) ;
if ( error )
goto V_336;
}
return;
V_336:
F_142 ( V_369 ) ;
F_142 ( V_370 ) ;
return;
}
static void F_154 ( struct V_14 * V_14 , unsigned int V_301 )
{
struct V_305 * V_306 = V_14 -> V_306 ;
T_6 V_304 = V_306 -> V_307 [ V_301 ] . V_304 ;
int V_76 ;
unsigned long V_222 ;
F_155 ( & V_306 -> V_314 , V_222 ) ;
V_306 -> V_307 [ V_301 ] . V_380 = false ;
F_156 ( & V_306 -> V_314 , V_222 ) ;
if ( V_306 -> V_307 [ V_301 ] . V_260 . V_260 )
F_78 ( & V_14 -> V_2 -> V_19 ,
& V_306 -> V_307 [ V_301 ] . V_260 . V_285 ) ;
if ( V_306 -> V_307 [ V_301 ] . V_207 . V_208 )
F_78 ( & V_14 -> V_2 -> V_19 ,
& V_306 -> V_307 [ V_301 ] ) ;
for ( V_76 = 0 ; V_76 < V_322 ; V_76 ++ ) {
if ( V_306 -> V_307 [ V_76 ] . V_304 == V_304 ) {
V_306 -> V_307 [ V_76 ] . V_304 = 0 ;
V_306 -> V_307 [ V_76 ] . V_207 . V_208 = NULL ;
V_306 -> V_307 [ V_76 ] . V_380 = false ;
V_306 -> V_307 [ V_76 ] . V_260 . V_260 = NULL ;
V_14 -> V_167 . V_168 [ V_76 ] . V_177 = V_323 ;
}
}
}
static int F_157 ( struct V_14 * V_14 , T_6 V_304 ,
unsigned int V_301 )
{
struct V_305 * V_306 = V_14 -> V_306 ;
struct V_194 * V_19 = & V_14 -> V_2 -> V_19 ;
int error , V_381 ;
for ( V_381 = 0 ; V_381 < V_322 ; V_381 ++ ) {
if ( V_306 -> V_307 [ V_381 ] . V_304 == V_304 )
break;
}
if ( V_381 < V_322 ) {
V_306 -> V_307 [ V_301 ] . V_304 = V_304 ;
return 0 ;
}
if ( ! F_80 ( V_19 , & V_306 -> V_307 [ V_301 ] , V_41 ) )
return - V_113 ;
error = F_111 ( V_14 , V_304 , V_301 ) ;
if ( error )
goto V_336;
V_306 -> V_307 [ V_301 ] . V_382 = F_123 ( V_14 ) ;
if ( ! V_306 -> V_307 [ V_301 ] . V_382 ) {
error = - V_113 ;
goto V_336;
}
V_306 -> V_307 [ V_301 ] . V_382 -> V_326 = V_306 -> V_307 [ V_301 ] . V_207 . V_208 ;
V_306 -> V_307 [ V_301 ] . V_382 -> V_208 = V_14 -> V_16 . V_332 ;
if ( ! V_306 -> V_307 [ V_301 ] . V_382 -> V_208 ) {
error = - V_115 ;
goto V_336;
}
error = F_132 ( V_306 -> V_307 [ V_301 ] . V_382 ,
& V_14 -> V_16 ) ;
if ( error )
goto V_336;
V_306 -> V_307 [ V_301 ] . V_304 = V_304 ;
error = F_130 ( V_306 -> V_307 [ V_301 ] . V_382 ) ;
if ( error )
goto V_336;
error = F_79 (
& V_306 -> V_307 [ V_301 ] . V_382 -> V_19 ,
V_14 , V_301 , 3 , true ) ;
if ( error )
goto V_336;
V_306 -> V_307 [ V_301 ] . V_380 = true ;
F_82 ( V_19 , & V_306 -> V_307 [ V_301 ] ) ;
return 0 ;
V_336:
F_78 ( V_19 , & V_306 -> V_307 [ V_301 ] ) ;
V_306 -> V_307 [ V_301 ] . V_304 = 0 ;
return error ;
}
static int F_158 ( struct V_14 * V_14 , int V_301 )
{
struct V_305 * V_306 = V_14 -> V_306 ;
int error ;
if ( ! V_306 -> V_307 [ V_301 ] . V_380 )
return 0 ;
if ( V_306 -> V_307 [ V_301 ] . V_260 . V_260 )
return 0 ;
if ( V_14 -> V_167 . V_168 [ V_301 ] . V_177 == V_323 )
return 0 ;
error = F_96 ( V_14 ,
& V_14 -> V_306 -> V_307 [ V_301 ] . V_260 ) ;
if ( error )
return error ;
return 0 ;
}
static void F_159 ( struct V_250 * V_251 )
{
struct V_14 * V_14 = F_43 ( V_251 , struct V_14 , V_383 ) ;
struct V_305 * V_306 = V_14 -> V_306 ;
struct V_315 V_17 ;
unsigned long V_222 ;
unsigned int V_196 ;
T_6 V_304 ;
int V_76 ;
F_155 ( & V_306 -> V_314 , V_222 ) ;
V_196 = F_160 ( & V_306 -> V_313 , & V_17 , sizeof( V_17 ) ) ;
if ( V_196 != sizeof( V_17 ) ) {
F_3 ( V_14 -> V_2 ,
L_44 ) ;
F_156 ( & V_306 -> V_314 , V_222 ) ;
return;
}
if ( ! F_161 ( & V_306 -> V_313 ) )
F_162 ( & V_14 -> V_16 , V_384 ) ;
F_156 ( & V_306 -> V_314 , V_222 ) ;
for ( V_76 = 0 ; V_76 < V_322 ; V_76 ++ ) {
V_304 = V_17 . V_306 [ V_76 ] . V_304 ;
if ( V_17 . V_306 [ V_76 ] . V_385 ) {
if ( V_306 -> V_307 [ V_76 ] . V_304 == V_304 ) {
F_158 ( V_14 , V_76 ) ;
continue;
}
if ( V_306 -> V_307 [ V_76 ] . V_304 )
F_154 ( V_14 , V_76 ) ;
F_157 ( V_14 , V_304 , V_76 ) ;
} else if ( V_306 -> V_307 [ V_76 ] . V_304 ) {
F_154 ( V_14 , V_76 ) ;
}
}
}
static void F_163 ( struct V_250 * V_251 )
{
struct V_14 * V_14 = F_43 ( V_251 , struct V_14 , V_386 ) ;
struct V_387 * V_160 = V_14 -> V_16 . V_160 ;
struct V_14 * V_369 = NULL ;
struct V_14 * V_370 = NULL ;
bool V_388 = V_14 -> V_16 . V_95 ;
int error = 0 ;
if ( V_160 -> V_67 ) {
V_369 = F_6 ( V_160 -> V_67 ) ;
F_142 ( V_369 ) ;
F_151 ( V_369 -> V_2 ) ;
V_369 -> V_16 . V_94 = true ;
V_369 -> V_16 . V_95 = V_388 ;
}
if ( V_160 -> V_161 ) {
V_370 = F_6 ( V_160 -> V_161 ) ;
F_142 ( V_370 ) ;
F_151 ( V_370 -> V_2 ) ;
V_370 -> V_16 . V_94 = true ;
V_370 -> V_16 . V_95 = V_388 ;
}
if ( V_369 ) {
error = F_146 ( V_369 , false ) ;
if ( error )
return;
}
if ( V_370 ) {
error = F_146 ( V_370 , false ) ;
if ( error )
return;
}
return;
}
static int F_164 ( struct V_1 * V_2 ,
const struct V_375 * V_42 )
{
struct V_128 * V_129 = F_139 ( V_2 -> V_19 . V_302 ) ;
struct V_345 * V_19 = F_140 ( V_129 ) ;
struct V_14 * V_14 ;
struct V_16 * V_16 ;
struct V_32 * V_33 ;
int error ;
if ( ! V_42 -> V_378 )
return - V_115 ;
V_2 -> V_293 |= V_389 ;
V_2 -> V_293 &= ~ V_390 ;
V_14 = F_81 ( & V_2 -> V_19 , sizeof( struct V_14 ) , V_41 ) ;
if ( ! V_14 )
return - V_113 ;
F_165 ( V_2 , V_14 ) ;
V_14 -> V_2 = V_2 ;
V_16 = & V_14 -> V_16 ;
V_16 -> V_33 = * ( (struct V_32 * ) V_42 -> V_378 ) ;
V_33 = & V_16 -> V_33 ;
if ( V_33 -> V_391 && V_33 -> V_392 != V_2 -> type ) {
error = - V_361 ;
goto V_336;
}
V_16 -> V_34 . V_48 = - 1 ;
V_16 -> V_54 = - 1 ;
V_14 -> V_366 = V_19 ;
V_14 -> V_129 = V_129 ;
F_166 ( & V_14 -> V_198 ) ;
F_167 ( & V_14 -> V_252 , F_90 ) ;
F_168 ( & V_14 -> V_365 , F_152 ) ;
F_168 ( & V_14 -> V_339 , F_135 ) ;
F_168 ( & V_14 -> V_383 , F_159 ) ;
F_168 ( & V_14 -> V_386 , F_163 ) ;
error = F_169 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_45 ) ;
goto V_336;
}
error = F_146 ( V_14 , false ) ;
if ( error )
goto V_336;
if ( V_2 -> V_122 == V_123 ) {
error = F_170 ( & V_2 -> V_19 , & V_393 ) ;
if ( error )
F_18 ( V_2 ,
L_46 ,
error ) ;
}
return 0 ;
V_336:
F_165 ( V_2 , NULL ) ;
return error ;
}
static void F_171 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_32 * V_33 = & V_16 -> V_33 ;
if ( V_33 -> V_68 & V_139 )
F_12 ( V_2 ) ;
F_151 ( V_2 ) ;
F_150 ( & V_14 -> V_252 ) ;
F_172 ( & V_14 -> V_365 ) ;
F_172 ( & V_14 -> V_339 ) ;
F_172 ( & V_14 -> V_383 ) ;
F_172 ( & V_14 -> V_386 ) ;
if ( V_2 -> V_122 == V_123 )
F_173 ( & V_2 -> V_19 , & V_393 ) ;
F_86 ( V_14 ) ;
if ( V_14 -> V_16 . V_33 . type != V_170 )
F_142 ( V_14 ) ;
F_165 ( V_2 , NULL ) ;
}
static int F_174 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
F_44 ( & V_14 -> V_198 ) ;
F_36 ( V_14 ) ;
F_53 ( V_14 ) ;
F_46 ( & V_14 -> V_198 ) ;
return 0 ;
}
static int F_175 ( struct V_1 * V_2 )
{
return F_174 ( V_2 ) ;
}
