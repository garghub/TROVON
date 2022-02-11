void F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 V_4 = 0 ;
T_4 V_5 , V_6 , V_7 ;
T_5 V_8 , V_9 , V_10 , V_11 ;
T_6 V_12 ;
V_6 = F_2 ( V_1 , V_4 ) ;
if( V_6 != V_13 )
{
return;
}
if( V_3 )
{
T_7 * V_14 ;
T_3 * V_15 ;
T_4 V_16 ;
T_4 V_17 ;
T_4 V_18 ;
T_4 V_19 ;
T_4 V_20 ;
V_5 = F_3 ( V_1 ) ;
V_14 = F_4 ( V_3 , V_21 , V_1 , V_4 , V_5 , L_1 , V_5 ) ;
V_15 = F_5 ( V_14 , V_22 ) ;
F_6 ( V_15 , V_23 , V_1 , V_4 , 1 , V_24 ) ;
V_4 ++ ;
V_16 = F_2 ( V_1 , V_4 ) ;
F_7 ( V_15 , V_1 , V_4 , 1 , L_2 , V_16 ) ;
V_4 ++ ;
V_17 = F_2 ( V_1 , V_4 ) ;
F_7 ( V_15 , V_1 , V_4 , 1 , L_3 , V_17 , ( 1 << V_17 ) ) ;
V_4 ++ ;
V_18 = F_2 ( V_1 , V_4 ) ;
F_7 ( V_15 , V_1 , V_4 , 1 , L_4 , V_18 , ( 1 << V_18 ) ) ;
V_4 ++ ;
V_19 = F_2 ( V_1 , V_4 ) ;
F_7 ( V_15 , V_1 , V_4 , 1 , L_5 , V_19 , ( 1 << V_19 ) ) ;
V_4 ++ ;
V_20 = F_2 ( V_1 , V_4 ) ;
F_7 ( V_15 , V_1 , V_4 , 1 , L_6 , V_20 , ( 1 << V_20 ) ) ;
V_4 ++ ;
while( V_4 < V_5 )
{
F_8 ( & V_12 , V_1 , V_4 ) ;
V_8 = F_9 ( & V_12 ) ;
V_9 = F_10 ( & V_12 ) ;
if( V_8 == - 1 || V_9 > V_25 || V_9 < 1 )
{
F_11 ( V_2 -> V_26 , V_27 , NULL , L_7 ) ;
F_6 ( V_15 , V_28 , V_1 , V_4 , ( V_5 - V_4 ) , V_29 ) ;
break;
}
V_11 = F_12 ( & V_12 ) ;
#ifdef F_13
F_4 ( V_15 , V_21 , V_1 , V_4 , ( V_9 + V_11 ) , L_8 , V_8 , V_9 , V_4 , V_5 ) ;
#endif
V_4 += V_11 ;
if ( V_30 )
{
switch ( V_8 )
{
T_3 * V_31 ;
case V_32 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_33 , V_1 , V_4 , V_9 , FALSE ) ;
F_6 ( V_31 , V_33 , V_1 , V_4 , V_9 , V_24 ) ;
break;
}
case V_34 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_35 , V_1 , V_4 , V_9 , FALSE ) ;
F_6 ( V_31 , V_35 , V_1 , V_4 , V_9 , V_24 ) ;
break;
}
case V_36 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_37 , V_1 , V_4 , V_9 , FALSE ) ;
F_6 ( V_31 , V_37 , V_1 , V_4 , V_9 , V_24 ) ;
break;
}
case V_38 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_39 , V_1 , V_4 , V_9 , FALSE ) ;
F_6 ( V_31 , V_39 , V_1 , V_4 , V_9 , V_24 ) ;
break;
}
case V_40 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_41 , V_1 , V_4 , V_9 , FALSE ) ;
F_6 ( V_31 , V_41 , V_1 , V_4 , V_9 , V_29 ) ;
break;
}
case V_42 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_43 , V_1 , V_4 , V_9 , FALSE ) ;
F_6 ( V_31 , V_43 , V_1 , V_4 , V_9 , V_29 ) ;
break;
}
case V_44 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_45 , V_1 , V_4 , V_9 , FALSE ) ;
F_6 ( V_31 , V_45 , V_1 , V_4 , V_9 , V_29 ) ;
break;
}
case V_46 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_47 , V_1 , V_4 , V_9 , FALSE ) ;
F_6 ( V_31 , V_47 , V_1 , V_4 , V_9 , V_29 ) ;
break;
}
}
}
switch ( V_8 )
{
T_3 * V_31 ;
T_7 * V_48 ;
T_4 V_49 ;
T_4 V_50 ;
case V_51 :
{
V_49 = F_2 ( V_1 , V_4 ) & 0x0F ;
V_31 = F_15 ( & V_12 , V_22 , V_15 , V_21 , V_1 , V_4 , V_9 , L_9 , V_49 , V_9 ) ;
F_6 ( V_31 , V_52 , V_1 , V_4 , 1 , V_24 ) ;
F_6 ( V_31 , V_53 , V_1 , V_4 , 1 , V_24 ) ;
for ( V_10 = 1 ; V_10 < V_9 ; )
{
F_8 ( & V_12 , V_1 , ( V_4 + V_10 ) ) ;
V_8 = F_9 ( & V_12 ) ;
if( V_8 == - 1 )
{
F_11 ( V_2 -> V_26 , V_27 , NULL , L_10 ) ;
F_6 ( V_31 , V_28 , V_1 , V_4 , ( V_9 - V_4 - V_10 ) , V_29 ) ;
break;
}
V_7 = F_10 ( & V_12 ) ;
V_10 += F_12 ( & V_12 ) ;
switch ( V_8 )
{
T_3 * V_54 ;
T_7 * V_55 ;
case V_56 :
{
V_54 = F_14 ( & V_12 , V_22 , V_31 , V_57 , V_1 , ( V_4 + V_10 ) , 1 , FALSE ) ;
F_6 ( V_54 , V_57 , V_1 , ( V_4 + V_10 ) , 1 , V_24 ) ;
break;
}
case V_58 :
{
V_54 = F_14 ( & V_12 , V_22 , V_31 , V_59 , V_1 , ( V_4 + V_10 ) , 1 , FALSE ) ;
V_55 = F_6 ( V_54 , V_59 , V_1 , ( V_4 + V_10 ) , 1 , V_24 ) ;
F_16 ( V_55 , L_11 ) ;
break;
}
#if 0
case UCD_BURST_POWER_BOOST:
{
sub_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, tlv_tree, hf_ucd_burst_power_boost, tvb, (offset+tlv_offset), 1, FALSE);
tlv_item2 = proto_tree_add_item(sub_tree, hf_ucd_burst_power_boost, tvb, (offset+tlv_offset), length, ENC_BIG_ENDIAN);
proto_item_append_text(tlv_item2, " dB");
break;
}
case UCD_BURST_TCS_ENABLE:
{
sub_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, tlv_tree, hf_ucd_burst_tcs_enable, tvb, (offset+tlv_offset), 1, FALSE);
proto_tree_add_item(sub_tree, hf_ucd_burst_tcs_enable, tvb, (offset+tlv_offset), 1, ENC_BIG_ENDIAN);
break;
}
#endif
default:
break;
}
V_10 += V_7 ;
}
break;
}
case V_60 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_61 , V_1 , V_4 , V_9 , FALSE ) ;
F_6 ( V_31 , V_61 , V_1 , V_4 , V_9 , V_24 ) ;
break;
}
case V_62 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_63 , V_1 , V_4 , V_9 , FALSE ) ;
V_48 = F_6 ( V_31 , V_63 , V_1 , V_4 , V_9 , V_24 ) ;
F_16 ( V_48 , L_12 ) ;
break;
}
case V_64 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_65 , V_1 , V_4 , V_9 , FALSE ) ;
V_48 = F_6 ( V_31 , V_65 , V_1 , V_4 , V_9 , V_24 ) ;
F_16 ( V_48 , L_12 ) ;
break;
}
case V_66 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_67 , V_1 , V_4 , V_9 , FALSE ) ;
V_48 = F_6 ( V_31 , V_67 , V_1 , V_4 , V_9 , V_24 ) ;
F_16 ( V_48 , L_13 ) ;
break;
}
case V_68 :
{
V_31 = F_15 ( & V_12 , V_22 , V_15 , V_21 , V_1 , V_4 , V_9 , L_14 , V_9 ) ;
V_50 = F_2 ( V_1 , V_4 ) ;
F_7 ( V_31 , V_1 , V_4 , V_5 , L_15 , V_50 , ( 1 << V_50 ) ) ;
break;
}
case V_69 :
{
V_31 = F_15 ( & V_12 , V_22 , V_15 , V_21 , V_1 , V_4 , V_9 , L_16 , V_9 ) ;
V_50 = F_2 ( V_1 , V_4 ) ;
F_7 ( V_31 , V_1 , V_4 , V_5 , L_17 , V_50 , ( 1 << V_50 ) ) ;
break;
}
case V_70 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_71 , V_1 , V_4 , V_9 , FALSE ) ;
F_6 ( V_31 , V_71 , V_1 , V_4 , V_9 , V_29 ) ;
break;
}
case V_72 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_73 , V_1 , V_4 , V_9 , FALSE ) ;
V_48 = F_6 ( V_31 , V_73 , V_1 , V_4 , V_9 , V_24 ) ;
F_16 ( V_48 , L_11 ) ;
break;
}
case V_74 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_75 , V_1 , V_4 , V_9 , FALSE ) ;
V_48 = F_6 ( V_31 , V_75 , V_1 , V_4 , V_9 , V_24 ) ;
F_16 ( V_48 , L_11 ) ;
break;
}
case V_76 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_77 , V_1 , V_4 , V_9 , FALSE ) ;
V_48 = F_6 ( V_31 , V_77 , V_1 , V_4 , V_9 , V_24 ) ;
F_16 ( V_48 , L_18 ) ;
break;
}
case V_78 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_77 , V_1 , V_4 , V_9 , FALSE ) ;
V_48 = F_6 ( V_31 , V_79 , V_1 , V_4 , V_9 , V_24 ) ;
F_16 ( V_48 , L_18 ) ;
break;
}
case V_80 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_81 , V_1 , V_4 , V_9 , FALSE ) ;
V_48 = F_6 ( V_31 , V_81 , V_1 , V_4 , V_9 , V_24 ) ;
F_16 ( V_48 , L_18 ) ;
break;
}
case V_82 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_83 , V_1 , V_4 , V_9 , FALSE ) ;
V_48 = F_6 ( V_31 , V_83 , V_1 , V_4 , V_9 , V_24 ) ;
F_16 ( V_48 , L_18 ) ;
break;
}
case V_84 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_85 , V_1 , V_4 , V_9 , FALSE ) ;
V_48 = F_6 ( V_31 , V_85 , V_1 , V_4 , V_9 , V_24 ) ;
F_16 ( V_48 , L_18 ) ;
break;
}
case V_86 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_87 , V_1 , V_4 , V_9 , FALSE ) ;
V_48 = F_6 ( V_31 , V_87 , V_1 , V_4 , V_9 , V_24 ) ;
F_16 ( V_48 , L_19 ) ;
break;
}
case V_88 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_89 , V_1 , V_4 , V_9 , FALSE ) ;
V_48 = F_6 ( V_31 , V_89 , V_1 , V_4 , V_9 , V_24 ) ;
F_16 ( V_48 , L_18 ) ;
break;
}
case V_90 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_91 , V_1 , V_4 , V_9 , FALSE ) ;
F_6 ( V_31 , V_91 , V_1 , V_4 , V_9 , V_24 ) ;
break;
}
case V_92 :
{
V_50 = F_2 ( V_1 , V_4 ) ;
V_93 = 0 ;
if ( V_50 && V_50 < 8 ) {
V_93 = V_50 + 2 ;
}
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_94 , V_1 , V_4 , V_9 , FALSE ) ;
F_6 ( V_31 , V_94 , V_1 , V_4 , V_9 , V_24 ) ;
break;
}
case V_95 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_96 , V_1 , V_4 , V_9 , FALSE ) ;
F_6 ( V_31 , V_97 , V_1 , V_4 + 2 , 1 , V_24 ) ;
F_6 ( V_31 , V_98 , V_1 , V_4 + 3 , 7 , V_99 | V_29 ) ;
break;
}
case V_100 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_101 , V_1 , V_4 , V_9 , FALSE ) ;
F_6 ( V_31 , V_101 , V_1 , V_4 , V_9 , V_24 ) ;
break;
}
case V_102 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_103 , V_1 , V_4 , V_9 , FALSE ) ;
F_6 ( V_31 , V_103 , V_1 , V_4 , V_9 , V_24 ) ;
break;
}
case V_104 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_105 , V_1 , V_4 , V_9 , FALSE ) ;
F_6 ( V_31 , V_105 , V_1 , V_4 , V_9 , V_24 ) ;
break;
}
case V_106 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_107 , V_1 , V_4 , V_9 , FALSE ) ;
F_6 ( V_31 , V_107 , V_1 , V_4 , V_9 , V_24 ) ;
break;
}
case V_108 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_109 , V_1 , V_4 , V_9 , FALSE ) ;
F_6 ( V_31 , V_109 , V_1 , V_4 , V_9 , V_24 ) ;
break;
}
case V_110 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_111 , V_1 , V_4 , V_9 , FALSE ) ;
F_6 ( V_31 , V_111 , V_1 , V_4 , V_9 , V_24 ) ;
break;
}
case V_112 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_113 , V_1 , V_4 , V_9 , FALSE ) ;
F_6 ( V_31 , V_113 , V_1 , V_4 , V_9 , V_24 ) ;
break;
}
case V_114 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_115 , V_1 , V_4 , V_9 , FALSE ) ;
F_6 ( V_31 , V_115 , V_1 , V_4 , V_9 , V_24 ) ;
break;
}
case V_116 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_117 , V_1 , V_4 , V_9 , FALSE ) ;
F_6 ( V_31 , V_117 , V_1 , V_4 , V_9 , V_24 ) ;
break;
}
case V_118 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_119 , V_1 , V_4 , V_9 , FALSE ) ;
F_6 ( V_31 , V_119 , V_1 , V_4 , V_9 , V_24 ) ;
break;
}
case V_120 :
{
V_31 = F_15 ( & V_12 , V_22 , V_15 , V_21 , V_1 , V_4 , V_9 , L_20 , V_9 ) ;
F_6 ( V_31 , V_121 , V_1 , V_4 , 1 , V_24 ) ;
F_6 ( V_31 , V_122 , V_1 , V_4 , 1 , V_24 ) ;
F_6 ( V_31 , V_123 , V_1 , ( V_4 + 1 ) , 1 , V_24 ) ;
F_6 ( V_31 , V_124 , V_1 , ( V_4 + 1 ) , 1 , V_24 ) ;
F_6 ( V_31 , V_125 , V_1 , ( V_4 + 2 ) , 1 , V_24 ) ;
F_6 ( V_31 , V_126 , V_1 , ( V_4 + 2 ) , 1 , V_24 ) ;
break;
}
case V_127 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_119 , V_1 , V_4 , V_9 , FALSE ) ;
F_6 ( V_31 , V_128 , V_1 , V_4 , V_9 , V_24 ) ;
break;
}
case V_129 :
{
V_31 = F_15 ( & V_12 , V_22 , V_15 , V_21 , V_1 , V_4 , V_9 , L_21 , V_9 ) ;
V_50 = F_2 ( V_1 , V_4 ) ;
F_7 ( V_31 , V_1 , V_4 , V_5 , L_22 , V_50 , ( 1 << V_50 ) ) ;
break;
}
case V_130 :
{
V_31 = F_15 ( & V_12 , V_22 , V_15 , V_21 , V_1 , V_4 , V_9 , L_23 , V_9 ) ;
V_50 = F_2 ( V_1 , V_4 ) ;
F_7 ( V_31 , V_1 , V_4 , V_5 , L_24 , V_50 , ( 1 << V_50 ) ) ;
break;
}
case V_131 :
{
V_31 = F_15 ( & V_12 , V_22 , V_15 , V_21 , V_1 , V_4 , V_9 , L_25 , V_9 ) ;
V_50 = F_2 ( V_1 , V_4 ) ;
F_7 ( V_31 , V_1 , V_4 , V_5 , L_26 , V_50 , ( 1 << V_50 ) ) ;
break;
}
case V_132 :
{
V_31 = F_15 ( & V_12 , V_22 , V_15 , V_21 , V_1 , V_4 , V_9 , L_27 , V_9 ) ;
V_50 = F_2 ( V_1 , V_4 ) ;
F_7 ( V_31 , V_1 , V_4 , V_5 , L_28 , V_50 , ( 1 << V_50 ) ) ;
break;
}
case V_133 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_134 , V_1 , V_4 , V_9 , FALSE ) ;
F_6 ( V_31 , V_134 , V_1 , V_4 , V_9 , V_24 ) ;
break;
}
case V_135 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_136 , V_1 , V_4 , V_9 , FALSE ) ;
F_6 ( V_31 , V_136 , V_1 , V_4 , V_9 , V_24 ) ;
break;
}
case V_137 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_138 , V_1 , V_4 , V_9 , FALSE ) ;
F_6 ( V_31 , V_138 , V_1 , V_4 , V_9 , V_24 ) ;
break;
}
case V_139 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_140 , V_1 , V_4 , V_9 , FALSE ) ;
F_6 ( V_31 , V_140 , V_1 , V_4 , V_9 , V_24 ) ;
break;
}
case V_141 :
{
V_31 = F_15 ( & V_12 , V_22 , V_15 , V_21 , V_1 , V_4 , V_9 , L_29 , V_9 ) ;
V_50 = F_2 ( V_1 , V_4 ) ;
F_7 ( V_31 , V_1 , V_4 , V_9 , L_30 , V_50 , ( 1 << V_50 ) ) ;
break;
}
case V_142 :
{
V_31 = F_15 ( & V_12 , V_22 , V_15 , V_21 , V_1 , V_4 , V_9 , L_31 , V_9 ) ;
V_50 = F_2 ( V_1 , V_4 ) ;
F_7 ( V_31 , V_1 , V_4 , V_9 , L_32 , V_50 , ( 1 << V_50 ) ) ;
break;
}
case V_143 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_144 , V_1 , V_4 , V_9 , FALSE ) ;
F_6 ( V_31 , V_144 , V_1 , V_4 , V_9 , V_24 ) ;
break;
}
case V_145 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_146 , V_1 , V_4 , V_9 , FALSE ) ;
F_6 ( V_31 , V_146 , V_1 , V_4 , V_9 , V_24 ) ;
break;
}
case V_147 :
{
V_31 = F_14 ( & V_12 , V_22 , V_15 , V_148 , V_1 , V_4 , V_9 , FALSE ) ;
F_6 ( V_31 , V_148 , V_1 , V_4 , V_9 , V_29 ) ;
break;
}
case V_32 :
case V_34 :
case V_36 :
case V_38 :
case V_40 :
case V_42 :
case V_44 :
case V_46 :
{
if ( ! V_30 )
{
F_4 ( V_15 , V_21 , V_1 , V_4 , V_9 , L_33 ) ;
}
break;
}
default:
{
F_4 ( V_15 , V_21 , V_1 , V_4 , V_9 , L_33 ) ;
}
}
V_4 += V_9 ;
}
}
}
void F_17 ( void )
{
static T_8 V_149 [] =
{
{
& V_23 ,
{
L_34 , L_35 ,
V_150 , V_151 , NULL , 0 , NULL , V_152
}
} ,
{
& V_105 ,
{
L_36 , L_37 ,
V_153 , V_151 , F_18 ( V_154 ) , 0 , NULL , V_152
}
} ,
{
& V_73 ,
{
L_38 , L_39 ,
V_150 , V_155 , NULL , 0 , NULL , V_152
}
} ,
{
& V_77 ,
{
L_40 , L_41 ,
V_150 , V_155 , NULL , 0 , NULL , V_152
}
} ,
{
& V_75 ,
{
L_42 , L_43 ,
V_150 , V_155 , NULL , 0 , NULL , V_152
}
} ,
{
& V_79 ,
{
L_44 , L_45 ,
V_150 , V_155 , NULL , 0 , NULL , V_152
}
} ,
{
& V_83 ,
{
L_46 , L_47 ,
V_150 , V_155 , NULL , 0 , NULL , V_152
}
} ,
{
& V_81 ,
{
L_48 , L_49 ,
V_150 , V_151 , NULL , 0 , NULL , V_152
}
} ,
{
& V_140 ,
{
L_50 , L_51 ,
V_150 , V_155 , NULL , 0 , NULL , V_152
}
} ,
{
& V_57 ,
{
L_52 , L_53 ,
V_150 , V_155 , F_18 ( V_156 ) , 0 , NULL , V_152
}
} ,
{
& V_59 ,
{
L_54 , L_55 ,
V_150 , V_151 , NULL , 0 , NULL , V_152
}
} ,
{
& V_52 ,
{
L_56 , L_57 ,
V_150 , V_155 , NULL , 0xF0 , NULL , V_152
}
} ,
{
& V_53 ,
{
L_58 , L_59 ,
V_150 , V_151 , NULL , 0x0F , NULL , V_152
}
} ,
#if 0
{
&hf_ucd_burst_power_boost,
{"Focused Contention Power Boost", "wmx.ucd.burst.power_boost", FT_UINT8, BASE_HEX, NULL, 0, "", HFILL}
},
{
&hf_ucd_burst_tcs_enable,
{"TCS", "wmx.ucd.burst.tcs", FT_UINT8, BASE_DEC, VALS(vals_dcd_burst_tcs), 0, "", HFILL}
},
#endif
{
& V_63 ,
{
L_60 , L_61 ,
V_157 , V_151 , NULL , 0 , NULL , V_152
}
} ,
{
& V_89 ,
{
L_62 , L_63 ,
V_150 , V_151 , NULL , 0 , NULL , V_152
}
} ,
{
& V_67 ,
{
L_64 , L_65 ,
V_158 , V_151 , NULL , 0 , NULL , V_152
}
} ,
{
& V_117 ,
{
L_66 , L_67 ,
V_153 , V_151 , NULL , 0 , NULL , V_152
}
} ,
{
& V_87 ,
{
L_68 , L_69 ,
V_150 , V_151 , NULL , 0 , NULL , V_152
}
} ,
{
& V_136 ,
{
L_70 , L_71 ,
V_150 , V_155 , NULL , 0 , NULL , V_152
}
} ,
{
& V_119 ,
{
L_72 , L_73 ,
V_153 , V_151 , NULL , 0 , NULL , V_152
}
} ,
{
& V_28 ,
{
L_74 , L_75 ,
V_159 , V_160 , NULL , 0 , NULL , V_152
}
} ,
{
& V_103 ,
{
L_76 , L_77 ,
V_153 , V_151 , NULL , 0 , NULL , V_152
}
} ,
{
& V_113 ,
{
L_78 , L_79 ,
V_153 , V_151 , NULL , 0 , NULL , V_152
}
} ,
{
& V_115 ,
{
L_80 , L_81 ,
V_153 , V_151 , NULL , 0 , NULL , V_152
}
} ,
{
& V_91 ,
{
L_82 , L_83 ,
V_150 , V_151 , NULL , 0 , NULL , V_152
}
} ,
{
& V_111 ,
{
L_84 , L_85 ,
V_150 , V_155 , NULL , 0 , NULL , V_152
}
} ,
{
& V_109 ,
{
L_86 , L_87 ,
V_150 , V_155 , NULL , 0 , NULL , V_152
}
} ,
{
& V_128 ,
{
L_88 , L_89 ,
V_150 , V_155 , NULL , 0 , NULL , V_152
}
} ,
{
& V_96 ,
{
L_90 , L_91 ,
V_161 , V_160 , NULL , 0 , NULL , V_152
}
} ,
{
& V_97 ,
{
L_92 , L_93 ,
V_150 , V_155 , NULL , 0 , NULL , V_152
}
} ,
{
& V_98 ,
{
L_94 , L_95 ,
V_161 , V_160 , NULL , 0 , NULL , V_152
}
} ,
{
& V_71 ,
{
L_96 , L_97 ,
V_159 , V_160 , NULL , 0 , NULL , V_152
}
} ,
{
& V_138 ,
{
L_98 , L_99 ,
V_150 , V_155 , NULL , 0 , NULL , V_152
}
} ,
{
& V_146 ,
{
L_100 , L_101 ,
V_150 , V_151 , NULL , 0 , NULL , V_152
}
} ,
{
& V_65 ,
{
L_102 , L_103 ,
V_157 , V_151 , NULL , 0 , NULL , V_152
}
} ,
{
& V_61 ,
{
L_104 , L_105 ,
V_150 , V_151 , NULL , 0 , NULL , V_152
}
} ,
{
& V_85 ,
{
L_106 , L_107 ,
V_150 , V_155 , NULL , 0 , NULL , V_152
}
} ,
{
& V_94 ,
{
L_108 , L_109 ,
V_150 , V_151 , F_18 ( V_162 ) , 0 , NULL , V_152
}
} ,
{
& V_144 ,
{
L_110 , L_111 ,
V_150 , V_151 , NULL , 0 , NULL , V_152
}
} ,
{
& V_148 ,
{
L_112 , L_113 ,
V_159 , V_160 , NULL , 0 , NULL , V_152
}
} ,
#if 0
{
&hf_ucd_subchan_codes,
{
"Periodic Ranging Codes", "wmx.ucd.subchan.codes",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_subchan_params_num_chan,
{
"Number of Subchannels", "wmx.ucd.subchan.num_chan",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_subchan_params_num_sym,
{
"Number of OFDMA Symbols", "wmx.ucd.subchan.num_sym",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_196_tx_power_report,
{
"Tx Power Report", "wmx.ucd.tx_power_report",
FT_UINT24, BASE_HEX, NULL, 0, NULL, HFILL
}
},
#endif
{
& V_123 ,
{
L_114 , L_115 ,
V_150 , V_151 , NULL , 0xF0 , NULL , V_152
}
} ,
{
& V_126 ,
{
L_116 , L_117 ,
V_150 , V_151 , NULL , 0x0F , NULL , V_152
}
} ,
{
& V_122 ,
{
L_118 , L_119 ,
V_150 , V_151 , NULL , 0x0F , NULL , V_152
}
} ,
{
& V_125 ,
{
L_120 , L_121 ,
V_150 , V_151 , NULL , 0xF0 , NULL , V_152
}
} ,
{
& V_121 ,
{
L_122 , L_123 ,
V_150 , V_151 , NULL , 0xF0 , NULL , V_152
}
} ,
{
& V_124 ,
{
L_124 , L_125 ,
V_150 , V_151 , NULL , 0x0F , NULL , V_152
}
} ,
#if 0
{
&hf_ucd_unknown_type,
{
"Unknown UCD Type", "wmx.ucd.unknown_tlv_type",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
}
},
#endif
{
& V_134 ,
{
L_126 , L_127 ,
V_150 , V_155 , NULL , 0 , NULL , V_152
}
} ,
{
& V_33 ,
{
L_128 , L_129 ,
V_150 , V_155 , NULL , 0 , NULL , V_152
}
} ,
{
& V_35 ,
{
L_130 , L_131 ,
V_150 , V_155 , NULL , 0 , NULL , V_152
}
} ,
{
& V_37 ,
{
L_132 , L_133 ,
V_150 , V_155 , NULL , 0 , NULL , V_152
}
} ,
{
& V_39 ,
{
L_134 , L_135 ,
V_150 , V_155 , NULL , 0 , NULL , V_152
}
} ,
{
& V_41 ,
{
L_136 , L_137 ,
V_159 , V_160 , NULL , 0 , NULL , V_152
}
} ,
{
& V_43 ,
{
L_138 , L_139 ,
V_159 , V_160 , NULL , 0 , NULL , V_152
}
} ,
{
& V_45 ,
{
L_140 , L_141 ,
V_159 , V_160 , NULL , 0 , NULL , V_152
}
} ,
{
& V_47 ,
{
L_142 , L_143 ,
V_159 , V_160 , NULL , 0 , NULL , V_152
}
} ,
{
& V_101 ,
{
L_144 , L_145 ,
V_153 , V_151 , NULL , 0 , NULL , V_152
}
} ,
{
& V_107 ,
{
L_146 , L_147 ,
V_150 , V_155 , NULL , 0 , NULL , V_152
}
}
} ;
static T_5 * V_163 [] =
{
& V_22 ,
} ;
V_21 = V_164 ;
F_19 ( V_21 , V_149 , F_20 ( V_149 ) ) ;
F_21 ( V_163 , F_20 ( V_163 ) ) ;
}
