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
const struct V_22 * V_31 ) {
V_30 -> V_26 = V_31 -> V_26 ;
V_30 -> V_27 = V_31 -> V_27 ;
V_30 -> V_28 = V_31 -> V_28 ;
V_30 -> V_16 = V_31 -> V_16 ;
}
static inline void
F_16 ( struct V_22 * V_29 , T_2 V_27 )
{
V_29 -> V_26 &= F_17 ( V_27 ) ;
V_29 -> V_27 = V_27 ;
}
static inline void
F_18 ( struct V_22 * V_29 )
{
V_29 -> V_27 = 0 ;
}
static bool
F_19 ( struct V_32 * V_33 ,
const struct V_22 * V_34 )
{
T_1 V_35 = V_34 -> V_28 ? V_36 : 0 ;
F_20 ( V_33 , V_37 , V_34 -> V_26 ) ;
F_21 ( V_33 , V_38 , V_34 -> V_27 ) ;
F_22 ( V_33 , V_39 , V_34 -> V_16 ) ;
if ( V_35 )
F_23 ( V_33 , V_40 , V_35 ) ;
return 0 ;
V_41:
return 1 ;
}
static bool
F_24 ( struct V_32 * V_33 ,
const struct V_22 * V_34 )
{
const struct V_42 * V_43 =
( const struct V_42 * ) V_34 ;
T_1 V_35 = V_34 -> V_28 ? V_36 : 0 ;
F_20 ( V_33 , V_37 , V_34 -> V_26 ) ;
F_21 ( V_33 , V_38 , V_34 -> V_27 ) ;
F_22 ( V_33 , V_39 , V_34 -> V_16 ) ;
if ( V_35 )
F_23 ( V_33 , V_40 , V_35 ) ;
F_23 ( V_33 , V_44 ,
F_25 ( F_26 ( V_43 -> V_45 ) ) ) ;
return 0 ;
V_41:
return 1 ;
}
static inline void
F_27 ( struct V_46 * V_47 ,
const struct V_22 * V_17 )
{
V_47 -> V_48 . V_26 = F_28 ( V_17 -> V_26 ) ;
}
static int
F_29 ( struct V_49 * V_50 , const struct V_32 * V_33 ,
const struct V_51 * V_52 ,
enum V_53 V_54 , const struct V_55 * V_56 )
{
struct V_46 * V_47 = V_50 -> V_34 ;
T_3 V_57 = V_50 -> V_58 -> V_54 [ V_54 ] ;
struct V_22 V_34 = {
. V_27 = V_47 -> V_59 [ 0 ] . V_27 ? V_47 -> V_59 [ 0 ] . V_27 : V_60
} ;
int V_61 ;
if ( V_34 . V_27 == 0 )
return - V_62 ;
if ( V_54 == V_63 )
V_34 . V_27 = V_60 ;
F_30 ( V_33 , V_56 -> V_35 & V_64 , & V_34 . V_26 ) ;
V_34 . V_26 &= F_17 ( V_34 . V_27 ) ;
#define F_31 ( T_4 ) (par->dir ? par->dir->name : NULL)
#define F_32 ( T_4 ) (nf_bridge->dir ? nf_bridge->dir->name : NULL)
#define F_33 (opt->flags & IPSET_DIM_TWO_SRC)
if ( V_56 -> V_65 & V_36 ) {
#ifdef F_34
const struct V_66 * V_67 = V_33 -> V_67 ;
if ( ! V_67 )
return - V_62 ;
V_34 . V_16 = F_33 ? F_32 ( V_68 ) : F_32 ( V_69 ) ;
V_34 . V_28 = 1 ;
#else
V_34 . V_16 = NULL ;
#endif
} else
V_34 . V_16 = F_33 ? F_31 ( V_70 ) : F_31 ( V_71 ) ;
if ( ! V_34 . V_16 )
return - V_62 ;
V_61 = F_7 ( & V_47 -> V_72 , & V_34 . V_16 ) ;
if ( V_54 == V_73 ) {
if ( ! V_61 ) {
V_61 = F_9 ( & V_47 -> V_72 , & V_34 . V_16 ) ;
if ( V_61 )
return V_61 ;
}
} else if ( ! V_61 )
return V_61 ;
return V_57 ( V_50 , & V_34 , F_35 ( V_56 , V_47 ) , V_56 -> V_65 ) ;
}
static int
F_36 ( struct V_49 * V_50 , struct V_74 * V_75 [] ,
enum V_53 V_54 , T_1 * V_76 , T_1 V_35 , bool V_77 )
{
struct V_46 * V_47 = V_50 -> V_34 ;
T_3 V_57 = V_50 -> V_58 -> V_54 [ V_54 ] ;
struct V_22 V_34 = { . V_27 = V_60 } ;
T_1 V_26 = 0 , V_78 , V_79 ;
T_1 V_45 = V_47 -> V_45 ;
char V_16 [ V_5 ] = {} ;
int V_61 ;
if ( F_37 ( ! V_75 [ V_37 ] ||
! V_75 [ V_39 ] ||
! F_38 ( V_75 , V_44 ) ||
! F_38 ( V_75 , V_40 ) ) )
return - V_80 ;
if ( V_75 [ V_81 ] )
* V_76 = F_39 ( V_75 [ V_81 ] ) ;
V_61 = F_40 ( V_75 [ V_37 ] , & V_26 ) ;
if ( V_61 )
return V_61 ;
if ( V_75 [ V_38 ] ) {
V_34 . V_27 = F_41 ( V_75 [ V_38 ] ) ;
if ( ! V_34 . V_27 )
return - V_82 ;
}
if ( V_75 [ V_44 ] ) {
if ( ! F_42 ( V_47 -> V_45 ) )
return - V_83 ;
V_45 = F_43 ( V_75 [ V_44 ] ) ;
}
strcpy ( V_16 , F_44 ( V_75 [ V_39 ] ) ) ;
V_34 . V_16 = V_16 ;
V_61 = F_7 ( & V_47 -> V_72 , & V_34 . V_16 ) ;
if ( V_54 == V_73 ) {
if ( ! V_61 ) {
V_61 = F_9 ( & V_47 -> V_72 , & V_34 . V_16 ) ;
if ( V_61 )
return V_61 ;
}
} else if ( ! V_61 )
return V_61 ;
if ( V_75 [ V_40 ] ) {
T_1 V_84 = F_45 ( V_75 [ V_40 ] ) ;
if ( V_84 & V_36 )
V_34 . V_28 = 1 ;
}
if ( V_54 == V_63 || ! V_75 [ V_85 ] ) {
V_34 . V_26 = F_25 ( V_26 & F_46 ( V_34 . V_27 ) ) ;
V_61 = V_57 ( V_50 , & V_34 , V_45 , V_35 ) ;
return F_47 ( V_61 , V_35 ) ? 0 : V_61 ;
}
if ( V_75 [ V_85 ] ) {
V_61 = F_40 ( V_75 [ V_85 ] , & V_78 ) ;
if ( V_61 )
return V_61 ;
if ( V_78 < V_26 )
F_48 ( V_26 , V_78 ) ;
if ( V_26 + V_86 == V_78 )
return - V_87 ;
} else {
F_49 ( V_26 , V_78 , V_34 . V_27 ) ;
}
if ( V_77 )
V_26 = V_47 -> V_48 . V_26 ;
while ( ! F_50 ( V_26 , V_78 ) ) {
V_34 . V_26 = F_25 ( V_26 ) ;
V_79 = F_51 ( V_26 , V_78 , & V_34 . V_27 ) ;
V_61 = V_57 ( V_50 , & V_34 , V_45 , V_35 ) ;
if ( V_61 && ! F_47 ( V_61 , V_35 ) )
return V_61 ;
else
V_61 = 0 ;
V_26 = V_79 + 1 ;
}
return V_61 ;
}
static bool
F_52 ( const struct V_49 * V_3 , const struct V_49 * V_4 )
{
const struct V_46 * V_88 = V_3 -> V_34 ;
const struct V_46 * V_89 = V_4 -> V_34 ;
return V_88 -> V_90 == V_89 -> V_90 &&
V_88 -> V_45 == V_89 -> V_45 ;
}
static inline bool
F_53 ( const struct V_91 * V_23 ,
const struct V_91 * V_24 ,
T_1 * V_25 )
{
return F_54 ( & V_23 -> V_26 . V_92 , & V_24 -> V_26 . V_92 ) == 0 &&
V_23 -> V_27 == V_24 -> V_27 &&
( ++ * V_25 ) &&
V_23 -> V_28 == V_24 -> V_28 &&
V_23 -> V_16 == V_24 -> V_16 ;
}
static inline bool
F_55 ( const struct V_91 * V_29 )
{
return V_29 -> V_27 == 0 ;
}
static inline void
F_56 ( struct V_91 * V_30 ,
const struct V_91 * V_31 )
{
memcpy ( V_30 , V_31 , sizeof( * V_30 ) ) ;
}
static inline void
F_57 ( struct V_91 * V_29 )
{
}
static inline void
F_58 ( union V_93 * V_26 , T_2 V_94 )
{
V_26 -> V_95 [ 0 ] &= F_59 ( V_94 ) [ 0 ] ;
V_26 -> V_95 [ 1 ] &= F_59 ( V_94 ) [ 1 ] ;
V_26 -> V_95 [ 2 ] &= F_59 ( V_94 ) [ 2 ] ;
V_26 -> V_95 [ 3 ] &= F_59 ( V_94 ) [ 3 ] ;
}
static inline void
F_60 ( struct V_91 * V_29 , T_2 V_27 )
{
F_58 ( & V_29 -> V_26 , V_27 ) ;
V_29 -> V_27 = V_27 ;
}
static bool
F_61 ( struct V_32 * V_33 ,
const struct V_91 * V_34 )
{
T_1 V_35 = V_34 -> V_28 ? V_36 : 0 ;
F_62 ( V_33 , V_37 , & V_34 -> V_26 ) ;
F_21 ( V_33 , V_38 , V_34 -> V_27 ) ;
F_22 ( V_33 , V_39 , V_34 -> V_16 ) ;
if ( V_35 )
F_23 ( V_33 , V_40 , V_35 ) ;
return 0 ;
V_41:
return 1 ;
}
static bool
F_63 ( struct V_32 * V_33 ,
const struct V_91 * V_34 )
{
const struct V_96 * V_97 =
( const struct V_96 * ) V_34 ;
T_1 V_35 = V_34 -> V_28 ? V_36 : 0 ;
F_62 ( V_33 , V_37 , & V_97 -> V_26 ) ;
F_21 ( V_33 , V_38 , V_34 -> V_27 ) ;
F_22 ( V_33 , V_39 , V_34 -> V_16 ) ;
if ( V_35 )
F_23 ( V_33 , V_40 , V_35 ) ;
F_23 ( V_33 , V_44 ,
F_25 ( F_26 ( V_97 -> V_45 ) ) ) ;
return 0 ;
V_41:
return 1 ;
}
static inline void
F_64 ( struct V_46 * V_47 ,
const struct V_91 * V_17 )
{
}
static int
F_65 ( struct V_49 * V_50 , const struct V_32 * V_33 ,
const struct V_51 * V_52 ,
enum V_53 V_54 , const struct V_55 * V_56 )
{
struct V_46 * V_47 = V_50 -> V_34 ;
T_3 V_57 = V_50 -> V_58 -> V_54 [ V_54 ] ;
struct V_91 V_34 = {
. V_27 = V_47 -> V_59 [ 0 ] . V_27 ? V_47 -> V_59 [ 0 ] . V_27 : V_60
} ;
int V_61 ;
if ( V_34 . V_27 == 0 )
return - V_62 ;
if ( V_54 == V_63 )
V_34 . V_27 = V_60 ;
F_66 ( V_33 , V_56 -> V_35 & V_64 , & V_34 . V_26 . V_92 ) ;
F_58 ( & V_34 . V_26 , V_34 . V_27 ) ;
if ( V_56 -> V_65 & V_36 ) {
#ifdef F_34
const struct V_66 * V_67 = V_33 -> V_67 ;
if ( ! V_67 )
return - V_62 ;
V_34 . V_16 = F_33 ? F_32 ( V_68 ) : F_32 ( V_69 ) ;
V_34 . V_28 = 1 ;
#else
V_34 . V_16 = NULL ;
#endif
} else
V_34 . V_16 = F_33 ? F_31 ( V_70 ) : F_31 ( V_71 ) ;
if ( ! V_34 . V_16 )
return - V_62 ;
V_61 = F_7 ( & V_47 -> V_72 , & V_34 . V_16 ) ;
if ( V_54 == V_73 ) {
if ( ! V_61 ) {
V_61 = F_9 ( & V_47 -> V_72 , & V_34 . V_16 ) ;
if ( V_61 )
return V_61 ;
}
} else if ( ! V_61 )
return V_61 ;
return V_57 ( V_50 , & V_34 , F_35 ( V_56 , V_47 ) , V_56 -> V_65 ) ;
}
static int
F_67 ( struct V_49 * V_50 , struct V_74 * V_75 [] ,
enum V_53 V_54 , T_1 * V_76 , T_1 V_35 , bool V_77 )
{
struct V_46 * V_47 = V_50 -> V_34 ;
T_3 V_57 = V_50 -> V_58 -> V_54 [ V_54 ] ;
struct V_91 V_34 = { . V_27 = V_60 } ;
T_1 V_45 = V_47 -> V_45 ;
char V_16 [ V_5 ] = {} ;
int V_61 ;
if ( F_37 ( ! V_75 [ V_37 ] ||
! V_75 [ V_39 ] ||
! F_38 ( V_75 , V_44 ) ||
! F_38 ( V_75 , V_40 ) ) )
return - V_80 ;
if ( F_37 ( V_75 [ V_85 ] ) )
return - V_98 ;
if ( V_75 [ V_81 ] )
* V_76 = F_39 ( V_75 [ V_81 ] ) ;
V_61 = F_68 ( V_75 [ V_37 ] , & V_34 . V_26 ) ;
if ( V_61 )
return V_61 ;
if ( V_75 [ V_38 ] )
V_34 . V_27 = F_41 ( V_75 [ V_38 ] ) ;
if ( ! V_34 . V_27 )
return - V_82 ;
F_58 ( & V_34 . V_26 , V_34 . V_27 ) ;
if ( V_75 [ V_44 ] ) {
if ( ! F_42 ( V_47 -> V_45 ) )
return - V_83 ;
V_45 = F_43 ( V_75 [ V_44 ] ) ;
}
strcpy ( V_16 , F_44 ( V_75 [ V_39 ] ) ) ;
V_34 . V_16 = V_16 ;
V_61 = F_7 ( & V_47 -> V_72 , & V_34 . V_16 ) ;
if ( V_54 == V_73 ) {
if ( ! V_61 ) {
V_61 = F_9 ( & V_47 -> V_72 , & V_34 . V_16 ) ;
if ( V_61 )
return V_61 ;
}
} else if ( ! V_61 )
return V_61 ;
if ( V_75 [ V_40 ] ) {
T_1 V_84 = F_45 ( V_75 [ V_40 ] ) ;
if ( V_84 & V_36 )
V_34 . V_28 = 1 ;
}
V_61 = V_57 ( V_50 , & V_34 , V_45 , V_35 ) ;
return F_47 ( V_61 , V_35 ) ? 0 : V_61 ;
}
static int
F_69 ( struct V_49 * V_50 , struct V_74 * V_75 [] , T_1 V_35 )
{
struct V_46 * V_47 ;
T_1 V_99 = V_100 , V_90 = V_101 ;
T_2 V_102 ;
if ( ! ( V_50 -> V_103 == V_104 || V_50 -> V_103 == V_105 ) )
return - V_106 ;
if ( F_37 ( ! F_38 ( V_75 , V_107 ) ||
! F_38 ( V_75 , V_108 ) ||
! F_38 ( V_75 , V_44 ) ) )
return - V_80 ;
if ( V_75 [ V_107 ] ) {
V_99 = F_45 ( V_75 [ V_107 ] ) ;
if ( V_99 < V_109 )
V_99 = V_109 ;
}
if ( V_75 [ V_108 ] )
V_90 = F_45 ( V_75 [ V_108 ] ) ;
V_47 = F_10 ( sizeof( * V_47 )
+ sizeof( struct V_110 )
* ( V_50 -> V_103 == V_104 ? 32 : 128 ) , V_111 ) ;
if ( ! V_47 )
return - V_21 ;
V_47 -> V_90 = V_90 ;
F_70 ( & V_47 -> V_112 , sizeof( V_47 -> V_112 ) ) ;
V_47 -> V_45 = V_113 ;
V_47 -> V_114 = V_115 ;
V_102 = F_71 ( V_99 ) ;
V_47 -> V_116 = F_72 (
sizeof( struct V_117 )
+ F_73 ( V_102 ) * sizeof( struct V_118 ) ) ;
if ( ! V_47 -> V_116 ) {
F_6 ( V_47 ) ;
return - V_21 ;
}
V_47 -> V_116 -> F_71 = V_102 ;
V_47 -> V_72 = V_15 ;
V_50 -> V_34 = V_47 ;
if ( V_75 [ V_44 ] ) {
V_47 -> V_45 = F_43 ( V_75 [ V_44 ] ) ;
V_50 -> V_58 = V_50 -> V_103 == V_104
? & V_119 : & V_120 ;
if ( V_50 -> V_103 == V_104 )
F_74 ( V_50 ) ;
else
F_75 ( V_50 ) ;
} else {
V_50 -> V_58 = V_50 -> V_103 == V_104
? & V_121 : & V_122 ;
}
F_76 ( L_1 ,
V_50 -> V_123 , F_73 ( V_47 -> V_116 -> F_71 ) ,
V_47 -> V_116 -> F_71 , V_47 -> V_90 , V_50 -> V_34 , V_47 -> V_116 ) ;
return 0 ;
}
static int T_5
F_77 ( void )
{
return F_78 ( & V_124 ) ;
}
static void T_6
F_79 ( void )
{
F_80 ( & V_124 ) ;
}
