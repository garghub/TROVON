static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = (struct V_3 * ) V_2 ;
F_2 ( V_3 , 0 ) ;
F_2 ( V_3 , 1 ) ;
return V_4 ;
}
static T_1 F_3 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = (struct V_3 * ) V_2 ;
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
T_2 V_8 ;
V_8 = F_4 ( V_6 -> V_8 ) ;
if ( V_8 & V_9 ) {
F_5 ( V_9 , V_6 -> V_8 + 4 ) ;
V_6 -> V_10 ( V_6 -> V_11 ) ;
return V_12 ;
}
return V_4 ;
}
static int F_6 ( struct V_3 * V_3 )
{
struct V_13 * V_14 = V_3 -> V_14 . V_15 ;
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_16 * V_17 = V_6 -> V_17 ;
if ( V_3 -> V_18 & 0x3ff ) {
F_7 ( V_14 , L_1 ) ;
return - V_19 ;
}
F_5 ( V_3 -> V_18 , V_6 -> V_20 ) ;
F_8 ( V_17 ) ;
F_9 ( V_17 ) ;
return 0 ;
}
static int F_10 ( struct V_3 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_7 ;
F_11 ( V_6 -> V_17 ) ;
return 0 ;
}
static void F_12 ( struct V_3 * V_3 , int V_21 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
F_5 ( V_22 , V_6 -> V_8 ) ;
}
static int F_13 ( struct V_13 * V_14 )
{
struct V_16 * V_17 ;
V_17 = F_14 ( V_14 , NULL ) ;
if ( F_15 ( V_17 ) ) {
F_7 ( V_14 , L_2 , F_16 ( V_17 ) ) ;
return F_16 ( V_17 ) ;
}
F_17 ( V_17 ) ;
F_18 ( V_17 ) ;
return 0 ;
}
static int F_19 ( struct V_23 * V_24 )
{
struct V_13 * V_14 = & V_24 -> V_14 ;
struct V_5 * V_6 ;
struct V_3 * V_3 ;
struct V_11 * V_11 ;
struct V_25 * V_26 ;
struct V_25 * V_27 ;
struct V_16 * V_17 ;
void T_3 * V_8 ;
void T_3 * V_20 ;
int V_1 ;
int V_28 ;
V_1 = F_20 ( V_24 , 0 ) ;
if ( V_1 < 0 ) {
F_7 ( V_14 , L_3 , V_1 ) ;
return V_1 ;
}
V_11 = F_21 ( V_1 ) ;
if ( ! V_11 ) {
F_7 ( V_14 , L_4 , V_1 ) ;
return - V_19 ;
}
V_26 = F_22 ( V_24 , V_29 , 0 ) ;
V_20 = F_23 ( V_14 , V_26 ) ;
if ( F_15 ( V_20 ) )
return F_16 ( V_20 ) ;
V_27 = F_22 ( V_24 , V_29 , 1 ) ;
V_8 = F_23 ( V_14 , V_27 ) ;
if ( F_15 ( V_8 ) )
return F_16 ( V_8 ) ;
V_17 = F_24 ( V_14 , NULL ) ;
if ( F_15 ( V_17 ) ) {
F_7 ( V_14 , L_2 , F_16 ( V_17 ) ) ;
return F_16 ( V_17 ) ;
}
V_3 = F_25 ( V_14 , L_5 , & V_30 , V_31 ,
sizeof( * V_6 ) ) ;
if ( ! V_3 )
return - V_32 ;
V_6 = V_3 -> V_7 ;
V_6 -> V_3 = V_3 ;
F_26 ( V_24 , V_3 ) ;
V_28 = F_27 ( V_14 , V_1 , F_3 ,
F_1 , 0 , L_6 ,
V_3 ) ;
if ( V_28 ) {
F_7 ( V_14 , L_7 , V_28 ) ;
goto V_33;
}
V_28 = F_13 ( V_14 ) ;
if ( V_28 )
goto V_33;
V_6 -> V_8 = V_8 ;
V_6 -> V_20 = V_20 ;
V_6 -> V_10 = V_11 -> V_34 -> V_35 ;
V_6 -> V_11 = V_11 ;
V_6 -> V_1 = V_1 ;
V_6 -> V_17 = V_17 ;
V_28 = F_28 ( V_3 ) ;
if ( V_28 ) {
F_7 ( V_14 , L_8 , V_28 ) ;
goto V_33;
}
return 0 ;
V_33:
F_29 ( V_3 ) ;
return V_28 ;
}
static int F_30 ( struct V_23 * V_24 )
{
struct V_13 * V_14 = & V_24 -> V_14 ;
struct V_3 * V_3 = F_31 ( V_24 ) ;
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
F_13 ( V_14 ) ;
F_32 ( V_6 -> V_1 ) ;
F_33 ( V_3 ) ;
F_29 ( V_3 ) ;
return 0 ;
}
