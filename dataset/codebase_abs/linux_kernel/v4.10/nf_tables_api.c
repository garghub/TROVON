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
static struct V_29 * F_18 ( const struct V_13 * V_14 ,
int V_30 , T_1 V_31 , T_2 V_32 )
{
struct V_29 * V_33 ;
V_33 = F_19 ( sizeof( struct V_29 ) + V_31 , V_32 ) ;
if ( V_33 == NULL )
return NULL ;
V_33 -> V_30 = V_30 ;
V_33 -> V_14 = * V_14 ;
return V_33 ;
}
static struct V_29 * F_20 ( const struct V_13 * V_14 ,
int V_30 , T_1 V_31 )
{
return F_18 ( V_14 , V_30 , V_31 , V_34 ) ;
}
static void F_21 ( struct V_29 * V_33 )
{
F_22 ( & V_33 -> V_6 ) ;
F_23 ( V_33 ) ;
}
static int F_24 ( struct V_1 * V_1 ,
const struct V_19 * V_20 ,
struct V_21 * V_22 ,
unsigned int V_35 )
{
if ( V_20 -> V_36 & V_37 ||
! ( V_22 -> V_36 & V_38 ) )
return 0 ;
return F_25 ( V_1 , F_26 ( V_22 ) -> V_39 ,
V_35 ) ;
}
static void F_27 ( struct V_1 * V_1 ,
const struct V_19 * V_20 ,
struct V_21 * V_22 ,
unsigned int V_35 )
{
if ( V_20 -> V_36 & V_37 ||
! ( V_22 -> V_36 & V_38 ) )
return;
F_28 ( V_1 , F_26 ( V_22 ) -> V_39 , V_35 ) ;
}
static int F_29 ( struct V_13 * V_14 , int V_30 )
{
struct V_29 * V_33 ;
V_33 = F_20 ( V_14 , V_30 , sizeof( struct V_40 ) ) ;
if ( V_33 == NULL )
return - V_41 ;
if ( V_30 == V_42 )
F_30 ( V_14 -> V_1 , V_14 -> V_20 ) ;
F_31 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_43 ) ;
return 0 ;
}
static int F_32 ( struct V_13 * V_14 )
{
int V_44 ;
V_44 = F_29 ( V_14 , V_45 ) ;
if ( V_44 < 0 )
return V_44 ;
F_33 ( V_14 -> V_1 , V_14 -> V_20 ) ;
return V_44 ;
}
static int F_34 ( struct V_13 * V_14 , int V_30 )
{
struct V_29 * V_33 ;
V_33 = F_20 ( V_14 , V_30 , sizeof( struct V_46 ) ) ;
if ( V_33 == NULL )
return - V_41 ;
if ( V_30 == V_47 )
F_30 ( V_14 -> V_1 , V_14 -> V_22 ) ;
F_31 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_43 ) ;
return 0 ;
}
static int F_35 ( struct V_13 * V_14 )
{
int V_44 ;
V_44 = F_34 ( V_14 , V_48 ) ;
if ( V_44 < 0 )
return V_44 ;
V_14 -> V_20 -> V_49 -- ;
F_33 ( V_14 -> V_1 , V_14 -> V_22 ) ;
return V_44 ;
}
static int
F_36 ( struct V_13 * V_14 , struct V_50 * V_51 )
{
if ( F_37 ( V_14 -> V_1 , V_51 ) ) {
F_33 ( V_14 -> V_1 , V_51 ) ;
V_14 -> V_22 -> V_49 -- ;
return 0 ;
}
return - V_52 ;
}
static struct V_29 * F_38 ( struct V_13 * V_14 , int V_30 ,
struct V_50 * V_51 )
{
struct V_29 * V_33 ;
V_33 = F_20 ( V_14 , V_30 , sizeof( struct V_53 ) ) ;
if ( V_33 == NULL )
return NULL ;
V_53 ( V_33 ) = V_51 ;
F_31 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_43 ) ;
return V_33 ;
}
static int F_39 ( struct V_13 * V_14 , struct V_50 * V_51 )
{
struct V_29 * V_33 ;
int V_44 ;
V_33 = F_38 ( V_14 , V_54 , V_51 ) ;
if ( V_33 == NULL )
return - V_41 ;
V_44 = F_36 ( V_14 , V_51 ) ;
if ( V_44 < 0 ) {
F_21 ( V_33 ) ;
return V_44 ;
}
return 0 ;
}
static int F_40 ( struct V_13 * V_14 )
{
struct V_50 * V_51 ;
int V_44 ;
F_10 (rule, &ctx->chain->rules, list) {
V_44 = F_39 ( V_14 , V_51 ) ;
if ( V_44 < 0 )
return V_44 ;
}
return 0 ;
}
static int F_41 ( struct V_13 * V_14 , int V_30 ,
struct V_55 * V_56 )
{
struct V_29 * V_33 ;
V_33 = F_20 ( V_14 , V_30 , sizeof( struct V_57 ) ) ;
if ( V_33 == NULL )
return - V_41 ;
if ( V_30 == V_58 && V_14 -> V_24 [ V_59 ] != NULL ) {
F_42 ( V_33 ) =
F_43 ( F_44 ( V_14 -> V_24 [ V_59 ] ) ) ;
F_30 ( V_14 -> V_1 , V_56 ) ;
}
V_57 ( V_33 ) = V_56 ;
F_31 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_43 ) ;
return 0 ;
}
static int F_45 ( struct V_13 * V_14 , struct V_55 * V_56 )
{
int V_44 ;
V_44 = F_41 ( V_14 , V_60 , V_56 ) ;
if ( V_44 < 0 )
return V_44 ;
F_33 ( V_14 -> V_1 , V_56 ) ;
V_14 -> V_20 -> V_49 -- ;
return V_44 ;
}
static int F_46 ( struct V_13 * V_14 , int V_30 ,
struct V_61 * V_62 )
{
struct V_29 * V_33 ;
V_33 = F_20 ( V_14 , V_30 , sizeof( struct V_63 ) ) ;
if ( V_33 == NULL )
return - V_41 ;
if ( V_30 == V_64 )
F_30 ( V_14 -> V_1 , V_62 ) ;
V_63 ( V_33 ) = V_62 ;
F_31 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_43 ) ;
return 0 ;
}
static int F_47 ( struct V_13 * V_14 , struct V_61 * V_62 )
{
int V_44 ;
V_44 = F_46 ( V_14 , V_65 , V_62 ) ;
if ( V_44 < 0 )
return V_44 ;
F_33 ( V_14 -> V_1 , V_62 ) ;
V_14 -> V_20 -> V_49 -- ;
return V_44 ;
}
static struct V_19 * F_48 ( const struct V_2 * V_3 ,
const struct V_23 * V_24 ,
T_3 V_66 )
{
struct V_19 * V_20 ;
F_10 (table, &afi->tables, list) {
if ( ! F_49 ( V_24 , V_20 -> V_67 ) &&
F_50 ( V_20 , V_66 ) )
return V_20 ;
}
return NULL ;
}
static struct V_19 * F_51 ( const struct V_2 * V_3 ,
const struct V_23 * V_24 ,
T_3 V_66 )
{
struct V_19 * V_20 ;
if ( V_24 == NULL )
return F_14 ( - V_68 ) ;
V_20 = F_48 ( V_3 , V_24 , V_66 ) ;
if ( V_20 != NULL )
return V_20 ;
return F_14 ( - V_52 ) ;
}
static inline T_4 F_52 ( struct V_19 * V_20 )
{
return ++ V_20 -> V_69 ;
}
static const struct V_70 *
F_53 ( int V_9 , const struct V_23 * V_24 )
{
int V_71 ;
for ( V_71 = 0 ; V_71 < V_72 ; V_71 ++ ) {
if ( V_73 [ V_9 ] [ V_71 ] != NULL &&
! F_49 ( V_24 , V_73 [ V_9 ] [ V_71 ] -> V_67 ) )
return V_73 [ V_9 ] [ V_71 ] ;
}
return NULL ;
}
static const struct V_70 *
F_54 ( const struct V_2 * V_3 ,
const struct V_23 * V_24 ,
bool V_10 )
{
const struct V_70 * type ;
type = F_53 ( V_3 -> V_9 , V_24 ) ;
if ( type != NULL )
return type ;
#ifdef F_12
if ( V_10 ) {
F_5 ( V_5 ) ;
F_13 ( L_2 , V_3 -> V_9 ,
F_55 ( V_24 ) , ( const char * ) F_56 ( V_24 ) ) ;
F_3 ( V_5 ) ;
type = F_53 ( V_3 -> V_9 , V_24 ) ;
if ( type != NULL )
return F_14 ( - V_11 ) ;
}
#endif
return F_14 ( - V_52 ) ;
}
static int F_57 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_25 , T_1 V_27 , int V_74 , T_1 V_36 ,
int V_9 , const struct V_19 * V_20 )
{
struct V_17 * V_18 ;
struct V_75 * V_76 ;
V_74 |= V_5 << 8 ;
V_18 = F_58 ( V_16 , V_25 , V_27 , V_74 , sizeof( struct V_75 ) , V_36 ) ;
if ( V_18 == NULL )
goto V_77;
V_76 = F_59 ( V_18 ) ;
V_76 -> V_78 = V_9 ;
V_76 -> V_79 = V_80 ;
V_76 -> V_81 = F_60 ( V_1 -> V_7 . V_82 & 0xffff ) ;
if ( F_61 ( V_16 , V_83 , V_20 -> V_67 ) ||
F_62 ( V_16 , V_84 , F_63 ( V_20 -> V_36 ) ) ||
F_62 ( V_16 , V_85 , F_63 ( V_20 -> V_49 ) ) )
goto V_77;
F_64 ( V_16 , V_18 ) ;
return 0 ;
V_77:
F_65 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_66 ( const struct V_13 * V_14 , int V_74 )
{
struct V_15 * V_16 ;
int V_44 ;
if ( ! V_14 -> V_26 &&
! F_67 ( V_14 -> V_1 , V_86 ) )
return 0 ;
V_44 = - V_87 ;
V_16 = F_68 ( V_88 , V_34 ) ;
if ( V_16 == NULL )
goto V_44;
V_44 = F_57 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_14 -> V_27 ,
V_74 , 0 , V_14 -> V_3 -> V_9 , V_14 -> V_20 ) ;
if ( V_44 < 0 ) {
F_69 ( V_16 ) ;
goto V_44;
}
V_44 = F_70 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_86 ,
V_14 -> V_26 , V_34 ) ;
V_44:
if ( V_44 < 0 ) {
F_71 ( V_14 -> V_1 , V_14 -> V_25 , V_86 ,
V_44 ) ;
}
return V_44 ;
}
static int F_72 ( struct V_15 * V_16 ,
struct V_89 * V_90 )
{
const struct V_75 * V_76 = F_59 ( V_90 -> V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
unsigned int V_91 = 0 , V_92 = V_90 -> args [ 0 ] ;
struct V_1 * V_1 = F_73 ( V_16 -> V_93 ) ;
int V_9 = V_76 -> V_78 ;
F_74 () ;
V_90 -> V_27 = V_1 -> V_7 . V_82 ;
F_75 (afi, &net->nft.af_info, list) {
if ( V_9 != V_94 && V_9 != V_3 -> V_9 )
continue;
F_75 (table, &afi->tables, list) {
if ( V_91 < V_92 )
goto V_95;
if ( V_91 > V_92 )
memset ( & V_90 -> args [ 1 ] , 0 ,
sizeof( V_90 -> args ) - sizeof( V_90 -> args [ 0 ] ) ) ;
if ( ! F_76 ( V_1 , V_20 ) )
continue;
if ( F_57 ( V_16 , V_1 ,
F_16 ( V_90 -> V_16 ) . V_25 ,
V_90 -> V_18 -> V_28 ,
V_42 ,
V_96 ,
V_3 -> V_9 , V_20 ) < 0 )
goto V_97;
F_77 ( V_90 , F_78 ( V_16 ) ) ;
V_95:
V_91 ++ ;
}
}
V_97:
F_79 () ;
V_90 -> args [ 0 ] = V_91 ;
return V_16 -> V_98 ;
}
static int F_80 ( struct V_1 * V_1 , struct V_99 * V_100 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_75 * V_76 = F_59 ( V_18 ) ;
T_3 V_66 = F_81 ( V_1 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
struct V_15 * V_101 ;
int V_9 = V_76 -> V_78 ;
int V_44 ;
if ( V_18 -> V_102 & V_103 ) {
struct V_104 V_105 = {
. V_106 = F_72 ,
} ;
return F_82 ( V_100 , V_16 , V_18 , & V_105 ) ;
}
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_83 ( V_3 ) )
return F_84 ( V_3 ) ;
V_20 = F_51 ( V_3 , V_24 [ V_83 ] , V_66 ) ;
if ( F_83 ( V_20 ) )
return F_84 ( V_20 ) ;
V_101 = F_85 ( V_88 , V_34 ) ;
if ( ! V_101 )
return - V_41 ;
V_44 = F_57 ( V_101 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 , V_42 , 0 ,
V_9 , V_20 ) ;
if ( V_44 < 0 )
goto V_44;
return F_86 ( V_100 , V_101 , F_16 ( V_16 ) . V_25 ) ;
V_44:
F_69 ( V_101 ) ;
return V_44 ;
}
static int F_87 ( struct V_1 * V_1 ,
const struct V_2 * V_3 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 ;
int V_44 , V_71 = 0 ;
F_10 (chain, &table->chains, list) {
if ( ! F_37 ( V_1 , V_22 ) )
continue;
if ( ! ( V_22 -> V_36 & V_38 ) )
continue;
V_44 = F_25 ( V_1 , F_26 ( V_22 ) -> V_39 ,
V_3 -> V_107 ) ;
if ( V_44 < 0 )
goto V_44;
V_71 ++ ;
}
return 0 ;
V_44:
F_10 (chain, &table->chains, list) {
if ( ! F_37 ( V_1 , V_22 ) )
continue;
if ( ! ( V_22 -> V_36 & V_38 ) )
continue;
if ( V_71 -- <= 0 )
break;
F_28 ( V_1 , F_26 ( V_22 ) -> V_39 ,
V_3 -> V_107 ) ;
}
return V_44 ;
}
static void F_88 ( struct V_1 * V_1 ,
const struct V_2 * V_3 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 ;
F_10 (chain, &table->chains, list) {
if ( ! F_37 ( V_1 , V_22 ) )
continue;
if ( ! ( V_22 -> V_36 & V_38 ) )
continue;
F_28 ( V_1 , F_26 ( V_22 ) -> V_39 ,
V_3 -> V_107 ) ;
}
}
static int F_89 ( struct V_13 * V_14 )
{
struct V_29 * V_33 ;
T_1 V_36 ;
int V_108 = 0 ;
if ( ! V_14 -> V_24 [ V_84 ] )
return 0 ;
V_36 = F_43 ( F_44 ( V_14 -> V_24 [ V_84 ] ) ) ;
if ( V_36 & ~ V_37 )
return - V_68 ;
if ( V_36 == V_14 -> V_20 -> V_36 )
return 0 ;
V_33 = F_20 ( V_14 , V_42 ,
sizeof( struct V_40 ) ) ;
if ( V_33 == NULL )
return - V_41 ;
if ( ( V_36 & V_37 ) &&
! ( V_14 -> V_20 -> V_36 & V_37 ) ) {
F_90 ( V_33 ) = false ;
} else if ( ! ( V_36 & V_37 ) &&
V_14 -> V_20 -> V_36 & V_37 ) {
V_108 = F_87 ( V_14 -> V_1 , V_14 -> V_3 , V_14 -> V_20 ) ;
if ( V_108 >= 0 ) {
V_14 -> V_20 -> V_36 &= ~ V_37 ;
F_90 ( V_33 ) = true ;
}
}
if ( V_108 < 0 )
goto V_44;
F_91 ( V_33 ) = true ;
F_31 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_43 ) ;
return 0 ;
V_44:
F_21 ( V_33 ) ;
return V_108 ;
}
static int F_92 ( struct V_1 * V_1 , struct V_99 * V_100 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_75 * V_76 = F_59 ( V_18 ) ;
T_3 V_66 = F_93 ( V_1 ) ;
const struct V_23 * V_67 ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
int V_9 = V_76 -> V_78 ;
T_1 V_36 = 0 ;
struct V_13 V_14 ;
int V_44 ;
V_3 = F_11 ( V_1 , V_9 , true ) ;
if ( F_83 ( V_3 ) )
return F_84 ( V_3 ) ;
V_67 = V_24 [ V_83 ] ;
V_20 = F_51 ( V_3 , V_67 , V_66 ) ;
if ( F_83 ( V_20 ) ) {
if ( F_84 ( V_20 ) != - V_52 )
return F_84 ( V_20 ) ;
V_20 = NULL ;
}
if ( V_20 != NULL ) {
if ( V_18 -> V_102 & V_109 )
return - V_110 ;
if ( V_18 -> V_102 & V_111 )
return - V_112 ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return F_89 ( & V_14 ) ;
}
if ( V_24 [ V_84 ] ) {
V_36 = F_43 ( F_44 ( V_24 [ V_84 ] ) ) ;
if ( V_36 & ~ V_37 )
return - V_68 ;
}
V_44 = - V_12 ;
if ( ! F_94 ( V_3 -> V_113 ) )
goto V_114;
V_44 = - V_41 ;
V_20 = F_19 ( sizeof( * V_20 ) , V_34 ) ;
if ( V_20 == NULL )
goto V_115;
F_95 ( V_20 -> V_67 , V_67 , V_116 ) ;
F_2 ( & V_20 -> V_117 ) ;
F_2 ( & V_20 -> V_118 ) ;
F_2 ( & V_20 -> V_119 ) ;
V_20 -> V_36 = V_36 ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
V_44 = F_29 ( & V_14 , V_42 ) ;
if ( V_44 < 0 )
goto V_120;
F_4 ( & V_20 -> V_6 , & V_3 -> V_4 ) ;
return 0 ;
V_120:
F_23 ( V_20 ) ;
V_115:
F_96 ( V_3 -> V_113 ) ;
V_114:
return V_44 ;
}
static int F_97 ( struct V_13 * V_14 )
{
int V_44 ;
struct V_21 * V_22 , * V_121 ;
struct V_61 * V_62 , * V_122 ;
struct V_55 * V_56 , * V_123 ;
F_10 (chain, &ctx->table->chains, list) {
if ( ! F_37 ( V_14 -> V_1 , V_22 ) )
continue;
V_14 -> V_22 = V_22 ;
V_44 = F_40 ( V_14 ) ;
if ( V_44 < 0 )
goto V_124;
}
F_98 (set, ns, &ctx->table->sets, list) {
if ( ! F_37 ( V_14 -> V_1 , V_56 ) )
continue;
if ( V_56 -> V_36 & V_125 &&
! F_99 ( & V_56 -> V_126 ) )
continue;
V_44 = F_45 ( V_14 , V_56 ) ;
if ( V_44 < 0 )
goto V_124;
}
F_98 (obj, ne, &ctx->table->objects, list) {
V_44 = F_47 ( V_14 , V_62 ) ;
if ( V_44 < 0 )
goto V_124;
}
F_98 (chain, nc, &ctx->table->chains, list) {
if ( ! F_37 ( V_14 -> V_1 , V_22 ) )
continue;
V_14 -> V_22 = V_22 ;
V_44 = F_35 ( V_14 ) ;
if ( V_44 < 0 )
goto V_124;
}
V_44 = F_32 ( V_14 ) ;
V_124:
return V_44 ;
}
static int F_100 ( struct V_13 * V_14 , int V_9 )
{
struct V_2 * V_3 ;
struct V_19 * V_20 , * V_127 ;
const struct V_23 * const * V_24 = V_14 -> V_24 ;
int V_44 = 0 ;
F_10 (afi, &ctx->net->nft.af_info, list) {
if ( V_9 != V_128 && V_3 -> V_9 != V_9 )
continue;
V_14 -> V_3 = V_3 ;
F_98 (table, nt, &afi->tables, list) {
if ( ! F_37 ( V_14 -> V_1 , V_20 ) )
continue;
if ( V_24 [ V_83 ] &&
F_49 ( V_24 [ V_83 ] , V_20 -> V_67 ) != 0 )
continue;
V_14 -> V_20 = V_20 ;
V_44 = F_97 ( V_14 ) ;
if ( V_44 < 0 )
goto V_124;
}
}
V_124:
return V_44 ;
}
static int F_101 ( struct V_1 * V_1 , struct V_99 * V_100 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_75 * V_76 = F_59 ( V_18 ) ;
T_3 V_66 = F_93 ( V_1 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
int V_9 = V_76 -> V_78 ;
struct V_13 V_14 ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , NULL , NULL , NULL , V_24 ) ;
if ( V_9 == V_128 || V_24 [ V_83 ] == NULL )
return F_100 ( & V_14 , V_9 ) ;
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_83 ( V_3 ) )
return F_84 ( V_3 ) ;
V_20 = F_51 ( V_3 , V_24 [ V_83 ] , V_66 ) ;
if ( F_83 ( V_20 ) )
return F_84 ( V_20 ) ;
V_14 . V_3 = V_3 ;
V_14 . V_20 = V_20 ;
return F_97 ( & V_14 ) ;
}
static void F_102 ( struct V_13 * V_14 )
{
F_103 ( V_14 -> V_20 -> V_49 > 0 ) ;
F_23 ( V_14 -> V_20 ) ;
F_96 ( V_14 -> V_3 -> V_113 ) ;
}
int F_104 ( const struct V_70 * V_129 )
{
int V_44 = 0 ;
F_3 ( V_5 ) ;
if ( V_73 [ V_129 -> V_9 ] [ V_129 -> type ] != NULL ) {
V_44 = - V_130 ;
goto V_124;
}
V_73 [ V_129 -> V_9 ] [ V_129 -> type ] = V_129 ;
V_124:
F_5 ( V_5 ) ;
return V_44 ;
}
void F_105 ( const struct V_70 * V_129 )
{
F_3 ( V_5 ) ;
V_73 [ V_129 -> V_9 ] [ V_129 -> type ] = NULL ;
F_5 ( V_5 ) ;
}
static struct V_21 *
F_106 ( const struct V_19 * V_20 , T_4 V_131 ,
T_3 V_66 )
{
struct V_21 * V_22 ;
F_10 (chain, &table->chains, list) {
if ( V_22 -> V_131 == V_131 &&
F_50 ( V_22 , V_66 ) )
return V_22 ;
}
return F_14 ( - V_52 ) ;
}
static struct V_21 * F_107 ( const struct V_19 * V_20 ,
const struct V_23 * V_24 ,
T_3 V_66 )
{
struct V_21 * V_22 ;
if ( V_24 == NULL )
return F_14 ( - V_68 ) ;
F_10 (chain, &table->chains, list) {
if ( ! F_49 ( V_24 , V_22 -> V_67 ) &&
F_50 ( V_22 , V_66 ) )
return V_22 ;
}
return F_14 ( - V_52 ) ;
}
static int F_108 ( struct V_15 * V_16 , struct V_132 T_5 * V_133 )
{
struct V_132 * V_134 , V_135 ;
struct V_23 * V_136 ;
unsigned int V_27 ;
T_4 V_137 , V_138 ;
int V_139 ;
memset ( & V_135 , 0 , sizeof( V_135 ) ) ;
F_109 (cpu) {
V_134 = F_110 ( V_133 , V_139 ) ;
do {
V_27 = F_111 ( & V_134 -> V_140 ) ;
V_137 = V_134 -> V_137 ;
V_138 = V_134 -> V_138 ;
} while ( F_112 ( & V_134 -> V_140 , V_27 ) );
V_135 . V_137 += V_137 ;
V_135 . V_138 += V_138 ;
}
V_136 = F_113 ( V_16 , V_141 ) ;
if ( V_136 == NULL )
goto V_77;
if ( F_114 ( V_16 , V_142 , F_115 ( V_135 . V_137 ) ,
V_143 ) ||
F_114 ( V_16 , V_144 , F_115 ( V_135 . V_138 ) ,
V_143 ) )
goto V_77;
F_116 ( V_16 , V_136 ) ;
return 0 ;
V_77:
return - V_145 ;
}
static int F_117 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_25 , T_1 V_27 , int V_74 , T_1 V_36 ,
int V_9 , const struct V_19 * V_20 ,
const struct V_21 * V_22 )
{
struct V_17 * V_18 ;
struct V_75 * V_76 ;
V_74 |= V_5 << 8 ;
V_18 = F_58 ( V_16 , V_25 , V_27 , V_74 , sizeof( struct V_75 ) , V_36 ) ;
if ( V_18 == NULL )
goto V_77;
V_76 = F_59 ( V_18 ) ;
V_76 -> V_78 = V_9 ;
V_76 -> V_79 = V_80 ;
V_76 -> V_81 = F_60 ( V_1 -> V_7 . V_82 & 0xffff ) ;
if ( F_61 ( V_16 , V_146 , V_20 -> V_67 ) )
goto V_77;
if ( F_114 ( V_16 , V_147 , F_115 ( V_22 -> V_131 ) ,
V_148 ) )
goto V_77;
if ( F_61 ( V_16 , V_149 , V_22 -> V_67 ) )
goto V_77;
if ( V_22 -> V_36 & V_38 ) {
const struct F_26 * V_150 = F_26 ( V_22 ) ;
const struct V_151 * V_39 = & V_150 -> V_39 [ 0 ] ;
struct V_23 * V_136 ;
V_136 = F_113 ( V_16 , V_152 ) ;
if ( V_136 == NULL )
goto V_77;
if ( F_62 ( V_16 , V_153 , F_63 ( V_39 -> V_154 ) ) )
goto V_77;
if ( F_62 ( V_16 , V_155 , F_63 ( V_39 -> V_156 ) ) )
goto V_77;
if ( V_150 -> V_157 [ 0 ] &&
F_61 ( V_16 , V_158 , V_150 -> V_157 ) )
goto V_77;
F_116 ( V_16 , V_136 ) ;
if ( F_62 ( V_16 , V_159 ,
F_63 ( V_150 -> V_160 ) ) )
goto V_77;
if ( F_61 ( V_16 , V_161 , V_150 -> type -> V_67 ) )
goto V_77;
if ( F_108 ( V_16 , F_26 ( V_22 ) -> V_133 ) )
goto V_77;
}
if ( F_62 ( V_16 , V_162 , F_63 ( V_22 -> V_49 ) ) )
goto V_77;
F_64 ( V_16 , V_18 ) ;
return 0 ;
V_77:
F_65 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_118 ( const struct V_13 * V_14 , int V_74 )
{
struct V_15 * V_16 ;
int V_44 ;
if ( ! V_14 -> V_26 &&
! F_67 ( V_14 -> V_1 , V_86 ) )
return 0 ;
V_44 = - V_87 ;
V_16 = F_68 ( V_88 , V_34 ) ;
if ( V_16 == NULL )
goto V_44;
V_44 = F_117 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_14 -> V_27 ,
V_74 , 0 , V_14 -> V_3 -> V_9 , V_14 -> V_20 ,
V_14 -> V_22 ) ;
if ( V_44 < 0 ) {
F_69 ( V_16 ) ;
goto V_44;
}
V_44 = F_70 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_86 ,
V_14 -> V_26 , V_34 ) ;
V_44:
if ( V_44 < 0 ) {
F_71 ( V_14 -> V_1 , V_14 -> V_25 , V_86 ,
V_44 ) ;
}
return V_44 ;
}
static int F_119 ( struct V_15 * V_16 ,
struct V_89 * V_90 )
{
const struct V_75 * V_76 = F_59 ( V_90 -> V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
unsigned int V_91 = 0 , V_92 = V_90 -> args [ 0 ] ;
struct V_1 * V_1 = F_73 ( V_16 -> V_93 ) ;
int V_9 = V_76 -> V_78 ;
F_74 () ;
V_90 -> V_27 = V_1 -> V_7 . V_82 ;
F_75 (afi, &net->nft.af_info, list) {
if ( V_9 != V_94 && V_9 != V_3 -> V_9 )
continue;
F_75 (table, &afi->tables, list) {
F_75 (chain, &table->chains, list) {
if ( V_91 < V_92 )
goto V_95;
if ( V_91 > V_92 )
memset ( & V_90 -> args [ 1 ] , 0 ,
sizeof( V_90 -> args ) - sizeof( V_90 -> args [ 0 ] ) ) ;
if ( ! F_76 ( V_1 , V_22 ) )
continue;
if ( F_117 ( V_16 , V_1 ,
F_16 ( V_90 -> V_16 ) . V_25 ,
V_90 -> V_18 -> V_28 ,
V_47 ,
V_96 ,
V_3 -> V_9 , V_20 , V_22 ) < 0 )
goto V_97;
F_77 ( V_90 , F_78 ( V_16 ) ) ;
V_95:
V_91 ++ ;
}
}
}
V_97:
F_79 () ;
V_90 -> args [ 0 ] = V_91 ;
return V_16 -> V_98 ;
}
static int F_120 ( struct V_1 * V_1 , struct V_99 * V_100 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_75 * V_76 = F_59 ( V_18 ) ;
T_3 V_66 = F_81 ( V_1 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
struct V_15 * V_101 ;
int V_9 = V_76 -> V_78 ;
int V_44 ;
if ( V_18 -> V_102 & V_103 ) {
struct V_104 V_105 = {
. V_106 = F_119 ,
} ;
return F_82 ( V_100 , V_16 , V_18 , & V_105 ) ;
}
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_83 ( V_3 ) )
return F_84 ( V_3 ) ;
V_20 = F_51 ( V_3 , V_24 [ V_146 ] , V_66 ) ;
if ( F_83 ( V_20 ) )
return F_84 ( V_20 ) ;
V_22 = F_107 ( V_20 , V_24 [ V_149 ] , V_66 ) ;
if ( F_83 ( V_22 ) )
return F_84 ( V_22 ) ;
V_101 = F_85 ( V_88 , V_34 ) ;
if ( ! V_101 )
return - V_41 ;
V_44 = F_117 ( V_101 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 , V_47 , 0 ,
V_9 , V_20 , V_22 ) ;
if ( V_44 < 0 )
goto V_44;
return F_86 ( V_100 , V_101 , F_16 ( V_16 ) . V_25 ) ;
V_44:
F_69 ( V_101 ) ;
return V_44 ;
}
static struct V_132 T_5 * F_121 ( const struct V_23 * V_163 )
{
struct V_23 * V_164 [ V_165 + 1 ] ;
struct V_132 T_5 * V_166 ;
struct V_132 * V_133 ;
int V_44 ;
V_44 = F_122 ( V_164 , V_165 , V_163 , V_167 ) ;
if ( V_44 < 0 )
return F_14 ( V_44 ) ;
if ( ! V_164 [ V_144 ] || ! V_164 [ V_142 ] )
return F_14 ( - V_68 ) ;
V_166 = F_123 ( struct V_132 ) ;
if ( V_166 == NULL )
return F_14 ( - V_41 ) ;
F_124 () ;
V_133 = F_125 ( V_166 ) ;
V_133 -> V_138 = F_126 ( F_127 ( V_164 [ V_144 ] ) ) ;
V_133 -> V_137 = F_126 ( F_127 ( V_164 [ V_142 ] ) ) ;
F_128 () ;
return V_166 ;
}
static void F_129 ( struct F_26 * V_22 ,
struct V_132 T_5 * V_166 )
{
if ( V_166 == NULL )
return;
if ( V_22 -> V_133 ) {
struct V_132 T_5 * V_168 =
F_130 ( V_22 -> V_133 ) ;
F_131 ( V_22 -> V_133 , V_166 ) ;
F_132 () ;
F_133 ( V_168 ) ;
} else
F_131 ( V_22 -> V_133 , V_166 ) ;
}
static void F_134 ( struct V_21 * V_22 )
{
F_103 ( V_22 -> V_49 > 0 ) ;
if ( V_22 -> V_36 & V_38 ) {
struct F_26 * V_150 = F_26 ( V_22 ) ;
F_96 ( V_150 -> type -> V_113 ) ;
F_133 ( V_150 -> V_133 ) ;
if ( V_150 -> V_39 [ 0 ] . V_169 != NULL )
F_135 ( V_150 -> V_39 [ 0 ] . V_169 ) ;
F_23 ( V_150 ) ;
} else {
F_23 ( V_22 ) ;
}
}
static int F_136 ( struct V_1 * V_1 ,
const struct V_23 * const V_24 [] ,
struct V_2 * V_3 ,
struct V_170 * V_171 , bool V_172 )
{
struct V_23 * V_173 [ V_174 + 1 ] ;
const struct V_70 * type ;
struct V_175 * V_169 ;
int V_44 ;
V_44 = F_122 ( V_173 , V_174 , V_24 [ V_152 ] ,
V_176 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_173 [ V_153 ] == NULL ||
V_173 [ V_155 ] == NULL )
return - V_68 ;
V_171 -> V_177 = F_43 ( F_44 ( V_173 [ V_153 ] ) ) ;
if ( V_171 -> V_177 >= V_3 -> V_178 )
return - V_68 ;
V_171 -> V_156 = F_43 ( F_44 ( V_173 [ V_155 ] ) ) ;
type = V_73 [ V_3 -> V_9 ] [ V_179 ] ;
if ( V_24 [ V_161 ] ) {
type = F_54 ( V_3 , V_24 [ V_161 ] ,
V_172 ) ;
if ( F_83 ( type ) )
return F_84 ( type ) ;
}
if ( ! ( type -> V_180 & ( 1 << V_171 -> V_177 ) ) )
return - V_112 ;
if ( ! F_94 ( type -> V_113 ) )
return - V_52 ;
V_171 -> type = type ;
V_171 -> V_169 = NULL ;
if ( V_3 -> V_36 & V_181 ) {
char V_182 [ V_183 ] ;
if ( ! V_173 [ V_158 ] ) {
F_96 ( type -> V_113 ) ;
return - V_112 ;
}
F_95 ( V_182 , V_173 [ V_158 ] , V_183 ) ;
V_169 = F_137 ( V_1 , V_182 ) ;
if ( ! V_169 ) {
F_96 ( type -> V_113 ) ;
return - V_52 ;
}
V_171 -> V_169 = V_169 ;
} else if ( V_173 [ V_158 ] ) {
F_96 ( type -> V_113 ) ;
return - V_112 ;
}
return 0 ;
}
static void F_138 ( struct V_170 * V_171 )
{
F_96 ( V_171 -> type -> V_113 ) ;
if ( V_171 -> V_169 != NULL )
F_135 ( V_171 -> V_169 ) ;
}
static int F_139 ( struct V_1 * V_1 , struct V_99 * V_100 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_75 * V_76 = F_59 ( V_18 ) ;
const struct V_23 * V_184 ( V_67 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct F_26 * V_150 = NULL ;
T_3 V_66 = F_93 ( V_1 ) ;
int V_9 = V_76 -> V_78 ;
T_3 V_160 = V_185 ;
T_4 V_131 = 0 ;
unsigned int V_71 ;
struct V_132 T_5 * V_133 ;
int V_44 ;
bool V_172 ;
struct V_13 V_14 ;
V_172 = V_18 -> V_102 & V_186 ? true : false ;
V_3 = F_11 ( V_1 , V_9 , true ) ;
if ( F_83 ( V_3 ) )
return F_84 ( V_3 ) ;
V_20 = F_51 ( V_3 , V_24 [ V_146 ] , V_66 ) ;
if ( F_83 ( V_20 ) )
return F_84 ( V_20 ) ;
V_22 = NULL ;
V_67 = V_24 [ V_149 ] ;
if ( V_24 [ V_147 ] ) {
V_131 = F_126 ( F_127 ( V_24 [ V_147 ] ) ) ;
V_22 = F_106 ( V_20 , V_131 , V_66 ) ;
if ( F_83 ( V_22 ) )
return F_84 ( V_22 ) ;
} else {
V_22 = F_107 ( V_20 , V_67 , V_66 ) ;
if ( F_83 ( V_22 ) ) {
if ( F_84 ( V_22 ) != - V_52 )
return F_84 ( V_22 ) ;
V_22 = NULL ;
}
}
if ( V_24 [ V_159 ] ) {
if ( ( V_22 != NULL &&
! ( V_22 -> V_36 & V_38 ) ) )
return - V_112 ;
if ( V_22 == NULL &&
V_24 [ V_152 ] == NULL )
return - V_112 ;
V_160 = F_43 ( F_44 ( V_24 [ V_159 ] ) ) ;
switch ( V_160 ) {
case V_187 :
case V_185 :
break;
default:
return - V_68 ;
}
}
if ( V_22 != NULL ) {
struct V_132 * V_133 = NULL ;
struct V_29 * V_33 ;
if ( V_18 -> V_102 & V_109 )
return - V_110 ;
if ( V_18 -> V_102 & V_111 )
return - V_112 ;
if ( V_24 [ V_152 ] ) {
struct F_26 * V_150 ;
struct V_170 V_171 ;
struct V_151 * V_39 ;
if ( ! ( V_22 -> V_36 & V_38 ) )
return - V_130 ;
V_44 = F_136 ( V_1 , V_24 , V_3 , & V_171 ,
V_172 ) ;
if ( V_44 < 0 )
return V_44 ;
V_150 = F_26 ( V_22 ) ;
if ( V_150 -> type != V_171 . type ) {
F_138 ( & V_171 ) ;
return - V_130 ;
}
for ( V_71 = 0 ; V_71 < V_3 -> V_107 ; V_71 ++ ) {
V_39 = & V_150 -> V_39 [ V_71 ] ;
if ( V_39 -> V_154 != V_171 . V_177 ||
V_39 -> V_156 != V_171 . V_156 ||
V_39 -> V_169 != V_171 . V_169 ) {
F_138 ( & V_171 ) ;
return - V_130 ;
}
}
F_138 ( & V_171 ) ;
}
if ( V_24 [ V_147 ] && V_67 ) {
struct V_21 * V_188 ;
V_188 = F_107 ( V_20 ,
V_24 [ V_149 ] ,
V_66 ) ;
if ( F_83 ( V_188 ) )
return F_84 ( V_188 ) ;
}
if ( V_24 [ V_141 ] ) {
if ( ! ( V_22 -> V_36 & V_38 ) )
return - V_112 ;
V_133 = F_121 ( V_24 [ V_141 ] ) ;
if ( F_83 ( V_133 ) )
return F_84 ( V_133 ) ;
}
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_33 = F_20 ( & V_14 , V_47 ,
sizeof( struct V_46 ) ) ;
if ( V_33 == NULL ) {
F_133 ( V_133 ) ;
return - V_41 ;
}
F_140 ( V_33 ) = V_133 ;
F_141 ( V_33 ) = true ;
if ( V_24 [ V_159 ] )
F_142 ( V_33 ) = V_160 ;
else
F_142 ( V_33 ) = - 1 ;
if ( V_24 [ V_147 ] && V_67 ) {
F_95 ( F_143 ( V_33 ) , V_67 ,
V_189 ) ;
}
F_31 ( & V_33 -> V_6 , & V_1 -> V_7 . V_43 ) ;
return 0 ;
}
if ( V_20 -> V_49 == V_190 )
return - V_191 ;
if ( V_24 [ V_152 ] ) {
struct V_170 V_171 ;
struct V_151 * V_39 ;
T_6 * V_192 ;
V_44 = F_136 ( V_1 , V_24 , V_3 , & V_171 , V_172 ) ;
if ( V_44 < 0 )
return V_44 ;
V_150 = F_19 ( sizeof( * V_150 ) , V_34 ) ;
if ( V_150 == NULL ) {
F_138 ( & V_171 ) ;
return - V_41 ;
}
if ( V_171 . V_169 != NULL )
strncpy ( V_150 -> V_157 , V_171 . V_169 -> V_67 , V_183 ) ;
if ( V_24 [ V_141 ] ) {
V_133 = F_121 ( V_24 [ V_141 ] ) ;
if ( F_83 ( V_133 ) ) {
F_138 ( & V_171 ) ;
F_23 ( V_150 ) ;
return F_84 ( V_133 ) ;
}
V_150 -> V_133 = V_133 ;
} else {
V_133 = F_123 ( struct V_132 ) ;
if ( V_133 == NULL ) {
F_138 ( & V_171 ) ;
F_23 ( V_150 ) ;
return - V_41 ;
}
F_131 ( V_150 -> V_133 , V_133 ) ;
}
V_192 = V_171 . type -> V_193 [ V_171 . V_177 ] ;
V_150 -> type = V_171 . type ;
V_22 = & V_150 -> V_22 ;
for ( V_71 = 0 ; V_71 < V_3 -> V_107 ; V_71 ++ ) {
V_39 = & V_150 -> V_39 [ V_71 ] ;
V_39 -> V_194 = V_9 ;
V_39 -> V_154 = V_171 . V_177 ;
V_39 -> V_156 = V_171 . V_156 ;
V_39 -> V_195 = V_22 ;
V_39 -> V_171 = V_3 -> V_193 [ V_39 -> V_154 ] ;
V_39 -> V_169 = V_171 . V_169 ;
if ( V_192 )
V_39 -> V_171 = V_192 ;
if ( V_3 -> V_196 )
V_3 -> V_196 ( V_39 , V_71 ) ;
}
V_22 -> V_36 |= V_38 ;
V_150 -> V_160 = V_160 ;
} else {
V_22 = F_19 ( sizeof( * V_22 ) , V_34 ) ;
if ( V_22 == NULL )
return - V_41 ;
}
F_2 ( & V_22 -> V_197 ) ;
V_22 -> V_131 = F_52 ( V_20 ) ;
V_22 -> V_20 = V_20 ;
F_95 ( V_22 -> V_67 , V_67 , V_189 ) ;
V_44 = F_24 ( V_1 , V_20 , V_22 , V_3 -> V_107 ) ;
if ( V_44 < 0 )
goto V_114;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_44 = F_34 ( & V_14 , V_47 ) ;
if ( V_44 < 0 )
goto V_115;
V_20 -> V_49 ++ ;
F_4 ( & V_22 -> V_6 , & V_20 -> V_117 ) ;
return 0 ;
V_115:
F_27 ( V_1 , V_20 , V_22 , V_3 -> V_107 ) ;
V_114:
F_134 ( V_22 ) ;
return V_44 ;
}
static int F_144 ( struct V_1 * V_1 , struct V_99 * V_100 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_75 * V_76 = F_59 ( V_18 ) ;
T_3 V_66 = F_93 ( V_1 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
int V_9 = V_76 -> V_78 ;
struct V_13 V_14 ;
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_83 ( V_3 ) )
return F_84 ( V_3 ) ;
V_20 = F_51 ( V_3 , V_24 [ V_146 ] , V_66 ) ;
if ( F_83 ( V_20 ) )
return F_84 ( V_20 ) ;
V_22 = F_107 ( V_20 , V_24 [ V_149 ] , V_66 ) ;
if ( F_83 ( V_22 ) )
return F_84 ( V_22 ) ;
if ( V_22 -> V_49 > 0 )
return - V_130 ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
return F_35 ( & V_14 ) ;
}
int F_145 ( struct V_198 * type )
{
F_3 ( V_5 ) ;
if ( type -> V_9 == V_94 )
F_4 ( & type -> V_6 , & V_199 ) ;
else
F_146 ( & type -> V_6 , & V_199 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_147 ( struct V_198 * type )
{
F_3 ( V_5 ) ;
F_8 ( & type -> V_6 ) ;
F_5 ( V_5 ) ;
}
static const struct V_198 * F_148 ( T_3 V_9 ,
struct V_23 * V_24 )
{
const struct V_198 * type ;
F_10 (type, &nf_tables_expressions, list) {
if ( ! F_49 ( V_24 , type -> V_67 ) &&
( ! type -> V_9 || type -> V_9 == V_9 ) )
return type ;
}
return NULL ;
}
static const struct V_198 * F_149 ( T_3 V_9 ,
struct V_23 * V_24 )
{
const struct V_198 * type ;
if ( V_24 == NULL )
return F_14 ( - V_68 ) ;
type = F_148 ( V_9 , V_24 ) ;
if ( type != NULL && F_94 ( type -> V_113 ) )
return type ;
#ifdef F_12
if ( type == NULL ) {
F_5 ( V_5 ) ;
F_13 ( L_3 , V_9 ,
F_55 ( V_24 ) , ( char * ) F_56 ( V_24 ) ) ;
F_3 ( V_5 ) ;
if ( F_148 ( V_9 , V_24 ) )
return F_14 ( - V_11 ) ;
F_5 ( V_5 ) ;
F_13 ( L_4 ,
F_55 ( V_24 ) , ( char * ) F_56 ( V_24 ) ) ;
F_3 ( V_5 ) ;
if ( F_148 ( V_9 , V_24 ) )
return F_14 ( - V_11 ) ;
}
#endif
return F_14 ( - V_52 ) ;
}
static int F_150 ( struct V_15 * V_16 ,
const struct V_200 * V_201 )
{
if ( F_61 ( V_16 , V_202 , V_201 -> V_39 -> type -> V_67 ) )
goto V_77;
if ( V_201 -> V_39 -> V_106 ) {
struct V_23 * V_203 = F_113 ( V_16 , V_204 ) ;
if ( V_203 == NULL )
goto V_77;
if ( V_201 -> V_39 -> V_106 ( V_16 , V_201 ) < 0 )
goto V_77;
F_116 ( V_16 , V_203 ) ;
}
return V_16 -> V_98 ;
V_77:
return - 1 ;
}
int F_151 ( struct V_15 * V_16 , unsigned int V_163 ,
const struct V_200 * V_201 )
{
struct V_23 * V_136 ;
V_136 = F_113 ( V_16 , V_163 ) ;
if ( ! V_136 )
goto V_77;
if ( F_150 ( V_16 , V_201 ) < 0 )
goto V_77;
F_116 ( V_16 , V_136 ) ;
return 0 ;
V_77:
return - 1 ;
}
static int F_152 ( const struct V_13 * V_14 ,
const struct V_23 * V_24 ,
struct V_205 * V_206 )
{
const struct V_198 * type ;
const struct V_207 * V_39 ;
struct V_23 * V_164 [ V_208 + 1 ] ;
int V_44 ;
V_44 = F_122 ( V_164 , V_208 , V_24 , V_209 ) ;
if ( V_44 < 0 )
return V_44 ;
type = F_149 ( V_14 -> V_3 -> V_9 , V_164 [ V_202 ] ) ;
if ( F_83 ( type ) )
return F_84 ( type ) ;
if ( V_164 [ V_204 ] ) {
V_44 = F_122 ( V_206 -> V_164 , type -> V_210 ,
V_164 [ V_204 ] , type -> V_160 ) ;
if ( V_44 < 0 )
goto V_114;
} else
memset ( V_206 -> V_164 , 0 , sizeof( V_206 -> V_164 [ 0 ] ) * ( type -> V_210 + 1 ) ) ;
if ( type -> V_211 != NULL ) {
V_39 = type -> V_211 ( V_14 ,
( const struct V_23 * const * ) V_206 -> V_164 ) ;
if ( F_83 ( V_39 ) ) {
V_44 = F_84 ( V_39 ) ;
goto V_114;
}
} else
V_39 = type -> V_39 ;
V_206 -> V_39 = V_39 ;
return 0 ;
V_114:
F_96 ( type -> V_113 ) ;
return V_44 ;
}
static int F_153 ( const struct V_13 * V_14 ,
const struct V_205 * V_206 ,
struct V_200 * V_201 )
{
const struct V_207 * V_39 = V_206 -> V_39 ;
int V_44 ;
V_201 -> V_39 = V_39 ;
if ( V_39 -> V_212 ) {
V_44 = V_39 -> V_212 ( V_14 , V_201 , ( const struct V_23 * * ) V_206 -> V_164 ) ;
if ( V_44 < 0 )
goto V_114;
}
return 0 ;
V_114:
V_201 -> V_39 = NULL ;
return V_44 ;
}
static void F_154 ( const struct V_13 * V_14 ,
struct V_200 * V_201 )
{
if ( V_201 -> V_39 -> V_213 )
V_201 -> V_39 -> V_213 ( V_14 , V_201 ) ;
F_96 ( V_201 -> V_39 -> type -> V_113 ) ;
}
struct V_200 * F_155 ( const struct V_13 * V_14 ,
const struct V_23 * V_24 )
{
struct V_205 V_206 ;
struct V_200 * V_201 ;
int V_44 ;
V_44 = F_152 ( V_14 , V_24 , & V_206 ) ;
if ( V_44 < 0 )
goto V_114;
V_44 = - V_41 ;
V_201 = F_19 ( V_206 . V_39 -> V_31 , V_34 ) ;
if ( V_201 == NULL )
goto V_115;
V_44 = F_153 ( V_14 , & V_206 , V_201 ) ;
if ( V_44 < 0 )
goto V_120;
return V_201 ;
V_120:
F_23 ( V_201 ) ;
V_115:
F_96 ( V_206 . V_39 -> type -> V_113 ) ;
V_114:
return F_14 ( V_44 ) ;
}
void F_156 ( const struct V_13 * V_14 , struct V_200 * V_201 )
{
F_154 ( V_14 , V_201 ) ;
F_23 ( V_201 ) ;
}
static struct V_50 * F_157 ( const struct V_21 * V_22 ,
T_4 V_131 )
{
struct V_50 * V_51 ;
F_10 (rule, &chain->rules, list) {
if ( V_131 == V_51 -> V_131 )
return V_51 ;
}
return F_14 ( - V_52 ) ;
}
static struct V_50 * F_158 ( const struct V_21 * V_22 ,
const struct V_23 * V_24 )
{
if ( V_24 == NULL )
return F_14 ( - V_68 ) ;
return F_157 ( V_22 , F_126 ( F_127 ( V_24 ) ) ) ;
}
static int F_159 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_25 , T_1 V_27 , int V_74 ,
T_1 V_36 , int V_9 ,
const struct V_19 * V_20 ,
const struct V_21 * V_22 ,
const struct V_50 * V_51 )
{
struct V_17 * V_18 ;
struct V_75 * V_76 ;
const struct V_200 * V_201 , * V_214 ;
struct V_23 * V_6 ;
const struct V_50 * V_215 ;
int type = V_74 | V_5 << 8 ;
V_18 = F_58 ( V_16 , V_25 , V_27 , type , sizeof( struct V_75 ) ,
V_36 ) ;
if ( V_18 == NULL )
goto V_77;
V_76 = F_59 ( V_18 ) ;
V_76 -> V_78 = V_9 ;
V_76 -> V_79 = V_80 ;
V_76 -> V_81 = F_60 ( V_1 -> V_7 . V_82 & 0xffff ) ;
if ( F_61 ( V_16 , V_216 , V_20 -> V_67 ) )
goto V_77;
if ( F_61 ( V_16 , V_217 , V_22 -> V_67 ) )
goto V_77;
if ( F_114 ( V_16 , V_218 , F_115 ( V_51 -> V_131 ) ,
V_219 ) )
goto V_77;
if ( ( V_74 != V_54 ) && ( V_51 -> V_6 . V_220 != & V_22 -> V_197 ) ) {
V_215 = F_160 ( V_51 -> V_6 . V_220 , struct V_50 , V_6 ) ;
if ( F_114 ( V_16 , V_221 ,
F_115 ( V_215 -> V_131 ) ,
V_219 ) )
goto V_77;
}
V_6 = F_113 ( V_16 , V_222 ) ;
if ( V_6 == NULL )
goto V_77;
F_161 (expr, next, rule) {
if ( F_151 ( V_16 , V_223 , V_201 ) < 0 )
goto V_77;
}
F_116 ( V_16 , V_6 ) ;
if ( V_51 -> V_224 ) {
struct V_225 * V_224 = V_225 ( V_51 ) ;
if ( F_162 ( V_16 , V_226 , V_224 -> V_98 + 1 ,
V_224 -> V_203 ) < 0 )
goto V_77;
}
F_64 ( V_16 , V_18 ) ;
return 0 ;
V_77:
F_65 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_163 ( const struct V_13 * V_14 ,
const struct V_50 * V_51 ,
int V_74 )
{
struct V_15 * V_16 ;
int V_44 ;
if ( ! V_14 -> V_26 &&
! F_67 ( V_14 -> V_1 , V_86 ) )
return 0 ;
V_44 = - V_87 ;
V_16 = F_68 ( V_88 , V_34 ) ;
if ( V_16 == NULL )
goto V_44;
V_44 = F_159 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_14 -> V_27 ,
V_74 , 0 , V_14 -> V_3 -> V_9 , V_14 -> V_20 ,
V_14 -> V_22 , V_51 ) ;
if ( V_44 < 0 ) {
F_69 ( V_16 ) ;
goto V_44;
}
V_44 = F_70 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_86 ,
V_14 -> V_26 , V_34 ) ;
V_44:
if ( V_44 < 0 ) {
F_71 ( V_14 -> V_1 , V_14 -> V_25 , V_86 ,
V_44 ) ;
}
return V_44 ;
}
static int F_164 ( struct V_15 * V_16 ,
struct V_89 * V_90 )
{
const struct V_75 * V_76 = F_59 ( V_90 -> V_18 ) ;
const struct V_227 * V_14 = V_90 -> V_203 ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
const struct V_50 * V_51 ;
unsigned int V_91 = 0 , V_92 = V_90 -> args [ 0 ] ;
struct V_1 * V_1 = F_73 ( V_16 -> V_93 ) ;
int V_9 = V_76 -> V_78 ;
F_74 () ;
V_90 -> V_27 = V_1 -> V_7 . V_82 ;
F_75 (afi, &net->nft.af_info, list) {
if ( V_9 != V_94 && V_9 != V_3 -> V_9 )
continue;
F_75 (table, &afi->tables, list) {
if ( V_14 && V_14 -> V_20 [ 0 ] &&
strcmp ( V_14 -> V_20 , V_20 -> V_67 ) != 0 )
continue;
F_75 (chain, &table->chains, list) {
if ( V_14 && V_14 -> V_22 [ 0 ] &&
strcmp ( V_14 -> V_22 , V_22 -> V_67 ) != 0 )
continue;
F_75 (rule, &chain->rules, list) {
if ( ! F_76 ( V_1 , V_51 ) )
goto V_95;
if ( V_91 < V_92 )
goto V_95;
if ( V_91 > V_92 )
memset ( & V_90 -> args [ 1 ] , 0 ,
sizeof( V_90 -> args ) - sizeof( V_90 -> args [ 0 ] ) ) ;
if ( F_159 ( V_16 , V_1 , F_16 ( V_90 -> V_16 ) . V_25 ,
V_90 -> V_18 -> V_28 ,
V_228 ,
V_96 | V_229 ,
V_3 -> V_9 , V_20 , V_22 , V_51 ) < 0 )
goto V_97;
F_77 ( V_90 , F_78 ( V_16 ) ) ;
V_95:
V_91 ++ ;
}
}
}
}
V_97:
F_79 () ;
V_90 -> args [ 0 ] = V_91 ;
return V_16 -> V_98 ;
}
static int F_165 ( struct V_89 * V_90 )
{
F_23 ( V_90 -> V_203 ) ;
return 0 ;
}
static int F_166 ( struct V_1 * V_1 , struct V_99 * V_100 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_75 * V_76 = F_59 ( V_18 ) ;
T_3 V_66 = F_81 ( V_1 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
const struct V_50 * V_51 ;
struct V_15 * V_101 ;
int V_9 = V_76 -> V_78 ;
int V_44 ;
if ( V_18 -> V_102 & V_103 ) {
struct V_104 V_105 = {
. V_106 = F_164 ,
. V_97 = F_165 ,
} ;
if ( V_24 [ V_216 ] || V_24 [ V_217 ] ) {
struct V_227 * V_14 ;
V_14 = F_19 ( sizeof( * V_14 ) , V_34 ) ;
if ( ! V_14 )
return - V_41 ;
if ( V_24 [ V_216 ] )
F_95 ( V_14 -> V_20 , V_24 [ V_216 ] ,
sizeof( V_14 -> V_20 ) ) ;
if ( V_24 [ V_217 ] )
F_95 ( V_14 -> V_22 , V_24 [ V_217 ] ,
sizeof( V_14 -> V_22 ) ) ;
V_105 . V_203 = V_14 ;
}
return F_82 ( V_100 , V_16 , V_18 , & V_105 ) ;
}
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_83 ( V_3 ) )
return F_84 ( V_3 ) ;
V_20 = F_51 ( V_3 , V_24 [ V_216 ] , V_66 ) ;
if ( F_83 ( V_20 ) )
return F_84 ( V_20 ) ;
V_22 = F_107 ( V_20 , V_24 [ V_217 ] , V_66 ) ;
if ( F_83 ( V_22 ) )
return F_84 ( V_22 ) ;
V_51 = F_158 ( V_22 , V_24 [ V_218 ] ) ;
if ( F_83 ( V_51 ) )
return F_84 ( V_51 ) ;
V_101 = F_85 ( V_88 , V_34 ) ;
if ( ! V_101 )
return - V_41 ;
V_44 = F_159 ( V_101 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 , V_228 , 0 ,
V_9 , V_20 , V_22 , V_51 ) ;
if ( V_44 < 0 )
goto V_44;
return F_86 ( V_100 , V_101 , F_16 ( V_16 ) . V_25 ) ;
V_44:
F_69 ( V_101 ) ;
return V_44 ;
}
static void F_167 ( const struct V_13 * V_14 ,
struct V_50 * V_51 )
{
struct V_200 * V_201 ;
V_201 = F_168 ( V_51 ) ;
while ( V_201 != F_169 ( V_51 ) && V_201 -> V_39 ) {
F_154 ( V_14 , V_201 ) ;
V_201 = F_170 ( V_201 ) ;
}
F_23 ( V_51 ) ;
}
static int F_171 ( struct V_1 * V_1 , struct V_99 * V_100 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_75 * V_76 = F_59 ( V_18 ) ;
T_3 V_66 = F_93 ( V_1 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_50 * V_51 , * V_230 = NULL ;
struct V_225 * V_224 ;
struct V_29 * V_33 = NULL ;
struct V_200 * V_201 ;
struct V_13 V_14 ;
struct V_23 * V_231 ;
unsigned int V_31 , V_71 , V_232 , V_233 = 0 , V_234 = 0 ;
int V_44 , V_235 ;
bool V_172 ;
T_4 V_131 , V_236 ;
V_172 = V_18 -> V_102 & V_186 ? true : false ;
V_3 = F_11 ( V_1 , V_76 -> V_78 , V_172 ) ;
if ( F_83 ( V_3 ) )
return F_84 ( V_3 ) ;
V_20 = F_51 ( V_3 , V_24 [ V_216 ] , V_66 ) ;
if ( F_83 ( V_20 ) )
return F_84 ( V_20 ) ;
V_22 = F_107 ( V_20 , V_24 [ V_217 ] , V_66 ) ;
if ( F_83 ( V_22 ) )
return F_84 ( V_22 ) ;
if ( V_24 [ V_218 ] ) {
V_131 = F_126 ( F_127 ( V_24 [ V_218 ] ) ) ;
V_51 = F_157 ( V_22 , V_131 ) ;
if ( F_83 ( V_51 ) )
return F_84 ( V_51 ) ;
if ( V_18 -> V_102 & V_109 )
return - V_110 ;
if ( V_18 -> V_102 & V_111 )
V_230 = V_51 ;
else
return - V_112 ;
} else {
if ( ! V_172 || V_18 -> V_102 & V_111 )
return - V_68 ;
V_131 = F_52 ( V_20 ) ;
if ( V_22 -> V_49 == V_190 )
return - V_191 ;
}
if ( V_24 [ V_221 ] ) {
if ( ! ( V_18 -> V_102 & V_186 ) )
return - V_112 ;
V_236 = F_126 ( F_127 ( V_24 [ V_221 ] ) ) ;
V_230 = F_157 ( V_22 , V_236 ) ;
if ( F_83 ( V_230 ) )
return F_84 ( V_230 ) ;
}
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_232 = 0 ;
V_31 = 0 ;
if ( V_24 [ V_222 ] ) {
F_172 (tmp, nla[NFTA_RULE_EXPRESSIONS], rem) {
V_44 = - V_68 ;
if ( F_173 ( V_231 ) != V_223 )
goto V_114;
if ( V_232 == V_237 )
goto V_114;
V_44 = F_152 ( & V_14 , V_231 , & V_206 [ V_232 ] ) ;
if ( V_44 < 0 )
goto V_114;
V_31 += V_206 [ V_232 ] . V_39 -> V_31 ;
V_232 ++ ;
}
}
V_44 = - V_238 ;
if ( V_31 >= 1 << 12 )
goto V_114;
if ( V_24 [ V_226 ] ) {
V_233 = F_55 ( V_24 [ V_226 ] ) ;
if ( V_233 > 0 )
V_234 = sizeof( struct V_225 ) + V_233 ;
}
V_44 = - V_41 ;
V_51 = F_19 ( sizeof( * V_51 ) + V_31 + V_234 , V_34 ) ;
if ( V_51 == NULL )
goto V_114;
F_30 ( V_1 , V_51 ) ;
V_51 -> V_131 = V_131 ;
V_51 -> V_239 = V_31 ;
V_51 -> V_224 = V_233 ? 1 : 0 ;
if ( V_233 ) {
V_224 = V_225 ( V_51 ) ;
V_224 -> V_98 = V_233 - 1 ;
F_174 ( V_224 -> V_203 , V_24 [ V_226 ] , V_233 ) ;
}
V_201 = F_168 ( V_51 ) ;
for ( V_71 = 0 ; V_71 < V_232 ; V_71 ++ ) {
V_44 = F_153 ( & V_14 , & V_206 [ V_71 ] , V_201 ) ;
if ( V_44 < 0 )
goto V_115;
V_206 [ V_71 ] . V_39 = NULL ;
V_201 = F_170 ( V_201 ) ;
}
if ( V_18 -> V_102 & V_111 ) {
if ( F_37 ( V_1 , V_230 ) ) {
V_33 = F_38 ( & V_14 , V_54 ,
V_230 ) ;
if ( V_33 == NULL ) {
V_44 = - V_41 ;
goto V_115;
}
F_33 ( V_1 , V_230 ) ;
V_22 -> V_49 -- ;
F_4 ( & V_51 -> V_6 , & V_230 -> V_6 ) ;
} else {
V_44 = - V_52 ;
goto V_115;
}
} else if ( V_18 -> V_102 & V_229 )
if ( V_230 )
F_146 ( & V_51 -> V_6 , & V_230 -> V_6 ) ;
else
F_4 ( & V_51 -> V_6 , & V_22 -> V_197 ) ;
else {
if ( V_230 )
F_4 ( & V_51 -> V_6 , & V_230 -> V_6 ) ;
else
F_146 ( & V_51 -> V_6 , & V_22 -> V_197 ) ;
}
if ( F_38 ( & V_14 , V_228 , V_51 ) == NULL ) {
V_44 = - V_41 ;
goto V_120;
}
V_22 -> V_49 ++ ;
return 0 ;
V_120:
F_8 ( & V_51 -> V_6 ) ;
V_115:
F_167 ( & V_14 , V_51 ) ;
V_114:
for ( V_71 = 0 ; V_71 < V_232 ; V_71 ++ ) {
if ( V_206 [ V_71 ] . V_39 != NULL )
F_96 ( V_206 [ V_71 ] . V_39 -> type -> V_113 ) ;
}
return V_44 ;
}
static int F_175 ( struct V_1 * V_1 , struct V_99 * V_100 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_75 * V_76 = F_59 ( V_18 ) ;
T_3 V_66 = F_93 ( V_1 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 = NULL ;
struct V_50 * V_51 ;
int V_9 = V_76 -> V_78 , V_44 = 0 ;
struct V_13 V_14 ;
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_83 ( V_3 ) )
return F_84 ( V_3 ) ;
V_20 = F_51 ( V_3 , V_24 [ V_216 ] , V_66 ) ;
if ( F_83 ( V_20 ) )
return F_84 ( V_20 ) ;
if ( V_24 [ V_217 ] ) {
V_22 = F_107 ( V_20 , V_24 [ V_217 ] ,
V_66 ) ;
if ( F_83 ( V_22 ) )
return F_84 ( V_22 ) ;
}
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
if ( V_22 ) {
if ( V_24 [ V_218 ] ) {
V_51 = F_158 ( V_22 ,
V_24 [ V_218 ] ) ;
if ( F_83 ( V_51 ) )
return F_84 ( V_51 ) ;
V_44 = F_39 ( & V_14 , V_51 ) ;
} else {
V_44 = F_40 ( & V_14 ) ;
}
} else {
F_10 (chain, &table->chains, list) {
if ( ! F_37 ( V_1 , V_22 ) )
continue;
V_14 . V_22 = V_22 ;
V_44 = F_40 ( & V_14 ) ;
if ( V_44 < 0 )
break;
}
}
return V_44 ;
}
int F_176 ( struct V_240 * V_39 )
{
F_3 ( V_5 ) ;
F_4 ( & V_39 -> V_6 , & V_241 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_177 ( struct V_240 * V_39 )
{
F_3 ( V_5 ) ;
F_8 ( & V_39 -> V_6 ) ;
F_5 ( V_5 ) ;
}
static const struct V_240 *
F_178 ( const struct V_23 * const V_24 [] ,
const struct V_242 * V_243 ,
enum V_244 V_160 )
{
const struct V_240 * V_39 , * V_245 ;
struct V_246 V_247 , V_248 ;
T_1 V_249 ;
#ifdef F_12
if ( F_99 ( & V_241 ) ) {
F_5 ( V_5 ) ;
F_13 ( L_5 ) ;
F_3 ( V_5 ) ;
if ( ! F_99 ( & V_241 ) )
return F_14 ( - V_11 ) ;
}
#endif
V_249 = 0 ;
if ( V_24 [ V_250 ] != NULL ) {
V_249 = F_43 ( F_44 ( V_24 [ V_250 ] ) ) ;
V_249 &= V_251 | V_252 | V_253 ;
}
V_245 = NULL ;
V_248 . V_31 = ~ 0 ;
V_248 . V_254 = ~ 0 ;
F_10 (ops, &nf_tables_set_ops, list) {
if ( ( V_39 -> V_249 & V_249 ) != V_249 )
continue;
if ( ! V_39 -> V_255 ( V_243 , V_249 , & V_247 ) )
continue;
switch ( V_160 ) {
case V_256 :
if ( V_247 . V_254 < V_248 . V_254 )
break;
if ( V_247 . V_254 == V_248 . V_254 && V_247 . V_31 < V_248 . V_31 )
break;
continue;
case V_257 :
if ( V_247 . V_31 < V_248 . V_31 )
break;
if ( V_247 . V_31 == V_248 . V_31 && V_247 . V_254 < V_248 . V_254 )
break;
continue;
default:
break;
}
if ( ! F_94 ( V_39 -> V_113 ) )
continue;
if ( V_245 != NULL )
F_96 ( V_245 -> V_113 ) ;
V_245 = V_39 ;
V_248 = V_247 ;
}
if ( V_245 != NULL )
return V_245 ;
return F_14 ( - V_112 ) ;
}
static int F_179 ( struct V_13 * V_14 , struct V_1 * V_1 ,
const struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
T_3 V_66 )
{
const struct V_75 * V_76 = F_59 ( V_18 ) ;
struct V_2 * V_3 = NULL ;
struct V_19 * V_20 = NULL ;
if ( V_76 -> V_78 != V_94 ) {
V_3 = F_11 ( V_1 , V_76 -> V_78 , false ) ;
if ( F_83 ( V_3 ) )
return F_84 ( V_3 ) ;
}
if ( V_24 [ V_258 ] != NULL ) {
if ( V_3 == NULL )
return - V_12 ;
V_20 = F_51 ( V_3 , V_24 [ V_258 ] ,
V_66 ) ;
if ( F_83 ( V_20 ) )
return F_84 ( V_20 ) ;
}
F_15 ( V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return 0 ;
}
struct V_55 * F_180 ( const struct V_19 * V_20 ,
const struct V_23 * V_24 , T_3 V_66 )
{
struct V_55 * V_56 ;
if ( V_24 == NULL )
return F_14 ( - V_68 ) ;
F_10 (set, &table->sets, list) {
if ( ! F_49 ( V_24 , V_56 -> V_67 ) &&
F_50 ( V_56 , V_66 ) )
return V_56 ;
}
return F_14 ( - V_52 ) ;
}
struct V_55 * F_181 ( const struct V_1 * V_1 ,
const struct V_23 * V_24 ,
T_3 V_66 )
{
struct V_29 * V_33 ;
T_1 V_259 = F_43 ( F_44 ( V_24 ) ) ;
F_10 (trans, &net->nft.commit_list, list) {
struct V_55 * V_56 = V_57 ( V_33 ) ;
if ( V_33 -> V_30 == V_58 &&
V_259 == F_42 ( V_33 ) &&
F_50 ( V_56 , V_66 ) )
return V_56 ;
}
return F_14 ( - V_52 ) ;
}
static int F_182 ( struct V_13 * V_14 , struct V_55 * V_56 ,
const char * V_67 )
{
const struct V_55 * V_71 ;
const char * V_260 ;
unsigned long * V_261 ;
unsigned int V_232 = 0 , V_262 = 0 ;
V_260 = F_183 ( V_67 , V_263 , '%' ) ;
if ( V_260 != NULL ) {
if ( V_260 [ 1 ] != 'd' || strchr ( V_260 + 2 , '%' ) )
return - V_68 ;
V_261 = ( unsigned long * ) F_184 ( V_34 ) ;
if ( V_261 == NULL )
return - V_41 ;
V_95:
F_10 (i, &ctx->table->sets, list) {
int V_231 ;
if ( ! F_37 ( V_14 -> V_1 , V_56 ) )
continue;
if ( ! sscanf ( V_71 -> V_67 , V_67 , & V_231 ) )
continue;
if ( V_231 < V_262 || V_231 >= V_262 + V_264 * V_265 )
continue;
F_185 ( V_231 - V_262 , V_261 ) ;
}
V_232 = F_186 ( V_261 , V_264 * V_265 ) ;
if ( V_232 >= V_264 * V_265 ) {
V_262 += V_264 * V_265 ;
memset ( V_261 , 0 , V_265 ) ;
goto V_95;
}
F_187 ( ( unsigned long ) V_261 ) ;
}
snprintf ( V_56 -> V_67 , sizeof( V_56 -> V_67 ) , V_67 , V_262 + V_232 ) ;
F_10 (i, &ctx->table->sets, list) {
if ( ! F_37 ( V_14 -> V_1 , V_71 ) )
continue;
if ( ! strcmp ( V_56 -> V_67 , V_71 -> V_67 ) )
return - V_266 ;
}
return 0 ;
}
static int F_188 ( struct V_15 * V_16 , const struct V_13 * V_14 ,
const struct V_55 * V_56 , T_7 V_74 , T_7 V_36 )
{
struct V_75 * V_76 ;
struct V_17 * V_18 ;
struct V_23 * V_243 ;
T_1 V_25 = V_14 -> V_25 ;
T_1 V_27 = V_14 -> V_27 ;
V_74 |= V_5 << 8 ;
V_18 = F_58 ( V_16 , V_25 , V_27 , V_74 , sizeof( struct V_75 ) ,
V_36 ) ;
if ( V_18 == NULL )
goto V_77;
V_76 = F_59 ( V_18 ) ;
V_76 -> V_78 = V_14 -> V_3 -> V_9 ;
V_76 -> V_79 = V_80 ;
V_76 -> V_81 = F_60 ( V_14 -> V_1 -> V_7 . V_82 & 0xffff ) ;
if ( F_61 ( V_16 , V_258 , V_14 -> V_20 -> V_67 ) )
goto V_77;
if ( F_61 ( V_16 , V_267 , V_56 -> V_67 ) )
goto V_77;
if ( V_56 -> V_36 != 0 )
if ( F_62 ( V_16 , V_250 , F_63 ( V_56 -> V_36 ) ) )
goto V_77;
if ( F_62 ( V_16 , V_268 , F_63 ( V_56 -> V_269 ) ) )
goto V_77;
if ( F_62 ( V_16 , V_270 , F_63 ( V_56 -> V_271 ) ) )
goto V_77;
if ( V_56 -> V_36 & V_252 ) {
if ( F_62 ( V_16 , V_272 , F_63 ( V_56 -> V_273 ) ) )
goto V_77;
if ( F_62 ( V_16 , V_274 , F_63 ( V_56 -> V_239 ) ) )
goto V_77;
}
if ( V_56 -> V_36 & V_275 &&
F_62 ( V_16 , V_276 , F_63 ( V_56 -> V_277 ) ) )
goto V_77;
if ( V_56 -> V_278 &&
F_114 ( V_16 , V_279 ,
F_115 ( F_189 ( V_56 -> V_278 ) ) ,
V_280 ) )
goto V_77;
if ( V_56 -> V_281 &&
F_62 ( V_16 , V_282 , F_63 ( V_56 -> V_281 ) ) )
goto V_77;
if ( V_56 -> V_160 != V_256 ) {
if ( F_62 ( V_16 , V_283 , F_63 ( V_56 -> V_160 ) ) )
goto V_77;
}
if ( F_162 ( V_16 , V_284 , V_56 -> V_285 , V_56 -> V_224 ) )
goto V_77;
V_243 = F_113 ( V_16 , V_286 ) ;
if ( V_243 == NULL )
goto V_77;
if ( V_56 -> V_31 &&
F_62 ( V_16 , V_287 , F_63 ( V_56 -> V_31 ) ) )
goto V_77;
F_116 ( V_16 , V_243 ) ;
F_64 ( V_16 , V_18 ) ;
return 0 ;
V_77:
F_65 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_190 ( const struct V_13 * V_14 ,
const struct V_55 * V_56 ,
int V_74 , T_2 V_288 )
{
struct V_15 * V_16 ;
T_1 V_25 = V_14 -> V_25 ;
int V_44 ;
if ( ! V_14 -> V_26 &&
! F_67 ( V_14 -> V_1 , V_86 ) )
return 0 ;
V_44 = - V_87 ;
V_16 = F_68 ( V_88 , V_288 ) ;
if ( V_16 == NULL )
goto V_44;
V_44 = F_188 ( V_16 , V_14 , V_56 , V_74 , 0 ) ;
if ( V_44 < 0 ) {
F_69 ( V_16 ) ;
goto V_44;
}
V_44 = F_70 ( V_16 , V_14 -> V_1 , V_25 , V_86 ,
V_14 -> V_26 , V_288 ) ;
V_44:
if ( V_44 < 0 )
F_71 ( V_14 -> V_1 , V_25 , V_86 , V_44 ) ;
return V_44 ;
}
static int F_191 ( struct V_15 * V_16 , struct V_89 * V_90 )
{
const struct V_55 * V_56 ;
unsigned int V_91 , V_92 = V_90 -> args [ 0 ] ;
struct V_2 * V_3 ;
struct V_19 * V_20 , * V_289 = (struct V_19 * ) V_90 -> args [ 2 ] ;
struct V_1 * V_1 = F_73 ( V_16 -> V_93 ) ;
int V_290 = V_90 -> args [ 3 ] ;
struct V_13 * V_14 = V_90 -> V_203 , V_291 ;
if ( V_90 -> args [ 1 ] )
return V_16 -> V_98 ;
F_74 () ;
V_90 -> V_27 = V_1 -> V_7 . V_82 ;
F_75 (afi, &net->nft.af_info, list) {
if ( V_14 -> V_3 && V_14 -> V_3 != V_3 )
continue;
if ( V_290 ) {
if ( V_3 -> V_9 != V_290 )
continue;
V_290 = 0 ;
}
F_75 (table, &afi->tables, list) {
if ( V_14 -> V_20 && V_14 -> V_20 != V_20 )
continue;
if ( V_289 ) {
if ( V_289 != V_20 )
continue;
V_289 = NULL ;
}
V_91 = 0 ;
F_75 (set, &table->sets, list) {
if ( V_91 < V_92 )
goto V_95;
if ( ! F_76 ( V_1 , V_56 ) )
goto V_95;
V_291 = * V_14 ;
V_291 . V_20 = V_20 ;
V_291 . V_3 = V_3 ;
if ( F_188 ( V_16 , & V_291 , V_56 ,
V_58 ,
V_96 ) < 0 ) {
V_90 -> args [ 0 ] = V_91 ;
V_90 -> args [ 2 ] = ( unsigned long ) V_20 ;
V_90 -> args [ 3 ] = V_3 -> V_9 ;
goto V_97;
}
F_77 ( V_90 , F_78 ( V_16 ) ) ;
V_95:
V_91 ++ ;
}
if ( V_92 )
V_92 = 0 ;
}
}
V_90 -> args [ 1 ] = 1 ;
V_97:
F_79 () ;
return V_16 -> V_98 ;
}
static int F_192 ( struct V_89 * V_90 )
{
F_23 ( V_90 -> V_203 ) ;
return 0 ;
}
static int F_193 ( struct V_1 * V_1 , struct V_99 * V_100 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
T_3 V_66 = F_81 ( V_1 ) ;
const struct V_55 * V_56 ;
struct V_13 V_14 ;
struct V_15 * V_101 ;
const struct V_75 * V_76 = F_59 ( V_18 ) ;
int V_44 ;
V_44 = F_179 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_66 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_18 -> V_102 & V_103 ) {
struct V_104 V_105 = {
. V_106 = F_191 ,
. V_97 = F_192 ,
} ;
struct V_13 * V_292 ;
V_292 = F_194 ( sizeof( * V_292 ) , V_34 ) ;
if ( V_292 == NULL )
return - V_41 ;
* V_292 = V_14 ;
V_105 . V_203 = V_292 ;
return F_82 ( V_100 , V_16 , V_18 , & V_105 ) ;
}
if ( V_76 -> V_78 == V_94 )
return - V_12 ;
if ( ! V_24 [ V_258 ] )
return - V_68 ;
V_56 = F_180 ( V_14 . V_20 , V_24 [ V_267 ] , V_66 ) ;
if ( F_83 ( V_56 ) )
return F_84 ( V_56 ) ;
V_101 = F_85 ( V_88 , V_34 ) ;
if ( V_101 == NULL )
return - V_41 ;
V_44 = F_188 ( V_101 , & V_14 , V_56 , V_58 , 0 ) ;
if ( V_44 < 0 )
goto V_44;
return F_86 ( V_100 , V_101 , F_16 ( V_16 ) . V_25 ) ;
V_44:
F_69 ( V_101 ) ;
return V_44 ;
}
static int F_195 ( const struct V_13 * V_14 ,
struct V_242 * V_243 ,
const struct V_23 * V_24 )
{
struct V_23 * V_293 [ V_294 + 1 ] ;
int V_44 ;
V_44 = F_122 ( V_293 , V_294 , V_24 , V_295 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_293 [ V_287 ] != NULL )
V_243 -> V_31 = F_43 ( F_44 ( V_293 [ V_287 ] ) ) ;
return 0 ;
}
static int F_196 ( struct V_1 * V_1 , struct V_99 * V_100 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_75 * V_76 = F_59 ( V_18 ) ;
T_3 V_66 = F_93 ( V_1 ) ;
const struct V_240 * V_39 ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_55 * V_56 ;
struct V_13 V_14 ;
char V_67 [ V_263 ] ;
unsigned int V_31 ;
bool V_172 ;
T_4 V_278 ;
T_1 V_269 , V_273 , V_36 , V_160 , V_281 , V_277 ;
struct V_242 V_243 ;
unsigned char * V_224 ;
T_7 V_285 ;
int V_44 ;
if ( V_24 [ V_258 ] == NULL ||
V_24 [ V_267 ] == NULL ||
V_24 [ V_270 ] == NULL ||
V_24 [ V_59 ] == NULL )
return - V_68 ;
memset ( & V_243 , 0 , sizeof( V_243 ) ) ;
V_269 = V_296 ;
if ( V_24 [ V_268 ] != NULL ) {
V_269 = F_43 ( F_44 ( V_24 [ V_268 ] ) ) ;
if ( ( V_269 & V_297 ) == V_297 )
return - V_68 ;
}
V_243 . V_271 = F_43 ( F_44 ( V_24 [ V_270 ] ) ) ;
if ( V_243 . V_271 == 0 || V_243 . V_271 > V_298 )
return - V_68 ;
V_36 = 0 ;
if ( V_24 [ V_250 ] != NULL ) {
V_36 = F_43 ( F_44 ( V_24 [ V_250 ] ) ) ;
if ( V_36 & ~ ( V_125 | V_299 |
V_251 | V_253 |
V_252 | V_300 |
V_275 ) )
return - V_68 ;
if ( ( V_36 & ( V_252 | V_300 | V_275 ) ) ==
( V_252 | V_300 | V_275 ) )
return - V_112 ;
}
V_273 = 0 ;
if ( V_24 [ V_272 ] != NULL ) {
if ( ! ( V_36 & V_252 ) )
return - V_68 ;
V_273 = F_43 ( F_44 ( V_24 [ V_272 ] ) ) ;
if ( ( V_273 & V_297 ) == V_297 &&
V_273 != V_301 )
return - V_68 ;
if ( V_273 != V_301 ) {
if ( V_24 [ V_274 ] == NULL )
return - V_68 ;
V_243 . V_239 = F_43 ( F_44 ( V_24 [ V_274 ] ) ) ;
if ( V_243 . V_239 == 0 || V_243 . V_239 > V_298 )
return - V_68 ;
} else
V_243 . V_239 = sizeof( struct V_302 ) ;
} else if ( V_36 & V_252 )
return - V_68 ;
if ( V_24 [ V_276 ] != NULL ) {
if ( ! ( V_36 & V_275 ) )
return - V_68 ;
V_277 = F_43 ( F_44 ( V_24 [ V_276 ] ) ) ;
if ( V_277 == V_303 ||
V_277 > V_304 )
return - V_68 ;
} else if ( V_36 & V_275 )
return - V_68 ;
else
V_277 = V_303 ;
V_278 = 0 ;
if ( V_24 [ V_279 ] != NULL ) {
if ( ! ( V_36 & V_253 ) )
return - V_68 ;
V_278 = F_197 ( F_126 ( F_127 (
V_24 [ V_279 ] ) ) ) ;
}
V_281 = 0 ;
if ( V_24 [ V_282 ] != NULL ) {
if ( ! ( V_36 & V_253 ) )
return - V_68 ;
V_281 = F_43 ( F_44 ( V_24 [ V_282 ] ) ) ;
}
V_160 = V_256 ;
if ( V_24 [ V_283 ] != NULL )
V_160 = F_43 ( F_44 ( V_24 [ V_283 ] ) ) ;
if ( V_24 [ V_286 ] != NULL ) {
V_44 = F_195 ( & V_14 , & V_243 , V_24 [ V_286 ] ) ;
if ( V_44 < 0 )
return V_44 ;
}
V_172 = V_18 -> V_102 & V_186 ? true : false ;
V_3 = F_11 ( V_1 , V_76 -> V_78 , V_172 ) ;
if ( F_83 ( V_3 ) )
return F_84 ( V_3 ) ;
V_20 = F_51 ( V_3 , V_24 [ V_258 ] , V_66 ) ;
if ( F_83 ( V_20 ) )
return F_84 ( V_20 ) ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
V_56 = F_180 ( V_20 , V_24 [ V_267 ] , V_66 ) ;
if ( F_83 ( V_56 ) ) {
if ( F_84 ( V_56 ) != - V_52 )
return F_84 ( V_56 ) ;
V_56 = NULL ;
}
if ( V_56 != NULL ) {
if ( V_18 -> V_102 & V_109 )
return - V_110 ;
if ( V_18 -> V_102 & V_111 )
return - V_112 ;
return 0 ;
}
if ( ! ( V_18 -> V_102 & V_186 ) )
return - V_52 ;
V_39 = F_178 ( V_24 , & V_243 , V_160 ) ;
if ( F_83 ( V_39 ) )
return F_84 ( V_39 ) ;
V_285 = 0 ;
if ( V_24 [ V_284 ] )
V_285 = F_55 ( V_24 [ V_284 ] ) ;
V_31 = 0 ;
if ( V_39 -> V_305 != NULL )
V_31 = V_39 -> V_305 ( V_24 ) ;
V_44 = - V_41 ;
V_56 = F_19 ( sizeof( * V_56 ) + V_31 + V_285 , V_34 ) ;
if ( V_56 == NULL )
goto V_114;
F_95 ( V_67 , V_24 [ V_267 ] , sizeof( V_56 -> V_67 ) ) ;
V_44 = F_182 ( & V_14 , V_56 , V_67 ) ;
if ( V_44 < 0 )
goto V_115;
V_224 = NULL ;
if ( V_285 ) {
V_224 = V_56 -> V_203 + V_31 ;
F_174 ( V_224 , V_24 [ V_284 ] , V_285 ) ;
}
F_2 ( & V_56 -> V_126 ) ;
V_56 -> V_39 = V_39 ;
V_56 -> V_269 = V_269 ;
V_56 -> V_271 = V_243 . V_271 ;
V_56 -> V_273 = V_273 ;
V_56 -> V_277 = V_277 ;
V_56 -> V_239 = V_243 . V_239 ;
V_56 -> V_36 = V_36 ;
V_56 -> V_31 = V_243 . V_31 ;
V_56 -> V_160 = V_160 ;
V_56 -> V_285 = V_285 ;
V_56 -> V_224 = V_224 ;
V_56 -> V_278 = V_278 ;
V_56 -> V_281 = V_281 ;
V_44 = V_39 -> V_212 ( V_56 , & V_243 , V_24 ) ;
if ( V_44 < 0 )
goto V_115;
V_44 = F_41 ( & V_14 , V_58 , V_56 ) ;
if ( V_44 < 0 )
goto V_120;
F_4 ( & V_56 -> V_6 , & V_20 -> V_118 ) ;
V_20 -> V_49 ++ ;
return 0 ;
V_120:
V_39 -> V_213 ( V_56 ) ;
V_115:
F_23 ( V_56 ) ;
V_114:
F_96 ( V_39 -> V_113 ) ;
return V_44 ;
}
static void F_198 ( struct V_55 * V_56 )
{
V_56 -> V_39 -> V_213 ( V_56 ) ;
F_96 ( V_56 -> V_39 -> V_113 ) ;
F_23 ( V_56 ) ;
}
static void F_199 ( const struct V_13 * V_14 , struct V_55 * V_56 )
{
F_8 ( & V_56 -> V_6 ) ;
F_190 ( V_14 , V_56 , V_60 , V_306 ) ;
F_198 ( V_56 ) ;
}
static int F_200 ( struct V_1 * V_1 , struct V_99 * V_100 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_75 * V_76 = F_59 ( V_18 ) ;
T_3 V_66 = F_93 ( V_1 ) ;
struct V_55 * V_56 ;
struct V_13 V_14 ;
int V_44 ;
if ( V_76 -> V_78 == V_94 )
return - V_12 ;
if ( V_24 [ V_258 ] == NULL )
return - V_68 ;
V_44 = F_179 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_66 ) ;
if ( V_44 < 0 )
return V_44 ;
V_56 = F_180 ( V_14 . V_20 , V_24 [ V_267 ] , V_66 ) ;
if ( F_83 ( V_56 ) )
return F_84 ( V_56 ) ;
if ( ! F_99 ( & V_56 -> V_126 ) )
return - V_130 ;
return F_45 ( & V_14 , V_56 ) ;
}
static int F_201 ( const struct V_13 * V_14 ,
struct V_55 * V_56 ,
const struct V_307 * V_308 ,
struct V_309 * V_310 )
{
const struct V_311 * V_312 = F_202 ( V_56 , V_310 -> V_195 ) ;
enum V_313 V_314 ;
V_314 = F_203 ( V_56 -> V_273 ) ;
return F_204 ( V_14 , V_314 , F_205 ( V_312 ) ,
V_56 -> V_273 == V_301 ?
V_301 : V_296 ,
V_56 -> V_239 ) ;
}
int F_206 ( const struct V_13 * V_14 , struct V_55 * V_56 ,
struct V_315 * V_316 )
{
struct V_315 * V_71 ;
struct V_307 V_308 ;
if ( ! F_99 ( & V_56 -> V_126 ) && V_56 -> V_36 & V_125 )
return - V_130 ;
if ( V_316 -> V_36 & V_252 ) {
F_10 (i, &set->bindings, list) {
if ( V_71 -> V_36 & V_252 &&
V_71 -> V_22 == V_316 -> V_22 )
goto V_317;
}
V_308 . V_66 = F_93 ( V_14 -> V_1 ) ;
V_308 . V_318 = 0 ;
V_308 . V_319 = 0 ;
V_308 . V_44 = 0 ;
V_308 . V_320 = F_201 ;
V_56 -> V_39 -> V_321 ( V_14 , V_56 , & V_308 ) ;
if ( V_308 . V_44 < 0 )
return V_308 . V_44 ;
}
V_317:
V_316 -> V_22 = V_14 -> V_22 ;
F_4 ( & V_316 -> V_6 , & V_56 -> V_126 ) ;
return 0 ;
}
void F_207 ( const struct V_13 * V_14 , struct V_55 * V_56 ,
struct V_315 * V_316 )
{
F_8 ( & V_316 -> V_6 ) ;
if ( F_99 ( & V_56 -> V_126 ) && V_56 -> V_36 & V_125 &&
F_76 ( V_14 -> V_1 , V_56 ) )
F_199 ( V_14 , V_56 ) ;
}
static int F_208 ( struct V_13 * V_14 , struct V_1 * V_1 ,
const struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
T_3 V_66 )
{
const struct V_75 * V_76 = F_59 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
V_3 = F_11 ( V_1 , V_76 -> V_78 , false ) ;
if ( F_83 ( V_3 ) )
return F_84 ( V_3 ) ;
V_20 = F_51 ( V_3 , V_24 [ V_322 ] ,
V_66 ) ;
if ( F_83 ( V_20 ) )
return F_84 ( V_20 ) ;
F_15 ( V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return 0 ;
}
static int F_209 ( struct V_15 * V_16 ,
const struct V_55 * V_56 ,
const struct V_309 * V_310 )
{
const struct V_311 * V_312 = F_202 ( V_56 , V_310 -> V_195 ) ;
unsigned char * V_323 = F_210 ( V_16 ) ;
struct V_23 * V_136 ;
V_136 = F_113 ( V_16 , V_223 ) ;
if ( V_136 == NULL )
goto V_77;
if ( F_211 ( V_16 , V_324 , F_212 ( V_312 ) ,
V_296 , V_56 -> V_271 ) < 0 )
goto V_77;
if ( F_213 ( V_312 , V_325 ) &&
F_211 ( V_16 , V_326 , F_205 ( V_312 ) ,
V_56 -> V_273 == V_301 ? V_301 : V_296 ,
V_56 -> V_239 ) < 0 )
goto V_77;
if ( F_213 ( V_312 , V_327 ) &&
F_151 ( V_16 , V_328 , F_214 ( V_312 ) ) < 0 )
goto V_77;
if ( F_213 ( V_312 , V_329 ) &&
F_61 ( V_16 , V_330 ,
( * F_215 ( V_312 ) ) -> V_67 ) < 0 )
goto V_77;
if ( F_213 ( V_312 , V_331 ) &&
F_62 ( V_16 , V_332 ,
F_63 ( * F_216 ( V_312 ) ) ) )
goto V_77;
if ( F_213 ( V_312 , V_333 ) &&
F_114 ( V_16 , V_334 ,
F_115 ( F_189 (
* F_217 ( V_312 ) ) ) ,
V_335 ) )
goto V_77;
if ( F_213 ( V_312 , V_336 ) ) {
unsigned long V_337 , V_338 = V_339 ;
V_337 = * F_218 ( V_312 ) ;
if ( F_219 ( V_338 , V_337 ) )
V_337 -= V_338 ;
else
V_337 = 0 ;
if ( F_114 ( V_16 , V_340 ,
F_115 ( F_189 ( V_337 ) ) ,
V_335 ) )
goto V_77;
}
if ( F_213 ( V_312 , V_341 ) ) {
struct V_225 * V_224 ;
V_224 = F_220 ( V_312 ) ;
if ( F_162 ( V_16 , V_342 ,
V_224 -> V_98 + 1 , V_224 -> V_203 ) )
goto V_77;
}
F_116 ( V_16 , V_136 ) ;
return 0 ;
V_77:
F_65 ( V_16 , V_323 ) ;
return - V_343 ;
}
static int F_221 ( const struct V_13 * V_14 ,
struct V_55 * V_56 ,
const struct V_307 * V_308 ,
struct V_309 * V_310 )
{
struct V_344 * args ;
args = F_222 ( V_308 , struct V_344 , V_308 ) ;
return F_209 ( args -> V_16 , V_56 , V_310 ) ;
}
static int F_223 ( struct V_15 * V_16 , struct V_89 * V_90 )
{
struct V_1 * V_1 = F_73 ( V_16 -> V_93 ) ;
T_3 V_66 = F_81 ( V_1 ) ;
struct V_55 * V_56 ;
struct V_344 args ;
struct V_13 V_14 ;
struct V_23 * V_24 [ V_345 + 1 ] ;
struct V_75 * V_76 ;
struct V_17 * V_18 ;
struct V_23 * V_136 ;
T_1 V_25 , V_27 ;
int V_74 , V_44 ;
V_44 = F_224 ( V_90 -> V_18 , sizeof( struct V_75 ) , V_24 ,
V_345 , V_346 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_208 ( & V_14 , V_1 , V_90 -> V_16 , V_90 -> V_18 ,
( void * ) V_24 , V_66 ) ;
if ( V_44 < 0 )
return V_44 ;
V_56 = F_180 ( V_14 . V_20 , V_24 [ V_347 ] ,
V_66 ) ;
if ( F_83 ( V_56 ) )
return F_84 ( V_56 ) ;
V_74 = V_348 ;
V_74 |= V_5 << 8 ;
V_25 = F_16 ( V_90 -> V_16 ) . V_25 ;
V_27 = V_90 -> V_18 -> V_28 ;
V_18 = F_58 ( V_16 , V_25 , V_27 , V_74 , sizeof( struct V_75 ) ,
V_96 ) ;
if ( V_18 == NULL )
goto V_77;
V_76 = F_59 ( V_18 ) ;
V_76 -> V_78 = V_14 . V_3 -> V_9 ;
V_76 -> V_79 = V_80 ;
V_76 -> V_81 = F_60 ( V_14 . V_1 -> V_7 . V_82 & 0xffff ) ;
if ( F_61 ( V_16 , V_322 , V_14 . V_20 -> V_67 ) )
goto V_77;
if ( F_61 ( V_16 , V_347 , V_56 -> V_67 ) )
goto V_77;
V_136 = F_113 ( V_16 , V_349 ) ;
if ( V_136 == NULL )
goto V_77;
args . V_90 = V_90 ;
args . V_16 = V_16 ;
args . V_308 . V_66 = F_81 ( V_14 . V_1 ) ;
args . V_308 . V_318 = V_90 -> args [ 0 ] ;
args . V_308 . V_319 = 0 ;
args . V_308 . V_44 = 0 ;
args . V_308 . V_320 = F_221 ;
V_56 -> V_39 -> V_321 ( & V_14 , V_56 , & args . V_308 ) ;
F_116 ( V_16 , V_136 ) ;
F_64 ( V_16 , V_18 ) ;
if ( args . V_308 . V_44 && args . V_308 . V_44 != - V_343 )
return args . V_308 . V_44 ;
if ( args . V_308 . V_319 == V_90 -> args [ 0 ] )
return 0 ;
V_90 -> args [ 0 ] = args . V_308 . V_319 ;
return V_16 -> V_98 ;
V_77:
return - V_145 ;
}
static int F_225 ( struct V_1 * V_1 , struct V_99 * V_100 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
T_3 V_66 = F_81 ( V_1 ) ;
const struct V_55 * V_56 ;
struct V_13 V_14 ;
int V_44 ;
V_44 = F_208 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_66 ) ;
if ( V_44 < 0 )
return V_44 ;
V_56 = F_180 ( V_14 . V_20 , V_24 [ V_347 ] ,
V_66 ) ;
if ( F_83 ( V_56 ) )
return F_84 ( V_56 ) ;
if ( V_18 -> V_102 & V_103 ) {
struct V_104 V_105 = {
. V_106 = F_223 ,
} ;
return F_82 ( V_100 , V_16 , V_18 , & V_105 ) ;
}
return - V_112 ;
}
static int F_226 ( struct V_15 * V_16 ,
const struct V_13 * V_14 , T_1 V_27 ,
T_1 V_25 , int V_74 , T_7 V_36 ,
const struct V_55 * V_56 ,
const struct V_309 * V_310 )
{
struct V_75 * V_76 ;
struct V_17 * V_18 ;
struct V_23 * V_136 ;
int V_44 ;
V_74 |= V_5 << 8 ;
V_18 = F_58 ( V_16 , V_25 , V_27 , V_74 , sizeof( struct V_75 ) ,
V_36 ) ;
if ( V_18 == NULL )
goto V_77;
V_76 = F_59 ( V_18 ) ;
V_76 -> V_78 = V_14 -> V_3 -> V_9 ;
V_76 -> V_79 = V_80 ;
V_76 -> V_81 = F_60 ( V_14 -> V_1 -> V_7 . V_82 & 0xffff ) ;
if ( F_61 ( V_16 , V_258 , V_14 -> V_20 -> V_67 ) )
goto V_77;
if ( F_61 ( V_16 , V_267 , V_56 -> V_67 ) )
goto V_77;
V_136 = F_113 ( V_16 , V_349 ) ;
if ( V_136 == NULL )
goto V_77;
V_44 = F_209 ( V_16 , V_56 , V_310 ) ;
if ( V_44 < 0 )
goto V_77;
F_116 ( V_16 , V_136 ) ;
F_64 ( V_16 , V_18 ) ;
return 0 ;
V_77:
F_65 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_227 ( const struct V_13 * V_14 ,
const struct V_55 * V_56 ,
const struct V_309 * V_310 ,
int V_74 , T_7 V_36 )
{
struct V_1 * V_1 = V_14 -> V_1 ;
T_1 V_25 = V_14 -> V_25 ;
struct V_15 * V_16 ;
int V_44 ;
if ( ! V_14 -> V_26 && ! F_67 ( V_1 , V_86 ) )
return 0 ;
V_44 = - V_87 ;
V_16 = F_68 ( V_88 , V_34 ) ;
if ( V_16 == NULL )
goto V_44;
V_44 = F_226 ( V_16 , V_14 , 0 , V_25 , V_74 , V_36 ,
V_56 , V_310 ) ;
if ( V_44 < 0 ) {
F_69 ( V_16 ) ;
goto V_44;
}
V_44 = F_70 ( V_16 , V_1 , V_25 , V_86 , V_14 -> V_26 ,
V_34 ) ;
V_44:
if ( V_44 < 0 )
F_71 ( V_1 , V_25 , V_86 , V_44 ) ;
return V_44 ;
}
static struct V_29 * F_228 ( struct V_13 * V_14 ,
int V_30 ,
struct V_55 * V_56 )
{
struct V_29 * V_33 ;
V_33 = F_20 ( V_14 , V_30 , sizeof( struct V_350 ) ) ;
if ( V_33 == NULL )
return NULL ;
F_229 ( V_33 ) = V_56 ;
return V_33 ;
}
void * F_230 ( const struct V_55 * V_56 ,
const struct V_351 * V_352 ,
const T_1 * V_353 , const T_1 * V_203 ,
T_4 V_278 , T_2 V_32 )
{
struct V_311 * V_312 ;
void * V_310 ;
V_310 = F_19 ( V_56 -> V_39 -> V_354 + V_352 -> V_98 , V_32 ) ;
if ( V_310 == NULL )
return NULL ;
V_312 = F_202 ( V_56 , V_310 ) ;
F_231 ( V_312 , V_352 ) ;
memcpy ( F_212 ( V_312 ) , V_353 , V_56 -> V_271 ) ;
if ( F_213 ( V_312 , V_325 ) )
memcpy ( F_205 ( V_312 ) , V_203 , V_56 -> V_239 ) ;
if ( F_213 ( V_312 , V_336 ) )
* F_218 ( V_312 ) =
V_339 + V_278 ;
if ( F_213 ( V_312 , V_333 ) )
* F_217 ( V_312 ) = V_278 ;
return V_310 ;
}
void F_232 ( const struct V_55 * V_56 , void * V_310 ,
bool V_355 )
{
struct V_311 * V_312 = F_202 ( V_56 , V_310 ) ;
F_233 ( F_212 ( V_312 ) , V_296 ) ;
if ( F_213 ( V_312 , V_325 ) )
F_233 ( F_205 ( V_312 ) , V_56 -> V_273 ) ;
if ( V_355 && F_213 ( V_312 , V_327 ) )
F_154 ( NULL , F_214 ( V_312 ) ) ;
if ( F_213 ( V_312 , V_329 ) )
( * F_215 ( V_312 ) ) -> V_49 -- ;
F_23 ( V_310 ) ;
}
static int F_234 ( const struct V_55 * V_56 ,
const struct V_23 * V_163 , T_1 * V_36 )
{
if ( V_163 == NULL )
return 0 ;
* V_36 = F_43 ( F_44 ( V_163 ) ) ;
if ( * V_36 & ~ V_356 )
return - V_68 ;
if ( ! ( V_56 -> V_36 & V_251 ) &&
* V_36 & V_356 )
return - V_68 ;
return 0 ;
}
static int F_235 ( struct V_13 * V_14 , struct V_55 * V_56 ,
const struct V_23 * V_163 , T_1 V_102 )
{
struct V_23 * V_24 [ V_357 + 1 ] ;
T_3 V_66 = F_93 ( V_14 -> V_1 ) ;
struct V_358 V_359 , V_360 ;
struct V_351 V_352 ;
struct V_311 * V_312 , * V_361 ;
struct V_309 V_310 ;
struct V_315 * V_316 ;
struct V_61 * V_62 = NULL ;
struct V_225 * V_224 ;
struct V_362 V_203 ;
enum V_313 V_314 ;
struct V_29 * V_33 ;
T_1 V_36 = 0 ;
T_4 V_278 ;
T_3 V_233 ;
int V_44 ;
V_44 = F_122 ( V_24 , V_357 , V_163 ,
V_363 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_24 [ V_324 ] == NULL )
return - V_68 ;
F_236 ( & V_352 ) ;
V_44 = F_234 ( V_56 , V_24 [ V_332 ] , & V_36 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_36 != 0 )
F_237 ( & V_352 , V_331 ) ;
if ( V_56 -> V_36 & V_252 ) {
if ( V_24 [ V_326 ] == NULL &&
! ( V_36 & V_356 ) )
return - V_68 ;
if ( V_24 [ V_326 ] != NULL &&
V_36 & V_356 )
return - V_68 ;
} else {
if ( V_24 [ V_326 ] != NULL )
return - V_68 ;
}
V_278 = 0 ;
if ( V_24 [ V_334 ] != NULL ) {
if ( ! ( V_56 -> V_36 & V_253 ) )
return - V_68 ;
V_278 = F_197 ( F_126 ( F_127 (
V_24 [ V_334 ] ) ) ) ;
} else if ( V_56 -> V_36 & V_253 ) {
V_278 = V_56 -> V_278 ;
}
V_44 = F_238 ( V_14 , & V_310 . V_353 . V_364 , sizeof( V_310 . V_353 ) , & V_359 ,
V_24 [ V_324 ] ) ;
if ( V_44 < 0 )
goto V_114;
V_44 = - V_68 ;
if ( V_359 . type != V_296 || V_359 . V_98 != V_56 -> V_271 )
goto V_115;
F_239 ( & V_352 , V_365 , V_359 . V_98 ) ;
if ( V_278 > 0 ) {
F_237 ( & V_352 , V_336 ) ;
if ( V_278 != V_56 -> V_278 )
F_237 ( & V_352 , V_333 ) ;
}
if ( V_24 [ V_330 ] != NULL ) {
if ( ! ( V_56 -> V_36 & V_275 ) ) {
V_44 = - V_68 ;
goto V_115;
}
V_62 = F_240 ( V_14 -> V_20 , V_24 [ V_330 ] ,
V_56 -> V_277 , V_66 ) ;
if ( F_83 ( V_62 ) ) {
V_44 = F_84 ( V_62 ) ;
goto V_115;
}
F_237 ( & V_352 , V_329 ) ;
}
if ( V_24 [ V_326 ] != NULL ) {
V_44 = F_238 ( V_14 , & V_203 , sizeof( V_203 ) , & V_360 ,
V_24 [ V_326 ] ) ;
if ( V_44 < 0 )
goto V_115;
V_44 = - V_68 ;
if ( V_56 -> V_273 != V_301 && V_360 . V_98 != V_56 -> V_239 )
goto V_120;
V_314 = F_203 ( V_56 -> V_273 ) ;
F_10 (binding, &set->bindings, list) {
struct V_13 V_366 = {
. V_1 = V_14 -> V_1 ,
. V_3 = V_14 -> V_3 ,
. V_20 = V_14 -> V_20 ,
. V_22 = (struct V_21 * ) V_316 -> V_22 ,
} ;
if ( ! ( V_316 -> V_36 & V_252 ) )
continue;
V_44 = F_204 ( & V_366 , V_314 ,
& V_203 ,
V_360 . type , V_360 . V_98 ) ;
if ( V_44 < 0 )
goto V_120;
}
F_239 ( & V_352 , V_325 , V_360 . V_98 ) ;
}
V_233 = 0 ;
if ( V_24 [ V_342 ] != NULL ) {
V_233 = F_55 ( V_24 [ V_342 ] ) ;
if ( V_233 > 0 )
F_239 ( & V_352 , V_341 ,
V_233 ) ;
}
V_44 = - V_41 ;
V_310 . V_195 = F_230 ( V_56 , & V_352 , V_310 . V_353 . V_364 . V_203 , V_203 . V_203 ,
V_278 , V_34 ) ;
if ( V_310 . V_195 == NULL )
goto V_120;
V_312 = F_202 ( V_56 , V_310 . V_195 ) ;
if ( V_36 )
* F_216 ( V_312 ) = V_36 ;
if ( V_233 > 0 ) {
V_224 = F_220 ( V_312 ) ;
V_224 -> V_98 = V_233 - 1 ;
F_174 ( & V_224 -> V_203 , V_24 [ V_342 ] , V_233 ) ;
}
if ( V_62 ) {
* F_215 ( V_312 ) = V_62 ;
V_62 -> V_49 ++ ;
}
V_33 = F_228 ( V_14 , V_348 , V_56 ) ;
if ( V_33 == NULL )
goto V_367;
V_312 -> V_66 = F_81 ( V_14 -> V_1 ) | V_368 ;
V_44 = V_56 -> V_39 -> V_369 ( V_14 -> V_1 , V_56 , & V_310 , & V_361 ) ;
if ( V_44 ) {
if ( V_44 == - V_110 ) {
if ( ( F_213 ( V_312 , V_325 ) &&
F_213 ( V_361 , V_325 ) &&
memcmp ( F_205 ( V_312 ) ,
F_205 ( V_361 ) , V_56 -> V_239 ) != 0 ) ||
( F_213 ( V_312 , V_329 ) &&
F_213 ( V_361 , V_329 ) &&
* F_215 ( V_312 ) != * F_215 ( V_361 ) ) )
V_44 = - V_130 ;
else if ( ! ( V_102 & V_109 ) )
V_44 = 0 ;
}
goto V_370;
}
if ( V_56 -> V_31 &&
! F_241 ( & V_56 -> V_371 , 1 , V_56 -> V_31 + V_56 -> V_372 ) ) {
V_44 = - V_266 ;
goto V_373;
}
V_350 ( V_33 ) = V_310 ;
F_31 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_43 ) ;
return 0 ;
V_373:
V_56 -> V_39 -> remove ( V_56 , & V_310 ) ;
V_370:
F_23 ( V_33 ) ;
V_367:
F_23 ( V_310 . V_195 ) ;
V_120:
if ( V_24 [ V_326 ] != NULL )
F_233 ( & V_203 , V_360 . type ) ;
V_115:
F_233 ( & V_310 . V_353 . V_364 , V_359 . type ) ;
V_114:
return V_44 ;
}
static int F_242 ( struct V_1 * V_1 , struct V_99 * V_100 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
T_3 V_66 = F_93 ( V_1 ) ;
const struct V_23 * V_163 ;
struct V_55 * V_56 ;
struct V_13 V_14 ;
int V_235 , V_44 = 0 ;
if ( V_24 [ V_349 ] == NULL )
return - V_68 ;
V_44 = F_208 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_66 ) ;
if ( V_44 < 0 )
return V_44 ;
V_56 = F_180 ( V_14 . V_20 , V_24 [ V_347 ] ,
V_66 ) ;
if ( F_83 ( V_56 ) ) {
if ( V_24 [ V_374 ] ) {
V_56 = F_181 ( V_1 ,
V_24 [ V_374 ] ,
V_66 ) ;
}
if ( F_83 ( V_56 ) )
return F_84 ( V_56 ) ;
}
if ( ! F_99 ( & V_56 -> V_126 ) && V_56 -> V_36 & V_299 )
return - V_130 ;
F_172 (attr, nla[NFTA_SET_ELEM_LIST_ELEMENTS], rem) {
V_44 = F_235 ( & V_14 , V_56 , V_163 , V_18 -> V_102 ) ;
if ( V_44 < 0 )
break;
}
return V_44 ;
}
static int F_243 ( struct V_13 * V_14 , struct V_55 * V_56 ,
const struct V_23 * V_163 )
{
struct V_23 * V_24 [ V_357 + 1 ] ;
struct V_351 V_352 ;
struct V_358 V_243 ;
struct V_309 V_310 ;
struct V_311 * V_312 ;
struct V_29 * V_33 ;
T_1 V_36 = 0 ;
void * V_195 ;
int V_44 ;
V_44 = F_122 ( V_24 , V_357 , V_163 ,
V_363 ) ;
if ( V_44 < 0 )
goto V_114;
V_44 = - V_68 ;
if ( V_24 [ V_324 ] == NULL )
goto V_114;
F_236 ( & V_352 ) ;
V_44 = F_234 ( V_56 , V_24 [ V_332 ] , & V_36 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_36 != 0 )
F_237 ( & V_352 , V_331 ) ;
V_44 = F_238 ( V_14 , & V_310 . V_353 . V_364 , sizeof( V_310 . V_353 ) , & V_243 ,
V_24 [ V_324 ] ) ;
if ( V_44 < 0 )
goto V_114;
V_44 = - V_68 ;
if ( V_243 . type != V_296 || V_243 . V_98 != V_56 -> V_271 )
goto V_115;
F_239 ( & V_352 , V_365 , V_243 . V_98 ) ;
V_44 = - V_41 ;
V_310 . V_195 = F_230 ( V_56 , & V_352 , V_310 . V_353 . V_364 . V_203 , NULL , 0 ,
V_34 ) ;
if ( V_310 . V_195 == NULL )
goto V_115;
V_312 = F_202 ( V_56 , V_310 . V_195 ) ;
if ( V_36 )
* F_216 ( V_312 ) = V_36 ;
V_33 = F_228 ( V_14 , V_375 , V_56 ) ;
if ( V_33 == NULL ) {
V_44 = - V_41 ;
goto V_120;
}
V_195 = V_56 -> V_39 -> V_376 ( V_14 -> V_1 , V_56 , & V_310 ) ;
if ( V_195 == NULL ) {
V_44 = - V_52 ;
goto V_367;
}
F_23 ( V_310 . V_195 ) ;
V_310 . V_195 = V_195 ;
V_350 ( V_33 ) = V_310 ;
F_31 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_43 ) ;
return 0 ;
V_367:
F_23 ( V_33 ) ;
V_120:
F_23 ( V_310 . V_195 ) ;
V_115:
F_233 ( & V_310 . V_353 . V_364 , V_243 . type ) ;
V_114:
return V_44 ;
}
static int F_244 ( const struct V_13 * V_14 ,
struct V_55 * V_56 ,
const struct V_307 * V_308 ,
struct V_309 * V_310 )
{
struct V_29 * V_33 ;
int V_44 ;
V_33 = F_18 ( V_14 , V_375 ,
sizeof( struct V_350 ) , V_306 ) ;
if ( ! V_33 )
return - V_41 ;
if ( ! V_56 -> V_39 -> V_377 ( V_14 -> V_1 , V_56 , V_310 -> V_195 ) ) {
V_44 = - V_52 ;
goto V_114;
}
V_56 -> V_372 ++ ;
F_229 ( V_33 ) = V_56 ;
V_350 ( V_33 ) = * V_310 ;
F_31 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_43 ) ;
return 0 ;
V_114:
F_23 ( V_33 ) ;
return V_44 ;
}
static int F_245 ( struct V_1 * V_1 , struct V_99 * V_100 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
T_3 V_66 = F_93 ( V_1 ) ;
const struct V_23 * V_163 ;
struct V_55 * V_56 ;
struct V_13 V_14 ;
int V_235 , V_44 = 0 ;
V_44 = F_208 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_66 ) ;
if ( V_44 < 0 )
return V_44 ;
V_56 = F_180 ( V_14 . V_20 , V_24 [ V_347 ] ,
V_66 ) ;
if ( F_83 ( V_56 ) )
return F_84 ( V_56 ) ;
if ( ! F_99 ( & V_56 -> V_126 ) && V_56 -> V_36 & V_299 )
return - V_130 ;
if ( V_24 [ V_349 ] == NULL ) {
struct V_344 args = {
. V_308 = {
. V_66 = V_66 ,
. V_320 = F_244 ,
} ,
} ;
V_56 -> V_39 -> V_321 ( & V_14 , V_56 , & args . V_308 ) ;
return args . V_308 . V_44 ;
}
F_172 (attr, nla[NFTA_SET_ELEM_LIST_ELEMENTS], rem) {
V_44 = F_243 ( & V_14 , V_56 , V_163 ) ;
if ( V_44 < 0 )
break;
V_56 -> V_372 ++ ;
}
return V_44 ;
}
void F_246 ( struct V_378 * V_379 )
{
struct V_380 * V_381 ;
unsigned int V_71 ;
V_381 = F_222 ( V_379 , struct V_380 , V_382 . V_379 ) ;
for ( V_71 = 0 ; V_71 < V_381 -> V_382 . V_383 ; V_71 ++ )
F_232 ( V_381 -> V_382 . V_56 , V_381 -> V_384 [ V_71 ] , true ) ;
F_23 ( V_381 ) ;
}
struct V_380 * F_247 ( const struct V_55 * V_56 ,
T_2 V_32 )
{
struct V_380 * V_381 ;
V_381 = F_19 ( sizeof( * V_381 ) , V_32 ) ;
if ( V_381 == NULL )
return V_381 ;
V_381 -> V_382 . V_56 = V_56 ;
return V_381 ;
}
int F_248 ( struct V_385 * V_386 )
{
if ( V_386 -> type == V_303 )
return - V_68 ;
F_3 ( V_5 ) ;
F_146 ( & V_386 -> V_6 , & V_387 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_249 ( struct V_385 * V_386 )
{
F_3 ( V_5 ) ;
F_8 ( & V_386 -> V_6 ) ;
F_5 ( V_5 ) ;
}
struct V_61 * F_240 ( const struct V_19 * V_20 ,
const struct V_23 * V_24 ,
T_1 V_277 , T_3 V_66 )
{
struct V_61 * V_62 ;
F_10 (obj, &table->objects, list) {
if ( ! F_49 ( V_24 , V_62 -> V_67 ) &&
V_277 == V_62 -> type -> type &&
F_50 ( V_62 , V_66 ) )
return V_62 ;
}
return F_14 ( - V_52 ) ;
}
static struct V_61 * F_250 ( const struct V_385 * type ,
const struct V_23 * V_163 )
{
struct V_23 * V_164 [ type -> V_210 + 1 ] ;
struct V_61 * V_62 ;
int V_44 ;
if ( V_163 ) {
V_44 = F_122 ( V_164 , type -> V_210 , V_163 , type -> V_160 ) ;
if ( V_44 < 0 )
goto V_114;
} else {
memset ( V_164 , 0 , sizeof( V_164 [ 0 ] ) * ( type -> V_210 + 1 ) ) ;
}
V_44 = - V_41 ;
V_62 = F_19 ( sizeof( struct V_61 ) + type -> V_31 , V_34 ) ;
if ( V_62 == NULL )
goto V_114;
V_44 = type -> V_212 ( ( const struct V_23 * const * ) V_164 , V_62 ) ;
if ( V_44 < 0 )
goto V_115;
V_62 -> type = type ;
return V_62 ;
V_115:
F_23 ( V_62 ) ;
V_114:
return F_14 ( V_44 ) ;
}
static int F_251 ( struct V_15 * V_16 , unsigned int V_163 ,
struct V_61 * V_62 , bool V_388 )
{
struct V_23 * V_136 ;
V_136 = F_113 ( V_16 , V_163 ) ;
if ( ! V_136 )
goto V_77;
if ( V_62 -> type -> V_106 ( V_16 , V_62 , V_388 ) < 0 )
goto V_77;
F_116 ( V_16 , V_136 ) ;
return 0 ;
V_77:
return - 1 ;
}
static const struct V_385 * F_252 ( T_1 V_277 )
{
const struct V_385 * type ;
F_10 (type, &nf_tables_objects, list) {
if ( V_277 == type -> type )
return type ;
}
return NULL ;
}
static const struct V_385 * F_253 ( T_1 V_277 )
{
const struct V_385 * type ;
type = F_252 ( V_277 ) ;
if ( type != NULL && F_94 ( type -> V_113 ) )
return type ;
#ifdef F_12
if ( type == NULL ) {
F_5 ( V_5 ) ;
F_13 ( L_6 , V_277 ) ;
F_3 ( V_5 ) ;
if ( F_252 ( V_277 ) )
return F_14 ( - V_11 ) ;
}
#endif
return F_14 ( - V_52 ) ;
}
static int F_254 ( struct V_1 * V_1 , struct V_99 * V_100 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_75 * V_76 = F_59 ( V_18 ) ;
const struct V_385 * type ;
T_3 V_66 = F_93 ( V_1 ) ;
int V_9 = V_76 -> V_78 ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_61 * V_62 ;
struct V_13 V_14 ;
T_1 V_277 ;
int V_44 ;
if ( ! V_24 [ V_389 ] ||
! V_24 [ V_390 ] ||
! V_24 [ V_391 ] )
return - V_68 ;
V_3 = F_11 ( V_1 , V_9 , true ) ;
if ( F_83 ( V_3 ) )
return F_84 ( V_3 ) ;
V_20 = F_51 ( V_3 , V_24 [ V_392 ] , V_66 ) ;
if ( F_83 ( V_20 ) )
return F_84 ( V_20 ) ;
V_277 = F_43 ( F_44 ( V_24 [ V_389 ] ) ) ;
V_62 = F_240 ( V_20 , V_24 [ V_390 ] , V_277 , V_66 ) ;
if ( F_83 ( V_62 ) ) {
V_44 = F_84 ( V_62 ) ;
if ( V_44 != - V_52 )
return V_44 ;
V_62 = NULL ;
}
if ( V_62 != NULL ) {
if ( V_18 -> V_102 & V_109 )
return - V_110 ;
return 0 ;
}
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
type = F_253 ( V_277 ) ;
if ( F_83 ( type ) )
return F_84 ( type ) ;
V_62 = F_250 ( type , V_24 [ V_391 ] ) ;
if ( F_83 ( V_62 ) ) {
V_44 = F_84 ( V_62 ) ;
goto V_114;
}
V_62 -> V_20 = V_20 ;
F_95 ( V_62 -> V_67 , V_24 [ V_390 ] , V_393 ) ;
V_44 = F_46 ( & V_14 , V_64 , V_62 ) ;
if ( V_44 < 0 )
goto V_115;
F_4 ( & V_62 -> V_6 , & V_20 -> V_119 ) ;
V_20 -> V_49 ++ ;
return 0 ;
V_115:
if ( V_62 -> type -> V_213 )
V_62 -> type -> V_213 ( V_62 ) ;
F_23 ( V_62 ) ;
V_114:
F_96 ( type -> V_113 ) ;
return V_44 ;
}
static int F_255 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_25 , T_1 V_27 , int V_74 , T_1 V_36 ,
int V_9 , const struct V_19 * V_20 ,
struct V_61 * V_62 , bool V_388 )
{
struct V_75 * V_76 ;
struct V_17 * V_18 ;
V_74 |= V_5 << 8 ;
V_18 = F_58 ( V_16 , V_25 , V_27 , V_74 , sizeof( struct V_75 ) , V_36 ) ;
if ( V_18 == NULL )
goto V_77;
V_76 = F_59 ( V_18 ) ;
V_76 -> V_78 = V_9 ;
V_76 -> V_79 = V_80 ;
V_76 -> V_81 = F_60 ( V_1 -> V_7 . V_82 & 0xffff ) ;
if ( F_61 ( V_16 , V_392 , V_20 -> V_67 ) ||
F_61 ( V_16 , V_390 , V_62 -> V_67 ) ||
F_62 ( V_16 , V_389 , F_63 ( V_62 -> type -> type ) ) ||
F_62 ( V_16 , V_394 , F_63 ( V_62 -> V_49 ) ) ||
F_251 ( V_16 , V_391 , V_62 , V_388 ) )
goto V_77;
F_64 ( V_16 , V_18 ) ;
return 0 ;
V_77:
F_65 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_256 ( struct V_15 * V_16 , struct V_89 * V_90 )
{
const struct V_75 * V_76 = F_59 ( V_90 -> V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
unsigned int V_91 = 0 , V_92 = V_90 -> args [ 0 ] ;
struct V_395 * V_396 = V_90 -> V_203 ;
struct V_1 * V_1 = F_73 ( V_16 -> V_93 ) ;
int V_9 = V_76 -> V_78 ;
struct V_61 * V_62 ;
bool V_388 = false ;
if ( F_257 ( V_90 -> V_18 -> V_397 ) == V_398 )
V_388 = true ;
F_74 () ;
V_90 -> V_27 = V_1 -> V_7 . V_82 ;
F_75 (afi, &net->nft.af_info, list) {
if ( V_9 != V_94 && V_9 != V_3 -> V_9 )
continue;
F_75 (table, &afi->tables, list) {
F_75 (obj, &table->objects, list) {
if ( ! F_76 ( V_1 , V_62 ) )
goto V_95;
if ( V_91 < V_92 )
goto V_95;
if ( V_91 > V_92 )
memset ( & V_90 -> args [ 1 ] , 0 ,
sizeof( V_90 -> args ) - sizeof( V_90 -> args [ 0 ] ) ) ;
if ( V_396 && V_396 -> V_20 [ 0 ] &&
strcmp ( V_396 -> V_20 , V_20 -> V_67 ) )
goto V_95;
if ( V_396 &&
V_396 -> type != V_303 &&
V_62 -> type -> type != V_396 -> type )
goto V_95;
if ( F_255 ( V_16 , V_1 , F_16 ( V_90 -> V_16 ) . V_25 ,
V_90 -> V_18 -> V_28 ,
V_64 ,
V_96 | V_229 ,
V_3 -> V_9 , V_20 , V_62 , V_388 ) < 0 )
goto V_97;
F_77 ( V_90 , F_78 ( V_16 ) ) ;
V_95:
V_91 ++ ;
}
}
}
V_97:
F_79 () ;
V_90 -> args [ 0 ] = V_91 ;
return V_16 -> V_98 ;
}
static int F_258 ( struct V_89 * V_90 )
{
F_23 ( V_90 -> V_203 ) ;
return 0 ;
}
static struct V_395 *
F_259 ( const struct V_23 * const V_24 [] )
{
struct V_395 * V_396 ;
V_396 = F_19 ( sizeof( * V_396 ) , V_34 ) ;
if ( ! V_396 )
return F_14 ( - V_41 ) ;
if ( V_24 [ V_392 ] )
F_95 ( V_396 -> V_20 , V_24 [ V_392 ] ,
V_116 ) ;
if ( V_24 [ V_389 ] )
V_396 -> type = F_43 ( F_44 ( V_24 [ V_389 ] ) ) ;
return V_396 ;
}
static int F_260 ( struct V_1 * V_1 , struct V_99 * V_100 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_75 * V_76 = F_59 ( V_18 ) ;
T_3 V_66 = F_81 ( V_1 ) ;
int V_9 = V_76 -> V_78 ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
struct V_61 * V_62 ;
struct V_15 * V_101 ;
bool V_388 = false ;
T_1 V_277 ;
int V_44 ;
if ( V_18 -> V_102 & V_103 ) {
struct V_104 V_105 = {
. V_106 = F_256 ,
. V_97 = F_258 ,
} ;
if ( V_24 [ V_392 ] ||
V_24 [ V_389 ] ) {
struct V_395 * V_396 ;
V_396 = F_259 ( V_24 ) ;
if ( F_83 ( V_396 ) )
return - V_41 ;
V_105 . V_203 = V_396 ;
}
return F_82 ( V_100 , V_16 , V_18 , & V_105 ) ;
}
if ( ! V_24 [ V_390 ] ||
! V_24 [ V_389 ] )
return - V_68 ;
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_83 ( V_3 ) )
return F_84 ( V_3 ) ;
V_20 = F_51 ( V_3 , V_24 [ V_392 ] , V_66 ) ;
if ( F_83 ( V_20 ) )
return F_84 ( V_20 ) ;
V_277 = F_43 ( F_44 ( V_24 [ V_389 ] ) ) ;
V_62 = F_240 ( V_20 , V_24 [ V_390 ] , V_277 , V_66 ) ;
if ( F_83 ( V_62 ) )
return F_84 ( V_62 ) ;
V_101 = F_85 ( V_88 , V_34 ) ;
if ( ! V_101 )
return - V_41 ;
if ( F_257 ( V_18 -> V_397 ) == V_398 )
V_388 = true ;
V_44 = F_255 ( V_101 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 , V_64 , 0 ,
V_9 , V_20 , V_62 , V_388 ) ;
if ( V_44 < 0 )
goto V_44;
return F_86 ( V_100 , V_101 , F_16 ( V_16 ) . V_25 ) ;
V_44:
F_69 ( V_101 ) ;
return V_44 ;
return 0 ;
}
static void F_261 ( struct V_61 * V_62 )
{
if ( V_62 -> type -> V_213 )
V_62 -> type -> V_213 ( V_62 ) ;
F_96 ( V_62 -> type -> V_113 ) ;
F_23 ( V_62 ) ;
}
static int F_262 ( struct V_1 * V_1 , struct V_99 * V_100 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_75 * V_76 = F_59 ( V_18 ) ;
T_3 V_66 = F_93 ( V_1 ) ;
int V_9 = V_76 -> V_78 ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_61 * V_62 ;
struct V_13 V_14 ;
T_1 V_277 ;
if ( ! V_24 [ V_389 ] ||
! V_24 [ V_390 ] )
return - V_68 ;
V_3 = F_11 ( V_1 , V_9 , true ) ;
if ( F_83 ( V_3 ) )
return F_84 ( V_3 ) ;
V_20 = F_51 ( V_3 , V_24 [ V_392 ] , V_66 ) ;
if ( F_83 ( V_20 ) )
return F_84 ( V_20 ) ;
V_277 = F_43 ( F_44 ( V_24 [ V_389 ] ) ) ;
V_62 = F_240 ( V_20 , V_24 [ V_390 ] , V_277 , V_66 ) ;
if ( F_83 ( V_62 ) )
return F_84 ( V_62 ) ;
if ( V_62 -> V_49 > 0 )
return - V_130 ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return F_47 ( & V_14 , V_62 ) ;
}
int F_263 ( struct V_1 * V_1 , struct V_19 * V_20 ,
struct V_61 * V_62 , T_1 V_25 , T_1 V_27 , int V_74 ,
int V_9 , int V_26 , T_2 V_32 )
{
struct V_15 * V_16 ;
int V_44 ;
if ( ! V_26 &&
! F_67 ( V_1 , V_86 ) )
return 0 ;
V_44 = - V_87 ;
V_16 = F_68 ( V_88 , V_32 ) ;
if ( V_16 == NULL )
goto V_44;
V_44 = F_255 ( V_16 , V_1 , V_25 , V_27 , V_74 , 0 , V_9 ,
V_20 , V_62 , false ) ;
if ( V_44 < 0 ) {
F_69 ( V_16 ) ;
goto V_44;
}
V_44 = F_70 ( V_16 , V_1 , V_25 , V_86 , V_26 , V_32 ) ;
V_44:
if ( V_44 < 0 ) {
F_71 ( V_1 , V_25 , V_86 , V_44 ) ;
}
return V_44 ;
}
static int F_264 ( const struct V_13 * V_14 ,
struct V_61 * V_62 , int V_74 )
{
return F_263 ( V_14 -> V_1 , V_14 -> V_20 , V_62 , V_14 -> V_25 ,
V_14 -> V_27 , V_74 , V_14 -> V_3 -> V_9 , V_14 -> V_26 ,
V_34 ) ;
}
static int F_265 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_25 , T_1 V_27 )
{
struct V_17 * V_18 ;
struct V_75 * V_76 ;
int V_74 = ( V_5 << 8 ) | V_399 ;
V_18 = F_58 ( V_16 , V_25 , V_27 , V_74 , sizeof( struct V_75 ) , 0 ) ;
if ( V_18 == NULL )
goto V_77;
V_76 = F_59 ( V_18 ) ;
V_76 -> V_78 = V_128 ;
V_76 -> V_79 = V_80 ;
V_76 -> V_81 = F_60 ( V_1 -> V_7 . V_82 & 0xffff ) ;
if ( F_62 ( V_16 , V_400 , F_63 ( V_1 -> V_7 . V_82 ) ) )
goto V_77;
F_64 ( V_16 , V_18 ) ;
return 0 ;
V_77:
F_65 ( V_16 , V_18 ) ;
return - V_343 ;
}
static int F_266 ( struct V_1 * V_1 , struct V_15 * V_16 , int V_74 )
{
struct V_17 * V_18 = F_78 ( V_16 ) ;
struct V_15 * V_101 ;
int V_44 ;
if ( F_17 ( V_18 ) &&
! F_67 ( V_1 , V_86 ) )
return 0 ;
V_44 = - V_87 ;
V_101 = F_68 ( V_88 , V_34 ) ;
if ( V_101 == NULL )
goto V_44;
V_44 = F_265 ( V_101 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 ) ;
if ( V_44 < 0 ) {
F_69 ( V_101 ) ;
goto V_44;
}
V_44 = F_70 ( V_101 , V_1 , F_16 ( V_16 ) . V_25 ,
V_86 , F_17 ( V_18 ) , V_34 ) ;
V_44:
if ( V_44 < 0 ) {
F_71 ( V_1 , F_16 ( V_16 ) . V_25 , V_86 ,
V_44 ) ;
}
return V_44 ;
}
static int F_267 ( struct V_1 * V_1 , struct V_99 * V_100 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
struct V_15 * V_101 ;
int V_44 ;
V_101 = F_85 ( V_88 , V_34 ) ;
if ( V_101 == NULL )
return - V_41 ;
V_44 = F_265 ( V_101 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 ) ;
if ( V_44 < 0 )
goto V_44;
return F_86 ( V_100 , V_101 , F_16 ( V_16 ) . V_25 ) ;
V_44:
F_69 ( V_101 ) ;
return V_44 ;
}
static void F_268 ( struct V_29 * V_33 )
{
struct F_26 * V_150 ;
if ( F_143 ( V_33 ) [ 0 ] )
strcpy ( V_33 -> V_14 . V_22 -> V_67 , F_143 ( V_33 ) ) ;
if ( ! ( V_33 -> V_14 . V_22 -> V_36 & V_38 ) )
return;
V_150 = F_26 ( V_33 -> V_14 . V_22 ) ;
F_129 ( V_150 , F_140 ( V_33 ) ) ;
switch ( F_142 ( V_33 ) ) {
case V_187 :
case V_185 :
V_150 -> V_160 = F_142 ( V_33 ) ;
break;
}
}
static void F_269 ( struct V_29 * V_33 )
{
switch ( V_33 -> V_30 ) {
case V_45 :
F_102 ( & V_33 -> V_14 ) ;
break;
case V_48 :
F_134 ( V_33 -> V_14 . V_22 ) ;
break;
case V_54 :
F_167 ( & V_33 -> V_14 , V_53 ( V_33 ) ) ;
break;
case V_60 :
F_198 ( V_57 ( V_33 ) ) ;
break;
case V_375 :
F_232 ( F_229 ( V_33 ) ,
V_350 ( V_33 ) . V_195 , true ) ;
break;
case V_65 :
F_261 ( V_63 ( V_33 ) ) ;
break;
}
F_23 ( V_33 ) ;
}
static int F_270 ( struct V_1 * V_1 , struct V_15 * V_16 )
{
struct V_29 * V_33 , * V_214 ;
struct V_350 * V_401 ;
while ( ++ V_1 -> V_7 . V_82 == 0 ) ;
V_1 -> V_7 . V_402 = F_271 ( V_1 ) ;
F_132 () ;
F_98 (trans, next, &net->nft.commit_list, list) {
switch ( V_33 -> V_30 ) {
case V_42 :
if ( F_91 ( V_33 ) ) {
if ( ! F_90 ( V_33 ) ) {
F_88 ( V_1 ,
V_33 -> V_14 . V_3 ,
V_33 -> V_14 . V_20 ) ;
V_33 -> V_14 . V_20 -> V_36 |= V_37 ;
}
} else {
F_272 ( V_1 , V_33 -> V_14 . V_20 ) ;
}
F_66 ( & V_33 -> V_14 , V_42 ) ;
F_21 ( V_33 ) ;
break;
case V_45 :
F_8 ( & V_33 -> V_14 . V_20 -> V_6 ) ;
F_66 ( & V_33 -> V_14 , V_45 ) ;
break;
case V_47 :
if ( F_141 ( V_33 ) )
F_268 ( V_33 ) ;
else
F_272 ( V_1 , V_33 -> V_14 . V_22 ) ;
F_118 ( & V_33 -> V_14 , V_47 ) ;
F_21 ( V_33 ) ;
break;
case V_48 :
F_8 ( & V_33 -> V_14 . V_22 -> V_6 ) ;
F_118 ( & V_33 -> V_14 , V_48 ) ;
F_27 ( V_33 -> V_14 . V_1 ,
V_33 -> V_14 . V_20 ,
V_33 -> V_14 . V_22 ,
V_33 -> V_14 . V_3 -> V_107 ) ;
break;
case V_228 :
F_272 ( V_33 -> V_14 . V_1 , V_53 ( V_33 ) ) ;
F_163 ( & V_33 -> V_14 ,
V_53 ( V_33 ) ,
V_228 ) ;
F_21 ( V_33 ) ;
break;
case V_54 :
F_8 ( & V_53 ( V_33 ) -> V_6 ) ;
F_163 ( & V_33 -> V_14 ,
V_53 ( V_33 ) ,
V_54 ) ;
break;
case V_58 :
F_272 ( V_1 , V_57 ( V_33 ) ) ;
if ( V_57 ( V_33 ) -> V_36 & V_125 &&
! F_99 ( & V_57 ( V_33 ) -> V_126 ) )
V_33 -> V_14 . V_20 -> V_49 -- ;
F_190 ( & V_33 -> V_14 , V_57 ( V_33 ) ,
V_58 , V_34 ) ;
F_21 ( V_33 ) ;
break;
case V_60 :
F_8 ( & V_57 ( V_33 ) -> V_6 ) ;
F_190 ( & V_33 -> V_14 , V_57 ( V_33 ) ,
V_60 , V_34 ) ;
break;
case V_348 :
V_401 = (struct V_350 * ) V_33 -> V_203 ;
V_401 -> V_56 -> V_39 -> V_403 ( V_1 , V_401 -> V_56 , & V_401 -> V_310 ) ;
F_227 ( & V_33 -> V_14 , V_401 -> V_56 ,
& V_401 -> V_310 ,
V_348 , 0 ) ;
F_21 ( V_33 ) ;
break;
case V_375 :
V_401 = (struct V_350 * ) V_33 -> V_203 ;
F_227 ( & V_33 -> V_14 , V_401 -> V_56 ,
& V_401 -> V_310 ,
V_375 , 0 ) ;
V_401 -> V_56 -> V_39 -> remove ( V_401 -> V_56 , & V_401 -> V_310 ) ;
F_273 ( & V_401 -> V_56 -> V_371 ) ;
V_401 -> V_56 -> V_372 -- ;
break;
case V_64 :
F_272 ( V_1 , V_63 ( V_33 ) ) ;
F_264 ( & V_33 -> V_14 , V_63 ( V_33 ) ,
V_64 ) ;
F_21 ( V_33 ) ;
break;
case V_65 :
F_8 ( & V_63 ( V_33 ) -> V_6 ) ;
F_264 ( & V_33 -> V_14 , V_63 ( V_33 ) ,
V_65 ) ;
break;
}
}
F_132 () ;
F_98 (trans, next, &net->nft.commit_list, list) {
F_22 ( & V_33 -> V_6 ) ;
F_269 ( V_33 ) ;
}
F_266 ( V_1 , V_16 , V_399 ) ;
return 0 ;
}
static void F_274 ( struct V_29 * V_33 )
{
switch ( V_33 -> V_30 ) {
case V_42 :
F_102 ( & V_33 -> V_14 ) ;
break;
case V_47 :
F_134 ( V_33 -> V_14 . V_22 ) ;
break;
case V_228 :
F_167 ( & V_33 -> V_14 , V_53 ( V_33 ) ) ;
break;
case V_58 :
F_198 ( V_57 ( V_33 ) ) ;
break;
case V_348 :
F_232 ( F_229 ( V_33 ) ,
V_350 ( V_33 ) . V_195 , true ) ;
break;
case V_64 :
F_261 ( V_63 ( V_33 ) ) ;
break;
}
F_23 ( V_33 ) ;
}
static int F_275 ( struct V_1 * V_1 , struct V_15 * V_16 )
{
struct V_29 * V_33 , * V_214 ;
struct V_350 * V_401 ;
F_276 (trans, next, &net->nft.commit_list,
list) {
switch ( V_33 -> V_30 ) {
case V_42 :
if ( F_91 ( V_33 ) ) {
if ( F_90 ( V_33 ) ) {
F_88 ( V_1 ,
V_33 -> V_14 . V_3 ,
V_33 -> V_14 . V_20 ) ;
V_33 -> V_14 . V_20 -> V_36 |= V_37 ;
}
F_21 ( V_33 ) ;
} else {
F_8 ( & V_33 -> V_14 . V_20 -> V_6 ) ;
}
break;
case V_45 :
F_272 ( V_33 -> V_14 . V_1 , V_33 -> V_14 . V_20 ) ;
F_21 ( V_33 ) ;
break;
case V_47 :
if ( F_141 ( V_33 ) ) {
F_133 ( F_140 ( V_33 ) ) ;
F_21 ( V_33 ) ;
} else {
V_33 -> V_14 . V_20 -> V_49 -- ;
F_8 ( & V_33 -> V_14 . V_22 -> V_6 ) ;
F_27 ( V_33 -> V_14 . V_1 ,
V_33 -> V_14 . V_20 ,
V_33 -> V_14 . V_22 ,
V_33 -> V_14 . V_3 -> V_107 ) ;
}
break;
case V_48 :
V_33 -> V_14 . V_20 -> V_49 ++ ;
F_272 ( V_33 -> V_14 . V_1 , V_33 -> V_14 . V_22 ) ;
F_21 ( V_33 ) ;
break;
case V_228 :
V_33 -> V_14 . V_22 -> V_49 -- ;
F_8 ( & V_53 ( V_33 ) -> V_6 ) ;
break;
case V_54 :
V_33 -> V_14 . V_22 -> V_49 ++ ;
F_272 ( V_33 -> V_14 . V_1 , V_53 ( V_33 ) ) ;
F_21 ( V_33 ) ;
break;
case V_58 :
V_33 -> V_14 . V_20 -> V_49 -- ;
F_8 ( & V_57 ( V_33 ) -> V_6 ) ;
break;
case V_60 :
V_33 -> V_14 . V_20 -> V_49 ++ ;
F_272 ( V_33 -> V_14 . V_1 , V_57 ( V_33 ) ) ;
F_21 ( V_33 ) ;
break;
case V_348 :
V_401 = (struct V_350 * ) V_33 -> V_203 ;
V_401 -> V_56 -> V_39 -> remove ( V_401 -> V_56 , & V_401 -> V_310 ) ;
F_273 ( & V_401 -> V_56 -> V_371 ) ;
break;
case V_375 :
V_401 = (struct V_350 * ) V_33 -> V_203 ;
V_401 -> V_56 -> V_39 -> V_403 ( V_1 , V_401 -> V_56 , & V_401 -> V_310 ) ;
V_401 -> V_56 -> V_372 -- ;
F_21 ( V_33 ) ;
break;
case V_64 :
V_33 -> V_14 . V_20 -> V_49 -- ;
F_8 ( & V_63 ( V_33 ) -> V_6 ) ;
break;
case V_65 :
V_33 -> V_14 . V_20 -> V_49 ++ ;
F_272 ( V_33 -> V_14 . V_1 , V_63 ( V_33 ) ) ;
F_21 ( V_33 ) ;
break;
}
}
F_132 () ;
F_276 (trans, next,
&net->nft.commit_list, list) {
F_22 ( & V_33 -> V_6 ) ;
F_274 ( V_33 ) ;
}
return 0 ;
}
int F_277 ( const struct V_21 * V_22 ,
enum V_404 type )
{
const struct F_26 * V_150 ;
if ( V_22 -> V_36 & V_38 ) {
V_150 = F_26 ( V_22 ) ;
if ( V_150 -> type -> type != type )
return - V_112 ;
}
return 0 ;
}
int F_278 ( const struct V_21 * V_22 ,
unsigned int V_405 )
{
struct F_26 * V_150 ;
if ( V_22 -> V_36 & V_38 ) {
V_150 = F_26 ( V_22 ) ;
if ( ( 1 << V_150 -> V_39 [ 0 ] . V_154 ) & V_405 )
return 0 ;
return - V_112 ;
}
return 0 ;
}
static int F_279 ( const struct V_13 * V_14 ,
struct V_55 * V_56 ,
const struct V_307 * V_308 ,
struct V_309 * V_310 )
{
const struct V_311 * V_312 = F_202 ( V_56 , V_310 -> V_195 ) ;
const struct V_362 * V_203 ;
if ( F_213 ( V_312 , V_331 ) &&
* F_216 ( V_312 ) & V_356 )
return 0 ;
V_203 = F_205 ( V_312 ) ;
switch ( V_203 -> V_406 . V_407 ) {
case V_408 :
case V_409 :
return F_280 ( V_14 , V_203 -> V_406 . V_22 ) ;
default:
return 0 ;
}
}
static int F_280 ( const struct V_13 * V_14 ,
const struct V_21 * V_22 )
{
const struct V_50 * V_51 ;
const struct V_200 * V_201 , * V_410 ;
struct V_55 * V_56 ;
struct V_315 * V_316 ;
struct V_307 V_308 ;
if ( V_14 -> V_22 == V_22 )
return - V_411 ;
F_10 (rule, &chain->rules, list) {
F_161 (expr, last, rule) {
const struct V_362 * V_203 = NULL ;
int V_44 ;
if ( ! V_201 -> V_39 -> V_412 )
continue;
V_44 = V_201 -> V_39 -> V_412 ( V_14 , V_201 , & V_203 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_203 == NULL )
continue;
switch ( V_203 -> V_406 . V_407 ) {
case V_408 :
case V_409 :
V_44 = F_280 ( V_14 ,
V_203 -> V_406 . V_22 ) ;
if ( V_44 < 0 )
return V_44 ;
default:
break;
}
}
}
F_10 (set, &ctx->table->sets, list) {
if ( ! F_37 ( V_14 -> V_1 , V_56 ) )
continue;
if ( ! ( V_56 -> V_36 & V_252 ) ||
V_56 -> V_273 != V_301 )
continue;
F_10 (binding, &set->bindings, list) {
if ( ! ( V_316 -> V_36 & V_252 ) ||
V_316 -> V_22 != V_22 )
continue;
V_308 . V_66 = F_93 ( V_14 -> V_1 ) ;
V_308 . V_318 = 0 ;
V_308 . V_319 = 0 ;
V_308 . V_44 = 0 ;
V_308 . V_320 = F_279 ;
V_56 -> V_39 -> V_321 ( V_14 , V_56 , & V_308 ) ;
if ( V_308 . V_44 < 0 )
return V_308 . V_44 ;
}
}
return 0 ;
}
int F_281 ( const struct V_23 * V_163 , int V_413 , T_1 * V_414 )
{
T_1 V_364 ;
V_364 = F_43 ( F_44 ( V_163 ) ) ;
if ( V_364 > V_413 )
return - V_415 ;
* V_414 = V_364 ;
return 0 ;
}
unsigned int F_282 ( const struct V_23 * V_163 )
{
unsigned int V_416 ;
V_416 = F_43 ( F_44 ( V_163 ) ) ;
switch ( V_416 ) {
case V_417 ... V_418 :
return V_416 * V_419 / V_420 ;
default:
return V_416 + V_419 / V_420 - V_421 ;
}
}
int F_283 ( struct V_15 * V_16 , unsigned int V_163 , unsigned int V_416 )
{
if ( V_416 % ( V_419 / V_420 ) == 0 )
V_416 = V_416 / ( V_419 / V_420 ) ;
else
V_416 = V_416 - V_419 / V_420 + V_421 ;
return F_62 ( V_16 , V_163 , F_63 ( V_416 ) ) ;
}
int F_284 ( enum V_313 V_416 , unsigned int V_98 )
{
if ( V_416 < V_422 * V_419 / V_420 )
return - V_68 ;
if ( V_98 == 0 )
return - V_68 ;
if ( V_416 * V_420 + V_98 > F_285 ( struct V_423 , V_203 ) )
return - V_415 ;
return 0 ;
}
int F_204 ( const struct V_13 * V_14 ,
enum V_313 V_416 ,
const struct V_362 * V_203 ,
enum V_424 type , unsigned int V_98 )
{
int V_44 ;
switch ( V_416 ) {
case V_417 :
if ( type != V_301 )
return - V_68 ;
if ( V_203 != NULL &&
( V_203 -> V_406 . V_407 == V_409 ||
V_203 -> V_406 . V_407 == V_408 ) ) {
V_44 = F_280 ( V_14 , V_203 -> V_406 . V_22 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_14 -> V_22 -> V_425 + 1 >
V_203 -> V_406 . V_22 -> V_425 ) {
if ( V_14 -> V_22 -> V_425 + 1 == V_426 )
return - V_427 ;
V_203 -> V_406 . V_22 -> V_425 = V_14 -> V_22 -> V_425 + 1 ;
}
}
return 0 ;
default:
if ( V_416 < V_422 * V_419 / V_420 )
return - V_68 ;
if ( V_98 == 0 )
return - V_68 ;
if ( V_416 * V_420 + V_98 >
F_285 ( struct V_423 , V_203 ) )
return - V_415 ;
if ( V_203 != NULL && type != V_296 )
return - V_68 ;
return 0 ;
}
}
static int F_286 ( const struct V_13 * V_14 , struct V_362 * V_203 ,
struct V_358 * V_243 , const struct V_23 * V_24 )
{
T_3 V_66 = F_93 ( V_14 -> V_1 ) ;
struct V_23 * V_164 [ V_428 + 1 ] ;
struct V_21 * V_22 ;
int V_44 ;
V_44 = F_122 ( V_164 , V_428 , V_24 , V_429 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( ! V_164 [ V_430 ] )
return - V_68 ;
V_203 -> V_406 . V_407 = F_43 ( F_44 ( V_164 [ V_430 ] ) ) ;
switch ( V_203 -> V_406 . V_407 ) {
default:
switch ( V_203 -> V_406 . V_407 & V_431 ) {
case V_185 :
case V_187 :
case V_432 :
break;
default:
return - V_68 ;
}
case V_433 :
case V_434 :
case V_435 :
break;
case V_408 :
case V_409 :
if ( ! V_164 [ V_436 ] )
return - V_68 ;
V_22 = F_107 ( V_14 -> V_20 ,
V_164 [ V_436 ] , V_66 ) ;
if ( F_83 ( V_22 ) )
return F_84 ( V_22 ) ;
if ( V_22 -> V_36 & V_38 )
return - V_112 ;
V_22 -> V_49 ++ ;
V_203 -> V_406 . V_22 = V_22 ;
break;
}
V_243 -> V_98 = sizeof( V_203 -> V_406 ) ;
V_243 -> type = V_301 ;
return 0 ;
}
static void F_287 ( const struct V_362 * V_203 )
{
switch ( V_203 -> V_406 . V_407 ) {
case V_408 :
case V_409 :
V_203 -> V_406 . V_22 -> V_49 -- ;
break;
}
}
int F_288 ( struct V_15 * V_16 , int type , const struct V_302 * V_437 )
{
struct V_23 * V_136 ;
V_136 = F_113 ( V_16 , type ) ;
if ( ! V_136 )
goto V_77;
if ( F_62 ( V_16 , V_430 , F_63 ( V_437 -> V_407 ) ) )
goto V_77;
switch ( V_437 -> V_407 ) {
case V_408 :
case V_409 :
if ( F_61 ( V_16 , V_436 ,
V_437 -> V_22 -> V_67 ) )
goto V_77;
}
F_116 ( V_16 , V_136 ) ;
return 0 ;
V_77:
return - 1 ;
}
static int F_289 ( const struct V_13 * V_14 ,
struct V_362 * V_203 , unsigned int V_31 ,
struct V_358 * V_243 , const struct V_23 * V_24 )
{
unsigned int V_98 ;
V_98 = F_55 ( V_24 ) ;
if ( V_98 == 0 )
return - V_68 ;
if ( V_98 > V_31 )
return - V_191 ;
F_174 ( V_203 -> V_203 , V_24 , V_98 ) ;
V_243 -> type = V_296 ;
V_243 -> V_98 = V_98 ;
return 0 ;
}
static int F_290 ( struct V_15 * V_16 , const struct V_362 * V_203 ,
unsigned int V_98 )
{
return F_162 ( V_16 , V_438 , V_98 , V_203 -> V_203 ) ;
}
int F_238 ( const struct V_13 * V_14 ,
struct V_362 * V_203 , unsigned int V_31 ,
struct V_358 * V_243 , const struct V_23 * V_24 )
{
struct V_23 * V_164 [ V_439 + 1 ] ;
int V_44 ;
V_44 = F_122 ( V_164 , V_439 , V_24 , V_440 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_164 [ V_438 ] )
return F_289 ( V_14 , V_203 , V_31 , V_243 ,
V_164 [ V_438 ] ) ;
if ( V_164 [ V_441 ] && V_14 != NULL )
return F_286 ( V_14 , V_203 , V_243 , V_164 [ V_441 ] ) ;
return - V_68 ;
}
void F_233 ( const struct V_362 * V_203 , enum V_424 type )
{
if ( type < V_301 )
return;
switch ( type ) {
case V_301 :
return F_287 ( V_203 ) ;
default:
F_291 ( 1 ) ;
}
}
int F_211 ( struct V_15 * V_16 , int V_163 , const struct V_362 * V_203 ,
enum V_424 type , unsigned int V_98 )
{
struct V_23 * V_136 ;
int V_44 ;
V_136 = F_113 ( V_16 , V_163 ) ;
if ( V_136 == NULL )
return - 1 ;
switch ( type ) {
case V_296 :
V_44 = F_290 ( V_16 , V_203 , V_98 ) ;
break;
case V_301 :
V_44 = F_288 ( V_16 , V_441 , & V_203 -> V_406 ) ;
break;
default:
V_44 = - V_68 ;
F_291 ( 1 ) ;
}
F_116 ( V_16 , V_136 ) ;
return V_44 ;
}
static int T_8 F_292 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_7 . V_8 ) ;
F_2 ( & V_1 -> V_7 . V_43 ) ;
V_1 -> V_7 . V_82 = 1 ;
return 0 ;
}
int F_293 ( struct V_13 * V_14 )
{
struct V_50 * V_51 , * V_442 ;
F_103 ( ! ( V_14 -> V_22 -> V_36 & V_38 ) ) ;
F_27 ( V_14 -> V_1 , V_14 -> V_22 -> V_20 , V_14 -> V_22 ,
V_14 -> V_3 -> V_107 ) ;
F_98 (rule, nr, &ctx->chain->rules, list) {
F_22 ( & V_51 -> V_6 ) ;
V_14 -> V_22 -> V_49 -- ;
F_167 ( V_14 , V_51 ) ;
}
F_22 ( & V_14 -> V_22 -> V_6 ) ;
V_14 -> V_20 -> V_49 -- ;
F_134 ( V_14 -> V_22 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_19 * V_20 , * V_127 ;
struct V_21 * V_22 , * V_121 ;
struct V_61 * V_62 , * V_122 ;
struct V_50 * V_51 , * V_442 ;
struct V_55 * V_56 , * V_123 ;
struct V_13 V_14 = {
. V_1 = V_1 ,
. V_3 = V_3 ,
} ;
F_98 (table, nt, &afi->tables, list) {
F_10 (chain, &table->chains, list)
F_27 ( V_1 , V_20 , V_22 ,
V_3 -> V_107 ) ;
V_14 . V_20 = V_20 ;
F_10 (chain, &table->chains, list) {
V_14 . V_22 = V_22 ;
F_98 (rule, nr, &chain->rules, list) {
F_22 ( & V_51 -> V_6 ) ;
V_22 -> V_49 -- ;
F_167 ( & V_14 , V_51 ) ;
}
}
F_98 (set, ns, &table->sets, list) {
F_22 ( & V_56 -> V_6 ) ;
V_20 -> V_49 -- ;
F_198 ( V_56 ) ;
}
F_98 (obj, ne, &table->objects, list) {
F_22 ( & V_62 -> V_6 ) ;
V_20 -> V_49 -- ;
F_261 ( V_62 ) ;
}
F_98 (chain, nc, &table->chains, list) {
F_22 ( & V_22 -> V_6 ) ;
V_20 -> V_49 -- ;
F_134 ( V_22 ) ;
}
F_22 ( & V_20 -> V_6 ) ;
F_102 ( & V_14 ) ;
}
}
static int T_9 F_294 ( void )
{
int V_44 ;
V_206 = F_194 ( sizeof( struct V_205 ) * V_237 ,
V_34 ) ;
if ( V_206 == NULL ) {
V_44 = - V_41 ;
goto V_114;
}
V_44 = F_295 () ;
if ( V_44 < 0 )
goto V_115;
V_44 = F_296 ( & V_443 ) ;
if ( V_44 < 0 )
goto V_120;
F_297 ( L_7 ) ;
return F_298 ( & V_444 ) ;
V_120:
F_299 () ;
V_115:
F_23 ( V_206 ) ;
V_114:
return V_44 ;
}
static void T_10 F_300 ( void )
{
F_301 ( & V_444 ) ;
F_302 ( & V_443 ) ;
F_303 () ;
F_299 () ;
F_23 ( V_206 ) ;
}
