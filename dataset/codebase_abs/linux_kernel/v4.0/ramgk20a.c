static void
F_1 ( struct V_1 * V_2 , struct V_3 * * V_4 )
{
struct V_5 * V_6 = F_2 ( F_3 ( V_2 ) ) ;
struct V_7 * V_8 = F_4 ( * V_4 ) ;
* V_4 = NULL ;
if ( F_5 ( V_8 == NULL ) )
return;
if ( F_6 ( V_8 -> V_9 ) )
F_7 ( V_6 , V_8 -> V_10 . V_11 << V_12 ,
V_8 -> V_9 , V_8 -> V_13 ) ;
F_8 ( V_8 -> V_10 . V_14 ) ;
F_8 ( V_8 ) ;
}
static int
F_9 ( struct V_1 * V_2 , T_1 V_11 , T_2 V_15 , T_2 V_16 ,
T_2 V_17 , struct V_3 * * V_4 )
{
struct V_5 * V_6 = F_2 ( F_3 ( V_2 ) ) ;
struct V_7 * V_8 ;
T_2 type = V_17 & 0xff ;
T_2 V_18 , V_19 ;
int V_20 ;
F_10 ( V_2 , L_1 , V_21 , V_11 ,
V_15 , V_16 ) ;
V_18 = V_11 >> V_12 ;
if ( V_18 == 0 )
V_18 = 1 ;
if ( V_15 == 0 )
V_15 = V_22 ;
V_15 >>= V_12 ;
V_19 = F_11 ( V_15 ) ;
if ( ( V_15 & ( V_15 - 1 ) ) == 0 )
V_19 -- ;
V_15 = F_12 ( V_19 ) ;
V_18 = F_13 ( V_15 , V_18 ) ;
V_8 = F_14 ( sizeof( * V_8 ) , V_23 ) ;
if ( ! V_8 )
return - V_24 ;
V_8 -> V_10 . V_11 = V_18 ;
V_8 -> V_10 . V_17 = type ;
V_8 -> V_10 . V_14 = F_14 ( sizeof( V_25 ) * V_18 , V_23 ) ;
if ( ! V_8 -> V_10 . V_14 ) {
F_8 ( V_8 ) ;
return - V_24 ;
}
* V_4 = & V_8 -> V_10 ;
V_8 -> V_9 = F_15 ( V_6 , V_18 << V_12 ,
& V_8 -> V_13 , V_23 ) ;
if ( ! V_8 -> V_9 ) {
F_16 ( V_2 , L_2 , V_21 ) ;
F_1 ( V_2 , V_4 ) ;
return - V_24 ;
}
V_15 <<= V_12 ;
if ( F_5 ( V_8 -> V_13 & ( V_15 - 1 ) ) )
F_17 ( V_2 , L_3 ,
& V_8 -> V_13 , V_15 ) ;
F_10 ( V_2 , L_4 ,
V_18 << V_12 , V_15 , & V_8 -> V_13 , V_8 -> V_9 ) ;
for ( V_20 = 0 ; V_20 < V_18 ; V_20 ++ )
V_8 -> V_10 . V_14 [ V_20 ] = V_8 -> V_13 + ( V_22 * V_20 ) ;
V_8 -> V_10 . V_26 = ( T_1 ) V_8 -> V_10 . V_14 [ 0 ] ;
return 0 ;
}
static int
F_18 ( struct V_27 * V_28 , struct V_27 * V_29 ,
struct V_30 * V_31 , void * V_32 , T_2 V_33 ,
struct V_27 * * V_34 )
{
struct V_35 * V_36 ;
int V_37 ;
V_37 = F_19 ( V_28 , V_29 , V_31 , & V_36 ) ;
* V_34 = F_20 ( V_36 ) ;
if ( V_37 )
return V_37 ;
V_36 -> type = V_38 ;
V_36 -> V_11 = F_21 () << V_12 ;
V_36 -> V_39 = F_9 ;
V_36 -> V_40 = F_1 ;
return 0 ;
}
