static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return F_3 ( V_5 , struct V_1 , V_5 ) ;
}
static int F_4 ( struct V_2 * V_3 , unsigned V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return ( V_7 -> V_8 & V_9 ) ? V_10 : V_11 ;
}
static int F_5 ( struct V_2 * V_3 , unsigned int V_12 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return ( V_7 -> V_8 & V_9 ) ? - V_13 : 0 ;
}
static int F_6 ( struct V_2 * V_3 , unsigned int V_12 , int V_14 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
if ( V_7 -> V_8 & V_9 ) {
V_3 -> V_15 ( V_3 , V_12 , V_14 ) ;
return 0 ;
}
return - V_13 ;
}
static int F_7 ( struct V_16 * V_17 )
{
const struct V_18 * V_19 =
F_8 ( V_20 , & V_17 -> V_21 ) ;
struct V_1 * V_7 ;
struct V_22 * V_23 ;
void T_1 * V_24 ;
int V_25 ;
V_7 = F_9 ( & V_17 -> V_21 , sizeof( * V_7 ) , V_26 ) ;
if ( ! V_7 )
return - V_27 ;
V_23 = F_10 ( V_17 , V_28 , 0 ) ;
V_24 = F_11 ( & V_17 -> V_21 , V_23 ) ;
if ( F_12 ( V_24 ) )
return F_13 ( V_24 ) ;
V_7 -> V_8 = ( unsigned ) V_19 -> V_29 ;
V_25 = F_14 ( & V_7 -> V_5 , & V_17 -> V_21 ,
F_15 ( F_16 ( V_7 -> V_8 ) , 8 ) ,
V_24 , NULL , NULL , NULL , NULL , 0 ) ;
if ( V_25 )
return V_25 ;
V_7 -> V_5 . V_3 . V_30 = F_5 ;
V_7 -> V_5 . V_3 . V_31 = F_6 ;
V_7 -> V_5 . V_3 . V_32 = F_4 ;
V_7 -> V_5 . V_3 . V_33 = F_16 ( V_7 -> V_8 ) ;
V_7 -> V_5 . V_3 . V_34 = V_35 ;
F_17 ( V_17 , V_7 ) ;
return F_18 ( & V_7 -> V_5 . V_3 ) ;
}
static int F_19 ( struct V_16 * V_17 )
{
struct V_1 * V_7 = F_20 ( V_17 ) ;
return F_21 ( & V_7 -> V_5 ) ;
}
