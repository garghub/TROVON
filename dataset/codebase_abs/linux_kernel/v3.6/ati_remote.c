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
F_5 ( V_14 , L_7 ,
V_16 [ 0 ] , V_16 [ 1 ] , V_16 [ 2 ] , V_16 [ 3 ] ) ;
else
F_5 ( V_14 ,
L_8 ,
V_17 , V_16 [ 0 ] , V_16 [ 1 ] , V_16 [ 2 ] , V_16 [ 3 ] , V_16 [ 4 ] ,
V_16 [ 5 ] ) ;
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
static const char V_47 [] = { 1 , 2 , 4 , 6 , 9 , 13 , 20 } ;
unsigned long V_48 = V_49 ;
int V_50 ;
if ( F_27 ( V_48 , V_18 -> V_51 + F_28 ( 250 ) ) ) {
V_50 = 1 ;
V_18 -> V_52 = V_48 ;
}
else if ( F_29 ( V_48 , V_18 -> V_52 + F_28 ( 125 ) ) )
V_50 = V_47 [ 0 ] ;
else if ( F_29 ( V_48 , V_18 -> V_52 + F_28 ( 250 ) ) )
V_50 = V_47 [ 1 ] ;
else if ( F_29 ( V_48 , V_18 -> V_52 + F_28 ( 500 ) ) )
V_50 = V_47 [ 2 ] ;
else if ( F_29 ( V_48 , V_18 -> V_52 + F_28 ( 1000 ) ) )
V_50 = V_47 [ 3 ] ;
else if ( F_29 ( V_48 , V_18 -> V_52 + F_28 ( 1500 ) ) )
V_50 = V_47 [ 4 ] ;
else if ( F_29 ( V_48 , V_18 -> V_52 + F_28 ( 2000 ) ) )
V_50 = V_47 [ 5 ] ;
else
V_50 = V_47 [ 6 ] ;
return V_50 ;
}
static void F_30 ( struct V_32 * V_32 )
{
struct V_18 * V_18 = V_32 -> V_33 ;
unsigned char * V_16 = V_18 -> V_53 ;
struct V_27 * V_14 = V_18 -> V_54 ;
int V_55 = - 1 ;
int V_50 ;
int V_56 ;
unsigned char V_57 ;
T_2 V_58 = V_59 ;
int V_60 ;
if ( ( V_32 -> V_61 != 4 ) || ( V_16 [ 0 ] != 0x14 ) ||
( ( V_16 [ 3 ] & 0x0f ) != 0x00 ) ) {
F_4 ( & V_32 -> V_14 -> V_14 , V_16 , V_32 -> V_61 ) ;
return;
}
if ( V_16 [ 1 ] != ( ( V_16 [ 2 ] + V_16 [ 3 ] + 0xd5 ) & 0xff ) ) {
F_31 ( & V_18 -> V_2 -> V_14 ,
L_12 ,
V_16 [ 0 ] , V_16 [ 1 ] , V_16 [ 2 ] , V_16 [ 3 ] ) ;
return;
}
V_56 = ( V_16 [ 3 ] >> 4 ) & 0x0f ;
if ( V_62 & ( 1 << ( V_56 + 1 ) ) ) {
F_31 ( & V_18 -> V_2 -> V_14 ,
L_13
L_14 ,
V_56 , V_16 [ 1 ] , V_16 [ 2 ] , V_62 ) ;
return;
}
V_57 = V_16 [ 2 ] & 0x7f ;
F_31 ( & V_18 -> V_2 -> V_14 ,
L_15 ,
V_56 , V_16 [ 2 ] , V_57 ) ;
if ( V_57 >= 0x70 ) {
V_58 = F_32 ( V_18 -> V_30 ,
V_57 & 0x78 ) ;
if ( V_58 == V_59 ) {
for ( V_60 = 0 ; V_63 [ V_60 ] . V_64 != V_65 ; V_60 ++ ) {
if ( V_57 == V_63 [ V_60 ] . V_16 ) {
V_55 = V_60 ;
break;
}
}
}
}
if ( V_55 >= 0 && V_63 [ V_55 ] . V_64 == V_66 ) {
F_33 ( V_14 , V_63 [ V_55 ] . type ,
V_63 [ V_55 ] . V_67 ,
V_63 [ V_55 ] . V_68 ) ;
F_34 ( V_14 ) ;
V_18 -> V_51 = V_49 ;
return;
}
if ( V_55 < 0 || V_63 [ V_55 ] . V_64 == V_69 ) {
unsigned long V_48 = V_49 ;
if ( V_18 -> V_70 == V_16 [ 2 ] &&
F_29 ( V_48 , V_18 -> V_51 +
F_28 ( V_71 ) ) ) {
V_18 -> V_72 ++ ;
} else {
V_18 -> V_72 = 0 ;
V_18 -> V_73 = V_48 ;
}
V_18 -> V_70 = V_16 [ 2 ] ;
V_18 -> V_51 = V_48 ;
if ( V_18 -> V_72 > 0 &&
( V_18 -> V_72 < 5 ||
F_29 ( V_48 , V_18 -> V_73 +
F_28 ( V_74 ) ) ) )
return;
if ( V_55 < 0 ) {
int V_75 = 1 ;
if ( V_58 != V_59 ) {
V_75 = ( V_57 & 0x07 ) + 1 ;
V_57 &= 0x78 ;
}
while ( V_75 -- ) {
F_35 ( V_18 -> V_30 , V_57 ,
V_16 [ 2 ] ) ;
F_36 ( V_18 -> V_30 ) ;
}
return;
}
F_33 ( V_14 , V_63 [ V_55 ] . type ,
V_63 [ V_55 ] . V_67 , 1 ) ;
F_34 ( V_14 ) ;
F_33 ( V_14 , V_63 [ V_55 ] . type ,
V_63 [ V_55 ] . V_67 , 0 ) ;
F_34 ( V_14 ) ;
} else {
V_50 = F_26 ( V_18 ) ;
switch ( V_63 [ V_55 ] . V_64 ) {
case V_76 :
F_33 ( V_14 , V_63 [ V_55 ] . type ,
V_63 [ V_55 ] . V_67 ,
V_63 [ V_55 ] . V_68 * V_50 ) ;
break;
case V_77 :
F_37 ( V_14 , V_78 , - V_50 ) ;
F_37 ( V_14 , V_79 , - V_50 ) ;
break;
case V_80 :
F_37 ( V_14 , V_78 , V_50 ) ;
F_37 ( V_14 , V_79 , - V_50 ) ;
break;
case V_81 :
F_37 ( V_14 , V_78 , - V_50 ) ;
F_37 ( V_14 , V_79 , V_50 ) ;
break;
case V_82 :
F_37 ( V_14 , V_78 , V_50 ) ;
F_37 ( V_14 , V_79 , V_50 ) ;
break;
default:
F_19 ( & V_18 -> V_2 -> V_14 ,
L_16 ,
V_63 [ V_55 ] . V_64 ) ;
}
F_34 ( V_14 ) ;
V_18 -> V_51 = V_49 ;
V_18 -> V_70 = V_16 [ 2 ] ;
}
}
static void F_38 ( struct V_32 * V_32 )
{
struct V_18 * V_18 = V_32 -> V_33 ;
int V_39 ;
switch ( V_32 -> V_34 ) {
case 0 :
F_30 ( V_32 ) ;
break;
case - V_83 :
case - V_84 :
case - V_85 :
F_19 ( & V_18 -> V_2 -> V_14 ,
L_17 ,
V_25 ) ;
return;
default:
F_19 ( & V_18 -> V_2 -> V_14 ,
L_18 ,
V_25 , V_32 -> V_34 ) ;
}
V_39 = F_8 ( V_32 , V_44 ) ;
if ( V_39 )
F_9 ( & V_18 -> V_2 -> V_14 ,
L_19 ,
V_25 , V_39 ) ;
}
static int F_39 ( struct V_3 * V_4 ,
struct V_18 * V_18 )
{
V_18 -> V_53 = F_40 ( V_4 , V_86 , V_44 ,
& V_18 -> V_87 ) ;
if ( ! V_18 -> V_53 )
return - 1 ;
V_18 -> V_88 = F_40 ( V_4 , V_86 , V_44 ,
& V_18 -> V_89 ) ;
if ( ! V_18 -> V_88 )
return - 1 ;
V_18 -> V_23 = F_41 ( 0 , V_24 ) ;
if ( ! V_18 -> V_23 )
return - 1 ;
V_18 -> V_40 = F_41 ( 0 , V_24 ) ;
if ( ! V_18 -> V_40 )
return - 1 ;
return 0 ;
}
static void F_42 ( struct V_18 * V_18 )
{
F_43 ( V_18 -> V_23 ) ;
F_43 ( V_18 -> V_40 ) ;
F_44 ( V_18 -> V_4 , V_86 ,
V_18 -> V_53 , V_18 -> V_87 ) ;
F_44 ( V_18 -> V_4 , V_86 ,
V_18 -> V_88 , V_18 -> V_89 ) ;
}
static void F_45 ( struct V_18 * V_18 )
{
struct V_27 * V_54 = V_18 -> V_54 ;
int V_60 ;
V_54 -> V_90 [ 0 ] = F_46 ( V_91 ) | F_46 ( V_92 ) ;
V_54 -> V_93 [ F_47 ( V_94 ) ] = F_46 ( V_95 ) |
F_46 ( V_96 ) | F_46 ( V_97 ) | F_46 ( V_98 ) ;
V_54 -> V_99 [ 0 ] = F_46 ( V_78 ) | F_46 ( V_79 ) ;
for ( V_60 = 0 ; V_63 [ V_60 ] . V_64 != V_65 ; V_60 ++ )
if ( V_63 [ V_60 ] . type == V_91 )
F_48 ( V_63 [ V_60 ] . V_67 , V_54 -> V_93 ) ;
F_49 ( V_54 , V_18 ) ;
V_54 -> V_100 = F_13 ;
V_54 -> V_101 = F_15 ;
V_54 -> V_102 = V_18 -> V_103 ;
V_54 -> V_104 = V_18 -> V_105 ;
F_50 ( V_18 -> V_4 , & V_54 -> V_106 ) ;
V_54 -> V_14 . V_107 = & V_18 -> V_2 -> V_14 ;
}
static void F_51 ( struct V_18 * V_18 )
{
struct V_29 * V_30 = V_18 -> V_30 ;
V_30 -> V_31 = V_18 ;
V_30 -> V_108 = V_109 ;
V_30 -> V_110 = V_111 ;
V_30 -> V_112 = L_20 ;
V_30 -> V_100 = F_16 ;
V_30 -> V_101 = F_17 ;
V_30 -> V_113 = V_18 -> V_114 ;
V_30 -> V_115 = V_18 -> V_116 ;
F_50 ( V_18 -> V_4 , & V_30 -> V_117 ) ;
V_30 -> V_14 . V_107 = & V_18 -> V_2 -> V_14 ;
}
static int F_52 ( struct V_18 * V_18 )
{
struct V_3 * V_4 = V_18 -> V_4 ;
int V_118 , V_119 ;
F_53 ( & V_18 -> V_37 ) ;
V_118 = F_54 ( V_4 , V_18 -> V_120 -> V_121 ) ;
V_119 = F_55 ( V_4 , V_118 , F_56 ( V_118 ) ) ;
V_119 = ( V_119 > V_86 ) ? V_86 : V_119 ;
F_57 ( V_18 -> V_23 , V_4 , V_118 , V_18 -> V_53 ,
V_119 , F_38 , V_18 ,
V_18 -> V_120 -> V_122 ) ;
V_18 -> V_23 -> V_123 = V_18 -> V_87 ;
V_18 -> V_23 -> V_124 |= V_125 ;
V_118 = F_58 ( V_4 , V_18 -> V_126 -> V_121 ) ;
V_119 = F_55 ( V_4 , V_118 , F_56 ( V_118 ) ) ;
V_119 = ( V_119 > V_86 ) ? V_86 : V_119 ;
F_57 ( V_18 -> V_40 , V_4 , V_118 , V_18 -> V_88 ,
V_119 , F_18 , V_18 ,
V_18 -> V_126 -> V_122 ) ;
V_18 -> V_40 -> V_123 = V_18 -> V_89 ;
V_18 -> V_40 -> V_124 |= V_125 ;
if ( ( F_22 ( V_18 , 0x8004 , V_127 ) ) ||
( F_22 ( V_18 , 0x8007 , V_128 ) ) ) {
F_9 ( & V_18 -> V_2 -> V_14 ,
L_21 ) ;
return - V_26 ;
}
return 0 ;
}
static int F_59 ( struct V_1 * V_2 ,
const struct V_129 * V_106 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_130 * V_131 = V_2 -> V_132 ;
struct V_133 * V_120 , * V_126 ;
struct V_134 * type = (struct V_134 * ) V_106 -> V_135 ;
struct V_18 * V_18 ;
struct V_27 * V_27 ;
struct V_29 * V_29 ;
int V_19 = - V_136 ;
if ( V_131 -> V_8 . V_137 != 2 ) {
V_19 ( L_22 , V_25 ) ;
return - V_138 ;
}
V_120 = & V_131 -> V_139 [ 0 ] . V_8 ;
V_126 = & V_131 -> V_139 [ 1 ] . V_8 ;
if ( ! F_60 ( V_120 ) ) {
V_19 ( L_23 , V_25 ) ;
return - V_138 ;
}
if ( F_61 ( V_120 -> V_140 ) == 0 ) {
V_19 ( L_24 , V_25 ) ;
return - V_138 ;
}
V_18 = F_62 ( sizeof ( struct V_18 ) , V_24 ) ;
V_29 = F_63 () ;
if ( ! V_18 || ! V_29 )
goto V_141;
if ( F_39 ( V_4 , V_18 ) )
goto V_142;
V_18 -> V_120 = V_120 ;
V_18 -> V_126 = V_126 ;
V_18 -> V_4 = V_4 ;
V_18 -> V_30 = V_29 ;
V_18 -> V_2 = V_2 ;
F_64 ( V_4 , V_18 -> V_116 , sizeof( V_18 -> V_116 ) ) ;
F_65 ( V_18 -> V_105 , V_18 -> V_116 ,
sizeof( V_18 -> V_105 ) ) ;
F_66 ( V_18 -> V_116 , L_25 , sizeof( V_18 -> V_116 ) ) ;
F_66 ( V_18 -> V_105 , L_26 , sizeof( V_18 -> V_105 ) ) ;
if ( V_4 -> V_5 )
F_65 ( V_18 -> V_114 , V_4 -> V_5 ,
sizeof( V_18 -> V_114 ) ) ;
if ( V_4 -> V_6 )
snprintf ( V_18 -> V_114 , sizeof( V_18 -> V_114 ) ,
L_27 , V_18 -> V_114 , V_4 -> V_6 ) ;
if ( ! strlen ( V_18 -> V_114 ) )
snprintf ( V_18 -> V_114 , sizeof( V_18 -> V_114 ) ,
V_143 L_28 ,
F_61 ( V_18 -> V_4 -> V_144 . V_145 ) ,
F_61 ( V_18 -> V_4 -> V_144 . V_146 ) ) ;
snprintf ( V_18 -> V_103 , sizeof( V_18 -> V_103 ) ,
L_29 , V_18 -> V_114 ) ;
V_29 -> V_147 = V_148 ;
if ( type ) {
if ( type -> V_149 )
V_29 -> V_147 = type -> V_149 ;
else if ( type -> V_150 )
V_29 -> V_147 = type -> V_150 ( V_2 ) ;
}
F_51 ( V_18 ) ;
F_67 ( & V_18 -> V_20 ) ;
V_19 = F_52 ( V_18 ) ;
if ( V_19 )
goto V_151;
V_19 = F_68 ( V_18 -> V_30 ) ;
if ( V_19 )
goto V_151;
V_18 -> V_30 -> V_27 -> V_152 [ V_153 ] = V_74 ;
if ( V_154 ) {
V_27 = F_69 () ;
if ( ! V_27 )
goto V_155;
V_18 -> V_54 = V_27 ;
F_45 ( V_18 ) ;
V_19 = F_70 ( V_27 ) ;
if ( V_19 )
goto V_156;
}
F_71 ( V_2 , V_18 ) ;
return 0 ;
V_156: F_72 ( V_27 ) ;
V_155: F_73 ( V_29 ) ;
V_29 = NULL ;
V_151: F_12 ( V_18 -> V_23 ) ;
F_12 ( V_18 -> V_40 ) ;
V_142: F_42 ( V_18 ) ;
V_141: F_74 ( V_29 ) ;
F_75 ( V_18 ) ;
return V_19 ;
}
static void F_76 ( struct V_1 * V_2 )
{
struct V_18 * V_18 ;
V_18 = F_77 ( V_2 ) ;
F_71 ( V_2 , NULL ) ;
if ( ! V_18 ) {
F_5 ( & V_2 -> V_14 , L_30 , V_25 ) ;
return;
}
F_12 ( V_18 -> V_23 ) ;
F_12 ( V_18 -> V_40 ) ;
if ( V_18 -> V_54 )
F_78 ( V_18 -> V_54 ) ;
F_73 ( V_18 -> V_30 ) ;
F_42 ( V_18 ) ;
F_75 ( V_18 ) ;
}
