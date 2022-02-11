static void
F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
enum V_7 V_8 ,
const struct V_9 * V_10 )
{
F_2 ( V_2 , V_4 , V_6 , V_8 , V_10 ,
& V_11 ) ;
}
static bool
F_3 ( struct V_12 * V_13 ,
const struct V_1 * V_2 ,
unsigned int V_14 , unsigned int V_15 ,
const struct V_3 * V_4 ,
enum V_7 V_8 )
{
struct V_16 * V_17 ;
int V_18 = 8 ;
if ( V_13 -> V_19 >= V_15 + sizeof( * V_17 ) )
V_18 = sizeof( * V_17 ) ;
if ( ! F_4 ( V_13 , V_15 + V_18 ) )
return false ;
V_17 = (struct V_16 * ) ( V_13 -> V_20 + V_15 ) ;
if ( V_8 == V_21 ) {
V_17 -> V_22 = V_4 -> V_23 . V_24 . V_25 . V_26 ;
} else {
V_17 -> V_27 = V_4 -> V_28 . V_24 . V_25 . V_26 ;
}
if ( V_18 < sizeof( * V_17 ) )
return true ;
if ( V_13 -> V_29 != V_30 ) {
V_17 -> V_31 = F_5 ( V_13 , V_15 ) ;
V_13 -> V_29 = V_32 ;
}
return true ;
}
