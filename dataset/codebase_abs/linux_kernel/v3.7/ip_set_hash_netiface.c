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
static inline bool
F_12 ( const struct V_17 * V_24 )
{
return V_24 -> V_24 == 0 ;
}
static inline void
F_13 ( struct V_17 * V_25 ,
const struct V_17 * V_26 )
{
memcpy ( V_25 , V_26 , sizeof( * V_25 ) ) ;
}
static inline void
F_14 ( struct V_17 * V_25 , T_1 V_27 )
{
V_25 -> V_28 = V_27 & V_29 ;
}
static inline int
F_15 ( const struct V_17 * V_24 )
{
return V_24 -> V_28 ? - V_30 : 1 ;
}
static inline void
F_16 ( struct V_17 * V_24 , T_2 V_22 )
{
V_24 -> V_21 &= F_17 ( V_22 ) ;
V_24 -> V_22 = V_22 ;
}
static inline void
F_18 ( struct V_17 * V_24 )
{
V_24 -> V_24 = 0 ;
}
static bool
F_19 ( struct V_31 * V_32 ,
const struct V_17 * V_33 )
{
T_1 V_27 = V_33 -> V_23 ? V_34 : 0 ;
if ( V_33 -> V_28 )
V_27 |= V_29 ;
if ( F_20 ( V_32 , V_35 , V_33 -> V_21 ) ||
F_21 ( V_32 , V_36 , V_33 -> V_22 ) ||
F_22 ( V_32 , V_37 , V_33 -> V_11 ) ||
( V_27 &&
F_23 ( V_32 , V_38 , F_24 ( V_27 ) ) ) )
goto V_39;
return 0 ;
V_39:
return 1 ;
}
static bool
F_25 ( struct V_31 * V_32 ,
const struct V_17 * V_33 )
{
const struct V_40 * V_41 =
( const struct V_40 * ) V_33 ;
T_1 V_27 = V_33 -> V_23 ? V_34 : 0 ;
if ( V_33 -> V_28 )
V_27 |= V_29 ;
if ( F_20 ( V_32 , V_35 , V_33 -> V_21 ) ||
F_21 ( V_32 , V_36 , V_33 -> V_22 ) ||
F_22 ( V_32 , V_37 , V_33 -> V_11 ) ||
( V_27 &&
F_23 ( V_32 , V_38 , F_24 ( V_27 ) ) ) ||
F_23 ( V_32 , V_42 ,
F_24 ( F_26 ( V_41 -> V_43 ) ) ) )
goto V_39;
return 0 ;
V_39:
return 1 ;
}
static inline void
F_27 ( struct V_44 * V_45 ,
const struct V_17 * V_12 )
{
V_45 -> V_46 . V_21 = V_12 -> V_21 ;
}
static int
F_28 ( struct V_47 * V_48 , const struct V_31 * V_32 ,
const struct V_49 * V_50 ,
enum V_51 V_52 , const struct V_53 * V_54 )
{
struct V_44 * V_45 = V_48 -> V_33 ;
T_3 V_55 = V_48 -> V_56 -> V_52 [ V_52 ] ;
struct V_17 V_33 = {
. V_22 = V_45 -> V_57 [ 0 ] . V_22 ? V_45 -> V_57 [ 0 ] . V_22 : V_58 ,
. V_24 = 1 ,
} ;
int V_59 ;
if ( V_33 . V_22 == 0 )
return - V_60 ;
if ( V_52 == V_61 )
V_33 . V_22 = V_58 ;
F_29 ( V_32 , V_54 -> V_27 & V_62 , & V_33 . V_21 ) ;
V_33 . V_21 &= F_17 ( V_33 . V_22 ) ;
#define F_30 ( T_4 ) (par->dir ? par->dir->name : NULL)
#define F_31 ( T_4 ) (nf_bridge->dir ? nf_bridge->dir->name : NULL)
#define F_32 (opt->flags & IPSET_DIM_TWO_SRC)
if ( V_54 -> V_63 & V_34 ) {
#ifdef F_33
const struct V_64 * V_65 = V_32 -> V_65 ;
if ( ! V_65 )
return - V_60 ;
V_33 . V_11 = F_32 ? F_31 ( V_66 ) : F_31 ( V_67 ) ;
V_33 . V_23 = 1 ;
#else
V_33 . V_11 = NULL ;
#endif
} else
V_33 . V_11 = F_32 ? F_30 ( V_68 ) : F_30 ( V_69 ) ;
if ( ! V_33 . V_11 )
return - V_60 ;
V_59 = F_5 ( & V_45 -> V_70 , & V_33 . V_11 ) ;
if ( V_52 == V_71 ) {
if ( ! V_59 ) {
V_59 = F_7 ( & V_45 -> V_70 , & V_33 . V_11 ) ;
if ( V_59 )
return V_59 ;
}
} else if ( ! V_59 )
return V_59 ;
return V_55 ( V_48 , & V_33 , F_34 ( V_54 , V_45 ) , V_54 -> V_63 ) ;
}
static int
F_35 ( struct V_47 * V_48 , struct V_72 * V_73 [] ,
enum V_51 V_52 , T_1 * V_74 , T_1 V_27 , bool V_75 )
{
struct V_44 * V_45 = V_48 -> V_33 ;
T_3 V_55 = V_48 -> V_56 -> V_52 [ V_52 ] ;
struct V_17 V_33 = { . V_22 = V_58 , . V_24 = 1 } ;
T_1 V_21 = 0 , V_76 , V_77 ;
T_1 V_43 = V_45 -> V_43 ;
char V_11 [ V_78 ] ;
int V_59 ;
if ( F_36 ( ! V_73 [ V_35 ] ||
! V_73 [ V_37 ] ||
! F_37 ( V_73 , V_42 ) ||
! F_37 ( V_73 , V_38 ) ) )
return - V_79 ;
if ( V_73 [ V_80 ] )
* V_74 = F_38 ( V_73 [ V_80 ] ) ;
V_59 = F_39 ( V_73 [ V_35 ] , & V_21 ) ;
if ( V_59 )
return V_59 ;
if ( V_73 [ V_36 ] ) {
V_33 . V_22 = F_40 ( V_73 [ V_36 ] ) ;
if ( V_33 . V_22 > V_58 )
return - V_81 ;
}
if ( V_73 [ V_42 ] ) {
if ( ! F_41 ( V_45 -> V_43 ) )
return - V_82 ;
V_43 = F_42 ( V_73 [ V_42 ] ) ;
}
strcpy ( V_11 , F_43 ( V_73 [ V_37 ] ) ) ;
V_33 . V_11 = V_11 ;
V_59 = F_5 ( & V_45 -> V_70 , & V_33 . V_11 ) ;
if ( V_52 == V_71 ) {
if ( ! V_59 ) {
V_59 = F_7 ( & V_45 -> V_70 , & V_33 . V_11 ) ;
if ( V_59 )
return V_59 ;
}
} else if ( ! V_59 )
return V_59 ;
if ( V_73 [ V_38 ] ) {
T_1 V_83 = F_44 ( V_73 [ V_38 ] ) ;
if ( V_83 & V_34 )
V_33 . V_23 = 1 ;
if ( V_52 == V_71 && ( V_83 & V_29 ) )
V_27 |= ( V_83 << 16 ) ;
}
if ( V_52 == V_61 || ! V_73 [ V_84 ] ) {
V_33 . V_21 = F_24 ( V_21 & F_45 ( V_33 . V_22 ) ) ;
V_59 = V_55 ( V_48 , & V_33 , V_43 , V_27 ) ;
return F_46 ( V_59 , V_27 ) ? 0 : V_59 ;
}
if ( V_73 [ V_84 ] ) {
V_59 = F_39 ( V_73 [ V_84 ] , & V_76 ) ;
if ( V_59 )
return V_59 ;
if ( V_76 < V_21 )
F_47 ( V_21 , V_76 ) ;
if ( V_21 + V_85 == V_76 )
return - V_86 ;
} else {
F_48 ( V_21 , V_76 , V_33 . V_22 ) ;
}
if ( V_75 )
V_21 = F_49 ( V_45 -> V_46 . V_21 ) ;
while ( ! F_50 ( V_21 , V_76 ) ) {
V_33 . V_21 = F_24 ( V_21 ) ;
V_77 = F_51 ( V_21 , V_76 , & V_33 . V_22 ) ;
V_59 = V_55 ( V_48 , & V_33 , V_43 , V_27 ) ;
if ( V_59 && ! F_46 ( V_59 , V_27 ) )
return V_59 ;
else
V_59 = 0 ;
V_21 = V_77 + 1 ;
}
return V_59 ;
}
static bool
F_52 ( const struct V_47 * V_87 , const struct V_47 * V_88 )
{
const struct V_44 * V_89 = V_87 -> V_33 ;
const struct V_44 * V_90 = V_88 -> V_33 ;
return V_89 -> V_91 == V_90 -> V_91 &&
V_89 -> V_43 == V_90 -> V_43 ;
}
static inline bool
F_53 ( const struct V_92 * V_18 ,
const struct V_92 * V_19 ,
T_1 * V_20 )
{
return F_54 ( & V_18 -> V_21 . V_93 , & V_19 -> V_21 . V_93 ) == 0 &&
V_18 -> V_22 == V_19 -> V_22 &&
( ++ * V_20 ) &&
V_18 -> V_23 == V_19 -> V_23 &&
V_18 -> V_11 == V_19 -> V_11 ;
}
static inline bool
F_55 ( const struct V_92 * V_24 )
{
return V_24 -> V_24 == 0 ;
}
static inline void
F_56 ( struct V_92 * V_25 ,
const struct V_92 * V_26 )
{
memcpy ( V_25 , V_26 , sizeof( * V_25 ) ) ;
}
static inline void
F_57 ( struct V_92 * V_25 , T_1 V_27 )
{
V_25 -> V_28 = V_27 & V_29 ;
}
static inline int
F_58 ( const struct V_92 * V_24 )
{
return V_24 -> V_28 ? - V_30 : 1 ;
}
static inline void
F_59 ( struct V_92 * V_24 )
{
V_24 -> V_24 = 0 ;
}
static inline void
F_60 ( union V_94 * V_21 , T_2 V_95 )
{
V_21 -> V_96 [ 0 ] &= F_61 ( V_95 ) [ 0 ] ;
V_21 -> V_96 [ 1 ] &= F_61 ( V_95 ) [ 1 ] ;
V_21 -> V_96 [ 2 ] &= F_61 ( V_95 ) [ 2 ] ;
V_21 -> V_96 [ 3 ] &= F_61 ( V_95 ) [ 3 ] ;
}
static inline void
F_62 ( struct V_92 * V_24 , T_2 V_22 )
{
F_60 ( & V_24 -> V_21 , V_22 ) ;
V_24 -> V_22 = V_22 ;
}
static bool
F_63 ( struct V_31 * V_32 ,
const struct V_92 * V_33 )
{
T_1 V_27 = V_33 -> V_23 ? V_34 : 0 ;
if ( V_33 -> V_28 )
V_27 |= V_29 ;
if ( F_64 ( V_32 , V_35 , & V_33 -> V_21 . V_93 ) ||
F_21 ( V_32 , V_36 , V_33 -> V_22 ) ||
F_22 ( V_32 , V_37 , V_33 -> V_11 ) ||
( V_27 &&
F_23 ( V_32 , V_38 , F_24 ( V_27 ) ) ) )
goto V_39;
return 0 ;
V_39:
return 1 ;
}
static bool
F_65 ( struct V_31 * V_32 ,
const struct V_92 * V_33 )
{
const struct V_97 * V_98 =
( const struct V_97 * ) V_33 ;
T_1 V_27 = V_33 -> V_23 ? V_34 : 0 ;
if ( V_33 -> V_28 )
V_27 |= V_29 ;
if ( F_64 ( V_32 , V_35 , & V_98 -> V_21 . V_93 ) ||
F_21 ( V_32 , V_36 , V_33 -> V_22 ) ||
F_22 ( V_32 , V_37 , V_33 -> V_11 ) ||
( V_27 &&
F_23 ( V_32 , V_38 , F_24 ( V_27 ) ) ) ||
F_23 ( V_32 , V_42 ,
F_24 ( F_26 ( V_98 -> V_43 ) ) ) )
goto V_39;
return 0 ;
V_39:
return 1 ;
}
static inline void
F_66 ( struct V_44 * V_45 ,
const struct V_92 * V_12 )
{
}
static int
F_67 ( struct V_47 * V_48 , const struct V_31 * V_32 ,
const struct V_49 * V_50 ,
enum V_51 V_52 , const struct V_53 * V_54 )
{
struct V_44 * V_45 = V_48 -> V_33 ;
T_3 V_55 = V_48 -> V_56 -> V_52 [ V_52 ] ;
struct V_92 V_33 = {
. V_22 = V_45 -> V_57 [ 0 ] . V_22 ? V_45 -> V_57 [ 0 ] . V_22 : V_58 ,
. V_24 = 1 ,
} ;
int V_59 ;
if ( V_33 . V_22 == 0 )
return - V_60 ;
if ( V_52 == V_61 )
V_33 . V_22 = V_58 ;
F_68 ( V_32 , V_54 -> V_27 & V_62 , & V_33 . V_21 . V_93 ) ;
F_60 ( & V_33 . V_21 , V_33 . V_22 ) ;
if ( V_54 -> V_63 & V_34 ) {
#ifdef F_33
const struct V_64 * V_65 = V_32 -> V_65 ;
if ( ! V_65 )
return - V_60 ;
V_33 . V_11 = F_32 ? F_31 ( V_66 ) : F_31 ( V_67 ) ;
V_33 . V_23 = 1 ;
#else
V_33 . V_11 = NULL ;
#endif
} else
V_33 . V_11 = F_32 ? F_30 ( V_68 ) : F_30 ( V_69 ) ;
if ( ! V_33 . V_11 )
return - V_60 ;
V_59 = F_5 ( & V_45 -> V_70 , & V_33 . V_11 ) ;
if ( V_52 == V_71 ) {
if ( ! V_59 ) {
V_59 = F_7 ( & V_45 -> V_70 , & V_33 . V_11 ) ;
if ( V_59 )
return V_59 ;
}
} else if ( ! V_59 )
return V_59 ;
return V_55 ( V_48 , & V_33 , F_34 ( V_54 , V_45 ) , V_54 -> V_63 ) ;
}
static int
F_69 ( struct V_47 * V_48 , struct V_72 * V_73 [] ,
enum V_51 V_52 , T_1 * V_74 , T_1 V_27 , bool V_75 )
{
struct V_44 * V_45 = V_48 -> V_33 ;
T_3 V_55 = V_48 -> V_56 -> V_52 [ V_52 ] ;
struct V_92 V_33 = { . V_22 = V_58 , . V_24 = 1 } ;
T_1 V_43 = V_45 -> V_43 ;
char V_11 [ V_78 ] ;
int V_59 ;
if ( F_36 ( ! V_73 [ V_35 ] ||
! V_73 [ V_37 ] ||
! F_37 ( V_73 , V_42 ) ||
! F_37 ( V_73 , V_38 ) ) )
return - V_79 ;
if ( F_36 ( V_73 [ V_84 ] ) )
return - V_99 ;
if ( V_73 [ V_80 ] )
* V_74 = F_38 ( V_73 [ V_80 ] ) ;
V_59 = F_70 ( V_73 [ V_35 ] , & V_33 . V_21 ) ;
if ( V_59 )
return V_59 ;
if ( V_73 [ V_36 ] )
V_33 . V_22 = F_40 ( V_73 [ V_36 ] ) ;
if ( V_33 . V_22 > V_58 )
return - V_81 ;
F_60 ( & V_33 . V_21 , V_33 . V_22 ) ;
if ( V_73 [ V_42 ] ) {
if ( ! F_41 ( V_45 -> V_43 ) )
return - V_82 ;
V_43 = F_42 ( V_73 [ V_42 ] ) ;
}
strcpy ( V_11 , F_43 ( V_73 [ V_37 ] ) ) ;
V_33 . V_11 = V_11 ;
V_59 = F_5 ( & V_45 -> V_70 , & V_33 . V_11 ) ;
if ( V_52 == V_71 ) {
if ( ! V_59 ) {
V_59 = F_7 ( & V_45 -> V_70 , & V_33 . V_11 ) ;
if ( V_59 )
return V_59 ;
}
} else if ( ! V_59 )
return V_59 ;
if ( V_73 [ V_38 ] ) {
T_1 V_83 = F_44 ( V_73 [ V_38 ] ) ;
if ( V_83 & V_34 )
V_33 . V_23 = 1 ;
if ( V_52 == V_71 && ( V_83 & V_29 ) )
V_27 |= ( V_83 << 16 ) ;
}
V_59 = V_55 ( V_48 , & V_33 , V_43 , V_27 ) ;
return F_46 ( V_59 , V_27 ) ? 0 : V_59 ;
}
static int
F_71 ( struct V_47 * V_48 , struct V_72 * V_73 [] , T_1 V_27 )
{
struct V_44 * V_45 ;
T_1 V_100 = V_101 , V_91 = V_102 ;
T_2 V_103 ;
T_5 V_104 ;
if ( ! ( V_48 -> V_105 == V_106 || V_48 -> V_105 == V_107 ) )
return - V_108 ;
if ( F_36 ( ! F_37 ( V_73 , V_109 ) ||
! F_37 ( V_73 , V_110 ) ||
! F_37 ( V_73 , V_42 ) ) )
return - V_79 ;
if ( V_73 [ V_109 ] ) {
V_100 = F_44 ( V_73 [ V_109 ] ) ;
if ( V_100 < V_111 )
V_100 = V_111 ;
}
if ( V_73 [ V_110 ] )
V_91 = F_44 ( V_73 [ V_110 ] ) ;
V_45 = F_8 ( sizeof( * V_45 )
+ sizeof( struct V_112 )
* ( V_48 -> V_105 == V_106 ? 32 : 128 ) , V_113 ) ;
if ( ! V_45 )
return - V_16 ;
V_45 -> V_91 = V_91 ;
F_72 ( & V_45 -> V_114 , sizeof( V_45 -> V_114 ) ) ;
V_45 -> V_43 = V_115 ;
V_45 -> V_116 = V_117 ;
V_103 = F_73 ( V_100 ) ;
V_104 = F_74 ( V_103 ) ;
if ( V_104 == 0 ) {
F_4 ( V_45 ) ;
return - V_16 ;
}
V_45 -> V_118 = F_75 ( V_104 ) ;
if ( ! V_45 -> V_118 ) {
F_4 ( V_45 ) ;
return - V_16 ;
}
V_45 -> V_118 -> F_73 = V_103 ;
V_45 -> V_70 = V_10 ;
V_48 -> V_33 = V_45 ;
if ( V_73 [ V_42 ] ) {
V_45 -> V_43 = F_42 ( V_73 [ V_42 ] ) ;
V_48 -> V_56 = V_48 -> V_105 == V_106
? & V_119 : & V_120 ;
if ( V_48 -> V_105 == V_106 )
F_76 ( V_48 ) ;
else
F_77 ( V_48 ) ;
} else {
V_48 -> V_56 = V_48 -> V_105 == V_106
? & V_121 : & V_122 ;
}
F_78 ( L_1 ,
V_48 -> V_123 , F_79 ( V_45 -> V_118 -> F_73 ) ,
V_45 -> V_118 -> F_73 , V_45 -> V_91 , V_48 -> V_33 , V_45 -> V_118 ) ;
return 0 ;
}
static int T_6
F_80 ( void )
{
return F_81 ( & V_124 ) ;
}
static void T_7
F_82 ( void )
{
F_83 ( & V_124 ) ;
}
