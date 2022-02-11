static inline bool
F_1 ( const struct V_1 * V_2 ,
const struct V_1 * V_3 )
{
return V_2 -> V_4 == V_3 -> V_4 &&
V_2 -> V_5 == V_3 -> V_5 &&
V_2 -> V_6 == V_3 -> V_6 &&
V_2 -> V_7 == V_3 -> V_7 ;
}
static inline bool
F_2 ( const struct V_1 * V_8 )
{
return V_8 -> V_6 == 0 ;
}
static inline void
F_3 ( struct V_1 * V_9 ,
const struct V_1 * V_10 )
{
V_9 -> V_4 = V_10 -> V_4 ;
V_9 -> V_5 = V_10 -> V_5 ;
V_9 -> V_6 = V_10 -> V_6 ;
V_9 -> V_7 = V_10 -> V_7 ;
}
static inline void
F_4 ( struct V_1 * V_8 , T_1 V_7 )
{
V_8 -> V_4 &= F_5 ( V_7 ) ;
V_8 -> V_7 = V_7 ;
}
static inline void
F_6 ( struct V_1 * V_8 )
{
V_8 -> V_6 = 0 ;
}
static bool
F_7 ( struct V_11 * V_12 ,
const struct V_1 * V_13 )
{
F_8 ( V_12 , V_14 , V_13 -> V_4 ) ;
F_9 ( V_12 , V_15 , V_13 -> V_5 ) ;
F_10 ( V_12 , V_16 , V_13 -> V_7 ) ;
F_10 ( V_12 , V_17 , V_13 -> V_6 ) ;
return 0 ;
V_18:
return 1 ;
}
static bool
F_11 ( struct V_11 * V_12 ,
const struct V_1 * V_13 )
{
const struct V_19 * V_20 =
( const struct V_19 * ) V_13 ;
F_8 ( V_12 , V_14 , V_20 -> V_4 ) ;
F_9 ( V_12 , V_15 , V_20 -> V_5 ) ;
F_10 ( V_12 , V_16 , V_13 -> V_7 ) ;
F_10 ( V_12 , V_17 , V_13 -> V_6 ) ;
F_12 ( V_12 , V_21 ,
F_13 ( F_14 ( V_20 -> V_22 ) ) ) ;
return 0 ;
V_18:
return 1 ;
}
static int
F_15 ( struct V_23 * V_24 , const struct V_11 * V_12 ,
enum V_25 V_26 , T_1 V_27 , T_1 V_28 , T_1 V_29 )
{
const struct V_30 * V_31 = V_24 -> V_13 ;
T_2 V_32 = V_24 -> V_33 -> V_26 [ V_26 ] ;
struct V_1 V_13 = {
. V_7 = V_31 -> V_34 [ 0 ] . V_7 ? V_31 -> V_34 [ 0 ] . V_7 : V_35
} ;
if ( V_13 . V_7 == 0 )
return - V_36 ;
if ( V_26 == V_37 )
V_13 . V_7 = V_35 ;
if ( ! F_16 ( V_12 , V_29 & V_38 ,
& V_13 . V_5 , & V_13 . V_6 ) )
return - V_36 ;
F_17 ( V_12 , V_29 & V_39 , & V_13 . V_4 ) ;
V_13 . V_4 &= F_5 ( V_13 . V_7 ) ;
return V_32 ( V_24 , & V_13 , V_31 -> V_22 ) ;
}
static int
F_18 ( struct V_23 * V_24 , struct V_40 * V_41 [] ,
enum V_25 V_26 , T_3 * V_42 , T_3 V_29 )
{
const struct V_30 * V_31 = V_24 -> V_13 ;
T_2 V_32 = V_24 -> V_33 -> V_26 [ V_26 ] ;
struct V_1 V_13 = { . V_7 = V_35 } ;
T_3 V_5 , V_43 ;
T_3 V_22 = V_31 -> V_22 ;
bool V_44 = false ;
int V_45 ;
if ( F_19 ( ! V_41 [ V_14 ] ||
! F_20 ( V_41 , V_15 ) ||
! F_21 ( V_41 , V_46 ) ||
! F_21 ( V_41 , V_21 ) ) )
return - V_47 ;
if ( V_41 [ V_48 ] )
* V_42 = F_22 ( V_41 [ V_48 ] ) ;
V_45 = F_23 ( V_41 [ V_14 ] , & V_13 . V_4 ) ;
if ( V_45 )
return V_45 ;
if ( V_41 [ V_16 ] )
V_13 . V_7 = F_24 ( V_41 [ V_16 ] ) ;
if ( ! V_13 . V_7 )
return - V_49 ;
V_13 . V_4 &= F_5 ( V_13 . V_7 ) ;
if ( V_41 [ V_15 ] )
V_13 . V_5 = F_25 ( V_41 [ V_15 ] ) ;
else
return - V_47 ;
if ( V_41 [ V_17 ] ) {
V_13 . V_6 = F_24 ( V_41 [ V_17 ] ) ;
V_44 = F_26 ( V_13 . V_6 ) ;
if ( V_13 . V_6 == 0 )
return - V_50 ;
} else
return - V_51 ;
if ( ! ( V_44 || V_13 . V_6 == V_52 ) )
V_13 . V_5 = 0 ;
if ( V_41 [ V_21 ] ) {
if ( ! F_27 ( V_31 -> V_22 ) )
return - V_53 ;
V_22 = F_28 ( V_41 [ V_21 ] ) ;
}
if ( V_26 == V_37 || ! V_44 || ! V_41 [ V_46 ] ) {
V_45 = V_32 ( V_24 , & V_13 , V_22 ) ;
return F_29 ( V_45 , V_29 ) ? 0 : V_45 ;
}
V_5 = F_30 ( V_13 . V_5 ) ;
V_43 = F_31 ( V_41 [ V_46 ] ) ;
if ( V_5 > V_43 )
F_32 ( V_5 , V_43 ) ;
for (; V_5 <= V_43 ; V_5 ++ ) {
V_13 . V_5 = F_33 ( V_5 ) ;
V_45 = V_32 ( V_24 , & V_13 , V_22 ) ;
if ( V_45 && ! F_29 ( V_45 , V_29 ) )
return V_45 ;
else
V_45 = 0 ;
}
return V_45 ;
}
static bool
F_34 ( const struct V_23 * V_54 , const struct V_23 * V_55 )
{
const struct V_30 * V_56 = V_54 -> V_13 ;
const struct V_30 * V_57 = V_55 -> V_13 ;
return V_56 -> V_58 == V_57 -> V_58 &&
V_56 -> V_22 == V_57 -> V_22 ;
}
static inline bool
F_35 ( const struct V_59 * V_2 ,
const struct V_59 * V_3 )
{
return F_36 ( & V_2 -> V_4 . V_60 , & V_3 -> V_4 . V_60 ) == 0 &&
V_2 -> V_5 == V_3 -> V_5 &&
V_2 -> V_6 == V_3 -> V_6 &&
V_2 -> V_7 == V_3 -> V_7 ;
}
static inline bool
F_37 ( const struct V_59 * V_8 )
{
return V_8 -> V_6 == 0 ;
}
static inline void
F_38 ( struct V_59 * V_9 ,
const struct V_59 * V_10 )
{
memcpy ( V_9 , V_10 , sizeof( * V_9 ) ) ;
}
static inline void
F_39 ( struct V_59 * V_8 )
{
V_8 -> V_6 = 0 ;
}
static inline void
F_40 ( union V_61 * V_4 , T_1 V_62 )
{
V_4 -> V_63 [ 0 ] &= F_41 ( V_62 ) [ 0 ] ;
V_4 -> V_63 [ 1 ] &= F_41 ( V_62 ) [ 1 ] ;
V_4 -> V_63 [ 2 ] &= F_41 ( V_62 ) [ 2 ] ;
V_4 -> V_63 [ 3 ] &= F_41 ( V_62 ) [ 3 ] ;
}
static inline void
F_42 ( struct V_59 * V_8 , T_1 V_7 )
{
F_40 ( & V_8 -> V_4 , V_7 ) ;
V_8 -> V_7 = V_7 ;
}
static bool
F_43 ( struct V_11 * V_12 ,
const struct V_59 * V_13 )
{
F_44 ( V_12 , V_14 , & V_13 -> V_4 ) ;
F_9 ( V_12 , V_15 , V_13 -> V_5 ) ;
F_10 ( V_12 , V_16 , V_13 -> V_7 ) ;
F_10 ( V_12 , V_17 , V_13 -> V_6 ) ;
return 0 ;
V_18:
return 1 ;
}
static bool
F_45 ( struct V_11 * V_12 ,
const struct V_59 * V_13 )
{
const struct V_64 * V_65 =
( const struct V_64 * ) V_13 ;
F_44 ( V_12 , V_14 , & V_65 -> V_4 ) ;
F_9 ( V_12 , V_15 , V_13 -> V_5 ) ;
F_10 ( V_12 , V_16 , V_13 -> V_7 ) ;
F_10 ( V_12 , V_17 , V_13 -> V_6 ) ;
F_12 ( V_12 , V_21 ,
F_13 ( F_14 ( V_65 -> V_22 ) ) ) ;
return 0 ;
V_18:
return 1 ;
}
static int
F_46 ( struct V_23 * V_24 , const struct V_11 * V_12 ,
enum V_25 V_26 , T_1 V_27 , T_1 V_28 , T_1 V_29 )
{
const struct V_30 * V_31 = V_24 -> V_13 ;
T_2 V_32 = V_24 -> V_33 -> V_26 [ V_26 ] ;
struct V_59 V_13 = {
. V_7 = V_31 -> V_34 [ 0 ] . V_7 ? V_31 -> V_34 [ 0 ] . V_7 : V_35
} ;
if ( V_13 . V_7 == 0 )
return - V_36 ;
if ( V_26 == V_37 )
V_13 . V_7 = V_35 ;
if ( ! F_47 ( V_12 , V_29 & V_38 ,
& V_13 . V_5 , & V_13 . V_6 ) )
return - V_36 ;
F_48 ( V_12 , V_29 & V_39 , & V_13 . V_4 . V_60 ) ;
F_40 ( & V_13 . V_4 , V_13 . V_7 ) ;
return V_32 ( V_24 , & V_13 , V_31 -> V_22 ) ;
}
static int
F_49 ( struct V_23 * V_24 , struct V_40 * V_41 [] ,
enum V_25 V_26 , T_3 * V_42 , T_3 V_29 )
{
const struct V_30 * V_31 = V_24 -> V_13 ;
T_2 V_32 = V_24 -> V_33 -> V_26 [ V_26 ] ;
struct V_59 V_13 = { . V_7 = V_35 } ;
T_3 V_5 , V_43 ;
T_3 V_22 = V_31 -> V_22 ;
bool V_44 = false ;
int V_45 ;
if ( F_19 ( ! V_41 [ V_14 ] ||
! F_20 ( V_41 , V_15 ) ||
! F_21 ( V_41 , V_46 ) ||
! F_21 ( V_41 , V_21 ) ) )
return - V_47 ;
if ( V_41 [ V_48 ] )
* V_42 = F_22 ( V_41 [ V_48 ] ) ;
V_45 = F_50 ( V_41 [ V_14 ] , & V_13 . V_4 ) ;
if ( V_45 )
return V_45 ;
if ( V_41 [ V_16 ] )
V_13 . V_7 = F_24 ( V_41 [ V_16 ] ) ;
if ( ! V_13 . V_7 )
return - V_49 ;
F_40 ( & V_13 . V_4 , V_13 . V_7 ) ;
if ( V_41 [ V_15 ] )
V_13 . V_5 = F_25 ( V_41 [ V_15 ] ) ;
else
return - V_47 ;
if ( V_41 [ V_17 ] ) {
V_13 . V_6 = F_24 ( V_41 [ V_17 ] ) ;
V_44 = F_26 ( V_13 . V_6 ) ;
if ( V_13 . V_6 == 0 )
return - V_50 ;
} else
return - V_51 ;
if ( ! ( V_44 || V_13 . V_6 == V_66 ) )
V_13 . V_5 = 0 ;
if ( V_41 [ V_21 ] ) {
if ( ! F_27 ( V_31 -> V_22 ) )
return - V_53 ;
V_22 = F_28 ( V_41 [ V_21 ] ) ;
}
if ( V_26 == V_37 || ! V_44 || ! V_41 [ V_46 ] ) {
V_45 = V_32 ( V_24 , & V_13 , V_22 ) ;
return F_29 ( V_45 , V_29 ) ? 0 : V_45 ;
}
V_5 = F_30 ( V_13 . V_5 ) ;
V_43 = F_31 ( V_41 [ V_46 ] ) ;
if ( V_5 > V_43 )
F_32 ( V_5 , V_43 ) ;
for (; V_5 <= V_43 ; V_5 ++ ) {
V_13 . V_5 = F_33 ( V_5 ) ;
V_45 = V_32 ( V_24 , & V_13 , V_22 ) ;
if ( V_45 && ! F_29 ( V_45 , V_29 ) )
return V_45 ;
else
V_45 = 0 ;
}
return V_45 ;
}
static int
F_51 ( struct V_23 * V_24 , struct V_40 * V_41 [] , T_3 V_29 )
{
struct V_30 * V_31 ;
T_3 V_67 = V_68 , V_58 = V_69 ;
T_1 V_70 ;
if ( ! ( V_24 -> V_71 == V_72 || V_24 -> V_71 == V_73 ) )
return - V_74 ;
if ( F_19 ( ! F_21 ( V_41 , V_75 ) ||
! F_21 ( V_41 , V_76 ) ||
! F_21 ( V_41 , V_21 ) ) )
return - V_47 ;
if ( V_41 [ V_75 ] ) {
V_67 = F_52 ( V_41 [ V_75 ] ) ;
if ( V_67 < V_77 )
V_67 = V_77 ;
}
if ( V_41 [ V_76 ] )
V_58 = F_52 ( V_41 [ V_76 ] ) ;
V_31 = F_53 ( sizeof( * V_31 )
+ sizeof( struct V_78 )
* ( V_24 -> V_71 == V_72 ? 32 : 128 ) , V_79 ) ;
if ( ! V_31 )
return - V_80 ;
V_31 -> V_58 = V_58 ;
F_54 ( & V_31 -> V_81 , sizeof( V_31 -> V_81 ) ) ;
V_31 -> V_22 = V_82 ;
V_70 = F_55 ( V_67 ) ;
V_31 -> V_83 = F_56 (
sizeof( struct V_84 )
+ F_57 ( V_70 ) * sizeof( struct V_85 ) ) ;
if ( ! V_31 -> V_83 ) {
F_58 ( V_31 ) ;
return - V_80 ;
}
V_31 -> V_83 -> F_55 = V_70 ;
V_24 -> V_13 = V_31 ;
if ( V_41 [ V_21 ] ) {
V_31 -> V_22 = F_28 ( V_41 [ V_21 ] ) ;
V_24 -> V_33 = V_24 -> V_71 == V_72
? & V_86 : & V_87 ;
if ( V_24 -> V_71 == V_72 )
F_59 ( V_24 ) ;
else
F_60 ( V_24 ) ;
} else {
V_24 -> V_33 = V_24 -> V_71 == V_72
? & V_88 : & V_89 ;
}
F_61 ( L_1 ,
V_24 -> V_90 , F_57 ( V_31 -> V_83 -> F_55 ) ,
V_31 -> V_83 -> F_55 , V_31 -> V_58 , V_24 -> V_13 , V_31 -> V_83 ) ;
return 0 ;
}
static int T_4
F_62 ( void )
{
return F_63 ( & V_91 ) ;
}
static void T_5
F_64 ( void )
{
F_65 ( & V_91 ) ;
}
