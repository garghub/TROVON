static int F_1 ( struct V_1 * V_2 ,
const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_4 ) {
case V_7 :
V_6 -> V_8 = & V_6 -> V_9 [ V_10 ] ;
break;
default:
return - V_11 ;
}
memcpy ( V_6 -> V_12 . V_13 . V_14 , V_3 , V_4 ) ;
return 0 ;
}
static int F_3 ( struct V_15 * V_2 )
{
struct V_16 * V_17 = F_4 ( V_2 ) ;
struct V_5 * V_6 = F_5 ( & V_2 -> V_18 -> V_19 ) ;
struct V_20 * V_21 = V_6 -> V_21 ;
struct V_22 * V_23 ;
F_6 ( V_6 , V_24 ) ;
memset ( V_17 , 0 , sizeof *V_17 ) ;
F_7 ( V_21 , V_25 ) ;
V_21 -> V_26 . V_27 . V_28 = V_29 ;
memcpy ( V_21 -> V_26 . V_30 . V_14 , V_6 -> V_12 . V_13 . V_14 , V_31 ) ;
memset ( V_6 -> V_12 . V_13 . V_14 , 0 , sizeof * V_6 -> V_12 . V_13 . V_14 ) ;
V_23 = F_8 ( V_6 -> V_23 , ( T_1 * ) V_17 -> V_32 ,
V_31 , V_6 -> V_8 -> V_33 ) ;
V_6 -> V_34 . V_35 = ( V_6 -> V_23 - V_23 ) * sizeof( struct V_22 ) ;
return 0 ;
}
static int F_9 ( struct V_15 * V_2 ,
const T_1 * V_36 ,
unsigned int V_37 )
{
struct V_16 * V_17 = F_4 ( V_2 ) ;
struct V_5 * V_6 = F_5 ( & V_2 -> V_18 -> V_19 ) ;
struct V_20 * V_21 = V_6 -> V_21 ;
struct V_22 * V_38 ;
T_2 V_39 , V_40 ;
int V_41 = 0 ;
if ( F_10 ( V_21 ) & V_42 ) {
memcpy ( V_21 -> V_26 . V_30 . V_43 ,
V_21 -> V_26 . V_30 . V_44 , V_31 ) ;
}
if ( V_37 + V_17 -> V_45 <= V_31 ) {
memcpy ( V_17 -> V_46 + V_17 -> V_45 , V_36 , V_37 ) ;
V_17 -> V_45 += V_37 ;
goto V_47;
}
V_39 = ( V_17 -> V_45 + V_37 ) & ~ ( V_31 - 1 ) ;
V_40 = ( V_17 -> V_45 + V_37 ) & ( V_31 - 1 ) ;
if ( ! V_40 ) {
V_39 -= V_31 ;
V_40 = V_31 ;
}
if ( V_17 -> V_45 ) {
V_38 = F_8 ( V_6 -> V_38 , V_17 -> V_46 ,
V_17 -> V_45 , V_6 -> V_8 -> V_33 ) ;
V_38 = F_8 ( V_38 , ( T_1 * ) V_36 ,
V_39 - V_17 -> V_45 ,
V_6 -> V_8 -> V_33 ) ;
V_6 -> V_34 . V_48 = ( V_6 -> V_38 - V_38 ) *
sizeof( struct V_22 ) ;
} else {
V_38 = F_8 ( V_6 -> V_38 , ( T_1 * ) V_36 , V_39 ,
V_6 -> V_8 -> V_33 ) ;
V_6 -> V_34 . V_48 = ( V_6 -> V_38 - V_38 ) *
sizeof( struct V_22 ) ;
}
F_10 ( V_21 ) |= V_49 ;
if ( ! V_6 -> V_34 . V_48 || ! V_6 -> V_34 . V_35 ) {
V_41 = - V_11 ;
goto V_47;
}
V_41 = F_11 ( V_6 , & V_6 -> V_34 ,
V_2 -> V_50 & V_51 ) ;
if ( V_41 )
goto V_47;
F_12 ( & ( V_6 -> V_52 -> V_53 ) ) ;
memcpy ( V_17 -> V_46 , V_36 + V_37 - V_40 , V_40 ) ;
V_17 -> V_45 = V_40 ;
F_10 ( V_21 ) |= V_42 ;
V_47:
return V_41 ;
}
static int F_13 ( struct V_15 * V_2 , T_1 * V_47 )
{
struct V_16 * V_17 = F_4 ( V_2 ) ;
struct V_5 * V_6 = F_5 ( & V_2 -> V_18 -> V_19 ) ;
struct V_20 * V_21 = V_6 -> V_21 ;
struct V_22 * V_38 , * V_23 ;
int V_41 = 0 ;
if ( F_10 ( V_21 ) & V_42 ) {
memcpy ( V_21 -> V_26 . V_30 . V_43 ,
V_21 -> V_26 . V_30 . V_44 , V_31 ) ;
} else if ( V_17 -> V_45 == 0 ) {
T_1 V_36 [] = { 0x75 , 0xf0 , 0x25 , 0x1d , 0x52 , 0x8a , 0xc0 , 0x1c ,
0x45 , 0x73 , 0xdf , 0xd5 , 0x84 , 0xd7 , 0x9f , 0x29 } ;
memcpy ( V_47 , V_36 , sizeof( V_36 ) ) ;
goto V_47;
}
F_10 ( V_21 ) &= ~ V_49 ;
V_38 = F_8 ( V_6 -> V_38 , ( T_1 * ) V_17 -> V_46 ,
V_17 -> V_45 , V_6 -> V_8 -> V_33 ) ;
V_23 = F_8 ( V_6 -> V_23 , V_47 , V_31 ,
V_6 -> V_8 -> V_33 ) ;
V_6 -> V_34 . V_48 = ( V_6 -> V_38 - V_38 ) * sizeof( struct V_22 ) ;
V_6 -> V_34 . V_35 = ( V_6 -> V_23 - V_23 ) * sizeof( struct V_22 ) ;
if ( ! V_6 -> V_34 . V_35 ) {
V_41 = - V_11 ;
goto V_47;
}
V_41 = F_11 ( V_6 , & V_6 -> V_34 ,
V_2 -> V_50 & V_51 ) ;
if ( V_41 )
goto V_47;
F_12 ( & ( V_6 -> V_52 -> V_53 ) ) ;
memcpy ( V_47 , V_21 -> V_26 . V_30 . V_44 , V_31 ) ;
V_47:
return V_41 ;
}
