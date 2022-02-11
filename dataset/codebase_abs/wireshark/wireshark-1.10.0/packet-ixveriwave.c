static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_3 * V_4 = NULL ;
T_4 * V_5 = NULL ;
T_4 * V_6 = NULL ;
T_3 * V_7 = NULL ;
int V_8 , V_9 , V_10 = 0 ;
T_5 V_11 , V_12 ;
T_6 V_13 ;
T_7 V_14 = 0 , V_15 = 0 ;
T_8 V_16 ;
T_8 V_17 , V_18 , V_19 ;
T_5 V_20 , V_21 , V_22 ;
T_1 * V_23 ;
T_9 * V_24 ;
V_9 = 0 ;
V_11 = F_2 ( V_1 , V_9 ) ;
F_3 ( V_2 -> V_25 , V_26 , V_11 ? L_1 : L_2 ) ;
F_4 ( V_2 -> V_25 , V_27 ) ;
V_12 = F_2 ( V_1 , V_9 + V_28 ) ;
V_16 = V_2 -> V_29 -> V_30 - V_12 - F_2 ( V_1 , V_9 + V_12 ) + 4 ;
F_5 ( V_2 -> V_25 , V_27 , L_3 ,
V_11 ? L_4 : L_5 , V_12 ) ;
if ( V_3 ) {
V_5 = F_6 ( V_3 , V_31 ,
V_1 , 0 , V_12 , L_6 , V_11 ? L_4 : L_5 , V_12 ) ;
V_4 = F_7 ( V_5 , V_32 ) ;
F_8 ( V_4 , V_33 ,
V_1 , 4 , 2 , V_16 ) ;
}
V_13 = V_12 ;
V_9 += 4 ;
V_13 -= 4 ;
V_8 = F_9 ( V_9 , 2 ) ;
V_9 += V_8 ;
V_13 -= V_8 ;
if ( V_13 >= 2 ) {
V_21 = F_2 ( V_1 , V_9 ) ;
if ( V_3 ) {
F_8 ( V_4 , V_34 ,
V_1 , V_9 , 2 , V_21 ) ;
}
V_9 += 2 ;
V_13 -= 2 ;
}
if ( V_13 >= 4 ) {
V_8 = F_9 ( V_9 , 4 ) ;
V_9 += V_8 ;
V_13 -= V_8 ;
V_19 = F_10 ( V_1 , V_9 ) ;
if ( V_3 ) {
F_8 ( V_4 , V_35 ,
V_1 , V_9 , 4 , V_19 ) ;
}
V_9 += 4 ;
V_13 -= 4 ;
}
if ( V_13 >= 2 ) {
V_8 = F_9 ( V_9 , 2 ) ;
V_9 += V_8 ;
V_13 -= V_8 ;
V_20 = F_2 ( V_1 , V_9 ) ;
if ( V_3 ) {
F_8 ( V_4 , V_36 ,
V_1 , V_9 , 2 , V_20 ) ;
}
V_9 += 2 ;
V_13 -= 2 ;
}
if ( V_13 >= 2 ) {
V_22 = F_2 ( V_1 , V_9 ) ;
if ( V_3 ) {
F_8 ( V_4 , V_37 ,
V_1 , V_9 , 2 , V_22 ) ;
}
V_9 += 2 ;
V_13 -= 2 ;
}
if ( V_13 >= 4 ) {
V_8 = F_9 ( V_9 , 4 ) ;
V_9 += V_8 ;
V_13 -= V_8 ;
V_17 = F_10 ( V_1 , V_9 ) ;
if ( V_3 ) {
if ( V_17 != 0 ) {
V_6 = F_11 ( V_4 ,
V_38 ,
V_1 , V_9 , 4 , ( float ) ( V_17 / 1000000.0 ) ,
L_7 ,
( float ) ( V_17 / 1000000.0 ) ) ;
V_7 = F_7 ( V_6 , V_39 ) ;
F_12 ( V_7 , V_40 ,
V_1 , V_9 , 4 , V_17 ,
L_8 , V_17 ) ;
}
else
{
V_6 = F_11 ( V_4 ,
V_38 ,
V_1 , V_9 , 4 , ( float ) ( V_17 / 1000000.0 ) ,
L_9 ) ;
V_7 = F_7 ( V_6 , V_39 ) ;
F_12 ( V_7 , V_40 ,
V_1 , V_9 , 4 , V_17 ,
L_10 ) ;
}
}
V_9 += 4 ;
V_13 -= 4 ;
}
if ( V_13 >= 4 ) {
V_8 = F_9 ( V_9 , 4 ) ;
V_9 += V_8 ;
V_13 -= V_8 ;
if ( V_3 ) {
if ( V_7 != NULL ) {
F_13 ( V_7 , V_41 ,
V_1 , V_9 , 4 , V_42 ) ;
}
}
V_10 = V_9 ;
V_9 += 4 ;
V_13 -= 4 ;
}
if ( V_13 >= 8 ) {
V_8 = F_9 ( V_9 , 8 ) ;
V_9 += V_8 ;
V_13 -= V_8 ;
V_14 = F_14 ( V_1 , V_9 ) ;
if ( V_3 ) {
if ( V_7 != NULL ) {
F_15 ( V_7 , V_43 ,
V_1 , V_9 , 8 , V_14 ,
L_11 V_44 L_12 , V_14 ) ;
}
}
V_9 += 8 ;
V_13 -= 8 ;
}
if ( V_13 >= 8 ) {
V_8 = F_9 ( V_9 , 8 ) ;
V_9 += V_8 ;
V_13 -= V_8 ;
V_15 = F_14 ( V_1 , V_9 ) ;
if ( V_3 ) {
if ( V_7 != NULL ) {
F_15 ( V_7 , V_45 ,
V_1 , V_9 , 8 , V_15 ,
L_13 V_44 L_12 , V_15 ) ;
}
}
V_9 += 8 ;
V_13 -= 8 ;
}
if ( V_13 >= 4 ) {
V_8 = F_9 ( V_9 , 4 ) ;
V_9 += V_8 ;
V_18 = F_10 ( V_1 , V_9 ) ;
if ( V_3 ) {
if ( V_7 != NULL ) {
T_4 * V_46 ;
if ( V_15 >= V_14 ) {
V_46 = F_12 ( V_7 , V_47 ,
V_1 , V_9 - 16 , 16 , V_18 ,
L_14 , V_18 ) ;
F_16 ( V_6 , L_15 , V_18 ) ;
}
else {
V_46 = F_12 ( V_7 , V_47 ,
V_1 , V_9 , 0 , V_18 ,
L_16 ) ;
F_16 ( V_6 , L_17 ) ;
}
F_17 ( V_46 ) ;
}
}
V_9 += 4 ;
}
if ( V_6 ) {
F_18 ( V_6 , V_9 - V_10 ) ;
}
V_24 = ( T_9 * ) F_19 ( V_2 -> V_29 , V_31 , 0 ) ;
if ( ! V_24 )
{
V_24 = F_20 ( struct T_9 ) ;
if ( V_48 . V_49 != 0 && ( V_2 -> V_29 -> V_50 - V_48 . V_49 == 1 ) )
{
V_24 -> V_51 = ( T_8 ) ( V_14 - V_48 . V_52 ) ;
V_24 -> V_52 = V_48 . V_52 ;
}
else
{
V_24 -> V_51 = 0 ;
V_24 -> V_52 = 0 ;
}
V_48 . V_52 = V_15 ;
V_48 . V_49 = V_2 -> V_29 -> V_50 ;
V_24 -> V_53 = V_14 ;
F_21 ( V_2 -> V_29 , V_31 , 0 , V_24 ) ;
}
if ( V_3 ) {
V_5 = F_8 ( V_4 , V_54 ,
V_1 , V_9 , 0 , V_24 -> V_51 ) ;
F_17 ( V_5 ) ;
}
V_23 = F_22 ( V_1 , V_12 ) ;
if ( V_11 == V_55 )
F_23 ( V_23 , V_2 , V_3 , V_4 ) ;
else
F_24 ( V_23 , V_2 , V_3 , V_4 ) ;
}
static void
F_23 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , T_3 * V_56 )
{
T_3 * V_57 , * V_58 = NULL , * V_59 , * V_60 = NULL ;
int V_8 , V_9 ;
T_1 * V_23 ;
T_6 V_12 , V_13 ;
T_5 V_61 , V_62 ;
T_5 V_63 ;
T_8 V_64 ;
T_10 V_65 , V_66 ;
V_65 = 0 ;
V_9 = 0 ;
V_12 = F_2 ( V_1 , V_9 ) ;
V_13 = V_12 ;
V_9 += 2 ;
V_13 -= 2 ;
if ( V_12 >= 2 ) {
V_8 = F_9 ( V_9 , 2 ) ;
V_9 += V_8 ;
V_13 -= V_8 ;
V_61 = F_2 ( V_1 , V_9 ) ;
V_65 = ( ( V_61 & V_67 ) == 0 ) ? 0 : 1 ;
V_66 = ( ( V_61 & V_68 ) == 0 ) ? 0 : 1 ;
if ( V_56 ) {
F_8 ( V_56 , V_69 ,
V_1 , 0 , 0 , V_65 ) ;
F_8 ( V_56 , V_70 ,
V_1 , 0 , 0 , V_66 ) ;
}
V_9 += 2 ;
V_13 -= 2 ;
}
if ( V_13 >= 2 ) {
V_62 = F_2 ( V_1 , V_9 ) ;
if ( V_56 ) {
V_59 = F_8 ( V_56 , V_71 ,
V_1 , V_9 , 2 , V_62 ) ;
V_60 = F_7 ( V_59 , V_72 ) ;
if ( V_65 == 0 ) {
F_13 ( V_60 , V_73 ,
V_1 , V_9 , 2 , V_74 ) ;
F_13 ( V_60 , V_75 ,
V_1 , V_9 , 2 , V_74 ) ;
} else {
F_12 ( V_60 , V_76 ,
V_1 , V_9 , 2 , V_62 ,
L_18 , V_62 ) ;
}
}
V_9 += 2 ;
V_13 -= 2 ;
}
if ( V_13 >= 4 ) {
V_64 = F_10 ( V_1 , V_9 ) ;
if ( V_56 ) {
V_57 = F_8 ( V_56 , V_77 ,
V_1 , V_9 , 4 , V_64 ) ;
V_58 = F_7 ( V_57 , V_78 ) ;
if ( V_65 == 0 ) {
F_13 ( V_58 , V_79 ,
V_1 , V_9 , 4 , V_74 ) ;
F_13 ( V_58 , V_80 ,
V_1 , V_9 , 4 , V_74 ) ;
F_13 ( V_58 , V_81 ,
V_1 , V_9 , 4 , V_74 ) ;
F_13 ( V_58 , V_82 ,
V_1 , V_9 , 4 , V_74 ) ;
F_13 ( V_58 , V_83 ,
V_1 , V_9 , 4 , V_74 ) ;
F_13 ( V_58 , V_84 ,
V_1 , V_9 , 4 , V_74 ) ;
F_13 ( V_58 , V_85 ,
V_1 , V_9 , 4 , V_74 ) ;
F_13 ( V_58 , V_86 ,
V_1 , V_9 , 4 , V_74 ) ;
F_13 ( V_58 , V_87 ,
V_1 , V_9 , 4 , V_74 ) ;
F_13 ( V_58 , V_88 ,
V_1 , V_9 , 4 , V_74 ) ;
} else {
F_13 ( V_58 , V_89 ,
V_1 , V_9 , 4 , V_74 ) ;
F_13 ( V_58 , V_90 ,
V_1 , V_9 , 4 , V_74 ) ;
F_13 ( V_58 , V_91 ,
V_1 , V_9 , 4 , V_74 ) ;
F_13 ( V_58 , V_92 ,
V_1 , V_9 , 4 , V_74 ) ;
F_13 ( V_58 , V_93 ,
V_1 , V_9 , 4 , V_74 ) ;
}
}
V_9 += 4 ;
V_13 -= 4 ;
}
if ( V_13 >= 4 ) {
V_63 = F_10 ( V_1 , V_9 ) ;
if ( V_56 ) {
F_8 ( V_56 , V_94 ,
V_1 , V_9 , 4 , V_63 ) ;
}
V_9 += 4 ;
V_13 -= 4 ;
}
if ( V_13 >= 4 ) {
F_10 ( V_1 , V_9 ) ;
}
V_23 = F_22 ( V_1 , V_12 ) ;
F_25 ( V_95 , V_23 , V_2 , V_3 ) ;
}
static void
F_24 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , T_3 * V_56 )
{
T_3 * V_96 , * V_97 = NULL ;
int V_8 , V_9 ;
T_1 * V_23 ;
T_6 V_12 ;
T_8 V_98 ;
T_11 V_99 ;
T_12 V_100 = 0 ;
T_3 * V_57 , * V_58 = NULL , * V_59 , * V_60 = NULL ;
T_5 V_61 , V_62 , V_101 , V_102 ;
T_8 V_103 ;
T_11 V_104 ;
float V_105 ;
V_9 = 0 ;
V_12 = F_2 ( V_1 , V_9 ) ;
V_9 += 2 ;
V_102 = F_2 ( V_1 , V_9 ) ;
if ( V_3 ) {
V_96 = F_8 ( V_56 , V_106 ,
V_1 , V_9 , 2 , V_102 ) ;
V_97 = F_7 ( V_96 , V_107 ) ;
F_26 ( V_97 , V_108 ,
V_1 , V_9 , 2 , V_102 ) ;
F_26 ( V_97 , V_109 ,
V_1 , V_9 , 2 , V_102 ) ;
F_26 ( V_97 , V_110 ,
V_1 , V_9 , 2 , V_102 ) ;
F_26 ( V_97 , V_111 ,
V_1 , V_9 , 2 , V_102 ) ;
F_26 ( V_97 , V_112 ,
V_1 , V_9 , 2 , V_102 ) ;
F_26 ( V_97 , V_113 ,
V_1 , V_9 , 2 , V_102 ) ;
if ( V_102 & V_114 ) {
F_26 ( V_97 , V_115 ,
V_1 , V_9 , 2 , V_102 ) ;
F_26 ( V_97 , V_116 ,
V_1 , V_9 , 2 , V_102 ) ;
F_26 ( V_97 , V_117 ,
V_1 , V_9 , 2 , V_102 ) ;
}
}
V_9 += 2 ;
V_9 += 2 ;
V_98 = F_27 ( V_1 , V_9 ) ;
if ( V_102 & V_114 ) {
V_105 = F_28 ( V_98 , V_100 ) ;
F_5 ( V_2 -> V_25 , V_118 , L_19 ,
V_105 ) ;
if ( V_3 ) {
F_12 ( V_56 , V_119 ,
V_1 , V_9 , 1 , F_27 ( V_1 , V_9 ) ,
L_20 , V_105 , V_98 & V_120 ) ;
}
} else {
F_5 ( V_2 -> V_25 , V_118 , L_21 ,
( V_98 & V_120 ) / 2 , V_98 & 1 ? 5 : 0 ) ;
if ( V_3 ) {
F_12 ( V_56 , V_119 ,
V_1 , V_9 , 1 , F_27 ( V_1 , V_9 ) ,
L_22 , ( V_98 & V_120 ) / 2 ,
( V_98 & V_120 ) & 1 ? 5 : 0 ) ;
}
}
V_9 ++ ;
V_99 = ( T_11 ) F_27 ( V_1 , V_9 ) ;
V_9 ++ ;
V_104 = ( T_11 ) F_27 ( V_1 , V_9 ) ;
if ( V_99 != 100 )
{
F_5 ( V_2 -> V_25 , V_121 , L_23 , V_99 ) ;
if ( V_3 ) {
F_29 ( V_56 ,
V_122 ,
V_1 , V_9 , 1 , V_99 ,
L_24 , V_99 ) ;
}
}
else if ( V_104 != 100 )
{
F_5 ( V_2 -> V_25 , V_121 , L_23 , V_104 ) ;
if ( V_3 ) {
F_29 ( V_56 ,
V_123 ,
V_1 , V_9 , 1 , V_104 ,
L_25 , V_104 ) ;
}
}
V_9 += 2 ;
V_61 = F_2 ( V_1 , V_9 ) ;
if ( V_3 ) {
F_8 ( V_56 , V_124 ,
V_1 , V_9 , 2 , ( V_61 & V_125 ) != 0 ) ;
F_8 ( V_56 , V_126 ,
V_1 , V_9 , 2 , ( V_61 & V_127 ) != 0 ) ;
F_8 ( V_56 , V_128 ,
V_1 , V_9 , 2 , ( V_61 & V_129 ) != 0 ) ;
F_8 ( V_56 , V_130 ,
V_1 , V_9 , 2 , ( V_61 & V_131 ) != 0 ) ;
F_8 ( V_56 , V_132 ,
V_1 , V_9 , 2 , ( V_61 & V_133 ) >>
V_134 ) ;
}
V_9 += 2 ;
V_8 = F_9 ( V_9 , 2 ) ;
V_9 += V_8 ;
V_101 = F_2 ( V_1 , V_9 ) ;
if ( ( V_3 ) && ( V_101 != 0 ) ) {
F_12 ( V_56 , V_135 ,
V_1 , V_9 , 2 ,
V_101 ,
L_26
L_27 ,
V_101 ) ;
}
V_9 += 2 ;
V_8 = F_9 ( V_9 , 2 ) ;
V_9 += V_8 ;
V_62 = F_2 ( V_1 , V_9 ) ;
if ( V_3 ) {
V_59 = F_8 ( V_56 , V_136 ,
V_1 , V_9 , 2 , V_62 ) ;
V_60 = F_7 ( V_59 , V_137 ) ;
if ( V_104 == 0 ) {
F_13 ( V_60 ,
V_138 , V_1 , V_9 , 2 , V_74 ) ;
F_13 ( V_60 ,
V_139 , V_1 , V_9 , 2 , V_74 ) ;
F_13 ( V_60 ,
V_140 , V_1 , V_9 , 2 , V_74 ) ;
F_13 ( V_60 ,
V_141 , V_1 , V_9 , 2 , V_74 ) ;
F_13 ( V_60 ,
V_142 , V_1 , V_9 , 2 , V_74 ) ;
F_13 ( V_60 ,
V_143 , V_1 , V_9 , 2 , V_74 ) ;
F_13 ( V_60 ,
V_144 , V_1 , V_9 , 2 , V_74 ) ;
F_13 ( V_60 ,
V_145 , V_1 , V_9 , 2 , V_74 ) ;
} else {
F_13 ( V_60 ,
V_146 , V_1 , V_9 , 2 , V_74 ) ;
F_13 ( V_60 ,
V_147 , V_1 , V_9 , 2 , V_74 ) ;
F_13 ( V_60 ,
V_148 , V_1 , V_9 , 2 , V_74 ) ;
F_13 ( V_60 ,
V_149 , V_1 , V_9 , 2 , V_74 ) ;
F_13 ( V_60 ,
V_150 , V_1 , V_9 , 2 , V_74 ) ;
F_13 ( V_60 ,
V_151 , V_1 , V_9 , 2 , V_74 ) ;
}
}
V_9 += 2 ;
V_8 = F_9 ( V_9 , 4 ) ;
V_9 += V_8 ;
V_103 = F_10 ( V_1 , V_9 ) ;
if ( V_3 ) {
V_57 = F_8 ( V_56 , V_152 ,
V_1 , V_9 , 4 , V_103 ) ;
V_58 = F_7 ( V_57 ,
V_153 ) ;
if ( V_104 == 0 ) {
F_13 ( V_58 ,
V_154 , V_1 , V_9 , 2 , V_74 ) ;
F_13 ( V_58 ,
V_155 , V_1 , V_9 , 2 , V_74 ) ;
F_13 ( V_58 ,
V_156 , V_1 , V_9 , 2 , V_74 ) ;
F_13 ( V_58 ,
V_157 , V_1 , V_9 , 2 , V_74 ) ;
F_13 ( V_58 ,
V_158 , V_1 , V_9 , 2 , V_74 ) ;
F_13 ( V_58 ,
V_159 , V_1 , V_9 , 2 , V_74 ) ;
F_13 ( V_58 ,
V_160 , V_1 , V_9 , 2 , V_74 ) ;
F_13 ( V_58 ,
V_161 , V_1 , V_9 , 2 , V_74 ) ;
F_13 ( V_58 ,
V_162 , V_1 , V_9 , 2 , V_74 ) ;
F_13 ( V_58 ,
V_163 , V_1 , V_9 , 2 , V_74 ) ;
} else {
F_13 ( V_58 ,
V_164 , V_1 , V_9 , 2 , V_74 ) ;
F_13 ( V_58 ,
V_165 , V_1 , V_9 , 2 , V_74 ) ;
}
}
if ( V_100 & V_166 )
V_2 -> V_167 -> V_168 . V_169 = 4 ;
else
V_2 -> V_167 -> V_168 . V_169 = 0 ;
V_23 = F_22 ( V_1 , V_12 ) ;
#if 0
if (hdr_fcs_ti) {
if (tvb_length(next_tvb) > (unsigned int) pinfo->pseudo_header->ieee_802_11.fcs_len) {
guint32 sent_fcs = 0;
calc_fcs = crc32_802_tvb(next_tvb,
tvb_length(next_tvb) - pinfo->pseudo_header->ieee_802_11.fcs_len);
if (calc_fcs == sent_fcs) {
proto_item_append_text(hdr_fcs_ti, " [correct]");
}
else {
proto_item_append_text(hdr_fcs_ti, " [incorrect, should be 0x%08x]", calc_fcs);
proto_tree_add_boolean(tap_tree, hf_radiotap_fcs_bad,
tvb, 0, 4, TRUE);
}
}
else {
proto_item_append_text(hdr_fcs_ti,
" [cannot verify - not enough data]");
}
}
#endif
F_25 ( ( V_100 & V_170 ) ?
V_171 : V_172 ,
V_23 , V_2 , V_3 ) ;
}
static float F_28 ( T_12 V_98 , T_12 V_100 )
{
int V_173 , V_174 ;
float V_175 , V_176 ;
if ( V_98 & 0x80 )
V_175 = ( float ) 3.6 ;
else
V_175 = ( float ) 4.0 ;
V_173 = V_98 & V_120 ;
if ( V_100 & V_177 )
V_174 = V_178 [ V_173 - 8 * ( int ) ( V_173 / 8 ) ] ;
else
V_174 = V_179 [ V_173 - 8 * ( int ) ( V_173 / 8 ) ] ;
V_176 = ( V_174 * ( ( ( int ) ( V_173 / 8 ) + 1 ) ) ) / V_175 ;
return V_176 ;
}
void F_30 ( void )
{
static const T_13 V_180 [] = {
{ 0 , L_28 } ,
{ 1 , L_29 } ,
{ 0 , NULL } ,
} ;
static const T_13 V_181 [] = {
{ 0 , L_30 } ,
{ 1 , L_31 } ,
{ 0 , NULL } ,
} ;
static const T_14 V_182 = {
L_32 ,
L_33 ,
} ;
static const T_13 V_183 [] = {
{ 0 , L_34 } ,
{ 1 , L_35 } ,
{ 0 , NULL } ,
} ;
static const T_13 V_184 [] = {
{ 0 , L_36 } ,
{ 1 , L_37 } ,
{ 0 , NULL } ,
} ;
static const T_13 V_185 [] = {
{ 0 , L_38 } ,
{ 1 , L_39 } ,
{ 2 , L_40 } ,
{ 3 , L_41 } ,
{ 0 , NULL } ,
} ;
static T_15 V_186 [] = {
{ & V_33 ,
{ L_42 , L_43 ,
V_187 , V_188 , NULL , 0x0 , NULL , V_189 } } ,
{ & V_34 ,
{ L_44 , L_45 ,
V_187 , V_188 , NULL , 0x0 , NULL , V_189 } } ,
{ & V_36 ,
{ L_46 , L_47 ,
V_187 , V_188 , NULL , 0x0 , NULL , V_189 } } ,
{ & V_35 ,
{ L_48 , L_49 ,
V_190 , V_188 , NULL , 0x0 , NULL , V_189 } } ,
{ & V_37 ,
{ L_50 , L_51 ,
V_187 , V_188 , NULL , 0x0 , NULL , V_189 } } ,
{ & V_38 ,
{ L_52 , L_53 ,
V_191 , 0 , NULL , 0x0 , NULL , V_189 } } ,
{ & V_40 ,
{ L_54 , L_55 ,
V_190 , V_188 , NULL , 0x0 , NULL , V_189 } } ,
{ & V_41 ,
{ L_56 , L_57 ,
V_190 , V_188 , NULL , 0x0 , NULL , V_189 } } ,
{ & V_43 ,
{ L_58 , L_59 ,
V_192 , V_188 , NULL , 0x0 , NULL , V_189 } } ,
{ & V_45 ,
{ L_60 , L_61 ,
V_192 , V_188 , NULL , 0x0 , NULL , V_189 } } ,
{ & V_47 ,
{ L_62 , L_63 ,
V_190 , V_188 , NULL , 0x0 , NULL , V_189 } } ,
{ & V_54 ,
{ L_64 , L_65 ,
V_190 , V_188 , NULL , 0x0 , NULL , V_189 } } ,
{ & V_69 ,
{ L_66 , L_67 ,
V_190 , V_188 , F_31 ( V_180 ) , 0x0 , NULL , V_189 } } ,
{ & V_70 ,
{ L_68 , L_69 ,
V_190 , V_188 , F_31 ( V_181 ) , 0x0 , NULL , V_189 } } ,
{ & V_71 ,
{ L_70 , L_71 ,
V_187 , V_193 , NULL , 0x0 , NULL , V_189 } } ,
{ & V_76 ,
{ L_72 , L_73 ,
V_187 , V_188 , NULL , 0x0 , NULL , V_189 } } ,
#if 0
{ &hf_ixveriwave_vw_info_tx_bit15,
{ "Info bit 15-frame was impressed on the ent tx media with one or more octets having tx_en framing signal deasserted.", "ixveriwave.info.bit15",
FT_BOOLEAN, 16, NULL, 0x8000, NULL, HFILL } },
#endif
{ & V_73 ,
{ L_74 , L_75 ,
V_194 , 16 , NULL , 0x0100 , NULL , V_189 } } ,
{ & V_75 ,
{ L_76 , L_77 ,
V_194 , 16 , NULL , 0x0200 , NULL , V_189 } } ,
{ & V_77 ,
{ L_78 , L_79 ,
V_190 , V_193 , NULL , 0x0 , NULL , V_189 } } ,
{ & V_89 ,
{ L_80 , L_81 ,
V_194 , 12 , NULL , 0x0002 , NULL , V_189 } } ,
{ & V_90 ,
{ L_82 , L_83 ,
V_194 , 12 , NULL , 0x0020 , NULL , V_189 } } ,
{ & V_91 ,
{ L_84 , L_85 ,
V_194 , 12 , NULL , 0x0200 , NULL , V_189 } } ,
{ & V_92 ,
{ L_86 , L_87 ,
V_194 , 12 , NULL , 0x0400 , NULL , V_189 } } ,
{ & V_93 ,
{ L_88 , L_89 ,
V_194 , 12 , NULL , 0x0800 , NULL , V_189 } } ,
{ & V_79 ,
{ L_90 , L_91 ,
V_194 , 12 , NULL , 0x0001 , L_92 , V_189 } } ,
{ & V_80 ,
{ L_80 , L_81 ,
V_194 , 12 , NULL , 0x0002 , NULL , V_189 } } ,
{ & V_81 ,
{ L_93 , L_94 ,
V_194 , 12 , NULL , 0x0004 , NULL , V_189 } } ,
{ & V_82 ,
{ L_95 , L_96 ,
V_194 , 12 , NULL , 0x0008 , NULL , V_189 } } ,
{ & V_83 ,
{ L_97 , L_98 ,
V_194 , 12 , NULL , 0x0010 , NULL , V_189 } } ,
{ & V_84 ,
{ L_82 , L_83 ,
V_194 , 12 , NULL , 0x0020 , NULL , V_189 } } ,
{ & V_85 ,
{ L_99 , L_100 ,
V_194 , 12 , NULL , 0x0040 , NULL , V_189 } } ,
{ & V_86 ,
{ L_101 , L_102 ,
V_194 , 12 , NULL , 0x0080 , NULL , V_189 } } ,
{ & V_87 ,
{ L_103 , L_104 ,
V_194 , 12 , NULL , 0x0100 , NULL , V_189 } } ,
{ & V_88 ,
{ L_105 , L_85 ,
V_194 , 12 , NULL , 0x0200 , NULL , V_189 } } ,
{ & V_164 ,
{ L_80 , L_106 ,
V_194 , 16 , NULL , 0x0002 , NULL , V_189 } } ,
{ & V_165 ,
{ L_82 , L_107 ,
V_194 , 16 , NULL , 0x0020 , NULL , V_189 } } ,
{ & V_94 ,
{ L_108 , L_109 ,
V_187 , V_193 , NULL , 0x0 , NULL , V_189 } } ,
#define F_32 (1 << VW_RADIOTAP_FPGA_VERSION)
#define F_33 (1 << VW_RADIOTAP_MCID)
#define F_34 (1 << VW_RADIOTAP_ERRORS)
#define F_35 (1 << VW_RADIOTAP_INFO)
#define F_36 (1 << VW_RADIOTAP_MSDU_LENGTH)
#define F_37 (1 << VW_RADIOTAP_HT_LENGTH)
#define F_38 (1 << VW_RADIOTAP_FLOWID)
#define F_39 (1 << VW_RADIOTAP_SEQNUM)
#define F_40 (1 << VW_RADIOTAP_LATENCY)
#define F_41 (1 << VW_RADIOTAP_SIG_TS)
#define F_42 (1 << VW_RADIOTAP_STARTT)
#define F_43 (1 << VW_RADIOTAP_ENDT)
#define F_44 (1 << VW_RADIOTAP_PKTDUR)
#define F_45 (1 << VW_RADIOTAP_IFG)
{ & V_119 ,
{ L_110 , L_111 ,
V_190 , V_188 , NULL , 0x0 ,
L_112 , V_189 } } ,
{ & V_106 ,
{ L_113 , L_114 ,
V_187 , V_193 , NULL , 0x0 , NULL , V_189 } } ,
{ & V_108 ,
{ L_115 , L_116 ,
V_194 , 12 , NULL , V_195 ,
L_117 , V_189 } } ,
{ & V_109 ,
{ L_118 , L_119 ,
V_194 , 12 , F_46 ( & V_182 ) , V_196 ,
L_120 , V_189 } } ,
{ & V_110 ,
{ L_121 , L_122 ,
V_194 , 12 , NULL , V_197 ,
L_123 , V_189 } } ,
{ & V_111 ,
{ L_124 , L_125 ,
V_194 , 12 , NULL , V_198 ,
L_126 , V_189 } } ,
{ & V_112 ,
{ L_127 , L_128 ,
V_194 , 12 , NULL , V_166 ,
L_129 , V_189 } } ,
{ & V_113 ,
{ L_130 , L_131 ,
V_194 , 12 , NULL , V_170 ,
L_132 , V_189 } } ,
{ & V_115 ,
{ L_133 , L_134 ,
V_194 , 12 , NULL , V_114 , NULL , V_189 } } ,
{ & V_116 ,
{ L_135 , L_136 ,
V_194 , 12 , NULL , V_177 , NULL , V_189 } } ,
{ & V_117 ,
{ L_137 , L_138 ,
V_194 , 12 , NULL , V_199 , NULL , V_189 } } ,
{ & V_122 ,
{ L_139 , L_140 ,
V_200 , V_188 , NULL , 0x0 ,
L_141 , V_189 } } ,
{ & V_123 ,
{ L_142 , L_143 ,
V_200 , V_188 , NULL , 0x0 ,
L_144 , V_189 } } ,
{ & V_124 ,
{ L_66 , L_67 ,
V_190 , V_188 , F_31 ( V_180 ) , 0x0 , NULL , V_189 } } ,
{ & V_126 ,
{ L_68 , L_69 ,
V_190 , V_188 , F_31 ( V_181 ) , 0x0 , NULL , V_189 } } ,
{ & V_128 ,
{ L_145 , L_146 ,
V_190 , V_188 , F_31 ( V_183 ) , 0x0 , NULL , V_189 } } ,
{ & V_130 ,
{ L_147 , L_148 ,
V_190 , V_188 , F_31 ( V_184 ) , 0x0 , NULL , V_189 } } ,
{ & V_132 ,
{ L_149 , L_150 ,
V_190 , V_188 , F_31 ( V_185 ) , 0x0 , NULL , V_189 } } ,
{ & V_135 ,
{ L_151 , L_152 ,
V_187 , V_188 , NULL , 0x0 , NULL , V_189 } } ,
{ & V_152 ,
{ L_78 , L_153 ,
V_190 , V_193 , NULL , 0x0 , NULL , V_189 } } ,
#if 0
{ &hf_radiotap_vw_errors_rx_1_bit0,
{ "L1 error", "ixveriwave.errors.bit0",
FT_BOOLEAN, 16, NULL, 0x0001, "error bit 0", HFILL } },
{ &hf_radiotap_vw_errors_rx_1_bit1,
{ "Packet FCS error", "ixveriwave.errors.bit1",
FT_BOOLEAN, 16, NULL, 0x0002, NULL, HFILL } },
{ &hf_radiotap_vw_errors_rx_1_bit2,
{ "Bad magic byte signature.", "ixveriwave.errors.bit2",
FT_BOOLEAN, 16, NULL, 0x0004, NULL, HFILL } },
{ &hf_radiotap_vw_errors_rx_1_bit3,
{ "Bad payload checksum.", "ixveriwave.errors.bit3",
FT_BOOLEAN, 16, NULL, 0x0008, NULL, HFILL } },
{ &hf_radiotap_vw_errors_rx_1_bit4,
{ "Duplicate MPDU", "ixveriwave.errors.bit4",
FT_BOOLEAN, 16, NULL, 0x0010, NULL, HFILL } },
{ &hf_radiotap_vw_errors_rx_1_bit5,
{ "IP checksum error", "ixveriwave.errors.bit5",
FT_BOOLEAN, 16, NULL, 0x0020, NULL, HFILL } },
{ &hf_radiotap_vw_errors_rx_1_bit6,
{ "TCP/ICMP/IGMP/UDP checksum error", "ixveriwave.errors.bit6",
FT_BOOLEAN, 16, NULL, 0x0040, NULL, HFILL } },
{ &hf_radiotap_vw_errors_rx_1_bit7,
{ "Reserved", "ixveriwave.errors.bit7",
FT_BOOLEAN, 16, NULL, 0x0080, NULL, HFILL } },
{ &hf_radiotap_vw_errors_rx_1_bit8,
{ "RX WEP IVC / TKIP/CCMP MIC miscompare", "ixveriwave.errors.bit8",
FT_BOOLEAN, 16, NULL, 0x0100, NULL, HFILL } },
{ &hf_radiotap_vw_errors_rx_1_bit9,
{ "RX TKIP / CCMP TSC SEQERR", "ixveriwave.errors.bit9",
FT_BOOLEAN, 16, NULL, 0x0200, NULL, HFILL } },
{ &hf_radiotap_vw_errors_rx_1_bit10,
{ "RX crypto short", "ixveriwave.errors.bit10",
FT_BOOLEAN, 16, NULL, 0x0400, NULL, HFILL } },
{ &hf_radiotap_vw_errors_rx_1_bit11,
{ "RX EXTIV fault A", "ixveriwave.errors.bit11",
FT_BOOLEAN, 16, NULL, 0x0800, NULL, HFILL } },
{ &hf_radiotap_vw_errors_rx_1_bit12,
{ "RX EXTIV fault B", "ixveriwave.errors.bit12",
FT_BOOLEAN, 16, NULL, 0x1000, NULL, HFILL } },
{ &hf_radiotap_vw_errors_rx_1_bit13,
{ "RX protected fault A", "ixveriwave.errors.bit13",
FT_BOOLEAN, 16, NULL, 0x2000, NULL, HFILL } },
{ &hf_radiotap_vw_errors_rx_1_bit14,
{ "RX protected fault B", "ixveriwave.errors.bit14",
FT_BOOLEAN, 16, NULL, 0x4000, NULL, HFILL } },
{ &hf_radiotap_vw_errors_rx_1_bit15,
{ "Reserved", "ixveriwave.errors.bit15",
FT_BOOLEAN, 16, NULL, 0x8000, NULL, HFILL } },
#endif
{ & V_154 ,
{ L_154 , L_155 ,
V_194 , 16 , NULL , 0x0001 , L_92 , V_189 } } ,
{ & V_155 ,
{ L_156 , L_106 ,
V_194 , 16 , NULL , 0x0002 , NULL , V_189 } } ,
{ & V_156 ,
{ L_157 , L_158 ,
V_194 , 16 , NULL , 0x0004 , NULL , V_189 } } ,
{ & V_157 ,
{ L_159 , L_160 ,
V_194 , 16 , NULL , 0x0010 , NULL , V_189 } } ,
{ & V_158 ,
{ L_161 , L_107 ,
V_194 , 16 , NULL , 0x0020 , NULL , V_189 } } ,
{ & V_159 ,
{ L_162 , L_163 ,
V_194 , 16 , NULL , 0x0040 , NULL , V_189 } } ,
{ & V_160 ,
{ L_164 , L_165 ,
V_194 , 16 , NULL , 0x0080 , NULL , V_189 } } ,
{ & V_161 ,
{ L_166 , L_167 ,
V_194 , 16 , NULL , 0x0100 , NULL , V_189 } } ,
{ & V_162 ,
{ L_168 , L_169 ,
V_194 , 16 , NULL , 0x0400 , NULL , V_189 } } ,
{ & V_163 ,
{ L_170 , L_171 ,
V_194 , 16 , NULL , 0x0800 , NULL , V_189 } } ,
{ & V_136 ,
{ L_70 , L_71 ,
V_187 , V_193 , NULL , 0x0 , NULL , V_189 } } ,
{ & V_146 ,
{ L_172 , L_173 ,
V_194 , 16 , NULL , 0x0400 , NULL , V_189 } } ,
{ & V_147 ,
{ L_174 , L_175 ,
V_194 , 16 , NULL , 0x0800 , NULL , V_189 } } ,
{ & V_148 ,
{ L_176 , L_177 ,
V_194 , 16 , NULL , 0x1000 , NULL , V_189 } } ,
{ & V_149 ,
{ L_178 , L_179 ,
V_194 , 16 , NULL , 0x2000 , NULL , V_189 } } ,
{ & V_150 ,
{ L_180 , L_181 ,
V_194 , 16 , NULL , 0x4000 , NULL , V_189 } } ,
{ & V_151 ,
{ L_182 , L_183 ,
V_194 , 16 , NULL , 0x8000 , NULL , V_189 } } ,
{ & V_138 ,
{ L_184 , L_75 ,
V_194 , 16 , NULL , 0x0100 , NULL , V_189 } } ,
{ & V_139 ,
{ L_185 , L_77 ,
V_194 , 16 , NULL , 0x0200 , NULL , V_189 } } ,
{ & V_140 ,
{ L_186 , L_173 ,
V_194 , 16 , NULL , 0x0400 , NULL , V_189 } } ,
{ & V_141 ,
{ L_174 , L_175 ,
V_194 , 16 , NULL , 0x0800 , NULL , V_189 } } ,
{ & V_142 ,
{ L_176 , L_177 ,
V_194 , 16 , NULL , 0x1000 , NULL , V_189 } } ,
{ & V_143 ,
{ L_178 , L_179 ,
V_194 , 16 , NULL , 0x2000 , NULL , V_189 } } ,
{ & V_144 ,
{ L_180 , L_181 ,
V_194 , 16 , NULL , 0x4000 , NULL , V_189 } } ,
{ & V_145 ,
{ L_182 , L_183 ,
V_194 , 16 , NULL , 0x8000 , NULL , V_189 } } ,
} ;
static T_16 * V_201 [] = {
& V_32 ,
& V_39 ,
& V_72 ,
& V_78 ,
& V_202 ,
& V_107 ,
& V_137 ,
& V_203 ,
& V_153
} ;
V_31 = F_47 ( L_187 , L_187 , L_187 ) ;
F_48 ( V_31 , V_186 , F_49 ( V_186 ) ) ;
F_50 ( V_201 , F_49 ( V_201 ) ) ;
F_51 ( L_187 , F_1 , V_31 ) ;
}
void F_52 ( void )
{
T_17 V_204 ;
V_95 = F_53 ( L_188 ) ;
V_172 = F_53 ( L_189 ) ;
V_171 = F_53 ( L_190 ) ;
V_204 = F_54 ( F_1 , V_31 ) ;
F_55 ( L_191 , V_205 , V_204 ) ;
}
