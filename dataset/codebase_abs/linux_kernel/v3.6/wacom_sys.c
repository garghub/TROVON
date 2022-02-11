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
static void F_21 ( struct V_42 * V_43 )
{
V_43 -> V_44 = ( V_43 -> V_45 * 100 ) / V_43 -> V_46 ;
V_43 -> V_47 = ( V_43 -> V_48 * 100 ) / V_43 -> V_49 ;
}
static int F_22 ( unsigned char * V_50 ,
struct V_42 * V_43 )
{
int V_51 = 0 ;
if ( V_43 -> type == V_52 ) {
V_43 -> V_53 = V_54 ;
V_43 -> V_55 = V_56 ;
F_21 ( V_43 ) ;
V_43 -> V_45 = V_43 -> V_48 =
F_23 ( & V_50 [ 10 ] ) ;
V_51 = 11 ;
}
return V_51 ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
int V_57 = 0 ;
unsigned char * V_58 ;
V_58 = F_25 ( 2 , V_37 ) ;
if ( V_58 ) {
V_58 [ 0 ] = 12 ;
V_57 = F_1 ( V_2 , V_59 ,
V_58 [ 0 ] , V_58 , 2 ,
V_60 ) ;
if ( V_57 >= 0 && V_58 [ 1 ] > 2 )
V_43 -> V_61 = V_58 [ 1 ] ;
F_26 ( V_58 ) ;
}
}
static int F_27 ( struct V_1 * V_2 ,
struct V_62 * V_63 ,
struct V_42 * V_43 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
char V_64 = 0 ;
int V_57 = 0 ;
int V_65 = 0 , V_66 = V_67 , V_68 = 0 , V_69 = 0 ;
unsigned char * V_50 ;
V_50 = F_28 ( V_63 -> V_70 , V_37 ) ;
if ( ! V_50 )
return - V_71 ;
do {
V_57 = F_3 ( V_8 , F_4 ( V_8 , 0 ) ,
V_72 ,
V_13 | V_11 ,
V_73 << 8 ,
V_2 -> V_14 [ 0 ] . V_15 . V_16 ,
V_50 ,
V_63 -> V_70 ,
5000 ) ;
} while ( V_57 < 0 && V_64 ++ < V_60 );
if ( V_57 < 0 )
goto V_38;
for ( V_65 = 0 ; V_65 < V_63 -> V_70 ; V_65 ++ ) {
switch ( V_50 [ V_65 ] ) {
case V_74 :
switch ( V_50 [ V_65 + 1 ] ) {
case V_75 :
V_66 = V_76 ;
V_65 ++ ;
break;
case V_77 :
V_66 = V_78 ;
V_65 ++ ;
break;
}
break;
case V_79 :
switch ( V_50 [ V_65 + 1 ] ) {
case V_80 :
if ( V_66 == V_78 ) {
if ( V_68 ) {
V_43 -> V_55 = V_56 ;
if ( V_43 -> type == V_81 ) {
V_43 -> V_53 = V_82 ;
}
if ( V_43 -> type == V_83 )
V_43 -> V_53 = V_84 ;
if ( V_43 -> type == V_52 ) {
V_43 -> V_53 = V_85 ;
V_43 -> V_44 =
F_23 ( & V_50 [ V_65 + 5 ] ) ;
V_43 -> V_45 =
F_23 ( & V_50 [ V_65 + 8 ] ) ;
V_65 += 15 ;
} else {
V_43 -> V_45 =
F_23 ( & V_50 [ V_65 + 3 ] ) ;
V_43 -> V_44 =
F_23 ( & V_50 [ V_65 + 6 ] ) ;
V_43 -> V_86 = V_50 [ V_65 + 9 ] ;
V_43 -> V_87 = V_50 [ V_65 + 11 ] ;
V_65 += 12 ;
}
} else if ( V_69 ) {
if ( V_43 -> type == V_81 )
V_43 -> V_53 = V_88 ;
V_43 -> V_55 = V_89 ;
V_43 -> V_45 =
F_23 ( & V_50 [ V_65 + 3 ] ) ;
V_65 += 4 ;
}
}
break;
case V_90 :
if ( V_66 == V_78 ) {
if ( V_68 ) {
int type = V_43 -> type ;
if ( type == V_81 || type == V_83 ) {
V_43 -> V_48 =
F_23 ( & V_50 [ V_65 + 3 ] ) ;
V_43 -> V_47 =
F_23 ( & V_50 [ V_65 + 6 ] ) ;
V_65 += 7 ;
} else if ( type == V_52 ) {
V_43 -> V_47 =
F_23 ( & V_50 [ V_65 + 3 ] ) ;
V_43 -> V_48 =
F_23 ( & V_50 [ V_65 + 6 ] ) ;
V_65 += 12 ;
} else {
V_43 -> V_48 =
V_43 -> V_45 ;
V_43 -> V_47 =
F_23 ( & V_50 [ V_65 + 3 ] ) ;
V_65 += 4 ;
}
} else if ( V_69 ) {
V_43 -> V_48 =
F_23 ( & V_50 [ V_65 + 3 ] ) ;
V_65 += 4 ;
}
}
break;
case V_91 :
V_68 = 1 ;
V_65 ++ ;
break;
case V_92 :
V_69 = 1 ;
V_65 ++ ;
break;
case V_93 :
if ( ! V_43 -> V_61 )
F_24 ( V_2 , V_43 ) ;
V_65 ++ ;
break;
}
break;
case V_94 :
V_68 = V_66 = 0 ;
break;
case V_95 :
V_65 ++ ;
switch ( V_50 [ V_65 ] ) {
case V_96 :
V_65 += F_22 ( & V_50 [ V_65 ] ,
V_43 ) ;
break;
}
break;
}
}
V_38:
V_57 = 0 ;
F_26 ( V_50 ) ;
return V_57 ;
}
static int F_29 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
unsigned char * V_58 ;
int V_64 = 0 , V_97 = 2 ;
int error = - V_71 ;
V_58 = F_25 ( 4 , V_37 ) ;
if ( ! V_58 )
return error ;
if ( V_43 -> V_55 == V_56 ) {
if ( V_43 -> type > V_98 ) {
do {
V_58 [ 0 ] = 3 ;
V_58 [ 1 ] = 4 ;
V_58 [ 2 ] = 0 ;
V_58 [ 3 ] = 0 ;
V_97 = 3 ;
error = F_5 ( V_2 ,
V_59 ,
V_97 ,
V_58 , 4 , 1 ) ;
if ( error >= 0 )
error = F_1 ( V_2 ,
V_59 ,
V_97 ,
V_58 , 4 , 1 ) ;
} while ( ( error < 0 || V_58 [ 1 ] != 4 ) &&
V_64 ++ < V_60 );
}
} else if ( V_43 -> type <= V_52 &&
V_43 -> type != V_99 &&
V_43 -> V_55 == V_89 ) {
do {
V_58 [ 0 ] = 2 ;
V_58 [ 1 ] = 2 ;
error = F_5 ( V_2 , V_59 ,
V_97 , V_58 , 2 , 1 ) ;
if ( error >= 0 )
error = F_1 ( V_2 ,
V_59 ,
V_97 , V_58 , 2 , 1 ) ;
} while ( ( error < 0 || V_58 [ 1 ] != 2 ) && V_64 ++ < V_60 );
}
F_26 ( V_58 ) ;
return error < 0 ? error : 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
int error = 0 ;
struct V_100 * V_101 = V_2 -> V_102 ;
struct V_62 * V_63 ;
V_43 -> V_55 = V_89 ;
V_43 -> V_103 = 4 ;
V_43 -> V_104 = 4 ;
V_43 -> V_105 = 0 ;
V_43 -> V_106 = 0 ;
if ( V_43 -> type == V_99 ) {
if ( V_2 -> V_102 -> V_15 . V_16 == 0 ) {
V_43 -> V_55 = 0 ;
} else if ( V_2 -> V_102 -> V_15 . V_16 == 2 ) {
V_43 -> V_55 = V_56 ;
V_43 -> V_53 = V_54 ;
}
}
if ( V_43 -> type < V_52 ) {
goto V_38;
}
error = F_31 ( V_101 , V_107 , & V_63 ) ;
if ( error ) {
error = F_31 ( & V_101 -> V_108 [ 0 ] ,
V_73 , & V_63 ) ;
if ( error ) {
F_12 ( & V_2 -> V_8 ,
L_4 ) ;
goto V_38;
}
}
error = F_27 ( V_2 , V_63 , V_43 ) ;
if ( error )
goto V_38;
V_38:
return error ;
}
static struct V_109 * F_32 ( struct V_7 * V_8 )
{
struct V_109 * V_110 ;
F_33 (data, &wacom_udev_list, list) {
if ( V_110 -> V_8 == V_8 ) {
F_34 ( & V_110 -> V_111 ) ;
return V_110 ;
}
}
return NULL ;
}
static int F_35 ( struct V_29 * V_21 ,
struct V_7 * V_8 )
{
struct V_109 * V_110 ;
int V_9 = 0 ;
F_16 ( & V_112 ) ;
V_110 = F_32 ( V_8 ) ;
if ( ! V_110 ) {
V_110 = F_28 ( sizeof( struct V_109 ) , V_37 ) ;
if ( ! V_110 ) {
V_9 = - V_71 ;
goto V_38;
}
F_36 ( & V_110 -> V_111 ) ;
V_110 -> V_8 = V_8 ;
F_37 ( & V_110 -> V_113 , & V_114 ) ;
}
V_21 -> V_115 = & V_110 -> V_115 ;
V_38:
F_17 ( & V_112 ) ;
return V_9 ;
}
static void F_38 ( struct V_111 * V_111 )
{
struct V_109 * V_110 =
F_39 ( V_111 , struct V_109 , V_111 ) ;
F_16 ( & V_112 ) ;
F_40 ( & V_110 -> V_113 ) ;
F_17 ( & V_112 ) ;
F_26 ( V_110 ) ;
}
static void F_41 ( struct V_29 * V_21 )
{
struct V_109 * V_110 ;
if ( V_21 -> V_115 ) {
V_110 = F_39 ( V_21 -> V_115 , struct V_109 , V_115 ) ;
F_42 ( & V_110 -> V_111 , F_38 ) ;
V_21 -> V_115 = NULL ;
}
}
static int F_43 ( struct V_21 * V_21 )
{
unsigned char * V_4 ;
int V_9 ;
V_4 = F_28 ( 9 , V_37 ) ;
if ( ! V_4 )
return - V_71 ;
if ( V_21 -> V_29 . V_43 . type >= V_116 &&
V_21 -> V_29 . V_43 . type <= V_117 ) {
int V_118 = V_21 -> V_119 . V_120 [ 0 ] & 0x03 ;
int V_121 = ( ( ( V_21 -> V_119 . V_122 & 0x60 ) >> 5 ) - 1 ) & 0x03 ;
int V_123 = 0 ;
V_4 [ 0 ] = V_124 ;
V_4 [ 1 ] = ( V_123 << 4 ) | ( V_121 << 2 ) | ( V_118 ) ;
}
else {
int V_119 = V_21 -> V_119 . V_120 [ 0 ] | 0x4 ;
if ( V_21 -> V_29 . V_43 . type == V_125 ||
V_21 -> V_29 . V_43 . type == V_126 )
V_119 |= ( V_21 -> V_119 . V_120 [ 1 ] << 4 ) | 0x40 ;
V_4 [ 0 ] = V_124 ;
V_4 [ 1 ] = V_119 ;
V_4 [ 2 ] = V_21 -> V_119 . V_122 ;
V_4 [ 3 ] = V_21 -> V_119 . V_127 ;
V_4 [ 4 ] = V_21 -> V_119 . V_128 ;
}
V_9 = F_5 ( V_21 -> V_2 , 0x03 , V_124 ,
V_4 , 9 , V_129 ) ;
F_26 ( V_4 ) ;
return V_9 ;
}
static int F_44 ( struct V_21 * V_21 , int V_130 , const void * V_131 )
{
unsigned char * V_4 ;
int V_65 , V_9 ;
V_4 = F_28 ( 259 , V_37 ) ;
if ( ! V_4 )
return - V_71 ;
V_4 [ 0 ] = V_132 ;
V_4 [ 1 ] = 1 ;
V_9 = F_5 ( V_21 -> V_2 , 0x03 , V_132 ,
V_4 , 2 , V_129 ) ;
if ( V_9 < 0 )
goto V_38;
V_4 [ 0 ] = V_133 ;
V_4 [ 1 ] = V_130 & 0x07 ;
for ( V_65 = 0 ; V_65 < 4 ; V_65 ++ ) {
V_4 [ 2 ] = V_65 ;
memcpy ( V_4 + 3 , V_131 + V_65 * 256 , 256 ) ;
V_9 = F_5 ( V_21 -> V_2 , 0x03 , V_133 ,
V_4 , 259 , V_129 ) ;
if ( V_9 < 0 )
break;
}
V_4 [ 0 ] = V_132 ;
V_4 [ 1 ] = 0 ;
F_5 ( V_21 -> V_2 , 0x03 , V_132 ,
V_4 , 2 , V_129 ) ;
V_38:
F_26 ( V_4 ) ;
return V_9 ;
}
static T_3 F_45 ( struct V_23 * V_8 , int V_134 ,
const char * V_4 , T_2 V_135 )
{
struct V_21 * V_21 = F_46 ( V_8 ) ;
unsigned int V_3 ;
int V_136 ;
V_136 = F_47 ( V_4 , 10 , & V_3 ) ;
if ( V_136 )
return V_136 ;
F_16 ( & V_21 -> V_35 ) ;
V_21 -> V_119 . V_120 [ V_134 ] = V_3 & 0x3 ;
V_136 = F_43 ( V_21 ) ;
F_17 ( & V_21 -> V_35 ) ;
return V_136 < 0 ? V_136 : V_135 ;
}
static T_3 F_48 ( struct V_21 * V_21 , T_1 * V_137 ,
const char * V_4 , T_2 V_135 )
{
unsigned int V_138 ;
int V_136 ;
V_136 = F_47 ( V_4 , 10 , & V_138 ) ;
if ( V_136 )
return V_136 ;
F_16 ( & V_21 -> V_35 ) ;
* V_137 = V_138 & 0x7f ;
V_136 = F_43 ( V_21 ) ;
F_17 ( & V_21 -> V_35 ) ;
return V_136 < 0 ? V_136 : V_135 ;
}
static T_3 F_49 ( struct V_23 * V_8 , int V_130 ,
const char * V_4 , T_2 V_135 )
{
struct V_21 * V_21 = F_46 ( V_8 ) ;
int V_136 ;
if ( V_135 != 1024 )
return - V_139 ;
F_16 ( & V_21 -> V_35 ) ;
V_136 = F_44 ( V_21 , V_130 , V_4 ) ;
F_17 ( & V_21 -> V_35 ) ;
return V_136 < 0 ? V_136 : V_135 ;
}
static int F_50 ( struct V_21 * V_21 )
{
int error ;
switch ( V_21 -> V_29 . V_43 . type ) {
case V_140 :
case V_141 :
case V_142 :
V_21 -> V_119 . V_120 [ 0 ] = 0 ;
V_21 -> V_119 . V_120 [ 1 ] = 0 ;
V_21 -> V_119 . V_122 = 10 ;
V_21 -> V_119 . V_127 = 20 ;
V_21 -> V_119 . V_128 = 10 ;
error = F_51 ( & V_21 -> V_2 -> V_8 . V_143 ,
& V_144 ) ;
break;
case V_126 :
case V_125 :
V_21 -> V_119 . V_120 [ 0 ] = 0 ;
V_21 -> V_119 . V_120 [ 1 ] = 0 ;
V_21 -> V_119 . V_122 = 0 ;
V_21 -> V_119 . V_127 = 0 ;
V_21 -> V_119 . V_128 = 0 ;
error = F_51 ( & V_21 -> V_2 -> V_8 . V_143 ,
& V_145 ) ;
break;
case V_116 :
case V_146 :
case V_117 :
V_21 -> V_119 . V_120 [ 0 ] = 0 ;
V_21 -> V_119 . V_120 [ 1 ] = 0 ;
V_21 -> V_119 . V_122 = 32 ;
V_21 -> V_119 . V_127 = 0 ;
V_21 -> V_119 . V_128 = 0 ;
error = F_51 ( & V_21 -> V_2 -> V_8 . V_143 ,
& V_147 ) ;
break;
default:
return 0 ;
}
if ( error ) {
F_12 ( & V_21 -> V_2 -> V_8 ,
L_5 , error ) ;
return error ;
}
F_43 ( V_21 ) ;
return 0 ;
}
static void F_52 ( struct V_21 * V_21 )
{
switch ( V_21 -> V_29 . V_43 . type ) {
case V_140 :
case V_141 :
case V_142 :
F_53 ( & V_21 -> V_2 -> V_8 . V_143 ,
& V_144 ) ;
break;
case V_126 :
case V_125 :
F_53 ( & V_21 -> V_2 -> V_8 . V_143 ,
& V_145 ) ;
break;
case V_116 :
case V_146 :
case V_117 :
F_53 ( & V_21 -> V_2 -> V_8 . V_143 ,
& V_147 ) ;
break;
}
}
static int F_54 ( struct V_148 * V_149 ,
enum V_150 V_151 ,
union V_152 * V_153 )
{
struct V_21 * V_21 = F_39 ( V_149 , struct V_21 , V_154 ) ;
int V_155 = 0 ;
switch ( V_151 ) {
case V_156 :
V_153 -> V_157 =
V_21 -> V_29 . V_158 * 100 / 31 ;
break;
default:
V_155 = - V_139 ;
break;
}
return V_155 ;
}
static int F_55 ( struct V_21 * V_21 )
{
int error = 0 ;
if ( V_21 -> V_29 . V_43 . V_159 & V_160 ) {
V_21 -> V_154 . V_161 = V_162 ;
V_21 -> V_154 . V_163 = F_56 ( V_162 ) ;
V_21 -> V_154 . V_164 = F_54 ;
V_21 -> V_154 . V_165 = L_6 ;
V_21 -> V_154 . type = V_166 ;
V_21 -> V_154 . V_167 = 0 ;
error = F_57 ( & V_21 -> V_31 -> V_8 ,
& V_21 -> V_154 ) ;
if ( ! error )
F_58 ( & V_21 -> V_154 ,
& V_21 -> V_31 -> V_8 ) ;
}
return error ;
}
static void F_59 ( struct V_21 * V_21 )
{
if ( V_21 -> V_29 . V_43 . V_159 & V_160 &&
V_21 -> V_154 . V_8 ) {
F_60 ( & V_21 -> V_154 ) ;
V_21 -> V_154 . V_8 = NULL ;
}
}
static int F_61 ( struct V_21 * V_21 )
{
struct V_33 * V_33 ;
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_29 * V_29 = & ( V_21 -> V_29 ) ;
int error ;
V_33 = F_62 () ;
if ( ! V_33 ) {
error = - V_71 ;
goto V_168;
}
V_33 -> V_165 = V_29 -> V_165 ;
V_33 -> V_8 . V_169 = & V_2 -> V_8 ;
V_33 -> V_39 = F_13 ;
V_33 -> V_170 = F_19 ;
F_63 ( V_8 , & V_33 -> V_3 ) ;
F_64 ( V_33 , V_21 ) ;
V_29 -> V_171 = V_33 ;
error = F_65 ( V_33 , V_29 ) ;
if ( error )
goto V_168;
error = F_66 ( V_33 ) ;
if ( error )
goto V_172;
return 0 ;
V_172:
F_67 ( V_33 ) ;
V_29 -> V_171 = NULL ;
V_168:
return error ;
}
static void F_68 ( struct V_173 * V_174 )
{
struct V_21 * V_21 = F_39 ( V_174 , struct V_21 , V_174 ) ;
struct V_7 * V_31 = V_21 -> V_31 ;
struct V_29 * V_29 = & V_21 -> V_29 ;
struct V_21 * V_175 , * V_176 ;
struct V_29 * V_177 , * V_178 ;
int error ;
F_59 ( V_21 ) ;
V_175 = F_69 ( V_31 -> V_179 -> V_101 [ 1 ] ) ;
V_177 = & ( V_175 -> V_29 ) ;
if ( V_177 -> V_171 )
F_70 ( V_177 -> V_171 ) ;
V_177 -> V_171 = NULL ;
V_176 = F_69 ( V_31 -> V_179 -> V_101 [ 2 ] ) ;
V_178 = & ( V_176 -> V_29 ) ;
if ( V_178 -> V_171 )
F_70 ( V_178 -> V_171 ) ;
V_178 -> V_171 = NULL ;
if ( V_29 -> V_180 == 0 ) {
F_71 ( & V_21 -> V_2 -> V_8 , L_7 ) ;
} else {
const struct V_181 * V_3 = V_182 ;
F_71 ( & V_21 -> V_2 -> V_8 ,
L_8 ,
V_29 -> V_180 ) ;
while ( V_3 -> V_183 ) {
if ( V_3 -> V_184 == V_185 &&
V_3 -> V_186 == V_29 -> V_180 )
break;
V_3 ++ ;
}
if ( ! V_3 -> V_183 ) {
F_71 ( & V_21 -> V_2 -> V_8 ,
L_9 ) ;
return;
}
V_177 -> V_43 =
* ( (struct V_42 * ) V_3 -> V_187 ) ;
V_177 -> V_43 . V_55 = V_89 ;
error = F_61 ( V_175 ) ;
if ( error )
goto V_168;
V_178 -> V_43 =
* ( (struct V_42 * ) V_3 -> V_187 ) ;
V_178 -> V_43 . V_53 = V_54 ;
V_178 -> V_43 . V_55 = V_56 ;
F_21 ( & V_178 -> V_43 ) ;
V_178 -> V_43 . V_45 = V_178 -> V_43 . V_48 = 4096 ;
error = F_61 ( V_176 ) ;
if ( error )
goto V_172;
error = F_55 ( V_21 ) ;
if ( error )
goto V_188;
}
return;
V_188:
F_70 ( V_178 -> V_171 ) ;
V_178 -> V_171 = NULL ;
V_172:
F_70 ( V_177 -> V_171 ) ;
V_177 -> V_171 = NULL ;
V_168:
return;
}
static int F_72 ( struct V_1 * V_2 , const struct V_181 * V_3 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_189 * V_108 ;
struct V_21 * V_21 ;
struct V_29 * V_29 ;
struct V_42 * V_43 ;
int error ;
if ( ! V_3 -> V_187 )
return - V_139 ;
V_21 = F_28 ( sizeof( struct V_21 ) , V_37 ) ;
if ( ! V_21 )
return - V_71 ;
V_29 = & V_21 -> V_29 ;
V_29 -> V_43 = * ( (struct V_42 * ) V_3 -> V_187 ) ;
V_43 = & V_29 -> V_43 ;
if ( V_43 -> V_53 > V_190 ) {
error = - V_139 ;
goto V_168;
}
V_29 -> V_110 = F_73 ( V_8 , V_190 ,
V_37 , & V_21 -> V_191 ) ;
if ( ! V_29 -> V_110 ) {
error = - V_71 ;
goto V_168;
}
V_21 -> V_36 = F_74 ( 0 , V_37 ) ;
if ( ! V_21 -> V_36 ) {
error = - V_71 ;
goto V_172;
}
V_21 -> V_31 = V_8 ;
V_21 -> V_2 = V_2 ;
F_75 ( & V_21 -> V_35 ) ;
F_76 ( & V_21 -> V_174 , F_68 ) ;
F_77 ( V_8 , V_21 -> V_192 , sizeof( V_21 -> V_192 ) ) ;
F_78 ( V_21 -> V_192 , L_10 , sizeof( V_21 -> V_192 ) ) ;
V_108 = & V_2 -> V_102 -> V_108 [ 0 ] . V_15 ;
error = F_30 ( V_2 , V_43 ) ;
if ( error )
goto V_188;
if ( V_43 -> type >= V_116 && V_43 -> type <= V_117 ) {
if ( V_108 -> V_193 == V_54 ) {
V_43 -> V_55 = V_56 ;
V_43 -> V_53 = V_54 ;
F_21 ( V_43 ) ;
V_43 -> V_45 = 4096 ;
V_43 -> V_48 = 4096 ;
} else {
V_43 -> V_55 = V_89 ;
}
}
F_79 ( V_43 ) ;
F_80 ( V_29 -> V_165 , V_43 -> V_165 , sizeof( V_29 -> V_165 ) ) ;
if ( V_43 -> V_159 & V_194 ) {
F_78 ( V_29 -> V_165 ,
V_43 -> V_55 == V_89 ?
L_11 : L_12 ,
sizeof( V_29 -> V_165 ) ) ;
error = F_35 ( V_29 , V_8 ) ;
if ( error )
goto V_188;
}
F_81 ( V_21 -> V_36 , V_8 ,
F_82 ( V_8 , V_108 -> V_195 ) ,
V_29 -> V_110 , V_43 -> V_53 ,
F_7 , V_21 , V_108 -> V_196 ) ;
V_21 -> V_36 -> V_197 = V_21 -> V_191 ;
V_21 -> V_36 -> V_198 |= V_199 ;
error = F_50 ( V_21 ) ;
if ( error )
goto V_200;
if ( ! ( V_43 -> V_159 & V_201 ) ) {
error = F_61 ( V_21 ) ;
if ( error )
goto V_202;
}
F_29 ( V_2 , V_43 ) ;
F_83 ( V_2 , V_21 ) ;
if ( V_43 -> V_159 & V_160 ) {
if ( F_11 ( V_21 -> V_36 , V_37 ) )
goto V_202;
}
return 0 ;
V_202: F_52 ( V_21 ) ;
V_200: F_41 ( V_29 ) ;
V_188: F_84 ( V_21 -> V_36 ) ;
V_172: F_85 ( V_8 , V_190 , V_29 -> V_110 , V_21 -> V_191 ) ;
V_168: F_26 ( V_21 ) ;
return error ;
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_21 * V_21 = F_69 ( V_2 ) ;
F_83 ( V_2 , NULL ) ;
F_20 ( V_21 -> V_36 ) ;
F_87 ( & V_21 -> V_174 ) ;
if ( V_21 -> V_29 . V_171 )
F_70 ( V_21 -> V_29 . V_171 ) ;
F_59 ( V_21 ) ;
F_52 ( V_21 ) ;
F_84 ( V_21 -> V_36 ) ;
F_85 ( F_2 ( V_2 ) , V_190 ,
V_21 -> V_29 . V_110 , V_21 -> V_191 ) ;
F_41 ( & V_21 -> V_29 ) ;
F_26 ( V_21 ) ;
}
static int F_88 ( struct V_1 * V_2 , T_4 V_203 )
{
struct V_21 * V_21 = F_69 ( V_2 ) ;
F_16 ( & V_21 -> V_35 ) ;
F_20 ( V_21 -> V_36 ) ;
F_17 ( & V_21 -> V_35 ) ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 )
{
struct V_21 * V_21 = F_69 ( V_2 ) ;
struct V_42 * V_43 = & V_21 -> V_29 . V_43 ;
int V_204 = 0 ;
F_16 ( & V_21 -> V_35 ) ;
F_29 ( V_2 , V_43 ) ;
F_43 ( V_21 ) ;
if ( ( V_21 -> V_39 || V_43 -> V_159 & V_160 )
&& F_11 ( V_21 -> V_36 , V_205 ) < 0 )
V_204 = - V_34 ;
F_17 ( & V_21 -> V_35 ) ;
return V_204 ;
}
static int F_90 ( struct V_1 * V_2 )
{
return F_89 ( V_2 ) ;
}
