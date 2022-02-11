static inline bool
F_1 ( const struct V_1 * V_2 ,
const struct V_1 * V_3 ,
T_1 * V_4 )
{
return V_2 -> V_5 == V_3 -> V_5 && F_2 ( V_2 -> V_6 , V_3 -> V_6 ) ;
}
static bool
F_3 ( struct V_7 * V_8 , const struct V_1 * V_9 )
{
if ( F_4 ( V_8 , V_10 , V_9 -> V_5 ) ||
F_5 ( V_8 , V_11 , V_12 , V_9 -> V_6 ) )
goto V_13;
return false ;
V_13:
return true ;
}
static inline void
F_6 ( struct V_1 * V_14 ,
const struct V_1 * V_9 )
{
V_14 -> V_5 = V_9 -> V_5 ;
}
static int
F_7 ( struct V_15 * V_16 , const struct V_7 * V_8 ,
const struct V_17 * V_18 ,
enum V_19 V_20 , struct V_21 * V_22 )
{
T_2 V_23 = V_16 -> V_24 -> V_20 [ V_20 ] ;
struct V_1 V_9 = { . V_5 = 0 , { . V_25 [ 0 ] = 0 , . V_25 [ 1 ] = 0 } } ;
struct V_26 V_27 = F_8 ( V_8 , V_22 , V_16 ) ;
if ( ! ( V_22 -> V_28 & V_29 ) )
return 0 ;
if ( F_9 ( V_8 ) < V_8 -> V_30 ||
( F_9 ( V_8 ) + V_31 ) > V_8 -> V_32 )
return - V_33 ;
memcpy ( V_9 . V_6 , F_10 ( V_8 ) -> V_34 , V_12 ) ;
if ( F_2 ( V_9 . V_6 , V_35 ) )
return - V_33 ;
F_11 ( V_8 , V_22 -> V_28 & V_36 , & V_9 . V_5 ) ;
return V_23 ( V_16 , & V_9 , & V_27 , & V_22 -> V_27 , V_22 -> V_37 ) ;
}
static int
F_12 ( struct V_15 * V_16 , struct V_38 * V_39 [] ,
enum V_19 V_20 , T_1 * V_40 , T_1 V_28 , bool V_41 )
{
T_2 V_23 = V_16 -> V_24 -> V_20 [ V_20 ] ;
struct V_1 V_9 = { . V_5 = 0 , { . V_25 [ 0 ] = 0 , . V_25 [ 1 ] = 0 } } ;
struct V_26 V_27 = F_13 ( V_16 ) ;
int V_42 ;
if ( F_14 ( ! V_39 [ V_10 ] ||
! V_39 [ V_11 ] ||
F_15 ( V_39 [ V_11 ] ) != V_12 ||
! F_16 ( V_39 , V_43 ) ||
! F_16 ( V_39 , V_44 ) ||
! F_16 ( V_39 , V_45 ) ||
! F_16 ( V_39 , V_46 ) ||
! F_16 ( V_39 , V_47 ) ||
! F_16 ( V_39 , V_48 ) ) )
return - V_49 ;
if ( V_39 [ V_50 ] )
* V_40 = F_17 ( V_39 [ V_50 ] ) ;
V_42 = F_18 ( V_39 [ V_10 ] , & V_9 . V_5 ) ||
F_19 ( V_16 , V_39 , & V_27 ) ;
if ( V_42 )
return V_42 ;
memcpy ( V_9 . V_6 , F_20 ( V_39 [ V_11 ] ) , V_12 ) ;
if ( F_2 ( V_9 . V_6 , V_35 ) )
return - V_51 ;
return V_23 ( V_16 , & V_9 , & V_27 , & V_27 , V_28 ) ;
}
static inline bool
F_21 ( const struct V_52 * V_2 ,
const struct V_52 * V_3 ,
T_1 * V_4 )
{
return F_22 ( & V_2 -> V_5 . V_53 , & V_3 -> V_5 . V_53 ) &&
F_2 ( V_2 -> V_6 , V_3 -> V_6 ) ;
}
static bool
F_23 ( struct V_7 * V_8 , const struct V_52 * V_9 )
{
if ( F_24 ( V_8 , V_10 , & V_9 -> V_5 . V_53 ) ||
F_5 ( V_8 , V_11 , V_12 , V_9 -> V_6 ) )
goto V_13;
return false ;
V_13:
return true ;
}
static inline void
F_25 ( struct V_52 * V_14 ,
const struct V_52 * V_9 )
{
}
static int
F_26 ( struct V_15 * V_16 , const struct V_7 * V_8 ,
const struct V_17 * V_18 ,
enum V_19 V_20 , struct V_21 * V_22 )
{
T_2 V_23 = V_16 -> V_24 -> V_20 [ V_20 ] ;
struct V_52 V_9 = {
{ . V_54 = { 0 } } ,
{ . V_25 [ 0 ] = 0 , . V_25 [ 1 ] = 0 }
} ;
struct V_26 V_27 = F_8 ( V_8 , V_22 , V_16 ) ;
if ( ! ( V_22 -> V_28 & V_29 ) )
return 0 ;
if ( F_9 ( V_8 ) < V_8 -> V_30 ||
( F_9 ( V_8 ) + V_31 ) > V_8 -> V_32 )
return - V_33 ;
memcpy ( V_9 . V_6 , F_10 ( V_8 ) -> V_34 , V_12 ) ;
if ( F_2 ( V_9 . V_6 , V_35 ) )
return - V_33 ;
F_27 ( V_8 , V_22 -> V_28 & V_36 , & V_9 . V_5 . V_53 ) ;
return V_23 ( V_16 , & V_9 , & V_27 , & V_22 -> V_27 , V_22 -> V_37 ) ;
}
static int
F_28 ( struct V_15 * V_16 , struct V_38 * V_39 [] ,
enum V_19 V_20 , T_1 * V_40 , T_1 V_28 , bool V_41 )
{
T_2 V_23 = V_16 -> V_24 -> V_20 [ V_20 ] ;
struct V_52 V_9 = {
{ . V_54 = { 0 } } ,
{ . V_25 [ 0 ] = 0 , . V_25 [ 1 ] = 0 }
} ;
struct V_26 V_27 = F_13 ( V_16 ) ;
int V_42 ;
if ( F_14 ( ! V_39 [ V_10 ] ||
! V_39 [ V_11 ] ||
F_15 ( V_39 [ V_11 ] ) != V_12 ||
! F_16 ( V_39 , V_43 ) ||
! F_16 ( V_39 , V_44 ) ||
! F_16 ( V_39 , V_45 ) ||
! F_16 ( V_39 , V_46 ) ||
! F_16 ( V_39 , V_47 ) ||
! F_16 ( V_39 , V_48 ) ) )
return - V_49 ;
if ( V_39 [ V_50 ] )
* V_40 = F_17 ( V_39 [ V_50 ] ) ;
V_42 = F_29 ( V_39 [ V_10 ] , & V_9 . V_5 ) ||
F_19 ( V_16 , V_39 , & V_27 ) ;
if ( V_42 )
return V_42 ;
memcpy ( V_9 . V_6 , F_20 ( V_39 [ V_11 ] ) , V_12 ) ;
if ( F_2 ( V_9 . V_6 , V_35 ) )
return - V_51 ;
return V_23 ( V_16 , & V_9 , & V_27 , & V_27 , V_28 ) ;
}
static int T_3
F_30 ( void )
{
return F_31 ( & V_55 ) ;
}
static void T_4
F_32 ( void )
{
F_33 ( & V_55 ) ;
}
