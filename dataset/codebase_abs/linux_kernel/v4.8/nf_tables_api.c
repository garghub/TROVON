int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
F_2 ( & V_3 -> V_4 ) ;
F_3 ( V_5 ) ;
F_4 ( & V_3 -> V_6 , & V_1 -> V_7 . V_8 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_6 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
F_3 ( V_5 ) ;
F_7 ( V_1 , V_3 ) ;
F_8 ( & V_3 -> V_6 ) ;
F_5 ( V_5 ) ;
}
static struct V_2 * F_9 ( struct V_1 * V_1 , int V_9 )
{
struct V_2 * V_3 ;
F_10 (afi, &net->nft.af_info, list) {
if ( V_3 -> V_9 == V_9 )
return V_3 ;
}
return NULL ;
}
static struct V_2 *
F_11 ( struct V_1 * V_1 , int V_9 , bool V_10 )
{
struct V_2 * V_3 ;
V_3 = F_9 ( V_1 , V_9 ) ;
if ( V_3 != NULL )
return V_3 ;
#ifdef F_12
if ( V_10 ) {
F_5 ( V_5 ) ;
F_13 ( L_1 , V_9 ) ;
F_3 ( V_5 ) ;
V_3 = F_9 ( V_1 , V_9 ) ;
if ( V_3 != NULL )
return F_14 ( - V_11 ) ;
}
#endif
return F_14 ( - V_12 ) ;
}
static void F_15 ( struct V_13 * V_14 ,
struct V_1 * V_1 ,
const struct V_15 * V_16 ,
const struct V_17 * V_18 ,
struct V_2 * V_3 ,
struct V_19 * V_20 ,
struct V_21 * V_22 ,
const struct V_23 * const * V_24 )
{
V_14 -> V_1 = V_1 ;
V_14 -> V_3 = V_3 ;
V_14 -> V_20 = V_20 ;
V_14 -> V_22 = V_22 ;
V_14 -> V_24 = V_24 ;
V_14 -> V_25 = F_16 ( V_16 ) . V_25 ;
V_14 -> V_26 = F_17 ( V_18 ) ;
V_14 -> V_27 = V_18 -> V_28 ;
}
static struct V_29 * F_18 ( struct V_13 * V_14 , int V_30 ,
T_1 V_31 )
{
struct V_29 * V_32 ;
V_32 = F_19 ( sizeof( struct V_29 ) + V_31 , V_33 ) ;
if ( V_32 == NULL )
return NULL ;
V_32 -> V_30 = V_30 ;
V_32 -> V_14 = * V_14 ;
return V_32 ;
}
static void F_20 ( struct V_29 * V_32 )
{
F_21 ( & V_32 -> V_6 ) ;
F_22 ( V_32 ) ;
}
static int F_23 ( struct V_1 * V_1 ,
const struct V_19 * V_20 ,
struct V_21 * V_22 ,
unsigned int V_34 )
{
if ( V_20 -> V_35 & V_36 ||
! ( V_22 -> V_35 & V_37 ) )
return 0 ;
return F_24 ( V_1 , F_25 ( V_22 ) -> V_38 ,
V_34 ) ;
}
static void F_26 ( struct V_1 * V_1 ,
const struct V_19 * V_20 ,
struct V_21 * V_22 ,
unsigned int V_34 )
{
if ( V_20 -> V_35 & V_36 ||
! ( V_22 -> V_35 & V_37 ) )
return;
F_27 ( V_1 , F_25 ( V_22 ) -> V_38 , V_34 ) ;
}
static int F_28 ( struct V_13 * V_14 , int V_30 )
{
struct V_29 * V_32 ;
V_32 = F_18 ( V_14 , V_30 , sizeof( struct V_39 ) ) ;
if ( V_32 == NULL )
return - V_40 ;
if ( V_30 == V_41 )
F_29 ( V_14 -> V_1 , V_14 -> V_20 ) ;
F_30 ( & V_32 -> V_6 , & V_14 -> V_1 -> V_7 . V_42 ) ;
return 0 ;
}
static int F_31 ( struct V_13 * V_14 )
{
int V_43 ;
V_43 = F_28 ( V_14 , V_44 ) ;
if ( V_43 < 0 )
return V_43 ;
F_32 ( V_14 -> V_1 , V_14 -> V_20 ) ;
return V_43 ;
}
static int F_33 ( struct V_13 * V_14 , int V_30 )
{
struct V_29 * V_32 ;
V_32 = F_18 ( V_14 , V_30 , sizeof( struct V_45 ) ) ;
if ( V_32 == NULL )
return - V_40 ;
if ( V_30 == V_46 )
F_29 ( V_14 -> V_1 , V_14 -> V_22 ) ;
F_30 ( & V_32 -> V_6 , & V_14 -> V_1 -> V_7 . V_42 ) ;
return 0 ;
}
static int F_34 ( struct V_13 * V_14 )
{
int V_43 ;
V_43 = F_33 ( V_14 , V_47 ) ;
if ( V_43 < 0 )
return V_43 ;
V_14 -> V_20 -> V_48 -- ;
F_32 ( V_14 -> V_1 , V_14 -> V_22 ) ;
return V_43 ;
}
static int
F_35 ( struct V_13 * V_14 , struct V_49 * V_50 )
{
if ( F_36 ( V_14 -> V_1 , V_50 ) ) {
F_32 ( V_14 -> V_1 , V_50 ) ;
V_14 -> V_22 -> V_48 -- ;
return 0 ;
}
return - V_51 ;
}
static struct V_29 * F_37 ( struct V_13 * V_14 , int V_30 ,
struct V_49 * V_50 )
{
struct V_29 * V_32 ;
V_32 = F_18 ( V_14 , V_30 , sizeof( struct V_52 ) ) ;
if ( V_32 == NULL )
return NULL ;
V_52 ( V_32 ) = V_50 ;
F_30 ( & V_32 -> V_6 , & V_14 -> V_1 -> V_7 . V_42 ) ;
return V_32 ;
}
static int F_38 ( struct V_13 * V_14 , struct V_49 * V_50 )
{
struct V_29 * V_32 ;
int V_43 ;
V_32 = F_37 ( V_14 , V_53 , V_50 ) ;
if ( V_32 == NULL )
return - V_40 ;
V_43 = F_35 ( V_14 , V_50 ) ;
if ( V_43 < 0 ) {
F_20 ( V_32 ) ;
return V_43 ;
}
return 0 ;
}
static int F_39 ( struct V_13 * V_14 )
{
struct V_49 * V_50 ;
int V_43 ;
F_10 (rule, &ctx->chain->rules, list) {
V_43 = F_38 ( V_14 , V_50 ) ;
if ( V_43 < 0 )
return V_43 ;
}
return 0 ;
}
static int F_40 ( struct V_13 * V_14 , int V_30 ,
struct V_54 * V_55 )
{
struct V_29 * V_32 ;
V_32 = F_18 ( V_14 , V_30 , sizeof( struct V_56 ) ) ;
if ( V_32 == NULL )
return - V_40 ;
if ( V_30 == V_57 && V_14 -> V_24 [ V_58 ] != NULL ) {
F_41 ( V_32 ) =
F_42 ( F_43 ( V_14 -> V_24 [ V_58 ] ) ) ;
F_29 ( V_14 -> V_1 , V_55 ) ;
}
V_56 ( V_32 ) = V_55 ;
F_30 ( & V_32 -> V_6 , & V_14 -> V_1 -> V_7 . V_42 ) ;
return 0 ;
}
static int F_44 ( struct V_13 * V_14 , struct V_54 * V_55 )
{
int V_43 ;
V_43 = F_40 ( V_14 , V_59 , V_55 ) ;
if ( V_43 < 0 )
return V_43 ;
F_32 ( V_14 -> V_1 , V_55 ) ;
V_14 -> V_20 -> V_48 -- ;
return V_43 ;
}
static struct V_19 * F_45 ( const struct V_2 * V_3 ,
const struct V_23 * V_24 ,
T_2 V_60 )
{
struct V_19 * V_20 ;
F_10 (table, &afi->tables, list) {
if ( ! F_46 ( V_24 , V_20 -> V_61 ) &&
F_47 ( V_20 , V_60 ) )
return V_20 ;
}
return NULL ;
}
static struct V_19 * F_48 ( const struct V_2 * V_3 ,
const struct V_23 * V_24 ,
T_2 V_60 )
{
struct V_19 * V_20 ;
if ( V_24 == NULL )
return F_14 ( - V_62 ) ;
V_20 = F_45 ( V_3 , V_24 , V_60 ) ;
if ( V_20 != NULL )
return V_20 ;
return F_14 ( - V_51 ) ;
}
static inline T_3 F_49 ( struct V_19 * V_20 )
{
return ++ V_20 -> V_63 ;
}
static const struct V_64 *
F_50 ( int V_9 , const struct V_23 * V_24 )
{
int V_65 ;
for ( V_65 = 0 ; V_65 < V_66 ; V_65 ++ ) {
if ( V_67 [ V_9 ] [ V_65 ] != NULL &&
! F_46 ( V_24 , V_67 [ V_9 ] [ V_65 ] -> V_61 ) )
return V_67 [ V_9 ] [ V_65 ] ;
}
return NULL ;
}
static const struct V_64 *
F_51 ( const struct V_2 * V_3 ,
const struct V_23 * V_24 ,
bool V_10 )
{
const struct V_64 * type ;
type = F_50 ( V_3 -> V_9 , V_24 ) ;
if ( type != NULL )
return type ;
#ifdef F_12
if ( V_10 ) {
F_5 ( V_5 ) ;
F_13 ( L_2 , V_3 -> V_9 ,
F_52 ( V_24 ) , ( const char * ) F_53 ( V_24 ) ) ;
F_3 ( V_5 ) ;
type = F_50 ( V_3 -> V_9 , V_24 ) ;
if ( type != NULL )
return F_14 ( - V_11 ) ;
}
#endif
return F_14 ( - V_51 ) ;
}
static int F_54 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_25 , T_1 V_27 , int V_68 , T_1 V_35 ,
int V_9 , const struct V_19 * V_20 )
{
struct V_17 * V_18 ;
struct V_69 * V_70 ;
V_68 |= V_5 << 8 ;
V_18 = F_55 ( V_16 , V_25 , V_27 , V_68 , sizeof( struct V_69 ) , V_35 ) ;
if ( V_18 == NULL )
goto V_71;
V_70 = F_56 ( V_18 ) ;
V_70 -> V_72 = V_9 ;
V_70 -> V_73 = V_74 ;
V_70 -> V_75 = F_57 ( V_1 -> V_7 . V_76 & 0xffff ) ;
if ( F_58 ( V_16 , V_77 , V_20 -> V_61 ) ||
F_59 ( V_16 , V_78 , F_60 ( V_20 -> V_35 ) ) ||
F_59 ( V_16 , V_79 , F_60 ( V_20 -> V_48 ) ) )
goto V_71;
F_61 ( V_16 , V_18 ) ;
return 0 ;
V_71:
F_62 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_63 ( const struct V_13 * V_14 , int V_68 )
{
struct V_15 * V_16 ;
int V_43 ;
if ( ! V_14 -> V_26 &&
! F_64 ( V_14 -> V_1 , V_80 ) )
return 0 ;
V_43 = - V_81 ;
V_16 = F_65 ( V_82 , V_33 ) ;
if ( V_16 == NULL )
goto V_43;
V_43 = F_54 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_14 -> V_27 ,
V_68 , 0 , V_14 -> V_3 -> V_9 , V_14 -> V_20 ) ;
if ( V_43 < 0 ) {
F_66 ( V_16 ) ;
goto V_43;
}
V_43 = F_67 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_80 ,
V_14 -> V_26 , V_33 ) ;
V_43:
if ( V_43 < 0 ) {
F_68 ( V_14 -> V_1 , V_14 -> V_25 , V_80 ,
V_43 ) ;
}
return V_43 ;
}
static int F_69 ( struct V_15 * V_16 ,
struct V_83 * V_84 )
{
const struct V_69 * V_70 = F_56 ( V_84 -> V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
unsigned int V_85 = 0 , V_86 = V_84 -> args [ 0 ] ;
struct V_1 * V_1 = F_70 ( V_16 -> V_87 ) ;
int V_9 = V_70 -> V_72 ;
F_71 () ;
V_84 -> V_27 = V_1 -> V_7 . V_76 ;
F_72 (afi, &net->nft.af_info, list) {
if ( V_9 != V_88 && V_9 != V_3 -> V_9 )
continue;
F_72 (table, &afi->tables, list) {
if ( V_85 < V_86 )
goto V_89;
if ( V_85 > V_86 )
memset ( & V_84 -> args [ 1 ] , 0 ,
sizeof( V_84 -> args ) - sizeof( V_84 -> args [ 0 ] ) ) ;
if ( ! F_73 ( V_1 , V_20 ) )
continue;
if ( F_54 ( V_16 , V_1 ,
F_16 ( V_84 -> V_16 ) . V_25 ,
V_84 -> V_18 -> V_28 ,
V_41 ,
V_90 ,
V_3 -> V_9 , V_20 ) < 0 )
goto V_91;
F_74 ( V_84 , F_75 ( V_16 ) ) ;
V_89:
V_85 ++ ;
}
}
V_91:
F_76 () ;
V_84 -> args [ 0 ] = V_85 ;
return V_16 -> V_92 ;
}
static int F_77 ( struct V_1 * V_1 , struct V_93 * V_94 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_69 * V_70 = F_56 ( V_18 ) ;
T_2 V_60 = F_78 ( V_1 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
struct V_15 * V_95 ;
int V_9 = V_70 -> V_72 ;
int V_43 ;
if ( V_18 -> V_96 & V_97 ) {
struct V_98 V_99 = {
. V_100 = F_69 ,
} ;
return F_79 ( V_94 , V_16 , V_18 , & V_99 ) ;
}
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_80 ( V_3 ) )
return F_81 ( V_3 ) ;
V_20 = F_48 ( V_3 , V_24 [ V_77 ] , V_60 ) ;
if ( F_80 ( V_20 ) )
return F_81 ( V_20 ) ;
V_95 = F_82 ( V_82 , V_33 ) ;
if ( ! V_95 )
return - V_40 ;
V_43 = F_54 ( V_95 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 , V_41 , 0 ,
V_9 , V_20 ) ;
if ( V_43 < 0 )
goto V_43;
return F_83 ( V_94 , V_95 , F_16 ( V_16 ) . V_25 ) ;
V_43:
F_66 ( V_95 ) ;
return V_43 ;
}
static int F_84 ( struct V_1 * V_1 ,
const struct V_2 * V_3 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 ;
int V_43 , V_65 = 0 ;
F_10 (chain, &table->chains, list) {
if ( ! F_36 ( V_1 , V_22 ) )
continue;
if ( ! ( V_22 -> V_35 & V_37 ) )
continue;
V_43 = F_24 ( V_1 , F_25 ( V_22 ) -> V_38 ,
V_3 -> V_101 ) ;
if ( V_43 < 0 )
goto V_43;
V_65 ++ ;
}
return 0 ;
V_43:
F_10 (chain, &table->chains, list) {
if ( ! F_36 ( V_1 , V_22 ) )
continue;
if ( ! ( V_22 -> V_35 & V_37 ) )
continue;
if ( V_65 -- <= 0 )
break;
F_27 ( V_1 , F_25 ( V_22 ) -> V_38 ,
V_3 -> V_101 ) ;
}
return V_43 ;
}
static void F_85 ( struct V_1 * V_1 ,
const struct V_2 * V_3 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 ;
F_10 (chain, &table->chains, list) {
if ( ! F_36 ( V_1 , V_22 ) )
continue;
if ( ! ( V_22 -> V_35 & V_37 ) )
continue;
F_27 ( V_1 , F_25 ( V_22 ) -> V_38 ,
V_3 -> V_101 ) ;
}
}
static int F_86 ( struct V_13 * V_14 )
{
struct V_29 * V_32 ;
T_1 V_35 ;
int V_102 = 0 ;
if ( ! V_14 -> V_24 [ V_78 ] )
return 0 ;
V_35 = F_42 ( F_43 ( V_14 -> V_24 [ V_78 ] ) ) ;
if ( V_35 & ~ V_36 )
return - V_62 ;
if ( V_35 == V_14 -> V_20 -> V_35 )
return 0 ;
V_32 = F_18 ( V_14 , V_41 ,
sizeof( struct V_39 ) ) ;
if ( V_32 == NULL )
return - V_40 ;
if ( ( V_35 & V_36 ) &&
! ( V_14 -> V_20 -> V_35 & V_36 ) ) {
F_87 ( V_32 ) = false ;
} else if ( ! ( V_35 & V_36 ) &&
V_14 -> V_20 -> V_35 & V_36 ) {
V_102 = F_84 ( V_14 -> V_1 , V_14 -> V_3 , V_14 -> V_20 ) ;
if ( V_102 >= 0 ) {
V_14 -> V_20 -> V_35 &= ~ V_36 ;
F_87 ( V_32 ) = true ;
}
}
if ( V_102 < 0 )
goto V_43;
F_88 ( V_32 ) = true ;
F_30 ( & V_32 -> V_6 , & V_14 -> V_1 -> V_7 . V_42 ) ;
return 0 ;
V_43:
F_20 ( V_32 ) ;
return V_102 ;
}
static int F_89 ( struct V_1 * V_1 , struct V_93 * V_94 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_69 * V_70 = F_56 ( V_18 ) ;
T_2 V_60 = F_90 ( V_1 ) ;
const struct V_23 * V_61 ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
int V_9 = V_70 -> V_72 ;
T_1 V_35 = 0 ;
struct V_13 V_14 ;
int V_43 ;
V_3 = F_11 ( V_1 , V_9 , true ) ;
if ( F_80 ( V_3 ) )
return F_81 ( V_3 ) ;
V_61 = V_24 [ V_77 ] ;
V_20 = F_48 ( V_3 , V_61 , V_60 ) ;
if ( F_80 ( V_20 ) ) {
if ( F_81 ( V_20 ) != - V_51 )
return F_81 ( V_20 ) ;
V_20 = NULL ;
}
if ( V_20 != NULL ) {
if ( V_18 -> V_96 & V_103 )
return - V_104 ;
if ( V_18 -> V_96 & V_105 )
return - V_106 ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return F_86 ( & V_14 ) ;
}
if ( V_24 [ V_78 ] ) {
V_35 = F_42 ( F_43 ( V_24 [ V_78 ] ) ) ;
if ( V_35 & ~ V_36 )
return - V_62 ;
}
V_43 = - V_12 ;
if ( ! F_91 ( V_3 -> V_107 ) )
goto V_108;
V_43 = - V_40 ;
V_20 = F_19 ( sizeof( * V_20 ) , V_33 ) ;
if ( V_20 == NULL )
goto V_109;
F_92 ( V_20 -> V_61 , V_61 , V_110 ) ;
F_2 ( & V_20 -> V_111 ) ;
F_2 ( & V_20 -> V_112 ) ;
V_20 -> V_35 = V_35 ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
V_43 = F_28 ( & V_14 , V_41 ) ;
if ( V_43 < 0 )
goto V_113;
F_4 ( & V_20 -> V_6 , & V_3 -> V_4 ) ;
return 0 ;
V_113:
F_22 ( V_20 ) ;
V_109:
F_93 ( V_3 -> V_107 ) ;
V_108:
return V_43 ;
}
static int F_94 ( struct V_13 * V_14 )
{
int V_43 ;
struct V_21 * V_22 , * V_114 ;
struct V_54 * V_55 , * V_115 ;
F_10 (chain, &ctx->table->chains, list) {
if ( ! F_36 ( V_14 -> V_1 , V_22 ) )
continue;
V_14 -> V_22 = V_22 ;
V_43 = F_39 ( V_14 ) ;
if ( V_43 < 0 )
goto V_116;
}
F_95 (set, ns, &ctx->table->sets, list) {
if ( ! F_36 ( V_14 -> V_1 , V_55 ) )
continue;
if ( V_55 -> V_35 & V_117 &&
! F_96 ( & V_55 -> V_118 ) )
continue;
V_43 = F_44 ( V_14 , V_55 ) ;
if ( V_43 < 0 )
goto V_116;
}
F_95 (chain, nc, &ctx->table->chains, list) {
if ( ! F_36 ( V_14 -> V_1 , V_22 ) )
continue;
V_14 -> V_22 = V_22 ;
V_43 = F_34 ( V_14 ) ;
if ( V_43 < 0 )
goto V_116;
}
V_43 = F_31 ( V_14 ) ;
V_116:
return V_43 ;
}
static int F_97 ( struct V_13 * V_14 , int V_9 )
{
struct V_2 * V_3 ;
struct V_19 * V_20 , * V_119 ;
const struct V_23 * const * V_24 = V_14 -> V_24 ;
int V_43 = 0 ;
F_10 (afi, &ctx->net->nft.af_info, list) {
if ( V_9 != V_120 && V_3 -> V_9 != V_9 )
continue;
V_14 -> V_3 = V_3 ;
F_95 (table, nt, &afi->tables, list) {
if ( ! F_36 ( V_14 -> V_1 , V_20 ) )
continue;
if ( V_24 [ V_77 ] &&
F_46 ( V_24 [ V_77 ] , V_20 -> V_61 ) != 0 )
continue;
V_14 -> V_20 = V_20 ;
V_43 = F_94 ( V_14 ) ;
if ( V_43 < 0 )
goto V_116;
}
}
V_116:
return V_43 ;
}
static int F_98 ( struct V_1 * V_1 , struct V_93 * V_94 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_69 * V_70 = F_56 ( V_18 ) ;
T_2 V_60 = F_90 ( V_1 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
int V_9 = V_70 -> V_72 ;
struct V_13 V_14 ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , NULL , NULL , NULL , V_24 ) ;
if ( V_9 == V_120 || V_24 [ V_77 ] == NULL )
return F_97 ( & V_14 , V_9 ) ;
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_80 ( V_3 ) )
return F_81 ( V_3 ) ;
V_20 = F_48 ( V_3 , V_24 [ V_77 ] , V_60 ) ;
if ( F_80 ( V_20 ) )
return F_81 ( V_20 ) ;
V_14 . V_3 = V_3 ;
V_14 . V_20 = V_20 ;
return F_94 ( & V_14 ) ;
}
static void F_99 ( struct V_13 * V_14 )
{
F_100 ( V_14 -> V_20 -> V_48 > 0 ) ;
F_22 ( V_14 -> V_20 ) ;
F_93 ( V_14 -> V_3 -> V_107 ) ;
}
int F_101 ( const struct V_64 * V_121 )
{
int V_43 = 0 ;
F_3 ( V_5 ) ;
if ( V_67 [ V_121 -> V_9 ] [ V_121 -> type ] != NULL ) {
V_43 = - V_122 ;
goto V_116;
}
V_67 [ V_121 -> V_9 ] [ V_121 -> type ] = V_121 ;
V_116:
F_5 ( V_5 ) ;
return V_43 ;
}
void F_102 ( const struct V_64 * V_121 )
{
F_3 ( V_5 ) ;
V_67 [ V_121 -> V_9 ] [ V_121 -> type ] = NULL ;
F_5 ( V_5 ) ;
}
static struct V_21 *
F_103 ( const struct V_19 * V_20 , T_3 V_123 ,
T_2 V_60 )
{
struct V_21 * V_22 ;
F_10 (chain, &table->chains, list) {
if ( V_22 -> V_123 == V_123 &&
F_47 ( V_22 , V_60 ) )
return V_22 ;
}
return F_14 ( - V_51 ) ;
}
static struct V_21 * F_104 ( const struct V_19 * V_20 ,
const struct V_23 * V_24 ,
T_2 V_60 )
{
struct V_21 * V_22 ;
if ( V_24 == NULL )
return F_14 ( - V_62 ) ;
F_10 (chain, &table->chains, list) {
if ( ! F_46 ( V_24 , V_22 -> V_61 ) &&
F_47 ( V_22 , V_60 ) )
return V_22 ;
}
return F_14 ( - V_51 ) ;
}
static int F_105 ( struct V_15 * V_16 , struct V_124 T_4 * V_125 )
{
struct V_124 * V_126 , V_127 ;
struct V_23 * V_128 ;
unsigned int V_27 ;
T_3 V_129 , V_130 ;
int V_131 ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
F_106 (cpu) {
V_126 = F_107 ( V_125 , V_131 ) ;
do {
V_27 = F_108 ( & V_126 -> V_132 ) ;
V_129 = V_126 -> V_129 ;
V_130 = V_126 -> V_130 ;
} while ( F_109 ( & V_126 -> V_132 , V_27 ) );
V_127 . V_129 += V_129 ;
V_127 . V_130 += V_130 ;
}
V_128 = F_110 ( V_16 , V_133 ) ;
if ( V_128 == NULL )
goto V_71;
if ( F_111 ( V_16 , V_134 , F_112 ( V_127 . V_129 ) ,
V_135 ) ||
F_111 ( V_16 , V_136 , F_112 ( V_127 . V_130 ) ,
V_135 ) )
goto V_71;
F_113 ( V_16 , V_128 ) ;
return 0 ;
V_71:
return - V_137 ;
}
static int F_114 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_25 , T_1 V_27 , int V_68 , T_1 V_35 ,
int V_9 , const struct V_19 * V_20 ,
const struct V_21 * V_22 )
{
struct V_17 * V_18 ;
struct V_69 * V_70 ;
V_68 |= V_5 << 8 ;
V_18 = F_55 ( V_16 , V_25 , V_27 , V_68 , sizeof( struct V_69 ) , V_35 ) ;
if ( V_18 == NULL )
goto V_71;
V_70 = F_56 ( V_18 ) ;
V_70 -> V_72 = V_9 ;
V_70 -> V_73 = V_74 ;
V_70 -> V_75 = F_57 ( V_1 -> V_7 . V_76 & 0xffff ) ;
if ( F_58 ( V_16 , V_138 , V_20 -> V_61 ) )
goto V_71;
if ( F_111 ( V_16 , V_139 , F_112 ( V_22 -> V_123 ) ,
V_140 ) )
goto V_71;
if ( F_58 ( V_16 , V_141 , V_22 -> V_61 ) )
goto V_71;
if ( V_22 -> V_35 & V_37 ) {
const struct F_25 * V_142 = F_25 ( V_22 ) ;
const struct V_143 * V_38 = & V_142 -> V_38 [ 0 ] ;
struct V_23 * V_128 ;
V_128 = F_110 ( V_16 , V_144 ) ;
if ( V_128 == NULL )
goto V_71;
if ( F_59 ( V_16 , V_145 , F_60 ( V_38 -> V_146 ) ) )
goto V_71;
if ( F_59 ( V_16 , V_147 , F_60 ( V_38 -> V_148 ) ) )
goto V_71;
if ( V_142 -> V_149 [ 0 ] &&
F_58 ( V_16 , V_150 , V_142 -> V_149 ) )
goto V_71;
F_113 ( V_16 , V_128 ) ;
if ( F_59 ( V_16 , V_151 ,
F_60 ( V_142 -> V_152 ) ) )
goto V_71;
if ( F_58 ( V_16 , V_153 , V_142 -> type -> V_61 ) )
goto V_71;
if ( F_105 ( V_16 , F_25 ( V_22 ) -> V_125 ) )
goto V_71;
}
if ( F_59 ( V_16 , V_154 , F_60 ( V_22 -> V_48 ) ) )
goto V_71;
F_61 ( V_16 , V_18 ) ;
return 0 ;
V_71:
F_62 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_115 ( const struct V_13 * V_14 , int V_68 )
{
struct V_15 * V_16 ;
int V_43 ;
if ( ! V_14 -> V_26 &&
! F_64 ( V_14 -> V_1 , V_80 ) )
return 0 ;
V_43 = - V_81 ;
V_16 = F_65 ( V_82 , V_33 ) ;
if ( V_16 == NULL )
goto V_43;
V_43 = F_114 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_14 -> V_27 ,
V_68 , 0 , V_14 -> V_3 -> V_9 , V_14 -> V_20 ,
V_14 -> V_22 ) ;
if ( V_43 < 0 ) {
F_66 ( V_16 ) ;
goto V_43;
}
V_43 = F_67 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_80 ,
V_14 -> V_26 , V_33 ) ;
V_43:
if ( V_43 < 0 ) {
F_68 ( V_14 -> V_1 , V_14 -> V_25 , V_80 ,
V_43 ) ;
}
return V_43 ;
}
static int F_116 ( struct V_15 * V_16 ,
struct V_83 * V_84 )
{
const struct V_69 * V_70 = F_56 ( V_84 -> V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
unsigned int V_85 = 0 , V_86 = V_84 -> args [ 0 ] ;
struct V_1 * V_1 = F_70 ( V_16 -> V_87 ) ;
int V_9 = V_70 -> V_72 ;
F_71 () ;
V_84 -> V_27 = V_1 -> V_7 . V_76 ;
F_72 (afi, &net->nft.af_info, list) {
if ( V_9 != V_88 && V_9 != V_3 -> V_9 )
continue;
F_72 (table, &afi->tables, list) {
F_72 (chain, &table->chains, list) {
if ( V_85 < V_86 )
goto V_89;
if ( V_85 > V_86 )
memset ( & V_84 -> args [ 1 ] , 0 ,
sizeof( V_84 -> args ) - sizeof( V_84 -> args [ 0 ] ) ) ;
if ( ! F_73 ( V_1 , V_22 ) )
continue;
if ( F_114 ( V_16 , V_1 ,
F_16 ( V_84 -> V_16 ) . V_25 ,
V_84 -> V_18 -> V_28 ,
V_46 ,
V_90 ,
V_3 -> V_9 , V_20 , V_22 ) < 0 )
goto V_91;
F_74 ( V_84 , F_75 ( V_16 ) ) ;
V_89:
V_85 ++ ;
}
}
}
V_91:
F_76 () ;
V_84 -> args [ 0 ] = V_85 ;
return V_16 -> V_92 ;
}
static int F_117 ( struct V_1 * V_1 , struct V_93 * V_94 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_69 * V_70 = F_56 ( V_18 ) ;
T_2 V_60 = F_78 ( V_1 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
struct V_15 * V_95 ;
int V_9 = V_70 -> V_72 ;
int V_43 ;
if ( V_18 -> V_96 & V_97 ) {
struct V_98 V_99 = {
. V_100 = F_116 ,
} ;
return F_79 ( V_94 , V_16 , V_18 , & V_99 ) ;
}
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_80 ( V_3 ) )
return F_81 ( V_3 ) ;
V_20 = F_48 ( V_3 , V_24 [ V_138 ] , V_60 ) ;
if ( F_80 ( V_20 ) )
return F_81 ( V_20 ) ;
V_22 = F_104 ( V_20 , V_24 [ V_141 ] , V_60 ) ;
if ( F_80 ( V_22 ) )
return F_81 ( V_22 ) ;
V_95 = F_82 ( V_82 , V_33 ) ;
if ( ! V_95 )
return - V_40 ;
V_43 = F_114 ( V_95 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 , V_46 , 0 ,
V_9 , V_20 , V_22 ) ;
if ( V_43 < 0 )
goto V_43;
return F_83 ( V_94 , V_95 , F_16 ( V_16 ) . V_25 ) ;
V_43:
F_66 ( V_95 ) ;
return V_43 ;
}
static struct V_124 T_4 * F_118 ( const struct V_23 * V_155 )
{
struct V_23 * V_156 [ V_157 + 1 ] ;
struct V_124 T_4 * V_158 ;
struct V_124 * V_125 ;
int V_43 ;
V_43 = F_119 ( V_156 , V_157 , V_155 , V_159 ) ;
if ( V_43 < 0 )
return F_14 ( V_43 ) ;
if ( ! V_156 [ V_136 ] || ! V_156 [ V_134 ] )
return F_14 ( - V_62 ) ;
V_158 = F_120 ( struct V_124 ) ;
if ( V_158 == NULL )
return F_14 ( - V_40 ) ;
F_121 () ;
V_125 = F_122 ( V_158 ) ;
V_125 -> V_130 = F_123 ( F_124 ( V_156 [ V_136 ] ) ) ;
V_125 -> V_129 = F_123 ( F_124 ( V_156 [ V_134 ] ) ) ;
F_125 () ;
return V_158 ;
}
static void F_126 ( struct F_25 * V_22 ,
struct V_124 T_4 * V_158 )
{
if ( V_158 == NULL )
return;
if ( V_22 -> V_125 ) {
struct V_124 T_4 * V_160 =
F_127 ( V_22 -> V_125 ) ;
F_128 ( V_22 -> V_125 , V_158 ) ;
F_129 () ;
F_130 ( V_160 ) ;
} else
F_128 ( V_22 -> V_125 , V_158 ) ;
}
static void F_131 ( struct V_21 * V_22 )
{
F_100 ( V_22 -> V_48 > 0 ) ;
if ( V_22 -> V_35 & V_37 ) {
struct F_25 * V_142 = F_25 ( V_22 ) ;
F_93 ( V_142 -> type -> V_107 ) ;
F_130 ( V_142 -> V_125 ) ;
if ( V_142 -> V_38 [ 0 ] . V_161 != NULL )
F_132 ( V_142 -> V_38 [ 0 ] . V_161 ) ;
F_22 ( V_142 ) ;
} else {
F_22 ( V_22 ) ;
}
}
static int F_133 ( struct V_1 * V_1 , struct V_93 * V_94 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_69 * V_70 = F_56 ( V_18 ) ;
const struct V_23 * V_162 ( V_61 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct F_25 * V_142 = NULL ;
struct V_23 * V_163 [ V_164 + 1 ] ;
T_2 V_60 = F_90 ( V_1 ) ;
int V_9 = V_70 -> V_72 ;
struct V_165 * V_161 = NULL ;
T_2 V_152 = V_166 ;
T_3 V_123 = 0 ;
unsigned int V_65 ;
struct V_124 T_4 * V_125 ;
int V_43 ;
bool V_167 ;
struct V_13 V_14 ;
V_167 = V_18 -> V_96 & V_168 ? true : false ;
V_3 = F_11 ( V_1 , V_9 , true ) ;
if ( F_80 ( V_3 ) )
return F_81 ( V_3 ) ;
V_20 = F_48 ( V_3 , V_24 [ V_138 ] , V_60 ) ;
if ( F_80 ( V_20 ) )
return F_81 ( V_20 ) ;
V_22 = NULL ;
V_61 = V_24 [ V_141 ] ;
if ( V_24 [ V_139 ] ) {
V_123 = F_123 ( F_124 ( V_24 [ V_139 ] ) ) ;
V_22 = F_103 ( V_20 , V_123 , V_60 ) ;
if ( F_80 ( V_22 ) )
return F_81 ( V_22 ) ;
} else {
V_22 = F_104 ( V_20 , V_61 , V_60 ) ;
if ( F_80 ( V_22 ) ) {
if ( F_81 ( V_22 ) != - V_51 )
return F_81 ( V_22 ) ;
V_22 = NULL ;
}
}
if ( V_24 [ V_151 ] ) {
if ( ( V_22 != NULL &&
! ( V_22 -> V_35 & V_37 ) ) )
return - V_106 ;
if ( V_22 == NULL &&
V_24 [ V_144 ] == NULL )
return - V_106 ;
V_152 = F_42 ( F_43 ( V_24 [ V_151 ] ) ) ;
switch ( V_152 ) {
case V_169 :
case V_166 :
break;
default:
return - V_62 ;
}
}
if ( V_22 != NULL ) {
struct V_124 * V_125 = NULL ;
struct V_29 * V_32 ;
if ( V_18 -> V_96 & V_103 )
return - V_104 ;
if ( V_18 -> V_96 & V_105 )
return - V_106 ;
if ( V_24 [ V_139 ] && V_61 ) {
struct V_21 * V_170 ;
V_170 = F_104 ( V_20 ,
V_24 [ V_141 ] ,
V_60 ) ;
if ( F_80 ( V_170 ) )
return F_81 ( V_170 ) ;
}
if ( V_24 [ V_133 ] ) {
if ( ! ( V_22 -> V_35 & V_37 ) )
return - V_106 ;
V_125 = F_118 ( V_24 [ V_133 ] ) ;
if ( F_80 ( V_125 ) )
return F_81 ( V_125 ) ;
}
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_32 = F_18 ( & V_14 , V_46 ,
sizeof( struct V_45 ) ) ;
if ( V_32 == NULL ) {
F_130 ( V_125 ) ;
return - V_40 ;
}
F_134 ( V_32 ) = V_125 ;
F_135 ( V_32 ) = true ;
if ( V_24 [ V_151 ] )
F_136 ( V_32 ) = V_152 ;
else
F_136 ( V_32 ) = - 1 ;
if ( V_24 [ V_139 ] && V_61 ) {
F_92 ( F_137 ( V_32 ) , V_61 ,
V_171 ) ;
}
F_30 ( & V_32 -> V_6 , & V_1 -> V_7 . V_42 ) ;
return 0 ;
}
if ( V_20 -> V_48 == V_172 )
return - V_173 ;
if ( V_24 [ V_144 ] ) {
const struct V_64 * type ;
struct V_143 * V_38 ;
T_5 * V_174 ;
T_1 V_146 , V_148 ;
type = V_67 [ V_9 ] [ V_175 ] ;
if ( V_24 [ V_153 ] ) {
type = F_51 ( V_3 ,
V_24 [ V_153 ] ,
V_167 ) ;
if ( F_80 ( type ) )
return F_81 ( type ) ;
}
V_43 = F_119 ( V_163 , V_164 , V_24 [ V_144 ] ,
V_176 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_163 [ V_145 ] == NULL ||
V_163 [ V_147 ] == NULL )
return - V_62 ;
V_146 = F_42 ( F_43 ( V_163 [ V_145 ] ) ) ;
if ( V_146 >= V_3 -> V_177 )
return - V_62 ;
V_148 = F_42 ( F_43 ( V_163 [ V_147 ] ) ) ;
if ( ! ( type -> V_178 & ( 1 << V_146 ) ) )
return - V_106 ;
if ( ! F_91 ( type -> V_107 ) )
return - V_51 ;
V_174 = type -> V_179 [ V_146 ] ;
if ( V_3 -> V_35 & V_180 ) {
char V_181 [ V_182 ] ;
if ( ! V_163 [ V_150 ] ) {
F_93 ( type -> V_107 ) ;
return - V_106 ;
}
F_92 ( V_181 , V_163 [ V_150 ] , V_182 ) ;
V_161 = F_138 ( V_1 , V_181 ) ;
if ( ! V_161 ) {
F_93 ( type -> V_107 ) ;
return - V_51 ;
}
} else if ( V_163 [ V_150 ] ) {
F_93 ( type -> V_107 ) ;
return - V_106 ;
}
V_142 = F_19 ( sizeof( * V_142 ) , V_33 ) ;
if ( V_142 == NULL ) {
F_93 ( type -> V_107 ) ;
if ( V_161 != NULL )
F_132 ( V_161 ) ;
return - V_40 ;
}
if ( V_161 != NULL )
strncpy ( V_142 -> V_149 , V_161 -> V_61 , V_182 ) ;
if ( V_24 [ V_133 ] ) {
V_125 = F_118 ( V_24 [ V_133 ] ) ;
if ( F_80 ( V_125 ) ) {
F_93 ( type -> V_107 ) ;
F_22 ( V_142 ) ;
if ( V_161 != NULL )
F_132 ( V_161 ) ;
return F_81 ( V_125 ) ;
}
V_142 -> V_125 = V_125 ;
} else {
V_125 = F_120 ( struct V_124 ) ;
if ( V_125 == NULL ) {
F_93 ( type -> V_107 ) ;
F_22 ( V_142 ) ;
if ( V_161 != NULL )
F_132 ( V_161 ) ;
return - V_40 ;
}
F_128 ( V_142 -> V_125 , V_125 ) ;
}
V_142 -> type = type ;
V_22 = & V_142 -> V_22 ;
for ( V_65 = 0 ; V_65 < V_3 -> V_101 ; V_65 ++ ) {
V_38 = & V_142 -> V_38 [ V_65 ] ;
V_38 -> V_183 = V_9 ;
V_38 -> V_146 = V_146 ;
V_38 -> V_148 = V_148 ;
V_38 -> V_184 = V_22 ;
V_38 -> V_185 = V_3 -> V_179 [ V_38 -> V_146 ] ;
V_38 -> V_161 = V_161 ;
if ( V_174 )
V_38 -> V_185 = V_174 ;
if ( V_3 -> V_186 )
V_3 -> V_186 ( V_38 , V_65 ) ;
}
V_22 -> V_35 |= V_37 ;
V_142 -> V_152 = V_152 ;
} else {
V_22 = F_19 ( sizeof( * V_22 ) , V_33 ) ;
if ( V_22 == NULL )
return - V_40 ;
}
F_2 ( & V_22 -> V_187 ) ;
V_22 -> V_123 = F_49 ( V_20 ) ;
V_22 -> V_20 = V_20 ;
F_92 ( V_22 -> V_61 , V_61 , V_171 ) ;
V_43 = F_23 ( V_1 , V_20 , V_22 , V_3 -> V_101 ) ;
if ( V_43 < 0 )
goto V_108;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_43 = F_33 ( & V_14 , V_46 ) ;
if ( V_43 < 0 )
goto V_109;
V_20 -> V_48 ++ ;
F_4 ( & V_22 -> V_6 , & V_20 -> V_111 ) ;
return 0 ;
V_109:
F_26 ( V_1 , V_20 , V_22 , V_3 -> V_101 ) ;
V_108:
F_131 ( V_22 ) ;
return V_43 ;
}
static int F_139 ( struct V_1 * V_1 , struct V_93 * V_94 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_69 * V_70 = F_56 ( V_18 ) ;
T_2 V_60 = F_90 ( V_1 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
int V_9 = V_70 -> V_72 ;
struct V_13 V_14 ;
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_80 ( V_3 ) )
return F_81 ( V_3 ) ;
V_20 = F_48 ( V_3 , V_24 [ V_138 ] , V_60 ) ;
if ( F_80 ( V_20 ) )
return F_81 ( V_20 ) ;
V_22 = F_104 ( V_20 , V_24 [ V_141 ] , V_60 ) ;
if ( F_80 ( V_22 ) )
return F_81 ( V_22 ) ;
if ( V_22 -> V_48 > 0 )
return - V_122 ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
return F_34 ( & V_14 ) ;
}
int F_140 ( struct V_188 * type )
{
F_3 ( V_5 ) ;
if ( type -> V_9 == V_88 )
F_4 ( & type -> V_6 , & V_189 ) ;
else
F_141 ( & type -> V_6 , & V_189 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_142 ( struct V_188 * type )
{
F_3 ( V_5 ) ;
F_8 ( & type -> V_6 ) ;
F_5 ( V_5 ) ;
}
static const struct V_188 * F_143 ( T_2 V_9 ,
struct V_23 * V_24 )
{
const struct V_188 * type ;
F_10 (type, &nf_tables_expressions, list) {
if ( ! F_46 ( V_24 , type -> V_61 ) &&
( ! type -> V_9 || type -> V_9 == V_9 ) )
return type ;
}
return NULL ;
}
static const struct V_188 * F_144 ( T_2 V_9 ,
struct V_23 * V_24 )
{
const struct V_188 * type ;
if ( V_24 == NULL )
return F_14 ( - V_62 ) ;
type = F_143 ( V_9 , V_24 ) ;
if ( type != NULL && F_91 ( type -> V_107 ) )
return type ;
#ifdef F_12
if ( type == NULL ) {
F_5 ( V_5 ) ;
F_13 ( L_3 , V_9 ,
F_52 ( V_24 ) , ( char * ) F_53 ( V_24 ) ) ;
F_3 ( V_5 ) ;
if ( F_143 ( V_9 , V_24 ) )
return F_14 ( - V_11 ) ;
F_5 ( V_5 ) ;
F_13 ( L_4 ,
F_52 ( V_24 ) , ( char * ) F_53 ( V_24 ) ) ;
F_3 ( V_5 ) ;
if ( F_143 ( V_9 , V_24 ) )
return F_14 ( - V_11 ) ;
}
#endif
return F_14 ( - V_51 ) ;
}
static int F_145 ( struct V_15 * V_16 ,
const struct V_190 * V_191 )
{
if ( F_58 ( V_16 , V_192 , V_191 -> V_38 -> type -> V_61 ) )
goto V_71;
if ( V_191 -> V_38 -> V_100 ) {
struct V_23 * V_193 = F_110 ( V_16 , V_194 ) ;
if ( V_193 == NULL )
goto V_71;
if ( V_191 -> V_38 -> V_100 ( V_16 , V_191 ) < 0 )
goto V_71;
F_113 ( V_16 , V_193 ) ;
}
return V_16 -> V_92 ;
V_71:
return - 1 ;
}
int F_146 ( struct V_15 * V_16 , unsigned int V_155 ,
const struct V_190 * V_191 )
{
struct V_23 * V_128 ;
V_128 = F_110 ( V_16 , V_155 ) ;
if ( ! V_128 )
goto V_71;
if ( F_145 ( V_16 , V_191 ) < 0 )
goto V_71;
F_113 ( V_16 , V_128 ) ;
return 0 ;
V_71:
return - 1 ;
}
static int F_147 ( const struct V_13 * V_14 ,
const struct V_23 * V_24 ,
struct V_195 * V_196 )
{
const struct V_188 * type ;
const struct V_197 * V_38 ;
struct V_23 * V_156 [ V_198 + 1 ] ;
int V_43 ;
V_43 = F_119 ( V_156 , V_198 , V_24 , V_199 ) ;
if ( V_43 < 0 )
return V_43 ;
type = F_144 ( V_14 -> V_3 -> V_9 , V_156 [ V_192 ] ) ;
if ( F_80 ( type ) )
return F_81 ( type ) ;
if ( V_156 [ V_194 ] ) {
V_43 = F_119 ( V_196 -> V_156 , type -> V_200 ,
V_156 [ V_194 ] , type -> V_152 ) ;
if ( V_43 < 0 )
goto V_108;
} else
memset ( V_196 -> V_156 , 0 , sizeof( V_196 -> V_156 [ 0 ] ) * ( type -> V_200 + 1 ) ) ;
if ( type -> V_201 != NULL ) {
V_38 = type -> V_201 ( V_14 ,
( const struct V_23 * const * ) V_196 -> V_156 ) ;
if ( F_80 ( V_38 ) ) {
V_43 = F_81 ( V_38 ) ;
goto V_108;
}
} else
V_38 = type -> V_38 ;
V_196 -> V_38 = V_38 ;
return 0 ;
V_108:
F_93 ( type -> V_107 ) ;
return V_43 ;
}
static int F_148 ( const struct V_13 * V_14 ,
const struct V_195 * V_196 ,
struct V_190 * V_191 )
{
const struct V_197 * V_38 = V_196 -> V_38 ;
int V_43 ;
V_191 -> V_38 = V_38 ;
if ( V_38 -> V_202 ) {
V_43 = V_38 -> V_202 ( V_14 , V_191 , ( const struct V_23 * * ) V_196 -> V_156 ) ;
if ( V_43 < 0 )
goto V_108;
}
return 0 ;
V_108:
V_191 -> V_38 = NULL ;
return V_43 ;
}
static void F_149 ( const struct V_13 * V_14 ,
struct V_190 * V_191 )
{
if ( V_191 -> V_38 -> V_203 )
V_191 -> V_38 -> V_203 ( V_14 , V_191 ) ;
F_93 ( V_191 -> V_38 -> type -> V_107 ) ;
}
struct V_190 * F_150 ( const struct V_13 * V_14 ,
const struct V_23 * V_24 )
{
struct V_195 V_196 ;
struct V_190 * V_191 ;
int V_43 ;
V_43 = F_147 ( V_14 , V_24 , & V_196 ) ;
if ( V_43 < 0 )
goto V_108;
V_43 = - V_40 ;
V_191 = F_19 ( V_196 . V_38 -> V_31 , V_33 ) ;
if ( V_191 == NULL )
goto V_109;
V_43 = F_148 ( V_14 , & V_196 , V_191 ) ;
if ( V_43 < 0 )
goto V_113;
return V_191 ;
V_113:
F_22 ( V_191 ) ;
V_109:
F_93 ( V_196 . V_38 -> type -> V_107 ) ;
V_108:
return F_14 ( V_43 ) ;
}
void F_151 ( const struct V_13 * V_14 , struct V_190 * V_191 )
{
F_149 ( V_14 , V_191 ) ;
F_22 ( V_191 ) ;
}
static struct V_49 * F_152 ( const struct V_21 * V_22 ,
T_3 V_123 )
{
struct V_49 * V_50 ;
F_10 (rule, &chain->rules, list) {
if ( V_123 == V_50 -> V_123 )
return V_50 ;
}
return F_14 ( - V_51 ) ;
}
static struct V_49 * F_153 ( const struct V_21 * V_22 ,
const struct V_23 * V_24 )
{
if ( V_24 == NULL )
return F_14 ( - V_62 ) ;
return F_152 ( V_22 , F_123 ( F_124 ( V_24 ) ) ) ;
}
static int F_154 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_25 , T_1 V_27 , int V_68 ,
T_1 V_35 , int V_9 ,
const struct V_19 * V_20 ,
const struct V_21 * V_22 ,
const struct V_49 * V_50 )
{
struct V_17 * V_18 ;
struct V_69 * V_70 ;
const struct V_190 * V_191 , * V_204 ;
struct V_23 * V_6 ;
const struct V_49 * V_205 ;
int type = V_68 | V_5 << 8 ;
V_18 = F_55 ( V_16 , V_25 , V_27 , type , sizeof( struct V_69 ) ,
V_35 ) ;
if ( V_18 == NULL )
goto V_71;
V_70 = F_56 ( V_18 ) ;
V_70 -> V_72 = V_9 ;
V_70 -> V_73 = V_74 ;
V_70 -> V_75 = F_57 ( V_1 -> V_7 . V_76 & 0xffff ) ;
if ( F_58 ( V_16 , V_206 , V_20 -> V_61 ) )
goto V_71;
if ( F_58 ( V_16 , V_207 , V_22 -> V_61 ) )
goto V_71;
if ( F_111 ( V_16 , V_208 , F_112 ( V_50 -> V_123 ) ,
V_209 ) )
goto V_71;
if ( ( V_68 != V_53 ) && ( V_50 -> V_6 . V_210 != & V_22 -> V_187 ) ) {
V_205 = F_155 ( V_50 -> V_6 . V_210 , struct V_49 , V_6 ) ;
if ( F_111 ( V_16 , V_211 ,
F_112 ( V_205 -> V_123 ) ,
V_209 ) )
goto V_71;
}
V_6 = F_110 ( V_16 , V_212 ) ;
if ( V_6 == NULL )
goto V_71;
F_156 (expr, next, rule) {
if ( F_146 ( V_16 , V_213 , V_191 ) < 0 )
goto V_71;
}
F_113 ( V_16 , V_6 ) ;
if ( V_50 -> V_214 ) {
struct V_215 * V_214 = V_215 ( V_50 ) ;
if ( F_157 ( V_16 , V_216 , V_214 -> V_92 + 1 ,
V_214 -> V_193 ) < 0 )
goto V_71;
}
F_61 ( V_16 , V_18 ) ;
return 0 ;
V_71:
F_62 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_158 ( const struct V_13 * V_14 ,
const struct V_49 * V_50 ,
int V_68 )
{
struct V_15 * V_16 ;
int V_43 ;
if ( ! V_14 -> V_26 &&
! F_64 ( V_14 -> V_1 , V_80 ) )
return 0 ;
V_43 = - V_81 ;
V_16 = F_65 ( V_82 , V_33 ) ;
if ( V_16 == NULL )
goto V_43;
V_43 = F_154 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_14 -> V_27 ,
V_68 , 0 , V_14 -> V_3 -> V_9 , V_14 -> V_20 ,
V_14 -> V_22 , V_50 ) ;
if ( V_43 < 0 ) {
F_66 ( V_16 ) ;
goto V_43;
}
V_43 = F_67 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_80 ,
V_14 -> V_26 , V_33 ) ;
V_43:
if ( V_43 < 0 ) {
F_68 ( V_14 -> V_1 , V_14 -> V_25 , V_80 ,
V_43 ) ;
}
return V_43 ;
}
static int F_159 ( struct V_15 * V_16 ,
struct V_83 * V_84 )
{
const struct V_69 * V_70 = F_56 ( V_84 -> V_18 ) ;
const struct V_217 * V_14 = V_84 -> V_193 ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
const struct V_49 * V_50 ;
unsigned int V_85 = 0 , V_86 = V_84 -> args [ 0 ] ;
struct V_1 * V_1 = F_70 ( V_16 -> V_87 ) ;
int V_9 = V_70 -> V_72 ;
F_71 () ;
V_84 -> V_27 = V_1 -> V_7 . V_76 ;
F_72 (afi, &net->nft.af_info, list) {
if ( V_9 != V_88 && V_9 != V_3 -> V_9 )
continue;
F_72 (table, &afi->tables, list) {
if ( V_14 && V_14 -> V_20 [ 0 ] &&
strcmp ( V_14 -> V_20 , V_20 -> V_61 ) != 0 )
continue;
F_72 (chain, &table->chains, list) {
if ( V_14 && V_14 -> V_22 [ 0 ] &&
strcmp ( V_14 -> V_22 , V_22 -> V_61 ) != 0 )
continue;
F_72 (rule, &chain->rules, list) {
if ( ! F_73 ( V_1 , V_50 ) )
goto V_89;
if ( V_85 < V_86 )
goto V_89;
if ( V_85 > V_86 )
memset ( & V_84 -> args [ 1 ] , 0 ,
sizeof( V_84 -> args ) - sizeof( V_84 -> args [ 0 ] ) ) ;
if ( F_154 ( V_16 , V_1 , F_16 ( V_84 -> V_16 ) . V_25 ,
V_84 -> V_18 -> V_28 ,
V_218 ,
V_90 | V_219 ,
V_3 -> V_9 , V_20 , V_22 , V_50 ) < 0 )
goto V_91;
F_74 ( V_84 , F_75 ( V_16 ) ) ;
V_89:
V_85 ++ ;
}
}
}
}
V_91:
F_76 () ;
V_84 -> args [ 0 ] = V_85 ;
return V_16 -> V_92 ;
}
static int F_160 ( struct V_83 * V_84 )
{
F_22 ( V_84 -> V_193 ) ;
return 0 ;
}
static int F_161 ( struct V_1 * V_1 , struct V_93 * V_94 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_69 * V_70 = F_56 ( V_18 ) ;
T_2 V_60 = F_78 ( V_1 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
const struct V_49 * V_50 ;
struct V_15 * V_95 ;
int V_9 = V_70 -> V_72 ;
int V_43 ;
if ( V_18 -> V_96 & V_97 ) {
struct V_98 V_99 = {
. V_100 = F_159 ,
. V_91 = F_160 ,
} ;
if ( V_24 [ V_206 ] || V_24 [ V_207 ] ) {
struct V_217 * V_14 ;
V_14 = F_19 ( sizeof( * V_14 ) , V_33 ) ;
if ( ! V_14 )
return - V_40 ;
if ( V_24 [ V_206 ] )
F_92 ( V_14 -> V_20 , V_24 [ V_206 ] ,
sizeof( V_14 -> V_20 ) ) ;
if ( V_24 [ V_207 ] )
F_92 ( V_14 -> V_22 , V_24 [ V_207 ] ,
sizeof( V_14 -> V_22 ) ) ;
V_99 . V_193 = V_14 ;
}
return F_79 ( V_94 , V_16 , V_18 , & V_99 ) ;
}
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_80 ( V_3 ) )
return F_81 ( V_3 ) ;
V_20 = F_48 ( V_3 , V_24 [ V_206 ] , V_60 ) ;
if ( F_80 ( V_20 ) )
return F_81 ( V_20 ) ;
V_22 = F_104 ( V_20 , V_24 [ V_207 ] , V_60 ) ;
if ( F_80 ( V_22 ) )
return F_81 ( V_22 ) ;
V_50 = F_153 ( V_22 , V_24 [ V_208 ] ) ;
if ( F_80 ( V_50 ) )
return F_81 ( V_50 ) ;
V_95 = F_82 ( V_82 , V_33 ) ;
if ( ! V_95 )
return - V_40 ;
V_43 = F_154 ( V_95 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 , V_218 , 0 ,
V_9 , V_20 , V_22 , V_50 ) ;
if ( V_43 < 0 )
goto V_43;
return F_83 ( V_94 , V_95 , F_16 ( V_16 ) . V_25 ) ;
V_43:
F_66 ( V_95 ) ;
return V_43 ;
}
static void F_162 ( const struct V_13 * V_14 ,
struct V_49 * V_50 )
{
struct V_190 * V_191 ;
V_191 = F_163 ( V_50 ) ;
while ( V_191 -> V_38 && V_191 != F_164 ( V_50 ) ) {
F_149 ( V_14 , V_191 ) ;
V_191 = F_165 ( V_191 ) ;
}
F_22 ( V_50 ) ;
}
static int F_166 ( struct V_1 * V_1 , struct V_93 * V_94 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_69 * V_70 = F_56 ( V_18 ) ;
T_2 V_60 = F_90 ( V_1 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_49 * V_50 , * V_220 = NULL ;
struct V_215 * V_214 ;
struct V_29 * V_32 = NULL ;
struct V_190 * V_191 ;
struct V_13 V_14 ;
struct V_23 * V_221 ;
unsigned int V_31 , V_65 , V_222 , V_223 = 0 , V_224 = 0 ;
int V_43 , V_225 ;
bool V_167 ;
T_3 V_123 , V_226 ;
V_167 = V_18 -> V_96 & V_168 ? true : false ;
V_3 = F_11 ( V_1 , V_70 -> V_72 , V_167 ) ;
if ( F_80 ( V_3 ) )
return F_81 ( V_3 ) ;
V_20 = F_48 ( V_3 , V_24 [ V_206 ] , V_60 ) ;
if ( F_80 ( V_20 ) )
return F_81 ( V_20 ) ;
V_22 = F_104 ( V_20 , V_24 [ V_207 ] , V_60 ) ;
if ( F_80 ( V_22 ) )
return F_81 ( V_22 ) ;
if ( V_24 [ V_208 ] ) {
V_123 = F_123 ( F_124 ( V_24 [ V_208 ] ) ) ;
V_50 = F_152 ( V_22 , V_123 ) ;
if ( F_80 ( V_50 ) )
return F_81 ( V_50 ) ;
if ( V_18 -> V_96 & V_103 )
return - V_104 ;
if ( V_18 -> V_96 & V_105 )
V_220 = V_50 ;
else
return - V_106 ;
} else {
if ( ! V_167 || V_18 -> V_96 & V_105 )
return - V_62 ;
V_123 = F_49 ( V_20 ) ;
if ( V_22 -> V_48 == V_172 )
return - V_173 ;
}
if ( V_24 [ V_211 ] ) {
if ( ! ( V_18 -> V_96 & V_168 ) )
return - V_106 ;
V_226 = F_123 ( F_124 ( V_24 [ V_211 ] ) ) ;
V_220 = F_152 ( V_22 , V_226 ) ;
if ( F_80 ( V_220 ) )
return F_81 ( V_220 ) ;
}
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_222 = 0 ;
V_31 = 0 ;
if ( V_24 [ V_212 ] ) {
F_167 (tmp, nla[NFTA_RULE_EXPRESSIONS], rem) {
V_43 = - V_62 ;
if ( F_168 ( V_221 ) != V_213 )
goto V_108;
if ( V_222 == V_227 )
goto V_108;
V_43 = F_147 ( & V_14 , V_221 , & V_196 [ V_222 ] ) ;
if ( V_43 < 0 )
goto V_108;
V_31 += V_196 [ V_222 ] . V_38 -> V_31 ;
V_222 ++ ;
}
}
V_43 = - V_228 ;
if ( V_31 >= 1 << 12 )
goto V_108;
if ( V_24 [ V_216 ] ) {
V_223 = F_52 ( V_24 [ V_216 ] ) ;
if ( V_223 > 0 )
V_224 = sizeof( struct V_215 ) + V_223 ;
}
V_43 = - V_40 ;
V_50 = F_19 ( sizeof( * V_50 ) + V_31 + V_224 , V_33 ) ;
if ( V_50 == NULL )
goto V_108;
F_29 ( V_1 , V_50 ) ;
V_50 -> V_123 = V_123 ;
V_50 -> V_229 = V_31 ;
V_50 -> V_214 = V_223 ? 1 : 0 ;
if ( V_223 ) {
V_214 = V_215 ( V_50 ) ;
V_214 -> V_92 = V_223 - 1 ;
F_169 ( V_214 -> V_193 , V_24 [ V_216 ] , V_223 ) ;
}
V_191 = F_163 ( V_50 ) ;
for ( V_65 = 0 ; V_65 < V_222 ; V_65 ++ ) {
V_43 = F_148 ( & V_14 , & V_196 [ V_65 ] , V_191 ) ;
if ( V_43 < 0 )
goto V_109;
V_196 [ V_65 ] . V_38 = NULL ;
V_191 = F_165 ( V_191 ) ;
}
if ( V_18 -> V_96 & V_105 ) {
if ( F_36 ( V_1 , V_220 ) ) {
V_32 = F_37 ( & V_14 , V_53 ,
V_220 ) ;
if ( V_32 == NULL ) {
V_43 = - V_40 ;
goto V_109;
}
F_32 ( V_1 , V_220 ) ;
V_22 -> V_48 -- ;
F_4 ( & V_50 -> V_6 , & V_220 -> V_6 ) ;
} else {
V_43 = - V_51 ;
goto V_109;
}
} else if ( V_18 -> V_96 & V_219 )
if ( V_220 )
F_141 ( & V_50 -> V_6 , & V_220 -> V_6 ) ;
else
F_4 ( & V_50 -> V_6 , & V_22 -> V_187 ) ;
else {
if ( V_220 )
F_4 ( & V_50 -> V_6 , & V_220 -> V_6 ) ;
else
F_141 ( & V_50 -> V_6 , & V_22 -> V_187 ) ;
}
if ( F_37 ( & V_14 , V_218 , V_50 ) == NULL ) {
V_43 = - V_40 ;
goto V_113;
}
V_22 -> V_48 ++ ;
return 0 ;
V_113:
F_8 ( & V_50 -> V_6 ) ;
V_109:
F_162 ( & V_14 , V_50 ) ;
V_108:
for ( V_65 = 0 ; V_65 < V_222 ; V_65 ++ ) {
if ( V_196 [ V_65 ] . V_38 != NULL )
F_93 ( V_196 [ V_65 ] . V_38 -> type -> V_107 ) ;
}
return V_43 ;
}
static int F_170 ( struct V_1 * V_1 , struct V_93 * V_94 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_69 * V_70 = F_56 ( V_18 ) ;
T_2 V_60 = F_90 ( V_1 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 = NULL ;
struct V_49 * V_50 ;
int V_9 = V_70 -> V_72 , V_43 = 0 ;
struct V_13 V_14 ;
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_80 ( V_3 ) )
return F_81 ( V_3 ) ;
V_20 = F_48 ( V_3 , V_24 [ V_206 ] , V_60 ) ;
if ( F_80 ( V_20 ) )
return F_81 ( V_20 ) ;
if ( V_24 [ V_207 ] ) {
V_22 = F_104 ( V_20 , V_24 [ V_207 ] ,
V_60 ) ;
if ( F_80 ( V_22 ) )
return F_81 ( V_22 ) ;
}
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
if ( V_22 ) {
if ( V_24 [ V_208 ] ) {
V_50 = F_153 ( V_22 ,
V_24 [ V_208 ] ) ;
if ( F_80 ( V_50 ) )
return F_81 ( V_50 ) ;
V_43 = F_38 ( & V_14 , V_50 ) ;
} else {
V_43 = F_39 ( & V_14 ) ;
}
} else {
F_10 (chain, &table->chains, list) {
if ( ! F_36 ( V_1 , V_22 ) )
continue;
V_14 . V_22 = V_22 ;
V_43 = F_39 ( & V_14 ) ;
if ( V_43 < 0 )
break;
}
}
return V_43 ;
}
int F_171 ( struct V_230 * V_38 )
{
F_3 ( V_5 ) ;
F_4 ( & V_38 -> V_6 , & V_231 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_172 ( struct V_230 * V_38 )
{
F_3 ( V_5 ) ;
F_8 ( & V_38 -> V_6 ) ;
F_5 ( V_5 ) ;
}
static const struct V_230 *
F_173 ( const struct V_23 * const V_24 [] ,
const struct V_232 * V_233 ,
enum V_234 V_152 )
{
const struct V_230 * V_38 , * V_235 ;
struct V_236 V_237 , V_238 ;
T_1 V_239 ;
#ifdef F_12
if ( F_96 ( & V_231 ) ) {
F_5 ( V_5 ) ;
F_13 ( L_5 ) ;
F_3 ( V_5 ) ;
if ( ! F_96 ( & V_231 ) )
return F_14 ( - V_11 ) ;
}
#endif
V_239 = 0 ;
if ( V_24 [ V_240 ] != NULL ) {
V_239 = F_42 ( F_43 ( V_24 [ V_240 ] ) ) ;
V_239 &= V_241 | V_242 | V_243 ;
}
V_235 = NULL ;
V_238 . V_31 = ~ 0 ;
V_238 . V_244 = ~ 0 ;
F_10 (ops, &nf_tables_set_ops, list) {
if ( ( V_38 -> V_239 & V_239 ) != V_239 )
continue;
if ( ! V_38 -> V_245 ( V_233 , V_239 , & V_237 ) )
continue;
switch ( V_152 ) {
case V_246 :
if ( V_237 . V_244 < V_238 . V_244 )
break;
if ( V_237 . V_244 == V_238 . V_244 && V_237 . V_31 < V_238 . V_31 )
break;
continue;
case V_247 :
if ( V_237 . V_31 < V_238 . V_31 )
break;
if ( V_237 . V_31 == V_238 . V_31 && V_237 . V_244 < V_238 . V_244 )
break;
continue;
default:
break;
}
if ( ! F_91 ( V_38 -> V_107 ) )
continue;
if ( V_235 != NULL )
F_93 ( V_235 -> V_107 ) ;
V_235 = V_38 ;
V_238 = V_237 ;
}
if ( V_235 != NULL )
return V_235 ;
return F_14 ( - V_106 ) ;
}
static int F_174 ( struct V_13 * V_14 , struct V_1 * V_1 ,
const struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
T_2 V_60 )
{
const struct V_69 * V_70 = F_56 ( V_18 ) ;
struct V_2 * V_3 = NULL ;
struct V_19 * V_20 = NULL ;
if ( V_70 -> V_72 != V_88 ) {
V_3 = F_11 ( V_1 , V_70 -> V_72 , false ) ;
if ( F_80 ( V_3 ) )
return F_81 ( V_3 ) ;
}
if ( V_24 [ V_248 ] != NULL ) {
if ( V_3 == NULL )
return - V_12 ;
V_20 = F_48 ( V_3 , V_24 [ V_248 ] ,
V_60 ) ;
if ( F_80 ( V_20 ) )
return F_81 ( V_20 ) ;
}
F_15 ( V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return 0 ;
}
struct V_54 * F_175 ( const struct V_19 * V_20 ,
const struct V_23 * V_24 , T_2 V_60 )
{
struct V_54 * V_55 ;
if ( V_24 == NULL )
return F_14 ( - V_62 ) ;
F_10 (set, &table->sets, list) {
if ( ! F_46 ( V_24 , V_55 -> V_61 ) &&
F_47 ( V_55 , V_60 ) )
return V_55 ;
}
return F_14 ( - V_51 ) ;
}
struct V_54 * F_176 ( const struct V_1 * V_1 ,
const struct V_23 * V_24 ,
T_2 V_60 )
{
struct V_29 * V_32 ;
T_1 V_249 = F_42 ( F_43 ( V_24 ) ) ;
F_10 (trans, &net->nft.commit_list, list) {
struct V_54 * V_55 = V_56 ( V_32 ) ;
if ( V_32 -> V_30 == V_57 &&
V_249 == F_41 ( V_32 ) &&
F_47 ( V_55 , V_60 ) )
return V_55 ;
}
return F_14 ( - V_51 ) ;
}
static int F_177 ( struct V_13 * V_14 , struct V_54 * V_55 ,
const char * V_61 )
{
const struct V_54 * V_65 ;
const char * V_250 ;
unsigned long * V_251 ;
unsigned int V_222 = 0 , V_252 = 0 ;
V_250 = F_178 ( V_61 , V_253 , '%' ) ;
if ( V_250 != NULL ) {
if ( V_250 [ 1 ] != 'd' || strchr ( V_250 + 2 , '%' ) )
return - V_62 ;
V_251 = ( unsigned long * ) F_179 ( V_33 ) ;
if ( V_251 == NULL )
return - V_40 ;
V_89:
F_10 (i, &ctx->table->sets, list) {
int V_221 ;
if ( ! F_36 ( V_14 -> V_1 , V_55 ) )
continue;
if ( ! sscanf ( V_65 -> V_61 , V_61 , & V_221 ) )
continue;
if ( V_221 < V_252 || V_221 >= V_252 + V_254 * V_255 )
continue;
F_180 ( V_221 - V_252 , V_251 ) ;
}
V_222 = F_181 ( V_251 , V_254 * V_255 ) ;
if ( V_222 >= V_254 * V_255 ) {
V_252 += V_254 * V_255 ;
memset ( V_251 , 0 , V_255 ) ;
goto V_89;
}
F_182 ( ( unsigned long ) V_251 ) ;
}
snprintf ( V_55 -> V_61 , sizeof( V_55 -> V_61 ) , V_61 , V_252 + V_222 ) ;
F_10 (i, &ctx->table->sets, list) {
if ( ! F_36 ( V_14 -> V_1 , V_65 ) )
continue;
if ( ! strcmp ( V_55 -> V_61 , V_65 -> V_61 ) )
return - V_256 ;
}
return 0 ;
}
static int F_183 ( struct V_15 * V_16 , const struct V_13 * V_14 ,
const struct V_54 * V_55 , T_6 V_68 , T_6 V_35 )
{
struct V_69 * V_70 ;
struct V_17 * V_18 ;
struct V_23 * V_233 ;
T_1 V_25 = V_14 -> V_25 ;
T_1 V_27 = V_14 -> V_27 ;
V_68 |= V_5 << 8 ;
V_18 = F_55 ( V_16 , V_25 , V_27 , V_68 , sizeof( struct V_69 ) ,
V_35 ) ;
if ( V_18 == NULL )
goto V_71;
V_70 = F_56 ( V_18 ) ;
V_70 -> V_72 = V_14 -> V_3 -> V_9 ;
V_70 -> V_73 = V_74 ;
V_70 -> V_75 = F_57 ( V_14 -> V_1 -> V_7 . V_76 & 0xffff ) ;
if ( F_58 ( V_16 , V_248 , V_14 -> V_20 -> V_61 ) )
goto V_71;
if ( F_58 ( V_16 , V_257 , V_55 -> V_61 ) )
goto V_71;
if ( V_55 -> V_35 != 0 )
if ( F_59 ( V_16 , V_240 , F_60 ( V_55 -> V_35 ) ) )
goto V_71;
if ( F_59 ( V_16 , V_258 , F_60 ( V_55 -> V_259 ) ) )
goto V_71;
if ( F_59 ( V_16 , V_260 , F_60 ( V_55 -> V_261 ) ) )
goto V_71;
if ( V_55 -> V_35 & V_242 ) {
if ( F_59 ( V_16 , V_262 , F_60 ( V_55 -> V_263 ) ) )
goto V_71;
if ( F_59 ( V_16 , V_264 , F_60 ( V_55 -> V_229 ) ) )
goto V_71;
}
if ( V_55 -> V_265 &&
F_111 ( V_16 , V_266 , F_112 ( V_55 -> V_265 ) ,
V_267 ) )
goto V_71;
if ( V_55 -> V_268 &&
F_59 ( V_16 , V_269 , F_60 ( V_55 -> V_268 ) ) )
goto V_71;
if ( V_55 -> V_152 != V_246 ) {
if ( F_59 ( V_16 , V_270 , F_60 ( V_55 -> V_152 ) ) )
goto V_71;
}
if ( F_157 ( V_16 , V_271 , V_55 -> V_272 , V_55 -> V_214 ) )
goto V_71;
V_233 = F_110 ( V_16 , V_273 ) ;
if ( V_233 == NULL )
goto V_71;
if ( V_55 -> V_31 &&
F_59 ( V_16 , V_274 , F_60 ( V_55 -> V_31 ) ) )
goto V_71;
F_113 ( V_16 , V_233 ) ;
F_61 ( V_16 , V_18 ) ;
return 0 ;
V_71:
F_62 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_184 ( const struct V_13 * V_14 ,
const struct V_54 * V_55 ,
int V_68 , T_7 V_275 )
{
struct V_15 * V_16 ;
T_1 V_25 = V_14 -> V_25 ;
int V_43 ;
if ( ! V_14 -> V_26 &&
! F_64 ( V_14 -> V_1 , V_80 ) )
return 0 ;
V_43 = - V_81 ;
V_16 = F_65 ( V_82 , V_275 ) ;
if ( V_16 == NULL )
goto V_43;
V_43 = F_183 ( V_16 , V_14 , V_55 , V_68 , 0 ) ;
if ( V_43 < 0 ) {
F_66 ( V_16 ) ;
goto V_43;
}
V_43 = F_67 ( V_16 , V_14 -> V_1 , V_25 , V_80 ,
V_14 -> V_26 , V_275 ) ;
V_43:
if ( V_43 < 0 )
F_68 ( V_14 -> V_1 , V_25 , V_80 , V_43 ) ;
return V_43 ;
}
static int F_185 ( struct V_15 * V_16 , struct V_83 * V_84 )
{
const struct V_54 * V_55 ;
unsigned int V_85 , V_86 = V_84 -> args [ 0 ] ;
struct V_2 * V_3 ;
struct V_19 * V_20 , * V_276 = (struct V_19 * ) V_84 -> args [ 2 ] ;
struct V_1 * V_1 = F_70 ( V_16 -> V_87 ) ;
int V_277 = V_84 -> args [ 3 ] ;
struct V_13 * V_14 = V_84 -> V_193 , V_278 ;
if ( V_84 -> args [ 1 ] )
return V_16 -> V_92 ;
F_71 () ;
V_84 -> V_27 = V_1 -> V_7 . V_76 ;
F_72 (afi, &net->nft.af_info, list) {
if ( V_14 -> V_3 && V_14 -> V_3 != V_3 )
continue;
if ( V_277 ) {
if ( V_3 -> V_9 != V_277 )
continue;
V_277 = 0 ;
}
F_72 (table, &afi->tables, list) {
if ( V_14 -> V_20 && V_14 -> V_20 != V_20 )
continue;
if ( V_276 ) {
if ( V_276 != V_20 )
continue;
V_276 = NULL ;
}
V_85 = 0 ;
F_72 (set, &table->sets, list) {
if ( V_85 < V_86 )
goto V_89;
if ( ! F_73 ( V_1 , V_55 ) )
goto V_89;
V_278 = * V_14 ;
V_278 . V_20 = V_20 ;
V_278 . V_3 = V_3 ;
if ( F_183 ( V_16 , & V_278 , V_55 ,
V_57 ,
V_90 ) < 0 ) {
V_84 -> args [ 0 ] = V_85 ;
V_84 -> args [ 2 ] = ( unsigned long ) V_20 ;
V_84 -> args [ 3 ] = V_3 -> V_9 ;
goto V_91;
}
F_74 ( V_84 , F_75 ( V_16 ) ) ;
V_89:
V_85 ++ ;
}
if ( V_86 )
V_86 = 0 ;
}
}
V_84 -> args [ 1 ] = 1 ;
V_91:
F_76 () ;
return V_16 -> V_92 ;
}
static int F_186 ( struct V_83 * V_84 )
{
F_22 ( V_84 -> V_193 ) ;
return 0 ;
}
static int F_187 ( struct V_1 * V_1 , struct V_93 * V_94 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
T_2 V_60 = F_78 ( V_1 ) ;
const struct V_54 * V_55 ;
struct V_13 V_14 ;
struct V_15 * V_95 ;
const struct V_69 * V_70 = F_56 ( V_18 ) ;
int V_43 ;
V_43 = F_174 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_60 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_18 -> V_96 & V_97 ) {
struct V_98 V_99 = {
. V_100 = F_185 ,
. V_91 = F_186 ,
} ;
struct V_13 * V_279 ;
V_279 = F_188 ( sizeof( * V_279 ) , V_33 ) ;
if ( V_279 == NULL )
return - V_40 ;
* V_279 = V_14 ;
V_99 . V_193 = V_279 ;
return F_79 ( V_94 , V_16 , V_18 , & V_99 ) ;
}
if ( V_70 -> V_72 == V_88 )
return - V_12 ;
if ( ! V_24 [ V_248 ] )
return - V_62 ;
V_55 = F_175 ( V_14 . V_20 , V_24 [ V_257 ] , V_60 ) ;
if ( F_80 ( V_55 ) )
return F_81 ( V_55 ) ;
V_95 = F_82 ( V_82 , V_33 ) ;
if ( V_95 == NULL )
return - V_40 ;
V_43 = F_183 ( V_95 , & V_14 , V_55 , V_57 , 0 ) ;
if ( V_43 < 0 )
goto V_43;
return F_83 ( V_94 , V_95 , F_16 ( V_16 ) . V_25 ) ;
V_43:
F_66 ( V_95 ) ;
return V_43 ;
}
static int F_189 ( const struct V_13 * V_14 ,
struct V_232 * V_233 ,
const struct V_23 * V_24 )
{
struct V_23 * V_280 [ V_281 + 1 ] ;
int V_43 ;
V_43 = F_119 ( V_280 , V_281 , V_24 , V_282 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_280 [ V_274 ] != NULL )
V_233 -> V_31 = F_42 ( F_43 ( V_280 [ V_274 ] ) ) ;
return 0 ;
}
static int F_190 ( struct V_1 * V_1 , struct V_93 * V_94 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_69 * V_70 = F_56 ( V_18 ) ;
T_2 V_60 = F_90 ( V_1 ) ;
const struct V_230 * V_38 ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_54 * V_55 ;
struct V_13 V_14 ;
char V_61 [ V_253 ] ;
unsigned int V_31 ;
bool V_167 ;
T_3 V_265 ;
T_1 V_259 , V_263 , V_35 , V_152 , V_268 ;
struct V_232 V_233 ;
unsigned char * V_214 ;
T_6 V_272 ;
int V_43 ;
if ( V_24 [ V_248 ] == NULL ||
V_24 [ V_257 ] == NULL ||
V_24 [ V_260 ] == NULL ||
V_24 [ V_58 ] == NULL )
return - V_62 ;
memset ( & V_233 , 0 , sizeof( V_233 ) ) ;
V_259 = V_283 ;
if ( V_24 [ V_258 ] != NULL ) {
V_259 = F_42 ( F_43 ( V_24 [ V_258 ] ) ) ;
if ( ( V_259 & V_284 ) == V_284 )
return - V_62 ;
}
V_233 . V_261 = F_42 ( F_43 ( V_24 [ V_260 ] ) ) ;
if ( V_233 . V_261 == 0 || V_233 . V_261 > V_285 )
return - V_62 ;
V_35 = 0 ;
if ( V_24 [ V_240 ] != NULL ) {
V_35 = F_42 ( F_43 ( V_24 [ V_240 ] ) ) ;
if ( V_35 & ~ ( V_117 | V_286 |
V_241 | V_243 |
V_242 | V_287 ) )
return - V_62 ;
if ( ( V_35 & ( V_242 | V_287 ) ) ==
( V_242 | V_287 ) )
return - V_106 ;
}
V_263 = 0 ;
if ( V_24 [ V_262 ] != NULL ) {
if ( ! ( V_35 & V_242 ) )
return - V_62 ;
V_263 = F_42 ( F_43 ( V_24 [ V_262 ] ) ) ;
if ( ( V_263 & V_284 ) == V_284 &&
V_263 != V_288 )
return - V_62 ;
if ( V_263 != V_288 ) {
if ( V_24 [ V_264 ] == NULL )
return - V_62 ;
V_233 . V_229 = F_42 ( F_43 ( V_24 [ V_264 ] ) ) ;
if ( V_233 . V_229 == 0 || V_233 . V_229 > V_285 )
return - V_62 ;
} else
V_233 . V_229 = sizeof( struct V_289 ) ;
} else if ( V_35 & V_242 )
return - V_62 ;
V_265 = 0 ;
if ( V_24 [ V_266 ] != NULL ) {
if ( ! ( V_35 & V_243 ) )
return - V_62 ;
V_265 = F_123 ( F_124 ( V_24 [ V_266 ] ) ) ;
}
V_268 = 0 ;
if ( V_24 [ V_269 ] != NULL ) {
if ( ! ( V_35 & V_243 ) )
return - V_62 ;
V_268 = F_42 ( F_43 ( V_24 [ V_269 ] ) ) ;
}
V_152 = V_246 ;
if ( V_24 [ V_270 ] != NULL )
V_152 = F_42 ( F_43 ( V_24 [ V_270 ] ) ) ;
if ( V_24 [ V_273 ] != NULL ) {
V_43 = F_189 ( & V_14 , & V_233 , V_24 [ V_273 ] ) ;
if ( V_43 < 0 )
return V_43 ;
}
V_167 = V_18 -> V_96 & V_168 ? true : false ;
V_3 = F_11 ( V_1 , V_70 -> V_72 , V_167 ) ;
if ( F_80 ( V_3 ) )
return F_81 ( V_3 ) ;
V_20 = F_48 ( V_3 , V_24 [ V_248 ] , V_60 ) ;
if ( F_80 ( V_20 ) )
return F_81 ( V_20 ) ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
V_55 = F_175 ( V_20 , V_24 [ V_257 ] , V_60 ) ;
if ( F_80 ( V_55 ) ) {
if ( F_81 ( V_55 ) != - V_51 )
return F_81 ( V_55 ) ;
V_55 = NULL ;
}
if ( V_55 != NULL ) {
if ( V_18 -> V_96 & V_103 )
return - V_104 ;
if ( V_18 -> V_96 & V_105 )
return - V_106 ;
return 0 ;
}
if ( ! ( V_18 -> V_96 & V_168 ) )
return - V_51 ;
V_38 = F_173 ( V_24 , & V_233 , V_152 ) ;
if ( F_80 ( V_38 ) )
return F_81 ( V_38 ) ;
V_272 = 0 ;
if ( V_24 [ V_271 ] )
V_272 = F_52 ( V_24 [ V_271 ] ) ;
V_31 = 0 ;
if ( V_38 -> V_290 != NULL )
V_31 = V_38 -> V_290 ( V_24 ) ;
V_43 = - V_40 ;
V_55 = F_19 ( sizeof( * V_55 ) + V_31 + V_272 , V_33 ) ;
if ( V_55 == NULL )
goto V_108;
F_92 ( V_61 , V_24 [ V_257 ] , sizeof( V_55 -> V_61 ) ) ;
V_43 = F_177 ( & V_14 , V_55 , V_61 ) ;
if ( V_43 < 0 )
goto V_109;
V_214 = NULL ;
if ( V_272 ) {
V_214 = V_55 -> V_193 + V_31 ;
F_169 ( V_214 , V_24 [ V_271 ] , V_272 ) ;
}
F_2 ( & V_55 -> V_118 ) ;
V_55 -> V_38 = V_38 ;
V_55 -> V_259 = V_259 ;
V_55 -> V_261 = V_233 . V_261 ;
V_55 -> V_263 = V_263 ;
V_55 -> V_229 = V_233 . V_229 ;
V_55 -> V_35 = V_35 ;
V_55 -> V_31 = V_233 . V_31 ;
V_55 -> V_152 = V_152 ;
V_55 -> V_272 = V_272 ;
V_55 -> V_214 = V_214 ;
V_55 -> V_265 = V_265 ;
V_55 -> V_268 = V_268 ;
V_43 = V_38 -> V_202 ( V_55 , & V_233 , V_24 ) ;
if ( V_43 < 0 )
goto V_109;
V_43 = F_40 ( & V_14 , V_57 , V_55 ) ;
if ( V_43 < 0 )
goto V_109;
F_4 ( & V_55 -> V_6 , & V_20 -> V_112 ) ;
V_20 -> V_48 ++ ;
return 0 ;
V_109:
F_22 ( V_55 ) ;
V_108:
F_93 ( V_38 -> V_107 ) ;
return V_43 ;
}
static void F_191 ( struct V_54 * V_55 )
{
V_55 -> V_38 -> V_203 ( V_55 ) ;
F_93 ( V_55 -> V_38 -> V_107 ) ;
F_22 ( V_55 ) ;
}
static void F_192 ( const struct V_13 * V_14 , struct V_54 * V_55 )
{
F_8 ( & V_55 -> V_6 ) ;
F_184 ( V_14 , V_55 , V_59 , V_291 ) ;
F_191 ( V_55 ) ;
}
static int F_193 ( struct V_1 * V_1 , struct V_93 * V_94 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_69 * V_70 = F_56 ( V_18 ) ;
T_2 V_60 = F_90 ( V_1 ) ;
struct V_54 * V_55 ;
struct V_13 V_14 ;
int V_43 ;
if ( V_70 -> V_72 == V_88 )
return - V_12 ;
if ( V_24 [ V_248 ] == NULL )
return - V_62 ;
V_43 = F_174 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_60 ) ;
if ( V_43 < 0 )
return V_43 ;
V_55 = F_175 ( V_14 . V_20 , V_24 [ V_257 ] , V_60 ) ;
if ( F_80 ( V_55 ) )
return F_81 ( V_55 ) ;
if ( ! F_96 ( & V_55 -> V_118 ) )
return - V_122 ;
return F_44 ( & V_14 , V_55 ) ;
}
static int F_194 ( const struct V_13 * V_14 ,
const struct V_54 * V_55 ,
const struct V_292 * V_293 ,
const struct V_294 * V_295 )
{
const struct V_296 * V_297 = F_195 ( V_55 , V_295 -> V_184 ) ;
enum V_298 V_299 ;
V_299 = F_196 ( V_55 -> V_263 ) ;
return F_197 ( V_14 , V_299 , F_198 ( V_297 ) ,
V_55 -> V_263 == V_288 ?
V_288 : V_283 ,
V_55 -> V_229 ) ;
}
int F_199 ( const struct V_13 * V_14 , struct V_54 * V_55 ,
struct V_300 * V_301 )
{
struct V_300 * V_65 ;
struct V_292 V_293 ;
if ( ! F_96 ( & V_55 -> V_118 ) && V_55 -> V_35 & V_117 )
return - V_122 ;
if ( V_301 -> V_35 & V_242 ) {
F_10 (i, &set->bindings, list) {
if ( V_65 -> V_35 & V_242 &&
V_65 -> V_22 == V_301 -> V_22 )
goto V_302;
}
V_293 . V_60 = F_90 ( V_14 -> V_1 ) ;
V_293 . V_303 = 0 ;
V_293 . V_304 = 0 ;
V_293 . V_43 = 0 ;
V_293 . V_305 = F_194 ;
V_55 -> V_38 -> V_306 ( V_14 , V_55 , & V_293 ) ;
if ( V_293 . V_43 < 0 )
return V_293 . V_43 ;
}
V_302:
V_301 -> V_22 = V_14 -> V_22 ;
F_4 ( & V_301 -> V_6 , & V_55 -> V_118 ) ;
return 0 ;
}
void F_200 ( const struct V_13 * V_14 , struct V_54 * V_55 ,
struct V_300 * V_301 )
{
F_8 ( & V_301 -> V_6 ) ;
if ( F_96 ( & V_55 -> V_118 ) && V_55 -> V_35 & V_117 &&
F_73 ( V_14 -> V_1 , V_55 ) )
F_192 ( V_14 , V_55 ) ;
}
static int F_201 ( struct V_13 * V_14 , struct V_1 * V_1 ,
const struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
T_2 V_60 )
{
const struct V_69 * V_70 = F_56 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
V_3 = F_11 ( V_1 , V_70 -> V_72 , false ) ;
if ( F_80 ( V_3 ) )
return F_81 ( V_3 ) ;
V_20 = F_48 ( V_3 , V_24 [ V_307 ] ,
V_60 ) ;
if ( F_80 ( V_20 ) )
return F_81 ( V_20 ) ;
F_15 ( V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return 0 ;
}
static int F_202 ( struct V_15 * V_16 ,
const struct V_54 * V_55 ,
const struct V_294 * V_295 )
{
const struct V_296 * V_297 = F_195 ( V_55 , V_295 -> V_184 ) ;
unsigned char * V_308 = F_203 ( V_16 ) ;
struct V_23 * V_128 ;
V_128 = F_110 ( V_16 , V_213 ) ;
if ( V_128 == NULL )
goto V_71;
if ( F_204 ( V_16 , V_309 , F_205 ( V_297 ) ,
V_283 , V_55 -> V_261 ) < 0 )
goto V_71;
if ( F_206 ( V_297 , V_310 ) &&
F_204 ( V_16 , V_311 , F_198 ( V_297 ) ,
V_55 -> V_263 == V_288 ? V_288 : V_283 ,
V_55 -> V_229 ) < 0 )
goto V_71;
if ( F_206 ( V_297 , V_312 ) &&
F_146 ( V_16 , V_313 , F_207 ( V_297 ) ) < 0 )
goto V_71;
if ( F_206 ( V_297 , V_314 ) &&
F_59 ( V_16 , V_315 ,
F_60 ( * F_208 ( V_297 ) ) ) )
goto V_71;
if ( F_206 ( V_297 , V_316 ) &&
F_111 ( V_16 , V_317 ,
F_112 ( * F_209 ( V_297 ) ) ,
V_318 ) )
goto V_71;
if ( F_206 ( V_297 , V_319 ) ) {
unsigned long V_320 , V_321 = V_322 ;
V_320 = * F_210 ( V_297 ) ;
if ( F_211 ( V_321 , V_320 ) )
V_320 -= V_321 ;
else
V_320 = 0 ;
if ( F_111 ( V_16 , V_323 ,
F_112 ( F_212 ( V_320 ) ) ,
V_318 ) )
goto V_71;
}
if ( F_206 ( V_297 , V_324 ) ) {
struct V_215 * V_214 ;
V_214 = F_213 ( V_297 ) ;
if ( F_157 ( V_16 , V_325 ,
V_214 -> V_92 + 1 , V_214 -> V_193 ) )
goto V_71;
}
F_113 ( V_16 , V_128 ) ;
return 0 ;
V_71:
F_62 ( V_16 , V_308 ) ;
return - V_326 ;
}
static int F_214 ( const struct V_13 * V_14 ,
const struct V_54 * V_55 ,
const struct V_292 * V_293 ,
const struct V_294 * V_295 )
{
struct V_327 * args ;
args = F_215 ( V_293 , struct V_327 , V_293 ) ;
return F_202 ( args -> V_16 , V_55 , V_295 ) ;
}
static int F_216 ( struct V_15 * V_16 , struct V_83 * V_84 )
{
struct V_1 * V_1 = F_70 ( V_16 -> V_87 ) ;
T_2 V_60 = F_78 ( V_1 ) ;
const struct V_54 * V_55 ;
struct V_327 args ;
struct V_13 V_14 ;
struct V_23 * V_24 [ V_328 + 1 ] ;
struct V_69 * V_70 ;
struct V_17 * V_18 ;
struct V_23 * V_128 ;
T_1 V_25 , V_27 ;
int V_68 , V_43 ;
V_43 = F_217 ( V_84 -> V_18 , sizeof( struct V_69 ) , V_24 ,
V_328 , V_329 ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 = F_201 ( & V_14 , V_1 , V_84 -> V_16 , V_84 -> V_18 ,
( void * ) V_24 , V_60 ) ;
if ( V_43 < 0 )
return V_43 ;
V_55 = F_175 ( V_14 . V_20 , V_24 [ V_330 ] ,
V_60 ) ;
if ( F_80 ( V_55 ) )
return F_81 ( V_55 ) ;
V_68 = V_331 ;
V_68 |= V_5 << 8 ;
V_25 = F_16 ( V_84 -> V_16 ) . V_25 ;
V_27 = V_84 -> V_18 -> V_28 ;
V_18 = F_55 ( V_16 , V_25 , V_27 , V_68 , sizeof( struct V_69 ) ,
V_90 ) ;
if ( V_18 == NULL )
goto V_71;
V_70 = F_56 ( V_18 ) ;
V_70 -> V_72 = V_14 . V_3 -> V_9 ;
V_70 -> V_73 = V_74 ;
V_70 -> V_75 = F_57 ( V_14 . V_1 -> V_7 . V_76 & 0xffff ) ;
if ( F_58 ( V_16 , V_307 , V_14 . V_20 -> V_61 ) )
goto V_71;
if ( F_58 ( V_16 , V_330 , V_55 -> V_61 ) )
goto V_71;
V_128 = F_110 ( V_16 , V_332 ) ;
if ( V_128 == NULL )
goto V_71;
args . V_84 = V_84 ;
args . V_16 = V_16 ;
args . V_293 . V_60 = F_78 ( V_14 . V_1 ) ;
args . V_293 . V_303 = V_84 -> args [ 0 ] ;
args . V_293 . V_304 = 0 ;
args . V_293 . V_43 = 0 ;
args . V_293 . V_305 = F_214 ;
V_55 -> V_38 -> V_306 ( & V_14 , V_55 , & args . V_293 ) ;
F_113 ( V_16 , V_128 ) ;
F_61 ( V_16 , V_18 ) ;
if ( args . V_293 . V_43 && args . V_293 . V_43 != - V_326 )
return args . V_293 . V_43 ;
if ( args . V_293 . V_304 == V_84 -> args [ 0 ] )
return 0 ;
V_84 -> args [ 0 ] = args . V_293 . V_304 ;
return V_16 -> V_92 ;
V_71:
return - V_137 ;
}
static int F_218 ( struct V_1 * V_1 , struct V_93 * V_94 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
T_2 V_60 = F_78 ( V_1 ) ;
const struct V_54 * V_55 ;
struct V_13 V_14 ;
int V_43 ;
V_43 = F_201 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_60 ) ;
if ( V_43 < 0 )
return V_43 ;
V_55 = F_175 ( V_14 . V_20 , V_24 [ V_330 ] ,
V_60 ) ;
if ( F_80 ( V_55 ) )
return F_81 ( V_55 ) ;
if ( V_18 -> V_96 & V_97 ) {
struct V_98 V_99 = {
. V_100 = F_216 ,
} ;
return F_79 ( V_94 , V_16 , V_18 , & V_99 ) ;
}
return - V_106 ;
}
static int F_219 ( struct V_15 * V_16 ,
const struct V_13 * V_14 , T_1 V_27 ,
T_1 V_25 , int V_68 , T_6 V_35 ,
const struct V_54 * V_55 ,
const struct V_294 * V_295 )
{
struct V_69 * V_70 ;
struct V_17 * V_18 ;
struct V_23 * V_128 ;
int V_43 ;
V_68 |= V_5 << 8 ;
V_18 = F_55 ( V_16 , V_25 , V_27 , V_68 , sizeof( struct V_69 ) ,
V_35 ) ;
if ( V_18 == NULL )
goto V_71;
V_70 = F_56 ( V_18 ) ;
V_70 -> V_72 = V_14 -> V_3 -> V_9 ;
V_70 -> V_73 = V_74 ;
V_70 -> V_75 = F_57 ( V_14 -> V_1 -> V_7 . V_76 & 0xffff ) ;
if ( F_58 ( V_16 , V_248 , V_14 -> V_20 -> V_61 ) )
goto V_71;
if ( F_58 ( V_16 , V_257 , V_55 -> V_61 ) )
goto V_71;
V_128 = F_110 ( V_16 , V_332 ) ;
if ( V_128 == NULL )
goto V_71;
V_43 = F_202 ( V_16 , V_55 , V_295 ) ;
if ( V_43 < 0 )
goto V_71;
F_113 ( V_16 , V_128 ) ;
F_61 ( V_16 , V_18 ) ;
return 0 ;
V_71:
F_62 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_220 ( const struct V_13 * V_14 ,
const struct V_54 * V_55 ,
const struct V_294 * V_295 ,
int V_68 , T_6 V_35 )
{
struct V_1 * V_1 = V_14 -> V_1 ;
T_1 V_25 = V_14 -> V_25 ;
struct V_15 * V_16 ;
int V_43 ;
if ( ! V_14 -> V_26 && ! F_64 ( V_1 , V_80 ) )
return 0 ;
V_43 = - V_81 ;
V_16 = F_65 ( V_82 , V_33 ) ;
if ( V_16 == NULL )
goto V_43;
V_43 = F_219 ( V_16 , V_14 , 0 , V_25 , V_68 , V_35 ,
V_55 , V_295 ) ;
if ( V_43 < 0 ) {
F_66 ( V_16 ) ;
goto V_43;
}
V_43 = F_67 ( V_16 , V_1 , V_25 , V_80 , V_14 -> V_26 ,
V_33 ) ;
V_43:
if ( V_43 < 0 )
F_68 ( V_1 , V_25 , V_80 , V_43 ) ;
return V_43 ;
}
static struct V_29 * F_221 ( struct V_13 * V_14 ,
int V_30 ,
struct V_54 * V_55 )
{
struct V_29 * V_32 ;
V_32 = F_18 ( V_14 , V_30 , sizeof( struct V_333 ) ) ;
if ( V_32 == NULL )
return NULL ;
F_222 ( V_32 ) = V_55 ;
return V_32 ;
}
void * F_223 ( const struct V_54 * V_55 ,
const struct V_334 * V_335 ,
const T_1 * V_336 , const T_1 * V_193 ,
T_3 V_265 , T_7 V_337 )
{
struct V_296 * V_297 ;
void * V_295 ;
V_295 = F_19 ( V_55 -> V_38 -> V_338 + V_335 -> V_92 , V_337 ) ;
if ( V_295 == NULL )
return NULL ;
V_297 = F_195 ( V_55 , V_295 ) ;
F_224 ( V_297 , V_335 ) ;
memcpy ( F_205 ( V_297 ) , V_336 , V_55 -> V_261 ) ;
if ( F_206 ( V_297 , V_310 ) )
memcpy ( F_198 ( V_297 ) , V_193 , V_55 -> V_229 ) ;
if ( F_206 ( V_297 , V_319 ) )
* F_210 ( V_297 ) =
V_322 + F_225 ( V_265 ) ;
if ( F_206 ( V_297 , V_316 ) )
* F_209 ( V_297 ) = V_265 ;
return V_295 ;
}
void F_226 ( const struct V_54 * V_55 , void * V_295 )
{
struct V_296 * V_297 = F_195 ( V_55 , V_295 ) ;
F_227 ( F_205 ( V_297 ) , V_283 ) ;
if ( F_206 ( V_297 , V_310 ) )
F_227 ( F_198 ( V_297 ) , V_55 -> V_263 ) ;
if ( F_206 ( V_297 , V_312 ) )
F_149 ( NULL , F_207 ( V_297 ) ) ;
F_22 ( V_295 ) ;
}
static int F_228 ( const struct V_54 * V_55 ,
const struct V_23 * V_155 , T_1 * V_35 )
{
if ( V_155 == NULL )
return 0 ;
* V_35 = F_42 ( F_43 ( V_155 ) ) ;
if ( * V_35 & ~ V_339 )
return - V_62 ;
if ( ! ( V_55 -> V_35 & V_241 ) &&
* V_35 & V_339 )
return - V_62 ;
return 0 ;
}
static int F_229 ( struct V_13 * V_14 , struct V_54 * V_55 ,
const struct V_23 * V_155 )
{
struct V_23 * V_24 [ V_340 + 1 ] ;
struct V_341 V_342 , V_343 ;
struct V_334 V_335 ;
struct V_296 * V_297 ;
struct V_294 V_295 ;
struct V_300 * V_301 ;
struct V_215 * V_214 ;
struct V_344 V_193 ;
enum V_298 V_299 ;
struct V_29 * V_32 ;
T_1 V_35 = 0 ;
T_3 V_265 ;
T_2 V_223 ;
int V_43 ;
V_43 = F_119 ( V_24 , V_340 , V_155 ,
V_345 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_24 [ V_309 ] == NULL )
return - V_62 ;
F_230 ( & V_335 ) ;
V_43 = F_228 ( V_55 , V_24 [ V_315 ] , & V_35 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_35 != 0 )
F_231 ( & V_335 , V_314 ) ;
if ( V_55 -> V_35 & V_242 ) {
if ( V_24 [ V_311 ] == NULL &&
! ( V_35 & V_339 ) )
return - V_62 ;
if ( V_24 [ V_311 ] != NULL &&
V_35 & V_339 )
return - V_62 ;
} else {
if ( V_24 [ V_311 ] != NULL )
return - V_62 ;
}
V_265 = 0 ;
if ( V_24 [ V_317 ] != NULL ) {
if ( ! ( V_55 -> V_35 & V_243 ) )
return - V_62 ;
V_265 = F_123 ( F_124 ( V_24 [ V_317 ] ) ) ;
} else if ( V_55 -> V_35 & V_243 ) {
V_265 = V_55 -> V_265 ;
}
V_43 = F_232 ( V_14 , & V_295 . V_336 . V_346 , sizeof( V_295 . V_336 ) , & V_342 ,
V_24 [ V_309 ] ) ;
if ( V_43 < 0 )
goto V_108;
V_43 = - V_62 ;
if ( V_342 . type != V_283 || V_342 . V_92 != V_55 -> V_261 )
goto V_109;
F_233 ( & V_335 , V_347 , V_342 . V_92 ) ;
if ( V_265 > 0 ) {
F_231 ( & V_335 , V_319 ) ;
if ( V_265 != V_55 -> V_265 )
F_231 ( & V_335 , V_316 ) ;
}
if ( V_24 [ V_311 ] != NULL ) {
V_43 = F_232 ( V_14 , & V_193 , sizeof( V_193 ) , & V_343 ,
V_24 [ V_311 ] ) ;
if ( V_43 < 0 )
goto V_109;
V_43 = - V_62 ;
if ( V_55 -> V_263 != V_288 && V_343 . V_92 != V_55 -> V_229 )
goto V_113;
V_299 = F_196 ( V_55 -> V_263 ) ;
F_10 (binding, &set->bindings, list) {
struct V_13 V_348 = {
. V_3 = V_14 -> V_3 ,
. V_20 = V_14 -> V_20 ,
. V_22 = (struct V_21 * ) V_301 -> V_22 ,
} ;
if ( ! ( V_301 -> V_35 & V_242 ) )
continue;
V_43 = F_197 ( & V_348 , V_299 ,
& V_193 ,
V_343 . type , V_343 . V_92 ) ;
if ( V_43 < 0 )
goto V_113;
}
F_233 ( & V_335 , V_310 , V_343 . V_92 ) ;
}
V_223 = 0 ;
if ( V_24 [ V_325 ] != NULL ) {
V_223 = F_52 ( V_24 [ V_325 ] ) ;
if ( V_223 > 0 )
F_233 ( & V_335 , V_324 ,
V_223 ) ;
}
V_43 = - V_40 ;
V_295 . V_184 = F_223 ( V_55 , & V_335 , V_295 . V_336 . V_346 . V_193 , V_193 . V_193 ,
V_265 , V_33 ) ;
if ( V_295 . V_184 == NULL )
goto V_113;
V_297 = F_195 ( V_55 , V_295 . V_184 ) ;
if ( V_35 )
* F_208 ( V_297 ) = V_35 ;
if ( V_223 > 0 ) {
V_214 = F_213 ( V_297 ) ;
V_214 -> V_92 = V_223 - 1 ;
F_169 ( & V_214 -> V_193 , V_24 [ V_325 ] , V_223 ) ;
}
V_32 = F_221 ( V_14 , V_331 , V_55 ) ;
if ( V_32 == NULL )
goto V_349;
V_297 -> V_60 = F_78 ( V_14 -> V_1 ) | V_350 ;
V_43 = V_55 -> V_38 -> V_351 ( V_14 -> V_1 , V_55 , & V_295 ) ;
if ( V_43 < 0 )
goto V_352;
V_333 ( V_32 ) = V_295 ;
F_30 ( & V_32 -> V_6 , & V_14 -> V_1 -> V_7 . V_42 ) ;
return 0 ;
V_352:
F_22 ( V_32 ) ;
V_349:
F_22 ( V_295 . V_184 ) ;
V_113:
if ( V_24 [ V_311 ] != NULL )
F_227 ( & V_193 , V_343 . type ) ;
V_109:
F_227 ( & V_295 . V_336 . V_346 , V_342 . type ) ;
V_108:
return V_43 ;
}
static int F_234 ( struct V_1 * V_1 , struct V_93 * V_94 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
T_2 V_60 = F_90 ( V_1 ) ;
const struct V_23 * V_155 ;
struct V_54 * V_55 ;
struct V_13 V_14 ;
int V_225 , V_43 = 0 ;
if ( V_24 [ V_332 ] == NULL )
return - V_62 ;
V_43 = F_201 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_60 ) ;
if ( V_43 < 0 )
return V_43 ;
V_55 = F_175 ( V_14 . V_20 , V_24 [ V_330 ] ,
V_60 ) ;
if ( F_80 ( V_55 ) ) {
if ( V_24 [ V_353 ] ) {
V_55 = F_176 ( V_1 ,
V_24 [ V_353 ] ,
V_60 ) ;
}
if ( F_80 ( V_55 ) )
return F_81 ( V_55 ) ;
}
if ( ! F_96 ( & V_55 -> V_118 ) && V_55 -> V_35 & V_286 )
return - V_122 ;
F_167 (attr, nla[NFTA_SET_ELEM_LIST_ELEMENTS], rem) {
if ( V_55 -> V_31 &&
! F_235 ( & V_55 -> V_354 , 1 , V_55 -> V_31 + V_55 -> V_355 ) )
return - V_256 ;
V_43 = F_229 ( & V_14 , V_55 , V_155 ) ;
if ( V_43 < 0 ) {
F_236 ( & V_55 -> V_354 ) ;
break;
}
}
return V_43 ;
}
static int F_237 ( struct V_13 * V_14 , struct V_54 * V_55 ,
const struct V_23 * V_155 )
{
struct V_23 * V_24 [ V_340 + 1 ] ;
struct V_334 V_335 ;
struct V_341 V_233 ;
struct V_294 V_295 ;
struct V_296 * V_297 ;
struct V_29 * V_32 ;
T_1 V_35 = 0 ;
void * V_184 ;
int V_43 ;
V_43 = F_119 ( V_24 , V_340 , V_155 ,
V_345 ) ;
if ( V_43 < 0 )
goto V_108;
V_43 = - V_62 ;
if ( V_24 [ V_309 ] == NULL )
goto V_108;
F_230 ( & V_335 ) ;
V_43 = F_228 ( V_55 , V_24 [ V_315 ] , & V_35 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_35 != 0 )
F_231 ( & V_335 , V_314 ) ;
V_43 = F_232 ( V_14 , & V_295 . V_336 . V_346 , sizeof( V_295 . V_336 ) , & V_233 ,
V_24 [ V_309 ] ) ;
if ( V_43 < 0 )
goto V_108;
V_43 = - V_62 ;
if ( V_233 . type != V_283 || V_233 . V_92 != V_55 -> V_261 )
goto V_109;
F_233 ( & V_335 , V_347 , V_233 . V_92 ) ;
V_43 = - V_40 ;
V_295 . V_184 = F_223 ( V_55 , & V_335 , V_295 . V_336 . V_346 . V_193 , NULL , 0 ,
V_33 ) ;
if ( V_295 . V_184 == NULL )
goto V_109;
V_297 = F_195 ( V_55 , V_295 . V_184 ) ;
if ( V_35 )
* F_208 ( V_297 ) = V_35 ;
V_32 = F_221 ( V_14 , V_356 , V_55 ) ;
if ( V_32 == NULL ) {
V_43 = - V_40 ;
goto V_113;
}
V_184 = V_55 -> V_38 -> V_357 ( V_14 -> V_1 , V_55 , & V_295 ) ;
if ( V_184 == NULL ) {
V_43 = - V_51 ;
goto V_349;
}
F_22 ( V_295 . V_184 ) ;
V_295 . V_184 = V_184 ;
V_333 ( V_32 ) = V_295 ;
F_30 ( & V_32 -> V_6 , & V_14 -> V_1 -> V_7 . V_42 ) ;
return 0 ;
V_349:
F_22 ( V_32 ) ;
V_113:
F_22 ( V_295 . V_184 ) ;
V_109:
F_227 ( & V_295 . V_336 . V_346 , V_233 . type ) ;
V_108:
return V_43 ;
}
static int F_238 ( struct V_1 * V_1 , struct V_93 * V_94 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
T_2 V_60 = F_90 ( V_1 ) ;
const struct V_23 * V_155 ;
struct V_54 * V_55 ;
struct V_13 V_14 ;
int V_225 , V_43 = 0 ;
if ( V_24 [ V_332 ] == NULL )
return - V_62 ;
V_43 = F_201 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_60 ) ;
if ( V_43 < 0 )
return V_43 ;
V_55 = F_175 ( V_14 . V_20 , V_24 [ V_330 ] ,
V_60 ) ;
if ( F_80 ( V_55 ) )
return F_81 ( V_55 ) ;
if ( ! F_96 ( & V_55 -> V_118 ) && V_55 -> V_35 & V_286 )
return - V_122 ;
F_167 (attr, nla[NFTA_SET_ELEM_LIST_ELEMENTS], rem) {
V_43 = F_237 ( & V_14 , V_55 , V_155 ) ;
if ( V_43 < 0 )
break;
V_55 -> V_355 ++ ;
}
return V_43 ;
}
void F_239 ( struct V_358 * V_359 )
{
struct V_360 * V_361 ;
unsigned int V_65 ;
V_361 = F_215 ( V_359 , struct V_360 , V_362 . V_359 ) ;
for ( V_65 = 0 ; V_65 < V_361 -> V_362 . V_363 ; V_65 ++ )
F_226 ( V_361 -> V_362 . V_55 , V_361 -> V_364 [ V_65 ] ) ;
F_22 ( V_361 ) ;
}
struct V_360 * F_240 ( const struct V_54 * V_55 ,
T_7 V_337 )
{
struct V_360 * V_361 ;
V_361 = F_19 ( sizeof( * V_361 ) , V_337 ) ;
if ( V_361 == NULL )
return V_361 ;
V_361 -> V_362 . V_55 = V_55 ;
return V_361 ;
}
static int F_241 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_25 , T_1 V_27 )
{
struct V_17 * V_18 ;
struct V_69 * V_70 ;
int V_68 = ( V_5 << 8 ) | V_365 ;
V_18 = F_55 ( V_16 , V_25 , V_27 , V_68 , sizeof( struct V_69 ) , 0 ) ;
if ( V_18 == NULL )
goto V_71;
V_70 = F_56 ( V_18 ) ;
V_70 -> V_72 = V_120 ;
V_70 -> V_73 = V_74 ;
V_70 -> V_75 = F_57 ( V_1 -> V_7 . V_76 & 0xffff ) ;
if ( F_59 ( V_16 , V_366 , F_60 ( V_1 -> V_7 . V_76 ) ) )
goto V_71;
F_61 ( V_16 , V_18 ) ;
return 0 ;
V_71:
F_62 ( V_16 , V_18 ) ;
return - V_326 ;
}
static int F_242 ( struct V_1 * V_1 , struct V_15 * V_16 , int V_68 )
{
struct V_17 * V_18 = F_75 ( V_16 ) ;
struct V_15 * V_95 ;
int V_43 ;
if ( F_17 ( V_18 ) &&
! F_64 ( V_1 , V_80 ) )
return 0 ;
V_43 = - V_81 ;
V_95 = F_65 ( V_82 , V_33 ) ;
if ( V_95 == NULL )
goto V_43;
V_43 = F_241 ( V_95 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 ) ;
if ( V_43 < 0 ) {
F_66 ( V_95 ) ;
goto V_43;
}
V_43 = F_67 ( V_95 , V_1 , F_16 ( V_16 ) . V_25 ,
V_80 , F_17 ( V_18 ) , V_33 ) ;
V_43:
if ( V_43 < 0 ) {
F_68 ( V_1 , F_16 ( V_16 ) . V_25 , V_80 ,
V_43 ) ;
}
return V_43 ;
}
static int F_243 ( struct V_1 * V_1 , struct V_93 * V_94 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
struct V_15 * V_95 ;
int V_43 ;
V_95 = F_82 ( V_82 , V_33 ) ;
if ( V_95 == NULL )
return - V_40 ;
V_43 = F_241 ( V_95 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 ) ;
if ( V_43 < 0 )
goto V_43;
return F_83 ( V_94 , V_95 , F_16 ( V_16 ) . V_25 ) ;
V_43:
F_66 ( V_95 ) ;
return V_43 ;
}
static void F_244 ( struct V_29 * V_32 )
{
struct F_25 * V_142 ;
if ( F_137 ( V_32 ) [ 0 ] )
strcpy ( V_32 -> V_14 . V_22 -> V_61 , F_137 ( V_32 ) ) ;
if ( ! ( V_32 -> V_14 . V_22 -> V_35 & V_37 ) )
return;
V_142 = F_25 ( V_32 -> V_14 . V_22 ) ;
F_126 ( V_142 , F_134 ( V_32 ) ) ;
switch ( F_136 ( V_32 ) ) {
case V_169 :
case V_166 :
V_142 -> V_152 = F_136 ( V_32 ) ;
break;
}
}
static void F_245 ( struct V_29 * V_32 )
{
switch ( V_32 -> V_30 ) {
case V_44 :
F_99 ( & V_32 -> V_14 ) ;
break;
case V_47 :
F_131 ( V_32 -> V_14 . V_22 ) ;
break;
case V_53 :
F_162 ( & V_32 -> V_14 , V_52 ( V_32 ) ) ;
break;
case V_59 :
F_191 ( V_56 ( V_32 ) ) ;
break;
case V_356 :
F_226 ( F_222 ( V_32 ) ,
V_333 ( V_32 ) . V_184 ) ;
break;
}
F_22 ( V_32 ) ;
}
static int F_246 ( struct V_1 * V_1 , struct V_15 * V_16 )
{
struct V_29 * V_32 , * V_204 ;
struct V_333 * V_367 ;
while ( ++ V_1 -> V_7 . V_76 == 0 ) ;
V_1 -> V_7 . V_368 = F_247 ( V_1 ) ;
F_129 () ;
F_95 (trans, next, &net->nft.commit_list, list) {
switch ( V_32 -> V_30 ) {
case V_41 :
if ( F_88 ( V_32 ) ) {
if ( ! F_87 ( V_32 ) ) {
F_85 ( V_1 ,
V_32 -> V_14 . V_3 ,
V_32 -> V_14 . V_20 ) ;
V_32 -> V_14 . V_20 -> V_35 |= V_36 ;
}
} else {
F_248 ( V_1 , V_32 -> V_14 . V_20 ) ;
}
F_63 ( & V_32 -> V_14 , V_41 ) ;
F_20 ( V_32 ) ;
break;
case V_44 :
F_8 ( & V_32 -> V_14 . V_20 -> V_6 ) ;
F_63 ( & V_32 -> V_14 , V_44 ) ;
break;
case V_46 :
if ( F_135 ( V_32 ) )
F_244 ( V_32 ) ;
else
F_248 ( V_1 , V_32 -> V_14 . V_22 ) ;
F_115 ( & V_32 -> V_14 , V_46 ) ;
F_20 ( V_32 ) ;
break;
case V_47 :
F_8 ( & V_32 -> V_14 . V_22 -> V_6 ) ;
F_115 ( & V_32 -> V_14 , V_47 ) ;
F_26 ( V_32 -> V_14 . V_1 ,
V_32 -> V_14 . V_20 ,
V_32 -> V_14 . V_22 ,
V_32 -> V_14 . V_3 -> V_101 ) ;
break;
case V_218 :
F_248 ( V_32 -> V_14 . V_1 , V_52 ( V_32 ) ) ;
F_158 ( & V_32 -> V_14 ,
V_52 ( V_32 ) ,
V_218 ) ;
F_20 ( V_32 ) ;
break;
case V_53 :
F_8 ( & V_52 ( V_32 ) -> V_6 ) ;
F_158 ( & V_32 -> V_14 ,
V_52 ( V_32 ) ,
V_53 ) ;
break;
case V_57 :
F_248 ( V_1 , V_56 ( V_32 ) ) ;
if ( V_56 ( V_32 ) -> V_35 & V_117 &&
! F_96 ( & V_56 ( V_32 ) -> V_118 ) )
V_32 -> V_14 . V_20 -> V_48 -- ;
F_184 ( & V_32 -> V_14 , V_56 ( V_32 ) ,
V_57 , V_33 ) ;
F_20 ( V_32 ) ;
break;
case V_59 :
F_8 ( & V_56 ( V_32 ) -> V_6 ) ;
F_184 ( & V_32 -> V_14 , V_56 ( V_32 ) ,
V_59 , V_33 ) ;
break;
case V_331 :
V_367 = (struct V_333 * ) V_32 -> V_193 ;
V_367 -> V_55 -> V_38 -> V_369 ( V_1 , V_367 -> V_55 , & V_367 -> V_295 ) ;
F_220 ( & V_32 -> V_14 , V_367 -> V_55 ,
& V_367 -> V_295 ,
V_331 , 0 ) ;
F_20 ( V_32 ) ;
break;
case V_356 :
V_367 = (struct V_333 * ) V_32 -> V_193 ;
F_220 ( & V_32 -> V_14 , V_367 -> V_55 ,
& V_367 -> V_295 ,
V_356 , 0 ) ;
V_367 -> V_55 -> V_38 -> remove ( V_367 -> V_55 , & V_367 -> V_295 ) ;
F_236 ( & V_367 -> V_55 -> V_354 ) ;
V_367 -> V_55 -> V_355 -- ;
break;
}
}
F_129 () ;
F_95 (trans, next, &net->nft.commit_list, list) {
F_21 ( & V_32 -> V_6 ) ;
F_245 ( V_32 ) ;
}
F_242 ( V_1 , V_16 , V_365 ) ;
return 0 ;
}
static void F_249 ( struct V_29 * V_32 )
{
switch ( V_32 -> V_30 ) {
case V_41 :
F_99 ( & V_32 -> V_14 ) ;
break;
case V_46 :
F_131 ( V_32 -> V_14 . V_22 ) ;
break;
case V_218 :
F_162 ( & V_32 -> V_14 , V_52 ( V_32 ) ) ;
break;
case V_57 :
F_191 ( V_56 ( V_32 ) ) ;
break;
case V_331 :
F_226 ( F_222 ( V_32 ) ,
V_333 ( V_32 ) . V_184 ) ;
break;
}
F_22 ( V_32 ) ;
}
static int F_250 ( struct V_1 * V_1 , struct V_15 * V_16 )
{
struct V_29 * V_32 , * V_204 ;
struct V_333 * V_367 ;
F_251 (trans, next, &net->nft.commit_list,
list) {
switch ( V_32 -> V_30 ) {
case V_41 :
if ( F_88 ( V_32 ) ) {
if ( F_87 ( V_32 ) ) {
F_85 ( V_1 ,
V_32 -> V_14 . V_3 ,
V_32 -> V_14 . V_20 ) ;
V_32 -> V_14 . V_20 -> V_35 |= V_36 ;
}
F_20 ( V_32 ) ;
} else {
F_8 ( & V_32 -> V_14 . V_20 -> V_6 ) ;
}
break;
case V_44 :
F_248 ( V_32 -> V_14 . V_1 , V_32 -> V_14 . V_20 ) ;
F_20 ( V_32 ) ;
break;
case V_46 :
if ( F_135 ( V_32 ) ) {
F_130 ( F_134 ( V_32 ) ) ;
F_20 ( V_32 ) ;
} else {
V_32 -> V_14 . V_20 -> V_48 -- ;
F_8 ( & V_32 -> V_14 . V_22 -> V_6 ) ;
F_26 ( V_32 -> V_14 . V_1 ,
V_32 -> V_14 . V_20 ,
V_32 -> V_14 . V_22 ,
V_32 -> V_14 . V_3 -> V_101 ) ;
}
break;
case V_47 :
V_32 -> V_14 . V_20 -> V_48 ++ ;
F_248 ( V_32 -> V_14 . V_1 , V_32 -> V_14 . V_22 ) ;
F_20 ( V_32 ) ;
break;
case V_218 :
V_32 -> V_14 . V_22 -> V_48 -- ;
F_8 ( & V_52 ( V_32 ) -> V_6 ) ;
break;
case V_53 :
V_32 -> V_14 . V_22 -> V_48 ++ ;
F_248 ( V_32 -> V_14 . V_1 , V_52 ( V_32 ) ) ;
F_20 ( V_32 ) ;
break;
case V_57 :
V_32 -> V_14 . V_20 -> V_48 -- ;
F_8 ( & V_56 ( V_32 ) -> V_6 ) ;
break;
case V_59 :
V_32 -> V_14 . V_20 -> V_48 ++ ;
F_248 ( V_32 -> V_14 . V_1 , V_56 ( V_32 ) ) ;
F_20 ( V_32 ) ;
break;
case V_331 :
V_367 = (struct V_333 * ) V_32 -> V_193 ;
V_367 -> V_55 -> V_38 -> remove ( V_367 -> V_55 , & V_367 -> V_295 ) ;
F_236 ( & V_367 -> V_55 -> V_354 ) ;
break;
case V_356 :
V_367 = (struct V_333 * ) V_32 -> V_193 ;
V_367 -> V_55 -> V_38 -> V_369 ( V_1 , V_367 -> V_55 , & V_367 -> V_295 ) ;
V_367 -> V_55 -> V_355 -- ;
F_20 ( V_32 ) ;
break;
}
}
F_129 () ;
F_251 (trans, next,
&net->nft.commit_list, list) {
F_21 ( & V_32 -> V_6 ) ;
F_249 ( V_32 ) ;
}
return 0 ;
}
int F_252 ( const struct V_21 * V_22 ,
enum V_370 type )
{
const struct F_25 * V_142 ;
if ( V_22 -> V_35 & V_37 ) {
V_142 = F_25 ( V_22 ) ;
if ( V_142 -> type -> type != type )
return - V_106 ;
}
return 0 ;
}
int F_253 ( const struct V_21 * V_22 ,
unsigned int V_371 )
{
struct F_25 * V_142 ;
if ( V_22 -> V_35 & V_37 ) {
V_142 = F_25 ( V_22 ) ;
if ( ( 1 << V_142 -> V_38 [ 0 ] . V_146 ) & V_371 )
return 0 ;
return - V_106 ;
}
return 0 ;
}
static int F_254 ( const struct V_13 * V_14 ,
const struct V_54 * V_55 ,
const struct V_292 * V_293 ,
const struct V_294 * V_295 )
{
const struct V_296 * V_297 = F_195 ( V_55 , V_295 -> V_184 ) ;
const struct V_344 * V_193 ;
if ( F_206 ( V_297 , V_314 ) &&
* F_208 ( V_297 ) & V_339 )
return 0 ;
V_193 = F_198 ( V_297 ) ;
switch ( V_193 -> V_372 . V_373 ) {
case V_374 :
case V_375 :
return F_255 ( V_14 , V_193 -> V_372 . V_22 ) ;
default:
return 0 ;
}
}
static int F_255 ( const struct V_13 * V_14 ,
const struct V_21 * V_22 )
{
const struct V_49 * V_50 ;
const struct V_190 * V_191 , * V_376 ;
const struct V_54 * V_55 ;
struct V_300 * V_301 ;
struct V_292 V_293 ;
if ( V_14 -> V_22 == V_22 )
return - V_377 ;
F_10 (rule, &chain->rules, list) {
F_156 (expr, last, rule) {
const struct V_344 * V_193 = NULL ;
int V_43 ;
if ( ! V_191 -> V_38 -> V_378 )
continue;
V_43 = V_191 -> V_38 -> V_378 ( V_14 , V_191 , & V_193 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_193 == NULL )
continue;
switch ( V_193 -> V_372 . V_373 ) {
case V_374 :
case V_375 :
V_43 = F_255 ( V_14 ,
V_193 -> V_372 . V_22 ) ;
if ( V_43 < 0 )
return V_43 ;
default:
break;
}
}
}
F_10 (set, &ctx->table->sets, list) {
if ( ! F_36 ( V_14 -> V_1 , V_55 ) )
continue;
if ( ! ( V_55 -> V_35 & V_242 ) ||
V_55 -> V_263 != V_288 )
continue;
F_10 (binding, &set->bindings, list) {
if ( ! ( V_301 -> V_35 & V_242 ) ||
V_301 -> V_22 != V_22 )
continue;
V_293 . V_60 = F_90 ( V_14 -> V_1 ) ;
V_293 . V_303 = 0 ;
V_293 . V_304 = 0 ;
V_293 . V_43 = 0 ;
V_293 . V_305 = F_254 ;
V_55 -> V_38 -> V_306 ( V_14 , V_55 , & V_293 ) ;
if ( V_293 . V_43 < 0 )
return V_293 . V_43 ;
}
}
return 0 ;
}
unsigned int F_256 ( const struct V_23 * V_155 )
{
unsigned int V_379 ;
V_379 = F_42 ( F_43 ( V_155 ) ) ;
switch ( V_379 ) {
case V_380 ... V_381 :
return V_379 * V_382 / V_383 ;
default:
return V_379 + V_382 / V_383 - V_384 ;
}
}
int F_257 ( struct V_15 * V_16 , unsigned int V_155 , unsigned int V_379 )
{
if ( V_379 % ( V_382 / V_383 ) == 0 )
V_379 = V_379 / ( V_382 / V_383 ) ;
else
V_379 = V_379 - V_382 / V_383 + V_384 ;
return F_59 ( V_16 , V_155 , F_60 ( V_379 ) ) ;
}
int F_258 ( enum V_298 V_379 , unsigned int V_92 )
{
if ( V_379 < V_385 * V_382 / V_383 )
return - V_62 ;
if ( V_92 == 0 )
return - V_62 ;
if ( V_379 * V_383 + V_92 > F_259 ( struct V_386 , V_193 ) )
return - V_387 ;
return 0 ;
}
int F_197 ( const struct V_13 * V_14 ,
enum V_298 V_379 ,
const struct V_344 * V_193 ,
enum V_388 type , unsigned int V_92 )
{
int V_43 ;
switch ( V_379 ) {
case V_380 :
if ( type != V_288 )
return - V_62 ;
if ( V_193 != NULL &&
( V_193 -> V_372 . V_373 == V_375 ||
V_193 -> V_372 . V_373 == V_374 ) ) {
V_43 = F_255 ( V_14 , V_193 -> V_372 . V_22 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_14 -> V_22 -> V_389 + 1 >
V_193 -> V_372 . V_22 -> V_389 ) {
if ( V_14 -> V_22 -> V_389 + 1 == V_390 )
return - V_391 ;
V_193 -> V_372 . V_22 -> V_389 = V_14 -> V_22 -> V_389 + 1 ;
}
}
return 0 ;
default:
if ( V_379 < V_385 * V_382 / V_383 )
return - V_62 ;
if ( V_92 == 0 )
return - V_62 ;
if ( V_379 * V_383 + V_92 >
F_259 ( struct V_386 , V_193 ) )
return - V_387 ;
if ( V_193 != NULL && type != V_283 )
return - V_62 ;
return 0 ;
}
}
static int F_260 ( const struct V_13 * V_14 , struct V_344 * V_193 ,
struct V_341 * V_233 , const struct V_23 * V_24 )
{
T_2 V_60 = F_90 ( V_14 -> V_1 ) ;
struct V_23 * V_156 [ V_392 + 1 ] ;
struct V_21 * V_22 ;
int V_43 ;
V_43 = F_119 ( V_156 , V_392 , V_24 , V_393 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( ! V_156 [ V_394 ] )
return - V_62 ;
V_193 -> V_372 . V_373 = F_42 ( F_43 ( V_156 [ V_394 ] ) ) ;
switch ( V_193 -> V_372 . V_373 ) {
default:
switch ( V_193 -> V_372 . V_373 & V_395 ) {
case V_166 :
case V_169 :
case V_396 :
break;
default:
return - V_62 ;
}
case V_397 :
case V_398 :
case V_399 :
break;
case V_374 :
case V_375 :
if ( ! V_156 [ V_400 ] )
return - V_62 ;
V_22 = F_104 ( V_14 -> V_20 ,
V_156 [ V_400 ] , V_60 ) ;
if ( F_80 ( V_22 ) )
return F_81 ( V_22 ) ;
if ( V_22 -> V_35 & V_37 )
return - V_106 ;
V_22 -> V_48 ++ ;
V_193 -> V_372 . V_22 = V_22 ;
break;
}
V_233 -> V_92 = sizeof( V_193 -> V_372 ) ;
V_233 -> type = V_288 ;
return 0 ;
}
static void F_261 ( const struct V_344 * V_193 )
{
switch ( V_193 -> V_372 . V_373 ) {
case V_374 :
case V_375 :
V_193 -> V_372 . V_22 -> V_48 -- ;
break;
}
}
int F_262 ( struct V_15 * V_16 , int type , const struct V_289 * V_401 )
{
struct V_23 * V_128 ;
V_128 = F_110 ( V_16 , type ) ;
if ( ! V_128 )
goto V_71;
if ( F_59 ( V_16 , V_394 , F_60 ( V_401 -> V_373 ) ) )
goto V_71;
switch ( V_401 -> V_373 ) {
case V_374 :
case V_375 :
if ( F_58 ( V_16 , V_400 ,
V_401 -> V_22 -> V_61 ) )
goto V_71;
}
F_113 ( V_16 , V_128 ) ;
return 0 ;
V_71:
return - 1 ;
}
static int F_263 ( const struct V_13 * V_14 ,
struct V_344 * V_193 , unsigned int V_31 ,
struct V_341 * V_233 , const struct V_23 * V_24 )
{
unsigned int V_92 ;
V_92 = F_52 ( V_24 ) ;
if ( V_92 == 0 )
return - V_62 ;
if ( V_92 > V_31 )
return - V_173 ;
F_169 ( V_193 -> V_193 , V_24 , V_92 ) ;
V_233 -> type = V_283 ;
V_233 -> V_92 = V_92 ;
return 0 ;
}
static int F_264 ( struct V_15 * V_16 , const struct V_344 * V_193 ,
unsigned int V_92 )
{
return F_157 ( V_16 , V_402 , V_92 , V_193 -> V_193 ) ;
}
int F_232 ( const struct V_13 * V_14 ,
struct V_344 * V_193 , unsigned int V_31 ,
struct V_341 * V_233 , const struct V_23 * V_24 )
{
struct V_23 * V_156 [ V_403 + 1 ] ;
int V_43 ;
V_43 = F_119 ( V_156 , V_403 , V_24 , V_404 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_156 [ V_402 ] )
return F_263 ( V_14 , V_193 , V_31 , V_233 ,
V_156 [ V_402 ] ) ;
if ( V_156 [ V_405 ] && V_14 != NULL )
return F_260 ( V_14 , V_193 , V_233 , V_156 [ V_405 ] ) ;
return - V_62 ;
}
void F_227 ( const struct V_344 * V_193 , enum V_388 type )
{
if ( type < V_288 )
return;
switch ( type ) {
case V_288 :
return F_261 ( V_193 ) ;
default:
F_265 ( 1 ) ;
}
}
int F_204 ( struct V_15 * V_16 , int V_155 , const struct V_344 * V_193 ,
enum V_388 type , unsigned int V_92 )
{
struct V_23 * V_128 ;
int V_43 ;
V_128 = F_110 ( V_16 , V_155 ) ;
if ( V_128 == NULL )
return - 1 ;
switch ( type ) {
case V_283 :
V_43 = F_264 ( V_16 , V_193 , V_92 ) ;
break;
case V_288 :
V_43 = F_262 ( V_16 , V_405 , & V_193 -> V_372 ) ;
break;
default:
V_43 = - V_62 ;
F_265 ( 1 ) ;
}
F_113 ( V_16 , V_128 ) ;
return V_43 ;
}
static int T_8 F_266 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_7 . V_8 ) ;
F_2 ( & V_1 -> V_7 . V_42 ) ;
V_1 -> V_7 . V_76 = 1 ;
return 0 ;
}
int F_267 ( struct V_13 * V_14 )
{
struct V_49 * V_50 , * V_406 ;
F_100 ( ! ( V_14 -> V_22 -> V_35 & V_37 ) ) ;
F_26 ( V_14 -> V_1 , V_14 -> V_22 -> V_20 , V_14 -> V_22 ,
V_14 -> V_3 -> V_101 ) ;
F_95 (rule, nr, &ctx->chain->rules, list) {
F_21 ( & V_50 -> V_6 ) ;
V_14 -> V_22 -> V_48 -- ;
F_162 ( V_14 , V_50 ) ;
}
F_21 ( & V_14 -> V_22 -> V_6 ) ;
V_14 -> V_20 -> V_48 -- ;
F_131 ( V_14 -> V_22 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_19 * V_20 , * V_119 ;
struct V_21 * V_22 , * V_114 ;
struct V_49 * V_50 , * V_406 ;
struct V_54 * V_55 , * V_115 ;
struct V_13 V_14 = {
. V_1 = V_1 ,
. V_3 = V_3 ,
} ;
F_95 (table, nt, &afi->tables, list) {
F_10 (chain, &table->chains, list)
F_26 ( V_1 , V_20 , V_22 ,
V_3 -> V_101 ) ;
V_14 . V_20 = V_20 ;
F_10 (chain, &table->chains, list) {
V_14 . V_22 = V_22 ;
F_95 (rule, nr, &chain->rules, list) {
F_21 ( & V_50 -> V_6 ) ;
V_22 -> V_48 -- ;
F_162 ( & V_14 , V_50 ) ;
}
}
F_95 (set, ns, &table->sets, list) {
F_21 ( & V_55 -> V_6 ) ;
V_20 -> V_48 -- ;
F_191 ( V_55 ) ;
}
F_95 (chain, nc, &table->chains, list) {
F_21 ( & V_22 -> V_6 ) ;
V_20 -> V_48 -- ;
F_131 ( V_22 ) ;
}
F_21 ( & V_20 -> V_6 ) ;
F_99 ( & V_14 ) ;
}
}
static int T_9 F_268 ( void )
{
int V_43 ;
V_196 = F_188 ( sizeof( struct V_195 ) * V_227 ,
V_33 ) ;
if ( V_196 == NULL ) {
V_43 = - V_40 ;
goto V_108;
}
V_43 = F_269 () ;
if ( V_43 < 0 )
goto V_109;
V_43 = F_270 ( & V_407 ) ;
if ( V_43 < 0 )
goto V_113;
F_271 ( L_6 ) ;
return F_272 ( & V_408 ) ;
V_113:
F_273 () ;
V_109:
F_22 ( V_196 ) ;
V_108:
return V_43 ;
}
static void T_10 F_274 ( void )
{
F_275 ( & V_408 ) ;
F_276 ( & V_407 ) ;
F_277 () ;
F_273 () ;
F_22 ( V_196 ) ;
}
