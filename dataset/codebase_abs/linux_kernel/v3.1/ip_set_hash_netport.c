static inline bool
F_1 ( const struct V_1 * V_2 ,
const struct V_1 * V_3 ,
T_1 * V_4 )
{
return V_2 -> V_5 == V_3 -> V_5 &&
V_2 -> V_6 == V_3 -> V_6 &&
V_2 -> V_7 == V_3 -> V_7 &&
V_2 -> V_8 == V_3 -> V_8 ;
}
static inline bool
F_2 ( const struct V_1 * V_9 )
{
return V_9 -> V_7 == 0 ;
}
static inline void
F_3 ( struct V_1 * V_10 ,
const struct V_1 * V_11 )
{
V_10 -> V_5 = V_11 -> V_5 ;
V_10 -> V_6 = V_11 -> V_6 ;
V_10 -> V_7 = V_11 -> V_7 ;
V_10 -> V_8 = V_11 -> V_8 ;
}
static inline void
F_4 ( struct V_1 * V_9 , T_2 V_8 )
{
V_9 -> V_5 &= F_5 ( V_8 ) ;
V_9 -> V_8 = V_8 ;
}
static inline void
F_6 ( struct V_1 * V_9 )
{
V_9 -> V_7 = 0 ;
}
static bool
F_7 ( struct V_12 * V_13 ,
const struct V_1 * V_14 )
{
F_8 ( V_13 , V_15 , V_14 -> V_5 ) ;
F_9 ( V_13 , V_16 , V_14 -> V_6 ) ;
F_10 ( V_13 , V_17 , V_14 -> V_8 ) ;
F_10 ( V_13 , V_18 , V_14 -> V_7 ) ;
return 0 ;
V_19:
return 1 ;
}
static bool
F_11 ( struct V_12 * V_13 ,
const struct V_1 * V_14 )
{
const struct V_20 * V_21 =
( const struct V_20 * ) V_14 ;
F_8 ( V_13 , V_15 , V_21 -> V_5 ) ;
F_9 ( V_13 , V_16 , V_21 -> V_6 ) ;
F_10 ( V_13 , V_17 , V_14 -> V_8 ) ;
F_10 ( V_13 , V_18 , V_14 -> V_7 ) ;
F_12 ( V_13 , V_22 ,
F_13 ( F_14 ( V_21 -> V_23 ) ) ) ;
return 0 ;
V_19:
return 1 ;
}
static inline void
F_15 ( struct V_24 * V_25 ,
const struct V_1 * V_26 )
{
V_25 -> V_27 . V_5 = F_16 ( V_26 -> V_5 ) ;
V_25 -> V_27 . V_6 = F_17 ( V_26 -> V_6 ) ;
}
static int
F_18 ( struct V_28 * V_29 , const struct V_12 * V_13 ,
const struct V_30 * V_31 ,
enum V_32 V_33 , const struct V_34 * V_35 )
{
const struct V_24 * V_25 = V_29 -> V_14 ;
T_3 V_36 = V_29 -> V_37 -> V_33 [ V_33 ] ;
struct V_1 V_14 = {
. V_8 = V_25 -> V_38 [ 0 ] . V_8 ? V_25 -> V_38 [ 0 ] . V_8 : V_39
} ;
if ( V_14 . V_8 == 0 )
return - V_40 ;
if ( V_33 == V_41 )
V_14 . V_8 = V_39 ;
if ( ! F_19 ( V_13 , V_35 -> V_42 & V_43 ,
& V_14 . V_6 , & V_14 . V_7 ) )
return - V_40 ;
F_20 ( V_13 , V_35 -> V_42 & V_44 , & V_14 . V_5 ) ;
V_14 . V_5 &= F_5 ( V_14 . V_8 ) ;
return V_36 ( V_29 , & V_14 , F_21 ( V_35 , V_25 ) , V_35 -> V_45 ) ;
}
static int
F_22 ( struct V_28 * V_29 , struct V_46 * V_47 [] ,
enum V_32 V_33 , T_1 * V_48 , T_1 V_42 , bool V_49 )
{
const struct V_24 * V_25 = V_29 -> V_14 ;
T_3 V_36 = V_29 -> V_37 -> V_33 [ V_33 ] ;
struct V_1 V_14 = { . V_8 = V_39 } ;
T_1 V_6 , V_50 , V_51 = 0 , V_5 = 0 , V_52 , V_53 ;
T_1 V_23 = V_25 -> V_23 ;
bool V_54 = false ;
int V_55 ;
if ( F_23 ( ! V_47 [ V_15 ] ||
! F_24 ( V_47 , V_16 ) ||
! F_25 ( V_47 , V_56 ) ||
! F_25 ( V_47 , V_22 ) ) )
return - V_57 ;
if ( V_47 [ V_58 ] )
* V_48 = F_26 ( V_47 [ V_58 ] ) ;
V_55 = F_27 ( V_47 [ V_15 ] , & V_5 ) ;
if ( V_55 )
return V_55 ;
if ( V_47 [ V_17 ] ) {
V_14 . V_8 = F_28 ( V_47 [ V_17 ] ) ;
if ( ! V_14 . V_8 )
return - V_59 ;
}
if ( V_47 [ V_16 ] )
V_14 . V_6 = F_29 ( V_47 [ V_16 ] ) ;
else
return - V_57 ;
if ( V_47 [ V_18 ] ) {
V_14 . V_7 = F_28 ( V_47 [ V_18 ] ) ;
V_54 = F_30 ( V_14 . V_7 ) ;
if ( V_14 . V_7 == 0 )
return - V_60 ;
} else
return - V_61 ;
if ( ! ( V_54 || V_14 . V_7 == V_62 ) )
V_14 . V_6 = 0 ;
if ( V_47 [ V_22 ] ) {
if ( ! F_31 ( V_25 -> V_23 ) )
return - V_63 ;
V_23 = F_32 ( V_47 [ V_22 ] ) ;
}
V_54 = V_54 && V_47 [ V_56 ] ;
if ( V_33 == V_41 || ! ( V_54 || V_47 [ V_64 ] ) ) {
V_14 . V_5 = F_13 ( V_5 & F_33 ( V_14 . V_8 ) ) ;
V_55 = V_36 ( V_29 , & V_14 , V_23 , V_42 ) ;
return F_34 ( V_55 , V_42 ) ? 0 : V_55 ;
}
V_6 = V_50 = F_17 ( V_14 . V_6 ) ;
if ( V_47 [ V_56 ] ) {
V_50 = F_35 ( V_47 [ V_56 ] ) ;
if ( V_50 < V_6 )
F_36 ( V_6 , V_50 ) ;
}
if ( V_47 [ V_64 ] ) {
V_55 = F_27 ( V_47 [ V_64 ] , & V_52 ) ;
if ( V_55 )
return V_55 ;
if ( V_52 < V_5 )
F_36 ( V_5 , V_52 ) ;
if ( V_5 + V_65 == V_52 )
return - V_66 ;
} else {
F_37 ( V_5 , V_52 , V_14 . V_8 ) ;
}
if ( V_49 )
V_5 = V_25 -> V_27 . V_5 ;
while ( ! F_38 ( V_5 , V_52 ) ) {
V_14 . V_5 = F_13 ( V_5 ) ;
V_53 = F_39 ( V_5 , V_52 , & V_14 . V_8 ) ;
V_51 = V_49 && V_5 == V_25 -> V_27 . V_5 ? V_25 -> V_27 . V_6 : V_6 ;
for (; V_51 <= V_50 ; V_51 ++ ) {
V_14 . V_6 = F_40 ( V_51 ) ;
V_55 = V_36 ( V_29 , & V_14 , V_23 , V_42 ) ;
if ( V_55 && ! F_34 ( V_55 , V_42 ) )
return V_55 ;
else
V_55 = 0 ;
}
V_5 = V_53 + 1 ;
}
return V_55 ;
}
static bool
F_41 ( const struct V_28 * V_67 , const struct V_28 * V_68 )
{
const struct V_24 * V_69 = V_67 -> V_14 ;
const struct V_24 * V_70 = V_68 -> V_14 ;
return V_69 -> V_71 == V_70 -> V_71 &&
V_69 -> V_23 == V_70 -> V_23 ;
}
static inline bool
F_42 ( const struct V_72 * V_2 ,
const struct V_72 * V_3 ,
T_1 * V_4 )
{
return F_43 ( & V_2 -> V_5 . V_73 , & V_3 -> V_5 . V_73 ) == 0 &&
V_2 -> V_6 == V_3 -> V_6 &&
V_2 -> V_7 == V_3 -> V_7 &&
V_2 -> V_8 == V_3 -> V_8 ;
}
static inline bool
F_44 ( const struct V_72 * V_9 )
{
return V_9 -> V_7 == 0 ;
}
static inline void
F_45 ( struct V_72 * V_10 ,
const struct V_72 * V_11 )
{
memcpy ( V_10 , V_11 , sizeof( * V_10 ) ) ;
}
static inline void
F_46 ( struct V_72 * V_9 )
{
V_9 -> V_7 = 0 ;
}
static inline void
F_47 ( union V_74 * V_5 , T_2 V_75 )
{
V_5 -> V_76 [ 0 ] &= F_48 ( V_75 ) [ 0 ] ;
V_5 -> V_76 [ 1 ] &= F_48 ( V_75 ) [ 1 ] ;
V_5 -> V_76 [ 2 ] &= F_48 ( V_75 ) [ 2 ] ;
V_5 -> V_76 [ 3 ] &= F_48 ( V_75 ) [ 3 ] ;
}
static inline void
F_49 ( struct V_72 * V_9 , T_2 V_8 )
{
F_47 ( & V_9 -> V_5 , V_8 ) ;
V_9 -> V_8 = V_8 ;
}
static bool
F_50 ( struct V_12 * V_13 ,
const struct V_72 * V_14 )
{
F_51 ( V_13 , V_15 , & V_14 -> V_5 ) ;
F_9 ( V_13 , V_16 , V_14 -> V_6 ) ;
F_10 ( V_13 , V_17 , V_14 -> V_8 ) ;
F_10 ( V_13 , V_18 , V_14 -> V_7 ) ;
return 0 ;
V_19:
return 1 ;
}
static bool
F_52 ( struct V_12 * V_13 ,
const struct V_72 * V_14 )
{
const struct V_77 * V_78 =
( const struct V_77 * ) V_14 ;
F_51 ( V_13 , V_15 , & V_78 -> V_5 ) ;
F_9 ( V_13 , V_16 , V_14 -> V_6 ) ;
F_10 ( V_13 , V_17 , V_14 -> V_8 ) ;
F_10 ( V_13 , V_18 , V_14 -> V_7 ) ;
F_12 ( V_13 , V_22 ,
F_13 ( F_14 ( V_78 -> V_23 ) ) ) ;
return 0 ;
V_19:
return 1 ;
}
static inline void
F_53 ( struct V_24 * V_25 ,
const struct V_72 * V_26 )
{
V_25 -> V_27 . V_6 = F_17 ( V_26 -> V_6 ) ;
}
static int
F_54 ( struct V_28 * V_29 , const struct V_12 * V_13 ,
const struct V_30 * V_31 ,
enum V_32 V_33 , const struct V_34 * V_35 )
{
const struct V_24 * V_25 = V_29 -> V_14 ;
T_3 V_36 = V_29 -> V_37 -> V_33 [ V_33 ] ;
struct V_72 V_14 = {
. V_8 = V_25 -> V_38 [ 0 ] . V_8 ? V_25 -> V_38 [ 0 ] . V_8 : V_39
} ;
if ( V_14 . V_8 == 0 )
return - V_40 ;
if ( V_33 == V_41 )
V_14 . V_8 = V_39 ;
if ( ! F_55 ( V_13 , V_35 -> V_42 & V_43 ,
& V_14 . V_6 , & V_14 . V_7 ) )
return - V_40 ;
F_56 ( V_13 , V_35 -> V_42 & V_44 , & V_14 . V_5 . V_73 ) ;
F_47 ( & V_14 . V_5 , V_14 . V_8 ) ;
return V_36 ( V_29 , & V_14 , F_21 ( V_35 , V_25 ) , V_35 -> V_45 ) ;
}
static int
F_57 ( struct V_28 * V_29 , struct V_46 * V_47 [] ,
enum V_32 V_33 , T_1 * V_48 , T_1 V_42 , bool V_49 )
{
const struct V_24 * V_25 = V_29 -> V_14 ;
T_3 V_36 = V_29 -> V_37 -> V_33 [ V_33 ] ;
struct V_72 V_14 = { . V_8 = V_39 } ;
T_1 V_6 , V_50 ;
T_1 V_23 = V_25 -> V_23 ;
bool V_54 = false ;
int V_55 ;
if ( F_23 ( ! V_47 [ V_15 ] ||
! F_24 ( V_47 , V_16 ) ||
! F_25 ( V_47 , V_56 ) ||
! F_25 ( V_47 , V_22 ) ) )
return - V_57 ;
if ( F_23 ( V_47 [ V_64 ] ) )
return - V_79 ;
if ( V_47 [ V_58 ] )
* V_48 = F_26 ( V_47 [ V_58 ] ) ;
V_55 = F_58 ( V_47 [ V_15 ] , & V_14 . V_5 ) ;
if ( V_55 )
return V_55 ;
if ( V_47 [ V_17 ] )
V_14 . V_8 = F_28 ( V_47 [ V_17 ] ) ;
if ( ! V_14 . V_8 )
return - V_59 ;
F_47 ( & V_14 . V_5 , V_14 . V_8 ) ;
if ( V_47 [ V_16 ] )
V_14 . V_6 = F_29 ( V_47 [ V_16 ] ) ;
else
return - V_57 ;
if ( V_47 [ V_18 ] ) {
V_14 . V_7 = F_28 ( V_47 [ V_18 ] ) ;
V_54 = F_30 ( V_14 . V_7 ) ;
if ( V_14 . V_7 == 0 )
return - V_60 ;
} else
return - V_61 ;
if ( ! ( V_54 || V_14 . V_7 == V_80 ) )
V_14 . V_6 = 0 ;
if ( V_47 [ V_22 ] ) {
if ( ! F_31 ( V_25 -> V_23 ) )
return - V_63 ;
V_23 = F_32 ( V_47 [ V_22 ] ) ;
}
if ( V_33 == V_41 || ! V_54 || ! V_47 [ V_56 ] ) {
V_55 = V_36 ( V_29 , & V_14 , V_23 , V_42 ) ;
return F_34 ( V_55 , V_42 ) ? 0 : V_55 ;
}
V_6 = F_17 ( V_14 . V_6 ) ;
V_50 = F_35 ( V_47 [ V_56 ] ) ;
if ( V_6 > V_50 )
F_36 ( V_6 , V_50 ) ;
if ( V_49 )
V_6 = V_25 -> V_27 . V_6 ;
for (; V_6 <= V_50 ; V_6 ++ ) {
V_14 . V_6 = F_40 ( V_6 ) ;
V_55 = V_36 ( V_29 , & V_14 , V_23 , V_42 ) ;
if ( V_55 && ! F_34 ( V_55 , V_42 ) )
return V_55 ;
else
V_55 = 0 ;
}
return V_55 ;
}
static int
F_59 ( struct V_28 * V_29 , struct V_46 * V_47 [] , T_1 V_42 )
{
struct V_24 * V_25 ;
T_1 V_81 = V_82 , V_71 = V_83 ;
T_2 V_84 ;
if ( ! ( V_29 -> V_85 == V_86 || V_29 -> V_85 == V_87 ) )
return - V_88 ;
if ( F_23 ( ! F_25 ( V_47 , V_89 ) ||
! F_25 ( V_47 , V_90 ) ||
! F_25 ( V_47 , V_22 ) ) )
return - V_57 ;
if ( V_47 [ V_89 ] ) {
V_81 = F_60 ( V_47 [ V_89 ] ) ;
if ( V_81 < V_91 )
V_81 = V_91 ;
}
if ( V_47 [ V_90 ] )
V_71 = F_60 ( V_47 [ V_90 ] ) ;
V_25 = F_61 ( sizeof( * V_25 )
+ sizeof( struct V_92 )
* ( V_29 -> V_85 == V_86 ? 32 : 128 ) , V_93 ) ;
if ( ! V_25 )
return - V_94 ;
V_25 -> V_71 = V_71 ;
F_62 ( & V_25 -> V_95 , sizeof( V_25 -> V_95 ) ) ;
V_25 -> V_23 = V_96 ;
V_84 = F_63 ( V_81 ) ;
V_25 -> V_97 = F_64 (
sizeof( struct V_98 )
+ F_65 ( V_84 ) * sizeof( struct V_99 ) ) ;
if ( ! V_25 -> V_97 ) {
F_66 ( V_25 ) ;
return - V_94 ;
}
V_25 -> V_97 -> F_63 = V_84 ;
V_29 -> V_14 = V_25 ;
if ( V_47 [ V_22 ] ) {
V_25 -> V_23 = F_32 ( V_47 [ V_22 ] ) ;
V_29 -> V_37 = V_29 -> V_85 == V_86
? & V_100 : & V_101 ;
if ( V_29 -> V_85 == V_86 )
F_67 ( V_29 ) ;
else
F_68 ( V_29 ) ;
} else {
V_29 -> V_37 = V_29 -> V_85 == V_86
? & V_102 : & V_103 ;
}
F_69 ( L_1 ,
V_29 -> V_104 , F_65 ( V_25 -> V_97 -> F_63 ) ,
V_25 -> V_97 -> F_63 , V_25 -> V_71 , V_29 -> V_14 , V_25 -> V_97 ) ;
return 0 ;
}
static int T_4
F_70 ( void )
{
return F_71 ( & V_105 ) ;
}
static void T_5
F_72 ( void )
{
F_73 ( & V_105 ) ;
}
