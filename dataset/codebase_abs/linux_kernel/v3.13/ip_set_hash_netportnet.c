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
return 0 ;
V_28:
return 1 ;
}
static inline void
F_15 ( struct V_1 * V_29 ,
const struct V_1 * V_30 )
{
V_29 -> V_5 = V_30 -> V_5 ;
V_29 -> V_7 = V_30 -> V_7 ;
}
static int
F_16 ( struct V_31 * V_32 , const struct V_18 * V_19 ,
const struct V_33 * V_34 ,
enum V_35 V_36 , struct V_37 * V_38 )
{
const struct V_39 * V_40 = V_32 -> V_20 ;
T_3 V_41 = V_32 -> V_42 -> V_36 [ V_36 ] ;
struct V_1 V_43 = { } ;
struct V_44 V_45 = F_17 ( V_19 , V_38 , V_32 ) ;
V_43 . V_16 [ 0 ] = F_18 ( V_40 -> V_46 [ 0 ] . V_16 [ 0 ] , V_47 ) ;
V_43 . V_16 [ 1 ] = F_18 ( V_40 -> V_46 [ 0 ] . V_16 [ 1 ] , V_47 ) ;
if ( V_36 == V_48 )
V_43 . V_6 = ( V_47 << ( sizeof( V_43 . V_16 [ 0 ] ) * 8 ) ) | V_47 ;
if ( ! F_19 ( V_19 , V_38 -> V_12 & V_49 ,
& V_43 . V_7 , & V_43 . V_8 ) )
return - V_50 ;
F_20 ( V_19 , V_38 -> V_12 & V_51 , & V_43 . V_15 [ 0 ] ) ;
F_20 ( V_19 , V_38 -> V_12 & V_52 , & V_43 . V_15 [ 1 ] ) ;
V_43 . V_15 [ 0 ] &= F_8 ( V_43 . V_16 [ 0 ] ) ;
V_43 . V_15 [ 1 ] &= F_8 ( V_43 . V_16 [ 1 ] ) ;
return V_41 ( V_32 , & V_43 , & V_45 , & V_38 -> V_45 , V_38 -> V_53 ) ;
}
static int
F_21 ( struct V_31 * V_32 , struct V_54 * V_55 [] ,
enum V_35 V_36 , T_1 * V_56 , T_1 V_12 , bool V_57 )
{
const struct V_39 * V_40 = V_32 -> V_20 ;
T_3 V_41 = V_32 -> V_42 -> V_36 [ V_36 ] ;
struct V_1 V_43 = { } ;
struct V_44 V_45 = F_22 ( V_32 ) ;
T_1 V_15 = 0 , V_58 = 0 , V_59 , V_60 = 0 , V_7 , V_61 ;
T_1 V_62 = 0 , V_63 = 0 , V_64 , V_3 ;
bool V_65 = false ;
T_2 V_16 , V_66 ;
int V_67 ;
V_43 . V_16 [ 0 ] = V_43 . V_16 [ 1 ] = V_47 ;
if ( F_23 ( ! V_55 [ V_21 ] || ! V_55 [ V_22 ] ||
! F_24 ( V_55 , V_23 ) ||
! F_25 ( V_55 , V_68 ) ||
! F_25 ( V_55 , V_69 ) ||
! F_25 ( V_55 , V_27 ) ||
! F_25 ( V_55 , V_70 ) ||
! F_25 ( V_55 , V_71 ) ) )
return - V_72 ;
if ( V_55 [ V_73 ] )
* V_56 = F_26 ( V_55 [ V_73 ] ) ;
V_67 = F_27 ( V_55 [ V_21 ] , & V_15 ) ||
F_27 ( V_55 [ V_22 ] , & V_62 ) ||
F_28 ( V_32 , V_55 , & V_45 ) ;
if ( V_67 )
return V_67 ;
if ( V_55 [ V_24 ] ) {
V_16 = F_29 ( V_55 [ V_24 ] ) ;
if ( ! V_16 || V_16 > V_47 )
return - V_74 ;
V_43 . V_16 [ 0 ] = V_16 ;
}
if ( V_55 [ V_25 ] ) {
V_16 = F_29 ( V_55 [ V_25 ] ) ;
if ( ! V_16 || V_16 > V_47 )
return - V_74 ;
V_43 . V_16 [ 1 ] = V_16 ;
}
if ( V_55 [ V_23 ] )
V_43 . V_7 = F_30 ( V_55 [ V_23 ] ) ;
else
return - V_72 ;
if ( V_55 [ V_26 ] ) {
V_43 . V_8 = F_29 ( V_55 [ V_26 ] ) ;
V_65 = F_31 ( V_43 . V_8 ) ;
if ( V_43 . V_8 == 0 )
return - V_75 ;
} else
return - V_76 ;
if ( ! ( V_65 || V_43 . V_8 == V_77 ) )
V_43 . V_7 = 0 ;
if ( V_55 [ V_27 ] ) {
T_1 V_78 = F_32 ( V_55 [ V_27 ] ) ;
if ( V_78 & V_13 )
V_12 |= ( V_13 << 16 ) ;
}
V_65 = V_65 && V_55 [ V_68 ] ;
if ( V_36 == V_48 ||
! ( V_55 [ V_79 ] || V_65 || V_55 [ V_80 ] ) ) {
V_43 . V_15 [ 0 ] = F_14 ( V_15 & F_33 ( V_43 . V_16 [ 0 ] ) ) ;
V_43 . V_15 [ 1 ] = F_14 ( V_62 & F_33 ( V_43 . V_16 [ 1 ] ) ) ;
V_67 = V_41 ( V_32 , & V_43 , & V_45 , & V_45 , V_12 ) ;
return F_34 ( V_67 , V_12 , V_36 , V_32 ) ? - V_67 :
F_35 ( V_67 , V_12 ) ? 0 : V_67 ;
}
V_58 = V_15 ;
if ( V_55 [ V_79 ] ) {
V_67 = F_27 ( V_55 [ V_79 ] , & V_58 ) ;
if ( V_67 )
return V_67 ;
if ( V_15 > V_58 )
F_5 ( V_15 , V_58 ) ;
if ( F_23 ( V_15 + V_81 == V_58 ) )
return - V_82 ;
}
V_61 = V_7 = F_36 ( V_43 . V_7 ) ;
if ( V_55 [ V_68 ] ) {
V_61 = F_37 ( V_55 [ V_68 ] ) ;
if ( V_7 > V_61 )
F_5 ( V_7 , V_61 ) ;
}
V_63 = V_62 ;
if ( V_55 [ V_80 ] ) {
V_67 = F_27 ( V_55 [ V_80 ] , & V_63 ) ;
if ( V_67 )
return V_67 ;
if ( V_62 > V_63 )
F_5 ( V_62 , V_63 ) ;
if ( F_23 ( V_62 + V_81 == V_63 ) )
return - V_82 ;
}
if ( V_57 )
V_15 = F_38 ( V_40 -> V_29 . V_15 [ 0 ] ) ;
while ( ! F_39 ( V_15 , V_58 ) ) {
V_43 . V_15 [ 0 ] = F_14 ( V_15 ) ;
V_59 = F_40 ( V_15 , V_58 , & V_16 ) ;
V_43 . V_16 [ 0 ] = V_16 ;
V_60 = V_57 && V_15 == F_38 ( V_40 -> V_29 . V_15 [ 0 ] ) ? F_36 ( V_40 -> V_29 . V_7 )
: V_7 ;
for (; V_60 <= V_61 ; V_60 ++ ) {
V_43 . V_7 = F_41 ( V_60 ) ;
V_3 = ( V_57 && V_15 == F_38 ( V_40 -> V_29 . V_15 [ 0 ] ) &&
V_60 == F_36 ( V_40 -> V_29 . V_7 ) ) ? F_38 ( V_40 -> V_29 . V_15 [ 1 ] )
: V_62 ;
while ( ! F_39 ( V_3 , V_63 ) ) {
V_43 . V_15 [ 1 ] = F_14 ( V_3 ) ;
V_64 = F_40 ( V_3 , V_63 ,
& V_66 ) ;
V_43 . V_16 [ 1 ] = V_66 ;
V_67 = V_41 ( V_32 , & V_43 , & V_45 , & V_45 , V_12 ) ;
if ( V_67 && ! F_35 ( V_67 , V_12 ) )
return V_67 ;
else
V_67 = 0 ;
V_3 = V_64 + 1 ;
}
}
V_15 = V_59 + 1 ;
}
return V_67 ;
}
static inline bool
F_42 ( const struct V_83 * V_2 ,
const struct V_83 * V_3 ,
T_1 * V_4 )
{
return F_43 ( & V_2 -> V_15 [ 0 ] . V_84 , & V_3 -> V_15 [ 0 ] . V_84 ) &&
F_43 ( & V_2 -> V_15 [ 1 ] . V_84 , & V_3 -> V_15 [ 1 ] . V_84 ) &&
V_2 -> V_6 == V_3 -> V_6 &&
V_2 -> V_7 == V_3 -> V_7 &&
V_2 -> V_8 == V_3 -> V_8 ;
}
static inline int
F_44 ( const struct V_83 * V_9 )
{
return V_9 -> V_10 ? - V_11 : 1 ;
}
static inline void
F_45 ( struct V_83 * V_9 , T_1 V_12 )
{
V_9 -> V_10 = ! ! ( ( V_12 >> 16 ) & V_13 ) ;
}
static inline void
F_46 ( struct V_83 * V_9 , T_2 * V_12 )
{
F_5 ( * V_12 , V_9 -> V_10 ) ;
}
static inline void
F_47 ( struct V_83 * V_9 ,
struct V_83 * V_14 )
{
V_9 -> V_15 [ 1 ] = V_14 -> V_15 [ 1 ] ;
}
static inline void
F_48 ( struct V_83 * V_9 ,
T_2 V_16 , bool V_17 )
{
if ( V_17 ) {
F_49 ( & V_9 -> V_15 [ 1 ] , V_16 ) ;
V_9 -> V_16 [ 1 ] = V_16 ;
} else {
F_49 ( & V_9 -> V_15 [ 0 ] , V_16 ) ;
V_9 -> V_16 [ 0 ] = V_16 ;
}
}
static bool
F_50 ( struct V_18 * V_19 ,
const struct V_83 * V_20 )
{
T_1 V_12 = V_20 -> V_10 ? V_13 : 0 ;
if ( F_51 ( V_19 , V_21 , & V_20 -> V_15 [ 0 ] . V_84 ) ||
F_51 ( V_19 , V_22 , & V_20 -> V_15 [ 1 ] . V_84 ) ||
F_11 ( V_19 , V_23 , V_20 -> V_7 ) ||
F_12 ( V_19 , V_24 , V_20 -> V_16 [ 0 ] ) ||
F_12 ( V_19 , V_25 , V_20 -> V_16 [ 1 ] ) ||
F_12 ( V_19 , V_26 , V_20 -> V_8 ) ||
( V_12 &&
F_13 ( V_19 , V_27 , F_14 ( V_12 ) ) ) )
goto V_28;
return 0 ;
V_28:
return 1 ;
}
static inline void
F_52 ( struct V_1 * V_29 ,
const struct V_83 * V_30 )
{
V_29 -> V_7 = V_30 -> V_7 ;
}
static int
F_53 ( struct V_31 * V_32 , const struct V_18 * V_19 ,
const struct V_33 * V_34 ,
enum V_35 V_36 , struct V_37 * V_38 )
{
const struct V_39 * V_40 = V_32 -> V_20 ;
T_3 V_41 = V_32 -> V_42 -> V_36 [ V_36 ] ;
struct V_83 V_43 = { } ;
struct V_44 V_45 = F_17 ( V_19 , V_38 , V_32 ) ;
V_43 . V_16 [ 0 ] = F_18 ( V_40 -> V_46 [ 0 ] . V_16 [ 0 ] , V_47 ) ;
V_43 . V_16 [ 1 ] = F_18 ( V_40 -> V_46 [ 0 ] . V_16 [ 1 ] , V_47 ) ;
if ( V_36 == V_48 )
V_43 . V_6 = ( V_47 << ( sizeof( T_2 ) * 8 ) ) | V_47 ;
if ( ! F_54 ( V_19 , V_38 -> V_12 & V_49 ,
& V_43 . V_7 , & V_43 . V_8 ) )
return - V_50 ;
F_55 ( V_19 , V_38 -> V_12 & V_51 , & V_43 . V_15 [ 0 ] . V_84 ) ;
F_55 ( V_19 , V_38 -> V_12 & V_52 , & V_43 . V_15 [ 1 ] . V_84 ) ;
F_49 ( & V_43 . V_15 [ 0 ] , V_43 . V_16 [ 0 ] ) ;
F_49 ( & V_43 . V_15 [ 1 ] , V_43 . V_16 [ 1 ] ) ;
return V_41 ( V_32 , & V_43 , & V_45 , & V_38 -> V_45 , V_38 -> V_53 ) ;
}
static int
F_56 ( struct V_31 * V_32 , struct V_54 * V_55 [] ,
enum V_35 V_36 , T_1 * V_56 , T_1 V_12 , bool V_57 )
{
const struct V_39 * V_40 = V_32 -> V_20 ;
T_3 V_41 = V_32 -> V_42 -> V_36 [ V_36 ] ;
struct V_83 V_43 = { } ;
struct V_44 V_45 = F_22 ( V_32 ) ;
T_1 V_7 , V_61 ;
bool V_65 = false ;
int V_67 ;
V_43 . V_16 [ 0 ] = V_43 . V_16 [ 1 ] = V_47 ;
if ( F_23 ( ! V_55 [ V_21 ] || ! V_55 [ V_22 ] ||
! F_24 ( V_55 , V_23 ) ||
! F_25 ( V_55 , V_68 ) ||
! F_25 ( V_55 , V_69 ) ||
! F_25 ( V_55 , V_27 ) ||
! F_25 ( V_55 , V_70 ) ||
! F_25 ( V_55 , V_71 ) ) )
return - V_72 ;
if ( F_23 ( V_55 [ V_79 ] || V_55 [ V_80 ] ) )
return - V_85 ;
if ( V_55 [ V_73 ] )
* V_56 = F_26 ( V_55 [ V_73 ] ) ;
V_67 = F_57 ( V_55 [ V_21 ] , & V_43 . V_15 [ 0 ] ) ||
F_57 ( V_55 [ V_22 ] , & V_43 . V_15 [ 1 ] ) ||
F_28 ( V_32 , V_55 , & V_45 ) ;
if ( V_67 )
return V_67 ;
if ( V_55 [ V_24 ] )
V_43 . V_16 [ 0 ] = F_29 ( V_55 [ V_24 ] ) ;
if ( V_55 [ V_25 ] )
V_43 . V_16 [ 1 ] = F_29 ( V_55 [ V_25 ] ) ;
if ( F_23 ( ! V_43 . V_16 [ 0 ] || V_43 . V_16 [ 0 ] > V_47 || ! V_43 . V_16 [ 1 ] ||
V_43 . V_16 [ 1 ] > V_47 ) )
return - V_74 ;
F_49 ( & V_43 . V_15 [ 0 ] , V_43 . V_16 [ 0 ] ) ;
F_49 ( & V_43 . V_15 [ 1 ] , V_43 . V_16 [ 1 ] ) ;
if ( V_55 [ V_23 ] )
V_43 . V_7 = F_30 ( V_55 [ V_23 ] ) ;
else
return - V_72 ;
if ( V_55 [ V_26 ] ) {
V_43 . V_8 = F_29 ( V_55 [ V_26 ] ) ;
V_65 = F_31 ( V_43 . V_8 ) ;
if ( V_43 . V_8 == 0 )
return - V_75 ;
} else
return - V_76 ;
if ( ! ( V_65 || V_43 . V_8 == V_86 ) )
V_43 . V_7 = 0 ;
if ( V_55 [ V_27 ] ) {
T_1 V_78 = F_32 ( V_55 [ V_27 ] ) ;
if ( V_78 & V_13 )
V_12 |= ( V_13 << 16 ) ;
}
if ( V_36 == V_48 || ! V_65 || ! V_55 [ V_68 ] ) {
V_67 = V_41 ( V_32 , & V_43 , & V_45 , & V_45 , V_12 ) ;
return F_34 ( V_67 , V_12 , V_36 , V_32 ) ? - V_67 :
F_35 ( V_67 , V_12 ) ? 0 : V_67 ;
}
V_7 = F_36 ( V_43 . V_7 ) ;
V_61 = F_37 ( V_55 [ V_68 ] ) ;
if ( V_7 > V_61 )
F_5 ( V_7 , V_61 ) ;
if ( V_57 )
V_7 = F_36 ( V_40 -> V_29 . V_7 ) ;
for (; V_7 <= V_61 ; V_7 ++ ) {
V_43 . V_7 = F_41 ( V_7 ) ;
V_67 = V_41 ( V_32 , & V_43 , & V_45 , & V_45 , V_12 ) ;
if ( V_67 && ! F_35 ( V_67 , V_12 ) )
return V_67 ;
else
V_67 = 0 ;
}
return V_67 ;
}
static int T_4
F_58 ( void )
{
return F_59 ( & V_87 ) ;
}
static void T_5
F_60 ( void )
{
F_61 ( & V_87 ) ;
}
