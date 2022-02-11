int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_8 = V_2 -> V_9 . V_8 - 1 ;
unsigned int V_10 = V_2 -> V_9 . V_10 - 1 ;
unsigned int V_11 , V_12 , V_13 , V_14 , V_15 ;
struct V_16 * V_17 ;
T_1 * V_18 , * V_19 ;
if ( V_2 -> V_20 != V_21 )
return 0 ;
V_14 = ( V_4 -> V_17 . V_22 + 7 ) >> 3 ;
V_13 = V_14 * V_4 -> V_17 . V_23 ;
if ( V_13 + sizeof( struct V_16 ) != V_6 -> V_24 ) {
if ( V_6 -> V_25 != NULL )
F_2 ( V_6 -> V_25 ) ;
V_6 -> V_24 = V_13 + sizeof( struct V_16 ) ;
V_6 -> V_25 = F_3 ( V_6 -> V_24 , V_26 ) ;
if ( ! V_6 -> V_25 ) {
V_6 -> V_24 = 0 ;
return - V_27 ;
}
}
V_18 = V_6 -> V_25 + sizeof( struct V_16 ) ;
V_17 = (struct V_16 * ) V_6 -> V_25 ;
* V_17 = V_4 -> V_17 ;
V_15 = ( V_14 + V_8 ) & ~ V_8 ;
V_12 = V_15 * V_17 -> V_23 + V_10 ;
V_12 &= ~ V_10 ;
V_19 = F_4 ( V_2 , & V_2 -> V_9 , V_12 ) ;
if ( V_4 -> V_28 ) {
switch ( V_4 -> V_29 ) {
case V_30 :
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ )
V_18 [ V_11 ] = V_17 -> V_31 [ V_11 ] ^ V_4 -> V_32 [ V_11 ] ;
break;
case V_33 :
default:
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ )
V_18 [ V_11 ] = V_17 -> V_31 [ V_11 ] & V_4 -> V_32 [ V_11 ] ;
break;
}
} else
memcpy ( V_18 , V_17 -> V_31 , V_13 ) ;
F_5 ( V_19 , V_15 , V_18 , V_14 , V_17 -> V_23 ) ;
V_17 -> V_31 = V_19 ;
V_2 -> V_34 -> V_35 ( V_2 , V_17 ) ;
return 0 ;
}
