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
V_6 -> V_12 = V_7 -> V_13 ;
V_11 = F_8 ( V_6 , 2 , 6 , V_14 ) ;
if ( V_11 )
return V_11 ;
if ( V_7 -> V_15 & V_16 ) {
V_11 = F_9 ( V_6 , V_17 , V_18 ) ;
if ( V_11 )
return V_11 ;
}
if ( F_10 ( V_7 -> V_9 ) ) {
V_11 = F_11 ( V_6 , V_19 ,
F_12 ( V_19 ) ) ;
if ( V_11 )
return V_11 ;
}
return 0 ;
}
static int T_1 F_13 ( struct V_20 * V_21 ,
const struct V_22 * V_23 )
{
struct V_7 * V_7 ;
struct V_24 * V_25 = V_21 -> V_26 . V_27 ;
int V_28 ;
V_7 = F_14 ( & V_21 -> V_26 , sizeof( * V_7 ) , V_29 ) ;
if ( ! V_7 )
return - V_30 ;
if ( V_25 ) {
V_28 = F_15 ( V_25 -> V_9 , V_31 , L_1 ) ;
V_7 -> V_9 = V_28 ? : V_25 -> V_9 ;
V_28 = F_15 ( V_25 -> V_32 , V_31 , L_2 ) ;
V_7 -> V_32 = V_28 ? : V_25 -> V_32 ;
V_7 -> V_15 = V_25 -> V_15 ;
} else {
V_7 -> V_32 = - V_33 ;
V_7 -> V_9 = - V_33 ;
}
F_16 ( V_21 , V_7 ) ;
V_7 -> V_13 = F_17 ( V_21 , & V_34 ) ;
if ( F_18 ( V_7 -> V_13 ) ) {
V_28 = F_19 ( V_7 -> V_13 ) ;
goto V_35;
}
V_28 = F_20 ( & V_21 -> V_26 , & V_36 , NULL , 0 ) ;
if ( V_28 )
goto V_37;
return 0 ;
V_37:
F_21 ( V_7 -> V_13 ) ;
V_35:
if ( F_10 ( V_7 -> V_32 ) )
F_22 ( V_7 -> V_32 ) ;
if ( F_10 ( V_7 -> V_9 ) )
F_22 ( V_7 -> V_9 ) ;
return V_28 ;
}
static int T_2 F_23 ( struct V_20 * V_21 )
{
struct V_7 * V_7 = F_24 ( V_21 ) ;
F_25 ( & V_21 -> V_26 ) ;
F_21 ( V_7 -> V_13 ) ;
if ( F_10 ( V_7 -> V_32 ) )
F_22 ( V_7 -> V_32 ) ;
if ( F_10 ( V_7 -> V_9 ) )
F_22 ( V_7 -> V_9 ) ;
return 0 ;
}
