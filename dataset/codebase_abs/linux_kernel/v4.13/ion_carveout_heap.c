static T_1 F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 =
F_2 ( V_2 , struct V_4 , V_2 ) ;
unsigned long V_6 = F_3 ( V_5 -> V_7 , V_3 ) ;
if ( ! V_6 )
return V_8 ;
return V_6 ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_9 ,
unsigned long V_3 )
{
struct V_4 * V_5 =
F_2 ( V_2 , struct V_4 , V_2 ) ;
if ( V_9 == V_8 )
return;
F_5 ( V_5 -> V_7 , V_9 , V_3 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
unsigned long V_3 ,
unsigned long V_12 )
{
struct V_13 * V_14 ;
T_1 V_15 ;
int V_16 ;
V_14 = F_7 ( sizeof( * V_14 ) , V_17 ) ;
if ( ! V_14 )
return - V_18 ;
V_16 = F_8 ( V_14 , 1 , V_17 ) ;
if ( V_16 )
goto V_19;
V_15 = F_1 ( V_2 , V_3 ) ;
if ( V_15 == V_8 ) {
V_16 = - V_18 ;
goto V_20;
}
F_9 ( V_14 -> V_21 , F_10 ( F_11 ( V_15 ) ) , V_3 , 0 ) ;
V_11 -> V_13 = V_14 ;
return 0 ;
V_20:
F_12 ( V_14 ) ;
V_19:
F_13 ( V_14 ) ;
return V_16 ;
}
static void F_14 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_13 * V_14 = V_11 -> V_13 ;
struct V_22 * V_22 = F_15 ( V_14 -> V_21 ) ;
T_1 V_15 = F_16 ( F_17 ( V_22 ) ) ;
F_18 ( V_11 ) ;
F_4 ( V_2 , V_15 , V_11 -> V_3 ) ;
F_12 ( V_14 ) ;
F_13 ( V_14 ) ;
}
struct V_1 * F_19 ( struct V_23 * V_24 )
{
struct V_4 * V_5 ;
int V_16 ;
struct V_22 * V_22 ;
T_2 V_3 ;
V_22 = F_10 ( F_11 ( V_24 -> V_25 ) ) ;
V_3 = V_24 -> V_3 ;
V_16 = F_20 ( V_22 , V_3 , F_21 ( V_26 ) ) ;
if ( V_16 )
return F_22 ( V_16 ) ;
V_5 = F_23 ( sizeof( * V_5 ) , V_17 ) ;
if ( ! V_5 )
return F_22 ( - V_18 ) ;
V_5 -> V_7 = F_24 ( V_27 , - 1 ) ;
if ( ! V_5 -> V_7 ) {
F_13 ( V_5 ) ;
return F_22 ( - V_18 ) ;
}
V_5 -> V_25 = V_24 -> V_25 ;
F_25 ( V_5 -> V_7 , V_5 -> V_25 , V_24 -> V_3 ,
- 1 ) ;
V_5 -> V_2 . V_28 = & V_29 ;
V_5 -> V_2 . type = V_30 ;
V_5 -> V_2 . V_12 = V_31 ;
return & V_5 -> V_2 ;
}
