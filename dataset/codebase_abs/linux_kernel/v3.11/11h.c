static void
F_1 ( struct V_1 * V_2 , T_1 * * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
T_1 V_14 ;
int V_15 ;
if ( ! V_3 || ! ( * V_3 ) )
return;
V_14 = F_2 ( ( T_1 ) V_5 -> V_16 ) ;
V_13 = V_2 -> V_17 -> V_18 -> V_19 [ V_14 ] ;
V_9 = (struct V_8 * ) * V_3 ;
V_9 -> V_20 . type = F_3 ( V_21 ) ;
V_9 -> V_20 . V_22 = F_3 ( 2 ) ;
V_9 -> V_23 = 0 ;
V_9 -> V_24 = 0 ;
* V_3 += sizeof( * V_9 ) ;
V_11 = (struct V_10 * ) * V_3 ;
V_11 -> V_20 . type = F_3 ( V_25 ) ;
V_11 -> V_20 . V_22 = F_3 ( 2 ) ;
V_11 -> V_26 = V_5 -> V_27 ;
V_11 -> V_11 = V_5 -> V_28 ;
* V_3 += sizeof( * V_11 ) ;
V_7 = (struct V_6 * ) * V_3 ;
V_7 -> type = F_3 ( V_29 ) ;
V_7 -> V_22 = F_3 ( 2 * V_13 -> V_30 + 2 ) ;
* V_3 += sizeof( * V_7 ) ;
* ( * V_3 ) ++ = V_31 ;
* ( * V_3 ) ++ = 2 * V_13 -> V_30 ;
for ( V_15 = 0 ; V_15 < V_13 -> V_30 ; V_15 ++ ) {
* ( * V_3 ) ++ = F_4 (
V_13 -> V_32 [ V_15 ] . V_33 ) ;
* ( * V_3 ) ++ = 1 ;
}
}
static int F_5 ( struct V_1 * V_2 , bool V_34 )
{
T_2 V_35 = V_34 ;
return F_6 ( V_2 , V_36 ,
V_37 , V_38 , & V_35 ) ;
}
void F_7 ( struct V_1 * V_2 , T_1 * * V_3 ,
struct V_4 * V_5 )
{
if ( V_5 -> V_39 ) {
F_5 ( V_2 , true ) ;
V_5 -> V_40 |= V_41 ;
F_1 ( V_2 , V_3 , V_5 ) ;
} else {
F_5 ( V_2 , false ) ;
V_5 -> V_40 &= ~ V_41 ;
}
}
