static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return ! ( V_5 -> V_6 & V_7 ) ;
}
static int F_3 ( struct V_1 * V_2 , unsigned int V_8 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return ( V_5 -> V_6 & V_7 ) ? - V_9 : 0 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_8 , int V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_6 & V_7 ) {
V_2 -> V_11 ( V_2 , V_8 , V_10 ) ;
return 0 ;
}
return - V_9 ;
}
static int F_5 ( struct V_12 * V_13 )
{
const struct V_14 * V_15 ;
struct V_4 * V_5 ;
struct V_16 * V_17 ;
void T_1 * V_18 ;
int V_19 ;
V_15 = F_6 ( V_20 , & V_13 -> V_21 ) ;
if ( ! V_15 )
return - V_22 ;
V_5 = F_7 ( & V_13 -> V_21 , sizeof( * V_5 ) , V_23 ) ;
if ( ! V_5 )
return - V_24 ;
V_17 = F_8 ( V_13 , V_25 , 0 ) ;
V_18 = F_9 ( & V_13 -> V_21 , V_17 ) ;
if ( F_10 ( V_18 ) )
return F_11 ( V_18 ) ;
V_5 -> V_6 = ( V_26 ) V_15 -> V_27 ;
V_19 = F_12 ( & V_5 -> V_2 , & V_13 -> V_21 ,
F_13 ( F_14 ( V_5 -> V_6 ) , 8 ) ,
V_18 , NULL , NULL , NULL , NULL , 0 ) ;
if ( V_19 )
return V_19 ;
V_5 -> V_2 . V_28 = F_3 ;
V_5 -> V_2 . V_29 = F_4 ;
V_5 -> V_2 . V_30 = F_1 ;
V_5 -> V_2 . V_31 = F_14 ( V_5 -> V_6 ) ;
V_5 -> V_2 . V_32 = V_33 ;
F_15 ( V_13 , V_5 ) ;
return F_16 ( & V_5 -> V_2 , V_5 ) ;
}
static int F_17 ( struct V_12 * V_13 )
{
struct V_4 * V_5 = F_18 ( V_13 ) ;
F_19 ( & V_5 -> V_2 ) ;
return 0 ;
}
