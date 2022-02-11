static const char * F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 && V_4 -> V_6 ) {
if ( V_4 -> V_7 -> V_8 . V_9 & V_10 ) {
if ( ! strcmp ( V_4 -> V_5 , L_1 )
&& ! strcmp ( V_4 -> V_6 , L_2 ) )
return V_11 ;
if ( ! strcmp ( V_4 -> V_5 , L_3 )
&& ! strcmp ( V_4 -> V_6 , L_4 ) )
return V_12 ;
} else {
if ( ! strcmp ( V_4 -> V_5 , L_1 )
&& ! strcmp ( V_4 -> V_6 , L_2 ) )
return V_13 ;
}
}
F_3 ( & V_2 -> V_14 ,
L_5 ) ;
return V_13 ;
}
static void F_4 ( struct V_15 * V_14 , unsigned char * V_16 ,
unsigned int V_17 )
{
if ( V_17 == 1 ) {
if ( V_16 [ 0 ] != ( unsigned char ) 0xff && V_16 [ 0 ] != 0x00 )
F_5 ( V_14 , L_6 , V_16 [ 0 ] ) ;
} else if ( V_17 == 4 )
F_5 ( V_14 , L_7 , 4 , V_16 ) ;
else
F_5 ( V_14 , L_8 , V_17 , 6 , V_16 ) ;
}
static int F_6 ( struct V_18 * V_18 )
{
int V_19 = 0 ;
F_7 ( & V_18 -> V_20 ) ;
if ( V_18 -> V_21 ++ != 0 )
goto V_22;
V_18 -> V_23 -> V_14 = V_18 -> V_4 ;
if ( F_8 ( V_18 -> V_23 , V_24 ) ) {
F_9 ( & V_18 -> V_2 -> V_14 ,
L_9 , V_25 ) ;
V_19 = - V_26 ;
}
V_22: F_10 ( & V_18 -> V_20 ) ;
return V_19 ;
}
static void F_11 ( struct V_18 * V_18 )
{
F_7 ( & V_18 -> V_20 ) ;
if ( -- V_18 -> V_21 == 0 )
F_12 ( V_18 -> V_23 ) ;
F_10 ( & V_18 -> V_20 ) ;
}
static int F_13 ( struct V_27 * V_28 )
{
struct V_18 * V_18 = F_14 ( V_28 ) ;
return F_6 ( V_18 ) ;
}
static void F_15 ( struct V_27 * V_28 )
{
struct V_18 * V_18 = F_14 ( V_28 ) ;
F_11 ( V_18 ) ;
}
static int F_16 ( struct V_29 * V_30 )
{
struct V_18 * V_18 = V_30 -> V_31 ;
return F_6 ( V_18 ) ;
}
static void F_17 ( struct V_29 * V_30 )
{
struct V_18 * V_18 = V_30 -> V_31 ;
F_11 ( V_18 ) ;
}
static void F_18 ( struct V_32 * V_32 )
{
struct V_18 * V_18 = V_32 -> V_33 ;
if ( V_32 -> V_34 ) {
F_19 ( & V_18 -> V_2 -> V_14 , L_10 ,
V_25 , V_32 -> V_34 ) ;
return;
}
V_18 -> V_35 |= V_36 ;
F_20 () ;
F_21 ( & V_18 -> V_37 ) ;
}
static int F_22 ( struct V_18 * V_18 , T_1 V_38 ,
unsigned char * V_16 )
{
int V_39 = 0 ;
memcpy ( V_18 -> V_40 -> V_41 + 1 , V_16 , F_23 ( V_38 ) ) ;
( ( char * ) V_18 -> V_40 -> V_41 ) [ 0 ] = F_24 ( V_38 ) ;
V_18 -> V_40 -> V_42 = F_23 ( V_38 ) + 1 ;
V_18 -> V_40 -> V_14 = V_18 -> V_4 ;
V_18 -> V_35 = V_43 ;
V_39 = F_8 ( V_18 -> V_40 , V_44 ) ;
if ( V_39 ) {
F_19 ( & V_18 -> V_2 -> V_14 ,
L_11 , V_39 ) ;
return V_39 ;
}
F_25 ( V_18 -> V_37 ,
( ( V_18 -> V_40 -> V_34 != - V_45 ) ||
( V_18 -> V_35 & V_36 ) ) ,
V_46 ) ;
F_12 ( V_18 -> V_40 ) ;
return V_39 ;
}
static int F_26 ( struct V_18 * V_18 )
{
unsigned long V_47 = V_48 , V_49 ;
int V_50 ;
V_49 = F_27 ( 250 ) ;
if ( F_28 ( V_47 , V_18 -> V_51 + V_49 ) ) {
V_18 -> V_52 = V_47 ;
return 1 ;
}
for ( V_50 = 0 ; V_50 < F_29 ( V_53 ) - 1 ; V_50 ++ ) {
unsigned long V_54 = F_27 ( V_53 [ V_50 ] . V_55 ) ;
if ( F_30 ( V_47 , V_18 -> V_52 + V_54 ) )
return V_53 [ V_50 ] . V_56 ;
}
return V_53 [ V_50 ] . V_56 ;
}
static void F_31 ( struct V_32 * V_32 )
{
struct V_18 * V_18 = V_32 -> V_33 ;
unsigned char * V_16 = V_18 -> V_57 ;
struct V_27 * V_14 = V_18 -> V_58 ;
int V_59 = - 1 ;
int V_60 ;
unsigned char V_61 ;
T_2 V_62 = V_63 ;
int V_50 ;
if ( V_32 -> V_64 != 4 || V_16 [ 0 ] != 0x14 ||
V_16 [ 1 ] != ( unsigned char ) ( V_16 [ 2 ] + V_16 [ 3 ] + 0xD5 ) ||
( V_16 [ 3 ] & 0x0f ) != 0x00 ) {
F_4 ( & V_32 -> V_14 -> V_14 , V_16 , V_32 -> V_64 ) ;
return;
}
if ( V_16 [ 1 ] != ( ( V_16 [ 2 ] + V_16 [ 3 ] + 0xd5 ) & 0xff ) ) {
F_32 ( & V_18 -> V_2 -> V_14 ,
L_12 , 4 , V_16 ) ;
return;
}
V_60 = ( V_16 [ 3 ] >> 4 ) & 0x0f ;
if ( V_65 & ( 1 << ( V_60 + 1 ) ) ) {
F_32 ( & V_18 -> V_2 -> V_14 ,
L_13 ,
V_60 , V_16 [ 2 ] , V_65 ) ;
return;
}
V_61 = V_16 [ 2 ] & 0x7f ;
F_32 ( & V_18 -> V_2 -> V_14 ,
L_14 ,
V_60 , V_16 [ 2 ] , V_61 ) ;
if ( V_61 >= 0x70 ) {
V_62 = F_33 ( V_18 -> V_30 ,
V_61 & 0x78 ) ;
if ( V_62 == V_63 ) {
for ( V_50 = 0 ; V_66 [ V_50 ] . V_67 != V_68 ; V_50 ++ ) {
if ( V_61 == V_66 [ V_50 ] . V_16 ) {
V_59 = V_50 ;
break;
}
}
}
}
if ( V_59 >= 0 && V_66 [ V_59 ] . V_67 == V_69 ) {
F_34 ( V_14 , V_70 , V_66 [ V_59 ] . V_71 ,
! ( V_16 [ 2 ] & 1 ) ) ;
V_18 -> V_51 = V_48 ;
} else if ( V_59 < 0 || V_66 [ V_59 ] . V_67 == V_72 ) {
unsigned long V_47 = V_48 ;
if ( V_18 -> V_73 == V_16 [ 2 ] &&
F_30 ( V_47 , V_18 -> V_51 +
F_27 ( V_74 ) ) ) {
V_18 -> V_75 ++ ;
} else {
V_18 -> V_75 = 0 ;
V_18 -> V_76 = V_47 ;
}
V_18 -> V_51 = V_47 ;
if ( V_18 -> V_75 > 0 &&
( V_18 -> V_75 < 5 ||
F_30 ( V_47 , V_18 -> V_76 +
F_27 ( V_77 ) ) ) )
return;
if ( V_59 >= 0 ) {
F_34 ( V_14 , V_70 , V_66 [ V_59 ] . V_71 , 1 ) ;
F_34 ( V_14 , V_70 , V_66 [ V_59 ] . V_71 , 0 ) ;
} else {
int V_78 = 1 ;
if ( V_62 != V_63 ) {
V_78 = ( V_61 & 0x07 ) + 1 ;
V_61 &= 0x78 ;
}
while ( V_78 -- ) {
F_35 ( V_18 -> V_30 , V_79 ,
V_61 , V_16 [ 2 ] ) ;
F_36 ( V_18 -> V_30 ) ;
}
goto V_80;
}
} else if ( V_66 [ V_59 ] . V_67 == V_81 ) {
signed char V_82 = V_66 [ V_59 ] . V_71 >> 8 ;
signed char V_83 = V_66 [ V_59 ] . V_71 & 255 ;
int V_84 = F_26 ( V_18 ) ;
if ( V_82 )
F_37 ( V_14 , V_85 , V_82 * V_84 ) ;
if ( V_83 )
F_37 ( V_14 , V_86 , V_83 * V_84 ) ;
V_18 -> V_51 = V_48 ;
} else {
F_19 ( & V_18 -> V_2 -> V_14 , L_15 ,
V_66 [ V_59 ] . V_67 ) ;
return;
}
F_38 ( V_14 ) ;
V_80:
V_18 -> V_73 = V_16 [ 2 ] ;
}
static void F_39 ( struct V_32 * V_32 )
{
struct V_18 * V_18 = V_32 -> V_33 ;
int V_39 ;
switch ( V_32 -> V_34 ) {
case 0 :
F_31 ( V_32 ) ;
break;
case - V_87 :
case - V_88 :
case - V_89 :
F_19 ( & V_18 -> V_2 -> V_14 ,
L_16 ,
V_25 ) ;
return;
default:
F_19 ( & V_18 -> V_2 -> V_14 ,
L_17 ,
V_25 , V_32 -> V_34 ) ;
}
V_39 = F_8 ( V_32 , V_44 ) ;
if ( V_39 )
F_9 ( & V_18 -> V_2 -> V_14 ,
L_18 ,
V_25 , V_39 ) ;
}
static int F_40 ( struct V_3 * V_4 ,
struct V_18 * V_18 )
{
V_18 -> V_57 = F_41 ( V_4 , V_90 , V_44 ,
& V_18 -> V_91 ) ;
if ( ! V_18 -> V_57 )
return - 1 ;
V_18 -> V_92 = F_41 ( V_4 , V_90 , V_44 ,
& V_18 -> V_93 ) ;
if ( ! V_18 -> V_92 )
return - 1 ;
V_18 -> V_23 = F_42 ( 0 , V_24 ) ;
if ( ! V_18 -> V_23 )
return - 1 ;
V_18 -> V_40 = F_42 ( 0 , V_24 ) ;
if ( ! V_18 -> V_40 )
return - 1 ;
return 0 ;
}
static void F_43 ( struct V_18 * V_18 )
{
F_44 ( V_18 -> V_23 ) ;
F_44 ( V_18 -> V_40 ) ;
F_45 ( V_18 -> V_4 , V_90 ,
V_18 -> V_57 , V_18 -> V_91 ) ;
F_45 ( V_18 -> V_4 , V_90 ,
V_18 -> V_92 , V_18 -> V_93 ) ;
}
static void F_46 ( struct V_18 * V_18 )
{
struct V_27 * V_58 = V_18 -> V_58 ;
int V_50 ;
V_58 -> V_94 [ 0 ] = F_47 ( V_70 ) | F_47 ( V_95 ) ;
V_58 -> V_96 [ F_48 ( V_97 ) ] = F_47 ( V_98 ) |
F_47 ( V_99 ) | F_47 ( V_100 ) | F_47 ( V_101 ) ;
V_58 -> V_102 [ 0 ] = F_47 ( V_85 ) | F_47 ( V_86 ) ;
for ( V_50 = 0 ; V_66 [ V_50 ] . V_67 != V_68 ; V_50 ++ )
if ( V_66 [ V_50 ] . V_67 == V_69 ||
V_66 [ V_50 ] . V_67 == V_72 )
F_49 ( V_66 [ V_50 ] . V_71 , V_58 -> V_96 ) ;
F_50 ( V_58 , V_18 ) ;
V_58 -> V_103 = F_13 ;
V_58 -> V_104 = F_15 ;
V_58 -> V_105 = V_18 -> V_106 ;
V_58 -> V_107 = V_18 -> V_108 ;
F_51 ( V_18 -> V_4 , & V_58 -> V_109 ) ;
V_58 -> V_14 . V_110 = & V_18 -> V_2 -> V_14 ;
}
static void F_52 ( struct V_18 * V_18 )
{
struct V_29 * V_30 = V_18 -> V_30 ;
V_30 -> V_31 = V_18 ;
V_30 -> V_111 = V_112 ;
V_30 -> V_113 = L_19 ;
V_30 -> V_103 = F_16 ;
V_30 -> V_104 = F_17 ;
V_30 -> V_114 = V_18 -> V_115 ;
V_30 -> V_116 = V_18 -> V_117 ;
F_51 ( V_18 -> V_4 , & V_30 -> V_118 ) ;
V_30 -> V_14 . V_110 = & V_18 -> V_2 -> V_14 ;
}
static int F_53 ( struct V_18 * V_18 )
{
struct V_3 * V_4 = V_18 -> V_4 ;
int V_119 , V_120 ;
F_54 ( & V_18 -> V_37 ) ;
V_119 = F_55 ( V_4 , V_18 -> V_121 -> V_122 ) ;
V_120 = F_56 ( V_4 , V_119 , F_57 ( V_119 ) ) ;
V_120 = ( V_120 > V_90 ) ? V_90 : V_120 ;
F_58 ( V_18 -> V_23 , V_4 , V_119 , V_18 -> V_57 ,
V_120 , F_39 , V_18 ,
V_18 -> V_121 -> V_123 ) ;
V_18 -> V_23 -> V_124 = V_18 -> V_91 ;
V_18 -> V_23 -> V_125 |= V_126 ;
V_119 = F_59 ( V_4 , V_18 -> V_127 -> V_122 ) ;
V_120 = F_56 ( V_4 , V_119 , F_57 ( V_119 ) ) ;
V_120 = ( V_120 > V_90 ) ? V_90 : V_120 ;
F_58 ( V_18 -> V_40 , V_4 , V_119 , V_18 -> V_92 ,
V_120 , F_18 , V_18 ,
V_18 -> V_127 -> V_123 ) ;
V_18 -> V_40 -> V_124 = V_18 -> V_93 ;
V_18 -> V_40 -> V_125 |= V_126 ;
if ( ( F_22 ( V_18 , 0x8004 , V_128 ) ) ||
( F_22 ( V_18 , 0x8007 , V_129 ) ) ) {
F_9 ( & V_18 -> V_2 -> V_14 ,
L_20 ) ;
return - V_26 ;
}
return 0 ;
}
static int F_60 ( struct V_1 * V_2 ,
const struct V_130 * V_109 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_131 * V_132 = V_2 -> V_133 ;
struct V_134 * V_121 , * V_127 ;
struct V_135 * type = (struct V_135 * ) V_109 -> V_136 ;
struct V_18 * V_18 ;
struct V_27 * V_27 ;
struct V_29 * V_29 ;
int V_19 = - V_137 ;
if ( V_132 -> V_8 . V_138 != 2 ) {
V_19 ( L_21 , V_25 ) ;
return - V_139 ;
}
V_121 = & V_132 -> V_140 [ 0 ] . V_8 ;
V_127 = & V_132 -> V_140 [ 1 ] . V_8 ;
if ( ! F_61 ( V_121 ) ) {
V_19 ( L_22 , V_25 ) ;
return - V_139 ;
}
if ( F_62 ( V_121 -> V_141 ) == 0 ) {
V_19 ( L_23 , V_25 ) ;
return - V_139 ;
}
V_18 = F_63 ( sizeof ( struct V_18 ) , V_24 ) ;
V_29 = F_64 ( V_142 ) ;
if ( ! V_18 || ! V_29 )
goto V_143;
if ( F_40 ( V_4 , V_18 ) )
goto V_144;
V_18 -> V_121 = V_121 ;
V_18 -> V_127 = V_127 ;
V_18 -> V_4 = V_4 ;
V_18 -> V_30 = V_29 ;
V_18 -> V_2 = V_2 ;
F_65 ( V_4 , V_18 -> V_117 , sizeof( V_18 -> V_117 ) ) ;
F_66 ( V_18 -> V_108 , V_18 -> V_117 ,
sizeof( V_18 -> V_108 ) ) ;
F_67 ( V_18 -> V_117 , L_24 , sizeof( V_18 -> V_117 ) ) ;
F_67 ( V_18 -> V_108 , L_25 , sizeof( V_18 -> V_108 ) ) ;
snprintf ( V_18 -> V_115 , sizeof( V_18 -> V_115 ) , L_26 ,
V_4 -> V_5 ? : L_27 ,
V_4 -> V_5 && V_4 -> V_6 ? L_28 : L_27 ,
V_4 -> V_6 ? : L_27 ) ;
if ( ! strlen ( V_18 -> V_115 ) )
snprintf ( V_18 -> V_115 , sizeof( V_18 -> V_115 ) ,
V_145 L_29 ,
F_62 ( V_18 -> V_4 -> V_146 . V_147 ) ,
F_62 ( V_18 -> V_4 -> V_146 . V_148 ) ) ;
snprintf ( V_18 -> V_106 , sizeof( V_18 -> V_106 ) ,
L_30 , V_18 -> V_115 ) ;
V_29 -> V_149 = V_150 ;
if ( type ) {
if ( type -> V_151 )
V_29 -> V_149 = type -> V_151 ;
else if ( type -> V_152 )
V_29 -> V_149 = type -> V_152 ( V_2 ) ;
}
F_52 ( V_18 ) ;
F_68 ( & V_18 -> V_20 ) ;
V_19 = F_53 ( V_18 ) ;
if ( V_19 )
goto V_153;
V_19 = F_69 ( V_18 -> V_30 ) ;
if ( V_19 )
goto V_153;
V_18 -> V_30 -> V_27 -> V_154 [ V_155 ] = V_77 ;
if ( V_156 ) {
V_27 = F_70 () ;
if ( ! V_27 ) {
V_19 = - V_137 ;
goto V_157;
}
V_18 -> V_58 = V_27 ;
F_46 ( V_18 ) ;
V_19 = F_71 ( V_27 ) ;
if ( V_19 )
goto V_158;
}
F_72 ( V_2 , V_18 ) ;
return 0 ;
V_158:
F_73 ( V_27 ) ;
V_157:
F_74 ( V_29 ) ;
V_29 = NULL ;
V_153:
F_12 ( V_18 -> V_23 ) ;
F_12 ( V_18 -> V_40 ) ;
V_144:
F_43 ( V_18 ) ;
V_143:
F_75 ( V_29 ) ;
F_76 ( V_18 ) ;
return V_19 ;
}
static void F_77 ( struct V_1 * V_2 )
{
struct V_18 * V_18 ;
V_18 = F_78 ( V_2 ) ;
F_72 ( V_2 , NULL ) ;
if ( ! V_18 ) {
F_5 ( & V_2 -> V_14 , L_31 , V_25 ) ;
return;
}
F_12 ( V_18 -> V_23 ) ;
F_12 ( V_18 -> V_40 ) ;
if ( V_18 -> V_58 )
F_79 ( V_18 -> V_58 ) ;
F_74 ( V_18 -> V_30 ) ;
F_43 ( V_18 ) ;
F_76 ( V_18 ) ;
}
