static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 ;
const struct V_7 * V_8 ;
struct V_7 V_9 ;
struct V_3 * V_4 ;
struct V_10 * V_11 ;
int V_12 ;
int V_13 ;
if ( F_5 () )
return - V_14 ;
V_6 = F_6 ( V_15 , & V_2 -> V_2 ) ;
if ( V_6 && V_6 -> V_16 ) {
V_8 = V_6 -> V_16 ;
} else {
F_7 ( & V_9 , - 1 ) ;
V_8 = & V_9 ;
V_9 . V_17 = 0 ;
}
V_4 = F_8 ( & V_2 -> V_2 , sizeof( * V_4 ) , V_18 ) ;
if ( ! V_4 )
return - V_19 ;
V_4 -> V_2 = & V_2 -> V_2 ;
if ( ! V_2 -> V_2 . V_20 )
V_2 -> V_2 . V_20 = & V_2 -> V_2 . V_21 ;
V_12 = F_9 ( & V_2 -> V_2 , F_10 ( 32 ) ) ;
if ( V_12 )
return V_12 ;
V_13 = F_11 ( V_2 , 0 ) ;
if ( V_13 < 0 ) {
F_12 ( & V_2 -> V_2 , L_1 ) ;
return V_13 ;
}
V_11 = F_13 ( V_2 , V_22 , 0 ) ;
V_4 -> V_23 = F_14 ( & V_2 -> V_2 , V_11 ) ;
if ( F_15 ( V_4 -> V_23 ) )
return F_16 ( V_4 -> V_23 ) ;
F_17 ( & V_2 -> V_2 , L_2 ,
( unsigned long ) V_11 -> V_24 , V_4 -> V_23 ) ;
V_12 = F_18 ( V_4 , V_13 , V_8 ) ;
if ( V_12 )
return V_12 ;
F_19 ( V_2 , V_4 ) ;
return V_12 ;
}
