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
return ! ! F_4 ( V_8 -> V_11 , V_9 -> V_12 ) ;
}
static inline int
F_7 ( const struct V_7 * V_8 , struct V_1 * V_9 )
{
return ! F_8 ( V_8 -> V_11 , V_9 -> V_12 ) ;
}
static inline int
F_9 ( struct V_14 * V_15 , const struct V_1 * V_9 , T_1 V_11 ,
T_2 V_10 )
{
return F_10 ( V_15 , V_16 ,
F_11 ( V_9 -> V_5 + V_11 * V_9 -> V_6 ) ) ;
}
static inline int
F_12 ( struct V_14 * V_15 , const struct V_1 * V_9 )
{
return F_10 ( V_15 , V_16 , F_11 ( V_9 -> V_5 ) ) ||
F_10 ( V_15 , V_17 , F_11 ( V_9 -> V_18 ) ) ||
( V_9 -> V_4 != 32 &&
F_13 ( V_15 , V_19 , V_9 -> V_4 ) ) ;
}
static int
F_14 ( struct V_20 * V_21 , const struct V_14 * V_15 ,
const struct V_22 * V_23 ,
enum V_24 V_25 , struct V_26 * V_27 )
{
struct V_1 * V_9 = V_21 -> V_28 ;
T_4 V_29 = V_21 -> V_30 -> V_25 [ V_25 ] ;
struct V_7 V_8 = { . V_11 = 0 } ;
struct V_31 V_32 = F_15 ( V_15 , V_27 , V_21 ) ;
T_1 V_3 ;
V_3 = F_16 ( F_17 ( V_15 , V_27 -> V_13 & V_33 ) ) ;
if ( V_3 < V_9 -> V_5 || V_3 > V_9 -> V_18 )
return - V_34 ;
V_8 . V_11 = F_1 ( V_9 , V_3 ) ;
return V_29 ( V_21 , & V_8 , & V_32 , & V_27 -> V_32 , V_27 -> V_35 ) ;
}
static int
F_18 ( struct V_20 * V_21 , struct V_36 * V_37 [] ,
enum V_24 V_25 , T_1 * V_38 , T_1 V_13 , bool V_39 )
{
struct V_1 * V_9 = V_21 -> V_28 ;
T_4 V_29 = V_21 -> V_30 -> V_25 [ V_25 ] ;
T_1 V_3 = 0 , V_40 = 0 ;
struct V_7 V_8 = { . V_11 = 0 } ;
struct V_31 V_32 = F_19 ( V_21 ) ;
int V_41 = 0 ;
if ( V_37 [ V_42 ] )
* V_38 = F_20 ( V_37 [ V_42 ] ) ;
if ( F_21 ( ! V_37 [ V_16 ] ) )
return - V_43 ;
V_41 = F_22 ( V_37 [ V_16 ] , & V_3 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_23 ( V_21 , V_37 , & V_32 ) ;
if ( V_41 )
return V_41 ;
if ( V_3 < V_9 -> V_5 || V_3 > V_9 -> V_18 )
return - V_34 ;
if ( V_25 == V_44 ) {
V_8 . V_11 = F_1 ( V_9 , V_3 ) ;
return V_29 ( V_21 , & V_8 , & V_32 , & V_32 , V_13 ) ;
}
if ( V_37 [ V_17 ] ) {
V_41 = F_22 ( V_37 [ V_17 ] , & V_40 ) ;
if ( V_41 )
return V_41 ;
if ( V_3 > V_40 ) {
F_24 ( V_3 , V_40 ) ;
if ( V_3 < V_9 -> V_5 )
return - V_34 ;
}
} else if ( V_37 [ V_45 ] ) {
T_5 V_46 = F_25 ( V_37 [ V_45 ] ) ;
if ( ! V_46 || V_46 > V_47 )
return - V_48 ;
F_26 ( V_3 , V_40 , V_46 ) ;
} else {
V_40 = V_3 ;
}
if ( V_40 > V_9 -> V_18 )
return - V_34 ;
for (; ! F_27 ( V_40 , V_3 ) ; V_3 += V_9 -> V_6 ) {
V_8 . V_11 = F_1 ( V_9 , V_3 ) ;
V_41 = V_29 ( V_21 , & V_8 , & V_32 , & V_32 , V_13 ) ;
if ( V_41 && ! F_28 ( V_41 , V_13 ) )
return V_41 ;
V_41 = 0 ;
}
return V_41 ;
}
static bool
F_29 ( const struct V_20 * V_49 , const struct V_20 * V_50 )
{
const struct V_1 * V_51 = V_49 -> V_28 ;
const struct V_1 * V_52 = V_50 -> V_28 ;
return V_51 -> V_5 == V_52 -> V_5 &&
V_51 -> V_18 == V_52 -> V_18 &&
V_51 -> V_4 == V_52 -> V_4 &&
V_49 -> V_53 == V_50 -> V_53 &&
V_49 -> V_54 == V_50 -> V_54 ;
}
static bool
F_30 ( struct V_20 * V_21 , struct V_1 * V_9 ,
T_1 V_5 , T_1 V_18 ,
T_1 V_55 , T_1 V_6 , T_5 V_4 )
{
V_9 -> V_12 = F_31 ( V_9 -> V_56 ) ;
if ( ! V_9 -> V_12 )
return false ;
if ( V_21 -> V_10 ) {
V_9 -> V_54 = F_31 ( V_21 -> V_10 * V_55 ) ;
if ( ! V_9 -> V_54 ) {
F_32 ( V_9 -> V_12 ) ;
return false ;
}
}
V_9 -> V_5 = V_5 ;
V_9 -> V_18 = V_18 ;
V_9 -> V_55 = V_55 ;
V_9 -> V_6 = V_6 ;
V_9 -> V_4 = V_4 ;
V_21 -> V_53 = V_57 ;
V_21 -> V_28 = V_9 ;
V_21 -> V_58 = V_59 ;
return true ;
}
static int
F_33 ( struct V_60 * V_60 , struct V_20 * V_21 , struct V_36 * V_37 [] ,
T_1 V_13 )
{
struct V_1 * V_9 ;
T_1 V_5 = 0 , V_18 = 0 , V_6 ;
T_6 V_55 ;
T_5 V_4 = 32 ;
int V_41 ;
if ( F_21 ( ! V_37 [ V_16 ] ||
! F_34 ( V_37 , V_61 ) ||
! F_34 ( V_37 , V_62 ) ) )
return - V_43 ;
V_41 = F_22 ( V_37 [ V_16 ] , & V_5 ) ;
if ( V_41 )
return V_41 ;
if ( V_37 [ V_17 ] ) {
V_41 = F_22 ( V_37 [ V_17 ] , & V_18 ) ;
if ( V_41 )
return V_41 ;
if ( V_5 > V_18 ) {
T_1 V_63 = V_5 ;
V_5 = V_18 ;
V_18 = V_63 ;
}
} else if ( V_37 [ V_45 ] ) {
T_5 V_46 = F_25 ( V_37 [ V_45 ] ) ;
if ( V_46 >= V_47 )
return - V_48 ;
F_26 ( V_5 , V_18 , V_46 ) ;
} else {
return - V_43 ;
}
if ( V_37 [ V_19 ] ) {
V_4 = F_25 ( V_37 [ V_19 ] ) ;
if ( V_4 > V_47 )
return - V_64 ;
V_5 &= F_2 ( V_4 ) ;
V_18 |= ~ F_2 ( V_4 ) ;
}
if ( V_4 == 32 ) {
V_6 = 1 ;
V_55 = ( T_6 ) V_18 - V_5 + 1 ;
} else {
T_5 V_65 ;
T_1 V_66 ;
V_66 = F_35 ( V_5 , V_18 , & V_65 ) ;
if ( ( ! V_66 && ( V_5 || V_18 != 0xFFFFFFFF ) ) ||
V_4 <= V_65 )
return - V_34 ;
F_36 ( L_1 , V_65 , V_4 ) ;
V_6 = 2 << ( 32 - V_4 - 1 ) ;
V_55 = 2 << ( V_4 - V_65 - 1 ) ;
}
if ( V_55 > V_67 + 1 )
return - V_68 ;
F_36 ( L_2 ,
V_6 , ( unsigned long long ) V_55 ) ;
V_9 = F_37 ( sizeof( * V_9 ) , V_69 ) ;
if ( ! V_9 )
return - V_70 ;
V_9 -> V_56 = F_38 ( 0 , V_55 - 1 ) ;
V_21 -> V_30 = & V_1 ;
V_21 -> V_10 = F_39 ( V_21 , V_37 , 0 ) ;
if ( ! F_30 ( V_21 , V_9 , V_5 , V_18 ,
V_55 , V_6 , V_4 ) ) {
F_32 ( V_9 ) ;
return - V_70 ;
}
if ( V_37 [ V_61 ] ) {
V_21 -> V_53 = F_40 ( V_37 [ V_61 ] ) ;
F_41 ( V_21 , V_71 ) ;
}
return 0 ;
}
static int T_7
F_42 ( void )
{
return F_43 ( & V_72 ) ;
}
static void T_8
F_44 ( void )
{
F_45 () ;
F_46 ( & V_72 ) ;
}
