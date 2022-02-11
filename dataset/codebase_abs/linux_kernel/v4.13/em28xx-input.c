static int F_1 ( struct V_1 * V_2 ,
enum V_3 * V_4 , T_1 * V_5 )
{
unsigned char V_6 ;
if ( 1 != F_2 ( V_2 , & V_6 , 1 ) )
return - V_7 ;
if ( V_6 == 0xff )
return 0 ;
if ( V_6 == 0xfe )
return 1 ;
* V_4 = V_8 ;
* V_5 = V_6 ;
return 1 ;
}
static int F_3 ( struct V_1 * V_2 ,
enum V_3 * V_4 , T_1 * V_5 )
{
unsigned char V_9 [ 2 ] ;
int V_10 ;
V_10 = F_2 ( V_2 , V_9 , sizeof( V_9 ) ) ;
if ( V_10 != 2 )
return - V_7 ;
if ( V_9 [ 1 ] == 0xff )
return 0 ;
* V_4 = V_11 ;
* V_5 = ( F_4 ( V_9 [ 1 ] ) & 0x1f ) << 8 | F_4 ( V_9 [ 0 ] ) >> 2 ;
return 1 ;
}
static int F_5 ( struct V_1 * V_2 ,
enum V_3 * V_4 , T_1 * V_5 )
{
unsigned char V_9 [ 3 ] ;
if ( 3 != F_2 ( V_2 , V_9 , 3 ) )
return - V_7 ;
if ( V_9 [ 0 ] != 0x00 )
return 0 ;
* V_4 = V_8 ;
* V_5 = V_9 [ 2 ] & 0x3f ;
return 1 ;
}
static int F_6 ( struct V_1 * V_2 ,
enum V_3 * V_4 , T_1 * V_5 )
{
unsigned char V_12 , V_13 , V_14 ;
struct V_15 V_16 [] = { { . V_17 = V_2 -> V_17 , . V_18 = 0 , . V_9 = & V_12 , . V_19 = 1 } ,
{ . V_17 = V_2 -> V_17 , . V_18 = V_20 , . V_9 = & V_13 , . V_19 = 1 } } ;
V_12 = 0x10 ;
if ( 2 != F_7 ( V_2 -> V_21 , V_16 , 2 ) )
return - V_7 ;
if ( V_13 == 0x00 )
return 0 ;
V_12 = 0x00 ;
V_16 [ 1 ] . V_9 = & V_14 ;
if ( 2 != F_7 ( V_2 -> V_21 , V_16 , 2 ) )
return - V_7 ;
if ( V_14 == 0x00 )
return 0 ;
* V_4 = V_8 ;
* V_5 = V_14 ;
return 1 ;
}
static int F_8 ( struct V_22 * V_23 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 = V_23 -> V_27 ;
int V_28 ;
T_2 V_16 [ 3 ] = { 0 , 0 , 0 } ;
V_28 = V_27 -> V_29 ( V_27 , 0 , V_30 ,
V_16 , sizeof( V_16 ) ) ;
if ( V_28 < 0 )
return V_28 ;
V_25 -> V_31 = ( V_16 [ 0 ] >> 7 ) ;
V_25 -> V_32 = ( V_16 [ 0 ] & 0x7f ) ;
switch ( V_23 -> V_3 ) {
case V_33 :
V_25 -> V_4 = V_11 ;
V_25 -> V_5 = F_9 ( V_16 [ 1 ] , V_16 [ 2 ] ) ;
break;
case V_34 :
V_25 -> V_4 = V_35 ;
V_25 -> V_5 = F_10 ( V_16 [ 1 ] , V_16 [ 2 ] ) ;
break;
default:
V_25 -> V_4 = V_8 ;
V_25 -> V_5 = V_16 [ 1 ] << 8 | V_16 [ 2 ] ;
break;
}
return 0 ;
}
static int F_11 ( struct V_22 * V_23 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 = V_23 -> V_27 ;
int V_28 ;
T_2 V_16 [ 5 ] = { 0 , 0 , 0 , 0 , 0 } ;
V_28 = V_27 -> V_29 ( V_27 , 0 , V_36 ,
V_16 , sizeof( V_16 ) ) ;
if ( V_28 < 0 )
return V_28 ;
V_25 -> V_31 = ( V_16 [ 0 ] >> 7 ) ;
V_25 -> V_32 = ( V_16 [ 0 ] & 0x7f ) ;
switch ( V_23 -> V_3 ) {
case V_33 :
V_25 -> V_4 = V_11 ;
V_25 -> V_5 = F_9 ( V_16 [ 1 ] , V_16 [ 2 ] ) ;
break;
case V_34 :
V_25 -> V_5 = V_16 [ 1 ] << 8 | V_16 [ 2 ] ;
if ( ( V_16 [ 3 ] ^ V_16 [ 4 ] ) != 0xff ) {
V_25 -> V_4 = V_37 ;
V_25 -> V_5 = F_12 ( ( V_16 [ 1 ] << 24 ) |
( V_16 [ 2 ] << 16 ) |
( V_16 [ 3 ] << 8 ) |
( V_16 [ 4 ] ) ) ;
} else if ( ( V_16 [ 1 ] ^ V_16 [ 2 ] ) != 0xff ) {
V_25 -> V_4 = V_38 ;
V_25 -> V_5 = F_13 ( V_16 [ 1 ] << 8 |
V_16 [ 2 ] , V_16 [ 3 ] ) ;
} else {
V_25 -> V_4 = V_35 ;
V_25 -> V_5 = F_10 ( V_16 [ 1 ] , V_16 [ 3 ] ) ;
}
break;
case V_39 :
V_25 -> V_4 = V_40 ;
V_25 -> V_5 = F_14 ( V_16 [ 1 ] , V_16 [ 2 ] ) ;
break;
default:
V_25 -> V_4 = V_8 ;
V_25 -> V_5 = ( V_16 [ 1 ] << 24 ) | ( V_16 [ 2 ] << 16 ) |
( V_16 [ 3 ] << 8 ) | V_16 [ 4 ] ;
break;
}
return 0 ;
}
static int F_15 ( struct V_22 * V_23 )
{
static T_1 V_5 ;
enum V_3 V_4 ;
int V_28 ;
V_28 = V_23 -> V_41 ( V_23 -> V_1 , & V_4 , & V_5 ) ;
if ( V_28 < 0 ) {
F_16 ( L_1 , V_28 ) ;
return V_28 ;
}
if ( V_28 ) {
F_16 ( L_2 ,
V_42 , V_4 , V_5 ) ;
F_17 ( V_23 -> V_28 , V_4 , V_5 , 0 ) ;
}
return 0 ;
}
static void F_18 ( struct V_22 * V_23 )
{
int V_43 ;
struct V_24 V_25 ;
V_43 = V_23 -> V_44 ( V_23 , & V_25 ) ;
if ( F_19 ( V_43 < 0 ) ) {
F_16 ( L_3 , V_43 ) ;
return;
}
if ( F_19 ( V_25 . V_32 != V_23 -> V_45 ) ) {
F_16 ( L_4 , V_42 ,
V_25 . V_31 , V_25 . V_32 ,
V_25 . V_5 ) ;
if ( V_23 -> V_46 )
F_17 ( V_23 -> V_28 ,
V_25 . V_4 ,
V_25 . V_5 ,
V_25 . V_31 ) ;
else
F_17 ( V_23 -> V_28 ,
V_8 ,
V_25 . V_5 & 0xff ,
V_25 . V_31 ) ;
if ( V_23 -> V_27 -> V_47 == V_48 ||
V_23 -> V_27 -> V_47 == V_49 )
V_23 -> V_45 = 0 ;
else
V_23 -> V_45 = V_25 . V_32 ;
}
}
static void F_20 ( struct V_50 * V_51 )
{
struct V_22 * V_23 = F_21 ( V_51 , struct V_22 , V_51 . V_51 ) ;
if ( V_23 -> V_1 )
F_15 ( V_23 ) ;
else
F_18 ( V_23 ) ;
F_22 ( & V_23 -> V_51 , F_23 ( V_23 -> V_52 ) ) ;
}
static int F_24 ( struct V_53 * V_28 )
{
struct V_22 * V_23 = V_28 -> V_54 ;
F_25 ( & V_23 -> V_51 , F_20 ) ;
F_22 ( & V_23 -> V_51 , 0 ) ;
return 0 ;
}
static void F_26 ( struct V_53 * V_28 )
{
struct V_22 * V_23 = V_28 -> V_54 ;
F_27 ( & V_23 -> V_51 ) ;
}
static int F_28 ( struct V_53 * V_53 , T_3 * V_3 )
{
struct V_22 * V_23 = V_53 -> V_54 ;
struct V_26 * V_27 = V_23 -> V_27 ;
if ( * V_3 & V_33 ) {
V_27 -> V_55 . V_56 |= V_57 ;
V_23 -> V_46 = 1 ;
* V_3 = V_33 ;
} else if ( * V_3 & V_34 ) {
V_27 -> V_55 . V_56 &= ~ V_57 ;
V_23 -> V_46 = 1 ;
* V_3 = V_34 ;
} else if ( * V_3 & V_58 ) {
* V_3 = V_58 ;
} else {
* V_3 = V_23 -> V_3 ;
return - V_59 ;
}
F_29 ( V_27 , V_60 , V_27 -> V_55 . V_56 ,
V_57 ) ;
V_23 -> V_3 = * V_3 ;
return 0 ;
}
static int F_30 ( struct V_53 * V_53 , T_3 * V_3 )
{
struct V_22 * V_23 = V_53 -> V_54 ;
struct V_26 * V_27 = V_23 -> V_27 ;
T_2 V_61 = V_62 ;
if ( * V_3 & V_33 ) {
V_27 -> V_55 . V_56 |= V_57 ;
V_23 -> V_46 = 1 ;
* V_3 = V_33 ;
} else if ( * V_3 & V_34 ) {
V_27 -> V_55 . V_56 &= ~ V_57 ;
V_61 = V_63 | V_64 ;
V_23 -> V_46 = 1 ;
* V_3 = V_34 ;
} else if ( * V_3 & V_39 ) {
V_27 -> V_55 . V_56 |= V_57 ;
V_61 = V_65 ;
V_23 -> V_46 = 1 ;
* V_3 = V_39 ;
} else if ( * V_3 & V_58 ) {
* V_3 = V_58 ;
} else {
* V_3 = V_23 -> V_3 ;
return - V_59 ;
}
F_31 ( V_27 , V_66 , & V_61 , 1 ) ;
F_29 ( V_27 , V_60 , V_27 -> V_55 . V_56 ,
V_57 ) ;
V_23 -> V_3 = * V_3 ;
return 0 ;
}
static int F_32 ( struct V_53 * V_53 , T_3 * V_3 )
{
struct V_22 * V_23 = V_53 -> V_54 ;
struct V_26 * V_27 = V_23 -> V_27 ;
switch ( V_27 -> V_47 ) {
case V_67 :
case V_68 :
return F_28 ( V_53 , V_3 ) ;
case V_49 :
case V_48 :
case V_69 :
case V_70 :
return F_30 ( V_53 , V_3 ) ;
default:
F_33 ( & V_23 -> V_27 -> V_71 -> V_27 ,
L_5 ,
V_27 -> V_47 ) ;
return - V_59 ;
}
}
static int F_34 ( struct V_26 * V_27 )
{
int V_72 = 0 ;
const unsigned short V_73 [] = {
0x1f , 0x30 , 0x47 , V_74
} ;
while ( V_73 [ V_72 ] != V_74 ) {
if ( F_35 ( & V_27 -> V_75 [ V_27 -> V_76 ] , V_73 [ V_72 ] ) == 1 )
return V_73 [ V_72 ] ;
V_72 ++ ;
}
return - V_77 ;
}
static void F_36 ( struct V_50 * V_51 )
{
struct V_26 * V_27 =
F_21 ( V_51 , struct V_26 , V_78 . V_51 ) ;
T_2 V_72 , V_79 ;
int V_80 ;
bool V_81 , V_82 ;
const struct V_83 * V_84 ;
for ( V_72 = 0 ; V_72 < V_27 -> V_85 ; V_72 ++ ) {
V_80 = F_37 ( V_27 , V_27 -> V_86 [ V_72 ] ) ;
if ( V_80 < 0 )
continue;
V_79 = 0 ;
while ( V_27 -> V_55 . V_87 [ V_79 ] . V_88 >= 0 &&
V_27 -> V_55 . V_87 [ V_79 ] . V_88 < V_89 ) {
struct V_90 * V_91 = & V_27 -> V_55 . V_87 [ V_79 ] ;
if ( V_91 -> V_92 != V_27 -> V_86 [ V_72 ] ) {
V_79 ++ ;
continue;
}
V_81 = V_80 & V_91 -> V_93 ;
V_82 = V_27 -> V_94 [ V_72 ]
& V_91 -> V_93 ;
if ( V_91 -> V_95 ) {
V_81 = ! V_81 ;
V_82 = ! V_82 ;
}
if ( V_81 && V_91 -> V_96 )
F_38 ( V_27 , V_91 -> V_96 ,
( ~ V_80 & V_91 -> V_93 )
| ( V_80 & ~ V_91 -> V_93 ) ) ;
if ( ! V_81 || V_82 ) {
V_79 ++ ;
continue;
}
switch ( V_91 -> V_88 ) {
case V_97 :
F_39 ( V_27 -> V_98 ,
V_99 , 1 ) ;
F_39 ( V_27 -> V_98 ,
V_99 , 0 ) ;
break;
case V_100 :
V_84 = F_40 ( V_27 ,
V_101 ) ;
if ( V_84 )
F_41 ( V_27 ,
V_84 -> V_102 ,
V_84 -> V_103 ) ;
break;
default:
F_42 ( 1 , L_6 ) ;
}
V_79 ++ ;
}
V_27 -> V_94 [ V_72 ] = V_80 ;
}
F_22 ( & V_27 -> V_78 ,
F_23 ( V_27 -> V_104 ) ) ;
}
static int F_43 ( struct V_26 * V_27 )
{
struct V_105 * V_106 = F_44 ( V_27 -> V_71 ) ;
struct V_107 * V_107 ;
int V_108 ;
F_45 ( & V_27 -> V_71 -> V_27 , L_7 ) ;
V_107 = F_46 () ;
if ( ! V_107 )
return - V_109 ;
F_47 ( V_106 , V_27 -> V_110 ,
sizeof( V_27 -> V_110 ) ) ;
F_48 ( V_27 -> V_110 , L_8 ,
sizeof( V_27 -> V_110 ) ) ;
V_107 -> V_111 = L_9 ;
V_107 -> V_112 = V_27 -> V_110 ;
V_107 -> V_113 [ 0 ] = F_49 ( V_114 ) | F_49 ( V_115 ) ;
F_50 ( V_99 , V_107 -> V_116 ) ;
V_107 -> V_117 = 0 ;
V_107 -> V_118 = 0 ;
V_107 -> V_119 . V_120 = V_121 ;
V_107 -> V_119 . V_122 = F_51 ( V_106 -> V_123 . V_124 ) ;
V_107 -> V_119 . V_125 = F_51 ( V_106 -> V_123 . V_126 ) ;
V_107 -> V_119 . V_127 = 1 ;
V_107 -> V_27 . V_128 = & V_27 -> V_71 -> V_27 ;
V_108 = F_52 ( V_107 ) ;
if ( V_108 ) {
F_33 ( & V_27 -> V_71 -> V_27 , L_10 ) ;
F_53 ( V_107 ) ;
return V_108 ;
}
V_27 -> V_98 = V_107 ;
return 0 ;
}
static void F_54 ( struct V_26 * V_27 )
{
T_2 V_72 = 0 , V_79 = 0 ;
bool V_129 = false ;
V_27 -> V_104 = V_130 ;
while ( V_27 -> V_55 . V_87 [ V_72 ] . V_88 >= 0 &&
V_27 -> V_55 . V_87 [ V_72 ] . V_88 < V_89 ) {
struct V_90 * V_91 = & V_27 -> V_55 . V_87 [ V_72 ] ;
V_129 = true ;
for ( V_79 = 0 ; V_79 < V_27 -> V_85 ; V_79 ++ ) {
if ( V_91 -> V_92 == V_27 -> V_86 [ V_79 ] ) {
V_129 = false ;
break;
}
}
if ( V_129 && V_27 -> V_85
>= V_131 ) {
F_42 ( 1 , L_11 ) ;
goto V_132;
}
if ( V_91 -> V_88 == V_97 ) {
if ( F_43 ( V_27 ) < 0 )
goto V_132;
} else if ( V_91 -> V_88 == V_100 ) {
if ( ! F_40 ( V_27 , V_101 ) ) {
F_33 ( & V_27 -> V_71 -> V_27 ,
L_12 ) ;
goto V_132;
}
}
if ( V_129 ) {
unsigned int V_133 = V_27 -> V_85 ;
V_27 -> V_86 [ V_133 ] = V_91 -> V_92 ;
V_27 -> V_85 ++ ;
}
if ( ! V_91 -> V_96 )
V_27 -> V_104 =
V_134 ;
V_132:
V_72 ++ ;
}
if ( V_27 -> V_85 ) {
memset ( V_27 -> V_94 , 0 ,
V_131 ) ;
F_22 ( & V_27 -> V_78 ,
F_23 ( V_27 -> V_104 ) ) ;
}
}
static void F_55 ( struct V_26 * V_27 )
{
F_27 ( & V_27 -> V_78 ) ;
V_27 -> V_85 = 0 ;
if ( V_27 -> V_98 != NULL ) {
F_45 ( & V_27 -> V_71 -> V_27 , L_13 ) ;
F_56 ( V_27 -> V_98 ) ;
V_27 -> V_98 = NULL ;
}
}
static int F_57 ( struct V_26 * V_27 )
{
struct V_105 * V_106 = F_44 ( V_27 -> V_71 ) ;
struct V_22 * V_23 ;
struct V_53 * V_28 ;
int V_108 = - V_109 ;
T_3 V_3 ;
T_4 V_135 = 0 ;
if ( V_27 -> V_136 ) {
return 0 ;
}
F_58 ( & V_27 -> V_137 ) ;
F_25 ( & V_27 -> V_78 , F_36 ) ;
if ( V_27 -> V_55 . V_87 )
F_54 ( V_27 ) ;
if ( V_27 -> V_55 . V_138 ) {
V_135 = F_34 ( V_27 ) ;
if ( ! V_135 ) {
V_27 -> V_55 . V_138 = 0 ;
F_59 ( & V_27 -> V_71 -> V_27 ,
L_14 ) ;
return - V_77 ;
}
}
if ( V_27 -> V_55 . V_139 == NULL && ! V_27 -> V_55 . V_138 ) {
F_59 ( & V_27 -> V_71 -> V_27 ,
L_15 ) ;
return 0 ;
}
F_45 ( & V_27 -> V_71 -> V_27 , L_16 ) ;
V_23 = F_60 ( sizeof( * V_23 ) , V_140 ) ;
if ( ! V_23 )
return - V_109 ;
V_28 = F_61 ( V_141 ) ;
if ( ! V_28 )
goto error;
V_23 -> V_27 = V_27 ;
V_27 -> V_23 = V_23 ;
V_23 -> V_28 = V_28 ;
V_28 -> V_54 = V_23 ;
V_28 -> V_142 = F_24 ;
V_28 -> V_143 = F_26 ;
if ( V_27 -> V_55 . V_138 ) {
switch ( V_27 -> V_144 ) {
case V_145 :
case V_146 :
V_28 -> V_147 = V_148 ;
V_23 -> V_41 = F_1 ;
break;
case V_149 :
V_28 -> V_147 = V_150 ;
V_23 -> V_41 = F_5 ;
break;
case V_151 :
V_28 -> V_147 = V_152 ;
V_23 -> V_41 = F_3 ;
V_28 -> V_153 = V_33 ;
break;
case V_154 :
V_28 -> V_147 = V_155 ;
V_23 -> V_41 = F_6 ;
break;
default:
V_108 = - V_77 ;
goto error;
}
V_23 -> V_1 = F_60 ( sizeof( struct V_1 ) , V_140 ) ;
if ( ! V_23 -> V_1 )
goto error;
V_23 -> V_1 -> V_21 = & V_23 -> V_27 -> V_75 [ V_27 -> V_76 ] ;
V_23 -> V_1 -> V_17 = V_135 ;
V_23 -> V_1 -> V_18 = 0 ;
} else {
switch ( V_27 -> V_47 ) {
case V_67 :
case V_68 :
V_28 -> V_153 = V_33 | V_34 ;
V_23 -> V_44 = F_8 ;
break;
case V_49 :
case V_48 :
case V_69 :
case V_70 :
V_23 -> V_44 = F_11 ;
V_28 -> V_153 = V_33 | V_34 |
V_156 | V_157 | V_39 ;
break;
default:
V_108 = - V_77 ;
goto error;
}
V_28 -> V_158 = F_32 ;
V_28 -> V_147 = V_27 -> V_55 . V_139 ;
V_3 = V_58 ;
V_108 = F_32 ( V_28 , & V_3 ) ;
if ( V_108 )
goto error;
}
V_23 -> V_52 = 100 ;
snprintf ( V_23 -> V_111 , sizeof( V_23 -> V_111 ) , L_17 ,
F_62 ( & V_27 -> V_71 -> V_27 ) ) ;
F_47 ( V_106 , V_23 -> V_112 , sizeof( V_23 -> V_112 ) ) ;
F_48 ( V_23 -> V_112 , L_18 , sizeof( V_23 -> V_112 ) ) ;
V_28 -> V_159 = V_23 -> V_111 ;
V_28 -> V_160 = V_23 -> V_112 ;
V_28 -> V_161 . V_120 = V_121 ;
V_28 -> V_161 . V_127 = 1 ;
V_28 -> V_161 . V_122 = F_51 ( V_106 -> V_123 . V_124 ) ;
V_28 -> V_161 . V_125 = F_51 ( V_106 -> V_123 . V_126 ) ;
V_28 -> V_27 . V_128 = & V_27 -> V_71 -> V_27 ;
V_28 -> V_162 = V_163 ;
V_108 = F_63 ( V_28 ) ;
if ( V_108 )
goto error;
F_45 ( & V_27 -> V_71 -> V_27 , L_19 ) ;
return 0 ;
error:
F_64 ( V_23 -> V_1 ) ;
V_27 -> V_23 = NULL ;
F_65 ( V_28 ) ;
F_64 ( V_23 ) ;
return V_108 ;
}
static int F_66 ( struct V_26 * V_27 )
{
struct V_22 * V_23 = V_27 -> V_23 ;
if ( V_27 -> V_136 ) {
return 0 ;
}
F_45 ( & V_27 -> V_71 -> V_27 , L_20 ) ;
F_55 ( V_27 ) ;
if ( ! V_23 )
goto V_164;
F_67 ( V_23 -> V_28 ) ;
F_64 ( V_23 -> V_1 ) ;
F_64 ( V_23 ) ;
V_27 -> V_23 = NULL ;
V_164:
F_68 ( & V_27 -> V_137 , V_165 ) ;
return 0 ;
}
static int F_69 ( struct V_26 * V_27 )
{
struct V_22 * V_23 = V_27 -> V_23 ;
if ( V_27 -> V_136 )
return 0 ;
F_45 ( & V_27 -> V_71 -> V_27 , L_21 ) ;
if ( V_23 )
F_27 ( & V_23 -> V_51 ) ;
F_27 ( & V_27 -> V_78 ) ;
return 0 ;
}
static int F_70 ( struct V_26 * V_27 )
{
struct V_22 * V_23 = V_27 -> V_23 ;
if ( V_27 -> V_136 )
return 0 ;
F_45 ( & V_27 -> V_71 -> V_27 , L_22 ) ;
if ( V_23 )
F_22 ( & V_23 -> V_51 , F_23 ( V_23 -> V_52 ) ) ;
if ( V_27 -> V_85 )
F_22 ( & V_27 -> V_78 ,
F_23 ( V_27 -> V_104 ) ) ;
return 0 ;
}
static int T_5 F_71 ( void )
{
return F_72 ( & V_166 ) ;
}
static void T_6 F_73 ( void )
{
F_74 ( & V_166 ) ;
}
