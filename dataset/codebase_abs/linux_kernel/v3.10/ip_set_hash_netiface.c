static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 = V_2 -> V_3 ;
struct V_6 * V_7 ;
while ( V_5 ) {
if ( V_5 -> V_8 ) {
V_5 = V_5 -> V_8 ;
continue;
}
if ( V_5 -> V_9 ) {
V_5 = V_5 -> V_9 ;
continue;
}
V_4 = F_2 ( V_5 ) ;
V_7 = F_3 ( V_5 , struct V_6 , V_7 ) ;
if ( ! V_4 )
* V_2 = V_10 ;
else if ( V_4 -> V_8 == V_5 )
V_4 -> V_8 = NULL ;
else if ( V_4 -> V_9 == V_5 )
V_4 -> V_9 = NULL ;
F_4 ( V_7 ) ;
V_5 = V_4 ;
}
}
static int
F_5 ( struct V_1 * V_2 , const char * * V_11 )
{
struct V_3 * V_5 = V_2 -> V_3 ;
while ( V_5 ) {
const char * V_12 = F_6 ( V_5 ) ;
int V_13 = strcmp ( * V_11 , V_12 ) ;
if ( V_13 < 0 )
V_5 = V_5 -> V_8 ;
else if ( V_13 > 0 )
V_5 = V_5 -> V_9 ;
else {
* V_11 = V_12 ;
return 1 ;
}
}
return 0 ;
}
static int
F_7 ( struct V_1 * V_2 , const char * * V_11 )
{
struct V_3 * * V_5 = & ( V_2 -> V_3 ) , * V_4 = NULL ;
struct V_6 * V_12 ;
while ( * V_5 ) {
char * V_14 = F_6 ( * V_5 ) ;
int V_13 = strcmp ( * V_11 , V_14 ) ;
V_4 = * V_5 ;
if ( V_13 < 0 )
V_5 = & ( ( * V_5 ) -> V_8 ) ;
else if ( V_13 > 0 )
V_5 = & ( ( * V_5 ) -> V_9 ) ;
else {
* V_11 = V_14 ;
return 0 ;
}
}
V_12 = F_8 ( sizeof( * V_12 ) , V_15 ) ;
if ( ! V_12 )
return - V_16 ;
strcpy ( V_12 -> V_11 , * V_11 ) ;
F_9 ( & V_12 -> V_7 , V_4 , V_5 ) ;
F_10 ( & V_12 -> V_7 , V_2 ) ;
* V_11 = V_12 -> V_11 ;
return 0 ;
}
static inline bool
F_11 ( const struct V_17 * V_18 ,
const struct V_17 * V_19 ,
T_1 * V_20 )
{
return V_18 -> V_21 == V_19 -> V_21 &&
V_18 -> V_22 == V_19 -> V_22 &&
( ++ * V_20 ) &&
V_18 -> V_23 == V_19 -> V_23 &&
V_18 -> V_11 == V_19 -> V_11 ;
}
static inline int
F_12 ( const struct V_17 * V_24 )
{
return V_24 -> V_25 ? - V_26 : 1 ;
}
static inline void
F_13 ( struct V_17 * V_24 , T_1 V_27 )
{
V_24 -> V_25 = ( V_27 >> 16 ) & V_28 ;
}
static inline void
F_14 ( struct V_17 * V_24 , T_2 * V_27 )
{
F_15 ( * V_27 , V_24 -> V_25 ) ;
}
static inline void
F_16 ( struct V_17 * V_24 , T_2 V_22 )
{
V_24 -> V_21 &= F_17 ( V_22 ) ;
V_24 -> V_22 = V_22 ;
}
static bool
F_18 ( struct V_29 * V_30 ,
const struct V_17 * V_31 )
{
T_1 V_27 = V_31 -> V_23 ? V_32 : 0 ;
if ( V_31 -> V_25 )
V_27 |= V_28 ;
if ( F_19 ( V_30 , V_33 , V_31 -> V_21 ) ||
F_20 ( V_30 , V_34 , V_31 -> V_22 ) ||
F_21 ( V_30 , V_35 , V_31 -> V_11 ) ||
( V_27 &&
F_22 ( V_30 , V_36 , F_23 ( V_27 ) ) ) )
goto V_37;
return 0 ;
V_37:
return 1 ;
}
static inline void
F_24 ( struct V_17 * V_38 ,
const struct V_17 * V_12 )
{
V_38 -> V_21 = V_12 -> V_21 ;
}
static int
F_25 ( struct V_39 * V_40 , const struct V_29 * V_30 ,
const struct V_41 * V_42 ,
enum V_43 V_44 , struct V_45 * V_46 )
{
struct V_47 * V_48 = V_40 -> V_31 ;
T_3 V_49 = V_40 -> V_50 -> V_44 [ V_44 ] ;
struct V_17 V_51 = {
. V_22 = V_48 -> V_52 [ 0 ] . V_22 ? V_48 -> V_52 [ 0 ] . V_22 : V_53 ,
. V_24 = 1 ,
} ;
struct V_54 V_55 = F_26 ( V_30 , V_46 , V_48 ) ;
int V_56 ;
if ( V_51 . V_22 == 0 )
return - V_57 ;
if ( V_44 == V_58 )
V_51 . V_22 = V_53 ;
F_27 ( V_30 , V_46 -> V_27 & V_59 , & V_51 . V_21 ) ;
V_51 . V_21 &= F_17 ( V_51 . V_22 ) ;
#define F_28 ( T_4 ) (par->dir ? par->dir->name : NULL)
#define F_29 ( T_4 ) (nf_bridge->dir ? nf_bridge->dir->name : NULL)
#define F_30 (opt->flags & IPSET_DIM_TWO_SRC)
if ( V_46 -> V_60 & V_32 ) {
#ifdef F_31
const struct V_61 * V_62 = V_30 -> V_62 ;
if ( ! V_62 )
return - V_57 ;
V_51 . V_11 = F_30 ? F_29 ( V_63 ) : F_29 ( V_64 ) ;
V_51 . V_23 = 1 ;
#else
V_51 . V_11 = NULL ;
#endif
} else
V_51 . V_11 = F_30 ? F_28 ( V_65 ) : F_28 ( V_66 ) ;
if ( ! V_51 . V_11 )
return - V_57 ;
V_56 = F_5 ( & V_48 -> V_67 , & V_51 . V_11 ) ;
if ( V_44 == V_68 ) {
if ( ! V_56 ) {
V_56 = F_7 ( & V_48 -> V_67 , & V_51 . V_11 ) ;
if ( V_56 )
return V_56 ;
}
} else if ( ! V_56 )
return V_56 ;
return V_49 ( V_40 , & V_51 , & V_55 , & V_46 -> V_55 , V_46 -> V_60 ) ;
}
static int
F_32 ( struct V_39 * V_40 , struct V_69 * V_70 [] ,
enum V_43 V_44 , T_1 * V_71 , T_1 V_27 , bool V_72 )
{
struct V_47 * V_48 = V_40 -> V_31 ;
T_3 V_49 = V_40 -> V_50 -> V_44 [ V_44 ] ;
struct V_17 V_51 = { . V_22 = V_53 , . V_24 = 1 } ;
struct V_54 V_55 = F_33 ( V_48 ) ;
T_1 V_21 = 0 , V_73 , V_74 ;
char V_11 [ V_75 ] ;
int V_56 ;
if ( F_34 ( ! V_70 [ V_33 ] ||
! V_70 [ V_35 ] ||
! F_35 ( V_70 , V_76 ) ||
! F_35 ( V_70 , V_36 ) ||
! F_35 ( V_70 , V_77 ) ||
! F_35 ( V_70 , V_78 ) ) )
return - V_79 ;
if ( V_70 [ V_80 ] )
* V_71 = F_36 ( V_70 [ V_80 ] ) ;
V_56 = F_37 ( V_70 [ V_33 ] , & V_21 ) ||
F_38 ( V_40 , V_70 , & V_55 ) ;
if ( V_56 )
return V_56 ;
if ( V_70 [ V_34 ] ) {
V_51 . V_22 = F_39 ( V_70 [ V_34 ] ) ;
if ( V_51 . V_22 > V_53 )
return - V_81 ;
}
strcpy ( V_11 , F_40 ( V_70 [ V_35 ] ) ) ;
V_51 . V_11 = V_11 ;
V_56 = F_5 ( & V_48 -> V_67 , & V_51 . V_11 ) ;
if ( V_44 == V_68 ) {
if ( ! V_56 ) {
V_56 = F_7 ( & V_48 -> V_67 , & V_51 . V_11 ) ;
if ( V_56 )
return V_56 ;
}
} else if ( ! V_56 )
return V_56 ;
if ( V_70 [ V_36 ] ) {
T_1 V_82 = F_41 ( V_70 [ V_36 ] ) ;
if ( V_82 & V_32 )
V_51 . V_23 = 1 ;
if ( V_82 & V_28 )
V_27 |= ( V_28 << 16 ) ;
}
if ( V_44 == V_58 || ! V_70 [ V_83 ] ) {
V_51 . V_21 = F_23 ( V_21 & F_42 ( V_51 . V_22 ) ) ;
V_56 = V_49 ( V_40 , & V_51 , & V_55 , & V_55 , V_27 ) ;
return F_43 ( V_56 , V_27 , V_44 ) ? 1 :
F_44 ( V_56 , V_27 ) ? 0 : V_56 ;
}
if ( V_70 [ V_83 ] ) {
V_56 = F_37 ( V_70 [ V_83 ] , & V_73 ) ;
if ( V_56 )
return V_56 ;
if ( V_73 < V_21 )
F_15 ( V_21 , V_73 ) ;
if ( V_21 + V_84 == V_73 )
return - V_85 ;
} else
F_45 ( V_21 , V_73 , V_51 . V_22 ) ;
if ( V_72 )
V_21 = F_46 ( V_48 -> V_38 . V_21 ) ;
while ( ! F_47 ( V_21 , V_73 ) ) {
V_51 . V_21 = F_23 ( V_21 ) ;
V_74 = F_48 ( V_21 , V_73 , & V_51 . V_22 ) ;
V_56 = V_49 ( V_40 , & V_51 , & V_55 , & V_55 , V_27 ) ;
if ( V_56 && ! F_44 ( V_56 , V_27 ) )
return V_56 ;
else
V_56 = 0 ;
V_21 = V_74 + 1 ;
}
return V_56 ;
}
static inline bool
F_49 ( const struct V_86 * V_18 ,
const struct V_86 * V_19 ,
T_1 * V_20 )
{
return F_50 ( & V_18 -> V_21 . V_87 , & V_19 -> V_21 . V_87 ) &&
V_18 -> V_22 == V_19 -> V_22 &&
( ++ * V_20 ) &&
V_18 -> V_23 == V_19 -> V_23 &&
V_18 -> V_11 == V_19 -> V_11 ;
}
static inline int
F_51 ( const struct V_86 * V_24 )
{
return V_24 -> V_25 ? - V_26 : 1 ;
}
static inline void
F_52 ( struct V_86 * V_24 , T_1 V_27 )
{
V_24 -> V_25 = ( V_27 >> 16 ) & V_28 ;
}
static inline void
F_53 ( struct V_86 * V_24 , T_2 * V_27 )
{
F_15 ( * V_27 , V_24 -> V_25 ) ;
}
static inline void
F_54 ( struct V_86 * V_24 , T_2 V_22 )
{
F_55 ( & V_24 -> V_21 , V_22 ) ;
V_24 -> V_22 = V_22 ;
}
static bool
F_56 ( struct V_29 * V_30 ,
const struct V_86 * V_31 )
{
T_1 V_27 = V_31 -> V_23 ? V_32 : 0 ;
if ( V_31 -> V_25 )
V_27 |= V_28 ;
if ( F_57 ( V_30 , V_33 , & V_31 -> V_21 . V_87 ) ||
F_20 ( V_30 , V_34 , V_31 -> V_22 ) ||
F_21 ( V_30 , V_35 , V_31 -> V_11 ) ||
( V_27 &&
F_22 ( V_30 , V_36 , F_23 ( V_27 ) ) ) )
goto V_37;
return 0 ;
V_37:
return 1 ;
}
static inline void
F_58 ( struct V_17 * V_38 ,
const struct V_86 * V_12 )
{
}
static int
F_59 ( struct V_39 * V_40 , const struct V_29 * V_30 ,
const struct V_41 * V_42 ,
enum V_43 V_44 , struct V_45 * V_46 )
{
struct V_47 * V_48 = V_40 -> V_31 ;
T_3 V_49 = V_40 -> V_50 -> V_44 [ V_44 ] ;
struct V_86 V_51 = {
. V_22 = V_48 -> V_52 [ 0 ] . V_22 ? V_48 -> V_52 [ 0 ] . V_22 : V_53 ,
. V_24 = 1 ,
} ;
struct V_54 V_55 = F_26 ( V_30 , V_46 , V_48 ) ;
int V_56 ;
if ( V_51 . V_22 == 0 )
return - V_57 ;
if ( V_44 == V_58 )
V_51 . V_22 = V_53 ;
F_60 ( V_30 , V_46 -> V_27 & V_59 , & V_51 . V_21 . V_87 ) ;
F_55 ( & V_51 . V_21 , V_51 . V_22 ) ;
if ( V_46 -> V_60 & V_32 ) {
#ifdef F_31
const struct V_61 * V_62 = V_30 -> V_62 ;
if ( ! V_62 )
return - V_57 ;
V_51 . V_11 = F_30 ? F_29 ( V_63 ) : F_29 ( V_64 ) ;
V_51 . V_23 = 1 ;
#else
V_51 . V_11 = NULL ;
#endif
} else
V_51 . V_11 = F_30 ? F_28 ( V_65 ) : F_28 ( V_66 ) ;
if ( ! V_51 . V_11 )
return - V_57 ;
V_56 = F_5 ( & V_48 -> V_67 , & V_51 . V_11 ) ;
if ( V_44 == V_68 ) {
if ( ! V_56 ) {
V_56 = F_7 ( & V_48 -> V_67 , & V_51 . V_11 ) ;
if ( V_56 )
return V_56 ;
}
} else if ( ! V_56 )
return V_56 ;
return V_49 ( V_40 , & V_51 , & V_55 , & V_46 -> V_55 , V_46 -> V_60 ) ;
}
static int
F_61 ( struct V_39 * V_40 , struct V_69 * V_70 [] ,
enum V_43 V_44 , T_1 * V_71 , T_1 V_27 , bool V_72 )
{
struct V_47 * V_48 = V_40 -> V_31 ;
T_3 V_49 = V_40 -> V_50 -> V_44 [ V_44 ] ;
struct V_86 V_51 = { . V_22 = V_53 , . V_24 = 1 } ;
struct V_54 V_55 = F_33 ( V_48 ) ;
char V_11 [ V_75 ] ;
int V_56 ;
if ( F_34 ( ! V_70 [ V_33 ] ||
! V_70 [ V_35 ] ||
! F_35 ( V_70 , V_76 ) ||
! F_35 ( V_70 , V_36 ) ||
! F_35 ( V_70 , V_77 ) ||
! F_35 ( V_70 , V_78 ) ) )
return - V_79 ;
if ( F_34 ( V_70 [ V_83 ] ) )
return - V_88 ;
if ( V_70 [ V_80 ] )
* V_71 = F_36 ( V_70 [ V_80 ] ) ;
V_56 = F_62 ( V_70 [ V_33 ] , & V_51 . V_21 ) ||
F_38 ( V_40 , V_70 , & V_55 ) ;
if ( V_56 )
return V_56 ;
if ( V_70 [ V_34 ] )
V_51 . V_22 = F_39 ( V_70 [ V_34 ] ) ;
if ( V_51 . V_22 > V_53 )
return - V_81 ;
F_55 ( & V_51 . V_21 , V_51 . V_22 ) ;
strcpy ( V_11 , F_40 ( V_70 [ V_35 ] ) ) ;
V_51 . V_11 = V_11 ;
V_56 = F_5 ( & V_48 -> V_67 , & V_51 . V_11 ) ;
if ( V_44 == V_68 ) {
if ( ! V_56 ) {
V_56 = F_7 ( & V_48 -> V_67 , & V_51 . V_11 ) ;
if ( V_56 )
return V_56 ;
}
} else if ( ! V_56 )
return V_56 ;
if ( V_70 [ V_36 ] ) {
T_1 V_82 = F_41 ( V_70 [ V_36 ] ) ;
if ( V_82 & V_32 )
V_51 . V_23 = 1 ;
if ( V_82 & V_28 )
V_27 |= ( V_28 << 16 ) ;
}
V_56 = V_49 ( V_40 , & V_51 , & V_55 , & V_55 , V_27 ) ;
return F_43 ( V_56 , V_27 , V_44 ) ? 1 :
F_44 ( V_56 , V_27 ) ? 0 : V_56 ;
}
static int T_5
F_63 ( void )
{
return F_64 ( & V_89 ) ;
}
static void T_6
F_65 ( void )
{
F_66 ( & V_89 ) ;
}
