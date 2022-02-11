static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ,
struct V_4 ,
V_2 ) ;
int V_6 = V_3 / V_7 ;
int V_8 = V_3 % V_7 ;
unsigned long V_9 ;
T_1 V_10 ;
F_3 ( & V_5 -> V_11 , V_9 ) ;
V_10 = F_4 ( V_5 -> V_12 + ( V_6 * 4 ) ) ;
F_5 ( V_10 | F_6 ( V_8 ) , V_5 -> V_12 + ( V_6 * 4 ) ) ;
F_7 ( & V_5 -> V_11 , V_9 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ,
struct V_4 ,
V_2 ) ;
int V_6 = V_3 / V_7 ;
int V_8 = V_3 % V_7 ;
unsigned long V_9 ;
T_1 V_10 ;
F_3 ( & V_5 -> V_11 , V_9 ) ;
V_10 = F_4 ( V_5 -> V_12 + ( V_6 * 4 ) ) ;
F_5 ( V_10 & ~ F_6 ( V_8 ) , V_5 -> V_12 + ( V_6 * 4 ) ) ;
F_7 ( & V_5 -> V_11 , V_9 ) ;
return 0 ;
}
static int F_9 ( struct V_13 * V_14 )
{
struct V_4 * V_5 ;
struct V_15 * V_16 ;
V_5 = F_10 ( & V_14 -> V_17 , sizeof( * V_5 ) , V_18 ) ;
if ( ! V_5 )
return - V_19 ;
V_16 = F_11 ( V_14 , V_20 , 0 ) ;
V_5 -> V_12 = F_12 ( & V_14 -> V_17 , V_16 ) ;
if ( F_13 ( V_5 -> V_12 ) )
return F_14 ( V_5 -> V_12 ) ;
F_15 ( & V_5 -> V_11 ) ;
V_5 -> V_2 . V_21 = V_22 ;
V_5 -> V_2 . V_23 = F_16 ( V_16 ) * 8 ;
V_5 -> V_2 . V_24 = & V_25 ;
V_5 -> V_2 . V_26 = V_14 -> V_17 . V_26 ;
return F_17 ( & V_14 -> V_17 , & V_5 -> V_2 ) ;
}
