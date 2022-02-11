static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
unsigned char V_4 ;
if ( 1 != F_2 ( V_2 , & V_4 , 1 ) )
return - V_5 ;
if ( V_4 == 0xff )
return 0 ;
if ( V_4 == 0xfe )
return 1 ;
* V_3 = V_4 ;
return 1 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 * V_3 )
{
unsigned char V_6 [ 2 ] ;
T_2 V_7 ;
int V_8 ;
V_8 = F_2 ( V_2 , V_6 , sizeof( V_6 ) ) ;
if ( V_8 != 2 )
return - V_5 ;
if ( V_6 [ 1 ] == 0xff )
return 0 ;
V_7 =
( ( V_6 [ 0 ] & 0x01 ) ? 0x0020 : 0 ) |
( ( V_6 [ 0 ] & 0x02 ) ? 0x0010 : 0 ) |
( ( V_6 [ 0 ] & 0x04 ) ? 0x0008 : 0 ) |
( ( V_6 [ 0 ] & 0x08 ) ? 0x0004 : 0 ) |
( ( V_6 [ 0 ] & 0x10 ) ? 0x0002 : 0 ) |
( ( V_6 [ 0 ] & 0x20 ) ? 0x0001 : 0 ) |
( ( V_6 [ 1 ] & 0x08 ) ? 0x1000 : 0 ) |
( ( V_6 [ 1 ] & 0x10 ) ? 0x0800 : 0 ) |
( ( V_6 [ 1 ] & 0x20 ) ? 0x0400 : 0 ) |
( ( V_6 [ 1 ] & 0x40 ) ? 0x0200 : 0 ) |
( ( V_6 [ 1 ] & 0x80 ) ? 0x0100 : 0 ) ;
* V_3 = V_7 ;
return 1 ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 * V_3 )
{
unsigned char V_6 [ 3 ] ;
if ( 3 != F_2 ( V_2 , V_6 , 3 ) )
return - V_5 ;
if ( V_6 [ 0 ] != 0x00 )
return 0 ;
* V_3 = V_6 [ 2 ] & 0x3f ;
return 1 ;
}
static int F_5 ( struct V_1 * V_2 ,
T_1 * V_3 )
{
unsigned char V_9 , V_10 , V_11 ;
struct V_12 V_13 [] = { { . V_14 = V_2 -> V_14 , . V_15 = 0 , . V_6 = & V_9 , . V_16 = 1 } ,
{ . V_14 = V_2 -> V_14 , . V_15 = V_17 , . V_6 = & V_10 , . V_16 = 1 } } ;
V_9 = 0x10 ;
if ( 2 != F_6 ( V_2 -> V_18 , V_13 , 2 ) )
return - V_5 ;
if ( V_10 == 0x00 )
return 0 ;
V_9 = 0x00 ;
V_13 [ 1 ] . V_6 = & V_11 ;
if ( 2 != F_6 ( V_2 -> V_18 , V_13 , 2 ) )
return - V_5 ;
if ( V_11 == 0x00 )
return 0 ;
* V_3 = V_11 ;
return 1 ;
}
static int F_7 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = V_20 -> V_24 ;
int V_25 ;
T_3 V_13 [ 3 ] = { 0 , 0 , 0 } ;
V_25 = V_24 -> V_26 ( V_24 , 0 , V_27 ,
V_13 , sizeof( V_13 ) ) ;
if ( V_25 < 0 )
return V_25 ;
V_22 -> V_28 = ( V_13 [ 0 ] >> 7 ) ;
V_22 -> V_29 = ( V_13 [ 0 ] & 0x7f ) ;
V_22 -> V_30 = V_13 [ 1 ] << 8 | V_13 [ 2 ] ;
return 0 ;
}
static int F_8 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = V_20 -> V_24 ;
int V_25 ;
T_3 V_13 [ 5 ] = { 0 , 0 , 0 , 0 , 0 } ;
V_25 = V_24 -> V_26 ( V_24 , 0 , V_31 ,
V_13 , sizeof( V_13 ) ) ;
if ( V_25 < 0 )
return V_25 ;
V_22 -> V_28 = ( V_13 [ 0 ] >> 7 ) ;
V_22 -> V_29 = ( V_13 [ 0 ] & 0x7f ) ;
switch ( V_20 -> V_32 ) {
case V_33 :
V_22 -> V_30 = V_13 [ 1 ] << 8 | V_13 [ 2 ] ;
break;
case V_34 :
if ( ( V_13 [ 3 ] ^ V_13 [ 4 ] ) != 0xff )
V_22 -> V_30 = ( V_13 [ 1 ] << 24 ) |
( V_13 [ 2 ] << 16 ) |
( V_13 [ 3 ] << 8 ) |
V_13 [ 4 ] ;
else if ( ( V_13 [ 1 ] ^ V_13 [ 2 ] ) != 0xff )
V_22 -> V_30 = ( V_13 [ 1 ] << 16 ) |
( V_13 [ 2 ] << 8 ) |
V_13 [ 3 ] ;
else
V_22 -> V_30 = V_13 [ 1 ] << 8 | V_13 [ 3 ] ;
break;
case V_35 :
V_22 -> V_30 = V_13 [ 1 ] << 8 | V_13 [ 2 ] ;
break;
default:
V_22 -> V_30 = ( V_13 [ 1 ] << 24 ) | ( V_13 [ 2 ] << 16 ) |
( V_13 [ 3 ] << 8 ) | V_13 [ 4 ] ;
break;
}
return 0 ;
}
static int F_9 ( struct V_19 * V_20 )
{
struct V_23 * V_24 = V_20 -> V_24 ;
static T_1 V_3 ;
int V_25 ;
struct V_1 V_36 ;
V_36 . V_18 = & V_20 -> V_24 -> V_37 [ V_24 -> V_38 ] ;
V_36 . V_14 = V_20 -> V_39 ;
V_25 = V_20 -> V_40 ( & V_36 , & V_3 ) ;
if ( V_25 < 0 ) {
F_10 ( L_1 , V_25 ) ;
return V_25 ;
}
if ( V_25 ) {
F_10 ( L_2 , V_41 , V_3 ) ;
F_11 ( V_20 -> V_25 , V_3 , 0 ) ;
}
return 0 ;
}
static void F_12 ( struct V_19 * V_20 )
{
int V_42 ;
struct V_21 V_22 ;
V_42 = V_20 -> V_43 ( V_20 , & V_22 ) ;
if ( F_13 ( V_42 < 0 ) ) {
F_10 ( L_3 , V_42 ) ;
return;
}
if ( F_13 ( V_22 . V_29 != V_20 -> V_44 ) ) {
F_10 ( L_4 , V_41 ,
V_22 . V_28 , V_22 . V_29 ,
V_22 . V_30 ) ;
if ( V_20 -> V_45 )
F_11 ( V_20 -> V_25 ,
V_22 . V_30 ,
V_22 . V_28 ) ;
else
F_11 ( V_20 -> V_25 ,
V_22 . V_30 & 0xff ,
V_22 . V_28 ) ;
if ( V_20 -> V_24 -> V_46 == V_47 ||
V_20 -> V_24 -> V_46 == V_48 )
V_20 -> V_44 = 0 ;
else
V_20 -> V_44 = V_22 . V_29 ;
}
}
static void F_14 ( struct V_49 * V_50 )
{
struct V_19 * V_20 = F_15 ( V_50 , struct V_19 , V_50 . V_50 ) ;
if ( V_20 -> V_39 )
F_9 ( V_20 ) ;
else
F_12 ( V_20 ) ;
F_16 ( & V_20 -> V_50 , F_17 ( V_20 -> V_51 ) ) ;
}
static int F_18 ( struct V_52 * V_25 )
{
struct V_19 * V_20 = V_25 -> V_53 ;
F_19 ( & V_20 -> V_50 , F_14 ) ;
F_16 ( & V_20 -> V_50 , 0 ) ;
return 0 ;
}
static void F_20 ( struct V_52 * V_25 )
{
struct V_19 * V_20 = V_25 -> V_53 ;
F_21 ( & V_20 -> V_50 ) ;
}
static int F_22 ( struct V_52 * V_52 , T_4 * V_32 )
{
struct V_19 * V_20 = V_52 -> V_53 ;
struct V_23 * V_24 = V_20 -> V_24 ;
if ( * V_32 & V_33 ) {
V_24 -> V_54 . V_55 |= V_56 ;
V_20 -> V_45 = 1 ;
* V_32 = V_33 ;
} else if ( * V_32 & V_34 ) {
V_24 -> V_54 . V_55 &= ~ V_56 ;
V_20 -> V_45 = 1 ;
* V_32 = V_34 ;
} else if ( * V_32 & V_57 ) {
* V_32 = V_57 ;
} else {
* V_32 = V_20 -> V_32 ;
return - V_58 ;
}
F_23 ( V_24 , V_59 , V_24 -> V_54 . V_55 ,
V_56 ) ;
V_20 -> V_32 = * V_32 ;
return 0 ;
}
static int F_24 ( struct V_52 * V_52 , T_4 * V_32 )
{
struct V_19 * V_20 = V_52 -> V_53 ;
struct V_23 * V_24 = V_20 -> V_24 ;
T_3 V_60 = V_61 ;
if ( * V_32 & V_33 ) {
V_24 -> V_54 . V_55 |= V_56 ;
V_20 -> V_45 = 1 ;
* V_32 = V_33 ;
} else if ( * V_32 & V_34 ) {
V_24 -> V_54 . V_55 &= ~ V_56 ;
V_60 = V_62 | V_63 ;
V_20 -> V_45 = 1 ;
* V_32 = V_34 ;
} else if ( * V_32 & V_35 ) {
V_24 -> V_54 . V_55 |= V_56 ;
V_60 = V_64 ;
V_20 -> V_45 = 1 ;
* V_32 = V_35 ;
} else if ( * V_32 & V_57 ) {
* V_32 = V_57 ;
} else {
* V_32 = V_20 -> V_32 ;
return - V_58 ;
}
F_25 ( V_24 , V_65 , & V_60 , 1 ) ;
F_23 ( V_24 , V_59 , V_24 -> V_54 . V_55 ,
V_56 ) ;
V_20 -> V_32 = * V_32 ;
return 0 ;
}
static int F_26 ( struct V_52 * V_52 , T_4 * V_32 )
{
struct V_19 * V_20 = V_52 -> V_53 ;
struct V_23 * V_24 = V_20 -> V_24 ;
switch ( V_24 -> V_46 ) {
case V_66 :
case V_67 :
return F_22 ( V_52 , V_32 ) ;
case V_48 :
case V_47 :
case V_68 :
case V_69 :
return F_24 ( V_52 , V_32 ) ;
default:
F_27 ( L_5 ,
V_24 -> V_46 ) ;
return - V_58 ;
}
}
static int F_28 ( struct V_23 * V_24 )
{
int V_70 = 0 ;
const unsigned short V_71 [] = {
0x1f , 0x30 , 0x47 , V_72
} ;
while ( V_71 [ V_70 ] != V_72 ) {
if ( F_29 ( & V_24 -> V_37 [ V_24 -> V_38 ] , V_71 [ V_70 ] ) == 1 )
return V_71 [ V_70 ] ;
V_70 ++ ;
}
return - V_73 ;
}
static void F_30 ( struct V_49 * V_50 )
{
struct V_23 * V_24 =
F_15 ( V_50 , struct V_23 , V_74 . V_50 ) ;
T_3 V_70 , V_75 ;
int V_76 ;
bool V_77 , V_78 ;
const struct V_79 * V_80 ;
for ( V_70 = 0 ; V_70 < V_24 -> V_81 ; V_70 ++ ) {
V_76 = F_31 ( V_24 , V_24 -> V_82 [ V_70 ] ) ;
if ( V_76 < 0 )
continue;
V_75 = 0 ;
while ( V_24 -> V_54 . V_83 [ V_75 ] . V_84 >= 0 &&
V_24 -> V_54 . V_83 [ V_75 ] . V_84 < V_85 ) {
struct V_86 * V_87 = & V_24 -> V_54 . V_83 [ V_75 ] ;
if ( V_87 -> V_88 != V_24 -> V_82 [ V_70 ] ) {
V_75 ++ ;
continue;
}
V_77 = V_76 & V_87 -> V_89 ;
V_78 = V_24 -> V_90 [ V_70 ]
& V_87 -> V_89 ;
if ( V_87 -> V_91 ) {
V_77 = ! V_77 ;
V_78 = ! V_78 ;
}
if ( V_77 && V_87 -> V_92 )
F_32 ( V_24 , V_87 -> V_92 ,
( ~ V_76 & V_87 -> V_89 )
| ( V_76 & ~ V_87 -> V_89 ) ) ;
if ( ! V_77 || V_78 ) {
V_75 ++ ;
continue;
}
switch ( V_87 -> V_84 ) {
case V_93 :
F_33 ( V_24 -> V_94 ,
V_95 , 1 ) ;
F_33 ( V_24 -> V_94 ,
V_95 , 0 ) ;
break;
case V_96 :
V_80 = F_34 ( V_24 ,
V_97 ) ;
if ( V_80 )
F_35 ( V_24 ,
V_80 -> V_98 ,
V_80 -> V_99 ) ;
break;
default:
F_36 ( 1 , L_6 ) ;
}
V_75 ++ ;
}
V_24 -> V_90 [ V_70 ] = V_76 ;
}
F_16 ( & V_24 -> V_74 ,
F_17 ( V_24 -> V_100 ) ) ;
}
static int F_37 ( struct V_23 * V_24 )
{
struct V_101 * V_101 ;
int V_102 ;
F_38 ( L_7 ) ;
V_101 = F_39 () ;
if ( ! V_101 )
return - V_103 ;
F_40 ( V_24 -> V_104 , V_24 -> V_105 ,
sizeof( V_24 -> V_105 ) ) ;
F_41 ( V_24 -> V_105 , L_8 ,
sizeof( V_24 -> V_105 ) ) ;
V_101 -> V_106 = L_9 ;
V_101 -> V_107 = V_24 -> V_105 ;
V_101 -> V_108 [ 0 ] = F_42 ( V_109 ) | F_42 ( V_110 ) ;
F_43 ( V_95 , V_101 -> V_111 ) ;
V_101 -> V_112 = 0 ;
V_101 -> V_113 = 0 ;
V_101 -> V_114 . V_115 = V_116 ;
V_101 -> V_114 . V_117 = F_44 ( V_24 -> V_104 -> V_118 . V_119 ) ;
V_101 -> V_114 . V_120 = F_44 ( V_24 -> V_104 -> V_118 . V_121 ) ;
V_101 -> V_114 . V_122 = 1 ;
V_101 -> V_24 . V_123 = & V_24 -> V_104 -> V_24 ;
V_102 = F_45 ( V_101 ) ;
if ( V_102 ) {
F_46 ( L_10 ) ;
F_47 ( V_101 ) ;
return V_102 ;
}
V_24 -> V_94 = V_101 ;
return 0 ;
}
static void F_48 ( struct V_23 * V_24 )
{
T_3 V_70 = 0 , V_75 = 0 ;
bool V_124 = 0 ;
V_24 -> V_100 = V_125 ;
while ( V_24 -> V_54 . V_83 [ V_70 ] . V_84 >= 0 &&
V_24 -> V_54 . V_83 [ V_70 ] . V_84 < V_85 ) {
struct V_86 * V_87 = & V_24 -> V_54 . V_83 [ V_70 ] ;
V_124 = 1 ;
for ( V_75 = 0 ; V_75 < V_24 -> V_81 ; V_75 ++ ) {
if ( V_87 -> V_88 == V_24 -> V_82 [ V_75 ] ) {
V_124 = 0 ;
break;
}
}
if ( V_124 && V_24 -> V_81
>= V_126 ) {
F_36 ( 1 , L_11 ) ;
goto V_127;
}
if ( V_87 -> V_84 == V_93 ) {
if ( F_37 ( V_24 ) < 0 )
goto V_127;
} else if ( V_87 -> V_84 == V_96 ) {
if ( ! F_34 ( V_24 , V_97 ) ) {
F_46 ( L_12 ) ;
goto V_127;
}
}
if ( V_124 ) {
unsigned int V_128 = V_24 -> V_81 ;
V_24 -> V_82 [ V_128 ] = V_87 -> V_88 ;
V_24 -> V_81 ++ ;
}
if ( ! V_87 -> V_92 )
V_24 -> V_100 =
V_129 ;
V_127:
V_70 ++ ;
}
if ( V_24 -> V_81 ) {
memset ( V_24 -> V_90 , 0 ,
V_126 ) ;
F_19 ( & V_24 -> V_74 ,
F_30 ) ;
F_16 ( & V_24 -> V_74 ,
F_17 ( V_24 -> V_100 ) ) ;
}
}
static void F_49 ( struct V_23 * V_24 )
{
F_21 ( & V_24 -> V_74 ) ;
V_24 -> V_81 = 0 ;
if ( V_24 -> V_94 != NULL ) {
F_38 ( L_13 ) ;
F_50 ( V_24 -> V_94 ) ;
V_24 -> V_94 = NULL ;
}
}
static int F_51 ( struct V_23 * V_24 )
{
struct V_19 * V_20 ;
struct V_52 * V_25 ;
int V_102 = - V_103 ;
T_4 V_32 ;
T_2 V_130 = 0 ;
if ( V_24 -> V_131 ) {
return 0 ;
}
if ( V_24 -> V_54 . V_83 )
F_48 ( V_24 ) ;
if ( V_24 -> V_54 . V_132 ) {
V_130 = F_28 ( V_24 ) ;
if ( ! V_130 ) {
V_24 -> V_54 . V_132 = 0 ;
F_52 ( L_14 ) ;
return - V_73 ;
}
}
if ( V_24 -> V_54 . V_133 == NULL && ! V_24 -> V_54 . V_132 ) {
F_52 ( L_15
L_16 ) ;
return 0 ;
}
F_38 ( L_17 ) ;
V_20 = F_53 ( sizeof( * V_20 ) , V_134 ) ;
V_25 = F_54 () ;
if ( ! V_20 || ! V_25 )
goto error;
V_20 -> V_24 = V_24 ;
V_24 -> V_20 = V_20 ;
V_20 -> V_25 = V_25 ;
V_25 -> V_53 = V_20 ;
V_25 -> V_135 = F_18 ;
V_25 -> V_136 = F_20 ;
if ( V_24 -> V_54 . V_132 ) {
switch ( V_24 -> V_137 ) {
case V_138 :
case V_139 :
V_25 -> V_140 = V_141 ;
V_20 -> V_40 = F_1 ;
break;
case V_142 :
V_25 -> V_140 = V_143 ;
V_20 -> V_40 = F_4 ;
break;
case V_144 :
V_25 -> V_140 = V_145 ;
V_20 -> V_40 = F_3 ;
V_25 -> V_146 = V_33 ;
break;
case V_147 :
V_25 -> V_140 = V_148 ;
V_20 -> V_40 = F_5 ;
break;
default:
V_102 = - V_73 ;
goto error;
}
V_20 -> V_39 = V_130 ;
} else {
switch ( V_24 -> V_46 ) {
case V_66 :
case V_67 :
V_25 -> V_146 = V_33 | V_34 ;
V_20 -> V_43 = F_7 ;
break;
case V_48 :
case V_47 :
case V_68 :
case V_69 :
V_20 -> V_43 = F_8 ;
V_25 -> V_146 = V_33 | V_34 |
V_35 ;
break;
default:
V_102 = - V_73 ;
goto error;
}
V_25 -> V_149 = F_26 ;
V_25 -> V_140 = V_24 -> V_54 . V_133 ;
V_32 = V_57 ;
V_102 = F_26 ( V_25 , & V_32 ) ;
if ( V_102 )
goto error;
}
V_20 -> V_51 = 100 ;
snprintf ( V_20 -> V_106 , sizeof( V_20 -> V_106 ) , L_18 , V_24 -> V_106 ) ;
F_40 ( V_24 -> V_104 , V_20 -> V_107 , sizeof( V_20 -> V_107 ) ) ;
F_41 ( V_20 -> V_107 , L_19 , sizeof( V_20 -> V_107 ) ) ;
V_25 -> V_150 = V_20 -> V_106 ;
V_25 -> V_151 = V_20 -> V_107 ;
V_25 -> V_152 . V_115 = V_116 ;
V_25 -> V_152 . V_122 = 1 ;
V_25 -> V_152 . V_117 = F_44 ( V_24 -> V_104 -> V_118 . V_119 ) ;
V_25 -> V_152 . V_120 = F_44 ( V_24 -> V_104 -> V_118 . V_121 ) ;
V_25 -> V_24 . V_123 = & V_24 -> V_104 -> V_24 ;
V_25 -> V_153 = V_154 ;
V_102 = F_55 ( V_25 ) ;
if ( V_102 )
goto error;
F_38 ( L_20 ) ;
return 0 ;
error:
V_24 -> V_20 = NULL ;
F_56 ( V_25 ) ;
F_57 ( V_20 ) ;
return V_102 ;
}
static int F_58 ( struct V_23 * V_24 )
{
struct V_19 * V_20 = V_24 -> V_20 ;
if ( V_24 -> V_131 ) {
return 0 ;
}
F_38 ( L_21 ) ;
F_49 ( V_24 ) ;
if ( ! V_20 )
return 0 ;
if ( V_20 -> V_25 )
F_59 ( V_20 -> V_25 ) ;
F_57 ( V_20 ) ;
V_24 -> V_20 = NULL ;
return 0 ;
}
static int T_5 F_60 ( void )
{
return F_61 ( & V_155 ) ;
}
static void T_6 F_62 ( void )
{
F_63 ( & V_155 ) ;
}
