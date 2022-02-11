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
if ( F_113 ( V_16 , V_141 , F_114 ( V_134 . V_136 ) ,
V_142 ) ||
F_113 ( V_16 , V_143 , F_114 ( V_134 . V_137 ) ,
V_142 ) )
goto V_78;
F_115 ( V_16 , V_135 ) ;
return 0 ;
V_78:
return - V_144 ;
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
if ( F_63 ( V_16 , V_145 , V_20 -> V_68 ) )
goto V_78;
if ( F_113 ( V_16 , V_146 , F_114 ( V_22 -> V_130 ) ,
V_147 ) )
goto V_78;
if ( F_63 ( V_16 , V_148 , V_22 -> V_68 ) )
goto V_78;
if ( V_22 -> V_38 & V_42 ) {
const struct V_34 * V_35 = V_34 ( V_22 ) ;
const struct V_149 * V_40 = & V_35 -> V_40 [ 0 ] ;
struct V_23 * V_135 ;
V_135 = F_112 ( V_16 , V_150 ) ;
if ( V_135 == NULL )
goto V_78;
if ( F_64 ( V_16 , V_151 , F_65 ( V_40 -> V_152 ) ) )
goto V_78;
if ( F_64 ( V_16 , V_153 , F_65 ( V_40 -> V_154 ) ) )
goto V_78;
if ( V_35 -> V_155 [ 0 ] &&
F_63 ( V_16 , V_156 , V_35 -> V_155 ) )
goto V_78;
F_115 ( V_16 , V_135 ) ;
if ( F_64 ( V_16 , V_157 ,
F_65 ( V_35 -> V_158 ) ) )
goto V_78;
if ( F_63 ( V_16 , V_159 , V_35 -> type -> V_68 ) )
goto V_78;
if ( F_107 ( V_16 , V_34 ( V_22 ) -> V_132 ) )
goto V_78;
}
if ( F_64 ( V_16 , V_160 , F_65 ( V_22 -> V_54 ) ) )
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
V_20 = F_53 ( V_3 , V_24 [ V_145 ] ) ;
if ( F_83 ( V_20 ) )
return F_84 ( V_20 ) ;
if ( V_20 -> V_38 & V_46 )
return - V_58 ;
V_22 = F_106 ( V_20 , V_24 [ V_148 ] ) ;
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
static struct V_131 T_3 * F_120 ( const struct V_23 * V_161 )
{
struct V_23 * V_162 [ V_163 + 1 ] ;
struct V_131 T_3 * V_164 ;
struct V_131 * V_132 ;
int V_48 ;
V_48 = F_121 ( V_162 , V_163 , V_161 , V_165 ) ;
if ( V_48 < 0 )
return F_14 ( V_48 ) ;
if ( ! V_162 [ V_143 ] || ! V_162 [ V_141 ] )
return F_14 ( - V_69 ) ;
V_164 = F_122 ( struct V_131 ) ;
if ( V_164 == NULL )
return F_14 ( - V_44 ) ;
F_123 () ;
V_132 = F_124 ( V_164 ) ;
V_132 -> V_137 = F_125 ( F_126 ( V_162 [ V_143 ] ) ) ;
V_132 -> V_136 = F_125 ( F_126 ( V_162 [ V_141 ] ) ) ;
F_127 () ;
return V_164 ;
}
static void F_128 ( struct V_34 * V_22 ,
struct V_131 T_3 * V_164 )
{
if ( V_164 == NULL )
return;
if ( V_22 -> V_132 ) {
struct V_131 T_3 * V_166 =
F_129 ( V_22 -> V_132 ) ;
F_130 ( V_22 -> V_132 , V_164 ) ;
F_131 () ;
F_132 ( V_166 ) ;
} else
F_130 ( V_22 -> V_132 , V_164 ) ;
}
static void F_133 ( struct V_21 * V_22 )
{
F_102 ( V_22 -> V_54 > 0 ) ;
if ( V_22 -> V_38 & V_42 ) {
struct V_34 * V_35 = V_34 ( V_22 ) ;
F_95 ( V_35 -> type -> V_114 ) ;
F_132 ( V_35 -> V_132 ) ;
if ( V_35 -> V_40 [ 0 ] . V_167 != NULL )
F_134 ( V_35 -> V_40 [ 0 ] . V_167 ) ;
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
const struct V_23 * V_168 ( V_68 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_34 * V_35 = NULL ;
struct V_23 * V_169 [ V_170 + 1 ] ;
int V_9 = V_77 -> V_79 ;
struct V_171 * V_167 = NULL ;
T_4 V_158 = V_172 ;
T_2 V_130 = 0 ;
unsigned int V_72 ;
struct V_131 T_3 * V_132 ;
int V_48 ;
bool V_173 ;
struct V_13 V_14 ;
V_173 = V_18 -> V_103 & V_174 ? true : false ;
V_3 = F_11 ( V_1 , V_9 , true ) ;
if ( F_83 ( V_3 ) )
return F_84 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_145 ] ) ;
if ( F_83 ( V_20 ) )
return F_84 ( V_20 ) ;
V_22 = NULL ;
V_68 = V_24 [ V_148 ] ;
if ( V_24 [ V_146 ] ) {
V_130 = F_125 ( F_126 ( V_24 [ V_146 ] ) ) ;
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
if ( V_24 [ V_157 ] ) {
if ( ( V_22 != NULL &&
! ( V_22 -> V_38 & V_42 ) ) )
return - V_113 ;
if ( V_22 == NULL &&
V_24 [ V_150 ] == NULL )
return - V_113 ;
V_158 = F_48 ( F_49 ( V_24 [ V_157 ] ) ) ;
switch ( V_158 ) {
case V_175 :
case V_172 :
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
if ( V_24 [ V_146 ] && V_68 &&
! F_83 ( F_106 ( V_20 , V_24 [ V_148 ] ) ) )
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
if ( V_24 [ V_157 ] )
F_138 ( V_32 ) = V_158 ;
else
F_138 ( V_32 ) = - 1 ;
if ( V_24 [ V_146 ] && V_68 ) {
F_94 ( F_139 ( V_32 ) , V_68 ,
V_176 ) ;
}
F_31 ( & V_32 -> V_6 , & V_1 -> V_7 . V_47 ) ;
return 0 ;
}
if ( V_20 -> V_54 == V_177 )
return - V_178 ;
if ( V_24 [ V_150 ] ) {
const struct V_71 * type ;
struct V_149 * V_40 ;
T_5 * V_179 ;
T_1 V_152 , V_154 ;
type = V_74 [ V_9 ] [ V_180 ] ;
if ( V_24 [ V_159 ] ) {
type = F_56 ( V_3 ,
V_24 [ V_159 ] ,
V_173 ) ;
if ( F_83 ( type ) )
return F_84 ( type ) ;
}
V_48 = F_121 ( V_169 , V_170 , V_24 [ V_150 ] ,
V_181 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_169 [ V_151 ] == NULL ||
V_169 [ V_153 ] == NULL )
return - V_69 ;
V_152 = F_48 ( F_49 ( V_169 [ V_151 ] ) ) ;
if ( V_152 >= V_3 -> V_182 )
return - V_69 ;
V_154 = F_48 ( F_49 ( V_169 [ V_153 ] ) ) ;
if ( ! ( type -> V_183 & ( 1 << V_152 ) ) )
return - V_113 ;
if ( ! F_93 ( type -> V_114 ) )
return - V_58 ;
V_179 = type -> V_184 [ V_152 ] ;
if ( V_3 -> V_38 & V_185 ) {
char V_186 [ V_187 ] ;
if ( ! V_169 [ V_156 ] ) {
F_95 ( type -> V_114 ) ;
return - V_113 ;
}
F_94 ( V_186 , V_169 [ V_156 ] , V_187 ) ;
V_167 = F_140 ( V_1 , V_186 ) ;
if ( ! V_167 ) {
F_95 ( type -> V_114 ) ;
return - V_58 ;
}
} else if ( V_169 [ V_156 ] ) {
F_95 ( type -> V_114 ) ;
return - V_113 ;
}
V_35 = F_19 ( sizeof( * V_35 ) , V_33 ) ;
if ( V_35 == NULL ) {
F_95 ( type -> V_114 ) ;
if ( V_167 != NULL )
F_134 ( V_167 ) ;
return - V_44 ;
}
if ( V_167 != NULL )
strncpy ( V_35 -> V_155 , V_167 -> V_68 , V_187 ) ;
if ( V_24 [ V_140 ] ) {
V_132 = F_120 ( V_24 [ V_140 ] ) ;
if ( F_83 ( V_132 ) ) {
F_95 ( type -> V_114 ) ;
F_22 ( V_35 ) ;
if ( V_167 != NULL )
F_134 ( V_167 ) ;
return F_84 ( V_132 ) ;
}
V_35 -> V_132 = V_132 ;
} else {
V_132 = F_122 ( struct V_131 ) ;
if ( V_132 == NULL ) {
F_95 ( type -> V_114 ) ;
F_22 ( V_35 ) ;
if ( V_167 != NULL )
F_134 ( V_167 ) ;
return - V_44 ;
}
F_130 ( V_35 -> V_132 , V_132 ) ;
}
F_141 ( & V_35 -> V_37 , V_1 ) ;
V_35 -> type = type ;
V_22 = & V_35 -> V_22 ;
for ( V_72 = 0 ; V_72 < V_3 -> V_108 ; V_72 ++ ) {
V_40 = & V_35 -> V_40 [ V_72 ] ;
V_40 -> V_188 = V_9 ;
V_40 -> V_152 = V_152 ;
V_40 -> V_154 = V_154 ;
V_40 -> V_189 = V_22 ;
V_40 -> V_190 = V_3 -> V_184 [ V_40 -> V_152 ] ;
V_40 -> V_167 = V_167 ;
if ( V_179 )
V_40 -> V_190 = V_179 ;
if ( V_3 -> V_191 )
V_3 -> V_191 ( V_40 , V_72 ) ;
}
V_22 -> V_38 |= V_42 ;
V_35 -> V_158 = V_158 ;
} else {
V_22 = F_19 ( sizeof( * V_22 ) , V_33 ) ;
if ( V_22 == NULL )
return - V_44 ;
}
F_2 ( & V_22 -> V_192 ) ;
V_22 -> V_130 = F_54 ( V_20 ) ;
V_22 -> V_20 = V_20 ;
F_94 ( V_22 -> V_68 , V_68 , V_176 ) ;
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
V_20 = F_53 ( V_3 , V_24 [ V_145 ] ) ;
if ( F_83 ( V_20 ) )
return F_84 ( V_20 ) ;
V_22 = F_106 ( V_20 , V_24 [ V_148 ] ) ;
if ( F_83 ( V_22 ) )
return F_84 ( V_22 ) ;
if ( V_22 -> V_54 > 0 )
return - V_129 ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
return F_34 ( & V_14 ) ;
}
int F_143 ( struct V_193 * type )
{
F_3 ( V_5 ) ;
if ( type -> V_9 == V_95 )
F_4 ( & type -> V_6 , & V_194 ) ;
else
F_144 ( & type -> V_6 , & V_194 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_145 ( struct V_193 * type )
{
F_3 ( V_5 ) ;
F_8 ( & type -> V_6 ) ;
F_5 ( V_5 ) ;
}
static const struct V_193 * F_146 ( T_4 V_9 ,
struct V_23 * V_24 )
{
const struct V_193 * type ;
F_10 (type, &nf_tables_expressions, list) {
if ( ! F_52 ( V_24 , type -> V_68 ) &&
( ! type -> V_9 || type -> V_9 == V_9 ) )
return type ;
}
return NULL ;
}
static const struct V_193 * F_147 ( T_4 V_9 ,
struct V_23 * V_24 )
{
const struct V_193 * type ;
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
const struct V_195 * V_196 )
{
if ( F_63 ( V_16 , V_197 , V_196 -> V_40 -> type -> V_68 ) )
goto V_78;
if ( V_196 -> V_40 -> V_107 ) {
struct V_23 * V_198 = F_112 ( V_16 , V_199 ) ;
if ( V_198 == NULL )
goto V_78;
if ( V_196 -> V_40 -> V_107 ( V_16 , V_196 ) < 0 )
goto V_78;
F_115 ( V_16 , V_198 ) ;
}
return V_16 -> V_99 ;
V_78:
return - 1 ;
}
int F_149 ( struct V_15 * V_16 , unsigned int V_161 ,
const struct V_195 * V_196 )
{
struct V_23 * V_135 ;
V_135 = F_112 ( V_16 , V_161 ) ;
if ( ! V_135 )
goto V_78;
if ( F_148 ( V_16 , V_196 ) < 0 )
goto V_78;
F_115 ( V_16 , V_135 ) ;
return 0 ;
V_78:
return - 1 ;
}
static int F_150 ( const struct V_13 * V_14 ,
const struct V_23 * V_24 ,
struct V_200 * V_201 )
{
const struct V_193 * type ;
const struct V_202 * V_40 ;
struct V_23 * V_162 [ V_203 + 1 ] ;
int V_48 ;
V_48 = F_121 ( V_162 , V_203 , V_24 , V_204 ) ;
if ( V_48 < 0 )
return V_48 ;
type = F_147 ( V_14 -> V_3 -> V_9 , V_162 [ V_197 ] ) ;
if ( F_83 ( type ) )
return F_84 ( type ) ;
if ( V_162 [ V_199 ] ) {
V_48 = F_121 ( V_201 -> V_162 , type -> V_205 ,
V_162 [ V_199 ] , type -> V_158 ) ;
if ( V_48 < 0 )
goto V_115;
} else
memset ( V_201 -> V_162 , 0 , sizeof( V_201 -> V_162 [ 0 ] ) * ( type -> V_205 + 1 ) ) ;
if ( type -> V_206 != NULL ) {
V_40 = type -> V_206 ( V_14 ,
( const struct V_23 * const * ) V_201 -> V_162 ) ;
if ( F_83 ( V_40 ) ) {
V_48 = F_84 ( V_40 ) ;
goto V_115;
}
} else
V_40 = type -> V_40 ;
V_201 -> V_40 = V_40 ;
return 0 ;
V_115:
F_95 ( type -> V_114 ) ;
return V_48 ;
}
static int F_151 ( const struct V_13 * V_14 ,
const struct V_200 * V_201 ,
struct V_195 * V_196 )
{
const struct V_202 * V_40 = V_201 -> V_40 ;
int V_48 ;
V_196 -> V_40 = V_40 ;
if ( V_40 -> V_207 ) {
V_48 = V_40 -> V_207 ( V_14 , V_196 , ( const struct V_23 * * ) V_201 -> V_162 ) ;
if ( V_48 < 0 )
goto V_115;
}
return 0 ;
V_115:
V_196 -> V_40 = NULL ;
return V_48 ;
}
static void F_152 ( const struct V_13 * V_14 ,
struct V_195 * V_196 )
{
if ( V_196 -> V_40 -> V_208 )
V_196 -> V_40 -> V_208 ( V_14 , V_196 ) ;
F_95 ( V_196 -> V_40 -> type -> V_114 ) ;
}
struct V_195 * F_153 ( const struct V_13 * V_14 ,
const struct V_23 * V_24 )
{
struct V_200 V_201 ;
struct V_195 * V_196 ;
int V_48 ;
V_48 = F_150 ( V_14 , V_24 , & V_201 ) ;
if ( V_48 < 0 )
goto V_115;
V_48 = - V_44 ;
V_196 = F_19 ( V_201 . V_40 -> V_31 , V_33 ) ;
if ( V_196 == NULL )
goto V_116;
V_48 = F_151 ( V_14 , & V_201 , V_196 ) ;
if ( V_48 < 0 )
goto V_120;
return V_196 ;
V_120:
F_22 ( V_196 ) ;
V_116:
F_95 ( V_201 . V_40 -> type -> V_114 ) ;
V_115:
return F_14 ( V_48 ) ;
}
void F_154 ( const struct V_13 * V_14 , struct V_195 * V_196 )
{
F_152 ( V_14 , V_196 ) ;
F_22 ( V_196 ) ;
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
const struct V_195 * V_196 , * V_209 ;
struct V_23 * V_6 ;
const struct V_55 * V_210 ;
int type = V_75 | V_5 << 8 ;
V_18 = F_60 ( V_16 , V_25 , V_27 , type , sizeof( struct V_76 ) ,
V_38 ) ;
if ( V_18 == NULL )
goto V_78;
V_77 = F_61 ( V_18 ) ;
V_77 -> V_79 = V_9 ;
V_77 -> V_80 = V_81 ;
V_77 -> V_82 = F_62 ( V_1 -> V_7 . V_83 & 0xffff ) ;
if ( F_63 ( V_16 , V_211 , V_20 -> V_68 ) )
goto V_78;
if ( F_63 ( V_16 , V_212 , V_22 -> V_68 ) )
goto V_78;
if ( F_113 ( V_16 , V_213 , F_114 ( V_56 -> V_130 ) ,
V_214 ) )
goto V_78;
if ( ( V_75 != V_60 ) && ( V_56 -> V_6 . V_215 != & V_22 -> V_192 ) ) {
V_210 = F_158 ( V_56 -> V_6 . V_215 , struct V_55 , V_6 ) ;
if ( F_113 ( V_16 , V_216 ,
F_114 ( V_210 -> V_130 ) ,
V_214 ) )
goto V_78;
}
V_6 = F_112 ( V_16 , V_217 ) ;
if ( V_6 == NULL )
goto V_78;
F_159 (expr, next, rule) {
if ( F_149 ( V_16 , V_218 , V_196 ) < 0 )
goto V_78;
}
F_115 ( V_16 , V_6 ) ;
if ( V_56 -> V_219 ) {
struct V_220 * V_219 = V_220 ( V_56 ) ;
if ( F_160 ( V_16 , V_221 , V_219 -> V_99 + 1 ,
V_219 -> V_198 ) < 0 )
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
V_222 ,
V_97 | V_223 ,
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
V_20 = F_53 ( V_3 , V_24 [ V_211 ] ) ;
if ( F_83 ( V_20 ) )
return F_84 ( V_20 ) ;
if ( V_20 -> V_38 & V_46 )
return - V_58 ;
V_22 = F_106 ( V_20 , V_24 [ V_212 ] ) ;
if ( F_83 ( V_22 ) )
return F_84 ( V_22 ) ;
if ( V_22 -> V_38 & V_52 )
return - V_58 ;
V_56 = F_156 ( V_22 , V_24 [ V_213 ] ) ;
if ( F_83 ( V_56 ) )
return F_84 ( V_56 ) ;
V_102 = F_85 ( V_89 , V_33 ) ;
if ( ! V_102 )
return - V_44 ;
V_48 = F_157 ( V_102 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 , V_222 , 0 ,
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
struct V_195 * V_196 ;
V_196 = F_165 ( V_56 ) ;
while ( V_196 -> V_40 && V_196 != F_166 ( V_56 ) ) {
F_152 ( V_14 , V_196 ) ;
V_196 = F_167 ( V_196 ) ;
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
struct V_55 * V_56 , * V_224 = NULL ;
struct V_220 * V_219 ;
struct V_29 * V_32 = NULL ;
struct V_195 * V_196 ;
struct V_13 V_14 ;
struct V_23 * V_225 ;
unsigned int V_31 , V_72 , V_226 , V_227 = 0 , V_228 = 0 ;
int V_48 , V_229 ;
bool V_173 ;
T_2 V_130 , V_230 ;
V_173 = V_18 -> V_103 & V_174 ? true : false ;
V_3 = F_11 ( V_1 , V_77 -> V_79 , V_173 ) ;
if ( F_83 ( V_3 ) )
return F_84 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_211 ] ) ;
if ( F_83 ( V_20 ) )
return F_84 ( V_20 ) ;
V_22 = F_106 ( V_20 , V_24 [ V_212 ] ) ;
if ( F_83 ( V_22 ) )
return F_84 ( V_22 ) ;
if ( V_24 [ V_213 ] ) {
V_130 = F_125 ( F_126 ( V_24 [ V_213 ] ) ) ;
V_56 = F_155 ( V_22 , V_130 ) ;
if ( F_83 ( V_56 ) )
return F_84 ( V_56 ) ;
if ( V_18 -> V_103 & V_110 )
return - V_111 ;
if ( V_18 -> V_103 & V_112 )
V_224 = V_56 ;
else
return - V_113 ;
} else {
if ( ! V_173 || V_18 -> V_103 & V_112 )
return - V_69 ;
V_130 = F_54 ( V_20 ) ;
if ( V_22 -> V_54 == V_177 )
return - V_178 ;
}
if ( V_24 [ V_216 ] ) {
if ( ! ( V_18 -> V_103 & V_174 ) )
return - V_113 ;
V_230 = F_125 ( F_126 ( V_24 [ V_216 ] ) ) ;
V_224 = F_155 ( V_22 , V_230 ) ;
if ( F_83 ( V_224 ) )
return F_84 ( V_224 ) ;
}
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_226 = 0 ;
V_31 = 0 ;
if ( V_24 [ V_217 ] ) {
F_169 (tmp, nla[NFTA_RULE_EXPRESSIONS], rem) {
V_48 = - V_69 ;
if ( F_170 ( V_225 ) != V_218 )
goto V_115;
if ( V_226 == V_231 )
goto V_115;
V_48 = F_150 ( & V_14 , V_225 , & V_201 [ V_226 ] ) ;
if ( V_48 < 0 )
goto V_115;
V_31 += V_201 [ V_226 ] . V_40 -> V_31 ;
V_226 ++ ;
}
}
V_48 = - V_232 ;
if ( V_31 >= 1 << 12 )
goto V_115;
if ( V_24 [ V_221 ] ) {
V_227 = F_57 ( V_24 [ V_221 ] ) ;
if ( V_227 > 0 )
V_228 = sizeof( struct V_220 ) + V_227 ;
}
V_48 = - V_44 ;
V_56 = F_19 ( sizeof( * V_56 ) + V_31 + V_228 , V_33 ) ;
if ( V_56 == NULL )
goto V_115;
F_39 ( V_1 , V_56 ) ;
V_56 -> V_130 = V_130 ;
V_56 -> V_233 = V_31 ;
V_56 -> V_219 = V_227 ? 1 : 0 ;
if ( V_227 ) {
V_219 = V_220 ( V_56 ) ;
V_219 -> V_99 = V_227 - 1 ;
F_171 ( V_219 -> V_198 , V_24 [ V_221 ] , V_227 ) ;
}
V_196 = F_165 ( V_56 ) ;
for ( V_72 = 0 ; V_72 < V_226 ; V_72 ++ ) {
V_48 = F_151 ( & V_14 , & V_201 [ V_72 ] , V_196 ) ;
if ( V_48 < 0 )
goto V_116;
V_201 [ V_72 ] . V_40 = NULL ;
V_196 = F_167 ( V_196 ) ;
}
if ( V_18 -> V_103 & V_112 ) {
if ( F_37 ( V_1 , V_224 ) ) {
V_32 = F_43 ( & V_14 , V_60 ,
V_224 ) ;
if ( V_32 == NULL ) {
V_48 = - V_44 ;
goto V_116;
}
F_40 ( V_1 , V_224 ) ;
V_22 -> V_54 -- ;
F_4 ( & V_56 -> V_6 , & V_224 -> V_6 ) ;
} else {
V_48 = - V_58 ;
goto V_116;
}
} else if ( V_18 -> V_103 & V_223 )
if ( V_224 )
F_144 ( & V_56 -> V_6 , & V_224 -> V_6 ) ;
else
F_4 ( & V_56 -> V_6 , & V_22 -> V_192 ) ;
else {
if ( V_224 )
F_4 ( & V_56 -> V_6 , & V_224 -> V_6 ) ;
else
F_144 ( & V_56 -> V_6 , & V_22 -> V_192 ) ;
}
if ( F_43 ( & V_14 , V_222 , V_56 ) == NULL ) {
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
for ( V_72 = 0 ; V_72 < V_226 ; V_72 ++ ) {
if ( V_201 [ V_72 ] . V_40 != NULL )
F_95 ( V_201 [ V_72 ] . V_40 -> type -> V_114 ) ;
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
V_20 = F_53 ( V_3 , V_24 [ V_211 ] ) ;
if ( F_83 ( V_20 ) )
return F_84 ( V_20 ) ;
if ( V_24 [ V_212 ] ) {
V_22 = F_106 ( V_20 , V_24 [ V_212 ] ) ;
if ( F_83 ( V_22 ) )
return F_84 ( V_22 ) ;
}
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
if ( V_22 ) {
if ( V_24 [ V_213 ] ) {
V_56 = F_156 ( V_22 ,
V_24 [ V_213 ] ) ;
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
int F_173 ( struct V_234 * V_40 )
{
F_3 ( V_5 ) ;
F_4 ( & V_40 -> V_6 , & V_235 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_174 ( struct V_234 * V_40 )
{
F_3 ( V_5 ) ;
F_8 ( & V_40 -> V_6 ) ;
F_5 ( V_5 ) ;
}
static const struct V_234 *
F_175 ( const struct V_23 * const V_24 [] ,
const struct V_236 * V_237 ,
enum V_238 V_158 )
{
const struct V_234 * V_40 , * V_239 ;
struct V_240 V_241 , V_242 ;
T_1 V_243 ;
#ifdef F_12
if ( F_98 ( & V_235 ) ) {
F_5 ( V_5 ) ;
F_13 ( L_5 ) ;
F_3 ( V_5 ) ;
if ( ! F_98 ( & V_235 ) )
return F_14 ( - V_11 ) ;
}
#endif
V_243 = 0 ;
if ( V_24 [ V_244 ] != NULL ) {
V_243 = F_48 ( F_49 ( V_24 [ V_244 ] ) ) ;
V_243 &= V_245 | V_246 | V_247 ;
}
V_239 = NULL ;
V_242 . V_31 = ~ 0 ;
V_242 . V_248 = ~ 0 ;
F_10 (ops, &nf_tables_set_ops, list) {
if ( ( V_40 -> V_243 & V_243 ) != V_243 )
continue;
if ( ! V_40 -> V_249 ( V_237 , V_243 , & V_241 ) )
continue;
switch ( V_158 ) {
case V_250 :
if ( V_241 . V_248 < V_242 . V_248 )
break;
if ( V_241 . V_248 == V_242 . V_248 && V_241 . V_31 < V_242 . V_31 )
break;
continue;
case V_251 :
if ( V_241 . V_31 < V_242 . V_31 )
break;
if ( V_241 . V_31 == V_242 . V_31 && V_241 . V_248 < V_242 . V_248 )
break;
continue;
default:
break;
}
if ( ! F_93 ( V_40 -> V_114 ) )
continue;
if ( V_239 != NULL )
F_95 ( V_239 -> V_114 ) ;
V_239 = V_40 ;
V_242 = V_241 ;
}
if ( V_239 != NULL )
return V_239 ;
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
if ( V_24 [ V_252 ] != NULL ) {
if ( V_3 == NULL )
return - V_12 ;
V_20 = F_53 ( V_3 , V_24 [ V_252 ] ) ;
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
T_1 V_253 = F_48 ( F_49 ( V_24 ) ) ;
F_10 (trans, &net->nft.commit_list, list) {
if ( V_32 -> V_30 == V_64 &&
V_253 == F_47 ( V_32 ) )
return V_63 ( V_32 ) ;
}
return F_14 ( - V_58 ) ;
}
static int F_179 ( struct V_13 * V_14 , struct V_61 * V_62 ,
const char * V_68 )
{
const struct V_61 * V_72 ;
const char * V_254 ;
unsigned long * V_255 ;
unsigned int V_226 = 0 , V_256 = 0 ;
V_254 = F_180 ( V_68 , V_257 , '%' ) ;
if ( V_254 != NULL ) {
if ( V_254 [ 1 ] != 'd' || strchr ( V_254 + 2 , '%' ) )
return - V_69 ;
V_255 = ( unsigned long * ) F_181 ( V_33 ) ;
if ( V_255 == NULL )
return - V_44 ;
V_96:
F_10 (i, &ctx->table->sets, list) {
int V_225 ;
if ( ! sscanf ( V_72 -> V_68 , V_68 , & V_225 ) )
continue;
if ( V_225 < V_256 || V_225 >= V_256 + V_258 * V_259 )
continue;
F_182 ( V_225 - V_256 , V_255 ) ;
}
V_226 = F_183 ( V_255 , V_258 * V_259 ) ;
if ( V_226 >= V_258 * V_259 ) {
V_256 += V_258 * V_259 ;
memset ( V_255 , 0 , V_259 ) ;
goto V_96;
}
F_184 ( ( unsigned long ) V_255 ) ;
}
snprintf ( V_62 -> V_68 , sizeof( V_62 -> V_68 ) , V_68 , V_256 + V_226 ) ;
F_10 (i, &ctx->table->sets, list) {
if ( ! strcmp ( V_62 -> V_68 , V_72 -> V_68 ) )
return - V_260 ;
}
return 0 ;
}
static int F_185 ( struct V_15 * V_16 , const struct V_13 * V_14 ,
const struct V_61 * V_62 , T_6 V_75 , T_6 V_38 )
{
struct V_76 * V_77 ;
struct V_17 * V_18 ;
struct V_23 * V_237 ;
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
if ( F_63 ( V_16 , V_252 , V_14 -> V_20 -> V_68 ) )
goto V_78;
if ( F_63 ( V_16 , V_261 , V_62 -> V_68 ) )
goto V_78;
if ( V_62 -> V_38 != 0 )
if ( F_64 ( V_16 , V_244 , F_65 ( V_62 -> V_38 ) ) )
goto V_78;
if ( F_64 ( V_16 , V_262 , F_65 ( V_62 -> V_263 ) ) )
goto V_78;
if ( F_64 ( V_16 , V_264 , F_65 ( V_62 -> V_265 ) ) )
goto V_78;
if ( V_62 -> V_38 & V_246 ) {
if ( F_64 ( V_16 , V_266 , F_65 ( V_62 -> V_267 ) ) )
goto V_78;
if ( F_64 ( V_16 , V_268 , F_65 ( V_62 -> V_233 ) ) )
goto V_78;
}
if ( V_62 -> V_269 &&
F_113 ( V_16 , V_270 , F_114 ( V_62 -> V_269 ) ,
V_271 ) )
goto V_78;
if ( V_62 -> V_272 &&
F_64 ( V_16 , V_273 , F_65 ( V_62 -> V_272 ) ) )
goto V_78;
if ( V_62 -> V_158 != V_250 ) {
if ( F_64 ( V_16 , V_274 , F_65 ( V_62 -> V_158 ) ) )
goto V_78;
}
if ( F_160 ( V_16 , V_275 , V_62 -> V_276 , V_62 -> V_219 ) )
goto V_78;
V_237 = F_112 ( V_16 , V_277 ) ;
if ( V_237 == NULL )
goto V_78;
if ( V_62 -> V_31 &&
F_64 ( V_16 , V_278 , F_65 ( V_62 -> V_31 ) ) )
goto V_78;
F_115 ( V_16 , V_237 ) ;
F_66 ( V_16 , V_18 ) ;
return 0 ;
V_78:
F_67 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_186 ( const struct V_13 * V_14 ,
const struct V_61 * V_62 ,
int V_75 , T_7 V_279 )
{
struct V_15 * V_16 ;
T_1 V_25 = V_14 -> V_25 ;
int V_48 ;
if ( ! V_14 -> V_26 &&
! F_69 ( V_14 -> V_1 , V_87 ) )
return 0 ;
V_48 = - V_88 ;
V_16 = F_70 ( V_89 , V_279 ) ;
if ( V_16 == NULL )
goto V_48;
V_48 = F_185 ( V_16 , V_14 , V_62 , V_75 , 0 ) ;
if ( V_48 < 0 ) {
F_71 ( V_16 ) ;
goto V_48;
}
V_48 = F_72 ( V_16 , V_14 -> V_1 , V_25 , V_87 ,
V_14 -> V_26 , V_279 ) ;
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
struct V_19 * V_20 , * V_280 = (struct V_19 * ) V_91 -> args [ 2 ] ;
struct V_1 * V_1 = F_75 ( V_16 -> V_94 ) ;
int V_281 = V_91 -> args [ 3 ] ;
struct V_13 * V_14 = V_91 -> V_198 , V_282 ;
if ( V_91 -> args [ 1 ] )
return V_16 -> V_99 ;
F_76 () ;
V_91 -> V_27 = V_1 -> V_7 . V_83 ;
F_77 (afi, &net->nft.af_info, list) {
if ( V_14 -> V_3 && V_14 -> V_3 != V_3 )
continue;
if ( V_281 ) {
if ( V_3 -> V_9 != V_281 )
continue;
V_281 = 0 ;
}
F_77 (table, &afi->tables, list) {
if ( V_14 -> V_20 && V_14 -> V_20 != V_20 )
continue;
if ( V_280 ) {
if ( V_280 != V_20 )
continue;
V_280 = NULL ;
}
V_92 = 0 ;
F_77 (set, &table->sets, list) {
if ( V_92 < V_93 )
goto V_96;
V_282 = * V_14 ;
V_282 . V_20 = V_20 ;
V_282 . V_3 = V_3 ;
if ( F_185 ( V_16 , & V_282 , V_62 ,
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
F_22 ( V_91 -> V_198 ) ;
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
struct V_13 * V_283 ;
V_283 = F_190 ( sizeof( * V_283 ) , V_33 ) ;
if ( V_283 == NULL )
return - V_44 ;
* V_283 = V_14 ;
V_106 . V_198 = V_283 ;
return F_82 ( V_101 , V_16 , V_18 , & V_106 ) ;
}
if ( V_77 -> V_79 == V_95 )
return - V_12 ;
if ( ! V_24 [ V_252 ] )
return - V_69 ;
V_62 = F_177 ( V_14 . V_20 , V_24 [ V_261 ] ) ;
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
struct V_236 * V_237 ,
const struct V_23 * V_24 )
{
struct V_23 * V_284 [ V_285 + 1 ] ;
int V_48 ;
V_48 = F_121 ( V_284 , V_285 , V_24 , V_286 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_284 [ V_278 ] != NULL )
V_237 -> V_31 = F_48 ( F_49 ( V_284 [ V_278 ] ) ) ;
return 0 ;
}
static int F_192 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_61 ( V_18 ) ;
const struct V_234 * V_40 ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_61 * V_62 ;
struct V_13 V_14 ;
char V_68 [ V_257 ] ;
unsigned int V_31 ;
bool V_173 ;
T_2 V_269 ;
T_1 V_263 , V_267 , V_38 , V_158 , V_272 ;
struct V_236 V_237 ;
unsigned char * V_219 ;
T_6 V_276 ;
int V_48 ;
if ( V_24 [ V_252 ] == NULL ||
V_24 [ V_261 ] == NULL ||
V_24 [ V_264 ] == NULL ||
V_24 [ V_65 ] == NULL )
return - V_69 ;
memset ( & V_237 , 0 , sizeof( V_237 ) ) ;
V_263 = V_287 ;
if ( V_24 [ V_262 ] != NULL ) {
V_263 = F_48 ( F_49 ( V_24 [ V_262 ] ) ) ;
if ( ( V_263 & V_288 ) == V_288 )
return - V_69 ;
}
V_237 . V_265 = F_48 ( F_49 ( V_24 [ V_264 ] ) ) ;
if ( V_237 . V_265 == 0 || V_237 . V_265 > V_289 )
return - V_69 ;
V_38 = 0 ;
if ( V_24 [ V_244 ] != NULL ) {
V_38 = F_48 ( F_49 ( V_24 [ V_244 ] ) ) ;
if ( V_38 & ~ ( V_124 | V_290 |
V_245 | V_247 |
V_246 | V_291 ) )
return - V_69 ;
if ( ( V_38 & ( V_246 | V_291 ) ) ==
( V_246 | V_291 ) )
return - V_113 ;
}
V_267 = 0 ;
if ( V_24 [ V_266 ] != NULL ) {
if ( ! ( V_38 & V_246 ) )
return - V_69 ;
V_267 = F_48 ( F_49 ( V_24 [ V_266 ] ) ) ;
if ( ( V_267 & V_288 ) == V_288 &&
V_267 != V_292 )
return - V_69 ;
if ( V_267 != V_292 ) {
if ( V_24 [ V_268 ] == NULL )
return - V_69 ;
V_237 . V_233 = F_48 ( F_49 ( V_24 [ V_268 ] ) ) ;
if ( V_237 . V_233 == 0 || V_237 . V_233 > V_289 )
return - V_69 ;
} else
V_237 . V_233 = sizeof( struct V_293 ) ;
} else if ( V_38 & V_246 )
return - V_69 ;
V_269 = 0 ;
if ( V_24 [ V_270 ] != NULL ) {
if ( ! ( V_38 & V_247 ) )
return - V_69 ;
V_269 = F_125 ( F_126 ( V_24 [ V_270 ] ) ) ;
}
V_272 = 0 ;
if ( V_24 [ V_273 ] != NULL ) {
if ( ! ( V_38 & V_247 ) )
return - V_69 ;
V_272 = F_48 ( F_49 ( V_24 [ V_273 ] ) ) ;
}
V_158 = V_250 ;
if ( V_24 [ V_274 ] != NULL )
V_158 = F_48 ( F_49 ( V_24 [ V_274 ] ) ) ;
if ( V_24 [ V_277 ] != NULL ) {
V_48 = F_191 ( & V_14 , & V_237 , V_24 [ V_277 ] ) ;
if ( V_48 < 0 )
return V_48 ;
}
V_173 = V_18 -> V_103 & V_174 ? true : false ;
V_3 = F_11 ( V_1 , V_77 -> V_79 , V_173 ) ;
if ( F_83 ( V_3 ) )
return F_84 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_252 ] ) ;
if ( F_83 ( V_20 ) )
return F_84 ( V_20 ) ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
V_62 = F_177 ( V_20 , V_24 [ V_261 ] ) ;
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
if ( ! ( V_18 -> V_103 & V_174 ) )
return - V_58 ;
V_40 = F_175 ( V_24 , & V_237 , V_158 ) ;
if ( F_83 ( V_40 ) )
return F_84 ( V_40 ) ;
V_276 = 0 ;
if ( V_24 [ V_275 ] )
V_276 = F_57 ( V_24 [ V_275 ] ) ;
V_31 = 0 ;
if ( V_40 -> V_294 != NULL )
V_31 = V_40 -> V_294 ( V_24 ) ;
V_48 = - V_44 ;
V_62 = F_19 ( sizeof( * V_62 ) + V_31 + V_276 , V_33 ) ;
if ( V_62 == NULL )
goto V_115;
F_94 ( V_68 , V_24 [ V_261 ] , sizeof( V_62 -> V_68 ) ) ;
V_48 = F_179 ( & V_14 , V_62 , V_68 ) ;
if ( V_48 < 0 )
goto V_116;
V_219 = NULL ;
if ( V_276 ) {
V_219 = V_62 -> V_198 + V_31 ;
F_171 ( V_219 , V_24 [ V_275 ] , V_276 ) ;
}
F_2 ( & V_62 -> V_125 ) ;
F_141 ( & V_62 -> V_37 , V_1 ) ;
V_62 -> V_40 = V_40 ;
V_62 -> V_263 = V_263 ;
V_62 -> V_265 = V_237 . V_265 ;
V_62 -> V_267 = V_267 ;
V_62 -> V_233 = V_237 . V_233 ;
V_62 -> V_38 = V_38 ;
V_62 -> V_31 = V_237 . V_31 ;
V_62 -> V_158 = V_158 ;
V_62 -> V_276 = V_276 ;
V_62 -> V_219 = V_219 ;
V_62 -> V_269 = V_269 ;
V_62 -> V_272 = V_272 ;
V_48 = V_40 -> V_207 ( V_62 , & V_237 , V_24 ) ;
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
V_62 -> V_40 -> V_208 ( V_62 ) ;
F_95 ( V_62 -> V_40 -> V_114 ) ;
F_22 ( V_62 ) ;
}
static void F_194 ( const struct V_13 * V_14 , struct V_61 * V_62 )
{
F_8 ( & V_62 -> V_6 ) ;
F_186 ( V_14 , V_62 , V_67 , V_295 ) ;
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
if ( V_24 [ V_252 ] == NULL )
return - V_69 ;
V_48 = F_176 ( & V_14 , V_1 , V_16 , V_18 , V_24 ) ;
if ( V_48 < 0 )
return V_48 ;
V_62 = F_177 ( V_14 . V_20 , V_24 [ V_261 ] ) ;
if ( F_83 ( V_62 ) )
return F_84 ( V_62 ) ;
if ( ! F_98 ( & V_62 -> V_125 ) )
return - V_129 ;
return F_50 ( & V_14 , V_62 ) ;
}
static int F_196 ( const struct V_13 * V_14 ,
const struct V_61 * V_62 ,
const struct V_296 * V_297 ,
const struct V_298 * V_299 )
{
const struct V_300 * V_301 = F_197 ( V_62 , V_299 -> V_189 ) ;
enum V_302 V_303 ;
V_303 = F_198 ( V_62 -> V_267 ) ;
return F_199 ( V_14 , V_303 , F_200 ( V_301 ) ,
V_62 -> V_267 == V_292 ?
V_292 : V_287 ,
V_62 -> V_233 ) ;
}
int F_201 ( const struct V_13 * V_14 , struct V_61 * V_62 ,
struct V_304 * V_305 )
{
struct V_304 * V_72 ;
struct V_296 V_297 ;
if ( ! F_98 ( & V_62 -> V_125 ) && V_62 -> V_38 & V_124 )
return - V_129 ;
if ( V_305 -> V_38 & V_246 ) {
F_10 (i, &set->bindings, list) {
if ( V_72 -> V_38 & V_246 &&
V_72 -> V_22 == V_305 -> V_22 )
goto V_306;
}
V_297 . V_57 = F_38 ( V_14 -> V_1 ) ;
V_297 . V_307 = 0 ;
V_297 . V_308 = 0 ;
V_297 . V_48 = 0 ;
V_297 . V_309 = F_196 ;
V_62 -> V_40 -> V_310 ( V_14 , V_62 , & V_297 ) ;
if ( V_297 . V_48 < 0 )
return V_297 . V_48 ;
}
V_306:
V_305 -> V_22 = V_14 -> V_22 ;
F_4 ( & V_305 -> V_6 , & V_62 -> V_125 ) ;
return 0 ;
}
void F_202 ( const struct V_13 * V_14 , struct V_61 * V_62 ,
struct V_304 * V_305 )
{
F_8 ( & V_305 -> V_6 ) ;
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
V_20 = F_53 ( V_3 , V_24 [ V_311 ] ) ;
if ( F_83 ( V_20 ) )
return F_84 ( V_20 ) ;
F_15 ( V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return 0 ;
}
static int F_204 ( struct V_15 * V_16 ,
const struct V_61 * V_62 ,
const struct V_298 * V_299 )
{
const struct V_300 * V_301 = F_197 ( V_62 , V_299 -> V_189 ) ;
unsigned char * V_312 = F_205 ( V_16 ) ;
struct V_23 * V_135 ;
V_135 = F_112 ( V_16 , V_218 ) ;
if ( V_135 == NULL )
goto V_78;
if ( F_206 ( V_16 , V_313 , F_207 ( V_301 ) ,
V_287 , V_62 -> V_265 ) < 0 )
goto V_78;
if ( F_208 ( V_301 , V_314 ) &&
F_206 ( V_16 , V_315 , F_200 ( V_301 ) ,
V_62 -> V_267 == V_292 ? V_292 : V_287 ,
V_62 -> V_233 ) < 0 )
goto V_78;
if ( F_208 ( V_301 , V_316 ) &&
F_149 ( V_16 , V_317 , F_209 ( V_301 ) ) < 0 )
goto V_78;
if ( F_208 ( V_301 , V_318 ) &&
F_64 ( V_16 , V_319 ,
F_65 ( * F_210 ( V_301 ) ) ) )
goto V_78;
if ( F_208 ( V_301 , V_320 ) &&
F_113 ( V_16 , V_321 ,
F_114 ( * F_211 ( V_301 ) ) ,
V_322 ) )
goto V_78;
if ( F_208 ( V_301 , V_323 ) ) {
unsigned long V_324 , V_325 = V_326 ;
V_324 = * F_212 ( V_301 ) ;
if ( F_213 ( V_325 , V_324 ) )
V_324 -= V_325 ;
else
V_324 = 0 ;
if ( F_113 ( V_16 , V_327 ,
F_114 ( F_214 ( V_324 ) ) ,
V_322 ) )
goto V_78;
}
if ( F_208 ( V_301 , V_328 ) ) {
struct V_220 * V_219 ;
V_219 = F_215 ( V_301 ) ;
if ( F_160 ( V_16 , V_329 ,
V_219 -> V_99 + 1 , V_219 -> V_198 ) )
goto V_78;
}
F_115 ( V_16 , V_135 ) ;
return 0 ;
V_78:
F_67 ( V_16 , V_312 ) ;
return - V_330 ;
}
static int F_216 ( const struct V_13 * V_14 ,
const struct V_61 * V_62 ,
const struct V_296 * V_297 ,
const struct V_298 * V_299 )
{
struct V_331 * args ;
args = F_217 ( V_297 , struct V_331 , V_297 ) ;
return F_204 ( args -> V_16 , V_62 , V_299 ) ;
}
static int F_218 ( struct V_15 * V_16 , struct V_90 * V_91 )
{
struct V_1 * V_1 = F_75 ( V_16 -> V_94 ) ;
const struct V_61 * V_62 ;
struct V_331 args ;
struct V_13 V_14 ;
struct V_23 * V_24 [ V_332 + 1 ] ;
struct V_76 * V_77 ;
struct V_17 * V_18 ;
struct V_23 * V_135 ;
T_1 V_25 , V_27 ;
int V_75 , V_48 ;
V_48 = F_219 ( V_91 -> V_18 , sizeof( struct V_76 ) , V_24 ,
V_332 , V_333 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_203 ( & V_14 , V_1 , V_91 -> V_16 , V_91 -> V_18 ,
( void * ) V_24 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_14 . V_20 -> V_38 & V_46 )
return - V_58 ;
V_62 = F_177 ( V_14 . V_20 , V_24 [ V_334 ] ) ;
if ( F_83 ( V_62 ) )
return F_84 ( V_62 ) ;
if ( V_62 -> V_38 & V_66 )
return - V_58 ;
V_75 = V_335 ;
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
if ( F_63 ( V_16 , V_311 , V_14 . V_20 -> V_68 ) )
goto V_78;
if ( F_63 ( V_16 , V_334 , V_62 -> V_68 ) )
goto V_78;
V_135 = F_112 ( V_16 , V_336 ) ;
if ( V_135 == NULL )
goto V_78;
args . V_91 = V_91 ;
args . V_16 = V_16 ;
args . V_297 . V_57 = F_36 ( V_14 . V_1 ) ;
args . V_297 . V_307 = V_91 -> args [ 0 ] ;
args . V_297 . V_308 = 0 ;
args . V_297 . V_48 = 0 ;
args . V_297 . V_309 = F_216 ;
V_62 -> V_40 -> V_310 ( & V_14 , V_62 , & args . V_297 ) ;
F_115 ( V_16 , V_135 ) ;
F_66 ( V_16 , V_18 ) ;
if ( args . V_297 . V_48 && args . V_297 . V_48 != - V_330 )
return args . V_297 . V_48 ;
if ( args . V_297 . V_308 == V_91 -> args [ 0 ] )
return 0 ;
V_91 -> args [ 0 ] = args . V_297 . V_308 ;
return V_16 -> V_99 ;
V_78:
return - V_144 ;
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
V_62 = F_177 ( V_14 . V_20 , V_24 [ V_334 ] ) ;
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
const struct V_298 * V_299 )
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
if ( F_63 ( V_16 , V_252 , V_14 -> V_20 -> V_68 ) )
goto V_78;
if ( F_63 ( V_16 , V_261 , V_62 -> V_68 ) )
goto V_78;
V_135 = F_112 ( V_16 , V_336 ) ;
if ( V_135 == NULL )
goto V_78;
V_48 = F_204 ( V_16 , V_62 , V_299 ) ;
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
const struct V_298 * V_299 ,
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
V_62 , V_299 ) ;
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
V_32 = F_18 ( V_14 , V_30 , sizeof( struct V_337 ) ) ;
if ( V_32 == NULL )
return NULL ;
F_224 ( V_32 ) = V_62 ;
return V_32 ;
}
void * F_225 ( const struct V_61 * V_62 ,
const struct V_338 * V_339 ,
const T_1 * V_340 , const T_1 * V_198 ,
T_2 V_269 , T_7 V_341 )
{
struct V_300 * V_301 ;
void * V_299 ;
V_299 = F_19 ( V_62 -> V_40 -> V_342 + V_339 -> V_99 , V_341 ) ;
if ( V_299 == NULL )
return NULL ;
V_301 = F_197 ( V_62 , V_299 ) ;
F_226 ( V_301 , V_339 ) ;
memcpy ( F_207 ( V_301 ) , V_340 , V_62 -> V_265 ) ;
if ( F_208 ( V_301 , V_314 ) )
memcpy ( F_200 ( V_301 ) , V_198 , V_62 -> V_233 ) ;
if ( F_208 ( V_301 , V_323 ) )
* F_212 ( V_301 ) =
V_326 + F_227 ( V_269 ) ;
if ( F_208 ( V_301 , V_320 ) )
* F_211 ( V_301 ) = V_269 ;
return V_299 ;
}
void F_228 ( const struct V_61 * V_62 , void * V_299 )
{
struct V_300 * V_301 = F_197 ( V_62 , V_299 ) ;
F_229 ( F_207 ( V_301 ) , V_287 ) ;
if ( F_208 ( V_301 , V_314 ) )
F_229 ( F_200 ( V_301 ) , V_62 -> V_267 ) ;
if ( F_208 ( V_301 , V_316 ) )
F_152 ( NULL , F_209 ( V_301 ) ) ;
F_22 ( V_299 ) ;
}
static int F_230 ( const struct V_61 * V_62 ,
const struct V_23 * V_161 , T_1 * V_38 )
{
if ( V_161 == NULL )
return 0 ;
* V_38 = F_48 ( F_49 ( V_161 ) ) ;
if ( * V_38 & ~ V_343 )
return - V_69 ;
if ( ! ( V_62 -> V_38 & V_245 ) &&
* V_38 & V_343 )
return - V_69 ;
return 0 ;
}
static int F_231 ( struct V_13 * V_14 , struct V_61 * V_62 ,
const struct V_23 * V_161 )
{
struct V_23 * V_24 [ V_344 + 1 ] ;
struct V_345 V_346 , V_347 ;
struct V_338 V_339 ;
struct V_300 * V_301 ;
struct V_298 V_299 ;
struct V_304 * V_305 ;
struct V_220 * V_219 ;
struct V_348 V_198 ;
enum V_302 V_303 ;
struct V_29 * V_32 ;
T_1 V_38 = 0 ;
T_2 V_269 ;
T_4 V_227 ;
int V_48 ;
V_48 = F_121 ( V_24 , V_344 , V_161 ,
V_349 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_24 [ V_313 ] == NULL )
return - V_69 ;
F_232 ( & V_339 ) ;
V_48 = F_230 ( V_62 , V_24 [ V_319 ] , & V_38 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_38 != 0 )
F_233 ( & V_339 , V_318 ) ;
if ( V_62 -> V_38 & V_246 ) {
if ( V_24 [ V_315 ] == NULL &&
! ( V_38 & V_343 ) )
return - V_69 ;
if ( V_24 [ V_315 ] != NULL &&
V_38 & V_343 )
return - V_69 ;
} else {
if ( V_24 [ V_315 ] != NULL )
return - V_69 ;
}
V_269 = 0 ;
if ( V_24 [ V_321 ] != NULL ) {
if ( ! ( V_62 -> V_38 & V_247 ) )
return - V_69 ;
V_269 = F_125 ( F_126 ( V_24 [ V_321 ] ) ) ;
} else if ( V_62 -> V_38 & V_247 ) {
V_269 = V_62 -> V_269 ;
}
V_48 = F_234 ( V_14 , & V_299 . V_340 . V_350 , sizeof( V_299 . V_340 ) , & V_346 ,
V_24 [ V_313 ] ) ;
if ( V_48 < 0 )
goto V_115;
V_48 = - V_69 ;
if ( V_346 . type != V_287 || V_346 . V_99 != V_62 -> V_265 )
goto V_116;
F_235 ( & V_339 , V_351 , V_346 . V_99 ) ;
if ( V_269 > 0 ) {
F_233 ( & V_339 , V_323 ) ;
if ( V_269 != V_62 -> V_269 )
F_233 ( & V_339 , V_320 ) ;
}
if ( V_24 [ V_315 ] != NULL ) {
V_48 = F_234 ( V_14 , & V_198 , sizeof( V_198 ) , & V_347 ,
V_24 [ V_315 ] ) ;
if ( V_48 < 0 )
goto V_116;
V_48 = - V_69 ;
if ( V_62 -> V_267 != V_292 && V_347 . V_99 != V_62 -> V_233 )
goto V_120;
V_303 = F_198 ( V_62 -> V_267 ) ;
F_10 (binding, &set->bindings, list) {
struct V_13 V_352 = {
. V_3 = V_14 -> V_3 ,
. V_20 = V_14 -> V_20 ,
. V_22 = (struct V_21 * ) V_305 -> V_22 ,
} ;
if ( ! ( V_305 -> V_38 & V_246 ) )
continue;
V_48 = F_199 ( & V_352 , V_303 ,
& V_198 ,
V_347 . type , V_347 . V_99 ) ;
if ( V_48 < 0 )
goto V_120;
}
F_235 ( & V_339 , V_314 , V_347 . V_99 ) ;
}
V_227 = 0 ;
if ( V_24 [ V_329 ] != NULL ) {
V_227 = F_57 ( V_24 [ V_329 ] ) ;
if ( V_227 > 0 )
F_235 ( & V_339 , V_328 ,
V_227 ) ;
}
V_48 = - V_44 ;
V_299 . V_189 = F_225 ( V_62 , & V_339 , V_299 . V_340 . V_350 . V_198 , V_198 . V_198 ,
V_269 , V_33 ) ;
if ( V_299 . V_189 == NULL )
goto V_120;
V_301 = F_197 ( V_62 , V_299 . V_189 ) ;
if ( V_38 )
* F_210 ( V_301 ) = V_38 ;
if ( V_227 > 0 ) {
V_219 = F_215 ( V_301 ) ;
V_219 -> V_99 = V_227 - 1 ;
F_171 ( & V_219 -> V_198 , V_24 [ V_329 ] , V_227 ) ;
}
V_32 = F_223 ( V_14 , V_335 , V_62 ) ;
if ( V_32 == NULL )
goto V_353;
V_301 -> V_57 = F_36 ( V_14 -> V_1 ) | V_354 ;
V_48 = V_62 -> V_40 -> V_355 ( V_62 , & V_299 ) ;
if ( V_48 < 0 )
goto V_356;
V_337 ( V_32 ) = V_299 ;
F_31 ( & V_32 -> V_6 , & V_14 -> V_1 -> V_7 . V_47 ) ;
return 0 ;
V_356:
F_22 ( V_32 ) ;
V_353:
F_22 ( V_299 . V_189 ) ;
V_120:
if ( V_24 [ V_315 ] != NULL )
F_229 ( & V_198 , V_347 . type ) ;
V_116:
F_229 ( & V_299 . V_340 . V_350 , V_346 . type ) ;
V_115:
return V_48 ;
}
static int F_236 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_23 * V_161 ;
struct V_61 * V_62 ;
struct V_13 V_14 ;
int V_229 , V_48 = 0 ;
if ( V_24 [ V_336 ] == NULL )
return - V_69 ;
V_48 = F_203 ( & V_14 , V_1 , V_16 , V_18 , V_24 ) ;
if ( V_48 < 0 )
return V_48 ;
V_62 = F_177 ( V_14 . V_20 , V_24 [ V_334 ] ) ;
if ( F_83 ( V_62 ) ) {
if ( V_24 [ V_357 ] ) {
V_62 = F_178 ( V_1 ,
V_24 [ V_357 ] ) ;
}
if ( F_83 ( V_62 ) )
return F_84 ( V_62 ) ;
}
if ( ! F_98 ( & V_62 -> V_125 ) && V_62 -> V_38 & V_290 )
return - V_129 ;
F_169 (attr, nla[NFTA_SET_ELEM_LIST_ELEMENTS], rem) {
if ( V_62 -> V_31 &&
! F_237 ( & V_62 -> V_358 , 1 , V_62 -> V_31 + V_62 -> V_359 ) )
return - V_260 ;
V_48 = F_231 ( & V_14 , V_62 , V_161 ) ;
if ( V_48 < 0 ) {
F_238 ( & V_62 -> V_358 ) ;
break;
}
}
return V_48 ;
}
static int F_239 ( struct V_13 * V_14 , struct V_61 * V_62 ,
const struct V_23 * V_161 )
{
struct V_23 * V_24 [ V_344 + 1 ] ;
struct V_338 V_339 ;
struct V_345 V_237 ;
struct V_298 V_299 ;
struct V_300 * V_301 ;
struct V_29 * V_32 ;
T_1 V_38 = 0 ;
void * V_189 ;
int V_48 ;
V_48 = F_121 ( V_24 , V_344 , V_161 ,
V_349 ) ;
if ( V_48 < 0 )
goto V_115;
V_48 = - V_69 ;
if ( V_24 [ V_313 ] == NULL )
goto V_115;
F_232 ( & V_339 ) ;
V_48 = F_230 ( V_62 , V_24 [ V_319 ] , & V_38 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_38 != 0 )
F_233 ( & V_339 , V_318 ) ;
V_48 = F_234 ( V_14 , & V_299 . V_340 . V_350 , sizeof( V_299 . V_340 ) , & V_237 ,
V_24 [ V_313 ] ) ;
if ( V_48 < 0 )
goto V_115;
V_48 = - V_69 ;
if ( V_237 . type != V_287 || V_237 . V_99 != V_62 -> V_265 )
goto V_116;
F_235 ( & V_339 , V_351 , V_237 . V_99 ) ;
V_48 = - V_44 ;
V_299 . V_189 = F_225 ( V_62 , & V_339 , V_299 . V_340 . V_350 . V_198 , NULL , 0 ,
V_33 ) ;
if ( V_299 . V_189 == NULL )
goto V_116;
V_301 = F_197 ( V_62 , V_299 . V_189 ) ;
if ( V_38 )
* F_210 ( V_301 ) = V_38 ;
V_32 = F_223 ( V_14 , V_360 , V_62 ) ;
if ( V_32 == NULL ) {
V_48 = - V_44 ;
goto V_120;
}
V_189 = V_62 -> V_40 -> V_361 ( V_62 , & V_299 ) ;
if ( V_189 == NULL ) {
V_48 = - V_58 ;
goto V_353;
}
F_22 ( V_299 . V_189 ) ;
V_299 . V_189 = V_189 ;
V_337 ( V_32 ) = V_299 ;
F_31 ( & V_32 -> V_6 , & V_14 -> V_1 -> V_7 . V_47 ) ;
return 0 ;
V_353:
F_22 ( V_32 ) ;
V_120:
F_22 ( V_299 . V_189 ) ;
V_116:
F_229 ( & V_299 . V_340 . V_350 , V_237 . type ) ;
V_115:
return V_48 ;
}
static int F_240 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_23 * V_161 ;
struct V_61 * V_62 ;
struct V_13 V_14 ;
int V_229 , V_48 = 0 ;
if ( V_24 [ V_336 ] == NULL )
return - V_69 ;
V_48 = F_203 ( & V_14 , V_1 , V_16 , V_18 , V_24 ) ;
if ( V_48 < 0 )
return V_48 ;
V_62 = F_177 ( V_14 . V_20 , V_24 [ V_334 ] ) ;
if ( F_83 ( V_62 ) )
return F_84 ( V_62 ) ;
if ( ! F_98 ( & V_62 -> V_125 ) && V_62 -> V_38 & V_290 )
return - V_129 ;
F_169 (attr, nla[NFTA_SET_ELEM_LIST_ELEMENTS], rem) {
V_48 = F_239 ( & V_14 , V_62 , V_161 ) ;
if ( V_48 < 0 )
break;
V_62 -> V_359 ++ ;
}
return V_48 ;
}
void F_241 ( struct V_362 * V_363 )
{
struct V_364 * V_365 ;
unsigned int V_72 ;
V_365 = F_217 ( V_363 , struct V_364 , V_366 . V_363 ) ;
for ( V_72 = 0 ; V_72 < V_365 -> V_366 . V_367 ; V_72 ++ )
F_228 ( V_365 -> V_366 . V_62 , V_365 -> V_368 [ V_72 ] ) ;
F_22 ( V_365 ) ;
}
struct V_364 * F_242 ( const struct V_61 * V_62 ,
T_7 V_341 )
{
struct V_364 * V_365 ;
V_365 = F_19 ( sizeof( * V_365 ) , V_341 ) ;
if ( V_365 == NULL )
return V_365 ;
V_365 -> V_366 . V_62 = V_62 ;
return V_365 ;
}
static int F_243 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_25 , T_1 V_27 )
{
struct V_17 * V_18 ;
struct V_76 * V_77 ;
int V_75 = ( V_5 << 8 ) | V_369 ;
V_18 = F_60 ( V_16 , V_25 , V_27 , V_75 , sizeof( struct V_76 ) , 0 ) ;
if ( V_18 == NULL )
goto V_78;
V_77 = F_61 ( V_18 ) ;
V_77 -> V_79 = V_127 ;
V_77 -> V_80 = V_81 ;
V_77 -> V_82 = F_62 ( V_1 -> V_7 . V_83 & 0xffff ) ;
if ( F_64 ( V_16 , V_370 , F_65 ( V_1 -> V_7 . V_83 ) ) )
goto V_78;
F_66 ( V_16 , V_18 ) ;
return 0 ;
V_78:
F_67 ( V_16 , V_18 ) ;
return - V_330 ;
}
static int F_244 ( struct V_1 * V_1 , struct V_15 * V_16 , int V_75 )
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
V_48 = F_243 ( V_102 , V_1 , F_16 ( V_16 ) . V_25 ,
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
static int F_245 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
struct V_15 * V_102 ;
int V_48 ;
V_102 = F_85 ( V_89 , V_33 ) ;
if ( V_102 == NULL )
return - V_44 ;
V_48 = F_243 ( V_102 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 ) ;
if ( V_48 < 0 )
goto V_48;
return F_86 ( V_101 , V_102 , F_16 ( V_16 ) . V_25 ) ;
V_48:
F_71 ( V_102 ) ;
return V_48 ;
}
static void F_246 ( struct V_29 * V_32 )
{
struct V_34 * V_35 ;
if ( F_139 ( V_32 ) [ 0 ] )
strcpy ( V_32 -> V_14 . V_22 -> V_68 , F_139 ( V_32 ) ) ;
if ( ! ( V_32 -> V_14 . V_22 -> V_38 & V_42 ) )
return;
V_35 = V_34 ( V_32 -> V_14 . V_22 ) ;
F_128 ( V_35 , F_136 ( V_32 ) ) ;
switch ( F_138 ( V_32 ) ) {
case V_175 :
case V_172 :
V_35 -> V_158 = F_138 ( V_32 ) ;
break;
}
}
static void F_247 ( struct V_29 * V_32 )
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
case V_360 :
F_228 ( F_224 ( V_32 ) ,
V_337 ( V_32 ) . V_189 ) ;
break;
}
F_22 ( V_32 ) ;
}
static int F_248 ( struct V_1 * V_1 , struct V_15 * V_16 )
{
struct V_29 * V_32 , * V_209 ;
struct V_337 * V_371 ;
while ( ++ V_1 -> V_7 . V_83 == 0 ) ;
V_1 -> V_7 . V_372 = F_249 ( V_1 ) ;
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
F_246 ( V_32 ) ;
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
case V_222 :
F_41 ( V_32 -> V_14 . V_1 , V_59 ( V_32 ) ) ;
F_161 ( & V_32 -> V_14 ,
V_59 ( V_32 ) ,
V_222 ) ;
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
case V_335 :
V_371 = (struct V_337 * ) V_32 -> V_198 ;
V_371 -> V_62 -> V_40 -> V_373 ( V_371 -> V_62 , & V_371 -> V_299 ) ;
F_222 ( & V_32 -> V_14 , V_371 -> V_62 ,
& V_371 -> V_299 ,
V_335 , 0 ) ;
F_20 ( V_32 ) ;
break;
case V_360 :
V_371 = (struct V_337 * ) V_32 -> V_198 ;
F_222 ( & V_32 -> V_14 , V_371 -> V_62 ,
& V_371 -> V_299 ,
V_360 , 0 ) ;
V_371 -> V_62 -> V_40 -> remove ( V_371 -> V_62 , & V_371 -> V_299 ) ;
F_238 ( & V_371 -> V_62 -> V_358 ) ;
V_371 -> V_62 -> V_359 -- ;
break;
}
}
F_131 () ;
F_97 (trans, next, &net->nft.commit_list, list) {
F_21 ( & V_32 -> V_6 ) ;
F_247 ( V_32 ) ;
}
F_244 ( V_1 , V_16 , V_369 ) ;
return 0 ;
}
static void F_250 ( struct V_29 * V_32 )
{
switch ( V_32 -> V_30 ) {
case V_45 :
F_101 ( & V_32 -> V_14 ) ;
break;
case V_51 :
F_133 ( V_32 -> V_14 . V_22 ) ;
break;
case V_222 :
F_164 ( & V_32 -> V_14 , V_59 ( V_32 ) ) ;
break;
case V_64 :
F_193 ( V_63 ( V_32 ) ) ;
break;
case V_335 :
F_228 ( F_224 ( V_32 ) ,
V_337 ( V_32 ) . V_189 ) ;
break;
}
F_22 ( V_32 ) ;
}
static int F_251 ( struct V_1 * V_1 , struct V_15 * V_16 )
{
struct V_29 * V_32 , * V_209 ;
struct V_337 * V_371 ;
F_252 (trans, next, &net->nft.commit_list,
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
case V_222 :
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
case V_335 :
V_371 = (struct V_337 * ) V_32 -> V_198 ;
V_371 -> V_62 -> V_40 -> remove ( V_371 -> V_62 , & V_371 -> V_299 ) ;
F_238 ( & V_371 -> V_62 -> V_358 ) ;
break;
case V_360 :
V_371 = (struct V_337 * ) V_32 -> V_198 ;
V_371 -> V_62 -> V_40 -> V_373 ( V_371 -> V_62 , & V_371 -> V_299 ) ;
V_371 -> V_62 -> V_359 -- ;
F_20 ( V_32 ) ;
break;
}
}
F_131 () ;
F_252 (trans, next,
&net->nft.commit_list, list) {
F_21 ( & V_32 -> V_6 ) ;
F_250 ( V_32 ) ;
}
return 0 ;
}
int F_253 ( const struct V_21 * V_22 ,
enum V_374 type )
{
const struct V_34 * V_35 ;
if ( V_22 -> V_38 & V_42 ) {
V_35 = V_34 ( V_22 ) ;
if ( V_35 -> type -> type != type )
return - V_113 ;
}
return 0 ;
}
int F_254 ( const struct V_21 * V_22 ,
unsigned int V_375 )
{
struct V_34 * V_35 ;
if ( V_22 -> V_38 & V_42 ) {
V_35 = V_34 ( V_22 ) ;
if ( ( 1 << V_35 -> V_40 [ 0 ] . V_152 ) & V_375 )
return 0 ;
return - V_113 ;
}
return 0 ;
}
static int F_255 ( const struct V_13 * V_14 ,
const struct V_61 * V_62 ,
const struct V_296 * V_297 ,
const struct V_298 * V_299 )
{
const struct V_300 * V_301 = F_197 ( V_62 , V_299 -> V_189 ) ;
const struct V_348 * V_198 ;
if ( F_208 ( V_301 , V_318 ) &&
* F_210 ( V_301 ) & V_343 )
return 0 ;
V_198 = F_200 ( V_301 ) ;
switch ( V_198 -> V_376 . V_377 ) {
case V_378 :
case V_379 :
return F_256 ( V_14 , V_198 -> V_376 . V_22 ) ;
default:
return 0 ;
}
}
static int F_256 ( const struct V_13 * V_14 ,
const struct V_21 * V_22 )
{
const struct V_55 * V_56 ;
const struct V_195 * V_196 , * V_380 ;
const struct V_61 * V_62 ;
struct V_304 * V_305 ;
struct V_296 V_297 ;
if ( V_14 -> V_22 == V_22 )
return - V_381 ;
F_10 (rule, &chain->rules, list) {
F_159 (expr, last, rule) {
const struct V_348 * V_198 = NULL ;
int V_48 ;
if ( ! V_196 -> V_40 -> V_382 )
continue;
V_48 = V_196 -> V_40 -> V_382 ( V_14 , V_196 , & V_198 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_198 == NULL )
continue;
switch ( V_198 -> V_376 . V_377 ) {
case V_378 :
case V_379 :
V_48 = F_256 ( V_14 ,
V_198 -> V_376 . V_22 ) ;
if ( V_48 < 0 )
return V_48 ;
default:
break;
}
}
}
F_10 (set, &ctx->table->sets, list) {
if ( ! ( V_62 -> V_38 & V_246 ) ||
V_62 -> V_267 != V_292 )
continue;
F_10 (binding, &set->bindings, list) {
if ( ! ( V_305 -> V_38 & V_246 ) ||
V_305 -> V_22 != V_22 )
continue;
V_297 . V_57 = F_38 ( V_14 -> V_1 ) ;
V_297 . V_307 = 0 ;
V_297 . V_308 = 0 ;
V_297 . V_48 = 0 ;
V_297 . V_309 = F_255 ;
V_62 -> V_40 -> V_310 ( V_14 , V_62 , & V_297 ) ;
if ( V_297 . V_48 < 0 )
return V_297 . V_48 ;
}
}
return 0 ;
}
unsigned int F_257 ( const struct V_23 * V_161 )
{
unsigned int V_383 ;
V_383 = F_48 ( F_49 ( V_161 ) ) ;
switch ( V_383 ) {
case V_384 ... V_385 :
return V_383 * V_386 / V_387 ;
default:
return V_383 + V_386 / V_387 - V_388 ;
}
}
int F_258 ( struct V_15 * V_16 , unsigned int V_161 , unsigned int V_383 )
{
if ( V_383 % ( V_386 / V_387 ) == 0 )
V_383 = V_383 / ( V_386 / V_387 ) ;
else
V_383 = V_383 - V_386 / V_387 + V_388 ;
return F_64 ( V_16 , V_161 , F_65 ( V_383 ) ) ;
}
int F_259 ( enum V_302 V_383 , unsigned int V_99 )
{
if ( V_383 < V_389 * V_386 / V_387 )
return - V_69 ;
if ( V_99 == 0 )
return - V_69 ;
if ( V_383 * V_387 + V_99 > F_260 ( struct V_390 , V_198 ) )
return - V_391 ;
return 0 ;
}
int F_199 ( const struct V_13 * V_14 ,
enum V_302 V_383 ,
const struct V_348 * V_198 ,
enum V_392 type , unsigned int V_99 )
{
int V_48 ;
switch ( V_383 ) {
case V_384 :
if ( type != V_292 )
return - V_69 ;
if ( V_198 != NULL &&
( V_198 -> V_376 . V_377 == V_379 ||
V_198 -> V_376 . V_377 == V_378 ) ) {
V_48 = F_256 ( V_14 , V_198 -> V_376 . V_22 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_14 -> V_22 -> V_393 + 1 >
V_198 -> V_376 . V_22 -> V_393 ) {
if ( V_14 -> V_22 -> V_393 + 1 == V_394 )
return - V_395 ;
V_198 -> V_376 . V_22 -> V_393 = V_14 -> V_22 -> V_393 + 1 ;
}
}
return 0 ;
default:
if ( V_383 < V_389 * V_386 / V_387 )
return - V_69 ;
if ( V_99 == 0 )
return - V_69 ;
if ( V_383 * V_387 + V_99 >
F_260 ( struct V_390 , V_198 ) )
return - V_391 ;
if ( V_198 != NULL && type != V_287 )
return - V_69 ;
return 0 ;
}
}
static int F_261 ( const struct V_13 * V_14 , struct V_348 * V_198 ,
struct V_345 * V_237 , const struct V_23 * V_24 )
{
struct V_23 * V_162 [ V_396 + 1 ] ;
struct V_21 * V_22 ;
int V_48 ;
V_48 = F_121 ( V_162 , V_396 , V_24 , V_397 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( ! V_162 [ V_398 ] )
return - V_69 ;
V_198 -> V_376 . V_377 = F_48 ( F_49 ( V_162 [ V_398 ] ) ) ;
switch ( V_198 -> V_376 . V_377 ) {
default:
switch ( V_198 -> V_376 . V_377 & V_399 ) {
case V_172 :
case V_175 :
case V_400 :
break;
default:
return - V_69 ;
}
case V_401 :
case V_402 :
case V_403 :
break;
case V_378 :
case V_379 :
if ( ! V_162 [ V_404 ] )
return - V_69 ;
V_22 = F_106 ( V_14 -> V_20 ,
V_162 [ V_404 ] ) ;
if ( F_83 ( V_22 ) )
return F_84 ( V_22 ) ;
if ( V_22 -> V_38 & V_42 )
return - V_113 ;
V_22 -> V_54 ++ ;
V_198 -> V_376 . V_22 = V_22 ;
break;
}
V_237 -> V_99 = sizeof( V_198 -> V_376 ) ;
V_237 -> type = V_292 ;
return 0 ;
}
static void F_262 ( const struct V_348 * V_198 )
{
switch ( V_198 -> V_376 . V_377 ) {
case V_378 :
case V_379 :
V_198 -> V_376 . V_22 -> V_54 -- ;
break;
}
}
int F_263 ( struct V_15 * V_16 , int type , const struct V_293 * V_405 )
{
struct V_23 * V_135 ;
V_135 = F_112 ( V_16 , type ) ;
if ( ! V_135 )
goto V_78;
if ( F_64 ( V_16 , V_398 , F_65 ( V_405 -> V_377 ) ) )
goto V_78;
switch ( V_405 -> V_377 ) {
case V_378 :
case V_379 :
if ( F_63 ( V_16 , V_404 ,
V_405 -> V_22 -> V_68 ) )
goto V_78;
}
F_115 ( V_16 , V_135 ) ;
return 0 ;
V_78:
return - 1 ;
}
static int F_264 ( const struct V_13 * V_14 ,
struct V_348 * V_198 , unsigned int V_31 ,
struct V_345 * V_237 , const struct V_23 * V_24 )
{
unsigned int V_99 ;
V_99 = F_57 ( V_24 ) ;
if ( V_99 == 0 )
return - V_69 ;
if ( V_99 > V_31 )
return - V_178 ;
F_171 ( V_198 -> V_198 , V_24 , V_99 ) ;
V_237 -> type = V_287 ;
V_237 -> V_99 = V_99 ;
return 0 ;
}
static int F_265 ( struct V_15 * V_16 , const struct V_348 * V_198 ,
unsigned int V_99 )
{
return F_160 ( V_16 , V_406 , V_99 , V_198 -> V_198 ) ;
}
int F_234 ( const struct V_13 * V_14 ,
struct V_348 * V_198 , unsigned int V_31 ,
struct V_345 * V_237 , const struct V_23 * V_24 )
{
struct V_23 * V_162 [ V_407 + 1 ] ;
int V_48 ;
V_48 = F_121 ( V_162 , V_407 , V_24 , V_408 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_162 [ V_406 ] )
return F_264 ( V_14 , V_198 , V_31 , V_237 ,
V_162 [ V_406 ] ) ;
if ( V_162 [ V_409 ] && V_14 != NULL )
return F_261 ( V_14 , V_198 , V_237 , V_162 [ V_409 ] ) ;
return - V_69 ;
}
void F_229 ( const struct V_348 * V_198 , enum V_392 type )
{
if ( type < V_292 )
return;
switch ( type ) {
case V_292 :
return F_262 ( V_198 ) ;
default:
F_266 ( 1 ) ;
}
}
int F_206 ( struct V_15 * V_16 , int V_161 , const struct V_348 * V_198 ,
enum V_392 type , unsigned int V_99 )
{
struct V_23 * V_135 ;
int V_48 ;
V_135 = F_112 ( V_16 , V_161 ) ;
if ( V_135 == NULL )
return - 1 ;
switch ( type ) {
case V_287 :
V_48 = F_265 ( V_16 , V_198 , V_99 ) ;
break;
case V_292 :
V_48 = F_263 ( V_16 , V_409 , & V_198 -> V_376 ) ;
break;
default:
V_48 = - V_69 ;
F_266 ( 1 ) ;
}
F_115 ( V_16 , V_135 ) ;
return V_48 ;
}
static int T_8 F_267 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_7 . V_8 ) ;
F_2 ( & V_1 -> V_7 . V_47 ) ;
V_1 -> V_7 . V_83 = 1 ;
return 0 ;
}
int F_268 ( struct V_13 * V_14 )
{
struct V_55 * V_56 , * V_410 ;
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
struct V_55 * V_56 , * V_410 ;
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
static int T_9 F_269 ( void )
{
int V_48 ;
V_201 = F_190 ( sizeof( struct V_200 ) * V_231 ,
V_33 ) ;
if ( V_201 == NULL ) {
V_48 = - V_44 ;
goto V_115;
}
V_48 = F_270 () ;
if ( V_48 < 0 )
goto V_116;
V_48 = F_271 ( & V_411 ) ;
if ( V_48 < 0 )
goto V_120;
F_272 ( L_6 ) ;
return F_273 ( & V_412 ) ;
V_120:
F_274 () ;
V_116:
F_22 ( V_201 ) ;
V_115:
return V_48 ;
}
static void T_10 F_275 ( void )
{
F_276 ( & V_412 ) ;
F_277 ( & V_411 ) ;
F_278 () ;
F_274 () ;
F_22 ( V_201 ) ;
}
