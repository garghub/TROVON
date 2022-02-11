static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return & V_2 -> V_3 . V_4 . V_5 ;
}
static bool F_2 ( const struct V_6 * V_7 ,
unsigned int V_8 ,
struct V_9 * V_10 )
{
V_10 -> V_11 . V_12 . V_13 = 0 ;
V_10 -> V_14 . V_12 . V_13 = 0 ;
return true ;
}
static bool F_3 ( struct V_9 * V_10 ,
const struct V_9 * V_15 )
{
V_10 -> V_11 . V_12 . V_13 = 0 ;
V_10 -> V_14 . V_12 . V_13 = 0 ;
return true ;
}
static int F_4 ( struct V_16 * V_17 ,
const struct V_9 * V_10 )
{
return 0 ;
}
static unsigned int * F_5 ( struct V_2 * V_2 )
{
return & ( F_1 ( V_2 ) -> V_18 ) ;
}
static int F_6 ( struct V_19 * V_3 ,
const struct V_6 * V_7 ,
unsigned int V_8 ,
enum V_20 V_21 ,
T_1 V_22 ,
unsigned int V_23 ,
unsigned int * V_18 )
{
F_7 ( V_3 , V_21 , V_7 , * V_18 ) ;
return V_24 ;
}
static bool F_8 ( struct V_19 * V_3 , const struct V_6 * V_7 ,
unsigned int V_8 , unsigned int * V_25 )
{
return true ;
}
static int F_9 ( struct V_26 * V_27 [] ,
struct V_2 * V_2 , void * V_28 )
{
unsigned int * V_18 = V_28 ;
struct V_1 * V_29 = F_1 ( V_2 ) ;
if ( V_27 [ V_30 ] )
* V_18 =
F_10 ( F_11 ( V_27 [ V_30 ] ) ) * V_31 ;
else {
* V_18 = V_29 -> V_18 ;
}
return 0 ;
}
static int
F_12 ( struct V_6 * V_7 , const void * V_28 )
{
const unsigned int * V_18 = V_28 ;
if ( F_13 ( V_7 , V_30 , F_14 ( * V_18 / V_31 ) ) )
goto V_32;
return 0 ;
V_32:
return - V_33 ;
}
static int F_15 ( struct V_34 * V_35 ,
struct V_1 * V_29 )
{
#ifdef F_16
V_35 -> V_36 = F_17 ( V_37 ,
sizeof( V_37 ) ,
V_38 ) ;
if ( ! V_35 -> V_36 )
return - V_39 ;
V_35 -> V_36 [ 0 ] . V_28 = & V_29 -> V_18 ;
#endif
return 0 ;
}
static int F_18 ( struct V_34 * V_35 ,
struct V_1 * V_29 )
{
#ifdef F_16
#ifdef F_19
V_35 -> V_40 = F_17 ( V_41 ,
sizeof( V_41 ) ,
V_38 ) ;
if ( ! V_35 -> V_40 )
return - V_39 ;
V_35 -> V_40 [ 0 ] . V_28 = & V_29 -> V_18 ;
#endif
#endif
return 0 ;
}
static int F_20 ( struct V_2 * V_2 , T_2 V_42 )
{
int V_43 ;
struct V_1 * V_29 = F_1 ( V_2 ) ;
struct V_34 * V_35 = & V_29 -> V_35 ;
V_29 -> V_18 = V_44 ;
V_43 = F_18 ( V_35 , V_29 ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 = F_15 ( V_35 , V_29 ) ;
if ( V_43 < 0 )
F_21 ( V_35 ) ;
return V_43 ;
}
static struct V_34 * F_22 ( struct V_2 * V_2 )
{
return & V_2 -> V_3 . V_4 . V_5 . V_35 ;
}
