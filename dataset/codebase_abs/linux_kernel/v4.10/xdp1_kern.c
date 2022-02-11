static int F_1 ( void * V_1 , T_1 V_2 , void * V_3 )
{
struct V_4 * V_5 = V_1 + V_2 ;
if ( V_5 + 1 > V_3 )
return 0 ;
return V_5 -> V_6 ;
}
static int F_2 ( void * V_1 , T_1 V_2 , void * V_3 )
{
struct V_7 * V_8 = V_1 + V_2 ;
if ( V_8 + 1 > V_3 )
return 0 ;
return V_8 -> V_9 ;
}
int F_3 ( struct V_10 * V_11 )
{
void * V_3 = ( void * ) ( long ) V_11 -> V_3 ;
void * V_1 = ( void * ) ( long ) V_11 -> V_1 ;
struct V_12 * V_13 = V_1 ;
int V_14 = V_15 ;
long * V_16 ;
T_2 V_17 ;
T_1 V_2 ;
T_3 V_18 ;
V_2 = sizeof( * V_13 ) ;
if ( V_1 + V_2 > V_3 )
return V_14 ;
V_17 = V_13 -> V_17 ;
if ( V_17 == F_4 ( V_19 ) || V_17 == F_4 ( V_20 ) ) {
struct V_21 * V_22 ;
V_22 = V_1 + V_2 ;
V_2 += sizeof( struct V_21 ) ;
if ( V_1 + V_2 > V_3 )
return V_14 ;
V_17 = V_22 -> V_23 ;
}
if ( V_17 == F_4 ( V_19 ) || V_17 == F_4 ( V_20 ) ) {
struct V_21 * V_22 ;
V_22 = V_1 + V_2 ;
V_2 += sizeof( struct V_21 ) ;
if ( V_1 + V_2 > V_3 )
return V_14 ;
V_17 = V_22 -> V_23 ;
}
if ( V_17 == F_4 ( V_24 ) )
V_18 = F_1 ( V_1 , V_2 , V_3 ) ;
else if ( V_17 == F_4 ( V_25 ) )
V_18 = F_2 ( V_1 , V_2 , V_3 ) ;
else
V_18 = 0 ;
V_16 = F_5 ( & V_26 , & V_18 ) ;
if ( V_16 )
* V_16 += 1 ;
return V_14 ;
}
