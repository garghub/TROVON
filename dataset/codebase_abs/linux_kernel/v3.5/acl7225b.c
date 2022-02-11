static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_6 -> V_8 != 2 )
return - V_9 ;
if ( V_7 [ 0 ] ) {
V_4 -> V_10 &= ~ V_7 [ 0 ] ;
V_4 -> V_10 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
}
if ( V_7 [ 0 ] & 0x00ff )
F_2 ( V_4 -> V_10 & 0xff , V_2 -> V_11 + ( unsigned long ) V_4 -> V_12 ) ;
if ( V_7 [ 0 ] & 0xff00 )
F_2 ( ( V_4 -> V_10 >> 8 ) ,
V_2 -> V_11 + ( unsigned long ) V_4 -> V_12 + 1 ) ;
V_7 [ 1 ] = V_4 -> V_10 ;
return 2 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_6 -> V_8 != 2 )
return - V_9 ;
V_7 [ 1 ] = F_4 ( V_2 -> V_11 + ( unsigned long ) V_4 -> V_12 ) |
( F_4 ( V_2 -> V_11 + ( unsigned long ) V_4 -> V_12 + 1 ) << 8 ) ;
return 2 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_3 * V_4 ;
int V_11 , V_15 ;
V_11 = V_14 -> V_16 [ 0 ] ;
V_15 = V_17 -> V_18 ;
F_6 ( V_19 L_1 , V_2 -> V_20 ,
V_17 -> V_21 , V_11 ) ;
if ( ! F_7 ( V_11 , V_15 , L_2 ) ) {
F_6 ( V_22 L_3 ,
V_2 -> V_20 ) ;
return - V_23 ;
}
V_2 -> V_24 = V_17 -> V_21 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_25 = 0 ;
if ( F_8 ( V_2 , 3 ) < 0 )
return - V_26 ;
V_4 = V_2 -> V_27 + 0 ;
V_4 -> type = V_28 ;
V_4 -> V_29 = V_30 ;
V_4 -> V_31 = 1 ;
V_4 -> V_32 = 16 ;
V_4 -> V_33 = F_1 ;
V_4 -> V_34 = & V_35 ;
V_4 -> V_12 = ( void * ) V_36 ;
V_4 = V_2 -> V_27 + 1 ;
V_4 -> type = V_37 ;
V_4 -> V_29 = V_38 ;
V_4 -> V_31 = 1 ;
V_4 -> V_32 = 16 ;
V_4 -> V_33 = F_3 ;
V_4 -> V_34 = & V_35 ;
V_4 -> V_12 = ( void * ) V_36 ;
V_4 = V_2 -> V_27 + 2 ;
V_4 -> type = V_37 ;
V_4 -> V_29 = V_38 ;
V_4 -> V_31 = 1 ;
V_4 -> V_32 = 16 ;
V_4 -> V_33 = F_3 ;
V_4 -> V_34 = & V_35 ;
V_4 -> V_12 = ( void * ) V_39 ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 )
F_10 ( V_2 -> V_11 , V_17 -> V_18 ) ;
}
