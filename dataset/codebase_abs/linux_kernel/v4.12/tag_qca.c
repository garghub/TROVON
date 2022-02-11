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
F_5 ( V_6 -> V_20 -> V_21 ) ;
* V_7 = F_6 ( V_8 ) ;
return V_2 ;
V_13:
F_7 ( V_2 ) ;
return NULL ;
}
static struct V_1 * F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_22 * V_23 ,
struct V_3 * V_24 )
{
struct V_25 * V_26 = V_4 -> V_27 ;
struct V_28 * V_29 ;
T_2 V_30 ;
int V_31 ;
T_3 * V_7 , V_8 ;
if ( F_9 ( ! F_10 ( V_2 , V_14 ) ) )
goto V_32;
V_7 = ( T_3 * ) ( V_2 -> V_15 - 2 ) ;
V_8 = F_11 ( * V_7 ) ;
V_30 = ( V_8 & V_33 ) >> V_34 ;
if ( F_9 ( V_30 != V_17 ) )
goto V_32;
F_12 ( V_2 , V_14 ) ;
memmove ( V_2 -> V_15 - V_35 , V_2 -> V_15 - V_35 - V_14 ,
V_35 - V_14 ) ;
V_29 = V_26 -> V_36 ;
if ( ! V_29 )
goto V_32;
V_31 = ( V_8 & V_37 ) ;
if ( ! V_29 -> V_38 [ V_31 ] . V_39 )
goto V_32;
V_2 -> V_4 = V_29 -> V_38 [ V_31 ] . V_39 ;
return V_2 ;
V_32:
return NULL ;
}
