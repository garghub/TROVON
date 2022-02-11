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
if ( V_30 == V_54 && V_14 -> V_24 [ V_55 ] != NULL ) {
F_39 ( V_33 ) =
F_40 ( F_41 ( V_14 -> V_24 [ V_55 ] ) ) ;
}
V_53 ( V_33 ) = V_51 ;
F_31 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_43 ) ;
return V_33 ;
}
static int F_42 ( struct V_13 * V_14 , struct V_50 * V_51 )
{
struct V_29 * V_33 ;
int V_44 ;
V_33 = F_38 ( V_14 , V_56 , V_51 ) ;
if ( V_33 == NULL )
return - V_41 ;
V_44 = F_36 ( V_14 , V_51 ) ;
if ( V_44 < 0 ) {
F_21 ( V_33 ) ;
return V_44 ;
}
return 0 ;
}
static int F_43 ( struct V_13 * V_14 )
{
struct V_50 * V_51 ;
int V_44 ;
F_10 (rule, &ctx->chain->rules, list) {
V_44 = F_42 ( V_14 , V_51 ) ;
if ( V_44 < 0 )
return V_44 ;
}
return 0 ;
}
static int F_44 ( struct V_13 * V_14 , int V_30 ,
struct V_57 * V_58 )
{
struct V_29 * V_33 ;
V_33 = F_20 ( V_14 , V_30 , sizeof( struct V_59 ) ) ;
if ( V_33 == NULL )
return - V_41 ;
if ( V_30 == V_60 && V_14 -> V_24 [ V_61 ] != NULL ) {
F_45 ( V_33 ) =
F_40 ( F_41 ( V_14 -> V_24 [ V_61 ] ) ) ;
F_30 ( V_14 -> V_1 , V_58 ) ;
}
V_59 ( V_33 ) = V_58 ;
F_31 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_43 ) ;
return 0 ;
}
static int F_46 ( struct V_13 * V_14 , struct V_57 * V_58 )
{
int V_44 ;
V_44 = F_44 ( V_14 , V_62 , V_58 ) ;
if ( V_44 < 0 )
return V_44 ;
F_33 ( V_14 -> V_1 , V_58 ) ;
V_14 -> V_20 -> V_49 -- ;
return V_44 ;
}
static int F_47 ( struct V_13 * V_14 , int V_30 ,
struct V_63 * V_64 )
{
struct V_29 * V_33 ;
V_33 = F_20 ( V_14 , V_30 , sizeof( struct V_65 ) ) ;
if ( V_33 == NULL )
return - V_41 ;
if ( V_30 == V_66 )
F_30 ( V_14 -> V_1 , V_64 ) ;
V_65 ( V_33 ) = V_64 ;
F_31 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_43 ) ;
return 0 ;
}
static int F_48 ( struct V_13 * V_14 , struct V_63 * V_64 )
{
int V_44 ;
V_44 = F_47 ( V_14 , V_67 , V_64 ) ;
if ( V_44 < 0 )
return V_44 ;
F_33 ( V_14 -> V_1 , V_64 ) ;
V_14 -> V_20 -> V_49 -- ;
return V_44 ;
}
static struct V_19 * F_49 ( const struct V_2 * V_3 ,
const struct V_23 * V_24 ,
T_3 V_68 )
{
struct V_19 * V_20 ;
F_10 (table, &afi->tables, list) {
if ( ! F_50 ( V_24 , V_20 -> V_69 ) &&
F_51 ( V_20 , V_68 ) )
return V_20 ;
}
return NULL ;
}
static struct V_19 * F_52 ( const struct V_2 * V_3 ,
const struct V_23 * V_24 ,
T_3 V_68 )
{
struct V_19 * V_20 ;
if ( V_24 == NULL )
return F_14 ( - V_70 ) ;
V_20 = F_49 ( V_3 , V_24 , V_68 ) ;
if ( V_20 != NULL )
return V_20 ;
return F_14 ( - V_52 ) ;
}
static inline T_4 F_53 ( struct V_19 * V_20 )
{
return ++ V_20 -> V_71 ;
}
static const struct V_72 *
F_54 ( int V_9 , const struct V_23 * V_24 )
{
int V_73 ;
for ( V_73 = 0 ; V_73 < V_74 ; V_73 ++ ) {
if ( V_75 [ V_9 ] [ V_73 ] != NULL &&
! F_50 ( V_24 , V_75 [ V_9 ] [ V_73 ] -> V_69 ) )
return V_75 [ V_9 ] [ V_73 ] ;
}
return NULL ;
}
static const struct V_72 *
F_55 ( const struct V_2 * V_3 ,
const struct V_23 * V_24 ,
bool V_10 )
{
const struct V_72 * type ;
type = F_54 ( V_3 -> V_9 , V_24 ) ;
if ( type != NULL )
return type ;
#ifdef F_12
if ( V_10 ) {
F_5 ( V_5 ) ;
F_13 ( L_2 , V_3 -> V_9 ,
F_56 ( V_24 ) , ( const char * ) F_57 ( V_24 ) ) ;
F_3 ( V_5 ) ;
type = F_54 ( V_3 -> V_9 , V_24 ) ;
if ( type != NULL )
return F_14 ( - V_11 ) ;
}
#endif
return F_14 ( - V_52 ) ;
}
static int F_58 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_25 , T_1 V_27 , int V_76 , T_1 V_36 ,
int V_9 , const struct V_19 * V_20 )
{
struct V_17 * V_18 ;
struct V_77 * V_78 ;
V_76 |= V_5 << 8 ;
V_18 = F_59 ( V_16 , V_25 , V_27 , V_76 , sizeof( struct V_77 ) , V_36 ) ;
if ( V_18 == NULL )
goto V_79;
V_78 = F_60 ( V_18 ) ;
V_78 -> V_80 = V_9 ;
V_78 -> V_81 = V_82 ;
V_78 -> V_83 = F_61 ( V_1 -> V_7 . V_84 & 0xffff ) ;
if ( F_62 ( V_16 , V_85 , V_20 -> V_69 ) ||
F_63 ( V_16 , V_86 , F_64 ( V_20 -> V_36 ) ) ||
F_63 ( V_16 , V_87 , F_64 ( V_20 -> V_49 ) ) )
goto V_79;
F_65 ( V_16 , V_18 ) ;
return 0 ;
V_79:
F_66 ( V_16 , V_18 ) ;
return - 1 ;
}
static void F_67 ( const struct V_13 * V_14 , int V_76 )
{
struct V_15 * V_16 ;
int V_44 ;
if ( ! V_14 -> V_26 &&
! F_68 ( V_14 -> V_1 , V_88 ) )
return;
V_16 = F_69 ( V_89 , V_34 ) ;
if ( V_16 == NULL )
goto V_44;
V_44 = F_58 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_14 -> V_27 ,
V_76 , 0 , V_14 -> V_3 -> V_9 , V_14 -> V_20 ) ;
if ( V_44 < 0 ) {
F_70 ( V_16 ) ;
goto V_44;
}
F_71 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_88 ,
V_14 -> V_26 , V_34 ) ;
return;
V_44:
F_72 ( V_14 -> V_1 , V_14 -> V_25 , V_88 , - V_90 ) ;
}
static int F_73 ( struct V_15 * V_16 ,
struct V_91 * V_92 )
{
const struct V_77 * V_78 = F_60 ( V_92 -> V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
unsigned int V_93 = 0 , V_94 = V_92 -> args [ 0 ] ;
struct V_1 * V_1 = F_74 ( V_16 -> V_95 ) ;
int V_9 = V_78 -> V_80 ;
F_75 () ;
V_92 -> V_27 = V_1 -> V_7 . V_84 ;
F_76 (afi, &net->nft.af_info, list) {
if ( V_9 != V_96 && V_9 != V_3 -> V_9 )
continue;
F_76 (table, &afi->tables, list) {
if ( V_93 < V_94 )
goto V_97;
if ( V_93 > V_94 )
memset ( & V_92 -> args [ 1 ] , 0 ,
sizeof( V_92 -> args ) - sizeof( V_92 -> args [ 0 ] ) ) ;
if ( ! F_77 ( V_1 , V_20 ) )
continue;
if ( F_58 ( V_16 , V_1 ,
F_16 ( V_92 -> V_16 ) . V_25 ,
V_92 -> V_18 -> V_28 ,
V_42 ,
V_98 ,
V_3 -> V_9 , V_20 ) < 0 )
goto V_99;
F_78 ( V_92 , F_79 ( V_16 ) ) ;
V_97:
V_93 ++ ;
}
}
V_99:
F_80 () ;
V_92 -> args [ 0 ] = V_93 ;
return V_16 -> V_100 ;
}
static int F_81 ( struct V_1 * V_1 , struct V_101 * V_102 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_77 * V_78 = F_60 ( V_18 ) ;
T_3 V_68 = F_82 ( V_1 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
struct V_15 * V_103 ;
int V_9 = V_78 -> V_80 ;
int V_44 ;
if ( V_18 -> V_104 & V_105 ) {
struct V_106 V_107 = {
. V_108 = F_73 ,
} ;
return F_83 ( V_102 , V_16 , V_18 , & V_107 ) ;
}
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_84 ( V_3 ) )
return F_85 ( V_3 ) ;
V_20 = F_52 ( V_3 , V_24 [ V_85 ] , V_68 ) ;
if ( F_84 ( V_20 ) )
return F_85 ( V_20 ) ;
V_103 = F_86 ( V_89 , V_34 ) ;
if ( ! V_103 )
return - V_41 ;
V_44 = F_58 ( V_103 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 , V_42 , 0 ,
V_9 , V_20 ) ;
if ( V_44 < 0 )
goto V_44;
return F_87 ( V_102 , V_103 , F_16 ( V_16 ) . V_25 ) ;
V_44:
F_70 ( V_103 ) ;
return V_44 ;
}
static void F_88 ( struct V_1 * V_1 ,
const struct V_2 * V_3 ,
struct V_19 * V_20 ,
T_1 V_109 )
{
struct V_21 * V_22 ;
T_1 V_73 = 0 ;
F_10 (chain, &table->chains, list) {
if ( ! F_37 ( V_1 , V_22 ) )
continue;
if ( ! ( V_22 -> V_36 & V_38 ) )
continue;
if ( V_109 && V_73 ++ == V_109 )
break;
F_28 ( V_1 , F_26 ( V_22 ) -> V_39 ,
V_3 -> V_110 ) ;
}
}
static int F_89 ( struct V_1 * V_1 ,
const struct V_2 * V_3 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 ;
int V_44 , V_73 = 0 ;
F_10 (chain, &table->chains, list) {
if ( ! F_37 ( V_1 , V_22 ) )
continue;
if ( ! ( V_22 -> V_36 & V_38 ) )
continue;
V_44 = F_25 ( V_1 , F_26 ( V_22 ) -> V_39 ,
V_3 -> V_110 ) ;
if ( V_44 < 0 )
goto V_44;
V_73 ++ ;
}
return 0 ;
V_44:
if ( V_73 )
F_88 ( V_1 , V_3 , V_20 , V_73 ) ;
return V_44 ;
}
static void F_90 ( struct V_1 * V_1 ,
const struct V_2 * V_3 ,
struct V_19 * V_20 )
{
F_88 ( V_1 , V_3 , V_20 , 0 ) ;
}
static int F_91 ( struct V_13 * V_14 )
{
struct V_29 * V_33 ;
T_1 V_36 ;
int V_111 = 0 ;
if ( ! V_14 -> V_24 [ V_86 ] )
return 0 ;
V_36 = F_40 ( F_41 ( V_14 -> V_24 [ V_86 ] ) ) ;
if ( V_36 & ~ V_37 )
return - V_70 ;
if ( V_36 == V_14 -> V_20 -> V_36 )
return 0 ;
V_33 = F_20 ( V_14 , V_42 ,
sizeof( struct V_40 ) ) ;
if ( V_33 == NULL )
return - V_41 ;
if ( ( V_36 & V_37 ) &&
! ( V_14 -> V_20 -> V_36 & V_37 ) ) {
F_92 ( V_33 ) = false ;
} else if ( ! ( V_36 & V_37 ) &&
V_14 -> V_20 -> V_36 & V_37 ) {
V_111 = F_89 ( V_14 -> V_1 , V_14 -> V_3 , V_14 -> V_20 ) ;
if ( V_111 >= 0 ) {
V_14 -> V_20 -> V_36 &= ~ V_37 ;
F_92 ( V_33 ) = true ;
}
}
if ( V_111 < 0 )
goto V_44;
F_93 ( V_33 ) = true ;
F_31 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_43 ) ;
return 0 ;
V_44:
F_21 ( V_33 ) ;
return V_111 ;
}
static int F_94 ( struct V_1 * V_1 , struct V_101 * V_102 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_77 * V_78 = F_60 ( V_18 ) ;
T_3 V_68 = F_95 ( V_1 ) ;
const struct V_23 * V_69 ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
int V_9 = V_78 -> V_80 ;
T_1 V_36 = 0 ;
struct V_13 V_14 ;
int V_44 ;
V_3 = F_11 ( V_1 , V_9 , true ) ;
if ( F_84 ( V_3 ) )
return F_85 ( V_3 ) ;
V_69 = V_24 [ V_85 ] ;
V_20 = F_52 ( V_3 , V_69 , V_68 ) ;
if ( F_84 ( V_20 ) ) {
if ( F_85 ( V_20 ) != - V_52 )
return F_85 ( V_20 ) ;
} else {
if ( V_18 -> V_104 & V_112 )
return - V_113 ;
if ( V_18 -> V_104 & V_114 )
return - V_115 ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return F_91 ( & V_14 ) ;
}
if ( V_24 [ V_86 ] ) {
V_36 = F_40 ( F_41 ( V_24 [ V_86 ] ) ) ;
if ( V_36 & ~ V_37 )
return - V_70 ;
}
V_44 = - V_12 ;
if ( ! F_96 ( V_3 -> V_116 ) )
goto V_117;
V_44 = - V_41 ;
V_20 = F_19 ( sizeof( * V_20 ) , V_34 ) ;
if ( V_20 == NULL )
goto V_118;
F_97 ( V_20 -> V_69 , V_69 , V_119 ) ;
F_2 ( & V_20 -> V_120 ) ;
F_2 ( & V_20 -> V_121 ) ;
F_2 ( & V_20 -> V_122 ) ;
V_20 -> V_36 = V_36 ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
V_44 = F_29 ( & V_14 , V_42 ) ;
if ( V_44 < 0 )
goto V_123;
F_4 ( & V_20 -> V_6 , & V_3 -> V_4 ) ;
return 0 ;
V_123:
F_23 ( V_20 ) ;
V_118:
F_98 ( V_3 -> V_116 ) ;
V_117:
return V_44 ;
}
static int F_99 ( struct V_13 * V_14 )
{
int V_44 ;
struct V_21 * V_22 , * V_124 ;
struct V_63 * V_64 , * V_125 ;
struct V_57 * V_58 , * V_126 ;
F_10 (chain, &ctx->table->chains, list) {
if ( ! F_37 ( V_14 -> V_1 , V_22 ) )
continue;
V_14 -> V_22 = V_22 ;
V_44 = F_43 ( V_14 ) ;
if ( V_44 < 0 )
goto V_127;
}
F_100 (set, ns, &ctx->table->sets, list) {
if ( ! F_37 ( V_14 -> V_1 , V_58 ) )
continue;
if ( V_58 -> V_36 & V_128 &&
! F_101 ( & V_58 -> V_129 ) )
continue;
V_44 = F_46 ( V_14 , V_58 ) ;
if ( V_44 < 0 )
goto V_127;
}
F_100 (obj, ne, &ctx->table->objects, list) {
V_44 = F_48 ( V_14 , V_64 ) ;
if ( V_44 < 0 )
goto V_127;
}
F_100 (chain, nc, &ctx->table->chains, list) {
if ( ! F_37 ( V_14 -> V_1 , V_22 ) )
continue;
V_14 -> V_22 = V_22 ;
V_44 = F_35 ( V_14 ) ;
if ( V_44 < 0 )
goto V_127;
}
V_44 = F_32 ( V_14 ) ;
V_127:
return V_44 ;
}
static int F_102 ( struct V_13 * V_14 , int V_9 )
{
struct V_2 * V_3 ;
struct V_19 * V_20 , * V_130 ;
const struct V_23 * const * V_24 = V_14 -> V_24 ;
int V_44 = 0 ;
F_10 (afi, &ctx->net->nft.af_info, list) {
if ( V_9 != V_131 && V_3 -> V_9 != V_9 )
continue;
V_14 -> V_3 = V_3 ;
F_100 (table, nt, &afi->tables, list) {
if ( ! F_37 ( V_14 -> V_1 , V_20 ) )
continue;
if ( V_24 [ V_85 ] &&
F_50 ( V_24 [ V_85 ] , V_20 -> V_69 ) != 0 )
continue;
V_14 -> V_20 = V_20 ;
V_44 = F_99 ( V_14 ) ;
if ( V_44 < 0 )
goto V_127;
}
}
V_127:
return V_44 ;
}
static int F_103 ( struct V_1 * V_1 , struct V_101 * V_102 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_77 * V_78 = F_60 ( V_18 ) ;
T_3 V_68 = F_95 ( V_1 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
int V_9 = V_78 -> V_80 ;
struct V_13 V_14 ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , NULL , NULL , NULL , V_24 ) ;
if ( V_9 == V_131 || V_24 [ V_85 ] == NULL )
return F_102 ( & V_14 , V_9 ) ;
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_84 ( V_3 ) )
return F_85 ( V_3 ) ;
V_20 = F_52 ( V_3 , V_24 [ V_85 ] , V_68 ) ;
if ( F_84 ( V_20 ) )
return F_85 ( V_20 ) ;
V_14 . V_3 = V_3 ;
V_14 . V_20 = V_20 ;
return F_99 ( & V_14 ) ;
}
static void F_104 ( struct V_13 * V_14 )
{
F_105 ( V_14 -> V_20 -> V_49 > 0 ) ;
F_23 ( V_14 -> V_20 ) ;
F_98 ( V_14 -> V_3 -> V_116 ) ;
}
int F_106 ( const struct V_72 * V_132 )
{
int V_44 = 0 ;
F_3 ( V_5 ) ;
if ( V_75 [ V_132 -> V_9 ] [ V_132 -> type ] != NULL ) {
V_44 = - V_133 ;
goto V_127;
}
V_75 [ V_132 -> V_9 ] [ V_132 -> type ] = V_132 ;
V_127:
F_5 ( V_5 ) ;
return V_44 ;
}
void F_107 ( const struct V_72 * V_132 )
{
F_3 ( V_5 ) ;
V_75 [ V_132 -> V_9 ] [ V_132 -> type ] = NULL ;
F_5 ( V_5 ) ;
}
static struct V_21 *
F_108 ( const struct V_19 * V_20 , T_4 V_134 ,
T_3 V_68 )
{
struct V_21 * V_22 ;
F_10 (chain, &table->chains, list) {
if ( V_22 -> V_134 == V_134 &&
F_51 ( V_22 , V_68 ) )
return V_22 ;
}
return F_14 ( - V_52 ) ;
}
static struct V_21 * F_109 ( const struct V_19 * V_20 ,
const struct V_23 * V_24 ,
T_3 V_68 )
{
struct V_21 * V_22 ;
if ( V_24 == NULL )
return F_14 ( - V_70 ) ;
F_10 (chain, &table->chains, list) {
if ( ! F_50 ( V_24 , V_22 -> V_69 ) &&
F_51 ( V_22 , V_68 ) )
return V_22 ;
}
return F_14 ( - V_52 ) ;
}
static int F_110 ( struct V_15 * V_16 , struct V_135 T_5 * V_136 )
{
struct V_135 * V_137 , V_138 ;
struct V_23 * V_139 ;
unsigned int V_27 ;
T_4 V_140 , V_141 ;
int V_142 ;
memset ( & V_138 , 0 , sizeof( V_138 ) ) ;
F_111 (cpu) {
V_137 = F_112 ( V_136 , V_142 ) ;
do {
V_27 = F_113 ( & V_137 -> V_143 ) ;
V_140 = V_137 -> V_140 ;
V_141 = V_137 -> V_141 ;
} while ( F_114 ( & V_137 -> V_143 , V_27 ) );
V_138 . V_140 += V_140 ;
V_138 . V_141 += V_141 ;
}
V_139 = F_115 ( V_16 , V_144 ) ;
if ( V_139 == NULL )
goto V_79;
if ( F_116 ( V_16 , V_145 , F_117 ( V_138 . V_140 ) ,
V_146 ) ||
F_116 ( V_16 , V_147 , F_117 ( V_138 . V_141 ) ,
V_146 ) )
goto V_79;
F_118 ( V_16 , V_139 ) ;
return 0 ;
V_79:
return - V_148 ;
}
static int F_119 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_25 , T_1 V_27 , int V_76 , T_1 V_36 ,
int V_9 , const struct V_19 * V_20 ,
const struct V_21 * V_22 )
{
struct V_17 * V_18 ;
struct V_77 * V_78 ;
V_76 |= V_5 << 8 ;
V_18 = F_59 ( V_16 , V_25 , V_27 , V_76 , sizeof( struct V_77 ) , V_36 ) ;
if ( V_18 == NULL )
goto V_79;
V_78 = F_60 ( V_18 ) ;
V_78 -> V_80 = V_9 ;
V_78 -> V_81 = V_82 ;
V_78 -> V_83 = F_61 ( V_1 -> V_7 . V_84 & 0xffff ) ;
if ( F_62 ( V_16 , V_149 , V_20 -> V_69 ) )
goto V_79;
if ( F_116 ( V_16 , V_150 , F_117 ( V_22 -> V_134 ) ,
V_151 ) )
goto V_79;
if ( F_62 ( V_16 , V_152 , V_22 -> V_69 ) )
goto V_79;
if ( V_22 -> V_36 & V_38 ) {
const struct F_26 * V_153 = F_26 ( V_22 ) ;
const struct V_154 * V_39 = & V_153 -> V_39 [ 0 ] ;
struct V_23 * V_139 ;
V_139 = F_115 ( V_16 , V_155 ) ;
if ( V_139 == NULL )
goto V_79;
if ( F_63 ( V_16 , V_156 , F_64 ( V_39 -> V_157 ) ) )
goto V_79;
if ( F_63 ( V_16 , V_158 , F_64 ( V_39 -> V_159 ) ) )
goto V_79;
if ( V_153 -> V_160 [ 0 ] &&
F_62 ( V_16 , V_161 , V_153 -> V_160 ) )
goto V_79;
F_118 ( V_16 , V_139 ) ;
if ( F_63 ( V_16 , V_162 ,
F_64 ( V_153 -> V_163 ) ) )
goto V_79;
if ( F_62 ( V_16 , V_164 , V_153 -> type -> V_69 ) )
goto V_79;
if ( F_110 ( V_16 , F_26 ( V_22 ) -> V_136 ) )
goto V_79;
}
if ( F_63 ( V_16 , V_165 , F_64 ( V_22 -> V_49 ) ) )
goto V_79;
F_65 ( V_16 , V_18 ) ;
return 0 ;
V_79:
F_66 ( V_16 , V_18 ) ;
return - 1 ;
}
static void F_120 ( const struct V_13 * V_14 , int V_76 )
{
struct V_15 * V_16 ;
int V_44 ;
if ( ! V_14 -> V_26 &&
! F_68 ( V_14 -> V_1 , V_88 ) )
return;
V_16 = F_69 ( V_89 , V_34 ) ;
if ( V_16 == NULL )
goto V_44;
V_44 = F_119 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_14 -> V_27 ,
V_76 , 0 , V_14 -> V_3 -> V_9 , V_14 -> V_20 ,
V_14 -> V_22 ) ;
if ( V_44 < 0 ) {
F_70 ( V_16 ) ;
goto V_44;
}
F_71 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_88 ,
V_14 -> V_26 , V_34 ) ;
return;
V_44:
F_72 ( V_14 -> V_1 , V_14 -> V_25 , V_88 , - V_90 ) ;
}
static int F_121 ( struct V_15 * V_16 ,
struct V_91 * V_92 )
{
const struct V_77 * V_78 = F_60 ( V_92 -> V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
unsigned int V_93 = 0 , V_94 = V_92 -> args [ 0 ] ;
struct V_1 * V_1 = F_74 ( V_16 -> V_95 ) ;
int V_9 = V_78 -> V_80 ;
F_75 () ;
V_92 -> V_27 = V_1 -> V_7 . V_84 ;
F_76 (afi, &net->nft.af_info, list) {
if ( V_9 != V_96 && V_9 != V_3 -> V_9 )
continue;
F_76 (table, &afi->tables, list) {
F_76 (chain, &table->chains, list) {
if ( V_93 < V_94 )
goto V_97;
if ( V_93 > V_94 )
memset ( & V_92 -> args [ 1 ] , 0 ,
sizeof( V_92 -> args ) - sizeof( V_92 -> args [ 0 ] ) ) ;
if ( ! F_77 ( V_1 , V_22 ) )
continue;
if ( F_119 ( V_16 , V_1 ,
F_16 ( V_92 -> V_16 ) . V_25 ,
V_92 -> V_18 -> V_28 ,
V_47 ,
V_98 ,
V_3 -> V_9 , V_20 , V_22 ) < 0 )
goto V_99;
F_78 ( V_92 , F_79 ( V_16 ) ) ;
V_97:
V_93 ++ ;
}
}
}
V_99:
F_80 () ;
V_92 -> args [ 0 ] = V_93 ;
return V_16 -> V_100 ;
}
static int F_122 ( struct V_1 * V_1 , struct V_101 * V_102 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_77 * V_78 = F_60 ( V_18 ) ;
T_3 V_68 = F_82 ( V_1 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
struct V_15 * V_103 ;
int V_9 = V_78 -> V_80 ;
int V_44 ;
if ( V_18 -> V_104 & V_105 ) {
struct V_106 V_107 = {
. V_108 = F_121 ,
} ;
return F_83 ( V_102 , V_16 , V_18 , & V_107 ) ;
}
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_84 ( V_3 ) )
return F_85 ( V_3 ) ;
V_20 = F_52 ( V_3 , V_24 [ V_149 ] , V_68 ) ;
if ( F_84 ( V_20 ) )
return F_85 ( V_20 ) ;
V_22 = F_109 ( V_20 , V_24 [ V_152 ] , V_68 ) ;
if ( F_84 ( V_22 ) )
return F_85 ( V_22 ) ;
V_103 = F_86 ( V_89 , V_34 ) ;
if ( ! V_103 )
return - V_41 ;
V_44 = F_119 ( V_103 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 , V_47 , 0 ,
V_9 , V_20 , V_22 ) ;
if ( V_44 < 0 )
goto V_44;
return F_87 ( V_102 , V_103 , F_16 ( V_16 ) . V_25 ) ;
V_44:
F_70 ( V_103 ) ;
return V_44 ;
}
static struct V_135 T_5 * F_123 ( const struct V_23 * V_166 )
{
struct V_23 * V_167 [ V_168 + 1 ] ;
struct V_135 T_5 * V_169 ;
struct V_135 * V_136 ;
int V_44 ;
V_44 = F_124 ( V_167 , V_168 , V_166 , V_170 ) ;
if ( V_44 < 0 )
return F_14 ( V_44 ) ;
if ( ! V_167 [ V_147 ] || ! V_167 [ V_145 ] )
return F_14 ( - V_70 ) ;
V_169 = F_125 ( struct V_135 ) ;
if ( V_169 == NULL )
return F_14 ( - V_41 ) ;
F_126 () ;
V_136 = F_127 ( V_169 ) ;
V_136 -> V_141 = F_128 ( F_129 ( V_167 [ V_147 ] ) ) ;
V_136 -> V_140 = F_128 ( F_129 ( V_167 [ V_145 ] ) ) ;
F_130 () ;
return V_169 ;
}
static void F_131 ( struct F_26 * V_22 ,
struct V_135 T_5 * V_169 )
{
if ( V_169 == NULL )
return;
if ( V_22 -> V_136 ) {
struct V_135 T_5 * V_171 =
F_132 ( V_22 -> V_136 ) ;
F_133 ( V_22 -> V_136 , V_169 ) ;
F_134 () ;
F_135 ( V_171 ) ;
} else
F_133 ( V_22 -> V_136 , V_169 ) ;
}
static void F_136 ( struct V_21 * V_22 )
{
F_105 ( V_22 -> V_49 > 0 ) ;
if ( V_22 -> V_36 & V_38 ) {
struct F_26 * V_153 = F_26 ( V_22 ) ;
F_98 ( V_153 -> type -> V_116 ) ;
F_135 ( V_153 -> V_136 ) ;
if ( V_153 -> V_39 [ 0 ] . V_172 != NULL )
F_137 ( V_153 -> V_39 [ 0 ] . V_172 ) ;
F_23 ( V_153 ) ;
} else {
F_23 ( V_22 ) ;
}
}
static int F_138 ( struct V_1 * V_1 ,
const struct V_23 * const V_24 [] ,
struct V_2 * V_3 ,
struct V_173 * V_174 , bool V_175 )
{
struct V_23 * V_176 [ V_177 + 1 ] ;
const struct V_72 * type ;
struct V_178 * V_172 ;
int V_44 ;
V_44 = F_124 ( V_176 , V_177 , V_24 [ V_155 ] ,
V_179 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_176 [ V_156 ] == NULL ||
V_176 [ V_158 ] == NULL )
return - V_70 ;
V_174 -> V_180 = F_40 ( F_41 ( V_176 [ V_156 ] ) ) ;
if ( V_174 -> V_180 >= V_3 -> V_181 )
return - V_70 ;
V_174 -> V_159 = F_40 ( F_41 ( V_176 [ V_158 ] ) ) ;
type = V_75 [ V_3 -> V_9 ] [ V_182 ] ;
if ( V_24 [ V_164 ] ) {
type = F_55 ( V_3 , V_24 [ V_164 ] ,
V_175 ) ;
if ( F_84 ( type ) )
return F_85 ( type ) ;
}
if ( ! ( type -> V_183 & ( 1 << V_174 -> V_180 ) ) )
return - V_115 ;
if ( ! F_96 ( type -> V_116 ) )
return - V_52 ;
V_174 -> type = type ;
V_174 -> V_172 = NULL ;
if ( V_3 -> V_36 & V_184 ) {
char V_185 [ V_186 ] ;
if ( ! V_176 [ V_161 ] ) {
F_98 ( type -> V_116 ) ;
return - V_115 ;
}
F_97 ( V_185 , V_176 [ V_161 ] , V_186 ) ;
V_172 = F_139 ( V_1 , V_185 ) ;
if ( ! V_172 ) {
F_98 ( type -> V_116 ) ;
return - V_52 ;
}
V_174 -> V_172 = V_172 ;
} else if ( V_176 [ V_161 ] ) {
F_98 ( type -> V_116 ) ;
return - V_115 ;
}
return 0 ;
}
static void F_140 ( struct V_173 * V_174 )
{
F_98 ( V_174 -> type -> V_116 ) ;
if ( V_174 -> V_172 != NULL )
F_137 ( V_174 -> V_172 ) ;
}
static int F_141 ( struct V_1 * V_1 , struct V_101 * V_102 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_77 * V_78 = F_60 ( V_18 ) ;
const struct V_23 * V_187 ( V_69 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct F_26 * V_153 = NULL ;
T_3 V_68 = F_95 ( V_1 ) ;
int V_9 = V_78 -> V_80 ;
T_3 V_163 = V_188 ;
T_4 V_134 = 0 ;
unsigned int V_73 ;
struct V_135 T_5 * V_136 ;
int V_44 ;
bool V_175 ;
struct V_13 V_14 ;
V_175 = V_18 -> V_104 & V_189 ? true : false ;
V_3 = F_11 ( V_1 , V_9 , true ) ;
if ( F_84 ( V_3 ) )
return F_85 ( V_3 ) ;
V_20 = F_52 ( V_3 , V_24 [ V_149 ] , V_68 ) ;
if ( F_84 ( V_20 ) )
return F_85 ( V_20 ) ;
V_22 = NULL ;
V_69 = V_24 [ V_152 ] ;
if ( V_24 [ V_150 ] ) {
V_134 = F_128 ( F_129 ( V_24 [ V_150 ] ) ) ;
V_22 = F_108 ( V_20 , V_134 , V_68 ) ;
if ( F_84 ( V_22 ) )
return F_85 ( V_22 ) ;
} else {
V_22 = F_109 ( V_20 , V_69 , V_68 ) ;
if ( F_84 ( V_22 ) ) {
if ( F_85 ( V_22 ) != - V_52 )
return F_85 ( V_22 ) ;
V_22 = NULL ;
}
}
if ( V_24 [ V_162 ] ) {
if ( ( V_22 != NULL &&
! ( V_22 -> V_36 & V_38 ) ) )
return - V_115 ;
if ( V_22 == NULL &&
V_24 [ V_155 ] == NULL )
return - V_115 ;
V_163 = F_40 ( F_41 ( V_24 [ V_162 ] ) ) ;
switch ( V_163 ) {
case V_190 :
case V_188 :
break;
default:
return - V_70 ;
}
}
if ( V_22 != NULL ) {
struct V_135 * V_136 = NULL ;
struct V_29 * V_33 ;
if ( V_18 -> V_104 & V_112 )
return - V_113 ;
if ( V_18 -> V_104 & V_114 )
return - V_115 ;
if ( V_24 [ V_155 ] ) {
struct F_26 * V_153 ;
struct V_173 V_174 ;
struct V_154 * V_39 ;
if ( ! ( V_22 -> V_36 & V_38 ) )
return - V_133 ;
V_44 = F_138 ( V_1 , V_24 , V_3 , & V_174 ,
V_175 ) ;
if ( V_44 < 0 )
return V_44 ;
V_153 = F_26 ( V_22 ) ;
if ( V_153 -> type != V_174 . type ) {
F_140 ( & V_174 ) ;
return - V_133 ;
}
for ( V_73 = 0 ; V_73 < V_3 -> V_110 ; V_73 ++ ) {
V_39 = & V_153 -> V_39 [ V_73 ] ;
if ( V_39 -> V_157 != V_174 . V_180 ||
V_39 -> V_159 != V_174 . V_159 ||
V_39 -> V_172 != V_174 . V_172 ) {
F_140 ( & V_174 ) ;
return - V_133 ;
}
}
F_140 ( & V_174 ) ;
}
if ( V_24 [ V_150 ] && V_69 ) {
struct V_21 * V_191 ;
V_191 = F_109 ( V_20 ,
V_24 [ V_152 ] ,
V_68 ) ;
if ( F_84 ( V_191 ) )
return F_85 ( V_191 ) ;
}
if ( V_24 [ V_144 ] ) {
if ( ! ( V_22 -> V_36 & V_38 ) )
return - V_115 ;
V_136 = F_123 ( V_24 [ V_144 ] ) ;
if ( F_84 ( V_136 ) )
return F_85 ( V_136 ) ;
}
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_33 = F_20 ( & V_14 , V_47 ,
sizeof( struct V_46 ) ) ;
if ( V_33 == NULL ) {
F_135 ( V_136 ) ;
return - V_41 ;
}
F_142 ( V_33 ) = V_136 ;
F_143 ( V_33 ) = true ;
if ( V_24 [ V_162 ] )
F_144 ( V_33 ) = V_163 ;
else
F_144 ( V_33 ) = - 1 ;
if ( V_24 [ V_150 ] && V_69 ) {
F_97 ( F_145 ( V_33 ) , V_69 ,
V_192 ) ;
}
F_31 ( & V_33 -> V_6 , & V_1 -> V_7 . V_43 ) ;
return 0 ;
}
if ( V_20 -> V_49 == V_193 )
return - V_194 ;
if ( V_24 [ V_155 ] ) {
struct V_173 V_174 ;
struct V_154 * V_39 ;
T_6 * V_195 ;
V_44 = F_138 ( V_1 , V_24 , V_3 , & V_174 , V_175 ) ;
if ( V_44 < 0 )
return V_44 ;
V_153 = F_19 ( sizeof( * V_153 ) , V_34 ) ;
if ( V_153 == NULL ) {
F_140 ( & V_174 ) ;
return - V_41 ;
}
if ( V_174 . V_172 != NULL )
strncpy ( V_153 -> V_160 , V_174 . V_172 -> V_69 , V_186 ) ;
if ( V_24 [ V_144 ] ) {
V_136 = F_123 ( V_24 [ V_144 ] ) ;
if ( F_84 ( V_136 ) ) {
F_140 ( & V_174 ) ;
F_23 ( V_153 ) ;
return F_85 ( V_136 ) ;
}
V_153 -> V_136 = V_136 ;
} else {
V_136 = F_125 ( struct V_135 ) ;
if ( V_136 == NULL ) {
F_140 ( & V_174 ) ;
F_23 ( V_153 ) ;
return - V_41 ;
}
F_133 ( V_153 -> V_136 , V_136 ) ;
}
V_195 = V_174 . type -> V_196 [ V_174 . V_180 ] ;
V_153 -> type = V_174 . type ;
V_22 = & V_153 -> V_22 ;
for ( V_73 = 0 ; V_73 < V_3 -> V_110 ; V_73 ++ ) {
V_39 = & V_153 -> V_39 [ V_73 ] ;
V_39 -> V_197 = V_9 ;
V_39 -> V_157 = V_174 . V_180 ;
V_39 -> V_159 = V_174 . V_159 ;
V_39 -> V_198 = V_22 ;
V_39 -> V_174 = V_3 -> V_196 [ V_39 -> V_157 ] ;
V_39 -> V_172 = V_174 . V_172 ;
if ( V_195 )
V_39 -> V_174 = V_195 ;
if ( V_3 -> V_199 )
V_3 -> V_199 ( V_39 , V_73 ) ;
}
V_22 -> V_36 |= V_38 ;
V_153 -> V_163 = V_163 ;
} else {
V_22 = F_19 ( sizeof( * V_22 ) , V_34 ) ;
if ( V_22 == NULL )
return - V_41 ;
}
F_2 ( & V_22 -> V_200 ) ;
V_22 -> V_134 = F_53 ( V_20 ) ;
V_22 -> V_20 = V_20 ;
F_97 ( V_22 -> V_69 , V_69 , V_192 ) ;
V_44 = F_24 ( V_1 , V_20 , V_22 , V_3 -> V_110 ) ;
if ( V_44 < 0 )
goto V_117;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_44 = F_34 ( & V_14 , V_47 ) ;
if ( V_44 < 0 )
goto V_118;
V_20 -> V_49 ++ ;
F_4 ( & V_22 -> V_6 , & V_20 -> V_120 ) ;
return 0 ;
V_118:
F_27 ( V_1 , V_20 , V_22 , V_3 -> V_110 ) ;
V_117:
F_136 ( V_22 ) ;
return V_44 ;
}
static int F_146 ( struct V_1 * V_1 , struct V_101 * V_102 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_77 * V_78 = F_60 ( V_18 ) ;
T_3 V_68 = F_95 ( V_1 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
int V_9 = V_78 -> V_80 ;
struct V_13 V_14 ;
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_84 ( V_3 ) )
return F_85 ( V_3 ) ;
V_20 = F_52 ( V_3 , V_24 [ V_149 ] , V_68 ) ;
if ( F_84 ( V_20 ) )
return F_85 ( V_20 ) ;
V_22 = F_109 ( V_20 , V_24 [ V_152 ] , V_68 ) ;
if ( F_84 ( V_22 ) )
return F_85 ( V_22 ) ;
if ( V_22 -> V_49 > 0 )
return - V_133 ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
return F_35 ( & V_14 ) ;
}
int F_147 ( struct V_201 * type )
{
F_3 ( V_5 ) ;
if ( type -> V_9 == V_96 )
F_4 ( & type -> V_6 , & V_202 ) ;
else
F_148 ( & type -> V_6 , & V_202 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_149 ( struct V_201 * type )
{
F_3 ( V_5 ) ;
F_8 ( & type -> V_6 ) ;
F_5 ( V_5 ) ;
}
static const struct V_201 * F_150 ( T_3 V_9 ,
struct V_23 * V_24 )
{
const struct V_201 * type ;
F_10 (type, &nf_tables_expressions, list) {
if ( ! F_50 ( V_24 , type -> V_69 ) &&
( ! type -> V_9 || type -> V_9 == V_9 ) )
return type ;
}
return NULL ;
}
static const struct V_201 * F_151 ( T_3 V_9 ,
struct V_23 * V_24 )
{
const struct V_201 * type ;
if ( V_24 == NULL )
return F_14 ( - V_70 ) ;
type = F_150 ( V_9 , V_24 ) ;
if ( type != NULL && F_96 ( type -> V_116 ) )
return type ;
#ifdef F_12
if ( type == NULL ) {
F_5 ( V_5 ) ;
F_13 ( L_3 , V_9 ,
F_56 ( V_24 ) , ( char * ) F_57 ( V_24 ) ) ;
F_3 ( V_5 ) ;
if ( F_150 ( V_9 , V_24 ) )
return F_14 ( - V_11 ) ;
F_5 ( V_5 ) ;
F_13 ( L_4 ,
F_56 ( V_24 ) , ( char * ) F_57 ( V_24 ) ) ;
F_3 ( V_5 ) ;
if ( F_150 ( V_9 , V_24 ) )
return F_14 ( - V_11 ) ;
}
#endif
return F_14 ( - V_52 ) ;
}
static int F_152 ( struct V_15 * V_16 ,
const struct V_203 * V_204 )
{
if ( F_62 ( V_16 , V_205 , V_204 -> V_39 -> type -> V_69 ) )
goto V_79;
if ( V_204 -> V_39 -> V_108 ) {
struct V_23 * V_206 = F_115 ( V_16 , V_207 ) ;
if ( V_206 == NULL )
goto V_79;
if ( V_204 -> V_39 -> V_108 ( V_16 , V_204 ) < 0 )
goto V_79;
F_118 ( V_16 , V_206 ) ;
}
return V_16 -> V_100 ;
V_79:
return - 1 ;
}
int F_153 ( struct V_15 * V_16 , unsigned int V_166 ,
const struct V_203 * V_204 )
{
struct V_23 * V_139 ;
V_139 = F_115 ( V_16 , V_166 ) ;
if ( ! V_139 )
goto V_79;
if ( F_152 ( V_16 , V_204 ) < 0 )
goto V_79;
F_118 ( V_16 , V_139 ) ;
return 0 ;
V_79:
return - 1 ;
}
static int F_154 ( const struct V_13 * V_14 ,
const struct V_23 * V_24 ,
struct V_208 * V_209 )
{
const struct V_201 * type ;
const struct V_210 * V_39 ;
struct V_23 * V_167 [ V_211 + 1 ] ;
int V_44 ;
V_44 = F_124 ( V_167 , V_211 , V_24 , V_212 ) ;
if ( V_44 < 0 )
return V_44 ;
type = F_151 ( V_14 -> V_3 -> V_9 , V_167 [ V_205 ] ) ;
if ( F_84 ( type ) )
return F_85 ( type ) ;
if ( V_167 [ V_207 ] ) {
V_44 = F_124 ( V_209 -> V_167 , type -> V_213 ,
V_167 [ V_207 ] , type -> V_163 ) ;
if ( V_44 < 0 )
goto V_117;
} else
memset ( V_209 -> V_167 , 0 , sizeof( V_209 -> V_167 [ 0 ] ) * ( type -> V_213 + 1 ) ) ;
if ( type -> V_214 != NULL ) {
V_39 = type -> V_214 ( V_14 ,
( const struct V_23 * const * ) V_209 -> V_167 ) ;
if ( F_84 ( V_39 ) ) {
V_44 = F_85 ( V_39 ) ;
goto V_117;
}
} else
V_39 = type -> V_39 ;
V_209 -> V_39 = V_39 ;
return 0 ;
V_117:
F_98 ( type -> V_116 ) ;
return V_44 ;
}
static int F_155 ( const struct V_13 * V_14 ,
const struct V_208 * V_209 ,
struct V_203 * V_204 )
{
const struct V_210 * V_39 = V_209 -> V_39 ;
int V_44 ;
V_204 -> V_39 = V_39 ;
if ( V_39 -> V_215 ) {
V_44 = V_39 -> V_215 ( V_14 , V_204 , ( const struct V_23 * * ) V_209 -> V_167 ) ;
if ( V_44 < 0 )
goto V_117;
}
return 0 ;
V_117:
V_204 -> V_39 = NULL ;
return V_44 ;
}
static void F_156 ( const struct V_13 * V_14 ,
struct V_203 * V_204 )
{
if ( V_204 -> V_39 -> V_216 )
V_204 -> V_39 -> V_216 ( V_14 , V_204 ) ;
F_98 ( V_204 -> V_39 -> type -> V_116 ) ;
}
struct V_203 * F_157 ( const struct V_13 * V_14 ,
const struct V_23 * V_24 )
{
struct V_208 V_209 ;
struct V_203 * V_204 ;
int V_44 ;
V_44 = F_154 ( V_14 , V_24 , & V_209 ) ;
if ( V_44 < 0 )
goto V_117;
V_44 = - V_41 ;
V_204 = F_19 ( V_209 . V_39 -> V_31 , V_34 ) ;
if ( V_204 == NULL )
goto V_118;
V_44 = F_155 ( V_14 , & V_209 , V_204 ) ;
if ( V_44 < 0 )
goto V_123;
return V_204 ;
V_123:
F_23 ( V_204 ) ;
V_118:
F_98 ( V_209 . V_39 -> type -> V_116 ) ;
V_117:
return F_14 ( V_44 ) ;
}
void F_158 ( const struct V_13 * V_14 , struct V_203 * V_204 )
{
F_156 ( V_14 , V_204 ) ;
F_23 ( V_204 ) ;
}
static struct V_50 * F_159 ( const struct V_21 * V_22 ,
T_4 V_134 )
{
struct V_50 * V_51 ;
F_10 (rule, &chain->rules, list) {
if ( V_134 == V_51 -> V_134 )
return V_51 ;
}
return F_14 ( - V_52 ) ;
}
static struct V_50 * F_160 ( const struct V_21 * V_22 ,
const struct V_23 * V_24 )
{
if ( V_24 == NULL )
return F_14 ( - V_70 ) ;
return F_159 ( V_22 , F_128 ( F_129 ( V_24 ) ) ) ;
}
static int F_161 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_25 , T_1 V_27 , int V_76 ,
T_1 V_36 , int V_9 ,
const struct V_19 * V_20 ,
const struct V_21 * V_22 ,
const struct V_50 * V_51 )
{
struct V_17 * V_18 ;
struct V_77 * V_78 ;
const struct V_203 * V_204 , * V_217 ;
struct V_23 * V_6 ;
const struct V_50 * V_218 ;
int type = V_76 | V_5 << 8 ;
V_18 = F_59 ( V_16 , V_25 , V_27 , type , sizeof( struct V_77 ) ,
V_36 ) ;
if ( V_18 == NULL )
goto V_79;
V_78 = F_60 ( V_18 ) ;
V_78 -> V_80 = V_9 ;
V_78 -> V_81 = V_82 ;
V_78 -> V_83 = F_61 ( V_1 -> V_7 . V_84 & 0xffff ) ;
if ( F_62 ( V_16 , V_219 , V_20 -> V_69 ) )
goto V_79;
if ( F_62 ( V_16 , V_220 , V_22 -> V_69 ) )
goto V_79;
if ( F_116 ( V_16 , V_221 , F_117 ( V_51 -> V_134 ) ,
V_222 ) )
goto V_79;
if ( ( V_76 != V_56 ) && ( V_51 -> V_6 . V_223 != & V_22 -> V_200 ) ) {
V_218 = F_162 ( V_51 -> V_6 . V_223 , struct V_50 , V_6 ) ;
if ( F_116 ( V_16 , V_224 ,
F_117 ( V_218 -> V_134 ) ,
V_222 ) )
goto V_79;
}
V_6 = F_115 ( V_16 , V_225 ) ;
if ( V_6 == NULL )
goto V_79;
F_163 (expr, next, rule) {
if ( F_153 ( V_16 , V_226 , V_204 ) < 0 )
goto V_79;
}
F_118 ( V_16 , V_6 ) ;
if ( V_51 -> V_227 ) {
struct V_228 * V_227 = V_228 ( V_51 ) ;
if ( F_164 ( V_16 , V_229 , V_227 -> V_100 + 1 ,
V_227 -> V_206 ) < 0 )
goto V_79;
}
F_65 ( V_16 , V_18 ) ;
return 0 ;
V_79:
F_66 ( V_16 , V_18 ) ;
return - 1 ;
}
static void F_165 ( const struct V_13 * V_14 ,
const struct V_50 * V_51 , int V_76 )
{
struct V_15 * V_16 ;
int V_44 ;
if ( ! V_14 -> V_26 &&
! F_68 ( V_14 -> V_1 , V_88 ) )
return;
V_16 = F_69 ( V_89 , V_34 ) ;
if ( V_16 == NULL )
goto V_44;
V_44 = F_161 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_14 -> V_27 ,
V_76 , 0 , V_14 -> V_3 -> V_9 , V_14 -> V_20 ,
V_14 -> V_22 , V_51 ) ;
if ( V_44 < 0 ) {
F_70 ( V_16 ) ;
goto V_44;
}
F_71 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_88 ,
V_14 -> V_26 , V_34 ) ;
return;
V_44:
F_72 ( V_14 -> V_1 , V_14 -> V_25 , V_88 , - V_90 ) ;
}
static int F_166 ( struct V_15 * V_16 ,
struct V_91 * V_92 )
{
const struct V_77 * V_78 = F_60 ( V_92 -> V_18 ) ;
const struct V_230 * V_14 = V_92 -> V_206 ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
const struct V_50 * V_51 ;
unsigned int V_93 = 0 , V_94 = V_92 -> args [ 0 ] ;
struct V_1 * V_1 = F_74 ( V_16 -> V_95 ) ;
int V_9 = V_78 -> V_80 ;
F_75 () ;
V_92 -> V_27 = V_1 -> V_7 . V_84 ;
F_76 (afi, &net->nft.af_info, list) {
if ( V_9 != V_96 && V_9 != V_3 -> V_9 )
continue;
F_76 (table, &afi->tables, list) {
if ( V_14 && V_14 -> V_20 [ 0 ] &&
strcmp ( V_14 -> V_20 , V_20 -> V_69 ) != 0 )
continue;
F_76 (chain, &table->chains, list) {
if ( V_14 && V_14 -> V_22 [ 0 ] &&
strcmp ( V_14 -> V_22 , V_22 -> V_69 ) != 0 )
continue;
F_76 (rule, &chain->rules, list) {
if ( ! F_77 ( V_1 , V_51 ) )
goto V_97;
if ( V_93 < V_94 )
goto V_97;
if ( V_93 > V_94 )
memset ( & V_92 -> args [ 1 ] , 0 ,
sizeof( V_92 -> args ) - sizeof( V_92 -> args [ 0 ] ) ) ;
if ( F_161 ( V_16 , V_1 , F_16 ( V_92 -> V_16 ) . V_25 ,
V_92 -> V_18 -> V_28 ,
V_54 ,
V_98 | V_231 ,
V_3 -> V_9 , V_20 , V_22 , V_51 ) < 0 )
goto V_99;
F_78 ( V_92 , F_79 ( V_16 ) ) ;
V_97:
V_93 ++ ;
}
}
}
}
V_99:
F_80 () ;
V_92 -> args [ 0 ] = V_93 ;
return V_16 -> V_100 ;
}
static int F_167 ( struct V_91 * V_92 )
{
F_23 ( V_92 -> V_206 ) ;
return 0 ;
}
static int F_168 ( struct V_1 * V_1 , struct V_101 * V_102 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_77 * V_78 = F_60 ( V_18 ) ;
T_3 V_68 = F_82 ( V_1 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
const struct V_50 * V_51 ;
struct V_15 * V_103 ;
int V_9 = V_78 -> V_80 ;
int V_44 ;
if ( V_18 -> V_104 & V_105 ) {
struct V_106 V_107 = {
. V_108 = F_166 ,
. V_99 = F_167 ,
} ;
if ( V_24 [ V_219 ] || V_24 [ V_220 ] ) {
struct V_230 * V_14 ;
V_14 = F_19 ( sizeof( * V_14 ) , V_34 ) ;
if ( ! V_14 )
return - V_41 ;
if ( V_24 [ V_219 ] )
F_97 ( V_14 -> V_20 , V_24 [ V_219 ] ,
sizeof( V_14 -> V_20 ) ) ;
if ( V_24 [ V_220 ] )
F_97 ( V_14 -> V_22 , V_24 [ V_220 ] ,
sizeof( V_14 -> V_22 ) ) ;
V_107 . V_206 = V_14 ;
}
return F_83 ( V_102 , V_16 , V_18 , & V_107 ) ;
}
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_84 ( V_3 ) )
return F_85 ( V_3 ) ;
V_20 = F_52 ( V_3 , V_24 [ V_219 ] , V_68 ) ;
if ( F_84 ( V_20 ) )
return F_85 ( V_20 ) ;
V_22 = F_109 ( V_20 , V_24 [ V_220 ] , V_68 ) ;
if ( F_84 ( V_22 ) )
return F_85 ( V_22 ) ;
V_51 = F_160 ( V_22 , V_24 [ V_221 ] ) ;
if ( F_84 ( V_51 ) )
return F_85 ( V_51 ) ;
V_103 = F_86 ( V_89 , V_34 ) ;
if ( ! V_103 )
return - V_41 ;
V_44 = F_161 ( V_103 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 , V_54 , 0 ,
V_9 , V_20 , V_22 , V_51 ) ;
if ( V_44 < 0 )
goto V_44;
return F_87 ( V_102 , V_103 , F_16 ( V_16 ) . V_25 ) ;
V_44:
F_70 ( V_103 ) ;
return V_44 ;
}
static void F_169 ( const struct V_13 * V_14 ,
struct V_50 * V_51 )
{
struct V_203 * V_204 ;
V_204 = F_170 ( V_51 ) ;
while ( V_204 != F_171 ( V_51 ) && V_204 -> V_39 ) {
F_156 ( V_14 , V_204 ) ;
V_204 = F_172 ( V_204 ) ;
}
F_23 ( V_51 ) ;
}
static int F_173 ( struct V_1 * V_1 , struct V_101 * V_102 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_77 * V_78 = F_60 ( V_18 ) ;
T_3 V_68 = F_95 ( V_1 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_50 * V_51 , * V_232 = NULL ;
struct V_228 * V_227 ;
struct V_29 * V_33 = NULL ;
struct V_203 * V_204 ;
struct V_13 V_14 ;
struct V_23 * V_233 ;
unsigned int V_31 , V_73 , V_234 , V_235 = 0 , V_236 = 0 ;
int V_44 , V_237 ;
bool V_175 ;
T_4 V_134 , V_238 ;
V_175 = V_18 -> V_104 & V_189 ? true : false ;
V_3 = F_11 ( V_1 , V_78 -> V_80 , V_175 ) ;
if ( F_84 ( V_3 ) )
return F_85 ( V_3 ) ;
V_20 = F_52 ( V_3 , V_24 [ V_219 ] , V_68 ) ;
if ( F_84 ( V_20 ) )
return F_85 ( V_20 ) ;
V_22 = F_109 ( V_20 , V_24 [ V_220 ] , V_68 ) ;
if ( F_84 ( V_22 ) )
return F_85 ( V_22 ) ;
if ( V_24 [ V_221 ] ) {
V_134 = F_128 ( F_129 ( V_24 [ V_221 ] ) ) ;
V_51 = F_159 ( V_22 , V_134 ) ;
if ( F_84 ( V_51 ) )
return F_85 ( V_51 ) ;
if ( V_18 -> V_104 & V_112 )
return - V_113 ;
if ( V_18 -> V_104 & V_114 )
V_232 = V_51 ;
else
return - V_115 ;
} else {
if ( ! V_175 || V_18 -> V_104 & V_114 )
return - V_70 ;
V_134 = F_53 ( V_20 ) ;
if ( V_22 -> V_49 == V_193 )
return - V_194 ;
}
if ( V_24 [ V_224 ] ) {
if ( ! ( V_18 -> V_104 & V_189 ) )
return - V_115 ;
V_238 = F_128 ( F_129 ( V_24 [ V_224 ] ) ) ;
V_232 = F_159 ( V_22 , V_238 ) ;
if ( F_84 ( V_232 ) )
return F_85 ( V_232 ) ;
}
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_234 = 0 ;
V_31 = 0 ;
if ( V_24 [ V_225 ] ) {
F_174 (tmp, nla[NFTA_RULE_EXPRESSIONS], rem) {
V_44 = - V_70 ;
if ( F_175 ( V_233 ) != V_226 )
goto V_117;
if ( V_234 == V_239 )
goto V_117;
V_44 = F_154 ( & V_14 , V_233 , & V_209 [ V_234 ] ) ;
if ( V_44 < 0 )
goto V_117;
V_31 += V_209 [ V_234 ] . V_39 -> V_31 ;
V_234 ++ ;
}
}
V_44 = - V_240 ;
if ( V_31 >= 1 << 12 )
goto V_117;
if ( V_24 [ V_229 ] ) {
V_235 = F_56 ( V_24 [ V_229 ] ) ;
if ( V_235 > 0 )
V_236 = sizeof( struct V_228 ) + V_235 ;
}
V_44 = - V_41 ;
V_51 = F_19 ( sizeof( * V_51 ) + V_31 + V_236 , V_34 ) ;
if ( V_51 == NULL )
goto V_117;
F_30 ( V_1 , V_51 ) ;
V_51 -> V_134 = V_134 ;
V_51 -> V_241 = V_31 ;
V_51 -> V_227 = V_235 ? 1 : 0 ;
if ( V_235 ) {
V_227 = V_228 ( V_51 ) ;
V_227 -> V_100 = V_235 - 1 ;
F_176 ( V_227 -> V_206 , V_24 [ V_229 ] , V_235 ) ;
}
V_204 = F_170 ( V_51 ) ;
for ( V_73 = 0 ; V_73 < V_234 ; V_73 ++ ) {
V_44 = F_155 ( & V_14 , & V_209 [ V_73 ] , V_204 ) ;
if ( V_44 < 0 )
goto V_118;
V_209 [ V_73 ] . V_39 = NULL ;
V_204 = F_172 ( V_204 ) ;
}
if ( V_18 -> V_104 & V_114 ) {
if ( F_37 ( V_1 , V_232 ) ) {
V_33 = F_38 ( & V_14 , V_56 ,
V_232 ) ;
if ( V_33 == NULL ) {
V_44 = - V_41 ;
goto V_118;
}
F_33 ( V_1 , V_232 ) ;
V_22 -> V_49 -- ;
F_4 ( & V_51 -> V_6 , & V_232 -> V_6 ) ;
} else {
V_44 = - V_52 ;
goto V_118;
}
} else if ( V_18 -> V_104 & V_231 )
if ( V_232 )
F_148 ( & V_51 -> V_6 , & V_232 -> V_6 ) ;
else
F_4 ( & V_51 -> V_6 , & V_22 -> V_200 ) ;
else {
if ( V_232 )
F_4 ( & V_51 -> V_6 , & V_232 -> V_6 ) ;
else
F_148 ( & V_51 -> V_6 , & V_22 -> V_200 ) ;
}
if ( F_38 ( & V_14 , V_54 , V_51 ) == NULL ) {
V_44 = - V_41 ;
goto V_123;
}
V_22 -> V_49 ++ ;
return 0 ;
V_123:
F_8 ( & V_51 -> V_6 ) ;
V_118:
F_169 ( & V_14 , V_51 ) ;
V_117:
for ( V_73 = 0 ; V_73 < V_234 ; V_73 ++ ) {
if ( V_209 [ V_73 ] . V_39 != NULL )
F_98 ( V_209 [ V_73 ] . V_39 -> type -> V_116 ) ;
}
return V_44 ;
}
static struct V_50 * F_177 ( const struct V_1 * V_1 ,
const struct V_23 * V_24 )
{
T_1 V_242 = F_40 ( F_41 ( V_24 ) ) ;
struct V_29 * V_33 ;
F_10 (trans, &net->nft.commit_list, list) {
struct V_50 * V_51 = V_53 ( V_33 ) ;
if ( V_33 -> V_30 == V_54 &&
V_242 == F_39 ( V_33 ) )
return V_51 ;
}
return F_14 ( - V_52 ) ;
}
static int F_178 ( struct V_1 * V_1 , struct V_101 * V_102 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_77 * V_78 = F_60 ( V_18 ) ;
T_3 V_68 = F_95 ( V_1 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 = NULL ;
struct V_50 * V_51 ;
int V_9 = V_78 -> V_80 , V_44 = 0 ;
struct V_13 V_14 ;
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_84 ( V_3 ) )
return F_85 ( V_3 ) ;
V_20 = F_52 ( V_3 , V_24 [ V_219 ] , V_68 ) ;
if ( F_84 ( V_20 ) )
return F_85 ( V_20 ) ;
if ( V_24 [ V_220 ] ) {
V_22 = F_109 ( V_20 , V_24 [ V_220 ] ,
V_68 ) ;
if ( F_84 ( V_22 ) )
return F_85 ( V_22 ) ;
}
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
if ( V_22 ) {
if ( V_24 [ V_221 ] ) {
V_51 = F_160 ( V_22 ,
V_24 [ V_221 ] ) ;
if ( F_84 ( V_51 ) )
return F_85 ( V_51 ) ;
V_44 = F_42 ( & V_14 , V_51 ) ;
} else if ( V_24 [ V_55 ] ) {
V_51 = F_177 ( V_1 , V_24 [ V_55 ] ) ;
if ( F_84 ( V_51 ) )
return F_85 ( V_51 ) ;
V_44 = F_42 ( & V_14 , V_51 ) ;
} else {
V_44 = F_43 ( & V_14 ) ;
}
} else {
F_10 (chain, &table->chains, list) {
if ( ! F_37 ( V_1 , V_22 ) )
continue;
V_14 . V_22 = V_22 ;
V_44 = F_43 ( & V_14 ) ;
if ( V_44 < 0 )
break;
}
}
return V_44 ;
}
int F_179 ( struct V_243 * V_39 )
{
F_3 ( V_5 ) ;
F_4 ( & V_39 -> V_6 , & V_244 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_180 ( struct V_243 * V_39 )
{
F_3 ( V_5 ) ;
F_8 ( & V_39 -> V_6 ) ;
F_5 ( V_5 ) ;
}
static const struct V_243 *
F_181 ( const struct V_23 * const V_24 [] ,
const struct V_245 * V_246 ,
enum V_247 V_163 )
{
const struct V_243 * V_39 , * V_248 ;
struct V_249 V_250 , V_251 ;
T_1 V_252 ;
#ifdef F_12
if ( F_101 ( & V_244 ) ) {
F_5 ( V_5 ) ;
F_13 ( L_5 ) ;
F_3 ( V_5 ) ;
if ( ! F_101 ( & V_244 ) )
return F_14 ( - V_11 ) ;
}
#endif
V_252 = 0 ;
if ( V_24 [ V_253 ] != NULL ) {
V_252 = F_40 ( F_41 ( V_24 [ V_253 ] ) ) ;
V_252 &= V_254 | V_255 | V_256 |
V_257 ;
}
V_248 = NULL ;
V_251 . V_31 = ~ 0 ;
V_251 . V_258 = ~ 0 ;
V_251 . V_259 = ~ 0 ;
F_10 (ops, &nf_tables_set_ops, list) {
if ( ( V_39 -> V_252 & V_252 ) != V_252 )
continue;
if ( ! V_39 -> V_260 ( V_246 , V_252 , & V_250 ) )
continue;
switch ( V_163 ) {
case V_261 :
if ( V_250 . V_258 < V_251 . V_258 )
break;
if ( V_250 . V_258 == V_251 . V_258 ) {
if ( ! V_246 -> V_31 ) {
if ( V_250 . V_259 < V_251 . V_259 )
break;
} else if ( V_250 . V_31 < V_251 . V_31 ) {
break;
}
}
continue;
case V_262 :
if ( ! V_246 -> V_31 ) {
if ( V_250 . V_259 < V_251 . V_259 )
break;
if ( V_250 . V_259 == V_251 . V_259 &&
V_250 . V_258 < V_251 . V_258 )
break;
} else if ( V_250 . V_31 < V_251 . V_31 ) {
break;
}
continue;
default:
break;
}
if ( ! F_96 ( V_39 -> V_116 ) )
continue;
if ( V_248 != NULL )
F_98 ( V_248 -> V_116 ) ;
V_248 = V_39 ;
V_251 = V_250 ;
}
if ( V_248 != NULL )
return V_248 ;
return F_14 ( - V_115 ) ;
}
static int F_182 ( struct V_13 * V_14 , struct V_1 * V_1 ,
const struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
T_3 V_68 )
{
const struct V_77 * V_78 = F_60 ( V_18 ) ;
struct V_2 * V_3 = NULL ;
struct V_19 * V_20 = NULL ;
if ( V_78 -> V_80 != V_96 ) {
V_3 = F_11 ( V_1 , V_78 -> V_80 , false ) ;
if ( F_84 ( V_3 ) )
return F_85 ( V_3 ) ;
}
if ( V_24 [ V_263 ] != NULL ) {
if ( V_3 == NULL )
return - V_12 ;
V_20 = F_52 ( V_3 , V_24 [ V_263 ] ,
V_68 ) ;
if ( F_84 ( V_20 ) )
return F_85 ( V_20 ) ;
}
F_15 ( V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return 0 ;
}
struct V_57 * F_183 ( const struct V_19 * V_20 ,
const struct V_23 * V_24 , T_3 V_68 )
{
struct V_57 * V_58 ;
if ( V_24 == NULL )
return F_14 ( - V_70 ) ;
F_10 (set, &table->sets, list) {
if ( ! F_50 ( V_24 , V_58 -> V_69 ) &&
F_51 ( V_58 , V_68 ) )
return V_58 ;
}
return F_14 ( - V_52 ) ;
}
struct V_57 * F_184 ( const struct V_1 * V_1 ,
const struct V_23 * V_24 ,
T_3 V_68 )
{
struct V_29 * V_33 ;
T_1 V_242 = F_40 ( F_41 ( V_24 ) ) ;
F_10 (trans, &net->nft.commit_list, list) {
struct V_57 * V_58 = V_59 ( V_33 ) ;
if ( V_33 -> V_30 == V_60 &&
V_242 == F_45 ( V_33 ) &&
F_51 ( V_58 , V_68 ) )
return V_58 ;
}
return F_14 ( - V_52 ) ;
}
static int F_185 ( struct V_13 * V_14 , struct V_57 * V_58 ,
const char * V_69 )
{
const struct V_57 * V_73 ;
const char * V_264 ;
unsigned long * V_265 ;
unsigned int V_234 = 0 , V_266 = 0 ;
V_264 = F_186 ( V_69 , V_267 , '%' ) ;
if ( V_264 != NULL ) {
if ( V_264 [ 1 ] != 'd' || strchr ( V_264 + 2 , '%' ) )
return - V_70 ;
V_265 = ( unsigned long * ) F_187 ( V_34 ) ;
if ( V_265 == NULL )
return - V_41 ;
V_97:
F_10 (i, &ctx->table->sets, list) {
int V_233 ;
if ( ! F_37 ( V_14 -> V_1 , V_58 ) )
continue;
if ( ! sscanf ( V_73 -> V_69 , V_69 , & V_233 ) )
continue;
if ( V_233 < V_266 || V_233 >= V_266 + V_268 * V_269 )
continue;
F_188 ( V_233 - V_266 , V_265 ) ;
}
V_234 = F_189 ( V_265 , V_268 * V_269 ) ;
if ( V_234 >= V_268 * V_269 ) {
V_266 += V_268 * V_269 ;
memset ( V_265 , 0 , V_269 ) ;
goto V_97;
}
F_190 ( ( unsigned long ) V_265 ) ;
}
snprintf ( V_58 -> V_69 , sizeof( V_58 -> V_69 ) , V_69 , V_266 + V_234 ) ;
F_10 (i, &ctx->table->sets, list) {
if ( ! F_37 ( V_14 -> V_1 , V_73 ) )
continue;
if ( ! strcmp ( V_58 -> V_69 , V_73 -> V_69 ) )
return - V_270 ;
}
return 0 ;
}
static int F_191 ( struct V_15 * V_16 , const struct V_13 * V_14 ,
const struct V_57 * V_58 , T_7 V_76 , T_7 V_36 )
{
struct V_77 * V_78 ;
struct V_17 * V_18 ;
struct V_23 * V_246 ;
T_1 V_25 = V_14 -> V_25 ;
T_1 V_27 = V_14 -> V_27 ;
V_76 |= V_5 << 8 ;
V_18 = F_59 ( V_16 , V_25 , V_27 , V_76 , sizeof( struct V_77 ) ,
V_36 ) ;
if ( V_18 == NULL )
goto V_79;
V_78 = F_60 ( V_18 ) ;
V_78 -> V_80 = V_14 -> V_3 -> V_9 ;
V_78 -> V_81 = V_82 ;
V_78 -> V_83 = F_61 ( V_14 -> V_1 -> V_7 . V_84 & 0xffff ) ;
if ( F_62 ( V_16 , V_263 , V_14 -> V_20 -> V_69 ) )
goto V_79;
if ( F_62 ( V_16 , V_271 , V_58 -> V_69 ) )
goto V_79;
if ( V_58 -> V_36 != 0 )
if ( F_63 ( V_16 , V_253 , F_64 ( V_58 -> V_36 ) ) )
goto V_79;
if ( F_63 ( V_16 , V_272 , F_64 ( V_58 -> V_273 ) ) )
goto V_79;
if ( F_63 ( V_16 , V_274 , F_64 ( V_58 -> V_275 ) ) )
goto V_79;
if ( V_58 -> V_36 & V_255 ) {
if ( F_63 ( V_16 , V_276 , F_64 ( V_58 -> V_277 ) ) )
goto V_79;
if ( F_63 ( V_16 , V_278 , F_64 ( V_58 -> V_241 ) ) )
goto V_79;
}
if ( V_58 -> V_36 & V_257 &&
F_63 ( V_16 , V_279 , F_64 ( V_58 -> V_280 ) ) )
goto V_79;
if ( V_58 -> V_281 &&
F_116 ( V_16 , V_282 ,
F_117 ( F_192 ( V_58 -> V_281 ) ) ,
V_283 ) )
goto V_79;
if ( V_58 -> V_284 &&
F_63 ( V_16 , V_285 , F_64 ( V_58 -> V_284 ) ) )
goto V_79;
if ( V_58 -> V_163 != V_261 ) {
if ( F_63 ( V_16 , V_286 , F_64 ( V_58 -> V_163 ) ) )
goto V_79;
}
if ( F_164 ( V_16 , V_287 , V_58 -> V_288 , V_58 -> V_227 ) )
goto V_79;
V_246 = F_115 ( V_16 , V_289 ) ;
if ( V_246 == NULL )
goto V_79;
if ( V_58 -> V_31 &&
F_63 ( V_16 , V_290 , F_64 ( V_58 -> V_31 ) ) )
goto V_79;
F_118 ( V_16 , V_246 ) ;
F_65 ( V_16 , V_18 ) ;
return 0 ;
V_79:
F_66 ( V_16 , V_18 ) ;
return - 1 ;
}
static void F_193 ( const struct V_13 * V_14 ,
const struct V_57 * V_58 , int V_76 ,
T_2 V_291 )
{
struct V_15 * V_16 ;
T_1 V_25 = V_14 -> V_25 ;
int V_44 ;
if ( ! V_14 -> V_26 &&
! F_68 ( V_14 -> V_1 , V_88 ) )
return;
V_16 = F_69 ( V_89 , V_291 ) ;
if ( V_16 == NULL )
goto V_44;
V_44 = F_191 ( V_16 , V_14 , V_58 , V_76 , 0 ) ;
if ( V_44 < 0 ) {
F_70 ( V_16 ) ;
goto V_44;
}
F_71 ( V_16 , V_14 -> V_1 , V_25 , V_88 , V_14 -> V_26 ,
V_291 ) ;
return;
V_44:
F_72 ( V_14 -> V_1 , V_25 , V_88 , - V_90 ) ;
}
static int F_194 ( struct V_15 * V_16 , struct V_91 * V_92 )
{
const struct V_57 * V_58 ;
unsigned int V_93 , V_94 = V_92 -> args [ 0 ] ;
struct V_2 * V_3 ;
struct V_19 * V_20 , * V_292 = (struct V_19 * ) V_92 -> args [ 2 ] ;
struct V_1 * V_1 = F_74 ( V_16 -> V_95 ) ;
int V_293 = V_92 -> args [ 3 ] ;
struct V_13 * V_14 = V_92 -> V_206 , V_294 ;
if ( V_92 -> args [ 1 ] )
return V_16 -> V_100 ;
F_75 () ;
V_92 -> V_27 = V_1 -> V_7 . V_84 ;
F_76 (afi, &net->nft.af_info, list) {
if ( V_14 -> V_3 && V_14 -> V_3 != V_3 )
continue;
if ( V_293 ) {
if ( V_3 -> V_9 != V_293 )
continue;
V_293 = 0 ;
}
F_76 (table, &afi->tables, list) {
if ( V_14 -> V_20 && V_14 -> V_20 != V_20 )
continue;
if ( V_292 ) {
if ( V_292 != V_20 )
continue;
V_292 = NULL ;
}
V_93 = 0 ;
F_76 (set, &table->sets, list) {
if ( V_93 < V_94 )
goto V_97;
if ( ! F_77 ( V_1 , V_58 ) )
goto V_97;
V_294 = * V_14 ;
V_294 . V_20 = V_20 ;
V_294 . V_3 = V_3 ;
if ( F_191 ( V_16 , & V_294 , V_58 ,
V_60 ,
V_98 ) < 0 ) {
V_92 -> args [ 0 ] = V_93 ;
V_92 -> args [ 2 ] = ( unsigned long ) V_20 ;
V_92 -> args [ 3 ] = V_3 -> V_9 ;
goto V_99;
}
F_78 ( V_92 , F_79 ( V_16 ) ) ;
V_97:
V_93 ++ ;
}
if ( V_94 )
V_94 = 0 ;
}
}
V_92 -> args [ 1 ] = 1 ;
V_99:
F_80 () ;
return V_16 -> V_100 ;
}
static int F_195 ( struct V_91 * V_92 )
{
F_23 ( V_92 -> V_206 ) ;
return 0 ;
}
static int F_196 ( struct V_1 * V_1 , struct V_101 * V_102 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
T_3 V_68 = F_82 ( V_1 ) ;
const struct V_57 * V_58 ;
struct V_13 V_14 ;
struct V_15 * V_103 ;
const struct V_77 * V_78 = F_60 ( V_18 ) ;
int V_44 ;
V_44 = F_182 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_68 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_18 -> V_104 & V_105 ) {
struct V_106 V_107 = {
. V_108 = F_194 ,
. V_99 = F_195 ,
} ;
struct V_13 * V_295 ;
V_295 = F_197 ( sizeof( * V_295 ) , V_34 ) ;
if ( V_295 == NULL )
return - V_41 ;
* V_295 = V_14 ;
V_107 . V_206 = V_295 ;
return F_83 ( V_102 , V_16 , V_18 , & V_107 ) ;
}
if ( V_78 -> V_80 == V_96 )
return - V_12 ;
if ( ! V_24 [ V_263 ] )
return - V_70 ;
V_58 = F_183 ( V_14 . V_20 , V_24 [ V_271 ] , V_68 ) ;
if ( F_84 ( V_58 ) )
return F_85 ( V_58 ) ;
V_103 = F_86 ( V_89 , V_34 ) ;
if ( V_103 == NULL )
return - V_41 ;
V_44 = F_191 ( V_103 , & V_14 , V_58 , V_60 , 0 ) ;
if ( V_44 < 0 )
goto V_44;
return F_87 ( V_102 , V_103 , F_16 ( V_16 ) . V_25 ) ;
V_44:
F_70 ( V_103 ) ;
return V_44 ;
}
static int F_198 ( const struct V_13 * V_14 ,
struct V_245 * V_246 ,
const struct V_23 * V_24 )
{
struct V_23 * V_296 [ V_297 + 1 ] ;
int V_44 ;
V_44 = F_124 ( V_296 , V_297 , V_24 , V_298 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_296 [ V_290 ] != NULL )
V_246 -> V_31 = F_40 ( F_41 ( V_296 [ V_290 ] ) ) ;
return 0 ;
}
static int F_199 ( struct V_1 * V_1 , struct V_101 * V_102 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_77 * V_78 = F_60 ( V_18 ) ;
T_3 V_68 = F_95 ( V_1 ) ;
const struct V_243 * V_39 ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_57 * V_58 ;
struct V_13 V_14 ;
char V_69 [ V_267 ] ;
unsigned int V_31 ;
bool V_175 ;
T_4 V_281 ;
T_1 V_273 , V_277 , V_36 , V_163 , V_284 , V_280 ;
struct V_245 V_246 ;
unsigned char * V_227 ;
T_7 V_288 ;
int V_44 ;
if ( V_24 [ V_263 ] == NULL ||
V_24 [ V_271 ] == NULL ||
V_24 [ V_274 ] == NULL ||
V_24 [ V_61 ] == NULL )
return - V_70 ;
memset ( & V_246 , 0 , sizeof( V_246 ) ) ;
V_273 = V_299 ;
if ( V_24 [ V_272 ] != NULL ) {
V_273 = F_40 ( F_41 ( V_24 [ V_272 ] ) ) ;
if ( ( V_273 & V_300 ) == V_300 )
return - V_70 ;
}
V_246 . V_275 = F_40 ( F_41 ( V_24 [ V_274 ] ) ) ;
if ( V_246 . V_275 == 0 || V_246 . V_275 > V_301 )
return - V_70 ;
V_36 = 0 ;
if ( V_24 [ V_253 ] != NULL ) {
V_36 = F_40 ( F_41 ( V_24 [ V_253 ] ) ) ;
if ( V_36 & ~ ( V_128 | V_302 |
V_254 | V_256 |
V_255 | V_303 |
V_257 ) )
return - V_70 ;
if ( ( V_36 & ( V_255 | V_303 | V_257 ) ) ==
( V_255 | V_303 | V_257 ) )
return - V_115 ;
}
V_277 = 0 ;
if ( V_24 [ V_276 ] != NULL ) {
if ( ! ( V_36 & V_255 ) )
return - V_70 ;
V_277 = F_40 ( F_41 ( V_24 [ V_276 ] ) ) ;
if ( ( V_277 & V_300 ) == V_300 &&
V_277 != V_304 )
return - V_70 ;
if ( V_277 != V_304 ) {
if ( V_24 [ V_278 ] == NULL )
return - V_70 ;
V_246 . V_241 = F_40 ( F_41 ( V_24 [ V_278 ] ) ) ;
if ( V_246 . V_241 == 0 || V_246 . V_241 > V_301 )
return - V_70 ;
} else
V_246 . V_241 = sizeof( struct V_305 ) ;
} else if ( V_36 & V_255 )
return - V_70 ;
if ( V_24 [ V_279 ] != NULL ) {
if ( ! ( V_36 & V_257 ) )
return - V_70 ;
V_280 = F_40 ( F_41 ( V_24 [ V_279 ] ) ) ;
if ( V_280 == V_306 ||
V_280 > V_307 )
return - V_70 ;
} else if ( V_36 & V_257 )
return - V_70 ;
else
V_280 = V_306 ;
V_281 = 0 ;
if ( V_24 [ V_282 ] != NULL ) {
if ( ! ( V_36 & V_256 ) )
return - V_70 ;
V_281 = F_200 ( F_128 ( F_129 (
V_24 [ V_282 ] ) ) ) ;
}
V_284 = 0 ;
if ( V_24 [ V_285 ] != NULL ) {
if ( ! ( V_36 & V_256 ) )
return - V_70 ;
V_284 = F_40 ( F_41 ( V_24 [ V_285 ] ) ) ;
}
V_163 = V_261 ;
if ( V_24 [ V_286 ] != NULL )
V_163 = F_40 ( F_41 ( V_24 [ V_286 ] ) ) ;
if ( V_24 [ V_289 ] != NULL ) {
V_44 = F_198 ( & V_14 , & V_246 , V_24 [ V_289 ] ) ;
if ( V_44 < 0 )
return V_44 ;
}
V_175 = V_18 -> V_104 & V_189 ? true : false ;
V_3 = F_11 ( V_1 , V_78 -> V_80 , V_175 ) ;
if ( F_84 ( V_3 ) )
return F_85 ( V_3 ) ;
V_20 = F_52 ( V_3 , V_24 [ V_263 ] , V_68 ) ;
if ( F_84 ( V_20 ) )
return F_85 ( V_20 ) ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
V_58 = F_183 ( V_20 , V_24 [ V_271 ] , V_68 ) ;
if ( F_84 ( V_58 ) ) {
if ( F_85 ( V_58 ) != - V_52 )
return F_85 ( V_58 ) ;
} else {
if ( V_18 -> V_104 & V_112 )
return - V_113 ;
if ( V_18 -> V_104 & V_114 )
return - V_115 ;
return 0 ;
}
if ( ! ( V_18 -> V_104 & V_189 ) )
return - V_52 ;
V_39 = F_181 ( V_24 , & V_246 , V_163 ) ;
if ( F_84 ( V_39 ) )
return F_85 ( V_39 ) ;
V_288 = 0 ;
if ( V_24 [ V_287 ] )
V_288 = F_56 ( V_24 [ V_287 ] ) ;
V_31 = 0 ;
if ( V_39 -> V_308 != NULL )
V_31 = V_39 -> V_308 ( V_24 ) ;
V_44 = - V_41 ;
V_58 = F_19 ( sizeof( * V_58 ) + V_31 + V_288 , V_34 ) ;
if ( V_58 == NULL )
goto V_117;
F_97 ( V_69 , V_24 [ V_271 ] , sizeof( V_58 -> V_69 ) ) ;
V_44 = F_185 ( & V_14 , V_58 , V_69 ) ;
if ( V_44 < 0 )
goto V_118;
V_227 = NULL ;
if ( V_288 ) {
V_227 = V_58 -> V_206 + V_31 ;
F_176 ( V_227 , V_24 [ V_287 ] , V_288 ) ;
}
F_2 ( & V_58 -> V_129 ) ;
V_58 -> V_39 = V_39 ;
V_58 -> V_273 = V_273 ;
V_58 -> V_275 = V_246 . V_275 ;
V_58 -> V_277 = V_277 ;
V_58 -> V_280 = V_280 ;
V_58 -> V_241 = V_246 . V_241 ;
V_58 -> V_36 = V_36 ;
V_58 -> V_31 = V_246 . V_31 ;
V_58 -> V_163 = V_163 ;
V_58 -> V_288 = V_288 ;
V_58 -> V_227 = V_227 ;
V_58 -> V_281 = V_281 ;
V_58 -> V_284 = V_284 ;
V_44 = V_39 -> V_215 ( V_58 , & V_246 , V_24 ) ;
if ( V_44 < 0 )
goto V_118;
V_44 = F_44 ( & V_14 , V_60 , V_58 ) ;
if ( V_44 < 0 )
goto V_123;
F_4 ( & V_58 -> V_6 , & V_20 -> V_121 ) ;
V_20 -> V_49 ++ ;
return 0 ;
V_123:
V_39 -> V_216 ( V_58 ) ;
V_118:
F_23 ( V_58 ) ;
V_117:
F_98 ( V_39 -> V_116 ) ;
return V_44 ;
}
static void F_201 ( struct V_57 * V_58 )
{
V_58 -> V_39 -> V_216 ( V_58 ) ;
F_98 ( V_58 -> V_39 -> V_116 ) ;
F_23 ( V_58 ) ;
}
static void F_202 ( const struct V_13 * V_14 , struct V_57 * V_58 )
{
F_8 ( & V_58 -> V_6 ) ;
F_193 ( V_14 , V_58 , V_62 , V_309 ) ;
F_201 ( V_58 ) ;
}
static int F_203 ( struct V_1 * V_1 , struct V_101 * V_102 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_77 * V_78 = F_60 ( V_18 ) ;
T_3 V_68 = F_95 ( V_1 ) ;
struct V_57 * V_58 ;
struct V_13 V_14 ;
int V_44 ;
if ( V_78 -> V_80 == V_96 )
return - V_12 ;
if ( V_24 [ V_263 ] == NULL )
return - V_70 ;
V_44 = F_182 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_68 ) ;
if ( V_44 < 0 )
return V_44 ;
V_58 = F_183 ( V_14 . V_20 , V_24 [ V_271 ] , V_68 ) ;
if ( F_84 ( V_58 ) )
return F_85 ( V_58 ) ;
if ( ! F_101 ( & V_58 -> V_129 ) )
return - V_133 ;
return F_46 ( & V_14 , V_58 ) ;
}
static int F_204 ( const struct V_13 * V_14 ,
struct V_57 * V_58 ,
const struct V_310 * V_311 ,
struct V_312 * V_313 )
{
const struct V_314 * V_315 = F_205 ( V_58 , V_313 -> V_198 ) ;
enum V_316 V_317 ;
V_317 = F_206 ( V_58 -> V_277 ) ;
return F_207 ( V_14 , V_317 , F_208 ( V_315 ) ,
V_58 -> V_277 == V_304 ?
V_304 : V_299 ,
V_58 -> V_241 ) ;
}
int F_209 ( const struct V_13 * V_14 , struct V_57 * V_58 ,
struct V_318 * V_319 )
{
struct V_318 * V_73 ;
struct V_310 V_311 ;
if ( ! F_101 ( & V_58 -> V_129 ) && V_58 -> V_36 & V_128 )
return - V_133 ;
if ( V_319 -> V_36 & V_255 ) {
F_10 (i, &set->bindings, list) {
if ( V_73 -> V_36 & V_255 &&
V_73 -> V_22 == V_319 -> V_22 )
goto V_320;
}
V_311 . V_68 = F_95 ( V_14 -> V_1 ) ;
V_311 . V_321 = 0 ;
V_311 . V_322 = 0 ;
V_311 . V_44 = 0 ;
V_311 . V_323 = F_204 ;
V_58 -> V_39 -> V_324 ( V_14 , V_58 , & V_311 ) ;
if ( V_311 . V_44 < 0 )
return V_311 . V_44 ;
}
V_320:
V_319 -> V_22 = V_14 -> V_22 ;
F_4 ( & V_319 -> V_6 , & V_58 -> V_129 ) ;
return 0 ;
}
void F_210 ( const struct V_13 * V_14 , struct V_57 * V_58 ,
struct V_318 * V_319 )
{
F_8 ( & V_319 -> V_6 ) ;
if ( F_101 ( & V_58 -> V_129 ) && V_58 -> V_36 & V_128 &&
F_77 ( V_14 -> V_1 , V_58 ) )
F_202 ( V_14 , V_58 ) ;
}
static int F_211 ( struct V_13 * V_14 , struct V_1 * V_1 ,
const struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
T_3 V_68 )
{
const struct V_77 * V_78 = F_60 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
V_3 = F_11 ( V_1 , V_78 -> V_80 , false ) ;
if ( F_84 ( V_3 ) )
return F_85 ( V_3 ) ;
V_20 = F_52 ( V_3 , V_24 [ V_325 ] ,
V_68 ) ;
if ( F_84 ( V_20 ) )
return F_85 ( V_20 ) ;
F_15 ( V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return 0 ;
}
static int F_212 ( struct V_15 * V_16 ,
const struct V_57 * V_58 ,
const struct V_312 * V_313 )
{
const struct V_314 * V_315 = F_205 ( V_58 , V_313 -> V_198 ) ;
unsigned char * V_326 = F_213 ( V_16 ) ;
struct V_23 * V_139 ;
V_139 = F_115 ( V_16 , V_226 ) ;
if ( V_139 == NULL )
goto V_79;
if ( F_214 ( V_16 , V_327 , F_215 ( V_315 ) ,
V_299 , V_58 -> V_275 ) < 0 )
goto V_79;
if ( F_216 ( V_315 , V_328 ) &&
F_214 ( V_16 , V_329 , F_208 ( V_315 ) ,
V_58 -> V_277 == V_304 ? V_304 : V_299 ,
V_58 -> V_241 ) < 0 )
goto V_79;
if ( F_216 ( V_315 , V_330 ) &&
F_153 ( V_16 , V_331 , F_217 ( V_315 ) ) < 0 )
goto V_79;
if ( F_216 ( V_315 , V_332 ) &&
F_62 ( V_16 , V_333 ,
( * F_218 ( V_315 ) ) -> V_69 ) < 0 )
goto V_79;
if ( F_216 ( V_315 , V_334 ) &&
F_63 ( V_16 , V_335 ,
F_64 ( * F_219 ( V_315 ) ) ) )
goto V_79;
if ( F_216 ( V_315 , V_336 ) &&
F_116 ( V_16 , V_337 ,
F_117 ( F_192 (
* F_220 ( V_315 ) ) ) ,
V_338 ) )
goto V_79;
if ( F_216 ( V_315 , V_339 ) ) {
unsigned long V_340 , V_341 = V_342 ;
V_340 = * F_221 ( V_315 ) ;
if ( F_222 ( V_341 , V_340 ) )
V_340 -= V_341 ;
else
V_340 = 0 ;
if ( F_116 ( V_16 , V_343 ,
F_117 ( F_192 ( V_340 ) ) ,
V_338 ) )
goto V_79;
}
if ( F_216 ( V_315 , V_344 ) ) {
struct V_228 * V_227 ;
V_227 = F_223 ( V_315 ) ;
if ( F_164 ( V_16 , V_345 ,
V_227 -> V_100 + 1 , V_227 -> V_206 ) )
goto V_79;
}
F_118 ( V_16 , V_139 ) ;
return 0 ;
V_79:
F_66 ( V_16 , V_326 ) ;
return - V_346 ;
}
static int F_224 ( const struct V_13 * V_14 ,
struct V_57 * V_58 ,
const struct V_310 * V_311 ,
struct V_312 * V_313 )
{
struct V_347 * args ;
args = F_225 ( V_311 , struct V_347 , V_311 ) ;
return F_212 ( args -> V_16 , V_58 , V_313 ) ;
}
static int F_226 ( struct V_15 * V_16 , struct V_91 * V_92 )
{
struct V_1 * V_1 = F_74 ( V_16 -> V_95 ) ;
T_3 V_68 = F_82 ( V_1 ) ;
struct V_57 * V_58 ;
struct V_347 args ;
struct V_13 V_14 ;
struct V_23 * V_24 [ V_348 + 1 ] ;
struct V_77 * V_78 ;
struct V_17 * V_18 ;
struct V_23 * V_139 ;
T_1 V_25 , V_27 ;
int V_76 , V_44 ;
V_44 = F_227 ( V_92 -> V_18 , sizeof( struct V_77 ) , V_24 ,
V_348 , V_349 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_211 ( & V_14 , V_1 , V_92 -> V_16 , V_92 -> V_18 ,
( void * ) V_24 , V_68 ) ;
if ( V_44 < 0 )
return V_44 ;
V_58 = F_183 ( V_14 . V_20 , V_24 [ V_350 ] ,
V_68 ) ;
if ( F_84 ( V_58 ) )
return F_85 ( V_58 ) ;
V_76 = V_351 ;
V_76 |= V_5 << 8 ;
V_25 = F_16 ( V_92 -> V_16 ) . V_25 ;
V_27 = V_92 -> V_18 -> V_28 ;
V_18 = F_59 ( V_16 , V_25 , V_27 , V_76 , sizeof( struct V_77 ) ,
V_98 ) ;
if ( V_18 == NULL )
goto V_79;
V_78 = F_60 ( V_18 ) ;
V_78 -> V_80 = V_14 . V_3 -> V_9 ;
V_78 -> V_81 = V_82 ;
V_78 -> V_83 = F_61 ( V_14 . V_1 -> V_7 . V_84 & 0xffff ) ;
if ( F_62 ( V_16 , V_325 , V_14 . V_20 -> V_69 ) )
goto V_79;
if ( F_62 ( V_16 , V_350 , V_58 -> V_69 ) )
goto V_79;
V_139 = F_115 ( V_16 , V_352 ) ;
if ( V_139 == NULL )
goto V_79;
args . V_92 = V_92 ;
args . V_16 = V_16 ;
args . V_311 . V_68 = F_82 ( V_14 . V_1 ) ;
args . V_311 . V_321 = V_92 -> args [ 0 ] ;
args . V_311 . V_322 = 0 ;
args . V_311 . V_44 = 0 ;
args . V_311 . V_323 = F_224 ;
V_58 -> V_39 -> V_324 ( & V_14 , V_58 , & args . V_311 ) ;
F_118 ( V_16 , V_139 ) ;
F_65 ( V_16 , V_18 ) ;
if ( args . V_311 . V_44 && args . V_311 . V_44 != - V_346 )
return args . V_311 . V_44 ;
if ( args . V_311 . V_322 == V_92 -> args [ 0 ] )
return 0 ;
V_92 -> args [ 0 ] = args . V_311 . V_322 ;
return V_16 -> V_100 ;
V_79:
return - V_148 ;
}
static int F_228 ( struct V_1 * V_1 , struct V_101 * V_102 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
T_3 V_68 = F_82 ( V_1 ) ;
const struct V_57 * V_58 ;
struct V_13 V_14 ;
int V_44 ;
V_44 = F_211 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_68 ) ;
if ( V_44 < 0 )
return V_44 ;
V_58 = F_183 ( V_14 . V_20 , V_24 [ V_350 ] ,
V_68 ) ;
if ( F_84 ( V_58 ) )
return F_85 ( V_58 ) ;
if ( V_18 -> V_104 & V_105 ) {
struct V_106 V_107 = {
. V_108 = F_226 ,
} ;
return F_83 ( V_102 , V_16 , V_18 , & V_107 ) ;
}
return - V_115 ;
}
static int F_229 ( struct V_15 * V_16 ,
const struct V_13 * V_14 , T_1 V_27 ,
T_1 V_25 , int V_76 , T_7 V_36 ,
const struct V_57 * V_58 ,
const struct V_312 * V_313 )
{
struct V_77 * V_78 ;
struct V_17 * V_18 ;
struct V_23 * V_139 ;
int V_44 ;
V_76 |= V_5 << 8 ;
V_18 = F_59 ( V_16 , V_25 , V_27 , V_76 , sizeof( struct V_77 ) ,
V_36 ) ;
if ( V_18 == NULL )
goto V_79;
V_78 = F_60 ( V_18 ) ;
V_78 -> V_80 = V_14 -> V_3 -> V_9 ;
V_78 -> V_81 = V_82 ;
V_78 -> V_83 = F_61 ( V_14 -> V_1 -> V_7 . V_84 & 0xffff ) ;
if ( F_62 ( V_16 , V_263 , V_14 -> V_20 -> V_69 ) )
goto V_79;
if ( F_62 ( V_16 , V_271 , V_58 -> V_69 ) )
goto V_79;
V_139 = F_115 ( V_16 , V_352 ) ;
if ( V_139 == NULL )
goto V_79;
V_44 = F_212 ( V_16 , V_58 , V_313 ) ;
if ( V_44 < 0 )
goto V_79;
F_118 ( V_16 , V_139 ) ;
F_65 ( V_16 , V_18 ) ;
return 0 ;
V_79:
F_66 ( V_16 , V_18 ) ;
return - 1 ;
}
static void F_230 ( const struct V_13 * V_14 ,
const struct V_57 * V_58 ,
const struct V_312 * V_313 ,
int V_76 , T_7 V_36 )
{
struct V_1 * V_1 = V_14 -> V_1 ;
T_1 V_25 = V_14 -> V_25 ;
struct V_15 * V_16 ;
int V_44 ;
if ( ! V_14 -> V_26 && ! F_68 ( V_1 , V_88 ) )
return;
V_16 = F_69 ( V_89 , V_34 ) ;
if ( V_16 == NULL )
goto V_44;
V_44 = F_229 ( V_16 , V_14 , 0 , V_25 , V_76 , V_36 ,
V_58 , V_313 ) ;
if ( V_44 < 0 ) {
F_70 ( V_16 ) ;
goto V_44;
}
F_71 ( V_16 , V_1 , V_25 , V_88 , V_14 -> V_26 ,
V_34 ) ;
return;
V_44:
F_72 ( V_1 , V_25 , V_88 , - V_90 ) ;
}
static struct V_29 * F_231 ( struct V_13 * V_14 ,
int V_30 ,
struct V_57 * V_58 )
{
struct V_29 * V_33 ;
V_33 = F_20 ( V_14 , V_30 , sizeof( struct V_353 ) ) ;
if ( V_33 == NULL )
return NULL ;
F_232 ( V_33 ) = V_58 ;
return V_33 ;
}
void * F_233 ( const struct V_57 * V_58 ,
const struct V_354 * V_355 ,
const T_1 * V_356 , const T_1 * V_206 ,
T_4 V_281 , T_2 V_32 )
{
struct V_314 * V_315 ;
void * V_313 ;
V_313 = F_19 ( V_58 -> V_39 -> V_357 + V_355 -> V_100 , V_32 ) ;
if ( V_313 == NULL )
return NULL ;
V_315 = F_205 ( V_58 , V_313 ) ;
F_234 ( V_315 , V_355 ) ;
memcpy ( F_215 ( V_315 ) , V_356 , V_58 -> V_275 ) ;
if ( F_216 ( V_315 , V_328 ) )
memcpy ( F_208 ( V_315 ) , V_206 , V_58 -> V_241 ) ;
if ( F_216 ( V_315 , V_339 ) )
* F_221 ( V_315 ) =
V_342 + V_281 ;
if ( F_216 ( V_315 , V_336 ) )
* F_220 ( V_315 ) = V_281 ;
return V_313 ;
}
void F_235 ( const struct V_57 * V_58 , void * V_313 ,
bool V_358 )
{
struct V_314 * V_315 = F_205 ( V_58 , V_313 ) ;
F_236 ( F_215 ( V_315 ) , V_299 ) ;
if ( F_216 ( V_315 , V_328 ) )
F_236 ( F_208 ( V_315 ) , V_58 -> V_277 ) ;
if ( V_358 && F_216 ( V_315 , V_330 ) )
F_156 ( NULL , F_217 ( V_315 ) ) ;
if ( F_216 ( V_315 , V_332 ) )
( * F_218 ( V_315 ) ) -> V_49 -- ;
F_23 ( V_313 ) ;
}
static int F_237 ( const struct V_57 * V_58 ,
const struct V_23 * V_166 , T_1 * V_36 )
{
if ( V_166 == NULL )
return 0 ;
* V_36 = F_40 ( F_41 ( V_166 ) ) ;
if ( * V_36 & ~ V_359 )
return - V_70 ;
if ( ! ( V_58 -> V_36 & V_254 ) &&
* V_36 & V_359 )
return - V_70 ;
return 0 ;
}
static int F_238 ( struct V_13 * V_14 , struct V_57 * V_58 ,
const struct V_23 * V_166 , T_1 V_104 )
{
struct V_23 * V_24 [ V_360 + 1 ] ;
T_3 V_68 = F_95 ( V_14 -> V_1 ) ;
struct V_361 V_362 , V_363 ;
struct V_354 V_355 ;
struct V_314 * V_315 , * V_364 ;
struct V_312 V_313 ;
struct V_318 * V_319 ;
struct V_63 * V_64 = NULL ;
struct V_228 * V_227 ;
struct V_365 V_206 ;
enum V_316 V_317 ;
struct V_29 * V_33 ;
T_1 V_36 = 0 ;
T_4 V_281 ;
T_3 V_235 ;
int V_44 ;
V_44 = F_124 ( V_24 , V_360 , V_166 ,
V_366 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_24 [ V_327 ] == NULL )
return - V_70 ;
F_239 ( & V_355 ) ;
V_44 = F_237 ( V_58 , V_24 [ V_335 ] , & V_36 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_36 != 0 )
F_240 ( & V_355 , V_334 ) ;
if ( V_58 -> V_36 & V_255 ) {
if ( V_24 [ V_329 ] == NULL &&
! ( V_36 & V_359 ) )
return - V_70 ;
if ( V_24 [ V_329 ] != NULL &&
V_36 & V_359 )
return - V_70 ;
} else {
if ( V_24 [ V_329 ] != NULL )
return - V_70 ;
}
V_281 = 0 ;
if ( V_24 [ V_337 ] != NULL ) {
if ( ! ( V_58 -> V_36 & V_256 ) )
return - V_70 ;
V_281 = F_200 ( F_128 ( F_129 (
V_24 [ V_337 ] ) ) ) ;
} else if ( V_58 -> V_36 & V_256 ) {
V_281 = V_58 -> V_281 ;
}
V_44 = F_241 ( V_14 , & V_313 . V_356 . V_367 , sizeof( V_313 . V_356 ) , & V_362 ,
V_24 [ V_327 ] ) ;
if ( V_44 < 0 )
goto V_117;
V_44 = - V_70 ;
if ( V_362 . type != V_299 || V_362 . V_100 != V_58 -> V_275 )
goto V_118;
F_242 ( & V_355 , V_368 , V_362 . V_100 ) ;
if ( V_281 > 0 ) {
F_240 ( & V_355 , V_339 ) ;
if ( V_281 != V_58 -> V_281 )
F_240 ( & V_355 , V_336 ) ;
}
if ( V_24 [ V_333 ] != NULL ) {
if ( ! ( V_58 -> V_36 & V_257 ) ) {
V_44 = - V_70 ;
goto V_118;
}
V_64 = F_243 ( V_14 -> V_20 , V_24 [ V_333 ] ,
V_58 -> V_280 , V_68 ) ;
if ( F_84 ( V_64 ) ) {
V_44 = F_85 ( V_64 ) ;
goto V_118;
}
F_240 ( & V_355 , V_332 ) ;
}
if ( V_24 [ V_329 ] != NULL ) {
V_44 = F_241 ( V_14 , & V_206 , sizeof( V_206 ) , & V_363 ,
V_24 [ V_329 ] ) ;
if ( V_44 < 0 )
goto V_118;
V_44 = - V_70 ;
if ( V_58 -> V_277 != V_304 && V_363 . V_100 != V_58 -> V_241 )
goto V_123;
V_317 = F_206 ( V_58 -> V_277 ) ;
F_10 (binding, &set->bindings, list) {
struct V_13 V_369 = {
. V_1 = V_14 -> V_1 ,
. V_3 = V_14 -> V_3 ,
. V_20 = V_14 -> V_20 ,
. V_22 = (struct V_21 * ) V_319 -> V_22 ,
} ;
if ( ! ( V_319 -> V_36 & V_255 ) )
continue;
V_44 = F_207 ( & V_369 , V_317 ,
& V_206 ,
V_363 . type , V_363 . V_100 ) ;
if ( V_44 < 0 )
goto V_123;
}
F_242 ( & V_355 , V_328 , V_363 . V_100 ) ;
}
V_235 = 0 ;
if ( V_24 [ V_345 ] != NULL ) {
V_235 = F_56 ( V_24 [ V_345 ] ) ;
if ( V_235 > 0 )
F_242 ( & V_355 , V_344 ,
V_235 ) ;
}
V_44 = - V_41 ;
V_313 . V_198 = F_233 ( V_58 , & V_355 , V_313 . V_356 . V_367 . V_206 , V_206 . V_206 ,
V_281 , V_34 ) ;
if ( V_313 . V_198 == NULL )
goto V_123;
V_315 = F_205 ( V_58 , V_313 . V_198 ) ;
if ( V_36 )
* F_219 ( V_315 ) = V_36 ;
if ( V_235 > 0 ) {
V_227 = F_223 ( V_315 ) ;
V_227 -> V_100 = V_235 - 1 ;
F_176 ( & V_227 -> V_206 , V_24 [ V_345 ] , V_235 ) ;
}
if ( V_64 ) {
* F_218 ( V_315 ) = V_64 ;
V_64 -> V_49 ++ ;
}
V_33 = F_231 ( V_14 , V_351 , V_58 ) ;
if ( V_33 == NULL )
goto V_370;
V_315 -> V_68 = F_82 ( V_14 -> V_1 ) | V_371 ;
V_44 = V_58 -> V_39 -> V_372 ( V_14 -> V_1 , V_58 , & V_313 , & V_364 ) ;
if ( V_44 ) {
if ( V_44 == - V_113 ) {
if ( ( F_216 ( V_315 , V_328 ) &&
F_216 ( V_364 , V_328 ) &&
memcmp ( F_208 ( V_315 ) ,
F_208 ( V_364 ) , V_58 -> V_241 ) != 0 ) ||
( F_216 ( V_315 , V_332 ) &&
F_216 ( V_364 , V_332 ) &&
* F_218 ( V_315 ) != * F_218 ( V_364 ) ) )
V_44 = - V_133 ;
else if ( ! ( V_104 & V_112 ) )
V_44 = 0 ;
}
goto V_373;
}
if ( V_58 -> V_31 &&
! F_244 ( & V_58 -> V_374 , 1 , V_58 -> V_31 + V_58 -> V_375 ) ) {
V_44 = - V_270 ;
goto V_376;
}
V_353 ( V_33 ) = V_313 ;
F_31 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_43 ) ;
return 0 ;
V_376:
V_58 -> V_39 -> remove ( V_14 -> V_1 , V_58 , & V_313 ) ;
V_373:
F_23 ( V_33 ) ;
V_370:
F_23 ( V_313 . V_198 ) ;
V_123:
if ( V_24 [ V_329 ] != NULL )
F_236 ( & V_206 , V_363 . type ) ;
V_118:
F_236 ( & V_313 . V_356 . V_367 , V_362 . type ) ;
V_117:
return V_44 ;
}
static int F_245 ( struct V_1 * V_1 , struct V_101 * V_102 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
T_3 V_68 = F_95 ( V_1 ) ;
const struct V_23 * V_166 ;
struct V_57 * V_58 ;
struct V_13 V_14 ;
int V_237 , V_44 = 0 ;
if ( V_24 [ V_352 ] == NULL )
return - V_70 ;
V_44 = F_211 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_68 ) ;
if ( V_44 < 0 )
return V_44 ;
V_58 = F_183 ( V_14 . V_20 , V_24 [ V_350 ] ,
V_68 ) ;
if ( F_84 ( V_58 ) ) {
if ( V_24 [ V_377 ] ) {
V_58 = F_184 ( V_1 ,
V_24 [ V_377 ] ,
V_68 ) ;
}
if ( F_84 ( V_58 ) )
return F_85 ( V_58 ) ;
}
if ( ! F_101 ( & V_58 -> V_129 ) && V_58 -> V_36 & V_302 )
return - V_133 ;
F_174 (attr, nla[NFTA_SET_ELEM_LIST_ELEMENTS], rem) {
V_44 = F_238 ( & V_14 , V_58 , V_166 , V_18 -> V_104 ) ;
if ( V_44 < 0 )
break;
}
return V_44 ;
}
static int F_246 ( struct V_13 * V_14 , struct V_57 * V_58 ,
const struct V_23 * V_166 )
{
struct V_23 * V_24 [ V_360 + 1 ] ;
struct V_354 V_355 ;
struct V_361 V_246 ;
struct V_312 V_313 ;
struct V_314 * V_315 ;
struct V_29 * V_33 ;
T_1 V_36 = 0 ;
void * V_198 ;
int V_44 ;
V_44 = F_124 ( V_24 , V_360 , V_166 ,
V_366 ) ;
if ( V_44 < 0 )
goto V_117;
V_44 = - V_70 ;
if ( V_24 [ V_327 ] == NULL )
goto V_117;
F_239 ( & V_355 ) ;
V_44 = F_237 ( V_58 , V_24 [ V_335 ] , & V_36 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_36 != 0 )
F_240 ( & V_355 , V_334 ) ;
V_44 = F_241 ( V_14 , & V_313 . V_356 . V_367 , sizeof( V_313 . V_356 ) , & V_246 ,
V_24 [ V_327 ] ) ;
if ( V_44 < 0 )
goto V_117;
V_44 = - V_70 ;
if ( V_246 . type != V_299 || V_246 . V_100 != V_58 -> V_275 )
goto V_118;
F_242 ( & V_355 , V_368 , V_246 . V_100 ) ;
V_44 = - V_41 ;
V_313 . V_198 = F_233 ( V_58 , & V_355 , V_313 . V_356 . V_367 . V_206 , NULL , 0 ,
V_34 ) ;
if ( V_313 . V_198 == NULL )
goto V_118;
V_315 = F_205 ( V_58 , V_313 . V_198 ) ;
if ( V_36 )
* F_219 ( V_315 ) = V_36 ;
V_33 = F_231 ( V_14 , V_378 , V_58 ) ;
if ( V_33 == NULL ) {
V_44 = - V_41 ;
goto V_123;
}
V_198 = V_58 -> V_39 -> V_379 ( V_14 -> V_1 , V_58 , & V_313 ) ;
if ( V_198 == NULL ) {
V_44 = - V_52 ;
goto V_370;
}
F_23 ( V_313 . V_198 ) ;
V_313 . V_198 = V_198 ;
V_353 ( V_33 ) = V_313 ;
F_31 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_43 ) ;
return 0 ;
V_370:
F_23 ( V_33 ) ;
V_123:
F_23 ( V_313 . V_198 ) ;
V_118:
F_236 ( & V_313 . V_356 . V_367 , V_246 . type ) ;
V_117:
return V_44 ;
}
static int F_247 ( const struct V_13 * V_14 ,
struct V_57 * V_58 ,
const struct V_310 * V_311 ,
struct V_312 * V_313 )
{
struct V_29 * V_33 ;
int V_44 ;
V_33 = F_18 ( V_14 , V_378 ,
sizeof( struct V_353 ) , V_309 ) ;
if ( ! V_33 )
return - V_41 ;
if ( ! V_58 -> V_39 -> V_380 ( V_14 -> V_1 , V_58 , V_313 -> V_198 ) ) {
V_44 = - V_52 ;
goto V_117;
}
V_58 -> V_375 ++ ;
F_232 ( V_33 ) = V_58 ;
V_353 ( V_33 ) = * V_313 ;
F_31 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_43 ) ;
return 0 ;
V_117:
F_23 ( V_33 ) ;
return V_44 ;
}
static int F_248 ( struct V_1 * V_1 , struct V_101 * V_102 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
T_3 V_68 = F_95 ( V_1 ) ;
const struct V_23 * V_166 ;
struct V_57 * V_58 ;
struct V_13 V_14 ;
int V_237 , V_44 = 0 ;
V_44 = F_211 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_68 ) ;
if ( V_44 < 0 )
return V_44 ;
V_58 = F_183 ( V_14 . V_20 , V_24 [ V_350 ] ,
V_68 ) ;
if ( F_84 ( V_58 ) )
return F_85 ( V_58 ) ;
if ( ! F_101 ( & V_58 -> V_129 ) && V_58 -> V_36 & V_302 )
return - V_133 ;
if ( V_24 [ V_352 ] == NULL ) {
struct V_310 V_311 = {
. V_68 = V_68 ,
. V_323 = F_247 ,
} ;
V_58 -> V_39 -> V_324 ( & V_14 , V_58 , & V_311 ) ;
return V_311 . V_44 ;
}
F_174 (attr, nla[NFTA_SET_ELEM_LIST_ELEMENTS], rem) {
V_44 = F_246 ( & V_14 , V_58 , V_166 ) ;
if ( V_44 < 0 )
break;
V_58 -> V_375 ++ ;
}
return V_44 ;
}
void F_249 ( struct V_381 * V_382 )
{
struct V_383 * V_384 ;
unsigned int V_73 ;
V_384 = F_225 ( V_382 , struct V_383 , V_385 . V_382 ) ;
for ( V_73 = 0 ; V_73 < V_384 -> V_385 . V_109 ; V_73 ++ )
F_235 ( V_384 -> V_385 . V_58 , V_384 -> V_386 [ V_73 ] , true ) ;
F_23 ( V_384 ) ;
}
struct V_383 * F_250 ( const struct V_57 * V_58 ,
T_2 V_32 )
{
struct V_383 * V_384 ;
V_384 = F_19 ( sizeof( * V_384 ) , V_32 ) ;
if ( V_384 == NULL )
return V_384 ;
V_384 -> V_385 . V_58 = V_58 ;
return V_384 ;
}
int F_251 ( struct V_387 * V_388 )
{
if ( V_388 -> type == V_306 )
return - V_70 ;
F_3 ( V_5 ) ;
F_148 ( & V_388 -> V_6 , & V_389 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_252 ( struct V_387 * V_388 )
{
F_3 ( V_5 ) ;
F_8 ( & V_388 -> V_6 ) ;
F_5 ( V_5 ) ;
}
struct V_63 * F_243 ( const struct V_19 * V_20 ,
const struct V_23 * V_24 ,
T_1 V_280 , T_3 V_68 )
{
struct V_63 * V_64 ;
F_10 (obj, &table->objects, list) {
if ( ! F_50 ( V_24 , V_64 -> V_69 ) &&
V_280 == V_64 -> type -> type &&
F_51 ( V_64 , V_68 ) )
return V_64 ;
}
return F_14 ( - V_52 ) ;
}
static struct V_63 * F_253 ( const struct V_387 * type ,
const struct V_23 * V_166 )
{
struct V_23 * V_167 [ type -> V_213 + 1 ] ;
struct V_63 * V_64 ;
int V_44 ;
if ( V_166 ) {
V_44 = F_124 ( V_167 , type -> V_213 , V_166 , type -> V_163 ) ;
if ( V_44 < 0 )
goto V_117;
} else {
memset ( V_167 , 0 , sizeof( V_167 [ 0 ] ) * ( type -> V_213 + 1 ) ) ;
}
V_44 = - V_41 ;
V_64 = F_19 ( sizeof( struct V_63 ) + type -> V_31 , V_34 ) ;
if ( V_64 == NULL )
goto V_117;
V_44 = type -> V_215 ( ( const struct V_23 * const * ) V_167 , V_64 ) ;
if ( V_44 < 0 )
goto V_118;
V_64 -> type = type ;
return V_64 ;
V_118:
F_23 ( V_64 ) ;
V_117:
return F_14 ( V_44 ) ;
}
static int F_254 ( struct V_15 * V_16 , unsigned int V_166 ,
struct V_63 * V_64 , bool V_390 )
{
struct V_23 * V_139 ;
V_139 = F_115 ( V_16 , V_166 ) ;
if ( ! V_139 )
goto V_79;
if ( V_64 -> type -> V_108 ( V_16 , V_64 , V_390 ) < 0 )
goto V_79;
F_118 ( V_16 , V_139 ) ;
return 0 ;
V_79:
return - 1 ;
}
static const struct V_387 * F_255 ( T_1 V_280 )
{
const struct V_387 * type ;
F_10 (type, &nf_tables_objects, list) {
if ( V_280 == type -> type )
return type ;
}
return NULL ;
}
static const struct V_387 * F_256 ( T_1 V_280 )
{
const struct V_387 * type ;
type = F_255 ( V_280 ) ;
if ( type != NULL && F_96 ( type -> V_116 ) )
return type ;
#ifdef F_12
if ( type == NULL ) {
F_5 ( V_5 ) ;
F_13 ( L_6 , V_280 ) ;
F_3 ( V_5 ) ;
if ( F_255 ( V_280 ) )
return F_14 ( - V_11 ) ;
}
#endif
return F_14 ( - V_52 ) ;
}
static int F_257 ( struct V_1 * V_1 , struct V_101 * V_102 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_77 * V_78 = F_60 ( V_18 ) ;
const struct V_387 * type ;
T_3 V_68 = F_95 ( V_1 ) ;
int V_9 = V_78 -> V_80 ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_63 * V_64 ;
struct V_13 V_14 ;
T_1 V_280 ;
int V_44 ;
if ( ! V_24 [ V_391 ] ||
! V_24 [ V_392 ] ||
! V_24 [ V_393 ] )
return - V_70 ;
V_3 = F_11 ( V_1 , V_9 , true ) ;
if ( F_84 ( V_3 ) )
return F_85 ( V_3 ) ;
V_20 = F_52 ( V_3 , V_24 [ V_394 ] , V_68 ) ;
if ( F_84 ( V_20 ) )
return F_85 ( V_20 ) ;
V_280 = F_40 ( F_41 ( V_24 [ V_391 ] ) ) ;
V_64 = F_243 ( V_20 , V_24 [ V_392 ] , V_280 , V_68 ) ;
if ( F_84 ( V_64 ) ) {
V_44 = F_85 ( V_64 ) ;
if ( V_44 != - V_52 )
return V_44 ;
} else {
if ( V_18 -> V_104 & V_112 )
return - V_113 ;
return 0 ;
}
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
type = F_256 ( V_280 ) ;
if ( F_84 ( type ) )
return F_85 ( type ) ;
V_64 = F_253 ( type , V_24 [ V_393 ] ) ;
if ( F_84 ( V_64 ) ) {
V_44 = F_85 ( V_64 ) ;
goto V_117;
}
V_64 -> V_20 = V_20 ;
F_97 ( V_64 -> V_69 , V_24 [ V_392 ] , V_395 ) ;
V_44 = F_47 ( & V_14 , V_66 , V_64 ) ;
if ( V_44 < 0 )
goto V_118;
F_4 ( & V_64 -> V_6 , & V_20 -> V_122 ) ;
V_20 -> V_49 ++ ;
return 0 ;
V_118:
if ( V_64 -> type -> V_216 )
V_64 -> type -> V_216 ( V_64 ) ;
F_23 ( V_64 ) ;
V_117:
F_98 ( type -> V_116 ) ;
return V_44 ;
}
static int F_258 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_25 , T_1 V_27 , int V_76 , T_1 V_36 ,
int V_9 , const struct V_19 * V_20 ,
struct V_63 * V_64 , bool V_390 )
{
struct V_77 * V_78 ;
struct V_17 * V_18 ;
V_76 |= V_5 << 8 ;
V_18 = F_59 ( V_16 , V_25 , V_27 , V_76 , sizeof( struct V_77 ) , V_36 ) ;
if ( V_18 == NULL )
goto V_79;
V_78 = F_60 ( V_18 ) ;
V_78 -> V_80 = V_9 ;
V_78 -> V_81 = V_82 ;
V_78 -> V_83 = F_61 ( V_1 -> V_7 . V_84 & 0xffff ) ;
if ( F_62 ( V_16 , V_394 , V_20 -> V_69 ) ||
F_62 ( V_16 , V_392 , V_64 -> V_69 ) ||
F_63 ( V_16 , V_391 , F_64 ( V_64 -> type -> type ) ) ||
F_63 ( V_16 , V_396 , F_64 ( V_64 -> V_49 ) ) ||
F_254 ( V_16 , V_393 , V_64 , V_390 ) )
goto V_79;
F_65 ( V_16 , V_18 ) ;
return 0 ;
V_79:
F_66 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_259 ( struct V_15 * V_16 , struct V_91 * V_92 )
{
const struct V_77 * V_78 = F_60 ( V_92 -> V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
unsigned int V_93 = 0 , V_94 = V_92 -> args [ 0 ] ;
struct V_397 * V_398 = V_92 -> V_206 ;
struct V_1 * V_1 = F_74 ( V_16 -> V_95 ) ;
int V_9 = V_78 -> V_80 ;
struct V_63 * V_64 ;
bool V_390 = false ;
if ( F_260 ( V_92 -> V_18 -> V_399 ) == V_400 )
V_390 = true ;
F_75 () ;
V_92 -> V_27 = V_1 -> V_7 . V_84 ;
F_76 (afi, &net->nft.af_info, list) {
if ( V_9 != V_96 && V_9 != V_3 -> V_9 )
continue;
F_76 (table, &afi->tables, list) {
F_76 (obj, &table->objects, list) {
if ( ! F_77 ( V_1 , V_64 ) )
goto V_97;
if ( V_93 < V_94 )
goto V_97;
if ( V_93 > V_94 )
memset ( & V_92 -> args [ 1 ] , 0 ,
sizeof( V_92 -> args ) - sizeof( V_92 -> args [ 0 ] ) ) ;
if ( V_398 && V_398 -> V_20 [ 0 ] &&
strcmp ( V_398 -> V_20 , V_20 -> V_69 ) )
goto V_97;
if ( V_398 &&
V_398 -> type != V_306 &&
V_64 -> type -> type != V_398 -> type )
goto V_97;
if ( F_258 ( V_16 , V_1 , F_16 ( V_92 -> V_16 ) . V_25 ,
V_92 -> V_18 -> V_28 ,
V_66 ,
V_98 | V_231 ,
V_3 -> V_9 , V_20 , V_64 , V_390 ) < 0 )
goto V_99;
F_78 ( V_92 , F_79 ( V_16 ) ) ;
V_97:
V_93 ++ ;
}
}
}
V_99:
F_80 () ;
V_92 -> args [ 0 ] = V_93 ;
return V_16 -> V_100 ;
}
static int F_261 ( struct V_91 * V_92 )
{
F_23 ( V_92 -> V_206 ) ;
return 0 ;
}
static struct V_397 *
F_262 ( const struct V_23 * const V_24 [] )
{
struct V_397 * V_398 ;
V_398 = F_19 ( sizeof( * V_398 ) , V_34 ) ;
if ( ! V_398 )
return F_14 ( - V_41 ) ;
if ( V_24 [ V_394 ] )
F_97 ( V_398 -> V_20 , V_24 [ V_394 ] ,
V_119 ) ;
if ( V_24 [ V_391 ] )
V_398 -> type = F_40 ( F_41 ( V_24 [ V_391 ] ) ) ;
return V_398 ;
}
static int F_263 ( struct V_1 * V_1 , struct V_101 * V_102 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_77 * V_78 = F_60 ( V_18 ) ;
T_3 V_68 = F_82 ( V_1 ) ;
int V_9 = V_78 -> V_80 ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
struct V_63 * V_64 ;
struct V_15 * V_103 ;
bool V_390 = false ;
T_1 V_280 ;
int V_44 ;
if ( V_18 -> V_104 & V_105 ) {
struct V_106 V_107 = {
. V_108 = F_259 ,
. V_99 = F_261 ,
} ;
if ( V_24 [ V_394 ] ||
V_24 [ V_391 ] ) {
struct V_397 * V_398 ;
V_398 = F_262 ( V_24 ) ;
if ( F_84 ( V_398 ) )
return - V_41 ;
V_107 . V_206 = V_398 ;
}
return F_83 ( V_102 , V_16 , V_18 , & V_107 ) ;
}
if ( ! V_24 [ V_392 ] ||
! V_24 [ V_391 ] )
return - V_70 ;
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_84 ( V_3 ) )
return F_85 ( V_3 ) ;
V_20 = F_52 ( V_3 , V_24 [ V_394 ] , V_68 ) ;
if ( F_84 ( V_20 ) )
return F_85 ( V_20 ) ;
V_280 = F_40 ( F_41 ( V_24 [ V_391 ] ) ) ;
V_64 = F_243 ( V_20 , V_24 [ V_392 ] , V_280 , V_68 ) ;
if ( F_84 ( V_64 ) )
return F_85 ( V_64 ) ;
V_103 = F_86 ( V_89 , V_34 ) ;
if ( ! V_103 )
return - V_41 ;
if ( F_260 ( V_18 -> V_399 ) == V_400 )
V_390 = true ;
V_44 = F_258 ( V_103 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 , V_66 , 0 ,
V_9 , V_20 , V_64 , V_390 ) ;
if ( V_44 < 0 )
goto V_44;
return F_87 ( V_102 , V_103 , F_16 ( V_16 ) . V_25 ) ;
V_44:
F_70 ( V_103 ) ;
return V_44 ;
return 0 ;
}
static void F_264 ( struct V_63 * V_64 )
{
if ( V_64 -> type -> V_216 )
V_64 -> type -> V_216 ( V_64 ) ;
F_98 ( V_64 -> type -> V_116 ) ;
F_23 ( V_64 ) ;
}
static int F_265 ( struct V_1 * V_1 , struct V_101 * V_102 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_77 * V_78 = F_60 ( V_18 ) ;
T_3 V_68 = F_95 ( V_1 ) ;
int V_9 = V_78 -> V_80 ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_63 * V_64 ;
struct V_13 V_14 ;
T_1 V_280 ;
if ( ! V_24 [ V_391 ] ||
! V_24 [ V_392 ] )
return - V_70 ;
V_3 = F_11 ( V_1 , V_9 , true ) ;
if ( F_84 ( V_3 ) )
return F_85 ( V_3 ) ;
V_20 = F_52 ( V_3 , V_24 [ V_394 ] , V_68 ) ;
if ( F_84 ( V_20 ) )
return F_85 ( V_20 ) ;
V_280 = F_40 ( F_41 ( V_24 [ V_391 ] ) ) ;
V_64 = F_243 ( V_20 , V_24 [ V_392 ] , V_280 , V_68 ) ;
if ( F_84 ( V_64 ) )
return F_85 ( V_64 ) ;
if ( V_64 -> V_49 > 0 )
return - V_133 ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return F_48 ( & V_14 , V_64 ) ;
}
void F_266 ( struct V_1 * V_1 , struct V_19 * V_20 ,
struct V_63 * V_64 , T_1 V_25 , T_1 V_27 , int V_76 ,
int V_9 , int V_26 , T_2 V_32 )
{
struct V_15 * V_16 ;
int V_44 ;
if ( ! V_26 &&
! F_68 ( V_1 , V_88 ) )
return;
V_16 = F_69 ( V_89 , V_32 ) ;
if ( V_16 == NULL )
goto V_44;
V_44 = F_258 ( V_16 , V_1 , V_25 , V_27 , V_76 , 0 , V_9 ,
V_20 , V_64 , false ) ;
if ( V_44 < 0 ) {
F_70 ( V_16 ) ;
goto V_44;
}
F_71 ( V_16 , V_1 , V_25 , V_88 , V_26 , V_32 ) ;
return;
V_44:
F_72 ( V_1 , V_25 , V_88 , - V_90 ) ;
}
static void F_267 ( const struct V_13 * V_14 ,
struct V_63 * V_64 , int V_76 )
{
F_266 ( V_14 -> V_1 , V_14 -> V_20 , V_64 , V_14 -> V_25 , V_14 -> V_27 , V_76 ,
V_14 -> V_3 -> V_9 , V_14 -> V_26 , V_34 ) ;
}
static int F_268 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_25 , T_1 V_27 )
{
struct V_17 * V_18 ;
struct V_77 * V_78 ;
int V_76 = ( V_5 << 8 ) | V_401 ;
V_18 = F_59 ( V_16 , V_25 , V_27 , V_76 , sizeof( struct V_77 ) , 0 ) ;
if ( V_18 == NULL )
goto V_79;
V_78 = F_60 ( V_18 ) ;
V_78 -> V_80 = V_131 ;
V_78 -> V_81 = V_82 ;
V_78 -> V_83 = F_61 ( V_1 -> V_7 . V_84 & 0xffff ) ;
if ( F_63 ( V_16 , V_402 , F_64 ( V_1 -> V_7 . V_84 ) ) )
goto V_79;
F_65 ( V_16 , V_18 ) ;
return 0 ;
V_79:
F_66 ( V_16 , V_18 ) ;
return - V_346 ;
}
static void F_269 ( struct V_1 * V_1 , struct V_15 * V_16 ,
int V_76 )
{
struct V_17 * V_18 = F_79 ( V_16 ) ;
struct V_15 * V_103 ;
int V_44 ;
if ( F_17 ( V_18 ) &&
! F_68 ( V_1 , V_88 ) )
return;
V_103 = F_69 ( V_89 , V_34 ) ;
if ( V_103 == NULL )
goto V_44;
V_44 = F_268 ( V_103 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 ) ;
if ( V_44 < 0 ) {
F_70 ( V_103 ) ;
goto V_44;
}
F_71 ( V_103 , V_1 , F_16 ( V_16 ) . V_25 , V_88 ,
F_17 ( V_18 ) , V_34 ) ;
return;
V_44:
F_72 ( V_1 , F_16 ( V_16 ) . V_25 , V_88 ,
- V_90 ) ;
}
static int F_270 ( struct V_1 * V_1 , struct V_101 * V_102 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
struct V_15 * V_103 ;
int V_44 ;
V_103 = F_86 ( V_89 , V_34 ) ;
if ( V_103 == NULL )
return - V_41 ;
V_44 = F_268 ( V_103 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 ) ;
if ( V_44 < 0 )
goto V_44;
return F_87 ( V_102 , V_103 , F_16 ( V_16 ) . V_25 ) ;
V_44:
F_70 ( V_103 ) ;
return V_44 ;
}
static void F_271 ( struct V_29 * V_33 )
{
struct F_26 * V_153 ;
if ( F_145 ( V_33 ) [ 0 ] )
strcpy ( V_33 -> V_14 . V_22 -> V_69 , F_145 ( V_33 ) ) ;
if ( ! ( V_33 -> V_14 . V_22 -> V_36 & V_38 ) )
return;
V_153 = F_26 ( V_33 -> V_14 . V_22 ) ;
F_131 ( V_153 , F_142 ( V_33 ) ) ;
switch ( F_144 ( V_33 ) ) {
case V_190 :
case V_188 :
V_153 -> V_163 = F_144 ( V_33 ) ;
break;
}
}
static void F_272 ( struct V_29 * V_33 )
{
switch ( V_33 -> V_30 ) {
case V_45 :
F_104 ( & V_33 -> V_14 ) ;
break;
case V_48 :
F_136 ( V_33 -> V_14 . V_22 ) ;
break;
case V_56 :
F_169 ( & V_33 -> V_14 , V_53 ( V_33 ) ) ;
break;
case V_62 :
F_201 ( V_59 ( V_33 ) ) ;
break;
case V_378 :
F_235 ( F_232 ( V_33 ) ,
V_353 ( V_33 ) . V_198 , true ) ;
break;
case V_67 :
F_264 ( V_65 ( V_33 ) ) ;
break;
}
F_23 ( V_33 ) ;
}
static int F_273 ( struct V_1 * V_1 , struct V_15 * V_16 )
{
struct V_29 * V_33 , * V_217 ;
struct V_353 * V_403 ;
while ( ++ V_1 -> V_7 . V_84 == 0 ) ;
V_1 -> V_7 . V_404 = F_274 ( V_1 ) ;
F_134 () ;
F_100 (trans, next, &net->nft.commit_list, list) {
switch ( V_33 -> V_30 ) {
case V_42 :
if ( F_93 ( V_33 ) ) {
if ( ! F_92 ( V_33 ) ) {
F_90 ( V_1 ,
V_33 -> V_14 . V_3 ,
V_33 -> V_14 . V_20 ) ;
V_33 -> V_14 . V_20 -> V_36 |= V_37 ;
}
} else {
F_275 ( V_1 , V_33 -> V_14 . V_20 ) ;
}
F_67 ( & V_33 -> V_14 , V_42 ) ;
F_21 ( V_33 ) ;
break;
case V_45 :
F_8 ( & V_33 -> V_14 . V_20 -> V_6 ) ;
F_67 ( & V_33 -> V_14 , V_45 ) ;
break;
case V_47 :
if ( F_143 ( V_33 ) )
F_271 ( V_33 ) ;
else
F_275 ( V_1 , V_33 -> V_14 . V_22 ) ;
F_120 ( & V_33 -> V_14 , V_47 ) ;
F_21 ( V_33 ) ;
break;
case V_48 :
F_8 ( & V_33 -> V_14 . V_22 -> V_6 ) ;
F_120 ( & V_33 -> V_14 , V_48 ) ;
F_27 ( V_33 -> V_14 . V_1 ,
V_33 -> V_14 . V_20 ,
V_33 -> V_14 . V_22 ,
V_33 -> V_14 . V_3 -> V_110 ) ;
break;
case V_54 :
F_275 ( V_33 -> V_14 . V_1 , V_53 ( V_33 ) ) ;
F_165 ( & V_33 -> V_14 ,
V_53 ( V_33 ) ,
V_54 ) ;
F_21 ( V_33 ) ;
break;
case V_56 :
F_8 ( & V_53 ( V_33 ) -> V_6 ) ;
F_165 ( & V_33 -> V_14 ,
V_53 ( V_33 ) ,
V_56 ) ;
break;
case V_60 :
F_275 ( V_1 , V_59 ( V_33 ) ) ;
if ( V_59 ( V_33 ) -> V_36 & V_128 &&
! F_101 ( & V_59 ( V_33 ) -> V_129 ) )
V_33 -> V_14 . V_20 -> V_49 -- ;
F_193 ( & V_33 -> V_14 , V_59 ( V_33 ) ,
V_60 , V_34 ) ;
F_21 ( V_33 ) ;
break;
case V_62 :
F_8 ( & V_59 ( V_33 ) -> V_6 ) ;
F_193 ( & V_33 -> V_14 , V_59 ( V_33 ) ,
V_62 , V_34 ) ;
break;
case V_351 :
V_403 = (struct V_353 * ) V_33 -> V_206 ;
V_403 -> V_58 -> V_39 -> V_405 ( V_1 , V_403 -> V_58 , & V_403 -> V_313 ) ;
F_230 ( & V_33 -> V_14 , V_403 -> V_58 ,
& V_403 -> V_313 ,
V_351 , 0 ) ;
F_21 ( V_33 ) ;
break;
case V_378 :
V_403 = (struct V_353 * ) V_33 -> V_206 ;
F_230 ( & V_33 -> V_14 , V_403 -> V_58 ,
& V_403 -> V_313 ,
V_378 , 0 ) ;
V_403 -> V_58 -> V_39 -> remove ( V_1 , V_403 -> V_58 , & V_403 -> V_313 ) ;
F_276 ( & V_403 -> V_58 -> V_374 ) ;
V_403 -> V_58 -> V_375 -- ;
break;
case V_66 :
F_275 ( V_1 , V_65 ( V_33 ) ) ;
F_267 ( & V_33 -> V_14 , V_65 ( V_33 ) ,
V_66 ) ;
F_21 ( V_33 ) ;
break;
case V_67 :
F_8 ( & V_65 ( V_33 ) -> V_6 ) ;
F_267 ( & V_33 -> V_14 , V_65 ( V_33 ) ,
V_67 ) ;
break;
}
}
F_134 () ;
F_100 (trans, next, &net->nft.commit_list, list) {
F_22 ( & V_33 -> V_6 ) ;
F_272 ( V_33 ) ;
}
F_269 ( V_1 , V_16 , V_401 ) ;
return 0 ;
}
static void F_277 ( struct V_29 * V_33 )
{
switch ( V_33 -> V_30 ) {
case V_42 :
F_104 ( & V_33 -> V_14 ) ;
break;
case V_47 :
F_136 ( V_33 -> V_14 . V_22 ) ;
break;
case V_54 :
F_169 ( & V_33 -> V_14 , V_53 ( V_33 ) ) ;
break;
case V_60 :
F_201 ( V_59 ( V_33 ) ) ;
break;
case V_351 :
F_235 ( F_232 ( V_33 ) ,
V_353 ( V_33 ) . V_198 , true ) ;
break;
case V_66 :
F_264 ( V_65 ( V_33 ) ) ;
break;
}
F_23 ( V_33 ) ;
}
static int F_278 ( struct V_1 * V_1 , struct V_15 * V_16 )
{
struct V_29 * V_33 , * V_217 ;
struct V_353 * V_403 ;
F_279 (trans, next, &net->nft.commit_list,
list) {
switch ( V_33 -> V_30 ) {
case V_42 :
if ( F_93 ( V_33 ) ) {
if ( F_92 ( V_33 ) ) {
F_90 ( V_1 ,
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
F_275 ( V_33 -> V_14 . V_1 , V_33 -> V_14 . V_20 ) ;
F_21 ( V_33 ) ;
break;
case V_47 :
if ( F_143 ( V_33 ) ) {
F_135 ( F_142 ( V_33 ) ) ;
F_21 ( V_33 ) ;
} else {
V_33 -> V_14 . V_20 -> V_49 -- ;
F_8 ( & V_33 -> V_14 . V_22 -> V_6 ) ;
F_27 ( V_33 -> V_14 . V_1 ,
V_33 -> V_14 . V_20 ,
V_33 -> V_14 . V_22 ,
V_33 -> V_14 . V_3 -> V_110 ) ;
}
break;
case V_48 :
V_33 -> V_14 . V_20 -> V_49 ++ ;
F_275 ( V_33 -> V_14 . V_1 , V_33 -> V_14 . V_22 ) ;
F_21 ( V_33 ) ;
break;
case V_54 :
V_33 -> V_14 . V_22 -> V_49 -- ;
F_8 ( & V_53 ( V_33 ) -> V_6 ) ;
break;
case V_56 :
V_33 -> V_14 . V_22 -> V_49 ++ ;
F_275 ( V_33 -> V_14 . V_1 , V_53 ( V_33 ) ) ;
F_21 ( V_33 ) ;
break;
case V_60 :
V_33 -> V_14 . V_20 -> V_49 -- ;
F_8 ( & V_59 ( V_33 ) -> V_6 ) ;
break;
case V_62 :
V_33 -> V_14 . V_20 -> V_49 ++ ;
F_275 ( V_33 -> V_14 . V_1 , V_59 ( V_33 ) ) ;
F_21 ( V_33 ) ;
break;
case V_351 :
V_403 = (struct V_353 * ) V_33 -> V_206 ;
V_403 -> V_58 -> V_39 -> remove ( V_1 , V_403 -> V_58 , & V_403 -> V_313 ) ;
F_276 ( & V_403 -> V_58 -> V_374 ) ;
break;
case V_378 :
V_403 = (struct V_353 * ) V_33 -> V_206 ;
V_403 -> V_58 -> V_39 -> V_405 ( V_1 , V_403 -> V_58 , & V_403 -> V_313 ) ;
V_403 -> V_58 -> V_375 -- ;
F_21 ( V_33 ) ;
break;
case V_66 :
V_33 -> V_14 . V_20 -> V_49 -- ;
F_8 ( & V_65 ( V_33 ) -> V_6 ) ;
break;
case V_67 :
V_33 -> V_14 . V_20 -> V_49 ++ ;
F_275 ( V_33 -> V_14 . V_1 , V_65 ( V_33 ) ) ;
F_21 ( V_33 ) ;
break;
}
}
F_134 () ;
F_279 (trans, next,
&net->nft.commit_list, list) {
F_22 ( & V_33 -> V_6 ) ;
F_277 ( V_33 ) ;
}
return 0 ;
}
static bool F_280 ( struct V_1 * V_1 , T_1 V_406 )
{
return V_1 -> V_7 . V_84 == V_406 ;
}
int F_281 ( const struct V_21 * V_22 ,
enum V_407 type )
{
const struct F_26 * V_153 ;
if ( V_22 -> V_36 & V_38 ) {
V_153 = F_26 ( V_22 ) ;
if ( V_153 -> type -> type != type )
return - V_115 ;
}
return 0 ;
}
int F_282 ( const struct V_21 * V_22 ,
unsigned int V_408 )
{
struct F_26 * V_153 ;
if ( V_22 -> V_36 & V_38 ) {
V_153 = F_26 ( V_22 ) ;
if ( ( 1 << V_153 -> V_39 [ 0 ] . V_157 ) & V_408 )
return 0 ;
return - V_115 ;
}
return 0 ;
}
static int F_283 ( const struct V_13 * V_14 ,
struct V_57 * V_58 ,
const struct V_310 * V_311 ,
struct V_312 * V_313 )
{
const struct V_314 * V_315 = F_205 ( V_58 , V_313 -> V_198 ) ;
const struct V_365 * V_206 ;
if ( F_216 ( V_315 , V_334 ) &&
* F_219 ( V_315 ) & V_359 )
return 0 ;
V_206 = F_208 ( V_315 ) ;
switch ( V_206 -> V_409 . V_410 ) {
case V_411 :
case V_412 :
return F_284 ( V_14 , V_206 -> V_409 . V_22 ) ;
default:
return 0 ;
}
}
static int F_284 ( const struct V_13 * V_14 ,
const struct V_21 * V_22 )
{
const struct V_50 * V_51 ;
const struct V_203 * V_204 , * V_413 ;
struct V_57 * V_58 ;
struct V_318 * V_319 ;
struct V_310 V_311 ;
if ( V_14 -> V_22 == V_22 )
return - V_414 ;
F_10 (rule, &chain->rules, list) {
F_163 (expr, last, rule) {
const struct V_365 * V_206 = NULL ;
int V_44 ;
if ( ! V_204 -> V_39 -> V_415 )
continue;
V_44 = V_204 -> V_39 -> V_415 ( V_14 , V_204 , & V_206 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_206 == NULL )
continue;
switch ( V_206 -> V_409 . V_410 ) {
case V_411 :
case V_412 :
V_44 = F_284 ( V_14 ,
V_206 -> V_409 . V_22 ) ;
if ( V_44 < 0 )
return V_44 ;
default:
break;
}
}
}
F_10 (set, &ctx->table->sets, list) {
if ( ! F_37 ( V_14 -> V_1 , V_58 ) )
continue;
if ( ! ( V_58 -> V_36 & V_255 ) ||
V_58 -> V_277 != V_304 )
continue;
F_10 (binding, &set->bindings, list) {
if ( ! ( V_319 -> V_36 & V_255 ) ||
V_319 -> V_22 != V_22 )
continue;
V_311 . V_68 = F_95 ( V_14 -> V_1 ) ;
V_311 . V_321 = 0 ;
V_311 . V_322 = 0 ;
V_311 . V_44 = 0 ;
V_311 . V_323 = F_283 ;
V_58 -> V_39 -> V_324 ( V_14 , V_58 , & V_311 ) ;
if ( V_311 . V_44 < 0 )
return V_311 . V_44 ;
}
}
return 0 ;
}
int F_285 ( const struct V_23 * V_166 , int V_416 , T_1 * V_417 )
{
T_1 V_367 ;
V_367 = F_40 ( F_41 ( V_166 ) ) ;
if ( V_367 > V_416 )
return - V_418 ;
* V_417 = V_367 ;
return 0 ;
}
unsigned int F_286 ( const struct V_23 * V_166 )
{
unsigned int V_419 ;
V_419 = F_40 ( F_41 ( V_166 ) ) ;
switch ( V_419 ) {
case V_420 ... V_421 :
return V_419 * V_422 / V_423 ;
default:
return V_419 + V_422 / V_423 - V_424 ;
}
}
int F_287 ( struct V_15 * V_16 , unsigned int V_166 , unsigned int V_419 )
{
if ( V_419 % ( V_422 / V_423 ) == 0 )
V_419 = V_419 / ( V_422 / V_423 ) ;
else
V_419 = V_419 - V_422 / V_423 + V_424 ;
return F_63 ( V_16 , V_166 , F_64 ( V_419 ) ) ;
}
int F_288 ( enum V_316 V_419 , unsigned int V_100 )
{
if ( V_419 < V_425 * V_422 / V_423 )
return - V_70 ;
if ( V_100 == 0 )
return - V_70 ;
if ( V_419 * V_423 + V_100 > F_289 ( struct V_426 , V_206 ) )
return - V_418 ;
return 0 ;
}
int F_207 ( const struct V_13 * V_14 ,
enum V_316 V_419 ,
const struct V_365 * V_206 ,
enum V_427 type , unsigned int V_100 )
{
int V_44 ;
switch ( V_419 ) {
case V_420 :
if ( type != V_304 )
return - V_70 ;
if ( V_206 != NULL &&
( V_206 -> V_409 . V_410 == V_412 ||
V_206 -> V_409 . V_410 == V_411 ) ) {
V_44 = F_284 ( V_14 , V_206 -> V_409 . V_22 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_14 -> V_22 -> V_428 + 1 >
V_206 -> V_409 . V_22 -> V_428 ) {
if ( V_14 -> V_22 -> V_428 + 1 == V_429 )
return - V_430 ;
V_206 -> V_409 . V_22 -> V_428 = V_14 -> V_22 -> V_428 + 1 ;
}
}
return 0 ;
default:
if ( V_419 < V_425 * V_422 / V_423 )
return - V_70 ;
if ( V_100 == 0 )
return - V_70 ;
if ( V_419 * V_423 + V_100 >
F_289 ( struct V_426 , V_206 ) )
return - V_418 ;
if ( V_206 != NULL && type != V_299 )
return - V_70 ;
return 0 ;
}
}
static int F_290 ( const struct V_13 * V_14 , struct V_365 * V_206 ,
struct V_361 * V_246 , const struct V_23 * V_24 )
{
T_3 V_68 = F_95 ( V_14 -> V_1 ) ;
struct V_23 * V_167 [ V_431 + 1 ] ;
struct V_21 * V_22 ;
int V_44 ;
V_44 = F_124 ( V_167 , V_431 , V_24 , V_432 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( ! V_167 [ V_433 ] )
return - V_70 ;
V_206 -> V_409 . V_410 = F_40 ( F_41 ( V_167 [ V_433 ] ) ) ;
switch ( V_206 -> V_409 . V_410 ) {
default:
switch ( V_206 -> V_409 . V_410 & V_434 ) {
case V_188 :
case V_190 :
case V_435 :
break;
default:
return - V_70 ;
}
case V_436 :
case V_437 :
case V_438 :
break;
case V_411 :
case V_412 :
if ( ! V_167 [ V_439 ] )
return - V_70 ;
V_22 = F_109 ( V_14 -> V_20 ,
V_167 [ V_439 ] , V_68 ) ;
if ( F_84 ( V_22 ) )
return F_85 ( V_22 ) ;
if ( V_22 -> V_36 & V_38 )
return - V_115 ;
V_22 -> V_49 ++ ;
V_206 -> V_409 . V_22 = V_22 ;
break;
}
V_246 -> V_100 = sizeof( V_206 -> V_409 ) ;
V_246 -> type = V_304 ;
return 0 ;
}
static void F_291 ( const struct V_365 * V_206 )
{
switch ( V_206 -> V_409 . V_410 ) {
case V_411 :
case V_412 :
V_206 -> V_409 . V_22 -> V_49 -- ;
break;
}
}
int F_292 ( struct V_15 * V_16 , int type , const struct V_305 * V_440 )
{
struct V_23 * V_139 ;
V_139 = F_115 ( V_16 , type ) ;
if ( ! V_139 )
goto V_79;
if ( F_63 ( V_16 , V_433 , F_64 ( V_440 -> V_410 ) ) )
goto V_79;
switch ( V_440 -> V_410 ) {
case V_411 :
case V_412 :
if ( F_62 ( V_16 , V_439 ,
V_440 -> V_22 -> V_69 ) )
goto V_79;
}
F_118 ( V_16 , V_139 ) ;
return 0 ;
V_79:
return - 1 ;
}
static int F_293 ( const struct V_13 * V_14 ,
struct V_365 * V_206 , unsigned int V_31 ,
struct V_361 * V_246 , const struct V_23 * V_24 )
{
unsigned int V_100 ;
V_100 = F_56 ( V_24 ) ;
if ( V_100 == 0 )
return - V_70 ;
if ( V_100 > V_31 )
return - V_194 ;
F_176 ( V_206 -> V_206 , V_24 , V_100 ) ;
V_246 -> type = V_299 ;
V_246 -> V_100 = V_100 ;
return 0 ;
}
static int F_294 ( struct V_15 * V_16 , const struct V_365 * V_206 ,
unsigned int V_100 )
{
return F_164 ( V_16 , V_441 , V_100 , V_206 -> V_206 ) ;
}
int F_241 ( const struct V_13 * V_14 ,
struct V_365 * V_206 , unsigned int V_31 ,
struct V_361 * V_246 , const struct V_23 * V_24 )
{
struct V_23 * V_167 [ V_442 + 1 ] ;
int V_44 ;
V_44 = F_124 ( V_167 , V_442 , V_24 , V_443 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_167 [ V_441 ] )
return F_293 ( V_14 , V_206 , V_31 , V_246 ,
V_167 [ V_441 ] ) ;
if ( V_167 [ V_444 ] && V_14 != NULL )
return F_290 ( V_14 , V_206 , V_246 , V_167 [ V_444 ] ) ;
return - V_70 ;
}
void F_236 ( const struct V_365 * V_206 , enum V_427 type )
{
if ( type < V_304 )
return;
switch ( type ) {
case V_304 :
return F_291 ( V_206 ) ;
default:
F_295 ( 1 ) ;
}
}
int F_214 ( struct V_15 * V_16 , int V_166 , const struct V_365 * V_206 ,
enum V_427 type , unsigned int V_100 )
{
struct V_23 * V_139 ;
int V_44 ;
V_139 = F_115 ( V_16 , V_166 ) ;
if ( V_139 == NULL )
return - 1 ;
switch ( type ) {
case V_299 :
V_44 = F_294 ( V_16 , V_206 , V_100 ) ;
break;
case V_304 :
V_44 = F_292 ( V_16 , V_444 , & V_206 -> V_409 ) ;
break;
default:
V_44 = - V_70 ;
F_295 ( 1 ) ;
}
F_118 ( V_16 , V_139 ) ;
return V_44 ;
}
static int T_8 F_296 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_7 . V_8 ) ;
F_2 ( & V_1 -> V_7 . V_43 ) ;
V_1 -> V_7 . V_84 = 1 ;
return 0 ;
}
int F_297 ( struct V_13 * V_14 )
{
struct V_50 * V_51 , * V_445 ;
F_105 ( ! ( V_14 -> V_22 -> V_36 & V_38 ) ) ;
F_27 ( V_14 -> V_1 , V_14 -> V_22 -> V_20 , V_14 -> V_22 ,
V_14 -> V_3 -> V_110 ) ;
F_100 (rule, nr, &ctx->chain->rules, list) {
F_22 ( & V_51 -> V_6 ) ;
V_14 -> V_22 -> V_49 -- ;
F_169 ( V_14 , V_51 ) ;
}
F_22 ( & V_14 -> V_22 -> V_6 ) ;
V_14 -> V_20 -> V_49 -- ;
F_136 ( V_14 -> V_22 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_19 * V_20 , * V_130 ;
struct V_21 * V_22 , * V_124 ;
struct V_63 * V_64 , * V_125 ;
struct V_50 * V_51 , * V_445 ;
struct V_57 * V_58 , * V_126 ;
struct V_13 V_14 = {
. V_1 = V_1 ,
. V_3 = V_3 ,
} ;
F_100 (table, nt, &afi->tables, list) {
F_10 (chain, &table->chains, list)
F_27 ( V_1 , V_20 , V_22 ,
V_3 -> V_110 ) ;
V_14 . V_20 = V_20 ;
F_10 (chain, &table->chains, list) {
V_14 . V_22 = V_22 ;
F_100 (rule, nr, &chain->rules, list) {
F_22 ( & V_51 -> V_6 ) ;
V_22 -> V_49 -- ;
F_169 ( & V_14 , V_51 ) ;
}
}
F_100 (set, ns, &table->sets, list) {
F_22 ( & V_58 -> V_6 ) ;
V_20 -> V_49 -- ;
F_201 ( V_58 ) ;
}
F_100 (obj, ne, &table->objects, list) {
F_22 ( & V_64 -> V_6 ) ;
V_20 -> V_49 -- ;
F_264 ( V_64 ) ;
}
F_100 (chain, nc, &table->chains, list) {
F_22 ( & V_22 -> V_6 ) ;
V_20 -> V_49 -- ;
F_136 ( V_22 ) ;
}
F_22 ( & V_20 -> V_6 ) ;
F_104 ( & V_14 ) ;
}
}
static int T_9 F_298 ( void )
{
int V_44 ;
V_209 = F_197 ( sizeof( struct V_208 ) * V_239 ,
V_34 ) ;
if ( V_209 == NULL ) {
V_44 = - V_41 ;
goto V_117;
}
V_44 = F_299 () ;
if ( V_44 < 0 )
goto V_118;
V_44 = F_300 ( & V_446 ) ;
if ( V_44 < 0 )
goto V_123;
F_301 ( L_7 ) ;
return F_302 ( & V_447 ) ;
V_123:
F_303 () ;
V_118:
F_23 ( V_209 ) ;
V_117:
return V_44 ;
}
static void T_10 F_304 ( void )
{
F_305 ( & V_447 ) ;
F_306 ( & V_446 ) ;
F_307 () ;
F_303 () ;
F_23 ( V_209 ) ;
}
