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
return V_10 -> V_16 == NULL ||
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
if ( F_11 ( V_10 -> V_7 , V_11 -> V_13 ) ) {
if ( V_12 -> V_14 == V_15 ) {
if ( V_10 -> V_16 && ( V_26 & V_27 ) )
memcpy ( V_12 -> V_16 , V_10 -> V_16 , V_28 ) ;
return V_29 ;
} else if ( ! V_10 -> V_16 )
return V_29 ;
memcpy ( V_12 -> V_16 , V_10 -> V_16 , V_28 ) ;
V_12 -> V_14 = V_15 ;
return V_25 ;
} else if ( V_10 -> V_16 ) {
memcpy ( V_12 -> V_16 , V_10 -> V_16 , V_28 ) ;
V_12 -> V_14 = V_15 ;
return 0 ;
} else {
V_12 -> V_14 = V_30 ;
return V_31 ;
}
}
static inline int
F_12 ( const struct V_9 * V_10 ,
struct V_1 * V_11 )
{
return ! F_13 ( V_10 -> V_7 , V_11 -> V_13 ) ;
}
static inline int
F_14 ( struct V_32 * V_33 , const struct V_1 * V_11 ,
T_1 V_7 , T_3 V_8 )
{
const struct V_5 * V_12 =
F_2 ( V_11 -> V_6 , V_7 , V_8 ) ;
return F_15 ( V_33 , V_34 ,
F_16 ( V_11 -> V_4 + V_7 ) ) ||
( V_12 -> V_14 == V_15 &&
F_17 ( V_33 , V_35 , V_28 , V_12 -> V_16 ) ) ;
}
static inline int
F_18 ( struct V_32 * V_33 , const struct V_1 * V_11 )
{
return F_15 ( V_33 , V_34 , F_16 ( V_11 -> V_4 ) ) ||
F_15 ( V_33 , V_36 , F_16 ( V_11 -> V_37 ) ) ;
}
static int
F_19 ( struct V_21 * V_22 , const struct V_32 * V_33 ,
const struct V_38 * V_39 ,
enum V_40 V_41 , struct V_42 * V_43 )
{
struct V_1 * V_11 = V_22 -> V_44 ;
T_4 V_45 = V_22 -> V_46 -> V_41 [ V_41 ] ;
struct V_9 V_10 = {} ;
struct V_19 V_20 = F_20 ( V_33 , V_43 , V_22 ) ;
T_1 V_3 ;
if ( ! ( V_43 -> V_26 & V_47 ) )
return 0 ;
V_3 = F_21 ( F_22 ( V_33 , V_43 -> V_26 & V_48 ) ) ;
if ( V_3 < V_11 -> V_4 || V_3 > V_11 -> V_37 )
return - V_49 ;
if ( F_23 ( V_33 ) < V_33 -> V_50 ||
( F_23 ( V_33 ) + V_51 ) > V_33 -> V_44 )
return - V_52 ;
V_10 . V_7 = F_1 ( V_11 , V_3 ) ;
V_10 . V_16 = F_24 ( V_33 ) -> V_53 ;
return V_45 ( V_22 , & V_10 , & V_20 , & V_43 -> V_20 , V_43 -> V_54 ) ;
}
static int
F_25 ( struct V_21 * V_22 , struct V_55 * V_56 [] ,
enum V_40 V_41 , T_1 * V_57 , T_1 V_26 , bool V_58 )
{
const struct V_1 * V_11 = V_22 -> V_44 ;
T_4 V_45 = V_22 -> V_46 -> V_41 [ V_41 ] ;
struct V_9 V_10 = {} ;
struct V_19 V_20 = F_26 ( V_22 ) ;
T_1 V_3 = 0 ;
int V_59 = 0 ;
if ( F_27 ( ! V_56 [ V_34 ] ||
! F_28 ( V_56 , V_60 ) ||
! F_28 ( V_56 , V_61 ) ||
! F_28 ( V_56 , V_62 ) ) )
return - V_63 ;
if ( V_56 [ V_64 ] )
* V_57 = F_29 ( V_56 [ V_64 ] ) ;
V_59 = F_30 ( V_56 [ V_34 ] , & V_3 ) ||
F_31 ( V_22 , V_56 , & V_20 ) ;
if ( V_59 )
return V_59 ;
if ( V_3 < V_11 -> V_4 || V_3 > V_11 -> V_37 )
return - V_49 ;
V_10 . V_7 = F_1 ( V_11 , V_3 ) ;
if ( V_56 [ V_35 ] )
V_10 . V_16 = F_32 ( V_56 [ V_35 ] ) ;
else
V_10 . V_16 = NULL ;
V_59 = V_45 ( V_22 , & V_10 , & V_20 , & V_20 , V_26 ) ;
return F_33 ( V_59 , V_26 ) ? 0 : V_59 ;
}
static bool
F_34 ( const struct V_21 * V_65 , const struct V_21 * V_66 )
{
const struct V_1 * V_67 = V_65 -> V_44 ;
const struct V_1 * V_68 = V_66 -> V_44 ;
return V_67 -> V_4 == V_68 -> V_4 &&
V_67 -> V_37 == V_68 -> V_37 &&
V_65 -> V_18 == V_66 -> V_18 &&
V_65 -> V_6 == V_66 -> V_6 ;
}
static bool
F_35 ( struct V_21 * V_22 , struct V_1 * V_11 ,
T_1 V_4 , T_1 V_37 , T_1 V_69 )
{
V_11 -> V_13 = F_36 ( V_11 -> V_70 ) ;
if ( ! V_11 -> V_13 )
return false ;
if ( V_22 -> V_8 ) {
V_11 -> V_6 = F_36 ( V_22 -> V_8 * V_69 ) ;
if ( ! V_11 -> V_6 ) {
F_37 ( V_11 -> V_13 ) ;
return false ;
}
}
V_11 -> V_4 = V_4 ;
V_11 -> V_37 = V_37 ;
V_11 -> V_69 = V_69 ;
V_22 -> V_18 = V_71 ;
V_22 -> V_44 = V_11 ;
V_22 -> V_72 = V_73 ;
return true ;
}
static int
F_38 ( struct V_74 * V_74 , struct V_21 * V_22 , struct V_55 * V_56 [] ,
T_1 V_26 )
{
T_1 V_4 = 0 , V_37 = 0 ;
T_5 V_69 ;
struct V_1 * V_11 ;
int V_59 ;
if ( F_27 ( ! V_56 [ V_34 ] ||
! F_28 ( V_56 , V_60 ) ||
! F_28 ( V_56 , V_75 ) ) )
return - V_63 ;
V_59 = F_30 ( V_56 [ V_34 ] , & V_4 ) ;
if ( V_59 )
return V_59 ;
if ( V_56 [ V_36 ] ) {
V_59 = F_30 ( V_56 [ V_36 ] , & V_37 ) ;
if ( V_59 )
return V_59 ;
if ( V_4 > V_37 ) {
T_1 V_76 = V_4 ;
V_4 = V_37 ;
V_37 = V_76 ;
}
} else if ( V_56 [ V_77 ] ) {
T_6 V_78 = F_39 ( V_56 [ V_77 ] ) ;
if ( V_78 >= 32 )
return - V_79 ;
F_40 ( V_4 , V_37 , V_78 ) ;
} else
return - V_63 ;
V_69 = ( T_5 ) V_37 - V_4 + 1 ;
if ( V_69 > V_80 + 1 )
return - V_81 ;
V_11 = F_41 ( sizeof( * V_11 ) , V_82 ) ;
if ( ! V_11 )
return - V_83 ;
V_11 -> V_70 = F_42 ( 0 , V_69 - 1 ) ;
V_22 -> V_46 = & V_1 ;
V_22 -> V_8 = F_43 ( V_22 , V_56 ,
sizeof( struct V_5 ) ) ;
if ( ! F_35 ( V_22 , V_11 , V_4 , V_37 , V_69 ) ) {
F_37 ( V_11 ) ;
return - V_83 ;
}
if ( V_56 [ V_60 ] ) {
V_22 -> V_18 = F_44 ( V_56 [ V_60 ] ) ;
F_45 ( V_22 , V_84 ) ;
}
return 0 ;
}
static int T_7
F_46 ( void )
{
return F_47 ( & V_85 ) ;
}
static void T_8
F_48 ( void )
{
F_49 ( & V_85 ) ;
}
