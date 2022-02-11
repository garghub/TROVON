static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_2 ) ;
}
static int F_3 ( struct V_2 * V_4 , unsigned int V_5 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_6 * V_7 = V_1 -> V_8 -> V_9 ;
T_1 V_10 = 0 ;
int V_11 ;
V_11 = F_4 ( V_7 , V_12 , & V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
return ! ! ( V_10 & F_5 ( V_5 ) ) ;
}
static void F_6 ( struct V_2 * V_4 , unsigned int V_5 , int V_10 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_6 * V_7 = V_1 -> V_8 -> V_9 ;
if ( V_10 )
F_7 ( V_7 , V_13 , F_5 ( V_5 ) ) ;
else
F_8 ( V_7 , V_13 , F_5 ( V_5 ) ) ;
}
static int F_9 ( struct V_2 * V_4 , unsigned int V_5 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_6 * V_7 = V_1 -> V_8 -> V_9 ;
int V_11 ;
V_11 = F_8 ( V_7 , V_14 , F_5 ( V_5 ) ) ;
if ( V_11 < 0 )
return V_11 ;
return F_8 ( V_7 , V_15 , F_5 ( V_5 ) ) ;
}
static int F_10 ( struct V_2 * V_4 , unsigned V_5 ,
int V_16 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_6 * V_7 = V_1 -> V_8 -> V_9 ;
int V_11 ;
F_6 ( V_4 , V_5 , V_16 ) ;
V_11 = F_7 ( V_7 , V_14 , F_5 ( V_5 ) ) ;
if ( V_11 < 0 )
return V_11 ;
return F_8 ( V_7 , V_15 , F_5 ( V_5 ) ) ;
}
static int F_11 ( struct V_2 * V_4 , unsigned V_5 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
if ( V_5 < V_17 )
return V_1 -> V_8 -> V_18 +
V_19 + V_5 ;
return - V_20 ;
}
static void F_12 ( struct V_2 * V_4 , unsigned V_5 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_6 * V_7 = V_1 -> V_8 -> V_9 ;
F_7 ( V_7 , V_15 , F_5 ( V_5 ) ) ;
}
static int F_13 ( struct V_21 * V_22 )
{
struct V_8 * V_8 = F_14 ( V_22 -> V_9 . V_7 ) ;
struct V_23 * V_24 = F_15 ( V_8 -> V_9 ) ;
struct V_1 * V_1 ;
V_1 = F_16 ( & V_22 -> V_9 , sizeof( * V_1 ) ,
V_25 ) ;
if ( ! V_1 )
return - V_26 ;
V_1 -> V_2 . V_27 = L_1 ,
V_1 -> V_2 . V_28 = V_29 ,
V_1 -> V_2 . free = F_12 ,
V_1 -> V_2 . V_30 = F_9 ,
V_1 -> V_2 . V_31 = F_10 ,
V_1 -> V_2 . V_32 = F_6 ,
V_1 -> V_2 . V_33 = F_3 ,
V_1 -> V_2 . V_34 = F_11 ,
V_1 -> V_2 . V_35 = V_17 ,
V_1 -> V_2 . V_36 = true ,
V_1 -> V_2 . V_9 = & V_22 -> V_9 ;
V_1 -> V_2 . V_37 = - 1 ;
V_1 -> V_8 = V_8 ;
if ( V_24 && V_24 -> V_38 )
V_1 -> V_2 . V_37 = V_24 -> V_38 ;
F_17 ( V_22 , V_1 ) ;
return F_18 ( & V_1 -> V_2 ) ;
}
static int F_19 ( struct V_21 * V_22 )
{
struct V_1 * V_1 = F_20 ( V_22 ) ;
F_21 ( & V_1 -> V_2 ) ;
return 0 ;
}
static int T_2 F_22 ( void )
{
return F_23 ( & V_39 ) ;
}
static void T_3 F_24 ( void )
{
F_25 ( & V_39 ) ;
}
