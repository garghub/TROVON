void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 ;
if ( V_2 -> V_6 || V_2 -> V_7 )
return;
V_5 = F_2 ( V_2 , V_8 ) ;
F_3 ( V_2 , V_8 , ( V_5 & 0xf0 ) | F_4 ( 5 ) | F_4 ( 6 ) ) ;
V_4 -> V_9 = true ;
}
void F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 ;
struct V_10 * V_11 = F_6 ( V_2 ) ;
if ( V_2 -> V_6 || V_2 -> V_7 )
goto exit;
V_5 = F_2 ( V_2 , V_8 ) ;
if ( V_11 -> V_12 ) {
V_5 &= 0x90 ;
F_3 ( V_2 , V_8 , ( V_5 | F_4 ( 3 ) ) ) ;
V_5 = F_2 ( V_2 , V_13 ) ;
V_5 &= 0xFE ;
F_3 ( V_2 , V_13 , V_5 ) ;
} else {
F_3 ( V_2 , V_8 , ( V_5 | F_4 ( 3 ) | F_4 ( 5 ) | F_4 ( 6 ) ) ) ;
}
exit:
V_4 -> V_9 = false ;
}
void F_7 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & ( V_2 -> V_16 ) ;
struct V_10 * V_17 = F_6 ( V_2 ) ;
V_15 -> V_18 = true ;
V_15 -> V_19 = V_20 ;
V_17 -> V_12 = true ;
F_8 ( V_2 , & ( V_15 -> V_21 ) ) ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_14 * V_16 = & ( V_2 -> V_16 ) ;
F_10 ( & ( V_16 -> V_21 ) ) ;
}
