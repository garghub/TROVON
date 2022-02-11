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
const struct V_1 * V_11 )
{
const struct V_5 * V_12 ;
if ( ! F_4 ( V_10 -> V_7 , V_11 -> V_13 ) )
return 0 ;
V_12 = F_2 ( V_11 -> V_6 , V_10 -> V_7 , V_11 -> V_8 ) ;
if ( V_12 -> V_14 == V_15 )
return V_10 -> V_16 == NULL ||
F_5 ( V_10 -> V_16 , V_12 -> V_16 ) ;
return - V_17 ;
}
static inline int
F_6 ( T_2 V_7 , const struct V_1 * V_11 )
{
const struct V_5 * V_12 ;
if ( ! F_4 ( V_7 , V_11 -> V_13 ) )
return 0 ;
V_12 = F_2 ( V_11 -> V_6 , V_7 , V_11 -> V_8 ) ;
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
const struct V_19 * V_20 ,
struct V_1 * V_11 , int V_21 )
{
T_1 V_22 = V_20 -> V_18 ;
if ( V_21 == V_23 ) {
if ( V_22 == V_11 -> V_18 )
V_22 = * V_18 ;
F_9 ( V_18 , V_22 ) ;
} else {
if ( V_10 -> V_16 )
F_9 ( V_18 , V_22 ) ;
else
* V_18 = V_22 ;
}
return 0 ;
}
static inline int
F_10 ( const struct V_9 * V_10 ,
struct V_1 * V_11 , T_1 V_24 )
{
struct V_5 * V_12 ;
V_12 = F_2 ( V_11 -> V_6 , V_10 -> V_7 , V_11 -> V_8 ) ;
if ( F_11 ( V_10 -> V_7 , V_11 -> V_13 ) ) {
if ( V_12 -> V_14 == V_15 ) {
if ( V_10 -> V_16 && ( V_24 & V_25 ) )
memcpy ( V_12 -> V_16 , V_10 -> V_16 , V_26 ) ;
return V_27 ;
} else if ( ! V_10 -> V_16 )
return V_27 ;
memcpy ( V_12 -> V_16 , V_10 -> V_16 , V_26 ) ;
V_12 -> V_14 = V_15 ;
return V_23 ;
} else if ( V_10 -> V_16 ) {
memcpy ( V_12 -> V_16 , V_10 -> V_16 , V_26 ) ;
V_12 -> V_14 = V_15 ;
return 0 ;
} else {
V_12 -> V_14 = V_28 ;
return V_29 ;
}
}
static inline int
F_12 ( const struct V_9 * V_10 ,
struct V_1 * V_11 )
{
return ! F_13 ( V_10 -> V_7 , V_11 -> V_13 ) ;
}
static inline unsigned long
F_14 ( struct V_1 * V_11 , T_1 V_7 , unsigned long * V_18 )
{
const struct V_5 * V_12 =
F_2 ( V_11 -> V_6 , V_7 , V_11 -> V_8 ) ;
return V_12 -> V_14 == V_15 ? F_15 ( V_18 ) :
* V_18 ;
}
static inline int
F_16 ( struct V_30 * V_31 , const struct V_1 * V_11 ,
T_1 V_7 )
{
const struct V_5 * V_12 =
F_2 ( V_11 -> V_6 , V_7 , V_11 -> V_8 ) ;
return F_17 ( V_31 , V_32 ,
F_18 ( V_11 -> V_4 + V_7 ) ) ||
( V_12 -> V_14 == V_15 &&
F_19 ( V_31 , V_33 , V_26 , V_12 -> V_16 ) ) ;
}
static inline int
F_20 ( struct V_30 * V_31 , const struct V_1 * V_11 )
{
return F_17 ( V_31 , V_32 , F_18 ( V_11 -> V_4 ) ) ||
F_17 ( V_31 , V_34 , F_18 ( V_11 -> V_35 ) ) ;
}
static int
F_21 ( struct V_36 * V_37 , const struct V_30 * V_31 ,
const struct V_38 * V_39 ,
enum V_40 V_41 , struct V_42 * V_43 )
{
struct V_1 * V_11 = V_37 -> V_44 ;
T_4 V_45 = V_37 -> V_46 -> V_41 [ V_41 ] ;
struct V_9 V_10 = {} ;
struct V_19 V_20 = F_22 ( V_31 , V_43 , V_11 ) ;
T_1 V_3 ;
if ( ! ( V_43 -> V_24 & V_47 ) )
return 0 ;
V_3 = F_23 ( F_24 ( V_31 , V_43 -> V_24 & V_48 ) ) ;
if ( V_3 < V_11 -> V_4 || V_3 > V_11 -> V_35 )
return - V_49 ;
if ( F_25 ( V_31 ) < V_31 -> V_50 ||
( F_25 ( V_31 ) + V_51 ) > V_31 -> V_44 )
return - V_52 ;
V_10 . V_7 = F_1 ( V_11 , V_3 ) ;
V_10 . V_16 = F_26 ( V_31 ) -> V_53 ;
return V_45 ( V_37 , & V_10 , & V_20 , & V_43 -> V_20 , V_43 -> V_54 ) ;
}
static int
F_27 ( struct V_36 * V_37 , struct V_55 * V_56 [] ,
enum V_40 V_41 , T_1 * V_57 , T_1 V_24 , bool V_58 )
{
const struct V_1 * V_11 = V_37 -> V_44 ;
T_4 V_45 = V_37 -> V_46 -> V_41 [ V_41 ] ;
struct V_9 V_10 = {} ;
struct V_19 V_20 = F_28 ( V_11 ) ;
T_1 V_3 ;
int V_59 = 0 ;
if ( F_29 ( ! V_56 [ V_32 ] ||
! F_30 ( V_56 , V_60 ) ||
! F_30 ( V_56 , V_61 ) ||
! F_30 ( V_56 , V_62 ) ) )
return - V_63 ;
if ( V_56 [ V_64 ] )
* V_57 = F_31 ( V_56 [ V_64 ] ) ;
V_59 = F_32 ( V_56 [ V_32 ] , & V_3 ) ||
F_33 ( V_37 , V_56 , & V_20 ) ;
if ( V_59 )
return V_59 ;
if ( V_3 < V_11 -> V_4 || V_3 > V_11 -> V_35 )
return - V_49 ;
V_10 . V_7 = F_1 ( V_11 , V_3 ) ;
if ( V_56 [ V_33 ] )
V_10 . V_16 = F_34 ( V_56 [ V_33 ] ) ;
else
V_10 . V_16 = NULL ;
V_59 = V_45 ( V_37 , & V_10 , & V_20 , & V_20 , V_24 ) ;
return F_35 ( V_59 , V_24 ) ? 0 : V_59 ;
}
static bool
F_36 ( const struct V_36 * V_65 , const struct V_36 * V_66 )
{
const struct V_1 * V_67 = V_65 -> V_44 ;
const struct V_1 * V_68 = V_66 -> V_44 ;
return V_67 -> V_4 == V_68 -> V_4 &&
V_67 -> V_35 == V_68 -> V_35 &&
V_67 -> V_18 == V_68 -> V_18 &&
V_65 -> V_6 == V_66 -> V_6 ;
}
static bool
F_37 ( struct V_36 * V_37 , struct V_1 * V_11 ,
T_1 V_4 , T_1 V_35 , T_1 V_69 )
{
V_11 -> V_13 = F_38 ( ( V_35 - V_4 + 1 ) * V_11 -> V_8 ) ;
if ( ! V_11 -> V_13 )
return false ;
if ( V_11 -> V_8 ) {
V_11 -> V_6 = F_38 ( V_11 -> V_8 * V_69 ) ;
if ( ! V_11 -> V_6 ) {
F_39 ( V_11 -> V_13 ) ;
return false ;
}
}
V_11 -> V_4 = V_4 ;
V_11 -> V_35 = V_35 ;
V_11 -> V_69 = V_69 ;
V_11 -> V_18 = V_70 ;
V_37 -> V_44 = V_11 ;
V_37 -> V_71 = V_72 ;
return true ;
}
static int
F_40 ( struct V_36 * V_37 , struct V_55 * V_56 [] ,
T_1 V_24 )
{
T_1 V_4 , V_35 , V_73 = 0 ;
T_5 V_69 ;
struct V_1 * V_11 ;
int V_59 ;
if ( F_29 ( ! V_56 [ V_32 ] ||
! F_30 ( V_56 , V_60 ) ||
! F_30 ( V_56 , V_74 ) ) )
return - V_63 ;
V_59 = F_32 ( V_56 [ V_32 ] , & V_4 ) ;
if ( V_59 )
return V_59 ;
if ( V_56 [ V_34 ] ) {
V_59 = F_32 ( V_56 [ V_34 ] , & V_35 ) ;
if ( V_59 )
return V_59 ;
if ( V_4 > V_35 ) {
T_1 V_75 = V_4 ;
V_4 = V_35 ;
V_35 = V_75 ;
}
} else if ( V_56 [ V_76 ] ) {
T_6 V_77 = F_41 ( V_56 [ V_76 ] ) ;
if ( V_77 >= 32 )
return - V_78 ;
F_42 ( V_4 , V_35 , V_77 ) ;
} else
return - V_63 ;
V_69 = ( T_5 ) V_35 - V_4 + 1 ;
if ( V_69 > V_79 + 1 )
return - V_80 ;
V_11 = F_43 ( sizeof( * V_11 ) , V_81 ) ;
if ( ! V_11 )
return - V_82 ;
V_11 -> V_83 = F_44 ( 0 , V_69 - 1 ) ;
V_37 -> V_46 = & V_1 ;
if ( V_56 [ V_74 ] )
V_73 = F_45 ( V_56 [ V_74 ] ) ;
if ( V_73 & V_84 ) {
V_37 -> V_6 |= V_85 ;
if ( V_56 [ V_60 ] ) {
V_11 -> V_8 = sizeof( struct V_86 ) ;
V_11 -> V_87 [ V_88 ] =
F_46 ( struct V_86 , V_18 ) ;
V_11 -> V_87 [ V_89 ] =
F_46 ( struct V_86 , V_90 ) ;
if ( ! F_37 ( V_37 , V_11 , V_4 , V_35 ,
V_69 ) ) {
F_39 ( V_11 ) ;
return - V_82 ;
}
V_11 -> V_18 = F_47 (
V_56 [ V_60 ] ) ;
V_37 -> V_6 |= V_91 ;
F_48 ( V_37 , V_92 ) ;
} else {
V_11 -> V_8 = sizeof( struct V_93 ) ;
V_11 -> V_87 [ V_89 ] =
F_46 ( struct V_93 , V_90 ) ;
if ( ! F_37 ( V_37 , V_11 , V_4 , V_35 ,
V_69 ) ) {
F_39 ( V_11 ) ;
return - V_82 ;
}
}
} else if ( V_56 [ V_60 ] ) {
V_11 -> V_8 = sizeof( struct V_94 ) ;
V_11 -> V_87 [ V_88 ] =
F_46 ( struct V_94 , V_18 ) ;
if ( ! F_37 ( V_37 , V_11 , V_4 , V_35 , V_69 ) ) {
F_39 ( V_11 ) ;
return - V_82 ;
}
V_11 -> V_18 = F_47 ( V_56 [ V_60 ] ) ;
V_37 -> V_6 |= V_91 ;
F_48 ( V_37 , V_92 ) ;
} else {
V_11 -> V_8 = sizeof( struct V_5 ) ;
if ( ! F_37 ( V_37 , V_11 , V_4 , V_35 , V_69 ) ) {
F_39 ( V_11 ) ;
return - V_82 ;
}
V_37 -> V_46 = & V_1 ;
}
return 0 ;
}
static int T_7
F_49 ( void )
{
return F_50 ( & V_95 ) ;
}
static void T_8
F_51 ( void )
{
F_52 ( & V_95 ) ;
}
