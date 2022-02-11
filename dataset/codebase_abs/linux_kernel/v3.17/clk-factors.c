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
V_9 = ( V_3 * ( V_4 + V_13 -> V_23 ) * ( V_5 + 1 ) >> V_6 ) / ( V_7 + 1 ) ;
return V_9 ;
}
static long F_5 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long * V_3 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
V_11 -> V_24 ( ( T_2 * ) & V_9 , ( T_2 ) * V_3 ,
NULL , NULL , NULL , NULL ) ;
return V_9 ;
}
static long F_6 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long * V_25 ,
struct V_26 * * V_27 )
{
struct V_26 * V_26 = V_2 -> V_26 , * V_28 , * V_29 = NULL ;
int V_30 , V_31 ;
unsigned long V_3 , V_32 = 0 , V_33 , V_34 = 0 ;
V_31 = F_7 ( V_26 ) ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
V_28 = F_8 ( V_26 , V_30 ) ;
if ( ! V_28 )
continue;
if ( F_9 ( V_26 ) & V_35 )
V_3 = F_10 ( V_28 , V_9 ) ;
else
V_3 = F_11 ( V_28 ) ;
V_33 = F_5 ( V_2 , V_9 , & V_3 ) ;
if ( V_33 <= V_9 && V_33 > V_34 ) {
V_29 = V_28 ;
V_32 = V_3 ;
V_34 = V_33 ;
}
}
if ( V_29 )
* V_27 = V_29 ;
* V_25 = V_32 ;
return V_34 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long V_3 )
{
T_1 V_4 = 0 , V_5 = 0 , V_7 = 0 , V_6 = 0 ;
T_2 V_8 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_13 ;
unsigned long V_36 = 0 ;
V_11 -> V_24 ( ( T_2 * ) & V_9 , ( T_2 ) V_3 , & V_4 , & V_5 , & V_7 , & V_6 ) ;
if ( V_11 -> V_37 )
F_13 ( V_11 -> V_37 , V_36 ) ;
V_8 = F_3 ( V_11 -> V_8 ) ;
V_8 = F_14 ( V_13 -> V_16 , V_13 -> V_14 , V_8 , V_4 ) ;
V_8 = F_14 ( V_13 -> V_18 , V_13 -> V_17 , V_8 , V_5 ) ;
V_8 = F_14 ( V_13 -> V_20 , V_13 -> V_19 , V_8 , V_7 ) ;
V_8 = F_14 ( V_13 -> V_22 , V_13 -> V_21 , V_8 , V_6 ) ;
F_15 ( V_8 , V_11 -> V_8 ) ;
F_16 ( ( V_9 >> 20 ) * 500 / 2 ) ;
if ( V_11 -> V_37 )
F_17 ( V_11 -> V_37 , V_36 ) ;
return 0 ;
}
