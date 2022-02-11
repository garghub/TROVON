static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_5 V_6 )
{
V_4 -> V_2 = V_2 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_7 = false ;
}
void F_2 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_8 ;
struct V_9 * V_10 = V_9 ( V_2 ) ;
F_3 ( V_10 , V_11 , V_12 ,
L_1 , V_13 , V_4 -> V_6 ) ;
switch ( V_4 -> V_6 ) {
case V_14 :
break;
case V_15 :
V_8 = F_4 ( V_10 , V_13 ) ;
V_8 &= ~ F_5 ( 6 ) ;
F_6 ( V_10 , V_13 , ( V_8 & 0xf0 ) | F_5 ( 5 ) ) ;
break;
case V_16 :
V_8 = F_4 ( V_10 , V_17 ) ;
F_6 ( V_10 , V_17 , V_8 & 0x10 ) ;
break;
default:
F_3 ( V_10 , V_18 , V_19 ,
L_2 ) ;
break;
}
V_4 -> V_7 = true ;
}
void F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_20 * V_21 = F_8 ( V_2 ) ;
T_1 V_8 ;
F_3 ( V_10 , V_11 , V_12 ,
L_1 , V_13 , V_4 -> V_6 ) ;
V_8 = F_4 ( V_10 , V_13 ) ;
switch ( V_4 -> V_6 ) {
case V_14 :
break;
case V_15 :
V_8 &= 0xf0 ;
if ( V_21 -> V_22 . V_23 ) {
V_8 &= 0x90 ;
F_6 ( V_10 , V_13 , ( V_8 | F_5 ( 3 ) ) ) ;
V_8 = F_4 ( V_10 , V_24 ) ;
V_8 &= 0xFE ;
F_6 ( V_10 , V_24 , V_8 ) ;
} else {
V_8 &= ~ F_5 ( 6 ) ;
F_6 ( V_10 , V_13 ,
( V_8 | F_5 ( 3 ) | F_5 ( 5 ) ) ) ;
}
break;
case V_16 :
V_8 = F_4 ( V_10 , V_17 ) ;
V_8 &= 0x10 ;
F_6 ( V_10 , V_17 , V_8 | F_5 ( 3 ) ) ;
break;
default:
F_3 ( V_10 , V_18 , V_19 ,
L_3 ) ;
break;
}
V_4 -> V_7 = false ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_8 ( V_2 ) ;
F_1 ( V_2 , & ( V_21 -> V_22 . V_25 ) , V_15 ) ;
F_1 ( V_2 , & ( V_21 -> V_22 . V_26 ) , V_16 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
enum V_27 V_28 )
{
struct V_20 * V_21 = F_8 ( V_2 ) ;
struct V_3 * V_29 = & ( V_21 -> V_22 . V_25 ) ;
switch ( V_28 ) {
case V_30 :
case V_31 :
case V_32 :
F_2 ( V_2 , V_29 ) ;
break;
case V_33 :
F_7 ( V_2 , V_29 ) ;
break;
default:
break;
}
}
void F_11 ( struct V_1 * V_2 ,
enum V_27 V_28 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_34 * V_35 = F_12 ( V_9 ( V_2 ) ) ;
if ( ( V_35 -> V_36 > V_37 ) &&
( V_28 == V_38 ||
V_28 == V_39 ||
V_28 == V_40 ||
V_28 == V_31 ||
V_28 == V_32 ||
V_28 == V_41 ||
V_28 == V_30 ) ) {
return;
}
F_3 ( V_10 , V_11 , V_12 , L_4 , V_28 ) ;
F_10 ( V_2 , V_28 ) ;
}
