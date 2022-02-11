static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
T_2 V_5 ;
V_3 = F_2 ( V_2 , ( char * ) & V_5 , 2 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_3 != 2 )
return - V_6 ;
V_4 = F_3 ( V_5 ) ;
V_4 = ( V_4 >> V_7 ) & V_8 ;
return V_4 ;
}
static inline T_1 F_4 ( T_1 V_9 , T_1 V_10 )
{
if ( V_10 == 0 )
return 0 ;
V_10 = V_10 * V_11 - V_11 / 2 ;
return V_10 * F_5 ( V_9 ,
( 1 << V_12 ) * V_11 ) ;
}
static T_3 F_6 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_5 )
{
struct V_1 * V_2 = F_7 ( V_14 ) ;
struct V_17 * V_18 = F_8 ( V_2 ) ;
int V_4 , V_19 ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
V_19 = F_4 ( V_18 -> V_9 , V_4 ) ;
return sprintf ( V_5 , L_1 , V_19 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
const struct V_20 * V_21 )
{
int V_22 ;
struct V_17 * V_18 = NULL ;
if ( ! F_10 ( V_2 -> V_23 , V_24 ) )
return - V_25 ;
V_18 = F_11 ( sizeof( struct V_17 ) , V_26 ) ;
if ( ! V_18 )
return - V_27 ;
F_12 ( V_2 , V_18 ) ;
if ( V_2 -> V_14 . V_28 ) {
V_18 -> V_9 = * ( V_29 * ) V_2 -> V_14 . V_28 ;
if ( V_18 -> V_9 > V_30 ||
V_18 -> V_9 < V_31 ) {
V_22 = - V_32 ;
goto V_33;
}
} else
V_18 -> V_9 = V_34 ;
V_22 = F_13 ( & V_2 -> V_14 . V_35 , & V_36 . V_16 ) ;
if ( V_22 )
goto V_33;
V_18 -> V_37 = F_14 ( & V_2 -> V_14 ) ;
if ( F_15 ( V_18 -> V_37 ) ) {
V_22 = F_16 ( V_18 -> V_37 ) ;
goto V_38;
}
return 0 ;
V_38:
F_17 ( & V_2 -> V_14 . V_35 , & V_36 . V_16 ) ;
V_33:
F_18 ( V_18 ) ;
return V_22 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_8 ( V_2 ) ;
F_20 ( V_18 -> V_37 ) ;
F_17 ( & V_2 -> V_14 . V_35 , & V_36 . V_16 ) ;
F_18 ( V_18 ) ;
return 0 ;
}
