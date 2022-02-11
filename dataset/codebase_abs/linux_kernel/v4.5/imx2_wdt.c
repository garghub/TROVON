static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 = V_6 ;
F_3 ( V_4 -> V_7 , V_8 , V_5 ) ;
F_3 ( V_4 -> V_7 , V_8 , V_5 ) ;
F_3 ( V_4 -> V_7 , V_8 , V_5 ) ;
F_4 ( 500 ) ;
return 0 ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_9 ;
F_6 ( V_4 -> V_7 , V_8 , & V_9 ) ;
V_9 |= V_10 ;
V_9 &= ~ V_11 ;
V_9 &= ~ V_12 ;
V_9 &= ~ V_6 ;
V_9 |= F_7 ( V_2 -> V_13 ) ;
F_3 ( V_4 -> V_7 , V_8 , V_9 ) ;
V_9 |= V_6 ;
F_3 ( V_4 -> V_7 , V_8 , V_9 ) ;
}
static inline bool F_8 ( struct V_3 * V_4 )
{
T_1 V_9 ;
F_6 ( V_4 -> V_7 , V_8 , & V_9 ) ;
return V_9 & V_6 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_7 , V_14 , V_15 ) ;
F_3 ( V_4 -> V_7 , V_14 , V_16 ) ;
return 0 ;
}
static void F_10 ( unsigned long V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_9 ( V_2 ) ;
F_11 ( & V_4 -> V_18 , V_19 + V_2 -> V_13 * V_20 / 2 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned int V_21 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_2 -> V_13 = V_21 ;
F_13 ( V_4 -> V_7 , V_8 , V_11 ,
F_7 ( V_21 ) ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_8 ( V_4 ) ) {
F_15 ( & V_4 -> V_18 ) ;
F_12 ( V_2 , V_2 -> V_13 ) ;
} else
F_5 ( V_2 ) ;
return F_9 ( V_2 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
F_10 ( ( unsigned long ) V_2 ) ;
return 0 ;
}
static inline void F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_8 ( V_4 ) ) {
F_12 ( V_2 , V_2 -> V_13 ) ;
F_10 ( ( unsigned long ) V_2 ) ;
}
}
static int T_2 F_18 ( struct V_22 * V_23 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_24 * V_25 ;
void T_3 * V_26 ;
int V_27 ;
T_1 V_9 ;
V_4 = F_19 ( & V_23 -> V_28 , sizeof( * V_4 ) , V_29 ) ;
if ( ! V_4 )
return - V_30 ;
V_25 = F_20 ( V_23 , V_31 , 0 ) ;
V_26 = F_21 ( & V_23 -> V_28 , V_25 ) ;
if ( F_22 ( V_26 ) )
return F_23 ( V_26 ) ;
V_4 -> V_7 = F_24 ( & V_23 -> V_28 , NULL , V_26 ,
& V_32 ) ;
if ( F_22 ( V_4 -> V_7 ) ) {
F_25 ( & V_23 -> V_28 , L_1 ) ;
return F_23 ( V_4 -> V_7 ) ;
}
V_4 -> V_33 = F_26 ( & V_23 -> V_28 , NULL ) ;
if ( F_22 ( V_4 -> V_33 ) ) {
F_25 ( & V_23 -> V_28 , L_2 ) ;
return F_23 ( V_4 -> V_33 ) ;
}
V_2 = & V_4 -> V_2 ;
V_2 -> V_34 = & V_35 ;
V_2 -> V_36 = & V_37 ;
V_2 -> V_38 = 1 ;
V_2 -> V_39 = V_40 ;
V_2 -> V_41 = & V_23 -> V_28 ;
V_27 = F_27 ( V_4 -> V_33 ) ;
if ( V_27 )
return V_27 ;
F_6 ( V_4 -> V_7 , V_42 , & V_9 ) ;
V_2 -> V_43 = V_9 & V_44 ? V_45 : 0 ;
V_2 -> V_13 = F_28 ( unsigned , V_13 , 1 , V_40 ) ;
if ( V_2 -> V_13 != V_13 )
F_29 ( & V_23 -> V_28 , L_3 ,
V_13 , V_2 -> V_13 ) ;
F_30 ( V_23 , V_2 ) ;
F_31 ( V_2 , V_4 ) ;
F_32 ( V_2 , V_46 ) ;
F_33 ( V_2 , 128 ) ;
F_34 ( V_2 , V_13 , & V_23 -> V_28 ) ;
F_35 ( & V_4 -> V_18 , F_10 , ( unsigned long ) V_2 ) ;
F_17 ( V_2 ) ;
F_3 ( V_4 -> V_7 , V_47 , 0 ) ;
V_27 = F_36 ( V_2 ) ;
if ( V_27 ) {
F_25 ( & V_23 -> V_28 , L_4 ) ;
goto V_48;
}
F_37 ( & V_23 -> V_28 , L_5 ,
V_2 -> V_13 , V_46 ) ;
return 0 ;
V_48:
F_38 ( V_4 -> V_33 ) ;
return V_27 ;
}
static int T_4 F_39 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_40 ( V_23 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_41 ( V_2 ) ;
if ( F_8 ( V_4 ) ) {
F_15 ( & V_4 -> V_18 ) ;
F_9 ( V_2 ) ;
F_42 ( & V_23 -> V_28 , L_6 ) ;
}
return 0 ;
}
static void F_43 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_40 ( V_23 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_8 ( V_4 ) ) {
F_15 ( & V_4 -> V_18 ) ;
F_12 ( V_2 , V_40 ) ;
F_9 ( V_2 ) ;
F_42 ( & V_23 -> V_28 , L_7 ) ;
}
}
static int F_44 ( struct V_49 * V_28 )
{
struct V_1 * V_2 = F_45 ( V_28 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_8 ( V_4 ) ) {
F_12 ( V_2 , V_40 ) ;
F_9 ( V_2 ) ;
if ( ! F_46 ( V_2 ) )
F_15 ( & V_4 -> V_18 ) ;
}
F_38 ( V_4 -> V_33 ) ;
return 0 ;
}
static int F_47 ( struct V_49 * V_28 )
{
struct V_1 * V_2 = F_45 ( V_28 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_27 ;
V_27 = F_27 ( V_4 -> V_33 ) ;
if ( V_27 )
return V_27 ;
if ( F_46 ( V_2 ) && ! F_8 ( V_4 ) ) {
F_5 ( V_2 ) ;
F_12 ( V_2 , V_2 -> V_13 ) ;
F_9 ( V_2 ) ;
} else if ( F_8 ( V_4 ) ) {
F_12 ( V_2 , V_2 -> V_13 ) ;
F_9 ( V_2 ) ;
if ( ! F_46 ( V_2 ) )
F_11 ( & V_4 -> V_18 ,
V_19 + V_2 -> V_13 * V_20 / 2 ) ;
}
return 0 ;
}
