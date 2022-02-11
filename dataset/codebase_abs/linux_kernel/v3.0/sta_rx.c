int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = V_2 -> V_9 [ V_7 -> V_10 ] ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int V_15 ;
struct V_16 * V_17 ;
T_1 V_18 [ V_19 ] = { 0xaa , 0xaa , 0x03 , 0x00 , 0x00 , 0x00 } ;
V_14 = (struct V_13 * ) ( V_4 -> V_20 ) ;
V_12 = (struct V_11 * ) ( ( T_1 * ) V_14 +
V_14 -> V_21 ) ;
if ( ! memcmp ( & V_12 -> V_22 ,
V_18 , sizeof( V_18 ) ) ) {
V_17 = (struct V_16 * )
( ( T_1 * ) & V_12 -> V_23
+ sizeof( V_12 -> V_23 ) +
sizeof( V_12 -> V_22 )
- sizeof( V_12 -> V_23 . V_24 )
- sizeof( V_12 -> V_23 . V_25 )
- sizeof( V_12 -> V_22 . V_26 ) ) ;
memcpy ( V_17 -> V_25 , V_12 -> V_23 . V_25 ,
sizeof( V_17 -> V_25 ) ) ;
memcpy ( V_17 -> V_24 , V_12 -> V_23 . V_24 ,
sizeof( V_17 -> V_24 ) ) ;
V_15 = ( T_1 * ) V_17 - ( T_1 * ) V_14 ;
} else {
V_15 = ( T_1 * ) & V_12 -> V_23 -
( T_1 * ) V_14 ;
}
F_3 ( V_4 , V_15 ) ;
V_9 -> V_27 = V_14 -> V_28 ;
V_9 -> V_29 = V_14 -> V_30 ;
V_5 = F_4 ( V_2 , V_4 ) ;
if ( V_5 == - 1 )
F_5 ( V_2 -> V_31 , L_1 ) ;
return V_5 ;
}
int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
struct V_13 * V_14 ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_11 * V_12 ;
T_1 V_32 [ V_19 ] ;
T_2 V_33 ;
struct V_8 * V_9 = V_2 -> V_9 [ V_7 -> V_10 ] ;
V_14 = (struct V_13 * ) ( V_4 -> V_20 ) ;
V_33 = V_14 -> V_33 ;
V_12 = (struct V_11 * ) ( ( T_1 * ) V_14 +
V_14 -> V_21 ) ;
if ( ( V_14 -> V_21 + V_14 -> V_34 ) >
( T_2 ) V_4 -> V_35 ) {
F_5 ( V_2 -> V_31 , L_2
L_3 , V_4 -> V_35 ,
V_14 -> V_21 , V_14 -> V_34 ) ;
V_9 -> V_36 . V_37 ++ ;
F_7 ( V_4 ) ;
return V_5 ;
}
if ( V_14 -> V_33 == V_38 ) {
struct V_39 V_40 ;
struct V_3 * V_41 ;
F_8 ( & V_40 ) ;
F_3 ( V_4 , V_14 -> V_21 ) ;
F_9 ( V_4 , V_14 -> V_34 ) ;
F_10 ( V_4 , & V_40 , V_9 -> V_42 ,
V_9 -> V_43 -> V_44 , 0 , false ) ;
while ( ! F_11 ( & V_40 ) ) {
V_41 = F_12 ( & V_40 ) ;
V_5 = F_4 ( V_2 , V_41 ) ;
if ( V_5 == - 1 )
F_5 ( V_2 -> V_31 , L_4 ) ;
}
return 0 ;
}
if ( ! F_13 ( V_9 ) ||
memcmp ( V_9 -> V_42 , V_12 -> V_23 . V_24 , V_19 ) ) {
F_1 ( V_2 , V_4 ) ;
return V_5 ;
}
if ( F_14 ( V_9 ) ) {
memcpy ( V_32 , V_12 -> V_23 . V_25 , V_19 ) ;
} else {
if ( V_33 != V_45 )
V_9 -> V_46 [ V_14 -> V_47 ] =
V_14 -> V_48 ;
memcpy ( V_32 , V_9 -> V_49 . V_50 . V_51 ,
V_19 ) ;
}
V_5 = F_15 ( V_9 , V_14 -> V_48 ,
V_14 -> V_47 , V_32 ,
( T_1 ) V_14 -> V_33 ,
( void * ) V_4 ) ;
if ( V_5 || ( V_33 == V_45 ) ) {
if ( V_9 && ( V_5 == - 1 ) )
V_9 -> V_36 . V_37 ++ ;
F_7 ( V_4 ) ;
}
return V_5 ;
}
