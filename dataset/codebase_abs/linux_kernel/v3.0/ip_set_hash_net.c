static inline bool
F_1 ( const struct V_1 * V_2 ,
const struct V_1 * V_3 )
{
return V_2 -> V_4 == V_3 -> V_4 && V_2 -> V_5 == V_3 -> V_5 ;
}
static inline bool
F_2 ( const struct V_1 * V_6 )
{
return V_6 -> V_5 == 0 ;
}
static inline void
F_3 ( struct V_1 * V_7 ,
const struct V_1 * V_8 )
{
V_7 -> V_4 = V_8 -> V_4 ;
V_7 -> V_5 = V_8 -> V_5 ;
}
static inline void
F_4 ( struct V_1 * V_6 , T_1 V_5 )
{
V_6 -> V_4 &= F_5 ( V_5 ) ;
V_6 -> V_5 = V_5 ;
}
static inline void
F_6 ( struct V_1 * V_6 )
{
V_6 -> V_5 = 0 ;
}
static bool
F_7 ( struct V_9 * V_10 , const struct V_1 * V_11 )
{
F_8 ( V_10 , V_12 , V_11 -> V_4 ) ;
F_9 ( V_10 , V_13 , V_11 -> V_5 ) ;
return 0 ;
V_14:
return 1 ;
}
static bool
F_10 ( struct V_9 * V_10 , const struct V_1 * V_11 )
{
const struct V_15 * V_16 =
( const struct V_15 * ) V_11 ;
F_8 ( V_10 , V_12 , V_16 -> V_4 ) ;
F_9 ( V_10 , V_13 , V_16 -> V_5 ) ;
F_11 ( V_10 , V_17 ,
F_12 ( F_13 ( V_16 -> V_18 ) ) ) ;
return 0 ;
V_14:
return 1 ;
}
static int
F_14 ( struct V_19 * V_20 , const struct V_9 * V_10 ,
enum V_21 V_22 , T_1 V_23 , T_1 V_24 , T_1 V_25 )
{
const struct V_26 * V_27 = V_20 -> V_11 ;
T_2 V_28 = V_20 -> V_29 -> V_22 [ V_22 ] ;
struct V_1 V_11 = {
. V_5 = V_27 -> V_30 [ 0 ] . V_5 ? V_27 -> V_30 [ 0 ] . V_5 : V_31
} ;
if ( V_11 . V_5 == 0 )
return - V_32 ;
if ( V_22 == V_33 )
V_11 . V_5 = V_31 ;
F_15 ( V_10 , V_25 & V_34 , & V_11 . V_4 ) ;
V_11 . V_4 &= F_5 ( V_11 . V_5 ) ;
return V_28 ( V_20 , & V_11 , V_27 -> V_18 ) ;
}
static int
F_16 ( struct V_19 * V_20 , struct V_35 * V_36 [] ,
enum V_21 V_22 , T_3 * V_37 , T_3 V_25 )
{
const struct V_26 * V_27 = V_20 -> V_11 ;
T_2 V_28 = V_20 -> V_29 -> V_22 [ V_22 ] ;
struct V_1 V_11 = { . V_5 = V_31 } ;
T_3 V_18 = V_27 -> V_18 ;
int V_38 ;
if ( F_17 ( ! V_36 [ V_12 ] ||
! F_18 ( V_36 , V_17 ) ) )
return - V_39 ;
if ( V_36 [ V_40 ] )
* V_37 = F_19 ( V_36 [ V_40 ] ) ;
V_38 = F_20 ( V_36 [ V_12 ] , & V_11 . V_4 ) ;
if ( V_38 )
return V_38 ;
if ( V_36 [ V_13 ] )
V_11 . V_5 = F_21 ( V_36 [ V_13 ] ) ;
if ( ! V_11 . V_5 )
return - V_41 ;
V_11 . V_4 &= F_5 ( V_11 . V_5 ) ;
if ( V_36 [ V_17 ] ) {
if ( ! F_22 ( V_27 -> V_18 ) )
return - V_42 ;
V_18 = F_23 ( V_36 [ V_17 ] ) ;
}
V_38 = V_28 ( V_20 , & V_11 , V_18 ) ;
return F_24 ( V_38 , V_25 ) ? 0 : V_38 ;
}
static bool
F_25 ( const struct V_19 * V_43 , const struct V_19 * V_44 )
{
const struct V_26 * V_45 = V_43 -> V_11 ;
const struct V_26 * V_46 = V_44 -> V_11 ;
return V_45 -> V_47 == V_46 -> V_47 &&
V_45 -> V_18 == V_46 -> V_18 ;
}
static inline bool
F_26 ( const struct V_48 * V_2 ,
const struct V_48 * V_3 )
{
return F_27 ( & V_2 -> V_4 . V_49 , & V_3 -> V_4 . V_49 ) == 0 &&
V_2 -> V_5 == V_3 -> V_5 ;
}
static inline bool
F_28 ( const struct V_48 * V_6 )
{
return V_6 -> V_5 == 0 ;
}
static inline void
F_29 ( struct V_48 * V_7 ,
const struct V_48 * V_8 )
{
F_30 ( & V_7 -> V_4 . V_49 , & V_8 -> V_4 . V_49 ) ;
V_7 -> V_5 = V_8 -> V_5 ;
}
static inline void
F_31 ( struct V_48 * V_6 )
{
V_6 -> V_5 = 0 ;
}
static inline void
F_32 ( union V_50 * V_4 , T_1 V_51 )
{
V_4 -> V_52 [ 0 ] &= F_33 ( V_51 ) [ 0 ] ;
V_4 -> V_52 [ 1 ] &= F_33 ( V_51 ) [ 1 ] ;
V_4 -> V_52 [ 2 ] &= F_33 ( V_51 ) [ 2 ] ;
V_4 -> V_52 [ 3 ] &= F_33 ( V_51 ) [ 3 ] ;
}
static inline void
F_34 ( struct V_48 * V_6 , T_1 V_5 )
{
F_32 ( & V_6 -> V_4 , V_5 ) ;
V_6 -> V_5 = V_5 ;
}
static bool
F_35 ( struct V_9 * V_10 , const struct V_48 * V_11 )
{
F_36 ( V_10 , V_12 , & V_11 -> V_4 ) ;
F_9 ( V_10 , V_13 , V_11 -> V_5 ) ;
return 0 ;
V_14:
return 1 ;
}
static bool
F_37 ( struct V_9 * V_10 , const struct V_48 * V_11 )
{
const struct V_53 * V_54 =
( const struct V_53 * ) V_11 ;
F_36 ( V_10 , V_12 , & V_54 -> V_4 ) ;
F_9 ( V_10 , V_13 , V_54 -> V_5 ) ;
F_11 ( V_10 , V_17 ,
F_12 ( F_13 ( V_54 -> V_18 ) ) ) ;
return 0 ;
V_14:
return 1 ;
}
static int
F_38 ( struct V_19 * V_20 , const struct V_9 * V_10 ,
enum V_21 V_22 , T_1 V_23 , T_1 V_24 , T_1 V_25 )
{
const struct V_26 * V_27 = V_20 -> V_11 ;
T_2 V_28 = V_20 -> V_29 -> V_22 [ V_22 ] ;
struct V_48 V_11 = {
. V_5 = V_27 -> V_30 [ 0 ] . V_5 ? V_27 -> V_30 [ 0 ] . V_5 : V_31
} ;
if ( V_11 . V_5 == 0 )
return - V_32 ;
if ( V_22 == V_33 )
V_11 . V_5 = V_31 ;
F_39 ( V_10 , V_25 & V_34 , & V_11 . V_4 . V_49 ) ;
F_32 ( & V_11 . V_4 , V_11 . V_5 ) ;
return V_28 ( V_20 , & V_11 , V_27 -> V_18 ) ;
}
static int
F_40 ( struct V_19 * V_20 , struct V_35 * V_36 [] ,
enum V_21 V_22 , T_3 * V_37 , T_3 V_25 )
{
const struct V_26 * V_27 = V_20 -> V_11 ;
T_2 V_28 = V_20 -> V_29 -> V_22 [ V_22 ] ;
struct V_48 V_11 = { . V_5 = V_31 } ;
T_3 V_18 = V_27 -> V_18 ;
int V_38 ;
if ( F_17 ( ! V_36 [ V_12 ] ||
! F_18 ( V_36 , V_17 ) ) )
return - V_39 ;
if ( V_36 [ V_40 ] )
* V_37 = F_19 ( V_36 [ V_40 ] ) ;
V_38 = F_41 ( V_36 [ V_12 ] , & V_11 . V_4 ) ;
if ( V_38 )
return V_38 ;
if ( V_36 [ V_13 ] )
V_11 . V_5 = F_21 ( V_36 [ V_13 ] ) ;
if ( ! V_11 . V_5 )
return - V_41 ;
F_32 ( & V_11 . V_4 , V_11 . V_5 ) ;
if ( V_36 [ V_17 ] ) {
if ( ! F_22 ( V_27 -> V_18 ) )
return - V_42 ;
V_18 = F_23 ( V_36 [ V_17 ] ) ;
}
V_38 = V_28 ( V_20 , & V_11 , V_18 ) ;
return F_24 ( V_38 , V_25 ) ? 0 : V_38 ;
}
static int
F_42 ( struct V_19 * V_20 , struct V_35 * V_36 [] , T_3 V_25 )
{
T_3 V_55 = V_56 , V_47 = V_57 ;
struct V_26 * V_27 ;
T_1 V_58 ;
if ( ! ( V_20 -> V_59 == V_60 || V_20 -> V_59 == V_61 ) )
return - V_62 ;
if ( F_17 ( ! F_18 ( V_36 , V_63 ) ||
! F_18 ( V_36 , V_64 ) ||
! F_18 ( V_36 , V_17 ) ) )
return - V_39 ;
if ( V_36 [ V_63 ] ) {
V_55 = F_43 ( V_36 [ V_63 ] ) ;
if ( V_55 < V_65 )
V_55 = V_65 ;
}
if ( V_36 [ V_64 ] )
V_47 = F_43 ( V_36 [ V_64 ] ) ;
V_27 = F_44 ( sizeof( * V_27 )
+ sizeof( struct V_66 )
* ( V_20 -> V_59 == V_60 ? 32 : 128 ) , V_67 ) ;
if ( ! V_27 )
return - V_68 ;
V_27 -> V_47 = V_47 ;
F_45 ( & V_27 -> V_69 , sizeof( V_27 -> V_69 ) ) ;
V_27 -> V_18 = V_70 ;
V_58 = F_46 ( V_55 ) ;
V_27 -> V_71 = F_47 (
sizeof( struct V_72 )
+ F_48 ( V_58 ) * sizeof( struct V_73 ) ) ;
if ( ! V_27 -> V_71 ) {
F_49 ( V_27 ) ;
return - V_68 ;
}
V_27 -> V_71 -> F_46 = V_58 ;
V_20 -> V_11 = V_27 ;
if ( V_36 [ V_17 ] ) {
V_27 -> V_18 = F_23 ( V_36 [ V_17 ] ) ;
V_20 -> V_29 = V_20 -> V_59 == V_60
? & V_74 : & V_75 ;
if ( V_20 -> V_59 == V_60 )
F_50 ( V_20 ) ;
else
F_51 ( V_20 ) ;
} else {
V_20 -> V_29 = V_20 -> V_59 == V_60
? & V_76 : & V_77 ;
}
F_52 ( L_1 ,
V_20 -> V_78 , F_48 ( V_27 -> V_71 -> F_46 ) ,
V_27 -> V_71 -> F_46 , V_27 -> V_47 , V_20 -> V_11 , V_27 -> V_71 ) ;
return 0 ;
}
static int T_4
F_53 ( void )
{
return F_54 ( & V_79 ) ;
}
static void T_5
F_55 ( void )
{
F_56 ( & V_79 ) ;
}
