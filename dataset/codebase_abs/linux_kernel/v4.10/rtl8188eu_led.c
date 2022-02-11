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
if ( V_2 -> V_6 || V_2 -> V_7 )
goto exit;
V_5 = F_2 ( V_2 , V_8 ) ;
V_5 &= 0x90 ;
F_3 ( V_2 , V_8 , ( V_5 | F_4 ( 3 ) ) ) ;
V_5 = F_2 ( V_2 , V_10 ) ;
V_5 &= 0xFE ;
F_3 ( V_2 , V_10 , V_5 ) ;
exit:
V_4 -> V_9 = false ;
}
void F_6 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = & ( V_2 -> V_13 ) ;
F_7 ( V_2 , & ( V_12 -> V_14 ) ) ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_11 * V_13 = & ( V_2 -> V_13 ) ;
F_9 ( & ( V_13 -> V_14 ) ) ;
}
