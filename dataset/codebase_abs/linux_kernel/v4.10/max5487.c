static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 , ( const void * ) & V_3 , sizeof( T_1 ) ) ;
}
static int F_3 ( struct V_4 * V_5 ,
struct V_6 const * V_7 ,
int * V_8 , int * V_9 , long V_10 )
{
struct V_11 * V_12 = F_4 ( V_5 ) ;
if ( V_10 != V_13 )
return - V_14 ;
* V_8 = 1000 * V_12 -> V_15 ;
* V_9 = V_16 ;
return V_17 ;
}
static int F_5 ( struct V_4 * V_5 ,
struct V_6 const * V_7 ,
int V_8 , int V_9 , long V_10 )
{
struct V_11 * V_12 = F_4 ( V_5 ) ;
if ( V_10 != V_18 )
return - V_14 ;
if ( V_8 < 0 || V_8 > V_16 )
return - V_14 ;
return F_1 ( V_12 -> V_2 , V_7 -> V_19 | V_8 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_11 * V_12 ;
const struct V_20 * V_21 = F_7 ( V_2 ) ;
int V_22 ;
V_5 = F_8 ( & V_2 -> V_23 , sizeof( * V_12 ) ) ;
if ( ! V_5 )
return - V_24 ;
F_9 ( & V_2 -> V_23 , V_5 ) ;
V_12 = F_4 ( V_5 ) ;
V_12 -> V_2 = V_2 ;
V_12 -> V_15 = V_21 -> V_25 ;
V_5 -> V_26 = & V_27 ;
V_5 -> V_28 = V_21 -> V_28 ;
V_5 -> V_23 . V_29 = & V_2 -> V_23 ;
V_5 -> V_30 = V_31 ;
V_5 -> V_32 = V_33 ;
V_5 -> V_34 = F_10 ( V_33 ) ;
V_22 = F_1 ( V_12 -> V_2 , V_35 ) ;
if ( V_22 < 0 )
return V_22 ;
return F_11 ( V_5 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_13 ( & V_2 -> V_23 ) ;
F_14 ( V_5 ) ;
return F_1 ( V_2 , V_36 ) ;
}
