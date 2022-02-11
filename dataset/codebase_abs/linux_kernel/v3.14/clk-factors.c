static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
T_1 V_4 = 1 , V_5 = 0 , V_6 = 0 , V_7 = 0 ;
T_2 V_8 ;
unsigned long V_9 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_13 ;
V_8 = F_3 ( V_11 -> V_8 ) ;
if ( V_13 -> V_14 != V_15 )
V_4 = F_4 ( V_13 -> V_16 , V_13 -> V_14 , V_8 ) ;
if ( V_13 -> V_17 != V_15 )
V_5 = F_4 ( V_13 -> V_18 , V_13 -> V_17 , V_8 ) ;
if ( V_13 -> V_19 != V_15 )
V_7 = F_4 ( V_13 -> V_20 , V_13 -> V_19 , V_8 ) ;
if ( V_13 -> V_21 != V_15 )
V_6 = F_4 ( V_13 -> V_22 , V_13 -> V_21 , V_8 ) ;
V_9 = ( V_3 * V_4 * ( V_5 + 1 ) >> V_6 ) / ( V_7 + 1 ) ;
return V_9 ;
}
static long F_5 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long * V_3 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
V_11 -> V_23 ( ( T_2 * ) & V_9 , ( T_2 ) * V_3 ,
NULL , NULL , NULL , NULL ) ;
return V_9 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long V_3 )
{
T_1 V_4 = 0 , V_5 = 0 , V_7 = 0 , V_6 = 0 ;
T_2 V_8 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_13 ;
unsigned long V_24 = 0 ;
V_11 -> V_23 ( ( T_2 * ) & V_9 , ( T_2 ) V_3 , & V_4 , & V_5 , & V_7 , & V_6 ) ;
if ( V_11 -> V_25 )
F_7 ( V_11 -> V_25 , V_24 ) ;
V_8 = F_3 ( V_11 -> V_8 ) ;
V_8 = F_8 ( V_13 -> V_16 , V_13 -> V_14 , V_8 , V_4 ) ;
V_8 = F_8 ( V_13 -> V_18 , V_13 -> V_17 , V_8 , V_5 ) ;
V_8 = F_8 ( V_13 -> V_20 , V_13 -> V_19 , V_8 , V_7 ) ;
V_8 = F_8 ( V_13 -> V_22 , V_13 -> V_21 , V_8 , V_6 ) ;
F_9 ( V_8 , V_11 -> V_8 ) ;
F_10 ( ( V_9 >> 20 ) * 500 / 2 ) ;
if ( V_11 -> V_25 )
F_11 ( V_11 -> V_25 , V_24 ) ;
return 0 ;
}
