static int F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 >= V_4 && V_2 -> V_3 < V_5 )
|| V_2 -> V_3 == V_6
|| V_2 -> V_3 == V_7
|| V_2 -> V_3 == V_8 ;
}
int F_2 ( struct V_1 * V_2 )
{
return ( F_3 ( V_9 ) & 0x7 ) + 1 ;
}
int F_4 ( struct V_1 * V_2 )
{
T_1 V_10 = ( F_3 ( V_9 ) & 0xF0 ) >> 4 ;
switch ( V_10 ) {
case 0x0 : return 8 ;
case 0x1 : return 16 ;
case 0x2 : return 20 ;
case 0x3 : return 24 ;
case 0x4 : return 32 ;
}
F_5 ( V_2 -> V_11 , L_1 ,
( int ) V_10 ) ;
return 16 ;
}
int F_6 ( struct V_1 * V_2 )
{
T_1 V_10 = F_3 ( V_9 ) ;
T_1 V_12 ;
if ( V_10 & 0x4000 )
V_12 = 44100 ;
else
V_12 = 48000 ;
V_12 *= ( ( V_10 >> 11 ) & 0x7 ) + 1 ;
V_12 /= ( ( V_10 >> 8 ) & 0x7 ) + 1 ;
return V_12 ;
}
T_2 F_7 ( struct V_1 * V_2 )
{
return F_3 ( V_13 ) & 0xff ;
}
T_2 F_8 ( struct V_1 * V_2 )
{
return ( F_3 ( V_13 ) >> 8 ) & 0xff ;
}
void F_9 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_14 ,
V_15 + F_11 ( V_16 ) ) ;
}
static void F_12 ( unsigned long V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 ;
struct V_18 * V_11 = V_2 -> V_19 ;
int V_20 = F_2 ( V_2 ) ;
int V_21 = F_6 ( V_2 ) ;
int V_22 = F_4 ( V_2 ) ;
T_2 V_23 = F_7 ( V_2 ) ;
T_2 V_24 = F_8 ( V_2 ) ;
struct V_25 * V_26 ;
int V_27 = 0 , V_28 = 0 ;
V_27 |= V_20 != V_2 -> V_29 ;
V_27 |= V_21 != V_2 -> V_30 ;
V_27 |= V_22 != V_2 -> V_31 ;
V_27 |= V_23 != V_2 -> V_32 ;
V_27 |= V_24 != V_2 -> V_33 ;
if ( V_27 ) {
V_2 -> V_29 = V_20 ;
V_2 -> V_30 = V_21 ;
V_2 -> V_31 = V_22 ;
V_2 -> V_32 = V_23 ;
V_2 -> V_33 = V_24 ;
}
F_13 (encoder, &dev->mode_config.encoder_list, head) {
struct V_34 * V_34 = F_14 ( V_26 ) ;
V_28 |= V_34 -> V_35 ;
if ( V_27 || F_15 ( V_26 ) )
F_16 ( V_26 ) ;
}
if ( V_28 )
F_9 ( V_2 ) ;
}
static void F_17 ( struct V_1 * V_2 , bool V_36 )
{
F_18 ( L_2 , V_36 ? L_3 : L_4 ) ;
F_19 ( V_37 , V_36 ? 0x81000000 : 0x0 , ~ 0x81000000 ) ;
V_2 -> V_38 = V_36 ;
}
int F_20 ( struct V_1 * V_2 )
{
if ( ! V_39 || ! F_1 ( V_2 ) )
return 0 ;
F_17 ( V_2 , true ) ;
V_2 -> V_29 = - 1 ;
V_2 -> V_30 = - 1 ;
V_2 -> V_31 = - 1 ;
V_2 -> V_32 = 0 ;
V_2 -> V_33 = 0 ;
F_21 (
& V_2 -> V_14 ,
F_12 ,
( unsigned long ) V_2 ) ;
return 0 ;
}
void F_22 ( struct V_25 * V_26 )
{
struct V_18 * V_11 = V_26 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_40 ;
struct V_34 * V_34 = F_14 ( V_26 ) ;
F_23 ( L_5 ,
V_34 -> V_35 ) ;
if ( V_34 -> V_35 )
return;
V_34 -> V_35 = 1 ;
if ( V_2 -> V_38 )
F_10 ( & V_2 -> V_14 , V_15 + 1 ) ;
}
void F_24 ( struct V_25 * V_26 )
{
struct V_34 * V_34 = F_14 ( V_26 ) ;
F_23 ( L_6 ,
V_34 -> V_35 ) ;
V_34 -> V_35 = 0 ;
}
void F_25 ( struct V_25 * V_26 , int clock )
{
struct V_18 * V_11 = V_26 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_40 ;
struct V_34 * V_34 = F_14 ( V_26 ) ;
struct V_41 * V_42 = V_34 -> V_43 ;
int V_44 = 48000 ;
switch ( V_34 -> V_45 ) {
case V_46 :
case V_47 :
F_19 ( V_48 , 0 , ~ 0x301 ) ;
break;
case V_49 :
case V_50 :
case V_51 :
case V_52 :
F_19 ( V_48 , 0x100 , ~ 0x301 ) ;
break;
default:
F_5 ( V_2 -> V_11 , L_7 ,
V_34 -> V_45 ) ;
return;
}
switch ( V_42 -> V_53 ) {
case 0 :
F_26 ( V_54 , V_44 * 50 ) ;
F_26 ( V_55 , clock * 100 ) ;
F_26 ( V_56 , 0 ) ;
break;
case 1 :
F_26 ( V_57 , V_44 * 50 ) ;
F_26 ( V_58 , clock * 100 ) ;
F_26 ( V_56 , 1 ) ;
break;
default:
F_5 ( V_2 -> V_11 , L_8 ,
V_34 -> V_45 ) ;
return;
}
}
void F_27 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_38 )
return;
F_28 ( & V_2 -> V_14 ) ;
F_17 ( V_2 , false ) ;
}
