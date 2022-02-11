static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static int F_5 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , unsigned int * V_8 )
{
if ( V_7 -> V_9 != 2 )
return - V_10 ;
if ( V_8 [ 0 ] ) {
V_5 -> V_11 &= ~ V_8 [ 0 ] ;
V_5 -> V_11 |= ( V_8 [ 0 ] & V_8 [ 1 ] ) ;
}
if ( V_8 [ 0 ] & 0x00ff )
F_6 ( V_5 -> V_11 & 0xff , V_3 -> V_12 + ( unsigned long ) V_5 -> V_13 ) ;
if ( V_8 [ 0 ] & 0xff00 )
F_6 ( ( V_5 -> V_11 >> 8 ) ,
V_3 -> V_12 + ( unsigned long ) V_5 -> V_13 + 1 ) ;
V_8 [ 1 ] = V_5 -> V_11 ;
return 2 ;
}
static int F_7 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , unsigned int * V_8 )
{
if ( V_7 -> V_9 != 2 )
return - V_10 ;
V_8 [ 1 ] = F_8 ( V_3 -> V_12 + ( unsigned long ) V_5 -> V_13 ) |
( F_8 ( V_3 -> V_12 + ( unsigned long ) V_5 -> V_13 + 1 ) << 8 ) ;
return 2 ;
}
static int F_9 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 ;
int V_12 , V_16 ;
V_12 = V_15 -> V_17 [ 0 ] ;
V_16 = V_18 -> V_19 ;
F_10 ( V_20 L_1 , V_3 -> V_21 ,
V_18 -> V_22 , V_12 ) ;
if ( ! F_11 ( V_12 , V_16 , L_2 ) ) {
F_10 ( V_23 L_3 ,
V_3 -> V_21 ) ;
return - V_24 ;
}
V_3 -> V_25 = V_18 -> V_22 ;
V_3 -> V_12 = V_12 ;
V_3 -> V_26 = 0 ;
if ( F_12 ( V_3 , 3 ) < 0 )
return - V_27 ;
V_5 = V_3 -> V_28 + 0 ;
V_5 -> type = V_29 ;
V_5 -> V_30 = V_31 ;
V_5 -> V_32 = 1 ;
V_5 -> V_33 = 16 ;
V_5 -> V_34 = F_5 ;
V_5 -> V_35 = & V_36 ;
V_5 -> V_13 = ( void * ) V_37 ;
V_5 = V_3 -> V_28 + 1 ;
V_5 -> type = V_38 ;
V_5 -> V_30 = V_39 ;
V_5 -> V_32 = 1 ;
V_5 -> V_33 = 16 ;
V_5 -> V_34 = F_7 ;
V_5 -> V_35 = & V_36 ;
V_5 -> V_13 = ( void * ) V_37 ;
V_5 = V_3 -> V_28 + 2 ;
V_5 -> type = V_38 ;
V_5 -> V_30 = V_39 ;
V_5 -> V_32 = 1 ;
V_5 -> V_33 = 16 ;
V_5 -> V_34 = F_7 ;
V_5 -> V_35 = & V_36 ;
V_5 -> V_13 = ( void * ) V_40 ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 )
{
F_10 ( V_20 L_4 , V_3 -> V_21 ) ;
if ( V_3 -> V_12 )
F_14 ( V_3 -> V_12 , V_18 -> V_19 ) ;
return 0 ;
}
