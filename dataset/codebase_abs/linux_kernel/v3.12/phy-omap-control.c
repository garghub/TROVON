struct V_1 * F_1 ( void )
{
if ( ! V_2 )
return F_2 ( - V_3 ) ;
return V_2 -> V_4 ;
}
void F_3 ( struct V_1 * V_4 , bool V_5 )
{
T_1 V_6 ;
unsigned long V_7 ;
struct V_8 * V_2 = F_4 ( V_4 ) ;
if ( V_2 -> type != V_9 )
return;
V_7 = F_5 ( V_2 -> V_10 ) ;
V_7 = V_7 / 1000000 ;
V_6 = F_6 ( V_2 -> V_11 ) ;
if ( V_5 ) {
V_6 &= ~ ( V_12 |
V_13 ) ;
V_6 |= V_14 <<
V_15 ;
V_6 |= V_7 << V_16 ;
} else {
V_6 &= ~ V_12 ;
V_6 |= V_17 <<
V_15 ;
}
F_7 ( V_6 , V_2 -> V_11 ) ;
}
void F_8 ( struct V_1 * V_4 , int V_5 )
{
T_1 V_6 ;
struct V_8 * V_2 = F_4 ( V_4 ) ;
V_6 = F_6 ( V_2 -> V_18 ) ;
if ( V_5 )
V_6 &= ~ V_19 ;
else
V_6 |= V_19 ;
F_7 ( V_6 , V_2 -> V_18 ) ;
}
static void F_9 ( struct V_8 * V_20 )
{
T_1 V_6 ;
V_6 = F_6 ( V_20 -> V_21 ) ;
V_6 &= ~ ( V_22 | V_23 ) ;
V_6 |= V_24 | V_25 ;
F_7 ( V_6 , V_20 -> V_21 ) ;
}
static void F_10 ( struct V_8 * V_20 )
{
T_1 V_6 ;
V_6 = F_6 ( V_20 -> V_21 ) ;
V_6 &= ~ V_23 ;
V_6 |= V_22 | V_24 |
V_25 ;
F_7 ( V_6 , V_20 -> V_21 ) ;
}
static void F_11 ( struct V_8 * V_20 )
{
T_1 V_6 ;
V_6 = F_6 ( V_20 -> V_21 ) ;
V_6 &= ~ ( V_24 | V_25 ) ;
V_6 |= V_22 | V_23 ;
F_7 ( V_6 , V_20 -> V_21 ) ;
}
void F_12 ( struct V_1 * V_4 ,
enum V_26 V_27 )
{
struct V_8 * V_20 ;
if ( F_13 ( V_4 ) || V_2 -> type != V_28 )
return;
V_20 = F_4 ( V_4 ) ;
switch ( V_27 ) {
case V_29 :
F_9 ( V_20 ) ;
break;
case V_30 :
F_10 ( V_20 ) ;
break;
case V_31 :
F_11 ( V_20 ) ;
break;
default:
F_14 ( V_4 , L_1 ) ;
}
}
static int F_15 ( struct V_32 * V_33 )
{
struct V_34 * V_35 ;
struct V_36 * V_37 = V_33 -> V_4 . V_38 ;
struct V_39 * V_40 =
F_16 ( & V_33 -> V_4 ) ;
V_2 = F_17 ( & V_33 -> V_4 , sizeof( * V_2 ) ,
V_41 ) ;
if ( ! V_2 ) {
F_18 ( & V_33 -> V_4 , L_2 ) ;
return - V_42 ;
}
if ( V_37 ) {
F_19 ( V_37 , L_3 , & V_2 -> type ) ;
} else if ( V_40 ) {
V_2 -> type = V_40 -> type ;
} else {
F_18 ( & V_33 -> V_4 , L_4 ) ;
return - V_43 ;
}
V_2 -> V_4 = & V_33 -> V_4 ;
V_35 = F_20 ( V_33 , V_44 ,
L_5 ) ;
V_2 -> V_18 = F_21 ( & V_33 -> V_4 , V_35 ) ;
if ( F_13 ( V_2 -> V_18 ) )
return F_22 ( V_2 -> V_18 ) ;
if ( V_2 -> type == V_28 ) {
V_35 = F_20 ( V_33 , V_44 ,
L_6 ) ;
V_2 -> V_21 = F_21 (
& V_33 -> V_4 , V_35 ) ;
if ( F_13 ( V_2 -> V_21 ) )
return F_22 ( V_2 -> V_21 ) ;
}
if ( V_2 -> type == V_9 ) {
V_35 = F_20 ( V_33 , V_44 ,
L_7 ) ;
V_2 -> V_11 = F_21 (
& V_33 -> V_4 , V_35 ) ;
if ( F_13 ( V_2 -> V_11 ) )
return F_22 ( V_2 -> V_11 ) ;
V_2 -> V_10 = F_23 ( V_2 -> V_4 ,
L_8 ) ;
if ( F_13 ( V_2 -> V_10 ) ) {
F_24 ( L_9 , V_45 ) ;
return - V_43 ;
}
}
F_25 ( V_2 -> V_4 , V_2 ) ;
return 0 ;
}
static int T_2 F_26 ( void )
{
return F_27 ( & V_46 ) ;
}
static void T_3 F_28 ( void )
{
F_29 ( & V_46 ) ;
}
