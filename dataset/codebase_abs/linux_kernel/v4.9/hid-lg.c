static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ( V_6 -> V_7 & V_8 ) && * V_4 >= 91 && V_3 [ 83 ] == 0x26 &&
V_3 [ 84 ] == 0x8c && V_3 [ 85 ] == 0x02 ) {
F_3 ( V_2 ,
L_1 ) ;
V_3 [ 84 ] = V_3 [ 89 ] = 0x4d ;
V_3 [ 85 ] = V_3 [ 90 ] = 0x10 ;
}
if ( ( V_6 -> V_7 & V_9 ) && * V_4 >= 51 &&
V_3 [ 32 ] == 0x81 && V_3 [ 33 ] == 0x06 &&
V_3 [ 49 ] == 0x81 && V_3 [ 50 ] == 0x06 ) {
F_3 ( V_2 ,
L_2 ) ;
V_3 [ 33 ] = V_3 [ 50 ] = 0x02 ;
}
switch ( V_2 -> V_10 ) {
case V_11 :
if ( * V_4 == V_12 ) {
F_3 ( V_2 ,
L_3 ) ;
V_3 = V_13 ;
* V_4 = sizeof( V_13 ) ;
}
break;
case V_14 :
if ( * V_4 == V_15 ) {
F_3 ( V_2 ,
L_4 ) ;
V_3 = V_16 ;
* V_4 = sizeof( V_16 ) ;
}
break;
case V_17 :
if ( * V_4 == V_18 ) {
F_3 ( V_2 ,
L_5 ) ;
V_3 = V_19 ;
* V_4 = sizeof( V_19 ) ;
}
break;
case V_20 :
if ( * V_4 == V_21 ) {
F_3 ( V_2 ,
L_6 ) ;
V_3 = V_22 ;
* V_4 = sizeof( V_22 ) ;
}
break;
case V_23 :
if ( * V_4 == V_24 ) {
F_3 ( V_2 ,
L_7 ) ;
V_3 = V_25 ;
* V_4 = sizeof( V_25 ) ;
}
break;
case V_26 :
if ( * V_4 == V_27 ) {
F_3 ( V_2 ,
L_8 ) ;
V_3 = V_28 ;
* V_4 = sizeof( V_28 ) ;
}
break;
case V_29 :
if ( * V_4 >= 101 && V_3 [ 41 ] == 0x95 && V_3 [ 42 ] == 0x0B &&
V_3 [ 47 ] == 0x05 && V_3 [ 48 ] == 0x09 ) {
F_3 ( V_2 , L_9 ) ;
V_3 [ 41 ] = 0x05 ;
V_3 [ 42 ] = 0x09 ;
V_3 [ 47 ] = 0x95 ;
V_3 [ 48 ] = 0x0B ;
}
break;
}
return V_3 ;
}
static int F_4 ( struct V_30 * V_31 ,
struct V_32 * V_33 , unsigned long * * V_34 , int * V_35 )
{
if ( ( V_33 -> V_36 & V_37 ) != V_38 )
return 0 ;
F_5 ( V_39 , V_31 -> V_40 -> V_41 ) ;
switch ( V_33 -> V_36 & V_42 ) {
case 0x004 : F_6 ( V_43 ) ; break;
case 0x00d : F_6 ( V_44 ) ; break;
case 0x024 : F_6 ( V_45 ) ; break;
case 0x025 : F_6 ( V_46 ) ; break;
case 0x026 : F_6 ( V_47 ) ; break;
case 0x031 : F_6 ( V_48 ) ; break;
case 0x032 : F_6 ( V_49 ) ; break;
case 0x033 : F_6 ( V_50 ) ; break;
case 0x047 : F_6 ( V_51 ) ; break;
case 0x048 : F_6 ( V_52 ) ; break;
case 0x049 : F_6 ( V_53 ) ; break;
case 0x04a : F_6 ( V_54 ) ; break;
case 0x04b : F_6 ( V_55 ) ; break;
case 0x04c : F_6 ( V_56 ) ; break;
case 0x04d : F_6 ( V_57 ) ; break;
case 0x051 : F_6 ( V_58 ) ; break;
case 0x052 : F_6 ( V_59 ) ; break;
default:
return 0 ;
}
return 1 ;
}
static int F_7 ( struct V_30 * V_31 , struct V_32 * V_33 ,
unsigned long * * V_34 , int * V_35 )
{
if ( ( V_33 -> V_36 & V_37 ) != V_38 )
return 0 ;
switch ( V_33 -> V_36 & V_42 ) {
case 0x00d : F_6 ( V_53 ) ; break;
default:
return 0 ;
}
return 1 ;
}
static int F_8 ( struct V_30 * V_31 , struct V_32 * V_33 ,
unsigned long * * V_34 , int * V_35 )
{
if ( ( V_33 -> V_36 & V_37 ) != V_60 )
return 0 ;
switch ( V_33 -> V_36 & V_42 ) {
case 0x1001 : F_6 ( V_61 ) ; break;
case 0x1003 : F_6 ( V_62 ) ; break;
case 0x1004 : F_6 ( V_54 ) ; break;
case 0x1005 : F_6 ( V_48 ) ; break;
case 0x100a : F_6 ( V_63 ) ; break;
case 0x100f : F_6 ( V_64 ) ; break;
case 0x1010 : F_6 ( V_65 ) ; break;
case 0x1011 : F_6 ( V_66 ) ; break;
case 0x1012 : F_6 ( V_67 ) ; break;
case 0x1013 : F_6 ( V_68 ) ; break;
case 0x1014 : F_6 ( V_61 ) ; break;
case 0x1015 : F_6 ( V_69 ) ; break;
case 0x1016 : F_6 ( V_70 ) ; break;
case 0x1017 : F_6 ( V_71 ) ; break;
case 0x1018 : F_6 ( V_53 ) ; break;
case 0x1019 : F_6 ( V_72 ) ; break;
case 0x101a : F_6 ( V_73 ) ; break;
case 0x101b : F_6 ( V_74 ) ; break;
case 0x101c : F_6 ( V_75 ) ; break;
case 0x101f : F_6 ( V_76 ) ; break;
case 0x1020 : F_6 ( V_77 ) ; break;
case 0x1021 : F_6 ( V_78 ) ; break;
case 0x1023 : F_6 ( V_59 ) ; break;
case 0x1027 : F_6 ( V_47 ) ; break;
case 0x1028 : F_6 ( V_55 ) ; break;
case 0x1029 : F_6 ( V_45 ) ; break;
case 0x102a : F_6 ( V_79 ) ; break;
case 0x102b : F_6 ( V_75 ) ; break;
case 0x102d : F_6 ( V_80 ) ; break;
case 0x1031 : F_6 ( V_81 ) ; break;
case 0x1032 : F_6 ( V_82 ) ; break;
case 0x1041 : F_6 ( V_83 ) ; break;
case 0x1042 : F_6 ( V_84 ) ; break;
case 0x1043 : F_6 ( V_85 ) ; break;
case 0x1044 : F_6 ( V_86 ) ; break;
case 0x1045 : F_6 ( V_87 ) ; break;
case 0x1046 : F_6 ( V_88 ) ; break;
case 0x1047 : F_6 ( V_89 ) ; break;
case 0x1048 : F_6 ( V_90 ) ; break;
case 0x1049 : F_6 ( V_72 ) ; break;
case 0x104a : F_6 ( V_73 ) ; break;
case 0x104b : F_6 ( V_74 ) ; break;
case 0x104c : F_6 ( V_91 ) ; break;
default:
return 0 ;
}
return 1 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_30 * V_31 ,
struct V_92 * V_93 , struct V_32 * V_33 ,
unsigned long * * V_34 , int * V_35 )
{
static const T_2 V_94 [] = {
0 , 216 , 0 , 213 , 175 , 156 , 0 , 0 , 0 , 0 ,
144 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 212 ,
174 , 167 , 152 , 161 , 112 , 0 , 0 , 0 , 154 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 183 , 184 , 185 , 186 , 187 ,
188 , 189 , 190 , 191 , 192 , 193 , 194 , 0 , 0 , 0
} ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_36 = V_33 -> V_36 ;
if ( V_2 -> V_10 == V_95 &&
F_4 ( V_31 , V_33 , V_34 , V_35 ) )
return 1 ;
if ( V_2 -> V_10 == V_96 &&
F_7 ( V_31 , V_33 , V_34 , V_35 ) )
return 1 ;
if ( ( V_6 -> V_7 & V_97 ) && F_8 ( V_31 , V_33 , V_34 , V_35 ) )
return 1 ;
if ( ( V_36 & V_37 ) != V_98 )
return 0 ;
V_36 &= V_42 ;
if ( V_93 -> V_99 == V_100 ) {
if ( ( V_6 -> V_7 & V_101 ) &&
( V_36 == 7 || V_36 == 8 ) )
return - 1 ;
} else {
if ( ( V_6 -> V_7 & V_102 ) &&
V_36 < F_10 ( V_94 ) &&
V_94 [ V_36 ] != 0 ) {
F_11 ( V_31 , V_33 , V_34 , V_35 , V_103 ,
V_94 [ V_36 ] ) ;
return 1 ;
}
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_30 * V_31 ,
struct V_92 * V_93 , struct V_32 * V_33 ,
unsigned long * * V_34 , int * V_35 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ( V_6 -> V_7 & V_104 ) && V_33 -> type == V_103 &&
( V_93 -> V_105 & V_106 ) )
V_93 -> V_105 &= ~ V_106 ;
if ( ( V_6 -> V_7 & V_107 ) && ( V_33 -> type == V_103 ||
V_33 -> type == V_108 || V_33 -> type == V_109 ) )
F_13 ( V_33 -> V_110 , * V_34 ) ;
if ( V_33 -> type == V_109 && ( V_33 -> V_110 == V_111 ||
V_33 -> V_110 == V_112 || V_33 -> V_110 == V_113 ||
V_33 -> V_110 == V_114 ) ) {
switch ( V_2 -> V_10 ) {
case V_115 :
case V_11 :
case V_14 :
case V_17 :
case V_26 :
case V_116 :
case V_117 :
case V_118 :
case V_29 :
case V_20 :
case V_23 :
V_93 -> V_99 = V_119 ;
break;
default:
break;
}
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_92 * V_93 ,
struct V_32 * V_33 , T_3 V_120 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ( V_6 -> V_7 & V_121 ) && V_33 -> V_110 == V_122 ) {
F_15 ( V_93 -> V_123 -> V_40 , V_33 -> type , V_33 -> V_110 ,
- V_120 ) ;
return 1 ;
}
if ( V_6 -> V_7 & V_124 ) {
return F_16 ( V_2 , V_93 , V_33 , V_120 , V_6 ) ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_125 * V_126 ,
T_2 * V_127 , int V_128 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_7 & V_124 )
return F_18 ( V_2 , V_126 , V_127 , V_128 , V_6 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , const struct V_129 * V_130 )
{
struct V_131 * V_132 = F_20 ( V_2 -> V_133 . V_134 ) ;
T_1 V_135 = V_132 -> V_136 -> V_137 . V_138 ;
unsigned int V_139 = V_140 ;
struct V_5 * V_6 ;
int V_141 ;
if ( ( V_2 -> V_10 == V_115 ) &&
( V_135 != 0 ) ) {
F_21 ( L_10 , V_142 , V_135 ) ;
return - V_143 ;
}
V_6 = F_22 ( sizeof( struct V_5 ) , V_144 ) ;
if ( ! V_6 ) {
F_23 ( V_2 , L_11 ) ;
return - V_145 ;
}
V_6 -> V_7 = V_130 -> V_146 ;
F_24 ( V_2 , ( void * ) V_6 ) ;
if ( V_6 -> V_7 & V_147 )
V_2 -> V_7 |= V_148 ;
V_141 = F_25 ( V_2 ) ;
if ( V_141 ) {
F_23 ( V_2 , L_12 ) ;
goto V_149;
}
if ( V_6 -> V_7 & ( V_150 | V_151 | V_152 | V_124 ) )
V_139 &= ~ V_153 ;
V_141 = F_26 ( V_2 , V_139 ) ;
if ( V_141 ) {
F_23 ( V_2 , L_13 ) ;
goto V_149;
}
if ( V_2 -> V_10 == V_29 ) {
const unsigned char V_154 [] = { 0x00 , 0xAF , 0x01 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
T_2 * V_155 = F_27 ( V_154 , sizeof( V_154 ) , V_144 ) ;
if ( ! V_155 ) {
V_141 = - V_145 ;
goto V_149;
}
V_141 = F_28 ( V_2 , V_155 [ 0 ] , V_155 , sizeof( V_154 ) ,
V_156 , V_157 ) ;
if ( V_141 >= 0 ) {
T_4 V_158 ;
F_29 ( & V_158 ) ;
F_30 ( V_158 , 0 ,
F_31 ( 40 ) ) ;
V_155 [ 1 ] = 0xB2 ;
F_32 ( & V_155 [ 2 ] , 2 ) ;
V_141 = F_28 ( V_2 , V_155 [ 0 ] , V_155 , sizeof( V_154 ) ,
V_156 , V_157 ) ;
}
F_33 ( V_155 ) ;
}
if ( V_6 -> V_7 & V_150 )
V_141 = F_34 ( V_2 ) ;
else if ( V_6 -> V_7 & V_151 )
V_141 = F_35 ( V_2 ) ;
else if ( V_6 -> V_7 & V_152 )
V_141 = F_36 ( V_2 ) ;
else if ( V_6 -> V_7 & V_124 )
V_141 = F_37 ( V_2 ) ;
if ( V_141 )
goto V_149;
return 0 ;
V_149:
F_33 ( V_6 ) ;
return V_141 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_7 & V_124 )
F_39 ( V_2 ) ;
else
F_40 ( V_2 ) ;
F_33 ( V_6 ) ;
}
