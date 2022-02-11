static inline bool
F_1 ( const struct V_1 * V_2 ,
const struct V_1 * V_3 ,
T_1 * V_4 )
{
return V_2 -> V_5 == V_3 -> V_5 &&
V_2 -> V_3 == V_3 -> V_3 &&
V_2 -> V_6 == V_3 -> V_6 &&
V_2 -> V_7 == V_3 -> V_7 &&
V_2 -> V_8 == V_3 -> V_8 ;
}
static inline bool
F_2 ( const struct V_1 * V_9 )
{
return V_9 -> V_8 == 0 ;
}
static inline void
F_3 ( struct V_1 * V_10 ,
const struct V_1 * V_11 )
{
memcpy ( V_10 , V_11 , sizeof( * V_10 ) ) ;
}
static inline void
F_4 ( struct V_1 * V_9 , T_2 V_6 )
{
V_9 -> V_3 &= F_5 ( V_6 ) ;
V_9 -> V_6 = V_6 ;
}
static inline void
F_6 ( struct V_1 * V_9 )
{
V_9 -> V_8 = 0 ;
}
static bool
F_7 ( struct V_12 * V_13 ,
const struct V_1 * V_14 )
{
F_8 ( V_13 , V_15 , V_14 -> V_5 ) ;
F_8 ( V_13 , V_16 , V_14 -> V_3 ) ;
F_9 ( V_13 , V_17 , V_14 -> V_7 ) ;
F_10 ( V_13 , V_18 , V_14 -> V_6 ) ;
F_10 ( V_13 , V_19 , V_14 -> V_8 ) ;
return 0 ;
V_20:
return 1 ;
}
static bool
F_11 ( struct V_12 * V_13 ,
const struct V_1 * V_14 )
{
const struct V_21 * V_22 =
( const struct V_21 * ) V_14 ;
F_8 ( V_13 , V_15 , V_22 -> V_5 ) ;
F_8 ( V_13 , V_16 , V_22 -> V_3 ) ;
F_9 ( V_13 , V_17 , V_22 -> V_7 ) ;
F_10 ( V_13 , V_18 , V_14 -> V_6 ) ;
F_10 ( V_13 , V_19 , V_14 -> V_8 ) ;
F_12 ( V_13 , V_23 ,
F_13 ( F_14 ( V_22 -> V_24 ) ) ) ;
return 0 ;
V_20:
return 1 ;
}
static inline void
F_15 ( struct V_25 * V_26 ,
const struct V_1 * V_27 )
{
V_26 -> V_28 . V_5 = F_16 ( V_27 -> V_5 ) ;
V_26 -> V_28 . V_7 = F_17 ( V_27 -> V_7 ) ;
V_26 -> V_28 . V_3 = F_16 ( V_27 -> V_3 ) ;
}
static int
F_18 ( struct V_29 * V_30 , const struct V_12 * V_13 ,
const struct V_31 * V_32 ,
enum V_33 V_34 , const struct V_35 * V_36 )
{
const struct V_25 * V_26 = V_30 -> V_14 ;
T_3 V_37 = V_30 -> V_38 -> V_34 [ V_34 ] ;
struct V_1 V_14 = {
. V_6 = V_26 -> V_39 [ 0 ] . V_6 ? V_26 -> V_39 [ 0 ] . V_6 : V_40
} ;
if ( V_14 . V_6 == 0 )
return - V_41 ;
if ( V_34 == V_42 )
V_14 . V_6 = V_40 ;
if ( ! F_19 ( V_13 , V_36 -> V_43 & V_44 ,
& V_14 . V_7 , & V_14 . V_8 ) )
return - V_41 ;
F_20 ( V_13 , V_36 -> V_43 & V_45 , & V_14 . V_5 ) ;
F_20 ( V_13 , V_36 -> V_43 & V_46 , & V_14 . V_3 ) ;
V_14 . V_3 &= F_5 ( V_14 . V_6 ) ;
return V_37 ( V_30 , & V_14 , F_21 ( V_36 , V_26 ) , V_36 -> V_47 ) ;
}
static int
F_22 ( struct V_29 * V_30 , struct V_48 * V_49 [] ,
enum V_33 V_34 , T_1 * V_50 , T_1 V_43 , bool V_51 )
{
const struct V_25 * V_26 = V_30 -> V_14 ;
T_3 V_37 = V_30 -> V_38 -> V_34 [ V_34 ] ;
struct V_1 V_14 = { . V_6 = V_40 } ;
T_1 V_5 , V_52 , V_53 = 0 , V_7 , V_54 ;
T_1 V_55 = 0 , V_56 , V_57 , V_3 ;
T_1 V_24 = V_26 -> V_24 ;
bool V_58 = false ;
int V_59 ;
if ( F_23 ( ! V_49 [ V_15 ] || ! V_49 [ V_16 ] ||
! F_24 ( V_49 , V_17 ) ||
! F_25 ( V_49 , V_60 ) ||
! F_25 ( V_49 , V_23 ) ) )
return - V_61 ;
if ( V_49 [ V_62 ] )
* V_50 = F_26 ( V_49 [ V_62 ] ) ;
V_59 = F_27 ( V_49 [ V_15 ] , & V_5 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_27 ( V_49 [ V_16 ] , & V_55 ) ;
if ( V_59 )
return V_59 ;
if ( V_49 [ V_18 ] ) {
V_14 . V_6 = F_28 ( V_49 [ V_18 ] ) ;
if ( ! V_14 . V_6 )
return - V_63 ;
}
if ( V_49 [ V_17 ] )
V_14 . V_7 = F_29 ( V_49 [ V_17 ] ) ;
else
return - V_61 ;
if ( V_49 [ V_19 ] ) {
V_14 . V_8 = F_28 ( V_49 [ V_19 ] ) ;
V_58 = F_30 ( V_14 . V_8 ) ;
if ( V_14 . V_8 == 0 )
return - V_64 ;
} else
return - V_65 ;
if ( ! ( V_58 || V_14 . V_8 == V_66 ) )
V_14 . V_7 = 0 ;
if ( V_49 [ V_23 ] ) {
if ( ! F_31 ( V_26 -> V_24 ) )
return - V_67 ;
V_24 = F_32 ( V_49 [ V_23 ] ) ;
}
V_58 = V_58 && V_49 [ V_60 ] ;
if ( V_34 == V_42 ||
! ( V_49 [ V_68 ] || V_49 [ V_69 ] || V_58 ||
V_49 [ V_70 ] ) ) {
V_14 . V_5 = F_13 ( V_5 ) ;
V_14 . V_3 = F_13 ( V_55 & F_33 ( V_14 . V_6 ) ) ;
V_59 = V_37 ( V_30 , & V_14 , V_24 , V_43 ) ;
return F_34 ( V_59 , V_43 ) ? 0 : V_59 ;
}
if ( V_49 [ V_69 ] ) {
V_59 = F_27 ( V_49 [ V_69 ] , & V_52 ) ;
if ( V_59 )
return V_59 ;
if ( V_5 > V_52 )
F_35 ( V_5 , V_52 ) ;
} else if ( V_49 [ V_68 ] ) {
T_2 V_6 = F_28 ( V_49 [ V_68 ] ) ;
if ( V_6 > 32 )
return - V_63 ;
F_36 ( V_5 , V_52 , V_6 ) ;
}
V_54 = V_7 = F_17 ( V_14 . V_7 ) ;
if ( V_49 [ V_60 ] ) {
V_54 = F_37 ( V_49 [ V_60 ] ) ;
if ( V_7 > V_54 )
F_35 ( V_7 , V_54 ) ;
}
if ( V_49 [ V_70 ] ) {
V_59 = F_27 ( V_49 [ V_70 ] , & V_56 ) ;
if ( V_59 )
return V_59 ;
if ( V_55 > V_56 )
F_35 ( V_55 , V_56 ) ;
if ( V_55 + V_71 == V_56 )
return - V_72 ;
} else {
F_36 ( V_55 , V_56 , V_14 . V_6 ) ;
}
if ( V_51 )
V_5 = V_26 -> V_28 . V_5 ;
for (; ! F_38 ( V_52 , V_5 ) ; V_5 ++ ) {
V_14 . V_5 = F_13 ( V_5 ) ;
V_53 = V_51 && V_5 == V_26 -> V_28 . V_5 ? V_26 -> V_28 . V_7 : V_7 ;
for (; V_53 <= V_54 ; V_53 ++ ) {
V_14 . V_7 = F_39 ( V_53 ) ;
V_3 = V_51 && V_5 == V_26 -> V_28 . V_5 && V_53 == V_26 -> V_28 . V_7
? V_26 -> V_28 . V_3 : V_55 ;
while ( ! F_40 ( V_3 , V_56 ) ) {
V_14 . V_3 = F_13 ( V_3 ) ;
V_57 = F_41 ( V_3 , V_56 ,
& V_14 . V_6 ) ;
V_59 = V_37 ( V_30 , & V_14 , V_24 , V_43 ) ;
if ( V_59 && ! F_34 ( V_59 , V_43 ) )
return V_59 ;
else
V_59 = 0 ;
V_3 = V_57 + 1 ;
}
}
}
return V_59 ;
}
static bool
F_42 ( const struct V_29 * V_73 , const struct V_29 * V_74 )
{
const struct V_25 * V_75 = V_73 -> V_14 ;
const struct V_25 * V_76 = V_74 -> V_14 ;
return V_75 -> V_77 == V_76 -> V_77 &&
V_75 -> V_24 == V_76 -> V_24 ;
}
static inline bool
F_43 ( const struct V_78 * V_2 ,
const struct V_78 * V_3 ,
T_1 * V_4 )
{
return F_44 ( & V_2 -> V_5 . V_79 , & V_3 -> V_5 . V_79 ) == 0 &&
F_44 ( & V_2 -> V_3 . V_79 , & V_3 -> V_3 . V_79 ) == 0 &&
V_2 -> V_6 == V_3 -> V_6 &&
V_2 -> V_7 == V_3 -> V_7 &&
V_2 -> V_8 == V_3 -> V_8 ;
}
static inline bool
F_45 ( const struct V_78 * V_9 )
{
return V_9 -> V_8 == 0 ;
}
static inline void
F_46 ( struct V_78 * V_10 ,
const struct V_78 * V_11 )
{
memcpy ( V_10 , V_11 , sizeof( * V_10 ) ) ;
}
static inline void
F_47 ( struct V_78 * V_9 )
{
V_9 -> V_8 = 0 ;
}
static inline void
F_48 ( union V_80 * V_5 , T_2 V_81 )
{
V_5 -> V_82 [ 0 ] &= F_49 ( V_81 ) [ 0 ] ;
V_5 -> V_82 [ 1 ] &= F_49 ( V_81 ) [ 1 ] ;
V_5 -> V_82 [ 2 ] &= F_49 ( V_81 ) [ 2 ] ;
V_5 -> V_82 [ 3 ] &= F_49 ( V_81 ) [ 3 ] ;
}
static inline void
F_50 ( struct V_78 * V_9 , T_2 V_6 )
{
F_48 ( & V_9 -> V_3 , V_6 ) ;
V_9 -> V_6 = V_6 ;
}
static bool
F_51 ( struct V_12 * V_13 ,
const struct V_78 * V_14 )
{
F_52 ( V_13 , V_15 , & V_14 -> V_5 ) ;
F_52 ( V_13 , V_16 , & V_14 -> V_3 ) ;
F_9 ( V_13 , V_17 , V_14 -> V_7 ) ;
F_10 ( V_13 , V_18 , V_14 -> V_6 ) ;
F_10 ( V_13 , V_19 , V_14 -> V_8 ) ;
return 0 ;
V_20:
return 1 ;
}
static bool
F_53 ( struct V_12 * V_13 ,
const struct V_78 * V_14 )
{
const struct V_83 * V_84 =
( const struct V_83 * ) V_14 ;
F_52 ( V_13 , V_15 , & V_84 -> V_5 ) ;
F_52 ( V_13 , V_16 , & V_14 -> V_3 ) ;
F_9 ( V_13 , V_17 , V_14 -> V_7 ) ;
F_10 ( V_13 , V_18 , V_14 -> V_6 ) ;
F_10 ( V_13 , V_19 , V_14 -> V_8 ) ;
F_12 ( V_13 , V_23 ,
F_13 ( F_14 ( V_84 -> V_24 ) ) ) ;
return 0 ;
V_20:
return 1 ;
}
static inline void
F_54 ( struct V_25 * V_26 ,
const struct V_78 * V_27 )
{
V_26 -> V_28 . V_7 = F_17 ( V_27 -> V_7 ) ;
}
static int
F_55 ( struct V_29 * V_30 , const struct V_12 * V_13 ,
const struct V_31 * V_32 ,
enum V_33 V_34 , const struct V_35 * V_36 )
{
const struct V_25 * V_26 = V_30 -> V_14 ;
T_3 V_37 = V_30 -> V_38 -> V_34 [ V_34 ] ;
struct V_78 V_14 = {
. V_6 = V_26 -> V_39 [ 0 ] . V_6 ? V_26 -> V_39 [ 0 ] . V_6 : V_40
} ;
if ( V_14 . V_6 == 0 )
return - V_41 ;
if ( V_34 == V_42 )
V_14 . V_6 = V_40 ;
if ( ! F_56 ( V_13 , V_36 -> V_43 & V_44 ,
& V_14 . V_7 , & V_14 . V_8 ) )
return - V_41 ;
F_57 ( V_13 , V_36 -> V_43 & V_45 , & V_14 . V_5 . V_79 ) ;
F_57 ( V_13 , V_36 -> V_43 & V_46 , & V_14 . V_3 . V_79 ) ;
F_48 ( & V_14 . V_3 , V_14 . V_6 ) ;
return V_37 ( V_30 , & V_14 , F_21 ( V_36 , V_26 ) , V_36 -> V_47 ) ;
}
static int
F_58 ( struct V_29 * V_30 , struct V_48 * V_49 [] ,
enum V_33 V_34 , T_1 * V_50 , T_1 V_43 , bool V_51 )
{
const struct V_25 * V_26 = V_30 -> V_14 ;
T_3 V_37 = V_30 -> V_38 -> V_34 [ V_34 ] ;
struct V_78 V_14 = { . V_6 = V_40 } ;
T_1 V_7 , V_54 ;
T_1 V_24 = V_26 -> V_24 ;
bool V_58 = false ;
int V_59 ;
if ( F_23 ( ! V_49 [ V_15 ] || ! V_49 [ V_16 ] ||
! F_24 ( V_49 , V_17 ) ||
! F_25 ( V_49 , V_60 ) ||
! F_25 ( V_49 , V_23 ) ||
V_49 [ V_69 ] ||
V_49 [ V_68 ] ) )
return - V_61 ;
if ( F_23 ( V_49 [ V_69 ] ) )
return - V_85 ;
if ( V_49 [ V_62 ] )
* V_50 = F_26 ( V_49 [ V_62 ] ) ;
V_59 = F_59 ( V_49 [ V_15 ] , & V_14 . V_5 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_59 ( V_49 [ V_16 ] , & V_14 . V_3 ) ;
if ( V_59 )
return V_59 ;
if ( V_49 [ V_18 ] )
V_14 . V_6 = F_28 ( V_49 [ V_18 ] ) ;
if ( ! V_14 . V_6 )
return - V_63 ;
F_48 ( & V_14 . V_3 , V_14 . V_6 ) ;
if ( V_49 [ V_17 ] )
V_14 . V_7 = F_29 ( V_49 [ V_17 ] ) ;
else
return - V_61 ;
if ( V_49 [ V_19 ] ) {
V_14 . V_8 = F_28 ( V_49 [ V_19 ] ) ;
V_58 = F_30 ( V_14 . V_8 ) ;
if ( V_14 . V_8 == 0 )
return - V_64 ;
} else
return - V_65 ;
if ( ! ( V_58 || V_14 . V_8 == V_86 ) )
V_14 . V_7 = 0 ;
if ( V_49 [ V_23 ] ) {
if ( ! F_31 ( V_26 -> V_24 ) )
return - V_67 ;
V_24 = F_32 ( V_49 [ V_23 ] ) ;
}
if ( V_34 == V_42 || ! V_58 || ! V_49 [ V_60 ] ) {
V_59 = V_37 ( V_30 , & V_14 , V_24 , V_43 ) ;
return F_34 ( V_59 , V_43 ) ? 0 : V_59 ;
}
V_7 = F_17 ( V_14 . V_7 ) ;
V_54 = F_37 ( V_49 [ V_60 ] ) ;
if ( V_7 > V_54 )
F_35 ( V_7 , V_54 ) ;
if ( V_51 )
V_7 = V_26 -> V_28 . V_7 ;
for (; V_7 <= V_54 ; V_7 ++ ) {
V_14 . V_7 = F_39 ( V_7 ) ;
V_59 = V_37 ( V_30 , & V_14 , V_24 , V_43 ) ;
if ( V_59 && ! F_34 ( V_59 , V_43 ) )
return V_59 ;
else
V_59 = 0 ;
}
return V_59 ;
}
static int
F_60 ( struct V_29 * V_30 , struct V_48 * V_49 [] , T_1 V_43 )
{
struct V_25 * V_26 ;
T_1 V_87 = V_88 , V_77 = V_89 ;
T_2 V_90 ;
if ( ! ( V_30 -> V_91 == V_92 || V_30 -> V_91 == V_93 ) )
return - V_94 ;
if ( F_23 ( ! F_25 ( V_49 , V_95 ) ||
! F_25 ( V_49 , V_96 ) ||
! F_25 ( V_49 , V_23 ) ) )
return - V_61 ;
if ( V_49 [ V_95 ] ) {
V_87 = F_61 ( V_49 [ V_95 ] ) ;
if ( V_87 < V_97 )
V_87 = V_97 ;
}
if ( V_49 [ V_96 ] )
V_77 = F_61 ( V_49 [ V_96 ] ) ;
V_26 = F_62 ( sizeof( * V_26 )
+ sizeof( struct V_98 )
* ( V_30 -> V_91 == V_92 ? 32 : 128 ) , V_99 ) ;
if ( ! V_26 )
return - V_100 ;
V_26 -> V_77 = V_77 ;
F_63 ( & V_26 -> V_101 , sizeof( V_26 -> V_101 ) ) ;
V_26 -> V_24 = V_102 ;
V_90 = F_64 ( V_87 ) ;
V_26 -> V_103 = F_65 (
sizeof( struct V_104 )
+ F_66 ( V_90 ) * sizeof( struct V_105 ) ) ;
if ( ! V_26 -> V_103 ) {
F_67 ( V_26 ) ;
return - V_100 ;
}
V_26 -> V_103 -> F_64 = V_90 ;
V_30 -> V_14 = V_26 ;
if ( V_49 [ V_23 ] ) {
V_26 -> V_24 = F_32 ( V_49 [ V_23 ] ) ;
V_30 -> V_38 = V_30 -> V_91 == V_92
? & V_106
: & V_107 ;
if ( V_30 -> V_91 == V_92 )
F_68 ( V_30 ) ;
else
F_69 ( V_30 ) ;
} else {
V_30 -> V_38 = V_30 -> V_91 == V_92
? & V_108 : & V_109 ;
}
F_70 ( L_1 ,
V_30 -> V_110 , F_66 ( V_26 -> V_103 -> F_64 ) ,
V_26 -> V_103 -> F_64 , V_26 -> V_77 , V_30 -> V_14 , V_26 -> V_103 ) ;
return 0 ;
}
static int T_4
F_71 ( void )
{
return F_72 ( & V_111 ) ;
}
static void T_5
F_73 ( void )
{
F_74 ( & V_111 ) ;
}
