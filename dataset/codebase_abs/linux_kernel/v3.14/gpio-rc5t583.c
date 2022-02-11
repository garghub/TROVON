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
if ( ( V_5 >= 0 ) && ( V_5 < 8 ) )
return V_1 -> V_8 -> V_17 +
V_18 + V_5 ;
return - V_19 ;
}
static void F_12 ( struct V_2 * V_4 , unsigned V_5 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_6 * V_7 = V_1 -> V_8 -> V_9 ;
F_7 ( V_7 , V_15 , F_5 ( V_5 ) ) ;
}
static int F_13 ( struct V_20 * V_21 )
{
struct V_8 * V_8 = F_14 ( V_21 -> V_9 . V_7 ) ;
struct V_22 * V_23 = F_15 ( V_8 -> V_9 ) ;
struct V_1 * V_1 ;
V_1 = F_16 ( & V_21 -> V_9 , sizeof( * V_1 ) ,
V_24 ) ;
if ( ! V_1 ) {
F_17 ( & V_21 -> V_9 , L_1 ) ;
return - V_25 ;
}
V_1 -> V_2 . V_26 = L_2 ,
V_1 -> V_2 . V_27 = V_28 ,
V_1 -> V_2 . free = F_12 ,
V_1 -> V_2 . V_29 = F_9 ,
V_1 -> V_2 . V_30 = F_10 ,
V_1 -> V_2 . V_31 = F_6 ,
V_1 -> V_2 . V_32 = F_3 ,
V_1 -> V_2 . V_33 = F_11 ,
V_1 -> V_2 . V_34 = V_35 ,
V_1 -> V_2 . V_36 = true ,
V_1 -> V_2 . V_9 = & V_21 -> V_9 ;
V_1 -> V_2 . V_37 = - 1 ;
V_1 -> V_8 = V_8 ;
if ( V_23 && V_23 -> V_38 )
V_1 -> V_2 . V_37 = V_23 -> V_38 ;
F_18 ( V_21 , V_1 ) ;
return F_19 ( & V_1 -> V_2 ) ;
}
static int F_20 ( struct V_20 * V_21 )
{
struct V_1 * V_1 = F_21 ( V_21 ) ;
return F_22 ( & V_1 -> V_2 ) ;
}
static int T_2 F_23 ( void )
{
return F_24 ( & V_39 ) ;
}
static void T_3 F_25 ( void )
{
F_26 ( & V_39 ) ;
}
