static inline void F_1 ( const struct V_1 * V_2 ,
const void * V_3 ,
T_1 * V_4 , T_1 * V_5 )
{
T_1 V_6 ;
if ( V_2 -> V_7 == 2 )
V_6 = * ( V_8 * ) V_3 ;
else
V_6 = * ( V_9 * ) V_3 ;
V_6 <<= 1 ;
* V_4 = V_6 / V_10 ;
* V_5 = V_6 % V_10 ;
}
static inline bool
F_2 ( const V_9 * V_11 , T_1 V_4 , T_1 V_5 , V_9 V_12 )
{
return ( V_11 [ V_4 ] & ( 0x3 << V_5 ) ) & ( V_12 << V_5 ) ;
}
static bool F_3 ( const struct V_13 * V_13 , const struct V_1 * V_2 ,
const T_1 * V_3 , const struct V_14 * * V_15 )
{
const struct V_16 * V_17 = F_4 ( V_2 ) ;
V_9 V_12 = F_5 ( V_13 ) ;
T_1 V_4 , V_5 ;
F_1 ( V_2 , V_3 , & V_4 , & V_5 ) ;
return F_2 ( V_17 -> V_11 , V_4 , V_5 , V_12 ) ;
}
static struct V_18 *
F_6 ( const struct V_1 * V_2 , struct V_18 * V_19 ,
V_9 V_12 )
{
const struct V_16 * V_17 = F_4 ( V_2 ) ;
struct V_18 * V_20 ;
F_7 (be, &priv->list, head) {
if ( memcmp ( F_8 ( & V_20 -> V_15 ) ,
F_8 ( & V_19 -> V_15 ) , V_2 -> V_7 ) ||
! F_9 ( & V_20 -> V_15 , V_12 ) )
continue;
return V_20 ;
}
return NULL ;
}
static int F_10 ( const struct V_13 * V_13 , const struct V_1 * V_2 ,
const struct V_21 * V_22 ,
struct V_14 * * V_15 )
{
struct V_16 * V_17 = F_4 ( V_2 ) ;
struct V_18 * V_23 = V_22 -> V_17 , * V_20 ;
V_9 V_12 = F_11 ( V_13 ) ;
T_1 V_4 , V_5 ;
V_20 = F_6 ( V_2 , V_23 , V_12 ) ;
if ( V_20 ) {
* V_15 = & V_20 -> V_15 ;
return - V_24 ;
}
F_1 ( V_2 , F_8 ( & V_23 -> V_15 ) , & V_4 , & V_5 ) ;
V_17 -> V_11 [ V_4 ] |= ( V_12 << V_5 ) ;
F_12 ( & V_23 -> V_25 , & V_17 -> V_26 ) ;
return 0 ;
}
static void F_13 ( const struct V_13 * V_13 ,
const struct V_1 * V_2 ,
const struct V_21 * V_22 )
{
struct V_16 * V_17 = F_4 ( V_2 ) ;
struct V_18 * V_20 = V_22 -> V_17 ;
V_9 V_12 = F_11 ( V_13 ) ;
T_1 V_4 , V_5 ;
F_1 ( V_2 , F_8 ( & V_20 -> V_15 ) , & V_4 , & V_5 ) ;
V_17 -> V_11 [ V_4 ] &= ~ ( V_12 << V_5 ) ;
F_14 ( & V_20 -> V_25 ) ;
}
static void F_15 ( const struct V_13 * V_13 ,
const struct V_1 * V_2 ,
const struct V_21 * V_22 )
{
struct V_16 * V_17 = F_4 ( V_2 ) ;
struct V_18 * V_20 = V_22 -> V_17 ;
V_9 V_12 = F_11 ( V_13 ) ;
T_1 V_4 , V_5 ;
F_1 ( V_2 , F_8 ( & V_20 -> V_15 ) , & V_4 , & V_5 ) ;
V_17 -> V_11 [ V_4 ] |= ( V_12 << V_5 ) ;
F_16 ( V_13 , V_2 , & V_20 -> V_15 ) ;
}
static bool F_17 ( const struct V_13 * V_13 ,
const struct V_1 * V_2 , void * V_27 )
{
struct V_16 * V_17 = F_4 ( V_2 ) ;
V_9 V_12 = F_11 ( V_13 ) ;
struct V_18 * V_20 = V_27 ;
T_1 V_4 , V_5 ;
F_1 ( V_2 , F_8 ( & V_20 -> V_15 ) , & V_4 , & V_5 ) ;
V_17 -> V_11 [ V_4 ] &= ~ ( V_12 << V_5 ) ;
F_16 ( V_13 , V_2 , & V_20 -> V_15 ) ;
return true ;
}
static void * F_18 ( const struct V_13 * V_13 ,
const struct V_1 * V_2 ,
const struct V_21 * V_22 )
{
struct V_16 * V_17 = F_4 ( V_2 ) ;
struct V_18 * V_19 = V_22 -> V_17 , * V_20 ;
V_9 V_12 = F_11 ( V_13 ) ;
T_1 V_4 , V_5 ;
F_1 ( V_2 , V_22 -> V_3 . V_28 . V_29 , & V_4 , & V_5 ) ;
V_20 = F_6 ( V_2 , V_19 , V_12 ) ;
if ( ! V_20 )
return NULL ;
V_17 -> V_11 [ V_4 ] &= ~ ( V_12 << V_5 ) ;
F_16 ( V_13 , V_2 , & V_20 -> V_15 ) ;
return V_20 ;
}
static void F_19 ( const struct V_30 * V_31 ,
struct V_1 * V_2 ,
struct V_32 * V_33 )
{
const struct V_16 * V_17 = F_4 ( V_2 ) ;
struct V_18 * V_20 ;
struct V_21 V_22 ;
F_7 (be, &priv->list, head) {
if ( V_33 -> V_34 < V_33 -> V_35 )
goto V_36;
if ( ! F_9 ( & V_20 -> V_15 , V_33 -> V_12 ) )
goto V_36;
V_22 . V_17 = V_20 ;
V_33 -> V_37 = V_33 -> V_38 ( V_31 , V_2 , V_33 , & V_22 ) ;
if ( V_33 -> V_37 < 0 )
return;
V_36:
V_33 -> V_34 ++ ;
}
}
static inline T_1 F_20 ( T_1 V_7 )
{
return ( ( 2 << ( ( V_7 * V_10 ) - 1 ) ) / V_10 ) << 1 ;
}
static inline T_1 F_21 ( T_1 V_7 )
{
return sizeof( struct V_16 ) + F_20 ( V_7 ) ;
}
static unsigned int F_22 ( const struct V_39 * const V_40 [] ,
const struct V_41 * V_42 )
{
T_1 V_7 = F_23 ( F_24 ( V_40 [ V_43 ] ) ) ;
return F_21 ( V_7 ) ;
}
static int F_25 ( const struct V_1 * V_2 ,
const struct V_41 * V_42 ,
const struct V_39 * const V_40 [] )
{
struct V_16 * V_17 = F_4 ( V_2 ) ;
F_26 ( & V_17 -> V_26 ) ;
V_17 -> V_44 = F_20 ( V_2 -> V_7 ) ;
return 0 ;
}
static void F_27 ( const struct V_1 * V_2 )
{
struct V_16 * V_17 = F_4 ( V_2 ) ;
struct V_18 * V_20 , * V_45 ;
F_28 (be, n, &priv->list, head)
F_29 ( V_2 , V_20 , true ) ;
}
static bool F_30 ( const struct V_41 * V_42 , T_1 V_46 ,
struct V_47 * V_48 )
{
if ( V_42 -> V_7 > 2 )
return false ;
V_48 -> V_49 = F_21 ( V_42 -> V_7 ) ;
V_48 -> V_50 = V_51 ;
V_48 -> V_52 = V_51 ;
return true ;
}
static int T_2 F_31 ( void )
{
return F_32 ( & V_53 ) ;
}
static void T_3 F_33 ( void )
{
F_34 ( & V_53 ) ;
}
