static bool F_1 ( T_1 V_1 )
{
switch ( V_1 ) {
#ifdef F_2
case V_2 :
return false ;
#endif
default:
return true ;
}
}
static inline struct V_3 * F_3 ( struct V_4 * V_4 )
{
return & V_4 -> V_5 . V_6 . V_7 ;
}
static bool F_4 ( const struct V_8 * V_9 ,
unsigned int V_10 ,
struct V_4 * V_4 , struct V_11 * V_12 )
{
V_12 -> V_13 . V_14 . V_15 = 0 ;
V_12 -> V_16 . V_14 . V_15 = 0 ;
return true ;
}
static bool F_5 ( struct V_11 * V_12 ,
const struct V_11 * V_17 )
{
V_12 -> V_13 . V_14 . V_15 = 0 ;
V_12 -> V_16 . V_14 . V_15 = 0 ;
return true ;
}
static unsigned int * F_6 ( struct V_4 * V_4 )
{
return & ( F_3 ( V_4 ) -> V_18 ) ;
}
static int F_7 ( struct V_19 * V_5 ,
const struct V_8 * V_9 ,
unsigned int V_10 ,
enum V_20 V_21 ,
T_2 V_22 ,
unsigned int * V_18 )
{
F_8 ( V_5 , V_21 , V_9 , * V_18 ) ;
return V_23 ;
}
static bool F_9 ( struct V_19 * V_5 , const struct V_8 * V_9 ,
unsigned int V_10 , unsigned int * V_24 )
{
bool V_25 ;
V_25 = F_1 ( F_10 ( V_5 ) ) ;
if ( ! V_25 )
F_11 ( L_1 ,
F_10 ( V_5 ) ) ;
return V_25 ;
}
static int F_12 ( struct V_26 * V_27 [] ,
struct V_4 * V_4 , void * V_28 )
{
unsigned int * V_18 = V_28 ;
struct V_3 * V_29 = F_3 ( V_4 ) ;
if ( V_27 [ V_30 ] )
* V_18 =
F_13 ( F_14 ( V_27 [ V_30 ] ) ) * V_31 ;
else {
* V_18 = V_29 -> V_18 ;
}
return 0 ;
}
static int
F_15 ( struct V_8 * V_9 , const void * V_28 )
{
const unsigned int * V_18 = V_28 ;
if ( F_16 ( V_9 , V_30 , F_17 ( * V_18 / V_31 ) ) )
goto V_32;
return 0 ;
V_32:
return - V_33 ;
}
static int F_18 ( struct V_34 * V_35 ,
struct V_3 * V_29 )
{
#ifdef F_19
V_35 -> V_36 = F_20 ( V_37 ,
sizeof( V_37 ) ,
V_38 ) ;
if ( ! V_35 -> V_36 )
return - V_39 ;
V_35 -> V_36 [ 0 ] . V_28 = & V_29 -> V_18 ;
#endif
return 0 ;
}
static int F_21 ( struct V_4 * V_4 , T_3 V_1 )
{
struct V_3 * V_29 = F_3 ( V_4 ) ;
struct V_34 * V_35 = & V_29 -> V_35 ;
V_29 -> V_18 = V_40 ;
return F_18 ( V_35 , V_29 ) ;
}
static struct V_34 * F_22 ( struct V_4 * V_4 )
{
return & V_4 -> V_5 . V_6 . V_7 . V_35 ;
}
