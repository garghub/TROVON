static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 -> V_8 ;
T_1 V_9 = 0 ;
int V_10 ;
V_10 = F_3 ( V_6 , V_11 , & V_9 ) ;
if ( V_10 < 0 )
return V_10 ;
return ! ! ( V_9 & F_4 ( V_3 ) ) ;
}
static void F_5 ( struct V_1 * V_2 , unsigned int V_3 , int V_9 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 -> V_8 ;
if ( V_9 )
F_6 ( V_6 , V_12 , F_4 ( V_3 ) ) ;
else
F_7 ( V_6 , V_12 , F_4 ( V_3 ) ) ;
}
static int F_8 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 -> V_8 ;
int V_10 ;
V_10 = F_7 ( V_6 , V_13 , F_4 ( V_3 ) ) ;
if ( V_10 < 0 )
return V_10 ;
return F_7 ( V_6 , V_14 , F_4 ( V_3 ) ) ;
}
static int F_9 ( struct V_1 * V_2 , unsigned V_3 ,
int V_15 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 -> V_8 ;
int V_10 ;
F_5 ( V_2 , V_3 , V_15 ) ;
V_10 = F_6 ( V_6 , V_13 , F_4 ( V_3 ) ) ;
if ( V_10 < 0 )
return V_10 ;
return F_7 ( V_6 , V_14 , F_4 ( V_3 ) ) ;
}
static int F_10 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
if ( V_3 < V_16 )
return V_4 -> V_7 -> V_17 +
V_18 + V_3 ;
return - V_19 ;
}
static void F_11 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 -> V_8 ;
F_6 ( V_6 , V_14 , F_4 ( V_3 ) ) ;
}
static int F_12 ( struct V_20 * V_21 )
{
struct V_7 * V_7 = F_13 ( V_21 -> V_8 . V_6 ) ;
struct V_22 * V_23 = F_14 ( V_7 -> V_8 ) ;
struct V_4 * V_4 ;
V_4 = F_15 ( & V_21 -> V_8 , sizeof( * V_4 ) ,
V_24 ) ;
if ( ! V_4 )
return - V_25 ;
V_4 -> V_1 . V_26 = L_1 ,
V_4 -> V_1 . V_27 = V_28 ,
V_4 -> V_1 . free = F_11 ,
V_4 -> V_1 . V_29 = F_8 ,
V_4 -> V_1 . V_30 = F_9 ,
V_4 -> V_1 . V_31 = F_5 ,
V_4 -> V_1 . V_32 = F_1 ,
V_4 -> V_1 . V_33 = F_10 ,
V_4 -> V_1 . V_34 = V_16 ,
V_4 -> V_1 . V_35 = true ,
V_4 -> V_1 . V_6 = & V_21 -> V_8 ;
V_4 -> V_1 . V_36 = - 1 ;
V_4 -> V_7 = V_7 ;
if ( V_23 && V_23 -> V_37 )
V_4 -> V_1 . V_36 = V_23 -> V_37 ;
F_16 ( V_21 , V_4 ) ;
return F_17 ( & V_21 -> V_8 , & V_4 -> V_1 ,
V_4 ) ;
}
static int T_2 F_18 ( void )
{
return F_19 ( & V_38 ) ;
}
static void T_3 F_20 ( void )
{
F_21 ( & V_38 ) ;
}
