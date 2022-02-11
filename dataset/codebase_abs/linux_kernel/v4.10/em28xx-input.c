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
static T_1 V_5 ;
enum V_3 V_4 ;
int V_28 ;
V_28 = V_23 -> V_39 ( V_23 -> V_1 , & V_4 , & V_5 ) ;
if ( V_28 < 0 ) {
F_16 ( L_1 , V_28 ) ;
return V_28 ;
}
if ( V_28 ) {
F_16 ( L_2 ,
V_40 , V_4 , V_5 ) ;
F_17 ( V_23 -> V_28 , V_4 , V_5 , 0 ) ;
}
return 0 ;
}
static void F_18 ( struct V_22 * V_23 )
{
int V_41 ;
struct V_24 V_25 ;
V_41 = V_23 -> V_42 ( V_23 , & V_25 ) ;
if ( F_19 ( V_41 < 0 ) ) {
F_16 ( L_3 , V_41 ) ;
return;
}
if ( F_19 ( V_25 . V_32 != V_23 -> V_43 ) ) {
F_16 ( L_4 , V_40 ,
V_25 . V_31 , V_25 . V_32 ,
V_25 . V_5 ) ;
if ( V_23 -> V_44 )
F_17 ( V_23 -> V_28 ,
V_25 . V_4 ,
V_25 . V_5 ,
V_25 . V_31 ) ;
else
F_17 ( V_23 -> V_28 ,
V_8 ,
V_25 . V_5 & 0xff ,
V_25 . V_31 ) ;
if ( V_23 -> V_27 -> V_45 == V_46 ||
V_23 -> V_27 -> V_45 == V_47 )
V_23 -> V_43 = 0 ;
else
V_23 -> V_43 = V_25 . V_32 ;
}
}
static void F_20 ( struct V_48 * V_49 )
{
struct V_22 * V_23 = F_21 ( V_49 , struct V_22 , V_49 . V_49 ) ;
if ( V_23 -> V_1 )
F_15 ( V_23 ) ;
else
F_18 ( V_23 ) ;
F_22 ( & V_23 -> V_49 , F_23 ( V_23 -> V_50 ) ) ;
}
static int F_24 ( struct V_51 * V_28 )
{
struct V_22 * V_23 = V_28 -> V_52 ;
F_25 ( & V_23 -> V_49 , F_20 ) ;
F_22 ( & V_23 -> V_49 , 0 ) ;
return 0 ;
}
static void F_26 ( struct V_51 * V_28 )
{
struct V_22 * V_23 = V_28 -> V_52 ;
F_27 ( & V_23 -> V_49 ) ;
}
static int F_28 ( struct V_51 * V_51 , T_3 * V_3 )
{
struct V_22 * V_23 = V_51 -> V_52 ;
struct V_26 * V_27 = V_23 -> V_27 ;
if ( * V_3 & V_33 ) {
V_27 -> V_53 . V_54 |= V_55 ;
V_23 -> V_44 = 1 ;
* V_3 = V_33 ;
} else if ( * V_3 & V_34 ) {
V_27 -> V_53 . V_54 &= ~ V_55 ;
V_23 -> V_44 = 1 ;
* V_3 = V_34 ;
} else if ( * V_3 & V_56 ) {
* V_3 = V_56 ;
} else {
* V_3 = V_23 -> V_3 ;
return - V_57 ;
}
F_29 ( V_27 , V_58 , V_27 -> V_53 . V_54 ,
V_55 ) ;
V_23 -> V_3 = * V_3 ;
return 0 ;
}
static int F_30 ( struct V_51 * V_51 , T_3 * V_3 )
{
struct V_22 * V_23 = V_51 -> V_52 ;
struct V_26 * V_27 = V_23 -> V_27 ;
T_2 V_59 = V_60 ;
if ( * V_3 & V_33 ) {
V_27 -> V_53 . V_54 |= V_55 ;
V_23 -> V_44 = 1 ;
* V_3 = V_33 ;
} else if ( * V_3 & V_34 ) {
V_27 -> V_53 . V_54 &= ~ V_55 ;
V_59 = V_61 | V_62 ;
V_23 -> V_44 = 1 ;
* V_3 = V_34 ;
} else if ( * V_3 & V_37 ) {
V_27 -> V_53 . V_54 |= V_55 ;
V_59 = V_63 ;
V_23 -> V_44 = 1 ;
* V_3 = V_37 ;
} else if ( * V_3 & V_56 ) {
* V_3 = V_56 ;
} else {
* V_3 = V_23 -> V_3 ;
return - V_57 ;
}
F_31 ( V_27 , V_64 , & V_59 , 1 ) ;
F_29 ( V_27 , V_58 , V_27 -> V_53 . V_54 ,
V_55 ) ;
V_23 -> V_3 = * V_3 ;
return 0 ;
}
static int F_32 ( struct V_51 * V_51 , T_3 * V_3 )
{
struct V_22 * V_23 = V_51 -> V_52 ;
struct V_26 * V_27 = V_23 -> V_27 ;
switch ( V_27 -> V_45 ) {
case V_65 :
case V_66 :
return F_28 ( V_51 , V_3 ) ;
case V_47 :
case V_46 :
case V_67 :
case V_68 :
return F_30 ( V_51 , V_3 ) ;
default:
F_33 ( & V_23 -> V_27 -> V_69 -> V_27 ,
L_5 ,
V_27 -> V_45 ) ;
return - V_57 ;
}
}
static int F_34 ( struct V_26 * V_27 )
{
int V_70 = 0 ;
const unsigned short V_71 [] = {
0x1f , 0x30 , 0x47 , V_72
} ;
while ( V_71 [ V_70 ] != V_72 ) {
if ( F_35 ( & V_27 -> V_73 [ V_27 -> V_74 ] , V_71 [ V_70 ] ) == 1 )
return V_71 [ V_70 ] ;
V_70 ++ ;
}
return - V_75 ;
}
static void F_36 ( struct V_48 * V_49 )
{
struct V_26 * V_27 =
F_21 ( V_49 , struct V_26 , V_76 . V_49 ) ;
T_2 V_70 , V_77 ;
int V_78 ;
bool V_79 , V_80 ;
const struct V_81 * V_82 ;
for ( V_70 = 0 ; V_70 < V_27 -> V_83 ; V_70 ++ ) {
V_78 = F_37 ( V_27 , V_27 -> V_84 [ V_70 ] ) ;
if ( V_78 < 0 )
continue;
V_77 = 0 ;
while ( V_27 -> V_53 . V_85 [ V_77 ] . V_86 >= 0 &&
V_27 -> V_53 . V_85 [ V_77 ] . V_86 < V_87 ) {
struct V_88 * V_89 = & V_27 -> V_53 . V_85 [ V_77 ] ;
if ( V_89 -> V_90 != V_27 -> V_84 [ V_70 ] ) {
V_77 ++ ;
continue;
}
V_79 = V_78 & V_89 -> V_91 ;
V_80 = V_27 -> V_92 [ V_70 ]
& V_89 -> V_91 ;
if ( V_89 -> V_93 ) {
V_79 = ! V_79 ;
V_80 = ! V_80 ;
}
if ( V_79 && V_89 -> V_94 )
F_38 ( V_27 , V_89 -> V_94 ,
( ~ V_78 & V_89 -> V_91 )
| ( V_78 & ~ V_89 -> V_91 ) ) ;
if ( ! V_79 || V_80 ) {
V_77 ++ ;
continue;
}
switch ( V_89 -> V_86 ) {
case V_95 :
F_39 ( V_27 -> V_96 ,
V_97 , 1 ) ;
F_39 ( V_27 -> V_96 ,
V_97 , 0 ) ;
break;
case V_98 :
V_82 = F_40 ( V_27 ,
V_99 ) ;
if ( V_82 )
F_41 ( V_27 ,
V_82 -> V_100 ,
V_82 -> V_101 ) ;
break;
default:
F_42 ( 1 , L_6 ) ;
}
V_77 ++ ;
}
V_27 -> V_92 [ V_70 ] = V_78 ;
}
F_22 ( & V_27 -> V_76 ,
F_23 ( V_27 -> V_102 ) ) ;
}
static int F_43 ( struct V_26 * V_27 )
{
struct V_103 * V_104 = F_44 ( V_27 -> V_69 ) ;
struct V_105 * V_105 ;
int V_106 ;
F_45 ( & V_27 -> V_69 -> V_27 , L_7 ) ;
V_105 = F_46 () ;
if ( ! V_105 )
return - V_107 ;
F_47 ( V_104 , V_27 -> V_108 ,
sizeof( V_27 -> V_108 ) ) ;
F_48 ( V_27 -> V_108 , L_8 ,
sizeof( V_27 -> V_108 ) ) ;
V_105 -> V_109 = L_9 ;
V_105 -> V_110 = V_27 -> V_108 ;
V_105 -> V_111 [ 0 ] = F_49 ( V_112 ) | F_49 ( V_113 ) ;
F_50 ( V_97 , V_105 -> V_114 ) ;
V_105 -> V_115 = 0 ;
V_105 -> V_116 = 0 ;
V_105 -> V_117 . V_118 = V_119 ;
V_105 -> V_117 . V_120 = F_51 ( V_104 -> V_121 . V_122 ) ;
V_105 -> V_117 . V_123 = F_51 ( V_104 -> V_121 . V_124 ) ;
V_105 -> V_117 . V_125 = 1 ;
V_105 -> V_27 . V_126 = & V_27 -> V_69 -> V_27 ;
V_106 = F_52 ( V_105 ) ;
if ( V_106 ) {
F_33 ( & V_27 -> V_69 -> V_27 , L_10 ) ;
F_53 ( V_105 ) ;
return V_106 ;
}
V_27 -> V_96 = V_105 ;
return 0 ;
}
static void F_54 ( struct V_26 * V_27 )
{
T_2 V_70 = 0 , V_77 = 0 ;
bool V_127 = false ;
V_27 -> V_102 = V_128 ;
while ( V_27 -> V_53 . V_85 [ V_70 ] . V_86 >= 0 &&
V_27 -> V_53 . V_85 [ V_70 ] . V_86 < V_87 ) {
struct V_88 * V_89 = & V_27 -> V_53 . V_85 [ V_70 ] ;
V_127 = true ;
for ( V_77 = 0 ; V_77 < V_27 -> V_83 ; V_77 ++ ) {
if ( V_89 -> V_90 == V_27 -> V_84 [ V_77 ] ) {
V_127 = false ;
break;
}
}
if ( V_127 && V_27 -> V_83
>= V_129 ) {
F_42 ( 1 , L_11 ) ;
goto V_130;
}
if ( V_89 -> V_86 == V_95 ) {
if ( F_43 ( V_27 ) < 0 )
goto V_130;
} else if ( V_89 -> V_86 == V_98 ) {
if ( ! F_40 ( V_27 , V_99 ) ) {
F_33 ( & V_27 -> V_69 -> V_27 ,
L_12 ) ;
goto V_130;
}
}
if ( V_127 ) {
unsigned int V_131 = V_27 -> V_83 ;
V_27 -> V_84 [ V_131 ] = V_89 -> V_90 ;
V_27 -> V_83 ++ ;
}
if ( ! V_89 -> V_94 )
V_27 -> V_102 =
V_132 ;
V_130:
V_70 ++ ;
}
if ( V_27 -> V_83 ) {
memset ( V_27 -> V_92 , 0 ,
V_129 ) ;
F_22 ( & V_27 -> V_76 ,
F_23 ( V_27 -> V_102 ) ) ;
}
}
static void F_55 ( struct V_26 * V_27 )
{
F_27 ( & V_27 -> V_76 ) ;
V_27 -> V_83 = 0 ;
if ( V_27 -> V_96 != NULL ) {
F_45 ( & V_27 -> V_69 -> V_27 , L_13 ) ;
F_56 ( V_27 -> V_96 ) ;
V_27 -> V_96 = NULL ;
}
}
static int F_57 ( struct V_26 * V_27 )
{
struct V_103 * V_104 = F_44 ( V_27 -> V_69 ) ;
struct V_22 * V_23 ;
struct V_51 * V_28 ;
int V_106 = - V_107 ;
T_3 V_3 ;
T_4 V_133 = 0 ;
if ( V_27 -> V_134 ) {
return 0 ;
}
F_58 ( & V_27 -> V_135 ) ;
F_25 ( & V_27 -> V_76 , F_36 ) ;
if ( V_27 -> V_53 . V_85 )
F_54 ( V_27 ) ;
if ( V_27 -> V_53 . V_136 ) {
V_133 = F_34 ( V_27 ) ;
if ( ! V_133 ) {
V_27 -> V_53 . V_136 = 0 ;
F_59 ( & V_27 -> V_69 -> V_27 ,
L_14 ) ;
return - V_75 ;
}
}
if ( V_27 -> V_53 . V_137 == NULL && ! V_27 -> V_53 . V_136 ) {
F_59 ( & V_27 -> V_69 -> V_27 ,
L_15 ) ;
return 0 ;
}
F_45 ( & V_27 -> V_69 -> V_27 , L_16 ) ;
V_23 = F_60 ( sizeof( * V_23 ) , V_138 ) ;
if ( ! V_23 )
return - V_107 ;
V_28 = F_61 () ;
if ( ! V_28 )
goto error;
V_23 -> V_27 = V_27 ;
V_27 -> V_23 = V_23 ;
V_23 -> V_28 = V_28 ;
V_28 -> V_52 = V_23 ;
V_28 -> V_139 = F_24 ;
V_28 -> V_140 = F_26 ;
if ( V_27 -> V_53 . V_136 ) {
switch ( V_27 -> V_141 ) {
case V_142 :
case V_143 :
V_28 -> V_144 = V_145 ;
V_23 -> V_39 = F_1 ;
break;
case V_146 :
V_28 -> V_144 = V_147 ;
V_23 -> V_39 = F_5 ;
break;
case V_148 :
V_28 -> V_144 = V_149 ;
V_23 -> V_39 = F_3 ;
V_28 -> V_150 = V_33 ;
break;
case V_151 :
V_28 -> V_144 = V_152 ;
V_23 -> V_39 = F_6 ;
break;
default:
V_106 = - V_75 ;
goto error;
}
V_23 -> V_1 = F_60 ( sizeof( struct V_1 ) , V_138 ) ;
if ( ! V_23 -> V_1 )
goto error;
V_23 -> V_1 -> V_21 = & V_23 -> V_27 -> V_73 [ V_27 -> V_74 ] ;
V_23 -> V_1 -> V_17 = V_133 ;
V_23 -> V_1 -> V_18 = 0 ;
} else {
switch ( V_27 -> V_45 ) {
case V_65 :
case V_66 :
V_28 -> V_150 = V_33 | V_34 ;
V_23 -> V_42 = F_8 ;
break;
case V_47 :
case V_46 :
case V_67 :
case V_68 :
V_23 -> V_42 = F_11 ;
V_28 -> V_150 = V_33 | V_34 |
V_37 ;
break;
default:
V_106 = - V_75 ;
goto error;
}
V_28 -> V_153 = F_32 ;
V_28 -> V_144 = V_27 -> V_53 . V_137 ;
V_3 = V_56 ;
V_106 = F_32 ( V_28 , & V_3 ) ;
if ( V_106 )
goto error;
}
V_23 -> V_50 = 100 ;
snprintf ( V_23 -> V_109 , sizeof( V_23 -> V_109 ) , L_17 ,
F_62 ( & V_27 -> V_69 -> V_27 ) ) ;
F_47 ( V_104 , V_23 -> V_110 , sizeof( V_23 -> V_110 ) ) ;
F_48 ( V_23 -> V_110 , L_18 , sizeof( V_23 -> V_110 ) ) ;
V_28 -> V_154 = V_23 -> V_109 ;
V_28 -> V_155 = V_23 -> V_110 ;
V_28 -> V_156 . V_118 = V_119 ;
V_28 -> V_156 . V_125 = 1 ;
V_28 -> V_156 . V_120 = F_51 ( V_104 -> V_121 . V_122 ) ;
V_28 -> V_156 . V_123 = F_51 ( V_104 -> V_121 . V_124 ) ;
V_28 -> V_27 . V_126 = & V_27 -> V_69 -> V_27 ;
V_28 -> V_157 = V_158 ;
V_106 = F_63 ( V_28 ) ;
if ( V_106 )
goto error;
F_45 ( & V_27 -> V_69 -> V_27 , L_19 ) ;
return 0 ;
error:
F_64 ( V_23 -> V_1 ) ;
V_27 -> V_23 = NULL ;
F_65 ( V_28 ) ;
F_64 ( V_23 ) ;
return V_106 ;
}
static int F_66 ( struct V_26 * V_27 )
{
struct V_22 * V_23 = V_27 -> V_23 ;
if ( V_27 -> V_134 ) {
return 0 ;
}
F_45 ( & V_27 -> V_69 -> V_27 , L_20 ) ;
F_55 ( V_27 ) ;
if ( ! V_23 )
goto V_159;
F_67 ( V_23 -> V_28 ) ;
F_64 ( V_23 -> V_1 ) ;
F_64 ( V_23 ) ;
V_27 -> V_23 = NULL ;
V_159:
F_68 ( & V_27 -> V_135 , V_160 ) ;
return 0 ;
}
static int F_69 ( struct V_26 * V_27 )
{
struct V_22 * V_23 = V_27 -> V_23 ;
if ( V_27 -> V_134 )
return 0 ;
F_45 ( & V_27 -> V_69 -> V_27 , L_21 ) ;
if ( V_23 )
F_27 ( & V_23 -> V_49 ) ;
F_27 ( & V_27 -> V_76 ) ;
return 0 ;
}
static int F_70 ( struct V_26 * V_27 )
{
struct V_22 * V_23 = V_27 -> V_23 ;
if ( V_27 -> V_134 )
return 0 ;
F_45 ( & V_27 -> V_69 -> V_27 , L_22 ) ;
if ( V_23 )
F_22 ( & V_23 -> V_49 , F_23 ( V_23 -> V_50 ) ) ;
if ( V_27 -> V_83 )
F_22 ( & V_27 -> V_76 ,
F_23 ( V_27 -> V_102 ) ) ;
return 0 ;
}
static int T_5 F_71 ( void )
{
return F_72 ( & V_161 ) ;
}
static void T_6 F_73 ( void )
{
F_74 ( & V_161 ) ;
}
