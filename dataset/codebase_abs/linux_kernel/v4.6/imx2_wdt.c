static int F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
void * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 = V_8 ;
F_3 ( V_6 -> V_9 , V_10 , V_7 ) ;
F_3 ( V_6 -> V_9 , V_10 , V_7 ) ;
F_3 ( V_6 -> V_9 , V_10 , V_7 ) ;
F_4 ( 500 ) ;
return 0 ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_11 ;
F_6 ( V_6 -> V_9 , V_10 , & V_11 ) ;
V_11 |= V_12 ;
V_11 &= ~ V_13 ;
V_11 &= ~ V_14 ;
V_11 &= ~ V_8 ;
V_11 |= F_7 ( V_2 -> V_15 ) ;
F_3 ( V_6 -> V_9 , V_10 , V_11 ) ;
V_11 |= V_8 ;
F_3 ( V_6 -> V_9 , V_10 , V_11 ) ;
}
static inline bool F_8 ( struct V_5 * V_6 )
{
T_1 V_11 ;
F_6 ( V_6 -> V_9 , V_10 , & V_11 ) ;
return V_11 & V_8 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_6 -> V_9 , V_16 , V_17 ) ;
F_3 ( V_6 -> V_9 , V_16 , V_18 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned int V_19 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_2 -> V_15 = V_19 ;
F_11 ( V_6 -> V_9 , V_10 , V_13 ,
F_7 ( V_19 ) ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_8 ( V_6 ) )
F_10 ( V_2 , V_2 -> V_15 ) ;
else
F_5 ( V_2 ) ;
F_13 ( V_20 , & V_2 -> V_21 ) ;
return F_9 ( V_2 ) ;
}
static int T_2 F_14 ( struct V_22 * V_23 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
struct V_24 * V_25 ;
void T_3 * V_26 ;
int V_27 ;
T_1 V_11 ;
V_6 = F_15 ( & V_23 -> V_28 , sizeof( * V_6 ) , V_29 ) ;
if ( ! V_6 )
return - V_30 ;
V_25 = F_16 ( V_23 , V_31 , 0 ) ;
V_26 = F_17 ( & V_23 -> V_28 , V_25 ) ;
if ( F_18 ( V_26 ) )
return F_19 ( V_26 ) ;
V_6 -> V_9 = F_20 ( & V_23 -> V_28 , NULL , V_26 ,
& V_32 ) ;
if ( F_18 ( V_6 -> V_9 ) ) {
F_21 ( & V_23 -> V_28 , L_1 ) ;
return F_19 ( V_6 -> V_9 ) ;
}
V_6 -> V_33 = F_22 ( & V_23 -> V_28 , NULL ) ;
if ( F_18 ( V_6 -> V_33 ) ) {
F_21 ( & V_23 -> V_28 , L_2 ) ;
return F_19 ( V_6 -> V_33 ) ;
}
V_2 = & V_6 -> V_2 ;
V_2 -> V_34 = & V_35 ;
V_2 -> V_36 = & V_37 ;
V_2 -> V_38 = 1 ;
V_2 -> V_39 = V_40 * 1000 ;
V_2 -> V_41 = & V_23 -> V_28 ;
V_27 = F_23 ( V_6 -> V_33 ) ;
if ( V_27 )
return V_27 ;
F_6 ( V_6 -> V_9 , V_42 , & V_11 ) ;
V_2 -> V_43 = V_11 & V_44 ? V_45 : 0 ;
V_2 -> V_15 = F_24 ( unsigned , V_15 , 1 , V_40 ) ;
if ( V_2 -> V_15 != V_15 )
F_25 ( & V_23 -> V_28 , L_3 ,
V_15 , V_2 -> V_15 ) ;
F_26 ( V_23 , V_2 ) ;
F_27 ( V_2 , V_6 ) ;
F_28 ( V_2 , V_46 ) ;
F_29 ( V_2 , 128 ) ;
F_30 ( V_2 , V_15 , & V_23 -> V_28 ) ;
if ( F_8 ( V_6 ) ) {
F_10 ( V_2 , V_2 -> V_15 ) ;
F_13 ( V_20 , & V_2 -> V_21 ) ;
}
F_3 ( V_6 -> V_9 , V_47 , 0 ) ;
V_27 = F_31 ( V_2 ) ;
if ( V_27 ) {
F_21 ( & V_23 -> V_28 , L_4 ) ;
goto V_48;
}
F_32 ( & V_23 -> V_28 , L_5 ,
V_2 -> V_15 , V_46 ) ;
return 0 ;
V_48:
F_33 ( V_6 -> V_33 ) ;
return V_27 ;
}
static int T_4 F_34 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_35 ( V_23 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_36 ( V_2 ) ;
if ( F_8 ( V_6 ) ) {
F_9 ( V_2 ) ;
F_37 ( & V_23 -> V_28 , L_6 ) ;
}
return 0 ;
}
static void F_38 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_35 ( V_23 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_8 ( V_6 ) ) {
F_10 ( V_2 , V_40 ) ;
F_9 ( V_2 ) ;
F_37 ( & V_23 -> V_28 , L_7 ) ;
}
}
static int F_39 ( struct V_49 * V_28 )
{
struct V_1 * V_2 = F_40 ( V_28 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_8 ( V_6 ) ) {
F_10 ( V_2 , V_40 ) ;
F_9 ( V_2 ) ;
}
F_33 ( V_6 -> V_33 ) ;
return 0 ;
}
static int F_41 ( struct V_49 * V_28 )
{
struct V_1 * V_2 = F_40 ( V_28 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_27 ;
V_27 = F_23 ( V_6 -> V_33 ) ;
if ( V_27 )
return V_27 ;
if ( F_42 ( V_2 ) && ! F_8 ( V_6 ) ) {
F_5 ( V_2 ) ;
}
if ( F_8 ( V_6 ) ) {
F_10 ( V_2 , V_2 -> V_15 ) ;
F_9 ( V_2 ) ;
}
return 0 ;
}
