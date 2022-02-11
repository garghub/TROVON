static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned long V_8 = ( unsigned long ) V_4 -> V_9 ;
unsigned int V_10 = V_7 [ 0 ] ;
unsigned int V_11 = V_7 [ 1 ] ;
if ( V_10 ) {
V_4 -> V_12 &= ~ V_10 ;
V_4 -> V_12 |= ( V_11 & V_10 ) ;
if ( V_10 & 0x00ff )
F_2 ( V_4 -> V_12 & 0xff , V_2 -> V_13 + V_8 ) ;
if ( V_10 & 0xff00 )
F_2 ( ( V_4 -> V_12 >> 8 ) , V_2 -> V_13 + V_8 + 1 ) ;
}
V_7 [ 1 ] = V_4 -> V_12 ;
return V_6 -> V_14 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned long V_8 = ( unsigned long ) V_4 -> V_9 ;
V_7 [ 1 ] = F_4 ( V_2 -> V_13 + V_8 ) |
( F_4 ( V_2 -> V_13 + V_8 + 1 ) << 8 ) ;
return V_6 -> V_14 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
const struct V_17 * V_18 = F_6 ( V_2 ) ;
struct V_3 * V_4 ;
int V_19 ;
V_19 = F_7 ( V_2 , V_16 -> V_20 [ 0 ] , V_18 -> V_21 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_8 ( V_2 , 3 ) ;
if ( V_19 )
return V_19 ;
V_4 = & V_2 -> V_22 [ 0 ] ;
V_4 -> type = V_23 ;
V_4 -> V_24 = V_25 ;
V_4 -> V_26 = 1 ;
V_4 -> V_27 = 16 ;
V_4 -> V_28 = F_1 ;
V_4 -> V_29 = & V_30 ;
V_4 -> V_9 = ( void * ) V_31 ;
V_4 = & V_2 -> V_22 [ 1 ] ;
V_4 -> type = V_32 ;
V_4 -> V_24 = V_33 ;
V_4 -> V_26 = 1 ;
V_4 -> V_27 = 16 ;
V_4 -> V_28 = F_3 ;
V_4 -> V_29 = & V_30 ;
V_4 -> V_9 = ( void * ) V_31 ;
V_4 = & V_2 -> V_22 [ 2 ] ;
V_4 -> type = V_32 ;
V_4 -> V_24 = V_33 ;
V_4 -> V_26 = 1 ;
V_4 -> V_27 = 16 ;
V_4 -> V_28 = F_3 ;
V_4 -> V_29 = & V_30 ;
V_4 -> V_9 = ( void * ) V_34 ;
return 0 ;
}
