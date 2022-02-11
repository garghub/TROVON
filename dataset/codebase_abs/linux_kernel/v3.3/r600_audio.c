static int F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 >= V_4 && ! F_2 ( V_2 ) )
|| V_2 -> V_3 == V_5
|| V_2 -> V_3 == V_6
|| V_2 -> V_3 == V_7 ;
}
int F_3 ( struct V_1 * V_2 )
{
return ( F_4 ( V_8 ) & 0x7 ) + 1 ;
}
int F_5 ( struct V_1 * V_2 )
{
T_1 V_9 = ( F_4 ( V_8 ) & 0xF0 ) >> 4 ;
switch ( V_9 ) {
case 0x0 : return 8 ;
case 0x1 : return 16 ;
case 0x2 : return 20 ;
case 0x3 : return 24 ;
case 0x4 : return 32 ;
}
F_6 ( V_2 -> V_10 , L_1 ,
( int ) V_9 ) ;
return 16 ;
}
int F_7 ( struct V_1 * V_2 )
{
T_1 V_9 = F_4 ( V_8 ) ;
T_1 V_11 ;
if ( V_9 & 0x4000 )
V_11 = 44100 ;
else
V_11 = 48000 ;
V_11 *= ( ( V_9 >> 11 ) & 0x7 ) + 1 ;
V_11 /= ( ( V_9 >> 8 ) & 0x7 ) + 1 ;
return V_11 ;
}
T_2 F_8 ( struct V_1 * V_2 )
{
return F_4 ( V_12 ) & 0xff ;
}
T_2 F_9 ( struct V_1 * V_2 )
{
return ( F_4 ( V_12 ) >> 8 ) & 0xff ;
}
void F_10 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_13 ,
V_14 + F_12 ( V_15 ) ) ;
}
static void F_13 ( unsigned long V_16 )
{
struct V_1 * V_2 = (struct V_1 * ) V_16 ;
struct V_17 * V_10 = V_2 -> V_18 ;
int V_19 = F_3 ( V_2 ) ;
int V_20 = F_7 ( V_2 ) ;
int V_21 = F_5 ( V_2 ) ;
T_2 V_22 = F_8 ( V_2 ) ;
T_2 V_23 = F_9 ( V_2 ) ;
struct V_24 * V_25 ;
int V_26 = 0 , V_27 = 0 ;
V_26 |= V_19 != V_2 -> V_28 ;
V_26 |= V_20 != V_2 -> V_29 ;
V_26 |= V_21 != V_2 -> V_30 ;
V_26 |= V_22 != V_2 -> V_31 ;
V_26 |= V_23 != V_2 -> V_32 ;
if ( V_26 ) {
V_2 -> V_28 = V_19 ;
V_2 -> V_29 = V_20 ;
V_2 -> V_30 = V_21 ;
V_2 -> V_31 = V_22 ;
V_2 -> V_32 = V_23 ;
}
F_14 (encoder, &dev->mode_config.encoder_list, head) {
struct V_33 * V_33 = F_15 ( V_25 ) ;
V_27 |= V_33 -> V_34 ;
if ( V_26 || F_16 ( V_25 ) )
F_17 ( V_25 ) ;
}
if ( V_27 )
F_10 ( V_2 ) ;
}
static void F_18 ( struct V_1 * V_2 , bool V_35 )
{
T_3 V_9 = 0 ;
F_19 ( L_2 , V_35 ? L_3 : L_4 ) ;
if ( F_20 ( V_2 ) ) {
if ( V_35 ) {
V_9 |= 0x81000000 ;
V_9 |= 0x0e1000f0 ;
}
F_21 ( V_36 , V_9 ) ;
} else {
F_22 ( V_37 ,
V_35 ? 0x81000000 : 0x0 , ~ 0x81000000 ) ;
}
V_2 -> V_38 = V_35 ;
}
int F_23 ( struct V_1 * V_2 )
{
if ( ! V_39 || ! F_1 ( V_2 ) )
return 0 ;
F_18 ( V_2 , true ) ;
V_2 -> V_28 = - 1 ;
V_2 -> V_29 = - 1 ;
V_2 -> V_30 = - 1 ;
V_2 -> V_31 = 0 ;
V_2 -> V_32 = 0 ;
F_24 (
& V_2 -> V_13 ,
F_13 ,
( unsigned long ) V_2 ) ;
return 0 ;
}
void F_25 ( struct V_24 * V_25 )
{
struct V_17 * V_10 = V_25 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_40 ;
struct V_33 * V_33 = F_15 ( V_25 ) ;
F_26 ( L_5 ,
V_33 -> V_34 ) ;
if ( V_33 -> V_34 )
return;
V_33 -> V_34 = 1 ;
if ( V_2 -> V_38 )
F_11 ( & V_2 -> V_13 , V_14 + 1 ) ;
}
void F_27 ( struct V_24 * V_25 )
{
struct V_33 * V_33 = F_15 ( V_25 ) ;
F_26 ( L_6 ,
V_33 -> V_34 ) ;
V_33 -> V_34 = 0 ;
}
void F_28 ( struct V_24 * V_25 , int clock )
{
struct V_17 * V_10 = V_25 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_40 ;
struct V_33 * V_33 = F_15 ( V_25 ) ;
struct V_41 * V_42 = V_33 -> V_43 ;
int V_44 = 48000 ;
switch ( V_33 -> V_45 ) {
case V_46 :
case V_47 :
F_22 ( V_48 , 0 , ~ 0x301 ) ;
break;
case V_49 :
case V_50 :
case V_51 :
case V_52 :
F_22 ( V_48 , 0x100 , ~ 0x301 ) ;
break;
default:
F_6 ( V_2 -> V_10 , L_7 ,
V_33 -> V_45 ) ;
return;
}
if ( F_20 ( V_2 ) ) {
F_21 ( V_53 , V_44 * 10 ) ;
F_21 ( V_54 , clock * 10 ) ;
F_21 ( V_55 , 0x00000071 ) ;
F_22 ( 0x5ac , 0x01 , ~ 0x77 ) ;
} else {
switch ( V_42 -> V_56 ) {
case 0 :
F_21 ( V_57 , V_44 * 50 ) ;
F_21 ( V_58 , clock * 100 ) ;
F_21 ( V_59 , 0 ) ;
break;
case 1 :
F_21 ( V_60 , V_44 * 50 ) ;
F_21 ( V_61 , clock * 100 ) ;
F_21 ( V_59 , 1 ) ;
break;
default:
F_6 ( V_2 -> V_10 ,
L_8 ,
V_33 -> V_45 ) ;
return;
}
}
}
void F_29 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_38 )
return;
F_30 ( & V_2 -> V_13 ) ;
F_18 ( V_2 , false ) ;
}
