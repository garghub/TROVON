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
if ( V_36 -> V_38 & V_39 )
return 0 ;
return F_24 ( V_36 -> V_40 , V_37 ) ;
}
void F_25 ( struct V_35 * V_36 ,
unsigned int V_37 )
{
if ( V_36 -> V_38 & V_39 )
return;
F_26 ( V_36 -> V_40 , V_37 ) ;
}
static int F_27 ( const struct V_19 * V_20 ,
struct V_21 * V_22 ,
unsigned int V_37 )
{
if ( V_20 -> V_38 & V_41 ||
! ( V_22 -> V_38 & V_42 ) )
return 0 ;
return F_23 ( V_35 ( V_22 ) , V_37 ) ;
}
static void F_28 ( const struct V_19 * V_20 ,
struct V_21 * V_22 ,
unsigned int V_37 )
{
if ( V_20 -> V_38 & V_41 ||
! ( V_22 -> V_38 & V_42 ) )
return;
F_25 ( V_35 ( V_22 ) , V_37 ) ;
}
static int F_29 ( struct V_13 * V_14 , int V_31 )
{
struct V_30 * V_33 ;
V_33 = F_18 ( V_14 , V_31 , sizeof( struct V_43 ) ) ;
if ( V_33 == NULL )
return - V_44 ;
if ( V_31 == V_45 )
V_14 -> V_20 -> V_38 |= V_46 ;
F_30 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_47 ) ;
return 0 ;
}
static int F_31 ( struct V_13 * V_14 )
{
int V_48 ;
V_48 = F_29 ( V_14 , V_49 ) ;
if ( V_48 < 0 )
return V_48 ;
F_7 ( & V_14 -> V_20 -> V_6 ) ;
return V_48 ;
}
static int F_32 ( struct V_13 * V_14 , int V_31 )
{
struct V_30 * V_33 ;
V_33 = F_18 ( V_14 , V_31 , sizeof( struct V_50 ) ) ;
if ( V_33 == NULL )
return - V_44 ;
if ( V_31 == V_51 )
V_14 -> V_22 -> V_38 |= V_52 ;
F_30 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_47 ) ;
return 0 ;
}
static int F_33 ( struct V_13 * V_14 )
{
int V_48 ;
V_48 = F_32 ( V_14 , V_53 ) ;
if ( V_48 < 0 )
return V_48 ;
V_14 -> V_20 -> V_54 -- ;
F_7 ( & V_14 -> V_22 -> V_6 ) ;
return V_48 ;
}
static inline bool
F_34 ( struct V_1 * V_1 , const struct V_55 * V_56 )
{
return ( V_56 -> V_57 & F_35 ( V_1 ) ) == 0 ;
}
static inline int
F_36 ( struct V_1 * V_1 , const struct V_55 * V_56 )
{
return ( V_56 -> V_57 & F_37 ( V_1 ) ) == 0 ;
}
static inline void
F_38 ( struct V_1 * V_1 , struct V_55 * V_56 )
{
V_56 -> V_57 = F_35 ( V_1 ) ;
}
static inline void
F_39 ( struct V_1 * V_1 , struct V_55 * V_56 )
{
V_56 -> V_57 = F_37 ( V_1 ) ;
}
static inline void F_40 ( struct V_1 * V_1 , struct V_55 * V_56 )
{
V_56 -> V_57 &= ~ F_37 ( V_1 ) ;
}
static int
F_41 ( struct V_13 * V_14 , struct V_55 * V_56 )
{
if ( F_36 ( V_14 -> V_1 , V_56 ) ) {
F_39 ( V_14 -> V_1 , V_56 ) ;
V_14 -> V_22 -> V_54 -- ;
return 0 ;
}
return - V_58 ;
}
static struct V_30 * F_42 ( struct V_13 * V_14 , int V_31 ,
struct V_55 * V_56 )
{
struct V_30 * V_33 ;
V_33 = F_18 ( V_14 , V_31 , sizeof( struct V_59 ) ) ;
if ( V_33 == NULL )
return NULL ;
V_59 ( V_33 ) = V_56 ;
F_30 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_47 ) ;
return V_33 ;
}
static int F_43 ( struct V_13 * V_14 , struct V_55 * V_56 )
{
struct V_30 * V_33 ;
int V_48 ;
V_33 = F_42 ( V_14 , V_60 , V_56 ) ;
if ( V_33 == NULL )
return - V_44 ;
V_48 = F_41 ( V_14 , V_56 ) ;
if ( V_48 < 0 ) {
F_20 ( V_33 ) ;
return V_48 ;
}
return 0 ;
}
static int F_44 ( struct V_13 * V_14 )
{
struct V_55 * V_56 ;
int V_48 ;
F_9 (rule, &ctx->chain->rules, list) {
V_48 = F_43 ( V_14 , V_56 ) ;
if ( V_48 < 0 )
return V_48 ;
}
return 0 ;
}
static int F_45 ( struct V_13 * V_14 , int V_31 ,
struct V_61 * V_62 )
{
struct V_30 * V_33 ;
V_33 = F_18 ( V_14 , V_31 , sizeof( struct V_63 ) ) ;
if ( V_33 == NULL )
return - V_44 ;
if ( V_31 == V_64 && V_14 -> V_24 [ V_65 ] != NULL ) {
F_46 ( V_33 ) =
F_47 ( F_48 ( V_14 -> V_24 [ V_65 ] ) ) ;
V_62 -> V_38 |= V_66 ;
}
V_63 ( V_33 ) = V_62 ;
F_30 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_47 ) ;
return 0 ;
}
static int F_49 ( struct V_13 * V_14 , struct V_61 * V_62 )
{
int V_48 ;
V_48 = F_45 ( V_14 , V_67 , V_62 ) ;
if ( V_48 < 0 )
return V_48 ;
F_7 ( & V_62 -> V_6 ) ;
V_14 -> V_20 -> V_54 -- ;
return V_48 ;
}
static struct V_19 * F_50 ( const struct V_2 * V_3 ,
const struct V_23 * V_24 )
{
struct V_19 * V_20 ;
F_9 (table, &afi->tables, list) {
if ( ! F_51 ( V_24 , V_20 -> V_68 ) )
return V_20 ;
}
return NULL ;
}
static struct V_19 * F_52 ( const struct V_2 * V_3 ,
const struct V_23 * V_24 )
{
struct V_19 * V_20 ;
if ( V_24 == NULL )
return F_13 ( - V_69 ) ;
V_20 = F_50 ( V_3 , V_24 ) ;
if ( V_20 != NULL )
return V_20 ;
return F_13 ( - V_58 ) ;
}
static inline T_2 F_53 ( struct V_19 * V_20 )
{
return ++ V_20 -> V_70 ;
}
static const struct V_71 *
F_54 ( int V_9 , const struct V_23 * V_24 )
{
int V_72 ;
for ( V_72 = 0 ; V_72 < V_73 ; V_72 ++ ) {
if ( V_74 [ V_9 ] [ V_72 ] != NULL &&
! F_51 ( V_24 , V_74 [ V_9 ] [ V_72 ] -> V_68 ) )
return V_74 [ V_9 ] [ V_72 ] ;
}
return NULL ;
}
static const struct V_71 *
F_55 ( const struct V_2 * V_3 ,
const struct V_23 * V_24 ,
bool V_10 )
{
const struct V_71 * type ;
type = F_54 ( V_3 -> V_9 , V_24 ) ;
if ( type != NULL )
return type ;
#ifdef F_11
if ( V_10 ) {
F_5 ( V_5 ) ;
F_12 ( L_2 , V_3 -> V_9 ,
F_56 ( V_24 ) , ( const char * ) F_57 ( V_24 ) ) ;
F_3 ( V_5 ) ;
type = F_54 ( V_3 -> V_9 , V_24 ) ;
if ( type != NULL )
return F_13 ( - V_11 ) ;
}
#endif
return F_13 ( - V_58 ) ;
}
static int F_58 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_26 , T_1 V_28 , int V_75 , T_1 V_38 ,
int V_9 , const struct V_19 * V_20 )
{
struct V_17 * V_18 ;
struct V_76 * V_77 ;
V_75 |= V_5 << 8 ;
V_18 = F_59 ( V_16 , V_26 , V_28 , V_75 , sizeof( struct V_76 ) , V_38 ) ;
if ( V_18 == NULL )
goto V_78;
V_77 = F_60 ( V_18 ) ;
V_77 -> V_79 = V_9 ;
V_77 -> V_80 = V_81 ;
V_77 -> V_82 = F_61 ( V_1 -> V_7 . V_83 & 0xffff ) ;
if ( F_62 ( V_16 , V_84 , V_20 -> V_68 ) ||
F_63 ( V_16 , V_85 , F_64 ( V_20 -> V_38 ) ) ||
F_63 ( V_16 , V_86 , F_64 ( V_20 -> V_54 ) ) )
goto V_78;
F_65 ( V_16 , V_18 ) ;
return 0 ;
V_78:
F_66 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_67 ( const struct V_13 * V_14 , int V_75 )
{
struct V_15 * V_16 ;
int V_48 ;
if ( ! V_14 -> V_27 &&
! F_68 ( V_14 -> V_1 , V_87 ) )
return 0 ;
V_48 = - V_88 ;
V_16 = F_69 ( V_89 , V_34 ) ;
if ( V_16 == NULL )
goto V_48;
V_48 = F_58 ( V_16 , V_14 -> V_1 , V_14 -> V_26 , V_14 -> V_28 ,
V_75 , 0 , V_14 -> V_3 -> V_9 , V_14 -> V_20 ) ;
if ( V_48 < 0 ) {
F_70 ( V_16 ) ;
goto V_48;
}
V_48 = F_71 ( V_16 , V_14 -> V_1 , V_14 -> V_26 , V_87 ,
V_14 -> V_27 , V_34 ) ;
V_48:
if ( V_48 < 0 ) {
F_72 ( V_14 -> V_1 , V_14 -> V_26 , V_87 ,
V_48 ) ;
}
return V_48 ;
}
static int F_73 ( struct V_15 * V_16 ,
struct V_90 * V_91 )
{
const struct V_76 * V_77 = F_60 ( V_91 -> V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
unsigned int V_92 = 0 , V_93 = V_91 -> args [ 0 ] ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_77 -> V_79 ;
F_74 () ;
V_91 -> V_28 = V_1 -> V_7 . V_83 ;
F_75 (afi, &net->nft.af_info, list) {
if ( V_9 != V_94 && V_9 != V_3 -> V_9 )
continue;
F_75 (table, &afi->tables, list) {
if ( V_92 < V_93 )
goto V_95;
if ( V_92 > V_93 )
memset ( & V_91 -> args [ 1 ] , 0 ,
sizeof( V_91 -> args ) - sizeof( V_91 -> args [ 0 ] ) ) ;
if ( F_58 ( V_16 , V_1 ,
F_16 ( V_91 -> V_16 ) . V_26 ,
V_91 -> V_18 -> V_29 ,
V_45 ,
V_96 ,
V_3 -> V_9 , V_20 ) < 0 )
goto V_97;
F_76 ( V_91 , F_77 ( V_16 ) ) ;
V_95:
V_92 ++ ;
}
}
V_97:
F_78 () ;
V_91 -> args [ 0 ] = V_92 ;
return V_16 -> V_98 ;
}
static int F_79 ( struct V_99 * V_100 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_60 ( V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
struct V_15 * V_101 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_77 -> V_79 ;
int V_48 ;
if ( V_18 -> V_102 & V_103 ) {
struct V_104 V_105 = {
. V_106 = F_73 ,
} ;
return F_80 ( V_100 , V_16 , V_18 , & V_105 ) ;
}
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_81 ( V_3 ) )
return F_82 ( V_3 ) ;
V_20 = F_52 ( V_3 , V_24 [ V_84 ] ) ;
if ( F_81 ( V_20 ) )
return F_82 ( V_20 ) ;
if ( V_20 -> V_38 & V_46 )
return - V_58 ;
V_101 = F_83 ( V_89 , V_34 ) ;
if ( ! V_101 )
return - V_44 ;
V_48 = F_58 ( V_101 , V_1 , F_16 ( V_16 ) . V_26 ,
V_18 -> V_29 , V_45 , 0 ,
V_9 , V_20 ) ;
if ( V_48 < 0 )
goto V_48;
return F_84 ( V_100 , V_101 , F_16 ( V_16 ) . V_26 ) ;
V_48:
F_70 ( V_101 ) ;
return V_48 ;
}
static int F_85 ( const struct V_2 * V_3 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 ;
int V_48 , V_72 = 0 ;
F_9 (chain, &table->chains, list) {
if ( ! ( V_22 -> V_38 & V_42 ) )
continue;
V_48 = F_23 ( V_35 ( V_22 ) , V_3 -> V_107 ) ;
if ( V_48 < 0 )
goto V_48;
V_72 ++ ;
}
return 0 ;
V_48:
F_9 (chain, &table->chains, list) {
if ( ! ( V_22 -> V_38 & V_42 ) )
continue;
if ( V_72 -- <= 0 )
break;
F_25 ( V_35 ( V_22 ) , V_3 -> V_107 ) ;
}
return V_48 ;
}
static void F_86 ( const struct V_2 * V_3 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 ;
F_9 (chain, &table->chains, list) {
if ( V_22 -> V_38 & V_42 )
F_25 ( V_35 ( V_22 ) ,
V_3 -> V_107 ) ;
}
}
static int F_87 ( struct V_13 * V_14 )
{
struct V_30 * V_33 ;
T_1 V_38 ;
int V_108 = 0 ;
if ( ! V_14 -> V_24 [ V_85 ] )
return 0 ;
V_38 = F_47 ( F_48 ( V_14 -> V_24 [ V_85 ] ) ) ;
if ( V_38 & ~ V_41 )
return - V_69 ;
if ( V_38 == V_14 -> V_20 -> V_38 )
return 0 ;
V_33 = F_18 ( V_14 , V_45 ,
sizeof( struct V_43 ) ) ;
if ( V_33 == NULL )
return - V_44 ;
if ( ( V_38 & V_41 ) &&
! ( V_14 -> V_20 -> V_38 & V_41 ) ) {
F_88 ( V_33 ) = false ;
} else if ( ! ( V_38 & V_41 ) &&
V_14 -> V_20 -> V_38 & V_41 ) {
V_108 = F_85 ( V_14 -> V_3 , V_14 -> V_20 ) ;
if ( V_108 >= 0 ) {
V_14 -> V_20 -> V_38 &= ~ V_41 ;
F_88 ( V_33 ) = true ;
}
}
if ( V_108 < 0 )
goto V_48;
F_89 ( V_33 ) = true ;
F_30 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_47 ) ;
return 0 ;
V_48:
F_20 ( V_33 ) ;
return V_108 ;
}
static int F_90 ( struct V_99 * V_100 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_60 ( V_18 ) ;
const struct V_23 * V_68 ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_77 -> V_79 ;
T_1 V_38 = 0 ;
struct V_13 V_14 ;
int V_48 ;
V_3 = F_10 ( V_1 , V_9 , true ) ;
if ( F_81 ( V_3 ) )
return F_82 ( V_3 ) ;
V_68 = V_24 [ V_84 ] ;
V_20 = F_52 ( V_3 , V_68 ) ;
if ( F_81 ( V_20 ) ) {
if ( F_82 ( V_20 ) != - V_58 )
return F_82 ( V_20 ) ;
V_20 = NULL ;
}
if ( V_20 != NULL ) {
if ( V_20 -> V_38 & V_46 )
return - V_58 ;
if ( V_18 -> V_102 & V_109 )
return - V_110 ;
if ( V_18 -> V_102 & V_111 )
return - V_112 ;
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return F_87 ( & V_14 ) ;
}
if ( V_24 [ V_85 ] ) {
V_38 = F_47 ( F_48 ( V_24 [ V_85 ] ) ) ;
if ( V_38 & ~ V_41 )
return - V_69 ;
}
V_48 = - V_12 ;
if ( ! F_91 ( V_3 -> V_113 ) )
goto V_114;
V_48 = - V_44 ;
V_20 = F_19 ( sizeof( * V_20 ) , V_34 ) ;
if ( V_20 == NULL )
goto V_115;
F_92 ( V_20 -> V_68 , V_68 , V_116 ) ;
F_2 ( & V_20 -> V_117 ) ;
F_2 ( & V_20 -> V_118 ) ;
V_20 -> V_38 = V_38 ;
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
V_48 = F_29 ( & V_14 , V_45 ) ;
if ( V_48 < 0 )
goto V_119;
F_4 ( & V_20 -> V_6 , & V_3 -> V_4 ) ;
return 0 ;
V_119:
F_22 ( V_20 ) ;
V_115:
F_93 ( V_3 -> V_113 ) ;
V_114:
return V_48 ;
}
static int F_94 ( struct V_13 * V_14 )
{
int V_48 ;
struct V_21 * V_22 , * V_120 ;
struct V_61 * V_62 , * V_121 ;
F_9 (chain, &ctx->table->chains, list) {
V_14 -> V_22 = V_22 ;
V_48 = F_44 ( V_14 ) ;
if ( V_48 < 0 )
goto V_122;
}
F_95 (set, ns, &ctx->table->sets, list) {
if ( V_62 -> V_38 & V_123 &&
! F_96 ( & V_62 -> V_124 ) )
continue;
V_48 = F_49 ( V_14 , V_62 ) ;
if ( V_48 < 0 )
goto V_122;
}
F_95 (chain, nc, &ctx->table->chains, list) {
V_14 -> V_22 = V_22 ;
V_48 = F_33 ( V_14 ) ;
if ( V_48 < 0 )
goto V_122;
}
V_48 = F_31 ( V_14 ) ;
V_122:
return V_48 ;
}
static int F_97 ( struct V_13 * V_14 , int V_9 )
{
struct V_2 * V_3 ;
struct V_19 * V_20 , * V_125 ;
const struct V_23 * const * V_24 = V_14 -> V_24 ;
int V_48 = 0 ;
F_9 (afi, &ctx->net->nft.af_info, list) {
if ( V_9 != V_126 && V_3 -> V_9 != V_9 )
continue;
V_14 -> V_3 = V_3 ;
F_95 (table, nt, &afi->tables, list) {
if ( V_24 [ V_84 ] &&
F_51 ( V_24 [ V_84 ] , V_20 -> V_68 ) != 0 )
continue;
V_14 -> V_20 = V_20 ;
V_48 = F_94 ( V_14 ) ;
if ( V_48 < 0 )
goto V_122;
}
}
V_122:
return V_48 ;
}
static int F_98 ( struct V_99 * V_100 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_60 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_77 -> V_79 ;
struct V_13 V_14 ;
F_14 ( & V_14 , V_16 , V_18 , NULL , NULL , NULL , V_24 ) ;
if ( V_9 == V_126 || V_24 [ V_84 ] == NULL )
return F_97 ( & V_14 , V_9 ) ;
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_81 ( V_3 ) )
return F_82 ( V_3 ) ;
V_20 = F_52 ( V_3 , V_24 [ V_84 ] ) ;
if ( F_81 ( V_20 ) )
return F_82 ( V_20 ) ;
if ( V_20 -> V_38 & V_46 )
return - V_58 ;
V_14 . V_3 = V_3 ;
V_14 . V_20 = V_20 ;
return F_94 ( & V_14 ) ;
}
static void F_99 ( struct V_13 * V_14 )
{
F_100 ( V_14 -> V_20 -> V_54 > 0 ) ;
F_22 ( V_14 -> V_20 ) ;
F_93 ( V_14 -> V_3 -> V_113 ) ;
}
int F_101 ( const struct V_71 * V_127 )
{
int V_48 = 0 ;
F_3 ( V_5 ) ;
if ( V_74 [ V_127 -> V_9 ] [ V_127 -> type ] != NULL ) {
V_48 = - V_128 ;
goto V_122;
}
V_74 [ V_127 -> V_9 ] [ V_127 -> type ] = V_127 ;
V_122:
F_5 ( V_5 ) ;
return V_48 ;
}
void F_102 ( const struct V_71 * V_127 )
{
F_3 ( V_5 ) ;
V_74 [ V_127 -> V_9 ] [ V_127 -> type ] = NULL ;
F_5 ( V_5 ) ;
}
static struct V_21 *
F_103 ( const struct V_19 * V_20 , T_2 V_129 )
{
struct V_21 * V_22 ;
F_9 (chain, &table->chains, list) {
if ( V_22 -> V_129 == V_129 )
return V_22 ;
}
return F_13 ( - V_58 ) ;
}
static struct V_21 * F_104 ( const struct V_19 * V_20 ,
const struct V_23 * V_24 )
{
struct V_21 * V_22 ;
if ( V_24 == NULL )
return F_13 ( - V_69 ) ;
F_9 (chain, &table->chains, list) {
if ( ! F_51 ( V_24 , V_22 -> V_68 ) )
return V_22 ;
}
return F_13 ( - V_58 ) ;
}
static int F_105 ( struct V_15 * V_16 , struct V_130 T_3 * V_131 )
{
struct V_130 * V_132 , V_133 ;
struct V_23 * V_134 ;
unsigned int V_28 ;
T_2 V_135 , V_136 ;
int V_137 ;
memset ( & V_133 , 0 , sizeof( V_133 ) ) ;
F_106 (cpu) {
V_132 = F_107 ( V_131 , V_137 ) ;
do {
V_28 = F_108 ( & V_132 -> V_138 ) ;
V_135 = V_132 -> V_135 ;
V_136 = V_132 -> V_136 ;
} while ( F_109 ( & V_132 -> V_138 , V_28 ) );
V_133 . V_135 += V_135 ;
V_133 . V_136 += V_136 ;
}
V_134 = F_110 ( V_16 , V_139 ) ;
if ( V_134 == NULL )
goto V_78;
if ( F_111 ( V_16 , V_140 , F_112 ( V_133 . V_135 ) ) ||
F_111 ( V_16 , V_141 , F_112 ( V_133 . V_136 ) ) )
goto V_78;
F_113 ( V_16 , V_134 ) ;
return 0 ;
V_78:
return - V_142 ;
}
static int F_114 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_26 , T_1 V_28 , int V_75 , T_1 V_38 ,
int V_9 , const struct V_19 * V_20 ,
const struct V_21 * V_22 )
{
struct V_17 * V_18 ;
struct V_76 * V_77 ;
V_75 |= V_5 << 8 ;
V_18 = F_59 ( V_16 , V_26 , V_28 , V_75 , sizeof( struct V_76 ) , V_38 ) ;
if ( V_18 == NULL )
goto V_78;
V_77 = F_60 ( V_18 ) ;
V_77 -> V_79 = V_9 ;
V_77 -> V_80 = V_81 ;
V_77 -> V_82 = F_61 ( V_1 -> V_7 . V_83 & 0xffff ) ;
if ( F_62 ( V_16 , V_143 , V_20 -> V_68 ) )
goto V_78;
if ( F_111 ( V_16 , V_144 , F_112 ( V_22 -> V_129 ) ) )
goto V_78;
if ( F_62 ( V_16 , V_145 , V_22 -> V_68 ) )
goto V_78;
if ( V_22 -> V_38 & V_42 ) {
const struct V_35 * V_36 = V_35 ( V_22 ) ;
const struct V_146 * V_40 = & V_36 -> V_40 [ 0 ] ;
struct V_23 * V_134 ;
V_134 = F_110 ( V_16 , V_147 ) ;
if ( V_134 == NULL )
goto V_78;
if ( F_63 ( V_16 , V_148 , F_64 ( V_40 -> V_149 ) ) )
goto V_78;
if ( F_63 ( V_16 , V_150 , F_64 ( V_40 -> V_151 ) ) )
goto V_78;
if ( V_36 -> V_152 [ 0 ] &&
F_62 ( V_16 , V_153 , V_36 -> V_152 ) )
goto V_78;
F_113 ( V_16 , V_134 ) ;
if ( F_63 ( V_16 , V_154 ,
F_64 ( V_36 -> V_155 ) ) )
goto V_78;
if ( F_62 ( V_16 , V_156 , V_36 -> type -> V_68 ) )
goto V_78;
if ( F_105 ( V_16 , V_35 ( V_22 ) -> V_131 ) )
goto V_78;
}
if ( F_63 ( V_16 , V_157 , F_64 ( V_22 -> V_54 ) ) )
goto V_78;
F_65 ( V_16 , V_18 ) ;
return 0 ;
V_78:
F_66 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_115 ( const struct V_13 * V_14 , int V_75 )
{
struct V_15 * V_16 ;
int V_48 ;
if ( ! V_14 -> V_27 &&
! F_68 ( V_14 -> V_1 , V_87 ) )
return 0 ;
V_48 = - V_88 ;
V_16 = F_69 ( V_89 , V_34 ) ;
if ( V_16 == NULL )
goto V_48;
V_48 = F_114 ( V_16 , V_14 -> V_1 , V_14 -> V_26 , V_14 -> V_28 ,
V_75 , 0 , V_14 -> V_3 -> V_9 , V_14 -> V_20 ,
V_14 -> V_22 ) ;
if ( V_48 < 0 ) {
F_70 ( V_16 ) ;
goto V_48;
}
V_48 = F_71 ( V_16 , V_14 -> V_1 , V_14 -> V_26 , V_87 ,
V_14 -> V_27 , V_34 ) ;
V_48:
if ( V_48 < 0 ) {
F_72 ( V_14 -> V_1 , V_14 -> V_26 , V_87 ,
V_48 ) ;
}
return V_48 ;
}
static int F_116 ( struct V_15 * V_16 ,
struct V_90 * V_91 )
{
const struct V_76 * V_77 = F_60 ( V_91 -> V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
unsigned int V_92 = 0 , V_93 = V_91 -> args [ 0 ] ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_77 -> V_79 ;
F_74 () ;
V_91 -> V_28 = V_1 -> V_7 . V_83 ;
F_75 (afi, &net->nft.af_info, list) {
if ( V_9 != V_94 && V_9 != V_3 -> V_9 )
continue;
F_75 (table, &afi->tables, list) {
F_75 (chain, &table->chains, list) {
if ( V_92 < V_93 )
goto V_95;
if ( V_92 > V_93 )
memset ( & V_91 -> args [ 1 ] , 0 ,
sizeof( V_91 -> args ) - sizeof( V_91 -> args [ 0 ] ) ) ;
if ( F_114 ( V_16 , V_1 ,
F_16 ( V_91 -> V_16 ) . V_26 ,
V_91 -> V_18 -> V_29 ,
V_51 ,
V_96 ,
V_3 -> V_9 , V_20 , V_22 ) < 0 )
goto V_97;
F_76 ( V_91 , F_77 ( V_16 ) ) ;
V_95:
V_92 ++ ;
}
}
}
V_97:
F_78 () ;
V_91 -> args [ 0 ] = V_92 ;
return V_16 -> V_98 ;
}
static int F_117 ( struct V_99 * V_100 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_60 ( V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
struct V_15 * V_101 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_77 -> V_79 ;
int V_48 ;
if ( V_18 -> V_102 & V_103 ) {
struct V_104 V_105 = {
. V_106 = F_116 ,
} ;
return F_80 ( V_100 , V_16 , V_18 , & V_105 ) ;
}
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_81 ( V_3 ) )
return F_82 ( V_3 ) ;
V_20 = F_52 ( V_3 , V_24 [ V_143 ] ) ;
if ( F_81 ( V_20 ) )
return F_82 ( V_20 ) ;
if ( V_20 -> V_38 & V_46 )
return - V_58 ;
V_22 = F_104 ( V_20 , V_24 [ V_145 ] ) ;
if ( F_81 ( V_22 ) )
return F_82 ( V_22 ) ;
if ( V_22 -> V_38 & V_52 )
return - V_58 ;
V_101 = F_83 ( V_89 , V_34 ) ;
if ( ! V_101 )
return - V_44 ;
V_48 = F_114 ( V_101 , V_1 , F_16 ( V_16 ) . V_26 ,
V_18 -> V_29 , V_51 , 0 ,
V_9 , V_20 , V_22 ) ;
if ( V_48 < 0 )
goto V_48;
return F_84 ( V_100 , V_101 , F_16 ( V_16 ) . V_26 ) ;
V_48:
F_70 ( V_101 ) ;
return V_48 ;
}
static struct V_130 T_3 * F_118 ( const struct V_23 * V_158 )
{
struct V_23 * V_159 [ V_160 + 1 ] ;
struct V_130 T_3 * V_161 ;
struct V_130 * V_131 ;
int V_48 ;
V_48 = F_119 ( V_159 , V_160 , V_158 , V_162 ) ;
if ( V_48 < 0 )
return F_13 ( V_48 ) ;
if ( ! V_159 [ V_141 ] || ! V_159 [ V_140 ] )
return F_13 ( - V_69 ) ;
V_161 = F_120 ( struct V_130 ) ;
if ( V_161 == NULL )
return F_13 ( - V_44 ) ;
F_121 () ;
V_131 = F_122 ( V_161 ) ;
V_131 -> V_136 = F_123 ( F_124 ( V_159 [ V_141 ] ) ) ;
V_131 -> V_135 = F_123 ( F_124 ( V_159 [ V_140 ] ) ) ;
F_125 () ;
return V_161 ;
}
static void F_126 ( struct V_35 * V_22 ,
struct V_130 T_3 * V_161 )
{
if ( V_161 == NULL )
return;
if ( V_22 -> V_131 ) {
struct V_130 T_3 * V_163 =
F_127 ( V_22 -> V_131 ) ;
F_128 ( V_22 -> V_131 , V_161 ) ;
F_129 () ;
F_130 ( V_163 ) ;
} else
F_128 ( V_22 -> V_131 , V_161 ) ;
}
static void F_131 ( struct V_21 * V_22 )
{
F_100 ( V_22 -> V_54 > 0 ) ;
if ( V_22 -> V_38 & V_42 ) {
struct V_35 * V_36 = V_35 ( V_22 ) ;
F_93 ( V_36 -> type -> V_113 ) ;
F_130 ( V_36 -> V_131 ) ;
if ( V_36 -> V_40 [ 0 ] . V_164 != NULL )
F_132 ( V_36 -> V_40 [ 0 ] . V_164 ) ;
F_22 ( V_36 ) ;
} else {
F_22 ( V_22 ) ;
}
}
static int F_133 ( struct V_99 * V_100 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_60 ( V_18 ) ;
const struct V_23 * V_165 ( V_68 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_35 * V_36 = NULL ;
struct V_23 * V_166 [ V_167 + 1 ] ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_77 -> V_79 ;
struct V_168 * V_164 = NULL ;
T_4 V_155 = V_169 ;
T_2 V_129 = 0 ;
unsigned int V_72 ;
struct V_130 T_3 * V_131 ;
int V_48 ;
bool V_170 ;
struct V_13 V_14 ;
V_170 = V_18 -> V_102 & V_171 ? true : false ;
V_3 = F_10 ( V_1 , V_9 , true ) ;
if ( F_81 ( V_3 ) )
return F_82 ( V_3 ) ;
V_20 = F_52 ( V_3 , V_24 [ V_143 ] ) ;
if ( F_81 ( V_20 ) )
return F_82 ( V_20 ) ;
V_22 = NULL ;
V_68 = V_24 [ V_145 ] ;
if ( V_24 [ V_144 ] ) {
V_129 = F_123 ( F_124 ( V_24 [ V_144 ] ) ) ;
V_22 = F_103 ( V_20 , V_129 ) ;
if ( F_81 ( V_22 ) )
return F_82 ( V_22 ) ;
} else {
V_22 = F_104 ( V_20 , V_68 ) ;
if ( F_81 ( V_22 ) ) {
if ( F_82 ( V_22 ) != - V_58 )
return F_82 ( V_22 ) ;
V_22 = NULL ;
}
}
if ( V_24 [ V_154 ] ) {
if ( ( V_22 != NULL &&
! ( V_22 -> V_38 & V_42 ) ) )
return - V_112 ;
if ( V_22 == NULL &&
V_24 [ V_147 ] == NULL )
return - V_112 ;
V_155 = F_47 ( F_48 ( V_24 [ V_154 ] ) ) ;
switch ( V_155 ) {
case V_172 :
case V_169 :
break;
default:
return - V_69 ;
}
}
if ( V_22 != NULL ) {
struct V_130 * V_131 = NULL ;
struct V_30 * V_33 ;
if ( V_22 -> V_38 & V_52 )
return - V_58 ;
if ( V_18 -> V_102 & V_109 )
return - V_110 ;
if ( V_18 -> V_102 & V_111 )
return - V_112 ;
if ( V_24 [ V_144 ] && V_68 &&
! F_81 ( F_104 ( V_20 , V_24 [ V_145 ] ) ) )
return - V_110 ;
if ( V_24 [ V_139 ] ) {
if ( ! ( V_22 -> V_38 & V_42 ) )
return - V_112 ;
V_131 = F_118 ( V_24 [ V_139 ] ) ;
if ( F_81 ( V_131 ) )
return F_82 ( V_131 ) ;
}
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_33 = F_18 ( & V_14 , V_51 ,
sizeof( struct V_50 ) ) ;
if ( V_33 == NULL ) {
F_130 ( V_131 ) ;
return - V_44 ;
}
F_134 ( V_33 ) = V_131 ;
F_135 ( V_33 ) = true ;
if ( V_24 [ V_154 ] )
F_136 ( V_33 ) = V_155 ;
else
F_136 ( V_33 ) = - 1 ;
if ( V_24 [ V_144 ] && V_68 ) {
F_92 ( F_137 ( V_33 ) , V_68 ,
V_173 ) ;
}
F_30 ( & V_33 -> V_6 , & V_1 -> V_7 . V_47 ) ;
return 0 ;
}
if ( V_20 -> V_54 == V_174 )
return - V_175 ;
if ( V_24 [ V_147 ] ) {
const struct V_71 * type ;
struct V_146 * V_40 ;
T_5 * V_176 ;
T_1 V_149 , V_151 ;
type = V_74 [ V_9 ] [ V_177 ] ;
if ( V_24 [ V_156 ] ) {
type = F_55 ( V_3 ,
V_24 [ V_156 ] ,
V_170 ) ;
if ( F_81 ( type ) )
return F_82 ( type ) ;
}
V_48 = F_119 ( V_166 , V_167 , V_24 [ V_147 ] ,
V_178 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_166 [ V_148 ] == NULL ||
V_166 [ V_150 ] == NULL )
return - V_69 ;
V_149 = F_47 ( F_48 ( V_166 [ V_148 ] ) ) ;
if ( V_149 >= V_3 -> V_179 )
return - V_69 ;
V_151 = F_47 ( F_48 ( V_166 [ V_150 ] ) ) ;
if ( ! ( type -> V_180 & ( 1 << V_149 ) ) )
return - V_112 ;
if ( ! F_91 ( type -> V_113 ) )
return - V_58 ;
V_176 = type -> V_181 [ V_149 ] ;
if ( V_3 -> V_38 & V_182 ) {
char V_183 [ V_184 ] ;
if ( ! V_166 [ V_153 ] ) {
F_93 ( type -> V_113 ) ;
return - V_112 ;
}
F_92 ( V_183 , V_166 [ V_153 ] , V_184 ) ;
V_164 = F_138 ( V_1 , V_183 ) ;
if ( ! V_164 ) {
F_93 ( type -> V_113 ) ;
return - V_58 ;
}
} else if ( V_166 [ V_153 ] ) {
F_93 ( type -> V_113 ) ;
return - V_112 ;
}
V_36 = F_19 ( sizeof( * V_36 ) , V_34 ) ;
if ( V_36 == NULL ) {
F_93 ( type -> V_113 ) ;
if ( V_164 != NULL )
F_132 ( V_164 ) ;
return - V_44 ;
}
if ( V_164 != NULL )
strncpy ( V_36 -> V_152 , V_164 -> V_68 , V_184 ) ;
if ( V_24 [ V_139 ] ) {
V_131 = F_118 ( V_24 [ V_139 ] ) ;
if ( F_81 ( V_131 ) ) {
F_93 ( type -> V_113 ) ;
F_22 ( V_36 ) ;
if ( V_164 != NULL )
F_132 ( V_164 ) ;
return F_82 ( V_131 ) ;
}
V_36 -> V_131 = V_131 ;
} else {
V_131 = F_120 ( struct V_130 ) ;
if ( V_131 == NULL ) {
F_93 ( type -> V_113 ) ;
F_22 ( V_36 ) ;
if ( V_164 != NULL )
F_132 ( V_164 ) ;
return - V_44 ;
}
F_128 ( V_36 -> V_131 , V_131 ) ;
}
F_139 ( & V_36 -> V_185 , V_1 ) ;
V_36 -> type = type ;
V_22 = & V_36 -> V_22 ;
for ( V_72 = 0 ; V_72 < V_3 -> V_107 ; V_72 ++ ) {
V_40 = & V_36 -> V_40 [ V_72 ] ;
V_40 -> V_186 = V_9 ;
V_40 -> V_113 = V_3 -> V_113 ;
V_40 -> V_149 = V_149 ;
V_40 -> V_151 = V_151 ;
V_40 -> V_187 = V_22 ;
V_40 -> V_188 = V_3 -> V_181 [ V_40 -> V_149 ] ;
V_40 -> V_164 = V_164 ;
if ( V_176 )
V_40 -> V_188 = V_176 ;
if ( V_3 -> V_189 )
V_3 -> V_189 ( V_40 , V_72 ) ;
}
V_22 -> V_38 |= V_42 ;
V_36 -> V_155 = V_155 ;
} else {
V_22 = F_19 ( sizeof( * V_22 ) , V_34 ) ;
if ( V_22 == NULL )
return - V_44 ;
}
F_2 ( & V_22 -> V_190 ) ;
V_22 -> V_129 = F_53 ( V_20 ) ;
V_22 -> V_20 = V_20 ;
F_92 ( V_22 -> V_68 , V_68 , V_173 ) ;
V_48 = F_27 ( V_20 , V_22 , V_3 -> V_107 ) ;
if ( V_48 < 0 )
goto V_114;
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_48 = F_32 ( & V_14 , V_51 ) ;
if ( V_48 < 0 )
goto V_115;
V_20 -> V_54 ++ ;
F_4 ( & V_22 -> V_6 , & V_20 -> V_117 ) ;
return 0 ;
V_115:
F_28 ( V_20 , V_22 , V_3 -> V_107 ) ;
V_114:
F_131 ( V_22 ) ;
return V_48 ;
}
static int F_140 ( struct V_99 * V_100 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_60 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_77 -> V_79 ;
struct V_13 V_14 ;
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_81 ( V_3 ) )
return F_82 ( V_3 ) ;
V_20 = F_52 ( V_3 , V_24 [ V_143 ] ) ;
if ( F_81 ( V_20 ) )
return F_82 ( V_20 ) ;
if ( V_20 -> V_38 & V_46 )
return - V_58 ;
V_22 = F_104 ( V_20 , V_24 [ V_145 ] ) ;
if ( F_81 ( V_22 ) )
return F_82 ( V_22 ) ;
if ( V_22 -> V_38 & V_52 )
return - V_58 ;
if ( V_22 -> V_54 > 0 )
return - V_128 ;
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
return F_33 ( & V_14 ) ;
}
int F_141 ( struct V_191 * type )
{
F_3 ( V_5 ) ;
if ( type -> V_9 == V_94 )
F_4 ( & type -> V_6 , & V_192 ) ;
else
F_142 ( & type -> V_6 , & V_192 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_143 ( struct V_191 * type )
{
F_3 ( V_5 ) ;
F_7 ( & type -> V_6 ) ;
F_5 ( V_5 ) ;
}
static const struct V_191 * F_144 ( T_4 V_9 ,
struct V_23 * V_24 )
{
const struct V_191 * type ;
F_9 (type, &nf_tables_expressions, list) {
if ( ! F_51 ( V_24 , type -> V_68 ) &&
( ! type -> V_9 || type -> V_9 == V_9 ) )
return type ;
}
return NULL ;
}
static const struct V_191 * F_145 ( T_4 V_9 ,
struct V_23 * V_24 )
{
const struct V_191 * type ;
if ( V_24 == NULL )
return F_13 ( - V_69 ) ;
type = F_144 ( V_9 , V_24 ) ;
if ( type != NULL && F_91 ( type -> V_113 ) )
return type ;
#ifdef F_11
if ( type == NULL ) {
F_5 ( V_5 ) ;
F_12 ( L_3 , V_9 ,
F_56 ( V_24 ) , ( char * ) F_57 ( V_24 ) ) ;
F_3 ( V_5 ) ;
if ( F_144 ( V_9 , V_24 ) )
return F_13 ( - V_11 ) ;
F_5 ( V_5 ) ;
F_12 ( L_4 ,
F_56 ( V_24 ) , ( char * ) F_57 ( V_24 ) ) ;
F_3 ( V_5 ) ;
if ( F_144 ( V_9 , V_24 ) )
return F_13 ( - V_11 ) ;
}
#endif
return F_13 ( - V_58 ) ;
}
static int F_146 ( struct V_15 * V_16 ,
const struct V_193 * V_194 )
{
if ( F_62 ( V_16 , V_195 , V_194 -> V_40 -> type -> V_68 ) )
goto V_78;
if ( V_194 -> V_40 -> V_106 ) {
struct V_23 * V_196 = F_110 ( V_16 , V_197 ) ;
if ( V_196 == NULL )
goto V_78;
if ( V_194 -> V_40 -> V_106 ( V_16 , V_194 ) < 0 )
goto V_78;
F_113 ( V_16 , V_196 ) ;
}
return V_16 -> V_98 ;
V_78:
return - 1 ;
}
int F_147 ( struct V_15 * V_16 , unsigned int V_158 ,
const struct V_193 * V_194 )
{
struct V_23 * V_134 ;
V_134 = F_110 ( V_16 , V_158 ) ;
if ( ! V_134 )
goto V_78;
if ( F_146 ( V_16 , V_194 ) < 0 )
goto V_78;
F_113 ( V_16 , V_134 ) ;
return 0 ;
V_78:
return - 1 ;
}
static int F_148 ( const struct V_13 * V_14 ,
const struct V_23 * V_24 ,
struct V_198 * V_199 )
{
const struct V_191 * type ;
const struct V_200 * V_40 ;
struct V_23 * V_159 [ V_201 + 1 ] ;
int V_48 ;
V_48 = F_119 ( V_159 , V_201 , V_24 , V_202 ) ;
if ( V_48 < 0 )
return V_48 ;
type = F_145 ( V_14 -> V_3 -> V_9 , V_159 [ V_195 ] ) ;
if ( F_81 ( type ) )
return F_82 ( type ) ;
if ( V_159 [ V_197 ] ) {
V_48 = F_119 ( V_199 -> V_159 , type -> V_203 ,
V_159 [ V_197 ] , type -> V_155 ) ;
if ( V_48 < 0 )
goto V_114;
} else
memset ( V_199 -> V_159 , 0 , sizeof( V_199 -> V_159 [ 0 ] ) * ( type -> V_203 + 1 ) ) ;
if ( type -> V_204 != NULL ) {
V_40 = type -> V_204 ( V_14 ,
( const struct V_23 * const * ) V_199 -> V_159 ) ;
if ( F_81 ( V_40 ) ) {
V_48 = F_82 ( V_40 ) ;
goto V_114;
}
} else
V_40 = type -> V_40 ;
V_199 -> V_40 = V_40 ;
return 0 ;
V_114:
F_93 ( type -> V_113 ) ;
return V_48 ;
}
static int F_149 ( const struct V_13 * V_14 ,
const struct V_198 * V_199 ,
struct V_193 * V_194 )
{
const struct V_200 * V_40 = V_199 -> V_40 ;
int V_48 ;
V_194 -> V_40 = V_40 ;
if ( V_40 -> V_205 ) {
V_48 = V_40 -> V_205 ( V_14 , V_194 , ( const struct V_23 * * ) V_199 -> V_159 ) ;
if ( V_48 < 0 )
goto V_114;
}
return 0 ;
V_114:
V_194 -> V_40 = NULL ;
return V_48 ;
}
static void F_150 ( const struct V_13 * V_14 ,
struct V_193 * V_194 )
{
if ( V_194 -> V_40 -> V_206 )
V_194 -> V_40 -> V_206 ( V_14 , V_194 ) ;
F_93 ( V_194 -> V_40 -> type -> V_113 ) ;
}
struct V_193 * F_151 ( const struct V_13 * V_14 ,
const struct V_23 * V_24 )
{
struct V_198 V_199 ;
struct V_193 * V_194 ;
int V_48 ;
V_48 = F_148 ( V_14 , V_24 , & V_199 ) ;
if ( V_48 < 0 )
goto V_114;
V_48 = - V_44 ;
V_194 = F_19 ( V_199 . V_40 -> V_32 , V_34 ) ;
if ( V_194 == NULL )
goto V_115;
V_48 = F_149 ( V_14 , & V_199 , V_194 ) ;
if ( V_48 < 0 )
goto V_115;
return V_194 ;
V_115:
F_93 ( V_199 . V_40 -> type -> V_113 ) ;
V_114:
return F_13 ( V_48 ) ;
}
void F_152 ( const struct V_13 * V_14 , struct V_193 * V_194 )
{
F_150 ( V_14 , V_194 ) ;
F_22 ( V_194 ) ;
}
static struct V_55 * F_153 ( const struct V_21 * V_22 ,
T_2 V_129 )
{
struct V_55 * V_56 ;
F_9 (rule, &chain->rules, list) {
if ( V_129 == V_56 -> V_129 )
return V_56 ;
}
return F_13 ( - V_58 ) ;
}
static struct V_55 * F_154 ( const struct V_21 * V_22 ,
const struct V_23 * V_24 )
{
if ( V_24 == NULL )
return F_13 ( - V_69 ) ;
return F_153 ( V_22 , F_123 ( F_124 ( V_24 ) ) ) ;
}
static int F_155 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_26 , T_1 V_28 , int V_75 ,
T_1 V_38 , int V_9 ,
const struct V_19 * V_20 ,
const struct V_21 * V_22 ,
const struct V_55 * V_56 )
{
struct V_17 * V_18 ;
struct V_76 * V_77 ;
const struct V_193 * V_194 , * V_207 ;
struct V_23 * V_6 ;
const struct V_55 * V_208 ;
int type = V_75 | V_5 << 8 ;
V_18 = F_59 ( V_16 , V_26 , V_28 , type , sizeof( struct V_76 ) ,
V_38 ) ;
if ( V_18 == NULL )
goto V_78;
V_77 = F_60 ( V_18 ) ;
V_77 -> V_79 = V_9 ;
V_77 -> V_80 = V_81 ;
V_77 -> V_82 = F_61 ( V_1 -> V_7 . V_83 & 0xffff ) ;
if ( F_62 ( V_16 , V_209 , V_20 -> V_68 ) )
goto V_78;
if ( F_62 ( V_16 , V_210 , V_22 -> V_68 ) )
goto V_78;
if ( F_111 ( V_16 , V_211 , F_112 ( V_56 -> V_129 ) ) )
goto V_78;
if ( ( V_75 != V_60 ) && ( V_56 -> V_6 . V_212 != & V_22 -> V_190 ) ) {
V_208 = F_156 ( V_56 -> V_6 . V_212 , struct V_55 , V_6 ) ;
if ( F_111 ( V_16 , V_213 ,
F_112 ( V_208 -> V_129 ) ) )
goto V_78;
}
V_6 = F_110 ( V_16 , V_214 ) ;
if ( V_6 == NULL )
goto V_78;
F_157 (expr, next, rule) {
if ( F_147 ( V_16 , V_215 , V_194 ) < 0 )
goto V_78;
}
F_113 ( V_16 , V_6 ) ;
if ( V_56 -> V_216 ) {
struct V_217 * V_216 = V_217 ( V_56 ) ;
if ( F_158 ( V_16 , V_218 , V_216 -> V_98 + 1 ,
V_216 -> V_196 ) < 0 )
goto V_78;
}
F_65 ( V_16 , V_18 ) ;
return 0 ;
V_78:
F_66 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_159 ( const struct V_13 * V_14 ,
const struct V_55 * V_56 ,
int V_75 )
{
struct V_15 * V_16 ;
int V_48 ;
if ( ! V_14 -> V_27 &&
! F_68 ( V_14 -> V_1 , V_87 ) )
return 0 ;
V_48 = - V_88 ;
V_16 = F_69 ( V_89 , V_34 ) ;
if ( V_16 == NULL )
goto V_48;
V_48 = F_155 ( V_16 , V_14 -> V_1 , V_14 -> V_26 , V_14 -> V_28 ,
V_75 , 0 , V_14 -> V_3 -> V_9 , V_14 -> V_20 ,
V_14 -> V_22 , V_56 ) ;
if ( V_48 < 0 ) {
F_70 ( V_16 ) ;
goto V_48;
}
V_48 = F_71 ( V_16 , V_14 -> V_1 , V_14 -> V_26 , V_87 ,
V_14 -> V_27 , V_34 ) ;
V_48:
if ( V_48 < 0 ) {
F_72 ( V_14 -> V_1 , V_14 -> V_26 , V_87 ,
V_48 ) ;
}
return V_48 ;
}
static int F_160 ( struct V_15 * V_16 ,
struct V_90 * V_91 )
{
const struct V_76 * V_77 = F_60 ( V_91 -> V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
const struct V_55 * V_56 ;
unsigned int V_92 = 0 , V_93 = V_91 -> args [ 0 ] ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_77 -> V_79 ;
F_74 () ;
V_91 -> V_28 = V_1 -> V_7 . V_83 ;
F_75 (afi, &net->nft.af_info, list) {
if ( V_9 != V_94 && V_9 != V_3 -> V_9 )
continue;
F_75 (table, &afi->tables, list) {
F_75 (chain, &table->chains, list) {
F_75 (rule, &chain->rules, list) {
if ( ! F_34 ( V_1 , V_56 ) )
goto V_95;
if ( V_92 < V_93 )
goto V_95;
if ( V_92 > V_93 )
memset ( & V_91 -> args [ 1 ] , 0 ,
sizeof( V_91 -> args ) - sizeof( V_91 -> args [ 0 ] ) ) ;
if ( F_155 ( V_16 , V_1 , F_16 ( V_91 -> V_16 ) . V_26 ,
V_91 -> V_18 -> V_29 ,
V_219 ,
V_96 | V_220 ,
V_3 -> V_9 , V_20 , V_22 , V_56 ) < 0 )
goto V_97;
F_76 ( V_91 , F_77 ( V_16 ) ) ;
V_95:
V_92 ++ ;
}
}
}
}
V_97:
F_78 () ;
V_91 -> args [ 0 ] = V_92 ;
return V_16 -> V_98 ;
}
static int F_161 ( struct V_99 * V_100 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_60 ( V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
const struct V_55 * V_56 ;
struct V_15 * V_101 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_77 -> V_79 ;
int V_48 ;
if ( V_18 -> V_102 & V_103 ) {
struct V_104 V_105 = {
. V_106 = F_160 ,
} ;
return F_80 ( V_100 , V_16 , V_18 , & V_105 ) ;
}
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_81 ( V_3 ) )
return F_82 ( V_3 ) ;
V_20 = F_52 ( V_3 , V_24 [ V_209 ] ) ;
if ( F_81 ( V_20 ) )
return F_82 ( V_20 ) ;
if ( V_20 -> V_38 & V_46 )
return - V_58 ;
V_22 = F_104 ( V_20 , V_24 [ V_210 ] ) ;
if ( F_81 ( V_22 ) )
return F_82 ( V_22 ) ;
if ( V_22 -> V_38 & V_52 )
return - V_58 ;
V_56 = F_154 ( V_22 , V_24 [ V_211 ] ) ;
if ( F_81 ( V_56 ) )
return F_82 ( V_56 ) ;
V_101 = F_83 ( V_89 , V_34 ) ;
if ( ! V_101 )
return - V_44 ;
V_48 = F_155 ( V_101 , V_1 , F_16 ( V_16 ) . V_26 ,
V_18 -> V_29 , V_219 , 0 ,
V_9 , V_20 , V_22 , V_56 ) ;
if ( V_48 < 0 )
goto V_48;
return F_84 ( V_100 , V_101 , F_16 ( V_16 ) . V_26 ) ;
V_48:
F_70 ( V_101 ) ;
return V_48 ;
}
static void F_162 ( const struct V_13 * V_14 ,
struct V_55 * V_56 )
{
struct V_193 * V_194 ;
V_194 = F_163 ( V_56 ) ;
while ( V_194 -> V_40 && V_194 != F_164 ( V_56 ) ) {
F_150 ( V_14 , V_194 ) ;
V_194 = F_165 ( V_194 ) ;
}
F_22 ( V_56 ) ;
}
static int F_166 ( struct V_99 * V_100 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_60 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_55 * V_56 , * V_221 = NULL ;
struct V_217 * V_216 ;
struct V_30 * V_33 = NULL ;
struct V_193 * V_194 ;
struct V_13 V_14 ;
struct V_23 * V_222 ;
unsigned int V_32 , V_72 , V_223 , V_224 = 0 , V_225 = 0 ;
int V_48 , V_226 ;
bool V_170 ;
T_2 V_129 , V_227 ;
V_170 = V_18 -> V_102 & V_171 ? true : false ;
V_3 = F_10 ( V_1 , V_77 -> V_79 , V_170 ) ;
if ( F_81 ( V_3 ) )
return F_82 ( V_3 ) ;
V_20 = F_52 ( V_3 , V_24 [ V_209 ] ) ;
if ( F_81 ( V_20 ) )
return F_82 ( V_20 ) ;
V_22 = F_104 ( V_20 , V_24 [ V_210 ] ) ;
if ( F_81 ( V_22 ) )
return F_82 ( V_22 ) ;
if ( V_24 [ V_211 ] ) {
V_129 = F_123 ( F_124 ( V_24 [ V_211 ] ) ) ;
V_56 = F_153 ( V_22 , V_129 ) ;
if ( F_81 ( V_56 ) )
return F_82 ( V_56 ) ;
if ( V_18 -> V_102 & V_109 )
return - V_110 ;
if ( V_18 -> V_102 & V_111 )
V_221 = V_56 ;
else
return - V_112 ;
} else {
if ( ! V_170 || V_18 -> V_102 & V_111 )
return - V_69 ;
V_129 = F_53 ( V_20 ) ;
if ( V_22 -> V_54 == V_174 )
return - V_175 ;
}
if ( V_24 [ V_213 ] ) {
if ( ! ( V_18 -> V_102 & V_171 ) )
return - V_112 ;
V_227 = F_123 ( F_124 ( V_24 [ V_213 ] ) ) ;
V_221 = F_153 ( V_22 , V_227 ) ;
if ( F_81 ( V_221 ) )
return F_82 ( V_221 ) ;
}
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_223 = 0 ;
V_32 = 0 ;
if ( V_24 [ V_214 ] ) {
F_167 (tmp, nla[NFTA_RULE_EXPRESSIONS], rem) {
V_48 = - V_69 ;
if ( F_168 ( V_222 ) != V_215 )
goto V_114;
if ( V_223 == V_228 )
goto V_114;
V_48 = F_148 ( & V_14 , V_222 , & V_199 [ V_223 ] ) ;
if ( V_48 < 0 )
goto V_114;
V_32 += V_199 [ V_223 ] . V_40 -> V_32 ;
V_223 ++ ;
}
}
V_48 = - V_229 ;
if ( V_32 >= 1 << 12 )
goto V_114;
if ( V_24 [ V_218 ] ) {
V_224 = F_56 ( V_24 [ V_218 ] ) ;
if ( V_224 > 0 )
V_225 = sizeof( struct V_217 ) + V_224 ;
}
V_48 = - V_44 ;
V_56 = F_19 ( sizeof( * V_56 ) + V_32 + V_225 , V_34 ) ;
if ( V_56 == NULL )
goto V_114;
F_38 ( V_1 , V_56 ) ;
V_56 -> V_129 = V_129 ;
V_56 -> V_230 = V_32 ;
V_56 -> V_216 = V_224 ? 1 : 0 ;
if ( V_224 ) {
V_216 = V_217 ( V_56 ) ;
V_216 -> V_98 = V_224 - 1 ;
F_169 ( V_216 -> V_196 , V_24 [ V_218 ] , V_224 ) ;
}
V_194 = F_163 ( V_56 ) ;
for ( V_72 = 0 ; V_72 < V_223 ; V_72 ++ ) {
V_48 = F_149 ( & V_14 , & V_199 [ V_72 ] , V_194 ) ;
if ( V_48 < 0 )
goto V_115;
V_199 [ V_72 ] . V_40 = NULL ;
V_194 = F_165 ( V_194 ) ;
}
if ( V_18 -> V_102 & V_111 ) {
if ( F_36 ( V_1 , V_221 ) ) {
V_33 = F_42 ( & V_14 , V_60 ,
V_221 ) ;
if ( V_33 == NULL ) {
V_48 = - V_44 ;
goto V_115;
}
F_39 ( V_1 , V_221 ) ;
V_22 -> V_54 -- ;
F_4 ( & V_56 -> V_6 , & V_221 -> V_6 ) ;
} else {
V_48 = - V_58 ;
goto V_115;
}
} else if ( V_18 -> V_102 & V_220 )
if ( V_221 )
F_142 ( & V_56 -> V_6 , & V_221 -> V_6 ) ;
else
F_4 ( & V_56 -> V_6 , & V_22 -> V_190 ) ;
else {
if ( V_221 )
F_4 ( & V_56 -> V_6 , & V_221 -> V_6 ) ;
else
F_142 ( & V_56 -> V_6 , & V_22 -> V_190 ) ;
}
if ( F_42 ( & V_14 , V_219 , V_56 ) == NULL ) {
V_48 = - V_44 ;
goto V_119;
}
V_22 -> V_54 ++ ;
return 0 ;
V_119:
F_7 ( & V_56 -> V_6 ) ;
V_115:
F_162 ( & V_14 , V_56 ) ;
V_114:
for ( V_72 = 0 ; V_72 < V_223 ; V_72 ++ ) {
if ( V_199 [ V_72 ] . V_40 != NULL )
F_93 ( V_199 [ V_72 ] . V_40 -> type -> V_113 ) ;
}
return V_48 ;
}
static int F_170 ( struct V_99 * V_100 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_60 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
struct V_19 * V_20 ;
struct V_21 * V_22 = NULL ;
struct V_55 * V_56 ;
int V_9 = V_77 -> V_79 , V_48 = 0 ;
struct V_13 V_14 ;
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_81 ( V_3 ) )
return F_82 ( V_3 ) ;
V_20 = F_52 ( V_3 , V_24 [ V_209 ] ) ;
if ( F_81 ( V_20 ) )
return F_82 ( V_20 ) ;
if ( V_20 -> V_38 & V_46 )
return - V_58 ;
if ( V_24 [ V_210 ] ) {
V_22 = F_104 ( V_20 , V_24 [ V_210 ] ) ;
if ( F_81 ( V_22 ) )
return F_82 ( V_22 ) ;
}
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
if ( V_22 ) {
if ( V_24 [ V_211 ] ) {
V_56 = F_154 ( V_22 ,
V_24 [ V_211 ] ) ;
if ( F_81 ( V_56 ) )
return F_82 ( V_56 ) ;
V_48 = F_43 ( & V_14 , V_56 ) ;
} else {
V_48 = F_44 ( & V_14 ) ;
}
} else {
F_9 (chain, &table->chains, list) {
V_14 . V_22 = V_22 ;
V_48 = F_44 ( & V_14 ) ;
if ( V_48 < 0 )
break;
}
}
return V_48 ;
}
int F_171 ( struct V_231 * V_40 )
{
F_3 ( V_5 ) ;
F_4 ( & V_40 -> V_6 , & V_232 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_172 ( struct V_231 * V_40 )
{
F_3 ( V_5 ) ;
F_7 ( & V_40 -> V_6 ) ;
F_5 ( V_5 ) ;
}
static const struct V_231 *
F_173 ( const struct V_23 * const V_24 [] ,
const struct V_233 * V_234 ,
enum V_235 V_155 )
{
const struct V_231 * V_40 , * V_236 ;
struct V_237 V_238 , V_239 ;
T_1 V_240 ;
#ifdef F_11
if ( F_96 ( & V_232 ) ) {
F_5 ( V_5 ) ;
F_12 ( L_5 ) ;
F_3 ( V_5 ) ;
if ( ! F_96 ( & V_232 ) )
return F_13 ( - V_11 ) ;
}
#endif
V_240 = 0 ;
if ( V_24 [ V_241 ] != NULL ) {
V_240 = F_47 ( F_48 ( V_24 [ V_241 ] ) ) ;
V_240 &= V_242 | V_243 | V_244 ;
}
V_236 = NULL ;
V_239 . V_32 = ~ 0 ;
V_239 . V_245 = ~ 0 ;
F_9 (ops, &nf_tables_set_ops, list) {
if ( ( V_40 -> V_240 & V_240 ) != V_240 )
continue;
if ( ! V_40 -> V_246 ( V_234 , V_240 , & V_238 ) )
continue;
switch ( V_155 ) {
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
if ( ! F_91 ( V_40 -> V_113 ) )
continue;
if ( V_236 != NULL )
F_93 ( V_236 -> V_113 ) ;
V_236 = V_40 ;
V_239 = V_238 ;
}
if ( V_236 != NULL )
return V_236 ;
return F_13 ( - V_112 ) ;
}
static int F_174 ( struct V_13 * V_14 ,
const struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
const struct V_76 * V_77 = F_60 ( V_18 ) ;
struct V_2 * V_3 = NULL ;
struct V_19 * V_20 = NULL ;
if ( V_77 -> V_79 != V_94 ) {
V_3 = F_10 ( V_1 , V_77 -> V_79 , false ) ;
if ( F_81 ( V_3 ) )
return F_82 ( V_3 ) ;
}
if ( V_24 [ V_249 ] != NULL ) {
if ( V_3 == NULL )
return - V_12 ;
V_20 = F_52 ( V_3 , V_24 [ V_249 ] ) ;
if ( F_81 ( V_20 ) )
return F_82 ( V_20 ) ;
if ( V_20 -> V_38 & V_46 )
return - V_58 ;
}
F_14 ( V_14 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return 0 ;
}
struct V_61 * F_175 ( const struct V_19 * V_20 ,
const struct V_23 * V_24 )
{
struct V_61 * V_62 ;
if ( V_24 == NULL )
return F_13 ( - V_69 ) ;
F_9 (set, &table->sets, list) {
if ( ! F_51 ( V_24 , V_62 -> V_68 ) )
return V_62 ;
}
return F_13 ( - V_58 ) ;
}
struct V_61 * F_176 ( const struct V_1 * V_1 ,
const struct V_23 * V_24 )
{
struct V_30 * V_33 ;
T_1 V_250 = F_47 ( F_48 ( V_24 ) ) ;
F_9 (trans, &net->nft.commit_list, list) {
if ( V_33 -> V_31 == V_64 &&
V_250 == F_46 ( V_33 ) )
return V_63 ( V_33 ) ;
}
return F_13 ( - V_58 ) ;
}
static int F_177 ( struct V_13 * V_14 , struct V_61 * V_62 ,
const char * V_68 )
{
const struct V_61 * V_72 ;
const char * V_251 ;
unsigned long * V_252 ;
unsigned int V_223 = 0 , V_253 = 0 ;
V_251 = F_178 ( V_68 , V_184 , '%' ) ;
if ( V_251 != NULL ) {
if ( V_251 [ 1 ] != 'd' || strchr ( V_251 + 2 , '%' ) )
return - V_69 ;
V_252 = ( unsigned long * ) F_179 ( V_34 ) ;
if ( V_252 == NULL )
return - V_44 ;
V_95:
F_9 (i, &ctx->table->sets, list) {
int V_222 ;
if ( ! sscanf ( V_72 -> V_68 , V_68 , & V_222 ) )
continue;
if ( V_222 < V_253 || V_222 >= V_253 + V_254 * V_255 )
continue;
F_180 ( V_222 - V_253 , V_252 ) ;
}
V_223 = F_181 ( V_252 , V_254 * V_255 ) ;
if ( V_223 >= V_254 * V_255 ) {
V_253 += V_254 * V_255 ;
memset ( V_252 , 0 , V_255 ) ;
goto V_95;
}
F_182 ( ( unsigned long ) V_252 ) ;
}
snprintf ( V_62 -> V_68 , sizeof( V_62 -> V_68 ) , V_68 , V_253 + V_223 ) ;
F_9 (i, &ctx->table->sets, list) {
if ( ! strcmp ( V_62 -> V_68 , V_72 -> V_68 ) )
return - V_256 ;
}
return 0 ;
}
static int F_183 ( struct V_15 * V_16 , const struct V_13 * V_14 ,
const struct V_61 * V_62 , T_6 V_75 , T_6 V_38 )
{
struct V_76 * V_77 ;
struct V_17 * V_18 ;
struct V_23 * V_234 ;
T_1 V_26 = V_14 -> V_26 ;
T_1 V_28 = V_14 -> V_28 ;
V_75 |= V_5 << 8 ;
V_18 = F_59 ( V_16 , V_26 , V_28 , V_75 , sizeof( struct V_76 ) ,
V_38 ) ;
if ( V_18 == NULL )
goto V_78;
V_77 = F_60 ( V_18 ) ;
V_77 -> V_79 = V_14 -> V_3 -> V_9 ;
V_77 -> V_80 = V_81 ;
V_77 -> V_82 = F_61 ( V_14 -> V_1 -> V_7 . V_83 & 0xffff ) ;
if ( F_62 ( V_16 , V_249 , V_14 -> V_20 -> V_68 ) )
goto V_78;
if ( F_62 ( V_16 , V_257 , V_62 -> V_68 ) )
goto V_78;
if ( V_62 -> V_38 != 0 )
if ( F_63 ( V_16 , V_241 , F_64 ( V_62 -> V_38 ) ) )
goto V_78;
if ( F_63 ( V_16 , V_258 , F_64 ( V_62 -> V_259 ) ) )
goto V_78;
if ( F_63 ( V_16 , V_260 , F_64 ( V_62 -> V_261 ) ) )
goto V_78;
if ( V_62 -> V_38 & V_243 ) {
if ( F_63 ( V_16 , V_262 , F_64 ( V_62 -> V_263 ) ) )
goto V_78;
if ( F_63 ( V_16 , V_264 , F_64 ( V_62 -> V_230 ) ) )
goto V_78;
}
if ( V_62 -> V_265 &&
F_111 ( V_16 , V_266 , F_112 ( V_62 -> V_265 ) ) )
goto V_78;
if ( V_62 -> V_267 &&
F_63 ( V_16 , V_268 , F_64 ( V_62 -> V_267 ) ) )
goto V_78;
if ( V_62 -> V_155 != V_247 ) {
if ( F_63 ( V_16 , V_269 , F_64 ( V_62 -> V_155 ) ) )
goto V_78;
}
V_234 = F_110 ( V_16 , V_270 ) ;
if ( V_234 == NULL )
goto V_78;
if ( V_62 -> V_32 &&
F_63 ( V_16 , V_271 , F_64 ( V_62 -> V_32 ) ) )
goto V_78;
F_113 ( V_16 , V_234 ) ;
F_65 ( V_16 , V_18 ) ;
return 0 ;
V_78:
F_66 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_184 ( const struct V_13 * V_14 ,
const struct V_61 * V_62 ,
int V_75 , T_7 V_272 )
{
struct V_15 * V_16 ;
T_1 V_26 = V_14 -> V_26 ;
int V_48 ;
if ( ! V_14 -> V_27 &&
! F_68 ( V_14 -> V_1 , V_87 ) )
return 0 ;
V_48 = - V_88 ;
V_16 = F_69 ( V_89 , V_272 ) ;
if ( V_16 == NULL )
goto V_48;
V_48 = F_183 ( V_16 , V_14 , V_62 , V_75 , 0 ) ;
if ( V_48 < 0 ) {
F_70 ( V_16 ) ;
goto V_48;
}
V_48 = F_71 ( V_16 , V_14 -> V_1 , V_26 , V_87 ,
V_14 -> V_27 , V_272 ) ;
V_48:
if ( V_48 < 0 )
F_72 ( V_14 -> V_1 , V_26 , V_87 , V_48 ) ;
return V_48 ;
}
static int F_185 ( struct V_15 * V_16 , struct V_90 * V_91 )
{
const struct V_61 * V_62 ;
unsigned int V_92 , V_93 = V_91 -> args [ 0 ] ;
struct V_2 * V_3 ;
struct V_19 * V_20 , * V_273 = (struct V_19 * ) V_91 -> args [ 2 ] ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_274 = V_91 -> args [ 3 ] ;
struct V_13 * V_14 = V_91 -> V_196 , V_275 ;
if ( V_91 -> args [ 1 ] )
return V_16 -> V_98 ;
F_74 () ;
V_91 -> V_28 = V_1 -> V_7 . V_83 ;
F_75 (afi, &net->nft.af_info, list) {
if ( V_14 -> V_3 && V_14 -> V_3 != V_3 )
continue;
if ( V_274 ) {
if ( V_3 -> V_9 != V_274 )
continue;
V_274 = 0 ;
}
F_75 (table, &afi->tables, list) {
if ( V_14 -> V_20 && V_14 -> V_20 != V_20 )
continue;
if ( V_273 ) {
if ( V_273 != V_20 )
continue;
V_273 = NULL ;
}
V_92 = 0 ;
F_75 (set, &table->sets, list) {
if ( V_92 < V_93 )
goto V_95;
V_275 = * V_14 ;
V_275 . V_20 = V_20 ;
V_275 . V_3 = V_3 ;
if ( F_183 ( V_16 , & V_275 , V_62 ,
V_64 ,
V_96 ) < 0 ) {
V_91 -> args [ 0 ] = V_92 ;
V_91 -> args [ 2 ] = ( unsigned long ) V_20 ;
V_91 -> args [ 3 ] = V_3 -> V_9 ;
goto V_97;
}
F_76 ( V_91 , F_77 ( V_16 ) ) ;
V_95:
V_92 ++ ;
}
if ( V_93 )
V_93 = 0 ;
}
}
V_91 -> args [ 1 ] = 1 ;
V_97:
F_78 () ;
return V_16 -> V_98 ;
}
static int F_186 ( struct V_90 * V_91 )
{
F_22 ( V_91 -> V_196 ) ;
return 0 ;
}
static int F_187 ( struct V_99 * V_100 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_61 * V_62 ;
struct V_13 V_14 ;
struct V_15 * V_101 ;
const struct V_76 * V_77 = F_60 ( V_18 ) ;
int V_48 ;
V_48 = F_174 ( & V_14 , V_16 , V_18 , V_24 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_18 -> V_102 & V_103 ) {
struct V_104 V_105 = {
. V_106 = F_185 ,
. V_97 = F_186 ,
} ;
struct V_13 * V_276 ;
V_276 = F_188 ( sizeof( * V_276 ) , V_34 ) ;
if ( V_276 == NULL )
return - V_44 ;
* V_276 = V_14 ;
V_105 . V_196 = V_276 ;
return F_80 ( V_100 , V_16 , V_18 , & V_105 ) ;
}
if ( V_77 -> V_79 == V_94 )
return - V_12 ;
V_62 = F_175 ( V_14 . V_20 , V_24 [ V_257 ] ) ;
if ( F_81 ( V_62 ) )
return F_82 ( V_62 ) ;
if ( V_62 -> V_38 & V_66 )
return - V_58 ;
V_101 = F_83 ( V_89 , V_34 ) ;
if ( V_101 == NULL )
return - V_44 ;
V_48 = F_183 ( V_101 , & V_14 , V_62 , V_64 , 0 ) ;
if ( V_48 < 0 )
goto V_48;
return F_84 ( V_100 , V_101 , F_16 ( V_16 ) . V_26 ) ;
V_48:
F_70 ( V_101 ) ;
return V_48 ;
}
static int F_189 ( const struct V_13 * V_14 ,
struct V_233 * V_234 ,
const struct V_23 * V_24 )
{
struct V_23 * V_277 [ V_278 + 1 ] ;
int V_48 ;
V_48 = F_119 ( V_277 , V_278 , V_24 , V_279 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_277 [ V_271 ] != NULL )
V_234 -> V_32 = F_47 ( F_48 ( V_277 [ V_271 ] ) ) ;
return 0 ;
}
static int F_190 ( struct V_99 * V_100 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_60 ( V_18 ) ;
const struct V_231 * V_40 ;
struct V_2 * V_3 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
struct V_19 * V_20 ;
struct V_61 * V_62 ;
struct V_13 V_14 ;
char V_68 [ V_184 ] ;
unsigned int V_32 ;
bool V_170 ;
T_2 V_265 ;
T_1 V_259 , V_263 , V_38 , V_155 , V_267 ;
struct V_233 V_234 ;
int V_48 ;
if ( V_24 [ V_249 ] == NULL ||
V_24 [ V_257 ] == NULL ||
V_24 [ V_260 ] == NULL ||
V_24 [ V_65 ] == NULL )
return - V_69 ;
memset ( & V_234 , 0 , sizeof( V_234 ) ) ;
V_259 = V_280 ;
if ( V_24 [ V_258 ] != NULL ) {
V_259 = F_47 ( F_48 ( V_24 [ V_258 ] ) ) ;
if ( ( V_259 & V_281 ) == V_281 )
return - V_69 ;
}
V_234 . V_261 = F_47 ( F_48 ( V_24 [ V_260 ] ) ) ;
if ( V_234 . V_261 == 0 || V_234 . V_261 > V_282 )
return - V_69 ;
V_38 = 0 ;
if ( V_24 [ V_241 ] != NULL ) {
V_38 = F_47 ( F_48 ( V_24 [ V_241 ] ) ) ;
if ( V_38 & ~ ( V_123 | V_283 |
V_242 | V_244 |
V_243 | V_284 ) )
return - V_69 ;
if ( ( V_38 & ( V_243 | V_284 ) ) ==
( V_243 | V_284 ) )
return - V_112 ;
}
V_263 = 0 ;
if ( V_24 [ V_262 ] != NULL ) {
if ( ! ( V_38 & V_243 ) )
return - V_69 ;
V_263 = F_47 ( F_48 ( V_24 [ V_262 ] ) ) ;
if ( ( V_263 & V_281 ) == V_281 &&
V_263 != V_285 )
return - V_69 ;
if ( V_263 != V_285 ) {
if ( V_24 [ V_264 ] == NULL )
return - V_69 ;
V_234 . V_230 = F_47 ( F_48 ( V_24 [ V_264 ] ) ) ;
if ( V_234 . V_230 == 0 || V_234 . V_230 > V_282 )
return - V_69 ;
} else
V_234 . V_230 = sizeof( struct V_286 ) ;
} else if ( V_38 & V_243 )
return - V_69 ;
V_265 = 0 ;
if ( V_24 [ V_266 ] != NULL ) {
if ( ! ( V_38 & V_244 ) )
return - V_69 ;
V_265 = F_123 ( F_124 ( V_24 [ V_266 ] ) ) ;
}
V_267 = 0 ;
if ( V_24 [ V_268 ] != NULL ) {
if ( ! ( V_38 & V_244 ) )
return - V_69 ;
V_267 = F_47 ( F_48 ( V_24 [ V_268 ] ) ) ;
}
V_155 = V_247 ;
if ( V_24 [ V_269 ] != NULL )
V_155 = F_47 ( F_48 ( V_24 [ V_269 ] ) ) ;
if ( V_24 [ V_270 ] != NULL ) {
V_48 = F_189 ( & V_14 , & V_234 , V_24 [ V_270 ] ) ;
if ( V_48 < 0 )
return V_48 ;
}
V_170 = V_18 -> V_102 & V_171 ? true : false ;
V_3 = F_10 ( V_1 , V_77 -> V_79 , V_170 ) ;
if ( F_81 ( V_3 ) )
return F_82 ( V_3 ) ;
V_20 = F_52 ( V_3 , V_24 [ V_249 ] ) ;
if ( F_81 ( V_20 ) )
return F_82 ( V_20 ) ;
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
V_62 = F_175 ( V_20 , V_24 [ V_257 ] ) ;
if ( F_81 ( V_62 ) ) {
if ( F_82 ( V_62 ) != - V_58 )
return F_82 ( V_62 ) ;
V_62 = NULL ;
}
if ( V_62 != NULL ) {
if ( V_18 -> V_102 & V_109 )
return - V_110 ;
if ( V_18 -> V_102 & V_111 )
return - V_112 ;
return 0 ;
}
if ( ! ( V_18 -> V_102 & V_171 ) )
return - V_58 ;
V_40 = F_173 ( V_24 , & V_234 , V_155 ) ;
if ( F_81 ( V_40 ) )
return F_82 ( V_40 ) ;
V_32 = 0 ;
if ( V_40 -> V_287 != NULL )
V_32 = V_40 -> V_287 ( V_24 ) ;
V_48 = - V_44 ;
V_62 = F_19 ( sizeof( * V_62 ) + V_32 , V_34 ) ;
if ( V_62 == NULL )
goto V_114;
F_92 ( V_68 , V_24 [ V_257 ] , sizeof( V_62 -> V_68 ) ) ;
V_48 = F_177 ( & V_14 , V_62 , V_68 ) ;
if ( V_48 < 0 )
goto V_115;
F_2 ( & V_62 -> V_124 ) ;
F_139 ( & V_62 -> V_185 , V_1 ) ;
V_62 -> V_40 = V_40 ;
V_62 -> V_259 = V_259 ;
V_62 -> V_261 = V_234 . V_261 ;
V_62 -> V_263 = V_263 ;
V_62 -> V_230 = V_234 . V_230 ;
V_62 -> V_38 = V_38 ;
V_62 -> V_32 = V_234 . V_32 ;
V_62 -> V_155 = V_155 ;
V_62 -> V_265 = V_265 ;
V_62 -> V_267 = V_267 ;
V_48 = V_40 -> V_205 ( V_62 , & V_234 , V_24 ) ;
if ( V_48 < 0 )
goto V_115;
V_48 = F_45 ( & V_14 , V_64 , V_62 ) ;
if ( V_48 < 0 )
goto V_115;
F_4 ( & V_62 -> V_6 , & V_20 -> V_118 ) ;
V_20 -> V_54 ++ ;
return 0 ;
V_115:
F_22 ( V_62 ) ;
V_114:
F_93 ( V_40 -> V_113 ) ;
return V_48 ;
}
static void F_191 ( struct V_61 * V_62 )
{
V_62 -> V_40 -> V_206 ( V_62 ) ;
F_93 ( V_62 -> V_40 -> V_113 ) ;
F_22 ( V_62 ) ;
}
static void F_192 ( const struct V_13 * V_14 , struct V_61 * V_62 )
{
F_7 ( & V_62 -> V_6 ) ;
F_184 ( V_14 , V_62 , V_67 , V_288 ) ;
F_191 ( V_62 ) ;
}
static int F_193 ( struct V_99 * V_100 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_60 ( V_18 ) ;
struct V_61 * V_62 ;
struct V_13 V_14 ;
int V_48 ;
if ( V_77 -> V_79 == V_94 )
return - V_12 ;
if ( V_24 [ V_249 ] == NULL )
return - V_69 ;
V_48 = F_174 ( & V_14 , V_16 , V_18 , V_24 ) ;
if ( V_48 < 0 )
return V_48 ;
V_62 = F_175 ( V_14 . V_20 , V_24 [ V_257 ] ) ;
if ( F_81 ( V_62 ) )
return F_82 ( V_62 ) ;
if ( V_62 -> V_38 & V_66 )
return - V_58 ;
if ( ! F_96 ( & V_62 -> V_124 ) )
return - V_128 ;
return F_49 ( & V_14 , V_62 ) ;
}
static int F_194 ( const struct V_13 * V_14 ,
const struct V_61 * V_62 ,
const struct V_289 * V_290 ,
const struct V_291 * V_292 )
{
const struct V_293 * V_294 = F_195 ( V_62 , V_292 -> V_187 ) ;
enum V_295 V_296 ;
V_296 = F_196 ( V_62 -> V_263 ) ;
return F_197 ( V_14 , V_296 , F_198 ( V_294 ) ,
V_62 -> V_263 == V_285 ?
V_285 : V_280 ,
V_62 -> V_230 ) ;
}
int F_199 ( const struct V_13 * V_14 , struct V_61 * V_62 ,
struct V_297 * V_298 )
{
struct V_297 * V_72 ;
struct V_289 V_290 ;
if ( ! F_96 ( & V_62 -> V_124 ) && V_62 -> V_38 & V_123 )
return - V_128 ;
if ( V_298 -> V_38 & V_243 ) {
F_9 (i, &set->bindings, list) {
if ( V_298 -> V_38 & V_243 &&
V_72 -> V_22 == V_298 -> V_22 )
goto V_299;
}
V_290 . V_300 = 0 ;
V_290 . V_301 = 0 ;
V_290 . V_48 = 0 ;
V_290 . V_302 = F_194 ;
V_62 -> V_40 -> V_303 ( V_14 , V_62 , & V_290 ) ;
if ( V_290 . V_48 < 0 ) {
if ( V_62 -> V_38 & V_123 )
F_192 ( V_14 , V_62 ) ;
return V_290 . V_48 ;
}
}
V_299:
V_298 -> V_22 = V_14 -> V_22 ;
F_4 ( & V_298 -> V_6 , & V_62 -> V_124 ) ;
return 0 ;
}
void F_200 ( const struct V_13 * V_14 , struct V_61 * V_62 ,
struct V_297 * V_298 )
{
F_7 ( & V_298 -> V_6 ) ;
if ( F_96 ( & V_62 -> V_124 ) && V_62 -> V_38 & V_123 &&
! ( V_62 -> V_38 & V_66 ) )
F_192 ( V_14 , V_62 ) ;
}
static int F_201 ( struct V_13 * V_14 ,
const struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
bool V_33 )
{
const struct V_76 * V_77 = F_60 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
V_3 = F_10 ( V_1 , V_77 -> V_79 , false ) ;
if ( F_81 ( V_3 ) )
return F_82 ( V_3 ) ;
V_20 = F_52 ( V_3 , V_24 [ V_304 ] ) ;
if ( F_81 ( V_20 ) )
return F_82 ( V_20 ) ;
if ( ! V_33 && ( V_20 -> V_38 & V_46 ) )
return - V_58 ;
F_14 ( V_14 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return 0 ;
}
static int F_202 ( struct V_15 * V_16 ,
const struct V_61 * V_62 ,
const struct V_291 * V_292 )
{
const struct V_293 * V_294 = F_195 ( V_62 , V_292 -> V_187 ) ;
unsigned char * V_305 = F_203 ( V_16 ) ;
struct V_23 * V_134 ;
V_134 = F_110 ( V_16 , V_215 ) ;
if ( V_134 == NULL )
goto V_78;
if ( F_204 ( V_16 , V_306 , F_205 ( V_294 ) ,
V_280 , V_62 -> V_261 ) < 0 )
goto V_78;
if ( F_206 ( V_294 , V_307 ) &&
F_204 ( V_16 , V_308 , F_198 ( V_294 ) ,
V_62 -> V_263 == V_285 ? V_285 : V_280 ,
V_62 -> V_230 ) < 0 )
goto V_78;
if ( F_206 ( V_294 , V_309 ) &&
F_147 ( V_16 , V_310 , F_207 ( V_294 ) ) < 0 )
goto V_78;
if ( F_206 ( V_294 , V_311 ) &&
F_63 ( V_16 , V_312 ,
F_64 ( * F_208 ( V_294 ) ) ) )
goto V_78;
if ( F_206 ( V_294 , V_313 ) &&
F_111 ( V_16 , V_314 ,
F_112 ( * F_209 ( V_294 ) ) ) )
goto V_78;
if ( F_206 ( V_294 , V_315 ) ) {
unsigned long V_316 , V_317 = V_318 ;
V_316 = * F_210 ( V_294 ) ;
if ( F_211 ( V_317 , V_316 ) )
V_316 -= V_317 ;
else
V_316 = 0 ;
if ( F_111 ( V_16 , V_319 ,
F_112 ( F_212 ( V_316 ) ) ) )
goto V_78;
}
if ( F_206 ( V_294 , V_320 ) ) {
struct V_217 * V_216 ;
V_216 = F_213 ( V_294 ) ;
if ( F_158 ( V_16 , V_321 ,
V_216 -> V_98 + 1 , V_216 -> V_196 ) )
goto V_78;
}
F_113 ( V_16 , V_134 ) ;
return 0 ;
V_78:
F_66 ( V_16 , V_305 ) ;
return - V_322 ;
}
static int F_214 ( const struct V_13 * V_14 ,
const struct V_61 * V_62 ,
const struct V_289 * V_290 ,
const struct V_291 * V_292 )
{
struct V_323 * args ;
args = F_215 ( V_290 , struct V_323 , V_290 ) ;
return F_202 ( args -> V_16 , V_62 , V_292 ) ;
}
static int F_216 ( struct V_15 * V_16 , struct V_90 * V_91 )
{
const struct V_61 * V_62 ;
struct V_323 args ;
struct V_13 V_14 ;
struct V_23 * V_24 [ V_324 + 1 ] ;
struct V_76 * V_77 ;
struct V_17 * V_18 ;
struct V_23 * V_134 ;
T_1 V_26 , V_28 ;
int V_75 , V_48 ;
V_48 = F_217 ( V_91 -> V_18 , sizeof( struct V_76 ) , V_24 ,
V_324 , V_325 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_201 ( & V_14 , V_91 -> V_16 , V_91 -> V_18 , ( void * ) V_24 ,
false ) ;
if ( V_48 < 0 )
return V_48 ;
V_62 = F_175 ( V_14 . V_20 , V_24 [ V_326 ] ) ;
if ( F_81 ( V_62 ) )
return F_82 ( V_62 ) ;
if ( V_62 -> V_38 & V_66 )
return - V_58 ;
V_75 = V_327 ;
V_75 |= V_5 << 8 ;
V_26 = F_16 ( V_91 -> V_16 ) . V_26 ;
V_28 = V_91 -> V_18 -> V_29 ;
V_18 = F_59 ( V_16 , V_26 , V_28 , V_75 , sizeof( struct V_76 ) ,
V_96 ) ;
if ( V_18 == NULL )
goto V_78;
V_77 = F_60 ( V_18 ) ;
V_77 -> V_79 = V_14 . V_3 -> V_9 ;
V_77 -> V_80 = V_81 ;
V_77 -> V_82 = F_61 ( V_14 . V_1 -> V_7 . V_83 & 0xffff ) ;
if ( F_62 ( V_16 , V_304 , V_14 . V_20 -> V_68 ) )
goto V_78;
if ( F_62 ( V_16 , V_326 , V_62 -> V_68 ) )
goto V_78;
V_134 = F_110 ( V_16 , V_328 ) ;
if ( V_134 == NULL )
goto V_78;
args . V_91 = V_91 ;
args . V_16 = V_16 ;
args . V_290 . V_300 = V_91 -> args [ 0 ] ;
args . V_290 . V_301 = 0 ;
args . V_290 . V_48 = 0 ;
args . V_290 . V_302 = F_214 ;
V_62 -> V_40 -> V_303 ( & V_14 , V_62 , & args . V_290 ) ;
F_113 ( V_16 , V_134 ) ;
F_65 ( V_16 , V_18 ) ;
if ( args . V_290 . V_48 && args . V_290 . V_48 != - V_322 )
return args . V_290 . V_48 ;
if ( args . V_290 . V_301 == V_91 -> args [ 0 ] )
return 0 ;
V_91 -> args [ 0 ] = args . V_290 . V_301 ;
return V_16 -> V_98 ;
V_78:
return - V_142 ;
}
static int F_218 ( struct V_99 * V_100 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_61 * V_62 ;
struct V_13 V_14 ;
int V_48 ;
V_48 = F_201 ( & V_14 , V_16 , V_18 , V_24 , false ) ;
if ( V_48 < 0 )
return V_48 ;
V_62 = F_175 ( V_14 . V_20 , V_24 [ V_326 ] ) ;
if ( F_81 ( V_62 ) )
return F_82 ( V_62 ) ;
if ( V_62 -> V_38 & V_66 )
return - V_58 ;
if ( V_18 -> V_102 & V_103 ) {
struct V_104 V_105 = {
. V_106 = F_216 ,
} ;
return F_80 ( V_100 , V_16 , V_18 , & V_105 ) ;
}
return - V_112 ;
}
static int F_219 ( struct V_15 * V_16 ,
const struct V_13 * V_14 , T_1 V_28 ,
T_1 V_26 , int V_75 , T_6 V_38 ,
const struct V_61 * V_62 ,
const struct V_291 * V_292 )
{
struct V_76 * V_77 ;
struct V_17 * V_18 ;
struct V_23 * V_134 ;
int V_48 ;
V_75 |= V_5 << 8 ;
V_18 = F_59 ( V_16 , V_26 , V_28 , V_75 , sizeof( struct V_76 ) ,
V_38 ) ;
if ( V_18 == NULL )
goto V_78;
V_77 = F_60 ( V_18 ) ;
V_77 -> V_79 = V_14 -> V_3 -> V_9 ;
V_77 -> V_80 = V_81 ;
V_77 -> V_82 = F_61 ( V_14 -> V_1 -> V_7 . V_83 & 0xffff ) ;
if ( F_62 ( V_16 , V_249 , V_14 -> V_20 -> V_68 ) )
goto V_78;
if ( F_62 ( V_16 , V_257 , V_62 -> V_68 ) )
goto V_78;
V_134 = F_110 ( V_16 , V_328 ) ;
if ( V_134 == NULL )
goto V_78;
V_48 = F_202 ( V_16 , V_62 , V_292 ) ;
if ( V_48 < 0 )
goto V_78;
F_113 ( V_16 , V_134 ) ;
F_65 ( V_16 , V_18 ) ;
return 0 ;
V_78:
F_66 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_220 ( const struct V_13 * V_14 ,
const struct V_61 * V_62 ,
const struct V_291 * V_292 ,
int V_75 , T_6 V_38 )
{
struct V_1 * V_1 = V_14 -> V_1 ;
T_1 V_26 = V_14 -> V_26 ;
struct V_15 * V_16 ;
int V_48 ;
if ( ! V_14 -> V_27 && ! F_68 ( V_1 , V_87 ) )
return 0 ;
V_48 = - V_88 ;
V_16 = F_69 ( V_89 , V_34 ) ;
if ( V_16 == NULL )
goto V_48;
V_48 = F_219 ( V_16 , V_14 , 0 , V_26 , V_75 , V_38 ,
V_62 , V_292 ) ;
if ( V_48 < 0 ) {
F_70 ( V_16 ) ;
goto V_48;
}
V_48 = F_71 ( V_16 , V_1 , V_26 , V_87 , V_14 -> V_27 ,
V_34 ) ;
V_48:
if ( V_48 < 0 )
F_72 ( V_1 , V_26 , V_87 , V_48 ) ;
return V_48 ;
}
static struct V_30 * F_221 ( struct V_13 * V_14 ,
int V_31 ,
struct V_61 * V_62 )
{
struct V_30 * V_33 ;
V_33 = F_18 ( V_14 , V_31 , sizeof( struct V_329 ) ) ;
if ( V_33 == NULL )
return NULL ;
F_222 ( V_33 ) = V_62 ;
return V_33 ;
}
void * F_223 ( const struct V_61 * V_62 ,
const struct V_330 * V_331 ,
const T_1 * V_332 , const T_1 * V_196 ,
T_2 V_265 , T_7 V_333 )
{
struct V_293 * V_294 ;
void * V_292 ;
V_292 = F_19 ( V_62 -> V_40 -> V_334 + V_331 -> V_98 , V_333 ) ;
if ( V_292 == NULL )
return NULL ;
V_294 = F_195 ( V_62 , V_292 ) ;
F_224 ( V_294 , V_331 ) ;
memcpy ( F_205 ( V_294 ) , V_332 , V_62 -> V_261 ) ;
if ( F_206 ( V_294 , V_307 ) )
memcpy ( F_198 ( V_294 ) , V_196 , V_62 -> V_230 ) ;
if ( F_206 ( V_294 , V_315 ) )
* F_210 ( V_294 ) =
V_318 + F_225 ( V_265 ) ;
if ( F_206 ( V_294 , V_313 ) )
* F_209 ( V_294 ) = V_265 ;
return V_292 ;
}
void F_226 ( const struct V_61 * V_62 , void * V_292 )
{
struct V_293 * V_294 = F_195 ( V_62 , V_292 ) ;
F_227 ( F_205 ( V_294 ) , V_280 ) ;
if ( F_206 ( V_294 , V_307 ) )
F_227 ( F_198 ( V_294 ) , V_62 -> V_263 ) ;
if ( F_206 ( V_294 , V_309 ) )
F_150 ( NULL , F_207 ( V_294 ) ) ;
F_22 ( V_292 ) ;
}
static int F_228 ( struct V_13 * V_14 , struct V_61 * V_62 ,
const struct V_23 * V_158 )
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
T_1 V_38 ;
T_4 V_224 ;
int V_48 ;
V_48 = F_119 ( V_24 , V_335 , V_158 ,
V_340 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_24 [ V_306 ] == NULL )
return - V_69 ;
F_229 ( & V_331 ) ;
V_38 = 0 ;
if ( V_24 [ V_312 ] != NULL ) {
V_38 = F_47 ( F_48 ( V_24 [ V_312 ] ) ) ;
if ( V_38 & ~ V_341 )
return - V_69 ;
if ( ! ( V_62 -> V_38 & V_242 ) &&
V_38 & V_341 )
return - V_69 ;
if ( V_38 != 0 )
F_230 ( & V_331 , V_311 ) ;
}
if ( V_62 -> V_38 & V_243 ) {
if ( V_24 [ V_308 ] == NULL &&
! ( V_38 & V_341 ) )
return - V_69 ;
if ( V_24 [ V_308 ] != NULL &&
V_38 & V_341 )
return - V_69 ;
} else {
if ( V_24 [ V_308 ] != NULL )
return - V_69 ;
}
V_265 = 0 ;
if ( V_24 [ V_314 ] != NULL ) {
if ( ! ( V_62 -> V_38 & V_244 ) )
return - V_69 ;
V_265 = F_123 ( F_124 ( V_24 [ V_314 ] ) ) ;
} else if ( V_62 -> V_38 & V_244 ) {
V_265 = V_62 -> V_265 ;
}
V_48 = F_231 ( V_14 , & V_292 . V_332 . V_342 , sizeof( V_292 . V_332 ) , & V_337 ,
V_24 [ V_306 ] ) ;
if ( V_48 < 0 )
goto V_114;
V_48 = - V_69 ;
if ( V_337 . type != V_280 || V_337 . V_98 != V_62 -> V_261 )
goto V_115;
F_232 ( & V_331 , V_343 , V_337 . V_98 ) ;
if ( V_265 > 0 ) {
F_230 ( & V_331 , V_315 ) ;
if ( V_265 != V_62 -> V_265 )
F_230 ( & V_331 , V_313 ) ;
}
if ( V_24 [ V_308 ] != NULL ) {
V_48 = F_231 ( V_14 , & V_196 , sizeof( V_196 ) , & V_338 ,
V_24 [ V_308 ] ) ;
if ( V_48 < 0 )
goto V_115;
V_48 = - V_69 ;
if ( V_62 -> V_263 != V_285 && V_338 . V_98 != V_62 -> V_230 )
goto V_119;
V_296 = F_196 ( V_62 -> V_263 ) ;
F_9 (binding, &set->bindings, list) {
struct V_13 V_344 = {
. V_3 = V_14 -> V_3 ,
. V_20 = V_14 -> V_20 ,
. V_22 = (struct V_21 * ) V_298 -> V_22 ,
} ;
if ( ! ( V_298 -> V_38 & V_243 ) )
continue;
V_48 = F_197 ( & V_344 , V_296 ,
& V_196 ,
V_338 . type , V_338 . V_98 ) ;
if ( V_48 < 0 )
goto V_119;
}
F_232 ( & V_331 , V_307 , V_338 . V_98 ) ;
}
V_224 = 0 ;
if ( V_24 [ V_321 ] != NULL ) {
V_224 = F_56 ( V_24 [ V_321 ] ) ;
if ( V_224 > 0 )
F_232 ( & V_331 , V_320 ,
V_224 ) ;
}
V_48 = - V_44 ;
V_292 . V_187 = F_223 ( V_62 , & V_331 , V_292 . V_332 . V_342 . V_196 , V_196 . V_196 ,
V_265 , V_34 ) ;
if ( V_292 . V_187 == NULL )
goto V_119;
V_294 = F_195 ( V_62 , V_292 . V_187 ) ;
if ( V_38 )
* F_208 ( V_294 ) = V_38 ;
if ( V_224 > 0 ) {
V_216 = F_213 ( V_294 ) ;
V_216 -> V_98 = V_224 - 1 ;
F_169 ( & V_216 -> V_196 , V_24 [ V_321 ] , V_224 ) ;
}
V_33 = F_221 ( V_14 , V_327 , V_62 ) ;
if ( V_33 == NULL )
goto V_345;
V_294 -> V_57 = F_35 ( V_14 -> V_1 ) | V_346 ;
V_48 = V_62 -> V_40 -> V_347 ( V_62 , & V_292 ) ;
if ( V_48 < 0 )
goto V_348;
V_329 ( V_33 ) = V_292 ;
F_30 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_47 ) ;
return 0 ;
V_348:
F_22 ( V_33 ) ;
V_345:
F_22 ( V_292 . V_187 ) ;
V_119:
if ( V_24 [ V_308 ] != NULL )
F_227 ( & V_196 , V_338 . type ) ;
V_115:
F_227 ( & V_292 . V_332 . V_342 , V_337 . type ) ;
V_114:
return V_48 ;
}
static int F_233 ( struct V_99 * V_100 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
const struct V_23 * V_158 ;
struct V_61 * V_62 ;
struct V_13 V_14 ;
int V_226 , V_48 = 0 ;
if ( V_24 [ V_328 ] == NULL )
return - V_69 ;
V_48 = F_201 ( & V_14 , V_16 , V_18 , V_24 , true ) ;
if ( V_48 < 0 )
return V_48 ;
V_62 = F_175 ( V_14 . V_20 , V_24 [ V_326 ] ) ;
if ( F_81 ( V_62 ) ) {
if ( V_24 [ V_349 ] ) {
V_62 = F_176 ( V_1 ,
V_24 [ V_349 ] ) ;
}
if ( F_81 ( V_62 ) )
return F_82 ( V_62 ) ;
}
if ( ! F_96 ( & V_62 -> V_124 ) && V_62 -> V_38 & V_283 )
return - V_128 ;
F_167 (attr, nla[NFTA_SET_ELEM_LIST_ELEMENTS], rem) {
if ( V_62 -> V_32 &&
! F_234 ( & V_62 -> V_350 , 1 , V_62 -> V_32 + V_62 -> V_351 ) )
return - V_256 ;
V_48 = F_228 ( & V_14 , V_62 , V_158 ) ;
if ( V_48 < 0 ) {
F_235 ( & V_62 -> V_350 ) ;
break;
}
}
return V_48 ;
}
static int F_236 ( struct V_13 * V_14 , struct V_61 * V_62 ,
const struct V_23 * V_158 )
{
struct V_23 * V_24 [ V_335 + 1 ] ;
struct V_336 V_234 ;
struct V_291 V_292 ;
struct V_30 * V_33 ;
int V_48 ;
V_48 = F_119 ( V_24 , V_335 , V_158 ,
V_340 ) ;
if ( V_48 < 0 )
goto V_114;
V_48 = - V_69 ;
if ( V_24 [ V_306 ] == NULL )
goto V_114;
V_48 = F_231 ( V_14 , & V_292 . V_332 . V_342 , sizeof( V_292 . V_332 ) , & V_234 ,
V_24 [ V_306 ] ) ;
if ( V_48 < 0 )
goto V_114;
V_48 = - V_69 ;
if ( V_234 . type != V_280 || V_234 . V_98 != V_62 -> V_261 )
goto V_115;
V_33 = F_221 ( V_14 , V_352 , V_62 ) ;
if ( V_33 == NULL ) {
V_48 = - V_44 ;
goto V_115;
}
V_292 . V_187 = V_62 -> V_40 -> V_353 ( V_62 , & V_292 ) ;
if ( V_292 . V_187 == NULL ) {
V_48 = - V_58 ;
goto V_119;
}
V_329 ( V_33 ) = V_292 ;
F_30 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_47 ) ;
return 0 ;
V_119:
F_22 ( V_33 ) ;
V_115:
F_227 ( & V_292 . V_332 . V_342 , V_234 . type ) ;
V_114:
return V_48 ;
}
static int F_237 ( struct V_99 * V_100 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_23 * V_158 ;
struct V_61 * V_62 ;
struct V_13 V_14 ;
int V_226 , V_48 = 0 ;
if ( V_24 [ V_328 ] == NULL )
return - V_69 ;
V_48 = F_201 ( & V_14 , V_16 , V_18 , V_24 , false ) ;
if ( V_48 < 0 )
return V_48 ;
V_62 = F_175 ( V_14 . V_20 , V_24 [ V_326 ] ) ;
if ( F_81 ( V_62 ) )
return F_82 ( V_62 ) ;
if ( ! F_96 ( & V_62 -> V_124 ) && V_62 -> V_38 & V_283 )
return - V_128 ;
F_167 (attr, nla[NFTA_SET_ELEM_LIST_ELEMENTS], rem) {
V_48 = F_236 ( & V_14 , V_62 , V_158 ) ;
if ( V_48 < 0 )
break;
V_62 -> V_351 ++ ;
}
return V_48 ;
}
void F_238 ( struct V_354 * V_355 )
{
struct V_356 * V_357 ;
unsigned int V_72 ;
V_357 = F_215 ( V_355 , struct V_356 , V_358 . V_355 ) ;
for ( V_72 = 0 ; V_72 < V_357 -> V_358 . V_359 ; V_72 ++ )
F_226 ( V_357 -> V_358 . V_62 , V_357 -> V_360 [ V_72 ] ) ;
F_22 ( V_357 ) ;
}
struct V_356 * F_239 ( const struct V_61 * V_62 ,
T_7 V_333 )
{
struct V_356 * V_357 ;
V_357 = F_19 ( sizeof( * V_357 ) , V_333 ) ;
if ( V_357 == NULL )
return V_357 ;
V_357 -> V_358 . V_62 = V_62 ;
return V_357 ;
}
static int F_240 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_26 , T_1 V_28 )
{
struct V_17 * V_18 ;
struct V_76 * V_77 ;
int V_75 = ( V_5 << 8 ) | V_361 ;
V_18 = F_59 ( V_16 , V_26 , V_28 , V_75 , sizeof( struct V_76 ) , 0 ) ;
if ( V_18 == NULL )
goto V_78;
V_77 = F_60 ( V_18 ) ;
V_77 -> V_79 = V_126 ;
V_77 -> V_80 = V_81 ;
V_77 -> V_82 = F_61 ( V_1 -> V_7 . V_83 & 0xffff ) ;
if ( F_63 ( V_16 , V_362 , F_64 ( V_1 -> V_7 . V_83 ) ) )
goto V_78;
F_65 ( V_16 , V_18 ) ;
return 0 ;
V_78:
F_66 ( V_16 , V_18 ) ;
return - V_322 ;
}
static int F_241 ( struct V_1 * V_1 , struct V_15 * V_16 , int V_75 )
{
struct V_17 * V_18 = F_77 ( V_16 ) ;
struct V_15 * V_101 ;
int V_48 ;
if ( F_17 ( V_18 ) &&
! F_68 ( V_1 , V_87 ) )
return 0 ;
V_48 = - V_88 ;
V_101 = F_69 ( V_89 , V_34 ) ;
if ( V_101 == NULL )
goto V_48;
V_48 = F_240 ( V_101 , V_1 , F_16 ( V_16 ) . V_26 ,
V_18 -> V_29 ) ;
if ( V_48 < 0 ) {
F_70 ( V_101 ) ;
goto V_48;
}
V_48 = F_71 ( V_101 , V_1 , F_16 ( V_16 ) . V_26 ,
V_87 , F_17 ( V_18 ) , V_34 ) ;
V_48:
if ( V_48 < 0 ) {
F_72 ( V_1 , F_16 ( V_16 ) . V_26 , V_87 ,
V_48 ) ;
}
return V_48 ;
}
static int F_242 ( struct V_99 * V_100 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
struct V_15 * V_101 ;
int V_48 ;
V_101 = F_83 ( V_89 , V_34 ) ;
if ( V_101 == NULL )
return - V_44 ;
V_48 = F_240 ( V_101 , V_1 , F_16 ( V_16 ) . V_26 ,
V_18 -> V_29 ) ;
if ( V_48 < 0 )
goto V_48;
return F_84 ( V_100 , V_101 , F_16 ( V_16 ) . V_26 ) ;
V_48:
F_70 ( V_101 ) ;
return V_48 ;
}
static void F_243 ( struct V_30 * V_33 )
{
struct V_35 * V_36 ;
if ( F_137 ( V_33 ) [ 0 ] )
strcpy ( V_33 -> V_14 . V_22 -> V_68 , F_137 ( V_33 ) ) ;
if ( ! ( V_33 -> V_14 . V_22 -> V_38 & V_42 ) )
return;
V_36 = V_35 ( V_33 -> V_14 . V_22 ) ;
F_126 ( V_36 , F_134 ( V_33 ) ) ;
switch ( F_136 ( V_33 ) ) {
case V_172 :
case V_169 :
V_36 -> V_155 = F_136 ( V_33 ) ;
break;
}
}
static void F_244 ( struct V_30 * V_33 )
{
switch ( V_33 -> V_31 ) {
case V_49 :
F_99 ( & V_33 -> V_14 ) ;
break;
case V_53 :
F_131 ( V_33 -> V_14 . V_22 ) ;
break;
case V_60 :
F_162 ( & V_33 -> V_14 , V_59 ( V_33 ) ) ;
break;
case V_67 :
F_191 ( V_63 ( V_33 ) ) ;
break;
case V_352 :
F_226 ( F_222 ( V_33 ) ,
V_329 ( V_33 ) . V_187 ) ;
break;
}
F_22 ( V_33 ) ;
}
static int F_245 ( struct V_15 * V_16 )
{
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
struct V_30 * V_33 , * V_207 ;
struct V_329 * V_363 ;
while ( ++ V_1 -> V_7 . V_83 == 0 ) ;
V_1 -> V_7 . V_364 = F_246 ( V_1 ) ;
F_129 () ;
F_95 (trans, next, &net->nft.commit_list, list) {
switch ( V_33 -> V_31 ) {
case V_45 :
if ( F_89 ( V_33 ) ) {
if ( ! F_88 ( V_33 ) ) {
F_86 ( V_33 -> V_14 . V_3 ,
V_33 -> V_14 . V_20 ) ;
V_33 -> V_14 . V_20 -> V_38 |= V_41 ;
}
} else {
V_33 -> V_14 . V_20 -> V_38 &= ~ V_46 ;
}
F_67 ( & V_33 -> V_14 , V_45 ) ;
F_20 ( V_33 ) ;
break;
case V_49 :
F_67 ( & V_33 -> V_14 , V_49 ) ;
break;
case V_51 :
if ( F_135 ( V_33 ) )
F_243 ( V_33 ) ;
else
V_33 -> V_14 . V_22 -> V_38 &= ~ V_52 ;
F_115 ( & V_33 -> V_14 , V_51 ) ;
F_20 ( V_33 ) ;
break;
case V_53 :
F_115 ( & V_33 -> V_14 , V_53 ) ;
F_28 ( V_33 -> V_14 . V_20 ,
V_33 -> V_14 . V_22 ,
V_33 -> V_14 . V_3 -> V_107 ) ;
break;
case V_219 :
F_40 ( V_33 -> V_14 . V_1 , V_59 ( V_33 ) ) ;
F_159 ( & V_33 -> V_14 ,
V_59 ( V_33 ) ,
V_219 ) ;
F_20 ( V_33 ) ;
break;
case V_60 :
F_7 ( & V_59 ( V_33 ) -> V_6 ) ;
F_159 ( & V_33 -> V_14 ,
V_59 ( V_33 ) ,
V_60 ) ;
break;
case V_64 :
V_63 ( V_33 ) -> V_38 &= ~ V_66 ;
if ( V_63 ( V_33 ) -> V_38 & V_123 &&
! F_96 ( & V_63 ( V_33 ) -> V_124 ) )
V_33 -> V_14 . V_20 -> V_54 -- ;
F_184 ( & V_33 -> V_14 , V_63 ( V_33 ) ,
V_64 , V_34 ) ;
F_20 ( V_33 ) ;
break;
case V_67 :
F_184 ( & V_33 -> V_14 , V_63 ( V_33 ) ,
V_67 , V_34 ) ;
break;
case V_327 :
V_363 = (struct V_329 * ) V_33 -> V_196 ;
V_363 -> V_62 -> V_40 -> V_365 ( V_363 -> V_62 , & V_363 -> V_292 ) ;
F_220 ( & V_33 -> V_14 , V_363 -> V_62 ,
& V_363 -> V_292 ,
V_327 , 0 ) ;
F_20 ( V_33 ) ;
break;
case V_352 :
V_363 = (struct V_329 * ) V_33 -> V_196 ;
F_220 ( & V_33 -> V_14 , V_363 -> V_62 ,
& V_363 -> V_292 ,
V_352 , 0 ) ;
V_363 -> V_62 -> V_40 -> remove ( V_363 -> V_62 , & V_363 -> V_292 ) ;
F_235 ( & V_363 -> V_62 -> V_350 ) ;
V_363 -> V_62 -> V_351 -- ;
break;
}
}
F_129 () ;
F_95 (trans, next, &net->nft.commit_list, list) {
F_21 ( & V_33 -> V_6 ) ;
F_244 ( V_33 ) ;
}
F_241 ( V_1 , V_16 , V_361 ) ;
return 0 ;
}
static void F_247 ( struct V_30 * V_33 )
{
switch ( V_33 -> V_31 ) {
case V_45 :
F_99 ( & V_33 -> V_14 ) ;
break;
case V_51 :
F_131 ( V_33 -> V_14 . V_22 ) ;
break;
case V_219 :
F_162 ( & V_33 -> V_14 , V_59 ( V_33 ) ) ;
break;
case V_64 :
F_191 ( V_63 ( V_33 ) ) ;
break;
case V_327 :
F_226 ( F_222 ( V_33 ) ,
V_329 ( V_33 ) . V_187 ) ;
break;
}
F_22 ( V_33 ) ;
}
static int F_248 ( struct V_15 * V_16 )
{
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
struct V_30 * V_33 , * V_207 ;
struct V_329 * V_363 ;
F_95 (trans, next, &net->nft.commit_list, list) {
switch ( V_33 -> V_31 ) {
case V_45 :
if ( F_89 ( V_33 ) ) {
if ( F_88 ( V_33 ) ) {
F_86 ( V_33 -> V_14 . V_3 ,
V_33 -> V_14 . V_20 ) ;
V_33 -> V_14 . V_20 -> V_38 |= V_41 ;
}
F_20 ( V_33 ) ;
} else {
F_7 ( & V_33 -> V_14 . V_20 -> V_6 ) ;
}
break;
case V_49 :
F_4 ( & V_33 -> V_14 . V_20 -> V_6 ,
& V_33 -> V_14 . V_3 -> V_4 ) ;
F_20 ( V_33 ) ;
break;
case V_51 :
if ( F_135 ( V_33 ) ) {
F_130 ( F_134 ( V_33 ) ) ;
F_20 ( V_33 ) ;
} else {
V_33 -> V_14 . V_20 -> V_54 -- ;
F_7 ( & V_33 -> V_14 . V_22 -> V_6 ) ;
F_28 ( V_33 -> V_14 . V_20 ,
V_33 -> V_14 . V_22 ,
V_33 -> V_14 . V_3 -> V_107 ) ;
}
break;
case V_53 :
V_33 -> V_14 . V_20 -> V_54 ++ ;
F_4 ( & V_33 -> V_14 . V_22 -> V_6 ,
& V_33 -> V_14 . V_20 -> V_117 ) ;
F_20 ( V_33 ) ;
break;
case V_219 :
V_33 -> V_14 . V_22 -> V_54 -- ;
F_7 ( & V_59 ( V_33 ) -> V_6 ) ;
break;
case V_60 :
V_33 -> V_14 . V_22 -> V_54 ++ ;
F_40 ( V_33 -> V_14 . V_1 , V_59 ( V_33 ) ) ;
F_20 ( V_33 ) ;
break;
case V_64 :
V_33 -> V_14 . V_20 -> V_54 -- ;
F_7 ( & V_63 ( V_33 ) -> V_6 ) ;
break;
case V_67 :
V_33 -> V_14 . V_20 -> V_54 ++ ;
F_4 ( & V_63 ( V_33 ) -> V_6 ,
& V_33 -> V_14 . V_20 -> V_118 ) ;
F_20 ( V_33 ) ;
break;
case V_327 :
V_363 = (struct V_329 * ) V_33 -> V_196 ;
V_363 -> V_62 -> V_40 -> remove ( V_363 -> V_62 , & V_363 -> V_292 ) ;
F_235 ( & V_363 -> V_62 -> V_350 ) ;
break;
case V_352 :
V_363 = (struct V_329 * ) V_33 -> V_196 ;
V_363 -> V_62 -> V_40 -> V_365 ( V_363 -> V_62 , & V_363 -> V_292 ) ;
V_363 -> V_62 -> V_351 -- ;
F_20 ( V_33 ) ;
break;
}
}
F_129 () ;
F_249 (trans, next,
&net->nft.commit_list, list) {
F_21 ( & V_33 -> V_6 ) ;
F_247 ( V_33 ) ;
}
return 0 ;
}
int F_250 ( const struct V_21 * V_22 ,
enum V_366 type )
{
const struct V_35 * V_36 ;
if ( V_22 -> V_38 & V_42 ) {
V_36 = V_35 ( V_22 ) ;
if ( V_36 -> type -> type != type )
return - V_112 ;
}
return 0 ;
}
int F_251 ( const struct V_21 * V_22 ,
unsigned int V_367 )
{
struct V_35 * V_36 ;
if ( V_22 -> V_38 & V_42 ) {
V_36 = V_35 ( V_22 ) ;
if ( ( 1 << V_36 -> V_40 [ 0 ] . V_149 ) & V_367 )
return 0 ;
return - V_112 ;
}
return 0 ;
}
static int F_252 ( const struct V_13 * V_14 ,
const struct V_61 * V_62 ,
const struct V_289 * V_290 ,
const struct V_291 * V_292 )
{
const struct V_293 * V_294 = F_195 ( V_62 , V_292 -> V_187 ) ;
const struct V_339 * V_196 ;
if ( F_206 ( V_294 , V_311 ) &&
* F_208 ( V_294 ) & V_341 )
return 0 ;
V_196 = F_198 ( V_294 ) ;
switch ( V_196 -> V_368 . V_369 ) {
case V_370 :
case V_371 :
return F_253 ( V_14 , V_196 -> V_368 . V_22 ) ;
default:
return 0 ;
}
}
static int F_253 ( const struct V_13 * V_14 ,
const struct V_21 * V_22 )
{
const struct V_55 * V_56 ;
const struct V_193 * V_194 , * V_372 ;
const struct V_61 * V_62 ;
struct V_297 * V_298 ;
struct V_289 V_290 ;
if ( V_14 -> V_22 == V_22 )
return - V_373 ;
F_9 (rule, &chain->rules, list) {
F_157 (expr, last, rule) {
const struct V_339 * V_196 = NULL ;
int V_48 ;
if ( ! V_194 -> V_40 -> V_374 )
continue;
V_48 = V_194 -> V_40 -> V_374 ( V_14 , V_194 , & V_196 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_196 == NULL )
continue;
switch ( V_196 -> V_368 . V_369 ) {
case V_370 :
case V_371 :
V_48 = F_253 ( V_14 ,
V_196 -> V_368 . V_22 ) ;
if ( V_48 < 0 )
return V_48 ;
default:
break;
}
}
}
F_9 (set, &ctx->table->sets, list) {
if ( ! ( V_62 -> V_38 & V_243 ) ||
V_62 -> V_263 != V_285 )
continue;
F_9 (binding, &set->bindings, list) {
if ( ! ( V_298 -> V_38 & V_243 ) ||
V_298 -> V_22 != V_22 )
continue;
V_290 . V_300 = 0 ;
V_290 . V_301 = 0 ;
V_290 . V_48 = 0 ;
V_290 . V_302 = F_252 ;
V_62 -> V_40 -> V_303 ( V_14 , V_62 , & V_290 ) ;
if ( V_290 . V_48 < 0 )
return V_290 . V_48 ;
}
}
return 0 ;
}
unsigned int F_254 ( const struct V_23 * V_158 )
{
unsigned int V_375 ;
V_375 = F_47 ( F_48 ( V_158 ) ) ;
switch ( V_375 ) {
case V_376 ... V_377 :
return V_375 * V_378 / V_379 ;
default:
return V_375 + V_378 / V_379 - V_380 ;
}
}
int F_255 ( struct V_15 * V_16 , unsigned int V_158 , unsigned int V_375 )
{
if ( V_375 % ( V_378 / V_379 ) == 0 )
V_375 = V_375 / ( V_378 / V_379 ) ;
else
V_375 = V_375 - V_378 / V_379 + V_380 ;
return F_63 ( V_16 , V_158 , F_64 ( V_375 ) ) ;
}
int F_256 ( enum V_295 V_375 , unsigned int V_98 )
{
if ( V_375 < V_381 * V_378 / V_379 )
return - V_69 ;
if ( V_98 == 0 )
return - V_69 ;
if ( V_375 * V_379 + V_98 > F_257 ( struct V_382 , V_196 ) )
return - V_383 ;
return 0 ;
}
int F_197 ( const struct V_13 * V_14 ,
enum V_295 V_375 ,
const struct V_339 * V_196 ,
enum V_384 type , unsigned int V_98 )
{
int V_48 ;
switch ( V_375 ) {
case V_376 :
if ( type != V_285 )
return - V_69 ;
if ( V_196 != NULL &&
( V_196 -> V_368 . V_369 == V_371 ||
V_196 -> V_368 . V_369 == V_370 ) ) {
V_48 = F_253 ( V_14 , V_196 -> V_368 . V_22 ) ;
if ( V_48 < 0 )
return V_48 ;
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
return - V_69 ;
if ( V_98 == 0 )
return - V_69 ;
if ( V_375 * V_379 + V_98 >
F_257 ( struct V_382 , V_196 ) )
return - V_383 ;
if ( V_196 != NULL && type != V_280 )
return - V_69 ;
return 0 ;
}
}
static int F_258 ( const struct V_13 * V_14 , struct V_339 * V_196 ,
struct V_336 * V_234 , const struct V_23 * V_24 )
{
struct V_23 * V_159 [ V_388 + 1 ] ;
struct V_21 * V_22 ;
int V_48 ;
V_48 = F_119 ( V_159 , V_388 , V_24 , V_389 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( ! V_159 [ V_390 ] )
return - V_69 ;
V_196 -> V_368 . V_369 = F_47 ( F_48 ( V_159 [ V_390 ] ) ) ;
switch ( V_196 -> V_368 . V_369 ) {
default:
switch ( V_196 -> V_368 . V_369 & V_391 ) {
case V_169 :
case V_172 :
case V_392 :
break;
default:
return - V_69 ;
}
case V_393 :
case V_394 :
case V_395 :
break;
case V_370 :
case V_371 :
if ( ! V_159 [ V_396 ] )
return - V_69 ;
V_22 = F_104 ( V_14 -> V_20 ,
V_159 [ V_396 ] ) ;
if ( F_81 ( V_22 ) )
return F_82 ( V_22 ) ;
if ( V_22 -> V_38 & V_42 )
return - V_112 ;
V_22 -> V_54 ++ ;
V_196 -> V_368 . V_22 = V_22 ;
break;
}
V_234 -> V_98 = sizeof( V_196 -> V_368 ) ;
V_234 -> type = V_285 ;
return 0 ;
}
static void F_259 ( const struct V_339 * V_196 )
{
switch ( V_196 -> V_368 . V_369 ) {
case V_370 :
case V_371 :
V_196 -> V_368 . V_22 -> V_54 -- ;
break;
}
}
static int F_260 ( struct V_15 * V_16 , const struct V_339 * V_196 )
{
struct V_23 * V_134 ;
V_134 = F_110 ( V_16 , V_397 ) ;
if ( ! V_134 )
goto V_78;
if ( F_63 ( V_16 , V_390 , F_64 ( V_196 -> V_368 . V_369 ) ) )
goto V_78;
switch ( V_196 -> V_368 . V_369 ) {
case V_370 :
case V_371 :
if ( F_62 ( V_16 , V_396 ,
V_196 -> V_368 . V_22 -> V_68 ) )
goto V_78;
}
F_113 ( V_16 , V_134 ) ;
return 0 ;
V_78:
return - 1 ;
}
static int F_261 ( const struct V_13 * V_14 ,
struct V_339 * V_196 , unsigned int V_32 ,
struct V_336 * V_234 , const struct V_23 * V_24 )
{
unsigned int V_98 ;
V_98 = F_56 ( V_24 ) ;
if ( V_98 == 0 )
return - V_69 ;
if ( V_98 > V_32 )
return - V_175 ;
F_169 ( V_196 -> V_196 , V_24 , V_98 ) ;
V_234 -> type = V_280 ;
V_234 -> V_98 = V_98 ;
return 0 ;
}
static int F_262 ( struct V_15 * V_16 , const struct V_339 * V_196 ,
unsigned int V_98 )
{
return F_158 ( V_16 , V_398 , V_98 , V_196 -> V_196 ) ;
}
int F_231 ( const struct V_13 * V_14 ,
struct V_339 * V_196 , unsigned int V_32 ,
struct V_336 * V_234 , const struct V_23 * V_24 )
{
struct V_23 * V_159 [ V_399 + 1 ] ;
int V_48 ;
V_48 = F_119 ( V_159 , V_399 , V_24 , V_400 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_159 [ V_398 ] )
return F_261 ( V_14 , V_196 , V_32 , V_234 ,
V_159 [ V_398 ] ) ;
if ( V_159 [ V_397 ] && V_14 != NULL )
return F_258 ( V_14 , V_196 , V_234 , V_159 [ V_397 ] ) ;
return - V_69 ;
}
void F_227 ( const struct V_339 * V_196 , enum V_384 type )
{
if ( type < V_285 )
return;
switch ( type ) {
case V_285 :
return F_259 ( V_196 ) ;
default:
F_263 ( 1 ) ;
}
}
int F_204 ( struct V_15 * V_16 , int V_158 , const struct V_339 * V_196 ,
enum V_384 type , unsigned int V_98 )
{
struct V_23 * V_134 ;
int V_48 ;
V_134 = F_110 ( V_16 , V_158 ) ;
if ( V_134 == NULL )
return - 1 ;
switch ( type ) {
case V_280 :
V_48 = F_262 ( V_16 , V_196 , V_98 ) ;
break;
case V_285 :
V_48 = F_260 ( V_16 , V_196 ) ;
break;
default:
V_48 = - V_69 ;
F_263 ( 1 ) ;
}
F_113 ( V_16 , V_134 ) ;
return V_48 ;
}
static int F_264 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_7 . V_8 ) ;
F_2 ( & V_1 -> V_7 . V_47 ) ;
V_1 -> V_7 . V_83 = 1 ;
return 0 ;
}
static int T_8 F_265 ( void )
{
int V_48 ;
V_199 = F_188 ( sizeof( struct V_198 ) * V_228 ,
V_34 ) ;
if ( V_199 == NULL ) {
V_48 = - V_44 ;
goto V_114;
}
V_48 = F_266 () ;
if ( V_48 < 0 )
goto V_115;
V_48 = F_267 ( & V_401 ) ;
if ( V_48 < 0 )
goto V_119;
F_268 ( L_6 ) ;
return F_269 ( & V_402 ) ;
V_119:
F_270 () ;
V_115:
F_22 ( V_199 ) ;
V_114:
return V_48 ;
}
static void T_9 F_271 ( void )
{
F_272 ( & V_402 ) ;
F_273 ( & V_401 ) ;
F_274 () ;
F_270 () ;
F_22 ( V_199 ) ;
}
