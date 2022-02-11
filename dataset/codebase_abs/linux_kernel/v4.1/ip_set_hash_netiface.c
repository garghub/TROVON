static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
F_2 (node, next, root, node)
F_3 ( V_4 ) ;
* V_2 = V_6 ;
}
static int
F_4 ( struct V_1 * V_2 , const char * * V_7 )
{
struct V_8 * V_9 = V_2 -> V_8 ;
while ( V_9 ) {
const char * V_10 = F_5 ( V_9 ) ;
int V_11 = strcmp ( * V_7 , V_10 ) ;
if ( V_11 < 0 )
V_9 = V_9 -> V_12 ;
else if ( V_11 > 0 )
V_9 = V_9 -> V_13 ;
else {
* V_7 = V_10 ;
return 1 ;
}
}
return 0 ;
}
static int
F_6 ( struct V_1 * V_2 , const char * * V_7 )
{
struct V_8 * * V_9 = & ( V_2 -> V_8 ) , * V_14 = NULL ;
struct V_3 * V_10 ;
while ( * V_9 ) {
char * V_15 = F_5 ( * V_9 ) ;
int V_11 = strcmp ( * V_7 , V_15 ) ;
V_14 = * V_9 ;
if ( V_11 < 0 )
V_9 = & ( ( * V_9 ) -> V_12 ) ;
else if ( V_11 > 0 )
V_9 = & ( ( * V_9 ) -> V_13 ) ;
else {
* V_7 = V_15 ;
return 0 ;
}
}
V_10 = F_7 ( sizeof( * V_10 ) , V_16 ) ;
if ( ! V_10 )
return - V_17 ;
strcpy ( V_10 -> V_7 , * V_7 ) ;
F_8 ( & V_10 -> V_4 , V_14 , V_9 ) ;
F_9 ( & V_10 -> V_4 , V_2 ) ;
* V_7 = V_10 -> V_7 ;
return 0 ;
}
static inline bool
F_10 ( const struct V_18 * V_19 ,
const struct V_18 * V_20 ,
T_1 * V_21 )
{
return V_19 -> V_22 == V_20 -> V_22 &&
V_19 -> V_23 == V_20 -> V_23 &&
( ++ * V_21 ) &&
V_19 -> V_24 == V_20 -> V_24 &&
V_19 -> V_7 == V_20 -> V_7 ;
}
static inline int
F_11 ( const struct V_18 * V_25 )
{
return V_25 -> V_26 ? - V_27 : 1 ;
}
static inline void
F_12 ( struct V_18 * V_25 , T_1 V_28 )
{
V_25 -> V_26 = ( V_28 >> 16 ) & V_29 ;
}
static inline void
F_13 ( struct V_18 * V_25 , T_2 * V_28 )
{
F_14 ( * V_28 , V_25 -> V_26 ) ;
}
static inline void
F_15 ( struct V_18 * V_25 , T_2 V_23 )
{
V_25 -> V_22 &= F_16 ( V_23 ) ;
V_25 -> V_23 = V_23 ;
}
static bool
F_17 ( struct V_30 * V_31 ,
const struct V_18 * V_32 )
{
T_1 V_28 = V_32 -> V_24 ? V_33 : 0 ;
if ( V_32 -> V_26 )
V_28 |= V_29 ;
if ( F_18 ( V_31 , V_34 , V_32 -> V_22 ) ||
F_19 ( V_31 , V_35 , V_32 -> V_23 ) ||
F_20 ( V_31 , V_36 , V_32 -> V_7 ) ||
( V_28 &&
F_21 ( V_31 , V_37 , F_22 ( V_28 ) ) ) )
goto V_38;
return 0 ;
V_38:
return 1 ;
}
static inline void
F_23 ( struct V_18 * V_5 ,
const struct V_18 * V_10 )
{
V_5 -> V_22 = V_10 -> V_22 ;
}
static const char * F_24 ( const struct V_30 * V_31 )
{
struct V_39 * V_40 = F_25 ( V_31 ) ;
return V_40 ? V_40 -> V_41 : NULL ;
}
static const char * F_26 ( const struct V_30 * V_31 )
{
struct V_39 * V_40 = F_27 ( V_31 ) ;
return V_40 ? V_40 -> V_41 : NULL ;
}
static int
F_28 ( struct V_42 * V_43 , const struct V_30 * V_31 ,
const struct V_44 * V_45 ,
enum V_46 V_47 , struct V_48 * V_49 )
{
struct V_50 * V_51 = V_43 -> V_32 ;
T_3 V_52 = V_43 -> V_53 -> V_47 [ V_47 ] ;
struct V_18 V_54 = {
. V_23 = F_29 ( V_51 -> V_55 [ 0 ] . V_23 [ 0 ] , V_56 ) ,
. V_25 = 1 ,
} ;
struct V_57 V_58 = F_30 ( V_31 , V_49 , V_43 ) ;
int V_59 ;
if ( V_54 . V_23 == 0 )
return - V_60 ;
if ( V_47 == V_61 )
V_54 . V_23 = V_56 ;
F_31 ( V_31 , V_49 -> V_28 & V_62 , & V_54 . V_22 ) ;
V_54 . V_22 &= F_16 ( V_54 . V_23 ) ;
#define F_32 ( T_4 ) (par->dir ? par->dir->name : NULL)
#define F_33 (opt->flags & IPSET_DIM_TWO_SRC)
if ( V_49 -> V_63 & V_33 ) {
#if F_34 ( V_64 )
V_54 . V_7 = F_33 ? F_24 ( V_31 ) :
F_26 ( V_31 ) ;
if ( ! V_54 . V_7 )
return - V_60 ;
V_54 . V_24 = 1 ;
#else
V_54 . V_7 = NULL ;
#endif
} else
V_54 . V_7 = F_33 ? F_32 ( V_65 ) : F_32 ( V_66 ) ;
if ( ! V_54 . V_7 )
return - V_60 ;
V_59 = F_4 ( & V_51 -> V_67 , & V_54 . V_7 ) ;
if ( V_47 == V_68 ) {
if ( ! V_59 ) {
V_59 = F_6 ( & V_51 -> V_67 , & V_54 . V_7 ) ;
if ( V_59 )
return V_59 ;
}
} else if ( ! V_59 )
return V_59 ;
return V_52 ( V_43 , & V_54 , & V_58 , & V_49 -> V_58 , V_49 -> V_63 ) ;
}
static int
F_35 ( struct V_42 * V_43 , struct V_69 * V_70 [] ,
enum V_46 V_47 , T_1 * V_71 , T_1 V_28 , bool V_72 )
{
struct V_50 * V_51 = V_43 -> V_32 ;
T_3 V_52 = V_43 -> V_53 -> V_47 [ V_47 ] ;
struct V_18 V_54 = { . V_23 = V_56 , . V_25 = 1 } ;
struct V_57 V_58 = F_36 ( V_43 ) ;
T_1 V_22 = 0 , V_73 = 0 , V_74 ;
char V_7 [ V_75 ] ;
int V_59 ;
if ( F_37 ( ! V_70 [ V_34 ] ||
! V_70 [ V_36 ] ||
! F_38 ( V_70 , V_76 ) ||
! F_38 ( V_70 , V_37 ) ||
! F_38 ( V_70 , V_77 ) ||
! F_38 ( V_70 , V_78 ) ||
! F_38 ( V_70 , V_79 ) ||
! F_38 ( V_70 , V_80 ) ||
! F_38 ( V_70 , V_81 ) ) )
return - V_82 ;
if ( V_70 [ V_83 ] )
* V_71 = F_39 ( V_70 [ V_83 ] ) ;
V_59 = F_40 ( V_70 [ V_34 ] , & V_22 ) ||
F_41 ( V_43 , V_70 , & V_58 ) ;
if ( V_59 )
return V_59 ;
if ( V_70 [ V_35 ] ) {
V_54 . V_23 = F_42 ( V_70 [ V_35 ] ) ;
if ( V_54 . V_23 > V_56 )
return - V_84 ;
}
strcpy ( V_7 , F_43 ( V_70 [ V_36 ] ) ) ;
V_54 . V_7 = V_7 ;
V_59 = F_4 ( & V_51 -> V_67 , & V_54 . V_7 ) ;
if ( V_47 == V_68 ) {
if ( ! V_59 ) {
V_59 = F_6 ( & V_51 -> V_67 , & V_54 . V_7 ) ;
if ( V_59 )
return V_59 ;
}
} else if ( ! V_59 )
return V_59 ;
if ( V_70 [ V_37 ] ) {
T_1 V_85 = F_44 ( V_70 [ V_37 ] ) ;
if ( V_85 & V_33 )
V_54 . V_24 = 1 ;
if ( V_85 & V_29 )
V_28 |= ( V_29 << 16 ) ;
}
if ( V_47 == V_61 || ! V_70 [ V_86 ] ) {
V_54 . V_22 = F_22 ( V_22 & F_45 ( V_54 . V_23 ) ) ;
V_59 = V_52 ( V_43 , & V_54 , & V_58 , & V_58 , V_28 ) ;
return F_46 ( V_59 , V_28 , V_47 , V_43 ) ? - V_59 :
F_47 ( V_59 , V_28 ) ? 0 : V_59 ;
}
if ( V_70 [ V_86 ] ) {
V_59 = F_40 ( V_70 [ V_86 ] , & V_73 ) ;
if ( V_59 )
return V_59 ;
if ( V_73 < V_22 )
F_14 ( V_22 , V_73 ) ;
if ( V_22 + V_87 == V_73 )
return - V_88 ;
} else
F_48 ( V_22 , V_73 , V_54 . V_23 ) ;
if ( V_72 )
V_22 = F_49 ( V_51 -> V_5 . V_22 ) ;
while ( ! F_50 ( V_22 , V_73 ) ) {
V_54 . V_22 = F_22 ( V_22 ) ;
V_74 = F_51 ( V_22 , V_73 , & V_54 . V_23 ) ;
V_59 = V_52 ( V_43 , & V_54 , & V_58 , & V_58 , V_28 ) ;
if ( V_59 && ! F_47 ( V_59 , V_28 ) )
return V_59 ;
else
V_59 = 0 ;
V_22 = V_74 + 1 ;
}
return V_59 ;
}
static inline bool
F_52 ( const struct V_89 * V_19 ,
const struct V_89 * V_20 ,
T_1 * V_21 )
{
return F_53 ( & V_19 -> V_22 . V_90 , & V_20 -> V_22 . V_90 ) &&
V_19 -> V_23 == V_20 -> V_23 &&
( ++ * V_21 ) &&
V_19 -> V_24 == V_20 -> V_24 &&
V_19 -> V_7 == V_20 -> V_7 ;
}
static inline int
F_54 ( const struct V_89 * V_25 )
{
return V_25 -> V_26 ? - V_27 : 1 ;
}
static inline void
F_55 ( struct V_89 * V_25 , T_1 V_28 )
{
V_25 -> V_26 = ( V_28 >> 16 ) & V_29 ;
}
static inline void
F_56 ( struct V_89 * V_25 , T_2 * V_28 )
{
F_14 ( * V_28 , V_25 -> V_26 ) ;
}
static inline void
F_57 ( struct V_89 * V_25 , T_2 V_23 )
{
F_58 ( & V_25 -> V_22 , V_23 ) ;
V_25 -> V_23 = V_23 ;
}
static bool
F_59 ( struct V_30 * V_31 ,
const struct V_89 * V_32 )
{
T_1 V_28 = V_32 -> V_24 ? V_33 : 0 ;
if ( V_32 -> V_26 )
V_28 |= V_29 ;
if ( F_60 ( V_31 , V_34 , & V_32 -> V_22 . V_90 ) ||
F_19 ( V_31 , V_35 , V_32 -> V_23 ) ||
F_20 ( V_31 , V_36 , V_32 -> V_7 ) ||
( V_28 &&
F_21 ( V_31 , V_37 , F_22 ( V_28 ) ) ) )
goto V_38;
return 0 ;
V_38:
return 1 ;
}
static inline void
F_61 ( struct V_18 * V_5 ,
const struct V_89 * V_10 )
{
}
static int
F_62 ( struct V_42 * V_43 , const struct V_30 * V_31 ,
const struct V_44 * V_45 ,
enum V_46 V_47 , struct V_48 * V_49 )
{
struct V_50 * V_51 = V_43 -> V_32 ;
T_3 V_52 = V_43 -> V_53 -> V_47 [ V_47 ] ;
struct V_89 V_54 = {
. V_23 = F_29 ( V_51 -> V_55 [ 0 ] . V_23 [ 0 ] , V_56 ) ,
. V_25 = 1 ,
} ;
struct V_57 V_58 = F_30 ( V_31 , V_49 , V_43 ) ;
int V_59 ;
if ( V_54 . V_23 == 0 )
return - V_60 ;
if ( V_47 == V_61 )
V_54 . V_23 = V_56 ;
F_63 ( V_31 , V_49 -> V_28 & V_62 , & V_54 . V_22 . V_90 ) ;
F_58 ( & V_54 . V_22 , V_54 . V_23 ) ;
if ( V_49 -> V_63 & V_33 ) {
#if F_34 ( V_64 )
V_54 . V_7 = F_33 ? F_24 ( V_31 ) :
F_26 ( V_31 ) ;
if ( ! V_54 . V_7 )
return - V_60 ;
V_54 . V_24 = 1 ;
#else
V_54 . V_7 = NULL ;
#endif
} else
V_54 . V_7 = F_33 ? F_32 ( V_65 ) : F_32 ( V_66 ) ;
if ( ! V_54 . V_7 )
return - V_60 ;
V_59 = F_4 ( & V_51 -> V_67 , & V_54 . V_7 ) ;
if ( V_47 == V_68 ) {
if ( ! V_59 ) {
V_59 = F_6 ( & V_51 -> V_67 , & V_54 . V_7 ) ;
if ( V_59 )
return V_59 ;
}
} else if ( ! V_59 )
return V_59 ;
return V_52 ( V_43 , & V_54 , & V_58 , & V_49 -> V_58 , V_49 -> V_63 ) ;
}
static int
F_64 ( struct V_42 * V_43 , struct V_69 * V_70 [] ,
enum V_46 V_47 , T_1 * V_71 , T_1 V_28 , bool V_72 )
{
struct V_50 * V_51 = V_43 -> V_32 ;
T_3 V_52 = V_43 -> V_53 -> V_47 [ V_47 ] ;
struct V_89 V_54 = { . V_23 = V_56 , . V_25 = 1 } ;
struct V_57 V_58 = F_36 ( V_43 ) ;
char V_7 [ V_75 ] ;
int V_59 ;
if ( F_37 ( ! V_70 [ V_34 ] ||
! V_70 [ V_36 ] ||
! F_38 ( V_70 , V_76 ) ||
! F_38 ( V_70 , V_37 ) ||
! F_38 ( V_70 , V_77 ) ||
! F_38 ( V_70 , V_78 ) ||
! F_38 ( V_70 , V_79 ) ||
! F_38 ( V_70 , V_80 ) ||
! F_38 ( V_70 , V_81 ) ) )
return - V_82 ;
if ( F_37 ( V_70 [ V_86 ] ) )
return - V_91 ;
if ( V_70 [ V_83 ] )
* V_71 = F_39 ( V_70 [ V_83 ] ) ;
V_59 = F_65 ( V_70 [ V_34 ] , & V_54 . V_22 ) ||
F_41 ( V_43 , V_70 , & V_58 ) ;
if ( V_59 )
return V_59 ;
if ( V_70 [ V_35 ] )
V_54 . V_23 = F_42 ( V_70 [ V_35 ] ) ;
if ( V_54 . V_23 > V_56 )
return - V_84 ;
F_58 ( & V_54 . V_22 , V_54 . V_23 ) ;
strcpy ( V_7 , F_43 ( V_70 [ V_36 ] ) ) ;
V_54 . V_7 = V_7 ;
V_59 = F_4 ( & V_51 -> V_67 , & V_54 . V_7 ) ;
if ( V_47 == V_68 ) {
if ( ! V_59 ) {
V_59 = F_6 ( & V_51 -> V_67 , & V_54 . V_7 ) ;
if ( V_59 )
return V_59 ;
}
} else if ( ! V_59 )
return V_59 ;
if ( V_70 [ V_37 ] ) {
T_1 V_85 = F_44 ( V_70 [ V_37 ] ) ;
if ( V_85 & V_33 )
V_54 . V_24 = 1 ;
if ( V_85 & V_29 )
V_28 |= ( V_29 << 16 ) ;
}
V_59 = V_52 ( V_43 , & V_54 , & V_58 , & V_58 , V_28 ) ;
return F_46 ( V_59 , V_28 , V_47 , V_43 ) ? - V_59 :
F_47 ( V_59 , V_28 ) ? 0 : V_59 ;
}
static int T_5
F_66 ( void )
{
return F_67 ( & V_92 ) ;
}
static void T_6
F_68 ( void )
{
F_69 ( & V_92 ) ;
}
