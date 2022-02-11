void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 = 0 ;
if ( ( V_2 -> V_6 == true ) || ( V_2 -> V_7 == true ) )
return;
switch ( V_4 -> V_8 ) {
case V_9 :
break;
case V_10 :
F_2 ( V_2 , V_11 , ( V_5 & 0xf0 ) | V_12 | V_13 ) ;
break;
case V_14 :
F_2 ( V_2 , V_15 , ( V_5 & 0x00 ) | V_13 ) ;
break;
case V_16 :
V_5 = F_3 ( V_2 , V_17 ) ;
F_2 ( V_2 , V_17 , ( V_5 & 0x80 ) | V_12 ) ;
break;
default:
break;
}
V_4 -> V_18 = true ;
}
void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 = 0 ;
if ( ( V_2 -> V_6 ) || ( V_2 -> V_7 ) )
goto exit;
switch ( V_4 -> V_8 ) {
case V_9 :
break;
case V_10 :
F_2 ( V_2 , V_11 , ( V_5 & 0xf0 ) | V_12 | V_13 ) ;
break;
case V_14 :
F_2 ( V_2 , V_15 , ( V_5 & 0x00 ) | V_12 | V_13 ) ;
break;
case V_16 :
V_5 = F_3 ( V_2 , V_17 ) ;
F_2 ( V_2 , V_17 , ( V_5 & 0x80 ) | V_19 | V_12 ) ;
break;
default:
break;
}
exit:
V_4 -> V_18 = false ;
}
void
F_5 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = & V_2 -> V_22 ;
V_21 -> V_23 = V_24 ;
F_6 ( V_2 , & V_21 -> V_25 , V_16 ) ;
}
void
F_7 ( struct V_1 * V_2 )
{
struct V_20 * V_22 = & V_2 -> V_22 ;
F_8 ( & V_22 -> V_25 ) ;
}
