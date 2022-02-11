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
V_7 = F_4 ( V_6 -> V_11 + V_8 ) ;
if ( V_4 ) {
V_7 &= ~ ( V_12 | V_13 ) ;
V_7 |= V_14 | V_15 ;
} else {
V_7 |= V_12 | V_13 ;
}
F_5 ( V_7 , V_6 -> V_11 + V_8 ) ;
}
static int F_6 ( struct V_16 * V_17 , void * V_18 )
{
struct V_19 * V_20 = (struct V_19 * ) V_18 ;
return V_17 -> V_21 == V_20 &&
V_17 -> V_22 == & V_23 . V_22 ;
}
struct V_1 * F_7 ( struct V_16 * V_17 )
{
struct V_19 * V_20 ;
struct V_5 * V_24 ;
V_20 = F_8 ( V_17 -> V_21 , L_1 , 0 ) ;
if ( ! V_20 )
return NULL ;
V_17 = F_9 ( & V_25 , NULL , V_20 , F_6 ) ;
V_24 = F_10 ( V_17 ) ;
if ( ! V_24 )
return NULL ;
return & V_24 -> V_2 ;
}
static int F_11 ( struct V_26 * V_27 )
{
struct V_28 * V_29 ;
struct V_5 * V_24 ;
const struct V_30 * V_31 ;
const struct V_1 * V_2 ;
V_31 = F_12 ( V_32 , V_27 -> V_17 . V_21 ) ;
if ( ! V_31 )
return - V_33 ;
V_2 = V_31 -> V_18 ;
V_24 = F_13 ( & V_27 -> V_17 , sizeof( * V_24 ) , V_34 ) ;
if ( ! V_24 ) {
F_14 ( & V_27 -> V_17 , L_2 ) ;
return - V_35 ;
}
V_24 -> V_17 = & V_27 -> V_17 ;
V_29 = F_15 ( V_27 , V_36 , L_3 ) ;
V_24 -> V_11 = F_16 ( & V_27 -> V_17 , V_29 ) ;
if ( F_17 ( V_24 -> V_11 ) )
return F_18 ( V_24 -> V_11 ) ;
F_19 ( & V_24 -> V_37 ) ;
V_24 -> V_2 = * V_2 ;
F_20 ( V_24 -> V_17 , V_24 ) ;
return 0 ;
}
