static inline bool
F_1 ( const struct V_1 * V_2 ,
const struct V_1 * V_3 ,
T_1 * V_4 )
{
return V_2 -> V_5 == V_3 -> V_5 &&
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
V_8 -> V_5 = V_9 -> V_5 ;
V_8 -> V_6 = V_9 -> V_6 ;
V_8 -> V_10 = V_9 -> V_10 ;
}
static inline void
F_4 ( struct V_1 * V_8 , T_1 V_11 )
{
V_8 -> V_10 = V_11 & V_12 ;
}
static inline bool
F_5 ( const struct V_1 * V_7 )
{
return ! V_7 -> V_10 ;
}
static inline void
F_6 ( struct V_1 * V_7 , T_2 V_6 )
{
V_7 -> V_5 &= F_7 ( V_6 ) ;
V_7 -> V_6 = V_6 ;
}
static inline void
F_8 ( struct V_1 * V_7 )
{
V_7 -> V_6 = 0 ;
}
static bool
F_9 ( struct V_13 * V_14 , const struct V_1 * V_15 )
{
T_1 V_11 = V_15 -> V_10 ? V_12 : 0 ;
F_10 ( V_14 , V_16 , V_15 -> V_5 ) ;
F_11 ( V_14 , V_17 , V_15 -> V_6 ) ;
if ( V_11 )
F_12 ( V_14 , V_18 , F_13 ( V_11 ) ) ;
return 0 ;
V_19:
return 1 ;
}
static bool
F_14 ( struct V_13 * V_14 , const struct V_1 * V_15 )
{
const struct V_20 * V_21 =
( const struct V_20 * ) V_15 ;
T_1 V_11 = V_15 -> V_10 ? V_12 : 0 ;
F_10 ( V_14 , V_16 , V_21 -> V_5 ) ;
F_11 ( V_14 , V_17 , V_21 -> V_6 ) ;
F_12 ( V_14 , V_22 ,
F_13 ( F_15 ( V_21 -> V_23 ) ) ) ;
if ( V_11 )
F_12 ( V_14 , V_18 , F_13 ( V_11 ) ) ;
return 0 ;
V_19:
return 1 ;
}
static inline void
F_16 ( struct V_24 * V_25 ,
const struct V_1 * V_26 )
{
V_25 -> V_27 . V_5 = F_17 ( V_26 -> V_5 ) ;
}
static int
F_18 ( struct V_28 * V_29 , const struct V_13 * V_14 ,
const struct V_30 * V_31 ,
enum V_32 V_33 , const struct V_34 * V_35 )
{
const struct V_24 * V_25 = V_29 -> V_15 ;
T_3 V_36 = V_29 -> V_37 -> V_33 [ V_33 ] ;
struct V_1 V_15 = {
. V_6 = V_25 -> V_38 [ 0 ] . V_6 ? V_25 -> V_38 [ 0 ] . V_6 : V_39
} ;
if ( V_15 . V_6 == 0 )
return - V_40 ;
if ( V_33 == V_41 )
V_15 . V_6 = V_39 ;
F_19 ( V_14 , V_35 -> V_11 & V_42 , & V_15 . V_5 ) ;
V_15 . V_5 &= F_7 ( V_15 . V_6 ) ;
return V_36 ( V_29 , & V_15 , F_20 ( V_35 , V_25 ) , V_35 -> V_43 ) ;
}
static int
F_21 ( struct V_28 * V_29 , struct V_44 * V_45 [] ,
enum V_32 V_33 , T_1 * V_46 , T_1 V_11 , bool V_47 )
{
const struct V_24 * V_25 = V_29 -> V_15 ;
T_3 V_36 = V_29 -> V_37 -> V_33 [ V_33 ] ;
struct V_1 V_15 = { . V_6 = V_39 } ;
T_1 V_23 = V_25 -> V_23 ;
T_1 V_5 = 0 , V_48 , V_49 ;
int V_50 ;
if ( F_22 ( ! V_45 [ V_16 ] ||
! F_23 ( V_45 , V_22 ) ||
! F_23 ( V_45 , V_18 ) ) )
return - V_51 ;
if ( V_45 [ V_52 ] )
* V_46 = F_24 ( V_45 [ V_52 ] ) ;
V_50 = F_25 ( V_45 [ V_16 ] , & V_5 ) ;
if ( V_50 )
return V_50 ;
if ( V_45 [ V_17 ] ) {
V_15 . V_6 = F_26 ( V_45 [ V_17 ] ) ;
if ( ! V_15 . V_6 || V_15 . V_6 > V_39 )
return - V_53 ;
}
if ( V_45 [ V_22 ] ) {
if ( ! F_27 ( V_25 -> V_23 ) )
return - V_54 ;
V_23 = F_28 ( V_45 [ V_22 ] ) ;
}
if ( V_45 [ V_18 ] && V_33 == V_55 ) {
T_1 V_56 = F_29 ( V_45 [ V_18 ] ) ;
if ( V_56 & V_12 )
V_11 |= ( V_56 << 16 ) ;
}
if ( V_33 == V_41 || ! V_45 [ V_57 ] ) {
V_15 . V_5 = F_13 ( V_5 & F_30 ( V_15 . V_6 ) ) ;
V_50 = V_36 ( V_29 , & V_15 , V_23 , V_11 ) ;
return F_31 ( V_50 , V_11 ) ? 0 : V_50 ;
}
V_48 = V_5 ;
if ( V_45 [ V_57 ] ) {
V_50 = F_25 ( V_45 [ V_57 ] , & V_48 ) ;
if ( V_50 )
return V_50 ;
if ( V_48 < V_5 )
F_32 ( V_5 , V_48 ) ;
if ( V_5 + V_58 == V_48 )
return - V_59 ;
}
if ( V_47 )
V_5 = V_25 -> V_27 . V_5 ;
while ( ! F_33 ( V_5 , V_48 ) ) {
V_15 . V_5 = F_13 ( V_5 ) ;
V_49 = F_34 ( V_5 , V_48 , & V_15 . V_6 ) ;
V_50 = V_36 ( V_29 , & V_15 , V_23 , V_11 ) ;
if ( V_50 && ! F_31 ( V_50 , V_11 ) )
return V_50 ;
else
V_50 = 0 ;
V_5 = V_49 + 1 ;
}
return V_50 ;
}
static bool
F_35 ( const struct V_28 * V_60 , const struct V_28 * V_61 )
{
const struct V_24 * V_62 = V_60 -> V_15 ;
const struct V_24 * V_63 = V_61 -> V_15 ;
return V_62 -> V_64 == V_63 -> V_64 &&
V_62 -> V_23 == V_63 -> V_23 ;
}
static inline bool
F_36 ( const struct V_65 * V_2 ,
const struct V_65 * V_3 ,
T_1 * V_4 )
{
return F_37 ( & V_2 -> V_5 . V_66 , & V_3 -> V_5 . V_66 ) == 0 &&
V_2 -> V_6 == V_3 -> V_6 ;
}
static inline bool
F_38 ( const struct V_65 * V_7 )
{
return V_7 -> V_6 == 0 ;
}
static inline void
F_39 ( struct V_65 * V_8 ,
const struct V_65 * V_9 )
{
V_8 -> V_5 . V_66 = V_9 -> V_5 . V_66 ;
V_8 -> V_6 = V_9 -> V_6 ;
V_8 -> V_10 = V_9 -> V_10 ;
}
static inline void
F_40 ( struct V_65 * V_8 , T_1 V_11 )
{
V_8 -> V_10 = V_11 & V_12 ;
}
static inline bool
F_41 ( const struct V_65 * V_7 )
{
return ! V_7 -> V_10 ;
}
static inline void
F_42 ( struct V_65 * V_7 )
{
V_7 -> V_6 = 0 ;
}
static inline void
F_43 ( union V_67 * V_5 , T_2 V_68 )
{
V_5 -> V_69 [ 0 ] &= F_44 ( V_68 ) [ 0 ] ;
V_5 -> V_69 [ 1 ] &= F_44 ( V_68 ) [ 1 ] ;
V_5 -> V_69 [ 2 ] &= F_44 ( V_68 ) [ 2 ] ;
V_5 -> V_69 [ 3 ] &= F_44 ( V_68 ) [ 3 ] ;
}
static inline void
F_45 ( struct V_65 * V_7 , T_2 V_6 )
{
F_43 ( & V_7 -> V_5 , V_6 ) ;
V_7 -> V_6 = V_6 ;
}
static bool
F_46 ( struct V_13 * V_14 , const struct V_65 * V_15 )
{
T_1 V_11 = V_15 -> V_10 ? V_12 : 0 ;
F_47 ( V_14 , V_16 , & V_15 -> V_5 ) ;
F_11 ( V_14 , V_17 , V_15 -> V_6 ) ;
if ( V_11 )
F_12 ( V_14 , V_18 , F_13 ( V_11 ) ) ;
return 0 ;
V_19:
return 1 ;
}
static bool
F_48 ( struct V_13 * V_14 , const struct V_65 * V_15 )
{
const struct V_70 * V_71 =
( const struct V_70 * ) V_15 ;
T_1 V_11 = V_15 -> V_10 ? V_12 : 0 ;
F_47 ( V_14 , V_16 , & V_71 -> V_5 ) ;
F_11 ( V_14 , V_17 , V_71 -> V_6 ) ;
F_12 ( V_14 , V_22 ,
F_13 ( F_15 ( V_71 -> V_23 ) ) ) ;
if ( V_11 )
F_12 ( V_14 , V_18 , F_13 ( V_11 ) ) ;
return 0 ;
V_19:
return 1 ;
}
static inline void
F_49 ( struct V_24 * V_25 ,
const struct V_65 * V_26 )
{
}
static int
F_50 ( struct V_28 * V_29 , const struct V_13 * V_14 ,
const struct V_30 * V_31 ,
enum V_32 V_33 , const struct V_34 * V_35 )
{
const struct V_24 * V_25 = V_29 -> V_15 ;
T_3 V_36 = V_29 -> V_37 -> V_33 [ V_33 ] ;
struct V_65 V_15 = {
. V_6 = V_25 -> V_38 [ 0 ] . V_6 ? V_25 -> V_38 [ 0 ] . V_6 : V_39
} ;
if ( V_15 . V_6 == 0 )
return - V_40 ;
if ( V_33 == V_41 )
V_15 . V_6 = V_39 ;
F_51 ( V_14 , V_35 -> V_11 & V_42 , & V_15 . V_5 . V_66 ) ;
F_43 ( & V_15 . V_5 , V_15 . V_6 ) ;
return V_36 ( V_29 , & V_15 , F_20 ( V_35 , V_25 ) , V_35 -> V_43 ) ;
}
static int
F_52 ( struct V_28 * V_29 , struct V_44 * V_45 [] ,
enum V_32 V_33 , T_1 * V_46 , T_1 V_11 , bool V_47 )
{
const struct V_24 * V_25 = V_29 -> V_15 ;
T_3 V_36 = V_29 -> V_37 -> V_33 [ V_33 ] ;
struct V_65 V_15 = { . V_6 = V_39 } ;
T_1 V_23 = V_25 -> V_23 ;
int V_50 ;
if ( F_22 ( ! V_45 [ V_16 ] ||
! F_23 ( V_45 , V_22 ) ||
! F_23 ( V_45 , V_18 ) ) )
return - V_51 ;
if ( F_22 ( V_45 [ V_57 ] ) )
return - V_72 ;
if ( V_45 [ V_52 ] )
* V_46 = F_24 ( V_45 [ V_52 ] ) ;
V_50 = F_53 ( V_45 [ V_16 ] , & V_15 . V_5 ) ;
if ( V_50 )
return V_50 ;
if ( V_45 [ V_17 ] )
V_15 . V_6 = F_26 ( V_45 [ V_17 ] ) ;
if ( ! V_15 . V_6 || V_15 . V_6 > V_39 )
return - V_53 ;
F_43 ( & V_15 . V_5 , V_15 . V_6 ) ;
if ( V_45 [ V_22 ] ) {
if ( ! F_27 ( V_25 -> V_23 ) )
return - V_54 ;
V_23 = F_28 ( V_45 [ V_22 ] ) ;
}
if ( V_45 [ V_18 ] && V_33 == V_55 ) {
T_1 V_56 = F_29 ( V_45 [ V_18 ] ) ;
if ( V_56 & V_12 )
V_11 |= ( V_56 << 16 ) ;
}
V_50 = V_36 ( V_29 , & V_15 , V_23 , V_11 ) ;
return F_31 ( V_50 , V_11 ) ? 0 : V_50 ;
}
static int
F_54 ( struct V_28 * V_29 , struct V_44 * V_45 [] , T_1 V_11 )
{
T_1 V_73 = V_74 , V_64 = V_75 ;
struct V_24 * V_25 ;
T_2 V_76 ;
T_4 V_77 ;
if ( ! ( V_29 -> V_78 == V_79 || V_29 -> V_78 == V_80 ) )
return - V_81 ;
if ( F_22 ( ! F_23 ( V_45 , V_82 ) ||
! F_23 ( V_45 , V_83 ) ||
! F_23 ( V_45 , V_22 ) ) )
return - V_51 ;
if ( V_45 [ V_82 ] ) {
V_73 = F_29 ( V_45 [ V_82 ] ) ;
if ( V_73 < V_84 )
V_73 = V_84 ;
}
if ( V_45 [ V_83 ] )
V_64 = F_29 ( V_45 [ V_83 ] ) ;
V_25 = F_55 ( sizeof( * V_25 )
+ sizeof( struct V_85 )
* ( V_29 -> V_78 == V_79 ? 32 : 128 ) , V_86 ) ;
if ( ! V_25 )
return - V_87 ;
V_25 -> V_64 = V_64 ;
F_56 ( & V_25 -> V_88 , sizeof( V_25 -> V_88 ) ) ;
V_25 -> V_23 = V_89 ;
V_76 = F_57 ( V_73 ) ;
V_77 = F_58 ( V_76 ) ;
if ( V_77 == 0 ) {
F_59 ( V_25 ) ;
return - V_87 ;
}
V_25 -> V_90 = F_60 ( V_77 ) ;
if ( ! V_25 -> V_90 ) {
F_59 ( V_25 ) ;
return - V_87 ;
}
V_25 -> V_90 -> F_57 = V_76 ;
V_29 -> V_15 = V_25 ;
if ( V_45 [ V_22 ] ) {
V_25 -> V_23 = F_28 ( V_45 [ V_22 ] ) ;
V_29 -> V_37 = V_29 -> V_78 == V_79
? & V_91 : & V_92 ;
if ( V_29 -> V_78 == V_79 )
F_61 ( V_29 ) ;
else
F_62 ( V_29 ) ;
} else {
V_29 -> V_37 = V_29 -> V_78 == V_79
? & V_93 : & V_94 ;
}
F_63 ( L_1 ,
V_29 -> V_95 , F_64 ( V_25 -> V_90 -> F_57 ) ,
V_25 -> V_90 -> F_57 , V_25 -> V_64 , V_29 -> V_15 , V_25 -> V_90 ) ;
return 0 ;
}
static int T_5
F_65 ( void )
{
return F_66 ( & V_96 ) ;
}
static void T_6
F_67 ( void )
{
F_68 ( & V_96 ) ;
}
