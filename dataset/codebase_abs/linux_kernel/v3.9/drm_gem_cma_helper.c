static unsigned int F_1 ( struct V_1 * V_2 )
{
return ( unsigned int ) V_2 -> V_3 . V_4 . V_5 << V_6 ;
}
static void F_2 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
F_3 ( V_8 -> V_11 , V_10 -> V_12 . V_13 , V_10 -> V_14 ,
V_10 -> V_15 ) ;
}
struct V_9 * F_4 ( struct V_7 * V_8 ,
unsigned int V_13 )
{
struct V_9 * V_10 ;
struct V_1 * V_16 ;
int V_17 ;
V_13 = F_5 ( V_13 , V_18 ) ;
V_10 = F_6 ( sizeof( * V_10 ) , V_19 ) ;
if ( ! V_10 )
return F_7 ( - V_20 ) ;
V_10 -> V_14 = F_8 ( V_8 -> V_11 , V_13 ,
& V_10 -> V_15 , V_19 | V_21 ) ;
if ( ! V_10 -> V_14 ) {
F_9 ( V_8 -> V_11 , L_1 , V_13 ) ;
V_17 = - V_20 ;
goto V_22;
}
V_16 = & V_10 -> V_12 ;
V_17 = F_10 ( V_8 , V_16 , V_13 ) ;
if ( V_17 )
goto V_23;
V_17 = F_11 ( V_16 ) ;
if ( V_17 )
goto V_24;
return V_10 ;
V_24:
F_12 ( V_16 ) ;
V_23:
F_2 ( V_8 , V_10 ) ;
V_22:
F_13 ( V_10 ) ;
return F_7 ( V_17 ) ;
}
static struct V_9 * F_14 (
struct V_25 * V_26 ,
struct V_7 * V_8 , unsigned int V_13 ,
unsigned int * V_27 )
{
struct V_9 * V_10 ;
struct V_1 * V_16 ;
int V_17 ;
V_10 = F_4 ( V_8 , V_13 ) ;
if ( F_15 ( V_10 ) )
return V_10 ;
V_16 = & V_10 -> V_12 ;
V_17 = F_16 ( V_26 , V_16 , V_27 ) ;
if ( V_17 )
goto V_28;
F_17 ( V_16 ) ;
return V_10 ;
V_28:
F_18 ( V_16 ) ;
return F_7 ( V_17 ) ;
}
void F_18 ( struct V_1 * V_16 )
{
struct V_9 * V_10 ;
if ( V_16 -> V_3 . V_29 )
F_19 ( V_16 ) ;
F_12 ( V_16 ) ;
V_10 = F_20 ( V_16 ) ;
F_2 ( V_16 -> V_11 , V_10 ) ;
F_13 ( V_10 ) ;
}
int F_21 ( struct V_25 * V_26 ,
struct V_7 * V_11 , struct V_30 * args )
{
struct V_9 * V_10 ;
int V_31 = F_22 ( args -> V_32 * args -> V_33 , 8 ) ;
if ( args -> V_34 < V_31 )
args -> V_34 = V_31 ;
if ( args -> V_13 < args -> V_34 * args -> V_35 )
args -> V_13 = args -> V_34 * args -> V_35 ;
V_10 = F_14 ( V_26 , V_11 ,
args -> V_13 , & args -> V_27 ) ;
if ( F_15 ( V_10 ) )
return F_23 ( V_10 ) ;
return 0 ;
}
int F_24 ( struct V_25 * V_26 ,
struct V_7 * V_8 , T_1 V_27 , T_2 * V_36 )
{
struct V_1 * V_16 ;
F_25 ( & V_8 -> V_37 ) ;
V_16 = F_26 ( V_8 , V_26 , V_27 ) ;
if ( ! V_16 ) {
F_9 ( V_8 -> V_11 , L_2 ) ;
F_27 ( & V_8 -> V_37 ) ;
return - V_38 ;
}
* V_36 = F_1 ( V_16 ) ;
F_28 ( V_16 ) ;
F_27 ( & V_8 -> V_37 ) ;
return 0 ;
}
int F_29 ( struct V_39 * V_40 , struct V_41 * V_42 )
{
struct V_1 * V_16 ;
struct V_9 * V_10 ;
int V_17 ;
V_17 = F_30 ( V_40 , V_42 ) ;
if ( V_17 )
return V_17 ;
V_16 = V_42 -> V_43 ;
V_10 = F_20 ( V_16 ) ;
V_17 = F_31 ( V_42 , V_42 -> V_44 , V_10 -> V_15 >> V_6 ,
V_42 -> V_45 - V_42 -> V_44 , V_42 -> V_46 ) ;
if ( V_17 )
F_32 ( V_42 ) ;
return V_17 ;
}
int F_33 ( struct V_25 * V_26 ,
struct V_7 * V_8 , unsigned int V_27 )
{
return F_34 ( V_26 , V_27 ) ;
}
void F_35 ( struct V_9 * V_10 , struct V_47 * V_48 )
{
struct V_1 * V_2 = & V_10 -> V_12 ;
struct V_7 * V_11 = V_2 -> V_11 ;
T_2 V_49 = 0 ;
F_36 ( ! F_37 ( & V_11 -> V_37 ) ) ;
if ( V_2 -> V_3 . V_29 )
V_49 = ( T_2 ) V_2 -> V_3 . V_4 . V_5 ;
F_38 ( V_48 , L_3 ,
V_2 -> V_50 , V_2 -> V_51 . V_51 . V_52 ,
V_49 , V_10 -> V_15 , V_10 -> V_14 , V_2 -> V_13 ) ;
F_38 ( V_48 , L_4 ) ;
}
