static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( & V_2 -> V_7 -> V_8 ) ;
struct V_9 * V_10 ;
F_4 ( V_6 , V_11 ) ;
memset ( V_4 , 0 , sizeof *V_4 ) ;
V_6 -> V_12 = & V_6 -> V_13 [ V_14 ] ;
F_5 ( V_6 -> V_15 , V_16 ) ;
V_10 = F_6 ( V_6 -> V_10 , ( V_17 * ) V_4 -> V_18 ,
V_19 , V_6 -> V_12 -> V_20 ) ;
V_6 -> V_21 . V_22 = ( V_6 -> V_10 - V_10 ) * sizeof( struct V_9 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , const V_17 * V_23 ,
unsigned int V_24 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( & V_2 -> V_7 -> V_8 ) ;
struct V_25 * V_15 = (struct V_25 * ) V_6 -> V_15 ;
struct V_9 * V_26 ;
T_1 V_27 , V_28 ;
int V_29 = 0 ;
if ( F_8 ( V_15 ) & V_30 ) {
memcpy ( V_15 -> V_31 . V_32 . V_33 ,
V_15 -> V_31 . V_32 . V_34 , V_19 ) ;
}
if ( V_24 + V_4 -> V_35 < V_36 ) {
memcpy ( V_4 -> V_37 + V_4 -> V_35 , V_23 , V_24 ) ;
V_4 -> V_35 += V_24 ;
goto V_38;
}
V_27 = ( V_4 -> V_35 + V_24 ) & ~ ( V_36 - 1 ) ;
V_28 = ( V_4 -> V_35 + V_24 ) & ( V_36 - 1 ) ;
if ( V_4 -> V_35 ) {
V_26 = F_6 ( V_6 -> V_26 , ( V_17 * ) V_4 -> V_37 ,
V_4 -> V_35 , V_6 -> V_12 -> V_20 ) ;
V_26 = F_6 ( V_26 , ( V_17 * ) V_23 ,
V_27 - V_4 -> V_35 ,
V_6 -> V_12 -> V_20 ) ;
V_6 -> V_21 . V_39 = ( V_6 -> V_26 - V_26 ) *
sizeof( struct V_9 ) ;
} else {
V_26 = F_6 ( V_6 -> V_26 , ( V_17 * ) V_23 ,
V_27 , V_6 -> V_12 -> V_20 ) ;
V_6 -> V_21 . V_39 = ( V_6 -> V_26 - V_26 ) *
sizeof( struct V_9 ) ;
}
F_8 ( V_15 ) |= V_40 ;
if ( ! V_6 -> V_21 . V_39 || ! V_6 -> V_21 . V_22 ) {
V_29 = - V_41 ;
goto V_38;
}
V_29 = F_9 ( V_6 , & V_6 -> V_21 ,
V_2 -> V_42 & V_43 ) ;
if ( V_29 )
goto V_38;
F_10 ( & ( V_6 -> V_44 -> V_45 ) ) ;
if ( V_28 )
memcpy ( V_4 -> V_37 , V_23 + V_24 - V_28 , V_28 ) ;
V_4 -> V_35 = V_28 ;
V_15 -> V_31 . V_32 . V_46 += ( T_1 )
( V_15 -> V_31 . V_32 . V_47 * 8 ) ;
F_8 ( V_15 ) |= V_30 ;
V_38:
return V_29 ;
}
static int F_11 ( struct V_1 * V_2 , V_17 * V_38 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( & V_2 -> V_7 -> V_8 ) ;
struct V_25 * V_15 = (struct V_25 * ) V_6 -> V_15 ;
struct V_9 * V_26 , * V_10 ;
int V_29 ;
if ( F_8 ( V_15 ) & V_30 ) {
memcpy ( V_15 -> V_31 . V_32 . V_33 ,
V_15 -> V_31 . V_32 . V_34 , V_19 ) ;
}
F_8 ( V_15 ) &= ~ V_40 ;
V_15 -> V_31 . V_32 . V_46 += ( T_1 ) ( V_4 -> V_35 * 8 ) ;
V_26 = F_6 ( V_6 -> V_26 , ( V_17 * ) V_4 -> V_37 ,
V_4 -> V_35 , V_6 -> V_12 -> V_20 ) ;
V_10 = F_6 ( V_6 -> V_10 , V_38 , V_19 ,
V_6 -> V_12 -> V_20 ) ;
V_6 -> V_21 . V_39 = ( V_6 -> V_26 - V_26 ) * sizeof( struct V_9 ) ;
V_6 -> V_21 . V_22 = ( V_6 -> V_10 - V_10 ) * sizeof( struct V_9 ) ;
if ( ! V_6 -> V_21 . V_22 ) {
V_29 = - V_41 ;
goto V_38;
}
V_29 = F_9 ( V_6 , & V_6 -> V_21 ,
V_2 -> V_42 & V_43 ) ;
if ( V_29 )
goto V_38;
F_10 ( & ( V_6 -> V_44 -> V_45 ) ) ;
F_12 ( V_15 -> V_31 . V_32 . V_46 / 8 ,
& ( V_6 -> V_44 -> V_48 ) ) ;
memcpy ( V_38 , V_15 -> V_31 . V_32 . V_34 , V_19 ) ;
V_38:
return V_29 ;
}
static int F_13 ( struct V_1 * V_2 , void * V_38 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( & V_2 -> V_7 -> V_8 ) ;
struct V_25 * V_15 = (struct V_25 * ) V_6 -> V_15 ;
struct V_3 * V_49 = V_38 ;
V_49 -> V_35 = V_4 -> V_35 +
( V_15 -> V_31 . V_32 . V_46 / 8 ) ;
memcpy ( V_49 -> V_37 , V_4 -> V_37 , sizeof( V_49 -> V_37 ) ) ;
if ( V_15 -> V_31 . V_32 . V_46 )
memcpy ( V_49 -> V_18 , V_15 -> V_31 . V_32 . V_34 ,
V_19 ) ;
else {
V_49 -> V_18 [ 0 ] = V_50 ;
V_49 -> V_18 [ 1 ] = V_51 ;
V_49 -> V_18 [ 2 ] = V_52 ;
V_49 -> V_18 [ 3 ] = V_53 ;
V_49 -> V_18 [ 4 ] = V_54 ;
V_49 -> V_18 [ 5 ] = V_55 ;
V_49 -> V_18 [ 6 ] = V_56 ;
V_49 -> V_18 [ 7 ] = V_57 ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , const void * V_58 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( & V_2 -> V_7 -> V_8 ) ;
struct V_25 * V_15 = (struct V_25 * ) V_6 -> V_15 ;
const struct V_3 * V_59 = V_58 ;
memcpy ( V_4 -> V_37 , V_59 -> V_37 , sizeof( V_59 -> V_37 ) ) ;
V_4 -> V_35 = V_59 -> V_35 & 0x3f ;
V_15 -> V_31 . V_32 . V_46 = ( V_59 -> V_35 & ~ 0x3f ) * 8 ;
if ( V_15 -> V_31 . V_32 . V_46 ) {
memcpy ( V_15 -> V_31 . V_32 . V_34 , V_59 -> V_18 ,
V_19 ) ;
F_8 ( V_15 ) |= V_30 ;
F_8 ( V_15 ) |= V_40 ;
}
return 0 ;
}
