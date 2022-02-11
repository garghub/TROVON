void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
T_2 V_5 ;
struct V_6 * V_7 ;
if ( F_2 ( V_2 ) || ! V_2 ) {
F_3 ( L_1 , V_8 ) ;
return;
}
V_7 = F_4 ( V_2 ) ;
if ( ! V_7 ) {
F_5 ( V_2 , L_2 , V_8 ) ;
return;
}
if ( V_7 -> type != V_9 ) {
F_5 ( V_2 , L_3 , V_8 ) ;
return;
}
V_5 = F_6 ( V_7 -> V_10 ) ;
V_5 &= ~ ( V_11 <<
( V_3 * V_12 ) ) ;
V_5 |= V_4 << ( V_3 * V_12 ) ;
F_7 ( V_5 , V_7 -> V_10 ) ;
}
void F_8 ( struct V_1 * V_2 , int V_13 )
{
T_2 V_5 ;
unsigned long V_14 ;
struct V_6 * V_7 ;
if ( F_2 ( V_2 ) || ! V_2 ) {
F_3 ( L_1 , V_8 ) ;
return;
}
V_7 = F_4 ( V_2 ) ;
if ( ! V_7 ) {
F_5 ( V_2 , L_2 , V_8 ) ;
return;
}
if ( V_7 -> type == V_15 )
return;
V_5 = F_6 ( V_7 -> V_16 ) ;
switch ( V_7 -> type ) {
case V_17 :
if ( V_13 )
V_5 &= ~ V_18 ;
else
V_5 |= V_18 ;
break;
case V_9 :
case V_19 :
V_14 = F_9 ( V_7 -> V_20 ) ;
V_14 = V_14 / 1000000 ;
if ( V_13 ) {
V_5 &= ~ ( V_21 |
V_22 ) ;
V_5 |= V_23 <<
V_24 ;
V_5 |= V_14 <<
V_25 ;
} else {
V_5 &= ~ V_21 ;
V_5 |= V_26 <<
V_24 ;
}
break;
case V_27 :
if ( V_13 )
V_5 &= ~ V_28 ;
else
V_5 |= V_28 ;
break;
case V_29 :
if ( V_13 ) {
V_5 &= ~ ( V_30 |
V_31 ) ;
V_5 |= ( V_32 |
V_33 ) ;
} else {
V_5 &= ~ ( V_32 |
V_33 ) ;
V_5 |= ( V_30 |
V_31 ) ;
}
break;
default:
F_5 ( V_2 , L_4 ,
V_8 , V_7 -> type ) ;
break;
}
F_7 ( V_5 , V_7 -> V_16 ) ;
}
static void F_10 ( struct V_6 * V_34 )
{
T_2 V_5 ;
V_5 = F_6 ( V_34 -> V_35 ) ;
V_5 &= ~ ( V_36 | V_37 ) ;
V_5 |= V_38 | V_39 ;
F_7 ( V_5 , V_34 -> V_35 ) ;
}
static void F_11 ( struct V_6 * V_34 )
{
T_2 V_5 ;
V_5 = F_6 ( V_34 -> V_35 ) ;
V_5 &= ~ V_37 ;
V_5 |= V_36 | V_38 |
V_39 ;
F_7 ( V_5 , V_34 -> V_35 ) ;
}
static void F_12 ( struct V_6 * V_34 )
{
T_2 V_5 ;
V_5 = F_6 ( V_34 -> V_35 ) ;
V_5 &= ~ ( V_38 | V_39 ) ;
V_5 |= V_36 | V_37 ;
F_7 ( V_5 , V_34 -> V_35 ) ;
}
void F_13 ( struct V_1 * V_2 ,
enum V_40 V_41 )
{
struct V_6 * V_34 ;
if ( F_2 ( V_2 ) || ! V_2 )
return;
V_34 = F_4 ( V_2 ) ;
if ( ! V_34 ) {
F_5 ( V_2 , L_5 ) ;
return;
}
if ( V_34 -> type != V_15 )
return;
switch ( V_41 ) {
case V_42 :
F_10 ( V_34 ) ;
break;
case V_43 :
F_11 ( V_34 ) ;
break;
case V_44 :
F_12 ( V_34 ) ;
break;
default:
F_14 ( V_2 , L_6 ) ;
}
}
static int F_15 ( struct V_45 * V_46 )
{
struct V_47 * V_48 ;
const struct V_49 * V_50 ;
struct V_6 * V_7 ;
V_50 = F_16 ( F_17 ( V_51 ) ,
& V_46 -> V_2 ) ;
if ( ! V_50 )
return - V_52 ;
V_7 = F_18 ( & V_46 -> V_2 , sizeof( * V_7 ) ,
V_53 ) ;
if ( ! V_7 ) {
F_5 ( & V_46 -> V_2 , L_7 ) ;
return - V_54 ;
}
V_7 -> V_2 = & V_46 -> V_2 ;
V_7 -> type = * (enum V_55 * ) V_50 -> V_56 ;
if ( V_7 -> type == V_15 ) {
V_48 = F_19 ( V_46 , V_57 ,
L_8 ) ;
V_7 -> V_35 = F_20 (
& V_46 -> V_2 , V_48 ) ;
if ( F_2 ( V_7 -> V_35 ) )
return F_21 ( V_7 -> V_35 ) ;
} else {
V_48 = F_19 ( V_46 , V_57 ,
L_9 ) ;
V_7 -> V_16 = F_20 ( & V_46 -> V_2 , V_48 ) ;
if ( F_2 ( V_7 -> V_16 ) ) {
F_5 ( & V_46 -> V_2 , L_10 ) ;
return F_21 ( V_7 -> V_16 ) ;
}
}
if ( V_7 -> type == V_19 ||
V_7 -> type == V_9 ) {
V_7 -> V_20 = F_22 ( V_7 -> V_2 ,
L_11 ) ;
if ( F_2 ( V_7 -> V_20 ) ) {
F_3 ( L_12 , V_8 ) ;
return - V_52 ;
}
}
if ( V_7 -> type == V_9 ) {
V_48 = F_19 ( V_46 , V_57 ,
L_13 ) ;
V_7 -> V_10 = F_20 ( & V_46 -> V_2 , V_48 ) ;
if ( F_2 ( V_7 -> V_10 ) )
return F_21 ( V_7 -> V_10 ) ;
}
F_23 ( V_7 -> V_2 , V_7 ) ;
return 0 ;
}
static int T_3 F_24 ( void )
{
return F_25 ( & V_58 ) ;
}
static void T_4 F_26 ( void )
{
F_27 ( & V_58 ) ;
}
