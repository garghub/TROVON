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
return V_24 -> V_22 == 0 ;
}
static inline void
F_13 ( struct V_17 * V_25 ,
const struct V_17 * V_26 )
{
V_25 -> V_21 = V_26 -> V_21 ;
V_25 -> V_22 = V_26 -> V_22 ;
V_25 -> V_23 = V_26 -> V_23 ;
V_25 -> V_11 = V_26 -> V_11 ;
V_25 -> V_27 = V_26 -> V_27 ;
}
static inline void
F_14 ( struct V_17 * V_25 , T_1 V_28 )
{
V_25 -> V_27 = V_28 & V_29 ;
}
static inline bool
F_15 ( const struct V_17 * V_24 )
{
return ! V_24 -> V_27 ;
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
V_24 -> V_22 = 0 ;
}
static bool
F_19 ( struct V_30 * V_31 ,
const struct V_17 * V_32 )
{
T_1 V_28 = V_32 -> V_23 ? V_33 : 0 ;
if ( V_32 -> V_27 )
V_28 |= V_29 ;
if ( F_20 ( V_31 , V_34 , V_32 -> V_21 ) ||
F_21 ( V_31 , V_35 , V_32 -> V_22 ) ||
F_22 ( V_31 , V_36 , V_32 -> V_11 ) ||
( V_28 &&
F_23 ( V_31 , V_37 , F_24 ( V_28 ) ) ) )
goto V_38;
return 0 ;
V_38:
return 1 ;
}
static bool
F_25 ( struct V_30 * V_31 ,
const struct V_17 * V_32 )
{
const struct V_39 * V_40 =
( const struct V_39 * ) V_32 ;
T_1 V_28 = V_32 -> V_23 ? V_33 : 0 ;
if ( V_32 -> V_27 )
V_28 |= V_29 ;
if ( F_20 ( V_31 , V_34 , V_32 -> V_21 ) ||
F_21 ( V_31 , V_35 , V_32 -> V_22 ) ||
F_22 ( V_31 , V_36 , V_32 -> V_11 ) ||
( V_28 &&
F_23 ( V_31 , V_37 , F_24 ( V_28 ) ) ) ||
F_23 ( V_31 , V_41 ,
F_24 ( F_26 ( V_40 -> V_42 ) ) ) )
goto V_38;
return 0 ;
V_38:
return 1 ;
}
static inline void
F_27 ( struct V_43 * V_44 ,
const struct V_17 * V_12 )
{
V_44 -> V_45 . V_21 = F_28 ( V_12 -> V_21 ) ;
}
static int
F_29 ( struct V_46 * V_47 , const struct V_30 * V_31 ,
const struct V_48 * V_49 ,
enum V_50 V_51 , const struct V_52 * V_53 )
{
struct V_43 * V_44 = V_47 -> V_32 ;
T_3 V_54 = V_47 -> V_55 -> V_51 [ V_51 ] ;
struct V_17 V_32 = {
. V_22 = V_44 -> V_56 [ 0 ] . V_22 ? V_44 -> V_56 [ 0 ] . V_22 : V_57
} ;
int V_58 ;
if ( V_32 . V_22 == 0 )
return - V_59 ;
if ( V_51 == V_60 )
V_32 . V_22 = V_57 ;
F_30 ( V_31 , V_53 -> V_28 & V_61 , & V_32 . V_21 ) ;
V_32 . V_21 &= F_17 ( V_32 . V_22 ) ;
#define F_31 ( T_4 ) (par->dir ? par->dir->name : NULL)
#define F_32 ( T_4 ) (nf_bridge->dir ? nf_bridge->dir->name : NULL)
#define F_33 (opt->flags & IPSET_DIM_TWO_SRC)
if ( V_53 -> V_62 & V_33 ) {
#ifdef F_34
const struct V_63 * V_64 = V_31 -> V_64 ;
if ( ! V_64 )
return - V_59 ;
V_32 . V_11 = F_33 ? F_32 ( V_65 ) : F_32 ( V_66 ) ;
V_32 . V_23 = 1 ;
#else
V_32 . V_11 = NULL ;
#endif
} else
V_32 . V_11 = F_33 ? F_31 ( V_67 ) : F_31 ( V_68 ) ;
if ( ! V_32 . V_11 )
return - V_59 ;
V_58 = F_5 ( & V_44 -> V_69 , & V_32 . V_11 ) ;
if ( V_51 == V_70 ) {
if ( ! V_58 ) {
V_58 = F_7 ( & V_44 -> V_69 , & V_32 . V_11 ) ;
if ( V_58 )
return V_58 ;
}
} else if ( ! V_58 )
return V_58 ;
return V_54 ( V_47 , & V_32 , F_35 ( V_53 , V_44 ) , V_53 -> V_62 ) ;
}
static int
F_36 ( struct V_46 * V_47 , struct V_71 * V_72 [] ,
enum V_50 V_51 , T_1 * V_73 , T_1 V_28 , bool V_74 )
{
struct V_43 * V_44 = V_47 -> V_32 ;
T_3 V_54 = V_47 -> V_55 -> V_51 [ V_51 ] ;
struct V_17 V_32 = { . V_22 = V_57 } ;
T_1 V_21 = 0 , V_75 , V_76 ;
T_1 V_42 = V_44 -> V_42 ;
char V_11 [ V_77 ] ;
int V_58 ;
if ( F_37 ( ! V_72 [ V_34 ] ||
! V_72 [ V_36 ] ||
! F_38 ( V_72 , V_41 ) ||
! F_38 ( V_72 , V_37 ) ) )
return - V_78 ;
if ( V_72 [ V_79 ] )
* V_73 = F_39 ( V_72 [ V_79 ] ) ;
V_58 = F_40 ( V_72 [ V_34 ] , & V_21 ) ;
if ( V_58 )
return V_58 ;
if ( V_72 [ V_35 ] ) {
V_32 . V_22 = F_41 ( V_72 [ V_35 ] ) ;
if ( ! V_32 . V_22 || V_32 . V_22 > V_57 )
return - V_80 ;
}
if ( V_72 [ V_41 ] ) {
if ( ! F_42 ( V_44 -> V_42 ) )
return - V_81 ;
V_42 = F_43 ( V_72 [ V_41 ] ) ;
}
strcpy ( V_11 , F_44 ( V_72 [ V_36 ] ) ) ;
V_32 . V_11 = V_11 ;
V_58 = F_5 ( & V_44 -> V_69 , & V_32 . V_11 ) ;
if ( V_51 == V_70 ) {
if ( ! V_58 ) {
V_58 = F_7 ( & V_44 -> V_69 , & V_32 . V_11 ) ;
if ( V_58 )
return V_58 ;
}
} else if ( ! V_58 )
return V_58 ;
if ( V_72 [ V_37 ] ) {
T_1 V_82 = F_45 ( V_72 [ V_37 ] ) ;
if ( V_82 & V_33 )
V_32 . V_23 = 1 ;
if ( V_51 == V_70 && ( V_82 & V_29 ) )
V_28 |= ( V_82 << 16 ) ;
}
if ( V_51 == V_60 || ! V_72 [ V_83 ] ) {
V_32 . V_21 = F_24 ( V_21 & F_46 ( V_32 . V_22 ) ) ;
V_58 = V_54 ( V_47 , & V_32 , V_42 , V_28 ) ;
return F_47 ( V_58 , V_28 ) ? 0 : V_58 ;
}
if ( V_72 [ V_83 ] ) {
V_58 = F_40 ( V_72 [ V_83 ] , & V_75 ) ;
if ( V_58 )
return V_58 ;
if ( V_75 < V_21 )
F_48 ( V_21 , V_75 ) ;
if ( V_21 + V_84 == V_75 )
return - V_85 ;
} else {
F_49 ( V_21 , V_75 , V_32 . V_22 ) ;
}
if ( V_74 )
V_21 = V_44 -> V_45 . V_21 ;
while ( ! F_50 ( V_21 , V_75 ) ) {
V_32 . V_21 = F_24 ( V_21 ) ;
V_76 = F_51 ( V_21 , V_75 , & V_32 . V_22 ) ;
V_58 = V_54 ( V_47 , & V_32 , V_42 , V_28 ) ;
if ( V_58 && ! F_47 ( V_58 , V_28 ) )
return V_58 ;
else
V_58 = 0 ;
V_21 = V_76 + 1 ;
}
return V_58 ;
}
static bool
F_52 ( const struct V_46 * V_86 , const struct V_46 * V_87 )
{
const struct V_43 * V_88 = V_86 -> V_32 ;
const struct V_43 * V_89 = V_87 -> V_32 ;
return V_88 -> V_90 == V_89 -> V_90 &&
V_88 -> V_42 == V_89 -> V_42 ;
}
static inline bool
F_53 ( const struct V_91 * V_18 ,
const struct V_91 * V_19 ,
T_1 * V_20 )
{
return F_54 ( & V_18 -> V_21 . V_92 , & V_19 -> V_21 . V_92 ) == 0 &&
V_18 -> V_22 == V_19 -> V_22 &&
( ++ * V_20 ) &&
V_18 -> V_23 == V_19 -> V_23 &&
V_18 -> V_11 == V_19 -> V_11 ;
}
static inline bool
F_55 ( const struct V_91 * V_24 )
{
return V_24 -> V_22 == 0 ;
}
static inline void
F_56 ( struct V_91 * V_25 ,
const struct V_91 * V_26 )
{
memcpy ( V_25 , V_26 , sizeof( * V_25 ) ) ;
}
static inline void
F_57 ( struct V_91 * V_25 , T_1 V_28 )
{
V_25 -> V_27 = V_28 & V_29 ;
}
static inline bool
F_58 ( const struct V_91 * V_24 )
{
return ! V_24 -> V_27 ;
}
static inline void
F_59 ( struct V_91 * V_24 )
{
V_24 -> V_22 = 0 ;
}
static inline void
F_60 ( union V_93 * V_21 , T_2 V_94 )
{
V_21 -> V_95 [ 0 ] &= F_61 ( V_94 ) [ 0 ] ;
V_21 -> V_95 [ 1 ] &= F_61 ( V_94 ) [ 1 ] ;
V_21 -> V_95 [ 2 ] &= F_61 ( V_94 ) [ 2 ] ;
V_21 -> V_95 [ 3 ] &= F_61 ( V_94 ) [ 3 ] ;
}
static inline void
F_62 ( struct V_91 * V_24 , T_2 V_22 )
{
F_60 ( & V_24 -> V_21 , V_22 ) ;
V_24 -> V_22 = V_22 ;
}
static bool
F_63 ( struct V_30 * V_31 ,
const struct V_91 * V_32 )
{
T_1 V_28 = V_32 -> V_23 ? V_33 : 0 ;
if ( V_32 -> V_27 )
V_28 |= V_29 ;
if ( F_64 ( V_31 , V_34 , & V_32 -> V_21 . V_92 ) ||
F_21 ( V_31 , V_35 , V_32 -> V_22 ) ||
F_22 ( V_31 , V_36 , V_32 -> V_11 ) ||
( V_28 &&
F_23 ( V_31 , V_37 , F_24 ( V_28 ) ) ) )
goto V_38;
return 0 ;
V_38:
return 1 ;
}
static bool
F_65 ( struct V_30 * V_31 ,
const struct V_91 * V_32 )
{
const struct V_96 * V_97 =
( const struct V_96 * ) V_32 ;
T_1 V_28 = V_32 -> V_23 ? V_33 : 0 ;
if ( V_32 -> V_27 )
V_28 |= V_29 ;
if ( F_64 ( V_31 , V_34 , & V_97 -> V_21 . V_92 ) ||
F_21 ( V_31 , V_35 , V_32 -> V_22 ) ||
F_22 ( V_31 , V_36 , V_32 -> V_11 ) ||
( V_28 &&
F_23 ( V_31 , V_37 , F_24 ( V_28 ) ) ) ||
F_23 ( V_31 , V_41 ,
F_24 ( F_26 ( V_97 -> V_42 ) ) ) )
goto V_38;
return 0 ;
V_38:
return 1 ;
}
static inline void
F_66 ( struct V_43 * V_44 ,
const struct V_91 * V_12 )
{
}
static int
F_67 ( struct V_46 * V_47 , const struct V_30 * V_31 ,
const struct V_48 * V_49 ,
enum V_50 V_51 , const struct V_52 * V_53 )
{
struct V_43 * V_44 = V_47 -> V_32 ;
T_3 V_54 = V_47 -> V_55 -> V_51 [ V_51 ] ;
struct V_91 V_32 = {
. V_22 = V_44 -> V_56 [ 0 ] . V_22 ? V_44 -> V_56 [ 0 ] . V_22 : V_57
} ;
int V_58 ;
if ( V_32 . V_22 == 0 )
return - V_59 ;
if ( V_51 == V_60 )
V_32 . V_22 = V_57 ;
F_68 ( V_31 , V_53 -> V_28 & V_61 , & V_32 . V_21 . V_92 ) ;
F_60 ( & V_32 . V_21 , V_32 . V_22 ) ;
if ( V_53 -> V_62 & V_33 ) {
#ifdef F_34
const struct V_63 * V_64 = V_31 -> V_64 ;
if ( ! V_64 )
return - V_59 ;
V_32 . V_11 = F_33 ? F_32 ( V_65 ) : F_32 ( V_66 ) ;
V_32 . V_23 = 1 ;
#else
V_32 . V_11 = NULL ;
#endif
} else
V_32 . V_11 = F_33 ? F_31 ( V_67 ) : F_31 ( V_68 ) ;
if ( ! V_32 . V_11 )
return - V_59 ;
V_58 = F_5 ( & V_44 -> V_69 , & V_32 . V_11 ) ;
if ( V_51 == V_70 ) {
if ( ! V_58 ) {
V_58 = F_7 ( & V_44 -> V_69 , & V_32 . V_11 ) ;
if ( V_58 )
return V_58 ;
}
} else if ( ! V_58 )
return V_58 ;
return V_54 ( V_47 , & V_32 , F_35 ( V_53 , V_44 ) , V_53 -> V_62 ) ;
}
static int
F_69 ( struct V_46 * V_47 , struct V_71 * V_72 [] ,
enum V_50 V_51 , T_1 * V_73 , T_1 V_28 , bool V_74 )
{
struct V_43 * V_44 = V_47 -> V_32 ;
T_3 V_54 = V_47 -> V_55 -> V_51 [ V_51 ] ;
struct V_91 V_32 = { . V_22 = V_57 } ;
T_1 V_42 = V_44 -> V_42 ;
char V_11 [ V_77 ] ;
int V_58 ;
if ( F_37 ( ! V_72 [ V_34 ] ||
! V_72 [ V_36 ] ||
! F_38 ( V_72 , V_41 ) ||
! F_38 ( V_72 , V_37 ) ) )
return - V_78 ;
if ( F_37 ( V_72 [ V_83 ] ) )
return - V_98 ;
if ( V_72 [ V_79 ] )
* V_73 = F_39 ( V_72 [ V_79 ] ) ;
V_58 = F_70 ( V_72 [ V_34 ] , & V_32 . V_21 ) ;
if ( V_58 )
return V_58 ;
if ( V_72 [ V_35 ] )
V_32 . V_22 = F_41 ( V_72 [ V_35 ] ) ;
if ( ! V_32 . V_22 || V_32 . V_22 > V_57 )
return - V_80 ;
F_60 ( & V_32 . V_21 , V_32 . V_22 ) ;
if ( V_72 [ V_41 ] ) {
if ( ! F_42 ( V_44 -> V_42 ) )
return - V_81 ;
V_42 = F_43 ( V_72 [ V_41 ] ) ;
}
strcpy ( V_11 , F_44 ( V_72 [ V_36 ] ) ) ;
V_32 . V_11 = V_11 ;
V_58 = F_5 ( & V_44 -> V_69 , & V_32 . V_11 ) ;
if ( V_51 == V_70 ) {
if ( ! V_58 ) {
V_58 = F_7 ( & V_44 -> V_69 , & V_32 . V_11 ) ;
if ( V_58 )
return V_58 ;
}
} else if ( ! V_58 )
return V_58 ;
if ( V_72 [ V_37 ] ) {
T_1 V_82 = F_45 ( V_72 [ V_37 ] ) ;
if ( V_82 & V_33 )
V_32 . V_23 = 1 ;
if ( V_51 == V_70 && ( V_82 & V_29 ) )
V_28 |= ( V_82 << 16 ) ;
}
V_58 = V_54 ( V_47 , & V_32 , V_42 , V_28 ) ;
return F_47 ( V_58 , V_28 ) ? 0 : V_58 ;
}
static int
F_71 ( struct V_46 * V_47 , struct V_71 * V_72 [] , T_1 V_28 )
{
struct V_43 * V_44 ;
T_1 V_99 = V_100 , V_90 = V_101 ;
T_2 V_102 ;
T_5 V_103 ;
if ( ! ( V_47 -> V_104 == V_105 || V_47 -> V_104 == V_106 ) )
return - V_107 ;
if ( F_37 ( ! F_38 ( V_72 , V_108 ) ||
! F_38 ( V_72 , V_109 ) ||
! F_38 ( V_72 , V_41 ) ) )
return - V_78 ;
if ( V_72 [ V_108 ] ) {
V_99 = F_45 ( V_72 [ V_108 ] ) ;
if ( V_99 < V_110 )
V_99 = V_110 ;
}
if ( V_72 [ V_109 ] )
V_90 = F_45 ( V_72 [ V_109 ] ) ;
V_44 = F_8 ( sizeof( * V_44 )
+ sizeof( struct V_111 )
* ( V_47 -> V_104 == V_105 ? 32 : 128 ) , V_112 ) ;
if ( ! V_44 )
return - V_16 ;
V_44 -> V_90 = V_90 ;
F_72 ( & V_44 -> V_113 , sizeof( V_44 -> V_113 ) ) ;
V_44 -> V_42 = V_114 ;
V_44 -> V_115 = V_116 ;
V_102 = F_73 ( V_99 ) ;
V_103 = F_74 ( V_102 ) ;
if ( V_103 == 0 ) {
F_4 ( V_44 ) ;
return - V_16 ;
}
V_44 -> V_117 = F_75 ( V_103 ) ;
if ( ! V_44 -> V_117 ) {
F_4 ( V_44 ) ;
return - V_16 ;
}
V_44 -> V_117 -> F_73 = V_102 ;
V_44 -> V_69 = V_10 ;
V_47 -> V_32 = V_44 ;
if ( V_72 [ V_41 ] ) {
V_44 -> V_42 = F_43 ( V_72 [ V_41 ] ) ;
V_47 -> V_55 = V_47 -> V_104 == V_105
? & V_118 : & V_119 ;
if ( V_47 -> V_104 == V_105 )
F_76 ( V_47 ) ;
else
F_77 ( V_47 ) ;
} else {
V_47 -> V_55 = V_47 -> V_104 == V_105
? & V_120 : & V_121 ;
}
F_78 ( L_1 ,
V_47 -> V_122 , F_79 ( V_44 -> V_117 -> F_73 ) ,
V_44 -> V_117 -> F_73 , V_44 -> V_90 , V_47 -> V_32 , V_44 -> V_117 ) ;
return 0 ;
}
static int T_6
F_80 ( void )
{
return F_81 ( & V_123 ) ;
}
static void T_7
F_82 ( void )
{
F_83 ( & V_123 ) ;
}
