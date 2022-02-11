static bool F_1 ( T_1 V_1 )
{
switch ( V_1 ) {
#ifdef F_2
case V_2 :
return false ;
#endif
#ifdef F_3
case V_3 :
return false ;
#endif
#ifdef F_4
case V_4 :
return false ;
#endif
#ifdef F_5
case V_5 :
return false ;
#endif
default:
return true ;
}
}
static inline struct V_6 * F_6 ( struct V_7 * V_7 )
{
return & V_7 -> V_8 . V_9 . V_10 ;
}
static bool F_7 ( const struct V_11 * V_12 ,
unsigned int V_13 ,
struct V_14 * V_15 )
{
V_15 -> V_16 . V_17 . V_18 = 0 ;
V_15 -> V_19 . V_17 . V_18 = 0 ;
return true ;
}
static bool F_8 ( struct V_14 * V_15 ,
const struct V_14 * V_20 )
{
V_15 -> V_16 . V_17 . V_18 = 0 ;
V_15 -> V_19 . V_17 . V_18 = 0 ;
return true ;
}
static int F_9 ( struct V_21 * V_22 ,
const struct V_14 * V_15 )
{
return 0 ;
}
static unsigned int * F_10 ( struct V_7 * V_7 )
{
return & ( F_6 ( V_7 ) -> V_23 ) ;
}
static int F_11 ( struct V_24 * V_8 ,
const struct V_11 * V_12 ,
unsigned int V_13 ,
enum V_25 V_26 ,
T_2 V_27 ,
unsigned int V_28 ,
unsigned int * V_23 )
{
F_12 ( V_8 , V_26 , V_12 , * V_23 ) ;
return V_29 ;
}
static bool F_13 ( struct V_24 * V_8 , const struct V_11 * V_12 ,
unsigned int V_13 , unsigned int * V_30 )
{
return F_1 ( F_14 ( V_8 ) ) ;
}
static int F_15 ( struct V_31 * V_32 [] ,
struct V_7 * V_7 , void * V_33 )
{
unsigned int * V_23 = V_33 ;
struct V_6 * V_34 = F_6 ( V_7 ) ;
if ( V_32 [ V_35 ] )
* V_23 =
F_16 ( F_17 ( V_32 [ V_35 ] ) ) * V_36 ;
else {
* V_23 = V_34 -> V_23 ;
}
return 0 ;
}
static int
F_18 ( struct V_11 * V_12 , const void * V_33 )
{
const unsigned int * V_23 = V_33 ;
if ( F_19 ( V_12 , V_35 , F_20 ( * V_23 / V_36 ) ) )
goto V_37;
return 0 ;
V_37:
return - V_38 ;
}
static int F_21 ( struct V_39 * V_40 ,
struct V_6 * V_34 )
{
#ifdef F_22
V_40 -> V_41 = F_23 ( V_42 ,
sizeof( V_42 ) ,
V_43 ) ;
if ( ! V_40 -> V_41 )
return - V_44 ;
V_40 -> V_41 [ 0 ] . V_33 = & V_34 -> V_23 ;
#endif
return 0 ;
}
static int F_24 ( struct V_39 * V_40 ,
struct V_6 * V_34 )
{
#ifdef F_22
#ifdef F_25
V_40 -> V_45 = F_23 ( V_46 ,
sizeof( V_46 ) ,
V_43 ) ;
if ( ! V_40 -> V_45 )
return - V_44 ;
V_40 -> V_45 [ 0 ] . V_33 = & V_34 -> V_23 ;
#endif
#endif
return 0 ;
}
static int F_26 ( struct V_7 * V_7 , T_3 V_1 )
{
int V_47 ;
struct V_6 * V_34 = F_6 ( V_7 ) ;
struct V_39 * V_40 = & V_34 -> V_40 ;
V_34 -> V_23 = V_48 ;
V_47 = F_24 ( V_40 , V_34 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_21 ( V_40 , V_34 ) ;
if ( V_47 < 0 )
F_27 ( V_40 ) ;
return V_47 ;
}
static struct V_39 * F_28 ( struct V_7 * V_7 )
{
return & V_7 -> V_8 . V_9 . V_10 . V_40 ;
}
