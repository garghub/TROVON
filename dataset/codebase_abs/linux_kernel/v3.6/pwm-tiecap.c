static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , struct V_4 * V_5 ,
int V_6 , int V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
unsigned long long V_9 ;
unsigned long V_10 , V_11 ;
unsigned int V_12 ;
if ( V_7 < 0 || V_6 < 0 || V_7 > V_13 )
return - V_14 ;
V_9 = V_8 -> V_15 ;
V_9 = V_9 * V_7 ;
F_4 ( V_9 , V_13 ) ;
V_10 = ( unsigned long ) V_9 ;
if ( V_10 < 1 ) {
V_10 = 1 ;
V_11 = 1 ;
} else {
V_9 = V_8 -> V_15 ;
V_9 = V_9 * V_6 ;
F_4 ( V_9 , V_13 ) ;
V_11 = ( unsigned long ) V_9 ;
}
F_5 ( V_8 -> V_3 . V_16 ) ;
V_12 = F_6 ( V_8 -> V_17 + V_18 ) ;
V_12 |= V_19 | V_20 ;
F_7 ( V_12 , V_8 -> V_17 + V_18 ) ;
if ( ! F_8 ( V_21 , & V_5 -> V_22 ) ) {
F_9 ( V_11 , V_8 -> V_17 + V_23 ) ;
F_9 ( V_10 , V_8 -> V_17 + V_24 ) ;
} else {
F_9 ( V_11 , V_8 -> V_17 + V_25 ) ;
F_9 ( V_10 , V_8 -> V_17 + V_26 ) ;
}
if ( ! F_8 ( V_21 , & V_5 -> V_22 ) ) {
V_12 = F_6 ( V_8 -> V_17 + V_18 ) ;
V_12 &= ~ V_19 ;
F_7 ( V_12 , V_8 -> V_17 + V_18 ) ;
}
F_10 ( V_8 -> V_3 . V_16 ) ;
return 0 ;
}
static int F_11 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
unsigned int V_12 ;
F_5 ( V_8 -> V_3 . V_16 ) ;
V_12 = F_6 ( V_8 -> V_17 + V_18 ) ;
V_12 |= V_27 | V_19 ;
F_7 ( V_12 , V_8 -> V_17 + V_18 ) ;
return 0 ;
}
static void F_12 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
unsigned int V_12 ;
V_12 = F_6 ( V_8 -> V_17 + V_18 ) ;
V_12 &= ~ ( V_27 | V_19 ) ;
F_7 ( V_12 , V_8 -> V_17 + V_18 ) ;
F_10 ( V_8 -> V_3 . V_16 ) ;
}
static void F_13 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
if ( F_8 ( V_21 , & V_5 -> V_22 ) ) {
F_14 ( V_3 -> V_16 , L_1 ) ;
F_10 ( V_3 -> V_16 ) ;
}
}
static int T_1 F_15 ( struct V_28 * V_29 )
{
int V_30 ;
struct V_31 * V_32 ;
struct V_33 * V_33 ;
struct V_1 * V_8 ;
V_8 = F_16 ( & V_29 -> V_16 , sizeof( * V_8 ) , V_34 ) ;
if ( ! V_8 ) {
F_17 ( & V_29 -> V_16 , L_2 ) ;
return - V_35 ;
}
V_33 = F_18 ( & V_29 -> V_16 , L_3 ) ;
if ( F_19 ( V_33 ) ) {
F_17 ( & V_29 -> V_16 , L_4 ) ;
return F_20 ( V_33 ) ;
}
V_8 -> V_15 = F_21 ( V_33 ) ;
if ( ! V_8 -> V_15 ) {
F_17 ( & V_29 -> V_16 , L_5 ) ;
return - V_36 ;
}
V_8 -> V_3 . V_16 = & V_29 -> V_16 ;
V_8 -> V_3 . V_37 = & V_38 ;
V_8 -> V_3 . V_39 = - 1 ;
V_8 -> V_3 . V_40 = 1 ;
V_32 = F_22 ( V_29 , V_41 , 0 ) ;
if ( ! V_32 ) {
F_17 ( & V_29 -> V_16 , L_6 ) ;
return - V_42 ;
}
V_8 -> V_17 = F_23 ( & V_29 -> V_16 , V_32 ) ;
if ( ! V_8 -> V_17 )
return - V_43 ;
V_30 = F_24 ( & V_8 -> V_3 ) ;
if ( V_30 < 0 ) {
F_17 ( & V_29 -> V_16 , L_7 , V_30 ) ;
return V_30 ;
}
F_25 ( & V_29 -> V_16 ) ;
F_26 ( V_29 , V_8 ) ;
return 0 ;
}
static int T_2 F_27 ( struct V_28 * V_29 )
{
struct V_1 * V_8 = F_28 ( V_29 ) ;
F_10 ( & V_29 -> V_16 ) ;
F_29 ( & V_29 -> V_16 ) ;
return F_30 ( & V_8 -> V_3 ) ;
}
