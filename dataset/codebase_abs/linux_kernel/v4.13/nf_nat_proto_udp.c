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
static void
F_3 ( struct V_12 * V_13 ,
const struct V_1 * V_2 ,
unsigned int V_14 , struct V_15 * V_16 ,
const struct V_3 * V_4 ,
enum V_7 V_8 , bool V_17 )
{
T_1 * V_18 , V_19 ;
if ( V_8 == V_20 ) {
V_19 = V_4 -> V_21 . V_22 . V_23 . V_24 ;
V_18 = & V_16 -> V_25 ;
} else {
V_19 = V_4 -> V_26 . V_22 . V_23 . V_24 ;
V_18 = & V_16 -> V_27 ;
}
if ( V_17 ) {
V_2 -> V_28 ( V_13 , V_14 , & V_16 -> V_29 ,
V_4 , V_8 ) ;
F_4 ( & V_16 -> V_29 , V_13 , * V_18 , V_19 ,
false ) ;
if ( ! V_16 -> V_29 )
V_16 -> V_29 = V_30 ;
}
* V_18 = V_19 ;
}
static bool F_5 ( struct V_12 * V_13 ,
const struct V_1 * V_2 ,
unsigned int V_14 , unsigned int V_31 ,
const struct V_3 * V_4 ,
enum V_7 V_8 )
{
struct V_15 * V_16 ;
bool V_17 ;
if ( ! F_6 ( V_13 , V_31 + sizeof( * V_16 ) ) )
return false ;
V_16 = (struct V_15 * ) ( V_13 -> V_32 + V_31 ) ;
V_17 = V_16 -> V_29 || V_13 -> V_33 == V_34 ;
F_3 ( V_13 , V_2 , V_14 , V_16 , V_4 , V_8 , V_17 ) ;
return true ;
}
static bool F_7 ( struct V_12 * V_13 ,
const struct V_1 * V_2 ,
unsigned int V_14 , unsigned int V_31 ,
const struct V_3 * V_4 ,
enum V_7 V_8 )
{
struct V_15 * V_16 ;
if ( ! F_6 ( V_13 , V_31 + sizeof( * V_16 ) ) )
return false ;
V_16 = (struct V_15 * ) ( V_13 -> V_32 + V_31 ) ;
F_3 ( V_13 , V_2 , V_14 , V_16 , V_4 , V_8 , true ) ;
return true ;
}
static void
F_8 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
enum V_7 V_8 ,
const struct V_9 * V_10 )
{
F_2 ( V_2 , V_4 , V_6 , V_8 , V_10 ,
& V_35 ) ;
}
