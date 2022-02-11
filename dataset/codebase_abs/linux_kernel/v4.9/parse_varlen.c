static int F_1 ( void * V_1 , T_1 V_2 , void * V_3 )
{
struct V_4 * F_1 = V_1 + V_2 ;
if ( F_1 + 1 > V_3 )
return 0 ;
if ( F_1 -> V_5 == F_2 ( 80 ) || F_1 -> V_6 == F_2 ( 80 ) )
return V_7 ;
return 0 ;
}
static int F_3 ( void * V_1 , T_1 V_2 , void * V_3 )
{
struct V_8 * F_3 = V_1 + V_2 ;
if ( F_3 + 1 > V_3 )
return 0 ;
if ( F_3 -> V_5 == F_2 ( V_9 ) ||
F_3 -> V_6 == F_2 ( V_9 ) ) {
if ( V_10 ) {
char V_11 [] = L_1 ;
F_4 ( V_11 , sizeof( V_11 ) ) ;
}
return V_7 ;
}
return 0 ;
}
static int F_5 ( void * V_1 , T_1 V_12 , void * V_3 )
{
struct V_13 * V_14 ;
T_1 V_15 ;
V_14 = V_1 + V_12 ;
if ( V_14 + 1 > V_3 )
return 0 ;
if ( F_6 ( V_14 ) )
return 0 ;
V_15 = V_14 -> V_16 * 4 ;
if ( V_14 -> V_17 == V_18 ) {
V_14 = V_1 + V_12 + V_15 ;
if ( V_14 + 1 > V_3 )
return 0 ;
V_15 += V_14 -> V_16 * 4 ;
}
if ( V_14 -> V_17 == V_19 )
return F_1 ( V_1 , V_12 + V_15 , V_3 ) ;
else if ( V_14 -> V_17 == V_20 )
return F_3 ( V_1 , V_12 + V_15 , V_3 ) ;
return 0 ;
}
static int F_7 ( void * V_1 , T_1 V_12 , void * V_3 )
{
struct V_21 * V_22 ;
struct V_13 * V_14 ;
T_1 V_15 = sizeof( struct V_21 ) ;
T_1 V_23 ;
V_22 = V_1 + V_12 ;
if ( V_22 + 1 > V_3 )
return 0 ;
V_23 = V_22 -> V_23 ;
if ( V_23 == V_18 ) {
V_14 = V_1 + V_12 + V_15 ;
if ( V_14 + 1 > V_3 )
return 0 ;
V_15 += V_14 -> V_16 * 4 ;
V_23 = V_14 -> V_17 ;
} else if ( V_23 == V_24 ) {
V_22 = V_1 + V_12 + V_15 ;
if ( V_22 + 1 > V_3 )
return 0 ;
V_15 += sizeof( struct V_21 ) ;
V_23 = V_22 -> V_23 ;
}
if ( V_23 == V_19 )
return F_1 ( V_1 , V_12 + V_15 , V_3 ) ;
else if ( V_23 == V_20 )
return F_3 ( V_1 , V_12 + V_15 , V_3 ) ;
return 0 ;
}
int F_8 ( struct V_25 * V_26 )
{
void * V_1 = ( void * ) ( long ) V_26 -> V_1 ;
struct V_27 * V_28 = V_1 ;
void * V_3 = ( void * ) ( long ) V_26 -> V_3 ;
T_1 V_29 , V_12 ;
V_12 = sizeof( * V_28 ) ;
if ( V_1 + V_12 > V_3 )
return 0 ;
V_29 = V_28 -> V_29 ;
if ( V_29 == V_30 || V_29 == V_31 ) {
struct V_32 * V_33 ;
V_33 = V_1 + V_12 ;
V_12 += sizeof( struct V_32 ) ;
if ( V_1 + V_12 > V_3 )
return 0 ;
V_29 = V_33 -> V_34 ;
}
if ( V_29 == V_30 || V_29 == V_31 ) {
struct V_32 * V_33 ;
V_33 = V_1 + V_12 ;
V_12 += sizeof( struct V_32 ) ;
if ( V_1 + V_12 > V_3 )
return 0 ;
V_29 = V_33 -> V_34 ;
}
if ( V_29 == F_2 ( V_35 ) )
return F_5 ( V_1 , V_12 , V_3 ) ;
else if ( V_29 == F_2 ( V_36 ) )
return F_7 ( V_1 , V_12 , V_3 ) ;
return 0 ;
}
