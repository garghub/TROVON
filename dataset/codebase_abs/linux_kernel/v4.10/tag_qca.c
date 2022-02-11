static struct V_1 * F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_1 * V_7 , V_8 ;
V_4 -> V_9 . V_10 ++ ;
V_4 -> V_9 . V_11 += V_2 -> V_12 ;
if ( F_3 ( V_2 , 0 ) < 0 )
goto V_13;
F_4 ( V_2 , V_14 ) ;
memmove ( V_2 -> V_15 , V_2 -> V_15 + V_14 , 2 * V_16 ) ;
V_7 = ( T_1 * ) ( V_2 -> V_15 + 2 * V_16 ) ;
V_8 = V_17 << V_18 |
V_19 |
F_5 ( V_6 -> V_20 ) ;
* V_7 = F_6 ( V_8 ) ;
return V_2 ;
V_13:
F_7 ( V_2 ) ;
return NULL ;
}
static int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_21 * V_22 , struct V_3 * V_23 )
{
struct V_24 * V_25 = V_4 -> V_26 ;
struct V_27 * V_28 ;
T_2 V_29 ;
int V_20 ;
T_3 * V_7 , V_8 ;
if ( F_9 ( ! V_25 ) )
goto V_30;
V_2 = F_10 ( V_2 , V_31 ) ;
if ( ! V_2 )
goto V_32;
if ( F_9 ( ! F_11 ( V_2 , V_14 ) ) )
goto V_30;
V_7 = ( T_3 * ) ( V_2 -> V_15 - 2 ) ;
V_8 = F_12 ( * V_7 ) ;
V_29 = ( V_8 & V_33 ) >> V_34 ;
if ( F_9 ( V_29 != V_17 ) )
goto V_30;
F_13 ( V_2 , V_14 ) ;
memmove ( V_2 -> V_15 - V_35 , V_2 -> V_15 - V_35 - V_14 ,
V_35 - V_14 ) ;
V_28 = V_25 -> V_28 [ 0 ] ;
if ( ! V_28 )
goto V_30;
V_20 = ( V_8 & V_36 ) ;
if ( ! V_28 -> V_37 [ V_20 ] . V_38 )
goto V_30;
F_4 ( V_2 , V_35 ) ;
V_2 -> V_39 = V_40 ;
V_2 -> V_4 = V_28 -> V_37 [ V_20 ] . V_38 ;
V_2 -> V_41 = F_14 ( V_2 , V_2 -> V_4 ) ;
V_2 -> V_4 -> V_9 . V_42 ++ ;
V_2 -> V_4 -> V_9 . V_43 += V_2 -> V_12 ;
F_15 ( V_2 ) ;
return 0 ;
V_30:
F_7 ( V_2 ) ;
V_32:
return 0 ;
}
