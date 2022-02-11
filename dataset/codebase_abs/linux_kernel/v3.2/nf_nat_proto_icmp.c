static bool
F_1 ( const struct V_1 * V_2 ,
enum V_3 V_4 ,
const union V_5 * V_6 ,
const union V_5 * V_7 )
{
return F_2 ( V_2 -> V_8 . V_9 . V_10 . V_11 ) >= F_2 ( V_6 -> V_10 . V_11 ) &&
F_2 ( V_2 -> V_8 . V_9 . V_10 . V_11 ) <= F_2 ( V_7 -> V_10 . V_11 ) ;
}
static void
F_3 ( struct V_1 * V_2 ,
const struct V_12 * V_13 ,
enum V_3 V_4 ,
const struct V_14 * V_15 )
{
static T_1 V_11 ;
unsigned int V_16 ;
unsigned int V_17 ;
V_16 = F_2 ( V_13 -> V_7 . V_10 . V_11 ) - F_2 ( V_13 -> V_6 . V_10 . V_11 ) + 1 ;
if ( ! ( V_13 -> V_18 & V_19 ) )
V_16 = 0xFFFF ;
for ( V_17 = 0 ; ; ++ V_11 ) {
V_2 -> V_8 . V_9 . V_10 . V_11 = F_4 ( F_2 ( V_13 -> V_6 . V_10 . V_11 ) +
( V_11 % V_16 ) ) ;
if ( ++ V_17 == V_16 || ! F_5 ( V_2 , V_15 ) )
return;
}
return;
}
static bool
F_6 ( struct V_20 * V_21 ,
unsigned int V_22 ,
const struct V_1 * V_2 ,
enum V_3 V_4 )
{
const struct V_23 * V_24 = (struct V_23 * ) ( V_21 -> V_25 + V_22 ) ;
struct V_26 * V_27 ;
unsigned int V_28 = V_22 + V_24 -> V_29 * 4 ;
if ( ! F_7 ( V_21 , V_28 + sizeof( * V_27 ) ) )
return false ;
V_27 = (struct V_26 * ) ( V_21 -> V_25 + V_28 ) ;
F_8 ( & V_27 -> V_30 , V_21 ,
V_27 -> V_31 . V_32 . V_11 , V_2 -> V_8 . V_9 . V_10 . V_11 , 0 ) ;
V_27 -> V_31 . V_32 . V_11 = V_2 -> V_8 . V_9 . V_10 . V_11 ;
return true ;
}
