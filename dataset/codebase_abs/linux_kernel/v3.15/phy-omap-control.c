void F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
unsigned long V_5 ;
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
if ( V_7 -> type == V_9 )
return;
V_4 = F_6 ( V_7 -> V_10 ) ;
switch ( V_7 -> type ) {
case V_11 :
if ( V_3 )
V_4 &= ~ V_12 ;
else
V_4 |= V_12 ;
break;
case V_13 :
V_5 = F_7 ( V_7 -> V_14 ) ;
V_5 = V_5 / 1000000 ;
if ( V_3 ) {
V_4 &= ~ ( V_15 |
V_16 ) ;
V_4 |= V_17 <<
V_18 ;
V_4 |= V_5 <<
V_19 ;
} else {
V_4 &= ~ V_15 ;
V_4 |= V_20 <<
V_18 ;
}
break;
case V_21 :
if ( V_3 )
V_4 &= ~ V_22 ;
else
V_4 |= V_22 ;
break;
case V_23 :
if ( V_3 ) {
V_4 &= ~ ( V_24 |
V_25 ) ;
V_4 |= ( V_26 |
V_27 ) ;
} else {
V_4 &= ~ ( V_26 |
V_27 ) ;
V_4 |= ( V_24 |
V_25 ) ;
}
break;
default:
F_5 ( V_2 , L_3 ,
V_8 , V_7 -> type ) ;
break;
}
F_8 ( V_4 , V_7 -> V_10 ) ;
}
static void F_9 ( struct V_6 * V_28 )
{
T_1 V_4 ;
V_4 = F_6 ( V_28 -> V_29 ) ;
V_4 &= ~ ( V_30 | V_31 ) ;
V_4 |= V_32 | V_33 ;
F_8 ( V_4 , V_28 -> V_29 ) ;
}
static void F_10 ( struct V_6 * V_28 )
{
T_1 V_4 ;
V_4 = F_6 ( V_28 -> V_29 ) ;
V_4 &= ~ V_31 ;
V_4 |= V_30 | V_32 |
V_33 ;
F_8 ( V_4 , V_28 -> V_29 ) ;
}
static void F_11 ( struct V_6 * V_28 )
{
T_1 V_4 ;
V_4 = F_6 ( V_28 -> V_29 ) ;
V_4 &= ~ ( V_32 | V_33 ) ;
V_4 |= V_30 | V_31 ;
F_8 ( V_4 , V_28 -> V_29 ) ;
}
void F_12 ( struct V_1 * V_2 ,
enum V_34 V_35 )
{
struct V_6 * V_28 ;
if ( F_2 ( V_2 ) || ! V_2 )
return;
V_28 = F_4 ( V_2 ) ;
if ( ! V_28 ) {
F_5 ( V_2 , L_4 ) ;
return;
}
if ( V_28 -> type != V_9 )
return;
switch ( V_35 ) {
case V_36 :
F_9 ( V_28 ) ;
break;
case V_37 :
F_10 ( V_28 ) ;
break;
case V_38 :
F_11 ( V_28 ) ;
break;
default:
F_13 ( V_2 , L_5 ) ;
}
}
static int F_14 ( struct V_39 * V_40 )
{
struct V_41 * V_42 ;
const struct V_43 * V_44 ;
struct V_6 * V_7 ;
V_44 = F_15 ( F_16 ( V_45 ) ,
& V_40 -> V_2 ) ;
if ( ! V_44 )
return - V_46 ;
V_7 = F_17 ( & V_40 -> V_2 , sizeof( * V_7 ) ,
V_47 ) ;
if ( ! V_7 ) {
F_5 ( & V_40 -> V_2 , L_6 ) ;
return - V_48 ;
}
V_7 -> V_2 = & V_40 -> V_2 ;
V_7 -> type = * (enum V_49 * ) V_44 -> V_50 ;
if ( V_7 -> type == V_9 ) {
V_42 = F_18 ( V_40 , V_51 ,
L_7 ) ;
V_7 -> V_29 = F_19 (
& V_40 -> V_2 , V_42 ) ;
if ( F_2 ( V_7 -> V_29 ) )
return F_20 ( V_7 -> V_29 ) ;
} else {
V_42 = F_18 ( V_40 , V_51 ,
L_8 ) ;
V_7 -> V_10 = F_19 ( & V_40 -> V_2 , V_42 ) ;
if ( F_2 ( V_7 -> V_10 ) ) {
F_5 ( & V_40 -> V_2 , L_9 ) ;
return F_20 ( V_7 -> V_10 ) ;
}
}
if ( V_7 -> type == V_13 ) {
V_7 -> V_14 = F_21 ( V_7 -> V_2 ,
L_10 ) ;
if ( F_2 ( V_7 -> V_14 ) ) {
F_3 ( L_11 , V_8 ) ;
return - V_46 ;
}
}
F_22 ( V_7 -> V_2 , V_7 ) ;
return 0 ;
}
static int T_2 F_23 ( void )
{
return F_24 ( & V_52 ) ;
}
static void T_3 F_25 ( void )
{
F_26 ( & V_52 ) ;
}
