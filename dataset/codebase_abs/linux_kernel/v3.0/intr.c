T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_5 ;
T_1 V_6 = V_7 ;
V_4 -> V_8 = 1 ;
V_5 = F_3 ( V_4 , V_9 ) ;
if ( V_5 & V_10 ) {
F_4 ( & V_4 -> V_11 -> V_12 ,
L_1 ,
V_5 , ( V_4 -> V_13 . V_14 << 4 ) | V_4 -> V_13 . V_15 ) ;
F_5 ( V_4 ) ;
V_6 = V_16 ;
}
if ( V_5 & V_17 ) {
F_6 ( V_4 ) ;
V_6 = V_16 ;
}
if ( V_5 & V_18 ) {
F_7 ( V_4 ) ;
V_6 = V_16 ;
}
V_4 -> V_8 = 0 ;
return V_6 ;
}
void F_6 ( struct V_3 * V_4 )
{
T_2 V_5 ;
F_8 ( V_4 -> V_19 , V_20 , 0 ) ;
while ( ( V_5 = F_9 ( V_4 -> V_19 , V_21 ) ) &
( V_22 |
V_23 |
V_24 |
V_25 |
V_26 |
V_27 |
V_28 ) ) {
F_8 ( V_4 -> V_19 , V_21 , V_5 ) ;
F_4 ( & V_4 -> V_11 -> V_12 , L_2 ,
V_5 ) ;
if ( V_5 & ( V_24 |
V_23 |
V_22 ) ) {
if ( V_5 & V_24 )
F_4 ( & V_4 -> V_11 -> V_12 ,
L_3 ,
V_4 -> V_13 . V_14 , V_4 -> V_13 . V_15 ) ;
if ( V_5 & V_23 )
F_4 ( & V_4 -> V_11 -> V_12 ,
L_4 ) ;
if ( V_5 & V_22 )
F_4 ( & V_4 -> V_11 -> V_12 ,
L_5 ) ;
F_10 ( V_4 ) ;
}
if ( V_5 & V_25 ) {
F_4 ( & V_4 -> V_11 -> V_12 , L_6 ) ;
F_11 ( V_4 ) ;
}
if ( V_5 & ( V_26 |
V_28 |
V_27 ) ) {
if ( V_5 & V_28 )
F_4 ( & V_4 -> V_11 -> V_12 , L_7 ) ;
if ( V_5 & V_26 )
F_4 ( & V_4 -> V_11 -> V_12 ,
L_8 ) ;
if ( V_5 & V_27 )
F_4 ( & V_4 -> V_11 -> V_12 ,
L_9 ) ;
F_12 ( V_4 ) ;
}
}
F_8 ( V_4 -> V_19 , V_20 ,
V_4 -> V_29 . V_30 ) ;
}
void F_10 ( struct V_3 * V_4 )
{
T_2 V_31 ;
T_2 V_32 , error ;
T_3 * V_33 ;
struct V_34 * V_35 , * V_36 ;
unsigned V_37 ;
V_4 -> V_38 ++ ;
V_31 = V_4 -> V_29 . V_39 ;
F_4 ( & V_4 -> V_11 -> V_12 , L_10 , V_31 ) ;
if ( ( V_4 -> V_40 . V_41 != V_42 ) && V_4 -> V_13 . V_15 ) {
while ( ! ( V_4 -> V_29 . V_43 [ V_31 ] . V_44 &
V_45 ) ) {
V_33 = & V_4 -> V_29 . V_43 [ V_31 ] ;
V_33 -> V_46 &= V_47 |
V_48 ;
V_33 -> V_46 |= V_49 ;
V_33 -> V_44 = V_45 ;
V_31 = ( V_31 + 1 ) % V_50 ;
}
V_4 -> V_29 . V_39 = V_31 ;
return;
}
while ( ! ( V_4 -> V_29 . V_43 [ V_31 ] . V_44 &
V_45 ) ) {
V_33 = & V_4 -> V_29 . V_43 [ V_31 ] ;
F_4 ( & V_4 -> V_11 -> V_12 , L_11 ,
V_33 -> V_44 , V_33 -> V_46 ) ;
V_35 = V_4 -> V_29 . V_51 [ V_31 ] ;
V_37 = ( V_33 -> V_44 & V_52 ) >>
V_53 ;
F_4 ( & V_4 -> V_11 -> V_12 , L_12 ,
V_37 ) ;
switch ( V_4 -> V_40 . V_54 ) {
case V_55 :
V_37 -= V_56 ;
break;
case V_57 :
V_37 -= V_58 ;
break;
default:
break;
}
if ( V_33 -> V_44 & V_59 ) {
V_32 = V_60 |
V_61 |
V_62 ;
switch ( V_4 -> V_40 . V_63 ) {
case V_64 :
V_32 |= V_65 ;
if ( V_4 -> V_40 . V_54 == V_57 )
V_32 |= V_66 ;
break;
case V_67 :
case V_68 :
break;
default:
V_32 = 0 ;
}
if ( V_4 -> V_13 . V_14 ) {
V_32 &= ~ ( V_62 ||
V_65 ) ;
}
error = V_33 -> V_44 & V_32 ;
if ( error ) {
V_4 -> V_13 . V_69 ++ ;
F_4 ( & V_4 -> V_11 -> V_12 ,
L_13 ,
V_4 -> V_70 . V_71 & V_72 ? 1 : 0 ) ;
V_33 -> V_46 &= V_47 |
V_48 ;
V_33 -> V_46 |= V_49 ;
V_33 -> V_44 = V_45 ;
if ( error & V_60 ) {
if ( ! ( V_4 -> V_70 . V_71 & V_72 ) )
F_13 ( & V_4 -> V_11 -> V_12 ,
L_14 ) ;
V_4 -> V_13 . V_73 ++ ;
}
if ( error & V_61 ) {
if ( ! ( V_4 -> V_70 . V_71 & V_72 ) )
F_13 ( & V_4 -> V_11 -> V_12 ,
L_15 ) ;
V_4 -> V_13 . V_74 ++ ;
} else {
if ( error & V_62 ) {
if ( ! ( V_4 -> V_70 . V_71 & V_72 ) )
F_13 ( & V_4 -> V_11 -> V_12 ,
L_16 ) ;
V_4 -> V_13 . V_75 ++ ;
}
if ( error & V_66 ) {
if ( ! ( V_4 -> V_70 . V_71 & V_72 ) )
F_13 ( & V_4 -> V_11 -> V_12 ,
L_17 ) ;
V_4 -> V_13 . V_76 ++ ;
}
}
if ( error & V_65 ) {
if ( ! ( V_4 -> V_70 . V_71 & V_72 ) )
F_13 ( & V_4 -> V_11 -> V_12 , L_18 ) ;
V_4 -> V_13 . V_77 ++ ;
}
V_31 = ( V_31 + 1 ) % V_50 ;
V_4 -> V_70 . V_71 |= V_72 ;
continue;
}
}
V_33 -> V_46 &= V_47 |
V_48 ;
V_33 -> V_46 |= V_49 ;
if ( V_37 > 1600 ) {
V_4 -> V_13 . V_69 ++ ;
V_4 -> V_13 . V_78 ++ ;
if ( ! ( V_4 -> V_70 . V_71 & V_72 ) )
F_13 ( & V_4 -> V_11 -> V_12 , L_19 ,
V_33 -> V_44 ) ;
} else {
V_36 = F_14 ( V_79 ) ;
if ( V_36 != NULL ) {
V_33 -> V_80 = F_15 ( V_36 -> V_81 ) ;
V_4 -> V_29 . V_51 [ V_31 ] = V_36 ;
V_4 -> V_13 . V_82 ++ ;
V_4 -> V_13 . V_83 += V_37 ;
V_35 -> V_12 = V_4 -> V_12 ;
F_16 ( V_35 , V_37 ) ;
F_17 ( V_35 ) ;
V_35 -> V_84 = F_18 ( V_35 , V_35 -> V_12 ) ;
F_19 ( V_35 ) ;
if ( V_4 -> V_70 . V_71 & V_72 ) {
F_4 ( & V_4 -> V_11 -> V_12 ,
L_20 ) ;
V_4 -> V_70 . V_71 &= ~ V_72 ;
}
} else {
V_4 -> V_13 . V_69 ++ ;
V_4 -> V_13 . V_78 ++ ;
}
}
V_33 -> V_44 = V_45 ;
V_31 = ( V_31 + 1 ) % V_50 ;
}
V_4 -> V_29 . V_39 = V_31 ;
F_8 ( V_4 -> V_19 , V_85 , 0xFFFFFFFF ) ;
}
void F_12 ( struct V_3 * V_4 )
{
T_2 V_31 , V_86 ;
T_2 V_87 , error ;
T_4 * V_33 ;
F_20 ( & V_4 -> V_29 . V_88 ) ;
V_31 = V_4 -> V_29 . V_89 ;
V_86 = V_4 -> V_29 . V_90 ;
while ( V_31 != V_86 ) {
V_33 = & V_4 -> V_29 . V_91 [ V_31 ] ;
if ( V_33 -> V_92 & V_45 )
break;
F_4 ( & V_4 -> V_11 -> V_12 ,
L_21 ,
V_33 -> V_92 , V_33 -> V_93 ) ;
error = V_33 -> V_92 & ( V_94 |
V_95 |
V_96 |
V_97 |
V_98 |
V_99 |
V_100 ) ;
V_87 = V_33 -> V_93 & V_101 ;
V_33 -> V_92 = 0 ;
V_33 -> V_93 &= V_102 |
V_103 ;
V_33 -> V_104 = 0 ;
V_4 -> V_29 . V_105 ++ ;
if ( V_87 != V_101 ) {
V_31 = ( V_31 + 1 ) % V_106 ;
continue;
}
if ( V_4 -> V_29 . V_107 [ V_31 ] ) {
V_4 -> V_13 . V_108 ++ ;
V_4 -> V_13 . V_109 += V_4 -> V_29 . V_107 [ V_31 ] -> V_110 ;
F_21 ( V_4 -> V_29 . V_107 [ V_31 ] ) ;
V_4 -> V_29 . V_107 [ V_31 ] = NULL ;
}
if ( error > 0 ) {
V_4 -> V_13 . V_111 ++ ;
if ( error & V_95 ) {
F_13 ( & V_4 -> V_11 -> V_12 , L_22 ) ;
V_4 -> V_13 . V_112 ++ ;
}
if ( V_4 -> V_40 . V_41 != V_42 ) {
if ( error & V_96 ) {
F_13 ( & V_4 -> V_11 -> V_12 , L_23 ) ;
V_4 -> V_13 . V_113 ++ ;
}
if ( error & V_97 ) {
F_13 ( & V_4 -> V_11 -> V_12 , L_24 ) ;
V_4 -> V_13 . V_114 ++ ;
}
}
if ( error & V_98 ) {
F_13 ( & V_4 -> V_11 -> V_12 , L_25 ) ;
V_4 -> V_13 . V_115 ++ ;
}
if ( error & V_99 ) {
F_13 ( & V_4 -> V_11 -> V_12 , L_26
L_27 ) ;
V_4 -> V_13 . V_116 ++ ;
F_22 ( & V_4 -> V_29 . V_88 ) ;
F_23 ( V_4 ) ;
return;
}
if ( error & V_100 ) {
F_13 ( & V_4 -> V_11 -> V_12 , L_28 ) ;
V_4 -> V_13 . V_117 ++ ;
}
}
V_31 = ( V_31 + 1 ) % V_106 ;
}
V_4 -> V_29 . V_89 = V_31 ;
if ( V_4 -> V_29 . V_118 &&
( V_4 -> V_29 . V_105 >= ( V_106 / 2 ) ) ) {
V_4 -> V_29 . V_118 = 0 ;
F_24 ( V_4 -> V_12 ) ;
}
F_22 ( & V_4 -> V_29 . V_88 ) ;
}
void F_11 ( struct V_3 * V_4 )
{
T_2 V_5 ;
F_25 ( V_4 , V_119 ) ;
V_5 = F_9 ( V_4 -> V_19 , V_120 ) ;
F_26 ( V_4 -> V_19 , V_120 ,
V_121 ) ;
switch ( V_5 & V_121 ) {
case V_122 :
F_27 ( V_4 -> V_19 , V_120 ,
V_123 ) ;
break;
case V_123 :
F_27 ( V_4 -> V_19 , V_120 ,
V_124 ) ;
break;
case V_124 :
F_27 ( V_4 -> V_19 , V_120 ,
V_125 ) ;
break;
case V_125 :
default:
F_27 ( V_4 -> V_19 , V_120 ,
V_126 ) ;
break;
}
F_25 ( V_4 , V_127 ) ;
}
void F_7 ( struct V_3 * V_4 )
{
T_2 V_128 , V_129 ;
#if 0
exar7250_write(sc, SBE_2T3E3_FRAMER_REG_BLOCK_INTERRUPT_ENABLE, 0);
#endif
V_129 = V_4 -> V_13 . V_15 ;
V_128 = F_28 ( V_4 , V_130 ) ;
F_4 ( & V_4 -> V_11 -> V_12 , L_29 , V_128 ) ;
switch ( V_4 -> V_40 . V_131 ) {
case V_132 :
case V_133 :
F_29 ( V_4 , V_128 ) ;
break;
case V_134 :
case V_135 :
F_30 ( V_4 , V_128 ) ;
break;
default:
break;
}
if ( V_4 -> V_13 . V_15 != V_129 ) {
if ( V_4 -> V_13 . V_15 ) {
if ( V_4 -> V_40 . V_41 == V_136 ) {
F_4 ( & V_4 -> V_11 -> V_12 , L_30 ) ;
F_31 ( V_4 ) ;
}
} else if ( V_4 -> V_70 . V_71 & V_137 ) {
F_4 ( & V_4 -> V_11 -> V_12 , L_31 ) ;
V_4 -> V_13 . V_15 = 1 ;
F_10 ( V_4 ) ;
V_4 -> V_13 . V_15 = 0 ;
if ( V_4 -> V_40 . V_138 ) {
F_32 ( V_4 , V_119 ) ;
F_32 ( V_4 , V_127 ) ;
}
F_33 ( V_4 ) ;
}
}
#if 0
exar7250_write(sc, SBE_2T3E3_FRAMER_REG_BLOCK_INTERRUPT_ENABLE,
SBE_2T3E3_FRAMER_VAL_RX_INTERRUPT_ENABLE |
SBE_2T3E3_FRAMER_VAL_TX_INTERRUPT_ENABLE
);
#endif
}
void F_30 ( struct V_3 * V_4 , T_2 V_139 )
{
T_2 V_128 , V_140 ;
if ( V_139 & V_141 ) {
V_128 = F_28 ( V_4 , V_142 ) ;
if ( V_128 ) {
F_4 ( & V_4 -> V_11 -> V_12 ,
L_32 ,
V_128 ) ;
V_140 = F_28 ( V_4 , V_143 ) ;
#if 0
if (status & SBE_2T3E3_FRAMER_VAL_T3_RX_LOS_INTERRUPT_STATUS) {
dev_dbg(&sc->pdev->dev,
"Framer interrupt T3: LOS\n");
sc->s.LOS = result & SBE_2T3E3_FRAMER_VAL_T3_RX_LOS ? 1 : 0;
}
#else
F_5 ( V_4 ) ;
#endif
if ( V_128 & V_144 ) {
V_4 -> V_13 . V_15 = V_140 & V_145 ? 1 : 0 ;
F_4 ( & V_4 -> V_11 -> V_12 ,
L_33 ,
V_4 -> V_13 . V_15 ) ;
}
F_34 ( V_4 , V_146 ,
V_147 |
V_148 ) ;
#if 0
SBE_2T3E3_FRAMER_VAL_T3_RX_CP_BIT_ERROR_INTERRUPT_ENABLE |
SBE_2T3E3_FRAMER_VAL_T3_RX_LOS_INTERRUPT_ENABLE |
SBE_2T3E3_FRAMER_VAL_T3_RX_AIS_INTERRUPT_ENABLE |
SBE_2T3E3_FRAMER_VAL_T3_RX_IDLE_INTERRUPT_ENABLE |
SBE_2T3E3_FRAMER_VAL_T3_RX_FERF_INTERRUPT_ENABLE |
SBE_2T3E3_FRAMER_VAL_T3_RX_AIC_INTERRUPT_ENABLE |
SBE_2T3E3_FRAMER_VAL_T3_RX_OOF_INTERRUPT_ENABLE |
SBE_2T3E3_FRAMER_VAL_T3_RX_P_BIT_INTERRUPT_ENABLE
#endif
}
V_128 = F_28 ( V_4 , V_149 ) ;
if ( V_128 ) {
F_4 ( & V_4 -> V_11 -> V_12 ,
L_34 ,
V_128 ) ;
#if 0
exar7250_write(sc, SBE_2T3E3_FRAMER_REG_T3_RX_FEAC_INTERRUPT_ENABLE_STATUS,
SBE_2T3E3_FRAMER_VAL_T3_RX_FEAC_REMOVE_INTERRUPT_ENABLE |
SBE_2T3E3_FRAMER_VAL_T3_RX_FEAC_VALID_INTERRUPT_ENABLE
);
#endif
}
V_128 = F_28 ( V_4 , V_150 ) ;
if ( V_128 )
F_4 ( & V_4 -> V_11 -> V_12 ,
L_35 ,
V_128 ) ;
}
if ( V_139 & V_151 ) {
V_128 = F_28 ( V_4 , V_152 ) ;
F_4 ( & V_4 -> V_11 -> V_12 , L_36 ,
V_128 ) ;
V_128 = F_28 ( V_4 , V_153 ) ;
F_4 ( & V_4 -> V_11 -> V_12 , L_37 ,
V_128 ) ;
}
}
void F_29 ( struct V_3 * V_4 , T_2 V_139 )
{
T_2 V_128 , V_140 ;
if ( V_139 & V_141 ) {
V_128 = F_28 ( V_4 , V_154 ) ;
if ( V_128 ) {
F_4 ( & V_4 -> V_11 -> V_12 ,
L_38 ,
V_128 ) ;
V_140 = F_28 ( V_4 , V_155 ) ;
#if 0
if (status & SBE_2T3E3_FRAMER_VAL_E3_RX_LOS_INTERRUPT_STATUS) {
dev_dbg(&sc->pdev->dev,
"Framer interrupt E3: LOS\n");
sc->s.LOS = result & SBE_2T3E3_FRAMER_VAL_E3_RX_LOS ? 1 : 0;
}
#else
F_5 ( V_4 ) ;
#endif
if ( V_128 & V_156 ) {
V_4 -> V_13 . V_15 = V_140 & V_157 ? 1 : 0 ;
F_4 ( & V_4 -> V_11 -> V_12 ,
L_39 ,
V_4 -> V_13 . V_15 ) ;
}
F_34 ( V_4 , V_158 ,
V_159 |
V_160
) ;
#if 0
SBE_2T3E3_FRAMER_VAL_E3_RX_COFA_INTERRUPT_ENABLE |
SBE_2T3E3_FRAMER_VAL_E3_RX_OOF_INTERRUPT_ENABLE |
SBE_2T3E3_FRAMER_VAL_E3_RX_LOF_INTERRUPT_ENABLE |
SBE_2T3E3_FRAMER_VAL_E3_RX_LOS_INTERRUPT_ENABLE |
SBE_2T3E3_FRAMER_VAL_E3_RX_AIS_INTERRUPT_ENABLE
#endif
}
V_128 = F_28 ( V_4 , V_161 ) ;
if ( V_128 ) {
F_4 ( & V_4 -> V_11 -> V_12 ,
L_40 ,
V_128 ) ;
#if 0
exar7250_write(sc, SBE_2T3E3_FRAMER_REG_E3_RX_INTERRUPT_ENABLE_2,
SBE_2T3E3_FRAMER_VAL_E3_RX_FEBE_INTERRUPT_ENABLE |
SBE_2T3E3_FRAMER_VAL_E3_RX_FERF_INTERRUPT_ENABLE |
SBE_2T3E3_FRAMER_VAL_E3_RX_FRAMING_BYTE_ERROR_INTERRUPT_ENABLE);
#endif
}
}
if ( V_139 & V_151 ) {
V_128 = F_28 ( V_4 , V_162 ) ;
F_4 ( & V_4 -> V_11 -> V_12 , L_41 ,
V_128 ) ;
}
}
