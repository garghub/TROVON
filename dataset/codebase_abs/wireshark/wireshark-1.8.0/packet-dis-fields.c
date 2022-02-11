void F_1 ( void )
{
F_2 ( V_1 ) ;
F_2 ( V_2 ) ;
F_2 ( V_3 ) ;
F_2 ( V_4 ) ;
F_2 ( V_5 ) ;
F_2 ( V_6 ) ;
F_2 ( V_7 ) ;
F_2 ( V_8 ) ;
F_2 ( V_9 ) ;
F_2 ( V_10 ) ;
F_2 ( V_11 ) ;
}
static T_1 F_3 ( T_1 V_12 , T_2 V_13 )
{
T_1 V_14 = V_12 % V_13 ;
if ( V_14 != 0 )
{
V_12 += V_13 - V_14 ;
}
return V_12 ;
}
T_1 F_4 ( T_3 * V_15 , T_4 * V_16 , T_1 V_12 , T_5 V_17 , T_2 V_18 )
{
F_5 ( V_16 , V_15 , V_12 , V_18 , L_1 ,
V_17 . V_19 , V_18 ) ;
V_12 += V_18 ;
return V_12 ;
}
T_1 F_6 ( T_3 * V_15 , T_4 * V_16 , T_1 V_12 , T_5 V_17 , T_2 V_18 )
{
T_6 * V_20 = 0 ;
T_7 V_21 = 0 ;
V_12 = F_3 ( V_12 , V_18 ) ;
switch( V_18 )
{
case 1 :
V_21 = F_7 ( V_15 , V_12 ) ;
break;
case 2 :
V_21 = F_8 ( V_15 , V_12 ) ;
break;
case 4 :
V_21 = F_9 ( V_15 , V_12 ) ;
break;
case 8 :
V_21 = F_10 ( V_15 , V_12 ) ;
break;
default:
break;
}
switch( V_17 . V_22 )
{
case V_23 :
if ( ( V_24 == V_25 ) &&
( V_26 == V_27 ) )
{
V_20 = V_28 ;
}
else if ( V_24 == V_29 )
{
V_20 = V_30 ;
}
break;
default:
break;
}
if ( V_20 != 0 )
{
int V_31 = 0 ;
while ( V_20 [ V_31 ] . V_32 != 0 )
{
int V_33 = 0 ;
T_8 * V_34 = V_20 [ V_31 ] . V_35 ;
while ( V_34 [ V_33 ] . V_36 != 0 )
{
if ( ( ( V_20 [ V_31 ] . V_32 & V_21 ) >> V_20 [ V_31 ] . V_37 ) ==
V_34 [ V_33 ] . V_38 )
{
F_5 ( V_16 , V_15 , V_12 , V_18 ,
L_2 , V_20 [ V_31 ] . V_36 ,
V_34 [ V_33 ] . V_36 ) ;
break;
}
++ V_33 ;
}
++ V_31 ;
}
}
else
{
F_5 ( V_16 , V_15 , V_12 , V_18 ,
L_3 V_39 L_4 , V_21 ) ;
}
V_12 += V_18 ;
return V_12 ;
}
T_1 F_11 ( T_3 * V_15 , T_4 * V_16 , T_1 V_12 , T_5 V_17 , T_2 V_18 )
{
T_7 V_21 = 0 ;
V_12 = F_3 ( V_12 , V_18 ) ;
switch( V_18 )
{
case 1 :
V_21 = F_7 ( V_15 , V_12 ) ;
break;
case 2 :
V_21 = F_8 ( V_15 , V_12 ) ;
break;
case 4 :
V_21 = F_9 ( V_15 , V_12 ) ;
break;
case 8 :
V_21 = F_10 ( V_15 , V_12 ) ;
break;
default:
break;
}
F_5 ( V_16 , V_15 , V_12 , V_18 , L_5 V_39 L_6 ,
V_17 . V_19 , V_21 ) ;
if ( V_17 . V_40 != 0 )
{
* ( V_17 . V_40 ) = ( V_41 ) V_21 ;
}
V_12 += V_18 ;
return V_12 ;
}
T_1 F_12 ( T_3 * V_15 , T_4 * V_16 , T_1 V_12 , T_5 V_17 , T_2 V_18 )
{
T_7 V_21 = 0 ;
V_12 = F_3 ( V_12 , V_18 ) ;
switch( V_18 )
{
case 1 :
V_21 = F_7 ( V_15 , V_12 ) ;
break;
case 2 :
V_21 = F_8 ( V_15 , V_12 ) ;
break;
case 4 :
V_21 = F_9 ( V_15 , V_12 ) ;
break;
case 8 :
V_21 = F_10 ( V_15 , V_12 ) ;
break;
default:
break;
}
F_5 ( V_16 , V_15 , V_12 , V_18 , L_5 V_39 L_7 ,
V_17 . V_19 , V_21 ) ;
V_12 += V_18 ;
return V_12 ;
}
T_1 F_13 ( T_3 * V_15 , T_4 * V_16 , T_1 V_12 , T_5 V_17 V_42 , T_2 V_18 )
{
F_5 ( V_16 , V_15 , V_12 , V_18 ,
L_8 , V_18 ) ;
V_12 += V_18 ;
return V_12 ;
}
T_1 F_14 ( T_3 * V_15 , T_4 * V_16 , T_1 V_12 , T_5 V_17 , T_2 V_18 )
{
const T_9 * V_43 = 0 ;
V_41 V_44 = 0 ;
const T_10 * V_45 = 0 ;
#if 0
proto_item *pi;
#endif
int V_46 = - 1 ;
V_12 = F_3 ( V_12 , V_18 ) ;
switch( V_17 . V_22 )
{
case V_47 :
V_43 = V_48 ;
break;
case V_49 :
V_43 = V_50 ;
break;
case V_51 :
V_43 = V_52 ;
break;
case V_53 :
V_43 = V_54 ;
break;
case V_55 :
V_43 = V_56 ;
break;
case V_57 :
V_43 = V_58 ;
break;
case V_59 :
V_43 = V_60 ;
V_46 = V_61 ;
break;
case V_62 :
V_43 = V_63 ;
V_46 = V_64 ;
break;
case V_65 :
V_43 = V_66 ;
V_46 = V_67 ;
break;
case V_68 :
V_43 = V_69 ;
V_46 = V_70 ;
break;
case V_71 :
V_43 = V_72 ;
V_46 = V_73 ;
break;
case V_74 :
V_43 = V_75 ;
break;
case V_76 :
V_43 = V_77 ;
break;
case V_78 :
V_43 = V_79 ;
V_46 = V_80 ;
break;
case V_81 :
V_43 = V_82 ;
break;
case V_83 :
V_43 = V_84 ;
break;
case V_85 :
if ( V_24 == V_25 )
{
switch( V_26 )
{
case V_27 :
V_43 = V_86 ;
V_46 = V_87 ;
break;
case V_88 :
V_43 = V_89 ;
V_46 = V_90 ;
break;
case V_91 :
V_43 = V_92 ;
V_46 = V_93 ;
break;
case V_94 :
V_43 = V_95 ;
V_46 = V_96 ;
break;
case V_97 :
V_43 = V_98 ;
V_46 = V_99 ;
break;
default:
V_43 = 0 ;
break;
}
}
break;
case V_100 :
V_43 = V_101 ;
V_46 = V_102 ;
break;
case V_103 :
V_43 = V_104 ;
V_46 = V_105 ;
break;
case V_106 :
V_43 = V_107 ;
V_46 = V_108 ;
break;
case V_109 :
V_43 = V_110 ;
break;
case V_111 :
V_43 = V_112 ;
break;
case V_113 :
V_43 = V_114 ;
break;
case V_115 :
V_43 = V_116 ;
break;
case V_117 :
V_43 = V_118 ;
break;
case V_119 :
V_43 = V_120 ;
break;
case V_121 :
V_43 = V_122 ;
break;
case V_123 :
switch ( V_124 ) {
case V_125 :
V_43 = V_126 ;
break;
case V_127 :
V_43 = V_128 ;
break;
case V_129 :
V_43 = V_130 ;
break;
case V_131 :
V_43 = V_132 ;
break;
case V_133 :
V_43 = V_134 ;
break;
case V_135 :
V_43 = V_136 ;
break;
case V_137 :
case V_138 :
default:
V_43 = V_139 ;
break;
}
break;
default:
V_43 = 0 ;
break;
}
switch( V_18 )
{
case 1 :
V_44 = F_7 ( V_15 , V_12 ) ;
break;
case 2 :
V_44 = F_8 ( V_15 , V_12 ) ;
break;
case 4 :
V_44 = F_9 ( V_15 , V_12 ) ;
break;
default:
break;
}
V_45 = F_15 ( V_44 , V_43 , L_9 ) ;
if ( V_46 != - 1 ) {
#if 0
pi = proto_tree_add_item(tree, dis_hf_id, tvb, offset, numBytes, ENC_BIG_ENDIAN);
proto_item_set_text(pi, "%s = %s", parserNode.fieldLabel, enumStr);
#else
F_16 ( V_16 , V_46 , V_15 , V_12 , V_18 , V_140 ) ;
#endif
}
else {
F_5 ( V_16 , V_15 , V_12 , V_18 , L_2 ,
V_17 . V_19 , V_45 ) ;
}
if ( V_17 . V_40 != 0 )
{
* ( V_17 . V_40 ) = V_44 ;
}
V_12 += V_18 ;
return V_12 ;
}
T_1 F_17 ( T_3 * V_15 , T_4 * V_16 , T_1 V_12 , T_5 V_17 )
{
T_11 V_141 ;
V_12 = F_3 ( V_12 , 4 ) ;
V_141 = F_18 ( V_15 , V_12 ) ;
F_5 ( V_16 , V_15 , V_12 , 4 , L_10 ,
V_17 . V_19 , V_141 ) ;
V_12 += 4 ;
return V_12 ;
}
T_1 F_19 ( T_3 * V_15 , T_4 * V_16 , T_1 V_12 , T_10 * V_142 )
{
T_11 V_141 ;
V_12 = F_3 ( V_12 , 4 ) ;
V_141 = F_18 ( V_15 , V_12 ) ;
F_5 ( V_16 , V_15 , V_12 , 4 , L_10 ,
V_142 , V_141 ) ;
V_12 += 4 ;
return V_12 ;
}
T_1 F_20 ( T_3 * V_15 , T_4 * V_16 , T_1 V_12 , T_5 V_17 )
{
T_12 V_143 ;
V_12 = F_3 ( V_12 , 8 ) ;
V_143 = F_21 ( V_15 , V_12 ) ;
F_5 ( V_16 , V_15 , V_12 , 8 , L_10 ,
V_17 . V_19 , V_143 ) ;
V_12 += 8 ;
return V_12 ;
}
T_1 F_22 ( T_3 * V_15 , T_4 * V_16 , T_1 V_12 , T_5 V_17 )
{
static double V_144 = 1000.0 ;
static double V_145 = 60.0 * 1000.0 ;
static double V_146 = 60.0 * 60.0 * 1000.0 ;
static double V_147 = 0x7fffffff ;
T_2 V_148 = 0 ;
V_41 V_21 ;
T_2 V_149 ;
T_2 V_150 ;
T_2 V_151 ;
double V_152 ;
V_12 = F_3 ( V_12 , 4 ) ;
V_21 = F_9 ( V_15 , V_12 ) ;
if( V_21 & 1 )
V_148 = 1 ;
V_152 = ( V_21 >> 1 ) * V_146 / V_147 ;
V_152 += 0.5 ;
V_149 = ( T_2 ) ( V_152 / V_145 ) ;
V_152 -= ( V_149 * V_145 ) ;
V_150 = ( T_2 ) ( V_152 / V_144 ) ;
V_152 -= ( V_150 * V_144 ) ;
V_151 = ( T_2 ) V_152 ;
if( V_148 )
{
F_5 ( V_16 , V_15 , V_12 , 4 , L_11 ,
V_17 . V_19 , V_149 , V_150 , V_151 ) ;
}
else
{
F_5 ( V_16 , V_15 , V_12 , 4 , L_12 ,
V_17 . V_19 , V_149 , V_150 , V_151 ) ;
}
V_12 += 4 ;
return V_12 ;
}
T_1 F_23 ( T_3 * V_15 , T_4 * V_16 , T_1 V_12 )
{
T_5 * V_153 = 0 ;
switch ( V_154 ) {
case V_155 :
V_153 = V_2 ;
break;
case V_156 :
V_153 = V_3 ;
break;
case V_157 :
V_153 = V_4 ;
break;
default:
V_153 = V_1 ;
break;
}
if ( V_153 )
{
V_12 = F_24 ( V_15 , V_16 , V_12 , V_153 ) ;
}
return V_12 ;
}
T_1 F_25 ( T_3 * V_15 , T_4 * V_16 , T_1 V_12 )
{
T_5 * V_153 = 0 ;
switch ( V_158 ) {
case 47200 :
V_153 = V_5 ;
break;
case 47300 :
V_153 = V_6 ;
break;
case 47600 :
V_153 = V_7 ;
break;
default:
{
V_41 V_159 = V_160 - 6 ;
if ( V_159 > 0 )
{
F_5 ( V_16 , V_15 , V_12 , V_159 ,
L_13 , V_159 ) ;
V_12 += V_159 ;
}
}
break;
}
if ( V_153 )
{
V_12 = F_24 ( V_15 , V_16 , V_12 , V_153 ) ;
}
if ( V_160 % 8 )
{
V_41 V_161 = ( 8 - ( V_160 % 8 ) ) ;
F_5 ( V_16 , V_15 , V_12 , V_161 ,
L_14 , V_161 ) ;
V_12 += V_161 ;
}
return V_12 ;
}
T_1 F_26 (
T_3 * V_15 , T_4 * V_16 , T_1 V_12 )
{
T_5 * V_153 = 0 ;
if ( V_162 == V_163 )
V_153 = V_8 ;
if ( V_153 )
{
V_12 = F_24 ( V_15 , V_16 , V_12 , V_153 ) ;
}
return V_12 ;
}
