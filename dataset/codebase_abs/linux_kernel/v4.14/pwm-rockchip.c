static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( struct V_2 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_1 * V_9 = F_1 ( V_4 ) ;
T_1 V_10 = V_9 -> V_11 -> V_10 ;
unsigned long V_12 ;
T_2 V_13 ;
T_1 V_14 ;
int V_15 ;
V_15 = F_4 ( V_9 -> V_16 ) ;
if ( V_15 )
return;
V_12 = F_5 ( V_9 -> V_17 ) ;
V_13 = F_6 ( V_9 -> V_18 + V_9 -> V_11 -> V_19 . V_20 ) ;
V_13 *= V_9 -> V_11 -> V_21 * V_22 ;
V_8 -> V_20 = F_7 ( V_13 , V_12 ) ;
V_13 = F_6 ( V_9 -> V_18 + V_9 -> V_11 -> V_19 . V_23 ) ;
V_13 *= V_9 -> V_11 -> V_21 * V_22 ;
V_8 -> V_24 = F_7 ( V_13 , V_12 ) ;
V_14 = F_6 ( V_9 -> V_18 + V_9 -> V_11 -> V_19 . V_25 ) ;
if ( V_9 -> V_11 -> V_26 )
V_8 -> V_27 = ( ( V_14 & V_10 ) != V_10 ) ?
false : true ;
else
V_8 -> V_27 = ( ( V_14 & V_10 ) == V_10 ) ?
true : false ;
if ( V_9 -> V_11 -> V_26 ) {
if ( ! ( V_14 & V_28 ) )
V_8 -> V_29 = V_30 ;
}
F_8 ( V_9 -> V_16 ) ;
}
static void F_9 ( struct V_2 * V_4 , struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_1 * V_9 = F_1 ( V_4 ) ;
unsigned long V_20 , V_23 ;
T_2 V_12 , div ;
T_1 V_25 ;
V_12 = F_5 ( V_9 -> V_17 ) ;
div = V_12 * V_8 -> V_20 ;
V_20 = F_7 ( div ,
V_9 -> V_11 -> V_21 * V_22 ) ;
div = V_12 * V_8 -> V_24 ;
V_23 = F_7 ( div , V_9 -> V_11 -> V_21 * V_22 ) ;
V_25 = F_6 ( V_9 -> V_18 + V_9 -> V_11 -> V_19 . V_25 ) ;
if ( V_9 -> V_11 -> V_31 ) {
V_25 |= V_32 ;
F_10 ( V_25 , V_9 -> V_18 + V_9 -> V_11 -> V_19 . V_25 ) ;
}
F_11 ( V_20 , V_9 -> V_18 + V_9 -> V_11 -> V_19 . V_20 ) ;
F_11 ( V_23 , V_9 -> V_18 + V_9 -> V_11 -> V_19 . V_23 ) ;
if ( V_9 -> V_11 -> V_26 ) {
V_25 &= ~ V_33 ;
if ( V_8 -> V_29 == V_30 )
V_25 |= V_34 | V_35 ;
else
V_25 |= V_28 | V_36 ;
}
if ( V_9 -> V_11 -> V_31 )
V_25 &= ~ V_32 ;
F_11 ( V_25 , V_9 -> V_18 + V_9 -> V_11 -> V_19 . V_25 ) ;
}
static int F_12 ( struct V_2 * V_4 ,
struct V_5 * V_6 ,
bool V_37 )
{
struct V_1 * V_9 = F_1 ( V_4 ) ;
T_1 V_10 = V_9 -> V_11 -> V_10 ;
int V_15 ;
T_1 V_14 ;
if ( V_37 ) {
V_15 = F_4 ( V_9 -> V_17 ) ;
if ( V_15 )
return V_15 ;
}
V_14 = F_6 ( V_9 -> V_18 + V_9 -> V_11 -> V_19 . V_25 ) ;
if ( V_37 )
V_14 |= V_10 ;
else
V_14 &= ~ V_10 ;
F_10 ( V_14 , V_9 -> V_18 + V_9 -> V_11 -> V_19 . V_25 ) ;
if ( ! V_37 )
F_8 ( V_9 -> V_17 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_4 , struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_1 * V_9 = F_1 ( V_4 ) ;
struct V_7 V_38 ;
bool V_27 ;
int V_15 = 0 ;
V_15 = F_4 ( V_9 -> V_16 ) ;
if ( V_15 )
return V_15 ;
F_14 ( V_6 , & V_38 ) ;
V_27 = V_38 . V_27 ;
if ( V_8 -> V_29 != V_38 . V_29 && V_27 &&
! V_9 -> V_11 -> V_31 ) {
V_15 = F_12 ( V_4 , V_6 , false ) ;
if ( V_15 )
goto V_39;
V_27 = false ;
}
F_9 ( V_4 , V_6 , V_8 ) ;
if ( V_8 -> V_27 != V_27 ) {
V_15 = F_12 ( V_4 , V_6 , V_8 -> V_27 ) ;
if ( V_15 )
goto V_39;
}
F_3 ( V_4 , V_6 , V_8 ) ;
V_39:
F_8 ( V_9 -> V_16 ) ;
return V_15 ;
}
static int F_15 ( struct V_40 * V_41 )
{
const struct V_42 * V_43 ;
struct V_1 * V_9 ;
struct V_44 * V_45 ;
int V_15 , V_46 ;
V_43 = F_16 ( V_47 , & V_41 -> V_48 ) ;
if ( ! V_43 )
return - V_49 ;
V_9 = F_17 ( & V_41 -> V_48 , sizeof( * V_9 ) , V_50 ) ;
if ( ! V_9 )
return - V_51 ;
V_45 = F_18 ( V_41 , V_52 , 0 ) ;
V_9 -> V_18 = F_19 ( & V_41 -> V_48 , V_45 ) ;
if ( F_20 ( V_9 -> V_18 ) )
return F_21 ( V_9 -> V_18 ) ;
V_9 -> V_17 = F_22 ( & V_41 -> V_48 , L_1 ) ;
if ( F_20 ( V_9 -> V_17 ) ) {
V_9 -> V_17 = F_22 ( & V_41 -> V_48 , NULL ) ;
if ( F_20 ( V_9 -> V_17 ) ) {
V_15 = F_21 ( V_9 -> V_17 ) ;
if ( V_15 != - V_53 )
F_23 ( & V_41 -> V_48 , L_2 ,
V_15 ) ;
return V_15 ;
}
}
V_46 = F_24 ( V_41 -> V_48 . V_54 ,
L_3 , L_4 ) ;
if ( V_46 == 2 )
V_9 -> V_16 = F_22 ( & V_41 -> V_48 , L_5 ) ;
else
V_9 -> V_16 = V_9 -> V_17 ;
if ( F_20 ( V_9 -> V_16 ) ) {
V_15 = F_21 ( V_9 -> V_16 ) ;
if ( V_15 != - V_53 )
F_23 ( & V_41 -> V_48 , L_6 , V_15 ) ;
return V_15 ;
}
V_15 = F_25 ( V_9 -> V_17 ) ;
if ( V_15 ) {
F_23 ( & V_41 -> V_48 , L_7 , V_15 ) ;
return V_15 ;
}
V_15 = F_26 ( V_9 -> V_16 ) ;
if ( V_15 ) {
F_23 ( & V_41 -> V_48 , L_8 , V_15 ) ;
goto V_55;
}
F_27 ( V_41 , V_9 ) ;
V_9 -> V_11 = V_43 -> V_11 ;
V_9 -> V_4 . V_48 = & V_41 -> V_48 ;
V_9 -> V_4 . V_56 = & V_57 ;
V_9 -> V_4 . V_18 = - 1 ;
V_9 -> V_4 . V_58 = 1 ;
if ( V_9 -> V_11 -> V_26 ) {
V_9 -> V_4 . V_59 = V_60 ;
V_9 -> V_4 . V_61 = 3 ;
}
V_15 = F_28 ( & V_9 -> V_4 ) ;
if ( V_15 < 0 ) {
F_29 ( V_9 -> V_17 ) ;
F_23 ( & V_41 -> V_48 , L_9 , V_15 ) ;
goto V_62;
}
if ( ! F_30 ( V_9 -> V_4 . V_63 ) )
F_8 ( V_9 -> V_17 ) ;
return 0 ;
V_62:
F_29 ( V_9 -> V_16 ) ;
V_55:
F_31 ( V_9 -> V_17 ) ;
return V_15 ;
}
static int F_32 ( struct V_40 * V_41 )
{
struct V_1 * V_9 = F_33 ( V_41 ) ;
if ( F_30 ( V_9 -> V_4 . V_63 ) )
F_8 ( V_9 -> V_17 ) ;
F_29 ( V_9 -> V_16 ) ;
F_29 ( V_9 -> V_17 ) ;
return F_34 ( & V_9 -> V_4 ) ;
}
