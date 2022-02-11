static int F_1 ( struct V_1 * V_2 , T_1 type , T_1 V_3 ,
void * V_4 , T_2 V_5 , unsigned int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_9 ;
do {
V_9 = F_3 ( V_8 , F_4 ( V_8 , 0 ) ,
V_10 ,
V_11 | V_12 |
V_13 ,
( type << 8 ) + V_3 ,
V_2 -> V_14 [ 0 ] . V_15 . V_16 ,
V_4 , V_5 , 100 ) ;
} while ( ( V_9 == - V_17 || V_9 == - V_18 ) && -- V_6 );
return V_9 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 type , T_1 V_3 ,
void * V_4 , T_2 V_5 , unsigned int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_9 ;
do {
V_9 = F_3 ( V_8 , F_6 ( V_8 , 0 ) ,
V_19 ,
V_12 | V_13 ,
( type << 8 ) + V_3 ,
V_2 -> V_14 [ 0 ] . V_15 . V_16 ,
V_4 , V_5 , 1000 ) ;
} while ( ( V_9 == - V_17 || V_9 == - V_18 ) && -- V_6 );
return V_9 ;
}
static void F_7 ( struct V_20 * V_20 )
{
struct V_21 * V_21 = V_20 -> V_22 ;
struct V_23 * V_8 = & V_21 -> V_2 -> V_8 ;
int V_9 ;
switch ( V_20 -> V_24 ) {
case 0 :
break;
case - V_25 :
case - V_26 :
case - V_27 :
F_8 ( V_8 , L_1 ,
V_28 , V_20 -> V_24 ) ;
return;
default:
F_8 ( V_8 , L_2 ,
V_28 , V_20 -> V_24 ) ;
goto exit;
}
F_9 ( & V_21 -> V_29 , V_20 -> V_30 ) ;
exit:
F_10 ( V_21 -> V_31 ) ;
V_9 = F_11 ( V_20 , V_32 ) ;
if ( V_9 )
F_12 ( V_8 , L_3 ,
V_28 , V_9 ) ;
}
static int F_13 ( struct V_33 * V_8 )
{
struct V_21 * V_21 = F_14 ( V_8 ) ;
int V_9 = 0 ;
if ( F_15 ( V_21 -> V_2 ) < 0 )
return - V_34 ;
F_16 ( & V_21 -> V_35 ) ;
if ( F_11 ( V_21 -> V_36 , V_37 ) ) {
V_9 = - V_34 ;
goto V_38;
}
V_21 -> V_39 = true ;
V_21 -> V_2 -> V_40 = 1 ;
V_38:
F_17 ( & V_21 -> V_35 ) ;
F_18 ( V_21 -> V_2 ) ;
return V_9 ;
}
static void F_19 ( struct V_33 * V_8 )
{
struct V_21 * V_21 = F_14 ( V_8 ) ;
int V_41 ;
V_41 = F_15 ( V_21 -> V_2 ) ;
F_16 ( & V_21 -> V_35 ) ;
F_20 ( V_21 -> V_36 ) ;
V_21 -> V_39 = false ;
V_21 -> V_2 -> V_40 = 0 ;
F_17 ( & V_21 -> V_35 ) ;
if ( ! V_41 )
F_18 ( V_21 -> V_2 ) ;
}
static int F_21 ( int V_42 , int V_43 ,
unsigned char V_44 , unsigned char V_45 )
{
int V_46 , V_47 ;
if ( V_42 <= 0 || V_43 <= 0 )
return 0 ;
V_47 = V_45 ;
if ( V_47 > 7 )
V_47 -= 16 ;
if ( V_44 == 0x11 ) {
V_47 += 1 ;
} else if ( V_44 == 0x13 ) {
V_46 = V_43 ;
V_43 *= 254 ;
if ( V_43 < V_46 )
return 0 ;
V_47 -= 1 ;
} else {
return 0 ;
}
for (; V_47 < 0 ; V_47 ++ ) {
V_46 = V_42 ;
V_42 *= 10 ;
if ( V_42 < V_46 )
return 0 ;
}
for (; V_47 > 0 ; V_47 -- ) {
V_46 = V_43 ;
V_43 *= 10 ;
if ( V_43 < V_46 )
return 0 ;
}
return V_42 / V_43 ;
}
static int F_22 ( unsigned char * V_48 ,
struct V_49 * V_50 )
{
int V_51 = 0 ;
if ( V_50 -> type == V_52 ) {
V_50 -> V_53 = V_54 ;
V_50 -> V_55 = V_56 ;
V_50 -> V_57 = V_50 -> V_58 =
F_23 ( & V_48 [ 10 ] ) ;
V_51 = 11 ;
}
return V_51 ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
int V_59 = 0 ;
unsigned char * V_60 ;
V_60 = F_25 ( 2 , V_37 ) ;
if ( V_60 ) {
V_60 [ 0 ] = 12 ;
V_59 = F_1 ( V_2 , V_61 ,
V_60 [ 0 ] , V_60 , 2 ,
V_62 ) ;
if ( V_59 >= 0 && V_60 [ 1 ] > 2 )
V_50 -> V_63 = V_60 [ 1 ] ;
F_26 ( V_60 ) ;
}
}
static int F_27 ( struct V_1 * V_2 ,
struct V_64 * V_65 ,
struct V_49 * V_50 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
char V_66 = 0 ;
int V_59 = 0 , V_63 = 0 ;
int V_67 = 0 , V_68 = 0 , V_69 = 0 , V_70 = 0 ;
unsigned char * V_48 ;
V_48 = F_28 ( V_65 -> V_71 , V_37 ) ;
if ( ! V_48 )
return - V_72 ;
do {
V_59 = F_3 ( V_8 , F_4 ( V_8 , 0 ) ,
V_73 ,
V_13 | V_11 ,
V_74 << 8 ,
V_2 -> V_14 [ 0 ] . V_15 . V_16 ,
V_48 ,
V_65 -> V_71 ,
5000 ) ;
} while ( V_59 < 0 && V_66 ++ < V_62 );
if ( V_59 < 0 )
goto V_38;
for ( V_67 = 0 ; V_67 < V_65 -> V_71 ; V_67 ++ ) {
switch ( V_48 [ V_67 ] ) {
case V_75 :
V_68 = V_48 [ V_67 + 1 ] ;
V_67 ++ ;
break;
case V_76 :
switch ( V_68 << 16 | V_48 [ V_67 + 1 ] ) {
case V_77 :
if ( V_69 ) {
V_50 -> V_55 = V_56 ;
V_63 = 1 ;
switch ( V_50 -> type ) {
case V_78 :
V_50 -> V_53 = V_79 ;
break;
case V_80 :
case V_81 :
V_50 -> V_53 = V_82 ;
break;
case V_83 :
V_50 -> V_53 = V_84 ;
break;
case V_52 :
V_50 -> V_53 = V_85 ;
break;
default:
V_50 -> V_53 = V_86 ;
break;
}
switch ( V_50 -> type ) {
case V_52 :
V_50 -> V_87 =
F_23 ( & V_48 [ V_67 + 5 ] ) ;
V_50 -> V_57 =
F_23 ( & V_48 [ V_67 + 8 ] ) ;
V_67 += 15 ;
break;
case V_81 :
V_50 -> V_57 =
F_23 ( & V_48 [ V_67 + 3 ] ) ;
V_50 -> V_87 =
F_23 ( & V_48 [ V_67 + 8 ] ) ;
V_50 -> V_44 = V_48 [ V_67 - 1 ] ;
V_50 -> V_88 = V_48 [ V_67 - 3 ] ;
V_67 += 12 ;
break;
default:
V_50 -> V_57 =
F_23 ( & V_48 [ V_67 + 3 ] ) ;
V_50 -> V_87 =
F_23 ( & V_48 [ V_67 + 6 ] ) ;
V_50 -> V_44 = V_48 [ V_67 + 9 ] ;
V_50 -> V_88 = V_48 [ V_67 + 11 ] ;
V_67 += 12 ;
break;
}
} else if ( V_70 ) {
if ( V_50 -> type >= V_89 )
V_50 -> V_53 = V_86 ;
V_50 -> V_55 = V_90 ;
V_50 -> V_57 =
F_23 ( & V_48 [ V_67 + 3 ] ) ;
V_67 += 4 ;
}
break;
case V_91 :
if ( V_69 ) {
switch ( V_50 -> type ) {
case V_78 :
case V_80 :
case V_83 :
V_50 -> V_58 =
F_23 ( & V_48 [ V_67 + 3 ] ) ;
V_50 -> V_92 =
F_23 ( & V_48 [ V_67 + 6 ] ) ;
V_67 += 7 ;
break;
case V_81 :
V_50 -> V_58 =
F_23 ( & V_48 [ V_67 + 3 ] ) ;
V_50 -> V_92 =
F_23 ( & V_48 [ V_67 - 2 ] ) ;
V_67 += 7 ;
break;
case V_52 :
V_50 -> V_92 =
F_23 ( & V_48 [ V_67 + 3 ] ) ;
V_50 -> V_58 =
F_23 ( & V_48 [ V_67 + 6 ] ) ;
V_67 += 12 ;
break;
default:
V_50 -> V_58 =
V_50 -> V_57 ;
V_50 -> V_92 =
F_23 ( & V_48 [ V_67 + 3 ] ) ;
V_67 += 4 ;
break;
}
} else if ( V_70 ) {
V_50 -> V_58 =
F_23 ( & V_48 [ V_67 + 3 ] ) ;
V_67 += 4 ;
}
break;
case V_93 :
V_69 = 1 ;
V_67 ++ ;
break;
case V_94 :
V_70 = 1 ;
V_67 ++ ;
break;
case V_95 :
if ( ! V_50 -> V_63 )
F_24 ( V_2 , V_50 ) ;
V_67 ++ ;
break;
case V_96 :
if ( V_70 ) {
V_50 -> V_97 =
F_23 ( & V_48 [ V_67 + 3 ] ) ;
V_67 += 4 ;
}
break;
}
break;
case V_98 :
V_69 = V_68 = 0 ;
break;
case V_99 :
V_67 ++ ;
switch ( V_48 [ V_67 ] ) {
case V_100 :
V_67 += F_22 ( & V_48 [ V_67 ] ,
V_50 ) ;
break;
}
break;
}
}
V_38:
if ( ! V_50 -> V_63 && V_63 )
V_50 -> V_63 = V_63 ;
V_59 = 0 ;
F_26 ( V_48 ) ;
return V_59 ;
}
static int F_29 ( struct V_1 * V_2 , int V_101 , int V_51 , int V_102 )
{
unsigned char * V_60 ;
int error = - V_72 , V_66 = 0 ;
V_60 = F_28 ( V_51 , V_37 ) ;
if ( ! V_60 )
return error ;
do {
V_60 [ 0 ] = V_101 ;
V_60 [ 1 ] = V_102 ;
error = F_5 ( V_2 , V_61 ,
V_101 , V_60 , V_51 , 1 ) ;
} while ( ( error < 0 || V_60 [ 1 ] != V_102 ) && V_66 ++ < V_62 );
F_26 ( V_60 ) ;
return error < 0 ? error : 0 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
if ( V_50 -> V_55 == V_56 ) {
if ( V_50 -> type > V_89 ) {
return F_29 ( V_2 , 3 , 4 , 4 ) ;
}
else if ( V_50 -> type == V_81 || V_50 -> type == V_103 ) {
return F_29 ( V_2 , 18 , 3 , 2 ) ;
}
} else if ( V_50 -> V_55 == V_90 ) {
if ( V_50 -> type <= V_52 && V_50 -> type != V_104 ) {
return F_29 ( V_2 , 2 , 2 , 2 ) ;
}
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
int error = 0 ;
struct V_105 * V_106 = V_2 -> V_107 ;
struct V_64 * V_65 ;
V_50 -> V_55 = V_90 ;
V_50 -> V_108 = 4 ;
V_50 -> V_109 = 4 ;
V_50 -> V_110 = 0 ;
V_50 -> V_111 = 0 ;
if ( V_50 -> type == V_104 ) {
if ( V_2 -> V_107 -> V_15 . V_16 == 0 ) {
V_50 -> V_55 = 0 ;
} else if ( V_2 -> V_107 -> V_15 . V_16 == 2 ) {
V_50 -> V_55 = V_56 ;
V_50 -> V_53 = V_54 ;
}
}
if ( V_50 -> type < V_52 ) {
goto V_38;
}
error = F_32 ( V_106 , V_112 , & V_65 ) ;
if ( error ) {
error = F_32 ( & V_106 -> V_113 [ 0 ] ,
V_74 , & V_65 ) ;
if ( error ) {
F_12 ( & V_2 -> V_8 ,
L_4 ) ;
goto V_38;
}
}
error = F_27 ( V_2 , V_65 , V_50 ) ;
V_38:
return error ;
}
static struct V_7 * F_33 ( struct V_7 * V_8 , int V_114 , int V_115 )
{
int V_116 ;
struct V_7 * V_117 ;
if ( V_114 == 0 && V_115 == 0 )
return V_8 ;
if ( V_8 -> V_118 == NULL )
return NULL ;
F_34 (dev->parent, port1, sibling) {
struct V_119 * V_120 ;
if ( V_117 == NULL )
continue;
V_120 = & V_117 -> V_121 ;
if ( V_120 -> V_122 == V_114 && V_120 -> V_123 == V_115 )
return V_117 ;
}
return NULL ;
}
static struct V_124 * F_35 ( struct V_7 * V_8 )
{
struct V_124 * V_125 ;
F_36 (data, &wacom_udev_list, list) {
if ( V_125 -> V_8 == V_8 ) {
F_37 ( & V_125 -> V_126 ) ;
return V_125 ;
}
}
return NULL ;
}
static int F_38 ( struct V_29 * V_21 ,
struct V_7 * V_8 )
{
struct V_124 * V_125 ;
int V_9 = 0 ;
F_16 ( & V_127 ) ;
V_125 = F_35 ( V_8 ) ;
if ( ! V_125 ) {
V_125 = F_28 ( sizeof( struct V_124 ) , V_37 ) ;
if ( ! V_125 ) {
V_9 = - V_72 ;
goto V_38;
}
F_39 ( & V_125 -> V_126 ) ;
V_125 -> V_8 = V_8 ;
F_40 ( & V_125 -> V_128 , & V_129 ) ;
}
V_21 -> V_130 = & V_125 -> V_130 ;
V_38:
F_17 ( & V_127 ) ;
return V_9 ;
}
static void F_41 ( struct V_126 * V_126 )
{
struct V_124 * V_125 =
F_42 ( V_126 , struct V_124 , V_126 ) ;
F_16 ( & V_127 ) ;
F_43 ( & V_125 -> V_128 ) ;
F_17 ( & V_127 ) ;
F_26 ( V_125 ) ;
}
static void F_44 ( struct V_29 * V_21 )
{
struct V_124 * V_125 ;
if ( V_21 -> V_130 ) {
V_125 = F_42 ( V_21 -> V_130 , struct V_124 , V_130 ) ;
F_45 ( & V_125 -> V_126 , F_41 ) ;
V_21 -> V_130 = NULL ;
}
}
static int F_46 ( struct V_21 * V_21 )
{
unsigned char * V_4 ;
int V_9 ;
V_4 = F_28 ( 9 , V_37 ) ;
if ( ! V_4 )
return - V_72 ;
if ( V_21 -> V_29 . V_50 . type >= V_131 &&
V_21 -> V_29 . V_50 . type <= V_132 ) {
int V_133 = V_21 -> V_134 . V_135 [ 0 ] & 0x03 ;
int V_136 = ( ( ( V_21 -> V_134 . V_137 & 0x60 ) >> 5 ) - 1 ) & 0x03 ;
int V_138 = 0 ;
V_4 [ 0 ] = V_139 ;
V_4 [ 1 ] = ( V_138 << 4 ) | ( V_136 << 2 ) | ( V_133 ) ;
}
else {
int V_134 = V_21 -> V_134 . V_135 [ 0 ] | 0x4 ;
if ( V_21 -> V_29 . V_50 . type == V_140 ||
V_21 -> V_29 . V_50 . type == V_141 )
V_134 |= ( V_21 -> V_134 . V_135 [ 1 ] << 4 ) | 0x40 ;
V_4 [ 0 ] = V_139 ;
V_4 [ 1 ] = V_134 ;
V_4 [ 2 ] = V_21 -> V_134 . V_137 ;
V_4 [ 3 ] = V_21 -> V_134 . V_142 ;
V_4 [ 4 ] = V_21 -> V_134 . V_143 ;
}
V_9 = F_5 ( V_21 -> V_2 , 0x03 , V_139 ,
V_4 , 9 , V_144 ) ;
F_26 ( V_4 ) ;
return V_9 ;
}
static int F_47 ( struct V_21 * V_21 , int V_145 , const void * V_146 )
{
unsigned char * V_4 ;
int V_67 , V_9 ;
V_4 = F_28 ( 259 , V_37 ) ;
if ( ! V_4 )
return - V_72 ;
V_4 [ 0 ] = V_147 ;
V_4 [ 1 ] = 1 ;
V_9 = F_5 ( V_21 -> V_2 , 0x03 , V_147 ,
V_4 , 2 , V_144 ) ;
if ( V_9 < 0 )
goto V_38;
V_4 [ 0 ] = V_148 ;
V_4 [ 1 ] = V_145 & 0x07 ;
for ( V_67 = 0 ; V_67 < 4 ; V_67 ++ ) {
V_4 [ 2 ] = V_67 ;
memcpy ( V_4 + 3 , V_146 + V_67 * 256 , 256 ) ;
V_9 = F_5 ( V_21 -> V_2 , 0x03 , V_148 ,
V_4 , 259 , V_144 ) ;
if ( V_9 < 0 )
break;
}
V_4 [ 0 ] = V_147 ;
V_4 [ 1 ] = 0 ;
F_5 ( V_21 -> V_2 , 0x03 , V_147 ,
V_4 , 2 , V_144 ) ;
V_38:
F_26 ( V_4 ) ;
return V_9 ;
}
static T_3 F_48 ( struct V_23 * V_8 , int V_149 ,
const char * V_4 , T_2 V_150 )
{
struct V_21 * V_21 = F_49 ( V_8 ) ;
unsigned int V_3 ;
int V_151 ;
V_151 = F_50 ( V_4 , 10 , & V_3 ) ;
if ( V_151 )
return V_151 ;
F_16 ( & V_21 -> V_35 ) ;
V_21 -> V_134 . V_135 [ V_149 ] = V_3 & 0x3 ;
V_151 = F_46 ( V_21 ) ;
F_17 ( & V_21 -> V_35 ) ;
return V_151 < 0 ? V_151 : V_150 ;
}
static T_3 F_51 ( struct V_21 * V_21 , T_1 * V_152 ,
const char * V_4 , T_2 V_150 )
{
unsigned int V_153 ;
int V_151 ;
V_151 = F_50 ( V_4 , 10 , & V_153 ) ;
if ( V_151 )
return V_151 ;
F_16 ( & V_21 -> V_35 ) ;
* V_152 = V_153 & 0x7f ;
V_151 = F_46 ( V_21 ) ;
F_17 ( & V_21 -> V_35 ) ;
return V_151 < 0 ? V_151 : V_150 ;
}
static T_3 F_52 ( struct V_23 * V_8 , int V_145 ,
const char * V_4 , T_2 V_150 )
{
struct V_21 * V_21 = F_49 ( V_8 ) ;
int V_151 ;
if ( V_150 != 1024 )
return - V_154 ;
F_16 ( & V_21 -> V_35 ) ;
V_151 = F_47 ( V_21 , V_145 , V_4 ) ;
F_17 ( & V_21 -> V_35 ) ;
return V_151 < 0 ? V_151 : V_150 ;
}
static int F_53 ( struct V_21 * V_21 )
{
int error ;
switch ( V_21 -> V_29 . V_50 . type ) {
case V_155 :
case V_156 :
case V_157 :
V_21 -> V_134 . V_135 [ 0 ] = 0 ;
V_21 -> V_134 . V_135 [ 1 ] = 0 ;
V_21 -> V_134 . V_137 = 10 ;
V_21 -> V_134 . V_142 = 20 ;
V_21 -> V_134 . V_143 = 10 ;
error = F_54 ( & V_21 -> V_2 -> V_8 . V_158 ,
& V_159 ) ;
break;
case V_141 :
case V_140 :
V_21 -> V_134 . V_135 [ 0 ] = 0 ;
V_21 -> V_134 . V_135 [ 1 ] = 0 ;
V_21 -> V_134 . V_137 = 0 ;
V_21 -> V_134 . V_142 = 0 ;
V_21 -> V_134 . V_143 = 0 ;
error = F_54 ( & V_21 -> V_2 -> V_8 . V_158 ,
& V_160 ) ;
break;
case V_131 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_132 :
if ( V_21 -> V_29 . V_50 . V_55 == V_90 ) {
V_21 -> V_134 . V_135 [ 0 ] = 0 ;
V_21 -> V_134 . V_135 [ 1 ] = 0 ;
V_21 -> V_134 . V_137 = 32 ;
V_21 -> V_134 . V_142 = 0 ;
V_21 -> V_134 . V_143 = 0 ;
error = F_54 ( & V_21 -> V_2 -> V_8 . V_158 ,
& V_165 ) ;
} else
return 0 ;
break;
default:
return 0 ;
}
if ( error ) {
F_12 ( & V_21 -> V_2 -> V_8 ,
L_5 , error ) ;
return error ;
}
F_46 ( V_21 ) ;
return 0 ;
}
static void F_55 ( struct V_21 * V_21 )
{
switch ( V_21 -> V_29 . V_50 . type ) {
case V_155 :
case V_156 :
case V_157 :
F_56 ( & V_21 -> V_2 -> V_8 . V_158 ,
& V_159 ) ;
break;
case V_141 :
case V_140 :
F_56 ( & V_21 -> V_2 -> V_8 . V_158 ,
& V_160 ) ;
break;
case V_131 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_132 :
if ( V_21 -> V_29 . V_50 . V_55 == V_90 )
F_56 ( & V_21 -> V_2 -> V_8 . V_158 ,
& V_165 ) ;
break;
}
}
static int F_57 ( struct V_166 * V_167 ,
enum V_168 V_169 ,
union V_170 * V_171 )
{
struct V_21 * V_21 = F_42 ( V_167 , struct V_21 , V_172 ) ;
int V_173 = 0 ;
switch ( V_169 ) {
case V_174 :
V_171 -> V_175 = V_176 ;
break;
case V_177 :
V_171 -> V_175 =
V_21 -> V_29 . V_178 * 100 / 31 ;
break;
default:
V_173 = - V_154 ;
break;
}
return V_173 ;
}
static int F_58 ( struct V_21 * V_21 )
{
int error = 0 ;
if ( V_21 -> V_29 . V_50 . V_179 & V_180 ) {
V_21 -> V_172 . V_181 = V_182 ;
V_21 -> V_172 . V_183 = F_59 ( V_182 ) ;
V_21 -> V_172 . V_184 = F_57 ;
V_21 -> V_172 . V_185 = L_6 ;
V_21 -> V_172 . type = V_186 ;
V_21 -> V_172 . V_187 = 0 ;
error = F_60 ( & V_21 -> V_31 -> V_8 ,
& V_21 -> V_172 ) ;
if ( ! error )
F_61 ( & V_21 -> V_172 ,
& V_21 -> V_31 -> V_8 ) ;
}
return error ;
}
static void F_62 ( struct V_21 * V_21 )
{
if ( V_21 -> V_29 . V_50 . V_179 & V_180 &&
V_21 -> V_172 . V_8 ) {
F_63 ( & V_21 -> V_172 ) ;
V_21 -> V_172 . V_8 = NULL ;
}
}
static int F_64 ( struct V_21 * V_21 )
{
struct V_33 * V_33 ;
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_29 * V_29 = & ( V_21 -> V_29 ) ;
int error ;
V_33 = F_65 () ;
if ( ! V_33 ) {
error = - V_72 ;
goto V_188;
}
V_33 -> V_185 = V_29 -> V_185 ;
V_33 -> V_8 . V_118 = & V_2 -> V_8 ;
V_33 -> V_39 = F_13 ;
V_33 -> V_189 = F_19 ;
F_66 ( V_8 , & V_33 -> V_3 ) ;
F_67 ( V_33 , V_21 ) ;
V_29 -> V_190 = V_33 ;
error = F_68 ( V_33 , V_29 ) ;
if ( error )
goto V_188;
error = F_69 ( V_33 ) ;
if ( error )
goto V_191;
return 0 ;
V_191:
F_70 ( V_33 ) ;
V_29 -> V_190 = NULL ;
V_188:
return error ;
}
static void F_71 ( struct V_192 * V_193 )
{
struct V_21 * V_21 = F_42 ( V_193 , struct V_21 , V_193 ) ;
struct V_7 * V_31 = V_21 -> V_31 ;
struct V_29 * V_29 = & V_21 -> V_29 ;
struct V_21 * V_194 , * V_195 ;
struct V_29 * V_196 , * V_197 ;
int error ;
F_62 ( V_21 ) ;
V_194 = F_72 ( V_31 -> V_198 -> V_106 [ 1 ] ) ;
V_196 = & ( V_194 -> V_29 ) ;
if ( V_196 -> V_190 )
F_73 ( V_196 -> V_190 ) ;
V_196 -> V_190 = NULL ;
V_195 = F_72 ( V_31 -> V_198 -> V_106 [ 2 ] ) ;
V_197 = & ( V_195 -> V_29 ) ;
if ( V_197 -> V_190 )
F_73 ( V_197 -> V_190 ) ;
V_197 -> V_190 = NULL ;
if ( V_29 -> V_199 == 0 ) {
F_74 ( & V_21 -> V_2 -> V_8 , L_7 ) ;
} else {
const struct V_200 * V_3 = V_201 ;
F_74 ( & V_21 -> V_2 -> V_8 ,
L_8 ,
V_29 -> V_199 ) ;
while ( V_3 -> V_202 ) {
if ( V_3 -> V_122 == V_203 &&
V_3 -> V_123 == V_29 -> V_199 )
break;
V_3 ++ ;
}
if ( ! V_3 -> V_202 ) {
F_74 ( & V_21 -> V_2 -> V_8 ,
L_9 ) ;
return;
}
V_196 -> V_50 =
* ( (struct V_49 * ) V_3 -> V_204 ) ;
V_196 -> V_50 . V_55 = V_90 ;
snprintf ( V_196 -> V_185 , V_205 , L_10 ,
V_196 -> V_50 . V_185 ) ;
V_196 -> V_130 -> V_63 = V_196 -> V_50 . V_63 ;
V_196 -> V_130 -> type = V_196 -> V_50 . type ;
error = F_64 ( V_194 ) ;
if ( error )
goto V_206;
if ( V_196 -> V_50 . V_63 ||
V_196 -> V_50 . type == V_207 ) {
V_197 -> V_50 =
* ( (struct V_49 * ) V_3 -> V_204 ) ;
V_197 -> V_50 . V_53 = V_54 ;
V_197 -> V_50 . V_55 = V_56 ;
V_197 -> V_50 . V_57 = V_197 -> V_50 . V_58 = 4096 ;
if ( V_197 -> V_50 . V_63 )
snprintf ( V_197 -> V_185 , V_205 ,
L_11 , V_197 -> V_50 . V_185 ) ;
else
snprintf ( V_197 -> V_185 , V_205 ,
L_12 , V_197 -> V_50 . V_185 ) ;
error = F_64 ( V_195 ) ;
if ( error )
goto V_206;
if ( V_196 -> V_50 . type == V_207 &&
V_196 -> V_50 . V_63 )
V_29 -> V_130 -> V_208 = V_197 -> V_190 ;
}
error = F_58 ( V_21 ) ;
if ( error )
goto V_206;
}
return;
V_206:
if ( V_197 -> V_190 ) {
F_73 ( V_197 -> V_190 ) ;
V_197 -> V_190 = NULL ;
}
if ( V_196 -> V_190 ) {
F_73 ( V_196 -> V_190 ) ;
V_196 -> V_190 = NULL ;
}
return;
}
static void F_75 ( struct V_49 * V_50 )
{
if ( V_50 -> V_209 ) {
V_50 -> V_87 = ( V_50 -> V_57 * 100 ) /
V_50 -> V_209 ;
V_50 -> V_92 = ( V_50 -> V_58 * 100 ) /
V_50 -> V_210 ;
}
}
static void F_76 ( struct V_49 * V_50 )
{
V_50 -> V_209 = F_21 ( V_50 -> V_57 ,
V_50 -> V_87 ,
V_50 -> V_44 ,
V_50 -> V_88 ) ;
V_50 -> V_210 = F_21 ( V_50 -> V_58 ,
V_50 -> V_92 ,
V_50 -> V_44 ,
V_50 -> V_88 ) ;
}
static int F_77 ( struct V_1 * V_2 , const struct V_200 * V_3 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_211 * V_113 ;
struct V_21 * V_21 ;
struct V_29 * V_29 ;
struct V_49 * V_50 ;
int error ;
if ( ! V_3 -> V_204 )
return - V_154 ;
V_21 = F_28 ( sizeof( struct V_21 ) , V_37 ) ;
if ( ! V_21 )
return - V_72 ;
V_29 = & V_21 -> V_29 ;
V_29 -> V_50 = * ( (struct V_49 * ) V_3 -> V_204 ) ;
V_50 = & V_29 -> V_50 ;
if ( V_50 -> V_53 > V_212 ) {
error = - V_154 ;
goto V_188;
}
V_29 -> V_125 = F_78 ( V_8 , V_212 ,
V_37 , & V_21 -> V_213 ) ;
if ( ! V_29 -> V_125 ) {
error = - V_72 ;
goto V_188;
}
V_21 -> V_36 = F_79 ( 0 , V_37 ) ;
if ( ! V_21 -> V_36 ) {
error = - V_72 ;
goto V_191;
}
V_21 -> V_31 = V_8 ;
V_21 -> V_2 = V_2 ;
F_80 ( & V_21 -> V_35 ) ;
F_81 ( & V_21 -> V_193 , F_71 ) ;
F_82 ( V_8 , V_21 -> V_214 , sizeof( V_21 -> V_214 ) ) ;
F_83 ( V_21 -> V_214 , L_13 , sizeof( V_21 -> V_214 ) ) ;
V_113 = & V_2 -> V_107 -> V_113 [ 0 ] . V_15 ;
F_75 ( V_50 ) ;
error = F_31 ( V_2 , V_50 ) ;
if ( error )
goto V_215;
if ( V_50 -> type >= V_131 && V_50 -> type <= V_207 ) {
if ( V_113 -> V_216 == V_54 ) {
V_50 -> V_55 = V_56 ;
V_50 -> V_53 = V_54 ;
V_50 -> V_57 = 4096 ;
V_50 -> V_58 = 4096 ;
} else {
V_50 -> V_55 = V_90 ;
}
}
F_84 ( V_50 ) ;
if ( ! V_50 -> V_44 ) {
V_50 -> V_44 = 0x11 ;
V_50 -> V_88 = 16 - 3 ;
}
F_76 ( V_50 ) ;
F_85 ( V_29 -> V_185 , V_50 -> V_185 , sizeof( V_29 -> V_185 ) ) ;
if ( V_50 -> V_179 & V_217 ) {
struct V_7 * V_218 ;
if ( V_50 -> V_55 != V_56 )
F_83 ( V_29 -> V_185 , L_14 , V_205 ) ;
else if ( V_50 -> V_63 )
F_83 ( V_29 -> V_185 , L_15 , V_205 ) ;
else
F_83 ( V_29 -> V_185 , L_16 , V_205 ) ;
V_218 = F_33 ( V_8 , V_50 -> V_219 , V_50 -> V_220 ) ;
if ( V_218 == NULL || F_35 ( V_218 ) == NULL )
V_218 = V_8 ;
error = F_38 ( V_29 , V_218 ) ;
if ( error )
goto V_215;
}
F_86 ( V_21 -> V_36 , V_8 ,
F_87 ( V_8 , V_113 -> V_221 ) ,
V_29 -> V_125 , V_50 -> V_53 ,
F_7 , V_21 , V_113 -> V_222 ) ;
V_21 -> V_36 -> V_223 = V_21 -> V_213 ;
V_21 -> V_36 -> V_224 |= V_225 ;
error = F_53 ( V_21 ) ;
if ( error )
goto V_226;
if ( ! ( V_50 -> V_179 & V_227 ) ) {
error = F_64 ( V_21 ) ;
if ( error )
goto V_228;
}
F_30 ( V_2 , V_50 ) ;
F_88 ( V_2 , V_21 ) ;
if ( V_50 -> V_179 & V_180 ) {
if ( F_11 ( V_21 -> V_36 , V_37 ) ) {
error = - V_34 ;
goto V_228;
}
}
if ( V_29 -> V_50 . type == V_207 && V_29 -> V_50 . V_63 ) {
if ( V_29 -> V_50 . V_55 == V_56 )
V_29 -> V_130 -> V_208 = V_29 -> V_190 ;
}
return 0 ;
V_228: F_55 ( V_21 ) ;
V_226: F_44 ( V_29 ) ;
V_215: F_89 ( V_21 -> V_36 ) ;
V_191: F_90 ( V_8 , V_212 , V_29 -> V_125 , V_21 -> V_213 ) ;
V_188: F_26 ( V_21 ) ;
return error ;
}
static void F_91 ( struct V_1 * V_2 )
{
struct V_21 * V_21 = F_72 ( V_2 ) ;
F_88 ( V_2 , NULL ) ;
F_20 ( V_21 -> V_36 ) ;
F_92 ( & V_21 -> V_193 ) ;
if ( V_21 -> V_29 . V_190 )
F_73 ( V_21 -> V_29 . V_190 ) ;
F_62 ( V_21 ) ;
F_55 ( V_21 ) ;
F_89 ( V_21 -> V_36 ) ;
F_90 ( F_2 ( V_2 ) , V_212 ,
V_21 -> V_29 . V_125 , V_21 -> V_213 ) ;
F_44 ( & V_21 -> V_29 ) ;
F_26 ( V_21 ) ;
}
static int F_93 ( struct V_1 * V_2 , T_4 V_229 )
{
struct V_21 * V_21 = F_72 ( V_2 ) ;
F_16 ( & V_21 -> V_35 ) ;
F_20 ( V_21 -> V_36 ) ;
F_17 ( & V_21 -> V_35 ) ;
return 0 ;
}
static int F_94 ( struct V_1 * V_2 )
{
struct V_21 * V_21 = F_72 ( V_2 ) ;
struct V_49 * V_50 = & V_21 -> V_29 . V_50 ;
int V_230 = 0 ;
F_16 ( & V_21 -> V_35 ) ;
F_30 ( V_2 , V_50 ) ;
F_46 ( V_21 ) ;
if ( ( V_21 -> V_39 || ( V_50 -> V_179 & V_180 ) ) &&
F_11 ( V_21 -> V_36 , V_231 ) < 0 )
V_230 = - V_34 ;
F_17 ( & V_21 -> V_35 ) ;
return V_230 ;
}
static int F_95 ( struct V_1 * V_2 )
{
return F_94 ( V_2 ) ;
}
