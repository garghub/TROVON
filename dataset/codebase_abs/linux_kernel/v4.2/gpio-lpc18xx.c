static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_2 * V_3 , unsigned V_5 )
{
return F_4 ( V_5 ) ;
}
static void F_5 ( struct V_2 * V_3 , unsigned V_5 )
{
F_6 ( V_5 ) ;
}
static void F_7 ( struct V_2 * V_3 , unsigned V_5 , int V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_8 ( V_6 ? 1 : 0 , V_7 -> V_8 + V_5 ) ;
}
static int F_9 ( struct V_2 * V_3 , unsigned V_5 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return ! ! F_10 ( V_7 -> V_8 + V_5 ) ;
}
static int F_11 ( struct V_2 * V_3 , unsigned V_5 ,
bool V_9 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned long V_10 ;
T_1 V_11 , V_12 , V_13 ;
V_11 = V_5 / V_14 ;
V_12 = V_5 % V_14 ;
F_12 ( & V_7 -> V_15 , V_10 ) ;
V_13 = F_13 ( V_7 -> V_8 + F_14 ( V_11 ) ) ;
if ( V_9 )
V_13 |= F_15 ( V_12 ) ;
else
V_13 &= ~ F_15 ( V_12 ) ;
F_16 ( V_13 , V_7 -> V_8 + F_14 ( V_11 ) ) ;
F_17 ( & V_7 -> V_15 , V_10 ) ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 ,
unsigned V_5 )
{
return F_11 ( V_3 , V_5 , false ) ;
}
static int F_19 ( struct V_2 * V_3 ,
unsigned V_5 , int V_6 )
{
F_7 ( V_3 , V_5 , V_6 ) ;
return F_11 ( V_3 , V_5 , true ) ;
}
static int F_20 ( struct V_16 * V_17 )
{
struct V_1 * V_7 ;
struct V_18 * V_19 ;
int V_20 ;
V_7 = F_21 ( & V_17 -> V_21 , sizeof( * V_7 ) , V_22 ) ;
if ( ! V_7 )
return - V_23 ;
V_7 -> V_4 = V_24 ;
F_22 ( V_17 , V_7 ) ;
V_19 = F_23 ( V_17 , V_25 , 0 ) ;
V_7 -> V_8 = F_24 ( & V_17 -> V_21 , V_19 ) ;
if ( F_25 ( V_7 -> V_8 ) )
return F_26 ( V_7 -> V_8 ) ;
V_7 -> V_26 = F_27 ( & V_17 -> V_21 , NULL ) ;
if ( F_25 ( V_7 -> V_26 ) ) {
F_28 ( & V_17 -> V_21 , L_1 ) ;
return F_26 ( V_7 -> V_26 ) ;
}
V_20 = F_29 ( V_7 -> V_26 ) ;
if ( V_20 ) {
F_28 ( & V_17 -> V_21 , L_2 ) ;
return V_20 ;
}
F_30 ( & V_7 -> V_15 ) ;
V_7 -> V_4 . V_21 = & V_17 -> V_21 ;
V_20 = F_31 ( & V_7 -> V_4 ) ;
if ( V_20 ) {
F_28 ( & V_17 -> V_21 , L_3 ) ;
F_32 ( V_7 -> V_26 ) ;
return V_20 ;
}
return 0 ;
}
static int F_33 ( struct V_16 * V_17 )
{
struct V_1 * V_7 = F_34 ( V_17 ) ;
F_35 ( & V_7 -> V_4 ) ;
F_32 ( V_7 -> V_26 ) ;
return 0 ;
}
