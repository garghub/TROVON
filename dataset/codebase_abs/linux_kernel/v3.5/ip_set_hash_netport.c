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
static inline bool
F_5 ( const struct V_1 * V_9 )
{
return ! V_9 -> V_12 ;
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
F_9 ( struct V_15 * V_16 ,
const struct V_1 * V_17 )
{
T_1 V_13 = V_17 -> V_12 ? V_14 : 0 ;
if ( F_10 ( V_16 , V_18 , V_17 -> V_5 ) ||
F_11 ( V_16 , V_19 , V_17 -> V_6 ) ||
F_12 ( V_16 , V_20 , V_17 -> V_8 + 1 ) ||
F_12 ( V_16 , V_21 , V_17 -> V_7 ) ||
( V_13 &&
F_13 ( V_16 , V_22 , F_14 ( V_13 ) ) ) )
goto V_23;
return 0 ;
V_23:
return 1 ;
}
static bool
F_15 ( struct V_15 * V_16 ,
const struct V_1 * V_17 )
{
const struct V_24 * V_25 =
( const struct V_24 * ) V_17 ;
T_1 V_13 = V_17 -> V_12 ? V_14 : 0 ;
if ( F_10 ( V_16 , V_18 , V_25 -> V_5 ) ||
F_11 ( V_16 , V_19 , V_25 -> V_6 ) ||
F_12 ( V_16 , V_20 , V_17 -> V_8 + 1 ) ||
F_12 ( V_16 , V_21 , V_17 -> V_7 ) ||
F_13 ( V_16 , V_26 ,
F_14 ( F_16 ( V_25 -> V_27 ) ) ) ||
( V_13 &&
F_13 ( V_16 , V_22 , F_14 ( V_13 ) ) ) )
goto V_23;
return 0 ;
V_23:
return 1 ;
}
static inline void
F_17 ( struct V_28 * V_29 ,
const struct V_1 * V_30 )
{
V_29 -> V_31 . V_5 = F_18 ( V_30 -> V_5 ) ;
V_29 -> V_31 . V_6 = F_19 ( V_30 -> V_6 ) ;
}
static int
F_20 ( struct V_32 * V_33 , const struct V_15 * V_16 ,
const struct V_34 * V_35 ,
enum V_36 V_37 , const struct V_38 * V_39 )
{
const struct V_28 * V_29 = V_33 -> V_17 ;
T_3 V_40 = V_33 -> V_41 -> V_37 [ V_37 ] ;
struct V_1 V_17 = {
. V_8 = V_29 -> V_42 [ 0 ] . V_8 ? V_29 -> V_42 [ 0 ] . V_8 - 1 : V_43 - 1
} ;
if ( V_37 == V_44 )
V_17 . V_8 = V_43 - 1 ;
if ( ! F_21 ( V_16 , V_39 -> V_13 & V_45 ,
& V_17 . V_6 , & V_17 . V_7 ) )
return - V_46 ;
F_22 ( V_16 , V_39 -> V_13 & V_47 , & V_17 . V_5 ) ;
V_17 . V_5 &= F_7 ( V_17 . V_8 + 1 ) ;
return V_40 ( V_33 , & V_17 , F_23 ( V_39 , V_29 ) , V_39 -> V_48 ) ;
}
static int
F_24 ( struct V_32 * V_33 , struct V_49 * V_50 [] ,
enum V_36 V_37 , T_1 * V_51 , T_1 V_13 , bool V_52 )
{
const struct V_28 * V_29 = V_33 -> V_17 ;
T_3 V_40 = V_33 -> V_41 -> V_37 [ V_37 ] ;
struct V_1 V_17 = { . V_8 = V_43 - 1 } ;
T_1 V_6 , V_53 , V_54 = 0 , V_5 = 0 , V_55 , V_56 ;
T_1 V_27 = V_29 -> V_27 ;
bool V_57 = false ;
T_2 V_8 ;
int V_58 ;
if ( F_25 ( ! V_50 [ V_18 ] ||
! F_26 ( V_50 , V_19 ) ||
! F_27 ( V_50 , V_59 ) ||
! F_27 ( V_50 , V_26 ) ||
! F_27 ( V_50 , V_22 ) ) )
return - V_60 ;
if ( V_50 [ V_61 ] )
* V_51 = F_28 ( V_50 [ V_61 ] ) ;
V_58 = F_29 ( V_50 [ V_18 ] , & V_5 ) ;
if ( V_58 )
return V_58 ;
if ( V_50 [ V_20 ] ) {
V_8 = F_30 ( V_50 [ V_20 ] ) ;
if ( ! V_8 || V_8 > V_43 )
return - V_62 ;
V_17 . V_8 = V_8 - 1 ;
}
if ( V_50 [ V_19 ] )
V_17 . V_6 = F_31 ( V_50 [ V_19 ] ) ;
else
return - V_60 ;
if ( V_50 [ V_21 ] ) {
V_17 . V_7 = F_30 ( V_50 [ V_21 ] ) ;
V_57 = F_32 ( V_17 . V_7 ) ;
if ( V_17 . V_7 == 0 )
return - V_63 ;
} else
return - V_64 ;
if ( ! ( V_57 || V_17 . V_7 == V_65 ) )
V_17 . V_6 = 0 ;
if ( V_50 [ V_26 ] ) {
if ( ! F_33 ( V_29 -> V_27 ) )
return - V_66 ;
V_27 = F_34 ( V_50 [ V_26 ] ) ;
}
V_57 = V_57 && V_50 [ V_59 ] ;
if ( V_50 [ V_22 ] && V_37 == V_67 ) {
T_1 V_68 = F_35 ( V_50 [ V_22 ] ) ;
if ( V_68 & V_14 )
V_13 |= ( V_68 << 16 ) ;
}
if ( V_37 == V_44 || ! ( V_57 || V_50 [ V_69 ] ) ) {
V_17 . V_5 = F_14 ( V_5 & F_36 ( V_17 . V_8 + 1 ) ) ;
V_58 = V_40 ( V_33 , & V_17 , V_27 , V_13 ) ;
return F_37 ( V_58 , V_13 ) ? 0 : V_58 ;
}
V_6 = V_53 = F_19 ( V_17 . V_6 ) ;
if ( V_50 [ V_59 ] ) {
V_53 = F_38 ( V_50 [ V_59 ] ) ;
if ( V_53 < V_6 )
F_39 ( V_6 , V_53 ) ;
}
if ( V_50 [ V_69 ] ) {
V_58 = F_29 ( V_50 [ V_69 ] , & V_55 ) ;
if ( V_58 )
return V_58 ;
if ( V_55 < V_5 )
F_39 ( V_5 , V_55 ) ;
if ( V_5 + V_70 == V_55 )
return - V_71 ;
} else {
F_40 ( V_5 , V_55 , V_17 . V_8 + 1 ) ;
}
if ( V_52 )
V_5 = V_29 -> V_31 . V_5 ;
while ( ! F_41 ( V_5 , V_55 ) ) {
V_17 . V_5 = F_14 ( V_5 ) ;
V_56 = F_42 ( V_5 , V_55 , & V_8 ) ;
V_17 . V_8 = V_8 - 1 ;
V_54 = V_52 && V_5 == V_29 -> V_31 . V_5 ? V_29 -> V_31 . V_6 : V_6 ;
for (; V_54 <= V_53 ; V_54 ++ ) {
V_17 . V_6 = F_43 ( V_54 ) ;
V_58 = V_40 ( V_33 , & V_17 , V_27 , V_13 ) ;
if ( V_58 && ! F_37 ( V_58 , V_13 ) )
return V_58 ;
else
V_58 = 0 ;
}
V_5 = V_56 + 1 ;
}
return V_58 ;
}
static bool
F_44 ( const struct V_32 * V_72 , const struct V_32 * V_73 )
{
const struct V_28 * V_74 = V_72 -> V_17 ;
const struct V_28 * V_75 = V_73 -> V_17 ;
return V_74 -> V_76 == V_75 -> V_76 &&
V_74 -> V_27 == V_75 -> V_27 ;
}
static inline bool
F_45 ( const struct V_77 * V_2 ,
const struct V_77 * V_3 ,
T_1 * V_4 )
{
return F_46 ( & V_2 -> V_5 . V_78 , & V_3 -> V_5 . V_78 ) == 0 &&
V_2 -> V_6 == V_3 -> V_6 &&
V_2 -> V_7 == V_3 -> V_7 &&
V_2 -> V_8 == V_3 -> V_8 ;
}
static inline bool
F_47 ( const struct V_77 * V_9 )
{
return V_9 -> V_7 == 0 ;
}
static inline void
F_48 ( struct V_77 * V_10 ,
const struct V_77 * V_11 )
{
memcpy ( V_10 , V_11 , sizeof( * V_10 ) ) ;
}
static inline void
F_49 ( struct V_77 * V_10 , T_1 V_13 )
{
V_10 -> V_12 = ! ! ( V_13 & V_14 ) ;
}
static inline bool
F_50 ( const struct V_77 * V_9 )
{
return ! V_9 -> V_12 ;
}
static inline void
F_51 ( struct V_77 * V_9 )
{
V_9 -> V_7 = 0 ;
}
static inline void
F_52 ( union V_79 * V_5 , T_2 V_80 )
{
V_5 -> V_81 [ 0 ] &= F_53 ( V_80 ) [ 0 ] ;
V_5 -> V_81 [ 1 ] &= F_53 ( V_80 ) [ 1 ] ;
V_5 -> V_81 [ 2 ] &= F_53 ( V_80 ) [ 2 ] ;
V_5 -> V_81 [ 3 ] &= F_53 ( V_80 ) [ 3 ] ;
}
static inline void
F_54 ( struct V_77 * V_9 , T_2 V_8 )
{
F_52 ( & V_9 -> V_5 , V_8 ) ;
V_9 -> V_8 = V_8 - 1 ;
}
static bool
F_55 ( struct V_15 * V_16 ,
const struct V_77 * V_17 )
{
T_1 V_13 = V_17 -> V_12 ? V_14 : 0 ;
if ( F_56 ( V_16 , V_18 , & V_17 -> V_5 . V_78 ) ||
F_11 ( V_16 , V_19 , V_17 -> V_6 ) ||
F_12 ( V_16 , V_20 , V_17 -> V_8 + 1 ) ||
F_12 ( V_16 , V_21 , V_17 -> V_7 ) ||
( V_13 &&
F_13 ( V_16 , V_22 , F_14 ( V_13 ) ) ) )
goto V_23;
return 0 ;
V_23:
return 1 ;
}
static bool
F_57 ( struct V_15 * V_16 ,
const struct V_77 * V_17 )
{
const struct V_82 * V_83 =
( const struct V_82 * ) V_17 ;
T_1 V_13 = V_17 -> V_12 ? V_14 : 0 ;
if ( F_56 ( V_16 , V_18 , & V_83 -> V_5 . V_78 ) ||
F_11 ( V_16 , V_19 , V_17 -> V_6 ) ||
F_12 ( V_16 , V_20 , V_17 -> V_8 + 1 ) ||
F_12 ( V_16 , V_21 , V_17 -> V_7 ) ||
F_13 ( V_16 , V_26 ,
F_14 ( F_16 ( V_83 -> V_27 ) ) ) ||
( V_13 &&
F_13 ( V_16 , V_22 , F_14 ( V_13 ) ) ) )
goto V_23;
return 0 ;
V_23:
return 1 ;
}
static inline void
F_58 ( struct V_28 * V_29 ,
const struct V_77 * V_30 )
{
V_29 -> V_31 . V_6 = F_19 ( V_30 -> V_6 ) ;
}
static int
F_59 ( struct V_32 * V_33 , const struct V_15 * V_16 ,
const struct V_34 * V_35 ,
enum V_36 V_37 , const struct V_38 * V_39 )
{
const struct V_28 * V_29 = V_33 -> V_17 ;
T_3 V_40 = V_33 -> V_41 -> V_37 [ V_37 ] ;
struct V_77 V_17 = {
. V_8 = V_29 -> V_42 [ 0 ] . V_8 ? V_29 -> V_42 [ 0 ] . V_8 - 1 : V_43 - 1 ,
} ;
if ( V_37 == V_44 )
V_17 . V_8 = V_43 - 1 ;
if ( ! F_60 ( V_16 , V_39 -> V_13 & V_45 ,
& V_17 . V_6 , & V_17 . V_7 ) )
return - V_46 ;
F_61 ( V_16 , V_39 -> V_13 & V_47 , & V_17 . V_5 . V_78 ) ;
F_52 ( & V_17 . V_5 , V_17 . V_8 + 1 ) ;
return V_40 ( V_33 , & V_17 , F_23 ( V_39 , V_29 ) , V_39 -> V_48 ) ;
}
static int
F_62 ( struct V_32 * V_33 , struct V_49 * V_50 [] ,
enum V_36 V_37 , T_1 * V_51 , T_1 V_13 , bool V_52 )
{
const struct V_28 * V_29 = V_33 -> V_17 ;
T_3 V_40 = V_33 -> V_41 -> V_37 [ V_37 ] ;
struct V_77 V_17 = { . V_8 = V_43 - 1 } ;
T_1 V_6 , V_53 ;
T_1 V_27 = V_29 -> V_27 ;
bool V_57 = false ;
T_2 V_8 ;
int V_58 ;
if ( F_25 ( ! V_50 [ V_18 ] ||
! F_26 ( V_50 , V_19 ) ||
! F_27 ( V_50 , V_59 ) ||
! F_27 ( V_50 , V_26 ) ||
! F_27 ( V_50 , V_22 ) ) )
return - V_60 ;
if ( F_25 ( V_50 [ V_69 ] ) )
return - V_84 ;
if ( V_50 [ V_61 ] )
* V_51 = F_28 ( V_50 [ V_61 ] ) ;
V_58 = F_63 ( V_50 [ V_18 ] , & V_17 . V_5 ) ;
if ( V_58 )
return V_58 ;
if ( V_50 [ V_20 ] ) {
V_8 = F_30 ( V_50 [ V_20 ] ) ;
if ( ! V_8 || V_8 > V_43 )
return - V_62 ;
V_17 . V_8 = V_8 - 1 ;
}
F_52 ( & V_17 . V_5 , V_17 . V_8 + 1 ) ;
if ( V_50 [ V_19 ] )
V_17 . V_6 = F_31 ( V_50 [ V_19 ] ) ;
else
return - V_60 ;
if ( V_50 [ V_21 ] ) {
V_17 . V_7 = F_30 ( V_50 [ V_21 ] ) ;
V_57 = F_32 ( V_17 . V_7 ) ;
if ( V_17 . V_7 == 0 )
return - V_63 ;
} else
return - V_64 ;
if ( ! ( V_57 || V_17 . V_7 == V_85 ) )
V_17 . V_6 = 0 ;
if ( V_50 [ V_26 ] ) {
if ( ! F_33 ( V_29 -> V_27 ) )
return - V_66 ;
V_27 = F_34 ( V_50 [ V_26 ] ) ;
}
if ( V_50 [ V_22 ] && V_37 == V_67 ) {
T_1 V_68 = F_35 ( V_50 [ V_22 ] ) ;
if ( V_68 & V_14 )
V_13 |= ( V_68 << 16 ) ;
}
if ( V_37 == V_44 || ! V_57 || ! V_50 [ V_59 ] ) {
V_58 = V_40 ( V_33 , & V_17 , V_27 , V_13 ) ;
return F_37 ( V_58 , V_13 ) ? 0 : V_58 ;
}
V_6 = F_19 ( V_17 . V_6 ) ;
V_53 = F_38 ( V_50 [ V_59 ] ) ;
if ( V_6 > V_53 )
F_39 ( V_6 , V_53 ) ;
if ( V_52 )
V_6 = V_29 -> V_31 . V_6 ;
for (; V_6 <= V_53 ; V_6 ++ ) {
V_17 . V_6 = F_43 ( V_6 ) ;
V_58 = V_40 ( V_33 , & V_17 , V_27 , V_13 ) ;
if ( V_58 && ! F_37 ( V_58 , V_13 ) )
return V_58 ;
else
V_58 = 0 ;
}
return V_58 ;
}
static int
F_64 ( struct V_32 * V_33 , struct V_49 * V_50 [] , T_1 V_13 )
{
struct V_28 * V_29 ;
T_1 V_86 = V_87 , V_76 = V_88 ;
T_2 V_89 ;
T_4 V_90 ;
if ( ! ( V_33 -> V_91 == V_92 || V_33 -> V_91 == V_93 ) )
return - V_94 ;
if ( F_25 ( ! F_27 ( V_50 , V_95 ) ||
! F_27 ( V_50 , V_96 ) ||
! F_27 ( V_50 , V_26 ) ) )
return - V_60 ;
if ( V_50 [ V_95 ] ) {
V_86 = F_35 ( V_50 [ V_95 ] ) ;
if ( V_86 < V_97 )
V_86 = V_97 ;
}
if ( V_50 [ V_96 ] )
V_76 = F_35 ( V_50 [ V_96 ] ) ;
V_29 = F_65 ( sizeof( * V_29 )
+ sizeof( struct V_98 )
* ( V_33 -> V_91 == V_92 ? 32 : 128 ) , V_99 ) ;
if ( ! V_29 )
return - V_100 ;
V_29 -> V_76 = V_76 ;
F_66 ( & V_29 -> V_101 , sizeof( V_29 -> V_101 ) ) ;
V_29 -> V_27 = V_102 ;
V_89 = F_67 ( V_86 ) ;
V_90 = F_68 ( V_89 ) ;
if ( V_90 == 0 ) {
F_69 ( V_29 ) ;
return - V_100 ;
}
V_29 -> V_103 = F_70 ( V_90 ) ;
if ( ! V_29 -> V_103 ) {
F_69 ( V_29 ) ;
return - V_100 ;
}
V_29 -> V_103 -> F_67 = V_89 ;
V_33 -> V_17 = V_29 ;
if ( V_50 [ V_26 ] ) {
V_29 -> V_27 = F_34 ( V_50 [ V_26 ] ) ;
V_33 -> V_41 = V_33 -> V_91 == V_92
? & V_104 : & V_105 ;
if ( V_33 -> V_91 == V_92 )
F_71 ( V_33 ) ;
else
F_72 ( V_33 ) ;
} else {
V_33 -> V_41 = V_33 -> V_91 == V_92
? & V_106 : & V_107 ;
}
F_73 ( L_1 ,
V_33 -> V_108 , F_74 ( V_29 -> V_103 -> F_67 ) ,
V_29 -> V_103 -> F_67 , V_29 -> V_76 , V_33 -> V_17 , V_29 -> V_103 ) ;
return 0 ;
}
static int T_5
F_75 ( void )
{
return F_76 ( & V_109 ) ;
}
static void T_6
F_77 ( void )
{
F_78 ( & V_109 ) ;
}
