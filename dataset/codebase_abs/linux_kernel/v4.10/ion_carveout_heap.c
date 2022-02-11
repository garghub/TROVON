static T_1 F_1 ( struct V_1 * V_2 ,
unsigned long V_3 ,
unsigned long V_4 )
{
struct V_5 * V_6 =
F_2 ( V_2 , struct V_5 , V_2 ) ;
unsigned long V_7 = F_3 ( V_6 -> V_8 , V_3 ) ;
if ( ! V_7 )
return V_9 ;
return V_7 ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_10 ,
unsigned long V_3 )
{
struct V_5 * V_6 =
F_2 ( V_2 , struct V_5 , V_2 ) ;
if ( V_10 == V_9 )
return;
F_5 ( V_6 -> V_8 , V_10 , V_3 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
unsigned long V_3 , unsigned long V_4 ,
unsigned long V_13 )
{
struct V_14 * V_15 ;
T_1 V_16 ;
int V_17 ;
if ( V_4 > V_18 )
return - V_19 ;
V_15 = F_7 ( sizeof( * V_15 ) , V_20 ) ;
if ( ! V_15 )
return - V_21 ;
V_17 = F_8 ( V_15 , 1 , V_20 ) ;
if ( V_17 )
goto V_22;
V_16 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_16 == V_9 ) {
V_17 = - V_21 ;
goto V_23;
}
F_9 ( V_15 -> V_24 , F_10 ( F_11 ( V_16 ) ) , V_3 , 0 ) ;
V_12 -> V_14 = V_15 ;
return 0 ;
V_23:
F_12 ( V_15 ) ;
V_22:
F_13 ( V_15 ) ;
return V_17 ;
}
static void F_14 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_14 * V_15 = V_12 -> V_14 ;
struct V_25 * V_25 = F_15 ( V_15 -> V_24 ) ;
T_1 V_16 = F_16 ( F_17 ( V_25 ) ) ;
F_18 ( V_12 ) ;
if ( F_19 ( V_12 ) )
F_20 ( NULL , V_15 -> V_24 , V_15 -> V_26 ,
V_27 ) ;
F_4 ( V_2 , V_16 , V_12 -> V_3 ) ;
F_12 ( V_15 ) ;
F_13 ( V_15 ) ;
}
struct V_1 * F_21 ( struct V_28 * V_29 )
{
struct V_5 * V_6 ;
int V_17 ;
struct V_25 * V_25 ;
T_2 V_3 ;
V_25 = F_10 ( F_11 ( V_29 -> V_30 ) ) ;
V_3 = V_29 -> V_3 ;
F_22 ( NULL , V_25 , V_3 , V_27 ) ;
V_17 = F_23 ( V_25 , V_3 , F_24 ( V_31 ) ) ;
if ( V_17 )
return F_25 ( V_17 ) ;
V_6 = F_26 ( sizeof( * V_6 ) , V_20 ) ;
if ( ! V_6 )
return F_25 ( - V_21 ) ;
V_6 -> V_8 = F_27 ( V_32 , - 1 ) ;
if ( ! V_6 -> V_8 ) {
F_13 ( V_6 ) ;
return F_25 ( - V_21 ) ;
}
V_6 -> V_30 = V_29 -> V_30 ;
F_28 ( V_6 -> V_8 , V_6 -> V_30 , V_29 -> V_3 ,
- 1 ) ;
V_6 -> V_2 . V_33 = & V_34 ;
V_6 -> V_2 . type = V_35 ;
V_6 -> V_2 . V_13 = V_36 ;
return & V_6 -> V_2 ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_2 ( V_2 , struct V_5 , V_2 ) ;
F_30 ( V_6 -> V_8 ) ;
F_13 ( V_6 ) ;
V_6 = NULL ;
}
