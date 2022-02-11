static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( & V_2 -> V_7 -> V_8 ) ;
int V_9 ;
int V_10 ;
F_4 ( V_6 , V_11 ) ;
memset ( V_4 , 0 , sizeof *V_4 ) ;
V_6 -> V_12 = & V_6 -> V_13 [ V_14 ] ;
F_5 ( V_6 -> V_15 , V_16 ) ;
V_9 = V_17 ;
V_10 = F_6 ( V_6 , V_6 -> V_18 ,
& V_6 -> V_19 . V_20 ,
& V_9 ,
( V_21 * ) V_4 -> V_22 ,
V_16 ) ;
if ( V_10 )
goto V_23;
V_4 -> V_22 [ 0 ] = F_7 ( V_24 ) ;
V_4 -> V_22 [ 1 ] = F_7 ( V_25 ) ;
V_4 -> V_22 [ 2 ] = F_7 ( V_26 ) ;
V_4 -> V_22 [ 3 ] = F_7 ( V_27 ) ;
V_4 -> V_22 [ 4 ] = F_7 ( V_28 ) ;
V_4 -> V_22 [ 5 ] = F_7 ( V_29 ) ;
V_4 -> V_22 [ 6 ] = F_7 ( V_30 ) ;
V_4 -> V_22 [ 7 ] = F_7 ( V_31 ) ;
V_4 -> V_32 = 0 ;
V_23:
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , const V_21 * V_33 ,
unsigned int V_9 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( & V_2 -> V_7 -> V_8 ) ;
struct V_34 * V_15 = (struct V_34 * ) V_6 -> V_15 ;
T_1 V_35 = 0 , V_36 , V_37 ;
unsigned long V_38 ;
int V_10 = 0 ;
int V_39 ;
T_1 V_40 = ( V_4 -> V_32 % V_41 ) ;
F_9 ( & V_6 -> V_42 , V_38 ) ;
V_37 = ( V_4 -> V_32 % V_41 ) + V_9 ;
if ( V_37 < V_41 ) {
memcpy ( V_4 -> V_43 + V_40 , V_33 , V_9 ) ;
V_4 -> V_32 += V_9 ;
goto V_23;
}
memcpy ( V_15 -> V_44 . V_45 . V_46 , V_4 -> V_22 , V_17 ) ;
F_10 ( V_15 ) |= V_47 ;
F_10 ( V_15 ) |= V_48 ;
do {
V_35 = V_37 - V_35 ;
V_35 = V_35 & ~ ( V_41 - 1 ) ;
if ( V_40 ) {
V_39 = V_40 ;
V_10 = F_6 ( V_6 , V_6 -> V_49 ,
& V_6 -> V_19 . V_50 ,
& V_39 ,
( V_21 * ) V_4 -> V_43 ,
V_16 ) ;
if ( V_10 || V_39 != V_40 )
goto V_23;
}
V_39 = V_35 - V_40 ;
V_10 = F_6 ( V_6 , V_6 -> V_49 ,
& V_6 -> V_19 . V_50 ,
& V_39 ,
( V_21 * ) V_33 ,
V_16 ) ;
if ( V_10 )
goto V_23;
V_35 = ( V_39 + V_40 ) ;
V_36 = V_37 - V_35 ;
memcpy ( V_15 -> V_44 . V_45 . V_51 ,
V_15 -> V_44 . V_45 . V_46 ,
V_17 ) ;
if ( ! V_6 -> V_19 . V_50 || ! V_6 -> V_19 . V_20 ) {
V_10 = - V_52 ;
goto V_23;
}
V_10 = F_11 ( V_6 , & V_6 -> V_19 ,
V_2 -> V_53 & V_54 ) ;
if ( V_10 )
goto V_23;
F_12 ( & ( V_6 -> V_55 -> V_56 ) ) ;
V_37 -= V_35 ;
V_33 += V_35 - V_40 ;
V_40 = 0 ;
} while ( V_36 >= V_41 );
if ( V_36 )
memcpy ( V_4 -> V_43 , V_33 , V_36 ) ;
V_4 -> V_32 += V_9 ;
memcpy ( V_4 -> V_22 , V_15 -> V_44 . V_45 . V_46 , V_17 ) ;
V_23:
F_13 ( & V_6 -> V_42 , V_38 ) ;
return V_10 ;
}
static int F_14 ( struct V_1 * V_2 , V_21 * V_23 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( & V_2 -> V_7 -> V_8 ) ;
struct V_34 * V_15 = (struct V_34 * ) V_6 -> V_15 ;
unsigned long V_38 ;
int V_10 ;
int V_9 ;
F_9 ( & V_6 -> V_42 , V_38 ) ;
if ( V_4 -> V_32 >= V_41 ) {
memcpy ( V_15 -> V_44 . V_45 . V_51 , V_4 -> V_22 , V_17 ) ;
F_10 ( V_15 ) &= ~ V_47 ;
F_10 ( V_15 ) |= V_48 ;
} else {
F_10 ( V_15 ) &= ~ V_47 ;
F_10 ( V_15 ) &= ~ V_48 ;
}
V_15 -> V_44 . V_45 . V_57 = ( T_1 ) ( V_4 -> V_32 * 8 ) ;
V_9 = V_4 -> V_32 & ( V_41 - 1 ) ;
V_10 = F_6 ( V_6 , V_6 -> V_49 ,
& V_6 -> V_19 . V_50 ,
& V_9 ,
( V_21 * ) V_4 -> V_43 ,
V_16 ) ;
if ( V_10 || V_9 != ( V_4 -> V_32 & ( V_41 - 1 ) ) )
goto V_23;
V_9 = V_17 ;
V_10 = F_6 ( V_6 , V_6 -> V_18 ,
& V_6 -> V_19 . V_20 ,
& V_9 ,
V_23 ,
V_16 ) ;
if ( V_10 || V_9 != V_17 )
goto V_23;
if ( ! V_6 -> V_19 . V_20 ) {
V_10 = - V_52 ;
goto V_23;
}
V_10 = F_11 ( V_6 , & V_6 -> V_19 ,
V_2 -> V_53 & V_54 ) ;
if ( V_10 )
goto V_23;
F_12 ( & ( V_6 -> V_55 -> V_56 ) ) ;
F_15 ( V_4 -> V_32 , & ( V_6 -> V_55 -> V_58 ) ) ;
memcpy ( V_23 , V_15 -> V_44 . V_45 . V_46 , V_17 ) ;
V_23:
F_13 ( & V_6 -> V_42 , V_38 ) ;
return V_10 ;
}
static int F_16 ( struct V_1 * V_2 , void * V_23 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
memcpy ( V_23 , V_4 , sizeof( * V_4 ) ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , const void * V_59 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
memcpy ( V_4 , V_59 , sizeof( * V_4 ) ) ;
return 0 ;
}
