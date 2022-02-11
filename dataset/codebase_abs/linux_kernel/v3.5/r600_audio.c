static bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
switch ( V_3 -> V_4 ) {
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
return true ;
}
return false ;
}
static int F_3 ( struct V_16 * V_17 )
{
return ( V_17 -> V_18 >= V_19 && ! F_4 ( V_17 ) )
|| V_17 -> V_18 == V_20
|| V_17 -> V_18 == V_21
|| V_17 -> V_18 == V_22 ;
}
struct V_23 F_5 ( struct V_16 * V_17 )
{
struct V_23 V_24 ;
T_1 V_25 ;
V_25 = F_6 ( V_26 ) ;
V_24 . V_27 = ( V_25 & 0x7 ) + 1 ;
switch ( ( V_25 & 0xF0 ) >> 4 ) {
case 0x0 :
V_24 . V_28 = 8 ;
break;
case 0x1 :
V_24 . V_28 = 16 ;
break;
case 0x2 :
V_24 . V_28 = 20 ;
break;
case 0x3 :
V_24 . V_28 = 24 ;
break;
case 0x4 :
V_24 . V_28 = 32 ;
break;
default:
F_7 ( V_17 -> V_29 , L_1 ,
( int ) V_25 ) ;
V_24 . V_28 = 16 ;
}
if ( V_25 & 0x4000 )
V_24 . V_30 = 44100 ;
else
V_24 . V_30 = 48000 ;
V_24 . V_30 *= ( ( V_25 >> 11 ) & 0x7 ) + 1 ;
V_24 . V_30 /= ( ( V_25 >> 8 ) & 0x7 ) + 1 ;
V_25 = F_6 ( V_31 ) ;
V_24 . V_32 = V_25 & 0xff ;
V_24 . V_33 = ( V_25 >> 8 ) & 0xff ;
return V_24 ;
}
void F_8 ( struct V_34 * V_35 )
{
struct V_16 * V_17 = F_9 ( V_35 , struct V_16 ,
V_36 ) ;
struct V_37 * V_29 = V_17 -> V_38 ;
struct V_23 V_39 = F_5 ( V_17 ) ;
struct V_1 * V_2 ;
bool V_40 = false ;
if ( V_17 -> V_39 . V_27 != V_39 . V_27 ||
V_17 -> V_39 . V_30 != V_39 . V_30 ||
V_17 -> V_39 . V_28 != V_39 . V_28 ||
V_17 -> V_39 . V_32 != V_39 . V_32 ||
V_17 -> V_39 . V_33 != V_39 . V_33 ) {
V_17 -> V_39 = V_39 ;
V_40 = true ;
}
F_10 (encoder, &dev->mode_config.encoder_list, head) {
if ( ! F_1 ( V_2 ) )
continue;
if ( V_40 || F_11 ( V_2 ) )
F_12 ( V_2 ) ;
}
}
static void F_13 ( struct V_16 * V_17 , bool V_41 )
{
T_2 V_25 = 0 ;
F_14 ( L_2 , V_41 ? L_3 : L_4 ) ;
if ( F_15 ( V_17 ) ) {
if ( V_41 ) {
V_25 |= 0x81000000 ;
V_25 |= 0x0e1000f0 ;
}
F_16 ( V_42 , V_25 ) ;
} else {
F_17 ( V_43 ,
V_41 ? 0x81000000 : 0x0 , ~ 0x81000000 ) ;
}
V_17 -> V_44 = V_41 ;
}
int F_18 ( struct V_16 * V_17 )
{
if ( ! V_45 || ! F_3 ( V_17 ) )
return 0 ;
F_13 ( V_17 , true ) ;
V_17 -> V_39 . V_27 = - 1 ;
V_17 -> V_39 . V_30 = - 1 ;
V_17 -> V_39 . V_28 = - 1 ;
V_17 -> V_39 . V_32 = 0 ;
V_17 -> V_39 . V_33 = 0 ;
return 0 ;
}
void F_19 ( struct V_1 * V_2 , int clock )
{
struct V_37 * V_29 = V_2 -> V_29 ;
struct V_16 * V_17 = V_29 -> V_46 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_47 * V_48 = V_3 -> V_49 ;
struct V_50 * V_50 = F_20 ( V_2 -> V_51 ) ;
int V_52 = 48000 ;
switch ( V_3 -> V_4 ) {
case V_7 :
case V_8 :
F_17 ( V_53 , 0 , ~ 0x301 ) ;
break;
case V_12 :
case V_14 :
case V_15 :
case V_13 :
F_17 ( V_53 , 0x100 , ~ 0x301 ) ;
break;
default:
F_7 ( V_17 -> V_29 , L_5 ,
V_3 -> V_4 ) ;
return;
}
if ( F_15 ( V_17 ) ) {
F_16 ( V_54 , V_52 * 10 ) ;
F_16 ( V_55 , clock * 10 ) ;
F_16 ( V_56 , 0x00000071 ) ;
F_16 ( 0x5ac , V_50 -> V_57 ) ;
} else {
switch ( V_48 -> V_58 ) {
case 0 :
F_16 ( V_59 , V_52 * 50 ) ;
F_16 ( V_60 , clock * 100 ) ;
F_16 ( V_61 , 0 ) ;
break;
case 1 :
F_16 ( V_62 , V_52 * 50 ) ;
F_16 ( V_63 , clock * 100 ) ;
F_16 ( V_61 , 1 ) ;
break;
default:
F_7 ( V_17 -> V_29 ,
L_6 ,
V_3 -> V_4 ) ;
return;
}
}
}
void F_21 ( struct V_16 * V_17 )
{
if ( ! V_17 -> V_44 )
return;
F_13 ( V_17 , false ) ;
}
