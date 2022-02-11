static bool F_1 ( const struct V_1 * V_2 ,
unsigned int V_3 ,
struct V_4 * V_5 )
{
V_5 -> V_6 . V_7 . V_8 = 0 ;
V_5 -> V_9 . V_7 . V_8 = 0 ;
return true ;
}
static bool F_2 ( struct V_4 * V_5 ,
const struct V_4 * V_10 )
{
V_5 -> V_6 . V_7 . V_8 = 0 ;
V_5 -> V_9 . V_7 . V_8 = 0 ;
return true ;
}
static int F_3 ( struct V_11 * V_12 ,
const struct V_4 * V_5 )
{
return 0 ;
}
static unsigned int * F_4 ( struct V_13 * V_13 )
{
return & V_14 ;
}
static int F_5 ( struct V_15 * V_16 ,
const struct V_1 * V_2 ,
unsigned int V_3 ,
enum V_17 V_18 ,
T_1 V_19 ,
unsigned int V_20 ,
unsigned int * V_21 )
{
F_6 ( V_16 , V_18 , V_2 , * V_21 ) ;
return V_22 ;
}
static bool F_7 ( struct V_15 * V_16 , const struct V_1 * V_2 ,
unsigned int V_3 , unsigned int * V_23 )
{
return true ;
}
static int F_8 ( struct V_24 * V_25 [] , void * V_26 )
{
unsigned int * V_21 = V_26 ;
if ( V_25 [ V_27 ] )
* V_21 =
F_9 ( F_10 ( V_25 [ V_27 ] ) ) * V_28 ;
else {
* V_21 = V_14 ;
}
return 0 ;
}
static int
F_11 ( struct V_1 * V_2 , const void * V_26 )
{
const unsigned int * V_21 = V_26 ;
F_12 ( V_2 , V_27 , F_13 ( * V_21 / V_28 ) ) ;
return 0 ;
V_29:
return - V_30 ;
}
