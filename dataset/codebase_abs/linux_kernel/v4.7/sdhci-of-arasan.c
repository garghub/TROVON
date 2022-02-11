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
static void F_5 ( struct V_1 * V_2 , unsigned int clock )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_6 ( V_5 ) ;
bool V_14 = false ;
if ( clock > V_15 && ( ! F_7 ( V_13 -> V_16 ) ) )
V_14 = true ;
if ( V_14 ) {
F_8 ( & V_2 -> V_17 ) ;
F_9 ( V_13 -> V_16 ) ;
F_10 ( & V_2 -> V_17 ) ;
}
F_11 ( V_2 , clock ) ;
if ( V_14 ) {
F_8 ( & V_2 -> V_17 ) ;
F_12 ( V_13 -> V_16 ) ;
F_10 ( & V_2 -> V_17 ) ;
}
}
static int F_13 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = F_14 ( V_19 ) ;
struct V_1 * V_2 = F_15 ( V_21 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_6 ( V_5 ) ;
int V_22 ;
V_22 = F_16 ( V_2 ) ;
if ( V_22 )
return V_22 ;
if ( ! F_7 ( V_13 -> V_16 ) ) {
V_22 = F_9 ( V_13 -> V_16 ) ;
if ( V_22 ) {
F_17 ( V_19 , L_1 ) ;
F_18 ( V_2 ) ;
return V_22 ;
}
}
F_19 ( V_5 -> V_10 ) ;
F_19 ( V_13 -> V_23 ) ;
return 0 ;
}
static int F_20 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = F_14 ( V_19 ) ;
struct V_1 * V_2 = F_15 ( V_21 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_6 ( V_5 ) ;
int V_22 ;
V_22 = F_21 ( V_13 -> V_23 ) ;
if ( V_22 ) {
F_17 ( V_19 , L_2 ) ;
return V_22 ;
}
V_22 = F_21 ( V_5 -> V_10 ) ;
if ( V_22 ) {
F_17 ( V_19 , L_3 ) ;
return V_22 ;
}
if ( ! F_7 ( V_13 -> V_16 ) ) {
V_22 = F_12 ( V_13 -> V_16 ) ;
if ( V_22 ) {
F_17 ( V_19 , L_4 ) ;
return V_22 ;
}
}
return F_18 ( V_2 ) ;
}
static int F_22 ( struct V_20 * V_21 )
{
int V_22 ;
struct V_10 * V_24 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_12 * V_13 ;
V_2 = F_23 ( V_21 , & V_25 ,
sizeof( * V_13 ) ) ;
if ( F_7 ( V_2 ) )
return F_24 ( V_2 ) ;
V_5 = F_2 ( V_2 ) ;
V_13 = F_6 ( V_5 ) ;
V_13 -> V_23 = F_25 ( & V_21 -> V_19 , L_5 ) ;
if ( F_7 ( V_13 -> V_23 ) ) {
F_17 ( & V_21 -> V_19 , L_6 ) ;
V_22 = F_24 ( V_13 -> V_23 ) ;
goto V_26;
}
V_24 = F_25 ( & V_21 -> V_19 , L_7 ) ;
if ( F_7 ( V_24 ) ) {
F_17 ( & V_21 -> V_19 , L_8 ) ;
V_22 = F_24 ( V_24 ) ;
goto V_26;
}
V_22 = F_26 ( V_13 -> V_23 ) ;
if ( V_22 ) {
F_17 ( & V_21 -> V_19 , L_9 ) ;
goto V_26;
}
V_22 = F_26 ( V_24 ) ;
if ( V_22 ) {
F_17 ( & V_21 -> V_19 , L_10 ) ;
goto V_27;
}
F_27 ( V_21 ) ;
V_5 -> V_10 = V_24 ;
V_22 = F_28 ( V_2 -> V_28 ) ;
if ( V_22 ) {
F_17 ( & V_21 -> V_19 , L_11 , V_22 ) ;
goto V_29;
}
V_13 -> V_16 = F_29 ( - V_30 ) ;
if ( F_30 ( V_21 -> V_19 . V_31 ,
L_12 ) ) {
V_13 -> V_16 = F_31 ( & V_21 -> V_19 ,
L_13 ) ;
if ( F_7 ( V_13 -> V_16 ) ) {
V_22 = F_24 ( V_13 -> V_16 ) ;
F_17 ( & V_21 -> V_19 , L_14 ) ;
goto V_29;
}
V_22 = F_32 ( V_13 -> V_16 ) ;
if ( V_22 < 0 ) {
F_17 ( & V_21 -> V_19 , L_15 ) ;
goto V_29;
}
V_22 = F_12 ( V_13 -> V_16 ) ;
if ( V_22 < 0 ) {
F_17 ( & V_21 -> V_19 , L_16 ) ;
goto V_32;
}
}
V_22 = F_33 ( V_2 ) ;
if ( V_22 )
goto V_33;
return 0 ;
V_33:
if ( ! F_7 ( V_13 -> V_16 ) )
F_9 ( V_13 -> V_16 ) ;
V_32:
if ( ! F_7 ( V_13 -> V_16 ) )
F_34 ( V_13 -> V_16 ) ;
V_29:
F_35 ( V_24 ) ;
V_27:
F_35 ( V_13 -> V_23 ) ;
V_26:
F_36 ( V_21 ) ;
return V_22 ;
}
static int F_37 ( struct V_20 * V_21 )
{
int V_22 ;
struct V_1 * V_2 = F_15 ( V_21 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_6 ( V_5 ) ;
struct V_10 * V_23 = V_13 -> V_23 ;
if ( ! F_7 ( V_13 -> V_16 ) ) {
F_9 ( V_13 -> V_16 ) ;
F_34 ( V_13 -> V_16 ) ;
}
V_22 = F_38 ( V_21 ) ;
F_35 ( V_23 ) ;
return V_22 ;
}
