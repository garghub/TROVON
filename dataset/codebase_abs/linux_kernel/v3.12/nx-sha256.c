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
T_1 V_27 , V_28 , V_29 ;
T_2 V_30 ;
unsigned long V_31 ;
int V_32 = 0 ;
F_8 ( & V_6 -> V_33 , V_31 ) ;
V_29 = V_4 -> V_34 + V_24 ;
if ( V_29 < V_35 ) {
memcpy ( V_4 -> V_36 + V_4 -> V_34 , V_23 , V_24 ) ;
V_4 -> V_34 += V_24 ;
goto V_37;
}
V_26 = V_6 -> V_26 ;
V_30 = F_9 ( T_2 , V_38 . V_39 . V_30 / sizeof( struct V_9 ) ,
V_6 -> V_12 -> V_20 ) ;
do {
V_27 = F_9 ( T_1 , V_29 , V_6 -> V_12 -> V_40 ) ;
V_27 = F_9 ( T_1 , V_27 ,
V_41 * ( V_30 - 1 ) ) ;
V_27 = V_27 & ~ ( V_35 - 1 ) ;
V_28 = V_29 - V_27 ;
if ( V_4 -> V_34 ) {
V_26 = F_6 ( V_6 -> V_26 ,
( V_17 * ) V_4 -> V_36 ,
V_4 -> V_34 , V_30 ) ;
}
V_26 = F_6 ( V_26 , ( V_17 * ) V_23 ,
V_27 - V_4 -> V_34 ,
V_30 ) ;
V_6 -> V_21 . V_42 = ( V_6 -> V_26 - V_26 ) *
sizeof( struct V_9 ) ;
if ( F_10 ( V_15 ) & V_43 ) {
memcpy ( V_15 -> V_44 . V_45 . V_46 ,
V_15 -> V_44 . V_45 . V_47 ,
V_19 ) ;
}
F_10 ( V_15 ) |= V_48 ;
if ( ! V_6 -> V_21 . V_42 || ! V_6 -> V_21 . V_22 ) {
V_32 = - V_49 ;
goto V_37;
}
V_32 = F_11 ( V_6 , & V_6 -> V_21 ,
V_2 -> V_50 & V_51 ) ;
if ( V_32 )
goto V_37;
F_12 ( & ( V_6 -> V_52 -> V_53 ) ) ;
V_15 -> V_44 . V_45 . V_54 += ( T_1 )
( V_15 -> V_44 . V_45 . V_55 * 8 ) ;
F_10 ( V_15 ) |= V_43 ;
V_29 -= V_27 ;
V_23 += V_27 - V_4 -> V_34 ;
V_4 -> V_34 = 0 ;
V_26 = V_6 -> V_26 ;
} while ( V_28 >= V_35 );
if ( V_28 )
memcpy ( V_4 -> V_36 , V_23 , V_28 ) ;
V_4 -> V_34 = V_28 ;
V_37:
F_13 ( & V_6 -> V_33 , V_31 ) ;
return V_32 ;
}
static int F_14 ( struct V_1 * V_2 , V_17 * V_37 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( & V_2 -> V_7 -> V_8 ) ;
struct V_25 * V_15 = (struct V_25 * ) V_6 -> V_15 ;
struct V_9 * V_26 , * V_10 ;
T_2 V_30 ;
unsigned long V_31 ;
int V_32 ;
F_8 ( & V_6 -> V_33 , V_31 ) ;
V_30 = F_9 ( T_2 , V_38 . V_39 . V_30 , V_6 -> V_12 -> V_20 ) ;
if ( F_10 ( V_15 ) & V_43 ) {
memcpy ( V_15 -> V_44 . V_45 . V_46 ,
V_15 -> V_44 . V_45 . V_47 , V_19 ) ;
}
F_10 ( V_15 ) &= ~ V_48 ;
V_15 -> V_44 . V_45 . V_54 += ( T_1 ) ( V_4 -> V_34 * 8 ) ;
V_26 = F_6 ( V_6 -> V_26 , ( V_17 * ) V_4 -> V_36 ,
V_4 -> V_34 , V_30 ) ;
V_10 = F_6 ( V_6 -> V_10 , V_37 , V_19 ,
V_30 ) ;
V_6 -> V_21 . V_42 = ( V_6 -> V_26 - V_26 ) * sizeof( struct V_9 ) ;
V_6 -> V_21 . V_22 = ( V_6 -> V_10 - V_10 ) * sizeof( struct V_9 ) ;
if ( ! V_6 -> V_21 . V_22 ) {
V_32 = - V_49 ;
goto V_37;
}
V_32 = F_11 ( V_6 , & V_6 -> V_21 ,
V_2 -> V_50 & V_51 ) ;
if ( V_32 )
goto V_37;
F_12 ( & ( V_6 -> V_52 -> V_53 ) ) ;
F_15 ( V_15 -> V_44 . V_45 . V_54 / 8 ,
& ( V_6 -> V_52 -> V_56 ) ) ;
memcpy ( V_37 , V_15 -> V_44 . V_45 . V_47 , V_19 ) ;
V_37:
F_13 ( & V_6 -> V_33 , V_31 ) ;
return V_32 ;
}
static int F_16 ( struct V_1 * V_2 , void * V_37 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( & V_2 -> V_7 -> V_8 ) ;
struct V_25 * V_15 = (struct V_25 * ) V_6 -> V_15 ;
struct V_3 * V_57 = V_37 ;
unsigned long V_31 ;
F_8 ( & V_6 -> V_33 , V_31 ) ;
V_57 -> V_34 = V_4 -> V_34 +
( V_15 -> V_44 . V_45 . V_54 / 8 ) ;
memcpy ( V_57 -> V_36 , V_4 -> V_36 , sizeof( V_57 -> V_36 ) ) ;
if ( V_15 -> V_44 . V_45 . V_54 )
memcpy ( V_57 -> V_18 , V_15 -> V_44 . V_45 . V_47 ,
V_19 ) ;
else {
V_57 -> V_18 [ 0 ] = V_58 ;
V_57 -> V_18 [ 1 ] = V_59 ;
V_57 -> V_18 [ 2 ] = V_60 ;
V_57 -> V_18 [ 3 ] = V_61 ;
V_57 -> V_18 [ 4 ] = V_62 ;
V_57 -> V_18 [ 5 ] = V_63 ;
V_57 -> V_18 [ 6 ] = V_64 ;
V_57 -> V_18 [ 7 ] = V_65 ;
}
F_13 ( & V_6 -> V_33 , V_31 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , const void * V_66 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( & V_2 -> V_7 -> V_8 ) ;
struct V_25 * V_15 = (struct V_25 * ) V_6 -> V_15 ;
const struct V_3 * V_67 = V_66 ;
unsigned long V_31 ;
F_8 ( & V_6 -> V_33 , V_31 ) ;
memcpy ( V_4 -> V_36 , V_67 -> V_36 , sizeof( V_67 -> V_36 ) ) ;
V_4 -> V_34 = V_67 -> V_34 & 0x3f ;
V_15 -> V_44 . V_45 . V_54 = ( V_67 -> V_34 & ~ 0x3f ) * 8 ;
if ( V_15 -> V_44 . V_45 . V_54 ) {
memcpy ( V_15 -> V_44 . V_45 . V_47 , V_67 -> V_18 ,
V_19 ) ;
F_10 ( V_15 ) |= V_43 ;
F_10 ( V_15 ) |= V_48 ;
}
F_13 ( & V_6 -> V_33 , V_31 ) ;
return 0 ;
}
