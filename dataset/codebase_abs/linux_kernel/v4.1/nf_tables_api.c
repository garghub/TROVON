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
return ( V_53 -> V_54 & F_32 ( V_1 ) ) == 0 ;
}
static inline int
F_33 ( struct V_1 * V_1 , const struct V_52 * V_53 )
{
return ( V_53 -> V_54 & F_34 ( V_1 ) ) == 0 ;
}
static inline void
F_35 ( struct V_1 * V_1 , struct V_52 * V_53 )
{
V_53 -> V_54 = F_32 ( V_1 ) ;
}
static inline void
F_36 ( struct V_1 * V_1 , struct V_52 * V_53 )
{
V_53 -> V_54 = F_34 ( V_1 ) ;
}
static inline void F_37 ( struct V_1 * V_1 , struct V_52 * V_53 )
{
V_53 -> V_54 &= ~ F_34 ( V_1 ) ;
}
static int
F_38 ( struct V_13 * V_14 , struct V_52 * V_53 )
{
if ( F_33 ( V_14 -> V_1 , V_53 ) ) {
F_36 ( V_14 -> V_1 , V_53 ) ;
V_14 -> V_22 -> V_51 -- ;
return 0 ;
}
return - V_55 ;
}
static struct V_30 * F_39 ( struct V_13 * V_14 , int V_31 ,
struct V_52 * V_53 )
{
struct V_30 * V_33 ;
V_33 = F_18 ( V_14 , V_31 , sizeof( struct V_56 ) ) ;
if ( V_33 == NULL )
return NULL ;
V_56 ( V_33 ) = V_53 ;
F_27 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_44 ) ;
return V_33 ;
}
static int F_40 ( struct V_13 * V_14 , struct V_52 * V_53 )
{
struct V_30 * V_33 ;
int V_45 ;
V_33 = F_39 ( V_14 , V_57 , V_53 ) ;
if ( V_33 == NULL )
return - V_41 ;
V_45 = F_38 ( V_14 , V_53 ) ;
if ( V_45 < 0 ) {
F_20 ( V_33 ) ;
return V_45 ;
}
return 0 ;
}
static int F_41 ( struct V_13 * V_14 )
{
struct V_52 * V_53 ;
int V_45 ;
F_9 (rule, &ctx->chain->rules, list) {
V_45 = F_40 ( V_14 , V_53 ) ;
if ( V_45 < 0 )
return V_45 ;
}
return 0 ;
}
static int F_42 ( struct V_13 * V_14 , int V_31 ,
struct V_58 * V_59 )
{
struct V_30 * V_33 ;
V_33 = F_18 ( V_14 , V_31 , sizeof( struct V_60 ) ) ;
if ( V_33 == NULL )
return - V_41 ;
if ( V_31 == V_61 && V_14 -> V_24 [ V_62 ] != NULL ) {
F_43 ( V_33 ) =
F_44 ( F_45 ( V_14 -> V_24 [ V_62 ] ) ) ;
V_59 -> V_36 |= V_63 ;
}
V_60 ( V_33 ) = V_59 ;
F_27 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_44 ) ;
return 0 ;
}
static int F_46 ( struct V_13 * V_14 , struct V_58 * V_59 )
{
int V_45 ;
V_45 = F_42 ( V_14 , V_64 , V_59 ) ;
if ( V_45 < 0 )
return V_45 ;
F_7 ( & V_59 -> V_6 ) ;
V_14 -> V_20 -> V_51 -- ;
return V_45 ;
}
static struct V_19 * F_47 ( const struct V_2 * V_3 ,
const struct V_23 * V_24 )
{
struct V_19 * V_20 ;
F_9 (table, &afi->tables, list) {
if ( ! F_48 ( V_24 , V_20 -> V_65 ) )
return V_20 ;
}
return NULL ;
}
static struct V_19 * F_49 ( const struct V_2 * V_3 ,
const struct V_23 * V_24 )
{
struct V_19 * V_20 ;
if ( V_24 == NULL )
return F_13 ( - V_66 ) ;
V_20 = F_47 ( V_3 , V_24 ) ;
if ( V_20 != NULL )
return V_20 ;
return F_13 ( - V_55 ) ;
}
static inline T_2 F_50 ( struct V_19 * V_20 )
{
return ++ V_20 -> V_67 ;
}
static const struct V_68 *
F_51 ( int V_9 , const struct V_23 * V_24 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_70 ; V_69 ++ ) {
if ( V_71 [ V_9 ] [ V_69 ] != NULL &&
! F_48 ( V_24 , V_71 [ V_9 ] [ V_69 ] -> V_65 ) )
return V_71 [ V_9 ] [ V_69 ] ;
}
return NULL ;
}
static const struct V_68 *
F_52 ( const struct V_2 * V_3 ,
const struct V_23 * V_24 ,
bool V_10 )
{
const struct V_68 * type ;
type = F_51 ( V_3 -> V_9 , V_24 ) ;
if ( type != NULL )
return type ;
#ifdef F_11
if ( V_10 ) {
F_5 ( V_5 ) ;
F_12 ( L_2 , V_3 -> V_9 ,
F_53 ( V_24 ) , ( const char * ) F_54 ( V_24 ) ) ;
F_3 ( V_5 ) ;
type = F_51 ( V_3 -> V_9 , V_24 ) ;
if ( type != NULL )
return F_13 ( - V_11 ) ;
}
#endif
return F_13 ( - V_55 ) ;
}
static int F_55 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_26 , T_1 V_28 , int V_72 , T_1 V_36 ,
int V_9 , const struct V_19 * V_20 )
{
struct V_17 * V_18 ;
struct V_73 * V_74 ;
V_72 |= V_5 << 8 ;
V_18 = F_56 ( V_16 , V_26 , V_28 , V_72 , sizeof( struct V_73 ) , V_36 ) ;
if ( V_18 == NULL )
goto V_75;
V_74 = F_57 ( V_18 ) ;
V_74 -> V_76 = V_9 ;
V_74 -> V_77 = V_78 ;
V_74 -> V_79 = F_58 ( V_1 -> V_7 . V_80 & 0xffff ) ;
if ( F_59 ( V_16 , V_81 , V_20 -> V_65 ) ||
F_60 ( V_16 , V_82 , F_61 ( V_20 -> V_36 ) ) ||
F_60 ( V_16 , V_83 , F_61 ( V_20 -> V_51 ) ) )
goto V_75;
F_62 ( V_16 , V_18 ) ;
return 0 ;
V_75:
F_63 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_64 ( const struct V_13 * V_14 , int V_72 )
{
struct V_15 * V_16 ;
int V_45 ;
if ( ! V_14 -> V_27 &&
! F_65 ( V_14 -> V_1 , V_84 ) )
return 0 ;
V_45 = - V_85 ;
V_16 = F_66 ( V_86 , V_34 ) ;
if ( V_16 == NULL )
goto V_45;
V_45 = F_55 ( V_16 , V_14 -> V_1 , V_14 -> V_26 , V_14 -> V_28 ,
V_72 , 0 , V_14 -> V_3 -> V_9 , V_14 -> V_20 ) ;
if ( V_45 < 0 ) {
F_67 ( V_16 ) ;
goto V_45;
}
V_45 = F_68 ( V_16 , V_14 -> V_1 , V_14 -> V_26 , V_84 ,
V_14 -> V_27 , V_34 ) ;
V_45:
if ( V_45 < 0 ) {
F_69 ( V_14 -> V_1 , V_14 -> V_26 , V_84 ,
V_45 ) ;
}
return V_45 ;
}
static int F_70 ( struct V_15 * V_16 ,
struct V_87 * V_88 )
{
const struct V_73 * V_74 = F_57 ( V_88 -> V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
unsigned int V_89 = 0 , V_90 = V_88 -> args [ 0 ] ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_74 -> V_76 ;
F_71 () ;
V_88 -> V_28 = V_1 -> V_7 . V_80 ;
F_72 (afi, &net->nft.af_info, list) {
if ( V_9 != V_91 && V_9 != V_3 -> V_9 )
continue;
F_72 (table, &afi->tables, list) {
if ( V_89 < V_90 )
goto V_92;
if ( V_89 > V_90 )
memset ( & V_88 -> args [ 1 ] , 0 ,
sizeof( V_88 -> args ) - sizeof( V_88 -> args [ 0 ] ) ) ;
if ( F_55 ( V_16 , V_1 ,
F_16 ( V_88 -> V_16 ) . V_26 ,
V_88 -> V_18 -> V_29 ,
V_42 ,
V_93 ,
V_3 -> V_9 , V_20 ) < 0 )
goto V_94;
F_73 ( V_88 , F_74 ( V_16 ) ) ;
V_92:
V_89 ++ ;
}
}
V_94:
F_75 () ;
V_88 -> args [ 0 ] = V_89 ;
return V_16 -> V_95 ;
}
static int F_76 ( struct V_96 * V_97 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_73 * V_74 = F_57 ( V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
struct V_15 * V_98 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_74 -> V_76 ;
int V_45 ;
if ( V_18 -> V_99 & V_100 ) {
struct V_101 V_102 = {
. V_103 = F_70 ,
} ;
return F_77 ( V_97 , V_16 , V_18 , & V_102 ) ;
}
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_78 ( V_3 ) )
return F_79 ( V_3 ) ;
V_20 = F_49 ( V_3 , V_24 [ V_81 ] ) ;
if ( F_78 ( V_20 ) )
return F_79 ( V_20 ) ;
if ( V_20 -> V_36 & V_43 )
return - V_55 ;
V_98 = F_80 ( V_86 , V_34 ) ;
if ( ! V_98 )
return - V_41 ;
V_45 = F_55 ( V_98 , V_1 , F_16 ( V_16 ) . V_26 ,
V_18 -> V_29 , V_42 , 0 ,
V_9 , V_20 ) ;
if ( V_45 < 0 )
goto V_45;
return F_81 ( V_97 , V_98 , F_16 ( V_16 ) . V_26 ) ;
V_45:
F_67 ( V_98 ) ;
return V_45 ;
}
static int F_82 ( const struct V_2 * V_3 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 ;
int V_45 , V_69 = 0 ;
F_9 (chain, &table->chains, list) {
if ( ! ( V_22 -> V_36 & V_38 ) )
continue;
V_45 = F_83 ( F_25 ( V_22 ) -> V_39 , V_3 -> V_104 ) ;
if ( V_45 < 0 )
goto V_45;
V_69 ++ ;
}
return 0 ;
V_45:
F_9 (chain, &table->chains, list) {
if ( ! ( V_22 -> V_36 & V_38 ) )
continue;
if ( V_69 -- <= 0 )
break;
F_24 ( F_25 ( V_22 ) -> V_39 , V_3 -> V_104 ) ;
}
return V_45 ;
}
static void F_84 ( const struct V_2 * V_3 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 ;
F_9 (chain, &table->chains, list) {
if ( V_22 -> V_36 & V_38 )
F_24 ( F_25 ( V_22 ) -> V_39 ,
V_3 -> V_104 ) ;
}
}
static int F_85 ( struct V_13 * V_14 )
{
struct V_30 * V_33 ;
T_1 V_36 ;
int V_105 = 0 ;
if ( ! V_14 -> V_24 [ V_82 ] )
return 0 ;
V_36 = F_44 ( F_45 ( V_14 -> V_24 [ V_82 ] ) ) ;
if ( V_36 & ~ V_37 )
return - V_66 ;
if ( V_36 == V_14 -> V_20 -> V_36 )
return 0 ;
V_33 = F_18 ( V_14 , V_42 ,
sizeof( struct V_40 ) ) ;
if ( V_33 == NULL )
return - V_41 ;
if ( ( V_36 & V_37 ) &&
! ( V_14 -> V_20 -> V_36 & V_37 ) ) {
F_86 ( V_33 ) = false ;
} else if ( ! ( V_36 & V_37 ) &&
V_14 -> V_20 -> V_36 & V_37 ) {
V_105 = F_82 ( V_14 -> V_3 , V_14 -> V_20 ) ;
if ( V_105 >= 0 ) {
V_14 -> V_20 -> V_36 &= ~ V_37 ;
F_86 ( V_33 ) = true ;
}
}
if ( V_105 < 0 )
goto V_45;
F_87 ( V_33 ) = true ;
F_27 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_44 ) ;
return 0 ;
V_45:
F_20 ( V_33 ) ;
return V_105 ;
}
static int F_88 ( struct V_96 * V_97 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_73 * V_74 = F_57 ( V_18 ) ;
const struct V_23 * V_65 ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_74 -> V_76 ;
T_1 V_36 = 0 ;
struct V_13 V_14 ;
int V_45 ;
V_3 = F_10 ( V_1 , V_9 , true ) ;
if ( F_78 ( V_3 ) )
return F_79 ( V_3 ) ;
V_65 = V_24 [ V_81 ] ;
V_20 = F_49 ( V_3 , V_65 ) ;
if ( F_78 ( V_20 ) ) {
if ( F_79 ( V_20 ) != - V_55 )
return F_79 ( V_20 ) ;
V_20 = NULL ;
}
if ( V_20 != NULL ) {
if ( V_20 -> V_36 & V_43 )
return - V_55 ;
if ( V_18 -> V_99 & V_106 )
return - V_107 ;
if ( V_18 -> V_99 & V_108 )
return - V_109 ;
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return F_85 ( & V_14 ) ;
}
if ( V_24 [ V_82 ] ) {
V_36 = F_44 ( F_45 ( V_24 [ V_82 ] ) ) ;
if ( V_36 & ~ V_37 )
return - V_66 ;
}
if ( ! F_89 ( V_3 -> V_110 ) )
return - V_12 ;
V_45 = - V_41 ;
V_20 = F_19 ( sizeof( * V_20 ) , V_34 ) ;
if ( V_20 == NULL )
goto V_111;
F_90 ( V_20 -> V_65 , V_65 , V_112 ) ;
F_2 ( & V_20 -> V_113 ) ;
F_2 ( & V_20 -> V_114 ) ;
V_20 -> V_36 = V_36 ;
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
V_45 = F_26 ( & V_14 , V_42 ) ;
if ( V_45 < 0 )
goto V_115;
F_4 ( & V_20 -> V_6 , & V_3 -> V_4 ) ;
return 0 ;
V_115:
F_22 ( V_20 ) ;
V_111:
F_91 ( V_3 -> V_110 ) ;
return V_45 ;
}
static int F_92 ( struct V_13 * V_14 )
{
int V_45 ;
struct V_21 * V_22 , * V_116 ;
struct V_58 * V_59 , * V_117 ;
F_9 (chain, &ctx->table->chains, list) {
V_14 -> V_22 = V_22 ;
V_45 = F_41 ( V_14 ) ;
if ( V_45 < 0 )
goto V_118;
}
F_93 (set, ns, &ctx->table->sets, list) {
if ( V_59 -> V_36 & V_119 &&
! F_94 ( & V_59 -> V_120 ) )
continue;
V_45 = F_46 ( V_14 , V_59 ) ;
if ( V_45 < 0 )
goto V_118;
}
F_93 (chain, nc, &ctx->table->chains, list) {
V_14 -> V_22 = V_22 ;
V_45 = F_30 ( V_14 ) ;
if ( V_45 < 0 )
goto V_118;
}
V_45 = F_28 ( V_14 ) ;
V_118:
return V_45 ;
}
static int F_95 ( struct V_13 * V_14 , int V_9 )
{
struct V_2 * V_3 ;
struct V_19 * V_20 , * V_121 ;
const struct V_23 * const * V_24 = V_14 -> V_24 ;
int V_45 = 0 ;
F_9 (afi, &ctx->net->nft.af_info, list) {
if ( V_9 != V_122 && V_3 -> V_9 != V_9 )
continue;
V_14 -> V_3 = V_3 ;
F_93 (table, nt, &afi->tables, list) {
if ( V_24 [ V_81 ] &&
F_48 ( V_24 [ V_81 ] , V_20 -> V_65 ) != 0 )
continue;
V_14 -> V_20 = V_20 ;
V_45 = F_92 ( V_14 ) ;
if ( V_45 < 0 )
goto V_118;
}
}
V_118:
return V_45 ;
}
static int F_96 ( struct V_96 * V_97 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_73 * V_74 = F_57 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_74 -> V_76 ;
struct V_13 V_14 ;
F_14 ( & V_14 , V_16 , V_18 , NULL , NULL , NULL , V_24 ) ;
if ( V_9 == V_122 || V_24 [ V_81 ] == NULL )
return F_95 ( & V_14 , V_9 ) ;
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_78 ( V_3 ) )
return F_79 ( V_3 ) ;
V_20 = F_49 ( V_3 , V_24 [ V_81 ] ) ;
if ( F_78 ( V_20 ) )
return F_79 ( V_20 ) ;
if ( V_20 -> V_36 & V_43 )
return - V_55 ;
V_14 . V_3 = V_3 ;
V_14 . V_20 = V_20 ;
return F_92 ( & V_14 ) ;
}
static void F_97 ( struct V_13 * V_14 )
{
F_98 ( V_14 -> V_20 -> V_51 > 0 ) ;
F_22 ( V_14 -> V_20 ) ;
F_91 ( V_14 -> V_3 -> V_110 ) ;
}
int F_99 ( const struct V_68 * V_123 )
{
int V_45 = 0 ;
F_3 ( V_5 ) ;
if ( V_71 [ V_123 -> V_9 ] [ V_123 -> type ] != NULL ) {
V_45 = - V_124 ;
goto V_118;
}
V_71 [ V_123 -> V_9 ] [ V_123 -> type ] = V_123 ;
V_118:
F_5 ( V_5 ) ;
return V_45 ;
}
void F_100 ( const struct V_68 * V_123 )
{
F_3 ( V_5 ) ;
V_71 [ V_123 -> V_9 ] [ V_123 -> type ] = NULL ;
F_5 ( V_5 ) ;
}
static struct V_21 *
F_101 ( const struct V_19 * V_20 , T_2 V_125 )
{
struct V_21 * V_22 ;
F_9 (chain, &table->chains, list) {
if ( V_22 -> V_125 == V_125 )
return V_22 ;
}
return F_13 ( - V_55 ) ;
}
static struct V_21 * F_102 ( const struct V_19 * V_20 ,
const struct V_23 * V_24 )
{
struct V_21 * V_22 ;
if ( V_24 == NULL )
return F_13 ( - V_66 ) ;
F_9 (chain, &table->chains, list) {
if ( ! F_48 ( V_24 , V_22 -> V_65 ) )
return V_22 ;
}
return F_13 ( - V_55 ) ;
}
static int F_103 ( struct V_15 * V_16 , struct V_126 T_3 * V_127 )
{
struct V_126 * V_128 , V_129 ;
struct V_23 * V_130 ;
unsigned int V_28 ;
T_2 V_131 , V_132 ;
int V_133 ;
memset ( & V_129 , 0 , sizeof( V_129 ) ) ;
F_104 (cpu) {
V_128 = F_105 ( V_127 , V_133 ) ;
do {
V_28 = F_106 ( & V_128 -> V_134 ) ;
V_131 = V_128 -> V_131 ;
V_132 = V_128 -> V_132 ;
} while ( F_107 ( & V_128 -> V_134 , V_28 ) );
V_129 . V_131 += V_131 ;
V_129 . V_132 += V_132 ;
}
V_130 = F_108 ( V_16 , V_135 ) ;
if ( V_130 == NULL )
goto V_75;
if ( F_109 ( V_16 , V_136 , F_110 ( V_129 . V_131 ) ) ||
F_109 ( V_16 , V_137 , F_110 ( V_129 . V_132 ) ) )
goto V_75;
F_111 ( V_16 , V_130 ) ;
return 0 ;
V_75:
return - V_138 ;
}
static int F_112 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_26 , T_1 V_28 , int V_72 , T_1 V_36 ,
int V_9 , const struct V_19 * V_20 ,
const struct V_21 * V_22 )
{
struct V_17 * V_18 ;
struct V_73 * V_74 ;
V_72 |= V_5 << 8 ;
V_18 = F_56 ( V_16 , V_26 , V_28 , V_72 , sizeof( struct V_73 ) , V_36 ) ;
if ( V_18 == NULL )
goto V_75;
V_74 = F_57 ( V_18 ) ;
V_74 -> V_76 = V_9 ;
V_74 -> V_77 = V_78 ;
V_74 -> V_79 = F_58 ( V_1 -> V_7 . V_80 & 0xffff ) ;
if ( F_59 ( V_16 , V_139 , V_20 -> V_65 ) )
goto V_75;
if ( F_109 ( V_16 , V_140 , F_110 ( V_22 -> V_125 ) ) )
goto V_75;
if ( F_59 ( V_16 , V_141 , V_22 -> V_65 ) )
goto V_75;
if ( V_22 -> V_36 & V_38 ) {
const struct F_25 * V_142 = F_25 ( V_22 ) ;
const struct V_143 * V_39 = & V_142 -> V_39 [ 0 ] ;
struct V_23 * V_130 ;
V_130 = F_108 ( V_16 , V_144 ) ;
if ( V_130 == NULL )
goto V_75;
if ( F_60 ( V_16 , V_145 , F_61 ( V_39 -> V_146 ) ) )
goto V_75;
if ( F_60 ( V_16 , V_147 , F_61 ( V_39 -> V_148 ) ) )
goto V_75;
F_111 ( V_16 , V_130 ) ;
if ( F_60 ( V_16 , V_149 ,
F_61 ( V_142 -> V_150 ) ) )
goto V_75;
if ( F_59 ( V_16 , V_151 , V_142 -> type -> V_65 ) )
goto V_75;
if ( F_103 ( V_16 , F_25 ( V_22 ) -> V_127 ) )
goto V_75;
}
if ( F_60 ( V_16 , V_152 , F_61 ( V_22 -> V_51 ) ) )
goto V_75;
F_62 ( V_16 , V_18 ) ;
return 0 ;
V_75:
F_63 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_113 ( const struct V_13 * V_14 , int V_72 )
{
struct V_15 * V_16 ;
int V_45 ;
if ( ! V_14 -> V_27 &&
! F_65 ( V_14 -> V_1 , V_84 ) )
return 0 ;
V_45 = - V_85 ;
V_16 = F_66 ( V_86 , V_34 ) ;
if ( V_16 == NULL )
goto V_45;
V_45 = F_112 ( V_16 , V_14 -> V_1 , V_14 -> V_26 , V_14 -> V_28 ,
V_72 , 0 , V_14 -> V_3 -> V_9 , V_14 -> V_20 ,
V_14 -> V_22 ) ;
if ( V_45 < 0 ) {
F_67 ( V_16 ) ;
goto V_45;
}
V_45 = F_68 ( V_16 , V_14 -> V_1 , V_14 -> V_26 , V_84 ,
V_14 -> V_27 , V_34 ) ;
V_45:
if ( V_45 < 0 ) {
F_69 ( V_14 -> V_1 , V_14 -> V_26 , V_84 ,
V_45 ) ;
}
return V_45 ;
}
static int F_114 ( struct V_15 * V_16 ,
struct V_87 * V_88 )
{
const struct V_73 * V_74 = F_57 ( V_88 -> V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
unsigned int V_89 = 0 , V_90 = V_88 -> args [ 0 ] ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_74 -> V_76 ;
F_71 () ;
V_88 -> V_28 = V_1 -> V_7 . V_80 ;
F_72 (afi, &net->nft.af_info, list) {
if ( V_9 != V_91 && V_9 != V_3 -> V_9 )
continue;
F_72 (table, &afi->tables, list) {
F_72 (chain, &table->chains, list) {
if ( V_89 < V_90 )
goto V_92;
if ( V_89 > V_90 )
memset ( & V_88 -> args [ 1 ] , 0 ,
sizeof( V_88 -> args ) - sizeof( V_88 -> args [ 0 ] ) ) ;
if ( F_112 ( V_16 , V_1 ,
F_16 ( V_88 -> V_16 ) . V_26 ,
V_88 -> V_18 -> V_29 ,
V_48 ,
V_93 ,
V_3 -> V_9 , V_20 , V_22 ) < 0 )
goto V_94;
F_73 ( V_88 , F_74 ( V_16 ) ) ;
V_92:
V_89 ++ ;
}
}
}
V_94:
F_75 () ;
V_88 -> args [ 0 ] = V_89 ;
return V_16 -> V_95 ;
}
static int F_115 ( struct V_96 * V_97 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_73 * V_74 = F_57 ( V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
struct V_15 * V_98 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_74 -> V_76 ;
int V_45 ;
if ( V_18 -> V_99 & V_100 ) {
struct V_101 V_102 = {
. V_103 = F_114 ,
} ;
return F_77 ( V_97 , V_16 , V_18 , & V_102 ) ;
}
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_78 ( V_3 ) )
return F_79 ( V_3 ) ;
V_20 = F_49 ( V_3 , V_24 [ V_139 ] ) ;
if ( F_78 ( V_20 ) )
return F_79 ( V_20 ) ;
if ( V_20 -> V_36 & V_43 )
return - V_55 ;
V_22 = F_102 ( V_20 , V_24 [ V_141 ] ) ;
if ( F_78 ( V_22 ) )
return F_79 ( V_22 ) ;
if ( V_22 -> V_36 & V_49 )
return - V_55 ;
V_98 = F_80 ( V_86 , V_34 ) ;
if ( ! V_98 )
return - V_41 ;
V_45 = F_112 ( V_98 , V_1 , F_16 ( V_16 ) . V_26 ,
V_18 -> V_29 , V_48 , 0 ,
V_9 , V_20 , V_22 ) ;
if ( V_45 < 0 )
goto V_45;
return F_81 ( V_97 , V_98 , F_16 ( V_16 ) . V_26 ) ;
V_45:
F_67 ( V_98 ) ;
return V_45 ;
}
static struct V_126 T_3 * F_116 ( const struct V_23 * V_153 )
{
struct V_23 * V_154 [ V_155 + 1 ] ;
struct V_126 T_3 * V_156 ;
struct V_126 * V_127 ;
int V_45 ;
V_45 = F_117 ( V_154 , V_155 , V_153 , V_157 ) ;
if ( V_45 < 0 )
return F_13 ( V_45 ) ;
if ( ! V_154 [ V_137 ] || ! V_154 [ V_136 ] )
return F_13 ( - V_66 ) ;
V_156 = F_118 ( struct V_126 ) ;
if ( V_156 == NULL )
return F_13 ( - V_41 ) ;
F_119 () ;
V_127 = F_120 ( V_156 ) ;
V_127 -> V_132 = F_121 ( F_122 ( V_154 [ V_137 ] ) ) ;
V_127 -> V_131 = F_121 ( F_122 ( V_154 [ V_136 ] ) ) ;
F_123 () ;
return V_156 ;
}
static void F_124 ( struct F_25 * V_22 ,
struct V_126 T_3 * V_156 )
{
if ( V_156 == NULL )
return;
if ( V_22 -> V_127 ) {
struct V_126 T_3 * V_158 =
F_125 ( V_22 -> V_127 ) ;
F_126 ( V_22 -> V_127 , V_156 ) ;
F_127 () ;
F_128 ( V_158 ) ;
} else
F_126 ( V_22 -> V_127 , V_156 ) ;
}
static void F_129 ( struct V_21 * V_22 )
{
F_98 ( V_22 -> V_51 > 0 ) ;
if ( V_22 -> V_36 & V_38 ) {
F_91 ( F_25 ( V_22 ) -> type -> V_110 ) ;
F_128 ( F_25 ( V_22 ) -> V_127 ) ;
F_22 ( F_25 ( V_22 ) ) ;
} else {
F_22 ( V_22 ) ;
}
}
static int F_130 ( struct V_96 * V_97 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_73 * V_74 = F_57 ( V_18 ) ;
const struct V_23 * V_159 ( V_65 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct F_25 * V_142 = NULL ;
struct V_23 * V_160 [ V_161 + 1 ] ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_74 -> V_76 ;
T_4 V_150 = V_162 ;
T_2 V_125 = 0 ;
unsigned int V_69 ;
struct V_126 T_3 * V_127 ;
int V_45 ;
bool V_163 ;
struct V_13 V_14 ;
V_163 = V_18 -> V_99 & V_164 ? true : false ;
V_3 = F_10 ( V_1 , V_9 , true ) ;
if ( F_78 ( V_3 ) )
return F_79 ( V_3 ) ;
V_20 = F_49 ( V_3 , V_24 [ V_139 ] ) ;
if ( F_78 ( V_20 ) )
return F_79 ( V_20 ) ;
V_22 = NULL ;
V_65 = V_24 [ V_141 ] ;
if ( V_24 [ V_140 ] ) {
V_125 = F_121 ( F_122 ( V_24 [ V_140 ] ) ) ;
V_22 = F_101 ( V_20 , V_125 ) ;
if ( F_78 ( V_22 ) )
return F_79 ( V_22 ) ;
} else {
V_22 = F_102 ( V_20 , V_65 ) ;
if ( F_78 ( V_22 ) ) {
if ( F_79 ( V_22 ) != - V_55 )
return F_79 ( V_22 ) ;
V_22 = NULL ;
}
}
if ( V_24 [ V_149 ] ) {
if ( ( V_22 != NULL &&
! ( V_22 -> V_36 & V_38 ) ) )
return - V_109 ;
if ( V_22 == NULL &&
V_24 [ V_144 ] == NULL )
return - V_109 ;
V_150 = F_44 ( F_45 ( V_24 [ V_149 ] ) ) ;
switch ( V_150 ) {
case V_165 :
case V_162 :
break;
default:
return - V_66 ;
}
}
if ( V_22 != NULL ) {
struct V_126 * V_127 = NULL ;
struct V_30 * V_33 ;
if ( V_22 -> V_36 & V_49 )
return - V_55 ;
if ( V_18 -> V_99 & V_106 )
return - V_107 ;
if ( V_18 -> V_99 & V_108 )
return - V_109 ;
if ( V_24 [ V_140 ] && V_65 &&
! F_78 ( F_102 ( V_20 , V_24 [ V_141 ] ) ) )
return - V_107 ;
if ( V_24 [ V_135 ] ) {
if ( ! ( V_22 -> V_36 & V_38 ) )
return - V_109 ;
V_127 = F_116 ( V_24 [ V_135 ] ) ;
if ( F_78 ( V_127 ) )
return F_79 ( V_127 ) ;
}
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_33 = F_18 ( & V_14 , V_48 ,
sizeof( struct V_47 ) ) ;
if ( V_33 == NULL ) {
F_128 ( V_127 ) ;
return - V_41 ;
}
F_131 ( V_33 ) = V_127 ;
F_132 ( V_33 ) = true ;
if ( V_24 [ V_149 ] )
F_133 ( V_33 ) = V_150 ;
else
F_133 ( V_33 ) = - 1 ;
if ( V_24 [ V_140 ] && V_65 ) {
F_90 ( F_134 ( V_33 ) , V_65 ,
V_166 ) ;
}
F_27 ( & V_33 -> V_6 , & V_1 -> V_7 . V_44 ) ;
return 0 ;
}
if ( V_20 -> V_51 == V_167 )
return - V_168 ;
if ( V_24 [ V_144 ] ) {
const struct V_68 * type ;
struct V_143 * V_39 ;
T_5 * V_169 ;
T_1 V_146 , V_148 ;
type = V_71 [ V_9 ] [ V_170 ] ;
if ( V_24 [ V_151 ] ) {
type = F_52 ( V_3 ,
V_24 [ V_151 ] ,
V_163 ) ;
if ( F_78 ( type ) )
return F_79 ( type ) ;
}
V_45 = F_117 ( V_160 , V_161 , V_24 [ V_144 ] ,
V_171 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_160 [ V_145 ] == NULL ||
V_160 [ V_147 ] == NULL )
return - V_66 ;
V_146 = F_44 ( F_45 ( V_160 [ V_145 ] ) ) ;
if ( V_146 >= V_3 -> V_172 )
return - V_66 ;
V_148 = F_44 ( F_45 ( V_160 [ V_147 ] ) ) ;
if ( ! ( type -> V_173 & ( 1 << V_146 ) ) )
return - V_109 ;
if ( ! F_89 ( type -> V_110 ) )
return - V_55 ;
V_169 = type -> V_174 [ V_146 ] ;
V_142 = F_19 ( sizeof( * V_142 ) , V_34 ) ;
if ( V_142 == NULL ) {
F_91 ( type -> V_110 ) ;
return - V_41 ;
}
if ( V_24 [ V_135 ] ) {
V_127 = F_116 ( V_24 [ V_135 ] ) ;
if ( F_78 ( V_127 ) ) {
F_91 ( type -> V_110 ) ;
F_22 ( V_142 ) ;
return F_79 ( V_127 ) ;
}
V_142 -> V_127 = V_127 ;
} else {
V_127 = F_118 ( struct V_126 ) ;
if ( V_127 == NULL ) {
F_91 ( type -> V_110 ) ;
F_22 ( V_142 ) ;
return - V_41 ;
}
F_126 ( V_142 -> V_127 , V_127 ) ;
}
F_135 ( & V_142 -> V_175 , V_1 ) ;
V_142 -> type = type ;
V_22 = & V_142 -> V_22 ;
for ( V_69 = 0 ; V_69 < V_3 -> V_104 ; V_69 ++ ) {
V_39 = & V_142 -> V_39 [ V_69 ] ;
V_39 -> V_176 = V_9 ;
V_39 -> V_110 = V_3 -> V_110 ;
V_39 -> V_146 = V_146 ;
V_39 -> V_148 = V_148 ;
V_39 -> V_177 = V_22 ;
V_39 -> V_178 = V_3 -> V_174 [ V_39 -> V_146 ] ;
if ( V_169 )
V_39 -> V_178 = V_169 ;
if ( V_3 -> V_179 )
V_3 -> V_179 ( V_39 , V_69 ) ;
}
V_22 -> V_36 |= V_38 ;
V_142 -> V_150 = V_150 ;
} else {
V_22 = F_19 ( sizeof( * V_22 ) , V_34 ) ;
if ( V_22 == NULL )
return - V_41 ;
}
F_2 ( & V_22 -> V_180 ) ;
V_22 -> V_125 = F_50 ( V_20 ) ;
V_22 -> V_20 = V_20 ;
F_90 ( V_22 -> V_65 , V_65 , V_166 ) ;
if ( ! ( V_20 -> V_36 & V_37 ) &&
V_22 -> V_36 & V_38 ) {
V_45 = F_83 ( F_25 ( V_22 ) -> V_39 , V_3 -> V_104 ) ;
if ( V_45 < 0 )
goto V_111;
}
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_45 = F_29 ( & V_14 , V_48 ) ;
if ( V_45 < 0 )
goto V_115;
V_20 -> V_51 ++ ;
F_4 ( & V_22 -> V_6 , & V_20 -> V_113 ) ;
return 0 ;
V_115:
F_23 ( V_20 , V_22 , V_3 -> V_104 ) ;
V_111:
F_129 ( V_22 ) ;
return V_45 ;
}
static int F_136 ( struct V_96 * V_97 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_73 * V_74 = F_57 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_74 -> V_76 ;
struct V_13 V_14 ;
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_78 ( V_3 ) )
return F_79 ( V_3 ) ;
V_20 = F_49 ( V_3 , V_24 [ V_139 ] ) ;
if ( F_78 ( V_20 ) )
return F_79 ( V_20 ) ;
if ( V_20 -> V_36 & V_43 )
return - V_55 ;
V_22 = F_102 ( V_20 , V_24 [ V_141 ] ) ;
if ( F_78 ( V_22 ) )
return F_79 ( V_22 ) ;
if ( V_22 -> V_36 & V_49 )
return - V_55 ;
if ( V_22 -> V_51 > 0 )
return - V_124 ;
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
return F_30 ( & V_14 ) ;
}
int F_137 ( struct V_181 * type )
{
F_3 ( V_5 ) ;
if ( type -> V_9 == V_91 )
F_4 ( & type -> V_6 , & V_182 ) ;
else
F_138 ( & type -> V_6 , & V_182 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_139 ( struct V_181 * type )
{
F_3 ( V_5 ) ;
F_7 ( & type -> V_6 ) ;
F_5 ( V_5 ) ;
}
static const struct V_181 * F_140 ( T_4 V_9 ,
struct V_23 * V_24 )
{
const struct V_181 * type ;
F_9 (type, &nf_tables_expressions, list) {
if ( ! F_48 ( V_24 , type -> V_65 ) &&
( ! type -> V_9 || type -> V_9 == V_9 ) )
return type ;
}
return NULL ;
}
static const struct V_181 * F_141 ( T_4 V_9 ,
struct V_23 * V_24 )
{
const struct V_181 * type ;
if ( V_24 == NULL )
return F_13 ( - V_66 ) ;
type = F_140 ( V_9 , V_24 ) ;
if ( type != NULL && F_89 ( type -> V_110 ) )
return type ;
#ifdef F_11
if ( type == NULL ) {
F_5 ( V_5 ) ;
F_12 ( L_3 , V_9 ,
F_53 ( V_24 ) , ( char * ) F_54 ( V_24 ) ) ;
F_3 ( V_5 ) ;
if ( F_140 ( V_9 , V_24 ) )
return F_13 ( - V_11 ) ;
F_5 ( V_5 ) ;
F_12 ( L_4 ,
F_53 ( V_24 ) , ( char * ) F_54 ( V_24 ) ) ;
F_3 ( V_5 ) ;
if ( F_140 ( V_9 , V_24 ) )
return F_13 ( - V_11 ) ;
}
#endif
return F_13 ( - V_55 ) ;
}
static int F_142 ( struct V_15 * V_16 ,
const struct V_183 * V_184 )
{
if ( F_59 ( V_16 , V_185 , V_184 -> V_39 -> type -> V_65 ) )
goto V_75;
if ( V_184 -> V_39 -> V_103 ) {
struct V_23 * V_186 = F_108 ( V_16 , V_187 ) ;
if ( V_186 == NULL )
goto V_75;
if ( V_184 -> V_39 -> V_103 ( V_16 , V_184 ) < 0 )
goto V_75;
F_111 ( V_16 , V_186 ) ;
}
return V_16 -> V_95 ;
V_75:
return - 1 ;
}
int F_143 ( struct V_15 * V_16 , unsigned int V_153 ,
const struct V_183 * V_184 )
{
struct V_23 * V_130 ;
V_130 = F_108 ( V_16 , V_153 ) ;
if ( ! V_130 )
goto V_75;
if ( F_142 ( V_16 , V_184 ) < 0 )
goto V_75;
F_111 ( V_16 , V_130 ) ;
return 0 ;
V_75:
return - 1 ;
}
static int F_144 ( const struct V_13 * V_14 ,
const struct V_23 * V_24 ,
struct V_188 * V_189 )
{
const struct V_181 * type ;
const struct V_190 * V_39 ;
struct V_23 * V_154 [ V_191 + 1 ] ;
int V_45 ;
V_45 = F_117 ( V_154 , V_191 , V_24 , V_192 ) ;
if ( V_45 < 0 )
return V_45 ;
type = F_141 ( V_14 -> V_3 -> V_9 , V_154 [ V_185 ] ) ;
if ( F_78 ( type ) )
return F_79 ( type ) ;
if ( V_154 [ V_187 ] ) {
V_45 = F_117 ( V_189 -> V_154 , type -> V_193 ,
V_154 [ V_187 ] , type -> V_150 ) ;
if ( V_45 < 0 )
goto V_111;
} else
memset ( V_189 -> V_154 , 0 , sizeof( V_189 -> V_154 [ 0 ] ) * ( type -> V_193 + 1 ) ) ;
if ( type -> V_194 != NULL ) {
V_39 = type -> V_194 ( V_14 ,
( const struct V_23 * const * ) V_189 -> V_154 ) ;
if ( F_78 ( V_39 ) ) {
V_45 = F_79 ( V_39 ) ;
goto V_111;
}
} else
V_39 = type -> V_39 ;
V_189 -> V_39 = V_39 ;
return 0 ;
V_111:
F_91 ( type -> V_110 ) ;
return V_45 ;
}
static int F_145 ( const struct V_13 * V_14 ,
const struct V_188 * V_189 ,
struct V_183 * V_184 )
{
const struct V_190 * V_39 = V_189 -> V_39 ;
int V_45 ;
V_184 -> V_39 = V_39 ;
if ( V_39 -> V_195 ) {
V_45 = V_39 -> V_195 ( V_14 , V_184 , ( const struct V_23 * * ) V_189 -> V_154 ) ;
if ( V_45 < 0 )
goto V_111;
}
return 0 ;
V_111:
V_184 -> V_39 = NULL ;
return V_45 ;
}
static void F_146 ( const struct V_13 * V_14 ,
struct V_183 * V_184 )
{
if ( V_184 -> V_39 -> V_196 )
V_184 -> V_39 -> V_196 ( V_14 , V_184 ) ;
F_91 ( V_184 -> V_39 -> type -> V_110 ) ;
}
struct V_183 * F_147 ( const struct V_13 * V_14 ,
const struct V_23 * V_24 )
{
struct V_188 V_189 ;
struct V_183 * V_184 ;
int V_45 ;
V_45 = F_144 ( V_14 , V_24 , & V_189 ) ;
if ( V_45 < 0 )
goto V_111;
V_45 = - V_41 ;
V_184 = F_19 ( V_189 . V_39 -> V_32 , V_34 ) ;
if ( V_184 == NULL )
goto V_115;
V_45 = F_145 ( V_14 , & V_189 , V_184 ) ;
if ( V_45 < 0 )
goto V_115;
return V_184 ;
V_115:
F_91 ( V_189 . V_39 -> type -> V_110 ) ;
V_111:
return F_13 ( V_45 ) ;
}
void F_148 ( const struct V_13 * V_14 , struct V_183 * V_184 )
{
F_146 ( V_14 , V_184 ) ;
F_22 ( V_184 ) ;
}
static struct V_52 * F_149 ( const struct V_21 * V_22 ,
T_2 V_125 )
{
struct V_52 * V_53 ;
F_9 (rule, &chain->rules, list) {
if ( V_125 == V_53 -> V_125 )
return V_53 ;
}
return F_13 ( - V_55 ) ;
}
static struct V_52 * F_150 ( const struct V_21 * V_22 ,
const struct V_23 * V_24 )
{
if ( V_24 == NULL )
return F_13 ( - V_66 ) ;
return F_149 ( V_22 , F_121 ( F_122 ( V_24 ) ) ) ;
}
static int F_151 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_26 , T_1 V_28 , int V_72 ,
T_1 V_36 , int V_9 ,
const struct V_19 * V_20 ,
const struct V_21 * V_22 ,
const struct V_52 * V_53 )
{
struct V_17 * V_18 ;
struct V_73 * V_74 ;
const struct V_183 * V_184 , * V_197 ;
struct V_23 * V_6 ;
const struct V_52 * V_198 ;
int type = V_72 | V_5 << 8 ;
V_18 = F_56 ( V_16 , V_26 , V_28 , type , sizeof( struct V_73 ) ,
V_36 ) ;
if ( V_18 == NULL )
goto V_75;
V_74 = F_57 ( V_18 ) ;
V_74 -> V_76 = V_9 ;
V_74 -> V_77 = V_78 ;
V_74 -> V_79 = F_58 ( V_1 -> V_7 . V_80 & 0xffff ) ;
if ( F_59 ( V_16 , V_199 , V_20 -> V_65 ) )
goto V_75;
if ( F_59 ( V_16 , V_200 , V_22 -> V_65 ) )
goto V_75;
if ( F_109 ( V_16 , V_201 , F_110 ( V_53 -> V_125 ) ) )
goto V_75;
if ( ( V_72 != V_57 ) && ( V_53 -> V_6 . V_202 != & V_22 -> V_180 ) ) {
V_198 = F_152 ( V_53 -> V_6 . V_202 , struct V_52 , V_6 ) ;
if ( F_109 ( V_16 , V_203 ,
F_110 ( V_198 -> V_125 ) ) )
goto V_75;
}
V_6 = F_108 ( V_16 , V_204 ) ;
if ( V_6 == NULL )
goto V_75;
F_153 (expr, next, rule) {
if ( F_143 ( V_16 , V_205 , V_184 ) < 0 )
goto V_75;
}
F_111 ( V_16 , V_6 ) ;
if ( V_53 -> V_206 ) {
struct V_207 * V_206 = V_207 ( V_53 ) ;
if ( F_154 ( V_16 , V_208 , V_206 -> V_95 + 1 ,
V_206 -> V_186 ) < 0 )
goto V_75;
}
F_62 ( V_16 , V_18 ) ;
return 0 ;
V_75:
F_63 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_155 ( const struct V_13 * V_14 ,
const struct V_52 * V_53 ,
int V_72 )
{
struct V_15 * V_16 ;
int V_45 ;
if ( ! V_14 -> V_27 &&
! F_65 ( V_14 -> V_1 , V_84 ) )
return 0 ;
V_45 = - V_85 ;
V_16 = F_66 ( V_86 , V_34 ) ;
if ( V_16 == NULL )
goto V_45;
V_45 = F_151 ( V_16 , V_14 -> V_1 , V_14 -> V_26 , V_14 -> V_28 ,
V_72 , 0 , V_14 -> V_3 -> V_9 , V_14 -> V_20 ,
V_14 -> V_22 , V_53 ) ;
if ( V_45 < 0 ) {
F_67 ( V_16 ) ;
goto V_45;
}
V_45 = F_68 ( V_16 , V_14 -> V_1 , V_14 -> V_26 , V_84 ,
V_14 -> V_27 , V_34 ) ;
V_45:
if ( V_45 < 0 ) {
F_69 ( V_14 -> V_1 , V_14 -> V_26 , V_84 ,
V_45 ) ;
}
return V_45 ;
}
static int F_156 ( struct V_15 * V_16 ,
struct V_87 * V_88 )
{
const struct V_73 * V_74 = F_57 ( V_88 -> V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
const struct V_52 * V_53 ;
unsigned int V_89 = 0 , V_90 = V_88 -> args [ 0 ] ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_74 -> V_76 ;
F_71 () ;
V_88 -> V_28 = V_1 -> V_7 . V_80 ;
F_72 (afi, &net->nft.af_info, list) {
if ( V_9 != V_91 && V_9 != V_3 -> V_9 )
continue;
F_72 (table, &afi->tables, list) {
F_72 (chain, &table->chains, list) {
F_72 (rule, &chain->rules, list) {
if ( ! F_31 ( V_1 , V_53 ) )
goto V_92;
if ( V_89 < V_90 )
goto V_92;
if ( V_89 > V_90 )
memset ( & V_88 -> args [ 1 ] , 0 ,
sizeof( V_88 -> args ) - sizeof( V_88 -> args [ 0 ] ) ) ;
if ( F_151 ( V_16 , V_1 , F_16 ( V_88 -> V_16 ) . V_26 ,
V_88 -> V_18 -> V_29 ,
V_209 ,
V_93 | V_210 ,
V_3 -> V_9 , V_20 , V_22 , V_53 ) < 0 )
goto V_94;
F_73 ( V_88 , F_74 ( V_16 ) ) ;
V_92:
V_89 ++ ;
}
}
}
}
V_94:
F_75 () ;
V_88 -> args [ 0 ] = V_89 ;
return V_16 -> V_95 ;
}
static int F_157 ( struct V_96 * V_97 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_73 * V_74 = F_57 ( V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
const struct V_52 * V_53 ;
struct V_15 * V_98 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_74 -> V_76 ;
int V_45 ;
if ( V_18 -> V_99 & V_100 ) {
struct V_101 V_102 = {
. V_103 = F_156 ,
} ;
return F_77 ( V_97 , V_16 , V_18 , & V_102 ) ;
}
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_78 ( V_3 ) )
return F_79 ( V_3 ) ;
V_20 = F_49 ( V_3 , V_24 [ V_199 ] ) ;
if ( F_78 ( V_20 ) )
return F_79 ( V_20 ) ;
if ( V_20 -> V_36 & V_43 )
return - V_55 ;
V_22 = F_102 ( V_20 , V_24 [ V_200 ] ) ;
if ( F_78 ( V_22 ) )
return F_79 ( V_22 ) ;
if ( V_22 -> V_36 & V_49 )
return - V_55 ;
V_53 = F_150 ( V_22 , V_24 [ V_201 ] ) ;
if ( F_78 ( V_53 ) )
return F_79 ( V_53 ) ;
V_98 = F_80 ( V_86 , V_34 ) ;
if ( ! V_98 )
return - V_41 ;
V_45 = F_151 ( V_98 , V_1 , F_16 ( V_16 ) . V_26 ,
V_18 -> V_29 , V_209 , 0 ,
V_9 , V_20 , V_22 , V_53 ) ;
if ( V_45 < 0 )
goto V_45;
return F_81 ( V_97 , V_98 , F_16 ( V_16 ) . V_26 ) ;
V_45:
F_67 ( V_98 ) ;
return V_45 ;
}
static void F_158 ( const struct V_13 * V_14 ,
struct V_52 * V_53 )
{
struct V_183 * V_184 ;
V_184 = F_159 ( V_53 ) ;
while ( V_184 -> V_39 && V_184 != F_160 ( V_53 ) ) {
F_146 ( V_14 , V_184 ) ;
V_184 = F_161 ( V_184 ) ;
}
F_22 ( V_53 ) ;
}
static int F_162 ( struct V_96 * V_97 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_73 * V_74 = F_57 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_52 * V_53 , * V_211 = NULL ;
struct V_207 * V_206 ;
struct V_30 * V_33 = NULL ;
struct V_183 * V_184 ;
struct V_13 V_14 ;
struct V_23 * V_212 ;
unsigned int V_32 , V_69 , V_213 , V_214 = 0 , V_215 = 0 ;
int V_45 , V_216 ;
bool V_163 ;
T_2 V_125 , V_217 ;
V_163 = V_18 -> V_99 & V_164 ? true : false ;
V_3 = F_10 ( V_1 , V_74 -> V_76 , V_163 ) ;
if ( F_78 ( V_3 ) )
return F_79 ( V_3 ) ;
V_20 = F_49 ( V_3 , V_24 [ V_199 ] ) ;
if ( F_78 ( V_20 ) )
return F_79 ( V_20 ) ;
V_22 = F_102 ( V_20 , V_24 [ V_200 ] ) ;
if ( F_78 ( V_22 ) )
return F_79 ( V_22 ) ;
if ( V_24 [ V_201 ] ) {
V_125 = F_121 ( F_122 ( V_24 [ V_201 ] ) ) ;
V_53 = F_149 ( V_22 , V_125 ) ;
if ( F_78 ( V_53 ) )
return F_79 ( V_53 ) ;
if ( V_18 -> V_99 & V_106 )
return - V_107 ;
if ( V_18 -> V_99 & V_108 )
V_211 = V_53 ;
else
return - V_109 ;
} else {
if ( ! V_163 || V_18 -> V_99 & V_108 )
return - V_66 ;
V_125 = F_50 ( V_20 ) ;
if ( V_22 -> V_51 == V_167 )
return - V_168 ;
}
if ( V_24 [ V_203 ] ) {
if ( ! ( V_18 -> V_99 & V_164 ) )
return - V_109 ;
V_217 = F_121 ( F_122 ( V_24 [ V_203 ] ) ) ;
V_211 = F_149 ( V_22 , V_217 ) ;
if ( F_78 ( V_211 ) )
return F_79 ( V_211 ) ;
}
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_213 = 0 ;
V_32 = 0 ;
if ( V_24 [ V_204 ] ) {
F_163 (tmp, nla[NFTA_RULE_EXPRESSIONS], rem) {
V_45 = - V_66 ;
if ( F_164 ( V_212 ) != V_205 )
goto V_111;
if ( V_213 == V_218 )
goto V_111;
V_45 = F_144 ( & V_14 , V_212 , & V_189 [ V_213 ] ) ;
if ( V_45 < 0 )
goto V_111;
V_32 += V_189 [ V_213 ] . V_39 -> V_32 ;
V_213 ++ ;
}
}
V_45 = - V_219 ;
if ( V_32 >= 1 << 12 )
goto V_111;
if ( V_24 [ V_208 ] ) {
V_214 = F_53 ( V_24 [ V_208 ] ) ;
if ( V_214 > 0 )
V_215 = sizeof( struct V_207 ) + V_214 ;
}
V_45 = - V_41 ;
V_53 = F_19 ( sizeof( * V_53 ) + V_32 + V_215 , V_34 ) ;
if ( V_53 == NULL )
goto V_111;
F_35 ( V_1 , V_53 ) ;
V_53 -> V_125 = V_125 ;
V_53 -> V_220 = V_32 ;
V_53 -> V_206 = V_214 ? 1 : 0 ;
if ( V_214 ) {
V_206 = V_207 ( V_53 ) ;
V_206 -> V_95 = V_214 - 1 ;
F_165 ( V_206 -> V_186 , V_24 [ V_208 ] , V_214 ) ;
}
V_184 = F_159 ( V_53 ) ;
for ( V_69 = 0 ; V_69 < V_213 ; V_69 ++ ) {
V_45 = F_145 ( & V_14 , & V_189 [ V_69 ] , V_184 ) ;
if ( V_45 < 0 )
goto V_115;
V_189 [ V_69 ] . V_39 = NULL ;
V_184 = F_161 ( V_184 ) ;
}
if ( V_18 -> V_99 & V_108 ) {
if ( F_33 ( V_1 , V_211 ) ) {
V_33 = F_39 ( & V_14 , V_57 ,
V_211 ) ;
if ( V_33 == NULL ) {
V_45 = - V_41 ;
goto V_115;
}
F_36 ( V_1 , V_211 ) ;
V_22 -> V_51 -- ;
F_4 ( & V_53 -> V_6 , & V_211 -> V_6 ) ;
} else {
V_45 = - V_55 ;
goto V_115;
}
} else if ( V_18 -> V_99 & V_210 )
if ( V_211 )
F_138 ( & V_53 -> V_6 , & V_211 -> V_6 ) ;
else
F_4 ( & V_53 -> V_6 , & V_22 -> V_180 ) ;
else {
if ( V_211 )
F_4 ( & V_53 -> V_6 , & V_211 -> V_6 ) ;
else
F_138 ( & V_53 -> V_6 , & V_22 -> V_180 ) ;
}
if ( F_39 ( & V_14 , V_209 , V_53 ) == NULL ) {
V_45 = - V_41 ;
goto V_221;
}
V_22 -> V_51 ++ ;
return 0 ;
V_221:
F_7 ( & V_53 -> V_6 ) ;
V_115:
F_158 ( & V_14 , V_53 ) ;
V_111:
for ( V_69 = 0 ; V_69 < V_213 ; V_69 ++ ) {
if ( V_189 [ V_69 ] . V_39 != NULL )
F_91 ( V_189 [ V_69 ] . V_39 -> type -> V_110 ) ;
}
return V_45 ;
}
static int F_166 ( struct V_96 * V_97 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_73 * V_74 = F_57 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
struct V_19 * V_20 ;
struct V_21 * V_22 = NULL ;
struct V_52 * V_53 ;
int V_9 = V_74 -> V_76 , V_45 = 0 ;
struct V_13 V_14 ;
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_78 ( V_3 ) )
return F_79 ( V_3 ) ;
V_20 = F_49 ( V_3 , V_24 [ V_199 ] ) ;
if ( F_78 ( V_20 ) )
return F_79 ( V_20 ) ;
if ( V_20 -> V_36 & V_43 )
return - V_55 ;
if ( V_24 [ V_200 ] ) {
V_22 = F_102 ( V_20 , V_24 [ V_200 ] ) ;
if ( F_78 ( V_22 ) )
return F_79 ( V_22 ) ;
}
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
if ( V_22 ) {
if ( V_24 [ V_201 ] ) {
V_53 = F_150 ( V_22 ,
V_24 [ V_201 ] ) ;
if ( F_78 ( V_53 ) )
return F_79 ( V_53 ) ;
V_45 = F_40 ( & V_14 , V_53 ) ;
} else {
V_45 = F_41 ( & V_14 ) ;
}
} else {
F_9 (chain, &table->chains, list) {
V_14 . V_22 = V_22 ;
V_45 = F_41 ( & V_14 ) ;
if ( V_45 < 0 )
break;
}
}
return V_45 ;
}
int F_167 ( struct V_222 * V_39 )
{
F_3 ( V_5 ) ;
F_4 ( & V_39 -> V_6 , & V_223 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_168 ( struct V_222 * V_39 )
{
F_3 ( V_5 ) ;
F_7 ( & V_39 -> V_6 ) ;
F_5 ( V_5 ) ;
}
static const struct V_222 *
F_169 ( const struct V_23 * const V_24 [] ,
const struct V_224 * V_225 ,
enum V_226 V_150 )
{
const struct V_222 * V_39 , * V_227 ;
struct V_228 V_229 , V_230 ;
T_1 V_231 ;
#ifdef F_11
if ( F_94 ( & V_223 ) ) {
F_5 ( V_5 ) ;
F_12 ( L_5 ) ;
F_3 ( V_5 ) ;
if ( ! F_94 ( & V_223 ) )
return F_13 ( - V_11 ) ;
}
#endif
V_231 = 0 ;
if ( V_24 [ V_232 ] != NULL ) {
V_231 = F_44 ( F_45 ( V_24 [ V_232 ] ) ) ;
V_231 &= V_233 | V_234 | V_235 ;
}
V_227 = NULL ;
V_230 . V_32 = ~ 0 ;
V_230 . V_236 = ~ 0 ;
F_9 (ops, &nf_tables_set_ops, list) {
if ( ( V_39 -> V_231 & V_231 ) != V_231 )
continue;
if ( ! V_39 -> V_237 ( V_225 , V_231 , & V_229 ) )
continue;
switch ( V_150 ) {
case V_238 :
if ( V_229 . V_236 < V_230 . V_236 )
break;
if ( V_229 . V_236 == V_230 . V_236 && V_229 . V_32 < V_230 . V_32 )
break;
continue;
case V_239 :
if ( V_229 . V_32 < V_230 . V_32 )
break;
if ( V_229 . V_32 == V_230 . V_32 && V_229 . V_236 < V_230 . V_236 )
break;
continue;
default:
break;
}
if ( ! F_89 ( V_39 -> V_110 ) )
continue;
if ( V_227 != NULL )
F_91 ( V_227 -> V_110 ) ;
V_227 = V_39 ;
V_230 = V_229 ;
}
if ( V_227 != NULL )
return V_227 ;
return F_13 ( - V_109 ) ;
}
static int F_170 ( struct V_13 * V_14 ,
const struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
const struct V_73 * V_74 = F_57 ( V_18 ) ;
struct V_2 * V_3 = NULL ;
struct V_19 * V_20 = NULL ;
if ( V_74 -> V_76 != V_91 ) {
V_3 = F_10 ( V_1 , V_74 -> V_76 , false ) ;
if ( F_78 ( V_3 ) )
return F_79 ( V_3 ) ;
}
if ( V_24 [ V_240 ] != NULL ) {
if ( V_3 == NULL )
return - V_12 ;
V_20 = F_49 ( V_3 , V_24 [ V_240 ] ) ;
if ( F_78 ( V_20 ) )
return F_79 ( V_20 ) ;
if ( V_20 -> V_36 & V_43 )
return - V_55 ;
}
F_14 ( V_14 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return 0 ;
}
struct V_58 * F_171 ( const struct V_19 * V_20 ,
const struct V_23 * V_24 )
{
struct V_58 * V_59 ;
if ( V_24 == NULL )
return F_13 ( - V_66 ) ;
F_9 (set, &table->sets, list) {
if ( ! F_48 ( V_24 , V_59 -> V_65 ) )
return V_59 ;
}
return F_13 ( - V_55 ) ;
}
struct V_58 * F_172 ( const struct V_1 * V_1 ,
const struct V_23 * V_24 )
{
struct V_30 * V_33 ;
T_1 V_241 = F_44 ( F_45 ( V_24 ) ) ;
F_9 (trans, &net->nft.commit_list, list) {
if ( V_33 -> V_31 == V_61 &&
V_241 == F_43 ( V_33 ) )
return V_60 ( V_33 ) ;
}
return F_13 ( - V_55 ) ;
}
static int F_173 ( struct V_13 * V_14 , struct V_58 * V_59 ,
const char * V_65 )
{
const struct V_58 * V_69 ;
const char * V_242 ;
unsigned long * V_243 ;
unsigned int V_213 = 0 , V_244 = 0 ;
V_242 = F_174 ( V_65 , V_245 , '%' ) ;
if ( V_242 != NULL ) {
if ( V_242 [ 1 ] != 'd' || strchr ( V_242 + 2 , '%' ) )
return - V_66 ;
V_243 = ( unsigned long * ) F_175 ( V_34 ) ;
if ( V_243 == NULL )
return - V_41 ;
V_92:
F_9 (i, &ctx->table->sets, list) {
int V_212 ;
if ( ! sscanf ( V_69 -> V_65 , V_65 , & V_212 ) )
continue;
if ( V_212 < V_244 || V_212 >= V_244 + V_246 * V_247 )
continue;
F_176 ( V_212 - V_244 , V_243 ) ;
}
V_213 = F_177 ( V_243 , V_246 * V_247 ) ;
if ( V_213 >= V_246 * V_247 ) {
V_244 += V_246 * V_247 ;
memset ( V_243 , 0 , V_247 ) ;
goto V_92;
}
F_178 ( ( unsigned long ) V_243 ) ;
}
snprintf ( V_59 -> V_65 , sizeof( V_59 -> V_65 ) , V_65 , V_244 + V_213 ) ;
F_9 (i, &ctx->table->sets, list) {
if ( ! strcmp ( V_59 -> V_65 , V_69 -> V_65 ) )
return - V_248 ;
}
return 0 ;
}
static int F_179 ( struct V_15 * V_16 , const struct V_13 * V_14 ,
const struct V_58 * V_59 , T_6 V_72 , T_6 V_36 )
{
struct V_73 * V_74 ;
struct V_17 * V_18 ;
struct V_23 * V_225 ;
T_1 V_26 = V_14 -> V_26 ;
T_1 V_28 = V_14 -> V_28 ;
V_72 |= V_5 << 8 ;
V_18 = F_56 ( V_16 , V_26 , V_28 , V_72 , sizeof( struct V_73 ) ,
V_36 ) ;
if ( V_18 == NULL )
goto V_75;
V_74 = F_57 ( V_18 ) ;
V_74 -> V_76 = V_14 -> V_3 -> V_9 ;
V_74 -> V_77 = V_78 ;
V_74 -> V_79 = F_58 ( V_14 -> V_1 -> V_7 . V_80 & 0xffff ) ;
if ( F_59 ( V_16 , V_240 , V_14 -> V_20 -> V_65 ) )
goto V_75;
if ( F_59 ( V_16 , V_249 , V_59 -> V_65 ) )
goto V_75;
if ( V_59 -> V_36 != 0 )
if ( F_60 ( V_16 , V_232 , F_61 ( V_59 -> V_36 ) ) )
goto V_75;
if ( F_60 ( V_16 , V_250 , F_61 ( V_59 -> V_251 ) ) )
goto V_75;
if ( F_60 ( V_16 , V_252 , F_61 ( V_59 -> V_253 ) ) )
goto V_75;
if ( V_59 -> V_36 & V_234 ) {
if ( F_60 ( V_16 , V_254 , F_61 ( V_59 -> V_255 ) ) )
goto V_75;
if ( F_60 ( V_16 , V_256 , F_61 ( V_59 -> V_220 ) ) )
goto V_75;
}
if ( V_59 -> V_257 &&
F_109 ( V_16 , V_258 , F_110 ( V_59 -> V_257 ) ) )
goto V_75;
if ( V_59 -> V_259 &&
F_60 ( V_16 , V_260 , F_61 ( V_59 -> V_259 ) ) )
goto V_75;
if ( V_59 -> V_150 != V_238 ) {
if ( F_60 ( V_16 , V_261 , F_61 ( V_59 -> V_150 ) ) )
goto V_75;
}
V_225 = F_108 ( V_16 , V_262 ) ;
if ( V_225 == NULL )
goto V_75;
if ( V_59 -> V_32 &&
F_60 ( V_16 , V_263 , F_61 ( V_59 -> V_32 ) ) )
goto V_75;
F_111 ( V_16 , V_225 ) ;
F_62 ( V_16 , V_18 ) ;
return 0 ;
V_75:
F_63 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_180 ( const struct V_13 * V_14 ,
const struct V_58 * V_59 ,
int V_72 , T_7 V_264 )
{
struct V_15 * V_16 ;
T_1 V_26 = V_14 -> V_26 ;
int V_45 ;
if ( ! V_14 -> V_27 &&
! F_65 ( V_14 -> V_1 , V_84 ) )
return 0 ;
V_45 = - V_85 ;
V_16 = F_66 ( V_86 , V_264 ) ;
if ( V_16 == NULL )
goto V_45;
V_45 = F_179 ( V_16 , V_14 , V_59 , V_72 , 0 ) ;
if ( V_45 < 0 ) {
F_67 ( V_16 ) ;
goto V_45;
}
V_45 = F_68 ( V_16 , V_14 -> V_1 , V_26 , V_84 ,
V_14 -> V_27 , V_264 ) ;
V_45:
if ( V_45 < 0 )
F_69 ( V_14 -> V_1 , V_26 , V_84 , V_45 ) ;
return V_45 ;
}
static int F_181 ( struct V_15 * V_16 , struct V_87 * V_88 )
{
const struct V_58 * V_59 ;
unsigned int V_89 , V_90 = V_88 -> args [ 0 ] ;
struct V_2 * V_3 ;
struct V_19 * V_20 , * V_265 = (struct V_19 * ) V_88 -> args [ 2 ] ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_266 = V_88 -> args [ 3 ] ;
struct V_13 * V_14 = V_88 -> V_186 , V_267 ;
if ( V_88 -> args [ 1 ] )
return V_16 -> V_95 ;
F_71 () ;
V_88 -> V_28 = V_1 -> V_7 . V_80 ;
F_72 (afi, &net->nft.af_info, list) {
if ( V_14 -> V_3 && V_14 -> V_3 != V_3 )
continue;
if ( V_266 ) {
if ( V_3 -> V_9 != V_266 )
continue;
V_266 = 0 ;
}
F_72 (table, &afi->tables, list) {
if ( V_14 -> V_20 && V_14 -> V_20 != V_20 )
continue;
if ( V_265 ) {
if ( V_265 != V_20 )
continue;
V_265 = NULL ;
}
V_89 = 0 ;
F_72 (set, &table->sets, list) {
if ( V_89 < V_90 )
goto V_92;
V_267 = * V_14 ;
V_267 . V_20 = V_20 ;
V_267 . V_3 = V_3 ;
if ( F_179 ( V_16 , & V_267 , V_59 ,
V_61 ,
V_93 ) < 0 ) {
V_88 -> args [ 0 ] = V_89 ;
V_88 -> args [ 2 ] = ( unsigned long ) V_20 ;
V_88 -> args [ 3 ] = V_3 -> V_9 ;
goto V_94;
}
F_73 ( V_88 , F_74 ( V_16 ) ) ;
V_92:
V_89 ++ ;
}
if ( V_90 )
V_90 = 0 ;
}
}
V_88 -> args [ 1 ] = 1 ;
V_94:
F_75 () ;
return V_16 -> V_95 ;
}
static int F_182 ( struct V_87 * V_88 )
{
F_22 ( V_88 -> V_186 ) ;
return 0 ;
}
static int F_183 ( struct V_96 * V_97 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_58 * V_59 ;
struct V_13 V_14 ;
struct V_15 * V_98 ;
const struct V_73 * V_74 = F_57 ( V_18 ) ;
int V_45 ;
V_45 = F_170 ( & V_14 , V_16 , V_18 , V_24 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_18 -> V_99 & V_100 ) {
struct V_101 V_102 = {
. V_103 = F_181 ,
. V_94 = F_182 ,
} ;
struct V_13 * V_268 ;
V_268 = F_184 ( sizeof( * V_268 ) , V_34 ) ;
if ( V_268 == NULL )
return - V_41 ;
* V_268 = V_14 ;
V_102 . V_186 = V_268 ;
return F_77 ( V_97 , V_16 , V_18 , & V_102 ) ;
}
if ( V_74 -> V_76 == V_91 )
return - V_12 ;
V_59 = F_171 ( V_14 . V_20 , V_24 [ V_249 ] ) ;
if ( F_78 ( V_59 ) )
return F_79 ( V_59 ) ;
if ( V_59 -> V_36 & V_63 )
return - V_55 ;
V_98 = F_80 ( V_86 , V_34 ) ;
if ( V_98 == NULL )
return - V_41 ;
V_45 = F_179 ( V_98 , & V_14 , V_59 , V_61 , 0 ) ;
if ( V_45 < 0 )
goto V_45;
return F_81 ( V_97 , V_98 , F_16 ( V_16 ) . V_26 ) ;
V_45:
F_67 ( V_98 ) ;
return V_45 ;
}
static int F_185 ( const struct V_13 * V_14 ,
struct V_224 * V_225 ,
const struct V_23 * V_24 )
{
struct V_23 * V_269 [ V_270 + 1 ] ;
int V_45 ;
V_45 = F_117 ( V_269 , V_270 , V_24 , V_271 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_269 [ V_263 ] != NULL )
V_225 -> V_32 = F_44 ( F_45 ( V_269 [ V_263 ] ) ) ;
return 0 ;
}
static int F_186 ( struct V_96 * V_97 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_73 * V_74 = F_57 ( V_18 ) ;
const struct V_222 * V_39 ;
struct V_2 * V_3 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
struct V_19 * V_20 ;
struct V_58 * V_59 ;
struct V_13 V_14 ;
char V_65 [ V_245 ] ;
unsigned int V_32 ;
bool V_163 ;
T_2 V_257 ;
T_1 V_251 , V_255 , V_36 , V_150 , V_259 ;
struct V_224 V_225 ;
int V_45 ;
if ( V_24 [ V_240 ] == NULL ||
V_24 [ V_249 ] == NULL ||
V_24 [ V_252 ] == NULL ||
V_24 [ V_62 ] == NULL )
return - V_66 ;
memset ( & V_225 , 0 , sizeof( V_225 ) ) ;
V_251 = V_272 ;
if ( V_24 [ V_250 ] != NULL ) {
V_251 = F_44 ( F_45 ( V_24 [ V_250 ] ) ) ;
if ( ( V_251 & V_273 ) == V_273 )
return - V_66 ;
}
V_225 . V_253 = F_44 ( F_45 ( V_24 [ V_252 ] ) ) ;
if ( V_225 . V_253 == 0 || V_225 . V_253 > V_274 )
return - V_66 ;
V_36 = 0 ;
if ( V_24 [ V_232 ] != NULL ) {
V_36 = F_44 ( F_45 ( V_24 [ V_232 ] ) ) ;
if ( V_36 & ~ ( V_119 | V_275 |
V_233 | V_235 |
V_234 | V_276 ) )
return - V_66 ;
if ( ( V_36 & ( V_234 | V_276 ) ) ==
( V_234 | V_276 ) )
return - V_109 ;
}
V_255 = 0 ;
if ( V_24 [ V_254 ] != NULL ) {
if ( ! ( V_36 & V_234 ) )
return - V_66 ;
V_255 = F_44 ( F_45 ( V_24 [ V_254 ] ) ) ;
if ( ( V_255 & V_273 ) == V_273 &&
V_255 != V_277 )
return - V_66 ;
if ( V_255 != V_277 ) {
if ( V_24 [ V_256 ] == NULL )
return - V_66 ;
V_225 . V_220 = F_44 ( F_45 ( V_24 [ V_256 ] ) ) ;
if ( V_225 . V_220 == 0 || V_225 . V_220 > V_274 )
return - V_66 ;
} else
V_225 . V_220 = sizeof( struct V_278 ) ;
} else if ( V_36 & V_234 )
return - V_66 ;
V_257 = 0 ;
if ( V_24 [ V_258 ] != NULL ) {
if ( ! ( V_36 & V_235 ) )
return - V_66 ;
V_257 = F_121 ( F_122 ( V_24 [ V_258 ] ) ) ;
}
V_259 = 0 ;
if ( V_24 [ V_260 ] != NULL ) {
if ( ! ( V_36 & V_235 ) )
return - V_66 ;
V_259 = F_44 ( F_45 ( V_24 [ V_260 ] ) ) ;
}
V_150 = V_238 ;
if ( V_24 [ V_261 ] != NULL )
V_150 = F_44 ( F_45 ( V_24 [ V_261 ] ) ) ;
if ( V_24 [ V_262 ] != NULL ) {
V_45 = F_185 ( & V_14 , & V_225 , V_24 [ V_262 ] ) ;
if ( V_45 < 0 )
return V_45 ;
}
V_163 = V_18 -> V_99 & V_164 ? true : false ;
V_3 = F_10 ( V_1 , V_74 -> V_76 , V_163 ) ;
if ( F_78 ( V_3 ) )
return F_79 ( V_3 ) ;
V_20 = F_49 ( V_3 , V_24 [ V_240 ] ) ;
if ( F_78 ( V_20 ) )
return F_79 ( V_20 ) ;
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
V_59 = F_171 ( V_20 , V_24 [ V_249 ] ) ;
if ( F_78 ( V_59 ) ) {
if ( F_79 ( V_59 ) != - V_55 )
return F_79 ( V_59 ) ;
V_59 = NULL ;
}
if ( V_59 != NULL ) {
if ( V_18 -> V_99 & V_106 )
return - V_107 ;
if ( V_18 -> V_99 & V_108 )
return - V_109 ;
return 0 ;
}
if ( ! ( V_18 -> V_99 & V_164 ) )
return - V_55 ;
V_39 = F_169 ( V_24 , & V_225 , V_150 ) ;
if ( F_78 ( V_39 ) )
return F_79 ( V_39 ) ;
V_32 = 0 ;
if ( V_39 -> V_279 != NULL )
V_32 = V_39 -> V_279 ( V_24 ) ;
V_45 = - V_41 ;
V_59 = F_19 ( sizeof( * V_59 ) + V_32 , V_34 ) ;
if ( V_59 == NULL )
goto V_111;
F_90 ( V_65 , V_24 [ V_249 ] , sizeof( V_59 -> V_65 ) ) ;
V_45 = F_173 ( & V_14 , V_59 , V_65 ) ;
if ( V_45 < 0 )
goto V_115;
F_2 ( & V_59 -> V_120 ) ;
F_135 ( & V_59 -> V_175 , V_1 ) ;
V_59 -> V_39 = V_39 ;
V_59 -> V_251 = V_251 ;
V_59 -> V_253 = V_225 . V_253 ;
V_59 -> V_255 = V_255 ;
V_59 -> V_220 = V_225 . V_220 ;
V_59 -> V_36 = V_36 ;
V_59 -> V_32 = V_225 . V_32 ;
V_59 -> V_150 = V_150 ;
V_59 -> V_257 = V_257 ;
V_59 -> V_259 = V_259 ;
V_45 = V_39 -> V_195 ( V_59 , & V_225 , V_24 ) ;
if ( V_45 < 0 )
goto V_115;
V_45 = F_42 ( & V_14 , V_61 , V_59 ) ;
if ( V_45 < 0 )
goto V_115;
F_4 ( & V_59 -> V_6 , & V_20 -> V_114 ) ;
V_20 -> V_51 ++ ;
return 0 ;
V_115:
F_22 ( V_59 ) ;
V_111:
F_91 ( V_39 -> V_110 ) ;
return V_45 ;
}
static void F_187 ( struct V_58 * V_59 )
{
V_59 -> V_39 -> V_196 ( V_59 ) ;
F_91 ( V_59 -> V_39 -> V_110 ) ;
F_22 ( V_59 ) ;
}
static void F_188 ( const struct V_13 * V_14 , struct V_58 * V_59 )
{
F_7 ( & V_59 -> V_6 ) ;
F_180 ( V_14 , V_59 , V_64 , V_280 ) ;
F_187 ( V_59 ) ;
}
static int F_189 ( struct V_96 * V_97 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_73 * V_74 = F_57 ( V_18 ) ;
struct V_58 * V_59 ;
struct V_13 V_14 ;
int V_45 ;
if ( V_74 -> V_76 == V_91 )
return - V_12 ;
if ( V_24 [ V_240 ] == NULL )
return - V_66 ;
V_45 = F_170 ( & V_14 , V_16 , V_18 , V_24 ) ;
if ( V_45 < 0 )
return V_45 ;
V_59 = F_171 ( V_14 . V_20 , V_24 [ V_249 ] ) ;
if ( F_78 ( V_59 ) )
return F_79 ( V_59 ) ;
if ( V_59 -> V_36 & V_63 )
return - V_55 ;
if ( ! F_94 ( & V_59 -> V_120 ) )
return - V_124 ;
return F_46 ( & V_14 , V_59 ) ;
}
static int F_190 ( const struct V_13 * V_14 ,
const struct V_58 * V_59 ,
const struct V_281 * V_282 ,
const struct V_283 * V_284 )
{
const struct V_285 * V_286 = F_191 ( V_59 , V_284 -> V_177 ) ;
enum V_287 V_288 ;
V_288 = F_192 ( V_59 -> V_255 ) ;
return F_193 ( V_14 , V_288 , F_194 ( V_286 ) ,
V_59 -> V_255 == V_277 ?
V_277 : V_272 ,
V_59 -> V_220 ) ;
}
int F_195 ( const struct V_13 * V_14 , struct V_58 * V_59 ,
struct V_289 * V_290 )
{
struct V_289 * V_69 ;
struct V_281 V_282 ;
if ( ! F_94 ( & V_59 -> V_120 ) && V_59 -> V_36 & V_119 )
return - V_124 ;
if ( V_290 -> V_36 & V_234 ) {
F_9 (i, &set->bindings, list) {
if ( V_290 -> V_36 & V_234 &&
V_69 -> V_22 == V_290 -> V_22 )
goto V_291;
}
V_282 . V_292 = 0 ;
V_282 . V_293 = 0 ;
V_282 . V_45 = 0 ;
V_282 . V_294 = F_190 ;
V_59 -> V_39 -> V_295 ( V_14 , V_59 , & V_282 ) ;
if ( V_282 . V_45 < 0 ) {
if ( V_59 -> V_36 & V_119 )
F_188 ( V_14 , V_59 ) ;
return V_282 . V_45 ;
}
}
V_291:
V_290 -> V_22 = V_14 -> V_22 ;
F_4 ( & V_290 -> V_6 , & V_59 -> V_120 ) ;
return 0 ;
}
void F_196 ( const struct V_13 * V_14 , struct V_58 * V_59 ,
struct V_289 * V_290 )
{
F_7 ( & V_290 -> V_6 ) ;
if ( F_94 ( & V_59 -> V_120 ) && V_59 -> V_36 & V_119 &&
! ( V_59 -> V_36 & V_63 ) )
F_188 ( V_14 , V_59 ) ;
}
static int F_197 ( struct V_13 * V_14 ,
const struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
bool V_33 )
{
const struct V_73 * V_74 = F_57 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
V_3 = F_10 ( V_1 , V_74 -> V_76 , false ) ;
if ( F_78 ( V_3 ) )
return F_79 ( V_3 ) ;
V_20 = F_49 ( V_3 , V_24 [ V_296 ] ) ;
if ( F_78 ( V_20 ) )
return F_79 ( V_20 ) ;
if ( ! V_33 && ( V_20 -> V_36 & V_43 ) )
return - V_55 ;
F_14 ( V_14 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return 0 ;
}
static int F_198 ( struct V_15 * V_16 ,
const struct V_58 * V_59 ,
const struct V_283 * V_284 )
{
const struct V_285 * V_286 = F_191 ( V_59 , V_284 -> V_177 ) ;
unsigned char * V_297 = F_199 ( V_16 ) ;
struct V_23 * V_130 ;
V_130 = F_108 ( V_16 , V_205 ) ;
if ( V_130 == NULL )
goto V_75;
if ( F_200 ( V_16 , V_298 , F_201 ( V_286 ) ,
V_272 , V_59 -> V_253 ) < 0 )
goto V_75;
if ( F_202 ( V_286 , V_299 ) &&
F_200 ( V_16 , V_300 , F_194 ( V_286 ) ,
V_59 -> V_255 == V_277 ? V_277 : V_272 ,
V_59 -> V_220 ) < 0 )
goto V_75;
if ( F_202 ( V_286 , V_301 ) &&
F_143 ( V_16 , V_302 , F_203 ( V_286 ) ) < 0 )
goto V_75;
if ( F_202 ( V_286 , V_303 ) &&
F_60 ( V_16 , V_304 ,
F_61 ( * F_204 ( V_286 ) ) ) )
goto V_75;
if ( F_202 ( V_286 , V_305 ) &&
F_109 ( V_16 , V_306 ,
F_110 ( * F_205 ( V_286 ) ) ) )
goto V_75;
if ( F_202 ( V_286 , V_307 ) ) {
unsigned long V_308 , V_309 = V_310 ;
V_308 = * F_206 ( V_286 ) ;
if ( F_207 ( V_309 , V_308 ) )
V_308 -= V_309 ;
else
V_308 = 0 ;
if ( F_109 ( V_16 , V_311 ,
F_110 ( F_208 ( V_308 ) ) ) )
goto V_75;
}
if ( F_202 ( V_286 , V_312 ) ) {
struct V_207 * V_206 ;
V_206 = F_209 ( V_286 ) ;
if ( F_154 ( V_16 , V_313 ,
V_206 -> V_95 + 1 , V_206 -> V_186 ) )
goto V_75;
}
F_111 ( V_16 , V_130 ) ;
return 0 ;
V_75:
F_63 ( V_16 , V_297 ) ;
return - V_314 ;
}
static int F_210 ( const struct V_13 * V_14 ,
const struct V_58 * V_59 ,
const struct V_281 * V_282 ,
const struct V_283 * V_284 )
{
struct V_315 * args ;
args = F_211 ( V_282 , struct V_315 , V_282 ) ;
return F_198 ( args -> V_16 , V_59 , V_284 ) ;
}
static int F_212 ( struct V_15 * V_16 , struct V_87 * V_88 )
{
const struct V_58 * V_59 ;
struct V_315 args ;
struct V_13 V_14 ;
struct V_23 * V_24 [ V_316 + 1 ] ;
struct V_73 * V_74 ;
struct V_17 * V_18 ;
struct V_23 * V_130 ;
T_1 V_26 , V_28 ;
int V_72 , V_45 ;
V_45 = F_213 ( V_88 -> V_18 , sizeof( struct V_73 ) , V_24 ,
V_316 , V_317 ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = F_197 ( & V_14 , V_88 -> V_16 , V_88 -> V_18 , ( void * ) V_24 ,
false ) ;
if ( V_45 < 0 )
return V_45 ;
V_59 = F_171 ( V_14 . V_20 , V_24 [ V_318 ] ) ;
if ( F_78 ( V_59 ) )
return F_79 ( V_59 ) ;
if ( V_59 -> V_36 & V_63 )
return - V_55 ;
V_72 = V_319 ;
V_72 |= V_5 << 8 ;
V_26 = F_16 ( V_88 -> V_16 ) . V_26 ;
V_28 = V_88 -> V_18 -> V_29 ;
V_18 = F_56 ( V_16 , V_26 , V_28 , V_72 , sizeof( struct V_73 ) ,
V_93 ) ;
if ( V_18 == NULL )
goto V_75;
V_74 = F_57 ( V_18 ) ;
V_74 -> V_76 = V_14 . V_3 -> V_9 ;
V_74 -> V_77 = V_78 ;
V_74 -> V_79 = F_58 ( V_14 . V_1 -> V_7 . V_80 & 0xffff ) ;
if ( F_59 ( V_16 , V_296 , V_14 . V_20 -> V_65 ) )
goto V_75;
if ( F_59 ( V_16 , V_318 , V_59 -> V_65 ) )
goto V_75;
V_130 = F_108 ( V_16 , V_320 ) ;
if ( V_130 == NULL )
goto V_75;
args . V_88 = V_88 ;
args . V_16 = V_16 ;
args . V_282 . V_292 = V_88 -> args [ 0 ] ;
args . V_282 . V_293 = 0 ;
args . V_282 . V_45 = 0 ;
args . V_282 . V_294 = F_210 ;
V_59 -> V_39 -> V_295 ( & V_14 , V_59 , & args . V_282 ) ;
F_111 ( V_16 , V_130 ) ;
F_62 ( V_16 , V_18 ) ;
if ( args . V_282 . V_45 && args . V_282 . V_45 != - V_314 )
return args . V_282 . V_45 ;
if ( args . V_282 . V_293 == V_88 -> args [ 0 ] )
return 0 ;
V_88 -> args [ 0 ] = args . V_282 . V_293 ;
return V_16 -> V_95 ;
V_75:
return - V_138 ;
}
static int F_214 ( struct V_96 * V_97 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_58 * V_59 ;
struct V_13 V_14 ;
int V_45 ;
V_45 = F_197 ( & V_14 , V_16 , V_18 , V_24 , false ) ;
if ( V_45 < 0 )
return V_45 ;
V_59 = F_171 ( V_14 . V_20 , V_24 [ V_318 ] ) ;
if ( F_78 ( V_59 ) )
return F_79 ( V_59 ) ;
if ( V_59 -> V_36 & V_63 )
return - V_55 ;
if ( V_18 -> V_99 & V_100 ) {
struct V_101 V_102 = {
. V_103 = F_212 ,
} ;
return F_77 ( V_97 , V_16 , V_18 , & V_102 ) ;
}
return - V_109 ;
}
static int F_215 ( struct V_15 * V_16 ,
const struct V_13 * V_14 , T_1 V_28 ,
T_1 V_26 , int V_72 , T_6 V_36 ,
const struct V_58 * V_59 ,
const struct V_283 * V_284 )
{
struct V_73 * V_74 ;
struct V_17 * V_18 ;
struct V_23 * V_130 ;
int V_45 ;
V_72 |= V_5 << 8 ;
V_18 = F_56 ( V_16 , V_26 , V_28 , V_72 , sizeof( struct V_73 ) ,
V_36 ) ;
if ( V_18 == NULL )
goto V_75;
V_74 = F_57 ( V_18 ) ;
V_74 -> V_76 = V_14 -> V_3 -> V_9 ;
V_74 -> V_77 = V_78 ;
V_74 -> V_79 = F_58 ( V_14 -> V_1 -> V_7 . V_80 & 0xffff ) ;
if ( F_59 ( V_16 , V_240 , V_14 -> V_20 -> V_65 ) )
goto V_75;
if ( F_59 ( V_16 , V_249 , V_59 -> V_65 ) )
goto V_75;
V_130 = F_108 ( V_16 , V_320 ) ;
if ( V_130 == NULL )
goto V_75;
V_45 = F_198 ( V_16 , V_59 , V_284 ) ;
if ( V_45 < 0 )
goto V_75;
F_111 ( V_16 , V_130 ) ;
F_62 ( V_16 , V_18 ) ;
return 0 ;
V_75:
F_63 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_216 ( const struct V_13 * V_14 ,
const struct V_58 * V_59 ,
const struct V_283 * V_284 ,
int V_72 , T_6 V_36 )
{
struct V_1 * V_1 = V_14 -> V_1 ;
T_1 V_26 = V_14 -> V_26 ;
struct V_15 * V_16 ;
int V_45 ;
if ( ! V_14 -> V_27 && ! F_65 ( V_1 , V_84 ) )
return 0 ;
V_45 = - V_85 ;
V_16 = F_66 ( V_86 , V_34 ) ;
if ( V_16 == NULL )
goto V_45;
V_45 = F_215 ( V_16 , V_14 , 0 , V_26 , V_72 , V_36 ,
V_59 , V_284 ) ;
if ( V_45 < 0 ) {
F_67 ( V_16 ) ;
goto V_45;
}
V_45 = F_68 ( V_16 , V_1 , V_26 , V_84 , V_14 -> V_27 ,
V_34 ) ;
V_45:
if ( V_45 < 0 )
F_69 ( V_1 , V_26 , V_84 , V_45 ) ;
return V_45 ;
}
static struct V_30 * F_217 ( struct V_13 * V_14 ,
int V_31 ,
struct V_58 * V_59 )
{
struct V_30 * V_33 ;
V_33 = F_18 ( V_14 , V_31 , sizeof( struct V_321 ) ) ;
if ( V_33 == NULL )
return NULL ;
F_218 ( V_33 ) = V_59 ;
return V_33 ;
}
void * F_219 ( const struct V_58 * V_59 ,
const struct V_322 * V_323 ,
const T_1 * V_324 , const T_1 * V_186 ,
T_2 V_257 , T_7 V_325 )
{
struct V_285 * V_286 ;
void * V_284 ;
V_284 = F_19 ( V_59 -> V_39 -> V_326 + V_323 -> V_95 , V_325 ) ;
if ( V_284 == NULL )
return NULL ;
V_286 = F_191 ( V_59 , V_284 ) ;
F_220 ( V_286 , V_323 ) ;
memcpy ( F_201 ( V_286 ) , V_324 , V_59 -> V_253 ) ;
if ( F_202 ( V_286 , V_299 ) )
memcpy ( F_194 ( V_286 ) , V_186 , V_59 -> V_220 ) ;
if ( F_202 ( V_286 , V_307 ) )
* F_206 ( V_286 ) =
V_310 + F_221 ( V_257 ) ;
if ( F_202 ( V_286 , V_305 ) )
* F_205 ( V_286 ) = V_257 ;
return V_284 ;
}
void F_222 ( const struct V_58 * V_59 , void * V_284 )
{
struct V_285 * V_286 = F_191 ( V_59 , V_284 ) ;
F_223 ( F_201 ( V_286 ) , V_272 ) ;
if ( F_202 ( V_286 , V_299 ) )
F_223 ( F_194 ( V_286 ) , V_59 -> V_255 ) ;
if ( F_202 ( V_286 , V_301 ) )
F_146 ( NULL , F_203 ( V_286 ) ) ;
F_22 ( V_284 ) ;
}
static int F_224 ( struct V_13 * V_14 , struct V_58 * V_59 ,
const struct V_23 * V_153 )
{
struct V_23 * V_24 [ V_327 + 1 ] ;
struct V_328 V_329 , V_330 ;
struct V_322 V_323 ;
struct V_285 * V_286 ;
struct V_283 V_284 ;
struct V_289 * V_290 ;
struct V_207 * V_206 ;
struct V_331 V_186 ;
enum V_287 V_288 ;
struct V_30 * V_33 ;
T_2 V_257 ;
T_1 V_36 ;
T_4 V_214 ;
int V_45 ;
V_45 = F_117 ( V_24 , V_327 , V_153 ,
V_332 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_24 [ V_298 ] == NULL )
return - V_66 ;
F_225 ( & V_323 ) ;
V_36 = 0 ;
if ( V_24 [ V_304 ] != NULL ) {
V_36 = F_44 ( F_45 ( V_24 [ V_304 ] ) ) ;
if ( V_36 & ~ V_333 )
return - V_66 ;
if ( ! ( V_59 -> V_36 & V_233 ) &&
V_36 & V_333 )
return - V_66 ;
if ( V_36 != 0 )
F_226 ( & V_323 , V_303 ) ;
}
if ( V_59 -> V_36 & V_234 ) {
if ( V_24 [ V_300 ] == NULL &&
! ( V_36 & V_333 ) )
return - V_66 ;
if ( V_24 [ V_300 ] != NULL &&
V_36 & V_333 )
return - V_66 ;
} else {
if ( V_24 [ V_300 ] != NULL )
return - V_66 ;
}
V_257 = 0 ;
if ( V_24 [ V_306 ] != NULL ) {
if ( ! ( V_59 -> V_36 & V_235 ) )
return - V_66 ;
V_257 = F_121 ( F_122 ( V_24 [ V_306 ] ) ) ;
} else if ( V_59 -> V_36 & V_235 ) {
V_257 = V_59 -> V_257 ;
}
V_45 = F_227 ( V_14 , & V_284 . V_324 . V_334 , sizeof( V_284 . V_324 ) , & V_329 ,
V_24 [ V_298 ] ) ;
if ( V_45 < 0 )
goto V_111;
V_45 = - V_66 ;
if ( V_329 . type != V_272 || V_329 . V_95 != V_59 -> V_253 )
goto V_115;
F_228 ( & V_323 , V_335 , V_329 . V_95 ) ;
if ( V_257 > 0 ) {
F_226 ( & V_323 , V_307 ) ;
if ( V_257 != V_59 -> V_257 )
F_226 ( & V_323 , V_305 ) ;
}
if ( V_24 [ V_300 ] != NULL ) {
V_45 = F_227 ( V_14 , & V_186 , sizeof( V_186 ) , & V_330 ,
V_24 [ V_300 ] ) ;
if ( V_45 < 0 )
goto V_115;
V_45 = - V_66 ;
if ( V_59 -> V_255 != V_277 && V_330 . V_95 != V_59 -> V_220 )
goto V_221;
V_288 = F_192 ( V_59 -> V_255 ) ;
F_9 (binding, &set->bindings, list) {
struct V_13 V_336 = {
. V_3 = V_14 -> V_3 ,
. V_20 = V_14 -> V_20 ,
. V_22 = (struct V_21 * ) V_290 -> V_22 ,
} ;
if ( ! ( V_290 -> V_36 & V_234 ) )
continue;
V_45 = F_193 ( & V_336 , V_288 ,
& V_186 ,
V_330 . type , V_330 . V_95 ) ;
if ( V_45 < 0 )
goto V_221;
}
F_228 ( & V_323 , V_299 , V_330 . V_95 ) ;
}
V_214 = 0 ;
if ( V_24 [ V_313 ] != NULL ) {
V_214 = F_53 ( V_24 [ V_313 ] ) ;
if ( V_214 > 0 )
F_228 ( & V_323 , V_312 ,
V_214 ) ;
}
V_45 = - V_41 ;
V_284 . V_177 = F_219 ( V_59 , & V_323 , V_284 . V_324 . V_334 . V_186 , V_186 . V_186 ,
V_257 , V_34 ) ;
if ( V_284 . V_177 == NULL )
goto V_221;
V_286 = F_191 ( V_59 , V_284 . V_177 ) ;
if ( V_36 )
* F_204 ( V_286 ) = V_36 ;
if ( V_214 > 0 ) {
V_206 = F_209 ( V_286 ) ;
V_206 -> V_95 = V_214 - 1 ;
F_165 ( & V_206 -> V_186 , V_24 [ V_313 ] , V_214 ) ;
}
V_33 = F_217 ( V_14 , V_319 , V_59 ) ;
if ( V_33 == NULL )
goto V_337;
V_286 -> V_54 = F_32 ( V_14 -> V_1 ) | V_338 ;
V_45 = V_59 -> V_39 -> V_339 ( V_59 , & V_284 ) ;
if ( V_45 < 0 )
goto V_340;
V_321 ( V_33 ) = V_284 ;
F_27 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_44 ) ;
return 0 ;
V_340:
F_22 ( V_33 ) ;
V_337:
F_22 ( V_284 . V_177 ) ;
V_221:
if ( V_24 [ V_300 ] != NULL )
F_223 ( & V_186 , V_330 . type ) ;
V_115:
F_223 ( & V_284 . V_324 . V_334 , V_329 . type ) ;
V_111:
return V_45 ;
}
static int F_229 ( struct V_96 * V_97 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
const struct V_23 * V_153 ;
struct V_58 * V_59 ;
struct V_13 V_14 ;
int V_216 , V_45 = 0 ;
if ( V_24 [ V_320 ] == NULL )
return - V_66 ;
V_45 = F_197 ( & V_14 , V_16 , V_18 , V_24 , true ) ;
if ( V_45 < 0 )
return V_45 ;
V_59 = F_171 ( V_14 . V_20 , V_24 [ V_318 ] ) ;
if ( F_78 ( V_59 ) ) {
if ( V_24 [ V_341 ] ) {
V_59 = F_172 ( V_1 ,
V_24 [ V_341 ] ) ;
}
if ( F_78 ( V_59 ) )
return F_79 ( V_59 ) ;
}
if ( ! F_94 ( & V_59 -> V_120 ) && V_59 -> V_36 & V_275 )
return - V_124 ;
F_163 (attr, nla[NFTA_SET_ELEM_LIST_ELEMENTS], rem) {
if ( V_59 -> V_32 &&
! F_230 ( & V_59 -> V_342 , 1 , V_59 -> V_32 + V_59 -> V_343 ) )
return - V_248 ;
V_45 = F_224 ( & V_14 , V_59 , V_153 ) ;
if ( V_45 < 0 ) {
F_231 ( & V_59 -> V_342 ) ;
break;
}
}
return V_45 ;
}
static int F_232 ( struct V_13 * V_14 , struct V_58 * V_59 ,
const struct V_23 * V_153 )
{
struct V_23 * V_24 [ V_327 + 1 ] ;
struct V_328 V_225 ;
struct V_283 V_284 ;
struct V_30 * V_33 ;
int V_45 ;
V_45 = F_117 ( V_24 , V_327 , V_153 ,
V_332 ) ;
if ( V_45 < 0 )
goto V_111;
V_45 = - V_66 ;
if ( V_24 [ V_298 ] == NULL )
goto V_111;
V_45 = F_227 ( V_14 , & V_284 . V_324 . V_334 , sizeof( V_284 . V_324 ) , & V_225 ,
V_24 [ V_298 ] ) ;
if ( V_45 < 0 )
goto V_111;
V_45 = - V_66 ;
if ( V_225 . type != V_272 || V_225 . V_95 != V_59 -> V_253 )
goto V_115;
V_33 = F_217 ( V_14 , V_344 , V_59 ) ;
if ( V_33 == NULL ) {
V_45 = - V_41 ;
goto V_115;
}
V_284 . V_177 = V_59 -> V_39 -> V_345 ( V_59 , & V_284 ) ;
if ( V_284 . V_177 == NULL ) {
V_45 = - V_55 ;
goto V_221;
}
V_321 ( V_33 ) = V_284 ;
F_27 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_44 ) ;
return 0 ;
V_221:
F_22 ( V_33 ) ;
V_115:
F_223 ( & V_284 . V_324 . V_334 , V_225 . type ) ;
V_111:
return V_45 ;
}
static int F_233 ( struct V_96 * V_97 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_23 * V_153 ;
struct V_58 * V_59 ;
struct V_13 V_14 ;
int V_216 , V_45 = 0 ;
if ( V_24 [ V_320 ] == NULL )
return - V_66 ;
V_45 = F_197 ( & V_14 , V_16 , V_18 , V_24 , false ) ;
if ( V_45 < 0 )
return V_45 ;
V_59 = F_171 ( V_14 . V_20 , V_24 [ V_318 ] ) ;
if ( F_78 ( V_59 ) )
return F_79 ( V_59 ) ;
if ( ! F_94 ( & V_59 -> V_120 ) && V_59 -> V_36 & V_275 )
return - V_124 ;
F_163 (attr, nla[NFTA_SET_ELEM_LIST_ELEMENTS], rem) {
V_45 = F_232 ( & V_14 , V_59 , V_153 ) ;
if ( V_45 < 0 )
break;
V_59 -> V_343 ++ ;
}
return V_45 ;
}
void F_234 ( struct V_346 * V_347 )
{
struct V_348 * V_349 ;
unsigned int V_69 ;
V_349 = F_211 ( V_347 , struct V_348 , V_350 . V_347 ) ;
for ( V_69 = 0 ; V_69 < V_349 -> V_350 . V_351 ; V_69 ++ )
F_222 ( V_349 -> V_350 . V_59 , V_349 -> V_352 [ V_69 ] ) ;
F_22 ( V_349 ) ;
}
struct V_348 * F_235 ( const struct V_58 * V_59 ,
T_7 V_325 )
{
struct V_348 * V_349 ;
V_349 = F_19 ( sizeof( * V_349 ) , V_325 ) ;
if ( V_349 == NULL )
return V_349 ;
V_349 -> V_350 . V_59 = V_59 ;
return V_349 ;
}
static int F_236 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_26 , T_1 V_28 )
{
struct V_17 * V_18 ;
struct V_73 * V_74 ;
int V_72 = ( V_5 << 8 ) | V_353 ;
V_18 = F_56 ( V_16 , V_26 , V_28 , V_72 , sizeof( struct V_73 ) , 0 ) ;
if ( V_18 == NULL )
goto V_75;
V_74 = F_57 ( V_18 ) ;
V_74 -> V_76 = V_122 ;
V_74 -> V_77 = V_78 ;
V_74 -> V_79 = F_58 ( V_1 -> V_7 . V_80 & 0xffff ) ;
if ( F_60 ( V_16 , V_354 , F_61 ( V_1 -> V_7 . V_80 ) ) )
goto V_75;
F_62 ( V_16 , V_18 ) ;
return 0 ;
V_75:
F_63 ( V_16 , V_18 ) ;
return - V_314 ;
}
static int F_237 ( struct V_1 * V_1 , struct V_15 * V_16 , int V_72 )
{
struct V_17 * V_18 = F_74 ( V_16 ) ;
struct V_15 * V_98 ;
int V_45 ;
if ( F_17 ( V_18 ) &&
! F_65 ( V_1 , V_84 ) )
return 0 ;
V_45 = - V_85 ;
V_98 = F_66 ( V_86 , V_34 ) ;
if ( V_98 == NULL )
goto V_45;
V_45 = F_236 ( V_98 , V_1 , F_16 ( V_16 ) . V_26 ,
V_18 -> V_29 ) ;
if ( V_45 < 0 ) {
F_67 ( V_98 ) ;
goto V_45;
}
V_45 = F_68 ( V_98 , V_1 , F_16 ( V_16 ) . V_26 ,
V_84 , F_17 ( V_18 ) , V_34 ) ;
V_45:
if ( V_45 < 0 ) {
F_69 ( V_1 , F_16 ( V_16 ) . V_26 , V_84 ,
V_45 ) ;
}
return V_45 ;
}
static int F_238 ( struct V_96 * V_97 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
struct V_15 * V_98 ;
int V_45 ;
V_98 = F_80 ( V_86 , V_34 ) ;
if ( V_98 == NULL )
return - V_41 ;
V_45 = F_236 ( V_98 , V_1 , F_16 ( V_16 ) . V_26 ,
V_18 -> V_29 ) ;
if ( V_45 < 0 )
goto V_45;
return F_81 ( V_97 , V_98 , F_16 ( V_16 ) . V_26 ) ;
V_45:
F_67 ( V_98 ) ;
return V_45 ;
}
static void F_239 ( struct V_30 * V_33 )
{
struct F_25 * V_142 ;
if ( F_134 ( V_33 ) [ 0 ] )
strcpy ( V_33 -> V_14 . V_22 -> V_65 , F_134 ( V_33 ) ) ;
if ( ! ( V_33 -> V_14 . V_22 -> V_36 & V_38 ) )
return;
V_142 = F_25 ( V_33 -> V_14 . V_22 ) ;
F_124 ( V_142 , F_131 ( V_33 ) ) ;
switch ( F_133 ( V_33 ) ) {
case V_165 :
case V_162 :
V_142 -> V_150 = F_133 ( V_33 ) ;
break;
}
}
static void F_240 ( struct V_30 * V_33 )
{
switch ( V_33 -> V_31 ) {
case V_46 :
F_97 ( & V_33 -> V_14 ) ;
break;
case V_50 :
F_129 ( V_33 -> V_14 . V_22 ) ;
break;
case V_57 :
F_158 ( & V_33 -> V_14 , V_56 ( V_33 ) ) ;
break;
case V_64 :
F_187 ( V_60 ( V_33 ) ) ;
break;
case V_344 :
F_222 ( F_218 ( V_33 ) ,
V_321 ( V_33 ) . V_177 ) ;
break;
}
F_22 ( V_33 ) ;
}
static int F_241 ( struct V_15 * V_16 )
{
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
struct V_30 * V_33 , * V_197 ;
struct V_321 * V_355 ;
while ( ++ V_1 -> V_7 . V_80 == 0 ) ;
V_1 -> V_7 . V_356 = F_242 ( V_1 ) ;
F_127 () ;
F_93 (trans, next, &net->nft.commit_list, list) {
switch ( V_33 -> V_31 ) {
case V_42 :
if ( F_87 ( V_33 ) ) {
if ( ! F_86 ( V_33 ) ) {
F_84 ( V_33 -> V_14 . V_3 ,
V_33 -> V_14 . V_20 ) ;
V_33 -> V_14 . V_20 -> V_36 |= V_37 ;
}
} else {
V_33 -> V_14 . V_20 -> V_36 &= ~ V_43 ;
}
F_64 ( & V_33 -> V_14 , V_42 ) ;
F_20 ( V_33 ) ;
break;
case V_46 :
F_64 ( & V_33 -> V_14 , V_46 ) ;
break;
case V_48 :
if ( F_132 ( V_33 ) )
F_239 ( V_33 ) ;
else
V_33 -> V_14 . V_22 -> V_36 &= ~ V_49 ;
F_113 ( & V_33 -> V_14 , V_48 ) ;
F_20 ( V_33 ) ;
break;
case V_50 :
F_113 ( & V_33 -> V_14 , V_50 ) ;
F_23 ( V_33 -> V_14 . V_20 ,
V_33 -> V_14 . V_22 ,
V_33 -> V_14 . V_3 -> V_104 ) ;
break;
case V_209 :
F_37 ( V_33 -> V_14 . V_1 , V_56 ( V_33 ) ) ;
F_155 ( & V_33 -> V_14 ,
V_56 ( V_33 ) ,
V_209 ) ;
F_20 ( V_33 ) ;
break;
case V_57 :
F_7 ( & V_56 ( V_33 ) -> V_6 ) ;
F_155 ( & V_33 -> V_14 ,
V_56 ( V_33 ) ,
V_57 ) ;
break;
case V_61 :
V_60 ( V_33 ) -> V_36 &= ~ V_63 ;
if ( V_60 ( V_33 ) -> V_36 & V_119 &&
! F_94 ( & V_60 ( V_33 ) -> V_120 ) )
V_33 -> V_14 . V_20 -> V_51 -- ;
F_180 ( & V_33 -> V_14 , V_60 ( V_33 ) ,
V_61 , V_34 ) ;
F_20 ( V_33 ) ;
break;
case V_64 :
F_180 ( & V_33 -> V_14 , V_60 ( V_33 ) ,
V_64 , V_34 ) ;
break;
case V_319 :
V_355 = (struct V_321 * ) V_33 -> V_186 ;
V_355 -> V_59 -> V_39 -> V_357 ( V_355 -> V_59 , & V_355 -> V_284 ) ;
F_216 ( & V_33 -> V_14 , V_355 -> V_59 ,
& V_355 -> V_284 ,
V_319 , 0 ) ;
F_20 ( V_33 ) ;
break;
case V_344 :
V_355 = (struct V_321 * ) V_33 -> V_186 ;
F_216 ( & V_33 -> V_14 , V_355 -> V_59 ,
& V_355 -> V_284 ,
V_344 , 0 ) ;
V_355 -> V_59 -> V_39 -> remove ( V_355 -> V_59 , & V_355 -> V_284 ) ;
F_231 ( & V_355 -> V_59 -> V_342 ) ;
V_355 -> V_59 -> V_343 -- ;
break;
}
}
F_127 () ;
F_93 (trans, next, &net->nft.commit_list, list) {
F_21 ( & V_33 -> V_6 ) ;
F_240 ( V_33 ) ;
}
F_237 ( V_1 , V_16 , V_353 ) ;
return 0 ;
}
static void F_243 ( struct V_30 * V_33 )
{
switch ( V_33 -> V_31 ) {
case V_42 :
F_97 ( & V_33 -> V_14 ) ;
break;
case V_48 :
F_129 ( V_33 -> V_14 . V_22 ) ;
break;
case V_209 :
F_158 ( & V_33 -> V_14 , V_56 ( V_33 ) ) ;
break;
case V_61 :
F_187 ( V_60 ( V_33 ) ) ;
break;
case V_319 :
F_222 ( F_218 ( V_33 ) ,
V_321 ( V_33 ) . V_177 ) ;
break;
}
F_22 ( V_33 ) ;
}
static int F_244 ( struct V_15 * V_16 )
{
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
struct V_30 * V_33 , * V_197 ;
struct V_321 * V_355 ;
F_93 (trans, next, &net->nft.commit_list, list) {
switch ( V_33 -> V_31 ) {
case V_42 :
if ( F_87 ( V_33 ) ) {
if ( F_86 ( V_33 ) ) {
F_84 ( V_33 -> V_14 . V_3 ,
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
if ( F_132 ( V_33 ) ) {
F_128 ( F_131 ( V_33 ) ) ;
F_20 ( V_33 ) ;
} else {
V_33 -> V_14 . V_20 -> V_51 -- ;
F_7 ( & V_33 -> V_14 . V_22 -> V_6 ) ;
F_23 ( V_33 -> V_14 . V_20 ,
V_33 -> V_14 . V_22 ,
V_33 -> V_14 . V_3 -> V_104 ) ;
}
break;
case V_50 :
V_33 -> V_14 . V_20 -> V_51 ++ ;
F_4 ( & V_33 -> V_14 . V_22 -> V_6 ,
& V_33 -> V_14 . V_20 -> V_113 ) ;
F_20 ( V_33 ) ;
break;
case V_209 :
V_33 -> V_14 . V_22 -> V_51 -- ;
F_7 ( & V_56 ( V_33 ) -> V_6 ) ;
break;
case V_57 :
V_33 -> V_14 . V_22 -> V_51 ++ ;
F_37 ( V_33 -> V_14 . V_1 , V_56 ( V_33 ) ) ;
F_20 ( V_33 ) ;
break;
case V_61 :
V_33 -> V_14 . V_20 -> V_51 -- ;
F_7 ( & V_60 ( V_33 ) -> V_6 ) ;
break;
case V_64 :
V_33 -> V_14 . V_20 -> V_51 ++ ;
F_4 ( & V_60 ( V_33 ) -> V_6 ,
& V_33 -> V_14 . V_20 -> V_114 ) ;
F_20 ( V_33 ) ;
break;
case V_319 :
V_355 = (struct V_321 * ) V_33 -> V_186 ;
V_355 -> V_59 -> V_39 -> remove ( V_355 -> V_59 , & V_355 -> V_284 ) ;
F_231 ( & V_355 -> V_59 -> V_342 ) ;
break;
case V_344 :
V_355 = (struct V_321 * ) V_33 -> V_186 ;
V_355 -> V_59 -> V_39 -> V_357 ( V_355 -> V_59 , & V_355 -> V_284 ) ;
V_355 -> V_59 -> V_343 -- ;
F_20 ( V_33 ) ;
break;
}
}
F_127 () ;
F_245 (trans, next,
&net->nft.commit_list, list) {
F_21 ( & V_33 -> V_6 ) ;
F_243 ( V_33 ) ;
}
return 0 ;
}
int F_246 ( const struct V_21 * V_22 ,
enum V_358 type )
{
const struct F_25 * V_142 ;
if ( V_22 -> V_36 & V_38 ) {
V_142 = F_25 ( V_22 ) ;
if ( V_142 -> type -> type != type )
return - V_109 ;
}
return 0 ;
}
int F_247 ( const struct V_21 * V_22 ,
unsigned int V_359 )
{
struct F_25 * V_142 ;
if ( V_22 -> V_36 & V_38 ) {
V_142 = F_25 ( V_22 ) ;
if ( ( 1 << V_142 -> V_39 [ 0 ] . V_146 ) & V_359 )
return 0 ;
return - V_109 ;
}
return 0 ;
}
static int F_248 ( const struct V_13 * V_14 ,
const struct V_58 * V_59 ,
const struct V_281 * V_282 ,
const struct V_283 * V_284 )
{
const struct V_285 * V_286 = F_191 ( V_59 , V_284 -> V_177 ) ;
const struct V_331 * V_186 ;
if ( F_202 ( V_286 , V_303 ) &&
* F_204 ( V_286 ) & V_333 )
return 0 ;
V_186 = F_194 ( V_286 ) ;
switch ( V_186 -> V_360 . V_361 ) {
case V_362 :
case V_363 :
return F_249 ( V_14 , V_186 -> V_360 . V_22 ) ;
default:
return 0 ;
}
}
static int F_249 ( const struct V_13 * V_14 ,
const struct V_21 * V_22 )
{
const struct V_52 * V_53 ;
const struct V_183 * V_184 , * V_364 ;
const struct V_58 * V_59 ;
struct V_289 * V_290 ;
struct V_281 V_282 ;
if ( V_14 -> V_22 == V_22 )
return - V_365 ;
F_9 (rule, &chain->rules, list) {
F_153 (expr, last, rule) {
const struct V_331 * V_186 = NULL ;
int V_45 ;
if ( ! V_184 -> V_39 -> V_366 )
continue;
V_45 = V_184 -> V_39 -> V_366 ( V_14 , V_184 , & V_186 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_186 == NULL )
continue;
switch ( V_186 -> V_360 . V_361 ) {
case V_362 :
case V_363 :
V_45 = F_249 ( V_14 ,
V_186 -> V_360 . V_22 ) ;
if ( V_45 < 0 )
return V_45 ;
default:
break;
}
}
}
F_9 (set, &ctx->table->sets, list) {
if ( ! ( V_59 -> V_36 & V_234 ) ||
V_59 -> V_255 != V_277 )
continue;
F_9 (binding, &set->bindings, list) {
if ( ! ( V_290 -> V_36 & V_234 ) ||
V_290 -> V_22 != V_22 )
continue;
V_282 . V_292 = 0 ;
V_282 . V_293 = 0 ;
V_282 . V_45 = 0 ;
V_282 . V_294 = F_248 ;
V_59 -> V_39 -> V_295 ( V_14 , V_59 , & V_282 ) ;
if ( V_282 . V_45 < 0 )
return V_282 . V_45 ;
}
}
return 0 ;
}
unsigned int F_250 ( const struct V_23 * V_153 )
{
unsigned int V_367 ;
V_367 = F_44 ( F_45 ( V_153 ) ) ;
switch ( V_367 ) {
case V_368 ... V_369 :
return V_367 * V_370 / V_371 ;
default:
return V_367 + V_370 / V_371 - V_372 ;
}
}
int F_251 ( struct V_15 * V_16 , unsigned int V_153 , unsigned int V_367 )
{
if ( V_367 % ( V_370 / V_371 ) == 0 )
V_367 = V_367 / ( V_370 / V_371 ) ;
else
V_367 = V_367 - V_370 / V_371 + V_372 ;
return F_60 ( V_16 , V_153 , F_61 ( V_367 ) ) ;
}
int F_252 ( enum V_287 V_367 , unsigned int V_95 )
{
if ( V_367 < V_373 * V_370 / V_371 )
return - V_66 ;
if ( V_95 == 0 )
return - V_66 ;
if ( V_367 * V_371 + V_95 > F_253 ( struct V_374 , V_186 ) )
return - V_375 ;
return 0 ;
}
int F_193 ( const struct V_13 * V_14 ,
enum V_287 V_367 ,
const struct V_331 * V_186 ,
enum V_376 type , unsigned int V_95 )
{
int V_45 ;
switch ( V_367 ) {
case V_368 :
if ( type != V_277 )
return - V_66 ;
if ( V_186 != NULL &&
( V_186 -> V_360 . V_361 == V_363 ||
V_186 -> V_360 . V_361 == V_362 ) ) {
V_45 = F_249 ( V_14 , V_186 -> V_360 . V_22 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_14 -> V_22 -> V_377 + 1 >
V_186 -> V_360 . V_22 -> V_377 ) {
if ( V_14 -> V_22 -> V_377 + 1 == V_378 )
return - V_379 ;
V_186 -> V_360 . V_22 -> V_377 = V_14 -> V_22 -> V_377 + 1 ;
}
}
return 0 ;
default:
if ( V_367 < V_373 * V_370 / V_371 )
return - V_66 ;
if ( V_95 == 0 )
return - V_66 ;
if ( V_367 * V_371 + V_95 >
F_253 ( struct V_374 , V_186 ) )
return - V_375 ;
if ( V_186 != NULL && type != V_272 )
return - V_66 ;
return 0 ;
}
}
static int F_254 ( const struct V_13 * V_14 , struct V_331 * V_186 ,
struct V_328 * V_225 , const struct V_23 * V_24 )
{
struct V_23 * V_154 [ V_380 + 1 ] ;
struct V_21 * V_22 ;
int V_45 ;
V_45 = F_117 ( V_154 , V_380 , V_24 , V_381 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( ! V_154 [ V_382 ] )
return - V_66 ;
V_186 -> V_360 . V_361 = F_44 ( F_45 ( V_154 [ V_382 ] ) ) ;
switch ( V_186 -> V_360 . V_361 ) {
default:
switch ( V_186 -> V_360 . V_361 & V_383 ) {
case V_162 :
case V_165 :
case V_384 :
break;
default:
return - V_66 ;
}
case V_385 :
case V_386 :
case V_387 :
break;
case V_362 :
case V_363 :
if ( ! V_154 [ V_388 ] )
return - V_66 ;
V_22 = F_102 ( V_14 -> V_20 ,
V_154 [ V_388 ] ) ;
if ( F_78 ( V_22 ) )
return F_79 ( V_22 ) ;
if ( V_22 -> V_36 & V_38 )
return - V_109 ;
V_22 -> V_51 ++ ;
V_186 -> V_360 . V_22 = V_22 ;
break;
}
V_225 -> V_95 = sizeof( V_186 -> V_360 ) ;
V_225 -> type = V_277 ;
return 0 ;
}
static void F_255 ( const struct V_331 * V_186 )
{
switch ( V_186 -> V_360 . V_361 ) {
case V_362 :
case V_363 :
V_186 -> V_360 . V_22 -> V_51 -- ;
break;
}
}
static int F_256 ( struct V_15 * V_16 , const struct V_331 * V_186 )
{
struct V_23 * V_130 ;
V_130 = F_108 ( V_16 , V_389 ) ;
if ( ! V_130 )
goto V_75;
if ( F_60 ( V_16 , V_382 , F_61 ( V_186 -> V_360 . V_361 ) ) )
goto V_75;
switch ( V_186 -> V_360 . V_361 ) {
case V_362 :
case V_363 :
if ( F_59 ( V_16 , V_388 ,
V_186 -> V_360 . V_22 -> V_65 ) )
goto V_75;
}
F_111 ( V_16 , V_130 ) ;
return 0 ;
V_75:
return - 1 ;
}
static int F_257 ( const struct V_13 * V_14 ,
struct V_331 * V_186 , unsigned int V_32 ,
struct V_328 * V_225 , const struct V_23 * V_24 )
{
unsigned int V_95 ;
V_95 = F_53 ( V_24 ) ;
if ( V_95 == 0 )
return - V_66 ;
if ( V_95 > V_32 )
return - V_168 ;
F_165 ( V_186 -> V_186 , V_24 , V_95 ) ;
V_225 -> type = V_272 ;
V_225 -> V_95 = V_95 ;
return 0 ;
}
static int F_258 ( struct V_15 * V_16 , const struct V_331 * V_186 ,
unsigned int V_95 )
{
return F_154 ( V_16 , V_390 , V_95 , V_186 -> V_186 ) ;
}
int F_227 ( const struct V_13 * V_14 ,
struct V_331 * V_186 , unsigned int V_32 ,
struct V_328 * V_225 , const struct V_23 * V_24 )
{
struct V_23 * V_154 [ V_391 + 1 ] ;
int V_45 ;
V_45 = F_117 ( V_154 , V_391 , V_24 , V_392 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_154 [ V_390 ] )
return F_257 ( V_14 , V_186 , V_32 , V_225 ,
V_154 [ V_390 ] ) ;
if ( V_154 [ V_389 ] && V_14 != NULL )
return F_254 ( V_14 , V_186 , V_225 , V_154 [ V_389 ] ) ;
return - V_66 ;
}
void F_223 ( const struct V_331 * V_186 , enum V_376 type )
{
if ( type < V_277 )
return;
switch ( type ) {
case V_277 :
return F_255 ( V_186 ) ;
default:
F_259 ( 1 ) ;
}
}
int F_200 ( struct V_15 * V_16 , int V_153 , const struct V_331 * V_186 ,
enum V_376 type , unsigned int V_95 )
{
struct V_23 * V_130 ;
int V_45 ;
V_130 = F_108 ( V_16 , V_153 ) ;
if ( V_130 == NULL )
return - 1 ;
switch ( type ) {
case V_272 :
V_45 = F_258 ( V_16 , V_186 , V_95 ) ;
break;
case V_277 :
V_45 = F_256 ( V_16 , V_186 ) ;
break;
default:
V_45 = - V_66 ;
F_259 ( 1 ) ;
}
F_111 ( V_16 , V_130 ) ;
return V_45 ;
}
static int F_260 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_7 . V_8 ) ;
F_2 ( & V_1 -> V_7 . V_44 ) ;
V_1 -> V_7 . V_80 = 1 ;
return 0 ;
}
static int T_8 F_261 ( void )
{
int V_45 ;
V_189 = F_184 ( sizeof( struct V_188 ) * V_218 ,
V_34 ) ;
if ( V_189 == NULL ) {
V_45 = - V_41 ;
goto V_111;
}
V_45 = F_262 () ;
if ( V_45 < 0 )
goto V_115;
V_45 = F_263 ( & V_393 ) ;
if ( V_45 < 0 )
goto V_221;
F_264 ( L_6 ) ;
return F_265 ( & V_394 ) ;
V_221:
F_266 () ;
V_115:
F_22 ( V_189 ) ;
V_111:
return V_45 ;
}
static void T_9 F_267 ( void )
{
F_268 ( & V_394 ) ;
F_269 ( & V_393 ) ;
F_270 () ;
F_266 () ;
F_22 ( V_189 ) ;
}
