static inline bool
F_1 ( const struct V_1 * V_2 ,
const struct V_1 * V_3 ,
T_1 * V_4 )
{
return V_2 -> V_5 == V_3 -> V_5 &&
V_2 -> V_6 == V_3 -> V_6 &&
( ++ * V_4 ) &&
V_2 -> V_7 == V_3 -> V_7 &&
strcmp ( V_2 -> V_8 , V_3 -> V_8 ) == 0 ;
}
static inline int
F_2 ( const struct V_1 * V_9 )
{
return V_9 -> V_10 ? - V_11 : 1 ;
}
static inline void
F_3 ( struct V_1 * V_9 , T_1 V_12 )
{
V_9 -> V_10 = ( V_12 >> 16 ) & V_13 ;
}
static inline void
F_4 ( struct V_1 * V_9 , T_2 * V_12 )
{
F_5 ( * V_12 , V_9 -> V_10 ) ;
}
static inline void
F_6 ( struct V_1 * V_9 , T_2 V_6 )
{
V_9 -> V_5 &= F_7 ( V_6 ) ;
V_9 -> V_6 = V_6 ;
}
static bool
F_8 ( struct V_14 * V_15 ,
const struct V_1 * V_16 )
{
T_1 V_12 = V_16 -> V_7 ? V_17 : 0 ;
if ( V_16 -> V_10 )
V_12 |= V_13 ;
if ( F_9 ( V_15 , V_18 , V_16 -> V_5 ) ||
F_10 ( V_15 , V_19 , V_16 -> V_6 ) ||
F_11 ( V_15 , V_20 , V_16 -> V_8 ) ||
( V_12 &&
F_12 ( V_15 , V_21 , F_13 ( V_12 ) ) ) )
goto V_22;
return false ;
V_22:
return true ;
}
static inline void
F_14 ( struct V_1 * V_23 ,
const struct V_1 * V_24 )
{
V_23 -> V_5 = V_24 -> V_5 ;
}
static const char * F_15 ( const struct V_14 * V_15 )
{
struct V_25 * V_26 = F_16 ( V_15 ) ;
return V_26 ? V_26 -> V_27 : NULL ;
}
static const char * F_17 ( const struct V_14 * V_15 )
{
struct V_25 * V_26 = F_18 ( V_15 ) ;
return V_26 ? V_26 -> V_27 : NULL ;
}
static int
F_19 ( struct V_28 * V_29 , const struct V_14 * V_15 ,
const struct V_30 * V_31 ,
enum V_32 V_33 , struct V_34 * V_35 )
{
struct V_36 * V_37 = V_29 -> V_16 ;
T_3 V_38 = V_29 -> V_39 -> V_33 [ V_33 ] ;
struct V_1 V_40 = {
. V_6 = F_20 ( V_37 -> V_41 [ 0 ] . V_6 [ 0 ] , V_42 ) ,
. V_9 = 1 ,
} ;
struct V_43 V_44 = F_21 ( V_15 , V_35 , V_29 ) ;
if ( V_33 == V_45 )
V_40 . V_6 = V_42 ;
F_22 ( V_15 , V_35 -> V_12 & V_46 , & V_40 . V_5 ) ;
V_40 . V_5 &= F_7 ( V_40 . V_6 ) ;
#define F_23 ( T_4 ) (par->state->dir ? par->state->dir->name : "")
#define F_24 (opt->flags & IPSET_DIM_TWO_SRC)
if ( V_35 -> V_47 & V_17 ) {
#if F_25 ( V_48 )
const char * V_49 = F_24 ? F_15 ( V_15 ) :
F_17 ( V_15 ) ;
if ( ! V_49 )
return - V_50 ;
F_26 ( V_40 . V_8 , V_49 ) ;
V_40 . V_7 = 1 ;
#endif
} else {
F_26 ( V_40 . V_8 , F_24 ? F_23 ( V_51 ) : F_23 ( V_52 ) ) ;
}
if ( strlen ( V_40 . V_8 ) == 0 )
return - V_50 ;
return V_38 ( V_29 , & V_40 , & V_44 , & V_35 -> V_44 , V_35 -> V_47 ) ;
}
static int
F_27 ( struct V_28 * V_29 , struct V_53 * V_54 [] ,
enum V_32 V_33 , T_1 * V_55 , T_1 V_12 , bool V_56 )
{
struct V_36 * V_37 = V_29 -> V_16 ;
T_3 V_38 = V_29 -> V_39 -> V_33 [ V_33 ] ;
struct V_1 V_40 = { . V_6 = V_42 , . V_9 = 1 } ;
struct V_43 V_44 = F_28 ( V_29 ) ;
T_1 V_5 = 0 , V_57 = 0 , V_58 ;
int V_59 ;
if ( V_54 [ V_60 ] )
* V_55 = F_29 ( V_54 [ V_60 ] ) ;
if ( F_30 ( ! V_54 [ V_18 ] ||
! V_54 [ V_20 ] ||
! F_31 ( V_54 , V_21 ) ) )
return - V_61 ;
V_59 = F_32 ( V_54 [ V_18 ] , & V_5 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_33 ( V_29 , V_54 , & V_44 ) ;
if ( V_59 )
return V_59 ;
if ( V_54 [ V_19 ] ) {
V_40 . V_6 = F_34 ( V_54 [ V_19 ] ) ;
if ( V_40 . V_6 > V_42 )
return - V_62 ;
}
F_35 ( V_40 . V_8 , V_54 [ V_20 ] , V_63 ) ;
if ( V_54 [ V_21 ] ) {
T_1 V_64 = F_36 ( V_54 [ V_21 ] ) ;
if ( V_64 & V_17 )
V_40 . V_7 = 1 ;
if ( V_64 & V_13 )
V_12 |= ( V_13 << 16 ) ;
}
if ( V_33 == V_45 || ! V_54 [ V_65 ] ) {
V_40 . V_5 = F_13 ( V_5 & F_37 ( V_40 . V_6 ) ) ;
V_59 = V_38 ( V_29 , & V_40 , & V_44 , & V_44 , V_12 ) ;
return F_38 ( V_59 , V_12 , V_33 , V_29 ) ? - V_59 :
F_39 ( V_59 , V_12 ) ? 0 : V_59 ;
}
if ( V_54 [ V_65 ] ) {
V_59 = F_32 ( V_54 [ V_65 ] , & V_57 ) ;
if ( V_59 )
return V_59 ;
if ( V_57 < V_5 )
F_5 ( V_5 , V_57 ) ;
if ( V_5 + V_66 == V_57 )
return - V_67 ;
} else {
F_40 ( V_5 , V_57 , V_40 . V_6 ) ;
}
if ( V_56 )
V_5 = F_41 ( V_37 -> V_23 . V_5 ) ;
while ( V_5 <= V_57 ) {
V_40 . V_5 = F_13 ( V_5 ) ;
V_58 = F_42 ( V_5 , V_57 , & V_40 . V_6 ) ;
V_59 = V_38 ( V_29 , & V_40 , & V_44 , & V_44 , V_12 ) ;
if ( V_59 && ! F_39 ( V_59 , V_12 ) )
return V_59 ;
V_59 = 0 ;
V_5 = V_58 + 1 ;
}
return V_59 ;
}
static inline bool
F_43 ( const struct V_68 * V_2 ,
const struct V_68 * V_3 ,
T_1 * V_4 )
{
return F_44 ( & V_2 -> V_5 . V_69 , & V_3 -> V_5 . V_69 ) &&
V_2 -> V_6 == V_3 -> V_6 &&
( ++ * V_4 ) &&
V_2 -> V_7 == V_3 -> V_7 &&
strcmp ( V_2 -> V_8 , V_3 -> V_8 ) == 0 ;
}
static inline int
F_45 ( const struct V_68 * V_9 )
{
return V_9 -> V_10 ? - V_11 : 1 ;
}
static inline void
F_46 ( struct V_68 * V_9 , T_1 V_12 )
{
V_9 -> V_10 = ( V_12 >> 16 ) & V_13 ;
}
static inline void
F_47 ( struct V_68 * V_9 , T_2 * V_12 )
{
F_5 ( * V_12 , V_9 -> V_10 ) ;
}
static inline void
F_48 ( struct V_68 * V_9 , T_2 V_6 )
{
F_49 ( & V_9 -> V_5 , V_6 ) ;
V_9 -> V_6 = V_6 ;
}
static bool
F_50 ( struct V_14 * V_15 ,
const struct V_68 * V_16 )
{
T_1 V_12 = V_16 -> V_7 ? V_17 : 0 ;
if ( V_16 -> V_10 )
V_12 |= V_13 ;
if ( F_51 ( V_15 , V_18 , & V_16 -> V_5 . V_69 ) ||
F_10 ( V_15 , V_19 , V_16 -> V_6 ) ||
F_11 ( V_15 , V_20 , V_16 -> V_8 ) ||
( V_12 &&
F_12 ( V_15 , V_21 , F_13 ( V_12 ) ) ) )
goto V_22;
return false ;
V_22:
return true ;
}
static inline void
F_52 ( struct V_68 * V_23 ,
const struct V_68 * V_24 )
{
}
static int
F_53 ( struct V_28 * V_29 , const struct V_14 * V_15 ,
const struct V_30 * V_31 ,
enum V_32 V_33 , struct V_34 * V_35 )
{
struct V_70 * V_37 = V_29 -> V_16 ;
T_3 V_38 = V_29 -> V_39 -> V_33 [ V_33 ] ;
struct V_68 V_40 = {
. V_6 = F_20 ( V_37 -> V_41 [ 0 ] . V_6 [ 0 ] , V_42 ) ,
. V_9 = 1 ,
} ;
struct V_43 V_44 = F_21 ( V_15 , V_35 , V_29 ) ;
if ( V_33 == V_45 )
V_40 . V_6 = V_42 ;
F_54 ( V_15 , V_35 -> V_12 & V_46 , & V_40 . V_5 . V_69 ) ;
F_49 ( & V_40 . V_5 , V_40 . V_6 ) ;
if ( V_35 -> V_47 & V_17 ) {
#if F_25 ( V_48 )
const char * V_49 = F_24 ? F_15 ( V_15 ) :
F_17 ( V_15 ) ;
if ( ! V_49 )
return - V_50 ;
F_26 ( V_40 . V_8 , V_49 ) ;
V_40 . V_7 = 1 ;
#endif
} else {
F_26 ( V_40 . V_8 , F_24 ? F_23 ( V_51 ) : F_23 ( V_52 ) ) ;
}
if ( strlen ( V_40 . V_8 ) == 0 )
return - V_50 ;
return V_38 ( V_29 , & V_40 , & V_44 , & V_35 -> V_44 , V_35 -> V_47 ) ;
}
static int
F_55 ( struct V_28 * V_29 , struct V_53 * V_54 [] ,
enum V_32 V_33 , T_1 * V_55 , T_1 V_12 , bool V_56 )
{
T_3 V_38 = V_29 -> V_39 -> V_33 [ V_33 ] ;
struct V_68 V_40 = { . V_6 = V_42 , . V_9 = 1 } ;
struct V_43 V_44 = F_28 ( V_29 ) ;
int V_59 ;
if ( V_54 [ V_60 ] )
* V_55 = F_29 ( V_54 [ V_60 ] ) ;
if ( F_30 ( ! V_54 [ V_18 ] ||
! V_54 [ V_20 ] ||
! F_31 ( V_54 , V_21 ) ) )
return - V_61 ;
if ( F_30 ( V_54 [ V_65 ] ) )
return - V_71 ;
V_59 = F_56 ( V_54 [ V_18 ] , & V_40 . V_5 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_33 ( V_29 , V_54 , & V_44 ) ;
if ( V_59 )
return V_59 ;
if ( V_54 [ V_19 ] ) {
V_40 . V_6 = F_34 ( V_54 [ V_19 ] ) ;
if ( V_40 . V_6 > V_42 )
return - V_62 ;
}
F_49 ( & V_40 . V_5 , V_40 . V_6 ) ;
F_35 ( V_40 . V_8 , V_54 [ V_20 ] , V_63 ) ;
if ( V_54 [ V_21 ] ) {
T_1 V_64 = F_36 ( V_54 [ V_21 ] ) ;
if ( V_64 & V_17 )
V_40 . V_7 = 1 ;
if ( V_64 & V_13 )
V_12 |= ( V_13 << 16 ) ;
}
V_59 = V_38 ( V_29 , & V_40 , & V_44 , & V_44 , V_12 ) ;
return F_38 ( V_59 , V_12 , V_33 , V_29 ) ? - V_59 :
F_39 ( V_59 , V_12 ) ? 0 : V_59 ;
}
static int T_5
F_57 ( void )
{
return F_58 ( & V_72 ) ;
}
static void T_6
F_59 ( void )
{
F_60 () ;
F_61 ( & V_72 ) ;
}
