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
V_25 -> V_4 = V_11 ;
V_25 -> V_5 = V_16 [ 1 ] << 8 | V_16 [ 2 ] ;
if ( ( V_16 [ 3 ] ^ V_16 [ 4 ] ) != 0xff )
V_25 -> V_5 = F_12 ( ( V_16 [ 1 ] << 24 ) |
( V_16 [ 2 ] << 16 ) |
( V_16 [ 3 ] << 8 ) |
( V_16 [ 4 ] ) ) ;
else if ( ( V_16 [ 1 ] ^ V_16 [ 2 ] ) != 0xff )
V_25 -> V_5 = F_13 ( V_16 [ 1 ] << 8 |
V_16 [ 2 ] , V_16 [ 3 ] ) ;
else
V_25 -> V_5 = F_10 ( V_16 [ 1 ] , V_16 [ 3 ] ) ;
break;
case V_37 :
V_25 -> V_4 = V_38 ;
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
struct V_26 * V_27 = V_23 -> V_27 ;
static T_1 V_5 ;
enum V_3 V_4 ;
int V_28 ;
struct V_1 V_39 ;
V_39 . V_21 = & V_23 -> V_27 -> V_40 [ V_27 -> V_41 ] ;
V_39 . V_17 = V_23 -> V_42 ;
V_28 = V_23 -> V_43 ( & V_39 , & V_4 , & V_5 ) ;
if ( V_28 < 0 ) {
F_16 ( L_1 , V_28 ) ;
return V_28 ;
}
if ( V_28 ) {
F_16 ( L_2 ,
V_44 , V_4 , V_5 ) ;
F_17 ( V_23 -> V_28 , V_4 , V_5 , 0 ) ;
}
return 0 ;
}
static void F_18 ( struct V_22 * V_23 )
{
int V_45 ;
struct V_24 V_25 ;
V_45 = V_23 -> V_46 ( V_23 , & V_25 ) ;
if ( F_19 ( V_45 < 0 ) ) {
F_16 ( L_3 , V_45 ) ;
return;
}
if ( F_19 ( V_25 . V_32 != V_23 -> V_47 ) ) {
F_16 ( L_4 , V_44 ,
V_25 . V_31 , V_25 . V_32 ,
V_25 . V_5 ) ;
if ( V_23 -> V_48 )
F_17 ( V_23 -> V_28 ,
V_25 . V_4 ,
V_25 . V_5 ,
V_25 . V_31 ) ;
else
F_17 ( V_23 -> V_28 ,
V_8 ,
V_25 . V_5 & 0xff ,
V_25 . V_31 ) ;
if ( V_23 -> V_27 -> V_49 == V_50 ||
V_23 -> V_27 -> V_49 == V_51 )
V_23 -> V_47 = 0 ;
else
V_23 -> V_47 = V_25 . V_32 ;
}
}
static void F_20 ( struct V_52 * V_53 )
{
struct V_22 * V_23 = F_21 ( V_53 , struct V_22 , V_53 . V_53 ) ;
if ( V_23 -> V_42 )
F_15 ( V_23 ) ;
else
F_18 ( V_23 ) ;
F_22 ( & V_23 -> V_53 , F_23 ( V_23 -> V_54 ) ) ;
}
static int F_24 ( struct V_55 * V_28 )
{
struct V_22 * V_23 = V_28 -> V_56 ;
F_25 ( & V_23 -> V_53 , F_20 ) ;
F_22 ( & V_23 -> V_53 , 0 ) ;
return 0 ;
}
static void F_26 ( struct V_55 * V_28 )
{
struct V_22 * V_23 = V_28 -> V_56 ;
F_27 ( & V_23 -> V_53 ) ;
}
static int F_28 ( struct V_55 * V_55 , T_3 * V_3 )
{
struct V_22 * V_23 = V_55 -> V_56 ;
struct V_26 * V_27 = V_23 -> V_27 ;
if ( * V_3 & V_33 ) {
V_27 -> V_57 . V_58 |= V_59 ;
V_23 -> V_48 = 1 ;
* V_3 = V_33 ;
} else if ( * V_3 & V_34 ) {
V_27 -> V_57 . V_58 &= ~ V_59 ;
V_23 -> V_48 = 1 ;
* V_3 = V_34 ;
} else if ( * V_3 & V_60 ) {
* V_3 = V_60 ;
} else {
* V_3 = V_23 -> V_3 ;
return - V_61 ;
}
F_29 ( V_27 , V_62 , V_27 -> V_57 . V_58 ,
V_59 ) ;
V_23 -> V_3 = * V_3 ;
return 0 ;
}
static int F_30 ( struct V_55 * V_55 , T_3 * V_3 )
{
struct V_22 * V_23 = V_55 -> V_56 ;
struct V_26 * V_27 = V_23 -> V_27 ;
T_2 V_63 = V_64 ;
if ( * V_3 & V_33 ) {
V_27 -> V_57 . V_58 |= V_59 ;
V_23 -> V_48 = 1 ;
* V_3 = V_33 ;
} else if ( * V_3 & V_34 ) {
V_27 -> V_57 . V_58 &= ~ V_59 ;
V_63 = V_65 | V_66 ;
V_23 -> V_48 = 1 ;
* V_3 = V_34 ;
} else if ( * V_3 & V_37 ) {
V_27 -> V_57 . V_58 |= V_59 ;
V_63 = V_67 ;
V_23 -> V_48 = 1 ;
* V_3 = V_37 ;
} else if ( * V_3 & V_60 ) {
* V_3 = V_60 ;
} else {
* V_3 = V_23 -> V_3 ;
return - V_61 ;
}
F_31 ( V_27 , V_68 , & V_63 , 1 ) ;
F_29 ( V_27 , V_62 , V_27 -> V_57 . V_58 ,
V_59 ) ;
V_23 -> V_3 = * V_3 ;
return 0 ;
}
static int F_32 ( struct V_55 * V_55 , T_3 * V_3 )
{
struct V_22 * V_23 = V_55 -> V_56 ;
struct V_26 * V_27 = V_23 -> V_27 ;
switch ( V_27 -> V_49 ) {
case V_69 :
case V_70 :
return F_28 ( V_55 , V_3 ) ;
case V_51 :
case V_50 :
case V_71 :
case V_72 :
return F_30 ( V_55 , V_3 ) ;
default:
F_33 ( L_5 ,
V_27 -> V_49 ) ;
return - V_61 ;
}
}
static int F_34 ( struct V_26 * V_27 )
{
int V_73 = 0 ;
const unsigned short V_74 [] = {
0x1f , 0x30 , 0x47 , V_75
} ;
while ( V_74 [ V_73 ] != V_75 ) {
if ( F_35 ( & V_27 -> V_40 [ V_27 -> V_41 ] , V_74 [ V_73 ] ) == 1 )
return V_74 [ V_73 ] ;
V_73 ++ ;
}
return - V_76 ;
}
static void F_36 ( struct V_52 * V_53 )
{
struct V_26 * V_27 =
F_21 ( V_53 , struct V_26 , V_77 . V_53 ) ;
T_2 V_73 , V_78 ;
int V_79 ;
bool V_80 , V_81 ;
const struct V_82 * V_83 ;
for ( V_73 = 0 ; V_73 < V_27 -> V_84 ; V_73 ++ ) {
V_79 = F_37 ( V_27 , V_27 -> V_85 [ V_73 ] ) ;
if ( V_79 < 0 )
continue;
V_78 = 0 ;
while ( V_27 -> V_57 . V_86 [ V_78 ] . V_87 >= 0 &&
V_27 -> V_57 . V_86 [ V_78 ] . V_87 < V_88 ) {
struct V_89 * V_90 = & V_27 -> V_57 . V_86 [ V_78 ] ;
if ( V_90 -> V_91 != V_27 -> V_85 [ V_73 ] ) {
V_78 ++ ;
continue;
}
V_80 = V_79 & V_90 -> V_92 ;
V_81 = V_27 -> V_93 [ V_73 ]
& V_90 -> V_92 ;
if ( V_90 -> V_94 ) {
V_80 = ! V_80 ;
V_81 = ! V_81 ;
}
if ( V_80 && V_90 -> V_95 )
F_38 ( V_27 , V_90 -> V_95 ,
( ~ V_79 & V_90 -> V_92 )
| ( V_79 & ~ V_90 -> V_92 ) ) ;
if ( ! V_80 || V_81 ) {
V_78 ++ ;
continue;
}
switch ( V_90 -> V_87 ) {
case V_96 :
F_39 ( V_27 -> V_97 ,
V_98 , 1 ) ;
F_39 ( V_27 -> V_97 ,
V_98 , 0 ) ;
break;
case V_99 :
V_83 = F_40 ( V_27 ,
V_100 ) ;
if ( V_83 )
F_41 ( V_27 ,
V_83 -> V_101 ,
V_83 -> V_102 ) ;
break;
default:
F_42 ( 1 , L_6 ) ;
}
V_78 ++ ;
}
V_27 -> V_93 [ V_73 ] = V_79 ;
}
F_22 ( & V_27 -> V_77 ,
F_23 ( V_27 -> V_103 ) ) ;
}
static int F_43 ( struct V_26 * V_27 )
{
struct V_104 * V_104 ;
int V_105 ;
F_44 ( L_7 ) ;
V_104 = F_45 () ;
if ( ! V_104 )
return - V_106 ;
F_46 ( V_27 -> V_107 , V_27 -> V_108 ,
sizeof( V_27 -> V_108 ) ) ;
F_47 ( V_27 -> V_108 , L_8 ,
sizeof( V_27 -> V_108 ) ) ;
V_104 -> V_109 = L_9 ;
V_104 -> V_110 = V_27 -> V_108 ;
V_104 -> V_111 [ 0 ] = F_48 ( V_112 ) | F_48 ( V_113 ) ;
F_49 ( V_98 , V_104 -> V_114 ) ;
V_104 -> V_115 = 0 ;
V_104 -> V_116 = 0 ;
V_104 -> V_117 . V_118 = V_119 ;
V_104 -> V_117 . V_120 = F_50 ( V_27 -> V_107 -> V_121 . V_122 ) ;
V_104 -> V_117 . V_123 = F_50 ( V_27 -> V_107 -> V_121 . V_124 ) ;
V_104 -> V_117 . V_125 = 1 ;
V_104 -> V_27 . V_126 = & V_27 -> V_107 -> V_27 ;
V_105 = F_51 ( V_104 ) ;
if ( V_105 ) {
F_52 ( L_10 ) ;
F_53 ( V_104 ) ;
return V_105 ;
}
V_27 -> V_97 = V_104 ;
return 0 ;
}
static void F_54 ( struct V_26 * V_27 )
{
T_2 V_73 = 0 , V_78 = 0 ;
bool V_127 = 0 ;
V_27 -> V_103 = V_128 ;
while ( V_27 -> V_57 . V_86 [ V_73 ] . V_87 >= 0 &&
V_27 -> V_57 . V_86 [ V_73 ] . V_87 < V_88 ) {
struct V_89 * V_90 = & V_27 -> V_57 . V_86 [ V_73 ] ;
V_127 = 1 ;
for ( V_78 = 0 ; V_78 < V_27 -> V_84 ; V_78 ++ ) {
if ( V_90 -> V_91 == V_27 -> V_85 [ V_78 ] ) {
V_127 = 0 ;
break;
}
}
if ( V_127 && V_27 -> V_84
>= V_129 ) {
F_42 ( 1 , L_11 ) ;
goto V_130;
}
if ( V_90 -> V_87 == V_96 ) {
if ( F_43 ( V_27 ) < 0 )
goto V_130;
} else if ( V_90 -> V_87 == V_99 ) {
if ( ! F_40 ( V_27 , V_100 ) ) {
F_52 ( L_12 ) ;
goto V_130;
}
}
if ( V_127 ) {
unsigned int V_131 = V_27 -> V_84 ;
V_27 -> V_85 [ V_131 ] = V_90 -> V_91 ;
V_27 -> V_84 ++ ;
}
if ( ! V_90 -> V_95 )
V_27 -> V_103 =
V_132 ;
V_130:
V_73 ++ ;
}
if ( V_27 -> V_84 ) {
memset ( V_27 -> V_93 , 0 ,
V_129 ) ;
F_25 ( & V_27 -> V_77 ,
F_36 ) ;
F_22 ( & V_27 -> V_77 ,
F_23 ( V_27 -> V_103 ) ) ;
}
}
static void F_55 ( struct V_26 * V_27 )
{
F_27 ( & V_27 -> V_77 ) ;
V_27 -> V_84 = 0 ;
if ( V_27 -> V_97 != NULL ) {
F_44 ( L_13 ) ;
F_56 ( V_27 -> V_97 ) ;
V_27 -> V_97 = NULL ;
}
}
static int F_57 ( struct V_26 * V_27 )
{
struct V_22 * V_23 ;
struct V_55 * V_28 ;
int V_105 = - V_106 ;
T_3 V_3 ;
T_4 V_133 = 0 ;
if ( V_27 -> V_134 ) {
return 0 ;
}
F_58 ( & V_27 -> V_135 ) ;
if ( V_27 -> V_57 . V_86 )
F_54 ( V_27 ) ;
if ( V_27 -> V_57 . V_136 ) {
V_133 = F_34 ( V_27 ) ;
if ( ! V_133 ) {
V_27 -> V_57 . V_136 = 0 ;
F_59 ( L_14 ) ;
return - V_76 ;
}
}
if ( V_27 -> V_57 . V_137 == NULL && ! V_27 -> V_57 . V_136 ) {
F_59 ( L_15
L_16 ) ;
return 0 ;
}
F_44 ( L_17 ) ;
V_23 = F_60 ( sizeof( * V_23 ) , V_138 ) ;
V_28 = F_61 () ;
if ( ! V_23 || ! V_28 )
goto error;
V_23 -> V_27 = V_27 ;
V_27 -> V_23 = V_23 ;
V_23 -> V_28 = V_28 ;
V_28 -> V_56 = V_23 ;
V_28 -> V_139 = F_24 ;
V_28 -> V_140 = F_26 ;
if ( V_27 -> V_57 . V_136 ) {
switch ( V_27 -> V_141 ) {
case V_142 :
case V_143 :
V_28 -> V_144 = V_145 ;
V_23 -> V_43 = F_1 ;
break;
case V_146 :
V_28 -> V_144 = V_147 ;
V_23 -> V_43 = F_5 ;
break;
case V_148 :
V_28 -> V_144 = V_149 ;
V_23 -> V_43 = F_3 ;
V_28 -> V_150 = V_33 ;
break;
case V_151 :
V_28 -> V_144 = V_152 ;
V_23 -> V_43 = F_6 ;
break;
default:
V_105 = - V_76 ;
goto error;
}
V_23 -> V_42 = V_133 ;
} else {
switch ( V_27 -> V_49 ) {
case V_69 :
case V_70 :
V_28 -> V_150 = V_33 | V_34 ;
V_23 -> V_46 = F_8 ;
break;
case V_51 :
case V_50 :
case V_71 :
case V_72 :
V_23 -> V_46 = F_11 ;
V_28 -> V_150 = V_33 | V_34 |
V_37 ;
break;
default:
V_105 = - V_76 ;
goto error;
}
V_28 -> V_153 = F_32 ;
V_28 -> V_144 = V_27 -> V_57 . V_137 ;
V_3 = V_60 ;
V_105 = F_32 ( V_28 , & V_3 ) ;
if ( V_105 )
goto error;
}
V_23 -> V_54 = 100 ;
snprintf ( V_23 -> V_109 , sizeof( V_23 -> V_109 ) , L_18 , V_27 -> V_109 ) ;
F_46 ( V_27 -> V_107 , V_23 -> V_110 , sizeof( V_23 -> V_110 ) ) ;
F_47 ( V_23 -> V_110 , L_19 , sizeof( V_23 -> V_110 ) ) ;
V_28 -> V_154 = V_23 -> V_109 ;
V_28 -> V_155 = V_23 -> V_110 ;
V_28 -> V_156 . V_118 = V_119 ;
V_28 -> V_156 . V_125 = 1 ;
V_28 -> V_156 . V_120 = F_50 ( V_27 -> V_107 -> V_121 . V_122 ) ;
V_28 -> V_156 . V_123 = F_50 ( V_27 -> V_107 -> V_121 . V_124 ) ;
V_28 -> V_27 . V_126 = & V_27 -> V_107 -> V_27 ;
V_28 -> V_157 = V_158 ;
V_105 = F_62 ( V_28 ) ;
if ( V_105 )
goto error;
F_44 ( L_20 ) ;
return 0 ;
error:
V_27 -> V_23 = NULL ;
F_63 ( V_28 ) ;
F_64 ( V_23 ) ;
return V_105 ;
}
static int F_65 ( struct V_26 * V_27 )
{
struct V_22 * V_23 = V_27 -> V_23 ;
if ( V_27 -> V_134 ) {
return 0 ;
}
F_44 ( L_21 ) ;
F_55 ( V_27 ) ;
if ( ! V_23 )
goto V_159;
if ( V_23 -> V_28 )
F_66 ( V_23 -> V_28 ) ;
F_64 ( V_23 ) ;
V_27 -> V_23 = NULL ;
V_159:
F_67 ( & V_27 -> V_135 , V_160 ) ;
return 0 ;
}
static int F_68 ( struct V_26 * V_27 )
{
struct V_22 * V_23 = V_27 -> V_23 ;
if ( V_27 -> V_134 )
return 0 ;
F_44 ( L_22 ) ;
if ( V_23 )
F_27 ( & V_23 -> V_53 ) ;
F_27 ( & V_27 -> V_77 ) ;
return 0 ;
}
static int F_69 ( struct V_26 * V_27 )
{
struct V_22 * V_23 = V_27 -> V_23 ;
if ( V_27 -> V_134 )
return 0 ;
F_44 ( L_23 ) ;
if ( V_23 )
F_22 ( & V_23 -> V_53 , F_23 ( V_23 -> V_54 ) ) ;
if ( V_27 -> V_84 )
F_22 ( & V_27 -> V_77 ,
F_23 ( V_27 -> V_103 ) ) ;
return 0 ;
}
static int T_5 F_70 ( void )
{
return F_71 ( & V_161 ) ;
}
static void T_6 F_72 ( void )
{
F_73 ( & V_161 ) ;
}
