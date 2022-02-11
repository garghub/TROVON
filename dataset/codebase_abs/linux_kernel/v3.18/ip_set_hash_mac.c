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
return F_4 ( V_7 , V_9 , V_10 , V_8 -> V_5 ) ;
}
static inline void
F_5 ( struct V_1 * V_11 ,
const struct V_1 * V_8 )
{
}
static int
F_6 ( struct V_12 * V_13 , const struct V_6 * V_7 ,
const struct V_14 * V_15 ,
enum V_16 V_17 , struct V_18 * V_19 )
{
T_2 V_20 = V_13 -> V_21 -> V_17 [ V_17 ] ;
struct V_1 V_8 = { { . V_22 [ 0 ] = 0 , . V_22 [ 1 ] = 0 } } ;
struct V_23 V_24 = F_7 ( V_7 , V_19 , V_13 ) ;
if ( ! ( V_19 -> V_25 & V_26 ) )
return 0 ;
if ( F_8 ( V_7 ) < V_7 -> V_27 ||
( F_8 ( V_7 ) + V_28 ) > V_7 -> V_29 )
return - V_30 ;
memcpy ( V_8 . V_5 , F_9 ( V_7 ) -> V_31 , V_10 ) ;
if ( memcmp ( V_8 . V_5 , V_32 , V_10 ) == 0 )
return - V_30 ;
return V_20 ( V_13 , & V_8 , & V_24 , & V_19 -> V_24 , V_19 -> V_33 ) ;
}
static int
F_10 ( struct V_12 * V_13 , struct V_34 * V_35 [] ,
enum V_16 V_17 , T_1 * V_36 , T_1 V_25 , bool V_37 )
{
T_2 V_20 = V_13 -> V_21 -> V_17 [ V_17 ] ;
struct V_1 V_8 = { { . V_22 [ 0 ] = 0 , . V_22 [ 1 ] = 0 } } ;
struct V_23 V_24 = F_11 ( V_13 ) ;
int V_38 ;
if ( F_12 ( ! V_35 [ V_9 ] ||
! F_13 ( V_35 , V_39 ) ||
! F_13 ( V_35 , V_40 ) ||
! F_13 ( V_35 , V_41 ) ||
! F_13 ( V_35 , V_42 ) ||
! F_13 ( V_35 , V_43 ) ||
! F_13 ( V_35 , V_44 ) ) )
return - V_45 ;
if ( V_35 [ V_46 ] )
* V_36 = F_14 ( V_35 [ V_46 ] ) ;
V_38 = F_15 ( V_13 , V_35 , & V_24 ) ;
if ( V_38 )
return V_38 ;
memcpy ( V_8 . V_5 , F_16 ( V_35 [ V_9 ] ) , V_10 ) ;
if ( memcmp ( V_8 . V_5 , V_32 , V_10 ) == 0 )
return - V_47 ;
return V_20 ( V_13 , & V_8 , & V_24 , & V_24 , V_25 ) ;
}
static int T_3
F_17 ( void )
{
return F_18 ( & V_48 ) ;
}
static void T_4
F_19 ( void )
{
F_20 ( & V_48 ) ;
}
