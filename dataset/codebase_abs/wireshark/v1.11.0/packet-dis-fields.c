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
F_2 ( V_12 ) ;
F_2 ( V_13 ) ;
F_2 ( V_14 ) ;
F_2 ( V_15 ) ;
}
static T_1 F_3 ( T_1 V_16 , T_2 V_17 )
{
T_1 V_18 = V_16 % V_17 ;
if ( V_18 != 0 )
{
V_16 += V_17 - V_18 ;
}
return V_16 ;
}
T_1 F_4 ( T_3 * V_19 , T_4 * V_20 , T_1 V_16 , T_5 V_21 , T_2 V_22 )
{
F_5 ( V_20 , V_19 , V_16 , V_22 , L_1 ,
V_21 . V_23 , V_22 ) ;
V_16 += V_22 ;
return V_16 ;
}
T_1 F_6 ( T_3 * V_19 , T_4 * V_20 , T_1 V_16 , T_5 V_21 , T_2 V_22 )
{
T_6 * V_24 = 0 ;
T_7 V_25 = 0 ;
V_16 = F_3 ( V_16 , V_22 ) ;
switch( V_22 )
{
case 1 :
V_25 = F_7 ( V_19 , V_16 ) ;
break;
case 2 :
V_25 = F_8 ( V_19 , V_16 ) ;
break;
case 4 :
V_25 = F_9 ( V_19 , V_16 ) ;
break;
case 8 :
V_25 = F_10 ( V_19 , V_16 ) ;
break;
default:
break;
}
switch( V_21 . V_26 )
{
case V_27 :
if ( ( V_28 == V_29 ) &&
( V_30 == V_31 ) )
{
V_24 = V_32 ;
}
else if ( V_28 == V_33 )
{
V_24 = V_34 ;
}
break;
default:
break;
}
if ( V_24 != 0 )
{
int V_35 = 0 ;
while ( V_24 [ V_35 ] . V_36 != 0 )
{
int V_37 = 0 ;
T_8 * V_38 = V_24 [ V_35 ] . V_39 ;
while ( V_38 [ V_37 ] . V_40 != 0 )
{
if ( ( ( V_24 [ V_35 ] . V_36 & V_25 ) >> V_24 [ V_35 ] . V_41 ) ==
V_38 [ V_37 ] . V_42 )
{
F_5 ( V_20 , V_19 , V_16 , V_22 ,
L_2 , V_24 [ V_35 ] . V_40 ,
V_38 [ V_37 ] . V_40 ) ;
break;
}
++ V_37 ;
}
++ V_35 ;
}
}
else
{
F_5 ( V_20 , V_19 , V_16 , V_22 ,
L_3 V_43 L_4 , V_25 ) ;
}
V_16 += V_22 ;
return V_16 ;
}
T_1 F_11 ( T_3 * V_19 , T_4 * V_20 , T_1 V_16 , T_5 V_21 , T_2 V_22 )
{
T_7 V_25 = 0 ;
V_16 = F_3 ( V_16 , V_22 ) ;
switch( V_22 )
{
case 1 :
V_25 = F_7 ( V_19 , V_16 ) ;
break;
case 2 :
V_25 = F_8 ( V_19 , V_16 ) ;
break;
case 4 :
V_25 = F_9 ( V_19 , V_16 ) ;
break;
case 8 :
V_25 = F_10 ( V_19 , V_16 ) ;
break;
default:
break;
}
F_5 ( V_20 , V_19 , V_16 , V_22 , L_5 V_43 L_6 ,
V_21 . V_23 , V_25 ) ;
if ( V_21 . V_44 != 0 )
{
* ( V_21 . V_44 ) = ( V_45 ) V_25 ;
}
V_16 += V_22 ;
return V_16 ;
}
T_1 F_12 ( T_3 * V_19 , T_4 * V_20 , T_1 V_16 , T_5 V_21 , T_2 V_22 )
{
T_9 V_46 = 0 ;
V_16 = F_3 ( V_16 , V_22 ) ;
switch( V_22 )
{
case 1 :
V_46 = ( V_47 ) F_7 ( V_19 , V_16 ) ;
break;
case 2 :
V_46 = ( V_48 ) F_8 ( V_19 , V_16 ) ;
break;
case 4 :
V_46 = ( V_49 ) F_9 ( V_19 , V_16 ) ;
break;
case 8 :
V_46 = ( T_9 ) F_10 ( V_19 , V_16 ) ;
break;
default:
break;
}
F_5 ( V_20 , V_19 , V_16 , V_22 , L_5 V_43 L_7 ,
V_21 . V_23 , V_46 ) ;
V_16 += V_22 ;
return V_16 ;
}
T_1 F_13 ( T_3 * V_19 , T_4 * V_20 , T_1 V_16 , T_5 V_21 V_50 , T_2 V_22 )
{
F_5 ( V_20 , V_19 , V_16 , V_22 ,
L_8 , V_22 ) ;
V_16 += V_22 ;
return V_16 ;
}
T_1 F_14 ( T_3 * V_19 , T_4 * V_20 , T_1 V_16 , T_5 V_21 , T_2 V_22 )
{
const T_10 * V_51 = 0 ;
V_45 V_52 = 0 ;
const T_11 * V_53 = 0 ;
#if 0
proto_item *pi;
#endif
int V_54 = - 1 ;
V_16 = F_3 ( V_16 , V_22 ) ;
switch( V_21 . V_26 )
{
case V_55 :
V_51 = V_56 ;
break;
case V_57 :
V_51 = V_58 ;
break;
case V_59 :
V_51 = V_60 ;
break;
case V_61 :
V_51 = V_62 ;
break;
case V_63 :
V_51 = V_64 ;
break;
case V_65 :
V_51 = V_66 ;
break;
case V_67 :
V_51 = V_68 ;
V_54 = V_69 ;
break;
case V_70 :
V_51 = V_71 ;
V_54 = V_72 ;
break;
case V_73 :
V_51 = V_74 ;
V_54 = V_75 ;
break;
case V_76 :
V_51 = V_77 ;
V_54 = V_78 ;
break;
case V_79 :
V_51 = V_80 ;
V_54 = V_81 ;
break;
case V_82 :
V_51 = V_83 ;
break;
case V_84 :
V_51 = V_85 ;
break;
case V_86 :
V_51 = V_87 ;
V_54 = V_88 ;
break;
case V_89 :
V_51 = V_90 ;
break;
case V_91 :
V_51 = V_92 ;
break;
case V_93 :
if ( V_28 == V_29 )
{
switch( V_30 )
{
case V_31 :
V_51 = V_94 ;
V_54 = V_95 ;
break;
case V_96 :
V_51 = V_97 ;
V_54 = V_98 ;
break;
case V_99 :
V_51 = V_100 ;
V_54 = V_101 ;
break;
case V_102 :
V_51 = V_103 ;
V_54 = V_104 ;
break;
case V_105 :
V_51 = V_106 ;
V_54 = V_107 ;
break;
default:
V_51 = 0 ;
break;
}
}
break;
case V_108 :
V_51 = V_109 ;
V_54 = V_110 ;
break;
case V_111 :
V_51 = V_112 ;
V_54 = V_113 ;
break;
case V_114 :
V_51 = V_115 ;
V_54 = V_116 ;
break;
case V_117 :
V_51 = V_118 ;
break;
case V_119 :
V_51 = V_120 ;
break;
case V_121 :
V_51 = V_122 ;
break;
case V_123 :
V_51 = V_124 ;
break;
case V_125 :
V_51 = V_126 ;
break;
case V_127 :
V_51 = V_128 ;
break;
case V_129 :
V_51 = V_130 ;
break;
case V_131 :
switch ( V_132 ) {
case V_133 :
V_51 = V_134 ;
break;
case V_135 :
V_51 = V_136 ;
break;
case V_137 :
V_51 = V_138 ;
break;
case V_139 :
V_51 = V_140 ;
break;
case V_141 :
V_51 = V_142 ;
break;
case V_143 :
V_51 = V_144 ;
break;
case V_145 :
case V_146 :
default:
V_51 = V_147 ;
break;
}
break;
default:
V_51 = 0 ;
break;
}
switch( V_22 )
{
case 1 :
V_52 = F_7 ( V_19 , V_16 ) ;
break;
case 2 :
V_52 = F_8 ( V_19 , V_16 ) ;
break;
case 4 :
V_52 = F_9 ( V_19 , V_16 ) ;
break;
default:
break;
}
V_53 = F_15 ( V_52 , V_51 , L_9 ) ;
if ( V_54 != - 1 ) {
#if 0
pi = proto_tree_add_item(tree, dis_hf_id, tvb, offset, numBytes, ENC_BIG_ENDIAN);
proto_item_set_text(pi, "%s = %s", parserNode.fieldLabel, enumStr);
#else
F_16 ( V_20 , V_54 , V_19 , V_16 , V_22 , V_148 ) ;
#endif
}
else {
F_5 ( V_20 , V_19 , V_16 , V_22 , L_2 ,
V_21 . V_23 , V_53 ) ;
}
if ( V_21 . V_44 != 0 )
{
* ( V_21 . V_44 ) = V_52 ;
}
V_16 += V_22 ;
return V_16 ;
}
T_1 F_17 ( T_3 * V_19 , T_4 * V_20 , T_1 V_16 , T_5 V_21 )
{
T_12 V_149 ;
V_16 = F_3 ( V_16 , 4 ) ;
V_149 = F_18 ( V_19 , V_16 ) ;
F_5 ( V_20 , V_19 , V_16 , 4 , L_10 ,
V_21 . V_23 , V_149 ) ;
V_16 += 4 ;
return V_16 ;
}
T_1 F_19 ( T_3 * V_19 , T_4 * V_20 , T_1 V_16 , T_5 V_21 )
{
T_13 V_150 ;
V_16 = F_3 ( V_16 , 8 ) ;
V_150 = F_20 ( V_19 , V_16 ) ;
F_5 ( V_20 , V_19 , V_16 , 8 , L_10 ,
V_21 . V_23 , V_150 ) ;
V_16 += 8 ;
return V_16 ;
}
T_1 F_21 ( T_3 * V_19 , T_4 * V_20 , T_1 V_16 , T_5 V_21 )
{
static double V_151 = 1000.0 ;
static double V_152 = 60.0 * 1000.0 ;
static double V_153 = 60.0 * 60.0 * 1000.0 ;
static double V_154 = 0x7fffffff ;
T_2 V_155 = 0 ;
V_45 V_25 ;
T_2 V_156 ;
T_2 V_157 ;
T_2 V_158 ;
double V_159 ;
V_16 = F_3 ( V_16 , 4 ) ;
V_25 = F_9 ( V_19 , V_16 ) ;
if( V_25 & 1 )
V_155 = 1 ;
V_159 = ( V_25 >> 1 ) * V_153 / V_154 ;
V_159 += 0.5 ;
V_156 = ( T_2 ) ( V_159 / V_152 ) ;
V_159 -= ( V_156 * V_152 ) ;
V_157 = ( T_2 ) ( V_159 / V_151 ) ;
V_159 -= ( V_157 * V_151 ) ;
V_158 = ( T_2 ) V_159 ;
if( V_155 )
{
F_5 ( V_20 , V_19 , V_16 , 4 , L_11 ,
V_21 . V_23 , V_156 , V_157 , V_158 ) ;
}
else
{
F_5 ( V_20 , V_19 , V_16 , 4 , L_12 ,
V_21 . V_23 , V_156 , V_157 , V_158 ) ;
}
V_16 += 4 ;
return V_16 ;
}
T_1 F_22 ( T_3 * V_19 , T_4 * V_20 , T_1 V_16 )
{
T_5 * V_160 = 0 ;
switch ( V_161 ) {
case V_162 :
V_160 = V_2 ;
break;
case V_163 :
V_160 = V_3 ;
break;
case V_164 :
V_160 = V_4 ;
break;
case V_165 :
V_160 = V_5 ;
break;
default:
V_160 = V_1 ;
break;
}
if ( V_160 )
{
V_16 = F_23 ( V_19 , V_20 , V_16 , V_160 ) ;
}
return V_16 ;
}
T_1 F_24 ( T_3 * V_19 , T_4 * V_20 , T_1 V_16 )
{
T_5 * V_160 = 0 ;
switch ( V_166 ) {
case 47200 :
V_160 = V_6 ;
break;
case 47300 :
V_160 = V_7 ;
break;
case 47600 :
V_160 = V_8 ;
break;
default:
{
V_45 V_167 = V_168 - 6 ;
if ( V_167 > 0 )
{
F_5 ( V_20 , V_19 , V_16 , V_167 ,
L_13 , V_167 ) ;
V_16 += V_167 ;
}
}
break;
}
if ( V_160 )
{
V_16 = F_23 ( V_19 , V_20 , V_16 , V_160 ) ;
}
if ( V_168 % 8 )
{
V_45 V_169 = ( 8 - ( V_168 % 8 ) ) ;
F_5 ( V_20 , V_19 , V_16 , V_169 ,
L_14 , V_169 ) ;
V_16 += V_169 ;
}
return V_16 ;
}
T_1 F_25 (
T_3 * V_19 , T_4 * V_20 , T_1 V_16 )
{
T_5 * V_160 = 0 ;
if ( V_170 == V_171 )
V_160 = V_9 ;
if ( V_160 )
{
V_16 = F_23 ( V_19 , V_20 , V_16 , V_160 ) ;
}
return V_16 ;
}
