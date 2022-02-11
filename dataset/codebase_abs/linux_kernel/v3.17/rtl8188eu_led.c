void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 ;
if ( V_2 -> V_6 || V_2 -> V_7 )
return;
V_5 = F_2 ( V_2 , V_8 ) ;
F_3 ( V_2 , V_8 , ( V_5 & 0xf0 ) | V_9 | V_10 ) ;
V_4 -> V_11 = true ;
}
void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 ;
struct V_12 * V_13 = F_5 ( V_2 ) ;
if ( V_2 -> V_6 || V_2 -> V_7 )
goto exit;
V_5 = F_2 ( V_2 , V_8 ) ;
if ( V_13 -> V_14 ) {
V_5 &= 0x90 ;
F_3 ( V_2 , V_8 , ( V_5 | V_15 ) ) ;
V_5 = F_2 ( V_2 , V_16 ) ;
V_5 &= 0xFE ;
F_3 ( V_2 , V_16 , V_5 ) ;
} else {
F_3 ( V_2 , V_8 , ( V_5 | V_15 | V_9 | V_10 ) ) ;
}
exit:
V_4 -> V_11 = false ;
}
void F_6 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = & ( V_2 -> V_19 ) ;
struct V_12 * V_20 = F_5 ( V_2 ) ;
V_18 -> V_21 = true ;
V_18 -> V_22 = V_23 ;
V_20 -> V_14 = true ;
F_7 ( V_2 , & ( V_18 -> V_24 ) ) ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_17 * V_19 = & ( V_2 -> V_19 ) ;
F_9 ( & ( V_19 -> V_24 ) ) ;
}
