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
static T_1 F_9 ( const struct V_1 * V_2 , int V_3 )
{
struct V_6 * V_7 = V_2 -> V_2 ;
unsigned long V_8 ;
T_1 V_5 ;
F_10 ( & V_7 -> V_9 , V_8 ) ;
F_11 ( V_3 , V_2 -> V_4 + 0 ) ;
V_5 = F_12 ( V_2 -> V_4 + 2 ) ;
F_13 ( & V_7 -> V_9 , V_8 ) ;
return V_5 ;
}
static void F_14 ( const struct V_1 * V_2 ,
int V_3 , T_1 V_5 )
{
struct V_6 * V_7 = V_2 -> V_2 ;
unsigned long V_8 ;
F_10 ( & V_7 -> V_9 , V_8 ) ;
F_11 ( V_3 , V_2 -> V_4 + 0 ) ;
F_11 ( V_5 , V_2 -> V_4 + 2 ) ;
F_13 ( & V_7 -> V_9 , V_8 ) ;
}
static int F_15 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_6 * V_7 = V_2 -> V_2 ;
V_2 -> V_12 = F_9 ;
V_2 -> V_13 = F_14 ;
F_16 ( & V_7 -> V_9 ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
unsigned long V_16 )
{
V_2 -> V_17 . clock . V_18 = V_15 -> V_19 / 2 ;
V_2 -> V_20 = V_15 -> V_20 ;
V_2 -> V_21 = V_15 -> V_21 ;
switch ( V_16 & V_22 ) {
case V_23 :
V_2 -> V_12 = F_7 ;
V_2 -> V_13 = F_8 ;
break;
case V_24 :
V_2 -> V_12 = F_5 ;
V_2 -> V_13 = F_6 ;
break;
case V_25 :
default:
V_2 -> V_12 = F_1 ;
V_2 -> V_13 = F_3 ;
break;
}
}
static void F_18 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
int V_26 ;
T_2 V_27 ;
V_26 = F_19 ( V_11 , L_1 , & V_27 ) ;
if ( V_26 )
V_27 = 1 ;
switch ( V_27 ) {
case 4 :
V_2 -> V_12 = F_7 ;
V_2 -> V_13 = F_8 ;
break;
case 2 :
V_2 -> V_12 = F_5 ;
V_2 -> V_13 = F_6 ;
break;
case 1 :
default:
V_2 -> V_12 = F_1 ;
V_2 -> V_13 = F_3 ;
}
V_26 = F_19 ( V_11 , L_2 , & V_27 ) ;
if ( ! V_26 )
V_2 -> V_17 . clock . V_18 = V_27 / 2 ;
else
V_2 -> V_17 . clock . V_18 = V_28 ;
V_26 = F_19 ( V_11 , L_3 , & V_27 ) ;
if ( ! V_26 )
V_2 -> V_20 |= V_27 & V_29 ;
else
V_2 -> V_20 |= V_30 ;
V_26 = F_19 ( V_11 , L_4 , & V_27 ) ;
if ( ! V_26 )
V_2 -> V_20 |= ( V_27 << V_31 ) & V_32 ;
else
V_2 -> V_20 |= V_33 ;
V_26 = F_19 ( V_11 , L_5 , & V_27 ) ;
if ( ! V_26 && V_27 ) {
T_2 V_34 = V_2 -> V_17 . clock . V_18 * 2 / V_27 ;
if ( V_34 > 1 )
V_2 -> V_21 |= V_34 / 2 - 1 ;
else
V_2 -> V_21 |= V_35 ;
} else {
V_2 -> V_21 |= V_36 ;
}
if ( ! F_20 ( V_11 , L_6 ) )
V_2 -> V_21 |= V_37 ;
}
static int F_21 ( struct V_38 * V_39 )
{
int V_26 , V_40 = 0 ;
void T_3 * V_41 ;
struct V_42 * V_43 ;
struct V_1 * V_2 ;
struct V_44 * V_45 , * V_46 = NULL ;
struct V_14 * V_15 ;
struct V_10 * V_11 = V_39 -> V_43 . V_47 ;
const struct V_48 * V_49 ;
const struct V_50 * V_51 = NULL ;
T_4 V_52 = 0 ;
V_15 = F_22 ( & V_39 -> V_43 ) ;
if ( ! V_15 && ! V_11 ) {
F_23 ( & V_39 -> V_43 , L_7 ) ;
return - V_53 ;
}
V_45 = F_24 ( V_39 , V_54 , 0 ) ;
if ( ! V_45 )
return - V_53 ;
if ( ! F_25 ( & V_39 -> V_43 , V_45 -> V_55 ,
F_26 ( V_45 ) , V_56 ) )
return - V_57 ;
V_41 = F_27 ( & V_39 -> V_43 , V_45 -> V_55 ,
F_26 ( V_45 ) ) ;
if ( ! V_41 )
return - V_58 ;
if ( V_11 )
V_40 = F_28 ( V_11 , 0 ) ;
else
V_46 = F_24 ( V_39 , V_59 , 0 ) ;
if ( ! V_40 && ! V_46 )
return - V_53 ;
V_49 = F_29 ( V_60 , & V_39 -> V_43 ) ;
if ( V_49 && V_49 -> V_61 ) {
V_51 = V_49 -> V_61 ;
V_52 = V_51 -> V_52 ;
}
V_43 = F_30 ( V_52 ) ;
if ( ! V_43 )
return - V_58 ;
V_2 = F_31 ( V_43 ) ;
if ( V_46 ) {
V_40 = V_46 -> V_55 ;
V_2 -> V_62 = V_46 -> V_8 & V_63 ;
if ( V_46 -> V_8 & V_64 )
V_2 -> V_62 |= V_65 ;
} else {
V_2 -> V_62 = V_65 ;
}
V_43 -> V_40 = V_40 ;
V_2 -> V_4 = V_41 ;
if ( V_11 ) {
F_18 ( V_2 , V_11 ) ;
if ( V_51 && V_51 -> V_66 ) {
V_26 = V_51 -> V_66 ( V_2 , V_11 ) ;
if ( V_26 )
goto V_67;
}
} else {
F_17 ( V_2 , V_15 , V_45 -> V_8 ) ;
}
F_32 ( V_39 , V_43 ) ;
F_33 ( V_43 , & V_39 -> V_43 ) ;
V_26 = F_34 ( V_43 ) ;
if ( V_26 ) {
F_23 ( & V_39 -> V_43 , L_8 ,
V_56 , V_26 ) ;
goto V_67;
}
F_35 ( & V_39 -> V_43 , L_9 ,
V_56 , V_2 -> V_4 , V_43 -> V_40 ) ;
return 0 ;
V_67:
F_36 ( V_43 ) ;
return V_26 ;
}
static int F_37 ( struct V_38 * V_39 )
{
struct V_42 * V_43 = F_38 ( V_39 ) ;
F_39 ( V_43 ) ;
F_36 ( V_43 ) ;
return 0 ;
}
