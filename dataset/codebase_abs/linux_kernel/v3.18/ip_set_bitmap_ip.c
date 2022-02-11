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
struct V_7 V_8 = { . V_11 = 0 } ;
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
struct V_7 V_8 = { . V_11 = 0 } ;
struct V_31 V_32 = F_20 ( V_21 ) ;
int V_41 = 0 ;
if ( F_21 ( ! V_37 [ V_16 ] ||
! F_22 ( V_37 , V_42 ) ||
! F_22 ( V_37 , V_43 ) ||
! F_22 ( V_37 , V_44 ) ||
! F_22 ( V_37 , V_45 ) ||
! F_22 ( V_37 , V_46 ) ||
! F_22 ( V_37 , V_47 ) ) )
return - V_48 ;
if ( V_37 [ V_49 ] )
* V_38 = F_23 ( V_37 [ V_49 ] ) ;
V_41 = F_24 ( V_37 [ V_16 ] , & V_3 ) ||
F_25 ( V_21 , V_37 , & V_32 ) ;
if ( V_41 )
return V_41 ;
if ( V_3 < V_9 -> V_5 || V_3 > V_9 -> V_18 )
return - V_34 ;
if ( V_25 == V_50 ) {
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
} else if ( V_37 [ V_51 ] ) {
T_5 V_52 = F_27 ( V_37 [ V_51 ] ) ;
if ( ! V_52 || V_52 > 32 )
return - V_53 ;
F_28 ( V_3 , V_40 , V_52 ) ;
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
F_31 ( const struct V_20 * V_54 , const struct V_20 * V_55 )
{
const struct V_1 * V_56 = V_54 -> V_28 ;
const struct V_1 * V_57 = V_55 -> V_28 ;
return V_56 -> V_5 == V_57 -> V_5 &&
V_56 -> V_18 == V_57 -> V_18 &&
V_56 -> V_4 == V_57 -> V_4 &&
V_54 -> V_58 == V_55 -> V_58 &&
V_54 -> V_59 == V_55 -> V_59 ;
}
static bool
F_32 ( struct V_20 * V_21 , struct V_1 * V_9 ,
T_1 V_5 , T_1 V_18 ,
T_1 V_60 , T_1 V_6 , T_5 V_4 )
{
V_9 -> V_12 = F_33 ( V_9 -> V_61 ) ;
if ( ! V_9 -> V_12 )
return false ;
if ( V_21 -> V_10 ) {
V_9 -> V_59 = F_33 ( V_21 -> V_10 * V_60 ) ;
if ( ! V_9 -> V_59 ) {
F_34 ( V_9 -> V_12 ) ;
return false ;
}
}
V_9 -> V_5 = V_5 ;
V_9 -> V_18 = V_18 ;
V_9 -> V_60 = V_60 ;
V_9 -> V_6 = V_6 ;
V_9 -> V_4 = V_4 ;
V_21 -> V_58 = V_62 ;
V_21 -> V_28 = V_9 ;
V_21 -> V_63 = V_64 ;
return true ;
}
static int
F_35 ( struct V_65 * V_65 , struct V_20 * V_21 , struct V_36 * V_37 [] ,
T_1 V_13 )
{
struct V_1 * V_9 ;
T_1 V_5 = 0 , V_18 = 0 , V_6 ;
T_6 V_60 ;
T_5 V_4 = 32 ;
int V_41 ;
if ( F_21 ( ! V_37 [ V_16 ] ||
! F_22 ( V_37 , V_42 ) ||
! F_22 ( V_37 , V_66 ) ) )
return - V_48 ;
V_41 = F_24 ( V_37 [ V_16 ] , & V_5 ) ;
if ( V_41 )
return V_41 ;
if ( V_37 [ V_17 ] ) {
V_41 = F_24 ( V_37 [ V_17 ] , & V_18 ) ;
if ( V_41 )
return V_41 ;
if ( V_5 > V_18 ) {
T_1 V_67 = V_5 ;
V_5 = V_18 ;
V_18 = V_67 ;
}
} else if ( V_37 [ V_51 ] ) {
T_5 V_52 = F_27 ( V_37 [ V_51 ] ) ;
if ( V_52 >= 32 )
return - V_53 ;
F_28 ( V_5 , V_18 , V_52 ) ;
} else
return - V_48 ;
if ( V_37 [ V_19 ] ) {
V_4 = F_27 ( V_37 [ V_19 ] ) ;
if ( V_4 > 32 )
return - V_68 ;
V_5 &= F_2 ( V_4 ) ;
V_18 |= ~ F_2 ( V_4 ) ;
}
if ( V_4 == 32 ) {
V_6 = 1 ;
V_60 = ( T_6 ) V_18 - V_5 + 1 ;
} else {
T_5 V_69 ;
T_1 V_70 ;
V_70 = F_36 ( V_5 , V_18 , & V_69 ) ;
if ( ( ! V_70 && ( V_5 || V_18 != 0xFFFFFFFF ) ) ||
V_4 <= V_69 )
return - V_34 ;
F_37 ( L_1 , V_69 , V_4 ) ;
V_6 = 2 << ( 32 - V_4 - 1 ) ;
V_60 = 2 << ( V_4 - V_69 - 1 ) ;
}
if ( V_60 > V_71 + 1 )
return - V_72 ;
F_37 ( L_2 ,
V_6 , ( unsigned long long ) V_60 ) ;
V_9 = F_38 ( sizeof( * V_9 ) , V_73 ) ;
if ( ! V_9 )
return - V_74 ;
V_9 -> V_61 = F_39 ( 0 , V_60 - 1 ) ;
V_21 -> V_30 = & V_1 ;
V_21 -> V_10 = F_40 ( V_21 , V_37 , 0 ) ;
if ( ! F_32 ( V_21 , V_9 , V_5 , V_18 ,
V_60 , V_6 , V_4 ) ) {
F_34 ( V_9 ) ;
return - V_74 ;
}
if ( V_37 [ V_42 ] ) {
V_21 -> V_58 = F_41 ( V_37 [ V_42 ] ) ;
F_42 ( V_21 , V_75 ) ;
}
return 0 ;
}
static int T_7
F_43 ( void )
{
return F_44 ( & V_76 ) ;
}
static void T_8
F_45 ( void )
{
F_46 ( & V_76 ) ;
}
