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
static struct V_13 * F_14 ( const struct V_2 * V_3 ,
const struct V_14 * V_15 )
{
struct V_13 * V_16 ;
F_9 (table, &afi->tables, list) {
if ( ! F_15 ( V_15 , V_16 -> V_17 ) )
return V_16 ;
}
return NULL ;
}
static struct V_13 * F_16 ( const struct V_2 * V_3 ,
const struct V_14 * V_15 )
{
struct V_13 * V_16 ;
if ( V_15 == NULL )
return F_13 ( - V_18 ) ;
V_16 = F_14 ( V_3 , V_15 ) ;
if ( V_16 != NULL )
return V_16 ;
return F_13 ( - V_19 ) ;
}
static inline T_1 F_17 ( struct V_13 * V_16 )
{
return ++ V_16 -> V_20 ;
}
static const struct V_21 *
F_18 ( int V_9 , const struct V_14 * V_15 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
if ( V_24 [ V_9 ] [ V_22 ] != NULL &&
! F_15 ( V_15 , V_24 [ V_9 ] [ V_22 ] -> V_17 ) )
return V_24 [ V_9 ] [ V_22 ] ;
}
return NULL ;
}
static const struct V_21 *
F_19 ( const struct V_2 * V_3 ,
const struct V_14 * V_15 ,
bool V_10 )
{
const struct V_21 * type ;
type = F_18 ( V_3 -> V_9 , V_15 ) ;
if ( type != NULL )
return type ;
#ifdef F_11
if ( V_10 ) {
F_5 ( V_5 ) ;
F_12 ( L_2 , V_3 -> V_9 ,
F_20 ( V_15 ) , ( const char * ) F_21 ( V_15 ) ) ;
F_3 ( V_5 ) ;
type = F_18 ( V_3 -> V_9 , V_15 ) ;
if ( type != NULL )
return F_13 ( - V_11 ) ;
}
#endif
return F_13 ( - V_19 ) ;
}
static int F_22 ( struct V_25 * V_26 , T_2 V_27 , T_2 V_28 ,
int V_29 , T_2 V_30 , int V_9 ,
const struct V_13 * V_16 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 ;
V_29 |= V_5 << 8 ;
V_32 = F_23 ( V_26 , V_27 , V_28 , V_29 , sizeof( struct V_33 ) , V_30 ) ;
if ( V_32 == NULL )
goto V_35;
V_34 = F_24 ( V_32 ) ;
V_34 -> V_36 = V_9 ;
V_34 -> V_37 = V_38 ;
V_34 -> V_39 = 0 ;
if ( F_25 ( V_26 , V_40 , V_16 -> V_17 ) ||
F_26 ( V_26 , V_41 , F_27 ( V_16 -> V_30 ) ) ||
F_26 ( V_26 , V_42 , F_27 ( V_16 -> V_43 ) ) )
goto V_35;
return F_28 ( V_26 , V_32 ) ;
V_35:
F_29 ( V_26 , V_32 ) ;
return - 1 ;
}
static int F_30 ( const struct V_25 * V_44 ,
const struct V_31 * V_32 ,
const struct V_13 * V_16 ,
int V_29 , int V_9 )
{
struct V_25 * V_26 ;
T_2 V_27 = V_44 ? F_31 ( V_44 ) . V_27 : 0 ;
T_2 V_28 = V_32 ? V_32 -> V_45 : 0 ;
struct V_1 * V_1 = V_44 ? F_32 ( V_44 -> V_46 ) : & V_47 ;
bool V_48 ;
int V_49 ;
V_48 = V_32 ? F_33 ( V_32 ) : false ;
if ( ! V_48 && ! F_34 ( V_1 , V_50 ) )
return 0 ;
V_49 = - V_51 ;
V_26 = F_35 ( V_52 , V_53 ) ;
if ( V_26 == NULL )
goto V_49;
V_49 = F_22 ( V_26 , V_27 , V_28 , V_29 , 0 ,
V_9 , V_16 ) ;
if ( V_49 < 0 ) {
F_36 ( V_26 ) ;
goto V_49;
}
V_49 = F_37 ( V_26 , V_1 , V_27 , V_50 , V_48 ,
V_53 ) ;
V_49:
if ( V_49 < 0 )
F_38 ( V_1 , V_27 , V_50 , V_49 ) ;
return V_49 ;
}
static int F_39 ( struct V_25 * V_26 ,
struct V_54 * V_55 )
{
const struct V_33 * V_34 = F_24 ( V_55 -> V_32 ) ;
const struct V_2 * V_3 ;
const struct V_13 * V_16 ;
unsigned int V_56 = 0 , V_57 = V_55 -> args [ 0 ] ;
struct V_1 * V_1 = F_32 ( V_26 -> V_46 ) ;
int V_9 = V_34 -> V_36 ;
F_9 (afi, &net->nft.af_info, list) {
if ( V_9 != V_58 && V_9 != V_3 -> V_9 )
continue;
F_9 (table, &afi->tables, list) {
if ( V_56 < V_57 )
goto V_59;
if ( V_56 > V_57 )
memset ( & V_55 -> args [ 1 ] , 0 ,
sizeof( V_55 -> args ) - sizeof( V_55 -> args [ 0 ] ) ) ;
if ( F_22 ( V_26 ,
F_31 ( V_55 -> V_26 ) . V_27 ,
V_55 -> V_32 -> V_45 ,
V_60 ,
V_61 ,
V_3 -> V_9 , V_16 ) < 0 )
goto V_62;
V_59:
V_56 ++ ;
}
}
V_62:
V_55 -> args [ 0 ] = V_56 ;
return V_26 -> V_63 ;
}
static int F_40 ( struct V_64 * V_65 , struct V_25 * V_26 ,
const struct V_31 * V_32 ,
const struct V_14 * const V_15 [] )
{
const struct V_33 * V_34 = F_24 ( V_32 ) ;
const struct V_2 * V_3 ;
const struct V_13 * V_16 ;
struct V_25 * V_66 ;
struct V_1 * V_1 = F_32 ( V_26 -> V_46 ) ;
int V_9 = V_34 -> V_36 ;
int V_49 ;
if ( V_32 -> V_67 & V_68 ) {
struct V_69 V_70 = {
. V_71 = F_39 ,
} ;
return F_41 ( V_65 , V_26 , V_32 , & V_70 ) ;
}
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_42 ( V_3 ) )
return F_43 ( V_3 ) ;
V_16 = F_16 ( V_3 , V_15 [ V_40 ] ) ;
if ( F_42 ( V_16 ) )
return F_43 ( V_16 ) ;
V_66 = F_44 ( V_52 , V_53 ) ;
if ( ! V_66 )
return - V_72 ;
V_49 = F_22 ( V_66 , F_31 ( V_26 ) . V_27 ,
V_32 -> V_45 , V_60 , 0 ,
V_9 , V_16 ) ;
if ( V_49 < 0 )
goto V_49;
return F_45 ( V_65 , V_66 , F_31 ( V_26 ) . V_27 ) ;
V_49:
F_36 ( V_66 ) ;
return V_49 ;
}
static int F_46 ( const struct V_2 * V_3 ,
struct V_13 * V_16 )
{
struct V_73 * V_74 ;
int V_49 , V_22 = 0 ;
F_9 (chain, &table->chains, list) {
if ( ! ( V_74 -> V_30 & V_75 ) )
continue;
V_49 = F_47 ( F_48 ( V_74 ) -> V_76 , V_3 -> V_77 ) ;
if ( V_49 < 0 )
goto V_49;
V_22 ++ ;
}
return 0 ;
V_49:
F_9 (chain, &table->chains, list) {
if ( ! ( V_74 -> V_30 & V_75 ) )
continue;
if ( V_22 -- <= 0 )
break;
F_49 ( F_48 ( V_74 ) -> V_76 , V_3 -> V_77 ) ;
}
return V_49 ;
}
static int F_50 ( const struct V_2 * V_3 ,
struct V_13 * V_16 )
{
struct V_73 * V_74 ;
F_9 (chain, &table->chains, list) {
if ( V_74 -> V_30 & V_75 )
F_49 ( F_48 ( V_74 ) -> V_76 ,
V_3 -> V_77 ) ;
}
return 0 ;
}
static int F_51 ( struct V_64 * V_65 , struct V_25 * V_26 ,
const struct V_31 * V_32 ,
const struct V_14 * const V_15 [] ,
struct V_2 * V_3 , struct V_13 * V_16 )
{
const struct V_33 * V_34 = F_24 ( V_32 ) ;
int V_9 = V_34 -> V_36 , V_78 = 0 ;
if ( V_15 [ V_41 ] ) {
T_2 V_30 ;
V_30 = F_52 ( F_53 ( V_15 [ V_41 ] ) ) ;
if ( V_30 & ~ V_79 )
return - V_18 ;
if ( ( V_30 & V_79 ) &&
! ( V_16 -> V_30 & V_79 ) ) {
V_78 = F_50 ( V_3 , V_16 ) ;
if ( V_78 >= 0 )
V_16 -> V_30 |= V_79 ;
} else if ( ! ( V_30 & V_79 ) &&
V_16 -> V_30 & V_79 ) {
V_78 = F_46 ( V_3 , V_16 ) ;
if ( V_78 >= 0 )
V_16 -> V_30 &= ~ V_79 ;
}
if ( V_78 < 0 )
goto V_49;
}
F_30 ( V_26 , V_32 , V_16 , V_60 , V_9 ) ;
V_49:
return V_78 ;
}
static int F_54 ( struct V_64 * V_65 , struct V_25 * V_26 ,
const struct V_31 * V_32 ,
const struct V_14 * const V_15 [] )
{
const struct V_33 * V_34 = F_24 ( V_32 ) ;
const struct V_14 * V_17 ;
struct V_2 * V_3 ;
struct V_13 * V_16 ;
struct V_1 * V_1 = F_32 ( V_26 -> V_46 ) ;
int V_9 = V_34 -> V_36 ;
T_2 V_30 = 0 ;
V_3 = F_10 ( V_1 , V_9 , true ) ;
if ( F_42 ( V_3 ) )
return F_43 ( V_3 ) ;
V_17 = V_15 [ V_40 ] ;
V_16 = F_16 ( V_3 , V_17 ) ;
if ( F_42 ( V_16 ) ) {
if ( F_43 ( V_16 ) != - V_19 )
return F_43 ( V_16 ) ;
V_16 = NULL ;
}
if ( V_16 != NULL ) {
if ( V_32 -> V_67 & V_80 )
return - V_81 ;
if ( V_32 -> V_67 & V_82 )
return - V_83 ;
return F_51 ( V_65 , V_26 , V_32 , V_15 , V_3 , V_16 ) ;
}
if ( V_15 [ V_41 ] ) {
V_30 = F_52 ( F_53 ( V_15 [ V_41 ] ) ) ;
if ( V_30 & ~ V_79 )
return - V_18 ;
}
if ( ! F_55 ( V_3 -> V_84 ) )
return - V_12 ;
V_16 = F_56 ( sizeof( * V_16 ) + F_20 ( V_17 ) , V_53 ) ;
if ( V_16 == NULL ) {
F_57 ( V_3 -> V_84 ) ;
return - V_72 ;
}
F_58 ( V_16 -> V_17 , V_17 , F_20 ( V_17 ) ) ;
F_2 ( & V_16 -> V_85 ) ;
F_2 ( & V_16 -> V_86 ) ;
V_16 -> V_30 = V_30 ;
F_4 ( & V_16 -> V_6 , & V_3 -> V_4 ) ;
F_30 ( V_26 , V_32 , V_16 , V_60 , V_9 ) ;
return 0 ;
}
static int F_59 ( struct V_64 * V_65 , struct V_25 * V_26 ,
const struct V_31 * V_32 ,
const struct V_14 * const V_15 [] )
{
const struct V_33 * V_34 = F_24 ( V_32 ) ;
struct V_2 * V_3 ;
struct V_13 * V_16 ;
struct V_1 * V_1 = F_32 ( V_26 -> V_46 ) ;
int V_9 = V_34 -> V_36 ;
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_42 ( V_3 ) )
return F_43 ( V_3 ) ;
V_16 = F_16 ( V_3 , V_15 [ V_40 ] ) ;
if ( F_42 ( V_16 ) )
return F_43 ( V_16 ) ;
if ( ! F_60 ( & V_16 -> V_85 ) || ! F_60 ( & V_16 -> V_86 ) )
return - V_87 ;
F_7 ( & V_16 -> V_6 ) ;
F_30 ( V_26 , V_32 , V_16 , V_88 , V_9 ) ;
F_61 ( V_16 ) ;
F_57 ( V_3 -> V_84 ) ;
return 0 ;
}
int F_62 ( const struct V_21 * V_89 )
{
int V_49 = 0 ;
F_3 ( V_5 ) ;
if ( V_24 [ V_89 -> V_9 ] [ V_89 -> type ] != NULL ) {
V_49 = - V_87 ;
goto V_90;
}
V_24 [ V_89 -> V_9 ] [ V_89 -> type ] = V_89 ;
V_90:
F_5 ( V_5 ) ;
return V_49 ;
}
void F_63 ( const struct V_21 * V_89 )
{
F_3 ( V_5 ) ;
V_24 [ V_89 -> V_9 ] [ V_89 -> type ] = NULL ;
F_5 ( V_5 ) ;
}
static struct V_73 *
F_64 ( const struct V_13 * V_16 , T_1 V_91 )
{
struct V_73 * V_74 ;
F_9 (chain, &table->chains, list) {
if ( V_74 -> V_91 == V_91 )
return V_74 ;
}
return F_13 ( - V_19 ) ;
}
static struct V_73 * F_65 ( const struct V_13 * V_16 ,
const struct V_14 * V_15 )
{
struct V_73 * V_74 ;
if ( V_15 == NULL )
return F_13 ( - V_18 ) ;
F_9 (chain, &table->chains, list) {
if ( ! F_15 ( V_15 , V_74 -> V_17 ) )
return V_74 ;
}
return F_13 ( - V_19 ) ;
}
static int F_66 ( struct V_25 * V_26 , struct V_92 T_3 * V_93 )
{
struct V_92 * V_94 , V_95 ;
struct V_14 * V_96 ;
int V_97 ;
memset ( & V_95 , 0 , sizeof( V_95 ) ) ;
F_67 (cpu) {
V_94 = F_68 ( V_93 , V_97 ) ;
V_95 . V_98 += V_94 -> V_98 ;
V_95 . V_99 += V_94 -> V_99 ;
}
V_96 = F_69 ( V_26 , V_100 ) ;
if ( V_96 == NULL )
goto V_35;
if ( F_70 ( V_26 , V_101 , F_71 ( V_95 . V_98 ) ) ||
F_70 ( V_26 , V_102 , F_71 ( V_95 . V_99 ) ) )
goto V_35;
F_72 ( V_26 , V_96 ) ;
return 0 ;
V_35:
return - V_103 ;
}
static int F_73 ( struct V_25 * V_26 , T_2 V_27 , T_2 V_28 ,
int V_29 , T_2 V_30 , int V_9 ,
const struct V_13 * V_16 ,
const struct V_73 * V_74 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 ;
V_29 |= V_5 << 8 ;
V_32 = F_23 ( V_26 , V_27 , V_28 , V_29 , sizeof( struct V_33 ) , V_30 ) ;
if ( V_32 == NULL )
goto V_35;
V_34 = F_24 ( V_32 ) ;
V_34 -> V_36 = V_9 ;
V_34 -> V_37 = V_38 ;
V_34 -> V_39 = 0 ;
if ( F_25 ( V_26 , V_104 , V_16 -> V_17 ) )
goto V_35;
if ( F_70 ( V_26 , V_105 , F_71 ( V_74 -> V_91 ) ) )
goto V_35;
if ( F_25 ( V_26 , V_106 , V_74 -> V_17 ) )
goto V_35;
if ( V_74 -> V_30 & V_75 ) {
const struct F_48 * V_107 = F_48 ( V_74 ) ;
const struct V_108 * V_76 = & V_107 -> V_76 [ 0 ] ;
struct V_14 * V_96 ;
V_96 = F_69 ( V_26 , V_109 ) ;
if ( V_96 == NULL )
goto V_35;
if ( F_26 ( V_26 , V_110 , F_27 ( V_76 -> V_111 ) ) )
goto V_35;
if ( F_26 ( V_26 , V_112 , F_27 ( V_76 -> V_113 ) ) )
goto V_35;
F_72 ( V_26 , V_96 ) ;
if ( F_26 ( V_26 , V_114 ,
F_27 ( V_107 -> V_115 ) ) )
goto V_35;
if ( F_25 ( V_26 , V_116 , V_107 -> type -> V_17 ) )
goto V_35;
if ( F_66 ( V_26 , F_48 ( V_74 ) -> V_93 ) )
goto V_35;
}
if ( F_26 ( V_26 , V_117 , F_27 ( V_74 -> V_43 ) ) )
goto V_35;
return F_28 ( V_26 , V_32 ) ;
V_35:
F_29 ( V_26 , V_32 ) ;
return - 1 ;
}
static int F_74 ( const struct V_25 * V_44 ,
const struct V_31 * V_32 ,
const struct V_13 * V_16 ,
const struct V_73 * V_74 ,
int V_29 , int V_9 )
{
struct V_25 * V_26 ;
T_2 V_27 = V_44 ? F_31 ( V_44 ) . V_27 : 0 ;
struct V_1 * V_1 = V_44 ? F_32 ( V_44 -> V_46 ) : & V_47 ;
T_2 V_28 = V_32 ? V_32 -> V_45 : 0 ;
bool V_48 ;
int V_49 ;
V_48 = V_32 ? F_33 ( V_32 ) : false ;
if ( ! V_48 && ! F_34 ( V_1 , V_50 ) )
return 0 ;
V_49 = - V_51 ;
V_26 = F_35 ( V_52 , V_53 ) ;
if ( V_26 == NULL )
goto V_49;
V_49 = F_73 ( V_26 , V_27 , V_28 , V_29 , 0 , V_9 ,
V_16 , V_74 ) ;
if ( V_49 < 0 ) {
F_36 ( V_26 ) ;
goto V_49;
}
V_49 = F_37 ( V_26 , V_1 , V_27 , V_50 , V_48 ,
V_53 ) ;
V_49:
if ( V_49 < 0 )
F_38 ( V_1 , V_27 , V_50 , V_49 ) ;
return V_49 ;
}
static int F_75 ( struct V_25 * V_26 ,
struct V_54 * V_55 )
{
const struct V_33 * V_34 = F_24 ( V_55 -> V_32 ) ;
const struct V_2 * V_3 ;
const struct V_13 * V_16 ;
const struct V_73 * V_74 ;
unsigned int V_56 = 0 , V_57 = V_55 -> args [ 0 ] ;
struct V_1 * V_1 = F_32 ( V_26 -> V_46 ) ;
int V_9 = V_34 -> V_36 ;
F_9 (afi, &net->nft.af_info, list) {
if ( V_9 != V_58 && V_9 != V_3 -> V_9 )
continue;
F_9 (table, &afi->tables, list) {
F_9 (chain, &table->chains, list) {
if ( V_56 < V_57 )
goto V_59;
if ( V_56 > V_57 )
memset ( & V_55 -> args [ 1 ] , 0 ,
sizeof( V_55 -> args ) - sizeof( V_55 -> args [ 0 ] ) ) ;
if ( F_73 ( V_26 , F_31 ( V_55 -> V_26 ) . V_27 ,
V_55 -> V_32 -> V_45 ,
V_118 ,
V_61 ,
V_3 -> V_9 , V_16 , V_74 ) < 0 )
goto V_62;
V_59:
V_56 ++ ;
}
}
}
V_62:
V_55 -> args [ 0 ] = V_56 ;
return V_26 -> V_63 ;
}
static int F_76 ( struct V_64 * V_65 , struct V_25 * V_26 ,
const struct V_31 * V_32 ,
const struct V_14 * const V_15 [] )
{
const struct V_33 * V_34 = F_24 ( V_32 ) ;
const struct V_2 * V_3 ;
const struct V_13 * V_16 ;
const struct V_73 * V_74 ;
struct V_25 * V_66 ;
struct V_1 * V_1 = F_32 ( V_26 -> V_46 ) ;
int V_9 = V_34 -> V_36 ;
int V_49 ;
if ( V_32 -> V_67 & V_68 ) {
struct V_69 V_70 = {
. V_71 = F_75 ,
} ;
return F_41 ( V_65 , V_26 , V_32 , & V_70 ) ;
}
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_42 ( V_3 ) )
return F_43 ( V_3 ) ;
V_16 = F_16 ( V_3 , V_15 [ V_104 ] ) ;
if ( F_42 ( V_16 ) )
return F_43 ( V_16 ) ;
V_74 = F_65 ( V_16 , V_15 [ V_106 ] ) ;
if ( F_42 ( V_74 ) )
return F_43 ( V_74 ) ;
V_66 = F_44 ( V_52 , V_53 ) ;
if ( ! V_66 )
return - V_72 ;
V_49 = F_73 ( V_66 , F_31 ( V_26 ) . V_27 ,
V_32 -> V_45 , V_118 , 0 ,
V_9 , V_16 , V_74 ) ;
if ( V_49 < 0 )
goto V_49;
return F_45 ( V_65 , V_66 , F_31 ( V_26 ) . V_27 ) ;
V_49:
F_36 ( V_66 ) ;
return V_49 ;
}
static int
F_77 ( struct F_48 * V_74 , const struct V_14 * V_119 )
{
struct V_14 * V_120 [ V_121 + 1 ] ;
struct V_92 T_3 * V_122 ;
struct V_92 * V_93 ;
int V_49 ;
V_49 = F_78 ( V_120 , V_121 , V_119 , V_123 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( ! V_120 [ V_102 ] || ! V_120 [ V_101 ] )
return - V_18 ;
V_122 = F_79 ( struct V_92 ) ;
if ( V_122 == NULL )
return - V_72 ;
V_93 = F_80 ( V_122 ) ;
V_93 -> V_99 = F_81 ( F_82 ( V_120 [ V_102 ] ) ) ;
V_93 -> V_98 = F_81 ( F_82 ( V_120 [ V_101 ] ) ) ;
if ( V_74 -> V_93 ) {
struct V_92 T_3 * V_124 =
F_83 ( V_74 -> V_93 ) ;
F_84 ( V_74 -> V_93 , V_122 ) ;
F_85 () ;
F_86 ( V_124 ) ;
} else
F_84 ( V_74 -> V_93 , V_122 ) ;
return 0 ;
}
static int F_87 ( struct V_64 * V_65 , struct V_25 * V_26 ,
const struct V_31 * V_32 ,
const struct V_14 * const V_15 [] )
{
const struct V_33 * V_34 = F_24 ( V_32 ) ;
const struct V_14 * V_125 ( V_17 ) ;
const struct V_2 * V_3 ;
struct V_13 * V_16 ;
struct V_73 * V_74 ;
struct F_48 * V_107 = NULL ;
struct V_14 * V_126 [ V_127 + 1 ] ;
struct V_1 * V_1 = F_32 ( V_26 -> V_46 ) ;
int V_9 = V_34 -> V_36 ;
T_4 V_115 = V_128 ;
T_1 V_91 = 0 ;
unsigned int V_22 ;
int V_49 ;
bool V_129 ;
V_129 = V_32 -> V_67 & V_130 ? true : false ;
V_3 = F_10 ( V_1 , V_9 , true ) ;
if ( F_42 ( V_3 ) )
return F_43 ( V_3 ) ;
V_16 = F_16 ( V_3 , V_15 [ V_104 ] ) ;
if ( F_42 ( V_16 ) )
return F_43 ( V_16 ) ;
V_74 = NULL ;
V_17 = V_15 [ V_106 ] ;
if ( V_15 [ V_105 ] ) {
V_91 = F_81 ( F_82 ( V_15 [ V_105 ] ) ) ;
V_74 = F_64 ( V_16 , V_91 ) ;
if ( F_42 ( V_74 ) )
return F_43 ( V_74 ) ;
} else {
V_74 = F_65 ( V_16 , V_17 ) ;
if ( F_42 ( V_74 ) ) {
if ( F_43 ( V_74 ) != - V_19 )
return F_43 ( V_74 ) ;
V_74 = NULL ;
}
}
if ( V_15 [ V_114 ] ) {
if ( ( V_74 != NULL &&
! ( V_74 -> V_30 & V_75 ) ) ||
V_15 [ V_109 ] == NULL )
return - V_83 ;
V_115 = F_52 ( F_53 ( V_15 [ V_114 ] ) ) ;
switch ( V_115 ) {
case V_131 :
case V_128 :
break;
default:
return - V_18 ;
}
}
if ( V_74 != NULL ) {
if ( V_32 -> V_67 & V_80 )
return - V_81 ;
if ( V_32 -> V_67 & V_82 )
return - V_83 ;
if ( V_15 [ V_105 ] && V_17 &&
! F_42 ( F_65 ( V_16 , V_15 [ V_106 ] ) ) )
return - V_81 ;
if ( V_15 [ V_100 ] ) {
if ( ! ( V_74 -> V_30 & V_75 ) )
return - V_83 ;
V_49 = F_77 ( F_48 ( V_74 ) ,
V_15 [ V_100 ] ) ;
if ( V_49 < 0 )
return V_49 ;
}
if ( V_15 [ V_114 ] )
F_48 ( V_74 ) -> V_115 = V_115 ;
if ( V_15 [ V_105 ] && V_17 )
F_58 ( V_74 -> V_17 , V_17 , V_132 ) ;
goto V_133;
}
if ( V_16 -> V_43 == V_134 )
return - V_135 ;
if ( V_15 [ V_109 ] ) {
const struct V_21 * type ;
struct V_108 * V_76 ;
T_5 * V_136 ;
T_2 V_111 , V_113 ;
type = V_24 [ V_9 ] [ V_137 ] ;
if ( V_15 [ V_116 ] ) {
type = F_19 ( V_3 ,
V_15 [ V_116 ] ,
V_129 ) ;
if ( F_42 ( type ) )
return F_43 ( type ) ;
}
V_49 = F_78 ( V_126 , V_127 , V_15 [ V_109 ] ,
V_138 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( V_126 [ V_110 ] == NULL ||
V_126 [ V_112 ] == NULL )
return - V_18 ;
V_111 = F_52 ( F_53 ( V_126 [ V_110 ] ) ) ;
if ( V_111 >= V_3 -> V_139 )
return - V_18 ;
V_113 = F_52 ( F_53 ( V_126 [ V_112 ] ) ) ;
if ( ! ( type -> V_140 & ( 1 << V_111 ) ) )
return - V_83 ;
if ( ! F_55 ( type -> V_84 ) )
return - V_19 ;
V_136 = type -> V_141 [ V_111 ] ;
V_107 = F_56 ( sizeof( * V_107 ) , V_53 ) ;
if ( V_107 == NULL )
return - V_72 ;
if ( V_15 [ V_100 ] ) {
V_49 = F_77 ( V_107 ,
V_15 [ V_100 ] ) ;
if ( V_49 < 0 ) {
F_57 ( type -> V_84 ) ;
F_61 ( V_107 ) ;
return V_49 ;
}
} else {
struct V_92 T_3 * V_122 ;
V_122 = F_79 ( struct V_92 ) ;
if ( V_122 == NULL ) {
F_57 ( type -> V_84 ) ;
F_61 ( V_107 ) ;
return - V_72 ;
}
F_84 ( V_107 -> V_93 , V_122 ) ;
}
V_107 -> type = type ;
V_74 = & V_107 -> V_74 ;
for ( V_22 = 0 ; V_22 < V_3 -> V_77 ; V_22 ++ ) {
V_76 = & V_107 -> V_76 [ V_22 ] ;
V_76 -> V_142 = V_9 ;
V_76 -> V_84 = V_3 -> V_84 ;
V_76 -> V_111 = V_111 ;
V_76 -> V_113 = V_113 ;
V_76 -> V_143 = V_74 ;
V_76 -> V_144 = V_3 -> V_141 [ V_76 -> V_111 ] ;
if ( V_136 )
V_76 -> V_144 = V_136 ;
if ( V_3 -> V_145 )
V_3 -> V_145 ( V_76 , V_22 ) ;
}
V_74 -> V_30 |= V_75 ;
V_107 -> V_115 = V_115 ;
} else {
V_74 = F_56 ( sizeof( * V_74 ) , V_53 ) ;
if ( V_74 == NULL )
return - V_72 ;
}
F_2 ( & V_74 -> V_146 ) ;
V_74 -> V_91 = F_17 ( V_16 ) ;
V_74 -> V_1 = V_1 ;
V_74 -> V_16 = V_16 ;
F_58 ( V_74 -> V_17 , V_17 , V_132 ) ;
if ( ! ( V_16 -> V_30 & V_79 ) &&
V_74 -> V_30 & V_75 ) {
V_49 = F_47 ( F_48 ( V_74 ) -> V_76 , V_3 -> V_77 ) ;
if ( V_49 < 0 ) {
F_57 ( V_107 -> type -> V_84 ) ;
F_86 ( V_107 -> V_93 ) ;
F_61 ( V_107 ) ;
return V_49 ;
}
}
F_4 ( & V_74 -> V_6 , & V_16 -> V_85 ) ;
V_16 -> V_43 ++ ;
V_133:
F_74 ( V_26 , V_32 , V_16 , V_74 , V_118 ,
V_9 ) ;
return 0 ;
}
static void F_88 ( struct V_73 * V_74 )
{
F_89 ( V_74 -> V_43 > 0 ) ;
if ( V_74 -> V_30 & V_75 ) {
F_57 ( F_48 ( V_74 ) -> type -> V_84 ) ;
F_86 ( F_48 ( V_74 ) -> V_93 ) ;
F_61 ( F_48 ( V_74 ) ) ;
} else
F_61 ( V_74 ) ;
}
static int F_90 ( struct V_64 * V_65 , struct V_25 * V_26 ,
const struct V_31 * V_32 ,
const struct V_14 * const V_15 [] )
{
const struct V_33 * V_34 = F_24 ( V_32 ) ;
const struct V_2 * V_3 ;
struct V_13 * V_16 ;
struct V_73 * V_74 ;
struct V_1 * V_1 = F_32 ( V_26 -> V_46 ) ;
int V_9 = V_34 -> V_36 ;
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_42 ( V_3 ) )
return F_43 ( V_3 ) ;
V_16 = F_16 ( V_3 , V_15 [ V_104 ] ) ;
if ( F_42 ( V_16 ) )
return F_43 ( V_16 ) ;
V_74 = F_65 ( V_16 , V_15 [ V_106 ] ) ;
if ( F_42 ( V_74 ) )
return F_43 ( V_74 ) ;
if ( ! F_60 ( & V_74 -> V_146 ) || V_74 -> V_43 > 0 )
return - V_87 ;
F_7 ( & V_74 -> V_6 ) ;
V_16 -> V_43 -- ;
if ( ! ( V_16 -> V_30 & V_79 ) &&
V_74 -> V_30 & V_75 )
F_49 ( F_48 ( V_74 ) -> V_76 , V_3 -> V_77 ) ;
F_74 ( V_26 , V_32 , V_16 , V_74 , V_147 ,
V_9 ) ;
F_85 () ;
F_88 ( V_74 ) ;
return 0 ;
}
static void F_91 ( struct V_148 * V_149 ,
const struct V_25 * V_26 ,
const struct V_31 * V_32 ,
const struct V_2 * V_3 ,
const struct V_13 * V_16 ,
const struct V_73 * V_74 ,
const struct V_14 * const * V_15 )
{
V_149 -> V_1 = F_32 ( V_26 -> V_46 ) ;
V_149 -> V_26 = V_26 ;
V_149 -> V_32 = V_32 ;
V_149 -> V_3 = V_3 ;
V_149 -> V_16 = V_16 ;
V_149 -> V_74 = V_74 ;
V_149 -> V_15 = V_15 ;
}
int F_92 ( struct V_150 * type )
{
F_3 ( V_5 ) ;
F_4 ( & type -> V_6 , & V_151 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_93 ( struct V_150 * type )
{
F_3 ( V_5 ) ;
F_7 ( & type -> V_6 ) ;
F_5 ( V_5 ) ;
}
static const struct V_150 * F_94 ( T_4 V_9 ,
struct V_14 * V_15 )
{
const struct V_150 * type ;
F_9 (type, &nf_tables_expressions, list) {
if ( ! F_15 ( V_15 , type -> V_17 ) &&
( ! type -> V_9 || type -> V_9 == V_9 ) )
return type ;
}
return NULL ;
}
static const struct V_150 * F_95 ( T_4 V_9 ,
struct V_14 * V_15 )
{
const struct V_150 * type ;
if ( V_15 == NULL )
return F_13 ( - V_18 ) ;
type = F_94 ( V_9 , V_15 ) ;
if ( type != NULL && F_55 ( type -> V_84 ) )
return type ;
#ifdef F_11
if ( type == NULL ) {
F_5 ( V_5 ) ;
F_12 ( L_3 , V_9 ,
F_20 ( V_15 ) , ( char * ) F_21 ( V_15 ) ) ;
F_3 ( V_5 ) ;
if ( F_94 ( V_9 , V_15 ) )
return F_13 ( - V_11 ) ;
F_5 ( V_5 ) ;
F_12 ( L_4 ,
F_20 ( V_15 ) , ( char * ) F_21 ( V_15 ) ) ;
F_3 ( V_5 ) ;
if ( F_94 ( V_9 , V_15 ) )
return F_13 ( - V_11 ) ;
}
#endif
return F_13 ( - V_19 ) ;
}
static int F_96 ( struct V_25 * V_26 ,
const struct V_152 * V_153 )
{
if ( F_25 ( V_26 , V_154 , V_153 -> V_76 -> type -> V_17 ) )
goto V_35;
if ( V_153 -> V_76 -> V_71 ) {
struct V_14 * V_155 = F_69 ( V_26 , V_156 ) ;
if ( V_155 == NULL )
goto V_35;
if ( V_153 -> V_76 -> V_71 ( V_26 , V_153 ) < 0 )
goto V_35;
F_72 ( V_26 , V_155 ) ;
}
return V_26 -> V_63 ;
V_35:
return - 1 ;
}
static int F_97 ( const struct V_148 * V_149 ,
const struct V_14 * V_15 ,
struct V_157 * V_158 )
{
const struct V_150 * type ;
const struct V_159 * V_76 ;
struct V_14 * V_120 [ V_160 + 1 ] ;
int V_49 ;
V_49 = F_78 ( V_120 , V_160 , V_15 , V_161 ) ;
if ( V_49 < 0 )
return V_49 ;
type = F_95 ( V_149 -> V_3 -> V_9 , V_120 [ V_154 ] ) ;
if ( F_42 ( type ) )
return F_43 ( type ) ;
if ( V_120 [ V_156 ] ) {
V_49 = F_78 ( V_158 -> V_120 , type -> V_162 ,
V_120 [ V_156 ] , type -> V_115 ) ;
if ( V_49 < 0 )
goto V_163;
} else
memset ( V_158 -> V_120 , 0 , sizeof( V_158 -> V_120 [ 0 ] ) * ( type -> V_162 + 1 ) ) ;
if ( type -> V_164 != NULL ) {
V_76 = type -> V_164 ( V_149 ,
( const struct V_14 * const * ) V_158 -> V_120 ) ;
if ( F_42 ( V_76 ) ) {
V_49 = F_43 ( V_76 ) ;
goto V_163;
}
} else
V_76 = type -> V_76 ;
V_158 -> V_76 = V_76 ;
return 0 ;
V_163:
F_57 ( type -> V_84 ) ;
return V_49 ;
}
static int F_98 ( const struct V_148 * V_149 ,
const struct V_157 * V_158 ,
struct V_152 * V_153 )
{
const struct V_159 * V_76 = V_158 -> V_76 ;
int V_49 ;
V_153 -> V_76 = V_76 ;
if ( V_76 -> V_165 ) {
V_49 = V_76 -> V_165 ( V_149 , V_153 , ( const struct V_14 * * ) V_158 -> V_120 ) ;
if ( V_49 < 0 )
goto V_163;
}
return 0 ;
V_163:
V_153 -> V_76 = NULL ;
return V_49 ;
}
static void F_99 ( const struct V_148 * V_149 ,
struct V_152 * V_153 )
{
if ( V_153 -> V_76 -> V_166 )
V_153 -> V_76 -> V_166 ( V_149 , V_153 ) ;
F_57 ( V_153 -> V_76 -> type -> V_84 ) ;
}
static struct V_167 * F_100 ( const struct V_73 * V_74 ,
T_1 V_91 )
{
struct V_167 * V_168 ;
F_9 (rule, &chain->rules, list) {
if ( V_91 == V_168 -> V_91 )
return V_168 ;
}
return F_13 ( - V_19 ) ;
}
static struct V_167 * F_101 ( const struct V_73 * V_74 ,
const struct V_14 * V_15 )
{
if ( V_15 == NULL )
return F_13 ( - V_18 ) ;
return F_100 ( V_74 , F_81 ( F_82 ( V_15 ) ) ) ;
}
static int F_102 ( struct V_25 * V_26 , T_2 V_27 , T_2 V_28 ,
int V_29 , T_2 V_30 , int V_9 ,
const struct V_13 * V_16 ,
const struct V_73 * V_74 ,
const struct V_167 * V_168 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 ;
const struct V_152 * V_153 , * V_169 ;
struct V_14 * V_6 ;
const struct V_167 * V_170 ;
int type = V_29 | V_5 << 8 ;
V_32 = F_23 ( V_26 , V_27 , V_28 , type , sizeof( struct V_33 ) ,
V_30 ) ;
if ( V_32 == NULL )
goto V_35;
V_34 = F_24 ( V_32 ) ;
V_34 -> V_36 = V_9 ;
V_34 -> V_37 = V_38 ;
V_34 -> V_39 = 0 ;
if ( F_25 ( V_26 , V_171 , V_16 -> V_17 ) )
goto V_35;
if ( F_25 ( V_26 , V_172 , V_74 -> V_17 ) )
goto V_35;
if ( F_70 ( V_26 , V_173 , F_71 ( V_168 -> V_91 ) ) )
goto V_35;
if ( ( V_29 != V_174 ) && ( V_168 -> V_6 . V_175 != & V_74 -> V_146 ) ) {
V_170 = F_103 ( V_168 -> V_6 . V_175 , struct V_167 , V_6 ) ;
if ( F_70 ( V_26 , V_176 ,
F_71 ( V_170 -> V_91 ) ) )
goto V_35;
}
V_6 = F_69 ( V_26 , V_177 ) ;
if ( V_6 == NULL )
goto V_35;
F_104 (expr, next, rule) {
struct V_14 * V_178 = F_69 ( V_26 , V_179 ) ;
if ( V_178 == NULL )
goto V_35;
if ( F_96 ( V_26 , V_153 ) < 0 )
goto V_35;
F_72 ( V_26 , V_178 ) ;
}
F_72 ( V_26 , V_6 ) ;
if ( V_168 -> V_180 &&
F_105 ( V_26 , V_181 , V_168 -> V_180 , F_106 ( V_168 ) ) )
goto V_35;
return F_28 ( V_26 , V_32 ) ;
V_35:
F_29 ( V_26 , V_32 ) ;
return - 1 ;
}
static int F_107 ( const struct V_25 * V_44 ,
const struct V_31 * V_32 ,
const struct V_13 * V_16 ,
const struct V_73 * V_74 ,
const struct V_167 * V_168 ,
int V_29 , T_2 V_30 , int V_9 )
{
struct V_25 * V_26 ;
T_2 V_27 = F_31 ( V_44 ) . V_27 ;
struct V_1 * V_1 = V_44 ? F_32 ( V_44 -> V_46 ) : & V_47 ;
T_2 V_28 = V_32 -> V_45 ;
bool V_48 ;
int V_49 ;
V_48 = F_33 ( V_32 ) ;
if ( ! V_48 && ! F_34 ( V_1 , V_50 ) )
return 0 ;
V_49 = - V_51 ;
V_26 = F_35 ( V_52 , V_53 ) ;
if ( V_26 == NULL )
goto V_49;
V_49 = F_102 ( V_26 , V_27 , V_28 , V_29 , V_30 ,
V_9 , V_16 , V_74 , V_168 ) ;
if ( V_49 < 0 ) {
F_36 ( V_26 ) ;
goto V_49;
}
V_49 = F_37 ( V_26 , V_1 , V_27 , V_50 , V_48 ,
V_53 ) ;
V_49:
if ( V_49 < 0 )
F_38 ( V_1 , V_27 , V_50 , V_49 ) ;
return V_49 ;
}
static inline bool
F_108 ( struct V_1 * V_1 , const struct V_167 * V_168 )
{
return ( V_168 -> V_182 & ( 1 << V_1 -> V_7 . V_183 ) ) == 0 ;
}
static inline int F_109 ( struct V_1 * V_1 )
{
return V_1 -> V_7 . V_183 + 1 == 1 ? 1 : 0 ;
}
static inline int
F_110 ( struct V_1 * V_1 , const struct V_167 * V_168 )
{
return ( V_168 -> V_182 & ( 1 << F_109 ( V_1 ) ) ) == 0 ;
}
static inline void
F_111 ( struct V_1 * V_1 , struct V_167 * V_168 )
{
V_168 -> V_182 = ( 1 << V_1 -> V_7 . V_183 ) ;
}
static inline void
F_112 ( struct V_1 * V_1 , struct V_167 * V_168 )
{
V_168 -> V_182 = ( 1 << F_109 ( V_1 ) ) ;
}
static inline void F_113 ( struct V_1 * V_1 , struct V_167 * V_168 )
{
V_168 -> V_182 = 0 ;
}
static int F_114 ( struct V_25 * V_26 ,
struct V_54 * V_55 )
{
const struct V_33 * V_34 = F_24 ( V_55 -> V_32 ) ;
const struct V_2 * V_3 ;
const struct V_13 * V_16 ;
const struct V_73 * V_74 ;
const struct V_167 * V_168 ;
unsigned int V_56 = 0 , V_57 = V_55 -> args [ 0 ] ;
struct V_1 * V_1 = F_32 ( V_26 -> V_46 ) ;
int V_9 = V_34 -> V_36 ;
T_4 V_184 = F_115 ( V_1 -> V_7 . V_184 ) ;
T_4 V_183 = F_115 ( V_1 -> V_7 . V_183 ) ;
F_9 (afi, &net->nft.af_info, list) {
if ( V_9 != V_58 && V_9 != V_3 -> V_9 )
continue;
F_9 (table, &afi->tables, list) {
F_9 (chain, &table->chains, list) {
F_9 (rule, &chain->rules, list) {
if ( ! F_108 ( V_1 , V_168 ) )
goto V_59;
if ( V_56 < V_57 )
goto V_59;
if ( V_56 > V_57 )
memset ( & V_55 -> args [ 1 ] , 0 ,
sizeof( V_55 -> args ) - sizeof( V_55 -> args [ 0 ] ) ) ;
if ( F_102 ( V_26 , F_31 ( V_55 -> V_26 ) . V_27 ,
V_55 -> V_32 -> V_45 ,
V_185 ,
V_61 | V_186 ,
V_3 -> V_9 , V_16 , V_74 , V_168 ) < 0 )
goto V_62;
V_59:
V_56 ++ ;
}
}
}
}
V_62:
if ( V_183 != V_1 -> V_7 . V_183 || V_184 != V_1 -> V_7 . V_184 )
return - V_87 ;
V_55 -> args [ 0 ] = V_56 ;
return V_26 -> V_63 ;
}
static int F_116 ( struct V_64 * V_65 , struct V_25 * V_26 ,
const struct V_31 * V_32 ,
const struct V_14 * const V_15 [] )
{
const struct V_33 * V_34 = F_24 ( V_32 ) ;
const struct V_2 * V_3 ;
const struct V_13 * V_16 ;
const struct V_73 * V_74 ;
const struct V_167 * V_168 ;
struct V_25 * V_66 ;
struct V_1 * V_1 = F_32 ( V_26 -> V_46 ) ;
int V_9 = V_34 -> V_36 ;
int V_49 ;
if ( V_32 -> V_67 & V_68 ) {
struct V_69 V_70 = {
. V_71 = F_114 ,
} ;
return F_41 ( V_65 , V_26 , V_32 , & V_70 ) ;
}
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_42 ( V_3 ) )
return F_43 ( V_3 ) ;
V_16 = F_16 ( V_3 , V_15 [ V_171 ] ) ;
if ( F_42 ( V_16 ) )
return F_43 ( V_16 ) ;
V_74 = F_65 ( V_16 , V_15 [ V_172 ] ) ;
if ( F_42 ( V_74 ) )
return F_43 ( V_74 ) ;
V_168 = F_101 ( V_74 , V_15 [ V_173 ] ) ;
if ( F_42 ( V_168 ) )
return F_43 ( V_168 ) ;
V_66 = F_44 ( V_52 , V_53 ) ;
if ( ! V_66 )
return - V_72 ;
V_49 = F_102 ( V_66 , F_31 ( V_26 ) . V_27 ,
V_32 -> V_45 , V_185 , 0 ,
V_9 , V_16 , V_74 , V_168 ) ;
if ( V_49 < 0 )
goto V_49;
return F_45 ( V_65 , V_66 , F_31 ( V_26 ) . V_27 ) ;
V_49:
F_36 ( V_66 ) ;
return V_49 ;
}
static void F_117 ( const struct V_148 * V_149 ,
struct V_167 * V_168 )
{
struct V_152 * V_153 ;
V_153 = F_118 ( V_168 ) ;
while ( V_153 -> V_76 && V_153 != F_119 ( V_168 ) ) {
F_99 ( V_149 , V_153 ) ;
V_153 = F_120 ( V_153 ) ;
}
F_61 ( V_168 ) ;
}
static struct V_187 *
F_121 ( struct V_148 * V_149 , struct V_167 * V_168 )
{
struct V_187 * V_188 ;
V_188 = F_122 ( sizeof( struct V_187 ) , V_53 ) ;
if ( V_188 == NULL )
return NULL ;
V_188 -> V_149 = * V_149 ;
V_188 -> V_168 = V_168 ;
F_4 ( & V_188 -> V_6 , & V_149 -> V_1 -> V_7 . V_189 ) ;
return V_188 ;
}
static int F_123 ( struct V_64 * V_65 , struct V_25 * V_26 ,
const struct V_31 * V_32 ,
const struct V_14 * const V_15 [] )
{
const struct V_33 * V_34 = F_24 ( V_32 ) ;
const struct V_2 * V_3 ;
struct V_1 * V_1 = F_32 ( V_26 -> V_46 ) ;
struct V_13 * V_16 ;
struct V_73 * V_74 ;
struct V_167 * V_168 , * V_190 = NULL ;
struct V_187 * V_191 = NULL ;
struct V_152 * V_153 ;
struct V_148 V_149 ;
struct V_14 * V_192 ;
unsigned int V_193 , V_22 , V_194 , V_180 = 0 ;
int V_49 , V_195 ;
bool V_129 ;
T_1 V_91 , V_196 ;
V_129 = V_32 -> V_67 & V_130 ? true : false ;
V_3 = F_10 ( V_1 , V_34 -> V_36 , V_129 ) ;
if ( F_42 ( V_3 ) )
return F_43 ( V_3 ) ;
V_16 = F_16 ( V_3 , V_15 [ V_171 ] ) ;
if ( F_42 ( V_16 ) )
return F_43 ( V_16 ) ;
V_74 = F_65 ( V_16 , V_15 [ V_172 ] ) ;
if ( F_42 ( V_74 ) )
return F_43 ( V_74 ) ;
if ( V_15 [ V_173 ] ) {
V_91 = F_81 ( F_82 ( V_15 [ V_173 ] ) ) ;
V_168 = F_100 ( V_74 , V_91 ) ;
if ( F_42 ( V_168 ) )
return F_43 ( V_168 ) ;
if ( V_32 -> V_67 & V_80 )
return - V_81 ;
if ( V_32 -> V_67 & V_82 )
V_190 = V_168 ;
else
return - V_83 ;
} else {
if ( ! V_129 || V_32 -> V_67 & V_82 )
return - V_18 ;
V_91 = F_17 ( V_16 ) ;
}
if ( V_15 [ V_176 ] ) {
if ( ! ( V_32 -> V_67 & V_130 ) )
return - V_83 ;
V_196 = F_81 ( F_82 ( V_15 [ V_176 ] ) ) ;
V_190 = F_100 ( V_74 , V_196 ) ;
if ( F_42 ( V_190 ) )
return F_43 ( V_190 ) ;
}
F_91 ( & V_149 , V_26 , V_32 , V_3 , V_16 , V_74 , V_15 ) ;
V_194 = 0 ;
V_193 = 0 ;
if ( V_15 [ V_177 ] ) {
F_124 (tmp, nla[NFTA_RULE_EXPRESSIONS], rem) {
V_49 = - V_18 ;
if ( F_125 ( V_192 ) != V_179 )
goto V_163;
if ( V_194 == V_197 )
goto V_163;
V_49 = F_97 ( & V_149 , V_192 , & V_158 [ V_194 ] ) ;
if ( V_49 < 0 )
goto V_163;
V_193 += V_158 [ V_194 ] . V_76 -> V_193 ;
V_194 ++ ;
}
}
if ( V_15 [ V_181 ] )
V_180 = F_20 ( V_15 [ V_181 ] ) ;
V_49 = - V_72 ;
V_168 = F_56 ( sizeof( * V_168 ) + V_193 + V_180 , V_53 ) ;
if ( V_168 == NULL )
goto V_163;
F_111 ( V_1 , V_168 ) ;
V_168 -> V_91 = V_91 ;
V_168 -> V_198 = V_193 ;
V_168 -> V_180 = V_180 ;
if ( V_180 )
F_126 ( F_106 ( V_168 ) , V_15 [ V_181 ] , V_180 ) ;
V_153 = F_118 ( V_168 ) ;
for ( V_22 = 0 ; V_22 < V_194 ; V_22 ++ ) {
V_49 = F_98 ( & V_149 , & V_158 [ V_22 ] , V_153 ) ;
if ( V_49 < 0 )
goto V_199;
V_158 [ V_22 ] . V_76 = NULL ;
V_153 = F_120 ( V_153 ) ;
}
if ( V_32 -> V_67 & V_82 ) {
if ( F_110 ( V_1 , V_190 ) ) {
V_191 = F_121 ( & V_149 , V_190 ) ;
if ( V_191 == NULL ) {
V_49 = - V_72 ;
goto V_199;
}
F_112 ( V_1 , V_190 ) ;
F_4 ( & V_168 -> V_6 , & V_190 -> V_6 ) ;
} else {
V_49 = - V_19 ;
goto V_199;
}
} else if ( V_32 -> V_67 & V_186 )
if ( V_190 )
F_127 ( & V_168 -> V_6 , & V_190 -> V_6 ) ;
else
F_128 ( & V_168 -> V_6 , & V_74 -> V_146 ) ;
else {
if ( V_190 )
F_128 ( & V_168 -> V_6 , & V_190 -> V_6 ) ;
else
F_127 ( & V_168 -> V_6 , & V_74 -> V_146 ) ;
}
if ( F_121 ( & V_149 , V_168 ) == NULL ) {
V_49 = - V_72 ;
goto V_200;
}
return 0 ;
V_200:
F_129 ( & V_168 -> V_6 ) ;
if ( V_191 ) {
F_129 ( & V_191 -> V_168 -> V_6 ) ;
F_7 ( & V_191 -> V_6 ) ;
F_113 ( V_1 , V_191 -> V_168 ) ;
F_61 ( V_191 ) ;
}
V_199:
F_117 ( & V_149 , V_168 ) ;
V_163:
for ( V_22 = 0 ; V_22 < V_194 ; V_22 ++ ) {
if ( V_158 [ V_22 ] . V_76 != NULL )
F_57 ( V_158 [ V_22 ] . V_76 -> type -> V_84 ) ;
}
return V_49 ;
}
static int
F_130 ( struct V_148 * V_149 , struct V_167 * V_168 )
{
if ( F_110 ( V_149 -> V_1 , V_168 ) ) {
if ( F_121 ( V_149 , V_168 ) == NULL )
return - V_72 ;
F_112 ( V_149 -> V_1 , V_168 ) ;
return 0 ;
}
return - V_19 ;
}
static int F_131 ( struct V_148 * V_149 )
{
struct V_167 * V_168 ;
int V_49 ;
F_9 (rule, &ctx->chain->rules, list) {
V_49 = F_130 ( V_149 , V_168 ) ;
if ( V_49 < 0 )
return V_49 ;
}
return 0 ;
}
static int F_132 ( struct V_64 * V_65 , struct V_25 * V_26 ,
const struct V_31 * V_32 ,
const struct V_14 * const V_15 [] )
{
const struct V_33 * V_34 = F_24 ( V_32 ) ;
const struct V_2 * V_3 ;
struct V_1 * V_1 = F_32 ( V_26 -> V_46 ) ;
const struct V_13 * V_16 ;
struct V_73 * V_74 = NULL ;
struct V_167 * V_168 ;
int V_9 = V_34 -> V_36 , V_49 = 0 ;
struct V_148 V_149 ;
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_42 ( V_3 ) )
return F_43 ( V_3 ) ;
V_16 = F_16 ( V_3 , V_15 [ V_171 ] ) ;
if ( F_42 ( V_16 ) )
return F_43 ( V_16 ) ;
if ( V_15 [ V_172 ] ) {
V_74 = F_65 ( V_16 , V_15 [ V_172 ] ) ;
if ( F_42 ( V_74 ) )
return F_43 ( V_74 ) ;
}
F_91 ( & V_149 , V_26 , V_32 , V_3 , V_16 , V_74 , V_15 ) ;
if ( V_74 ) {
if ( V_15 [ V_173 ] ) {
V_168 = F_101 ( V_74 ,
V_15 [ V_173 ] ) ;
if ( F_42 ( V_168 ) )
return F_43 ( V_168 ) ;
V_49 = F_130 ( & V_149 , V_168 ) ;
} else {
V_49 = F_131 ( & V_149 ) ;
}
} else {
F_9 (chain, &table->chains, list) {
V_149 . V_74 = V_74 ;
V_49 = F_131 ( & V_149 ) ;
if ( V_49 < 0 )
break;
}
}
return V_49 ;
}
static int F_133 ( struct V_25 * V_26 )
{
struct V_1 * V_1 = F_32 ( V_26 -> V_46 ) ;
struct V_187 * V_188 , * V_192 ;
V_1 -> V_7 . V_184 ++ ;
V_1 -> V_7 . V_183 = F_109 ( V_1 ) ;
F_85 () ;
F_134 (rupd, tmp, &net->nft.commit_list, list) {
if ( F_108 ( V_1 , V_188 -> V_168 ) ) {
F_113 ( V_1 , V_188 -> V_168 ) ;
F_107 ( V_26 , V_188 -> V_149 . V_32 ,
V_188 -> V_149 . V_16 , V_188 -> V_149 . V_74 ,
V_188 -> V_168 , V_185 , 0 ,
V_188 -> V_149 . V_3 -> V_9 ) ;
F_7 ( & V_188 -> V_6 ) ;
F_61 ( V_188 ) ;
continue;
}
F_129 ( & V_188 -> V_168 -> V_6 ) ;
F_107 ( V_26 , V_188 -> V_149 . V_32 ,
V_188 -> V_149 . V_16 , V_188 -> V_149 . V_74 ,
V_188 -> V_168 , V_174 , 0 ,
V_188 -> V_149 . V_3 -> V_9 ) ;
}
F_85 () ;
F_134 (rupd, tmp, &net->nft.commit_list, list) {
F_117 ( & V_188 -> V_149 , V_188 -> V_168 ) ;
F_7 ( & V_188 -> V_6 ) ;
F_61 ( V_188 ) ;
}
return 0 ;
}
static int F_135 ( struct V_25 * V_26 )
{
struct V_1 * V_1 = F_32 ( V_26 -> V_46 ) ;
struct V_187 * V_188 , * V_192 ;
F_134 (rupd, tmp, &net->nft.commit_list, list) {
if ( ! F_110 ( V_1 , V_188 -> V_168 ) ) {
F_113 ( V_1 , V_188 -> V_168 ) ;
F_7 ( & V_188 -> V_6 ) ;
F_61 ( V_188 ) ;
continue;
}
F_129 ( & V_188 -> V_168 -> V_6 ) ;
}
F_85 () ;
F_134 (rupd, tmp, &net->nft.commit_list, list) {
F_117 ( & V_188 -> V_149 , V_188 -> V_168 ) ;
F_7 ( & V_188 -> V_6 ) ;
F_61 ( V_188 ) ;
}
return 0 ;
}
int F_136 ( struct V_201 * V_76 )
{
F_3 ( V_5 ) ;
F_4 ( & V_76 -> V_6 , & V_202 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_137 ( struct V_201 * V_76 )
{
F_3 ( V_5 ) ;
F_7 ( & V_76 -> V_6 ) ;
F_5 ( V_5 ) ;
}
static const struct V_201 * F_138 ( const struct V_14 * const V_15 [] )
{
const struct V_201 * V_76 ;
T_2 V_203 ;
#ifdef F_11
if ( F_60 ( & V_202 ) ) {
F_5 ( V_5 ) ;
F_12 ( L_5 ) ;
F_3 ( V_5 ) ;
if ( ! F_60 ( & V_202 ) )
return F_13 ( - V_11 ) ;
}
#endif
V_203 = 0 ;
if ( V_15 [ V_204 ] != NULL ) {
V_203 = F_52 ( F_53 ( V_15 [ V_204 ] ) ) ;
V_203 &= V_205 | V_206 ;
}
F_9 (ops, &nf_tables_set_ops, list) {
if ( ( V_76 -> V_203 & V_203 ) != V_203 )
continue;
if ( ! F_55 ( V_76 -> V_84 ) )
continue;
return V_76 ;
}
return F_13 ( - V_83 ) ;
}
static int F_139 ( struct V_148 * V_149 ,
const struct V_25 * V_26 ,
const struct V_31 * V_32 ,
const struct V_14 * const V_15 [] )
{
struct V_1 * V_1 = F_32 ( V_26 -> V_46 ) ;
const struct V_33 * V_34 = F_24 ( V_32 ) ;
const struct V_2 * V_3 = NULL ;
const struct V_13 * V_16 = NULL ;
if ( V_34 -> V_36 != V_58 ) {
V_3 = F_10 ( V_1 , V_34 -> V_36 , false ) ;
if ( F_42 ( V_3 ) )
return F_43 ( V_3 ) ;
}
if ( V_15 [ V_207 ] != NULL ) {
if ( V_3 == NULL )
return - V_12 ;
V_16 = F_16 ( V_3 , V_15 [ V_207 ] ) ;
if ( F_42 ( V_16 ) )
return F_43 ( V_16 ) ;
}
F_91 ( V_149 , V_26 , V_32 , V_3 , V_16 , NULL , V_15 ) ;
return 0 ;
}
struct V_208 * F_140 ( const struct V_13 * V_16 ,
const struct V_14 * V_15 )
{
struct V_208 * V_209 ;
if ( V_15 == NULL )
return F_13 ( - V_18 ) ;
F_9 (set, &table->sets, list) {
if ( ! F_15 ( V_15 , V_209 -> V_17 ) )
return V_209 ;
}
return F_13 ( - V_19 ) ;
}
static int F_141 ( struct V_148 * V_149 , struct V_208 * V_209 ,
const char * V_17 )
{
const struct V_208 * V_22 ;
const char * V_210 ;
unsigned long * V_211 ;
unsigned int V_194 = 0 ;
V_210 = F_142 ( V_17 , V_212 , '%' ) ;
if ( V_210 != NULL ) {
if ( V_210 [ 1 ] != 'd' || strchr ( V_210 + 2 , '%' ) )
return - V_18 ;
V_211 = ( unsigned long * ) F_143 ( V_53 ) ;
if ( V_211 == NULL )
return - V_72 ;
F_9 (i, &ctx->table->sets, list) {
int V_192 ;
if ( ! sscanf ( V_22 -> V_17 , V_17 , & V_192 ) )
continue;
if ( V_192 < 0 || V_192 >= V_213 * V_214 )
continue;
F_144 ( V_192 , V_211 ) ;
}
V_194 = F_145 ( V_211 , V_213 * V_214 ) ;
F_146 ( ( unsigned long ) V_211 ) ;
}
snprintf ( V_209 -> V_17 , sizeof( V_209 -> V_17 ) , V_17 , V_194 ) ;
F_9 (i, &ctx->table->sets, list) {
if ( ! strcmp ( V_209 -> V_17 , V_22 -> V_17 ) )
return - V_215 ;
}
return 0 ;
}
static int F_147 ( struct V_25 * V_26 , const struct V_148 * V_149 ,
const struct V_208 * V_209 , T_6 V_29 , T_6 V_30 )
{
struct V_33 * V_34 ;
struct V_31 * V_32 ;
T_2 V_27 = F_31 ( V_149 -> V_26 ) . V_27 ;
T_2 V_28 = V_149 -> V_32 -> V_45 ;
V_29 |= V_5 << 8 ;
V_32 = F_23 ( V_26 , V_27 , V_28 , V_29 , sizeof( struct V_33 ) ,
V_30 ) ;
if ( V_32 == NULL )
goto V_35;
V_34 = F_24 ( V_32 ) ;
V_34 -> V_36 = V_149 -> V_3 -> V_9 ;
V_34 -> V_37 = V_38 ;
V_34 -> V_39 = 0 ;
if ( F_25 ( V_26 , V_207 , V_149 -> V_16 -> V_17 ) )
goto V_35;
if ( F_25 ( V_26 , V_216 , V_209 -> V_17 ) )
goto V_35;
if ( V_209 -> V_30 != 0 )
if ( F_26 ( V_26 , V_204 , F_27 ( V_209 -> V_30 ) ) )
goto V_35;
if ( F_26 ( V_26 , V_217 , F_27 ( V_209 -> V_218 ) ) )
goto V_35;
if ( F_26 ( V_26 , V_219 , F_27 ( V_209 -> V_220 ) ) )
goto V_35;
if ( V_209 -> V_30 & V_206 ) {
if ( F_26 ( V_26 , V_221 , F_27 ( V_209 -> V_222 ) ) )
goto V_35;
if ( F_26 ( V_26 , V_223 , F_27 ( V_209 -> V_198 ) ) )
goto V_35;
}
return F_28 ( V_26 , V_32 ) ;
V_35:
F_29 ( V_26 , V_32 ) ;
return - 1 ;
}
static int F_148 ( const struct V_148 * V_149 ,
const struct V_208 * V_209 ,
int V_29 )
{
struct V_25 * V_26 ;
T_2 V_27 = F_31 ( V_149 -> V_26 ) . V_27 ;
bool V_48 ;
int V_49 ;
V_48 = F_33 ( V_149 -> V_32 ) ;
if ( ! V_48 && ! F_34 ( V_149 -> V_1 , V_50 ) )
return 0 ;
V_49 = - V_51 ;
V_26 = F_35 ( V_52 , V_53 ) ;
if ( V_26 == NULL )
goto V_49;
V_49 = F_147 ( V_26 , V_149 , V_209 , V_29 , 0 ) ;
if ( V_49 < 0 ) {
F_36 ( V_26 ) ;
goto V_49;
}
V_49 = F_37 ( V_26 , V_149 -> V_1 , V_27 , V_50 , V_48 ,
V_53 ) ;
V_49:
if ( V_49 < 0 )
F_38 ( V_149 -> V_1 , V_27 , V_50 , V_49 ) ;
return V_49 ;
}
static int F_149 ( struct V_148 * V_149 , struct V_25 * V_26 ,
struct V_54 * V_55 )
{
const struct V_208 * V_209 ;
unsigned int V_56 = 0 , V_57 = V_55 -> args [ 0 ] ;
if ( V_55 -> args [ 1 ] )
return V_26 -> V_63 ;
F_9 (set, &ctx->table->sets, list) {
if ( V_56 < V_57 )
goto V_59;
if ( F_147 ( V_26 , V_149 , V_209 , V_224 ,
V_61 ) < 0 ) {
V_55 -> args [ 0 ] = V_56 ;
goto V_62;
}
V_59:
V_56 ++ ;
}
V_55 -> args [ 1 ] = 1 ;
V_62:
return V_26 -> V_63 ;
}
static int F_150 ( struct V_148 * V_149 , struct V_25 * V_26 ,
struct V_54 * V_55 )
{
const struct V_208 * V_209 ;
unsigned int V_56 , V_57 = V_55 -> args [ 0 ] ;
struct V_13 * V_16 , * V_225 = (struct V_13 * ) V_55 -> args [ 2 ] ;
if ( V_55 -> args [ 1 ] )
return V_26 -> V_63 ;
F_9 (table, &ctx->afi->tables, list) {
if ( V_225 ) {
if ( V_225 != V_16 )
continue;
V_225 = NULL ;
}
V_149 -> V_16 = V_16 ;
V_56 = 0 ;
F_9 (set, &ctx->table->sets, list) {
if ( V_56 < V_57 )
goto V_59;
if ( F_147 ( V_26 , V_149 , V_209 , V_224 ,
V_61 ) < 0 ) {
V_55 -> args [ 0 ] = V_56 ;
V_55 -> args [ 2 ] = ( unsigned long ) V_16 ;
goto V_62;
}
V_59:
V_56 ++ ;
}
}
V_55 -> args [ 1 ] = 1 ;
V_62:
return V_26 -> V_63 ;
}
static int F_151 ( struct V_148 * V_149 , struct V_25 * V_26 ,
struct V_54 * V_55 )
{
const struct V_208 * V_209 ;
unsigned int V_56 , V_57 = V_55 -> args [ 0 ] ;
const struct V_2 * V_3 ;
struct V_13 * V_16 , * V_225 = (struct V_13 * ) V_55 -> args [ 2 ] ;
struct V_1 * V_1 = F_32 ( V_26 -> V_46 ) ;
int V_226 = V_55 -> args [ 3 ] ;
if ( V_55 -> args [ 1 ] )
return V_26 -> V_63 ;
F_9 (afi, &net->nft.af_info, list) {
if ( V_226 ) {
if ( V_3 -> V_9 != V_226 )
continue;
V_226 = 0 ;
}
F_9 (table, &afi->tables, list) {
if ( V_225 ) {
if ( V_225 != V_16 )
continue;
V_225 = NULL ;
}
V_149 -> V_16 = V_16 ;
V_149 -> V_3 = V_3 ;
V_56 = 0 ;
F_9 (set, &ctx->table->sets, list) {
if ( V_56 < V_57 )
goto V_59;
if ( F_147 ( V_26 , V_149 , V_209 ,
V_224 ,
V_61 ) < 0 ) {
V_55 -> args [ 0 ] = V_56 ;
V_55 -> args [ 2 ] = ( unsigned long ) V_16 ;
V_55 -> args [ 3 ] = V_3 -> V_9 ;
goto V_62;
}
V_59:
V_56 ++ ;
}
if ( V_57 )
V_57 = 0 ;
}
}
V_55 -> args [ 1 ] = 1 ;
V_62:
return V_26 -> V_63 ;
}
static int F_152 ( struct V_25 * V_26 , struct V_54 * V_55 )
{
const struct V_33 * V_34 = F_24 ( V_55 -> V_32 ) ;
struct V_14 * V_15 [ V_227 + 1 ] ;
struct V_148 V_149 ;
int V_49 , V_78 ;
V_49 = F_153 ( V_55 -> V_32 , sizeof( * V_34 ) , V_15 , V_227 ,
V_228 ) ;
if ( V_49 < 0 )
return V_49 ;
V_49 = F_139 ( & V_149 , V_55 -> V_26 , V_55 -> V_32 , ( void * ) V_15 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( V_149 . V_16 == NULL ) {
if ( V_149 . V_3 == NULL )
V_78 = F_151 ( & V_149 , V_26 , V_55 ) ;
else
V_78 = F_150 ( & V_149 , V_26 , V_55 ) ;
} else
V_78 = F_149 ( & V_149 , V_26 , V_55 ) ;
return V_78 ;
}
static int F_154 ( struct V_64 * V_65 , struct V_25 * V_26 ,
const struct V_31 * V_32 ,
const struct V_14 * const V_15 [] )
{
const struct V_208 * V_209 ;
struct V_148 V_149 ;
struct V_25 * V_66 ;
const struct V_33 * V_34 = F_24 ( V_32 ) ;
int V_49 ;
V_49 = F_139 ( & V_149 , V_26 , V_32 , V_15 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( V_32 -> V_67 & V_68 ) {
struct V_69 V_70 = {
. V_71 = F_152 ,
} ;
return F_41 ( V_65 , V_26 , V_32 , & V_70 ) ;
}
if ( V_34 -> V_36 == V_58 )
return - V_12 ;
V_209 = F_140 ( V_149 . V_16 , V_15 [ V_216 ] ) ;
if ( F_42 ( V_209 ) )
return F_43 ( V_209 ) ;
V_66 = F_44 ( V_52 , V_53 ) ;
if ( V_66 == NULL )
return - V_72 ;
V_49 = F_147 ( V_66 , & V_149 , V_209 , V_224 , 0 ) ;
if ( V_49 < 0 )
goto V_49;
return F_45 ( V_65 , V_66 , F_31 ( V_26 ) . V_27 ) ;
V_49:
F_36 ( V_66 ) ;
return V_49 ;
}
static int F_155 ( struct V_64 * V_65 , struct V_25 * V_26 ,
const struct V_31 * V_32 ,
const struct V_14 * const V_15 [] )
{
const struct V_33 * V_34 = F_24 ( V_32 ) ;
const struct V_201 * V_76 ;
const struct V_2 * V_3 ;
struct V_1 * V_1 = F_32 ( V_26 -> V_46 ) ;
struct V_13 * V_16 ;
struct V_208 * V_209 ;
struct V_148 V_149 ;
char V_17 [ V_212 ] ;
unsigned int V_193 ;
bool V_129 ;
T_2 V_218 , V_220 , V_198 , V_222 , V_30 ;
int V_49 ;
if ( V_15 [ V_207 ] == NULL ||
V_15 [ V_216 ] == NULL ||
V_15 [ V_219 ] == NULL )
return - V_18 ;
V_218 = V_229 ;
if ( V_15 [ V_217 ] != NULL ) {
V_218 = F_52 ( F_53 ( V_15 [ V_217 ] ) ) ;
if ( ( V_218 & V_230 ) == V_230 )
return - V_18 ;
}
V_220 = F_52 ( F_53 ( V_15 [ V_219 ] ) ) ;
if ( V_220 == 0 || V_220 > F_156 ( struct V_231 , V_155 ) )
return - V_18 ;
V_30 = 0 ;
if ( V_15 [ V_204 ] != NULL ) {
V_30 = F_52 ( F_53 ( V_15 [ V_204 ] ) ) ;
if ( V_30 & ~ ( V_232 | V_233 |
V_205 | V_206 ) )
return - V_18 ;
}
V_222 = 0 ;
V_198 = 0 ;
if ( V_15 [ V_221 ] != NULL ) {
if ( ! ( V_30 & V_206 ) )
return - V_18 ;
V_222 = F_52 ( F_53 ( V_15 [ V_221 ] ) ) ;
if ( ( V_222 & V_230 ) == V_230 &&
V_222 != V_234 )
return - V_18 ;
if ( V_222 != V_234 ) {
if ( V_15 [ V_223 ] == NULL )
return - V_18 ;
V_198 = F_52 ( F_53 ( V_15 [ V_223 ] ) ) ;
if ( V_198 == 0 ||
V_198 > F_156 ( struct V_231 , V_155 ) )
return - V_18 ;
} else
V_198 = sizeof( struct V_231 ) ;
} else if ( V_30 & V_206 )
return - V_18 ;
V_129 = V_32 -> V_67 & V_130 ? true : false ;
V_3 = F_10 ( V_1 , V_34 -> V_36 , V_129 ) ;
if ( F_42 ( V_3 ) )
return F_43 ( V_3 ) ;
V_16 = F_16 ( V_3 , V_15 [ V_207 ] ) ;
if ( F_42 ( V_16 ) )
return F_43 ( V_16 ) ;
F_91 ( & V_149 , V_26 , V_32 , V_3 , V_16 , NULL , V_15 ) ;
V_209 = F_140 ( V_16 , V_15 [ V_216 ] ) ;
if ( F_42 ( V_209 ) ) {
if ( F_43 ( V_209 ) != - V_19 )
return F_43 ( V_209 ) ;
V_209 = NULL ;
}
if ( V_209 != NULL ) {
if ( V_32 -> V_67 & V_80 )
return - V_81 ;
if ( V_32 -> V_67 & V_82 )
return - V_83 ;
return 0 ;
}
if ( ! ( V_32 -> V_67 & V_130 ) )
return - V_19 ;
V_76 = F_138 ( V_15 ) ;
if ( F_42 ( V_76 ) )
return F_43 ( V_76 ) ;
V_193 = 0 ;
if ( V_76 -> V_235 != NULL )
V_193 = V_76 -> V_235 ( V_15 ) ;
V_49 = - V_72 ;
V_209 = F_56 ( sizeof( * V_209 ) + V_193 , V_53 ) ;
if ( V_209 == NULL )
goto V_163;
F_58 ( V_17 , V_15 [ V_216 ] , sizeof( V_209 -> V_17 ) ) ;
V_49 = F_141 ( & V_149 , V_209 , V_17 ) ;
if ( V_49 < 0 )
goto V_199;
F_2 ( & V_209 -> V_236 ) ;
V_209 -> V_76 = V_76 ;
V_209 -> V_218 = V_218 ;
V_209 -> V_220 = V_220 ;
V_209 -> V_222 = V_222 ;
V_209 -> V_198 = V_198 ;
V_209 -> V_30 = V_30 ;
V_49 = V_76 -> V_165 ( V_209 , V_15 ) ;
if ( V_49 < 0 )
goto V_199;
F_4 ( & V_209 -> V_6 , & V_16 -> V_86 ) ;
F_148 ( & V_149 , V_209 , V_224 ) ;
return 0 ;
V_199:
F_61 ( V_209 ) ;
V_163:
F_57 ( V_76 -> V_84 ) ;
return V_49 ;
}
static void F_157 ( const struct V_148 * V_149 , struct V_208 * V_209 )
{
F_7 ( & V_209 -> V_6 ) ;
F_148 ( V_149 , V_209 , V_237 ) ;
V_209 -> V_76 -> V_166 ( V_209 ) ;
F_57 ( V_209 -> V_76 -> V_84 ) ;
F_61 ( V_209 ) ;
}
static int F_158 ( struct V_64 * V_65 , struct V_25 * V_26 ,
const struct V_31 * V_32 ,
const struct V_14 * const V_15 [] )
{
const struct V_33 * V_34 = F_24 ( V_32 ) ;
struct V_208 * V_209 ;
struct V_148 V_149 ;
int V_49 ;
if ( V_34 -> V_36 == V_58 )
return - V_12 ;
if ( V_15 [ V_207 ] == NULL )
return - V_18 ;
V_49 = F_139 ( & V_149 , V_26 , V_32 , V_15 ) ;
if ( V_49 < 0 )
return V_49 ;
V_209 = F_140 ( V_149 . V_16 , V_15 [ V_216 ] ) ;
if ( F_42 ( V_209 ) )
return F_43 ( V_209 ) ;
if ( ! F_60 ( & V_209 -> V_236 ) )
return - V_87 ;
F_157 ( & V_149 , V_209 ) ;
return 0 ;
}
static int F_159 ( const struct V_148 * V_149 ,
const struct V_208 * V_209 ,
const struct V_238 * V_239 ,
const struct V_240 * V_178 )
{
enum V_241 V_242 ;
V_242 = F_160 ( V_209 -> V_222 ) ;
return F_161 ( V_149 , V_242 , & V_178 -> V_155 ,
V_209 -> V_222 == V_234 ?
V_234 : V_229 ) ;
}
int F_162 ( const struct V_148 * V_149 , struct V_208 * V_209 ,
struct V_243 * V_244 )
{
struct V_243 * V_22 ;
struct V_238 V_239 ;
if ( ! F_60 ( & V_209 -> V_236 ) && V_209 -> V_30 & V_232 )
return - V_87 ;
if ( V_209 -> V_30 & V_206 ) {
F_9 (i, &set->bindings, list) {
if ( V_22 -> V_74 == V_244 -> V_74 )
goto V_245;
}
V_239 . V_246 = 0 ;
V_239 . V_247 = 0 ;
V_239 . V_49 = 0 ;
V_239 . V_248 = F_159 ;
V_209 -> V_76 -> V_249 ( V_149 , V_209 , & V_239 ) ;
if ( V_239 . V_49 < 0 ) {
if ( V_209 -> V_30 & V_232 )
F_157 ( V_149 , V_209 ) ;
return V_239 . V_49 ;
}
}
V_245:
V_244 -> V_74 = V_149 -> V_74 ;
F_4 ( & V_244 -> V_6 , & V_209 -> V_236 ) ;
return 0 ;
}
void F_163 ( const struct V_148 * V_149 , struct V_208 * V_209 ,
struct V_243 * V_244 )
{
F_7 ( & V_244 -> V_6 ) ;
if ( F_60 ( & V_209 -> V_236 ) && V_209 -> V_30 & V_232 )
F_157 ( V_149 , V_209 ) ;
}
static int F_164 ( struct V_148 * V_149 ,
const struct V_25 * V_26 ,
const struct V_31 * V_32 ,
const struct V_14 * const V_15 [] )
{
const struct V_33 * V_34 = F_24 ( V_32 ) ;
const struct V_2 * V_3 ;
const struct V_13 * V_16 ;
struct V_1 * V_1 = F_32 ( V_26 -> V_46 ) ;
V_3 = F_10 ( V_1 , V_34 -> V_36 , false ) ;
if ( F_42 ( V_3 ) )
return F_43 ( V_3 ) ;
V_16 = F_16 ( V_3 , V_15 [ V_250 ] ) ;
if ( F_42 ( V_16 ) )
return F_43 ( V_16 ) ;
F_91 ( V_149 , V_26 , V_32 , V_3 , V_16 , NULL , V_15 ) ;
return 0 ;
}
static int F_165 ( struct V_25 * V_26 ,
const struct V_208 * V_209 ,
const struct V_240 * V_178 )
{
unsigned char * V_251 = F_166 ( V_26 ) ;
struct V_14 * V_96 ;
V_96 = F_69 ( V_26 , V_179 ) ;
if ( V_96 == NULL )
goto V_35;
if ( F_167 ( V_26 , V_252 , & V_178 -> V_253 , V_229 ,
V_209 -> V_220 ) < 0 )
goto V_35;
if ( V_209 -> V_30 & V_206 &&
! ( V_178 -> V_30 & V_254 ) &&
F_167 ( V_26 , V_255 , & V_178 -> V_155 ,
V_209 -> V_222 == V_234 ? V_234 : V_229 ,
V_209 -> V_198 ) < 0 )
goto V_35;
if ( V_178 -> V_30 != 0 )
if ( F_26 ( V_26 , V_256 , F_27 ( V_178 -> V_30 ) ) )
goto V_35;
F_72 ( V_26 , V_96 ) ;
return 0 ;
V_35:
F_29 ( V_26 , V_251 ) ;
return - V_257 ;
}
static int F_168 ( const struct V_148 * V_149 ,
const struct V_208 * V_209 ,
const struct V_238 * V_239 ,
const struct V_240 * V_178 )
{
struct V_258 * args ;
args = F_169 ( V_239 , struct V_258 , V_239 ) ;
return F_165 ( args -> V_26 , V_209 , V_178 ) ;
}
static int F_170 ( struct V_25 * V_26 , struct V_54 * V_55 )
{
const struct V_208 * V_209 ;
struct V_258 args ;
struct V_148 V_149 ;
struct V_14 * V_15 [ V_259 + 1 ] ;
struct V_33 * V_34 ;
struct V_31 * V_32 ;
struct V_14 * V_96 ;
T_2 V_27 , V_28 ;
int V_29 , V_49 ;
V_49 = F_153 ( V_55 -> V_32 , sizeof( struct V_33 ) , V_15 ,
V_259 , V_260 ) ;
if ( V_49 < 0 )
return V_49 ;
V_49 = F_164 ( & V_149 , V_55 -> V_26 , V_55 -> V_32 , ( void * ) V_15 ) ;
if ( V_49 < 0 )
return V_49 ;
V_209 = F_140 ( V_149 . V_16 , V_15 [ V_261 ] ) ;
if ( F_42 ( V_209 ) )
return F_43 ( V_209 ) ;
V_29 = V_262 ;
V_29 |= V_5 << 8 ;
V_27 = F_31 ( V_55 -> V_26 ) . V_27 ;
V_28 = V_55 -> V_32 -> V_45 ;
V_32 = F_23 ( V_26 , V_27 , V_28 , V_29 , sizeof( struct V_33 ) ,
V_61 ) ;
if ( V_32 == NULL )
goto V_35;
V_34 = F_24 ( V_32 ) ;
V_34 -> V_36 = V_58 ;
V_34 -> V_37 = V_38 ;
V_34 -> V_39 = 0 ;
if ( F_25 ( V_26 , V_250 , V_149 . V_16 -> V_17 ) )
goto V_35;
if ( F_25 ( V_26 , V_261 , V_209 -> V_17 ) )
goto V_35;
V_96 = F_69 ( V_26 , V_263 ) ;
if ( V_96 == NULL )
goto V_35;
args . V_55 = V_55 ;
args . V_26 = V_26 ;
args . V_239 . V_246 = V_55 -> args [ 0 ] ;
args . V_239 . V_247 = 0 ;
args . V_239 . V_49 = 0 ;
args . V_239 . V_248 = F_168 ;
V_209 -> V_76 -> V_249 ( & V_149 , V_209 , & args . V_239 ) ;
F_72 ( V_26 , V_96 ) ;
F_28 ( V_26 , V_32 ) ;
if ( args . V_239 . V_49 && args . V_239 . V_49 != - V_257 )
return args . V_239 . V_49 ;
if ( args . V_239 . V_247 == V_55 -> args [ 0 ] )
return 0 ;
V_55 -> args [ 0 ] = args . V_239 . V_247 ;
return V_26 -> V_63 ;
V_35:
return - V_103 ;
}
static int F_171 ( struct V_64 * V_65 , struct V_25 * V_26 ,
const struct V_31 * V_32 ,
const struct V_14 * const V_15 [] )
{
const struct V_208 * V_209 ;
struct V_148 V_149 ;
int V_49 ;
V_49 = F_164 ( & V_149 , V_26 , V_32 , V_15 ) ;
if ( V_49 < 0 )
return V_49 ;
V_209 = F_140 ( V_149 . V_16 , V_15 [ V_261 ] ) ;
if ( F_42 ( V_209 ) )
return F_43 ( V_209 ) ;
if ( V_32 -> V_67 & V_68 ) {
struct V_69 V_70 = {
. V_71 = F_170 ,
} ;
return F_41 ( V_65 , V_26 , V_32 , & V_70 ) ;
}
return - V_83 ;
}
static int F_172 ( const struct V_148 * V_149 , struct V_208 * V_209 ,
const struct V_14 * V_119 )
{
struct V_14 * V_15 [ V_264 + 1 ] ;
struct V_265 V_266 , V_267 ;
struct V_240 V_178 ;
struct V_243 * V_244 ;
enum V_241 V_242 ;
int V_49 ;
V_49 = F_78 ( V_15 , V_264 , V_119 ,
V_268 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( V_15 [ V_252 ] == NULL )
return - V_18 ;
V_178 . V_30 = 0 ;
if ( V_15 [ V_256 ] != NULL ) {
V_178 . V_30 = F_52 ( F_53 ( V_15 [ V_256 ] ) ) ;
if ( V_178 . V_30 & ~ V_254 )
return - V_18 ;
}
if ( V_209 -> V_30 & V_206 ) {
if ( V_15 [ V_255 ] == NULL &&
! ( V_178 . V_30 & V_254 ) )
return - V_18 ;
if ( V_15 [ V_255 ] != NULL &&
V_178 . V_30 & V_254 )
return - V_18 ;
} else {
if ( V_15 [ V_255 ] != NULL )
return - V_18 ;
}
V_49 = F_173 ( V_149 , & V_178 . V_253 , & V_266 , V_15 [ V_252 ] ) ;
if ( V_49 < 0 )
goto V_163;
V_49 = - V_18 ;
if ( V_266 . type != V_229 || V_266 . V_63 != V_209 -> V_220 )
goto V_199;
V_49 = - V_81 ;
if ( V_209 -> V_76 -> V_269 ( V_209 , & V_178 ) == 0 )
goto V_199;
if ( V_15 [ V_255 ] != NULL ) {
V_49 = F_173 ( V_149 , & V_178 . V_155 , & V_267 , V_15 [ V_255 ] ) ;
if ( V_49 < 0 )
goto V_199;
V_49 = - V_18 ;
if ( V_209 -> V_222 != V_234 && V_267 . V_63 != V_209 -> V_198 )
goto V_200;
V_242 = F_160 ( V_209 -> V_222 ) ;
F_9 (binding, &set->bindings, list) {
struct V_148 V_270 = {
. V_3 = V_149 -> V_3 ,
. V_16 = V_149 -> V_16 ,
. V_74 = V_244 -> V_74 ,
} ;
V_49 = F_161 ( & V_270 , V_242 ,
& V_178 . V_155 , V_267 . type ) ;
if ( V_49 < 0 )
goto V_200;
}
}
V_49 = V_209 -> V_76 -> V_271 ( V_209 , & V_178 ) ;
if ( V_49 < 0 )
goto V_200;
return 0 ;
V_200:
if ( V_15 [ V_255 ] != NULL )
F_174 ( & V_178 . V_155 , V_267 . type ) ;
V_199:
F_174 ( & V_178 . V_253 , V_266 . type ) ;
V_163:
return V_49 ;
}
static int F_175 ( struct V_64 * V_65 , struct V_25 * V_26 ,
const struct V_31 * V_32 ,
const struct V_14 * const V_15 [] )
{
const struct V_14 * V_119 ;
struct V_208 * V_209 ;
struct V_148 V_149 ;
int V_195 , V_49 ;
V_49 = F_164 ( & V_149 , V_26 , V_32 , V_15 ) ;
if ( V_49 < 0 )
return V_49 ;
V_209 = F_140 ( V_149 . V_16 , V_15 [ V_261 ] ) ;
if ( F_42 ( V_209 ) )
return F_43 ( V_209 ) ;
if ( ! F_60 ( & V_209 -> V_236 ) && V_209 -> V_30 & V_233 )
return - V_87 ;
F_124 (attr, nla[NFTA_SET_ELEM_LIST_ELEMENTS], rem) {
V_49 = F_172 ( & V_149 , V_209 , V_119 ) ;
if ( V_49 < 0 )
return V_49 ;
}
return 0 ;
}
static int F_176 ( const struct V_148 * V_149 , struct V_208 * V_209 ,
const struct V_14 * V_119 )
{
struct V_14 * V_15 [ V_264 + 1 ] ;
struct V_265 V_272 ;
struct V_240 V_178 ;
int V_49 ;
V_49 = F_78 ( V_15 , V_264 , V_119 ,
V_268 ) ;
if ( V_49 < 0 )
goto V_163;
V_49 = - V_18 ;
if ( V_15 [ V_252 ] == NULL )
goto V_163;
V_49 = F_173 ( V_149 , & V_178 . V_253 , & V_272 , V_15 [ V_252 ] ) ;
if ( V_49 < 0 )
goto V_163;
V_49 = - V_18 ;
if ( V_272 . type != V_229 || V_272 . V_63 != V_209 -> V_220 )
goto V_199;
V_49 = V_209 -> V_76 -> V_269 ( V_209 , & V_178 ) ;
if ( V_49 < 0 )
goto V_199;
V_209 -> V_76 -> remove ( V_209 , & V_178 ) ;
F_174 ( & V_178 . V_253 , V_229 ) ;
if ( V_209 -> V_30 & V_206 )
F_174 ( & V_178 . V_155 , V_209 -> V_222 ) ;
V_199:
F_174 ( & V_178 . V_253 , V_272 . type ) ;
V_163:
return V_49 ;
}
static int F_177 ( struct V_64 * V_65 , struct V_25 * V_26 ,
const struct V_31 * V_32 ,
const struct V_14 * const V_15 [] )
{
const struct V_14 * V_119 ;
struct V_208 * V_209 ;
struct V_148 V_149 ;
int V_195 , V_49 ;
V_49 = F_164 ( & V_149 , V_26 , V_32 , V_15 ) ;
if ( V_49 < 0 )
return V_49 ;
V_209 = F_140 ( V_149 . V_16 , V_15 [ V_261 ] ) ;
if ( F_42 ( V_209 ) )
return F_43 ( V_209 ) ;
if ( ! F_60 ( & V_209 -> V_236 ) && V_209 -> V_30 & V_233 )
return - V_87 ;
F_124 (attr, nla[NFTA_SET_ELEM_LIST_ELEMENTS], rem) {
V_49 = F_176 ( & V_149 , V_209 , V_119 ) ;
if ( V_49 < 0 )
return V_49 ;
}
return 0 ;
}
static int F_178 ( const struct V_148 * V_149 ,
const struct V_208 * V_209 ,
const struct V_238 * V_239 ,
const struct V_240 * V_178 )
{
if ( V_178 -> V_30 & V_254 )
return 0 ;
switch ( V_178 -> V_155 . V_273 ) {
case V_274 :
case V_275 :
return F_179 ( V_149 , V_178 -> V_155 . V_74 ) ;
default:
return 0 ;
}
}
static int F_179 ( const struct V_148 * V_149 ,
const struct V_73 * V_74 )
{
const struct V_167 * V_168 ;
const struct V_152 * V_153 , * V_276 ;
const struct V_208 * V_209 ;
struct V_243 * V_244 ;
struct V_238 V_239 ;
if ( V_149 -> V_74 == V_74 )
return - V_277 ;
F_9 (rule, &chain->rules, list) {
F_104 (expr, last, rule) {
const struct V_231 * V_155 = NULL ;
int V_49 ;
if ( ! V_153 -> V_76 -> V_278 )
continue;
V_49 = V_153 -> V_76 -> V_278 ( V_149 , V_153 , & V_155 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( V_155 == NULL )
continue;
switch ( V_155 -> V_273 ) {
case V_274 :
case V_275 :
V_49 = F_179 ( V_149 , V_155 -> V_74 ) ;
if ( V_49 < 0 )
return V_49 ;
default:
break;
}
}
}
F_9 (set, &ctx->table->sets, list) {
if ( ! ( V_209 -> V_30 & V_206 ) ||
V_209 -> V_222 != V_234 )
continue;
F_9 (binding, &set->bindings, list) {
if ( V_244 -> V_74 != V_74 )
continue;
V_239 . V_246 = 0 ;
V_239 . V_247 = 0 ;
V_239 . V_49 = 0 ;
V_239 . V_248 = F_178 ;
V_209 -> V_76 -> V_249 ( V_149 , V_209 , & V_239 ) ;
if ( V_239 . V_49 < 0 )
return V_239 . V_49 ;
}
}
return 0 ;
}
int F_180 ( enum V_241 V_279 )
{
if ( V_279 <= V_280 )
return - V_18 ;
if ( V_279 > V_281 )
return - V_282 ;
return 0 ;
}
int F_181 ( enum V_241 V_279 )
{
if ( V_279 < V_280 )
return - V_18 ;
if ( V_279 > V_281 )
return - V_282 ;
return 0 ;
}
int F_161 ( const struct V_148 * V_149 , enum V_241 V_279 ,
const struct V_231 * V_155 ,
enum V_283 type )
{
int V_49 ;
switch ( V_279 ) {
case V_280 :
if ( V_155 == NULL || type != V_234 )
return - V_18 ;
if ( V_155 -> V_273 == V_275 || V_155 -> V_273 == V_274 ) {
V_49 = F_179 ( V_149 , V_155 -> V_74 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( V_149 -> V_74 -> V_284 + 1 > V_155 -> V_74 -> V_284 ) {
if ( V_149 -> V_74 -> V_284 + 1 == V_285 )
return - V_286 ;
V_155 -> V_74 -> V_284 = V_149 -> V_74 -> V_284 + 1 ;
}
}
return 0 ;
default:
if ( V_155 != NULL && type != V_229 )
return - V_18 ;
return 0 ;
}
}
static int F_182 ( const struct V_148 * V_149 , struct V_231 * V_155 ,
struct V_265 * V_272 , const struct V_14 * V_15 )
{
struct V_14 * V_120 [ V_287 + 1 ] ;
struct V_73 * V_74 ;
int V_49 ;
V_49 = F_78 ( V_120 , V_287 , V_15 , V_288 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( ! V_120 [ V_289 ] )
return - V_18 ;
V_155 -> V_273 = F_52 ( F_53 ( V_120 [ V_289 ] ) ) ;
switch ( V_155 -> V_273 ) {
default:
switch ( V_155 -> V_273 & V_290 ) {
case V_128 :
case V_131 :
case V_291 :
break;
default:
return - V_18 ;
}
case V_292 :
case V_293 :
case V_294 :
V_272 -> V_63 = sizeof( V_155 -> V_273 ) ;
break;
case V_274 :
case V_275 :
if ( ! V_120 [ V_295 ] )
return - V_18 ;
V_74 = F_65 ( V_149 -> V_16 ,
V_120 [ V_295 ] ) ;
if ( F_42 ( V_74 ) )
return F_43 ( V_74 ) ;
if ( V_74 -> V_30 & V_75 )
return - V_83 ;
V_74 -> V_43 ++ ;
V_155 -> V_74 = V_74 ;
V_272 -> V_63 = sizeof( V_155 ) ;
break;
}
V_272 -> type = V_234 ;
return 0 ;
}
static void F_183 ( const struct V_231 * V_155 )
{
switch ( V_155 -> V_273 ) {
case V_274 :
case V_275 :
V_155 -> V_74 -> V_43 -- ;
break;
}
}
static int F_184 ( struct V_25 * V_26 , const struct V_231 * V_155 )
{
struct V_14 * V_96 ;
V_96 = F_69 ( V_26 , V_296 ) ;
if ( ! V_96 )
goto V_35;
if ( F_26 ( V_26 , V_289 , F_27 ( V_155 -> V_273 ) ) )
goto V_35;
switch ( V_155 -> V_273 ) {
case V_274 :
case V_275 :
if ( F_25 ( V_26 , V_295 , V_155 -> V_74 -> V_17 ) )
goto V_35;
}
F_72 ( V_26 , V_96 ) ;
return 0 ;
V_35:
return - 1 ;
}
static int F_185 ( const struct V_148 * V_149 , struct V_231 * V_155 ,
struct V_265 * V_272 , const struct V_14 * V_15 )
{
unsigned int V_63 ;
V_63 = F_20 ( V_15 ) ;
if ( V_63 == 0 )
return - V_18 ;
if ( V_63 > sizeof( V_155 -> V_155 ) )
return - V_135 ;
F_126 ( V_155 -> V_155 , V_15 , sizeof( V_155 -> V_155 ) ) ;
V_272 -> type = V_229 ;
V_272 -> V_63 = V_63 ;
return 0 ;
}
static int F_186 ( struct V_25 * V_26 , const struct V_231 * V_155 ,
unsigned int V_63 )
{
return F_105 ( V_26 , V_297 , V_63 , V_155 -> V_155 ) ;
}
int F_173 ( const struct V_148 * V_149 , struct V_231 * V_155 ,
struct V_265 * V_272 , const struct V_14 * V_15 )
{
struct V_14 * V_120 [ V_298 + 1 ] ;
int V_49 ;
V_49 = F_78 ( V_120 , V_298 , V_15 , V_299 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( V_120 [ V_297 ] )
return F_185 ( V_149 , V_155 , V_272 , V_120 [ V_297 ] ) ;
if ( V_120 [ V_296 ] && V_149 != NULL )
return F_182 ( V_149 , V_155 , V_272 , V_120 [ V_296 ] ) ;
return - V_18 ;
}
void F_174 ( const struct V_231 * V_155 , enum V_283 type )
{
switch ( type ) {
case V_229 :
return;
case V_234 :
return F_183 ( V_155 ) ;
default:
F_187 ( 1 ) ;
}
}
int F_167 ( struct V_25 * V_26 , int V_119 , const struct V_231 * V_155 ,
enum V_283 type , unsigned int V_63 )
{
struct V_14 * V_96 ;
int V_49 ;
V_96 = F_69 ( V_26 , V_119 ) ;
if ( V_96 == NULL )
return - 1 ;
switch ( type ) {
case V_229 :
V_49 = F_186 ( V_26 , V_155 , V_63 ) ;
break;
case V_234 :
V_49 = F_184 ( V_26 , V_155 ) ;
break;
default:
V_49 = - V_18 ;
F_187 ( 1 ) ;
}
F_72 ( V_26 , V_96 ) ;
return V_49 ;
}
static int F_188 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_7 . V_8 ) ;
F_2 ( & V_1 -> V_7 . V_189 ) ;
return 0 ;
}
static int T_7 F_189 ( void )
{
int V_49 ;
V_158 = F_122 ( sizeof( struct V_157 ) * V_197 ,
V_53 ) ;
if ( V_158 == NULL ) {
V_49 = - V_72 ;
goto V_163;
}
V_49 = F_190 () ;
if ( V_49 < 0 )
goto V_199;
V_49 = F_191 ( & V_300 ) ;
if ( V_49 < 0 )
goto V_200;
F_192 ( L_6 ) ;
return F_193 ( & V_301 ) ;
V_200:
F_194 () ;
V_199:
F_61 ( V_158 ) ;
V_163:
return V_49 ;
}
static void T_8 F_195 ( void )
{
F_196 ( & V_301 ) ;
F_197 ( & V_300 ) ;
F_194 () ;
F_61 ( V_158 ) ;
}
