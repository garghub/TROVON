static int F_1 ( struct V_1 * V_2 ,
const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
switch ( V_4 ) {
case V_9 :
V_6 -> V_10 = & V_6 -> V_11 [ V_12 ] ;
break;
default:
return - V_13 ;
}
memcpy ( V_8 -> V_14 . V_15 . V_16 , V_3 , V_4 ) ;
return 0 ;
}
static int F_3 ( struct V_17 * V_2 , T_1 * V_18 )
{
struct V_5 * V_6 = F_4 ( & V_2 -> V_19 -> V_20 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_21 * V_22 , * V_23 ;
T_1 V_24 [ 2 ] [ V_25 ] ;
T_1 V_16 [ 32 ] ;
int V_26 = 0 ;
int V_27 ;
V_8 -> V_14 . V_28 . V_29 = V_30 ;
memcpy ( V_16 , V_8 -> V_14 . V_15 . V_16 , V_25 ) ;
memcpy ( V_8 -> V_14 . V_31 . V_16 , V_16 , V_25 ) ;
F_5 ( V_8 ) |= V_32 ;
memset ( V_24 [ 0 ] , 0x01 , sizeof( V_24 [ 0 ] ) ) ;
memset ( V_24 [ 1 ] , 0x03 , sizeof( V_24 [ 1 ] ) ) ;
V_27 = sizeof( V_24 ) ;
V_22 = F_6 ( V_6 -> V_22 , ( T_1 * ) V_24 , & V_27 ,
V_6 -> V_10 -> V_33 ) ;
if ( V_27 != sizeof( V_24 ) )
return - V_13 ;
V_23 = F_6 ( V_6 -> V_23 , ( T_1 * ) V_24 , & V_27 ,
V_6 -> V_10 -> V_33 ) ;
if ( V_27 != sizeof( V_24 ) )
return - V_13 ;
V_6 -> V_34 . V_35 = ( V_6 -> V_22 - V_22 ) * sizeof( struct V_21 ) ;
V_6 -> V_34 . V_36 = ( V_6 -> V_23 - V_23 ) * sizeof( struct V_21 ) ;
V_26 = F_7 ( V_6 , & V_6 -> V_34 ,
V_2 -> V_37 & V_38 ) ;
if ( V_26 )
goto V_18;
F_8 ( & ( V_6 -> V_39 -> V_40 ) ) ;
V_24 [ 1 ] [ 0 ] ^= 0x80 ;
V_27 = sizeof( V_24 [ 1 ] ) ;
memcpy ( V_8 -> V_14 . V_31 . V_16 , V_24 [ 0 ] , V_25 ) ;
V_22 = F_6 ( V_6 -> V_22 , ( T_1 * ) V_24 [ 1 ] , & V_27 ,
V_6 -> V_10 -> V_33 ) ;
if ( V_27 != sizeof( V_24 [ 1 ] ) )
return - V_13 ;
V_27 = V_25 ;
V_23 = F_6 ( V_6 -> V_23 , V_18 , & V_27 ,
V_6 -> V_10 -> V_33 ) ;
if ( V_27 != V_25 )
return - V_13 ;
V_6 -> V_34 . V_35 = ( V_6 -> V_22 - V_22 ) * sizeof( struct V_21 ) ;
V_6 -> V_34 . V_36 = ( V_6 -> V_23 - V_23 ) * sizeof( struct V_21 ) ;
V_26 = F_7 ( V_6 , & V_6 -> V_34 ,
V_2 -> V_37 & V_38 ) ;
if ( V_26 )
goto V_18;
F_8 ( & ( V_6 -> V_39 -> V_40 ) ) ;
V_18:
V_8 -> V_14 . V_28 . V_29 = V_41 ;
memcpy ( V_8 -> V_14 . V_15 . V_16 , V_16 , V_25 ) ;
F_5 ( V_8 ) &= ~ V_32 ;
return V_26 ;
}
static int F_9 ( struct V_42 * V_19 )
{
struct V_5 * V_6 = F_4 ( V_19 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_43 ;
V_43 = F_10 ( V_19 ) ;
if ( V_43 )
return V_43 ;
F_11 ( V_6 , V_44 ) ;
F_12 ( V_8 , V_45 ) ;
V_8 -> V_14 . V_28 . V_29 = V_41 ;
return 0 ;
}
static int F_13 ( struct V_17 * V_2 )
{
struct V_46 * V_47 = F_14 ( V_2 ) ;
memset ( V_47 , 0 , sizeof *V_47 ) ;
return 0 ;
}
static int F_15 ( struct V_17 * V_2 ,
const T_1 * V_48 ,
unsigned int V_27 )
{
struct V_46 * V_47 = F_14 ( V_2 ) ;
struct V_5 * V_6 = F_4 ( & V_2 -> V_19 -> V_20 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_21 * V_22 ;
struct V_21 * V_23 ;
T_2 V_49 = 0 , V_50 , V_51 ;
unsigned int V_52 ;
unsigned long V_53 ;
int V_26 = 0 ;
int V_54 ;
F_16 ( & V_6 -> V_55 , V_53 ) ;
V_51 = V_47 -> V_56 + V_27 ;
if ( V_51 <= V_25 ) {
memcpy ( V_47 -> V_57 + V_47 -> V_56 , V_48 , V_27 ) ;
V_47 -> V_56 += V_27 ;
goto V_18;
}
V_22 = V_6 -> V_22 ;
V_52 = F_17 ( V_58 , V_59 . V_60 . V_52 / sizeof( struct V_21 ) ,
V_6 -> V_10 -> V_33 ) ;
V_52 = F_17 ( V_58 , V_52 ,
V_6 -> V_10 -> V_61 / V_62 ) ;
V_54 = V_25 ;
V_23 = F_6 ( V_6 -> V_23 , ( T_1 * ) V_47 -> V_63 ,
& V_27 , V_6 -> V_10 -> V_33 ) ;
if ( V_54 != V_25 ) {
V_26 = - V_13 ;
goto V_18;
}
V_6 -> V_34 . V_36 = ( V_6 -> V_23 - V_23 ) * sizeof( struct V_21 ) ;
do {
V_49 = V_51 - V_49 ;
V_49 = V_49 & ~ ( V_25 - 1 ) ;
V_50 = V_51 - V_49 ;
if ( ! V_50 ) {
V_49 -= V_25 ;
V_50 = V_25 ;
}
if ( V_47 -> V_56 ) {
V_54 = V_47 -> V_56 ;
V_22 = F_6 ( V_6 -> V_22 ,
( T_1 * ) V_47 -> V_57 ,
& V_54 ,
V_52 ) ;
if ( V_54 != V_47 -> V_56 ) {
V_26 = - V_13 ;
goto V_18;
}
}
V_54 = V_49 - V_47 -> V_56 ;
V_22 = F_6 ( V_22 ,
( T_1 * ) V_48 ,
& V_54 ,
V_52 ) ;
if ( V_54 != V_49 - V_47 -> V_56 ) {
V_26 = - V_13 ;
goto V_18;
}
V_6 -> V_34 . V_35 = ( V_6 -> V_22 - V_22 ) *
sizeof( struct V_21 ) ;
if ( F_5 ( V_8 ) & V_64 ) {
memcpy ( V_8 -> V_14 . V_15 . V_65 ,
V_8 -> V_14 . V_15 . V_66 ,
V_25 ) ;
}
F_5 ( V_8 ) |= V_67 ;
if ( ! V_6 -> V_34 . V_35 || ! V_6 -> V_34 . V_36 ) {
V_26 = - V_13 ;
goto V_18;
}
V_26 = F_7 ( V_6 , & V_6 -> V_34 ,
V_2 -> V_37 & V_38 ) ;
if ( V_26 )
goto V_18;
F_8 ( & ( V_6 -> V_39 -> V_40 ) ) ;
F_5 ( V_8 ) |= V_64 ;
V_51 -= V_49 ;
V_48 += V_49 - V_47 -> V_56 ;
V_47 -> V_56 = 0 ;
V_22 = V_6 -> V_22 ;
} while ( V_50 > V_25 );
memcpy ( V_47 -> V_57 , V_48 , V_50 ) ;
V_47 -> V_56 = V_50 ;
V_18:
F_18 ( & V_6 -> V_55 , V_53 ) ;
return V_26 ;
}
static int F_19 ( struct V_17 * V_2 , T_1 * V_18 )
{
struct V_46 * V_47 = F_14 ( V_2 ) ;
struct V_5 * V_6 = F_4 ( & V_2 -> V_19 -> V_20 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_21 * V_22 , * V_23 ;
unsigned long V_53 ;
int V_26 = 0 ;
int V_27 ;
F_16 ( & V_6 -> V_55 , V_53 ) ;
if ( F_5 ( V_8 ) & V_64 ) {
memcpy ( V_8 -> V_14 . V_15 . V_65 ,
V_8 -> V_14 . V_15 . V_66 , V_25 ) ;
} else if ( V_47 -> V_56 == 0 ) {
V_26 = F_3 ( V_2 , V_18 ) ;
goto V_18;
}
F_5 ( V_8 ) &= ~ V_67 ;
V_27 = V_47 -> V_56 ;
V_22 = F_6 ( V_6 -> V_22 , ( T_1 * ) V_47 -> V_57 ,
& V_27 , V_6 -> V_10 -> V_33 ) ;
if ( V_27 != V_47 -> V_56 ) {
V_26 = - V_13 ;
goto V_18;
}
V_27 = V_25 ;
V_23 = F_6 ( V_6 -> V_23 , V_18 , & V_27 ,
V_6 -> V_10 -> V_33 ) ;
if ( V_27 != V_25 ) {
V_26 = - V_13 ;
goto V_18;
}
V_6 -> V_34 . V_35 = ( V_6 -> V_22 - V_22 ) * sizeof( struct V_21 ) ;
V_6 -> V_34 . V_36 = ( V_6 -> V_23 - V_23 ) * sizeof( struct V_21 ) ;
if ( ! V_6 -> V_34 . V_36 ) {
V_26 = - V_13 ;
goto V_18;
}
V_26 = F_7 ( V_6 , & V_6 -> V_34 ,
V_2 -> V_37 & V_38 ) ;
if ( V_26 )
goto V_18;
F_8 ( & ( V_6 -> V_39 -> V_40 ) ) ;
memcpy ( V_18 , V_8 -> V_14 . V_15 . V_66 , V_25 ) ;
V_18:
F_18 ( & V_6 -> V_55 , V_53 ) ;
return V_26 ;
}
