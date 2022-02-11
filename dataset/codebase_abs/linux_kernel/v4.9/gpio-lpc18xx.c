static void F_1 ( struct V_1 * V_2 , unsigned V_3 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_4 ? 1 : 0 , V_6 -> V_7 + V_3 ) ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return ! ! F_5 ( V_6 -> V_7 + V_3 ) ;
}
static int F_6 ( struct V_1 * V_2 , unsigned V_3 ,
bool V_8 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_9 ;
T_1 V_10 , V_11 , V_12 ;
V_10 = V_3 / V_13 ;
V_11 = V_3 % V_13 ;
F_7 ( & V_6 -> V_14 , V_9 ) ;
V_12 = F_8 ( V_6 -> V_7 + F_9 ( V_10 ) ) ;
if ( V_8 )
V_12 |= F_10 ( V_11 ) ;
else
V_12 &= ~ F_10 ( V_11 ) ;
F_11 ( V_12 , V_6 -> V_7 + F_9 ( V_10 ) ) ;
F_12 ( & V_6 -> V_14 , V_9 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
unsigned V_3 )
{
return F_6 ( V_2 , V_3 , false ) ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned V_3 , int V_4 )
{
F_1 ( V_2 , V_3 , V_4 ) ;
return F_6 ( V_2 , V_3 , true ) ;
}
static int F_15 ( struct V_15 * V_16 )
{
struct V_5 * V_6 ;
struct V_17 * V_18 ;
int V_19 ;
V_6 = F_16 ( & V_16 -> V_20 , sizeof( * V_6 ) , V_21 ) ;
if ( ! V_6 )
return - V_22 ;
V_6 -> V_23 = V_24 ;
F_17 ( V_16 , V_6 ) ;
V_18 = F_18 ( V_16 , V_25 , 0 ) ;
V_6 -> V_7 = F_19 ( & V_16 -> V_20 , V_18 ) ;
if ( F_20 ( V_6 -> V_7 ) )
return F_21 ( V_6 -> V_7 ) ;
V_6 -> V_26 = F_22 ( & V_16 -> V_20 , NULL ) ;
if ( F_20 ( V_6 -> V_26 ) ) {
F_23 ( & V_16 -> V_20 , L_1 ) ;
return F_21 ( V_6 -> V_26 ) ;
}
V_19 = F_24 ( V_6 -> V_26 ) ;
if ( V_19 ) {
F_23 ( & V_16 -> V_20 , L_2 ) ;
return V_19 ;
}
F_25 ( & V_6 -> V_14 ) ;
V_6 -> V_23 . V_27 = & V_16 -> V_20 ;
V_19 = F_26 ( & V_6 -> V_23 , V_6 ) ;
if ( V_19 ) {
F_23 ( & V_16 -> V_20 , L_3 ) ;
F_27 ( V_6 -> V_26 ) ;
return V_19 ;
}
return 0 ;
}
static int F_28 ( struct V_15 * V_16 )
{
struct V_5 * V_6 = F_29 ( V_16 ) ;
F_30 ( & V_6 -> V_23 ) ;
F_27 ( V_6 -> V_26 ) ;
return 0 ;
}
