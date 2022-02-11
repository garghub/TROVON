static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_7 [ 0 ] ) {
V_4 -> V_8 &= ~ V_7 [ 0 ] ;
V_4 -> V_8 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
}
if ( V_7 [ 0 ] & 0x00ff )
F_2 ( V_4 -> V_8 & 0xff ,
V_2 -> V_9 + ( ( unsigned long ) V_4 -> V_10 ) ) ;
if ( V_7 [ 0 ] & 0xff00 )
F_2 ( ( V_4 -> V_8 >> 8 ) ,
V_2 -> V_9 + ( ( unsigned long ) V_4 -> V_10 ) + 1 ) ;
V_7 [ 1 ] = V_4 -> V_8 ;
return V_6 -> V_11 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 1 ] = F_4 ( V_2 -> V_9 + ( ( unsigned long ) V_4 -> V_10 ) ) |
( F_4 ( V_2 -> V_9 + ( ( unsigned long ) V_4 -> V_10 ) + 1 ) << 8 ) ;
return V_6 -> V_11 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
const struct V_14 * V_15 = F_6 ( V_2 ) ;
struct V_3 * V_4 ;
int V_16 ;
V_16 = F_7 ( V_2 , V_13 -> V_17 [ 0 ] , V_15 -> V_18 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_8 ( V_2 , 4 ) ;
if ( V_16 )
return V_16 ;
V_4 = & V_2 -> V_19 [ 0 ] ;
V_4 -> type = V_20 ;
V_4 -> V_21 = V_22 ;
V_4 -> V_23 = 1 ;
V_4 -> V_24 = 16 ;
V_4 -> V_25 = F_1 ;
V_4 -> V_26 = & V_27 ;
V_4 -> V_10 = ( void * ) V_28 ;
V_4 = & V_2 -> V_19 [ 1 ] ;
V_4 -> type = V_29 ;
V_4 -> V_21 = V_30 ;
V_4 -> V_23 = 1 ;
V_4 -> V_24 = 16 ;
V_4 -> V_25 = F_3 ;
V_4 -> V_26 = & V_27 ;
V_4 -> V_10 = ( void * ) V_28 ;
V_4 = & V_2 -> V_19 [ 2 ] ;
V_4 -> type = V_20 ;
V_4 -> V_21 = V_22 ;
V_4 -> V_23 = 1 ;
V_4 -> V_24 = 16 ;
V_4 -> V_25 = F_1 ;
V_4 -> V_26 = & V_27 ;
V_4 -> V_10 = ( void * ) V_31 ;
V_4 = & V_2 -> V_19 [ 3 ] ;
V_4 -> type = V_29 ;
V_4 -> V_21 = V_30 ;
V_4 -> V_23 = 1 ;
V_4 -> V_24 = 16 ;
V_4 -> V_25 = F_3 ;
V_4 -> V_26 = & V_27 ;
V_4 -> V_10 = ( void * ) V_31 ;
F_9 ( V_32 L_1 ) ;
return 0 ;
}
