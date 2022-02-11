static struct V_1 * F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_1 * V_7 , V_8 ;
V_4 -> V_9 . V_10 ++ ;
V_4 -> V_9 . V_11 += V_2 -> V_12 ;
if ( F_3 ( V_2 , 0 ) < 0 )
return NULL ;
F_4 ( V_2 , V_13 ) ;
memmove ( V_2 -> V_14 , V_2 -> V_14 + V_13 , 2 * V_15 ) ;
V_7 = ( T_1 * ) ( V_2 -> V_14 + 2 * V_15 ) ;
V_8 = V_16 << V_17 |
V_18 |
F_5 ( V_6 -> V_19 -> V_20 ) ;
* V_7 = F_6 ( V_8 ) ;
return V_2 ;
}
static struct V_1 * F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_26 * V_27 = F_8 ( V_24 ) ;
struct V_28 * V_29 ;
T_2 V_30 ;
int V_31 ;
T_3 * V_7 , V_8 ;
if ( F_9 ( ! F_10 ( V_2 , V_13 ) ) )
return NULL ;
V_7 = ( T_3 * ) ( V_2 -> V_14 - 2 ) ;
V_8 = F_11 ( * V_7 ) ;
V_30 = ( V_8 & V_32 ) >> V_33 ;
if ( F_9 ( V_30 != V_16 ) )
return NULL ;
F_12 ( V_2 , V_13 ) ;
memmove ( V_2 -> V_14 - V_34 , V_2 -> V_14 - V_34 - V_13 ,
V_34 - V_13 ) ;
V_29 = V_27 -> V_29 ;
if ( ! V_29 )
return NULL ;
V_31 = ( V_8 & V_35 ) ;
if ( ! V_29 -> V_36 [ V_31 ] . V_37 )
return NULL ;
V_2 -> V_4 = V_29 -> V_36 [ V_31 ] . V_37 ;
return V_2 ;
}
