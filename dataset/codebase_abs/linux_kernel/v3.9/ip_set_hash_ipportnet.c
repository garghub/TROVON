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
static inline void
F_5 ( struct V_1 * V_10 , T_1 * V_12 )
{
if ( V_10 -> V_13 ) {
* V_12 = V_14 ;
V_10 -> V_13 = 0 ;
}
}
static inline int
F_6 ( const struct V_1 * V_9 )
{
return V_9 -> V_13 ? - V_15 : 1 ;
}
static inline void
F_7 ( struct V_1 * V_9 , T_2 V_6 )
{
V_9 -> V_3 &= F_8 ( V_6 ) ;
V_9 -> V_6 = V_6 - 1 ;
}
static inline void
F_9 ( struct V_1 * V_9 )
{
V_9 -> V_8 = 0 ;
}
static bool
F_10 ( struct V_16 * V_17 ,
const struct V_1 * V_18 )
{
T_1 V_12 = V_18 -> V_13 ? V_14 : 0 ;
if ( F_11 ( V_17 , V_19 , V_18 -> V_5 ) ||
F_11 ( V_17 , V_20 , V_18 -> V_3 ) ||
F_12 ( V_17 , V_21 , V_18 -> V_7 ) ||
F_13 ( V_17 , V_22 , V_18 -> V_6 + 1 ) ||
F_13 ( V_17 , V_23 , V_18 -> V_8 ) ||
( V_12 &&
F_14 ( V_17 , V_24 , F_15 ( V_12 ) ) ) )
goto V_25;
return 0 ;
V_25:
return 1 ;
}
static bool
F_16 ( struct V_16 * V_17 ,
const struct V_1 * V_18 )
{
const struct V_26 * V_27 =
( const struct V_26 * ) V_18 ;
T_1 V_12 = V_18 -> V_13 ? V_14 : 0 ;
if ( F_11 ( V_17 , V_19 , V_27 -> V_5 ) ||
F_11 ( V_17 , V_20 , V_27 -> V_3 ) ||
F_12 ( V_17 , V_21 , V_27 -> V_7 ) ||
F_13 ( V_17 , V_22 , V_18 -> V_6 + 1 ) ||
F_13 ( V_17 , V_23 , V_18 -> V_8 ) ||
F_14 ( V_17 , V_28 ,
F_15 ( F_17 ( V_27 -> V_29 ) ) ) ||
( V_12 &&
F_14 ( V_17 , V_24 , F_15 ( V_12 ) ) ) )
goto V_25;
return 0 ;
V_25:
return 1 ;
}
static inline void
F_18 ( struct V_30 * V_31 ,
const struct V_1 * V_32 )
{
V_31 -> V_33 . V_5 = V_32 -> V_5 ;
V_31 -> V_33 . V_7 = V_32 -> V_7 ;
V_31 -> V_33 . V_3 = V_32 -> V_3 ;
}
static int
F_19 ( struct V_34 * V_35 , const struct V_16 * V_17 ,
const struct V_36 * V_37 ,
enum V_38 V_39 , const struct V_40 * V_41 )
{
const struct V_30 * V_31 = V_35 -> V_18 ;
T_3 V_42 = V_35 -> V_43 -> V_39 [ V_39 ] ;
struct V_1 V_18 = {
. V_6 = V_31 -> V_44 [ 0 ] . V_6 ? V_31 -> V_44 [ 0 ] . V_6 - 1 : V_45 - 1
} ;
if ( V_39 == V_46 )
V_18 . V_6 = V_45 - 1 ;
if ( ! F_20 ( V_17 , V_41 -> V_12 & V_47 ,
& V_18 . V_7 , & V_18 . V_8 ) )
return - V_48 ;
F_21 ( V_17 , V_41 -> V_12 & V_49 , & V_18 . V_5 ) ;
F_21 ( V_17 , V_41 -> V_12 & V_50 , & V_18 . V_3 ) ;
V_18 . V_3 &= F_8 ( V_18 . V_6 + 1 ) ;
return V_42 ( V_35 , & V_18 , F_22 ( V_41 , V_31 ) , V_41 -> V_51 ) ;
}
static int
F_23 ( struct V_34 * V_35 , struct V_52 * V_53 [] ,
enum V_38 V_39 , T_1 * V_54 , T_1 V_12 , bool V_55 )
{
const struct V_30 * V_31 = V_35 -> V_18 ;
T_3 V_42 = V_35 -> V_43 -> V_39 [ V_39 ] ;
struct V_1 V_18 = { . V_6 = V_45 - 1 } ;
T_1 V_5 , V_56 , V_57 = 0 , V_7 , V_58 ;
T_1 V_59 , V_60 , V_61 , V_3 ;
T_1 V_29 = V_31 -> V_29 ;
bool V_62 = false ;
T_2 V_6 ;
int V_63 ;
if ( F_24 ( ! V_53 [ V_19 ] || ! V_53 [ V_20 ] ||
! F_25 ( V_53 , V_21 ) ||
! F_26 ( V_53 , V_64 ) ||
! F_26 ( V_53 , V_28 ) ||
! F_26 ( V_53 , V_24 ) ) )
return - V_65 ;
if ( V_53 [ V_66 ] )
* V_54 = F_27 ( V_53 [ V_66 ] ) ;
V_63 = F_28 ( V_53 [ V_19 ] , & V_5 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_28 ( V_53 [ V_20 ] , & V_59 ) ;
if ( V_63 )
return V_63 ;
if ( V_53 [ V_22 ] ) {
V_6 = F_29 ( V_53 [ V_22 ] ) ;
if ( ! V_6 || V_6 > V_45 )
return - V_67 ;
V_18 . V_6 = V_6 - 1 ;
}
if ( V_53 [ V_21 ] )
V_18 . V_7 = F_30 ( V_53 [ V_21 ] ) ;
else
return - V_65 ;
if ( V_53 [ V_23 ] ) {
V_18 . V_8 = F_29 ( V_53 [ V_23 ] ) ;
V_62 = F_31 ( V_18 . V_8 ) ;
if ( V_18 . V_8 == 0 )
return - V_68 ;
} else
return - V_69 ;
if ( ! ( V_62 || V_18 . V_8 == V_70 ) )
V_18 . V_7 = 0 ;
if ( V_53 [ V_28 ] ) {
if ( ! F_32 ( V_31 -> V_29 ) )
return - V_71 ;
V_29 = F_33 ( V_53 [ V_28 ] ) ;
}
if ( V_53 [ V_24 ] && V_39 == V_72 ) {
T_1 V_73 = F_34 ( V_53 [ V_24 ] ) ;
if ( V_73 & V_14 )
V_12 |= ( V_73 << 16 ) ;
}
V_62 = V_62 && V_53 [ V_64 ] ;
if ( V_39 == V_46 ||
! ( V_53 [ V_74 ] || V_53 [ V_75 ] || V_62 ||
V_53 [ V_76 ] ) ) {
V_18 . V_5 = F_15 ( V_5 ) ;
V_18 . V_3 = F_15 ( V_59 & F_35 ( V_18 . V_6 + 1 ) ) ;
V_63 = V_42 ( V_35 , & V_18 , V_29 , V_12 ) ;
return F_36 ( V_63 , V_12 ) ? 0 : V_63 ;
}
V_56 = V_5 ;
if ( V_53 [ V_75 ] ) {
V_63 = F_28 ( V_53 [ V_75 ] , & V_56 ) ;
if ( V_63 )
return V_63 ;
if ( V_5 > V_56 )
F_37 ( V_5 , V_56 ) ;
} else if ( V_53 [ V_74 ] ) {
T_2 V_6 = F_29 ( V_53 [ V_74 ] ) ;
if ( ! V_6 || V_6 > 32 )
return - V_67 ;
F_38 ( V_5 , V_56 , V_6 ) ;
}
V_58 = V_7 = F_39 ( V_18 . V_7 ) ;
if ( V_53 [ V_64 ] ) {
V_58 = F_40 ( V_53 [ V_64 ] ) ;
if ( V_7 > V_58 )
F_37 ( V_7 , V_58 ) ;
}
V_60 = V_59 ;
if ( V_53 [ V_76 ] ) {
V_63 = F_28 ( V_53 [ V_76 ] , & V_60 ) ;
if ( V_63 )
return V_63 ;
if ( V_59 > V_60 )
F_37 ( V_59 , V_60 ) ;
if ( V_59 + V_77 == V_60 )
return - V_78 ;
} else {
F_38 ( V_59 , V_60 , V_18 . V_6 + 1 ) ;
}
if ( V_55 )
V_5 = F_41 ( V_31 -> V_33 . V_5 ) ;
for (; ! F_42 ( V_56 , V_5 ) ; V_5 ++ ) {
V_18 . V_5 = F_15 ( V_5 ) ;
V_57 = V_55 && V_5 == F_41 ( V_31 -> V_33 . V_5 ) ? F_39 ( V_31 -> V_33 . V_7 )
: V_7 ;
for (; V_57 <= V_58 ; V_57 ++ ) {
V_18 . V_7 = F_43 ( V_57 ) ;
V_3 = V_55
&& V_5 == F_41 ( V_31 -> V_33 . V_5 )
&& V_57 == F_39 ( V_31 -> V_33 . V_7 )
? F_41 ( V_31 -> V_33 . V_3 ) : V_59 ;
while ( ! F_44 ( V_3 , V_60 ) ) {
V_18 . V_3 = F_15 ( V_3 ) ;
V_61 = F_45 ( V_3 , V_60 ,
& V_6 ) ;
V_18 . V_6 = V_6 - 1 ;
V_63 = V_42 ( V_35 , & V_18 , V_29 , V_12 ) ;
if ( V_63 && ! F_36 ( V_63 , V_12 ) )
return V_63 ;
else
V_63 = 0 ;
V_3 = V_61 + 1 ;
}
}
}
return V_63 ;
}
static bool
F_46 ( const struct V_34 * V_79 , const struct V_34 * V_80 )
{
const struct V_30 * V_81 = V_79 -> V_18 ;
const struct V_30 * V_82 = V_80 -> V_18 ;
return V_81 -> V_83 == V_82 -> V_83 &&
V_81 -> V_29 == V_82 -> V_29 ;
}
static inline bool
F_47 ( const struct V_84 * V_2 ,
const struct V_84 * V_3 ,
T_1 * V_4 )
{
return F_48 ( & V_2 -> V_5 . V_85 , & V_3 -> V_5 . V_85 ) &&
F_48 ( & V_2 -> V_3 . V_85 , & V_3 -> V_3 . V_85 ) &&
V_2 -> V_6 == V_3 -> V_6 &&
V_2 -> V_7 == V_3 -> V_7 &&
V_2 -> V_8 == V_3 -> V_8 ;
}
static inline bool
F_49 ( const struct V_84 * V_9 )
{
return V_9 -> V_8 == 0 ;
}
static inline void
F_50 ( struct V_84 * V_10 ,
const struct V_84 * V_11 )
{
memcpy ( V_10 , V_11 , sizeof( * V_10 ) ) ;
}
static inline void
F_51 ( struct V_84 * V_10 , T_1 V_12 )
{
V_10 -> V_13 = ! ! ( V_12 & V_14 ) ;
}
static inline void
F_52 ( struct V_84 * V_10 , T_1 * V_12 )
{
if ( V_10 -> V_13 ) {
* V_12 = V_14 ;
V_10 -> V_13 = 0 ;
}
}
static inline int
F_53 ( const struct V_84 * V_9 )
{
return V_9 -> V_13 ? - V_15 : 1 ;
}
static inline void
F_54 ( struct V_84 * V_9 )
{
V_9 -> V_8 = 0 ;
}
static inline void
F_55 ( union V_86 * V_5 , T_2 V_87 )
{
V_5 -> V_88 [ 0 ] &= F_56 ( V_87 ) [ 0 ] ;
V_5 -> V_88 [ 1 ] &= F_56 ( V_87 ) [ 1 ] ;
V_5 -> V_88 [ 2 ] &= F_56 ( V_87 ) [ 2 ] ;
V_5 -> V_88 [ 3 ] &= F_56 ( V_87 ) [ 3 ] ;
}
static inline void
F_57 ( struct V_84 * V_9 , T_2 V_6 )
{
F_55 ( & V_9 -> V_3 , V_6 ) ;
V_9 -> V_6 = V_6 - 1 ;
}
static bool
F_58 ( struct V_16 * V_17 ,
const struct V_84 * V_18 )
{
T_1 V_12 = V_18 -> V_13 ? V_14 : 0 ;
if ( F_59 ( V_17 , V_19 , & V_18 -> V_5 . V_85 ) ||
F_59 ( V_17 , V_20 , & V_18 -> V_3 . V_85 ) ||
F_12 ( V_17 , V_21 , V_18 -> V_7 ) ||
F_13 ( V_17 , V_22 , V_18 -> V_6 + 1 ) ||
F_13 ( V_17 , V_23 , V_18 -> V_8 ) ||
( V_12 &&
F_14 ( V_17 , V_24 , F_15 ( V_12 ) ) ) )
goto V_25;
return 0 ;
V_25:
return 1 ;
}
static bool
F_60 ( struct V_16 * V_17 ,
const struct V_84 * V_18 )
{
const struct V_89 * V_90 =
( const struct V_89 * ) V_18 ;
T_1 V_12 = V_18 -> V_13 ? V_14 : 0 ;
if ( F_59 ( V_17 , V_19 , & V_90 -> V_5 . V_85 ) ||
F_59 ( V_17 , V_20 , & V_18 -> V_3 . V_85 ) ||
F_12 ( V_17 , V_21 , V_18 -> V_7 ) ||
F_13 ( V_17 , V_22 , V_18 -> V_6 + 1 ) ||
F_13 ( V_17 , V_23 , V_18 -> V_8 ) ||
F_14 ( V_17 , V_28 ,
F_15 ( F_17 ( V_90 -> V_29 ) ) ) ||
( V_12 &&
F_14 ( V_17 , V_24 , F_15 ( V_12 ) ) ) )
goto V_25;
return 0 ;
V_25:
return 1 ;
}
static inline void
F_61 ( struct V_30 * V_31 ,
const struct V_84 * V_32 )
{
V_31 -> V_33 . V_7 = V_32 -> V_7 ;
}
static int
F_62 ( struct V_34 * V_35 , const struct V_16 * V_17 ,
const struct V_36 * V_37 ,
enum V_38 V_39 , const struct V_40 * V_41 )
{
const struct V_30 * V_31 = V_35 -> V_18 ;
T_3 V_42 = V_35 -> V_43 -> V_39 [ V_39 ] ;
struct V_84 V_18 = {
. V_6 = V_31 -> V_44 [ 0 ] . V_6 ? V_31 -> V_44 [ 0 ] . V_6 - 1 : V_45 - 1
} ;
if ( V_39 == V_46 )
V_18 . V_6 = V_45 - 1 ;
if ( ! F_63 ( V_17 , V_41 -> V_12 & V_47 ,
& V_18 . V_7 , & V_18 . V_8 ) )
return - V_48 ;
F_64 ( V_17 , V_41 -> V_12 & V_49 , & V_18 . V_5 . V_85 ) ;
F_64 ( V_17 , V_41 -> V_12 & V_50 , & V_18 . V_3 . V_85 ) ;
F_55 ( & V_18 . V_3 , V_18 . V_6 + 1 ) ;
return V_42 ( V_35 , & V_18 , F_22 ( V_41 , V_31 ) , V_41 -> V_51 ) ;
}
static int
F_65 ( struct V_34 * V_35 , struct V_52 * V_53 [] ,
enum V_38 V_39 , T_1 * V_54 , T_1 V_12 , bool V_55 )
{
const struct V_30 * V_31 = V_35 -> V_18 ;
T_3 V_42 = V_35 -> V_43 -> V_39 [ V_39 ] ;
struct V_84 V_18 = { . V_6 = V_45 - 1 } ;
T_1 V_7 , V_58 ;
T_1 V_29 = V_31 -> V_29 ;
bool V_62 = false ;
T_2 V_6 ;
int V_63 ;
if ( F_24 ( ! V_53 [ V_19 ] || ! V_53 [ V_20 ] ||
! F_25 ( V_53 , V_21 ) ||
! F_26 ( V_53 , V_64 ) ||
! F_26 ( V_53 , V_28 ) ||
! F_26 ( V_53 , V_24 ) ||
V_53 [ V_75 ] ||
V_53 [ V_74 ] ) )
return - V_65 ;
if ( F_24 ( V_53 [ V_75 ] ) )
return - V_91 ;
if ( V_53 [ V_66 ] )
* V_54 = F_27 ( V_53 [ V_66 ] ) ;
V_63 = F_66 ( V_53 [ V_19 ] , & V_18 . V_5 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_66 ( V_53 [ V_20 ] , & V_18 . V_3 ) ;
if ( V_63 )
return V_63 ;
if ( V_53 [ V_22 ] ) {
V_6 = F_29 ( V_53 [ V_22 ] ) ;
if ( ! V_6 || V_6 > V_45 )
return - V_67 ;
V_18 . V_6 = V_6 - 1 ;
}
F_55 ( & V_18 . V_3 , V_18 . V_6 + 1 ) ;
if ( V_53 [ V_21 ] )
V_18 . V_7 = F_30 ( V_53 [ V_21 ] ) ;
else
return - V_65 ;
if ( V_53 [ V_23 ] ) {
V_18 . V_8 = F_29 ( V_53 [ V_23 ] ) ;
V_62 = F_31 ( V_18 . V_8 ) ;
if ( V_18 . V_8 == 0 )
return - V_68 ;
} else
return - V_69 ;
if ( ! ( V_62 || V_18 . V_8 == V_92 ) )
V_18 . V_7 = 0 ;
if ( V_53 [ V_28 ] ) {
if ( ! F_32 ( V_31 -> V_29 ) )
return - V_71 ;
V_29 = F_33 ( V_53 [ V_28 ] ) ;
}
if ( V_53 [ V_24 ] && V_39 == V_72 ) {
T_1 V_73 = F_34 ( V_53 [ V_24 ] ) ;
if ( V_73 & V_14 )
V_12 |= ( V_73 << 16 ) ;
}
if ( V_39 == V_46 || ! V_62 || ! V_53 [ V_64 ] ) {
V_63 = V_42 ( V_35 , & V_18 , V_29 , V_12 ) ;
return F_36 ( V_63 , V_12 ) ? 0 : V_63 ;
}
V_7 = F_39 ( V_18 . V_7 ) ;
V_58 = F_40 ( V_53 [ V_64 ] ) ;
if ( V_7 > V_58 )
F_37 ( V_7 , V_58 ) ;
if ( V_55 )
V_7 = F_39 ( V_31 -> V_33 . V_7 ) ;
for (; V_7 <= V_58 ; V_7 ++ ) {
V_18 . V_7 = F_43 ( V_7 ) ;
V_63 = V_42 ( V_35 , & V_18 , V_29 , V_12 ) ;
if ( V_63 && ! F_36 ( V_63 , V_12 ) )
return V_63 ;
else
V_63 = 0 ;
}
return V_63 ;
}
static int
F_67 ( struct V_34 * V_35 , struct V_52 * V_53 [] , T_1 V_12 )
{
struct V_30 * V_31 ;
T_1 V_93 = V_94 , V_83 = V_95 ;
T_2 V_96 ;
T_4 V_97 ;
if ( ! ( V_35 -> V_98 == V_99 || V_35 -> V_98 == V_100 ) )
return - V_101 ;
if ( F_24 ( ! F_26 ( V_53 , V_102 ) ||
! F_26 ( V_53 , V_103 ) ||
! F_26 ( V_53 , V_28 ) ) )
return - V_65 ;
if ( V_53 [ V_102 ] ) {
V_93 = F_34 ( V_53 [ V_102 ] ) ;
if ( V_93 < V_104 )
V_93 = V_104 ;
}
if ( V_53 [ V_103 ] )
V_83 = F_34 ( V_53 [ V_103 ] ) ;
V_31 = F_68 ( sizeof( * V_31 )
+ sizeof( struct V_105 )
* ( V_35 -> V_98 == V_99 ? 32 : 128 ) , V_106 ) ;
if ( ! V_31 )
return - V_107 ;
V_31 -> V_83 = V_83 ;
F_69 ( & V_31 -> V_108 , sizeof( V_31 -> V_108 ) ) ;
V_31 -> V_29 = V_109 ;
V_96 = F_70 ( V_93 ) ;
V_97 = F_71 ( V_96 ) ;
if ( V_97 == 0 ) {
F_72 ( V_31 ) ;
return - V_107 ;
}
V_31 -> V_110 = F_73 ( V_97 ) ;
if ( ! V_31 -> V_110 ) {
F_72 ( V_31 ) ;
return - V_107 ;
}
V_31 -> V_110 -> F_70 = V_96 ;
V_35 -> V_18 = V_31 ;
if ( V_53 [ V_28 ] ) {
V_31 -> V_29 = F_33 ( V_53 [ V_28 ] ) ;
V_35 -> V_43 = V_35 -> V_98 == V_99
? & V_111
: & V_112 ;
if ( V_35 -> V_98 == V_99 )
F_74 ( V_35 ) ;
else
F_75 ( V_35 ) ;
} else {
V_35 -> V_43 = V_35 -> V_98 == V_99
? & V_113 : & V_114 ;
}
F_76 ( L_1 ,
V_35 -> V_115 , F_77 ( V_31 -> V_110 -> F_70 ) ,
V_31 -> V_110 -> F_70 , V_31 -> V_83 , V_35 -> V_18 , V_31 -> V_110 ) ;
return 0 ;
}
static int T_5
F_78 ( void )
{
return F_79 ( & V_116 ) ;
}
static void T_6
F_80 ( void )
{
F_81 ( & V_116 ) ;
}
