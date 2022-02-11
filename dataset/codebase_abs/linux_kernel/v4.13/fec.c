struct V_1 *
F_1 ( int V_2 , T_1 V_3 , int V_4 )
{
struct V_1 * V_5 ;
struct V_6 * V_7 ;
V_5 = F_2 ( V_2 , sizeof( struct V_8 ) ,
sizeof( struct V_6 ) ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_9 = V_10 ;
V_7 = V_5 -> V_7 ;
V_7 -> V_3 = V_3 ;
V_7 -> V_4 = V_4 ;
if ( F_3 ( V_5 ) ) {
F_4 ( V_5 ) ;
return NULL ;
}
return V_5 ;
}
int
F_3 ( struct V_1 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
F_5 ( V_5 -> V_15 ) ;
V_12 = (struct V_11 * ) F_6 ( V_5 -> V_15 ) ;
V_14 = (struct V_13 * ) F_7 ( V_5 -> V_15 ) ;
if ( F_8 ( V_5 -> V_15 , V_16 ) )
return - 1 ;
V_12 -> V_17 = V_18 -> V_19 +
F_9 ( struct V_20 , V_21 [ V_5 -> V_15 ] ) ;
V_12 -> V_3 = ( V_22 ) V_7 -> V_3 ;
V_12 -> V_23 = V_5 -> V_24 ;
V_12 -> V_25 = V_5 -> V_24 + ( ( V_5 -> V_26 - 1 ) * V_5 -> V_27 ) ;
V_12 -> V_28 = V_5 -> V_24 ;
V_12 -> V_29 = V_7 -> V_4 ;
V_14 -> V_30 = - ( V_31 ) sizeof( V_22 ) ;
V_14 -> V_32 = sizeof( V_22 ) ;
V_14 -> V_33 = sizeof( V_34 ) ;
V_5 -> V_35 = 0 ;
V_5 -> V_36 = 0 ;
memset ( V_5 -> V_37 , 0x00 , V_5 -> V_26 * V_5 -> V_27 ) ;
F_10 ( V_5 -> V_15 , V_38 ) ;
F_11 ( V_5 -> V_15 , V_5 -> V_15 ) ;
F_12 ( & V_18 -> V_39 -> V_40 [ V_41 ] , V_42 ) ;
F_13 ( & V_18 -> V_39 -> V_43 , 1 << V_5 -> V_15 ) ;
return 0 ;
}
void
F_14 ( struct V_1 * V_5 )
{
F_4 ( V_5 ) ;
}
static V_22 * F_15 ( int V_15 )
{
V_22 * V_44 ;
int V_45 ;
int V_46 ;
int V_47 ;
V_45 = F_16 ( V_15 ) ;
V_44 = F_17 ( V_15 ) + V_45 - 1 ;
V_46 = 0 ;
for ( V_47 = 0 ; V_47 < V_45 ; V_47 ++ , V_44 -- )
if ( F_18 ( * V_44 ) && ++ V_46 == 3 )
break;
return V_44 ;
}
struct V_1 *
F_19 ( int V_2 , T_1 V_3 )
{
struct V_1 * V_5 ;
struct V_6 * V_7 ;
V_5 = F_2 ( V_2 , sizeof( struct V_8 ) ,
sizeof( struct V_6 ) ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_9 = V_48 ;
V_7 = V_5 -> V_7 ;
V_7 -> V_3 = V_3 ;
if ( F_20 ( V_5 ) ) {
F_4 ( V_5 ) ;
return NULL ;
}
return V_5 ;
}
int
F_20 ( struct V_1 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_49 * V_12 ;
struct V_50 * V_14 ;
F_5 ( V_5 -> V_15 ) ;
V_12 = (struct V_49 * ) F_6 ( V_5 -> V_15 ) ;
V_14 = (struct V_50 * ) F_7 ( V_5 -> V_15 ) ;
if ( F_8 ( V_5 -> V_15 , V_51 ) )
return - 1 ;
V_12 -> V_17 = V_18 -> V_19 +
F_9 ( struct V_20 , V_21 [ V_5 -> V_15 ] ) ;
V_12 -> V_3 = ( V_22 ) V_7 -> V_3 ;
V_12 -> V_52 = F_21 ( F_15 ( V_5 -> V_15 ) ) ;
V_12 -> V_23 = V_5 -> V_24 ;
V_12 -> V_25 = V_5 -> V_24 + ( ( V_5 -> V_26 - 1 ) * V_5 -> V_27 ) ;
V_12 -> V_28 = V_5 -> V_24 ;
V_14 -> V_30 = - ( V_31 ) sizeof( V_22 ) ;
V_14 -> V_53 = sizeof( V_22 ) ;
V_14 -> V_54 = sizeof( V_34 ) ;
V_5 -> V_35 = 0 ;
V_5 -> V_36 = 0 ;
memset ( V_5 -> V_37 , 0x00 , V_5 -> V_26 * V_5 -> V_27 ) ;
F_10 ( V_5 -> V_15 , V_55 ) ;
F_11 ( V_5 -> V_15 , V_5 -> V_15 ) ;
F_12 ( & V_18 -> V_39 -> V_40 [ V_56 ] , V_57 ) ;
F_13 ( & V_18 -> V_39 -> V_43 , 1 << V_5 -> V_15 ) ;
return 0 ;
}
void
F_22 ( struct V_1 * V_5 )
{
F_4 ( V_5 ) ;
}
