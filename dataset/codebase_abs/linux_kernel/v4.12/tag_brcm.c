static struct V_1 * F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_1 * V_7 ;
if ( F_3 ( V_2 , V_8 ) < 0 )
goto V_9;
F_4 ( V_2 , V_8 ) ;
memmove ( V_2 -> V_10 , V_2 -> V_10 + V_8 , 2 * V_11 ) ;
V_7 = V_2 -> V_10 + 2 * V_11 ;
V_7 [ 0 ] = ( 1 << V_12 ) |
( ( V_2 -> V_13 << V_14 ) & V_15 ) ;
V_7 [ 1 ] = 0 ;
V_7 [ 2 ] = 0 ;
if ( V_6 -> V_16 -> V_17 == 8 )
V_7 [ 2 ] = V_18 ;
V_7 [ 3 ] = ( 1 << V_6 -> V_16 -> V_17 ) & V_19 ;
return V_2 ;
V_9:
F_5 ( V_2 ) ;
return NULL ;
}
static struct V_1 * F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_20 * V_21 ,
struct V_3 * V_22 )
{
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_26 * V_27 ;
int V_28 ;
T_1 * V_7 ;
V_27 = V_24 -> V_29 ;
if ( F_7 ( ! F_8 ( V_2 , V_8 ) ) )
goto V_30;
V_7 = V_2 -> V_10 - 2 ;
if ( F_7 ( ( V_7 [ 0 ] >> V_12 ) & V_31 ) )
goto V_30;
if ( F_7 ( V_7 [ 2 ] & V_32 ) )
goto V_30;
V_28 = V_7 [ 3 ] & V_33 ;
if ( V_28 >= V_27 -> V_34 || ! V_27 -> V_35 [ V_28 ] . V_36 )
goto V_30;
F_9 ( V_2 , V_8 ) ;
memmove ( V_2 -> V_10 - V_37 ,
V_2 -> V_10 - V_37 - V_8 ,
2 * V_11 ) ;
V_2 -> V_4 = V_27 -> V_35 [ V_28 ] . V_36 ;
return V_2 ;
V_30:
return NULL ;
}
