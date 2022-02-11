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
static void F_22 ( struct V_48 * V_49 )
{
int V_50 = F_21 ( V_49 -> V_51 , V_49 -> V_52 ,
V_49 -> V_44 , V_49 -> V_53 ) ;
int V_54 = F_21 ( V_49 -> V_55 , V_49 -> V_56 ,
V_49 -> V_44 , V_49 -> V_53 ) ;
if ( V_50 > 0 && V_54 > 0 ) {
V_49 -> V_52 = ( 100 * V_49 -> V_51 ) / V_50 ;
V_49 -> V_56 = ( 100 * V_49 -> V_55 ) / V_54 ;
}
}
static void F_23 ( struct V_48 * V_49 )
{
V_49 -> V_52 = ( V_49 -> V_51 * 100 ) / V_49 -> V_57 ;
V_49 -> V_56 = ( V_49 -> V_55 * 100 ) / V_49 -> V_58 ;
}
static int F_24 ( unsigned char * V_59 ,
struct V_48 * V_49 )
{
int V_60 = 0 ;
if ( V_49 -> type == V_61 ) {
V_49 -> V_62 = V_63 ;
V_49 -> V_64 = V_65 ;
F_23 ( V_49 ) ;
V_49 -> V_51 = V_49 -> V_55 =
F_25 ( & V_59 [ 10 ] ) ;
V_60 = 11 ;
}
return V_60 ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_48 * V_49 )
{
int V_66 = 0 ;
unsigned char * V_67 ;
V_67 = F_27 ( 2 , V_37 ) ;
if ( V_67 ) {
V_67 [ 0 ] = 12 ;
V_66 = F_1 ( V_2 , V_68 ,
V_67 [ 0 ] , V_67 , 2 ,
V_69 ) ;
if ( V_66 >= 0 && V_67 [ 1 ] > 2 )
V_49 -> V_70 = V_67 [ 1 ] ;
F_28 ( V_67 ) ;
}
}
static int F_29 ( struct V_1 * V_2 ,
struct V_71 * V_72 ,
struct V_48 * V_49 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
char V_73 = 0 ;
int V_66 = 0 ;
int V_74 = 0 , V_75 = V_76 , V_77 = 0 , V_78 = 0 ;
unsigned char * V_59 ;
V_59 = F_30 ( V_72 -> V_79 , V_37 ) ;
if ( ! V_59 )
return - V_80 ;
do {
V_66 = F_3 ( V_8 , F_4 ( V_8 , 0 ) ,
V_81 ,
V_13 | V_11 ,
V_82 << 8 ,
V_2 -> V_14 [ 0 ] . V_15 . V_16 ,
V_59 ,
V_72 -> V_79 ,
5000 ) ;
} while ( V_66 < 0 && V_73 ++ < V_69 );
if ( V_66 < 0 )
goto V_38;
for ( V_74 = 0 ; V_74 < V_72 -> V_79 ; V_74 ++ ) {
switch ( V_59 [ V_74 ] ) {
case V_83 :
switch ( V_59 [ V_74 + 1 ] ) {
case V_84 :
V_75 = V_85 ;
V_74 ++ ;
break;
case V_86 :
V_75 = V_87 ;
V_74 ++ ;
break;
}
break;
case V_88 :
switch ( V_59 [ V_74 + 1 ] ) {
case V_89 :
if ( V_75 == V_87 ) {
if ( V_77 ) {
V_49 -> V_64 = V_65 ;
switch ( V_49 -> type ) {
case V_90 :
V_49 -> V_62 = V_91 ;
break;
case V_92 :
case V_93 :
V_49 -> V_62 = V_94 ;
break;
case V_95 :
V_49 -> V_62 = V_96 ;
break;
case V_61 :
V_49 -> V_62 = V_97 ;
break;
default:
V_49 -> V_62 = V_98 ;
break;
}
switch ( V_49 -> type ) {
case V_61 :
V_49 -> V_52 =
F_25 ( & V_59 [ V_74 + 5 ] ) ;
V_49 -> V_51 =
F_25 ( & V_59 [ V_74 + 8 ] ) ;
V_74 += 15 ;
break;
case V_93 :
V_49 -> V_51 =
F_25 ( & V_59 [ V_74 + 3 ] ) ;
V_49 -> V_52 =
F_25 ( & V_59 [ V_74 + 8 ] ) ;
V_49 -> V_44 = V_59 [ V_74 - 1 ] ;
V_49 -> V_53 = V_59 [ V_74 - 3 ] ;
V_74 += 12 ;
break;
default:
V_49 -> V_51 =
F_25 ( & V_59 [ V_74 + 3 ] ) ;
V_49 -> V_52 =
F_25 ( & V_59 [ V_74 + 6 ] ) ;
V_49 -> V_44 = V_59 [ V_74 + 9 ] ;
V_49 -> V_53 = V_59 [ V_74 + 11 ] ;
V_74 += 12 ;
break;
}
} else if ( V_78 ) {
if ( V_49 -> type >= V_99 )
V_49 -> V_62 = V_98 ;
V_49 -> V_64 = V_100 ;
V_49 -> V_51 =
F_25 ( & V_59 [ V_74 + 3 ] ) ;
V_74 += 4 ;
}
}
break;
case V_101 :
if ( V_75 == V_87 ) {
if ( V_77 ) {
switch ( V_49 -> type ) {
case V_90 :
case V_92 :
case V_95 :
V_49 -> V_55 =
F_25 ( & V_59 [ V_74 + 3 ] ) ;
V_49 -> V_56 =
F_25 ( & V_59 [ V_74 + 6 ] ) ;
V_74 += 7 ;
break;
case V_93 :
V_49 -> V_55 =
F_25 ( & V_59 [ V_74 + 3 ] ) ;
V_49 -> V_56 =
F_25 ( & V_59 [ V_74 - 2 ] ) ;
V_74 += 7 ;
break;
case V_61 :
V_49 -> V_56 =
F_25 ( & V_59 [ V_74 + 3 ] ) ;
V_49 -> V_55 =
F_25 ( & V_59 [ V_74 + 6 ] ) ;
V_74 += 12 ;
break;
default:
V_49 -> V_55 =
V_49 -> V_51 ;
V_49 -> V_56 =
F_25 ( & V_59 [ V_74 + 3 ] ) ;
V_74 += 4 ;
break;
}
} else if ( V_78 ) {
V_49 -> V_55 =
F_25 ( & V_59 [ V_74 + 3 ] ) ;
V_74 += 4 ;
}
}
break;
case V_102 :
V_77 = 1 ;
V_74 ++ ;
break;
case V_103 :
V_78 = 1 ;
V_74 ++ ;
break;
case V_104 :
if ( ! V_49 -> V_70 )
F_26 ( V_2 , V_49 ) ;
V_74 ++ ;
break;
}
break;
case V_105 :
V_77 = V_75 = 0 ;
break;
case V_106 :
V_74 ++ ;
switch ( V_59 [ V_74 ] ) {
case V_107 :
V_74 += F_24 ( & V_59 [ V_74 ] ,
V_49 ) ;
break;
}
break;
}
}
V_38:
V_66 = 0 ;
F_28 ( V_59 ) ;
return V_66 ;
}
static int F_31 ( struct V_1 * V_2 , int V_108 , int V_60 , int V_109 )
{
unsigned char * V_67 ;
int error = - V_80 , V_73 = 0 ;
V_67 = F_30 ( V_60 , V_37 ) ;
if ( ! V_67 )
return error ;
do {
V_67 [ 0 ] = V_108 ;
V_67 [ 1 ] = V_109 ;
error = F_5 ( V_2 , V_68 ,
V_108 , V_67 , V_60 , 1 ) ;
if ( error >= 0 )
error = F_1 ( V_2 , V_68 ,
V_108 , V_67 , V_60 , 1 ) ;
} while ( ( error < 0 || V_67 [ 1 ] != V_109 ) && V_73 ++ < V_69 );
F_28 ( V_67 ) ;
return error < 0 ? error : 0 ;
}
static int F_32 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
if ( V_49 -> V_64 == V_65 ) {
if ( V_49 -> type > V_99 ) {
return F_31 ( V_2 , 3 , 4 , 4 ) ;
}
else if ( V_49 -> type == V_93 ) {
return F_31 ( V_2 , 18 , 3 , 2 ) ;
}
} else if ( V_49 -> V_64 == V_100 ) {
if ( V_49 -> type <= V_61 && V_49 -> type != V_110 ) {
return F_31 ( V_2 , 2 , 2 , 2 ) ;
}
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_48 * V_49 )
{
int error = 0 ;
struct V_111 * V_112 = V_2 -> V_113 ;
struct V_71 * V_72 ;
V_49 -> V_64 = V_100 ;
V_49 -> V_114 = 4 ;
V_49 -> V_115 = 4 ;
V_49 -> V_116 = 0 ;
V_49 -> V_117 = 0 ;
if ( V_49 -> type == V_110 ) {
if ( V_2 -> V_113 -> V_15 . V_16 == 0 ) {
V_49 -> V_64 = 0 ;
} else if ( V_2 -> V_113 -> V_15 . V_16 == 2 ) {
V_49 -> V_64 = V_65 ;
V_49 -> V_62 = V_63 ;
}
}
if ( V_49 -> type < V_61 ) {
goto V_38;
}
error = F_34 ( V_112 , V_118 , & V_72 ) ;
if ( error ) {
error = F_34 ( & V_112 -> V_119 [ 0 ] ,
V_82 , & V_72 ) ;
if ( error ) {
F_12 ( & V_2 -> V_8 ,
L_4 ) ;
goto V_38;
}
}
error = F_29 ( V_2 , V_72 , V_49 ) ;
if ( error )
goto V_38;
F_22 ( V_49 ) ;
V_38:
return error ;
}
static struct V_7 * F_35 ( struct V_7 * V_8 , int V_120 , int V_121 )
{
int V_122 ;
struct V_7 * V_123 ;
if ( V_120 == 0 && V_121 == 0 )
return V_8 ;
if ( V_8 -> V_124 == NULL )
return NULL ;
F_36 (dev->parent, port1, sibling) {
struct V_125 * V_126 ;
if ( V_123 == NULL )
continue;
V_126 = & V_123 -> V_127 ;
if ( V_126 -> V_128 == V_120 && V_126 -> V_129 == V_121 )
return V_123 ;
}
return NULL ;
}
static struct V_130 * F_37 ( struct V_7 * V_8 )
{
struct V_130 * V_131 ;
F_38 (data, &wacom_udev_list, list) {
if ( V_131 -> V_8 == V_8 ) {
F_39 ( & V_131 -> V_132 ) ;
return V_131 ;
}
}
return NULL ;
}
static int F_40 ( struct V_29 * V_21 ,
struct V_7 * V_8 )
{
struct V_130 * V_131 ;
int V_9 = 0 ;
F_16 ( & V_133 ) ;
V_131 = F_37 ( V_8 ) ;
if ( ! V_131 ) {
V_131 = F_30 ( sizeof( struct V_130 ) , V_37 ) ;
if ( ! V_131 ) {
V_9 = - V_80 ;
goto V_38;
}
F_41 ( & V_131 -> V_132 ) ;
V_131 -> V_8 = V_8 ;
F_42 ( & V_131 -> V_134 , & V_135 ) ;
}
V_21 -> V_136 = & V_131 -> V_136 ;
V_38:
F_17 ( & V_133 ) ;
return V_9 ;
}
static void F_43 ( struct V_132 * V_132 )
{
struct V_130 * V_131 =
F_44 ( V_132 , struct V_130 , V_132 ) ;
F_16 ( & V_133 ) ;
F_45 ( & V_131 -> V_134 ) ;
F_17 ( & V_133 ) ;
F_28 ( V_131 ) ;
}
static void F_46 ( struct V_29 * V_21 )
{
struct V_130 * V_131 ;
if ( V_21 -> V_136 ) {
V_131 = F_44 ( V_21 -> V_136 , struct V_130 , V_136 ) ;
F_47 ( & V_131 -> V_132 , F_43 ) ;
V_21 -> V_136 = NULL ;
}
}
static int F_48 ( struct V_21 * V_21 )
{
unsigned char * V_4 ;
int V_9 ;
V_4 = F_30 ( 9 , V_37 ) ;
if ( ! V_4 )
return - V_80 ;
if ( V_21 -> V_29 . V_49 . type >= V_137 &&
V_21 -> V_29 . V_49 . type <= V_138 ) {
int V_139 = V_21 -> V_140 . V_141 [ 0 ] & 0x03 ;
int V_142 = ( ( ( V_21 -> V_140 . V_143 & 0x60 ) >> 5 ) - 1 ) & 0x03 ;
int V_144 = 0 ;
V_4 [ 0 ] = V_145 ;
V_4 [ 1 ] = ( V_144 << 4 ) | ( V_142 << 2 ) | ( V_139 ) ;
}
else {
int V_140 = V_21 -> V_140 . V_141 [ 0 ] | 0x4 ;
if ( V_21 -> V_29 . V_49 . type == V_146 ||
V_21 -> V_29 . V_49 . type == V_147 )
V_140 |= ( V_21 -> V_140 . V_141 [ 1 ] << 4 ) | 0x40 ;
V_4 [ 0 ] = V_145 ;
V_4 [ 1 ] = V_140 ;
V_4 [ 2 ] = V_21 -> V_140 . V_143 ;
V_4 [ 3 ] = V_21 -> V_140 . V_148 ;
V_4 [ 4 ] = V_21 -> V_140 . V_149 ;
}
V_9 = F_5 ( V_21 -> V_2 , 0x03 , V_145 ,
V_4 , 9 , V_150 ) ;
F_28 ( V_4 ) ;
return V_9 ;
}
static int F_49 ( struct V_21 * V_21 , int V_151 , const void * V_152 )
{
unsigned char * V_4 ;
int V_74 , V_9 ;
V_4 = F_30 ( 259 , V_37 ) ;
if ( ! V_4 )
return - V_80 ;
V_4 [ 0 ] = V_153 ;
V_4 [ 1 ] = 1 ;
V_9 = F_5 ( V_21 -> V_2 , 0x03 , V_153 ,
V_4 , 2 , V_150 ) ;
if ( V_9 < 0 )
goto V_38;
V_4 [ 0 ] = V_154 ;
V_4 [ 1 ] = V_151 & 0x07 ;
for ( V_74 = 0 ; V_74 < 4 ; V_74 ++ ) {
V_4 [ 2 ] = V_74 ;
memcpy ( V_4 + 3 , V_152 + V_74 * 256 , 256 ) ;
V_9 = F_5 ( V_21 -> V_2 , 0x03 , V_154 ,
V_4 , 259 , V_150 ) ;
if ( V_9 < 0 )
break;
}
V_4 [ 0 ] = V_153 ;
V_4 [ 1 ] = 0 ;
F_5 ( V_21 -> V_2 , 0x03 , V_153 ,
V_4 , 2 , V_150 ) ;
V_38:
F_28 ( V_4 ) ;
return V_9 ;
}
static T_3 F_50 ( struct V_23 * V_8 , int V_155 ,
const char * V_4 , T_2 V_156 )
{
struct V_21 * V_21 = F_51 ( V_8 ) ;
unsigned int V_3 ;
int V_157 ;
V_157 = F_52 ( V_4 , 10 , & V_3 ) ;
if ( V_157 )
return V_157 ;
F_16 ( & V_21 -> V_35 ) ;
V_21 -> V_140 . V_141 [ V_155 ] = V_3 & 0x3 ;
V_157 = F_48 ( V_21 ) ;
F_17 ( & V_21 -> V_35 ) ;
return V_157 < 0 ? V_157 : V_156 ;
}
static T_3 F_53 ( struct V_21 * V_21 , T_1 * V_158 ,
const char * V_4 , T_2 V_156 )
{
unsigned int V_159 ;
int V_157 ;
V_157 = F_52 ( V_4 , 10 , & V_159 ) ;
if ( V_157 )
return V_157 ;
F_16 ( & V_21 -> V_35 ) ;
* V_158 = V_159 & 0x7f ;
V_157 = F_48 ( V_21 ) ;
F_17 ( & V_21 -> V_35 ) ;
return V_157 < 0 ? V_157 : V_156 ;
}
static T_3 F_54 ( struct V_23 * V_8 , int V_151 ,
const char * V_4 , T_2 V_156 )
{
struct V_21 * V_21 = F_51 ( V_8 ) ;
int V_157 ;
if ( V_156 != 1024 )
return - V_160 ;
F_16 ( & V_21 -> V_35 ) ;
V_157 = F_49 ( V_21 , V_151 , V_4 ) ;
F_17 ( & V_21 -> V_35 ) ;
return V_157 < 0 ? V_157 : V_156 ;
}
static int F_55 ( struct V_21 * V_21 )
{
int error ;
switch ( V_21 -> V_29 . V_49 . type ) {
case V_161 :
case V_162 :
case V_163 :
V_21 -> V_140 . V_141 [ 0 ] = 0 ;
V_21 -> V_140 . V_141 [ 1 ] = 0 ;
V_21 -> V_140 . V_143 = 10 ;
V_21 -> V_140 . V_148 = 20 ;
V_21 -> V_140 . V_149 = 10 ;
error = F_56 ( & V_21 -> V_2 -> V_8 . V_164 ,
& V_165 ) ;
break;
case V_147 :
case V_146 :
V_21 -> V_140 . V_141 [ 0 ] = 0 ;
V_21 -> V_140 . V_141 [ 1 ] = 0 ;
V_21 -> V_140 . V_143 = 0 ;
V_21 -> V_140 . V_148 = 0 ;
V_21 -> V_140 . V_149 = 0 ;
error = F_56 ( & V_21 -> V_2 -> V_8 . V_164 ,
& V_166 ) ;
break;
case V_137 :
case V_167 :
case V_138 :
V_21 -> V_140 . V_141 [ 0 ] = 0 ;
V_21 -> V_140 . V_141 [ 1 ] = 0 ;
V_21 -> V_140 . V_143 = 32 ;
V_21 -> V_140 . V_148 = 0 ;
V_21 -> V_140 . V_149 = 0 ;
error = F_56 ( & V_21 -> V_2 -> V_8 . V_164 ,
& V_168 ) ;
break;
default:
return 0 ;
}
if ( error ) {
F_12 ( & V_21 -> V_2 -> V_8 ,
L_5 , error ) ;
return error ;
}
F_48 ( V_21 ) ;
return 0 ;
}
static void F_57 ( struct V_21 * V_21 )
{
switch ( V_21 -> V_29 . V_49 . type ) {
case V_161 :
case V_162 :
case V_163 :
F_58 ( & V_21 -> V_2 -> V_8 . V_164 ,
& V_165 ) ;
break;
case V_147 :
case V_146 :
F_58 ( & V_21 -> V_2 -> V_8 . V_164 ,
& V_166 ) ;
break;
case V_137 :
case V_167 :
case V_138 :
F_58 ( & V_21 -> V_2 -> V_8 . V_164 ,
& V_168 ) ;
break;
}
}
static int F_59 ( struct V_169 * V_170 ,
enum V_171 V_172 ,
union V_173 * V_174 )
{
struct V_21 * V_21 = F_44 ( V_170 , struct V_21 , V_175 ) ;
int V_176 = 0 ;
switch ( V_172 ) {
case V_177 :
V_174 -> V_178 =
V_21 -> V_29 . V_179 * 100 / 31 ;
break;
default:
V_176 = - V_160 ;
break;
}
return V_176 ;
}
static int F_60 ( struct V_21 * V_21 )
{
int error = 0 ;
if ( V_21 -> V_29 . V_49 . V_180 & V_181 ) {
V_21 -> V_175 . V_182 = V_183 ;
V_21 -> V_175 . V_184 = F_61 ( V_183 ) ;
V_21 -> V_175 . V_185 = F_59 ;
V_21 -> V_175 . V_186 = L_6 ;
V_21 -> V_175 . type = V_187 ;
V_21 -> V_175 . V_188 = 0 ;
error = F_62 ( & V_21 -> V_31 -> V_8 ,
& V_21 -> V_175 ) ;
if ( ! error )
F_63 ( & V_21 -> V_175 ,
& V_21 -> V_31 -> V_8 ) ;
}
return error ;
}
static void F_64 ( struct V_21 * V_21 )
{
if ( V_21 -> V_29 . V_49 . V_180 & V_181 &&
V_21 -> V_175 . V_8 ) {
F_65 ( & V_21 -> V_175 ) ;
V_21 -> V_175 . V_8 = NULL ;
}
}
static int F_66 ( struct V_21 * V_21 )
{
struct V_33 * V_33 ;
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_29 * V_29 = & ( V_21 -> V_29 ) ;
int error ;
V_33 = F_67 () ;
if ( ! V_33 ) {
error = - V_80 ;
goto V_189;
}
V_33 -> V_186 = V_29 -> V_186 ;
V_33 -> V_8 . V_124 = & V_2 -> V_8 ;
V_33 -> V_39 = F_13 ;
V_33 -> V_190 = F_19 ;
F_68 ( V_8 , & V_33 -> V_3 ) ;
F_69 ( V_33 , V_21 ) ;
V_29 -> V_191 = V_33 ;
error = F_70 ( V_33 , V_29 ) ;
if ( error )
goto V_189;
error = F_71 ( V_33 ) ;
if ( error )
goto V_192;
return 0 ;
V_192:
F_72 ( V_33 ) ;
V_29 -> V_191 = NULL ;
V_189:
return error ;
}
static void F_73 ( struct V_193 * V_194 )
{
struct V_21 * V_21 = F_44 ( V_194 , struct V_21 , V_194 ) ;
struct V_7 * V_31 = V_21 -> V_31 ;
struct V_29 * V_29 = & V_21 -> V_29 ;
struct V_21 * V_195 , * V_196 ;
struct V_29 * V_197 , * V_198 ;
int error ;
F_64 ( V_21 ) ;
V_195 = F_74 ( V_31 -> V_199 -> V_112 [ 1 ] ) ;
V_197 = & ( V_195 -> V_29 ) ;
if ( V_197 -> V_191 )
F_75 ( V_197 -> V_191 ) ;
V_197 -> V_191 = NULL ;
V_196 = F_74 ( V_31 -> V_199 -> V_112 [ 2 ] ) ;
V_198 = & ( V_196 -> V_29 ) ;
if ( V_198 -> V_191 )
F_75 ( V_198 -> V_191 ) ;
V_198 -> V_191 = NULL ;
if ( V_29 -> V_200 == 0 ) {
F_76 ( & V_21 -> V_2 -> V_8 , L_7 ) ;
} else {
const struct V_201 * V_3 = V_202 ;
F_76 ( & V_21 -> V_2 -> V_8 ,
L_8 ,
V_29 -> V_200 ) ;
while ( V_3 -> V_203 ) {
if ( V_3 -> V_128 == V_204 &&
V_3 -> V_129 == V_29 -> V_200 )
break;
V_3 ++ ;
}
if ( ! V_3 -> V_203 ) {
F_76 ( & V_21 -> V_2 -> V_8 ,
L_9 ) ;
return;
}
V_197 -> V_49 =
* ( (struct V_48 * ) V_3 -> V_205 ) ;
V_197 -> V_49 . V_64 = V_100 ;
error = F_66 ( V_195 ) ;
if ( error )
goto V_189;
V_198 -> V_49 =
* ( (struct V_48 * ) V_3 -> V_205 ) ;
V_198 -> V_49 . V_62 = V_63 ;
V_198 -> V_49 . V_64 = V_65 ;
F_23 ( & V_198 -> V_49 ) ;
V_198 -> V_49 . V_51 = V_198 -> V_49 . V_55 = 4096 ;
error = F_66 ( V_196 ) ;
if ( error )
goto V_192;
error = F_60 ( V_21 ) ;
if ( error )
goto V_206;
}
return;
V_206:
F_75 ( V_198 -> V_191 ) ;
V_198 -> V_191 = NULL ;
V_192:
F_75 ( V_197 -> V_191 ) ;
V_197 -> V_191 = NULL ;
V_189:
return;
}
static int F_77 ( struct V_1 * V_2 , const struct V_201 * V_3 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_207 * V_119 ;
struct V_21 * V_21 ;
struct V_29 * V_29 ;
struct V_48 * V_49 ;
int error ;
if ( ! V_3 -> V_205 )
return - V_160 ;
V_21 = F_30 ( sizeof( struct V_21 ) , V_37 ) ;
if ( ! V_21 )
return - V_80 ;
V_29 = & V_21 -> V_29 ;
V_29 -> V_49 = * ( (struct V_48 * ) V_3 -> V_205 ) ;
V_49 = & V_29 -> V_49 ;
if ( V_49 -> V_62 > V_208 ) {
error = - V_160 ;
goto V_189;
}
V_29 -> V_131 = F_78 ( V_8 , V_208 ,
V_37 , & V_21 -> V_209 ) ;
if ( ! V_29 -> V_131 ) {
error = - V_80 ;
goto V_189;
}
V_21 -> V_36 = F_79 ( 0 , V_37 ) ;
if ( ! V_21 -> V_36 ) {
error = - V_80 ;
goto V_192;
}
V_21 -> V_31 = V_8 ;
V_21 -> V_2 = V_2 ;
F_80 ( & V_21 -> V_35 ) ;
F_81 ( & V_21 -> V_194 , F_73 ) ;
F_82 ( V_8 , V_21 -> V_210 , sizeof( V_21 -> V_210 ) ) ;
F_83 ( V_21 -> V_210 , L_10 , sizeof( V_21 -> V_210 ) ) ;
V_119 = & V_2 -> V_113 -> V_119 [ 0 ] . V_15 ;
error = F_33 ( V_2 , V_49 ) ;
if ( error )
goto V_206;
if ( V_49 -> type >= V_137 && V_49 -> type <= V_138 ) {
if ( V_119 -> V_211 == V_63 ) {
V_49 -> V_64 = V_65 ;
V_49 -> V_62 = V_63 ;
F_23 ( V_49 ) ;
V_49 -> V_51 = 4096 ;
V_49 -> V_55 = 4096 ;
} else {
V_49 -> V_64 = V_100 ;
}
}
F_84 ( V_49 ) ;
F_85 ( V_29 -> V_186 , V_49 -> V_186 , sizeof( V_29 -> V_186 ) ) ;
if ( V_49 -> V_180 & V_212 ) {
struct V_7 * V_213 ;
F_83 ( V_29 -> V_186 ,
V_49 -> V_64 == V_100 ?
L_11 : L_12 ,
sizeof( V_29 -> V_186 ) ) ;
V_213 = F_35 ( V_8 , V_49 -> V_214 , V_49 -> V_215 ) ;
if ( V_213 == NULL || F_37 ( V_213 ) == NULL )
V_213 = V_8 ;
error = F_40 ( V_29 , V_213 ) ;
if ( error )
goto V_206;
}
F_86 ( V_21 -> V_36 , V_8 ,
F_87 ( V_8 , V_119 -> V_216 ) ,
V_29 -> V_131 , V_49 -> V_62 ,
F_7 , V_21 , V_119 -> V_217 ) ;
V_21 -> V_36 -> V_218 = V_21 -> V_209 ;
V_21 -> V_36 -> V_219 |= V_220 ;
error = F_55 ( V_21 ) ;
if ( error )
goto V_221;
if ( ! ( V_49 -> V_180 & V_222 ) ) {
error = F_66 ( V_21 ) ;
if ( error )
goto V_223;
}
F_32 ( V_2 , V_49 ) ;
F_88 ( V_2 , V_21 ) ;
if ( V_49 -> V_180 & V_181 ) {
if ( F_11 ( V_21 -> V_36 , V_37 ) )
goto V_223;
}
return 0 ;
V_223: F_57 ( V_21 ) ;
V_221: F_46 ( V_29 ) ;
V_206: F_89 ( V_21 -> V_36 ) ;
V_192: F_90 ( V_8 , V_208 , V_29 -> V_131 , V_21 -> V_209 ) ;
V_189: F_28 ( V_21 ) ;
return error ;
}
static void F_91 ( struct V_1 * V_2 )
{
struct V_21 * V_21 = F_74 ( V_2 ) ;
F_88 ( V_2 , NULL ) ;
F_20 ( V_21 -> V_36 ) ;
F_92 ( & V_21 -> V_194 ) ;
if ( V_21 -> V_29 . V_191 )
F_75 ( V_21 -> V_29 . V_191 ) ;
F_64 ( V_21 ) ;
F_57 ( V_21 ) ;
F_89 ( V_21 -> V_36 ) ;
F_90 ( F_2 ( V_2 ) , V_208 ,
V_21 -> V_29 . V_131 , V_21 -> V_209 ) ;
F_46 ( & V_21 -> V_29 ) ;
F_28 ( V_21 ) ;
}
static int F_93 ( struct V_1 * V_2 , T_4 V_224 )
{
struct V_21 * V_21 = F_74 ( V_2 ) ;
F_16 ( & V_21 -> V_35 ) ;
F_20 ( V_21 -> V_36 ) ;
F_17 ( & V_21 -> V_35 ) ;
return 0 ;
}
static int F_94 ( struct V_1 * V_2 )
{
struct V_21 * V_21 = F_74 ( V_2 ) ;
struct V_48 * V_49 = & V_21 -> V_29 . V_49 ;
int V_225 = 0 ;
F_16 ( & V_21 -> V_35 ) ;
F_32 ( V_2 , V_49 ) ;
F_48 ( V_21 ) ;
if ( ( V_21 -> V_39 || V_49 -> V_180 & V_181 )
&& F_11 ( V_21 -> V_36 , V_226 ) < 0 )
V_225 = - V_34 ;
F_17 ( & V_21 -> V_35 ) ;
return V_225 ;
}
static int F_95 ( struct V_1 * V_2 )
{
return F_94 ( V_2 ) ;
}
