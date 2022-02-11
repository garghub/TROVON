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
static int F_3 ( struct V_15 * V_2 , T_1 * V_16 )
{
struct V_5 * V_6 = F_4 ( & V_2 -> V_17 -> V_18 ) ;
struct V_19 * V_20 = V_6 -> V_20 ;
struct V_21 * V_22 , * V_23 ;
T_1 V_24 [ 2 ] [ V_25 ] ;
T_1 V_14 [ 32 ] ;
int V_26 = 0 ;
V_20 -> V_27 . V_28 . V_29 = V_30 ;
memcpy ( V_14 , V_20 -> V_27 . V_31 . V_14 , V_25 ) ;
memcpy ( V_20 -> V_27 . V_32 . V_14 , V_14 , V_25 ) ;
F_5 ( V_20 ) |= V_33 ;
memset ( V_24 [ 0 ] , 0x01 , sizeof( V_24 [ 0 ] ) ) ;
memset ( V_24 [ 1 ] , 0x03 , sizeof( V_24 [ 1 ] ) ) ;
V_22 = F_6 ( V_6 -> V_22 , ( T_1 * ) V_24 , sizeof( V_24 ) ,
V_6 -> V_8 -> V_34 ) ;
V_23 = F_6 ( V_6 -> V_23 , ( T_1 * ) V_24 , sizeof( V_24 ) ,
V_6 -> V_8 -> V_34 ) ;
V_6 -> V_35 . V_36 = ( V_6 -> V_22 - V_22 ) * sizeof( struct V_21 ) ;
V_6 -> V_35 . V_37 = ( V_6 -> V_23 - V_23 ) * sizeof( struct V_21 ) ;
V_26 = F_7 ( V_6 , & V_6 -> V_35 ,
V_2 -> V_38 & V_39 ) ;
if ( V_26 )
goto V_16;
F_8 ( & ( V_6 -> V_40 -> V_41 ) ) ;
V_24 [ 1 ] [ 0 ] ^= 0x80 ;
memcpy ( V_20 -> V_27 . V_32 . V_14 , V_24 [ 0 ] , V_25 ) ;
V_22 = F_6 ( V_6 -> V_22 , ( T_1 * ) V_24 [ 1 ] , sizeof( V_24 [ 1 ] ) ,
V_6 -> V_8 -> V_34 ) ;
V_23 = F_6 ( V_6 -> V_23 , V_16 , V_25 ,
V_6 -> V_8 -> V_34 ) ;
V_6 -> V_35 . V_36 = ( V_6 -> V_22 - V_22 ) * sizeof( struct V_21 ) ;
V_6 -> V_35 . V_37 = ( V_6 -> V_23 - V_23 ) * sizeof( struct V_21 ) ;
V_26 = F_7 ( V_6 , & V_6 -> V_35 ,
V_2 -> V_38 & V_39 ) ;
if ( V_26 )
goto V_16;
F_8 ( & ( V_6 -> V_40 -> V_41 ) ) ;
V_16:
V_20 -> V_27 . V_28 . V_29 = V_42 ;
memcpy ( V_20 -> V_27 . V_31 . V_14 , V_14 , V_25 ) ;
F_5 ( V_20 ) &= ~ V_33 ;
return V_26 ;
}
static int F_9 ( struct V_15 * V_2 )
{
struct V_43 * V_44 = F_10 ( V_2 ) ;
struct V_5 * V_6 = F_4 ( & V_2 -> V_17 -> V_18 ) ;
struct V_19 * V_20 = V_6 -> V_20 ;
struct V_21 * V_23 ;
F_11 ( V_6 , V_45 ) ;
memset ( V_44 , 0 , sizeof *V_44 ) ;
F_12 ( V_20 , V_46 ) ;
V_20 -> V_27 . V_28 . V_29 = V_42 ;
memcpy ( V_20 -> V_27 . V_31 . V_14 , V_6 -> V_12 . V_13 . V_14 , V_25 ) ;
memset ( V_6 -> V_12 . V_13 . V_14 , 0 , sizeof * V_6 -> V_12 . V_13 . V_14 ) ;
V_23 = F_6 ( V_6 -> V_23 , ( T_1 * ) V_44 -> V_47 ,
V_25 , V_6 -> V_8 -> V_34 ) ;
V_6 -> V_35 . V_37 = ( V_6 -> V_23 - V_23 ) * sizeof( struct V_21 ) ;
return 0 ;
}
static int F_13 ( struct V_15 * V_2 ,
const T_1 * V_48 ,
unsigned int V_49 )
{
struct V_43 * V_44 = F_10 ( V_2 ) ;
struct V_5 * V_6 = F_4 ( & V_2 -> V_17 -> V_18 ) ;
struct V_19 * V_20 = V_6 -> V_20 ;
struct V_21 * V_22 ;
T_2 V_50 , V_51 , V_52 ;
T_2 V_53 ;
unsigned long V_54 ;
int V_26 = 0 ;
F_14 ( & V_6 -> V_55 , V_54 ) ;
V_52 = V_44 -> V_56 + V_49 ;
if ( V_52 <= V_25 ) {
memcpy ( V_44 -> V_57 + V_44 -> V_56 , V_48 , V_49 ) ;
V_44 -> V_56 += V_49 ;
goto V_16;
}
V_22 = V_6 -> V_22 ;
V_53 = F_15 ( T_2 , V_58 . V_59 . V_53 / sizeof( struct V_21 ) ,
V_6 -> V_8 -> V_34 ) ;
do {
V_50 = F_15 ( V_60 , V_52 , V_6 -> V_8 -> V_61 ) ;
V_50 = F_15 ( V_60 , V_50 ,
V_62 * ( V_53 - 1 ) ) ;
V_50 = V_50 & ~ ( V_25 - 1 ) ;
V_51 = V_52 - V_50 ;
if ( ! V_51 ) {
V_50 -= V_25 ;
V_51 = V_25 ;
}
if ( V_44 -> V_56 ) {
V_22 = F_6 ( V_6 -> V_22 ,
( T_1 * ) V_44 -> V_57 ,
V_44 -> V_56 ,
V_53 ) ;
}
V_22 = F_6 ( V_22 ,
( T_1 * ) V_48 ,
V_50 - V_44 -> V_56 ,
V_53 ) ;
V_6 -> V_35 . V_36 = ( V_6 -> V_22 - V_22 ) *
sizeof( struct V_21 ) ;
if ( F_5 ( V_20 ) & V_63 ) {
memcpy ( V_20 -> V_27 . V_31 . V_64 ,
V_20 -> V_27 . V_31 . V_65 ,
V_25 ) ;
}
F_5 ( V_20 ) |= V_66 ;
if ( ! V_6 -> V_35 . V_36 || ! V_6 -> V_35 . V_37 ) {
V_26 = - V_11 ;
goto V_16;
}
V_26 = F_7 ( V_6 , & V_6 -> V_35 ,
V_2 -> V_38 & V_39 ) ;
if ( V_26 )
goto V_16;
F_8 ( & ( V_6 -> V_40 -> V_41 ) ) ;
F_5 ( V_20 ) |= V_63 ;
V_52 -= V_50 ;
V_48 += V_50 - V_44 -> V_56 ;
V_44 -> V_56 = 0 ;
V_22 = V_6 -> V_22 ;
} while ( V_51 > V_25 );
memcpy ( V_44 -> V_57 , V_48 , V_51 ) ;
V_44 -> V_56 = V_51 ;
V_16:
F_16 ( & V_6 -> V_55 , V_54 ) ;
return V_26 ;
}
static int F_17 ( struct V_15 * V_2 , T_1 * V_16 )
{
struct V_43 * V_44 = F_10 ( V_2 ) ;
struct V_5 * V_6 = F_4 ( & V_2 -> V_17 -> V_18 ) ;
struct V_19 * V_20 = V_6 -> V_20 ;
struct V_21 * V_22 , * V_23 ;
unsigned long V_54 ;
int V_26 = 0 ;
F_14 ( & V_6 -> V_55 , V_54 ) ;
if ( F_5 ( V_20 ) & V_63 ) {
memcpy ( V_20 -> V_27 . V_31 . V_64 ,
V_20 -> V_27 . V_31 . V_65 , V_25 ) ;
} else if ( V_44 -> V_56 == 0 ) {
V_26 = F_3 ( V_2 , V_16 ) ;
goto V_16;
}
F_5 ( V_20 ) &= ~ V_66 ;
V_22 = F_6 ( V_6 -> V_22 , ( T_1 * ) V_44 -> V_57 ,
V_44 -> V_56 , V_6 -> V_8 -> V_34 ) ;
V_23 = F_6 ( V_6 -> V_23 , V_16 , V_25 ,
V_6 -> V_8 -> V_34 ) ;
V_6 -> V_35 . V_36 = ( V_6 -> V_22 - V_22 ) * sizeof( struct V_21 ) ;
V_6 -> V_35 . V_37 = ( V_6 -> V_23 - V_23 ) * sizeof( struct V_21 ) ;
if ( ! V_6 -> V_35 . V_37 ) {
V_26 = - V_11 ;
goto V_16;
}
V_26 = F_7 ( V_6 , & V_6 -> V_35 ,
V_2 -> V_38 & V_39 ) ;
if ( V_26 )
goto V_16;
F_8 ( & ( V_6 -> V_40 -> V_41 ) ) ;
memcpy ( V_16 , V_20 -> V_27 . V_31 . V_65 , V_25 ) ;
V_16:
F_16 ( & V_6 -> V_55 , V_54 ) ;
return V_26 ;
}
