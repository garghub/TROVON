static inline bool
F_1 ( const struct V_1 * V_2 ,
const struct V_1 * V_3 ,
T_1 * V_4 )
{
return V_2 -> V_5 == V_3 -> V_5 && V_2 -> V_6 == V_3 -> V_6 ;
}
static inline bool
F_2 ( const struct V_1 * V_7 )
{
return V_7 -> V_6 == 0 ;
}
static inline void
F_3 ( struct V_1 * V_8 ,
const struct V_1 * V_9 )
{
V_8 -> V_5 = V_9 -> V_5 ;
V_8 -> V_6 = V_9 -> V_6 ;
}
static inline void
F_4 ( struct V_1 * V_7 , T_2 V_6 )
{
V_7 -> V_5 &= F_5 ( V_6 ) ;
V_7 -> V_6 = V_6 ;
}
static inline void
F_6 ( struct V_1 * V_7 )
{
V_7 -> V_6 = 0 ;
}
static bool
F_7 ( struct V_10 * V_11 , const struct V_1 * V_12 )
{
F_8 ( V_11 , V_13 , V_12 -> V_5 ) ;
F_9 ( V_11 , V_14 , V_12 -> V_6 ) ;
return 0 ;
V_15:
return 1 ;
}
static bool
F_10 ( struct V_10 * V_11 , const struct V_1 * V_12 )
{
const struct V_16 * V_17 =
( const struct V_16 * ) V_12 ;
F_8 ( V_11 , V_13 , V_17 -> V_5 ) ;
F_9 ( V_11 , V_14 , V_17 -> V_6 ) ;
F_11 ( V_11 , V_18 ,
F_12 ( F_13 ( V_17 -> V_19 ) ) ) ;
return 0 ;
V_15:
return 1 ;
}
static inline void
F_14 ( struct V_20 * V_21 ,
const struct V_1 * V_22 )
{
V_21 -> V_23 . V_5 = F_15 ( V_22 -> V_5 ) ;
}
static int
F_16 ( struct V_24 * V_25 , const struct V_10 * V_11 ,
const struct V_26 * V_27 ,
enum V_28 V_29 , const struct V_30 * V_31 )
{
const struct V_20 * V_21 = V_25 -> V_12 ;
T_3 V_32 = V_25 -> V_33 -> V_29 [ V_29 ] ;
struct V_1 V_12 = {
. V_6 = V_21 -> V_34 [ 0 ] . V_6 ? V_21 -> V_34 [ 0 ] . V_6 : V_35
} ;
if ( V_12 . V_6 == 0 )
return - V_36 ;
if ( V_29 == V_37 )
V_12 . V_6 = V_35 ;
F_17 ( V_11 , V_31 -> V_38 & V_39 , & V_12 . V_5 ) ;
V_12 . V_5 &= F_5 ( V_12 . V_6 ) ;
return V_32 ( V_25 , & V_12 , F_18 ( V_31 , V_21 ) , V_31 -> V_40 ) ;
}
static int
F_19 ( struct V_24 * V_25 , struct V_41 * V_42 [] ,
enum V_28 V_29 , T_1 * V_43 , T_1 V_38 , bool V_44 )
{
const struct V_20 * V_21 = V_25 -> V_12 ;
T_3 V_32 = V_25 -> V_33 -> V_29 [ V_29 ] ;
struct V_1 V_12 = { . V_6 = V_35 } ;
T_1 V_19 = V_21 -> V_19 ;
T_1 V_5 = 0 , V_45 , V_46 ;
int V_47 ;
if ( F_20 ( ! V_42 [ V_13 ] ||
! F_21 ( V_42 , V_18 ) ) )
return - V_48 ;
if ( V_42 [ V_49 ] )
* V_43 = F_22 ( V_42 [ V_49 ] ) ;
V_47 = F_23 ( V_42 [ V_13 ] , & V_5 ) ;
if ( V_47 )
return V_47 ;
if ( V_42 [ V_14 ] ) {
V_12 . V_6 = F_24 ( V_42 [ V_14 ] ) ;
if ( ! V_12 . V_6 )
return - V_50 ;
}
if ( V_42 [ V_18 ] ) {
if ( ! F_25 ( V_21 -> V_19 ) )
return - V_51 ;
V_19 = F_26 ( V_42 [ V_18 ] ) ;
}
if ( V_29 == V_37 || ! V_42 [ V_52 ] ) {
V_12 . V_5 = F_12 ( V_5 & F_27 ( V_12 . V_6 ) ) ;
V_47 = V_32 ( V_25 , & V_12 , V_19 , V_38 ) ;
return F_28 ( V_47 , V_38 ) ? 0 : V_47 ;
}
V_45 = V_5 ;
if ( V_42 [ V_52 ] ) {
V_47 = F_23 ( V_42 [ V_52 ] , & V_45 ) ;
if ( V_47 )
return V_47 ;
if ( V_45 < V_5 )
F_29 ( V_5 , V_45 ) ;
if ( V_5 + V_53 == V_45 )
return - V_54 ;
}
if ( V_44 )
V_5 = V_21 -> V_23 . V_5 ;
while ( ! F_30 ( V_5 , V_45 ) ) {
V_12 . V_5 = F_12 ( V_5 ) ;
V_46 = F_31 ( V_5 , V_45 , & V_12 . V_6 ) ;
V_47 = V_32 ( V_25 , & V_12 , V_19 , V_38 ) ;
if ( V_47 && ! F_28 ( V_47 , V_38 ) )
return V_47 ;
else
V_47 = 0 ;
V_5 = V_46 + 1 ;
}
return V_47 ;
}
static bool
F_32 ( const struct V_24 * V_55 , const struct V_24 * V_56 )
{
const struct V_20 * V_57 = V_55 -> V_12 ;
const struct V_20 * V_58 = V_56 -> V_12 ;
return V_57 -> V_59 == V_58 -> V_59 &&
V_57 -> V_19 == V_58 -> V_19 ;
}
static inline bool
F_33 ( const struct V_60 * V_2 ,
const struct V_60 * V_3 ,
T_1 * V_4 )
{
return F_34 ( & V_2 -> V_5 . V_61 , & V_3 -> V_5 . V_61 ) == 0 &&
V_2 -> V_6 == V_3 -> V_6 ;
}
static inline bool
F_35 ( const struct V_60 * V_7 )
{
return V_7 -> V_6 == 0 ;
}
static inline void
F_36 ( struct V_60 * V_8 ,
const struct V_60 * V_9 )
{
V_8 -> V_5 . V_61 = V_9 -> V_5 . V_61 ;
V_8 -> V_6 = V_9 -> V_6 ;
}
static inline void
F_37 ( struct V_60 * V_7 )
{
V_7 -> V_6 = 0 ;
}
static inline void
F_38 ( union V_62 * V_5 , T_2 V_63 )
{
V_5 -> V_64 [ 0 ] &= F_39 ( V_63 ) [ 0 ] ;
V_5 -> V_64 [ 1 ] &= F_39 ( V_63 ) [ 1 ] ;
V_5 -> V_64 [ 2 ] &= F_39 ( V_63 ) [ 2 ] ;
V_5 -> V_64 [ 3 ] &= F_39 ( V_63 ) [ 3 ] ;
}
static inline void
F_40 ( struct V_60 * V_7 , T_2 V_6 )
{
F_38 ( & V_7 -> V_5 , V_6 ) ;
V_7 -> V_6 = V_6 ;
}
static bool
F_41 ( struct V_10 * V_11 , const struct V_60 * V_12 )
{
F_42 ( V_11 , V_13 , & V_12 -> V_5 ) ;
F_9 ( V_11 , V_14 , V_12 -> V_6 ) ;
return 0 ;
V_15:
return 1 ;
}
static bool
F_43 ( struct V_10 * V_11 , const struct V_60 * V_12 )
{
const struct V_65 * V_66 =
( const struct V_65 * ) V_12 ;
F_42 ( V_11 , V_13 , & V_66 -> V_5 ) ;
F_9 ( V_11 , V_14 , V_66 -> V_6 ) ;
F_11 ( V_11 , V_18 ,
F_12 ( F_13 ( V_66 -> V_19 ) ) ) ;
return 0 ;
V_15:
return 1 ;
}
static inline void
F_44 ( struct V_20 * V_21 ,
const struct V_60 * V_22 )
{
}
static int
F_45 ( struct V_24 * V_25 , const struct V_10 * V_11 ,
const struct V_26 * V_27 ,
enum V_28 V_29 , const struct V_30 * V_31 )
{
const struct V_20 * V_21 = V_25 -> V_12 ;
T_3 V_32 = V_25 -> V_33 -> V_29 [ V_29 ] ;
struct V_60 V_12 = {
. V_6 = V_21 -> V_34 [ 0 ] . V_6 ? V_21 -> V_34 [ 0 ] . V_6 : V_35
} ;
if ( V_12 . V_6 == 0 )
return - V_36 ;
if ( V_29 == V_37 )
V_12 . V_6 = V_35 ;
F_46 ( V_11 , V_31 -> V_38 & V_39 , & V_12 . V_5 . V_61 ) ;
F_38 ( & V_12 . V_5 , V_12 . V_6 ) ;
return V_32 ( V_25 , & V_12 , F_18 ( V_31 , V_21 ) , V_31 -> V_40 ) ;
}
static int
F_47 ( struct V_24 * V_25 , struct V_41 * V_42 [] ,
enum V_28 V_29 , T_1 * V_43 , T_1 V_38 , bool V_44 )
{
const struct V_20 * V_21 = V_25 -> V_12 ;
T_3 V_32 = V_25 -> V_33 -> V_29 [ V_29 ] ;
struct V_60 V_12 = { . V_6 = V_35 } ;
T_1 V_19 = V_21 -> V_19 ;
int V_47 ;
if ( F_20 ( ! V_42 [ V_13 ] ||
! F_21 ( V_42 , V_18 ) ) )
return - V_48 ;
if ( F_20 ( V_42 [ V_52 ] ) )
return - V_67 ;
if ( V_42 [ V_49 ] )
* V_43 = F_22 ( V_42 [ V_49 ] ) ;
V_47 = F_48 ( V_42 [ V_13 ] , & V_12 . V_5 ) ;
if ( V_47 )
return V_47 ;
if ( V_42 [ V_14 ] )
V_12 . V_6 = F_24 ( V_42 [ V_14 ] ) ;
if ( ! V_12 . V_6 )
return - V_50 ;
F_38 ( & V_12 . V_5 , V_12 . V_6 ) ;
if ( V_42 [ V_18 ] ) {
if ( ! F_25 ( V_21 -> V_19 ) )
return - V_51 ;
V_19 = F_26 ( V_42 [ V_18 ] ) ;
}
V_47 = V_32 ( V_25 , & V_12 , V_19 , V_38 ) ;
return F_28 ( V_47 , V_38 ) ? 0 : V_47 ;
}
static int
F_49 ( struct V_24 * V_25 , struct V_41 * V_42 [] , T_1 V_38 )
{
T_1 V_68 = V_69 , V_59 = V_70 ;
struct V_20 * V_21 ;
T_2 V_71 ;
if ( ! ( V_25 -> V_72 == V_73 || V_25 -> V_72 == V_74 ) )
return - V_75 ;
if ( F_20 ( ! F_21 ( V_42 , V_76 ) ||
! F_21 ( V_42 , V_77 ) ||
! F_21 ( V_42 , V_18 ) ) )
return - V_48 ;
if ( V_42 [ V_76 ] ) {
V_68 = F_50 ( V_42 [ V_76 ] ) ;
if ( V_68 < V_78 )
V_68 = V_78 ;
}
if ( V_42 [ V_77 ] )
V_59 = F_50 ( V_42 [ V_77 ] ) ;
V_21 = F_51 ( sizeof( * V_21 )
+ sizeof( struct V_79 )
* ( V_25 -> V_72 == V_73 ? 32 : 128 ) , V_80 ) ;
if ( ! V_21 )
return - V_81 ;
V_21 -> V_59 = V_59 ;
F_52 ( & V_21 -> V_82 , sizeof( V_21 -> V_82 ) ) ;
V_21 -> V_19 = V_83 ;
V_71 = F_53 ( V_68 ) ;
V_21 -> V_84 = F_54 (
sizeof( struct V_85 )
+ F_55 ( V_71 ) * sizeof( struct V_86 ) ) ;
if ( ! V_21 -> V_84 ) {
F_56 ( V_21 ) ;
return - V_81 ;
}
V_21 -> V_84 -> F_53 = V_71 ;
V_25 -> V_12 = V_21 ;
if ( V_42 [ V_18 ] ) {
V_21 -> V_19 = F_26 ( V_42 [ V_18 ] ) ;
V_25 -> V_33 = V_25 -> V_72 == V_73
? & V_87 : & V_88 ;
if ( V_25 -> V_72 == V_73 )
F_57 ( V_25 ) ;
else
F_58 ( V_25 ) ;
} else {
V_25 -> V_33 = V_25 -> V_72 == V_73
? & V_89 : & V_90 ;
}
F_59 ( L_1 ,
V_25 -> V_91 , F_55 ( V_21 -> V_84 -> F_53 ) ,
V_21 -> V_84 -> F_53 , V_21 -> V_59 , V_25 -> V_12 , V_21 -> V_84 ) ;
return 0 ;
}
static int T_4
F_60 ( void )
{
return F_61 ( & V_92 ) ;
}
static void T_5
F_62 ( void )
{
F_63 ( & V_92 ) ;
}
