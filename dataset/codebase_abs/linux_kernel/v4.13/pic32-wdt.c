static inline bool F_1 ( struct V_1 * V_2 )
{
return ! ! ( F_2 ( V_2 -> V_3 + V_4 ) & V_5 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 )
{
T_1 V_6 = F_2 ( V_2 -> V_3 + V_4 ) ;
return ( V_6 >> V_7 ) & V_8 ;
}
static inline T_1 F_4 ( struct V_1 * V_2 )
{
T_1 V_6 = F_2 ( V_2 -> V_3 + V_4 ) ;
return ( V_6 >> V_9 ) & V_10 ;
}
static int F_5 ( struct V_1 * V_2 )
{
T_1 V_6 = F_2 ( V_2 -> V_11 ) ;
F_6 ( V_12 , F_7 ( V_2 -> V_11 ) ) ;
return V_6 & V_12 ;
}
static T_1 F_8 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
unsigned long V_15 ;
T_1 V_16 , V_17 , V_18 ;
V_15 = F_9 ( V_2 -> V_19 ) ;
F_10 ( V_14 , L_1 ,
F_4 ( V_2 ) , V_15 ) ;
V_15 >>= 5 ;
if ( ! V_15 )
return 0 ;
V_17 = F_3 ( V_2 ) ;
V_18 = F_11 ( V_17 ) ;
V_16 = V_18 / V_15 ;
F_10 ( V_14 ,
L_2 ,
V_15 , V_18 , V_16 ) ;
return V_16 ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_13 ( V_20 , V_2 -> V_3 + V_4 + 2 ) ;
}
static int F_14 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_15 ( V_22 ) ;
F_6 ( V_23 , F_16 ( V_2 -> V_3 + V_4 ) ) ;
F_12 ( V_2 ) ;
return 0 ;
}
static int F_17 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_15 ( V_22 ) ;
F_6 ( V_23 , F_7 ( V_2 -> V_3 + V_4 ) ) ;
F_18 () ;
return 0 ;
}
static int F_19 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_15 ( V_22 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
static int F_20 ( struct V_24 * V_25 )
{
int V_26 ;
struct V_21 * V_22 = & V_27 ;
struct V_1 * V_2 ;
struct V_28 * V_29 ;
V_2 = F_21 ( & V_25 -> V_14 , sizeof( * V_2 ) , V_30 ) ;
if ( ! V_2 )
return - V_31 ;
V_29 = F_22 ( V_25 , V_32 , 0 ) ;
V_2 -> V_3 = F_23 ( & V_25 -> V_14 , V_29 ) ;
if ( F_24 ( V_2 -> V_3 ) )
return F_25 ( V_2 -> V_3 ) ;
V_2 -> V_11 = F_26 ( & V_25 -> V_14 , V_33 , 0x10 ) ;
if ( ! V_2 -> V_11 )
return - V_31 ;
V_2 -> V_19 = F_27 ( & V_25 -> V_14 , NULL ) ;
if ( F_24 ( V_2 -> V_19 ) ) {
F_28 ( & V_25 -> V_14 , L_3 ) ;
return F_25 ( V_2 -> V_19 ) ;
}
V_26 = F_29 ( V_2 -> V_19 ) ;
if ( V_26 ) {
F_28 ( & V_25 -> V_14 , L_4 ) ;
return V_26 ;
}
if ( F_1 ( V_2 ) ) {
F_28 ( & V_25 -> V_14 , L_5 ) ;
V_26 = - V_34 ;
goto V_35;
}
V_22 -> V_36 = F_8 ( V_2 , & V_25 -> V_14 ) ;
if ( ! V_22 -> V_36 ) {
F_28 ( & V_25 -> V_14 ,
L_6 ) ;
V_26 = - V_37 ;
goto V_35;
}
F_30 ( & V_25 -> V_14 , L_7 , V_22 -> V_36 ) ;
V_22 -> V_38 = F_5 ( V_2 ) ? V_39 : 0 ;
F_31 ( V_22 , V_40 ) ;
F_32 ( V_22 , V_2 ) ;
V_26 = F_33 ( V_22 ) ;
if ( V_26 ) {
F_28 ( & V_25 -> V_14 , L_8 , V_26 ) ;
goto V_35;
}
F_34 ( V_25 , V_22 ) ;
return 0 ;
V_35:
F_35 ( V_2 -> V_19 ) ;
return V_26 ;
}
static int F_36 ( struct V_24 * V_25 )
{
struct V_21 * V_22 = F_37 ( V_25 ) ;
struct V_1 * V_2 = F_15 ( V_22 ) ;
F_38 ( V_22 ) ;
F_35 ( V_2 -> V_19 ) ;
return 0 ;
}
