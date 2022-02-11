void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 ;
if ( V_2 -> V_6 || V_2 -> V_7 )
return;
V_5 = F_2 ( V_2 , V_8 ) ;
switch ( V_4 -> V_9 ) {
case V_10 :
F_3 ( V_2 , V_8 , ( V_5 & 0xf0 ) | V_11 | V_12 ) ;
break;
case V_13 :
F_3 ( V_2 , V_8 , ( V_5 & 0x0f ) | V_11 ) ;
break;
default:
break;
}
V_4 -> V_14 = true ;
}
void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 ;
struct V_15 * V_16 = F_5 ( V_2 ) ;
if ( V_2 -> V_6 || V_2 -> V_7 )
goto exit;
V_5 = F_2 ( V_2 , V_8 ) ;
switch ( V_4 -> V_9 ) {
case V_10 :
if ( V_16 -> V_17 ) {
V_5 &= 0x90 ;
F_3 ( V_2 , V_8 , ( V_5 | V_18 ) ) ;
V_5 = F_2 ( V_2 , V_19 ) ;
V_5 &= 0xFE ;
F_3 ( V_2 , V_19 , V_5 ) ;
} else {
F_3 ( V_2 , V_8 , ( V_5 | V_18 | V_11 | V_12 ) ) ;
}
break;
case V_13 :
V_5 &= 0x0f ;
F_3 ( V_2 , V_8 , ( V_5 | V_18 ) ) ;
break;
default:
break;
}
exit:
V_4 -> V_14 = false ;
}
void F_6 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = & ( V_2 -> V_22 ) ;
V_21 -> V_23 = V_24 ;
F_7 ( V_2 , & ( V_21 -> V_25 ) , V_10 ) ;
F_7 ( V_2 , & ( V_21 -> V_26 ) , V_13 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_20 * V_22 = & ( V_2 -> V_22 ) ;
F_9 ( & ( V_22 -> V_25 ) ) ;
F_9 ( & ( V_22 -> V_26 ) ) ;
}
