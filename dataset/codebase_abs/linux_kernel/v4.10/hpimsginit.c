static void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
T_1 V_5 ;
if ( ( V_3 > 0 ) && ( V_3 <= V_6 ) )
V_5 = V_7 [ V_3 ] ;
else
V_5 = sizeof( * V_2 ) ;
memset ( V_2 , 0 , V_5 ) ;
V_2 -> V_5 = V_5 ;
if ( V_8 )
V_2 -> type = V_9 ;
else
V_2 -> type = V_10 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_11 = 0 ;
V_2 -> V_12 = V_13 ;
}
void F_2 ( struct V_14 * V_15 , T_1 V_3 , T_1 V_4 ,
T_1 error )
{
T_1 V_5 ;
if ( ( V_3 > 0 ) && ( V_3 <= V_6 ) )
V_5 = V_16 [ V_3 ] ;
else
V_5 = sizeof( * V_15 ) ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_5 = V_5 ;
V_15 -> type = V_17 ;
V_15 -> V_3 = V_3 ;
V_15 -> V_4 = V_4 ;
V_15 -> error = error ;
V_15 -> V_18 = 0 ;
V_15 -> V_11 = 0 ;
}
void F_3 ( struct V_1 * V_2 ,
struct V_14 * V_15 , T_1 V_3 , T_1 V_4 )
{
F_1 ( V_2 , V_3 , V_4 ) ;
F_2 ( V_15 , V_3 , V_4 ,
V_19 ) ;
}
static void F_4 ( struct V_20 * V_2 , T_1 V_5 ,
T_1 V_3 , T_1 V_4 )
{
memset ( V_2 , 0 , V_5 ) ;
if ( ( V_3 > 0 ) && ( V_3 <= V_6 ) ) {
V_2 -> V_5 = V_5 ;
V_2 -> type = V_10 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_11 = 1 ;
}
}
void F_5 ( struct V_21 * V_15 , T_1 V_5 ,
T_1 V_3 , T_1 V_4 )
{
( void ) V_3 ;
( void ) V_4 ;
memset ( V_15 , 0 , V_5 ) ;
V_15 -> V_5 = V_5 ;
V_15 -> V_11 = 1 ;
V_15 -> type = V_17 ;
V_15 -> error = V_19 ;
}
void F_6 ( struct V_20 * V_2 , T_1 V_7 ,
struct V_21 * V_15 , T_1 V_16 , T_1 V_3 ,
T_1 V_4 )
{
F_4 ( V_2 , V_7 , V_3 , V_4 ) ;
F_5 ( V_15 , V_16 , V_3 , V_4 ) ;
}
