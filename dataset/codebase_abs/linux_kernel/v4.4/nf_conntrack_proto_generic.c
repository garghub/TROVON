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
struct V_7 * V_7 , struct V_14 * V_15 )
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
static void F_9 ( struct V_21 * V_22 ,
const struct V_14 * V_15 )
{
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
bool V_31 ;
V_31 = F_1 ( F_14 ( V_8 ) ) ;
if ( ! V_31 )
F_15 ( L_1 ,
F_14 ( V_8 ) ) ;
return V_31 ;
}
static int F_16 ( struct V_32 * V_33 [] ,
struct V_7 * V_7 , void * V_34 )
{
unsigned int * V_23 = V_34 ;
struct V_6 * V_35 = F_6 ( V_7 ) ;
if ( V_33 [ V_36 ] )
* V_23 =
F_17 ( F_18 ( V_33 [ V_36 ] ) ) * V_37 ;
else {
* V_23 = V_35 -> V_23 ;
}
return 0 ;
}
static int
F_19 ( struct V_11 * V_12 , const void * V_34 )
{
const unsigned int * V_23 = V_34 ;
if ( F_20 ( V_12 , V_36 , F_21 ( * V_23 / V_37 ) ) )
goto V_38;
return 0 ;
V_38:
return - V_39 ;
}
static int F_22 ( struct V_40 * V_41 ,
struct V_6 * V_35 )
{
#ifdef F_23
V_41 -> V_42 = F_24 ( V_43 ,
sizeof( V_43 ) ,
V_44 ) ;
if ( ! V_41 -> V_42 )
return - V_45 ;
V_41 -> V_42 [ 0 ] . V_34 = & V_35 -> V_23 ;
#endif
return 0 ;
}
static int F_25 ( struct V_40 * V_41 ,
struct V_6 * V_35 )
{
#ifdef F_23
#ifdef F_26
V_41 -> V_46 = F_24 ( V_47 ,
sizeof( V_47 ) ,
V_44 ) ;
if ( ! V_41 -> V_46 )
return - V_45 ;
V_41 -> V_46 [ 0 ] . V_34 = & V_35 -> V_23 ;
#endif
#endif
return 0 ;
}
static int F_27 ( struct V_7 * V_7 , T_3 V_1 )
{
int V_31 ;
struct V_6 * V_35 = F_6 ( V_7 ) ;
struct V_40 * V_41 = & V_35 -> V_41 ;
V_35 -> V_23 = V_48 ;
V_31 = F_25 ( V_41 , V_35 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_22 ( V_41 , V_35 ) ;
if ( V_31 < 0 )
F_28 ( V_41 ) ;
return V_31 ;
}
static struct V_40 * F_29 ( struct V_7 * V_7 )
{
return & V_7 -> V_8 . V_9 . V_10 . V_41 ;
}
