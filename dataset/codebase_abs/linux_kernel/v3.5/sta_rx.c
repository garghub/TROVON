int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 =
F_3 ( V_2 , V_7 -> V_10 ,
V_7 -> V_11 ) ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_16 ;
struct V_17 * V_18 ;
T_1 V_19 [ V_20 ] = { 0xaa , 0xaa , 0x03 , 0x00 , 0x00 , 0x00 } ;
V_15 = (struct V_14 * ) ( V_4 -> V_21 ) ;
V_13 = (struct V_12 * ) ( ( T_1 * ) V_15 +
V_15 -> V_22 ) ;
if ( ! memcmp ( & V_13 -> V_23 ,
V_19 , sizeof( V_19 ) ) ) {
V_18 = (struct V_17 * )
( ( T_1 * ) & V_13 -> V_24
+ sizeof( V_13 -> V_24 ) +
sizeof( V_13 -> V_23 )
- sizeof( V_13 -> V_24 . V_25 )
- sizeof( V_13 -> V_24 . V_26 )
- sizeof( V_13 -> V_23 . V_27 ) ) ;
memcpy ( V_18 -> V_26 , V_13 -> V_24 . V_26 ,
sizeof( V_18 -> V_26 ) ) ;
memcpy ( V_18 -> V_25 , V_13 -> V_24 . V_25 ,
sizeof( V_18 -> V_25 ) ) ;
V_16 = ( T_1 * ) V_18 - ( T_1 * ) V_15 ;
} else {
V_16 = ( T_1 * ) & V_13 -> V_24 -
( T_1 * ) V_15 ;
}
F_4 ( V_4 , V_16 ) ;
V_9 -> V_28 = V_15 -> V_29 ;
V_9 -> V_30 = V_15 -> V_31 ;
V_5 = F_5 ( V_2 , V_4 ) ;
if ( V_5 == - 1 )
F_6 ( V_2 -> V_32 , L_1 ) ;
return V_5 ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
struct V_14 * V_15 ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_12 * V_13 ;
T_1 V_33 [ V_20 ] ;
T_2 V_34 ;
struct V_8 * V_9 =
F_3 ( V_2 , V_7 -> V_10 ,
V_7 -> V_11 ) ;
if ( ! V_9 )
return - 1 ;
V_15 = (struct V_14 * ) ( V_4 -> V_21 ) ;
V_34 = V_15 -> V_34 ;
V_13 = (struct V_12 * ) ( ( T_1 * ) V_15 +
V_15 -> V_22 ) ;
if ( ( V_15 -> V_22 + V_15 -> V_35 ) >
( T_2 ) V_4 -> V_36 ) {
F_6 ( V_2 -> V_32 , L_2
L_3 , V_4 -> V_36 ,
V_15 -> V_22 , V_15 -> V_35 ) ;
V_9 -> V_37 . V_38 ++ ;
if ( V_2 -> V_39 . V_40 )
V_2 -> V_39 . V_40 ( V_2 , V_4 ) ;
else
F_8 ( V_4 ) ;
return V_5 ;
}
if ( V_15 -> V_34 == V_41 ) {
struct V_42 V_43 ;
struct V_3 * V_44 ;
F_9 ( & V_43 ) ;
F_4 ( V_4 , V_15 -> V_22 ) ;
F_10 ( V_4 , V_15 -> V_35 ) ;
F_11 ( V_4 , & V_43 , V_9 -> V_45 ,
V_9 -> V_46 -> V_47 , 0 , false ) ;
while ( ! F_12 ( & V_43 ) ) {
V_44 = F_13 ( & V_43 ) ;
V_5 = F_5 ( V_2 , V_44 ) ;
if ( V_5 == - 1 )
F_6 ( V_2 -> V_32 , L_4 ) ;
}
return 0 ;
}
if ( ! F_14 ( V_9 ) ||
memcmp ( V_9 -> V_45 , V_13 -> V_24 . V_25 , V_20 ) ) {
F_1 ( V_2 , V_4 ) ;
return V_5 ;
}
if ( F_15 ( V_9 ) ) {
memcpy ( V_33 , V_13 -> V_24 . V_26 , V_20 ) ;
} else {
if ( V_34 != V_48 )
V_9 -> V_49 [ V_15 -> V_50 ] =
V_15 -> V_51 ;
memcpy ( V_33 , V_9 -> V_52 . V_53 . V_54 ,
V_20 ) ;
}
V_5 = F_16 ( V_9 , V_15 -> V_51 ,
V_15 -> V_50 , V_33 ,
( T_1 ) V_15 -> V_34 ,
V_4 ) ;
if ( V_5 || ( V_34 == V_48 ) ) {
if ( V_2 -> V_39 . V_40 )
V_2 -> V_39 . V_40 ( V_2 , V_4 ) ;
else
F_8 ( V_4 ) ;
}
if ( V_5 )
V_9 -> V_37 . V_38 ++ ;
return V_5 ;
}
