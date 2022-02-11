static inline bool
F_1 ( const struct V_1 * V_2 ,
const struct V_1 * V_3 ,
T_1 * V_4 )
{
return V_2 -> V_5 == V_3 -> V_5 &&
V_2 -> V_3 == V_3 -> V_3 &&
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
memcpy ( V_9 , V_10 , sizeof( * V_9 ) ) ;
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
F_6 ( V_12 , V_14 , V_13 -> V_5 ) ;
F_6 ( V_12 , V_15 , V_13 -> V_3 ) ;
F_7 ( V_12 , V_16 , V_13 -> V_6 ) ;
F_8 ( V_12 , V_17 , V_13 -> V_7 ) ;
return 0 ;
V_18:
return 1 ;
}
static bool
F_9 ( struct V_11 * V_12 ,
const struct V_1 * V_13 )
{
const struct V_19 * V_20 =
( const struct V_19 * ) V_13 ;
F_6 ( V_12 , V_14 , V_20 -> V_5 ) ;
F_6 ( V_12 , V_15 , V_20 -> V_3 ) ;
F_7 ( V_12 , V_16 , V_20 -> V_6 ) ;
F_8 ( V_12 , V_17 , V_13 -> V_7 ) ;
F_10 ( V_12 , V_21 ,
F_11 ( F_12 ( V_20 -> V_22 ) ) ) ;
return 0 ;
V_18:
return 1 ;
}
static inline void
F_13 ( struct V_23 * V_24 ,
const struct V_1 * V_25 )
{
V_24 -> V_26 . V_5 = F_14 ( V_25 -> V_5 ) ;
V_24 -> V_26 . V_6 = F_15 ( V_25 -> V_6 ) ;
}
static int
F_16 ( struct V_27 * V_28 , const struct V_11 * V_12 ,
const struct V_29 * V_30 ,
enum V_31 V_32 , const struct V_33 * V_34 )
{
const struct V_23 * V_24 = V_28 -> V_13 ;
T_2 V_35 = V_28 -> V_36 -> V_32 [ V_32 ] ;
struct V_1 V_13 = { } ;
if ( ! F_17 ( V_12 , V_34 -> V_37 & V_38 ,
& V_13 . V_6 , & V_13 . V_7 ) )
return - V_39 ;
F_18 ( V_12 , V_34 -> V_37 & V_40 , & V_13 . V_5 ) ;
F_18 ( V_12 , V_34 -> V_37 & V_41 , & V_13 . V_3 ) ;
return V_35 ( V_28 , & V_13 , F_19 ( V_34 , V_24 ) , V_34 -> V_42 ) ;
}
static int
F_20 ( struct V_27 * V_28 , struct V_43 * V_44 [] ,
enum V_31 V_32 , T_1 * V_45 , T_1 V_37 , bool V_46 )
{
const struct V_23 * V_24 = V_28 -> V_13 ;
T_2 V_35 = V_28 -> V_36 -> V_32 [ V_32 ] ;
struct V_1 V_13 = { } ;
T_1 V_5 , V_47 = 0 , V_48 = 0 , V_6 , V_49 ;
T_1 V_22 = V_24 -> V_22 ;
bool V_50 = false ;
int V_51 ;
if ( F_21 ( ! V_44 [ V_14 ] || ! V_44 [ V_15 ] ||
! F_22 ( V_44 , V_16 ) ||
! F_23 ( V_44 , V_52 ) ||
! F_23 ( V_44 , V_21 ) ) )
return - V_53 ;
if ( V_44 [ V_54 ] )
* V_45 = F_24 ( V_44 [ V_54 ] ) ;
V_51 = F_25 ( V_44 [ V_14 ] , & V_13 . V_5 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_25 ( V_44 [ V_15 ] , & V_13 . V_3 ) ;
if ( V_51 )
return V_51 ;
if ( V_44 [ V_16 ] )
V_13 . V_6 = F_26 ( V_44 [ V_16 ] ) ;
else
return - V_53 ;
if ( V_44 [ V_17 ] ) {
V_13 . V_7 = F_27 ( V_44 [ V_17 ] ) ;
V_50 = F_28 ( V_13 . V_7 ) ;
if ( V_13 . V_7 == 0 )
return - V_55 ;
} else
return - V_56 ;
if ( ! ( V_50 || V_13 . V_7 == V_57 ) )
V_13 . V_6 = 0 ;
if ( V_44 [ V_21 ] ) {
if ( ! F_29 ( V_24 -> V_22 ) )
return - V_58 ;
V_22 = F_30 ( V_44 [ V_21 ] ) ;
}
if ( V_32 == V_59 ||
! ( V_44 [ V_60 ] || V_44 [ V_61 ] ||
V_44 [ V_52 ] ) ) {
V_51 = V_35 ( V_28 , & V_13 , V_22 , V_37 ) ;
return F_31 ( V_51 , V_37 ) ? 0 : V_51 ;
}
V_5 = F_14 ( V_13 . V_5 ) ;
if ( V_44 [ V_60 ] ) {
V_51 = F_32 ( V_44 [ V_60 ] , & V_47 ) ;
if ( V_51 )
return V_51 ;
if ( V_5 > V_47 )
F_33 ( V_5 , V_47 ) ;
} else if ( V_44 [ V_61 ] ) {
T_3 V_62 = F_27 ( V_44 [ V_61 ] ) ;
if ( V_62 > 32 )
return - V_63 ;
F_34 ( V_5 , V_47 , V_62 ) ;
} else
V_47 = V_5 ;
V_49 = V_6 = F_15 ( V_13 . V_6 ) ;
if ( V_50 && V_44 [ V_52 ] ) {
V_49 = F_35 ( V_44 [ V_52 ] ) ;
if ( V_6 > V_49 )
F_33 ( V_6 , V_49 ) ;
}
if ( V_46 )
V_5 = V_24 -> V_26 . V_5 ;
for (; ! F_36 ( V_47 , V_5 ) ; V_5 ++ ) {
V_48 = V_46 && V_5 == V_24 -> V_26 . V_5 ? V_24 -> V_26 . V_6 : V_6 ;
for (; V_48 <= V_49 ; V_48 ++ ) {
V_13 . V_5 = F_11 ( V_5 ) ;
V_13 . V_6 = F_37 ( V_48 ) ;
V_51 = V_35 ( V_28 , & V_13 , V_22 , V_37 ) ;
if ( V_51 && ! F_31 ( V_51 , V_37 ) )
return V_51 ;
else
V_51 = 0 ;
}
}
return V_51 ;
}
static bool
F_38 ( const struct V_27 * V_64 , const struct V_27 * V_65 )
{
const struct V_23 * V_66 = V_64 -> V_13 ;
const struct V_23 * V_67 = V_65 -> V_13 ;
return V_66 -> V_68 == V_67 -> V_68 &&
V_66 -> V_22 == V_67 -> V_22 ;
}
static inline bool
F_39 ( const struct V_69 * V_2 ,
const struct V_69 * V_3 ,
T_1 * V_4 )
{
return F_40 ( & V_2 -> V_5 . V_70 , & V_3 -> V_5 . V_70 ) == 0 &&
F_40 ( & V_2 -> V_3 . V_70 , & V_3 -> V_3 . V_70 ) == 0 &&
V_2 -> V_6 == V_3 -> V_6 &&
V_2 -> V_7 == V_3 -> V_7 ;
}
static inline bool
F_41 ( const struct V_69 * V_8 )
{
return V_8 -> V_7 == 0 ;
}
static inline void
F_42 ( struct V_69 * V_9 ,
const struct V_69 * V_10 )
{
memcpy ( V_9 , V_10 , sizeof( * V_9 ) ) ;
}
static inline void
F_43 ( struct V_69 * V_8 )
{
V_8 -> V_7 = 0 ;
}
static bool
F_44 ( struct V_11 * V_12 ,
const struct V_69 * V_13 )
{
F_45 ( V_12 , V_14 , & V_13 -> V_5 ) ;
F_45 ( V_12 , V_15 , & V_13 -> V_3 ) ;
F_7 ( V_12 , V_16 , V_13 -> V_6 ) ;
F_8 ( V_12 , V_17 , V_13 -> V_7 ) ;
return 0 ;
V_18:
return 1 ;
}
static bool
F_46 ( struct V_11 * V_12 ,
const struct V_69 * V_13 )
{
const struct V_71 * V_72 =
( const struct V_71 * ) V_13 ;
F_45 ( V_12 , V_14 , & V_72 -> V_5 ) ;
F_45 ( V_12 , V_15 , & V_13 -> V_3 ) ;
F_7 ( V_12 , V_16 , V_13 -> V_6 ) ;
F_8 ( V_12 , V_17 , V_13 -> V_7 ) ;
F_10 ( V_12 , V_21 ,
F_11 ( F_12 ( V_72 -> V_22 ) ) ) ;
return 0 ;
V_18:
return 1 ;
}
static inline void
F_47 ( struct V_23 * V_24 ,
const struct V_69 * V_25 )
{
V_24 -> V_26 . V_6 = F_15 ( V_25 -> V_6 ) ;
}
static int
F_48 ( struct V_27 * V_28 , const struct V_11 * V_12 ,
const struct V_29 * V_30 ,
enum V_31 V_32 , const struct V_33 * V_34 )
{
const struct V_23 * V_24 = V_28 -> V_13 ;
T_2 V_35 = V_28 -> V_36 -> V_32 [ V_32 ] ;
struct V_69 V_13 = { } ;
if ( ! F_49 ( V_12 , V_34 -> V_37 & V_38 ,
& V_13 . V_6 , & V_13 . V_7 ) )
return - V_39 ;
F_50 ( V_12 , V_34 -> V_37 & V_40 , & V_13 . V_5 . V_70 ) ;
F_50 ( V_12 , V_34 -> V_37 & V_41 , & V_13 . V_3 . V_70 ) ;
return V_35 ( V_28 , & V_13 , F_19 ( V_34 , V_24 ) , V_34 -> V_42 ) ;
}
static int
F_51 ( struct V_27 * V_28 , struct V_43 * V_44 [] ,
enum V_31 V_32 , T_1 * V_45 , T_1 V_37 , bool V_46 )
{
const struct V_23 * V_24 = V_28 -> V_13 ;
T_2 V_35 = V_28 -> V_36 -> V_32 [ V_32 ] ;
struct V_69 V_13 = { } ;
T_1 V_6 , V_49 ;
T_1 V_22 = V_24 -> V_22 ;
bool V_50 = false ;
int V_51 ;
if ( F_21 ( ! V_44 [ V_14 ] || ! V_44 [ V_15 ] ||
! F_22 ( V_44 , V_16 ) ||
! F_23 ( V_44 , V_52 ) ||
! F_23 ( V_44 , V_21 ) ||
V_44 [ V_60 ] ||
V_44 [ V_61 ] ) )
return - V_53 ;
if ( V_44 [ V_54 ] )
* V_45 = F_24 ( V_44 [ V_54 ] ) ;
V_51 = F_52 ( V_44 [ V_14 ] , & V_13 . V_5 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_52 ( V_44 [ V_15 ] , & V_13 . V_3 ) ;
if ( V_51 )
return V_51 ;
if ( V_44 [ V_16 ] )
V_13 . V_6 = F_26 ( V_44 [ V_16 ] ) ;
else
return - V_53 ;
if ( V_44 [ V_17 ] ) {
V_13 . V_7 = F_27 ( V_44 [ V_17 ] ) ;
V_50 = F_28 ( V_13 . V_7 ) ;
if ( V_13 . V_7 == 0 )
return - V_55 ;
} else
return - V_56 ;
if ( ! ( V_50 || V_13 . V_7 == V_73 ) )
V_13 . V_6 = 0 ;
if ( V_44 [ V_21 ] ) {
if ( ! F_29 ( V_24 -> V_22 ) )
return - V_58 ;
V_22 = F_30 ( V_44 [ V_21 ] ) ;
}
if ( V_32 == V_59 || ! V_50 || ! V_44 [ V_52 ] ) {
V_51 = V_35 ( V_28 , & V_13 , V_22 , V_37 ) ;
return F_31 ( V_51 , V_37 ) ? 0 : V_51 ;
}
V_6 = F_15 ( V_13 . V_6 ) ;
V_49 = F_35 ( V_44 [ V_52 ] ) ;
if ( V_6 > V_49 )
F_33 ( V_6 , V_49 ) ;
if ( V_46 )
V_6 = V_24 -> V_26 . V_6 ;
for (; V_6 <= V_49 ; V_6 ++ ) {
V_13 . V_6 = F_37 ( V_6 ) ;
V_51 = V_35 ( V_28 , & V_13 , V_22 , V_37 ) ;
if ( V_51 && ! F_31 ( V_51 , V_37 ) )
return V_51 ;
else
V_51 = 0 ;
}
return V_51 ;
}
static int
F_53 ( struct V_27 * V_28 , struct V_43 * V_44 [] , T_1 V_37 )
{
struct V_23 * V_24 ;
T_1 V_74 = V_75 , V_68 = V_76 ;
T_3 V_77 ;
T_4 V_78 ;
if ( ! ( V_28 -> V_79 == V_80 || V_28 -> V_79 == V_81 ) )
return - V_82 ;
if ( F_21 ( ! F_23 ( V_44 , V_83 ) ||
! F_23 ( V_44 , V_84 ) ||
! F_23 ( V_44 , V_21 ) ) )
return - V_53 ;
if ( V_44 [ V_83 ] ) {
V_74 = F_54 ( V_44 [ V_83 ] ) ;
if ( V_74 < V_85 )
V_74 = V_85 ;
}
if ( V_44 [ V_84 ] )
V_68 = F_54 ( V_44 [ V_84 ] ) ;
V_24 = F_55 ( sizeof( * V_24 ) , V_86 ) ;
if ( ! V_24 )
return - V_87 ;
V_24 -> V_68 = V_68 ;
F_56 ( & V_24 -> V_88 , sizeof( V_24 -> V_88 ) ) ;
V_24 -> V_22 = V_89 ;
V_77 = F_57 ( V_74 ) ;
V_78 = F_58 ( V_77 ) ;
if ( V_78 == 0 ) {
F_59 ( V_24 ) ;
return - V_87 ;
}
V_24 -> V_90 = F_60 ( V_78 ) ;
if ( ! V_24 -> V_90 ) {
F_59 ( V_24 ) ;
return - V_87 ;
}
V_24 -> V_90 -> F_57 = V_77 ;
V_28 -> V_13 = V_24 ;
if ( V_44 [ V_21 ] ) {
V_24 -> V_22 = F_30 ( V_44 [ V_21 ] ) ;
V_28 -> V_36 = V_28 -> V_79 == V_80
? & V_91 : & V_92 ;
if ( V_28 -> V_79 == V_80 )
F_61 ( V_28 ) ;
else
F_62 ( V_28 ) ;
} else {
V_28 -> V_36 = V_28 -> V_79 == V_80
? & V_93 : & V_94 ;
}
F_63 ( L_1 ,
V_28 -> V_95 , F_64 ( V_24 -> V_90 -> F_57 ) ,
V_24 -> V_90 -> F_57 , V_24 -> V_68 , V_28 -> V_13 , V_24 -> V_90 ) ;
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
