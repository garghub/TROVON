struct V_1 * F_1 ( struct V_2 * V_2 )
{
return V_2 -> V_1 ;
}
T_1 F_2 ( int V_3 , int V_4 , int V_5 )
{
T_1 V_6 ;
int V_7 ;
V_6 = sizeof( struct V_2 ) ;
V_6 += sizeof( struct V_1 ) + V_8 +
sizeof( struct V_9 ) +
V_4 * sizeof( struct V_10 ) ;
if ( V_3 ) {
V_6 += sizeof( struct V_1 ) + V_8 +
sizeof( struct V_9 ) +
V_5 * sizeof( struct V_10 ) ;
}
V_6 += 63 + 7 ;
if ( V_4 ) {
V_7 = 1 + ( ( V_4 * sizeof( struct V_10 ) - 1 )
>> V_11 ) ;
V_6 += V_7 * sizeof( struct V_10 ) ;
}
if ( V_5 ) {
V_7 = 1 + ( ( V_5 * sizeof( struct V_10 ) - 1 )
>> V_11 ) ;
V_6 += V_7 * sizeof( struct V_10 ) ;
}
return V_6 ;
}
static inline void * F_3 ( T_2 * V_12 , T_2 V_13 , T_1 V_6 ,
int V_14 , int V_15 )
{
T_2 V_16 ;
V_16 = F_4 ( * V_12 , V_14 ) ;
if ( V_15 && F_5 ( V_16 , V_6 ) ) {
V_16 = F_4 ( V_16 , 4096 ) ;
V_16 = F_4 ( V_16 , V_14 ) ;
}
if ( V_16 + V_6 > V_13 )
return F_6 ( - V_17 ) ;
* V_12 = V_16 + V_6 ;
return ( void * ) V_16 ;
}
struct V_2 * F_7 ( void * V_18 , T_1 V_19 , int V_20 , int V_3 ,
int V_4 , int V_5 )
{
struct V_2 * V_2 ;
void * V_21 ;
T_2 V_12 ;
T_2 V_13 ;
int V_7 ;
V_12 = ( T_2 ) V_18 ;
V_13 = V_12 + V_19 ;
if ( V_13 > ( 1 << 31 ) )
return F_6 ( - V_22 ) ;
memset ( V_18 , 0 , V_19 ) ;
V_21 = F_3 ( & V_12 , V_13 , sizeof( struct V_2 ) , 1 , 0 ) ;
if ( F_8 ( V_21 ) )
return V_21 ;
V_2 = V_21 ;
V_7 = 0 ;
if ( V_4 )
V_7 = 1 + ( ( V_4 * sizeof( struct V_10 ) - 1 )
>> V_11 ) ;
V_2 -> V_4 = V_4 + V_7 ;
V_7 = 0 ;
if ( V_5 )
V_7 = 1 + ( ( V_5 * sizeof( struct V_10 ) - 1 )
>> V_11 ) ;
V_2 -> V_5 = V_5 + V_7 ;
V_21 = F_3 ( & V_12 , V_13 , sizeof( struct V_1 ) , 64 , 0 ) ;
if ( F_8 ( V_21 ) )
return V_21 ;
V_2 -> V_1 = V_21 ;
F_9 ( V_2 -> V_1 , ( V_20 == V_23 ) ? 1 : 0 ,
( V_20 == V_24 ) ? 1 : 0 ) ;
if ( V_3 ) {
V_21 = F_3 ( & V_12 , V_13 , sizeof( struct V_1 ) , 64 , 0 ) ;
if ( F_8 ( V_21 ) )
return V_21 ;
V_2 -> V_25 = V_21 ;
F_9 ( V_2 -> V_25 , 1 , 0 ) ;
F_10 ( V_2 -> V_1 , V_2 -> V_25 ) ;
}
if ( V_4 > 0 ) {
V_21 = F_3 ( & V_12 , V_13 , sizeof( struct V_10 ) *
V_2 -> V_4 , 16 , 0 ) ;
if ( F_8 ( V_21 ) )
return V_21 ;
F_11 ( V_2 -> V_1 , V_21 , 1 ) ;
}
if ( V_3 && ( V_5 > 0 ) ) {
V_21 = F_3 ( & V_12 , V_13 , sizeof( struct V_10 ) *
V_2 -> V_5 , 16 , 0 ) ;
if ( F_8 ( V_21 ) )
return V_21 ;
F_11 ( V_2 -> V_25 , V_21 , 1 ) ;
}
V_21 = F_3 ( & V_12 , V_13 , sizeof( struct V_9 ) , 8 , 0 ) ;
if ( F_8 ( V_21 ) )
return V_21 ;
F_12 ( V_21 ) ;
F_13 ( V_2 -> V_1 , V_21 ) ;
if ( V_3 ) {
V_21 = F_3 ( & V_12 , V_13 , sizeof( struct V_9 ) , 8 , 0 ) ;
if ( F_8 ( V_21 ) )
return V_21 ;
F_12 ( V_21 ) ;
F_13 ( V_2 -> V_25 , V_21 ) ;
}
V_21 = F_3 ( & V_12 , V_13 , V_8 , 8 , 0 ) ;
if ( F_8 ( V_21 ) )
return V_21 ;
F_14 ( V_21 , V_8 , V_26 ) ;
F_15 ( V_2 -> V_1 , V_21 ) ;
if ( V_3 ) {
V_21 = F_3 ( & V_12 , V_13 , V_8 , 8 , 0 ) ;
if ( F_8 ( V_21 ) )
return V_21 ;
F_14 ( V_21 , V_8 , V_27 ) ;
F_15 ( V_2 -> V_25 , V_21 ) ;
F_16 ( V_21 , V_8 , V_28 , 0 , NULL ,
sizeof( struct V_29 ) , 0 ) ;
F_17 ( V_2 -> V_25 , 0 ) ;
}
return V_2 ;
}
struct V_30 * F_18 ( struct V_2 * V_2 , T_3 V_31 , T_3 V_32 , void * V_33 ,
T_3 V_34 , T_4 V_35 )
{
return F_16 ( F_19 ( V_2 -> V_1 ) , V_8 , V_31 ,
V_32 , V_33 , V_34 , V_35 ) ;
}
struct V_10 * F_20 ( struct V_2 * V_2 , T_3 V_32 , void * V_16 , T_4 V_35 )
{
struct V_10 * V_36 ;
if ( V_2 -> V_37 >= V_2 -> V_4 )
return F_6 ( - V_17 ) ;
V_36 = ( (struct V_10 * ) F_21 ( V_2 -> V_1 ) )
+ V_2 -> V_37 + 1 ;
if ( V_2 -> V_37 && ! ( ( unsigned long ) V_36 & ~ V_38 ) ) {
F_22 ( V_2 -> V_1 , V_2 -> V_37 ++ ,
V_39 , V_36 , 0 ) ;
if ( V_2 -> V_37 >= V_2 -> V_4 )
return F_6 ( - V_17 ) ;
}
return F_22 ( V_2 -> V_1 , V_2 -> V_37 ++ , V_32 , V_16 , V_35 ) ;
}
void F_23 ( struct V_2 * V_2 , void * V_16 , int V_40 )
{
F_11 ( V_2 -> V_1 , V_16 , V_40 ) ;
}
void F_24 ( struct V_2 * V_2 )
{
F_17 ( V_2 -> V_1 , V_2 -> V_37 ) ;
}
