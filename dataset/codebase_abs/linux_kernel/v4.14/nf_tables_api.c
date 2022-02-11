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
V_20 -> V_68 = F_99 ( V_68 , V_34 ) ;
if ( V_20 -> V_68 == NULL )
goto V_120;
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
F_23 ( V_20 -> V_68 ) ;
V_120:
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
if ( V_18 -> V_105 & V_133 &&
V_20 -> V_48 > 0 )
return - V_134 ;
V_14 . V_3 = V_3 ;
V_14 . V_20 = V_20 ;
return F_101 ( & V_14 ) ;
}
static void F_106 ( struct V_13 * V_14 )
{
F_107 ( V_14 -> V_20 -> V_48 > 0 ) ;
F_23 ( V_14 -> V_20 -> V_68 ) ;
F_23 ( V_14 -> V_20 ) ;
F_100 ( V_14 -> V_3 -> V_117 ) ;
}
int F_108 ( const struct V_71 * V_135 )
{
int V_43 = 0 ;
if ( F_109 ( V_135 -> V_9 >= V_136 ) )
return - V_69 ;
F_3 ( V_5 ) ;
if ( V_74 [ V_135 -> V_9 ] [ V_135 -> type ] != NULL ) {
V_43 = - V_134 ;
goto V_128;
}
V_74 [ V_135 -> V_9 ] [ V_135 -> type ] = V_135 ;
V_128:
F_5 ( V_5 ) ;
return V_43 ;
}
void F_110 ( const struct V_71 * V_135 )
{
F_3 ( V_5 ) ;
V_74 [ V_135 -> V_9 ] [ V_135 -> type ] = NULL ;
F_5 ( V_5 ) ;
}
static struct V_21 *
F_111 ( const struct V_19 * V_20 , T_4 V_137 ,
T_3 V_67 )
{
struct V_21 * V_22 ;
F_10 (chain, &table->chains, list) {
if ( V_22 -> V_137 == V_137 &&
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
static int F_113 ( struct V_15 * V_16 , struct V_138 T_5 * V_139 )
{
struct V_138 * V_140 , V_141 ;
struct V_23 * V_142 ;
unsigned int V_27 ;
T_4 V_143 , V_144 ;
int V_145 ;
memset ( & V_141 , 0 , sizeof( V_141 ) ) ;
F_114 (cpu) {
V_140 = F_115 ( V_139 , V_145 ) ;
do {
V_27 = F_116 ( & V_140 -> V_146 ) ;
V_143 = V_140 -> V_143 ;
V_144 = V_140 -> V_144 ;
} while ( F_117 ( & V_140 -> V_146 , V_27 ) );
V_141 . V_143 += V_143 ;
V_141 . V_144 += V_144 ;
}
V_142 = F_118 ( V_16 , V_147 ) ;
if ( V_142 == NULL )
goto V_78;
if ( F_119 ( V_16 , V_148 , F_120 ( V_141 . V_143 ) ,
V_149 ) ||
F_119 ( V_16 , V_150 , F_120 ( V_141 . V_144 ) ,
V_149 ) )
goto V_78;
F_121 ( V_16 , V_142 ) ;
return 0 ;
V_78:
return - V_151 ;
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
if ( F_64 ( V_16 , V_152 , V_20 -> V_68 ) )
goto V_78;
if ( F_119 ( V_16 , V_153 , F_120 ( V_22 -> V_137 ) ,
V_154 ) )
goto V_78;
if ( F_64 ( V_16 , V_155 , V_22 -> V_68 ) )
goto V_78;
if ( F_25 ( V_22 ) ) {
const struct F_27 * V_156 = F_27 ( V_22 ) ;
const struct V_157 * V_38 = & V_156 -> V_38 [ 0 ] ;
struct V_23 * V_142 ;
V_142 = F_118 ( V_16 , V_158 ) ;
if ( V_142 == NULL )
goto V_78;
if ( F_65 ( V_16 , V_159 , F_66 ( V_38 -> V_160 ) ) )
goto V_78;
if ( F_65 ( V_16 , V_161 , F_66 ( V_38 -> V_162 ) ) )
goto V_78;
if ( V_156 -> V_163 [ 0 ] &&
F_64 ( V_16 , V_164 , V_156 -> V_163 ) )
goto V_78;
F_121 ( V_16 , V_142 ) ;
if ( F_65 ( V_16 , V_165 ,
F_66 ( V_156 -> V_166 ) ) )
goto V_78;
if ( F_64 ( V_16 , V_167 , V_156 -> type -> V_68 ) )
goto V_78;
if ( V_156 -> V_139 && F_113 ( V_16 , V_156 -> V_139 ) )
goto V_78;
}
if ( F_65 ( V_16 , V_168 , F_66 ( V_22 -> V_48 ) ) )
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
V_20 = F_53 ( V_3 , V_24 [ V_152 ] , V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
V_22 = F_112 ( V_20 , V_24 [ V_155 ] , V_67 ) ;
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
static struct V_138 T_5 * F_126 ( const struct V_23 * V_169 )
{
struct V_23 * V_170 [ V_171 + 1 ] ;
struct V_138 T_5 * V_172 ;
struct V_138 * V_139 ;
int V_43 ;
V_43 = F_127 ( V_170 , V_171 , V_169 , V_173 ,
NULL ) ;
if ( V_43 < 0 )
return F_14 ( V_43 ) ;
if ( ! V_170 [ V_150 ] || ! V_170 [ V_148 ] )
return F_14 ( - V_69 ) ;
V_172 = F_128 ( struct V_138 ) ;
if ( V_172 == NULL )
return F_14 ( - V_40 ) ;
F_129 () ;
V_139 = F_130 ( V_172 ) ;
V_139 -> V_144 = F_131 ( F_132 ( V_170 [ V_150 ] ) ) ;
V_139 -> V_143 = F_131 ( F_132 ( V_170 [ V_148 ] ) ) ;
F_133 () ;
return V_172 ;
}
static void F_134 ( struct F_27 * V_22 ,
struct V_138 T_5 * V_172 )
{
if ( V_172 == NULL )
return;
if ( V_22 -> V_139 ) {
struct V_138 T_5 * V_174 =
F_135 ( V_22 -> V_139 ) ;
F_136 ( V_22 -> V_139 , V_172 ) ;
F_137 () ;
F_138 ( V_174 ) ;
} else
F_136 ( V_22 -> V_139 , V_172 ) ;
}
static void F_139 ( struct V_21 * V_22 )
{
F_107 ( V_22 -> V_48 > 0 ) ;
if ( F_25 ( V_22 ) ) {
struct F_27 * V_156 = F_27 ( V_22 ) ;
F_100 ( V_156 -> type -> V_117 ) ;
F_138 ( V_156 -> V_139 ) ;
if ( V_156 -> V_139 )
F_140 ( & V_175 ) ;
if ( V_156 -> V_38 [ 0 ] . V_176 != NULL )
F_141 ( V_156 -> V_38 [ 0 ] . V_176 ) ;
F_23 ( V_22 -> V_68 ) ;
F_23 ( V_156 ) ;
} else {
F_23 ( V_22 -> V_68 ) ;
F_23 ( V_22 ) ;
}
}
static int F_142 ( struct V_1 * V_1 ,
const struct V_23 * const V_24 [] ,
struct V_2 * V_3 ,
struct V_177 * V_178 , bool V_179 )
{
struct V_23 * V_180 [ V_181 + 1 ] ;
const struct V_71 * type ;
struct V_182 * V_176 ;
int V_43 ;
V_43 = F_127 ( V_180 , V_181 , V_24 [ V_158 ] ,
V_183 , NULL ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_180 [ V_159 ] == NULL ||
V_180 [ V_161 ] == NULL )
return - V_69 ;
V_178 -> V_184 = F_41 ( F_42 ( V_180 [ V_159 ] ) ) ;
if ( V_178 -> V_184 >= V_3 -> V_185 )
return - V_69 ;
V_178 -> V_162 = F_41 ( F_42 ( V_180 [ V_161 ] ) ) ;
type = V_74 [ V_3 -> V_9 ] [ V_186 ] ;
if ( V_24 [ V_167 ] ) {
type = F_56 ( V_3 , V_24 [ V_167 ] ,
V_179 ) ;
if ( F_86 ( type ) )
return F_87 ( type ) ;
}
if ( ! ( type -> V_187 & ( 1 << V_178 -> V_184 ) ) )
return - V_116 ;
if ( ! F_98 ( type -> V_117 ) )
return - V_51 ;
V_178 -> type = type ;
V_178 -> V_176 = NULL ;
if ( V_3 -> V_36 & V_188 ) {
char V_189 [ V_190 ] ;
if ( ! V_180 [ V_164 ] ) {
F_100 ( type -> V_117 ) ;
return - V_116 ;
}
F_143 ( V_189 , V_180 [ V_164 ] , V_190 ) ;
V_176 = F_144 ( V_1 , V_189 ) ;
if ( ! V_176 ) {
F_100 ( type -> V_117 ) ;
return - V_51 ;
}
V_178 -> V_176 = V_176 ;
} else if ( V_180 [ V_164 ] ) {
F_100 ( type -> V_117 ) ;
return - V_116 ;
}
return 0 ;
}
static void F_145 ( struct V_177 * V_178 )
{
F_100 ( V_178 -> type -> V_117 ) ;
if ( V_178 -> V_176 != NULL )
F_141 ( V_178 -> V_176 ) ;
}
static int F_146 ( struct V_13 * V_14 , T_3 V_9 , T_3 V_67 ,
T_3 V_166 , bool V_179 )
{
const struct V_23 * const * V_24 = V_14 -> V_24 ;
struct V_19 * V_20 = V_14 -> V_20 ;
struct V_2 * V_3 = V_14 -> V_3 ;
struct F_27 * V_156 ;
struct V_138 T_5 * V_139 ;
struct V_1 * V_1 = V_14 -> V_1 ;
struct V_21 * V_22 ;
unsigned int V_72 ;
int V_43 ;
if ( V_20 -> V_48 == V_191 )
return - V_192 ;
if ( V_24 [ V_158 ] ) {
struct V_177 V_178 ;
struct V_157 * V_38 ;
T_6 * V_193 ;
V_43 = F_142 ( V_1 , V_24 , V_3 , & V_178 , V_179 ) ;
if ( V_43 < 0 )
return V_43 ;
V_156 = F_19 ( sizeof( * V_156 ) , V_34 ) ;
if ( V_156 == NULL ) {
F_145 ( & V_178 ) ;
return - V_40 ;
}
if ( V_178 . V_176 != NULL )
strncpy ( V_156 -> V_163 , V_178 . V_176 -> V_68 , V_190 ) ;
if ( V_24 [ V_147 ] ) {
V_139 = F_126 ( V_24 [ V_147 ] ) ;
if ( F_86 ( V_139 ) ) {
F_145 ( & V_178 ) ;
F_23 ( V_156 ) ;
return F_87 ( V_139 ) ;
}
V_156 -> V_139 = V_139 ;
F_147 ( & V_175 ) ;
}
V_193 = V_178 . type -> V_194 [ V_178 . V_184 ] ;
V_156 -> type = V_178 . type ;
V_22 = & V_156 -> V_22 ;
for ( V_72 = 0 ; V_72 < V_3 -> V_111 ; V_72 ++ ) {
V_38 = & V_156 -> V_38 [ V_72 ] ;
V_38 -> V_195 = V_9 ;
V_38 -> V_160 = V_178 . V_184 ;
V_38 -> V_162 = V_178 . V_162 ;
V_38 -> V_196 = V_22 ;
V_38 -> V_178 = V_3 -> V_194 [ V_38 -> V_160 ] ;
V_38 -> V_176 = V_178 . V_176 ;
if ( V_193 )
V_38 -> V_178 = V_193 ;
if ( V_3 -> V_197 )
V_3 -> V_197 ( V_38 , V_72 ) ;
}
V_22 -> V_36 |= V_198 ;
V_156 -> V_166 = V_166 ;
} else {
V_22 = F_19 ( sizeof( * V_22 ) , V_34 ) ;
if ( V_22 == NULL )
return - V_40 ;
}
F_2 ( & V_22 -> V_199 ) ;
V_22 -> V_137 = F_54 ( V_20 ) ;
V_22 -> V_20 = V_20 ;
V_22 -> V_68 = F_99 ( V_24 [ V_155 ] , V_34 ) ;
if ( ! V_22 -> V_68 ) {
V_43 = - V_40 ;
goto V_118;
}
V_43 = F_24 ( V_1 , V_20 , V_22 , V_3 -> V_111 ) ;
if ( V_43 < 0 )
goto V_118;
V_14 -> V_22 = V_22 ;
V_43 = F_35 ( V_14 , V_46 ) ;
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
static int F_148 ( struct V_13 * V_14 , T_3 V_67 , T_3 V_166 ,
bool V_179 )
{
const struct V_23 * const * V_24 = V_14 -> V_24 ;
struct V_19 * V_20 = V_14 -> V_20 ;
struct V_21 * V_22 = V_14 -> V_22 ;
struct V_2 * V_3 = V_14 -> V_3 ;
struct F_27 * V_156 ;
struct V_138 * V_139 = NULL ;
struct V_177 V_178 ;
const struct V_23 * V_68 ;
struct V_157 * V_38 ;
struct V_29 * V_33 ;
int V_43 , V_72 ;
if ( V_24 [ V_158 ] ) {
if ( ! F_25 ( V_22 ) )
return - V_134 ;
V_43 = F_142 ( V_14 -> V_1 , V_24 , V_14 -> V_3 , & V_178 ,
V_179 ) ;
if ( V_43 < 0 )
return V_43 ;
V_156 = F_27 ( V_22 ) ;
if ( V_156 -> type != V_178 . type ) {
F_145 ( & V_178 ) ;
return - V_134 ;
}
for ( V_72 = 0 ; V_72 < V_3 -> V_111 ; V_72 ++ ) {
V_38 = & V_156 -> V_38 [ V_72 ] ;
if ( V_38 -> V_160 != V_178 . V_184 ||
V_38 -> V_162 != V_178 . V_162 ||
V_38 -> V_176 != V_178 . V_176 ) {
F_145 ( & V_178 ) ;
return - V_134 ;
}
}
F_145 ( & V_178 ) ;
}
if ( V_24 [ V_153 ] &&
V_24 [ V_155 ] ) {
struct V_21 * V_200 ;
V_200 = F_112 ( V_20 , V_24 [ V_155 ] ,
V_67 ) ;
if ( ! F_86 ( V_200 ) )
return - V_114 ;
}
if ( V_24 [ V_147 ] ) {
if ( ! F_25 ( V_22 ) )
return - V_116 ;
V_139 = F_126 ( V_24 [ V_147 ] ) ;
if ( F_86 ( V_139 ) )
return F_87 ( V_139 ) ;
}
V_33 = F_20 ( V_14 , V_46 ,
sizeof( struct V_45 ) ) ;
if ( V_33 == NULL ) {
F_138 ( V_139 ) ;
return - V_40 ;
}
F_149 ( V_33 ) = V_139 ;
F_150 ( V_33 ) = true ;
if ( V_24 [ V_165 ] )
F_151 ( V_33 ) = V_166 ;
else
F_151 ( V_33 ) = - 1 ;
V_68 = V_24 [ V_155 ] ;
if ( V_24 [ V_153 ] && V_68 ) {
F_152 ( V_33 ) =
F_99 ( V_68 , V_34 ) ;
if ( ! F_152 ( V_33 ) ) {
F_23 ( V_33 ) ;
F_138 ( V_139 ) ;
return - V_40 ;
}
}
F_32 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_42 ) ;
return 0 ;
}
static int F_153 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
struct V_102 * V_103 )
{
const struct V_76 * V_77 = F_62 ( V_18 ) ;
const struct V_23 * V_201 ( V_68 ) ;
T_3 V_67 = F_97 ( V_1 ) ;
int V_9 = V_77 -> V_79 ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
T_3 V_166 = V_202 ;
struct V_13 V_14 ;
T_4 V_137 = 0 ;
bool V_179 ;
V_179 = V_18 -> V_105 & V_203 ? true : false ;
V_3 = F_11 ( V_1 , V_9 , true ) ;
if ( F_86 ( V_3 ) )
return F_87 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_152 ] , V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
V_22 = NULL ;
V_68 = V_24 [ V_155 ] ;
if ( V_24 [ V_153 ] ) {
V_137 = F_131 ( F_132 ( V_24 [ V_153 ] ) ) ;
V_22 = F_111 ( V_20 , V_137 , V_67 ) ;
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
if ( V_24 [ V_165 ] ) {
if ( V_22 != NULL &&
! F_25 ( V_22 ) )
return - V_116 ;
if ( V_22 == NULL &&
V_24 [ V_158 ] == NULL )
return - V_116 ;
V_166 = F_41 ( F_42 ( V_24 [ V_165 ] ) ) ;
switch ( V_166 ) {
case V_204 :
case V_202 :
break;
default:
return - V_69 ;
}
}
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
if ( V_22 != NULL ) {
if ( V_18 -> V_105 & V_113 )
return - V_114 ;
if ( V_18 -> V_105 & V_115 )
return - V_116 ;
return F_148 ( & V_14 , V_67 , V_166 , V_179 ) ;
}
return F_146 ( & V_14 , V_9 , V_67 , V_166 , V_179 ) ;
}
static int F_154 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
struct V_102 * V_103 )
{
const struct V_76 * V_77 = F_62 ( V_18 ) ;
T_3 V_67 = F_97 ( V_1 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_49 * V_50 ;
int V_9 = V_77 -> V_79 ;
struct V_13 V_14 ;
T_1 V_48 ;
int V_43 ;
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_86 ( V_3 ) )
return F_87 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_152 ] , V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
V_22 = F_112 ( V_20 , V_24 [ V_155 ] , V_67 ) ;
if ( F_86 ( V_22 ) )
return F_87 ( V_22 ) ;
if ( V_18 -> V_105 & V_133 &&
V_22 -> V_48 > 0 )
return - V_134 ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_48 = V_22 -> V_48 ;
F_10 (rule, &chain->rules, list) {
if ( ! F_38 ( V_1 , V_50 ) )
continue;
V_48 -- ;
V_43 = F_43 ( & V_14 , V_50 ) ;
if ( V_43 < 0 )
return V_43 ;
}
if ( V_48 > 0 )
return - V_134 ;
return F_36 ( & V_14 ) ;
}
int F_155 ( struct V_205 * type )
{
F_3 ( V_5 ) ;
if ( type -> V_9 == V_95 )
F_4 ( & type -> V_6 , & V_206 ) ;
else
F_156 ( & type -> V_6 , & V_206 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_157 ( struct V_205 * type )
{
F_3 ( V_5 ) ;
F_8 ( & type -> V_6 ) ;
F_5 ( V_5 ) ;
}
static const struct V_205 * F_158 ( T_3 V_9 ,
struct V_23 * V_24 )
{
const struct V_205 * type ;
F_10 (type, &nf_tables_expressions, list) {
if ( ! F_51 ( V_24 , type -> V_68 ) &&
( ! type -> V_9 || type -> V_9 == V_9 ) )
return type ;
}
return NULL ;
}
static const struct V_205 * F_159 ( T_3 V_9 ,
struct V_23 * V_24 )
{
const struct V_205 * type ;
if ( V_24 == NULL )
return F_14 ( - V_69 ) ;
type = F_158 ( V_9 , V_24 ) ;
if ( type != NULL && F_98 ( type -> V_117 ) )
return type ;
#ifdef F_12
if ( type == NULL ) {
F_5 ( V_5 ) ;
F_13 ( L_3 , V_9 ,
F_57 ( V_24 ) , ( char * ) F_58 ( V_24 ) ) ;
F_3 ( V_5 ) ;
if ( F_158 ( V_9 , V_24 ) )
return F_14 ( - V_11 ) ;
F_5 ( V_5 ) ;
F_13 ( L_4 ,
F_57 ( V_24 ) , ( char * ) F_58 ( V_24 ) ) ;
F_3 ( V_5 ) ;
if ( F_158 ( V_9 , V_24 ) )
return F_14 ( - V_11 ) ;
}
#endif
return F_14 ( - V_51 ) ;
}
static int F_160 ( struct V_15 * V_16 ,
const struct V_207 * V_208 )
{
if ( F_64 ( V_16 , V_209 , V_208 -> V_38 -> type -> V_68 ) )
goto V_78;
if ( V_208 -> V_38 -> V_109 ) {
struct V_23 * V_210 = F_118 ( V_16 , V_211 ) ;
if ( V_210 == NULL )
goto V_78;
if ( V_208 -> V_38 -> V_109 ( V_16 , V_208 ) < 0 )
goto V_78;
F_121 ( V_16 , V_210 ) ;
}
return V_16 -> V_99 ;
V_78:
return - 1 ;
}
int F_161 ( struct V_15 * V_16 , unsigned int V_169 ,
const struct V_207 * V_208 )
{
struct V_23 * V_142 ;
V_142 = F_118 ( V_16 , V_169 ) ;
if ( ! V_142 )
goto V_78;
if ( F_160 ( V_16 , V_208 ) < 0 )
goto V_78;
F_121 ( V_16 , V_142 ) ;
return 0 ;
V_78:
return - 1 ;
}
static int F_162 ( const struct V_13 * V_14 ,
const struct V_23 * V_24 ,
struct V_212 * V_213 )
{
const struct V_205 * type ;
const struct V_214 * V_38 ;
struct V_23 * V_170 [ V_215 + 1 ] ;
int V_43 ;
V_43 = F_127 ( V_170 , V_215 , V_24 , V_216 , NULL ) ;
if ( V_43 < 0 )
return V_43 ;
type = F_159 ( V_14 -> V_3 -> V_9 , V_170 [ V_209 ] ) ;
if ( F_86 ( type ) )
return F_87 ( type ) ;
if ( V_170 [ V_211 ] ) {
V_43 = F_127 ( V_213 -> V_170 , type -> V_217 ,
V_170 [ V_211 ] , type -> V_166 , NULL ) ;
if ( V_43 < 0 )
goto V_118;
} else
memset ( V_213 -> V_170 , 0 , sizeof( V_213 -> V_170 [ 0 ] ) * ( type -> V_217 + 1 ) ) ;
if ( type -> V_218 != NULL ) {
V_38 = type -> V_218 ( V_14 ,
( const struct V_23 * const * ) V_213 -> V_170 ) ;
if ( F_86 ( V_38 ) ) {
V_43 = F_87 ( V_38 ) ;
goto V_118;
}
} else
V_38 = type -> V_38 ;
V_213 -> V_38 = V_38 ;
return 0 ;
V_118:
F_100 ( type -> V_117 ) ;
return V_43 ;
}
static int F_163 ( const struct V_13 * V_14 ,
const struct V_212 * V_213 ,
struct V_207 * V_208 )
{
const struct V_214 * V_38 = V_213 -> V_38 ;
int V_43 ;
V_208 -> V_38 = V_38 ;
if ( V_38 -> V_219 ) {
V_43 = V_38 -> V_219 ( V_14 , V_208 , ( const struct V_23 * * ) V_213 -> V_170 ) ;
if ( V_43 < 0 )
goto V_118;
}
if ( V_38 -> V_220 ) {
const struct V_221 * V_210 = NULL ;
V_43 = V_38 -> V_220 ( V_14 , V_208 , & V_210 ) ;
if ( V_43 < 0 )
goto V_119;
}
return 0 ;
V_119:
if ( V_38 -> V_222 )
V_38 -> V_222 ( V_14 , V_208 ) ;
V_118:
V_208 -> V_38 = NULL ;
return V_43 ;
}
static void F_164 ( const struct V_13 * V_14 ,
struct V_207 * V_208 )
{
if ( V_208 -> V_38 -> V_222 )
V_208 -> V_38 -> V_222 ( V_14 , V_208 ) ;
F_100 ( V_208 -> V_38 -> type -> V_117 ) ;
}
struct V_207 * F_165 ( const struct V_13 * V_14 ,
const struct V_23 * V_24 )
{
struct V_212 V_213 ;
struct V_207 * V_208 ;
int V_43 ;
V_43 = F_162 ( V_14 , V_24 , & V_213 ) ;
if ( V_43 < 0 )
goto V_118;
V_43 = - V_40 ;
V_208 = F_19 ( V_213 . V_38 -> V_31 , V_34 ) ;
if ( V_208 == NULL )
goto V_119;
V_43 = F_163 ( V_14 , & V_213 , V_208 ) ;
if ( V_43 < 0 )
goto V_120;
return V_208 ;
V_120:
F_23 ( V_208 ) ;
V_119:
F_100 ( V_213 . V_38 -> type -> V_117 ) ;
V_118:
return F_14 ( V_43 ) ;
}
void F_166 ( const struct V_13 * V_14 , struct V_207 * V_208 )
{
F_164 ( V_14 , V_208 ) ;
F_23 ( V_208 ) ;
}
static struct V_49 * F_167 ( const struct V_21 * V_22 ,
T_4 V_137 )
{
struct V_49 * V_50 ;
F_10 (rule, &chain->rules, list) {
if ( V_137 == V_50 -> V_137 )
return V_50 ;
}
return F_14 ( - V_51 ) ;
}
static struct V_49 * F_168 ( const struct V_21 * V_22 ,
const struct V_23 * V_24 )
{
if ( V_24 == NULL )
return F_14 ( - V_69 ) ;
return F_167 ( V_22 , F_131 ( F_132 ( V_24 ) ) ) ;
}
static int F_169 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_25 , T_1 V_27 , int V_75 ,
T_1 V_36 , int V_9 ,
const struct V_19 * V_20 ,
const struct V_21 * V_22 ,
const struct V_49 * V_50 )
{
struct V_17 * V_18 ;
struct V_76 * V_77 ;
const struct V_207 * V_208 , * V_223 ;
struct V_23 * V_6 ;
const struct V_49 * V_224 ;
T_7 type = F_60 ( V_5 , V_75 ) ;
V_18 = F_61 ( V_16 , V_25 , V_27 , type , sizeof( struct V_76 ) , V_36 ) ;
if ( V_18 == NULL )
goto V_78;
V_77 = F_62 ( V_18 ) ;
V_77 -> V_79 = V_9 ;
V_77 -> V_80 = V_81 ;
V_77 -> V_82 = F_63 ( V_1 -> V_7 . V_83 & 0xffff ) ;
if ( F_64 ( V_16 , V_225 , V_20 -> V_68 ) )
goto V_78;
if ( F_64 ( V_16 , V_226 , V_22 -> V_68 ) )
goto V_78;
if ( F_119 ( V_16 , V_227 , F_120 ( V_50 -> V_137 ) ,
V_228 ) )
goto V_78;
if ( ( V_75 != V_55 ) && ( V_50 -> V_6 . V_229 != & V_22 -> V_199 ) ) {
V_224 = F_170 ( V_50 , V_6 ) ;
if ( F_119 ( V_16 , V_230 ,
F_120 ( V_224 -> V_137 ) ,
V_228 ) )
goto V_78;
}
V_6 = F_118 ( V_16 , V_231 ) ;
if ( V_6 == NULL )
goto V_78;
F_171 (expr, next, rule) {
if ( F_161 ( V_16 , V_232 , V_208 ) < 0 )
goto V_78;
}
F_121 ( V_16 , V_6 ) ;
if ( V_50 -> V_233 ) {
struct V_234 * V_233 = V_234 ( V_50 ) ;
if ( F_172 ( V_16 , V_235 , V_233 -> V_99 + 1 ,
V_233 -> V_210 ) < 0 )
goto V_78;
}
F_67 ( V_16 , V_18 ) ;
return 0 ;
V_78:
F_68 ( V_16 , V_18 ) ;
return - 1 ;
}
static void F_173 ( const struct V_13 * V_14 ,
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
V_43 = F_169 ( V_16 , V_14 -> V_1 , V_14 -> V_25 , V_14 -> V_27 ,
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
static int F_174 ( struct V_15 * V_16 ,
struct V_90 * V_91 )
{
const struct V_76 * V_77 = F_62 ( V_91 -> V_18 ) ;
const struct V_236 * V_14 = V_91 -> V_210 ;
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
if ( V_14 && V_14 -> V_20 &&
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
if ( F_169 ( V_16 , V_1 , F_16 ( V_91 -> V_16 ) . V_25 ,
V_91 -> V_18 -> V_28 ,
V_53 ,
V_97 | V_237 ,
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
static int F_175 ( struct V_90 * V_91 )
{
struct V_236 * V_14 = V_91 -> V_210 ;
if ( V_14 ) {
F_23 ( V_14 -> V_20 ) ;
F_23 ( V_14 -> V_22 ) ;
F_23 ( V_14 ) ;
}
return 0 ;
}
static int F_176 ( struct V_1 * V_1 , struct V_100 * V_101 ,
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
. V_109 = F_174 ,
. V_98 = F_175 ,
} ;
if ( V_24 [ V_225 ] || V_24 [ V_226 ] ) {
struct V_236 * V_14 ;
V_14 = F_19 ( sizeof( * V_14 ) , V_34 ) ;
if ( ! V_14 )
return - V_40 ;
if ( V_24 [ V_225 ] ) {
V_14 -> V_20 = F_99 ( V_24 [ V_225 ] ,
V_34 ) ;
if ( ! V_14 -> V_20 ) {
F_23 ( V_14 ) ;
return - V_40 ;
}
}
if ( V_24 [ V_226 ] ) {
V_14 -> V_22 = F_99 ( V_24 [ V_226 ] ,
V_34 ) ;
if ( ! V_14 -> V_22 ) {
F_23 ( V_14 -> V_20 ) ;
F_23 ( V_14 ) ;
return - V_40 ;
}
}
V_108 . V_210 = V_14 ;
}
return F_85 ( V_101 , V_16 , V_18 , & V_108 ) ;
}
V_3 = F_11 ( V_1 , V_9 , false ) ;
if ( F_86 ( V_3 ) )
return F_87 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_225 ] , V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
V_22 = F_112 ( V_20 , V_24 [ V_226 ] , V_67 ) ;
if ( F_86 ( V_22 ) )
return F_87 ( V_22 ) ;
V_50 = F_168 ( V_22 , V_24 [ V_227 ] ) ;
if ( F_86 ( V_50 ) )
return F_87 ( V_50 ) ;
V_104 = F_88 ( V_88 , V_34 ) ;
if ( ! V_104 )
return - V_40 ;
V_43 = F_169 ( V_104 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 , V_53 , 0 ,
V_9 , V_20 , V_22 , V_50 ) ;
if ( V_43 < 0 )
goto V_43;
return F_89 ( V_101 , V_104 , F_16 ( V_16 ) . V_25 ) ;
V_43:
F_72 ( V_104 ) ;
return V_43 ;
}
static void F_177 ( const struct V_13 * V_14 ,
struct V_49 * V_50 )
{
struct V_207 * V_208 ;
V_208 = F_178 ( V_50 ) ;
while ( V_208 != F_179 ( V_50 ) && V_208 -> V_38 ) {
F_164 ( V_14 , V_208 ) ;
V_208 = F_180 ( V_208 ) ;
}
F_23 ( V_50 ) ;
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
struct V_21 * V_22 ;
struct V_49 * V_50 , * V_238 = NULL ;
struct V_234 * V_233 ;
struct V_29 * V_33 = NULL ;
struct V_207 * V_208 ;
struct V_13 V_14 ;
struct V_23 * V_239 ;
unsigned int V_31 , V_72 , V_240 , V_241 = 0 , V_242 = 0 ;
int V_43 , V_243 ;
bool V_179 ;
T_4 V_137 , V_244 ;
V_179 = V_18 -> V_105 & V_203 ? true : false ;
V_3 = F_11 ( V_1 , V_77 -> V_79 , V_179 ) ;
if ( F_86 ( V_3 ) )
return F_87 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_225 ] , V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
V_22 = F_112 ( V_20 , V_24 [ V_226 ] , V_67 ) ;
if ( F_86 ( V_22 ) )
return F_87 ( V_22 ) ;
if ( V_24 [ V_227 ] ) {
V_137 = F_131 ( F_132 ( V_24 [ V_227 ] ) ) ;
V_50 = F_167 ( V_22 , V_137 ) ;
if ( F_86 ( V_50 ) )
return F_87 ( V_50 ) ;
if ( V_18 -> V_105 & V_113 )
return - V_114 ;
if ( V_18 -> V_105 & V_115 )
V_238 = V_50 ;
else
return - V_116 ;
} else {
if ( ! V_179 || V_18 -> V_105 & V_115 )
return - V_69 ;
V_137 = F_54 ( V_20 ) ;
if ( V_22 -> V_48 == V_191 )
return - V_192 ;
}
if ( V_24 [ V_230 ] ) {
if ( ! ( V_18 -> V_105 & V_203 ) )
return - V_116 ;
V_244 = F_131 ( F_132 ( V_24 [ V_230 ] ) ) ;
V_238 = F_167 ( V_22 , V_244 ) ;
if ( F_86 ( V_238 ) )
return F_87 ( V_238 ) ;
}
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_240 = 0 ;
V_31 = 0 ;
if ( V_24 [ V_231 ] ) {
F_182 (tmp, nla[NFTA_RULE_EXPRESSIONS], rem) {
V_43 = - V_69 ;
if ( F_183 ( V_239 ) != V_232 )
goto V_118;
if ( V_240 == V_245 )
goto V_118;
V_43 = F_162 ( & V_14 , V_239 , & V_213 [ V_240 ] ) ;
if ( V_43 < 0 )
goto V_118;
V_31 += V_213 [ V_240 ] . V_38 -> V_31 ;
V_240 ++ ;
}
}
V_43 = - V_246 ;
if ( V_31 >= 1 << 12 )
goto V_118;
if ( V_24 [ V_235 ] ) {
V_241 = F_57 ( V_24 [ V_235 ] ) ;
if ( V_241 > 0 )
V_242 = sizeof( struct V_234 ) + V_241 ;
}
V_43 = - V_40 ;
V_50 = F_19 ( sizeof( * V_50 ) + V_31 + V_242 , V_34 ) ;
if ( V_50 == NULL )
goto V_118;
F_31 ( V_1 , V_50 ) ;
V_50 -> V_137 = V_137 ;
V_50 -> V_247 = V_31 ;
V_50 -> V_233 = V_241 ? 1 : 0 ;
if ( V_241 ) {
V_233 = V_234 ( V_50 ) ;
V_233 -> V_99 = V_241 - 1 ;
F_184 ( V_233 -> V_210 , V_24 [ V_235 ] , V_241 ) ;
}
V_208 = F_178 ( V_50 ) ;
for ( V_72 = 0 ; V_72 < V_240 ; V_72 ++ ) {
V_43 = F_163 ( & V_14 , & V_213 [ V_72 ] , V_208 ) ;
if ( V_43 < 0 )
goto V_119;
V_213 [ V_72 ] . V_38 = NULL ;
V_208 = F_180 ( V_208 ) ;
}
if ( V_18 -> V_105 & V_115 ) {
if ( F_38 ( V_1 , V_238 ) ) {
V_33 = F_39 ( & V_14 , V_55 ,
V_238 ) ;
if ( V_33 == NULL ) {
V_43 = - V_40 ;
goto V_119;
}
F_34 ( V_1 , V_238 ) ;
V_22 -> V_48 -- ;
F_4 ( & V_50 -> V_6 , & V_238 -> V_6 ) ;
} else {
V_43 = - V_51 ;
goto V_119;
}
} else if ( V_18 -> V_105 & V_237 )
if ( V_238 )
F_156 ( & V_50 -> V_6 , & V_238 -> V_6 ) ;
else
F_4 ( & V_50 -> V_6 , & V_22 -> V_199 ) ;
else {
if ( V_238 )
F_4 ( & V_50 -> V_6 , & V_238 -> V_6 ) ;
else
F_156 ( & V_50 -> V_6 , & V_22 -> V_199 ) ;
}
if ( F_39 ( & V_14 , V_53 , V_50 ) == NULL ) {
V_43 = - V_40 ;
goto V_120;
}
V_22 -> V_48 ++ ;
return 0 ;
V_120:
F_8 ( & V_50 -> V_6 ) ;
V_119:
F_177 ( & V_14 , V_50 ) ;
V_118:
for ( V_72 = 0 ; V_72 < V_240 ; V_72 ++ ) {
if ( V_213 [ V_72 ] . V_38 != NULL )
F_100 ( V_213 [ V_72 ] . V_38 -> type -> V_117 ) ;
}
return V_43 ;
}
static struct V_49 * F_185 ( const struct V_1 * V_1 ,
const struct V_23 * V_24 )
{
T_1 V_248 = F_41 ( F_42 ( V_24 ) ) ;
struct V_29 * V_33 ;
F_10 (trans, &net->nft.commit_list, list) {
struct V_49 * V_50 = V_52 ( V_33 ) ;
if ( V_33 -> V_30 == V_53 &&
V_248 == F_40 ( V_33 ) )
return V_50 ;
}
return F_14 ( - V_51 ) ;
}
static int F_186 ( struct V_1 * V_1 , struct V_100 * V_101 ,
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
V_20 = F_53 ( V_3 , V_24 [ V_225 ] , V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
if ( V_24 [ V_226 ] ) {
V_22 = F_112 ( V_20 , V_24 [ V_226 ] ,
V_67 ) ;
if ( F_86 ( V_22 ) )
return F_87 ( V_22 ) ;
}
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
if ( V_22 ) {
if ( V_24 [ V_227 ] ) {
V_50 = F_168 ( V_22 ,
V_24 [ V_227 ] ) ;
if ( F_86 ( V_50 ) )
return F_87 ( V_50 ) ;
V_43 = F_43 ( & V_14 , V_50 ) ;
} else if ( V_24 [ V_54 ] ) {
V_50 = F_185 ( V_1 , V_24 [ V_54 ] ) ;
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
int F_187 ( struct V_249 * type )
{
F_3 ( V_5 ) ;
F_4 ( & type -> V_6 , & V_250 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_188 ( struct V_249 * type )
{
F_3 ( V_5 ) ;
F_8 ( & type -> V_6 ) ;
F_5 ( V_5 ) ;
}
static bool F_189 ( const struct V_251 * V_38 , T_1 V_36 )
{
return ( V_36 & V_38 -> V_252 ) == ( V_36 & V_253 ) ;
}
static const struct V_251 *
F_190 ( const struct V_13 * V_14 ,
const struct V_23 * const V_24 [] ,
const struct V_254 * V_255 ,
enum V_256 V_166 )
{
const struct V_251 * V_38 , * V_257 ;
struct V_258 V_259 , V_260 ;
const struct V_249 * type ;
T_1 V_36 = 0 ;
#ifdef F_12
if ( F_103 ( & V_250 ) ) {
F_5 ( V_5 ) ;
F_13 ( L_5 ) ;
F_3 ( V_5 ) ;
if ( ! F_103 ( & V_250 ) )
return F_14 ( - V_11 ) ;
}
#endif
if ( V_24 [ V_261 ] != NULL )
V_36 = F_41 ( F_42 ( V_24 [ V_261 ] ) ) ;
V_257 = NULL ;
V_260 . V_31 = ~ 0 ;
V_260 . V_262 = ~ 0 ;
V_260 . V_263 = ~ 0 ;
F_10 (type, &nf_tables_set_types, list) {
if ( ! type -> V_218 )
V_38 = type -> V_38 ;
else
V_38 = type -> V_218 ( V_14 , V_255 , V_36 ) ;
if ( ! V_38 )
continue;
if ( ! F_189 ( V_38 , V_36 ) )
continue;
if ( ! V_38 -> V_264 ( V_255 , V_36 , & V_259 ) )
continue;
switch ( V_166 ) {
case V_265 :
if ( V_259 . V_262 < V_260 . V_262 )
break;
if ( V_259 . V_262 == V_260 . V_262 ) {
if ( ! V_255 -> V_31 ) {
if ( V_259 . V_263 < V_260 . V_263 )
break;
} else if ( V_259 . V_31 < V_260 . V_31 ) {
break;
}
}
continue;
case V_266 :
if ( ! V_255 -> V_31 ) {
if ( V_259 . V_263 < V_260 . V_263 )
break;
if ( V_259 . V_263 == V_260 . V_263 &&
V_259 . V_262 < V_260 . V_262 )
break;
} else if ( V_259 . V_31 < V_260 . V_31 ) {
break;
}
continue;
default:
break;
}
if ( ! F_98 ( type -> V_117 ) )
continue;
if ( V_257 != NULL )
F_100 ( V_257 -> type -> V_117 ) ;
V_257 = V_38 ;
V_260 = V_259 ;
}
if ( V_257 != NULL )
return V_257 ;
return F_14 ( - V_116 ) ;
}
static int F_191 ( struct V_13 * V_14 , struct V_1 * V_1 ,
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
if ( V_24 [ V_267 ] != NULL ) {
if ( V_3 == NULL )
return - V_12 ;
V_20 = F_53 ( V_3 , V_24 [ V_267 ] ,
V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
}
F_15 ( V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return 0 ;
}
static struct V_56 * F_192 ( const struct V_19 * V_20 ,
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
static struct V_56 * F_193 ( const struct V_1 * V_1 ,
const struct V_23 * V_24 ,
T_3 V_67 )
{
struct V_29 * V_33 ;
T_1 V_248 = F_41 ( F_42 ( V_24 ) ) ;
F_10 (trans, &net->nft.commit_list, list) {
struct V_56 * V_57 = V_58 ( V_33 ) ;
if ( V_33 -> V_30 == V_59 &&
V_248 == F_46 ( V_33 ) &&
F_52 ( V_57 , V_67 ) )
return V_57 ;
}
return F_14 ( - V_51 ) ;
}
struct V_56 * F_194 ( const struct V_1 * V_1 ,
const struct V_19 * V_20 ,
const struct V_23 * V_268 ,
const struct V_23 * V_269 ,
T_3 V_67 )
{
struct V_56 * V_57 ;
V_57 = F_192 ( V_20 , V_268 , V_67 ) ;
if ( F_86 ( V_57 ) ) {
if ( ! V_269 )
return V_57 ;
V_57 = F_193 ( V_1 , V_269 , V_67 ) ;
}
return V_57 ;
}
static int F_195 ( struct V_13 * V_14 , struct V_56 * V_57 ,
const char * V_68 )
{
const struct V_56 * V_72 ;
const char * V_270 ;
unsigned long * V_271 ;
unsigned int V_240 = 0 , V_272 = 0 ;
V_270 = strchr ( V_68 , '%' ) ;
if ( V_270 != NULL ) {
if ( V_270 [ 1 ] != 'd' || strchr ( V_270 + 2 , '%' ) )
return - V_69 ;
V_271 = ( unsigned long * ) F_196 ( V_34 ) ;
if ( V_271 == NULL )
return - V_40 ;
V_96:
F_10 (i, &ctx->table->sets, list) {
int V_239 ;
if ( ! F_38 ( V_14 -> V_1 , V_57 ) )
continue;
if ( ! sscanf ( V_72 -> V_68 , V_68 , & V_239 ) )
continue;
if ( V_239 < V_272 || V_239 >= V_272 + V_273 * V_274 )
continue;
F_197 ( V_239 - V_272 , V_271 ) ;
}
V_240 = F_198 ( V_271 , V_273 * V_274 ) ;
if ( V_240 >= V_273 * V_274 ) {
V_272 += V_273 * V_274 ;
memset ( V_271 , 0 , V_274 ) ;
goto V_96;
}
F_199 ( ( unsigned long ) V_271 ) ;
}
V_57 -> V_68 = F_200 ( V_34 , V_68 , V_272 + V_240 ) ;
if ( ! V_57 -> V_68 )
return - V_40 ;
F_10 (i, &ctx->table->sets, list) {
if ( ! F_38 ( V_14 -> V_1 , V_72 ) )
continue;
if ( ! strcmp ( V_57 -> V_68 , V_72 -> V_68 ) ) {
F_23 ( V_57 -> V_68 ) ;
return - V_275 ;
}
}
return 0 ;
}
static int F_201 ( struct V_15 * V_16 , const struct V_13 * V_14 ,
const struct V_56 * V_57 , T_7 V_75 , T_7 V_36 )
{
struct V_76 * V_77 ;
struct V_17 * V_18 ;
struct V_23 * V_255 ;
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
if ( F_64 ( V_16 , V_267 , V_14 -> V_20 -> V_68 ) )
goto V_78;
if ( F_64 ( V_16 , V_276 , V_57 -> V_68 ) )
goto V_78;
if ( V_57 -> V_36 != 0 )
if ( F_65 ( V_16 , V_261 , F_66 ( V_57 -> V_36 ) ) )
goto V_78;
if ( F_65 ( V_16 , V_277 , F_66 ( V_57 -> V_278 ) ) )
goto V_78;
if ( F_65 ( V_16 , V_279 , F_66 ( V_57 -> V_280 ) ) )
goto V_78;
if ( V_57 -> V_36 & V_281 ) {
if ( F_65 ( V_16 , V_282 , F_66 ( V_57 -> V_283 ) ) )
goto V_78;
if ( F_65 ( V_16 , V_284 , F_66 ( V_57 -> V_247 ) ) )
goto V_78;
}
if ( V_57 -> V_36 & V_285 &&
F_65 ( V_16 , V_286 , F_66 ( V_57 -> V_287 ) ) )
goto V_78;
if ( V_57 -> V_288 &&
F_119 ( V_16 , V_289 ,
F_120 ( F_202 ( V_57 -> V_288 ) ) ,
V_290 ) )
goto V_78;
if ( V_57 -> V_291 &&
F_65 ( V_16 , V_292 , F_66 ( V_57 -> V_291 ) ) )
goto V_78;
if ( V_57 -> V_166 != V_265 ) {
if ( F_65 ( V_16 , V_293 , F_66 ( V_57 -> V_166 ) ) )
goto V_78;
}
if ( F_172 ( V_16 , V_294 , V_57 -> V_295 , V_57 -> V_233 ) )
goto V_78;
V_255 = F_118 ( V_16 , V_296 ) ;
if ( V_255 == NULL )
goto V_78;
if ( V_57 -> V_31 &&
F_65 ( V_16 , V_297 , F_66 ( V_57 -> V_31 ) ) )
goto V_78;
F_121 ( V_16 , V_255 ) ;
F_67 ( V_16 , V_18 ) ;
return 0 ;
V_78:
F_68 ( V_16 , V_18 ) ;
return - 1 ;
}
static void F_203 ( const struct V_13 * V_14 ,
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
V_43 = F_201 ( V_16 , V_14 , V_57 , V_75 , 0 ) ;
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
static int F_204 ( struct V_15 * V_16 , struct V_90 * V_91 )
{
const struct V_56 * V_57 ;
unsigned int V_92 , V_93 = V_91 -> args [ 0 ] ;
struct V_2 * V_3 ;
struct V_19 * V_20 , * V_299 = (struct V_19 * ) V_91 -> args [ 2 ] ;
struct V_1 * V_1 = F_76 ( V_16 -> V_94 ) ;
int V_300 = V_91 -> args [ 3 ] ;
struct V_13 * V_14 = V_91 -> V_210 , V_301 ;
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
if ( F_201 ( V_16 , & V_301 , V_57 ,
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
static int F_205 ( struct V_90 * V_91 )
{
F_23 ( V_91 -> V_210 ) ;
return 0 ;
}
static int F_206 ( struct V_1 * V_1 , struct V_100 * V_101 ,
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
V_43 = F_191 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_67 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_18 -> V_105 & V_106 ) {
struct V_107 V_108 = {
. V_109 = F_204 ,
. V_98 = F_205 ,
} ;
struct V_13 * V_302 ;
V_302 = F_207 ( sizeof( * V_302 ) , V_34 ) ;
if ( V_302 == NULL )
return - V_40 ;
* V_302 = V_14 ;
V_108 . V_210 = V_302 ;
return F_85 ( V_101 , V_16 , V_18 , & V_108 ) ;
}
if ( V_77 -> V_79 == V_95 )
return - V_12 ;
if ( ! V_24 [ V_267 ] )
return - V_69 ;
V_57 = F_192 ( V_14 . V_20 , V_24 [ V_276 ] , V_67 ) ;
if ( F_86 ( V_57 ) )
return F_87 ( V_57 ) ;
V_104 = F_88 ( V_88 , V_34 ) ;
if ( V_104 == NULL )
return - V_40 ;
V_43 = F_201 ( V_104 , & V_14 , V_57 , V_59 , 0 ) ;
if ( V_43 < 0 )
goto V_43;
return F_89 ( V_101 , V_104 , F_16 ( V_16 ) . V_25 ) ;
V_43:
F_72 ( V_104 ) ;
return V_43 ;
}
static int F_208 ( const struct V_13 * V_14 ,
struct V_254 * V_255 ,
const struct V_23 * V_24 )
{
struct V_23 * V_303 [ V_304 + 1 ] ;
int V_43 ;
V_43 = F_127 ( V_303 , V_304 , V_24 ,
V_305 , NULL ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_303 [ V_297 ] != NULL )
V_255 -> V_31 = F_41 ( F_42 ( V_303 [ V_297 ] ) ) ;
return 0 ;
}
static int F_209 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
struct V_102 * V_103 )
{
const struct V_76 * V_77 = F_62 ( V_18 ) ;
T_3 V_67 = F_97 ( V_1 ) ;
const struct V_251 * V_38 ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_56 * V_57 ;
struct V_13 V_14 ;
char * V_68 ;
unsigned int V_31 ;
bool V_179 ;
T_4 V_288 ;
T_1 V_278 , V_283 , V_36 , V_166 , V_291 , V_287 ;
struct V_254 V_255 ;
unsigned char * V_233 ;
T_7 V_295 ;
int V_43 ;
if ( V_24 [ V_267 ] == NULL ||
V_24 [ V_276 ] == NULL ||
V_24 [ V_279 ] == NULL ||
V_24 [ V_60 ] == NULL )
return - V_69 ;
memset ( & V_255 , 0 , sizeof( V_255 ) ) ;
V_278 = V_306 ;
if ( V_24 [ V_277 ] != NULL ) {
V_278 = F_41 ( F_42 ( V_24 [ V_277 ] ) ) ;
if ( ( V_278 & V_307 ) == V_307 )
return - V_69 ;
}
V_255 . V_280 = F_41 ( F_42 ( V_24 [ V_279 ] ) ) ;
if ( V_255 . V_280 == 0 || V_255 . V_280 > V_308 )
return - V_69 ;
V_36 = 0 ;
if ( V_24 [ V_261 ] != NULL ) {
V_36 = F_41 ( F_42 ( V_24 [ V_261 ] ) ) ;
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
V_255 . V_247 = F_41 ( F_42 ( V_24 [ V_284 ] ) ) ;
if ( V_255 . V_247 == 0 || V_255 . V_247 > V_308 )
return - V_69 ;
} else
V_255 . V_247 = sizeof( struct V_314 ) ;
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
V_288 = F_210 ( F_131 ( F_132 (
V_24 [ V_289 ] ) ) ) ;
}
V_291 = 0 ;
if ( V_24 [ V_292 ] != NULL ) {
if ( ! ( V_36 & V_311 ) )
return - V_69 ;
V_291 = F_41 ( F_42 ( V_24 [ V_292 ] ) ) ;
}
V_166 = V_265 ;
if ( V_24 [ V_293 ] != NULL )
V_166 = F_41 ( F_42 ( V_24 [ V_293 ] ) ) ;
if ( V_24 [ V_296 ] != NULL ) {
V_43 = F_208 ( & V_14 , & V_255 , V_24 [ V_296 ] ) ;
if ( V_43 < 0 )
return V_43 ;
}
V_179 = V_18 -> V_105 & V_203 ? true : false ;
V_3 = F_11 ( V_1 , V_77 -> V_79 , V_179 ) ;
if ( F_86 ( V_3 ) )
return F_87 ( V_3 ) ;
V_20 = F_53 ( V_3 , V_24 [ V_267 ] , V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
V_57 = F_192 ( V_20 , V_24 [ V_276 ] , V_67 ) ;
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
if ( ! ( V_18 -> V_105 & V_203 ) )
return - V_51 ;
V_38 = F_190 ( & V_14 , V_24 , & V_255 , V_166 ) ;
if ( F_86 ( V_38 ) )
return F_87 ( V_38 ) ;
V_295 = 0 ;
if ( V_24 [ V_294 ] )
V_295 = F_57 ( V_24 [ V_294 ] ) ;
V_31 = 0 ;
if ( V_38 -> V_317 != NULL )
V_31 = V_38 -> V_317 ( V_24 , & V_255 ) ;
V_57 = F_211 ( sizeof( * V_57 ) + V_31 + V_295 , V_34 ) ;
if ( ! V_57 ) {
V_43 = - V_40 ;
goto V_118;
}
V_68 = F_99 ( V_24 [ V_276 ] , V_34 ) ;
if ( ! V_68 ) {
V_43 = - V_40 ;
goto V_119;
}
V_43 = F_195 ( & V_14 , V_57 , V_68 ) ;
F_23 ( V_68 ) ;
if ( V_43 < 0 )
goto V_119;
V_233 = NULL ;
if ( V_295 ) {
V_233 = V_57 -> V_210 + V_31 ;
F_184 ( V_233 , V_24 [ V_294 ] , V_295 ) ;
}
F_2 ( & V_57 -> V_130 ) ;
V_57 -> V_38 = V_38 ;
V_57 -> V_278 = V_278 ;
V_57 -> V_280 = V_255 . V_280 ;
V_57 -> V_283 = V_283 ;
V_57 -> V_287 = V_287 ;
V_57 -> V_247 = V_255 . V_247 ;
V_57 -> V_36 = V_36 ;
V_57 -> V_31 = V_255 . V_31 ;
V_57 -> V_166 = V_166 ;
V_57 -> V_295 = V_295 ;
V_57 -> V_233 = V_233 ;
V_57 -> V_288 = V_288 ;
V_57 -> V_291 = V_291 ;
V_43 = V_38 -> V_219 ( V_57 , & V_255 , V_24 ) ;
if ( V_43 < 0 )
goto V_119;
V_43 = F_45 ( & V_14 , V_59 , V_57 ) ;
if ( V_43 < 0 )
goto V_120;
F_4 ( & V_57 -> V_6 , & V_20 -> V_122 ) ;
V_20 -> V_48 ++ ;
return 0 ;
V_120:
V_38 -> V_222 ( V_57 ) ;
V_119:
F_212 ( V_57 ) ;
V_118:
F_100 ( V_38 -> type -> V_117 ) ;
return V_43 ;
}
static void F_213 ( struct V_56 * V_57 )
{
V_57 -> V_38 -> V_222 ( V_57 ) ;
F_100 ( V_57 -> V_38 -> type -> V_117 ) ;
F_23 ( V_57 -> V_68 ) ;
F_212 ( V_57 ) ;
}
static void F_214 ( const struct V_13 * V_14 , struct V_56 * V_57 )
{
F_8 ( & V_57 -> V_6 ) ;
F_203 ( V_14 , V_57 , V_61 , V_318 ) ;
F_213 ( V_57 ) ;
}
static int F_215 ( struct V_1 * V_1 , struct V_100 * V_101 ,
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
if ( V_24 [ V_267 ] == NULL )
return - V_69 ;
V_43 = F_191 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_67 ) ;
if ( V_43 < 0 )
return V_43 ;
V_57 = F_192 ( V_14 . V_20 , V_24 [ V_276 ] , V_67 ) ;
if ( F_86 ( V_57 ) )
return F_87 ( V_57 ) ;
if ( ! F_103 ( & V_57 -> V_130 ) ||
( V_18 -> V_105 & V_133 && F_216 ( & V_57 -> V_319 ) > 0 ) )
return - V_134 ;
return F_47 ( & V_14 , V_57 ) ;
}
static int F_217 ( const struct V_13 * V_14 ,
struct V_56 * V_57 ,
const struct V_320 * V_321 ,
struct V_322 * V_323 )
{
const struct V_324 * V_325 = F_218 ( V_57 , V_323 -> V_196 ) ;
enum V_326 V_327 ;
V_327 = F_219 ( V_57 -> V_283 ) ;
return F_220 ( V_14 , V_327 , F_221 ( V_325 ) ,
V_57 -> V_283 == V_313 ?
V_313 : V_306 ,
V_57 -> V_247 ) ;
}
int F_222 ( const struct V_13 * V_14 , struct V_56 * V_57 ,
struct V_328 * V_329 )
{
struct V_328 * V_72 ;
struct V_320 V_321 ;
if ( ! F_103 ( & V_57 -> V_130 ) && V_57 -> V_36 & V_129 )
return - V_134 ;
if ( V_329 -> V_36 & V_281 ) {
F_10 (i, &set->bindings, list) {
if ( V_72 -> V_36 & V_281 &&
V_72 -> V_22 == V_329 -> V_22 )
goto V_330;
}
V_321 . V_67 = F_97 ( V_14 -> V_1 ) ;
V_321 . V_331 = 0 ;
V_321 . V_332 = 0 ;
V_321 . V_43 = 0 ;
V_321 . V_333 = F_217 ;
V_57 -> V_38 -> V_334 ( V_14 , V_57 , & V_321 ) ;
if ( V_321 . V_43 < 0 )
return V_321 . V_43 ;
}
V_330:
V_329 -> V_22 = V_14 -> V_22 ;
F_4 ( & V_329 -> V_6 , & V_57 -> V_130 ) ;
return 0 ;
}
void F_223 ( const struct V_13 * V_14 , struct V_56 * V_57 ,
struct V_328 * V_329 )
{
F_8 ( & V_329 -> V_6 ) ;
if ( F_103 ( & V_57 -> V_130 ) && V_57 -> V_36 & V_129 &&
F_79 ( V_14 -> V_1 , V_57 ) )
F_214 ( V_14 , V_57 ) ;
}
static int F_224 ( struct V_13 * V_14 , struct V_1 * V_1 ,
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
V_20 = F_53 ( V_3 , V_24 [ V_335 ] ,
V_67 ) ;
if ( F_86 ( V_20 ) )
return F_87 ( V_20 ) ;
F_15 ( V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return 0 ;
}
static int F_225 ( struct V_15 * V_16 ,
const struct V_56 * V_57 ,
const struct V_322 * V_323 )
{
const struct V_324 * V_325 = F_218 ( V_57 , V_323 -> V_196 ) ;
unsigned char * V_336 = F_226 ( V_16 ) ;
struct V_23 * V_142 ;
V_142 = F_118 ( V_16 , V_232 ) ;
if ( V_142 == NULL )
goto V_78;
if ( F_227 ( V_16 , V_337 , F_228 ( V_325 ) ,
V_306 , V_57 -> V_280 ) < 0 )
goto V_78;
if ( F_229 ( V_325 , V_338 ) &&
F_227 ( V_16 , V_339 , F_221 ( V_325 ) ,
V_57 -> V_283 == V_313 ? V_313 : V_306 ,
V_57 -> V_247 ) < 0 )
goto V_78;
if ( F_229 ( V_325 , V_340 ) &&
F_161 ( V_16 , V_341 , F_230 ( V_325 ) ) < 0 )
goto V_78;
if ( F_229 ( V_325 , V_342 ) &&
F_64 ( V_16 , V_343 ,
( * F_231 ( V_325 ) ) -> V_68 ) < 0 )
goto V_78;
if ( F_229 ( V_325 , V_344 ) &&
F_65 ( V_16 , V_345 ,
F_66 ( * F_232 ( V_325 ) ) ) )
goto V_78;
if ( F_229 ( V_325 , V_346 ) &&
F_119 ( V_16 , V_347 ,
F_120 ( F_202 (
* F_233 ( V_325 ) ) ) ,
V_348 ) )
goto V_78;
if ( F_229 ( V_325 , V_349 ) ) {
unsigned long V_350 , V_351 = V_352 ;
V_350 = * F_234 ( V_325 ) ;
if ( F_235 ( V_351 , V_350 ) )
V_350 -= V_351 ;
else
V_350 = 0 ;
if ( F_119 ( V_16 , V_353 ,
F_120 ( F_202 ( V_350 ) ) ,
V_348 ) )
goto V_78;
}
if ( F_229 ( V_325 , V_354 ) ) {
struct V_234 * V_233 ;
V_233 = F_236 ( V_325 ) ;
if ( F_172 ( V_16 , V_355 ,
V_233 -> V_99 + 1 , V_233 -> V_210 ) )
goto V_78;
}
F_121 ( V_16 , V_142 ) ;
return 0 ;
V_78:
F_68 ( V_16 , V_336 ) ;
return - V_356 ;
}
static int F_237 ( const struct V_13 * V_14 ,
struct V_56 * V_57 ,
const struct V_320 * V_321 ,
struct V_322 * V_323 )
{
struct V_357 * args ;
args = F_238 ( V_321 , struct V_357 , V_321 ) ;
return F_225 ( args -> V_16 , V_57 , V_323 ) ;
}
static int F_239 ( struct V_15 * V_16 , struct V_90 * V_91 )
{
struct V_358 * V_359 = V_91 -> V_210 ;
struct V_1 * V_1 = F_76 ( V_16 -> V_94 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_56 * V_57 ;
struct V_357 args ;
bool V_360 = false ;
struct V_76 * V_77 ;
struct V_17 * V_18 ;
struct V_23 * V_142 ;
T_1 V_25 , V_27 ;
int V_75 ;
F_77 () ;
F_78 (afi, &net->nft.af_info, list) {
if ( V_3 != V_359 -> V_14 . V_3 )
continue;
F_78 (table, &afi->tables, list) {
if ( V_20 != V_359 -> V_14 . V_20 )
continue;
F_78 (set, &table->sets, list) {
if ( V_57 == V_359 -> V_57 ) {
V_360 = true ;
break;
}
}
break;
}
break;
}
if ( ! V_360 ) {
F_82 () ;
return - V_51 ;
}
V_75 = F_60 ( V_5 , V_361 ) ;
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
if ( F_64 ( V_16 , V_335 , V_20 -> V_68 ) )
goto V_78;
if ( F_64 ( V_16 , V_362 , V_57 -> V_68 ) )
goto V_78;
V_142 = F_118 ( V_16 , V_363 ) ;
if ( V_142 == NULL )
goto V_78;
args . V_91 = V_91 ;
args . V_16 = V_16 ;
args . V_321 . V_67 = F_84 ( V_1 ) ;
args . V_321 . V_331 = V_91 -> args [ 0 ] ;
args . V_321 . V_332 = 0 ;
args . V_321 . V_43 = 0 ;
args . V_321 . V_333 = F_237 ;
V_57 -> V_38 -> V_334 ( & V_359 -> V_14 , V_57 , & args . V_321 ) ;
F_82 () ;
F_121 ( V_16 , V_142 ) ;
F_67 ( V_16 , V_18 ) ;
if ( args . V_321 . V_43 && args . V_321 . V_43 != - V_356 )
return args . V_321 . V_43 ;
if ( args . V_321 . V_332 == V_91 -> args [ 0 ] )
return 0 ;
V_91 -> args [ 0 ] = args . V_321 . V_332 ;
return V_16 -> V_99 ;
V_78:
F_82 () ;
return - V_151 ;
}
static int F_240 ( struct V_90 * V_91 )
{
F_23 ( V_91 -> V_210 ) ;
return 0 ;
}
static int F_241 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
struct V_102 * V_103 )
{
T_3 V_67 = F_84 ( V_1 ) ;
const struct V_56 * V_57 ;
struct V_13 V_14 ;
int V_43 ;
V_43 = F_224 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_67 ) ;
if ( V_43 < 0 )
return V_43 ;
V_57 = F_192 ( V_14 . V_20 , V_24 [ V_362 ] ,
V_67 ) ;
if ( F_86 ( V_57 ) )
return F_87 ( V_57 ) ;
if ( V_18 -> V_105 & V_106 ) {
struct V_107 V_108 = {
. V_109 = F_239 ,
. V_98 = F_240 ,
} ;
struct V_358 * V_359 ;
V_359 = F_207 ( sizeof( * V_359 ) , V_34 ) ;
if ( ! V_359 )
return - V_40 ;
V_359 -> V_57 = V_57 ;
V_359 -> V_14 = V_14 ;
V_108 . V_210 = V_359 ;
return F_85 ( V_101 , V_16 , V_18 , & V_108 ) ;
}
return - V_116 ;
}
static int F_242 ( struct V_15 * V_16 ,
const struct V_13 * V_14 , T_1 V_27 ,
T_1 V_25 , int V_75 , T_7 V_36 ,
const struct V_56 * V_57 ,
const struct V_322 * V_323 )
{
struct V_76 * V_77 ;
struct V_17 * V_18 ;
struct V_23 * V_142 ;
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
if ( F_64 ( V_16 , V_267 , V_14 -> V_20 -> V_68 ) )
goto V_78;
if ( F_64 ( V_16 , V_276 , V_57 -> V_68 ) )
goto V_78;
V_142 = F_118 ( V_16 , V_363 ) ;
if ( V_142 == NULL )
goto V_78;
V_43 = F_225 ( V_16 , V_57 , V_323 ) ;
if ( V_43 < 0 )
goto V_78;
F_121 ( V_16 , V_142 ) ;
F_67 ( V_16 , V_18 ) ;
return 0 ;
V_78:
F_68 ( V_16 , V_18 ) ;
return - 1 ;
}
static void F_243 ( const struct V_13 * V_14 ,
const struct V_56 * V_57 ,
const struct V_322 * V_323 ,
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
V_43 = F_242 ( V_16 , V_14 , 0 , V_25 , V_75 , V_36 ,
V_57 , V_323 ) ;
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
static struct V_29 * F_244 ( struct V_13 * V_14 ,
int V_30 ,
struct V_56 * V_57 )
{
struct V_29 * V_33 ;
V_33 = F_20 ( V_14 , V_30 , sizeof( struct V_364 ) ) ;
if ( V_33 == NULL )
return NULL ;
F_245 ( V_33 ) = V_57 ;
return V_33 ;
}
void * F_246 ( const struct V_56 * V_57 ,
const struct V_365 * V_366 ,
const T_1 * V_367 , const T_1 * V_210 ,
T_4 V_288 , T_2 V_32 )
{
struct V_324 * V_325 ;
void * V_323 ;
V_323 = F_19 ( V_57 -> V_38 -> V_368 + V_366 -> V_99 , V_32 ) ;
if ( V_323 == NULL )
return NULL ;
V_325 = F_218 ( V_57 , V_323 ) ;
F_247 ( V_325 , V_366 ) ;
memcpy ( F_228 ( V_325 ) , V_367 , V_57 -> V_280 ) ;
if ( F_229 ( V_325 , V_338 ) )
memcpy ( F_221 ( V_325 ) , V_210 , V_57 -> V_247 ) ;
if ( F_229 ( V_325 , V_349 ) )
* F_234 ( V_325 ) =
V_352 + V_288 ;
if ( F_229 ( V_325 , V_346 ) )
* F_233 ( V_325 ) = V_288 ;
return V_323 ;
}
void F_248 ( const struct V_56 * V_57 , void * V_323 ,
bool V_369 )
{
struct V_324 * V_325 = F_218 ( V_57 , V_323 ) ;
F_249 ( F_228 ( V_325 ) , V_306 ) ;
if ( F_229 ( V_325 , V_338 ) )
F_249 ( F_221 ( V_325 ) , V_57 -> V_283 ) ;
if ( V_369 && F_229 ( V_325 , V_340 ) )
F_164 ( NULL , F_230 ( V_325 ) ) ;
if ( F_229 ( V_325 , V_342 ) )
( * F_231 ( V_325 ) ) -> V_48 -- ;
F_23 ( V_323 ) ;
}
static void F_250 ( const struct V_56 * V_57 , void * V_323 )
{
struct V_324 * V_325 = F_218 ( V_57 , V_323 ) ;
if ( F_229 ( V_325 , V_340 ) )
F_164 ( NULL , F_230 ( V_325 ) ) ;
F_23 ( V_323 ) ;
}
static int F_251 ( const struct V_56 * V_57 ,
const struct V_23 * V_169 , T_1 * V_36 )
{
if ( V_169 == NULL )
return 0 ;
* V_36 = F_41 ( F_42 ( V_169 ) ) ;
if ( * V_36 & ~ V_370 )
return - V_69 ;
if ( ! ( V_57 -> V_36 & V_310 ) &&
* V_36 & V_370 )
return - V_69 ;
return 0 ;
}
static int F_252 ( struct V_13 * V_14 , struct V_56 * V_57 ,
const struct V_23 * V_169 , T_1 V_105 )
{
struct V_23 * V_24 [ V_371 + 1 ] ;
T_3 V_67 = F_97 ( V_14 -> V_1 ) ;
struct V_372 V_373 , V_374 ;
struct V_365 V_366 ;
struct V_324 * V_325 , * V_375 ;
struct V_322 V_323 ;
struct V_328 * V_329 ;
struct V_62 * V_63 = NULL ;
struct V_234 * V_233 ;
struct V_221 V_210 ;
enum V_326 V_327 ;
struct V_29 * V_33 ;
T_1 V_36 = 0 ;
T_4 V_288 ;
T_3 V_241 ;
int V_43 ;
V_43 = F_127 ( V_24 , V_371 , V_169 ,
V_376 , NULL ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_24 [ V_337 ] == NULL )
return - V_69 ;
F_253 ( & V_366 ) ;
V_43 = F_251 ( V_57 , V_24 [ V_345 ] , & V_36 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_36 != 0 )
F_254 ( & V_366 , V_344 ) ;
if ( V_57 -> V_36 & V_281 ) {
if ( V_24 [ V_339 ] == NULL &&
! ( V_36 & V_370 ) )
return - V_69 ;
if ( V_24 [ V_339 ] != NULL &&
V_36 & V_370 )
return - V_69 ;
} else {
if ( V_24 [ V_339 ] != NULL )
return - V_69 ;
}
V_288 = 0 ;
if ( V_24 [ V_347 ] != NULL ) {
if ( ! ( V_57 -> V_36 & V_311 ) )
return - V_69 ;
V_288 = F_210 ( F_131 ( F_132 (
V_24 [ V_347 ] ) ) ) ;
} else if ( V_57 -> V_36 & V_311 ) {
V_288 = V_57 -> V_288 ;
}
V_43 = F_255 ( V_14 , & V_323 . V_367 . V_377 , sizeof( V_323 . V_367 ) , & V_373 ,
V_24 [ V_337 ] ) ;
if ( V_43 < 0 )
goto V_118;
V_43 = - V_69 ;
if ( V_373 . type != V_306 || V_373 . V_99 != V_57 -> V_280 )
goto V_119;
F_256 ( & V_366 , V_378 , V_373 . V_99 ) ;
if ( V_288 > 0 ) {
F_254 ( & V_366 , V_349 ) ;
if ( V_288 != V_57 -> V_288 )
F_254 ( & V_366 , V_346 ) ;
}
if ( V_24 [ V_343 ] != NULL ) {
if ( ! ( V_57 -> V_36 & V_285 ) ) {
V_43 = - V_69 ;
goto V_119;
}
V_63 = F_257 ( V_14 -> V_20 , V_24 [ V_343 ] ,
V_57 -> V_287 , V_67 ) ;
if ( F_86 ( V_63 ) ) {
V_43 = F_87 ( V_63 ) ;
goto V_119;
}
F_254 ( & V_366 , V_342 ) ;
}
if ( V_24 [ V_339 ] != NULL ) {
V_43 = F_255 ( V_14 , & V_210 , sizeof( V_210 ) , & V_374 ,
V_24 [ V_339 ] ) ;
if ( V_43 < 0 )
goto V_119;
V_43 = - V_69 ;
if ( V_57 -> V_283 != V_313 && V_374 . V_99 != V_57 -> V_247 )
goto V_120;
V_327 = F_219 ( V_57 -> V_283 ) ;
F_10 (binding, &set->bindings, list) {
struct V_13 V_379 = {
. V_1 = V_14 -> V_1 ,
. V_3 = V_14 -> V_3 ,
. V_20 = V_14 -> V_20 ,
. V_22 = (struct V_21 * ) V_329 -> V_22 ,
} ;
if ( ! ( V_329 -> V_36 & V_281 ) )
continue;
V_43 = F_220 ( & V_379 , V_327 ,
& V_210 ,
V_374 . type , V_374 . V_99 ) ;
if ( V_43 < 0 )
goto V_120;
}
F_256 ( & V_366 , V_338 , V_374 . V_99 ) ;
}
V_241 = 0 ;
if ( V_24 [ V_355 ] != NULL ) {
V_241 = F_57 ( V_24 [ V_355 ] ) ;
if ( V_241 > 0 )
F_256 ( & V_366 , V_354 ,
V_241 ) ;
}
V_43 = - V_40 ;
V_323 . V_196 = F_246 ( V_57 , & V_366 , V_323 . V_367 . V_377 . V_210 , V_210 . V_210 ,
V_288 , V_34 ) ;
if ( V_323 . V_196 == NULL )
goto V_120;
V_325 = F_218 ( V_57 , V_323 . V_196 ) ;
if ( V_36 )
* F_232 ( V_325 ) = V_36 ;
if ( V_241 > 0 ) {
V_233 = F_236 ( V_325 ) ;
V_233 -> V_99 = V_241 - 1 ;
F_184 ( & V_233 -> V_210 , V_24 [ V_355 ] , V_241 ) ;
}
if ( V_63 ) {
* F_231 ( V_325 ) = V_63 ;
V_63 -> V_48 ++ ;
}
V_33 = F_244 ( V_14 , V_361 , V_57 ) ;
if ( V_33 == NULL )
goto V_124;
V_325 -> V_67 = F_84 ( V_14 -> V_1 ) | V_380 ;
V_43 = V_57 -> V_38 -> V_381 ( V_14 -> V_1 , V_57 , & V_323 , & V_375 ) ;
if ( V_43 ) {
if ( V_43 == - V_114 ) {
if ( F_229 ( V_325 , V_338 ) ^
F_229 ( V_375 , V_338 ) ||
F_229 ( V_325 , V_342 ) ^
F_229 ( V_375 , V_342 ) )
return - V_134 ;
if ( ( F_229 ( V_325 , V_338 ) &&
F_229 ( V_375 , V_338 ) &&
memcmp ( F_221 ( V_325 ) ,
F_221 ( V_375 ) , V_57 -> V_247 ) != 0 ) ||
( F_229 ( V_325 , V_342 ) &&
F_229 ( V_375 , V_342 ) &&
* F_231 ( V_325 ) != * F_231 ( V_375 ) ) )
V_43 = - V_134 ;
else if ( ! ( V_105 & V_113 ) )
V_43 = 0 ;
}
goto V_382;
}
if ( V_57 -> V_31 &&
! F_258 ( & V_57 -> V_319 , 1 , V_57 -> V_31 + V_57 -> V_383 ) ) {
V_43 = - V_275 ;
goto V_384;
}
V_364 ( V_33 ) = V_323 ;
F_32 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_42 ) ;
return 0 ;
V_384:
V_57 -> V_38 -> remove ( V_14 -> V_1 , V_57 , & V_323 ) ;
V_382:
F_23 ( V_33 ) ;
V_124:
F_23 ( V_323 . V_196 ) ;
V_120:
if ( V_24 [ V_339 ] != NULL )
F_249 ( & V_210 , V_374 . type ) ;
V_119:
F_249 ( & V_323 . V_367 . V_377 , V_373 . type ) ;
V_118:
return V_43 ;
}
static int F_259 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
struct V_102 * V_103 )
{
T_3 V_67 = F_97 ( V_1 ) ;
const struct V_23 * V_169 ;
struct V_56 * V_57 ;
struct V_13 V_14 ;
int V_243 , V_43 = 0 ;
if ( V_24 [ V_363 ] == NULL )
return - V_69 ;
V_43 = F_224 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_67 ) ;
if ( V_43 < 0 )
return V_43 ;
V_57 = F_192 ( V_14 . V_20 , V_24 [ V_362 ] ,
V_67 ) ;
if ( F_86 ( V_57 ) ) {
if ( V_24 [ V_385 ] ) {
V_57 = F_193 ( V_1 ,
V_24 [ V_385 ] ,
V_67 ) ;
}
if ( F_86 ( V_57 ) )
return F_87 ( V_57 ) ;
}
if ( ! F_103 ( & V_57 -> V_130 ) && V_57 -> V_36 & V_309 )
return - V_134 ;
F_182 (attr, nla[NFTA_SET_ELEM_LIST_ELEMENTS], rem) {
V_43 = F_252 ( & V_14 , V_57 , V_169 , V_18 -> V_105 ) ;
if ( V_43 < 0 )
break;
}
return V_43 ;
}
static void F_260 ( const struct V_221 * V_210 , enum V_386 type )
{
if ( type == V_313 ) {
switch ( V_210 -> V_387 . V_388 ) {
case V_389 :
case V_390 :
V_210 -> V_387 . V_22 -> V_48 ++ ;
break;
}
}
}
static void F_261 ( const struct V_1 * V_1 ,
const struct V_56 * V_57 ,
struct V_322 * V_323 )
{
const struct V_324 * V_325 = F_218 ( V_57 , V_323 -> V_196 ) ;
if ( F_229 ( V_325 , V_338 ) )
F_260 ( F_221 ( V_325 ) , V_57 -> V_283 ) ;
if ( F_229 ( V_325 , V_342 ) )
( * F_231 ( V_325 ) ) -> V_48 ++ ;
}
static void F_262 ( const struct V_1 * V_1 ,
const struct V_56 * V_57 ,
struct V_322 * V_323 )
{
const struct V_324 * V_325 = F_218 ( V_57 , V_323 -> V_196 ) ;
if ( F_229 ( V_325 , V_338 ) )
F_249 ( F_221 ( V_325 ) , V_57 -> V_283 ) ;
if ( F_229 ( V_325 , V_342 ) )
( * F_231 ( V_325 ) ) -> V_48 -- ;
}
static int F_263 ( struct V_13 * V_14 , struct V_56 * V_57 ,
const struct V_23 * V_169 )
{
struct V_23 * V_24 [ V_371 + 1 ] ;
struct V_365 V_366 ;
struct V_372 V_255 ;
struct V_322 V_323 ;
struct V_324 * V_325 ;
struct V_29 * V_33 ;
T_1 V_36 = 0 ;
void * V_196 ;
int V_43 ;
V_43 = F_127 ( V_24 , V_371 , V_169 ,
V_376 , NULL ) ;
if ( V_43 < 0 )
goto V_118;
V_43 = - V_69 ;
if ( V_24 [ V_337 ] == NULL )
goto V_118;
F_253 ( & V_366 ) ;
V_43 = F_251 ( V_57 , V_24 [ V_345 ] , & V_36 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_36 != 0 )
F_254 ( & V_366 , V_344 ) ;
V_43 = F_255 ( V_14 , & V_323 . V_367 . V_377 , sizeof( V_323 . V_367 ) , & V_255 ,
V_24 [ V_337 ] ) ;
if ( V_43 < 0 )
goto V_118;
V_43 = - V_69 ;
if ( V_255 . type != V_306 || V_255 . V_99 != V_57 -> V_280 )
goto V_119;
F_256 ( & V_366 , V_378 , V_255 . V_99 ) ;
V_43 = - V_40 ;
V_323 . V_196 = F_246 ( V_57 , & V_366 , V_323 . V_367 . V_377 . V_210 , NULL , 0 ,
V_34 ) ;
if ( V_323 . V_196 == NULL )
goto V_119;
V_325 = F_218 ( V_57 , V_323 . V_196 ) ;
if ( V_36 )
* F_232 ( V_325 ) = V_36 ;
V_33 = F_244 ( V_14 , V_391 , V_57 ) ;
if ( V_33 == NULL ) {
V_43 = - V_40 ;
goto V_120;
}
V_196 = V_57 -> V_38 -> V_392 ( V_14 -> V_1 , V_57 , & V_323 ) ;
if ( V_196 == NULL ) {
V_43 = - V_51 ;
goto V_124;
}
F_23 ( V_323 . V_196 ) ;
V_323 . V_196 = V_196 ;
F_262 ( V_14 -> V_1 , V_57 , & V_323 ) ;
V_364 ( V_33 ) = V_323 ;
F_32 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_42 ) ;
return 0 ;
V_124:
F_23 ( V_33 ) ;
V_120:
F_23 ( V_323 . V_196 ) ;
V_119:
F_249 ( & V_323 . V_367 . V_377 , V_255 . type ) ;
V_118:
return V_43 ;
}
static int F_264 ( const struct V_13 * V_14 ,
struct V_56 * V_57 ,
const struct V_320 * V_321 ,
struct V_322 * V_323 )
{
struct V_29 * V_33 ;
int V_43 ;
V_33 = F_18 ( V_14 , V_391 ,
sizeof( struct V_364 ) , V_318 ) ;
if ( ! V_33 )
return - V_40 ;
if ( ! V_57 -> V_38 -> V_393 ( V_14 -> V_1 , V_57 , V_323 -> V_196 ) ) {
V_43 = - V_51 ;
goto V_118;
}
V_57 -> V_383 ++ ;
F_245 ( V_33 ) = V_57 ;
V_364 ( V_33 ) = * V_323 ;
F_32 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_42 ) ;
return 0 ;
V_118:
F_23 ( V_33 ) ;
return V_43 ;
}
static int F_265 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
struct V_102 * V_103 )
{
T_3 V_67 = F_97 ( V_1 ) ;
const struct V_23 * V_169 ;
struct V_56 * V_57 ;
struct V_13 V_14 ;
int V_243 , V_43 = 0 ;
V_43 = F_224 ( & V_14 , V_1 , V_16 , V_18 , V_24 , V_67 ) ;
if ( V_43 < 0 )
return V_43 ;
V_57 = F_192 ( V_14 . V_20 , V_24 [ V_362 ] ,
V_67 ) ;
if ( F_86 ( V_57 ) )
return F_87 ( V_57 ) ;
if ( ! F_103 ( & V_57 -> V_130 ) && V_57 -> V_36 & V_309 )
return - V_134 ;
if ( V_24 [ V_363 ] == NULL ) {
struct V_320 V_321 = {
. V_67 = V_67 ,
. V_333 = F_264 ,
} ;
V_57 -> V_38 -> V_334 ( & V_14 , V_57 , & V_321 ) ;
return V_321 . V_43 ;
}
F_182 (attr, nla[NFTA_SET_ELEM_LIST_ELEMENTS], rem) {
V_43 = F_263 ( & V_14 , V_57 , V_169 ) ;
if ( V_43 < 0 )
break;
V_57 -> V_383 ++ ;
}
return V_43 ;
}
void F_266 ( struct V_394 * V_395 )
{
struct V_396 * V_397 ;
unsigned int V_72 ;
V_397 = F_238 ( V_395 , struct V_396 , V_398 . V_395 ) ;
for ( V_72 = 0 ; V_72 < V_397 -> V_398 . V_110 ; V_72 ++ )
F_248 ( V_397 -> V_398 . V_57 , V_397 -> V_399 [ V_72 ] , true ) ;
F_23 ( V_397 ) ;
}
struct V_396 * F_267 ( const struct V_56 * V_57 ,
T_2 V_32 )
{
struct V_396 * V_397 ;
V_397 = F_19 ( sizeof( * V_397 ) , V_32 ) ;
if ( V_397 == NULL )
return V_397 ;
V_397 -> V_398 . V_57 = V_57 ;
return V_397 ;
}
int F_268 ( struct V_400 * V_401 )
{
if ( V_401 -> type == V_315 )
return - V_69 ;
F_3 ( V_5 ) ;
F_156 ( & V_401 -> V_6 , & V_402 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_269 ( struct V_400 * V_401 )
{
F_3 ( V_5 ) ;
F_8 ( & V_401 -> V_6 ) ;
F_5 ( V_5 ) ;
}
struct V_62 * F_257 ( const struct V_19 * V_20 ,
const struct V_23 * V_24 ,
T_1 V_287 , T_3 V_67 )
{
struct V_62 * V_63 ;
F_10 (obj, &table->objects, list) {
if ( ! F_51 ( V_24 , V_63 -> V_68 ) &&
V_287 == V_63 -> V_38 -> type -> type &&
F_52 ( V_63 , V_67 ) )
return V_63 ;
}
return F_14 ( - V_51 ) ;
}
static struct V_62 * F_270 ( const struct V_13 * V_14 ,
const struct V_400 * type ,
const struct V_23 * V_169 )
{
struct V_23 * V_170 [ type -> V_217 + 1 ] ;
const struct V_403 * V_38 ;
struct V_62 * V_63 ;
int V_43 ;
if ( V_169 ) {
V_43 = F_127 ( V_170 , type -> V_217 , V_169 , type -> V_166 ,
NULL ) ;
if ( V_43 < 0 )
goto V_118;
} else {
memset ( V_170 , 0 , sizeof( V_170 [ 0 ] ) * ( type -> V_217 + 1 ) ) ;
}
if ( type -> V_218 ) {
V_38 = type -> V_218 ( V_14 , ( const struct V_23 * const * ) V_170 ) ;
if ( F_86 ( V_38 ) ) {
V_43 = F_87 ( V_38 ) ;
goto V_118;
}
} else {
V_38 = type -> V_38 ;
}
V_43 = - V_40 ;
V_63 = F_19 ( sizeof( * V_63 ) + V_38 -> V_31 , V_34 ) ;
if ( V_63 == NULL )
goto V_118;
V_43 = V_38 -> V_219 ( V_14 , ( const struct V_23 * const * ) V_170 , V_63 ) ;
if ( V_43 < 0 )
goto V_119;
V_63 -> V_38 = V_38 ;
return V_63 ;
V_119:
F_23 ( V_63 ) ;
V_118:
return F_14 ( V_43 ) ;
}
static int F_271 ( struct V_15 * V_16 , unsigned int V_169 ,
struct V_62 * V_63 , bool V_404 )
{
struct V_23 * V_142 ;
V_142 = F_118 ( V_16 , V_169 ) ;
if ( ! V_142 )
goto V_78;
if ( V_63 -> V_38 -> V_109 ( V_16 , V_63 , V_404 ) < 0 )
goto V_78;
F_121 ( V_16 , V_142 ) ;
return 0 ;
V_78:
return - 1 ;
}
static const struct V_400 * F_272 ( T_1 V_287 )
{
const struct V_400 * type ;
F_10 (type, &nf_tables_objects, list) {
if ( V_287 == type -> type )
return type ;
}
return NULL ;
}
static const struct V_400 * F_273 ( T_1 V_287 )
{
const struct V_400 * type ;
type = F_272 ( V_287 ) ;
if ( type != NULL && F_98 ( type -> V_117 ) )
return type ;
#ifdef F_12
if ( type == NULL ) {
F_5 ( V_5 ) ;
F_13 ( L_6 , V_287 ) ;
F_3 ( V_5 ) ;
if ( F_272 ( V_287 ) )
return F_14 ( - V_11 ) ;
}
#endif
return F_14 ( - V_51 ) ;
}
static int F_274 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
struct V_102 * V_103 )
{
const struct V_76 * V_77 = F_62 ( V_18 ) ;
const struct V_400 * type ;
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
V_63 = F_257 ( V_20 , V_24 [ V_406 ] , V_287 , V_67 ) ;
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
type = F_273 ( V_287 ) ;
if ( F_86 ( type ) )
return F_87 ( type ) ;
V_63 = F_270 ( & V_14 , type , V_24 [ V_407 ] ) ;
if ( F_86 ( V_63 ) ) {
V_43 = F_87 ( V_63 ) ;
goto V_118;
}
V_63 -> V_20 = V_20 ;
V_63 -> V_68 = F_99 ( V_24 [ V_406 ] , V_34 ) ;
if ( ! V_63 -> V_68 ) {
V_43 = - V_40 ;
goto V_119;
}
V_43 = F_48 ( & V_14 , V_65 , V_63 ) ;
if ( V_43 < 0 )
goto V_120;
F_4 ( & V_63 -> V_6 , & V_20 -> V_123 ) ;
V_20 -> V_48 ++ ;
return 0 ;
V_120:
F_23 ( V_63 -> V_68 ) ;
V_119:
if ( V_63 -> V_38 -> V_222 )
V_63 -> V_38 -> V_222 ( V_63 ) ;
F_23 ( V_63 ) ;
V_118:
F_100 ( type -> V_117 ) ;
return V_43 ;
}
static int F_275 ( struct V_15 * V_16 , struct V_1 * V_1 ,
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
F_65 ( V_16 , V_405 , F_66 ( V_63 -> V_38 -> type -> type ) ) ||
F_65 ( V_16 , V_409 , F_66 ( V_63 -> V_48 ) ) ||
F_271 ( V_16 , V_407 , V_63 , V_404 ) )
goto V_78;
F_67 ( V_16 , V_18 ) ;
return 0 ;
V_78:
F_68 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_276 ( struct V_15 * V_16 , struct V_90 * V_91 )
{
const struct V_76 * V_77 = F_62 ( V_91 -> V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
unsigned int V_92 = 0 , V_93 = V_91 -> args [ 0 ] ;
struct V_410 * V_411 = V_91 -> V_210 ;
struct V_1 * V_1 = F_76 ( V_16 -> V_94 ) ;
int V_9 = V_77 -> V_79 ;
struct V_62 * V_63 ;
bool V_404 = false ;
if ( F_277 ( V_91 -> V_18 -> V_412 ) == V_413 )
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
if ( V_411 && V_411 -> V_20 [ 0 ] &&
strcmp ( V_411 -> V_20 , V_20 -> V_68 ) )
goto V_96;
if ( V_411 &&
V_411 -> type != V_315 &&
V_63 -> V_38 -> type -> type != V_411 -> type )
goto V_96;
if ( F_275 ( V_16 , V_1 , F_16 ( V_91 -> V_16 ) . V_25 ,
V_91 -> V_18 -> V_28 ,
V_65 ,
V_97 | V_237 ,
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
static int F_278 ( struct V_90 * V_91 )
{
struct V_410 * V_411 = V_91 -> V_210 ;
F_23 ( V_411 -> V_20 ) ;
F_23 ( V_411 ) ;
return 0 ;
}
static struct V_410 *
F_279 ( const struct V_23 * const V_24 [] )
{
struct V_410 * V_411 ;
V_411 = F_19 ( sizeof( * V_411 ) , V_34 ) ;
if ( ! V_411 )
return F_14 ( - V_40 ) ;
if ( V_24 [ V_408 ] ) {
V_411 -> V_20 = F_99 ( V_24 [ V_408 ] , V_34 ) ;
if ( ! V_411 -> V_20 ) {
F_23 ( V_411 ) ;
return F_14 ( - V_40 ) ;
}
}
if ( V_24 [ V_405 ] )
V_411 -> type = F_41 ( F_42 ( V_24 [ V_405 ] ) ) ;
return V_411 ;
}
static int F_280 ( struct V_1 * V_1 , struct V_100 * V_101 ,
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
. V_109 = F_276 ,
. V_98 = F_278 ,
} ;
if ( V_24 [ V_408 ] ||
V_24 [ V_405 ] ) {
struct V_410 * V_411 ;
V_411 = F_279 ( V_24 ) ;
if ( F_86 ( V_411 ) )
return - V_40 ;
V_108 . V_210 = V_411 ;
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
V_63 = F_257 ( V_20 , V_24 [ V_406 ] , V_287 , V_67 ) ;
if ( F_86 ( V_63 ) )
return F_87 ( V_63 ) ;
V_104 = F_88 ( V_88 , V_34 ) ;
if ( ! V_104 )
return - V_40 ;
if ( F_277 ( V_18 -> V_412 ) == V_413 )
V_404 = true ;
V_43 = F_275 ( V_104 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 , V_65 , 0 ,
V_9 , V_20 , V_63 , V_404 ) ;
if ( V_43 < 0 )
goto V_43;
return F_89 ( V_101 , V_104 , F_16 ( V_16 ) . V_25 ) ;
V_43:
F_72 ( V_104 ) ;
return V_43 ;
}
static void F_281 ( struct V_62 * V_63 )
{
if ( V_63 -> V_38 -> V_222 )
V_63 -> V_38 -> V_222 ( V_63 ) ;
F_100 ( V_63 -> V_38 -> type -> V_117 ) ;
F_23 ( V_63 -> V_68 ) ;
F_23 ( V_63 ) ;
}
static int F_282 ( struct V_1 * V_1 , struct V_100 * V_101 ,
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
V_63 = F_257 ( V_20 , V_24 [ V_406 ] , V_287 , V_67 ) ;
if ( F_86 ( V_63 ) )
return F_87 ( V_63 ) ;
if ( V_63 -> V_48 > 0 )
return - V_134 ;
F_15 ( & V_14 , V_1 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return F_49 ( & V_14 , V_63 ) ;
}
void F_283 ( struct V_1 * V_1 , struct V_19 * V_20 ,
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
V_43 = F_275 ( V_16 , V_1 , V_25 , V_27 , V_75 , 0 , V_9 ,
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
static void F_284 ( const struct V_13 * V_14 ,
struct V_62 * V_63 , int V_75 )
{
F_283 ( V_14 -> V_1 , V_14 -> V_20 , V_63 , V_14 -> V_25 , V_14 -> V_27 , V_75 ,
V_14 -> V_3 -> V_9 , V_14 -> V_26 , V_34 ) ;
}
static int F_285 ( struct V_15 * V_16 , struct V_1 * V_1 ,
T_1 V_25 , T_1 V_27 )
{
struct V_17 * V_18 ;
struct V_76 * V_77 ;
char V_414 [ V_415 ] ;
int V_75 = F_60 ( V_5 , V_416 ) ;
V_18 = F_61 ( V_16 , V_25 , V_27 , V_75 , sizeof( struct V_76 ) , 0 ) ;
if ( V_18 == NULL )
goto V_78;
V_77 = F_62 ( V_18 ) ;
V_77 -> V_79 = V_132 ;
V_77 -> V_80 = V_81 ;
V_77 -> V_82 = F_63 ( V_1 -> V_7 . V_83 & 0xffff ) ;
if ( F_65 ( V_16 , V_417 , F_66 ( V_1 -> V_7 . V_83 ) ) ||
F_65 ( V_16 , V_418 , F_66 ( F_286 ( V_419 ) ) ) ||
F_64 ( V_16 , V_420 , F_287 ( V_414 , V_419 ) ) )
goto V_78;
F_67 ( V_16 , V_18 ) ;
return 0 ;
V_78:
F_68 ( V_16 , V_18 ) ;
return - V_356 ;
}
static void F_288 ( struct V_1 * V_1 , struct V_15 * V_16 ,
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
V_43 = F_285 ( V_104 , V_1 , F_16 ( V_16 ) . V_25 ,
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
static int F_289 ( struct V_1 * V_1 , struct V_100 * V_101 ,
struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
struct V_102 * V_103 )
{
struct V_15 * V_104 ;
int V_43 ;
V_104 = F_88 ( V_88 , V_34 ) ;
if ( V_104 == NULL )
return - V_40 ;
V_43 = F_285 ( V_104 , V_1 , F_16 ( V_16 ) . V_25 ,
V_18 -> V_28 ) ;
if ( V_43 < 0 )
goto V_43;
return F_89 ( V_101 , V_104 , F_16 ( V_16 ) . V_25 ) ;
V_43:
F_72 ( V_104 ) ;
return V_43 ;
}
static void F_290 ( struct V_29 * V_33 )
{
struct F_27 * V_156 ;
if ( F_152 ( V_33 ) )
strcpy ( V_33 -> V_14 . V_22 -> V_68 , F_152 ( V_33 ) ) ;
if ( ! F_25 ( V_33 -> V_14 . V_22 ) )
return;
V_156 = F_27 ( V_33 -> V_14 . V_22 ) ;
F_134 ( V_156 , F_149 ( V_33 ) ) ;
switch ( F_151 ( V_33 ) ) {
case V_204 :
case V_202 :
V_156 -> V_166 = F_151 ( V_33 ) ;
break;
}
}
static void F_291 ( struct V_29 * V_33 )
{
switch ( V_33 -> V_30 ) {
case V_44 :
F_106 ( & V_33 -> V_14 ) ;
break;
case V_47 :
F_139 ( V_33 -> V_14 . V_22 ) ;
break;
case V_55 :
F_177 ( & V_33 -> V_14 , V_52 ( V_33 ) ) ;
break;
case V_61 :
F_213 ( V_58 ( V_33 ) ) ;
break;
case V_391 :
F_250 ( F_245 ( V_33 ) ,
V_364 ( V_33 ) . V_196 ) ;
break;
case V_66 :
F_281 ( V_64 ( V_33 ) ) ;
break;
}
F_23 ( V_33 ) ;
}
static int F_292 ( struct V_1 * V_1 , struct V_15 * V_16 )
{
struct V_29 * V_33 , * V_223 ;
struct V_364 * V_421 ;
while ( ++ V_1 -> V_7 . V_83 == 0 ) ;
V_1 -> V_7 . V_422 = F_293 ( V_1 ) ;
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
F_294 ( V_1 , V_33 -> V_14 . V_20 ) ;
}
F_69 ( & V_33 -> V_14 , V_41 ) ;
F_21 ( V_33 ) ;
break;
case V_44 :
F_8 ( & V_33 -> V_14 . V_20 -> V_6 ) ;
F_69 ( & V_33 -> V_14 , V_44 ) ;
break;
case V_46 :
if ( F_150 ( V_33 ) )
F_290 ( V_33 ) ;
else
F_294 ( V_1 , V_33 -> V_14 . V_22 ) ;
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
F_294 ( V_33 -> V_14 . V_1 , V_52 ( V_33 ) ) ;
F_173 ( & V_33 -> V_14 ,
V_52 ( V_33 ) ,
V_53 ) ;
F_21 ( V_33 ) ;
break;
case V_55 :
F_8 ( & V_52 ( V_33 ) -> V_6 ) ;
F_173 ( & V_33 -> V_14 ,
V_52 ( V_33 ) ,
V_55 ) ;
break;
case V_59 :
F_294 ( V_1 , V_58 ( V_33 ) ) ;
if ( V_58 ( V_33 ) -> V_36 & V_129 &&
! F_103 ( & V_58 ( V_33 ) -> V_130 ) )
V_33 -> V_14 . V_20 -> V_48 -- ;
F_203 ( & V_33 -> V_14 , V_58 ( V_33 ) ,
V_59 , V_34 ) ;
F_21 ( V_33 ) ;
break;
case V_61 :
F_8 ( & V_58 ( V_33 ) -> V_6 ) ;
F_203 ( & V_33 -> V_14 , V_58 ( V_33 ) ,
V_61 , V_34 ) ;
break;
case V_361 :
V_421 = (struct V_364 * ) V_33 -> V_210 ;
V_421 -> V_57 -> V_38 -> V_423 ( V_1 , V_421 -> V_57 , & V_421 -> V_323 ) ;
F_243 ( & V_33 -> V_14 , V_421 -> V_57 ,
& V_421 -> V_323 ,
V_361 , 0 ) ;
F_21 ( V_33 ) ;
break;
case V_391 :
V_421 = (struct V_364 * ) V_33 -> V_210 ;
F_243 ( & V_33 -> V_14 , V_421 -> V_57 ,
& V_421 -> V_323 ,
V_391 , 0 ) ;
V_421 -> V_57 -> V_38 -> remove ( V_1 , V_421 -> V_57 , & V_421 -> V_323 ) ;
F_295 ( & V_421 -> V_57 -> V_319 ) ;
V_421 -> V_57 -> V_383 -- ;
break;
case V_65 :
F_294 ( V_1 , V_64 ( V_33 ) ) ;
F_284 ( & V_33 -> V_14 , V_64 ( V_33 ) ,
V_65 ) ;
F_21 ( V_33 ) ;
break;
case V_66 :
F_8 ( & V_64 ( V_33 ) -> V_6 ) ;
F_284 ( & V_33 -> V_14 , V_64 ( V_33 ) ,
V_66 ) ;
break;
}
}
F_137 () ;
F_102 (trans, next, &net->nft.commit_list, list) {
F_22 ( & V_33 -> V_6 ) ;
F_291 ( V_33 ) ;
}
F_288 ( V_1 , V_16 , V_416 ) ;
return 0 ;
}
static void F_296 ( struct V_29 * V_33 )
{
switch ( V_33 -> V_30 ) {
case V_41 :
F_106 ( & V_33 -> V_14 ) ;
break;
case V_46 :
F_139 ( V_33 -> V_14 . V_22 ) ;
break;
case V_53 :
F_177 ( & V_33 -> V_14 , V_52 ( V_33 ) ) ;
break;
case V_59 :
F_213 ( V_58 ( V_33 ) ) ;
break;
case V_361 :
F_248 ( F_245 ( V_33 ) ,
V_364 ( V_33 ) . V_196 , true ) ;
break;
case V_65 :
F_281 ( V_64 ( V_33 ) ) ;
break;
}
F_23 ( V_33 ) ;
}
static int F_297 ( struct V_1 * V_1 , struct V_15 * V_16 )
{
struct V_29 * V_33 , * V_223 ;
struct V_364 * V_421 ;
F_298 (trans, next, &net->nft.commit_list,
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
F_294 ( V_33 -> V_14 . V_1 , V_33 -> V_14 . V_20 ) ;
F_21 ( V_33 ) ;
break;
case V_46 :
if ( F_150 ( V_33 ) ) {
F_138 ( F_149 ( V_33 ) ) ;
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
F_294 ( V_33 -> V_14 . V_1 , V_33 -> V_14 . V_22 ) ;
F_21 ( V_33 ) ;
break;
case V_53 :
V_33 -> V_14 . V_22 -> V_48 -- ;
F_8 ( & V_52 ( V_33 ) -> V_6 ) ;
break;
case V_55 :
V_33 -> V_14 . V_22 -> V_48 ++ ;
F_294 ( V_33 -> V_14 . V_1 , V_52 ( V_33 ) ) ;
F_21 ( V_33 ) ;
break;
case V_59 :
V_33 -> V_14 . V_20 -> V_48 -- ;
F_8 ( & V_58 ( V_33 ) -> V_6 ) ;
break;
case V_61 :
V_33 -> V_14 . V_20 -> V_48 ++ ;
F_294 ( V_33 -> V_14 . V_1 , V_58 ( V_33 ) ) ;
F_21 ( V_33 ) ;
break;
case V_361 :
V_421 = (struct V_364 * ) V_33 -> V_210 ;
V_421 -> V_57 -> V_38 -> remove ( V_1 , V_421 -> V_57 , & V_421 -> V_323 ) ;
F_295 ( & V_421 -> V_57 -> V_319 ) ;
break;
case V_391 :
V_421 = (struct V_364 * ) V_33 -> V_210 ;
F_261 ( V_1 , V_421 -> V_57 , & V_421 -> V_323 ) ;
V_421 -> V_57 -> V_38 -> V_423 ( V_1 , V_421 -> V_57 , & V_421 -> V_323 ) ;
V_421 -> V_57 -> V_383 -- ;
F_21 ( V_33 ) ;
break;
case V_65 :
V_33 -> V_14 . V_20 -> V_48 -- ;
F_8 ( & V_64 ( V_33 ) -> V_6 ) ;
break;
case V_66 :
V_33 -> V_14 . V_20 -> V_48 ++ ;
F_294 ( V_33 -> V_14 . V_1 , V_64 ( V_33 ) ) ;
F_21 ( V_33 ) ;
break;
}
}
F_137 () ;
F_298 (trans, next,
&net->nft.commit_list, list) {
F_22 ( & V_33 -> V_6 ) ;
F_296 ( V_33 ) ;
}
return 0 ;
}
static bool F_299 ( struct V_1 * V_1 , T_1 V_424 )
{
return V_1 -> V_7 . V_83 == V_424 ;
}
int F_300 ( const struct V_21 * V_22 ,
enum V_425 type )
{
const struct F_27 * V_156 ;
if ( F_25 ( V_22 ) ) {
V_156 = F_27 ( V_22 ) ;
if ( V_156 -> type -> type != type )
return - V_116 ;
}
return 0 ;
}
int F_301 ( const struct V_21 * V_22 ,
unsigned int V_426 )
{
struct F_27 * V_156 ;
if ( F_25 ( V_22 ) ) {
V_156 = F_27 ( V_22 ) ;
if ( ( 1 << V_156 -> V_38 [ 0 ] . V_160 ) & V_426 )
return 0 ;
return - V_116 ;
}
return 0 ;
}
static int F_302 ( const struct V_13 * V_14 ,
struct V_56 * V_57 ,
const struct V_320 * V_321 ,
struct V_322 * V_323 )
{
const struct V_324 * V_325 = F_218 ( V_57 , V_323 -> V_196 ) ;
const struct V_221 * V_210 ;
if ( F_229 ( V_325 , V_344 ) &&
* F_232 ( V_325 ) & V_370 )
return 0 ;
V_210 = F_221 ( V_325 ) ;
switch ( V_210 -> V_387 . V_388 ) {
case V_389 :
case V_390 :
return F_303 ( V_14 , V_210 -> V_387 . V_22 ) ;
default:
return 0 ;
}
}
static int F_303 ( const struct V_13 * V_14 ,
const struct V_21 * V_22 )
{
const struct V_49 * V_50 ;
const struct V_207 * V_208 , * V_427 ;
struct V_56 * V_57 ;
struct V_328 * V_329 ;
struct V_320 V_321 ;
if ( V_14 -> V_22 == V_22 )
return - V_428 ;
F_10 (rule, &chain->rules, list) {
F_171 (expr, last, rule) {
const struct V_221 * V_210 = NULL ;
int V_43 ;
if ( ! V_208 -> V_38 -> V_220 )
continue;
V_43 = V_208 -> V_38 -> V_220 ( V_14 , V_208 , & V_210 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_210 == NULL )
continue;
switch ( V_210 -> V_387 . V_388 ) {
case V_389 :
case V_390 :
V_43 = F_303 ( V_14 ,
V_210 -> V_387 . V_22 ) ;
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
if ( ! ( V_329 -> V_36 & V_281 ) ||
V_329 -> V_22 != V_22 )
continue;
V_321 . V_67 = F_97 ( V_14 -> V_1 ) ;
V_321 . V_331 = 0 ;
V_321 . V_332 = 0 ;
V_321 . V_43 = 0 ;
V_321 . V_333 = F_302 ;
V_57 -> V_38 -> V_334 ( V_14 , V_57 , & V_321 ) ;
if ( V_321 . V_43 < 0 )
return V_321 . V_43 ;
}
}
return 0 ;
}
int F_304 ( const struct V_23 * V_169 , int V_429 , T_1 * V_430 )
{
T_1 V_377 ;
V_377 = F_41 ( F_42 ( V_169 ) ) ;
if ( V_377 > V_429 )
return - V_431 ;
* V_430 = V_377 ;
return 0 ;
}
unsigned int F_305 ( const struct V_23 * V_169 )
{
unsigned int V_432 ;
V_432 = F_41 ( F_42 ( V_169 ) ) ;
switch ( V_432 ) {
case V_433 ... V_434 :
return V_432 * V_435 / V_436 ;
default:
return V_432 + V_435 / V_436 - V_437 ;
}
}
int F_306 ( struct V_15 * V_16 , unsigned int V_169 , unsigned int V_432 )
{
if ( V_432 % ( V_435 / V_436 ) == 0 )
V_432 = V_432 / ( V_435 / V_436 ) ;
else
V_432 = V_432 - V_435 / V_436 + V_437 ;
return F_65 ( V_16 , V_169 , F_66 ( V_432 ) ) ;
}
int F_307 ( enum V_326 V_432 , unsigned int V_99 )
{
if ( V_432 < V_438 * V_435 / V_436 )
return - V_69 ;
if ( V_99 == 0 )
return - V_69 ;
if ( V_432 * V_436 + V_99 > F_308 ( struct V_439 , V_210 ) )
return - V_431 ;
return 0 ;
}
int F_220 ( const struct V_13 * V_14 ,
enum V_326 V_432 ,
const struct V_221 * V_210 ,
enum V_386 type , unsigned int V_99 )
{
int V_43 ;
switch ( V_432 ) {
case V_433 :
if ( type != V_313 )
return - V_69 ;
if ( V_210 != NULL &&
( V_210 -> V_387 . V_388 == V_390 ||
V_210 -> V_387 . V_388 == V_389 ) ) {
V_43 = F_303 ( V_14 , V_210 -> V_387 . V_22 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_14 -> V_22 -> V_440 + 1 >
V_210 -> V_387 . V_22 -> V_440 ) {
if ( V_14 -> V_22 -> V_440 + 1 == V_441 )
return - V_442 ;
V_210 -> V_387 . V_22 -> V_440 = V_14 -> V_22 -> V_440 + 1 ;
}
}
return 0 ;
default:
if ( V_432 < V_438 * V_435 / V_436 )
return - V_69 ;
if ( V_99 == 0 )
return - V_69 ;
if ( V_432 * V_436 + V_99 >
F_308 ( struct V_439 , V_210 ) )
return - V_431 ;
if ( V_210 != NULL && type != V_306 )
return - V_69 ;
return 0 ;
}
}
static int F_309 ( const struct V_13 * V_14 , struct V_221 * V_210 ,
struct V_372 * V_255 , const struct V_23 * V_24 )
{
T_3 V_67 = F_97 ( V_14 -> V_1 ) ;
struct V_23 * V_170 [ V_443 + 1 ] ;
struct V_21 * V_22 ;
int V_43 ;
V_43 = F_127 ( V_170 , V_443 , V_24 , V_444 ,
NULL ) ;
if ( V_43 < 0 )
return V_43 ;
if ( ! V_170 [ V_445 ] )
return - V_69 ;
V_210 -> V_387 . V_388 = F_41 ( F_42 ( V_170 [ V_445 ] ) ) ;
switch ( V_210 -> V_387 . V_388 ) {
default:
switch ( V_210 -> V_387 . V_388 & V_446 ) {
case V_202 :
case V_204 :
case V_447 :
break;
default:
return - V_69 ;
}
case V_448 :
case V_449 :
case V_450 :
break;
case V_389 :
case V_390 :
if ( ! V_170 [ V_451 ] )
return - V_69 ;
V_22 = F_112 ( V_14 -> V_20 ,
V_170 [ V_451 ] , V_67 ) ;
if ( F_86 ( V_22 ) )
return F_87 ( V_22 ) ;
if ( F_25 ( V_22 ) )
return - V_116 ;
V_22 -> V_48 ++ ;
V_210 -> V_387 . V_22 = V_22 ;
break;
}
V_255 -> V_99 = sizeof( V_210 -> V_387 ) ;
V_255 -> type = V_313 ;
return 0 ;
}
static void F_310 ( const struct V_221 * V_210 )
{
switch ( V_210 -> V_387 . V_388 ) {
case V_389 :
case V_390 :
V_210 -> V_387 . V_22 -> V_48 -- ;
break;
}
}
int F_311 ( struct V_15 * V_16 , int type , const struct V_314 * V_452 )
{
struct V_23 * V_142 ;
V_142 = F_118 ( V_16 , type ) ;
if ( ! V_142 )
goto V_78;
if ( F_65 ( V_16 , V_445 , F_66 ( V_452 -> V_388 ) ) )
goto V_78;
switch ( V_452 -> V_388 ) {
case V_389 :
case V_390 :
if ( F_64 ( V_16 , V_451 ,
V_452 -> V_22 -> V_68 ) )
goto V_78;
}
F_121 ( V_16 , V_142 ) ;
return 0 ;
V_78:
return - 1 ;
}
static int F_312 ( const struct V_13 * V_14 ,
struct V_221 * V_210 , unsigned int V_31 ,
struct V_372 * V_255 , const struct V_23 * V_24 )
{
unsigned int V_99 ;
V_99 = F_57 ( V_24 ) ;
if ( V_99 == 0 )
return - V_69 ;
if ( V_99 > V_31 )
return - V_192 ;
F_184 ( V_210 -> V_210 , V_24 , V_99 ) ;
V_255 -> type = V_306 ;
V_255 -> V_99 = V_99 ;
return 0 ;
}
static int F_313 ( struct V_15 * V_16 , const struct V_221 * V_210 ,
unsigned int V_99 )
{
return F_172 ( V_16 , V_453 , V_99 , V_210 -> V_210 ) ;
}
int F_255 ( const struct V_13 * V_14 ,
struct V_221 * V_210 , unsigned int V_31 ,
struct V_372 * V_255 , const struct V_23 * V_24 )
{
struct V_23 * V_170 [ V_454 + 1 ] ;
int V_43 ;
V_43 = F_127 ( V_170 , V_454 , V_24 , V_455 , NULL ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_170 [ V_453 ] )
return F_312 ( V_14 , V_210 , V_31 , V_255 ,
V_170 [ V_453 ] ) ;
if ( V_170 [ V_456 ] && V_14 != NULL )
return F_309 ( V_14 , V_210 , V_255 , V_170 [ V_456 ] ) ;
return - V_69 ;
}
void F_249 ( const struct V_221 * V_210 , enum V_386 type )
{
if ( type < V_313 )
return;
switch ( type ) {
case V_313 :
return F_310 ( V_210 ) ;
default:
F_109 ( 1 ) ;
}
}
int F_227 ( struct V_15 * V_16 , int V_169 , const struct V_221 * V_210 ,
enum V_386 type , unsigned int V_99 )
{
struct V_23 * V_142 ;
int V_43 ;
V_142 = F_118 ( V_16 , V_169 ) ;
if ( V_142 == NULL )
return - 1 ;
switch ( type ) {
case V_306 :
V_43 = F_313 ( V_16 , V_210 , V_99 ) ;
break;
case V_313 :
V_43 = F_311 ( V_16 , V_456 , & V_210 -> V_387 ) ;
break;
default:
V_43 = - V_69 ;
F_109 ( 1 ) ;
}
F_121 ( V_16 , V_142 ) ;
return V_43 ;
}
static int T_8 F_314 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_7 . V_8 ) ;
F_2 ( & V_1 -> V_7 . V_42 ) ;
V_1 -> V_7 . V_83 = 1 ;
return 0 ;
}
int F_315 ( struct V_13 * V_14 )
{
struct V_49 * V_50 , * V_457 ;
F_107 ( ! F_25 ( V_14 -> V_22 ) ) ;
F_28 ( V_14 -> V_1 , V_14 -> V_22 -> V_20 , V_14 -> V_22 ,
V_14 -> V_3 -> V_111 ) ;
F_102 (rule, nr, &ctx->chain->rules, list) {
F_22 ( & V_50 -> V_6 ) ;
V_14 -> V_22 -> V_48 -- ;
F_177 ( V_14 , V_50 ) ;
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
struct V_49 * V_50 , * V_457 ;
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
F_177 ( & V_14 , V_50 ) ;
}
}
F_102 (set, ns, &table->sets, list) {
F_22 ( & V_57 -> V_6 ) ;
V_20 -> V_48 -- ;
F_213 ( V_57 ) ;
}
F_102 (obj, ne, &table->objects, list) {
F_22 ( & V_63 -> V_6 ) ;
V_20 -> V_48 -- ;
F_281 ( V_63 ) ;
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
static int T_9 F_316 ( void )
{
int V_43 ;
V_213 = F_207 ( sizeof( struct V_212 ) * V_245 ,
V_34 ) ;
if ( V_213 == NULL ) {
V_43 = - V_40 ;
goto V_118;
}
V_43 = F_317 () ;
if ( V_43 < 0 )
goto V_119;
V_43 = F_318 ( & V_458 ) ;
if ( V_43 < 0 )
goto V_120;
F_319 ( L_7 ) ;
return F_320 ( & V_459 ) ;
V_120:
F_321 () ;
V_119:
F_23 ( V_213 ) ;
V_118:
return V_43 ;
}
static void T_10 F_322 ( void )
{
F_323 ( & V_459 ) ;
F_324 ( & V_458 ) ;
F_325 () ;
F_321 () ;
F_23 ( V_213 ) ;
}
