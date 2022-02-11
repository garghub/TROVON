static int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
struct V_4 * V_4 = V_3 -> V_5 -> V_6 ;
struct V_7 V_8 = { . V_9 = V_3 , . V_10 = V_11 } ;
struct V_12 V_13 ;
int V_14 , V_15 ;
F_2 ( V_16 , L_1 ) ;
F_3 ( ! F_4 ( V_3 ) ) ;
V_14 = F_5 ( V_4 , V_3 ) ;
if ( V_14 == 0 )
return V_14 ;
F_6 ( & V_13 , V_17 | V_18 , & V_8 , 1 , V_11 ) ;
V_14 = F_7 ( V_2 , F_8 ( V_3 ) , & V_13 , & V_15 ) ;
if ( V_15 ) {
F_9 ( V_4 , V_3 ) ;
V_14 = V_15 ;
goto V_19;
}
F_10 ( V_3 , V_14 , V_11 - V_14 ) ;
F_11 ( V_3 ) ;
F_12 ( V_3 ) ;
F_13 ( V_4 , V_3 ) ;
V_14 = 0 ;
V_19:
F_14 ( V_3 ) ;
return V_14 ;
}
static int F_15 ( struct V_20 * V_21 , struct V_3 * V_3 )
{
return F_1 ( V_21 -> V_22 , V_3 ) ;
}
static int F_16 ( struct V_20 * V_21 , struct V_23 * V_5 ,
struct V_24 * V_25 , unsigned V_26 )
{
int V_27 = 0 ;
struct V_4 * V_4 ;
V_4 = V_5 -> V_6 ;
F_2 ( V_16 , L_2 , V_4 , V_21 ) ;
V_27 = F_17 ( V_4 , V_5 , V_25 , & V_26 ) ;
if ( V_27 == 0 )
return V_27 ;
V_27 = F_18 ( V_5 , V_25 , ( void * ) F_15 , V_21 ) ;
F_2 ( V_16 , L_3 , V_27 ) ;
return V_27 ;
}
static int F_19 ( struct V_3 * V_3 , T_1 V_28 )
{
if ( F_20 ( V_3 ) )
return 0 ;
return F_21 ( V_3 , V_28 ) ;
}
static void F_22 ( struct V_3 * V_3 , unsigned int V_29 ,
unsigned int V_30 )
{
if ( V_29 == 0 && V_30 == V_11 )
F_23 ( V_3 ) ;
}
static int F_24 ( struct V_3 * V_3 )
{
struct V_4 * V_4 = V_3 -> V_5 -> V_6 ;
struct V_31 * V_32 = F_25 ( V_4 ) ;
T_2 V_33 = F_26 ( V_4 ) ;
struct V_12 V_34 ;
struct V_7 V_8 ;
int V_15 , V_35 ;
if ( V_3 -> V_36 == V_33 >> V_37 )
V_35 = V_33 & ~ V_38 ;
else
V_35 = V_11 ;
V_8 . V_9 = V_3 ;
V_8 . V_39 = 0 ;
V_8 . V_10 = V_35 ;
F_6 ( & V_34 , V_17 | V_40 , & V_8 , 1 , V_35 ) ;
F_3 ( ! V_32 -> V_41 ) ;
F_27 ( V_3 ) ;
F_28 ( V_32 -> V_41 , F_8 ( V_3 ) , & V_34 , & V_15 ) ;
F_29 ( V_3 ) ;
return V_15 ;
}
static int F_30 ( struct V_3 * V_3 , struct V_42 * V_43 )
{
int V_14 ;
F_2 ( V_16 , L_4 , V_3 ) ;
V_14 = F_24 ( V_3 ) ;
if ( V_14 < 0 ) {
if ( V_14 == - V_44 ) {
F_31 ( V_43 , V_3 ) ;
V_14 = 0 ;
} else {
F_32 ( V_3 ) ;
F_33 ( V_3 -> V_5 , V_14 ) ;
}
} else
V_14 = 0 ;
F_14 ( V_3 ) ;
return V_14 ;
}
static int F_34 ( struct V_3 * V_3 )
{
int V_14 ;
struct V_4 * V_4 = V_3 -> V_5 -> V_6 ;
F_35 ( V_4 , V_3 ) ;
if ( F_36 ( V_3 ) ) {
V_14 = F_24 ( V_3 ) ;
if ( V_14 )
return V_14 ;
}
return 0 ;
}
static T_3
F_37 ( struct V_45 * V_46 , struct V_12 * V_47 )
{
struct V_20 * V_20 = V_46 -> V_48 ;
T_2 V_49 = V_46 -> V_50 ;
T_3 V_51 ;
int V_15 = 0 ;
if ( F_38 ( V_47 ) == V_40 ) {
V_51 = F_28 ( V_20 -> V_22 , V_49 , V_47 , & V_15 ) ;
if ( V_51 ) {
struct V_4 * V_4 = F_39 ( V_20 ) ;
T_2 V_52 = F_26 ( V_4 ) ;
if ( V_49 + V_51 > V_52 )
F_40 ( V_4 , V_49 + V_51 - V_52 ) ;
}
} else {
V_51 = F_7 ( V_20 -> V_22 , V_49 , V_47 , & V_15 ) ;
}
return V_51 ? V_51 : V_15 ;
}
static int F_41 ( struct V_20 * V_21 , struct V_23 * V_5 ,
T_2 V_49 , unsigned V_35 , unsigned V_53 ,
struct V_3 * * V_54 , void * * V_55 )
{
int V_14 = 0 ;
struct V_3 * V_3 ;
struct V_31 * V_32 ;
T_4 V_36 = V_49 >> V_37 ;
struct V_4 * V_4 = V_5 -> V_6 ;
F_2 ( V_16 , L_5 , V_21 , V_5 ) ;
V_32 = F_25 ( V_4 ) ;
V_56:
V_3 = F_42 ( V_5 , V_36 , V_53 ) ;
if ( ! V_3 ) {
V_14 = - V_57 ;
goto V_58;
}
F_3 ( ! V_32 -> V_41 ) ;
if ( F_43 ( V_3 ) )
goto V_58;
if ( V_35 == V_11 )
goto V_58;
V_14 = F_1 ( V_32 -> V_41 , V_3 ) ;
F_44 ( V_3 ) ;
if ( ! V_14 )
goto V_56;
V_58:
* V_54 = V_3 ;
return V_14 ;
}
static int F_45 ( struct V_20 * V_21 , struct V_23 * V_5 ,
T_2 V_49 , unsigned V_35 , unsigned V_59 ,
struct V_3 * V_3 , void * V_55 )
{
T_2 V_60 = V_49 + V_59 ;
struct V_4 * V_4 = V_3 -> V_5 -> V_6 ;
F_2 ( V_16 , L_5 , V_21 , V_5 ) ;
if ( ! F_43 ( V_3 ) ) {
if ( F_46 ( V_59 < V_35 ) ) {
V_59 = 0 ;
goto V_58;
} else if ( V_35 == V_11 ) {
F_12 ( V_3 ) ;
}
}
if ( V_60 > V_4 -> V_52 ) {
F_40 ( V_4 , V_60 - V_4 -> V_52 ) ;
F_47 ( V_4 , V_60 ) ;
}
F_48 ( V_3 ) ;
V_58:
F_14 ( V_3 ) ;
F_44 ( V_3 ) ;
return V_59 ;
}
