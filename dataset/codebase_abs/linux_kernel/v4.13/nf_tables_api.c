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
const struct V_23 * const V_24 [] ,
struct V_102 * V_103 )
{
const struct V_76 * V_77 = F_62 ( V_18 ) ;
T_3 V_67 = F_84 ( V_1 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
struct V_15 * V_104 ;
int V_9 = V_77 -> V_79 ;
int V_43 ;
if ( V_18 -> V_105 & V_106 ) {
struct V_107 V_108 = {
. V_109 = F_75 ,
} ;
return F_85 ( V_101 , V_16 , V_18 , & V_108 ) ;
}
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_86 ( V_3 ) )
return F_87 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_84 ] , V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
V_104 = F_88 ( V_88 , V_34 ) ;
if ( ! V_104 )
return - V_40 ;
V_43 = F_59 ( V_104 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 , V_41 , 0 ,
V_9 , V_20 ) ;
if ( V_43 < 0 )
goto V_43;
return F_89 ( V_101 , V_104 , F_16 ( V_16 ) . V_25 ) ;
V_43:
F_72 ( V_104 ) ;
return V_43 ;
}
static void F_90 ( struct V_1 * V_1 ,
const struct V_2 * V_3 ,
struct V_19 * V_20 ,
T_1 V_110 )
{
struct V_21 * V_22 ;
T_1 V_72 = 0 ;
F_10 (chain, &table->chains, list) {
if ( ! F_38 ( V_1 , V_22 ) )
continue;
if ( ! F_25 ( V_22 ) )
continue;
if ( V_110 && V_72 ++ == V_110 )
break;
F_29 ( V_1 , F_27 ( V_22 ) -> V_38 ,
V_3 -> V_111 ) ;
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
V_3 -> V_111 ) ;
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
int V_112 = 0 ;
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
V_112 = F_91 ( V_14 -> V_1 , V_14 -> V_3 , V_14 -> V_20 ) ;
if ( V_112 >= 0 ) {
V_14 -> V_20 -> V_36 &= ~ V_37 ;
F_94 ( V_33 ) = true ;
}
}
if ( V_112 < 0 )
goto V_43;
F_95 ( V_33 ) = true ;
F_32 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_42 ) ;
return 0 ;
V_43:
F_21 ( V_33 ) ;
return V_112 ;
}
static int F_96 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
struct V_102 * V_103 )
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
if ( V_18 -> V_105 & V_113 )
return - V_114 ;
if ( V_18 -> V_105 & V_115 )
return - V_116 ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return F_93 ( & V_14 ) ;
}
if ( V_24 [ V_85 ] ) {
V_36 = F_41 ( F_42 ( V_24 [ V_85 ] ) ) ;
if ( V_36 & ~ V_37 )
return - V_69 ;
}
V_43 = - V_12 ;
if ( ! F_98 ( V_3 -> V_117 ) )
goto V_118;
V_43 = - V_40 ;
V_20 = F_19 ( sizeof( * V_20 ) , V_34 ) ;
if ( V_20 == NULL )
goto V_119;
F_99 ( V_20 -> V_68 , V_68 , V_120 ) ;
F_2 ( & V_20 -> V_121 ) ;
F_2 ( & V_20 -> V_122 ) ;
F_2 ( & V_20 -> V_123 ) ;
V_20 -> V_36 = V_36 ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
V_43 = F_30 ( & V_14 , V_41 ) ;
if ( V_43 < 0 )
goto V_124;
F_4 ( & V_20 -> V_6 , & V_3 -> V_4 ) ;
return 0 ;
V_124:
F_23 ( V_20 ) ;
V_119:
F_100 ( V_3 -> V_117 ) ;
V_118:
return V_43 ;
}
static int F_101 ( struct V_13 * V_14 )
{
int V_43 ;
struct V_21 * V_22 , * V_125 ;
struct V_62 * V_63 , * V_126 ;
struct V_56 * V_57 , * V_127 ;
F_10 (chain, &ctx->table->chains, list) {
if ( ! F_38 ( V_14 -> V_1 , V_22 ) )
continue;
V_14 -> V_22 = V_22 ;
V_43 = F_44 ( V_14 ) ;
if ( V_43 < 0 )
goto V_128;
}
F_102 (set, ns, &ctx->table->sets, list) {
if ( ! F_38 ( V_14 -> V_1 , V_57 ) )
continue;
if ( V_57 -> V_36 & V_129 &&
! F_103 ( & V_57 -> V_130 ) )
continue;
V_43 = F_47 ( V_14 , V_57 ) ;
if ( V_43 < 0 )
goto V_128;
}
F_102 (obj, ne, &ctx->table->objects, list) {
V_43 = F_49 ( V_14 , V_63 ) ;
if ( V_43 < 0 )
goto V_128;
}
F_102 (chain, nc, &ctx->table->chains, list) {
if ( ! F_38 ( V_14 -> V_1 , V_22 ) )
continue;
V_14 -> V_22 = V_22 ;
V_43 = F_36 ( V_14 ) ;
if ( V_43 < 0 )
goto V_128;
}
V_43 = F_33 ( V_14 ) ;
V_128:
return V_43 ;
}
static int F_104 ( struct V_13 * V_14 , int V_9 )
{
struct V_2 * V_3 ;
struct V_19 * V_20 , * V_131 ;
const struct V_23 * const * V_24 = V_14 -> V_24 ;
int V_43 = 0 ;
F_10 (afi, &ctx->net->nft.af_info, list) {
if ( V_9 != V_132 && V_3 -> V_9 != V_9 )
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
goto V_128;
}
}
V_128:
return V_43 ;
}
static int F_105 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
struct V_102 * V_103 )
{
const struct V_76 * V_77 = F_62 ( V_18 ) ;
T_3 V_67 = F_97 ( V_1 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
int V_9 = V_77 -> V_79 ;
struct V_13 V_14 ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , NULL , NULL , NULL , V_24 ) ;
if ( V_9 == V_132 || V_24 [ V_84 ] == NULL )
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
F_100 ( V_14 -> V_3 -> V_117 ) ;
}
int F_108 ( const struct V_71 * V_133 )
{
int V_43 = 0 ;
if ( F_109 ( V_133 -> V_9 >= V_134 ) )
return - V_69 ;
F_3 ( V_5 ) ;
if ( V_74 [ V_133 -> V_9 ] [ V_133 -> type ] != NULL ) {
V_43 = - V_135 ;
goto V_128;
}
V_74 [ V_133 -> V_9 ] [ V_133 -> type ] = V_133 ;
V_128:
F_5 ( V_5 ) ;
return V_43 ;
}
void F_110 ( const struct V_71 * V_133 )
{
F_3 ( V_5 ) ;
V_74 [ V_133 -> V_9 ] [ V_133 -> type ] = NULL ;
F_5 ( V_5 ) ;
}
static struct V_21 *
F_111 ( const struct V_19 * V_20 , T_4 V_136 ,
T_3 V_67 )
{
struct V_21 * V_22 ;
F_10 (chain, &table->chains, list) {
if ( V_22 -> V_136 == V_136 &&
F_52 ( V_22 , V_67 ) )
return V_22 ;
}
return F_14 ( - V_51 ) ;
}
static struct V_21 * F_112 ( const struct V_19 * V_20 ,
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
static int F_113 ( struct V_15 * V_16 , struct V_137 T_5 * V_138 )
{
struct V_137 * V_139 , V_140 ;
struct V_23 * V_141 ;
unsigned int V_27 ;
T_4 V_142 , V_143 ;
int V_144 ;
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
F_114 (cpu) {
V_139 = F_115 ( V_138 , V_144 ) ;
do {
V_27 = F_116 ( & V_139 -> V_145 ) ;
V_142 = V_139 -> V_142 ;
V_143 = V_139 -> V_143 ;
} while ( F_117 ( & V_139 -> V_145 , V_27 ) );
V_140 . V_142 += V_142 ;
V_140 . V_143 += V_143 ;
}
V_141 = F_118 ( V_16 , V_146 ) ;
if ( V_141 == NULL )
goto V_78;
if ( F_119 ( V_16 , V_147 , F_120 ( V_140 . V_142 ) ,
V_148 ) ||
F_119 ( V_16 , V_149 , F_120 ( V_140 . V_143 ) ,
V_148 ) )
goto V_78;
F_121 ( V_16 , V_141 ) ;
return 0 ;
V_78:
return - V_150 ;
}
static int F_122 ( struct V_15 * V_16 , struct V_1 * V_1 ,
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
if ( F_64 ( V_16 , V_151 , V_20 -> V_68 ) )
goto V_78;
if ( F_119 ( V_16 , V_152 , F_120 ( V_22 -> V_136 ) ,
V_153 ) )
goto V_78;
if ( F_64 ( V_16 , V_154 , V_22 -> V_68 ) )
goto V_78;
if ( F_25 ( V_22 ) ) {
const struct F_27 * V_155 = F_27 ( V_22 ) ;
const struct V_156 * V_38 = & V_155 -> V_38 [ 0 ] ;
struct V_23 * V_141 ;
V_141 = F_118 ( V_16 , V_157 ) ;
if ( V_141 == NULL )
goto V_78;
if ( F_65 ( V_16 , V_158 , F_66 ( V_38 -> V_159 ) ) )
goto V_78;
if ( F_65 ( V_16 , V_160 , F_66 ( V_38 -> V_161 ) ) )
goto V_78;
if ( V_155 -> V_162 [ 0 ] &&
F_64 ( V_16 , V_163 , V_155 -> V_162 ) )
goto V_78;
F_121 ( V_16 , V_141 ) ;
if ( F_65 ( V_16 , V_164 ,
F_66 ( V_155 -> V_165 ) ) )
goto V_78;
if ( F_64 ( V_16 , V_166 , V_155 -> type -> V_68 ) )
goto V_78;
if ( F_113 ( V_16 , F_27 ( V_22 ) -> V_138 ) )
goto V_78;
}
if ( F_65 ( V_16 , V_167 , F_66 ( V_22 -> V_48 ) ) )
goto V_78;
F_67 ( V_16 , V_18 ) ;
return 0 ;
V_78:
F_68 ( V_16 , V_18 ) ;
return - 1 ;
}
static void F_123 ( const struct V_13 * V_14 , int V_75 )
{
struct V_15 * V_16 ;
int V_43 ;
if ( ! V_14 -> V_26 &&
! F_70 ( V_14 -> V_1 , V_87 ) )
return;
V_16 = F_71 ( V_88 , V_34 ) ;
if ( V_16 == NULL )
goto V_43;
V_43 = F_122 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_14 -> V_27 ,
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
static int F_124 ( struct V_15 * V_16 ,
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
if ( F_122 ( V_16 , V_1 ,
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
static int F_125 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
struct V_102 * V_103 )
{
const struct V_76 * V_77 = F_62 ( V_18 ) ;
T_3 V_67 = F_84 ( V_1 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
struct V_15 * V_104 ;
int V_9 = V_77 -> V_79 ;
int V_43 ;
if ( V_18 -> V_105 & V_106 ) {
struct V_107 V_108 = {
. V_109 = F_124 ,
} ;
return F_85 ( V_101 , V_16 , V_18 , & V_108 ) ;
}
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_86 ( V_3 ) )
return F_87 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_151 ] , V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
V_22 = F_112 ( V_20 , V_24 [ V_154 ] , V_67 ) ;
if ( F_86 ( V_22 ) )
return F_87 ( V_22 ) ;
V_104 = F_88 ( V_88 , V_34 ) ;
if ( ! V_104 )
return - V_40 ;
V_43 = F_122 ( V_104 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 , V_46 , 0 ,
V_9 , V_20 , V_22 ) ;
if ( V_43 < 0 )
goto V_43;
return F_89 ( V_101 , V_104 , F_16 ( V_16 ) . V_25 ) ;
V_43:
F_72 ( V_104 ) ;
return V_43 ;
}
static struct V_137 T_5 * F_126 ( const struct V_23 * V_168 )
{
struct V_23 * V_169 [ V_170 + 1 ] ;
struct V_137 T_5 * V_171 ;
struct V_137 * V_138 ;
int V_43 ;
V_43 = F_127 ( V_169 , V_170 , V_168 , V_172 ,
NULL ) ;
if ( V_43 < 0 )
return F_14 ( V_43 ) ;
if ( ! V_169 [ V_149 ] || ! V_169 [ V_147 ] )
return F_14 ( - V_69 ) ;
V_171 = F_128 ( struct V_137 ) ;
if ( V_171 == NULL )
return F_14 ( - V_40 ) ;
F_129 () ;
V_138 = F_130 ( V_171 ) ;
V_138 -> V_143 = F_131 ( F_132 ( V_169 [ V_149 ] ) ) ;
V_138 -> V_142 = F_131 ( F_132 ( V_169 [ V_147 ] ) ) ;
F_133 () ;
return V_171 ;
}
static void F_134 ( struct F_27 * V_22 ,
struct V_137 T_5 * V_171 )
{
if ( V_171 == NULL )
return;
if ( V_22 -> V_138 ) {
struct V_137 T_5 * V_173 =
F_135 ( V_22 -> V_138 ) ;
F_136 ( V_22 -> V_138 , V_171 ) ;
F_137 () ;
F_138 ( V_173 ) ;
} else
F_136 ( V_22 -> V_138 , V_171 ) ;
}
static void F_139 ( struct V_21 * V_22 )
{
F_107 ( V_22 -> V_48 > 0 ) ;
if ( F_25 ( V_22 ) ) {
struct F_27 * V_155 = F_27 ( V_22 ) ;
F_100 ( V_155 -> type -> V_117 ) ;
F_138 ( V_155 -> V_138 ) ;
if ( V_155 -> V_38 [ 0 ] . V_174 != NULL )
F_140 ( V_155 -> V_38 [ 0 ] . V_174 ) ;
F_23 ( V_155 ) ;
} else {
F_23 ( V_22 ) ;
}
}
static int F_141 ( struct V_1 * V_1 ,
const struct V_23 * const V_24 [] ,
struct V_2 * V_3 ,
struct V_175 * V_176 , bool V_177 )
{
struct V_23 * V_178 [ V_179 + 1 ] ;
const struct V_71 * type ;
struct V_180 * V_174 ;
int V_43 ;
V_43 = F_127 ( V_178 , V_179 , V_24 [ V_157 ] ,
V_181 , NULL ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_178 [ V_158 ] == NULL ||
V_178 [ V_160 ] == NULL )
return - V_69 ;
V_176 -> V_182 = F_41 ( F_42 ( V_178 [ V_158 ] ) ) ;
if ( V_176 -> V_182 >= V_3 -> V_183 )
return - V_69 ;
V_176 -> V_161 = F_41 ( F_42 ( V_178 [ V_160 ] ) ) ;
type = V_74 [ V_3 -> V_9 ] [ V_184 ] ;
if ( V_24 [ V_166 ] ) {
type = F_56 ( V_3 , V_24 [ V_166 ] ,
V_177 ) ;
if ( F_86 ( type ) )
return F_87 ( type ) ;
}
if ( ! ( type -> V_185 & ( 1 << V_176 -> V_182 ) ) )
return - V_116 ;
if ( ! F_98 ( type -> V_117 ) )
return - V_51 ;
V_176 -> type = type ;
V_176 -> V_174 = NULL ;
if ( V_3 -> V_36 & V_186 ) {
char V_187 [ V_188 ] ;
if ( ! V_178 [ V_163 ] ) {
F_100 ( type -> V_117 ) ;
return - V_116 ;
}
F_99 ( V_187 , V_178 [ V_163 ] , V_188 ) ;
V_174 = F_142 ( V_1 , V_187 ) ;
if ( ! V_174 ) {
F_100 ( type -> V_117 ) ;
return - V_51 ;
}
V_176 -> V_174 = V_174 ;
} else if ( V_178 [ V_163 ] ) {
F_100 ( type -> V_117 ) ;
return - V_116 ;
}
return 0 ;
}
static void F_143 ( struct V_175 * V_176 )
{
F_100 ( V_176 -> type -> V_117 ) ;
if ( V_176 -> V_174 != NULL )
F_140 ( V_176 -> V_174 ) ;
}
static int F_144 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
struct V_102 * V_103 )
{
const struct V_76 * V_77 = F_62 ( V_18 ) ;
const struct V_23 * V_189 ( V_68 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct F_27 * V_155 = NULL ;
T_3 V_67 = F_97 ( V_1 ) ;
int V_9 = V_77 -> V_79 ;
T_3 V_165 = V_190 ;
T_4 V_136 = 0 ;
unsigned int V_72 ;
struct V_137 T_5 * V_138 ;
int V_43 ;
bool V_177 ;
struct V_13 V_14 ;
V_177 = V_18 -> V_105 & V_191 ? true : false ;
V_3 = F_11 ( V_1 , V_9 , true ) ;
if ( F_86 ( V_3 ) )
return F_87 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_151 ] , V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
V_22 = NULL ;
V_68 = V_24 [ V_154 ] ;
if ( V_24 [ V_152 ] ) {
V_136 = F_131 ( F_132 ( V_24 [ V_152 ] ) ) ;
V_22 = F_111 ( V_20 , V_136 , V_67 ) ;
if ( F_86 ( V_22 ) )
return F_87 ( V_22 ) ;
} else {
V_22 = F_112 ( V_20 , V_68 , V_67 ) ;
if ( F_86 ( V_22 ) ) {
if ( F_87 ( V_22 ) != - V_51 )
return F_87 ( V_22 ) ;
V_22 = NULL ;
}
}
if ( V_24 [ V_164 ] ) {
if ( V_22 != NULL &&
! F_25 ( V_22 ) )
return - V_116 ;
if ( V_22 == NULL &&
V_24 [ V_157 ] == NULL )
return - V_116 ;
V_165 = F_41 ( F_42 ( V_24 [ V_164 ] ) ) ;
switch ( V_165 ) {
case V_192 :
case V_190 :
break;
default:
return - V_69 ;
}
}
if ( V_22 != NULL ) {
struct V_137 * V_138 = NULL ;
struct V_29 * V_33 ;
if ( V_18 -> V_105 & V_113 )
return - V_114 ;
if ( V_18 -> V_105 & V_115 )
return - V_116 ;
if ( V_24 [ V_157 ] ) {
struct F_27 * V_155 ;
struct V_175 V_176 ;
struct V_156 * V_38 ;
if ( ! F_25 ( V_22 ) )
return - V_135 ;
V_43 = F_141 ( V_1 , V_24 , V_3 , & V_176 ,
V_177 ) ;
if ( V_43 < 0 )
return V_43 ;
V_155 = F_27 ( V_22 ) ;
if ( V_155 -> type != V_176 . type ) {
F_143 ( & V_176 ) ;
return - V_135 ;
}
for ( V_72 = 0 ; V_72 < V_3 -> V_111 ; V_72 ++ ) {
V_38 = & V_155 -> V_38 [ V_72 ] ;
if ( V_38 -> V_159 != V_176 . V_182 ||
V_38 -> V_161 != V_176 . V_161 ||
V_38 -> V_174 != V_176 . V_174 ) {
F_143 ( & V_176 ) ;
return - V_135 ;
}
}
F_143 ( & V_176 ) ;
}
if ( V_24 [ V_152 ] && V_68 ) {
struct V_21 * V_193 ;
V_193 = F_112 ( V_20 ,
V_24 [ V_154 ] ,
V_67 ) ;
if ( F_86 ( V_193 ) )
return F_87 ( V_193 ) ;
}
if ( V_24 [ V_146 ] ) {
if ( ! F_25 ( V_22 ) )
return - V_116 ;
V_138 = F_126 ( V_24 [ V_146 ] ) ;
if ( F_86 ( V_138 ) )
return F_87 ( V_138 ) ;
}
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_33 = F_20 ( & V_14 , V_46 ,
sizeof( struct V_45 ) ) ;
if ( V_33 == NULL ) {
F_138 ( V_138 ) ;
return - V_40 ;
}
F_145 ( V_33 ) = V_138 ;
F_146 ( V_33 ) = true ;
if ( V_24 [ V_164 ] )
F_147 ( V_33 ) = V_165 ;
else
F_147 ( V_33 ) = - 1 ;
if ( V_24 [ V_152 ] && V_68 ) {
F_99 ( F_148 ( V_33 ) , V_68 ,
V_194 ) ;
}
F_32 ( & V_33 -> V_6 , & V_1 -> V_7 . V_42 ) ;
return 0 ;
}
if ( V_20 -> V_48 == V_195 )
return - V_196 ;
if ( V_24 [ V_157 ] ) {
struct V_175 V_176 ;
struct V_156 * V_38 ;
T_6 * V_197 ;
V_43 = F_141 ( V_1 , V_24 , V_3 , & V_176 , V_177 ) ;
if ( V_43 < 0 )
return V_43 ;
V_155 = F_19 ( sizeof( * V_155 ) , V_34 ) ;
if ( V_155 == NULL ) {
F_143 ( & V_176 ) ;
return - V_40 ;
}
if ( V_176 . V_174 != NULL )
strncpy ( V_155 -> V_162 , V_176 . V_174 -> V_68 , V_188 ) ;
if ( V_24 [ V_146 ] ) {
V_138 = F_126 ( V_24 [ V_146 ] ) ;
if ( F_86 ( V_138 ) ) {
F_143 ( & V_176 ) ;
F_23 ( V_155 ) ;
return F_87 ( V_138 ) ;
}
V_155 -> V_138 = V_138 ;
} else {
V_138 = F_128 ( struct V_137 ) ;
if ( V_138 == NULL ) {
F_143 ( & V_176 ) ;
F_23 ( V_155 ) ;
return - V_40 ;
}
F_136 ( V_155 -> V_138 , V_138 ) ;
}
V_197 = V_176 . type -> V_198 [ V_176 . V_182 ] ;
V_155 -> type = V_176 . type ;
V_22 = & V_155 -> V_22 ;
for ( V_72 = 0 ; V_72 < V_3 -> V_111 ; V_72 ++ ) {
V_38 = & V_155 -> V_38 [ V_72 ] ;
V_38 -> V_199 = V_9 ;
V_38 -> V_159 = V_176 . V_182 ;
V_38 -> V_161 = V_176 . V_161 ;
V_38 -> V_200 = V_22 ;
V_38 -> V_176 = V_3 -> V_198 [ V_38 -> V_159 ] ;
V_38 -> V_174 = V_176 . V_174 ;
if ( V_197 )
V_38 -> V_176 = V_197 ;
if ( V_3 -> V_201 )
V_3 -> V_201 ( V_38 , V_72 ) ;
}
V_22 -> V_36 |= V_202 ;
V_155 -> V_165 = V_165 ;
} else {
V_22 = F_19 ( sizeof( * V_22 ) , V_34 ) ;
if ( V_22 == NULL )
return - V_40 ;
}
F_2 ( & V_22 -> V_203 ) ;
V_22 -> V_136 = F_54 ( V_20 ) ;
V_22 -> V_20 = V_20 ;
F_99 ( V_22 -> V_68 , V_68 , V_194 ) ;
V_43 = F_24 ( V_1 , V_20 , V_22 , V_3 -> V_111 ) ;
if ( V_43 < 0 )
goto V_118;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_43 = F_35 ( & V_14 , V_46 ) ;
if ( V_43 < 0 )
goto V_119;
V_20 -> V_48 ++ ;
F_4 ( & V_22 -> V_6 , & V_20 -> V_121 ) ;
return 0 ;
V_119:
F_28 ( V_1 , V_20 , V_22 , V_3 -> V_111 ) ;
V_118:
F_139 ( V_22 ) ;
return V_43 ;
}
static int F_149 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
struct V_102 * V_103 )
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
V_20 = F_53 ( V_3 , V_24 [ V_151 ] , V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
V_22 = F_112 ( V_20 , V_24 [ V_154 ] , V_67 ) ;
if ( F_86 ( V_22 ) )
return F_87 ( V_22 ) ;
if ( V_22 -> V_48 > 0 )
return - V_135 ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
return F_36 ( & V_14 ) ;
}
int F_150 ( struct V_204 * type )
{
F_3 ( V_5 ) ;
if ( type -> V_9 == V_95 )
F_4 ( & type -> V_6 , & V_205 ) ;
else
F_151 ( & type -> V_6 , & V_205 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_152 ( struct V_204 * type )
{
F_3 ( V_5 ) ;
F_8 ( & type -> V_6 ) ;
F_5 ( V_5 ) ;
}
static const struct V_204 * F_153 ( T_3 V_9 ,
struct V_23 * V_24 )
{
const struct V_204 * type ;
F_10 (type, &nf_tables_expressions, list) {
if ( ! F_51 ( V_24 , type -> V_68 ) &&
( ! type -> V_9 || type -> V_9 == V_9 ) )
return type ;
}
return NULL ;
}
static const struct V_204 * F_154 ( T_3 V_9 ,
struct V_23 * V_24 )
{
const struct V_204 * type ;
if ( V_24 == NULL )
return F_14 ( - V_69 ) ;
type = F_153 ( V_9 , V_24 ) ;
if ( type != NULL && F_98 ( type -> V_117 ) )
return type ;
#ifdef F_12
if ( type == NULL ) {
F_5 ( V_5 ) ;
F_13 ( L_3 , V_9 ,
F_57 ( V_24 ) , ( char * ) F_58 ( V_24 ) ) ;
F_3 ( V_5 ) ;
if ( F_153 ( V_9 , V_24 ) )
return F_14 ( - V_11 ) ;
F_5 ( V_5 ) ;
F_13 ( L_4 ,
F_57 ( V_24 ) , ( char * ) F_58 ( V_24 ) ) ;
F_3 ( V_5 ) ;
if ( F_153 ( V_9 , V_24 ) )
return F_14 ( - V_11 ) ;
}
#endif
return F_14 ( - V_51 ) ;
}
static int F_155 ( struct V_15 * V_16 ,
const struct V_206 * V_207 )
{
if ( F_64 ( V_16 , V_208 , V_207 -> V_38 -> type -> V_68 ) )
goto V_78;
if ( V_207 -> V_38 -> V_109 ) {
struct V_23 * V_209 = F_118 ( V_16 , V_210 ) ;
if ( V_209 == NULL )
goto V_78;
if ( V_207 -> V_38 -> V_109 ( V_16 , V_207 ) < 0 )
goto V_78;
F_121 ( V_16 , V_209 ) ;
}
return V_16 -> V_99 ;
V_78:
return - 1 ;
}
int F_156 ( struct V_15 * V_16 , unsigned int V_168 ,
const struct V_206 * V_207 )
{
struct V_23 * V_141 ;
V_141 = F_118 ( V_16 , V_168 ) ;
if ( ! V_141 )
goto V_78;
if ( F_155 ( V_16 , V_207 ) < 0 )
goto V_78;
F_121 ( V_16 , V_141 ) ;
return 0 ;
V_78:
return - 1 ;
}
static int F_157 ( const struct V_13 * V_14 ,
const struct V_23 * V_24 ,
struct V_211 * V_212 )
{
const struct V_204 * type ;
const struct V_213 * V_38 ;
struct V_23 * V_169 [ V_214 + 1 ] ;
int V_43 ;
V_43 = F_127 ( V_169 , V_214 , V_24 , V_215 , NULL ) ;
if ( V_43 < 0 )
return V_43 ;
type = F_154 ( V_14 -> V_3 -> V_9 , V_169 [ V_208 ] ) ;
if ( F_86 ( type ) )
return F_87 ( type ) ;
if ( V_169 [ V_210 ] ) {
V_43 = F_127 ( V_212 -> V_169 , type -> V_216 ,
V_169 [ V_210 ] , type -> V_165 , NULL ) ;
if ( V_43 < 0 )
goto V_118;
} else
memset ( V_212 -> V_169 , 0 , sizeof( V_212 -> V_169 [ 0 ] ) * ( type -> V_216 + 1 ) ) ;
if ( type -> V_217 != NULL ) {
V_38 = type -> V_217 ( V_14 ,
( const struct V_23 * const * ) V_212 -> V_169 ) ;
if ( F_86 ( V_38 ) ) {
V_43 = F_87 ( V_38 ) ;
goto V_118;
}
} else
V_38 = type -> V_38 ;
V_212 -> V_38 = V_38 ;
return 0 ;
V_118:
F_100 ( type -> V_117 ) ;
return V_43 ;
}
static int F_158 ( const struct V_13 * V_14 ,
const struct V_211 * V_212 ,
struct V_206 * V_207 )
{
const struct V_213 * V_38 = V_212 -> V_38 ;
int V_43 ;
V_207 -> V_38 = V_38 ;
if ( V_38 -> V_218 ) {
V_43 = V_38 -> V_218 ( V_14 , V_207 , ( const struct V_23 * * ) V_212 -> V_169 ) ;
if ( V_43 < 0 )
goto V_118;
}
if ( V_38 -> V_219 ) {
const struct V_220 * V_209 = NULL ;
V_43 = V_38 -> V_219 ( V_14 , V_207 , & V_209 ) ;
if ( V_43 < 0 )
goto V_119;
}
return 0 ;
V_119:
if ( V_38 -> V_221 )
V_38 -> V_221 ( V_14 , V_207 ) ;
V_118:
V_207 -> V_38 = NULL ;
return V_43 ;
}
static void F_159 ( const struct V_13 * V_14 ,
struct V_206 * V_207 )
{
if ( V_207 -> V_38 -> V_221 )
V_207 -> V_38 -> V_221 ( V_14 , V_207 ) ;
F_100 ( V_207 -> V_38 -> type -> V_117 ) ;
}
struct V_206 * F_160 ( const struct V_13 * V_14 ,
const struct V_23 * V_24 )
{
struct V_211 V_212 ;
struct V_206 * V_207 ;
int V_43 ;
V_43 = F_157 ( V_14 , V_24 , & V_212 ) ;
if ( V_43 < 0 )
goto V_118;
V_43 = - V_40 ;
V_207 = F_19 ( V_212 . V_38 -> V_31 , V_34 ) ;
if ( V_207 == NULL )
goto V_119;
V_43 = F_158 ( V_14 , & V_212 , V_207 ) ;
if ( V_43 < 0 )
goto V_124;
return V_207 ;
V_124:
F_23 ( V_207 ) ;
V_119:
F_100 ( V_212 . V_38 -> type -> V_117 ) ;
V_118:
return F_14 ( V_43 ) ;
}
void F_161 ( const struct V_13 * V_14 , struct V_206 * V_207 )
{
F_159 ( V_14 , V_207 ) ;
F_23 ( V_207 ) ;
}
static struct V_49 * F_162 ( const struct V_21 * V_22 ,
T_4 V_136 )
{
struct V_49 * V_50 ;
F_10 (rule, &chain->rules, list) {
if ( V_136 == V_50 -> V_136 )
return V_50 ;
}
return F_14 ( - V_51 ) ;
}
static struct V_49 * F_163 ( const struct V_21 * V_22 ,
const struct V_23 * V_24 )
{
if ( V_24 == NULL )
return F_14 ( - V_69 ) ;
return F_162 ( V_22 , F_131 ( F_132 ( V_24 ) ) ) ;
}
static int F_164 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_25 , T_1 V_27 , int V_75 ,
T_1 V_36 , int V_9 ,
const struct V_19 * V_20 ,
const struct V_21 * V_22 ,
const struct V_49 * V_50 )
{
struct V_17 * V_18 ;
struct V_76 * V_77 ;
const struct V_206 * V_207 , * V_222 ;
struct V_23 * V_6 ;
const struct V_49 * V_223 ;
T_7 type = F_60 ( V_5 , V_75 ) ;
V_18 = F_61 ( V_16 , V_25 , V_27 , type , sizeof( struct V_76 ) , V_36 ) ;
if ( V_18 == NULL )
goto V_78;
V_77 = F_62 ( V_18 ) ;
V_77 -> V_79 = V_9 ;
V_77 -> V_80 = V_81 ;
V_77 -> V_82 = F_63 ( V_1 -> V_7 . V_83 & 0xffff ) ;
if ( F_64 ( V_16 , V_224 , V_20 -> V_68 ) )
goto V_78;
if ( F_64 ( V_16 , V_225 , V_22 -> V_68 ) )
goto V_78;
if ( F_119 ( V_16 , V_226 , F_120 ( V_50 -> V_136 ) ,
V_227 ) )
goto V_78;
if ( ( V_75 != V_55 ) && ( V_50 -> V_6 . V_228 != & V_22 -> V_203 ) ) {
V_223 = F_165 ( V_50 , V_6 ) ;
if ( F_119 ( V_16 , V_229 ,
F_120 ( V_223 -> V_136 ) ,
V_227 ) )
goto V_78;
}
V_6 = F_118 ( V_16 , V_230 ) ;
if ( V_6 == NULL )
goto V_78;
F_166 (expr, next, rule) {
if ( F_156 ( V_16 , V_231 , V_207 ) < 0 )
goto V_78;
}
F_121 ( V_16 , V_6 ) ;
if ( V_50 -> V_232 ) {
struct V_233 * V_232 = V_233 ( V_50 ) ;
if ( F_167 ( V_16 , V_234 , V_232 -> V_99 + 1 ,
V_232 -> V_209 ) < 0 )
goto V_78;
}
F_67 ( V_16 , V_18 ) ;
return 0 ;
V_78:
F_68 ( V_16 , V_18 ) ;
return - 1 ;
}
static void F_168 ( const struct V_13 * V_14 ,
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
V_43 = F_164 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_14 -> V_27 ,
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
static int F_169 ( struct V_15 * V_16 ,
struct V_90 * V_91 )
{
const struct V_76 * V_77 = F_62 ( V_91 -> V_18 ) ;
const struct V_235 * V_14 = V_91 -> V_209 ;
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
if ( F_164 ( V_16 , V_1 , F_16 ( V_91 -> V_16 ) . V_25 ,
V_91 -> V_18 -> V_28 ,
V_53 ,
V_97 | V_236 ,
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
static int F_170 ( struct V_90 * V_91 )
{
F_23 ( V_91 -> V_209 ) ;
return 0 ;
}
static int F_171 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
struct V_102 * V_103 )
{
const struct V_76 * V_77 = F_62 ( V_18 ) ;
T_3 V_67 = F_84 ( V_1 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
const struct V_49 * V_50 ;
struct V_15 * V_104 ;
int V_9 = V_77 -> V_79 ;
int V_43 ;
if ( V_18 -> V_105 & V_106 ) {
struct V_107 V_108 = {
. V_109 = F_169 ,
. V_98 = F_170 ,
} ;
if ( V_24 [ V_224 ] || V_24 [ V_225 ] ) {
struct V_235 * V_14 ;
V_14 = F_19 ( sizeof( * V_14 ) , V_34 ) ;
if ( ! V_14 )
return - V_40 ;
if ( V_24 [ V_224 ] )
F_99 ( V_14 -> V_20 , V_24 [ V_224 ] ,
sizeof( V_14 -> V_20 ) ) ;
if ( V_24 [ V_225 ] )
F_99 ( V_14 -> V_22 , V_24 [ V_225 ] ,
sizeof( V_14 -> V_22 ) ) ;
V_108 . V_209 = V_14 ;
}
return F_85 ( V_101 , V_16 , V_18 , & V_108 ) ;
}
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_86 ( V_3 ) )
return F_87 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_224 ] , V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
V_22 = F_112 ( V_20 , V_24 [ V_225 ] , V_67 ) ;
if ( F_86 ( V_22 ) )
return F_87 ( V_22 ) ;
V_50 = F_163 ( V_22 , V_24 [ V_226 ] ) ;
if ( F_86 ( V_50 ) )
return F_87 ( V_50 ) ;
V_104 = F_88 ( V_88 , V_34 ) ;
if ( ! V_104 )
return - V_40 ;
V_43 = F_164 ( V_104 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 , V_53 , 0 ,
V_9 , V_20 , V_22 , V_50 ) ;
if ( V_43 < 0 )
goto V_43;
return F_89 ( V_101 , V_104 , F_16 ( V_16 ) . V_25 ) ;
V_43:
F_72 ( V_104 ) ;
return V_43 ;
}
static void F_172 ( const struct V_13 * V_14 ,
struct V_49 * V_50 )
{
struct V_206 * V_207 ;
V_207 = F_173 ( V_50 ) ;
while ( V_207 != F_174 ( V_50 ) && V_207 -> V_38 ) {
F_159 ( V_14 , V_207 ) ;
V_207 = F_175 ( V_207 ) ;
}
F_23 ( V_50 ) ;
}
static int F_176 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
struct V_102 * V_103 )
{
const struct V_76 * V_77 = F_62 ( V_18 ) ;
T_3 V_67 = F_97 ( V_1 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_49 * V_50 , * V_237 = NULL ;
struct V_233 * V_232 ;
struct V_29 * V_33 = NULL ;
struct V_206 * V_207 ;
struct V_13 V_14 ;
struct V_23 * V_238 ;
unsigned int V_31 , V_72 , V_239 , V_240 = 0 , V_241 = 0 ;
int V_43 , V_242 ;
bool V_177 ;
T_4 V_136 , V_243 ;
V_177 = V_18 -> V_105 & V_191 ? true : false ;
V_3 = F_11 ( V_1 , V_77 -> V_79 , V_177 ) ;
if ( F_86 ( V_3 ) )
return F_87 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_224 ] , V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
V_22 = F_112 ( V_20 , V_24 [ V_225 ] , V_67 ) ;
if ( F_86 ( V_22 ) )
return F_87 ( V_22 ) ;
if ( V_24 [ V_226 ] ) {
V_136 = F_131 ( F_132 ( V_24 [ V_226 ] ) ) ;
V_50 = F_162 ( V_22 , V_136 ) ;
if ( F_86 ( V_50 ) )
return F_87 ( V_50 ) ;
if ( V_18 -> V_105 & V_113 )
return - V_114 ;
if ( V_18 -> V_105 & V_115 )
V_237 = V_50 ;
else
return - V_116 ;
} else {
if ( ! V_177 || V_18 -> V_105 & V_115 )
return - V_69 ;
V_136 = F_54 ( V_20 ) ;
if ( V_22 -> V_48 == V_195 )
return - V_196 ;
}
if ( V_24 [ V_229 ] ) {
if ( ! ( V_18 -> V_105 & V_191 ) )
return - V_116 ;
V_243 = F_131 ( F_132 ( V_24 [ V_229 ] ) ) ;
V_237 = F_162 ( V_22 , V_243 ) ;
if ( F_86 ( V_237 ) )
return F_87 ( V_237 ) ;
}
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_239 = 0 ;
V_31 = 0 ;
if ( V_24 [ V_230 ] ) {
F_177 (tmp, nla[NFTA_RULE_EXPRESSIONS], rem) {
V_43 = - V_69 ;
if ( F_178 ( V_238 ) != V_231 )
goto V_118;
if ( V_239 == V_244 )
goto V_118;
V_43 = F_157 ( & V_14 , V_238 , & V_212 [ V_239 ] ) ;
if ( V_43 < 0 )
goto V_118;
V_31 += V_212 [ V_239 ] . V_38 -> V_31 ;
V_239 ++ ;
}
}
V_43 = - V_245 ;
if ( V_31 >= 1 << 12 )
goto V_118;
if ( V_24 [ V_234 ] ) {
V_240 = F_57 ( V_24 [ V_234 ] ) ;
if ( V_240 > 0 )
V_241 = sizeof( struct V_233 ) + V_240 ;
}
V_43 = - V_40 ;
V_50 = F_19 ( sizeof( * V_50 ) + V_31 + V_241 , V_34 ) ;
if ( V_50 == NULL )
goto V_118;
F_31 ( V_1 , V_50 ) ;
V_50 -> V_136 = V_136 ;
V_50 -> V_246 = V_31 ;
V_50 -> V_232 = V_240 ? 1 : 0 ;
if ( V_240 ) {
V_232 = V_233 ( V_50 ) ;
V_232 -> V_99 = V_240 - 1 ;
F_179 ( V_232 -> V_209 , V_24 [ V_234 ] , V_240 ) ;
}
V_207 = F_173 ( V_50 ) ;
for ( V_72 = 0 ; V_72 < V_239 ; V_72 ++ ) {
V_43 = F_158 ( & V_14 , & V_212 [ V_72 ] , V_207 ) ;
if ( V_43 < 0 )
goto V_119;
V_212 [ V_72 ] . V_38 = NULL ;
V_207 = F_175 ( V_207 ) ;
}
if ( V_18 -> V_105 & V_115 ) {
if ( F_38 ( V_1 , V_237 ) ) {
V_33 = F_39 ( & V_14 , V_55 ,
V_237 ) ;
if ( V_33 == NULL ) {
V_43 = - V_40 ;
goto V_119;
}
F_34 ( V_1 , V_237 ) ;
V_22 -> V_48 -- ;
F_4 ( & V_50 -> V_6 , & V_237 -> V_6 ) ;
} else {
V_43 = - V_51 ;
goto V_119;
}
} else if ( V_18 -> V_105 & V_236 )
if ( V_237 )
F_151 ( & V_50 -> V_6 , & V_237 -> V_6 ) ;
else
F_4 ( & V_50 -> V_6 , & V_22 -> V_203 ) ;
else {
if ( V_237 )
F_4 ( & V_50 -> V_6 , & V_237 -> V_6 ) ;
else
F_151 ( & V_50 -> V_6 , & V_22 -> V_203 ) ;
}
if ( F_39 ( & V_14 , V_53 , V_50 ) == NULL ) {
V_43 = - V_40 ;
goto V_124;
}
V_22 -> V_48 ++ ;
return 0 ;
V_124:
F_8 ( & V_50 -> V_6 ) ;
V_119:
F_172 ( & V_14 , V_50 ) ;
V_118:
for ( V_72 = 0 ; V_72 < V_239 ; V_72 ++ ) {
if ( V_212 [ V_72 ] . V_38 != NULL )
F_100 ( V_212 [ V_72 ] . V_38 -> type -> V_117 ) ;
}
return V_43 ;
}
static struct V_49 * F_180 ( const struct V_1 * V_1 ,
const struct V_23 * V_24 )
{
T_1 V_247 = F_41 ( F_42 ( V_24 ) ) ;
struct V_29 * V_33 ;
F_10 (trans, &net->nft.commit_list, list) {
struct V_49 * V_50 = V_52 ( V_33 ) ;
if ( V_33 -> V_30 == V_53 &&
V_247 == F_40 ( V_33 ) )
return V_50 ;
}
return F_14 ( - V_51 ) ;
}
static int F_181 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
struct V_102 * V_103 )
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
V_20 = F_53 ( V_3 , V_24 [ V_224 ] , V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
if ( V_24 [ V_225 ] ) {
V_22 = F_112 ( V_20 , V_24 [ V_225 ] ,
V_67 ) ;
if ( F_86 ( V_22 ) )
return F_87 ( V_22 ) ;
}
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
if ( V_22 ) {
if ( V_24 [ V_226 ] ) {
V_50 = F_163 ( V_22 ,
V_24 [ V_226 ] ) ;
if ( F_86 ( V_50 ) )
return F_87 ( V_50 ) ;
V_43 = F_43 ( & V_14 , V_50 ) ;
} else if ( V_24 [ V_54 ] ) {
V_50 = F_180 ( V_1 , V_24 [ V_54 ] ) ;
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
int F_182 ( struct V_248 * type )
{
F_3 ( V_5 ) ;
F_4 ( & type -> V_6 , & V_249 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_183 ( struct V_248 * type )
{
F_3 ( V_5 ) ;
F_8 ( & type -> V_6 ) ;
F_5 ( V_5 ) ;
}
static bool F_184 ( const struct V_250 * V_38 , T_1 V_36 )
{
return ( V_36 & V_38 -> V_251 ) == ( V_36 & V_252 ) ;
}
static const struct V_250 *
F_185 ( const struct V_13 * V_14 ,
const struct V_23 * const V_24 [] ,
const struct V_253 * V_254 ,
enum V_255 V_165 )
{
const struct V_250 * V_38 , * V_256 ;
struct V_257 V_258 , V_259 ;
const struct V_248 * type ;
T_1 V_36 = 0 ;
#ifdef F_12
if ( F_103 ( & V_249 ) ) {
F_5 ( V_5 ) ;
F_13 ( L_5 ) ;
F_3 ( V_5 ) ;
if ( ! F_103 ( & V_249 ) )
return F_14 ( - V_11 ) ;
}
#endif
if ( V_24 [ V_260 ] != NULL )
V_36 = F_41 ( F_42 ( V_24 [ V_260 ] ) ) ;
V_256 = NULL ;
V_259 . V_31 = ~ 0 ;
V_259 . V_261 = ~ 0 ;
V_259 . V_262 = ~ 0 ;
F_10 (type, &nf_tables_set_types, list) {
if ( ! type -> V_217 )
V_38 = type -> V_38 ;
else
V_38 = type -> V_217 ( V_14 , V_254 , V_36 ) ;
if ( ! V_38 )
continue;
if ( ! F_184 ( V_38 , V_36 ) )
continue;
if ( ! V_38 -> V_263 ( V_254 , V_36 , & V_258 ) )
continue;
switch ( V_165 ) {
case V_264 :
if ( V_258 . V_261 < V_259 . V_261 )
break;
if ( V_258 . V_261 == V_259 . V_261 ) {
if ( ! V_254 -> V_31 ) {
if ( V_258 . V_262 < V_259 . V_262 )
break;
} else if ( V_258 . V_31 < V_259 . V_31 ) {
break;
}
}
continue;
case V_265 :
if ( ! V_254 -> V_31 ) {
if ( V_258 . V_262 < V_259 . V_262 )
break;
if ( V_258 . V_262 == V_259 . V_262 &&
V_258 . V_261 < V_259 . V_261 )
break;
} else if ( V_258 . V_31 < V_259 . V_31 ) {
break;
}
continue;
default:
break;
}
if ( ! F_98 ( type -> V_117 ) )
continue;
if ( V_256 != NULL )
F_100 ( V_256 -> type -> V_117 ) ;
V_256 = V_38 ;
V_259 = V_258 ;
}
if ( V_256 != NULL )
return V_256 ;
return F_14 ( - V_116 ) ;
}
static int F_186 ( struct V_13 * V_14 , struct V_1 * V_1 ,
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
if ( V_24 [ V_266 ] != NULL ) {
if ( V_3 == NULL )
return - V_12 ;
V_20 = F_53 ( V_3 , V_24 [ V_266 ] ,
V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
}
F_15 ( V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return 0 ;
}
static struct V_56 * F_187 ( const struct V_19 * V_20 ,
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
static struct V_56 * F_188 ( const struct V_1 * V_1 ,
const struct V_23 * V_24 ,
T_3 V_67 )
{
struct V_29 * V_33 ;
T_1 V_247 = F_41 ( F_42 ( V_24 ) ) ;
F_10 (trans, &net->nft.commit_list, list) {
struct V_56 * V_57 = V_58 ( V_33 ) ;
if ( V_33 -> V_30 == V_59 &&
V_247 == F_46 ( V_33 ) &&
F_52 ( V_57 , V_67 ) )
return V_57 ;
}
return F_14 ( - V_51 ) ;
}
struct V_56 * F_189 ( const struct V_1 * V_1 ,
const struct V_19 * V_20 ,
const struct V_23 * V_267 ,
const struct V_23 * V_268 ,
T_3 V_67 )
{
struct V_56 * V_57 ;
V_57 = F_187 ( V_20 , V_267 , V_67 ) ;
if ( F_86 ( V_57 ) ) {
if ( ! V_268 )
return V_57 ;
V_57 = F_188 ( V_1 , V_268 , V_67 ) ;
}
return V_57 ;
}
static int F_190 ( struct V_13 * V_14 , struct V_56 * V_57 ,
const char * V_68 )
{
const struct V_56 * V_72 ;
const char * V_269 ;
unsigned long * V_270 ;
unsigned int V_239 = 0 , V_271 = 0 ;
V_269 = F_191 ( V_68 , V_272 , '%' ) ;
if ( V_269 != NULL ) {
if ( V_269 [ 1 ] != 'd' || strchr ( V_269 + 2 , '%' ) )
return - V_69 ;
V_270 = ( unsigned long * ) F_192 ( V_34 ) ;
if ( V_270 == NULL )
return - V_40 ;
V_96:
F_10 (i, &ctx->table->sets, list) {
int V_238 ;
if ( ! F_38 ( V_14 -> V_1 , V_57 ) )
continue;
if ( ! sscanf ( V_72 -> V_68 , V_68 , & V_238 ) )
continue;
if ( V_238 < V_271 || V_238 >= V_271 + V_273 * V_274 )
continue;
F_193 ( V_238 - V_271 , V_270 ) ;
}
V_239 = F_194 ( V_270 , V_273 * V_274 ) ;
if ( V_239 >= V_273 * V_274 ) {
V_271 += V_273 * V_274 ;
memset ( V_270 , 0 , V_274 ) ;
goto V_96;
}
F_195 ( ( unsigned long ) V_270 ) ;
}
snprintf ( V_57 -> V_68 , sizeof( V_57 -> V_68 ) , V_68 , V_271 + V_239 ) ;
F_10 (i, &ctx->table->sets, list) {
if ( ! F_38 ( V_14 -> V_1 , V_72 ) )
continue;
if ( ! strcmp ( V_57 -> V_68 , V_72 -> V_68 ) )
return - V_275 ;
}
return 0 ;
}
static int F_196 ( struct V_15 * V_16 , const struct V_13 * V_14 ,
const struct V_56 * V_57 , T_7 V_75 , T_7 V_36 )
{
struct V_76 * V_77 ;
struct V_17 * V_18 ;
struct V_23 * V_254 ;
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
if ( F_64 ( V_16 , V_266 , V_14 -> V_20 -> V_68 ) )
goto V_78;
if ( F_64 ( V_16 , V_276 , V_57 -> V_68 ) )
goto V_78;
if ( V_57 -> V_36 != 0 )
if ( F_65 ( V_16 , V_260 , F_66 ( V_57 -> V_36 ) ) )
goto V_78;
if ( F_65 ( V_16 , V_277 , F_66 ( V_57 -> V_278 ) ) )
goto V_78;
if ( F_65 ( V_16 , V_279 , F_66 ( V_57 -> V_280 ) ) )
goto V_78;
if ( V_57 -> V_36 & V_281 ) {
if ( F_65 ( V_16 , V_282 , F_66 ( V_57 -> V_283 ) ) )
goto V_78;
if ( F_65 ( V_16 , V_284 , F_66 ( V_57 -> V_246 ) ) )
goto V_78;
}
if ( V_57 -> V_36 & V_285 &&
F_65 ( V_16 , V_286 , F_66 ( V_57 -> V_287 ) ) )
goto V_78;
if ( V_57 -> V_288 &&
F_119 ( V_16 , V_289 ,
F_120 ( F_197 ( V_57 -> V_288 ) ) ,
V_290 ) )
goto V_78;
if ( V_57 -> V_291 &&
F_65 ( V_16 , V_292 , F_66 ( V_57 -> V_291 ) ) )
goto V_78;
if ( V_57 -> V_165 != V_264 ) {
if ( F_65 ( V_16 , V_293 , F_66 ( V_57 -> V_165 ) ) )
goto V_78;
}
if ( F_167 ( V_16 , V_294 , V_57 -> V_295 , V_57 -> V_232 ) )
goto V_78;
V_254 = F_118 ( V_16 , V_296 ) ;
if ( V_254 == NULL )
goto V_78;
if ( V_57 -> V_31 &&
F_65 ( V_16 , V_297 , F_66 ( V_57 -> V_31 ) ) )
goto V_78;
F_121 ( V_16 , V_254 ) ;
F_67 ( V_16 , V_18 ) ;
return 0 ;
V_78:
F_68 ( V_16 , V_18 ) ;
return - 1 ;
}
static void F_198 ( const struct V_13 * V_14 ,
const struct V_56 * V_57 , int V_75 ,
T_2 V_298 )
{
struct V_15 * V_16 ;
T_1 V_25 = V_14 -> V_25 ;
int V_43 ;
if ( ! V_14 -> V_26 &&
! F_70 ( V_14 -> V_1 , V_87 ) )
return;
V_16 = F_71 ( V_88 , V_298 ) ;
if ( V_16 == NULL )
goto V_43;
V_43 = F_196 ( V_16 , V_14 , V_57 , V_75 , 0 ) ;
if ( V_43 < 0 ) {
F_72 ( V_16 ) ;
goto V_43;
}
F_73 ( V_16 , V_14 -> V_1 , V_25 , V_87 , V_14 -> V_26 ,
V_298 ) ;
return;
V_43:
F_74 ( V_14 -> V_1 , V_25 , V_87 , - V_89 ) ;
}
static int F_199 ( struct V_15 * V_16 , struct V_90 * V_91 )
{
const struct V_56 * V_57 ;
unsigned int V_92 , V_93 = V_91 -> args [ 0 ] ;
struct V_2 * V_3 ;
struct V_19 * V_20 , * V_299 = (struct V_19 * ) V_91 -> args [ 2 ] ;
struct V_1 * V_1 = F_76 ( V_16 -> V_94 ) ;
int V_300 = V_91 -> args [ 3 ] ;
struct V_13 * V_14 = V_91 -> V_209 , V_301 ;
if ( V_91 -> args [ 1 ] )
return V_16 -> V_99 ;
F_77 () ;
V_91 -> V_27 = V_1 -> V_7 . V_83 ;
F_78 (afi, &net->nft.af_info, list) {
if ( V_14 -> V_3 && V_14 -> V_3 != V_3 )
continue;
if ( V_300 ) {
if ( V_3 -> V_9 != V_300 )
continue;
V_300 = 0 ;
}
F_78 (table, &afi->tables, list) {
if ( V_14 -> V_20 && V_14 -> V_20 != V_20 )
continue;
if ( V_299 ) {
if ( V_299 != V_20 )
continue;
V_299 = NULL ;
}
V_92 = 0 ;
F_78 (set, &table->sets, list) {
if ( V_92 < V_93 )
goto V_96;
if ( ! F_79 ( V_1 , V_57 ) )
goto V_96;
V_301 = * V_14 ;
V_301 . V_20 = V_20 ;
V_301 . V_3 = V_3 ;
if ( F_196 ( V_16 , & V_301 , V_57 ,
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
static int F_200 ( struct V_90 * V_91 )
{
F_23 ( V_91 -> V_209 ) ;
return 0 ;
}
static int F_201 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
struct V_102 * V_103 )
{
T_3 V_67 = F_84 ( V_1 ) ;
const struct V_56 * V_57 ;
struct V_13 V_14 ;
struct V_15 * V_104 ;
const struct V_76 * V_77 = F_62 ( V_18 ) ;
int V_43 ;
V_43 = F_186 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_67 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_18 -> V_105 & V_106 ) {
struct V_107 V_108 = {
. V_109 = F_199 ,
. V_98 = F_200 ,
} ;
struct V_13 * V_302 ;
V_302 = F_202 ( sizeof( * V_302 ) , V_34 ) ;
if ( V_302 == NULL )
return - V_40 ;
* V_302 = V_14 ;
V_108 . V_209 = V_302 ;
return F_85 ( V_101 , V_16 , V_18 , & V_108 ) ;
}
if ( V_77 -> V_79 == V_95 )
return - V_12 ;
if ( ! V_24 [ V_266 ] )
return - V_69 ;
V_57 = F_187 ( V_14 . V_20 , V_24 [ V_276 ] , V_67 ) ;
if ( F_86 ( V_57 ) )
return F_87 ( V_57 ) ;
V_104 = F_88 ( V_88 , V_34 ) ;
if ( V_104 == NULL )
return - V_40 ;
V_43 = F_196 ( V_104 , & V_14 , V_57 , V_59 , 0 ) ;
if ( V_43 < 0 )
goto V_43;
return F_89 ( V_101 , V_104 , F_16 ( V_16 ) . V_25 ) ;
V_43:
F_72 ( V_104 ) ;
return V_43 ;
}
static int F_203 ( const struct V_13 * V_14 ,
struct V_253 * V_254 ,
const struct V_23 * V_24 )
{
struct V_23 * V_303 [ V_304 + 1 ] ;
int V_43 ;
V_43 = F_127 ( V_303 , V_304 , V_24 ,
V_305 , NULL ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_303 [ V_297 ] != NULL )
V_254 -> V_31 = F_41 ( F_42 ( V_303 [ V_297 ] ) ) ;
return 0 ;
}
static int F_204 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
struct V_102 * V_103 )
{
const struct V_76 * V_77 = F_62 ( V_18 ) ;
T_3 V_67 = F_97 ( V_1 ) ;
const struct V_250 * V_38 ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_56 * V_57 ;
struct V_13 V_14 ;
char V_68 [ V_272 ] ;
unsigned int V_31 ;
bool V_177 ;
T_4 V_288 ;
T_1 V_278 , V_283 , V_36 , V_165 , V_291 , V_287 ;
struct V_253 V_254 ;
unsigned char * V_232 ;
T_7 V_295 ;
int V_43 ;
if ( V_24 [ V_266 ] == NULL ||
V_24 [ V_276 ] == NULL ||
V_24 [ V_279 ] == NULL ||
V_24 [ V_60 ] == NULL )
return - V_69 ;
memset ( & V_254 , 0 , sizeof( V_254 ) ) ;
V_278 = V_306 ;
if ( V_24 [ V_277 ] != NULL ) {
V_278 = F_41 ( F_42 ( V_24 [ V_277 ] ) ) ;
if ( ( V_278 & V_307 ) == V_307 )
return - V_69 ;
}
V_254 . V_280 = F_41 ( F_42 ( V_24 [ V_279 ] ) ) ;
if ( V_254 . V_280 == 0 || V_254 . V_280 > V_308 )
return - V_69 ;
V_36 = 0 ;
if ( V_24 [ V_260 ] != NULL ) {
V_36 = F_41 ( F_42 ( V_24 [ V_260 ] ) ) ;
if ( V_36 & ~ ( V_129 | V_309 |
V_310 | V_311 |
V_281 | V_312 |
V_285 ) )
return - V_69 ;
if ( ( V_36 & ( V_281 | V_312 | V_285 ) ) ==
( V_281 | V_312 | V_285 ) )
return - V_116 ;
}
V_283 = 0 ;
if ( V_24 [ V_282 ] != NULL ) {
if ( ! ( V_36 & V_281 ) )
return - V_69 ;
V_283 = F_41 ( F_42 ( V_24 [ V_282 ] ) ) ;
if ( ( V_283 & V_307 ) == V_307 &&
V_283 != V_313 )
return - V_69 ;
if ( V_283 != V_313 ) {
if ( V_24 [ V_284 ] == NULL )
return - V_69 ;
V_254 . V_246 = F_41 ( F_42 ( V_24 [ V_284 ] ) ) ;
if ( V_254 . V_246 == 0 || V_254 . V_246 > V_308 )
return - V_69 ;
} else
V_254 . V_246 = sizeof( struct V_314 ) ;
} else if ( V_36 & V_281 )
return - V_69 ;
if ( V_24 [ V_286 ] != NULL ) {
if ( ! ( V_36 & V_285 ) )
return - V_69 ;
V_287 = F_41 ( F_42 ( V_24 [ V_286 ] ) ) ;
if ( V_287 == V_315 ||
V_287 > V_316 )
return - V_69 ;
} else if ( V_36 & V_285 )
return - V_69 ;
else
V_287 = V_315 ;
V_288 = 0 ;
if ( V_24 [ V_289 ] != NULL ) {
if ( ! ( V_36 & V_311 ) )
return - V_69 ;
V_288 = F_205 ( F_131 ( F_132 (
V_24 [ V_289 ] ) ) ) ;
}
V_291 = 0 ;
if ( V_24 [ V_292 ] != NULL ) {
if ( ! ( V_36 & V_311 ) )
return - V_69 ;
V_291 = F_41 ( F_42 ( V_24 [ V_292 ] ) ) ;
}
V_165 = V_264 ;
if ( V_24 [ V_293 ] != NULL )
V_165 = F_41 ( F_42 ( V_24 [ V_293 ] ) ) ;
if ( V_24 [ V_296 ] != NULL ) {
V_43 = F_203 ( & V_14 , & V_254 , V_24 [ V_296 ] ) ;
if ( V_43 < 0 )
return V_43 ;
}
V_177 = V_18 -> V_105 & V_191 ? true : false ;
V_3 = F_11 ( V_1 , V_77 -> V_79 , V_177 ) ;
if ( F_86 ( V_3 ) )
return F_87 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_266 ] , V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
V_57 = F_187 ( V_20 , V_24 [ V_276 ] , V_67 ) ;
if ( F_86 ( V_57 ) ) {
if ( F_87 ( V_57 ) != - V_51 )
return F_87 ( V_57 ) ;
} else {
if ( V_18 -> V_105 & V_113 )
return - V_114 ;
if ( V_18 -> V_105 & V_115 )
return - V_116 ;
return 0 ;
}
if ( ! ( V_18 -> V_105 & V_191 ) )
return - V_51 ;
V_38 = F_185 ( & V_14 , V_24 , & V_254 , V_165 ) ;
if ( F_86 ( V_38 ) )
return F_87 ( V_38 ) ;
V_295 = 0 ;
if ( V_24 [ V_294 ] )
V_295 = F_57 ( V_24 [ V_294 ] ) ;
V_31 = 0 ;
if ( V_38 -> V_317 != NULL )
V_31 = V_38 -> V_317 ( V_24 , & V_254 ) ;
V_57 = F_206 ( sizeof( * V_57 ) + V_31 + V_295 , V_34 ) ;
if ( ! V_57 ) {
V_43 = - V_40 ;
goto V_118;
}
F_99 ( V_68 , V_24 [ V_276 ] , sizeof( V_57 -> V_68 ) ) ;
V_43 = F_190 ( & V_14 , V_57 , V_68 ) ;
if ( V_43 < 0 )
goto V_119;
V_232 = NULL ;
if ( V_295 ) {
V_232 = V_57 -> V_209 + V_31 ;
F_179 ( V_232 , V_24 [ V_294 ] , V_295 ) ;
}
F_2 ( & V_57 -> V_130 ) ;
V_57 -> V_38 = V_38 ;
V_57 -> V_278 = V_278 ;
V_57 -> V_280 = V_254 . V_280 ;
V_57 -> V_283 = V_283 ;
V_57 -> V_287 = V_287 ;
V_57 -> V_246 = V_254 . V_246 ;
V_57 -> V_36 = V_36 ;
V_57 -> V_31 = V_254 . V_31 ;
V_57 -> V_165 = V_165 ;
V_57 -> V_295 = V_295 ;
V_57 -> V_232 = V_232 ;
V_57 -> V_288 = V_288 ;
V_57 -> V_291 = V_291 ;
V_43 = V_38 -> V_218 ( V_57 , & V_254 , V_24 ) ;
if ( V_43 < 0 )
goto V_119;
V_43 = F_45 ( & V_14 , V_59 , V_57 ) ;
if ( V_43 < 0 )
goto V_124;
F_4 ( & V_57 -> V_6 , & V_20 -> V_122 ) ;
V_20 -> V_48 ++ ;
return 0 ;
V_124:
V_38 -> V_221 ( V_57 ) ;
V_119:
F_207 ( V_57 ) ;
V_118:
F_100 ( V_38 -> type -> V_117 ) ;
return V_43 ;
}
static void F_208 ( struct V_56 * V_57 )
{
V_57 -> V_38 -> V_221 ( V_57 ) ;
F_100 ( V_57 -> V_38 -> type -> V_117 ) ;
F_207 ( V_57 ) ;
}
static void F_209 ( const struct V_13 * V_14 , struct V_56 * V_57 )
{
F_8 ( & V_57 -> V_6 ) ;
F_198 ( V_14 , V_57 , V_61 , V_318 ) ;
F_208 ( V_57 ) ;
}
static int F_210 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
struct V_102 * V_103 )
{
const struct V_76 * V_77 = F_62 ( V_18 ) ;
T_3 V_67 = F_97 ( V_1 ) ;
struct V_56 * V_57 ;
struct V_13 V_14 ;
int V_43 ;
if ( V_77 -> V_79 == V_95 )
return - V_12 ;
if ( V_24 [ V_266 ] == NULL )
return - V_69 ;
V_43 = F_186 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_67 ) ;
if ( V_43 < 0 )
return V_43 ;
V_57 = F_187 ( V_14 . V_20 , V_24 [ V_276 ] , V_67 ) ;
if ( F_86 ( V_57 ) )
return F_87 ( V_57 ) ;
if ( ! F_103 ( & V_57 -> V_130 ) )
return - V_135 ;
return F_47 ( & V_14 , V_57 ) ;
}
static int F_211 ( const struct V_13 * V_14 ,
struct V_56 * V_57 ,
const struct V_319 * V_320 ,
struct V_321 * V_322 )
{
const struct V_323 * V_324 = F_212 ( V_57 , V_322 -> V_200 ) ;
enum V_325 V_326 ;
V_326 = F_213 ( V_57 -> V_283 ) ;
return F_214 ( V_14 , V_326 , F_215 ( V_324 ) ,
V_57 -> V_283 == V_313 ?
V_313 : V_306 ,
V_57 -> V_246 ) ;
}
int F_216 ( const struct V_13 * V_14 , struct V_56 * V_57 ,
struct V_327 * V_328 )
{
struct V_327 * V_72 ;
struct V_319 V_320 ;
if ( ! F_103 ( & V_57 -> V_130 ) && V_57 -> V_36 & V_129 )
return - V_135 ;
if ( V_328 -> V_36 & V_281 ) {
F_10 (i, &set->bindings, list) {
if ( V_72 -> V_36 & V_281 &&
V_72 -> V_22 == V_328 -> V_22 )
goto V_329;
}
V_320 . V_67 = F_97 ( V_14 -> V_1 ) ;
V_320 . V_330 = 0 ;
V_320 . V_331 = 0 ;
V_320 . V_43 = 0 ;
V_320 . V_332 = F_211 ;
V_57 -> V_38 -> V_333 ( V_14 , V_57 , & V_320 ) ;
if ( V_320 . V_43 < 0 )
return V_320 . V_43 ;
}
V_329:
V_328 -> V_22 = V_14 -> V_22 ;
F_4 ( & V_328 -> V_6 , & V_57 -> V_130 ) ;
return 0 ;
}
void F_217 ( const struct V_13 * V_14 , struct V_56 * V_57 ,
struct V_327 * V_328 )
{
F_8 ( & V_328 -> V_6 ) ;
if ( F_103 ( & V_57 -> V_130 ) && V_57 -> V_36 & V_129 &&
F_79 ( V_14 -> V_1 , V_57 ) )
F_209 ( V_14 , V_57 ) ;
}
static int F_218 ( struct V_13 * V_14 , struct V_1 * V_1 ,
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
V_20 = F_53 ( V_3 , V_24 [ V_334 ] ,
V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
F_15 ( V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return 0 ;
}
static int F_219 ( struct V_15 * V_16 ,
const struct V_56 * V_57 ,
const struct V_321 * V_322 )
{
const struct V_323 * V_324 = F_212 ( V_57 , V_322 -> V_200 ) ;
unsigned char * V_335 = F_220 ( V_16 ) ;
struct V_23 * V_141 ;
V_141 = F_118 ( V_16 , V_231 ) ;
if ( V_141 == NULL )
goto V_78;
if ( F_221 ( V_16 , V_336 , F_222 ( V_324 ) ,
V_306 , V_57 -> V_280 ) < 0 )
goto V_78;
if ( F_223 ( V_324 , V_337 ) &&
F_221 ( V_16 , V_338 , F_215 ( V_324 ) ,
V_57 -> V_283 == V_313 ? V_313 : V_306 ,
V_57 -> V_246 ) < 0 )
goto V_78;
if ( F_223 ( V_324 , V_339 ) &&
F_156 ( V_16 , V_340 , F_224 ( V_324 ) ) < 0 )
goto V_78;
if ( F_223 ( V_324 , V_341 ) &&
F_64 ( V_16 , V_342 ,
( * F_225 ( V_324 ) ) -> V_68 ) < 0 )
goto V_78;
if ( F_223 ( V_324 , V_343 ) &&
F_65 ( V_16 , V_344 ,
F_66 ( * F_226 ( V_324 ) ) ) )
goto V_78;
if ( F_223 ( V_324 , V_345 ) &&
F_119 ( V_16 , V_346 ,
F_120 ( F_197 (
* F_227 ( V_324 ) ) ) ,
V_347 ) )
goto V_78;
if ( F_223 ( V_324 , V_348 ) ) {
unsigned long V_349 , V_350 = V_351 ;
V_349 = * F_228 ( V_324 ) ;
if ( F_229 ( V_350 , V_349 ) )
V_349 -= V_350 ;
else
V_349 = 0 ;
if ( F_119 ( V_16 , V_352 ,
F_120 ( F_197 ( V_349 ) ) ,
V_347 ) )
goto V_78;
}
if ( F_223 ( V_324 , V_353 ) ) {
struct V_233 * V_232 ;
V_232 = F_230 ( V_324 ) ;
if ( F_167 ( V_16 , V_354 ,
V_232 -> V_99 + 1 , V_232 -> V_209 ) )
goto V_78;
}
F_121 ( V_16 , V_141 ) ;
return 0 ;
V_78:
F_68 ( V_16 , V_335 ) ;
return - V_355 ;
}
static int F_231 ( const struct V_13 * V_14 ,
struct V_56 * V_57 ,
const struct V_319 * V_320 ,
struct V_321 * V_322 )
{
struct V_356 * args ;
args = F_232 ( V_320 , struct V_356 , V_320 ) ;
return F_219 ( args -> V_16 , V_57 , V_322 ) ;
}
static int F_233 ( struct V_15 * V_16 , struct V_90 * V_91 )
{
struct V_357 * V_358 = V_91 -> V_209 ;
struct V_1 * V_1 = F_76 ( V_16 -> V_94 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_56 * V_57 ;
struct V_356 args ;
bool V_359 = false ;
struct V_76 * V_77 ;
struct V_17 * V_18 ;
struct V_23 * V_141 ;
T_1 V_25 , V_27 ;
int V_75 ;
F_77 () ;
F_78 (afi, &net->nft.af_info, list) {
if ( V_3 != V_358 -> V_14 . V_3 )
continue;
F_78 (table, &afi->tables, list) {
if ( V_20 != V_358 -> V_14 . V_20 )
continue;
F_78 (set, &table->sets, list) {
if ( V_57 == V_358 -> V_57 ) {
V_359 = true ;
break;
}
}
break;
}
break;
}
if ( ! V_359 ) {
F_82 () ;
return - V_51 ;
}
V_75 = F_60 ( V_5 , V_360 ) ;
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
if ( F_64 ( V_16 , V_334 , V_20 -> V_68 ) )
goto V_78;
if ( F_64 ( V_16 , V_361 , V_57 -> V_68 ) )
goto V_78;
V_141 = F_118 ( V_16 , V_362 ) ;
if ( V_141 == NULL )
goto V_78;
args . V_91 = V_91 ;
args . V_16 = V_16 ;
args . V_320 . V_67 = F_84 ( V_1 ) ;
args . V_320 . V_330 = V_91 -> args [ 0 ] ;
args . V_320 . V_331 = 0 ;
args . V_320 . V_43 = 0 ;
args . V_320 . V_332 = F_231 ;
V_57 -> V_38 -> V_333 ( & V_358 -> V_14 , V_57 , & args . V_320 ) ;
F_82 () ;
F_121 ( V_16 , V_141 ) ;
F_67 ( V_16 , V_18 ) ;
if ( args . V_320 . V_43 && args . V_320 . V_43 != - V_355 )
return args . V_320 . V_43 ;
if ( args . V_320 . V_331 == V_91 -> args [ 0 ] )
return 0 ;
V_91 -> args [ 0 ] = args . V_320 . V_331 ;
return V_16 -> V_99 ;
V_78:
F_82 () ;
return - V_150 ;
}
static int F_234 ( struct V_90 * V_91 )
{
F_23 ( V_91 -> V_209 ) ;
return 0 ;
}
static int F_235 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
struct V_102 * V_103 )
{
T_3 V_67 = F_84 ( V_1 ) ;
const struct V_56 * V_57 ;
struct V_13 V_14 ;
int V_43 ;
V_43 = F_218 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_67 ) ;
if ( V_43 < 0 )
return V_43 ;
V_57 = F_187 ( V_14 . V_20 , V_24 [ V_361 ] ,
V_67 ) ;
if ( F_86 ( V_57 ) )
return F_87 ( V_57 ) ;
if ( V_18 -> V_105 & V_106 ) {
struct V_107 V_108 = {
. V_109 = F_233 ,
. V_98 = F_234 ,
} ;
struct V_357 * V_358 ;
V_358 = F_202 ( sizeof( * V_358 ) , V_34 ) ;
if ( ! V_358 )
return - V_40 ;
V_358 -> V_57 = V_57 ;
V_358 -> V_14 = V_14 ;
V_108 . V_209 = V_358 ;
return F_85 ( V_101 , V_16 , V_18 , & V_108 ) ;
}
return - V_116 ;
}
static int F_236 ( struct V_15 * V_16 ,
const struct V_13 * V_14 , T_1 V_27 ,
T_1 V_25 , int V_75 , T_7 V_36 ,
const struct V_56 * V_57 ,
const struct V_321 * V_322 )
{
struct V_76 * V_77 ;
struct V_17 * V_18 ;
struct V_23 * V_141 ;
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
if ( F_64 ( V_16 , V_266 , V_14 -> V_20 -> V_68 ) )
goto V_78;
if ( F_64 ( V_16 , V_276 , V_57 -> V_68 ) )
goto V_78;
V_141 = F_118 ( V_16 , V_362 ) ;
if ( V_141 == NULL )
goto V_78;
V_43 = F_219 ( V_16 , V_57 , V_322 ) ;
if ( V_43 < 0 )
goto V_78;
F_121 ( V_16 , V_141 ) ;
F_67 ( V_16 , V_18 ) ;
return 0 ;
V_78:
F_68 ( V_16 , V_18 ) ;
return - 1 ;
}
static void F_237 ( const struct V_13 * V_14 ,
const struct V_56 * V_57 ,
const struct V_321 * V_322 ,
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
V_43 = F_236 ( V_16 , V_14 , 0 , V_25 , V_75 , V_36 ,
V_57 , V_322 ) ;
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
static struct V_29 * F_238 ( struct V_13 * V_14 ,
int V_30 ,
struct V_56 * V_57 )
{
struct V_29 * V_33 ;
V_33 = F_20 ( V_14 , V_30 , sizeof( struct V_363 ) ) ;
if ( V_33 == NULL )
return NULL ;
F_239 ( V_33 ) = V_57 ;
return V_33 ;
}
void * F_240 ( const struct V_56 * V_57 ,
const struct V_364 * V_365 ,
const T_1 * V_366 , const T_1 * V_209 ,
T_4 V_288 , T_2 V_32 )
{
struct V_323 * V_324 ;
void * V_322 ;
V_322 = F_19 ( V_57 -> V_38 -> V_367 + V_365 -> V_99 , V_32 ) ;
if ( V_322 == NULL )
return NULL ;
V_324 = F_212 ( V_57 , V_322 ) ;
F_241 ( V_324 , V_365 ) ;
memcpy ( F_222 ( V_324 ) , V_366 , V_57 -> V_280 ) ;
if ( F_223 ( V_324 , V_337 ) )
memcpy ( F_215 ( V_324 ) , V_209 , V_57 -> V_246 ) ;
if ( F_223 ( V_324 , V_348 ) )
* F_228 ( V_324 ) =
V_351 + V_288 ;
if ( F_223 ( V_324 , V_345 ) )
* F_227 ( V_324 ) = V_288 ;
return V_322 ;
}
void F_242 ( const struct V_56 * V_57 , void * V_322 ,
bool V_368 )
{
struct V_323 * V_324 = F_212 ( V_57 , V_322 ) ;
F_243 ( F_222 ( V_324 ) , V_306 ) ;
if ( F_223 ( V_324 , V_337 ) )
F_243 ( F_215 ( V_324 ) , V_57 -> V_283 ) ;
if ( V_368 && F_223 ( V_324 , V_339 ) )
F_159 ( NULL , F_224 ( V_324 ) ) ;
if ( F_223 ( V_324 , V_341 ) )
( * F_225 ( V_324 ) ) -> V_48 -- ;
F_23 ( V_322 ) ;
}
static void F_244 ( const struct V_56 * V_57 , void * V_322 )
{
struct V_323 * V_324 = F_212 ( V_57 , V_322 ) ;
if ( F_223 ( V_324 , V_339 ) )
F_159 ( NULL , F_224 ( V_324 ) ) ;
F_23 ( V_322 ) ;
}
static int F_245 ( const struct V_56 * V_57 ,
const struct V_23 * V_168 , T_1 * V_36 )
{
if ( V_168 == NULL )
return 0 ;
* V_36 = F_41 ( F_42 ( V_168 ) ) ;
if ( * V_36 & ~ V_369 )
return - V_69 ;
if ( ! ( V_57 -> V_36 & V_310 ) &&
* V_36 & V_369 )
return - V_69 ;
return 0 ;
}
static int F_246 ( struct V_13 * V_14 , struct V_56 * V_57 ,
const struct V_23 * V_168 , T_1 V_105 )
{
struct V_23 * V_24 [ V_370 + 1 ] ;
T_3 V_67 = F_97 ( V_14 -> V_1 ) ;
struct V_371 V_372 , V_373 ;
struct V_364 V_365 ;
struct V_323 * V_324 , * V_374 ;
struct V_321 V_322 ;
struct V_327 * V_328 ;
struct V_62 * V_63 = NULL ;
struct V_233 * V_232 ;
struct V_220 V_209 ;
enum V_325 V_326 ;
struct V_29 * V_33 ;
T_1 V_36 = 0 ;
T_4 V_288 ;
T_3 V_240 ;
int V_43 ;
V_43 = F_127 ( V_24 , V_370 , V_168 ,
V_375 , NULL ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_24 [ V_336 ] == NULL )
return - V_69 ;
F_247 ( & V_365 ) ;
V_43 = F_245 ( V_57 , V_24 [ V_344 ] , & V_36 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_36 != 0 )
F_248 ( & V_365 , V_343 ) ;
if ( V_57 -> V_36 & V_281 ) {
if ( V_24 [ V_338 ] == NULL &&
! ( V_36 & V_369 ) )
return - V_69 ;
if ( V_24 [ V_338 ] != NULL &&
V_36 & V_369 )
return - V_69 ;
} else {
if ( V_24 [ V_338 ] != NULL )
return - V_69 ;
}
V_288 = 0 ;
if ( V_24 [ V_346 ] != NULL ) {
if ( ! ( V_57 -> V_36 & V_311 ) )
return - V_69 ;
V_288 = F_205 ( F_131 ( F_132 (
V_24 [ V_346 ] ) ) ) ;
} else if ( V_57 -> V_36 & V_311 ) {
V_288 = V_57 -> V_288 ;
}
V_43 = F_249 ( V_14 , & V_322 . V_366 . V_376 , sizeof( V_322 . V_366 ) , & V_372 ,
V_24 [ V_336 ] ) ;
if ( V_43 < 0 )
goto V_118;
V_43 = - V_69 ;
if ( V_372 . type != V_306 || V_372 . V_99 != V_57 -> V_280 )
goto V_119;
F_250 ( & V_365 , V_377 , V_372 . V_99 ) ;
if ( V_288 > 0 ) {
F_248 ( & V_365 , V_348 ) ;
if ( V_288 != V_57 -> V_288 )
F_248 ( & V_365 , V_345 ) ;
}
if ( V_24 [ V_342 ] != NULL ) {
if ( ! ( V_57 -> V_36 & V_285 ) ) {
V_43 = - V_69 ;
goto V_119;
}
V_63 = F_251 ( V_14 -> V_20 , V_24 [ V_342 ] ,
V_57 -> V_287 , V_67 ) ;
if ( F_86 ( V_63 ) ) {
V_43 = F_87 ( V_63 ) ;
goto V_119;
}
F_248 ( & V_365 , V_341 ) ;
}
if ( V_24 [ V_338 ] != NULL ) {
V_43 = F_249 ( V_14 , & V_209 , sizeof( V_209 ) , & V_373 ,
V_24 [ V_338 ] ) ;
if ( V_43 < 0 )
goto V_119;
V_43 = - V_69 ;
if ( V_57 -> V_283 != V_313 && V_373 . V_99 != V_57 -> V_246 )
goto V_124;
V_326 = F_213 ( V_57 -> V_283 ) ;
F_10 (binding, &set->bindings, list) {
struct V_13 V_378 = {
. V_1 = V_14 -> V_1 ,
. V_3 = V_14 -> V_3 ,
. V_20 = V_14 -> V_20 ,
. V_22 = (struct V_21 * ) V_328 -> V_22 ,
} ;
if ( ! ( V_328 -> V_36 & V_281 ) )
continue;
V_43 = F_214 ( & V_378 , V_326 ,
& V_209 ,
V_373 . type , V_373 . V_99 ) ;
if ( V_43 < 0 )
goto V_124;
}
F_250 ( & V_365 , V_337 , V_373 . V_99 ) ;
}
V_240 = 0 ;
if ( V_24 [ V_354 ] != NULL ) {
V_240 = F_57 ( V_24 [ V_354 ] ) ;
if ( V_240 > 0 )
F_250 ( & V_365 , V_353 ,
V_240 ) ;
}
V_43 = - V_40 ;
V_322 . V_200 = F_240 ( V_57 , & V_365 , V_322 . V_366 . V_376 . V_209 , V_209 . V_209 ,
V_288 , V_34 ) ;
if ( V_322 . V_200 == NULL )
goto V_124;
V_324 = F_212 ( V_57 , V_322 . V_200 ) ;
if ( V_36 )
* F_226 ( V_324 ) = V_36 ;
if ( V_240 > 0 ) {
V_232 = F_230 ( V_324 ) ;
V_232 -> V_99 = V_240 - 1 ;
F_179 ( & V_232 -> V_209 , V_24 [ V_354 ] , V_240 ) ;
}
if ( V_63 ) {
* F_225 ( V_324 ) = V_63 ;
V_63 -> V_48 ++ ;
}
V_33 = F_238 ( V_14 , V_360 , V_57 ) ;
if ( V_33 == NULL )
goto V_379;
V_324 -> V_67 = F_84 ( V_14 -> V_1 ) | V_380 ;
V_43 = V_57 -> V_38 -> V_381 ( V_14 -> V_1 , V_57 , & V_322 , & V_374 ) ;
if ( V_43 ) {
if ( V_43 == - V_114 ) {
if ( F_223 ( V_324 , V_337 ) ^
F_223 ( V_374 , V_337 ) ||
F_223 ( V_324 , V_341 ) ^
F_223 ( V_374 , V_341 ) )
return - V_135 ;
if ( ( F_223 ( V_324 , V_337 ) &&
F_223 ( V_374 , V_337 ) &&
memcmp ( F_215 ( V_324 ) ,
F_215 ( V_374 ) , V_57 -> V_246 ) != 0 ) ||
( F_223 ( V_324 , V_341 ) &&
F_223 ( V_374 , V_341 ) &&
* F_225 ( V_324 ) != * F_225 ( V_374 ) ) )
V_43 = - V_135 ;
else if ( ! ( V_105 & V_113 ) )
V_43 = 0 ;
}
goto V_382;
}
if ( V_57 -> V_31 &&
! F_252 ( & V_57 -> V_383 , 1 , V_57 -> V_31 + V_57 -> V_384 ) ) {
V_43 = - V_275 ;
goto V_385;
}
V_363 ( V_33 ) = V_322 ;
F_32 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_42 ) ;
return 0 ;
V_385:
V_57 -> V_38 -> remove ( V_14 -> V_1 , V_57 , & V_322 ) ;
V_382:
F_23 ( V_33 ) ;
V_379:
F_23 ( V_322 . V_200 ) ;
V_124:
if ( V_24 [ V_338 ] != NULL )
F_243 ( & V_209 , V_373 . type ) ;
V_119:
F_243 ( & V_322 . V_366 . V_376 , V_372 . type ) ;
V_118:
return V_43 ;
}
static int F_253 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
struct V_102 * V_103 )
{
T_3 V_67 = F_97 ( V_1 ) ;
const struct V_23 * V_168 ;
struct V_56 * V_57 ;
struct V_13 V_14 ;
int V_242 , V_43 = 0 ;
if ( V_24 [ V_362 ] == NULL )
return - V_69 ;
V_43 = F_218 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_67 ) ;
if ( V_43 < 0 )
return V_43 ;
V_57 = F_187 ( V_14 . V_20 , V_24 [ V_361 ] ,
V_67 ) ;
if ( F_86 ( V_57 ) ) {
if ( V_24 [ V_386 ] ) {
V_57 = F_188 ( V_1 ,
V_24 [ V_386 ] ,
V_67 ) ;
}
if ( F_86 ( V_57 ) )
return F_87 ( V_57 ) ;
}
if ( ! F_103 ( & V_57 -> V_130 ) && V_57 -> V_36 & V_309 )
return - V_135 ;
F_177 (attr, nla[NFTA_SET_ELEM_LIST_ELEMENTS], rem) {
V_43 = F_246 ( & V_14 , V_57 , V_168 , V_18 -> V_105 ) ;
if ( V_43 < 0 )
break;
}
return V_43 ;
}
static void F_254 ( const struct V_220 * V_209 , enum V_387 type )
{
if ( type == V_313 ) {
switch ( V_209 -> V_388 . V_389 ) {
case V_390 :
case V_391 :
V_209 -> V_388 . V_22 -> V_48 ++ ;
break;
}
}
}
static void F_255 ( const struct V_1 * V_1 ,
const struct V_56 * V_57 ,
struct V_321 * V_322 )
{
const struct V_323 * V_324 = F_212 ( V_57 , V_322 -> V_200 ) ;
if ( F_223 ( V_324 , V_337 ) )
F_254 ( F_215 ( V_324 ) , V_57 -> V_283 ) ;
if ( F_223 ( V_324 , V_341 ) )
( * F_225 ( V_324 ) ) -> V_48 ++ ;
}
static void F_256 ( const struct V_1 * V_1 ,
const struct V_56 * V_57 ,
struct V_321 * V_322 )
{
const struct V_323 * V_324 = F_212 ( V_57 , V_322 -> V_200 ) ;
if ( F_223 ( V_324 , V_337 ) )
F_243 ( F_215 ( V_324 ) , V_57 -> V_283 ) ;
if ( F_223 ( V_324 , V_341 ) )
( * F_225 ( V_324 ) ) -> V_48 -- ;
}
static int F_257 ( struct V_13 * V_14 , struct V_56 * V_57 ,
const struct V_23 * V_168 )
{
struct V_23 * V_24 [ V_370 + 1 ] ;
struct V_364 V_365 ;
struct V_371 V_254 ;
struct V_321 V_322 ;
struct V_323 * V_324 ;
struct V_29 * V_33 ;
T_1 V_36 = 0 ;
void * V_200 ;
int V_43 ;
V_43 = F_127 ( V_24 , V_370 , V_168 ,
V_375 , NULL ) ;
if ( V_43 < 0 )
goto V_118;
V_43 = - V_69 ;
if ( V_24 [ V_336 ] == NULL )
goto V_118;
F_247 ( & V_365 ) ;
V_43 = F_245 ( V_57 , V_24 [ V_344 ] , & V_36 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_36 != 0 )
F_248 ( & V_365 , V_343 ) ;
V_43 = F_249 ( V_14 , & V_322 . V_366 . V_376 , sizeof( V_322 . V_366 ) , & V_254 ,
V_24 [ V_336 ] ) ;
if ( V_43 < 0 )
goto V_118;
V_43 = - V_69 ;
if ( V_254 . type != V_306 || V_254 . V_99 != V_57 -> V_280 )
goto V_119;
F_250 ( & V_365 , V_377 , V_254 . V_99 ) ;
V_43 = - V_40 ;
V_322 . V_200 = F_240 ( V_57 , & V_365 , V_322 . V_366 . V_376 . V_209 , NULL , 0 ,
V_34 ) ;
if ( V_322 . V_200 == NULL )
goto V_119;
V_324 = F_212 ( V_57 , V_322 . V_200 ) ;
if ( V_36 )
* F_226 ( V_324 ) = V_36 ;
V_33 = F_238 ( V_14 , V_392 , V_57 ) ;
if ( V_33 == NULL ) {
V_43 = - V_40 ;
goto V_124;
}
V_200 = V_57 -> V_38 -> V_393 ( V_14 -> V_1 , V_57 , & V_322 ) ;
if ( V_200 == NULL ) {
V_43 = - V_51 ;
goto V_379;
}
F_23 ( V_322 . V_200 ) ;
V_322 . V_200 = V_200 ;
F_256 ( V_14 -> V_1 , V_57 , & V_322 ) ;
V_363 ( V_33 ) = V_322 ;
F_32 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_42 ) ;
return 0 ;
V_379:
F_23 ( V_33 ) ;
V_124:
F_23 ( V_322 . V_200 ) ;
V_119:
F_243 ( & V_322 . V_366 . V_376 , V_254 . type ) ;
V_118:
return V_43 ;
}
static int F_258 ( const struct V_13 * V_14 ,
struct V_56 * V_57 ,
const struct V_319 * V_320 ,
struct V_321 * V_322 )
{
struct V_29 * V_33 ;
int V_43 ;
V_33 = F_18 ( V_14 , V_392 ,
sizeof( struct V_363 ) , V_318 ) ;
if ( ! V_33 )
return - V_40 ;
if ( ! V_57 -> V_38 -> V_394 ( V_14 -> V_1 , V_57 , V_322 -> V_200 ) ) {
V_43 = - V_51 ;
goto V_118;
}
V_57 -> V_384 ++ ;
F_239 ( V_33 ) = V_57 ;
V_363 ( V_33 ) = * V_322 ;
F_32 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_42 ) ;
return 0 ;
V_118:
F_23 ( V_33 ) ;
return V_43 ;
}
static int F_259 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
struct V_102 * V_103 )
{
T_3 V_67 = F_97 ( V_1 ) ;
const struct V_23 * V_168 ;
struct V_56 * V_57 ;
struct V_13 V_14 ;
int V_242 , V_43 = 0 ;
V_43 = F_218 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_67 ) ;
if ( V_43 < 0 )
return V_43 ;
V_57 = F_187 ( V_14 . V_20 , V_24 [ V_361 ] ,
V_67 ) ;
if ( F_86 ( V_57 ) )
return F_87 ( V_57 ) ;
if ( ! F_103 ( & V_57 -> V_130 ) && V_57 -> V_36 & V_309 )
return - V_135 ;
if ( V_24 [ V_362 ] == NULL ) {
struct V_319 V_320 = {
. V_67 = V_67 ,
. V_332 = F_258 ,
} ;
V_57 -> V_38 -> V_333 ( & V_14 , V_57 , & V_320 ) ;
return V_320 . V_43 ;
}
F_177 (attr, nla[NFTA_SET_ELEM_LIST_ELEMENTS], rem) {
V_43 = F_257 ( & V_14 , V_57 , V_168 ) ;
if ( V_43 < 0 )
break;
V_57 -> V_384 ++ ;
}
return V_43 ;
}
void F_260 ( struct V_395 * V_396 )
{
struct V_397 * V_398 ;
unsigned int V_72 ;
V_398 = F_232 ( V_396 , struct V_397 , V_399 . V_396 ) ;
for ( V_72 = 0 ; V_72 < V_398 -> V_399 . V_110 ; V_72 ++ )
F_242 ( V_398 -> V_399 . V_57 , V_398 -> V_400 [ V_72 ] , true ) ;
F_23 ( V_398 ) ;
}
struct V_397 * F_261 ( const struct V_56 * V_57 ,
T_2 V_32 )
{
struct V_397 * V_398 ;
V_398 = F_19 ( sizeof( * V_398 ) , V_32 ) ;
if ( V_398 == NULL )
return V_398 ;
V_398 -> V_399 . V_57 = V_57 ;
return V_398 ;
}
int F_262 ( struct V_401 * V_402 )
{
if ( V_402 -> type == V_315 )
return - V_69 ;
F_3 ( V_5 ) ;
F_151 ( & V_402 -> V_6 , & V_403 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_263 ( struct V_401 * V_402 )
{
F_3 ( V_5 ) ;
F_8 ( & V_402 -> V_6 ) ;
F_5 ( V_5 ) ;
}
struct V_62 * F_251 ( const struct V_19 * V_20 ,
const struct V_23 * V_24 ,
T_1 V_287 , T_3 V_67 )
{
struct V_62 * V_63 ;
F_10 (obj, &table->objects, list) {
if ( ! F_51 ( V_24 , V_63 -> V_68 ) &&
V_287 == V_63 -> type -> type &&
F_52 ( V_63 , V_67 ) )
return V_63 ;
}
return F_14 ( - V_51 ) ;
}
static struct V_62 * F_264 ( const struct V_13 * V_14 ,
const struct V_401 * type ,
const struct V_23 * V_168 )
{
struct V_23 * V_169 [ type -> V_216 + 1 ] ;
struct V_62 * V_63 ;
int V_43 ;
if ( V_168 ) {
V_43 = F_127 ( V_169 , type -> V_216 , V_168 , type -> V_165 ,
NULL ) ;
if ( V_43 < 0 )
goto V_118;
} else {
memset ( V_169 , 0 , sizeof( V_169 [ 0 ] ) * ( type -> V_216 + 1 ) ) ;
}
V_43 = - V_40 ;
V_63 = F_19 ( sizeof( struct V_62 ) + type -> V_31 , V_34 ) ;
if ( V_63 == NULL )
goto V_118;
V_43 = type -> V_218 ( V_14 , ( const struct V_23 * const * ) V_169 , V_63 ) ;
if ( V_43 < 0 )
goto V_119;
V_63 -> type = type ;
return V_63 ;
V_119:
F_23 ( V_63 ) ;
V_118:
return F_14 ( V_43 ) ;
}
static int F_265 ( struct V_15 * V_16 , unsigned int V_168 ,
struct V_62 * V_63 , bool V_404 )
{
struct V_23 * V_141 ;
V_141 = F_118 ( V_16 , V_168 ) ;
if ( ! V_141 )
goto V_78;
if ( V_63 -> type -> V_109 ( V_16 , V_63 , V_404 ) < 0 )
goto V_78;
F_121 ( V_16 , V_141 ) ;
return 0 ;
V_78:
return - 1 ;
}
static const struct V_401 * F_266 ( T_1 V_287 )
{
const struct V_401 * type ;
F_10 (type, &nf_tables_objects, list) {
if ( V_287 == type -> type )
return type ;
}
return NULL ;
}
static const struct V_401 * F_267 ( T_1 V_287 )
{
const struct V_401 * type ;
type = F_266 ( V_287 ) ;
if ( type != NULL && F_98 ( type -> V_117 ) )
return type ;
#ifdef F_12
if ( type == NULL ) {
F_5 ( V_5 ) ;
F_13 ( L_6 , V_287 ) ;
F_3 ( V_5 ) ;
if ( F_266 ( V_287 ) )
return F_14 ( - V_11 ) ;
}
#endif
return F_14 ( - V_51 ) ;
}
static int F_268 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
struct V_102 * V_103 )
{
const struct V_76 * V_77 = F_62 ( V_18 ) ;
const struct V_401 * type ;
T_3 V_67 = F_97 ( V_1 ) ;
int V_9 = V_77 -> V_79 ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_62 * V_63 ;
struct V_13 V_14 ;
T_1 V_287 ;
int V_43 ;
if ( ! V_24 [ V_405 ] ||
! V_24 [ V_406 ] ||
! V_24 [ V_407 ] )
return - V_69 ;
V_3 = F_11 ( V_1 , V_9 , true ) ;
if ( F_86 ( V_3 ) )
return F_87 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_408 ] , V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
V_287 = F_41 ( F_42 ( V_24 [ V_405 ] ) ) ;
V_63 = F_251 ( V_20 , V_24 [ V_406 ] , V_287 , V_67 ) ;
if ( F_86 ( V_63 ) ) {
V_43 = F_87 ( V_63 ) ;
if ( V_43 != - V_51 )
return V_43 ;
} else {
if ( V_18 -> V_105 & V_113 )
return - V_114 ;
return 0 ;
}
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
type = F_267 ( V_287 ) ;
if ( F_86 ( type ) )
return F_87 ( type ) ;
V_63 = F_264 ( & V_14 , type , V_24 [ V_407 ] ) ;
if ( F_86 ( V_63 ) ) {
V_43 = F_87 ( V_63 ) ;
goto V_118;
}
V_63 -> V_20 = V_20 ;
F_99 ( V_63 -> V_68 , V_24 [ V_406 ] , V_409 ) ;
V_43 = F_48 ( & V_14 , V_65 , V_63 ) ;
if ( V_43 < 0 )
goto V_119;
F_4 ( & V_63 -> V_6 , & V_20 -> V_123 ) ;
V_20 -> V_48 ++ ;
return 0 ;
V_119:
if ( V_63 -> type -> V_221 )
V_63 -> type -> V_221 ( V_63 ) ;
F_23 ( V_63 ) ;
V_118:
F_100 ( type -> V_117 ) ;
return V_43 ;
}
static int F_269 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_25 , T_1 V_27 , int V_75 , T_1 V_36 ,
int V_9 , const struct V_19 * V_20 ,
struct V_62 * V_63 , bool V_404 )
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
if ( F_64 ( V_16 , V_408 , V_20 -> V_68 ) ||
F_64 ( V_16 , V_406 , V_63 -> V_68 ) ||
F_65 ( V_16 , V_405 , F_66 ( V_63 -> type -> type ) ) ||
F_65 ( V_16 , V_410 , F_66 ( V_63 -> V_48 ) ) ||
F_265 ( V_16 , V_407 , V_63 , V_404 ) )
goto V_78;
F_67 ( V_16 , V_18 ) ;
return 0 ;
V_78:
F_68 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_270 ( struct V_15 * V_16 , struct V_90 * V_91 )
{
const struct V_76 * V_77 = F_62 ( V_91 -> V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
unsigned int V_92 = 0 , V_93 = V_91 -> args [ 0 ] ;
struct V_411 * V_412 = V_91 -> V_209 ;
struct V_1 * V_1 = F_76 ( V_16 -> V_94 ) ;
int V_9 = V_77 -> V_79 ;
struct V_62 * V_63 ;
bool V_404 = false ;
if ( F_271 ( V_91 -> V_18 -> V_413 ) == V_414 )
V_404 = true ;
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
if ( V_412 && V_412 -> V_20 [ 0 ] &&
strcmp ( V_412 -> V_20 , V_20 -> V_68 ) )
goto V_96;
if ( V_412 &&
V_412 -> type != V_315 &&
V_63 -> type -> type != V_412 -> type )
goto V_96;
if ( F_269 ( V_16 , V_1 , F_16 ( V_91 -> V_16 ) . V_25 ,
V_91 -> V_18 -> V_28 ,
V_65 ,
V_97 | V_236 ,
V_3 -> V_9 , V_20 , V_63 , V_404 ) < 0 )
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
static int F_272 ( struct V_90 * V_91 )
{
F_23 ( V_91 -> V_209 ) ;
return 0 ;
}
static struct V_411 *
F_273 ( const struct V_23 * const V_24 [] )
{
struct V_411 * V_412 ;
V_412 = F_19 ( sizeof( * V_412 ) , V_34 ) ;
if ( ! V_412 )
return F_14 ( - V_40 ) ;
if ( V_24 [ V_408 ] )
F_99 ( V_412 -> V_20 , V_24 [ V_408 ] ,
V_120 ) ;
if ( V_24 [ V_405 ] )
V_412 -> type = F_41 ( F_42 ( V_24 [ V_405 ] ) ) ;
return V_412 ;
}
static int F_274 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
struct V_102 * V_103 )
{
const struct V_76 * V_77 = F_62 ( V_18 ) ;
T_3 V_67 = F_84 ( V_1 ) ;
int V_9 = V_77 -> V_79 ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
struct V_62 * V_63 ;
struct V_15 * V_104 ;
bool V_404 = false ;
T_1 V_287 ;
int V_43 ;
if ( V_18 -> V_105 & V_106 ) {
struct V_107 V_108 = {
. V_109 = F_270 ,
. V_98 = F_272 ,
} ;
if ( V_24 [ V_408 ] ||
V_24 [ V_405 ] ) {
struct V_411 * V_412 ;
V_412 = F_273 ( V_24 ) ;
if ( F_86 ( V_412 ) )
return - V_40 ;
V_108 . V_209 = V_412 ;
}
return F_85 ( V_101 , V_16 , V_18 , & V_108 ) ;
}
if ( ! V_24 [ V_406 ] ||
! V_24 [ V_405 ] )
return - V_69 ;
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_86 ( V_3 ) )
return F_87 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_408 ] , V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
V_287 = F_41 ( F_42 ( V_24 [ V_405 ] ) ) ;
V_63 = F_251 ( V_20 , V_24 [ V_406 ] , V_287 , V_67 ) ;
if ( F_86 ( V_63 ) )
return F_87 ( V_63 ) ;
V_104 = F_88 ( V_88 , V_34 ) ;
if ( ! V_104 )
return - V_40 ;
if ( F_271 ( V_18 -> V_413 ) == V_414 )
V_404 = true ;
V_43 = F_269 ( V_104 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 , V_65 , 0 ,
V_9 , V_20 , V_63 , V_404 ) ;
if ( V_43 < 0 )
goto V_43;
return F_89 ( V_101 , V_104 , F_16 ( V_16 ) . V_25 ) ;
V_43:
F_72 ( V_104 ) ;
return V_43 ;
}
static void F_275 ( struct V_62 * V_63 )
{
if ( V_63 -> type -> V_221 )
V_63 -> type -> V_221 ( V_63 ) ;
F_100 ( V_63 -> type -> V_117 ) ;
F_23 ( V_63 ) ;
}
static int F_276 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
struct V_102 * V_103 )
{
const struct V_76 * V_77 = F_62 ( V_18 ) ;
T_3 V_67 = F_97 ( V_1 ) ;
int V_9 = V_77 -> V_79 ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_62 * V_63 ;
struct V_13 V_14 ;
T_1 V_287 ;
if ( ! V_24 [ V_405 ] ||
! V_24 [ V_406 ] )
return - V_69 ;
V_3 = F_11 ( V_1 , V_9 , true ) ;
if ( F_86 ( V_3 ) )
return F_87 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_408 ] , V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
V_287 = F_41 ( F_42 ( V_24 [ V_405 ] ) ) ;
V_63 = F_251 ( V_20 , V_24 [ V_406 ] , V_287 , V_67 ) ;
if ( F_86 ( V_63 ) )
return F_87 ( V_63 ) ;
if ( V_63 -> V_48 > 0 )
return - V_135 ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return F_49 ( & V_14 , V_63 ) ;
}
void F_277 ( struct V_1 * V_1 , struct V_19 * V_20 ,
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
V_43 = F_269 ( V_16 , V_1 , V_25 , V_27 , V_75 , 0 , V_9 ,
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
static void F_278 ( const struct V_13 * V_14 ,
struct V_62 * V_63 , int V_75 )
{
F_277 ( V_14 -> V_1 , V_14 -> V_20 , V_63 , V_14 -> V_25 , V_14 -> V_27 , V_75 ,
V_14 -> V_3 -> V_9 , V_14 -> V_26 , V_34 ) ;
}
static int F_279 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_25 , T_1 V_27 )
{
struct V_17 * V_18 ;
struct V_76 * V_77 ;
int V_75 = F_60 ( V_5 , V_415 ) ;
V_18 = F_61 ( V_16 , V_25 , V_27 , V_75 , sizeof( struct V_76 ) , 0 ) ;
if ( V_18 == NULL )
goto V_78;
V_77 = F_62 ( V_18 ) ;
V_77 -> V_79 = V_132 ;
V_77 -> V_80 = V_81 ;
V_77 -> V_82 = F_63 ( V_1 -> V_7 . V_83 & 0xffff ) ;
if ( F_65 ( V_16 , V_416 , F_66 ( V_1 -> V_7 . V_83 ) ) )
goto V_78;
F_67 ( V_16 , V_18 ) ;
return 0 ;
V_78:
F_68 ( V_16 , V_18 ) ;
return - V_355 ;
}
static void F_280 ( struct V_1 * V_1 , struct V_15 * V_16 ,
int V_75 )
{
struct V_17 * V_18 = F_81 ( V_16 ) ;
struct V_15 * V_104 ;
int V_43 ;
if ( F_17 ( V_18 ) &&
! F_70 ( V_1 , V_87 ) )
return;
V_104 = F_71 ( V_88 , V_34 ) ;
if ( V_104 == NULL )
goto V_43;
V_43 = F_279 ( V_104 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 ) ;
if ( V_43 < 0 ) {
F_72 ( V_104 ) ;
goto V_43;
}
F_73 ( V_104 , V_1 , F_16 ( V_16 ) . V_25 , V_87 ,
F_17 ( V_18 ) , V_34 ) ;
return;
V_43:
F_74 ( V_1 , F_16 ( V_16 ) . V_25 , V_87 ,
- V_89 ) ;
}
static int F_281 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
struct V_102 * V_103 )
{
struct V_15 * V_104 ;
int V_43 ;
V_104 = F_88 ( V_88 , V_34 ) ;
if ( V_104 == NULL )
return - V_40 ;
V_43 = F_279 ( V_104 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 ) ;
if ( V_43 < 0 )
goto V_43;
return F_89 ( V_101 , V_104 , F_16 ( V_16 ) . V_25 ) ;
V_43:
F_72 ( V_104 ) ;
return V_43 ;
}
static void F_282 ( struct V_29 * V_33 )
{
struct F_27 * V_155 ;
if ( F_148 ( V_33 ) [ 0 ] )
strcpy ( V_33 -> V_14 . V_22 -> V_68 , F_148 ( V_33 ) ) ;
if ( ! F_25 ( V_33 -> V_14 . V_22 ) )
return;
V_155 = F_27 ( V_33 -> V_14 . V_22 ) ;
F_134 ( V_155 , F_145 ( V_33 ) ) ;
switch ( F_147 ( V_33 ) ) {
case V_192 :
case V_190 :
V_155 -> V_165 = F_147 ( V_33 ) ;
break;
}
}
static void F_283 ( struct V_29 * V_33 )
{
switch ( V_33 -> V_30 ) {
case V_44 :
F_106 ( & V_33 -> V_14 ) ;
break;
case V_47 :
F_139 ( V_33 -> V_14 . V_22 ) ;
break;
case V_55 :
F_172 ( & V_33 -> V_14 , V_52 ( V_33 ) ) ;
break;
case V_61 :
F_208 ( V_58 ( V_33 ) ) ;
break;
case V_392 :
F_244 ( F_239 ( V_33 ) ,
V_363 ( V_33 ) . V_200 ) ;
break;
case V_66 :
F_275 ( V_64 ( V_33 ) ) ;
break;
}
F_23 ( V_33 ) ;
}
static int F_284 ( struct V_1 * V_1 , struct V_15 * V_16 )
{
struct V_29 * V_33 , * V_222 ;
struct V_363 * V_417 ;
while ( ++ V_1 -> V_7 . V_83 == 0 ) ;
V_1 -> V_7 . V_418 = F_285 ( V_1 ) ;
F_137 () ;
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
F_286 ( V_1 , V_33 -> V_14 . V_20 ) ;
}
F_69 ( & V_33 -> V_14 , V_41 ) ;
F_21 ( V_33 ) ;
break;
case V_44 :
F_8 ( & V_33 -> V_14 . V_20 -> V_6 ) ;
F_69 ( & V_33 -> V_14 , V_44 ) ;
break;
case V_46 :
if ( F_146 ( V_33 ) )
F_282 ( V_33 ) ;
else
F_286 ( V_1 , V_33 -> V_14 . V_22 ) ;
F_123 ( & V_33 -> V_14 , V_46 ) ;
F_21 ( V_33 ) ;
break;
case V_47 :
F_8 ( & V_33 -> V_14 . V_22 -> V_6 ) ;
F_123 ( & V_33 -> V_14 , V_47 ) ;
F_28 ( V_33 -> V_14 . V_1 ,
V_33 -> V_14 . V_20 ,
V_33 -> V_14 . V_22 ,
V_33 -> V_14 . V_3 -> V_111 ) ;
break;
case V_53 :
F_286 ( V_33 -> V_14 . V_1 , V_52 ( V_33 ) ) ;
F_168 ( & V_33 -> V_14 ,
V_52 ( V_33 ) ,
V_53 ) ;
F_21 ( V_33 ) ;
break;
case V_55 :
F_8 ( & V_52 ( V_33 ) -> V_6 ) ;
F_168 ( & V_33 -> V_14 ,
V_52 ( V_33 ) ,
V_55 ) ;
break;
case V_59 :
F_286 ( V_1 , V_58 ( V_33 ) ) ;
if ( V_58 ( V_33 ) -> V_36 & V_129 &&
! F_103 ( & V_58 ( V_33 ) -> V_130 ) )
V_33 -> V_14 . V_20 -> V_48 -- ;
F_198 ( & V_33 -> V_14 , V_58 ( V_33 ) ,
V_59 , V_34 ) ;
F_21 ( V_33 ) ;
break;
case V_61 :
F_8 ( & V_58 ( V_33 ) -> V_6 ) ;
F_198 ( & V_33 -> V_14 , V_58 ( V_33 ) ,
V_61 , V_34 ) ;
break;
case V_360 :
V_417 = (struct V_363 * ) V_33 -> V_209 ;
V_417 -> V_57 -> V_38 -> V_419 ( V_1 , V_417 -> V_57 , & V_417 -> V_322 ) ;
F_237 ( & V_33 -> V_14 , V_417 -> V_57 ,
& V_417 -> V_322 ,
V_360 , 0 ) ;
F_21 ( V_33 ) ;
break;
case V_392 :
V_417 = (struct V_363 * ) V_33 -> V_209 ;
F_237 ( & V_33 -> V_14 , V_417 -> V_57 ,
& V_417 -> V_322 ,
V_392 , 0 ) ;
V_417 -> V_57 -> V_38 -> remove ( V_1 , V_417 -> V_57 , & V_417 -> V_322 ) ;
F_287 ( & V_417 -> V_57 -> V_383 ) ;
V_417 -> V_57 -> V_384 -- ;
break;
case V_65 :
F_286 ( V_1 , V_64 ( V_33 ) ) ;
F_278 ( & V_33 -> V_14 , V_64 ( V_33 ) ,
V_65 ) ;
F_21 ( V_33 ) ;
break;
case V_66 :
F_8 ( & V_64 ( V_33 ) -> V_6 ) ;
F_278 ( & V_33 -> V_14 , V_64 ( V_33 ) ,
V_66 ) ;
break;
}
}
F_137 () ;
F_102 (trans, next, &net->nft.commit_list, list) {
F_22 ( & V_33 -> V_6 ) ;
F_283 ( V_33 ) ;
}
F_280 ( V_1 , V_16 , V_415 ) ;
return 0 ;
}
static void F_288 ( struct V_29 * V_33 )
{
switch ( V_33 -> V_30 ) {
case V_41 :
F_106 ( & V_33 -> V_14 ) ;
break;
case V_46 :
F_139 ( V_33 -> V_14 . V_22 ) ;
break;
case V_53 :
F_172 ( & V_33 -> V_14 , V_52 ( V_33 ) ) ;
break;
case V_59 :
F_208 ( V_58 ( V_33 ) ) ;
break;
case V_360 :
F_242 ( F_239 ( V_33 ) ,
V_363 ( V_33 ) . V_200 , true ) ;
break;
case V_65 :
F_275 ( V_64 ( V_33 ) ) ;
break;
}
F_23 ( V_33 ) ;
}
static int F_289 ( struct V_1 * V_1 , struct V_15 * V_16 )
{
struct V_29 * V_33 , * V_222 ;
struct V_363 * V_417 ;
F_290 (trans, next, &net->nft.commit_list,
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
F_286 ( V_33 -> V_14 . V_1 , V_33 -> V_14 . V_20 ) ;
F_21 ( V_33 ) ;
break;
case V_46 :
if ( F_146 ( V_33 ) ) {
F_138 ( F_145 ( V_33 ) ) ;
F_21 ( V_33 ) ;
} else {
V_33 -> V_14 . V_20 -> V_48 -- ;
F_8 ( & V_33 -> V_14 . V_22 -> V_6 ) ;
F_28 ( V_33 -> V_14 . V_1 ,
V_33 -> V_14 . V_20 ,
V_33 -> V_14 . V_22 ,
V_33 -> V_14 . V_3 -> V_111 ) ;
}
break;
case V_47 :
V_33 -> V_14 . V_20 -> V_48 ++ ;
F_286 ( V_33 -> V_14 . V_1 , V_33 -> V_14 . V_22 ) ;
F_21 ( V_33 ) ;
break;
case V_53 :
V_33 -> V_14 . V_22 -> V_48 -- ;
F_8 ( & V_52 ( V_33 ) -> V_6 ) ;
break;
case V_55 :
V_33 -> V_14 . V_22 -> V_48 ++ ;
F_286 ( V_33 -> V_14 . V_1 , V_52 ( V_33 ) ) ;
F_21 ( V_33 ) ;
break;
case V_59 :
V_33 -> V_14 . V_20 -> V_48 -- ;
F_8 ( & V_58 ( V_33 ) -> V_6 ) ;
break;
case V_61 :
V_33 -> V_14 . V_20 -> V_48 ++ ;
F_286 ( V_33 -> V_14 . V_1 , V_58 ( V_33 ) ) ;
F_21 ( V_33 ) ;
break;
case V_360 :
V_417 = (struct V_363 * ) V_33 -> V_209 ;
V_417 -> V_57 -> V_38 -> remove ( V_1 , V_417 -> V_57 , & V_417 -> V_322 ) ;
F_287 ( & V_417 -> V_57 -> V_383 ) ;
break;
case V_392 :
V_417 = (struct V_363 * ) V_33 -> V_209 ;
F_255 ( V_1 , V_417 -> V_57 , & V_417 -> V_322 ) ;
V_417 -> V_57 -> V_38 -> V_419 ( V_1 , V_417 -> V_57 , & V_417 -> V_322 ) ;
V_417 -> V_57 -> V_384 -- ;
F_21 ( V_33 ) ;
break;
case V_65 :
V_33 -> V_14 . V_20 -> V_48 -- ;
F_8 ( & V_64 ( V_33 ) -> V_6 ) ;
break;
case V_66 :
V_33 -> V_14 . V_20 -> V_48 ++ ;
F_286 ( V_33 -> V_14 . V_1 , V_64 ( V_33 ) ) ;
F_21 ( V_33 ) ;
break;
}
}
F_137 () ;
F_290 (trans, next,
&net->nft.commit_list, list) {
F_22 ( & V_33 -> V_6 ) ;
F_288 ( V_33 ) ;
}
return 0 ;
}
static bool F_291 ( struct V_1 * V_1 , T_1 V_420 )
{
return V_1 -> V_7 . V_83 == V_420 ;
}
int F_292 ( const struct V_21 * V_22 ,
enum V_421 type )
{
const struct F_27 * V_155 ;
if ( F_25 ( V_22 ) ) {
V_155 = F_27 ( V_22 ) ;
if ( V_155 -> type -> type != type )
return - V_116 ;
}
return 0 ;
}
int F_293 ( const struct V_21 * V_22 ,
unsigned int V_422 )
{
struct F_27 * V_155 ;
if ( F_25 ( V_22 ) ) {
V_155 = F_27 ( V_22 ) ;
if ( ( 1 << V_155 -> V_38 [ 0 ] . V_159 ) & V_422 )
return 0 ;
return - V_116 ;
}
return 0 ;
}
static int F_294 ( const struct V_13 * V_14 ,
struct V_56 * V_57 ,
const struct V_319 * V_320 ,
struct V_321 * V_322 )
{
const struct V_323 * V_324 = F_212 ( V_57 , V_322 -> V_200 ) ;
const struct V_220 * V_209 ;
if ( F_223 ( V_324 , V_343 ) &&
* F_226 ( V_324 ) & V_369 )
return 0 ;
V_209 = F_215 ( V_324 ) ;
switch ( V_209 -> V_388 . V_389 ) {
case V_390 :
case V_391 :
return F_295 ( V_14 , V_209 -> V_388 . V_22 ) ;
default:
return 0 ;
}
}
static int F_295 ( const struct V_13 * V_14 ,
const struct V_21 * V_22 )
{
const struct V_49 * V_50 ;
const struct V_206 * V_207 , * V_423 ;
struct V_56 * V_57 ;
struct V_327 * V_328 ;
struct V_319 V_320 ;
if ( V_14 -> V_22 == V_22 )
return - V_424 ;
F_10 (rule, &chain->rules, list) {
F_166 (expr, last, rule) {
const struct V_220 * V_209 = NULL ;
int V_43 ;
if ( ! V_207 -> V_38 -> V_219 )
continue;
V_43 = V_207 -> V_38 -> V_219 ( V_14 , V_207 , & V_209 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_209 == NULL )
continue;
switch ( V_209 -> V_388 . V_389 ) {
case V_390 :
case V_391 :
V_43 = F_295 ( V_14 ,
V_209 -> V_388 . V_22 ) ;
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
if ( ! ( V_57 -> V_36 & V_281 ) ||
V_57 -> V_283 != V_313 )
continue;
F_10 (binding, &set->bindings, list) {
if ( ! ( V_328 -> V_36 & V_281 ) ||
V_328 -> V_22 != V_22 )
continue;
V_320 . V_67 = F_97 ( V_14 -> V_1 ) ;
V_320 . V_330 = 0 ;
V_320 . V_331 = 0 ;
V_320 . V_43 = 0 ;
V_320 . V_332 = F_294 ;
V_57 -> V_38 -> V_333 ( V_14 , V_57 , & V_320 ) ;
if ( V_320 . V_43 < 0 )
return V_320 . V_43 ;
}
}
return 0 ;
}
int F_296 ( const struct V_23 * V_168 , int V_425 , T_1 * V_426 )
{
T_1 V_376 ;
V_376 = F_41 ( F_42 ( V_168 ) ) ;
if ( V_376 > V_425 )
return - V_427 ;
* V_426 = V_376 ;
return 0 ;
}
unsigned int F_297 ( const struct V_23 * V_168 )
{
unsigned int V_428 ;
V_428 = F_41 ( F_42 ( V_168 ) ) ;
switch ( V_428 ) {
case V_429 ... V_430 :
return V_428 * V_431 / V_432 ;
default:
return V_428 + V_431 / V_432 - V_433 ;
}
}
int F_298 ( struct V_15 * V_16 , unsigned int V_168 , unsigned int V_428 )
{
if ( V_428 % ( V_431 / V_432 ) == 0 )
V_428 = V_428 / ( V_431 / V_432 ) ;
else
V_428 = V_428 - V_431 / V_432 + V_433 ;
return F_65 ( V_16 , V_168 , F_66 ( V_428 ) ) ;
}
int F_299 ( enum V_325 V_428 , unsigned int V_99 )
{
if ( V_428 < V_434 * V_431 / V_432 )
return - V_69 ;
if ( V_99 == 0 )
return - V_69 ;
if ( V_428 * V_432 + V_99 > F_300 ( struct V_435 , V_209 ) )
return - V_427 ;
return 0 ;
}
int F_214 ( const struct V_13 * V_14 ,
enum V_325 V_428 ,
const struct V_220 * V_209 ,
enum V_387 type , unsigned int V_99 )
{
int V_43 ;
switch ( V_428 ) {
case V_429 :
if ( type != V_313 )
return - V_69 ;
if ( V_209 != NULL &&
( V_209 -> V_388 . V_389 == V_391 ||
V_209 -> V_388 . V_389 == V_390 ) ) {
V_43 = F_295 ( V_14 , V_209 -> V_388 . V_22 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_14 -> V_22 -> V_436 + 1 >
V_209 -> V_388 . V_22 -> V_436 ) {
if ( V_14 -> V_22 -> V_436 + 1 == V_437 )
return - V_438 ;
V_209 -> V_388 . V_22 -> V_436 = V_14 -> V_22 -> V_436 + 1 ;
}
}
return 0 ;
default:
if ( V_428 < V_434 * V_431 / V_432 )
return - V_69 ;
if ( V_99 == 0 )
return - V_69 ;
if ( V_428 * V_432 + V_99 >
F_300 ( struct V_435 , V_209 ) )
return - V_427 ;
if ( V_209 != NULL && type != V_306 )
return - V_69 ;
return 0 ;
}
}
static int F_301 ( const struct V_13 * V_14 , struct V_220 * V_209 ,
struct V_371 * V_254 , const struct V_23 * V_24 )
{
T_3 V_67 = F_97 ( V_14 -> V_1 ) ;
struct V_23 * V_169 [ V_439 + 1 ] ;
struct V_21 * V_22 ;
int V_43 ;
V_43 = F_127 ( V_169 , V_439 , V_24 , V_440 ,
NULL ) ;
if ( V_43 < 0 )
return V_43 ;
if ( ! V_169 [ V_441 ] )
return - V_69 ;
V_209 -> V_388 . V_389 = F_41 ( F_42 ( V_169 [ V_441 ] ) ) ;
switch ( V_209 -> V_388 . V_389 ) {
default:
switch ( V_209 -> V_388 . V_389 & V_442 ) {
case V_190 :
case V_192 :
case V_443 :
break;
default:
return - V_69 ;
}
case V_444 :
case V_445 :
case V_446 :
break;
case V_390 :
case V_391 :
if ( ! V_169 [ V_447 ] )
return - V_69 ;
V_22 = F_112 ( V_14 -> V_20 ,
V_169 [ V_447 ] , V_67 ) ;
if ( F_86 ( V_22 ) )
return F_87 ( V_22 ) ;
if ( F_25 ( V_22 ) )
return - V_116 ;
V_22 -> V_48 ++ ;
V_209 -> V_388 . V_22 = V_22 ;
break;
}
V_254 -> V_99 = sizeof( V_209 -> V_388 ) ;
V_254 -> type = V_313 ;
return 0 ;
}
static void F_302 ( const struct V_220 * V_209 )
{
switch ( V_209 -> V_388 . V_389 ) {
case V_390 :
case V_391 :
V_209 -> V_388 . V_22 -> V_48 -- ;
break;
}
}
int F_303 ( struct V_15 * V_16 , int type , const struct V_314 * V_448 )
{
struct V_23 * V_141 ;
V_141 = F_118 ( V_16 , type ) ;
if ( ! V_141 )
goto V_78;
if ( F_65 ( V_16 , V_441 , F_66 ( V_448 -> V_389 ) ) )
goto V_78;
switch ( V_448 -> V_389 ) {
case V_390 :
case V_391 :
if ( F_64 ( V_16 , V_447 ,
V_448 -> V_22 -> V_68 ) )
goto V_78;
}
F_121 ( V_16 , V_141 ) ;
return 0 ;
V_78:
return - 1 ;
}
static int F_304 ( const struct V_13 * V_14 ,
struct V_220 * V_209 , unsigned int V_31 ,
struct V_371 * V_254 , const struct V_23 * V_24 )
{
unsigned int V_99 ;
V_99 = F_57 ( V_24 ) ;
if ( V_99 == 0 )
return - V_69 ;
if ( V_99 > V_31 )
return - V_196 ;
F_179 ( V_209 -> V_209 , V_24 , V_99 ) ;
V_254 -> type = V_306 ;
V_254 -> V_99 = V_99 ;
return 0 ;
}
static int F_305 ( struct V_15 * V_16 , const struct V_220 * V_209 ,
unsigned int V_99 )
{
return F_167 ( V_16 , V_449 , V_99 , V_209 -> V_209 ) ;
}
int F_249 ( const struct V_13 * V_14 ,
struct V_220 * V_209 , unsigned int V_31 ,
struct V_371 * V_254 , const struct V_23 * V_24 )
{
struct V_23 * V_169 [ V_450 + 1 ] ;
int V_43 ;
V_43 = F_127 ( V_169 , V_450 , V_24 , V_451 , NULL ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_169 [ V_449 ] )
return F_304 ( V_14 , V_209 , V_31 , V_254 ,
V_169 [ V_449 ] ) ;
if ( V_169 [ V_452 ] && V_14 != NULL )
return F_301 ( V_14 , V_209 , V_254 , V_169 [ V_452 ] ) ;
return - V_69 ;
}
void F_243 ( const struct V_220 * V_209 , enum V_387 type )
{
if ( type < V_313 )
return;
switch ( type ) {
case V_313 :
return F_302 ( V_209 ) ;
default:
F_109 ( 1 ) ;
}
}
int F_221 ( struct V_15 * V_16 , int V_168 , const struct V_220 * V_209 ,
enum V_387 type , unsigned int V_99 )
{
struct V_23 * V_141 ;
int V_43 ;
V_141 = F_118 ( V_16 , V_168 ) ;
if ( V_141 == NULL )
return - 1 ;
switch ( type ) {
case V_306 :
V_43 = F_305 ( V_16 , V_209 , V_99 ) ;
break;
case V_313 :
V_43 = F_303 ( V_16 , V_452 , & V_209 -> V_388 ) ;
break;
default:
V_43 = - V_69 ;
F_109 ( 1 ) ;
}
F_121 ( V_16 , V_141 ) ;
return V_43 ;
}
static int T_8 F_306 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_7 . V_8 ) ;
F_2 ( & V_1 -> V_7 . V_42 ) ;
V_1 -> V_7 . V_83 = 1 ;
return 0 ;
}
int F_307 ( struct V_13 * V_14 )
{
struct V_49 * V_50 , * V_453 ;
F_107 ( ! F_25 ( V_14 -> V_22 ) ) ;
F_28 ( V_14 -> V_1 , V_14 -> V_22 -> V_20 , V_14 -> V_22 ,
V_14 -> V_3 -> V_111 ) ;
F_102 (rule, nr, &ctx->chain->rules, list) {
F_22 ( & V_50 -> V_6 ) ;
V_14 -> V_22 -> V_48 -- ;
F_172 ( V_14 , V_50 ) ;
}
F_22 ( & V_14 -> V_22 -> V_6 ) ;
V_14 -> V_20 -> V_48 -- ;
F_139 ( V_14 -> V_22 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_19 * V_20 , * V_131 ;
struct V_21 * V_22 , * V_125 ;
struct V_62 * V_63 , * V_126 ;
struct V_49 * V_50 , * V_453 ;
struct V_56 * V_57 , * V_127 ;
struct V_13 V_14 = {
. V_1 = V_1 ,
. V_3 = V_3 ,
} ;
F_102 (table, nt, &afi->tables, list) {
F_10 (chain, &table->chains, list)
F_28 ( V_1 , V_20 , V_22 ,
V_3 -> V_111 ) ;
V_14 . V_20 = V_20 ;
F_10 (chain, &table->chains, list) {
V_14 . V_22 = V_22 ;
F_102 (rule, nr, &chain->rules, list) {
F_22 ( & V_50 -> V_6 ) ;
V_22 -> V_48 -- ;
F_172 ( & V_14 , V_50 ) ;
}
}
F_102 (set, ns, &table->sets, list) {
F_22 ( & V_57 -> V_6 ) ;
V_20 -> V_48 -- ;
F_208 ( V_57 ) ;
}
F_102 (obj, ne, &table->objects, list) {
F_22 ( & V_63 -> V_6 ) ;
V_20 -> V_48 -- ;
F_275 ( V_63 ) ;
}
F_102 (chain, nc, &table->chains, list) {
F_22 ( & V_22 -> V_6 ) ;
V_20 -> V_48 -- ;
F_139 ( V_22 ) ;
}
F_22 ( & V_20 -> V_6 ) ;
F_106 ( & V_14 ) ;
}
}
static int T_9 F_308 ( void )
{
int V_43 ;
V_212 = F_202 ( sizeof( struct V_211 ) * V_244 ,
V_34 ) ;
if ( V_212 == NULL ) {
V_43 = - V_40 ;
goto V_118;
}
V_43 = F_309 () ;
if ( V_43 < 0 )
goto V_119;
V_43 = F_310 ( & V_454 ) ;
if ( V_43 < 0 )
goto V_124;
F_311 ( L_7 ) ;
return F_312 ( & V_455 ) ;
V_124:
F_313 () ;
V_119:
F_23 ( V_212 ) ;
V_118:
return V_43 ;
}
static void T_10 F_314 ( void )
{
F_315 ( & V_455 ) ;
F_316 ( & V_454 ) ;
F_317 () ;
F_313 () ;
F_23 ( V_212 ) ;
}
