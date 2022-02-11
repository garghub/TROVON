static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_7 = F_3 ( V_6 ) ;
int V_8 = F_4 ( V_7 -> V_9 ) ;
V_4 -> V_10 . integer . V_10 [ 0 ] = ! V_8 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_7 = F_3 ( V_6 ) ;
F_6 ( V_7 -> V_9 , ! V_4 -> V_10 . integer . V_10 [ 0 ] ) ;
return 0 ;
}
static int F_7 ( struct V_5 * V_11 )
{
struct V_7 * V_7 = F_3 ( V_11 ) ;
int V_12 ;
if ( V_7 -> V_13 & V_14 ) {
V_12 = F_8 ( V_7 -> V_15 , V_16 ,
V_17 ) ;
if ( V_12 )
return V_12 ;
}
if ( F_9 ( V_7 -> V_9 ) ) {
V_12 = F_10 ( V_11 , V_18 ,
F_11 ( V_18 ) ) ;
if ( V_12 )
return V_12 ;
}
return 0 ;
}
static int F_12 ( struct V_19 * V_20 ,
const struct V_21 * V_22 )
{
struct V_7 * V_7 ;
struct V_23 * V_24 = V_20 -> V_25 . V_26 ;
int V_27 ;
V_7 = F_13 ( & V_20 -> V_25 , sizeof( * V_7 ) , V_28 ) ;
if ( ! V_7 )
return - V_29 ;
if ( V_24 ) {
V_27 = F_14 ( & V_20 -> V_25 , V_24 -> V_9 ,
V_30 , L_1 ) ;
V_7 -> V_9 = V_27 ? : V_24 -> V_9 ;
V_27 = F_14 ( & V_20 -> V_25 , V_24 -> V_31 ,
V_30 , L_2 ) ;
V_7 -> V_31 = V_27 ? : V_24 -> V_31 ;
V_7 -> V_13 = V_24 -> V_13 ;
} else {
V_7 -> V_31 = - V_32 ;
V_7 -> V_9 = - V_32 ;
}
F_15 ( V_20 , V_7 ) ;
V_7 -> V_15 = F_16 ( V_20 , & V_33 ) ;
if ( F_17 ( V_7 -> V_15 ) )
return F_18 ( V_7 -> V_15 ) ;
return F_19 ( & V_20 -> V_25 ,
& V_34 , NULL , 0 ) ;
}
