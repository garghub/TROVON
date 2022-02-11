static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
V_5 = F_3 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_4 ( V_4 , V_6 ) ;
V_4 -> V_7 = & V_4 -> V_8 [ V_9 ] ;
F_5 ( V_4 -> V_10 , V_11 ) ;
return 0 ;
}
static int F_6 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_7 ( V_13 ) ;
memset ( V_15 , 0 , sizeof *V_15 ) ;
V_15 -> V_16 [ 0 ] = F_8 ( V_17 ) ;
V_15 -> V_16 [ 1 ] = F_8 ( V_18 ) ;
V_15 -> V_16 [ 2 ] = F_8 ( V_19 ) ;
V_15 -> V_16 [ 3 ] = F_8 ( V_20 ) ;
V_15 -> V_16 [ 4 ] = F_8 ( V_21 ) ;
V_15 -> V_16 [ 5 ] = F_8 ( V_22 ) ;
V_15 -> V_16 [ 6 ] = F_8 ( V_23 ) ;
V_15 -> V_16 [ 7 ] = F_8 ( V_24 ) ;
V_15 -> V_25 [ 0 ] = 0 ;
return 0 ;
}
static int F_9 ( struct V_12 * V_13 , const T_1 * V_26 ,
unsigned int V_27 )
{
struct V_14 * V_15 = F_7 ( V_13 ) ;
struct V_3 * V_4 = F_2 ( & V_13 -> V_2 -> V_28 ) ;
struct V_29 * V_10 = (struct V_29 * ) V_4 -> V_10 ;
struct V_30 * V_31 ;
T_2 V_32 , V_33 = 0 , V_34 ;
unsigned long V_35 ;
int V_36 = 0 ;
int V_37 ;
T_3 V_38 ;
T_2 V_39 = ( V_15 -> V_25 [ 0 ] % V_40 ) ;
F_10 ( & V_4 -> V_41 , V_35 ) ;
V_34 = ( V_15 -> V_25 [ 0 ] % V_40 ) + V_27 ;
if ( V_34 < V_40 ) {
memcpy ( V_15 -> V_42 + V_39 , V_26 , V_27 ) ;
V_15 -> V_25 [ 0 ] += V_27 ;
goto V_43;
}
memcpy ( V_10 -> V_44 . V_45 . V_46 , V_15 -> V_16 , V_47 ) ;
F_11 ( V_10 ) |= V_48 ;
F_11 ( V_10 ) |= V_49 ;
V_38 = F_12 ( T_2 , V_4 -> V_7 -> V_50 ,
V_51 . V_52 . V_38 / sizeof( struct V_30 ) ) ;
V_38 = F_12 ( T_2 , V_38 ,
V_4 -> V_7 -> V_53 / V_54 ) ;
V_37 = V_47 ;
V_31 = F_13 ( V_4 -> V_31 , ( T_1 * ) V_15 -> V_16 ,
& V_37 , V_38 ) ;
V_4 -> V_55 . V_56 = ( V_4 -> V_31 - V_31 ) * sizeof( struct V_30 ) ;
if ( V_37 != V_47 ) {
V_36 = - V_57 ;
goto V_43;
}
do {
int V_58 = 0 ;
struct V_30 * V_59 = V_4 -> V_59 ;
if ( V_39 ) {
V_37 = V_39 ;
V_59 = F_13 ( V_59 ,
( T_1 * ) V_15 -> V_42 ,
& V_37 , V_38 ) ;
if ( V_37 != V_39 ) {
V_36 = - V_57 ;
goto V_43;
}
V_58 = V_59 - V_4 -> V_59 ;
}
V_32 = F_12 ( T_2 , V_34 ,
( V_38 - 1 - V_58 ) * V_54 ) ;
V_32 = V_32 & ~ ( V_40 - 1 ) ;
V_37 = V_32 - V_39 ;
V_59 = F_13 ( V_59 , ( T_1 * ) V_26 ,
& V_37 , V_38 ) ;
V_4 -> V_55 . V_60 = ( V_4 -> V_59 - V_59 ) * sizeof( struct V_30 ) ;
if ( V_37 != ( V_32 - V_39 ) ) {
V_36 = - V_57 ;
goto V_43;
}
V_32 = V_37 + V_39 ;
V_33 = V_34 - V_32 ;
memcpy ( V_10 -> V_44 . V_45 . V_61 ,
V_10 -> V_44 . V_45 . V_46 ,
V_47 ) ;
if ( ! V_4 -> V_55 . V_60 || ! V_4 -> V_55 . V_56 ) {
V_36 = - V_57 ;
goto V_43;
}
V_36 = F_14 ( V_4 , & V_4 -> V_55 ,
V_13 -> V_62 & V_63 ) ;
if ( V_36 )
goto V_43;
F_15 ( & ( V_4 -> V_64 -> V_65 ) ) ;
V_34 -= V_32 ;
V_26 += V_32 - V_39 ;
V_39 = 0 ;
} while ( V_33 >= V_40 );
if ( V_33 )
memcpy ( V_15 -> V_42 , V_26 , V_33 ) ;
V_15 -> V_25 [ 0 ] += V_27 ;
memcpy ( V_15 -> V_16 , V_10 -> V_44 . V_45 . V_46 , V_47 ) ;
V_43:
F_16 ( & V_4 -> V_41 , V_35 ) ;
return V_36 ;
}
static int F_17 ( struct V_12 * V_13 , T_1 * V_43 )
{
struct V_14 * V_15 = F_7 ( V_13 ) ;
struct V_3 * V_4 = F_2 ( & V_13 -> V_2 -> V_28 ) ;
struct V_29 * V_10 = (struct V_29 * ) V_4 -> V_10 ;
struct V_30 * V_59 , * V_31 ;
T_3 V_38 ;
T_2 V_66 ;
unsigned long V_35 ;
int V_36 = 0 ;
int V_27 ;
F_10 ( & V_4 -> V_41 , V_35 ) ;
V_38 = F_12 ( T_2 , V_4 -> V_7 -> V_50 ,
V_51 . V_52 . V_38 / sizeof( struct V_30 ) ) ;
V_38 = F_12 ( T_2 , V_38 ,
V_4 -> V_7 -> V_53 / V_54 ) ;
if ( V_15 -> V_25 [ 0 ] >= V_40 ) {
memcpy ( V_10 -> V_44 . V_45 . V_61 , V_15 -> V_16 ,
V_47 ) ;
F_11 ( V_10 ) &= ~ V_48 ;
F_11 ( V_10 ) |= V_49 ;
} else {
F_11 ( V_10 ) &= ~ V_48 ;
F_11 ( V_10 ) &= ~ V_49 ;
}
F_11 ( V_10 ) &= ~ V_48 ;
V_66 = V_15 -> V_25 [ 0 ] * 8 ;
V_10 -> V_44 . V_45 . V_67 = V_66 ;
V_27 = V_15 -> V_25 [ 0 ] & ( V_40 - 1 ) ;
V_59 = F_13 ( V_4 -> V_59 , V_15 -> V_42 , & V_27 ,
V_38 ) ;
if ( V_27 != ( V_15 -> V_25 [ 0 ] & ( V_40 - 1 ) ) ) {
V_36 = - V_57 ;
goto V_43;
}
V_27 = V_47 ;
V_31 = F_13 ( V_4 -> V_31 , V_43 , & V_27 ,
V_38 ) ;
V_4 -> V_55 . V_60 = ( V_4 -> V_59 - V_59 ) * sizeof( struct V_30 ) ;
V_4 -> V_55 . V_56 = ( V_4 -> V_31 - V_31 ) * sizeof( struct V_30 ) ;
if ( ! V_4 -> V_55 . V_56 ) {
V_36 = - V_57 ;
goto V_43;
}
V_36 = F_14 ( V_4 , & V_4 -> V_55 ,
V_13 -> V_62 & V_63 ) ;
if ( V_36 )
goto V_43;
F_15 ( & ( V_4 -> V_64 -> V_65 ) ) ;
F_18 ( V_15 -> V_25 [ 0 ] , & ( V_4 -> V_64 -> V_68 ) ) ;
memcpy ( V_43 , V_10 -> V_44 . V_45 . V_46 , V_47 ) ;
V_43:
F_16 ( & V_4 -> V_41 , V_35 ) ;
return V_36 ;
}
static int F_19 ( struct V_12 * V_13 , void * V_43 )
{
struct V_14 * V_15 = F_7 ( V_13 ) ;
memcpy ( V_43 , V_15 , sizeof( * V_15 ) ) ;
return 0 ;
}
static int F_20 ( struct V_12 * V_13 , const void * V_69 )
{
struct V_14 * V_15 = F_7 ( V_13 ) ;
memcpy ( V_15 , V_69 , sizeof( * V_15 ) ) ;
return 0 ;
}
