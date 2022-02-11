static inline bool
F_1 ( const struct V_1 * V_2 ,
const struct V_1 * V_3 ,
T_1 * V_4 )
{
return V_2 -> V_5 == V_3 -> V_5 &&
V_2 -> V_6 == V_3 -> V_6 ;
}
static inline bool
F_2 ( const struct V_1 * V_7 )
{
return V_7 -> V_6 == 0 ;
}
static inline void
F_3 ( struct V_1 * V_8 ,
const struct V_1 * V_9 )
{
V_8 -> V_5 = V_9 -> V_5 ;
V_8 -> V_6 = V_9 -> V_6 ;
V_8 -> V_10 = V_9 -> V_10 ;
}
static inline void
F_4 ( struct V_1 * V_8 , T_1 V_11 )
{
V_8 -> V_10 = ! ! ( V_11 & V_12 ) ;
}
static inline void
F_5 ( struct V_1 * V_8 , T_1 * V_11 )
{
if ( V_8 -> V_10 ) {
* V_11 = V_12 ;
V_8 -> V_10 = 0 ;
}
}
static inline int
F_6 ( const struct V_1 * V_7 )
{
return V_7 -> V_10 ? - V_13 : 1 ;
}
static inline void
F_7 ( struct V_1 * V_7 , T_2 V_6 )
{
V_7 -> V_5 &= F_8 ( V_6 ) ;
V_7 -> V_6 = V_6 ;
}
static inline void
F_9 ( struct V_1 * V_7 )
{
V_7 -> V_6 = 0 ;
}
static bool
F_10 ( struct V_14 * V_15 , const struct V_1 * V_16 )
{
T_1 V_11 = V_16 -> V_10 ? V_12 : 0 ;
if ( F_11 ( V_15 , V_17 , V_16 -> V_5 ) ||
F_12 ( V_15 , V_18 , V_16 -> V_6 ) ||
( V_11 &&
F_13 ( V_15 , V_19 , F_14 ( V_11 ) ) ) )
goto V_20;
return 0 ;
V_20:
return 1 ;
}
static bool
F_15 ( struct V_14 * V_15 , const struct V_1 * V_16 )
{
const struct V_21 * V_22 =
( const struct V_21 * ) V_16 ;
T_1 V_11 = V_16 -> V_10 ? V_12 : 0 ;
if ( F_11 ( V_15 , V_17 , V_22 -> V_5 ) ||
F_12 ( V_15 , V_18 , V_22 -> V_6 ) ||
F_13 ( V_15 , V_23 ,
F_14 ( F_16 ( V_22 -> V_24 ) ) ) ||
( V_11 &&
F_13 ( V_15 , V_19 , F_14 ( V_11 ) ) ) )
goto V_20;
return 0 ;
V_20:
return 1 ;
}
static inline void
F_17 ( struct V_25 * V_26 ,
const struct V_1 * V_27 )
{
V_26 -> V_28 . V_5 = V_27 -> V_5 ;
}
static int
F_18 ( struct V_29 * V_30 , const struct V_14 * V_15 ,
const struct V_31 * V_32 ,
enum V_33 V_34 , const struct V_35 * V_36 )
{
const struct V_25 * V_26 = V_30 -> V_16 ;
T_3 V_37 = V_30 -> V_38 -> V_34 [ V_34 ] ;
struct V_1 V_16 = {
. V_6 = V_26 -> V_39 [ 0 ] . V_6 ? V_26 -> V_39 [ 0 ] . V_6 : V_40
} ;
if ( V_16 . V_6 == 0 )
return - V_41 ;
if ( V_34 == V_42 )
V_16 . V_6 = V_40 ;
F_19 ( V_15 , V_36 -> V_11 & V_43 , & V_16 . V_5 ) ;
V_16 . V_5 &= F_8 ( V_16 . V_6 ) ;
return V_37 ( V_30 , & V_16 , F_20 ( V_36 , V_26 ) , V_36 -> V_44 ) ;
}
static int
F_21 ( struct V_29 * V_30 , struct V_45 * V_46 [] ,
enum V_33 V_34 , T_1 * V_47 , T_1 V_11 , bool V_48 )
{
const struct V_25 * V_26 = V_30 -> V_16 ;
T_3 V_37 = V_30 -> V_38 -> V_34 [ V_34 ] ;
struct V_1 V_16 = { . V_6 = V_40 } ;
T_1 V_24 = V_26 -> V_24 ;
T_1 V_5 = 0 , V_49 , V_50 ;
int V_51 ;
if ( F_22 ( ! V_46 [ V_17 ] ||
! F_23 ( V_46 , V_23 ) ||
! F_23 ( V_46 , V_19 ) ) )
return - V_52 ;
if ( V_46 [ V_53 ] )
* V_47 = F_24 ( V_46 [ V_53 ] ) ;
V_51 = F_25 ( V_46 [ V_17 ] , & V_5 ) ;
if ( V_51 )
return V_51 ;
if ( V_46 [ V_18 ] ) {
V_16 . V_6 = F_26 ( V_46 [ V_18 ] ) ;
if ( ! V_16 . V_6 || V_16 . V_6 > V_40 )
return - V_54 ;
}
if ( V_46 [ V_23 ] ) {
if ( ! F_27 ( V_26 -> V_24 ) )
return - V_55 ;
V_24 = F_28 ( V_46 [ V_23 ] ) ;
}
if ( V_46 [ V_19 ] && V_34 == V_56 ) {
T_1 V_57 = F_29 ( V_46 [ V_19 ] ) ;
if ( V_57 & V_12 )
V_11 |= ( V_57 << 16 ) ;
}
if ( V_34 == V_42 || ! V_46 [ V_58 ] ) {
V_16 . V_5 = F_14 ( V_5 & F_30 ( V_16 . V_6 ) ) ;
V_51 = V_37 ( V_30 , & V_16 , V_24 , V_11 ) ;
return F_31 ( V_51 , V_11 ) ? 0 : V_51 ;
}
V_49 = V_5 ;
if ( V_46 [ V_58 ] ) {
V_51 = F_25 ( V_46 [ V_58 ] , & V_49 ) ;
if ( V_51 )
return V_51 ;
if ( V_49 < V_5 )
F_32 ( V_5 , V_49 ) ;
if ( V_5 + V_59 == V_49 )
return - V_60 ;
}
if ( V_48 )
V_5 = F_33 ( V_26 -> V_28 . V_5 ) ;
while ( ! F_34 ( V_5 , V_49 ) ) {
V_16 . V_5 = F_14 ( V_5 ) ;
V_50 = F_35 ( V_5 , V_49 , & V_16 . V_6 ) ;
V_51 = V_37 ( V_30 , & V_16 , V_24 , V_11 ) ;
if ( V_51 && ! F_31 ( V_51 , V_11 ) )
return V_51 ;
else
V_51 = 0 ;
V_5 = V_50 + 1 ;
}
return V_51 ;
}
static bool
F_36 ( const struct V_29 * V_61 , const struct V_29 * V_62 )
{
const struct V_25 * V_63 = V_61 -> V_16 ;
const struct V_25 * V_64 = V_62 -> V_16 ;
return V_63 -> V_65 == V_64 -> V_65 &&
V_63 -> V_24 == V_64 -> V_24 ;
}
static inline bool
F_37 ( const struct V_66 * V_2 ,
const struct V_66 * V_3 ,
T_1 * V_4 )
{
return F_38 ( & V_2 -> V_5 . V_67 , & V_3 -> V_5 . V_67 ) &&
V_2 -> V_6 == V_3 -> V_6 ;
}
static inline bool
F_39 ( const struct V_66 * V_7 )
{
return V_7 -> V_6 == 0 ;
}
static inline void
F_40 ( struct V_66 * V_8 ,
const struct V_66 * V_9 )
{
V_8 -> V_5 . V_67 = V_9 -> V_5 . V_67 ;
V_8 -> V_6 = V_9 -> V_6 ;
V_8 -> V_10 = V_9 -> V_10 ;
}
static inline void
F_41 ( struct V_66 * V_8 , T_1 V_11 )
{
V_8 -> V_10 = ! ! ( V_11 & V_12 ) ;
}
static inline void
F_42 ( struct V_66 * V_8 , T_1 * V_11 )
{
if ( V_8 -> V_10 ) {
* V_11 = V_12 ;
V_8 -> V_10 = 0 ;
}
}
static inline int
F_43 ( const struct V_66 * V_7 )
{
return V_7 -> V_10 ? - V_13 : 1 ;
}
static inline void
F_44 ( struct V_66 * V_7 )
{
V_7 -> V_6 = 0 ;
}
static inline void
F_45 ( union V_68 * V_5 , T_2 V_69 )
{
V_5 -> V_70 [ 0 ] &= F_46 ( V_69 ) [ 0 ] ;
V_5 -> V_70 [ 1 ] &= F_46 ( V_69 ) [ 1 ] ;
V_5 -> V_70 [ 2 ] &= F_46 ( V_69 ) [ 2 ] ;
V_5 -> V_70 [ 3 ] &= F_46 ( V_69 ) [ 3 ] ;
}
static inline void
F_47 ( struct V_66 * V_7 , T_2 V_6 )
{
F_45 ( & V_7 -> V_5 , V_6 ) ;
V_7 -> V_6 = V_6 ;
}
static bool
F_48 ( struct V_14 * V_15 , const struct V_66 * V_16 )
{
T_1 V_11 = V_16 -> V_10 ? V_12 : 0 ;
if ( F_49 ( V_15 , V_17 , & V_16 -> V_5 . V_67 ) ||
F_12 ( V_15 , V_18 , V_16 -> V_6 ) ||
( V_11 &&
F_13 ( V_15 , V_19 , F_14 ( V_11 ) ) ) )
goto V_20;
return 0 ;
V_20:
return 1 ;
}
static bool
F_50 ( struct V_14 * V_15 , const struct V_66 * V_16 )
{
const struct V_71 * V_72 =
( const struct V_71 * ) V_16 ;
T_1 V_11 = V_16 -> V_10 ? V_12 : 0 ;
if ( F_49 ( V_15 , V_17 , & V_72 -> V_5 . V_67 ) ||
F_12 ( V_15 , V_18 , V_72 -> V_6 ) ||
F_13 ( V_15 , V_23 ,
F_14 ( F_16 ( V_72 -> V_24 ) ) ) ||
( V_11 &&
F_13 ( V_15 , V_19 , F_14 ( V_11 ) ) ) )
goto V_20;
return 0 ;
V_20:
return 1 ;
}
static inline void
F_51 ( struct V_25 * V_26 ,
const struct V_66 * V_27 )
{
}
static int
F_52 ( struct V_29 * V_30 , const struct V_14 * V_15 ,
const struct V_31 * V_32 ,
enum V_33 V_34 , const struct V_35 * V_36 )
{
const struct V_25 * V_26 = V_30 -> V_16 ;
T_3 V_37 = V_30 -> V_38 -> V_34 [ V_34 ] ;
struct V_66 V_16 = {
. V_6 = V_26 -> V_39 [ 0 ] . V_6 ? V_26 -> V_39 [ 0 ] . V_6 : V_40
} ;
if ( V_16 . V_6 == 0 )
return - V_41 ;
if ( V_34 == V_42 )
V_16 . V_6 = V_40 ;
F_53 ( V_15 , V_36 -> V_11 & V_43 , & V_16 . V_5 . V_67 ) ;
F_45 ( & V_16 . V_5 , V_16 . V_6 ) ;
return V_37 ( V_30 , & V_16 , F_20 ( V_36 , V_26 ) , V_36 -> V_44 ) ;
}
static int
F_54 ( struct V_29 * V_30 , struct V_45 * V_46 [] ,
enum V_33 V_34 , T_1 * V_47 , T_1 V_11 , bool V_48 )
{
const struct V_25 * V_26 = V_30 -> V_16 ;
T_3 V_37 = V_30 -> V_38 -> V_34 [ V_34 ] ;
struct V_66 V_16 = { . V_6 = V_40 } ;
T_1 V_24 = V_26 -> V_24 ;
int V_51 ;
if ( F_22 ( ! V_46 [ V_17 ] ||
! F_23 ( V_46 , V_23 ) ||
! F_23 ( V_46 , V_19 ) ) )
return - V_52 ;
if ( F_22 ( V_46 [ V_58 ] ) )
return - V_73 ;
if ( V_46 [ V_53 ] )
* V_47 = F_24 ( V_46 [ V_53 ] ) ;
V_51 = F_55 ( V_46 [ V_17 ] , & V_16 . V_5 ) ;
if ( V_51 )
return V_51 ;
if ( V_46 [ V_18 ] )
V_16 . V_6 = F_26 ( V_46 [ V_18 ] ) ;
if ( ! V_16 . V_6 || V_16 . V_6 > V_40 )
return - V_54 ;
F_45 ( & V_16 . V_5 , V_16 . V_6 ) ;
if ( V_46 [ V_23 ] ) {
if ( ! F_27 ( V_26 -> V_24 ) )
return - V_55 ;
V_24 = F_28 ( V_46 [ V_23 ] ) ;
}
if ( V_46 [ V_19 ] && V_34 == V_56 ) {
T_1 V_57 = F_29 ( V_46 [ V_19 ] ) ;
if ( V_57 & V_12 )
V_11 |= ( V_57 << 16 ) ;
}
V_51 = V_37 ( V_30 , & V_16 , V_24 , V_11 ) ;
return F_31 ( V_51 , V_11 ) ? 0 : V_51 ;
}
static int
F_56 ( struct V_29 * V_30 , struct V_45 * V_46 [] , T_1 V_11 )
{
T_1 V_74 = V_75 , V_65 = V_76 ;
struct V_25 * V_26 ;
T_2 V_77 ;
T_4 V_78 ;
if ( ! ( V_30 -> V_79 == V_80 || V_30 -> V_79 == V_81 ) )
return - V_82 ;
if ( F_22 ( ! F_23 ( V_46 , V_83 ) ||
! F_23 ( V_46 , V_84 ) ||
! F_23 ( V_46 , V_23 ) ) )
return - V_52 ;
if ( V_46 [ V_83 ] ) {
V_74 = F_29 ( V_46 [ V_83 ] ) ;
if ( V_74 < V_85 )
V_74 = V_85 ;
}
if ( V_46 [ V_84 ] )
V_65 = F_29 ( V_46 [ V_84 ] ) ;
V_26 = F_57 ( sizeof( * V_26 )
+ sizeof( struct V_86 )
* ( V_30 -> V_79 == V_80 ? 32 : 128 ) , V_87 ) ;
if ( ! V_26 )
return - V_88 ;
V_26 -> V_65 = V_65 ;
F_58 ( & V_26 -> V_89 , sizeof( V_26 -> V_89 ) ) ;
V_26 -> V_24 = V_90 ;
V_77 = F_59 ( V_74 ) ;
V_78 = F_60 ( V_77 ) ;
if ( V_78 == 0 ) {
F_61 ( V_26 ) ;
return - V_88 ;
}
V_26 -> V_91 = F_62 ( V_78 ) ;
if ( ! V_26 -> V_91 ) {
F_61 ( V_26 ) ;
return - V_88 ;
}
V_26 -> V_91 -> F_59 = V_77 ;
V_30 -> V_16 = V_26 ;
if ( V_46 [ V_23 ] ) {
V_26 -> V_24 = F_28 ( V_46 [ V_23 ] ) ;
V_30 -> V_38 = V_30 -> V_79 == V_80
? & V_92 : & V_93 ;
if ( V_30 -> V_79 == V_80 )
F_63 ( V_30 ) ;
else
F_64 ( V_30 ) ;
} else {
V_30 -> V_38 = V_30 -> V_79 == V_80
? & V_94 : & V_95 ;
}
F_65 ( L_1 ,
V_30 -> V_96 , F_66 ( V_26 -> V_91 -> F_59 ) ,
V_26 -> V_91 -> F_59 , V_26 -> V_65 , V_30 -> V_16 , V_26 -> V_91 ) ;
return 0 ;
}
static int T_5
F_67 ( void )
{
return F_68 ( & V_97 ) ;
}
static void T_6
F_69 ( void )
{
F_70 ( & V_97 ) ;
}
