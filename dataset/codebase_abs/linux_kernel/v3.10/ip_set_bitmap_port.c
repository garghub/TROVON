static inline T_1
F_1 ( const struct V_1 * V_2 , T_1 V_3 )
{
return V_3 - V_2 -> V_4 ;
}
static inline int
F_2 ( const struct V_5 * V_6 ,
const struct V_1 * V_7 )
{
return ! ! F_3 ( V_6 -> V_8 , V_7 -> V_9 ) ;
}
static inline int
F_4 ( T_1 V_8 , const struct V_1 * V_7 )
{
return ! ! F_3 ( V_8 , V_7 -> V_9 ) ;
}
static inline int
F_5 ( const struct V_5 * V_6 ,
struct V_1 * V_7 , T_2 V_10 )
{
return ! ! F_6 ( V_6 -> V_8 , V_7 -> V_9 ) ;
}
static inline int
F_7 ( const struct V_5 * V_6 ,
struct V_1 * V_7 )
{
return ! F_8 ( V_6 -> V_8 , V_7 -> V_9 ) ;
}
static inline int
F_9 ( struct V_11 * V_12 , const struct V_1 * V_7 , T_2 V_8 )
{
return F_10 ( V_12 , V_13 ,
F_11 ( V_7 -> V_4 + V_8 ) ) ;
}
static inline int
F_12 ( struct V_11 * V_12 , const struct V_1 * V_7 )
{
return F_10 ( V_12 , V_13 , F_11 ( V_7 -> V_4 ) ) ||
F_10 ( V_12 , V_14 , F_11 ( V_7 -> V_15 ) ) ;
}
static int
F_13 ( struct V_16 * V_17 , const struct V_11 * V_12 ,
const struct V_18 * V_19 ,
enum V_20 V_21 , struct V_22 * V_23 )
{
struct V_1 * V_7 = V_17 -> V_24 ;
T_3 V_25 = V_17 -> V_26 -> V_21 [ V_21 ] ;
struct V_5 V_6 = {} ;
struct V_27 V_28 = F_14 ( V_12 , V_23 , V_7 ) ;
T_4 V_29 ;
T_1 V_3 = 0 ;
if ( ! F_15 ( V_12 , V_23 -> V_30 ,
V_23 -> V_10 & V_31 , & V_29 ) )
return - V_32 ;
V_3 = F_16 ( V_29 ) ;
if ( V_3 < V_7 -> V_4 || V_3 > V_7 -> V_15 )
return - V_33 ;
V_6 . V_8 = F_1 ( V_7 , V_3 ) ;
return V_25 ( V_17 , & V_6 , & V_28 , & V_23 -> V_28 , V_23 -> V_34 ) ;
}
static int
F_17 ( struct V_16 * V_17 , struct V_35 * V_36 [] ,
enum V_20 V_21 , T_2 * V_37 , T_2 V_10 , bool V_38 )
{
struct V_1 * V_7 = V_17 -> V_24 ;
T_3 V_25 = V_17 -> V_26 -> V_21 [ V_21 ] ;
struct V_5 V_6 = {} ;
struct V_27 V_28 = F_18 ( V_7 ) ;
T_2 V_3 ;
T_1 V_39 ;
int V_40 = 0 ;
if ( F_19 ( ! F_20 ( V_36 , V_13 ) ||
! F_21 ( V_36 , V_14 ) ||
! F_21 ( V_36 , V_41 ) ||
! F_21 ( V_36 , V_42 ) ||
! F_21 ( V_36 , V_43 ) ) )
return - V_44 ;
if ( V_36 [ V_45 ] )
* V_37 = F_22 ( V_36 [ V_45 ] ) ;
V_3 = F_23 ( V_36 [ V_13 ] ) ;
if ( V_3 < V_7 -> V_4 || V_3 > V_7 -> V_15 )
return - V_33 ;
V_40 = F_24 ( V_17 , V_36 , & V_28 ) ;
if ( V_40 )
return V_40 ;
if ( V_21 == V_46 ) {
V_6 . V_8 = F_1 ( V_7 , V_3 ) ;
return V_25 ( V_17 , & V_6 , & V_28 , & V_28 , V_10 ) ;
}
if ( V_36 [ V_14 ] ) {
V_39 = F_23 ( V_36 [ V_14 ] ) ;
if ( V_3 > V_39 ) {
F_25 ( V_3 , V_39 ) ;
if ( V_3 < V_7 -> V_4 )
return - V_33 ;
}
} else
V_39 = V_3 ;
if ( V_39 > V_7 -> V_15 )
return - V_33 ;
for (; V_3 <= V_39 ; V_3 ++ ) {
V_6 . V_8 = F_1 ( V_7 , V_3 ) ;
V_40 = V_25 ( V_17 , & V_6 , & V_28 , & V_28 , V_10 ) ;
if ( V_40 && ! F_26 ( V_40 , V_10 ) )
return V_40 ;
else
V_40 = 0 ;
}
return V_40 ;
}
static bool
F_27 ( const struct V_16 * V_47 , const struct V_16 * V_48 )
{
const struct V_1 * V_49 = V_47 -> V_24 ;
const struct V_1 * V_50 = V_48 -> V_24 ;
return V_49 -> V_4 == V_50 -> V_4 &&
V_49 -> V_15 == V_50 -> V_15 &&
V_49 -> V_51 == V_50 -> V_51 &&
V_47 -> V_52 == V_48 -> V_52 ;
}
static bool
F_28 ( struct V_16 * V_17 , struct V_1 * V_7 ,
T_1 V_4 , T_1 V_15 )
{
V_7 -> V_9 = F_29 ( V_7 -> V_53 ) ;
if ( ! V_7 -> V_9 )
return false ;
if ( V_7 -> V_54 ) {
V_7 -> V_52 = F_29 ( V_7 -> V_54 * V_7 -> V_55 ) ;
if ( ! V_7 -> V_52 ) {
F_30 ( V_7 -> V_9 ) ;
return false ;
}
}
V_7 -> V_4 = V_4 ;
V_7 -> V_15 = V_15 ;
V_7 -> V_51 = V_56 ;
V_17 -> V_24 = V_7 ;
V_17 -> V_30 = V_57 ;
return true ;
}
static int
F_31 ( struct V_16 * V_17 , struct V_35 * V_36 [] , T_2 V_10 )
{
struct V_1 * V_7 ;
T_1 V_4 , V_15 ;
T_2 V_58 = 0 ;
if ( F_19 ( ! F_20 ( V_36 , V_13 ) ||
! F_20 ( V_36 , V_14 ) ||
! F_21 ( V_36 , V_41 ) ||
! F_21 ( V_36 , V_59 ) ) )
return - V_44 ;
V_4 = F_23 ( V_36 [ V_13 ] ) ;
V_15 = F_23 ( V_36 [ V_14 ] ) ;
if ( V_4 > V_15 ) {
T_1 V_60 = V_4 ;
V_4 = V_15 ;
V_15 = V_60 ;
}
V_7 = F_32 ( sizeof( * V_7 ) , V_61 ) ;
if ( ! V_7 )
return - V_62 ;
V_7 -> V_55 = V_15 - V_4 + 1 ;
V_7 -> V_53 = V_7 -> V_55 * sizeof( unsigned long ) ;
V_17 -> V_26 = & V_1 ;
if ( V_36 [ V_59 ] )
V_58 = F_33 ( V_36 [ V_59 ] ) ;
if ( V_58 & V_63 ) {
V_17 -> V_52 |= V_64 ;
if ( V_36 [ V_41 ] ) {
V_7 -> V_54 = sizeof( struct V_65 ) ;
V_7 -> V_66 [ V_67 ] =
F_34 ( struct V_65 , V_51 ) ;
V_7 -> V_66 [ V_68 ] =
F_34 ( struct V_65 , V_69 ) ;
if ( ! F_28 ( V_17 , V_7 , V_4 , V_15 ) ) {
F_30 ( V_7 ) ;
return - V_62 ;
}
V_7 -> V_51 =
F_35 ( V_36 [ V_41 ] ) ;
V_17 -> V_52 |= V_70 ;
F_36 ( V_17 , V_71 ) ;
} else {
V_7 -> V_54 = sizeof( struct V_72 ) ;
V_7 -> V_66 [ V_68 ] =
F_34 ( struct V_72 , V_69 ) ;
if ( ! F_28 ( V_17 , V_7 , V_4 , V_15 ) ) {
F_30 ( V_7 ) ;
return - V_62 ;
}
}
} else if ( V_36 [ V_41 ] ) {
V_7 -> V_54 = sizeof( struct V_73 ) ;
V_7 -> V_66 [ V_67 ] =
F_34 ( struct V_73 , V_51 ) ;
if ( ! F_28 ( V_17 , V_7 , V_4 , V_15 ) ) {
F_30 ( V_7 ) ;
return - V_62 ;
}
V_7 -> V_51 = F_35 ( V_36 [ V_41 ] ) ;
V_17 -> V_52 |= V_70 ;
F_36 ( V_17 , V_71 ) ;
} else {
V_7 -> V_54 = 0 ;
if ( ! F_28 ( V_17 , V_7 , V_4 , V_15 ) ) {
F_30 ( V_7 ) ;
return - V_62 ;
}
}
return 0 ;
}
static int T_5
F_37 ( void )
{
return F_38 ( & V_74 ) ;
}
static void T_6
F_39 ( void )
{
F_40 ( & V_74 ) ;
}
