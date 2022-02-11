static void F_1 ( void * V_1 , unsigned int V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
void T_1 * V_5 = V_4 -> V_5 ;
T_2 V_6 ;
if ( ! V_5 )
return;
V_6 = F_2 ( V_5 + V_7 ) ;
V_6 &= ~ V_8 ;
switch ( V_2 ) {
case 1000 :
V_6 |= V_9 ;
break;
case 100 :
V_6 |= V_10 ;
break;
case 10 :
V_6 |= V_11 ;
break;
default:
return;
}
F_3 ( V_6 , V_5 + V_7 ) ;
}
static int F_4 ( struct V_3 * V_4 , struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_16 ;
struct V_17 * V_18 ;
T_2 V_19 , V_20 ;
int V_21 ;
struct V_14 * V_22 ;
struct V_23 V_24 ;
V_4 -> V_25 = F_5 ( V_13 ,
V_26 ) ;
if ( F_6 ( V_4 -> V_25 ) ) {
F_7 ( V_13 , L_1 ) ;
if ( F_8 ( V_4 -> V_25 ) == - V_27 )
return - V_27 ;
V_4 -> V_25 = NULL ;
}
V_4 -> V_28 = F_9 ( V_15 ) ;
V_18 = F_10 ( V_15 , L_2 ) ;
if ( F_6 ( V_18 ) ) {
F_7 ( V_13 , L_3 ) ;
return F_8 ( V_18 ) ;
}
V_21 = F_11 ( V_15 , L_2 , 1 , & V_19 ) ;
if ( V_21 ) {
F_7 ( V_13 , L_4 ) ;
return - V_29 ;
}
V_21 = F_11 ( V_15 , L_2 , 2 , & V_20 ) ;
if ( V_21 ) {
F_7 ( V_13 , L_5 ) ;
return - V_29 ;
}
V_22 = F_12 ( V_15 , L_6 , 0 ) ;
if ( V_22 ) {
if ( F_13 ( V_22 , 0 , & V_24 ) ) {
F_7 ( V_13 , L_7 ) ;
return - V_29 ;
}
V_4 -> V_5 = F_14 ( V_13 , & V_24 ) ;
if ( F_6 ( V_4 -> V_5 ) ) {
F_7 ( V_13 , L_8 ) ;
return F_8 ( V_4 -> V_5 ) ;
}
}
V_4 -> V_19 = V_19 ;
V_4 -> V_20 = V_20 ;
V_4 -> V_18 = V_18 ;
V_4 -> V_13 = V_13 ;
return 0 ;
}
static int F_15 ( struct V_3 * V_4 )
{
struct V_17 * V_18 = V_4 -> V_18 ;
int V_30 = V_4 -> V_28 ;
T_2 V_19 = V_4 -> V_19 ;
T_2 V_20 = V_4 -> V_20 ;
T_2 V_31 , V_6 ;
switch ( V_30 ) {
case V_32 :
case V_33 :
V_6 = V_34 ;
break;
case V_35 :
case V_36 :
V_6 = V_37 ;
break;
default:
F_16 ( V_4 -> V_13 , L_9 , V_30 ) ;
return - V_29 ;
}
if ( V_4 -> V_5 )
V_6 = V_37 ;
F_17 ( V_18 , V_19 , & V_31 ) ;
V_31 &= ~ ( V_38 << V_20 ) ;
V_31 |= V_6 << V_20 ;
F_18 ( V_18 , V_19 , V_31 ) ;
return 0 ;
}
static void * F_19 ( struct V_39 * V_40 )
{
struct V_12 * V_13 = & V_40 -> V_13 ;
int V_21 ;
struct V_3 * V_4 ;
V_4 = F_20 ( V_13 , sizeof( * V_4 ) , V_41 ) ;
if ( ! V_4 )
return F_21 ( - V_42 ) ;
V_21 = F_4 ( V_4 , V_13 ) ;
if ( V_21 ) {
F_16 ( V_13 , L_10 ) ;
return F_21 ( V_21 ) ;
}
V_21 = F_15 ( V_4 ) ;
if ( V_21 ) {
F_16 ( V_13 , L_11 , V_21 ) ;
return F_21 ( V_21 ) ;
}
return V_4 ;
}
static void F_22 ( struct V_39 * V_40 , void * V_1 )
{
struct V_3 * V_4 = V_1 ;
if ( V_4 -> V_25 )
F_23 ( V_4 -> V_25 ) ;
}
static int F_24 ( struct V_39 * V_40 , void * V_1 )
{
struct V_3 * V_4 = V_1 ;
struct V_43 * V_44 = F_25 ( V_40 ) ;
struct V_45 * V_46 = NULL ;
int V_21 = 0 ;
if ( V_44 )
V_46 = F_26 ( V_44 ) ;
if ( V_4 -> V_25 )
F_23 ( V_4 -> V_25 ) ;
V_21 = F_15 ( V_4 ) ;
if ( V_4 -> V_25 )
F_27 ( V_4 -> V_25 ) ;
if ( V_46 && V_46 -> V_47 )
F_28 ( V_46 -> V_47 ) ;
return V_21 ;
}
