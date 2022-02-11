static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
F_4 ( F_5 ( F_6 ( V_2 ) ) , V_6 -> V_7 + V_8 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
T_1 V_9 ;
V_9 = F_8 ( V_6 -> V_7 + V_10 ) ;
V_9 &= ~ F_5 ( F_6 ( V_2 ) ) ;
F_4 ( V_9 , V_6 -> V_7 + V_10 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
T_1 V_9 ;
V_9 = F_8 ( V_6 -> V_7 + V_10 ) ;
V_9 |= F_5 ( F_6 ( V_2 ) ) ;
F_4 ( V_9 , V_6 -> V_7 + V_10 ) ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int type )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
T_1 V_11 = F_5 ( F_6 ( V_2 ) ) ;
T_1 V_12 , V_13 , V_14 ;
V_14 = F_8 ( V_6 -> V_7 + V_15 ) ;
V_13 = F_8 ( V_6 -> V_7 + V_16 ) ;
V_12 = F_8 ( V_6 -> V_7 + V_17 ) ;
switch ( type ) {
case V_18 :
F_11 ( V_2 , V_19 ) ;
V_14 &= ~ V_11 ;
V_12 |= V_11 ;
break;
case V_20 :
F_11 ( V_2 , V_19 ) ;
V_14 &= ~ V_11 ;
V_12 &= ~ V_11 ;
V_13 &= ~ V_11 ;
break;
case V_21 :
F_11 ( V_2 , V_19 ) ;
V_14 &= ~ V_11 ;
V_12 &= ~ V_11 ;
V_13 |= V_11 ;
break;
case V_22 :
F_11 ( V_2 , V_23 ) ;
V_14 |= V_11 ;
V_13 &= ~ V_11 ;
break;
case V_24 :
F_11 ( V_2 , V_23 ) ;
V_14 |= V_11 ;
V_13 |= V_11 ;
break;
default:
F_11 ( V_2 , V_25 ) ;
return - V_26 ;
}
F_4 ( V_14 , V_6 -> V_7 + V_15 ) ;
F_4 ( V_13 , V_6 -> V_7 + V_16 ) ;
F_4 ( V_12 , V_6 -> V_7 + V_17 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static void F_12 ( struct V_27 * V_28 )
{
struct V_3 * V_4 = F_13 ( V_28 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_29 * V_30 = F_14 ( V_28 ) ;
int V_31 ;
unsigned long V_32 ;
F_15 ( V_30 , V_28 ) ;
V_32 = F_8 ( V_6 -> V_7 + V_33 ) ;
if ( V_32 )
F_16 (offset, &stat, gc->ngpio)
F_17 ( F_18 ( V_4 -> V_34 ,
V_31 ) ) ;
F_19 ( V_30 , V_28 ) ;
}
static int F_20 ( struct V_35 * V_36 )
{
struct V_37 * V_38 = & V_36 -> V_38 ;
struct V_39 * V_40 ;
struct V_5 * V_6 ;
int V_41 ;
int V_42 ;
V_6 = F_21 ( V_38 , sizeof( * V_6 ) , V_43 ) ;
if ( ! V_6 )
return - V_44 ;
V_6 -> V_38 = V_38 ;
V_40 = F_22 ( V_36 , V_45 , 0 ) ;
V_6 -> V_7 = F_23 ( V_38 , V_40 ) ;
if ( F_24 ( V_6 -> V_7 ) )
return F_25 ( V_6 -> V_7 ) ;
V_41 = F_26 ( V_36 , 0 ) ;
if ( ! V_41 )
return - V_26 ;
V_42 = F_27 ( & V_6 -> V_4 , V_38 , 4 ,
V_6 -> V_7 + V_46 ,
V_6 -> V_7 + V_47 ,
V_6 -> V_7 + V_48 ,
V_6 -> V_7 + V_49 ,
NULL ,
0 ) ;
if ( V_42 ) {
F_28 ( V_38 , L_1 ) ;
return V_42 ;
}
V_6 -> V_4 . V_50 = L_2 ;
V_6 -> V_4 . V_7 = - 1 ;
V_6 -> V_4 . V_51 = V_38 ;
V_6 -> V_4 . V_52 = V_53 ;
V_42 = F_29 ( V_38 , & V_6 -> V_4 , V_6 ) ;
if ( V_42 )
return V_42 ;
F_4 ( 0x0 , V_6 -> V_7 + V_10 ) ;
F_4 ( 0x0 , V_6 -> V_7 + V_54 ) ;
F_4 ( ~ 0x0 , V_6 -> V_7 + V_8 ) ;
V_42 = F_30 ( & V_6 -> V_4 , & V_55 ,
0 , V_25 ,
V_56 ) ;
if ( V_42 ) {
F_31 ( V_38 , L_3 ) ;
return V_42 ;
}
F_32 ( & V_6 -> V_4 , & V_55 ,
V_41 , F_12 ) ;
F_31 ( V_38 , L_4 , V_6 -> V_7 ) ;
return 0 ;
}
