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
F_6 ( struct V_1 * V_9 ,
struct V_1 * V_14 )
{
V_9 -> V_15 [ 1 ] = V_14 -> V_15 [ 1 ] ;
}
static inline void
F_7 ( struct V_1 * V_9 ,
T_2 V_16 , bool V_17 )
{
if ( V_17 ) {
V_9 -> V_15 [ 1 ] &= F_8 ( V_16 ) ;
V_9 -> V_16 [ 1 ] = V_16 ;
} else {
V_9 -> V_15 [ 0 ] &= F_8 ( V_16 ) ;
V_9 -> V_16 [ 0 ] = V_16 ;
}
}
static bool
F_9 ( struct V_18 * V_19 ,
const struct V_1 * V_20 )
{
T_1 V_12 = V_20 -> V_10 ? V_13 : 0 ;
if ( F_10 ( V_19 , V_21 , V_20 -> V_15 [ 0 ] ) ||
F_10 ( V_19 , V_22 , V_20 -> V_15 [ 1 ] ) ||
F_11 ( V_19 , V_23 , V_20 -> V_7 ) ||
F_12 ( V_19 , V_24 , V_20 -> V_16 [ 0 ] ) ||
F_12 ( V_19 , V_25 , V_20 -> V_16 [ 1 ] ) ||
F_12 ( V_19 , V_26 , V_20 -> V_8 ) ||
( V_12 &&
F_13 ( V_19 , V_27 , F_14 ( V_12 ) ) ) )
goto V_28;
return false ;
V_28:
return true ;
}
static inline void
F_15 ( struct V_1 * V_29 ,
const struct V_1 * V_30 )
{
V_29 -> V_5 = V_30 -> V_5 ;
V_29 -> V_7 = V_30 -> V_7 ;
}
static void
F_16 ( struct V_1 * V_31 )
{
V_31 -> V_16 [ 0 ] = V_32 ;
V_31 -> V_16 [ 1 ] = V_32 ;
}
static int
F_17 ( struct V_33 * V_34 , const struct V_18 * V_19 ,
const struct V_35 * V_36 ,
enum V_37 V_38 , struct V_39 * V_40 )
{
const struct V_41 * V_42 = V_34 -> V_20 ;
T_3 V_43 = V_34 -> V_44 -> V_38 [ V_38 ] ;
struct V_1 V_31 = { } ;
struct V_45 V_46 = F_18 ( V_19 , V_40 , V_34 ) ;
V_31 . V_16 [ 0 ] = F_19 ( V_42 -> V_47 [ 0 ] . V_16 [ 0 ] , V_32 ) ;
V_31 . V_16 [ 1 ] = F_19 ( V_42 -> V_47 [ 0 ] . V_16 [ 1 ] , V_32 ) ;
if ( V_38 == V_48 )
V_31 . V_6 = ( V_32 << ( sizeof( V_31 . V_16 [ 0 ] ) * 8 ) ) | V_32 ;
if ( ! F_20 ( V_19 , V_40 -> V_12 & V_49 ,
& V_31 . V_7 , & V_31 . V_8 ) )
return - V_50 ;
F_21 ( V_19 , V_40 -> V_12 & V_51 , & V_31 . V_15 [ 0 ] ) ;
F_21 ( V_19 , V_40 -> V_12 & V_52 , & V_31 . V_15 [ 1 ] ) ;
V_31 . V_15 [ 0 ] &= F_8 ( V_31 . V_16 [ 0 ] ) ;
V_31 . V_15 [ 1 ] &= F_8 ( V_31 . V_16 [ 1 ] ) ;
return V_43 ( V_34 , & V_31 , & V_46 , & V_40 -> V_46 , V_40 -> V_53 ) ;
}
static int
F_22 ( struct V_33 * V_34 , struct V_54 * V_55 [] ,
enum V_37 V_38 , T_1 * V_56 , T_1 V_12 , bool V_57 )
{
const struct V_41 * V_42 = V_34 -> V_20 ;
T_3 V_43 = V_34 -> V_44 -> V_38 [ V_38 ] ;
struct V_1 V_31 = { } ;
struct V_45 V_46 = F_23 ( V_34 ) ;
T_1 V_15 = 0 , V_58 = 0 , V_59 , V_60 = 0 , V_7 , V_61 ;
T_1 V_62 = 0 , V_63 = 0 , V_64 , V_3 ;
bool V_65 = false ;
int V_66 ;
if ( V_55 [ V_67 ] )
* V_56 = F_24 ( V_55 [ V_67 ] ) ;
F_16 ( & V_31 ) ;
if ( F_25 ( ! V_55 [ V_21 ] || ! V_55 [ V_22 ] ||
! F_26 ( V_55 , V_23 ) ||
! F_27 ( V_55 , V_68 ) ||
! F_27 ( V_55 , V_27 ) ) )
return - V_69 ;
V_66 = F_28 ( V_55 [ V_21 ] , & V_15 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_28 ( V_55 [ V_22 ] , & V_62 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_29 ( V_34 , V_55 , & V_46 ) ;
if ( V_66 )
return V_66 ;
if ( V_55 [ V_24 ] ) {
V_31 . V_16 [ 0 ] = F_30 ( V_55 [ V_24 ] ) ;
if ( ! V_31 . V_16 [ 0 ] || V_31 . V_16 [ 0 ] > V_32 )
return - V_70 ;
}
if ( V_55 [ V_25 ] ) {
V_31 . V_16 [ 1 ] = F_30 ( V_55 [ V_25 ] ) ;
if ( ! V_31 . V_16 [ 1 ] || V_31 . V_16 [ 1 ] > V_32 )
return - V_70 ;
}
V_31 . V_7 = F_31 ( V_55 [ V_23 ] ) ;
if ( V_55 [ V_26 ] ) {
V_31 . V_8 = F_30 ( V_55 [ V_26 ] ) ;
V_65 = F_32 ( V_31 . V_8 ) ;
if ( V_31 . V_8 == 0 )
return - V_71 ;
} else {
return - V_72 ;
}
if ( ! ( V_65 || V_31 . V_8 == V_73 ) )
V_31 . V_7 = 0 ;
if ( V_55 [ V_27 ] ) {
T_1 V_74 = F_33 ( V_55 [ V_27 ] ) ;
if ( V_74 & V_13 )
V_12 |= ( V_13 << 16 ) ;
}
V_65 = V_65 && V_55 [ V_68 ] ;
if ( V_38 == V_48 ||
! ( V_55 [ V_75 ] || V_65 || V_55 [ V_76 ] ) ) {
V_31 . V_15 [ 0 ] = F_14 ( V_15 & F_34 ( V_31 . V_16 [ 0 ] ) ) ;
V_31 . V_15 [ 1 ] = F_14 ( V_62 & F_34 ( V_31 . V_16 [ 1 ] ) ) ;
V_66 = V_43 ( V_34 , & V_31 , & V_46 , & V_46 , V_12 ) ;
return F_35 ( V_66 , V_12 , V_38 , V_34 ) ? - V_66 :
F_36 ( V_66 , V_12 ) ? 0 : V_66 ;
}
V_58 = V_15 ;
if ( V_55 [ V_75 ] ) {
V_66 = F_28 ( V_55 [ V_75 ] , & V_58 ) ;
if ( V_66 )
return V_66 ;
if ( V_15 > V_58 )
F_5 ( V_15 , V_58 ) ;
if ( F_25 ( V_15 + V_77 == V_58 ) )
return - V_78 ;
} else {
F_37 ( V_15 , V_58 , V_31 . V_16 [ 0 ] ) ;
}
V_61 = V_7 = F_38 ( V_31 . V_7 ) ;
if ( V_55 [ V_68 ] ) {
V_61 = F_39 ( V_55 [ V_68 ] ) ;
if ( V_7 > V_61 )
F_5 ( V_7 , V_61 ) ;
}
V_63 = V_62 ;
if ( V_55 [ V_76 ] ) {
V_66 = F_28 ( V_55 [ V_76 ] , & V_63 ) ;
if ( V_66 )
return V_66 ;
if ( V_62 > V_63 )
F_5 ( V_62 , V_63 ) ;
if ( F_25 ( V_62 + V_77 == V_63 ) )
return - V_78 ;
} else {
F_37 ( V_62 , V_63 , V_31 . V_16 [ 1 ] ) ;
}
if ( V_57 )
V_15 = F_40 ( V_42 -> V_29 . V_15 [ 0 ] ) ;
while ( ! F_41 ( V_15 , V_58 ) ) {
V_31 . V_15 [ 0 ] = F_14 ( V_15 ) ;
V_59 = F_42 ( V_15 , V_58 , & V_31 . V_16 [ 0 ] ) ;
V_60 = V_57 && V_15 == F_40 ( V_42 -> V_29 . V_15 [ 0 ] ) ? F_38 ( V_42 -> V_29 . V_7 )
: V_7 ;
for (; V_60 <= V_61 ; V_60 ++ ) {
V_31 . V_7 = F_43 ( V_60 ) ;
V_3 = ( V_57 && V_15 == F_40 ( V_42 -> V_29 . V_15 [ 0 ] ) &&
V_60 == F_38 ( V_42 -> V_29 . V_7 ) ) ? F_40 ( V_42 -> V_29 . V_15 [ 1 ] )
: V_62 ;
while ( ! F_41 ( V_3 , V_63 ) ) {
V_31 . V_15 [ 1 ] = F_14 ( V_3 ) ;
V_64 = F_42 ( V_3 , V_63 ,
& V_31 . V_16 [ 1 ] ) ;
V_66 = V_43 ( V_34 , & V_31 , & V_46 , & V_46 , V_12 ) ;
if ( V_66 && ! F_36 ( V_66 , V_12 ) )
return V_66 ;
V_66 = 0 ;
V_3 = V_64 + 1 ;
}
}
V_15 = V_59 + 1 ;
}
return V_66 ;
}
static inline bool
F_44 ( const struct V_79 * V_2 ,
const struct V_79 * V_3 ,
T_1 * V_4 )
{
return F_45 ( & V_2 -> V_15 [ 0 ] . V_80 , & V_3 -> V_15 [ 0 ] . V_80 ) &&
F_45 ( & V_2 -> V_15 [ 1 ] . V_80 , & V_3 -> V_15 [ 1 ] . V_80 ) &&
V_2 -> V_6 == V_3 -> V_6 &&
V_2 -> V_7 == V_3 -> V_7 &&
V_2 -> V_8 == V_3 -> V_8 ;
}
static inline int
F_46 ( const struct V_79 * V_9 )
{
return V_9 -> V_10 ? - V_11 : 1 ;
}
static inline void
F_47 ( struct V_79 * V_9 , T_1 V_12 )
{
V_9 -> V_10 = ! ! ( ( V_12 >> 16 ) & V_13 ) ;
}
static inline void
F_48 ( struct V_79 * V_9 , T_2 * V_12 )
{
F_5 ( * V_12 , V_9 -> V_10 ) ;
}
static inline void
F_49 ( struct V_79 * V_9 ,
struct V_79 * V_14 )
{
V_9 -> V_15 [ 1 ] = V_14 -> V_15 [ 1 ] ;
}
static inline void
F_50 ( struct V_79 * V_9 ,
T_2 V_16 , bool V_17 )
{
if ( V_17 ) {
F_51 ( & V_9 -> V_15 [ 1 ] , V_16 ) ;
V_9 -> V_16 [ 1 ] = V_16 ;
} else {
F_51 ( & V_9 -> V_15 [ 0 ] , V_16 ) ;
V_9 -> V_16 [ 0 ] = V_16 ;
}
}
static bool
F_52 ( struct V_18 * V_19 ,
const struct V_79 * V_20 )
{
T_1 V_12 = V_20 -> V_10 ? V_13 : 0 ;
if ( F_53 ( V_19 , V_21 , & V_20 -> V_15 [ 0 ] . V_80 ) ||
F_53 ( V_19 , V_22 , & V_20 -> V_15 [ 1 ] . V_80 ) ||
F_11 ( V_19 , V_23 , V_20 -> V_7 ) ||
F_12 ( V_19 , V_24 , V_20 -> V_16 [ 0 ] ) ||
F_12 ( V_19 , V_25 , V_20 -> V_16 [ 1 ] ) ||
F_12 ( V_19 , V_26 , V_20 -> V_8 ) ||
( V_12 &&
F_13 ( V_19 , V_27 , F_14 ( V_12 ) ) ) )
goto V_28;
return false ;
V_28:
return true ;
}
static inline void
F_54 ( struct V_79 * V_29 ,
const struct V_79 * V_30 )
{
V_29 -> V_7 = V_30 -> V_7 ;
}
static void
F_55 ( struct V_79 * V_31 )
{
V_31 -> V_16 [ 0 ] = V_32 ;
V_31 -> V_16 [ 1 ] = V_32 ;
}
static int
F_56 ( struct V_33 * V_34 , const struct V_18 * V_19 ,
const struct V_35 * V_36 ,
enum V_37 V_38 , struct V_39 * V_40 )
{
const struct V_81 * V_42 = V_34 -> V_20 ;
T_3 V_43 = V_34 -> V_44 -> V_38 [ V_38 ] ;
struct V_79 V_31 = { } ;
struct V_45 V_46 = F_18 ( V_19 , V_40 , V_34 ) ;
V_31 . V_16 [ 0 ] = F_19 ( V_42 -> V_47 [ 0 ] . V_16 [ 0 ] , V_32 ) ;
V_31 . V_16 [ 1 ] = F_19 ( V_42 -> V_47 [ 0 ] . V_16 [ 1 ] , V_32 ) ;
if ( V_38 == V_48 )
V_31 . V_6 = ( V_32 << ( sizeof( T_2 ) * 8 ) ) | V_32 ;
if ( ! F_57 ( V_19 , V_40 -> V_12 & V_49 ,
& V_31 . V_7 , & V_31 . V_8 ) )
return - V_50 ;
F_58 ( V_19 , V_40 -> V_12 & V_51 , & V_31 . V_15 [ 0 ] . V_80 ) ;
F_58 ( V_19 , V_40 -> V_12 & V_52 , & V_31 . V_15 [ 1 ] . V_80 ) ;
F_51 ( & V_31 . V_15 [ 0 ] , V_31 . V_16 [ 0 ] ) ;
F_51 ( & V_31 . V_15 [ 1 ] , V_31 . V_16 [ 1 ] ) ;
return V_43 ( V_34 , & V_31 , & V_46 , & V_40 -> V_46 , V_40 -> V_53 ) ;
}
static int
F_59 ( struct V_33 * V_34 , struct V_54 * V_55 [] ,
enum V_37 V_38 , T_1 * V_56 , T_1 V_12 , bool V_57 )
{
const struct V_81 * V_42 = V_34 -> V_20 ;
T_3 V_43 = V_34 -> V_44 -> V_38 [ V_38 ] ;
struct V_79 V_31 = { } ;
struct V_45 V_46 = F_23 ( V_34 ) ;
T_1 V_7 , V_61 ;
bool V_65 = false ;
int V_66 ;
if ( V_55 [ V_67 ] )
* V_56 = F_24 ( V_55 [ V_67 ] ) ;
F_55 ( & V_31 ) ;
if ( F_25 ( ! V_55 [ V_21 ] || ! V_55 [ V_22 ] ||
! F_26 ( V_55 , V_23 ) ||
! F_27 ( V_55 , V_68 ) ||
! F_27 ( V_55 , V_27 ) ) )
return - V_69 ;
if ( F_25 ( V_55 [ V_75 ] || V_55 [ V_76 ] ) )
return - V_82 ;
V_66 = F_60 ( V_55 [ V_21 ] , & V_31 . V_15 [ 0 ] ) ;
if ( V_66 )
return V_66 ;
V_66 = F_60 ( V_55 [ V_22 ] , & V_31 . V_15 [ 1 ] ) ;
if ( V_66 )
return V_66 ;
V_66 = F_29 ( V_34 , V_55 , & V_46 ) ;
if ( V_66 )
return V_66 ;
if ( V_55 [ V_24 ] ) {
V_31 . V_16 [ 0 ] = F_30 ( V_55 [ V_24 ] ) ;
if ( ! V_31 . V_16 [ 0 ] || V_31 . V_16 [ 0 ] > V_32 )
return - V_70 ;
}
if ( V_55 [ V_25 ] ) {
V_31 . V_16 [ 1 ] = F_30 ( V_55 [ V_25 ] ) ;
if ( ! V_31 . V_16 [ 1 ] || V_31 . V_16 [ 1 ] > V_32 )
return - V_70 ;
}
F_51 ( & V_31 . V_15 [ 0 ] , V_31 . V_16 [ 0 ] ) ;
F_51 ( & V_31 . V_15 [ 1 ] , V_31 . V_16 [ 1 ] ) ;
V_31 . V_7 = F_31 ( V_55 [ V_23 ] ) ;
if ( V_55 [ V_26 ] ) {
V_31 . V_8 = F_30 ( V_55 [ V_26 ] ) ;
V_65 = F_32 ( V_31 . V_8 ) ;
if ( V_31 . V_8 == 0 )
return - V_71 ;
} else {
return - V_72 ;
}
if ( ! ( V_65 || V_31 . V_8 == V_83 ) )
V_31 . V_7 = 0 ;
if ( V_55 [ V_27 ] ) {
T_1 V_74 = F_33 ( V_55 [ V_27 ] ) ;
if ( V_74 & V_13 )
V_12 |= ( V_13 << 16 ) ;
}
if ( V_38 == V_48 || ! V_65 || ! V_55 [ V_68 ] ) {
V_66 = V_43 ( V_34 , & V_31 , & V_46 , & V_46 , V_12 ) ;
return F_35 ( V_66 , V_12 , V_38 , V_34 ) ? - V_66 :
F_36 ( V_66 , V_12 ) ? 0 : V_66 ;
}
V_7 = F_38 ( V_31 . V_7 ) ;
V_61 = F_39 ( V_55 [ V_68 ] ) ;
if ( V_7 > V_61 )
F_5 ( V_7 , V_61 ) ;
if ( V_57 )
V_7 = F_38 ( V_42 -> V_29 . V_7 ) ;
for (; V_7 <= V_61 ; V_7 ++ ) {
V_31 . V_7 = F_43 ( V_7 ) ;
V_66 = V_43 ( V_34 , & V_31 , & V_46 , & V_46 , V_12 ) ;
if ( V_66 && ! F_36 ( V_66 , V_12 ) )
return V_66 ;
V_66 = 0 ;
}
return V_66 ;
}
static int T_4
F_61 ( void )
{
return F_62 ( & V_84 ) ;
}
static void T_5
F_63 ( void )
{
F_64 () ;
F_65 ( & V_84 ) ;
}
