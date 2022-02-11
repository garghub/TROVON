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
struct V_16 * V_17 = F_8 ( V_5 ) ;
int V_18 ;
V_18 = F_9 ( V_2 ) ;
if ( V_18 )
return V_18 ;
if ( ! F_10 ( V_17 -> V_19 ) ) {
V_18 = F_11 ( V_17 -> V_19 ) ;
if ( V_18 ) {
F_12 ( V_13 , L_1 ) ;
F_13 ( V_2 ) ;
return V_18 ;
}
}
F_14 ( V_5 -> V_10 ) ;
F_14 ( V_17 -> V_20 ) ;
return 0 ;
}
static int F_15 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_6 ( V_13 ) ;
struct V_1 * V_2 = F_7 ( V_15 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_16 * V_17 = F_8 ( V_5 ) ;
int V_18 ;
V_18 = F_16 ( V_17 -> V_20 ) ;
if ( V_18 ) {
F_12 ( V_13 , L_2 ) ;
return V_18 ;
}
V_18 = F_16 ( V_5 -> V_10 ) ;
if ( V_18 ) {
F_12 ( V_13 , L_3 ) ;
return V_18 ;
}
if ( ! F_10 ( V_17 -> V_19 ) ) {
V_18 = F_17 ( V_17 -> V_19 ) ;
if ( V_18 ) {
F_12 ( V_13 , L_4 ) ;
return V_18 ;
}
}
return F_13 ( V_2 ) ;
}
static int F_18 ( struct V_14 * V_15 )
{
int V_18 ;
struct V_10 * V_21 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_16 * V_17 ;
V_2 = F_19 ( V_15 , & V_22 ,
sizeof( * V_17 ) ) ;
if ( F_10 ( V_2 ) )
return F_20 ( V_2 ) ;
V_5 = F_2 ( V_2 ) ;
V_17 = F_8 ( V_5 ) ;
V_17 -> V_20 = F_21 ( & V_15 -> V_13 , L_5 ) ;
if ( F_10 ( V_17 -> V_20 ) ) {
F_12 ( & V_15 -> V_13 , L_6 ) ;
V_18 = F_20 ( V_17 -> V_20 ) ;
goto V_23;
}
V_21 = F_21 ( & V_15 -> V_13 , L_7 ) ;
if ( F_10 ( V_21 ) ) {
F_12 ( & V_15 -> V_13 , L_8 ) ;
V_18 = F_20 ( V_21 ) ;
goto V_23;
}
V_18 = F_22 ( V_17 -> V_20 ) ;
if ( V_18 ) {
F_12 ( & V_15 -> V_13 , L_9 ) ;
goto V_23;
}
V_18 = F_22 ( V_21 ) ;
if ( V_18 ) {
F_12 ( & V_15 -> V_13 , L_10 ) ;
goto V_24;
}
F_23 ( V_15 ) ;
V_5 -> V_10 = V_21 ;
V_18 = F_24 ( V_2 -> V_25 ) ;
if ( V_18 ) {
F_12 ( & V_15 -> V_13 , L_11 , V_18 ) ;
goto V_26;
}
V_17 -> V_19 = F_25 ( - V_27 ) ;
if ( F_26 ( V_15 -> V_13 . V_28 ,
L_12 ) ) {
V_17 -> V_19 = F_27 ( & V_15 -> V_13 ,
L_13 ) ;
if ( F_10 ( V_17 -> V_19 ) ) {
V_18 = F_20 ( V_17 -> V_19 ) ;
F_12 ( & V_15 -> V_13 , L_14 ) ;
goto V_26;
}
V_18 = F_28 ( V_17 -> V_19 ) ;
if ( V_18 < 0 ) {
F_12 ( & V_15 -> V_13 , L_15 ) ;
goto V_26;
}
V_18 = F_17 ( V_17 -> V_19 ) ;
if ( V_18 < 0 ) {
F_12 ( & V_15 -> V_13 , L_16 ) ;
goto V_29;
}
}
V_18 = F_29 ( V_2 ) ;
if ( V_18 )
goto V_30;
return 0 ;
V_30:
if ( ! F_10 ( V_17 -> V_19 ) )
F_11 ( V_17 -> V_19 ) ;
V_29:
if ( ! F_10 ( V_17 -> V_19 ) )
F_30 ( V_17 -> V_19 ) ;
V_26:
F_31 ( V_21 ) ;
V_24:
F_31 ( V_17 -> V_20 ) ;
V_23:
F_32 ( V_15 ) ;
return V_18 ;
}
static int F_33 ( struct V_14 * V_15 )
{
int V_18 ;
struct V_1 * V_2 = F_7 ( V_15 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_16 * V_17 = F_8 ( V_5 ) ;
struct V_10 * V_20 = V_17 -> V_20 ;
if ( ! F_10 ( V_17 -> V_19 ) ) {
F_11 ( V_17 -> V_19 ) ;
F_30 ( V_17 -> V_19 ) ;
}
V_18 = F_34 ( V_15 ) ;
F_31 ( V_20 ) ;
return V_18 ;
}
