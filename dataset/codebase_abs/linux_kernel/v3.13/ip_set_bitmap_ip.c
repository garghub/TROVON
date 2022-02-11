static inline T_1
F_1 ( const struct V_1 * V_2 , T_1 V_3 )
{
return ( ( V_3 & F_2 ( V_2 -> V_4 ) ) - V_2 -> V_5 ) / V_2 -> V_6 ;
}
static inline int
F_3 ( const struct V_7 * V_8 ,
struct V_1 * V_9 , T_2 V_10 )
{
return ! ! F_4 ( V_8 -> V_11 , V_9 -> V_12 ) ;
}
static inline int
F_5 ( T_3 V_11 , const struct V_1 * V_9 , T_2 V_10 )
{
return ! ! F_4 ( V_11 , V_9 -> V_12 ) ;
}
static inline int
F_6 ( const struct V_7 * V_8 , struct V_1 * V_9 ,
T_1 V_13 , T_2 V_10 )
{
return ! ! F_7 ( V_8 -> V_11 , V_9 -> V_12 ) ;
}
static inline int
F_8 ( const struct V_7 * V_8 , struct V_1 * V_9 )
{
return ! F_9 ( V_8 -> V_11 , V_9 -> V_12 ) ;
}
static inline int
F_10 ( struct V_14 * V_15 , const struct V_1 * V_9 , T_1 V_11 ,
T_2 V_10 )
{
return F_11 ( V_15 , V_16 ,
F_12 ( V_9 -> V_5 + V_11 * V_9 -> V_6 ) ) ;
}
static inline int
F_13 ( struct V_14 * V_15 , const struct V_1 * V_9 )
{
return F_11 ( V_15 , V_16 , F_12 ( V_9 -> V_5 ) ) ||
F_11 ( V_15 , V_17 , F_12 ( V_9 -> V_18 ) ) ||
( V_9 -> V_4 != 32 &&
F_14 ( V_15 , V_19 , V_9 -> V_4 ) ) ;
}
static int
F_15 ( struct V_20 * V_21 , const struct V_14 * V_15 ,
const struct V_22 * V_23 ,
enum V_24 V_25 , struct V_26 * V_27 )
{
struct V_1 * V_9 = V_21 -> V_28 ;
T_4 V_29 = V_21 -> V_30 -> V_25 [ V_25 ] ;
struct V_7 V_8 = { } ;
struct V_31 V_32 = F_16 ( V_15 , V_27 , V_21 ) ;
T_1 V_3 ;
V_3 = F_17 ( F_18 ( V_15 , V_27 -> V_13 & V_33 ) ) ;
if ( V_3 < V_9 -> V_5 || V_3 > V_9 -> V_18 )
return - V_34 ;
V_8 . V_11 = F_1 ( V_9 , V_3 ) ;
return V_29 ( V_21 , & V_8 , & V_32 , & V_27 -> V_32 , V_27 -> V_35 ) ;
}
static int
F_19 ( struct V_20 * V_21 , struct V_36 * V_37 [] ,
enum V_24 V_25 , T_1 * V_38 , T_1 V_13 , bool V_39 )
{
struct V_1 * V_9 = V_21 -> V_28 ;
T_4 V_29 = V_21 -> V_30 -> V_25 [ V_25 ] ;
T_1 V_3 = 0 , V_40 = 0 ;
struct V_7 V_8 = { } ;
struct V_31 V_32 = F_20 ( V_21 ) ;
int V_41 = 0 ;
if ( F_21 ( ! V_37 [ V_16 ] ||
! F_22 ( V_37 , V_42 ) ||
! F_22 ( V_37 , V_43 ) ||
! F_22 ( V_37 , V_44 ) ) )
return - V_45 ;
if ( V_37 [ V_46 ] )
* V_38 = F_23 ( V_37 [ V_46 ] ) ;
V_41 = F_24 ( V_37 [ V_16 ] , & V_3 ) ||
F_25 ( V_21 , V_37 , & V_32 ) ;
if ( V_41 )
return V_41 ;
if ( V_3 < V_9 -> V_5 || V_3 > V_9 -> V_18 )
return - V_34 ;
if ( V_25 == V_47 ) {
V_8 . V_11 = F_1 ( V_9 , V_3 ) ;
return V_29 ( V_21 , & V_8 , & V_32 , & V_32 , V_13 ) ;
}
if ( V_37 [ V_17 ] ) {
V_41 = F_24 ( V_37 [ V_17 ] , & V_40 ) ;
if ( V_41 )
return V_41 ;
if ( V_3 > V_40 ) {
F_26 ( V_3 , V_40 ) ;
if ( V_3 < V_9 -> V_5 )
return - V_34 ;
}
} else if ( V_37 [ V_48 ] ) {
T_5 V_49 = F_27 ( V_37 [ V_48 ] ) ;
if ( ! V_49 || V_49 > 32 )
return - V_50 ;
F_28 ( V_3 , V_40 , V_49 ) ;
} else
V_40 = V_3 ;
if ( V_40 > V_9 -> V_18 )
return - V_34 ;
for (; ! F_29 ( V_40 , V_3 ) ; V_3 += V_9 -> V_6 ) {
V_8 . V_11 = F_1 ( V_9 , V_3 ) ;
V_41 = V_29 ( V_21 , & V_8 , & V_32 , & V_32 , V_13 ) ;
if ( V_41 && ! F_30 ( V_41 , V_13 ) )
return V_41 ;
else
V_41 = 0 ;
}
return V_41 ;
}
static bool
F_31 ( const struct V_20 * V_51 , const struct V_20 * V_52 )
{
const struct V_1 * V_53 = V_51 -> V_28 ;
const struct V_1 * V_54 = V_52 -> V_28 ;
return V_53 -> V_5 == V_54 -> V_5 &&
V_53 -> V_18 == V_54 -> V_18 &&
V_53 -> V_4 == V_54 -> V_4 &&
V_51 -> V_55 == V_52 -> V_55 &&
V_51 -> V_56 == V_52 -> V_56 ;
}
static bool
F_32 ( struct V_20 * V_21 , struct V_1 * V_9 ,
T_1 V_5 , T_1 V_18 ,
T_1 V_57 , T_1 V_6 , T_5 V_4 )
{
V_9 -> V_12 = F_33 ( V_9 -> V_58 ) ;
if ( ! V_9 -> V_12 )
return false ;
if ( V_21 -> V_10 ) {
V_9 -> V_56 = F_33 ( V_21 -> V_10 * V_57 ) ;
if ( ! V_9 -> V_56 ) {
F_34 ( V_9 -> V_12 ) ;
return false ;
}
}
V_9 -> V_5 = V_5 ;
V_9 -> V_18 = V_18 ;
V_9 -> V_57 = V_57 ;
V_9 -> V_6 = V_6 ;
V_9 -> V_4 = V_4 ;
V_21 -> V_55 = V_59 ;
V_21 -> V_28 = V_9 ;
V_21 -> V_60 = V_61 ;
return true ;
}
static int
F_35 ( struct V_62 * V_62 , struct V_20 * V_21 , struct V_36 * V_37 [] ,
T_1 V_13 )
{
struct V_1 * V_9 ;
T_1 V_5 = 0 , V_18 = 0 , V_6 ;
T_6 V_57 ;
T_5 V_4 = 32 ;
int V_41 ;
if ( F_21 ( ! V_37 [ V_16 ] ||
! F_22 ( V_37 , V_42 ) ||
! F_22 ( V_37 , V_63 ) ) )
return - V_45 ;
V_41 = F_24 ( V_37 [ V_16 ] , & V_5 ) ;
if ( V_41 )
return V_41 ;
if ( V_37 [ V_17 ] ) {
V_41 = F_24 ( V_37 [ V_17 ] , & V_18 ) ;
if ( V_41 )
return V_41 ;
if ( V_5 > V_18 ) {
T_1 V_64 = V_5 ;
V_5 = V_18 ;
V_18 = V_64 ;
}
} else if ( V_37 [ V_48 ] ) {
T_5 V_49 = F_27 ( V_37 [ V_48 ] ) ;
if ( V_49 >= 32 )
return - V_50 ;
F_28 ( V_5 , V_18 , V_49 ) ;
} else
return - V_45 ;
if ( V_37 [ V_19 ] ) {
V_4 = F_27 ( V_37 [ V_19 ] ) ;
if ( V_4 > 32 )
return - V_65 ;
V_5 &= F_2 ( V_4 ) ;
V_18 |= ~ F_2 ( V_4 ) ;
}
if ( V_4 == 32 ) {
V_6 = 1 ;
V_57 = ( T_6 ) V_18 - V_5 + 1 ;
} else {
T_5 V_66 ;
T_1 V_67 ;
V_67 = F_36 ( V_5 , V_18 , & V_66 ) ;
if ( ( ! V_67 && ( V_5 || V_18 != 0xFFFFFFFF ) ) ||
V_4 <= V_66 )
return - V_34 ;
F_37 ( L_1 , V_66 , V_4 ) ;
V_6 = 2 << ( 32 - V_4 - 1 ) ;
V_57 = 2 << ( V_4 - V_66 - 1 ) ;
}
if ( V_57 > V_68 + 1 )
return - V_69 ;
F_37 ( L_2 ,
V_6 , ( unsigned long long ) V_57 ) ;
V_9 = F_38 ( sizeof( * V_9 ) , V_70 ) ;
if ( ! V_9 )
return - V_71 ;
V_9 -> V_58 = F_39 ( 0 , V_57 - 1 ) ;
V_21 -> V_30 = & V_1 ;
V_21 -> V_10 = F_40 ( V_21 , V_37 , 0 ) ;
if ( ! F_32 ( V_21 , V_9 , V_5 , V_18 ,
V_57 , V_6 , V_4 ) ) {
F_34 ( V_9 ) ;
return - V_71 ;
}
if ( V_37 [ V_42 ] ) {
V_21 -> V_55 = F_41 ( V_37 [ V_42 ] ) ;
F_42 ( V_21 , V_72 ) ;
}
return 0 ;
}
static int T_7
F_43 ( void )
{
return F_44 ( & V_73 ) ;
}
static void T_8
F_45 ( void )
{
F_46 ( & V_73 ) ;
}
