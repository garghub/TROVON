int F_1 ( struct V_1 * V_2 , const T_1 * V_3 , unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 = F_3 ( V_2 -> V_8 ) ;
unsigned int V_9 , V_10 ;
V_9 = V_6 -> V_11 & ( V_7 - 1 ) ;
V_6 -> V_11 += V_4 ;
if ( ( V_9 + V_4 ) < V_7 )
goto V_12;
if ( V_9 ) {
memcpy ( V_6 -> V_13 + V_9 , V_3 , V_7 - V_9 ) ;
F_4 ( V_6 -> V_14 , V_6 -> V_15 , V_6 -> V_13 , V_7 ) ;
V_3 += V_7 - V_9 ;
V_4 -= V_7 - V_9 ;
V_9 = 0 ;
}
if ( V_4 >= V_7 ) {
V_10 = V_4 & ~ ( V_7 - 1 ) ;
F_4 ( V_6 -> V_14 , V_6 -> V_15 , V_3 , V_10 ) ;
V_3 += V_10 ;
V_4 -= V_10 ;
}
V_12:
if ( V_4 )
memcpy ( V_6 -> V_13 + V_9 , V_3 , V_4 ) ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 , T_1 * V_16 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 = F_3 ( V_2 -> V_8 ) ;
T_2 V_17 ;
unsigned int V_9 , V_18 , V_19 ;
V_19 = ( V_7 > V_20 ) ? 16 : 8 ;
V_9 = V_6 -> V_11 & ( V_7 - 1 ) ;
V_18 = ( V_9 < V_7 - V_19 ) ? V_7 : ( 2 * V_7 ) ;
V_6 -> V_13 [ V_9 ] = 0x80 ;
V_9 ++ ;
memset ( V_6 -> V_13 + V_9 , 0x00 , V_18 - V_9 - 8 ) ;
V_17 = V_6 -> V_11 * 8 ;
memcpy ( V_6 -> V_13 + V_18 - 8 , & V_17 , sizeof( V_17 ) ) ;
F_4 ( V_6 -> V_14 , V_6 -> V_15 , V_6 -> V_13 , V_18 ) ;
memcpy ( V_16 , V_6 -> V_15 , F_6 ( V_2 -> V_8 ) ) ;
memset ( V_6 , 0 , sizeof *V_6 ) ;
return 0 ;
}
