static inline T_1 F_1 ( void T_2 * V_1 )
{
return V_2 ? F_2 ( V_1 ) : F_3 ( V_1 ) ;
}
static inline void F_4 ( void T_2 * V_1 , T_1 V_3 )
{
if ( V_2 )
F_5 ( V_3 , V_1 ) ;
else
F_6 ( V_3 , V_1 ) ;
}
static T_3 F_7 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
char * V_8 )
{
struct V_9 * V_10 = F_8 ( V_5 ) ;
struct V_11 * V_12 = V_10 -> V_13 ;
return sprintf ( V_8 , L_1 ,
F_1 ( V_12 -> V_14 + V_15 ) ) ;
}
static T_3 F_9 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
char * V_8 )
{
struct V_9 * V_10 = F_8 ( V_5 ) ;
struct V_11 * V_12 = V_10 -> V_13 ;
return sprintf ( V_8 , L_1 ,
F_1 ( V_12 -> V_14 + V_16 ) ) ;
}
static T_3 F_10 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
char * V_8 )
{
struct V_9 * V_10 = F_8 ( V_5 ) ;
struct V_11 * V_12 = V_10 -> V_13 ;
return sprintf ( V_8 , L_1 ,
F_1 ( V_12 -> V_14 + V_17 ) ) ;
}
static T_3 F_11 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
const char * V_8 , T_4 V_18 )
{
struct V_9 * V_10 = F_8 ( V_5 ) ;
struct V_11 * V_12 = V_10 -> V_13 ;
unsigned long V_19 ;
int V_20 ;
if ( isdigit ( * V_8 ) ) {
V_20 = F_12 ( V_8 , 0 , & V_19 ) ;
if ( V_20 )
return V_20 ;
F_4 ( V_12 -> V_14 + V_15 , V_19 ) ;
return V_18 ;
}
return 0 ;
}
static T_3 F_13 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
const char * V_8 , T_4 V_18 )
{
struct V_9 * V_10 = F_8 ( V_5 ) ;
struct V_11 * V_12 = V_10 -> V_13 ;
unsigned long V_19 ;
int V_20 ;
if ( isdigit ( * V_8 ) ) {
V_20 = F_12 ( V_8 , 0 , & V_19 ) ;
if ( V_20 )
return V_20 ;
F_4 ( V_12 -> V_14 + V_16 , V_19 ) ;
return V_18 ;
}
return 0 ;
}
static T_3 F_14 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
const char * V_8 , T_4 V_18 )
{
struct V_9 * V_10 = F_8 ( V_5 ) ;
struct V_11 * V_12 = V_10 -> V_13 ;
unsigned long V_19 ;
int V_20 ;
if ( isdigit ( * V_8 ) ) {
V_20 = F_12 ( V_8 , 0 , & V_19 ) ;
if ( V_20 )
return V_20 ;
F_4 ( V_12 -> V_14 + V_17 , V_19 ) ;
return V_18 ;
}
return 0 ;
}
static T_5 F_15 ( T_1 V_21 , T_1 V_22 )
{
T_1 V_23 ;
T_1 V_24 ;
int V_25 ;
T_5 V_26 = 0 ;
int V_27 ;
int V_28 ;
for ( V_27 = 0 ; V_27 < 8 ; V_27 ++ ) {
V_24 = V_29 [ V_27 * 2 ] ;
V_23 = V_29 [ V_27 * 2 + 1 ] ;
V_25 = 0 ;
for ( V_28 = 0 ; V_28 < 32 ; V_28 ++ ) {
if ( ( V_24 >> V_28 ) & 1 )
V_25 ^= ( V_21 >> V_28 ) & 1 ;
if ( ( V_23 >> V_28 ) & 1 )
V_25 ^= ( V_22 >> V_28 ) & 1 ;
}
V_26 |= V_25 << V_27 ;
}
return V_26 ;
}
static T_5 F_16 ( unsigned int V_30 ) {
int V_27 ;
T_5 V_31 = 0 ;
for ( V_27 = V_30 < 32 ; V_27 < 16 ; V_27 += 2 )
V_31 |= ( ( V_29 [ V_27 ] >> ( V_30 % 32 ) ) & 1 ) << ( V_27 / 2 ) ;
return V_31 ;
}
static void F_17 ( T_1 V_32 , T_1 V_33 , T_1 V_34 ,
int * V_35 , int * V_36 )
{
int V_27 ;
T_5 V_31 ;
* V_35 = - 1 ;
* V_36 = - 1 ;
V_31 = F_15 ( V_32 , V_33 ) ^ V_34 ;
for ( V_27 = 0 ; V_27 < 64 ; V_27 ++ ) {
if ( V_31 == F_16 ( V_27 ) ) {
* V_35 = V_27 ;
return;
}
}
for ( V_27 = 0 ; V_27 < 8 ; V_27 ++ ) {
if ( ( V_31 >> V_27 ) & 0x1 ) {
* V_36 = V_27 ;
return;
}
}
}
static void F_18 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_37 * V_38 ;
T_1 V_39 ;
T_1 V_40 ;
T_1 V_31 ;
T_6 V_41 ;
T_1 V_42 ;
int V_43 ;
T_1 V_32 ;
T_1 V_33 ;
int V_35 ;
int V_36 ;
V_40 = F_1 ( V_12 -> V_14 + V_44 ) ;
if ( ! V_40 )
return;
F_19 ( V_10 , V_45 , L_2 ,
V_40 ) ;
if ( ! ( V_40 & ( V_46 | V_47 ) ) ) {
F_4 ( V_12 -> V_14 + V_44 , V_40 ) ;
return;
}
V_31 = F_1 ( V_12 -> V_14 + V_48 ) ;
V_39 = ( F_1 ( V_12 -> V_14 + V_49 ) &
V_50 ) ? 32 : 64 ;
if ( V_39 == 64 )
V_31 &= 0xff ;
else
V_31 &= 0xffff ;
V_41 = F_20 (
F_1 ( V_12 -> V_14 + V_51 ) ,
F_1 ( V_12 -> V_14 + V_52 ) ) ;
V_42 = V_41 >> V_53 ;
for ( V_43 = 0 ; V_43 < V_10 -> V_54 ; V_43 ++ ) {
V_38 = V_10 -> V_55 [ V_43 ] ;
if ( ( V_42 >= V_38 -> V_56 ) && ( V_42 <= V_38 -> V_57 ) )
break;
}
V_32 = F_1 ( V_12 -> V_14 + V_58 ) ;
V_33 = F_1 ( V_12 -> V_14 + V_59 ) ;
if ( ( V_40 & V_46 ) && ( V_39 == 64 ) ) {
F_17 ( V_32 , V_33 , V_31 ,
& V_35 , & V_36 ) ;
if ( V_35 != - 1 )
F_19 ( V_10 , V_45 ,
L_3 , V_35 ) ;
if ( V_36 != - 1 )
F_19 ( V_10 , V_45 ,
L_4 , V_36 ) ;
F_19 ( V_10 , V_45 ,
L_5 ,
V_32 ^ ( 1 << ( V_35 - 32 ) ) ,
V_33 ^ ( 1 << V_35 ) ,
V_31 ^ ( 1 << V_36 ) ) ;
}
F_19 ( V_10 , V_45 ,
L_6 ,
V_32 , V_33 , V_31 ) ;
F_19 ( V_10 , V_45 , L_7 , V_41 ) ;
F_19 ( V_10 , V_45 , L_8 , V_42 ) ;
if ( V_43 == V_10 -> V_54 )
F_19 ( V_10 , V_45 , L_9 ) ;
if ( V_40 & V_46 )
F_21 ( V_60 , V_10 , 1 ,
V_42 , V_41 & ~ V_61 , V_31 ,
V_43 , 0 , - 1 ,
V_10 -> V_62 , L_10 ) ;
if ( V_40 & V_47 )
F_21 ( V_63 , V_10 , 1 ,
V_42 , V_41 & ~ V_61 , V_31 ,
V_43 , 0 , - 1 ,
V_10 -> V_62 , L_10 ) ;
F_4 ( V_12 -> V_14 + V_44 , V_40 ) ;
}
static T_7 F_22 ( int V_64 , void * V_65 )
{
struct V_9 * V_10 = V_65 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_40 ;
V_40 = F_1 ( V_12 -> V_14 + V_44 ) ;
if ( ! V_40 )
return V_66 ;
F_18 ( V_10 ) ;
return V_67 ;
}
static void F_23 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_37 * V_38 ;
struct V_68 * V_69 ;
T_1 V_70 ;
T_1 V_71 ;
enum V_72 V_73 ;
T_1 V_74 ;
int V_75 ;
V_70 = F_1 ( V_12 -> V_14 + V_49 ) ;
V_71 = V_70 & V_76 ;
if ( V_70 & V_77 ) {
switch ( V_71 ) {
case 0x02000000 :
V_73 = V_78 ;
break;
case 0x03000000 :
V_73 = V_79 ;
break;
case 0x07000000 :
V_73 = V_80 ;
break;
case 0x05000000 :
V_73 = V_81 ;
break;
default:
V_73 = V_82 ;
break;
}
} else {
switch ( V_71 ) {
case 0x02000000 :
V_73 = V_83 ;
break;
case 0x03000000 :
V_73 = V_84 ;
break;
case 0x07000000 :
V_73 = V_85 ;
break;
case 0x05000000 :
V_73 = V_86 ;
break;
default:
V_73 = V_82 ;
break;
}
}
for ( V_75 = 0 ; V_75 < V_10 -> V_54 ; V_75 ++ ) {
T_1 V_87 ;
T_1 V_88 ;
V_38 = V_10 -> V_55 [ V_75 ] ;
V_69 = V_38 -> V_89 [ 0 ] -> V_69 ;
V_74 = F_1 ( V_12 -> V_14 + V_90 +
( V_75 * V_91 ) ) ;
V_87 = ( V_74 & 0xffff0000 ) >> 16 ;
V_88 = ( V_74 & 0x0000ffff ) ;
if ( V_87 == V_88 )
continue;
V_87 <<= ( 24 - V_53 ) ;
V_88 <<= ( 24 - V_53 ) ;
V_88 |= ( 1 << ( 24 - V_53 ) ) - 1 ;
V_38 -> V_56 = V_87 ;
V_38 -> V_57 = V_88 ;
V_69 -> V_92 = V_88 + 1 - V_87 ;
V_69 -> V_93 = 8 ;
V_69 -> V_73 = V_73 ;
V_69 -> V_94 = V_95 ;
if ( V_70 & V_96 )
V_69 -> V_94 = V_97 ;
V_69 -> V_98 = V_99 ;
}
}
int F_24 ( struct V_100 * V_101 )
{
struct V_9 * V_10 ;
struct V_102 V_103 [ 2 ] ;
struct V_11 * V_12 ;
struct V_104 V_105 ;
T_1 V_70 ;
int V_106 ;
if ( ! F_25 ( & V_101 -> V_5 , F_24 , V_107 ) )
return - V_108 ;
V_103 [ 0 ] . type = V_109 ;
V_103 [ 0 ] . V_110 = 4 ;
V_103 [ 0 ] . V_111 = true ;
V_103 [ 1 ] . type = V_112 ;
V_103 [ 1 ] . V_110 = 1 ;
V_103 [ 1 ] . V_111 = false ;
V_10 = F_26 ( V_113 , F_27 ( V_103 ) , V_103 ,
sizeof( * V_12 ) ) ;
if ( ! V_10 ) {
F_28 ( & V_101 -> V_5 , F_24 ) ;
return - V_108 ;
}
V_12 = V_10 -> V_13 ;
V_12 -> V_114 = L_11 ;
V_10 -> V_115 = & V_101 -> V_5 ;
V_12 -> V_116 = V_113 ++ ;
F_29 ( V_10 -> V_115 , V_10 ) ;
V_10 -> V_62 = V_12 -> V_114 ;
V_10 -> V_117 = V_12 -> V_114 ;
V_2 = F_30 ( V_101 -> V_5 . V_118 , L_12 ) ;
V_106 = F_31 ( V_101 -> V_5 . V_118 , 0 , & V_105 ) ;
if ( V_106 ) {
F_32 ( L_13 ,
V_119 ) ;
goto V_120;
}
if ( ! F_33 ( & V_101 -> V_5 , V_105 . V_87 , F_34 ( & V_105 ) ,
V_12 -> V_114 ) ) {
F_32 ( L_14 ,
V_119 ) ;
V_106 = - V_121 ;
goto V_120;
}
V_12 -> V_14 = F_35 ( & V_101 -> V_5 , V_105 . V_87 , F_34 ( & V_105 ) ) ;
if ( ! V_12 -> V_14 ) {
F_32 ( L_15 , V_119 ) ;
V_106 = - V_108 ;
goto V_120;
}
V_70 = F_1 ( V_12 -> V_14 + V_49 ) ;
if ( ! ( V_70 & V_122 ) ) {
F_36 ( L_16 , V_119 ) ;
V_106 = - V_123 ;
goto V_120;
}
F_37 ( 3 , L_17 ) ;
V_10 -> V_124 = V_125 | V_126 |
V_127 | V_128 |
V_129 | V_130 |
V_131 | V_132 ;
V_10 -> V_133 = V_134 | V_135 ;
V_10 -> V_136 = V_135 ;
V_10 -> V_137 = V_138 ;
if ( V_139 == V_140 )
V_10 -> V_141 = F_18 ;
V_10 -> V_142 = NULL ;
V_10 -> V_143 = V_144 ;
F_23 ( V_10 ) ;
V_145 = F_1 ( V_12 -> V_14 + V_146 ) ;
F_4 ( V_12 -> V_14 + V_146 , 0 ) ;
F_4 ( V_12 -> V_14 + V_44 , ~ 0 ) ;
V_106 = F_38 ( V_10 , V_147 ) ;
if ( V_106 ) {
F_37 ( 3 , L_18 ) ;
goto V_120;
}
if ( V_139 == V_148 ) {
F_4 ( V_12 -> V_14 + V_149 ,
V_150 | V_151 ) ;
V_152 = F_1 ( V_12 -> V_14 +
V_153 ) & 0xff0000 ;
F_4 ( V_12 -> V_14 + V_153 , 0x10000 ) ;
V_12 -> V_64 = F_39 ( V_101 , 0 ) ;
V_106 = F_40 ( & V_101 -> V_5 , V_12 -> V_64 ,
F_22 ,
V_154 ,
L_19 , V_10 ) ;
if ( V_106 < 0 ) {
F_32 ( L_20 ,
V_119 , V_12 -> V_64 ) ;
V_106 = - V_123 ;
goto V_155;
}
F_41 ( V_138 L_21 ,
V_12 -> V_64 ) ;
}
F_42 ( & V_101 -> V_5 , F_24 ) ;
F_37 ( 3 , L_22 ) ;
F_41 ( V_138 L_23 ) ;
return 0 ;
V_155:
F_43 ( & V_101 -> V_5 ) ;
V_120:
F_28 ( & V_101 -> V_5 , F_24 ) ;
F_44 ( V_10 ) ;
return V_106 ;
}
int F_45 ( struct V_100 * V_101 )
{
struct V_9 * V_10 = F_46 ( & V_101 -> V_5 ) ;
struct V_11 * V_12 = V_10 -> V_13 ;
F_37 ( 0 , L_24 ) ;
if ( V_139 == V_148 ) {
F_4 ( V_12 -> V_14 + V_149 , 0 ) ;
}
F_4 ( V_12 -> V_14 + V_146 ,
V_145 ) ;
F_4 ( V_12 -> V_14 + V_153 , V_152 ) ;
F_43 ( & V_101 -> V_5 ) ;
F_44 ( V_10 ) ;
return 0 ;
}
