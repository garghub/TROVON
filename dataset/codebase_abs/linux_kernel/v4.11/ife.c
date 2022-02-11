void * F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 = V_3 + V_5 ;
int V_6 = V_4 + V_2 -> V_7 -> V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
int V_13 = 0 ;
int V_14 ;
V_14 = F_2 ( V_2 , V_6 ) ;
if ( F_3 ( V_14 ) )
return NULL ;
V_12 = (struct V_11 * ) V_2 -> V_15 ;
F_4 ( V_2 , V_6 ) ;
memcpy ( V_2 -> V_15 , V_12 , V_2 -> V_7 -> V_8 ) ;
F_5 ( V_2 ) ;
V_13 += V_2 -> V_7 -> V_8 ;
V_10 = (struct V_9 * ) ( V_2 -> V_15 + V_13 ) ;
V_3 += V_5 ;
V_10 -> V_3 = F_6 ( V_3 ) ;
return V_10 -> V_16 ;
}
void * F_7 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_9 * V_10 ;
int V_17 ;
T_1 V_18 ;
V_10 = (struct V_9 * ) ( V_2 -> V_15 + V_2 -> V_7 -> V_8 ) ;
V_18 = F_8 ( V_10 -> V_3 ) ;
V_17 = V_2 -> V_7 -> V_8 + V_18 ;
if ( F_3 ( V_18 < 2 ) )
return NULL ;
if ( F_3 ( ! F_9 ( V_2 , V_17 ) ) )
return NULL ;
F_10 ( V_2 , V_17 ) ;
F_11 ( V_2 , V_17 ) ;
* V_3 = V_18 - V_5 ;
return & V_10 -> V_16 ;
}
void * F_12 ( void * V_19 , T_1 * V_20 , T_1 * V_21 , T_1 * V_22 )
{
struct V_23 * V_24 = (struct V_23 * ) V_19 ;
* V_21 = F_8 ( V_24 -> V_25 ) - V_26 ;
* V_20 = F_8 ( V_24 -> type ) ;
if ( V_22 )
* V_22 = F_13 ( * V_21 ) ;
return V_19 + sizeof( struct V_23 ) ;
}
void * F_14 ( void * V_19 )
{
struct V_23 * V_24 = (struct V_23 * ) V_19 ;
T_1 V_27 = F_8 ( V_24 -> V_25 ) ;
V_27 = F_15 ( V_27 ) ;
return V_19 + V_27 ;
}
int F_16 ( void * V_19 , T_1 V_20 , T_1 V_21 , const void * V_28 )
{
T_2 * V_24 = ( T_2 * ) ( V_19 ) ;
T_1 V_22 = F_13 ( V_21 ) ;
char * V_29 = ( char * ) V_24 + V_26 ;
T_3 V_30 = V_20 << 16 | ( V_21 + V_26 ) ;
* V_24 = F_17 ( V_30 ) ;
memset ( V_29 , 0 , V_22 - V_26 ) ;
memcpy ( V_29 , V_28 , V_21 ) ;
return V_22 ;
}
