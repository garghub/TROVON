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
V_10 -> V_12 = V_11 -> V_12 ;
}
static inline void
F_4 ( struct V_1 * V_10 , T_1 V_13 )
{
V_10 -> V_12 = ! ! ( V_13 & V_14 ) ;
}
static inline int
F_5 ( const struct V_1 * V_9 )
{
return V_9 -> V_12 ? - V_15 : 1 ;
}
static inline void
F_6 ( struct V_1 * V_9 , T_2 V_8 )
{
V_9 -> V_5 &= F_7 ( V_8 ) ;
V_9 -> V_8 = V_8 - 1 ;
}
static inline void
F_8 ( struct V_1 * V_9 )
{
V_9 -> V_7 = 0 ;
}
static bool
F_9 ( struct V_16 * V_17 ,
const struct V_1 * V_18 )
{
T_1 V_13 = V_18 -> V_12 ? V_14 : 0 ;
if ( F_10 ( V_17 , V_19 , V_18 -> V_5 ) ||
F_11 ( V_17 , V_20 , V_18 -> V_6 ) ||
F_12 ( V_17 , V_21 , V_18 -> V_8 + 1 ) ||
F_12 ( V_17 , V_22 , V_18 -> V_7 ) ||
( V_13 &&
F_13 ( V_17 , V_23 , F_14 ( V_13 ) ) ) )
goto V_24;
return 0 ;
V_24:
return 1 ;
}
static bool
F_15 ( struct V_16 * V_17 ,
const struct V_1 * V_18 )
{
const struct V_25 * V_26 =
( const struct V_25 * ) V_18 ;
T_1 V_13 = V_18 -> V_12 ? V_14 : 0 ;
if ( F_10 ( V_17 , V_19 , V_26 -> V_5 ) ||
F_11 ( V_17 , V_20 , V_26 -> V_6 ) ||
F_12 ( V_17 , V_21 , V_18 -> V_8 + 1 ) ||
F_12 ( V_17 , V_22 , V_18 -> V_7 ) ||
F_13 ( V_17 , V_27 ,
F_14 ( F_16 ( V_26 -> V_28 ) ) ) ||
( V_13 &&
F_13 ( V_17 , V_23 , F_14 ( V_13 ) ) ) )
goto V_24;
return 0 ;
V_24:
return 1 ;
}
static inline void
F_17 ( struct V_29 * V_30 ,
const struct V_1 * V_31 )
{
V_30 -> V_32 . V_5 = V_31 -> V_5 ;
V_30 -> V_32 . V_6 = V_31 -> V_6 ;
}
static int
F_18 ( struct V_33 * V_34 , const struct V_16 * V_17 ,
const struct V_35 * V_36 ,
enum V_37 V_38 , const struct V_39 * V_40 )
{
const struct V_29 * V_30 = V_34 -> V_18 ;
T_3 V_41 = V_34 -> V_42 -> V_38 [ V_38 ] ;
struct V_1 V_18 = {
. V_8 = V_30 -> V_43 [ 0 ] . V_8 ? V_30 -> V_43 [ 0 ] . V_8 - 1 : V_44 - 1
} ;
if ( V_38 == V_45 )
V_18 . V_8 = V_44 - 1 ;
if ( ! F_19 ( V_17 , V_40 -> V_13 & V_46 ,
& V_18 . V_6 , & V_18 . V_7 ) )
return - V_47 ;
F_20 ( V_17 , V_40 -> V_13 & V_48 , & V_18 . V_5 ) ;
V_18 . V_5 &= F_7 ( V_18 . V_8 + 1 ) ;
return V_41 ( V_34 , & V_18 , F_21 ( V_40 , V_30 ) , V_40 -> V_49 ) ;
}
static int
F_22 ( struct V_33 * V_34 , struct V_50 * V_51 [] ,
enum V_37 V_38 , T_1 * V_52 , T_1 V_13 , bool V_53 )
{
const struct V_29 * V_30 = V_34 -> V_18 ;
T_3 V_41 = V_34 -> V_42 -> V_38 [ V_38 ] ;
struct V_1 V_18 = { . V_8 = V_44 - 1 } ;
T_1 V_6 , V_54 , V_55 = 0 , V_5 = 0 , V_56 , V_57 ;
T_1 V_28 = V_30 -> V_28 ;
bool V_58 = false ;
T_2 V_8 ;
int V_59 ;
if ( F_23 ( ! V_51 [ V_19 ] ||
! F_24 ( V_51 , V_20 ) ||
! F_25 ( V_51 , V_60 ) ||
! F_25 ( V_51 , V_27 ) ||
! F_25 ( V_51 , V_23 ) ) )
return - V_61 ;
if ( V_51 [ V_62 ] )
* V_52 = F_26 ( V_51 [ V_62 ] ) ;
V_59 = F_27 ( V_51 [ V_19 ] , & V_5 ) ;
if ( V_59 )
return V_59 ;
if ( V_51 [ V_21 ] ) {
V_8 = F_28 ( V_51 [ V_21 ] ) ;
if ( ! V_8 || V_8 > V_44 )
return - V_63 ;
V_18 . V_8 = V_8 - 1 ;
}
if ( V_51 [ V_20 ] )
V_18 . V_6 = F_29 ( V_51 [ V_20 ] ) ;
else
return - V_61 ;
if ( V_51 [ V_22 ] ) {
V_18 . V_7 = F_28 ( V_51 [ V_22 ] ) ;
V_58 = F_30 ( V_18 . V_7 ) ;
if ( V_18 . V_7 == 0 )
return - V_64 ;
} else
return - V_65 ;
if ( ! ( V_58 || V_18 . V_7 == V_66 ) )
V_18 . V_6 = 0 ;
if ( V_51 [ V_27 ] ) {
if ( ! F_31 ( V_30 -> V_28 ) )
return - V_67 ;
V_28 = F_32 ( V_51 [ V_27 ] ) ;
}
V_58 = V_58 && V_51 [ V_60 ] ;
if ( V_51 [ V_23 ] && V_38 == V_68 ) {
T_1 V_69 = F_33 ( V_51 [ V_23 ] ) ;
if ( V_69 & V_14 )
V_13 |= ( V_69 << 16 ) ;
}
if ( V_38 == V_45 || ! ( V_58 || V_51 [ V_70 ] ) ) {
V_18 . V_5 = F_14 ( V_5 & F_34 ( V_18 . V_8 + 1 ) ) ;
V_59 = V_41 ( V_34 , & V_18 , V_28 , V_13 ) ;
return F_35 ( V_59 , V_13 ) ? 0 : V_59 ;
}
V_6 = V_54 = F_36 ( V_18 . V_6 ) ;
if ( V_51 [ V_60 ] ) {
V_54 = F_37 ( V_51 [ V_60 ] ) ;
if ( V_54 < V_6 )
F_38 ( V_6 , V_54 ) ;
}
if ( V_51 [ V_70 ] ) {
V_59 = F_27 ( V_51 [ V_70 ] , & V_56 ) ;
if ( V_59 )
return V_59 ;
if ( V_56 < V_5 )
F_38 ( V_5 , V_56 ) ;
if ( V_5 + V_71 == V_56 )
return - V_72 ;
} else {
F_39 ( V_5 , V_56 , V_18 . V_8 + 1 ) ;
}
if ( V_53 )
V_5 = F_40 ( V_30 -> V_32 . V_5 ) ;
while ( ! F_41 ( V_5 , V_56 ) ) {
V_18 . V_5 = F_14 ( V_5 ) ;
V_57 = F_42 ( V_5 , V_56 , & V_8 ) ;
V_18 . V_8 = V_8 - 1 ;
V_55 = V_53 && V_5 == F_40 ( V_30 -> V_32 . V_5 ) ? F_36 ( V_30 -> V_32 . V_6 )
: V_6 ;
for (; V_55 <= V_54 ; V_55 ++ ) {
V_18 . V_6 = F_43 ( V_55 ) ;
V_59 = V_41 ( V_34 , & V_18 , V_28 , V_13 ) ;
if ( V_59 && ! F_35 ( V_59 , V_13 ) )
return V_59 ;
else
V_59 = 0 ;
}
V_5 = V_57 + 1 ;
}
return V_59 ;
}
static bool
F_44 ( const struct V_33 * V_73 , const struct V_33 * V_74 )
{
const struct V_29 * V_75 = V_73 -> V_18 ;
const struct V_29 * V_76 = V_74 -> V_18 ;
return V_75 -> V_77 == V_76 -> V_77 &&
V_75 -> V_28 == V_76 -> V_28 ;
}
static inline bool
F_45 ( const struct V_78 * V_2 ,
const struct V_78 * V_3 ,
T_1 * V_4 )
{
return F_46 ( & V_2 -> V_5 . V_79 , & V_3 -> V_5 . V_79 ) == 0 &&
V_2 -> V_6 == V_3 -> V_6 &&
V_2 -> V_7 == V_3 -> V_7 &&
V_2 -> V_8 == V_3 -> V_8 ;
}
static inline bool
F_47 ( const struct V_78 * V_9 )
{
return V_9 -> V_7 == 0 ;
}
static inline void
F_48 ( struct V_78 * V_10 ,
const struct V_78 * V_11 )
{
memcpy ( V_10 , V_11 , sizeof( * V_10 ) ) ;
}
static inline void
F_49 ( struct V_78 * V_10 , T_1 V_13 )
{
V_10 -> V_12 = ! ! ( V_13 & V_14 ) ;
}
static inline int
F_50 ( const struct V_78 * V_9 )
{
return V_9 -> V_12 ? - V_15 : 1 ;
}
static inline void
F_51 ( struct V_78 * V_9 )
{
V_9 -> V_7 = 0 ;
}
static inline void
F_52 ( union V_80 * V_5 , T_2 V_81 )
{
V_5 -> V_82 [ 0 ] &= F_53 ( V_81 ) [ 0 ] ;
V_5 -> V_82 [ 1 ] &= F_53 ( V_81 ) [ 1 ] ;
V_5 -> V_82 [ 2 ] &= F_53 ( V_81 ) [ 2 ] ;
V_5 -> V_82 [ 3 ] &= F_53 ( V_81 ) [ 3 ] ;
}
static inline void
F_54 ( struct V_78 * V_9 , T_2 V_8 )
{
F_52 ( & V_9 -> V_5 , V_8 ) ;
V_9 -> V_8 = V_8 - 1 ;
}
static bool
F_55 ( struct V_16 * V_17 ,
const struct V_78 * V_18 )
{
T_1 V_13 = V_18 -> V_12 ? V_14 : 0 ;
if ( F_56 ( V_17 , V_19 , & V_18 -> V_5 . V_79 ) ||
F_11 ( V_17 , V_20 , V_18 -> V_6 ) ||
F_12 ( V_17 , V_21 , V_18 -> V_8 + 1 ) ||
F_12 ( V_17 , V_22 , V_18 -> V_7 ) ||
( V_13 &&
F_13 ( V_17 , V_23 , F_14 ( V_13 ) ) ) )
goto V_24;
return 0 ;
V_24:
return 1 ;
}
static bool
F_57 ( struct V_16 * V_17 ,
const struct V_78 * V_18 )
{
const struct V_83 * V_84 =
( const struct V_83 * ) V_18 ;
T_1 V_13 = V_18 -> V_12 ? V_14 : 0 ;
if ( F_56 ( V_17 , V_19 , & V_84 -> V_5 . V_79 ) ||
F_11 ( V_17 , V_20 , V_18 -> V_6 ) ||
F_12 ( V_17 , V_21 , V_18 -> V_8 + 1 ) ||
F_12 ( V_17 , V_22 , V_18 -> V_7 ) ||
F_13 ( V_17 , V_27 ,
F_14 ( F_16 ( V_84 -> V_28 ) ) ) ||
( V_13 &&
F_13 ( V_17 , V_23 , F_14 ( V_13 ) ) ) )
goto V_24;
return 0 ;
V_24:
return 1 ;
}
static inline void
F_58 ( struct V_29 * V_30 ,
const struct V_78 * V_31 )
{
V_30 -> V_32 . V_6 = V_31 -> V_6 ;
}
static int
F_59 ( struct V_33 * V_34 , const struct V_16 * V_17 ,
const struct V_35 * V_36 ,
enum V_37 V_38 , const struct V_39 * V_40 )
{
const struct V_29 * V_30 = V_34 -> V_18 ;
T_3 V_41 = V_34 -> V_42 -> V_38 [ V_38 ] ;
struct V_78 V_18 = {
. V_8 = V_30 -> V_43 [ 0 ] . V_8 ? V_30 -> V_43 [ 0 ] . V_8 - 1 : V_44 - 1 ,
} ;
if ( V_38 == V_45 )
V_18 . V_8 = V_44 - 1 ;
if ( ! F_60 ( V_17 , V_40 -> V_13 & V_46 ,
& V_18 . V_6 , & V_18 . V_7 ) )
return - V_47 ;
F_61 ( V_17 , V_40 -> V_13 & V_48 , & V_18 . V_5 . V_79 ) ;
F_52 ( & V_18 . V_5 , V_18 . V_8 + 1 ) ;
return V_41 ( V_34 , & V_18 , F_21 ( V_40 , V_30 ) , V_40 -> V_49 ) ;
}
static int
F_62 ( struct V_33 * V_34 , struct V_50 * V_51 [] ,
enum V_37 V_38 , T_1 * V_52 , T_1 V_13 , bool V_53 )
{
const struct V_29 * V_30 = V_34 -> V_18 ;
T_3 V_41 = V_34 -> V_42 -> V_38 [ V_38 ] ;
struct V_78 V_18 = { . V_8 = V_44 - 1 } ;
T_1 V_6 , V_54 ;
T_1 V_28 = V_30 -> V_28 ;
bool V_58 = false ;
T_2 V_8 ;
int V_59 ;
if ( F_23 ( ! V_51 [ V_19 ] ||
! F_24 ( V_51 , V_20 ) ||
! F_25 ( V_51 , V_60 ) ||
! F_25 ( V_51 , V_27 ) ||
! F_25 ( V_51 , V_23 ) ) )
return - V_61 ;
if ( F_23 ( V_51 [ V_70 ] ) )
return - V_85 ;
if ( V_51 [ V_62 ] )
* V_52 = F_26 ( V_51 [ V_62 ] ) ;
V_59 = F_63 ( V_51 [ V_19 ] , & V_18 . V_5 ) ;
if ( V_59 )
return V_59 ;
if ( V_51 [ V_21 ] ) {
V_8 = F_28 ( V_51 [ V_21 ] ) ;
if ( ! V_8 || V_8 > V_44 )
return - V_63 ;
V_18 . V_8 = V_8 - 1 ;
}
F_52 ( & V_18 . V_5 , V_18 . V_8 + 1 ) ;
if ( V_51 [ V_20 ] )
V_18 . V_6 = F_29 ( V_51 [ V_20 ] ) ;
else
return - V_61 ;
if ( V_51 [ V_22 ] ) {
V_18 . V_7 = F_28 ( V_51 [ V_22 ] ) ;
V_58 = F_30 ( V_18 . V_7 ) ;
if ( V_18 . V_7 == 0 )
return - V_64 ;
} else
return - V_65 ;
if ( ! ( V_58 || V_18 . V_7 == V_86 ) )
V_18 . V_6 = 0 ;
if ( V_51 [ V_27 ] ) {
if ( ! F_31 ( V_30 -> V_28 ) )
return - V_67 ;
V_28 = F_32 ( V_51 [ V_27 ] ) ;
}
if ( V_51 [ V_23 ] && V_38 == V_68 ) {
T_1 V_69 = F_33 ( V_51 [ V_23 ] ) ;
if ( V_69 & V_14 )
V_13 |= ( V_69 << 16 ) ;
}
if ( V_38 == V_45 || ! V_58 || ! V_51 [ V_60 ] ) {
V_59 = V_41 ( V_34 , & V_18 , V_28 , V_13 ) ;
return F_35 ( V_59 , V_13 ) ? 0 : V_59 ;
}
V_6 = F_36 ( V_18 . V_6 ) ;
V_54 = F_37 ( V_51 [ V_60 ] ) ;
if ( V_6 > V_54 )
F_38 ( V_6 , V_54 ) ;
if ( V_53 )
V_6 = F_36 ( V_30 -> V_32 . V_6 ) ;
for (; V_6 <= V_54 ; V_6 ++ ) {
V_18 . V_6 = F_43 ( V_6 ) ;
V_59 = V_41 ( V_34 , & V_18 , V_28 , V_13 ) ;
if ( V_59 && ! F_35 ( V_59 , V_13 ) )
return V_59 ;
else
V_59 = 0 ;
}
return V_59 ;
}
static int
F_64 ( struct V_33 * V_34 , struct V_50 * V_51 [] , T_1 V_13 )
{
struct V_29 * V_30 ;
T_1 V_87 = V_88 , V_77 = V_89 ;
T_2 V_90 ;
T_4 V_91 ;
if ( ! ( V_34 -> V_92 == V_93 || V_34 -> V_92 == V_94 ) )
return - V_95 ;
if ( F_23 ( ! F_25 ( V_51 , V_96 ) ||
! F_25 ( V_51 , V_97 ) ||
! F_25 ( V_51 , V_27 ) ) )
return - V_61 ;
if ( V_51 [ V_96 ] ) {
V_87 = F_33 ( V_51 [ V_96 ] ) ;
if ( V_87 < V_98 )
V_87 = V_98 ;
}
if ( V_51 [ V_97 ] )
V_77 = F_33 ( V_51 [ V_97 ] ) ;
V_30 = F_65 ( sizeof( * V_30 )
+ sizeof( struct V_99 )
* ( V_34 -> V_92 == V_93 ? 32 : 128 ) , V_100 ) ;
if ( ! V_30 )
return - V_101 ;
V_30 -> V_77 = V_77 ;
F_66 ( & V_30 -> V_102 , sizeof( V_30 -> V_102 ) ) ;
V_30 -> V_28 = V_103 ;
V_90 = F_67 ( V_87 ) ;
V_91 = F_68 ( V_90 ) ;
if ( V_91 == 0 ) {
F_69 ( V_30 ) ;
return - V_101 ;
}
V_30 -> V_104 = F_70 ( V_91 ) ;
if ( ! V_30 -> V_104 ) {
F_69 ( V_30 ) ;
return - V_101 ;
}
V_30 -> V_104 -> F_67 = V_90 ;
V_34 -> V_18 = V_30 ;
if ( V_51 [ V_27 ] ) {
V_30 -> V_28 = F_32 ( V_51 [ V_27 ] ) ;
V_34 -> V_42 = V_34 -> V_92 == V_93
? & V_105 : & V_106 ;
if ( V_34 -> V_92 == V_93 )
F_71 ( V_34 ) ;
else
F_72 ( V_34 ) ;
} else {
V_34 -> V_42 = V_34 -> V_92 == V_93
? & V_107 : & V_108 ;
}
F_73 ( L_1 ,
V_34 -> V_109 , F_74 ( V_30 -> V_104 -> F_67 ) ,
V_30 -> V_104 -> F_67 , V_30 -> V_77 , V_34 -> V_18 , V_30 -> V_104 ) ;
return 0 ;
}
static int T_5
F_75 ( void )
{
return F_76 ( & V_110 ) ;
}
static void T_6
F_77 ( void )
{
F_78 ( & V_110 ) ;
}
