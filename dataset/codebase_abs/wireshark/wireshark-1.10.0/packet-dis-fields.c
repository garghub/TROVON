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
}
static T_1 F_3 ( T_1 V_15 , T_2 V_16 )
{
T_1 V_17 = V_15 % V_16 ;
if ( V_17 != 0 )
{
V_15 += V_16 - V_17 ;
}
return V_15 ;
}
T_1 F_4 ( T_3 * V_18 , T_4 * V_19 , T_1 V_15 , T_5 V_20 , T_2 V_21 )
{
F_5 ( V_19 , V_18 , V_15 , V_21 , L_1 ,
V_20 . V_22 , V_21 ) ;
V_15 += V_21 ;
return V_15 ;
}
T_1 F_6 ( T_3 * V_18 , T_4 * V_19 , T_1 V_15 , T_5 V_20 , T_2 V_21 )
{
T_6 * V_23 = 0 ;
T_7 V_24 = 0 ;
V_15 = F_3 ( V_15 , V_21 ) ;
switch( V_21 )
{
case 1 :
V_24 = F_7 ( V_18 , V_15 ) ;
break;
case 2 :
V_24 = F_8 ( V_18 , V_15 ) ;
break;
case 4 :
V_24 = F_9 ( V_18 , V_15 ) ;
break;
case 8 :
V_24 = F_10 ( V_18 , V_15 ) ;
break;
default:
break;
}
switch( V_20 . V_25 )
{
case V_26 :
if ( ( V_27 == V_28 ) &&
( V_29 == V_30 ) )
{
V_23 = V_31 ;
}
else if ( V_27 == V_32 )
{
V_23 = V_33 ;
}
break;
default:
break;
}
if ( V_23 != 0 )
{
int V_34 = 0 ;
while ( V_23 [ V_34 ] . V_35 != 0 )
{
int V_36 = 0 ;
T_8 * V_37 = V_23 [ V_34 ] . V_38 ;
while ( V_37 [ V_36 ] . V_39 != 0 )
{
if ( ( ( V_23 [ V_34 ] . V_35 & V_24 ) >> V_23 [ V_34 ] . V_40 ) ==
V_37 [ V_36 ] . V_41 )
{
F_5 ( V_19 , V_18 , V_15 , V_21 ,
L_2 , V_23 [ V_34 ] . V_39 ,
V_37 [ V_36 ] . V_39 ) ;
break;
}
++ V_36 ;
}
++ V_34 ;
}
}
else
{
F_5 ( V_19 , V_18 , V_15 , V_21 ,
L_3 V_42 L_4 , V_24 ) ;
}
V_15 += V_21 ;
return V_15 ;
}
T_1 F_11 ( T_3 * V_18 , T_4 * V_19 , T_1 V_15 , T_5 V_20 , T_2 V_21 )
{
T_7 V_24 = 0 ;
V_15 = F_3 ( V_15 , V_21 ) ;
switch( V_21 )
{
case 1 :
V_24 = F_7 ( V_18 , V_15 ) ;
break;
case 2 :
V_24 = F_8 ( V_18 , V_15 ) ;
break;
case 4 :
V_24 = F_9 ( V_18 , V_15 ) ;
break;
case 8 :
V_24 = F_10 ( V_18 , V_15 ) ;
break;
default:
break;
}
F_5 ( V_19 , V_18 , V_15 , V_21 , L_5 V_42 L_6 ,
V_20 . V_22 , V_24 ) ;
if ( V_20 . V_43 != 0 )
{
* ( V_20 . V_43 ) = ( V_44 ) V_24 ;
}
V_15 += V_21 ;
return V_15 ;
}
T_1 F_12 ( T_3 * V_18 , T_4 * V_19 , T_1 V_15 , T_5 V_20 , T_2 V_21 )
{
T_9 V_45 = 0 ;
V_15 = F_3 ( V_15 , V_21 ) ;
switch( V_21 )
{
case 1 :
V_45 = ( V_46 ) F_7 ( V_18 , V_15 ) ;
break;
case 2 :
V_45 = ( V_47 ) F_8 ( V_18 , V_15 ) ;
break;
case 4 :
V_45 = ( V_48 ) F_9 ( V_18 , V_15 ) ;
break;
case 8 :
V_45 = ( T_9 ) F_10 ( V_18 , V_15 ) ;
break;
default:
break;
}
F_5 ( V_19 , V_18 , V_15 , V_21 , L_5 V_42 L_7 ,
V_20 . V_22 , V_45 ) ;
V_15 += V_21 ;
return V_15 ;
}
T_1 F_13 ( T_3 * V_18 , T_4 * V_19 , T_1 V_15 , T_5 V_20 V_49 , T_2 V_21 )
{
F_5 ( V_19 , V_18 , V_15 , V_21 ,
L_8 , V_21 ) ;
V_15 += V_21 ;
return V_15 ;
}
T_1 F_14 ( T_3 * V_18 , T_4 * V_19 , T_1 V_15 , T_5 V_20 , T_2 V_21 )
{
const T_10 * V_50 = 0 ;
V_44 V_51 = 0 ;
const T_11 * V_52 = 0 ;
#if 0
proto_item *pi;
#endif
int V_53 = - 1 ;
V_15 = F_3 ( V_15 , V_21 ) ;
switch( V_20 . V_25 )
{
case V_54 :
V_50 = V_55 ;
break;
case V_56 :
V_50 = V_57 ;
break;
case V_58 :
V_50 = V_59 ;
break;
case V_60 :
V_50 = V_61 ;
break;
case V_62 :
V_50 = V_63 ;
break;
case V_64 :
V_50 = V_65 ;
break;
case V_66 :
V_50 = V_67 ;
V_53 = V_68 ;
break;
case V_69 :
V_50 = V_70 ;
V_53 = V_71 ;
break;
case V_72 :
V_50 = V_73 ;
V_53 = V_74 ;
break;
case V_75 :
V_50 = V_76 ;
V_53 = V_77 ;
break;
case V_78 :
V_50 = V_79 ;
V_53 = V_80 ;
break;
case V_81 :
V_50 = V_82 ;
break;
case V_83 :
V_50 = V_84 ;
break;
case V_85 :
V_50 = V_86 ;
V_53 = V_87 ;
break;
case V_88 :
V_50 = V_89 ;
break;
case V_90 :
V_50 = V_91 ;
break;
case V_92 :
if ( V_27 == V_28 )
{
switch( V_29 )
{
case V_30 :
V_50 = V_93 ;
V_53 = V_94 ;
break;
case V_95 :
V_50 = V_96 ;
V_53 = V_97 ;
break;
case V_98 :
V_50 = V_99 ;
V_53 = V_100 ;
break;
case V_101 :
V_50 = V_102 ;
V_53 = V_103 ;
break;
case V_104 :
V_50 = V_105 ;
V_53 = V_106 ;
break;
default:
V_50 = 0 ;
break;
}
}
break;
case V_107 :
V_50 = V_108 ;
V_53 = V_109 ;
break;
case V_110 :
V_50 = V_111 ;
V_53 = V_112 ;
break;
case V_113 :
V_50 = V_114 ;
V_53 = V_115 ;
break;
case V_116 :
V_50 = V_117 ;
break;
case V_118 :
V_50 = V_119 ;
break;
case V_120 :
V_50 = V_121 ;
break;
case V_122 :
V_50 = V_123 ;
break;
case V_124 :
V_50 = V_125 ;
break;
case V_126 :
V_50 = V_127 ;
break;
case V_128 :
V_50 = V_129 ;
break;
case V_130 :
switch ( V_131 ) {
case V_132 :
V_50 = V_133 ;
break;
case V_134 :
V_50 = V_135 ;
break;
case V_136 :
V_50 = V_137 ;
break;
case V_138 :
V_50 = V_139 ;
break;
case V_140 :
V_50 = V_141 ;
break;
case V_142 :
V_50 = V_143 ;
break;
case V_144 :
case V_145 :
default:
V_50 = V_146 ;
break;
}
break;
default:
V_50 = 0 ;
break;
}
switch( V_21 )
{
case 1 :
V_51 = F_7 ( V_18 , V_15 ) ;
break;
case 2 :
V_51 = F_8 ( V_18 , V_15 ) ;
break;
case 4 :
V_51 = F_9 ( V_18 , V_15 ) ;
break;
default:
break;
}
V_52 = F_15 ( V_51 , V_50 , L_9 ) ;
if ( V_53 != - 1 ) {
#if 0
pi = proto_tree_add_item(tree, dis_hf_id, tvb, offset, numBytes, ENC_BIG_ENDIAN);
proto_item_set_text(pi, "%s = %s", parserNode.fieldLabel, enumStr);
#else
F_16 ( V_19 , V_53 , V_18 , V_15 , V_21 , V_147 ) ;
#endif
}
else {
F_5 ( V_19 , V_18 , V_15 , V_21 , L_2 ,
V_20 . V_22 , V_52 ) ;
}
if ( V_20 . V_43 != 0 )
{
* ( V_20 . V_43 ) = V_51 ;
}
V_15 += V_21 ;
return V_15 ;
}
T_1 F_17 ( T_3 * V_18 , T_4 * V_19 , T_1 V_15 , T_5 V_20 )
{
T_12 V_148 ;
V_15 = F_3 ( V_15 , 4 ) ;
V_148 = F_18 ( V_18 , V_15 ) ;
F_5 ( V_19 , V_18 , V_15 , 4 , L_10 ,
V_20 . V_22 , V_148 ) ;
V_15 += 4 ;
return V_15 ;
}
T_1 F_19 ( T_3 * V_18 , T_4 * V_19 , T_1 V_15 , T_5 V_20 )
{
T_13 V_149 ;
V_15 = F_3 ( V_15 , 8 ) ;
V_149 = F_20 ( V_18 , V_15 ) ;
F_5 ( V_19 , V_18 , V_15 , 8 , L_10 ,
V_20 . V_22 , V_149 ) ;
V_15 += 8 ;
return V_15 ;
}
T_1 F_21 ( T_3 * V_18 , T_4 * V_19 , T_1 V_15 , T_5 V_20 )
{
static double V_150 = 1000.0 ;
static double V_151 = 60.0 * 1000.0 ;
static double V_152 = 60.0 * 60.0 * 1000.0 ;
static double V_153 = 0x7fffffff ;
T_2 V_154 = 0 ;
V_44 V_24 ;
T_2 V_155 ;
T_2 V_156 ;
T_2 V_157 ;
double V_158 ;
V_15 = F_3 ( V_15 , 4 ) ;
V_24 = F_9 ( V_18 , V_15 ) ;
if( V_24 & 1 )
V_154 = 1 ;
V_158 = ( V_24 >> 1 ) * V_152 / V_153 ;
V_158 += 0.5 ;
V_155 = ( T_2 ) ( V_158 / V_151 ) ;
V_158 -= ( V_155 * V_151 ) ;
V_156 = ( T_2 ) ( V_158 / V_150 ) ;
V_158 -= ( V_156 * V_150 ) ;
V_157 = ( T_2 ) V_158 ;
if( V_154 )
{
F_5 ( V_19 , V_18 , V_15 , 4 , L_11 ,
V_20 . V_22 , V_155 , V_156 , V_157 ) ;
}
else
{
F_5 ( V_19 , V_18 , V_15 , 4 , L_12 ,
V_20 . V_22 , V_155 , V_156 , V_157 ) ;
}
V_15 += 4 ;
return V_15 ;
}
T_1 F_22 ( T_3 * V_18 , T_4 * V_19 , T_1 V_15 )
{
T_5 * V_159 = 0 ;
switch ( V_160 ) {
case V_161 :
V_159 = V_2 ;
break;
case V_162 :
V_159 = V_3 ;
break;
case V_163 :
V_159 = V_4 ;
break;
default:
V_159 = V_1 ;
break;
}
if ( V_159 )
{
V_15 = F_23 ( V_18 , V_19 , V_15 , V_159 ) ;
}
return V_15 ;
}
T_1 F_24 ( T_3 * V_18 , T_4 * V_19 , T_1 V_15 )
{
T_5 * V_159 = 0 ;
switch ( V_164 ) {
case 47200 :
V_159 = V_5 ;
break;
case 47300 :
V_159 = V_6 ;
break;
case 47600 :
V_159 = V_7 ;
break;
default:
{
V_44 V_165 = V_166 - 6 ;
if ( V_165 > 0 )
{
F_5 ( V_19 , V_18 , V_15 , V_165 ,
L_13 , V_165 ) ;
V_15 += V_165 ;
}
}
break;
}
if ( V_159 )
{
V_15 = F_23 ( V_18 , V_19 , V_15 , V_159 ) ;
}
if ( V_166 % 8 )
{
V_44 V_167 = ( 8 - ( V_166 % 8 ) ) ;
F_5 ( V_19 , V_18 , V_15 , V_167 ,
L_14 , V_167 ) ;
V_15 += V_167 ;
}
return V_15 ;
}
T_1 F_25 (
T_3 * V_18 , T_4 * V_19 , T_1 V_15 )
{
T_5 * V_159 = 0 ;
if ( V_168 == V_169 )
V_159 = V_8 ;
if ( V_159 )
{
V_15 = F_23 ( V_18 , V_19 , V_15 , V_159 ) ;
}
return V_15 ;
}
