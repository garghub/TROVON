static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 -> V_5 , V_6 , 1 ) ;
F_3 ( V_4 -> V_5 ) ;
return V_7 ;
}
static T_1 F_4 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 -> V_5 , V_6 , 0 ) ;
F_3 ( V_4 -> V_5 ) ;
return V_7 ;
}
static int F_5 ( struct V_8 * V_9 )
{
struct V_3 * V_4 = F_6 ( V_9 ) ;
if ( F_7 ( V_9 ) )
F_8 ( V_4 -> V_10 ) ;
return 0 ;
}
static int F_9 ( struct V_8 * V_9 )
{
struct V_3 * V_4 = F_6 ( V_9 ) ;
if ( F_7 ( V_9 ) )
F_10 ( V_4 -> V_10 ) ;
return 0 ;
}
static int T_2 F_11 ( struct V_11 * V_12 )
{
struct V_13 * V_5 ;
int V_14 = F_12 ( V_12 , 0 ) ;
int V_10 = F_12 ( V_12 , 1 ) ;
int V_15 ;
unsigned int V_16 ;
T_3 V_17 ;
struct V_3 * V_4 ;
const struct V_18 * V_19 =
F_13 ( & V_12 -> V_9 ) ;
if ( ! V_19 ) {
F_14 ( & V_12 -> V_9 , L_1 ) ;
return - V_20 ;
}
if ( V_19 -> V_21 > 62500 ) {
F_14 ( & V_12 -> V_9 , L_2 ) ;
return - V_20 ;
}
V_4 = F_15 ( sizeof( * V_4 ) , V_22 ) ;
if ( ! V_4 )
return - V_23 ;
V_5 = F_16 () ;
if ( ! V_5 ) {
F_17 ( & V_12 -> V_9 , L_3 ) ;
V_15 = - V_23 ;
goto V_24;
}
F_18 ( V_5 , V_25 , V_6 ) ;
V_5 -> V_26 = L_4 ;
V_5 -> V_27 = L_5 ;
V_5 -> V_9 . V_28 = & V_12 -> V_9 ;
V_16 = ( V_19 -> V_21 << 10 ) / V_29 ;
V_16 = 1 + F_19 ( V_16 ) ;
V_15 = F_20 ( V_12 -> V_9 . V_28 , V_30 , & V_17 ) ;
if ( V_15 < 0 ) {
F_14 ( & V_12 -> V_9 , L_6 , V_15 ) ;
goto V_31;
}
V_17 &= ~ V_32 ;
V_17 |= ( V_16 & V_32 ) ;
if ( V_19 -> V_33 )
V_17 |= V_34 ;
else
V_17 &= ~ V_34 ;
V_15 = F_21 ( V_12 -> V_9 . V_28 , V_30 , V_17 ) ;
if ( V_15 < 0 ) {
F_14 ( & V_12 -> V_9 , L_7 , V_15 ) ;
goto V_31;
}
V_15 = F_22 ( V_5 ) ;
if ( V_15 ) {
F_17 ( & V_12 -> V_9 , L_8 , V_15 ) ;
goto V_31;
}
V_4 -> V_10 = V_10 ;
V_4 -> V_5 = V_5 ;
F_23 ( V_12 , V_4 ) ;
V_15 = F_24 ( V_10 , F_1 ,
V_35 , L_9 , V_4 ) ;
if ( V_15 < 0 ) {
F_17 ( & V_12 -> V_9 , L_10 ,
V_10 , V_15 ) ;
goto V_36;
}
V_15 = F_24 ( V_14 , F_4 ,
V_35 , L_11 , V_4 ) ;
if ( V_15 < 0 ) {
F_17 ( & V_12 -> V_9 , L_10 ,
V_14 , V_15 ) ;
goto V_37;
}
F_25 ( & V_12 -> V_9 , V_19 -> V_38 ) ;
return 0 ;
V_37:
F_26 ( V_10 , NULL ) ;
V_36:
F_23 ( V_12 , NULL ) ;
F_27 ( V_5 ) ;
V_5 = NULL ;
V_31:
F_28 ( V_5 ) ;
V_24:
F_29 ( V_4 ) ;
return V_15 ;
}
static int T_4 F_30 ( struct V_11 * V_12 )
{
struct V_3 * V_4 = F_31 ( V_12 ) ;
int V_14 = F_12 ( V_12 , 0 ) ;
int V_10 = F_12 ( V_12 , 1 ) ;
F_25 ( & V_12 -> V_9 , 0 ) ;
F_26 ( V_10 , V_4 ) ;
F_26 ( V_14 , V_4 ) ;
F_27 ( V_4 -> V_5 ) ;
F_23 ( V_12 , NULL ) ;
F_29 ( V_4 ) ;
return 0 ;
}
static int T_5 F_32 ( void )
{
return F_33 ( & V_39 ) ;
}
static void T_6 F_34 ( void )
{
F_35 ( & V_39 ) ;
}
