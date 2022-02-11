static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_2 * V_7 ;
V_4 -> V_8 . V_9 ++ ;
V_4 -> V_8 . V_10 += V_2 -> V_11 ;
if ( F_3 ( V_2 , V_12 ) < 0 )
goto V_13;
F_4 ( V_2 , V_12 ) ;
memmove ( V_2 -> V_14 , V_2 -> V_14 + V_12 , 2 * V_15 ) ;
V_7 = V_2 -> V_14 + 2 * V_15 ;
V_7 [ 0 ] = ( 1 << V_16 ) |
( ( V_2 -> V_17 << V_18 ) & V_19 ) ;
V_7 [ 1 ] = 0 ;
V_7 [ 2 ] = 0 ;
if ( V_6 -> V_20 == 8 )
V_7 [ 2 ] = V_21 ;
V_7 [ 3 ] = ( 1 << V_6 -> V_20 ) & V_22 ;
V_2 -> V_4 = V_6 -> V_23 -> V_24 -> V_25 ;
F_5 ( V_2 ) ;
return V_26 ;
V_13:
F_6 ( V_2 ) ;
return V_26 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_27 * V_28 , struct V_3 * V_29 )
{
struct V_30 * V_24 = V_4 -> V_31 ;
struct V_32 * V_33 ;
int V_34 ;
T_2 * V_7 ;
if ( F_8 ( V_24 == NULL ) )
goto V_35;
V_33 = V_24 -> V_33 [ 0 ] ;
V_2 = F_9 ( V_2 , V_36 ) ;
if ( V_2 == NULL )
goto V_37;
if ( F_8 ( ! F_10 ( V_2 , V_12 ) ) )
goto V_35;
V_7 = V_2 -> V_14 - 2 ;
if ( F_8 ( ( V_7 [ 0 ] >> V_16 ) & V_38 ) )
goto V_35;
F_11 ( V_7 [ 2 ] & V_39 ) ;
V_34 = V_7 [ 3 ] & V_40 ;
if ( V_34 >= V_41 || V_33 -> V_42 [ V_34 ] == NULL )
goto V_35;
F_12 ( V_2 , V_12 ) ;
memmove ( V_2 -> V_14 - V_43 ,
V_2 -> V_14 - V_43 - V_12 ,
2 * V_15 ) ;
F_4 ( V_2 , V_43 ) ;
V_2 -> V_44 = V_45 ;
V_2 -> V_4 = V_33 -> V_42 [ V_34 ] ;
V_2 -> V_46 = F_13 ( V_2 , V_2 -> V_4 ) ;
V_2 -> V_4 -> V_8 . V_47 ++ ;
V_2 -> V_4 -> V_8 . V_48 += V_2 -> V_11 ;
F_14 ( V_2 ) ;
return 0 ;
V_35:
F_6 ( V_2 ) ;
V_37:
return 0 ;
}
