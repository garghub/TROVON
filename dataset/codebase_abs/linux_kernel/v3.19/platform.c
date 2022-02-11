static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 ) ;
F_4 ( V_4 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 ;
const struct V_7 * V_8 ;
struct V_7 V_9 ;
struct V_3 * V_4 ;
struct V_10 * V_11 ;
int V_12 ;
int V_13 ;
V_6 = F_6 ( V_14 , & V_2 -> V_2 ) ;
if ( V_6 && V_6 -> V_15 ) {
V_8 = V_6 -> V_15 ;
} else {
F_7 ( & V_9 , - 1 ) ;
V_8 = & V_9 ;
V_9 . V_16 = 0 ;
}
V_4 = F_8 ( & V_2 -> V_2 , sizeof( * V_4 ) , V_17 ) ;
if ( ! V_4 )
return - V_18 ;
V_4 -> V_2 = & V_2 -> V_2 ;
if ( ! V_2 -> V_2 . V_19 )
V_2 -> V_2 . V_19 = & V_2 -> V_2 . V_20 ;
V_12 = F_9 ( & V_2 -> V_2 , F_10 ( 32 ) ) ;
if ( V_12 )
return V_12 ;
V_13 = F_11 ( V_2 , 0 ) ;
if ( V_13 < 0 ) {
F_12 ( & V_2 -> V_2 , L_1 ) ;
return V_13 ;
}
F_13 ( V_4 -> V_2 , L_2 ,
V_13 ) ;
V_12 = F_14 ( V_4 -> V_2 , V_13 ,
V_21 , V_22 ,
F_15 ( V_4 -> V_2 ) , V_4 ) ;
if ( V_12 )
return V_12 ;
V_11 = F_16 ( V_2 , V_23 , 0 ) ;
V_4 -> V_24 = F_17 ( & V_2 -> V_2 , V_11 ) ;
if ( F_18 ( V_4 -> V_24 ) )
return F_19 ( V_4 -> V_24 ) ;
F_13 ( & V_2 -> V_2 , L_3 ,
( unsigned long ) V_11 -> V_25 , V_4 -> V_24 ) ;
V_4 -> V_26 = F_20 ( V_2 -> V_2 . V_27 ) ;
F_21 ( & V_4 -> V_28 ) ;
F_22 ( & V_4 -> V_29 ) ;
V_12 = F_23 ( V_4 , V_13 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_24 ( V_4 , V_13 , V_8 ) ;
if ( V_12 )
return V_12 ;
F_25 ( V_2 , V_4 ) ;
return V_12 ;
}
static int T_1 F_26 ( struct V_30 * V_2 )
{
struct V_3 * V_31 = F_27 ( V_2 ) ;
int V_32 = 0 ;
if ( F_28 ( V_31 ) )
V_32 = F_29 ( V_31 ) ;
return V_32 ;
}
static int T_1 F_30 ( struct V_30 * V_2 )
{
struct V_3 * V_31 = F_27 ( V_2 ) ;
int V_32 = 0 ;
if ( F_28 ( V_31 ) )
V_32 = F_31 ( V_31 ) ;
return V_32 ;
}
