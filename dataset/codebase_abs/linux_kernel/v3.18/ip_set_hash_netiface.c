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
static int
F_24 ( struct V_39 * V_40 , const struct V_30 * V_31 ,
const struct V_41 * V_42 ,
enum V_43 V_44 , struct V_45 * V_46 )
{
struct V_47 * V_48 = V_40 -> V_32 ;
T_3 V_49 = V_40 -> V_50 -> V_44 [ V_44 ] ;
struct V_18 V_51 = {
. V_23 = F_25 ( V_48 -> V_52 [ 0 ] . V_23 [ 0 ] , V_53 ) ,
. V_25 = 1 ,
} ;
struct V_54 V_55 = F_26 ( V_31 , V_46 , V_40 ) ;
int V_56 ;
if ( V_51 . V_23 == 0 )
return - V_57 ;
if ( V_44 == V_58 )
V_51 . V_23 = V_53 ;
F_27 ( V_31 , V_46 -> V_28 & V_59 , & V_51 . V_22 ) ;
V_51 . V_22 &= F_16 ( V_51 . V_23 ) ;
#define F_28 ( T_4 ) (par->dir ? par->dir->name : NULL)
#define F_29 ( T_4 ) (nf_bridge->dir ? nf_bridge->dir->name : NULL)
#define F_30 (opt->flags & IPSET_DIM_TWO_SRC)
if ( V_46 -> V_60 & V_33 ) {
#if F_31 ( V_61 )
const struct V_62 * V_63 = V_31 -> V_63 ;
if ( ! V_63 )
return - V_57 ;
V_51 . V_7 = F_30 ? F_29 ( V_64 ) : F_29 ( V_65 ) ;
V_51 . V_24 = 1 ;
#else
V_51 . V_7 = NULL ;
#endif
} else
V_51 . V_7 = F_30 ? F_28 ( V_66 ) : F_28 ( V_67 ) ;
if ( ! V_51 . V_7 )
return - V_57 ;
V_56 = F_4 ( & V_48 -> V_68 , & V_51 . V_7 ) ;
if ( V_44 == V_69 ) {
if ( ! V_56 ) {
V_56 = F_6 ( & V_48 -> V_68 , & V_51 . V_7 ) ;
if ( V_56 )
return V_56 ;
}
} else if ( ! V_56 )
return V_56 ;
return V_49 ( V_40 , & V_51 , & V_55 , & V_46 -> V_55 , V_46 -> V_60 ) ;
}
static int
F_32 ( struct V_39 * V_40 , struct V_70 * V_71 [] ,
enum V_43 V_44 , T_1 * V_72 , T_1 V_28 , bool V_73 )
{
struct V_47 * V_48 = V_40 -> V_32 ;
T_3 V_49 = V_40 -> V_50 -> V_44 [ V_44 ] ;
struct V_18 V_51 = { . V_23 = V_53 , . V_25 = 1 } ;
struct V_54 V_55 = F_33 ( V_40 ) ;
T_1 V_22 = 0 , V_74 = 0 , V_75 ;
char V_7 [ V_76 ] ;
int V_56 ;
if ( F_34 ( ! V_71 [ V_34 ] ||
! V_71 [ V_36 ] ||
! F_35 ( V_71 , V_77 ) ||
! F_35 ( V_71 , V_37 ) ||
! F_35 ( V_71 , V_78 ) ||
! F_35 ( V_71 , V_79 ) ||
! F_35 ( V_71 , V_80 ) ||
! F_35 ( V_71 , V_81 ) ||
! F_35 ( V_71 , V_82 ) ) )
return - V_83 ;
if ( V_71 [ V_84 ] )
* V_72 = F_36 ( V_71 [ V_84 ] ) ;
V_56 = F_37 ( V_71 [ V_34 ] , & V_22 ) ||
F_38 ( V_40 , V_71 , & V_55 ) ;
if ( V_56 )
return V_56 ;
if ( V_71 [ V_35 ] ) {
V_51 . V_23 = F_39 ( V_71 [ V_35 ] ) ;
if ( V_51 . V_23 > V_53 )
return - V_85 ;
}
strcpy ( V_7 , F_40 ( V_71 [ V_36 ] ) ) ;
V_51 . V_7 = V_7 ;
V_56 = F_4 ( & V_48 -> V_68 , & V_51 . V_7 ) ;
if ( V_44 == V_69 ) {
if ( ! V_56 ) {
V_56 = F_6 ( & V_48 -> V_68 , & V_51 . V_7 ) ;
if ( V_56 )
return V_56 ;
}
} else if ( ! V_56 )
return V_56 ;
if ( V_71 [ V_37 ] ) {
T_1 V_86 = F_41 ( V_71 [ V_37 ] ) ;
if ( V_86 & V_33 )
V_51 . V_24 = 1 ;
if ( V_86 & V_29 )
V_28 |= ( V_29 << 16 ) ;
}
if ( V_44 == V_58 || ! V_71 [ V_87 ] ) {
V_51 . V_22 = F_22 ( V_22 & F_42 ( V_51 . V_23 ) ) ;
V_56 = V_49 ( V_40 , & V_51 , & V_55 , & V_55 , V_28 ) ;
return F_43 ( V_56 , V_28 , V_44 , V_40 ) ? - V_56 :
F_44 ( V_56 , V_28 ) ? 0 : V_56 ;
}
if ( V_71 [ V_87 ] ) {
V_56 = F_37 ( V_71 [ V_87 ] , & V_74 ) ;
if ( V_56 )
return V_56 ;
if ( V_74 < V_22 )
F_14 ( V_22 , V_74 ) ;
if ( V_22 + V_88 == V_74 )
return - V_89 ;
} else
F_45 ( V_22 , V_74 , V_51 . V_23 ) ;
if ( V_73 )
V_22 = F_46 ( V_48 -> V_5 . V_22 ) ;
while ( ! F_47 ( V_22 , V_74 ) ) {
V_51 . V_22 = F_22 ( V_22 ) ;
V_75 = F_48 ( V_22 , V_74 , & V_51 . V_23 ) ;
V_56 = V_49 ( V_40 , & V_51 , & V_55 , & V_55 , V_28 ) ;
if ( V_56 && ! F_44 ( V_56 , V_28 ) )
return V_56 ;
else
V_56 = 0 ;
V_22 = V_75 + 1 ;
}
return V_56 ;
}
static inline bool
F_49 ( const struct V_90 * V_19 ,
const struct V_90 * V_20 ,
T_1 * V_21 )
{
return F_50 ( & V_19 -> V_22 . V_91 , & V_20 -> V_22 . V_91 ) &&
V_19 -> V_23 == V_20 -> V_23 &&
( ++ * V_21 ) &&
V_19 -> V_24 == V_20 -> V_24 &&
V_19 -> V_7 == V_20 -> V_7 ;
}
static inline int
F_51 ( const struct V_90 * V_25 )
{
return V_25 -> V_26 ? - V_27 : 1 ;
}
static inline void
F_52 ( struct V_90 * V_25 , T_1 V_28 )
{
V_25 -> V_26 = ( V_28 >> 16 ) & V_29 ;
}
static inline void
F_53 ( struct V_90 * V_25 , T_2 * V_28 )
{
F_14 ( * V_28 , V_25 -> V_26 ) ;
}
static inline void
F_54 ( struct V_90 * V_25 , T_2 V_23 )
{
F_55 ( & V_25 -> V_22 , V_23 ) ;
V_25 -> V_23 = V_23 ;
}
static bool
F_56 ( struct V_30 * V_31 ,
const struct V_90 * V_32 )
{
T_1 V_28 = V_32 -> V_24 ? V_33 : 0 ;
if ( V_32 -> V_26 )
V_28 |= V_29 ;
if ( F_57 ( V_31 , V_34 , & V_32 -> V_22 . V_91 ) ||
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
F_58 ( struct V_18 * V_5 ,
const struct V_90 * V_10 )
{
}
static int
F_59 ( struct V_39 * V_40 , const struct V_30 * V_31 ,
const struct V_41 * V_42 ,
enum V_43 V_44 , struct V_45 * V_46 )
{
struct V_47 * V_48 = V_40 -> V_32 ;
T_3 V_49 = V_40 -> V_50 -> V_44 [ V_44 ] ;
struct V_90 V_51 = {
. V_23 = F_25 ( V_48 -> V_52 [ 0 ] . V_23 [ 0 ] , V_53 ) ,
. V_25 = 1 ,
} ;
struct V_54 V_55 = F_26 ( V_31 , V_46 , V_40 ) ;
int V_56 ;
if ( V_51 . V_23 == 0 )
return - V_57 ;
if ( V_44 == V_58 )
V_51 . V_23 = V_53 ;
F_60 ( V_31 , V_46 -> V_28 & V_59 , & V_51 . V_22 . V_91 ) ;
F_55 ( & V_51 . V_22 , V_51 . V_23 ) ;
if ( V_46 -> V_60 & V_33 ) {
#if F_31 ( V_61 )
const struct V_62 * V_63 = V_31 -> V_63 ;
if ( ! V_63 )
return - V_57 ;
V_51 . V_7 = F_30 ? F_29 ( V_64 ) : F_29 ( V_65 ) ;
V_51 . V_24 = 1 ;
#else
V_51 . V_7 = NULL ;
#endif
} else
V_51 . V_7 = F_30 ? F_28 ( V_66 ) : F_28 ( V_67 ) ;
if ( ! V_51 . V_7 )
return - V_57 ;
V_56 = F_4 ( & V_48 -> V_68 , & V_51 . V_7 ) ;
if ( V_44 == V_69 ) {
if ( ! V_56 ) {
V_56 = F_6 ( & V_48 -> V_68 , & V_51 . V_7 ) ;
if ( V_56 )
return V_56 ;
}
} else if ( ! V_56 )
return V_56 ;
return V_49 ( V_40 , & V_51 , & V_55 , & V_46 -> V_55 , V_46 -> V_60 ) ;
}
static int
F_61 ( struct V_39 * V_40 , struct V_70 * V_71 [] ,
enum V_43 V_44 , T_1 * V_72 , T_1 V_28 , bool V_73 )
{
struct V_47 * V_48 = V_40 -> V_32 ;
T_3 V_49 = V_40 -> V_50 -> V_44 [ V_44 ] ;
struct V_90 V_51 = { . V_23 = V_53 , . V_25 = 1 } ;
struct V_54 V_55 = F_33 ( V_40 ) ;
char V_7 [ V_76 ] ;
int V_56 ;
if ( F_34 ( ! V_71 [ V_34 ] ||
! V_71 [ V_36 ] ||
! F_35 ( V_71 , V_77 ) ||
! F_35 ( V_71 , V_37 ) ||
! F_35 ( V_71 , V_78 ) ||
! F_35 ( V_71 , V_79 ) ||
! F_35 ( V_71 , V_80 ) ||
! F_35 ( V_71 , V_81 ) ||
! F_35 ( V_71 , V_82 ) ) )
return - V_83 ;
if ( F_34 ( V_71 [ V_87 ] ) )
return - V_92 ;
if ( V_71 [ V_84 ] )
* V_72 = F_36 ( V_71 [ V_84 ] ) ;
V_56 = F_62 ( V_71 [ V_34 ] , & V_51 . V_22 ) ||
F_38 ( V_40 , V_71 , & V_55 ) ;
if ( V_56 )
return V_56 ;
if ( V_71 [ V_35 ] )
V_51 . V_23 = F_39 ( V_71 [ V_35 ] ) ;
if ( V_51 . V_23 > V_53 )
return - V_85 ;
F_55 ( & V_51 . V_22 , V_51 . V_23 ) ;
strcpy ( V_7 , F_40 ( V_71 [ V_36 ] ) ) ;
V_51 . V_7 = V_7 ;
V_56 = F_4 ( & V_48 -> V_68 , & V_51 . V_7 ) ;
if ( V_44 == V_69 ) {
if ( ! V_56 ) {
V_56 = F_6 ( & V_48 -> V_68 , & V_51 . V_7 ) ;
if ( V_56 )
return V_56 ;
}
} else if ( ! V_56 )
return V_56 ;
if ( V_71 [ V_37 ] ) {
T_1 V_86 = F_41 ( V_71 [ V_37 ] ) ;
if ( V_86 & V_33 )
V_51 . V_24 = 1 ;
if ( V_86 & V_29 )
V_28 |= ( V_29 << 16 ) ;
}
V_56 = V_49 ( V_40 , & V_51 , & V_55 , & V_55 , V_28 ) ;
return F_43 ( V_56 , V_28 , V_44 , V_40 ) ? - V_56 :
F_44 ( V_56 , V_28 ) ? 0 : V_56 ;
}
static int T_5
F_63 ( void )
{
return F_64 ( & V_93 ) ;
}
static void T_6
F_65 ( void )
{
F_66 ( & V_93 ) ;
}
