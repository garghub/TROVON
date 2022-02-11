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
return F_4 ( V_17 ) && ! F_5 ( V_17 ) ;
}
struct V_18 F_6 ( struct V_16 * V_17 )
{
struct V_18 V_19 ;
T_1 V_20 ;
V_20 = F_7 ( V_21 ) ;
V_19 . V_22 = ( V_20 & 0x7 ) + 1 ;
switch ( ( V_20 & 0xF0 ) >> 4 ) {
case 0x0 :
V_19 . V_23 = 8 ;
break;
case 0x1 :
V_19 . V_23 = 16 ;
break;
case 0x2 :
V_19 . V_23 = 20 ;
break;
case 0x3 :
V_19 . V_23 = 24 ;
break;
case 0x4 :
V_19 . V_23 = 32 ;
break;
default:
F_8 ( V_17 -> V_24 , L_1 ,
( int ) V_20 ) ;
V_19 . V_23 = 16 ;
}
if ( V_20 & 0x4000 )
V_19 . V_25 = 44100 ;
else
V_19 . V_25 = 48000 ;
V_19 . V_25 *= ( ( V_20 >> 11 ) & 0x7 ) + 1 ;
V_19 . V_25 /= ( ( V_20 >> 8 ) & 0x7 ) + 1 ;
V_20 = F_7 ( V_26 ) ;
V_19 . V_27 = V_20 & 0xff ;
V_19 . V_28 = ( V_20 >> 8 ) & 0xff ;
return V_19 ;
}
void F_9 ( struct V_29 * V_30 )
{
struct V_16 * V_17 = F_10 ( V_30 , struct V_16 ,
V_31 ) ;
struct V_32 * V_24 = V_17 -> V_33 ;
struct V_18 V_34 = F_6 ( V_17 ) ;
struct V_1 * V_2 ;
bool V_35 = false ;
if ( V_17 -> V_36 . V_37 [ 0 ] . V_22 != V_34 . V_22 ||
V_17 -> V_36 . V_37 [ 0 ] . V_25 != V_34 . V_25 ||
V_17 -> V_36 . V_37 [ 0 ] . V_23 != V_34 . V_23 ||
V_17 -> V_36 . V_37 [ 0 ] . V_27 != V_34 . V_27 ||
V_17 -> V_36 . V_37 [ 0 ] . V_28 != V_34 . V_28 ) {
V_17 -> V_36 . V_37 [ 0 ] = V_34 ;
V_35 = true ;
}
F_11 (encoder, &dev->mode_config.encoder_list, head) {
if ( ! F_1 ( V_2 ) )
continue;
if ( V_35 || F_12 ( V_2 ) )
F_13 ( V_2 ) ;
}
}
void F_14 ( struct V_16 * V_17 ,
struct V_18 * V_37 ,
bool V_38 )
{
T_2 V_20 = 0 ;
if ( ! V_37 )
return;
if ( F_15 ( V_17 ) ) {
if ( V_38 ) {
V_20 |= 0x81000000 ;
V_20 |= 0x0e1000f0 ;
}
F_16 ( V_39 , V_20 ) ;
} else {
F_17 ( V_40 ,
V_38 ? 0x81000000 : 0x0 , ~ 0x81000000 ) ;
}
}
int F_18 ( struct V_16 * V_17 )
{
if ( ! V_41 || ! F_3 ( V_17 ) )
return 0 ;
V_17 -> V_36 . V_42 = true ;
V_17 -> V_36 . V_43 = 1 ;
V_17 -> V_36 . V_37 [ 0 ] . V_22 = - 1 ;
V_17 -> V_36 . V_37 [ 0 ] . V_25 = - 1 ;
V_17 -> V_36 . V_37 [ 0 ] . V_23 = - 1 ;
V_17 -> V_36 . V_37 [ 0 ] . V_27 = 0 ;
V_17 -> V_36 . V_37 [ 0 ] . V_28 = 0 ;
V_17 -> V_36 . V_37 [ 0 ] . V_44 = 0 ;
F_14 ( V_17 , & V_17 -> V_36 . V_37 [ 0 ] , false ) ;
return 0 ;
}
void F_19 ( struct V_16 * V_17 )
{
if ( ! V_17 -> V_36 . V_42 )
return;
F_14 ( V_17 , & V_17 -> V_36 . V_37 [ 0 ] , false ) ;
V_17 -> V_36 . V_42 = false ;
}
struct V_18 * F_20 ( struct V_16 * V_17 )
{
return & V_17 -> V_36 . V_37 [ 0 ] ;
}
