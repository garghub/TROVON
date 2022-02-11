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
F_33 ( L_5 ,
V_27 -> V_45 ) ;
return - V_57 ;
}
}
static int F_34 ( struct V_26 * V_27 )
{
int V_69 = 0 ;
const unsigned short V_70 [] = {
0x1f , 0x30 , 0x47 , V_71
} ;
while ( V_70 [ V_69 ] != V_71 ) {
if ( F_35 ( & V_27 -> V_72 [ V_27 -> V_73 ] , V_70 [ V_69 ] ) == 1 )
return V_70 [ V_69 ] ;
V_69 ++ ;
}
return - V_74 ;
}
static void F_36 ( struct V_48 * V_49 )
{
struct V_26 * V_27 =
F_21 ( V_49 , struct V_26 , V_75 . V_49 ) ;
T_2 V_69 , V_76 ;
int V_77 ;
bool V_78 , V_79 ;
const struct V_80 * V_81 ;
for ( V_69 = 0 ; V_69 < V_27 -> V_82 ; V_69 ++ ) {
V_77 = F_37 ( V_27 , V_27 -> V_83 [ V_69 ] ) ;
if ( V_77 < 0 )
continue;
V_76 = 0 ;
while ( V_27 -> V_53 . V_84 [ V_76 ] . V_85 >= 0 &&
V_27 -> V_53 . V_84 [ V_76 ] . V_85 < V_86 ) {
struct V_87 * V_88 = & V_27 -> V_53 . V_84 [ V_76 ] ;
if ( V_88 -> V_89 != V_27 -> V_83 [ V_69 ] ) {
V_76 ++ ;
continue;
}
V_78 = V_77 & V_88 -> V_90 ;
V_79 = V_27 -> V_91 [ V_69 ]
& V_88 -> V_90 ;
if ( V_88 -> V_92 ) {
V_78 = ! V_78 ;
V_79 = ! V_79 ;
}
if ( V_78 && V_88 -> V_93 )
F_38 ( V_27 , V_88 -> V_93 ,
( ~ V_77 & V_88 -> V_90 )
| ( V_77 & ~ V_88 -> V_90 ) ) ;
if ( ! V_78 || V_79 ) {
V_76 ++ ;
continue;
}
switch ( V_88 -> V_85 ) {
case V_94 :
F_39 ( V_27 -> V_95 ,
V_96 , 1 ) ;
F_39 ( V_27 -> V_95 ,
V_96 , 0 ) ;
break;
case V_97 :
V_81 = F_40 ( V_27 ,
V_98 ) ;
if ( V_81 )
F_41 ( V_27 ,
V_81 -> V_99 ,
V_81 -> V_100 ) ;
break;
default:
F_42 ( 1 , L_6 ) ;
}
V_76 ++ ;
}
V_27 -> V_91 [ V_69 ] = V_77 ;
}
F_22 ( & V_27 -> V_75 ,
F_23 ( V_27 -> V_101 ) ) ;
}
static int F_43 ( struct V_26 * V_27 )
{
struct V_102 * V_102 ;
int V_103 ;
F_44 ( L_7 ) ;
V_102 = F_45 () ;
if ( ! V_102 )
return - V_104 ;
F_46 ( V_27 -> V_105 , V_27 -> V_106 ,
sizeof( V_27 -> V_106 ) ) ;
F_47 ( V_27 -> V_106 , L_8 ,
sizeof( V_27 -> V_106 ) ) ;
V_102 -> V_107 = L_9 ;
V_102 -> V_108 = V_27 -> V_106 ;
V_102 -> V_109 [ 0 ] = F_48 ( V_110 ) | F_48 ( V_111 ) ;
F_49 ( V_96 , V_102 -> V_112 ) ;
V_102 -> V_113 = 0 ;
V_102 -> V_114 = 0 ;
V_102 -> V_115 . V_116 = V_117 ;
V_102 -> V_115 . V_118 = F_50 ( V_27 -> V_105 -> V_119 . V_120 ) ;
V_102 -> V_115 . V_121 = F_50 ( V_27 -> V_105 -> V_119 . V_122 ) ;
V_102 -> V_115 . V_123 = 1 ;
V_102 -> V_27 . V_124 = & V_27 -> V_105 -> V_27 ;
V_103 = F_51 ( V_102 ) ;
if ( V_103 ) {
F_52 ( L_10 ) ;
F_53 ( V_102 ) ;
return V_103 ;
}
V_27 -> V_95 = V_102 ;
return 0 ;
}
static void F_54 ( struct V_26 * V_27 )
{
T_2 V_69 = 0 , V_76 = 0 ;
bool V_125 = false ;
V_27 -> V_101 = V_126 ;
while ( V_27 -> V_53 . V_84 [ V_69 ] . V_85 >= 0 &&
V_27 -> V_53 . V_84 [ V_69 ] . V_85 < V_86 ) {
struct V_87 * V_88 = & V_27 -> V_53 . V_84 [ V_69 ] ;
V_125 = true ;
for ( V_76 = 0 ; V_76 < V_27 -> V_82 ; V_76 ++ ) {
if ( V_88 -> V_89 == V_27 -> V_83 [ V_76 ] ) {
V_125 = false ;
break;
}
}
if ( V_125 && V_27 -> V_82
>= V_127 ) {
F_42 ( 1 , L_11 ) ;
goto V_128;
}
if ( V_88 -> V_85 == V_94 ) {
if ( F_43 ( V_27 ) < 0 )
goto V_128;
} else if ( V_88 -> V_85 == V_97 ) {
if ( ! F_40 ( V_27 , V_98 ) ) {
F_52 ( L_12 ) ;
goto V_128;
}
}
if ( V_125 ) {
unsigned int V_129 = V_27 -> V_82 ;
V_27 -> V_83 [ V_129 ] = V_88 -> V_89 ;
V_27 -> V_82 ++ ;
}
if ( ! V_88 -> V_93 )
V_27 -> V_101 =
V_130 ;
V_128:
V_69 ++ ;
}
if ( V_27 -> V_82 ) {
memset ( V_27 -> V_91 , 0 ,
V_127 ) ;
F_25 ( & V_27 -> V_75 ,
F_36 ) ;
F_22 ( & V_27 -> V_75 ,
F_23 ( V_27 -> V_101 ) ) ;
}
}
static void F_55 ( struct V_26 * V_27 )
{
F_27 ( & V_27 -> V_75 ) ;
V_27 -> V_82 = 0 ;
if ( V_27 -> V_95 != NULL ) {
F_44 ( L_13 ) ;
F_56 ( V_27 -> V_95 ) ;
V_27 -> V_95 = NULL ;
}
}
static int F_57 ( struct V_26 * V_27 )
{
struct V_22 * V_23 ;
struct V_51 * V_28 ;
int V_103 = - V_104 ;
T_3 V_3 ;
T_4 V_131 = 0 ;
if ( V_27 -> V_132 ) {
return 0 ;
}
F_58 ( & V_27 -> V_133 ) ;
if ( V_27 -> V_53 . V_84 )
F_54 ( V_27 ) ;
if ( V_27 -> V_53 . V_134 ) {
V_131 = F_34 ( V_27 ) ;
if ( ! V_131 ) {
V_27 -> V_53 . V_134 = 0 ;
F_59 ( L_14 ) ;
return - V_74 ;
}
}
if ( V_27 -> V_53 . V_135 == NULL && ! V_27 -> V_53 . V_134 ) {
F_59 ( L_15
L_16 ) ;
return 0 ;
}
F_44 ( L_17 ) ;
V_23 = F_60 ( sizeof( * V_23 ) , V_136 ) ;
if ( ! V_23 )
return - V_104 ;
V_28 = F_61 () ;
if ( ! V_28 )
goto error;
V_23 -> V_27 = V_27 ;
V_27 -> V_23 = V_23 ;
V_23 -> V_28 = V_28 ;
V_28 -> V_52 = V_23 ;
V_28 -> V_137 = F_24 ;
V_28 -> V_138 = F_26 ;
if ( V_27 -> V_53 . V_134 ) {
switch ( V_27 -> V_139 ) {
case V_140 :
case V_141 :
V_28 -> V_142 = V_143 ;
V_23 -> V_39 = F_1 ;
break;
case V_144 :
V_28 -> V_142 = V_145 ;
V_23 -> V_39 = F_5 ;
break;
case V_146 :
V_28 -> V_142 = V_147 ;
V_23 -> V_39 = F_3 ;
V_28 -> V_148 = V_33 ;
break;
case V_149 :
V_28 -> V_142 = V_150 ;
V_23 -> V_39 = F_6 ;
break;
default:
V_103 = - V_74 ;
goto error;
}
V_23 -> V_1 = F_60 ( sizeof( struct V_1 ) , V_136 ) ;
if ( ! V_23 -> V_1 )
goto error;
V_23 -> V_1 -> V_21 = & V_23 -> V_27 -> V_72 [ V_27 -> V_73 ] ;
V_23 -> V_1 -> V_17 = V_131 ;
V_23 -> V_1 -> V_18 = 0 ;
} else {
switch ( V_27 -> V_45 ) {
case V_65 :
case V_66 :
V_28 -> V_148 = V_33 | V_34 ;
V_23 -> V_42 = F_8 ;
break;
case V_47 :
case V_46 :
case V_67 :
case V_68 :
V_23 -> V_42 = F_11 ;
V_28 -> V_148 = V_33 | V_34 |
V_37 ;
break;
default:
V_103 = - V_74 ;
goto error;
}
V_28 -> V_151 = F_32 ;
V_28 -> V_142 = V_27 -> V_53 . V_135 ;
V_3 = V_56 ;
V_103 = F_32 ( V_28 , & V_3 ) ;
if ( V_103 )
goto error;
}
V_23 -> V_50 = 100 ;
snprintf ( V_23 -> V_107 , sizeof( V_23 -> V_107 ) , L_18 , V_27 -> V_107 ) ;
F_46 ( V_27 -> V_105 , V_23 -> V_108 , sizeof( V_23 -> V_108 ) ) ;
F_47 ( V_23 -> V_108 , L_19 , sizeof( V_23 -> V_108 ) ) ;
V_28 -> V_152 = V_23 -> V_107 ;
V_28 -> V_153 = V_23 -> V_108 ;
V_28 -> V_154 . V_116 = V_117 ;
V_28 -> V_154 . V_123 = 1 ;
V_28 -> V_154 . V_118 = F_50 ( V_27 -> V_105 -> V_119 . V_120 ) ;
V_28 -> V_154 . V_121 = F_50 ( V_27 -> V_105 -> V_119 . V_122 ) ;
V_28 -> V_27 . V_124 = & V_27 -> V_105 -> V_27 ;
V_28 -> V_155 = V_156 ;
V_103 = F_62 ( V_28 ) ;
if ( V_103 )
goto error;
F_44 ( L_20 ) ;
return 0 ;
error:
F_63 ( V_23 -> V_1 ) ;
V_27 -> V_23 = NULL ;
F_64 ( V_28 ) ;
F_63 ( V_23 ) ;
return V_103 ;
}
static int F_65 ( struct V_26 * V_27 )
{
struct V_22 * V_23 = V_27 -> V_23 ;
if ( V_27 -> V_132 ) {
return 0 ;
}
F_44 ( L_21 ) ;
F_55 ( V_27 ) ;
if ( ! V_23 )
goto V_157;
F_66 ( V_23 -> V_28 ) ;
F_63 ( V_23 -> V_1 ) ;
F_63 ( V_23 ) ;
V_27 -> V_23 = NULL ;
V_157:
F_67 ( & V_27 -> V_133 , V_158 ) ;
return 0 ;
}
static int F_68 ( struct V_26 * V_27 )
{
struct V_22 * V_23 = V_27 -> V_23 ;
if ( V_27 -> V_132 )
return 0 ;
F_44 ( L_22 ) ;
if ( V_23 )
F_27 ( & V_23 -> V_49 ) ;
F_27 ( & V_27 -> V_75 ) ;
return 0 ;
}
static int F_69 ( struct V_26 * V_27 )
{
struct V_22 * V_23 = V_27 -> V_23 ;
if ( V_27 -> V_132 )
return 0 ;
F_44 ( L_23 ) ;
if ( V_23 )
F_22 ( & V_23 -> V_49 , F_23 ( V_23 -> V_50 ) ) ;
if ( V_27 -> V_82 )
F_22 ( & V_27 -> V_75 ,
F_23 ( V_27 -> V_101 ) ) ;
return 0 ;
}
static int T_5 F_70 ( void )
{
return F_71 ( & V_159 ) ;
}
static void T_6 F_72 ( void )
{
F_73 ( & V_159 ) ;
}
