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
int F_23 ( struct V_35 * V_36 ,
unsigned int V_37 )
{
struct V_1 * V_1 = F_24 ( & V_36 -> V_38 ) ;
if ( V_36 -> V_39 & V_40 )
return 0 ;
return F_25 ( V_1 , V_36 -> V_41 , V_37 ) ;
}
void F_26 ( struct V_35 * V_36 ,
unsigned int V_37 )
{
struct V_1 * V_1 = F_24 ( & V_36 -> V_38 ) ;
if ( V_36 -> V_39 & V_40 )
return;
F_27 ( V_1 , V_36 -> V_41 , V_37 ) ;
}
static int F_28 ( const struct V_19 * V_20 ,
struct V_21 * V_22 ,
unsigned int V_37 )
{
if ( V_20 -> V_39 & V_42 ||
! ( V_22 -> V_39 & V_43 ) )
return 0 ;
return F_23 ( V_35 ( V_22 ) , V_37 ) ;
}
static void F_29 ( const struct V_19 * V_20 ,
struct V_21 * V_22 ,
unsigned int V_37 )
{
if ( V_20 -> V_39 & V_42 ||
! ( V_22 -> V_39 & V_43 ) )
return;
F_26 ( V_35 ( V_22 ) , V_37 ) ;
}
static int F_30 ( struct V_13 * V_14 , int V_31 )
{
struct V_30 * V_33 ;
V_33 = F_18 ( V_14 , V_31 , sizeof( struct V_44 ) ) ;
if ( V_33 == NULL )
return - V_45 ;
if ( V_31 == V_46 )
V_14 -> V_20 -> V_39 |= V_47 ;
F_31 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_48 ) ;
return 0 ;
}
static int F_32 ( struct V_13 * V_14 )
{
int V_49 ;
V_49 = F_30 ( V_14 , V_50 ) ;
if ( V_49 < 0 )
return V_49 ;
F_7 ( & V_14 -> V_20 -> V_6 ) ;
return V_49 ;
}
static int F_33 ( struct V_13 * V_14 , int V_31 )
{
struct V_30 * V_33 ;
V_33 = F_18 ( V_14 , V_31 , sizeof( struct V_51 ) ) ;
if ( V_33 == NULL )
return - V_45 ;
if ( V_31 == V_52 )
V_14 -> V_22 -> V_39 |= V_53 ;
F_31 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_48 ) ;
return 0 ;
}
static int F_34 ( struct V_13 * V_14 )
{
int V_49 ;
V_49 = F_33 ( V_14 , V_54 ) ;
if ( V_49 < 0 )
return V_49 ;
V_14 -> V_20 -> V_55 -- ;
F_7 ( & V_14 -> V_22 -> V_6 ) ;
return V_49 ;
}
static inline bool
F_35 ( struct V_1 * V_1 , const struct V_56 * V_57 )
{
return ( V_57 -> V_58 & F_36 ( V_1 ) ) == 0 ;
}
static inline int
F_37 ( struct V_1 * V_1 , const struct V_56 * V_57 )
{
return ( V_57 -> V_58 & F_38 ( V_1 ) ) == 0 ;
}
static inline void
F_39 ( struct V_1 * V_1 , struct V_56 * V_57 )
{
V_57 -> V_58 = F_36 ( V_1 ) ;
}
static inline void
F_40 ( struct V_1 * V_1 , struct V_56 * V_57 )
{
V_57 -> V_58 = F_38 ( V_1 ) ;
}
static inline void F_41 ( struct V_1 * V_1 , struct V_56 * V_57 )
{
V_57 -> V_58 &= ~ F_38 ( V_1 ) ;
}
static int
F_42 ( struct V_13 * V_14 , struct V_56 * V_57 )
{
if ( F_37 ( V_14 -> V_1 , V_57 ) ) {
F_40 ( V_14 -> V_1 , V_57 ) ;
V_14 -> V_22 -> V_55 -- ;
return 0 ;
}
return - V_59 ;
}
static struct V_30 * F_43 ( struct V_13 * V_14 , int V_31 ,
struct V_56 * V_57 )
{
struct V_30 * V_33 ;
V_33 = F_18 ( V_14 , V_31 , sizeof( struct V_60 ) ) ;
if ( V_33 == NULL )
return NULL ;
V_60 ( V_33 ) = V_57 ;
F_31 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_48 ) ;
return V_33 ;
}
static int F_44 ( struct V_13 * V_14 , struct V_56 * V_57 )
{
struct V_30 * V_33 ;
int V_49 ;
V_33 = F_43 ( V_14 , V_61 , V_57 ) ;
if ( V_33 == NULL )
return - V_45 ;
V_49 = F_42 ( V_14 , V_57 ) ;
if ( V_49 < 0 ) {
F_20 ( V_33 ) ;
return V_49 ;
}
return 0 ;
}
static int F_45 ( struct V_13 * V_14 )
{
struct V_56 * V_57 ;
int V_49 ;
F_9 (rule, &ctx->chain->rules, list) {
V_49 = F_44 ( V_14 , V_57 ) ;
if ( V_49 < 0 )
return V_49 ;
}
return 0 ;
}
static int F_46 ( struct V_13 * V_14 , int V_31 ,
struct V_62 * V_63 )
{
struct V_30 * V_33 ;
V_33 = F_18 ( V_14 , V_31 , sizeof( struct V_64 ) ) ;
if ( V_33 == NULL )
return - V_45 ;
if ( V_31 == V_65 && V_14 -> V_24 [ V_66 ] != NULL ) {
F_47 ( V_33 ) =
F_48 ( F_49 ( V_14 -> V_24 [ V_66 ] ) ) ;
V_63 -> V_39 |= V_67 ;
}
V_64 ( V_33 ) = V_63 ;
F_31 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_48 ) ;
return 0 ;
}
static int F_50 ( struct V_13 * V_14 , struct V_62 * V_63 )
{
int V_49 ;
V_49 = F_46 ( V_14 , V_68 , V_63 ) ;
if ( V_49 < 0 )
return V_49 ;
F_7 ( & V_63 -> V_6 ) ;
V_14 -> V_20 -> V_55 -- ;
return V_49 ;
}
static struct V_19 * F_51 ( const struct V_2 * V_3 ,
const struct V_23 * V_24 )
{
struct V_19 * V_20 ;
F_9 (table, &afi->tables, list) {
if ( ! F_52 ( V_24 , V_20 -> V_69 ) )
return V_20 ;
}
return NULL ;
}
static struct V_19 * F_53 ( const struct V_2 * V_3 ,
const struct V_23 * V_24 )
{
struct V_19 * V_20 ;
if ( V_24 == NULL )
return F_13 ( - V_70 ) ;
V_20 = F_51 ( V_3 , V_24 ) ;
if ( V_20 != NULL )
return V_20 ;
return F_13 ( - V_59 ) ;
}
static inline T_2 F_54 ( struct V_19 * V_20 )
{
return ++ V_20 -> V_71 ;
}
static const struct V_72 *
F_55 ( int V_9 , const struct V_23 * V_24 )
{
int V_73 ;
for ( V_73 = 0 ; V_73 < V_74 ; V_73 ++ ) {
if ( V_75 [ V_9 ] [ V_73 ] != NULL &&
! F_52 ( V_24 , V_75 [ V_9 ] [ V_73 ] -> V_69 ) )
return V_75 [ V_9 ] [ V_73 ] ;
}
return NULL ;
}
static const struct V_72 *
F_56 ( const struct V_2 * V_3 ,
const struct V_23 * V_24 ,
bool V_10 )
{
const struct V_72 * type ;
type = F_55 ( V_3 -> V_9 , V_24 ) ;
if ( type != NULL )
return type ;
#ifdef F_11
if ( V_10 ) {
F_5 ( V_5 ) ;
F_12 ( L_2 , V_3 -> V_9 ,
F_57 ( V_24 ) , ( const char * ) F_58 ( V_24 ) ) ;
F_3 ( V_5 ) ;
type = F_55 ( V_3 -> V_9 , V_24 ) ;
if ( type != NULL )
return F_13 ( - V_11 ) ;
}
#endif
return F_13 ( - V_59 ) ;
}
static int F_59 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_26 , T_1 V_28 , int V_76 , T_1 V_39 ,
int V_9 , const struct V_19 * V_20 )
{
struct V_17 * V_18 ;
struct V_77 * V_78 ;
V_76 |= V_5 << 8 ;
V_18 = F_60 ( V_16 , V_26 , V_28 , V_76 , sizeof( struct V_77 ) , V_39 ) ;
if ( V_18 == NULL )
goto V_79;
V_78 = F_61 ( V_18 ) ;
V_78 -> V_80 = V_9 ;
V_78 -> V_81 = V_82 ;
V_78 -> V_83 = F_62 ( V_1 -> V_7 . V_84 & 0xffff ) ;
if ( F_63 ( V_16 , V_85 , V_20 -> V_69 ) ||
F_64 ( V_16 , V_86 , F_65 ( V_20 -> V_39 ) ) ||
F_64 ( V_16 , V_87 , F_65 ( V_20 -> V_55 ) ) )
goto V_79;
F_66 ( V_16 , V_18 ) ;
return 0 ;
V_79:
F_67 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_68 ( const struct V_13 * V_14 , int V_76 )
{
struct V_15 * V_16 ;
int V_49 ;
if ( ! V_14 -> V_27 &&
! F_69 ( V_14 -> V_1 , V_88 ) )
return 0 ;
V_49 = - V_89 ;
V_16 = F_70 ( V_90 , V_34 ) ;
if ( V_16 == NULL )
goto V_49;
V_49 = F_59 ( V_16 , V_14 -> V_1 , V_14 -> V_26 , V_14 -> V_28 ,
V_76 , 0 , V_14 -> V_3 -> V_9 , V_14 -> V_20 ) ;
if ( V_49 < 0 ) {
F_71 ( V_16 ) ;
goto V_49;
}
V_49 = F_72 ( V_16 , V_14 -> V_1 , V_14 -> V_26 , V_88 ,
V_14 -> V_27 , V_34 ) ;
V_49:
if ( V_49 < 0 ) {
F_73 ( V_14 -> V_1 , V_14 -> V_26 , V_88 ,
V_49 ) ;
}
return V_49 ;
}
static int F_74 ( struct V_15 * V_16 ,
struct V_91 * V_92 )
{
const struct V_77 * V_78 = F_61 ( V_92 -> V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
unsigned int V_93 = 0 , V_94 = V_92 -> args [ 0 ] ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_78 -> V_80 ;
F_75 () ;
V_92 -> V_28 = V_1 -> V_7 . V_84 ;
F_76 (afi, &net->nft.af_info, list) {
if ( V_9 != V_95 && V_9 != V_3 -> V_9 )
continue;
F_76 (table, &afi->tables, list) {
if ( V_93 < V_94 )
goto V_96;
if ( V_93 > V_94 )
memset ( & V_92 -> args [ 1 ] , 0 ,
sizeof( V_92 -> args ) - sizeof( V_92 -> args [ 0 ] ) ) ;
if ( F_59 ( V_16 , V_1 ,
F_16 ( V_92 -> V_16 ) . V_26 ,
V_92 -> V_18 -> V_29 ,
V_46 ,
V_97 ,
V_3 -> V_9 , V_20 ) < 0 )
goto V_98;
F_77 ( V_92 , F_78 ( V_16 ) ) ;
V_96:
V_93 ++ ;
}
}
V_98:
F_79 () ;
V_92 -> args [ 0 ] = V_93 ;
return V_16 -> V_99 ;
}
static int F_80 ( struct V_100 * V_101 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_77 * V_78 = F_61 ( V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
struct V_15 * V_102 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_78 -> V_80 ;
int V_49 ;
if ( V_18 -> V_103 & V_104 ) {
struct V_105 V_106 = {
. V_107 = F_74 ,
} ;
return F_81 ( V_101 , V_16 , V_18 , & V_106 ) ;
}
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_82 ( V_3 ) )
return F_83 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_85 ] ) ;
if ( F_82 ( V_20 ) )
return F_83 ( V_20 ) ;
if ( V_20 -> V_39 & V_47 )
return - V_59 ;
V_102 = F_84 ( V_90 , V_34 ) ;
if ( ! V_102 )
return - V_45 ;
V_49 = F_59 ( V_102 , V_1 , F_16 ( V_16 ) . V_26 ,
V_18 -> V_29 , V_46 , 0 ,
V_9 , V_20 ) ;
if ( V_49 < 0 )
goto V_49;
return F_85 ( V_101 , V_102 , F_16 ( V_16 ) . V_26 ) ;
V_49:
F_71 ( V_102 ) ;
return V_49 ;
}
static int F_86 ( const struct V_2 * V_3 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 ;
int V_49 , V_73 = 0 ;
F_9 (chain, &table->chains, list) {
if ( ! ( V_22 -> V_39 & V_43 ) )
continue;
V_49 = F_23 ( V_35 ( V_22 ) , V_3 -> V_108 ) ;
if ( V_49 < 0 )
goto V_49;
V_73 ++ ;
}
return 0 ;
V_49:
F_9 (chain, &table->chains, list) {
if ( ! ( V_22 -> V_39 & V_43 ) )
continue;
if ( V_73 -- <= 0 )
break;
F_26 ( V_35 ( V_22 ) , V_3 -> V_108 ) ;
}
return V_49 ;
}
static void F_87 ( const struct V_2 * V_3 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 ;
F_9 (chain, &table->chains, list) {
if ( V_22 -> V_39 & V_43 )
F_26 ( V_35 ( V_22 ) ,
V_3 -> V_108 ) ;
}
}
static int F_88 ( struct V_13 * V_14 )
{
struct V_30 * V_33 ;
T_1 V_39 ;
int V_109 = 0 ;
if ( ! V_14 -> V_24 [ V_86 ] )
return 0 ;
V_39 = F_48 ( F_49 ( V_14 -> V_24 [ V_86 ] ) ) ;
if ( V_39 & ~ V_42 )
return - V_70 ;
if ( V_39 == V_14 -> V_20 -> V_39 )
return 0 ;
V_33 = F_18 ( V_14 , V_46 ,
sizeof( struct V_44 ) ) ;
if ( V_33 == NULL )
return - V_45 ;
if ( ( V_39 & V_42 ) &&
! ( V_14 -> V_20 -> V_39 & V_42 ) ) {
F_89 ( V_33 ) = false ;
} else if ( ! ( V_39 & V_42 ) &&
V_14 -> V_20 -> V_39 & V_42 ) {
V_109 = F_86 ( V_14 -> V_3 , V_14 -> V_20 ) ;
if ( V_109 >= 0 ) {
V_14 -> V_20 -> V_39 &= ~ V_42 ;
F_89 ( V_33 ) = true ;
}
}
if ( V_109 < 0 )
goto V_49;
F_90 ( V_33 ) = true ;
F_31 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_48 ) ;
return 0 ;
V_49:
F_20 ( V_33 ) ;
return V_109 ;
}
static int F_91 ( struct V_100 * V_101 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_77 * V_78 = F_61 ( V_18 ) ;
const struct V_23 * V_69 ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_78 -> V_80 ;
T_1 V_39 = 0 ;
struct V_13 V_14 ;
int V_49 ;
V_3 = F_10 ( V_1 , V_9 , true ) ;
if ( F_82 ( V_3 ) )
return F_83 ( V_3 ) ;
V_69 = V_24 [ V_85 ] ;
V_20 = F_53 ( V_3 , V_69 ) ;
if ( F_82 ( V_20 ) ) {
if ( F_83 ( V_20 ) != - V_59 )
return F_83 ( V_20 ) ;
V_20 = NULL ;
}
if ( V_20 != NULL ) {
if ( V_20 -> V_39 & V_47 )
return - V_59 ;
if ( V_18 -> V_103 & V_110 )
return - V_111 ;
if ( V_18 -> V_103 & V_112 )
return - V_113 ;
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return F_88 ( & V_14 ) ;
}
if ( V_24 [ V_86 ] ) {
V_39 = F_48 ( F_49 ( V_24 [ V_86 ] ) ) ;
if ( V_39 & ~ V_42 )
return - V_70 ;
}
V_49 = - V_12 ;
if ( ! F_92 ( V_3 -> V_114 ) )
goto V_115;
V_49 = - V_45 ;
V_20 = F_19 ( sizeof( * V_20 ) , V_34 ) ;
if ( V_20 == NULL )
goto V_116;
F_93 ( V_20 -> V_69 , V_69 , V_117 ) ;
F_2 ( & V_20 -> V_118 ) ;
F_2 ( & V_20 -> V_119 ) ;
V_20 -> V_39 = V_39 ;
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
V_49 = F_30 ( & V_14 , V_46 ) ;
if ( V_49 < 0 )
goto V_120;
F_4 ( & V_20 -> V_6 , & V_3 -> V_4 ) ;
return 0 ;
V_120:
F_22 ( V_20 ) ;
V_116:
F_94 ( V_3 -> V_114 ) ;
V_115:
return V_49 ;
}
static int F_95 ( struct V_13 * V_14 )
{
int V_49 ;
struct V_21 * V_22 , * V_121 ;
struct V_62 * V_63 , * V_122 ;
F_9 (chain, &ctx->table->chains, list) {
V_14 -> V_22 = V_22 ;
V_49 = F_45 ( V_14 ) ;
if ( V_49 < 0 )
goto V_123;
}
F_96 (set, ns, &ctx->table->sets, list) {
if ( V_63 -> V_39 & V_124 &&
! F_97 ( & V_63 -> V_125 ) )
continue;
V_49 = F_50 ( V_14 , V_63 ) ;
if ( V_49 < 0 )
goto V_123;
}
F_96 (chain, nc, &ctx->table->chains, list) {
V_14 -> V_22 = V_22 ;
V_49 = F_34 ( V_14 ) ;
if ( V_49 < 0 )
goto V_123;
}
V_49 = F_32 ( V_14 ) ;
V_123:
return V_49 ;
}
static int F_98 ( struct V_13 * V_14 , int V_9 )
{
struct V_2 * V_3 ;
struct V_19 * V_20 , * V_126 ;
const struct V_23 * const * V_24 = V_14 -> V_24 ;
int V_49 = 0 ;
F_9 (afi, &ctx->net->nft.af_info, list) {
if ( V_9 != V_127 && V_3 -> V_9 != V_9 )
continue;
V_14 -> V_3 = V_3 ;
F_96 (table, nt, &afi->tables, list) {
if ( V_24 [ V_85 ] &&
F_52 ( V_24 [ V_85 ] , V_20 -> V_69 ) != 0 )
continue;
V_14 -> V_20 = V_20 ;
V_49 = F_95 ( V_14 ) ;
if ( V_49 < 0 )
goto V_123;
}
}
V_123:
return V_49 ;
}
static int F_99 ( struct V_100 * V_101 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_77 * V_78 = F_61 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_78 -> V_80 ;
struct V_13 V_14 ;
F_14 ( & V_14 , V_16 , V_18 , NULL , NULL , NULL , V_24 ) ;
if ( V_9 == V_127 || V_24 [ V_85 ] == NULL )
return F_98 ( & V_14 , V_9 ) ;
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_82 ( V_3 ) )
return F_83 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_85 ] ) ;
if ( F_82 ( V_20 ) )
return F_83 ( V_20 ) ;
if ( V_20 -> V_39 & V_47 )
return - V_59 ;
V_14 . V_3 = V_3 ;
V_14 . V_20 = V_20 ;
return F_95 ( & V_14 ) ;
}
static void F_100 ( struct V_13 * V_14 )
{
F_101 ( V_14 -> V_20 -> V_55 > 0 ) ;
F_22 ( V_14 -> V_20 ) ;
F_94 ( V_14 -> V_3 -> V_114 ) ;
}
int F_102 ( const struct V_72 * V_128 )
{
int V_49 = 0 ;
F_3 ( V_5 ) ;
if ( V_75 [ V_128 -> V_9 ] [ V_128 -> type ] != NULL ) {
V_49 = - V_129 ;
goto V_123;
}
V_75 [ V_128 -> V_9 ] [ V_128 -> type ] = V_128 ;
V_123:
F_5 ( V_5 ) ;
return V_49 ;
}
void F_103 ( const struct V_72 * V_128 )
{
F_3 ( V_5 ) ;
V_75 [ V_128 -> V_9 ] [ V_128 -> type ] = NULL ;
F_5 ( V_5 ) ;
}
static struct V_21 *
F_104 ( const struct V_19 * V_20 , T_2 V_130 )
{
struct V_21 * V_22 ;
F_9 (chain, &table->chains, list) {
if ( V_22 -> V_130 == V_130 )
return V_22 ;
}
return F_13 ( - V_59 ) ;
}
static struct V_21 * F_105 ( const struct V_19 * V_20 ,
const struct V_23 * V_24 )
{
struct V_21 * V_22 ;
if ( V_24 == NULL )
return F_13 ( - V_70 ) ;
F_9 (chain, &table->chains, list) {
if ( ! F_52 ( V_24 , V_22 -> V_69 ) )
return V_22 ;
}
return F_13 ( - V_59 ) ;
}
static int F_106 ( struct V_15 * V_16 , struct V_131 T_3 * V_132 )
{
struct V_131 * V_133 , V_134 ;
struct V_23 * V_135 ;
unsigned int V_28 ;
T_2 V_136 , V_137 ;
int V_138 ;
memset ( & V_134 , 0 , sizeof( V_134 ) ) ;
F_107 (cpu) {
V_133 = F_108 ( V_132 , V_138 ) ;
do {
V_28 = F_109 ( & V_133 -> V_139 ) ;
V_136 = V_133 -> V_136 ;
V_137 = V_133 -> V_137 ;
} while ( F_110 ( & V_133 -> V_139 , V_28 ) );
V_134 . V_136 += V_136 ;
V_134 . V_137 += V_137 ;
}
V_135 = F_111 ( V_16 , V_140 ) ;
if ( V_135 == NULL )
goto V_79;
if ( F_112 ( V_16 , V_141 , F_113 ( V_134 . V_136 ) ) ||
F_112 ( V_16 , V_142 , F_113 ( V_134 . V_137 ) ) )
goto V_79;
F_114 ( V_16 , V_135 ) ;
return 0 ;
V_79:
return - V_143 ;
}
static int F_115 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_26 , T_1 V_28 , int V_76 , T_1 V_39 ,
int V_9 , const struct V_19 * V_20 ,
const struct V_21 * V_22 )
{
struct V_17 * V_18 ;
struct V_77 * V_78 ;
V_76 |= V_5 << 8 ;
V_18 = F_60 ( V_16 , V_26 , V_28 , V_76 , sizeof( struct V_77 ) , V_39 ) ;
if ( V_18 == NULL )
goto V_79;
V_78 = F_61 ( V_18 ) ;
V_78 -> V_80 = V_9 ;
V_78 -> V_81 = V_82 ;
V_78 -> V_83 = F_62 ( V_1 -> V_7 . V_84 & 0xffff ) ;
if ( F_63 ( V_16 , V_144 , V_20 -> V_69 ) )
goto V_79;
if ( F_112 ( V_16 , V_145 , F_113 ( V_22 -> V_130 ) ) )
goto V_79;
if ( F_63 ( V_16 , V_146 , V_22 -> V_69 ) )
goto V_79;
if ( V_22 -> V_39 & V_43 ) {
const struct V_35 * V_36 = V_35 ( V_22 ) ;
const struct V_147 * V_41 = & V_36 -> V_41 [ 0 ] ;
struct V_23 * V_135 ;
V_135 = F_111 ( V_16 , V_148 ) ;
if ( V_135 == NULL )
goto V_79;
if ( F_64 ( V_16 , V_149 , F_65 ( V_41 -> V_150 ) ) )
goto V_79;
if ( F_64 ( V_16 , V_151 , F_65 ( V_41 -> V_152 ) ) )
goto V_79;
if ( V_36 -> V_153 [ 0 ] &&
F_63 ( V_16 , V_154 , V_36 -> V_153 ) )
goto V_79;
F_114 ( V_16 , V_135 ) ;
if ( F_64 ( V_16 , V_155 ,
F_65 ( V_36 -> V_156 ) ) )
goto V_79;
if ( F_63 ( V_16 , V_157 , V_36 -> type -> V_69 ) )
goto V_79;
if ( F_106 ( V_16 , V_35 ( V_22 ) -> V_132 ) )
goto V_79;
}
if ( F_64 ( V_16 , V_158 , F_65 ( V_22 -> V_55 ) ) )
goto V_79;
F_66 ( V_16 , V_18 ) ;
return 0 ;
V_79:
F_67 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_116 ( const struct V_13 * V_14 , int V_76 )
{
struct V_15 * V_16 ;
int V_49 ;
if ( ! V_14 -> V_27 &&
! F_69 ( V_14 -> V_1 , V_88 ) )
return 0 ;
V_49 = - V_89 ;
V_16 = F_70 ( V_90 , V_34 ) ;
if ( V_16 == NULL )
goto V_49;
V_49 = F_115 ( V_16 , V_14 -> V_1 , V_14 -> V_26 , V_14 -> V_28 ,
V_76 , 0 , V_14 -> V_3 -> V_9 , V_14 -> V_20 ,
V_14 -> V_22 ) ;
if ( V_49 < 0 ) {
F_71 ( V_16 ) ;
goto V_49;
}
V_49 = F_72 ( V_16 , V_14 -> V_1 , V_14 -> V_26 , V_88 ,
V_14 -> V_27 , V_34 ) ;
V_49:
if ( V_49 < 0 ) {
F_73 ( V_14 -> V_1 , V_14 -> V_26 , V_88 ,
V_49 ) ;
}
return V_49 ;
}
static int F_117 ( struct V_15 * V_16 ,
struct V_91 * V_92 )
{
const struct V_77 * V_78 = F_61 ( V_92 -> V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
unsigned int V_93 = 0 , V_94 = V_92 -> args [ 0 ] ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_78 -> V_80 ;
F_75 () ;
V_92 -> V_28 = V_1 -> V_7 . V_84 ;
F_76 (afi, &net->nft.af_info, list) {
if ( V_9 != V_95 && V_9 != V_3 -> V_9 )
continue;
F_76 (table, &afi->tables, list) {
F_76 (chain, &table->chains, list) {
if ( V_93 < V_94 )
goto V_96;
if ( V_93 > V_94 )
memset ( & V_92 -> args [ 1 ] , 0 ,
sizeof( V_92 -> args ) - sizeof( V_92 -> args [ 0 ] ) ) ;
if ( F_115 ( V_16 , V_1 ,
F_16 ( V_92 -> V_16 ) . V_26 ,
V_92 -> V_18 -> V_29 ,
V_52 ,
V_97 ,
V_3 -> V_9 , V_20 , V_22 ) < 0 )
goto V_98;
F_77 ( V_92 , F_78 ( V_16 ) ) ;
V_96:
V_93 ++ ;
}
}
}
V_98:
F_79 () ;
V_92 -> args [ 0 ] = V_93 ;
return V_16 -> V_99 ;
}
static int F_118 ( struct V_100 * V_101 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_77 * V_78 = F_61 ( V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
struct V_15 * V_102 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_78 -> V_80 ;
int V_49 ;
if ( V_18 -> V_103 & V_104 ) {
struct V_105 V_106 = {
. V_107 = F_117 ,
} ;
return F_81 ( V_101 , V_16 , V_18 , & V_106 ) ;
}
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_82 ( V_3 ) )
return F_83 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_144 ] ) ;
if ( F_82 ( V_20 ) )
return F_83 ( V_20 ) ;
if ( V_20 -> V_39 & V_47 )
return - V_59 ;
V_22 = F_105 ( V_20 , V_24 [ V_146 ] ) ;
if ( F_82 ( V_22 ) )
return F_83 ( V_22 ) ;
if ( V_22 -> V_39 & V_53 )
return - V_59 ;
V_102 = F_84 ( V_90 , V_34 ) ;
if ( ! V_102 )
return - V_45 ;
V_49 = F_115 ( V_102 , V_1 , F_16 ( V_16 ) . V_26 ,
V_18 -> V_29 , V_52 , 0 ,
V_9 , V_20 , V_22 ) ;
if ( V_49 < 0 )
goto V_49;
return F_85 ( V_101 , V_102 , F_16 ( V_16 ) . V_26 ) ;
V_49:
F_71 ( V_102 ) ;
return V_49 ;
}
static struct V_131 T_3 * F_119 ( const struct V_23 * V_159 )
{
struct V_23 * V_160 [ V_161 + 1 ] ;
struct V_131 T_3 * V_162 ;
struct V_131 * V_132 ;
int V_49 ;
V_49 = F_120 ( V_160 , V_161 , V_159 , V_163 ) ;
if ( V_49 < 0 )
return F_13 ( V_49 ) ;
if ( ! V_160 [ V_142 ] || ! V_160 [ V_141 ] )
return F_13 ( - V_70 ) ;
V_162 = F_121 ( struct V_131 ) ;
if ( V_162 == NULL )
return F_13 ( - V_45 ) ;
F_122 () ;
V_132 = F_123 ( V_162 ) ;
V_132 -> V_137 = F_124 ( F_125 ( V_160 [ V_142 ] ) ) ;
V_132 -> V_136 = F_124 ( F_125 ( V_160 [ V_141 ] ) ) ;
F_126 () ;
return V_162 ;
}
static void F_127 ( struct V_35 * V_22 ,
struct V_131 T_3 * V_162 )
{
if ( V_162 == NULL )
return;
if ( V_22 -> V_132 ) {
struct V_131 T_3 * V_164 =
F_128 ( V_22 -> V_132 ) ;
F_129 ( V_22 -> V_132 , V_162 ) ;
F_130 () ;
F_131 ( V_164 ) ;
} else
F_129 ( V_22 -> V_132 , V_162 ) ;
}
static void F_132 ( struct V_21 * V_22 )
{
F_101 ( V_22 -> V_55 > 0 ) ;
if ( V_22 -> V_39 & V_43 ) {
struct V_35 * V_36 = V_35 ( V_22 ) ;
F_94 ( V_36 -> type -> V_114 ) ;
F_131 ( V_36 -> V_132 ) ;
if ( V_36 -> V_41 [ 0 ] . V_165 != NULL )
F_133 ( V_36 -> V_41 [ 0 ] . V_165 ) ;
F_22 ( V_36 ) ;
} else {
F_22 ( V_22 ) ;
}
}
static int F_134 ( struct V_100 * V_101 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_77 * V_78 = F_61 ( V_18 ) ;
const struct V_23 * V_166 ( V_69 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_35 * V_36 = NULL ;
struct V_23 * V_167 [ V_168 + 1 ] ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_78 -> V_80 ;
struct V_169 * V_165 = NULL ;
T_4 V_156 = V_170 ;
T_2 V_130 = 0 ;
unsigned int V_73 ;
struct V_131 T_3 * V_132 ;
int V_49 ;
bool V_171 ;
struct V_13 V_14 ;
V_171 = V_18 -> V_103 & V_172 ? true : false ;
V_3 = F_10 ( V_1 , V_9 , true ) ;
if ( F_82 ( V_3 ) )
return F_83 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_144 ] ) ;
if ( F_82 ( V_20 ) )
return F_83 ( V_20 ) ;
V_22 = NULL ;
V_69 = V_24 [ V_146 ] ;
if ( V_24 [ V_145 ] ) {
V_130 = F_124 ( F_125 ( V_24 [ V_145 ] ) ) ;
V_22 = F_104 ( V_20 , V_130 ) ;
if ( F_82 ( V_22 ) )
return F_83 ( V_22 ) ;
} else {
V_22 = F_105 ( V_20 , V_69 ) ;
if ( F_82 ( V_22 ) ) {
if ( F_83 ( V_22 ) != - V_59 )
return F_83 ( V_22 ) ;
V_22 = NULL ;
}
}
if ( V_24 [ V_155 ] ) {
if ( ( V_22 != NULL &&
! ( V_22 -> V_39 & V_43 ) ) )
return - V_113 ;
if ( V_22 == NULL &&
V_24 [ V_148 ] == NULL )
return - V_113 ;
V_156 = F_48 ( F_49 ( V_24 [ V_155 ] ) ) ;
switch ( V_156 ) {
case V_173 :
case V_170 :
break;
default:
return - V_70 ;
}
}
if ( V_22 != NULL ) {
struct V_131 * V_132 = NULL ;
struct V_30 * V_33 ;
if ( V_22 -> V_39 & V_53 )
return - V_59 ;
if ( V_18 -> V_103 & V_110 )
return - V_111 ;
if ( V_18 -> V_103 & V_112 )
return - V_113 ;
if ( V_24 [ V_145 ] && V_69 &&
! F_82 ( F_105 ( V_20 , V_24 [ V_146 ] ) ) )
return - V_111 ;
if ( V_24 [ V_140 ] ) {
if ( ! ( V_22 -> V_39 & V_43 ) )
return - V_113 ;
V_132 = F_119 ( V_24 [ V_140 ] ) ;
if ( F_82 ( V_132 ) )
return F_83 ( V_132 ) ;
}
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_33 = F_18 ( & V_14 , V_52 ,
sizeof( struct V_51 ) ) ;
if ( V_33 == NULL ) {
F_131 ( V_132 ) ;
return - V_45 ;
}
F_135 ( V_33 ) = V_132 ;
F_136 ( V_33 ) = true ;
if ( V_24 [ V_155 ] )
F_137 ( V_33 ) = V_156 ;
else
F_137 ( V_33 ) = - 1 ;
if ( V_24 [ V_145 ] && V_69 ) {
F_93 ( F_138 ( V_33 ) , V_69 ,
V_174 ) ;
}
F_31 ( & V_33 -> V_6 , & V_1 -> V_7 . V_48 ) ;
return 0 ;
}
if ( V_20 -> V_55 == V_175 )
return - V_176 ;
if ( V_24 [ V_148 ] ) {
const struct V_72 * type ;
struct V_147 * V_41 ;
T_5 * V_177 ;
T_1 V_150 , V_152 ;
type = V_75 [ V_9 ] [ V_178 ] ;
if ( V_24 [ V_157 ] ) {
type = F_56 ( V_3 ,
V_24 [ V_157 ] ,
V_171 ) ;
if ( F_82 ( type ) )
return F_83 ( type ) ;
}
V_49 = F_120 ( V_167 , V_168 , V_24 [ V_148 ] ,
V_179 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( V_167 [ V_149 ] == NULL ||
V_167 [ V_151 ] == NULL )
return - V_70 ;
V_150 = F_48 ( F_49 ( V_167 [ V_149 ] ) ) ;
if ( V_150 >= V_3 -> V_180 )
return - V_70 ;
V_152 = F_48 ( F_49 ( V_167 [ V_151 ] ) ) ;
if ( ! ( type -> V_181 & ( 1 << V_150 ) ) )
return - V_113 ;
if ( ! F_92 ( type -> V_114 ) )
return - V_59 ;
V_177 = type -> V_182 [ V_150 ] ;
if ( V_3 -> V_39 & V_183 ) {
char V_184 [ V_185 ] ;
if ( ! V_167 [ V_154 ] ) {
F_94 ( type -> V_114 ) ;
return - V_113 ;
}
F_93 ( V_184 , V_167 [ V_154 ] , V_185 ) ;
V_165 = F_139 ( V_1 , V_184 ) ;
if ( ! V_165 ) {
F_94 ( type -> V_114 ) ;
return - V_59 ;
}
} else if ( V_167 [ V_154 ] ) {
F_94 ( type -> V_114 ) ;
return - V_113 ;
}
V_36 = F_19 ( sizeof( * V_36 ) , V_34 ) ;
if ( V_36 == NULL ) {
F_94 ( type -> V_114 ) ;
if ( V_165 != NULL )
F_133 ( V_165 ) ;
return - V_45 ;
}
if ( V_165 != NULL )
strncpy ( V_36 -> V_153 , V_165 -> V_69 , V_185 ) ;
if ( V_24 [ V_140 ] ) {
V_132 = F_119 ( V_24 [ V_140 ] ) ;
if ( F_82 ( V_132 ) ) {
F_94 ( type -> V_114 ) ;
F_22 ( V_36 ) ;
if ( V_165 != NULL )
F_133 ( V_165 ) ;
return F_83 ( V_132 ) ;
}
V_36 -> V_132 = V_132 ;
} else {
V_132 = F_121 ( struct V_131 ) ;
if ( V_132 == NULL ) {
F_94 ( type -> V_114 ) ;
F_22 ( V_36 ) ;
if ( V_165 != NULL )
F_133 ( V_165 ) ;
return - V_45 ;
}
F_129 ( V_36 -> V_132 , V_132 ) ;
}
F_140 ( & V_36 -> V_38 , V_1 ) ;
V_36 -> type = type ;
V_22 = & V_36 -> V_22 ;
for ( V_73 = 0 ; V_73 < V_3 -> V_108 ; V_73 ++ ) {
V_41 = & V_36 -> V_41 [ V_73 ] ;
V_41 -> V_186 = V_9 ;
V_41 -> V_114 = V_3 -> V_114 ;
V_41 -> V_150 = V_150 ;
V_41 -> V_152 = V_152 ;
V_41 -> V_187 = V_22 ;
V_41 -> V_188 = V_3 -> V_182 [ V_41 -> V_150 ] ;
V_41 -> V_165 = V_165 ;
if ( V_177 )
V_41 -> V_188 = V_177 ;
if ( V_3 -> V_189 )
V_3 -> V_189 ( V_41 , V_73 ) ;
}
V_22 -> V_39 |= V_43 ;
V_36 -> V_156 = V_156 ;
} else {
V_22 = F_19 ( sizeof( * V_22 ) , V_34 ) ;
if ( V_22 == NULL )
return - V_45 ;
}
F_2 ( & V_22 -> V_190 ) ;
V_22 -> V_130 = F_54 ( V_20 ) ;
V_22 -> V_20 = V_20 ;
F_93 ( V_22 -> V_69 , V_69 , V_174 ) ;
V_49 = F_28 ( V_20 , V_22 , V_3 -> V_108 ) ;
if ( V_49 < 0 )
goto V_115;
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_49 = F_33 ( & V_14 , V_52 ) ;
if ( V_49 < 0 )
goto V_116;
V_20 -> V_55 ++ ;
F_4 ( & V_22 -> V_6 , & V_20 -> V_118 ) ;
return 0 ;
V_116:
F_29 ( V_20 , V_22 , V_3 -> V_108 ) ;
V_115:
F_132 ( V_22 ) ;
return V_49 ;
}
static int F_141 ( struct V_100 * V_101 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_77 * V_78 = F_61 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_78 -> V_80 ;
struct V_13 V_14 ;
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_82 ( V_3 ) )
return F_83 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_144 ] ) ;
if ( F_82 ( V_20 ) )
return F_83 ( V_20 ) ;
if ( V_20 -> V_39 & V_47 )
return - V_59 ;
V_22 = F_105 ( V_20 , V_24 [ V_146 ] ) ;
if ( F_82 ( V_22 ) )
return F_83 ( V_22 ) ;
if ( V_22 -> V_39 & V_53 )
return - V_59 ;
if ( V_22 -> V_55 > 0 )
return - V_129 ;
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
return F_34 ( & V_14 ) ;
}
int F_142 ( struct V_191 * type )
{
F_3 ( V_5 ) ;
if ( type -> V_9 == V_95 )
F_4 ( & type -> V_6 , & V_192 ) ;
else
F_143 ( & type -> V_6 , & V_192 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_144 ( struct V_191 * type )
{
F_3 ( V_5 ) ;
F_7 ( & type -> V_6 ) ;
F_5 ( V_5 ) ;
}
static const struct V_191 * F_145 ( T_4 V_9 ,
struct V_23 * V_24 )
{
const struct V_191 * type ;
F_9 (type, &nf_tables_expressions, list) {
if ( ! F_52 ( V_24 , type -> V_69 ) &&
( ! type -> V_9 || type -> V_9 == V_9 ) )
return type ;
}
return NULL ;
}
static const struct V_191 * F_146 ( T_4 V_9 ,
struct V_23 * V_24 )
{
const struct V_191 * type ;
if ( V_24 == NULL )
return F_13 ( - V_70 ) ;
type = F_145 ( V_9 , V_24 ) ;
if ( type != NULL && F_92 ( type -> V_114 ) )
return type ;
#ifdef F_11
if ( type == NULL ) {
F_5 ( V_5 ) ;
F_12 ( L_3 , V_9 ,
F_57 ( V_24 ) , ( char * ) F_58 ( V_24 ) ) ;
F_3 ( V_5 ) ;
if ( F_145 ( V_9 , V_24 ) )
return F_13 ( - V_11 ) ;
F_5 ( V_5 ) ;
F_12 ( L_4 ,
F_57 ( V_24 ) , ( char * ) F_58 ( V_24 ) ) ;
F_3 ( V_5 ) ;
if ( F_145 ( V_9 , V_24 ) )
return F_13 ( - V_11 ) ;
}
#endif
return F_13 ( - V_59 ) ;
}
static int F_147 ( struct V_15 * V_16 ,
const struct V_193 * V_194 )
{
if ( F_63 ( V_16 , V_195 , V_194 -> V_41 -> type -> V_69 ) )
goto V_79;
if ( V_194 -> V_41 -> V_107 ) {
struct V_23 * V_196 = F_111 ( V_16 , V_197 ) ;
if ( V_196 == NULL )
goto V_79;
if ( V_194 -> V_41 -> V_107 ( V_16 , V_194 ) < 0 )
goto V_79;
F_114 ( V_16 , V_196 ) ;
}
return V_16 -> V_99 ;
V_79:
return - 1 ;
}
int F_148 ( struct V_15 * V_16 , unsigned int V_159 ,
const struct V_193 * V_194 )
{
struct V_23 * V_135 ;
V_135 = F_111 ( V_16 , V_159 ) ;
if ( ! V_135 )
goto V_79;
if ( F_147 ( V_16 , V_194 ) < 0 )
goto V_79;
F_114 ( V_16 , V_135 ) ;
return 0 ;
V_79:
return - 1 ;
}
static int F_149 ( const struct V_13 * V_14 ,
const struct V_23 * V_24 ,
struct V_198 * V_199 )
{
const struct V_191 * type ;
const struct V_200 * V_41 ;
struct V_23 * V_160 [ V_201 + 1 ] ;
int V_49 ;
V_49 = F_120 ( V_160 , V_201 , V_24 , V_202 ) ;
if ( V_49 < 0 )
return V_49 ;
type = F_146 ( V_14 -> V_3 -> V_9 , V_160 [ V_195 ] ) ;
if ( F_82 ( type ) )
return F_83 ( type ) ;
if ( V_160 [ V_197 ] ) {
V_49 = F_120 ( V_199 -> V_160 , type -> V_203 ,
V_160 [ V_197 ] , type -> V_156 ) ;
if ( V_49 < 0 )
goto V_115;
} else
memset ( V_199 -> V_160 , 0 , sizeof( V_199 -> V_160 [ 0 ] ) * ( type -> V_203 + 1 ) ) ;
if ( type -> V_204 != NULL ) {
V_41 = type -> V_204 ( V_14 ,
( const struct V_23 * const * ) V_199 -> V_160 ) ;
if ( F_82 ( V_41 ) ) {
V_49 = F_83 ( V_41 ) ;
goto V_115;
}
} else
V_41 = type -> V_41 ;
V_199 -> V_41 = V_41 ;
return 0 ;
V_115:
F_94 ( type -> V_114 ) ;
return V_49 ;
}
static int F_150 ( const struct V_13 * V_14 ,
const struct V_198 * V_199 ,
struct V_193 * V_194 )
{
const struct V_200 * V_41 = V_199 -> V_41 ;
int V_49 ;
V_194 -> V_41 = V_41 ;
if ( V_41 -> V_205 ) {
V_49 = V_41 -> V_205 ( V_14 , V_194 , ( const struct V_23 * * ) V_199 -> V_160 ) ;
if ( V_49 < 0 )
goto V_115;
}
return 0 ;
V_115:
V_194 -> V_41 = NULL ;
return V_49 ;
}
static void F_151 ( const struct V_13 * V_14 ,
struct V_193 * V_194 )
{
if ( V_194 -> V_41 -> V_206 )
V_194 -> V_41 -> V_206 ( V_14 , V_194 ) ;
F_94 ( V_194 -> V_41 -> type -> V_114 ) ;
}
struct V_193 * F_152 ( const struct V_13 * V_14 ,
const struct V_23 * V_24 )
{
struct V_198 V_199 ;
struct V_193 * V_194 ;
int V_49 ;
V_49 = F_149 ( V_14 , V_24 , & V_199 ) ;
if ( V_49 < 0 )
goto V_115;
V_49 = - V_45 ;
V_194 = F_19 ( V_199 . V_41 -> V_32 , V_34 ) ;
if ( V_194 == NULL )
goto V_116;
V_49 = F_150 ( V_14 , & V_199 , V_194 ) ;
if ( V_49 < 0 )
goto V_116;
return V_194 ;
V_116:
F_94 ( V_199 . V_41 -> type -> V_114 ) ;
V_115:
return F_13 ( V_49 ) ;
}
void F_153 ( const struct V_13 * V_14 , struct V_193 * V_194 )
{
F_151 ( V_14 , V_194 ) ;
F_22 ( V_194 ) ;
}
static struct V_56 * F_154 ( const struct V_21 * V_22 ,
T_2 V_130 )
{
struct V_56 * V_57 ;
F_9 (rule, &chain->rules, list) {
if ( V_130 == V_57 -> V_130 )
return V_57 ;
}
return F_13 ( - V_59 ) ;
}
static struct V_56 * F_155 ( const struct V_21 * V_22 ,
const struct V_23 * V_24 )
{
if ( V_24 == NULL )
return F_13 ( - V_70 ) ;
return F_154 ( V_22 , F_124 ( F_125 ( V_24 ) ) ) ;
}
static int F_156 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_26 , T_1 V_28 , int V_76 ,
T_1 V_39 , int V_9 ,
const struct V_19 * V_20 ,
const struct V_21 * V_22 ,
const struct V_56 * V_57 )
{
struct V_17 * V_18 ;
struct V_77 * V_78 ;
const struct V_193 * V_194 , * V_207 ;
struct V_23 * V_6 ;
const struct V_56 * V_208 ;
int type = V_76 | V_5 << 8 ;
V_18 = F_60 ( V_16 , V_26 , V_28 , type , sizeof( struct V_77 ) ,
V_39 ) ;
if ( V_18 == NULL )
goto V_79;
V_78 = F_61 ( V_18 ) ;
V_78 -> V_80 = V_9 ;
V_78 -> V_81 = V_82 ;
V_78 -> V_83 = F_62 ( V_1 -> V_7 . V_84 & 0xffff ) ;
if ( F_63 ( V_16 , V_209 , V_20 -> V_69 ) )
goto V_79;
if ( F_63 ( V_16 , V_210 , V_22 -> V_69 ) )
goto V_79;
if ( F_112 ( V_16 , V_211 , F_113 ( V_57 -> V_130 ) ) )
goto V_79;
if ( ( V_76 != V_61 ) && ( V_57 -> V_6 . V_212 != & V_22 -> V_190 ) ) {
V_208 = F_157 ( V_57 -> V_6 . V_212 , struct V_56 , V_6 ) ;
if ( F_112 ( V_16 , V_213 ,
F_113 ( V_208 -> V_130 ) ) )
goto V_79;
}
V_6 = F_111 ( V_16 , V_214 ) ;
if ( V_6 == NULL )
goto V_79;
F_158 (expr, next, rule) {
if ( F_148 ( V_16 , V_215 , V_194 ) < 0 )
goto V_79;
}
F_114 ( V_16 , V_6 ) ;
if ( V_57 -> V_216 ) {
struct V_217 * V_216 = V_217 ( V_57 ) ;
if ( F_159 ( V_16 , V_218 , V_216 -> V_99 + 1 ,
V_216 -> V_196 ) < 0 )
goto V_79;
}
F_66 ( V_16 , V_18 ) ;
return 0 ;
V_79:
F_67 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_160 ( const struct V_13 * V_14 ,
const struct V_56 * V_57 ,
int V_76 )
{
struct V_15 * V_16 ;
int V_49 ;
if ( ! V_14 -> V_27 &&
! F_69 ( V_14 -> V_1 , V_88 ) )
return 0 ;
V_49 = - V_89 ;
V_16 = F_70 ( V_90 , V_34 ) ;
if ( V_16 == NULL )
goto V_49;
V_49 = F_156 ( V_16 , V_14 -> V_1 , V_14 -> V_26 , V_14 -> V_28 ,
V_76 , 0 , V_14 -> V_3 -> V_9 , V_14 -> V_20 ,
V_14 -> V_22 , V_57 ) ;
if ( V_49 < 0 ) {
F_71 ( V_16 ) ;
goto V_49;
}
V_49 = F_72 ( V_16 , V_14 -> V_1 , V_14 -> V_26 , V_88 ,
V_14 -> V_27 , V_34 ) ;
V_49:
if ( V_49 < 0 ) {
F_73 ( V_14 -> V_1 , V_14 -> V_26 , V_88 ,
V_49 ) ;
}
return V_49 ;
}
static int F_161 ( struct V_15 * V_16 ,
struct V_91 * V_92 )
{
const struct V_77 * V_78 = F_61 ( V_92 -> V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
const struct V_56 * V_57 ;
unsigned int V_93 = 0 , V_94 = V_92 -> args [ 0 ] ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_78 -> V_80 ;
F_75 () ;
V_92 -> V_28 = V_1 -> V_7 . V_84 ;
F_76 (afi, &net->nft.af_info, list) {
if ( V_9 != V_95 && V_9 != V_3 -> V_9 )
continue;
F_76 (table, &afi->tables, list) {
F_76 (chain, &table->chains, list) {
F_76 (rule, &chain->rules, list) {
if ( ! F_35 ( V_1 , V_57 ) )
goto V_96;
if ( V_93 < V_94 )
goto V_96;
if ( V_93 > V_94 )
memset ( & V_92 -> args [ 1 ] , 0 ,
sizeof( V_92 -> args ) - sizeof( V_92 -> args [ 0 ] ) ) ;
if ( F_156 ( V_16 , V_1 , F_16 ( V_92 -> V_16 ) . V_26 ,
V_92 -> V_18 -> V_29 ,
V_219 ,
V_97 | V_220 ,
V_3 -> V_9 , V_20 , V_22 , V_57 ) < 0 )
goto V_98;
F_77 ( V_92 , F_78 ( V_16 ) ) ;
V_96:
V_93 ++ ;
}
}
}
}
V_98:
F_79 () ;
V_92 -> args [ 0 ] = V_93 ;
return V_16 -> V_99 ;
}
static int F_162 ( struct V_100 * V_101 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_77 * V_78 = F_61 ( V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
const struct V_56 * V_57 ;
struct V_15 * V_102 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_78 -> V_80 ;
int V_49 ;
if ( V_18 -> V_103 & V_104 ) {
struct V_105 V_106 = {
. V_107 = F_161 ,
} ;
return F_81 ( V_101 , V_16 , V_18 , & V_106 ) ;
}
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_82 ( V_3 ) )
return F_83 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_209 ] ) ;
if ( F_82 ( V_20 ) )
return F_83 ( V_20 ) ;
if ( V_20 -> V_39 & V_47 )
return - V_59 ;
V_22 = F_105 ( V_20 , V_24 [ V_210 ] ) ;
if ( F_82 ( V_22 ) )
return F_83 ( V_22 ) ;
if ( V_22 -> V_39 & V_53 )
return - V_59 ;
V_57 = F_155 ( V_22 , V_24 [ V_211 ] ) ;
if ( F_82 ( V_57 ) )
return F_83 ( V_57 ) ;
V_102 = F_84 ( V_90 , V_34 ) ;
if ( ! V_102 )
return - V_45 ;
V_49 = F_156 ( V_102 , V_1 , F_16 ( V_16 ) . V_26 ,
V_18 -> V_29 , V_219 , 0 ,
V_9 , V_20 , V_22 , V_57 ) ;
if ( V_49 < 0 )
goto V_49;
return F_85 ( V_101 , V_102 , F_16 ( V_16 ) . V_26 ) ;
V_49:
F_71 ( V_102 ) ;
return V_49 ;
}
static void F_163 ( const struct V_13 * V_14 ,
struct V_56 * V_57 )
{
struct V_193 * V_194 ;
V_194 = F_164 ( V_57 ) ;
while ( V_194 -> V_41 && V_194 != F_165 ( V_57 ) ) {
F_151 ( V_14 , V_194 ) ;
V_194 = F_166 ( V_194 ) ;
}
F_22 ( V_57 ) ;
}
static int F_167 ( struct V_100 * V_101 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_77 * V_78 = F_61 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_56 * V_57 , * V_221 = NULL ;
struct V_217 * V_216 ;
struct V_30 * V_33 = NULL ;
struct V_193 * V_194 ;
struct V_13 V_14 ;
struct V_23 * V_222 ;
unsigned int V_32 , V_73 , V_223 , V_224 = 0 , V_225 = 0 ;
int V_49 , V_226 ;
bool V_171 ;
T_2 V_130 , V_227 ;
V_171 = V_18 -> V_103 & V_172 ? true : false ;
V_3 = F_10 ( V_1 , V_78 -> V_80 , V_171 ) ;
if ( F_82 ( V_3 ) )
return F_83 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_209 ] ) ;
if ( F_82 ( V_20 ) )
return F_83 ( V_20 ) ;
V_22 = F_105 ( V_20 , V_24 [ V_210 ] ) ;
if ( F_82 ( V_22 ) )
return F_83 ( V_22 ) ;
if ( V_24 [ V_211 ] ) {
V_130 = F_124 ( F_125 ( V_24 [ V_211 ] ) ) ;
V_57 = F_154 ( V_22 , V_130 ) ;
if ( F_82 ( V_57 ) )
return F_83 ( V_57 ) ;
if ( V_18 -> V_103 & V_110 )
return - V_111 ;
if ( V_18 -> V_103 & V_112 )
V_221 = V_57 ;
else
return - V_113 ;
} else {
if ( ! V_171 || V_18 -> V_103 & V_112 )
return - V_70 ;
V_130 = F_54 ( V_20 ) ;
if ( V_22 -> V_55 == V_175 )
return - V_176 ;
}
if ( V_24 [ V_213 ] ) {
if ( ! ( V_18 -> V_103 & V_172 ) )
return - V_113 ;
V_227 = F_124 ( F_125 ( V_24 [ V_213 ] ) ) ;
V_221 = F_154 ( V_22 , V_227 ) ;
if ( F_82 ( V_221 ) )
return F_83 ( V_221 ) ;
}
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_223 = 0 ;
V_32 = 0 ;
if ( V_24 [ V_214 ] ) {
F_168 (tmp, nla[NFTA_RULE_EXPRESSIONS], rem) {
V_49 = - V_70 ;
if ( F_169 ( V_222 ) != V_215 )
goto V_115;
if ( V_223 == V_228 )
goto V_115;
V_49 = F_149 ( & V_14 , V_222 , & V_199 [ V_223 ] ) ;
if ( V_49 < 0 )
goto V_115;
V_32 += V_199 [ V_223 ] . V_41 -> V_32 ;
V_223 ++ ;
}
}
V_49 = - V_229 ;
if ( V_32 >= 1 << 12 )
goto V_115;
if ( V_24 [ V_218 ] ) {
V_224 = F_57 ( V_24 [ V_218 ] ) ;
if ( V_224 > 0 )
V_225 = sizeof( struct V_217 ) + V_224 ;
}
V_49 = - V_45 ;
V_57 = F_19 ( sizeof( * V_57 ) + V_32 + V_225 , V_34 ) ;
if ( V_57 == NULL )
goto V_115;
F_39 ( V_1 , V_57 ) ;
V_57 -> V_130 = V_130 ;
V_57 -> V_230 = V_32 ;
V_57 -> V_216 = V_224 ? 1 : 0 ;
if ( V_224 ) {
V_216 = V_217 ( V_57 ) ;
V_216 -> V_99 = V_224 - 1 ;
F_170 ( V_216 -> V_196 , V_24 [ V_218 ] , V_224 ) ;
}
V_194 = F_164 ( V_57 ) ;
for ( V_73 = 0 ; V_73 < V_223 ; V_73 ++ ) {
V_49 = F_150 ( & V_14 , & V_199 [ V_73 ] , V_194 ) ;
if ( V_49 < 0 )
goto V_116;
V_199 [ V_73 ] . V_41 = NULL ;
V_194 = F_166 ( V_194 ) ;
}
if ( V_18 -> V_103 & V_112 ) {
if ( F_37 ( V_1 , V_221 ) ) {
V_33 = F_43 ( & V_14 , V_61 ,
V_221 ) ;
if ( V_33 == NULL ) {
V_49 = - V_45 ;
goto V_116;
}
F_40 ( V_1 , V_221 ) ;
V_22 -> V_55 -- ;
F_4 ( & V_57 -> V_6 , & V_221 -> V_6 ) ;
} else {
V_49 = - V_59 ;
goto V_116;
}
} else if ( V_18 -> V_103 & V_220 )
if ( V_221 )
F_143 ( & V_57 -> V_6 , & V_221 -> V_6 ) ;
else
F_4 ( & V_57 -> V_6 , & V_22 -> V_190 ) ;
else {
if ( V_221 )
F_4 ( & V_57 -> V_6 , & V_221 -> V_6 ) ;
else
F_143 ( & V_57 -> V_6 , & V_22 -> V_190 ) ;
}
if ( F_43 ( & V_14 , V_219 , V_57 ) == NULL ) {
V_49 = - V_45 ;
goto V_120;
}
V_22 -> V_55 ++ ;
return 0 ;
V_120:
F_7 ( & V_57 -> V_6 ) ;
V_116:
F_163 ( & V_14 , V_57 ) ;
V_115:
for ( V_73 = 0 ; V_73 < V_223 ; V_73 ++ ) {
if ( V_199 [ V_73 ] . V_41 != NULL )
F_94 ( V_199 [ V_73 ] . V_41 -> type -> V_114 ) ;
}
return V_49 ;
}
static int F_171 ( struct V_100 * V_101 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_77 * V_78 = F_61 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
struct V_19 * V_20 ;
struct V_21 * V_22 = NULL ;
struct V_56 * V_57 ;
int V_9 = V_78 -> V_80 , V_49 = 0 ;
struct V_13 V_14 ;
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_82 ( V_3 ) )
return F_83 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_209 ] ) ;
if ( F_82 ( V_20 ) )
return F_83 ( V_20 ) ;
if ( V_20 -> V_39 & V_47 )
return - V_59 ;
if ( V_24 [ V_210 ] ) {
V_22 = F_105 ( V_20 , V_24 [ V_210 ] ) ;
if ( F_82 ( V_22 ) )
return F_83 ( V_22 ) ;
}
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
if ( V_22 ) {
if ( V_24 [ V_211 ] ) {
V_57 = F_155 ( V_22 ,
V_24 [ V_211 ] ) ;
if ( F_82 ( V_57 ) )
return F_83 ( V_57 ) ;
V_49 = F_44 ( & V_14 , V_57 ) ;
} else {
V_49 = F_45 ( & V_14 ) ;
}
} else {
F_9 (chain, &table->chains, list) {
V_14 . V_22 = V_22 ;
V_49 = F_45 ( & V_14 ) ;
if ( V_49 < 0 )
break;
}
}
return V_49 ;
}
int F_172 ( struct V_231 * V_41 )
{
F_3 ( V_5 ) ;
F_4 ( & V_41 -> V_6 , & V_232 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_173 ( struct V_231 * V_41 )
{
F_3 ( V_5 ) ;
F_7 ( & V_41 -> V_6 ) ;
F_5 ( V_5 ) ;
}
static const struct V_231 *
F_174 ( const struct V_23 * const V_24 [] ,
const struct V_233 * V_234 ,
enum V_235 V_156 )
{
const struct V_231 * V_41 , * V_236 ;
struct V_237 V_238 , V_239 ;
T_1 V_240 ;
#ifdef F_11
if ( F_97 ( & V_232 ) ) {
F_5 ( V_5 ) ;
F_12 ( L_5 ) ;
F_3 ( V_5 ) ;
if ( ! F_97 ( & V_232 ) )
return F_13 ( - V_11 ) ;
}
#endif
V_240 = 0 ;
if ( V_24 [ V_241 ] != NULL ) {
V_240 = F_48 ( F_49 ( V_24 [ V_241 ] ) ) ;
V_240 &= V_242 | V_243 | V_244 ;
}
V_236 = NULL ;
V_239 . V_32 = ~ 0 ;
V_239 . V_245 = ~ 0 ;
F_9 (ops, &nf_tables_set_ops, list) {
if ( ( V_41 -> V_240 & V_240 ) != V_240 )
continue;
if ( ! V_41 -> V_246 ( V_234 , V_240 , & V_238 ) )
continue;
switch ( V_156 ) {
case V_247 :
if ( V_238 . V_245 < V_239 . V_245 )
break;
if ( V_238 . V_245 == V_239 . V_245 && V_238 . V_32 < V_239 . V_32 )
break;
continue;
case V_248 :
if ( V_238 . V_32 < V_239 . V_32 )
break;
if ( V_238 . V_32 == V_239 . V_32 && V_238 . V_245 < V_239 . V_245 )
break;
continue;
default:
break;
}
if ( ! F_92 ( V_41 -> V_114 ) )
continue;
if ( V_236 != NULL )
F_94 ( V_236 -> V_114 ) ;
V_236 = V_41 ;
V_239 = V_238 ;
}
if ( V_236 != NULL )
return V_236 ;
return F_13 ( - V_113 ) ;
}
static int F_175 ( struct V_13 * V_14 ,
const struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
const struct V_77 * V_78 = F_61 ( V_18 ) ;
struct V_2 * V_3 = NULL ;
struct V_19 * V_20 = NULL ;
if ( V_78 -> V_80 != V_95 ) {
V_3 = F_10 ( V_1 , V_78 -> V_80 , false ) ;
if ( F_82 ( V_3 ) )
return F_83 ( V_3 ) ;
}
if ( V_24 [ V_249 ] != NULL ) {
if ( V_3 == NULL )
return - V_12 ;
V_20 = F_53 ( V_3 , V_24 [ V_249 ] ) ;
if ( F_82 ( V_20 ) )
return F_83 ( V_20 ) ;
if ( V_20 -> V_39 & V_47 )
return - V_59 ;
}
F_14 ( V_14 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return 0 ;
}
struct V_62 * F_176 ( const struct V_19 * V_20 ,
const struct V_23 * V_24 )
{
struct V_62 * V_63 ;
if ( V_24 == NULL )
return F_13 ( - V_70 ) ;
F_9 (set, &table->sets, list) {
if ( ! F_52 ( V_24 , V_63 -> V_69 ) )
return V_63 ;
}
return F_13 ( - V_59 ) ;
}
struct V_62 * F_177 ( const struct V_1 * V_1 ,
const struct V_23 * V_24 )
{
struct V_30 * V_33 ;
T_1 V_250 = F_48 ( F_49 ( V_24 ) ) ;
F_9 (trans, &net->nft.commit_list, list) {
if ( V_33 -> V_31 == V_65 &&
V_250 == F_47 ( V_33 ) )
return V_64 ( V_33 ) ;
}
return F_13 ( - V_59 ) ;
}
static int F_178 ( struct V_13 * V_14 , struct V_62 * V_63 ,
const char * V_69 )
{
const struct V_62 * V_73 ;
const char * V_251 ;
unsigned long * V_252 ;
unsigned int V_223 = 0 , V_253 = 0 ;
V_251 = F_179 ( V_69 , V_185 , '%' ) ;
if ( V_251 != NULL ) {
if ( V_251 [ 1 ] != 'd' || strchr ( V_251 + 2 , '%' ) )
return - V_70 ;
V_252 = ( unsigned long * ) F_180 ( V_34 ) ;
if ( V_252 == NULL )
return - V_45 ;
V_96:
F_9 (i, &ctx->table->sets, list) {
int V_222 ;
if ( ! sscanf ( V_73 -> V_69 , V_69 , & V_222 ) )
continue;
if ( V_222 < V_253 || V_222 >= V_253 + V_254 * V_255 )
continue;
F_181 ( V_222 - V_253 , V_252 ) ;
}
V_223 = F_182 ( V_252 , V_254 * V_255 ) ;
if ( V_223 >= V_254 * V_255 ) {
V_253 += V_254 * V_255 ;
memset ( V_252 , 0 , V_255 ) ;
goto V_96;
}
F_183 ( ( unsigned long ) V_252 ) ;
}
snprintf ( V_63 -> V_69 , sizeof( V_63 -> V_69 ) , V_69 , V_253 + V_223 ) ;
F_9 (i, &ctx->table->sets, list) {
if ( ! strcmp ( V_63 -> V_69 , V_73 -> V_69 ) )
return - V_256 ;
}
return 0 ;
}
static int F_184 ( struct V_15 * V_16 , const struct V_13 * V_14 ,
const struct V_62 * V_63 , T_6 V_76 , T_6 V_39 )
{
struct V_77 * V_78 ;
struct V_17 * V_18 ;
struct V_23 * V_234 ;
T_1 V_26 = V_14 -> V_26 ;
T_1 V_28 = V_14 -> V_28 ;
V_76 |= V_5 << 8 ;
V_18 = F_60 ( V_16 , V_26 , V_28 , V_76 , sizeof( struct V_77 ) ,
V_39 ) ;
if ( V_18 == NULL )
goto V_79;
V_78 = F_61 ( V_18 ) ;
V_78 -> V_80 = V_14 -> V_3 -> V_9 ;
V_78 -> V_81 = V_82 ;
V_78 -> V_83 = F_62 ( V_14 -> V_1 -> V_7 . V_84 & 0xffff ) ;
if ( F_63 ( V_16 , V_249 , V_14 -> V_20 -> V_69 ) )
goto V_79;
if ( F_63 ( V_16 , V_257 , V_63 -> V_69 ) )
goto V_79;
if ( V_63 -> V_39 != 0 )
if ( F_64 ( V_16 , V_241 , F_65 ( V_63 -> V_39 ) ) )
goto V_79;
if ( F_64 ( V_16 , V_258 , F_65 ( V_63 -> V_259 ) ) )
goto V_79;
if ( F_64 ( V_16 , V_260 , F_65 ( V_63 -> V_261 ) ) )
goto V_79;
if ( V_63 -> V_39 & V_243 ) {
if ( F_64 ( V_16 , V_262 , F_65 ( V_63 -> V_263 ) ) )
goto V_79;
if ( F_64 ( V_16 , V_264 , F_65 ( V_63 -> V_230 ) ) )
goto V_79;
}
if ( V_63 -> V_265 &&
F_112 ( V_16 , V_266 , F_113 ( V_63 -> V_265 ) ) )
goto V_79;
if ( V_63 -> V_267 &&
F_64 ( V_16 , V_268 , F_65 ( V_63 -> V_267 ) ) )
goto V_79;
if ( V_63 -> V_156 != V_247 ) {
if ( F_64 ( V_16 , V_269 , F_65 ( V_63 -> V_156 ) ) )
goto V_79;
}
V_234 = F_111 ( V_16 , V_270 ) ;
if ( V_234 == NULL )
goto V_79;
if ( V_63 -> V_32 &&
F_64 ( V_16 , V_271 , F_65 ( V_63 -> V_32 ) ) )
goto V_79;
F_114 ( V_16 , V_234 ) ;
F_66 ( V_16 , V_18 ) ;
return 0 ;
V_79:
F_67 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_185 ( const struct V_13 * V_14 ,
const struct V_62 * V_63 ,
int V_76 , T_7 V_272 )
{
struct V_15 * V_16 ;
T_1 V_26 = V_14 -> V_26 ;
int V_49 ;
if ( ! V_14 -> V_27 &&
! F_69 ( V_14 -> V_1 , V_88 ) )
return 0 ;
V_49 = - V_89 ;
V_16 = F_70 ( V_90 , V_272 ) ;
if ( V_16 == NULL )
goto V_49;
V_49 = F_184 ( V_16 , V_14 , V_63 , V_76 , 0 ) ;
if ( V_49 < 0 ) {
F_71 ( V_16 ) ;
goto V_49;
}
V_49 = F_72 ( V_16 , V_14 -> V_1 , V_26 , V_88 ,
V_14 -> V_27 , V_272 ) ;
V_49:
if ( V_49 < 0 )
F_73 ( V_14 -> V_1 , V_26 , V_88 , V_49 ) ;
return V_49 ;
}
static int F_186 ( struct V_15 * V_16 , struct V_91 * V_92 )
{
const struct V_62 * V_63 ;
unsigned int V_93 , V_94 = V_92 -> args [ 0 ] ;
struct V_2 * V_3 ;
struct V_19 * V_20 , * V_273 = (struct V_19 * ) V_92 -> args [ 2 ] ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_274 = V_92 -> args [ 3 ] ;
struct V_13 * V_14 = V_92 -> V_196 , V_275 ;
if ( V_92 -> args [ 1 ] )
return V_16 -> V_99 ;
F_75 () ;
V_92 -> V_28 = V_1 -> V_7 . V_84 ;
F_76 (afi, &net->nft.af_info, list) {
if ( V_14 -> V_3 && V_14 -> V_3 != V_3 )
continue;
if ( V_274 ) {
if ( V_3 -> V_9 != V_274 )
continue;
V_274 = 0 ;
}
F_76 (table, &afi->tables, list) {
if ( V_14 -> V_20 && V_14 -> V_20 != V_20 )
continue;
if ( V_273 ) {
if ( V_273 != V_20 )
continue;
V_273 = NULL ;
}
V_93 = 0 ;
F_76 (set, &table->sets, list) {
if ( V_93 < V_94 )
goto V_96;
V_275 = * V_14 ;
V_275 . V_20 = V_20 ;
V_275 . V_3 = V_3 ;
if ( F_184 ( V_16 , & V_275 , V_63 ,
V_65 ,
V_97 ) < 0 ) {
V_92 -> args [ 0 ] = V_93 ;
V_92 -> args [ 2 ] = ( unsigned long ) V_20 ;
V_92 -> args [ 3 ] = V_3 -> V_9 ;
goto V_98;
}
F_77 ( V_92 , F_78 ( V_16 ) ) ;
V_96:
V_93 ++ ;
}
if ( V_94 )
V_94 = 0 ;
}
}
V_92 -> args [ 1 ] = 1 ;
V_98:
F_79 () ;
return V_16 -> V_99 ;
}
static int F_187 ( struct V_91 * V_92 )
{
F_22 ( V_92 -> V_196 ) ;
return 0 ;
}
static int F_188 ( struct V_100 * V_101 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_62 * V_63 ;
struct V_13 V_14 ;
struct V_15 * V_102 ;
const struct V_77 * V_78 = F_61 ( V_18 ) ;
int V_49 ;
V_49 = F_175 ( & V_14 , V_16 , V_18 , V_24 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( V_18 -> V_103 & V_104 ) {
struct V_105 V_106 = {
. V_107 = F_186 ,
. V_98 = F_187 ,
} ;
struct V_13 * V_276 ;
V_276 = F_189 ( sizeof( * V_276 ) , V_34 ) ;
if ( V_276 == NULL )
return - V_45 ;
* V_276 = V_14 ;
V_106 . V_196 = V_276 ;
return F_81 ( V_101 , V_16 , V_18 , & V_106 ) ;
}
if ( V_78 -> V_80 == V_95 )
return - V_12 ;
V_63 = F_176 ( V_14 . V_20 , V_24 [ V_257 ] ) ;
if ( F_82 ( V_63 ) )
return F_83 ( V_63 ) ;
if ( V_63 -> V_39 & V_67 )
return - V_59 ;
V_102 = F_84 ( V_90 , V_34 ) ;
if ( V_102 == NULL )
return - V_45 ;
V_49 = F_184 ( V_102 , & V_14 , V_63 , V_65 , 0 ) ;
if ( V_49 < 0 )
goto V_49;
return F_85 ( V_101 , V_102 , F_16 ( V_16 ) . V_26 ) ;
V_49:
F_71 ( V_102 ) ;
return V_49 ;
}
static int F_190 ( const struct V_13 * V_14 ,
struct V_233 * V_234 ,
const struct V_23 * V_24 )
{
struct V_23 * V_277 [ V_278 + 1 ] ;
int V_49 ;
V_49 = F_120 ( V_277 , V_278 , V_24 , V_279 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( V_277 [ V_271 ] != NULL )
V_234 -> V_32 = F_48 ( F_49 ( V_277 [ V_271 ] ) ) ;
return 0 ;
}
static int F_191 ( struct V_100 * V_101 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_77 * V_78 = F_61 ( V_18 ) ;
const struct V_231 * V_41 ;
struct V_2 * V_3 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
struct V_19 * V_20 ;
struct V_62 * V_63 ;
struct V_13 V_14 ;
char V_69 [ V_185 ] ;
unsigned int V_32 ;
bool V_171 ;
T_2 V_265 ;
T_1 V_259 , V_263 , V_39 , V_156 , V_267 ;
struct V_233 V_234 ;
int V_49 ;
if ( V_24 [ V_249 ] == NULL ||
V_24 [ V_257 ] == NULL ||
V_24 [ V_260 ] == NULL ||
V_24 [ V_66 ] == NULL )
return - V_70 ;
memset ( & V_234 , 0 , sizeof( V_234 ) ) ;
V_259 = V_280 ;
if ( V_24 [ V_258 ] != NULL ) {
V_259 = F_48 ( F_49 ( V_24 [ V_258 ] ) ) ;
if ( ( V_259 & V_281 ) == V_281 )
return - V_70 ;
}
V_234 . V_261 = F_48 ( F_49 ( V_24 [ V_260 ] ) ) ;
if ( V_234 . V_261 == 0 || V_234 . V_261 > V_282 )
return - V_70 ;
V_39 = 0 ;
if ( V_24 [ V_241 ] != NULL ) {
V_39 = F_48 ( F_49 ( V_24 [ V_241 ] ) ) ;
if ( V_39 & ~ ( V_124 | V_283 |
V_242 | V_244 |
V_243 | V_284 ) )
return - V_70 ;
if ( ( V_39 & ( V_243 | V_284 ) ) ==
( V_243 | V_284 ) )
return - V_113 ;
}
V_263 = 0 ;
if ( V_24 [ V_262 ] != NULL ) {
if ( ! ( V_39 & V_243 ) )
return - V_70 ;
V_263 = F_48 ( F_49 ( V_24 [ V_262 ] ) ) ;
if ( ( V_263 & V_281 ) == V_281 &&
V_263 != V_285 )
return - V_70 ;
if ( V_263 != V_285 ) {
if ( V_24 [ V_264 ] == NULL )
return - V_70 ;
V_234 . V_230 = F_48 ( F_49 ( V_24 [ V_264 ] ) ) ;
if ( V_234 . V_230 == 0 || V_234 . V_230 > V_282 )
return - V_70 ;
} else
V_234 . V_230 = sizeof( struct V_286 ) ;
} else if ( V_39 & V_243 )
return - V_70 ;
V_265 = 0 ;
if ( V_24 [ V_266 ] != NULL ) {
if ( ! ( V_39 & V_244 ) )
return - V_70 ;
V_265 = F_124 ( F_125 ( V_24 [ V_266 ] ) ) ;
}
V_267 = 0 ;
if ( V_24 [ V_268 ] != NULL ) {
if ( ! ( V_39 & V_244 ) )
return - V_70 ;
V_267 = F_48 ( F_49 ( V_24 [ V_268 ] ) ) ;
}
V_156 = V_247 ;
if ( V_24 [ V_269 ] != NULL )
V_156 = F_48 ( F_49 ( V_24 [ V_269 ] ) ) ;
if ( V_24 [ V_270 ] != NULL ) {
V_49 = F_190 ( & V_14 , & V_234 , V_24 [ V_270 ] ) ;
if ( V_49 < 0 )
return V_49 ;
}
V_171 = V_18 -> V_103 & V_172 ? true : false ;
V_3 = F_10 ( V_1 , V_78 -> V_80 , V_171 ) ;
if ( F_82 ( V_3 ) )
return F_83 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_249 ] ) ;
if ( F_82 ( V_20 ) )
return F_83 ( V_20 ) ;
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
V_63 = F_176 ( V_20 , V_24 [ V_257 ] ) ;
if ( F_82 ( V_63 ) ) {
if ( F_83 ( V_63 ) != - V_59 )
return F_83 ( V_63 ) ;
V_63 = NULL ;
}
if ( V_63 != NULL ) {
if ( V_18 -> V_103 & V_110 )
return - V_111 ;
if ( V_18 -> V_103 & V_112 )
return - V_113 ;
return 0 ;
}
if ( ! ( V_18 -> V_103 & V_172 ) )
return - V_59 ;
V_41 = F_174 ( V_24 , & V_234 , V_156 ) ;
if ( F_82 ( V_41 ) )
return F_83 ( V_41 ) ;
V_32 = 0 ;
if ( V_41 -> V_287 != NULL )
V_32 = V_41 -> V_287 ( V_24 ) ;
V_49 = - V_45 ;
V_63 = F_19 ( sizeof( * V_63 ) + V_32 , V_34 ) ;
if ( V_63 == NULL )
goto V_115;
F_93 ( V_69 , V_24 [ V_257 ] , sizeof( V_63 -> V_69 ) ) ;
V_49 = F_178 ( & V_14 , V_63 , V_69 ) ;
if ( V_49 < 0 )
goto V_116;
F_2 ( & V_63 -> V_125 ) ;
F_140 ( & V_63 -> V_38 , V_1 ) ;
V_63 -> V_41 = V_41 ;
V_63 -> V_259 = V_259 ;
V_63 -> V_261 = V_234 . V_261 ;
V_63 -> V_263 = V_263 ;
V_63 -> V_230 = V_234 . V_230 ;
V_63 -> V_39 = V_39 ;
V_63 -> V_32 = V_234 . V_32 ;
V_63 -> V_156 = V_156 ;
V_63 -> V_265 = V_265 ;
V_63 -> V_267 = V_267 ;
V_49 = V_41 -> V_205 ( V_63 , & V_234 , V_24 ) ;
if ( V_49 < 0 )
goto V_116;
V_49 = F_46 ( & V_14 , V_65 , V_63 ) ;
if ( V_49 < 0 )
goto V_116;
F_4 ( & V_63 -> V_6 , & V_20 -> V_119 ) ;
V_20 -> V_55 ++ ;
return 0 ;
V_116:
F_22 ( V_63 ) ;
V_115:
F_94 ( V_41 -> V_114 ) ;
return V_49 ;
}
static void F_192 ( struct V_62 * V_63 )
{
V_63 -> V_41 -> V_206 ( V_63 ) ;
F_94 ( V_63 -> V_41 -> V_114 ) ;
F_22 ( V_63 ) ;
}
static void F_193 ( const struct V_13 * V_14 , struct V_62 * V_63 )
{
F_7 ( & V_63 -> V_6 ) ;
F_185 ( V_14 , V_63 , V_68 , V_288 ) ;
F_192 ( V_63 ) ;
}
static int F_194 ( struct V_100 * V_101 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_77 * V_78 = F_61 ( V_18 ) ;
struct V_62 * V_63 ;
struct V_13 V_14 ;
int V_49 ;
if ( V_78 -> V_80 == V_95 )
return - V_12 ;
if ( V_24 [ V_249 ] == NULL )
return - V_70 ;
V_49 = F_175 ( & V_14 , V_16 , V_18 , V_24 ) ;
if ( V_49 < 0 )
return V_49 ;
V_63 = F_176 ( V_14 . V_20 , V_24 [ V_257 ] ) ;
if ( F_82 ( V_63 ) )
return F_83 ( V_63 ) ;
if ( V_63 -> V_39 & V_67 )
return - V_59 ;
if ( ! F_97 ( & V_63 -> V_125 ) )
return - V_129 ;
return F_50 ( & V_14 , V_63 ) ;
}
static int F_195 ( const struct V_13 * V_14 ,
const struct V_62 * V_63 ,
const struct V_289 * V_290 ,
const struct V_291 * V_292 )
{
const struct V_293 * V_294 = F_196 ( V_63 , V_292 -> V_187 ) ;
enum V_295 V_296 ;
V_296 = F_197 ( V_63 -> V_263 ) ;
return F_198 ( V_14 , V_296 , F_199 ( V_294 ) ,
V_63 -> V_263 == V_285 ?
V_285 : V_280 ,
V_63 -> V_230 ) ;
}
int F_200 ( const struct V_13 * V_14 , struct V_62 * V_63 ,
struct V_297 * V_298 )
{
struct V_297 * V_73 ;
struct V_289 V_290 ;
if ( ! F_97 ( & V_63 -> V_125 ) && V_63 -> V_39 & V_124 )
return - V_129 ;
if ( V_298 -> V_39 & V_243 ) {
F_9 (i, &set->bindings, list) {
if ( V_298 -> V_39 & V_243 &&
V_73 -> V_22 == V_298 -> V_22 )
goto V_299;
}
V_290 . V_300 = 0 ;
V_290 . V_301 = 0 ;
V_290 . V_49 = 0 ;
V_290 . V_302 = F_195 ;
V_63 -> V_41 -> V_303 ( V_14 , V_63 , & V_290 ) ;
if ( V_290 . V_49 < 0 ) {
if ( V_63 -> V_39 & V_124 )
F_193 ( V_14 , V_63 ) ;
return V_290 . V_49 ;
}
}
V_299:
V_298 -> V_22 = V_14 -> V_22 ;
F_4 ( & V_298 -> V_6 , & V_63 -> V_125 ) ;
return 0 ;
}
void F_201 ( const struct V_13 * V_14 , struct V_62 * V_63 ,
struct V_297 * V_298 )
{
F_7 ( & V_298 -> V_6 ) ;
if ( F_97 ( & V_63 -> V_125 ) && V_63 -> V_39 & V_124 &&
! ( V_63 -> V_39 & V_67 ) )
F_193 ( V_14 , V_63 ) ;
}
static int F_202 ( struct V_13 * V_14 ,
const struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
bool V_33 )
{
const struct V_77 * V_78 = F_61 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
V_3 = F_10 ( V_1 , V_78 -> V_80 , false ) ;
if ( F_82 ( V_3 ) )
return F_83 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_304 ] ) ;
if ( F_82 ( V_20 ) )
return F_83 ( V_20 ) ;
if ( ! V_33 && ( V_20 -> V_39 & V_47 ) )
return - V_59 ;
F_14 ( V_14 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return 0 ;
}
static int F_203 ( struct V_15 * V_16 ,
const struct V_62 * V_63 ,
const struct V_291 * V_292 )
{
const struct V_293 * V_294 = F_196 ( V_63 , V_292 -> V_187 ) ;
unsigned char * V_305 = F_204 ( V_16 ) ;
struct V_23 * V_135 ;
V_135 = F_111 ( V_16 , V_215 ) ;
if ( V_135 == NULL )
goto V_79;
if ( F_205 ( V_16 , V_306 , F_206 ( V_294 ) ,
V_280 , V_63 -> V_261 ) < 0 )
goto V_79;
if ( F_207 ( V_294 , V_307 ) &&
F_205 ( V_16 , V_308 , F_199 ( V_294 ) ,
V_63 -> V_263 == V_285 ? V_285 : V_280 ,
V_63 -> V_230 ) < 0 )
goto V_79;
if ( F_207 ( V_294 , V_309 ) &&
F_148 ( V_16 , V_310 , F_208 ( V_294 ) ) < 0 )
goto V_79;
if ( F_207 ( V_294 , V_311 ) &&
F_64 ( V_16 , V_312 ,
F_65 ( * F_209 ( V_294 ) ) ) )
goto V_79;
if ( F_207 ( V_294 , V_313 ) &&
F_112 ( V_16 , V_314 ,
F_113 ( * F_210 ( V_294 ) ) ) )
goto V_79;
if ( F_207 ( V_294 , V_315 ) ) {
unsigned long V_316 , V_317 = V_318 ;
V_316 = * F_211 ( V_294 ) ;
if ( F_212 ( V_317 , V_316 ) )
V_316 -= V_317 ;
else
V_316 = 0 ;
if ( F_112 ( V_16 , V_319 ,
F_113 ( F_213 ( V_316 ) ) ) )
goto V_79;
}
if ( F_207 ( V_294 , V_320 ) ) {
struct V_217 * V_216 ;
V_216 = F_214 ( V_294 ) ;
if ( F_159 ( V_16 , V_321 ,
V_216 -> V_99 + 1 , V_216 -> V_196 ) )
goto V_79;
}
F_114 ( V_16 , V_135 ) ;
return 0 ;
V_79:
F_67 ( V_16 , V_305 ) ;
return - V_322 ;
}
static int F_215 ( const struct V_13 * V_14 ,
const struct V_62 * V_63 ,
const struct V_289 * V_290 ,
const struct V_291 * V_292 )
{
struct V_323 * args ;
args = F_216 ( V_290 , struct V_323 , V_290 ) ;
return F_203 ( args -> V_16 , V_63 , V_292 ) ;
}
static int F_217 ( struct V_15 * V_16 , struct V_91 * V_92 )
{
const struct V_62 * V_63 ;
struct V_323 args ;
struct V_13 V_14 ;
struct V_23 * V_24 [ V_324 + 1 ] ;
struct V_77 * V_78 ;
struct V_17 * V_18 ;
struct V_23 * V_135 ;
T_1 V_26 , V_28 ;
int V_76 , V_49 ;
V_49 = F_218 ( V_92 -> V_18 , sizeof( struct V_77 ) , V_24 ,
V_324 , V_325 ) ;
if ( V_49 < 0 )
return V_49 ;
V_49 = F_202 ( & V_14 , V_92 -> V_16 , V_92 -> V_18 , ( void * ) V_24 ,
false ) ;
if ( V_49 < 0 )
return V_49 ;
V_63 = F_176 ( V_14 . V_20 , V_24 [ V_326 ] ) ;
if ( F_82 ( V_63 ) )
return F_83 ( V_63 ) ;
if ( V_63 -> V_39 & V_67 )
return - V_59 ;
V_76 = V_327 ;
V_76 |= V_5 << 8 ;
V_26 = F_16 ( V_92 -> V_16 ) . V_26 ;
V_28 = V_92 -> V_18 -> V_29 ;
V_18 = F_60 ( V_16 , V_26 , V_28 , V_76 , sizeof( struct V_77 ) ,
V_97 ) ;
if ( V_18 == NULL )
goto V_79;
V_78 = F_61 ( V_18 ) ;
V_78 -> V_80 = V_14 . V_3 -> V_9 ;
V_78 -> V_81 = V_82 ;
V_78 -> V_83 = F_62 ( V_14 . V_1 -> V_7 . V_84 & 0xffff ) ;
if ( F_63 ( V_16 , V_304 , V_14 . V_20 -> V_69 ) )
goto V_79;
if ( F_63 ( V_16 , V_326 , V_63 -> V_69 ) )
goto V_79;
V_135 = F_111 ( V_16 , V_328 ) ;
if ( V_135 == NULL )
goto V_79;
args . V_92 = V_92 ;
args . V_16 = V_16 ;
args . V_290 . V_300 = V_92 -> args [ 0 ] ;
args . V_290 . V_301 = 0 ;
args . V_290 . V_49 = 0 ;
args . V_290 . V_302 = F_215 ;
V_63 -> V_41 -> V_303 ( & V_14 , V_63 , & args . V_290 ) ;
F_114 ( V_16 , V_135 ) ;
F_66 ( V_16 , V_18 ) ;
if ( args . V_290 . V_49 && args . V_290 . V_49 != - V_322 )
return args . V_290 . V_49 ;
if ( args . V_290 . V_301 == V_92 -> args [ 0 ] )
return 0 ;
V_92 -> args [ 0 ] = args . V_290 . V_301 ;
return V_16 -> V_99 ;
V_79:
return - V_143 ;
}
static int F_219 ( struct V_100 * V_101 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_62 * V_63 ;
struct V_13 V_14 ;
int V_49 ;
V_49 = F_202 ( & V_14 , V_16 , V_18 , V_24 , false ) ;
if ( V_49 < 0 )
return V_49 ;
V_63 = F_176 ( V_14 . V_20 , V_24 [ V_326 ] ) ;
if ( F_82 ( V_63 ) )
return F_83 ( V_63 ) ;
if ( V_63 -> V_39 & V_67 )
return - V_59 ;
if ( V_18 -> V_103 & V_104 ) {
struct V_105 V_106 = {
. V_107 = F_217 ,
} ;
return F_81 ( V_101 , V_16 , V_18 , & V_106 ) ;
}
return - V_113 ;
}
static int F_220 ( struct V_15 * V_16 ,
const struct V_13 * V_14 , T_1 V_28 ,
T_1 V_26 , int V_76 , T_6 V_39 ,
const struct V_62 * V_63 ,
const struct V_291 * V_292 )
{
struct V_77 * V_78 ;
struct V_17 * V_18 ;
struct V_23 * V_135 ;
int V_49 ;
V_76 |= V_5 << 8 ;
V_18 = F_60 ( V_16 , V_26 , V_28 , V_76 , sizeof( struct V_77 ) ,
V_39 ) ;
if ( V_18 == NULL )
goto V_79;
V_78 = F_61 ( V_18 ) ;
V_78 -> V_80 = V_14 -> V_3 -> V_9 ;
V_78 -> V_81 = V_82 ;
V_78 -> V_83 = F_62 ( V_14 -> V_1 -> V_7 . V_84 & 0xffff ) ;
if ( F_63 ( V_16 , V_249 , V_14 -> V_20 -> V_69 ) )
goto V_79;
if ( F_63 ( V_16 , V_257 , V_63 -> V_69 ) )
goto V_79;
V_135 = F_111 ( V_16 , V_328 ) ;
if ( V_135 == NULL )
goto V_79;
V_49 = F_203 ( V_16 , V_63 , V_292 ) ;
if ( V_49 < 0 )
goto V_79;
F_114 ( V_16 , V_135 ) ;
F_66 ( V_16 , V_18 ) ;
return 0 ;
V_79:
F_67 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_221 ( const struct V_13 * V_14 ,
const struct V_62 * V_63 ,
const struct V_291 * V_292 ,
int V_76 , T_6 V_39 )
{
struct V_1 * V_1 = V_14 -> V_1 ;
T_1 V_26 = V_14 -> V_26 ;
struct V_15 * V_16 ;
int V_49 ;
if ( ! V_14 -> V_27 && ! F_69 ( V_1 , V_88 ) )
return 0 ;
V_49 = - V_89 ;
V_16 = F_70 ( V_90 , V_34 ) ;
if ( V_16 == NULL )
goto V_49;
V_49 = F_220 ( V_16 , V_14 , 0 , V_26 , V_76 , V_39 ,
V_63 , V_292 ) ;
if ( V_49 < 0 ) {
F_71 ( V_16 ) ;
goto V_49;
}
V_49 = F_72 ( V_16 , V_1 , V_26 , V_88 , V_14 -> V_27 ,
V_34 ) ;
V_49:
if ( V_49 < 0 )
F_73 ( V_1 , V_26 , V_88 , V_49 ) ;
return V_49 ;
}
static struct V_30 * F_222 ( struct V_13 * V_14 ,
int V_31 ,
struct V_62 * V_63 )
{
struct V_30 * V_33 ;
V_33 = F_18 ( V_14 , V_31 , sizeof( struct V_329 ) ) ;
if ( V_33 == NULL )
return NULL ;
F_223 ( V_33 ) = V_63 ;
return V_33 ;
}
void * F_224 ( const struct V_62 * V_63 ,
const struct V_330 * V_331 ,
const T_1 * V_332 , const T_1 * V_196 ,
T_2 V_265 , T_7 V_333 )
{
struct V_293 * V_294 ;
void * V_292 ;
V_292 = F_19 ( V_63 -> V_41 -> V_334 + V_331 -> V_99 , V_333 ) ;
if ( V_292 == NULL )
return NULL ;
V_294 = F_196 ( V_63 , V_292 ) ;
F_225 ( V_294 , V_331 ) ;
memcpy ( F_206 ( V_294 ) , V_332 , V_63 -> V_261 ) ;
if ( F_207 ( V_294 , V_307 ) )
memcpy ( F_199 ( V_294 ) , V_196 , V_63 -> V_230 ) ;
if ( F_207 ( V_294 , V_315 ) )
* F_211 ( V_294 ) =
V_318 + F_226 ( V_265 ) ;
if ( F_207 ( V_294 , V_313 ) )
* F_210 ( V_294 ) = V_265 ;
return V_292 ;
}
void F_227 ( const struct V_62 * V_63 , void * V_292 )
{
struct V_293 * V_294 = F_196 ( V_63 , V_292 ) ;
F_228 ( F_206 ( V_294 ) , V_280 ) ;
if ( F_207 ( V_294 , V_307 ) )
F_228 ( F_199 ( V_294 ) , V_63 -> V_263 ) ;
if ( F_207 ( V_294 , V_309 ) )
F_151 ( NULL , F_208 ( V_294 ) ) ;
F_22 ( V_292 ) ;
}
static int F_229 ( struct V_13 * V_14 , struct V_62 * V_63 ,
const struct V_23 * V_159 )
{
struct V_23 * V_24 [ V_335 + 1 ] ;
struct V_336 V_337 , V_338 ;
struct V_330 V_331 ;
struct V_293 * V_294 ;
struct V_291 V_292 ;
struct V_297 * V_298 ;
struct V_217 * V_216 ;
struct V_339 V_196 ;
enum V_295 V_296 ;
struct V_30 * V_33 ;
T_2 V_265 ;
T_1 V_39 ;
T_4 V_224 ;
int V_49 ;
V_49 = F_120 ( V_24 , V_335 , V_159 ,
V_340 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( V_24 [ V_306 ] == NULL )
return - V_70 ;
F_230 ( & V_331 ) ;
V_39 = 0 ;
if ( V_24 [ V_312 ] != NULL ) {
V_39 = F_48 ( F_49 ( V_24 [ V_312 ] ) ) ;
if ( V_39 & ~ V_341 )
return - V_70 ;
if ( ! ( V_63 -> V_39 & V_242 ) &&
V_39 & V_341 )
return - V_70 ;
if ( V_39 != 0 )
F_231 ( & V_331 , V_311 ) ;
}
if ( V_63 -> V_39 & V_243 ) {
if ( V_24 [ V_308 ] == NULL &&
! ( V_39 & V_341 ) )
return - V_70 ;
if ( V_24 [ V_308 ] != NULL &&
V_39 & V_341 )
return - V_70 ;
} else {
if ( V_24 [ V_308 ] != NULL )
return - V_70 ;
}
V_265 = 0 ;
if ( V_24 [ V_314 ] != NULL ) {
if ( ! ( V_63 -> V_39 & V_244 ) )
return - V_70 ;
V_265 = F_124 ( F_125 ( V_24 [ V_314 ] ) ) ;
} else if ( V_63 -> V_39 & V_244 ) {
V_265 = V_63 -> V_265 ;
}
V_49 = F_232 ( V_14 , & V_292 . V_332 . V_342 , sizeof( V_292 . V_332 ) , & V_337 ,
V_24 [ V_306 ] ) ;
if ( V_49 < 0 )
goto V_115;
V_49 = - V_70 ;
if ( V_337 . type != V_280 || V_337 . V_99 != V_63 -> V_261 )
goto V_116;
F_233 ( & V_331 , V_343 , V_337 . V_99 ) ;
if ( V_265 > 0 ) {
F_231 ( & V_331 , V_315 ) ;
if ( V_265 != V_63 -> V_265 )
F_231 ( & V_331 , V_313 ) ;
}
if ( V_24 [ V_308 ] != NULL ) {
V_49 = F_232 ( V_14 , & V_196 , sizeof( V_196 ) , & V_338 ,
V_24 [ V_308 ] ) ;
if ( V_49 < 0 )
goto V_116;
V_49 = - V_70 ;
if ( V_63 -> V_263 != V_285 && V_338 . V_99 != V_63 -> V_230 )
goto V_120;
V_296 = F_197 ( V_63 -> V_263 ) ;
F_9 (binding, &set->bindings, list) {
struct V_13 V_344 = {
. V_3 = V_14 -> V_3 ,
. V_20 = V_14 -> V_20 ,
. V_22 = (struct V_21 * ) V_298 -> V_22 ,
} ;
if ( ! ( V_298 -> V_39 & V_243 ) )
continue;
V_49 = F_198 ( & V_344 , V_296 ,
& V_196 ,
V_338 . type , V_338 . V_99 ) ;
if ( V_49 < 0 )
goto V_120;
}
F_233 ( & V_331 , V_307 , V_338 . V_99 ) ;
}
V_224 = 0 ;
if ( V_24 [ V_321 ] != NULL ) {
V_224 = F_57 ( V_24 [ V_321 ] ) ;
if ( V_224 > 0 )
F_233 ( & V_331 , V_320 ,
V_224 ) ;
}
V_49 = - V_45 ;
V_292 . V_187 = F_224 ( V_63 , & V_331 , V_292 . V_332 . V_342 . V_196 , V_196 . V_196 ,
V_265 , V_34 ) ;
if ( V_292 . V_187 == NULL )
goto V_120;
V_294 = F_196 ( V_63 , V_292 . V_187 ) ;
if ( V_39 )
* F_209 ( V_294 ) = V_39 ;
if ( V_224 > 0 ) {
V_216 = F_214 ( V_294 ) ;
V_216 -> V_99 = V_224 - 1 ;
F_170 ( & V_216 -> V_196 , V_24 [ V_321 ] , V_224 ) ;
}
V_33 = F_222 ( V_14 , V_327 , V_63 ) ;
if ( V_33 == NULL )
goto V_345;
V_294 -> V_58 = F_36 ( V_14 -> V_1 ) | V_346 ;
V_49 = V_63 -> V_41 -> V_347 ( V_63 , & V_292 ) ;
if ( V_49 < 0 )
goto V_348;
V_329 ( V_33 ) = V_292 ;
F_31 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_48 ) ;
return 0 ;
V_348:
F_22 ( V_33 ) ;
V_345:
F_22 ( V_292 . V_187 ) ;
V_120:
if ( V_24 [ V_308 ] != NULL )
F_228 ( & V_196 , V_338 . type ) ;
V_116:
F_228 ( & V_292 . V_332 . V_342 , V_337 . type ) ;
V_115:
return V_49 ;
}
static int F_234 ( struct V_100 * V_101 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
const struct V_23 * V_159 ;
struct V_62 * V_63 ;
struct V_13 V_14 ;
int V_226 , V_49 = 0 ;
if ( V_24 [ V_328 ] == NULL )
return - V_70 ;
V_49 = F_202 ( & V_14 , V_16 , V_18 , V_24 , true ) ;
if ( V_49 < 0 )
return V_49 ;
V_63 = F_176 ( V_14 . V_20 , V_24 [ V_326 ] ) ;
if ( F_82 ( V_63 ) ) {
if ( V_24 [ V_349 ] ) {
V_63 = F_177 ( V_1 ,
V_24 [ V_349 ] ) ;
}
if ( F_82 ( V_63 ) )
return F_83 ( V_63 ) ;
}
if ( ! F_97 ( & V_63 -> V_125 ) && V_63 -> V_39 & V_283 )
return - V_129 ;
F_168 (attr, nla[NFTA_SET_ELEM_LIST_ELEMENTS], rem) {
if ( V_63 -> V_32 &&
! F_235 ( & V_63 -> V_350 , 1 , V_63 -> V_32 + V_63 -> V_351 ) )
return - V_256 ;
V_49 = F_229 ( & V_14 , V_63 , V_159 ) ;
if ( V_49 < 0 ) {
F_236 ( & V_63 -> V_350 ) ;
break;
}
}
return V_49 ;
}
static int F_237 ( struct V_13 * V_14 , struct V_62 * V_63 ,
const struct V_23 * V_159 )
{
struct V_23 * V_24 [ V_335 + 1 ] ;
struct V_336 V_234 ;
struct V_291 V_292 ;
struct V_30 * V_33 ;
int V_49 ;
V_49 = F_120 ( V_24 , V_335 , V_159 ,
V_340 ) ;
if ( V_49 < 0 )
goto V_115;
V_49 = - V_70 ;
if ( V_24 [ V_306 ] == NULL )
goto V_115;
V_49 = F_232 ( V_14 , & V_292 . V_332 . V_342 , sizeof( V_292 . V_332 ) , & V_234 ,
V_24 [ V_306 ] ) ;
if ( V_49 < 0 )
goto V_115;
V_49 = - V_70 ;
if ( V_234 . type != V_280 || V_234 . V_99 != V_63 -> V_261 )
goto V_116;
V_33 = F_222 ( V_14 , V_352 , V_63 ) ;
if ( V_33 == NULL ) {
V_49 = - V_45 ;
goto V_116;
}
V_292 . V_187 = V_63 -> V_41 -> V_353 ( V_63 , & V_292 ) ;
if ( V_292 . V_187 == NULL ) {
V_49 = - V_59 ;
goto V_120;
}
V_329 ( V_33 ) = V_292 ;
F_31 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_48 ) ;
return 0 ;
V_120:
F_22 ( V_33 ) ;
V_116:
F_228 ( & V_292 . V_332 . V_342 , V_234 . type ) ;
V_115:
return V_49 ;
}
static int F_238 ( struct V_100 * V_101 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_23 * V_159 ;
struct V_62 * V_63 ;
struct V_13 V_14 ;
int V_226 , V_49 = 0 ;
if ( V_24 [ V_328 ] == NULL )
return - V_70 ;
V_49 = F_202 ( & V_14 , V_16 , V_18 , V_24 , false ) ;
if ( V_49 < 0 )
return V_49 ;
V_63 = F_176 ( V_14 . V_20 , V_24 [ V_326 ] ) ;
if ( F_82 ( V_63 ) )
return F_83 ( V_63 ) ;
if ( ! F_97 ( & V_63 -> V_125 ) && V_63 -> V_39 & V_283 )
return - V_129 ;
F_168 (attr, nla[NFTA_SET_ELEM_LIST_ELEMENTS], rem) {
V_49 = F_237 ( & V_14 , V_63 , V_159 ) ;
if ( V_49 < 0 )
break;
V_63 -> V_351 ++ ;
}
return V_49 ;
}
void F_239 ( struct V_354 * V_355 )
{
struct V_356 * V_357 ;
unsigned int V_73 ;
V_357 = F_216 ( V_355 , struct V_356 , V_358 . V_355 ) ;
for ( V_73 = 0 ; V_73 < V_357 -> V_358 . V_359 ; V_73 ++ )
F_227 ( V_357 -> V_358 . V_63 , V_357 -> V_360 [ V_73 ] ) ;
F_22 ( V_357 ) ;
}
struct V_356 * F_240 ( const struct V_62 * V_63 ,
T_7 V_333 )
{
struct V_356 * V_357 ;
V_357 = F_19 ( sizeof( * V_357 ) , V_333 ) ;
if ( V_357 == NULL )
return V_357 ;
V_357 -> V_358 . V_63 = V_63 ;
return V_357 ;
}
static int F_241 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_26 , T_1 V_28 )
{
struct V_17 * V_18 ;
struct V_77 * V_78 ;
int V_76 = ( V_5 << 8 ) | V_361 ;
V_18 = F_60 ( V_16 , V_26 , V_28 , V_76 , sizeof( struct V_77 ) , 0 ) ;
if ( V_18 == NULL )
goto V_79;
V_78 = F_61 ( V_18 ) ;
V_78 -> V_80 = V_127 ;
V_78 -> V_81 = V_82 ;
V_78 -> V_83 = F_62 ( V_1 -> V_7 . V_84 & 0xffff ) ;
if ( F_64 ( V_16 , V_362 , F_65 ( V_1 -> V_7 . V_84 ) ) )
goto V_79;
F_66 ( V_16 , V_18 ) ;
return 0 ;
V_79:
F_67 ( V_16 , V_18 ) ;
return - V_322 ;
}
static int F_242 ( struct V_1 * V_1 , struct V_15 * V_16 , int V_76 )
{
struct V_17 * V_18 = F_78 ( V_16 ) ;
struct V_15 * V_102 ;
int V_49 ;
if ( F_17 ( V_18 ) &&
! F_69 ( V_1 , V_88 ) )
return 0 ;
V_49 = - V_89 ;
V_102 = F_70 ( V_90 , V_34 ) ;
if ( V_102 == NULL )
goto V_49;
V_49 = F_241 ( V_102 , V_1 , F_16 ( V_16 ) . V_26 ,
V_18 -> V_29 ) ;
if ( V_49 < 0 ) {
F_71 ( V_102 ) ;
goto V_49;
}
V_49 = F_72 ( V_102 , V_1 , F_16 ( V_16 ) . V_26 ,
V_88 , F_17 ( V_18 ) , V_34 ) ;
V_49:
if ( V_49 < 0 ) {
F_73 ( V_1 , F_16 ( V_16 ) . V_26 , V_88 ,
V_49 ) ;
}
return V_49 ;
}
static int F_243 ( struct V_100 * V_101 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
struct V_15 * V_102 ;
int V_49 ;
V_102 = F_84 ( V_90 , V_34 ) ;
if ( V_102 == NULL )
return - V_45 ;
V_49 = F_241 ( V_102 , V_1 , F_16 ( V_16 ) . V_26 ,
V_18 -> V_29 ) ;
if ( V_49 < 0 )
goto V_49;
return F_85 ( V_101 , V_102 , F_16 ( V_16 ) . V_26 ) ;
V_49:
F_71 ( V_102 ) ;
return V_49 ;
}
static void F_244 ( struct V_30 * V_33 )
{
struct V_35 * V_36 ;
if ( F_138 ( V_33 ) [ 0 ] )
strcpy ( V_33 -> V_14 . V_22 -> V_69 , F_138 ( V_33 ) ) ;
if ( ! ( V_33 -> V_14 . V_22 -> V_39 & V_43 ) )
return;
V_36 = V_35 ( V_33 -> V_14 . V_22 ) ;
F_127 ( V_36 , F_135 ( V_33 ) ) ;
switch ( F_137 ( V_33 ) ) {
case V_173 :
case V_170 :
V_36 -> V_156 = F_137 ( V_33 ) ;
break;
}
}
static void F_245 ( struct V_30 * V_33 )
{
switch ( V_33 -> V_31 ) {
case V_50 :
F_100 ( & V_33 -> V_14 ) ;
break;
case V_54 :
F_132 ( V_33 -> V_14 . V_22 ) ;
break;
case V_61 :
F_163 ( & V_33 -> V_14 , V_60 ( V_33 ) ) ;
break;
case V_68 :
F_192 ( V_64 ( V_33 ) ) ;
break;
case V_352 :
F_227 ( F_223 ( V_33 ) ,
V_329 ( V_33 ) . V_187 ) ;
break;
}
F_22 ( V_33 ) ;
}
static int F_246 ( struct V_15 * V_16 )
{
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
struct V_30 * V_33 , * V_207 ;
struct V_329 * V_363 ;
while ( ++ V_1 -> V_7 . V_84 == 0 ) ;
V_1 -> V_7 . V_364 = F_247 ( V_1 ) ;
F_130 () ;
F_96 (trans, next, &net->nft.commit_list, list) {
switch ( V_33 -> V_31 ) {
case V_46 :
if ( F_90 ( V_33 ) ) {
if ( ! F_89 ( V_33 ) ) {
F_87 ( V_33 -> V_14 . V_3 ,
V_33 -> V_14 . V_20 ) ;
V_33 -> V_14 . V_20 -> V_39 |= V_42 ;
}
} else {
V_33 -> V_14 . V_20 -> V_39 &= ~ V_47 ;
}
F_68 ( & V_33 -> V_14 , V_46 ) ;
F_20 ( V_33 ) ;
break;
case V_50 :
F_68 ( & V_33 -> V_14 , V_50 ) ;
break;
case V_52 :
if ( F_136 ( V_33 ) )
F_244 ( V_33 ) ;
else
V_33 -> V_14 . V_22 -> V_39 &= ~ V_53 ;
F_116 ( & V_33 -> V_14 , V_52 ) ;
F_20 ( V_33 ) ;
break;
case V_54 :
F_116 ( & V_33 -> V_14 , V_54 ) ;
F_29 ( V_33 -> V_14 . V_20 ,
V_33 -> V_14 . V_22 ,
V_33 -> V_14 . V_3 -> V_108 ) ;
break;
case V_219 :
F_41 ( V_33 -> V_14 . V_1 , V_60 ( V_33 ) ) ;
F_160 ( & V_33 -> V_14 ,
V_60 ( V_33 ) ,
V_219 ) ;
F_20 ( V_33 ) ;
break;
case V_61 :
F_7 ( & V_60 ( V_33 ) -> V_6 ) ;
F_160 ( & V_33 -> V_14 ,
V_60 ( V_33 ) ,
V_61 ) ;
break;
case V_65 :
V_64 ( V_33 ) -> V_39 &= ~ V_67 ;
if ( V_64 ( V_33 ) -> V_39 & V_124 &&
! F_97 ( & V_64 ( V_33 ) -> V_125 ) )
V_33 -> V_14 . V_20 -> V_55 -- ;
F_185 ( & V_33 -> V_14 , V_64 ( V_33 ) ,
V_65 , V_34 ) ;
F_20 ( V_33 ) ;
break;
case V_68 :
F_185 ( & V_33 -> V_14 , V_64 ( V_33 ) ,
V_68 , V_34 ) ;
break;
case V_327 :
V_363 = (struct V_329 * ) V_33 -> V_196 ;
V_363 -> V_63 -> V_41 -> V_365 ( V_363 -> V_63 , & V_363 -> V_292 ) ;
F_221 ( & V_33 -> V_14 , V_363 -> V_63 ,
& V_363 -> V_292 ,
V_327 , 0 ) ;
F_20 ( V_33 ) ;
break;
case V_352 :
V_363 = (struct V_329 * ) V_33 -> V_196 ;
F_221 ( & V_33 -> V_14 , V_363 -> V_63 ,
& V_363 -> V_292 ,
V_352 , 0 ) ;
V_363 -> V_63 -> V_41 -> remove ( V_363 -> V_63 , & V_363 -> V_292 ) ;
F_236 ( & V_363 -> V_63 -> V_350 ) ;
V_363 -> V_63 -> V_351 -- ;
break;
}
}
F_130 () ;
F_96 (trans, next, &net->nft.commit_list, list) {
F_21 ( & V_33 -> V_6 ) ;
F_245 ( V_33 ) ;
}
F_242 ( V_1 , V_16 , V_361 ) ;
return 0 ;
}
static void F_248 ( struct V_30 * V_33 )
{
switch ( V_33 -> V_31 ) {
case V_46 :
F_100 ( & V_33 -> V_14 ) ;
break;
case V_52 :
F_132 ( V_33 -> V_14 . V_22 ) ;
break;
case V_219 :
F_163 ( & V_33 -> V_14 , V_60 ( V_33 ) ) ;
break;
case V_65 :
F_192 ( V_64 ( V_33 ) ) ;
break;
case V_327 :
F_227 ( F_223 ( V_33 ) ,
V_329 ( V_33 ) . V_187 ) ;
break;
}
F_22 ( V_33 ) ;
}
static int F_249 ( struct V_15 * V_16 )
{
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
struct V_30 * V_33 , * V_207 ;
struct V_329 * V_363 ;
F_96 (trans, next, &net->nft.commit_list, list) {
switch ( V_33 -> V_31 ) {
case V_46 :
if ( F_90 ( V_33 ) ) {
if ( F_89 ( V_33 ) ) {
F_87 ( V_33 -> V_14 . V_3 ,
V_33 -> V_14 . V_20 ) ;
V_33 -> V_14 . V_20 -> V_39 |= V_42 ;
}
F_20 ( V_33 ) ;
} else {
F_7 ( & V_33 -> V_14 . V_20 -> V_6 ) ;
}
break;
case V_50 :
F_4 ( & V_33 -> V_14 . V_20 -> V_6 ,
& V_33 -> V_14 . V_3 -> V_4 ) ;
F_20 ( V_33 ) ;
break;
case V_52 :
if ( F_136 ( V_33 ) ) {
F_131 ( F_135 ( V_33 ) ) ;
F_20 ( V_33 ) ;
} else {
V_33 -> V_14 . V_20 -> V_55 -- ;
F_7 ( & V_33 -> V_14 . V_22 -> V_6 ) ;
F_29 ( V_33 -> V_14 . V_20 ,
V_33 -> V_14 . V_22 ,
V_33 -> V_14 . V_3 -> V_108 ) ;
}
break;
case V_54 :
V_33 -> V_14 . V_20 -> V_55 ++ ;
F_4 ( & V_33 -> V_14 . V_22 -> V_6 ,
& V_33 -> V_14 . V_20 -> V_118 ) ;
F_20 ( V_33 ) ;
break;
case V_219 :
V_33 -> V_14 . V_22 -> V_55 -- ;
F_7 ( & V_60 ( V_33 ) -> V_6 ) ;
break;
case V_61 :
V_33 -> V_14 . V_22 -> V_55 ++ ;
F_41 ( V_33 -> V_14 . V_1 , V_60 ( V_33 ) ) ;
F_20 ( V_33 ) ;
break;
case V_65 :
V_33 -> V_14 . V_20 -> V_55 -- ;
F_7 ( & V_64 ( V_33 ) -> V_6 ) ;
break;
case V_68 :
V_33 -> V_14 . V_20 -> V_55 ++ ;
F_4 ( & V_64 ( V_33 ) -> V_6 ,
& V_33 -> V_14 . V_20 -> V_119 ) ;
F_20 ( V_33 ) ;
break;
case V_327 :
V_363 = (struct V_329 * ) V_33 -> V_196 ;
V_363 -> V_63 -> V_41 -> remove ( V_363 -> V_63 , & V_363 -> V_292 ) ;
F_236 ( & V_363 -> V_63 -> V_350 ) ;
break;
case V_352 :
V_363 = (struct V_329 * ) V_33 -> V_196 ;
V_363 -> V_63 -> V_41 -> V_365 ( V_363 -> V_63 , & V_363 -> V_292 ) ;
V_363 -> V_63 -> V_351 -- ;
F_20 ( V_33 ) ;
break;
}
}
F_130 () ;
F_250 (trans, next,
&net->nft.commit_list, list) {
F_21 ( & V_33 -> V_6 ) ;
F_248 ( V_33 ) ;
}
return 0 ;
}
int F_251 ( const struct V_21 * V_22 ,
enum V_366 type )
{
const struct V_35 * V_36 ;
if ( V_22 -> V_39 & V_43 ) {
V_36 = V_35 ( V_22 ) ;
if ( V_36 -> type -> type != type )
return - V_113 ;
}
return 0 ;
}
int F_252 ( const struct V_21 * V_22 ,
unsigned int V_367 )
{
struct V_35 * V_36 ;
if ( V_22 -> V_39 & V_43 ) {
V_36 = V_35 ( V_22 ) ;
if ( ( 1 << V_36 -> V_41 [ 0 ] . V_150 ) & V_367 )
return 0 ;
return - V_113 ;
}
return 0 ;
}
static int F_253 ( const struct V_13 * V_14 ,
const struct V_62 * V_63 ,
const struct V_289 * V_290 ,
const struct V_291 * V_292 )
{
const struct V_293 * V_294 = F_196 ( V_63 , V_292 -> V_187 ) ;
const struct V_339 * V_196 ;
if ( F_207 ( V_294 , V_311 ) &&
* F_209 ( V_294 ) & V_341 )
return 0 ;
V_196 = F_199 ( V_294 ) ;
switch ( V_196 -> V_368 . V_369 ) {
case V_370 :
case V_371 :
return F_254 ( V_14 , V_196 -> V_368 . V_22 ) ;
default:
return 0 ;
}
}
static int F_254 ( const struct V_13 * V_14 ,
const struct V_21 * V_22 )
{
const struct V_56 * V_57 ;
const struct V_193 * V_194 , * V_372 ;
const struct V_62 * V_63 ;
struct V_297 * V_298 ;
struct V_289 V_290 ;
if ( V_14 -> V_22 == V_22 )
return - V_373 ;
F_9 (rule, &chain->rules, list) {
F_158 (expr, last, rule) {
const struct V_339 * V_196 = NULL ;
int V_49 ;
if ( ! V_194 -> V_41 -> V_374 )
continue;
V_49 = V_194 -> V_41 -> V_374 ( V_14 , V_194 , & V_196 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( V_196 == NULL )
continue;
switch ( V_196 -> V_368 . V_369 ) {
case V_370 :
case V_371 :
V_49 = F_254 ( V_14 ,
V_196 -> V_368 . V_22 ) ;
if ( V_49 < 0 )
return V_49 ;
default:
break;
}
}
}
F_9 (set, &ctx->table->sets, list) {
if ( ! ( V_63 -> V_39 & V_243 ) ||
V_63 -> V_263 != V_285 )
continue;
F_9 (binding, &set->bindings, list) {
if ( ! ( V_298 -> V_39 & V_243 ) ||
V_298 -> V_22 != V_22 )
continue;
V_290 . V_300 = 0 ;
V_290 . V_301 = 0 ;
V_290 . V_49 = 0 ;
V_290 . V_302 = F_253 ;
V_63 -> V_41 -> V_303 ( V_14 , V_63 , & V_290 ) ;
if ( V_290 . V_49 < 0 )
return V_290 . V_49 ;
}
}
return 0 ;
}
unsigned int F_255 ( const struct V_23 * V_159 )
{
unsigned int V_375 ;
V_375 = F_48 ( F_49 ( V_159 ) ) ;
switch ( V_375 ) {
case V_376 ... V_377 :
return V_375 * V_378 / V_379 ;
default:
return V_375 + V_378 / V_379 - V_380 ;
}
}
int F_256 ( struct V_15 * V_16 , unsigned int V_159 , unsigned int V_375 )
{
if ( V_375 % ( V_378 / V_379 ) == 0 )
V_375 = V_375 / ( V_378 / V_379 ) ;
else
V_375 = V_375 - V_378 / V_379 + V_380 ;
return F_64 ( V_16 , V_159 , F_65 ( V_375 ) ) ;
}
int F_257 ( enum V_295 V_375 , unsigned int V_99 )
{
if ( V_375 < V_381 * V_378 / V_379 )
return - V_70 ;
if ( V_99 == 0 )
return - V_70 ;
if ( V_375 * V_379 + V_99 > F_258 ( struct V_382 , V_196 ) )
return - V_383 ;
return 0 ;
}
int F_198 ( const struct V_13 * V_14 ,
enum V_295 V_375 ,
const struct V_339 * V_196 ,
enum V_384 type , unsigned int V_99 )
{
int V_49 ;
switch ( V_375 ) {
case V_376 :
if ( type != V_285 )
return - V_70 ;
if ( V_196 != NULL &&
( V_196 -> V_368 . V_369 == V_371 ||
V_196 -> V_368 . V_369 == V_370 ) ) {
V_49 = F_254 ( V_14 , V_196 -> V_368 . V_22 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( V_14 -> V_22 -> V_385 + 1 >
V_196 -> V_368 . V_22 -> V_385 ) {
if ( V_14 -> V_22 -> V_385 + 1 == V_386 )
return - V_387 ;
V_196 -> V_368 . V_22 -> V_385 = V_14 -> V_22 -> V_385 + 1 ;
}
}
return 0 ;
default:
if ( V_375 < V_381 * V_378 / V_379 )
return - V_70 ;
if ( V_99 == 0 )
return - V_70 ;
if ( V_375 * V_379 + V_99 >
F_258 ( struct V_382 , V_196 ) )
return - V_383 ;
if ( V_196 != NULL && type != V_280 )
return - V_70 ;
return 0 ;
}
}
static int F_259 ( const struct V_13 * V_14 , struct V_339 * V_196 ,
struct V_336 * V_234 , const struct V_23 * V_24 )
{
struct V_23 * V_160 [ V_388 + 1 ] ;
struct V_21 * V_22 ;
int V_49 ;
V_49 = F_120 ( V_160 , V_388 , V_24 , V_389 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( ! V_160 [ V_390 ] )
return - V_70 ;
V_196 -> V_368 . V_369 = F_48 ( F_49 ( V_160 [ V_390 ] ) ) ;
switch ( V_196 -> V_368 . V_369 ) {
default:
switch ( V_196 -> V_368 . V_369 & V_391 ) {
case V_170 :
case V_173 :
case V_392 :
break;
default:
return - V_70 ;
}
case V_393 :
case V_394 :
case V_395 :
break;
case V_370 :
case V_371 :
if ( ! V_160 [ V_396 ] )
return - V_70 ;
V_22 = F_105 ( V_14 -> V_20 ,
V_160 [ V_396 ] ) ;
if ( F_82 ( V_22 ) )
return F_83 ( V_22 ) ;
if ( V_22 -> V_39 & V_43 )
return - V_113 ;
V_22 -> V_55 ++ ;
V_196 -> V_368 . V_22 = V_22 ;
break;
}
V_234 -> V_99 = sizeof( V_196 -> V_368 ) ;
V_234 -> type = V_285 ;
return 0 ;
}
static void F_260 ( const struct V_339 * V_196 )
{
switch ( V_196 -> V_368 . V_369 ) {
case V_370 :
case V_371 :
V_196 -> V_368 . V_22 -> V_55 -- ;
break;
}
}
static int F_261 ( struct V_15 * V_16 , const struct V_339 * V_196 )
{
struct V_23 * V_135 ;
V_135 = F_111 ( V_16 , V_397 ) ;
if ( ! V_135 )
goto V_79;
if ( F_64 ( V_16 , V_390 , F_65 ( V_196 -> V_368 . V_369 ) ) )
goto V_79;
switch ( V_196 -> V_368 . V_369 ) {
case V_370 :
case V_371 :
if ( F_63 ( V_16 , V_396 ,
V_196 -> V_368 . V_22 -> V_69 ) )
goto V_79;
}
F_114 ( V_16 , V_135 ) ;
return 0 ;
V_79:
return - 1 ;
}
static int F_262 ( const struct V_13 * V_14 ,
struct V_339 * V_196 , unsigned int V_32 ,
struct V_336 * V_234 , const struct V_23 * V_24 )
{
unsigned int V_99 ;
V_99 = F_57 ( V_24 ) ;
if ( V_99 == 0 )
return - V_70 ;
if ( V_99 > V_32 )
return - V_176 ;
F_170 ( V_196 -> V_196 , V_24 , V_99 ) ;
V_234 -> type = V_280 ;
V_234 -> V_99 = V_99 ;
return 0 ;
}
static int F_263 ( struct V_15 * V_16 , const struct V_339 * V_196 ,
unsigned int V_99 )
{
return F_159 ( V_16 , V_398 , V_99 , V_196 -> V_196 ) ;
}
int F_232 ( const struct V_13 * V_14 ,
struct V_339 * V_196 , unsigned int V_32 ,
struct V_336 * V_234 , const struct V_23 * V_24 )
{
struct V_23 * V_160 [ V_399 + 1 ] ;
int V_49 ;
V_49 = F_120 ( V_160 , V_399 , V_24 , V_400 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( V_160 [ V_398 ] )
return F_262 ( V_14 , V_196 , V_32 , V_234 ,
V_160 [ V_398 ] ) ;
if ( V_160 [ V_397 ] && V_14 != NULL )
return F_259 ( V_14 , V_196 , V_234 , V_160 [ V_397 ] ) ;
return - V_70 ;
}
void F_228 ( const struct V_339 * V_196 , enum V_384 type )
{
if ( type < V_285 )
return;
switch ( type ) {
case V_285 :
return F_260 ( V_196 ) ;
default:
F_264 ( 1 ) ;
}
}
int F_205 ( struct V_15 * V_16 , int V_159 , const struct V_339 * V_196 ,
enum V_384 type , unsigned int V_99 )
{
struct V_23 * V_135 ;
int V_49 ;
V_135 = F_111 ( V_16 , V_159 ) ;
if ( V_135 == NULL )
return - 1 ;
switch ( type ) {
case V_280 :
V_49 = F_263 ( V_16 , V_196 , V_99 ) ;
break;
case V_285 :
V_49 = F_261 ( V_16 , V_196 ) ;
break;
default:
V_49 = - V_70 ;
F_264 ( 1 ) ;
}
F_114 ( V_16 , V_135 ) ;
return V_49 ;
}
static int F_265 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_7 . V_8 ) ;
F_2 ( & V_1 -> V_7 . V_48 ) ;
V_1 -> V_7 . V_84 = 1 ;
return 0 ;
}
static int T_8 F_266 ( void )
{
int V_49 ;
V_199 = F_189 ( sizeof( struct V_198 ) * V_228 ,
V_34 ) ;
if ( V_199 == NULL ) {
V_49 = - V_45 ;
goto V_115;
}
V_49 = F_267 () ;
if ( V_49 < 0 )
goto V_116;
V_49 = F_268 ( & V_401 ) ;
if ( V_49 < 0 )
goto V_120;
F_269 ( L_6 ) ;
return F_270 ( & V_402 ) ;
V_120:
F_271 () ;
V_116:
F_22 ( V_199 ) ;
V_115:
return V_49 ;
}
static void T_9 F_272 ( void )
{
F_273 ( & V_402 ) ;
F_274 ( & V_401 ) ;
F_275 () ;
F_271 () ;
F_22 ( V_199 ) ;
}
