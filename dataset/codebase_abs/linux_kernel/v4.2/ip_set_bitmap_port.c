static inline T_1
F_1 ( const struct V_1 * V_2 , T_1 V_3 )
{
return V_3 - V_2 -> V_4 ;
}
static inline int
F_2 ( const struct V_5 * V_6 ,
const struct V_1 * V_7 , T_2 V_8 )
{
return ! ! F_3 ( V_6 -> V_9 , V_7 -> V_10 ) ;
}
static inline int
F_4 ( T_1 V_9 , const struct V_1 * V_7 , T_2 V_8 )
{
return ! ! F_3 ( V_9 , V_7 -> V_10 ) ;
}
static inline int
F_5 ( const struct V_5 * V_6 ,
struct V_1 * V_7 , T_3 V_11 , T_2 V_8 )
{
return ! ! F_3 ( V_6 -> V_9 , V_7 -> V_10 ) ;
}
static inline int
F_6 ( const struct V_5 * V_6 ,
struct V_1 * V_7 )
{
return ! F_7 ( V_6 -> V_9 , V_7 -> V_10 ) ;
}
static inline int
F_8 ( struct V_12 * V_13 , const struct V_1 * V_7 , T_3 V_9 ,
T_2 V_8 )
{
return F_9 ( V_13 , V_14 ,
F_10 ( V_7 -> V_4 + V_9 ) ) ;
}
static inline int
F_11 ( struct V_12 * V_13 , const struct V_1 * V_7 )
{
return F_9 ( V_13 , V_14 , F_10 ( V_7 -> V_4 ) ) ||
F_9 ( V_13 , V_15 , F_10 ( V_7 -> V_16 ) ) ;
}
static int
F_12 ( struct V_17 * V_18 , const struct V_12 * V_13 ,
const struct V_19 * V_20 ,
enum V_21 V_22 , struct V_23 * V_24 )
{
struct V_1 * V_7 = V_18 -> V_25 ;
T_4 V_26 = V_18 -> V_27 -> V_22 [ V_22 ] ;
struct V_5 V_6 = { . V_9 = 0 } ;
struct V_28 V_29 = F_13 ( V_13 , V_24 , V_18 ) ;
T_5 V_30 ;
T_1 V_3 = 0 ;
if ( ! F_14 ( V_13 , V_24 -> V_31 ,
V_24 -> V_11 & V_32 , & V_30 ) )
return - V_33 ;
V_3 = F_15 ( V_30 ) ;
if ( V_3 < V_7 -> V_4 || V_3 > V_7 -> V_16 )
return - V_34 ;
V_6 . V_9 = F_1 ( V_7 , V_3 ) ;
return V_26 ( V_18 , & V_6 , & V_29 , & V_24 -> V_29 , V_24 -> V_35 ) ;
}
static int
F_16 ( struct V_17 * V_18 , struct V_36 * V_37 [] ,
enum V_21 V_22 , T_3 * V_38 , T_3 V_11 , bool V_39 )
{
struct V_1 * V_7 = V_18 -> V_25 ;
T_4 V_26 = V_18 -> V_27 -> V_22 [ V_22 ] ;
struct V_5 V_6 = { . V_9 = 0 } ;
struct V_28 V_29 = F_17 ( V_18 ) ;
T_3 V_3 ;
T_1 V_40 ;
int V_41 = 0 ;
if ( V_37 [ V_42 ] )
* V_38 = F_18 ( V_37 [ V_42 ] ) ;
if ( F_19 ( ! F_20 ( V_37 , V_14 ) ||
! F_21 ( V_37 , V_15 ) ) )
return - V_43 ;
V_3 = F_22 ( V_37 [ V_14 ] ) ;
if ( V_3 < V_7 -> V_4 || V_3 > V_7 -> V_16 )
return - V_34 ;
V_41 = F_23 ( V_18 , V_37 , & V_29 ) ;
if ( V_41 )
return V_41 ;
if ( V_22 == V_44 ) {
V_6 . V_9 = F_1 ( V_7 , V_3 ) ;
return V_26 ( V_18 , & V_6 , & V_29 , & V_29 , V_11 ) ;
}
if ( V_37 [ V_15 ] ) {
V_40 = F_22 ( V_37 [ V_15 ] ) ;
if ( V_3 > V_40 ) {
F_24 ( V_3 , V_40 ) ;
if ( V_3 < V_7 -> V_4 )
return - V_34 ;
}
} else {
V_40 = V_3 ;
}
if ( V_40 > V_7 -> V_16 )
return - V_34 ;
for (; V_3 <= V_40 ; V_3 ++ ) {
V_6 . V_9 = F_1 ( V_7 , V_3 ) ;
V_41 = V_26 ( V_18 , & V_6 , & V_29 , & V_29 , V_11 ) ;
if ( V_41 && ! F_25 ( V_41 , V_11 ) )
return V_41 ;
V_41 = 0 ;
}
return V_41 ;
}
static bool
F_26 ( const struct V_17 * V_45 , const struct V_17 * V_46 )
{
const struct V_1 * V_47 = V_45 -> V_25 ;
const struct V_1 * V_48 = V_46 -> V_25 ;
return V_47 -> V_4 == V_48 -> V_4 &&
V_47 -> V_16 == V_48 -> V_16 &&
V_45 -> V_49 == V_46 -> V_49 &&
V_45 -> V_50 == V_46 -> V_50 ;
}
static bool
F_27 ( struct V_17 * V_18 , struct V_1 * V_7 ,
T_1 V_4 , T_1 V_16 )
{
V_7 -> V_10 = F_28 ( V_7 -> V_51 ) ;
if ( ! V_7 -> V_10 )
return false ;
if ( V_18 -> V_8 ) {
V_7 -> V_50 = F_28 ( V_18 -> V_8 * V_7 -> V_52 ) ;
if ( ! V_7 -> V_50 ) {
F_29 ( V_7 -> V_10 ) ;
return false ;
}
}
V_7 -> V_4 = V_4 ;
V_7 -> V_16 = V_16 ;
V_18 -> V_49 = V_53 ;
V_18 -> V_25 = V_7 ;
V_18 -> V_31 = V_54 ;
return true ;
}
static int
F_30 ( struct V_55 * V_55 , struct V_17 * V_18 , struct V_36 * V_37 [] ,
T_3 V_11 )
{
struct V_1 * V_7 ;
T_1 V_4 , V_16 ;
if ( F_19 ( ! F_20 ( V_37 , V_14 ) ||
! F_20 ( V_37 , V_15 ) ||
! F_21 ( V_37 , V_56 ) ||
! F_21 ( V_37 , V_57 ) ) )
return - V_43 ;
V_4 = F_22 ( V_37 [ V_14 ] ) ;
V_16 = F_22 ( V_37 [ V_15 ] ) ;
if ( V_4 > V_16 ) {
T_1 V_58 = V_4 ;
V_4 = V_16 ;
V_16 = V_58 ;
}
V_7 = F_31 ( sizeof( * V_7 ) , V_59 ) ;
if ( ! V_7 )
return - V_60 ;
V_7 -> V_52 = V_16 - V_4 + 1 ;
V_7 -> V_51 = F_32 ( 0 , V_7 -> V_52 ) ;
V_18 -> V_27 = & V_1 ;
V_18 -> V_8 = F_33 ( V_18 , V_37 , 0 ) ;
if ( ! F_27 ( V_18 , V_7 , V_4 , V_16 ) ) {
F_29 ( V_7 ) ;
return - V_60 ;
}
if ( V_37 [ V_56 ] ) {
V_18 -> V_49 = F_34 ( V_37 [ V_56 ] ) ;
F_35 ( V_18 , V_61 ) ;
}
return 0 ;
}
static int T_6
F_36 ( void )
{
return F_37 ( & V_62 ) ;
}
static void T_7
F_38 ( void )
{
F_39 () ;
F_40 ( & V_62 ) ;
}
