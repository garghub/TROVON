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
static int F_23 ( struct V_34 * V_35 ,
unsigned int V_36 )
{
struct V_1 * V_1 = F_24 ( & V_35 -> V_37 ) ;
if ( V_35 -> V_38 & V_39 )
return 0 ;
return F_25 ( V_1 , V_35 -> V_40 , V_36 ) ;
}
static void F_26 ( struct V_34 * V_35 ,
unsigned int V_36 )
{
struct V_1 * V_1 = F_24 ( & V_35 -> V_37 ) ;
if ( V_35 -> V_38 & V_39 )
return;
F_27 ( V_1 , V_35 -> V_40 , V_36 ) ;
}
static int F_28 ( const struct V_19 * V_20 ,
struct V_21 * V_22 ,
unsigned int V_36 )
{
if ( V_20 -> V_38 & V_41 ||
! ( V_22 -> V_38 & V_42 ) )
return 0 ;
return F_23 ( V_34 ( V_22 ) , V_36 ) ;
}
static void F_29 ( const struct V_19 * V_20 ,
struct V_21 * V_22 ,
unsigned int V_36 )
{
if ( V_20 -> V_38 & V_41 ||
! ( V_22 -> V_38 & V_42 ) )
return;
F_26 ( V_34 ( V_22 ) , V_36 ) ;
}
static int F_30 ( struct V_13 * V_14 , int V_30 )
{
struct V_29 * V_32 ;
V_32 = F_18 ( V_14 , V_30 , sizeof( struct V_43 ) ) ;
if ( V_32 == NULL )
return - V_44 ;
if ( V_30 == V_45 )
V_14 -> V_20 -> V_38 |= V_46 ;
F_31 ( & V_32 -> V_6 , & V_14 -> V_1 -> V_7 . V_47 ) ;
return 0 ;
}
static int F_32 ( struct V_13 * V_14 )
{
int V_48 ;
V_48 = F_30 ( V_14 , V_49 ) ;
if ( V_48 < 0 )
return V_48 ;
F_8 ( & V_14 -> V_20 -> V_6 ) ;
return V_48 ;
}
static int F_33 ( struct V_13 * V_14 , int V_30 )
{
struct V_29 * V_32 ;
V_32 = F_18 ( V_14 , V_30 , sizeof( struct V_50 ) ) ;
if ( V_32 == NULL )
return - V_44 ;
if ( V_30 == V_51 )
V_14 -> V_22 -> V_38 |= V_52 ;
F_31 ( & V_32 -> V_6 , & V_14 -> V_1 -> V_7 . V_47 ) ;
return 0 ;
}
static int F_34 ( struct V_13 * V_14 )
{
int V_48 ;
V_48 = F_33 ( V_14 , V_53 ) ;
if ( V_48 < 0 )
return V_48 ;
V_14 -> V_20 -> V_54 -- ;
F_8 ( & V_14 -> V_22 -> V_6 ) ;
return V_48 ;
}
static inline bool
F_35 ( struct V_1 * V_1 , const struct V_55 * V_56 )
{
return ( V_56 -> V_57 & F_36 ( V_1 ) ) == 0 ;
}
static inline int
F_37 ( struct V_1 * V_1 , const struct V_55 * V_56 )
{
return ( V_56 -> V_57 & F_38 ( V_1 ) ) == 0 ;
}
static inline void
F_39 ( struct V_1 * V_1 , struct V_55 * V_56 )
{
V_56 -> V_57 = F_36 ( V_1 ) ;
}
static inline void
F_40 ( struct V_1 * V_1 , struct V_55 * V_56 )
{
V_56 -> V_57 = F_38 ( V_1 ) ;
}
static inline void F_41 ( struct V_1 * V_1 , struct V_55 * V_56 )
{
V_56 -> V_57 &= ~ F_38 ( V_1 ) ;
}
static int
F_42 ( struct V_13 * V_14 , struct V_55 * V_56 )
{
if ( F_37 ( V_14 -> V_1 , V_56 ) ) {
F_40 ( V_14 -> V_1 , V_56 ) ;
V_14 -> V_22 -> V_54 -- ;
return 0 ;
}
return - V_58 ;
}
static struct V_29 * F_43 ( struct V_13 * V_14 , int V_30 ,
struct V_55 * V_56 )
{
struct V_29 * V_32 ;
V_32 = F_18 ( V_14 , V_30 , sizeof( struct V_59 ) ) ;
if ( V_32 == NULL )
return NULL ;
V_59 ( V_32 ) = V_56 ;
F_31 ( & V_32 -> V_6 , & V_14 -> V_1 -> V_7 . V_47 ) ;
return V_32 ;
}
static int F_44 ( struct V_13 * V_14 , struct V_55 * V_56 )
{
struct V_29 * V_32 ;
int V_48 ;
V_32 = F_43 ( V_14 , V_60 , V_56 ) ;
if ( V_32 == NULL )
return - V_44 ;
V_48 = F_42 ( V_14 , V_56 ) ;
if ( V_48 < 0 ) {
F_20 ( V_32 ) ;
return V_48 ;
}
return 0 ;
}
static int F_45 ( struct V_13 * V_14 )
{
struct V_55 * V_56 ;
int V_48 ;
F_10 (rule, &ctx->chain->rules, list) {
V_48 = F_44 ( V_14 , V_56 ) ;
if ( V_48 < 0 )
return V_48 ;
}
return 0 ;
}
static int F_46 ( struct V_13 * V_14 , int V_30 ,
struct V_61 * V_62 )
{
struct V_29 * V_32 ;
V_32 = F_18 ( V_14 , V_30 , sizeof( struct V_63 ) ) ;
if ( V_32 == NULL )
return - V_44 ;
if ( V_30 == V_64 && V_14 -> V_24 [ V_65 ] != NULL ) {
F_47 ( V_32 ) =
F_48 ( F_49 ( V_14 -> V_24 [ V_65 ] ) ) ;
V_62 -> V_38 |= V_66 ;
}
V_63 ( V_32 ) = V_62 ;
F_31 ( & V_32 -> V_6 , & V_14 -> V_1 -> V_7 . V_47 ) ;
return 0 ;
}
static int F_50 ( struct V_13 * V_14 , struct V_61 * V_62 )
{
int V_48 ;
V_48 = F_46 ( V_14 , V_67 , V_62 ) ;
if ( V_48 < 0 )
return V_48 ;
F_8 ( & V_62 -> V_6 ) ;
V_14 -> V_20 -> V_54 -- ;
return V_48 ;
}
static struct V_19 * F_51 ( const struct V_2 * V_3 ,
const struct V_23 * V_24 )
{
struct V_19 * V_20 ;
F_10 (table, &afi->tables, list) {
if ( ! F_52 ( V_24 , V_20 -> V_68 ) )
return V_20 ;
}
return NULL ;
}
static struct V_19 * F_53 ( const struct V_2 * V_3 ,
const struct V_23 * V_24 )
{
struct V_19 * V_20 ;
if ( V_24 == NULL )
return F_14 ( - V_69 ) ;
V_20 = F_51 ( V_3 , V_24 ) ;
if ( V_20 != NULL )
return V_20 ;
return F_14 ( - V_58 ) ;
}
static inline T_2 F_54 ( struct V_19 * V_20 )
{
return ++ V_20 -> V_70 ;
}
static const struct V_71 *
F_55 ( int V_9 , const struct V_23 * V_24 )
{
int V_72 ;
for ( V_72 = 0 ; V_72 < V_73 ; V_72 ++ ) {
if ( V_74 [ V_9 ] [ V_72 ] != NULL &&
! F_52 ( V_24 , V_74 [ V_9 ] [ V_72 ] -> V_68 ) )
return V_74 [ V_9 ] [ V_72 ] ;
}
return NULL ;
}
static const struct V_71 *
F_56 ( const struct V_2 * V_3 ,
const struct V_23 * V_24 ,
bool V_10 )
{
const struct V_71 * type ;
type = F_55 ( V_3 -> V_9 , V_24 ) ;
if ( type != NULL )
return type ;
#ifdef F_12
if ( V_10 ) {
F_5 ( V_5 ) ;
F_13 ( L_2 , V_3 -> V_9 ,
F_57 ( V_24 ) , ( const char * ) F_58 ( V_24 ) ) ;
F_3 ( V_5 ) ;
type = F_55 ( V_3 -> V_9 , V_24 ) ;
if ( type != NULL )
return F_14 ( - V_11 ) ;
}
#endif
return F_14 ( - V_58 ) ;
}
static int F_59 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_25 , T_1 V_27 , int V_75 , T_1 V_38 ,
int V_9 , const struct V_19 * V_20 )
{
struct V_17 * V_18 ;
struct V_76 * V_77 ;
V_75 |= V_5 << 8 ;
V_18 = F_60 ( V_16 , V_25 , V_27 , V_75 , sizeof( struct V_76 ) , V_38 ) ;
if ( V_18 == NULL )
goto V_78;
V_77 = F_61 ( V_18 ) ;
V_77 -> V_79 = V_9 ;
V_77 -> V_80 = V_81 ;
V_77 -> V_82 = F_62 ( V_1 -> V_7 . V_83 & 0xffff ) ;
if ( F_63 ( V_16 , V_84 , V_20 -> V_68 ) ||
F_64 ( V_16 , V_85 , F_65 ( V_20 -> V_38 ) ) ||
F_64 ( V_16 , V_86 , F_65 ( V_20 -> V_54 ) ) )
goto V_78;
F_66 ( V_16 , V_18 ) ;
return 0 ;
V_78:
F_67 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_68 ( const struct V_13 * V_14 , int V_75 )
{
struct V_15 * V_16 ;
int V_48 ;
if ( ! V_14 -> V_26 &&
! F_69 ( V_14 -> V_1 , V_87 ) )
return 0 ;
V_48 = - V_88 ;
V_16 = F_70 ( V_89 , V_33 ) ;
if ( V_16 == NULL )
goto V_48;
V_48 = F_59 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_14 -> V_27 ,
V_75 , 0 , V_14 -> V_3 -> V_9 , V_14 -> V_20 ) ;
if ( V_48 < 0 ) {
F_71 ( V_16 ) ;
goto V_48;
}
V_48 = F_72 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_87 ,
V_14 -> V_26 , V_33 ) ;
V_48:
if ( V_48 < 0 ) {
F_73 ( V_14 -> V_1 , V_14 -> V_25 , V_87 ,
V_48 ) ;
}
return V_48 ;
}
static int F_74 ( struct V_15 * V_16 ,
struct V_90 * V_91 )
{
const struct V_76 * V_77 = F_61 ( V_91 -> V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
unsigned int V_92 = 0 , V_93 = V_91 -> args [ 0 ] ;
struct V_1 * V_1 = F_75 ( V_16 -> V_94 ) ;
int V_9 = V_77 -> V_79 ;
F_76 () ;
V_91 -> V_27 = V_1 -> V_7 . V_83 ;
F_77 (afi, &net->nft.af_info, list) {
if ( V_9 != V_95 && V_9 != V_3 -> V_9 )
continue;
F_77 (table, &afi->tables, list) {
if ( V_92 < V_93 )
goto V_96;
if ( V_92 > V_93 )
memset ( & V_91 -> args [ 1 ] , 0 ,
sizeof( V_91 -> args ) - sizeof( V_91 -> args [ 0 ] ) ) ;
if ( F_59 ( V_16 , V_1 ,
F_16 ( V_91 -> V_16 ) . V_25 ,
V_91 -> V_18 -> V_28 ,
V_45 ,
V_97 ,
V_3 -> V_9 , V_20 ) < 0 )
goto V_98;
F_78 ( V_91 , F_79 ( V_16 ) ) ;
V_96:
V_92 ++ ;
}
}
V_98:
F_80 () ;
V_91 -> args [ 0 ] = V_92 ;
return V_16 -> V_99 ;
}
static int F_81 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_61 ( V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
struct V_15 * V_102 ;
int V_9 = V_77 -> V_79 ;
int V_48 ;
if ( V_18 -> V_103 & V_104 ) {
struct V_105 V_106 = {
. V_107 = F_74 ,
} ;
return F_82 ( V_101 , V_16 , V_18 , & V_106 ) ;
}
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_83 ( V_3 ) )
return F_84 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_84 ] ) ;
if ( F_83 ( V_20 ) )
return F_84 ( V_20 ) ;
if ( V_20 -> V_38 & V_46 )
return - V_58 ;
V_102 = F_85 ( V_89 , V_33 ) ;
if ( ! V_102 )
return - V_44 ;
V_48 = F_59 ( V_102 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 , V_45 , 0 ,
V_9 , V_20 ) ;
if ( V_48 < 0 )
goto V_48;
return F_86 ( V_101 , V_102 , F_16 ( V_16 ) . V_25 ) ;
V_48:
F_71 ( V_102 ) ;
return V_48 ;
}
static int F_87 ( const struct V_2 * V_3 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 ;
int V_48 , V_72 = 0 ;
F_10 (chain, &table->chains, list) {
if ( ! ( V_22 -> V_38 & V_42 ) )
continue;
V_48 = F_23 ( V_34 ( V_22 ) , V_3 -> V_108 ) ;
if ( V_48 < 0 )
goto V_48;
V_72 ++ ;
}
return 0 ;
V_48:
F_10 (chain, &table->chains, list) {
if ( ! ( V_22 -> V_38 & V_42 ) )
continue;
if ( V_72 -- <= 0 )
break;
F_26 ( V_34 ( V_22 ) , V_3 -> V_108 ) ;
}
return V_48 ;
}
static void F_88 ( const struct V_2 * V_3 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 ;
F_10 (chain, &table->chains, list) {
if ( V_22 -> V_38 & V_42 )
F_26 ( V_34 ( V_22 ) ,
V_3 -> V_108 ) ;
}
}
static int F_89 ( struct V_13 * V_14 )
{
struct V_29 * V_32 ;
T_1 V_38 ;
int V_109 = 0 ;
if ( ! V_14 -> V_24 [ V_85 ] )
return 0 ;
V_38 = F_48 ( F_49 ( V_14 -> V_24 [ V_85 ] ) ) ;
if ( V_38 & ~ V_41 )
return - V_69 ;
if ( V_38 == V_14 -> V_20 -> V_38 )
return 0 ;
V_32 = F_18 ( V_14 , V_45 ,
sizeof( struct V_43 ) ) ;
if ( V_32 == NULL )
return - V_44 ;
if ( ( V_38 & V_41 ) &&
! ( V_14 -> V_20 -> V_38 & V_41 ) ) {
F_90 ( V_32 ) = false ;
} else if ( ! ( V_38 & V_41 ) &&
V_14 -> V_20 -> V_38 & V_41 ) {
V_109 = F_87 ( V_14 -> V_3 , V_14 -> V_20 ) ;
if ( V_109 >= 0 ) {
V_14 -> V_20 -> V_38 &= ~ V_41 ;
F_90 ( V_32 ) = true ;
}
}
if ( V_109 < 0 )
goto V_48;
F_91 ( V_32 ) = true ;
F_31 ( & V_32 -> V_6 , & V_14 -> V_1 -> V_7 . V_47 ) ;
return 0 ;
V_48:
F_20 ( V_32 ) ;
return V_109 ;
}
static int F_92 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_61 ( V_18 ) ;
const struct V_23 * V_68 ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
int V_9 = V_77 -> V_79 ;
T_1 V_38 = 0 ;
struct V_13 V_14 ;
int V_48 ;
V_3 = F_11 ( V_1 , V_9 , true ) ;
if ( F_83 ( V_3 ) )
return F_84 ( V_3 ) ;
V_68 = V_24 [ V_84 ] ;
V_20 = F_53 ( V_3 , V_68 ) ;
if ( F_83 ( V_20 ) ) {
if ( F_84 ( V_20 ) != - V_58 )
return F_84 ( V_20 ) ;
V_20 = NULL ;
}
if ( V_20 != NULL ) {
if ( V_20 -> V_38 & V_46 )
return - V_58 ;
if ( V_18 -> V_103 & V_110 )
return - V_111 ;
if ( V_18 -> V_103 & V_112 )
return - V_113 ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return F_89 ( & V_14 ) ;
}
if ( V_24 [ V_85 ] ) {
V_38 = F_48 ( F_49 ( V_24 [ V_85 ] ) ) ;
if ( V_38 & ~ V_41 )
return - V_69 ;
}
V_48 = - V_12 ;
if ( ! F_93 ( V_3 -> V_114 ) )
goto V_115;
V_48 = - V_44 ;
V_20 = F_19 ( sizeof( * V_20 ) , V_33 ) ;
if ( V_20 == NULL )
goto V_116;
F_94 ( V_20 -> V_68 , V_68 , V_117 ) ;
F_2 ( & V_20 -> V_118 ) ;
F_2 ( & V_20 -> V_119 ) ;
V_20 -> V_38 = V_38 ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
V_48 = F_30 ( & V_14 , V_45 ) ;
if ( V_48 < 0 )
goto V_120;
F_4 ( & V_20 -> V_6 , & V_3 -> V_4 ) ;
return 0 ;
V_120:
F_22 ( V_20 ) ;
V_116:
F_95 ( V_3 -> V_114 ) ;
V_115:
return V_48 ;
}
static int F_96 ( struct V_13 * V_14 )
{
int V_48 ;
struct V_21 * V_22 , * V_121 ;
struct V_61 * V_62 , * V_122 ;
F_10 (chain, &ctx->table->chains, list) {
V_14 -> V_22 = V_22 ;
V_48 = F_45 ( V_14 ) ;
if ( V_48 < 0 )
goto V_123;
}
F_97 (set, ns, &ctx->table->sets, list) {
if ( V_62 -> V_38 & V_124 &&
! F_98 ( & V_62 -> V_125 ) )
continue;
V_48 = F_50 ( V_14 , V_62 ) ;
if ( V_48 < 0 )
goto V_123;
}
F_97 (chain, nc, &ctx->table->chains, list) {
V_14 -> V_22 = V_22 ;
V_48 = F_34 ( V_14 ) ;
if ( V_48 < 0 )
goto V_123;
}
V_48 = F_32 ( V_14 ) ;
V_123:
return V_48 ;
}
static int F_99 ( struct V_13 * V_14 , int V_9 )
{
struct V_2 * V_3 ;
struct V_19 * V_20 , * V_126 ;
const struct V_23 * const * V_24 = V_14 -> V_24 ;
int V_48 = 0 ;
F_10 (afi, &ctx->net->nft.af_info, list) {
if ( V_9 != V_127 && V_3 -> V_9 != V_9 )
continue;
V_14 -> V_3 = V_3 ;
F_97 (table, nt, &afi->tables, list) {
if ( V_24 [ V_84 ] &&
F_52 ( V_24 [ V_84 ] , V_20 -> V_68 ) != 0 )
continue;
V_14 -> V_20 = V_20 ;
V_48 = F_96 ( V_14 ) ;
if ( V_48 < 0 )
goto V_123;
}
}
V_123:
return V_48 ;
}
static int F_100 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_61 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
int V_9 = V_77 -> V_79 ;
struct V_13 V_14 ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , NULL , NULL , NULL , V_24 ) ;
if ( V_9 == V_127 || V_24 [ V_84 ] == NULL )
return F_99 ( & V_14 , V_9 ) ;
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_83 ( V_3 ) )
return F_84 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_84 ] ) ;
if ( F_83 ( V_20 ) )
return F_84 ( V_20 ) ;
V_14 . V_3 = V_3 ;
V_14 . V_20 = V_20 ;
return F_96 ( & V_14 ) ;
}
static void F_101 ( struct V_13 * V_14 )
{
F_102 ( V_14 -> V_20 -> V_54 > 0 ) ;
F_22 ( V_14 -> V_20 ) ;
F_95 ( V_14 -> V_3 -> V_114 ) ;
}
int F_103 ( const struct V_71 * V_128 )
{
int V_48 = 0 ;
F_3 ( V_5 ) ;
if ( V_74 [ V_128 -> V_9 ] [ V_128 -> type ] != NULL ) {
V_48 = - V_129 ;
goto V_123;
}
V_74 [ V_128 -> V_9 ] [ V_128 -> type ] = V_128 ;
V_123:
F_5 ( V_5 ) ;
return V_48 ;
}
void F_104 ( const struct V_71 * V_128 )
{
F_3 ( V_5 ) ;
V_74 [ V_128 -> V_9 ] [ V_128 -> type ] = NULL ;
F_5 ( V_5 ) ;
}
static struct V_21 *
F_105 ( const struct V_19 * V_20 , T_2 V_130 )
{
struct V_21 * V_22 ;
F_10 (chain, &table->chains, list) {
if ( V_22 -> V_130 == V_130 )
return V_22 ;
}
return F_14 ( - V_58 ) ;
}
static struct V_21 * F_106 ( const struct V_19 * V_20 ,
const struct V_23 * V_24 )
{
struct V_21 * V_22 ;
if ( V_24 == NULL )
return F_14 ( - V_69 ) ;
F_10 (chain, &table->chains, list) {
if ( ! F_52 ( V_24 , V_22 -> V_68 ) )
return V_22 ;
}
return F_14 ( - V_58 ) ;
}
static int F_107 ( struct V_15 * V_16 , struct V_131 T_3 * V_132 )
{
struct V_131 * V_133 , V_134 ;
struct V_23 * V_135 ;
unsigned int V_27 ;
T_2 V_136 , V_137 ;
int V_138 ;
memset ( & V_134 , 0 , sizeof( V_134 ) ) ;
F_108 (cpu) {
V_133 = F_109 ( V_132 , V_138 ) ;
do {
V_27 = F_110 ( & V_133 -> V_139 ) ;
V_136 = V_133 -> V_136 ;
V_137 = V_133 -> V_137 ;
} while ( F_111 ( & V_133 -> V_139 , V_27 ) );
V_134 . V_136 += V_136 ;
V_134 . V_137 += V_137 ;
}
V_135 = F_112 ( V_16 , V_140 ) ;
if ( V_135 == NULL )
goto V_78;
if ( F_113 ( V_16 , V_141 , F_114 ( V_134 . V_136 ) ) ||
F_113 ( V_16 , V_142 , F_114 ( V_134 . V_137 ) ) )
goto V_78;
F_115 ( V_16 , V_135 ) ;
return 0 ;
V_78:
return - V_143 ;
}
static int F_116 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_25 , T_1 V_27 , int V_75 , T_1 V_38 ,
int V_9 , const struct V_19 * V_20 ,
const struct V_21 * V_22 )
{
struct V_17 * V_18 ;
struct V_76 * V_77 ;
V_75 |= V_5 << 8 ;
V_18 = F_60 ( V_16 , V_25 , V_27 , V_75 , sizeof( struct V_76 ) , V_38 ) ;
if ( V_18 == NULL )
goto V_78;
V_77 = F_61 ( V_18 ) ;
V_77 -> V_79 = V_9 ;
V_77 -> V_80 = V_81 ;
V_77 -> V_82 = F_62 ( V_1 -> V_7 . V_83 & 0xffff ) ;
if ( F_63 ( V_16 , V_144 , V_20 -> V_68 ) )
goto V_78;
if ( F_113 ( V_16 , V_145 , F_114 ( V_22 -> V_130 ) ) )
goto V_78;
if ( F_63 ( V_16 , V_146 , V_22 -> V_68 ) )
goto V_78;
if ( V_22 -> V_38 & V_42 ) {
const struct V_34 * V_35 = V_34 ( V_22 ) ;
const struct V_147 * V_40 = & V_35 -> V_40 [ 0 ] ;
struct V_23 * V_135 ;
V_135 = F_112 ( V_16 , V_148 ) ;
if ( V_135 == NULL )
goto V_78;
if ( F_64 ( V_16 , V_149 , F_65 ( V_40 -> V_150 ) ) )
goto V_78;
if ( F_64 ( V_16 , V_151 , F_65 ( V_40 -> V_152 ) ) )
goto V_78;
if ( V_35 -> V_153 [ 0 ] &&
F_63 ( V_16 , V_154 , V_35 -> V_153 ) )
goto V_78;
F_115 ( V_16 , V_135 ) ;
if ( F_64 ( V_16 , V_155 ,
F_65 ( V_35 -> V_156 ) ) )
goto V_78;
if ( F_63 ( V_16 , V_157 , V_35 -> type -> V_68 ) )
goto V_78;
if ( F_107 ( V_16 , V_34 ( V_22 ) -> V_132 ) )
goto V_78;
}
if ( F_64 ( V_16 , V_158 , F_65 ( V_22 -> V_54 ) ) )
goto V_78;
F_66 ( V_16 , V_18 ) ;
return 0 ;
V_78:
F_67 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_117 ( const struct V_13 * V_14 , int V_75 )
{
struct V_15 * V_16 ;
int V_48 ;
if ( ! V_14 -> V_26 &&
! F_69 ( V_14 -> V_1 , V_87 ) )
return 0 ;
V_48 = - V_88 ;
V_16 = F_70 ( V_89 , V_33 ) ;
if ( V_16 == NULL )
goto V_48;
V_48 = F_116 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_14 -> V_27 ,
V_75 , 0 , V_14 -> V_3 -> V_9 , V_14 -> V_20 ,
V_14 -> V_22 ) ;
if ( V_48 < 0 ) {
F_71 ( V_16 ) ;
goto V_48;
}
V_48 = F_72 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_87 ,
V_14 -> V_26 , V_33 ) ;
V_48:
if ( V_48 < 0 ) {
F_73 ( V_14 -> V_1 , V_14 -> V_25 , V_87 ,
V_48 ) ;
}
return V_48 ;
}
static int F_118 ( struct V_15 * V_16 ,
struct V_90 * V_91 )
{
const struct V_76 * V_77 = F_61 ( V_91 -> V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
unsigned int V_92 = 0 , V_93 = V_91 -> args [ 0 ] ;
struct V_1 * V_1 = F_75 ( V_16 -> V_94 ) ;
int V_9 = V_77 -> V_79 ;
F_76 () ;
V_91 -> V_27 = V_1 -> V_7 . V_83 ;
F_77 (afi, &net->nft.af_info, list) {
if ( V_9 != V_95 && V_9 != V_3 -> V_9 )
continue;
F_77 (table, &afi->tables, list) {
F_77 (chain, &table->chains, list) {
if ( V_92 < V_93 )
goto V_96;
if ( V_92 > V_93 )
memset ( & V_91 -> args [ 1 ] , 0 ,
sizeof( V_91 -> args ) - sizeof( V_91 -> args [ 0 ] ) ) ;
if ( F_116 ( V_16 , V_1 ,
F_16 ( V_91 -> V_16 ) . V_25 ,
V_91 -> V_18 -> V_28 ,
V_51 ,
V_97 ,
V_3 -> V_9 , V_20 , V_22 ) < 0 )
goto V_98;
F_78 ( V_91 , F_79 ( V_16 ) ) ;
V_96:
V_92 ++ ;
}
}
}
V_98:
F_80 () ;
V_91 -> args [ 0 ] = V_92 ;
return V_16 -> V_99 ;
}
static int F_119 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_61 ( V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
struct V_15 * V_102 ;
int V_9 = V_77 -> V_79 ;
int V_48 ;
if ( V_18 -> V_103 & V_104 ) {
struct V_105 V_106 = {
. V_107 = F_118 ,
} ;
return F_82 ( V_101 , V_16 , V_18 , & V_106 ) ;
}
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_83 ( V_3 ) )
return F_84 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_144 ] ) ;
if ( F_83 ( V_20 ) )
return F_84 ( V_20 ) ;
if ( V_20 -> V_38 & V_46 )
return - V_58 ;
V_22 = F_106 ( V_20 , V_24 [ V_146 ] ) ;
if ( F_83 ( V_22 ) )
return F_84 ( V_22 ) ;
if ( V_22 -> V_38 & V_52 )
return - V_58 ;
V_102 = F_85 ( V_89 , V_33 ) ;
if ( ! V_102 )
return - V_44 ;
V_48 = F_116 ( V_102 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 , V_51 , 0 ,
V_9 , V_20 , V_22 ) ;
if ( V_48 < 0 )
goto V_48;
return F_86 ( V_101 , V_102 , F_16 ( V_16 ) . V_25 ) ;
V_48:
F_71 ( V_102 ) ;
return V_48 ;
}
static struct V_131 T_3 * F_120 ( const struct V_23 * V_159 )
{
struct V_23 * V_160 [ V_161 + 1 ] ;
struct V_131 T_3 * V_162 ;
struct V_131 * V_132 ;
int V_48 ;
V_48 = F_121 ( V_160 , V_161 , V_159 , V_163 ) ;
if ( V_48 < 0 )
return F_14 ( V_48 ) ;
if ( ! V_160 [ V_142 ] || ! V_160 [ V_141 ] )
return F_14 ( - V_69 ) ;
V_162 = F_122 ( struct V_131 ) ;
if ( V_162 == NULL )
return F_14 ( - V_44 ) ;
F_123 () ;
V_132 = F_124 ( V_162 ) ;
V_132 -> V_137 = F_125 ( F_126 ( V_160 [ V_142 ] ) ) ;
V_132 -> V_136 = F_125 ( F_126 ( V_160 [ V_141 ] ) ) ;
F_127 () ;
return V_162 ;
}
static void F_128 ( struct V_34 * V_22 ,
struct V_131 T_3 * V_162 )
{
if ( V_162 == NULL )
return;
if ( V_22 -> V_132 ) {
struct V_131 T_3 * V_164 =
F_129 ( V_22 -> V_132 ) ;
F_130 ( V_22 -> V_132 , V_162 ) ;
F_131 () ;
F_132 ( V_164 ) ;
} else
F_130 ( V_22 -> V_132 , V_162 ) ;
}
static void F_133 ( struct V_21 * V_22 )
{
F_102 ( V_22 -> V_54 > 0 ) ;
if ( V_22 -> V_38 & V_42 ) {
struct V_34 * V_35 = V_34 ( V_22 ) ;
F_95 ( V_35 -> type -> V_114 ) ;
F_132 ( V_35 -> V_132 ) ;
if ( V_35 -> V_40 [ 0 ] . V_165 != NULL )
F_134 ( V_35 -> V_40 [ 0 ] . V_165 ) ;
F_22 ( V_35 ) ;
} else {
F_22 ( V_22 ) ;
}
}
static int F_135 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_61 ( V_18 ) ;
const struct V_23 * V_166 ( V_68 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_34 * V_35 = NULL ;
struct V_23 * V_167 [ V_168 + 1 ] ;
int V_9 = V_77 -> V_79 ;
struct V_169 * V_165 = NULL ;
T_4 V_156 = V_170 ;
T_2 V_130 = 0 ;
unsigned int V_72 ;
struct V_131 T_3 * V_132 ;
int V_48 ;
bool V_171 ;
struct V_13 V_14 ;
V_171 = V_18 -> V_103 & V_172 ? true : false ;
V_3 = F_11 ( V_1 , V_9 , true ) ;
if ( F_83 ( V_3 ) )
return F_84 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_144 ] ) ;
if ( F_83 ( V_20 ) )
return F_84 ( V_20 ) ;
V_22 = NULL ;
V_68 = V_24 [ V_146 ] ;
if ( V_24 [ V_145 ] ) {
V_130 = F_125 ( F_126 ( V_24 [ V_145 ] ) ) ;
V_22 = F_105 ( V_20 , V_130 ) ;
if ( F_83 ( V_22 ) )
return F_84 ( V_22 ) ;
} else {
V_22 = F_106 ( V_20 , V_68 ) ;
if ( F_83 ( V_22 ) ) {
if ( F_84 ( V_22 ) != - V_58 )
return F_84 ( V_22 ) ;
V_22 = NULL ;
}
}
if ( V_24 [ V_155 ] ) {
if ( ( V_22 != NULL &&
! ( V_22 -> V_38 & V_42 ) ) )
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
return - V_69 ;
}
}
if ( V_22 != NULL ) {
struct V_131 * V_132 = NULL ;
struct V_29 * V_32 ;
if ( V_22 -> V_38 & V_52 )
return - V_58 ;
if ( V_18 -> V_103 & V_110 )
return - V_111 ;
if ( V_18 -> V_103 & V_112 )
return - V_113 ;
if ( V_24 [ V_145 ] && V_68 &&
! F_83 ( F_106 ( V_20 , V_24 [ V_146 ] ) ) )
return - V_111 ;
if ( V_24 [ V_140 ] ) {
if ( ! ( V_22 -> V_38 & V_42 ) )
return - V_113 ;
V_132 = F_120 ( V_24 [ V_140 ] ) ;
if ( F_83 ( V_132 ) )
return F_84 ( V_132 ) ;
}
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_32 = F_18 ( & V_14 , V_51 ,
sizeof( struct V_50 ) ) ;
if ( V_32 == NULL ) {
F_132 ( V_132 ) ;
return - V_44 ;
}
F_136 ( V_32 ) = V_132 ;
F_137 ( V_32 ) = true ;
if ( V_24 [ V_155 ] )
F_138 ( V_32 ) = V_156 ;
else
F_138 ( V_32 ) = - 1 ;
if ( V_24 [ V_145 ] && V_68 ) {
F_94 ( F_139 ( V_32 ) , V_68 ,
V_174 ) ;
}
F_31 ( & V_32 -> V_6 , & V_1 -> V_7 . V_47 ) ;
return 0 ;
}
if ( V_20 -> V_54 == V_175 )
return - V_176 ;
if ( V_24 [ V_148 ] ) {
const struct V_71 * type ;
struct V_147 * V_40 ;
T_5 * V_177 ;
T_1 V_150 , V_152 ;
type = V_74 [ V_9 ] [ V_178 ] ;
if ( V_24 [ V_157 ] ) {
type = F_56 ( V_3 ,
V_24 [ V_157 ] ,
V_171 ) ;
if ( F_83 ( type ) )
return F_84 ( type ) ;
}
V_48 = F_121 ( V_167 , V_168 , V_24 [ V_148 ] ,
V_179 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_167 [ V_149 ] == NULL ||
V_167 [ V_151 ] == NULL )
return - V_69 ;
V_150 = F_48 ( F_49 ( V_167 [ V_149 ] ) ) ;
if ( V_150 >= V_3 -> V_180 )
return - V_69 ;
V_152 = F_48 ( F_49 ( V_167 [ V_151 ] ) ) ;
if ( ! ( type -> V_181 & ( 1 << V_150 ) ) )
return - V_113 ;
if ( ! F_93 ( type -> V_114 ) )
return - V_58 ;
V_177 = type -> V_182 [ V_150 ] ;
if ( V_3 -> V_38 & V_183 ) {
char V_184 [ V_185 ] ;
if ( ! V_167 [ V_154 ] ) {
F_95 ( type -> V_114 ) ;
return - V_113 ;
}
F_94 ( V_184 , V_167 [ V_154 ] , V_185 ) ;
V_165 = F_140 ( V_1 , V_184 ) ;
if ( ! V_165 ) {
F_95 ( type -> V_114 ) ;
return - V_58 ;
}
} else if ( V_167 [ V_154 ] ) {
F_95 ( type -> V_114 ) ;
return - V_113 ;
}
V_35 = F_19 ( sizeof( * V_35 ) , V_33 ) ;
if ( V_35 == NULL ) {
F_95 ( type -> V_114 ) ;
if ( V_165 != NULL )
F_134 ( V_165 ) ;
return - V_44 ;
}
if ( V_165 != NULL )
strncpy ( V_35 -> V_153 , V_165 -> V_68 , V_185 ) ;
if ( V_24 [ V_140 ] ) {
V_132 = F_120 ( V_24 [ V_140 ] ) ;
if ( F_83 ( V_132 ) ) {
F_95 ( type -> V_114 ) ;
F_22 ( V_35 ) ;
if ( V_165 != NULL )
F_134 ( V_165 ) ;
return F_84 ( V_132 ) ;
}
V_35 -> V_132 = V_132 ;
} else {
V_132 = F_122 ( struct V_131 ) ;
if ( V_132 == NULL ) {
F_95 ( type -> V_114 ) ;
F_22 ( V_35 ) ;
if ( V_165 != NULL )
F_134 ( V_165 ) ;
return - V_44 ;
}
F_130 ( V_35 -> V_132 , V_132 ) ;
}
F_141 ( & V_35 -> V_37 , V_1 ) ;
V_35 -> type = type ;
V_22 = & V_35 -> V_22 ;
for ( V_72 = 0 ; V_72 < V_3 -> V_108 ; V_72 ++ ) {
V_40 = & V_35 -> V_40 [ V_72 ] ;
V_40 -> V_186 = V_9 ;
V_40 -> V_150 = V_150 ;
V_40 -> V_152 = V_152 ;
V_40 -> V_187 = V_22 ;
V_40 -> V_188 = V_3 -> V_182 [ V_40 -> V_150 ] ;
V_40 -> V_165 = V_165 ;
if ( V_177 )
V_40 -> V_188 = V_177 ;
if ( V_3 -> V_189 )
V_3 -> V_189 ( V_40 , V_72 ) ;
}
V_22 -> V_38 |= V_42 ;
V_35 -> V_156 = V_156 ;
} else {
V_22 = F_19 ( sizeof( * V_22 ) , V_33 ) ;
if ( V_22 == NULL )
return - V_44 ;
}
F_2 ( & V_22 -> V_190 ) ;
V_22 -> V_130 = F_54 ( V_20 ) ;
V_22 -> V_20 = V_20 ;
F_94 ( V_22 -> V_68 , V_68 , V_174 ) ;
V_48 = F_28 ( V_20 , V_22 , V_3 -> V_108 ) ;
if ( V_48 < 0 )
goto V_115;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_48 = F_33 ( & V_14 , V_51 ) ;
if ( V_48 < 0 )
goto V_116;
V_20 -> V_54 ++ ;
F_4 ( & V_22 -> V_6 , & V_20 -> V_118 ) ;
return 0 ;
V_116:
F_29 ( V_20 , V_22 , V_3 -> V_108 ) ;
V_115:
F_133 ( V_22 ) ;
return V_48 ;
}
static int F_142 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_61 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
int V_9 = V_77 -> V_79 ;
struct V_13 V_14 ;
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_83 ( V_3 ) )
return F_84 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_144 ] ) ;
if ( F_83 ( V_20 ) )
return F_84 ( V_20 ) ;
V_22 = F_106 ( V_20 , V_24 [ V_146 ] ) ;
if ( F_83 ( V_22 ) )
return F_84 ( V_22 ) ;
if ( V_22 -> V_54 > 0 )
return - V_129 ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
return F_34 ( & V_14 ) ;
}
int F_143 ( struct V_191 * type )
{
F_3 ( V_5 ) ;
if ( type -> V_9 == V_95 )
F_4 ( & type -> V_6 , & V_192 ) ;
else
F_144 ( & type -> V_6 , & V_192 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_145 ( struct V_191 * type )
{
F_3 ( V_5 ) ;
F_8 ( & type -> V_6 ) ;
F_5 ( V_5 ) ;
}
static const struct V_191 * F_146 ( T_4 V_9 ,
struct V_23 * V_24 )
{
const struct V_191 * type ;
F_10 (type, &nf_tables_expressions, list) {
if ( ! F_52 ( V_24 , type -> V_68 ) &&
( ! type -> V_9 || type -> V_9 == V_9 ) )
return type ;
}
return NULL ;
}
static const struct V_191 * F_147 ( T_4 V_9 ,
struct V_23 * V_24 )
{
const struct V_191 * type ;
if ( V_24 == NULL )
return F_14 ( - V_69 ) ;
type = F_146 ( V_9 , V_24 ) ;
if ( type != NULL && F_93 ( type -> V_114 ) )
return type ;
#ifdef F_12
if ( type == NULL ) {
F_5 ( V_5 ) ;
F_13 ( L_3 , V_9 ,
F_57 ( V_24 ) , ( char * ) F_58 ( V_24 ) ) ;
F_3 ( V_5 ) ;
if ( F_146 ( V_9 , V_24 ) )
return F_14 ( - V_11 ) ;
F_5 ( V_5 ) ;
F_13 ( L_4 ,
F_57 ( V_24 ) , ( char * ) F_58 ( V_24 ) ) ;
F_3 ( V_5 ) ;
if ( F_146 ( V_9 , V_24 ) )
return F_14 ( - V_11 ) ;
}
#endif
return F_14 ( - V_58 ) ;
}
static int F_148 ( struct V_15 * V_16 ,
const struct V_193 * V_194 )
{
if ( F_63 ( V_16 , V_195 , V_194 -> V_40 -> type -> V_68 ) )
goto V_78;
if ( V_194 -> V_40 -> V_107 ) {
struct V_23 * V_196 = F_112 ( V_16 , V_197 ) ;
if ( V_196 == NULL )
goto V_78;
if ( V_194 -> V_40 -> V_107 ( V_16 , V_194 ) < 0 )
goto V_78;
F_115 ( V_16 , V_196 ) ;
}
return V_16 -> V_99 ;
V_78:
return - 1 ;
}
int F_149 ( struct V_15 * V_16 , unsigned int V_159 ,
const struct V_193 * V_194 )
{
struct V_23 * V_135 ;
V_135 = F_112 ( V_16 , V_159 ) ;
if ( ! V_135 )
goto V_78;
if ( F_148 ( V_16 , V_194 ) < 0 )
goto V_78;
F_115 ( V_16 , V_135 ) ;
return 0 ;
V_78:
return - 1 ;
}
static int F_150 ( const struct V_13 * V_14 ,
const struct V_23 * V_24 ,
struct V_198 * V_199 )
{
const struct V_191 * type ;
const struct V_200 * V_40 ;
struct V_23 * V_160 [ V_201 + 1 ] ;
int V_48 ;
V_48 = F_121 ( V_160 , V_201 , V_24 , V_202 ) ;
if ( V_48 < 0 )
return V_48 ;
type = F_147 ( V_14 -> V_3 -> V_9 , V_160 [ V_195 ] ) ;
if ( F_83 ( type ) )
return F_84 ( type ) ;
if ( V_160 [ V_197 ] ) {
V_48 = F_121 ( V_199 -> V_160 , type -> V_203 ,
V_160 [ V_197 ] , type -> V_156 ) ;
if ( V_48 < 0 )
goto V_115;
} else
memset ( V_199 -> V_160 , 0 , sizeof( V_199 -> V_160 [ 0 ] ) * ( type -> V_203 + 1 ) ) ;
if ( type -> V_204 != NULL ) {
V_40 = type -> V_204 ( V_14 ,
( const struct V_23 * const * ) V_199 -> V_160 ) ;
if ( F_83 ( V_40 ) ) {
V_48 = F_84 ( V_40 ) ;
goto V_115;
}
} else
V_40 = type -> V_40 ;
V_199 -> V_40 = V_40 ;
return 0 ;
V_115:
F_95 ( type -> V_114 ) ;
return V_48 ;
}
static int F_151 ( const struct V_13 * V_14 ,
const struct V_198 * V_199 ,
struct V_193 * V_194 )
{
const struct V_200 * V_40 = V_199 -> V_40 ;
int V_48 ;
V_194 -> V_40 = V_40 ;
if ( V_40 -> V_205 ) {
V_48 = V_40 -> V_205 ( V_14 , V_194 , ( const struct V_23 * * ) V_199 -> V_160 ) ;
if ( V_48 < 0 )
goto V_115;
}
return 0 ;
V_115:
V_194 -> V_40 = NULL ;
return V_48 ;
}
static void F_152 ( const struct V_13 * V_14 ,
struct V_193 * V_194 )
{
if ( V_194 -> V_40 -> V_206 )
V_194 -> V_40 -> V_206 ( V_14 , V_194 ) ;
F_95 ( V_194 -> V_40 -> type -> V_114 ) ;
}
struct V_193 * F_153 ( const struct V_13 * V_14 ,
const struct V_23 * V_24 )
{
struct V_198 V_199 ;
struct V_193 * V_194 ;
int V_48 ;
V_48 = F_150 ( V_14 , V_24 , & V_199 ) ;
if ( V_48 < 0 )
goto V_115;
V_48 = - V_44 ;
V_194 = F_19 ( V_199 . V_40 -> V_31 , V_33 ) ;
if ( V_194 == NULL )
goto V_116;
V_48 = F_151 ( V_14 , & V_199 , V_194 ) ;
if ( V_48 < 0 )
goto V_116;
return V_194 ;
V_116:
F_95 ( V_199 . V_40 -> type -> V_114 ) ;
V_115:
return F_14 ( V_48 ) ;
}
void F_154 ( const struct V_13 * V_14 , struct V_193 * V_194 )
{
F_152 ( V_14 , V_194 ) ;
F_22 ( V_194 ) ;
}
static struct V_55 * F_155 ( const struct V_21 * V_22 ,
T_2 V_130 )
{
struct V_55 * V_56 ;
F_10 (rule, &chain->rules, list) {
if ( V_130 == V_56 -> V_130 )
return V_56 ;
}
return F_14 ( - V_58 ) ;
}
static struct V_55 * F_156 ( const struct V_21 * V_22 ,
const struct V_23 * V_24 )
{
if ( V_24 == NULL )
return F_14 ( - V_69 ) ;
return F_155 ( V_22 , F_125 ( F_126 ( V_24 ) ) ) ;
}
static int F_157 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_25 , T_1 V_27 , int V_75 ,
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
V_18 = F_60 ( V_16 , V_25 , V_27 , type , sizeof( struct V_76 ) ,
V_38 ) ;
if ( V_18 == NULL )
goto V_78;
V_77 = F_61 ( V_18 ) ;
V_77 -> V_79 = V_9 ;
V_77 -> V_80 = V_81 ;
V_77 -> V_82 = F_62 ( V_1 -> V_7 . V_83 & 0xffff ) ;
if ( F_63 ( V_16 , V_209 , V_20 -> V_68 ) )
goto V_78;
if ( F_63 ( V_16 , V_210 , V_22 -> V_68 ) )
goto V_78;
if ( F_113 ( V_16 , V_211 , F_114 ( V_56 -> V_130 ) ) )
goto V_78;
if ( ( V_75 != V_60 ) && ( V_56 -> V_6 . V_212 != & V_22 -> V_190 ) ) {
V_208 = F_158 ( V_56 -> V_6 . V_212 , struct V_55 , V_6 ) ;
if ( F_113 ( V_16 , V_213 ,
F_114 ( V_208 -> V_130 ) ) )
goto V_78;
}
V_6 = F_112 ( V_16 , V_214 ) ;
if ( V_6 == NULL )
goto V_78;
F_159 (expr, next, rule) {
if ( F_149 ( V_16 , V_215 , V_194 ) < 0 )
goto V_78;
}
F_115 ( V_16 , V_6 ) ;
if ( V_56 -> V_216 ) {
struct V_217 * V_216 = V_217 ( V_56 ) ;
if ( F_160 ( V_16 , V_218 , V_216 -> V_99 + 1 ,
V_216 -> V_196 ) < 0 )
goto V_78;
}
F_66 ( V_16 , V_18 ) ;
return 0 ;
V_78:
F_67 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_161 ( const struct V_13 * V_14 ,
const struct V_55 * V_56 ,
int V_75 )
{
struct V_15 * V_16 ;
int V_48 ;
if ( ! V_14 -> V_26 &&
! F_69 ( V_14 -> V_1 , V_87 ) )
return 0 ;
V_48 = - V_88 ;
V_16 = F_70 ( V_89 , V_33 ) ;
if ( V_16 == NULL )
goto V_48;
V_48 = F_157 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_14 -> V_27 ,
V_75 , 0 , V_14 -> V_3 -> V_9 , V_14 -> V_20 ,
V_14 -> V_22 , V_56 ) ;
if ( V_48 < 0 ) {
F_71 ( V_16 ) ;
goto V_48;
}
V_48 = F_72 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_87 ,
V_14 -> V_26 , V_33 ) ;
V_48:
if ( V_48 < 0 ) {
F_73 ( V_14 -> V_1 , V_14 -> V_25 , V_87 ,
V_48 ) ;
}
return V_48 ;
}
static int F_162 ( struct V_15 * V_16 ,
struct V_90 * V_91 )
{
const struct V_76 * V_77 = F_61 ( V_91 -> V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
const struct V_55 * V_56 ;
unsigned int V_92 = 0 , V_93 = V_91 -> args [ 0 ] ;
struct V_1 * V_1 = F_75 ( V_16 -> V_94 ) ;
int V_9 = V_77 -> V_79 ;
F_76 () ;
V_91 -> V_27 = V_1 -> V_7 . V_83 ;
F_77 (afi, &net->nft.af_info, list) {
if ( V_9 != V_95 && V_9 != V_3 -> V_9 )
continue;
F_77 (table, &afi->tables, list) {
F_77 (chain, &table->chains, list) {
F_77 (rule, &chain->rules, list) {
if ( ! F_35 ( V_1 , V_56 ) )
goto V_96;
if ( V_92 < V_93 )
goto V_96;
if ( V_92 > V_93 )
memset ( & V_91 -> args [ 1 ] , 0 ,
sizeof( V_91 -> args ) - sizeof( V_91 -> args [ 0 ] ) ) ;
if ( F_157 ( V_16 , V_1 , F_16 ( V_91 -> V_16 ) . V_25 ,
V_91 -> V_18 -> V_28 ,
V_219 ,
V_97 | V_220 ,
V_3 -> V_9 , V_20 , V_22 , V_56 ) < 0 )
goto V_98;
F_78 ( V_91 , F_79 ( V_16 ) ) ;
V_96:
V_92 ++ ;
}
}
}
}
V_98:
F_80 () ;
V_91 -> args [ 0 ] = V_92 ;
return V_16 -> V_99 ;
}
static int F_163 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_61 ( V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
const struct V_55 * V_56 ;
struct V_15 * V_102 ;
int V_9 = V_77 -> V_79 ;
int V_48 ;
if ( V_18 -> V_103 & V_104 ) {
struct V_105 V_106 = {
. V_107 = F_162 ,
} ;
return F_82 ( V_101 , V_16 , V_18 , & V_106 ) ;
}
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_83 ( V_3 ) )
return F_84 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_209 ] ) ;
if ( F_83 ( V_20 ) )
return F_84 ( V_20 ) ;
if ( V_20 -> V_38 & V_46 )
return - V_58 ;
V_22 = F_106 ( V_20 , V_24 [ V_210 ] ) ;
if ( F_83 ( V_22 ) )
return F_84 ( V_22 ) ;
if ( V_22 -> V_38 & V_52 )
return - V_58 ;
V_56 = F_156 ( V_22 , V_24 [ V_211 ] ) ;
if ( F_83 ( V_56 ) )
return F_84 ( V_56 ) ;
V_102 = F_85 ( V_89 , V_33 ) ;
if ( ! V_102 )
return - V_44 ;
V_48 = F_157 ( V_102 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 , V_219 , 0 ,
V_9 , V_20 , V_22 , V_56 ) ;
if ( V_48 < 0 )
goto V_48;
return F_86 ( V_101 , V_102 , F_16 ( V_16 ) . V_25 ) ;
V_48:
F_71 ( V_102 ) ;
return V_48 ;
}
static void F_164 ( const struct V_13 * V_14 ,
struct V_55 * V_56 )
{
struct V_193 * V_194 ;
V_194 = F_165 ( V_56 ) ;
while ( V_194 -> V_40 && V_194 != F_166 ( V_56 ) ) {
F_152 ( V_14 , V_194 ) ;
V_194 = F_167 ( V_194 ) ;
}
F_22 ( V_56 ) ;
}
static int F_168 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_61 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_55 * V_56 , * V_221 = NULL ;
struct V_217 * V_216 ;
struct V_29 * V_32 = NULL ;
struct V_193 * V_194 ;
struct V_13 V_14 ;
struct V_23 * V_222 ;
unsigned int V_31 , V_72 , V_223 , V_224 = 0 , V_225 = 0 ;
int V_48 , V_226 ;
bool V_171 ;
T_2 V_130 , V_227 ;
V_171 = V_18 -> V_103 & V_172 ? true : false ;
V_3 = F_11 ( V_1 , V_77 -> V_79 , V_171 ) ;
if ( F_83 ( V_3 ) )
return F_84 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_209 ] ) ;
if ( F_83 ( V_20 ) )
return F_84 ( V_20 ) ;
V_22 = F_106 ( V_20 , V_24 [ V_210 ] ) ;
if ( F_83 ( V_22 ) )
return F_84 ( V_22 ) ;
if ( V_24 [ V_211 ] ) {
V_130 = F_125 ( F_126 ( V_24 [ V_211 ] ) ) ;
V_56 = F_155 ( V_22 , V_130 ) ;
if ( F_83 ( V_56 ) )
return F_84 ( V_56 ) ;
if ( V_18 -> V_103 & V_110 )
return - V_111 ;
if ( V_18 -> V_103 & V_112 )
V_221 = V_56 ;
else
return - V_113 ;
} else {
if ( ! V_171 || V_18 -> V_103 & V_112 )
return - V_69 ;
V_130 = F_54 ( V_20 ) ;
if ( V_22 -> V_54 == V_175 )
return - V_176 ;
}
if ( V_24 [ V_213 ] ) {
if ( ! ( V_18 -> V_103 & V_172 ) )
return - V_113 ;
V_227 = F_125 ( F_126 ( V_24 [ V_213 ] ) ) ;
V_221 = F_155 ( V_22 , V_227 ) ;
if ( F_83 ( V_221 ) )
return F_84 ( V_221 ) ;
}
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_223 = 0 ;
V_31 = 0 ;
if ( V_24 [ V_214 ] ) {
F_169 (tmp, nla[NFTA_RULE_EXPRESSIONS], rem) {
V_48 = - V_69 ;
if ( F_170 ( V_222 ) != V_215 )
goto V_115;
if ( V_223 == V_228 )
goto V_115;
V_48 = F_150 ( & V_14 , V_222 , & V_199 [ V_223 ] ) ;
if ( V_48 < 0 )
goto V_115;
V_31 += V_199 [ V_223 ] . V_40 -> V_31 ;
V_223 ++ ;
}
}
V_48 = - V_229 ;
if ( V_31 >= 1 << 12 )
goto V_115;
if ( V_24 [ V_218 ] ) {
V_224 = F_57 ( V_24 [ V_218 ] ) ;
if ( V_224 > 0 )
V_225 = sizeof( struct V_217 ) + V_224 ;
}
V_48 = - V_44 ;
V_56 = F_19 ( sizeof( * V_56 ) + V_31 + V_225 , V_33 ) ;
if ( V_56 == NULL )
goto V_115;
F_39 ( V_1 , V_56 ) ;
V_56 -> V_130 = V_130 ;
V_56 -> V_230 = V_31 ;
V_56 -> V_216 = V_224 ? 1 : 0 ;
if ( V_224 ) {
V_216 = V_217 ( V_56 ) ;
V_216 -> V_99 = V_224 - 1 ;
F_171 ( V_216 -> V_196 , V_24 [ V_218 ] , V_224 ) ;
}
V_194 = F_165 ( V_56 ) ;
for ( V_72 = 0 ; V_72 < V_223 ; V_72 ++ ) {
V_48 = F_151 ( & V_14 , & V_199 [ V_72 ] , V_194 ) ;
if ( V_48 < 0 )
goto V_116;
V_199 [ V_72 ] . V_40 = NULL ;
V_194 = F_167 ( V_194 ) ;
}
if ( V_18 -> V_103 & V_112 ) {
if ( F_37 ( V_1 , V_221 ) ) {
V_32 = F_43 ( & V_14 , V_60 ,
V_221 ) ;
if ( V_32 == NULL ) {
V_48 = - V_44 ;
goto V_116;
}
F_40 ( V_1 , V_221 ) ;
V_22 -> V_54 -- ;
F_4 ( & V_56 -> V_6 , & V_221 -> V_6 ) ;
} else {
V_48 = - V_58 ;
goto V_116;
}
} else if ( V_18 -> V_103 & V_220 )
if ( V_221 )
F_144 ( & V_56 -> V_6 , & V_221 -> V_6 ) ;
else
F_4 ( & V_56 -> V_6 , & V_22 -> V_190 ) ;
else {
if ( V_221 )
F_4 ( & V_56 -> V_6 , & V_221 -> V_6 ) ;
else
F_144 ( & V_56 -> V_6 , & V_22 -> V_190 ) ;
}
if ( F_43 ( & V_14 , V_219 , V_56 ) == NULL ) {
V_48 = - V_44 ;
goto V_120;
}
V_22 -> V_54 ++ ;
return 0 ;
V_120:
F_8 ( & V_56 -> V_6 ) ;
V_116:
F_164 ( & V_14 , V_56 ) ;
V_115:
for ( V_72 = 0 ; V_72 < V_223 ; V_72 ++ ) {
if ( V_199 [ V_72 ] . V_40 != NULL )
F_95 ( V_199 [ V_72 ] . V_40 -> type -> V_114 ) ;
}
return V_48 ;
}
static int F_172 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_61 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 = NULL ;
struct V_55 * V_56 ;
int V_9 = V_77 -> V_79 , V_48 = 0 ;
struct V_13 V_14 ;
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_83 ( V_3 ) )
return F_84 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_209 ] ) ;
if ( F_83 ( V_20 ) )
return F_84 ( V_20 ) ;
if ( V_24 [ V_210 ] ) {
V_22 = F_106 ( V_20 , V_24 [ V_210 ] ) ;
if ( F_83 ( V_22 ) )
return F_84 ( V_22 ) ;
}
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
if ( V_22 ) {
if ( V_24 [ V_211 ] ) {
V_56 = F_156 ( V_22 ,
V_24 [ V_211 ] ) ;
if ( F_83 ( V_56 ) )
return F_84 ( V_56 ) ;
V_48 = F_44 ( & V_14 , V_56 ) ;
} else {
V_48 = F_45 ( & V_14 ) ;
}
} else {
F_10 (chain, &table->chains, list) {
V_14 . V_22 = V_22 ;
V_48 = F_45 ( & V_14 ) ;
if ( V_48 < 0 )
break;
}
}
return V_48 ;
}
int F_173 ( struct V_231 * V_40 )
{
F_3 ( V_5 ) ;
F_4 ( & V_40 -> V_6 , & V_232 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_174 ( struct V_231 * V_40 )
{
F_3 ( V_5 ) ;
F_8 ( & V_40 -> V_6 ) ;
F_5 ( V_5 ) ;
}
static const struct V_231 *
F_175 ( const struct V_23 * const V_24 [] ,
const struct V_233 * V_234 ,
enum V_235 V_156 )
{
const struct V_231 * V_40 , * V_236 ;
struct V_237 V_238 , V_239 ;
T_1 V_240 ;
#ifdef F_12
if ( F_98 ( & V_232 ) ) {
F_5 ( V_5 ) ;
F_13 ( L_5 ) ;
F_3 ( V_5 ) ;
if ( ! F_98 ( & V_232 ) )
return F_14 ( - V_11 ) ;
}
#endif
V_240 = 0 ;
if ( V_24 [ V_241 ] != NULL ) {
V_240 = F_48 ( F_49 ( V_24 [ V_241 ] ) ) ;
V_240 &= V_242 | V_243 | V_244 ;
}
V_236 = NULL ;
V_239 . V_31 = ~ 0 ;
V_239 . V_245 = ~ 0 ;
F_10 (ops, &nf_tables_set_ops, list) {
if ( ( V_40 -> V_240 & V_240 ) != V_240 )
continue;
if ( ! V_40 -> V_246 ( V_234 , V_240 , & V_238 ) )
continue;
switch ( V_156 ) {
case V_247 :
if ( V_238 . V_245 < V_239 . V_245 )
break;
if ( V_238 . V_245 == V_239 . V_245 && V_238 . V_31 < V_239 . V_31 )
break;
continue;
case V_248 :
if ( V_238 . V_31 < V_239 . V_31 )
break;
if ( V_238 . V_31 == V_239 . V_31 && V_238 . V_245 < V_239 . V_245 )
break;
continue;
default:
break;
}
if ( ! F_93 ( V_40 -> V_114 ) )
continue;
if ( V_236 != NULL )
F_95 ( V_236 -> V_114 ) ;
V_236 = V_40 ;
V_239 = V_238 ;
}
if ( V_236 != NULL )
return V_236 ;
return F_14 ( - V_113 ) ;
}
static int F_176 ( struct V_13 * V_14 , struct V_1 * V_1 ,
const struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_61 ( V_18 ) ;
struct V_2 * V_3 = NULL ;
struct V_19 * V_20 = NULL ;
if ( V_77 -> V_79 != V_95 ) {
V_3 = F_11 ( V_1 , V_77 -> V_79 , false ) ;
if ( F_83 ( V_3 ) )
return F_84 ( V_3 ) ;
}
if ( V_24 [ V_249 ] != NULL ) {
if ( V_3 == NULL )
return - V_12 ;
V_20 = F_53 ( V_3 , V_24 [ V_249 ] ) ;
if ( F_83 ( V_20 ) )
return F_84 ( V_20 ) ;
}
F_15 ( V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return 0 ;
}
struct V_61 * F_177 ( const struct V_19 * V_20 ,
const struct V_23 * V_24 )
{
struct V_61 * V_62 ;
if ( V_24 == NULL )
return F_14 ( - V_69 ) ;
F_10 (set, &table->sets, list) {
if ( ! F_52 ( V_24 , V_62 -> V_68 ) )
return V_62 ;
}
return F_14 ( - V_58 ) ;
}
struct V_61 * F_178 ( const struct V_1 * V_1 ,
const struct V_23 * V_24 )
{
struct V_29 * V_32 ;
T_1 V_250 = F_48 ( F_49 ( V_24 ) ) ;
F_10 (trans, &net->nft.commit_list, list) {
if ( V_32 -> V_30 == V_64 &&
V_250 == F_47 ( V_32 ) )
return V_63 ( V_32 ) ;
}
return F_14 ( - V_58 ) ;
}
static int F_179 ( struct V_13 * V_14 , struct V_61 * V_62 ,
const char * V_68 )
{
const struct V_61 * V_72 ;
const char * V_251 ;
unsigned long * V_252 ;
unsigned int V_223 = 0 , V_253 = 0 ;
V_251 = F_180 ( V_68 , V_185 , '%' ) ;
if ( V_251 != NULL ) {
if ( V_251 [ 1 ] != 'd' || strchr ( V_251 + 2 , '%' ) )
return - V_69 ;
V_252 = ( unsigned long * ) F_181 ( V_33 ) ;
if ( V_252 == NULL )
return - V_44 ;
V_96:
F_10 (i, &ctx->table->sets, list) {
int V_222 ;
if ( ! sscanf ( V_72 -> V_68 , V_68 , & V_222 ) )
continue;
if ( V_222 < V_253 || V_222 >= V_253 + V_254 * V_255 )
continue;
F_182 ( V_222 - V_253 , V_252 ) ;
}
V_223 = F_183 ( V_252 , V_254 * V_255 ) ;
if ( V_223 >= V_254 * V_255 ) {
V_253 += V_254 * V_255 ;
memset ( V_252 , 0 , V_255 ) ;
goto V_96;
}
F_184 ( ( unsigned long ) V_252 ) ;
}
snprintf ( V_62 -> V_68 , sizeof( V_62 -> V_68 ) , V_68 , V_253 + V_223 ) ;
F_10 (i, &ctx->table->sets, list) {
if ( ! strcmp ( V_62 -> V_68 , V_72 -> V_68 ) )
return - V_256 ;
}
return 0 ;
}
static int F_185 ( struct V_15 * V_16 , const struct V_13 * V_14 ,
const struct V_61 * V_62 , T_6 V_75 , T_6 V_38 )
{
struct V_76 * V_77 ;
struct V_17 * V_18 ;
struct V_23 * V_234 ;
T_1 V_25 = V_14 -> V_25 ;
T_1 V_27 = V_14 -> V_27 ;
V_75 |= V_5 << 8 ;
V_18 = F_60 ( V_16 , V_25 , V_27 , V_75 , sizeof( struct V_76 ) ,
V_38 ) ;
if ( V_18 == NULL )
goto V_78;
V_77 = F_61 ( V_18 ) ;
V_77 -> V_79 = V_14 -> V_3 -> V_9 ;
V_77 -> V_80 = V_81 ;
V_77 -> V_82 = F_62 ( V_14 -> V_1 -> V_7 . V_83 & 0xffff ) ;
if ( F_63 ( V_16 , V_249 , V_14 -> V_20 -> V_68 ) )
goto V_78;
if ( F_63 ( V_16 , V_257 , V_62 -> V_68 ) )
goto V_78;
if ( V_62 -> V_38 != 0 )
if ( F_64 ( V_16 , V_241 , F_65 ( V_62 -> V_38 ) ) )
goto V_78;
if ( F_64 ( V_16 , V_258 , F_65 ( V_62 -> V_259 ) ) )
goto V_78;
if ( F_64 ( V_16 , V_260 , F_65 ( V_62 -> V_261 ) ) )
goto V_78;
if ( V_62 -> V_38 & V_243 ) {
if ( F_64 ( V_16 , V_262 , F_65 ( V_62 -> V_263 ) ) )
goto V_78;
if ( F_64 ( V_16 , V_264 , F_65 ( V_62 -> V_230 ) ) )
goto V_78;
}
if ( V_62 -> V_265 &&
F_113 ( V_16 , V_266 , F_114 ( V_62 -> V_265 ) ) )
goto V_78;
if ( V_62 -> V_267 &&
F_64 ( V_16 , V_268 , F_65 ( V_62 -> V_267 ) ) )
goto V_78;
if ( V_62 -> V_156 != V_247 ) {
if ( F_64 ( V_16 , V_269 , F_65 ( V_62 -> V_156 ) ) )
goto V_78;
}
if ( F_160 ( V_16 , V_270 , V_62 -> V_271 , V_62 -> V_216 ) )
goto V_78;
V_234 = F_112 ( V_16 , V_272 ) ;
if ( V_234 == NULL )
goto V_78;
if ( V_62 -> V_31 &&
F_64 ( V_16 , V_273 , F_65 ( V_62 -> V_31 ) ) )
goto V_78;
F_115 ( V_16 , V_234 ) ;
F_66 ( V_16 , V_18 ) ;
return 0 ;
V_78:
F_67 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_186 ( const struct V_13 * V_14 ,
const struct V_61 * V_62 ,
int V_75 , T_7 V_274 )
{
struct V_15 * V_16 ;
T_1 V_25 = V_14 -> V_25 ;
int V_48 ;
if ( ! V_14 -> V_26 &&
! F_69 ( V_14 -> V_1 , V_87 ) )
return 0 ;
V_48 = - V_88 ;
V_16 = F_70 ( V_89 , V_274 ) ;
if ( V_16 == NULL )
goto V_48;
V_48 = F_185 ( V_16 , V_14 , V_62 , V_75 , 0 ) ;
if ( V_48 < 0 ) {
F_71 ( V_16 ) ;
goto V_48;
}
V_48 = F_72 ( V_16 , V_14 -> V_1 , V_25 , V_87 ,
V_14 -> V_26 , V_274 ) ;
V_48:
if ( V_48 < 0 )
F_73 ( V_14 -> V_1 , V_25 , V_87 , V_48 ) ;
return V_48 ;
}
static int F_187 ( struct V_15 * V_16 , struct V_90 * V_91 )
{
const struct V_61 * V_62 ;
unsigned int V_92 , V_93 = V_91 -> args [ 0 ] ;
struct V_2 * V_3 ;
struct V_19 * V_20 , * V_275 = (struct V_19 * ) V_91 -> args [ 2 ] ;
struct V_1 * V_1 = F_75 ( V_16 -> V_94 ) ;
int V_276 = V_91 -> args [ 3 ] ;
struct V_13 * V_14 = V_91 -> V_196 , V_277 ;
if ( V_91 -> args [ 1 ] )
return V_16 -> V_99 ;
F_76 () ;
V_91 -> V_27 = V_1 -> V_7 . V_83 ;
F_77 (afi, &net->nft.af_info, list) {
if ( V_14 -> V_3 && V_14 -> V_3 != V_3 )
continue;
if ( V_276 ) {
if ( V_3 -> V_9 != V_276 )
continue;
V_276 = 0 ;
}
F_77 (table, &afi->tables, list) {
if ( V_14 -> V_20 && V_14 -> V_20 != V_20 )
continue;
if ( V_275 ) {
if ( V_275 != V_20 )
continue;
V_275 = NULL ;
}
V_92 = 0 ;
F_77 (set, &table->sets, list) {
if ( V_92 < V_93 )
goto V_96;
V_277 = * V_14 ;
V_277 . V_20 = V_20 ;
V_277 . V_3 = V_3 ;
if ( F_185 ( V_16 , & V_277 , V_62 ,
V_64 ,
V_97 ) < 0 ) {
V_91 -> args [ 0 ] = V_92 ;
V_91 -> args [ 2 ] = ( unsigned long ) V_20 ;
V_91 -> args [ 3 ] = V_3 -> V_9 ;
goto V_98;
}
F_78 ( V_91 , F_79 ( V_16 ) ) ;
V_96:
V_92 ++ ;
}
if ( V_93 )
V_93 = 0 ;
}
}
V_91 -> args [ 1 ] = 1 ;
V_98:
F_80 () ;
return V_16 -> V_99 ;
}
static int F_188 ( struct V_90 * V_91 )
{
F_22 ( V_91 -> V_196 ) ;
return 0 ;
}
static int F_189 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_61 * V_62 ;
struct V_13 V_14 ;
struct V_15 * V_102 ;
const struct V_76 * V_77 = F_61 ( V_18 ) ;
int V_48 ;
V_48 = F_176 ( & V_14 , V_1 , V_16 , V_18 , V_24 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_18 -> V_103 & V_104 ) {
struct V_105 V_106 = {
. V_107 = F_187 ,
. V_98 = F_188 ,
} ;
struct V_13 * V_278 ;
V_278 = F_190 ( sizeof( * V_278 ) , V_33 ) ;
if ( V_278 == NULL )
return - V_44 ;
* V_278 = V_14 ;
V_106 . V_196 = V_278 ;
return F_82 ( V_101 , V_16 , V_18 , & V_106 ) ;
}
if ( V_77 -> V_79 == V_95 )
return - V_12 ;
V_62 = F_177 ( V_14 . V_20 , V_24 [ V_257 ] ) ;
if ( F_83 ( V_62 ) )
return F_84 ( V_62 ) ;
if ( V_62 -> V_38 & V_66 )
return - V_58 ;
V_102 = F_85 ( V_89 , V_33 ) ;
if ( V_102 == NULL )
return - V_44 ;
V_48 = F_185 ( V_102 , & V_14 , V_62 , V_64 , 0 ) ;
if ( V_48 < 0 )
goto V_48;
return F_86 ( V_101 , V_102 , F_16 ( V_16 ) . V_25 ) ;
V_48:
F_71 ( V_102 ) ;
return V_48 ;
}
static int F_191 ( const struct V_13 * V_14 ,
struct V_233 * V_234 ,
const struct V_23 * V_24 )
{
struct V_23 * V_279 [ V_280 + 1 ] ;
int V_48 ;
V_48 = F_121 ( V_279 , V_280 , V_24 , V_281 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_279 [ V_273 ] != NULL )
V_234 -> V_31 = F_48 ( F_49 ( V_279 [ V_273 ] ) ) ;
return 0 ;
}
static int F_192 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_61 ( V_18 ) ;
const struct V_231 * V_40 ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_61 * V_62 ;
struct V_13 V_14 ;
char V_68 [ V_185 ] ;
unsigned int V_31 ;
bool V_171 ;
T_2 V_265 ;
T_1 V_259 , V_263 , V_38 , V_156 , V_267 ;
struct V_233 V_234 ;
unsigned char * V_216 ;
T_6 V_271 ;
int V_48 ;
if ( V_24 [ V_249 ] == NULL ||
V_24 [ V_257 ] == NULL ||
V_24 [ V_260 ] == NULL ||
V_24 [ V_65 ] == NULL )
return - V_69 ;
memset ( & V_234 , 0 , sizeof( V_234 ) ) ;
V_259 = V_282 ;
if ( V_24 [ V_258 ] != NULL ) {
V_259 = F_48 ( F_49 ( V_24 [ V_258 ] ) ) ;
if ( ( V_259 & V_283 ) == V_283 )
return - V_69 ;
}
V_234 . V_261 = F_48 ( F_49 ( V_24 [ V_260 ] ) ) ;
if ( V_234 . V_261 == 0 || V_234 . V_261 > V_284 )
return - V_69 ;
V_38 = 0 ;
if ( V_24 [ V_241 ] != NULL ) {
V_38 = F_48 ( F_49 ( V_24 [ V_241 ] ) ) ;
if ( V_38 & ~ ( V_124 | V_285 |
V_242 | V_244 |
V_243 | V_286 ) )
return - V_69 ;
if ( ( V_38 & ( V_243 | V_286 ) ) ==
( V_243 | V_286 ) )
return - V_113 ;
}
V_263 = 0 ;
if ( V_24 [ V_262 ] != NULL ) {
if ( ! ( V_38 & V_243 ) )
return - V_69 ;
V_263 = F_48 ( F_49 ( V_24 [ V_262 ] ) ) ;
if ( ( V_263 & V_283 ) == V_283 &&
V_263 != V_287 )
return - V_69 ;
if ( V_263 != V_287 ) {
if ( V_24 [ V_264 ] == NULL )
return - V_69 ;
V_234 . V_230 = F_48 ( F_49 ( V_24 [ V_264 ] ) ) ;
if ( V_234 . V_230 == 0 || V_234 . V_230 > V_284 )
return - V_69 ;
} else
V_234 . V_230 = sizeof( struct V_288 ) ;
} else if ( V_38 & V_243 )
return - V_69 ;
V_265 = 0 ;
if ( V_24 [ V_266 ] != NULL ) {
if ( ! ( V_38 & V_244 ) )
return - V_69 ;
V_265 = F_125 ( F_126 ( V_24 [ V_266 ] ) ) ;
}
V_267 = 0 ;
if ( V_24 [ V_268 ] != NULL ) {
if ( ! ( V_38 & V_244 ) )
return - V_69 ;
V_267 = F_48 ( F_49 ( V_24 [ V_268 ] ) ) ;
}
V_156 = V_247 ;
if ( V_24 [ V_269 ] != NULL )
V_156 = F_48 ( F_49 ( V_24 [ V_269 ] ) ) ;
if ( V_24 [ V_272 ] != NULL ) {
V_48 = F_191 ( & V_14 , & V_234 , V_24 [ V_272 ] ) ;
if ( V_48 < 0 )
return V_48 ;
}
V_171 = V_18 -> V_103 & V_172 ? true : false ;
V_3 = F_11 ( V_1 , V_77 -> V_79 , V_171 ) ;
if ( F_83 ( V_3 ) )
return F_84 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_249 ] ) ;
if ( F_83 ( V_20 ) )
return F_84 ( V_20 ) ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
V_62 = F_177 ( V_20 , V_24 [ V_257 ] ) ;
if ( F_83 ( V_62 ) ) {
if ( F_84 ( V_62 ) != - V_58 )
return F_84 ( V_62 ) ;
V_62 = NULL ;
}
if ( V_62 != NULL ) {
if ( V_18 -> V_103 & V_110 )
return - V_111 ;
if ( V_18 -> V_103 & V_112 )
return - V_113 ;
return 0 ;
}
if ( ! ( V_18 -> V_103 & V_172 ) )
return - V_58 ;
V_40 = F_175 ( V_24 , & V_234 , V_156 ) ;
if ( F_83 ( V_40 ) )
return F_84 ( V_40 ) ;
V_271 = 0 ;
if ( V_24 [ V_270 ] )
V_271 = F_57 ( V_24 [ V_270 ] ) ;
V_31 = 0 ;
if ( V_40 -> V_289 != NULL )
V_31 = V_40 -> V_289 ( V_24 ) ;
V_48 = - V_44 ;
V_62 = F_19 ( sizeof( * V_62 ) + V_31 + V_271 , V_33 ) ;
if ( V_62 == NULL )
goto V_115;
F_94 ( V_68 , V_24 [ V_257 ] , sizeof( V_62 -> V_68 ) ) ;
V_48 = F_179 ( & V_14 , V_62 , V_68 ) ;
if ( V_48 < 0 )
goto V_116;
V_216 = NULL ;
if ( V_271 ) {
V_216 = V_62 -> V_196 + V_31 ;
F_171 ( V_216 , V_24 [ V_270 ] , V_271 ) ;
}
F_2 ( & V_62 -> V_125 ) ;
F_141 ( & V_62 -> V_37 , V_1 ) ;
V_62 -> V_40 = V_40 ;
V_62 -> V_259 = V_259 ;
V_62 -> V_261 = V_234 . V_261 ;
V_62 -> V_263 = V_263 ;
V_62 -> V_230 = V_234 . V_230 ;
V_62 -> V_38 = V_38 ;
V_62 -> V_31 = V_234 . V_31 ;
V_62 -> V_156 = V_156 ;
V_62 -> V_271 = V_271 ;
V_62 -> V_216 = V_216 ;
V_62 -> V_265 = V_265 ;
V_62 -> V_267 = V_267 ;
V_48 = V_40 -> V_205 ( V_62 , & V_234 , V_24 ) ;
if ( V_48 < 0 )
goto V_116;
V_48 = F_46 ( & V_14 , V_64 , V_62 ) ;
if ( V_48 < 0 )
goto V_116;
F_4 ( & V_62 -> V_6 , & V_20 -> V_119 ) ;
V_20 -> V_54 ++ ;
return 0 ;
V_116:
F_22 ( V_62 ) ;
V_115:
F_95 ( V_40 -> V_114 ) ;
return V_48 ;
}
static void F_193 ( struct V_61 * V_62 )
{
V_62 -> V_40 -> V_206 ( V_62 ) ;
F_95 ( V_62 -> V_40 -> V_114 ) ;
F_22 ( V_62 ) ;
}
static void F_194 ( const struct V_13 * V_14 , struct V_61 * V_62 )
{
F_8 ( & V_62 -> V_6 ) ;
F_186 ( V_14 , V_62 , V_67 , V_290 ) ;
F_193 ( V_62 ) ;
}
static int F_195 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_61 ( V_18 ) ;
struct V_61 * V_62 ;
struct V_13 V_14 ;
int V_48 ;
if ( V_77 -> V_79 == V_95 )
return - V_12 ;
if ( V_24 [ V_249 ] == NULL )
return - V_69 ;
V_48 = F_176 ( & V_14 , V_1 , V_16 , V_18 , V_24 ) ;
if ( V_48 < 0 )
return V_48 ;
V_62 = F_177 ( V_14 . V_20 , V_24 [ V_257 ] ) ;
if ( F_83 ( V_62 ) )
return F_84 ( V_62 ) ;
if ( ! F_98 ( & V_62 -> V_125 ) )
return - V_129 ;
return F_50 ( & V_14 , V_62 ) ;
}
static int F_196 ( const struct V_13 * V_14 ,
const struct V_61 * V_62 ,
const struct V_291 * V_292 ,
const struct V_293 * V_294 )
{
const struct V_295 * V_296 = F_197 ( V_62 , V_294 -> V_187 ) ;
enum V_297 V_298 ;
V_298 = F_198 ( V_62 -> V_263 ) ;
return F_199 ( V_14 , V_298 , F_200 ( V_296 ) ,
V_62 -> V_263 == V_287 ?
V_287 : V_282 ,
V_62 -> V_230 ) ;
}
int F_201 ( const struct V_13 * V_14 , struct V_61 * V_62 ,
struct V_299 * V_300 )
{
struct V_299 * V_72 ;
struct V_291 V_292 ;
if ( ! F_98 ( & V_62 -> V_125 ) && V_62 -> V_38 & V_124 )
return - V_129 ;
if ( V_300 -> V_38 & V_243 ) {
F_10 (i, &set->bindings, list) {
if ( V_300 -> V_38 & V_243 &&
V_72 -> V_22 == V_300 -> V_22 )
goto V_301;
}
V_292 . V_302 = 0 ;
V_292 . V_303 = 0 ;
V_292 . V_48 = 0 ;
V_292 . V_304 = F_196 ;
V_62 -> V_40 -> V_305 ( V_14 , V_62 , & V_292 ) ;
if ( V_292 . V_48 < 0 ) {
if ( V_62 -> V_38 & V_124 )
F_194 ( V_14 , V_62 ) ;
return V_292 . V_48 ;
}
}
V_301:
V_300 -> V_22 = V_14 -> V_22 ;
F_4 ( & V_300 -> V_6 , & V_62 -> V_125 ) ;
return 0 ;
}
void F_202 ( const struct V_13 * V_14 , struct V_61 * V_62 ,
struct V_299 * V_300 )
{
F_8 ( & V_300 -> V_6 ) ;
if ( F_98 ( & V_62 -> V_125 ) && V_62 -> V_38 & V_124 &&
! ( V_62 -> V_38 & V_66 ) )
F_194 ( V_14 , V_62 ) ;
}
static int F_203 ( struct V_13 * V_14 , struct V_1 * V_1 ,
const struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_61 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
V_3 = F_11 ( V_1 , V_77 -> V_79 , false ) ;
if ( F_83 ( V_3 ) )
return F_84 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_306 ] ) ;
if ( F_83 ( V_20 ) )
return F_84 ( V_20 ) ;
F_15 ( V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return 0 ;
}
static int F_204 ( struct V_15 * V_16 ,
const struct V_61 * V_62 ,
const struct V_293 * V_294 )
{
const struct V_295 * V_296 = F_197 ( V_62 , V_294 -> V_187 ) ;
unsigned char * V_307 = F_205 ( V_16 ) ;
struct V_23 * V_135 ;
V_135 = F_112 ( V_16 , V_215 ) ;
if ( V_135 == NULL )
goto V_78;
if ( F_206 ( V_16 , V_308 , F_207 ( V_296 ) ,
V_282 , V_62 -> V_261 ) < 0 )
goto V_78;
if ( F_208 ( V_296 , V_309 ) &&
F_206 ( V_16 , V_310 , F_200 ( V_296 ) ,
V_62 -> V_263 == V_287 ? V_287 : V_282 ,
V_62 -> V_230 ) < 0 )
goto V_78;
if ( F_208 ( V_296 , V_311 ) &&
F_149 ( V_16 , V_312 , F_209 ( V_296 ) ) < 0 )
goto V_78;
if ( F_208 ( V_296 , V_313 ) &&
F_64 ( V_16 , V_314 ,
F_65 ( * F_210 ( V_296 ) ) ) )
goto V_78;
if ( F_208 ( V_296 , V_315 ) &&
F_113 ( V_16 , V_316 ,
F_114 ( * F_211 ( V_296 ) ) ) )
goto V_78;
if ( F_208 ( V_296 , V_317 ) ) {
unsigned long V_318 , V_319 = V_320 ;
V_318 = * F_212 ( V_296 ) ;
if ( F_213 ( V_319 , V_318 ) )
V_318 -= V_319 ;
else
V_318 = 0 ;
if ( F_113 ( V_16 , V_321 ,
F_114 ( F_214 ( V_318 ) ) ) )
goto V_78;
}
if ( F_208 ( V_296 , V_322 ) ) {
struct V_217 * V_216 ;
V_216 = F_215 ( V_296 ) ;
if ( F_160 ( V_16 , V_323 ,
V_216 -> V_99 + 1 , V_216 -> V_196 ) )
goto V_78;
}
F_115 ( V_16 , V_135 ) ;
return 0 ;
V_78:
F_67 ( V_16 , V_307 ) ;
return - V_324 ;
}
static int F_216 ( const struct V_13 * V_14 ,
const struct V_61 * V_62 ,
const struct V_291 * V_292 ,
const struct V_293 * V_294 )
{
struct V_325 * args ;
args = F_217 ( V_292 , struct V_325 , V_292 ) ;
return F_204 ( args -> V_16 , V_62 , V_294 ) ;
}
static int F_218 ( struct V_15 * V_16 , struct V_90 * V_91 )
{
struct V_1 * V_1 = F_75 ( V_16 -> V_94 ) ;
const struct V_61 * V_62 ;
struct V_325 args ;
struct V_13 V_14 ;
struct V_23 * V_24 [ V_326 + 1 ] ;
struct V_76 * V_77 ;
struct V_17 * V_18 ;
struct V_23 * V_135 ;
T_1 V_25 , V_27 ;
int V_75 , V_48 ;
V_48 = F_219 ( V_91 -> V_18 , sizeof( struct V_76 ) , V_24 ,
V_326 , V_327 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_203 ( & V_14 , V_1 , V_91 -> V_16 , V_91 -> V_18 ,
( void * ) V_24 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_14 . V_20 -> V_38 & V_46 )
return - V_58 ;
V_62 = F_177 ( V_14 . V_20 , V_24 [ V_328 ] ) ;
if ( F_83 ( V_62 ) )
return F_84 ( V_62 ) ;
if ( V_62 -> V_38 & V_66 )
return - V_58 ;
V_75 = V_329 ;
V_75 |= V_5 << 8 ;
V_25 = F_16 ( V_91 -> V_16 ) . V_25 ;
V_27 = V_91 -> V_18 -> V_28 ;
V_18 = F_60 ( V_16 , V_25 , V_27 , V_75 , sizeof( struct V_76 ) ,
V_97 ) ;
if ( V_18 == NULL )
goto V_78;
V_77 = F_61 ( V_18 ) ;
V_77 -> V_79 = V_14 . V_3 -> V_9 ;
V_77 -> V_80 = V_81 ;
V_77 -> V_82 = F_62 ( V_14 . V_1 -> V_7 . V_83 & 0xffff ) ;
if ( F_63 ( V_16 , V_306 , V_14 . V_20 -> V_68 ) )
goto V_78;
if ( F_63 ( V_16 , V_328 , V_62 -> V_68 ) )
goto V_78;
V_135 = F_112 ( V_16 , V_330 ) ;
if ( V_135 == NULL )
goto V_78;
args . V_91 = V_91 ;
args . V_16 = V_16 ;
args . V_292 . V_302 = V_91 -> args [ 0 ] ;
args . V_292 . V_303 = 0 ;
args . V_292 . V_48 = 0 ;
args . V_292 . V_304 = F_216 ;
V_62 -> V_40 -> V_305 ( & V_14 , V_62 , & args . V_292 ) ;
F_115 ( V_16 , V_135 ) ;
F_66 ( V_16 , V_18 ) ;
if ( args . V_292 . V_48 && args . V_292 . V_48 != - V_324 )
return args . V_292 . V_48 ;
if ( args . V_292 . V_303 == V_91 -> args [ 0 ] )
return 0 ;
V_91 -> args [ 0 ] = args . V_292 . V_303 ;
return V_16 -> V_99 ;
V_78:
return - V_143 ;
}
static int F_220 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_61 * V_62 ;
struct V_13 V_14 ;
int V_48 ;
V_48 = F_203 ( & V_14 , V_1 , V_16 , V_18 , V_24 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_14 . V_20 -> V_38 & V_46 )
return - V_58 ;
V_62 = F_177 ( V_14 . V_20 , V_24 [ V_328 ] ) ;
if ( F_83 ( V_62 ) )
return F_84 ( V_62 ) ;
if ( V_62 -> V_38 & V_66 )
return - V_58 ;
if ( V_18 -> V_103 & V_104 ) {
struct V_105 V_106 = {
. V_107 = F_218 ,
} ;
return F_82 ( V_101 , V_16 , V_18 , & V_106 ) ;
}
return - V_113 ;
}
static int F_221 ( struct V_15 * V_16 ,
const struct V_13 * V_14 , T_1 V_27 ,
T_1 V_25 , int V_75 , T_6 V_38 ,
const struct V_61 * V_62 ,
const struct V_293 * V_294 )
{
struct V_76 * V_77 ;
struct V_17 * V_18 ;
struct V_23 * V_135 ;
int V_48 ;
V_75 |= V_5 << 8 ;
V_18 = F_60 ( V_16 , V_25 , V_27 , V_75 , sizeof( struct V_76 ) ,
V_38 ) ;
if ( V_18 == NULL )
goto V_78;
V_77 = F_61 ( V_18 ) ;
V_77 -> V_79 = V_14 -> V_3 -> V_9 ;
V_77 -> V_80 = V_81 ;
V_77 -> V_82 = F_62 ( V_14 -> V_1 -> V_7 . V_83 & 0xffff ) ;
if ( F_63 ( V_16 , V_249 , V_14 -> V_20 -> V_68 ) )
goto V_78;
if ( F_63 ( V_16 , V_257 , V_62 -> V_68 ) )
goto V_78;
V_135 = F_112 ( V_16 , V_330 ) ;
if ( V_135 == NULL )
goto V_78;
V_48 = F_204 ( V_16 , V_62 , V_294 ) ;
if ( V_48 < 0 )
goto V_78;
F_115 ( V_16 , V_135 ) ;
F_66 ( V_16 , V_18 ) ;
return 0 ;
V_78:
F_67 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_222 ( const struct V_13 * V_14 ,
const struct V_61 * V_62 ,
const struct V_293 * V_294 ,
int V_75 , T_6 V_38 )
{
struct V_1 * V_1 = V_14 -> V_1 ;
T_1 V_25 = V_14 -> V_25 ;
struct V_15 * V_16 ;
int V_48 ;
if ( ! V_14 -> V_26 && ! F_69 ( V_1 , V_87 ) )
return 0 ;
V_48 = - V_88 ;
V_16 = F_70 ( V_89 , V_33 ) ;
if ( V_16 == NULL )
goto V_48;
V_48 = F_221 ( V_16 , V_14 , 0 , V_25 , V_75 , V_38 ,
V_62 , V_294 ) ;
if ( V_48 < 0 ) {
F_71 ( V_16 ) ;
goto V_48;
}
V_48 = F_72 ( V_16 , V_1 , V_25 , V_87 , V_14 -> V_26 ,
V_33 ) ;
V_48:
if ( V_48 < 0 )
F_73 ( V_1 , V_25 , V_87 , V_48 ) ;
return V_48 ;
}
static struct V_29 * F_223 ( struct V_13 * V_14 ,
int V_30 ,
struct V_61 * V_62 )
{
struct V_29 * V_32 ;
V_32 = F_18 ( V_14 , V_30 , sizeof( struct V_331 ) ) ;
if ( V_32 == NULL )
return NULL ;
F_224 ( V_32 ) = V_62 ;
return V_32 ;
}
void * F_225 ( const struct V_61 * V_62 ,
const struct V_332 * V_333 ,
const T_1 * V_334 , const T_1 * V_196 ,
T_2 V_265 , T_7 V_335 )
{
struct V_295 * V_296 ;
void * V_294 ;
V_294 = F_19 ( V_62 -> V_40 -> V_336 + V_333 -> V_99 , V_335 ) ;
if ( V_294 == NULL )
return NULL ;
V_296 = F_197 ( V_62 , V_294 ) ;
F_226 ( V_296 , V_333 ) ;
memcpy ( F_207 ( V_296 ) , V_334 , V_62 -> V_261 ) ;
if ( F_208 ( V_296 , V_309 ) )
memcpy ( F_200 ( V_296 ) , V_196 , V_62 -> V_230 ) ;
if ( F_208 ( V_296 , V_317 ) )
* F_212 ( V_296 ) =
V_320 + F_227 ( V_265 ) ;
if ( F_208 ( V_296 , V_315 ) )
* F_211 ( V_296 ) = V_265 ;
return V_294 ;
}
void F_228 ( const struct V_61 * V_62 , void * V_294 )
{
struct V_295 * V_296 = F_197 ( V_62 , V_294 ) ;
F_229 ( F_207 ( V_296 ) , V_282 ) ;
if ( F_208 ( V_296 , V_309 ) )
F_229 ( F_200 ( V_296 ) , V_62 -> V_263 ) ;
if ( F_208 ( V_296 , V_311 ) )
F_152 ( NULL , F_209 ( V_296 ) ) ;
F_22 ( V_294 ) ;
}
static int F_230 ( struct V_13 * V_14 , struct V_61 * V_62 ,
const struct V_23 * V_159 )
{
struct V_23 * V_24 [ V_337 + 1 ] ;
struct V_338 V_339 , V_340 ;
struct V_332 V_333 ;
struct V_295 * V_296 ;
struct V_293 V_294 ;
struct V_299 * V_300 ;
struct V_217 * V_216 ;
struct V_341 V_196 ;
enum V_297 V_298 ;
struct V_29 * V_32 ;
T_2 V_265 ;
T_1 V_38 ;
T_4 V_224 ;
int V_48 ;
V_48 = F_121 ( V_24 , V_337 , V_159 ,
V_342 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_24 [ V_308 ] == NULL )
return - V_69 ;
F_231 ( & V_333 ) ;
V_38 = 0 ;
if ( V_24 [ V_314 ] != NULL ) {
V_38 = F_48 ( F_49 ( V_24 [ V_314 ] ) ) ;
if ( V_38 & ~ V_343 )
return - V_69 ;
if ( ! ( V_62 -> V_38 & V_242 ) &&
V_38 & V_343 )
return - V_69 ;
if ( V_38 != 0 )
F_232 ( & V_333 , V_313 ) ;
}
if ( V_62 -> V_38 & V_243 ) {
if ( V_24 [ V_310 ] == NULL &&
! ( V_38 & V_343 ) )
return - V_69 ;
if ( V_24 [ V_310 ] != NULL &&
V_38 & V_343 )
return - V_69 ;
} else {
if ( V_24 [ V_310 ] != NULL )
return - V_69 ;
}
V_265 = 0 ;
if ( V_24 [ V_316 ] != NULL ) {
if ( ! ( V_62 -> V_38 & V_244 ) )
return - V_69 ;
V_265 = F_125 ( F_126 ( V_24 [ V_316 ] ) ) ;
} else if ( V_62 -> V_38 & V_244 ) {
V_265 = V_62 -> V_265 ;
}
V_48 = F_233 ( V_14 , & V_294 . V_334 . V_344 , sizeof( V_294 . V_334 ) , & V_339 ,
V_24 [ V_308 ] ) ;
if ( V_48 < 0 )
goto V_115;
V_48 = - V_69 ;
if ( V_339 . type != V_282 || V_339 . V_99 != V_62 -> V_261 )
goto V_116;
F_234 ( & V_333 , V_345 , V_339 . V_99 ) ;
if ( V_265 > 0 ) {
F_232 ( & V_333 , V_317 ) ;
if ( V_265 != V_62 -> V_265 )
F_232 ( & V_333 , V_315 ) ;
}
if ( V_24 [ V_310 ] != NULL ) {
V_48 = F_233 ( V_14 , & V_196 , sizeof( V_196 ) , & V_340 ,
V_24 [ V_310 ] ) ;
if ( V_48 < 0 )
goto V_116;
V_48 = - V_69 ;
if ( V_62 -> V_263 != V_287 && V_340 . V_99 != V_62 -> V_230 )
goto V_120;
V_298 = F_198 ( V_62 -> V_263 ) ;
F_10 (binding, &set->bindings, list) {
struct V_13 V_346 = {
. V_3 = V_14 -> V_3 ,
. V_20 = V_14 -> V_20 ,
. V_22 = (struct V_21 * ) V_300 -> V_22 ,
} ;
if ( ! ( V_300 -> V_38 & V_243 ) )
continue;
V_48 = F_199 ( & V_346 , V_298 ,
& V_196 ,
V_340 . type , V_340 . V_99 ) ;
if ( V_48 < 0 )
goto V_120;
}
F_234 ( & V_333 , V_309 , V_340 . V_99 ) ;
}
V_224 = 0 ;
if ( V_24 [ V_323 ] != NULL ) {
V_224 = F_57 ( V_24 [ V_323 ] ) ;
if ( V_224 > 0 )
F_234 ( & V_333 , V_322 ,
V_224 ) ;
}
V_48 = - V_44 ;
V_294 . V_187 = F_225 ( V_62 , & V_333 , V_294 . V_334 . V_344 . V_196 , V_196 . V_196 ,
V_265 , V_33 ) ;
if ( V_294 . V_187 == NULL )
goto V_120;
V_296 = F_197 ( V_62 , V_294 . V_187 ) ;
if ( V_38 )
* F_210 ( V_296 ) = V_38 ;
if ( V_224 > 0 ) {
V_216 = F_215 ( V_296 ) ;
V_216 -> V_99 = V_224 - 1 ;
F_171 ( & V_216 -> V_196 , V_24 [ V_323 ] , V_224 ) ;
}
V_32 = F_223 ( V_14 , V_329 , V_62 ) ;
if ( V_32 == NULL )
goto V_347;
V_296 -> V_57 = F_36 ( V_14 -> V_1 ) | V_348 ;
V_48 = V_62 -> V_40 -> V_349 ( V_62 , & V_294 ) ;
if ( V_48 < 0 )
goto V_350;
V_331 ( V_32 ) = V_294 ;
F_31 ( & V_32 -> V_6 , & V_14 -> V_1 -> V_7 . V_47 ) ;
return 0 ;
V_350:
F_22 ( V_32 ) ;
V_347:
F_22 ( V_294 . V_187 ) ;
V_120:
if ( V_24 [ V_310 ] != NULL )
F_229 ( & V_196 , V_340 . type ) ;
V_116:
F_229 ( & V_294 . V_334 . V_344 , V_339 . type ) ;
V_115:
return V_48 ;
}
static int F_235 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_23 * V_159 ;
struct V_61 * V_62 ;
struct V_13 V_14 ;
int V_226 , V_48 = 0 ;
if ( V_24 [ V_330 ] == NULL )
return - V_69 ;
V_48 = F_203 ( & V_14 , V_1 , V_16 , V_18 , V_24 ) ;
if ( V_48 < 0 )
return V_48 ;
V_62 = F_177 ( V_14 . V_20 , V_24 [ V_328 ] ) ;
if ( F_83 ( V_62 ) ) {
if ( V_24 [ V_351 ] ) {
V_62 = F_178 ( V_1 ,
V_24 [ V_351 ] ) ;
}
if ( F_83 ( V_62 ) )
return F_84 ( V_62 ) ;
}
if ( ! F_98 ( & V_62 -> V_125 ) && V_62 -> V_38 & V_285 )
return - V_129 ;
F_169 (attr, nla[NFTA_SET_ELEM_LIST_ELEMENTS], rem) {
if ( V_62 -> V_31 &&
! F_236 ( & V_62 -> V_352 , 1 , V_62 -> V_31 + V_62 -> V_353 ) )
return - V_256 ;
V_48 = F_230 ( & V_14 , V_62 , V_159 ) ;
if ( V_48 < 0 ) {
F_237 ( & V_62 -> V_352 ) ;
break;
}
}
return V_48 ;
}
static int F_238 ( struct V_13 * V_14 , struct V_61 * V_62 ,
const struct V_23 * V_159 )
{
struct V_23 * V_24 [ V_337 + 1 ] ;
struct V_338 V_234 ;
struct V_293 V_294 ;
struct V_29 * V_32 ;
int V_48 ;
V_48 = F_121 ( V_24 , V_337 , V_159 ,
V_342 ) ;
if ( V_48 < 0 )
goto V_115;
V_48 = - V_69 ;
if ( V_24 [ V_308 ] == NULL )
goto V_115;
V_48 = F_233 ( V_14 , & V_294 . V_334 . V_344 , sizeof( V_294 . V_334 ) , & V_234 ,
V_24 [ V_308 ] ) ;
if ( V_48 < 0 )
goto V_115;
V_48 = - V_69 ;
if ( V_234 . type != V_282 || V_234 . V_99 != V_62 -> V_261 )
goto V_116;
V_32 = F_223 ( V_14 , V_354 , V_62 ) ;
if ( V_32 == NULL ) {
V_48 = - V_44 ;
goto V_116;
}
V_294 . V_187 = V_62 -> V_40 -> V_355 ( V_62 , & V_294 ) ;
if ( V_294 . V_187 == NULL ) {
V_48 = - V_58 ;
goto V_120;
}
V_331 ( V_32 ) = V_294 ;
F_31 ( & V_32 -> V_6 , & V_14 -> V_1 -> V_7 . V_47 ) ;
return 0 ;
V_120:
F_22 ( V_32 ) ;
V_116:
F_229 ( & V_294 . V_334 . V_344 , V_234 . type ) ;
V_115:
return V_48 ;
}
static int F_239 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_23 * V_159 ;
struct V_61 * V_62 ;
struct V_13 V_14 ;
int V_226 , V_48 = 0 ;
if ( V_24 [ V_330 ] == NULL )
return - V_69 ;
V_48 = F_203 ( & V_14 , V_1 , V_16 , V_18 , V_24 ) ;
if ( V_48 < 0 )
return V_48 ;
V_62 = F_177 ( V_14 . V_20 , V_24 [ V_328 ] ) ;
if ( F_83 ( V_62 ) )
return F_84 ( V_62 ) ;
if ( ! F_98 ( & V_62 -> V_125 ) && V_62 -> V_38 & V_285 )
return - V_129 ;
F_169 (attr, nla[NFTA_SET_ELEM_LIST_ELEMENTS], rem) {
V_48 = F_238 ( & V_14 , V_62 , V_159 ) ;
if ( V_48 < 0 )
break;
V_62 -> V_353 ++ ;
}
return V_48 ;
}
void F_240 ( struct V_356 * V_357 )
{
struct V_358 * V_359 ;
unsigned int V_72 ;
V_359 = F_217 ( V_357 , struct V_358 , V_360 . V_357 ) ;
for ( V_72 = 0 ; V_72 < V_359 -> V_360 . V_361 ; V_72 ++ )
F_228 ( V_359 -> V_360 . V_62 , V_359 -> V_362 [ V_72 ] ) ;
F_22 ( V_359 ) ;
}
struct V_358 * F_241 ( const struct V_61 * V_62 ,
T_7 V_335 )
{
struct V_358 * V_359 ;
V_359 = F_19 ( sizeof( * V_359 ) , V_335 ) ;
if ( V_359 == NULL )
return V_359 ;
V_359 -> V_360 . V_62 = V_62 ;
return V_359 ;
}
static int F_242 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_25 , T_1 V_27 )
{
struct V_17 * V_18 ;
struct V_76 * V_77 ;
int V_75 = ( V_5 << 8 ) | V_363 ;
V_18 = F_60 ( V_16 , V_25 , V_27 , V_75 , sizeof( struct V_76 ) , 0 ) ;
if ( V_18 == NULL )
goto V_78;
V_77 = F_61 ( V_18 ) ;
V_77 -> V_79 = V_127 ;
V_77 -> V_80 = V_81 ;
V_77 -> V_82 = F_62 ( V_1 -> V_7 . V_83 & 0xffff ) ;
if ( F_64 ( V_16 , V_364 , F_65 ( V_1 -> V_7 . V_83 ) ) )
goto V_78;
F_66 ( V_16 , V_18 ) ;
return 0 ;
V_78:
F_67 ( V_16 , V_18 ) ;
return - V_324 ;
}
static int F_243 ( struct V_1 * V_1 , struct V_15 * V_16 , int V_75 )
{
struct V_17 * V_18 = F_79 ( V_16 ) ;
struct V_15 * V_102 ;
int V_48 ;
if ( F_17 ( V_18 ) &&
! F_69 ( V_1 , V_87 ) )
return 0 ;
V_48 = - V_88 ;
V_102 = F_70 ( V_89 , V_33 ) ;
if ( V_102 == NULL )
goto V_48;
V_48 = F_242 ( V_102 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 ) ;
if ( V_48 < 0 ) {
F_71 ( V_102 ) ;
goto V_48;
}
V_48 = F_72 ( V_102 , V_1 , F_16 ( V_16 ) . V_25 ,
V_87 , F_17 ( V_18 ) , V_33 ) ;
V_48:
if ( V_48 < 0 ) {
F_73 ( V_1 , F_16 ( V_16 ) . V_25 , V_87 ,
V_48 ) ;
}
return V_48 ;
}
static int F_244 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
struct V_15 * V_102 ;
int V_48 ;
V_102 = F_85 ( V_89 , V_33 ) ;
if ( V_102 == NULL )
return - V_44 ;
V_48 = F_242 ( V_102 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 ) ;
if ( V_48 < 0 )
goto V_48;
return F_86 ( V_101 , V_102 , F_16 ( V_16 ) . V_25 ) ;
V_48:
F_71 ( V_102 ) ;
return V_48 ;
}
static void F_245 ( struct V_29 * V_32 )
{
struct V_34 * V_35 ;
if ( F_139 ( V_32 ) [ 0 ] )
strcpy ( V_32 -> V_14 . V_22 -> V_68 , F_139 ( V_32 ) ) ;
if ( ! ( V_32 -> V_14 . V_22 -> V_38 & V_42 ) )
return;
V_35 = V_34 ( V_32 -> V_14 . V_22 ) ;
F_128 ( V_35 , F_136 ( V_32 ) ) ;
switch ( F_138 ( V_32 ) ) {
case V_173 :
case V_170 :
V_35 -> V_156 = F_138 ( V_32 ) ;
break;
}
}
static void F_246 ( struct V_29 * V_32 )
{
switch ( V_32 -> V_30 ) {
case V_49 :
F_101 ( & V_32 -> V_14 ) ;
break;
case V_53 :
F_133 ( V_32 -> V_14 . V_22 ) ;
break;
case V_60 :
F_164 ( & V_32 -> V_14 , V_59 ( V_32 ) ) ;
break;
case V_67 :
F_193 ( V_63 ( V_32 ) ) ;
break;
case V_354 :
F_228 ( F_224 ( V_32 ) ,
V_331 ( V_32 ) . V_187 ) ;
break;
}
F_22 ( V_32 ) ;
}
static int F_247 ( struct V_1 * V_1 , struct V_15 * V_16 )
{
struct V_29 * V_32 , * V_207 ;
struct V_331 * V_365 ;
while ( ++ V_1 -> V_7 . V_83 == 0 ) ;
V_1 -> V_7 . V_366 = F_248 ( V_1 ) ;
F_131 () ;
F_97 (trans, next, &net->nft.commit_list, list) {
switch ( V_32 -> V_30 ) {
case V_45 :
if ( F_91 ( V_32 ) ) {
if ( ! F_90 ( V_32 ) ) {
F_88 ( V_32 -> V_14 . V_3 ,
V_32 -> V_14 . V_20 ) ;
V_32 -> V_14 . V_20 -> V_38 |= V_41 ;
}
} else {
V_32 -> V_14 . V_20 -> V_38 &= ~ V_46 ;
}
F_68 ( & V_32 -> V_14 , V_45 ) ;
F_20 ( V_32 ) ;
break;
case V_49 :
F_68 ( & V_32 -> V_14 , V_49 ) ;
break;
case V_51 :
if ( F_137 ( V_32 ) )
F_245 ( V_32 ) ;
else
V_32 -> V_14 . V_22 -> V_38 &= ~ V_52 ;
F_117 ( & V_32 -> V_14 , V_51 ) ;
F_20 ( V_32 ) ;
break;
case V_53 :
F_117 ( & V_32 -> V_14 , V_53 ) ;
F_29 ( V_32 -> V_14 . V_20 ,
V_32 -> V_14 . V_22 ,
V_32 -> V_14 . V_3 -> V_108 ) ;
break;
case V_219 :
F_41 ( V_32 -> V_14 . V_1 , V_59 ( V_32 ) ) ;
F_161 ( & V_32 -> V_14 ,
V_59 ( V_32 ) ,
V_219 ) ;
F_20 ( V_32 ) ;
break;
case V_60 :
F_8 ( & V_59 ( V_32 ) -> V_6 ) ;
F_161 ( & V_32 -> V_14 ,
V_59 ( V_32 ) ,
V_60 ) ;
break;
case V_64 :
V_63 ( V_32 ) -> V_38 &= ~ V_66 ;
if ( V_63 ( V_32 ) -> V_38 & V_124 &&
! F_98 ( & V_63 ( V_32 ) -> V_125 ) )
V_32 -> V_14 . V_20 -> V_54 -- ;
F_186 ( & V_32 -> V_14 , V_63 ( V_32 ) ,
V_64 , V_33 ) ;
F_20 ( V_32 ) ;
break;
case V_67 :
F_186 ( & V_32 -> V_14 , V_63 ( V_32 ) ,
V_67 , V_33 ) ;
break;
case V_329 :
V_365 = (struct V_331 * ) V_32 -> V_196 ;
V_365 -> V_62 -> V_40 -> V_367 ( V_365 -> V_62 , & V_365 -> V_294 ) ;
F_222 ( & V_32 -> V_14 , V_365 -> V_62 ,
& V_365 -> V_294 ,
V_329 , 0 ) ;
F_20 ( V_32 ) ;
break;
case V_354 :
V_365 = (struct V_331 * ) V_32 -> V_196 ;
F_222 ( & V_32 -> V_14 , V_365 -> V_62 ,
& V_365 -> V_294 ,
V_354 , 0 ) ;
V_365 -> V_62 -> V_40 -> remove ( V_365 -> V_62 , & V_365 -> V_294 ) ;
F_237 ( & V_365 -> V_62 -> V_352 ) ;
V_365 -> V_62 -> V_353 -- ;
break;
}
}
F_131 () ;
F_97 (trans, next, &net->nft.commit_list, list) {
F_21 ( & V_32 -> V_6 ) ;
F_246 ( V_32 ) ;
}
F_243 ( V_1 , V_16 , V_363 ) ;
return 0 ;
}
static void F_249 ( struct V_29 * V_32 )
{
switch ( V_32 -> V_30 ) {
case V_45 :
F_101 ( & V_32 -> V_14 ) ;
break;
case V_51 :
F_133 ( V_32 -> V_14 . V_22 ) ;
break;
case V_219 :
F_164 ( & V_32 -> V_14 , V_59 ( V_32 ) ) ;
break;
case V_64 :
F_193 ( V_63 ( V_32 ) ) ;
break;
case V_329 :
F_228 ( F_224 ( V_32 ) ,
V_331 ( V_32 ) . V_187 ) ;
break;
}
F_22 ( V_32 ) ;
}
static int F_250 ( struct V_1 * V_1 , struct V_15 * V_16 )
{
struct V_29 * V_32 , * V_207 ;
struct V_331 * V_365 ;
F_251 (trans, next, &net->nft.commit_list,
list) {
switch ( V_32 -> V_30 ) {
case V_45 :
if ( F_91 ( V_32 ) ) {
if ( F_90 ( V_32 ) ) {
F_88 ( V_32 -> V_14 . V_3 ,
V_32 -> V_14 . V_20 ) ;
V_32 -> V_14 . V_20 -> V_38 |= V_41 ;
}
F_20 ( V_32 ) ;
} else {
F_8 ( & V_32 -> V_14 . V_20 -> V_6 ) ;
}
break;
case V_49 :
F_4 ( & V_32 -> V_14 . V_20 -> V_6 ,
& V_32 -> V_14 . V_3 -> V_4 ) ;
F_20 ( V_32 ) ;
break;
case V_51 :
if ( F_137 ( V_32 ) ) {
F_132 ( F_136 ( V_32 ) ) ;
F_20 ( V_32 ) ;
} else {
V_32 -> V_14 . V_20 -> V_54 -- ;
F_8 ( & V_32 -> V_14 . V_22 -> V_6 ) ;
F_29 ( V_32 -> V_14 . V_20 ,
V_32 -> V_14 . V_22 ,
V_32 -> V_14 . V_3 -> V_108 ) ;
}
break;
case V_53 :
V_32 -> V_14 . V_20 -> V_54 ++ ;
F_4 ( & V_32 -> V_14 . V_22 -> V_6 ,
& V_32 -> V_14 . V_20 -> V_118 ) ;
F_20 ( V_32 ) ;
break;
case V_219 :
V_32 -> V_14 . V_22 -> V_54 -- ;
F_8 ( & V_59 ( V_32 ) -> V_6 ) ;
break;
case V_60 :
V_32 -> V_14 . V_22 -> V_54 ++ ;
F_41 ( V_32 -> V_14 . V_1 , V_59 ( V_32 ) ) ;
F_20 ( V_32 ) ;
break;
case V_64 :
V_32 -> V_14 . V_20 -> V_54 -- ;
F_8 ( & V_63 ( V_32 ) -> V_6 ) ;
break;
case V_67 :
V_32 -> V_14 . V_20 -> V_54 ++ ;
F_4 ( & V_63 ( V_32 ) -> V_6 ,
& V_32 -> V_14 . V_20 -> V_119 ) ;
F_20 ( V_32 ) ;
break;
case V_329 :
V_365 = (struct V_331 * ) V_32 -> V_196 ;
V_365 -> V_62 -> V_40 -> remove ( V_365 -> V_62 , & V_365 -> V_294 ) ;
F_237 ( & V_365 -> V_62 -> V_352 ) ;
break;
case V_354 :
V_365 = (struct V_331 * ) V_32 -> V_196 ;
V_365 -> V_62 -> V_40 -> V_367 ( V_365 -> V_62 , & V_365 -> V_294 ) ;
V_365 -> V_62 -> V_353 -- ;
F_20 ( V_32 ) ;
break;
}
}
F_131 () ;
F_251 (trans, next,
&net->nft.commit_list, list) {
F_21 ( & V_32 -> V_6 ) ;
F_249 ( V_32 ) ;
}
return 0 ;
}
int F_252 ( const struct V_21 * V_22 ,
enum V_368 type )
{
const struct V_34 * V_35 ;
if ( V_22 -> V_38 & V_42 ) {
V_35 = V_34 ( V_22 ) ;
if ( V_35 -> type -> type != type )
return - V_113 ;
}
return 0 ;
}
int F_253 ( const struct V_21 * V_22 ,
unsigned int V_369 )
{
struct V_34 * V_35 ;
if ( V_22 -> V_38 & V_42 ) {
V_35 = V_34 ( V_22 ) ;
if ( ( 1 << V_35 -> V_40 [ 0 ] . V_150 ) & V_369 )
return 0 ;
return - V_113 ;
}
return 0 ;
}
static int F_254 ( const struct V_13 * V_14 ,
const struct V_61 * V_62 ,
const struct V_291 * V_292 ,
const struct V_293 * V_294 )
{
const struct V_295 * V_296 = F_197 ( V_62 , V_294 -> V_187 ) ;
const struct V_341 * V_196 ;
if ( F_208 ( V_296 , V_313 ) &&
* F_210 ( V_296 ) & V_343 )
return 0 ;
V_196 = F_200 ( V_296 ) ;
switch ( V_196 -> V_370 . V_371 ) {
case V_372 :
case V_373 :
return F_255 ( V_14 , V_196 -> V_370 . V_22 ) ;
default:
return 0 ;
}
}
static int F_255 ( const struct V_13 * V_14 ,
const struct V_21 * V_22 )
{
const struct V_55 * V_56 ;
const struct V_193 * V_194 , * V_374 ;
const struct V_61 * V_62 ;
struct V_299 * V_300 ;
struct V_291 V_292 ;
if ( V_14 -> V_22 == V_22 )
return - V_375 ;
F_10 (rule, &chain->rules, list) {
F_159 (expr, last, rule) {
const struct V_341 * V_196 = NULL ;
int V_48 ;
if ( ! V_194 -> V_40 -> V_376 )
continue;
V_48 = V_194 -> V_40 -> V_376 ( V_14 , V_194 , & V_196 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_196 == NULL )
continue;
switch ( V_196 -> V_370 . V_371 ) {
case V_372 :
case V_373 :
V_48 = F_255 ( V_14 ,
V_196 -> V_370 . V_22 ) ;
if ( V_48 < 0 )
return V_48 ;
default:
break;
}
}
}
F_10 (set, &ctx->table->sets, list) {
if ( ! ( V_62 -> V_38 & V_243 ) ||
V_62 -> V_263 != V_287 )
continue;
F_10 (binding, &set->bindings, list) {
if ( ! ( V_300 -> V_38 & V_243 ) ||
V_300 -> V_22 != V_22 )
continue;
V_292 . V_302 = 0 ;
V_292 . V_303 = 0 ;
V_292 . V_48 = 0 ;
V_292 . V_304 = F_254 ;
V_62 -> V_40 -> V_305 ( V_14 , V_62 , & V_292 ) ;
if ( V_292 . V_48 < 0 )
return V_292 . V_48 ;
}
}
return 0 ;
}
unsigned int F_256 ( const struct V_23 * V_159 )
{
unsigned int V_377 ;
V_377 = F_48 ( F_49 ( V_159 ) ) ;
switch ( V_377 ) {
case V_378 ... V_379 :
return V_377 * V_380 / V_381 ;
default:
return V_377 + V_380 / V_381 - V_382 ;
}
}
int F_257 ( struct V_15 * V_16 , unsigned int V_159 , unsigned int V_377 )
{
if ( V_377 % ( V_380 / V_381 ) == 0 )
V_377 = V_377 / ( V_380 / V_381 ) ;
else
V_377 = V_377 - V_380 / V_381 + V_382 ;
return F_64 ( V_16 , V_159 , F_65 ( V_377 ) ) ;
}
int F_258 ( enum V_297 V_377 , unsigned int V_99 )
{
if ( V_377 < V_383 * V_380 / V_381 )
return - V_69 ;
if ( V_99 == 0 )
return - V_69 ;
if ( V_377 * V_381 + V_99 > F_259 ( struct V_384 , V_196 ) )
return - V_385 ;
return 0 ;
}
int F_199 ( const struct V_13 * V_14 ,
enum V_297 V_377 ,
const struct V_341 * V_196 ,
enum V_386 type , unsigned int V_99 )
{
int V_48 ;
switch ( V_377 ) {
case V_378 :
if ( type != V_287 )
return - V_69 ;
if ( V_196 != NULL &&
( V_196 -> V_370 . V_371 == V_373 ||
V_196 -> V_370 . V_371 == V_372 ) ) {
V_48 = F_255 ( V_14 , V_196 -> V_370 . V_22 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_14 -> V_22 -> V_387 + 1 >
V_196 -> V_370 . V_22 -> V_387 ) {
if ( V_14 -> V_22 -> V_387 + 1 == V_388 )
return - V_389 ;
V_196 -> V_370 . V_22 -> V_387 = V_14 -> V_22 -> V_387 + 1 ;
}
}
return 0 ;
default:
if ( V_377 < V_383 * V_380 / V_381 )
return - V_69 ;
if ( V_99 == 0 )
return - V_69 ;
if ( V_377 * V_381 + V_99 >
F_259 ( struct V_384 , V_196 ) )
return - V_385 ;
if ( V_196 != NULL && type != V_282 )
return - V_69 ;
return 0 ;
}
}
static int F_260 ( const struct V_13 * V_14 , struct V_341 * V_196 ,
struct V_338 * V_234 , const struct V_23 * V_24 )
{
struct V_23 * V_160 [ V_390 + 1 ] ;
struct V_21 * V_22 ;
int V_48 ;
V_48 = F_121 ( V_160 , V_390 , V_24 , V_391 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( ! V_160 [ V_392 ] )
return - V_69 ;
V_196 -> V_370 . V_371 = F_48 ( F_49 ( V_160 [ V_392 ] ) ) ;
switch ( V_196 -> V_370 . V_371 ) {
default:
switch ( V_196 -> V_370 . V_371 & V_393 ) {
case V_170 :
case V_173 :
case V_394 :
break;
default:
return - V_69 ;
}
case V_395 :
case V_396 :
case V_397 :
break;
case V_372 :
case V_373 :
if ( ! V_160 [ V_398 ] )
return - V_69 ;
V_22 = F_106 ( V_14 -> V_20 ,
V_160 [ V_398 ] ) ;
if ( F_83 ( V_22 ) )
return F_84 ( V_22 ) ;
if ( V_22 -> V_38 & V_42 )
return - V_113 ;
V_22 -> V_54 ++ ;
V_196 -> V_370 . V_22 = V_22 ;
break;
}
V_234 -> V_99 = sizeof( V_196 -> V_370 ) ;
V_234 -> type = V_287 ;
return 0 ;
}
static void F_261 ( const struct V_341 * V_196 )
{
switch ( V_196 -> V_370 . V_371 ) {
case V_372 :
case V_373 :
V_196 -> V_370 . V_22 -> V_54 -- ;
break;
}
}
int F_262 ( struct V_15 * V_16 , int type , const struct V_288 * V_399 )
{
struct V_23 * V_135 ;
V_135 = F_112 ( V_16 , type ) ;
if ( ! V_135 )
goto V_78;
if ( F_64 ( V_16 , V_392 , F_65 ( V_399 -> V_371 ) ) )
goto V_78;
switch ( V_399 -> V_371 ) {
case V_372 :
case V_373 :
if ( F_63 ( V_16 , V_398 ,
V_399 -> V_22 -> V_68 ) )
goto V_78;
}
F_115 ( V_16 , V_135 ) ;
return 0 ;
V_78:
return - 1 ;
}
static int F_263 ( const struct V_13 * V_14 ,
struct V_341 * V_196 , unsigned int V_31 ,
struct V_338 * V_234 , const struct V_23 * V_24 )
{
unsigned int V_99 ;
V_99 = F_57 ( V_24 ) ;
if ( V_99 == 0 )
return - V_69 ;
if ( V_99 > V_31 )
return - V_176 ;
F_171 ( V_196 -> V_196 , V_24 , V_99 ) ;
V_234 -> type = V_282 ;
V_234 -> V_99 = V_99 ;
return 0 ;
}
static int F_264 ( struct V_15 * V_16 , const struct V_341 * V_196 ,
unsigned int V_99 )
{
return F_160 ( V_16 , V_400 , V_99 , V_196 -> V_196 ) ;
}
int F_233 ( const struct V_13 * V_14 ,
struct V_341 * V_196 , unsigned int V_31 ,
struct V_338 * V_234 , const struct V_23 * V_24 )
{
struct V_23 * V_160 [ V_401 + 1 ] ;
int V_48 ;
V_48 = F_121 ( V_160 , V_401 , V_24 , V_402 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_160 [ V_400 ] )
return F_263 ( V_14 , V_196 , V_31 , V_234 ,
V_160 [ V_400 ] ) ;
if ( V_160 [ V_403 ] && V_14 != NULL )
return F_260 ( V_14 , V_196 , V_234 , V_160 [ V_403 ] ) ;
return - V_69 ;
}
void F_229 ( const struct V_341 * V_196 , enum V_386 type )
{
if ( type < V_287 )
return;
switch ( type ) {
case V_287 :
return F_261 ( V_196 ) ;
default:
F_265 ( 1 ) ;
}
}
int F_206 ( struct V_15 * V_16 , int V_159 , const struct V_341 * V_196 ,
enum V_386 type , unsigned int V_99 )
{
struct V_23 * V_135 ;
int V_48 ;
V_135 = F_112 ( V_16 , V_159 ) ;
if ( V_135 == NULL )
return - 1 ;
switch ( type ) {
case V_282 :
V_48 = F_264 ( V_16 , V_196 , V_99 ) ;
break;
case V_287 :
V_48 = F_262 ( V_16 , V_403 , & V_196 -> V_370 ) ;
break;
default:
V_48 = - V_69 ;
F_265 ( 1 ) ;
}
F_115 ( V_16 , V_135 ) ;
return V_48 ;
}
static int T_8 F_266 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_7 . V_8 ) ;
F_2 ( & V_1 -> V_7 . V_47 ) ;
V_1 -> V_7 . V_83 = 1 ;
return 0 ;
}
int F_267 ( struct V_13 * V_14 )
{
struct V_55 * V_56 , * V_404 ;
F_102 ( ! ( V_14 -> V_22 -> V_38 & V_42 ) ) ;
F_29 ( V_14 -> V_22 -> V_20 , V_14 -> V_22 ,
V_14 -> V_3 -> V_108 ) ;
F_97 (rule, nr, &ctx->chain->rules, list) {
F_21 ( & V_56 -> V_6 ) ;
V_14 -> V_22 -> V_54 -- ;
F_164 ( V_14 , V_56 ) ;
}
F_21 ( & V_14 -> V_22 -> V_6 ) ;
V_14 -> V_20 -> V_54 -- ;
F_133 ( V_14 -> V_22 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_19 * V_20 , * V_126 ;
struct V_21 * V_22 , * V_121 ;
struct V_55 * V_56 , * V_404 ;
struct V_61 * V_62 , * V_122 ;
struct V_13 V_14 = {
. V_1 = V_1 ,
. V_3 = V_3 ,
} ;
F_97 (table, nt, &afi->tables, list) {
F_10 (chain, &table->chains, list)
F_29 ( V_20 , V_22 , V_3 -> V_108 ) ;
V_14 . V_20 = V_20 ;
F_10 (chain, &table->chains, list) {
V_14 . V_22 = V_22 ;
F_97 (rule, nr, &chain->rules, list) {
F_21 ( & V_56 -> V_6 ) ;
V_22 -> V_54 -- ;
F_164 ( & V_14 , V_56 ) ;
}
}
F_97 (set, ns, &table->sets, list) {
F_21 ( & V_62 -> V_6 ) ;
V_20 -> V_54 -- ;
F_193 ( V_62 ) ;
}
F_97 (chain, nc, &table->chains, list) {
F_21 ( & V_22 -> V_6 ) ;
V_20 -> V_54 -- ;
F_133 ( V_22 ) ;
}
F_21 ( & V_20 -> V_6 ) ;
F_101 ( & V_14 ) ;
}
}
static int T_9 F_268 ( void )
{
int V_48 ;
V_199 = F_190 ( sizeof( struct V_198 ) * V_228 ,
V_33 ) ;
if ( V_199 == NULL ) {
V_48 = - V_44 ;
goto V_115;
}
V_48 = F_269 () ;
if ( V_48 < 0 )
goto V_116;
V_48 = F_270 ( & V_405 ) ;
if ( V_48 < 0 )
goto V_120;
F_271 ( L_6 ) ;
return F_272 ( & V_406 ) ;
V_120:
F_273 () ;
V_116:
F_22 ( V_199 ) ;
V_115:
return V_48 ;
}
static void T_10 F_274 ( void )
{
F_275 ( & V_406 ) ;
F_276 ( & V_405 ) ;
F_277 () ;
F_273 () ;
F_22 ( V_199 ) ;
}
