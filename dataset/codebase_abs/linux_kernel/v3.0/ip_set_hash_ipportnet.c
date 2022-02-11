static inline bool
F_1 ( const struct V_1 * V_2 ,
const struct V_1 * V_3 )
{
return V_2 -> V_4 == V_3 -> V_4 &&
V_2 -> V_3 == V_3 -> V_3 &&
V_2 -> V_5 == V_3 -> V_5 &&
V_2 -> V_6 == V_3 -> V_6 &&
V_2 -> V_7 == V_3 -> V_7 ;
}
static inline bool
F_2 ( const struct V_1 * V_8 )
{
return V_8 -> V_7 == 0 ;
}
static inline void
F_3 ( struct V_1 * V_9 ,
const struct V_1 * V_10 )
{
memcpy ( V_9 , V_10 , sizeof( * V_9 ) ) ;
}
static inline void
F_4 ( struct V_1 * V_8 , T_1 V_5 )
{
V_8 -> V_3 &= F_5 ( V_5 ) ;
V_8 -> V_5 = V_5 ;
}
static inline void
F_6 ( struct V_1 * V_8 )
{
V_8 -> V_7 = 0 ;
}
static bool
F_7 ( struct V_11 * V_12 ,
const struct V_1 * V_13 )
{
F_8 ( V_12 , V_14 , V_13 -> V_4 ) ;
F_8 ( V_12 , V_15 , V_13 -> V_3 ) ;
F_9 ( V_12 , V_16 , V_13 -> V_6 ) ;
F_10 ( V_12 , V_17 , V_13 -> V_5 ) ;
F_10 ( V_12 , V_18 , V_13 -> V_7 ) ;
return 0 ;
V_19:
return 1 ;
}
static bool
F_11 ( struct V_11 * V_12 ,
const struct V_1 * V_13 )
{
const struct V_20 * V_21 =
( const struct V_20 * ) V_13 ;
F_8 ( V_12 , V_14 , V_21 -> V_4 ) ;
F_8 ( V_12 , V_15 , V_21 -> V_3 ) ;
F_9 ( V_12 , V_16 , V_21 -> V_6 ) ;
F_10 ( V_12 , V_17 , V_13 -> V_5 ) ;
F_10 ( V_12 , V_18 , V_13 -> V_7 ) ;
F_12 ( V_12 , V_22 ,
F_13 ( F_14 ( V_21 -> V_23 ) ) ) ;
return 0 ;
V_19:
return 1 ;
}
static int
F_15 ( struct V_24 * V_25 , const struct V_11 * V_12 ,
enum V_26 V_27 , T_1 V_28 , T_1 V_29 , T_1 V_30 )
{
const struct V_31 * V_32 = V_25 -> V_13 ;
T_2 V_33 = V_25 -> V_34 -> V_27 [ V_27 ] ;
struct V_1 V_13 = {
. V_5 = V_32 -> V_35 [ 0 ] . V_5 ? V_32 -> V_35 [ 0 ] . V_5 : V_36
} ;
if ( V_13 . V_5 == 0 )
return - V_37 ;
if ( V_27 == V_38 )
V_13 . V_5 = V_36 ;
if ( ! F_16 ( V_12 , V_30 & V_39 ,
& V_13 . V_6 , & V_13 . V_7 ) )
return - V_37 ;
F_17 ( V_12 , V_30 & V_40 , & V_13 . V_4 ) ;
F_17 ( V_12 , V_30 & V_41 , & V_13 . V_3 ) ;
V_13 . V_3 &= F_5 ( V_13 . V_5 ) ;
return V_33 ( V_25 , & V_13 , V_32 -> V_23 ) ;
}
static int
F_18 ( struct V_24 * V_25 , struct V_42 * V_43 [] ,
enum V_26 V_27 , T_3 * V_44 , T_3 V_30 )
{
const struct V_31 * V_32 = V_25 -> V_13 ;
T_2 V_33 = V_25 -> V_34 -> V_27 [ V_27 ] ;
struct V_1 V_13 = { . V_5 = V_36 } ;
T_3 V_4 , V_45 , V_46 , V_6 , V_47 ;
T_3 V_23 = V_32 -> V_23 ;
bool V_48 = false ;
int V_49 ;
if ( F_19 ( ! V_43 [ V_14 ] || ! V_43 [ V_15 ] ||
! F_20 ( V_43 , V_16 ) ||
! F_21 ( V_43 , V_50 ) ||
! F_21 ( V_43 , V_22 ) ) )
return - V_51 ;
if ( V_43 [ V_52 ] )
* V_44 = F_22 ( V_43 [ V_52 ] ) ;
V_49 = F_23 ( V_43 [ V_14 ] , & V_13 . V_4 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_23 ( V_43 [ V_15 ] , & V_13 . V_3 ) ;
if ( V_49 )
return V_49 ;
if ( V_43 [ V_17 ] )
V_13 . V_5 = F_24 ( V_43 [ V_17 ] ) ;
if ( ! V_13 . V_5 )
return - V_53 ;
V_13 . V_3 &= F_5 ( V_13 . V_5 ) ;
if ( V_43 [ V_16 ] )
V_13 . V_6 = F_25 ( V_43 [ V_16 ] ) ;
else
return - V_51 ;
if ( V_43 [ V_18 ] ) {
V_13 . V_7 = F_24 ( V_43 [ V_18 ] ) ;
V_48 = F_26 ( V_13 . V_7 ) ;
if ( V_13 . V_7 == 0 )
return - V_54 ;
} else
return - V_55 ;
if ( ! ( V_48 || V_13 . V_7 == V_56 ) )
V_13 . V_6 = 0 ;
if ( V_43 [ V_22 ] ) {
if ( ! F_27 ( V_32 -> V_23 ) )
return - V_57 ;
V_23 = F_28 ( V_43 [ V_22 ] ) ;
}
if ( V_27 == V_38 ||
! ( V_43 [ V_58 ] || V_43 [ V_59 ] ||
V_43 [ V_50 ] ) ) {
V_49 = V_33 ( V_25 , & V_13 , V_23 ) ;
return F_29 ( V_49 , V_30 ) ? 0 : V_49 ;
}
V_4 = F_30 ( V_13 . V_4 ) ;
if ( V_43 [ V_58 ] ) {
V_49 = F_31 ( V_43 [ V_58 ] , & V_45 ) ;
if ( V_49 )
return V_49 ;
if ( V_4 > V_45 )
F_32 ( V_4 , V_45 ) ;
} else if ( V_43 [ V_59 ] ) {
T_1 V_5 = F_24 ( V_43 [ V_59 ] ) ;
if ( V_5 > 32 )
return - V_53 ;
V_4 &= F_33 ( V_5 ) ;
V_45 = V_4 | ~ F_33 ( V_5 ) ;
} else
V_45 = V_4 ;
V_47 = V_6 = F_34 ( V_13 . V_6 ) ;
if ( V_48 && V_43 [ V_50 ] ) {
V_47 = F_35 ( V_43 [ V_50 ] ) ;
if ( V_6 > V_47 )
F_32 ( V_6 , V_47 ) ;
}
for (; ! F_36 ( V_45 , V_4 ) ; V_4 ++ )
for ( V_46 = V_6 ; V_46 <= V_47 ; V_46 ++ ) {
V_13 . V_4 = F_13 ( V_4 ) ;
V_13 . V_6 = F_37 ( V_46 ) ;
V_49 = V_33 ( V_25 , & V_13 , V_23 ) ;
if ( V_49 && ! F_29 ( V_49 , V_30 ) )
return V_49 ;
else
V_49 = 0 ;
}
return V_49 ;
}
static bool
F_38 ( const struct V_24 * V_60 , const struct V_24 * V_61 )
{
const struct V_31 * V_62 = V_60 -> V_13 ;
const struct V_31 * V_63 = V_61 -> V_13 ;
return V_62 -> V_64 == V_63 -> V_64 &&
V_62 -> V_23 == V_63 -> V_23 ;
}
static inline bool
F_39 ( const struct V_65 * V_2 ,
const struct V_65 * V_3 )
{
return F_40 ( & V_2 -> V_4 . V_66 , & V_3 -> V_4 . V_66 ) == 0 &&
F_40 ( & V_2 -> V_3 . V_66 , & V_3 -> V_3 . V_66 ) == 0 &&
V_2 -> V_5 == V_3 -> V_5 &&
V_2 -> V_6 == V_3 -> V_6 &&
V_2 -> V_7 == V_3 -> V_7 ;
}
static inline bool
F_41 ( const struct V_65 * V_8 )
{
return V_8 -> V_7 == 0 ;
}
static inline void
F_42 ( struct V_65 * V_9 ,
const struct V_65 * V_10 )
{
memcpy ( V_9 , V_10 , sizeof( * V_9 ) ) ;
}
static inline void
F_43 ( struct V_65 * V_8 )
{
V_8 -> V_7 = 0 ;
}
static inline void
F_44 ( union V_67 * V_4 , T_1 V_68 )
{
V_4 -> V_69 [ 0 ] &= F_45 ( V_68 ) [ 0 ] ;
V_4 -> V_69 [ 1 ] &= F_45 ( V_68 ) [ 1 ] ;
V_4 -> V_69 [ 2 ] &= F_45 ( V_68 ) [ 2 ] ;
V_4 -> V_69 [ 3 ] &= F_45 ( V_68 ) [ 3 ] ;
}
static inline void
F_46 ( struct V_65 * V_8 , T_1 V_5 )
{
F_44 ( & V_8 -> V_3 , V_5 ) ;
V_8 -> V_5 = V_5 ;
}
static bool
F_47 ( struct V_11 * V_12 ,
const struct V_65 * V_13 )
{
F_48 ( V_12 , V_14 , & V_13 -> V_4 ) ;
F_48 ( V_12 , V_15 , & V_13 -> V_3 ) ;
F_9 ( V_12 , V_16 , V_13 -> V_6 ) ;
F_10 ( V_12 , V_17 , V_13 -> V_5 ) ;
F_10 ( V_12 , V_18 , V_13 -> V_7 ) ;
return 0 ;
V_19:
return 1 ;
}
static bool
F_49 ( struct V_11 * V_12 ,
const struct V_65 * V_13 )
{
const struct V_70 * V_71 =
( const struct V_70 * ) V_13 ;
F_48 ( V_12 , V_14 , & V_71 -> V_4 ) ;
F_48 ( V_12 , V_15 , & V_13 -> V_3 ) ;
F_9 ( V_12 , V_16 , V_13 -> V_6 ) ;
F_10 ( V_12 , V_17 , V_13 -> V_5 ) ;
F_10 ( V_12 , V_18 , V_13 -> V_7 ) ;
F_12 ( V_12 , V_22 ,
F_13 ( F_14 ( V_71 -> V_23 ) ) ) ;
return 0 ;
V_19:
return 1 ;
}
static int
F_50 ( struct V_24 * V_25 , const struct V_11 * V_12 ,
enum V_26 V_27 , T_1 V_28 , T_1 V_29 , T_1 V_30 )
{
const struct V_31 * V_32 = V_25 -> V_13 ;
T_2 V_33 = V_25 -> V_34 -> V_27 [ V_27 ] ;
struct V_65 V_13 = {
. V_5 = V_32 -> V_35 [ 0 ] . V_5 ? V_32 -> V_35 [ 0 ] . V_5 : V_36
} ;
if ( V_13 . V_5 == 0 )
return - V_37 ;
if ( V_27 == V_38 )
V_13 . V_5 = V_36 ;
if ( ! F_51 ( V_12 , V_30 & V_39 ,
& V_13 . V_6 , & V_13 . V_7 ) )
return - V_37 ;
F_52 ( V_12 , V_30 & V_40 , & V_13 . V_4 . V_66 ) ;
F_52 ( V_12 , V_30 & V_41 , & V_13 . V_3 . V_66 ) ;
F_44 ( & V_13 . V_3 , V_13 . V_5 ) ;
return V_33 ( V_25 , & V_13 , V_32 -> V_23 ) ;
}
static int
F_53 ( struct V_24 * V_25 , struct V_42 * V_43 [] ,
enum V_26 V_27 , T_3 * V_44 , T_3 V_30 )
{
const struct V_31 * V_32 = V_25 -> V_13 ;
T_2 V_33 = V_25 -> V_34 -> V_27 [ V_27 ] ;
struct V_65 V_13 = { . V_5 = V_36 } ;
T_3 V_6 , V_47 ;
T_3 V_23 = V_32 -> V_23 ;
bool V_48 = false ;
int V_49 ;
if ( F_19 ( ! V_43 [ V_14 ] || ! V_43 [ V_15 ] ||
! F_20 ( V_43 , V_16 ) ||
! F_21 ( V_43 , V_50 ) ||
! F_21 ( V_43 , V_22 ) ||
V_43 [ V_58 ] ||
V_43 [ V_59 ] ) )
return - V_51 ;
if ( V_43 [ V_52 ] )
* V_44 = F_22 ( V_43 [ V_52 ] ) ;
V_49 = F_54 ( V_43 [ V_14 ] , & V_13 . V_4 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_54 ( V_43 [ V_15 ] , & V_13 . V_3 ) ;
if ( V_49 )
return V_49 ;
if ( V_43 [ V_17 ] )
V_13 . V_5 = F_24 ( V_43 [ V_17 ] ) ;
if ( ! V_13 . V_5 )
return - V_53 ;
F_44 ( & V_13 . V_3 , V_13 . V_5 ) ;
if ( V_43 [ V_16 ] )
V_13 . V_6 = F_25 ( V_43 [ V_16 ] ) ;
else
return - V_51 ;
if ( V_43 [ V_18 ] ) {
V_13 . V_7 = F_24 ( V_43 [ V_18 ] ) ;
V_48 = F_26 ( V_13 . V_7 ) ;
if ( V_13 . V_7 == 0 )
return - V_54 ;
} else
return - V_55 ;
if ( ! ( V_48 || V_13 . V_7 == V_72 ) )
V_13 . V_6 = 0 ;
if ( V_43 [ V_22 ] ) {
if ( ! F_27 ( V_32 -> V_23 ) )
return - V_57 ;
V_23 = F_28 ( V_43 [ V_22 ] ) ;
}
if ( V_27 == V_38 || ! V_48 || ! V_43 [ V_50 ] ) {
V_49 = V_33 ( V_25 , & V_13 , V_23 ) ;
return F_29 ( V_49 , V_30 ) ? 0 : V_49 ;
}
V_6 = F_34 ( V_13 . V_6 ) ;
V_47 = F_35 ( V_43 [ V_50 ] ) ;
if ( V_6 > V_47 )
F_32 ( V_6 , V_47 ) ;
for (; V_6 <= V_47 ; V_6 ++ ) {
V_13 . V_6 = F_37 ( V_6 ) ;
V_49 = V_33 ( V_25 , & V_13 , V_23 ) ;
if ( V_49 && ! F_29 ( V_49 , V_30 ) )
return V_49 ;
else
V_49 = 0 ;
}
return V_49 ;
}
static int
F_55 ( struct V_24 * V_25 , struct V_42 * V_43 [] , T_3 V_30 )
{
struct V_31 * V_32 ;
T_3 V_73 = V_74 , V_64 = V_75 ;
T_1 V_76 ;
if ( ! ( V_25 -> V_77 == V_78 || V_25 -> V_77 == V_79 ) )
return - V_80 ;
if ( F_19 ( ! F_21 ( V_43 , V_81 ) ||
! F_21 ( V_43 , V_82 ) ||
! F_21 ( V_43 , V_22 ) ) )
return - V_51 ;
if ( V_43 [ V_81 ] ) {
V_73 = F_56 ( V_43 [ V_81 ] ) ;
if ( V_73 < V_83 )
V_73 = V_83 ;
}
if ( V_43 [ V_82 ] )
V_64 = F_56 ( V_43 [ V_82 ] ) ;
V_32 = F_57 ( sizeof( * V_32 )
+ sizeof( struct V_84 )
* ( V_25 -> V_77 == V_78 ? 32 : 128 ) , V_85 ) ;
if ( ! V_32 )
return - V_86 ;
V_32 -> V_64 = V_64 ;
F_58 ( & V_32 -> V_87 , sizeof( V_32 -> V_87 ) ) ;
V_32 -> V_23 = V_88 ;
V_76 = F_59 ( V_73 ) ;
V_32 -> V_89 = F_60 (
sizeof( struct V_90 )
+ F_61 ( V_76 ) * sizeof( struct V_91 ) ) ;
if ( ! V_32 -> V_89 ) {
F_62 ( V_32 ) ;
return - V_86 ;
}
V_32 -> V_89 -> F_59 = V_76 ;
V_25 -> V_13 = V_32 ;
if ( V_43 [ V_22 ] ) {
V_32 -> V_23 = F_28 ( V_43 [ V_22 ] ) ;
V_25 -> V_34 = V_25 -> V_77 == V_78
? & V_92
: & V_93 ;
if ( V_25 -> V_77 == V_78 )
F_63 ( V_25 ) ;
else
F_64 ( V_25 ) ;
} else {
V_25 -> V_34 = V_25 -> V_77 == V_78
? & V_94 : & V_95 ;
}
F_65 ( L_1 ,
V_25 -> V_96 , F_61 ( V_32 -> V_89 -> F_59 ) ,
V_32 -> V_89 -> F_59 , V_32 -> V_64 , V_25 -> V_13 , V_32 -> V_89 ) ;
return 0 ;
}
static int T_4
F_66 ( void )
{
return F_67 ( & V_97 ) ;
}
static void T_5
F_68 ( void )
{
F_69 ( & V_97 ) ;
}
