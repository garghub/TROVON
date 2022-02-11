static struct V_1 * F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_1 * V_7 ;
if ( F_3 ( V_2 , V_8 ) < 0 )
goto V_9;
F_4 ( V_2 , V_8 ) ;
memmove ( V_2 -> V_10 , V_2 -> V_10 + V_8 , 2 * V_11 ) ;
V_7 = V_2 -> V_10 + 2 * V_11 ;
V_7 [ 0 ] = 0 ;
V_7 [ 1 ] = ( 1 << V_6 -> V_12 -> V_13 ) & V_14 ;
V_7 [ 2 ] = 0 ;
V_7 [ 3 ] = 0 ;
return V_2 ;
V_9:
F_5 ( V_2 ) ;
return NULL ;
}
static struct V_1 * F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_15 * V_16 ,
struct V_3 * V_17 )
{
struct V_18 * V_19 = V_4 -> V_20 ;
struct V_21 * V_22 ;
int V_23 ;
T_2 * V_24 , V_25 ;
if ( F_7 ( ! F_8 ( V_2 , V_8 ) ) )
goto V_26;
V_24 = ( T_2 * ) ( V_2 -> V_10 - 2 ) ;
V_25 = F_9 ( * V_24 ) ;
F_10 ( V_2 , V_8 ) ;
memmove ( V_2 -> V_10 - V_27 ,
V_2 -> V_10 - V_27 - V_8 ,
2 * V_11 ) ;
V_22 = V_19 -> V_22 [ 0 ] ;
if ( ! V_22 )
goto V_26;
V_23 = ( V_25 & V_28 ) ;
if ( ! V_22 -> V_29 [ V_23 ] . V_30 )
goto V_26;
V_2 -> V_4 = V_22 -> V_29 [ V_23 ] . V_30 ;
return V_2 ;
V_26:
return NULL ;
}
