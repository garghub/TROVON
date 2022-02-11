static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( & V_2 -> V_4 ) ;
if ( V_2 -> V_5 ) {
F_3 ( V_2 -> V_5 , 1 ) ;
F_4 ( 1 ) ;
F_3 ( V_2 -> V_5 , 0 ) ;
F_4 ( 1 ) ;
}
V_3 = F_5 ( V_2 -> V_6 , V_2 -> V_7 , V_2 -> V_8 ) ;
F_6 ( & V_2 -> V_4 ) ;
return V_3 ;
}
static int F_7 ( struct V_9 * V_10 ,
unsigned V_11 )
{
return 1 ;
}
static int F_8 ( struct V_9 * V_10 ,
unsigned V_11 )
{
return 0 ;
}
static int F_9 ( struct V_9 * V_10 ,
unsigned V_11 , int V_12 )
{
return - V_13 ;
}
static int F_10 ( struct V_9 * V_10 , unsigned V_11 )
{
struct V_1 * V_2 = F_11 ( V_10 ) ;
F_1 ( V_2 ) ;
return ( V_2 -> V_7 [ V_11 / 8 ] >> ( V_11 % 8 ) ) & 0x1 ;
}
static int F_12 ( struct V_14 * V_6 )
{
struct V_15 * V_16 = & V_6 -> V_16 ;
struct V_1 * V_2 ;
int V_3 ;
V_2 = F_13 ( V_16 , sizeof( * V_2 ) , V_17 ) ;
if ( ! V_2 )
return - V_18 ;
F_14 ( V_6 , V_2 ) ;
V_2 -> V_10 = V_19 ;
V_2 -> V_10 . V_20 = V_16 ;
F_15 ( V_16 -> V_21 , L_1 , & V_2 -> V_10 . V_22 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_8 = F_16 ( V_2 -> V_10 . V_22 , 8 ) ;
V_2 -> V_7 = F_13 ( V_16 , V_2 -> V_8 , V_17 ) ;
if ( ! V_2 -> V_7 )
return - V_18 ;
V_2 -> V_5 = F_17 ( V_16 , L_2 , V_23 ) ;
if ( F_18 ( V_2 -> V_5 ) ) {
V_3 = F_19 ( V_2 -> V_5 ) ;
if ( V_3 != - V_24 )
F_20 ( V_16 , L_3 ) ;
return V_3 ;
}
F_21 ( & V_2 -> V_4 ) ;
V_3 = F_22 ( & V_2 -> V_10 , V_2 ) ;
if ( V_3 < 0 ) {
F_20 ( V_16 , L_4 ) ;
return V_3 ;
}
return 0 ;
}
static int F_23 ( struct V_14 * V_6 )
{
struct V_1 * V_2 = F_24 ( V_6 ) ;
F_25 ( & V_2 -> V_10 ) ;
F_26 ( & V_2 -> V_4 ) ;
return 0 ;
}
