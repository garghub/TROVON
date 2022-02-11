static inline bool
F_1 ( const struct V_1 * V_2 ,
const struct V_1 * V_3 ,
T_1 * V_4 )
{
return V_2 -> V_5 == V_3 -> V_5 ;
}
static inline bool
F_2 ( const struct V_1 * V_6 )
{
return V_6 -> V_5 == 0 ;
}
static inline void
F_3 ( struct V_1 * V_7 , const struct V_1 * V_8 )
{
V_7 -> V_5 = V_8 -> V_5 ;
}
static inline void
F_4 ( struct V_1 * V_6 )
{
V_6 -> V_5 = 0 ;
}
static inline bool
F_5 ( struct V_9 * V_10 , const struct V_1 * V_11 )
{
F_6 ( V_10 , V_12 , V_11 -> V_5 ) ;
return 0 ;
V_13:
return 1 ;
}
static bool
F_7 ( struct V_9 * V_10 , const struct V_1 * V_11 )
{
const struct V_14 * V_15 =
( const struct V_14 * ) V_11 ;
F_6 ( V_10 , V_12 , V_15 -> V_5 ) ;
F_8 ( V_10 , V_16 ,
F_9 ( F_10 ( V_15 -> V_17 ) ) ) ;
return 0 ;
V_13:
return 1 ;
}
static inline void
F_11 ( struct V_18 * V_19 , const struct V_1 * V_20 )
{
V_19 -> V_21 . V_5 = F_12 ( V_20 -> V_5 ) ;
}
static int
F_13 ( struct V_22 * V_23 , const struct V_9 * V_10 ,
const struct V_24 * V_25 ,
enum V_26 V_27 , const struct V_28 * V_29 )
{
const struct V_18 * V_19 = V_23 -> V_11 ;
T_2 V_30 = V_23 -> V_31 -> V_27 [ V_27 ] ;
T_3 V_5 ;
F_14 ( V_10 , V_29 -> V_32 & V_33 , & V_5 ) ;
V_5 &= F_15 ( V_19 -> V_34 ) ;
if ( V_5 == 0 )
return - V_35 ;
return V_30 ( V_23 , & V_5 , F_16 ( V_29 , V_19 ) , V_29 -> V_36 ) ;
}
static int
F_17 ( struct V_22 * V_23 , struct V_37 * V_38 [] ,
enum V_26 V_27 , T_1 * V_39 , T_1 V_32 , bool V_40 )
{
const struct V_18 * V_19 = V_23 -> V_11 ;
T_2 V_30 = V_23 -> V_31 -> V_27 [ V_27 ] ;
T_1 V_5 , V_41 , V_42 , V_17 = V_19 -> V_17 ;
T_3 V_43 ;
int V_44 = 0 ;
if ( F_18 ( ! V_38 [ V_12 ] ||
! F_19 ( V_38 , V_16 ) ) )
return - V_45 ;
if ( V_38 [ V_46 ] )
* V_39 = F_20 ( V_38 [ V_46 ] ) ;
V_44 = F_21 ( V_38 [ V_12 ] , & V_5 ) ;
if ( V_44 )
return V_44 ;
V_5 &= F_22 ( V_19 -> V_34 ) ;
if ( V_38 [ V_16 ] ) {
if ( ! F_23 ( V_19 -> V_17 ) )
return - V_47 ;
V_17 = F_24 ( V_38 [ V_16 ] ) ;
}
if ( V_27 == V_48 ) {
V_43 = F_9 ( V_5 ) ;
if ( V_43 == 0 )
return - V_49 ;
return V_30 ( V_23 , & V_43 , V_17 , V_32 ) ;
}
if ( V_38 [ V_50 ] ) {
V_44 = F_21 ( V_38 [ V_50 ] , & V_41 ) ;
if ( V_44 )
return V_44 ;
if ( V_5 > V_41 )
F_25 ( V_5 , V_41 ) ;
} else if ( V_38 [ V_51 ] ) {
T_4 V_52 = F_26 ( V_38 [ V_51 ] ) ;
if ( V_52 > 32 )
return - V_53 ;
F_27 ( V_5 , V_41 , V_52 ) ;
} else
V_41 = V_5 ;
V_42 = V_19 -> V_34 == 32 ? 1 : 2 << ( 32 - V_19 -> V_34 - 1 ) ;
if ( V_40 )
V_5 = V_19 -> V_21 . V_5 ;
for (; ! F_28 ( V_41 , V_5 ) ; V_5 += V_42 ) {
V_43 = F_9 ( V_5 ) ;
if ( V_43 == 0 )
return - V_49 ;
V_44 = V_30 ( V_23 , & V_43 , V_17 , V_32 ) ;
if ( V_44 && ! F_29 ( V_44 , V_32 ) )
return V_44 ;
else
V_44 = 0 ;
}
return V_44 ;
}
static bool
F_30 ( const struct V_22 * V_54 , const struct V_22 * V_55 )
{
const struct V_18 * V_56 = V_54 -> V_11 ;
const struct V_18 * V_57 = V_55 -> V_11 ;
return V_56 -> V_58 == V_57 -> V_58 &&
V_56 -> V_17 == V_57 -> V_17 &&
V_56 -> V_34 == V_57 -> V_34 ;
}
static inline bool
F_31 ( const struct V_59 * V_2 ,
const struct V_59 * V_3 ,
T_1 * V_4 )
{
return F_32 ( & V_2 -> V_5 . V_60 , & V_3 -> V_5 . V_60 ) == 0 ;
}
static inline bool
F_33 ( const struct V_59 * V_6 )
{
return F_34 ( & V_6 -> V_5 . V_60 ) ;
}
static inline void
F_35 ( struct V_59 * V_7 , const struct V_59 * V_8 )
{
V_7 -> V_5 . V_60 = V_8 -> V_5 . V_60 ;
}
static inline void
F_36 ( struct V_59 * V_6 )
{
F_37 ( & V_6 -> V_5 . V_60 , 0 , 0 , 0 , 0 ) ;
}
static inline void
F_38 ( union V_61 * V_5 , T_4 V_62 )
{
V_5 -> V_63 [ 0 ] &= F_39 ( V_62 ) [ 0 ] ;
V_5 -> V_63 [ 1 ] &= F_39 ( V_62 ) [ 1 ] ;
V_5 -> V_63 [ 2 ] &= F_39 ( V_62 ) [ 2 ] ;
V_5 -> V_63 [ 3 ] &= F_39 ( V_62 ) [ 3 ] ;
}
static bool
F_40 ( struct V_9 * V_10 , const struct V_59 * V_11 )
{
F_41 ( V_10 , V_12 , & V_11 -> V_5 ) ;
return 0 ;
V_13:
return 1 ;
}
static bool
F_42 ( struct V_9 * V_10 , const struct V_59 * V_11 )
{
const struct V_64 * V_65 =
( const struct V_64 * ) V_11 ;
F_41 ( V_10 , V_12 , & V_65 -> V_5 ) ;
F_8 ( V_10 , V_16 ,
F_9 ( F_10 ( V_65 -> V_17 ) ) ) ;
return 0 ;
V_13:
return 1 ;
}
static inline void
F_43 ( struct V_18 * V_19 , const struct V_59 * V_20 )
{
}
static int
F_44 ( struct V_22 * V_23 , const struct V_9 * V_10 ,
const struct V_24 * V_25 ,
enum V_26 V_27 , const struct V_28 * V_29 )
{
const struct V_18 * V_19 = V_23 -> V_11 ;
T_2 V_30 = V_23 -> V_31 -> V_27 [ V_27 ] ;
union V_61 V_5 ;
F_45 ( V_10 , V_29 -> V_32 & V_33 , & V_5 . V_60 ) ;
F_38 ( & V_5 , V_19 -> V_34 ) ;
if ( F_34 ( & V_5 . V_60 ) )
return - V_35 ;
return V_30 ( V_23 , & V_5 , F_16 ( V_29 , V_19 ) , V_29 -> V_36 ) ;
}
static int
F_46 ( struct V_22 * V_23 , struct V_37 * V_38 [] ,
enum V_26 V_27 , T_1 * V_39 , T_1 V_32 , bool V_40 )
{
const struct V_18 * V_19 = V_23 -> V_11 ;
T_2 V_30 = V_23 -> V_31 -> V_27 [ V_27 ] ;
union V_61 V_5 ;
T_1 V_17 = V_19 -> V_17 ;
int V_44 ;
if ( F_18 ( ! V_38 [ V_12 ] ||
! F_19 ( V_38 , V_16 ) ||
V_38 [ V_50 ] ||
V_38 [ V_51 ] ) )
return - V_45 ;
if ( V_38 [ V_46 ] )
* V_39 = F_20 ( V_38 [ V_46 ] ) ;
V_44 = F_47 ( V_38 [ V_12 ] , & V_5 ) ;
if ( V_44 )
return V_44 ;
F_38 ( & V_5 , V_19 -> V_34 ) ;
if ( F_34 ( & V_5 . V_60 ) )
return - V_49 ;
if ( V_38 [ V_16 ] ) {
if ( ! F_23 ( V_19 -> V_17 ) )
return - V_47 ;
V_17 = F_24 ( V_38 [ V_16 ] ) ;
}
V_44 = V_30 ( V_23 , & V_5 , V_17 , V_32 ) ;
return F_29 ( V_44 , V_32 ) ? 0 : V_44 ;
}
static int
F_48 ( struct V_22 * V_23 , struct V_37 * V_38 [] , T_1 V_32 )
{
T_1 V_66 = V_67 , V_58 = V_68 ;
T_4 V_34 , V_69 ;
struct V_18 * V_19 ;
if ( ! ( V_23 -> V_70 == V_71 || V_23 -> V_70 == V_72 ) )
return - V_73 ;
V_34 = V_23 -> V_70 == V_71 ? 32 : 128 ;
F_49 ( L_1 ,
V_23 -> V_74 , V_23 -> V_70 == V_71 ? L_2 : L_3 ) ;
if ( F_18 ( ! F_19 ( V_38 , V_75 ) ||
! F_19 ( V_38 , V_76 ) ||
! F_19 ( V_38 , V_16 ) ) )
return - V_45 ;
if ( V_38 [ V_75 ] ) {
V_66 = F_50 ( V_38 [ V_75 ] ) ;
if ( V_66 < V_77 )
V_66 = V_77 ;
}
if ( V_38 [ V_76 ] )
V_58 = F_50 ( V_38 [ V_76 ] ) ;
if ( V_38 [ V_78 ] ) {
V_34 = F_26 ( V_38 [ V_78 ] ) ;
if ( ( V_23 -> V_70 == V_71 && V_34 > 32 ) ||
( V_23 -> V_70 == V_72 && V_34 > 128 ) ||
V_34 == 0 )
return - V_79 ;
}
V_19 = F_51 ( sizeof( * V_19 ) , V_80 ) ;
if ( ! V_19 )
return - V_81 ;
V_19 -> V_58 = V_58 ;
V_19 -> V_34 = V_34 ;
F_52 ( & V_19 -> V_82 , sizeof( V_19 -> V_82 ) ) ;
V_19 -> V_17 = V_83 ;
V_69 = F_53 ( V_66 ) ;
V_19 -> V_84 = F_54 (
sizeof( struct V_85 )
+ F_55 ( V_69 ) * sizeof( struct V_86 ) ) ;
if ( ! V_19 -> V_84 ) {
F_56 ( V_19 ) ;
return - V_81 ;
}
V_19 -> V_84 -> F_53 = V_69 ;
V_23 -> V_11 = V_19 ;
if ( V_38 [ V_16 ] ) {
V_19 -> V_17 = F_24 ( V_38 [ V_16 ] ) ;
V_23 -> V_31 = V_23 -> V_70 == V_71
? & V_87 : & V_88 ;
if ( V_23 -> V_70 == V_71 )
F_57 ( V_23 ) ;
else
F_58 ( V_23 ) ;
} else {
V_23 -> V_31 = V_23 -> V_70 == V_71
? & V_89 : & V_90 ;
}
F_49 ( L_4 ,
V_23 -> V_74 , F_55 ( V_19 -> V_84 -> F_53 ) ,
V_19 -> V_84 -> F_53 , V_19 -> V_58 , V_23 -> V_11 , V_19 -> V_84 ) ;
return 0 ;
}
static int T_5
F_59 ( void )
{
return F_60 ( & V_91 ) ;
}
static void T_6
F_61 ( void )
{
F_62 ( & V_91 ) ;
}
