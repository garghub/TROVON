static inline bool
F_1 ( const struct V_1 * V_2 ,
const struct V_1 * V_3 )
{
return V_2 -> V_4 == V_3 -> V_4 &&
V_2 -> V_3 == V_3 -> V_3 &&
V_2 -> V_5 == V_3 -> V_5 &&
V_2 -> V_6 == V_3 -> V_6 ;
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
memcpy ( V_8 , V_9 , sizeof( * V_8 ) ) ;
}
static inline void
F_4 ( struct V_1 * V_7 )
{
V_7 -> V_6 = 0 ;
}
static bool
F_5 ( struct V_10 * V_11 ,
const struct V_1 * V_12 )
{
F_6 ( V_11 , V_13 , V_12 -> V_4 ) ;
F_6 ( V_11 , V_14 , V_12 -> V_3 ) ;
F_7 ( V_11 , V_15 , V_12 -> V_5 ) ;
F_8 ( V_11 , V_16 , V_12 -> V_6 ) ;
return 0 ;
V_17:
return 1 ;
}
static bool
F_9 ( struct V_10 * V_11 ,
const struct V_1 * V_12 )
{
const struct V_18 * V_19 =
( const struct V_18 * ) V_12 ;
F_6 ( V_11 , V_13 , V_19 -> V_4 ) ;
F_6 ( V_11 , V_14 , V_19 -> V_3 ) ;
F_7 ( V_11 , V_15 , V_19 -> V_5 ) ;
F_8 ( V_11 , V_16 , V_12 -> V_6 ) ;
F_10 ( V_11 , V_20 ,
F_11 ( F_12 ( V_19 -> V_21 ) ) ) ;
return 0 ;
V_17:
return 1 ;
}
static int
F_13 ( struct V_22 * V_23 , const struct V_10 * V_11 ,
enum V_24 V_25 , T_1 V_26 , T_1 V_27 , T_1 V_28 )
{
const struct V_29 * V_30 = V_23 -> V_12 ;
T_2 V_31 = V_23 -> V_32 -> V_25 [ V_25 ] ;
struct V_1 V_12 = { } ;
if ( ! F_14 ( V_11 , V_28 & V_33 ,
& V_12 . V_5 , & V_12 . V_6 ) )
return - V_34 ;
F_15 ( V_11 , V_28 & V_35 , & V_12 . V_4 ) ;
F_15 ( V_11 , V_28 & V_36 , & V_12 . V_3 ) ;
return V_31 ( V_23 , & V_12 , V_30 -> V_21 ) ;
}
static int
F_16 ( struct V_22 * V_23 , struct V_37 * V_38 [] ,
enum V_24 V_25 , T_3 * V_39 , T_3 V_28 )
{
const struct V_29 * V_30 = V_23 -> V_12 ;
T_2 V_31 = V_23 -> V_32 -> V_25 [ V_25 ] ;
struct V_1 V_12 = { } ;
T_3 V_4 , V_40 , V_41 , V_5 , V_42 ;
T_3 V_21 = V_30 -> V_21 ;
bool V_43 = false ;
int V_44 ;
if ( F_17 ( ! V_38 [ V_13 ] || ! V_38 [ V_14 ] ||
! F_18 ( V_38 , V_15 ) ||
! F_19 ( V_38 , V_45 ) ||
! F_19 ( V_38 , V_20 ) ) )
return - V_46 ;
if ( V_38 [ V_47 ] )
* V_39 = F_20 ( V_38 [ V_47 ] ) ;
V_44 = F_21 ( V_38 [ V_13 ] , & V_12 . V_4 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_21 ( V_38 [ V_14 ] , & V_12 . V_3 ) ;
if ( V_44 )
return V_44 ;
if ( V_38 [ V_15 ] )
V_12 . V_5 = F_22 ( V_38 [ V_15 ] ) ;
else
return - V_46 ;
if ( V_38 [ V_16 ] ) {
V_12 . V_6 = F_23 ( V_38 [ V_16 ] ) ;
V_43 = F_24 ( V_12 . V_6 ) ;
if ( V_12 . V_6 == 0 )
return - V_48 ;
} else
return - V_49 ;
if ( ! ( V_43 || V_12 . V_6 == V_50 ) )
V_12 . V_5 = 0 ;
if ( V_38 [ V_20 ] ) {
if ( ! F_25 ( V_30 -> V_21 ) )
return - V_51 ;
V_21 = F_26 ( V_38 [ V_20 ] ) ;
}
if ( V_25 == V_52 ||
! ( V_38 [ V_53 ] || V_38 [ V_54 ] ||
V_38 [ V_45 ] ) ) {
V_44 = V_31 ( V_23 , & V_12 , V_21 ) ;
return F_27 ( V_44 , V_28 ) ? 0 : V_44 ;
}
V_4 = F_28 ( V_12 . V_4 ) ;
if ( V_38 [ V_53 ] ) {
V_44 = F_29 ( V_38 [ V_53 ] , & V_40 ) ;
if ( V_44 )
return V_44 ;
if ( V_4 > V_40 )
F_30 ( V_4 , V_40 ) ;
} else if ( V_38 [ V_54 ] ) {
T_1 V_55 = F_23 ( V_38 [ V_54 ] ) ;
if ( V_55 > 32 )
return - V_56 ;
V_4 &= F_31 ( V_55 ) ;
V_40 = V_4 | ~ F_31 ( V_55 ) ;
} else
V_40 = V_4 ;
V_42 = V_5 = F_32 ( V_12 . V_5 ) ;
if ( V_43 && V_38 [ V_45 ] ) {
V_42 = F_33 ( V_38 [ V_45 ] ) ;
if ( V_5 > V_42 )
F_30 ( V_5 , V_42 ) ;
}
for (; ! F_34 ( V_40 , V_4 ) ; V_4 ++ )
for ( V_41 = V_5 ; V_41 <= V_42 ; V_41 ++ ) {
V_12 . V_4 = F_11 ( V_4 ) ;
V_12 . V_5 = F_35 ( V_41 ) ;
V_44 = V_31 ( V_23 , & V_12 , V_21 ) ;
if ( V_44 && ! F_27 ( V_44 , V_28 ) )
return V_44 ;
else
V_44 = 0 ;
}
return V_44 ;
}
static bool
F_36 ( const struct V_22 * V_57 , const struct V_22 * V_58 )
{
const struct V_29 * V_59 = V_57 -> V_12 ;
const struct V_29 * V_60 = V_58 -> V_12 ;
return V_59 -> V_61 == V_60 -> V_61 &&
V_59 -> V_21 == V_60 -> V_21 ;
}
static inline bool
F_37 ( const struct V_62 * V_2 ,
const struct V_62 * V_3 )
{
return F_38 ( & V_2 -> V_4 . V_63 , & V_3 -> V_4 . V_63 ) == 0 &&
F_38 ( & V_2 -> V_3 . V_63 , & V_3 -> V_3 . V_63 ) == 0 &&
V_2 -> V_5 == V_3 -> V_5 &&
V_2 -> V_6 == V_3 -> V_6 ;
}
static inline bool
F_39 ( const struct V_62 * V_7 )
{
return V_7 -> V_6 == 0 ;
}
static inline void
F_40 ( struct V_62 * V_8 ,
const struct V_62 * V_9 )
{
memcpy ( V_8 , V_9 , sizeof( * V_8 ) ) ;
}
static inline void
F_41 ( struct V_62 * V_7 )
{
V_7 -> V_6 = 0 ;
}
static bool
F_42 ( struct V_10 * V_11 ,
const struct V_62 * V_12 )
{
F_43 ( V_11 , V_13 , & V_12 -> V_4 ) ;
F_43 ( V_11 , V_14 , & V_12 -> V_3 ) ;
F_7 ( V_11 , V_15 , V_12 -> V_5 ) ;
F_8 ( V_11 , V_16 , V_12 -> V_6 ) ;
return 0 ;
V_17:
return 1 ;
}
static bool
F_44 ( struct V_10 * V_11 ,
const struct V_62 * V_12 )
{
const struct V_64 * V_65 =
( const struct V_64 * ) V_12 ;
F_43 ( V_11 , V_13 , & V_65 -> V_4 ) ;
F_43 ( V_11 , V_14 , & V_12 -> V_3 ) ;
F_7 ( V_11 , V_15 , V_12 -> V_5 ) ;
F_8 ( V_11 , V_16 , V_12 -> V_6 ) ;
F_10 ( V_11 , V_20 ,
F_11 ( F_12 ( V_65 -> V_21 ) ) ) ;
return 0 ;
V_17:
return 1 ;
}
static int
F_45 ( struct V_22 * V_23 , const struct V_10 * V_11 ,
enum V_24 V_25 , T_1 V_26 , T_1 V_27 , T_1 V_28 )
{
const struct V_29 * V_30 = V_23 -> V_12 ;
T_2 V_31 = V_23 -> V_32 -> V_25 [ V_25 ] ;
struct V_62 V_12 = { } ;
if ( ! F_46 ( V_11 , V_28 & V_33 ,
& V_12 . V_5 , & V_12 . V_6 ) )
return - V_34 ;
F_47 ( V_11 , V_28 & V_35 , & V_12 . V_4 . V_63 ) ;
F_47 ( V_11 , V_28 & V_36 , & V_12 . V_3 . V_63 ) ;
return V_31 ( V_23 , & V_12 , V_30 -> V_21 ) ;
}
static int
F_48 ( struct V_22 * V_23 , struct V_37 * V_38 [] ,
enum V_24 V_25 , T_3 * V_39 , T_3 V_28 )
{
const struct V_29 * V_30 = V_23 -> V_12 ;
T_2 V_31 = V_23 -> V_32 -> V_25 [ V_25 ] ;
struct V_62 V_12 = { } ;
T_3 V_5 , V_42 ;
T_3 V_21 = V_30 -> V_21 ;
bool V_43 = false ;
int V_44 ;
if ( F_17 ( ! V_38 [ V_13 ] || ! V_38 [ V_14 ] ||
! F_18 ( V_38 , V_15 ) ||
! F_19 ( V_38 , V_45 ) ||
! F_19 ( V_38 , V_20 ) ||
V_38 [ V_53 ] ||
V_38 [ V_54 ] ) )
return - V_46 ;
if ( V_38 [ V_47 ] )
* V_39 = F_20 ( V_38 [ V_47 ] ) ;
V_44 = F_49 ( V_38 [ V_13 ] , & V_12 . V_4 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_49 ( V_38 [ V_14 ] , & V_12 . V_3 ) ;
if ( V_44 )
return V_44 ;
if ( V_38 [ V_15 ] )
V_12 . V_5 = F_22 ( V_38 [ V_15 ] ) ;
else
return - V_46 ;
if ( V_38 [ V_16 ] ) {
V_12 . V_6 = F_23 ( V_38 [ V_16 ] ) ;
V_43 = F_24 ( V_12 . V_6 ) ;
if ( V_12 . V_6 == 0 )
return - V_48 ;
} else
return - V_49 ;
if ( ! ( V_43 || V_12 . V_6 == V_66 ) )
V_12 . V_5 = 0 ;
if ( V_38 [ V_20 ] ) {
if ( ! F_25 ( V_30 -> V_21 ) )
return - V_51 ;
V_21 = F_26 ( V_38 [ V_20 ] ) ;
}
if ( V_25 == V_52 || ! V_43 || ! V_38 [ V_45 ] ) {
V_44 = V_31 ( V_23 , & V_12 , V_21 ) ;
return F_27 ( V_44 , V_28 ) ? 0 : V_44 ;
}
V_5 = F_32 ( V_12 . V_5 ) ;
V_42 = F_33 ( V_38 [ V_45 ] ) ;
if ( V_5 > V_42 )
F_30 ( V_5 , V_42 ) ;
for (; V_5 <= V_42 ; V_5 ++ ) {
V_12 . V_5 = F_35 ( V_5 ) ;
V_44 = V_31 ( V_23 , & V_12 , V_21 ) ;
if ( V_44 && ! F_27 ( V_44 , V_28 ) )
return V_44 ;
else
V_44 = 0 ;
}
return V_44 ;
}
static int
F_50 ( struct V_22 * V_23 , struct V_37 * V_38 [] , T_3 V_28 )
{
struct V_29 * V_30 ;
T_3 V_67 = V_68 , V_61 = V_69 ;
T_1 V_70 ;
if ( ! ( V_23 -> V_71 == V_72 || V_23 -> V_71 == V_73 ) )
return - V_74 ;
if ( F_17 ( ! F_19 ( V_38 , V_75 ) ||
! F_19 ( V_38 , V_76 ) ||
! F_19 ( V_38 , V_20 ) ) )
return - V_46 ;
if ( V_38 [ V_75 ] ) {
V_67 = F_51 ( V_38 [ V_75 ] ) ;
if ( V_67 < V_77 )
V_67 = V_77 ;
}
if ( V_38 [ V_76 ] )
V_61 = F_51 ( V_38 [ V_76 ] ) ;
V_30 = F_52 ( sizeof( * V_30 ) , V_78 ) ;
if ( ! V_30 )
return - V_79 ;
V_30 -> V_61 = V_61 ;
F_53 ( & V_30 -> V_80 , sizeof( V_30 -> V_80 ) ) ;
V_30 -> V_21 = V_81 ;
V_70 = F_54 ( V_67 ) ;
V_30 -> V_82 = F_55 (
sizeof( struct V_83 )
+ F_56 ( V_70 ) * sizeof( struct V_84 ) ) ;
if ( ! V_30 -> V_82 ) {
F_57 ( V_30 ) ;
return - V_79 ;
}
V_30 -> V_82 -> F_54 = V_70 ;
V_23 -> V_12 = V_30 ;
if ( V_38 [ V_20 ] ) {
V_30 -> V_21 = F_26 ( V_38 [ V_20 ] ) ;
V_23 -> V_32 = V_23 -> V_71 == V_72
? & V_85 : & V_86 ;
if ( V_23 -> V_71 == V_72 )
F_58 ( V_23 ) ;
else
F_59 ( V_23 ) ;
} else {
V_23 -> V_32 = V_23 -> V_71 == V_72
? & V_87 : & V_88 ;
}
F_60 ( L_1 ,
V_23 -> V_89 , F_56 ( V_30 -> V_82 -> F_54 ) ,
V_30 -> V_82 -> F_54 , V_30 -> V_61 , V_23 -> V_12 , V_30 -> V_82 ) ;
return 0 ;
}
static int T_4
F_61 ( void )
{
return F_62 ( & V_90 ) ;
}
static void T_5
F_63 ( void )
{
F_64 ( & V_90 ) ;
}
