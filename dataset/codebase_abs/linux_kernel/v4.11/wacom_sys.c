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
if ( V_33 -> V_40 > 1 ) {
if ( V_33 -> V_68 & V_94 )
F_29 ( V_16 -> V_95 ,
V_16 -> V_33 . V_40 ,
V_96 ) ;
else
F_29 ( V_16 -> V_95 ,
V_16 -> V_33 . V_40 ,
V_97 ) ;
}
}
}
static void F_30 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_98 * V_99 ;
struct V_11 * V_100 ;
int V_76 , V_101 ;
V_99 = & V_2 -> V_102 [ V_43 ] ;
F_31 (hreport, &rep_enum->report_list, list) {
for ( V_76 = 0 ; V_76 < V_100 -> V_103 ; V_76 ++ ) {
if ( V_100 -> V_25 [ V_76 ] -> V_47 < 1 )
continue;
for ( V_101 = 0 ; V_101 < V_100 -> V_25 [ V_76 ] -> V_77 ; V_101 ++ ) {
F_15 ( V_2 , V_100 -> V_25 [ V_76 ] ,
V_100 -> V_25 [ V_76 ] -> V_31 + V_101 ) ;
}
}
}
V_99 = & V_2 -> V_102 [ V_104 ] ;
F_31 (hreport, &rep_enum->report_list, list) {
if ( ! V_100 -> V_103 )
continue;
for ( V_76 = 0 ; V_76 < V_100 -> V_103 ; V_76 ++ )
for ( V_101 = 0 ; V_101 < V_100 -> V_25 [ V_76 ] -> V_77 ; V_101 ++ )
F_24 ( V_2 , V_100 -> V_25 [ V_76 ] ,
V_100 -> V_25 [ V_76 ] -> V_31 + V_101 ) ;
}
F_28 ( V_2 , V_33 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_34 * V_34 = & V_14 -> V_16 . V_34 ;
struct V_11 * V_105 ;
struct V_98 * V_106 ;
if ( V_34 -> V_48 < 0 )
return 0 ;
V_106 = & ( V_2 -> V_102 [ V_43 ] ) ;
V_105 = V_106 -> V_107 [ V_34 -> V_48 ] ;
if ( V_105 ) {
V_105 -> V_25 [ 0 ] -> V_108 [ V_34 -> V_49 ] = 2 ;
F_33 ( V_2 , V_105 , V_10 ) ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_16 * V_16 )
{
T_1 * V_109 ;
struct V_11 * V_105 ;
struct V_98 * V_106 ;
int V_110 ;
int error = - V_111 , V_112 = 0 ;
if ( V_16 -> V_54 < 0 )
return 0 ;
V_106 = & ( V_2 -> V_102 [ V_43 ] ) ;
V_105 = V_106 -> V_107 [ V_16 -> V_54 ] ;
if ( ! V_105 )
return - V_113 ;
V_109 = F_22 ( V_105 , V_41 ) ;
if ( ! V_109 )
return - V_111 ;
V_110 = F_21 ( V_105 ) ;
do {
V_109 [ 0 ] = V_16 -> V_54 ;
V_109 [ 1 ] = V_16 -> V_55 ;
error = F_4 ( V_2 , V_43 , V_109 ,
V_110 , 1 ) ;
if ( error >= 0 )
error = F_1 ( V_2 , V_43 ,
V_109 , V_110 , 1 ) ;
} while ( error >= 0 &&
V_109 [ 1 ] != V_16 -> V_54 &&
V_112 ++ < V_114 );
F_19 ( V_109 ) ;
return error < 0 ? error : 0 ;
}
static int F_35 ( struct V_1 * V_2 , T_1 V_115 ,
struct V_32 * V_33 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
int V_37 ;
T_1 V_109 [ 2 ] ;
switch ( V_33 -> type ) {
case V_116 :
V_109 [ 0 ] = 0x03 ;
V_109 [ 1 ] = 0x00 ;
V_37 = F_4 ( V_2 , V_43 , V_109 , 2 ,
3 ) ;
if ( V_37 >= 0 ) {
V_109 [ 0 ] = V_115 == 0 ? 0x05 : 0x06 ;
V_109 [ 1 ] = 0x00 ;
V_37 = F_4 ( V_2 , V_43 ,
V_109 , 2 , 3 ) ;
if ( V_37 >= 0 ) {
V_14 -> V_16 . V_117 = V_115 ;
return 0 ;
}
}
F_18 ( V_2 , L_9 ,
V_109 [ 0 ] , V_37 ) ;
break;
case V_118 :
if ( V_115 == 1 )
V_14 -> V_16 . V_119 &= ~ 0x20 ;
else
V_14 -> V_16 . V_119 |= 0x20 ;
V_109 [ 0 ] = 0x03 ;
V_109 [ 1 ] = V_14 -> V_16 . V_119 ;
V_37 = F_4 ( V_2 , V_43 , V_109 , 2 ,
1 ) ;
if ( V_37 >= 0 )
V_14 -> V_16 . V_117 = V_115 ;
break;
}
return 0 ;
}
static int F_36 ( struct V_14 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_32 * V_33 = & V_16 -> V_33 ;
if ( V_2 -> V_120 == V_121 )
return F_35 ( V_2 , 1 , V_33 ) ;
if ( V_33 -> type != V_72 ) {
if ( V_33 -> V_68 & V_70 ) {
if ( V_33 -> type > V_122 ) {
V_16 -> V_54 = 3 ;
V_16 -> V_55 = 4 ;
} else if ( V_33 -> type == V_123 ) {
V_16 -> V_54 = 18 ;
V_16 -> V_55 = 2 ;
} else if ( V_33 -> type == V_124 ) {
V_16 -> V_54 = 131 ;
V_16 -> V_55 = 2 ;
} else if ( V_33 -> type == V_125 ) {
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
struct V_126 * V_127 = V_14 -> V_127 ;
V_33 -> V_128 = 4 ;
V_33 -> V_129 = 4 ;
V_33 -> V_130 = 0 ;
V_33 -> V_131 = 1 ;
V_33 -> V_132 = 1 ;
if ( V_33 -> type == V_133 ) {
if ( V_127 -> V_134 -> V_135 . V_136 == 0 )
V_33 -> V_68 = V_137 ;
else
V_33 -> V_68 = V_138 ;
return;
}
F_30 ( V_2 , V_33 ) ;
}
static bool F_38 ( struct V_1 * V_139 ,
struct V_1 * V_140 , char V_141 )
{
int V_142 = strrchr ( V_139 -> V_143 , V_141 ) - V_139 -> V_143 ;
int V_144 = strrchr ( V_140 -> V_143 , V_141 ) - V_140 -> V_143 ;
if ( V_142 != V_144 || V_142 <= 0 || V_144 <= 0 )
return false ;
return ! strncmp ( V_139 -> V_143 , V_140 -> V_143 , V_142 ) ;
}
static bool F_39 ( struct V_1 * V_2 ,
struct V_1 * V_145 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_32 * V_33 = & V_14 -> V_16 . V_33 ;
struct V_14 * V_146 = F_6 ( V_145 ) ;
struct V_32 * V_147 = & V_146 -> V_16 . V_33 ;
T_3 V_148 = V_33 -> V_148 ? V_33 -> V_148 : V_2 -> V_149 ;
T_3 V_150 = V_33 -> V_150 ? V_33 -> V_150 : V_2 -> V_151 ;
if ( V_33 -> V_148 != V_152 && V_145 -> V_149 != V_148 )
return false ;
if ( V_33 -> V_150 != V_152 && V_145 -> V_151 != V_150 )
return false ;
if ( V_2 -> V_149 == V_145 -> V_149 && V_2 -> V_151 == V_145 -> V_151 ) {
if ( ! F_38 ( V_2 , V_145 , '/' ) )
return false ;
} else {
if ( ! F_38 ( V_2 , V_145 , '.' ) )
return false ;
}
if ( V_33 -> type != V_72 )
return true ;
if ( ( V_33 -> V_68 & V_94 ) &&
! ( V_147 -> V_68 & V_94 ) )
return false ;
if ( ! ( V_33 -> V_68 & V_94 ) &&
( V_147 -> V_68 & V_94 ) )
return false ;
if ( ( V_33 -> V_68 & V_69 ) &&
! ( V_147 -> V_68 & V_70 ) )
return false ;
if ( ( V_33 -> V_68 & V_70 ) &&
! ( V_147 -> V_68 & V_69 ) )
return false ;
return true ;
}
static struct V_153 * F_40 ( struct V_1 * V_2 )
{
struct V_153 * V_17 ;
F_31 (data, &wacom_udev_list, list) {
if ( F_38 ( V_2 , V_17 -> V_19 , '/' ) )
return V_17 ;
}
F_31 (data, &wacom_udev_list, list) {
if ( F_39 ( V_2 , V_17 -> V_19 ) ) {
F_41 ( & V_17 -> V_154 ) ;
return V_17 ;
}
}
return NULL ;
}
static void F_42 ( struct V_154 * V_154 )
{
struct V_153 * V_17 =
F_43 ( V_154 , struct V_153 , V_154 ) ;
F_44 ( & V_155 ) ;
F_45 ( & V_17 -> V_156 ) ;
F_46 ( & V_155 ) ;
F_19 ( V_17 ) ;
}
static void F_47 ( void * V_157 )
{
struct V_14 * V_14 = V_157 ;
struct V_153 * V_17 ;
struct V_16 * V_16 = & V_14 -> V_16 ;
if ( V_16 -> V_158 ) {
V_17 = F_43 ( V_16 -> V_158 , struct V_153 ,
V_158 ) ;
if ( V_16 -> V_158 -> V_159 == V_14 -> V_2 )
V_16 -> V_158 -> V_159 = NULL ;
else if ( V_16 -> V_158 -> V_67 == V_14 -> V_2 )
V_16 -> V_158 -> V_67 = NULL ;
F_48 ( & V_17 -> V_154 , F_42 ) ;
V_16 -> V_158 = NULL ;
}
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_153 * V_17 ;
int V_6 = 0 ;
F_44 ( & V_155 ) ;
V_17 = F_40 ( V_2 ) ;
if ( ! V_17 ) {
V_17 = F_17 ( sizeof( struct V_153 ) , V_41 ) ;
if ( ! V_17 ) {
V_6 = - V_111 ;
goto V_160;
}
F_50 ( & V_17 -> V_154 ) ;
V_17 -> V_19 = V_2 ;
F_51 ( & V_17 -> V_156 , & V_161 ) ;
}
V_16 -> V_158 = & V_17 -> V_158 ;
V_6 = F_52 ( & V_2 -> V_19 , F_47 , V_14 ) ;
if ( V_6 ) {
F_46 ( & V_155 ) ;
F_47 ( V_14 ) ;
return V_6 ;
}
if ( V_16 -> V_33 . V_68 & V_70 )
V_16 -> V_158 -> V_159 = V_2 ;
else if ( V_16 -> V_33 . V_68 & V_69 )
V_16 -> V_158 -> V_67 = V_2 ;
V_160:
F_46 ( & V_155 ) ;
return V_6 ;
}
static int F_53 ( struct V_14 * V_14 )
{
unsigned char * V_3 ;
int V_6 ;
unsigned char V_162 = V_163 ;
int V_164 = 9 ;
if ( ! V_14 -> V_165 . V_166 )
return - V_167 ;
if ( V_14 -> V_16 . V_168 ) {
V_162 = V_169 ;
V_164 = 13 ;
}
else if ( V_14 -> V_16 . V_33 . type == V_170 ) {
V_162 = V_171 ;
V_164 = 51 ;
}
V_3 = F_17 ( V_164 , V_41 ) ;
if ( ! V_3 )
return - V_111 ;
if ( V_14 -> V_16 . V_33 . type == V_72 ) {
V_3 [ 0 ] = V_172 ;
V_3 [ 1 ] = V_14 -> V_165 . V_173 ;
V_3 [ 2 ] = V_14 -> V_165 . V_166 [ 0 ] . V_174 & 0x03 ;
} else if ( ( V_14 -> V_16 . V_33 . type >= V_175 &&
V_14 -> V_16 . V_33 . type <= V_176 ) ) {
int V_177 = V_14 -> V_165 . V_166 [ 0 ] . V_174 & 0x03 ;
int V_178 = ( ( ( V_14 -> V_165 . V_173 & 0x60 ) >> 5 ) - 1 ) & 0x03 ;
int V_179 = 0 ;
unsigned char V_180 = ( V_179 << 4 ) | ( V_178 << 2 ) | ( V_177 ) ;
V_3 [ 0 ] = V_162 ;
if ( V_14 -> V_16 . V_168 ) {
F_1 ( V_14 -> V_2 , V_43 ,
V_3 , V_164 , V_44 ) ;
V_3 [ 0 ] = V_162 ;
V_3 [ 4 ] = V_180 ;
} else
V_3 [ 1 ] = V_180 ;
}
else if ( V_14 -> V_16 . V_33 . type == V_170 ) {
V_3 [ 0 ] = V_162 ;
V_3 [ 4 ] = 100 ;
V_3 [ 5 ] = 100 ;
V_3 [ 6 ] = 100 ;
V_3 [ 7 ] = 100 ;
V_3 [ 8 ] = 100 ;
V_3 [ 9 ] = V_14 -> V_165 . V_173 ;
V_3 [ 10 ] = V_14 -> V_165 . V_166 [ 0 ] . V_174 & 0x03 ;
}
else {
int V_165 = V_14 -> V_165 . V_166 [ 0 ] . V_174 | 0x4 ;
if ( V_14 -> V_16 . V_33 . type == V_181 ||
V_14 -> V_16 . V_33 . type == V_182 )
V_165 |= ( V_14 -> V_165 . V_166 [ 1 ] . V_174 << 4 ) | 0x40 ;
V_3 [ 0 ] = V_162 ;
V_3 [ 1 ] = V_165 ;
V_3 [ 2 ] = V_14 -> V_165 . V_173 ;
V_3 [ 3 ] = V_14 -> V_165 . V_183 ;
V_3 [ 4 ] = V_14 -> V_165 . V_184 ;
}
V_6 = F_4 ( V_14 -> V_2 , V_43 , V_3 , V_164 ,
V_44 ) ;
F_19 ( V_3 ) ;
return V_6 ;
}
static int F_54 ( struct V_14 * V_14 , int V_185 , T_1 V_186 ,
const unsigned V_187 , const void * V_188 )
{
unsigned char * V_3 ;
int V_76 , V_6 ;
const unsigned V_189 = V_187 / 4 ;
V_3 = F_17 ( V_189 + 3 , V_41 ) ;
if ( ! V_3 )
return - V_111 ;
V_3 [ 0 ] = V_190 ;
V_3 [ 1 ] = 1 ;
V_6 = F_4 ( V_14 -> V_2 , V_43 , V_3 , 2 ,
V_44 ) ;
if ( V_6 < 0 )
goto V_160;
V_3 [ 0 ] = V_186 ;
V_3 [ 1 ] = V_185 & 0x07 ;
for ( V_76 = 0 ; V_76 < 4 ; V_76 ++ ) {
V_3 [ 2 ] = V_76 ;
memcpy ( V_3 + 3 , V_188 + V_76 * V_189 , V_189 ) ;
V_6 = F_4 ( V_14 -> V_2 , V_43 ,
V_3 , V_189 + 3 , V_44 ) ;
if ( V_6 < 0 )
break;
}
V_3 [ 0 ] = V_190 ;
V_3 [ 1 ] = 0 ;
F_4 ( V_14 -> V_2 , V_43 , V_3 , 2 ,
V_44 ) ;
V_160:
F_19 ( V_3 ) ;
return V_6 ;
}
static T_4 F_55 ( struct V_191 * V_19 , int V_192 ,
const char * V_3 , T_2 V_193 )
{
struct V_1 * V_2 = F_56 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
unsigned int V_42 ;
int V_194 ;
V_194 = F_57 ( V_3 , 10 , & V_42 ) ;
if ( V_194 )
return V_194 ;
F_44 ( & V_14 -> V_195 ) ;
V_14 -> V_165 . V_166 [ V_192 ] . V_174 = V_42 & 0x3 ;
V_194 = F_53 ( V_14 ) ;
F_46 ( & V_14 -> V_195 ) ;
return V_194 < 0 ? V_194 : V_193 ;
}
static T_4 F_58 ( struct V_14 * V_14 , T_1 * V_196 ,
const char * V_3 , T_2 V_193 )
{
unsigned int V_108 ;
int V_194 ;
V_194 = F_57 ( V_3 , 10 , & V_108 ) ;
if ( V_194 )
return V_194 ;
F_44 ( & V_14 -> V_195 ) ;
* V_196 = V_108 & 0x7f ;
V_194 = F_53 ( V_14 ) ;
F_46 ( & V_14 -> V_195 ) ;
return V_194 < 0 ? V_194 : V_193 ;
}
static T_4 F_59 ( struct V_191 * V_19 , int V_185 ,
const char * V_3 , T_2 V_193 )
{
struct V_1 * V_2 = F_56 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
int V_194 ;
unsigned V_187 ;
T_1 V_186 ;
if ( V_2 -> V_120 == V_121 ) {
V_187 = 256 ;
V_186 = V_197 ;
} else {
V_187 = 1024 ;
V_186 = V_198 ;
}
if ( V_193 != V_187 )
return - V_113 ;
F_44 ( & V_14 -> V_195 ) ;
V_194 = F_54 ( V_14 , V_185 , V_186 , V_187 , V_3 ) ;
F_46 ( & V_14 -> V_195 ) ;
return V_194 < 0 ? V_194 : V_193 ;
}
static void F_60 ( struct V_191 * V_19 , void * V_157 )
{
struct V_199 * V_200 = V_157 ;
struct V_201 * V_202 = V_200 -> V_203 ;
F_61 ( V_19 , L_10 ,
V_65 , V_200 -> V_204 -> V_205 ) ;
F_62 ( V_202 , V_200 -> V_204 ) ;
}
static int F_63 ( struct V_14 * V_14 ,
struct V_201 * V_203 ,
struct V_206 * V_204 )
{
struct V_199 * V_200 ;
int error ;
V_200 = F_64 ( F_60 ,
sizeof( struct V_199 ) ,
V_41 ) ;
if ( ! V_200 )
return - V_111 ;
V_200 -> V_204 = V_204 ;
V_200 -> V_203 = V_203 ;
error = F_65 ( V_200 -> V_203 , V_204 ) ;
if ( error )
return error ;
F_66 ( & V_14 -> V_2 -> V_19 , V_200 ) ;
return 0 ;
}
static int F_67 ( struct V_14 * V_14 ,
struct V_206 * V_204 )
{
return F_63 ( V_14 , & V_14 -> V_2 -> V_19 . V_202 ,
V_204 ) ;
}
enum V_207 F_68 ( struct V_208 * V_165 )
{
struct V_14 * V_14 = V_165 -> V_14 ;
if ( V_14 -> V_165 . V_209 )
return V_165 -> V_183 * V_210 / V_14 -> V_165 . V_209 ;
if ( V_14 -> V_165 . V_211 )
return V_165 -> V_173 * V_210 / V_14 -> V_165 . V_211 ;
return V_210 ;
}
static enum V_207 F_69 ( struct V_212 * V_213 )
{
struct V_208 * V_165 = F_43 ( V_213 , struct V_208 , V_213 ) ;
struct V_14 * V_14 = V_165 -> V_14 ;
if ( V_14 -> V_165 . V_166 [ V_165 -> V_204 ] . V_174 != V_165 -> V_42 )
return V_214 ;
return F_68 ( V_165 ) ;
}
static int F_70 ( struct V_212 * V_213 ,
enum V_207 V_215 )
{
struct V_208 * V_165 = F_43 ( V_213 , struct V_208 , V_213 ) ;
struct V_14 * V_14 = V_165 -> V_14 ;
int error ;
F_44 ( & V_14 -> V_195 ) ;
if ( ! V_14 -> V_165 . V_166 || ( V_215 == V_214 &&
V_14 -> V_165 . V_166 [ V_165 -> V_204 ] . V_174 != V_165 -> V_42 ) ) {
error = 0 ;
goto V_160;
}
V_165 -> V_173 = V_14 -> V_165 . V_173 = V_14 -> V_165 . V_211 * V_215 / V_210 ;
V_165 -> V_183 = V_14 -> V_165 . V_183 = V_14 -> V_165 . V_209 * V_215 / V_210 ;
V_14 -> V_165 . V_166 [ V_165 -> V_204 ] . V_174 = V_165 -> V_42 ;
error = F_53 ( V_14 ) ;
V_160:
F_46 ( & V_14 -> V_195 ) ;
return error ;
}
static void F_71 ( struct V_212 * V_213 ,
enum V_207 V_215 )
{
}
static int F_72 ( struct V_191 * V_19 , struct V_14 * V_14 ,
struct V_208 * V_165 , unsigned int V_204 ,
unsigned int V_42 , bool V_216 )
{
int error ;
char * V_205 ;
V_205 = F_73 ( V_19 , V_41 ,
L_11 ,
F_74 ( V_19 ) ,
V_204 ,
V_42 ) ;
if ( ! V_205 )
return - V_111 ;
if ( ! V_216 ) {
V_165 -> V_217 . V_205 = V_205 ;
error = F_75 ( V_19 , & V_165 -> V_217 ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_12 ,
V_165 -> V_213 . V_205 , error ) ;
return error ;
}
}
V_165 -> V_204 = V_204 ;
V_165 -> V_42 = V_42 ;
V_165 -> V_14 = V_14 ;
V_165 -> V_173 = V_14 -> V_165 . V_173 ;
V_165 -> V_183 = V_14 -> V_165 . V_183 ;
V_165 -> V_213 . V_205 = V_205 ;
V_165 -> V_213 . V_218 = V_210 ;
V_165 -> V_213 . V_219 = V_220 ;
V_165 -> V_213 . V_221 = F_69 ;
if ( ! V_216 ) {
V_165 -> V_213 . V_222 = F_70 ;
V_165 -> V_213 . V_223 = V_165 -> V_213 . V_205 ;
} else {
V_165 -> V_213 . V_224 = F_71 ;
}
error = F_76 ( V_19 , & V_165 -> V_213 ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_13 ,
V_165 -> V_213 . V_205 , error ) ;
V_165 -> V_213 . V_205 = NULL ;
return error ;
}
return 0 ;
}
static void F_77 ( void * V_17 )
{
struct V_225 * V_204 = V_17 ;
F_78 ( V_204 -> V_19 , V_204 ) ;
}
static int F_79 ( struct V_191 * V_19 ,
struct V_14 * V_14 ,
int V_226 , int V_193 ,
bool V_216 )
{
struct V_208 * V_227 ;
int V_76 , error ;
if ( V_226 >= V_14 -> V_165 . V_193 || V_193 <= 0 )
return - V_113 ;
if ( ! F_80 ( V_19 , & V_14 -> V_165 . V_166 [ V_226 ] , V_41 ) )
return - V_111 ;
V_227 = F_81 ( V_19 , sizeof( struct V_208 ) * V_193 , V_41 ) ;
if ( ! V_227 ) {
error = - V_111 ;
goto V_194;
}
V_14 -> V_165 . V_166 [ V_226 ] . V_227 = V_227 ;
V_14 -> V_165 . V_166 [ V_226 ] . V_193 = V_193 ;
for ( V_76 = 0 ; V_76 < V_193 ; V_76 ++ ) {
error = F_72 ( V_19 , V_14 , & V_227 [ V_76 ] ,
V_226 , V_76 , V_216 ) ;
if ( error )
goto V_194;
}
V_14 -> V_165 . V_166 [ V_226 ] . V_19 = V_19 ;
F_82 ( V_19 , & V_14 -> V_165 . V_166 [ V_226 ] ) ;
error = F_83 ( & V_14 -> V_2 -> V_19 ,
F_77 ,
& V_14 -> V_165 . V_166 [ V_226 ] ) ;
if ( error )
return error ;
return 0 ;
V_194:
F_78 ( V_19 , & V_14 -> V_165 . V_166 [ V_226 ] ) ;
return error ;
}
struct V_208 * F_84 ( struct V_14 * V_14 , unsigned int V_226 ,
unsigned int V_42 )
{
struct V_225 * V_204 ;
if ( V_226 >= V_14 -> V_165 . V_193 )
return NULL ;
V_204 = & V_14 -> V_165 . V_166 [ V_226 ] ;
if ( ! V_204 -> V_227 )
return NULL ;
V_42 %= V_204 -> V_193 ;
return & V_204 -> V_227 [ V_42 ] ;
}
struct V_208 * F_85 ( struct V_14 * V_14 , struct V_208 * V_228 )
{
struct V_208 * V_229 ;
int V_204 , V_230 ;
if ( ! V_14 || ! V_228 )
return NULL ;
V_204 = V_228 -> V_204 ;
V_230 = V_228 -> V_42 ;
do {
V_229 = F_84 ( V_14 , V_204 , ++ V_230 ) ;
if ( ! V_229 || V_229 == V_228 )
return V_229 ;
} while ( V_229 -> V_213 . V_217 != & V_229 -> V_217 );
return V_229 ;
}
static void F_86 ( void * V_17 )
{
struct V_14 * V_14 = V_17 ;
V_14 -> V_165 . V_166 = NULL ;
V_14 -> V_165 . V_193 = 0 ;
}
static int F_87 ( struct V_14 * V_14 , int V_193 )
{
struct V_191 * V_19 = & V_14 -> V_2 -> V_19 ;
struct V_225 * V_166 ;
int error ;
V_166 = F_81 ( V_19 , sizeof( struct V_225 ) * V_193 ,
V_41 ) ;
if ( ! V_166 )
return - V_111 ;
error = F_83 ( V_19 , F_86 , V_14 ) ;
if ( error )
return error ;
V_14 -> V_165 . V_166 = V_166 ;
V_14 -> V_165 . V_193 = V_193 ;
return 0 ;
}
static int F_88 ( struct V_14 * V_14 , int V_231 ,
int V_232 , bool V_216 )
{
struct V_191 * V_19 ;
int V_76 , error ;
if ( ! V_14 -> V_16 . V_233 )
return - V_113 ;
V_19 = & V_14 -> V_16 . V_233 -> V_19 ;
error = F_87 ( V_14 , V_231 ) ;
if ( error )
return error ;
for ( V_76 = 0 ; V_76 < V_231 ; V_76 ++ ) {
error = F_79 ( V_19 , V_14 , V_76 ,
V_232 ,
V_216 ) ;
if ( error )
return error ;
}
return 0 ;
}
int F_89 ( struct V_14 * V_14 )
{
int error ;
if ( ! ( V_14 -> V_16 . V_33 . V_68 & V_234 ) )
return 0 ;
switch ( V_14 -> V_16 . V_33 . type ) {
case V_72 :
if ( ! V_14 -> V_235 )
return 0 ;
V_14 -> V_165 . V_173 = 100 ;
V_14 -> V_165 . V_211 = 100 ;
error = F_88 ( V_14 , 1 , 4 , false ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_14 , error ) ;
return error ;
}
error = F_67 ( V_14 ,
& V_236 ) ;
break;
case V_237 :
case V_238 :
case V_118 :
case V_239 :
V_14 -> V_165 . V_173 = 10 ;
V_14 -> V_165 . V_183 = 20 ;
V_14 -> V_165 . V_211 = 127 ;
V_14 -> V_165 . V_209 = 127 ;
V_14 -> V_165 . V_184 = 10 ;
error = F_88 ( V_14 , 1 , 4 , false ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_14 , error ) ;
return error ;
}
error = F_67 ( V_14 ,
& V_240 ) ;
break;
case V_182 :
case V_181 :
V_14 -> V_165 . V_173 = 0 ;
V_14 -> V_165 . V_183 = 0 ;
V_14 -> V_165 . V_184 = 0 ;
error = F_88 ( V_14 , 2 , 4 , false ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_14 , error ) ;
return error ;
}
error = F_67 ( V_14 ,
& V_241 ) ;
break;
case V_175 :
case V_242 :
case V_243 :
case V_244 :
case V_245 :
case V_176 :
V_14 -> V_165 . V_173 = 32 ;
V_14 -> V_165 . V_211 = 96 ;
error = F_88 ( V_14 , 1 , 4 , false ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_14 , error ) ;
return error ;
}
error = F_67 ( V_14 ,
& V_246 ) ;
break;
case V_170 :
V_14 -> V_165 . V_173 = 50 ;
V_14 -> V_165 . V_211 = 100 ;
error = F_88 ( V_14 , 1 , 4 , false ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_14 , error ) ;
return error ;
}
return 0 ;
case V_247 :
V_14 -> V_165 . V_173 = 255 ;
V_14 -> V_165 . V_211 = 255 ;
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
static void F_90 ( struct V_248 * V_249 )
{
struct V_14 * V_14 = F_43 ( V_249 , struct V_14 , V_250 . V_249 ) ;
F_36 ( V_14 ) ;
F_53 ( V_14 ) ;
}
static void F_91 ( struct V_14 * V_14 )
{
F_92 ( & V_14 -> V_250 , F_93 ( 1000 ) ) ;
}
static int F_94 ( struct V_251 * V_252 ,
enum V_253 V_254 ,
union V_255 * V_256 )
{
struct V_257 * V_258 = F_95 ( V_252 ) ;
int V_37 = 0 ;
switch ( V_254 ) {
case V_259 :
V_256 -> V_260 = V_258 -> V_14 -> V_16 . V_205 ;
break;
case V_261 :
V_256 -> V_262 = V_258 -> V_263 ;
break;
case V_264 :
V_256 -> V_262 = V_265 ;
break;
case V_266 :
V_256 -> V_262 = V_258 -> V_267 ;
break;
case V_268 :
if ( V_258 -> V_269 )
V_256 -> V_262 = V_270 ;
else if ( V_258 -> V_267 == 100 &&
V_258 -> V_271 )
V_256 -> V_262 = V_272 ;
else if ( V_258 -> V_271 )
V_256 -> V_262 = V_273 ;
else
V_256 -> V_262 = V_274 ;
break;
default:
V_37 = - V_113 ;
break;
}
return V_37 ;
}
static int F_96 ( struct V_14 * V_14 ,
struct V_257 * V_258 )
{
static T_5 V_275 = F_97 ( 0 ) ;
struct V_191 * V_19 = & V_14 -> V_2 -> V_19 ;
struct V_276 V_277 = { . V_278 = V_258 , } ;
struct V_251 * V_279 ;
struct V_280 * V_281 = & V_258 -> V_281 ;
unsigned long V_38 ;
int error ;
if ( ! F_80 ( V_19 , V_281 , V_41 ) )
return - V_111 ;
V_258 -> V_14 = V_14 ;
V_38 = F_98 ( & V_275 ) - 1 ;
V_281 -> V_282 = V_283 ;
V_281 -> V_284 = F_99 ( V_283 ) ;
V_281 -> V_285 = F_94 ;
sprintf ( V_258 -> V_286 , L_16 , V_38 ) ;
V_281 -> V_205 = V_258 -> V_286 ;
V_281 -> type = V_287 ;
V_281 -> V_288 = 0 ;
V_279 = F_100 ( V_19 , V_281 , & V_277 ) ;
if ( F_101 ( V_279 ) ) {
error = F_102 ( V_279 ) ;
goto V_194;
}
F_103 ( V_279 , & V_14 -> V_2 -> V_19 ) ;
V_258 -> V_258 = V_279 ;
F_82 ( V_19 , V_281 ) ;
return 0 ;
V_194:
F_78 ( V_19 , V_281 ) ;
return error ;
}
static int F_104 ( struct V_14 * V_14 )
{
if ( V_14 -> V_16 . V_33 . V_289 & V_290 )
return F_96 ( V_14 , & V_14 -> V_258 ) ;
return 0 ;
}
static void F_105 ( struct V_14 * V_14 )
{
if ( V_14 -> V_258 . V_258 ) {
F_78 ( & V_14 -> V_2 -> V_19 ,
& V_14 -> V_258 . V_281 ) ;
V_14 -> V_258 . V_258 = NULL ;
}
}
static T_4 F_106 ( struct V_191 * V_19 ,
struct V_291
* V_292 , char * V_3 )
{
struct V_1 * V_2 = F_56 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
return snprintf ( V_3 , V_293 , L_17 , V_14 -> V_16 . V_117 ) ;
}
static T_4 F_107 ( struct V_191 * V_19 ,
struct V_291 * V_292 ,
const char * V_3 , T_2 V_193 )
{
struct V_1 * V_2 = F_56 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
T_1 V_294 ;
if ( F_108 ( V_3 , 0 , & V_294 ) )
return - V_113 ;
if ( V_294 != 0 && V_294 != 1 )
return - V_113 ;
F_35 ( V_2 , V_294 , & V_14 -> V_16 . V_33 ) ;
return V_193 ;
}
static T_4 F_109 ( struct V_201 * V_202 ,
struct V_295 * V_296 ,
char * V_3 , int V_297 )
{
struct V_191 * V_19 = F_110 ( V_202 -> V_298 ) ;
struct V_1 * V_2 = F_56 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
T_1 V_299 ;
V_299 = V_14 -> V_165 . V_166 [ V_297 ] . V_174 ;
if ( V_299 >= 0 && V_299 < 3 )
return snprintf ( V_3 , V_293 , L_18 , V_299 ) ;
else
return snprintf ( V_3 , V_293 , L_18 , - 1 ) ;
}
static int F_111 ( struct V_14 * V_14 , T_3 V_300 ,
int V_297 )
{
int error = 0 ;
struct V_301 * V_302 = V_14 -> V_302 ;
V_302 -> V_303 [ V_297 ] . V_204 . V_205 = F_73 ( & V_14 -> V_2 -> V_19 ,
V_41 ,
L_19 , V_300 ) ;
if ( ! V_302 -> V_303 [ V_297 ] . V_204 . V_205 )
return - V_111 ;
error = F_63 ( V_14 , V_302 -> V_304 ,
& V_302 -> V_303 [ V_297 ] . V_204 ) ;
if ( error ) {
V_302 -> V_303 [ V_297 ] . V_204 . V_205 = NULL ;
F_3 ( V_14 -> V_2 ,
L_15 , error ) ;
return error ;
}
return 0 ;
}
static int F_112 ( struct V_14 * V_14 , unsigned char V_305 )
{
const T_2 V_164 = 2 ;
unsigned char * V_3 ;
int V_6 ;
V_3 = F_17 ( V_164 , V_41 ) ;
if ( ! V_3 )
return - V_111 ;
V_3 [ 0 ] = V_306 ;
V_3 [ 1 ] = V_305 ;
V_6 = F_4 ( V_14 -> V_2 , V_307 , V_3 ,
V_164 , V_44 ) ;
F_19 ( V_3 ) ;
return V_6 ;
}
static T_4 F_113 ( struct V_201 * V_202 ,
struct V_295 * V_292 ,
const char * V_3 , T_2 V_193 )
{
unsigned char V_305 = 0 ;
struct V_191 * V_19 = F_110 ( V_202 -> V_298 ) ;
struct V_1 * V_2 = F_56 ( V_19 ) ;
struct V_14 * V_14 = F_6 ( V_2 ) ;
int V_194 ;
if ( ! strncmp ( V_3 , L_20 , 2 ) ) {
V_305 = V_308 ;
} else {
F_114 ( V_14 -> V_2 , L_21 ,
V_3 ) ;
return - 1 ;
}
F_44 ( & V_14 -> V_195 ) ;
V_194 = F_112 ( V_14 , V_305 ) ;
F_46 ( & V_14 -> V_195 ) ;
return V_194 < 0 ? V_194 : V_193 ;
}
static void F_115 ( void * V_17 )
{
struct V_14 * V_14 = V_17 ;
struct V_301 * V_302 = V_14 -> V_302 ;
if ( ! V_302 )
return;
F_116 ( V_302 -> V_304 ) ;
F_117 ( & V_302 -> V_309 ) ;
V_14 -> V_302 = NULL ;
}
static int F_118 ( struct V_14 * V_14 )
{
int error = 0 ;
struct V_301 * V_302 ;
int V_76 ;
if ( V_14 -> V_16 . V_33 . type != V_247 )
return 0 ;
V_302 = F_81 ( & V_14 -> V_2 -> V_19 , sizeof( * V_14 -> V_302 ) ,
V_41 ) ;
if ( ! V_302 )
return - V_111 ;
V_14 -> V_302 = V_302 ;
F_119 ( & V_302 -> V_310 ) ;
error = F_120 ( & V_302 -> V_309 ,
5 * sizeof( struct V_311 ) ,
V_41 ) ;
if ( error ) {
F_3 ( V_14 -> V_2 , L_22 ) ;
return - V_111 ;
}
V_302 -> V_303 [ 0 ] . V_204 = V_312 ;
V_302 -> V_303 [ 1 ] . V_204 = V_313 ;
V_302 -> V_303 [ 2 ] . V_204 = V_314 ;
V_302 -> V_303 [ 3 ] . V_204 = V_315 ;
V_302 -> V_303 [ 4 ] . V_204 = V_316 ;
V_302 -> V_304 = F_121 ( L_23 ,
& V_14 -> V_2 -> V_19 . V_202 ) ;
if ( ! V_302 -> V_304 )
return - V_111 ;
error = F_122 ( V_302 -> V_304 , V_317 ) ;
if ( error ) {
F_3 ( V_14 -> V_2 ,
L_15 , error ) ;
return error ;
}
for ( V_76 = 0 ; V_76 < V_318 ; V_76 ++ ) {
V_14 -> V_165 . V_166 [ V_76 ] . V_174 = V_319 ;
V_302 -> V_303 [ V_76 ] . V_300 = 0 ;
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
V_18 -> V_205 = V_16 -> V_33 . V_205 ;
V_18 -> V_143 = V_2 -> V_143 ;
V_18 -> V_19 . V_298 = & V_2 -> V_19 ;
V_18 -> V_320 = F_8 ;
V_18 -> V_321 = F_11 ;
V_18 -> V_322 = V_2 -> V_322 ;
V_18 -> V_42 . V_323 = V_2 -> V_120 ;
V_18 -> V_42 . V_149 = V_2 -> V_149 ;
V_18 -> V_42 . V_151 = V_16 -> V_168 ? V_16 -> V_168 : V_2 -> V_151 ;
V_18 -> V_42 . V_324 = V_2 -> V_324 ;
F_125 ( V_18 , V_14 ) ;
return V_18 ;
}
static int F_126 ( struct V_14 * V_14 )
{
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
V_16 -> V_325 = F_123 ( V_14 ) ;
V_16 -> V_95 = F_123 ( V_14 ) ;
V_16 -> V_233 = F_123 ( V_14 ) ;
if ( ! V_16 -> V_325 ||
! V_16 -> V_95 ||
! V_16 -> V_233 )
return - V_111 ;
V_16 -> V_325 -> V_205 = V_16 -> V_326 ;
V_16 -> V_95 -> V_205 = V_16 -> V_327 ;
V_16 -> V_233 -> V_205 = V_16 -> V_328 ;
return 0 ;
}
static int F_127 ( struct V_14 * V_14 )
{
struct V_18 * V_329 , * V_330 , * V_331 ;
struct V_16 * V_16 = & ( V_14 -> V_16 ) ;
int error = 0 ;
V_329 = V_16 -> V_325 ;
V_330 = V_16 -> V_95 ;
V_331 = V_16 -> V_233 ;
if ( ! V_329 || ! V_330 || ! V_331 )
return - V_113 ;
error = F_128 ( V_329 , V_16 ) ;
if ( error ) {
F_129 ( V_329 ) ;
V_16 -> V_325 = NULL ;
V_329 = NULL ;
} else {
error = F_130 ( V_329 ) ;
if ( error )
goto V_332;
}
error = F_131 ( V_330 , V_16 ) ;
if ( error ) {
F_129 ( V_330 ) ;
V_16 -> V_95 = NULL ;
V_330 = NULL ;
} else {
error = F_130 ( V_330 ) ;
if ( error )
goto V_332;
}
error = F_132 ( V_331 , V_16 ) ;
if ( error ) {
F_129 ( V_331 ) ;
V_16 -> V_233 = NULL ;
V_331 = NULL ;
} else {
error = F_130 ( V_331 ) ;
if ( error )
goto V_332;
}
return 0 ;
V_332:
V_16 -> V_233 = NULL ;
V_16 -> V_95 = NULL ;
V_16 -> V_325 = NULL ;
return error ;
}
static void F_133 ( struct V_32 * V_33 )
{
if ( V_33 -> V_333 ) {
V_33 -> V_86 = ( V_33 -> V_85 * 100 ) /
V_33 -> V_333 ;
V_33 -> V_91 = ( V_33 -> V_90 * 100 ) /
V_33 -> V_334 ;
}
}
static void F_134 ( struct V_32 * V_33 )
{
if ( ! V_33 -> V_22 ) {
V_33 -> V_22 = 0x11 ;
V_33 -> V_88 = - 3 ;
}
V_33 -> V_333 = F_13 ( V_33 -> V_85 ,
V_33 -> V_86 ,
V_33 -> V_22 ,
V_33 -> V_88 ) ;
V_33 -> V_334 = F_13 ( V_33 -> V_90 ,
V_33 -> V_91 ,
V_33 -> V_22 ,
V_33 -> V_88 ) ;
}
void F_135 ( struct V_248 * V_249 )
{
struct V_14 * V_14 = F_43 ( V_249 , struct V_14 , V_335 ) ;
if ( ( V_14 -> V_16 . V_33 . V_289 & V_290 ) &&
! V_14 -> V_258 . V_258 ) {
F_104 ( V_14 ) ;
}
else if ( ! ( V_14 -> V_16 . V_33 . V_289 & V_290 ) &&
V_14 -> V_258 . V_258 ) {
F_105 ( V_14 ) ;
}
}
static T_2 F_136 ( struct V_1 * V_2 )
{
struct V_98 * V_102 ;
struct V_11 * V_12 ;
T_2 V_4 = 0 ;
V_102 = V_2 -> V_102 + V_104 ;
F_31 (report, &report_enum->report_list, list) {
T_2 V_336 = F_21 ( V_12 ) ;
if ( V_336 > V_4 )
V_4 = V_336 ;
}
return V_4 ;
}
static void F_137 ( struct V_14 * V_14 , const char * V_337 )
{
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_32 * V_33 = & V_16 -> V_33 ;
char V_205 [ V_338 ] ;
if ( ( V_33 -> type == V_72 ) && ! strcmp ( L_24 , V_33 -> V_205 ) ) {
if ( strstr ( V_14 -> V_2 -> V_205 , L_25 ) ||
strstr ( V_14 -> V_2 -> V_205 , L_26 ) ||
strstr ( V_14 -> V_2 -> V_205 , L_27 ) ) {
F_138 ( V_205 , V_14 -> V_2 -> V_205 , sizeof( V_205 ) ) ;
while ( 1 ) {
char * V_339 = strstr ( V_205 , L_28 ) ;
if ( V_339 == NULL )
break;
memmove ( V_339 , V_339 + 1 , strlen ( V_339 ) ) ;
}
if ( strstr ( V_205 , L_29 ) == V_205 ) {
int V_38 = strlen ( V_205 ) ;
int V_340 = strlen ( L_30 ) ;
memmove ( V_205 , V_205 + V_340 , V_38 - V_340 + 1 ) ;
}
if ( strstr ( V_205 , L_31 ) == V_205 ) {
int V_38 = strlen ( V_205 ) ;
int V_340 = strlen ( L_32 ) ;
memmove ( V_205 , V_205 + V_340 , V_38 - V_340 + 1 ) ;
}
if ( V_205 [ strlen ( V_205 ) - 1 ] == ' ' )
V_205 [ strlen ( V_205 ) - 1 ] = '\0' ;
} else {
snprintf ( V_205 , sizeof( V_205 ) ,
L_33 , V_33 -> V_205 , V_14 -> V_2 -> V_151 ) ;
}
} else {
F_138 ( V_205 , V_33 -> V_205 , sizeof( V_205 ) ) ;
}
snprintf ( V_16 -> V_205 , sizeof( V_16 -> V_205 ) , L_34 ,
V_205 , V_337 ) ;
snprintf ( V_16 -> V_326 , sizeof( V_16 -> V_326 ) ,
L_35 , V_205 , V_337 ) ;
snprintf ( V_16 -> V_327 , sizeof( V_16 -> V_327 ) ,
L_36 , V_205 , V_337 ) ;
snprintf ( V_16 -> V_328 , sizeof( V_16 -> V_328 ) ,
L_37 , V_205 , V_337 ) ;
}
static void F_139 ( struct V_14 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
if ( ! V_14 -> V_341 )
return;
F_78 ( & V_2 -> V_19 , V_14 ) ;
V_14 -> V_341 = false ;
V_14 -> V_16 . V_325 = NULL ;
V_14 -> V_16 . V_95 = NULL ;
V_14 -> V_16 . V_233 = NULL ;
}
static void F_140 ( struct V_16 * V_16 )
{
if ( V_16 -> V_33 . V_68 & V_70 ) {
V_16 -> V_158 -> type = V_16 -> V_33 . type ;
V_16 -> V_158 -> V_95 = V_16 -> V_95 ;
}
if ( V_16 -> V_342 )
V_16 -> V_158 -> V_342 = true ;
if ( V_16 -> V_158 -> V_342 &&
V_16 -> V_158 -> V_95 ) {
F_141 ( V_343 , V_16 -> V_158 -> V_95 -> V_344 ) ;
F_142 ( V_16 -> V_158 -> V_95 , V_343 ,
V_345 ) ;
}
}
static int F_143 ( struct V_14 * V_14 , bool V_346 )
{
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_32 * V_33 = & V_16 -> V_33 ;
struct V_1 * V_2 = V_14 -> V_2 ;
int error ;
unsigned int V_347 = V_348 ;
V_33 -> V_349 = F_136 ( V_2 ) ;
if ( V_33 -> V_349 > V_15 )
return - V_113 ;
if ( ! F_80 ( & V_2 -> V_19 , V_14 , V_41 ) )
return - V_111 ;
V_14 -> V_341 = true ;
error = F_126 ( V_14 ) ;
if ( error )
goto V_332;
if ( V_33 -> type == V_125 ) {
if ( V_33 -> V_349 == V_350 ) {
V_33 -> type = V_72 ;
} else if ( ( V_33 -> V_349 != V_351 ) &&
( V_33 -> V_349 != V_352 ) ) {
error = - V_353 ;
goto V_332;
}
}
F_133 ( V_33 ) ;
F_37 ( V_2 , V_33 ) ;
F_144 ( V_14 ) ;
if ( V_33 -> V_68 == V_138 &&
V_33 -> type != V_133 ) {
error = V_33 -> type == V_72 ? - V_353 : 0 ;
F_145 ( & V_2 -> V_19 , L_38 ,
V_2 -> V_205 ,
error ? L_39 : L_40 ) ;
if ( error )
goto V_332;
V_33 -> V_68 |= V_69 ;
}
F_134 ( V_33 ) ;
F_137 ( V_14 , V_346 ? L_41 : L_42 ) ;
if ( ( V_33 -> type == V_354 ) &&
( ( V_33 -> V_68 & V_70 ) ||
( V_33 -> V_68 & V_234 ) ) ) {
error = - V_353 ;
goto V_332;
}
error = F_49 ( V_2 ) ;
if ( error )
goto V_332;
if ( ! ( V_33 -> V_68 & V_137 ) &&
( V_33 -> V_289 & V_290 ) ) {
error = F_104 ( V_14 ) ;
if ( error )
goto V_332;
}
error = F_127 ( V_14 ) ;
if ( error )
goto V_332;
if ( V_14 -> V_16 . V_33 . V_68 & V_234 ) {
error = F_89 ( V_14 ) ;
if ( error )
goto V_332;
error = F_118 ( V_14 ) ;
if ( error )
goto V_332;
}
if ( V_33 -> type == V_72 )
V_347 |= V_355 ;
error = F_146 ( V_2 , V_347 ) ;
if ( error ) {
F_3 ( V_2 , L_43 ) ;
goto V_332;
}
if ( ! V_346 ) {
F_91 ( V_14 ) ;
}
if ( ( V_33 -> type == V_87 ) &&
( V_33 -> V_68 & V_69 ) ) {
F_147 ( & V_14 -> V_250 ) ;
F_36 ( V_14 ) ;
error = - V_353 ;
goto V_356;
}
if ( V_33 -> V_68 & V_137 )
error = F_10 ( V_2 ) ;
F_140 ( V_16 ) ;
F_82 ( & V_2 -> V_19 , V_14 ) ;
return 0 ;
V_356:
F_148 ( V_2 ) ;
V_332:
F_139 ( V_14 ) ;
return error ;
}
static void F_149 ( struct V_248 * V_249 )
{
struct V_14 * V_14 = F_43 ( V_249 , struct V_14 , V_357 ) ;
struct V_358 * V_359 = V_14 -> V_359 ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_1 * V_360 , * V_361 ;
struct V_14 * V_362 , * V_363 ;
struct V_16 * V_364 , * V_365 ;
int error ;
F_105 ( V_14 ) ;
V_360 = F_150 ( V_359 -> V_366 -> V_367 [ 1 ] ) ;
V_362 = F_6 ( V_360 ) ;
V_364 = & ( V_362 -> V_16 ) ;
F_139 ( V_362 ) ;
V_361 = F_150 ( V_359 -> V_366 -> V_367 [ 2 ] ) ;
V_363 = F_6 ( V_361 ) ;
V_365 = & ( V_363 -> V_16 ) ;
F_139 ( V_363 ) ;
if ( V_16 -> V_168 == 0 ) {
F_114 ( V_14 -> V_2 , L_44 ) ;
} else {
const struct V_368 * V_42 = V_369 ;
F_114 ( V_14 -> V_2 , L_45 ,
V_16 -> V_168 ) ;
while ( V_42 -> V_120 ) {
if ( V_42 -> V_149 == V_370 &&
V_42 -> V_151 == V_16 -> V_168 )
break;
V_42 ++ ;
}
if ( ! V_42 -> V_120 ) {
F_114 ( V_14 -> V_2 , L_46 ) ;
return;
}
V_364 -> V_33 =
* ( (struct V_32 * ) V_42 -> V_371 ) ;
V_364 -> V_168 = V_16 -> V_168 ;
F_148 ( V_360 ) ;
error = F_143 ( V_362 , true ) ;
if ( error )
goto V_332;
if ( V_364 -> V_33 . V_40 ||
( V_364 -> V_33 . type >= V_372 &&
V_364 -> V_33 . type <= V_71 ) ) {
V_365 -> V_33 =
* ( (struct V_32 * ) V_42 -> V_371 ) ;
V_365 -> V_168 = V_16 -> V_168 ;
F_148 ( V_361 ) ;
error = F_143 ( V_363 , true ) ;
if ( error )
goto V_332;
}
F_138 ( V_16 -> V_205 , V_364 -> V_205 ,
sizeof( V_16 -> V_205 ) ) ;
error = F_104 ( V_14 ) ;
if ( error )
goto V_332;
}
return;
V_332:
F_139 ( V_362 ) ;
F_139 ( V_363 ) ;
return;
}
static void F_151 ( struct V_14 * V_14 , unsigned int V_297 )
{
struct V_301 * V_302 = V_14 -> V_302 ;
T_6 V_300 = V_302 -> V_303 [ V_297 ] . V_300 ;
int V_76 ;
unsigned long V_219 ;
F_152 ( & V_302 -> V_310 , V_219 ) ;
V_302 -> V_303 [ V_297 ] . V_373 = false ;
F_153 ( & V_302 -> V_310 , V_219 ) ;
if ( V_302 -> V_303 [ V_297 ] . V_258 . V_258 )
F_78 ( & V_14 -> V_2 -> V_19 ,
& V_302 -> V_303 [ V_297 ] . V_258 . V_281 ) ;
if ( V_302 -> V_303 [ V_297 ] . V_204 . V_205 )
F_78 ( & V_14 -> V_2 -> V_19 ,
& V_302 -> V_303 [ V_297 ] ) ;
for ( V_76 = 0 ; V_76 < V_318 ; V_76 ++ ) {
if ( V_302 -> V_303 [ V_76 ] . V_300 == V_300 ) {
V_302 -> V_303 [ V_76 ] . V_300 = 0 ;
V_302 -> V_303 [ V_76 ] . V_204 . V_205 = NULL ;
V_302 -> V_303 [ V_76 ] . V_373 = false ;
V_302 -> V_303 [ V_76 ] . V_258 . V_258 = NULL ;
V_14 -> V_165 . V_166 [ V_76 ] . V_174 = V_319 ;
}
}
}
static int F_154 ( struct V_14 * V_14 , T_6 V_300 ,
unsigned int V_297 )
{
struct V_301 * V_302 = V_14 -> V_302 ;
struct V_191 * V_19 = & V_14 -> V_2 -> V_19 ;
int error , V_374 ;
for ( V_374 = 0 ; V_374 < V_318 ; V_374 ++ ) {
if ( V_302 -> V_303 [ V_374 ] . V_300 == V_300 )
break;
}
if ( V_374 < V_318 ) {
V_302 -> V_303 [ V_297 ] . V_300 = V_300 ;
return 0 ;
}
if ( ! F_80 ( V_19 , & V_302 -> V_303 [ V_297 ] , V_41 ) )
return - V_111 ;
error = F_111 ( V_14 , V_300 , V_297 ) ;
if ( error )
goto V_332;
V_302 -> V_303 [ V_297 ] . V_375 = F_123 ( V_14 ) ;
if ( ! V_302 -> V_303 [ V_297 ] . V_375 ) {
error = - V_111 ;
goto V_332;
}
V_302 -> V_303 [ V_297 ] . V_375 -> V_322 = V_302 -> V_303 [ V_297 ] . V_204 . V_205 ;
V_302 -> V_303 [ V_297 ] . V_375 -> V_205 = V_14 -> V_16 . V_328 ;
if ( ! V_302 -> V_303 [ V_297 ] . V_375 -> V_205 ) {
error = - V_113 ;
goto V_332;
}
error = F_132 ( V_302 -> V_303 [ V_297 ] . V_375 ,
& V_14 -> V_16 ) ;
if ( error )
goto V_332;
V_302 -> V_303 [ V_297 ] . V_300 = V_300 ;
error = F_130 ( V_302 -> V_303 [ V_297 ] . V_375 ) ;
if ( error )
goto V_332;
error = F_79 (
& V_302 -> V_303 [ V_297 ] . V_375 -> V_19 ,
V_14 , V_297 , 3 , true ) ;
if ( error )
goto V_332;
V_302 -> V_303 [ V_297 ] . V_373 = true ;
F_82 ( V_19 , & V_302 -> V_303 [ V_297 ] ) ;
return 0 ;
V_332:
F_78 ( V_19 , & V_302 -> V_303 [ V_297 ] ) ;
V_302 -> V_303 [ V_297 ] . V_300 = 0 ;
return error ;
}
static int F_155 ( struct V_14 * V_14 , int V_297 )
{
struct V_301 * V_302 = V_14 -> V_302 ;
int error ;
if ( ! V_302 -> V_303 [ V_297 ] . V_373 )
return 0 ;
if ( V_302 -> V_303 [ V_297 ] . V_258 . V_258 )
return 0 ;
if ( V_14 -> V_165 . V_166 [ V_297 ] . V_174 == V_319 )
return 0 ;
error = F_96 ( V_14 ,
& V_14 -> V_302 -> V_303 [ V_297 ] . V_258 ) ;
if ( error )
return error ;
return 0 ;
}
static void F_156 ( struct V_248 * V_249 )
{
struct V_14 * V_14 = F_43 ( V_249 , struct V_14 , V_376 ) ;
struct V_301 * V_302 = V_14 -> V_302 ;
struct V_311 V_17 ;
unsigned long V_219 ;
unsigned int V_193 ;
T_6 V_300 ;
int V_76 ;
F_152 ( & V_302 -> V_310 , V_219 ) ;
V_193 = F_157 ( & V_302 -> V_309 , & V_17 , sizeof( V_17 ) ) ;
if ( V_193 != sizeof( V_17 ) ) {
F_3 ( V_14 -> V_2 ,
L_47 ) ;
F_153 ( & V_302 -> V_310 , V_219 ) ;
return;
}
if ( ! F_158 ( & V_302 -> V_309 ) )
F_159 ( & V_14 -> V_16 , V_377 ) ;
F_153 ( & V_302 -> V_310 , V_219 ) ;
for ( V_76 = 0 ; V_76 < V_318 ; V_76 ++ ) {
V_300 = V_17 . V_302 [ V_76 ] . V_300 ;
if ( V_17 . V_302 [ V_76 ] . V_378 ) {
if ( V_302 -> V_303 [ V_76 ] . V_300 == V_300 ) {
F_155 ( V_14 , V_76 ) ;
continue;
}
if ( V_302 -> V_303 [ V_76 ] . V_300 )
F_151 ( V_14 , V_76 ) ;
F_154 ( V_14 , V_300 , V_76 ) ;
} else if ( V_302 -> V_303 [ V_76 ] . V_300 ) {
F_151 ( V_14 , V_76 ) ;
}
}
}
static int F_160 ( struct V_1 * V_2 ,
const struct V_368 * V_42 )
{
struct V_126 * V_127 = F_161 ( V_2 -> V_19 . V_298 ) ;
struct V_358 * V_19 = F_162 ( V_127 ) ;
struct V_14 * V_14 ;
struct V_16 * V_16 ;
struct V_32 * V_33 ;
int error ;
if ( ! V_42 -> V_371 )
return - V_113 ;
V_2 -> V_289 |= V_379 ;
V_2 -> V_289 &= ~ V_380 ;
V_14 = F_81 ( & V_2 -> V_19 , sizeof( struct V_14 ) , V_41 ) ;
if ( ! V_14 )
return - V_111 ;
F_163 ( V_2 , V_14 ) ;
V_14 -> V_2 = V_2 ;
V_16 = & V_14 -> V_16 ;
V_16 -> V_33 = * ( (struct V_32 * ) V_42 -> V_371 ) ;
V_33 = & V_16 -> V_33 ;
if ( V_33 -> V_381 && V_33 -> V_382 != V_2 -> type ) {
error = - V_353 ;
goto V_332;
}
V_16 -> V_34 . V_48 = - 1 ;
V_16 -> V_54 = - 1 ;
V_14 -> V_359 = V_19 ;
V_14 -> V_127 = V_127 ;
F_164 ( & V_14 -> V_195 ) ;
F_165 ( & V_14 -> V_250 , F_90 ) ;
F_166 ( & V_14 -> V_357 , F_149 ) ;
F_166 ( & V_14 -> V_335 , F_135 ) ;
F_166 ( & V_14 -> V_376 , F_156 ) ;
error = F_167 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_48 ) ;
goto V_332;
}
error = F_143 ( V_14 , false ) ;
if ( error )
goto V_332;
if ( V_2 -> V_120 == V_121 ) {
error = F_168 ( & V_2 -> V_19 , & V_383 ) ;
if ( error )
F_18 ( V_2 ,
L_49 ,
error ) ;
}
return 0 ;
V_332:
F_163 ( V_2 , NULL ) ;
return error ;
}
static void F_169 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_16 * V_16 = & V_14 -> V_16 ;
struct V_32 * V_33 = & V_16 -> V_33 ;
if ( V_33 -> V_68 & V_137 )
F_12 ( V_2 ) ;
F_148 ( V_2 ) ;
F_147 ( & V_14 -> V_250 ) ;
F_170 ( & V_14 -> V_357 ) ;
F_170 ( & V_14 -> V_335 ) ;
F_170 ( & V_14 -> V_376 ) ;
if ( V_2 -> V_120 == V_121 )
F_171 ( & V_2 -> V_19 , & V_383 ) ;
F_86 ( V_14 ) ;
if ( V_14 -> V_16 . V_33 . type != V_247 )
F_139 ( V_14 ) ;
F_163 ( V_2 , NULL ) ;
}
static int F_172 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
F_44 ( & V_14 -> V_195 ) ;
F_36 ( V_14 ) ;
F_53 ( V_14 ) ;
F_46 ( & V_14 -> V_195 ) ;
return 0 ;
}
static int F_173 ( struct V_1 * V_2 )
{
return F_172 ( V_2 ) ;
}
