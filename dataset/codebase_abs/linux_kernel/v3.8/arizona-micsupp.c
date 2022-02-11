static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
if ( V_3 > V_4 )
return - V_5 ;
if ( V_3 == V_4 )
return 3300000 ;
else
return ( V_3 * 50000 ) + 1700000 ;
}
static int F_2 ( struct V_1 * V_2 ,
int V_6 , int V_7 )
{
unsigned int V_8 ;
int V_3 ;
if ( V_6 < 1700000 )
V_6 = 1700000 ;
if ( V_6 > 3200000 )
V_3 = V_4 ;
else
V_3 = F_3 ( V_6 - 1700000 , 50000 ) ;
if ( V_3 < 0 )
return - V_5 ;
V_8 = F_1 ( V_2 , V_3 ) ;
if ( V_8 < V_6 || V_8 > V_7 )
return - V_5 ;
return V_3 ;
}
static int F_4 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_5 ( V_10 -> V_12 . V_13 ) ;
struct V_14 V_15 = { } ;
struct V_16 * V_17 ;
int V_18 ;
V_17 = F_6 ( & V_10 -> V_12 , sizeof( * V_17 ) , V_19 ) ;
if ( V_17 == NULL ) {
F_7 ( & V_10 -> V_12 , L_1 ) ;
return - V_20 ;
}
V_17 -> V_11 = V_11 ;
V_17 -> V_21 = V_22 ;
V_17 -> V_21 . V_23 = & V_17 -> V_24 ;
V_17 -> V_24 . V_24 = L_2 ;
V_17 -> V_24 . V_25 = V_25 ( V_11 -> V_12 ) ;
V_15 . V_12 = V_11 -> V_12 ;
V_15 . V_26 = V_17 ;
V_15 . V_27 = V_11 -> V_27 ;
if ( V_11 -> V_28 . V_29 )
V_15 . V_21 = V_11 -> V_28 . V_29 ;
else
V_15 . V_21 = & V_17 -> V_21 ;
F_8 ( V_11 -> V_27 , V_30 ,
V_31 , 0 ) ;
V_17 -> V_32 = F_9 ( & V_16 , & V_15 ) ;
if ( F_10 ( V_17 -> V_32 ) ) {
V_18 = F_11 ( V_17 -> V_32 ) ;
F_7 ( V_11 -> V_12 , L_3 ,
V_18 ) ;
return V_18 ;
}
F_12 ( V_10 , V_17 ) ;
return 0 ;
}
static int F_13 ( struct V_9 * V_10 )
{
struct V_16 * V_17 = F_14 ( V_10 ) ;
F_15 ( V_17 -> V_32 ) ;
return 0 ;
}
