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
F_4 ( struct V_1 * V_10 , T_1 V_12 )
{
V_10 -> V_13 = ! ! ( V_12 & V_14 ) ;
}
static inline bool
F_5 ( const struct V_1 * V_9 )
{
return ! V_9 -> V_13 ;
}
static inline void
F_6 ( struct V_1 * V_9 , T_2 V_6 )
{
V_9 -> V_3 &= F_7 ( V_6 ) ;
V_9 -> V_6 = V_6 - 1 ;
}
static inline void
F_8 ( struct V_1 * V_9 )
{
V_9 -> V_8 = 0 ;
}
static bool
F_9 ( struct V_15 * V_16 ,
const struct V_1 * V_17 )
{
T_1 V_12 = V_17 -> V_13 ? V_14 : 0 ;
F_10 ( V_16 , V_18 , V_17 -> V_5 ) ;
F_10 ( V_16 , V_19 , V_17 -> V_3 ) ;
F_11 ( V_16 , V_20 , V_17 -> V_7 ) ;
F_12 ( V_16 , V_21 , V_17 -> V_6 + 1 ) ;
F_12 ( V_16 , V_22 , V_17 -> V_8 ) ;
if ( V_12 )
F_13 ( V_16 , V_23 , F_14 ( V_12 ) ) ;
return 0 ;
V_24:
return 1 ;
}
static bool
F_15 ( struct V_15 * V_16 ,
const struct V_1 * V_17 )
{
const struct V_25 * V_26 =
( const struct V_25 * ) V_17 ;
T_1 V_12 = V_17 -> V_13 ? V_14 : 0 ;
F_10 ( V_16 , V_18 , V_26 -> V_5 ) ;
F_10 ( V_16 , V_19 , V_26 -> V_3 ) ;
F_11 ( V_16 , V_20 , V_26 -> V_7 ) ;
F_12 ( V_16 , V_21 , V_17 -> V_6 + 1 ) ;
F_12 ( V_16 , V_22 , V_17 -> V_8 ) ;
F_13 ( V_16 , V_27 ,
F_14 ( F_16 ( V_26 -> V_28 ) ) ) ;
if ( V_12 )
F_13 ( V_16 , V_23 , F_14 ( V_12 ) ) ;
return 0 ;
V_24:
return 1 ;
}
static inline void
F_17 ( struct V_29 * V_30 ,
const struct V_1 * V_31 )
{
V_30 -> V_32 . V_5 = F_18 ( V_31 -> V_5 ) ;
V_30 -> V_32 . V_7 = F_19 ( V_31 -> V_7 ) ;
V_30 -> V_32 . V_3 = F_18 ( V_31 -> V_3 ) ;
}
static int
F_20 ( struct V_33 * V_34 , const struct V_15 * V_16 ,
const struct V_35 * V_36 ,
enum V_37 V_38 , const struct V_39 * V_40 )
{
const struct V_29 * V_30 = V_34 -> V_17 ;
T_3 V_41 = V_34 -> V_42 -> V_38 [ V_38 ] ;
struct V_1 V_17 = {
. V_6 = V_30 -> V_43 [ 0 ] . V_6 ? V_30 -> V_43 [ 0 ] . V_6 - 1 : V_44 - 1
} ;
if ( V_38 == V_45 )
V_17 . V_6 = V_44 - 1 ;
if ( ! F_21 ( V_16 , V_40 -> V_12 & V_46 ,
& V_17 . V_7 , & V_17 . V_8 ) )
return - V_47 ;
F_22 ( V_16 , V_40 -> V_12 & V_48 , & V_17 . V_5 ) ;
F_22 ( V_16 , V_40 -> V_12 & V_49 , & V_17 . V_3 ) ;
V_17 . V_3 &= F_7 ( V_17 . V_6 + 1 ) ;
return V_41 ( V_34 , & V_17 , F_23 ( V_40 , V_30 ) , V_40 -> V_50 ) ;
}
static int
F_24 ( struct V_33 * V_34 , struct V_51 * V_52 [] ,
enum V_37 V_38 , T_1 * V_53 , T_1 V_12 , bool V_54 )
{
const struct V_29 * V_30 = V_34 -> V_17 ;
T_3 V_41 = V_34 -> V_42 -> V_38 [ V_38 ] ;
struct V_1 V_17 = { . V_6 = V_44 - 1 } ;
T_1 V_5 , V_55 = 0 , V_56 = 0 , V_7 , V_57 ;
T_1 V_58 = 0 , V_59 , V_60 , V_3 ;
T_1 V_28 = V_30 -> V_28 ;
bool V_61 = false ;
T_2 V_6 ;
int V_62 ;
if ( F_25 ( ! V_52 [ V_18 ] || ! V_52 [ V_19 ] ||
! F_26 ( V_52 , V_20 ) ||
! F_27 ( V_52 , V_63 ) ||
! F_27 ( V_52 , V_27 ) ||
! F_27 ( V_52 , V_23 ) ) )
return - V_64 ;
if ( V_52 [ V_65 ] )
* V_53 = F_28 ( V_52 [ V_65 ] ) ;
V_62 = F_29 ( V_52 [ V_18 ] , & V_5 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_29 ( V_52 [ V_19 ] , & V_58 ) ;
if ( V_62 )
return V_62 ;
if ( V_52 [ V_21 ] ) {
V_6 = F_30 ( V_52 [ V_21 ] ) ;
if ( ! V_6 || V_6 > V_44 )
return - V_66 ;
V_17 . V_6 = V_6 - 1 ;
}
if ( V_52 [ V_20 ] )
V_17 . V_7 = F_31 ( V_52 [ V_20 ] ) ;
else
return - V_64 ;
if ( V_52 [ V_22 ] ) {
V_17 . V_8 = F_30 ( V_52 [ V_22 ] ) ;
V_61 = F_32 ( V_17 . V_8 ) ;
if ( V_17 . V_8 == 0 )
return - V_67 ;
} else
return - V_68 ;
if ( ! ( V_61 || V_17 . V_8 == V_69 ) )
V_17 . V_7 = 0 ;
if ( V_52 [ V_27 ] ) {
if ( ! F_33 ( V_30 -> V_28 ) )
return - V_70 ;
V_28 = F_34 ( V_52 [ V_27 ] ) ;
}
if ( V_52 [ V_23 ] && V_38 == V_71 ) {
T_1 V_72 = F_35 ( V_52 [ V_23 ] ) ;
if ( V_72 & V_14 )
V_12 |= ( V_72 << 16 ) ;
}
V_61 = V_61 && V_52 [ V_63 ] ;
if ( V_38 == V_45 ||
! ( V_52 [ V_73 ] || V_52 [ V_74 ] || V_61 ||
V_52 [ V_75 ] ) ) {
V_17 . V_5 = F_14 ( V_5 ) ;
V_17 . V_3 = F_14 ( V_58 & F_36 ( V_17 . V_6 + 1 ) ) ;
V_62 = V_41 ( V_34 , & V_17 , V_28 , V_12 ) ;
return F_37 ( V_62 , V_12 ) ? 0 : V_62 ;
}
if ( V_52 [ V_74 ] ) {
V_62 = F_29 ( V_52 [ V_74 ] , & V_55 ) ;
if ( V_62 )
return V_62 ;
if ( V_5 > V_55 )
F_38 ( V_5 , V_55 ) ;
} else if ( V_52 [ V_73 ] ) {
T_2 V_6 = F_30 ( V_52 [ V_73 ] ) ;
if ( V_6 > 32 )
return - V_66 ;
F_39 ( V_5 , V_55 , V_6 ) ;
}
V_57 = V_7 = F_19 ( V_17 . V_7 ) ;
if ( V_52 [ V_63 ] ) {
V_57 = F_40 ( V_52 [ V_63 ] ) ;
if ( V_7 > V_57 )
F_38 ( V_7 , V_57 ) ;
}
if ( V_52 [ V_75 ] ) {
V_62 = F_29 ( V_52 [ V_75 ] , & V_59 ) ;
if ( V_62 )
return V_62 ;
if ( V_58 > V_59 )
F_38 ( V_58 , V_59 ) ;
if ( V_58 + V_76 == V_59 )
return - V_77 ;
} else {
F_39 ( V_58 , V_59 , V_17 . V_6 + 1 ) ;
}
if ( V_54 )
V_5 = V_30 -> V_32 . V_5 ;
for (; ! F_41 ( V_55 , V_5 ) ; V_5 ++ ) {
V_17 . V_5 = F_14 ( V_5 ) ;
V_56 = V_54 && V_5 == V_30 -> V_32 . V_5 ? V_30 -> V_32 . V_7 : V_7 ;
for (; V_56 <= V_57 ; V_56 ++ ) {
V_17 . V_7 = F_42 ( V_56 ) ;
V_3 = V_54 && V_5 == V_30 -> V_32 . V_5 && V_56 == V_30 -> V_32 . V_7
? V_30 -> V_32 . V_3 : V_58 ;
while ( ! F_43 ( V_3 , V_59 ) ) {
V_17 . V_3 = F_14 ( V_3 ) ;
V_60 = F_44 ( V_3 , V_59 ,
& V_6 ) ;
V_17 . V_6 = V_6 - 1 ;
V_62 = V_41 ( V_34 , & V_17 , V_28 , V_12 ) ;
if ( V_62 && ! F_37 ( V_62 , V_12 ) )
return V_62 ;
else
V_62 = 0 ;
V_3 = V_60 + 1 ;
}
}
}
return V_62 ;
}
static bool
F_45 ( const struct V_33 * V_78 , const struct V_33 * V_79 )
{
const struct V_29 * V_80 = V_78 -> V_17 ;
const struct V_29 * V_81 = V_79 -> V_17 ;
return V_80 -> V_82 == V_81 -> V_82 &&
V_80 -> V_28 == V_81 -> V_28 ;
}
static inline bool
F_46 ( const struct V_83 * V_2 ,
const struct V_83 * V_3 ,
T_1 * V_4 )
{
return F_47 ( & V_2 -> V_5 . V_84 , & V_3 -> V_5 . V_84 ) == 0 &&
F_47 ( & V_2 -> V_3 . V_84 , & V_3 -> V_3 . V_84 ) == 0 &&
V_2 -> V_6 == V_3 -> V_6 &&
V_2 -> V_7 == V_3 -> V_7 &&
V_2 -> V_8 == V_3 -> V_8 ;
}
static inline bool
F_48 ( const struct V_83 * V_9 )
{
return V_9 -> V_8 == 0 ;
}
static inline void
F_49 ( struct V_83 * V_10 ,
const struct V_83 * V_11 )
{
memcpy ( V_10 , V_11 , sizeof( * V_10 ) ) ;
}
static inline void
F_50 ( struct V_83 * V_10 , T_1 V_12 )
{
V_10 -> V_13 = ! ! ( V_12 & V_14 ) ;
}
static inline bool
F_51 ( const struct V_83 * V_9 )
{
return ! V_9 -> V_13 ;
}
static inline void
F_52 ( struct V_83 * V_9 )
{
V_9 -> V_8 = 0 ;
}
static inline void
F_53 ( union V_85 * V_5 , T_2 V_86 )
{
V_5 -> V_87 [ 0 ] &= F_54 ( V_86 ) [ 0 ] ;
V_5 -> V_87 [ 1 ] &= F_54 ( V_86 ) [ 1 ] ;
V_5 -> V_87 [ 2 ] &= F_54 ( V_86 ) [ 2 ] ;
V_5 -> V_87 [ 3 ] &= F_54 ( V_86 ) [ 3 ] ;
}
static inline void
F_55 ( struct V_83 * V_9 , T_2 V_6 )
{
F_53 ( & V_9 -> V_3 , V_6 ) ;
V_9 -> V_6 = V_6 - 1 ;
}
static bool
F_56 ( struct V_15 * V_16 ,
const struct V_83 * V_17 )
{
T_1 V_12 = V_17 -> V_13 ? V_14 : 0 ;
F_57 ( V_16 , V_18 , & V_17 -> V_5 ) ;
F_57 ( V_16 , V_19 , & V_17 -> V_3 ) ;
F_11 ( V_16 , V_20 , V_17 -> V_7 ) ;
F_12 ( V_16 , V_21 , V_17 -> V_6 + 1 ) ;
F_12 ( V_16 , V_22 , V_17 -> V_8 ) ;
if ( V_12 )
F_13 ( V_16 , V_23 , F_14 ( V_12 ) ) ;
return 0 ;
V_24:
return 1 ;
}
static bool
F_58 ( struct V_15 * V_16 ,
const struct V_83 * V_17 )
{
const struct V_88 * V_89 =
( const struct V_88 * ) V_17 ;
T_1 V_12 = V_17 -> V_13 ? V_14 : 0 ;
F_57 ( V_16 , V_18 , & V_89 -> V_5 ) ;
F_57 ( V_16 , V_19 , & V_17 -> V_3 ) ;
F_11 ( V_16 , V_20 , V_17 -> V_7 ) ;
F_12 ( V_16 , V_21 , V_17 -> V_6 + 1 ) ;
F_12 ( V_16 , V_22 , V_17 -> V_8 ) ;
F_13 ( V_16 , V_27 ,
F_14 ( F_16 ( V_89 -> V_28 ) ) ) ;
if ( V_12 )
F_13 ( V_16 , V_23 , F_14 ( V_12 ) ) ;
return 0 ;
V_24:
return 1 ;
}
static inline void
F_59 ( struct V_29 * V_30 ,
const struct V_83 * V_31 )
{
V_30 -> V_32 . V_7 = F_19 ( V_31 -> V_7 ) ;
}
static int
F_60 ( struct V_33 * V_34 , const struct V_15 * V_16 ,
const struct V_35 * V_36 ,
enum V_37 V_38 , const struct V_39 * V_40 )
{
const struct V_29 * V_30 = V_34 -> V_17 ;
T_3 V_41 = V_34 -> V_42 -> V_38 [ V_38 ] ;
struct V_83 V_17 = {
. V_6 = V_30 -> V_43 [ 0 ] . V_6 ? V_30 -> V_43 [ 0 ] . V_6 - 1 : V_44 - 1
} ;
if ( V_38 == V_45 )
V_17 . V_6 = V_44 - 1 ;
if ( ! F_61 ( V_16 , V_40 -> V_12 & V_46 ,
& V_17 . V_7 , & V_17 . V_8 ) )
return - V_47 ;
F_62 ( V_16 , V_40 -> V_12 & V_48 , & V_17 . V_5 . V_84 ) ;
F_62 ( V_16 , V_40 -> V_12 & V_49 , & V_17 . V_3 . V_84 ) ;
F_53 ( & V_17 . V_3 , V_17 . V_6 + 1 ) ;
return V_41 ( V_34 , & V_17 , F_23 ( V_40 , V_30 ) , V_40 -> V_50 ) ;
}
static int
F_63 ( struct V_33 * V_34 , struct V_51 * V_52 [] ,
enum V_37 V_38 , T_1 * V_53 , T_1 V_12 , bool V_54 )
{
const struct V_29 * V_30 = V_34 -> V_17 ;
T_3 V_41 = V_34 -> V_42 -> V_38 [ V_38 ] ;
struct V_83 V_17 = { . V_6 = V_44 - 1 } ;
T_1 V_7 , V_57 ;
T_1 V_28 = V_30 -> V_28 ;
bool V_61 = false ;
T_2 V_6 ;
int V_62 ;
if ( F_25 ( ! V_52 [ V_18 ] || ! V_52 [ V_19 ] ||
! F_26 ( V_52 , V_20 ) ||
! F_27 ( V_52 , V_63 ) ||
! F_27 ( V_52 , V_27 ) ||
! F_27 ( V_52 , V_23 ) ||
V_52 [ V_74 ] ||
V_52 [ V_73 ] ) )
return - V_64 ;
if ( F_25 ( V_52 [ V_74 ] ) )
return - V_90 ;
if ( V_52 [ V_65 ] )
* V_53 = F_28 ( V_52 [ V_65 ] ) ;
V_62 = F_64 ( V_52 [ V_18 ] , & V_17 . V_5 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_64 ( V_52 [ V_19 ] , & V_17 . V_3 ) ;
if ( V_62 )
return V_62 ;
if ( V_52 [ V_21 ] ) {
V_6 = F_30 ( V_52 [ V_21 ] ) ;
if ( ! V_6 || V_6 > V_44 )
return - V_66 ;
V_17 . V_6 = V_6 - 1 ;
}
F_53 ( & V_17 . V_3 , V_17 . V_6 + 1 ) ;
if ( V_52 [ V_20 ] )
V_17 . V_7 = F_31 ( V_52 [ V_20 ] ) ;
else
return - V_64 ;
if ( V_52 [ V_22 ] ) {
V_17 . V_8 = F_30 ( V_52 [ V_22 ] ) ;
V_61 = F_32 ( V_17 . V_8 ) ;
if ( V_17 . V_8 == 0 )
return - V_67 ;
} else
return - V_68 ;
if ( ! ( V_61 || V_17 . V_8 == V_91 ) )
V_17 . V_7 = 0 ;
if ( V_52 [ V_27 ] ) {
if ( ! F_33 ( V_30 -> V_28 ) )
return - V_70 ;
V_28 = F_34 ( V_52 [ V_27 ] ) ;
}
if ( V_52 [ V_23 ] && V_38 == V_71 ) {
T_1 V_72 = F_35 ( V_52 [ V_23 ] ) ;
if ( V_72 & V_14 )
V_12 |= ( V_72 << 16 ) ;
}
if ( V_38 == V_45 || ! V_61 || ! V_52 [ V_63 ] ) {
V_62 = V_41 ( V_34 , & V_17 , V_28 , V_12 ) ;
return F_37 ( V_62 , V_12 ) ? 0 : V_62 ;
}
V_7 = F_19 ( V_17 . V_7 ) ;
V_57 = F_40 ( V_52 [ V_63 ] ) ;
if ( V_7 > V_57 )
F_38 ( V_7 , V_57 ) ;
if ( V_54 )
V_7 = V_30 -> V_32 . V_7 ;
for (; V_7 <= V_57 ; V_7 ++ ) {
V_17 . V_7 = F_42 ( V_7 ) ;
V_62 = V_41 ( V_34 , & V_17 , V_28 , V_12 ) ;
if ( V_62 && ! F_37 ( V_62 , V_12 ) )
return V_62 ;
else
V_62 = 0 ;
}
return V_62 ;
}
static int
F_65 ( struct V_33 * V_34 , struct V_51 * V_52 [] , T_1 V_12 )
{
struct V_29 * V_30 ;
T_1 V_92 = V_93 , V_82 = V_94 ;
T_2 V_95 ;
T_4 V_96 ;
if ( ! ( V_34 -> V_97 == V_98 || V_34 -> V_97 == V_99 ) )
return - V_100 ;
if ( F_25 ( ! F_27 ( V_52 , V_101 ) ||
! F_27 ( V_52 , V_102 ) ||
! F_27 ( V_52 , V_27 ) ) )
return - V_64 ;
if ( V_52 [ V_101 ] ) {
V_92 = F_35 ( V_52 [ V_101 ] ) ;
if ( V_92 < V_103 )
V_92 = V_103 ;
}
if ( V_52 [ V_102 ] )
V_82 = F_35 ( V_52 [ V_102 ] ) ;
V_30 = F_66 ( sizeof( * V_30 )
+ sizeof( struct V_104 )
* ( V_34 -> V_97 == V_98 ? 32 : 128 ) , V_105 ) ;
if ( ! V_30 )
return - V_106 ;
V_30 -> V_82 = V_82 ;
F_67 ( & V_30 -> V_107 , sizeof( V_30 -> V_107 ) ) ;
V_30 -> V_28 = V_108 ;
V_95 = F_68 ( V_92 ) ;
V_96 = F_69 ( V_95 ) ;
if ( V_96 == 0 ) {
F_70 ( V_30 ) ;
return - V_106 ;
}
V_30 -> V_109 = F_71 ( V_96 ) ;
if ( ! V_30 -> V_109 ) {
F_70 ( V_30 ) ;
return - V_106 ;
}
V_30 -> V_109 -> F_68 = V_95 ;
V_34 -> V_17 = V_30 ;
if ( V_52 [ V_27 ] ) {
V_30 -> V_28 = F_34 ( V_52 [ V_27 ] ) ;
V_34 -> V_42 = V_34 -> V_97 == V_98
? & V_110
: & V_111 ;
if ( V_34 -> V_97 == V_98 )
F_72 ( V_34 ) ;
else
F_73 ( V_34 ) ;
} else {
V_34 -> V_42 = V_34 -> V_97 == V_98
? & V_112 : & V_113 ;
}
F_74 ( L_1 ,
V_34 -> V_114 , F_75 ( V_30 -> V_109 -> F_68 ) ,
V_30 -> V_109 -> F_68 , V_30 -> V_82 , V_34 -> V_17 , V_30 -> V_109 ) ;
return 0 ;
}
static int T_5
F_76 ( void )
{
return F_77 ( & V_115 ) ;
}
static void T_6
F_78 ( void )
{
F_79 ( & V_115 ) ;
}
