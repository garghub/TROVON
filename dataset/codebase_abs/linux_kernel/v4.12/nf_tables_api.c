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
! F_25 ( V_22 ) )
return 0 ;
return F_26 ( V_1 , F_27 ( V_22 ) -> V_38 ,
V_35 ) ;
}
static void F_28 ( struct V_1 * V_1 ,
const struct V_19 * V_20 ,
struct V_21 * V_22 ,
unsigned int V_35 )
{
if ( V_20 -> V_36 & V_37 ||
! F_25 ( V_22 ) )
return;
F_29 ( V_1 , F_27 ( V_22 ) -> V_38 , V_35 ) ;
}
static int F_30 ( struct V_13 * V_14 , int V_30 )
{
struct V_29 * V_33 ;
V_33 = F_20 ( V_14 , V_30 , sizeof( struct V_39 ) ) ;
if ( V_33 == NULL )
return - V_40 ;
if ( V_30 == V_41 )
F_31 ( V_14 -> V_1 , V_14 -> V_20 ) ;
F_32 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_42 ) ;
return 0 ;
}
static int F_33 ( struct V_13 * V_14 )
{
int V_43 ;
V_43 = F_30 ( V_14 , V_44 ) ;
if ( V_43 < 0 )
return V_43 ;
F_34 ( V_14 -> V_1 , V_14 -> V_20 ) ;
return V_43 ;
}
static int F_35 ( struct V_13 * V_14 , int V_30 )
{
struct V_29 * V_33 ;
V_33 = F_20 ( V_14 , V_30 , sizeof( struct V_45 ) ) ;
if ( V_33 == NULL )
return - V_40 ;
if ( V_30 == V_46 )
F_31 ( V_14 -> V_1 , V_14 -> V_22 ) ;
F_32 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_42 ) ;
return 0 ;
}
static int F_36 ( struct V_13 * V_14 )
{
int V_43 ;
V_43 = F_35 ( V_14 , V_47 ) ;
if ( V_43 < 0 )
return V_43 ;
V_14 -> V_20 -> V_48 -- ;
F_34 ( V_14 -> V_1 , V_14 -> V_22 ) ;
return V_43 ;
}
static int
F_37 ( struct V_13 * V_14 , struct V_49 * V_50 )
{
if ( F_38 ( V_14 -> V_1 , V_50 ) ) {
F_34 ( V_14 -> V_1 , V_50 ) ;
V_14 -> V_22 -> V_48 -- ;
return 0 ;
}
return - V_51 ;
}
static struct V_29 * F_39 ( struct V_13 * V_14 , int V_30 ,
struct V_49 * V_50 )
{
struct V_29 * V_33 ;
V_33 = F_20 ( V_14 , V_30 , sizeof( struct V_52 ) ) ;
if ( V_33 == NULL )
return NULL ;
if ( V_30 == V_53 && V_14 -> V_24 [ V_54 ] != NULL ) {
F_40 ( V_33 ) =
F_41 ( F_42 ( V_14 -> V_24 [ V_54 ] ) ) ;
}
V_52 ( V_33 ) = V_50 ;
F_32 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_42 ) ;
return V_33 ;
}
static int F_43 ( struct V_13 * V_14 , struct V_49 * V_50 )
{
struct V_29 * V_33 ;
int V_43 ;
V_33 = F_39 ( V_14 , V_55 , V_50 ) ;
if ( V_33 == NULL )
return - V_40 ;
V_43 = F_37 ( V_14 , V_50 ) ;
if ( V_43 < 0 ) {
F_21 ( V_33 ) ;
return V_43 ;
}
return 0 ;
}
static int F_44 ( struct V_13 * V_14 )
{
struct V_49 * V_50 ;
int V_43 ;
F_10 (rule, &ctx->chain->rules, list) {
V_43 = F_43 ( V_14 , V_50 ) ;
if ( V_43 < 0 )
return V_43 ;
}
return 0 ;
}
static int F_45 ( struct V_13 * V_14 , int V_30 ,
struct V_56 * V_57 )
{
struct V_29 * V_33 ;
V_33 = F_20 ( V_14 , V_30 , sizeof( struct V_58 ) ) ;
if ( V_33 == NULL )
return - V_40 ;
if ( V_30 == V_59 && V_14 -> V_24 [ V_60 ] != NULL ) {
F_46 ( V_33 ) =
F_41 ( F_42 ( V_14 -> V_24 [ V_60 ] ) ) ;
F_31 ( V_14 -> V_1 , V_57 ) ;
}
V_58 ( V_33 ) = V_57 ;
F_32 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_42 ) ;
return 0 ;
}
static int F_47 ( struct V_13 * V_14 , struct V_56 * V_57 )
{
int V_43 ;
V_43 = F_45 ( V_14 , V_61 , V_57 ) ;
if ( V_43 < 0 )
return V_43 ;
F_34 ( V_14 -> V_1 , V_57 ) ;
V_14 -> V_20 -> V_48 -- ;
return V_43 ;
}
static int F_48 ( struct V_13 * V_14 , int V_30 ,
struct V_62 * V_63 )
{
struct V_29 * V_33 ;
V_33 = F_20 ( V_14 , V_30 , sizeof( struct V_64 ) ) ;
if ( V_33 == NULL )
return - V_40 ;
if ( V_30 == V_65 )
F_31 ( V_14 -> V_1 , V_63 ) ;
V_64 ( V_33 ) = V_63 ;
F_32 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_42 ) ;
return 0 ;
}
static int F_49 ( struct V_13 * V_14 , struct V_62 * V_63 )
{
int V_43 ;
V_43 = F_48 ( V_14 , V_66 , V_63 ) ;
if ( V_43 < 0 )
return V_43 ;
F_34 ( V_14 -> V_1 , V_63 ) ;
V_14 -> V_20 -> V_48 -- ;
return V_43 ;
}
static struct V_19 * F_50 ( const struct V_2 * V_3 ,
const struct V_23 * V_24 ,
T_3 V_67 )
{
struct V_19 * V_20 ;
F_10 (table, &afi->tables, list) {
if ( ! F_51 ( V_24 , V_20 -> V_68 ) &&
F_52 ( V_20 , V_67 ) )
return V_20 ;
}
return NULL ;
}
static struct V_19 * F_53 ( const struct V_2 * V_3 ,
const struct V_23 * V_24 ,
T_3 V_67 )
{
struct V_19 * V_20 ;
if ( V_24 == NULL )
return F_14 ( - V_69 ) ;
V_20 = F_50 ( V_3 , V_24 , V_67 ) ;
if ( V_20 != NULL )
return V_20 ;
return F_14 ( - V_51 ) ;
}
static inline T_4 F_54 ( struct V_19 * V_20 )
{
return ++ V_20 -> V_70 ;
}
static const struct V_71 *
F_55 ( int V_9 , const struct V_23 * V_24 )
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
return F_14 ( - V_51 ) ;
}
static int F_59 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_25 , T_1 V_27 , int V_75 , T_1 V_36 ,
int V_9 , const struct V_19 * V_20 )
{
struct V_17 * V_18 ;
struct V_76 * V_77 ;
V_75 = F_60 ( V_5 , V_75 ) ;
V_18 = F_61 ( V_16 , V_25 , V_27 , V_75 , sizeof( struct V_76 ) , V_36 ) ;
if ( V_18 == NULL )
goto V_78;
V_77 = F_62 ( V_18 ) ;
V_77 -> V_79 = V_9 ;
V_77 -> V_80 = V_81 ;
V_77 -> V_82 = F_63 ( V_1 -> V_7 . V_83 & 0xffff ) ;
if ( F_64 ( V_16 , V_84 , V_20 -> V_68 ) ||
F_65 ( V_16 , V_85 , F_66 ( V_20 -> V_36 ) ) ||
F_65 ( V_16 , V_86 , F_66 ( V_20 -> V_48 ) ) )
goto V_78;
F_67 ( V_16 , V_18 ) ;
return 0 ;
V_78:
F_68 ( V_16 , V_18 ) ;
return - 1 ;
}
static void F_69 ( const struct V_13 * V_14 , int V_75 )
{
struct V_15 * V_16 ;
int V_43 ;
if ( ! V_14 -> V_26 &&
! F_70 ( V_14 -> V_1 , V_87 ) )
return;
V_16 = F_71 ( V_88 , V_34 ) ;
if ( V_16 == NULL )
goto V_43;
V_43 = F_59 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_14 -> V_27 ,
V_75 , 0 , V_14 -> V_3 -> V_9 , V_14 -> V_20 ) ;
if ( V_43 < 0 ) {
F_72 ( V_16 ) ;
goto V_43;
}
F_73 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_87 ,
V_14 -> V_26 , V_34 ) ;
return;
V_43:
F_74 ( V_14 -> V_1 , V_14 -> V_25 , V_87 , - V_89 ) ;
}
static int F_75 ( struct V_15 * V_16 ,
struct V_90 * V_91 )
{
const struct V_76 * V_77 = F_62 ( V_91 -> V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
unsigned int V_92 = 0 , V_93 = V_91 -> args [ 0 ] ;
struct V_1 * V_1 = F_76 ( V_16 -> V_94 ) ;
int V_9 = V_77 -> V_79 ;
F_77 () ;
V_91 -> V_27 = V_1 -> V_7 . V_83 ;
F_78 (afi, &net->nft.af_info, list) {
if ( V_9 != V_95 && V_9 != V_3 -> V_9 )
continue;
F_78 (table, &afi->tables, list) {
if ( V_92 < V_93 )
goto V_96;
if ( V_92 > V_93 )
memset ( & V_91 -> args [ 1 ] , 0 ,
sizeof( V_91 -> args ) - sizeof( V_91 -> args [ 0 ] ) ) ;
if ( ! F_79 ( V_1 , V_20 ) )
continue;
if ( F_59 ( V_16 , V_1 ,
F_16 ( V_91 -> V_16 ) . V_25 ,
V_91 -> V_18 -> V_28 ,
V_41 ,
V_97 ,
V_3 -> V_9 , V_20 ) < 0 )
goto V_98;
F_80 ( V_91 , F_81 ( V_16 ) ) ;
V_96:
V_92 ++ ;
}
}
V_98:
F_82 () ;
V_91 -> args [ 0 ] = V_92 ;
return V_16 -> V_99 ;
}
static int F_83 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_62 ( V_18 ) ;
T_3 V_67 = F_84 ( V_1 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
struct V_15 * V_102 ;
int V_9 = V_77 -> V_79 ;
int V_43 ;
if ( V_18 -> V_103 & V_104 ) {
struct V_105 V_106 = {
. V_107 = F_75 ,
} ;
return F_85 ( V_101 , V_16 , V_18 , & V_106 ) ;
}
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_86 ( V_3 ) )
return F_87 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_84 ] , V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
V_102 = F_88 ( V_88 , V_34 ) ;
if ( ! V_102 )
return - V_40 ;
V_43 = F_59 ( V_102 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 , V_41 , 0 ,
V_9 , V_20 ) ;
if ( V_43 < 0 )
goto V_43;
return F_89 ( V_101 , V_102 , F_16 ( V_16 ) . V_25 ) ;
V_43:
F_72 ( V_102 ) ;
return V_43 ;
}
static void F_90 ( struct V_1 * V_1 ,
const struct V_2 * V_3 ,
struct V_19 * V_20 ,
T_1 V_108 )
{
struct V_21 * V_22 ;
T_1 V_72 = 0 ;
F_10 (chain, &table->chains, list) {
if ( ! F_38 ( V_1 , V_22 ) )
continue;
if ( ! F_25 ( V_22 ) )
continue;
if ( V_108 && V_72 ++ == V_108 )
break;
F_29 ( V_1 , F_27 ( V_22 ) -> V_38 ,
V_3 -> V_109 ) ;
}
}
static int F_91 ( struct V_1 * V_1 ,
const struct V_2 * V_3 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 ;
int V_43 , V_72 = 0 ;
F_10 (chain, &table->chains, list) {
if ( ! F_38 ( V_1 , V_22 ) )
continue;
if ( ! F_25 ( V_22 ) )
continue;
V_43 = F_26 ( V_1 , F_27 ( V_22 ) -> V_38 ,
V_3 -> V_109 ) ;
if ( V_43 < 0 )
goto V_43;
V_72 ++ ;
}
return 0 ;
V_43:
if ( V_72 )
F_90 ( V_1 , V_3 , V_20 , V_72 ) ;
return V_43 ;
}
static void F_92 ( struct V_1 * V_1 ,
const struct V_2 * V_3 ,
struct V_19 * V_20 )
{
F_90 ( V_1 , V_3 , V_20 , 0 ) ;
}
static int F_93 ( struct V_13 * V_14 )
{
struct V_29 * V_33 ;
T_1 V_36 ;
int V_110 = 0 ;
if ( ! V_14 -> V_24 [ V_85 ] )
return 0 ;
V_36 = F_41 ( F_42 ( V_14 -> V_24 [ V_85 ] ) ) ;
if ( V_36 & ~ V_37 )
return - V_69 ;
if ( V_36 == V_14 -> V_20 -> V_36 )
return 0 ;
V_33 = F_20 ( V_14 , V_41 ,
sizeof( struct V_39 ) ) ;
if ( V_33 == NULL )
return - V_40 ;
if ( ( V_36 & V_37 ) &&
! ( V_14 -> V_20 -> V_36 & V_37 ) ) {
F_94 ( V_33 ) = false ;
} else if ( ! ( V_36 & V_37 ) &&
V_14 -> V_20 -> V_36 & V_37 ) {
V_110 = F_91 ( V_14 -> V_1 , V_14 -> V_3 , V_14 -> V_20 ) ;
if ( V_110 >= 0 ) {
V_14 -> V_20 -> V_36 &= ~ V_37 ;
F_94 ( V_33 ) = true ;
}
}
if ( V_110 < 0 )
goto V_43;
F_95 ( V_33 ) = true ;
F_32 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_42 ) ;
return 0 ;
V_43:
F_21 ( V_33 ) ;
return V_110 ;
}
static int F_96 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_62 ( V_18 ) ;
T_3 V_67 = F_97 ( V_1 ) ;
const struct V_23 * V_68 ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
int V_9 = V_77 -> V_79 ;
T_1 V_36 = 0 ;
struct V_13 V_14 ;
int V_43 ;
V_3 = F_11 ( V_1 , V_9 , true ) ;
if ( F_86 ( V_3 ) )
return F_87 ( V_3 ) ;
V_68 = V_24 [ V_84 ] ;
V_20 = F_53 ( V_3 , V_68 , V_67 ) ;
if ( F_86 ( V_20 ) ) {
if ( F_87 ( V_20 ) != - V_51 )
return F_87 ( V_20 ) ;
} else {
if ( V_18 -> V_103 & V_111 )
return - V_112 ;
if ( V_18 -> V_103 & V_113 )
return - V_114 ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return F_93 ( & V_14 ) ;
}
if ( V_24 [ V_85 ] ) {
V_36 = F_41 ( F_42 ( V_24 [ V_85 ] ) ) ;
if ( V_36 & ~ V_37 )
return - V_69 ;
}
V_43 = - V_12 ;
if ( ! F_98 ( V_3 -> V_115 ) )
goto V_116;
V_43 = - V_40 ;
V_20 = F_19 ( sizeof( * V_20 ) , V_34 ) ;
if ( V_20 == NULL )
goto V_117;
F_99 ( V_20 -> V_68 , V_68 , V_118 ) ;
F_2 ( & V_20 -> V_119 ) ;
F_2 ( & V_20 -> V_120 ) ;
F_2 ( & V_20 -> V_121 ) ;
V_20 -> V_36 = V_36 ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
V_43 = F_30 ( & V_14 , V_41 ) ;
if ( V_43 < 0 )
goto V_122;
F_4 ( & V_20 -> V_6 , & V_3 -> V_4 ) ;
return 0 ;
V_122:
F_23 ( V_20 ) ;
V_117:
F_100 ( V_3 -> V_115 ) ;
V_116:
return V_43 ;
}
static int F_101 ( struct V_13 * V_14 )
{
int V_43 ;
struct V_21 * V_22 , * V_123 ;
struct V_62 * V_63 , * V_124 ;
struct V_56 * V_57 , * V_125 ;
F_10 (chain, &ctx->table->chains, list) {
if ( ! F_38 ( V_14 -> V_1 , V_22 ) )
continue;
V_14 -> V_22 = V_22 ;
V_43 = F_44 ( V_14 ) ;
if ( V_43 < 0 )
goto V_126;
}
F_102 (set, ns, &ctx->table->sets, list) {
if ( ! F_38 ( V_14 -> V_1 , V_57 ) )
continue;
if ( V_57 -> V_36 & V_127 &&
! F_103 ( & V_57 -> V_128 ) )
continue;
V_43 = F_47 ( V_14 , V_57 ) ;
if ( V_43 < 0 )
goto V_126;
}
F_102 (obj, ne, &ctx->table->objects, list) {
V_43 = F_49 ( V_14 , V_63 ) ;
if ( V_43 < 0 )
goto V_126;
}
F_102 (chain, nc, &ctx->table->chains, list) {
if ( ! F_38 ( V_14 -> V_1 , V_22 ) )
continue;
V_14 -> V_22 = V_22 ;
V_43 = F_36 ( V_14 ) ;
if ( V_43 < 0 )
goto V_126;
}
V_43 = F_33 ( V_14 ) ;
V_126:
return V_43 ;
}
static int F_104 ( struct V_13 * V_14 , int V_9 )
{
struct V_2 * V_3 ;
struct V_19 * V_20 , * V_129 ;
const struct V_23 * const * V_24 = V_14 -> V_24 ;
int V_43 = 0 ;
F_10 (afi, &ctx->net->nft.af_info, list) {
if ( V_9 != V_130 && V_3 -> V_9 != V_9 )
continue;
V_14 -> V_3 = V_3 ;
F_102 (table, nt, &afi->tables, list) {
if ( ! F_38 ( V_14 -> V_1 , V_20 ) )
continue;
if ( V_24 [ V_84 ] &&
F_51 ( V_24 [ V_84 ] , V_20 -> V_68 ) != 0 )
continue;
V_14 -> V_20 = V_20 ;
V_43 = F_101 ( V_14 ) ;
if ( V_43 < 0 )
goto V_126;
}
}
V_126:
return V_43 ;
}
static int F_105 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_62 ( V_18 ) ;
T_3 V_67 = F_97 ( V_1 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
int V_9 = V_77 -> V_79 ;
struct V_13 V_14 ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , NULL , NULL , NULL , V_24 ) ;
if ( V_9 == V_130 || V_24 [ V_84 ] == NULL )
return F_104 ( & V_14 , V_9 ) ;
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_86 ( V_3 ) )
return F_87 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_84 ] , V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
V_14 . V_3 = V_3 ;
V_14 . V_20 = V_20 ;
return F_101 ( & V_14 ) ;
}
static void F_106 ( struct V_13 * V_14 )
{
F_107 ( V_14 -> V_20 -> V_48 > 0 ) ;
F_23 ( V_14 -> V_20 ) ;
F_100 ( V_14 -> V_3 -> V_115 ) ;
}
int F_108 ( const struct V_71 * V_131 )
{
int V_43 = 0 ;
F_3 ( V_5 ) ;
if ( V_74 [ V_131 -> V_9 ] [ V_131 -> type ] != NULL ) {
V_43 = - V_132 ;
goto V_126;
}
V_74 [ V_131 -> V_9 ] [ V_131 -> type ] = V_131 ;
V_126:
F_5 ( V_5 ) ;
return V_43 ;
}
void F_109 ( const struct V_71 * V_131 )
{
F_3 ( V_5 ) ;
V_74 [ V_131 -> V_9 ] [ V_131 -> type ] = NULL ;
F_5 ( V_5 ) ;
}
static struct V_21 *
F_110 ( const struct V_19 * V_20 , T_4 V_133 ,
T_3 V_67 )
{
struct V_21 * V_22 ;
F_10 (chain, &table->chains, list) {
if ( V_22 -> V_133 == V_133 &&
F_52 ( V_22 , V_67 ) )
return V_22 ;
}
return F_14 ( - V_51 ) ;
}
static struct V_21 * F_111 ( const struct V_19 * V_20 ,
const struct V_23 * V_24 ,
T_3 V_67 )
{
struct V_21 * V_22 ;
if ( V_24 == NULL )
return F_14 ( - V_69 ) ;
F_10 (chain, &table->chains, list) {
if ( ! F_51 ( V_24 , V_22 -> V_68 ) &&
F_52 ( V_22 , V_67 ) )
return V_22 ;
}
return F_14 ( - V_51 ) ;
}
static int F_112 ( struct V_15 * V_16 , struct V_134 T_5 * V_135 )
{
struct V_134 * V_136 , V_137 ;
struct V_23 * V_138 ;
unsigned int V_27 ;
T_4 V_139 , V_140 ;
int V_141 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
F_113 (cpu) {
V_136 = F_114 ( V_135 , V_141 ) ;
do {
V_27 = F_115 ( & V_136 -> V_142 ) ;
V_139 = V_136 -> V_139 ;
V_140 = V_136 -> V_140 ;
} while ( F_116 ( & V_136 -> V_142 , V_27 ) );
V_137 . V_139 += V_139 ;
V_137 . V_140 += V_140 ;
}
V_138 = F_117 ( V_16 , V_143 ) ;
if ( V_138 == NULL )
goto V_78;
if ( F_118 ( V_16 , V_144 , F_119 ( V_137 . V_139 ) ,
V_145 ) ||
F_118 ( V_16 , V_146 , F_119 ( V_137 . V_140 ) ,
V_145 ) )
goto V_78;
F_120 ( V_16 , V_138 ) ;
return 0 ;
V_78:
return - V_147 ;
}
static int F_121 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_25 , T_1 V_27 , int V_75 , T_1 V_36 ,
int V_9 , const struct V_19 * V_20 ,
const struct V_21 * V_22 )
{
struct V_17 * V_18 ;
struct V_76 * V_77 ;
V_75 = F_60 ( V_5 , V_75 ) ;
V_18 = F_61 ( V_16 , V_25 , V_27 , V_75 , sizeof( struct V_76 ) , V_36 ) ;
if ( V_18 == NULL )
goto V_78;
V_77 = F_62 ( V_18 ) ;
V_77 -> V_79 = V_9 ;
V_77 -> V_80 = V_81 ;
V_77 -> V_82 = F_63 ( V_1 -> V_7 . V_83 & 0xffff ) ;
if ( F_64 ( V_16 , V_148 , V_20 -> V_68 ) )
goto V_78;
if ( F_118 ( V_16 , V_149 , F_119 ( V_22 -> V_133 ) ,
V_150 ) )
goto V_78;
if ( F_64 ( V_16 , V_151 , V_22 -> V_68 ) )
goto V_78;
if ( F_25 ( V_22 ) ) {
const struct F_27 * V_152 = F_27 ( V_22 ) ;
const struct V_153 * V_38 = & V_152 -> V_38 [ 0 ] ;
struct V_23 * V_138 ;
V_138 = F_117 ( V_16 , V_154 ) ;
if ( V_138 == NULL )
goto V_78;
if ( F_65 ( V_16 , V_155 , F_66 ( V_38 -> V_156 ) ) )
goto V_78;
if ( F_65 ( V_16 , V_157 , F_66 ( V_38 -> V_158 ) ) )
goto V_78;
if ( V_152 -> V_159 [ 0 ] &&
F_64 ( V_16 , V_160 , V_152 -> V_159 ) )
goto V_78;
F_120 ( V_16 , V_138 ) ;
if ( F_65 ( V_16 , V_161 ,
F_66 ( V_152 -> V_162 ) ) )
goto V_78;
if ( F_64 ( V_16 , V_163 , V_152 -> type -> V_68 ) )
goto V_78;
if ( F_112 ( V_16 , F_27 ( V_22 ) -> V_135 ) )
goto V_78;
}
if ( F_65 ( V_16 , V_164 , F_66 ( V_22 -> V_48 ) ) )
goto V_78;
F_67 ( V_16 , V_18 ) ;
return 0 ;
V_78:
F_68 ( V_16 , V_18 ) ;
return - 1 ;
}
static void F_122 ( const struct V_13 * V_14 , int V_75 )
{
struct V_15 * V_16 ;
int V_43 ;
if ( ! V_14 -> V_26 &&
! F_70 ( V_14 -> V_1 , V_87 ) )
return;
V_16 = F_71 ( V_88 , V_34 ) ;
if ( V_16 == NULL )
goto V_43;
V_43 = F_121 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_14 -> V_27 ,
V_75 , 0 , V_14 -> V_3 -> V_9 , V_14 -> V_20 ,
V_14 -> V_22 ) ;
if ( V_43 < 0 ) {
F_72 ( V_16 ) ;
goto V_43;
}
F_73 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_87 ,
V_14 -> V_26 , V_34 ) ;
return;
V_43:
F_74 ( V_14 -> V_1 , V_14 -> V_25 , V_87 , - V_89 ) ;
}
static int F_123 ( struct V_15 * V_16 ,
struct V_90 * V_91 )
{
const struct V_76 * V_77 = F_62 ( V_91 -> V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
unsigned int V_92 = 0 , V_93 = V_91 -> args [ 0 ] ;
struct V_1 * V_1 = F_76 ( V_16 -> V_94 ) ;
int V_9 = V_77 -> V_79 ;
F_77 () ;
V_91 -> V_27 = V_1 -> V_7 . V_83 ;
F_78 (afi, &net->nft.af_info, list) {
if ( V_9 != V_95 && V_9 != V_3 -> V_9 )
continue;
F_78 (table, &afi->tables, list) {
F_78 (chain, &table->chains, list) {
if ( V_92 < V_93 )
goto V_96;
if ( V_92 > V_93 )
memset ( & V_91 -> args [ 1 ] , 0 ,
sizeof( V_91 -> args ) - sizeof( V_91 -> args [ 0 ] ) ) ;
if ( ! F_79 ( V_1 , V_22 ) )
continue;
if ( F_121 ( V_16 , V_1 ,
F_16 ( V_91 -> V_16 ) . V_25 ,
V_91 -> V_18 -> V_28 ,
V_46 ,
V_97 ,
V_3 -> V_9 , V_20 , V_22 ) < 0 )
goto V_98;
F_80 ( V_91 , F_81 ( V_16 ) ) ;
V_96:
V_92 ++ ;
}
}
}
V_98:
F_82 () ;
V_91 -> args [ 0 ] = V_92 ;
return V_16 -> V_99 ;
}
static int F_124 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_62 ( V_18 ) ;
T_3 V_67 = F_84 ( V_1 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
struct V_15 * V_102 ;
int V_9 = V_77 -> V_79 ;
int V_43 ;
if ( V_18 -> V_103 & V_104 ) {
struct V_105 V_106 = {
. V_107 = F_123 ,
} ;
return F_85 ( V_101 , V_16 , V_18 , & V_106 ) ;
}
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_86 ( V_3 ) )
return F_87 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_148 ] , V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
V_22 = F_111 ( V_20 , V_24 [ V_151 ] , V_67 ) ;
if ( F_86 ( V_22 ) )
return F_87 ( V_22 ) ;
V_102 = F_88 ( V_88 , V_34 ) ;
if ( ! V_102 )
return - V_40 ;
V_43 = F_121 ( V_102 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 , V_46 , 0 ,
V_9 , V_20 , V_22 ) ;
if ( V_43 < 0 )
goto V_43;
return F_89 ( V_101 , V_102 , F_16 ( V_16 ) . V_25 ) ;
V_43:
F_72 ( V_102 ) ;
return V_43 ;
}
static struct V_134 T_5 * F_125 ( const struct V_23 * V_165 )
{
struct V_23 * V_166 [ V_167 + 1 ] ;
struct V_134 T_5 * V_168 ;
struct V_134 * V_135 ;
int V_43 ;
V_43 = F_126 ( V_166 , V_167 , V_165 , V_169 ,
NULL ) ;
if ( V_43 < 0 )
return F_14 ( V_43 ) ;
if ( ! V_166 [ V_146 ] || ! V_166 [ V_144 ] )
return F_14 ( - V_69 ) ;
V_168 = F_127 ( struct V_134 ) ;
if ( V_168 == NULL )
return F_14 ( - V_40 ) ;
F_128 () ;
V_135 = F_129 ( V_168 ) ;
V_135 -> V_140 = F_130 ( F_131 ( V_166 [ V_146 ] ) ) ;
V_135 -> V_139 = F_130 ( F_131 ( V_166 [ V_144 ] ) ) ;
F_132 () ;
return V_168 ;
}
static void F_133 ( struct F_27 * V_22 ,
struct V_134 T_5 * V_168 )
{
if ( V_168 == NULL )
return;
if ( V_22 -> V_135 ) {
struct V_134 T_5 * V_170 =
F_134 ( V_22 -> V_135 ) ;
F_135 ( V_22 -> V_135 , V_168 ) ;
F_136 () ;
F_137 ( V_170 ) ;
} else
F_135 ( V_22 -> V_135 , V_168 ) ;
}
static void F_138 ( struct V_21 * V_22 )
{
F_107 ( V_22 -> V_48 > 0 ) ;
if ( F_25 ( V_22 ) ) {
struct F_27 * V_152 = F_27 ( V_22 ) ;
F_100 ( V_152 -> type -> V_115 ) ;
F_137 ( V_152 -> V_135 ) ;
if ( V_152 -> V_38 [ 0 ] . V_171 != NULL )
F_139 ( V_152 -> V_38 [ 0 ] . V_171 ) ;
F_23 ( V_152 ) ;
} else {
F_23 ( V_22 ) ;
}
}
static int F_140 ( struct V_1 * V_1 ,
const struct V_23 * const V_24 [] ,
struct V_2 * V_3 ,
struct V_172 * V_173 , bool V_174 )
{
struct V_23 * V_175 [ V_176 + 1 ] ;
const struct V_71 * type ;
struct V_177 * V_171 ;
int V_43 ;
V_43 = F_126 ( V_175 , V_176 , V_24 [ V_154 ] ,
V_178 , NULL ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_175 [ V_155 ] == NULL ||
V_175 [ V_157 ] == NULL )
return - V_69 ;
V_173 -> V_179 = F_41 ( F_42 ( V_175 [ V_155 ] ) ) ;
if ( V_173 -> V_179 >= V_3 -> V_180 )
return - V_69 ;
V_173 -> V_158 = F_41 ( F_42 ( V_175 [ V_157 ] ) ) ;
type = V_74 [ V_3 -> V_9 ] [ V_181 ] ;
if ( V_24 [ V_163 ] ) {
type = F_56 ( V_3 , V_24 [ V_163 ] ,
V_174 ) ;
if ( F_86 ( type ) )
return F_87 ( type ) ;
}
if ( ! ( type -> V_182 & ( 1 << V_173 -> V_179 ) ) )
return - V_114 ;
if ( ! F_98 ( type -> V_115 ) )
return - V_51 ;
V_173 -> type = type ;
V_173 -> V_171 = NULL ;
if ( V_3 -> V_36 & V_183 ) {
char V_184 [ V_185 ] ;
if ( ! V_175 [ V_160 ] ) {
F_100 ( type -> V_115 ) ;
return - V_114 ;
}
F_99 ( V_184 , V_175 [ V_160 ] , V_185 ) ;
V_171 = F_141 ( V_1 , V_184 ) ;
if ( ! V_171 ) {
F_100 ( type -> V_115 ) ;
return - V_51 ;
}
V_173 -> V_171 = V_171 ;
} else if ( V_175 [ V_160 ] ) {
F_100 ( type -> V_115 ) ;
return - V_114 ;
}
return 0 ;
}
static void F_142 ( struct V_172 * V_173 )
{
F_100 ( V_173 -> type -> V_115 ) ;
if ( V_173 -> V_171 != NULL )
F_139 ( V_173 -> V_171 ) ;
}
static int F_143 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_62 ( V_18 ) ;
const struct V_23 * V_186 ( V_68 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct F_27 * V_152 = NULL ;
T_3 V_67 = F_97 ( V_1 ) ;
int V_9 = V_77 -> V_79 ;
T_3 V_162 = V_187 ;
T_4 V_133 = 0 ;
unsigned int V_72 ;
struct V_134 T_5 * V_135 ;
int V_43 ;
bool V_174 ;
struct V_13 V_14 ;
V_174 = V_18 -> V_103 & V_188 ? true : false ;
V_3 = F_11 ( V_1 , V_9 , true ) ;
if ( F_86 ( V_3 ) )
return F_87 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_148 ] , V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
V_22 = NULL ;
V_68 = V_24 [ V_151 ] ;
if ( V_24 [ V_149 ] ) {
V_133 = F_130 ( F_131 ( V_24 [ V_149 ] ) ) ;
V_22 = F_110 ( V_20 , V_133 , V_67 ) ;
if ( F_86 ( V_22 ) )
return F_87 ( V_22 ) ;
} else {
V_22 = F_111 ( V_20 , V_68 , V_67 ) ;
if ( F_86 ( V_22 ) ) {
if ( F_87 ( V_22 ) != - V_51 )
return F_87 ( V_22 ) ;
V_22 = NULL ;
}
}
if ( V_24 [ V_161 ] ) {
if ( V_22 != NULL &&
! F_25 ( V_22 ) )
return - V_114 ;
if ( V_22 == NULL &&
V_24 [ V_154 ] == NULL )
return - V_114 ;
V_162 = F_41 ( F_42 ( V_24 [ V_161 ] ) ) ;
switch ( V_162 ) {
case V_189 :
case V_187 :
break;
default:
return - V_69 ;
}
}
if ( V_22 != NULL ) {
struct V_134 * V_135 = NULL ;
struct V_29 * V_33 ;
if ( V_18 -> V_103 & V_111 )
return - V_112 ;
if ( V_18 -> V_103 & V_113 )
return - V_114 ;
if ( V_24 [ V_154 ] ) {
struct F_27 * V_152 ;
struct V_172 V_173 ;
struct V_153 * V_38 ;
if ( ! F_25 ( V_22 ) )
return - V_132 ;
V_43 = F_140 ( V_1 , V_24 , V_3 , & V_173 ,
V_174 ) ;
if ( V_43 < 0 )
return V_43 ;
V_152 = F_27 ( V_22 ) ;
if ( V_152 -> type != V_173 . type ) {
F_142 ( & V_173 ) ;
return - V_132 ;
}
for ( V_72 = 0 ; V_72 < V_3 -> V_109 ; V_72 ++ ) {
V_38 = & V_152 -> V_38 [ V_72 ] ;
if ( V_38 -> V_156 != V_173 . V_179 ||
V_38 -> V_158 != V_173 . V_158 ||
V_38 -> V_171 != V_173 . V_171 ) {
F_142 ( & V_173 ) ;
return - V_132 ;
}
}
F_142 ( & V_173 ) ;
}
if ( V_24 [ V_149 ] && V_68 ) {
struct V_21 * V_190 ;
V_190 = F_111 ( V_20 ,
V_24 [ V_151 ] ,
V_67 ) ;
if ( F_86 ( V_190 ) )
return F_87 ( V_190 ) ;
}
if ( V_24 [ V_143 ] ) {
if ( ! F_25 ( V_22 ) )
return - V_114 ;
V_135 = F_125 ( V_24 [ V_143 ] ) ;
if ( F_86 ( V_135 ) )
return F_87 ( V_135 ) ;
}
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_33 = F_20 ( & V_14 , V_46 ,
sizeof( struct V_45 ) ) ;
if ( V_33 == NULL ) {
F_137 ( V_135 ) ;
return - V_40 ;
}
F_144 ( V_33 ) = V_135 ;
F_145 ( V_33 ) = true ;
if ( V_24 [ V_161 ] )
F_146 ( V_33 ) = V_162 ;
else
F_146 ( V_33 ) = - 1 ;
if ( V_24 [ V_149 ] && V_68 ) {
F_99 ( F_147 ( V_33 ) , V_68 ,
V_191 ) ;
}
F_32 ( & V_33 -> V_6 , & V_1 -> V_7 . V_42 ) ;
return 0 ;
}
if ( V_20 -> V_48 == V_192 )
return - V_193 ;
if ( V_24 [ V_154 ] ) {
struct V_172 V_173 ;
struct V_153 * V_38 ;
T_6 * V_194 ;
V_43 = F_140 ( V_1 , V_24 , V_3 , & V_173 , V_174 ) ;
if ( V_43 < 0 )
return V_43 ;
V_152 = F_19 ( sizeof( * V_152 ) , V_34 ) ;
if ( V_152 == NULL ) {
F_142 ( & V_173 ) ;
return - V_40 ;
}
if ( V_173 . V_171 != NULL )
strncpy ( V_152 -> V_159 , V_173 . V_171 -> V_68 , V_185 ) ;
if ( V_24 [ V_143 ] ) {
V_135 = F_125 ( V_24 [ V_143 ] ) ;
if ( F_86 ( V_135 ) ) {
F_142 ( & V_173 ) ;
F_23 ( V_152 ) ;
return F_87 ( V_135 ) ;
}
V_152 -> V_135 = V_135 ;
} else {
V_135 = F_127 ( struct V_134 ) ;
if ( V_135 == NULL ) {
F_142 ( & V_173 ) ;
F_23 ( V_152 ) ;
return - V_40 ;
}
F_135 ( V_152 -> V_135 , V_135 ) ;
}
V_194 = V_173 . type -> V_195 [ V_173 . V_179 ] ;
V_152 -> type = V_173 . type ;
V_22 = & V_152 -> V_22 ;
for ( V_72 = 0 ; V_72 < V_3 -> V_109 ; V_72 ++ ) {
V_38 = & V_152 -> V_38 [ V_72 ] ;
V_38 -> V_196 = V_9 ;
V_38 -> V_156 = V_173 . V_179 ;
V_38 -> V_158 = V_173 . V_158 ;
V_38 -> V_197 = V_22 ;
V_38 -> V_173 = V_3 -> V_195 [ V_38 -> V_156 ] ;
V_38 -> V_171 = V_173 . V_171 ;
if ( V_194 )
V_38 -> V_173 = V_194 ;
if ( V_3 -> V_198 )
V_3 -> V_198 ( V_38 , V_72 ) ;
}
V_22 -> V_36 |= V_199 ;
V_152 -> V_162 = V_162 ;
} else {
V_22 = F_19 ( sizeof( * V_22 ) , V_34 ) ;
if ( V_22 == NULL )
return - V_40 ;
}
F_2 ( & V_22 -> V_200 ) ;
V_22 -> V_133 = F_54 ( V_20 ) ;
V_22 -> V_20 = V_20 ;
F_99 ( V_22 -> V_68 , V_68 , V_191 ) ;
V_43 = F_24 ( V_1 , V_20 , V_22 , V_3 -> V_109 ) ;
if ( V_43 < 0 )
goto V_116;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_43 = F_35 ( & V_14 , V_46 ) ;
if ( V_43 < 0 )
goto V_117;
V_20 -> V_48 ++ ;
F_4 ( & V_22 -> V_6 , & V_20 -> V_119 ) ;
return 0 ;
V_117:
F_28 ( V_1 , V_20 , V_22 , V_3 -> V_109 ) ;
V_116:
F_138 ( V_22 ) ;
return V_43 ;
}
static int F_148 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_62 ( V_18 ) ;
T_3 V_67 = F_97 ( V_1 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
int V_9 = V_77 -> V_79 ;
struct V_13 V_14 ;
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_86 ( V_3 ) )
return F_87 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_148 ] , V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
V_22 = F_111 ( V_20 , V_24 [ V_151 ] , V_67 ) ;
if ( F_86 ( V_22 ) )
return F_87 ( V_22 ) ;
if ( V_22 -> V_48 > 0 )
return - V_132 ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
return F_36 ( & V_14 ) ;
}
int F_149 ( struct V_201 * type )
{
F_3 ( V_5 ) ;
if ( type -> V_9 == V_95 )
F_4 ( & type -> V_6 , & V_202 ) ;
else
F_150 ( & type -> V_6 , & V_202 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_151 ( struct V_201 * type )
{
F_3 ( V_5 ) ;
F_8 ( & type -> V_6 ) ;
F_5 ( V_5 ) ;
}
static const struct V_201 * F_152 ( T_3 V_9 ,
struct V_23 * V_24 )
{
const struct V_201 * type ;
F_10 (type, &nf_tables_expressions, list) {
if ( ! F_51 ( V_24 , type -> V_68 ) &&
( ! type -> V_9 || type -> V_9 == V_9 ) )
return type ;
}
return NULL ;
}
static const struct V_201 * F_153 ( T_3 V_9 ,
struct V_23 * V_24 )
{
const struct V_201 * type ;
if ( V_24 == NULL )
return F_14 ( - V_69 ) ;
type = F_152 ( V_9 , V_24 ) ;
if ( type != NULL && F_98 ( type -> V_115 ) )
return type ;
#ifdef F_12
if ( type == NULL ) {
F_5 ( V_5 ) ;
F_13 ( L_3 , V_9 ,
F_57 ( V_24 ) , ( char * ) F_58 ( V_24 ) ) ;
F_3 ( V_5 ) ;
if ( F_152 ( V_9 , V_24 ) )
return F_14 ( - V_11 ) ;
F_5 ( V_5 ) ;
F_13 ( L_4 ,
F_57 ( V_24 ) , ( char * ) F_58 ( V_24 ) ) ;
F_3 ( V_5 ) ;
if ( F_152 ( V_9 , V_24 ) )
return F_14 ( - V_11 ) ;
}
#endif
return F_14 ( - V_51 ) ;
}
static int F_154 ( struct V_15 * V_16 ,
const struct V_203 * V_204 )
{
if ( F_64 ( V_16 , V_205 , V_204 -> V_38 -> type -> V_68 ) )
goto V_78;
if ( V_204 -> V_38 -> V_107 ) {
struct V_23 * V_206 = F_117 ( V_16 , V_207 ) ;
if ( V_206 == NULL )
goto V_78;
if ( V_204 -> V_38 -> V_107 ( V_16 , V_204 ) < 0 )
goto V_78;
F_120 ( V_16 , V_206 ) ;
}
return V_16 -> V_99 ;
V_78:
return - 1 ;
}
int F_155 ( struct V_15 * V_16 , unsigned int V_165 ,
const struct V_203 * V_204 )
{
struct V_23 * V_138 ;
V_138 = F_117 ( V_16 , V_165 ) ;
if ( ! V_138 )
goto V_78;
if ( F_154 ( V_16 , V_204 ) < 0 )
goto V_78;
F_120 ( V_16 , V_138 ) ;
return 0 ;
V_78:
return - 1 ;
}
static int F_156 ( const struct V_13 * V_14 ,
const struct V_23 * V_24 ,
struct V_208 * V_209 )
{
const struct V_201 * type ;
const struct V_210 * V_38 ;
struct V_23 * V_166 [ V_211 + 1 ] ;
int V_43 ;
V_43 = F_126 ( V_166 , V_211 , V_24 , V_212 , NULL ) ;
if ( V_43 < 0 )
return V_43 ;
type = F_153 ( V_14 -> V_3 -> V_9 , V_166 [ V_205 ] ) ;
if ( F_86 ( type ) )
return F_87 ( type ) ;
if ( V_166 [ V_207 ] ) {
V_43 = F_126 ( V_209 -> V_166 , type -> V_213 ,
V_166 [ V_207 ] , type -> V_162 , NULL ) ;
if ( V_43 < 0 )
goto V_116;
} else
memset ( V_209 -> V_166 , 0 , sizeof( V_209 -> V_166 [ 0 ] ) * ( type -> V_213 + 1 ) ) ;
if ( type -> V_214 != NULL ) {
V_38 = type -> V_214 ( V_14 ,
( const struct V_23 * const * ) V_209 -> V_166 ) ;
if ( F_86 ( V_38 ) ) {
V_43 = F_87 ( V_38 ) ;
goto V_116;
}
} else
V_38 = type -> V_38 ;
V_209 -> V_38 = V_38 ;
return 0 ;
V_116:
F_100 ( type -> V_115 ) ;
return V_43 ;
}
static int F_157 ( const struct V_13 * V_14 ,
const struct V_208 * V_209 ,
struct V_203 * V_204 )
{
const struct V_210 * V_38 = V_209 -> V_38 ;
int V_43 ;
V_204 -> V_38 = V_38 ;
if ( V_38 -> V_215 ) {
V_43 = V_38 -> V_215 ( V_14 , V_204 , ( const struct V_23 * * ) V_209 -> V_166 ) ;
if ( V_43 < 0 )
goto V_116;
}
if ( V_38 -> V_216 ) {
const struct V_217 * V_206 = NULL ;
V_43 = V_38 -> V_216 ( V_14 , V_204 , & V_206 ) ;
if ( V_43 < 0 )
goto V_117;
}
return 0 ;
V_117:
if ( V_38 -> V_218 )
V_38 -> V_218 ( V_14 , V_204 ) ;
V_116:
V_204 -> V_38 = NULL ;
return V_43 ;
}
static void F_158 ( const struct V_13 * V_14 ,
struct V_203 * V_204 )
{
if ( V_204 -> V_38 -> V_218 )
V_204 -> V_38 -> V_218 ( V_14 , V_204 ) ;
F_100 ( V_204 -> V_38 -> type -> V_115 ) ;
}
struct V_203 * F_159 ( const struct V_13 * V_14 ,
const struct V_23 * V_24 )
{
struct V_208 V_209 ;
struct V_203 * V_204 ;
int V_43 ;
V_43 = F_156 ( V_14 , V_24 , & V_209 ) ;
if ( V_43 < 0 )
goto V_116;
V_43 = - V_40 ;
V_204 = F_19 ( V_209 . V_38 -> V_31 , V_34 ) ;
if ( V_204 == NULL )
goto V_117;
V_43 = F_157 ( V_14 , & V_209 , V_204 ) ;
if ( V_43 < 0 )
goto V_122;
return V_204 ;
V_122:
F_23 ( V_204 ) ;
V_117:
F_100 ( V_209 . V_38 -> type -> V_115 ) ;
V_116:
return F_14 ( V_43 ) ;
}
void F_160 ( const struct V_13 * V_14 , struct V_203 * V_204 )
{
F_158 ( V_14 , V_204 ) ;
F_23 ( V_204 ) ;
}
static struct V_49 * F_161 ( const struct V_21 * V_22 ,
T_4 V_133 )
{
struct V_49 * V_50 ;
F_10 (rule, &chain->rules, list) {
if ( V_133 == V_50 -> V_133 )
return V_50 ;
}
return F_14 ( - V_51 ) ;
}
static struct V_49 * F_162 ( const struct V_21 * V_22 ,
const struct V_23 * V_24 )
{
if ( V_24 == NULL )
return F_14 ( - V_69 ) ;
return F_161 ( V_22 , F_130 ( F_131 ( V_24 ) ) ) ;
}
static int F_163 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_25 , T_1 V_27 , int V_75 ,
T_1 V_36 , int V_9 ,
const struct V_19 * V_20 ,
const struct V_21 * V_22 ,
const struct V_49 * V_50 )
{
struct V_17 * V_18 ;
struct V_76 * V_77 ;
const struct V_203 * V_204 , * V_219 ;
struct V_23 * V_6 ;
const struct V_49 * V_220 ;
T_7 type = F_60 ( V_5 , V_75 ) ;
V_18 = F_61 ( V_16 , V_25 , V_27 , type , sizeof( struct V_76 ) , V_36 ) ;
if ( V_18 == NULL )
goto V_78;
V_77 = F_62 ( V_18 ) ;
V_77 -> V_79 = V_9 ;
V_77 -> V_80 = V_81 ;
V_77 -> V_82 = F_63 ( V_1 -> V_7 . V_83 & 0xffff ) ;
if ( F_64 ( V_16 , V_221 , V_20 -> V_68 ) )
goto V_78;
if ( F_64 ( V_16 , V_222 , V_22 -> V_68 ) )
goto V_78;
if ( F_118 ( V_16 , V_223 , F_119 ( V_50 -> V_133 ) ,
V_224 ) )
goto V_78;
if ( ( V_75 != V_55 ) && ( V_50 -> V_6 . V_225 != & V_22 -> V_200 ) ) {
V_220 = F_164 ( V_50 , V_6 ) ;
if ( F_118 ( V_16 , V_226 ,
F_119 ( V_220 -> V_133 ) ,
V_224 ) )
goto V_78;
}
V_6 = F_117 ( V_16 , V_227 ) ;
if ( V_6 == NULL )
goto V_78;
F_165 (expr, next, rule) {
if ( F_155 ( V_16 , V_228 , V_204 ) < 0 )
goto V_78;
}
F_120 ( V_16 , V_6 ) ;
if ( V_50 -> V_229 ) {
struct V_230 * V_229 = V_230 ( V_50 ) ;
if ( F_166 ( V_16 , V_231 , V_229 -> V_99 + 1 ,
V_229 -> V_206 ) < 0 )
goto V_78;
}
F_67 ( V_16 , V_18 ) ;
return 0 ;
V_78:
F_68 ( V_16 , V_18 ) ;
return - 1 ;
}
static void F_167 ( const struct V_13 * V_14 ,
const struct V_49 * V_50 , int V_75 )
{
struct V_15 * V_16 ;
int V_43 ;
if ( ! V_14 -> V_26 &&
! F_70 ( V_14 -> V_1 , V_87 ) )
return;
V_16 = F_71 ( V_88 , V_34 ) ;
if ( V_16 == NULL )
goto V_43;
V_43 = F_163 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_14 -> V_27 ,
V_75 , 0 , V_14 -> V_3 -> V_9 , V_14 -> V_20 ,
V_14 -> V_22 , V_50 ) ;
if ( V_43 < 0 ) {
F_72 ( V_16 ) ;
goto V_43;
}
F_73 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_87 ,
V_14 -> V_26 , V_34 ) ;
return;
V_43:
F_74 ( V_14 -> V_1 , V_14 -> V_25 , V_87 , - V_89 ) ;
}
static int F_168 ( struct V_15 * V_16 ,
struct V_90 * V_91 )
{
const struct V_76 * V_77 = F_62 ( V_91 -> V_18 ) ;
const struct V_232 * V_14 = V_91 -> V_206 ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
const struct V_49 * V_50 ;
unsigned int V_92 = 0 , V_93 = V_91 -> args [ 0 ] ;
struct V_1 * V_1 = F_76 ( V_16 -> V_94 ) ;
int V_9 = V_77 -> V_79 ;
F_77 () ;
V_91 -> V_27 = V_1 -> V_7 . V_83 ;
F_78 (afi, &net->nft.af_info, list) {
if ( V_9 != V_95 && V_9 != V_3 -> V_9 )
continue;
F_78 (table, &afi->tables, list) {
if ( V_14 && V_14 -> V_20 [ 0 ] &&
strcmp ( V_14 -> V_20 , V_20 -> V_68 ) != 0 )
continue;
F_78 (chain, &table->chains, list) {
if ( V_14 && V_14 -> V_22 [ 0 ] &&
strcmp ( V_14 -> V_22 , V_22 -> V_68 ) != 0 )
continue;
F_78 (rule, &chain->rules, list) {
if ( ! F_79 ( V_1 , V_50 ) )
goto V_96;
if ( V_92 < V_93 )
goto V_96;
if ( V_92 > V_93 )
memset ( & V_91 -> args [ 1 ] , 0 ,
sizeof( V_91 -> args ) - sizeof( V_91 -> args [ 0 ] ) ) ;
if ( F_163 ( V_16 , V_1 , F_16 ( V_91 -> V_16 ) . V_25 ,
V_91 -> V_18 -> V_28 ,
V_53 ,
V_97 | V_233 ,
V_3 -> V_9 , V_20 , V_22 , V_50 ) < 0 )
goto V_98;
F_80 ( V_91 , F_81 ( V_16 ) ) ;
V_96:
V_92 ++ ;
}
}
}
}
V_98:
F_82 () ;
V_91 -> args [ 0 ] = V_92 ;
return V_16 -> V_99 ;
}
static int F_169 ( struct V_90 * V_91 )
{
F_23 ( V_91 -> V_206 ) ;
return 0 ;
}
static int F_170 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_62 ( V_18 ) ;
T_3 V_67 = F_84 ( V_1 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
const struct V_49 * V_50 ;
struct V_15 * V_102 ;
int V_9 = V_77 -> V_79 ;
int V_43 ;
if ( V_18 -> V_103 & V_104 ) {
struct V_105 V_106 = {
. V_107 = F_168 ,
. V_98 = F_169 ,
} ;
if ( V_24 [ V_221 ] || V_24 [ V_222 ] ) {
struct V_232 * V_14 ;
V_14 = F_19 ( sizeof( * V_14 ) , V_34 ) ;
if ( ! V_14 )
return - V_40 ;
if ( V_24 [ V_221 ] )
F_99 ( V_14 -> V_20 , V_24 [ V_221 ] ,
sizeof( V_14 -> V_20 ) ) ;
if ( V_24 [ V_222 ] )
F_99 ( V_14 -> V_22 , V_24 [ V_222 ] ,
sizeof( V_14 -> V_22 ) ) ;
V_106 . V_206 = V_14 ;
}
return F_85 ( V_101 , V_16 , V_18 , & V_106 ) ;
}
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_86 ( V_3 ) )
return F_87 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_221 ] , V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
V_22 = F_111 ( V_20 , V_24 [ V_222 ] , V_67 ) ;
if ( F_86 ( V_22 ) )
return F_87 ( V_22 ) ;
V_50 = F_162 ( V_22 , V_24 [ V_223 ] ) ;
if ( F_86 ( V_50 ) )
return F_87 ( V_50 ) ;
V_102 = F_88 ( V_88 , V_34 ) ;
if ( ! V_102 )
return - V_40 ;
V_43 = F_163 ( V_102 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 , V_53 , 0 ,
V_9 , V_20 , V_22 , V_50 ) ;
if ( V_43 < 0 )
goto V_43;
return F_89 ( V_101 , V_102 , F_16 ( V_16 ) . V_25 ) ;
V_43:
F_72 ( V_102 ) ;
return V_43 ;
}
static void F_171 ( const struct V_13 * V_14 ,
struct V_49 * V_50 )
{
struct V_203 * V_204 ;
V_204 = F_172 ( V_50 ) ;
while ( V_204 != F_173 ( V_50 ) && V_204 -> V_38 ) {
F_158 ( V_14 , V_204 ) ;
V_204 = F_174 ( V_204 ) ;
}
F_23 ( V_50 ) ;
}
static int F_175 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_62 ( V_18 ) ;
T_3 V_67 = F_97 ( V_1 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_49 * V_50 , * V_234 = NULL ;
struct V_230 * V_229 ;
struct V_29 * V_33 = NULL ;
struct V_203 * V_204 ;
struct V_13 V_14 ;
struct V_23 * V_235 ;
unsigned int V_31 , V_72 , V_236 , V_237 = 0 , V_238 = 0 ;
int V_43 , V_239 ;
bool V_174 ;
T_4 V_133 , V_240 ;
V_174 = V_18 -> V_103 & V_188 ? true : false ;
V_3 = F_11 ( V_1 , V_77 -> V_79 , V_174 ) ;
if ( F_86 ( V_3 ) )
return F_87 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_221 ] , V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
V_22 = F_111 ( V_20 , V_24 [ V_222 ] , V_67 ) ;
if ( F_86 ( V_22 ) )
return F_87 ( V_22 ) ;
if ( V_24 [ V_223 ] ) {
V_133 = F_130 ( F_131 ( V_24 [ V_223 ] ) ) ;
V_50 = F_161 ( V_22 , V_133 ) ;
if ( F_86 ( V_50 ) )
return F_87 ( V_50 ) ;
if ( V_18 -> V_103 & V_111 )
return - V_112 ;
if ( V_18 -> V_103 & V_113 )
V_234 = V_50 ;
else
return - V_114 ;
} else {
if ( ! V_174 || V_18 -> V_103 & V_113 )
return - V_69 ;
V_133 = F_54 ( V_20 ) ;
if ( V_22 -> V_48 == V_192 )
return - V_193 ;
}
if ( V_24 [ V_226 ] ) {
if ( ! ( V_18 -> V_103 & V_188 ) )
return - V_114 ;
V_240 = F_130 ( F_131 ( V_24 [ V_226 ] ) ) ;
V_234 = F_161 ( V_22 , V_240 ) ;
if ( F_86 ( V_234 ) )
return F_87 ( V_234 ) ;
}
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_236 = 0 ;
V_31 = 0 ;
if ( V_24 [ V_227 ] ) {
F_176 (tmp, nla[NFTA_RULE_EXPRESSIONS], rem) {
V_43 = - V_69 ;
if ( F_177 ( V_235 ) != V_228 )
goto V_116;
if ( V_236 == V_241 )
goto V_116;
V_43 = F_156 ( & V_14 , V_235 , & V_209 [ V_236 ] ) ;
if ( V_43 < 0 )
goto V_116;
V_31 += V_209 [ V_236 ] . V_38 -> V_31 ;
V_236 ++ ;
}
}
V_43 = - V_242 ;
if ( V_31 >= 1 << 12 )
goto V_116;
if ( V_24 [ V_231 ] ) {
V_237 = F_57 ( V_24 [ V_231 ] ) ;
if ( V_237 > 0 )
V_238 = sizeof( struct V_230 ) + V_237 ;
}
V_43 = - V_40 ;
V_50 = F_19 ( sizeof( * V_50 ) + V_31 + V_238 , V_34 ) ;
if ( V_50 == NULL )
goto V_116;
F_31 ( V_1 , V_50 ) ;
V_50 -> V_133 = V_133 ;
V_50 -> V_243 = V_31 ;
V_50 -> V_229 = V_237 ? 1 : 0 ;
if ( V_237 ) {
V_229 = V_230 ( V_50 ) ;
V_229 -> V_99 = V_237 - 1 ;
F_178 ( V_229 -> V_206 , V_24 [ V_231 ] , V_237 ) ;
}
V_204 = F_172 ( V_50 ) ;
for ( V_72 = 0 ; V_72 < V_236 ; V_72 ++ ) {
V_43 = F_157 ( & V_14 , & V_209 [ V_72 ] , V_204 ) ;
if ( V_43 < 0 )
goto V_117;
V_209 [ V_72 ] . V_38 = NULL ;
V_204 = F_174 ( V_204 ) ;
}
if ( V_18 -> V_103 & V_113 ) {
if ( F_38 ( V_1 , V_234 ) ) {
V_33 = F_39 ( & V_14 , V_55 ,
V_234 ) ;
if ( V_33 == NULL ) {
V_43 = - V_40 ;
goto V_117;
}
F_34 ( V_1 , V_234 ) ;
V_22 -> V_48 -- ;
F_4 ( & V_50 -> V_6 , & V_234 -> V_6 ) ;
} else {
V_43 = - V_51 ;
goto V_117;
}
} else if ( V_18 -> V_103 & V_233 )
if ( V_234 )
F_150 ( & V_50 -> V_6 , & V_234 -> V_6 ) ;
else
F_4 ( & V_50 -> V_6 , & V_22 -> V_200 ) ;
else {
if ( V_234 )
F_4 ( & V_50 -> V_6 , & V_234 -> V_6 ) ;
else
F_150 ( & V_50 -> V_6 , & V_22 -> V_200 ) ;
}
if ( F_39 ( & V_14 , V_53 , V_50 ) == NULL ) {
V_43 = - V_40 ;
goto V_122;
}
V_22 -> V_48 ++ ;
return 0 ;
V_122:
F_8 ( & V_50 -> V_6 ) ;
V_117:
F_171 ( & V_14 , V_50 ) ;
V_116:
for ( V_72 = 0 ; V_72 < V_236 ; V_72 ++ ) {
if ( V_209 [ V_72 ] . V_38 != NULL )
F_100 ( V_209 [ V_72 ] . V_38 -> type -> V_115 ) ;
}
return V_43 ;
}
static struct V_49 * F_179 ( const struct V_1 * V_1 ,
const struct V_23 * V_24 )
{
T_1 V_244 = F_41 ( F_42 ( V_24 ) ) ;
struct V_29 * V_33 ;
F_10 (trans, &net->nft.commit_list, list) {
struct V_49 * V_50 = V_52 ( V_33 ) ;
if ( V_33 -> V_30 == V_53 &&
V_244 == F_40 ( V_33 ) )
return V_50 ;
}
return F_14 ( - V_51 ) ;
}
static int F_180 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_62 ( V_18 ) ;
T_3 V_67 = F_97 ( V_1 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 = NULL ;
struct V_49 * V_50 ;
int V_9 = V_77 -> V_79 , V_43 = 0 ;
struct V_13 V_14 ;
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_86 ( V_3 ) )
return F_87 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_221 ] , V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
if ( V_24 [ V_222 ] ) {
V_22 = F_111 ( V_20 , V_24 [ V_222 ] ,
V_67 ) ;
if ( F_86 ( V_22 ) )
return F_87 ( V_22 ) ;
}
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
if ( V_22 ) {
if ( V_24 [ V_223 ] ) {
V_50 = F_162 ( V_22 ,
V_24 [ V_223 ] ) ;
if ( F_86 ( V_50 ) )
return F_87 ( V_50 ) ;
V_43 = F_43 ( & V_14 , V_50 ) ;
} else if ( V_24 [ V_54 ] ) {
V_50 = F_179 ( V_1 , V_24 [ V_54 ] ) ;
if ( F_86 ( V_50 ) )
return F_87 ( V_50 ) ;
V_43 = F_43 ( & V_14 , V_50 ) ;
} else {
V_43 = F_44 ( & V_14 ) ;
}
} else {
F_10 (chain, &table->chains, list) {
if ( ! F_38 ( V_1 , V_22 ) )
continue;
V_14 . V_22 = V_22 ;
V_43 = F_44 ( & V_14 ) ;
if ( V_43 < 0 )
break;
}
}
return V_43 ;
}
int F_181 ( struct V_245 * V_38 )
{
F_3 ( V_5 ) ;
F_4 ( & V_38 -> V_6 , & V_246 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_182 ( struct V_245 * V_38 )
{
F_3 ( V_5 ) ;
F_8 ( & V_38 -> V_6 ) ;
F_5 ( V_5 ) ;
}
static const struct V_245 *
F_183 ( const struct V_23 * const V_24 [] ,
const struct V_247 * V_248 ,
enum V_249 V_162 )
{
const struct V_245 * V_38 , * V_250 ;
struct V_251 V_252 , V_253 ;
T_1 V_254 ;
#ifdef F_12
if ( F_103 ( & V_246 ) ) {
F_5 ( V_5 ) ;
F_13 ( L_5 ) ;
F_3 ( V_5 ) ;
if ( ! F_103 ( & V_246 ) )
return F_14 ( - V_11 ) ;
}
#endif
V_254 = 0 ;
if ( V_24 [ V_255 ] != NULL ) {
V_254 = F_41 ( F_42 ( V_24 [ V_255 ] ) ) ;
V_254 &= V_256 | V_257 | V_258 |
V_259 ;
}
V_250 = NULL ;
V_253 . V_31 = ~ 0 ;
V_253 . V_260 = ~ 0 ;
V_253 . V_261 = ~ 0 ;
F_10 (ops, &nf_tables_set_ops, list) {
if ( ( V_38 -> V_254 & V_254 ) != V_254 )
continue;
if ( ! V_38 -> V_262 ( V_248 , V_254 , & V_252 ) )
continue;
switch ( V_162 ) {
case V_263 :
if ( V_252 . V_260 < V_253 . V_260 )
break;
if ( V_252 . V_260 == V_253 . V_260 ) {
if ( ! V_248 -> V_31 ) {
if ( V_252 . V_261 < V_253 . V_261 )
break;
} else if ( V_252 . V_31 < V_253 . V_31 ) {
break;
}
}
continue;
case V_264 :
if ( ! V_248 -> V_31 ) {
if ( V_252 . V_261 < V_253 . V_261 )
break;
if ( V_252 . V_261 == V_253 . V_261 &&
V_252 . V_260 < V_253 . V_260 )
break;
} else if ( V_252 . V_31 < V_253 . V_31 ) {
break;
}
continue;
default:
break;
}
if ( ! F_98 ( V_38 -> V_115 ) )
continue;
if ( V_250 != NULL )
F_100 ( V_250 -> V_115 ) ;
V_250 = V_38 ;
V_253 = V_252 ;
}
if ( V_250 != NULL )
return V_250 ;
return F_14 ( - V_114 ) ;
}
static int F_184 ( struct V_13 * V_14 , struct V_1 * V_1 ,
const struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
T_3 V_67 )
{
const struct V_76 * V_77 = F_62 ( V_18 ) ;
struct V_2 * V_3 = NULL ;
struct V_19 * V_20 = NULL ;
if ( V_77 -> V_79 != V_95 ) {
V_3 = F_11 ( V_1 , V_77 -> V_79 , false ) ;
if ( F_86 ( V_3 ) )
return F_87 ( V_3 ) ;
}
if ( V_24 [ V_265 ] != NULL ) {
if ( V_3 == NULL )
return - V_12 ;
V_20 = F_53 ( V_3 , V_24 [ V_265 ] ,
V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
}
F_15 ( V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return 0 ;
}
static struct V_56 * F_185 ( const struct V_19 * V_20 ,
const struct V_23 * V_24 , T_3 V_67 )
{
struct V_56 * V_57 ;
if ( V_24 == NULL )
return F_14 ( - V_69 ) ;
F_10 (set, &table->sets, list) {
if ( ! F_51 ( V_24 , V_57 -> V_68 ) &&
F_52 ( V_57 , V_67 ) )
return V_57 ;
}
return F_14 ( - V_51 ) ;
}
static struct V_56 * F_186 ( const struct V_1 * V_1 ,
const struct V_23 * V_24 ,
T_3 V_67 )
{
struct V_29 * V_33 ;
T_1 V_244 = F_41 ( F_42 ( V_24 ) ) ;
F_10 (trans, &net->nft.commit_list, list) {
struct V_56 * V_57 = V_58 ( V_33 ) ;
if ( V_33 -> V_30 == V_59 &&
V_244 == F_46 ( V_33 ) &&
F_52 ( V_57 , V_67 ) )
return V_57 ;
}
return F_14 ( - V_51 ) ;
}
struct V_56 * F_187 ( const struct V_1 * V_1 ,
const struct V_19 * V_20 ,
const struct V_23 * V_266 ,
const struct V_23 * V_267 ,
T_3 V_67 )
{
struct V_56 * V_57 ;
V_57 = F_185 ( V_20 , V_266 , V_67 ) ;
if ( F_86 ( V_57 ) ) {
if ( ! V_267 )
return V_57 ;
V_57 = F_186 ( V_1 , V_267 , V_67 ) ;
}
return V_57 ;
}
static int F_188 ( struct V_13 * V_14 , struct V_56 * V_57 ,
const char * V_68 )
{
const struct V_56 * V_72 ;
const char * V_268 ;
unsigned long * V_269 ;
unsigned int V_236 = 0 , V_270 = 0 ;
V_268 = F_189 ( V_68 , V_271 , '%' ) ;
if ( V_268 != NULL ) {
if ( V_268 [ 1 ] != 'd' || strchr ( V_268 + 2 , '%' ) )
return - V_69 ;
V_269 = ( unsigned long * ) F_190 ( V_34 ) ;
if ( V_269 == NULL )
return - V_40 ;
V_96:
F_10 (i, &ctx->table->sets, list) {
int V_235 ;
if ( ! F_38 ( V_14 -> V_1 , V_57 ) )
continue;
if ( ! sscanf ( V_72 -> V_68 , V_68 , & V_235 ) )
continue;
if ( V_235 < V_270 || V_235 >= V_270 + V_272 * V_273 )
continue;
F_191 ( V_235 - V_270 , V_269 ) ;
}
V_236 = F_192 ( V_269 , V_272 * V_273 ) ;
if ( V_236 >= V_272 * V_273 ) {
V_270 += V_272 * V_273 ;
memset ( V_269 , 0 , V_273 ) ;
goto V_96;
}
F_193 ( ( unsigned long ) V_269 ) ;
}
snprintf ( V_57 -> V_68 , sizeof( V_57 -> V_68 ) , V_68 , V_270 + V_236 ) ;
F_10 (i, &ctx->table->sets, list) {
if ( ! F_38 ( V_14 -> V_1 , V_72 ) )
continue;
if ( ! strcmp ( V_57 -> V_68 , V_72 -> V_68 ) )
return - V_274 ;
}
return 0 ;
}
static int F_194 ( struct V_15 * V_16 , const struct V_13 * V_14 ,
const struct V_56 * V_57 , T_7 V_75 , T_7 V_36 )
{
struct V_76 * V_77 ;
struct V_17 * V_18 ;
struct V_23 * V_248 ;
T_1 V_25 = V_14 -> V_25 ;
T_1 V_27 = V_14 -> V_27 ;
V_75 = F_60 ( V_5 , V_75 ) ;
V_18 = F_61 ( V_16 , V_25 , V_27 , V_75 , sizeof( struct V_76 ) ,
V_36 ) ;
if ( V_18 == NULL )
goto V_78;
V_77 = F_62 ( V_18 ) ;
V_77 -> V_79 = V_14 -> V_3 -> V_9 ;
V_77 -> V_80 = V_81 ;
V_77 -> V_82 = F_63 ( V_14 -> V_1 -> V_7 . V_83 & 0xffff ) ;
if ( F_64 ( V_16 , V_265 , V_14 -> V_20 -> V_68 ) )
goto V_78;
if ( F_64 ( V_16 , V_275 , V_57 -> V_68 ) )
goto V_78;
if ( V_57 -> V_36 != 0 )
if ( F_65 ( V_16 , V_255 , F_66 ( V_57 -> V_36 ) ) )
goto V_78;
if ( F_65 ( V_16 , V_276 , F_66 ( V_57 -> V_277 ) ) )
goto V_78;
if ( F_65 ( V_16 , V_278 , F_66 ( V_57 -> V_279 ) ) )
goto V_78;
if ( V_57 -> V_36 & V_257 ) {
if ( F_65 ( V_16 , V_280 , F_66 ( V_57 -> V_281 ) ) )
goto V_78;
if ( F_65 ( V_16 , V_282 , F_66 ( V_57 -> V_243 ) ) )
goto V_78;
}
if ( V_57 -> V_36 & V_259 &&
F_65 ( V_16 , V_283 , F_66 ( V_57 -> V_284 ) ) )
goto V_78;
if ( V_57 -> V_285 &&
F_118 ( V_16 , V_286 ,
F_119 ( F_195 ( V_57 -> V_285 ) ) ,
V_287 ) )
goto V_78;
if ( V_57 -> V_288 &&
F_65 ( V_16 , V_289 , F_66 ( V_57 -> V_288 ) ) )
goto V_78;
if ( V_57 -> V_162 != V_263 ) {
if ( F_65 ( V_16 , V_290 , F_66 ( V_57 -> V_162 ) ) )
goto V_78;
}
if ( F_166 ( V_16 , V_291 , V_57 -> V_292 , V_57 -> V_229 ) )
goto V_78;
V_248 = F_117 ( V_16 , V_293 ) ;
if ( V_248 == NULL )
goto V_78;
if ( V_57 -> V_31 &&
F_65 ( V_16 , V_294 , F_66 ( V_57 -> V_31 ) ) )
goto V_78;
F_120 ( V_16 , V_248 ) ;
F_67 ( V_16 , V_18 ) ;
return 0 ;
V_78:
F_68 ( V_16 , V_18 ) ;
return - 1 ;
}
static void F_196 ( const struct V_13 * V_14 ,
const struct V_56 * V_57 , int V_75 ,
T_2 V_295 )
{
struct V_15 * V_16 ;
T_1 V_25 = V_14 -> V_25 ;
int V_43 ;
if ( ! V_14 -> V_26 &&
! F_70 ( V_14 -> V_1 , V_87 ) )
return;
V_16 = F_71 ( V_88 , V_295 ) ;
if ( V_16 == NULL )
goto V_43;
V_43 = F_194 ( V_16 , V_14 , V_57 , V_75 , 0 ) ;
if ( V_43 < 0 ) {
F_72 ( V_16 ) ;
goto V_43;
}
F_73 ( V_16 , V_14 -> V_1 , V_25 , V_87 , V_14 -> V_26 ,
V_295 ) ;
return;
V_43:
F_74 ( V_14 -> V_1 , V_25 , V_87 , - V_89 ) ;
}
static int F_197 ( struct V_15 * V_16 , struct V_90 * V_91 )
{
const struct V_56 * V_57 ;
unsigned int V_92 , V_93 = V_91 -> args [ 0 ] ;
struct V_2 * V_3 ;
struct V_19 * V_20 , * V_296 = (struct V_19 * ) V_91 -> args [ 2 ] ;
struct V_1 * V_1 = F_76 ( V_16 -> V_94 ) ;
int V_297 = V_91 -> args [ 3 ] ;
struct V_13 * V_14 = V_91 -> V_206 , V_298 ;
if ( V_91 -> args [ 1 ] )
return V_16 -> V_99 ;
F_77 () ;
V_91 -> V_27 = V_1 -> V_7 . V_83 ;
F_78 (afi, &net->nft.af_info, list) {
if ( V_14 -> V_3 && V_14 -> V_3 != V_3 )
continue;
if ( V_297 ) {
if ( V_3 -> V_9 != V_297 )
continue;
V_297 = 0 ;
}
F_78 (table, &afi->tables, list) {
if ( V_14 -> V_20 && V_14 -> V_20 != V_20 )
continue;
if ( V_296 ) {
if ( V_296 != V_20 )
continue;
V_296 = NULL ;
}
V_92 = 0 ;
F_78 (set, &table->sets, list) {
if ( V_92 < V_93 )
goto V_96;
if ( ! F_79 ( V_1 , V_57 ) )
goto V_96;
V_298 = * V_14 ;
V_298 . V_20 = V_20 ;
V_298 . V_3 = V_3 ;
if ( F_194 ( V_16 , & V_298 , V_57 ,
V_59 ,
V_97 ) < 0 ) {
V_91 -> args [ 0 ] = V_92 ;
V_91 -> args [ 2 ] = ( unsigned long ) V_20 ;
V_91 -> args [ 3 ] = V_3 -> V_9 ;
goto V_98;
}
F_80 ( V_91 , F_81 ( V_16 ) ) ;
V_96:
V_92 ++ ;
}
if ( V_93 )
V_93 = 0 ;
}
}
V_91 -> args [ 1 ] = 1 ;
V_98:
F_82 () ;
return V_16 -> V_99 ;
}
static int F_198 ( struct V_90 * V_91 )
{
F_23 ( V_91 -> V_206 ) ;
return 0 ;
}
static int F_199 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
T_3 V_67 = F_84 ( V_1 ) ;
const struct V_56 * V_57 ;
struct V_13 V_14 ;
struct V_15 * V_102 ;
const struct V_76 * V_77 = F_62 ( V_18 ) ;
int V_43 ;
V_43 = F_184 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_67 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_18 -> V_103 & V_104 ) {
struct V_105 V_106 = {
. V_107 = F_197 ,
. V_98 = F_198 ,
} ;
struct V_13 * V_299 ;
V_299 = F_200 ( sizeof( * V_299 ) , V_34 ) ;
if ( V_299 == NULL )
return - V_40 ;
* V_299 = V_14 ;
V_106 . V_206 = V_299 ;
return F_85 ( V_101 , V_16 , V_18 , & V_106 ) ;
}
if ( V_77 -> V_79 == V_95 )
return - V_12 ;
if ( ! V_24 [ V_265 ] )
return - V_69 ;
V_57 = F_185 ( V_14 . V_20 , V_24 [ V_275 ] , V_67 ) ;
if ( F_86 ( V_57 ) )
return F_87 ( V_57 ) ;
V_102 = F_88 ( V_88 , V_34 ) ;
if ( V_102 == NULL )
return - V_40 ;
V_43 = F_194 ( V_102 , & V_14 , V_57 , V_59 , 0 ) ;
if ( V_43 < 0 )
goto V_43;
return F_89 ( V_101 , V_102 , F_16 ( V_16 ) . V_25 ) ;
V_43:
F_72 ( V_102 ) ;
return V_43 ;
}
static int F_201 ( const struct V_13 * V_14 ,
struct V_247 * V_248 ,
const struct V_23 * V_24 )
{
struct V_23 * V_300 [ V_301 + 1 ] ;
int V_43 ;
V_43 = F_126 ( V_300 , V_301 , V_24 ,
V_302 , NULL ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_300 [ V_294 ] != NULL )
V_248 -> V_31 = F_41 ( F_42 ( V_300 [ V_294 ] ) ) ;
return 0 ;
}
static int F_202 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_62 ( V_18 ) ;
T_3 V_67 = F_97 ( V_1 ) ;
const struct V_245 * V_38 ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_56 * V_57 ;
struct V_13 V_14 ;
char V_68 [ V_271 ] ;
unsigned int V_31 ;
bool V_174 ;
T_4 V_285 ;
T_1 V_277 , V_281 , V_36 , V_162 , V_288 , V_284 ;
struct V_247 V_248 ;
unsigned char * V_229 ;
T_7 V_292 ;
int V_43 ;
if ( V_24 [ V_265 ] == NULL ||
V_24 [ V_275 ] == NULL ||
V_24 [ V_278 ] == NULL ||
V_24 [ V_60 ] == NULL )
return - V_69 ;
memset ( & V_248 , 0 , sizeof( V_248 ) ) ;
V_277 = V_303 ;
if ( V_24 [ V_276 ] != NULL ) {
V_277 = F_41 ( F_42 ( V_24 [ V_276 ] ) ) ;
if ( ( V_277 & V_304 ) == V_304 )
return - V_69 ;
}
V_248 . V_279 = F_41 ( F_42 ( V_24 [ V_278 ] ) ) ;
if ( V_248 . V_279 == 0 || V_248 . V_279 > V_305 )
return - V_69 ;
V_36 = 0 ;
if ( V_24 [ V_255 ] != NULL ) {
V_36 = F_41 ( F_42 ( V_24 [ V_255 ] ) ) ;
if ( V_36 & ~ ( V_127 | V_306 |
V_256 | V_258 |
V_257 | V_307 |
V_259 ) )
return - V_69 ;
if ( ( V_36 & ( V_257 | V_307 | V_259 ) ) ==
( V_257 | V_307 | V_259 ) )
return - V_114 ;
}
V_281 = 0 ;
if ( V_24 [ V_280 ] != NULL ) {
if ( ! ( V_36 & V_257 ) )
return - V_69 ;
V_281 = F_41 ( F_42 ( V_24 [ V_280 ] ) ) ;
if ( ( V_281 & V_304 ) == V_304 &&
V_281 != V_308 )
return - V_69 ;
if ( V_281 != V_308 ) {
if ( V_24 [ V_282 ] == NULL )
return - V_69 ;
V_248 . V_243 = F_41 ( F_42 ( V_24 [ V_282 ] ) ) ;
if ( V_248 . V_243 == 0 || V_248 . V_243 > V_305 )
return - V_69 ;
} else
V_248 . V_243 = sizeof( struct V_309 ) ;
} else if ( V_36 & V_257 )
return - V_69 ;
if ( V_24 [ V_283 ] != NULL ) {
if ( ! ( V_36 & V_259 ) )
return - V_69 ;
V_284 = F_41 ( F_42 ( V_24 [ V_283 ] ) ) ;
if ( V_284 == V_310 ||
V_284 > V_311 )
return - V_69 ;
} else if ( V_36 & V_259 )
return - V_69 ;
else
V_284 = V_310 ;
V_285 = 0 ;
if ( V_24 [ V_286 ] != NULL ) {
if ( ! ( V_36 & V_258 ) )
return - V_69 ;
V_285 = F_203 ( F_130 ( F_131 (
V_24 [ V_286 ] ) ) ) ;
}
V_288 = 0 ;
if ( V_24 [ V_289 ] != NULL ) {
if ( ! ( V_36 & V_258 ) )
return - V_69 ;
V_288 = F_41 ( F_42 ( V_24 [ V_289 ] ) ) ;
}
V_162 = V_263 ;
if ( V_24 [ V_290 ] != NULL )
V_162 = F_41 ( F_42 ( V_24 [ V_290 ] ) ) ;
if ( V_24 [ V_293 ] != NULL ) {
V_43 = F_201 ( & V_14 , & V_248 , V_24 [ V_293 ] ) ;
if ( V_43 < 0 )
return V_43 ;
}
V_174 = V_18 -> V_103 & V_188 ? true : false ;
V_3 = F_11 ( V_1 , V_77 -> V_79 , V_174 ) ;
if ( F_86 ( V_3 ) )
return F_87 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_265 ] , V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
V_57 = F_185 ( V_20 , V_24 [ V_275 ] , V_67 ) ;
if ( F_86 ( V_57 ) ) {
if ( F_87 ( V_57 ) != - V_51 )
return F_87 ( V_57 ) ;
} else {
if ( V_18 -> V_103 & V_111 )
return - V_112 ;
if ( V_18 -> V_103 & V_113 )
return - V_114 ;
return 0 ;
}
if ( ! ( V_18 -> V_103 & V_188 ) )
return - V_51 ;
V_38 = F_183 ( V_24 , & V_248 , V_162 ) ;
if ( F_86 ( V_38 ) )
return F_87 ( V_38 ) ;
V_292 = 0 ;
if ( V_24 [ V_291 ] )
V_292 = F_57 ( V_24 [ V_291 ] ) ;
V_31 = 0 ;
if ( V_38 -> V_312 != NULL )
V_31 = V_38 -> V_312 ( V_24 ) ;
V_43 = - V_40 ;
V_57 = F_19 ( sizeof( * V_57 ) + V_31 + V_292 , V_34 ) ;
if ( V_57 == NULL )
goto V_116;
F_99 ( V_68 , V_24 [ V_275 ] , sizeof( V_57 -> V_68 ) ) ;
V_43 = F_188 ( & V_14 , V_57 , V_68 ) ;
if ( V_43 < 0 )
goto V_117;
V_229 = NULL ;
if ( V_292 ) {
V_229 = V_57 -> V_206 + V_31 ;
F_178 ( V_229 , V_24 [ V_291 ] , V_292 ) ;
}
F_2 ( & V_57 -> V_128 ) ;
V_57 -> V_38 = V_38 ;
V_57 -> V_277 = V_277 ;
V_57 -> V_279 = V_248 . V_279 ;
V_57 -> V_281 = V_281 ;
V_57 -> V_284 = V_284 ;
V_57 -> V_243 = V_248 . V_243 ;
V_57 -> V_36 = V_36 ;
V_57 -> V_31 = V_248 . V_31 ;
V_57 -> V_162 = V_162 ;
V_57 -> V_292 = V_292 ;
V_57 -> V_229 = V_229 ;
V_57 -> V_285 = V_285 ;
V_57 -> V_288 = V_288 ;
V_43 = V_38 -> V_215 ( V_57 , & V_248 , V_24 ) ;
if ( V_43 < 0 )
goto V_117;
V_43 = F_45 ( & V_14 , V_59 , V_57 ) ;
if ( V_43 < 0 )
goto V_122;
F_4 ( & V_57 -> V_6 , & V_20 -> V_120 ) ;
V_20 -> V_48 ++ ;
return 0 ;
V_122:
V_38 -> V_218 ( V_57 ) ;
V_117:
F_23 ( V_57 ) ;
V_116:
F_100 ( V_38 -> V_115 ) ;
return V_43 ;
}
static void F_204 ( struct V_56 * V_57 )
{
V_57 -> V_38 -> V_218 ( V_57 ) ;
F_100 ( V_57 -> V_38 -> V_115 ) ;
F_23 ( V_57 ) ;
}
static void F_205 ( const struct V_13 * V_14 , struct V_56 * V_57 )
{
F_8 ( & V_57 -> V_6 ) ;
F_196 ( V_14 , V_57 , V_61 , V_313 ) ;
F_204 ( V_57 ) ;
}
static int F_206 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_62 ( V_18 ) ;
T_3 V_67 = F_97 ( V_1 ) ;
struct V_56 * V_57 ;
struct V_13 V_14 ;
int V_43 ;
if ( V_77 -> V_79 == V_95 )
return - V_12 ;
if ( V_24 [ V_265 ] == NULL )
return - V_69 ;
V_43 = F_184 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_67 ) ;
if ( V_43 < 0 )
return V_43 ;
V_57 = F_185 ( V_14 . V_20 , V_24 [ V_275 ] , V_67 ) ;
if ( F_86 ( V_57 ) )
return F_87 ( V_57 ) ;
if ( ! F_103 ( & V_57 -> V_128 ) )
return - V_132 ;
return F_47 ( & V_14 , V_57 ) ;
}
static int F_207 ( const struct V_13 * V_14 ,
struct V_56 * V_57 ,
const struct V_314 * V_315 ,
struct V_316 * V_317 )
{
const struct V_318 * V_319 = F_208 ( V_57 , V_317 -> V_197 ) ;
enum V_320 V_321 ;
V_321 = F_209 ( V_57 -> V_281 ) ;
return F_210 ( V_14 , V_321 , F_211 ( V_319 ) ,
V_57 -> V_281 == V_308 ?
V_308 : V_303 ,
V_57 -> V_243 ) ;
}
int F_212 ( const struct V_13 * V_14 , struct V_56 * V_57 ,
struct V_322 * V_323 )
{
struct V_322 * V_72 ;
struct V_314 V_315 ;
if ( ! F_103 ( & V_57 -> V_128 ) && V_57 -> V_36 & V_127 )
return - V_132 ;
if ( V_323 -> V_36 & V_257 ) {
F_10 (i, &set->bindings, list) {
if ( V_72 -> V_36 & V_257 &&
V_72 -> V_22 == V_323 -> V_22 )
goto V_324;
}
V_315 . V_67 = F_97 ( V_14 -> V_1 ) ;
V_315 . V_325 = 0 ;
V_315 . V_326 = 0 ;
V_315 . V_43 = 0 ;
V_315 . V_327 = F_207 ;
V_57 -> V_38 -> V_328 ( V_14 , V_57 , & V_315 ) ;
if ( V_315 . V_43 < 0 )
return V_315 . V_43 ;
}
V_324:
V_323 -> V_22 = V_14 -> V_22 ;
F_4 ( & V_323 -> V_6 , & V_57 -> V_128 ) ;
return 0 ;
}
void F_213 ( const struct V_13 * V_14 , struct V_56 * V_57 ,
struct V_322 * V_323 )
{
F_8 ( & V_323 -> V_6 ) ;
if ( F_103 ( & V_57 -> V_128 ) && V_57 -> V_36 & V_127 &&
F_79 ( V_14 -> V_1 , V_57 ) )
F_205 ( V_14 , V_57 ) ;
}
static int F_214 ( struct V_13 * V_14 , struct V_1 * V_1 ,
const struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
T_3 V_67 )
{
const struct V_76 * V_77 = F_62 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
V_3 = F_11 ( V_1 , V_77 -> V_79 , false ) ;
if ( F_86 ( V_3 ) )
return F_87 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_329 ] ,
V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
F_15 ( V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return 0 ;
}
static int F_215 ( struct V_15 * V_16 ,
const struct V_56 * V_57 ,
const struct V_316 * V_317 )
{
const struct V_318 * V_319 = F_208 ( V_57 , V_317 -> V_197 ) ;
unsigned char * V_330 = F_216 ( V_16 ) ;
struct V_23 * V_138 ;
V_138 = F_117 ( V_16 , V_228 ) ;
if ( V_138 == NULL )
goto V_78;
if ( F_217 ( V_16 , V_331 , F_218 ( V_319 ) ,
V_303 , V_57 -> V_279 ) < 0 )
goto V_78;
if ( F_219 ( V_319 , V_332 ) &&
F_217 ( V_16 , V_333 , F_211 ( V_319 ) ,
V_57 -> V_281 == V_308 ? V_308 : V_303 ,
V_57 -> V_243 ) < 0 )
goto V_78;
if ( F_219 ( V_319 , V_334 ) &&
F_155 ( V_16 , V_335 , F_220 ( V_319 ) ) < 0 )
goto V_78;
if ( F_219 ( V_319 , V_336 ) &&
F_64 ( V_16 , V_337 ,
( * F_221 ( V_319 ) ) -> V_68 ) < 0 )
goto V_78;
if ( F_219 ( V_319 , V_338 ) &&
F_65 ( V_16 , V_339 ,
F_66 ( * F_222 ( V_319 ) ) ) )
goto V_78;
if ( F_219 ( V_319 , V_340 ) &&
F_118 ( V_16 , V_341 ,
F_119 ( F_195 (
* F_223 ( V_319 ) ) ) ,
V_342 ) )
goto V_78;
if ( F_219 ( V_319 , V_343 ) ) {
unsigned long V_344 , V_345 = V_346 ;
V_344 = * F_224 ( V_319 ) ;
if ( F_225 ( V_345 , V_344 ) )
V_344 -= V_345 ;
else
V_344 = 0 ;
if ( F_118 ( V_16 , V_347 ,
F_119 ( F_195 ( V_344 ) ) ,
V_342 ) )
goto V_78;
}
if ( F_219 ( V_319 , V_348 ) ) {
struct V_230 * V_229 ;
V_229 = F_226 ( V_319 ) ;
if ( F_166 ( V_16 , V_349 ,
V_229 -> V_99 + 1 , V_229 -> V_206 ) )
goto V_78;
}
F_120 ( V_16 , V_138 ) ;
return 0 ;
V_78:
F_68 ( V_16 , V_330 ) ;
return - V_350 ;
}
static int F_227 ( const struct V_13 * V_14 ,
struct V_56 * V_57 ,
const struct V_314 * V_315 ,
struct V_316 * V_317 )
{
struct V_351 * args ;
args = F_228 ( V_315 , struct V_351 , V_315 ) ;
return F_215 ( args -> V_16 , V_57 , V_317 ) ;
}
static int F_229 ( struct V_15 * V_16 , struct V_90 * V_91 )
{
struct V_352 * V_353 = V_91 -> V_206 ;
struct V_1 * V_1 = F_76 ( V_16 -> V_94 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_56 * V_57 ;
struct V_351 args ;
bool V_354 = false ;
struct V_76 * V_77 ;
struct V_17 * V_18 ;
struct V_23 * V_138 ;
T_1 V_25 , V_27 ;
int V_75 ;
F_77 () ;
F_78 (afi, &net->nft.af_info, list) {
if ( V_3 != V_353 -> V_14 . V_3 )
continue;
F_78 (table, &afi->tables, list) {
if ( V_20 != V_353 -> V_14 . V_20 )
continue;
F_78 (set, &table->sets, list) {
if ( V_57 == V_353 -> V_57 ) {
V_354 = true ;
break;
}
}
break;
}
break;
}
if ( ! V_354 ) {
F_82 () ;
return - V_51 ;
}
V_75 = F_60 ( V_5 , V_355 ) ;
V_25 = F_16 ( V_91 -> V_16 ) . V_25 ;
V_27 = V_91 -> V_18 -> V_28 ;
V_18 = F_61 ( V_16 , V_25 , V_27 , V_75 , sizeof( struct V_76 ) ,
V_97 ) ;
if ( V_18 == NULL )
goto V_78;
V_77 = F_62 ( V_18 ) ;
V_77 -> V_79 = V_3 -> V_9 ;
V_77 -> V_80 = V_81 ;
V_77 -> V_82 = F_63 ( V_1 -> V_7 . V_83 & 0xffff ) ;
if ( F_64 ( V_16 , V_329 , V_20 -> V_68 ) )
goto V_78;
if ( F_64 ( V_16 , V_356 , V_57 -> V_68 ) )
goto V_78;
V_138 = F_117 ( V_16 , V_357 ) ;
if ( V_138 == NULL )
goto V_78;
args . V_91 = V_91 ;
args . V_16 = V_16 ;
args . V_315 . V_67 = F_84 ( V_1 ) ;
args . V_315 . V_325 = V_91 -> args [ 0 ] ;
args . V_315 . V_326 = 0 ;
args . V_315 . V_43 = 0 ;
args . V_315 . V_327 = F_227 ;
V_57 -> V_38 -> V_328 ( & V_353 -> V_14 , V_57 , & args . V_315 ) ;
F_82 () ;
F_120 ( V_16 , V_138 ) ;
F_67 ( V_16 , V_18 ) ;
if ( args . V_315 . V_43 && args . V_315 . V_43 != - V_350 )
return args . V_315 . V_43 ;
if ( args . V_315 . V_326 == V_91 -> args [ 0 ] )
return 0 ;
V_91 -> args [ 0 ] = args . V_315 . V_326 ;
return V_16 -> V_99 ;
V_78:
F_82 () ;
return - V_147 ;
}
static int F_230 ( struct V_90 * V_91 )
{
F_23 ( V_91 -> V_206 ) ;
return 0 ;
}
static int F_231 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
T_3 V_67 = F_84 ( V_1 ) ;
const struct V_56 * V_57 ;
struct V_13 V_14 ;
int V_43 ;
V_43 = F_214 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_67 ) ;
if ( V_43 < 0 )
return V_43 ;
V_57 = F_185 ( V_14 . V_20 , V_24 [ V_356 ] ,
V_67 ) ;
if ( F_86 ( V_57 ) )
return F_87 ( V_57 ) ;
if ( V_18 -> V_103 & V_104 ) {
struct V_105 V_106 = {
. V_107 = F_229 ,
. V_98 = F_230 ,
} ;
struct V_352 * V_353 ;
V_353 = F_200 ( sizeof( * V_353 ) , V_34 ) ;
if ( ! V_353 )
return - V_40 ;
V_353 -> V_57 = V_57 ;
V_353 -> V_14 = V_14 ;
V_106 . V_206 = V_353 ;
return F_85 ( V_101 , V_16 , V_18 , & V_106 ) ;
}
return - V_114 ;
}
static int F_232 ( struct V_15 * V_16 ,
const struct V_13 * V_14 , T_1 V_27 ,
T_1 V_25 , int V_75 , T_7 V_36 ,
const struct V_56 * V_57 ,
const struct V_316 * V_317 )
{
struct V_76 * V_77 ;
struct V_17 * V_18 ;
struct V_23 * V_138 ;
int V_43 ;
V_75 = F_60 ( V_5 , V_75 ) ;
V_18 = F_61 ( V_16 , V_25 , V_27 , V_75 , sizeof( struct V_76 ) ,
V_36 ) ;
if ( V_18 == NULL )
goto V_78;
V_77 = F_62 ( V_18 ) ;
V_77 -> V_79 = V_14 -> V_3 -> V_9 ;
V_77 -> V_80 = V_81 ;
V_77 -> V_82 = F_63 ( V_14 -> V_1 -> V_7 . V_83 & 0xffff ) ;
if ( F_64 ( V_16 , V_265 , V_14 -> V_20 -> V_68 ) )
goto V_78;
if ( F_64 ( V_16 , V_275 , V_57 -> V_68 ) )
goto V_78;
V_138 = F_117 ( V_16 , V_357 ) ;
if ( V_138 == NULL )
goto V_78;
V_43 = F_215 ( V_16 , V_57 , V_317 ) ;
if ( V_43 < 0 )
goto V_78;
F_120 ( V_16 , V_138 ) ;
F_67 ( V_16 , V_18 ) ;
return 0 ;
V_78:
F_68 ( V_16 , V_18 ) ;
return - 1 ;
}
static void F_233 ( const struct V_13 * V_14 ,
const struct V_56 * V_57 ,
const struct V_316 * V_317 ,
int V_75 , T_7 V_36 )
{
struct V_1 * V_1 = V_14 -> V_1 ;
T_1 V_25 = V_14 -> V_25 ;
struct V_15 * V_16 ;
int V_43 ;
if ( ! V_14 -> V_26 && ! F_70 ( V_1 , V_87 ) )
return;
V_16 = F_71 ( V_88 , V_34 ) ;
if ( V_16 == NULL )
goto V_43;
V_43 = F_232 ( V_16 , V_14 , 0 , V_25 , V_75 , V_36 ,
V_57 , V_317 ) ;
if ( V_43 < 0 ) {
F_72 ( V_16 ) ;
goto V_43;
}
F_73 ( V_16 , V_1 , V_25 , V_87 , V_14 -> V_26 ,
V_34 ) ;
return;
V_43:
F_74 ( V_1 , V_25 , V_87 , - V_89 ) ;
}
static struct V_29 * F_234 ( struct V_13 * V_14 ,
int V_30 ,
struct V_56 * V_57 )
{
struct V_29 * V_33 ;
V_33 = F_20 ( V_14 , V_30 , sizeof( struct V_358 ) ) ;
if ( V_33 == NULL )
return NULL ;
F_235 ( V_33 ) = V_57 ;
return V_33 ;
}
void * F_236 ( const struct V_56 * V_57 ,
const struct V_359 * V_360 ,
const T_1 * V_361 , const T_1 * V_206 ,
T_4 V_285 , T_2 V_32 )
{
struct V_318 * V_319 ;
void * V_317 ;
V_317 = F_19 ( V_57 -> V_38 -> V_362 + V_360 -> V_99 , V_32 ) ;
if ( V_317 == NULL )
return NULL ;
V_319 = F_208 ( V_57 , V_317 ) ;
F_237 ( V_319 , V_360 ) ;
memcpy ( F_218 ( V_319 ) , V_361 , V_57 -> V_279 ) ;
if ( F_219 ( V_319 , V_332 ) )
memcpy ( F_211 ( V_319 ) , V_206 , V_57 -> V_243 ) ;
if ( F_219 ( V_319 , V_343 ) )
* F_224 ( V_319 ) =
V_346 + V_285 ;
if ( F_219 ( V_319 , V_340 ) )
* F_223 ( V_319 ) = V_285 ;
return V_317 ;
}
void F_238 ( const struct V_56 * V_57 , void * V_317 ,
bool V_363 )
{
struct V_318 * V_319 = F_208 ( V_57 , V_317 ) ;
F_239 ( F_218 ( V_319 ) , V_303 ) ;
if ( F_219 ( V_319 , V_332 ) )
F_239 ( F_211 ( V_319 ) , V_57 -> V_281 ) ;
if ( V_363 && F_219 ( V_319 , V_334 ) )
F_158 ( NULL , F_220 ( V_319 ) ) ;
if ( F_219 ( V_319 , V_336 ) )
( * F_221 ( V_319 ) ) -> V_48 -- ;
F_23 ( V_317 ) ;
}
static void F_240 ( const struct V_56 * V_57 , void * V_317 )
{
struct V_318 * V_319 = F_208 ( V_57 , V_317 ) ;
if ( F_219 ( V_319 , V_334 ) )
F_158 ( NULL , F_220 ( V_319 ) ) ;
F_23 ( V_317 ) ;
}
static int F_241 ( const struct V_56 * V_57 ,
const struct V_23 * V_165 , T_1 * V_36 )
{
if ( V_165 == NULL )
return 0 ;
* V_36 = F_41 ( F_42 ( V_165 ) ) ;
if ( * V_36 & ~ V_364 )
return - V_69 ;
if ( ! ( V_57 -> V_36 & V_256 ) &&
* V_36 & V_364 )
return - V_69 ;
return 0 ;
}
static int F_242 ( struct V_13 * V_14 , struct V_56 * V_57 ,
const struct V_23 * V_165 , T_1 V_103 )
{
struct V_23 * V_24 [ V_365 + 1 ] ;
T_3 V_67 = F_97 ( V_14 -> V_1 ) ;
struct V_366 V_367 , V_368 ;
struct V_359 V_360 ;
struct V_318 * V_319 , * V_369 ;
struct V_316 V_317 ;
struct V_322 * V_323 ;
struct V_62 * V_63 = NULL ;
struct V_230 * V_229 ;
struct V_217 V_206 ;
enum V_320 V_321 ;
struct V_29 * V_33 ;
T_1 V_36 = 0 ;
T_4 V_285 ;
T_3 V_237 ;
int V_43 ;
V_43 = F_126 ( V_24 , V_365 , V_165 ,
V_370 , NULL ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_24 [ V_331 ] == NULL )
return - V_69 ;
F_243 ( & V_360 ) ;
V_43 = F_241 ( V_57 , V_24 [ V_339 ] , & V_36 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_36 != 0 )
F_244 ( & V_360 , V_338 ) ;
if ( V_57 -> V_36 & V_257 ) {
if ( V_24 [ V_333 ] == NULL &&
! ( V_36 & V_364 ) )
return - V_69 ;
if ( V_24 [ V_333 ] != NULL &&
V_36 & V_364 )
return - V_69 ;
} else {
if ( V_24 [ V_333 ] != NULL )
return - V_69 ;
}
V_285 = 0 ;
if ( V_24 [ V_341 ] != NULL ) {
if ( ! ( V_57 -> V_36 & V_258 ) )
return - V_69 ;
V_285 = F_203 ( F_130 ( F_131 (
V_24 [ V_341 ] ) ) ) ;
} else if ( V_57 -> V_36 & V_258 ) {
V_285 = V_57 -> V_285 ;
}
V_43 = F_245 ( V_14 , & V_317 . V_361 . V_371 , sizeof( V_317 . V_361 ) , & V_367 ,
V_24 [ V_331 ] ) ;
if ( V_43 < 0 )
goto V_116;
V_43 = - V_69 ;
if ( V_367 . type != V_303 || V_367 . V_99 != V_57 -> V_279 )
goto V_117;
F_246 ( & V_360 , V_372 , V_367 . V_99 ) ;
if ( V_285 > 0 ) {
F_244 ( & V_360 , V_343 ) ;
if ( V_285 != V_57 -> V_285 )
F_244 ( & V_360 , V_340 ) ;
}
if ( V_24 [ V_337 ] != NULL ) {
if ( ! ( V_57 -> V_36 & V_259 ) ) {
V_43 = - V_69 ;
goto V_117;
}
V_63 = F_247 ( V_14 -> V_20 , V_24 [ V_337 ] ,
V_57 -> V_284 , V_67 ) ;
if ( F_86 ( V_63 ) ) {
V_43 = F_87 ( V_63 ) ;
goto V_117;
}
F_244 ( & V_360 , V_336 ) ;
}
if ( V_24 [ V_333 ] != NULL ) {
V_43 = F_245 ( V_14 , & V_206 , sizeof( V_206 ) , & V_368 ,
V_24 [ V_333 ] ) ;
if ( V_43 < 0 )
goto V_117;
V_43 = - V_69 ;
if ( V_57 -> V_281 != V_308 && V_368 . V_99 != V_57 -> V_243 )
goto V_122;
V_321 = F_209 ( V_57 -> V_281 ) ;
F_10 (binding, &set->bindings, list) {
struct V_13 V_373 = {
. V_1 = V_14 -> V_1 ,
. V_3 = V_14 -> V_3 ,
. V_20 = V_14 -> V_20 ,
. V_22 = (struct V_21 * ) V_323 -> V_22 ,
} ;
if ( ! ( V_323 -> V_36 & V_257 ) )
continue;
V_43 = F_210 ( & V_373 , V_321 ,
& V_206 ,
V_368 . type , V_368 . V_99 ) ;
if ( V_43 < 0 )
goto V_122;
}
F_246 ( & V_360 , V_332 , V_368 . V_99 ) ;
}
V_237 = 0 ;
if ( V_24 [ V_349 ] != NULL ) {
V_237 = F_57 ( V_24 [ V_349 ] ) ;
if ( V_237 > 0 )
F_246 ( & V_360 , V_348 ,
V_237 ) ;
}
V_43 = - V_40 ;
V_317 . V_197 = F_236 ( V_57 , & V_360 , V_317 . V_361 . V_371 . V_206 , V_206 . V_206 ,
V_285 , V_34 ) ;
if ( V_317 . V_197 == NULL )
goto V_122;
V_319 = F_208 ( V_57 , V_317 . V_197 ) ;
if ( V_36 )
* F_222 ( V_319 ) = V_36 ;
if ( V_237 > 0 ) {
V_229 = F_226 ( V_319 ) ;
V_229 -> V_99 = V_237 - 1 ;
F_178 ( & V_229 -> V_206 , V_24 [ V_349 ] , V_237 ) ;
}
if ( V_63 ) {
* F_221 ( V_319 ) = V_63 ;
V_63 -> V_48 ++ ;
}
V_33 = F_234 ( V_14 , V_355 , V_57 ) ;
if ( V_33 == NULL )
goto V_374;
V_319 -> V_67 = F_84 ( V_14 -> V_1 ) | V_375 ;
V_43 = V_57 -> V_38 -> V_376 ( V_14 -> V_1 , V_57 , & V_317 , & V_369 ) ;
if ( V_43 ) {
if ( V_43 == - V_112 ) {
if ( F_219 ( V_319 , V_332 ) ^
F_219 ( V_369 , V_332 ) ||
F_219 ( V_319 , V_336 ) ^
F_219 ( V_369 , V_336 ) )
return - V_132 ;
if ( ( F_219 ( V_319 , V_332 ) &&
F_219 ( V_369 , V_332 ) &&
memcmp ( F_211 ( V_319 ) ,
F_211 ( V_369 ) , V_57 -> V_243 ) != 0 ) ||
( F_219 ( V_319 , V_336 ) &&
F_219 ( V_369 , V_336 ) &&
* F_221 ( V_319 ) != * F_221 ( V_369 ) ) )
V_43 = - V_132 ;
else if ( ! ( V_103 & V_111 ) )
V_43 = 0 ;
}
goto V_377;
}
if ( V_57 -> V_31 &&
! F_248 ( & V_57 -> V_378 , 1 , V_57 -> V_31 + V_57 -> V_379 ) ) {
V_43 = - V_274 ;
goto V_380;
}
V_358 ( V_33 ) = V_317 ;
F_32 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_42 ) ;
return 0 ;
V_380:
V_57 -> V_38 -> remove ( V_14 -> V_1 , V_57 , & V_317 ) ;
V_377:
F_23 ( V_33 ) ;
V_374:
F_23 ( V_317 . V_197 ) ;
V_122:
if ( V_24 [ V_333 ] != NULL )
F_239 ( & V_206 , V_368 . type ) ;
V_117:
F_239 ( & V_317 . V_361 . V_371 , V_367 . type ) ;
V_116:
return V_43 ;
}
static int F_249 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
T_3 V_67 = F_97 ( V_1 ) ;
const struct V_23 * V_165 ;
struct V_56 * V_57 ;
struct V_13 V_14 ;
int V_239 , V_43 = 0 ;
if ( V_24 [ V_357 ] == NULL )
return - V_69 ;
V_43 = F_214 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_67 ) ;
if ( V_43 < 0 )
return V_43 ;
V_57 = F_185 ( V_14 . V_20 , V_24 [ V_356 ] ,
V_67 ) ;
if ( F_86 ( V_57 ) ) {
if ( V_24 [ V_381 ] ) {
V_57 = F_186 ( V_1 ,
V_24 [ V_381 ] ,
V_67 ) ;
}
if ( F_86 ( V_57 ) )
return F_87 ( V_57 ) ;
}
if ( ! F_103 ( & V_57 -> V_128 ) && V_57 -> V_36 & V_306 )
return - V_132 ;
F_176 (attr, nla[NFTA_SET_ELEM_LIST_ELEMENTS], rem) {
V_43 = F_242 ( & V_14 , V_57 , V_165 , V_18 -> V_103 ) ;
if ( V_43 < 0 )
break;
}
return V_43 ;
}
static void F_250 ( const struct V_217 * V_206 , enum V_382 type )
{
if ( type == V_308 ) {
switch ( V_206 -> V_383 . V_384 ) {
case V_385 :
case V_386 :
V_206 -> V_383 . V_22 -> V_48 ++ ;
break;
}
}
}
static void F_251 ( const struct V_1 * V_1 ,
const struct V_56 * V_57 ,
struct V_316 * V_317 )
{
const struct V_318 * V_319 = F_208 ( V_57 , V_317 -> V_197 ) ;
if ( F_219 ( V_319 , V_332 ) )
F_250 ( F_211 ( V_319 ) , V_57 -> V_281 ) ;
if ( F_219 ( V_319 , V_336 ) )
( * F_221 ( V_319 ) ) -> V_48 ++ ;
}
static void F_252 ( const struct V_1 * V_1 ,
const struct V_56 * V_57 ,
struct V_316 * V_317 )
{
const struct V_318 * V_319 = F_208 ( V_57 , V_317 -> V_197 ) ;
if ( F_219 ( V_319 , V_332 ) )
F_239 ( F_211 ( V_319 ) , V_57 -> V_281 ) ;
if ( F_219 ( V_319 , V_336 ) )
( * F_221 ( V_319 ) ) -> V_48 -- ;
}
static int F_253 ( struct V_13 * V_14 , struct V_56 * V_57 ,
const struct V_23 * V_165 )
{
struct V_23 * V_24 [ V_365 + 1 ] ;
struct V_359 V_360 ;
struct V_366 V_248 ;
struct V_316 V_317 ;
struct V_318 * V_319 ;
struct V_29 * V_33 ;
T_1 V_36 = 0 ;
void * V_197 ;
int V_43 ;
V_43 = F_126 ( V_24 , V_365 , V_165 ,
V_370 , NULL ) ;
if ( V_43 < 0 )
goto V_116;
V_43 = - V_69 ;
if ( V_24 [ V_331 ] == NULL )
goto V_116;
F_243 ( & V_360 ) ;
V_43 = F_241 ( V_57 , V_24 [ V_339 ] , & V_36 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_36 != 0 )
F_244 ( & V_360 , V_338 ) ;
V_43 = F_245 ( V_14 , & V_317 . V_361 . V_371 , sizeof( V_317 . V_361 ) , & V_248 ,
V_24 [ V_331 ] ) ;
if ( V_43 < 0 )
goto V_116;
V_43 = - V_69 ;
if ( V_248 . type != V_303 || V_248 . V_99 != V_57 -> V_279 )
goto V_117;
F_246 ( & V_360 , V_372 , V_248 . V_99 ) ;
V_43 = - V_40 ;
V_317 . V_197 = F_236 ( V_57 , & V_360 , V_317 . V_361 . V_371 . V_206 , NULL , 0 ,
V_34 ) ;
if ( V_317 . V_197 == NULL )
goto V_117;
V_319 = F_208 ( V_57 , V_317 . V_197 ) ;
if ( V_36 )
* F_222 ( V_319 ) = V_36 ;
V_33 = F_234 ( V_14 , V_387 , V_57 ) ;
if ( V_33 == NULL ) {
V_43 = - V_40 ;
goto V_122;
}
V_197 = V_57 -> V_38 -> V_388 ( V_14 -> V_1 , V_57 , & V_317 ) ;
if ( V_197 == NULL ) {
V_43 = - V_51 ;
goto V_374;
}
F_23 ( V_317 . V_197 ) ;
V_317 . V_197 = V_197 ;
F_252 ( V_14 -> V_1 , V_57 , & V_317 ) ;
V_358 ( V_33 ) = V_317 ;
F_32 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_42 ) ;
return 0 ;
V_374:
F_23 ( V_33 ) ;
V_122:
F_23 ( V_317 . V_197 ) ;
V_117:
F_239 ( & V_317 . V_361 . V_371 , V_248 . type ) ;
V_116:
return V_43 ;
}
static int F_254 ( const struct V_13 * V_14 ,
struct V_56 * V_57 ,
const struct V_314 * V_315 ,
struct V_316 * V_317 )
{
struct V_29 * V_33 ;
int V_43 ;
V_33 = F_18 ( V_14 , V_387 ,
sizeof( struct V_358 ) , V_313 ) ;
if ( ! V_33 )
return - V_40 ;
if ( ! V_57 -> V_38 -> V_389 ( V_14 -> V_1 , V_57 , V_317 -> V_197 ) ) {
V_43 = - V_51 ;
goto V_116;
}
V_57 -> V_379 ++ ;
F_235 ( V_33 ) = V_57 ;
V_358 ( V_33 ) = * V_317 ;
F_32 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_42 ) ;
return 0 ;
V_116:
F_23 ( V_33 ) ;
return V_43 ;
}
static int F_255 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
T_3 V_67 = F_97 ( V_1 ) ;
const struct V_23 * V_165 ;
struct V_56 * V_57 ;
struct V_13 V_14 ;
int V_239 , V_43 = 0 ;
V_43 = F_214 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_67 ) ;
if ( V_43 < 0 )
return V_43 ;
V_57 = F_185 ( V_14 . V_20 , V_24 [ V_356 ] ,
V_67 ) ;
if ( F_86 ( V_57 ) )
return F_87 ( V_57 ) ;
if ( ! F_103 ( & V_57 -> V_128 ) && V_57 -> V_36 & V_306 )
return - V_132 ;
if ( V_24 [ V_357 ] == NULL ) {
struct V_314 V_315 = {
. V_67 = V_67 ,
. V_327 = F_254 ,
} ;
V_57 -> V_38 -> V_328 ( & V_14 , V_57 , & V_315 ) ;
return V_315 . V_43 ;
}
F_176 (attr, nla[NFTA_SET_ELEM_LIST_ELEMENTS], rem) {
V_43 = F_253 ( & V_14 , V_57 , V_165 ) ;
if ( V_43 < 0 )
break;
V_57 -> V_379 ++ ;
}
return V_43 ;
}
void F_256 ( struct V_390 * V_391 )
{
struct V_392 * V_393 ;
unsigned int V_72 ;
V_393 = F_228 ( V_391 , struct V_392 , V_394 . V_391 ) ;
for ( V_72 = 0 ; V_72 < V_393 -> V_394 . V_108 ; V_72 ++ )
F_238 ( V_393 -> V_394 . V_57 , V_393 -> V_395 [ V_72 ] , true ) ;
F_23 ( V_393 ) ;
}
struct V_392 * F_257 ( const struct V_56 * V_57 ,
T_2 V_32 )
{
struct V_392 * V_393 ;
V_393 = F_19 ( sizeof( * V_393 ) , V_32 ) ;
if ( V_393 == NULL )
return V_393 ;
V_393 -> V_394 . V_57 = V_57 ;
return V_393 ;
}
int F_258 ( struct V_396 * V_397 )
{
if ( V_397 -> type == V_310 )
return - V_69 ;
F_3 ( V_5 ) ;
F_150 ( & V_397 -> V_6 , & V_398 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_259 ( struct V_396 * V_397 )
{
F_3 ( V_5 ) ;
F_8 ( & V_397 -> V_6 ) ;
F_5 ( V_5 ) ;
}
struct V_62 * F_247 ( const struct V_19 * V_20 ,
const struct V_23 * V_24 ,
T_1 V_284 , T_3 V_67 )
{
struct V_62 * V_63 ;
F_10 (obj, &table->objects, list) {
if ( ! F_51 ( V_24 , V_63 -> V_68 ) &&
V_284 == V_63 -> type -> type &&
F_52 ( V_63 , V_67 ) )
return V_63 ;
}
return F_14 ( - V_51 ) ;
}
static struct V_62 * F_260 ( const struct V_13 * V_14 ,
const struct V_396 * type ,
const struct V_23 * V_165 )
{
struct V_23 * V_166 [ type -> V_213 + 1 ] ;
struct V_62 * V_63 ;
int V_43 ;
if ( V_165 ) {
V_43 = F_126 ( V_166 , type -> V_213 , V_165 , type -> V_162 ,
NULL ) ;
if ( V_43 < 0 )
goto V_116;
} else {
memset ( V_166 , 0 , sizeof( V_166 [ 0 ] ) * ( type -> V_213 + 1 ) ) ;
}
V_43 = - V_40 ;
V_63 = F_19 ( sizeof( struct V_62 ) + type -> V_31 , V_34 ) ;
if ( V_63 == NULL )
goto V_116;
V_43 = type -> V_215 ( V_14 , ( const struct V_23 * const * ) V_166 , V_63 ) ;
if ( V_43 < 0 )
goto V_117;
V_63 -> type = type ;
return V_63 ;
V_117:
F_23 ( V_63 ) ;
V_116:
return F_14 ( V_43 ) ;
}
static int F_261 ( struct V_15 * V_16 , unsigned int V_165 ,
struct V_62 * V_63 , bool V_399 )
{
struct V_23 * V_138 ;
V_138 = F_117 ( V_16 , V_165 ) ;
if ( ! V_138 )
goto V_78;
if ( V_63 -> type -> V_107 ( V_16 , V_63 , V_399 ) < 0 )
goto V_78;
F_120 ( V_16 , V_138 ) ;
return 0 ;
V_78:
return - 1 ;
}
static const struct V_396 * F_262 ( T_1 V_284 )
{
const struct V_396 * type ;
F_10 (type, &nf_tables_objects, list) {
if ( V_284 == type -> type )
return type ;
}
return NULL ;
}
static const struct V_396 * F_263 ( T_1 V_284 )
{
const struct V_396 * type ;
type = F_262 ( V_284 ) ;
if ( type != NULL && F_98 ( type -> V_115 ) )
return type ;
#ifdef F_12
if ( type == NULL ) {
F_5 ( V_5 ) ;
F_13 ( L_6 , V_284 ) ;
F_3 ( V_5 ) ;
if ( F_262 ( V_284 ) )
return F_14 ( - V_11 ) ;
}
#endif
return F_14 ( - V_51 ) ;
}
static int F_264 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_62 ( V_18 ) ;
const struct V_396 * type ;
T_3 V_67 = F_97 ( V_1 ) ;
int V_9 = V_77 -> V_79 ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_62 * V_63 ;
struct V_13 V_14 ;
T_1 V_284 ;
int V_43 ;
if ( ! V_24 [ V_400 ] ||
! V_24 [ V_401 ] ||
! V_24 [ V_402 ] )
return - V_69 ;
V_3 = F_11 ( V_1 , V_9 , true ) ;
if ( F_86 ( V_3 ) )
return F_87 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_403 ] , V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
V_284 = F_41 ( F_42 ( V_24 [ V_400 ] ) ) ;
V_63 = F_247 ( V_20 , V_24 [ V_401 ] , V_284 , V_67 ) ;
if ( F_86 ( V_63 ) ) {
V_43 = F_87 ( V_63 ) ;
if ( V_43 != - V_51 )
return V_43 ;
} else {
if ( V_18 -> V_103 & V_111 )
return - V_112 ;
return 0 ;
}
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
type = F_263 ( V_284 ) ;
if ( F_86 ( type ) )
return F_87 ( type ) ;
V_63 = F_260 ( & V_14 , type , V_24 [ V_402 ] ) ;
if ( F_86 ( V_63 ) ) {
V_43 = F_87 ( V_63 ) ;
goto V_116;
}
V_63 -> V_20 = V_20 ;
F_99 ( V_63 -> V_68 , V_24 [ V_401 ] , V_404 ) ;
V_43 = F_48 ( & V_14 , V_65 , V_63 ) ;
if ( V_43 < 0 )
goto V_117;
F_4 ( & V_63 -> V_6 , & V_20 -> V_121 ) ;
V_20 -> V_48 ++ ;
return 0 ;
V_117:
if ( V_63 -> type -> V_218 )
V_63 -> type -> V_218 ( V_63 ) ;
F_23 ( V_63 ) ;
V_116:
F_100 ( type -> V_115 ) ;
return V_43 ;
}
static int F_265 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_25 , T_1 V_27 , int V_75 , T_1 V_36 ,
int V_9 , const struct V_19 * V_20 ,
struct V_62 * V_63 , bool V_399 )
{
struct V_76 * V_77 ;
struct V_17 * V_18 ;
V_75 = F_60 ( V_5 , V_75 ) ;
V_18 = F_61 ( V_16 , V_25 , V_27 , V_75 , sizeof( struct V_76 ) , V_36 ) ;
if ( V_18 == NULL )
goto V_78;
V_77 = F_62 ( V_18 ) ;
V_77 -> V_79 = V_9 ;
V_77 -> V_80 = V_81 ;
V_77 -> V_82 = F_63 ( V_1 -> V_7 . V_83 & 0xffff ) ;
if ( F_64 ( V_16 , V_403 , V_20 -> V_68 ) ||
F_64 ( V_16 , V_401 , V_63 -> V_68 ) ||
F_65 ( V_16 , V_400 , F_66 ( V_63 -> type -> type ) ) ||
F_65 ( V_16 , V_405 , F_66 ( V_63 -> V_48 ) ) ||
F_261 ( V_16 , V_402 , V_63 , V_399 ) )
goto V_78;
F_67 ( V_16 , V_18 ) ;
return 0 ;
V_78:
F_68 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_266 ( struct V_15 * V_16 , struct V_90 * V_91 )
{
const struct V_76 * V_77 = F_62 ( V_91 -> V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
unsigned int V_92 = 0 , V_93 = V_91 -> args [ 0 ] ;
struct V_406 * V_407 = V_91 -> V_206 ;
struct V_1 * V_1 = F_76 ( V_16 -> V_94 ) ;
int V_9 = V_77 -> V_79 ;
struct V_62 * V_63 ;
bool V_399 = false ;
if ( F_267 ( V_91 -> V_18 -> V_408 ) == V_409 )
V_399 = true ;
F_77 () ;
V_91 -> V_27 = V_1 -> V_7 . V_83 ;
F_78 (afi, &net->nft.af_info, list) {
if ( V_9 != V_95 && V_9 != V_3 -> V_9 )
continue;
F_78 (table, &afi->tables, list) {
F_78 (obj, &table->objects, list) {
if ( ! F_79 ( V_1 , V_63 ) )
goto V_96;
if ( V_92 < V_93 )
goto V_96;
if ( V_92 > V_93 )
memset ( & V_91 -> args [ 1 ] , 0 ,
sizeof( V_91 -> args ) - sizeof( V_91 -> args [ 0 ] ) ) ;
if ( V_407 && V_407 -> V_20 [ 0 ] &&
strcmp ( V_407 -> V_20 , V_20 -> V_68 ) )
goto V_96;
if ( V_407 &&
V_407 -> type != V_310 &&
V_63 -> type -> type != V_407 -> type )
goto V_96;
if ( F_265 ( V_16 , V_1 , F_16 ( V_91 -> V_16 ) . V_25 ,
V_91 -> V_18 -> V_28 ,
V_65 ,
V_97 | V_233 ,
V_3 -> V_9 , V_20 , V_63 , V_399 ) < 0 )
goto V_98;
F_80 ( V_91 , F_81 ( V_16 ) ) ;
V_96:
V_92 ++ ;
}
}
}
V_98:
F_82 () ;
V_91 -> args [ 0 ] = V_92 ;
return V_16 -> V_99 ;
}
static int F_268 ( struct V_90 * V_91 )
{
F_23 ( V_91 -> V_206 ) ;
return 0 ;
}
static struct V_406 *
F_269 ( const struct V_23 * const V_24 [] )
{
struct V_406 * V_407 ;
V_407 = F_19 ( sizeof( * V_407 ) , V_34 ) ;
if ( ! V_407 )
return F_14 ( - V_40 ) ;
if ( V_24 [ V_403 ] )
F_99 ( V_407 -> V_20 , V_24 [ V_403 ] ,
V_118 ) ;
if ( V_24 [ V_400 ] )
V_407 -> type = F_41 ( F_42 ( V_24 [ V_400 ] ) ) ;
return V_407 ;
}
static int F_270 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_62 ( V_18 ) ;
T_3 V_67 = F_84 ( V_1 ) ;
int V_9 = V_77 -> V_79 ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
struct V_62 * V_63 ;
struct V_15 * V_102 ;
bool V_399 = false ;
T_1 V_284 ;
int V_43 ;
if ( V_18 -> V_103 & V_104 ) {
struct V_105 V_106 = {
. V_107 = F_266 ,
. V_98 = F_268 ,
} ;
if ( V_24 [ V_403 ] ||
V_24 [ V_400 ] ) {
struct V_406 * V_407 ;
V_407 = F_269 ( V_24 ) ;
if ( F_86 ( V_407 ) )
return - V_40 ;
V_106 . V_206 = V_407 ;
}
return F_85 ( V_101 , V_16 , V_18 , & V_106 ) ;
}
if ( ! V_24 [ V_401 ] ||
! V_24 [ V_400 ] )
return - V_69 ;
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_86 ( V_3 ) )
return F_87 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_403 ] , V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
V_284 = F_41 ( F_42 ( V_24 [ V_400 ] ) ) ;
V_63 = F_247 ( V_20 , V_24 [ V_401 ] , V_284 , V_67 ) ;
if ( F_86 ( V_63 ) )
return F_87 ( V_63 ) ;
V_102 = F_88 ( V_88 , V_34 ) ;
if ( ! V_102 )
return - V_40 ;
if ( F_267 ( V_18 -> V_408 ) == V_409 )
V_399 = true ;
V_43 = F_265 ( V_102 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 , V_65 , 0 ,
V_9 , V_20 , V_63 , V_399 ) ;
if ( V_43 < 0 )
goto V_43;
return F_89 ( V_101 , V_102 , F_16 ( V_16 ) . V_25 ) ;
V_43:
F_72 ( V_102 ) ;
return V_43 ;
}
static void F_271 ( struct V_62 * V_63 )
{
if ( V_63 -> type -> V_218 )
V_63 -> type -> V_218 ( V_63 ) ;
F_100 ( V_63 -> type -> V_115 ) ;
F_23 ( V_63 ) ;
}
static int F_272 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_76 * V_77 = F_62 ( V_18 ) ;
T_3 V_67 = F_97 ( V_1 ) ;
int V_9 = V_77 -> V_79 ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_62 * V_63 ;
struct V_13 V_14 ;
T_1 V_284 ;
if ( ! V_24 [ V_400 ] ||
! V_24 [ V_401 ] )
return - V_69 ;
V_3 = F_11 ( V_1 , V_9 , true ) ;
if ( F_86 ( V_3 ) )
return F_87 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_403 ] , V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
V_284 = F_41 ( F_42 ( V_24 [ V_400 ] ) ) ;
V_63 = F_247 ( V_20 , V_24 [ V_401 ] , V_284 , V_67 ) ;
if ( F_86 ( V_63 ) )
return F_87 ( V_63 ) ;
if ( V_63 -> V_48 > 0 )
return - V_132 ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return F_49 ( & V_14 , V_63 ) ;
}
void F_273 ( struct V_1 * V_1 , struct V_19 * V_20 ,
struct V_62 * V_63 , T_1 V_25 , T_1 V_27 , int V_75 ,
int V_9 , int V_26 , T_2 V_32 )
{
struct V_15 * V_16 ;
int V_43 ;
if ( ! V_26 &&
! F_70 ( V_1 , V_87 ) )
return;
V_16 = F_71 ( V_88 , V_32 ) ;
if ( V_16 == NULL )
goto V_43;
V_43 = F_265 ( V_16 , V_1 , V_25 , V_27 , V_75 , 0 , V_9 ,
V_20 , V_63 , false ) ;
if ( V_43 < 0 ) {
F_72 ( V_16 ) ;
goto V_43;
}
F_73 ( V_16 , V_1 , V_25 , V_87 , V_26 , V_32 ) ;
return;
V_43:
F_74 ( V_1 , V_25 , V_87 , - V_89 ) ;
}
static void F_274 ( const struct V_13 * V_14 ,
struct V_62 * V_63 , int V_75 )
{
F_273 ( V_14 -> V_1 , V_14 -> V_20 , V_63 , V_14 -> V_25 , V_14 -> V_27 , V_75 ,
V_14 -> V_3 -> V_9 , V_14 -> V_26 , V_34 ) ;
}
static int F_275 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_25 , T_1 V_27 )
{
struct V_17 * V_18 ;
struct V_76 * V_77 ;
int V_75 = F_60 ( V_5 , V_410 ) ;
V_18 = F_61 ( V_16 , V_25 , V_27 , V_75 , sizeof( struct V_76 ) , 0 ) ;
if ( V_18 == NULL )
goto V_78;
V_77 = F_62 ( V_18 ) ;
V_77 -> V_79 = V_130 ;
V_77 -> V_80 = V_81 ;
V_77 -> V_82 = F_63 ( V_1 -> V_7 . V_83 & 0xffff ) ;
if ( F_65 ( V_16 , V_411 , F_66 ( V_1 -> V_7 . V_83 ) ) )
goto V_78;
F_67 ( V_16 , V_18 ) ;
return 0 ;
V_78:
F_68 ( V_16 , V_18 ) ;
return - V_350 ;
}
static void F_276 ( struct V_1 * V_1 , struct V_15 * V_16 ,
int V_75 )
{
struct V_17 * V_18 = F_81 ( V_16 ) ;
struct V_15 * V_102 ;
int V_43 ;
if ( F_17 ( V_18 ) &&
! F_70 ( V_1 , V_87 ) )
return;
V_102 = F_71 ( V_88 , V_34 ) ;
if ( V_102 == NULL )
goto V_43;
V_43 = F_275 ( V_102 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 ) ;
if ( V_43 < 0 ) {
F_72 ( V_102 ) ;
goto V_43;
}
F_73 ( V_102 , V_1 , F_16 ( V_16 ) . V_25 , V_87 ,
F_17 ( V_18 ) , V_34 ) ;
return;
V_43:
F_74 ( V_1 , F_16 ( V_16 ) . V_25 , V_87 ,
- V_89 ) ;
}
static int F_277 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
struct V_15 * V_102 ;
int V_43 ;
V_102 = F_88 ( V_88 , V_34 ) ;
if ( V_102 == NULL )
return - V_40 ;
V_43 = F_275 ( V_102 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 ) ;
if ( V_43 < 0 )
goto V_43;
return F_89 ( V_101 , V_102 , F_16 ( V_16 ) . V_25 ) ;
V_43:
F_72 ( V_102 ) ;
return V_43 ;
}
static void F_278 ( struct V_29 * V_33 )
{
struct F_27 * V_152 ;
if ( F_147 ( V_33 ) [ 0 ] )
strcpy ( V_33 -> V_14 . V_22 -> V_68 , F_147 ( V_33 ) ) ;
if ( ! F_25 ( V_33 -> V_14 . V_22 ) )
return;
V_152 = F_27 ( V_33 -> V_14 . V_22 ) ;
F_133 ( V_152 , F_144 ( V_33 ) ) ;
switch ( F_146 ( V_33 ) ) {
case V_189 :
case V_187 :
V_152 -> V_162 = F_146 ( V_33 ) ;
break;
}
}
static void F_279 ( struct V_29 * V_33 )
{
switch ( V_33 -> V_30 ) {
case V_44 :
F_106 ( & V_33 -> V_14 ) ;
break;
case V_47 :
F_138 ( V_33 -> V_14 . V_22 ) ;
break;
case V_55 :
F_171 ( & V_33 -> V_14 , V_52 ( V_33 ) ) ;
break;
case V_61 :
F_204 ( V_58 ( V_33 ) ) ;
break;
case V_387 :
F_240 ( F_235 ( V_33 ) ,
V_358 ( V_33 ) . V_197 ) ;
break;
case V_66 :
F_271 ( V_64 ( V_33 ) ) ;
break;
}
F_23 ( V_33 ) ;
}
static int F_280 ( struct V_1 * V_1 , struct V_15 * V_16 )
{
struct V_29 * V_33 , * V_219 ;
struct V_358 * V_412 ;
while ( ++ V_1 -> V_7 . V_83 == 0 ) ;
V_1 -> V_7 . V_413 = F_281 ( V_1 ) ;
F_136 () ;
F_102 (trans, next, &net->nft.commit_list, list) {
switch ( V_33 -> V_30 ) {
case V_41 :
if ( F_95 ( V_33 ) ) {
if ( ! F_94 ( V_33 ) ) {
F_92 ( V_1 ,
V_33 -> V_14 . V_3 ,
V_33 -> V_14 . V_20 ) ;
V_33 -> V_14 . V_20 -> V_36 |= V_37 ;
}
} else {
F_282 ( V_1 , V_33 -> V_14 . V_20 ) ;
}
F_69 ( & V_33 -> V_14 , V_41 ) ;
F_21 ( V_33 ) ;
break;
case V_44 :
F_8 ( & V_33 -> V_14 . V_20 -> V_6 ) ;
F_69 ( & V_33 -> V_14 , V_44 ) ;
break;
case V_46 :
if ( F_145 ( V_33 ) )
F_278 ( V_33 ) ;
else
F_282 ( V_1 , V_33 -> V_14 . V_22 ) ;
F_122 ( & V_33 -> V_14 , V_46 ) ;
F_21 ( V_33 ) ;
break;
case V_47 :
F_8 ( & V_33 -> V_14 . V_22 -> V_6 ) ;
F_122 ( & V_33 -> V_14 , V_47 ) ;
F_28 ( V_33 -> V_14 . V_1 ,
V_33 -> V_14 . V_20 ,
V_33 -> V_14 . V_22 ,
V_33 -> V_14 . V_3 -> V_109 ) ;
break;
case V_53 :
F_282 ( V_33 -> V_14 . V_1 , V_52 ( V_33 ) ) ;
F_167 ( & V_33 -> V_14 ,
V_52 ( V_33 ) ,
V_53 ) ;
F_21 ( V_33 ) ;
break;
case V_55 :
F_8 ( & V_52 ( V_33 ) -> V_6 ) ;
F_167 ( & V_33 -> V_14 ,
V_52 ( V_33 ) ,
V_55 ) ;
break;
case V_59 :
F_282 ( V_1 , V_58 ( V_33 ) ) ;
if ( V_58 ( V_33 ) -> V_36 & V_127 &&
! F_103 ( & V_58 ( V_33 ) -> V_128 ) )
V_33 -> V_14 . V_20 -> V_48 -- ;
F_196 ( & V_33 -> V_14 , V_58 ( V_33 ) ,
V_59 , V_34 ) ;
F_21 ( V_33 ) ;
break;
case V_61 :
F_8 ( & V_58 ( V_33 ) -> V_6 ) ;
F_196 ( & V_33 -> V_14 , V_58 ( V_33 ) ,
V_61 , V_34 ) ;
break;
case V_355 :
V_412 = (struct V_358 * ) V_33 -> V_206 ;
V_412 -> V_57 -> V_38 -> V_414 ( V_1 , V_412 -> V_57 , & V_412 -> V_317 ) ;
F_233 ( & V_33 -> V_14 , V_412 -> V_57 ,
& V_412 -> V_317 ,
V_355 , 0 ) ;
F_21 ( V_33 ) ;
break;
case V_387 :
V_412 = (struct V_358 * ) V_33 -> V_206 ;
F_233 ( & V_33 -> V_14 , V_412 -> V_57 ,
& V_412 -> V_317 ,
V_387 , 0 ) ;
V_412 -> V_57 -> V_38 -> remove ( V_1 , V_412 -> V_57 , & V_412 -> V_317 ) ;
F_283 ( & V_412 -> V_57 -> V_378 ) ;
V_412 -> V_57 -> V_379 -- ;
break;
case V_65 :
F_282 ( V_1 , V_64 ( V_33 ) ) ;
F_274 ( & V_33 -> V_14 , V_64 ( V_33 ) ,
V_65 ) ;
F_21 ( V_33 ) ;
break;
case V_66 :
F_8 ( & V_64 ( V_33 ) -> V_6 ) ;
F_274 ( & V_33 -> V_14 , V_64 ( V_33 ) ,
V_66 ) ;
break;
}
}
F_136 () ;
F_102 (trans, next, &net->nft.commit_list, list) {
F_22 ( & V_33 -> V_6 ) ;
F_279 ( V_33 ) ;
}
F_276 ( V_1 , V_16 , V_410 ) ;
return 0 ;
}
static void F_284 ( struct V_29 * V_33 )
{
switch ( V_33 -> V_30 ) {
case V_41 :
F_106 ( & V_33 -> V_14 ) ;
break;
case V_46 :
F_138 ( V_33 -> V_14 . V_22 ) ;
break;
case V_53 :
F_171 ( & V_33 -> V_14 , V_52 ( V_33 ) ) ;
break;
case V_59 :
F_204 ( V_58 ( V_33 ) ) ;
break;
case V_355 :
F_238 ( F_235 ( V_33 ) ,
V_358 ( V_33 ) . V_197 , true ) ;
break;
case V_65 :
F_271 ( V_64 ( V_33 ) ) ;
break;
}
F_23 ( V_33 ) ;
}
static int F_285 ( struct V_1 * V_1 , struct V_15 * V_16 )
{
struct V_29 * V_33 , * V_219 ;
struct V_358 * V_412 ;
F_286 (trans, next, &net->nft.commit_list,
list) {
switch ( V_33 -> V_30 ) {
case V_41 :
if ( F_95 ( V_33 ) ) {
if ( F_94 ( V_33 ) ) {
F_92 ( V_1 ,
V_33 -> V_14 . V_3 ,
V_33 -> V_14 . V_20 ) ;
V_33 -> V_14 . V_20 -> V_36 |= V_37 ;
}
F_21 ( V_33 ) ;
} else {
F_8 ( & V_33 -> V_14 . V_20 -> V_6 ) ;
}
break;
case V_44 :
F_282 ( V_33 -> V_14 . V_1 , V_33 -> V_14 . V_20 ) ;
F_21 ( V_33 ) ;
break;
case V_46 :
if ( F_145 ( V_33 ) ) {
F_137 ( F_144 ( V_33 ) ) ;
F_21 ( V_33 ) ;
} else {
V_33 -> V_14 . V_20 -> V_48 -- ;
F_8 ( & V_33 -> V_14 . V_22 -> V_6 ) ;
F_28 ( V_33 -> V_14 . V_1 ,
V_33 -> V_14 . V_20 ,
V_33 -> V_14 . V_22 ,
V_33 -> V_14 . V_3 -> V_109 ) ;
}
break;
case V_47 :
V_33 -> V_14 . V_20 -> V_48 ++ ;
F_282 ( V_33 -> V_14 . V_1 , V_33 -> V_14 . V_22 ) ;
F_21 ( V_33 ) ;
break;
case V_53 :
V_33 -> V_14 . V_22 -> V_48 -- ;
F_8 ( & V_52 ( V_33 ) -> V_6 ) ;
break;
case V_55 :
V_33 -> V_14 . V_22 -> V_48 ++ ;
F_282 ( V_33 -> V_14 . V_1 , V_52 ( V_33 ) ) ;
F_21 ( V_33 ) ;
break;
case V_59 :
V_33 -> V_14 . V_20 -> V_48 -- ;
F_8 ( & V_58 ( V_33 ) -> V_6 ) ;
break;
case V_61 :
V_33 -> V_14 . V_20 -> V_48 ++ ;
F_282 ( V_33 -> V_14 . V_1 , V_58 ( V_33 ) ) ;
F_21 ( V_33 ) ;
break;
case V_355 :
V_412 = (struct V_358 * ) V_33 -> V_206 ;
V_412 -> V_57 -> V_38 -> remove ( V_1 , V_412 -> V_57 , & V_412 -> V_317 ) ;
F_283 ( & V_412 -> V_57 -> V_378 ) ;
break;
case V_387 :
V_412 = (struct V_358 * ) V_33 -> V_206 ;
F_251 ( V_1 , V_412 -> V_57 , & V_412 -> V_317 ) ;
V_412 -> V_57 -> V_38 -> V_414 ( V_1 , V_412 -> V_57 , & V_412 -> V_317 ) ;
V_412 -> V_57 -> V_379 -- ;
F_21 ( V_33 ) ;
break;
case V_65 :
V_33 -> V_14 . V_20 -> V_48 -- ;
F_8 ( & V_64 ( V_33 ) -> V_6 ) ;
break;
case V_66 :
V_33 -> V_14 . V_20 -> V_48 ++ ;
F_282 ( V_33 -> V_14 . V_1 , V_64 ( V_33 ) ) ;
F_21 ( V_33 ) ;
break;
}
}
F_136 () ;
F_286 (trans, next,
&net->nft.commit_list, list) {
F_22 ( & V_33 -> V_6 ) ;
F_284 ( V_33 ) ;
}
return 0 ;
}
static bool F_287 ( struct V_1 * V_1 , T_1 V_415 )
{
return V_1 -> V_7 . V_83 == V_415 ;
}
int F_288 ( const struct V_21 * V_22 ,
enum V_416 type )
{
const struct F_27 * V_152 ;
if ( F_25 ( V_22 ) ) {
V_152 = F_27 ( V_22 ) ;
if ( V_152 -> type -> type != type )
return - V_114 ;
}
return 0 ;
}
int F_289 ( const struct V_21 * V_22 ,
unsigned int V_417 )
{
struct F_27 * V_152 ;
if ( F_25 ( V_22 ) ) {
V_152 = F_27 ( V_22 ) ;
if ( ( 1 << V_152 -> V_38 [ 0 ] . V_156 ) & V_417 )
return 0 ;
return - V_114 ;
}
return 0 ;
}
static int F_290 ( const struct V_13 * V_14 ,
struct V_56 * V_57 ,
const struct V_314 * V_315 ,
struct V_316 * V_317 )
{
const struct V_318 * V_319 = F_208 ( V_57 , V_317 -> V_197 ) ;
const struct V_217 * V_206 ;
if ( F_219 ( V_319 , V_338 ) &&
* F_222 ( V_319 ) & V_364 )
return 0 ;
V_206 = F_211 ( V_319 ) ;
switch ( V_206 -> V_383 . V_384 ) {
case V_385 :
case V_386 :
return F_291 ( V_14 , V_206 -> V_383 . V_22 ) ;
default:
return 0 ;
}
}
static int F_291 ( const struct V_13 * V_14 ,
const struct V_21 * V_22 )
{
const struct V_49 * V_50 ;
const struct V_203 * V_204 , * V_418 ;
struct V_56 * V_57 ;
struct V_322 * V_323 ;
struct V_314 V_315 ;
if ( V_14 -> V_22 == V_22 )
return - V_419 ;
F_10 (rule, &chain->rules, list) {
F_165 (expr, last, rule) {
const struct V_217 * V_206 = NULL ;
int V_43 ;
if ( ! V_204 -> V_38 -> V_216 )
continue;
V_43 = V_204 -> V_38 -> V_216 ( V_14 , V_204 , & V_206 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_206 == NULL )
continue;
switch ( V_206 -> V_383 . V_384 ) {
case V_385 :
case V_386 :
V_43 = F_291 ( V_14 ,
V_206 -> V_383 . V_22 ) ;
if ( V_43 < 0 )
return V_43 ;
default:
break;
}
}
}
F_10 (set, &ctx->table->sets, list) {
if ( ! F_38 ( V_14 -> V_1 , V_57 ) )
continue;
if ( ! ( V_57 -> V_36 & V_257 ) ||
V_57 -> V_281 != V_308 )
continue;
F_10 (binding, &set->bindings, list) {
if ( ! ( V_323 -> V_36 & V_257 ) ||
V_323 -> V_22 != V_22 )
continue;
V_315 . V_67 = F_97 ( V_14 -> V_1 ) ;
V_315 . V_325 = 0 ;
V_315 . V_326 = 0 ;
V_315 . V_43 = 0 ;
V_315 . V_327 = F_290 ;
V_57 -> V_38 -> V_328 ( V_14 , V_57 , & V_315 ) ;
if ( V_315 . V_43 < 0 )
return V_315 . V_43 ;
}
}
return 0 ;
}
int F_292 ( const struct V_23 * V_165 , int V_420 , T_1 * V_421 )
{
T_1 V_371 ;
V_371 = F_41 ( F_42 ( V_165 ) ) ;
if ( V_371 > V_420 )
return - V_422 ;
* V_421 = V_371 ;
return 0 ;
}
unsigned int F_293 ( const struct V_23 * V_165 )
{
unsigned int V_423 ;
V_423 = F_41 ( F_42 ( V_165 ) ) ;
switch ( V_423 ) {
case V_424 ... V_425 :
return V_423 * V_426 / V_427 ;
default:
return V_423 + V_426 / V_427 - V_428 ;
}
}
int F_294 ( struct V_15 * V_16 , unsigned int V_165 , unsigned int V_423 )
{
if ( V_423 % ( V_426 / V_427 ) == 0 )
V_423 = V_423 / ( V_426 / V_427 ) ;
else
V_423 = V_423 - V_426 / V_427 + V_428 ;
return F_65 ( V_16 , V_165 , F_66 ( V_423 ) ) ;
}
int F_295 ( enum V_320 V_423 , unsigned int V_99 )
{
if ( V_423 < V_429 * V_426 / V_427 )
return - V_69 ;
if ( V_99 == 0 )
return - V_69 ;
if ( V_423 * V_427 + V_99 > F_296 ( struct V_430 , V_206 ) )
return - V_422 ;
return 0 ;
}
int F_210 ( const struct V_13 * V_14 ,
enum V_320 V_423 ,
const struct V_217 * V_206 ,
enum V_382 type , unsigned int V_99 )
{
int V_43 ;
switch ( V_423 ) {
case V_424 :
if ( type != V_308 )
return - V_69 ;
if ( V_206 != NULL &&
( V_206 -> V_383 . V_384 == V_386 ||
V_206 -> V_383 . V_384 == V_385 ) ) {
V_43 = F_291 ( V_14 , V_206 -> V_383 . V_22 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_14 -> V_22 -> V_431 + 1 >
V_206 -> V_383 . V_22 -> V_431 ) {
if ( V_14 -> V_22 -> V_431 + 1 == V_432 )
return - V_433 ;
V_206 -> V_383 . V_22 -> V_431 = V_14 -> V_22 -> V_431 + 1 ;
}
}
return 0 ;
default:
if ( V_423 < V_429 * V_426 / V_427 )
return - V_69 ;
if ( V_99 == 0 )
return - V_69 ;
if ( V_423 * V_427 + V_99 >
F_296 ( struct V_430 , V_206 ) )
return - V_422 ;
if ( V_206 != NULL && type != V_303 )
return - V_69 ;
return 0 ;
}
}
static int F_297 ( const struct V_13 * V_14 , struct V_217 * V_206 ,
struct V_366 * V_248 , const struct V_23 * V_24 )
{
T_3 V_67 = F_97 ( V_14 -> V_1 ) ;
struct V_23 * V_166 [ V_434 + 1 ] ;
struct V_21 * V_22 ;
int V_43 ;
V_43 = F_126 ( V_166 , V_434 , V_24 , V_435 ,
NULL ) ;
if ( V_43 < 0 )
return V_43 ;
if ( ! V_166 [ V_436 ] )
return - V_69 ;
V_206 -> V_383 . V_384 = F_41 ( F_42 ( V_166 [ V_436 ] ) ) ;
switch ( V_206 -> V_383 . V_384 ) {
default:
switch ( V_206 -> V_383 . V_384 & V_437 ) {
case V_187 :
case V_189 :
case V_438 :
break;
default:
return - V_69 ;
}
case V_439 :
case V_440 :
case V_441 :
break;
case V_385 :
case V_386 :
if ( ! V_166 [ V_442 ] )
return - V_69 ;
V_22 = F_111 ( V_14 -> V_20 ,
V_166 [ V_442 ] , V_67 ) ;
if ( F_86 ( V_22 ) )
return F_87 ( V_22 ) ;
if ( F_25 ( V_22 ) )
return - V_114 ;
V_22 -> V_48 ++ ;
V_206 -> V_383 . V_22 = V_22 ;
break;
}
V_248 -> V_99 = sizeof( V_206 -> V_383 ) ;
V_248 -> type = V_308 ;
return 0 ;
}
static void F_298 ( const struct V_217 * V_206 )
{
switch ( V_206 -> V_383 . V_384 ) {
case V_385 :
case V_386 :
V_206 -> V_383 . V_22 -> V_48 -- ;
break;
}
}
int F_299 ( struct V_15 * V_16 , int type , const struct V_309 * V_443 )
{
struct V_23 * V_138 ;
V_138 = F_117 ( V_16 , type ) ;
if ( ! V_138 )
goto V_78;
if ( F_65 ( V_16 , V_436 , F_66 ( V_443 -> V_384 ) ) )
goto V_78;
switch ( V_443 -> V_384 ) {
case V_385 :
case V_386 :
if ( F_64 ( V_16 , V_442 ,
V_443 -> V_22 -> V_68 ) )
goto V_78;
}
F_120 ( V_16 , V_138 ) ;
return 0 ;
V_78:
return - 1 ;
}
static int F_300 ( const struct V_13 * V_14 ,
struct V_217 * V_206 , unsigned int V_31 ,
struct V_366 * V_248 , const struct V_23 * V_24 )
{
unsigned int V_99 ;
V_99 = F_57 ( V_24 ) ;
if ( V_99 == 0 )
return - V_69 ;
if ( V_99 > V_31 )
return - V_193 ;
F_178 ( V_206 -> V_206 , V_24 , V_99 ) ;
V_248 -> type = V_303 ;
V_248 -> V_99 = V_99 ;
return 0 ;
}
static int F_301 ( struct V_15 * V_16 , const struct V_217 * V_206 ,
unsigned int V_99 )
{
return F_166 ( V_16 , V_444 , V_99 , V_206 -> V_206 ) ;
}
int F_245 ( const struct V_13 * V_14 ,
struct V_217 * V_206 , unsigned int V_31 ,
struct V_366 * V_248 , const struct V_23 * V_24 )
{
struct V_23 * V_166 [ V_445 + 1 ] ;
int V_43 ;
V_43 = F_126 ( V_166 , V_445 , V_24 , V_446 , NULL ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_166 [ V_444 ] )
return F_300 ( V_14 , V_206 , V_31 , V_248 ,
V_166 [ V_444 ] ) ;
if ( V_166 [ V_447 ] && V_14 != NULL )
return F_297 ( V_14 , V_206 , V_248 , V_166 [ V_447 ] ) ;
return - V_69 ;
}
void F_239 ( const struct V_217 * V_206 , enum V_382 type )
{
if ( type < V_308 )
return;
switch ( type ) {
case V_308 :
return F_298 ( V_206 ) ;
default:
F_302 ( 1 ) ;
}
}
int F_217 ( struct V_15 * V_16 , int V_165 , const struct V_217 * V_206 ,
enum V_382 type , unsigned int V_99 )
{
struct V_23 * V_138 ;
int V_43 ;
V_138 = F_117 ( V_16 , V_165 ) ;
if ( V_138 == NULL )
return - 1 ;
switch ( type ) {
case V_303 :
V_43 = F_301 ( V_16 , V_206 , V_99 ) ;
break;
case V_308 :
V_43 = F_299 ( V_16 , V_447 , & V_206 -> V_383 ) ;
break;
default:
V_43 = - V_69 ;
F_302 ( 1 ) ;
}
F_120 ( V_16 , V_138 ) ;
return V_43 ;
}
static int T_8 F_303 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_7 . V_8 ) ;
F_2 ( & V_1 -> V_7 . V_42 ) ;
V_1 -> V_7 . V_83 = 1 ;
return 0 ;
}
int F_304 ( struct V_13 * V_14 )
{
struct V_49 * V_50 , * V_448 ;
F_107 ( ! F_25 ( V_14 -> V_22 ) ) ;
F_28 ( V_14 -> V_1 , V_14 -> V_22 -> V_20 , V_14 -> V_22 ,
V_14 -> V_3 -> V_109 ) ;
F_102 (rule, nr, &ctx->chain->rules, list) {
F_22 ( & V_50 -> V_6 ) ;
V_14 -> V_22 -> V_48 -- ;
F_171 ( V_14 , V_50 ) ;
}
F_22 ( & V_14 -> V_22 -> V_6 ) ;
V_14 -> V_20 -> V_48 -- ;
F_138 ( V_14 -> V_22 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_19 * V_20 , * V_129 ;
struct V_21 * V_22 , * V_123 ;
struct V_62 * V_63 , * V_124 ;
struct V_49 * V_50 , * V_448 ;
struct V_56 * V_57 , * V_125 ;
struct V_13 V_14 = {
. V_1 = V_1 ,
. V_3 = V_3 ,
} ;
F_102 (table, nt, &afi->tables, list) {
F_10 (chain, &table->chains, list)
F_28 ( V_1 , V_20 , V_22 ,
V_3 -> V_109 ) ;
V_14 . V_20 = V_20 ;
F_10 (chain, &table->chains, list) {
V_14 . V_22 = V_22 ;
F_102 (rule, nr, &chain->rules, list) {
F_22 ( & V_50 -> V_6 ) ;
V_22 -> V_48 -- ;
F_171 ( & V_14 , V_50 ) ;
}
}
F_102 (set, ns, &table->sets, list) {
F_22 ( & V_57 -> V_6 ) ;
V_20 -> V_48 -- ;
F_204 ( V_57 ) ;
}
F_102 (obj, ne, &table->objects, list) {
F_22 ( & V_63 -> V_6 ) ;
V_20 -> V_48 -- ;
F_271 ( V_63 ) ;
}
F_102 (chain, nc, &table->chains, list) {
F_22 ( & V_22 -> V_6 ) ;
V_20 -> V_48 -- ;
F_138 ( V_22 ) ;
}
F_22 ( & V_20 -> V_6 ) ;
F_106 ( & V_14 ) ;
}
}
static int T_9 F_305 ( void )
{
int V_43 ;
V_209 = F_200 ( sizeof( struct V_208 ) * V_241 ,
V_34 ) ;
if ( V_209 == NULL ) {
V_43 = - V_40 ;
goto V_116;
}
V_43 = F_306 () ;
if ( V_43 < 0 )
goto V_117;
V_43 = F_307 ( & V_449 ) ;
if ( V_43 < 0 )
goto V_122;
F_308 ( L_7 ) ;
return F_309 ( & V_450 ) ;
V_122:
F_310 () ;
V_117:
F_23 ( V_209 ) ;
V_116:
return V_43 ;
}
static void T_10 F_311 ( void )
{
F_312 ( & V_450 ) ;
F_313 ( & V_449 ) ;
F_314 () ;
F_310 () ;
F_23 ( V_209 ) ;
}
