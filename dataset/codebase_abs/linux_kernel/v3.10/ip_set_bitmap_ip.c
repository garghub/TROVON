static inline T_1
F_1 ( const struct V_1 * V_2 , T_1 V_3 )
{
return ( ( V_3 & F_2 ( V_2 -> V_4 ) ) - V_2 -> V_5 ) / V_2 -> V_6 ;
}
static inline int
F_3 ( const struct V_7 * V_8 , struct V_1 * V_9 )
{
return ! ! F_4 ( V_8 -> V_10 , V_9 -> V_11 ) ;
}
static inline int
F_5 ( T_2 V_10 , const struct V_1 * V_9 )
{
return ! ! F_4 ( V_10 , V_9 -> V_11 ) ;
}
static inline int
F_6 ( const struct V_7 * V_8 , struct V_1 * V_9 ,
T_1 V_12 )
{
return ! ! F_7 ( V_8 -> V_10 , V_9 -> V_11 ) ;
}
static inline int
F_8 ( const struct V_7 * V_8 , struct V_1 * V_9 )
{
return ! F_9 ( V_8 -> V_10 , V_9 -> V_11 ) ;
}
static inline int
F_10 ( struct V_13 * V_14 , const struct V_1 * V_9 , T_1 V_10 )
{
return F_11 ( V_14 , V_15 ,
F_12 ( V_9 -> V_5 + V_10 * V_9 -> V_6 ) ) ;
}
static inline int
F_13 ( struct V_13 * V_14 , const struct V_1 * V_9 )
{
return F_11 ( V_14 , V_15 , F_12 ( V_9 -> V_5 ) ) ||
F_11 ( V_14 , V_16 , F_12 ( V_9 -> V_17 ) ) ||
( V_9 -> V_4 != 32 &&
F_14 ( V_14 , V_18 , V_9 -> V_4 ) ) ;
}
static int
F_15 ( struct V_19 * V_20 , const struct V_13 * V_14 ,
const struct V_21 * V_22 ,
enum V_23 V_24 , struct V_25 * V_26 )
{
struct V_1 * V_9 = V_20 -> V_27 ;
T_3 V_28 = V_20 -> V_29 -> V_24 [ V_24 ] ;
struct V_7 V_8 = { } ;
struct V_30 V_31 = F_16 ( V_14 , V_26 , V_9 ) ;
T_1 V_3 ;
V_3 = F_17 ( F_18 ( V_14 , V_26 -> V_12 & V_32 ) ) ;
if ( V_3 < V_9 -> V_5 || V_3 > V_9 -> V_17 )
return - V_33 ;
V_8 . V_10 = F_1 ( V_9 , V_3 ) ;
return V_28 ( V_20 , & V_8 , & V_31 , & V_26 -> V_31 , V_26 -> V_34 ) ;
}
static int
F_19 ( struct V_19 * V_20 , struct V_35 * V_36 [] ,
enum V_23 V_24 , T_1 * V_37 , T_1 V_12 , bool V_38 )
{
struct V_1 * V_9 = V_20 -> V_27 ;
T_3 V_28 = V_20 -> V_29 -> V_24 [ V_24 ] ;
T_1 V_3 , V_39 ;
struct V_7 V_8 = { } ;
struct V_30 V_31 = F_20 ( V_9 ) ;
int V_40 = 0 ;
if ( F_21 ( ! V_36 [ V_15 ] ||
! F_22 ( V_36 , V_41 ) ||
! F_22 ( V_36 , V_42 ) ||
! F_22 ( V_36 , V_43 ) ) )
return - V_44 ;
if ( V_36 [ V_45 ] )
* V_37 = F_23 ( V_36 [ V_45 ] ) ;
V_40 = F_24 ( V_36 [ V_15 ] , & V_3 ) ||
F_25 ( V_20 , V_36 , & V_31 ) ;
if ( V_40 )
return V_40 ;
if ( V_3 < V_9 -> V_5 || V_3 > V_9 -> V_17 )
return - V_33 ;
if ( V_24 == V_46 ) {
V_8 . V_10 = F_1 ( V_9 , V_3 ) ;
return V_28 ( V_20 , & V_8 , & V_31 , & V_31 , V_12 ) ;
}
if ( V_36 [ V_16 ] ) {
V_40 = F_24 ( V_36 [ V_16 ] , & V_39 ) ;
if ( V_40 )
return V_40 ;
if ( V_3 > V_39 ) {
F_26 ( V_3 , V_39 ) ;
if ( V_3 < V_9 -> V_5 )
return - V_33 ;
}
} else if ( V_36 [ V_47 ] ) {
T_4 V_48 = F_27 ( V_36 [ V_47 ] ) ;
if ( ! V_48 || V_48 > 32 )
return - V_49 ;
F_28 ( V_3 , V_39 , V_48 ) ;
} else
V_39 = V_3 ;
if ( V_39 > V_9 -> V_17 )
return - V_33 ;
for (; ! F_29 ( V_39 , V_3 ) ; V_3 += V_9 -> V_6 ) {
V_8 . V_10 = F_1 ( V_9 , V_3 ) ;
V_40 = V_28 ( V_20 , & V_8 , & V_31 , & V_31 , V_12 ) ;
if ( V_40 && ! F_30 ( V_40 , V_12 ) )
return V_40 ;
else
V_40 = 0 ;
}
return V_40 ;
}
static bool
F_31 ( const struct V_19 * V_50 , const struct V_19 * V_51 )
{
const struct V_1 * V_52 = V_50 -> V_27 ;
const struct V_1 * V_53 = V_51 -> V_27 ;
return V_52 -> V_5 == V_53 -> V_5 &&
V_52 -> V_17 == V_53 -> V_17 &&
V_52 -> V_4 == V_53 -> V_4 &&
V_52 -> V_54 == V_53 -> V_54 &&
V_50 -> V_55 == V_51 -> V_55 ;
}
static bool
F_32 ( struct V_19 * V_20 , struct V_1 * V_9 ,
T_1 V_5 , T_1 V_17 ,
T_1 V_56 , T_1 V_6 , T_4 V_4 )
{
V_9 -> V_11 = F_33 ( V_9 -> V_57 ) ;
if ( ! V_9 -> V_11 )
return false ;
if ( V_9 -> V_58 ) {
V_9 -> V_55 = F_33 ( V_9 -> V_58 * V_56 ) ;
if ( ! V_9 -> V_55 ) {
F_34 ( V_9 -> V_11 ) ;
return false ;
}
}
V_9 -> V_5 = V_5 ;
V_9 -> V_17 = V_17 ;
V_9 -> V_56 = V_56 ;
V_9 -> V_6 = V_6 ;
V_9 -> V_4 = V_4 ;
V_9 -> V_54 = V_59 ;
V_20 -> V_27 = V_9 ;
V_20 -> V_60 = V_61 ;
return true ;
}
static int
F_35 ( struct V_19 * V_20 , struct V_35 * V_36 [] , T_1 V_12 )
{
struct V_1 * V_9 ;
T_1 V_5 , V_17 , V_6 , V_62 = 0 ;
T_5 V_56 ;
T_4 V_4 = 32 ;
int V_40 ;
if ( F_21 ( ! V_36 [ V_15 ] ||
! F_22 ( V_36 , V_41 ) ||
! F_22 ( V_36 , V_63 ) ) )
return - V_44 ;
V_40 = F_24 ( V_36 [ V_15 ] , & V_5 ) ;
if ( V_40 )
return V_40 ;
if ( V_36 [ V_16 ] ) {
V_40 = F_24 ( V_36 [ V_16 ] , & V_17 ) ;
if ( V_40 )
return V_40 ;
if ( V_5 > V_17 ) {
T_1 V_64 = V_5 ;
V_5 = V_17 ;
V_17 = V_64 ;
}
} else if ( V_36 [ V_47 ] ) {
T_4 V_48 = F_27 ( V_36 [ V_47 ] ) ;
if ( V_48 >= 32 )
return - V_49 ;
F_28 ( V_5 , V_17 , V_48 ) ;
} else
return - V_44 ;
if ( V_36 [ V_18 ] ) {
V_4 = F_27 ( V_36 [ V_18 ] ) ;
if ( V_4 > 32 )
return - V_65 ;
V_5 &= F_2 ( V_4 ) ;
V_17 |= ~ F_2 ( V_4 ) ;
}
if ( V_4 == 32 ) {
V_6 = 1 ;
V_56 = ( T_5 ) V_17 - V_5 + 1 ;
} else {
T_4 V_66 ;
T_1 V_67 ;
V_67 = F_36 ( V_5 , V_17 , & V_66 ) ;
if ( ( ! V_67 && ( V_5 || V_17 != 0xFFFFFFFF ) ) ||
V_4 <= V_66 )
return - V_33 ;
F_37 ( L_1 , V_66 , V_4 ) ;
V_6 = 2 << ( 32 - V_4 - 1 ) ;
V_56 = 2 << ( V_4 - V_66 - 1 ) ;
}
if ( V_56 > V_68 + 1 )
return - V_69 ;
F_37 ( L_2 ,
V_6 , ( unsigned long long ) V_56 ) ;
V_9 = F_38 ( sizeof( * V_9 ) , V_70 ) ;
if ( ! V_9 )
return - V_71 ;
V_9 -> V_57 = F_39 ( 0 , V_56 - 1 ) ;
V_20 -> V_29 = & V_1 ;
if ( V_36 [ V_63 ] )
V_62 = F_40 ( V_36 [ V_63 ] ) ;
if ( V_62 & V_72 ) {
V_20 -> V_55 |= V_73 ;
if ( V_36 [ V_41 ] ) {
V_9 -> V_58 = sizeof( struct V_74 ) ;
V_9 -> V_75 [ V_76 ] =
F_41 ( struct V_74 , V_54 ) ;
V_9 -> V_75 [ V_77 ] =
F_41 ( struct V_74 , V_78 ) ;
if ( ! F_32 ( V_20 , V_9 , V_5 , V_17 ,
V_56 , V_6 , V_4 ) ) {
F_34 ( V_9 ) ;
return - V_71 ;
}
V_9 -> V_54 = F_42 (
V_36 [ V_41 ] ) ;
V_20 -> V_55 |= V_79 ;
F_43 ( V_20 , V_80 ) ;
} else {
V_9 -> V_58 = sizeof( struct V_81 ) ;
V_9 -> V_75 [ V_77 ] =
F_41 ( struct V_81 , V_78 ) ;
if ( ! F_32 ( V_20 , V_9 , V_5 , V_17 ,
V_56 , V_6 , V_4 ) ) {
F_34 ( V_9 ) ;
return - V_71 ;
}
}
} else if ( V_36 [ V_41 ] ) {
V_9 -> V_58 = sizeof( struct V_82 ) ;
V_9 -> V_75 [ V_76 ] =
F_41 ( struct V_82 , V_54 ) ;
if ( ! F_32 ( V_20 , V_9 , V_5 , V_17 ,
V_56 , V_6 , V_4 ) ) {
F_34 ( V_9 ) ;
return - V_71 ;
}
V_9 -> V_54 = F_42 ( V_36 [ V_41 ] ) ;
V_20 -> V_55 |= V_79 ;
F_43 ( V_20 , V_80 ) ;
} else {
V_9 -> V_58 = 0 ;
if ( ! F_32 ( V_20 , V_9 , V_5 , V_17 ,
V_56 , V_6 , V_4 ) ) {
F_34 ( V_9 ) ;
return - V_71 ;
}
}
return 0 ;
}
static int T_6
F_44 ( void )
{
return F_45 ( & V_83 ) ;
}
static void T_7
F_46 ( void )
{
F_47 ( & V_83 ) ;
}
