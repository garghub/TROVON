static void
F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
enum V_5 V_6 ,
const struct V_7 * V_8 )
{
F_2 ( V_2 , V_4 , V_6 , V_8 , & V_9 ) ;
}
static bool
F_3 ( struct V_10 * V_11 ,
unsigned int V_12 ,
const struct V_1 * V_2 ,
enum V_5 V_6 )
{
const struct V_13 * V_14 = (struct V_13 * ) ( V_11 -> V_15 + V_12 ) ;
struct V_16 * V_17 ;
unsigned int V_18 = V_12 + V_14 -> V_19 * 4 ;
T_1 V_20 , V_21 ;
T_2 * V_22 , V_23 , V_24 ;
int V_25 = 8 ;
if ( V_11 -> V_26 >= V_18 + sizeof( struct V_16 ) )
V_25 = sizeof( struct V_16 ) ;
if ( ! F_4 ( V_11 , V_18 + V_25 ) )
return false ;
V_14 = (struct V_13 * ) ( V_11 -> V_15 + V_12 ) ;
V_17 = (struct V_16 * ) ( V_11 -> V_15 + V_18 ) ;
if ( V_6 == V_27 ) {
V_20 = V_14 -> V_28 ;
V_21 = V_2 -> V_29 . V_30 . V_31 ;
V_23 = V_2 -> V_29 . V_32 . V_33 . V_34 ;
V_22 = & V_17 -> V_35 ;
} else {
V_20 = V_14 -> V_36 ;
V_21 = V_2 -> V_37 . V_30 . V_31 ;
V_23 = V_2 -> V_37 . V_32 . V_33 . V_34 ;
V_22 = & V_17 -> V_38 ;
}
V_24 = * V_22 ;
* V_22 = V_23 ;
if ( V_25 < sizeof( * V_17 ) )
return true ;
F_5 ( & V_17 -> V_39 , V_11 , V_20 , V_21 , 1 ) ;
F_6 ( & V_17 -> V_39 , V_11 , V_24 , V_23 , 0 ) ;
return true ;
}
