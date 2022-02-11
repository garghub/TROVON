static void F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
T_1 V_4 = 0 ;
int V_5 ;
V_3 /= V_2 -> V_6 ;
do {
V_5 = V_3 & ( 1 << V_4 ) ;
if ( V_2 -> V_7 [ V_4 ] != V_5 ) {
F_2 ( V_2 -> V_8 [ V_4 ] , V_5 ) ;
V_2 -> V_7 [ V_4 ] = V_5 ;
}
} while ( ++ V_4 < V_2 -> V_9 );
}
static T_2 F_3 ( struct V_10 * V_11 , unsigned long V_3 )
{
struct V_1 * V_2 = F_4 ( V_11 ) ;
T_3 V_12 ;
T_2 V_13 ;
F_1 ( V_2 , V_3 ) ;
V_12 = F_5 ( V_11 -> V_14 + ( V_3 % V_2 -> V_6 ) ) ;
V_13 . V_15 [ 0 ] = V_12 ;
return V_13 ;
}
static void F_6 ( struct V_10 * V_11 , void * V_16 , unsigned long V_17 , T_4 V_18 )
{
struct V_1 * V_2 = F_4 ( V_11 ) ;
F_1 ( V_2 , V_17 ) ;
F_7 ( ! ( ( V_17 + V_18 ) % V_2 -> V_6 <= ( V_17 + V_18 ) ) ) ;
F_8 ( V_16 , V_11 -> V_14 + ( V_17 % V_2 -> V_6 ) , V_18 ) ;
}
static void F_9 ( struct V_10 * V_11 , T_2 V_19 , unsigned long V_3 )
{
struct V_1 * V_2 = F_4 ( V_11 ) ;
T_3 V_20 ;
F_1 ( V_2 , V_3 ) ;
V_20 = V_19 . V_15 [ 0 ] ;
F_10 ( V_20 , V_11 -> V_14 + ( V_3 % V_2 -> V_6 ) ) ;
}
static void F_11 ( struct V_10 * V_11 , unsigned long V_16 , const void * V_17 , T_4 V_18 )
{
struct V_1 * V_2 = F_4 ( V_11 ) ;
F_1 ( V_2 , V_16 ) ;
F_7 ( ! ( ( V_16 + V_18 ) % V_2 -> V_6 <= ( V_16 + V_18 ) ) ) ;
F_12 ( V_11 -> V_14 + ( V_16 % V_2 -> V_6 ) , V_17 , V_18 ) ;
}
static int T_5 F_13 ( struct V_21 * V_22 )
{
T_1 V_4 , V_23 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
struct V_26 * V_28 ;
struct V_1 * V_2 ;
V_25 = V_22 -> V_29 . V_30 ;
V_27 = F_14 ( V_22 , V_31 , 0 ) ;
V_28 = F_14 ( V_22 , V_32 , 0 ) ;
if ( ! V_27 || ! V_28 || ! V_28 -> V_33 )
return - V_34 ;
V_23 = sizeof( int ) * V_28 -> V_33 ;
V_2 = F_15 ( sizeof( * V_2 ) + V_23 , V_35 ) ;
if ( ! V_2 )
return - V_36 ;
V_2 -> V_9 = V_28 -> V_33 ;
V_2 -> V_8 = ( void * ) ( unsigned long ) V_28 -> V_37 ;
V_2 -> V_7 = ( void * ) ( V_2 + 1 ) ;
V_2 -> V_6 = F_16 ( V_27 ) ;
memset ( V_2 -> V_7 , 0xff , V_23 ) ;
V_2 -> V_11 . V_38 = V_39 ;
V_2 -> V_11 . V_40 = F_3 ;
V_2 -> V_11 . V_41 = F_6 ;
V_2 -> V_11 . V_42 = F_9 ;
V_2 -> V_11 . V_43 = F_11 ;
V_2 -> V_11 . V_44 = V_25 -> V_45 ;
V_2 -> V_11 . V_46 = V_2 -> V_6 * ( 1 << V_2 -> V_9 ) ;
V_2 -> V_11 . V_14 = F_17 ( V_27 -> V_37 , V_2 -> V_11 . V_46 ) ;
V_2 -> V_11 . V_47 = V_48 ;
V_2 -> V_11 . V_49 = ( unsigned long ) V_2 ;
F_18 ( V_22 , V_2 ) ;
V_4 = 0 ;
do {
if ( F_19 ( V_2 -> V_8 [ V_4 ] , V_39 ) ) {
F_20 (KERN_ERR PFX L_1 ,
state->gpio_addrs[i]) ;
while ( V_4 -- )
F_21 ( V_2 -> V_8 [ V_4 ] ) ;
F_22 ( V_2 ) ;
return - V_50 ;
}
F_23 ( V_2 -> V_8 [ V_4 ] , 0 ) ;
} while ( ++ V_4 < V_2 -> V_9 );
F_20 (KERN_NOTICE PFX L_2 ,
state->map.bankwidth * 8 ) ;
V_2 -> V_51 = F_24 ( V_27 -> V_38 , & V_2 -> V_11 ) ;
if ( ! V_2 -> V_51 ) {
for ( V_4 = 0 ; V_4 < V_2 -> V_9 ; ++ V_4 )
F_21 ( V_2 -> V_8 [ V_4 ] ) ;
F_22 ( V_2 ) ;
return - V_52 ;
}
F_25 ( V_2 -> V_51 , V_53 , 0 ,
V_25 -> V_54 , V_25 -> V_55 ) ;
return 0 ;
}
static int T_6 F_26 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_27 ( V_22 ) ;
T_1 V_4 = 0 ;
do {
F_21 ( V_2 -> V_8 [ V_4 ] ) ;
} while ( ++ V_4 < V_2 -> V_9 );
F_28 ( V_2 -> V_51 ) ;
F_29 ( V_2 -> V_51 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
