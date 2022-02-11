void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 = 0 ;
if ( ( V_2 -> V_6 == true ) || ( V_2 -> V_7 == true ) )
return;
switch ( V_4 -> V_8 ) {
case V_9 :
break;
case V_10 :
F_2 ( V_2 , V_11 ,
( V_5 & 0xf0 ) | F_3 ( 5 ) | F_3 ( 6 ) ) ;
break;
case V_12 :
F_2 ( V_2 , V_13 , ( V_5 & 0x00 ) | F_3 ( 6 ) ) ;
break;
case V_14 :
V_5 = F_4 ( V_2 , V_15 ) ;
F_2 ( V_2 , V_15 , ( V_5 & 0x80 ) | F_3 ( 5 ) ) ;
break;
default:
break;
}
V_4 -> V_16 = true ;
}
void F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 = 0 ;
if ( ( V_2 -> V_6 ) || ( V_2 -> V_7 ) )
goto exit;
switch ( V_4 -> V_8 ) {
case V_9 :
break;
case V_10 :
F_2 ( V_2 , V_11 ,
( V_5 & 0xf0 ) | F_3 ( 5 ) | F_3 ( 6 ) ) ;
break;
case V_12 :
F_2 ( V_2 , V_13 ,
( V_5 & 0x00 ) | F_3 ( 5 ) | F_3 ( 6 ) ) ;
break;
case V_14 :
V_5 = F_4 ( V_2 , V_15 ) ;
F_2 ( V_2 , V_15 ,
( V_5 & 0x80 ) | F_3 ( 3 ) | F_3 ( 5 ) ) ;
break;
default:
break;
}
exit:
V_4 -> V_16 = false ;
}
void
F_6 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = & V_2 -> V_19 ;
V_18 -> V_20 = V_21 ;
F_7 ( V_2 , & V_18 -> V_22 , V_14 ) ;
}
void
F_8 ( struct V_1 * V_2 )
{
struct V_17 * V_19 = & V_2 -> V_19 ;
F_9 ( & V_19 -> V_22 ) ;
}
