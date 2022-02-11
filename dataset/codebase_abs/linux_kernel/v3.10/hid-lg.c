static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
T_2 V_9 , V_10 , V_11 ;
if ( ( V_6 -> V_12 & V_13 ) && * V_4 >= 90 && V_3 [ 83 ] == 0x26 &&
V_3 [ 84 ] == 0x8c && V_3 [ 85 ] == 0x02 ) {
F_3 ( V_2 ,
L_1 ) ;
V_3 [ 84 ] = V_3 [ 89 ] = 0x4d ;
V_3 [ 85 ] = V_3 [ 90 ] = 0x10 ;
}
if ( ( V_6 -> V_12 & V_14 ) && * V_4 >= 50 &&
V_3 [ 32 ] == 0x81 && V_3 [ 33 ] == 0x06 &&
V_3 [ 49 ] == 0x81 && V_3 [ 50 ] == 0x06 ) {
F_3 ( V_2 ,
L_2 ) ;
V_3 [ 33 ] = V_3 [ 50 ] = 0x02 ;
}
switch ( V_2 -> V_15 ) {
case V_16 :
V_8 = & ( F_4 ( V_2 ) -> V_17 ) ;
if ( ! V_8 ) {
F_5 ( V_2 , L_3 ) ;
break;
}
V_9 = F_6 ( V_8 -> V_9 ) ;
V_10 = V_9 >> 8 ;
V_11 = V_9 & 0xff ;
if ( V_10 == 1 && V_11 == 2 &&
* V_4 == V_18 ) {
F_3 ( V_2 ,
L_4 ) ;
V_3 = V_19 ;
* V_4 = sizeof( V_19 ) ;
}
break;
case V_20 :
if ( * V_4 == V_21 ) {
F_3 ( V_2 ,
L_5 ) ;
V_3 = V_22 ;
* V_4 = sizeof( V_22 ) ;
}
break;
case V_23 :
if ( * V_4 == V_24 ) {
F_3 ( V_2 ,
L_6 ) ;
V_3 = V_25 ;
* V_4 = sizeof( V_25 ) ;
}
break;
case V_26 :
if ( * V_4 >= 101 && V_3 [ 41 ] == 0x95 && V_3 [ 42 ] == 0x0B &&
V_3 [ 47 ] == 0x05 && V_3 [ 48 ] == 0x09 ) {
F_3 ( V_2 , L_7 ) ;
V_3 [ 41 ] = 0x05 ;
V_3 [ 42 ] = 0x09 ;
V_3 [ 47 ] = 0x95 ;
V_3 [ 48 ] = 0x0B ;
}
break;
}
return V_3 ;
}
static int F_7 ( struct V_27 * V_28 ,
struct V_29 * V_30 , unsigned long * * V_31 , int * V_32 )
{
if ( ( V_30 -> V_33 & V_34 ) != V_35 )
return 0 ;
F_8 ( V_36 , V_28 -> V_37 -> V_38 ) ;
switch ( V_30 -> V_33 & V_39 ) {
case 0x004 : F_9 ( V_40 ) ; break;
case 0x00d : F_9 ( V_41 ) ; break;
case 0x024 : F_9 ( V_42 ) ; break;
case 0x025 : F_9 ( V_43 ) ; break;
case 0x026 : F_9 ( V_44 ) ; break;
case 0x031 : F_9 ( V_45 ) ; break;
case 0x032 : F_9 ( V_46 ) ; break;
case 0x033 : F_9 ( V_47 ) ; break;
case 0x047 : F_9 ( V_48 ) ; break;
case 0x048 : F_9 ( V_49 ) ; break;
case 0x049 : F_9 ( V_50 ) ; break;
case 0x04a : F_9 ( V_51 ) ; break;
case 0x04b : F_9 ( V_52 ) ; break;
case 0x04c : F_9 ( V_53 ) ; break;
case 0x04d : F_9 ( V_54 ) ; break;
case 0x051 : F_9 ( V_55 ) ; break;
case 0x052 : F_9 ( V_56 ) ; break;
default:
return 0 ;
}
return 1 ;
}
static int F_10 ( struct V_27 * V_28 , struct V_29 * V_30 ,
unsigned long * * V_31 , int * V_32 )
{
if ( ( V_30 -> V_33 & V_34 ) != V_35 )
return 0 ;
switch ( V_30 -> V_33 & V_39 ) {
case 0x00d : F_9 ( V_50 ) ; break;
default:
return 0 ;
}
return 1 ;
}
static int F_11 ( struct V_27 * V_28 , struct V_29 * V_30 ,
unsigned long * * V_31 , int * V_32 )
{
if ( ( V_30 -> V_33 & V_34 ) != V_57 )
return 0 ;
switch ( V_30 -> V_33 & V_39 ) {
case 0x1001 : F_9 ( V_58 ) ; break;
case 0x1003 : F_9 ( V_59 ) ; break;
case 0x1004 : F_9 ( V_51 ) ; break;
case 0x1005 : F_9 ( V_45 ) ; break;
case 0x100a : F_9 ( V_60 ) ; break;
case 0x100f : F_9 ( V_61 ) ; break;
case 0x1010 : F_9 ( V_62 ) ; break;
case 0x1011 : F_9 ( V_63 ) ; break;
case 0x1012 : F_9 ( V_64 ) ; break;
case 0x1013 : F_9 ( V_65 ) ; break;
case 0x1014 : F_9 ( V_58 ) ; break;
case 0x1015 : F_9 ( V_66 ) ; break;
case 0x1016 : F_9 ( V_67 ) ; break;
case 0x1017 : F_9 ( V_68 ) ; break;
case 0x1018 : F_9 ( V_50 ) ; break;
case 0x1019 : F_9 ( V_69 ) ; break;
case 0x101a : F_9 ( V_70 ) ; break;
case 0x101b : F_9 ( V_71 ) ; break;
case 0x101c : F_9 ( V_72 ) ; break;
case 0x101f : F_9 ( V_73 ) ; break;
case 0x1020 : F_9 ( V_74 ) ; break;
case 0x1021 : F_9 ( V_75 ) ; break;
case 0x1023 : F_9 ( V_56 ) ; break;
case 0x1027 : F_9 ( V_44 ) ; break;
case 0x1028 : F_9 ( V_52 ) ; break;
case 0x1029 : F_9 ( V_42 ) ; break;
case 0x102a : F_9 ( V_76 ) ; break;
case 0x102b : F_9 ( V_72 ) ; break;
case 0x102d : F_9 ( V_77 ) ; break;
case 0x1031 : F_9 ( V_78 ) ; break;
case 0x1032 : F_9 ( V_79 ) ; break;
case 0x1041 : F_9 ( V_80 ) ; break;
case 0x1042 : F_9 ( V_81 ) ; break;
case 0x1043 : F_9 ( V_82 ) ; break;
case 0x1044 : F_9 ( V_83 ) ; break;
case 0x1045 : F_9 ( V_84 ) ; break;
case 0x1046 : F_9 ( V_85 ) ; break;
case 0x1047 : F_9 ( V_86 ) ; break;
case 0x1048 : F_9 ( V_87 ) ; break;
case 0x1049 : F_9 ( V_69 ) ; break;
case 0x104a : F_9 ( V_70 ) ; break;
case 0x104b : F_9 ( V_71 ) ; break;
case 0x104c : F_9 ( V_88 ) ; break;
default:
return 0 ;
}
return 1 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_27 * V_28 ,
struct V_89 * V_90 , struct V_29 * V_30 ,
unsigned long * * V_31 , int * V_32 )
{
static const T_3 V_91 [] = {
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
unsigned int V_33 = V_30 -> V_33 ;
if ( V_2 -> V_15 == V_92 &&
F_7 ( V_28 , V_30 , V_31 , V_32 ) )
return 1 ;
if ( V_2 -> V_15 == V_93 &&
F_10 ( V_28 , V_30 , V_31 , V_32 ) )
return 1 ;
if ( ( V_6 -> V_12 & V_94 ) && F_11 ( V_28 , V_30 , V_31 , V_32 ) )
return 1 ;
if ( ( V_33 & V_34 ) != V_95 )
return 0 ;
V_33 &= V_39 ;
if ( V_90 -> V_96 == V_97 ) {
if ( ( V_6 -> V_12 & V_98 ) &&
( V_33 == 7 || V_33 == 8 ) )
return - 1 ;
} else {
if ( ( V_6 -> V_12 & V_99 ) &&
V_33 < F_13 ( V_91 ) &&
V_91 [ V_33 ] != 0 ) {
F_14 ( V_28 , V_30 , V_31 , V_32 , V_100 ,
V_91 [ V_33 ] ) ;
return 1 ;
}
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_27 * V_28 ,
struct V_89 * V_90 , struct V_29 * V_30 ,
unsigned long * * V_31 , int * V_32 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ( V_6 -> V_12 & V_101 ) && V_30 -> type == V_100 &&
( V_90 -> V_102 & V_103 ) )
V_90 -> V_102 &= ~ V_103 ;
if ( ( V_6 -> V_12 & V_104 ) && ( V_30 -> type == V_100 ||
V_30 -> type == V_105 || V_30 -> type == V_106 ) )
F_16 ( V_30 -> V_107 , * V_31 ) ;
if ( V_30 -> type == V_106 && ( V_30 -> V_107 == V_108 ||
V_30 -> V_107 == V_109 || V_30 -> V_107 == V_110 ||
V_30 -> V_107 == V_111 ) ) {
switch ( V_2 -> V_15 ) {
case V_16 :
case V_20 :
case V_23 :
case V_112 :
case V_113 :
case V_114 :
case V_26 :
case V_115 :
V_90 -> V_96 = V_116 ;
break;
default:
break;
}
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_89 * V_90 ,
struct V_29 * V_30 , T_4 V_117 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ( V_6 -> V_12 & V_118 ) && V_30 -> V_107 == V_119 ) {
F_18 ( V_90 -> V_120 -> V_37 , V_30 -> type , V_30 -> V_107 ,
- V_117 ) ;
return 1 ;
}
if ( V_6 -> V_12 & V_121 ) {
return F_19 ( V_2 , V_90 , V_30 , V_117 , V_6 ) ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , const struct V_122 * V_123 )
{
unsigned int V_124 = V_125 ;
struct V_5 * V_6 ;
int V_126 ;
V_6 = F_21 ( sizeof( struct V_5 ) , V_127 ) ;
if ( ! V_6 ) {
F_5 ( V_2 , L_8 ) ;
return - V_128 ;
}
V_6 -> V_12 = V_123 -> V_129 ;
F_22 ( V_2 , ( void * ) V_6 ) ;
if ( V_6 -> V_12 & V_130 )
V_2 -> V_12 |= V_131 ;
V_126 = F_23 ( V_2 ) ;
if ( V_126 ) {
F_5 ( V_2 , L_9 ) ;
goto V_132;
}
if ( V_6 -> V_12 & ( V_133 | V_134 | V_135 | V_121 ) )
V_124 &= ~ V_136 ;
V_126 = F_24 ( V_2 , V_124 ) ;
if ( V_126 ) {
F_5 ( V_2 , L_10 ) ;
goto V_132;
}
if ( V_2 -> V_15 == V_26 ) {
unsigned char V_137 [] = { 0x00 , 0xAF , 0x01 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
V_126 = V_2 -> V_138 ( V_2 , V_137 , sizeof( V_137 ) , V_139 ) ;
if ( V_126 >= 0 ) {
T_5 V_140 ;
F_25 ( & V_140 ) ;
F_26 ( V_140 , 0 , 10 ) ;
V_137 [ 1 ] = 0xB2 ;
F_27 ( & V_137 [ 2 ] , 2 ) ;
V_126 = V_2 -> V_138 ( V_2 , V_137 , sizeof( V_137 ) , V_139 ) ;
}
}
if ( V_6 -> V_12 & V_133 )
F_28 ( V_2 ) ;
if ( V_6 -> V_12 & V_134 )
F_29 ( V_2 ) ;
if ( V_6 -> V_12 & V_135 )
F_30 ( V_2 ) ;
if ( V_6 -> V_12 & V_121 )
F_31 ( V_2 ) ;
return 0 ;
V_132:
F_32 ( V_6 ) ;
return V_126 ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_12 & V_121 )
F_34 ( V_2 ) ;
F_35 ( V_2 ) ;
F_32 ( V_6 ) ;
}
