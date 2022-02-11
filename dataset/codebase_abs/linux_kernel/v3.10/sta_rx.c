int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_10 ;
struct V_11 * V_12 ;
T_1 V_13 [ V_14 ] = { 0xaa , 0xaa , 0x03 , 0x00 , 0x00 , 0x00 } ;
V_9 = (struct V_8 * ) ( V_4 -> V_15 ) ;
V_7 = ( void * ) V_9 +
F_2 ( V_9 -> V_16 ) ;
if ( ! memcmp ( & V_7 -> V_17 ,
V_13 , sizeof( V_13 ) ) ) {
V_12 = (struct V_11 * )
( ( T_1 * ) & V_7 -> V_18
+ sizeof( V_7 -> V_18 ) +
sizeof( V_7 -> V_17 )
- sizeof( V_7 -> V_18 . V_19 )
- sizeof( V_7 -> V_18 . V_20 )
- sizeof( V_7 -> V_17 . V_21 ) ) ;
memcpy ( V_12 -> V_20 , V_7 -> V_18 . V_20 ,
sizeof( V_12 -> V_20 ) ) ;
memcpy ( V_12 -> V_19 , V_7 -> V_18 . V_19 ,
sizeof( V_12 -> V_19 ) ) ;
V_10 = ( T_1 * ) V_12 - ( T_1 * ) V_9 ;
} else {
V_10 = ( T_1 * ) & V_7 -> V_18 -
( T_1 * ) V_9 ;
}
F_3 ( V_4 , V_10 ) ;
V_2 -> V_22 = V_9 -> V_23 ;
V_2 -> V_24 = V_9 -> V_25 ;
V_5 = F_4 ( V_2 , V_4 ) ;
if ( V_5 == - 1 )
F_5 ( V_2 -> V_26 -> V_27 , L_1 ) ;
return V_5 ;
}
int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_28 * V_26 = V_2 -> V_26 ;
int V_5 = 0 ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
T_1 V_29 [ V_14 ] ;
T_2 V_30 , V_16 , V_31 , V_32 ;
V_9 = (struct V_8 * ) ( V_4 -> V_15 ) ;
V_30 = F_2 ( V_9 -> V_30 ) ;
V_16 = F_2 ( V_9 -> V_16 ) ;
V_31 = F_2 ( V_9 -> V_31 ) ;
V_32 = F_2 ( V_9 -> V_32 ) ;
V_7 = ( void * ) V_9 + V_16 ;
if ( ( V_16 + V_31 ) > ( T_2 ) V_4 -> V_33 ) {
F_5 ( V_26 -> V_27 ,
L_2 ,
V_4 -> V_33 , V_16 , V_31 ) ;
V_2 -> V_34 . V_35 ++ ;
if ( V_26 -> V_36 . V_37 )
V_26 -> V_36 . V_37 ( V_26 , V_4 ) ;
else
F_7 ( V_4 ) ;
return V_5 ;
}
if ( V_30 == V_38 ) {
struct V_39 V_40 ;
struct V_3 * V_41 ;
F_8 ( & V_40 ) ;
F_3 ( V_4 , V_16 ) ;
F_9 ( V_4 , V_31 ) ;
F_10 ( V_4 , & V_40 , V_2 -> V_42 ,
V_2 -> V_43 -> V_44 , 0 , false ) ;
while ( ! F_11 ( & V_40 ) ) {
V_41 = F_12 ( & V_40 ) ;
V_5 = F_4 ( V_2 , V_41 ) ;
if ( V_5 == - 1 )
F_5 ( V_26 -> V_27 , L_3 ) ;
}
return 0 ;
} else if ( V_30 == V_45 ) {
V_5 = F_13 ( V_2 , V_4 ) ;
if ( V_5 )
F_5 ( V_26 -> V_27 , L_4 ) ;
F_7 ( V_4 ) ;
return V_5 ;
}
if ( ! F_14 ( V_2 ) ||
memcmp ( V_2 -> V_42 , V_7 -> V_18 . V_19 , V_14 ) ) {
F_1 ( V_2 , V_4 ) ;
return V_5 ;
}
if ( F_15 ( V_2 ) ) {
memcpy ( V_29 , V_7 -> V_18 . V_20 , V_14 ) ;
} else {
if ( V_30 != V_46 )
V_2 -> V_47 [ V_9 -> V_48 ] = V_32 ;
memcpy ( V_29 , V_2 -> V_49 . V_50 . V_51 ,
V_14 ) ;
}
V_5 = F_16 ( V_2 , V_32 , V_9 -> V_48 ,
V_29 , ( T_1 ) V_30 , V_4 ) ;
if ( V_5 || ( V_30 == V_46 ) ) {
if ( V_26 -> V_36 . V_37 )
V_26 -> V_36 . V_37 ( V_26 , V_4 ) ;
else
F_7 ( V_4 ) ;
}
if ( V_5 )
V_2 -> V_34 . V_35 ++ ;
return V_5 ;
}
