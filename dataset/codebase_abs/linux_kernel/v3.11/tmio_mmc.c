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
int V_6 = - V_14 , V_15 ;
if ( V_9 -> V_16 != 2 )
goto V_17;
V_11 = V_9 -> V_2 . V_18 ;
if ( ! V_11 || ! V_11 -> V_19 )
goto V_17;
V_15 = F_7 ( V_9 , 0 ) ;
if ( V_15 < 0 ) {
V_6 = V_15 ;
goto V_17;
}
if ( V_5 -> V_20 ) {
V_6 = V_5 -> V_20 ( V_9 ) ;
if ( V_6 )
goto V_17;
}
V_6 = F_8 ( & V_13 , V_9 , V_11 ) ;
if ( V_6 )
goto V_21;
V_6 = F_9 ( V_15 , V_22 , V_23 ,
F_10 ( & V_9 -> V_2 ) , V_13 ) ;
if ( V_6 )
goto V_24;
F_11 ( L_1 , F_12 ( V_13 -> V_25 ) ,
( unsigned long ) V_13 -> V_26 , V_15 ) ;
return 0 ;
V_24:
F_13 ( V_13 ) ;
V_21:
if ( V_5 -> V_7 )
V_5 -> V_7 ( V_9 ) ;
V_17:
return V_6 ;
}
static int F_14 ( struct V_1 * V_9 )
{
const struct V_4 * V_5 = F_2 ( V_9 ) ;
struct V_27 * V_25 = F_15 ( V_9 ) ;
if ( V_25 ) {
struct V_12 * V_13 = F_16 ( V_25 ) ;
F_17 ( F_7 ( V_9 , 0 ) , V_13 ) ;
F_13 ( V_13 ) ;
if ( V_5 -> V_7 )
V_5 -> V_7 ( V_9 ) ;
}
return 0 ;
}
