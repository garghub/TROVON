int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
F_2 ( & V_3 -> V_4 ) ;
F_3 ( V_5 ) ;
F_4 ( & V_3 -> V_6 , & V_1 -> V_7 . V_8 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_6 ( struct V_2 * V_3 )
{
F_3 ( V_5 ) ;
F_7 ( & V_3 -> V_6 ) ;
F_5 ( V_5 ) ;
}
static struct V_2 * F_8 ( struct V_1 * V_1 , int V_9 )
{
struct V_2 * V_3 ;
F_9 (afi, &net->nft.af_info, list) {
if ( V_3 -> V_9 == V_9 )
return V_3 ;
}
return NULL ;
}
static struct V_2 *
F_10 ( struct V_1 * V_1 , int V_9 , bool V_10 )
{
struct V_2 * V_3 ;
V_3 = F_8 ( V_1 , V_9 ) ;
if ( V_3 != NULL )
return V_3 ;
#ifdef F_11
if ( V_10 ) {
F_5 ( V_5 ) ;
F_12 ( L_1 , V_9 ) ;
F_3 ( V_5 ) ;
V_3 = F_8 ( V_1 , V_9 ) ;
if ( V_3 != NULL )
return F_13 ( - V_11 ) ;
}
#endif
return F_13 ( - V_12 ) ;
}
static void F_14 ( struct V_13 * V_14 ,
const struct V_15 * V_16 ,
const struct V_17 * V_18 ,
struct V_2 * V_3 ,
struct V_19 * V_20 ,
struct V_21 * V_22 ,
const struct V_23 * const * V_24 )
{
V_14 -> V_1 = F_15 ( V_16 -> V_25 ) ;
V_14 -> V_3 = V_3 ;
V_14 -> V_20 = V_20 ;
V_14 -> V_22 = V_22 ;
V_14 -> V_24 = V_24 ;
V_14 -> V_26 = F_16 ( V_16 ) . V_26 ;
V_14 -> V_27 = F_17 ( V_18 ) ;
V_14 -> V_28 = V_18 -> V_29 ;
}
static struct V_30 * F_18 ( struct V_13 * V_14 , int V_31 ,
T_1 V_32 )
{
struct V_30 * V_33 ;
V_33 = F_19 ( sizeof( struct V_30 ) + V_32 , V_34 ) ;
if ( V_33 == NULL )
return NULL ;
V_33 -> V_31 = V_31 ;
V_33 -> V_14 = * V_14 ;
return V_33 ;
}
static void F_20 ( struct V_30 * V_33 )
{
F_21 ( & V_33 -> V_6 ) ;
F_22 ( V_33 ) ;
}
static void F_23 ( const struct V_19 * V_20 ,
const struct V_21 * V_22 ,
unsigned int V_35 )
{
if ( ! ( V_20 -> V_36 & V_37 ) &&
V_22 -> V_36 & V_38 )
F_24 ( F_25 ( V_22 ) -> V_39 , V_35 ) ;
}
static int F_26 ( struct V_13 * V_14 , int V_31 )
{
struct V_30 * V_33 ;
V_33 = F_18 ( V_14 , V_31 , sizeof( struct V_40 ) ) ;
if ( V_33 == NULL )
return - V_41 ;
if ( V_31 == V_42 )
V_14 -> V_20 -> V_36 |= V_43 ;
F_27 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_44 ) ;
return 0 ;
}
static int F_28 ( struct V_13 * V_14 )
{
int V_45 ;
V_45 = F_26 ( V_14 , V_46 ) ;
if ( V_45 < 0 )
return V_45 ;
F_7 ( & V_14 -> V_20 -> V_6 ) ;
return V_45 ;
}
static int F_29 ( struct V_13 * V_14 , int V_31 )
{
struct V_30 * V_33 ;
V_33 = F_18 ( V_14 , V_31 , sizeof( struct V_47 ) ) ;
if ( V_33 == NULL )
return - V_41 ;
if ( V_31 == V_48 )
V_14 -> V_22 -> V_36 |= V_49 ;
F_27 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_44 ) ;
return 0 ;
}
static int F_30 ( struct V_13 * V_14 )
{
int V_45 ;
V_45 = F_29 ( V_14 , V_50 ) ;
if ( V_45 < 0 )
return V_45 ;
V_14 -> V_20 -> V_51 -- ;
F_7 ( & V_14 -> V_22 -> V_6 ) ;
return V_45 ;
}
static inline bool
F_31 ( struct V_1 * V_1 , const struct V_52 * V_53 )
{
return ( V_53 -> V_54 & ( 1 << V_1 -> V_7 . V_55 ) ) == 0 ;
}
static inline int F_32 ( struct V_1 * V_1 )
{
return V_1 -> V_7 . V_55 + 1 == 1 ? 1 : 0 ;
}
static inline int
F_33 ( struct V_1 * V_1 , const struct V_52 * V_53 )
{
return ( V_53 -> V_54 & ( 1 << F_32 ( V_1 ) ) ) == 0 ;
}
static inline void
F_34 ( struct V_1 * V_1 , struct V_52 * V_53 )
{
V_53 -> V_54 = ( 1 << V_1 -> V_7 . V_55 ) ;
}
static inline void
F_35 ( struct V_1 * V_1 , struct V_52 * V_53 )
{
V_53 -> V_54 = ( 1 << F_32 ( V_1 ) ) ;
}
static inline void F_36 ( struct V_1 * V_1 , struct V_52 * V_53 )
{
V_53 -> V_54 = 0 ;
}
static int
F_37 ( struct V_13 * V_14 , struct V_52 * V_53 )
{
if ( F_33 ( V_14 -> V_1 , V_53 ) ) {
F_35 ( V_14 -> V_1 , V_53 ) ;
V_14 -> V_22 -> V_51 -- ;
return 0 ;
}
return - V_56 ;
}
static struct V_30 * F_38 ( struct V_13 * V_14 , int V_31 ,
struct V_52 * V_53 )
{
struct V_30 * V_33 ;
V_33 = F_18 ( V_14 , V_31 , sizeof( struct V_57 ) ) ;
if ( V_33 == NULL )
return NULL ;
V_57 ( V_33 ) = V_53 ;
F_27 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_44 ) ;
return V_33 ;
}
static int F_39 ( struct V_13 * V_14 , struct V_52 * V_53 )
{
struct V_30 * V_33 ;
int V_45 ;
V_33 = F_38 ( V_14 , V_58 , V_53 ) ;
if ( V_33 == NULL )
return - V_41 ;
V_45 = F_37 ( V_14 , V_53 ) ;
if ( V_45 < 0 ) {
F_20 ( V_33 ) ;
return V_45 ;
}
return 0 ;
}
static int F_40 ( struct V_13 * V_14 )
{
struct V_52 * V_53 ;
int V_45 ;
F_9 (rule, &ctx->chain->rules, list) {
V_45 = F_39 ( V_14 , V_53 ) ;
if ( V_45 < 0 )
return V_45 ;
}
return 0 ;
}
static int F_41 ( struct V_13 * V_14 , int V_31 ,
struct V_59 * V_60 )
{
struct V_30 * V_33 ;
V_33 = F_18 ( V_14 , V_31 , sizeof( struct V_61 ) ) ;
if ( V_33 == NULL )
return - V_41 ;
if ( V_31 == V_62 && V_14 -> V_24 [ V_63 ] != NULL ) {
F_42 ( V_33 ) =
F_43 ( F_44 ( V_14 -> V_24 [ V_63 ] ) ) ;
V_60 -> V_36 |= V_64 ;
}
V_61 ( V_33 ) = V_60 ;
F_27 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_44 ) ;
return 0 ;
}
static int F_45 ( struct V_13 * V_14 , struct V_59 * V_60 )
{
int V_45 ;
V_45 = F_41 ( V_14 , V_65 , V_60 ) ;
if ( V_45 < 0 )
return V_45 ;
F_7 ( & V_60 -> V_6 ) ;
V_14 -> V_20 -> V_51 -- ;
return V_45 ;
}
static struct V_19 * F_46 ( const struct V_2 * V_3 ,
const struct V_23 * V_24 )
{
struct V_19 * V_20 ;
F_9 (table, &afi->tables, list) {
if ( ! F_47 ( V_24 , V_20 -> V_66 ) )
return V_20 ;
}
return NULL ;
}
static struct V_19 * F_48 ( const struct V_2 * V_3 ,
const struct V_23 * V_24 )
{
struct V_19 * V_20 ;
if ( V_24 == NULL )
return F_13 ( - V_67 ) ;
V_20 = F_46 ( V_3 , V_24 ) ;
if ( V_20 != NULL )
return V_20 ;
return F_13 ( - V_56 ) ;
}
static inline T_2 F_49 ( struct V_19 * V_20 )
{
return ++ V_20 -> V_68 ;
}
static const struct V_69 *
F_50 ( int V_9 , const struct V_23 * V_24 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < V_71 ; V_70 ++ ) {
if ( V_72 [ V_9 ] [ V_70 ] != NULL &&
! F_47 ( V_24 , V_72 [ V_9 ] [ V_70 ] -> V_66 ) )
return V_72 [ V_9 ] [ V_70 ] ;
}
return NULL ;
}
static const struct V_69 *
F_51 ( const struct V_2 * V_3 ,
const struct V_23 * V_24 ,
bool V_10 )
{
const struct V_69 * type ;
type = F_50 ( V_3 -> V_9 , V_24 ) ;
if ( type != NULL )
return type ;
#ifdef F_11
if ( V_10 ) {
F_5 ( V_5 ) ;
F_12 ( L_2 , V_3 -> V_9 ,
F_52 ( V_24 ) , ( const char * ) F_53 ( V_24 ) ) ;
F_3 ( V_5 ) ;
type = F_50 ( V_3 -> V_9 , V_24 ) ;
if ( type != NULL )
return F_13 ( - V_11 ) ;
}
#endif
return F_13 ( - V_56 ) ;
}
static int F_54 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_26 , T_1 V_28 , int V_73 , T_1 V_36 ,
int V_9 , const struct V_19 * V_20 )
{
struct V_17 * V_18 ;
struct V_74 * V_75 ;
V_73 |= V_5 << 8 ;
V_18 = F_55 ( V_16 , V_26 , V_28 , V_73 , sizeof( struct V_74 ) , V_36 ) ;
if ( V_18 == NULL )
goto V_76;
V_75 = F_56 ( V_18 ) ;
V_75 -> V_77 = V_9 ;
V_75 -> V_78 = V_79 ;
V_75 -> V_80 = F_57 ( V_1 -> V_7 . V_81 & 0xffff ) ;
if ( F_58 ( V_16 , V_82 , V_20 -> V_66 ) ||
F_59 ( V_16 , V_83 , F_60 ( V_20 -> V_36 ) ) ||
F_59 ( V_16 , V_84 , F_60 ( V_20 -> V_51 ) ) )
goto V_76;
return F_61 ( V_16 , V_18 ) ;
V_76:
F_62 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_63 ( const struct V_13 * V_14 , int V_73 )
{
struct V_15 * V_16 ;
int V_45 ;
if ( ! V_14 -> V_27 &&
! F_64 ( V_14 -> V_1 , V_85 ) )
return 0 ;
V_45 = - V_86 ;
V_16 = F_65 ( V_87 , V_34 ) ;
if ( V_16 == NULL )
goto V_45;
V_45 = F_54 ( V_16 , V_14 -> V_1 , V_14 -> V_26 , V_14 -> V_28 ,
V_73 , 0 , V_14 -> V_3 -> V_9 , V_14 -> V_20 ) ;
if ( V_45 < 0 ) {
F_66 ( V_16 ) ;
goto V_45;
}
V_45 = F_67 ( V_16 , V_14 -> V_1 , V_14 -> V_26 , V_85 ,
V_14 -> V_27 , V_34 ) ;
V_45:
if ( V_45 < 0 ) {
F_68 ( V_14 -> V_1 , V_14 -> V_26 , V_85 ,
V_45 ) ;
}
return V_45 ;
}
static int F_69 ( struct V_15 * V_16 ,
struct V_88 * V_89 )
{
const struct V_74 * V_75 = F_56 ( V_89 -> V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
unsigned int V_90 = 0 , V_91 = V_89 -> args [ 0 ] ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_75 -> V_77 ;
F_70 () ;
V_89 -> V_28 = V_1 -> V_7 . V_81 ;
F_71 (afi, &net->nft.af_info, list) {
if ( V_9 != V_92 && V_9 != V_3 -> V_9 )
continue;
F_71 (table, &afi->tables, list) {
if ( V_90 < V_91 )
goto V_93;
if ( V_90 > V_91 )
memset ( & V_89 -> args [ 1 ] , 0 ,
sizeof( V_89 -> args ) - sizeof( V_89 -> args [ 0 ] ) ) ;
if ( F_54 ( V_16 , V_1 ,
F_16 ( V_89 -> V_16 ) . V_26 ,
V_89 -> V_18 -> V_29 ,
V_42 ,
V_94 ,
V_3 -> V_9 , V_20 ) < 0 )
goto V_95;
F_72 ( V_89 , F_73 ( V_16 ) ) ;
V_93:
V_90 ++ ;
}
}
V_95:
F_74 () ;
V_89 -> args [ 0 ] = V_90 ;
return V_16 -> V_96 ;
}
static int F_75 ( struct V_97 * V_98 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_74 * V_75 = F_56 ( V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
struct V_15 * V_99 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_75 -> V_77 ;
int V_45 ;
if ( V_18 -> V_100 & V_101 ) {
struct V_102 V_103 = {
. V_104 = F_69 ,
} ;
return F_76 ( V_98 , V_16 , V_18 , & V_103 ) ;
}
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_77 ( V_3 ) )
return F_78 ( V_3 ) ;
V_20 = F_48 ( V_3 , V_24 [ V_82 ] ) ;
if ( F_77 ( V_20 ) )
return F_78 ( V_20 ) ;
if ( V_20 -> V_36 & V_43 )
return - V_56 ;
V_99 = F_79 ( V_87 , V_34 ) ;
if ( ! V_99 )
return - V_41 ;
V_45 = F_54 ( V_99 , V_1 , F_16 ( V_16 ) . V_26 ,
V_18 -> V_29 , V_42 , 0 ,
V_9 , V_20 ) ;
if ( V_45 < 0 )
goto V_45;
return F_80 ( V_98 , V_99 , F_16 ( V_16 ) . V_26 ) ;
V_45:
F_66 ( V_99 ) ;
return V_45 ;
}
static int F_81 ( const struct V_2 * V_3 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 ;
int V_45 , V_70 = 0 ;
F_9 (chain, &table->chains, list) {
if ( ! ( V_22 -> V_36 & V_38 ) )
continue;
V_45 = F_82 ( F_25 ( V_22 ) -> V_39 , V_3 -> V_105 ) ;
if ( V_45 < 0 )
goto V_45;
V_70 ++ ;
}
return 0 ;
V_45:
F_9 (chain, &table->chains, list) {
if ( ! ( V_22 -> V_36 & V_38 ) )
continue;
if ( V_70 -- <= 0 )
break;
F_24 ( F_25 ( V_22 ) -> V_39 , V_3 -> V_105 ) ;
}
return V_45 ;
}
static void F_83 ( const struct V_2 * V_3 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 ;
F_9 (chain, &table->chains, list) {
if ( V_22 -> V_36 & V_38 )
F_24 ( F_25 ( V_22 ) -> V_39 ,
V_3 -> V_105 ) ;
}
}
static int F_84 ( struct V_13 * V_14 )
{
struct V_30 * V_33 ;
T_1 V_36 ;
int V_106 = 0 ;
if ( ! V_14 -> V_24 [ V_83 ] )
return 0 ;
V_36 = F_43 ( F_44 ( V_14 -> V_24 [ V_83 ] ) ) ;
if ( V_36 & ~ V_37 )
return - V_67 ;
if ( V_36 == V_14 -> V_20 -> V_36 )
return 0 ;
V_33 = F_18 ( V_14 , V_42 ,
sizeof( struct V_40 ) ) ;
if ( V_33 == NULL )
return - V_41 ;
if ( ( V_36 & V_37 ) &&
! ( V_14 -> V_20 -> V_36 & V_37 ) ) {
F_85 ( V_33 ) = false ;
} else if ( ! ( V_36 & V_37 ) &&
V_14 -> V_20 -> V_36 & V_37 ) {
V_106 = F_81 ( V_14 -> V_3 , V_14 -> V_20 ) ;
if ( V_106 >= 0 ) {
V_14 -> V_20 -> V_36 &= ~ V_37 ;
F_85 ( V_33 ) = true ;
}
}
if ( V_106 < 0 )
goto V_45;
F_86 ( V_33 ) = true ;
F_27 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_44 ) ;
return 0 ;
V_45:
F_20 ( V_33 ) ;
return V_106 ;
}
static int F_87 ( struct V_97 * V_98 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_74 * V_75 = F_56 ( V_18 ) ;
const struct V_23 * V_66 ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_75 -> V_77 ;
T_1 V_36 = 0 ;
struct V_13 V_14 ;
int V_45 ;
V_3 = F_10 ( V_1 , V_9 , true ) ;
if ( F_77 ( V_3 ) )
return F_78 ( V_3 ) ;
V_66 = V_24 [ V_82 ] ;
V_20 = F_48 ( V_3 , V_66 ) ;
if ( F_77 ( V_20 ) ) {
if ( F_78 ( V_20 ) != - V_56 )
return F_78 ( V_20 ) ;
V_20 = NULL ;
}
if ( V_20 != NULL ) {
if ( V_20 -> V_36 & V_43 )
return - V_56 ;
if ( V_18 -> V_100 & V_107 )
return - V_108 ;
if ( V_18 -> V_100 & V_109 )
return - V_110 ;
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return F_84 ( & V_14 ) ;
}
if ( V_24 [ V_83 ] ) {
V_36 = F_43 ( F_44 ( V_24 [ V_83 ] ) ) ;
if ( V_36 & ~ V_37 )
return - V_67 ;
}
if ( ! F_88 ( V_3 -> V_111 ) )
return - V_12 ;
V_20 = F_19 ( sizeof( * V_20 ) + F_52 ( V_66 ) , V_34 ) ;
if ( V_20 == NULL ) {
F_89 ( V_3 -> V_111 ) ;
return - V_41 ;
}
F_90 ( V_20 -> V_66 , V_66 , F_52 ( V_66 ) ) ;
F_2 ( & V_20 -> V_112 ) ;
F_2 ( & V_20 -> V_113 ) ;
V_20 -> V_36 = V_36 ;
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
V_45 = F_26 ( & V_14 , V_42 ) ;
if ( V_45 < 0 ) {
F_22 ( V_20 ) ;
F_89 ( V_3 -> V_111 ) ;
return V_45 ;
}
F_4 ( & V_20 -> V_6 , & V_3 -> V_4 ) ;
return 0 ;
}
static int F_91 ( struct V_13 * V_14 )
{
int V_45 ;
struct V_21 * V_22 , * V_114 ;
struct V_59 * V_60 , * V_115 ;
F_92 (chain, nc, &ctx->table->chains, list) {
V_14 -> V_22 = V_22 ;
V_45 = F_40 ( V_14 ) ;
if ( V_45 < 0 )
goto V_116;
V_45 = F_30 ( V_14 ) ;
if ( V_45 < 0 )
goto V_116;
}
F_92 (set, ns, &ctx->table->sets, list) {
if ( V_60 -> V_36 & V_117 &&
! F_93 ( & V_60 -> V_118 ) )
continue;
V_45 = F_45 ( V_14 , V_60 ) ;
if ( V_45 < 0 )
goto V_116;
}
V_45 = F_28 ( V_14 ) ;
V_116:
return V_45 ;
}
static int F_94 ( struct V_13 * V_14 , int V_9 )
{
struct V_2 * V_3 ;
struct V_19 * V_20 , * V_119 ;
const struct V_23 * const * V_24 = V_14 -> V_24 ;
int V_45 = 0 ;
F_9 (afi, &ctx->net->nft.af_info, list) {
if ( V_9 != V_120 && V_3 -> V_9 != V_9 )
continue;
V_14 -> V_3 = V_3 ;
F_92 (table, nt, &afi->tables, list) {
if ( V_24 [ V_82 ] &&
F_47 ( V_24 [ V_82 ] , V_20 -> V_66 ) != 0 )
continue;
V_14 -> V_20 = V_20 ;
V_45 = F_91 ( V_14 ) ;
if ( V_45 < 0 )
goto V_116;
}
}
V_116:
return V_45 ;
}
static int F_95 ( struct V_97 * V_98 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_74 * V_75 = F_56 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_75 -> V_77 ;
struct V_13 V_14 ;
F_14 ( & V_14 , V_16 , V_18 , NULL , NULL , NULL , V_24 ) ;
if ( V_9 == V_120 || V_24 [ V_82 ] == NULL )
return F_94 ( & V_14 , V_9 ) ;
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_77 ( V_3 ) )
return F_78 ( V_3 ) ;
V_20 = F_48 ( V_3 , V_24 [ V_82 ] ) ;
if ( F_77 ( V_20 ) )
return F_78 ( V_20 ) ;
if ( V_20 -> V_36 & V_43 )
return - V_56 ;
V_14 . V_3 = V_3 ;
V_14 . V_20 = V_20 ;
return F_91 ( & V_14 ) ;
}
static void F_96 ( struct V_13 * V_14 )
{
F_97 ( V_14 -> V_20 -> V_51 > 0 ) ;
F_22 ( V_14 -> V_20 ) ;
F_89 ( V_14 -> V_3 -> V_111 ) ;
}
int F_98 ( const struct V_69 * V_121 )
{
int V_45 = 0 ;
F_3 ( V_5 ) ;
if ( V_72 [ V_121 -> V_9 ] [ V_121 -> type ] != NULL ) {
V_45 = - V_122 ;
goto V_116;
}
V_72 [ V_121 -> V_9 ] [ V_121 -> type ] = V_121 ;
V_116:
F_5 ( V_5 ) ;
return V_45 ;
}
void F_99 ( const struct V_69 * V_121 )
{
F_3 ( V_5 ) ;
V_72 [ V_121 -> V_9 ] [ V_121 -> type ] = NULL ;
F_5 ( V_5 ) ;
}
static struct V_21 *
F_100 ( const struct V_19 * V_20 , T_2 V_123 )
{
struct V_21 * V_22 ;
F_9 (chain, &table->chains, list) {
if ( V_22 -> V_123 == V_123 )
return V_22 ;
}
return F_13 ( - V_56 ) ;
}
static struct V_21 * F_101 ( const struct V_19 * V_20 ,
const struct V_23 * V_24 )
{
struct V_21 * V_22 ;
if ( V_24 == NULL )
return F_13 ( - V_67 ) ;
F_9 (chain, &table->chains, list) {
if ( ! F_47 ( V_24 , V_22 -> V_66 ) )
return V_22 ;
}
return F_13 ( - V_56 ) ;
}
static int F_102 ( struct V_15 * V_16 , struct V_124 T_3 * V_125 )
{
struct V_124 * V_126 , V_127 ;
struct V_23 * V_128 ;
unsigned int V_28 ;
T_2 V_129 , V_130 ;
int V_131 ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
F_103 (cpu) {
V_126 = F_104 ( V_125 , V_131 ) ;
do {
V_28 = F_105 ( & V_126 -> V_132 ) ;
V_129 = V_126 -> V_129 ;
V_130 = V_126 -> V_130 ;
} while ( F_106 ( & V_126 -> V_132 , V_28 ) );
V_127 . V_129 += V_129 ;
V_127 . V_130 += V_130 ;
}
V_128 = F_107 ( V_16 , V_133 ) ;
if ( V_128 == NULL )
goto V_76;
if ( F_108 ( V_16 , V_134 , F_109 ( V_127 . V_129 ) ) ||
F_108 ( V_16 , V_135 , F_109 ( V_127 . V_130 ) ) )
goto V_76;
F_110 ( V_16 , V_128 ) ;
return 0 ;
V_76:
return - V_136 ;
}
static int F_111 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_26 , T_1 V_28 , int V_73 , T_1 V_36 ,
int V_9 , const struct V_19 * V_20 ,
const struct V_21 * V_22 )
{
struct V_17 * V_18 ;
struct V_74 * V_75 ;
V_73 |= V_5 << 8 ;
V_18 = F_55 ( V_16 , V_26 , V_28 , V_73 , sizeof( struct V_74 ) , V_36 ) ;
if ( V_18 == NULL )
goto V_76;
V_75 = F_56 ( V_18 ) ;
V_75 -> V_77 = V_9 ;
V_75 -> V_78 = V_79 ;
V_75 -> V_80 = F_57 ( V_1 -> V_7 . V_81 & 0xffff ) ;
if ( F_58 ( V_16 , V_137 , V_20 -> V_66 ) )
goto V_76;
if ( F_108 ( V_16 , V_138 , F_109 ( V_22 -> V_123 ) ) )
goto V_76;
if ( F_58 ( V_16 , V_139 , V_22 -> V_66 ) )
goto V_76;
if ( V_22 -> V_36 & V_38 ) {
const struct F_25 * V_140 = F_25 ( V_22 ) ;
const struct V_141 * V_39 = & V_140 -> V_39 [ 0 ] ;
struct V_23 * V_128 ;
V_128 = F_107 ( V_16 , V_142 ) ;
if ( V_128 == NULL )
goto V_76;
if ( F_59 ( V_16 , V_143 , F_60 ( V_39 -> V_144 ) ) )
goto V_76;
if ( F_59 ( V_16 , V_145 , F_60 ( V_39 -> V_146 ) ) )
goto V_76;
F_110 ( V_16 , V_128 ) ;
if ( F_59 ( V_16 , V_147 ,
F_60 ( V_140 -> V_148 ) ) )
goto V_76;
if ( F_58 ( V_16 , V_149 , V_140 -> type -> V_66 ) )
goto V_76;
if ( F_102 ( V_16 , F_25 ( V_22 ) -> V_125 ) )
goto V_76;
}
if ( F_59 ( V_16 , V_150 , F_60 ( V_22 -> V_51 ) ) )
goto V_76;
return F_61 ( V_16 , V_18 ) ;
V_76:
F_62 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_112 ( const struct V_13 * V_14 , int V_73 )
{
struct V_15 * V_16 ;
int V_45 ;
if ( ! V_14 -> V_27 &&
! F_64 ( V_14 -> V_1 , V_85 ) )
return 0 ;
V_45 = - V_86 ;
V_16 = F_65 ( V_87 , V_34 ) ;
if ( V_16 == NULL )
goto V_45;
V_45 = F_111 ( V_16 , V_14 -> V_1 , V_14 -> V_26 , V_14 -> V_28 ,
V_73 , 0 , V_14 -> V_3 -> V_9 , V_14 -> V_20 ,
V_14 -> V_22 ) ;
if ( V_45 < 0 ) {
F_66 ( V_16 ) ;
goto V_45;
}
V_45 = F_67 ( V_16 , V_14 -> V_1 , V_14 -> V_26 , V_85 ,
V_14 -> V_27 , V_34 ) ;
V_45:
if ( V_45 < 0 ) {
F_68 ( V_14 -> V_1 , V_14 -> V_26 , V_85 ,
V_45 ) ;
}
return V_45 ;
}
static int F_113 ( struct V_15 * V_16 ,
struct V_88 * V_89 )
{
const struct V_74 * V_75 = F_56 ( V_89 -> V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
unsigned int V_90 = 0 , V_91 = V_89 -> args [ 0 ] ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_75 -> V_77 ;
F_70 () ;
V_89 -> V_28 = V_1 -> V_7 . V_81 ;
F_71 (afi, &net->nft.af_info, list) {
if ( V_9 != V_92 && V_9 != V_3 -> V_9 )
continue;
F_71 (table, &afi->tables, list) {
F_71 (chain, &table->chains, list) {
if ( V_90 < V_91 )
goto V_93;
if ( V_90 > V_91 )
memset ( & V_89 -> args [ 1 ] , 0 ,
sizeof( V_89 -> args ) - sizeof( V_89 -> args [ 0 ] ) ) ;
if ( F_111 ( V_16 , V_1 ,
F_16 ( V_89 -> V_16 ) . V_26 ,
V_89 -> V_18 -> V_29 ,
V_48 ,
V_94 ,
V_3 -> V_9 , V_20 , V_22 ) < 0 )
goto V_95;
F_72 ( V_89 , F_73 ( V_16 ) ) ;
V_93:
V_90 ++ ;
}
}
}
V_95:
F_74 () ;
V_89 -> args [ 0 ] = V_90 ;
return V_16 -> V_96 ;
}
static int F_114 ( struct V_97 * V_98 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_74 * V_75 = F_56 ( V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
struct V_15 * V_99 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_75 -> V_77 ;
int V_45 ;
if ( V_18 -> V_100 & V_101 ) {
struct V_102 V_103 = {
. V_104 = F_113 ,
} ;
return F_76 ( V_98 , V_16 , V_18 , & V_103 ) ;
}
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_77 ( V_3 ) )
return F_78 ( V_3 ) ;
V_20 = F_48 ( V_3 , V_24 [ V_137 ] ) ;
if ( F_77 ( V_20 ) )
return F_78 ( V_20 ) ;
if ( V_20 -> V_36 & V_43 )
return - V_56 ;
V_22 = F_101 ( V_20 , V_24 [ V_139 ] ) ;
if ( F_77 ( V_22 ) )
return F_78 ( V_22 ) ;
if ( V_22 -> V_36 & V_49 )
return - V_56 ;
V_99 = F_79 ( V_87 , V_34 ) ;
if ( ! V_99 )
return - V_41 ;
V_45 = F_111 ( V_99 , V_1 , F_16 ( V_16 ) . V_26 ,
V_18 -> V_29 , V_48 , 0 ,
V_9 , V_20 , V_22 ) ;
if ( V_45 < 0 )
goto V_45;
return F_80 ( V_98 , V_99 , F_16 ( V_16 ) . V_26 ) ;
V_45:
F_66 ( V_99 ) ;
return V_45 ;
}
static struct V_124 T_3 * F_115 ( const struct V_23 * V_151 )
{
struct V_23 * V_152 [ V_153 + 1 ] ;
struct V_124 T_3 * V_154 ;
struct V_124 * V_125 ;
int V_45 ;
V_45 = F_116 ( V_152 , V_153 , V_151 , V_155 ) ;
if ( V_45 < 0 )
return F_13 ( V_45 ) ;
if ( ! V_152 [ V_135 ] || ! V_152 [ V_134 ] )
return F_13 ( - V_67 ) ;
V_154 = F_117 ( struct V_124 ) ;
if ( V_154 == NULL )
return F_13 ( - V_41 ) ;
V_125 = F_118 ( V_154 ) ;
V_125 -> V_130 = F_119 ( F_120 ( V_152 [ V_135 ] ) ) ;
V_125 -> V_129 = F_119 ( F_120 ( V_152 [ V_134 ] ) ) ;
return V_154 ;
}
static void F_121 ( struct F_25 * V_22 ,
struct V_124 T_3 * V_154 )
{
if ( V_154 == NULL )
return;
if ( V_22 -> V_125 ) {
struct V_124 T_3 * V_156 =
F_122 ( V_22 -> V_125 ) ;
F_123 ( V_22 -> V_125 , V_154 ) ;
F_124 () ;
F_125 ( V_156 ) ;
} else
F_123 ( V_22 -> V_125 , V_154 ) ;
}
static void F_126 ( struct V_21 * V_22 )
{
F_97 ( V_22 -> V_51 > 0 ) ;
if ( V_22 -> V_36 & V_38 ) {
F_89 ( F_25 ( V_22 ) -> type -> V_111 ) ;
F_125 ( F_25 ( V_22 ) -> V_125 ) ;
F_22 ( F_25 ( V_22 ) ) ;
} else {
F_22 ( V_22 ) ;
}
}
static int F_127 ( struct V_97 * V_98 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_74 * V_75 = F_56 ( V_18 ) ;
const struct V_23 * V_157 ( V_66 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct F_25 * V_140 = NULL ;
struct V_23 * V_158 [ V_159 + 1 ] ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_75 -> V_77 ;
T_4 V_148 = V_160 ;
T_2 V_123 = 0 ;
unsigned int V_70 ;
struct V_124 T_3 * V_125 ;
int V_45 ;
bool V_161 ;
struct V_13 V_14 ;
V_161 = V_18 -> V_100 & V_162 ? true : false ;
V_3 = F_10 ( V_1 , V_9 , true ) ;
if ( F_77 ( V_3 ) )
return F_78 ( V_3 ) ;
V_20 = F_48 ( V_3 , V_24 [ V_137 ] ) ;
if ( F_77 ( V_20 ) )
return F_78 ( V_20 ) ;
V_22 = NULL ;
V_66 = V_24 [ V_139 ] ;
if ( V_24 [ V_138 ] ) {
V_123 = F_119 ( F_120 ( V_24 [ V_138 ] ) ) ;
V_22 = F_100 ( V_20 , V_123 ) ;
if ( F_77 ( V_22 ) )
return F_78 ( V_22 ) ;
} else {
V_22 = F_101 ( V_20 , V_66 ) ;
if ( F_77 ( V_22 ) ) {
if ( F_78 ( V_22 ) != - V_56 )
return F_78 ( V_22 ) ;
V_22 = NULL ;
}
}
if ( V_24 [ V_147 ] ) {
if ( ( V_22 != NULL &&
! ( V_22 -> V_36 & V_38 ) ) ||
V_24 [ V_142 ] == NULL )
return - V_110 ;
V_148 = F_43 ( F_44 ( V_24 [ V_147 ] ) ) ;
switch ( V_148 ) {
case V_163 :
case V_160 :
break;
default:
return - V_67 ;
}
}
if ( V_22 != NULL ) {
struct V_124 * V_125 = NULL ;
struct V_30 * V_33 ;
if ( V_22 -> V_36 & V_49 )
return - V_56 ;
if ( V_18 -> V_100 & V_107 )
return - V_108 ;
if ( V_18 -> V_100 & V_109 )
return - V_110 ;
if ( V_24 [ V_138 ] && V_66 &&
! F_77 ( F_101 ( V_20 , V_24 [ V_139 ] ) ) )
return - V_108 ;
if ( V_24 [ V_133 ] ) {
if ( ! ( V_22 -> V_36 & V_38 ) )
return - V_110 ;
V_125 = F_115 ( V_24 [ V_133 ] ) ;
if ( F_77 ( V_125 ) )
return F_78 ( V_125 ) ;
}
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_33 = F_18 ( & V_14 , V_48 ,
sizeof( struct V_47 ) ) ;
if ( V_33 == NULL )
return - V_41 ;
F_128 ( V_33 ) = V_125 ;
F_129 ( V_33 ) = true ;
if ( V_24 [ V_147 ] )
F_130 ( V_33 ) = V_148 ;
else
F_130 ( V_33 ) = - 1 ;
if ( V_24 [ V_138 ] && V_66 ) {
F_90 ( F_131 ( V_33 ) , V_66 ,
V_164 ) ;
}
F_27 ( & V_33 -> V_6 , & V_1 -> V_7 . V_44 ) ;
return 0 ;
}
if ( V_20 -> V_51 == V_165 )
return - V_166 ;
if ( V_24 [ V_142 ] ) {
const struct V_69 * type ;
struct V_141 * V_39 ;
T_5 * V_167 ;
T_1 V_144 , V_146 ;
type = V_72 [ V_9 ] [ V_168 ] ;
if ( V_24 [ V_149 ] ) {
type = F_51 ( V_3 ,
V_24 [ V_149 ] ,
V_161 ) ;
if ( F_77 ( type ) )
return F_78 ( type ) ;
}
V_45 = F_116 ( V_158 , V_159 , V_24 [ V_142 ] ,
V_169 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_158 [ V_143 ] == NULL ||
V_158 [ V_145 ] == NULL )
return - V_67 ;
V_144 = F_43 ( F_44 ( V_158 [ V_143 ] ) ) ;
if ( V_144 >= V_3 -> V_170 )
return - V_67 ;
V_146 = F_43 ( F_44 ( V_158 [ V_145 ] ) ) ;
if ( ! ( type -> V_171 & ( 1 << V_144 ) ) )
return - V_110 ;
if ( ! F_88 ( type -> V_111 ) )
return - V_56 ;
V_167 = type -> V_172 [ V_144 ] ;
V_140 = F_19 ( sizeof( * V_140 ) , V_34 ) ;
if ( V_140 == NULL )
return - V_41 ;
if ( V_24 [ V_133 ] ) {
V_125 = F_115 ( V_24 [ V_133 ] ) ;
if ( F_77 ( V_125 ) ) {
F_89 ( type -> V_111 ) ;
F_22 ( V_140 ) ;
return F_78 ( V_125 ) ;
}
V_140 -> V_125 = V_125 ;
} else {
V_125 = F_117 ( struct V_124 ) ;
if ( V_125 == NULL ) {
F_89 ( type -> V_111 ) ;
F_22 ( V_140 ) ;
return - V_41 ;
}
F_123 ( V_140 -> V_125 , V_125 ) ;
}
V_140 -> type = type ;
V_22 = & V_140 -> V_22 ;
for ( V_70 = 0 ; V_70 < V_3 -> V_105 ; V_70 ++ ) {
V_39 = & V_140 -> V_39 [ V_70 ] ;
V_39 -> V_173 = V_9 ;
V_39 -> V_111 = V_3 -> V_111 ;
V_39 -> V_144 = V_144 ;
V_39 -> V_146 = V_146 ;
V_39 -> V_174 = V_22 ;
V_39 -> V_175 = V_3 -> V_172 [ V_39 -> V_144 ] ;
if ( V_167 )
V_39 -> V_175 = V_167 ;
if ( V_3 -> V_176 )
V_3 -> V_176 ( V_39 , V_70 ) ;
}
V_22 -> V_36 |= V_38 ;
V_140 -> V_148 = V_148 ;
} else {
V_22 = F_19 ( sizeof( * V_22 ) , V_34 ) ;
if ( V_22 == NULL )
return - V_41 ;
}
F_2 ( & V_22 -> V_177 ) ;
V_22 -> V_123 = F_49 ( V_20 ) ;
V_22 -> V_1 = V_1 ;
V_22 -> V_20 = V_20 ;
F_90 ( V_22 -> V_66 , V_66 , V_164 ) ;
if ( ! ( V_20 -> V_36 & V_37 ) &&
V_22 -> V_36 & V_38 ) {
V_45 = F_82 ( F_25 ( V_22 ) -> V_39 , V_3 -> V_105 ) ;
if ( V_45 < 0 )
goto V_178;
}
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_45 = F_29 ( & V_14 , V_48 ) ;
if ( V_45 < 0 )
goto V_179;
V_20 -> V_51 ++ ;
F_4 ( & V_22 -> V_6 , & V_20 -> V_112 ) ;
return 0 ;
V_179:
F_23 ( V_20 , V_22 , V_3 -> V_105 ) ;
V_178:
F_126 ( V_22 ) ;
return V_45 ;
}
static int F_132 ( struct V_97 * V_98 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_74 * V_75 = F_56 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_75 -> V_77 ;
struct V_13 V_14 ;
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_77 ( V_3 ) )
return F_78 ( V_3 ) ;
V_20 = F_48 ( V_3 , V_24 [ V_137 ] ) ;
if ( F_77 ( V_20 ) )
return F_78 ( V_20 ) ;
if ( V_20 -> V_36 & V_43 )
return - V_56 ;
V_22 = F_101 ( V_20 , V_24 [ V_139 ] ) ;
if ( F_77 ( V_22 ) )
return F_78 ( V_22 ) ;
if ( V_22 -> V_36 & V_49 )
return - V_56 ;
if ( V_22 -> V_51 > 0 )
return - V_122 ;
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
return F_30 ( & V_14 ) ;
}
int F_133 ( struct V_180 * type )
{
F_3 ( V_5 ) ;
if ( type -> V_9 == V_92 )
F_4 ( & type -> V_6 , & V_181 ) ;
else
F_134 ( & type -> V_6 , & V_181 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_135 ( struct V_180 * type )
{
F_3 ( V_5 ) ;
F_7 ( & type -> V_6 ) ;
F_5 ( V_5 ) ;
}
static const struct V_180 * F_136 ( T_4 V_9 ,
struct V_23 * V_24 )
{
const struct V_180 * type ;
F_9 (type, &nf_tables_expressions, list) {
if ( ! F_47 ( V_24 , type -> V_66 ) &&
( ! type -> V_9 || type -> V_9 == V_9 ) )
return type ;
}
return NULL ;
}
static const struct V_180 * F_137 ( T_4 V_9 ,
struct V_23 * V_24 )
{
const struct V_180 * type ;
if ( V_24 == NULL )
return F_13 ( - V_67 ) ;
type = F_136 ( V_9 , V_24 ) ;
if ( type != NULL && F_88 ( type -> V_111 ) )
return type ;
#ifdef F_11
if ( type == NULL ) {
F_5 ( V_5 ) ;
F_12 ( L_3 , V_9 ,
F_52 ( V_24 ) , ( char * ) F_53 ( V_24 ) ) ;
F_3 ( V_5 ) ;
if ( F_136 ( V_9 , V_24 ) )
return F_13 ( - V_11 ) ;
F_5 ( V_5 ) ;
F_12 ( L_4 ,
F_52 ( V_24 ) , ( char * ) F_53 ( V_24 ) ) ;
F_3 ( V_5 ) ;
if ( F_136 ( V_9 , V_24 ) )
return F_13 ( - V_11 ) ;
}
#endif
return F_13 ( - V_56 ) ;
}
static int F_138 ( struct V_15 * V_16 ,
const struct V_182 * V_183 )
{
if ( F_58 ( V_16 , V_184 , V_183 -> V_39 -> type -> V_66 ) )
goto V_76;
if ( V_183 -> V_39 -> V_104 ) {
struct V_23 * V_185 = F_107 ( V_16 , V_186 ) ;
if ( V_185 == NULL )
goto V_76;
if ( V_183 -> V_39 -> V_104 ( V_16 , V_183 ) < 0 )
goto V_76;
F_110 ( V_16 , V_185 ) ;
}
return V_16 -> V_96 ;
V_76:
return - 1 ;
}
static int F_139 ( const struct V_13 * V_14 ,
const struct V_23 * V_24 ,
struct V_187 * V_188 )
{
const struct V_180 * type ;
const struct V_189 * V_39 ;
struct V_23 * V_152 [ V_190 + 1 ] ;
int V_45 ;
V_45 = F_116 ( V_152 , V_190 , V_24 , V_191 ) ;
if ( V_45 < 0 )
return V_45 ;
type = F_137 ( V_14 -> V_3 -> V_9 , V_152 [ V_184 ] ) ;
if ( F_77 ( type ) )
return F_78 ( type ) ;
if ( V_152 [ V_186 ] ) {
V_45 = F_116 ( V_188 -> V_152 , type -> V_192 ,
V_152 [ V_186 ] , type -> V_148 ) ;
if ( V_45 < 0 )
goto V_178;
} else
memset ( V_188 -> V_152 , 0 , sizeof( V_188 -> V_152 [ 0 ] ) * ( type -> V_192 + 1 ) ) ;
if ( type -> V_193 != NULL ) {
V_39 = type -> V_193 ( V_14 ,
( const struct V_23 * const * ) V_188 -> V_152 ) ;
if ( F_77 ( V_39 ) ) {
V_45 = F_78 ( V_39 ) ;
goto V_178;
}
} else
V_39 = type -> V_39 ;
V_188 -> V_39 = V_39 ;
return 0 ;
V_178:
F_89 ( type -> V_111 ) ;
return V_45 ;
}
static int F_140 ( const struct V_13 * V_14 ,
const struct V_187 * V_188 ,
struct V_182 * V_183 )
{
const struct V_189 * V_39 = V_188 -> V_39 ;
int V_45 ;
V_183 -> V_39 = V_39 ;
if ( V_39 -> V_194 ) {
V_45 = V_39 -> V_194 ( V_14 , V_183 , ( const struct V_23 * * ) V_188 -> V_152 ) ;
if ( V_45 < 0 )
goto V_178;
}
return 0 ;
V_178:
V_183 -> V_39 = NULL ;
return V_45 ;
}
static void F_141 ( const struct V_13 * V_14 ,
struct V_182 * V_183 )
{
if ( V_183 -> V_39 -> V_195 )
V_183 -> V_39 -> V_195 ( V_14 , V_183 ) ;
F_89 ( V_183 -> V_39 -> type -> V_111 ) ;
}
static struct V_52 * F_142 ( const struct V_21 * V_22 ,
T_2 V_123 )
{
struct V_52 * V_53 ;
F_9 (rule, &chain->rules, list) {
if ( V_123 == V_53 -> V_123 )
return V_53 ;
}
return F_13 ( - V_56 ) ;
}
static struct V_52 * F_143 ( const struct V_21 * V_22 ,
const struct V_23 * V_24 )
{
if ( V_24 == NULL )
return F_13 ( - V_67 ) ;
return F_142 ( V_22 , F_119 ( F_120 ( V_24 ) ) ) ;
}
static int F_144 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_26 , T_1 V_28 , int V_73 ,
T_1 V_36 , int V_9 ,
const struct V_19 * V_20 ,
const struct V_21 * V_22 ,
const struct V_52 * V_53 )
{
struct V_17 * V_18 ;
struct V_74 * V_75 ;
const struct V_182 * V_183 , * V_196 ;
struct V_23 * V_6 ;
const struct V_52 * V_197 ;
int type = V_73 | V_5 << 8 ;
V_18 = F_55 ( V_16 , V_26 , V_28 , type , sizeof( struct V_74 ) ,
V_36 ) ;
if ( V_18 == NULL )
goto V_76;
V_75 = F_56 ( V_18 ) ;
V_75 -> V_77 = V_9 ;
V_75 -> V_78 = V_79 ;
V_75 -> V_80 = F_57 ( V_1 -> V_7 . V_81 & 0xffff ) ;
if ( F_58 ( V_16 , V_198 , V_20 -> V_66 ) )
goto V_76;
if ( F_58 ( V_16 , V_199 , V_22 -> V_66 ) )
goto V_76;
if ( F_108 ( V_16 , V_200 , F_109 ( V_53 -> V_123 ) ) )
goto V_76;
if ( ( V_73 != V_58 ) && ( V_53 -> V_6 . V_201 != & V_22 -> V_177 ) ) {
V_197 = F_145 ( V_53 -> V_6 . V_201 , struct V_52 , V_6 ) ;
if ( F_108 ( V_16 , V_202 ,
F_109 ( V_197 -> V_123 ) ) )
goto V_76;
}
V_6 = F_107 ( V_16 , V_203 ) ;
if ( V_6 == NULL )
goto V_76;
F_146 (expr, next, rule) {
struct V_23 * V_204 = F_107 ( V_16 , V_205 ) ;
if ( V_204 == NULL )
goto V_76;
if ( F_138 ( V_16 , V_183 ) < 0 )
goto V_76;
F_110 ( V_16 , V_204 ) ;
}
F_110 ( V_16 , V_6 ) ;
if ( V_53 -> V_206 &&
F_147 ( V_16 , V_207 , V_53 -> V_206 , F_148 ( V_53 ) ) )
goto V_76;
return F_61 ( V_16 , V_18 ) ;
V_76:
F_62 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_149 ( const struct V_13 * V_14 ,
const struct V_52 * V_53 ,
int V_73 )
{
struct V_15 * V_16 ;
int V_45 ;
if ( ! V_14 -> V_27 &&
! F_64 ( V_14 -> V_1 , V_85 ) )
return 0 ;
V_45 = - V_86 ;
V_16 = F_65 ( V_87 , V_34 ) ;
if ( V_16 == NULL )
goto V_45;
V_45 = F_144 ( V_16 , V_14 -> V_1 , V_14 -> V_26 , V_14 -> V_28 ,
V_73 , 0 , V_14 -> V_3 -> V_9 , V_14 -> V_20 ,
V_14 -> V_22 , V_53 ) ;
if ( V_45 < 0 ) {
F_66 ( V_16 ) ;
goto V_45;
}
V_45 = F_67 ( V_16 , V_14 -> V_1 , V_14 -> V_26 , V_85 ,
V_14 -> V_27 , V_34 ) ;
V_45:
if ( V_45 < 0 ) {
F_68 ( V_14 -> V_1 , V_14 -> V_26 , V_85 ,
V_45 ) ;
}
return V_45 ;
}
static int F_150 ( struct V_15 * V_16 ,
struct V_88 * V_89 )
{
const struct V_74 * V_75 = F_56 ( V_89 -> V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
const struct V_52 * V_53 ;
unsigned int V_90 = 0 , V_91 = V_89 -> args [ 0 ] ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_75 -> V_77 ;
F_70 () ;
V_89 -> V_28 = V_1 -> V_7 . V_81 ;
F_71 (afi, &net->nft.af_info, list) {
if ( V_9 != V_92 && V_9 != V_3 -> V_9 )
continue;
F_71 (table, &afi->tables, list) {
F_71 (chain, &table->chains, list) {
F_71 (rule, &chain->rules, list) {
if ( ! F_31 ( V_1 , V_53 ) )
goto V_93;
if ( V_90 < V_91 )
goto V_93;
if ( V_90 > V_91 )
memset ( & V_89 -> args [ 1 ] , 0 ,
sizeof( V_89 -> args ) - sizeof( V_89 -> args [ 0 ] ) ) ;
if ( F_144 ( V_16 , V_1 , F_16 ( V_89 -> V_16 ) . V_26 ,
V_89 -> V_18 -> V_29 ,
V_208 ,
V_94 | V_209 ,
V_3 -> V_9 , V_20 , V_22 , V_53 ) < 0 )
goto V_95;
F_72 ( V_89 , F_73 ( V_16 ) ) ;
V_93:
V_90 ++ ;
}
}
}
}
V_95:
F_74 () ;
V_89 -> args [ 0 ] = V_90 ;
return V_16 -> V_96 ;
}
static int F_151 ( struct V_97 * V_98 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_74 * V_75 = F_56 ( V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
const struct V_52 * V_53 ;
struct V_15 * V_99 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_75 -> V_77 ;
int V_45 ;
if ( V_18 -> V_100 & V_101 ) {
struct V_102 V_103 = {
. V_104 = F_150 ,
} ;
return F_76 ( V_98 , V_16 , V_18 , & V_103 ) ;
}
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_77 ( V_3 ) )
return F_78 ( V_3 ) ;
V_20 = F_48 ( V_3 , V_24 [ V_198 ] ) ;
if ( F_77 ( V_20 ) )
return F_78 ( V_20 ) ;
if ( V_20 -> V_36 & V_43 )
return - V_56 ;
V_22 = F_101 ( V_20 , V_24 [ V_199 ] ) ;
if ( F_77 ( V_22 ) )
return F_78 ( V_22 ) ;
if ( V_22 -> V_36 & V_49 )
return - V_56 ;
V_53 = F_143 ( V_22 , V_24 [ V_200 ] ) ;
if ( F_77 ( V_53 ) )
return F_78 ( V_53 ) ;
V_99 = F_79 ( V_87 , V_34 ) ;
if ( ! V_99 )
return - V_41 ;
V_45 = F_144 ( V_99 , V_1 , F_16 ( V_16 ) . V_26 ,
V_18 -> V_29 , V_208 , 0 ,
V_9 , V_20 , V_22 , V_53 ) ;
if ( V_45 < 0 )
goto V_45;
return F_80 ( V_98 , V_99 , F_16 ( V_16 ) . V_26 ) ;
V_45:
F_66 ( V_99 ) ;
return V_45 ;
}
static void F_152 ( const struct V_13 * V_14 ,
struct V_52 * V_53 )
{
struct V_182 * V_183 ;
V_183 = F_153 ( V_53 ) ;
while ( V_183 -> V_39 && V_183 != F_154 ( V_53 ) ) {
F_141 ( V_14 , V_183 ) ;
V_183 = F_155 ( V_183 ) ;
}
F_22 ( V_53 ) ;
}
static int F_156 ( struct V_97 * V_98 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_74 * V_75 = F_56 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_52 * V_53 , * V_210 = NULL ;
struct V_30 * V_33 = NULL ;
struct V_182 * V_183 ;
struct V_13 V_14 ;
struct V_23 * V_211 ;
unsigned int V_32 , V_70 , V_212 , V_206 = 0 ;
int V_45 , V_213 ;
bool V_161 ;
T_2 V_123 , V_214 ;
V_161 = V_18 -> V_100 & V_162 ? true : false ;
V_3 = F_10 ( V_1 , V_75 -> V_77 , V_161 ) ;
if ( F_77 ( V_3 ) )
return F_78 ( V_3 ) ;
V_20 = F_48 ( V_3 , V_24 [ V_198 ] ) ;
if ( F_77 ( V_20 ) )
return F_78 ( V_20 ) ;
V_22 = F_101 ( V_20 , V_24 [ V_199 ] ) ;
if ( F_77 ( V_22 ) )
return F_78 ( V_22 ) ;
if ( V_24 [ V_200 ] ) {
V_123 = F_119 ( F_120 ( V_24 [ V_200 ] ) ) ;
V_53 = F_142 ( V_22 , V_123 ) ;
if ( F_77 ( V_53 ) )
return F_78 ( V_53 ) ;
if ( V_18 -> V_100 & V_107 )
return - V_108 ;
if ( V_18 -> V_100 & V_109 )
V_210 = V_53 ;
else
return - V_110 ;
} else {
if ( ! V_161 || V_18 -> V_100 & V_109 )
return - V_67 ;
V_123 = F_49 ( V_20 ) ;
if ( V_22 -> V_51 == V_165 )
return - V_166 ;
}
if ( V_24 [ V_202 ] ) {
if ( ! ( V_18 -> V_100 & V_162 ) )
return - V_110 ;
V_214 = F_119 ( F_120 ( V_24 [ V_202 ] ) ) ;
V_210 = F_142 ( V_22 , V_214 ) ;
if ( F_77 ( V_210 ) )
return F_78 ( V_210 ) ;
}
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_212 = 0 ;
V_32 = 0 ;
if ( V_24 [ V_203 ] ) {
F_157 (tmp, nla[NFTA_RULE_EXPRESSIONS], rem) {
V_45 = - V_67 ;
if ( F_158 ( V_211 ) != V_205 )
goto V_178;
if ( V_212 == V_215 )
goto V_178;
V_45 = F_139 ( & V_14 , V_211 , & V_188 [ V_212 ] ) ;
if ( V_45 < 0 )
goto V_178;
V_32 += V_188 [ V_212 ] . V_39 -> V_32 ;
V_212 ++ ;
}
}
if ( V_24 [ V_207 ] )
V_206 = F_52 ( V_24 [ V_207 ] ) ;
V_45 = - V_41 ;
V_53 = F_19 ( sizeof( * V_53 ) + V_32 + V_206 , V_34 ) ;
if ( V_53 == NULL )
goto V_178;
F_34 ( V_1 , V_53 ) ;
V_53 -> V_123 = V_123 ;
V_53 -> V_216 = V_32 ;
V_53 -> V_206 = V_206 ;
if ( V_206 )
F_159 ( F_148 ( V_53 ) , V_24 [ V_207 ] , V_206 ) ;
V_183 = F_153 ( V_53 ) ;
for ( V_70 = 0 ; V_70 < V_212 ; V_70 ++ ) {
V_45 = F_140 ( & V_14 , & V_188 [ V_70 ] , V_183 ) ;
if ( V_45 < 0 )
goto V_179;
V_188 [ V_70 ] . V_39 = NULL ;
V_183 = F_155 ( V_183 ) ;
}
if ( V_18 -> V_100 & V_109 ) {
if ( F_33 ( V_1 , V_210 ) ) {
V_33 = F_38 ( & V_14 , V_58 ,
V_210 ) ;
if ( V_33 == NULL ) {
V_45 = - V_41 ;
goto V_179;
}
F_35 ( V_1 , V_210 ) ;
V_22 -> V_51 -- ;
F_4 ( & V_53 -> V_6 , & V_210 -> V_6 ) ;
} else {
V_45 = - V_56 ;
goto V_179;
}
} else if ( V_18 -> V_100 & V_209 )
if ( V_210 )
F_134 ( & V_53 -> V_6 , & V_210 -> V_6 ) ;
else
F_4 ( & V_53 -> V_6 , & V_22 -> V_177 ) ;
else {
if ( V_210 )
F_4 ( & V_53 -> V_6 , & V_210 -> V_6 ) ;
else
F_134 ( & V_53 -> V_6 , & V_22 -> V_177 ) ;
}
if ( F_38 ( & V_14 , V_208 , V_53 ) == NULL ) {
V_45 = - V_41 ;
goto V_217;
}
V_22 -> V_51 ++ ;
return 0 ;
V_217:
F_7 ( & V_53 -> V_6 ) ;
if ( V_33 ) {
F_7 ( & V_57 ( V_33 ) -> V_6 ) ;
F_36 ( V_1 , V_57 ( V_33 ) ) ;
F_20 ( V_33 ) ;
V_22 -> V_51 ++ ;
}
V_179:
F_152 ( & V_14 , V_53 ) ;
V_178:
for ( V_70 = 0 ; V_70 < V_212 ; V_70 ++ ) {
if ( V_188 [ V_70 ] . V_39 != NULL )
F_89 ( V_188 [ V_70 ] . V_39 -> type -> V_111 ) ;
}
return V_45 ;
}
static int F_160 ( struct V_97 * V_98 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_74 * V_75 = F_56 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
struct V_19 * V_20 ;
struct V_21 * V_22 = NULL ;
struct V_52 * V_53 ;
int V_9 = V_75 -> V_77 , V_45 = 0 ;
struct V_13 V_14 ;
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_77 ( V_3 ) )
return F_78 ( V_3 ) ;
V_20 = F_48 ( V_3 , V_24 [ V_198 ] ) ;
if ( F_77 ( V_20 ) )
return F_78 ( V_20 ) ;
if ( V_20 -> V_36 & V_43 )
return - V_56 ;
if ( V_24 [ V_199 ] ) {
V_22 = F_101 ( V_20 , V_24 [ V_199 ] ) ;
if ( F_77 ( V_22 ) )
return F_78 ( V_22 ) ;
}
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
if ( V_22 ) {
if ( V_24 [ V_200 ] ) {
V_53 = F_143 ( V_22 ,
V_24 [ V_200 ] ) ;
if ( F_77 ( V_53 ) )
return F_78 ( V_53 ) ;
V_45 = F_39 ( & V_14 , V_53 ) ;
} else {
V_45 = F_40 ( & V_14 ) ;
}
} else {
F_9 (chain, &table->chains, list) {
V_14 . V_22 = V_22 ;
V_45 = F_40 ( & V_14 ) ;
if ( V_45 < 0 )
break;
}
}
return V_45 ;
}
int F_161 ( struct V_218 * V_39 )
{
F_3 ( V_5 ) ;
F_4 ( & V_39 -> V_6 , & V_219 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_162 ( struct V_218 * V_39 )
{
F_3 ( V_5 ) ;
F_7 ( & V_39 -> V_6 ) ;
F_5 ( V_5 ) ;
}
static const struct V_218 *
F_163 ( const struct V_23 * const V_24 [] ,
const struct V_220 * V_221 ,
enum V_222 V_148 )
{
const struct V_218 * V_39 , * V_223 ;
struct V_224 V_225 , V_226 ;
T_1 V_227 ;
#ifdef F_11
if ( F_93 ( & V_219 ) ) {
F_5 ( V_5 ) ;
F_12 ( L_5 ) ;
F_3 ( V_5 ) ;
if ( ! F_93 ( & V_219 ) )
return F_13 ( - V_11 ) ;
}
#endif
V_227 = 0 ;
if ( V_24 [ V_228 ] != NULL ) {
V_227 = F_43 ( F_44 ( V_24 [ V_228 ] ) ) ;
V_227 &= V_229 | V_230 ;
}
V_223 = NULL ;
V_226 . V_32 = ~ 0 ;
V_226 . V_231 = ~ 0 ;
F_9 (ops, &nf_tables_set_ops, list) {
if ( ( V_39 -> V_227 & V_227 ) != V_227 )
continue;
if ( ! V_39 -> V_232 ( V_221 , V_227 , & V_225 ) )
continue;
switch ( V_148 ) {
case V_233 :
if ( V_225 . V_231 < V_226 . V_231 )
break;
if ( V_225 . V_231 == V_226 . V_231 && V_225 . V_32 < V_226 . V_32 )
break;
continue;
case V_234 :
if ( V_225 . V_32 < V_226 . V_32 )
break;
if ( V_225 . V_32 == V_226 . V_32 && V_225 . V_231 < V_226 . V_231 )
break;
continue;
default:
break;
}
if ( ! F_88 ( V_39 -> V_111 ) )
continue;
if ( V_223 != NULL )
F_89 ( V_223 -> V_111 ) ;
V_223 = V_39 ;
V_226 = V_225 ;
}
if ( V_223 != NULL )
return V_223 ;
return F_13 ( - V_110 ) ;
}
static int F_164 ( struct V_13 * V_14 ,
const struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
const struct V_74 * V_75 = F_56 ( V_18 ) ;
struct V_2 * V_3 = NULL ;
struct V_19 * V_20 = NULL ;
if ( V_75 -> V_77 != V_92 ) {
V_3 = F_10 ( V_1 , V_75 -> V_77 , false ) ;
if ( F_77 ( V_3 ) )
return F_78 ( V_3 ) ;
}
if ( V_24 [ V_235 ] != NULL ) {
if ( V_3 == NULL )
return - V_12 ;
V_20 = F_48 ( V_3 , V_24 [ V_235 ] ) ;
if ( F_77 ( V_20 ) )
return F_78 ( V_20 ) ;
if ( V_20 -> V_36 & V_43 )
return - V_56 ;
}
F_14 ( V_14 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return 0 ;
}
struct V_59 * F_165 ( const struct V_19 * V_20 ,
const struct V_23 * V_24 )
{
struct V_59 * V_60 ;
if ( V_24 == NULL )
return F_13 ( - V_67 ) ;
F_9 (set, &table->sets, list) {
if ( ! F_47 ( V_24 , V_60 -> V_66 ) )
return V_60 ;
}
return F_13 ( - V_56 ) ;
}
struct V_59 * F_166 ( const struct V_1 * V_1 ,
const struct V_23 * V_24 )
{
struct V_30 * V_33 ;
T_1 V_236 = F_43 ( F_44 ( V_24 ) ) ;
F_9 (trans, &net->nft.commit_list, list) {
if ( V_33 -> V_31 == V_62 &&
V_236 == F_42 ( V_33 ) )
return V_61 ( V_33 ) ;
}
return F_13 ( - V_56 ) ;
}
static int F_167 ( struct V_13 * V_14 , struct V_59 * V_60 ,
const char * V_66 )
{
const struct V_59 * V_70 ;
const char * V_237 ;
unsigned long * V_238 ;
unsigned int V_212 = 0 , V_239 = 0 ;
V_237 = F_168 ( V_66 , V_240 , '%' ) ;
if ( V_237 != NULL ) {
if ( V_237 [ 1 ] != 'd' || strchr ( V_237 + 2 , '%' ) )
return - V_67 ;
V_238 = ( unsigned long * ) F_169 ( V_34 ) ;
if ( V_238 == NULL )
return - V_41 ;
V_93:
F_9 (i, &ctx->table->sets, list) {
int V_211 ;
if ( ! sscanf ( V_70 -> V_66 , V_66 , & V_211 ) )
continue;
if ( V_211 < V_239 || V_211 >= V_239 + V_241 * V_242 )
continue;
F_170 ( V_211 - V_239 , V_238 ) ;
}
V_212 = F_171 ( V_238 , V_241 * V_242 ) ;
if ( V_212 >= V_241 * V_242 ) {
V_239 += V_241 * V_242 ;
memset ( V_238 , 0 , V_242 ) ;
goto V_93;
}
F_172 ( ( unsigned long ) V_238 ) ;
}
snprintf ( V_60 -> V_66 , sizeof( V_60 -> V_66 ) , V_66 , V_239 + V_212 ) ;
F_9 (i, &ctx->table->sets, list) {
if ( ! strcmp ( V_60 -> V_66 , V_70 -> V_66 ) )
return - V_243 ;
}
return 0 ;
}
static int F_173 ( struct V_15 * V_16 , const struct V_13 * V_14 ,
const struct V_59 * V_60 , T_6 V_73 , T_6 V_36 )
{
struct V_74 * V_75 ;
struct V_17 * V_18 ;
struct V_23 * V_221 ;
T_1 V_26 = V_14 -> V_26 ;
T_1 V_28 = V_14 -> V_28 ;
V_73 |= V_5 << 8 ;
V_18 = F_55 ( V_16 , V_26 , V_28 , V_73 , sizeof( struct V_74 ) ,
V_36 ) ;
if ( V_18 == NULL )
goto V_76;
V_75 = F_56 ( V_18 ) ;
V_75 -> V_77 = V_14 -> V_3 -> V_9 ;
V_75 -> V_78 = V_79 ;
V_75 -> V_80 = F_57 ( V_14 -> V_1 -> V_7 . V_81 & 0xffff ) ;
if ( F_58 ( V_16 , V_235 , V_14 -> V_20 -> V_66 ) )
goto V_76;
if ( F_58 ( V_16 , V_244 , V_60 -> V_66 ) )
goto V_76;
if ( V_60 -> V_36 != 0 )
if ( F_59 ( V_16 , V_228 , F_60 ( V_60 -> V_36 ) ) )
goto V_76;
if ( F_59 ( V_16 , V_245 , F_60 ( V_60 -> V_246 ) ) )
goto V_76;
if ( F_59 ( V_16 , V_247 , F_60 ( V_60 -> V_248 ) ) )
goto V_76;
if ( V_60 -> V_36 & V_230 ) {
if ( F_59 ( V_16 , V_249 , F_60 ( V_60 -> V_250 ) ) )
goto V_76;
if ( F_59 ( V_16 , V_251 , F_60 ( V_60 -> V_216 ) ) )
goto V_76;
}
if ( V_60 -> V_148 != V_233 ) {
if ( F_59 ( V_16 , V_252 , F_60 ( V_60 -> V_148 ) ) )
goto V_76;
}
V_221 = F_107 ( V_16 , V_253 ) ;
if ( V_221 == NULL )
goto V_76;
if ( V_60 -> V_32 &&
F_59 ( V_16 , V_254 , F_60 ( V_60 -> V_32 ) ) )
goto V_76;
F_110 ( V_16 , V_221 ) ;
return F_61 ( V_16 , V_18 ) ;
V_76:
F_62 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_174 ( const struct V_13 * V_14 ,
const struct V_59 * V_60 ,
int V_73 , T_7 V_255 )
{
struct V_15 * V_16 ;
T_1 V_26 = V_14 -> V_26 ;
int V_45 ;
if ( ! V_14 -> V_27 &&
! F_64 ( V_14 -> V_1 , V_85 ) )
return 0 ;
V_45 = - V_86 ;
V_16 = F_65 ( V_87 , V_255 ) ;
if ( V_16 == NULL )
goto V_45;
V_45 = F_173 ( V_16 , V_14 , V_60 , V_73 , 0 ) ;
if ( V_45 < 0 ) {
F_66 ( V_16 ) ;
goto V_45;
}
V_45 = F_67 ( V_16 , V_14 -> V_1 , V_26 , V_85 ,
V_14 -> V_27 , V_255 ) ;
V_45:
if ( V_45 < 0 )
F_68 ( V_14 -> V_1 , V_26 , V_85 , V_45 ) ;
return V_45 ;
}
static int F_175 ( struct V_15 * V_16 , struct V_88 * V_89 )
{
const struct V_59 * V_60 ;
unsigned int V_90 , V_91 = V_89 -> args [ 0 ] ;
struct V_2 * V_3 ;
struct V_19 * V_20 , * V_256 = (struct V_19 * ) V_89 -> args [ 2 ] ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_257 = V_89 -> args [ 3 ] ;
struct V_13 * V_14 = V_89 -> V_185 , V_258 ;
if ( V_89 -> args [ 1 ] )
return V_16 -> V_96 ;
F_70 () ;
V_89 -> V_28 = V_1 -> V_7 . V_81 ;
F_71 (afi, &net->nft.af_info, list) {
if ( V_14 -> V_3 && V_14 -> V_3 != V_3 )
continue;
if ( V_257 ) {
if ( V_3 -> V_9 != V_257 )
continue;
V_257 = 0 ;
}
F_71 (table, &afi->tables, list) {
if ( V_14 -> V_20 && V_14 -> V_20 != V_20 )
continue;
if ( V_256 ) {
if ( V_256 != V_20 )
continue;
V_256 = NULL ;
}
V_90 = 0 ;
F_71 (set, &table->sets, list) {
if ( V_90 < V_91 )
goto V_93;
V_258 = * V_14 ;
V_258 . V_20 = V_20 ;
V_258 . V_3 = V_3 ;
if ( F_173 ( V_16 , & V_258 , V_60 ,
V_62 ,
V_94 ) < 0 ) {
V_89 -> args [ 0 ] = V_90 ;
V_89 -> args [ 2 ] = ( unsigned long ) V_20 ;
V_89 -> args [ 3 ] = V_3 -> V_9 ;
goto V_95;
}
F_72 ( V_89 , F_73 ( V_16 ) ) ;
V_93:
V_90 ++ ;
}
if ( V_91 )
V_91 = 0 ;
}
}
V_89 -> args [ 1 ] = 1 ;
V_95:
F_74 () ;
return V_16 -> V_96 ;
}
static int F_176 ( struct V_88 * V_89 )
{
F_22 ( V_89 -> V_185 ) ;
return 0 ;
}
static int F_177 ( struct V_97 * V_98 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_59 * V_60 ;
struct V_13 V_14 ;
struct V_15 * V_99 ;
const struct V_74 * V_75 = F_56 ( V_18 ) ;
int V_45 ;
V_45 = F_164 ( & V_14 , V_16 , V_18 , V_24 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_18 -> V_100 & V_101 ) {
struct V_102 V_103 = {
. V_104 = F_175 ,
. V_95 = F_176 ,
} ;
struct V_13 * V_259 ;
V_259 = F_178 ( sizeof( * V_259 ) , V_34 ) ;
if ( V_259 == NULL )
return - V_41 ;
* V_259 = V_14 ;
V_103 . V_185 = V_259 ;
return F_76 ( V_98 , V_16 , V_18 , & V_103 ) ;
}
if ( V_75 -> V_77 == V_92 )
return - V_12 ;
V_60 = F_165 ( V_14 . V_20 , V_24 [ V_244 ] ) ;
if ( F_77 ( V_60 ) )
return F_78 ( V_60 ) ;
if ( V_60 -> V_36 & V_64 )
return - V_56 ;
V_99 = F_79 ( V_87 , V_34 ) ;
if ( V_99 == NULL )
return - V_41 ;
V_45 = F_173 ( V_99 , & V_14 , V_60 , V_62 , 0 ) ;
if ( V_45 < 0 )
goto V_45;
return F_80 ( V_98 , V_99 , F_16 ( V_16 ) . V_26 ) ;
V_45:
F_66 ( V_99 ) ;
return V_45 ;
}
static int F_179 ( const struct V_13 * V_14 ,
struct V_220 * V_221 ,
const struct V_23 * V_24 )
{
struct V_23 * V_260 [ V_261 + 1 ] ;
int V_45 ;
V_45 = F_116 ( V_260 , V_261 , V_24 , V_262 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_260 [ V_254 ] != NULL )
V_221 -> V_32 = F_43 ( F_44 ( V_260 [ V_254 ] ) ) ;
return 0 ;
}
static int F_180 ( struct V_97 * V_98 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_74 * V_75 = F_56 ( V_18 ) ;
const struct V_218 * V_39 ;
struct V_2 * V_3 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
struct V_19 * V_20 ;
struct V_59 * V_60 ;
struct V_13 V_14 ;
char V_66 [ V_240 ] ;
unsigned int V_32 ;
bool V_161 ;
T_1 V_246 , V_250 , V_36 , V_148 ;
struct V_220 V_221 ;
int V_45 ;
if ( V_24 [ V_235 ] == NULL ||
V_24 [ V_244 ] == NULL ||
V_24 [ V_247 ] == NULL ||
V_24 [ V_63 ] == NULL )
return - V_67 ;
memset ( & V_221 , 0 , sizeof( V_221 ) ) ;
V_246 = V_263 ;
if ( V_24 [ V_245 ] != NULL ) {
V_246 = F_43 ( F_44 ( V_24 [ V_245 ] ) ) ;
if ( ( V_246 & V_264 ) == V_264 )
return - V_67 ;
}
V_221 . V_248 = F_43 ( F_44 ( V_24 [ V_247 ] ) ) ;
if ( V_221 . V_248 == 0 || V_221 . V_248 > F_181 ( struct V_265 , V_185 ) )
return - V_67 ;
V_36 = 0 ;
if ( V_24 [ V_228 ] != NULL ) {
V_36 = F_43 ( F_44 ( V_24 [ V_228 ] ) ) ;
if ( V_36 & ~ ( V_117 | V_266 |
V_229 | V_230 ) )
return - V_67 ;
}
V_250 = 0 ;
if ( V_24 [ V_249 ] != NULL ) {
if ( ! ( V_36 & V_230 ) )
return - V_67 ;
V_250 = F_43 ( F_44 ( V_24 [ V_249 ] ) ) ;
if ( ( V_250 & V_264 ) == V_264 &&
V_250 != V_267 )
return - V_67 ;
if ( V_250 != V_267 ) {
if ( V_24 [ V_251 ] == NULL )
return - V_67 ;
V_221 . V_216 = F_43 ( F_44 ( V_24 [ V_251 ] ) ) ;
if ( V_221 . V_216 == 0 ||
V_221 . V_216 > F_181 ( struct V_265 , V_185 ) )
return - V_67 ;
} else
V_221 . V_216 = sizeof( struct V_265 ) ;
} else if ( V_36 & V_230 )
return - V_67 ;
V_148 = V_233 ;
if ( V_24 [ V_252 ] != NULL )
V_148 = F_43 ( F_44 ( V_24 [ V_252 ] ) ) ;
if ( V_24 [ V_253 ] != NULL ) {
V_45 = F_179 ( & V_14 , & V_221 , V_24 [ V_253 ] ) ;
if ( V_45 < 0 )
return V_45 ;
}
V_161 = V_18 -> V_100 & V_162 ? true : false ;
V_3 = F_10 ( V_1 , V_75 -> V_77 , V_161 ) ;
if ( F_77 ( V_3 ) )
return F_78 ( V_3 ) ;
V_20 = F_48 ( V_3 , V_24 [ V_235 ] ) ;
if ( F_77 ( V_20 ) )
return F_78 ( V_20 ) ;
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
V_60 = F_165 ( V_20 , V_24 [ V_244 ] ) ;
if ( F_77 ( V_60 ) ) {
if ( F_78 ( V_60 ) != - V_56 )
return F_78 ( V_60 ) ;
V_60 = NULL ;
}
if ( V_60 != NULL ) {
if ( V_18 -> V_100 & V_107 )
return - V_108 ;
if ( V_18 -> V_100 & V_109 )
return - V_110 ;
return 0 ;
}
if ( ! ( V_18 -> V_100 & V_162 ) )
return - V_56 ;
V_39 = F_163 ( V_24 , & V_221 , V_148 ) ;
if ( F_77 ( V_39 ) )
return F_78 ( V_39 ) ;
V_32 = 0 ;
if ( V_39 -> V_268 != NULL )
V_32 = V_39 -> V_268 ( V_24 ) ;
V_45 = - V_41 ;
V_60 = F_19 ( sizeof( * V_60 ) + V_32 , V_34 ) ;
if ( V_60 == NULL )
goto V_178;
F_90 ( V_66 , V_24 [ V_244 ] , sizeof( V_60 -> V_66 ) ) ;
V_45 = F_167 ( & V_14 , V_60 , V_66 ) ;
if ( V_45 < 0 )
goto V_179;
F_2 ( & V_60 -> V_118 ) ;
V_60 -> V_39 = V_39 ;
V_60 -> V_246 = V_246 ;
V_60 -> V_248 = V_221 . V_248 ;
V_60 -> V_250 = V_250 ;
V_60 -> V_216 = V_221 . V_216 ;
V_60 -> V_36 = V_36 ;
V_60 -> V_32 = V_221 . V_32 ;
V_60 -> V_148 = V_148 ;
V_45 = V_39 -> V_194 ( V_60 , & V_221 , V_24 ) ;
if ( V_45 < 0 )
goto V_179;
V_45 = F_41 ( & V_14 , V_62 , V_60 ) ;
if ( V_45 < 0 )
goto V_179;
F_4 ( & V_60 -> V_6 , & V_20 -> V_113 ) ;
V_20 -> V_51 ++ ;
return 0 ;
V_179:
F_22 ( V_60 ) ;
V_178:
F_89 ( V_39 -> V_111 ) ;
return V_45 ;
}
static void F_182 ( struct V_59 * V_60 )
{
V_60 -> V_39 -> V_195 ( V_60 ) ;
F_89 ( V_60 -> V_39 -> V_111 ) ;
F_22 ( V_60 ) ;
}
static void F_183 ( const struct V_13 * V_14 , struct V_59 * V_60 )
{
F_7 ( & V_60 -> V_6 ) ;
F_174 ( V_14 , V_60 , V_65 , V_269 ) ;
F_182 ( V_60 ) ;
}
static int F_184 ( struct V_97 * V_98 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_74 * V_75 = F_56 ( V_18 ) ;
struct V_59 * V_60 ;
struct V_13 V_14 ;
int V_45 ;
if ( V_75 -> V_77 == V_92 )
return - V_12 ;
if ( V_24 [ V_235 ] == NULL )
return - V_67 ;
V_45 = F_164 ( & V_14 , V_16 , V_18 , V_24 ) ;
if ( V_45 < 0 )
return V_45 ;
V_60 = F_165 ( V_14 . V_20 , V_24 [ V_244 ] ) ;
if ( F_77 ( V_60 ) )
return F_78 ( V_60 ) ;
if ( V_60 -> V_36 & V_64 )
return - V_56 ;
if ( ! F_93 ( & V_60 -> V_118 ) )
return - V_122 ;
return F_45 ( & V_14 , V_60 ) ;
}
static int F_185 ( const struct V_13 * V_14 ,
const struct V_59 * V_60 ,
const struct V_270 * V_271 ,
const struct V_272 * V_204 )
{
enum V_273 V_274 ;
V_274 = F_186 ( V_60 -> V_250 ) ;
return F_187 ( V_14 , V_274 , & V_204 -> V_185 ,
V_60 -> V_250 == V_267 ?
V_267 : V_263 ) ;
}
int F_188 ( const struct V_13 * V_14 , struct V_59 * V_60 ,
struct V_275 * V_276 )
{
struct V_275 * V_70 ;
struct V_270 V_271 ;
if ( ! F_93 ( & V_60 -> V_118 ) && V_60 -> V_36 & V_117 )
return - V_122 ;
if ( V_60 -> V_36 & V_230 ) {
F_9 (i, &set->bindings, list) {
if ( V_70 -> V_22 == V_276 -> V_22 )
goto V_277;
}
V_271 . V_278 = 0 ;
V_271 . V_279 = 0 ;
V_271 . V_45 = 0 ;
V_271 . V_280 = F_185 ;
V_60 -> V_39 -> V_281 ( V_14 , V_60 , & V_271 ) ;
if ( V_271 . V_45 < 0 ) {
if ( V_60 -> V_36 & V_117 )
F_183 ( V_14 , V_60 ) ;
return V_271 . V_45 ;
}
}
V_277:
V_276 -> V_22 = V_14 -> V_22 ;
F_4 ( & V_276 -> V_6 , & V_60 -> V_118 ) ;
return 0 ;
}
void F_189 ( const struct V_13 * V_14 , struct V_59 * V_60 ,
struct V_275 * V_276 )
{
F_7 ( & V_276 -> V_6 ) ;
if ( F_93 ( & V_60 -> V_118 ) && V_60 -> V_36 & V_117 &&
! ( V_60 -> V_36 & V_64 ) )
F_183 ( V_14 , V_60 ) ;
}
static int F_190 ( struct V_13 * V_14 ,
const struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
bool V_33 )
{
const struct V_74 * V_75 = F_56 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
V_3 = F_10 ( V_1 , V_75 -> V_77 , false ) ;
if ( F_77 ( V_3 ) )
return F_78 ( V_3 ) ;
V_20 = F_48 ( V_3 , V_24 [ V_282 ] ) ;
if ( F_77 ( V_20 ) )
return F_78 ( V_20 ) ;
if ( ! V_33 && ( V_20 -> V_36 & V_43 ) )
return - V_56 ;
F_14 ( V_14 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return 0 ;
}
static int F_191 ( struct V_15 * V_16 ,
const struct V_59 * V_60 ,
const struct V_272 * V_204 )
{
unsigned char * V_283 = F_192 ( V_16 ) ;
struct V_23 * V_128 ;
V_128 = F_107 ( V_16 , V_205 ) ;
if ( V_128 == NULL )
goto V_76;
if ( F_193 ( V_16 , V_284 , & V_204 -> V_285 , V_263 ,
V_60 -> V_248 ) < 0 )
goto V_76;
if ( V_60 -> V_36 & V_230 &&
! ( V_204 -> V_36 & V_286 ) &&
F_193 ( V_16 , V_287 , & V_204 -> V_185 ,
V_60 -> V_250 == V_267 ? V_267 : V_263 ,
V_60 -> V_216 ) < 0 )
goto V_76;
if ( V_204 -> V_36 != 0 )
if ( F_59 ( V_16 , V_288 , F_60 ( V_204 -> V_36 ) ) )
goto V_76;
F_110 ( V_16 , V_128 ) ;
return 0 ;
V_76:
F_62 ( V_16 , V_283 ) ;
return - V_289 ;
}
static int F_194 ( const struct V_13 * V_14 ,
const struct V_59 * V_60 ,
const struct V_270 * V_271 ,
const struct V_272 * V_204 )
{
struct V_290 * args ;
args = F_195 ( V_271 , struct V_290 , V_271 ) ;
return F_191 ( args -> V_16 , V_60 , V_204 ) ;
}
static int F_196 ( struct V_15 * V_16 , struct V_88 * V_89 )
{
const struct V_59 * V_60 ;
struct V_290 args ;
struct V_13 V_14 ;
struct V_23 * V_24 [ V_291 + 1 ] ;
struct V_74 * V_75 ;
struct V_17 * V_18 ;
struct V_23 * V_128 ;
T_1 V_26 , V_28 ;
int V_73 , V_45 ;
V_45 = F_197 ( V_89 -> V_18 , sizeof( struct V_74 ) , V_24 ,
V_291 , V_292 ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = F_190 ( & V_14 , V_89 -> V_16 , V_89 -> V_18 , ( void * ) V_24 ,
false ) ;
if ( V_45 < 0 )
return V_45 ;
V_60 = F_165 ( V_14 . V_20 , V_24 [ V_293 ] ) ;
if ( F_77 ( V_60 ) )
return F_78 ( V_60 ) ;
if ( V_60 -> V_36 & V_64 )
return - V_56 ;
V_73 = V_294 ;
V_73 |= V_5 << 8 ;
V_26 = F_16 ( V_89 -> V_16 ) . V_26 ;
V_28 = V_89 -> V_18 -> V_29 ;
V_18 = F_55 ( V_16 , V_26 , V_28 , V_73 , sizeof( struct V_74 ) ,
V_94 ) ;
if ( V_18 == NULL )
goto V_76;
V_75 = F_56 ( V_18 ) ;
V_75 -> V_77 = V_14 . V_3 -> V_9 ;
V_75 -> V_78 = V_79 ;
V_75 -> V_80 = F_57 ( V_14 . V_1 -> V_7 . V_81 & 0xffff ) ;
if ( F_58 ( V_16 , V_282 , V_14 . V_20 -> V_66 ) )
goto V_76;
if ( F_58 ( V_16 , V_293 , V_60 -> V_66 ) )
goto V_76;
V_128 = F_107 ( V_16 , V_295 ) ;
if ( V_128 == NULL )
goto V_76;
args . V_89 = V_89 ;
args . V_16 = V_16 ;
args . V_271 . V_278 = V_89 -> args [ 0 ] ;
args . V_271 . V_279 = 0 ;
args . V_271 . V_45 = 0 ;
args . V_271 . V_280 = F_194 ;
V_60 -> V_39 -> V_281 ( & V_14 , V_60 , & args . V_271 ) ;
F_110 ( V_16 , V_128 ) ;
F_61 ( V_16 , V_18 ) ;
if ( args . V_271 . V_45 && args . V_271 . V_45 != - V_289 )
return args . V_271 . V_45 ;
if ( args . V_271 . V_279 == V_89 -> args [ 0 ] )
return 0 ;
V_89 -> args [ 0 ] = args . V_271 . V_279 ;
return V_16 -> V_96 ;
V_76:
return - V_136 ;
}
static int F_198 ( struct V_97 * V_98 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_59 * V_60 ;
struct V_13 V_14 ;
int V_45 ;
V_45 = F_190 ( & V_14 , V_16 , V_18 , V_24 , false ) ;
if ( V_45 < 0 )
return V_45 ;
V_60 = F_165 ( V_14 . V_20 , V_24 [ V_293 ] ) ;
if ( F_77 ( V_60 ) )
return F_78 ( V_60 ) ;
if ( V_60 -> V_36 & V_64 )
return - V_56 ;
if ( V_18 -> V_100 & V_101 ) {
struct V_102 V_103 = {
. V_104 = F_196 ,
} ;
return F_76 ( V_98 , V_16 , V_18 , & V_103 ) ;
}
return - V_110 ;
}
static int F_199 ( struct V_15 * V_16 ,
const struct V_13 * V_14 , T_1 V_28 ,
T_1 V_26 , int V_73 , T_6 V_36 ,
const struct V_59 * V_60 ,
const struct V_272 * V_204 )
{
struct V_74 * V_75 ;
struct V_17 * V_18 ;
struct V_23 * V_128 ;
int V_45 ;
V_73 |= V_5 << 8 ;
V_18 = F_55 ( V_16 , V_26 , V_28 , V_73 , sizeof( struct V_74 ) ,
V_36 ) ;
if ( V_18 == NULL )
goto V_76;
V_75 = F_56 ( V_18 ) ;
V_75 -> V_77 = V_14 -> V_3 -> V_9 ;
V_75 -> V_78 = V_79 ;
V_75 -> V_80 = F_57 ( V_14 -> V_1 -> V_7 . V_81 & 0xffff ) ;
if ( F_58 ( V_16 , V_235 , V_14 -> V_20 -> V_66 ) )
goto V_76;
if ( F_58 ( V_16 , V_244 , V_60 -> V_66 ) )
goto V_76;
V_128 = F_107 ( V_16 , V_295 ) ;
if ( V_128 == NULL )
goto V_76;
V_45 = F_191 ( V_16 , V_60 , V_204 ) ;
if ( V_45 < 0 )
goto V_76;
F_110 ( V_16 , V_128 ) ;
return F_61 ( V_16 , V_18 ) ;
V_76:
F_62 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_200 ( const struct V_13 * V_14 ,
const struct V_59 * V_60 ,
const struct V_272 * V_204 ,
int V_73 , T_6 V_36 )
{
struct V_1 * V_1 = V_14 -> V_1 ;
T_1 V_26 = V_14 -> V_26 ;
struct V_15 * V_16 ;
int V_45 ;
if ( ! V_14 -> V_27 && ! F_64 ( V_1 , V_85 ) )
return 0 ;
V_45 = - V_86 ;
V_16 = F_65 ( V_87 , V_34 ) ;
if ( V_16 == NULL )
goto V_45;
V_45 = F_199 ( V_16 , V_14 , 0 , V_26 , V_73 , V_36 ,
V_60 , V_204 ) ;
if ( V_45 < 0 ) {
F_66 ( V_16 ) ;
goto V_45;
}
V_45 = F_67 ( V_16 , V_1 , V_26 , V_85 , V_14 -> V_27 ,
V_34 ) ;
V_45:
if ( V_45 < 0 )
F_68 ( V_1 , V_26 , V_85 , V_45 ) ;
return V_45 ;
}
static struct V_30 * F_201 ( struct V_13 * V_14 ,
int V_31 ,
struct V_59 * V_60 )
{
struct V_30 * V_33 ;
V_33 = F_18 ( V_14 , V_31 , sizeof( struct V_296 ) ) ;
if ( V_33 == NULL )
return NULL ;
F_202 ( V_33 ) = V_60 ;
return V_33 ;
}
static int F_203 ( struct V_13 * V_14 , struct V_59 * V_60 ,
const struct V_23 * V_151 )
{
struct V_23 * V_24 [ V_297 + 1 ] ;
struct V_298 V_299 , V_300 ;
struct V_272 V_204 ;
struct V_275 * V_276 ;
enum V_273 V_274 ;
struct V_30 * V_33 ;
int V_45 ;
if ( V_60 -> V_32 && V_60 -> V_301 == V_60 -> V_32 )
return - V_243 ;
V_45 = F_116 ( V_24 , V_297 , V_151 ,
V_302 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_24 [ V_284 ] == NULL )
return - V_67 ;
V_204 . V_36 = 0 ;
if ( V_24 [ V_288 ] != NULL ) {
V_204 . V_36 = F_43 ( F_44 ( V_24 [ V_288 ] ) ) ;
if ( V_204 . V_36 & ~ V_286 )
return - V_67 ;
}
if ( V_60 -> V_36 & V_230 ) {
if ( V_24 [ V_287 ] == NULL &&
! ( V_204 . V_36 & V_286 ) )
return - V_67 ;
if ( V_24 [ V_287 ] != NULL &&
V_204 . V_36 & V_286 )
return - V_67 ;
} else {
if ( V_24 [ V_287 ] != NULL )
return - V_67 ;
}
V_45 = F_204 ( V_14 , & V_204 . V_285 , & V_299 , V_24 [ V_284 ] ) ;
if ( V_45 < 0 )
goto V_178;
V_45 = - V_67 ;
if ( V_299 . type != V_263 || V_299 . V_96 != V_60 -> V_248 )
goto V_179;
V_45 = - V_108 ;
if ( V_60 -> V_39 -> V_303 ( V_60 , & V_204 ) == 0 )
goto V_179;
if ( V_24 [ V_287 ] != NULL ) {
V_45 = F_204 ( V_14 , & V_204 . V_185 , & V_300 , V_24 [ V_287 ] ) ;
if ( V_45 < 0 )
goto V_179;
V_45 = - V_67 ;
if ( V_60 -> V_250 != V_267 && V_300 . V_96 != V_60 -> V_216 )
goto V_217;
V_274 = F_186 ( V_60 -> V_250 ) ;
F_9 (binding, &set->bindings, list) {
struct V_13 V_304 = {
. V_3 = V_14 -> V_3 ,
. V_20 = V_14 -> V_20 ,
. V_22 = (struct V_21 * ) V_276 -> V_22 ,
} ;
V_45 = F_187 ( & V_304 , V_274 ,
& V_204 . V_185 , V_300 . type ) ;
if ( V_45 < 0 )
goto V_217;
}
}
V_33 = F_201 ( V_14 , V_294 , V_60 ) ;
if ( V_33 == NULL )
goto V_217;
V_45 = V_60 -> V_39 -> V_305 ( V_60 , & V_204 ) ;
if ( V_45 < 0 )
goto V_306;
V_296 ( V_33 ) = V_204 ;
F_27 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_44 ) ;
return 0 ;
V_306:
F_22 ( V_33 ) ;
V_217:
if ( V_24 [ V_287 ] != NULL )
F_205 ( & V_204 . V_185 , V_300 . type ) ;
V_179:
F_205 ( & V_204 . V_285 , V_299 . type ) ;
V_178:
return V_45 ;
}
static int F_206 ( struct V_97 * V_98 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
const struct V_23 * V_151 ;
struct V_59 * V_60 ;
struct V_13 V_14 ;
int V_213 , V_45 = 0 ;
if ( V_24 [ V_295 ] == NULL )
return - V_67 ;
V_45 = F_190 ( & V_14 , V_16 , V_18 , V_24 , true ) ;
if ( V_45 < 0 )
return V_45 ;
V_60 = F_165 ( V_14 . V_20 , V_24 [ V_293 ] ) ;
if ( F_77 ( V_60 ) ) {
if ( V_24 [ V_307 ] ) {
V_60 = F_166 ( V_1 ,
V_24 [ V_307 ] ) ;
}
if ( F_77 ( V_60 ) )
return F_78 ( V_60 ) ;
}
if ( ! F_93 ( & V_60 -> V_118 ) && V_60 -> V_36 & V_266 )
return - V_122 ;
F_157 (attr, nla[NFTA_SET_ELEM_LIST_ELEMENTS], rem) {
V_45 = F_203 ( & V_14 , V_60 , V_151 ) ;
if ( V_45 < 0 )
break;
V_60 -> V_301 ++ ;
}
return V_45 ;
}
static int F_207 ( struct V_13 * V_14 , struct V_59 * V_60 ,
const struct V_23 * V_151 )
{
struct V_23 * V_24 [ V_297 + 1 ] ;
struct V_298 V_221 ;
struct V_272 V_204 ;
struct V_30 * V_33 ;
int V_45 ;
V_45 = F_116 ( V_24 , V_297 , V_151 ,
V_302 ) ;
if ( V_45 < 0 )
goto V_178;
V_45 = - V_67 ;
if ( V_24 [ V_284 ] == NULL )
goto V_178;
V_45 = F_204 ( V_14 , & V_204 . V_285 , & V_221 , V_24 [ V_284 ] ) ;
if ( V_45 < 0 )
goto V_178;
V_45 = - V_67 ;
if ( V_221 . type != V_263 || V_221 . V_96 != V_60 -> V_248 )
goto V_179;
V_45 = V_60 -> V_39 -> V_303 ( V_60 , & V_204 ) ;
if ( V_45 < 0 )
goto V_179;
V_33 = F_201 ( V_14 , V_308 , V_60 ) ;
if ( V_33 == NULL ) {
V_45 = - V_41 ;
goto V_179;
}
V_296 ( V_33 ) = V_204 ;
F_27 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_44 ) ;
return 0 ;
V_179:
F_205 ( & V_204 . V_285 , V_221 . type ) ;
V_178:
return V_45 ;
}
static int F_208 ( struct V_97 * V_98 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_23 * V_151 ;
struct V_59 * V_60 ;
struct V_13 V_14 ;
int V_213 , V_45 = 0 ;
if ( V_24 [ V_295 ] == NULL )
return - V_67 ;
V_45 = F_190 ( & V_14 , V_16 , V_18 , V_24 , false ) ;
if ( V_45 < 0 )
return V_45 ;
V_60 = F_165 ( V_14 . V_20 , V_24 [ V_293 ] ) ;
if ( F_77 ( V_60 ) )
return F_78 ( V_60 ) ;
if ( ! F_93 ( & V_60 -> V_118 ) && V_60 -> V_36 & V_266 )
return - V_122 ;
F_157 (attr, nla[NFTA_SET_ELEM_LIST_ELEMENTS], rem) {
V_45 = F_207 ( & V_14 , V_60 , V_151 ) ;
if ( V_45 < 0 )
break;
V_60 -> V_301 -- ;
}
return V_45 ;
}
static int F_209 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_26 , T_1 V_28 )
{
struct V_17 * V_18 ;
struct V_74 * V_75 ;
int V_73 = ( V_5 << 8 ) | V_309 ;
V_18 = F_55 ( V_16 , V_26 , V_28 , V_73 , sizeof( struct V_74 ) , 0 ) ;
if ( V_18 == NULL )
goto V_76;
V_75 = F_56 ( V_18 ) ;
V_75 -> V_77 = V_120 ;
V_75 -> V_78 = V_79 ;
V_75 -> V_80 = F_57 ( V_1 -> V_7 . V_81 & 0xffff ) ;
if ( F_59 ( V_16 , V_310 , F_60 ( V_1 -> V_7 . V_81 ) ) )
goto V_76;
return F_61 ( V_16 , V_18 ) ;
V_76:
F_62 ( V_16 , V_18 ) ;
return - V_289 ;
}
static int F_210 ( struct V_1 * V_1 , struct V_15 * V_16 , int V_73 )
{
struct V_17 * V_18 = F_73 ( V_16 ) ;
struct V_15 * V_99 ;
int V_45 ;
if ( F_17 ( V_18 ) &&
! F_64 ( V_1 , V_85 ) )
return 0 ;
V_45 = - V_86 ;
V_99 = F_65 ( V_87 , V_34 ) ;
if ( V_99 == NULL )
goto V_45;
V_45 = F_209 ( V_99 , V_1 , F_16 ( V_16 ) . V_26 ,
V_18 -> V_29 ) ;
if ( V_45 < 0 ) {
F_66 ( V_99 ) ;
goto V_45;
}
V_45 = F_67 ( V_99 , V_1 , F_16 ( V_16 ) . V_26 ,
V_85 , F_17 ( V_18 ) , V_34 ) ;
V_45:
if ( V_45 < 0 ) {
F_68 ( V_1 , F_16 ( V_16 ) . V_26 , V_85 ,
V_45 ) ;
}
return V_45 ;
}
static int F_211 ( struct V_97 * V_98 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
struct V_15 * V_99 ;
int V_45 ;
V_99 = F_79 ( V_87 , V_34 ) ;
if ( V_99 == NULL )
return - V_41 ;
V_45 = F_209 ( V_99 , V_1 , F_16 ( V_16 ) . V_26 ,
V_18 -> V_29 ) ;
if ( V_45 < 0 )
goto V_45;
return F_80 ( V_98 , V_99 , F_16 ( V_16 ) . V_26 ) ;
V_45:
F_66 ( V_99 ) ;
return V_45 ;
}
static void F_212 ( struct V_30 * V_33 )
{
struct F_25 * V_140 ;
if ( F_131 ( V_33 ) [ 0 ] )
strcpy ( V_33 -> V_14 . V_22 -> V_66 , F_131 ( V_33 ) ) ;
if ( ! ( V_33 -> V_14 . V_22 -> V_36 & V_38 ) )
return;
V_140 = F_25 ( V_33 -> V_14 . V_22 ) ;
F_121 ( V_140 , F_128 ( V_33 ) ) ;
switch ( F_130 ( V_33 ) ) {
case V_163 :
case V_160 :
V_140 -> V_148 = F_130 ( V_33 ) ;
break;
}
}
static void F_213 ( struct V_30 * V_33 )
{
switch ( V_33 -> V_31 ) {
case V_46 :
F_96 ( & V_33 -> V_14 ) ;
break;
case V_50 :
F_126 ( V_33 -> V_14 . V_22 ) ;
break;
case V_58 :
F_152 ( & V_33 -> V_14 , V_57 ( V_33 ) ) ;
break;
case V_65 :
F_182 ( V_61 ( V_33 ) ) ;
break;
}
F_22 ( V_33 ) ;
}
static int F_214 ( struct V_15 * V_16 )
{
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
struct V_30 * V_33 , * V_196 ;
struct V_296 * V_311 ;
while ( ++ V_1 -> V_7 . V_81 == 0 ) ;
V_1 -> V_7 . V_55 = F_32 ( V_1 ) ;
F_124 () ;
F_92 (trans, next, &net->nft.commit_list, list) {
switch ( V_33 -> V_31 ) {
case V_42 :
if ( F_86 ( V_33 ) ) {
if ( ! F_85 ( V_33 ) ) {
F_83 ( V_33 -> V_14 . V_3 ,
V_33 -> V_14 . V_20 ) ;
V_33 -> V_14 . V_20 -> V_36 |= V_37 ;
}
} else {
V_33 -> V_14 . V_20 -> V_36 &= ~ V_43 ;
}
F_63 ( & V_33 -> V_14 , V_42 ) ;
F_20 ( V_33 ) ;
break;
case V_46 :
F_63 ( & V_33 -> V_14 , V_46 ) ;
break;
case V_48 :
if ( F_129 ( V_33 ) )
F_212 ( V_33 ) ;
else
V_33 -> V_14 . V_22 -> V_36 &= ~ V_49 ;
F_112 ( & V_33 -> V_14 , V_48 ) ;
F_20 ( V_33 ) ;
break;
case V_50 :
F_112 ( & V_33 -> V_14 , V_50 ) ;
F_23 ( V_33 -> V_14 . V_20 ,
V_33 -> V_14 . V_22 ,
V_33 -> V_14 . V_3 -> V_105 ) ;
break;
case V_208 :
F_36 ( V_33 -> V_14 . V_1 , V_57 ( V_33 ) ) ;
F_149 ( & V_33 -> V_14 ,
V_57 ( V_33 ) ,
V_208 ) ;
F_20 ( V_33 ) ;
break;
case V_58 :
F_7 ( & V_57 ( V_33 ) -> V_6 ) ;
F_149 ( & V_33 -> V_14 ,
V_57 ( V_33 ) ,
V_58 ) ;
break;
case V_62 :
V_61 ( V_33 ) -> V_36 &= ~ V_64 ;
if ( V_61 ( V_33 ) -> V_36 & V_117 &&
! F_93 ( & V_61 ( V_33 ) -> V_118 ) )
V_33 -> V_14 . V_20 -> V_51 -- ;
F_174 ( & V_33 -> V_14 , V_61 ( V_33 ) ,
V_62 , V_34 ) ;
F_20 ( V_33 ) ;
break;
case V_65 :
F_174 ( & V_33 -> V_14 , V_61 ( V_33 ) ,
V_65 , V_34 ) ;
break;
case V_294 :
F_200 ( & V_33 -> V_14 ,
F_202 ( V_33 ) ,
& V_296 ( V_33 ) ,
V_294 , 0 ) ;
F_20 ( V_33 ) ;
break;
case V_308 :
V_311 = (struct V_296 * ) V_33 -> V_185 ;
F_200 ( & V_33 -> V_14 , V_311 -> V_60 ,
& V_311 -> V_204 ,
V_308 , 0 ) ;
V_311 -> V_60 -> V_39 -> V_303 ( V_311 -> V_60 , & V_311 -> V_204 ) ;
V_311 -> V_60 -> V_39 -> remove ( V_311 -> V_60 , & V_311 -> V_204 ) ;
F_205 ( & V_311 -> V_204 . V_285 , V_263 ) ;
if ( V_311 -> V_204 . V_36 & V_230 ) {
F_205 ( & V_311 -> V_204 . V_185 ,
V_311 -> V_60 -> V_250 ) ;
}
F_20 ( V_33 ) ;
break;
}
}
F_124 () ;
F_92 (trans, next, &net->nft.commit_list, list) {
F_21 ( & V_33 -> V_6 ) ;
F_213 ( V_33 ) ;
}
F_210 ( V_1 , V_16 , V_309 ) ;
return 0 ;
}
static void F_215 ( struct V_30 * V_33 )
{
switch ( V_33 -> V_31 ) {
case V_42 :
F_96 ( & V_33 -> V_14 ) ;
break;
case V_48 :
F_126 ( V_33 -> V_14 . V_22 ) ;
break;
case V_208 :
F_152 ( & V_33 -> V_14 , V_57 ( V_33 ) ) ;
break;
case V_62 :
F_182 ( V_61 ( V_33 ) ) ;
break;
}
F_22 ( V_33 ) ;
}
static int F_216 ( struct V_15 * V_16 )
{
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
struct V_30 * V_33 , * V_196 ;
struct V_59 * V_60 ;
F_92 (trans, next, &net->nft.commit_list, list) {
switch ( V_33 -> V_31 ) {
case V_42 :
if ( F_86 ( V_33 ) ) {
if ( F_85 ( V_33 ) ) {
F_83 ( V_33 -> V_14 . V_3 ,
V_33 -> V_14 . V_20 ) ;
V_33 -> V_14 . V_20 -> V_36 |= V_37 ;
}
F_20 ( V_33 ) ;
} else {
F_7 ( & V_33 -> V_14 . V_20 -> V_6 ) ;
}
break;
case V_46 :
F_4 ( & V_33 -> V_14 . V_20 -> V_6 ,
& V_33 -> V_14 . V_3 -> V_4 ) ;
F_20 ( V_33 ) ;
break;
case V_48 :
if ( F_129 ( V_33 ) ) {
if ( F_128 ( V_33 ) )
F_125 ( F_128 ( V_33 ) ) ;
F_20 ( V_33 ) ;
} else {
V_33 -> V_14 . V_20 -> V_51 -- ;
F_7 ( & V_33 -> V_14 . V_22 -> V_6 ) ;
F_23 ( V_33 -> V_14 . V_20 ,
V_33 -> V_14 . V_22 ,
V_33 -> V_14 . V_3 -> V_105 ) ;
}
break;
case V_50 :
V_33 -> V_14 . V_20 -> V_51 ++ ;
F_4 ( & V_33 -> V_14 . V_22 -> V_6 ,
& V_33 -> V_14 . V_20 -> V_112 ) ;
F_20 ( V_33 ) ;
break;
case V_208 :
V_33 -> V_14 . V_22 -> V_51 -- ;
F_7 ( & V_57 ( V_33 ) -> V_6 ) ;
break;
case V_58 :
V_33 -> V_14 . V_22 -> V_51 ++ ;
F_36 ( V_33 -> V_14 . V_1 , V_57 ( V_33 ) ) ;
F_20 ( V_33 ) ;
break;
case V_62 :
V_33 -> V_14 . V_20 -> V_51 -- ;
F_7 ( & V_61 ( V_33 ) -> V_6 ) ;
break;
case V_65 :
V_33 -> V_14 . V_20 -> V_51 ++ ;
F_4 ( & V_61 ( V_33 ) -> V_6 ,
& V_33 -> V_14 . V_20 -> V_113 ) ;
F_20 ( V_33 ) ;
break;
case V_294 :
F_202 ( V_33 ) -> V_301 -- ;
V_60 = F_202 ( V_33 ) ;
V_60 -> V_39 -> V_303 ( V_60 , & V_296 ( V_33 ) ) ;
V_60 -> V_39 -> remove ( V_60 , & V_296 ( V_33 ) ) ;
F_20 ( V_33 ) ;
break;
case V_308 :
F_202 ( V_33 ) -> V_301 ++ ;
F_20 ( V_33 ) ;
break;
}
}
F_124 () ;
F_217 (trans, next,
&net->nft.commit_list, list) {
F_21 ( & V_33 -> V_6 ) ;
F_215 ( V_33 ) ;
}
return 0 ;
}
int F_218 ( const struct V_21 * V_22 ,
enum V_312 type )
{
const struct F_25 * V_140 ;
if ( V_22 -> V_36 & V_38 ) {
V_140 = F_25 ( V_22 ) ;
if ( V_140 -> type -> type != type )
return - V_110 ;
}
return 0 ;
}
static int F_219 ( const struct V_13 * V_14 ,
const struct V_59 * V_60 ,
const struct V_270 * V_271 ,
const struct V_272 * V_204 )
{
if ( V_204 -> V_36 & V_286 )
return 0 ;
switch ( V_204 -> V_185 . V_313 ) {
case V_314 :
case V_315 :
return F_220 ( V_14 , V_204 -> V_185 . V_22 ) ;
default:
return 0 ;
}
}
static int F_220 ( const struct V_13 * V_14 ,
const struct V_21 * V_22 )
{
const struct V_52 * V_53 ;
const struct V_182 * V_183 , * V_316 ;
const struct V_59 * V_60 ;
struct V_275 * V_276 ;
struct V_270 V_271 ;
if ( V_14 -> V_22 == V_22 )
return - V_317 ;
F_9 (rule, &chain->rules, list) {
F_146 (expr, last, rule) {
const struct V_265 * V_185 = NULL ;
int V_45 ;
if ( ! V_183 -> V_39 -> V_318 )
continue;
V_45 = V_183 -> V_39 -> V_318 ( V_14 , V_183 , & V_185 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_185 == NULL )
continue;
switch ( V_185 -> V_313 ) {
case V_314 :
case V_315 :
V_45 = F_220 ( V_14 , V_185 -> V_22 ) ;
if ( V_45 < 0 )
return V_45 ;
default:
break;
}
}
}
F_9 (set, &ctx->table->sets, list) {
if ( ! ( V_60 -> V_36 & V_230 ) ||
V_60 -> V_250 != V_267 )
continue;
F_9 (binding, &set->bindings, list) {
if ( V_276 -> V_22 != V_22 )
continue;
V_271 . V_278 = 0 ;
V_271 . V_279 = 0 ;
V_271 . V_45 = 0 ;
V_271 . V_280 = F_219 ;
V_60 -> V_39 -> V_281 ( V_14 , V_60 , & V_271 ) ;
if ( V_271 . V_45 < 0 )
return V_271 . V_45 ;
}
}
return 0 ;
}
int F_221 ( enum V_273 V_319 )
{
if ( V_319 <= V_320 )
return - V_67 ;
if ( V_319 > V_321 )
return - V_322 ;
return 0 ;
}
int F_222 ( enum V_273 V_319 )
{
if ( V_319 < V_320 )
return - V_67 ;
if ( V_319 > V_321 )
return - V_322 ;
return 0 ;
}
int F_187 ( const struct V_13 * V_14 , enum V_273 V_319 ,
const struct V_265 * V_185 ,
enum V_323 type )
{
int V_45 ;
switch ( V_319 ) {
case V_320 :
if ( V_185 == NULL || type != V_267 )
return - V_67 ;
if ( V_185 -> V_313 == V_315 || V_185 -> V_313 == V_314 ) {
V_45 = F_220 ( V_14 , V_185 -> V_22 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_14 -> V_22 -> V_324 + 1 > V_185 -> V_22 -> V_324 ) {
if ( V_14 -> V_22 -> V_324 + 1 == V_325 )
return - V_326 ;
V_185 -> V_22 -> V_324 = V_14 -> V_22 -> V_324 + 1 ;
}
}
return 0 ;
default:
if ( V_185 != NULL && type != V_263 )
return - V_67 ;
return 0 ;
}
}
static int F_223 ( const struct V_13 * V_14 , struct V_265 * V_185 ,
struct V_298 * V_221 , const struct V_23 * V_24 )
{
struct V_23 * V_152 [ V_327 + 1 ] ;
struct V_21 * V_22 ;
int V_45 ;
V_45 = F_116 ( V_152 , V_327 , V_24 , V_328 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( ! V_152 [ V_329 ] )
return - V_67 ;
V_185 -> V_313 = F_43 ( F_44 ( V_152 [ V_329 ] ) ) ;
switch ( V_185 -> V_313 ) {
default:
switch ( V_185 -> V_313 & V_330 ) {
case V_160 :
case V_163 :
case V_331 :
break;
default:
return - V_67 ;
}
case V_332 :
case V_333 :
case V_334 :
V_221 -> V_96 = sizeof( V_185 -> V_313 ) ;
break;
case V_314 :
case V_315 :
if ( ! V_152 [ V_335 ] )
return - V_67 ;
V_22 = F_101 ( V_14 -> V_20 ,
V_152 [ V_335 ] ) ;
if ( F_77 ( V_22 ) )
return F_78 ( V_22 ) ;
if ( V_22 -> V_36 & V_38 )
return - V_110 ;
V_22 -> V_51 ++ ;
V_185 -> V_22 = V_22 ;
V_221 -> V_96 = sizeof( V_185 ) ;
break;
}
V_221 -> type = V_267 ;
return 0 ;
}
static void F_224 ( const struct V_265 * V_185 )
{
switch ( V_185 -> V_313 ) {
case V_314 :
case V_315 :
V_185 -> V_22 -> V_51 -- ;
break;
}
}
static int F_225 ( struct V_15 * V_16 , const struct V_265 * V_185 )
{
struct V_23 * V_128 ;
V_128 = F_107 ( V_16 , V_336 ) ;
if ( ! V_128 )
goto V_76;
if ( F_59 ( V_16 , V_329 , F_60 ( V_185 -> V_313 ) ) )
goto V_76;
switch ( V_185 -> V_313 ) {
case V_314 :
case V_315 :
if ( F_58 ( V_16 , V_335 , V_185 -> V_22 -> V_66 ) )
goto V_76;
}
F_110 ( V_16 , V_128 ) ;
return 0 ;
V_76:
return - 1 ;
}
static int F_226 ( const struct V_13 * V_14 , struct V_265 * V_185 ,
struct V_298 * V_221 , const struct V_23 * V_24 )
{
unsigned int V_96 ;
V_96 = F_52 ( V_24 ) ;
if ( V_96 == 0 )
return - V_67 ;
if ( V_96 > sizeof( V_185 -> V_185 ) )
return - V_166 ;
F_159 ( V_185 -> V_185 , V_24 , sizeof( V_185 -> V_185 ) ) ;
V_221 -> type = V_263 ;
V_221 -> V_96 = V_96 ;
return 0 ;
}
static int F_227 ( struct V_15 * V_16 , const struct V_265 * V_185 ,
unsigned int V_96 )
{
return F_147 ( V_16 , V_337 , V_96 , V_185 -> V_185 ) ;
}
int F_204 ( const struct V_13 * V_14 , struct V_265 * V_185 ,
struct V_298 * V_221 , const struct V_23 * V_24 )
{
struct V_23 * V_152 [ V_338 + 1 ] ;
int V_45 ;
V_45 = F_116 ( V_152 , V_338 , V_24 , V_339 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_152 [ V_337 ] )
return F_226 ( V_14 , V_185 , V_221 , V_152 [ V_337 ] ) ;
if ( V_152 [ V_336 ] && V_14 != NULL )
return F_223 ( V_14 , V_185 , V_221 , V_152 [ V_336 ] ) ;
return - V_67 ;
}
void F_205 ( const struct V_265 * V_185 , enum V_323 type )
{
switch ( type ) {
case V_263 :
return;
case V_267 :
return F_224 ( V_185 ) ;
default:
F_228 ( 1 ) ;
}
}
int F_193 ( struct V_15 * V_16 , int V_151 , const struct V_265 * V_185 ,
enum V_323 type , unsigned int V_96 )
{
struct V_23 * V_128 ;
int V_45 ;
V_128 = F_107 ( V_16 , V_151 ) ;
if ( V_128 == NULL )
return - 1 ;
switch ( type ) {
case V_263 :
V_45 = F_227 ( V_16 , V_185 , V_96 ) ;
break;
case V_267 :
V_45 = F_225 ( V_16 , V_185 ) ;
break;
default:
V_45 = - V_67 ;
F_228 ( 1 ) ;
}
F_110 ( V_16 , V_128 ) ;
return V_45 ;
}
static int F_229 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_7 . V_8 ) ;
F_2 ( & V_1 -> V_7 . V_44 ) ;
V_1 -> V_7 . V_81 = 1 ;
return 0 ;
}
static int T_8 F_230 ( void )
{
int V_45 ;
V_188 = F_178 ( sizeof( struct V_187 ) * V_215 ,
V_34 ) ;
if ( V_188 == NULL ) {
V_45 = - V_41 ;
goto V_178;
}
V_45 = F_231 () ;
if ( V_45 < 0 )
goto V_179;
V_45 = F_232 ( & V_340 ) ;
if ( V_45 < 0 )
goto V_217;
F_233 ( L_6 ) ;
return F_234 ( & V_341 ) ;
V_217:
F_235 () ;
V_179:
F_22 ( V_188 ) ;
V_178:
return V_45 ;
}
static void T_9 F_236 ( void )
{
F_237 ( & V_341 ) ;
F_238 ( & V_340 ) ;
F_239 () ;
F_235 () ;
F_22 ( V_188 ) ;
}
