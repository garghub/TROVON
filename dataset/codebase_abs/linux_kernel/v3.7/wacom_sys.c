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
if ( V_49 -> type == V_90 ) {
V_49 -> V_62 = V_91 ;
}
if ( V_49 -> type == V_92 || V_49 -> type == V_93 )
V_49 -> V_62 = V_94 ;
if ( V_49 -> type == V_61 ) {
V_49 -> V_62 = V_95 ;
V_49 -> V_52 =
F_25 ( & V_59 [ V_74 + 5 ] ) ;
V_49 -> V_51 =
F_25 ( & V_59 [ V_74 + 8 ] ) ;
V_74 += 15 ;
} else if ( V_49 -> type == V_93 ) {
V_49 -> V_51 =
F_25 ( & V_59 [ V_74 + 3 ] ) ;
V_49 -> V_52 =
F_25 ( & V_59 [ V_74 + 8 ] ) ;
V_49 -> V_44 = V_59 [ V_74 - 1 ] ;
V_49 -> V_53 = V_59 [ V_74 - 3 ] ;
V_74 += 12 ;
} else {
V_49 -> V_51 =
F_25 ( & V_59 [ V_74 + 3 ] ) ;
V_49 -> V_52 =
F_25 ( & V_59 [ V_74 + 6 ] ) ;
V_49 -> V_44 = V_59 [ V_74 + 9 ] ;
V_49 -> V_53 = V_59 [ V_74 + 11 ] ;
V_74 += 12 ;
}
} else if ( V_78 ) {
if ( V_49 -> type == V_90 )
V_49 -> V_62 = V_96 ;
V_49 -> V_64 = V_97 ;
V_49 -> V_51 =
F_25 ( & V_59 [ V_74 + 3 ] ) ;
V_74 += 4 ;
}
}
break;
case V_98 :
if ( V_75 == V_87 ) {
if ( V_77 ) {
int type = V_49 -> type ;
if ( type == V_90 || type == V_92 ) {
V_49 -> V_55 =
F_25 ( & V_59 [ V_74 + 3 ] ) ;
V_49 -> V_56 =
F_25 ( & V_59 [ V_74 + 6 ] ) ;
V_74 += 7 ;
} else if ( type == V_93 ) {
V_49 -> V_55 =
F_25 ( & V_59 [ V_74 + 3 ] ) ;
V_49 -> V_56 =
F_25 ( & V_59 [ V_74 - 2 ] ) ;
V_74 += 7 ;
} else if ( type == V_61 ) {
V_49 -> V_56 =
F_25 ( & V_59 [ V_74 + 3 ] ) ;
V_49 -> V_55 =
F_25 ( & V_59 [ V_74 + 6 ] ) ;
V_74 += 12 ;
} else {
V_49 -> V_55 =
V_49 -> V_51 ;
V_49 -> V_56 =
F_25 ( & V_59 [ V_74 + 3 ] ) ;
V_74 += 4 ;
}
} else if ( V_78 ) {
V_49 -> V_55 =
F_25 ( & V_59 [ V_74 + 3 ] ) ;
V_74 += 4 ;
}
}
break;
case V_99 :
V_77 = 1 ;
V_74 ++ ;
break;
case V_100 :
V_78 = 1 ;
V_74 ++ ;
break;
case V_101 :
if ( ! V_49 -> V_70 )
F_26 ( V_2 , V_49 ) ;
V_74 ++ ;
break;
}
break;
case V_102 :
V_77 = V_75 = 0 ;
break;
case V_103 :
V_74 ++ ;
switch ( V_59 [ V_74 ] ) {
case V_104 :
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
static int F_31 ( struct V_1 * V_2 , int V_105 , int V_60 , int V_106 )
{
unsigned char * V_67 ;
int error = - V_80 , V_73 = 0 ;
V_67 = F_30 ( V_60 , V_37 ) ;
if ( ! V_67 )
return error ;
V_67 [ 0 ] = V_105 ;
V_67 [ 1 ] = V_106 ;
do {
error = F_5 ( V_2 , V_68 ,
V_105 , V_67 , V_60 , 1 ) ;
if ( error >= 0 )
error = F_1 ( V_2 , V_68 ,
V_105 , V_67 , V_60 , 1 ) ;
} while ( ( error < 0 || V_67 [ 1 ] != V_106 ) && V_73 ++ < V_69 );
F_28 ( V_67 ) ;
return error < 0 ? error : 0 ;
}
static int F_32 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
if ( V_49 -> V_64 == V_65 ) {
if ( V_49 -> type > V_107 ) {
return F_31 ( V_2 , 3 , 4 , 4 ) ;
}
else if ( V_49 -> type == V_93 ) {
return F_31 ( V_2 , 18 , 3 , 2 ) ;
}
} else if ( V_49 -> V_64 == V_97 ) {
if ( V_49 -> type <= V_61 && V_49 -> type != V_108 ) {
return F_31 ( V_2 , 2 , 2 , 2 ) ;
}
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_48 * V_49 )
{
int error = 0 ;
struct V_109 * V_110 = V_2 -> V_111 ;
struct V_71 * V_72 ;
V_49 -> V_64 = V_97 ;
V_49 -> V_112 = 4 ;
V_49 -> V_113 = 4 ;
V_49 -> V_114 = 0 ;
V_49 -> V_115 = 0 ;
if ( V_49 -> type == V_108 ) {
if ( V_2 -> V_111 -> V_15 . V_16 == 0 ) {
V_49 -> V_64 = 0 ;
} else if ( V_2 -> V_111 -> V_15 . V_16 == 2 ) {
V_49 -> V_64 = V_65 ;
V_49 -> V_62 = V_63 ;
}
}
if ( V_49 -> type < V_61 ) {
goto V_38;
}
error = F_34 ( V_110 , V_116 , & V_72 ) ;
if ( error ) {
error = F_34 ( & V_110 -> V_117 [ 0 ] ,
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
static struct V_7 * F_35 ( struct V_7 * V_8 , int V_118 , int V_119 )
{
int V_120 ;
struct V_7 * V_121 ;
if ( V_118 == 0 && V_119 == 0 )
return V_8 ;
if ( V_8 -> V_122 == NULL )
return NULL ;
F_36 (dev->parent, port1, sibling) {
struct V_123 * V_124 ;
if ( V_121 == NULL )
continue;
V_124 = & V_121 -> V_125 ;
if ( V_124 -> V_126 == V_118 && V_124 -> V_127 == V_119 )
return V_121 ;
}
return NULL ;
}
static struct V_128 * F_37 ( struct V_7 * V_8 )
{
struct V_128 * V_129 ;
F_38 (data, &wacom_udev_list, list) {
if ( V_129 -> V_8 == V_8 ) {
F_39 ( & V_129 -> V_130 ) ;
return V_129 ;
}
}
return NULL ;
}
static int F_40 ( struct V_29 * V_21 ,
struct V_7 * V_8 )
{
struct V_128 * V_129 ;
int V_9 = 0 ;
F_16 ( & V_131 ) ;
V_129 = F_37 ( V_8 ) ;
if ( ! V_129 ) {
V_129 = F_30 ( sizeof( struct V_128 ) , V_37 ) ;
if ( ! V_129 ) {
V_9 = - V_80 ;
goto V_38;
}
F_41 ( & V_129 -> V_130 ) ;
V_129 -> V_8 = V_8 ;
F_42 ( & V_129 -> V_132 , & V_133 ) ;
}
V_21 -> V_134 = & V_129 -> V_134 ;
V_38:
F_17 ( & V_131 ) ;
return V_9 ;
}
static void F_43 ( struct V_130 * V_130 )
{
struct V_128 * V_129 =
F_44 ( V_130 , struct V_128 , V_130 ) ;
F_16 ( & V_131 ) ;
F_45 ( & V_129 -> V_132 ) ;
F_17 ( & V_131 ) ;
F_28 ( V_129 ) ;
}
static void F_46 ( struct V_29 * V_21 )
{
struct V_128 * V_129 ;
if ( V_21 -> V_134 ) {
V_129 = F_44 ( V_21 -> V_134 , struct V_128 , V_134 ) ;
F_47 ( & V_129 -> V_130 , F_43 ) ;
V_21 -> V_134 = NULL ;
}
}
static int F_48 ( struct V_21 * V_21 )
{
unsigned char * V_4 ;
int V_9 ;
V_4 = F_30 ( 9 , V_37 ) ;
if ( ! V_4 )
return - V_80 ;
if ( V_21 -> V_29 . V_49 . type >= V_135 &&
V_21 -> V_29 . V_49 . type <= V_136 ) {
int V_137 = V_21 -> V_138 . V_139 [ 0 ] & 0x03 ;
int V_140 = ( ( ( V_21 -> V_138 . V_141 & 0x60 ) >> 5 ) - 1 ) & 0x03 ;
int V_142 = 0 ;
V_4 [ 0 ] = V_143 ;
V_4 [ 1 ] = ( V_142 << 4 ) | ( V_140 << 2 ) | ( V_137 ) ;
}
else {
int V_138 = V_21 -> V_138 . V_139 [ 0 ] | 0x4 ;
if ( V_21 -> V_29 . V_49 . type == V_144 ||
V_21 -> V_29 . V_49 . type == V_145 )
V_138 |= ( V_21 -> V_138 . V_139 [ 1 ] << 4 ) | 0x40 ;
V_4 [ 0 ] = V_143 ;
V_4 [ 1 ] = V_138 ;
V_4 [ 2 ] = V_21 -> V_138 . V_141 ;
V_4 [ 3 ] = V_21 -> V_138 . V_146 ;
V_4 [ 4 ] = V_21 -> V_138 . V_147 ;
}
V_9 = F_5 ( V_21 -> V_2 , 0x03 , V_143 ,
V_4 , 9 , V_148 ) ;
F_28 ( V_4 ) ;
return V_9 ;
}
static int F_49 ( struct V_21 * V_21 , int V_149 , const void * V_150 )
{
unsigned char * V_4 ;
int V_74 , V_9 ;
V_4 = F_30 ( 259 , V_37 ) ;
if ( ! V_4 )
return - V_80 ;
V_4 [ 0 ] = V_151 ;
V_4 [ 1 ] = 1 ;
V_9 = F_5 ( V_21 -> V_2 , 0x03 , V_151 ,
V_4 , 2 , V_148 ) ;
if ( V_9 < 0 )
goto V_38;
V_4 [ 0 ] = V_152 ;
V_4 [ 1 ] = V_149 & 0x07 ;
for ( V_74 = 0 ; V_74 < 4 ; V_74 ++ ) {
V_4 [ 2 ] = V_74 ;
memcpy ( V_4 + 3 , V_150 + V_74 * 256 , 256 ) ;
V_9 = F_5 ( V_21 -> V_2 , 0x03 , V_152 ,
V_4 , 259 , V_148 ) ;
if ( V_9 < 0 )
break;
}
V_4 [ 0 ] = V_151 ;
V_4 [ 1 ] = 0 ;
F_5 ( V_21 -> V_2 , 0x03 , V_151 ,
V_4 , 2 , V_148 ) ;
V_38:
F_28 ( V_4 ) ;
return V_9 ;
}
static T_3 F_50 ( struct V_23 * V_8 , int V_153 ,
const char * V_4 , T_2 V_154 )
{
struct V_21 * V_21 = F_51 ( V_8 ) ;
unsigned int V_3 ;
int V_155 ;
V_155 = F_52 ( V_4 , 10 , & V_3 ) ;
if ( V_155 )
return V_155 ;
F_16 ( & V_21 -> V_35 ) ;
V_21 -> V_138 . V_139 [ V_153 ] = V_3 & 0x3 ;
V_155 = F_48 ( V_21 ) ;
F_17 ( & V_21 -> V_35 ) ;
return V_155 < 0 ? V_155 : V_154 ;
}
static T_3 F_53 ( struct V_21 * V_21 , T_1 * V_156 ,
const char * V_4 , T_2 V_154 )
{
unsigned int V_157 ;
int V_155 ;
V_155 = F_52 ( V_4 , 10 , & V_157 ) ;
if ( V_155 )
return V_155 ;
F_16 ( & V_21 -> V_35 ) ;
* V_156 = V_157 & 0x7f ;
V_155 = F_48 ( V_21 ) ;
F_17 ( & V_21 -> V_35 ) ;
return V_155 < 0 ? V_155 : V_154 ;
}
static T_3 F_54 ( struct V_23 * V_8 , int V_149 ,
const char * V_4 , T_2 V_154 )
{
struct V_21 * V_21 = F_51 ( V_8 ) ;
int V_155 ;
if ( V_154 != 1024 )
return - V_158 ;
F_16 ( & V_21 -> V_35 ) ;
V_155 = F_49 ( V_21 , V_149 , V_4 ) ;
F_17 ( & V_21 -> V_35 ) ;
return V_155 < 0 ? V_155 : V_154 ;
}
static int F_55 ( struct V_21 * V_21 )
{
int error ;
switch ( V_21 -> V_29 . V_49 . type ) {
case V_159 :
case V_160 :
case V_161 :
V_21 -> V_138 . V_139 [ 0 ] = 0 ;
V_21 -> V_138 . V_139 [ 1 ] = 0 ;
V_21 -> V_138 . V_141 = 10 ;
V_21 -> V_138 . V_146 = 20 ;
V_21 -> V_138 . V_147 = 10 ;
error = F_56 ( & V_21 -> V_2 -> V_8 . V_162 ,
& V_163 ) ;
break;
case V_145 :
case V_144 :
V_21 -> V_138 . V_139 [ 0 ] = 0 ;
V_21 -> V_138 . V_139 [ 1 ] = 0 ;
V_21 -> V_138 . V_141 = 0 ;
V_21 -> V_138 . V_146 = 0 ;
V_21 -> V_138 . V_147 = 0 ;
error = F_56 ( & V_21 -> V_2 -> V_8 . V_162 ,
& V_164 ) ;
break;
case V_135 :
case V_165 :
case V_136 :
V_21 -> V_138 . V_139 [ 0 ] = 0 ;
V_21 -> V_138 . V_139 [ 1 ] = 0 ;
V_21 -> V_138 . V_141 = 32 ;
V_21 -> V_138 . V_146 = 0 ;
V_21 -> V_138 . V_147 = 0 ;
error = F_56 ( & V_21 -> V_2 -> V_8 . V_162 ,
& V_166 ) ;
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
case V_159 :
case V_160 :
case V_161 :
F_58 ( & V_21 -> V_2 -> V_8 . V_162 ,
& V_163 ) ;
break;
case V_145 :
case V_144 :
F_58 ( & V_21 -> V_2 -> V_8 . V_162 ,
& V_164 ) ;
break;
case V_135 :
case V_165 :
case V_136 :
F_58 ( & V_21 -> V_2 -> V_8 . V_162 ,
& V_166 ) ;
break;
}
}
static int F_59 ( struct V_167 * V_168 ,
enum V_169 V_170 ,
union V_171 * V_172 )
{
struct V_21 * V_21 = F_44 ( V_168 , struct V_21 , V_173 ) ;
int V_174 = 0 ;
switch ( V_170 ) {
case V_175 :
V_172 -> V_176 =
V_21 -> V_29 . V_177 * 100 / 31 ;
break;
default:
V_174 = - V_158 ;
break;
}
return V_174 ;
}
static int F_60 ( struct V_21 * V_21 )
{
int error = 0 ;
if ( V_21 -> V_29 . V_49 . V_178 & V_179 ) {
V_21 -> V_173 . V_180 = V_181 ;
V_21 -> V_173 . V_182 = F_61 ( V_181 ) ;
V_21 -> V_173 . V_183 = F_59 ;
V_21 -> V_173 . V_184 = L_6 ;
V_21 -> V_173 . type = V_185 ;
V_21 -> V_173 . V_186 = 0 ;
error = F_62 ( & V_21 -> V_31 -> V_8 ,
& V_21 -> V_173 ) ;
if ( ! error )
F_63 ( & V_21 -> V_173 ,
& V_21 -> V_31 -> V_8 ) ;
}
return error ;
}
static void F_64 ( struct V_21 * V_21 )
{
if ( V_21 -> V_29 . V_49 . V_178 & V_179 &&
V_21 -> V_173 . V_8 ) {
F_65 ( & V_21 -> V_173 ) ;
V_21 -> V_173 . V_8 = NULL ;
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
goto V_187;
}
V_33 -> V_184 = V_29 -> V_184 ;
V_33 -> V_8 . V_122 = & V_2 -> V_8 ;
V_33 -> V_39 = F_13 ;
V_33 -> V_188 = F_19 ;
F_68 ( V_8 , & V_33 -> V_3 ) ;
F_69 ( V_33 , V_21 ) ;
V_29 -> V_189 = V_33 ;
error = F_70 ( V_33 , V_29 ) ;
if ( error )
goto V_187;
error = F_71 ( V_33 ) ;
if ( error )
goto V_190;
return 0 ;
V_190:
F_72 ( V_33 ) ;
V_29 -> V_189 = NULL ;
V_187:
return error ;
}
static void F_73 ( struct V_191 * V_192 )
{
struct V_21 * V_21 = F_44 ( V_192 , struct V_21 , V_192 ) ;
struct V_7 * V_31 = V_21 -> V_31 ;
struct V_29 * V_29 = & V_21 -> V_29 ;
struct V_21 * V_193 , * V_194 ;
struct V_29 * V_195 , * V_196 ;
int error ;
F_64 ( V_21 ) ;
V_193 = F_74 ( V_31 -> V_197 -> V_110 [ 1 ] ) ;
V_195 = & ( V_193 -> V_29 ) ;
if ( V_195 -> V_189 )
F_75 ( V_195 -> V_189 ) ;
V_195 -> V_189 = NULL ;
V_194 = F_74 ( V_31 -> V_197 -> V_110 [ 2 ] ) ;
V_196 = & ( V_194 -> V_29 ) ;
if ( V_196 -> V_189 )
F_75 ( V_196 -> V_189 ) ;
V_196 -> V_189 = NULL ;
if ( V_29 -> V_198 == 0 ) {
F_76 ( & V_21 -> V_2 -> V_8 , L_7 ) ;
} else {
const struct V_199 * V_3 = V_200 ;
F_76 ( & V_21 -> V_2 -> V_8 ,
L_8 ,
V_29 -> V_198 ) ;
while ( V_3 -> V_201 ) {
if ( V_3 -> V_126 == V_202 &&
V_3 -> V_127 == V_29 -> V_198 )
break;
V_3 ++ ;
}
if ( ! V_3 -> V_201 ) {
F_76 ( & V_21 -> V_2 -> V_8 ,
L_9 ) ;
return;
}
V_195 -> V_49 =
* ( (struct V_48 * ) V_3 -> V_203 ) ;
V_195 -> V_49 . V_64 = V_97 ;
error = F_66 ( V_193 ) ;
if ( error )
goto V_187;
V_196 -> V_49 =
* ( (struct V_48 * ) V_3 -> V_203 ) ;
V_196 -> V_49 . V_62 = V_63 ;
V_196 -> V_49 . V_64 = V_65 ;
F_23 ( & V_196 -> V_49 ) ;
V_196 -> V_49 . V_51 = V_196 -> V_49 . V_55 = 4096 ;
error = F_66 ( V_194 ) ;
if ( error )
goto V_190;
error = F_60 ( V_21 ) ;
if ( error )
goto V_204;
}
return;
V_204:
F_75 ( V_196 -> V_189 ) ;
V_196 -> V_189 = NULL ;
V_190:
F_75 ( V_195 -> V_189 ) ;
V_195 -> V_189 = NULL ;
V_187:
return;
}
static int F_77 ( struct V_1 * V_2 , const struct V_199 * V_3 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_205 * V_117 ;
struct V_21 * V_21 ;
struct V_29 * V_29 ;
struct V_48 * V_49 ;
int error ;
if ( ! V_3 -> V_203 )
return - V_158 ;
V_21 = F_30 ( sizeof( struct V_21 ) , V_37 ) ;
if ( ! V_21 )
return - V_80 ;
V_29 = & V_21 -> V_29 ;
V_29 -> V_49 = * ( (struct V_48 * ) V_3 -> V_203 ) ;
V_49 = & V_29 -> V_49 ;
if ( V_49 -> V_62 > V_206 ) {
error = - V_158 ;
goto V_187;
}
V_29 -> V_129 = F_78 ( V_8 , V_206 ,
V_37 , & V_21 -> V_207 ) ;
if ( ! V_29 -> V_129 ) {
error = - V_80 ;
goto V_187;
}
V_21 -> V_36 = F_79 ( 0 , V_37 ) ;
if ( ! V_21 -> V_36 ) {
error = - V_80 ;
goto V_190;
}
V_21 -> V_31 = V_8 ;
V_21 -> V_2 = V_2 ;
F_80 ( & V_21 -> V_35 ) ;
F_81 ( & V_21 -> V_192 , F_73 ) ;
F_82 ( V_8 , V_21 -> V_208 , sizeof( V_21 -> V_208 ) ) ;
F_83 ( V_21 -> V_208 , L_10 , sizeof( V_21 -> V_208 ) ) ;
V_117 = & V_2 -> V_111 -> V_117 [ 0 ] . V_15 ;
error = F_33 ( V_2 , V_49 ) ;
if ( error )
goto V_204;
if ( V_49 -> type >= V_135 && V_49 -> type <= V_136 ) {
if ( V_117 -> V_209 == V_63 ) {
V_49 -> V_64 = V_65 ;
V_49 -> V_62 = V_63 ;
F_23 ( V_49 ) ;
V_49 -> V_51 = 4096 ;
V_49 -> V_55 = 4096 ;
} else {
V_49 -> V_64 = V_97 ;
}
}
F_84 ( V_49 ) ;
F_85 ( V_29 -> V_184 , V_49 -> V_184 , sizeof( V_29 -> V_184 ) ) ;
if ( V_49 -> V_178 & V_210 ) {
struct V_7 * V_211 ;
F_83 ( V_29 -> V_184 ,
V_49 -> V_64 == V_97 ?
L_11 : L_12 ,
sizeof( V_29 -> V_184 ) ) ;
V_211 = F_35 ( V_8 , V_49 -> V_212 , V_49 -> V_213 ) ;
if ( V_211 == NULL || F_37 ( V_211 ) == NULL )
V_211 = V_8 ;
error = F_40 ( V_29 , V_211 ) ;
if ( error )
goto V_204;
}
F_86 ( V_21 -> V_36 , V_8 ,
F_87 ( V_8 , V_117 -> V_214 ) ,
V_29 -> V_129 , V_49 -> V_62 ,
F_7 , V_21 , V_117 -> V_215 ) ;
V_21 -> V_36 -> V_216 = V_21 -> V_207 ;
V_21 -> V_36 -> V_217 |= V_218 ;
error = F_55 ( V_21 ) ;
if ( error )
goto V_219;
if ( ! ( V_49 -> V_178 & V_220 ) ) {
error = F_66 ( V_21 ) ;
if ( error )
goto V_221;
}
F_32 ( V_2 , V_49 ) ;
F_88 ( V_2 , V_21 ) ;
if ( V_49 -> V_178 & V_179 ) {
if ( F_11 ( V_21 -> V_36 , V_37 ) )
goto V_221;
}
return 0 ;
V_221: F_57 ( V_21 ) ;
V_219: F_46 ( V_29 ) ;
V_204: F_89 ( V_21 -> V_36 ) ;
V_190: F_90 ( V_8 , V_206 , V_29 -> V_129 , V_21 -> V_207 ) ;
V_187: F_28 ( V_21 ) ;
return error ;
}
static void F_91 ( struct V_1 * V_2 )
{
struct V_21 * V_21 = F_74 ( V_2 ) ;
F_88 ( V_2 , NULL ) ;
F_20 ( V_21 -> V_36 ) ;
F_92 ( & V_21 -> V_192 ) ;
if ( V_21 -> V_29 . V_189 )
F_75 ( V_21 -> V_29 . V_189 ) ;
F_64 ( V_21 ) ;
F_57 ( V_21 ) ;
F_89 ( V_21 -> V_36 ) ;
F_90 ( F_2 ( V_2 ) , V_206 ,
V_21 -> V_29 . V_129 , V_21 -> V_207 ) ;
F_46 ( & V_21 -> V_29 ) ;
F_28 ( V_21 ) ;
}
static int F_93 ( struct V_1 * V_2 , T_4 V_222 )
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
int V_223 = 0 ;
F_16 ( & V_21 -> V_35 ) ;
F_32 ( V_2 , V_49 ) ;
F_48 ( V_21 ) ;
if ( ( V_21 -> V_39 || V_49 -> V_178 & V_179 )
&& F_11 ( V_21 -> V_36 , V_224 ) < 0 )
V_223 = - V_34 ;
F_17 ( & V_21 -> V_35 ) ;
return V_223 ;
}
static int F_95 ( struct V_1 * V_2 )
{
return F_94 ( V_2 ) ;
}
