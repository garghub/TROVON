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
int V_9 ;
switch ( V_20 -> V_23 ) {
case 0 :
break;
case - V_24 :
case - V_25 :
case - V_26 :
F_8 ( L_1 , V_27 , V_20 -> V_23 ) ;
return;
default:
F_8 ( L_2 , V_27 , V_20 -> V_23 ) ;
goto exit;
}
F_9 ( & V_21 -> V_28 , V_20 -> V_29 ) ;
exit:
F_10 ( V_21 -> V_30 ) ;
V_9 = F_11 ( V_20 , V_31 ) ;
if ( V_9 )
F_12 ( L_3 ,
V_27 , V_9 ) ;
}
static int F_13 ( struct V_32 * V_8 )
{
struct V_21 * V_21 = F_14 ( V_8 ) ;
int V_9 = 0 ;
if ( F_15 ( V_21 -> V_2 ) < 0 )
return - V_33 ;
F_16 ( & V_21 -> V_34 ) ;
if ( F_11 ( V_21 -> V_35 , V_36 ) ) {
V_9 = - V_33 ;
goto V_37;
}
V_21 -> V_38 = true ;
V_21 -> V_2 -> V_39 = 1 ;
V_37:
F_17 ( & V_21 -> V_34 ) ;
F_18 ( V_21 -> V_2 ) ;
return V_9 ;
}
static void F_19 ( struct V_32 * V_8 )
{
struct V_21 * V_21 = F_14 ( V_8 ) ;
int V_40 ;
V_40 = F_15 ( V_21 -> V_2 ) ;
F_16 ( & V_21 -> V_34 ) ;
F_20 ( V_21 -> V_35 ) ;
V_21 -> V_38 = false ;
V_21 -> V_2 -> V_39 = 0 ;
F_17 ( & V_21 -> V_34 ) ;
if ( ! V_40 )
F_18 ( V_21 -> V_2 ) ;
}
static void F_21 ( struct V_41 * V_42 )
{
V_42 -> V_43 = ( V_42 -> V_44 * 100 ) / V_42 -> V_45 ;
V_42 -> V_46 = ( V_42 -> V_47 * 100 ) / V_42 -> V_48 ;
}
static int F_22 ( unsigned char * V_49 ,
struct V_41 * V_42 )
{
int V_50 = 0 ;
if ( V_42 -> type == V_51 ) {
V_42 -> V_52 = V_53 ;
V_42 -> V_54 = V_55 ;
F_21 ( V_42 ) ;
V_42 -> V_44 = V_42 -> V_47 =
F_23 ( & V_49 [ 10 ] ) ;
V_50 = 11 ;
}
return V_50 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_56 * V_57 ,
struct V_41 * V_42 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
char V_58 = 0 ;
int V_59 = 0 ;
int V_60 = 0 , V_61 = V_62 , V_63 = 0 , V_64 = 0 ;
unsigned char * V_49 ;
V_49 = F_25 ( V_57 -> V_65 , V_36 ) ;
if ( ! V_49 )
return - V_66 ;
do {
V_59 = F_3 ( V_8 , F_4 ( V_8 , 0 ) ,
V_67 ,
V_13 | V_11 ,
V_68 << 8 ,
V_2 -> V_14 [ 0 ] . V_15 . V_16 ,
V_49 ,
V_57 -> V_65 ,
5000 ) ;
} while ( V_59 < 0 && V_58 ++ < V_69 );
if ( V_59 < 0 )
goto V_37;
for ( V_60 = 0 ; V_60 < V_57 -> V_65 ; V_60 ++ ) {
switch ( V_49 [ V_60 ] ) {
case V_70 :
switch ( V_49 [ V_60 + 1 ] ) {
case V_71 :
V_61 = V_72 ;
V_60 ++ ;
break;
case V_73 :
V_61 = V_74 ;
V_60 ++ ;
break;
}
break;
case V_75 :
switch ( V_49 [ V_60 + 1 ] ) {
case V_76 :
if ( V_61 == V_74 ) {
if ( V_63 ) {
V_42 -> V_54 = V_55 ;
if ( V_42 -> type == V_77 ) {
V_42 -> V_52 = V_78 ;
}
if ( V_42 -> type == V_51 ) {
V_42 -> V_52 = V_79 ;
V_42 -> V_43 =
F_23 ( & V_49 [ V_60 + 5 ] ) ;
V_42 -> V_44 =
F_23 ( & V_49 [ V_60 + 8 ] ) ;
V_60 += 15 ;
} else {
V_42 -> V_44 =
F_23 ( & V_49 [ V_60 + 3 ] ) ;
V_42 -> V_43 =
F_23 ( & V_49 [ V_60 + 6 ] ) ;
V_42 -> V_80 = V_49 [ V_60 + 9 ] ;
V_42 -> V_81 = V_49 [ V_60 + 11 ] ;
V_60 += 12 ;
}
} else if ( V_64 ) {
if ( V_42 -> type == V_77 )
V_42 -> V_52 = V_82 ;
V_42 -> V_54 = V_83 ;
V_42 -> V_44 =
F_23 ( & V_49 [ V_60 + 3 ] ) ;
V_60 += 4 ;
}
}
break;
case V_84 :
if ( V_61 == V_74 ) {
if ( V_63 ) {
V_42 -> V_54 = V_55 ;
if ( V_42 -> type == V_77 ) {
V_42 -> V_52 = V_78 ;
V_42 -> V_47 =
F_23 ( & V_49 [ V_60 + 3 ] ) ;
V_42 -> V_46 =
F_23 ( & V_49 [ V_60 + 6 ] ) ;
V_60 += 7 ;
} else if ( V_42 -> type == V_51 ) {
V_42 -> V_52 = V_79 ;
V_42 -> V_46 =
F_23 ( & V_49 [ V_60 + 3 ] ) ;
V_42 -> V_47 =
F_23 ( & V_49 [ V_60 + 6 ] ) ;
V_60 += 12 ;
} else {
V_42 -> V_47 =
V_42 -> V_44 ;
V_42 -> V_46 =
F_23 ( & V_49 [ V_60 + 3 ] ) ;
V_60 += 4 ;
}
} else if ( V_64 ) {
if ( V_42 -> type == V_77 )
V_42 -> V_52 = V_82 ;
V_42 -> V_54 = V_83 ;
V_42 -> V_47 =
F_23 ( & V_49 [ V_60 + 3 ] ) ;
V_60 += 4 ;
}
}
break;
case V_85 :
V_63 = 1 ;
V_60 ++ ;
break;
case V_86 :
V_64 = 1 ;
V_60 ++ ;
break;
}
break;
case V_87 :
V_63 = V_61 = 0 ;
break;
case V_88 :
V_60 ++ ;
switch ( V_49 [ V_60 ] ) {
case V_89 :
V_60 += F_22 ( & V_49 [ V_60 ] ,
V_42 ) ;
break;
}
break;
}
}
V_37:
V_59 = 0 ;
F_26 ( V_49 ) ;
return V_59 ;
}
static int F_27 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
unsigned char * V_90 ;
int V_58 = 0 , V_91 = 2 ;
int error = - V_66 ;
V_90 = F_28 ( 4 , V_36 ) ;
if ( ! V_90 )
return error ;
if ( V_42 -> type == V_77 ) {
do {
V_90 [ 0 ] = 3 ;
V_90 [ 1 ] = 4 ;
V_90 [ 2 ] = 0 ;
V_90 [ 3 ] = 0 ;
V_91 = 3 ;
error = F_5 ( V_2 , V_92 ,
V_91 , V_90 , 4 , 1 ) ;
if ( error >= 0 )
error = F_1 ( V_2 ,
V_92 ,
V_91 , V_90 , 4 , 1 ) ;
} while ( ( error < 0 || V_90 [ 1 ] != 4 ) && V_58 ++ < V_69 );
} else if ( V_42 -> type != V_93 &&
V_42 -> type != V_94 &&
V_42 -> V_54 == V_83 ) {
do {
V_90 [ 0 ] = 2 ;
V_90 [ 1 ] = 2 ;
error = F_5 ( V_2 , V_92 ,
V_91 , V_90 , 2 , 1 ) ;
if ( error >= 0 )
error = F_1 ( V_2 ,
V_92 ,
V_91 , V_90 , 2 , 1 ) ;
} while ( ( error < 0 || V_90 [ 1 ] != 2 ) && V_58 ++ < V_69 );
}
F_26 ( V_90 ) ;
return error < 0 ? error : 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
int error = 0 ;
struct V_95 * V_96 = V_2 -> V_97 ;
struct V_56 * V_57 ;
V_42 -> V_54 = V_83 ;
V_42 -> V_98 = 4 ;
V_42 -> V_99 = 4 ;
V_42 -> V_100 = 0 ;
V_42 -> V_101 = 0 ;
if ( V_42 -> type == V_94 ) {
if ( V_2 -> V_97 -> V_15 . V_16 == 0 ) {
V_42 -> V_54 = 0 ;
} else if ( V_2 -> V_97 -> V_15 . V_16 == 2 ) {
V_42 -> V_54 = V_102 ;
V_42 -> V_52 = V_53 ;
}
}
if ( ( V_42 -> type != V_93 ) && ( V_42 -> type != V_77 ) &&
( V_42 -> type != V_51 ) )
goto V_37;
if ( F_30 ( V_96 , V_103 , & V_57 ) ) {
if ( F_30 ( & V_96 -> V_104 [ 0 ] ,
V_68 , & V_57 ) ) {
F_31 ( L_4 ) ;
error = 1 ;
goto V_37;
}
}
error = F_24 ( V_2 , V_57 , V_42 ) ;
if ( error )
goto V_37;
V_37:
return error ;
}
static struct V_105 * F_32 ( struct V_7 * V_8 )
{
struct V_105 * V_106 ;
F_33 (data, &wacom_udev_list, list) {
if ( V_106 -> V_8 == V_8 ) {
F_34 ( & V_106 -> V_107 ) ;
return V_106 ;
}
}
return NULL ;
}
static int F_35 ( struct V_28 * V_21 ,
struct V_7 * V_8 )
{
struct V_105 * V_106 ;
int V_9 = 0 ;
F_16 ( & V_108 ) ;
V_106 = F_32 ( V_8 ) ;
if ( ! V_106 ) {
V_106 = F_25 ( sizeof( struct V_105 ) , V_36 ) ;
if ( ! V_106 ) {
V_9 = - V_66 ;
goto V_37;
}
F_36 ( & V_106 -> V_107 ) ;
V_106 -> V_8 = V_8 ;
F_37 ( & V_106 -> V_109 , & V_110 ) ;
}
V_21 -> V_111 = & V_106 -> V_111 ;
V_37:
F_17 ( & V_108 ) ;
return V_9 ;
}
static void F_38 ( struct V_107 * V_107 )
{
struct V_105 * V_106 =
F_39 ( V_107 , struct V_105 , V_107 ) ;
F_16 ( & V_108 ) ;
F_40 ( & V_106 -> V_109 ) ;
F_17 ( & V_108 ) ;
F_26 ( V_106 ) ;
}
static void F_41 ( struct V_28 * V_21 )
{
struct V_105 * V_106 ;
if ( V_21 -> V_111 ) {
V_106 = F_39 ( V_21 -> V_111 , struct V_105 , V_111 ) ;
F_42 ( & V_106 -> V_107 , F_38 ) ;
V_21 -> V_111 = NULL ;
}
}
static int F_43 ( struct V_21 * V_21 )
{
unsigned char * V_4 ;
int V_9 , V_112 = 0 ;
V_4 = F_25 ( 9 , V_36 ) ;
if ( ! V_4 )
return - V_66 ;
if ( V_21 -> V_28 . V_42 . type == V_113 ||
V_21 -> V_28 . V_42 . type == V_114 )
V_112 = ( V_21 -> V_112 . V_115 [ 1 ] << 4 ) | 0x40 ;
V_112 |= V_21 -> V_112 . V_115 [ 0 ] | 0x4 ;
V_4 [ 0 ] = V_116 ;
V_4 [ 1 ] = V_112 ;
V_4 [ 2 ] = V_21 -> V_112 . V_117 ;
V_4 [ 3 ] = V_21 -> V_112 . V_118 ;
V_4 [ 4 ] = V_21 -> V_112 . V_119 ;
V_9 = F_5 ( V_21 -> V_2 , 0x03 , V_116 ,
V_4 , 9 , V_120 ) ;
F_26 ( V_4 ) ;
return V_9 ;
}
static int F_44 ( struct V_21 * V_21 , int V_121 , const void * V_122 )
{
unsigned char * V_4 ;
int V_60 , V_9 ;
V_4 = F_25 ( 259 , V_36 ) ;
if ( ! V_4 )
return - V_66 ;
V_4 [ 0 ] = V_123 ;
V_4 [ 1 ] = 1 ;
V_9 = F_5 ( V_21 -> V_2 , 0x03 , V_123 ,
V_4 , 2 , V_120 ) ;
if ( V_9 < 0 )
goto V_37;
V_4 [ 0 ] = V_124 ;
V_4 [ 1 ] = V_121 & 0x07 ;
for ( V_60 = 0 ; V_60 < 4 ; V_60 ++ ) {
V_4 [ 2 ] = V_60 ;
memcpy ( V_4 + 3 , V_122 + V_60 * 256 , 256 ) ;
V_9 = F_5 ( V_21 -> V_2 , 0x03 , V_124 ,
V_4 , 259 , V_120 ) ;
if ( V_9 < 0 )
break;
}
V_4 [ 0 ] = V_123 ;
V_4 [ 1 ] = 0 ;
F_5 ( V_21 -> V_2 , 0x03 , V_123 ,
V_4 , 2 , V_120 ) ;
V_37:
F_26 ( V_4 ) ;
return V_9 ;
}
static T_3 F_45 ( struct V_125 * V_8 , int V_126 ,
const char * V_4 , T_2 V_127 )
{
struct V_21 * V_21 = F_46 ( V_8 ) ;
unsigned int V_3 ;
int F_12 ;
F_12 = F_47 ( V_4 , 10 , & V_3 ) ;
if ( F_12 )
return F_12 ;
F_16 ( & V_21 -> V_34 ) ;
V_21 -> V_112 . V_115 [ V_126 ] = V_3 & 0x3 ;
F_12 = F_43 ( V_21 ) ;
F_17 ( & V_21 -> V_34 ) ;
return F_12 < 0 ? F_12 : V_127 ;
}
static T_3 F_48 ( struct V_21 * V_21 , T_1 * V_128 ,
const char * V_4 , T_2 V_127 )
{
unsigned int V_129 ;
int F_12 ;
F_12 = F_47 ( V_4 , 10 , & V_129 ) ;
if ( F_12 )
return F_12 ;
F_16 ( & V_21 -> V_34 ) ;
* V_128 = V_129 & 0x7f ;
F_12 = F_43 ( V_21 ) ;
F_17 ( & V_21 -> V_34 ) ;
return F_12 < 0 ? F_12 : V_127 ;
}
static T_3 F_49 ( struct V_125 * V_8 , int V_121 ,
const char * V_4 , T_2 V_127 )
{
struct V_21 * V_21 = F_46 ( V_8 ) ;
int F_12 ;
if ( V_127 != 1024 )
return - V_130 ;
F_16 ( & V_21 -> V_34 ) ;
F_12 = F_44 ( V_21 , V_121 , V_4 ) ;
F_17 ( & V_21 -> V_34 ) ;
return F_12 < 0 ? F_12 : V_127 ;
}
static int F_50 ( struct V_21 * V_21 )
{
int error ;
switch ( V_21 -> V_28 . V_42 . type ) {
case V_131 :
case V_132 :
V_21 -> V_112 . V_115 [ 0 ] = 0 ;
V_21 -> V_112 . V_115 [ 1 ] = 0 ;
V_21 -> V_112 . V_117 = 10 ;
V_21 -> V_112 . V_118 = 20 ;
V_21 -> V_112 . V_119 = 10 ;
error = F_51 ( & V_21 -> V_2 -> V_8 . V_133 ,
& V_134 ) ;
break;
case V_114 :
case V_113 :
V_21 -> V_112 . V_115 [ 0 ] = 0 ;
V_21 -> V_112 . V_115 [ 1 ] = 0 ;
V_21 -> V_112 . V_117 = 0 ;
V_21 -> V_112 . V_118 = 0 ;
V_21 -> V_112 . V_119 = 0 ;
error = F_51 ( & V_21 -> V_2 -> V_8 . V_133 ,
& V_135 ) ;
break;
default:
return 0 ;
}
if ( error ) {
F_52 ( & V_21 -> V_2 -> V_8 ,
L_5 , error ) ;
return error ;
}
F_43 ( V_21 ) ;
return 0 ;
}
static void F_53 ( struct V_21 * V_21 )
{
switch ( V_21 -> V_28 . V_42 . type ) {
case V_131 :
case V_132 :
F_54 ( & V_21 -> V_2 -> V_8 . V_133 ,
& V_134 ) ;
break;
case V_114 :
case V_113 :
F_54 ( & V_21 -> V_2 -> V_8 . V_133 ,
& V_135 ) ;
break;
}
}
static int F_55 ( struct V_136 * V_137 ,
enum V_138 V_139 ,
union V_140 * V_141 )
{
struct V_21 * V_21 = F_39 ( V_137 , struct V_21 , V_142 ) ;
int V_143 = 0 ;
switch ( V_139 ) {
case V_144 :
V_141 -> V_145 =
V_21 -> V_28 . V_146 * 100 / 31 ;
break;
default:
V_143 = - V_130 ;
break;
}
return V_143 ;
}
static int F_56 ( struct V_21 * V_21 )
{
int error = 0 ;
if ( V_21 -> V_28 . V_42 . V_147 & V_148 ) {
V_21 -> V_142 . V_149 = V_150 ;
V_21 -> V_142 . V_151 = F_57 ( V_150 ) ;
V_21 -> V_142 . V_152 = F_55 ;
V_21 -> V_142 . V_153 = L_6 ;
V_21 -> V_142 . type = V_154 ;
V_21 -> V_142 . V_155 = 0 ;
error = F_58 ( & V_21 -> V_30 -> V_8 ,
& V_21 -> V_142 ) ;
}
return error ;
}
static void F_59 ( struct V_21 * V_21 )
{
if ( V_21 -> V_28 . V_42 . V_147 & V_148 )
F_60 ( & V_21 -> V_142 ) ;
}
static int F_61 ( struct V_21 * V_21 )
{
struct V_32 * V_32 ;
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_28 * V_28 = & ( V_21 -> V_28 ) ;
int error ;
V_32 = F_62 () ;
if ( ! V_32 )
return - V_66 ;
V_32 -> V_153 = V_28 -> V_153 ;
V_32 -> V_8 . V_156 = & V_2 -> V_8 ;
V_32 -> V_38 = F_13 ;
V_32 -> V_157 = F_19 ;
F_63 ( V_8 , & V_32 -> V_3 ) ;
F_64 ( V_32 , V_21 ) ;
V_28 -> V_158 = V_32 ;
F_65 ( V_32 , V_28 ) ;
error = F_66 ( V_32 ) ;
if ( error ) {
F_67 ( V_32 ) ;
V_28 -> V_158 = NULL ;
}
return error ;
}
static void F_68 ( struct V_159 * V_160 )
{
struct V_21 * V_21 = F_39 ( V_160 , struct V_21 , V_160 ) ;
struct V_7 * V_30 = V_21 -> V_30 ;
struct V_28 * V_28 = & V_21 -> V_28 ;
V_21 = F_69 ( V_30 -> V_161 -> V_96 [ 1 ] ) ;
if ( V_21 -> V_28 . V_158 )
F_70 ( V_21 -> V_28 . V_158 ) ;
V_21 -> V_28 . V_158 = 0 ;
V_21 = F_69 ( V_30 -> V_161 -> V_96 [ 2 ] ) ;
if ( V_21 -> V_28 . V_158 )
F_70 ( V_21 -> V_28 . V_158 ) ;
V_21 -> V_28 . V_158 = 0 ;
if ( V_28 -> V_162 == 0 ) {
F_31 ( V_163 L_7 ) ;
} else {
const struct V_164 * V_3 = V_165 ;
F_31 ( V_163
L_8 ,
V_28 -> V_162 ) ;
while ( V_3 -> V_166 ) {
if ( V_3 -> V_167 == V_168 &&
V_3 -> V_169 == V_28 -> V_162 )
break;
V_3 ++ ;
}
if ( ! V_3 -> V_166 ) {
F_31 ( V_163
L_9 ) ;
return;
}
V_21 = F_69 ( V_30 -> V_161 -> V_96 [ 1 ] ) ;
V_28 = & V_21 -> V_28 ;
V_28 -> V_42 =
* ( (struct V_41 * ) V_3 -> V_170 ) ;
V_28 -> V_42 . V_54 = V_83 ;
F_61 ( V_21 ) ;
V_21 = F_69 ( V_30 -> V_161 -> V_96 [ 2 ] ) ;
V_28 = & V_21 -> V_28 ;
V_28 -> V_42 =
* ( (struct V_41 * ) V_3 -> V_170 ) ;
V_28 -> V_42 . V_52 = V_53 ;
V_28 -> V_42 . V_54 = V_55 ;
F_21 ( & V_28 -> V_42 ) ;
V_28 -> V_42 . V_44 = V_28 -> V_42 . V_47 = 4096 ;
F_61 ( V_21 ) ;
}
}
static int F_71 ( struct V_1 * V_2 , const struct V_164 * V_3 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_171 * V_104 ;
struct V_21 * V_21 ;
struct V_28 * V_28 ;
struct V_41 * V_42 ;
int error ;
if ( ! V_3 -> V_170 )
return - V_130 ;
V_21 = F_25 ( sizeof( struct V_21 ) , V_36 ) ;
if ( ! V_21 )
return - V_66 ;
V_28 = & V_21 -> V_28 ;
V_28 -> V_42 = * ( (struct V_41 * ) V_3 -> V_170 ) ;
V_42 = & V_28 -> V_42 ;
if ( V_42 -> V_52 > V_172 ) {
error = - V_130 ;
goto V_173;
}
V_28 -> V_106 = F_72 ( V_8 , V_172 ,
V_36 , & V_21 -> V_174 ) ;
if ( ! V_28 -> V_106 ) {
error = - V_66 ;
goto V_173;
}
V_21 -> V_35 = F_73 ( 0 , V_36 ) ;
if ( ! V_21 -> V_35 ) {
error = - V_66 ;
goto V_175;
}
V_21 -> V_30 = V_8 ;
V_21 -> V_2 = V_2 ;
F_74 ( & V_21 -> V_34 ) ;
F_75 ( & V_21 -> V_160 , F_68 ) ;
F_76 ( V_8 , V_21 -> V_176 , sizeof( V_21 -> V_176 ) ) ;
F_77 ( V_21 -> V_176 , L_10 , sizeof( V_21 -> V_176 ) ) ;
V_104 = & V_2 -> V_97 -> V_104 [ 0 ] . V_15 ;
error = F_29 ( V_2 , V_42 ) ;
if ( error )
goto V_177;
F_78 ( V_42 ) ;
F_79 ( V_28 -> V_153 , V_42 -> V_153 , sizeof( V_28 -> V_153 ) ) ;
if ( V_42 -> V_147 & V_178 ) {
F_77 ( V_28 -> V_153 ,
V_42 -> V_54 == V_83 ?
L_11 : L_12 ,
sizeof( V_28 -> V_153 ) ) ;
error = F_35 ( V_28 , V_8 ) ;
if ( error )
goto V_177;
}
F_80 ( V_21 -> V_35 , V_8 ,
F_81 ( V_8 , V_104 -> V_179 ) ,
V_28 -> V_106 , V_42 -> V_52 ,
F_7 , V_21 , V_104 -> V_180 ) ;
V_21 -> V_35 -> V_181 = V_21 -> V_174 ;
V_21 -> V_35 -> V_182 |= V_183 ;
error = F_50 ( V_21 ) ;
if ( error )
goto V_184;
error = F_56 ( V_21 ) ;
if ( error )
goto V_185;
if ( ! ( V_42 -> V_147 & V_186 ) ) {
error = F_61 ( V_21 ) ;
if ( error )
goto V_187;
}
F_27 ( V_2 , V_42 ) ;
F_82 ( V_2 , V_21 ) ;
if ( V_42 -> V_147 & V_148 ) {
if ( F_11 ( V_21 -> V_35 , V_36 ) )
goto V_185;
}
return 0 ;
V_187: F_59 ( V_21 ) ;
V_185: F_53 ( V_21 ) ;
V_184: F_41 ( V_28 ) ;
V_177: F_83 ( V_21 -> V_35 ) ;
V_175: F_84 ( V_8 , V_172 , V_28 -> V_106 , V_21 -> V_174 ) ;
V_173: F_26 ( V_21 ) ;
return error ;
}
static void F_85 ( struct V_1 * V_2 )
{
struct V_21 * V_21 = F_69 ( V_2 ) ;
F_82 ( V_2 , NULL ) ;
F_20 ( V_21 -> V_35 ) ;
F_86 ( & V_21 -> V_160 ) ;
if ( V_21 -> V_28 . V_158 )
F_70 ( V_21 -> V_28 . V_158 ) ;
F_59 ( V_21 ) ;
F_53 ( V_21 ) ;
F_83 ( V_21 -> V_35 ) ;
F_84 ( F_2 ( V_2 ) , V_172 ,
V_21 -> V_28 . V_106 , V_21 -> V_174 ) ;
F_41 ( & V_21 -> V_28 ) ;
F_26 ( V_21 ) ;
}
static int F_87 ( struct V_1 * V_2 , T_4 V_188 )
{
struct V_21 * V_21 = F_69 ( V_2 ) ;
F_16 ( & V_21 -> V_34 ) ;
F_20 ( V_21 -> V_35 ) ;
F_17 ( & V_21 -> V_34 ) ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 )
{
struct V_21 * V_21 = F_69 ( V_2 ) ;
struct V_41 * V_42 = & V_21 -> V_28 . V_42 ;
int V_189 = 0 ;
F_16 ( & V_21 -> V_34 ) ;
F_27 ( V_2 , V_42 ) ;
F_43 ( V_21 ) ;
if ( ( V_21 -> V_38 || V_42 -> V_147 & V_148 )
&& F_11 ( V_21 -> V_35 , V_190 ) < 0 )
V_189 = - V_33 ;
F_17 ( & V_21 -> V_34 ) ;
return V_189 ;
}
static int F_89 ( struct V_1 * V_2 )
{
return F_88 ( V_2 ) ;
}
