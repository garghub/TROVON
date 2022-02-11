static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
unsigned long V_5 = ( unsigned long ) F_2 ( V_2 ) ;
if ( ( V_5 & V_6 ) && * V_4 >= 90 && V_3 [ 83 ] == 0x26 &&
V_3 [ 84 ] == 0x8c && V_3 [ 85 ] == 0x02 ) {
F_3 ( V_2 ,
L_1 ) ;
V_3 [ 84 ] = V_3 [ 89 ] = 0x4d ;
V_3 [ 85 ] = V_3 [ 90 ] = 0x10 ;
}
if ( ( V_5 & V_7 ) && * V_4 >= 50 &&
V_3 [ 32 ] == 0x81 && V_3 [ 33 ] == 0x06 &&
V_3 [ 49 ] == 0x81 && V_3 [ 50 ] == 0x06 ) {
F_3 ( V_2 ,
L_2 ) ;
V_3 [ 33 ] = V_3 [ 50 ] = 0x02 ;
}
if ( ( V_5 & V_8 ) && * V_4 >= 101 &&
V_3 [ 41 ] == 0x95 && V_3 [ 42 ] == 0x0B &&
V_3 [ 47 ] == 0x05 && V_3 [ 48 ] == 0x09 ) {
F_3 ( V_2 , L_3 ) ;
V_3 [ 41 ] = 0x05 ;
V_3 [ 42 ] = 0x09 ;
V_3 [ 47 ] = 0x95 ;
V_3 [ 48 ] = 0x0B ;
}
switch ( V_2 -> V_9 ) {
case V_10 :
if ( * V_4 == V_11 ) {
F_3 ( V_2 ,
L_4 ) ;
V_3 = V_12 ;
* V_4 = sizeof( V_12 ) ;
}
break;
}
return V_3 ;
}
static int F_4 ( struct V_13 * V_14 ,
struct V_15 * V_16 , unsigned long * * V_17 , int * V_18 )
{
if ( ( V_16 -> V_19 & V_20 ) != V_21 )
return 0 ;
F_5 ( V_22 , V_14 -> V_23 -> V_24 ) ;
switch ( V_16 -> V_19 & V_25 ) {
case 0x004 : F_6 ( V_26 ) ; break;
case 0x00d : F_6 ( V_27 ) ; break;
case 0x024 : F_6 ( V_28 ) ; break;
case 0x025 : F_6 ( V_29 ) ; break;
case 0x026 : F_6 ( V_30 ) ; break;
case 0x031 : F_6 ( V_31 ) ; break;
case 0x032 : F_6 ( V_32 ) ; break;
case 0x033 : F_6 ( V_33 ) ; break;
case 0x047 : F_6 ( V_34 ) ; break;
case 0x048 : F_6 ( V_35 ) ; break;
case 0x049 : F_6 ( V_36 ) ; break;
case 0x04a : F_6 ( V_37 ) ; break;
case 0x04b : F_6 ( V_38 ) ; break;
case 0x04c : F_6 ( V_39 ) ; break;
case 0x04d : F_6 ( V_40 ) ; break;
case 0x051 : F_6 ( V_41 ) ; break;
case 0x052 : F_6 ( V_42 ) ; break;
default:
return 0 ;
}
return 1 ;
}
static int F_7 ( struct V_13 * V_14 , struct V_15 * V_16 ,
unsigned long * * V_17 , int * V_18 )
{
if ( ( V_16 -> V_19 & V_20 ) != V_21 )
return 0 ;
switch ( V_16 -> V_19 & V_25 ) {
case 0x00d : F_6 ( V_36 ) ; break;
default:
return 0 ;
}
return 1 ;
}
static int F_8 ( struct V_13 * V_14 , struct V_15 * V_16 ,
unsigned long * * V_17 , int * V_18 )
{
if ( ( V_16 -> V_19 & V_20 ) != V_43 )
return 0 ;
switch ( V_16 -> V_19 & V_25 ) {
case 0x1001 : F_6 ( V_44 ) ; break;
case 0x1003 : F_6 ( V_45 ) ; break;
case 0x1004 : F_6 ( V_37 ) ; break;
case 0x1005 : F_6 ( V_31 ) ; break;
case 0x100a : F_6 ( V_46 ) ; break;
case 0x100f : F_6 ( V_47 ) ; break;
case 0x1010 : F_6 ( V_48 ) ; break;
case 0x1011 : F_6 ( V_49 ) ; break;
case 0x1012 : F_6 ( V_50 ) ; break;
case 0x1013 : F_6 ( V_51 ) ; break;
case 0x1014 : F_6 ( V_44 ) ; break;
case 0x1015 : F_6 ( V_52 ) ; break;
case 0x1016 : F_6 ( V_53 ) ; break;
case 0x1017 : F_6 ( V_54 ) ; break;
case 0x1018 : F_6 ( V_36 ) ; break;
case 0x1019 : F_6 ( V_55 ) ; break;
case 0x101a : F_6 ( V_56 ) ; break;
case 0x101b : F_6 ( V_57 ) ; break;
case 0x101c : F_6 ( V_58 ) ; break;
case 0x101f : F_6 ( V_59 ) ; break;
case 0x1020 : F_6 ( V_60 ) ; break;
case 0x1021 : F_6 ( V_61 ) ; break;
case 0x1023 : F_6 ( V_42 ) ; break;
case 0x1027 : F_6 ( V_30 ) ; break;
case 0x1028 : F_6 ( V_38 ) ; break;
case 0x1029 : F_6 ( V_28 ) ; break;
case 0x102a : F_6 ( V_62 ) ; break;
case 0x102b : F_6 ( V_58 ) ; break;
case 0x102d : F_6 ( V_63 ) ; break;
case 0x1031 : F_6 ( V_64 ) ; break;
case 0x1032 : F_6 ( V_65 ) ; break;
case 0x1041 : F_6 ( V_66 ) ; break;
case 0x1042 : F_6 ( V_67 ) ; break;
case 0x1043 : F_6 ( V_68 ) ; break;
case 0x1044 : F_6 ( V_69 ) ; break;
case 0x1045 : F_6 ( V_70 ) ; break;
case 0x1046 : F_6 ( V_71 ) ; break;
case 0x1047 : F_6 ( V_72 ) ; break;
case 0x1048 : F_6 ( V_73 ) ; break;
case 0x1049 : F_6 ( V_55 ) ; break;
case 0x104a : F_6 ( V_56 ) ; break;
case 0x104b : F_6 ( V_57 ) ; break;
case 0x104c : F_6 ( V_74 ) ; break;
default:
return 0 ;
}
return 1 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_13 * V_14 ,
struct V_75 * V_76 , struct V_15 * V_16 ,
unsigned long * * V_17 , int * V_18 )
{
static const T_2 V_77 [] = {
0 , 216 , 0 , 213 , 175 , 156 , 0 , 0 , 0 , 0 ,
144 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 212 ,
174 , 167 , 152 , 161 , 112 , 0 , 0 , 0 , 154 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 183 , 184 , 185 , 186 , 187 ,
188 , 189 , 190 , 191 , 192 , 193 , 194 , 0 , 0 , 0
} ;
unsigned long V_5 = ( unsigned long ) F_2 ( V_2 ) ;
unsigned int V_19 = V_16 -> V_19 ;
if ( V_2 -> V_9 == V_78 &&
F_4 ( V_14 , V_16 , V_17 , V_18 ) )
return 1 ;
if ( V_2 -> V_9 == V_79 &&
F_7 ( V_14 , V_16 , V_17 , V_18 ) )
return 1 ;
if ( ( V_5 & V_80 ) && F_8 ( V_14 , V_16 , V_17 , V_18 ) )
return 1 ;
if ( ( V_19 & V_20 ) != V_81 )
return 0 ;
V_19 &= V_25 ;
if ( V_76 -> V_82 == V_83 ) {
if ( ( V_5 & V_84 ) &&
( V_19 == 7 || V_19 == 8 ) )
return - 1 ;
} else {
if ( ( V_5 & V_85 ) &&
V_19 < F_10 ( V_77 ) &&
V_77 [ V_19 ] != 0 ) {
F_11 ( V_14 , V_16 , V_17 , V_18 , V_86 ,
V_77 [ V_19 ] ) ;
return 1 ;
}
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_13 * V_14 ,
struct V_75 * V_76 , struct V_15 * V_16 ,
unsigned long * * V_17 , int * V_18 )
{
unsigned long V_5 = ( unsigned long ) F_2 ( V_2 ) ;
if ( ( V_5 & V_87 ) && V_16 -> type == V_86 &&
( V_76 -> V_88 & V_89 ) )
V_76 -> V_88 &= ~ V_89 ;
if ( ( V_5 & V_90 ) && ( V_16 -> type == V_86 ||
V_16 -> type == V_91 || V_16 -> type == V_92 ) )
F_13 ( V_16 -> V_93 , * V_17 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_75 * V_76 ,
struct V_15 * V_16 , T_3 V_94 )
{
unsigned long V_5 = ( unsigned long ) F_2 ( V_2 ) ;
if ( ( V_5 & V_95 ) && V_16 -> V_93 == V_96 ) {
F_15 ( V_76 -> V_97 -> V_23 , V_16 -> type , V_16 -> V_93 ,
- V_94 ) ;
return 1 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , const struct V_98 * V_99 )
{
unsigned long V_5 = V_99 -> V_100 ;
unsigned int V_101 = V_102 ;
int V_103 ;
F_17 ( V_2 , ( void * ) V_5 ) ;
if ( V_5 & V_104 )
V_2 -> V_5 |= V_105 ;
V_103 = F_18 ( V_2 ) ;
if ( V_103 ) {
F_19 ( V_2 , L_5 ) ;
goto V_106;
}
if ( V_5 & ( V_107 | V_108 | V_109 ) )
V_101 &= ~ V_110 ;
V_103 = F_20 ( V_2 , V_101 ) ;
if ( V_103 ) {
F_19 ( V_2 , L_6 ) ;
goto V_106;
}
if ( V_5 & V_8 ) {
unsigned char V_111 [] = { 0x00 , 0xAF , 0x01 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
V_103 = V_2 -> V_112 ( V_2 , V_111 , sizeof( V_111 ) , V_113 ) ;
if ( V_103 >= 0 ) {
T_4 V_114 ;
F_21 ( & V_114 ) ;
F_22 ( V_114 , 0 , 10 ) ;
V_111 [ 1 ] = 0xB2 ;
F_23 ( & V_111 [ 2 ] , 2 ) ;
V_103 = V_2 -> V_112 ( V_2 , V_111 , sizeof( V_111 ) , V_113 ) ;
}
}
if ( V_5 & V_107 )
F_24 ( V_2 ) ;
if ( V_5 & V_108 )
F_25 ( V_2 ) ;
if ( V_5 & V_109 )
F_26 ( V_2 ) ;
if ( V_5 & V_8 )
F_27 ( V_2 ) ;
return 0 ;
V_106:
return V_103 ;
}
static int T_5 F_28 ( void )
{
return F_29 ( & V_115 ) ;
}
static void T_6 F_30 ( void )
{
F_31 ( & V_115 ) ;
}
