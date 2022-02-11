static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_6 ;
F_3 ( V_5 -> V_7 , V_3 , & V_6 ) ;
return ! ( V_6 & V_8 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_5 ( V_5 -> V_7 , V_3 , 0 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned int V_3 , int V_9 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_10 ;
if ( V_9 )
V_10 = F_5 ( V_5 -> V_7 , V_3 , V_8 |
V_11 ) ;
else
V_10 = F_5 ( V_5 -> V_7 , V_3 , V_8 ) ;
return V_10 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_6 ;
F_3 ( V_5 -> V_7 , V_3 , & V_6 ) ;
return ! ! ( V_6 & V_5 -> V_12 ) ;
}
static void F_8 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_9 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_9 )
F_9 ( V_5 -> V_7 , V_3 , V_11 ,
V_11 ) ;
else
F_9 ( V_5 -> V_7 , V_3 , V_11 , 0 ) ;
}
static int F_10 ( struct V_13 * V_14 ,
const struct V_15 * V_16 )
{
const struct V_17 * V_18 ;
struct V_4 * V_5 ;
T_1 V_19 ;
int V_10 ;
V_18 = F_11 ( V_20 , & V_14 -> V_21 ) ;
if ( ! V_18 )
return - V_22 ;
if ( F_12 ( V_14 -> V_21 . V_23 , L_1 , & V_19 ) )
V_19 = V_24 ;
V_5 = F_13 ( & V_14 -> V_21 , sizeof( * V_5 ) , V_25 ) ;
if ( ! V_5 )
return - V_26 ;
V_5 -> V_1 = V_27 ;
V_5 -> V_1 . V_28 = L_2 ;
V_5 -> V_1 . V_19 = V_19 ;
V_5 -> V_1 . V_29 = & V_14 -> V_21 ;
V_5 -> V_12 = ( V_30 ) V_18 -> V_31 ;
V_5 -> V_7 = F_14 ( V_14 , & V_32 ) ;
if ( F_15 ( V_5 -> V_7 ) ) {
V_10 = F_16 ( V_5 -> V_7 ) ;
F_17 ( & V_14 -> V_21 , L_3 ,
V_10 ) ;
return V_10 ;
}
V_10 = F_18 ( & V_14 -> V_21 , & V_5 -> V_1 , V_5 ) ;
if ( V_10 < 0 ) {
F_17 ( & V_14 -> V_21 , L_4 ) ;
return V_10 ;
}
F_19 ( V_14 , V_5 ) ;
return 0 ;
}
