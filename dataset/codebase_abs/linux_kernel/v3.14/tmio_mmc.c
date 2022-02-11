static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
const struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
V_6 = F_3 ( & V_2 -> V_2 ) ;
if ( ! V_6 && V_5 -> V_7 )
V_5 -> V_7 ( V_2 ) ;
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 )
{
const struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 = 0 ;
if ( V_5 -> V_8 )
V_6 = V_5 -> V_8 ( V_2 ) ;
if ( ! V_6 )
V_6 = F_5 ( & V_2 -> V_2 ) ;
return V_6 ;
}
static int F_6 ( struct V_1 * V_9 )
{
const struct V_4 * V_5 = F_2 ( V_9 ) ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_6 = - V_16 , V_17 ;
if ( V_9 -> V_18 != 2 )
goto V_19;
V_11 = V_9 -> V_2 . V_20 ;
if ( ! V_11 || ! V_11 -> V_21 )
goto V_19;
V_17 = F_7 ( V_9 , 0 ) ;
if ( V_17 < 0 ) {
V_6 = V_17 ;
goto V_19;
}
if ( V_5 -> V_22 ) {
V_6 = V_5 -> V_22 ( V_9 ) ;
if ( V_6 )
goto V_19;
}
V_15 = F_8 ( V_9 , V_23 , 0 ) ;
if ( ! V_15 )
return - V_16 ;
V_11 -> V_24 = F_9 ( V_15 ) >> 10 ;
V_11 -> V_25 |= V_26 ;
V_6 = F_10 ( & V_13 , V_9 , V_11 ) ;
if ( V_6 )
goto V_27;
V_6 = F_11 ( V_17 , V_28 , V_29 ,
F_12 ( & V_9 -> V_2 ) , V_13 ) ;
if ( V_6 )
goto V_30;
F_13 ( L_1 , F_14 ( V_13 -> V_31 ) ,
( unsigned long ) V_13 -> V_32 , V_17 ) ;
return 0 ;
V_30:
F_15 ( V_13 ) ;
V_27:
if ( V_5 -> V_7 )
V_5 -> V_7 ( V_9 ) ;
V_19:
return V_6 ;
}
static int F_16 ( struct V_1 * V_9 )
{
const struct V_4 * V_5 = F_2 ( V_9 ) ;
struct V_33 * V_31 = F_17 ( V_9 ) ;
if ( V_31 ) {
struct V_12 * V_13 = F_18 ( V_31 ) ;
F_19 ( F_7 ( V_9 , 0 ) , V_13 ) ;
F_15 ( V_13 ) ;
if ( V_5 -> V_7 )
V_5 -> V_7 ( V_9 ) ;
}
return 0 ;
}
