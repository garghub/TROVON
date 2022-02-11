struct V_1 * F_1 ( int V_2 , int V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( struct V_1 ) , V_5 , V_3 ) ;
if ( V_4 != NULL ) {
F_3 ( & V_4 -> V_6 ) ;
F_4 ( & V_4 -> V_7 ) ;
V_4 -> V_2 = V_2 ;
}
return V_4 ;
}
int F_5 ( struct V_1 * V_4 , unsigned long V_8 , T_1 V_9 ,
T_2 V_10 , int V_3 )
{
struct V_11 * V_12 ;
int V_13 = V_10 >> V_4 -> V_2 ;
int V_14 = sizeof( struct V_11 ) +
( V_13 + V_15 - 1 ) / V_15 ;
V_12 = F_2 ( V_14 , V_5 | V_16 , V_3 ) ;
if ( F_6 ( V_12 == NULL ) )
return - V_17 ;
F_7 ( & V_12 -> V_6 ) ;
V_12 -> V_18 = V_9 ;
V_12 -> V_19 = V_8 ;
V_12 -> V_20 = V_8 + V_10 ;
F_8 ( & V_4 -> V_6 ) ;
F_9 ( & V_12 -> V_21 , & V_4 -> V_7 ) ;
F_10 ( & V_4 -> V_6 ) ;
return 0 ;
}
T_1 F_11 ( struct V_1 * V_4 , unsigned long V_22 )
{
struct V_23 * V_24 ;
struct V_11 * V_12 ;
F_12 ( & V_4 -> V_6 ) ;
F_13 (_chunk, &pool->chunks) {
V_12 = F_14 ( V_24 , struct V_11 , V_21 ) ;
if ( V_22 >= V_12 -> V_19 && V_22 < V_12 -> V_20 )
return V_12 -> V_18 + V_22 - V_12 -> V_19 ;
}
F_15 ( & V_4 -> V_6 ) ;
return - 1 ;
}
void F_16 ( struct V_1 * V_4 )
{
struct V_23 * V_24 , * V_25 ;
struct V_11 * V_12 ;
int V_26 = V_4 -> V_2 ;
int V_27 , V_28 ;
F_17 (_chunk, _next_chunk, &pool->chunks) {
V_12 = F_14 ( V_24 , struct V_11 , V_21 ) ;
F_18 ( & V_12 -> V_21 ) ;
V_28 = ( V_12 -> V_20 - V_12 -> V_19 ) >> V_26 ;
V_27 = F_19 ( V_12 -> V_29 , V_28 , 0 ) ;
F_20 ( V_27 < V_28 ) ;
F_21 ( V_12 ) ;
}
F_21 ( V_4 ) ;
return;
}
unsigned long F_22 ( struct V_1 * V_4 , T_2 V_10 )
{
struct V_23 * V_24 ;
struct V_11 * V_12 ;
unsigned long V_22 , V_30 ;
int V_26 = V_4 -> V_2 ;
int V_13 , V_31 , V_28 ;
if ( V_10 == 0 )
return 0 ;
V_13 = ( V_10 + ( 1UL << V_26 ) - 1 ) >> V_26 ;
F_12 ( & V_4 -> V_6 ) ;
F_13 (_chunk, &pool->chunks) {
V_12 = F_14 ( V_24 , struct V_11 , V_21 ) ;
V_28 = ( V_12 -> V_20 - V_12 -> V_19 ) >> V_26 ;
F_23 ( & V_12 -> V_6 , V_30 ) ;
V_31 = F_24 ( V_12 -> V_29 , V_28 , 0 ,
V_13 , 0 ) ;
if ( V_31 >= V_28 ) {
F_25 ( & V_12 -> V_6 , V_30 ) ;
continue;
}
V_22 = V_12 -> V_19 + ( ( unsigned long ) V_31 << V_26 ) ;
F_26 ( V_12 -> V_29 , V_31 , V_13 ) ;
F_25 ( & V_12 -> V_6 , V_30 ) ;
F_15 ( & V_4 -> V_6 ) ;
return V_22 ;
}
F_15 ( & V_4 -> V_6 ) ;
return 0 ;
}
void F_27 ( struct V_1 * V_4 , unsigned long V_22 , T_2 V_10 )
{
struct V_23 * V_24 ;
struct V_11 * V_12 ;
unsigned long V_30 ;
int V_26 = V_4 -> V_2 ;
int V_27 , V_13 ;
V_13 = ( V_10 + ( 1UL << V_26 ) - 1 ) >> V_26 ;
F_12 ( & V_4 -> V_6 ) ;
F_13 (_chunk, &pool->chunks) {
V_12 = F_14 ( V_24 , struct V_11 , V_21 ) ;
if ( V_22 >= V_12 -> V_19 && V_22 < V_12 -> V_20 ) {
F_20 ( V_22 + V_10 > V_12 -> V_20 ) ;
F_23 ( & V_12 -> V_6 , V_30 ) ;
V_27 = ( V_22 - V_12 -> V_19 ) >> V_26 ;
while ( V_13 -- )
F_28 ( V_27 ++ , V_12 -> V_29 ) ;
F_25 ( & V_12 -> V_6 , V_30 ) ;
break;
}
}
F_20 ( V_13 > 0 ) ;
F_15 ( & V_4 -> V_6 ) ;
}
