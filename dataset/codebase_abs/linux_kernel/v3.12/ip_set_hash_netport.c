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
F_6 ( struct V_1 * V_9 , T_2 V_8 )
{
V_9 -> V_5 &= F_7 ( V_8 ) ;
V_9 -> V_8 = V_8 - 1 ;
}
static bool
F_8 ( struct V_14 * V_15 ,
const struct V_1 * V_16 )
{
T_1 V_12 = V_16 -> V_10 ? V_13 : 0 ;
if ( F_9 ( V_15 , V_17 , V_16 -> V_5 ) ||
F_10 ( V_15 , V_18 , V_16 -> V_6 ) ||
F_11 ( V_15 , V_19 , V_16 -> V_8 + 1 ) ||
F_11 ( V_15 , V_20 , V_16 -> V_7 ) ||
( V_12 &&
F_12 ( V_15 , V_21 , F_13 ( V_12 ) ) ) )
goto V_22;
return 0 ;
V_22:
return 1 ;
}
static inline void
F_14 ( struct V_1 * V_23 ,
const struct V_1 * V_24 )
{
V_23 -> V_5 = V_24 -> V_5 ;
V_23 -> V_6 = V_24 -> V_6 ;
}
static int
F_15 ( struct V_25 * V_26 , const struct V_14 * V_15 ,
const struct V_27 * V_28 ,
enum V_29 V_30 , struct V_31 * V_32 )
{
const struct V_33 * V_34 = V_26 -> V_16 ;
T_3 V_35 = V_26 -> V_36 -> V_30 [ V_30 ] ;
struct V_1 V_37 = {
. V_8 = V_34 -> V_38 [ 0 ] . V_8 ? V_34 -> V_38 [ 0 ] . V_8 - 1 : V_39 - 1
} ;
struct V_40 V_41 = F_16 ( V_15 , V_32 , V_34 ) ;
if ( V_30 == V_42 )
V_37 . V_8 = V_39 - 1 ;
if ( ! F_17 ( V_15 , V_32 -> V_12 & V_43 ,
& V_37 . V_6 , & V_37 . V_7 ) )
return - V_44 ;
F_18 ( V_15 , V_32 -> V_12 & V_45 , & V_37 . V_5 ) ;
V_37 . V_5 &= F_7 ( V_37 . V_8 + 1 ) ;
return V_35 ( V_26 , & V_37 , & V_41 , & V_32 -> V_41 , V_32 -> V_46 ) ;
}
static int
F_19 ( struct V_25 * V_26 , struct V_47 * V_48 [] ,
enum V_29 V_30 , T_1 * V_49 , T_1 V_12 , bool V_50 )
{
const struct V_33 * V_34 = V_26 -> V_16 ;
T_3 V_35 = V_26 -> V_36 -> V_30 [ V_30 ] ;
struct V_1 V_37 = { . V_8 = V_39 - 1 } ;
struct V_40 V_41 = F_20 ( V_34 ) ;
T_1 V_6 , V_51 , V_52 = 0 , V_5 = 0 , V_53 , V_54 ;
bool V_55 = false ;
T_2 V_8 ;
int V_56 ;
if ( F_21 ( ! V_48 [ V_17 ] ||
! F_22 ( V_48 , V_18 ) ||
! F_23 ( V_48 , V_57 ) ||
! F_23 ( V_48 , V_58 ) ||
! F_23 ( V_48 , V_21 ) ||
! F_23 ( V_48 , V_59 ) ||
! F_23 ( V_48 , V_60 ) ) )
return - V_61 ;
if ( V_48 [ V_62 ] )
* V_49 = F_24 ( V_48 [ V_62 ] ) ;
V_56 = F_25 ( V_48 [ V_17 ] , & V_5 ) ||
F_26 ( V_26 , V_48 , & V_41 ) ;
if ( V_56 )
return V_56 ;
if ( V_48 [ V_19 ] ) {
V_8 = F_27 ( V_48 [ V_19 ] ) ;
if ( ! V_8 || V_8 > V_39 )
return - V_63 ;
V_37 . V_8 = V_8 - 1 ;
}
if ( V_48 [ V_18 ] )
V_37 . V_6 = F_28 ( V_48 [ V_18 ] ) ;
else
return - V_61 ;
if ( V_48 [ V_20 ] ) {
V_37 . V_7 = F_27 ( V_48 [ V_20 ] ) ;
V_55 = F_29 ( V_37 . V_7 ) ;
if ( V_37 . V_7 == 0 )
return - V_64 ;
} else
return - V_65 ;
if ( ! ( V_55 || V_37 . V_7 == V_66 ) )
V_37 . V_6 = 0 ;
V_55 = V_55 && V_48 [ V_57 ] ;
if ( V_48 [ V_21 ] ) {
T_1 V_67 = F_30 ( V_48 [ V_21 ] ) ;
if ( V_67 & V_13 )
V_12 |= ( V_13 << 16 ) ;
}
if ( V_30 == V_42 || ! ( V_55 || V_48 [ V_68 ] ) ) {
V_37 . V_5 = F_13 ( V_5 & F_31 ( V_37 . V_8 + 1 ) ) ;
V_56 = V_35 ( V_26 , & V_37 , & V_41 , & V_41 , V_12 ) ;
return F_32 ( V_56 , V_12 , V_30 , V_26 ) ? - V_56 :
F_33 ( V_56 , V_12 ) ? 0 : V_56 ;
}
V_6 = V_51 = F_34 ( V_37 . V_6 ) ;
if ( V_48 [ V_57 ] ) {
V_51 = F_35 ( V_48 [ V_57 ] ) ;
if ( V_51 < V_6 )
F_5 ( V_6 , V_51 ) ;
}
if ( V_48 [ V_68 ] ) {
V_56 = F_25 ( V_48 [ V_68 ] , & V_53 ) ;
if ( V_56 )
return V_56 ;
if ( V_53 < V_5 )
F_5 ( V_5 , V_53 ) ;
if ( V_5 + V_69 == V_53 )
return - V_70 ;
} else
F_36 ( V_5 , V_53 , V_37 . V_8 + 1 ) ;
if ( V_50 )
V_5 = F_37 ( V_34 -> V_23 . V_5 ) ;
while ( ! F_38 ( V_5 , V_53 ) ) {
V_37 . V_5 = F_13 ( V_5 ) ;
V_54 = F_39 ( V_5 , V_53 , & V_8 ) ;
V_37 . V_8 = V_8 - 1 ;
V_52 = V_50 && V_5 == F_37 ( V_34 -> V_23 . V_5 ) ? F_34 ( V_34 -> V_23 . V_6 )
: V_6 ;
for (; V_52 <= V_51 ; V_52 ++ ) {
V_37 . V_6 = F_40 ( V_52 ) ;
V_56 = V_35 ( V_26 , & V_37 , & V_41 , & V_41 , V_12 ) ;
if ( V_56 && ! F_33 ( V_56 , V_12 ) )
return V_56 ;
else
V_56 = 0 ;
}
V_5 = V_54 + 1 ;
}
return V_56 ;
}
static inline bool
F_41 ( const struct V_71 * V_2 ,
const struct V_71 * V_3 ,
T_1 * V_4 )
{
return F_42 ( & V_2 -> V_5 . V_72 , & V_3 -> V_5 . V_72 ) &&
V_2 -> V_6 == V_3 -> V_6 &&
V_2 -> V_7 == V_3 -> V_7 &&
V_2 -> V_8 == V_3 -> V_8 ;
}
static inline int
F_43 ( const struct V_71 * V_9 )
{
return V_9 -> V_10 ? - V_11 : 1 ;
}
static inline void
F_44 ( struct V_71 * V_9 , T_1 V_12 )
{
V_9 -> V_10 = ! ! ( ( V_12 >> 16 ) & V_13 ) ;
}
static inline void
F_45 ( struct V_71 * V_9 , T_2 * V_12 )
{
F_5 ( * V_12 , V_9 -> V_10 ) ;
}
static inline void
F_46 ( struct V_71 * V_9 , T_2 V_8 )
{
F_47 ( & V_9 -> V_5 , V_8 ) ;
V_9 -> V_8 = V_8 - 1 ;
}
static bool
F_48 ( struct V_14 * V_15 ,
const struct V_71 * V_16 )
{
T_1 V_12 = V_16 -> V_10 ? V_13 : 0 ;
if ( F_49 ( V_15 , V_17 , & V_16 -> V_5 . V_72 ) ||
F_10 ( V_15 , V_18 , V_16 -> V_6 ) ||
F_11 ( V_15 , V_19 , V_16 -> V_8 + 1 ) ||
F_11 ( V_15 , V_20 , V_16 -> V_7 ) ||
( V_12 &&
F_12 ( V_15 , V_21 , F_13 ( V_12 ) ) ) )
goto V_22;
return 0 ;
V_22:
return 1 ;
}
static inline void
F_50 ( struct V_1 * V_23 ,
const struct V_71 * V_24 )
{
V_23 -> V_6 = V_24 -> V_6 ;
}
static int
F_51 ( struct V_25 * V_26 , const struct V_14 * V_15 ,
const struct V_27 * V_28 ,
enum V_29 V_30 , struct V_31 * V_32 )
{
const struct V_33 * V_34 = V_26 -> V_16 ;
T_3 V_35 = V_26 -> V_36 -> V_30 [ V_30 ] ;
struct V_71 V_37 = {
. V_8 = V_34 -> V_38 [ 0 ] . V_8 ? V_34 -> V_38 [ 0 ] . V_8 - 1 : V_39 - 1 ,
} ;
struct V_40 V_41 = F_16 ( V_15 , V_32 , V_34 ) ;
if ( V_30 == V_42 )
V_37 . V_8 = V_39 - 1 ;
if ( ! F_52 ( V_15 , V_32 -> V_12 & V_43 ,
& V_37 . V_6 , & V_37 . V_7 ) )
return - V_44 ;
F_53 ( V_15 , V_32 -> V_12 & V_45 , & V_37 . V_5 . V_72 ) ;
F_47 ( & V_37 . V_5 , V_37 . V_8 + 1 ) ;
return V_35 ( V_26 , & V_37 , & V_41 , & V_32 -> V_41 , V_32 -> V_46 ) ;
}
static int
F_54 ( struct V_25 * V_26 , struct V_47 * V_48 [] ,
enum V_29 V_30 , T_1 * V_49 , T_1 V_12 , bool V_50 )
{
const struct V_33 * V_34 = V_26 -> V_16 ;
T_3 V_35 = V_26 -> V_36 -> V_30 [ V_30 ] ;
struct V_71 V_37 = { . V_8 = V_39 - 1 } ;
struct V_40 V_41 = F_20 ( V_34 ) ;
T_1 V_6 , V_51 ;
bool V_55 = false ;
T_2 V_8 ;
int V_56 ;
if ( F_21 ( ! V_48 [ V_17 ] ||
! F_22 ( V_48 , V_18 ) ||
! F_23 ( V_48 , V_57 ) ||
! F_23 ( V_48 , V_58 ) ||
! F_23 ( V_48 , V_21 ) ||
! F_23 ( V_48 , V_59 ) ||
! F_23 ( V_48 , V_60 ) ) )
return - V_61 ;
if ( F_21 ( V_48 [ V_68 ] ) )
return - V_73 ;
if ( V_48 [ V_62 ] )
* V_49 = F_24 ( V_48 [ V_62 ] ) ;
V_56 = F_55 ( V_48 [ V_17 ] , & V_37 . V_5 ) ||
F_26 ( V_26 , V_48 , & V_41 ) ;
if ( V_56 )
return V_56 ;
if ( V_48 [ V_19 ] ) {
V_8 = F_27 ( V_48 [ V_19 ] ) ;
if ( ! V_8 || V_8 > V_39 )
return - V_63 ;
V_37 . V_8 = V_8 - 1 ;
}
F_47 ( & V_37 . V_5 , V_37 . V_8 + 1 ) ;
if ( V_48 [ V_18 ] )
V_37 . V_6 = F_28 ( V_48 [ V_18 ] ) ;
else
return - V_61 ;
if ( V_48 [ V_20 ] ) {
V_37 . V_7 = F_27 ( V_48 [ V_20 ] ) ;
V_55 = F_29 ( V_37 . V_7 ) ;
if ( V_37 . V_7 == 0 )
return - V_64 ;
} else
return - V_65 ;
if ( ! ( V_55 || V_37 . V_7 == V_74 ) )
V_37 . V_6 = 0 ;
if ( V_48 [ V_21 ] ) {
T_1 V_67 = F_30 ( V_48 [ V_21 ] ) ;
if ( V_67 & V_13 )
V_12 |= ( V_13 << 16 ) ;
}
if ( V_30 == V_42 || ! V_55 || ! V_48 [ V_57 ] ) {
V_56 = V_35 ( V_26 , & V_37 , & V_41 , & V_41 , V_12 ) ;
return F_32 ( V_56 , V_12 , V_30 , V_26 ) ? - V_56 :
F_33 ( V_56 , V_12 ) ? 0 : V_56 ;
}
V_6 = F_34 ( V_37 . V_6 ) ;
V_51 = F_35 ( V_48 [ V_57 ] ) ;
if ( V_6 > V_51 )
F_5 ( V_6 , V_51 ) ;
if ( V_50 )
V_6 = F_34 ( V_34 -> V_23 . V_6 ) ;
for (; V_6 <= V_51 ; V_6 ++ ) {
V_37 . V_6 = F_40 ( V_6 ) ;
V_56 = V_35 ( V_26 , & V_37 , & V_41 , & V_41 , V_12 ) ;
if ( V_56 && ! F_33 ( V_56 , V_12 ) )
return V_56 ;
else
V_56 = 0 ;
}
return V_56 ;
}
static int T_4
F_56 ( void )
{
return F_57 ( & V_75 ) ;
}
static void T_5
F_58 ( void )
{
F_59 ( & V_75 ) ;
}
