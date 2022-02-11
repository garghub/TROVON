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
F_3 ( const struct V_12 * V_13 ,
struct V_1 * V_2 ,
const struct V_14 * V_15 ,
enum V_3 V_4 ,
const struct V_16 * V_17 )
{
static T_1 V_11 ;
unsigned int V_18 ;
unsigned int V_19 ;
V_18 = F_2 ( V_15 -> V_20 . V_10 . V_11 ) -
F_2 ( V_15 -> V_21 . V_10 . V_11 ) + 1 ;
if ( ! ( V_15 -> V_22 & V_23 ) )
V_18 = 0xffff ;
for ( V_19 = 0 ; ; ++ V_11 ) {
V_2 -> V_8 . V_9 . V_10 . V_11 = F_4 ( F_2 ( V_15 -> V_21 . V_10 . V_11 ) +
( V_11 % V_18 ) ) ;
if ( ++ V_19 == V_18 || ! F_5 ( V_2 , V_17 ) )
return;
}
}
static bool
F_6 ( struct V_24 * V_25 ,
const struct V_12 * V_13 ,
unsigned int V_26 , unsigned int V_27 ,
const struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_28 * V_29 ;
if ( ! F_7 ( V_25 , V_27 + sizeof( * V_29 ) ) )
return false ;
V_29 = (struct V_28 * ) ( V_25 -> V_30 + V_27 ) ;
V_13 -> V_31 ( V_25 , V_26 , & V_29 -> V_32 ,
V_2 , V_4 ) ;
if ( V_29 -> V_33 == V_34 ||
V_29 -> V_33 == V_35 ) {
F_8 ( & V_29 -> V_32 , V_25 ,
V_29 -> V_36 ,
V_2 -> V_8 . V_9 . V_10 . V_11 , 0 ) ;
V_29 -> V_36 = V_2 -> V_8 . V_9 . V_10 . V_11 ;
}
return true ;
}
