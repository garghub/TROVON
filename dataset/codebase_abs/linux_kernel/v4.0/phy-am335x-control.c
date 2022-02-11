static void F_1 ( struct V_1 * V_2 , T_1 V_3 , bool V_4 )
{
struct V_5 * V_6 ;
T_1 V_7 ;
T_1 V_8 ;
V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
switch ( V_3 ) {
case 0 :
V_8 = V_9 ;
break;
case 1 :
V_8 = V_10 ;
break;
default:
F_3 ( 1 ) ;
return;
}
F_4 ( & V_6 -> V_11 ) ;
V_7 = F_5 ( V_6 -> V_12 ) ;
if ( V_4 )
V_7 |= V_8 ;
else
V_7 &= ~ V_8 ;
F_6 ( V_7 , V_6 -> V_12 ) ;
F_7 ( & V_6 -> V_11 ) ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_3 , bool V_4 )
{
struct V_5 * V_6 ;
T_1 V_7 ;
T_1 V_8 ;
V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
switch ( V_3 ) {
case 0 :
V_8 = V_13 ;
break;
case 1 :
V_8 = V_14 ;
break;
default:
F_3 ( 1 ) ;
return;
}
V_7 = F_5 ( V_6 -> V_15 + V_8 ) ;
if ( V_4 ) {
V_7 &= ~ ( V_16 | V_17 ) ;
V_7 |= V_18 | V_19 ;
} else {
V_7 |= V_16 | V_17 ;
}
F_6 ( V_7 , V_6 -> V_15 + V_8 ) ;
if ( V_4 )
F_9 ( 1 ) ;
}
static int F_10 ( struct V_20 * V_21 , void * V_22 )
{
struct V_23 * V_24 = (struct V_23 * ) V_22 ;
return V_21 -> V_25 == V_24 &&
V_21 -> V_26 == & V_27 . V_26 ;
}
struct V_1 * F_11 ( struct V_20 * V_21 )
{
struct V_23 * V_24 ;
struct V_5 * V_28 ;
V_24 = F_12 ( V_21 -> V_25 , L_1 , 0 ) ;
if ( ! V_24 )
return NULL ;
V_21 = F_13 ( & V_29 , NULL , V_24 , F_10 ) ;
if ( ! V_21 )
return NULL ;
V_28 = F_14 ( V_21 ) ;
if ( ! V_28 )
return NULL ;
return & V_28 -> V_2 ;
}
static int F_15 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
struct V_5 * V_28 ;
const struct V_34 * V_35 ;
const struct V_1 * V_2 ;
V_35 = F_16 ( V_36 , V_31 -> V_21 . V_25 ) ;
if ( ! V_35 )
return - V_37 ;
V_2 = V_35 -> V_22 ;
V_28 = F_17 ( & V_31 -> V_21 , sizeof( * V_28 ) , V_38 ) ;
if ( ! V_28 )
return - V_39 ;
V_28 -> V_21 = & V_31 -> V_21 ;
V_33 = F_18 ( V_31 , V_40 , L_2 ) ;
V_28 -> V_15 = F_19 ( & V_31 -> V_21 , V_33 ) ;
if ( F_20 ( V_28 -> V_15 ) )
return F_21 ( V_28 -> V_15 ) ;
V_33 = F_18 ( V_31 , V_40 , L_3 ) ;
V_28 -> V_12 = F_19 ( & V_31 -> V_21 , V_33 ) ;
if ( F_20 ( V_28 -> V_12 ) )
return F_21 ( V_28 -> V_12 ) ;
F_22 ( & V_28 -> V_11 ) ;
V_28 -> V_2 = * V_2 ;
F_23 ( V_28 -> V_21 , V_28 ) ;
return 0 ;
}
