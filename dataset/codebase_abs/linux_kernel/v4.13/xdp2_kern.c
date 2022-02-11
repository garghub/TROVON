static void F_1 ( void * V_1 )
{
unsigned short * V_2 = V_1 ;
unsigned short V_3 [ 3 ] ;
V_3 [ 0 ] = V_2 [ 0 ] ;
V_3 [ 1 ] = V_2 [ 1 ] ;
V_3 [ 2 ] = V_2 [ 2 ] ;
V_2 [ 0 ] = V_2 [ 3 ] ;
V_2 [ 1 ] = V_2 [ 4 ] ;
V_2 [ 2 ] = V_2 [ 5 ] ;
V_2 [ 3 ] = V_3 [ 0 ] ;
V_2 [ 4 ] = V_3 [ 1 ] ;
V_2 [ 5 ] = V_3 [ 2 ] ;
}
static int F_2 ( void * V_1 , T_1 V_4 , void * V_5 )
{
struct V_6 * V_7 = V_1 + V_4 ;
if ( V_7 + 1 > V_5 )
return 0 ;
return V_7 -> V_8 ;
}
static int F_3 ( void * V_1 , T_1 V_4 , void * V_5 )
{
struct V_9 * V_10 = V_1 + V_4 ;
if ( V_10 + 1 > V_5 )
return 0 ;
return V_10 -> V_11 ;
}
int F_4 ( struct V_12 * V_13 )
{
void * V_5 = ( void * ) ( long ) V_13 -> V_5 ;
void * V_1 = ( void * ) ( long ) V_13 -> V_1 ;
struct V_14 * V_15 = V_1 ;
int V_16 = V_17 ;
long * V_18 ;
T_2 V_19 ;
T_1 V_4 ;
T_3 V_20 ;
V_4 = sizeof( * V_15 ) ;
if ( V_1 + V_4 > V_5 )
return V_16 ;
V_19 = V_15 -> V_19 ;
if ( V_19 == F_5 ( V_21 ) || V_19 == F_5 ( V_22 ) ) {
struct V_23 * V_24 ;
V_24 = V_1 + V_4 ;
V_4 += sizeof( struct V_23 ) ;
if ( V_1 + V_4 > V_5 )
return V_16 ;
V_19 = V_24 -> V_25 ;
}
if ( V_19 == F_5 ( V_21 ) || V_19 == F_5 ( V_22 ) ) {
struct V_23 * V_24 ;
V_24 = V_1 + V_4 ;
V_4 += sizeof( struct V_23 ) ;
if ( V_1 + V_4 > V_5 )
return V_16 ;
V_19 = V_24 -> V_25 ;
}
if ( V_19 == F_5 ( V_26 ) )
V_20 = F_2 ( V_1 , V_4 , V_5 ) ;
else if ( V_19 == F_5 ( V_27 ) )
V_20 = F_3 ( V_1 , V_4 , V_5 ) ;
else
V_20 = 0 ;
V_18 = F_6 ( & V_28 , & V_20 ) ;
if ( V_18 )
* V_18 += 1 ;
if ( V_20 == V_29 ) {
F_1 ( V_1 ) ;
V_16 = V_30 ;
}
return V_16 ;
}
