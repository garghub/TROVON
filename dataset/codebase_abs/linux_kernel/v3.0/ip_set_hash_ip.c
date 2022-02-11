static inline bool
F_1 ( const struct V_1 * V_2 ,
const struct V_1 * V_3 )
{
return V_2 -> V_4 == V_3 -> V_4 ;
}
static inline bool
F_2 ( const struct V_1 * V_5 )
{
return V_5 -> V_4 == 0 ;
}
static inline void
F_3 ( struct V_1 * V_6 , const struct V_1 * V_7 )
{
V_6 -> V_4 = V_7 -> V_4 ;
}
static inline void
F_4 ( struct V_1 * V_5 )
{
V_5 -> V_4 = 0 ;
}
static inline bool
F_5 ( struct V_8 * V_9 , const struct V_1 * V_10 )
{
F_6 ( V_9 , V_11 , V_10 -> V_4 ) ;
return 0 ;
V_12:
return 1 ;
}
static bool
F_7 ( struct V_8 * V_9 , const struct V_1 * V_10 )
{
const struct V_13 * V_14 =
( const struct V_13 * ) V_10 ;
F_6 ( V_9 , V_11 , V_14 -> V_4 ) ;
F_8 ( V_9 , V_15 ,
F_9 ( F_10 ( V_14 -> V_16 ) ) ) ;
return 0 ;
V_12:
return 1 ;
}
static int
F_11 ( struct V_17 * V_18 , const struct V_8 * V_9 ,
enum V_19 V_20 , T_1 V_21 , T_1 V_22 , T_1 V_23 )
{
const struct V_24 * V_25 = V_18 -> V_10 ;
T_2 V_26 = V_18 -> V_27 -> V_20 [ V_20 ] ;
T_3 V_4 ;
F_12 ( V_9 , V_23 & V_28 , & V_4 ) ;
V_4 &= F_13 ( V_25 -> V_29 ) ;
if ( V_4 == 0 )
return - V_30 ;
return V_26 ( V_18 , & V_4 , V_25 -> V_16 ) ;
}
static int
F_14 ( struct V_17 * V_18 , struct V_31 * V_32 [] ,
enum V_19 V_20 , T_4 * V_33 , T_4 V_23 )
{
const struct V_24 * V_25 = V_18 -> V_10 ;
T_2 V_26 = V_18 -> V_27 -> V_20 [ V_20 ] ;
T_4 V_4 , V_34 , V_35 , V_16 = V_25 -> V_16 ;
T_3 V_36 ;
int V_37 = 0 ;
if ( F_15 ( ! V_32 [ V_11 ] ||
! F_16 ( V_32 , V_15 ) ) )
return - V_38 ;
if ( V_32 [ V_39 ] )
* V_33 = F_17 ( V_32 [ V_39 ] ) ;
V_37 = F_18 ( V_32 [ V_11 ] , & V_4 ) ;
if ( V_37 )
return V_37 ;
V_4 &= F_19 ( V_25 -> V_29 ) ;
if ( V_32 [ V_15 ] ) {
if ( ! F_20 ( V_25 -> V_16 ) )
return - V_40 ;
V_16 = F_21 ( V_32 [ V_15 ] ) ;
}
if ( V_20 == V_41 ) {
V_36 = F_9 ( V_4 ) ;
if ( V_36 == 0 )
return - V_42 ;
return V_26 ( V_18 , & V_36 , V_16 ) ;
}
if ( V_32 [ V_43 ] ) {
V_37 = F_18 ( V_32 [ V_43 ] , & V_34 ) ;
if ( V_37 )
return V_37 ;
if ( V_4 > V_34 )
F_22 ( V_4 , V_34 ) ;
} else if ( V_32 [ V_44 ] ) {
T_1 V_45 = F_23 ( V_32 [ V_44 ] ) ;
if ( V_45 > 32 )
return - V_46 ;
V_4 &= F_19 ( V_45 ) ;
V_34 = V_4 | ~ F_19 ( V_45 ) ;
} else
V_34 = V_4 ;
V_35 = V_25 -> V_29 == 32 ? 1 : 2 << ( 32 - V_25 -> V_29 - 1 ) ;
for (; ! F_24 ( V_34 , V_4 ) ; V_4 += V_35 ) {
V_36 = F_9 ( V_4 ) ;
if ( V_36 == 0 )
return - V_42 ;
V_37 = V_26 ( V_18 , & V_36 , V_16 ) ;
if ( V_37 && ! F_25 ( V_37 , V_23 ) )
return V_37 ;
else
V_37 = 0 ;
}
return V_37 ;
}
static bool
F_26 ( const struct V_17 * V_47 , const struct V_17 * V_48 )
{
const struct V_24 * V_49 = V_47 -> V_10 ;
const struct V_24 * V_50 = V_48 -> V_10 ;
return V_49 -> V_51 == V_50 -> V_51 &&
V_49 -> V_16 == V_50 -> V_16 &&
V_49 -> V_29 == V_50 -> V_29 ;
}
static inline bool
F_27 ( const struct V_52 * V_2 ,
const struct V_52 * V_3 )
{
return F_28 ( & V_2 -> V_4 . V_53 , & V_3 -> V_4 . V_53 ) == 0 ;
}
static inline bool
F_29 ( const struct V_52 * V_5 )
{
return F_30 ( & V_5 -> V_4 . V_53 ) ;
}
static inline void
F_31 ( struct V_52 * V_6 , const struct V_52 * V_7 )
{
F_32 ( & V_6 -> V_4 . V_53 , & V_7 -> V_4 . V_53 ) ;
}
static inline void
F_33 ( struct V_52 * V_5 )
{
F_34 ( & V_5 -> V_4 . V_53 , 0 , 0 , 0 , 0 ) ;
}
static inline void
F_35 ( union V_54 * V_4 , T_1 V_55 )
{
V_4 -> V_56 [ 0 ] &= F_36 ( V_55 ) [ 0 ] ;
V_4 -> V_56 [ 1 ] &= F_36 ( V_55 ) [ 1 ] ;
V_4 -> V_56 [ 2 ] &= F_36 ( V_55 ) [ 2 ] ;
V_4 -> V_56 [ 3 ] &= F_36 ( V_55 ) [ 3 ] ;
}
static bool
F_37 ( struct V_8 * V_9 , const struct V_52 * V_10 )
{
F_38 ( V_9 , V_11 , & V_10 -> V_4 ) ;
return 0 ;
V_12:
return 1 ;
}
static bool
F_39 ( struct V_8 * V_9 , const struct V_52 * V_10 )
{
const struct V_57 * V_58 =
( const struct V_57 * ) V_10 ;
F_38 ( V_9 , V_11 , & V_58 -> V_4 ) ;
F_8 ( V_9 , V_15 ,
F_9 ( F_10 ( V_58 -> V_16 ) ) ) ;
return 0 ;
V_12:
return 1 ;
}
static int
F_40 ( struct V_17 * V_18 , const struct V_8 * V_9 ,
enum V_19 V_20 , T_1 V_21 , T_1 V_22 , T_1 V_23 )
{
const struct V_24 * V_25 = V_18 -> V_10 ;
T_2 V_26 = V_18 -> V_27 -> V_20 [ V_20 ] ;
union V_54 V_4 ;
F_41 ( V_9 , V_23 & V_28 , & V_4 . V_53 ) ;
F_35 ( & V_4 , V_25 -> V_29 ) ;
if ( F_30 ( & V_4 . V_53 ) )
return - V_30 ;
return V_26 ( V_18 , & V_4 , V_25 -> V_16 ) ;
}
static int
F_42 ( struct V_17 * V_18 , struct V_31 * V_32 [] ,
enum V_19 V_20 , T_4 * V_33 , T_4 V_23 )
{
const struct V_24 * V_25 = V_18 -> V_10 ;
T_2 V_26 = V_18 -> V_27 -> V_20 [ V_20 ] ;
union V_54 V_4 ;
T_4 V_16 = V_25 -> V_16 ;
int V_37 ;
if ( F_15 ( ! V_32 [ V_11 ] ||
! F_16 ( V_32 , V_15 ) ||
V_32 [ V_43 ] ||
V_32 [ V_44 ] ) )
return - V_38 ;
if ( V_32 [ V_39 ] )
* V_33 = F_17 ( V_32 [ V_39 ] ) ;
V_37 = F_43 ( V_32 [ V_11 ] , & V_4 ) ;
if ( V_37 )
return V_37 ;
F_35 ( & V_4 , V_25 -> V_29 ) ;
if ( F_30 ( & V_4 . V_53 ) )
return - V_42 ;
if ( V_32 [ V_15 ] ) {
if ( ! F_20 ( V_25 -> V_16 ) )
return - V_40 ;
V_16 = F_21 ( V_32 [ V_15 ] ) ;
}
V_37 = V_26 ( V_18 , & V_4 , V_16 ) ;
return F_25 ( V_37 , V_23 ) ? 0 : V_37 ;
}
static int
F_44 ( struct V_17 * V_18 , struct V_31 * V_32 [] , T_4 V_23 )
{
T_4 V_59 = V_60 , V_51 = V_61 ;
T_1 V_29 , V_62 ;
struct V_24 * V_25 ;
if ( ! ( V_18 -> V_63 == V_64 || V_18 -> V_63 == V_65 ) )
return - V_66 ;
V_29 = V_18 -> V_63 == V_64 ? 32 : 128 ;
F_45 ( L_1 ,
V_18 -> V_67 , V_18 -> V_63 == V_64 ? L_2 : L_3 ) ;
if ( F_15 ( ! F_16 ( V_32 , V_68 ) ||
! F_16 ( V_32 , V_69 ) ||
! F_16 ( V_32 , V_15 ) ) )
return - V_38 ;
if ( V_32 [ V_68 ] ) {
V_59 = F_46 ( V_32 [ V_68 ] ) ;
if ( V_59 < V_70 )
V_59 = V_70 ;
}
if ( V_32 [ V_69 ] )
V_51 = F_46 ( V_32 [ V_69 ] ) ;
if ( V_32 [ V_71 ] ) {
V_29 = F_23 ( V_32 [ V_71 ] ) ;
if ( ( V_18 -> V_63 == V_64 && V_29 > 32 ) ||
( V_18 -> V_63 == V_65 && V_29 > 128 ) ||
V_29 == 0 )
return - V_72 ;
}
V_25 = F_47 ( sizeof( * V_25 ) , V_73 ) ;
if ( ! V_25 )
return - V_74 ;
V_25 -> V_51 = V_51 ;
V_25 -> V_29 = V_29 ;
F_48 ( & V_25 -> V_75 , sizeof( V_25 -> V_75 ) ) ;
V_25 -> V_16 = V_76 ;
V_62 = F_49 ( V_59 ) ;
V_25 -> V_77 = F_50 (
sizeof( struct V_78 )
+ F_51 ( V_62 ) * sizeof( struct V_79 ) ) ;
if ( ! V_25 -> V_77 ) {
F_52 ( V_25 ) ;
return - V_74 ;
}
V_25 -> V_77 -> F_49 = V_62 ;
V_18 -> V_10 = V_25 ;
if ( V_32 [ V_15 ] ) {
V_25 -> V_16 = F_21 ( V_32 [ V_15 ] ) ;
V_18 -> V_27 = V_18 -> V_63 == V_64
? & V_80 : & V_81 ;
if ( V_18 -> V_63 == V_64 )
F_53 ( V_18 ) ;
else
F_54 ( V_18 ) ;
} else {
V_18 -> V_27 = V_18 -> V_63 == V_64
? & V_82 : & V_83 ;
}
F_45 ( L_4 ,
V_18 -> V_67 , F_51 ( V_25 -> V_77 -> F_49 ) ,
V_25 -> V_77 -> F_49 , V_25 -> V_51 , V_18 -> V_10 , V_25 -> V_77 ) ;
return 0 ;
}
static int T_5
F_55 ( void )
{
return F_56 ( & V_84 ) ;
}
static void T_6
F_57 ( void )
{
F_58 ( & V_84 ) ;
}
