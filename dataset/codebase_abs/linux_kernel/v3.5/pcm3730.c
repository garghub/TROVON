static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_6 -> V_8 != 2 )
return - V_9 ;
if ( V_7 [ 0 ] ) {
V_4 -> V_10 &= ~ V_7 [ 0 ] ;
V_4 -> V_10 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
F_2 ( V_4 -> V_10 , V_2 -> V_11 + ( unsigned long ) ( V_4 -> V_12 ) ) ;
}
V_7 [ 1 ] = V_4 -> V_10 ;
return 2 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_6 -> V_8 != 2 )
return - V_9 ;
V_7 [ 1 ] = F_4 ( V_2 -> V_11 + ( unsigned long ) ( V_4 -> V_12 ) ) ;
return 2 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_3 * V_4 ;
unsigned long V_11 ;
V_11 = V_14 -> V_15 [ 0 ] ;
F_6 ( V_16 L_1 , V_2 -> V_17 , V_11 ) ;
if ( ! F_7 ( V_11 , V_18 , L_2 ) ) {
F_6 ( L_3 ) ;
return - V_19 ;
}
V_2 -> V_11 = V_11 ;
V_2 -> V_20 = L_2 ;
V_2 -> V_11 = V_2 -> V_11 ;
V_2 -> V_21 = 0 ;
if ( F_8 ( V_2 , 6 ) < 0 )
return - V_22 ;
V_4 = V_2 -> V_23 + 0 ;
V_4 -> type = V_24 ;
V_4 -> V_25 = V_26 ;
V_4 -> V_27 = 1 ;
V_4 -> V_28 = 8 ;
V_4 -> V_29 = F_1 ;
V_4 -> V_30 = & V_31 ;
V_4 -> V_12 = ( void * ) V_32 ;
V_4 = V_2 -> V_23 + 1 ;
V_4 -> type = V_24 ;
V_4 -> V_25 = V_26 ;
V_4 -> V_27 = 1 ;
V_4 -> V_28 = 8 ;
V_4 -> V_29 = F_1 ;
V_4 -> V_30 = & V_31 ;
V_4 -> V_12 = ( void * ) V_33 ;
V_4 = V_2 -> V_23 + 2 ;
V_4 -> type = V_24 ;
V_4 -> V_25 = V_26 ;
V_4 -> V_27 = 1 ;
V_4 -> V_28 = 8 ;
V_4 -> V_29 = F_1 ;
V_4 -> V_30 = & V_31 ;
V_4 -> V_12 = ( void * ) V_34 ;
V_4 = V_2 -> V_23 + 3 ;
V_4 -> type = V_35 ;
V_4 -> V_25 = V_36 ;
V_4 -> V_27 = 1 ;
V_4 -> V_28 = 8 ;
V_4 -> V_29 = F_3 ;
V_4 -> V_30 = & V_31 ;
V_4 -> V_12 = ( void * ) V_37 ;
V_4 = V_2 -> V_23 + 4 ;
V_4 -> type = V_35 ;
V_4 -> V_25 = V_36 ;
V_4 -> V_27 = 1 ;
V_4 -> V_28 = 8 ;
V_4 -> V_29 = F_3 ;
V_4 -> V_30 = & V_31 ;
V_4 -> V_12 = ( void * ) V_38 ;
V_4 = V_2 -> V_23 + 5 ;
V_4 -> type = V_35 ;
V_4 -> V_25 = V_36 ;
V_4 -> V_27 = 1 ;
V_4 -> V_28 = 8 ;
V_4 -> V_29 = F_3 ;
V_4 -> V_30 = & V_31 ;
V_4 -> V_12 = ( void * ) V_39 ;
F_6 ( V_16 L_4 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 )
F_10 ( V_2 -> V_11 , V_18 ) ;
}
