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
if ( V_6 -> V_16 == 8 )
V_7 [ 2 ] = V_17 ;
V_7 [ 3 ] = ( 1 << V_6 -> V_16 ) & V_18 ;
return V_2 ;
V_9:
F_5 ( V_2 ) ;
return NULL ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_19 * V_20 , struct V_3 * V_21 )
{
struct V_22 * V_23 = V_4 -> V_24 ;
struct V_25 * V_26 ;
int V_27 ;
T_1 * V_7 ;
if ( F_7 ( V_23 == NULL ) )
goto V_28;
V_26 = V_23 -> V_26 [ 0 ] ;
V_2 = F_8 ( V_2 , V_29 ) ;
if ( V_2 == NULL )
goto V_30;
if ( F_7 ( ! F_9 ( V_2 , V_8 ) ) )
goto V_28;
V_7 = V_2 -> V_10 - 2 ;
if ( F_7 ( ( V_7 [ 0 ] >> V_12 ) & V_31 ) )
goto V_28;
F_10 ( V_7 [ 2 ] & V_32 ) ;
V_27 = V_7 [ 3 ] & V_33 ;
if ( V_27 >= V_34 || ! V_26 -> V_35 [ V_27 ] . V_36 )
goto V_28;
F_11 ( V_2 , V_8 ) ;
memmove ( V_2 -> V_10 - V_37 ,
V_2 -> V_10 - V_37 - V_8 ,
2 * V_11 ) ;
F_4 ( V_2 , V_37 ) ;
V_2 -> V_38 = V_39 ;
V_2 -> V_4 = V_26 -> V_35 [ V_27 ] . V_36 ;
V_2 -> V_40 = F_12 ( V_2 , V_2 -> V_4 ) ;
V_2 -> V_4 -> V_41 . V_42 ++ ;
V_2 -> V_4 -> V_41 . V_43 += V_2 -> V_44 ;
F_13 ( V_2 ) ;
return 0 ;
V_28:
F_5 ( V_2 ) ;
V_30:
return 0 ;
}
