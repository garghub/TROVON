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
unsigned long V_9 ;
unsigned int V_16 ;
int V_17 ;
V_9 = V_13 -> V_18 [ 0 ] ;
V_16 = V_15 -> V_19 ;
F_7 ( V_20 L_1 , V_2 -> V_21 ,
V_15 -> V_22 , V_9 ) ;
if ( ! F_8 ( V_9 , V_16 , L_2 ) ) {
F_7 ( L_3 ) ;
return - V_23 ;
}
V_2 -> V_24 = V_15 -> V_22 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_25 = 0 ;
V_17 = F_9 ( V_2 , 4 ) ;
if ( V_17 )
return V_17 ;
V_4 = V_2 -> V_26 + 0 ;
V_4 -> type = V_27 ;
V_4 -> V_28 = V_29 ;
V_4 -> V_30 = 1 ;
V_4 -> V_31 = 16 ;
V_4 -> V_32 = F_1 ;
V_4 -> V_33 = & V_34 ;
V_4 -> V_10 = ( void * ) V_35 ;
V_4 = V_2 -> V_26 + 1 ;
V_4 -> type = V_36 ;
V_4 -> V_28 = V_37 ;
V_4 -> V_30 = 1 ;
V_4 -> V_31 = 16 ;
V_4 -> V_32 = F_3 ;
V_4 -> V_33 = & V_34 ;
V_4 -> V_10 = ( void * ) V_35 ;
V_4 = V_2 -> V_26 + 2 ;
V_4 -> type = V_27 ;
V_4 -> V_28 = V_29 ;
V_4 -> V_30 = 1 ;
V_4 -> V_31 = 16 ;
V_4 -> V_32 = F_1 ;
V_4 -> V_33 = & V_34 ;
V_4 -> V_10 = ( void * ) V_38 ;
V_4 = V_2 -> V_26 + 3 ;
V_4 -> type = V_36 ;
V_4 -> V_28 = V_37 ;
V_4 -> V_30 = 1 ;
V_4 -> V_31 = 16 ;
V_4 -> V_32 = F_3 ;
V_4 -> V_33 = & V_34 ;
V_4 -> V_10 = ( void * ) V_38 ;
F_7 ( V_20 L_4 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
const struct V_14 * V_15 = F_6 ( V_2 ) ;
if ( V_2 -> V_9 )
F_11 ( V_2 -> V_9 , V_15 -> V_19 ) ;
}
