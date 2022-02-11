static inline bool
F_1 ( const struct V_1 * V_2 ,
const struct V_1 * V_3 )
{
return V_2 -> V_4 == V_3 -> V_4 &&
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
V_8 -> V_4 = V_9 -> V_4 ;
V_8 -> V_5 = V_9 -> V_5 ;
V_8 -> V_6 = V_9 -> V_6 ;
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
F_7 ( V_11 , V_14 , V_12 -> V_5 ) ;
F_8 ( V_11 , V_15 , V_12 -> V_6 ) ;
return 0 ;
V_16:
return 1 ;
}
static bool
F_9 ( struct V_10 * V_11 ,
const struct V_1 * V_12 )
{
const struct V_17 * V_18 =
( const struct V_17 * ) V_12 ;
F_6 ( V_11 , V_13 , V_18 -> V_4 ) ;
F_7 ( V_11 , V_14 , V_18 -> V_5 ) ;
F_8 ( V_11 , V_15 , V_12 -> V_6 ) ;
F_10 ( V_11 , V_19 ,
F_11 ( F_12 ( V_18 -> V_20 ) ) ) ;
return 0 ;
V_16:
return 1 ;
}
static int
F_13 ( struct V_21 * V_22 , const struct V_10 * V_11 ,
enum V_23 V_24 , T_1 V_25 , T_1 V_26 , T_1 V_27 )
{
const struct V_28 * V_29 = V_22 -> V_12 ;
T_2 V_30 = V_22 -> V_31 -> V_24 [ V_24 ] ;
struct V_1 V_12 = { } ;
if ( ! F_14 ( V_11 , V_27 & V_32 ,
& V_12 . V_5 , & V_12 . V_6 ) )
return - V_33 ;
F_15 ( V_11 , V_27 & V_34 , & V_12 . V_4 ) ;
return V_30 ( V_22 , & V_12 , V_29 -> V_20 ) ;
}
static int
F_16 ( struct V_21 * V_22 , struct V_35 * V_36 [] ,
enum V_23 V_24 , T_3 * V_37 , T_3 V_27 )
{
const struct V_28 * V_29 = V_22 -> V_12 ;
T_2 V_30 = V_22 -> V_31 -> V_24 [ V_24 ] ;
struct V_1 V_12 = { } ;
T_3 V_4 , V_38 , V_39 , V_5 , V_40 ;
T_3 V_20 = V_29 -> V_20 ;
bool V_41 = false ;
int V_42 ;
if ( F_17 ( ! V_36 [ V_13 ] ||
! F_18 ( V_36 , V_14 ) ||
! F_19 ( V_36 , V_43 ) ||
! F_19 ( V_36 , V_19 ) ) )
return - V_44 ;
if ( V_36 [ V_45 ] )
* V_37 = F_20 ( V_36 [ V_45 ] ) ;
V_42 = F_21 ( V_36 [ V_13 ] , & V_12 . V_4 ) ;
if ( V_42 )
return V_42 ;
if ( V_36 [ V_14 ] )
V_12 . V_5 = F_22 ( V_36 [ V_14 ] ) ;
else
return - V_44 ;
if ( V_36 [ V_15 ] ) {
V_12 . V_6 = F_23 ( V_36 [ V_15 ] ) ;
V_41 = F_24 ( V_12 . V_6 ) ;
if ( V_12 . V_6 == 0 )
return - V_46 ;
} else
return - V_47 ;
if ( ! ( V_41 || V_12 . V_6 == V_48 ) )
V_12 . V_5 = 0 ;
if ( V_36 [ V_19 ] ) {
if ( ! F_25 ( V_29 -> V_20 ) )
return - V_49 ;
V_20 = F_26 ( V_36 [ V_19 ] ) ;
}
if ( V_24 == V_50 ||
! ( V_36 [ V_51 ] || V_36 [ V_52 ] ||
V_36 [ V_43 ] ) ) {
V_42 = V_30 ( V_22 , & V_12 , V_20 ) ;
return F_27 ( V_42 , V_27 ) ? 0 : V_42 ;
}
V_4 = F_28 ( V_12 . V_4 ) ;
if ( V_36 [ V_51 ] ) {
V_42 = F_29 ( V_36 [ V_51 ] , & V_38 ) ;
if ( V_42 )
return V_42 ;
if ( V_4 > V_38 )
F_30 ( V_4 , V_38 ) ;
} else if ( V_36 [ V_52 ] ) {
T_1 V_53 = F_23 ( V_36 [ V_52 ] ) ;
if ( V_53 > 32 )
return - V_54 ;
V_4 &= F_31 ( V_53 ) ;
V_38 = V_4 | ~ F_31 ( V_53 ) ;
} else
V_38 = V_4 ;
V_40 = V_5 = F_32 ( V_12 . V_5 ) ;
if ( V_41 && V_36 [ V_43 ] ) {
V_40 = F_33 ( V_36 [ V_43 ] ) ;
if ( V_5 > V_40 )
F_30 ( V_5 , V_40 ) ;
}
for (; ! F_34 ( V_38 , V_4 ) ; V_4 ++ )
for ( V_39 = V_5 ; V_39 <= V_40 ; V_39 ++ ) {
V_12 . V_4 = F_11 ( V_4 ) ;
V_12 . V_5 = F_35 ( V_39 ) ;
V_42 = V_30 ( V_22 , & V_12 , V_20 ) ;
if ( V_42 && ! F_27 ( V_42 , V_27 ) )
return V_42 ;
else
V_42 = 0 ;
}
return V_42 ;
}
static bool
F_36 ( const struct V_21 * V_55 , const struct V_21 * V_56 )
{
const struct V_28 * V_57 = V_55 -> V_12 ;
const struct V_28 * V_58 = V_56 -> V_12 ;
return V_57 -> V_59 == V_58 -> V_59 &&
V_57 -> V_20 == V_58 -> V_20 ;
}
static inline bool
F_37 ( const struct V_60 * V_2 ,
const struct V_60 * V_3 )
{
return F_38 ( & V_2 -> V_4 . V_61 , & V_3 -> V_4 . V_61 ) == 0 &&
V_2 -> V_5 == V_3 -> V_5 &&
V_2 -> V_6 == V_3 -> V_6 ;
}
static inline bool
F_39 ( const struct V_60 * V_7 )
{
return V_7 -> V_6 == 0 ;
}
static inline void
F_40 ( struct V_60 * V_8 ,
const struct V_60 * V_9 )
{
memcpy ( V_8 , V_9 , sizeof( * V_8 ) ) ;
}
static inline void
F_41 ( struct V_60 * V_7 )
{
V_7 -> V_6 = 0 ;
}
static bool
F_42 ( struct V_10 * V_11 ,
const struct V_60 * V_12 )
{
F_43 ( V_11 , V_13 , & V_12 -> V_4 ) ;
F_7 ( V_11 , V_14 , V_12 -> V_5 ) ;
F_8 ( V_11 , V_15 , V_12 -> V_6 ) ;
return 0 ;
V_16:
return 1 ;
}
static bool
F_44 ( struct V_10 * V_11 ,
const struct V_60 * V_12 )
{
const struct V_62 * V_63 =
( const struct V_62 * ) V_12 ;
F_43 ( V_11 , V_13 , & V_63 -> V_4 ) ;
F_7 ( V_11 , V_14 , V_12 -> V_5 ) ;
F_8 ( V_11 , V_15 , V_12 -> V_6 ) ;
F_10 ( V_11 , V_19 ,
F_11 ( F_12 ( V_63 -> V_20 ) ) ) ;
return 0 ;
V_16:
return 1 ;
}
static int
F_45 ( struct V_21 * V_22 , const struct V_10 * V_11 ,
enum V_23 V_24 , T_1 V_25 , T_1 V_26 , T_1 V_27 )
{
const struct V_28 * V_29 = V_22 -> V_12 ;
T_2 V_30 = V_22 -> V_31 -> V_24 [ V_24 ] ;
struct V_60 V_12 = { } ;
if ( ! F_46 ( V_11 , V_27 & V_32 ,
& V_12 . V_5 , & V_12 . V_6 ) )
return - V_33 ;
F_47 ( V_11 , V_27 & V_34 , & V_12 . V_4 . V_61 ) ;
return V_30 ( V_22 , & V_12 , V_29 -> V_20 ) ;
}
static int
F_48 ( struct V_21 * V_22 , struct V_35 * V_36 [] ,
enum V_23 V_24 , T_3 * V_37 , T_3 V_27 )
{
const struct V_28 * V_29 = V_22 -> V_12 ;
T_2 V_30 = V_22 -> V_31 -> V_24 [ V_24 ] ;
struct V_60 V_12 = { } ;
T_3 V_5 , V_40 ;
T_3 V_20 = V_29 -> V_20 ;
bool V_41 = false ;
int V_42 ;
if ( F_17 ( ! V_36 [ V_13 ] ||
! F_18 ( V_36 , V_14 ) ||
! F_19 ( V_36 , V_43 ) ||
! F_19 ( V_36 , V_19 ) ||
V_36 [ V_51 ] ||
V_36 [ V_52 ] ) )
return - V_44 ;
if ( V_36 [ V_45 ] )
* V_37 = F_20 ( V_36 [ V_45 ] ) ;
V_42 = F_49 ( V_36 [ V_13 ] , & V_12 . V_4 ) ;
if ( V_42 )
return V_42 ;
if ( V_36 [ V_14 ] )
V_12 . V_5 = F_22 ( V_36 [ V_14 ] ) ;
else
return - V_44 ;
if ( V_36 [ V_15 ] ) {
V_12 . V_6 = F_23 ( V_36 [ V_15 ] ) ;
V_41 = F_24 ( V_12 . V_6 ) ;
if ( V_12 . V_6 == 0 )
return - V_46 ;
} else
return - V_47 ;
if ( ! ( V_41 || V_12 . V_6 == V_64 ) )
V_12 . V_5 = 0 ;
if ( V_36 [ V_19 ] ) {
if ( ! F_25 ( V_29 -> V_20 ) )
return - V_49 ;
V_20 = F_26 ( V_36 [ V_19 ] ) ;
}
if ( V_24 == V_50 || ! V_41 || ! V_36 [ V_43 ] ) {
V_42 = V_30 ( V_22 , & V_12 , V_20 ) ;
return F_27 ( V_42 , V_27 ) ? 0 : V_42 ;
}
V_5 = F_32 ( V_12 . V_5 ) ;
V_40 = F_33 ( V_36 [ V_43 ] ) ;
if ( V_5 > V_40 )
F_30 ( V_5 , V_40 ) ;
for (; V_5 <= V_40 ; V_5 ++ ) {
V_12 . V_5 = F_35 ( V_5 ) ;
V_42 = V_30 ( V_22 , & V_12 , V_20 ) ;
if ( V_42 && ! F_27 ( V_42 , V_27 ) )
return V_42 ;
else
V_42 = 0 ;
}
return V_42 ;
}
static int
F_50 ( struct V_21 * V_22 , struct V_35 * V_36 [] , T_3 V_27 )
{
struct V_28 * V_29 ;
T_3 V_65 = V_66 , V_59 = V_67 ;
T_1 V_68 ;
if ( ! ( V_22 -> V_69 == V_70 || V_22 -> V_69 == V_71 ) )
return - V_72 ;
if ( F_17 ( ! F_19 ( V_36 , V_73 ) ||
! F_19 ( V_36 , V_74 ) ||
! F_19 ( V_36 , V_19 ) ) )
return - V_44 ;
if ( V_36 [ V_73 ] ) {
V_65 = F_51 ( V_36 [ V_73 ] ) ;
if ( V_65 < V_75 )
V_65 = V_75 ;
}
if ( V_36 [ V_74 ] )
V_59 = F_51 ( V_36 [ V_74 ] ) ;
V_29 = F_52 ( sizeof( * V_29 ) , V_76 ) ;
if ( ! V_29 )
return - V_77 ;
V_29 -> V_59 = V_59 ;
F_53 ( & V_29 -> V_78 , sizeof( V_29 -> V_78 ) ) ;
V_29 -> V_20 = V_79 ;
V_68 = F_54 ( V_65 ) ;
V_29 -> V_80 = F_55 (
sizeof( struct V_81 )
+ F_56 ( V_68 ) * sizeof( struct V_82 ) ) ;
if ( ! V_29 -> V_80 ) {
F_57 ( V_29 ) ;
return - V_77 ;
}
V_29 -> V_80 -> F_54 = V_68 ;
V_22 -> V_12 = V_29 ;
if ( V_36 [ V_19 ] ) {
V_29 -> V_20 = F_26 ( V_36 [ V_19 ] ) ;
V_22 -> V_31 = V_22 -> V_69 == V_70
? & V_83 : & V_84 ;
if ( V_22 -> V_69 == V_70 )
F_58 ( V_22 ) ;
else
F_59 ( V_22 ) ;
} else {
V_22 -> V_31 = V_22 -> V_69 == V_70
? & V_85 : & V_86 ;
}
F_60 ( L_1 ,
V_22 -> V_87 , F_56 ( V_29 -> V_80 -> F_54 ) ,
V_29 -> V_80 -> F_54 , V_29 -> V_59 , V_22 -> V_12 , V_29 -> V_80 ) ;
return 0 ;
}
static int T_4
F_61 ( void )
{
return F_62 ( & V_88 ) ;
}
static void T_5
F_63 ( void )
{
F_64 ( & V_88 ) ;
}
