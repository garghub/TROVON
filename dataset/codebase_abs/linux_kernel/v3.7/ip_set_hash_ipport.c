static inline bool
F_1 ( const struct V_1 * V_2 ,
const struct V_1 * V_3 ,
T_1 * V_4 )
{
return V_2 -> V_5 == V_3 -> V_5 &&
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
V_9 -> V_5 = V_10 -> V_5 ;
V_9 -> V_6 = V_10 -> V_6 ;
V_9 -> V_7 = V_10 -> V_7 ;
}
static inline void
F_4 ( struct V_1 * V_8 )
{
V_8 -> V_7 = 0 ;
}
static bool
F_5 ( struct V_11 * V_12 ,
const struct V_1 * V_13 )
{
if ( F_6 ( V_12 , V_14 , V_13 -> V_5 ) ||
F_7 ( V_12 , V_15 , V_13 -> V_6 ) ||
F_8 ( V_12 , V_16 , V_13 -> V_7 ) )
goto V_17;
return 0 ;
V_17:
return 1 ;
}
static bool
F_9 ( struct V_11 * V_12 ,
const struct V_1 * V_13 )
{
const struct V_18 * V_19 =
( const struct V_18 * ) V_13 ;
if ( F_6 ( V_12 , V_14 , V_19 -> V_5 ) ||
F_7 ( V_12 , V_15 , V_19 -> V_6 ) ||
F_8 ( V_12 , V_16 , V_13 -> V_7 ) ||
F_10 ( V_12 , V_20 ,
F_11 ( F_12 ( V_19 -> V_21 ) ) ) )
goto V_17;
return 0 ;
V_17:
return 1 ;
}
static inline void
F_13 ( struct V_22 * V_23 ,
const struct V_1 * V_24 )
{
V_23 -> V_25 . V_5 = V_24 -> V_5 ;
V_23 -> V_25 . V_6 = V_24 -> V_6 ;
}
static int
F_14 ( struct V_26 * V_27 , const struct V_11 * V_12 ,
const struct V_28 * V_29 ,
enum V_30 V_31 , const struct V_32 * V_33 )
{
const struct V_22 * V_23 = V_27 -> V_13 ;
T_2 V_34 = V_27 -> V_35 -> V_31 [ V_31 ] ;
struct V_1 V_13 = { } ;
if ( ! F_15 ( V_12 , V_33 -> V_36 & V_37 ,
& V_13 . V_6 , & V_13 . V_7 ) )
return - V_38 ;
F_16 ( V_12 , V_33 -> V_36 & V_39 , & V_13 . V_5 ) ;
return V_34 ( V_27 , & V_13 , F_17 ( V_33 , V_23 ) , V_33 -> V_40 ) ;
}
static int
F_18 ( struct V_26 * V_27 , struct V_41 * V_42 [] ,
enum V_30 V_31 , T_1 * V_43 , T_1 V_36 , bool V_44 )
{
const struct V_22 * V_23 = V_27 -> V_13 ;
T_2 V_34 = V_27 -> V_35 -> V_31 [ V_31 ] ;
struct V_1 V_13 = { } ;
T_1 V_5 , V_45 , V_46 = 0 , V_6 , V_47 ;
T_1 V_21 = V_23 -> V_21 ;
bool V_48 = false ;
int V_49 ;
if ( F_19 ( ! V_42 [ V_14 ] ||
! F_20 ( V_42 , V_15 ) ||
! F_21 ( V_42 , V_50 ) ||
! F_21 ( V_42 , V_20 ) ) )
return - V_51 ;
if ( V_42 [ V_52 ] )
* V_43 = F_22 ( V_42 [ V_52 ] ) ;
V_49 = F_23 ( V_42 [ V_14 ] , & V_13 . V_5 ) ;
if ( V_49 )
return V_49 ;
if ( V_42 [ V_15 ] )
V_13 . V_6 = F_24 ( V_42 [ V_15 ] ) ;
else
return - V_51 ;
if ( V_42 [ V_16 ] ) {
V_13 . V_7 = F_25 ( V_42 [ V_16 ] ) ;
V_48 = F_26 ( V_13 . V_7 ) ;
if ( V_13 . V_7 == 0 )
return - V_53 ;
} else
return - V_54 ;
if ( ! ( V_48 || V_13 . V_7 == V_55 ) )
V_13 . V_6 = 0 ;
if ( V_42 [ V_20 ] ) {
if ( ! F_27 ( V_23 -> V_21 ) )
return - V_56 ;
V_21 = F_28 ( V_42 [ V_20 ] ) ;
}
if ( V_31 == V_57 ||
! ( V_42 [ V_58 ] || V_42 [ V_59 ] ||
V_42 [ V_50 ] ) ) {
V_49 = V_34 ( V_27 , & V_13 , V_21 , V_36 ) ;
return F_29 ( V_49 , V_36 ) ? 0 : V_49 ;
}
V_45 = V_5 = F_30 ( V_13 . V_5 ) ;
if ( V_42 [ V_58 ] ) {
V_49 = F_31 ( V_42 [ V_58 ] , & V_45 ) ;
if ( V_49 )
return V_49 ;
if ( V_5 > V_45 )
F_32 ( V_5 , V_45 ) ;
} else if ( V_42 [ V_59 ] ) {
T_3 V_60 = F_25 ( V_42 [ V_59 ] ) ;
if ( ! V_60 || V_60 > 32 )
return - V_61 ;
F_33 ( V_5 , V_45 , V_60 ) ;
}
V_47 = V_6 = F_34 ( V_13 . V_6 ) ;
if ( V_48 && V_42 [ V_50 ] ) {
V_47 = F_35 ( V_42 [ V_50 ] ) ;
if ( V_6 > V_47 )
F_32 ( V_6 , V_47 ) ;
}
if ( V_44 )
V_5 = F_30 ( V_23 -> V_25 . V_5 ) ;
for (; ! F_36 ( V_45 , V_5 ) ; V_5 ++ ) {
V_46 = V_44 && V_5 == F_30 ( V_23 -> V_25 . V_5 ) ? F_34 ( V_23 -> V_25 . V_6 )
: V_6 ;
for (; V_46 <= V_47 ; V_46 ++ ) {
V_13 . V_5 = F_11 ( V_5 ) ;
V_13 . V_6 = F_37 ( V_46 ) ;
V_49 = V_34 ( V_27 , & V_13 , V_21 , V_36 ) ;
if ( V_49 && ! F_29 ( V_49 , V_36 ) )
return V_49 ;
else
V_49 = 0 ;
}
}
return V_49 ;
}
static bool
F_38 ( const struct V_26 * V_62 , const struct V_26 * V_63 )
{
const struct V_22 * V_64 = V_62 -> V_13 ;
const struct V_22 * V_65 = V_63 -> V_13 ;
return V_64 -> V_66 == V_65 -> V_66 &&
V_64 -> V_21 == V_65 -> V_21 ;
}
static inline bool
F_39 ( const struct V_67 * V_2 ,
const struct V_67 * V_3 ,
T_1 * V_4 )
{
return F_40 ( & V_2 -> V_5 . V_68 , & V_3 -> V_5 . V_68 ) == 0 &&
V_2 -> V_6 == V_3 -> V_6 &&
V_2 -> V_7 == V_3 -> V_7 ;
}
static inline bool
F_41 ( const struct V_67 * V_8 )
{
return V_8 -> V_7 == 0 ;
}
static inline void
F_42 ( struct V_67 * V_9 ,
const struct V_67 * V_10 )
{
memcpy ( V_9 , V_10 , sizeof( * V_9 ) ) ;
}
static inline void
F_43 ( struct V_67 * V_8 )
{
V_8 -> V_7 = 0 ;
}
static bool
F_44 ( struct V_11 * V_12 ,
const struct V_67 * V_13 )
{
if ( F_45 ( V_12 , V_14 , & V_13 -> V_5 . V_68 ) ||
F_7 ( V_12 , V_15 , V_13 -> V_6 ) ||
F_8 ( V_12 , V_16 , V_13 -> V_7 ) )
goto V_17;
return 0 ;
V_17:
return 1 ;
}
static bool
F_46 ( struct V_11 * V_12 ,
const struct V_67 * V_13 )
{
const struct V_69 * V_70 =
( const struct V_69 * ) V_13 ;
if ( F_45 ( V_12 , V_14 , & V_70 -> V_5 . V_68 ) ||
F_7 ( V_12 , V_15 , V_13 -> V_6 ) ||
F_8 ( V_12 , V_16 , V_13 -> V_7 ) ||
F_10 ( V_12 , V_20 ,
F_11 ( F_12 ( V_70 -> V_21 ) ) ) )
goto V_17;
return 0 ;
V_17:
return 1 ;
}
static inline void
F_47 ( struct V_22 * V_23 ,
const struct V_67 * V_24 )
{
V_23 -> V_25 . V_6 = V_24 -> V_6 ;
}
static int
F_48 ( struct V_26 * V_27 , const struct V_11 * V_12 ,
const struct V_28 * V_29 ,
enum V_30 V_31 , const struct V_32 * V_33 )
{
const struct V_22 * V_23 = V_27 -> V_13 ;
T_2 V_34 = V_27 -> V_35 -> V_31 [ V_31 ] ;
struct V_67 V_13 = { } ;
if ( ! F_49 ( V_12 , V_33 -> V_36 & V_37 ,
& V_13 . V_6 , & V_13 . V_7 ) )
return - V_38 ;
F_50 ( V_12 , V_33 -> V_36 & V_39 , & V_13 . V_5 . V_68 ) ;
return V_34 ( V_27 , & V_13 , F_17 ( V_33 , V_23 ) , V_33 -> V_40 ) ;
}
static int
F_51 ( struct V_26 * V_27 , struct V_41 * V_42 [] ,
enum V_30 V_31 , T_1 * V_43 , T_1 V_36 , bool V_44 )
{
const struct V_22 * V_23 = V_27 -> V_13 ;
T_2 V_34 = V_27 -> V_35 -> V_31 [ V_31 ] ;
struct V_67 V_13 = { } ;
T_1 V_6 , V_47 ;
T_1 V_21 = V_23 -> V_21 ;
bool V_48 = false ;
int V_49 ;
if ( F_19 ( ! V_42 [ V_14 ] ||
! F_20 ( V_42 , V_15 ) ||
! F_21 ( V_42 , V_50 ) ||
! F_21 ( V_42 , V_20 ) ||
V_42 [ V_58 ] ||
V_42 [ V_59 ] ) )
return - V_51 ;
if ( V_42 [ V_52 ] )
* V_43 = F_22 ( V_42 [ V_52 ] ) ;
V_49 = F_52 ( V_42 [ V_14 ] , & V_13 . V_5 ) ;
if ( V_49 )
return V_49 ;
if ( V_42 [ V_15 ] )
V_13 . V_6 = F_24 ( V_42 [ V_15 ] ) ;
else
return - V_51 ;
if ( V_42 [ V_16 ] ) {
V_13 . V_7 = F_25 ( V_42 [ V_16 ] ) ;
V_48 = F_26 ( V_13 . V_7 ) ;
if ( V_13 . V_7 == 0 )
return - V_53 ;
} else
return - V_54 ;
if ( ! ( V_48 || V_13 . V_7 == V_71 ) )
V_13 . V_6 = 0 ;
if ( V_42 [ V_20 ] ) {
if ( ! F_27 ( V_23 -> V_21 ) )
return - V_56 ;
V_21 = F_28 ( V_42 [ V_20 ] ) ;
}
if ( V_31 == V_57 || ! V_48 || ! V_42 [ V_50 ] ) {
V_49 = V_34 ( V_27 , & V_13 , V_21 , V_36 ) ;
return F_29 ( V_49 , V_36 ) ? 0 : V_49 ;
}
V_6 = F_34 ( V_13 . V_6 ) ;
V_47 = F_35 ( V_42 [ V_50 ] ) ;
if ( V_6 > V_47 )
F_32 ( V_6 , V_47 ) ;
if ( V_44 )
V_6 = F_34 ( V_23 -> V_25 . V_6 ) ;
for (; V_6 <= V_47 ; V_6 ++ ) {
V_13 . V_6 = F_37 ( V_6 ) ;
V_49 = V_34 ( V_27 , & V_13 , V_21 , V_36 ) ;
if ( V_49 && ! F_29 ( V_49 , V_36 ) )
return V_49 ;
else
V_49 = 0 ;
}
return V_49 ;
}
static int
F_53 ( struct V_26 * V_27 , struct V_41 * V_42 [] , T_1 V_36 )
{
struct V_22 * V_23 ;
T_1 V_72 = V_73 , V_66 = V_74 ;
T_3 V_75 ;
T_4 V_76 ;
if ( ! ( V_27 -> V_77 == V_78 || V_27 -> V_77 == V_79 ) )
return - V_80 ;
if ( F_19 ( ! F_21 ( V_42 , V_81 ) ||
! F_21 ( V_42 , V_82 ) ||
! F_21 ( V_42 , V_20 ) ) )
return - V_51 ;
if ( V_42 [ V_81 ] ) {
V_72 = F_54 ( V_42 [ V_81 ] ) ;
if ( V_72 < V_83 )
V_72 = V_83 ;
}
if ( V_42 [ V_82 ] )
V_66 = F_54 ( V_42 [ V_82 ] ) ;
V_23 = F_55 ( sizeof( * V_23 ) , V_84 ) ;
if ( ! V_23 )
return - V_85 ;
V_23 -> V_66 = V_66 ;
F_56 ( & V_23 -> V_86 , sizeof( V_23 -> V_86 ) ) ;
V_23 -> V_21 = V_87 ;
V_75 = F_57 ( V_72 ) ;
V_76 = F_58 ( V_75 ) ;
if ( V_76 == 0 ) {
F_59 ( V_23 ) ;
return - V_85 ;
}
V_23 -> V_88 = F_60 ( V_76 ) ;
if ( ! V_23 -> V_88 ) {
F_59 ( V_23 ) ;
return - V_85 ;
}
V_23 -> V_88 -> F_57 = V_75 ;
V_27 -> V_13 = V_23 ;
if ( V_42 [ V_20 ] ) {
V_23 -> V_21 = F_28 ( V_42 [ V_20 ] ) ;
V_27 -> V_35 = V_27 -> V_77 == V_78
? & V_89 : & V_90 ;
if ( V_27 -> V_77 == V_78 )
F_61 ( V_27 ) ;
else
F_62 ( V_27 ) ;
} else {
V_27 -> V_35 = V_27 -> V_77 == V_78
? & V_91 : & V_92 ;
}
F_63 ( L_1 ,
V_27 -> V_93 , F_64 ( V_23 -> V_88 -> F_57 ) ,
V_23 -> V_88 -> F_57 , V_23 -> V_66 , V_27 -> V_13 , V_23 -> V_88 ) ;
return 0 ;
}
static int T_5
F_65 ( void )
{
return F_66 ( & V_94 ) ;
}
static void T_6
F_67 ( void )
{
F_68 ( & V_94 ) ;
}
