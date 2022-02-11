static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_7 ;
V_7 = F_3 ( V_4 ) ;
if ( V_7 > V_8 )
return - V_9 ;
F_4 ( V_7 , V_6 -> V_10 + V_11 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_6 ( F_7 ( V_6 -> V_10 + V_12 ) , V_4 ) ;
return F_8 ( V_4 ) ;
}
static int F_9 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_6 ( F_7 ( V_6 -> V_10 + V_15 ) , & V_14 -> time ) ;
V_14 -> V_16 = F_7 ( V_6 -> V_10 + V_17 ) & V_18 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_16 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_16 )
F_4 ( V_18 , V_6 -> V_10 + V_19 ) ;
else
F_4 ( V_18 , V_6 -> V_10 + V_20 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_21 ;
V_21 = F_3 ( & V_14 -> time ) ;
if ( V_21 > V_8 )
return - V_9 ;
F_4 ( ( T_1 ) V_21 , ( V_6 -> V_10 + V_15 ) ) ;
F_10 ( V_2 , V_14 -> V_16 ) ;
return 0 ;
}
static void F_12 ( struct V_5 * V_6 , T_1 V_22 )
{
V_22 &= V_23 ;
F_4 ( V_22 , ( V_6 -> V_10 + V_24 ) ) ;
}
static T_2 F_13 ( int V_25 , void * V_26 )
{
struct V_5 * V_6 = (struct V_5 * ) V_26 ;
unsigned int V_27 ;
V_27 = F_7 ( V_6 -> V_10 + V_28 ) ;
if ( ! ( V_27 & ( V_29 | V_18 ) ) )
return V_30 ;
F_4 ( V_27 , V_6 -> V_10 + V_28 ) ;
if ( V_27 & V_29 )
F_14 ( V_6 -> V_31 , 1 , V_32 | V_33 ) ;
if ( V_27 & V_18 )
F_14 ( V_6 -> V_31 , 1 , V_32 | V_34 ) ;
return V_35 ;
}
static int F_15 ( struct V_36 * V_37 )
{
struct V_5 * V_6 ;
struct V_38 * V_39 ;
int V_40 ;
unsigned int V_41 ;
V_6 = F_16 ( & V_37 -> V_2 , sizeof( * V_6 ) , V_42 ) ;
if ( ! V_6 )
return - V_43 ;
F_17 ( V_37 , V_6 ) ;
V_39 = F_18 ( V_37 , V_44 , 0 ) ;
V_6 -> V_10 = F_19 ( & V_37 -> V_2 , V_39 ) ;
if ( F_20 ( V_6 -> V_10 ) )
return F_21 ( V_6 -> V_10 ) ;
V_6 -> V_45 = F_22 ( V_37 , L_1 ) ;
if ( V_6 -> V_45 < 0 ) {
F_23 ( & V_37 -> V_2 , L_2 ) ;
return V_6 -> V_45 ;
}
V_40 = F_24 ( & V_37 -> V_2 , V_6 -> V_45 ,
F_13 , 0 ,
F_25 ( & V_37 -> V_2 ) , V_6 ) ;
if ( V_40 ) {
F_23 ( & V_37 -> V_2 , L_3 ) ;
return V_40 ;
}
V_6 -> V_46 = F_22 ( V_37 , L_4 ) ;
if ( V_6 -> V_46 < 0 ) {
F_23 ( & V_37 -> V_2 , L_2 ) ;
return V_6 -> V_46 ;
}
V_40 = F_24 ( & V_37 -> V_2 , V_6 -> V_46 ,
F_13 , 0 ,
F_25 ( & V_37 -> V_2 ) , V_6 ) ;
if ( V_40 ) {
F_23 ( & V_37 -> V_2 , L_3 ) ;
return V_40 ;
}
V_40 = F_26 ( V_37 -> V_2 . V_47 , L_5 ,
& V_41 ) ;
if ( V_40 )
V_41 = V_48 ;
F_12 ( V_6 , V_41 ) ;
F_27 ( & V_37 -> V_2 , 1 ) ;
V_6 -> V_31 = F_28 ( & V_37 -> V_2 , V_37 -> V_49 ,
& V_50 , V_51 ) ;
return F_29 ( V_6 -> V_31 ) ;
}
static int F_30 ( struct V_36 * V_37 )
{
F_10 ( & V_37 -> V_2 , 0 ) ;
F_27 ( & V_37 -> V_2 , 0 ) ;
return 0 ;
}
static int T_3 F_31 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_32 ( V_2 ) ;
struct V_5 * V_6 = F_33 ( V_37 ) ;
if ( F_34 ( & V_37 -> V_2 ) )
F_35 ( V_6 -> V_45 ) ;
else
F_10 ( V_2 , 0 ) ;
return 0 ;
}
static int T_3 F_36 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_32 ( V_2 ) ;
struct V_5 * V_6 = F_33 ( V_37 ) ;
if ( F_34 ( & V_37 -> V_2 ) )
F_37 ( V_6 -> V_45 ) ;
else
F_10 ( V_2 , 1 ) ;
return 0 ;
}
