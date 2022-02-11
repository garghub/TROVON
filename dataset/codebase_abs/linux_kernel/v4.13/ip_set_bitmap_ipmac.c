static inline T_1
F_1 ( const struct V_1 * V_2 , T_1 V_3 )
{
return V_3 - V_2 -> V_4 ;
}
static inline int
F_2 ( const struct V_5 * V_6 ,
const struct V_1 * V_7 , T_2 V_8 )
{
const struct V_9 * V_10 ;
if ( ! F_3 ( V_6 -> V_11 , V_7 -> V_12 ) )
return 0 ;
V_10 = F_4 ( V_7 -> V_13 , V_6 -> V_11 , V_8 ) ;
if ( V_6 -> V_14 && V_10 -> V_15 == V_16 )
return F_5 ( V_6 -> V_17 , V_10 -> V_17 ) ;
return - V_18 ;
}
static inline int
F_6 ( T_3 V_11 , const struct V_1 * V_7 , T_2 V_8 )
{
const struct V_9 * V_10 ;
if ( ! F_3 ( V_11 , V_7 -> V_12 ) )
return 0 ;
V_10 = F_4 ( V_7 -> V_13 , V_11 , V_8 ) ;
return V_10 -> V_15 == V_16 ;
}
static inline int
F_7 ( const struct V_9 * V_10 )
{
return V_10 -> V_15 == V_16 ;
}
static inline int
F_8 ( unsigned long * V_19 ,
const struct V_5 * V_6 ,
const struct V_20 * V_21 , struct V_22 * V_23 ,
struct V_1 * V_7 , int V_24 )
{
T_1 V_25 = V_21 -> V_19 ;
if ( V_24 == V_26 ) {
if ( V_25 == V_23 -> V_19 )
V_25 = * V_19 ;
F_9 ( V_19 , V_25 ) ;
} else {
if ( V_6 -> V_14 )
F_9 ( V_19 , V_25 ) ;
else
* V_19 = V_25 ;
}
return 0 ;
}
static inline int
F_10 ( const struct V_5 * V_6 ,
struct V_1 * V_7 , T_1 V_27 , T_2 V_8 )
{
struct V_9 * V_10 ;
V_10 = F_11 ( V_7 -> V_13 , V_6 -> V_11 , V_8 ) ;
if ( F_3 ( V_6 -> V_11 , V_7 -> V_12 ) ) {
if ( V_10 -> V_15 == V_16 ) {
if ( V_6 -> V_14 &&
( V_27 & V_28 ) &&
! F_5 ( V_6 -> V_17 , V_10 -> V_17 ) ) {
F_12 ( V_6 -> V_11 , V_7 -> V_12 ) ;
F_13 () ;
F_14 ( V_10 -> V_17 , V_6 -> V_17 ) ;
}
return V_29 ;
} else if ( ! V_6 -> V_14 )
return V_29 ;
F_12 ( V_6 -> V_11 , V_7 -> V_12 ) ;
F_13 () ;
F_14 ( V_10 -> V_17 , V_6 -> V_17 ) ;
V_10 -> V_15 = V_16 ;
return V_26 ;
} else if ( V_6 -> V_14 ) {
F_14 ( V_10 -> V_17 , V_6 -> V_17 ) ;
V_10 -> V_15 = V_16 ;
return 0 ;
}
V_10 -> V_15 = V_30 ;
return V_31 ;
}
static inline int
F_15 ( const struct V_5 * V_6 ,
struct V_1 * V_7 )
{
return ! F_16 ( V_6 -> V_11 , V_7 -> V_12 ) ;
}
static inline int
F_17 ( struct V_32 * V_33 , const struct V_1 * V_7 ,
T_1 V_11 , T_2 V_8 )
{
const struct V_9 * V_10 =
F_4 ( V_7 -> V_13 , V_11 , V_8 ) ;
return F_18 ( V_33 , V_34 ,
F_19 ( V_7 -> V_4 + V_11 ) ) ||
( V_10 -> V_15 == V_16 &&
F_20 ( V_33 , V_35 , V_36 , V_10 -> V_17 ) ) ;
}
static inline int
F_21 ( struct V_32 * V_33 , const struct V_1 * V_7 )
{
return F_18 ( V_33 , V_34 , F_19 ( V_7 -> V_4 ) ) ||
F_18 ( V_33 , V_37 , F_19 ( V_7 -> V_38 ) ) ;
}
static int
F_22 ( struct V_22 * V_23 , const struct V_32 * V_33 ,
const struct V_39 * V_40 ,
enum V_41 V_42 , struct V_43 * V_44 )
{
struct V_1 * V_7 = V_23 -> V_45 ;
T_4 V_46 = V_23 -> V_47 -> V_42 [ V_42 ] ;
struct V_5 V_6 = { . V_11 = 0 , . V_14 = 1 } ;
struct V_20 V_21 = F_23 ( V_33 , V_44 , V_23 ) ;
T_1 V_3 ;
if ( ! ( V_44 -> V_27 & V_48 ) )
return 0 ;
V_3 = F_24 ( F_25 ( V_33 , V_44 -> V_27 & V_49 ) ) ;
if ( V_3 < V_7 -> V_4 || V_3 > V_7 -> V_38 )
return - V_50 ;
if ( F_26 ( V_33 ) < V_33 -> V_51 ||
( F_26 ( V_33 ) + V_52 ) > V_33 -> V_45 )
return - V_53 ;
V_6 . V_11 = F_1 ( V_7 , V_3 ) ;
memcpy ( V_6 . V_17 , F_27 ( V_33 ) -> V_54 , V_36 ) ;
return V_46 ( V_23 , & V_6 , & V_21 , & V_44 -> V_21 , V_44 -> V_55 ) ;
}
static int
F_28 ( struct V_22 * V_23 , struct V_56 * V_57 [] ,
enum V_41 V_42 , T_1 * V_58 , T_1 V_27 , bool V_59 )
{
const struct V_1 * V_7 = V_23 -> V_45 ;
T_4 V_46 = V_23 -> V_47 -> V_42 [ V_42 ] ;
struct V_5 V_6 = { . V_11 = 0 } ;
struct V_20 V_21 = F_29 ( V_23 ) ;
T_1 V_3 = 0 ;
int V_60 = 0 ;
if ( V_57 [ V_61 ] )
* V_58 = F_30 ( V_57 [ V_61 ] ) ;
if ( F_31 ( ! V_57 [ V_34 ] ) )
return - V_62 ;
V_60 = F_32 ( V_57 [ V_34 ] , & V_3 ) ;
if ( V_60 )
return V_60 ;
V_60 = F_33 ( V_23 , V_57 , & V_21 ) ;
if ( V_60 )
return V_60 ;
if ( V_3 < V_7 -> V_4 || V_3 > V_7 -> V_38 )
return - V_50 ;
V_6 . V_11 = F_1 ( V_7 , V_3 ) ;
if ( V_57 [ V_35 ] ) {
if ( F_34 ( V_57 [ V_35 ] ) != V_36 )
return - V_62 ;
memcpy ( V_6 . V_17 , F_35 ( V_57 [ V_35 ] ) , V_36 ) ;
V_6 . V_14 = 1 ;
}
V_60 = V_46 ( V_23 , & V_6 , & V_21 , & V_21 , V_27 ) ;
return F_36 ( V_60 , V_27 ) ? 0 : V_60 ;
}
static bool
F_37 ( const struct V_22 * V_63 , const struct V_22 * V_64 )
{
const struct V_1 * V_65 = V_63 -> V_45 ;
const struct V_1 * V_66 = V_64 -> V_45 ;
return V_65 -> V_4 == V_66 -> V_4 &&
V_65 -> V_38 == V_66 -> V_38 &&
V_63 -> V_19 == V_64 -> V_19 &&
V_63 -> V_13 == V_64 -> V_13 ;
}
static bool
F_38 ( struct V_22 * V_23 , struct V_1 * V_7 ,
T_1 V_4 , T_1 V_38 , T_1 V_67 )
{
V_7 -> V_12 = F_39 ( V_7 -> V_68 ) ;
if ( ! V_7 -> V_12 )
return false ;
V_7 -> V_4 = V_4 ;
V_7 -> V_38 = V_38 ;
V_7 -> V_67 = V_67 ;
V_23 -> V_19 = V_69 ;
V_23 -> V_45 = V_7 ;
V_23 -> V_70 = V_71 ;
return true ;
}
static int
F_40 ( struct V_72 * V_72 , struct V_22 * V_23 , struct V_56 * V_57 [] ,
T_1 V_27 )
{
T_1 V_4 = 0 , V_38 = 0 ;
T_5 V_67 ;
struct V_1 * V_7 ;
int V_60 ;
if ( F_31 ( ! V_57 [ V_34 ] ||
! F_41 ( V_57 , V_73 ) ||
! F_41 ( V_57 , V_74 ) ) )
return - V_62 ;
V_60 = F_32 ( V_57 [ V_34 ] , & V_4 ) ;
if ( V_60 )
return V_60 ;
if ( V_57 [ V_37 ] ) {
V_60 = F_32 ( V_57 [ V_37 ] , & V_38 ) ;
if ( V_60 )
return V_60 ;
if ( V_4 > V_38 ) {
T_1 V_75 = V_4 ;
V_4 = V_38 ;
V_38 = V_75 ;
}
} else if ( V_57 [ V_76 ] ) {
T_6 V_77 = F_42 ( V_57 [ V_76 ] ) ;
if ( V_77 >= V_78 )
return - V_79 ;
F_43 ( V_4 , V_38 , V_77 ) ;
} else {
return - V_62 ;
}
V_67 = ( T_5 ) V_38 - V_4 + 1 ;
if ( V_67 > V_80 + 1 )
return - V_81 ;
V_23 -> V_8 = F_44 ( V_23 , V_57 ,
sizeof( struct V_9 ) ,
F_45 ( struct V_9 ) ) ;
V_7 = F_39 ( sizeof( * V_7 ) + V_67 * V_23 -> V_8 ) ;
if ( ! V_7 )
return - V_82 ;
V_7 -> V_68 = F_46 ( 0 , V_67 - 1 ) ;
V_23 -> V_47 = & V_1 ;
if ( ! F_38 ( V_23 , V_7 , V_4 , V_38 , V_67 ) ) {
F_47 ( V_7 ) ;
return - V_82 ;
}
if ( V_57 [ V_73 ] ) {
V_23 -> V_19 = F_48 ( V_57 [ V_73 ] ) ;
F_49 ( V_23 , V_83 ) ;
}
return 0 ;
}
static int T_7
F_50 ( void )
{
return F_51 ( & V_84 ) ;
}
static void T_8
F_52 ( void )
{
F_53 () ;
F_54 ( & V_84 ) ;
}
