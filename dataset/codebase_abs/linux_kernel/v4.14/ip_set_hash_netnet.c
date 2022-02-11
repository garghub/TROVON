static inline bool
F_1 ( const struct V_1 * V_2 ,
const struct V_1 * V_3 ,
T_1 * V_4 )
{
return V_2 -> V_5 == V_3 -> V_5 &&
V_2 -> V_6 == V_3 -> V_6 ;
}
static inline int
F_2 ( const struct V_1 * V_7 )
{
return V_7 -> V_8 ? - V_9 : 1 ;
}
static inline void
F_3 ( struct V_1 * V_7 , T_1 V_10 )
{
V_7 -> V_8 = ( V_10 >> 16 ) & V_11 ;
}
static inline void
F_4 ( struct V_1 * V_7 , T_2 * V_10 )
{
F_5 ( * V_10 , V_7 -> V_8 ) ;
}
static inline void
F_6 ( struct V_1 * V_7 ,
struct V_1 * V_12 )
{
V_7 -> V_13 [ 1 ] = V_12 -> V_13 [ 1 ] ;
}
static inline void
F_7 ( struct V_1 * V_7 , T_2 V_14 , bool V_15 )
{
if ( V_15 ) {
V_7 -> V_13 [ 1 ] &= F_8 ( V_14 ) ;
V_7 -> V_14 [ 1 ] = V_14 ;
} else {
V_7 -> V_13 [ 0 ] &= F_8 ( V_14 ) ;
V_7 -> V_14 [ 0 ] = V_14 ;
}
}
static bool
F_9 ( struct V_16 * V_17 ,
const struct V_1 * V_18 )
{
T_1 V_10 = V_18 -> V_8 ? V_11 : 0 ;
if ( F_10 ( V_17 , V_19 , V_18 -> V_13 [ 0 ] ) ||
F_10 ( V_17 , V_20 , V_18 -> V_13 [ 1 ] ) ||
F_11 ( V_17 , V_21 , V_18 -> V_14 [ 0 ] ) ||
F_11 ( V_17 , V_22 , V_18 -> V_14 [ 1 ] ) ||
( V_10 &&
F_12 ( V_17 , V_23 , F_13 ( V_10 ) ) ) )
goto V_24;
return false ;
V_24:
return true ;
}
static inline void
F_14 ( struct V_1 * V_25 ,
const struct V_1 * V_26 )
{
V_25 -> V_5 = V_26 -> V_5 ;
}
static void
F_15 ( struct V_1 * V_27 )
{
V_27 -> V_14 [ 0 ] = V_28 ;
V_27 -> V_14 [ 1 ] = V_28 ;
}
static int
F_16 ( struct V_29 * V_30 , const struct V_16 * V_17 ,
const struct V_31 * V_32 ,
enum V_33 V_34 , struct V_35 * V_36 )
{
const struct V_37 * V_38 = V_30 -> V_18 ;
T_3 V_39 = V_30 -> V_40 -> V_34 [ V_34 ] ;
struct V_1 V_27 = { } ;
struct V_41 V_42 = F_17 ( V_17 , V_36 , V_30 ) ;
V_27 . V_14 [ 0 ] = F_18 ( V_38 -> V_43 [ 0 ] . V_14 [ 0 ] , V_28 ) ;
V_27 . V_14 [ 1 ] = F_18 ( V_38 -> V_43 [ 0 ] . V_14 [ 1 ] , V_28 ) ;
if ( V_34 == V_44 )
V_27 . V_6 = ( V_28 << ( sizeof( V_27 . V_14 [ 0 ] ) * 8 ) ) | V_28 ;
F_19 ( V_17 , V_36 -> V_10 & V_45 , & V_27 . V_13 [ 0 ] ) ;
F_19 ( V_17 , V_36 -> V_10 & V_46 , & V_27 . V_13 [ 1 ] ) ;
V_27 . V_13 [ 0 ] &= F_8 ( V_27 . V_14 [ 0 ] ) ;
V_27 . V_13 [ 1 ] &= F_8 ( V_27 . V_14 [ 1 ] ) ;
return V_39 ( V_30 , & V_27 , & V_42 , & V_36 -> V_42 , V_36 -> V_47 ) ;
}
static int
F_20 ( struct V_29 * V_30 , struct V_48 * V_49 [] ,
enum V_33 V_34 , T_1 * V_50 , T_1 V_10 , bool V_51 )
{
const struct V_37 * V_38 = V_30 -> V_18 ;
T_3 V_39 = V_30 -> V_40 -> V_34 [ V_34 ] ;
struct V_1 V_27 = { } ;
struct V_41 V_42 = F_21 ( V_30 ) ;
T_1 V_13 = 0 , V_52 = 0 , V_53 ;
T_1 V_3 = 0 , V_54 = 0 , V_55 = 0 , V_56 ;
int V_57 ;
if ( V_49 [ V_58 ] )
* V_50 = F_22 ( V_49 [ V_58 ] ) ;
F_15 ( & V_27 ) ;
if ( F_23 ( ! V_49 [ V_19 ] || ! V_49 [ V_20 ] ||
! F_24 ( V_49 , V_23 ) ) )
return - V_59 ;
V_57 = F_25 ( V_49 [ V_19 ] , & V_13 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_25 ( V_49 [ V_20 ] , & V_54 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_26 ( V_30 , V_49 , & V_42 ) ;
if ( V_57 )
return V_57 ;
if ( V_49 [ V_21 ] ) {
V_27 . V_14 [ 0 ] = F_27 ( V_49 [ V_21 ] ) ;
if ( ! V_27 . V_14 [ 0 ] || V_27 . V_14 [ 0 ] > V_28 )
return - V_60 ;
}
if ( V_49 [ V_22 ] ) {
V_27 . V_14 [ 1 ] = F_27 ( V_49 [ V_22 ] ) ;
if ( ! V_27 . V_14 [ 1 ] || V_27 . V_14 [ 1 ] > V_28 )
return - V_60 ;
}
if ( V_49 [ V_23 ] ) {
T_1 V_61 = F_28 ( V_49 [ V_23 ] ) ;
if ( V_61 & V_11 )
V_10 |= ( V_11 << 16 ) ;
}
if ( V_34 == V_44 || ! ( V_49 [ V_62 ] ||
V_49 [ V_63 ] ) ) {
V_27 . V_13 [ 0 ] = F_13 ( V_13 & F_29 ( V_27 . V_14 [ 0 ] ) ) ;
V_27 . V_13 [ 1 ] = F_13 ( V_54 & F_29 ( V_27 . V_14 [ 1 ] ) ) ;
V_57 = V_39 ( V_30 , & V_27 , & V_42 , & V_42 , V_10 ) ;
return F_30 ( V_57 , V_10 , V_34 , V_30 ) ? - V_57 :
F_31 ( V_57 , V_10 ) ? 0 : V_57 ;
}
V_52 = V_13 ;
if ( V_49 [ V_62 ] ) {
V_57 = F_25 ( V_49 [ V_62 ] , & V_52 ) ;
if ( V_57 )
return V_57 ;
if ( V_52 < V_13 )
F_5 ( V_13 , V_52 ) ;
if ( F_23 ( V_13 + V_64 == V_52 ) )
return - V_65 ;
} else {
F_32 ( V_13 , V_52 , V_27 . V_14 [ 0 ] ) ;
}
V_55 = V_54 ;
if ( V_49 [ V_63 ] ) {
V_57 = F_25 ( V_49 [ V_63 ] , & V_55 ) ;
if ( V_57 )
return V_57 ;
if ( V_55 < V_54 )
F_5 ( V_54 , V_55 ) ;
if ( F_23 ( V_54 + V_64 == V_55 ) )
return - V_65 ;
} else {
F_32 ( V_54 , V_55 , V_27 . V_14 [ 1 ] ) ;
}
if ( V_51 )
V_13 = F_33 ( V_38 -> V_25 . V_13 [ 0 ] ) ;
while ( V_13 <= V_52 ) {
V_27 . V_13 [ 0 ] = F_13 ( V_13 ) ;
V_53 = F_34 ( V_13 , V_52 , & V_27 . V_14 [ 0 ] ) ;
V_3 = ( V_51 &&
V_13 == F_33 ( V_38 -> V_25 . V_13 [ 0 ] ) ) ? F_33 ( V_38 -> V_25 . V_13 [ 1 ] )
: V_54 ;
while ( V_3 <= V_55 ) {
V_27 . V_13 [ 1 ] = F_13 ( V_3 ) ;
V_56 = F_34 ( V_3 , V_55 , & V_27 . V_14 [ 1 ] ) ;
V_57 = V_39 ( V_30 , & V_27 , & V_42 , & V_42 , V_10 ) ;
if ( V_57 && ! F_31 ( V_57 , V_10 ) )
return V_57 ;
V_57 = 0 ;
V_3 = V_56 + 1 ;
}
V_13 = V_53 + 1 ;
}
return V_57 ;
}
static inline bool
F_35 ( const struct V_66 * V_2 ,
const struct V_66 * V_3 ,
T_1 * V_4 )
{
return F_36 ( & V_2 -> V_13 [ 0 ] . V_67 , & V_3 -> V_13 [ 0 ] . V_67 ) &&
F_36 ( & V_2 -> V_13 [ 1 ] . V_67 , & V_3 -> V_13 [ 1 ] . V_67 ) &&
V_2 -> V_6 == V_3 -> V_6 ;
}
static inline int
F_37 ( const struct V_66 * V_7 )
{
return V_7 -> V_8 ? - V_9 : 1 ;
}
static inline void
F_38 ( struct V_66 * V_7 , T_1 V_10 )
{
V_7 -> V_8 = ( V_10 >> 16 ) & V_11 ;
}
static inline void
F_39 ( struct V_66 * V_7 , T_2 * V_10 )
{
F_5 ( * V_10 , V_7 -> V_8 ) ;
}
static inline void
F_40 ( struct V_66 * V_7 ,
struct V_66 * V_12 )
{
V_7 -> V_13 [ 1 ] = V_12 -> V_13 [ 1 ] ;
}
static inline void
F_41 ( struct V_66 * V_7 , T_2 V_14 , bool V_15 )
{
if ( V_15 ) {
F_42 ( & V_7 -> V_13 [ 1 ] , V_14 ) ;
V_7 -> V_14 [ 1 ] = V_14 ;
} else {
F_42 ( & V_7 -> V_13 [ 0 ] , V_14 ) ;
V_7 -> V_14 [ 0 ] = V_14 ;
}
}
static bool
F_43 ( struct V_16 * V_17 ,
const struct V_66 * V_18 )
{
T_1 V_10 = V_18 -> V_8 ? V_11 : 0 ;
if ( F_44 ( V_17 , V_19 , & V_18 -> V_13 [ 0 ] . V_67 ) ||
F_44 ( V_17 , V_20 , & V_18 -> V_13 [ 1 ] . V_67 ) ||
F_11 ( V_17 , V_21 , V_18 -> V_14 [ 0 ] ) ||
F_11 ( V_17 , V_22 , V_18 -> V_14 [ 1 ] ) ||
( V_10 &&
F_12 ( V_17 , V_23 , F_13 ( V_10 ) ) ) )
goto V_24;
return false ;
V_24:
return true ;
}
static inline void
F_45 ( struct V_66 * V_25 ,
const struct V_66 * V_26 )
{
}
static void
F_46 ( struct V_66 * V_27 )
{
V_27 -> V_14 [ 0 ] = V_28 ;
V_27 -> V_14 [ 1 ] = V_28 ;
}
static int
F_47 ( struct V_29 * V_30 , const struct V_16 * V_17 ,
const struct V_31 * V_32 ,
enum V_33 V_34 , struct V_35 * V_36 )
{
const struct V_68 * V_38 = V_30 -> V_18 ;
T_3 V_39 = V_30 -> V_40 -> V_34 [ V_34 ] ;
struct V_66 V_27 = { } ;
struct V_41 V_42 = F_17 ( V_17 , V_36 , V_30 ) ;
V_27 . V_14 [ 0 ] = F_18 ( V_38 -> V_43 [ 0 ] . V_14 [ 0 ] , V_28 ) ;
V_27 . V_14 [ 1 ] = F_18 ( V_38 -> V_43 [ 0 ] . V_14 [ 1 ] , V_28 ) ;
if ( V_34 == V_44 )
V_27 . V_6 = ( V_28 << ( sizeof( T_2 ) * 8 ) ) | V_28 ;
F_48 ( V_17 , V_36 -> V_10 & V_45 , & V_27 . V_13 [ 0 ] . V_67 ) ;
F_48 ( V_17 , V_36 -> V_10 & V_46 , & V_27 . V_13 [ 1 ] . V_67 ) ;
F_42 ( & V_27 . V_13 [ 0 ] , V_27 . V_14 [ 0 ] ) ;
F_42 ( & V_27 . V_13 [ 1 ] , V_27 . V_14 [ 1 ] ) ;
return V_39 ( V_30 , & V_27 , & V_42 , & V_36 -> V_42 , V_36 -> V_47 ) ;
}
static int
F_49 ( struct V_29 * V_30 , struct V_48 * V_49 [] ,
enum V_33 V_34 , T_1 * V_50 , T_1 V_10 , bool V_51 )
{
T_3 V_39 = V_30 -> V_40 -> V_34 [ V_34 ] ;
struct V_66 V_27 = { } ;
struct V_41 V_42 = F_21 ( V_30 ) ;
int V_57 ;
if ( V_49 [ V_58 ] )
* V_50 = F_22 ( V_49 [ V_58 ] ) ;
F_46 ( & V_27 ) ;
if ( F_23 ( ! V_49 [ V_19 ] || ! V_49 [ V_20 ] ||
! F_24 ( V_49 , V_23 ) ) )
return - V_59 ;
if ( F_23 ( V_49 [ V_62 ] || V_49 [ V_63 ] ) )
return - V_69 ;
V_57 = F_50 ( V_49 [ V_19 ] , & V_27 . V_13 [ 0 ] ) ;
if ( V_57 )
return V_57 ;
V_57 = F_50 ( V_49 [ V_20 ] , & V_27 . V_13 [ 1 ] ) ;
if ( V_57 )
return V_57 ;
V_57 = F_26 ( V_30 , V_49 , & V_42 ) ;
if ( V_57 )
return V_57 ;
if ( V_49 [ V_21 ] ) {
V_27 . V_14 [ 0 ] = F_27 ( V_49 [ V_21 ] ) ;
if ( ! V_27 . V_14 [ 0 ] || V_27 . V_14 [ 0 ] > V_28 )
return - V_60 ;
}
if ( V_49 [ V_22 ] ) {
V_27 . V_14 [ 1 ] = F_27 ( V_49 [ V_22 ] ) ;
if ( ! V_27 . V_14 [ 1 ] || V_27 . V_14 [ 1 ] > V_28 )
return - V_60 ;
}
F_42 ( & V_27 . V_13 [ 0 ] , V_27 . V_14 [ 0 ] ) ;
F_42 ( & V_27 . V_13 [ 1 ] , V_27 . V_14 [ 1 ] ) ;
if ( V_49 [ V_23 ] ) {
T_1 V_61 = F_28 ( V_49 [ V_23 ] ) ;
if ( V_61 & V_11 )
V_10 |= ( V_11 << 16 ) ;
}
V_57 = V_39 ( V_30 , & V_27 , & V_42 , & V_42 , V_10 ) ;
return F_30 ( V_57 , V_10 , V_34 , V_30 ) ? - V_57 :
F_31 ( V_57 , V_10 ) ? 0 : V_57 ;
}
static int T_4
F_51 ( void )
{
return F_52 ( & V_70 ) ;
}
static void T_5
F_53 ( void )
{
F_54 () ;
F_55 ( & V_70 ) ;
}
