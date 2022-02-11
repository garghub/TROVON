static inline T_1
F_1 ( const struct V_1 * V_2 , T_1 V_3 )
{
return V_3 - V_2 -> V_4 ;
}
static inline struct V_5 *
F_2 ( void * V_6 , T_2 V_7 , T_3 V_8 )
{
return (struct V_5 * ) ( V_6 + V_7 * V_8 ) ;
}
static inline int
F_3 ( const struct V_9 * V_10 ,
const struct V_1 * V_11 , T_3 V_8 )
{
const struct V_5 * V_12 ;
if ( ! F_4 ( V_10 -> V_7 , V_11 -> V_13 ) )
return 0 ;
V_12 = F_2 ( V_11 -> V_6 , V_10 -> V_7 , V_8 ) ;
if ( V_12 -> V_14 == V_15 )
return ! V_10 -> V_16 ||
F_5 ( V_10 -> V_16 , V_12 -> V_16 ) ;
return - V_17 ;
}
static inline int
F_6 ( T_2 V_7 , const struct V_1 * V_11 , T_3 V_8 )
{
const struct V_5 * V_12 ;
if ( ! F_4 ( V_7 , V_11 -> V_13 ) )
return 0 ;
V_12 = F_2 ( V_11 -> V_6 , V_7 , V_8 ) ;
return V_12 -> V_14 == V_15 ;
}
static inline int
F_7 ( const struct V_5 * V_12 )
{
return V_12 -> V_14 == V_15 ;
}
static inline int
F_8 ( unsigned long * V_18 ,
const struct V_9 * V_10 ,
const struct V_19 * V_20 , struct V_21 * V_22 ,
struct V_1 * V_11 , int V_23 )
{
T_1 V_24 = V_20 -> V_18 ;
if ( V_23 == V_25 ) {
if ( V_24 == V_22 -> V_18 )
V_24 = * V_18 ;
F_9 ( V_18 , V_24 ) ;
} else {
if ( V_10 -> V_16 )
F_9 ( V_18 , V_24 ) ;
else
* V_18 = V_24 ;
}
return 0 ;
}
static inline int
F_10 ( const struct V_9 * V_10 ,
struct V_1 * V_11 , T_1 V_26 , T_3 V_8 )
{
struct V_5 * V_12 ;
V_12 = F_2 ( V_11 -> V_6 , V_10 -> V_7 , V_8 ) ;
if ( F_4 ( V_10 -> V_7 , V_11 -> V_13 ) ) {
if ( V_12 -> V_14 == V_15 ) {
if ( V_10 -> V_16 &&
( V_26 & V_27 ) &&
! F_5 ( V_10 -> V_16 , V_12 -> V_16 ) ) {
F_11 ( V_10 -> V_7 , V_11 -> V_13 ) ;
F_12 () ;
F_13 ( V_12 -> V_16 , V_10 -> V_16 ) ;
}
return V_28 ;
} else if ( ! V_10 -> V_16 )
return V_28 ;
F_11 ( V_10 -> V_7 , V_11 -> V_13 ) ;
F_12 () ;
F_13 ( V_12 -> V_16 , V_10 -> V_16 ) ;
V_12 -> V_14 = V_15 ;
return V_25 ;
} else if ( V_10 -> V_16 ) {
F_13 ( V_12 -> V_16 , V_10 -> V_16 ) ;
V_12 -> V_14 = V_15 ;
return 0 ;
}
V_12 -> V_14 = V_29 ;
return V_30 ;
}
static inline int
F_14 ( const struct V_9 * V_10 ,
struct V_1 * V_11 )
{
return ! F_15 ( V_10 -> V_7 , V_11 -> V_13 ) ;
}
static inline int
F_16 ( struct V_31 * V_32 , const struct V_1 * V_11 ,
T_1 V_7 , T_3 V_8 )
{
const struct V_5 * V_12 =
F_2 ( V_11 -> V_6 , V_7 , V_8 ) ;
return F_17 ( V_32 , V_33 ,
F_18 ( V_11 -> V_4 + V_7 ) ) ||
( V_12 -> V_14 == V_15 &&
F_19 ( V_32 , V_34 , V_35 , V_12 -> V_16 ) ) ;
}
static inline int
F_20 ( struct V_31 * V_32 , const struct V_1 * V_11 )
{
return F_17 ( V_32 , V_33 , F_18 ( V_11 -> V_4 ) ) ||
F_17 ( V_32 , V_36 , F_18 ( V_11 -> V_37 ) ) ;
}
static int
F_21 ( struct V_21 * V_22 , const struct V_31 * V_32 ,
const struct V_38 * V_39 ,
enum V_40 V_41 , struct V_42 * V_43 )
{
struct V_1 * V_11 = V_22 -> V_44 ;
T_4 V_45 = V_22 -> V_46 -> V_41 [ V_41 ] ;
struct V_9 V_10 = { . V_7 = 0 } ;
struct V_19 V_20 = F_22 ( V_32 , V_43 , V_22 ) ;
T_1 V_3 ;
if ( ! ( V_43 -> V_26 & V_47 ) )
return 0 ;
V_3 = F_23 ( F_24 ( V_32 , V_43 -> V_26 & V_48 ) ) ;
if ( V_3 < V_11 -> V_4 || V_3 > V_11 -> V_37 )
return - V_49 ;
if ( F_25 ( V_32 ) < V_32 -> V_50 ||
( F_25 ( V_32 ) + V_51 ) > V_32 -> V_44 )
return - V_52 ;
V_10 . V_7 = F_1 ( V_11 , V_3 ) ;
V_10 . V_16 = F_26 ( V_32 ) -> V_53 ;
return V_45 ( V_22 , & V_10 , & V_20 , & V_43 -> V_20 , V_43 -> V_54 ) ;
}
static int
F_27 ( struct V_21 * V_22 , struct V_55 * V_56 [] ,
enum V_40 V_41 , T_1 * V_57 , T_1 V_26 , bool V_58 )
{
const struct V_1 * V_11 = V_22 -> V_44 ;
T_4 V_45 = V_22 -> V_46 -> V_41 [ V_41 ] ;
struct V_9 V_10 = { . V_7 = 0 } ;
struct V_19 V_20 = F_28 ( V_22 ) ;
T_1 V_3 = 0 ;
int V_59 = 0 ;
if ( V_56 [ V_60 ] )
* V_57 = F_29 ( V_56 [ V_60 ] ) ;
if ( F_30 ( ! V_56 [ V_33 ] ) )
return - V_61 ;
V_59 = F_31 ( V_56 [ V_33 ] , & V_3 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_32 ( V_22 , V_56 , & V_20 ) ;
if ( V_59 )
return V_59 ;
if ( V_3 < V_11 -> V_4 || V_3 > V_11 -> V_37 )
return - V_49 ;
V_10 . V_7 = F_1 ( V_11 , V_3 ) ;
if ( V_56 [ V_34 ] )
V_10 . V_16 = F_33 ( V_56 [ V_34 ] ) ;
else
V_10 . V_16 = NULL ;
V_59 = V_45 ( V_22 , & V_10 , & V_20 , & V_20 , V_26 ) ;
return F_34 ( V_59 , V_26 ) ? 0 : V_59 ;
}
static bool
F_35 ( const struct V_21 * V_62 , const struct V_21 * V_63 )
{
const struct V_1 * V_64 = V_62 -> V_44 ;
const struct V_1 * V_65 = V_63 -> V_44 ;
return V_64 -> V_4 == V_65 -> V_4 &&
V_64 -> V_37 == V_65 -> V_37 &&
V_62 -> V_18 == V_63 -> V_18 &&
V_62 -> V_6 == V_63 -> V_6 ;
}
static bool
F_36 ( struct V_21 * V_22 , struct V_1 * V_11 ,
T_1 V_4 , T_1 V_37 , T_1 V_66 )
{
V_11 -> V_13 = F_37 ( V_11 -> V_67 ) ;
if ( ! V_11 -> V_13 )
return false ;
if ( V_22 -> V_8 ) {
V_11 -> V_6 = F_37 ( V_22 -> V_8 * V_66 ) ;
if ( ! V_11 -> V_6 ) {
F_38 ( V_11 -> V_13 ) ;
return false ;
}
}
V_11 -> V_4 = V_4 ;
V_11 -> V_37 = V_37 ;
V_11 -> V_66 = V_66 ;
V_22 -> V_18 = V_68 ;
V_22 -> V_44 = V_11 ;
V_22 -> V_69 = V_70 ;
return true ;
}
static int
F_39 ( struct V_71 * V_71 , struct V_21 * V_22 , struct V_55 * V_56 [] ,
T_1 V_26 )
{
T_1 V_4 = 0 , V_37 = 0 ;
T_5 V_66 ;
struct V_1 * V_11 ;
int V_59 ;
if ( F_30 ( ! V_56 [ V_33 ] ||
! F_40 ( V_56 , V_72 ) ||
! F_40 ( V_56 , V_73 ) ) )
return - V_61 ;
V_59 = F_31 ( V_56 [ V_33 ] , & V_4 ) ;
if ( V_59 )
return V_59 ;
if ( V_56 [ V_36 ] ) {
V_59 = F_31 ( V_56 [ V_36 ] , & V_37 ) ;
if ( V_59 )
return V_59 ;
if ( V_4 > V_37 ) {
T_1 V_74 = V_4 ;
V_4 = V_37 ;
V_37 = V_74 ;
}
} else if ( V_56 [ V_75 ] ) {
T_6 V_76 = F_41 ( V_56 [ V_75 ] ) ;
if ( V_76 >= V_77 )
return - V_78 ;
F_42 ( V_4 , V_37 , V_76 ) ;
} else {
return - V_61 ;
}
V_66 = ( T_5 ) V_37 - V_4 + 1 ;
if ( V_66 > V_79 + 1 )
return - V_80 ;
V_11 = F_43 ( sizeof( * V_11 ) , V_81 ) ;
if ( ! V_11 )
return - V_82 ;
V_11 -> V_67 = F_44 ( 0 , V_66 - 1 ) ;
V_22 -> V_46 = & V_1 ;
V_22 -> V_8 = F_45 ( V_22 , V_56 ,
sizeof( struct V_5 ) ) ;
if ( ! F_36 ( V_22 , V_11 , V_4 , V_37 , V_66 ) ) {
F_38 ( V_11 ) ;
return - V_82 ;
}
if ( V_56 [ V_72 ] ) {
V_22 -> V_18 = F_46 ( V_56 [ V_72 ] ) ;
F_47 ( V_22 , V_83 ) ;
}
return 0 ;
}
static int T_7
F_48 ( void )
{
return F_49 ( & V_84 ) ;
}
static void T_8
F_50 ( void )
{
F_51 () ;
F_52 ( & V_84 ) ;
}
