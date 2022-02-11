static unsigned int F_1 ( struct V_1 * V_2 )
{
T_1 div ;
unsigned long V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
div = F_3 ( V_2 -> V_6 + V_7 ) ;
div = ( div & V_8 ) >> V_9 ;
V_3 = F_4 ( V_5 -> V_10 ) ;
V_3 /= 1 << ( V_11 + div ) ;
return V_3 ;
}
static int F_5 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_6 ( V_13 ) ;
struct V_1 * V_2 = F_7 ( V_15 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_16 * V_17 = V_5 -> V_18 ;
int V_19 ;
V_19 = F_8 ( V_2 ) ;
if ( V_19 )
return V_19 ;
F_9 ( V_5 -> V_10 ) ;
F_9 ( V_17 -> V_20 ) ;
return 0 ;
}
static int F_10 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_6 ( V_13 ) ;
struct V_1 * V_2 = F_7 ( V_15 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_16 * V_17 = V_5 -> V_18 ;
int V_19 ;
V_19 = F_11 ( V_17 -> V_20 ) ;
if ( V_19 ) {
F_12 ( V_13 , L_1 ) ;
return V_19 ;
}
V_19 = F_11 ( V_5 -> V_10 ) ;
if ( V_19 ) {
F_12 ( V_13 , L_2 ) ;
F_9 ( V_17 -> V_20 ) ;
return V_19 ;
}
return F_13 ( V_2 ) ;
}
static int F_14 ( struct V_14 * V_15 )
{
int V_19 ;
struct V_10 * V_21 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_16 * V_17 ;
V_17 = F_15 ( & V_15 -> V_13 , sizeof( * V_17 ) ,
V_22 ) ;
if ( ! V_17 )
return - V_23 ;
V_17 -> V_20 = F_16 ( & V_15 -> V_13 , L_3 ) ;
if ( F_17 ( V_17 -> V_20 ) ) {
F_12 ( & V_15 -> V_13 , L_4 ) ;
return F_18 ( V_17 -> V_20 ) ;
}
V_21 = F_16 ( & V_15 -> V_13 , L_5 ) ;
if ( F_17 ( V_21 ) ) {
F_12 ( & V_15 -> V_13 , L_6 ) ;
return F_18 ( V_21 ) ;
}
V_19 = F_19 ( V_17 -> V_20 ) ;
if ( V_19 ) {
F_12 ( & V_15 -> V_13 , L_7 ) ;
return V_19 ;
}
V_19 = F_19 ( V_21 ) ;
if ( V_19 ) {
F_12 ( & V_15 -> V_13 , L_8 ) ;
goto V_24;
}
V_2 = F_20 ( V_15 , & V_25 , 0 ) ;
if ( F_17 ( V_2 ) ) {
V_19 = F_18 ( V_2 ) ;
goto V_26;
}
F_21 ( V_15 ) ;
V_5 = F_2 ( V_2 ) ;
V_5 -> V_18 = V_17 ;
V_5 -> V_10 = V_21 ;
V_19 = F_22 ( V_2 ) ;
if ( V_19 )
goto V_27;
return 0 ;
V_27:
F_23 ( V_15 ) ;
V_26:
F_24 ( V_21 ) ;
V_24:
F_24 ( V_17 -> V_20 ) ;
return V_19 ;
}
static int F_25 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_16 * V_17 = V_5 -> V_18 ;
F_24 ( V_5 -> V_10 ) ;
F_24 ( V_17 -> V_20 ) ;
return F_26 ( V_15 ) ;
}
