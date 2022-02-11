static int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
int V_4 ;
T_1 V_5 ;
char * V_6 ;
struct V_7 * V_7 ;
V_7 = V_3 -> V_8 -> V_9 ;
F_2 ( V_10 , L_1 ) ;
F_3 ( ! F_4 ( V_3 ) ) ;
V_4 = F_5 ( V_7 , V_3 ) ;
if ( V_4 == 0 )
return V_4 ;
V_6 = F_6 ( V_3 ) ;
V_5 = F_7 ( V_3 ) ;
V_4 = F_8 ( V_2 , V_6 , NULL , V_11 , V_5 ) ;
if ( V_4 < 0 ) {
F_9 ( V_7 , V_3 ) ;
goto V_12;
}
memset ( V_6 + V_4 , 0 , V_11 - V_4 ) ;
F_10 ( V_3 ) ;
F_11 ( V_3 ) ;
F_12 ( V_7 , V_3 ) ;
V_4 = 0 ;
V_12:
F_13 ( V_3 ) ;
F_14 ( V_3 ) ;
return V_4 ;
}
static int F_15 ( struct V_13 * V_14 , struct V_3 * V_3 )
{
return F_1 ( V_14 -> V_15 , V_3 ) ;
}
static int F_16 ( struct V_13 * V_14 , struct V_16 * V_8 ,
struct V_17 * V_18 , unsigned V_19 )
{
int V_20 = 0 ;
struct V_7 * V_7 ;
V_7 = V_8 -> V_9 ;
F_2 ( V_10 , L_2 , V_7 , V_14 ) ;
V_20 = F_17 ( V_7 , V_8 , V_18 , & V_19 ) ;
if ( V_20 == 0 )
return V_20 ;
V_20 = F_18 ( V_8 , V_18 , ( void * ) F_15 , V_14 ) ;
F_2 ( V_10 , L_3 , V_20 ) ;
return V_20 ;
}
static int F_19 ( struct V_3 * V_3 , T_2 V_21 )
{
if ( F_20 ( V_3 ) )
return 0 ;
return F_21 ( V_3 , V_21 ) ;
}
static void F_22 ( struct V_3 * V_3 , unsigned int V_5 ,
unsigned int V_22 )
{
if ( V_5 == 0 && V_22 == V_11 )
F_23 ( V_3 ) ;
}
static int F_24 ( struct V_3 * V_3 )
{
char * V_6 ;
int V_4 , V_23 ;
T_1 V_5 , V_24 ;
T_3 V_25 ;
struct V_26 * V_27 ;
struct V_7 * V_7 = V_3 -> V_8 -> V_9 ;
V_27 = F_25 ( V_7 ) ;
V_24 = F_26 ( V_7 ) ;
if ( V_3 -> V_28 == V_24 >> V_29 )
V_23 = V_24 & ~ V_30 ;
else
V_23 = V_11 ;
F_27 ( V_3 ) ;
V_6 = F_6 ( V_3 ) ;
V_5 = F_7 ( V_3 ) ;
V_25 = F_28 () ;
F_29 ( F_30 () ) ;
F_3 ( ! V_27 -> V_31 ) ;
V_4 = F_31 ( V_7 ,
V_27 -> V_31 ,
( V_32 const char V_33 * ) V_6 ,
V_23 , & V_5 , 0 ) ;
if ( V_4 > 0 )
V_4 = 0 ;
F_29 ( V_25 ) ;
F_13 ( V_3 ) ;
F_32 ( V_3 ) ;
return V_4 ;
}
static int F_33 ( struct V_3 * V_3 , struct V_34 * V_35 )
{
int V_4 ;
F_2 ( V_10 , L_4 , V_3 ) ;
V_4 = F_24 ( V_3 ) ;
if ( V_4 < 0 ) {
if ( V_4 == - V_36 ) {
F_34 ( V_35 , V_3 ) ;
V_4 = 0 ;
} else {
F_35 ( V_3 ) ;
F_36 ( V_3 -> V_8 , V_4 ) ;
}
} else
V_4 = 0 ;
F_14 ( V_3 ) ;
return V_4 ;
}
static int F_37 ( struct V_3 * V_3 )
{
int V_4 ;
struct V_7 * V_7 = V_3 -> V_8 -> V_9 ;
F_38 ( V_7 , V_3 ) ;
if ( F_39 ( V_3 ) ) {
V_4 = F_24 ( V_3 ) ;
if ( V_4 )
return V_4 ;
}
return 0 ;
}
static T_4
F_40 ( int V_37 , struct V_38 * V_39 , struct V_40 * V_41 , T_1 V_42 )
{
F_2 ( V_10 , L_5 ,
V_39 -> V_43 ,
( long long ) V_42 , V_41 -> V_44 ) ;
return - V_45 ;
}
static int F_41 ( struct V_13 * V_14 , struct V_16 * V_8 ,
T_1 V_42 , unsigned V_23 , unsigned V_46 ,
struct V_3 * * V_47 , void * * V_48 )
{
int V_4 = 0 ;
struct V_3 * V_3 ;
struct V_26 * V_27 ;
T_5 V_28 = V_42 >> V_29 ;
struct V_7 * V_7 = V_8 -> V_9 ;
F_2 ( V_10 , L_6 , V_14 , V_8 ) ;
V_27 = F_25 ( V_7 ) ;
V_49:
V_3 = F_42 ( V_8 , V_28 , V_46 ) ;
if ( ! V_3 ) {
V_4 = - V_50 ;
goto V_51;
}
F_3 ( ! V_27 -> V_31 ) ;
if ( F_43 ( V_3 ) )
goto V_51;
if ( V_23 == V_11 )
goto V_51;
V_4 = F_1 ( V_27 -> V_31 , V_3 ) ;
F_44 ( V_3 ) ;
if ( ! V_4 )
goto V_49;
V_51:
* V_47 = V_3 ;
return V_4 ;
}
static int F_45 ( struct V_13 * V_14 , struct V_16 * V_8 ,
T_1 V_42 , unsigned V_23 , unsigned V_52 ,
struct V_3 * V_3 , void * V_48 )
{
T_1 V_53 = V_42 + V_52 ;
struct V_7 * V_7 = V_3 -> V_8 -> V_9 ;
F_2 ( V_10 , L_6 , V_14 , V_8 ) ;
if ( F_46 ( V_52 < V_23 ) ) {
unsigned V_54 = V_42 & ( V_11 - 1 ) ;
F_47 ( V_3 , V_54 + V_52 , V_23 - V_52 ) ;
F_10 ( V_3 ) ;
}
if ( ! F_43 ( V_3 ) )
F_11 ( V_3 ) ;
if ( V_53 > V_7 -> V_55 ) {
F_48 ( V_7 , V_53 - V_7 -> V_55 ) ;
F_49 ( V_7 , V_53 ) ;
}
F_50 ( V_3 ) ;
F_14 ( V_3 ) ;
F_44 ( V_3 ) ;
return V_52 ;
}
