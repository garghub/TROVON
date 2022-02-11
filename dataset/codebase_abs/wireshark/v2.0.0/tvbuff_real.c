static void
F_1 ( T_1 * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
if ( V_3 -> V_4 ) {
V_3 -> V_4 ( ( V_5 ) V_1 -> V_6 ) ;
}
}
static T_2
F_2 ( const T_1 * V_1 V_7 , const T_2 V_8 )
{
return V_8 ;
}
T_1 *
F_3 ( const T_3 * V_9 , const T_2 V_10 , const T_4 V_11 )
{
T_1 * V_1 ;
struct V_2 * V_3 ;
F_4 ( V_11 < - 1 , V_12 ) ;
V_1 = F_5 ( & V_13 ) ;
V_1 -> V_6 = V_9 ;
V_1 -> V_10 = V_10 ;
V_1 -> V_11 = V_11 ;
V_1 -> V_14 = TRUE ;
V_1 -> V_15 = V_1 ;
V_3 = (struct V_2 * ) V_1 ;
V_3 -> V_4 = NULL ;
return V_1 ;
}
void
F_6 ( T_1 * V_1 , const T_5 V_16 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_7 ( V_1 ) ;
F_7 ( V_1 -> V_17 == & V_13 ) ;
V_3 -> V_4 = V_16 ;
}
void
F_8 ( T_1 * V_18 , T_1 * V_19 )
{
F_7 ( V_18 && V_19 ) ;
F_7 ( V_18 -> V_14 ) ;
F_7 ( V_19 -> V_14 ) ;
F_7 ( V_19 -> V_17 == & V_13 ) ;
F_9 ( V_18 , V_19 ) ;
}
T_1 *
F_10 ( T_1 * V_18 , const T_3 * V_9 , const T_2 V_10 , const T_4 V_11 )
{
T_1 * V_1 = F_3 ( V_9 , V_10 , V_11 ) ;
F_8 ( V_18 , V_1 ) ;
return V_1 ;
}
