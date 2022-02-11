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
static inline int
F_2 ( const struct V_1 * V_9 )
{
return V_9 -> V_10 ? - V_11 : 1 ;
}
static inline void
F_3 ( struct V_1 * V_9 , T_1 V_12 )
{
V_9 -> V_10 = ! ! ( ( V_12 >> 16 ) & V_13 ) ;
}
static inline void
F_4 ( struct V_1 * V_9 , T_2 * V_12 )
{
F_5 ( * V_12 , V_9 -> V_10 ) ;
}
static inline void
F_6 ( struct V_1 * V_9 , T_2 V_6 )
{
V_9 -> V_3 &= F_7 ( V_6 ) ;
V_9 -> V_6 = V_6 - 1 ;
}
static bool
F_8 ( struct V_14 * V_15 ,
const struct V_1 * V_16 )
{
T_1 V_12 = V_16 -> V_10 ? V_13 : 0 ;
if ( F_9 ( V_15 , V_17 , V_16 -> V_5 ) ||
F_9 ( V_15 , V_18 , V_16 -> V_3 ) ||
F_10 ( V_15 , V_19 , V_16 -> V_7 ) ||
F_11 ( V_15 , V_20 , V_16 -> V_6 + 1 ) ||
F_11 ( V_15 , V_21 , V_16 -> V_8 ) ||
( V_12 &&
F_12 ( V_15 , V_22 , F_13 ( V_12 ) ) ) )
goto V_23;
return 0 ;
V_23:
return 1 ;
}
static inline void
F_14 ( struct V_1 * V_24 ,
const struct V_1 * V_25 )
{
V_24 -> V_5 = V_25 -> V_5 ;
V_24 -> V_7 = V_25 -> V_7 ;
V_24 -> V_3 = V_25 -> V_3 ;
}
static int
F_15 ( struct V_26 * V_27 , const struct V_14 * V_15 ,
const struct V_28 * V_29 ,
enum V_30 V_31 , struct V_32 * V_33 )
{
const struct V_34 * V_35 = V_27 -> V_16 ;
T_3 V_36 = V_27 -> V_37 -> V_31 [ V_31 ] ;
struct V_1 V_38 = {
. V_6 = F_16 ( V_35 -> V_39 [ 0 ] . V_6 [ 0 ] , V_40 ) - 1 ,
} ;
struct V_41 V_42 = F_17 ( V_15 , V_33 , V_27 ) ;
if ( V_31 == V_43 )
V_38 . V_6 = V_40 - 1 ;
if ( ! F_18 ( V_15 , V_33 -> V_12 & V_44 ,
& V_38 . V_7 , & V_38 . V_8 ) )
return - V_45 ;
F_19 ( V_15 , V_33 -> V_12 & V_46 , & V_38 . V_5 ) ;
F_19 ( V_15 , V_33 -> V_12 & V_47 , & V_38 . V_3 ) ;
V_38 . V_3 &= F_7 ( V_38 . V_6 + 1 ) ;
return V_36 ( V_27 , & V_38 , & V_42 , & V_33 -> V_42 , V_33 -> V_48 ) ;
}
static int
F_20 ( struct V_26 * V_27 , struct V_49 * V_50 [] ,
enum V_30 V_31 , T_1 * V_51 , T_1 V_12 , bool V_52 )
{
const struct V_34 * V_35 = V_27 -> V_16 ;
T_3 V_36 = V_27 -> V_37 -> V_31 [ V_31 ] ;
struct V_1 V_38 = { . V_6 = V_40 - 1 } ;
struct V_41 V_42 = F_21 ( V_27 ) ;
T_1 V_5 = 0 , V_53 = 0 , V_54 = 0 , V_7 , V_55 ;
T_1 V_56 = 0 , V_57 = 0 , V_58 , V_3 ;
bool V_59 = false ;
T_2 V_6 ;
int V_60 ;
if ( F_22 ( ! V_50 [ V_17 ] || ! V_50 [ V_18 ] ||
! F_23 ( V_50 , V_19 ) ||
! F_24 ( V_50 , V_61 ) ||
! F_24 ( V_50 , V_62 ) ||
! F_24 ( V_50 , V_22 ) ||
! F_24 ( V_50 , V_63 ) ||
! F_24 ( V_50 , V_64 ) ||
! F_24 ( V_50 , V_65 ) ||
! F_24 ( V_50 , V_66 ) ||
! F_24 ( V_50 , V_67 ) ) )
return - V_68 ;
if ( V_50 [ V_69 ] )
* V_51 = F_25 ( V_50 [ V_69 ] ) ;
V_60 = F_26 ( V_50 [ V_17 ] , & V_5 ) ||
F_27 ( V_27 , V_50 , & V_42 ) ;
if ( V_60 )
return V_60 ;
V_60 = F_26 ( V_50 [ V_18 ] , & V_56 ) ;
if ( V_60 )
return V_60 ;
if ( V_50 [ V_20 ] ) {
V_6 = F_28 ( V_50 [ V_20 ] ) ;
if ( ! V_6 || V_6 > V_40 )
return - V_70 ;
V_38 . V_6 = V_6 - 1 ;
}
if ( V_50 [ V_19 ] )
V_38 . V_7 = F_29 ( V_50 [ V_19 ] ) ;
else
return - V_68 ;
if ( V_50 [ V_21 ] ) {
V_38 . V_8 = F_28 ( V_50 [ V_21 ] ) ;
V_59 = F_30 ( V_38 . V_8 ) ;
if ( V_38 . V_8 == 0 )
return - V_71 ;
} else
return - V_72 ;
if ( ! ( V_59 || V_38 . V_8 == V_73 ) )
V_38 . V_7 = 0 ;
if ( V_50 [ V_22 ] ) {
T_1 V_74 = F_31 ( V_50 [ V_22 ] ) ;
if ( V_74 & V_13 )
V_12 |= ( V_13 << 16 ) ;
}
V_59 = V_59 && V_50 [ V_61 ] ;
if ( V_31 == V_43 ||
! ( V_50 [ V_75 ] || V_50 [ V_76 ] || V_59 ||
V_50 [ V_77 ] ) ) {
V_38 . V_5 = F_13 ( V_5 ) ;
V_38 . V_3 = F_13 ( V_56 & F_32 ( V_38 . V_6 + 1 ) ) ;
V_60 = V_36 ( V_27 , & V_38 , & V_42 , & V_42 , V_12 ) ;
return F_33 ( V_60 , V_12 , V_31 , V_27 ) ? - V_60 :
F_34 ( V_60 , V_12 ) ? 0 : V_60 ;
}
V_53 = V_5 ;
if ( V_50 [ V_76 ] ) {
V_60 = F_26 ( V_50 [ V_76 ] , & V_53 ) ;
if ( V_60 )
return V_60 ;
if ( V_5 > V_53 )
F_5 ( V_5 , V_53 ) ;
} else if ( V_50 [ V_75 ] ) {
V_6 = F_28 ( V_50 [ V_75 ] ) ;
if ( ! V_6 || V_6 > 32 )
return - V_70 ;
F_35 ( V_5 , V_53 , V_6 ) ;
}
V_55 = V_7 = F_36 ( V_38 . V_7 ) ;
if ( V_50 [ V_61 ] ) {
V_55 = F_37 ( V_50 [ V_61 ] ) ;
if ( V_7 > V_55 )
F_5 ( V_7 , V_55 ) ;
}
V_57 = V_56 ;
if ( V_50 [ V_77 ] ) {
V_60 = F_26 ( V_50 [ V_77 ] , & V_57 ) ;
if ( V_60 )
return V_60 ;
if ( V_56 > V_57 )
F_5 ( V_56 , V_57 ) ;
if ( V_56 + V_78 == V_57 )
return - V_79 ;
} else
F_35 ( V_56 , V_57 , V_38 . V_6 + 1 ) ;
if ( V_52 )
V_5 = F_38 ( V_35 -> V_24 . V_5 ) ;
for (; ! F_39 ( V_53 , V_5 ) ; V_5 ++ ) {
V_38 . V_5 = F_13 ( V_5 ) ;
V_54 = V_52 && V_5 == F_38 ( V_35 -> V_24 . V_5 ) ? F_36 ( V_35 -> V_24 . V_7 )
: V_7 ;
for (; V_54 <= V_55 ; V_54 ++ ) {
V_38 . V_7 = F_40 ( V_54 ) ;
V_3 = V_52 &&
V_5 == F_38 ( V_35 -> V_24 . V_5 ) &&
V_54 == F_36 ( V_35 -> V_24 . V_7 )
? F_38 ( V_35 -> V_24 . V_3 ) : V_56 ;
while ( ! F_41 ( V_3 , V_57 ) ) {
V_38 . V_3 = F_13 ( V_3 ) ;
V_58 = F_42 ( V_3 , V_57 ,
& V_6 ) ;
V_38 . V_6 = V_6 - 1 ;
V_60 = V_36 ( V_27 , & V_38 , & V_42 , & V_42 , V_12 ) ;
if ( V_60 && ! F_34 ( V_60 , V_12 ) )
return V_60 ;
else
V_60 = 0 ;
V_3 = V_58 + 1 ;
}
}
}
return V_60 ;
}
static inline bool
F_43 ( const struct V_80 * V_2 ,
const struct V_80 * V_3 ,
T_1 * V_4 )
{
return F_44 ( & V_2 -> V_5 . V_81 , & V_3 -> V_5 . V_81 ) &&
F_44 ( & V_2 -> V_3 . V_81 , & V_3 -> V_3 . V_81 ) &&
V_2 -> V_6 == V_3 -> V_6 &&
V_2 -> V_7 == V_3 -> V_7 &&
V_2 -> V_8 == V_3 -> V_8 ;
}
static inline int
F_45 ( const struct V_80 * V_9 )
{
return V_9 -> V_10 ? - V_11 : 1 ;
}
static inline void
F_46 ( struct V_80 * V_9 , T_1 V_12 )
{
V_9 -> V_10 = ! ! ( ( V_12 >> 16 ) & V_13 ) ;
}
static inline void
F_47 ( struct V_80 * V_9 , T_2 * V_12 )
{
F_5 ( * V_12 , V_9 -> V_10 ) ;
}
static inline void
F_48 ( struct V_80 * V_9 , T_2 V_6 )
{
F_49 ( & V_9 -> V_3 , V_6 ) ;
V_9 -> V_6 = V_6 - 1 ;
}
static bool
F_50 ( struct V_14 * V_15 ,
const struct V_80 * V_16 )
{
T_1 V_12 = V_16 -> V_10 ? V_13 : 0 ;
if ( F_51 ( V_15 , V_17 , & V_16 -> V_5 . V_81 ) ||
F_51 ( V_15 , V_18 , & V_16 -> V_3 . V_81 ) ||
F_10 ( V_15 , V_19 , V_16 -> V_7 ) ||
F_11 ( V_15 , V_20 , V_16 -> V_6 + 1 ) ||
F_11 ( V_15 , V_21 , V_16 -> V_8 ) ||
( V_12 &&
F_12 ( V_15 , V_22 , F_13 ( V_12 ) ) ) )
goto V_23;
return 0 ;
V_23:
return 1 ;
}
static inline void
F_52 ( struct V_1 * V_24 ,
const struct V_80 * V_25 )
{
V_24 -> V_7 = V_25 -> V_7 ;
}
static int
F_53 ( struct V_26 * V_27 , const struct V_14 * V_15 ,
const struct V_28 * V_29 ,
enum V_30 V_31 , struct V_32 * V_33 )
{
const struct V_34 * V_35 = V_27 -> V_16 ;
T_3 V_36 = V_27 -> V_37 -> V_31 [ V_31 ] ;
struct V_80 V_38 = {
. V_6 = F_16 ( V_35 -> V_39 [ 0 ] . V_6 [ 0 ] , V_40 ) - 1 ,
} ;
struct V_41 V_42 = F_17 ( V_15 , V_33 , V_27 ) ;
if ( V_31 == V_43 )
V_38 . V_6 = V_40 - 1 ;
if ( ! F_54 ( V_15 , V_33 -> V_12 & V_44 ,
& V_38 . V_7 , & V_38 . V_8 ) )
return - V_45 ;
F_55 ( V_15 , V_33 -> V_12 & V_46 , & V_38 . V_5 . V_81 ) ;
F_55 ( V_15 , V_33 -> V_12 & V_47 , & V_38 . V_3 . V_81 ) ;
F_49 ( & V_38 . V_3 , V_38 . V_6 + 1 ) ;
return V_36 ( V_27 , & V_38 , & V_42 , & V_33 -> V_42 , V_33 -> V_48 ) ;
}
static int
F_56 ( struct V_26 * V_27 , struct V_49 * V_50 [] ,
enum V_30 V_31 , T_1 * V_51 , T_1 V_12 , bool V_52 )
{
const struct V_34 * V_35 = V_27 -> V_16 ;
T_3 V_36 = V_27 -> V_37 -> V_31 [ V_31 ] ;
struct V_80 V_38 = { . V_6 = V_40 - 1 } ;
struct V_41 V_42 = F_21 ( V_27 ) ;
T_1 V_7 , V_55 ;
bool V_59 = false ;
T_2 V_6 ;
int V_60 ;
if ( F_22 ( ! V_50 [ V_17 ] || ! V_50 [ V_18 ] ||
! F_23 ( V_50 , V_19 ) ||
! F_24 ( V_50 , V_61 ) ||
! F_24 ( V_50 , V_62 ) ||
! F_24 ( V_50 , V_22 ) ||
! F_24 ( V_50 , V_63 ) ||
! F_24 ( V_50 , V_64 ) ||
! F_24 ( V_50 , V_65 ) ||
! F_24 ( V_50 , V_66 ) ||
! F_24 ( V_50 , V_67 ) ||
V_50 [ V_76 ] ||
V_50 [ V_75 ] ) )
return - V_68 ;
if ( F_22 ( V_50 [ V_76 ] ) )
return - V_82 ;
if ( V_50 [ V_69 ] )
* V_51 = F_25 ( V_50 [ V_69 ] ) ;
V_60 = F_57 ( V_50 [ V_17 ] , & V_38 . V_5 ) ||
F_27 ( V_27 , V_50 , & V_42 ) ;
if ( V_60 )
return V_60 ;
V_60 = F_57 ( V_50 [ V_18 ] , & V_38 . V_3 ) ;
if ( V_60 )
return V_60 ;
if ( V_50 [ V_20 ] ) {
V_6 = F_28 ( V_50 [ V_20 ] ) ;
if ( ! V_6 || V_6 > V_40 )
return - V_70 ;
V_38 . V_6 = V_6 - 1 ;
}
F_49 ( & V_38 . V_3 , V_38 . V_6 + 1 ) ;
if ( V_50 [ V_19 ] )
V_38 . V_7 = F_29 ( V_50 [ V_19 ] ) ;
else
return - V_68 ;
if ( V_50 [ V_21 ] ) {
V_38 . V_8 = F_28 ( V_50 [ V_21 ] ) ;
V_59 = F_30 ( V_38 . V_8 ) ;
if ( V_38 . V_8 == 0 )
return - V_71 ;
} else
return - V_72 ;
if ( ! ( V_59 || V_38 . V_8 == V_83 ) )
V_38 . V_7 = 0 ;
if ( V_50 [ V_22 ] ) {
T_1 V_74 = F_31 ( V_50 [ V_22 ] ) ;
if ( V_74 & V_13 )
V_12 |= ( V_13 << 16 ) ;
}
if ( V_31 == V_43 || ! V_59 || ! V_50 [ V_61 ] ) {
V_60 = V_36 ( V_27 , & V_38 , & V_42 , & V_42 , V_12 ) ;
return F_33 ( V_60 , V_12 , V_31 , V_27 ) ? - V_60 :
F_34 ( V_60 , V_12 ) ? 0 : V_60 ;
}
V_7 = F_36 ( V_38 . V_7 ) ;
V_55 = F_37 ( V_50 [ V_61 ] ) ;
if ( V_7 > V_55 )
F_5 ( V_7 , V_55 ) ;
if ( V_52 )
V_7 = F_36 ( V_35 -> V_24 . V_7 ) ;
for (; V_7 <= V_55 ; V_7 ++ ) {
V_38 . V_7 = F_40 ( V_7 ) ;
V_60 = V_36 ( V_27 , & V_38 , & V_42 , & V_42 , V_12 ) ;
if ( V_60 && ! F_34 ( V_60 , V_12 ) )
return V_60 ;
else
V_60 = 0 ;
}
return V_60 ;
}
static int T_4
F_58 ( void )
{
return F_59 ( & V_84 ) ;
}
static void T_5
F_60 ( void )
{
F_61 ( & V_84 ) ;
}
