static inline bool
F_1 ( const struct V_1 * V_2 ,
const struct V_1 * V_3 ,
T_1 * V_4 )
{
return F_2 ( V_2 -> V_5 , V_3 -> V_5 ) ;
}
static inline bool
F_3 ( struct V_6 * V_7 , const struct V_1 * V_8 )
{
if ( F_4 ( V_7 , V_9 , V_10 , V_8 -> V_5 ) )
goto V_11;
return false ;
V_11:
return true ;
}
static inline void
F_5 ( struct V_1 * V_12 ,
const struct V_1 * V_8 )
{
}
static int
F_6 ( struct V_13 * V_14 , const struct V_6 * V_7 ,
const struct V_15 * V_16 ,
enum V_17 V_18 , struct V_19 * V_20 )
{
T_2 V_21 = V_14 -> V_22 -> V_18 [ V_18 ] ;
struct V_1 V_8 = { { . V_23 [ 0 ] = 0 , . V_23 [ 1 ] = 0 } } ;
struct V_24 V_25 = F_7 ( V_7 , V_20 , V_14 ) ;
if ( ! ( V_20 -> V_26 & V_27 ) )
return 0 ;
if ( F_8 ( V_7 ) < V_7 -> V_28 ||
( F_8 ( V_7 ) + V_29 ) > V_7 -> V_30 )
return - V_31 ;
F_9 ( V_8 . V_5 , F_10 ( V_7 ) -> V_32 ) ;
if ( memcmp ( V_8 . V_5 , V_33 , V_10 ) == 0 )
return - V_31 ;
return V_21 ( V_14 , & V_8 , & V_25 , & V_20 -> V_25 , V_20 -> V_34 ) ;
}
static int
F_11 ( struct V_13 * V_14 , struct V_35 * V_36 [] ,
enum V_17 V_18 , T_1 * V_37 , T_1 V_26 , bool V_38 )
{
T_2 V_21 = V_14 -> V_22 -> V_18 [ V_18 ] ;
struct V_1 V_8 = { { . V_23 [ 0 ] = 0 , . V_23 [ 1 ] = 0 } } ;
struct V_24 V_25 = F_12 ( V_14 ) ;
int V_39 ;
if ( V_36 [ V_40 ] )
* V_37 = F_13 ( V_36 [ V_40 ] ) ;
if ( F_14 ( ! V_36 [ V_9 ] ) )
return - V_41 ;
V_39 = F_15 ( V_14 , V_36 , & V_25 ) ;
if ( V_39 )
return V_39 ;
F_9 ( V_8 . V_5 , F_16 ( V_36 [ V_9 ] ) ) ;
if ( memcmp ( V_8 . V_5 , V_33 , V_10 ) == 0 )
return - V_42 ;
return V_21 ( V_14 , & V_8 , & V_25 , & V_25 , V_26 ) ;
}
static int T_3
F_17 ( void )
{
return F_18 ( & V_43 ) ;
}
static void T_4
F_19 ( void )
{
F_20 () ;
F_21 ( & V_43 ) ;
}
