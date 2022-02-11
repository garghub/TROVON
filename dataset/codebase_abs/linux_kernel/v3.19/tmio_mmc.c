static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_7 ;
V_7 = F_4 ( V_2 ) ;
if ( ! V_7 && V_6 -> V_8 )
V_6 -> V_8 ( V_4 ) ;
return V_7 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_7 = 0 ;
if ( V_6 -> V_9 )
V_7 = V_6 -> V_9 ( V_4 ) ;
if ( ! V_7 )
V_7 = F_6 ( V_2 ) ;
return V_7 ;
}
static int F_7 ( struct V_3 * V_4 )
{
const struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_7 = - V_16 , V_17 ;
if ( V_4 -> V_18 != 2 )
goto V_19;
V_11 = V_4 -> V_2 . V_20 ;
if ( ! V_11 || ! V_11 -> V_21 )
goto V_19;
V_17 = F_8 ( V_4 , 0 ) ;
if ( V_17 < 0 ) {
V_7 = V_17 ;
goto V_19;
}
if ( V_6 -> V_22 ) {
V_7 = V_6 -> V_22 ( V_4 ) ;
if ( V_7 )
goto V_19;
}
V_15 = F_9 ( V_4 , V_23 , 0 ) ;
if ( ! V_15 )
return - V_16 ;
V_11 -> V_24 = F_10 ( V_15 ) >> 10 ;
V_11 -> V_25 |= V_26 ;
V_7 = F_11 ( & V_13 , V_4 , V_11 ) ;
if ( V_7 )
goto V_27;
V_7 = F_12 ( V_17 , V_28 , V_29 ,
F_13 ( & V_4 -> V_2 ) , V_13 ) ;
if ( V_7 )
goto V_30;
F_14 ( L_1 , F_15 ( V_13 -> V_31 ) ,
( unsigned long ) V_13 -> V_32 , V_17 ) ;
return 0 ;
V_30:
F_16 ( V_13 ) ;
V_27:
if ( V_6 -> V_8 )
V_6 -> V_8 ( V_4 ) ;
V_19:
return V_7 ;
}
static int F_17 ( struct V_3 * V_4 )
{
const struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_33 * V_31 = F_18 ( V_4 ) ;
if ( V_31 ) {
struct V_12 * V_13 = F_19 ( V_31 ) ;
F_20 ( F_8 ( V_4 , 0 ) , V_13 ) ;
F_16 ( V_13 ) ;
if ( V_6 -> V_8 )
V_6 -> V_8 ( V_4 ) ;
}
return 0 ;
}
