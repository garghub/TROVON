void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_4 ;
struct V_5 * V_6 ;
if ( F_2 ( V_2 ) || ! V_2 ) {
F_3 ( L_1 , V_7 ) ;
return;
}
V_6 = F_4 ( V_2 ) ;
if ( ! V_6 ) {
F_5 ( V_2 , L_2 , V_7 ) ;
return;
}
if ( V_6 -> type != V_8 ) {
F_5 ( V_2 , L_3 , V_7 ) ;
return;
}
V_4 = F_6 ( V_6 -> V_9 ) ;
V_4 &= ~ ( V_10 <<
V_11 ) ;
V_4 |= ( V_3 << V_11 ) ;
F_7 ( V_4 , V_6 -> V_9 ) ;
}
void F_8 ( struct V_1 * V_2 , int V_12 )
{
T_2 V_4 ;
unsigned long V_13 ;
struct V_5 * V_6 ;
if ( F_2 ( V_2 ) || ! V_2 ) {
F_3 ( L_1 , V_7 ) ;
return;
}
V_6 = F_4 ( V_2 ) ;
if ( ! V_6 ) {
F_5 ( V_2 , L_2 , V_7 ) ;
return;
}
if ( V_6 -> type == V_14 )
return;
V_4 = F_6 ( V_6 -> V_15 ) ;
switch ( V_6 -> type ) {
case V_16 :
if ( V_12 )
V_4 &= ~ V_17 ;
else
V_4 |= V_17 ;
break;
case V_8 :
case V_18 :
V_13 = F_9 ( V_6 -> V_19 ) ;
V_13 = V_13 / 1000000 ;
if ( V_12 ) {
V_4 &= ~ ( V_20 |
V_21 ) ;
V_4 |= V_22 <<
V_23 ;
V_4 |= V_13 <<
V_24 ;
} else {
V_4 &= ~ V_20 ;
V_4 |= V_25 <<
V_23 ;
}
break;
case V_26 :
if ( V_12 )
V_4 &= ~ V_27 ;
else
V_4 |= V_27 ;
break;
case V_28 :
if ( V_12 ) {
V_4 &= ~ ( V_29 |
V_30 ) ;
V_4 |= ( V_31 |
V_32 ) ;
} else {
V_4 &= ~ ( V_31 |
V_32 ) ;
V_4 |= ( V_29 |
V_30 ) ;
}
break;
default:
F_5 ( V_2 , L_4 ,
V_7 , V_6 -> type ) ;
break;
}
F_7 ( V_4 , V_6 -> V_15 ) ;
}
static void F_10 ( struct V_5 * V_33 )
{
T_2 V_4 ;
V_4 = F_6 ( V_33 -> V_34 ) ;
V_4 &= ~ ( V_35 | V_36 ) ;
V_4 |= V_37 | V_38 ;
F_7 ( V_4 , V_33 -> V_34 ) ;
}
static void F_11 ( struct V_5 * V_33 )
{
T_2 V_4 ;
V_4 = F_6 ( V_33 -> V_34 ) ;
V_4 &= ~ V_36 ;
V_4 |= V_35 | V_37 |
V_38 ;
F_7 ( V_4 , V_33 -> V_34 ) ;
}
static void F_12 ( struct V_5 * V_33 )
{
T_2 V_4 ;
V_4 = F_6 ( V_33 -> V_34 ) ;
V_4 &= ~ ( V_37 | V_38 ) ;
V_4 |= V_35 | V_36 ;
F_7 ( V_4 , V_33 -> V_34 ) ;
}
void F_13 ( struct V_1 * V_2 ,
enum V_39 V_40 )
{
struct V_5 * V_33 ;
if ( F_2 ( V_2 ) || ! V_2 )
return;
V_33 = F_4 ( V_2 ) ;
if ( ! V_33 ) {
F_5 ( V_2 , L_5 ) ;
return;
}
if ( V_33 -> type != V_14 )
return;
switch ( V_40 ) {
case V_41 :
F_10 ( V_33 ) ;
break;
case V_42 :
F_11 ( V_33 ) ;
break;
case V_43 :
F_12 ( V_33 ) ;
break;
default:
F_14 ( V_2 , L_6 ) ;
}
}
static int F_15 ( struct V_44 * V_45 )
{
struct V_46 * V_47 ;
const struct V_48 * V_49 ;
struct V_5 * V_6 ;
V_49 = F_16 ( V_50 , & V_45 -> V_2 ) ;
if ( ! V_49 )
return - V_51 ;
V_6 = F_17 ( & V_45 -> V_2 , sizeof( * V_6 ) ,
V_52 ) ;
if ( ! V_6 )
return - V_53 ;
V_6 -> V_2 = & V_45 -> V_2 ;
V_6 -> type = * (enum V_54 * ) V_49 -> V_55 ;
if ( V_6 -> type == V_14 ) {
V_47 = F_18 ( V_45 , V_56 ,
L_7 ) ;
V_6 -> V_34 = F_19 (
& V_45 -> V_2 , V_47 ) ;
if ( F_2 ( V_6 -> V_34 ) )
return F_20 ( V_6 -> V_34 ) ;
} else {
V_47 = F_18 ( V_45 , V_56 ,
L_8 ) ;
V_6 -> V_15 = F_19 ( & V_45 -> V_2 , V_47 ) ;
if ( F_2 ( V_6 -> V_15 ) ) {
F_5 ( & V_45 -> V_2 , L_9 ) ;
return F_20 ( V_6 -> V_15 ) ;
}
}
if ( V_6 -> type == V_18 ||
V_6 -> type == V_8 ) {
V_6 -> V_19 = F_21 ( V_6 -> V_2 ,
L_10 ) ;
if ( F_2 ( V_6 -> V_19 ) ) {
F_3 ( L_11 , V_7 ) ;
return - V_51 ;
}
}
if ( V_6 -> type == V_8 ) {
V_47 = F_18 ( V_45 , V_56 ,
L_12 ) ;
V_6 -> V_9 = F_19 ( & V_45 -> V_2 , V_47 ) ;
if ( F_2 ( V_6 -> V_9 ) )
return F_20 ( V_6 -> V_9 ) ;
}
F_22 ( V_6 -> V_2 , V_6 ) ;
return 0 ;
}
static int T_3 F_23 ( void )
{
return F_24 ( & V_57 ) ;
}
static void T_4 F_25 ( void )
{
F_26 ( & V_57 ) ;
}
