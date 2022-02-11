static inline bool
F_1 ( const struct V_1 * V_2 ,
const struct V_1 * V_3 ,
T_1 * V_4 )
{
return V_2 -> V_5 == V_3 -> V_5 &&
V_2 -> V_6 == V_3 -> V_6 ;
}
static inline int
F_2 ( const struct V_1 * V_7 )
{
return V_7 -> V_8 ? - V_9 : 1 ;
}
static inline void
F_3 ( struct V_1 * V_7 , T_1 V_10 )
{
V_7 -> V_8 = ( V_10 >> 16 ) & V_11 ;
}
static inline void
F_4 ( struct V_1 * V_7 , T_2 * V_10 )
{
F_5 ( * V_10 , V_7 -> V_8 ) ;
}
static inline void
F_6 ( struct V_1 * V_7 , T_2 V_6 )
{
V_7 -> V_5 &= F_7 ( V_6 ) ;
V_7 -> V_6 = V_6 ;
}
static bool
F_8 ( struct V_12 * V_13 , const struct V_1 * V_14 )
{
T_1 V_10 = V_14 -> V_8 ? V_11 : 0 ;
if ( F_9 ( V_13 , V_15 , V_14 -> V_5 ) ||
F_10 ( V_13 , V_16 , V_14 -> V_6 ) ||
( V_10 &&
F_11 ( V_13 , V_17 , F_12 ( V_10 ) ) ) )
goto V_18;
return 0 ;
V_18:
return 1 ;
}
static inline void
F_13 ( struct V_1 * V_19 ,
const struct V_1 * V_20 )
{
V_19 -> V_5 = V_20 -> V_5 ;
}
static int
F_14 ( struct V_21 * V_22 , const struct V_12 * V_13 ,
const struct V_23 * V_24 ,
enum V_25 V_26 , struct V_27 * V_28 )
{
const struct V_29 * V_30 = V_22 -> V_14 ;
T_3 V_31 = V_22 -> V_32 -> V_26 [ V_26 ] ;
struct V_1 V_33 = {
. V_6 = V_30 -> V_34 [ 0 ] . V_6 ? V_30 -> V_34 [ 0 ] . V_6 : V_35
} ;
struct V_36 V_37 = F_15 ( V_13 , V_28 , V_30 ) ;
if ( V_33 . V_6 == 0 )
return - V_38 ;
if ( V_26 == V_39 )
V_33 . V_6 = V_35 ;
F_16 ( V_13 , V_28 -> V_10 & V_40 , & V_33 . V_5 ) ;
V_33 . V_5 &= F_7 ( V_33 . V_6 ) ;
return V_31 ( V_22 , & V_33 , & V_37 , & V_28 -> V_37 , V_28 -> V_41 ) ;
}
static int
F_17 ( struct V_21 * V_22 , struct V_42 * V_43 [] ,
enum V_25 V_26 , T_1 * V_44 , T_1 V_10 , bool V_45 )
{
const struct V_29 * V_30 = V_22 -> V_14 ;
T_3 V_31 = V_22 -> V_32 -> V_26 [ V_26 ] ;
struct V_1 V_33 = { . V_6 = V_35 } ;
struct V_36 V_37 = F_18 ( V_30 ) ;
T_1 V_5 = 0 , V_46 , V_47 ;
int V_48 ;
if ( F_19 ( ! V_43 [ V_15 ] ||
! F_20 ( V_43 , V_49 ) ||
! F_20 ( V_43 , V_17 ) ||
! F_20 ( V_43 , V_50 ) ||
! F_20 ( V_43 , V_51 ) ) )
return - V_52 ;
if ( V_43 [ V_53 ] )
* V_44 = F_21 ( V_43 [ V_53 ] ) ;
V_48 = F_22 ( V_43 [ V_15 ] , & V_5 ) ||
F_23 ( V_22 , V_43 , & V_37 ) ;
if ( V_48 )
return V_48 ;
if ( V_43 [ V_16 ] ) {
V_33 . V_6 = F_24 ( V_43 [ V_16 ] ) ;
if ( ! V_33 . V_6 || V_33 . V_6 > V_35 )
return - V_54 ;
}
if ( V_43 [ V_17 ] ) {
T_1 V_55 = F_25 ( V_43 [ V_17 ] ) ;
if ( V_55 & V_11 )
V_10 |= ( V_11 << 16 ) ;
}
if ( V_26 == V_39 || ! V_43 [ V_56 ] ) {
V_33 . V_5 = F_12 ( V_5 & F_26 ( V_33 . V_6 ) ) ;
V_48 = V_31 ( V_22 , & V_33 , & V_37 , & V_37 , V_10 ) ;
return F_27 ( V_48 , V_10 , V_26 ) ? 1 :
F_28 ( V_48 , V_10 ) ? 0 : V_48 ;
}
V_46 = V_5 ;
if ( V_43 [ V_56 ] ) {
V_48 = F_22 ( V_43 [ V_56 ] , & V_46 ) ;
if ( V_48 )
return V_48 ;
if ( V_46 < V_5 )
F_5 ( V_5 , V_46 ) ;
if ( V_5 + V_57 == V_46 )
return - V_58 ;
}
if ( V_45 )
V_5 = F_29 ( V_30 -> V_19 . V_5 ) ;
while ( ! F_30 ( V_5 , V_46 ) ) {
V_33 . V_5 = F_12 ( V_5 ) ;
V_47 = F_31 ( V_5 , V_46 , & V_33 . V_6 ) ;
V_48 = V_31 ( V_22 , & V_33 , & V_37 , & V_37 , V_10 ) ;
if ( V_48 && ! F_28 ( V_48 , V_10 ) )
return V_48 ;
else
V_48 = 0 ;
V_5 = V_47 + 1 ;
}
return V_48 ;
}
static inline bool
F_32 ( const struct V_59 * V_2 ,
const struct V_59 * V_3 ,
T_1 * V_4 )
{
return F_33 ( & V_2 -> V_5 . V_60 , & V_3 -> V_5 . V_60 ) &&
V_2 -> V_6 == V_3 -> V_6 ;
}
static inline int
F_34 ( const struct V_59 * V_7 )
{
return V_7 -> V_8 ? - V_9 : 1 ;
}
static inline void
F_35 ( struct V_59 * V_7 , T_1 V_10 )
{
V_7 -> V_8 = ( V_10 >> 16 ) & V_11 ;
}
static inline void
F_36 ( struct V_59 * V_7 , T_2 * V_10 )
{
F_5 ( * V_10 , V_7 -> V_8 ) ;
}
static inline void
F_37 ( struct V_59 * V_7 , T_2 V_6 )
{
F_38 ( & V_7 -> V_5 , V_6 ) ;
V_7 -> V_6 = V_6 ;
}
static bool
F_39 ( struct V_12 * V_13 , const struct V_59 * V_14 )
{
T_1 V_10 = V_14 -> V_8 ? V_11 : 0 ;
if ( F_40 ( V_13 , V_15 , & V_14 -> V_5 . V_60 ) ||
F_10 ( V_13 , V_16 , V_14 -> V_6 ) ||
( V_10 &&
F_11 ( V_13 , V_17 , F_12 ( V_10 ) ) ) )
goto V_18;
return 0 ;
V_18:
return 1 ;
}
static inline void
F_41 ( struct V_1 * V_19 ,
const struct V_59 * V_20 )
{
}
static int
F_42 ( struct V_21 * V_22 , const struct V_12 * V_13 ,
const struct V_23 * V_24 ,
enum V_25 V_26 , struct V_27 * V_28 )
{
const struct V_29 * V_30 = V_22 -> V_14 ;
T_3 V_31 = V_22 -> V_32 -> V_26 [ V_26 ] ;
struct V_59 V_33 = {
. V_6 = V_30 -> V_34 [ 0 ] . V_6 ? V_30 -> V_34 [ 0 ] . V_6 : V_35
} ;
struct V_36 V_37 = F_15 ( V_13 , V_28 , V_30 ) ;
if ( V_33 . V_6 == 0 )
return - V_38 ;
if ( V_26 == V_39 )
V_33 . V_6 = V_35 ;
F_43 ( V_13 , V_28 -> V_10 & V_40 , & V_33 . V_5 . V_60 ) ;
F_38 ( & V_33 . V_5 , V_33 . V_6 ) ;
return V_31 ( V_22 , & V_33 , & V_37 , & V_28 -> V_37 , V_28 -> V_41 ) ;
}
static int
F_44 ( struct V_21 * V_22 , struct V_42 * V_43 [] ,
enum V_25 V_26 , T_1 * V_44 , T_1 V_10 , bool V_45 )
{
const struct V_29 * V_30 = V_22 -> V_14 ;
T_3 V_31 = V_22 -> V_32 -> V_26 [ V_26 ] ;
struct V_59 V_33 = { . V_6 = V_35 } ;
struct V_36 V_37 = F_18 ( V_30 ) ;
int V_48 ;
if ( F_19 ( ! V_43 [ V_15 ] ||
! F_20 ( V_43 , V_49 ) ||
! F_20 ( V_43 , V_17 ) ||
! F_20 ( V_43 , V_50 ) ||
! F_20 ( V_43 , V_51 ) ) )
return - V_52 ;
if ( F_19 ( V_43 [ V_56 ] ) )
return - V_61 ;
if ( V_43 [ V_53 ] )
* V_44 = F_21 ( V_43 [ V_53 ] ) ;
V_48 = F_45 ( V_43 [ V_15 ] , & V_33 . V_5 ) ||
F_23 ( V_22 , V_43 , & V_37 ) ;
if ( V_48 )
return V_48 ;
if ( V_43 [ V_16 ] )
V_33 . V_6 = F_24 ( V_43 [ V_16 ] ) ;
if ( ! V_33 . V_6 || V_33 . V_6 > V_35 )
return - V_54 ;
F_38 ( & V_33 . V_5 , V_33 . V_6 ) ;
if ( V_43 [ V_17 ] ) {
T_1 V_55 = F_25 ( V_43 [ V_17 ] ) ;
if ( V_55 & V_11 )
V_10 |= ( V_11 << 16 ) ;
}
V_48 = V_31 ( V_22 , & V_33 , & V_37 , & V_37 , V_10 ) ;
return F_27 ( V_48 , V_10 , V_26 ) ? 1 :
F_28 ( V_48 , V_10 ) ? 0 : V_48 ;
}
static int T_4
F_46 ( void )
{
return F_47 ( & V_62 ) ;
}
static void T_5
F_48 ( void )
{
F_49 ( & V_62 ) ;
}
