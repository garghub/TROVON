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
static int F_7 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_3 ( V_6 ) ;
int V_11 ;
if ( V_7 -> V_12 & V_13 ) {
V_11 = F_8 ( V_6 , V_14 , V_15 ) ;
if ( V_11 )
return V_11 ;
}
if ( F_9 ( V_7 -> V_9 ) ) {
V_11 = F_10 ( V_6 , V_16 ,
F_11 ( V_16 ) ) ;
if ( V_11 )
return V_11 ;
}
return 0 ;
}
static int F_12 ( struct V_17 * V_18 ,
const struct V_19 * V_20 )
{
struct V_7 * V_7 ;
struct V_21 * V_22 = V_18 -> V_23 . V_24 ;
int V_25 ;
V_7 = F_13 ( & V_18 -> V_23 , sizeof( * V_7 ) , V_26 ) ;
if ( ! V_7 )
return - V_27 ;
if ( V_22 ) {
V_25 = F_14 ( V_22 -> V_9 , V_28 , L_1 ) ;
V_7 -> V_9 = V_25 ? : V_22 -> V_9 ;
V_25 = F_14 ( V_22 -> V_29 , V_28 , L_2 ) ;
V_7 -> V_29 = V_25 ? : V_22 -> V_29 ;
V_7 -> V_12 = V_22 -> V_12 ;
} else {
V_7 -> V_29 = - V_30 ;
V_7 -> V_9 = - V_30 ;
}
F_15 ( V_18 , V_7 ) ;
V_7 -> V_31 = F_16 ( V_18 , & V_32 ) ;
if ( F_17 ( V_7 -> V_31 ) ) {
V_25 = F_18 ( V_7 -> V_31 ) ;
goto V_33;
}
V_25 = F_19 ( & V_18 -> V_23 , & V_34 , NULL , 0 ) ;
if ( V_25 )
goto V_33;
return 0 ;
V_33:
if ( F_9 ( V_7 -> V_29 ) )
F_20 ( V_7 -> V_29 ) ;
if ( F_9 ( V_7 -> V_9 ) )
F_20 ( V_7 -> V_9 ) ;
return V_25 ;
}
static int F_21 ( struct V_17 * V_18 )
{
struct V_7 * V_7 = F_22 ( V_18 ) ;
F_23 ( & V_18 -> V_23 ) ;
if ( F_9 ( V_7 -> V_29 ) )
F_20 ( V_7 -> V_29 ) ;
if ( F_9 ( V_7 -> V_9 ) )
F_20 ( V_7 -> V_9 ) ;
return 0 ;
}
