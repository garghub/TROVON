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
static int F_133 ( struct V_1 * V_1 ,
const struct V_23 * const V_24 [] ,
struct V_2 * V_3 ,
struct V_162 * V_163 , bool V_164 )
{
struct V_23 * V_165 [ V_166 + 1 ] ;
const struct V_64 * type ;
struct V_167 * V_161 ;
int V_43 ;
V_43 = F_119 ( V_165 , V_166 , V_24 [ V_144 ] ,
V_168 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_165 [ V_145 ] == NULL ||
V_165 [ V_147 ] == NULL )
return - V_62 ;
V_163 -> V_169 = F_42 ( F_43 ( V_165 [ V_145 ] ) ) ;
if ( V_163 -> V_169 >= V_3 -> V_170 )
return - V_62 ;
V_163 -> V_148 = F_42 ( F_43 ( V_165 [ V_147 ] ) ) ;
type = V_67 [ V_3 -> V_9 ] [ V_171 ] ;
if ( V_24 [ V_153 ] ) {
type = F_51 ( V_3 , V_24 [ V_153 ] ,
V_164 ) ;
if ( F_80 ( type ) )
return F_81 ( type ) ;
}
if ( ! ( type -> V_172 & ( 1 << V_163 -> V_169 ) ) )
return - V_106 ;
if ( ! F_91 ( type -> V_107 ) )
return - V_51 ;
V_163 -> type = type ;
V_163 -> V_161 = NULL ;
if ( V_3 -> V_35 & V_173 ) {
char V_174 [ V_175 ] ;
if ( ! V_165 [ V_150 ] ) {
F_93 ( type -> V_107 ) ;
return - V_106 ;
}
F_92 ( V_174 , V_165 [ V_150 ] , V_175 ) ;
V_161 = F_134 ( V_1 , V_174 ) ;
if ( ! V_161 ) {
F_93 ( type -> V_107 ) ;
return - V_51 ;
}
V_163 -> V_161 = V_161 ;
} else if ( V_165 [ V_150 ] ) {
F_93 ( type -> V_107 ) ;
return - V_106 ;
}
return 0 ;
}
static void F_135 ( struct V_162 * V_163 )
{
F_93 ( V_163 -> type -> V_107 ) ;
if ( V_163 -> V_161 != NULL )
F_132 ( V_163 -> V_161 ) ;
}
static int F_136 ( struct V_1 * V_1 , struct V_93 * V_94 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_69 * V_70 = F_56 ( V_18 ) ;
const struct V_23 * V_176 ( V_61 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct F_25 * V_142 = NULL ;
T_2 V_60 = F_90 ( V_1 ) ;
int V_9 = V_70 -> V_72 ;
T_2 V_152 = V_177 ;
T_3 V_123 = 0 ;
unsigned int V_65 ;
struct V_124 T_4 * V_125 ;
int V_43 ;
bool V_164 ;
struct V_13 V_14 ;
V_164 = V_18 -> V_96 & V_178 ? true : false ;
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
case V_179 :
case V_177 :
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
if ( V_24 [ V_144 ] ) {
struct F_25 * V_142 ;
struct V_162 V_163 ;
struct V_143 * V_38 ;
if ( ! ( V_22 -> V_35 & V_37 ) )
return - V_122 ;
V_43 = F_133 ( V_1 , V_24 , V_3 , & V_163 ,
V_164 ) ;
if ( V_43 < 0 )
return V_43 ;
V_142 = F_25 ( V_22 ) ;
if ( V_142 -> type != V_163 . type ) {
F_135 ( & V_163 ) ;
return - V_122 ;
}
for ( V_65 = 0 ; V_65 < V_3 -> V_101 ; V_65 ++ ) {
V_38 = & V_142 -> V_38 [ V_65 ] ;
if ( V_38 -> V_146 != V_163 . V_169 ||
V_38 -> V_148 != V_163 . V_148 ||
V_38 -> V_161 != V_163 . V_161 ) {
F_135 ( & V_163 ) ;
return - V_122 ;
}
}
F_135 ( & V_163 ) ;
}
if ( V_24 [ V_139 ] && V_61 ) {
struct V_21 * V_180 ;
V_180 = F_104 ( V_20 ,
V_24 [ V_141 ] ,
V_60 ) ;
if ( F_80 ( V_180 ) )
return F_81 ( V_180 ) ;
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
F_137 ( V_32 ) = V_125 ;
F_138 ( V_32 ) = true ;
if ( V_24 [ V_151 ] )
F_139 ( V_32 ) = V_152 ;
else
F_139 ( V_32 ) = - 1 ;
if ( V_24 [ V_139 ] && V_61 ) {
F_92 ( F_140 ( V_32 ) , V_61 ,
V_181 ) ;
}
F_30 ( & V_32 -> V_6 , & V_1 -> V_7 . V_42 ) ;
return 0 ;
}
if ( V_20 -> V_48 == V_182 )
return - V_183 ;
if ( V_24 [ V_144 ] ) {
struct V_162 V_163 ;
struct V_143 * V_38 ;
T_5 * V_184 ;
V_43 = F_133 ( V_1 , V_24 , V_3 , & V_163 , V_164 ) ;
if ( V_43 < 0 )
return V_43 ;
V_142 = F_19 ( sizeof( * V_142 ) , V_33 ) ;
if ( V_142 == NULL ) {
F_135 ( & V_163 ) ;
return - V_40 ;
}
if ( V_163 . V_161 != NULL )
strncpy ( V_142 -> V_149 , V_163 . V_161 -> V_61 , V_175 ) ;
if ( V_24 [ V_133 ] ) {
V_125 = F_118 ( V_24 [ V_133 ] ) ;
if ( F_80 ( V_125 ) ) {
F_135 ( & V_163 ) ;
F_22 ( V_142 ) ;
return F_81 ( V_125 ) ;
}
V_142 -> V_125 = V_125 ;
} else {
V_125 = F_120 ( struct V_124 ) ;
if ( V_125 == NULL ) {
F_135 ( & V_163 ) ;
F_22 ( V_142 ) ;
return - V_40 ;
}
F_128 ( V_142 -> V_125 , V_125 ) ;
}
V_184 = V_163 . type -> V_185 [ V_163 . V_169 ] ;
V_142 -> type = V_163 . type ;
V_22 = & V_142 -> V_22 ;
for ( V_65 = 0 ; V_65 < V_3 -> V_101 ; V_65 ++ ) {
V_38 = & V_142 -> V_38 [ V_65 ] ;
V_38 -> V_186 = V_9 ;
V_38 -> V_146 = V_163 . V_169 ;
V_38 -> V_148 = V_163 . V_148 ;
V_38 -> V_187 = V_22 ;
V_38 -> V_163 = V_3 -> V_185 [ V_38 -> V_146 ] ;
V_38 -> V_161 = V_163 . V_161 ;
if ( V_184 )
V_38 -> V_163 = V_184 ;
if ( V_3 -> V_188 )
V_3 -> V_188 ( V_38 , V_65 ) ;
}
V_22 -> V_35 |= V_37 ;
V_142 -> V_152 = V_152 ;
} else {
V_22 = F_19 ( sizeof( * V_22 ) , V_33 ) ;
if ( V_22 == NULL )
return - V_40 ;
}
F_2 ( & V_22 -> V_189 ) ;
V_22 -> V_123 = F_49 ( V_20 ) ;
V_22 -> V_20 = V_20 ;
F_92 ( V_22 -> V_61 , V_61 , V_181 ) ;
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
static int F_141 ( struct V_1 * V_1 , struct V_93 * V_94 ,
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
int F_142 ( struct V_190 * type )
{
F_3 ( V_5 ) ;
if ( type -> V_9 == V_88 )
F_4 ( & type -> V_6 , & V_191 ) ;
else
F_143 ( & type -> V_6 , & V_191 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_144 ( struct V_190 * type )
{
F_3 ( V_5 ) ;
F_8 ( & type -> V_6 ) ;
F_5 ( V_5 ) ;
}
static const struct V_190 * F_145 ( T_2 V_9 ,
struct V_23 * V_24 )
{
const struct V_190 * type ;
F_10 (type, &nf_tables_expressions, list) {
if ( ! F_46 ( V_24 , type -> V_61 ) &&
( ! type -> V_9 || type -> V_9 == V_9 ) )
return type ;
}
return NULL ;
}
static const struct V_190 * F_146 ( T_2 V_9 ,
struct V_23 * V_24 )
{
const struct V_190 * type ;
if ( V_24 == NULL )
return F_14 ( - V_62 ) ;
type = F_145 ( V_9 , V_24 ) ;
if ( type != NULL && F_91 ( type -> V_107 ) )
return type ;
#ifdef F_12
if ( type == NULL ) {
F_5 ( V_5 ) ;
F_13 ( L_3 , V_9 ,
F_52 ( V_24 ) , ( char * ) F_53 ( V_24 ) ) ;
F_3 ( V_5 ) ;
if ( F_145 ( V_9 , V_24 ) )
return F_14 ( - V_11 ) ;
F_5 ( V_5 ) ;
F_13 ( L_4 ,
F_52 ( V_24 ) , ( char * ) F_53 ( V_24 ) ) ;
F_3 ( V_5 ) ;
if ( F_145 ( V_9 , V_24 ) )
return F_14 ( - V_11 ) ;
}
#endif
return F_14 ( - V_51 ) ;
}
static int F_147 ( struct V_15 * V_16 ,
const struct V_192 * V_193 )
{
if ( F_58 ( V_16 , V_194 , V_193 -> V_38 -> type -> V_61 ) )
goto V_71;
if ( V_193 -> V_38 -> V_100 ) {
struct V_23 * V_195 = F_110 ( V_16 , V_196 ) ;
if ( V_195 == NULL )
goto V_71;
if ( V_193 -> V_38 -> V_100 ( V_16 , V_193 ) < 0 )
goto V_71;
F_113 ( V_16 , V_195 ) ;
}
return V_16 -> V_92 ;
V_71:
return - 1 ;
}
int F_148 ( struct V_15 * V_16 , unsigned int V_155 ,
const struct V_192 * V_193 )
{
struct V_23 * V_128 ;
V_128 = F_110 ( V_16 , V_155 ) ;
if ( ! V_128 )
goto V_71;
if ( F_147 ( V_16 , V_193 ) < 0 )
goto V_71;
F_113 ( V_16 , V_128 ) ;
return 0 ;
V_71:
return - 1 ;
}
static int F_149 ( const struct V_13 * V_14 ,
const struct V_23 * V_24 ,
struct V_197 * V_198 )
{
const struct V_190 * type ;
const struct V_199 * V_38 ;
struct V_23 * V_156 [ V_200 + 1 ] ;
int V_43 ;
V_43 = F_119 ( V_156 , V_200 , V_24 , V_201 ) ;
if ( V_43 < 0 )
return V_43 ;
type = F_146 ( V_14 -> V_3 -> V_9 , V_156 [ V_194 ] ) ;
if ( F_80 ( type ) )
return F_81 ( type ) ;
if ( V_156 [ V_196 ] ) {
V_43 = F_119 ( V_198 -> V_156 , type -> V_202 ,
V_156 [ V_196 ] , type -> V_152 ) ;
if ( V_43 < 0 )
goto V_108;
} else
memset ( V_198 -> V_156 , 0 , sizeof( V_198 -> V_156 [ 0 ] ) * ( type -> V_202 + 1 ) ) ;
if ( type -> V_203 != NULL ) {
V_38 = type -> V_203 ( V_14 ,
( const struct V_23 * const * ) V_198 -> V_156 ) ;
if ( F_80 ( V_38 ) ) {
V_43 = F_81 ( V_38 ) ;
goto V_108;
}
} else
V_38 = type -> V_38 ;
V_198 -> V_38 = V_38 ;
return 0 ;
V_108:
F_93 ( type -> V_107 ) ;
return V_43 ;
}
static int F_150 ( const struct V_13 * V_14 ,
const struct V_197 * V_198 ,
struct V_192 * V_193 )
{
const struct V_199 * V_38 = V_198 -> V_38 ;
int V_43 ;
V_193 -> V_38 = V_38 ;
if ( V_38 -> V_204 ) {
V_43 = V_38 -> V_204 ( V_14 , V_193 , ( const struct V_23 * * ) V_198 -> V_156 ) ;
if ( V_43 < 0 )
goto V_108;
}
return 0 ;
V_108:
V_193 -> V_38 = NULL ;
return V_43 ;
}
static void F_151 ( const struct V_13 * V_14 ,
struct V_192 * V_193 )
{
if ( V_193 -> V_38 -> V_205 )
V_193 -> V_38 -> V_205 ( V_14 , V_193 ) ;
F_93 ( V_193 -> V_38 -> type -> V_107 ) ;
}
struct V_192 * F_152 ( const struct V_13 * V_14 ,
const struct V_23 * V_24 )
{
struct V_197 V_198 ;
struct V_192 * V_193 ;
int V_43 ;
V_43 = F_149 ( V_14 , V_24 , & V_198 ) ;
if ( V_43 < 0 )
goto V_108;
V_43 = - V_40 ;
V_193 = F_19 ( V_198 . V_38 -> V_31 , V_33 ) ;
if ( V_193 == NULL )
goto V_109;
V_43 = F_150 ( V_14 , & V_198 , V_193 ) ;
if ( V_43 < 0 )
goto V_113;
return V_193 ;
V_113:
F_22 ( V_193 ) ;
V_109:
F_93 ( V_198 . V_38 -> type -> V_107 ) ;
V_108:
return F_14 ( V_43 ) ;
}
void F_153 ( const struct V_13 * V_14 , struct V_192 * V_193 )
{
F_151 ( V_14 , V_193 ) ;
F_22 ( V_193 ) ;
}
static struct V_49 * F_154 ( const struct V_21 * V_22 ,
T_3 V_123 )
{
struct V_49 * V_50 ;
F_10 (rule, &chain->rules, list) {
if ( V_123 == V_50 -> V_123 )
return V_50 ;
}
return F_14 ( - V_51 ) ;
}
static struct V_49 * F_155 ( const struct V_21 * V_22 ,
const struct V_23 * V_24 )
{
if ( V_24 == NULL )
return F_14 ( - V_62 ) ;
return F_154 ( V_22 , F_123 ( F_124 ( V_24 ) ) ) ;
}
static int F_156 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_25 , T_1 V_27 , int V_68 ,
T_1 V_35 , int V_9 ,
const struct V_19 * V_20 ,
const struct V_21 * V_22 ,
const struct V_49 * V_50 )
{
struct V_17 * V_18 ;
struct V_69 * V_70 ;
const struct V_192 * V_193 , * V_206 ;
struct V_23 * V_6 ;
const struct V_49 * V_207 ;
int type = V_68 | V_5 << 8 ;
V_18 = F_55 ( V_16 , V_25 , V_27 , type , sizeof( struct V_69 ) ,
V_35 ) ;
if ( V_18 == NULL )
goto V_71;
V_70 = F_56 ( V_18 ) ;
V_70 -> V_72 = V_9 ;
V_70 -> V_73 = V_74 ;
V_70 -> V_75 = F_57 ( V_1 -> V_7 . V_76 & 0xffff ) ;
if ( F_58 ( V_16 , V_208 , V_20 -> V_61 ) )
goto V_71;
if ( F_58 ( V_16 , V_209 , V_22 -> V_61 ) )
goto V_71;
if ( F_111 ( V_16 , V_210 , F_112 ( V_50 -> V_123 ) ,
V_211 ) )
goto V_71;
if ( ( V_68 != V_53 ) && ( V_50 -> V_6 . V_212 != & V_22 -> V_189 ) ) {
V_207 = F_157 ( V_50 -> V_6 . V_212 , struct V_49 , V_6 ) ;
if ( F_111 ( V_16 , V_213 ,
F_112 ( V_207 -> V_123 ) ,
V_211 ) )
goto V_71;
}
V_6 = F_110 ( V_16 , V_214 ) ;
if ( V_6 == NULL )
goto V_71;
F_158 (expr, next, rule) {
if ( F_148 ( V_16 , V_215 , V_193 ) < 0 )
goto V_71;
}
F_113 ( V_16 , V_6 ) ;
if ( V_50 -> V_216 ) {
struct V_217 * V_216 = V_217 ( V_50 ) ;
if ( F_159 ( V_16 , V_218 , V_216 -> V_92 + 1 ,
V_216 -> V_195 ) < 0 )
goto V_71;
}
F_61 ( V_16 , V_18 ) ;
return 0 ;
V_71:
F_62 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_160 ( const struct V_13 * V_14 ,
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
V_43 = F_156 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_14 -> V_27 ,
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
static int F_161 ( struct V_15 * V_16 ,
struct V_83 * V_84 )
{
const struct V_69 * V_70 = F_56 ( V_84 -> V_18 ) ;
const struct V_219 * V_14 = V_84 -> V_195 ;
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
if ( F_156 ( V_16 , V_1 , F_16 ( V_84 -> V_16 ) . V_25 ,
V_84 -> V_18 -> V_28 ,
V_220 ,
V_90 | V_221 ,
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
static int F_162 ( struct V_83 * V_84 )
{
F_22 ( V_84 -> V_195 ) ;
return 0 ;
}
static int F_163 ( struct V_1 * V_1 , struct V_93 * V_94 ,
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
. V_100 = F_161 ,
. V_91 = F_162 ,
} ;
if ( V_24 [ V_208 ] || V_24 [ V_209 ] ) {
struct V_219 * V_14 ;
V_14 = F_19 ( sizeof( * V_14 ) , V_33 ) ;
if ( ! V_14 )
return - V_40 ;
if ( V_24 [ V_208 ] )
F_92 ( V_14 -> V_20 , V_24 [ V_208 ] ,
sizeof( V_14 -> V_20 ) ) ;
if ( V_24 [ V_209 ] )
F_92 ( V_14 -> V_22 , V_24 [ V_209 ] ,
sizeof( V_14 -> V_22 ) ) ;
V_99 . V_195 = V_14 ;
}
return F_79 ( V_94 , V_16 , V_18 , & V_99 ) ;
}
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_80 ( V_3 ) )
return F_81 ( V_3 ) ;
V_20 = F_48 ( V_3 , V_24 [ V_208 ] , V_60 ) ;
if ( F_80 ( V_20 ) )
return F_81 ( V_20 ) ;
V_22 = F_104 ( V_20 , V_24 [ V_209 ] , V_60 ) ;
if ( F_80 ( V_22 ) )
return F_81 ( V_22 ) ;
V_50 = F_155 ( V_22 , V_24 [ V_210 ] ) ;
if ( F_80 ( V_50 ) )
return F_81 ( V_50 ) ;
V_95 = F_82 ( V_82 , V_33 ) ;
if ( ! V_95 )
return - V_40 ;
V_43 = F_156 ( V_95 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 , V_220 , 0 ,
V_9 , V_20 , V_22 , V_50 ) ;
if ( V_43 < 0 )
goto V_43;
return F_83 ( V_94 , V_95 , F_16 ( V_16 ) . V_25 ) ;
V_43:
F_66 ( V_95 ) ;
return V_43 ;
}
static void F_164 ( const struct V_13 * V_14 ,
struct V_49 * V_50 )
{
struct V_192 * V_193 ;
V_193 = F_165 ( V_50 ) ;
while ( V_193 -> V_38 && V_193 != F_166 ( V_50 ) ) {
F_151 ( V_14 , V_193 ) ;
V_193 = F_167 ( V_193 ) ;
}
F_22 ( V_50 ) ;
}
static int F_168 ( struct V_1 * V_1 , struct V_93 * V_94 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_69 * V_70 = F_56 ( V_18 ) ;
T_2 V_60 = F_90 ( V_1 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_49 * V_50 , * V_222 = NULL ;
struct V_217 * V_216 ;
struct V_29 * V_32 = NULL ;
struct V_192 * V_193 ;
struct V_13 V_14 ;
struct V_23 * V_223 ;
unsigned int V_31 , V_65 , V_224 , V_225 = 0 , V_226 = 0 ;
int V_43 , V_227 ;
bool V_164 ;
T_3 V_123 , V_228 ;
V_164 = V_18 -> V_96 & V_178 ? true : false ;
V_3 = F_11 ( V_1 , V_70 -> V_72 , V_164 ) ;
if ( F_80 ( V_3 ) )
return F_81 ( V_3 ) ;
V_20 = F_48 ( V_3 , V_24 [ V_208 ] , V_60 ) ;
if ( F_80 ( V_20 ) )
return F_81 ( V_20 ) ;
V_22 = F_104 ( V_20 , V_24 [ V_209 ] , V_60 ) ;
if ( F_80 ( V_22 ) )
return F_81 ( V_22 ) ;
if ( V_24 [ V_210 ] ) {
V_123 = F_123 ( F_124 ( V_24 [ V_210 ] ) ) ;
V_50 = F_154 ( V_22 , V_123 ) ;
if ( F_80 ( V_50 ) )
return F_81 ( V_50 ) ;
if ( V_18 -> V_96 & V_103 )
return - V_104 ;
if ( V_18 -> V_96 & V_105 )
V_222 = V_50 ;
else
return - V_106 ;
} else {
if ( ! V_164 || V_18 -> V_96 & V_105 )
return - V_62 ;
V_123 = F_49 ( V_20 ) ;
if ( V_22 -> V_48 == V_182 )
return - V_183 ;
}
if ( V_24 [ V_213 ] ) {
if ( ! ( V_18 -> V_96 & V_178 ) )
return - V_106 ;
V_228 = F_123 ( F_124 ( V_24 [ V_213 ] ) ) ;
V_222 = F_154 ( V_22 , V_228 ) ;
if ( F_80 ( V_222 ) )
return F_81 ( V_222 ) ;
}
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_224 = 0 ;
V_31 = 0 ;
if ( V_24 [ V_214 ] ) {
F_169 (tmp, nla[NFTA_RULE_EXPRESSIONS], rem) {
V_43 = - V_62 ;
if ( F_170 ( V_223 ) != V_215 )
goto V_108;
if ( V_224 == V_229 )
goto V_108;
V_43 = F_149 ( & V_14 , V_223 , & V_198 [ V_224 ] ) ;
if ( V_43 < 0 )
goto V_108;
V_31 += V_198 [ V_224 ] . V_38 -> V_31 ;
V_224 ++ ;
}
}
V_43 = - V_230 ;
if ( V_31 >= 1 << 12 )
goto V_108;
if ( V_24 [ V_218 ] ) {
V_225 = F_52 ( V_24 [ V_218 ] ) ;
if ( V_225 > 0 )
V_226 = sizeof( struct V_217 ) + V_225 ;
}
V_43 = - V_40 ;
V_50 = F_19 ( sizeof( * V_50 ) + V_31 + V_226 , V_33 ) ;
if ( V_50 == NULL )
goto V_108;
F_29 ( V_1 , V_50 ) ;
V_50 -> V_123 = V_123 ;
V_50 -> V_231 = V_31 ;
V_50 -> V_216 = V_225 ? 1 : 0 ;
if ( V_225 ) {
V_216 = V_217 ( V_50 ) ;
V_216 -> V_92 = V_225 - 1 ;
F_171 ( V_216 -> V_195 , V_24 [ V_218 ] , V_225 ) ;
}
V_193 = F_165 ( V_50 ) ;
for ( V_65 = 0 ; V_65 < V_224 ; V_65 ++ ) {
V_43 = F_150 ( & V_14 , & V_198 [ V_65 ] , V_193 ) ;
if ( V_43 < 0 )
goto V_109;
V_198 [ V_65 ] . V_38 = NULL ;
V_193 = F_167 ( V_193 ) ;
}
if ( V_18 -> V_96 & V_105 ) {
if ( F_36 ( V_1 , V_222 ) ) {
V_32 = F_37 ( & V_14 , V_53 ,
V_222 ) ;
if ( V_32 == NULL ) {
V_43 = - V_40 ;
goto V_109;
}
F_32 ( V_1 , V_222 ) ;
V_22 -> V_48 -- ;
F_4 ( & V_50 -> V_6 , & V_222 -> V_6 ) ;
} else {
V_43 = - V_51 ;
goto V_109;
}
} else if ( V_18 -> V_96 & V_221 )
if ( V_222 )
F_143 ( & V_50 -> V_6 , & V_222 -> V_6 ) ;
else
F_4 ( & V_50 -> V_6 , & V_22 -> V_189 ) ;
else {
if ( V_222 )
F_4 ( & V_50 -> V_6 , & V_222 -> V_6 ) ;
else
F_143 ( & V_50 -> V_6 , & V_22 -> V_189 ) ;
}
if ( F_37 ( & V_14 , V_220 , V_50 ) == NULL ) {
V_43 = - V_40 ;
goto V_113;
}
V_22 -> V_48 ++ ;
return 0 ;
V_113:
F_8 ( & V_50 -> V_6 ) ;
V_109:
F_164 ( & V_14 , V_50 ) ;
V_108:
for ( V_65 = 0 ; V_65 < V_224 ; V_65 ++ ) {
if ( V_198 [ V_65 ] . V_38 != NULL )
F_93 ( V_198 [ V_65 ] . V_38 -> type -> V_107 ) ;
}
return V_43 ;
}
static int F_172 ( struct V_1 * V_1 , struct V_93 * V_94 ,
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
V_20 = F_48 ( V_3 , V_24 [ V_208 ] , V_60 ) ;
if ( F_80 ( V_20 ) )
return F_81 ( V_20 ) ;
if ( V_24 [ V_209 ] ) {
V_22 = F_104 ( V_20 , V_24 [ V_209 ] ,
V_60 ) ;
if ( F_80 ( V_22 ) )
return F_81 ( V_22 ) ;
}
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
if ( V_22 ) {
if ( V_24 [ V_210 ] ) {
V_50 = F_155 ( V_22 ,
V_24 [ V_210 ] ) ;
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
int F_173 ( struct V_232 * V_38 )
{
F_3 ( V_5 ) ;
F_4 ( & V_38 -> V_6 , & V_233 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_174 ( struct V_232 * V_38 )
{
F_3 ( V_5 ) ;
F_8 ( & V_38 -> V_6 ) ;
F_5 ( V_5 ) ;
}
static const struct V_232 *
F_175 ( const struct V_23 * const V_24 [] ,
const struct V_234 * V_235 ,
enum V_236 V_152 )
{
const struct V_232 * V_38 , * V_237 ;
struct V_238 V_239 , V_240 ;
T_1 V_241 ;
#ifdef F_12
if ( F_96 ( & V_233 ) ) {
F_5 ( V_5 ) ;
F_13 ( L_5 ) ;
F_3 ( V_5 ) ;
if ( ! F_96 ( & V_233 ) )
return F_14 ( - V_11 ) ;
}
#endif
V_241 = 0 ;
if ( V_24 [ V_242 ] != NULL ) {
V_241 = F_42 ( F_43 ( V_24 [ V_242 ] ) ) ;
V_241 &= V_243 | V_244 | V_245 ;
}
V_237 = NULL ;
V_240 . V_31 = ~ 0 ;
V_240 . V_246 = ~ 0 ;
F_10 (ops, &nf_tables_set_ops, list) {
if ( ( V_38 -> V_241 & V_241 ) != V_241 )
continue;
if ( ! V_38 -> V_247 ( V_235 , V_241 , & V_239 ) )
continue;
switch ( V_152 ) {
case V_248 :
if ( V_239 . V_246 < V_240 . V_246 )
break;
if ( V_239 . V_246 == V_240 . V_246 && V_239 . V_31 < V_240 . V_31 )
break;
continue;
case V_249 :
if ( V_239 . V_31 < V_240 . V_31 )
break;
if ( V_239 . V_31 == V_240 . V_31 && V_239 . V_246 < V_240 . V_246 )
break;
continue;
default:
break;
}
if ( ! F_91 ( V_38 -> V_107 ) )
continue;
if ( V_237 != NULL )
F_93 ( V_237 -> V_107 ) ;
V_237 = V_38 ;
V_240 = V_239 ;
}
if ( V_237 != NULL )
return V_237 ;
return F_14 ( - V_106 ) ;
}
static int F_176 ( struct V_13 * V_14 , struct V_1 * V_1 ,
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
if ( V_24 [ V_250 ] != NULL ) {
if ( V_3 == NULL )
return - V_12 ;
V_20 = F_48 ( V_3 , V_24 [ V_250 ] ,
V_60 ) ;
if ( F_80 ( V_20 ) )
return F_81 ( V_20 ) ;
}
F_15 ( V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return 0 ;
}
struct V_54 * F_177 ( const struct V_19 * V_20 ,
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
struct V_54 * F_178 ( const struct V_1 * V_1 ,
const struct V_23 * V_24 ,
T_2 V_60 )
{
struct V_29 * V_32 ;
T_1 V_251 = F_42 ( F_43 ( V_24 ) ) ;
F_10 (trans, &net->nft.commit_list, list) {
struct V_54 * V_55 = V_56 ( V_32 ) ;
if ( V_32 -> V_30 == V_57 &&
V_251 == F_41 ( V_32 ) &&
F_47 ( V_55 , V_60 ) )
return V_55 ;
}
return F_14 ( - V_51 ) ;
}
static int F_179 ( struct V_13 * V_14 , struct V_54 * V_55 ,
const char * V_61 )
{
const struct V_54 * V_65 ;
const char * V_252 ;
unsigned long * V_253 ;
unsigned int V_224 = 0 , V_254 = 0 ;
V_252 = F_180 ( V_61 , V_255 , '%' ) ;
if ( V_252 != NULL ) {
if ( V_252 [ 1 ] != 'd' || strchr ( V_252 + 2 , '%' ) )
return - V_62 ;
V_253 = ( unsigned long * ) F_181 ( V_33 ) ;
if ( V_253 == NULL )
return - V_40 ;
V_89:
F_10 (i, &ctx->table->sets, list) {
int V_223 ;
if ( ! F_36 ( V_14 -> V_1 , V_55 ) )
continue;
if ( ! sscanf ( V_65 -> V_61 , V_61 , & V_223 ) )
continue;
if ( V_223 < V_254 || V_223 >= V_254 + V_256 * V_257 )
continue;
F_182 ( V_223 - V_254 , V_253 ) ;
}
V_224 = F_183 ( V_253 , V_256 * V_257 ) ;
if ( V_224 >= V_256 * V_257 ) {
V_254 += V_256 * V_257 ;
memset ( V_253 , 0 , V_257 ) ;
goto V_89;
}
F_184 ( ( unsigned long ) V_253 ) ;
}
snprintf ( V_55 -> V_61 , sizeof( V_55 -> V_61 ) , V_61 , V_254 + V_224 ) ;
F_10 (i, &ctx->table->sets, list) {
if ( ! F_36 ( V_14 -> V_1 , V_65 ) )
continue;
if ( ! strcmp ( V_55 -> V_61 , V_65 -> V_61 ) )
return - V_258 ;
}
return 0 ;
}
static int F_185 ( struct V_15 * V_16 , const struct V_13 * V_14 ,
const struct V_54 * V_55 , T_6 V_68 , T_6 V_35 )
{
struct V_69 * V_70 ;
struct V_17 * V_18 ;
struct V_23 * V_235 ;
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
if ( F_58 ( V_16 , V_250 , V_14 -> V_20 -> V_61 ) )
goto V_71;
if ( F_58 ( V_16 , V_259 , V_55 -> V_61 ) )
goto V_71;
if ( V_55 -> V_35 != 0 )
if ( F_59 ( V_16 , V_242 , F_60 ( V_55 -> V_35 ) ) )
goto V_71;
if ( F_59 ( V_16 , V_260 , F_60 ( V_55 -> V_261 ) ) )
goto V_71;
if ( F_59 ( V_16 , V_262 , F_60 ( V_55 -> V_263 ) ) )
goto V_71;
if ( V_55 -> V_35 & V_244 ) {
if ( F_59 ( V_16 , V_264 , F_60 ( V_55 -> V_265 ) ) )
goto V_71;
if ( F_59 ( V_16 , V_266 , F_60 ( V_55 -> V_231 ) ) )
goto V_71;
}
if ( V_55 -> V_267 &&
F_111 ( V_16 , V_268 ,
F_112 ( F_186 ( V_55 -> V_267 ) ) ,
V_269 ) )
goto V_71;
if ( V_55 -> V_270 &&
F_59 ( V_16 , V_271 , F_60 ( V_55 -> V_270 ) ) )
goto V_71;
if ( V_55 -> V_152 != V_248 ) {
if ( F_59 ( V_16 , V_272 , F_60 ( V_55 -> V_152 ) ) )
goto V_71;
}
if ( F_159 ( V_16 , V_273 , V_55 -> V_274 , V_55 -> V_216 ) )
goto V_71;
V_235 = F_110 ( V_16 , V_275 ) ;
if ( V_235 == NULL )
goto V_71;
if ( V_55 -> V_31 &&
F_59 ( V_16 , V_276 , F_60 ( V_55 -> V_31 ) ) )
goto V_71;
F_113 ( V_16 , V_235 ) ;
F_61 ( V_16 , V_18 ) ;
return 0 ;
V_71:
F_62 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_187 ( const struct V_13 * V_14 ,
const struct V_54 * V_55 ,
int V_68 , T_7 V_277 )
{
struct V_15 * V_16 ;
T_1 V_25 = V_14 -> V_25 ;
int V_43 ;
if ( ! V_14 -> V_26 &&
! F_64 ( V_14 -> V_1 , V_80 ) )
return 0 ;
V_43 = - V_81 ;
V_16 = F_65 ( V_82 , V_277 ) ;
if ( V_16 == NULL )
goto V_43;
V_43 = F_185 ( V_16 , V_14 , V_55 , V_68 , 0 ) ;
if ( V_43 < 0 ) {
F_66 ( V_16 ) ;
goto V_43;
}
V_43 = F_67 ( V_16 , V_14 -> V_1 , V_25 , V_80 ,
V_14 -> V_26 , V_277 ) ;
V_43:
if ( V_43 < 0 )
F_68 ( V_14 -> V_1 , V_25 , V_80 , V_43 ) ;
return V_43 ;
}
static int F_188 ( struct V_15 * V_16 , struct V_83 * V_84 )
{
const struct V_54 * V_55 ;
unsigned int V_85 , V_86 = V_84 -> args [ 0 ] ;
struct V_2 * V_3 ;
struct V_19 * V_20 , * V_278 = (struct V_19 * ) V_84 -> args [ 2 ] ;
struct V_1 * V_1 = F_70 ( V_16 -> V_87 ) ;
int V_279 = V_84 -> args [ 3 ] ;
struct V_13 * V_14 = V_84 -> V_195 , V_280 ;
if ( V_84 -> args [ 1 ] )
return V_16 -> V_92 ;
F_71 () ;
V_84 -> V_27 = V_1 -> V_7 . V_76 ;
F_72 (afi, &net->nft.af_info, list) {
if ( V_14 -> V_3 && V_14 -> V_3 != V_3 )
continue;
if ( V_279 ) {
if ( V_3 -> V_9 != V_279 )
continue;
V_279 = 0 ;
}
F_72 (table, &afi->tables, list) {
if ( V_14 -> V_20 && V_14 -> V_20 != V_20 )
continue;
if ( V_278 ) {
if ( V_278 != V_20 )
continue;
V_278 = NULL ;
}
V_85 = 0 ;
F_72 (set, &table->sets, list) {
if ( V_85 < V_86 )
goto V_89;
if ( ! F_73 ( V_1 , V_55 ) )
goto V_89;
V_280 = * V_14 ;
V_280 . V_20 = V_20 ;
V_280 . V_3 = V_3 ;
if ( F_185 ( V_16 , & V_280 , V_55 ,
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
static int F_189 ( struct V_83 * V_84 )
{
F_22 ( V_84 -> V_195 ) ;
return 0 ;
}
static int F_190 ( struct V_1 * V_1 , struct V_93 * V_94 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
T_2 V_60 = F_78 ( V_1 ) ;
const struct V_54 * V_55 ;
struct V_13 V_14 ;
struct V_15 * V_95 ;
const struct V_69 * V_70 = F_56 ( V_18 ) ;
int V_43 ;
V_43 = F_176 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_60 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_18 -> V_96 & V_97 ) {
struct V_98 V_99 = {
. V_100 = F_188 ,
. V_91 = F_189 ,
} ;
struct V_13 * V_281 ;
V_281 = F_191 ( sizeof( * V_281 ) , V_33 ) ;
if ( V_281 == NULL )
return - V_40 ;
* V_281 = V_14 ;
V_99 . V_195 = V_281 ;
return F_79 ( V_94 , V_16 , V_18 , & V_99 ) ;
}
if ( V_70 -> V_72 == V_88 )
return - V_12 ;
if ( ! V_24 [ V_250 ] )
return - V_62 ;
V_55 = F_177 ( V_14 . V_20 , V_24 [ V_259 ] , V_60 ) ;
if ( F_80 ( V_55 ) )
return F_81 ( V_55 ) ;
V_95 = F_82 ( V_82 , V_33 ) ;
if ( V_95 == NULL )
return - V_40 ;
V_43 = F_185 ( V_95 , & V_14 , V_55 , V_57 , 0 ) ;
if ( V_43 < 0 )
goto V_43;
return F_83 ( V_94 , V_95 , F_16 ( V_16 ) . V_25 ) ;
V_43:
F_66 ( V_95 ) ;
return V_43 ;
}
static int F_192 ( const struct V_13 * V_14 ,
struct V_234 * V_235 ,
const struct V_23 * V_24 )
{
struct V_23 * V_282 [ V_283 + 1 ] ;
int V_43 ;
V_43 = F_119 ( V_282 , V_283 , V_24 , V_284 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_282 [ V_276 ] != NULL )
V_235 -> V_31 = F_42 ( F_43 ( V_282 [ V_276 ] ) ) ;
return 0 ;
}
static int F_193 ( struct V_1 * V_1 , struct V_93 * V_94 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_69 * V_70 = F_56 ( V_18 ) ;
T_2 V_60 = F_90 ( V_1 ) ;
const struct V_232 * V_38 ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_54 * V_55 ;
struct V_13 V_14 ;
char V_61 [ V_255 ] ;
unsigned int V_31 ;
bool V_164 ;
T_3 V_267 ;
T_1 V_261 , V_265 , V_35 , V_152 , V_270 ;
struct V_234 V_235 ;
unsigned char * V_216 ;
T_6 V_274 ;
int V_43 ;
if ( V_24 [ V_250 ] == NULL ||
V_24 [ V_259 ] == NULL ||
V_24 [ V_262 ] == NULL ||
V_24 [ V_58 ] == NULL )
return - V_62 ;
memset ( & V_235 , 0 , sizeof( V_235 ) ) ;
V_261 = V_285 ;
if ( V_24 [ V_260 ] != NULL ) {
V_261 = F_42 ( F_43 ( V_24 [ V_260 ] ) ) ;
if ( ( V_261 & V_286 ) == V_286 )
return - V_62 ;
}
V_235 . V_263 = F_42 ( F_43 ( V_24 [ V_262 ] ) ) ;
if ( V_235 . V_263 == 0 || V_235 . V_263 > V_287 )
return - V_62 ;
V_35 = 0 ;
if ( V_24 [ V_242 ] != NULL ) {
V_35 = F_42 ( F_43 ( V_24 [ V_242 ] ) ) ;
if ( V_35 & ~ ( V_117 | V_288 |
V_243 | V_245 |
V_244 | V_289 ) )
return - V_62 ;
if ( ( V_35 & ( V_244 | V_289 ) ) ==
( V_244 | V_289 ) )
return - V_106 ;
}
V_265 = 0 ;
if ( V_24 [ V_264 ] != NULL ) {
if ( ! ( V_35 & V_244 ) )
return - V_62 ;
V_265 = F_42 ( F_43 ( V_24 [ V_264 ] ) ) ;
if ( ( V_265 & V_286 ) == V_286 &&
V_265 != V_290 )
return - V_62 ;
if ( V_265 != V_290 ) {
if ( V_24 [ V_266 ] == NULL )
return - V_62 ;
V_235 . V_231 = F_42 ( F_43 ( V_24 [ V_266 ] ) ) ;
if ( V_235 . V_231 == 0 || V_235 . V_231 > V_287 )
return - V_62 ;
} else
V_235 . V_231 = sizeof( struct V_291 ) ;
} else if ( V_35 & V_244 )
return - V_62 ;
V_267 = 0 ;
if ( V_24 [ V_268 ] != NULL ) {
if ( ! ( V_35 & V_245 ) )
return - V_62 ;
V_267 = F_194 ( F_123 ( F_124 (
V_24 [ V_268 ] ) ) ) ;
}
V_270 = 0 ;
if ( V_24 [ V_271 ] != NULL ) {
if ( ! ( V_35 & V_245 ) )
return - V_62 ;
V_270 = F_42 ( F_43 ( V_24 [ V_271 ] ) ) ;
}
V_152 = V_248 ;
if ( V_24 [ V_272 ] != NULL )
V_152 = F_42 ( F_43 ( V_24 [ V_272 ] ) ) ;
if ( V_24 [ V_275 ] != NULL ) {
V_43 = F_192 ( & V_14 , & V_235 , V_24 [ V_275 ] ) ;
if ( V_43 < 0 )
return V_43 ;
}
V_164 = V_18 -> V_96 & V_178 ? true : false ;
V_3 = F_11 ( V_1 , V_70 -> V_72 , V_164 ) ;
if ( F_80 ( V_3 ) )
return F_81 ( V_3 ) ;
V_20 = F_48 ( V_3 , V_24 [ V_250 ] , V_60 ) ;
if ( F_80 ( V_20 ) )
return F_81 ( V_20 ) ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
V_55 = F_177 ( V_20 , V_24 [ V_259 ] , V_60 ) ;
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
if ( ! ( V_18 -> V_96 & V_178 ) )
return - V_51 ;
V_38 = F_175 ( V_24 , & V_235 , V_152 ) ;
if ( F_80 ( V_38 ) )
return F_81 ( V_38 ) ;
V_274 = 0 ;
if ( V_24 [ V_273 ] )
V_274 = F_52 ( V_24 [ V_273 ] ) ;
V_31 = 0 ;
if ( V_38 -> V_292 != NULL )
V_31 = V_38 -> V_292 ( V_24 ) ;
V_43 = - V_40 ;
V_55 = F_19 ( sizeof( * V_55 ) + V_31 + V_274 , V_33 ) ;
if ( V_55 == NULL )
goto V_108;
F_92 ( V_61 , V_24 [ V_259 ] , sizeof( V_55 -> V_61 ) ) ;
V_43 = F_179 ( & V_14 , V_55 , V_61 ) ;
if ( V_43 < 0 )
goto V_109;
V_216 = NULL ;
if ( V_274 ) {
V_216 = V_55 -> V_195 + V_31 ;
F_171 ( V_216 , V_24 [ V_273 ] , V_274 ) ;
}
F_2 ( & V_55 -> V_118 ) ;
V_55 -> V_38 = V_38 ;
V_55 -> V_261 = V_261 ;
V_55 -> V_263 = V_235 . V_263 ;
V_55 -> V_265 = V_265 ;
V_55 -> V_231 = V_235 . V_231 ;
V_55 -> V_35 = V_35 ;
V_55 -> V_31 = V_235 . V_31 ;
V_55 -> V_152 = V_152 ;
V_55 -> V_274 = V_274 ;
V_55 -> V_216 = V_216 ;
V_55 -> V_267 = V_267 ;
V_55 -> V_270 = V_270 ;
V_43 = V_38 -> V_204 ( V_55 , & V_235 , V_24 ) ;
if ( V_43 < 0 )
goto V_109;
V_43 = F_40 ( & V_14 , V_57 , V_55 ) ;
if ( V_43 < 0 )
goto V_113;
F_4 ( & V_55 -> V_6 , & V_20 -> V_112 ) ;
V_20 -> V_48 ++ ;
return 0 ;
V_113:
V_38 -> V_205 ( V_55 ) ;
V_109:
F_22 ( V_55 ) ;
V_108:
F_93 ( V_38 -> V_107 ) ;
return V_43 ;
}
static void F_195 ( struct V_54 * V_55 )
{
V_55 -> V_38 -> V_205 ( V_55 ) ;
F_93 ( V_55 -> V_38 -> V_107 ) ;
F_22 ( V_55 ) ;
}
static void F_196 ( const struct V_13 * V_14 , struct V_54 * V_55 )
{
F_8 ( & V_55 -> V_6 ) ;
F_187 ( V_14 , V_55 , V_59 , V_293 ) ;
F_195 ( V_55 ) ;
}
static int F_197 ( struct V_1 * V_1 , struct V_93 * V_94 ,
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
if ( V_24 [ V_250 ] == NULL )
return - V_62 ;
V_43 = F_176 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_60 ) ;
if ( V_43 < 0 )
return V_43 ;
V_55 = F_177 ( V_14 . V_20 , V_24 [ V_259 ] , V_60 ) ;
if ( F_80 ( V_55 ) )
return F_81 ( V_55 ) ;
if ( ! F_96 ( & V_55 -> V_118 ) )
return - V_122 ;
return F_44 ( & V_14 , V_55 ) ;
}
static int F_198 ( const struct V_13 * V_14 ,
const struct V_54 * V_55 ,
const struct V_294 * V_295 ,
const struct V_296 * V_297 )
{
const struct V_298 * V_299 = F_199 ( V_55 , V_297 -> V_187 ) ;
enum V_300 V_301 ;
V_301 = F_200 ( V_55 -> V_265 ) ;
return F_201 ( V_14 , V_301 , F_202 ( V_299 ) ,
V_55 -> V_265 == V_290 ?
V_290 : V_285 ,
V_55 -> V_231 ) ;
}
int F_203 ( const struct V_13 * V_14 , struct V_54 * V_55 ,
struct V_302 * V_303 )
{
struct V_302 * V_65 ;
struct V_294 V_295 ;
if ( ! F_96 ( & V_55 -> V_118 ) && V_55 -> V_35 & V_117 )
return - V_122 ;
if ( V_303 -> V_35 & V_244 ) {
F_10 (i, &set->bindings, list) {
if ( V_65 -> V_35 & V_244 &&
V_65 -> V_22 == V_303 -> V_22 )
goto V_304;
}
V_295 . V_60 = F_90 ( V_14 -> V_1 ) ;
V_295 . V_305 = 0 ;
V_295 . V_306 = 0 ;
V_295 . V_43 = 0 ;
V_295 . V_307 = F_198 ;
V_55 -> V_38 -> V_308 ( V_14 , V_55 , & V_295 ) ;
if ( V_295 . V_43 < 0 )
return V_295 . V_43 ;
}
V_304:
V_303 -> V_22 = V_14 -> V_22 ;
F_4 ( & V_303 -> V_6 , & V_55 -> V_118 ) ;
return 0 ;
}
void F_204 ( const struct V_13 * V_14 , struct V_54 * V_55 ,
struct V_302 * V_303 )
{
F_8 ( & V_303 -> V_6 ) ;
if ( F_96 ( & V_55 -> V_118 ) && V_55 -> V_35 & V_117 &&
F_73 ( V_14 -> V_1 , V_55 ) )
F_196 ( V_14 , V_55 ) ;
}
static int F_205 ( struct V_13 * V_14 , struct V_1 * V_1 ,
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
V_20 = F_48 ( V_3 , V_24 [ V_309 ] ,
V_60 ) ;
if ( F_80 ( V_20 ) )
return F_81 ( V_20 ) ;
F_15 ( V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return 0 ;
}
static int F_206 ( struct V_15 * V_16 ,
const struct V_54 * V_55 ,
const struct V_296 * V_297 )
{
const struct V_298 * V_299 = F_199 ( V_55 , V_297 -> V_187 ) ;
unsigned char * V_310 = F_207 ( V_16 ) ;
struct V_23 * V_128 ;
V_128 = F_110 ( V_16 , V_215 ) ;
if ( V_128 == NULL )
goto V_71;
if ( F_208 ( V_16 , V_311 , F_209 ( V_299 ) ,
V_285 , V_55 -> V_263 ) < 0 )
goto V_71;
if ( F_210 ( V_299 , V_312 ) &&
F_208 ( V_16 , V_313 , F_202 ( V_299 ) ,
V_55 -> V_265 == V_290 ? V_290 : V_285 ,
V_55 -> V_231 ) < 0 )
goto V_71;
if ( F_210 ( V_299 , V_314 ) &&
F_148 ( V_16 , V_315 , F_211 ( V_299 ) ) < 0 )
goto V_71;
if ( F_210 ( V_299 , V_316 ) &&
F_59 ( V_16 , V_317 ,
F_60 ( * F_212 ( V_299 ) ) ) )
goto V_71;
if ( F_210 ( V_299 , V_318 ) &&
F_111 ( V_16 , V_319 ,
F_112 ( F_186 (
* F_213 ( V_299 ) ) ) ,
V_320 ) )
goto V_71;
if ( F_210 ( V_299 , V_321 ) ) {
unsigned long V_322 , V_323 = V_324 ;
V_322 = * F_214 ( V_299 ) ;
if ( F_215 ( V_323 , V_322 ) )
V_322 -= V_323 ;
else
V_322 = 0 ;
if ( F_111 ( V_16 , V_325 ,
F_112 ( F_186 ( V_322 ) ) ,
V_320 ) )
goto V_71;
}
if ( F_210 ( V_299 , V_326 ) ) {
struct V_217 * V_216 ;
V_216 = F_216 ( V_299 ) ;
if ( F_159 ( V_16 , V_327 ,
V_216 -> V_92 + 1 , V_216 -> V_195 ) )
goto V_71;
}
F_113 ( V_16 , V_128 ) ;
return 0 ;
V_71:
F_62 ( V_16 , V_310 ) ;
return - V_328 ;
}
static int F_217 ( const struct V_13 * V_14 ,
const struct V_54 * V_55 ,
const struct V_294 * V_295 ,
const struct V_296 * V_297 )
{
struct V_329 * args ;
args = F_218 ( V_295 , struct V_329 , V_295 ) ;
return F_206 ( args -> V_16 , V_55 , V_297 ) ;
}
static int F_219 ( struct V_15 * V_16 , struct V_83 * V_84 )
{
struct V_1 * V_1 = F_70 ( V_16 -> V_87 ) ;
T_2 V_60 = F_78 ( V_1 ) ;
const struct V_54 * V_55 ;
struct V_329 args ;
struct V_13 V_14 ;
struct V_23 * V_24 [ V_330 + 1 ] ;
struct V_69 * V_70 ;
struct V_17 * V_18 ;
struct V_23 * V_128 ;
T_1 V_25 , V_27 ;
int V_68 , V_43 ;
V_43 = F_220 ( V_84 -> V_18 , sizeof( struct V_69 ) , V_24 ,
V_330 , V_331 ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 = F_205 ( & V_14 , V_1 , V_84 -> V_16 , V_84 -> V_18 ,
( void * ) V_24 , V_60 ) ;
if ( V_43 < 0 )
return V_43 ;
V_55 = F_177 ( V_14 . V_20 , V_24 [ V_332 ] ,
V_60 ) ;
if ( F_80 ( V_55 ) )
return F_81 ( V_55 ) ;
V_68 = V_333 ;
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
if ( F_58 ( V_16 , V_309 , V_14 . V_20 -> V_61 ) )
goto V_71;
if ( F_58 ( V_16 , V_332 , V_55 -> V_61 ) )
goto V_71;
V_128 = F_110 ( V_16 , V_334 ) ;
if ( V_128 == NULL )
goto V_71;
args . V_84 = V_84 ;
args . V_16 = V_16 ;
args . V_295 . V_60 = F_78 ( V_14 . V_1 ) ;
args . V_295 . V_305 = V_84 -> args [ 0 ] ;
args . V_295 . V_306 = 0 ;
args . V_295 . V_43 = 0 ;
args . V_295 . V_307 = F_217 ;
V_55 -> V_38 -> V_308 ( & V_14 , V_55 , & args . V_295 ) ;
F_113 ( V_16 , V_128 ) ;
F_61 ( V_16 , V_18 ) ;
if ( args . V_295 . V_43 && args . V_295 . V_43 != - V_328 )
return args . V_295 . V_43 ;
if ( args . V_295 . V_306 == V_84 -> args [ 0 ] )
return 0 ;
V_84 -> args [ 0 ] = args . V_295 . V_306 ;
return V_16 -> V_92 ;
V_71:
return - V_137 ;
}
static int F_221 ( struct V_1 * V_1 , struct V_93 * V_94 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
T_2 V_60 = F_78 ( V_1 ) ;
const struct V_54 * V_55 ;
struct V_13 V_14 ;
int V_43 ;
V_43 = F_205 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_60 ) ;
if ( V_43 < 0 )
return V_43 ;
V_55 = F_177 ( V_14 . V_20 , V_24 [ V_332 ] ,
V_60 ) ;
if ( F_80 ( V_55 ) )
return F_81 ( V_55 ) ;
if ( V_18 -> V_96 & V_97 ) {
struct V_98 V_99 = {
. V_100 = F_219 ,
} ;
return F_79 ( V_94 , V_16 , V_18 , & V_99 ) ;
}
return - V_106 ;
}
static int F_222 ( struct V_15 * V_16 ,
const struct V_13 * V_14 , T_1 V_27 ,
T_1 V_25 , int V_68 , T_6 V_35 ,
const struct V_54 * V_55 ,
const struct V_296 * V_297 )
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
if ( F_58 ( V_16 , V_250 , V_14 -> V_20 -> V_61 ) )
goto V_71;
if ( F_58 ( V_16 , V_259 , V_55 -> V_61 ) )
goto V_71;
V_128 = F_110 ( V_16 , V_334 ) ;
if ( V_128 == NULL )
goto V_71;
V_43 = F_206 ( V_16 , V_55 , V_297 ) ;
if ( V_43 < 0 )
goto V_71;
F_113 ( V_16 , V_128 ) ;
F_61 ( V_16 , V_18 ) ;
return 0 ;
V_71:
F_62 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_223 ( const struct V_13 * V_14 ,
const struct V_54 * V_55 ,
const struct V_296 * V_297 ,
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
V_43 = F_222 ( V_16 , V_14 , 0 , V_25 , V_68 , V_35 ,
V_55 , V_297 ) ;
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
static struct V_29 * F_224 ( struct V_13 * V_14 ,
int V_30 ,
struct V_54 * V_55 )
{
struct V_29 * V_32 ;
V_32 = F_18 ( V_14 , V_30 , sizeof( struct V_335 ) ) ;
if ( V_32 == NULL )
return NULL ;
F_225 ( V_32 ) = V_55 ;
return V_32 ;
}
void * F_226 ( const struct V_54 * V_55 ,
const struct V_336 * V_337 ,
const T_1 * V_338 , const T_1 * V_195 ,
T_3 V_267 , T_7 V_339 )
{
struct V_298 * V_299 ;
void * V_297 ;
V_297 = F_19 ( V_55 -> V_38 -> V_340 + V_337 -> V_92 , V_339 ) ;
if ( V_297 == NULL )
return NULL ;
V_299 = F_199 ( V_55 , V_297 ) ;
F_227 ( V_299 , V_337 ) ;
memcpy ( F_209 ( V_299 ) , V_338 , V_55 -> V_263 ) ;
if ( F_210 ( V_299 , V_312 ) )
memcpy ( F_202 ( V_299 ) , V_195 , V_55 -> V_231 ) ;
if ( F_210 ( V_299 , V_321 ) )
* F_214 ( V_299 ) =
V_324 + V_267 ;
if ( F_210 ( V_299 , V_318 ) )
* F_213 ( V_299 ) = V_267 ;
return V_297 ;
}
void F_228 ( const struct V_54 * V_55 , void * V_297 ,
bool V_341 )
{
struct V_298 * V_299 = F_199 ( V_55 , V_297 ) ;
F_229 ( F_209 ( V_299 ) , V_285 ) ;
if ( F_210 ( V_299 , V_312 ) )
F_229 ( F_202 ( V_299 ) , V_55 -> V_265 ) ;
if ( V_341 && F_210 ( V_299 , V_314 ) )
F_151 ( NULL , F_211 ( V_299 ) ) ;
F_22 ( V_297 ) ;
}
static int F_230 ( const struct V_54 * V_55 ,
const struct V_23 * V_155 , T_1 * V_35 )
{
if ( V_155 == NULL )
return 0 ;
* V_35 = F_42 ( F_43 ( V_155 ) ) ;
if ( * V_35 & ~ V_342 )
return - V_62 ;
if ( ! ( V_55 -> V_35 & V_243 ) &&
* V_35 & V_342 )
return - V_62 ;
return 0 ;
}
static int F_231 ( struct V_13 * V_14 , struct V_54 * V_55 ,
const struct V_23 * V_155 , T_1 V_96 )
{
struct V_23 * V_24 [ V_343 + 1 ] ;
struct V_344 V_345 , V_346 ;
struct V_336 V_337 ;
struct V_298 * V_299 , * V_347 ;
struct V_296 V_297 ;
struct V_302 * V_303 ;
struct V_217 * V_216 ;
struct V_348 V_195 ;
enum V_300 V_301 ;
struct V_29 * V_32 ;
T_1 V_35 = 0 ;
T_3 V_267 ;
T_2 V_225 ;
int V_43 ;
V_43 = F_119 ( V_24 , V_343 , V_155 ,
V_349 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_24 [ V_311 ] == NULL )
return - V_62 ;
F_232 ( & V_337 ) ;
V_43 = F_230 ( V_55 , V_24 [ V_317 ] , & V_35 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_35 != 0 )
F_233 ( & V_337 , V_316 ) ;
if ( V_55 -> V_35 & V_244 ) {
if ( V_24 [ V_313 ] == NULL &&
! ( V_35 & V_342 ) )
return - V_62 ;
if ( V_24 [ V_313 ] != NULL &&
V_35 & V_342 )
return - V_62 ;
} else {
if ( V_24 [ V_313 ] != NULL )
return - V_62 ;
}
V_267 = 0 ;
if ( V_24 [ V_319 ] != NULL ) {
if ( ! ( V_55 -> V_35 & V_245 ) )
return - V_62 ;
V_267 = F_194 ( F_123 ( F_124 (
V_24 [ V_319 ] ) ) ) ;
} else if ( V_55 -> V_35 & V_245 ) {
V_267 = V_55 -> V_267 ;
}
V_43 = F_234 ( V_14 , & V_297 . V_338 . V_350 , sizeof( V_297 . V_338 ) , & V_345 ,
V_24 [ V_311 ] ) ;
if ( V_43 < 0 )
goto V_108;
V_43 = - V_62 ;
if ( V_345 . type != V_285 || V_345 . V_92 != V_55 -> V_263 )
goto V_109;
F_235 ( & V_337 , V_351 , V_345 . V_92 ) ;
if ( V_267 > 0 ) {
F_233 ( & V_337 , V_321 ) ;
if ( V_267 != V_55 -> V_267 )
F_233 ( & V_337 , V_318 ) ;
}
if ( V_24 [ V_313 ] != NULL ) {
V_43 = F_234 ( V_14 , & V_195 , sizeof( V_195 ) , & V_346 ,
V_24 [ V_313 ] ) ;
if ( V_43 < 0 )
goto V_109;
V_43 = - V_62 ;
if ( V_55 -> V_265 != V_290 && V_346 . V_92 != V_55 -> V_231 )
goto V_113;
V_301 = F_200 ( V_55 -> V_265 ) ;
F_10 (binding, &set->bindings, list) {
struct V_13 V_352 = {
. V_1 = V_14 -> V_1 ,
. V_3 = V_14 -> V_3 ,
. V_20 = V_14 -> V_20 ,
. V_22 = (struct V_21 * ) V_303 -> V_22 ,
} ;
if ( ! ( V_303 -> V_35 & V_244 ) )
continue;
V_43 = F_201 ( & V_352 , V_301 ,
& V_195 ,
V_346 . type , V_346 . V_92 ) ;
if ( V_43 < 0 )
goto V_113;
}
F_235 ( & V_337 , V_312 , V_346 . V_92 ) ;
}
V_225 = 0 ;
if ( V_24 [ V_327 ] != NULL ) {
V_225 = F_52 ( V_24 [ V_327 ] ) ;
if ( V_225 > 0 )
F_235 ( & V_337 , V_326 ,
V_225 ) ;
}
V_43 = - V_40 ;
V_297 . V_187 = F_226 ( V_55 , & V_337 , V_297 . V_338 . V_350 . V_195 , V_195 . V_195 ,
V_267 , V_33 ) ;
if ( V_297 . V_187 == NULL )
goto V_113;
V_299 = F_199 ( V_55 , V_297 . V_187 ) ;
if ( V_35 )
* F_212 ( V_299 ) = V_35 ;
if ( V_225 > 0 ) {
V_216 = F_216 ( V_299 ) ;
V_216 -> V_92 = V_225 - 1 ;
F_171 ( & V_216 -> V_195 , V_24 [ V_327 ] , V_225 ) ;
}
V_32 = F_224 ( V_14 , V_333 , V_55 ) ;
if ( V_32 == NULL )
goto V_353;
V_299 -> V_60 = F_78 ( V_14 -> V_1 ) | V_354 ;
V_43 = V_55 -> V_38 -> V_355 ( V_14 -> V_1 , V_55 , & V_297 , & V_347 ) ;
if ( V_43 ) {
if ( V_43 == - V_104 ) {
if ( F_210 ( V_299 , V_312 ) &&
F_210 ( V_347 , V_312 ) &&
memcmp ( F_202 ( V_299 ) ,
F_202 ( V_347 ) , V_55 -> V_231 ) != 0 )
V_43 = - V_122 ;
else if ( ! ( V_96 & V_103 ) )
V_43 = 0 ;
}
goto V_356;
}
V_335 ( V_32 ) = V_297 ;
F_30 ( & V_32 -> V_6 , & V_14 -> V_1 -> V_7 . V_42 ) ;
return 0 ;
V_356:
F_22 ( V_32 ) ;
V_353:
F_22 ( V_297 . V_187 ) ;
V_113:
if ( V_24 [ V_313 ] != NULL )
F_229 ( & V_195 , V_346 . type ) ;
V_109:
F_229 ( & V_297 . V_338 . V_350 , V_345 . type ) ;
V_108:
return V_43 ;
}
static int F_236 ( struct V_1 * V_1 , struct V_93 * V_94 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
T_2 V_60 = F_90 ( V_1 ) ;
const struct V_23 * V_155 ;
struct V_54 * V_55 ;
struct V_13 V_14 ;
int V_227 , V_43 = 0 ;
if ( V_24 [ V_334 ] == NULL )
return - V_62 ;
V_43 = F_205 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_60 ) ;
if ( V_43 < 0 )
return V_43 ;
V_55 = F_177 ( V_14 . V_20 , V_24 [ V_332 ] ,
V_60 ) ;
if ( F_80 ( V_55 ) ) {
if ( V_24 [ V_357 ] ) {
V_55 = F_178 ( V_1 ,
V_24 [ V_357 ] ,
V_60 ) ;
}
if ( F_80 ( V_55 ) )
return F_81 ( V_55 ) ;
}
if ( ! F_96 ( & V_55 -> V_118 ) && V_55 -> V_35 & V_288 )
return - V_122 ;
F_169 (attr, nla[NFTA_SET_ELEM_LIST_ELEMENTS], rem) {
if ( V_55 -> V_31 &&
! F_237 ( & V_55 -> V_358 , 1 , V_55 -> V_31 + V_55 -> V_359 ) )
return - V_258 ;
V_43 = F_231 ( & V_14 , V_55 , V_155 , V_18 -> V_96 ) ;
if ( V_43 < 0 ) {
F_238 ( & V_55 -> V_358 ) ;
break;
}
}
return V_43 ;
}
static int F_239 ( struct V_13 * V_14 , struct V_54 * V_55 ,
const struct V_23 * V_155 )
{
struct V_23 * V_24 [ V_343 + 1 ] ;
struct V_336 V_337 ;
struct V_344 V_235 ;
struct V_296 V_297 ;
struct V_298 * V_299 ;
struct V_29 * V_32 ;
T_1 V_35 = 0 ;
void * V_187 ;
int V_43 ;
V_43 = F_119 ( V_24 , V_343 , V_155 ,
V_349 ) ;
if ( V_43 < 0 )
goto V_108;
V_43 = - V_62 ;
if ( V_24 [ V_311 ] == NULL )
goto V_108;
F_232 ( & V_337 ) ;
V_43 = F_230 ( V_55 , V_24 [ V_317 ] , & V_35 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_35 != 0 )
F_233 ( & V_337 , V_316 ) ;
V_43 = F_234 ( V_14 , & V_297 . V_338 . V_350 , sizeof( V_297 . V_338 ) , & V_235 ,
V_24 [ V_311 ] ) ;
if ( V_43 < 0 )
goto V_108;
V_43 = - V_62 ;
if ( V_235 . type != V_285 || V_235 . V_92 != V_55 -> V_263 )
goto V_109;
F_235 ( & V_337 , V_351 , V_235 . V_92 ) ;
V_43 = - V_40 ;
V_297 . V_187 = F_226 ( V_55 , & V_337 , V_297 . V_338 . V_350 . V_195 , NULL , 0 ,
V_33 ) ;
if ( V_297 . V_187 == NULL )
goto V_109;
V_299 = F_199 ( V_55 , V_297 . V_187 ) ;
if ( V_35 )
* F_212 ( V_299 ) = V_35 ;
V_32 = F_224 ( V_14 , V_360 , V_55 ) ;
if ( V_32 == NULL ) {
V_43 = - V_40 ;
goto V_113;
}
V_187 = V_55 -> V_38 -> V_361 ( V_14 -> V_1 , V_55 , & V_297 ) ;
if ( V_187 == NULL ) {
V_43 = - V_51 ;
goto V_353;
}
F_22 ( V_297 . V_187 ) ;
V_297 . V_187 = V_187 ;
V_335 ( V_32 ) = V_297 ;
F_30 ( & V_32 -> V_6 , & V_14 -> V_1 -> V_7 . V_42 ) ;
return 0 ;
V_353:
F_22 ( V_32 ) ;
V_113:
F_22 ( V_297 . V_187 ) ;
V_109:
F_229 ( & V_297 . V_338 . V_350 , V_235 . type ) ;
V_108:
return V_43 ;
}
static int F_240 ( struct V_1 * V_1 , struct V_93 * V_94 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
T_2 V_60 = F_90 ( V_1 ) ;
const struct V_23 * V_155 ;
struct V_54 * V_55 ;
struct V_13 V_14 ;
int V_227 , V_43 = 0 ;
if ( V_24 [ V_334 ] == NULL )
return - V_62 ;
V_43 = F_205 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_60 ) ;
if ( V_43 < 0 )
return V_43 ;
V_55 = F_177 ( V_14 . V_20 , V_24 [ V_332 ] ,
V_60 ) ;
if ( F_80 ( V_55 ) )
return F_81 ( V_55 ) ;
if ( ! F_96 ( & V_55 -> V_118 ) && V_55 -> V_35 & V_288 )
return - V_122 ;
F_169 (attr, nla[NFTA_SET_ELEM_LIST_ELEMENTS], rem) {
V_43 = F_239 ( & V_14 , V_55 , V_155 ) ;
if ( V_43 < 0 )
break;
V_55 -> V_359 ++ ;
}
return V_43 ;
}
void F_241 ( struct V_362 * V_363 )
{
struct V_364 * V_365 ;
unsigned int V_65 ;
V_365 = F_218 ( V_363 , struct V_364 , V_366 . V_363 ) ;
for ( V_65 = 0 ; V_65 < V_365 -> V_366 . V_367 ; V_65 ++ )
F_228 ( V_365 -> V_366 . V_55 , V_365 -> V_368 [ V_65 ] , true ) ;
F_22 ( V_365 ) ;
}
struct V_364 * F_242 ( const struct V_54 * V_55 ,
T_7 V_339 )
{
struct V_364 * V_365 ;
V_365 = F_19 ( sizeof( * V_365 ) , V_339 ) ;
if ( V_365 == NULL )
return V_365 ;
V_365 -> V_366 . V_55 = V_55 ;
return V_365 ;
}
static int F_243 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_25 , T_1 V_27 )
{
struct V_17 * V_18 ;
struct V_69 * V_70 ;
int V_68 = ( V_5 << 8 ) | V_369 ;
V_18 = F_55 ( V_16 , V_25 , V_27 , V_68 , sizeof( struct V_69 ) , 0 ) ;
if ( V_18 == NULL )
goto V_71;
V_70 = F_56 ( V_18 ) ;
V_70 -> V_72 = V_120 ;
V_70 -> V_73 = V_74 ;
V_70 -> V_75 = F_57 ( V_1 -> V_7 . V_76 & 0xffff ) ;
if ( F_59 ( V_16 , V_370 , F_60 ( V_1 -> V_7 . V_76 ) ) )
goto V_71;
F_61 ( V_16 , V_18 ) ;
return 0 ;
V_71:
F_62 ( V_16 , V_18 ) ;
return - V_328 ;
}
static int F_244 ( struct V_1 * V_1 , struct V_15 * V_16 , int V_68 )
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
V_43 = F_243 ( V_95 , V_1 , F_16 ( V_16 ) . V_25 ,
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
static int F_245 ( struct V_1 * V_1 , struct V_93 * V_94 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
struct V_15 * V_95 ;
int V_43 ;
V_95 = F_82 ( V_82 , V_33 ) ;
if ( V_95 == NULL )
return - V_40 ;
V_43 = F_243 ( V_95 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 ) ;
if ( V_43 < 0 )
goto V_43;
return F_83 ( V_94 , V_95 , F_16 ( V_16 ) . V_25 ) ;
V_43:
F_66 ( V_95 ) ;
return V_43 ;
}
static void F_246 ( struct V_29 * V_32 )
{
struct F_25 * V_142 ;
if ( F_140 ( V_32 ) [ 0 ] )
strcpy ( V_32 -> V_14 . V_22 -> V_61 , F_140 ( V_32 ) ) ;
if ( ! ( V_32 -> V_14 . V_22 -> V_35 & V_37 ) )
return;
V_142 = F_25 ( V_32 -> V_14 . V_22 ) ;
F_126 ( V_142 , F_137 ( V_32 ) ) ;
switch ( F_139 ( V_32 ) ) {
case V_179 :
case V_177 :
V_142 -> V_152 = F_139 ( V_32 ) ;
break;
}
}
static void F_247 ( struct V_29 * V_32 )
{
switch ( V_32 -> V_30 ) {
case V_44 :
F_99 ( & V_32 -> V_14 ) ;
break;
case V_47 :
F_131 ( V_32 -> V_14 . V_22 ) ;
break;
case V_53 :
F_164 ( & V_32 -> V_14 , V_52 ( V_32 ) ) ;
break;
case V_59 :
F_195 ( V_56 ( V_32 ) ) ;
break;
case V_360 :
F_228 ( F_225 ( V_32 ) ,
V_335 ( V_32 ) . V_187 , true ) ;
break;
}
F_22 ( V_32 ) ;
}
static int F_248 ( struct V_1 * V_1 , struct V_15 * V_16 )
{
struct V_29 * V_32 , * V_206 ;
struct V_335 * V_371 ;
while ( ++ V_1 -> V_7 . V_76 == 0 ) ;
V_1 -> V_7 . V_372 = F_249 ( V_1 ) ;
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
F_250 ( V_1 , V_32 -> V_14 . V_20 ) ;
}
F_63 ( & V_32 -> V_14 , V_41 ) ;
F_20 ( V_32 ) ;
break;
case V_44 :
F_8 ( & V_32 -> V_14 . V_20 -> V_6 ) ;
F_63 ( & V_32 -> V_14 , V_44 ) ;
break;
case V_46 :
if ( F_138 ( V_32 ) )
F_246 ( V_32 ) ;
else
F_250 ( V_1 , V_32 -> V_14 . V_22 ) ;
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
case V_220 :
F_250 ( V_32 -> V_14 . V_1 , V_52 ( V_32 ) ) ;
F_160 ( & V_32 -> V_14 ,
V_52 ( V_32 ) ,
V_220 ) ;
F_20 ( V_32 ) ;
break;
case V_53 :
F_8 ( & V_52 ( V_32 ) -> V_6 ) ;
F_160 ( & V_32 -> V_14 ,
V_52 ( V_32 ) ,
V_53 ) ;
break;
case V_57 :
F_250 ( V_1 , V_56 ( V_32 ) ) ;
if ( V_56 ( V_32 ) -> V_35 & V_117 &&
! F_96 ( & V_56 ( V_32 ) -> V_118 ) )
V_32 -> V_14 . V_20 -> V_48 -- ;
F_187 ( & V_32 -> V_14 , V_56 ( V_32 ) ,
V_57 , V_33 ) ;
F_20 ( V_32 ) ;
break;
case V_59 :
F_8 ( & V_56 ( V_32 ) -> V_6 ) ;
F_187 ( & V_32 -> V_14 , V_56 ( V_32 ) ,
V_59 , V_33 ) ;
break;
case V_333 :
V_371 = (struct V_335 * ) V_32 -> V_195 ;
V_371 -> V_55 -> V_38 -> V_373 ( V_1 , V_371 -> V_55 , & V_371 -> V_297 ) ;
F_223 ( & V_32 -> V_14 , V_371 -> V_55 ,
& V_371 -> V_297 ,
V_333 , 0 ) ;
F_20 ( V_32 ) ;
break;
case V_360 :
V_371 = (struct V_335 * ) V_32 -> V_195 ;
F_223 ( & V_32 -> V_14 , V_371 -> V_55 ,
& V_371 -> V_297 ,
V_360 , 0 ) ;
V_371 -> V_55 -> V_38 -> remove ( V_371 -> V_55 , & V_371 -> V_297 ) ;
F_238 ( & V_371 -> V_55 -> V_358 ) ;
V_371 -> V_55 -> V_359 -- ;
break;
}
}
F_129 () ;
F_95 (trans, next, &net->nft.commit_list, list) {
F_21 ( & V_32 -> V_6 ) ;
F_247 ( V_32 ) ;
}
F_244 ( V_1 , V_16 , V_369 ) ;
return 0 ;
}
static void F_251 ( struct V_29 * V_32 )
{
switch ( V_32 -> V_30 ) {
case V_41 :
F_99 ( & V_32 -> V_14 ) ;
break;
case V_46 :
F_131 ( V_32 -> V_14 . V_22 ) ;
break;
case V_220 :
F_164 ( & V_32 -> V_14 , V_52 ( V_32 ) ) ;
break;
case V_57 :
F_195 ( V_56 ( V_32 ) ) ;
break;
case V_333 :
F_228 ( F_225 ( V_32 ) ,
V_335 ( V_32 ) . V_187 , true ) ;
break;
}
F_22 ( V_32 ) ;
}
static int F_252 ( struct V_1 * V_1 , struct V_15 * V_16 )
{
struct V_29 * V_32 , * V_206 ;
struct V_335 * V_371 ;
F_253 (trans, next, &net->nft.commit_list,
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
F_250 ( V_32 -> V_14 . V_1 , V_32 -> V_14 . V_20 ) ;
F_20 ( V_32 ) ;
break;
case V_46 :
if ( F_138 ( V_32 ) ) {
F_130 ( F_137 ( V_32 ) ) ;
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
F_250 ( V_32 -> V_14 . V_1 , V_32 -> V_14 . V_22 ) ;
F_20 ( V_32 ) ;
break;
case V_220 :
V_32 -> V_14 . V_22 -> V_48 -- ;
F_8 ( & V_52 ( V_32 ) -> V_6 ) ;
break;
case V_53 :
V_32 -> V_14 . V_22 -> V_48 ++ ;
F_250 ( V_32 -> V_14 . V_1 , V_52 ( V_32 ) ) ;
F_20 ( V_32 ) ;
break;
case V_57 :
V_32 -> V_14 . V_20 -> V_48 -- ;
F_8 ( & V_56 ( V_32 ) -> V_6 ) ;
break;
case V_59 :
V_32 -> V_14 . V_20 -> V_48 ++ ;
F_250 ( V_32 -> V_14 . V_1 , V_56 ( V_32 ) ) ;
F_20 ( V_32 ) ;
break;
case V_333 :
V_371 = (struct V_335 * ) V_32 -> V_195 ;
V_371 -> V_55 -> V_38 -> remove ( V_371 -> V_55 , & V_371 -> V_297 ) ;
F_238 ( & V_371 -> V_55 -> V_358 ) ;
break;
case V_360 :
V_371 = (struct V_335 * ) V_32 -> V_195 ;
V_371 -> V_55 -> V_38 -> V_373 ( V_1 , V_371 -> V_55 , & V_371 -> V_297 ) ;
V_371 -> V_55 -> V_359 -- ;
F_20 ( V_32 ) ;
break;
}
}
F_129 () ;
F_253 (trans, next,
&net->nft.commit_list, list) {
F_21 ( & V_32 -> V_6 ) ;
F_251 ( V_32 ) ;
}
return 0 ;
}
int F_254 ( const struct V_21 * V_22 ,
enum V_374 type )
{
const struct F_25 * V_142 ;
if ( V_22 -> V_35 & V_37 ) {
V_142 = F_25 ( V_22 ) ;
if ( V_142 -> type -> type != type )
return - V_106 ;
}
return 0 ;
}
int F_255 ( const struct V_21 * V_22 ,
unsigned int V_375 )
{
struct F_25 * V_142 ;
if ( V_22 -> V_35 & V_37 ) {
V_142 = F_25 ( V_22 ) ;
if ( ( 1 << V_142 -> V_38 [ 0 ] . V_146 ) & V_375 )
return 0 ;
return - V_106 ;
}
return 0 ;
}
static int F_256 ( const struct V_13 * V_14 ,
const struct V_54 * V_55 ,
const struct V_294 * V_295 ,
const struct V_296 * V_297 )
{
const struct V_298 * V_299 = F_199 ( V_55 , V_297 -> V_187 ) ;
const struct V_348 * V_195 ;
if ( F_210 ( V_299 , V_316 ) &&
* F_212 ( V_299 ) & V_342 )
return 0 ;
V_195 = F_202 ( V_299 ) ;
switch ( V_195 -> V_376 . V_377 ) {
case V_378 :
case V_379 :
return F_257 ( V_14 , V_195 -> V_376 . V_22 ) ;
default:
return 0 ;
}
}
static int F_257 ( const struct V_13 * V_14 ,
const struct V_21 * V_22 )
{
const struct V_49 * V_50 ;
const struct V_192 * V_193 , * V_380 ;
const struct V_54 * V_55 ;
struct V_302 * V_303 ;
struct V_294 V_295 ;
if ( V_14 -> V_22 == V_22 )
return - V_381 ;
F_10 (rule, &chain->rules, list) {
F_158 (expr, last, rule) {
const struct V_348 * V_195 = NULL ;
int V_43 ;
if ( ! V_193 -> V_38 -> V_382 )
continue;
V_43 = V_193 -> V_38 -> V_382 ( V_14 , V_193 , & V_195 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_195 == NULL )
continue;
switch ( V_195 -> V_376 . V_377 ) {
case V_378 :
case V_379 :
V_43 = F_257 ( V_14 ,
V_195 -> V_376 . V_22 ) ;
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
if ( ! ( V_55 -> V_35 & V_244 ) ||
V_55 -> V_265 != V_290 )
continue;
F_10 (binding, &set->bindings, list) {
if ( ! ( V_303 -> V_35 & V_244 ) ||
V_303 -> V_22 != V_22 )
continue;
V_295 . V_60 = F_90 ( V_14 -> V_1 ) ;
V_295 . V_305 = 0 ;
V_295 . V_306 = 0 ;
V_295 . V_43 = 0 ;
V_295 . V_307 = F_256 ;
V_55 -> V_38 -> V_308 ( V_14 , V_55 , & V_295 ) ;
if ( V_295 . V_43 < 0 )
return V_295 . V_43 ;
}
}
return 0 ;
}
int F_258 ( const struct V_23 * V_155 , int V_383 , T_1 * V_384 )
{
T_1 V_350 ;
V_350 = F_42 ( F_43 ( V_155 ) ) ;
if ( V_350 > V_383 )
return - V_385 ;
* V_384 = V_350 ;
return 0 ;
}
unsigned int F_259 ( const struct V_23 * V_155 )
{
unsigned int V_386 ;
V_386 = F_42 ( F_43 ( V_155 ) ) ;
switch ( V_386 ) {
case V_387 ... V_388 :
return V_386 * V_389 / V_390 ;
default:
return V_386 + V_389 / V_390 - V_391 ;
}
}
int F_260 ( struct V_15 * V_16 , unsigned int V_155 , unsigned int V_386 )
{
if ( V_386 % ( V_389 / V_390 ) == 0 )
V_386 = V_386 / ( V_389 / V_390 ) ;
else
V_386 = V_386 - V_389 / V_390 + V_391 ;
return F_59 ( V_16 , V_155 , F_60 ( V_386 ) ) ;
}
int F_261 ( enum V_300 V_386 , unsigned int V_92 )
{
if ( V_386 < V_392 * V_389 / V_390 )
return - V_62 ;
if ( V_92 == 0 )
return - V_62 ;
if ( V_386 * V_390 + V_92 > F_262 ( struct V_393 , V_195 ) )
return - V_385 ;
return 0 ;
}
int F_201 ( const struct V_13 * V_14 ,
enum V_300 V_386 ,
const struct V_348 * V_195 ,
enum V_394 type , unsigned int V_92 )
{
int V_43 ;
switch ( V_386 ) {
case V_387 :
if ( type != V_290 )
return - V_62 ;
if ( V_195 != NULL &&
( V_195 -> V_376 . V_377 == V_379 ||
V_195 -> V_376 . V_377 == V_378 ) ) {
V_43 = F_257 ( V_14 , V_195 -> V_376 . V_22 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_14 -> V_22 -> V_395 + 1 >
V_195 -> V_376 . V_22 -> V_395 ) {
if ( V_14 -> V_22 -> V_395 + 1 == V_396 )
return - V_397 ;
V_195 -> V_376 . V_22 -> V_395 = V_14 -> V_22 -> V_395 + 1 ;
}
}
return 0 ;
default:
if ( V_386 < V_392 * V_389 / V_390 )
return - V_62 ;
if ( V_92 == 0 )
return - V_62 ;
if ( V_386 * V_390 + V_92 >
F_262 ( struct V_393 , V_195 ) )
return - V_385 ;
if ( V_195 != NULL && type != V_285 )
return - V_62 ;
return 0 ;
}
}
static int F_263 ( const struct V_13 * V_14 , struct V_348 * V_195 ,
struct V_344 * V_235 , const struct V_23 * V_24 )
{
T_2 V_60 = F_90 ( V_14 -> V_1 ) ;
struct V_23 * V_156 [ V_398 + 1 ] ;
struct V_21 * V_22 ;
int V_43 ;
V_43 = F_119 ( V_156 , V_398 , V_24 , V_399 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( ! V_156 [ V_400 ] )
return - V_62 ;
V_195 -> V_376 . V_377 = F_42 ( F_43 ( V_156 [ V_400 ] ) ) ;
switch ( V_195 -> V_376 . V_377 ) {
default:
switch ( V_195 -> V_376 . V_377 & V_401 ) {
case V_177 :
case V_179 :
case V_402 :
break;
default:
return - V_62 ;
}
case V_403 :
case V_404 :
case V_405 :
break;
case V_378 :
case V_379 :
if ( ! V_156 [ V_406 ] )
return - V_62 ;
V_22 = F_104 ( V_14 -> V_20 ,
V_156 [ V_406 ] , V_60 ) ;
if ( F_80 ( V_22 ) )
return F_81 ( V_22 ) ;
if ( V_22 -> V_35 & V_37 )
return - V_106 ;
V_22 -> V_48 ++ ;
V_195 -> V_376 . V_22 = V_22 ;
break;
}
V_235 -> V_92 = sizeof( V_195 -> V_376 ) ;
V_235 -> type = V_290 ;
return 0 ;
}
static void F_264 ( const struct V_348 * V_195 )
{
switch ( V_195 -> V_376 . V_377 ) {
case V_378 :
case V_379 :
V_195 -> V_376 . V_22 -> V_48 -- ;
break;
}
}
int F_265 ( struct V_15 * V_16 , int type , const struct V_291 * V_407 )
{
struct V_23 * V_128 ;
V_128 = F_110 ( V_16 , type ) ;
if ( ! V_128 )
goto V_71;
if ( F_59 ( V_16 , V_400 , F_60 ( V_407 -> V_377 ) ) )
goto V_71;
switch ( V_407 -> V_377 ) {
case V_378 :
case V_379 :
if ( F_58 ( V_16 , V_406 ,
V_407 -> V_22 -> V_61 ) )
goto V_71;
}
F_113 ( V_16 , V_128 ) ;
return 0 ;
V_71:
return - 1 ;
}
static int F_266 ( const struct V_13 * V_14 ,
struct V_348 * V_195 , unsigned int V_31 ,
struct V_344 * V_235 , const struct V_23 * V_24 )
{
unsigned int V_92 ;
V_92 = F_52 ( V_24 ) ;
if ( V_92 == 0 )
return - V_62 ;
if ( V_92 > V_31 )
return - V_183 ;
F_171 ( V_195 -> V_195 , V_24 , V_92 ) ;
V_235 -> type = V_285 ;
V_235 -> V_92 = V_92 ;
return 0 ;
}
static int F_267 ( struct V_15 * V_16 , const struct V_348 * V_195 ,
unsigned int V_92 )
{
return F_159 ( V_16 , V_408 , V_92 , V_195 -> V_195 ) ;
}
int F_234 ( const struct V_13 * V_14 ,
struct V_348 * V_195 , unsigned int V_31 ,
struct V_344 * V_235 , const struct V_23 * V_24 )
{
struct V_23 * V_156 [ V_409 + 1 ] ;
int V_43 ;
V_43 = F_119 ( V_156 , V_409 , V_24 , V_410 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_156 [ V_408 ] )
return F_266 ( V_14 , V_195 , V_31 , V_235 ,
V_156 [ V_408 ] ) ;
if ( V_156 [ V_411 ] && V_14 != NULL )
return F_263 ( V_14 , V_195 , V_235 , V_156 [ V_411 ] ) ;
return - V_62 ;
}
void F_229 ( const struct V_348 * V_195 , enum V_394 type )
{
if ( type < V_290 )
return;
switch ( type ) {
case V_290 :
return F_264 ( V_195 ) ;
default:
F_268 ( 1 ) ;
}
}
int F_208 ( struct V_15 * V_16 , int V_155 , const struct V_348 * V_195 ,
enum V_394 type , unsigned int V_92 )
{
struct V_23 * V_128 ;
int V_43 ;
V_128 = F_110 ( V_16 , V_155 ) ;
if ( V_128 == NULL )
return - 1 ;
switch ( type ) {
case V_285 :
V_43 = F_267 ( V_16 , V_195 , V_92 ) ;
break;
case V_290 :
V_43 = F_265 ( V_16 , V_411 , & V_195 -> V_376 ) ;
break;
default:
V_43 = - V_62 ;
F_268 ( 1 ) ;
}
F_113 ( V_16 , V_128 ) ;
return V_43 ;
}
static int T_8 F_269 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_7 . V_8 ) ;
F_2 ( & V_1 -> V_7 . V_42 ) ;
V_1 -> V_7 . V_76 = 1 ;
return 0 ;
}
int F_270 ( struct V_13 * V_14 )
{
struct V_49 * V_50 , * V_412 ;
F_100 ( ! ( V_14 -> V_22 -> V_35 & V_37 ) ) ;
F_26 ( V_14 -> V_1 , V_14 -> V_22 -> V_20 , V_14 -> V_22 ,
V_14 -> V_3 -> V_101 ) ;
F_95 (rule, nr, &ctx->chain->rules, list) {
F_21 ( & V_50 -> V_6 ) ;
V_14 -> V_22 -> V_48 -- ;
F_164 ( V_14 , V_50 ) ;
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
struct V_49 * V_50 , * V_412 ;
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
F_164 ( & V_14 , V_50 ) ;
}
}
F_95 (set, ns, &table->sets, list) {
F_21 ( & V_55 -> V_6 ) ;
V_20 -> V_48 -- ;
F_195 ( V_55 ) ;
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
static int T_9 F_271 ( void )
{
int V_43 ;
V_198 = F_191 ( sizeof( struct V_197 ) * V_229 ,
V_33 ) ;
if ( V_198 == NULL ) {
V_43 = - V_40 ;
goto V_108;
}
V_43 = F_272 () ;
if ( V_43 < 0 )
goto V_109;
V_43 = F_273 ( & V_413 ) ;
if ( V_43 < 0 )
goto V_113;
F_274 ( L_6 ) ;
return F_275 ( & V_414 ) ;
V_113:
F_276 () ;
V_109:
F_22 ( V_198 ) ;
V_108:
return V_43 ;
}
static void T_10 F_277 ( void )
{
F_278 ( & V_414 ) ;
F_279 ( & V_413 ) ;
F_280 () ;
F_276 () ;
F_22 ( V_198 ) ;
}
