static void F_1 ( struct V_1 * V_2 ,
struct V_3 * args ,
struct V_4 * V_5 )
{
F_2 ( V_2 , V_6 , V_7 , V_5 ) ;
F_3 ( V_2 , & args -> V_8 ) ;
F_4 ( V_2 , args -> V_9 ) ;
F_5 ( V_2 , args -> V_10 ) ;
}
static void F_6 ( struct V_11 * V_12 ,
struct V_1 * V_2 ,
struct V_3 * args )
{
struct V_4 V_5 = {
. V_13 = F_7 ( & args -> V_14 ) ,
} ;
F_8 ( V_2 , V_12 , & V_5 ) ;
F_9 ( V_2 , & args -> V_14 , & V_5 ) ;
F_10 ( V_2 , args -> V_15 , & V_5 ) ;
F_1 ( V_2 , args , & V_5 ) ;
F_11 ( & V_5 ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
int V_18 ;
T_1 * V_19 ;
V_18 = F_13 ( V_2 , V_6 ) ;
if ( V_18 )
return V_18 ;
V_19 = F_14 ( V_2 , 4 + 8 ) ;
if ( F_15 ( ! V_19 ) )
goto V_20;
V_17 -> V_21 = F_16 ( V_19 ++ ) ;
V_19 = F_17 ( V_19 , & V_17 -> V_22 ) ;
return 0 ;
V_20:
F_18 ( V_23 , V_2 ) ;
return - V_24 ;
}
static int F_19 ( struct V_11 * V_25 ,
struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_4 V_5 ;
int V_18 ;
V_18 = F_20 ( V_2 , & V_5 ) ;
if ( V_18 )
goto V_26;
V_18 = F_21 ( V_2 , & V_17 -> V_27 , V_25 ) ;
if ( V_18 )
goto V_26;
V_18 = F_22 ( V_2 ) ;
if ( V_18 )
goto V_26;
V_18 = F_12 ( V_2 , V_17 ) ;
V_26:
return V_18 ;
}
