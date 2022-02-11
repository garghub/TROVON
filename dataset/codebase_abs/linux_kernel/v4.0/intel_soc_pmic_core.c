static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
V_4 = F_2 ( V_2 , L_1 , 0 ) ;
if ( F_3 ( V_4 ) )
return - V_6 ;
V_5 = F_4 ( V_4 ) ;
if ( V_5 < 0 )
F_5 ( V_2 , L_2 , V_5 ) ;
return V_5 ;
}
static int F_6 ( struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
const struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
int V_17 ;
int V_5 ;
V_12 = F_7 ( V_2 -> V_18 -> V_19 , V_2 ) ;
if ( ! V_12 || ! V_12 -> V_20 )
return - V_21 ;
V_14 = (struct V_13 * ) V_12 -> V_20 ;
V_16 = F_8 ( V_2 , sizeof( * V_16 ) , V_22 ) ;
if ( ! V_16 )
return - V_23 ;
F_9 ( V_2 , V_16 ) ;
V_16 -> V_24 = F_10 ( V_8 , V_14 -> V_25 ) ;
V_5 = F_1 ( V_2 ) ;
V_16 -> V_5 = ( V_5 < 0 ) ? V_8 -> V_5 : V_5 ;
V_17 = F_11 ( V_16 -> V_24 , V_16 -> V_5 ,
V_14 -> V_26 | V_27 ,
0 , V_14 -> V_28 ,
& V_16 -> V_29 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_12 ( V_16 -> V_5 ) ;
if ( V_17 )
F_5 ( V_2 , L_3 , V_17 ) ;
V_17 = F_13 ( V_2 , - 1 , V_14 -> V_30 ,
V_14 -> V_31 , NULL , 0 ,
F_14 ( V_16 -> V_29 ) ) ;
if ( V_17 )
goto V_32;
return 0 ;
V_32:
F_15 ( V_16 -> V_5 , V_16 -> V_29 ) ;
return V_17 ;
}
static int F_16 ( struct V_7 * V_8 )
{
struct V_15 * V_16 = F_17 ( & V_8 -> V_2 ) ;
F_15 ( V_16 -> V_5 , V_16 -> V_29 ) ;
F_18 ( & V_8 -> V_2 ) ;
return 0 ;
}
static void F_19 ( struct V_7 * V_8 )
{
struct V_15 * V_16 = F_17 ( & V_8 -> V_2 ) ;
F_20 ( V_16 -> V_5 ) ;
return;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_17 ( V_2 ) ;
F_20 ( V_16 -> V_5 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_17 ( V_2 ) ;
F_23 ( V_16 -> V_5 ) ;
return 0 ;
}
