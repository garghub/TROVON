static void F_1 ( T_1 * V_1 , T_2 V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
T_1 V_7 = V_4 -> V_7 ;
T_1 V_8 = V_7 >> V_9 ;
bool V_10 = ! ! ( V_7 & V_11 ) ;
T_3 * V_12 ;
T_4 V_13 ;
T_1 V_14 = V_4 -> V_15 ;
int V_16 ;
V_1 [ 0 ] = V_17 ;
V_1 [ 1 ] = V_2 - 2 ;
V_1 [ 2 ] = ( V_18 >> 16 ) & 0xff ;
V_1 [ 3 ] = ( V_18 >> 8 ) & 0xff ;
V_1 [ 4 ] = ( V_18 >> 0 ) & 0xff ;
V_1 [ 5 ] = V_19 ;
V_1 [ 6 ] = V_20 ;
V_12 = ( T_3 * ) & V_1 [ 7 ] ;
V_6 = (struct V_5 * ) & V_1 [ 9 ] ;
V_6 -> V_21 = V_4 -> V_21 ;
V_6 -> V_22 = V_8 ;
if ( V_10 )
V_6 -> V_22 |= V_23 ;
for ( V_16 = 0 ; V_16 < V_14 ; V_16 ++ ) {
V_6 -> V_24 [ V_16 ] . V_25 =
F_2 ( V_4 -> V_26 [ V_16 ] . V_27 ) ;
V_6 -> V_24 [ V_16 ] . V_28 = V_4 -> V_26 [ V_16 ] . V_28 ;
V_6 -> V_24 [ V_16 ] . V_29 = V_4 -> V_26 [ V_16 ] . V_29 ;
V_6 -> V_24 [ V_16 ] . V_30 = V_4 -> V_26 [ V_16 ] . V_30 ;
}
V_13 = 2 ;
V_13 += V_14 * sizeof( struct V_31 ) ;
* V_12 = F_3 ( V_13 ) ;
}
static T_2 F_4 ( const struct V_3 * V_4 )
{
T_2 V_2 = 0 ;
if ( ! V_4 -> V_15 &&
! ( V_4 -> V_7 & V_11 ) )
return 0 ;
V_2 += 1 + 1 + 4 ;
V_2 += 1 + 2 ;
V_2 += 1 + 1 ;
V_2 += V_4 -> V_15 * sizeof( struct V_31 ) ;
return V_2 ;
}
static void F_5 ( struct V_32 * V_33 , void * V_34 ,
T_2 V_2 )
{
struct V_35 * V_36 = V_33 -> V_36 ;
F_6 ( & V_36 -> V_37 ) ;
F_7 ( V_33 -> V_38 . V_39 . V_40 ) ;
V_33 -> V_38 . V_39 . V_40 = V_34 ;
V_33 -> V_38 . V_39 . V_41 = V_2 ;
}
static void F_8 ( struct V_32 * V_33 ,
const struct V_3 * V_4 )
{
struct V_35 * V_36 = V_33 -> V_36 ;
void * V_34 ;
T_2 V_2 ;
F_6 ( & V_36 -> V_37 ) ;
F_5 ( V_33 , NULL , 0 ) ;
V_2 = F_4 ( V_4 ) ;
if ( ! V_2 )
return;
V_34 = F_9 ( V_2 , V_42 ) ;
if ( ! V_34 )
return;
F_1 ( V_34 , V_2 , V_4 ) ;
F_5 ( V_33 , V_34 , V_2 ) ;
}
void F_10 ( struct V_32 * V_33 ,
const struct V_3 * V_4 )
{
struct V_35 * V_36 = V_33 -> V_36 ;
F_11 ( & V_36 -> V_37 ) ;
F_8 ( V_33 , V_4 ) ;
F_12 ( & V_36 -> V_37 ) ;
}
static void F_13 ( void * V_1 , T_1 * V_43 ,
struct V_44 * V_45 )
{
struct V_32 * V_33 = ( void * ) V_45 -> V_46 ;
struct V_47 * V_48 = V_1 ;
if ( V_33 -> V_49 != V_48 -> V_49 )
return;
F_10 ( V_33 , V_48 -> V_4 ) ;
}
void F_14 ( struct V_35 * V_36 , T_5 V_49 ,
const struct V_3 * V_4 )
{
struct V_47 V_48 = {
. V_49 = V_49 ,
. V_4 = V_4 ,
} ;
F_15 ( V_36 -> V_50 ,
V_51 ,
F_13 ,
& V_48 ) ;
}
