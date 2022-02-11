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
static void F_8 ( struct V_1 * V_2 , T_1 V_3 ,
enum V_13 V_14 , bool V_4 )
{
struct V_5 * V_6 ;
T_1 V_7 ;
T_1 V_8 ;
V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
switch ( V_3 ) {
case 0 :
V_8 = V_15 ;
break;
case 1 :
V_8 = V_16 ;
break;
default:
F_3 ( 1 ) ;
return;
}
V_7 = F_5 ( V_6 -> V_17 + V_8 ) ;
if ( V_4 ) {
if ( V_14 == V_18 ) {
V_7 &= ~ ( V_19 | V_20 |
V_21 ) ;
V_7 |= V_22 ;
} else {
V_7 &= ~ ( V_19 | V_20 ) ;
V_7 |= V_21 | V_22 ;
}
} else {
V_7 |= V_19 | V_20 ;
}
F_6 ( V_7 , V_6 -> V_17 + V_8 ) ;
if ( V_4 )
F_9 ( 1 ) ;
}
static int F_10 ( struct V_23 * V_24 , void * V_25 )
{
struct V_26 * V_27 = (struct V_26 * ) V_25 ;
return V_24 -> V_28 == V_27 &&
V_24 -> V_29 == & V_30 . V_29 ;
}
struct V_1 * F_11 ( struct V_23 * V_24 )
{
struct V_26 * V_27 ;
struct V_5 * V_31 ;
V_27 = F_12 ( V_24 -> V_28 , L_1 , 0 ) ;
if ( ! V_27 )
return NULL ;
V_24 = F_13 ( & V_32 , NULL , V_27 , F_10 ) ;
if ( ! V_24 )
return NULL ;
V_31 = F_14 ( V_24 ) ;
if ( ! V_31 )
return NULL ;
return & V_31 -> V_2 ;
}
static int F_15 ( struct V_33 * V_34 )
{
struct V_35 * V_36 ;
struct V_5 * V_31 ;
const struct V_37 * V_38 ;
const struct V_1 * V_2 ;
V_38 = F_16 ( V_39 , V_34 -> V_24 . V_28 ) ;
if ( ! V_38 )
return - V_40 ;
V_2 = V_38 -> V_25 ;
V_31 = F_17 ( & V_34 -> V_24 , sizeof( * V_31 ) , V_41 ) ;
if ( ! V_31 )
return - V_42 ;
V_31 -> V_24 = & V_34 -> V_24 ;
V_36 = F_18 ( V_34 , V_43 , L_2 ) ;
V_31 -> V_17 = F_19 ( & V_34 -> V_24 , V_36 ) ;
if ( F_20 ( V_31 -> V_17 ) )
return F_21 ( V_31 -> V_17 ) ;
V_36 = F_18 ( V_34 , V_43 , L_3 ) ;
V_31 -> V_12 = F_19 ( & V_34 -> V_24 , V_36 ) ;
if ( F_20 ( V_31 -> V_12 ) )
return F_21 ( V_31 -> V_12 ) ;
F_22 ( & V_31 -> V_11 ) ;
V_31 -> V_2 = * V_2 ;
F_23 ( V_31 -> V_24 , V_31 ) ;
return 0 ;
}
