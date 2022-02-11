static int F_1 ( T_1 * V_1 , int V_2 , int V_3 , struct V_4 * V_5 )
{
int V_6 ;
T_1 * V_7 = V_1 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_2 ; V_6 ++ ) {
if ( V_7 [ V_6 ] != V_5 -> V_8 [ V_6 ] )
return - 1 ;
}
return 0 ;
}
static int F_2 ( struct V_9 * V_10 , T_1 * V_1 , struct V_4 * V_11 , int V_12 )
{
struct V_13 * V_14 = V_10 -> V_15 ;
struct V_16 * V_17 = V_14 -> V_17 ;
int V_6 , V_18 , V_19 , V_2 , V_20 ;
int V_21 ;
T_2 V_22 ;
T_3 V_23 , V_24 ;
struct V_25 V_26 ;
int V_27 ;
F_3 ( V_28 L_1 ) ;
V_2 = 2 ;
V_20 = V_24 = 0 ;
V_23 = V_11 -> V_2 ;
V_19 = V_14 -> V_29 >> ( V_17 -> V_30 - 1 ) ;
V_21 = 0 ;
V_22 = 0 ;
V_26 . V_31 = V_32 ;
V_26 . V_24 = V_23 ;
V_26 . V_33 = V_1 ;
V_26 . V_2 = V_26 . V_34 = V_26 . V_35 = V_26 . V_36 = 0 ;
for ( V_6 = V_21 ; V_6 < V_19 ; ) {
int V_37 ;
for ( V_18 = 0 ; V_18 < V_2 ; V_18 ++ ) {
V_37 = F_4 ( V_10 ,
V_22 + V_18 * V_14 -> V_38 + V_11 -> V_39 , & V_26 ) ;
if ( V_37 == V_40 )
return - V_41 ;
if ( V_37 || F_1 ( & V_1 [ V_18 * V_20 ] ,
V_20 , V_14 -> V_38 , V_11 ) ) {
V_17 -> V_42 [ V_6 >> 3 ] |= 0x03 << ( V_6 & 0x6 ) ;
F_3 ( V_28 L_2
L_3 , V_6 >> 1 ) ;
V_10 -> V_43 . V_44 ++ ;
break;
}
}
V_6 += 2 ;
if ( F_5 ( V_14 ) ) {
V_27 = F_6 ( V_10 , V_22 ) ;
V_22 += V_10 -> V_45 [ V_27 ] . V_46 ;
} else
V_22 += ( 1 << V_17 -> V_30 ) ;
}
return 0 ;
}
static inline int F_7 ( struct V_9 * V_10 , struct V_4 * V_11 )
{
struct V_13 * V_14 = V_10 -> V_15 ;
V_11 -> V_47 &= ~ V_48 ;
return F_2 ( V_10 , V_14 -> V_49 , V_11 , - 1 ) ;
}
static int F_8 ( struct V_9 * V_10 , T_2 V_39 , int V_50 )
{
struct V_13 * V_14 = V_10 -> V_15 ;
struct V_16 * V_17 = V_14 -> V_17 ;
int V_51 ;
T_1 V_52 ;
V_51 = ( int ) ( F_9 ( V_14 , V_39 ) << 1 ) ;
V_52 = ( V_17 -> V_42 [ V_51 >> 3 ] >> ( V_51 & 0x06 ) ) & 0x03 ;
F_10 ( L_4 ,
( unsigned int ) V_39 , V_51 >> 1 , V_52 ) ;
switch ( ( int ) V_52 ) {
case 0x00 : return 0 ;
case 0x01 : return 1 ;
case 0x02 : return V_50 ? 0 : 1 ;
}
return 1 ;
}
int F_11 ( struct V_9 * V_10 , struct V_4 * V_11 )
{
struct V_13 * V_14 = V_10 -> V_15 ;
struct V_16 * V_17 = V_14 -> V_17 ;
int V_2 , V_37 = 0 ;
V_2 = V_14 -> V_29 >> ( V_14 -> V_53 + 2 ) ;
V_17 -> V_42 = F_12 ( V_2 , V_54 ) ;
if ( ! V_17 -> V_42 )
return - V_55 ;
V_17 -> V_56 = V_57 ;
V_17 -> V_30 = V_14 -> V_53 ;
if ( ! V_17 -> V_58 )
V_17 -> V_58 = F_8 ;
if ( ( V_37 = F_7 ( V_10 , V_11 ) ) ) {
F_3 ( V_59 L_5 ) ;
F_13 ( V_17 -> V_42 ) ;
V_17 -> V_42 = NULL ;
}
return V_37 ;
}
int F_14 ( struct V_9 * V_10 )
{
struct V_13 * V_14 = V_10 -> V_15 ;
struct V_16 * V_17 ;
V_14 -> V_17 = F_12 ( sizeof( struct V_16 ) , V_54 ) ;
if ( ! V_14 -> V_17 )
return - V_55 ;
V_17 = V_14 -> V_17 ;
if ( ! V_17 -> V_60 )
V_17 -> V_60 = & V_61 ;
return F_11 ( V_10 , V_17 -> V_60 ) ;
}
