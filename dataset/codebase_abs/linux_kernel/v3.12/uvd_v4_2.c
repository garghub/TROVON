int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_2 V_4 ;
V_3 = V_2 -> V_5 . V_6 >> 3 ;
V_4 = F_2 ( V_2 -> V_7 -> V_4 + 4 ) >> 3 ;
F_3 ( V_8 , V_3 ) ;
F_3 ( V_9 , V_4 ) ;
V_3 += V_4 ;
V_4 = V_10 >> 3 ;
F_3 ( V_11 , V_3 ) ;
F_3 ( V_12 , V_4 ) ;
V_3 += V_4 ;
V_4 = V_13 >> 3 ;
F_3 ( V_14 , V_3 ) ;
F_3 ( V_15 , V_4 ) ;
V_3 = ( V_2 -> V_5 . V_6 >> 28 ) & 0xF ;
F_3 ( V_16 , ( V_3 << 12 ) | ( V_3 << 0 ) ) ;
V_3 = ( V_2 -> V_5 . V_6 >> 32 ) & 0xFF ;
F_3 ( V_17 , V_3 | ( 0x9 << 16 ) | ( 0x1 << 31 ) ) ;
return 0 ;
}
