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
return 0 ;
V_24:
return 1 ;
}
static inline void
F_14 ( struct V_1 * V_25 ,
const struct V_1 * V_26 )
{
V_25 -> V_5 = V_26 -> V_5 ;
}
static int
F_15 ( struct V_27 * V_28 , const struct V_16 * V_17 ,
const struct V_29 * V_30 ,
enum V_31 V_32 , struct V_33 * V_34 )
{
const struct V_35 * V_36 = V_28 -> V_18 ;
T_3 V_37 = V_28 -> V_38 -> V_32 [ V_32 ] ;
struct V_1 V_39 = { } ;
struct V_40 V_41 = F_16 ( V_17 , V_34 , V_28 ) ;
V_39 . V_14 [ 0 ] = F_17 ( V_36 -> V_42 [ 0 ] . V_14 [ 0 ] , V_43 ) ;
V_39 . V_14 [ 1 ] = F_17 ( V_36 -> V_42 [ 0 ] . V_14 [ 1 ] , V_43 ) ;
if ( V_32 == V_44 )
V_39 . V_6 = ( V_43 << ( sizeof( V_39 . V_14 [ 0 ] ) * 8 ) ) | V_43 ;
F_18 ( V_17 , V_34 -> V_10 & V_45 , & V_39 . V_13 [ 0 ] ) ;
F_18 ( V_17 , V_34 -> V_10 & V_46 , & V_39 . V_13 [ 1 ] ) ;
V_39 . V_13 [ 0 ] &= F_8 ( V_39 . V_14 [ 0 ] ) ;
V_39 . V_13 [ 1 ] &= F_8 ( V_39 . V_14 [ 1 ] ) ;
return V_37 ( V_28 , & V_39 , & V_41 , & V_34 -> V_41 , V_34 -> V_47 ) ;
}
static int
F_19 ( struct V_27 * V_28 , struct V_48 * V_49 [] ,
enum V_31 V_32 , T_1 * V_50 , T_1 V_10 , bool V_51 )
{
const struct V_35 * V_36 = V_28 -> V_18 ;
T_3 V_37 = V_28 -> V_38 -> V_32 [ V_32 ] ;
struct V_1 V_39 = { } ;
struct V_40 V_41 = F_20 ( V_28 ) ;
T_1 V_13 = 0 , V_52 = 0 , V_53 ;
T_1 V_3 = 0 , V_54 = 0 , V_55 = 0 , V_56 ;
T_2 V_14 , V_57 ;
int V_58 ;
V_39 . V_14 [ 0 ] = V_39 . V_14 [ 1 ] = V_43 ;
if ( F_21 ( ! V_49 [ V_19 ] || ! V_49 [ V_20 ] ||
! F_22 ( V_49 , V_59 ) ||
! F_22 ( V_49 , V_23 ) ||
! F_22 ( V_49 , V_60 ) ||
! F_22 ( V_49 , V_61 ) ) )
return - V_62 ;
if ( V_49 [ V_63 ] )
* V_50 = F_23 ( V_49 [ V_63 ] ) ;
V_58 = F_24 ( V_49 [ V_19 ] , & V_13 ) ||
F_24 ( V_49 [ V_20 ] , & V_54 ) ||
F_25 ( V_28 , V_49 , & V_41 ) ;
if ( V_58 )
return V_58 ;
if ( V_49 [ V_21 ] ) {
V_14 = F_26 ( V_49 [ V_21 ] ) ;
if ( ! V_14 || V_14 > V_43 )
return - V_64 ;
V_39 . V_14 [ 0 ] = V_14 ;
}
if ( V_49 [ V_22 ] ) {
V_57 = F_26 ( V_49 [ V_22 ] ) ;
if ( ! V_57 || V_57 > V_43 )
return - V_64 ;
V_39 . V_14 [ 1 ] = V_57 ;
}
if ( V_49 [ V_23 ] ) {
T_1 V_65 = F_27 ( V_49 [ V_23 ] ) ;
if ( V_65 & V_11 )
V_10 |= ( V_11 << 16 ) ;
}
if ( V_32 == V_44 || ! ( V_49 [ V_66 ] &&
V_49 [ V_67 ] ) ) {
V_39 . V_13 [ 0 ] = F_13 ( V_13 & F_28 ( V_39 . V_14 [ 0 ] ) ) ;
V_39 . V_13 [ 1 ] = F_13 ( V_54 & F_28 ( V_39 . V_14 [ 1 ] ) ) ;
V_58 = V_37 ( V_28 , & V_39 , & V_41 , & V_41 , V_10 ) ;
return F_29 ( V_58 , V_10 , V_32 , V_28 ) ? - V_58 :
F_30 ( V_58 , V_10 ) ? 0 : V_58 ;
}
V_52 = V_13 ;
if ( V_49 [ V_66 ] ) {
V_58 = F_24 ( V_49 [ V_66 ] , & V_52 ) ;
if ( V_58 )
return V_58 ;
if ( V_52 < V_13 )
F_5 ( V_13 , V_52 ) ;
if ( V_13 + V_68 == V_52 )
return - V_69 ;
}
V_55 = V_54 ;
if ( V_49 [ V_67 ] ) {
V_58 = F_24 ( V_49 [ V_67 ] , & V_55 ) ;
if ( V_58 )
return V_58 ;
if ( V_55 < V_54 )
F_5 ( V_54 , V_55 ) ;
if ( V_54 + V_68 == V_55 )
return - V_69 ;
}
if ( V_51 )
V_13 = F_31 ( V_36 -> V_25 . V_13 [ 0 ] ) ;
while ( ! F_32 ( V_13 , V_52 ) ) {
V_39 . V_13 [ 0 ] = F_13 ( V_13 ) ;
V_53 = F_33 ( V_13 , V_52 , & V_14 ) ;
V_39 . V_14 [ 0 ] = V_14 ;
V_3 = ( V_51 &&
V_13 == F_31 ( V_36 -> V_25 . V_13 [ 0 ] ) ) ? F_31 ( V_36 -> V_25 . V_13 [ 1 ] )
: V_54 ;
while ( ! F_32 ( V_3 , V_55 ) ) {
V_39 . V_13 [ 1 ] = F_13 ( V_3 ) ;
V_56 = F_33 ( V_3 , V_55 , & V_57 ) ;
V_39 . V_14 [ 1 ] = V_57 ;
V_58 = V_37 ( V_28 , & V_39 , & V_41 , & V_41 , V_10 ) ;
if ( V_58 && ! F_30 ( V_58 , V_10 ) )
return V_58 ;
else
V_58 = 0 ;
V_3 = V_56 + 1 ;
}
V_13 = V_53 + 1 ;
}
return V_58 ;
}
static inline bool
F_34 ( const struct V_70 * V_2 ,
const struct V_70 * V_3 ,
T_1 * V_4 )
{
return F_35 ( & V_2 -> V_13 [ 0 ] . V_71 , & V_3 -> V_13 [ 0 ] . V_71 ) &&
F_35 ( & V_2 -> V_13 [ 1 ] . V_71 , & V_3 -> V_13 [ 1 ] . V_71 ) &&
V_2 -> V_6 == V_3 -> V_6 ;
}
static inline int
F_36 ( const struct V_70 * V_7 )
{
return V_7 -> V_8 ? - V_9 : 1 ;
}
static inline void
F_37 ( struct V_70 * V_7 , T_1 V_10 )
{
V_7 -> V_8 = ( V_10 >> 16 ) & V_11 ;
}
static inline void
F_38 ( struct V_70 * V_7 , T_2 * V_10 )
{
F_5 ( * V_10 , V_7 -> V_8 ) ;
}
static inline void
F_39 ( struct V_70 * V_7 ,
struct V_70 * V_12 )
{
V_7 -> V_13 [ 1 ] = V_12 -> V_13 [ 1 ] ;
}
static inline void
F_40 ( struct V_70 * V_7 , T_2 V_14 , bool V_15 )
{
if ( V_15 ) {
F_41 ( & V_7 -> V_13 [ 1 ] , V_14 ) ;
V_7 -> V_14 [ 1 ] = V_14 ;
} else {
F_41 ( & V_7 -> V_13 [ 0 ] , V_14 ) ;
V_7 -> V_14 [ 0 ] = V_14 ;
}
}
static bool
F_42 ( struct V_16 * V_17 ,
const struct V_70 * V_18 )
{
T_1 V_10 = V_18 -> V_8 ? V_11 : 0 ;
if ( F_43 ( V_17 , V_19 , & V_18 -> V_13 [ 0 ] . V_71 ) ||
F_43 ( V_17 , V_20 , & V_18 -> V_13 [ 1 ] . V_71 ) ||
F_11 ( V_17 , V_21 , V_18 -> V_14 [ 0 ] ) ||
F_11 ( V_17 , V_22 , V_18 -> V_14 [ 1 ] ) ||
( V_10 &&
F_12 ( V_17 , V_23 , F_13 ( V_10 ) ) ) )
goto V_24;
return 0 ;
V_24:
return 1 ;
}
static inline void
F_44 ( struct V_1 * V_25 ,
const struct V_70 * V_26 )
{
}
static int
F_45 ( struct V_27 * V_28 , const struct V_16 * V_17 ,
const struct V_29 * V_30 ,
enum V_31 V_32 , struct V_33 * V_34 )
{
const struct V_35 * V_36 = V_28 -> V_18 ;
T_3 V_37 = V_28 -> V_38 -> V_32 [ V_32 ] ;
struct V_70 V_39 = { } ;
struct V_40 V_41 = F_16 ( V_17 , V_34 , V_28 ) ;
V_39 . V_14 [ 0 ] = F_17 ( V_36 -> V_42 [ 0 ] . V_14 [ 0 ] , V_43 ) ;
V_39 . V_14 [ 1 ] = F_17 ( V_36 -> V_42 [ 0 ] . V_14 [ 1 ] , V_43 ) ;
if ( V_32 == V_44 )
V_39 . V_6 = ( V_43 << ( sizeof( T_2 ) * 8 ) ) | V_43 ;
F_46 ( V_17 , V_34 -> V_10 & V_45 , & V_39 . V_13 [ 0 ] . V_71 ) ;
F_46 ( V_17 , V_34 -> V_10 & V_46 , & V_39 . V_13 [ 1 ] . V_71 ) ;
F_41 ( & V_39 . V_13 [ 0 ] , V_39 . V_14 [ 0 ] ) ;
F_41 ( & V_39 . V_13 [ 1 ] , V_39 . V_14 [ 1 ] ) ;
return V_37 ( V_28 , & V_39 , & V_41 , & V_34 -> V_41 , V_34 -> V_47 ) ;
}
static int
F_47 ( struct V_27 * V_28 , struct V_48 * V_49 [] ,
enum V_31 V_32 , T_1 * V_50 , T_1 V_10 , bool V_51 )
{
T_3 V_37 = V_28 -> V_38 -> V_32 [ V_32 ] ;
struct V_70 V_39 = { } ;
struct V_40 V_41 = F_20 ( V_28 ) ;
int V_58 ;
V_39 . V_14 [ 0 ] = V_39 . V_14 [ 1 ] = V_43 ;
if ( F_21 ( ! V_49 [ V_19 ] || ! V_49 [ V_20 ] ||
! F_22 ( V_49 , V_59 ) ||
! F_22 ( V_49 , V_23 ) ||
! F_22 ( V_49 , V_60 ) ||
! F_22 ( V_49 , V_61 ) ) )
return - V_62 ;
if ( F_21 ( V_49 [ V_66 ] || V_49 [ V_67 ] ) )
return - V_72 ;
if ( V_49 [ V_63 ] )
* V_50 = F_23 ( V_49 [ V_63 ] ) ;
V_58 = F_48 ( V_49 [ V_19 ] , & V_39 . V_13 [ 0 ] ) ||
F_48 ( V_49 [ V_20 ] , & V_39 . V_13 [ 1 ] ) ||
F_25 ( V_28 , V_49 , & V_41 ) ;
if ( V_58 )
return V_58 ;
if ( V_49 [ V_21 ] )
V_39 . V_14 [ 0 ] = F_26 ( V_49 [ V_21 ] ) ;
if ( V_49 [ V_22 ] )
V_39 . V_14 [ 1 ] = F_26 ( V_49 [ V_22 ] ) ;
if ( ! V_39 . V_14 [ 0 ] || V_39 . V_14 [ 0 ] > V_43 || ! V_39 . V_14 [ 1 ] ||
V_39 . V_14 [ 1 ] > V_43 )
return - V_64 ;
F_41 ( & V_39 . V_13 [ 0 ] , V_39 . V_14 [ 0 ] ) ;
F_41 ( & V_39 . V_13 [ 1 ] , V_39 . V_14 [ 1 ] ) ;
if ( V_49 [ V_23 ] ) {
T_1 V_65 = F_27 ( V_49 [ V_23 ] ) ;
if ( V_65 & V_11 )
V_10 |= ( V_11 << 16 ) ;
}
V_58 = V_37 ( V_28 , & V_39 , & V_41 , & V_41 , V_10 ) ;
return F_29 ( V_58 , V_10 , V_32 , V_28 ) ? - V_58 :
F_30 ( V_58 , V_10 ) ? 0 : V_58 ;
}
static int T_4
F_49 ( void )
{
return F_50 ( & V_73 ) ;
}
static void T_5
F_51 ( void )
{
F_52 ( & V_73 ) ;
}
