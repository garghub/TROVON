static inline long
F_1 ( const char * V_1 , const char * V_2 )
{
const long * V_3 = ( const long * ) V_1 ;
const long * V_4 = ( const long * ) V_2 ;
F_2 ( V_5 > 4 * sizeof( unsigned long ) ) ;
if ( V_3 [ 0 ] != V_4 [ 0 ] )
return V_3 [ 0 ] - V_4 [ 0 ] ;
if ( V_5 > sizeof( long ) ) {
if ( V_3 [ 1 ] != V_4 [ 1 ] )
return V_3 [ 1 ] - V_4 [ 1 ] ;
}
if ( V_5 > 2 * sizeof( long ) ) {
if ( V_3 [ 2 ] != V_4 [ 2 ] )
return V_3 [ 2 ] - V_4 [ 2 ] ;
}
if ( V_5 > 3 * sizeof( long ) ) {
if ( V_3 [ 3 ] != V_4 [ 3 ] )
return V_3 [ 3 ] - V_4 [ 3 ] ;
}
return 0 ;
}
static void
F_3 ( struct V_6 * V_7 )
{
struct V_8 * V_9 , * V_10 = V_7 -> V_8 ;
struct V_11 * V_12 ;
while ( V_10 ) {
if ( V_10 -> V_13 ) {
V_10 = V_10 -> V_13 ;
continue;
}
if ( V_10 -> V_14 ) {
V_10 = V_10 -> V_14 ;
continue;
}
V_9 = F_4 ( V_10 ) ;
V_12 = F_5 ( V_10 , struct V_11 , V_12 ) ;
if ( ! V_9 )
* V_7 = V_15 ;
else if ( V_9 -> V_13 == V_10 )
V_9 -> V_13 = NULL ;
else if ( V_9 -> V_14 == V_10 )
V_9 -> V_14 = NULL ;
F_6 ( V_12 ) ;
V_10 = V_9 ;
}
}
static int
F_7 ( struct V_6 * V_7 , const char * * V_16 )
{
struct V_8 * V_10 = V_7 -> V_8 ;
while ( V_10 ) {
const char * V_17 = F_8 ( V_10 ) ;
long V_18 = F_1 ( * V_16 , V_17 ) ;
if ( V_18 < 0 )
V_10 = V_10 -> V_13 ;
else if ( V_18 > 0 )
V_10 = V_10 -> V_14 ;
else {
* V_16 = V_17 ;
return 1 ;
}
}
return 0 ;
}
static int
F_9 ( struct V_6 * V_7 , const char * * V_16 )
{
struct V_8 * * V_10 = & ( V_7 -> V_8 ) , * V_9 = NULL ;
struct V_11 * V_17 ;
while ( * V_10 ) {
char * V_19 = F_8 ( * V_10 ) ;
long V_18 = F_1 ( * V_16 , V_19 ) ;
V_9 = * V_10 ;
if ( V_18 < 0 )
V_10 = & ( ( * V_10 ) -> V_13 ) ;
else if ( V_18 > 0 )
V_10 = & ( ( * V_10 ) -> V_14 ) ;
else {
* V_16 = V_19 ;
return 0 ;
}
}
V_17 = F_10 ( sizeof( * V_17 ) , V_20 ) ;
if ( ! V_17 )
return - V_21 ;
strcpy ( V_17 -> V_16 , * V_16 ) ;
F_11 ( & V_17 -> V_12 , V_9 , V_10 ) ;
F_12 ( & V_17 -> V_12 , V_7 ) ;
* V_16 = V_17 -> V_16 ;
return 0 ;
}
static inline bool
F_13 ( const struct V_22 * V_23 ,
const struct V_22 * V_24 ,
T_1 * V_25 )
{
return V_23 -> V_26 == V_24 -> V_26 &&
V_23 -> V_27 == V_24 -> V_27 &&
( ++ * V_25 ) &&
V_23 -> V_28 == V_24 -> V_28 &&
V_23 -> V_16 == V_24 -> V_16 ;
}
static inline bool
F_14 ( const struct V_22 * V_29 )
{
return V_29 -> V_27 == 0 ;
}
static inline void
F_15 ( struct V_22 * V_30 ,
const struct V_22 * V_31 )
{
V_30 -> V_26 = V_31 -> V_26 ;
V_30 -> V_27 = V_31 -> V_27 ;
V_30 -> V_28 = V_31 -> V_28 ;
V_30 -> V_16 = V_31 -> V_16 ;
V_30 -> V_32 = V_31 -> V_32 ;
}
static inline void
F_16 ( struct V_22 * V_30 , T_1 V_33 )
{
V_30 -> V_32 = V_33 & V_34 ;
}
static inline bool
F_17 ( const struct V_22 * V_29 )
{
return ! V_29 -> V_32 ;
}
static inline void
F_18 ( struct V_22 * V_29 , T_2 V_27 )
{
V_29 -> V_26 &= F_19 ( V_27 ) ;
V_29 -> V_27 = V_27 ;
}
static inline void
F_20 ( struct V_22 * V_29 )
{
V_29 -> V_27 = 0 ;
}
static bool
F_21 ( struct V_35 * V_36 ,
const struct V_22 * V_37 )
{
T_1 V_33 = V_37 -> V_28 ? V_38 : 0 ;
if ( V_37 -> V_32 )
V_33 |= V_34 ;
F_22 ( V_36 , V_39 , V_37 -> V_26 ) ;
F_23 ( V_36 , V_40 , V_37 -> V_27 ) ;
F_24 ( V_36 , V_41 , V_37 -> V_16 ) ;
if ( V_33 )
F_25 ( V_36 , V_42 , F_26 ( V_33 ) ) ;
return 0 ;
V_43:
return 1 ;
}
static bool
F_27 ( struct V_35 * V_36 ,
const struct V_22 * V_37 )
{
const struct V_44 * V_45 =
( const struct V_44 * ) V_37 ;
T_1 V_33 = V_37 -> V_28 ? V_38 : 0 ;
if ( V_37 -> V_32 )
V_33 |= V_34 ;
F_22 ( V_36 , V_39 , V_37 -> V_26 ) ;
F_23 ( V_36 , V_40 , V_37 -> V_27 ) ;
F_24 ( V_36 , V_41 , V_37 -> V_16 ) ;
if ( V_33 )
F_25 ( V_36 , V_42 , F_26 ( V_33 ) ) ;
F_25 ( V_36 , V_46 ,
F_26 ( F_28 ( V_45 -> V_47 ) ) ) ;
return 0 ;
V_43:
return 1 ;
}
static inline void
F_29 ( struct V_48 * V_49 ,
const struct V_22 * V_17 )
{
V_49 -> V_50 . V_26 = F_30 ( V_17 -> V_26 ) ;
}
static int
F_31 ( struct V_51 * V_52 , const struct V_35 * V_36 ,
const struct V_53 * V_54 ,
enum V_55 V_56 , const struct V_57 * V_58 )
{
struct V_48 * V_49 = V_52 -> V_37 ;
T_3 V_59 = V_52 -> V_60 -> V_56 [ V_56 ] ;
struct V_22 V_37 = {
. V_27 = V_49 -> V_61 [ 0 ] . V_27 ? V_49 -> V_61 [ 0 ] . V_27 : V_62
} ;
int V_63 ;
if ( V_37 . V_27 == 0 )
return - V_64 ;
if ( V_56 == V_65 )
V_37 . V_27 = V_62 ;
F_32 ( V_36 , V_58 -> V_33 & V_66 , & V_37 . V_26 ) ;
V_37 . V_26 &= F_19 ( V_37 . V_27 ) ;
#define F_33 ( T_4 ) (par->dir ? par->dir->name : NULL)
#define F_34 ( T_4 ) (nf_bridge->dir ? nf_bridge->dir->name : NULL)
#define F_35 (opt->flags & IPSET_DIM_TWO_SRC)
if ( V_58 -> V_67 & V_38 ) {
#ifdef F_36
const struct V_68 * V_69 = V_36 -> V_69 ;
if ( ! V_69 )
return - V_64 ;
V_37 . V_16 = F_35 ? F_34 ( V_70 ) : F_34 ( V_71 ) ;
V_37 . V_28 = 1 ;
#else
V_37 . V_16 = NULL ;
#endif
} else
V_37 . V_16 = F_35 ? F_33 ( V_72 ) : F_33 ( V_73 ) ;
if ( ! V_37 . V_16 )
return - V_64 ;
V_63 = F_7 ( & V_49 -> V_74 , & V_37 . V_16 ) ;
if ( V_56 == V_75 ) {
if ( ! V_63 ) {
V_63 = F_9 ( & V_49 -> V_74 , & V_37 . V_16 ) ;
if ( V_63 )
return V_63 ;
}
} else if ( ! V_63 )
return V_63 ;
return V_59 ( V_52 , & V_37 , F_37 ( V_58 , V_49 ) , V_58 -> V_67 ) ;
}
static int
F_38 ( struct V_51 * V_52 , struct V_76 * V_77 [] ,
enum V_55 V_56 , T_1 * V_78 , T_1 V_33 , bool V_79 )
{
struct V_48 * V_49 = V_52 -> V_37 ;
T_3 V_59 = V_52 -> V_60 -> V_56 [ V_56 ] ;
struct V_22 V_37 = { . V_27 = V_62 } ;
T_1 V_26 = 0 , V_80 , V_81 ;
T_1 V_47 = V_49 -> V_47 ;
char V_16 [ V_5 ] = {} ;
int V_63 ;
if ( F_39 ( ! V_77 [ V_39 ] ||
! V_77 [ V_41 ] ||
! F_40 ( V_77 , V_46 ) ||
! F_40 ( V_77 , V_42 ) ) )
return - V_82 ;
if ( V_77 [ V_83 ] )
* V_78 = F_41 ( V_77 [ V_83 ] ) ;
V_63 = F_42 ( V_77 [ V_39 ] , & V_26 ) ;
if ( V_63 )
return V_63 ;
if ( V_77 [ V_40 ] ) {
V_37 . V_27 = F_43 ( V_77 [ V_40 ] ) ;
if ( ! V_37 . V_27 || V_37 . V_27 > V_62 )
return - V_84 ;
}
if ( V_77 [ V_46 ] ) {
if ( ! F_44 ( V_49 -> V_47 ) )
return - V_85 ;
V_47 = F_45 ( V_77 [ V_46 ] ) ;
}
strcpy ( V_16 , F_46 ( V_77 [ V_41 ] ) ) ;
V_37 . V_16 = V_16 ;
V_63 = F_7 ( & V_49 -> V_74 , & V_37 . V_16 ) ;
if ( V_56 == V_75 ) {
if ( ! V_63 ) {
V_63 = F_9 ( & V_49 -> V_74 , & V_37 . V_16 ) ;
if ( V_63 )
return V_63 ;
}
} else if ( ! V_63 )
return V_63 ;
if ( V_77 [ V_42 ] ) {
T_1 V_86 = F_47 ( V_77 [ V_42 ] ) ;
if ( V_86 & V_38 )
V_37 . V_28 = 1 ;
if ( V_56 == V_75 && ( V_86 & V_34 ) )
V_33 |= ( V_86 << 16 ) ;
}
if ( V_56 == V_65 || ! V_77 [ V_87 ] ) {
V_37 . V_26 = F_26 ( V_26 & F_48 ( V_37 . V_27 ) ) ;
V_63 = V_59 ( V_52 , & V_37 , V_47 , V_33 ) ;
return F_49 ( V_63 , V_33 ) ? 0 : V_63 ;
}
if ( V_77 [ V_87 ] ) {
V_63 = F_42 ( V_77 [ V_87 ] , & V_80 ) ;
if ( V_63 )
return V_63 ;
if ( V_80 < V_26 )
F_50 ( V_26 , V_80 ) ;
if ( V_26 + V_88 == V_80 )
return - V_89 ;
} else {
F_51 ( V_26 , V_80 , V_37 . V_27 ) ;
}
if ( V_79 )
V_26 = V_49 -> V_50 . V_26 ;
while ( ! F_52 ( V_26 , V_80 ) ) {
V_37 . V_26 = F_26 ( V_26 ) ;
V_81 = F_53 ( V_26 , V_80 , & V_37 . V_27 ) ;
V_63 = V_59 ( V_52 , & V_37 , V_47 , V_33 ) ;
if ( V_63 && ! F_49 ( V_63 , V_33 ) )
return V_63 ;
else
V_63 = 0 ;
V_26 = V_81 + 1 ;
}
return V_63 ;
}
static bool
F_54 ( const struct V_51 * V_3 , const struct V_51 * V_4 )
{
const struct V_48 * V_90 = V_3 -> V_37 ;
const struct V_48 * V_91 = V_4 -> V_37 ;
return V_90 -> V_92 == V_91 -> V_92 &&
V_90 -> V_47 == V_91 -> V_47 ;
}
static inline bool
F_55 ( const struct V_93 * V_23 ,
const struct V_93 * V_24 ,
T_1 * V_25 )
{
return F_56 ( & V_23 -> V_26 . V_94 , & V_24 -> V_26 . V_94 ) == 0 &&
V_23 -> V_27 == V_24 -> V_27 &&
( ++ * V_25 ) &&
V_23 -> V_28 == V_24 -> V_28 &&
V_23 -> V_16 == V_24 -> V_16 ;
}
static inline bool
F_57 ( const struct V_93 * V_29 )
{
return V_29 -> V_27 == 0 ;
}
static inline void
F_58 ( struct V_93 * V_30 ,
const struct V_93 * V_31 )
{
memcpy ( V_30 , V_31 , sizeof( * V_30 ) ) ;
}
static inline void
F_59 ( struct V_93 * V_30 , T_1 V_33 )
{
V_30 -> V_32 = V_33 & V_34 ;
}
static inline bool
F_60 ( const struct V_93 * V_29 )
{
return ! V_29 -> V_32 ;
}
static inline void
F_61 ( struct V_93 * V_29 )
{
V_29 -> V_27 = 0 ;
}
static inline void
F_62 ( union V_95 * V_26 , T_2 V_96 )
{
V_26 -> V_97 [ 0 ] &= F_63 ( V_96 ) [ 0 ] ;
V_26 -> V_97 [ 1 ] &= F_63 ( V_96 ) [ 1 ] ;
V_26 -> V_97 [ 2 ] &= F_63 ( V_96 ) [ 2 ] ;
V_26 -> V_97 [ 3 ] &= F_63 ( V_96 ) [ 3 ] ;
}
static inline void
F_64 ( struct V_93 * V_29 , T_2 V_27 )
{
F_62 ( & V_29 -> V_26 , V_27 ) ;
V_29 -> V_27 = V_27 ;
}
static bool
F_65 ( struct V_35 * V_36 ,
const struct V_93 * V_37 )
{
T_1 V_33 = V_37 -> V_28 ? V_38 : 0 ;
if ( V_37 -> V_32 )
V_33 |= V_34 ;
F_66 ( V_36 , V_39 , & V_37 -> V_26 ) ;
F_23 ( V_36 , V_40 , V_37 -> V_27 ) ;
F_24 ( V_36 , V_41 , V_37 -> V_16 ) ;
if ( V_33 )
F_25 ( V_36 , V_42 , F_26 ( V_33 ) ) ;
return 0 ;
V_43:
return 1 ;
}
static bool
F_67 ( struct V_35 * V_36 ,
const struct V_93 * V_37 )
{
const struct V_98 * V_99 =
( const struct V_98 * ) V_37 ;
T_1 V_33 = V_37 -> V_28 ? V_38 : 0 ;
if ( V_37 -> V_32 )
V_33 |= V_34 ;
F_66 ( V_36 , V_39 , & V_99 -> V_26 ) ;
F_23 ( V_36 , V_40 , V_37 -> V_27 ) ;
F_24 ( V_36 , V_41 , V_37 -> V_16 ) ;
if ( V_33 )
F_25 ( V_36 , V_42 , F_26 ( V_33 ) ) ;
F_25 ( V_36 , V_46 ,
F_26 ( F_28 ( V_99 -> V_47 ) ) ) ;
return 0 ;
V_43:
return 1 ;
}
static inline void
F_68 ( struct V_48 * V_49 ,
const struct V_93 * V_17 )
{
}
static int
F_69 ( struct V_51 * V_52 , const struct V_35 * V_36 ,
const struct V_53 * V_54 ,
enum V_55 V_56 , const struct V_57 * V_58 )
{
struct V_48 * V_49 = V_52 -> V_37 ;
T_3 V_59 = V_52 -> V_60 -> V_56 [ V_56 ] ;
struct V_93 V_37 = {
. V_27 = V_49 -> V_61 [ 0 ] . V_27 ? V_49 -> V_61 [ 0 ] . V_27 : V_62
} ;
int V_63 ;
if ( V_37 . V_27 == 0 )
return - V_64 ;
if ( V_56 == V_65 )
V_37 . V_27 = V_62 ;
F_70 ( V_36 , V_58 -> V_33 & V_66 , & V_37 . V_26 . V_94 ) ;
F_62 ( & V_37 . V_26 , V_37 . V_27 ) ;
if ( V_58 -> V_67 & V_38 ) {
#ifdef F_36
const struct V_68 * V_69 = V_36 -> V_69 ;
if ( ! V_69 )
return - V_64 ;
V_37 . V_16 = F_35 ? F_34 ( V_70 ) : F_34 ( V_71 ) ;
V_37 . V_28 = 1 ;
#else
V_37 . V_16 = NULL ;
#endif
} else
V_37 . V_16 = F_35 ? F_33 ( V_72 ) : F_33 ( V_73 ) ;
if ( ! V_37 . V_16 )
return - V_64 ;
V_63 = F_7 ( & V_49 -> V_74 , & V_37 . V_16 ) ;
if ( V_56 == V_75 ) {
if ( ! V_63 ) {
V_63 = F_9 ( & V_49 -> V_74 , & V_37 . V_16 ) ;
if ( V_63 )
return V_63 ;
}
} else if ( ! V_63 )
return V_63 ;
return V_59 ( V_52 , & V_37 , F_37 ( V_58 , V_49 ) , V_58 -> V_67 ) ;
}
static int
F_71 ( struct V_51 * V_52 , struct V_76 * V_77 [] ,
enum V_55 V_56 , T_1 * V_78 , T_1 V_33 , bool V_79 )
{
struct V_48 * V_49 = V_52 -> V_37 ;
T_3 V_59 = V_52 -> V_60 -> V_56 [ V_56 ] ;
struct V_93 V_37 = { . V_27 = V_62 } ;
T_1 V_47 = V_49 -> V_47 ;
char V_16 [ V_5 ] = {} ;
int V_63 ;
if ( F_39 ( ! V_77 [ V_39 ] ||
! V_77 [ V_41 ] ||
! F_40 ( V_77 , V_46 ) ||
! F_40 ( V_77 , V_42 ) ) )
return - V_82 ;
if ( F_39 ( V_77 [ V_87 ] ) )
return - V_100 ;
if ( V_77 [ V_83 ] )
* V_78 = F_41 ( V_77 [ V_83 ] ) ;
V_63 = F_72 ( V_77 [ V_39 ] , & V_37 . V_26 ) ;
if ( V_63 )
return V_63 ;
if ( V_77 [ V_40 ] )
V_37 . V_27 = F_43 ( V_77 [ V_40 ] ) ;
if ( ! V_37 . V_27 || V_37 . V_27 > V_62 )
return - V_84 ;
F_62 ( & V_37 . V_26 , V_37 . V_27 ) ;
if ( V_77 [ V_46 ] ) {
if ( ! F_44 ( V_49 -> V_47 ) )
return - V_85 ;
V_47 = F_45 ( V_77 [ V_46 ] ) ;
}
strcpy ( V_16 , F_46 ( V_77 [ V_41 ] ) ) ;
V_37 . V_16 = V_16 ;
V_63 = F_7 ( & V_49 -> V_74 , & V_37 . V_16 ) ;
if ( V_56 == V_75 ) {
if ( ! V_63 ) {
V_63 = F_9 ( & V_49 -> V_74 , & V_37 . V_16 ) ;
if ( V_63 )
return V_63 ;
}
} else if ( ! V_63 )
return V_63 ;
if ( V_77 [ V_42 ] ) {
T_1 V_86 = F_47 ( V_77 [ V_42 ] ) ;
if ( V_86 & V_38 )
V_37 . V_28 = 1 ;
if ( V_56 == V_75 && ( V_86 & V_34 ) )
V_33 |= ( V_86 << 16 ) ;
}
V_63 = V_59 ( V_52 , & V_37 , V_47 , V_33 ) ;
return F_49 ( V_63 , V_33 ) ? 0 : V_63 ;
}
static int
F_73 ( struct V_51 * V_52 , struct V_76 * V_77 [] , T_1 V_33 )
{
struct V_48 * V_49 ;
T_1 V_101 = V_102 , V_92 = V_103 ;
T_2 V_104 ;
T_5 V_105 ;
if ( ! ( V_52 -> V_106 == V_107 || V_52 -> V_106 == V_108 ) )
return - V_109 ;
if ( F_39 ( ! F_40 ( V_77 , V_110 ) ||
! F_40 ( V_77 , V_111 ) ||
! F_40 ( V_77 , V_46 ) ) )
return - V_82 ;
if ( V_77 [ V_110 ] ) {
V_101 = F_47 ( V_77 [ V_110 ] ) ;
if ( V_101 < V_112 )
V_101 = V_112 ;
}
if ( V_77 [ V_111 ] )
V_92 = F_47 ( V_77 [ V_111 ] ) ;
V_49 = F_10 ( sizeof( * V_49 )
+ sizeof( struct V_113 )
* ( V_52 -> V_106 == V_107 ? 32 : 128 ) , V_114 ) ;
if ( ! V_49 )
return - V_21 ;
V_49 -> V_92 = V_92 ;
F_74 ( & V_49 -> V_115 , sizeof( V_49 -> V_115 ) ) ;
V_49 -> V_47 = V_116 ;
V_49 -> V_117 = V_118 ;
V_104 = F_75 ( V_101 ) ;
V_105 = F_76 ( V_104 ) ;
if ( V_105 == 0 ) {
F_6 ( V_49 ) ;
return - V_21 ;
}
V_49 -> V_119 = F_77 ( V_105 ) ;
if ( ! V_49 -> V_119 ) {
F_6 ( V_49 ) ;
return - V_21 ;
}
V_49 -> V_119 -> F_75 = V_104 ;
V_49 -> V_74 = V_15 ;
V_52 -> V_37 = V_49 ;
if ( V_77 [ V_46 ] ) {
V_49 -> V_47 = F_45 ( V_77 [ V_46 ] ) ;
V_52 -> V_60 = V_52 -> V_106 == V_107
? & V_120 : & V_121 ;
if ( V_52 -> V_106 == V_107 )
F_78 ( V_52 ) ;
else
F_79 ( V_52 ) ;
} else {
V_52 -> V_60 = V_52 -> V_106 == V_107
? & V_122 : & V_123 ;
}
F_80 ( L_1 ,
V_52 -> V_124 , F_81 ( V_49 -> V_119 -> F_75 ) ,
V_49 -> V_119 -> F_75 , V_49 -> V_92 , V_52 -> V_37 , V_49 -> V_119 ) ;
return 0 ;
}
static int T_6
F_82 ( void )
{
return F_83 ( & V_125 ) ;
}
static void T_7
F_84 ( void )
{
F_85 ( & V_125 ) ;
}
