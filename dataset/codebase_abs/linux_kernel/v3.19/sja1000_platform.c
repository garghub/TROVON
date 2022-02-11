static T_1 F_1 ( const struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( const struct V_1 * V_2 , int V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static T_1 F_5 ( const struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 * 2 ) ;
}
static void F_6 ( const struct V_1 * V_2 , int V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 * 2 ) ;
}
static T_1 F_7 ( const struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 * 4 ) ;
}
static void F_8 ( const struct V_1 * V_2 , int V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 * 4 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
unsigned long V_8 )
{
V_2 -> V_9 . clock . V_10 = V_7 -> V_11 / 2 ;
V_2 -> V_12 = V_7 -> V_12 ;
V_2 -> V_13 = V_7 -> V_13 ;
switch ( V_8 & V_14 ) {
case V_15 :
V_2 -> V_16 = F_7 ;
V_2 -> V_17 = F_8 ;
break;
case V_18 :
V_2 -> V_16 = F_5 ;
V_2 -> V_17 = F_6 ;
break;
case V_19 :
default:
V_2 -> V_16 = F_1 ;
V_2 -> V_17 = F_3 ;
break;
}
}
static void F_10 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
int V_22 ;
T_2 V_23 ;
V_22 = F_11 ( V_21 , L_1 , & V_23 ) ;
if ( V_22 )
V_23 = 1 ;
switch ( V_23 ) {
case 4 :
V_2 -> V_16 = F_7 ;
V_2 -> V_17 = F_8 ;
break;
case 2 :
V_2 -> V_16 = F_5 ;
V_2 -> V_17 = F_6 ;
break;
case 1 :
default:
V_2 -> V_16 = F_1 ;
V_2 -> V_17 = F_3 ;
}
V_22 = F_11 ( V_21 , L_2 , & V_23 ) ;
if ( ! V_22 )
V_2 -> V_9 . clock . V_10 = V_23 / 2 ;
else
V_2 -> V_9 . clock . V_10 = V_24 ;
V_22 = F_11 ( V_21 , L_3 , & V_23 ) ;
if ( ! V_22 )
V_2 -> V_12 |= V_23 & V_25 ;
else
V_2 -> V_12 |= V_26 ;
V_22 = F_11 ( V_21 , L_4 , & V_23 ) ;
if ( ! V_22 )
V_2 -> V_12 |= ( V_23 << V_27 ) & V_28 ;
else
V_2 -> V_12 |= V_29 ;
V_22 = F_11 ( V_21 , L_5 , & V_23 ) ;
if ( ! V_22 && V_23 ) {
T_2 V_30 = V_2 -> V_9 . clock . V_10 * 2 / V_23 ;
if ( V_30 > 1 )
V_2 -> V_13 |= V_30 / 2 - 1 ;
else
V_2 -> V_13 |= V_31 ;
} else {
V_2 -> V_13 |= V_32 ;
}
if ( ! F_12 ( V_21 , L_6 ) )
V_2 -> V_13 |= V_33 ;
}
static int F_13 ( struct V_34 * V_35 )
{
int V_22 , V_36 = 0 ;
void T_3 * V_37 ;
struct V_38 * V_39 ;
struct V_1 * V_2 ;
struct V_40 * V_41 , * V_42 = NULL ;
struct V_6 * V_7 ;
struct V_20 * V_21 = V_35 -> V_39 . V_43 ;
V_7 = F_14 ( & V_35 -> V_39 ) ;
if ( ! V_7 && ! V_21 ) {
F_15 ( & V_35 -> V_39 , L_7 ) ;
return - V_44 ;
}
V_41 = F_16 ( V_35 , V_45 , 0 ) ;
if ( ! V_41 )
return - V_44 ;
if ( ! F_17 ( & V_35 -> V_39 , V_41 -> V_46 ,
F_18 ( V_41 ) , V_47 ) )
return - V_48 ;
V_37 = F_19 ( & V_35 -> V_39 , V_41 -> V_46 ,
F_18 ( V_41 ) ) ;
if ( ! V_37 )
return - V_49 ;
if ( V_21 )
V_36 = F_20 ( V_21 , 0 ) ;
else
V_42 = F_16 ( V_35 , V_50 , 0 ) ;
if ( ! V_36 && ! V_42 )
return - V_44 ;
V_39 = F_21 ( 0 ) ;
if ( ! V_39 )
return - V_49 ;
V_2 = F_22 ( V_39 ) ;
if ( V_42 ) {
V_36 = V_42 -> V_46 ;
V_2 -> V_51 = V_42 -> V_52 & V_53 ;
if ( V_42 -> V_52 & V_54 )
V_2 -> V_51 |= V_55 ;
} else {
V_2 -> V_51 = V_55 ;
}
V_39 -> V_36 = V_36 ;
V_2 -> V_4 = V_37 ;
if ( V_21 )
F_10 ( V_2 , V_21 ) ;
else
F_9 ( V_2 , V_7 , V_41 -> V_52 ) ;
F_23 ( V_35 , V_39 ) ;
F_24 ( V_39 , & V_35 -> V_39 ) ;
V_22 = F_25 ( V_39 ) ;
if ( V_22 ) {
F_15 ( & V_35 -> V_39 , L_8 ,
V_47 , V_22 ) ;
goto V_56;
}
F_26 ( & V_35 -> V_39 , L_9 ,
V_47 , V_2 -> V_4 , V_39 -> V_36 ) ;
return 0 ;
V_56:
F_27 ( V_39 ) ;
return V_22 ;
}
static int F_28 ( struct V_34 * V_35 )
{
struct V_38 * V_39 = F_29 ( V_35 ) ;
F_30 ( V_39 ) ;
F_27 ( V_39 ) ;
return 0 ;
}
