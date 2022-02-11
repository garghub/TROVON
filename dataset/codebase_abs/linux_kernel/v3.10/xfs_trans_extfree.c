T_1 *
F_1 ( T_2 * V_1 ,
T_3 V_2 )
{
T_1 * V_3 ;
ASSERT ( V_1 != NULL ) ;
ASSERT ( V_2 > 0 ) ;
V_3 = F_2 ( V_1 -> V_4 , V_2 ) ;
ASSERT ( V_3 != NULL ) ;
F_3 ( V_1 , & V_3 -> V_5 ) ;
return V_3 ;
}
void
F_4 ( T_2 * V_1 ,
T_1 * V_3 ,
T_4 V_6 ,
T_5 V_7 )
{
T_3 V_8 ;
T_6 * V_9 ;
V_1 -> V_10 |= V_11 ;
V_3 -> V_5 . V_12 -> V_13 |= V_14 ;
V_8 = F_5 ( & V_3 -> V_15 ) - 1 ;
ASSERT ( V_8 < V_3 -> V_16 . V_17 ) ;
V_9 = & ( V_3 -> V_16 . V_18 [ V_8 ] ) ;
V_9 -> V_19 = V_6 ;
V_9 -> V_7 = V_7 ;
}
T_7 *
F_6 ( T_2 * V_1 ,
T_1 * V_3 ,
T_3 V_2 )
{
T_7 * V_20 ;
ASSERT ( V_1 != NULL ) ;
ASSERT ( V_2 > 0 ) ;
V_20 = F_7 ( V_1 -> V_4 , V_3 , V_2 ) ;
ASSERT ( V_20 != NULL ) ;
F_3 ( V_1 , & V_20 -> V_21 ) ;
return V_20 ;
}
void
F_8 ( T_2 * V_1 ,
T_7 * V_20 ,
T_4 V_6 ,
T_5 V_7 )
{
T_3 V_8 ;
T_6 * V_9 ;
V_1 -> V_10 |= V_11 ;
V_20 -> V_21 . V_12 -> V_13 |= V_14 ;
V_8 = V_20 -> V_22 ;
ASSERT ( V_8 < V_20 -> V_23 . V_24 ) ;
V_9 = & ( V_20 -> V_23 . V_25 [ V_8 ] ) ;
V_9 -> V_19 = V_6 ;
V_9 -> V_7 = V_7 ;
V_20 -> V_22 ++ ;
}
