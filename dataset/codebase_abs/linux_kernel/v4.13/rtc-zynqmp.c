static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_7 ;
V_7 = F_3 ( V_4 ) + 1 ;
if ( V_7 > V_8 )
return - V_9 ;
V_6 -> V_10 &= V_11 ;
F_4 ( V_6 -> V_10 , ( V_6 -> V_12 + V_13 ) ) ;
F_4 ( V_7 , V_6 -> V_12 + V_14 ) ;
F_4 ( V_15 , V_6 -> V_12 + V_16 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_17 ;
unsigned long V_18 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_17 = F_6 ( V_6 -> V_12 + V_16 ) ;
if ( V_17 & V_15 ) {
F_7 ( F_6 ( V_6 -> V_12 + V_19 ) , V_4 ) ;
} else {
V_18 = F_6 ( V_6 -> V_12 + V_20 ) - 1 ;
F_7 ( V_18 , V_4 ) ;
}
return F_8 ( V_4 ) ;
}
static int F_9 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_7 ( F_6 ( V_6 -> V_12 + V_23 ) , & V_22 -> time ) ;
V_22 -> V_24 = F_6 ( V_6 -> V_12 + V_25 ) & V_26 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_24 )
F_4 ( V_26 , V_6 -> V_12 + V_27 ) ;
else
F_4 ( V_26 , V_6 -> V_12 + V_28 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_29 ;
V_29 = F_3 ( & V_22 -> time ) ;
if ( V_29 > V_8 )
return - V_9 ;
F_4 ( ( T_1 ) V_29 , ( V_6 -> V_12 + V_23 ) ) ;
F_10 ( V_2 , V_22 -> V_24 ) ;
return 0 ;
}
static void F_12 ( struct V_5 * V_6 )
{
T_1 V_30 ;
V_30 = F_6 ( V_6 -> V_12 + V_31 ) ;
V_30 |= V_32 ;
F_4 ( V_30 , V_6 -> V_12 + V_31 ) ;
V_6 -> V_10 &= V_11 ;
F_4 ( V_6 -> V_10 , ( V_6 -> V_12 + V_13 ) ) ;
}
static T_2 F_13 ( int V_33 , void * V_34 )
{
struct V_5 * V_6 = (struct V_5 * ) V_34 ;
unsigned int V_17 ;
V_17 = F_6 ( V_6 -> V_12 + V_16 ) ;
if ( ! ( V_17 & ( V_15 | V_26 ) ) )
return V_35 ;
F_4 ( V_26 , V_6 -> V_12 + V_16 ) ;
if ( V_17 & V_26 )
F_14 ( V_6 -> V_36 , 1 , V_37 | V_38 ) ;
return V_39 ;
}
static int F_15 ( struct V_40 * V_41 )
{
struct V_5 * V_6 ;
struct V_42 * V_43 ;
int V_44 ;
V_6 = F_16 ( & V_41 -> V_2 , sizeof( * V_6 ) , V_45 ) ;
if ( ! V_6 )
return - V_46 ;
F_17 ( V_41 , V_6 ) ;
V_43 = F_18 ( V_41 , V_47 , 0 ) ;
V_6 -> V_12 = F_19 ( & V_41 -> V_2 , V_43 ) ;
if ( F_20 ( V_6 -> V_12 ) )
return F_21 ( V_6 -> V_12 ) ;
V_6 -> V_48 = F_22 ( V_41 , L_1 ) ;
if ( V_6 -> V_48 < 0 ) {
F_23 ( & V_41 -> V_2 , L_2 ) ;
return V_6 -> V_48 ;
}
V_44 = F_24 ( & V_41 -> V_2 , V_6 -> V_48 ,
F_13 , 0 ,
F_25 ( & V_41 -> V_2 ) , V_6 ) ;
if ( V_44 ) {
F_23 ( & V_41 -> V_2 , L_3 ) ;
return V_44 ;
}
V_6 -> V_49 = F_22 ( V_41 , L_4 ) ;
if ( V_6 -> V_49 < 0 ) {
F_23 ( & V_41 -> V_2 , L_2 ) ;
return V_6 -> V_49 ;
}
V_44 = F_24 ( & V_41 -> V_2 , V_6 -> V_49 ,
F_13 , 0 ,
F_25 ( & V_41 -> V_2 ) , V_6 ) ;
if ( V_44 ) {
F_23 ( & V_41 -> V_2 , L_3 ) ;
return V_44 ;
}
V_44 = F_26 ( V_41 -> V_2 . V_50 , L_5 ,
& V_6 -> V_10 ) ;
if ( V_44 )
V_6 -> V_10 = V_51 ;
F_12 ( V_6 ) ;
F_27 ( & V_41 -> V_2 , 1 ) ;
V_6 -> V_36 = F_28 ( & V_41 -> V_2 , V_41 -> V_52 ,
& V_53 , V_54 ) ;
return F_29 ( V_6 -> V_36 ) ;
}
static int F_30 ( struct V_40 * V_41 )
{
F_10 ( & V_41 -> V_2 , 0 ) ;
F_27 ( & V_41 -> V_2 , 0 ) ;
return 0 ;
}
static int T_3 F_31 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = F_32 ( V_2 ) ;
struct V_5 * V_6 = F_33 ( V_41 ) ;
if ( F_34 ( & V_41 -> V_2 ) )
F_35 ( V_6 -> V_48 ) ;
else
F_10 ( V_2 , 0 ) ;
return 0 ;
}
static int T_3 F_36 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = F_32 ( V_2 ) ;
struct V_5 * V_6 = F_33 ( V_41 ) ;
if ( F_34 ( & V_41 -> V_2 ) )
F_37 ( V_6 -> V_48 ) ;
else
F_10 ( V_2 , 1 ) ;
return 0 ;
}
