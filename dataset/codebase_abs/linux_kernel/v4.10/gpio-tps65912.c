static int F_1 ( struct V_1 * V_2 ,
unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 , V_7 ;
V_6 = F_3 ( V_5 -> V_8 -> V_9 , V_10 + V_3 , & V_7 ) ;
if ( V_6 )
return V_6 ;
if ( V_7 & V_11 )
return V_12 ;
else
return V_13 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_5 ( V_5 -> V_8 -> V_9 , V_10 + V_3 ,
V_11 , 0 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned V_3 , int V_14 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_5 ( V_5 -> V_8 -> V_9 , V_10 + V_3 ,
V_15 , V_14 ? V_15 : 0 ) ;
return F_5 ( V_5 -> V_8 -> V_9 , V_10 + V_3 ,
V_11 , V_11 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 , V_7 ;
V_6 = F_3 ( V_5 -> V_8 -> V_9 , V_10 + V_3 , & V_7 ) ;
if ( V_6 )
return V_6 ;
if ( V_7 & V_16 )
return 1 ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 , unsigned V_3 ,
int V_14 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_5 ( V_5 -> V_8 -> V_9 , V_10 + V_3 ,
V_15 , V_14 ? V_15 : 0 ) ;
}
static int F_9 ( struct V_17 * V_18 )
{
struct V_19 * V_8 = F_10 ( V_18 -> V_20 . V_21 ) ;
struct V_4 * V_5 ;
int V_6 ;
V_5 = F_11 ( & V_18 -> V_20 , sizeof( * V_5 ) , V_22 ) ;
if ( ! V_5 )
return - V_23 ;
V_5 -> V_8 = F_10 ( V_18 -> V_20 . V_21 ) ;
V_5 -> V_1 = V_24 ;
V_5 -> V_1 . V_21 = V_8 -> V_20 ;
V_6 = F_12 ( & V_18 -> V_20 , & V_5 -> V_1 ,
V_5 ) ;
if ( V_6 < 0 ) {
F_13 ( & V_18 -> V_20 , L_1 , V_6 ) ;
return V_6 ;
}
F_14 ( V_18 , V_5 ) ;
return 0 ;
}
