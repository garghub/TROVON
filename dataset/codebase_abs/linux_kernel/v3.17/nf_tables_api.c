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
static void F_14 ( struct V_13 * V_14 ,
const struct V_15 * V_16 ,
const struct V_17 * V_18 ,
struct V_2 * V_3 ,
struct V_19 * V_20 ,
struct V_21 * V_22 ,
const struct V_23 * const * V_24 )
{
V_14 -> V_1 = F_15 ( V_16 -> V_25 ) ;
V_14 -> V_3 = V_3 ;
V_14 -> V_20 = V_20 ;
V_14 -> V_22 = V_22 ;
V_14 -> V_24 = V_24 ;
V_14 -> V_26 = F_16 ( V_16 ) . V_26 ;
V_14 -> V_27 = F_17 ( V_18 ) ;
V_14 -> V_28 = V_18 -> V_29 ;
}
static struct V_30 * F_18 ( struct V_13 * V_14 , int V_31 ,
T_1 V_32 )
{
struct V_30 * V_33 ;
V_33 = F_19 ( sizeof( struct V_30 ) + V_32 , V_34 ) ;
if ( V_33 == NULL )
return NULL ;
V_33 -> V_31 = V_31 ;
V_33 -> V_14 = * V_14 ;
return V_33 ;
}
static void F_20 ( struct V_30 * V_33 )
{
F_21 ( & V_33 -> V_6 ) ;
F_22 ( V_33 ) ;
}
static struct V_19 * F_23 ( const struct V_2 * V_3 ,
const struct V_23 * V_24 )
{
struct V_19 * V_20 ;
F_9 (table, &afi->tables, list) {
if ( ! F_24 ( V_24 , V_20 -> V_35 ) )
return V_20 ;
}
return NULL ;
}
static struct V_19 * F_25 ( const struct V_2 * V_3 ,
const struct V_23 * V_24 )
{
struct V_19 * V_20 ;
if ( V_24 == NULL )
return F_13 ( - V_36 ) ;
V_20 = F_23 ( V_3 , V_24 ) ;
if ( V_20 != NULL )
return V_20 ;
return F_13 ( - V_37 ) ;
}
static inline T_2 F_26 ( struct V_19 * V_20 )
{
return ++ V_20 -> V_38 ;
}
static const struct V_39 *
F_27 ( int V_9 , const struct V_23 * V_24 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_41 ; V_40 ++ ) {
if ( V_42 [ V_9 ] [ V_40 ] != NULL &&
! F_24 ( V_24 , V_42 [ V_9 ] [ V_40 ] -> V_35 ) )
return V_42 [ V_9 ] [ V_40 ] ;
}
return NULL ;
}
static const struct V_39 *
F_28 ( const struct V_2 * V_3 ,
const struct V_23 * V_24 ,
bool V_10 )
{
const struct V_39 * type ;
type = F_27 ( V_3 -> V_9 , V_24 ) ;
if ( type != NULL )
return type ;
#ifdef F_11
if ( V_10 ) {
F_5 ( V_5 ) ;
F_12 ( L_2 , V_3 -> V_9 ,
F_29 ( V_24 ) , ( const char * ) F_30 ( V_24 ) ) ;
F_3 ( V_5 ) ;
type = F_27 ( V_3 -> V_9 , V_24 ) ;
if ( type != NULL )
return F_13 ( - V_11 ) ;
}
#endif
return F_13 ( - V_37 ) ;
}
static int F_31 ( struct V_15 * V_16 , T_1 V_26 , T_1 V_28 ,
int V_43 , T_1 V_44 , int V_9 ,
const struct V_19 * V_20 )
{
struct V_17 * V_18 ;
struct V_45 * V_46 ;
V_43 |= V_5 << 8 ;
V_18 = F_32 ( V_16 , V_26 , V_28 , V_43 , sizeof( struct V_45 ) , V_44 ) ;
if ( V_18 == NULL )
goto V_47;
V_46 = F_33 ( V_18 ) ;
V_46 -> V_48 = V_9 ;
V_46 -> V_49 = V_50 ;
V_46 -> V_51 = 0 ;
if ( F_34 ( V_16 , V_52 , V_20 -> V_35 ) ||
F_35 ( V_16 , V_53 , F_36 ( V_20 -> V_44 ) ) ||
F_35 ( V_16 , V_54 , F_36 ( V_20 -> V_55 ) ) )
goto V_47;
return F_37 ( V_16 , V_18 ) ;
V_47:
F_38 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_39 ( const struct V_13 * V_14 , int V_43 )
{
struct V_15 * V_16 ;
int V_56 ;
if ( ! V_14 -> V_27 &&
! F_40 ( V_14 -> V_1 , V_57 ) )
return 0 ;
V_56 = - V_58 ;
V_16 = F_41 ( V_59 , V_34 ) ;
if ( V_16 == NULL )
goto V_56;
V_56 = F_31 ( V_16 , V_14 -> V_26 , V_14 -> V_28 , V_43 , 0 ,
V_14 -> V_3 -> V_9 , V_14 -> V_20 ) ;
if ( V_56 < 0 ) {
F_42 ( V_16 ) ;
goto V_56;
}
V_56 = F_43 ( V_16 , V_14 -> V_1 , V_14 -> V_26 , V_57 ,
V_14 -> V_27 , V_34 ) ;
V_56:
if ( V_56 < 0 ) {
F_44 ( V_14 -> V_1 , V_14 -> V_26 , V_57 ,
V_56 ) ;
}
return V_56 ;
}
static int F_45 ( struct V_15 * V_16 ,
struct V_60 * V_61 )
{
const struct V_45 * V_46 = F_33 ( V_61 -> V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
unsigned int V_62 = 0 , V_63 = V_61 -> args [ 0 ] ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_46 -> V_48 ;
F_46 () ;
V_61 -> V_28 = V_1 -> V_7 . V_64 ;
F_47 (afi, &net->nft.af_info, list) {
if ( V_9 != V_65 && V_9 != V_3 -> V_9 )
continue;
F_47 (table, &afi->tables, list) {
if ( V_62 < V_63 )
goto V_66;
if ( V_62 > V_63 )
memset ( & V_61 -> args [ 1 ] , 0 ,
sizeof( V_61 -> args ) - sizeof( V_61 -> args [ 0 ] ) ) ;
if ( F_31 ( V_16 ,
F_16 ( V_61 -> V_16 ) . V_26 ,
V_61 -> V_18 -> V_29 ,
V_67 ,
V_68 ,
V_3 -> V_9 , V_20 ) < 0 )
goto V_69;
F_48 ( V_61 , F_49 ( V_16 ) ) ;
V_66:
V_62 ++ ;
}
}
V_69:
F_50 () ;
V_61 -> args [ 0 ] = V_62 ;
return V_16 -> V_70 ;
}
static int F_51 ( struct V_71 * V_72 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_45 * V_46 = F_33 ( V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
struct V_15 * V_73 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_46 -> V_48 ;
int V_56 ;
if ( V_18 -> V_74 & V_75 ) {
struct V_76 V_77 = {
. V_78 = F_45 ,
} ;
return F_52 ( V_72 , V_16 , V_18 , & V_77 ) ;
}
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_53 ( V_3 ) )
return F_54 ( V_3 ) ;
V_20 = F_25 ( V_3 , V_24 [ V_52 ] ) ;
if ( F_53 ( V_20 ) )
return F_54 ( V_20 ) ;
if ( V_20 -> V_44 & V_79 )
return - V_37 ;
V_73 = F_55 ( V_59 , V_34 ) ;
if ( ! V_73 )
return - V_80 ;
V_56 = F_31 ( V_73 , F_16 ( V_16 ) . V_26 ,
V_18 -> V_29 , V_67 , 0 ,
V_9 , V_20 ) ;
if ( V_56 < 0 )
goto V_56;
return F_56 ( V_72 , V_73 , F_16 ( V_16 ) . V_26 ) ;
V_56:
F_42 ( V_73 ) ;
return V_56 ;
}
static int F_57 ( const struct V_2 * V_3 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 ;
int V_56 , V_40 = 0 ;
F_9 (chain, &table->chains, list) {
if ( ! ( V_22 -> V_44 & V_81 ) )
continue;
V_56 = F_58 ( F_59 ( V_22 ) -> V_82 , V_3 -> V_83 ) ;
if ( V_56 < 0 )
goto V_56;
V_40 ++ ;
}
return 0 ;
V_56:
F_9 (chain, &table->chains, list) {
if ( ! ( V_22 -> V_44 & V_81 ) )
continue;
if ( V_40 -- <= 0 )
break;
F_60 ( F_59 ( V_22 ) -> V_82 , V_3 -> V_83 ) ;
}
return V_56 ;
}
static void F_61 ( const struct V_2 * V_3 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 ;
F_9 (chain, &table->chains, list) {
if ( V_22 -> V_44 & V_81 )
F_60 ( F_59 ( V_22 ) -> V_82 ,
V_3 -> V_83 ) ;
}
}
static int F_62 ( struct V_13 * V_14 )
{
struct V_30 * V_33 ;
T_1 V_44 ;
int V_84 = 0 ;
if ( ! V_14 -> V_24 [ V_53 ] )
return 0 ;
V_44 = F_63 ( F_64 ( V_14 -> V_24 [ V_53 ] ) ) ;
if ( V_44 & ~ V_85 )
return - V_36 ;
if ( V_44 == V_14 -> V_20 -> V_44 )
return 0 ;
V_33 = F_18 ( V_14 , V_67 ,
sizeof( struct V_86 ) ) ;
if ( V_33 == NULL )
return - V_80 ;
if ( ( V_44 & V_85 ) &&
! ( V_14 -> V_20 -> V_44 & V_85 ) ) {
F_65 ( V_33 ) = false ;
} else if ( ! ( V_44 & V_85 ) &&
V_14 -> V_20 -> V_44 & V_85 ) {
V_84 = F_57 ( V_14 -> V_3 , V_14 -> V_20 ) ;
if ( V_84 >= 0 ) {
V_14 -> V_20 -> V_44 &= ~ V_85 ;
F_65 ( V_33 ) = true ;
}
}
if ( V_84 < 0 )
goto V_56;
F_66 ( V_33 ) = true ;
F_67 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_87 ) ;
return 0 ;
V_56:
F_20 ( V_33 ) ;
return V_84 ;
}
static int F_68 ( struct V_13 * V_14 , int V_31 )
{
struct V_30 * V_33 ;
V_33 = F_18 ( V_14 , V_31 , sizeof( struct V_86 ) ) ;
if ( V_33 == NULL )
return - V_80 ;
if ( V_31 == V_67 )
V_14 -> V_20 -> V_44 |= V_79 ;
F_67 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_87 ) ;
return 0 ;
}
static int F_69 ( struct V_71 * V_72 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_45 * V_46 = F_33 ( V_18 ) ;
const struct V_23 * V_35 ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_46 -> V_48 ;
T_1 V_44 = 0 ;
struct V_13 V_14 ;
int V_56 ;
V_3 = F_10 ( V_1 , V_9 , true ) ;
if ( F_53 ( V_3 ) )
return F_54 ( V_3 ) ;
V_35 = V_24 [ V_52 ] ;
V_20 = F_25 ( V_3 , V_35 ) ;
if ( F_53 ( V_20 ) ) {
if ( F_54 ( V_20 ) != - V_37 )
return F_54 ( V_20 ) ;
V_20 = NULL ;
}
if ( V_20 != NULL ) {
if ( V_20 -> V_44 & V_79 )
return - V_37 ;
if ( V_18 -> V_74 & V_88 )
return - V_89 ;
if ( V_18 -> V_74 & V_90 )
return - V_91 ;
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return F_62 ( & V_14 ) ;
}
if ( V_24 [ V_53 ] ) {
V_44 = F_63 ( F_64 ( V_24 [ V_53 ] ) ) ;
if ( V_44 & ~ V_85 )
return - V_36 ;
}
if ( ! F_70 ( V_3 -> V_92 ) )
return - V_12 ;
V_20 = F_19 ( sizeof( * V_20 ) + F_29 ( V_35 ) , V_34 ) ;
if ( V_20 == NULL ) {
F_71 ( V_3 -> V_92 ) ;
return - V_80 ;
}
F_72 ( V_20 -> V_35 , V_35 , F_29 ( V_35 ) ) ;
F_2 ( & V_20 -> V_93 ) ;
F_2 ( & V_20 -> V_94 ) ;
V_20 -> V_44 = V_44 ;
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
V_56 = F_68 ( & V_14 , V_67 ) ;
if ( V_56 < 0 ) {
F_22 ( V_20 ) ;
F_71 ( V_3 -> V_92 ) ;
return V_56 ;
}
F_4 ( & V_20 -> V_6 , & V_3 -> V_4 ) ;
return 0 ;
}
static int F_73 ( struct V_71 * V_72 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_45 * V_46 = F_33 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_46 -> V_48 , V_56 ;
struct V_13 V_14 ;
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_53 ( V_3 ) )
return F_54 ( V_3 ) ;
V_20 = F_25 ( V_3 , V_24 [ V_52 ] ) ;
if ( F_53 ( V_20 ) )
return F_54 ( V_20 ) ;
if ( V_20 -> V_44 & V_79 )
return - V_37 ;
if ( V_20 -> V_55 > 0 )
return - V_95 ;
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
V_56 = F_68 ( & V_14 , V_96 ) ;
if ( V_56 < 0 )
return V_56 ;
F_7 ( & V_20 -> V_6 ) ;
return 0 ;
}
static void F_74 ( struct V_13 * V_14 )
{
F_75 ( V_14 -> V_20 -> V_55 > 0 ) ;
F_22 ( V_14 -> V_20 ) ;
F_71 ( V_14 -> V_3 -> V_92 ) ;
}
int F_76 ( const struct V_39 * V_97 )
{
int V_56 = 0 ;
F_3 ( V_5 ) ;
if ( V_42 [ V_97 -> V_9 ] [ V_97 -> type ] != NULL ) {
V_56 = - V_95 ;
goto V_98;
}
V_42 [ V_97 -> V_9 ] [ V_97 -> type ] = V_97 ;
V_98:
F_5 ( V_5 ) ;
return V_56 ;
}
void F_77 ( const struct V_39 * V_97 )
{
F_3 ( V_5 ) ;
V_42 [ V_97 -> V_9 ] [ V_97 -> type ] = NULL ;
F_5 ( V_5 ) ;
}
static struct V_21 *
F_78 ( const struct V_19 * V_20 , T_2 V_99 )
{
struct V_21 * V_22 ;
F_9 (chain, &table->chains, list) {
if ( V_22 -> V_99 == V_99 )
return V_22 ;
}
return F_13 ( - V_37 ) ;
}
static struct V_21 * F_79 ( const struct V_19 * V_20 ,
const struct V_23 * V_24 )
{
struct V_21 * V_22 ;
if ( V_24 == NULL )
return F_13 ( - V_36 ) ;
F_9 (chain, &table->chains, list) {
if ( ! F_24 ( V_24 , V_22 -> V_35 ) )
return V_22 ;
}
return F_13 ( - V_37 ) ;
}
static int F_80 ( struct V_15 * V_16 , struct V_100 T_3 * V_101 )
{
struct V_100 * V_102 , V_103 ;
struct V_23 * V_104 ;
unsigned int V_28 ;
T_2 V_105 , V_106 ;
int V_107 ;
memset ( & V_103 , 0 , sizeof( V_103 ) ) ;
F_81 (cpu) {
V_102 = F_82 ( V_101 , V_107 ) ;
do {
V_28 = F_83 ( & V_102 -> V_108 ) ;
V_105 = V_102 -> V_105 ;
V_106 = V_102 -> V_106 ;
} while ( F_84 ( & V_102 -> V_108 , V_28 ) );
V_103 . V_105 += V_105 ;
V_103 . V_106 += V_106 ;
}
V_104 = F_85 ( V_16 , V_109 ) ;
if ( V_104 == NULL )
goto V_47;
if ( F_86 ( V_16 , V_110 , F_87 ( V_103 . V_105 ) ) ||
F_86 ( V_16 , V_111 , F_87 ( V_103 . V_106 ) ) )
goto V_47;
F_88 ( V_16 , V_104 ) ;
return 0 ;
V_47:
return - V_112 ;
}
static int F_89 ( struct V_15 * V_16 , T_1 V_26 , T_1 V_28 ,
int V_43 , T_1 V_44 , int V_9 ,
const struct V_19 * V_20 ,
const struct V_21 * V_22 )
{
struct V_17 * V_18 ;
struct V_45 * V_46 ;
V_43 |= V_5 << 8 ;
V_18 = F_32 ( V_16 , V_26 , V_28 , V_43 , sizeof( struct V_45 ) , V_44 ) ;
if ( V_18 == NULL )
goto V_47;
V_46 = F_33 ( V_18 ) ;
V_46 -> V_48 = V_9 ;
V_46 -> V_49 = V_50 ;
V_46 -> V_51 = 0 ;
if ( F_34 ( V_16 , V_113 , V_20 -> V_35 ) )
goto V_47;
if ( F_86 ( V_16 , V_114 , F_87 ( V_22 -> V_99 ) ) )
goto V_47;
if ( F_34 ( V_16 , V_115 , V_22 -> V_35 ) )
goto V_47;
if ( V_22 -> V_44 & V_81 ) {
const struct F_59 * V_116 = F_59 ( V_22 ) ;
const struct V_117 * V_82 = & V_116 -> V_82 [ 0 ] ;
struct V_23 * V_104 ;
V_104 = F_85 ( V_16 , V_118 ) ;
if ( V_104 == NULL )
goto V_47;
if ( F_35 ( V_16 , V_119 , F_36 ( V_82 -> V_120 ) ) )
goto V_47;
if ( F_35 ( V_16 , V_121 , F_36 ( V_82 -> V_122 ) ) )
goto V_47;
F_88 ( V_16 , V_104 ) ;
if ( F_35 ( V_16 , V_123 ,
F_36 ( V_116 -> V_124 ) ) )
goto V_47;
if ( F_34 ( V_16 , V_125 , V_116 -> type -> V_35 ) )
goto V_47;
if ( F_80 ( V_16 , F_59 ( V_22 ) -> V_101 ) )
goto V_47;
}
if ( F_35 ( V_16 , V_126 , F_36 ( V_22 -> V_55 ) ) )
goto V_47;
return F_37 ( V_16 , V_18 ) ;
V_47:
F_38 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_90 ( const struct V_13 * V_14 , int V_43 )
{
struct V_15 * V_16 ;
int V_56 ;
if ( ! V_14 -> V_27 &&
! F_40 ( V_14 -> V_1 , V_57 ) )
return 0 ;
V_56 = - V_58 ;
V_16 = F_41 ( V_59 , V_34 ) ;
if ( V_16 == NULL )
goto V_56;
V_56 = F_89 ( V_16 , V_14 -> V_26 , V_14 -> V_28 , V_43 , 0 ,
V_14 -> V_3 -> V_9 , V_14 -> V_20 ,
V_14 -> V_22 ) ;
if ( V_56 < 0 ) {
F_42 ( V_16 ) ;
goto V_56;
}
V_56 = F_43 ( V_16 , V_14 -> V_1 , V_14 -> V_26 , V_57 ,
V_14 -> V_27 , V_34 ) ;
V_56:
if ( V_56 < 0 ) {
F_44 ( V_14 -> V_1 , V_14 -> V_26 , V_57 ,
V_56 ) ;
}
return V_56 ;
}
static int F_91 ( struct V_15 * V_16 ,
struct V_60 * V_61 )
{
const struct V_45 * V_46 = F_33 ( V_61 -> V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
unsigned int V_62 = 0 , V_63 = V_61 -> args [ 0 ] ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_46 -> V_48 ;
F_46 () ;
V_61 -> V_28 = V_1 -> V_7 . V_64 ;
F_47 (afi, &net->nft.af_info, list) {
if ( V_9 != V_65 && V_9 != V_3 -> V_9 )
continue;
F_47 (table, &afi->tables, list) {
F_47 (chain, &table->chains, list) {
if ( V_62 < V_63 )
goto V_66;
if ( V_62 > V_63 )
memset ( & V_61 -> args [ 1 ] , 0 ,
sizeof( V_61 -> args ) - sizeof( V_61 -> args [ 0 ] ) ) ;
if ( F_89 ( V_16 , F_16 ( V_61 -> V_16 ) . V_26 ,
V_61 -> V_18 -> V_29 ,
V_127 ,
V_68 ,
V_3 -> V_9 , V_20 , V_22 ) < 0 )
goto V_69;
F_48 ( V_61 , F_49 ( V_16 ) ) ;
V_66:
V_62 ++ ;
}
}
}
V_69:
F_50 () ;
V_61 -> args [ 0 ] = V_62 ;
return V_16 -> V_70 ;
}
static int F_92 ( struct V_71 * V_72 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_45 * V_46 = F_33 ( V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
struct V_15 * V_73 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_46 -> V_48 ;
int V_56 ;
if ( V_18 -> V_74 & V_75 ) {
struct V_76 V_77 = {
. V_78 = F_91 ,
} ;
return F_52 ( V_72 , V_16 , V_18 , & V_77 ) ;
}
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_53 ( V_3 ) )
return F_54 ( V_3 ) ;
V_20 = F_25 ( V_3 , V_24 [ V_113 ] ) ;
if ( F_53 ( V_20 ) )
return F_54 ( V_20 ) ;
if ( V_20 -> V_44 & V_79 )
return - V_37 ;
V_22 = F_79 ( V_20 , V_24 [ V_115 ] ) ;
if ( F_53 ( V_22 ) )
return F_54 ( V_22 ) ;
if ( V_22 -> V_44 & V_128 )
return - V_37 ;
V_73 = F_55 ( V_59 , V_34 ) ;
if ( ! V_73 )
return - V_80 ;
V_56 = F_89 ( V_73 , F_16 ( V_16 ) . V_26 ,
V_18 -> V_29 , V_127 , 0 ,
V_9 , V_20 , V_22 ) ;
if ( V_56 < 0 )
goto V_56;
return F_56 ( V_72 , V_73 , F_16 ( V_16 ) . V_26 ) ;
V_56:
F_42 ( V_73 ) ;
return V_56 ;
}
static struct V_100 T_3 * F_93 ( const struct V_23 * V_129 )
{
struct V_23 * V_130 [ V_131 + 1 ] ;
struct V_100 T_3 * V_132 ;
struct V_100 * V_101 ;
int V_56 ;
V_56 = F_94 ( V_130 , V_131 , V_129 , V_133 ) ;
if ( V_56 < 0 )
return F_13 ( V_56 ) ;
if ( ! V_130 [ V_111 ] || ! V_130 [ V_110 ] )
return F_13 ( - V_36 ) ;
V_132 = F_95 ( struct V_100 ) ;
if ( V_132 == NULL )
return F_13 ( - V_80 ) ;
V_101 = F_96 ( V_132 ) ;
V_101 -> V_106 = F_97 ( F_98 ( V_130 [ V_111 ] ) ) ;
V_101 -> V_105 = F_97 ( F_98 ( V_130 [ V_110 ] ) ) ;
return V_132 ;
}
static void F_99 ( struct F_59 * V_22 ,
struct V_100 T_3 * V_132 )
{
if ( V_132 == NULL )
return;
if ( V_22 -> V_101 ) {
struct V_100 T_3 * V_134 =
F_100 ( V_22 -> V_101 ) ;
F_101 ( V_22 -> V_101 , V_132 ) ;
F_102 () ;
F_103 ( V_134 ) ;
} else
F_101 ( V_22 -> V_101 , V_132 ) ;
}
static int F_104 ( struct V_13 * V_14 , int V_31 )
{
struct V_30 * V_33 ;
V_33 = F_18 ( V_14 , V_31 , sizeof( struct V_135 ) ) ;
if ( V_33 == NULL )
return - V_80 ;
if ( V_31 == V_127 )
V_14 -> V_22 -> V_44 |= V_128 ;
F_67 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_87 ) ;
return 0 ;
}
static void F_105 ( struct V_21 * V_22 )
{
F_75 ( V_22 -> V_55 > 0 ) ;
if ( V_22 -> V_44 & V_81 ) {
F_71 ( F_59 ( V_22 ) -> type -> V_92 ) ;
F_103 ( F_59 ( V_22 ) -> V_101 ) ;
F_22 ( F_59 ( V_22 ) ) ;
} else {
F_22 ( V_22 ) ;
}
}
static int F_106 ( struct V_71 * V_72 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_45 * V_46 = F_33 ( V_18 ) ;
const struct V_23 * V_136 ( V_35 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct F_59 * V_116 = NULL ;
struct V_23 * V_137 [ V_138 + 1 ] ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_46 -> V_48 ;
T_4 V_124 = V_139 ;
T_2 V_99 = 0 ;
unsigned int V_40 ;
struct V_100 T_3 * V_101 ;
int V_56 ;
bool V_140 ;
struct V_13 V_14 ;
V_140 = V_18 -> V_74 & V_141 ? true : false ;
V_3 = F_10 ( V_1 , V_9 , true ) ;
if ( F_53 ( V_3 ) )
return F_54 ( V_3 ) ;
V_20 = F_25 ( V_3 , V_24 [ V_113 ] ) ;
if ( F_53 ( V_20 ) )
return F_54 ( V_20 ) ;
V_22 = NULL ;
V_35 = V_24 [ V_115 ] ;
if ( V_24 [ V_114 ] ) {
V_99 = F_97 ( F_98 ( V_24 [ V_114 ] ) ) ;
V_22 = F_78 ( V_20 , V_99 ) ;
if ( F_53 ( V_22 ) )
return F_54 ( V_22 ) ;
} else {
V_22 = F_79 ( V_20 , V_35 ) ;
if ( F_53 ( V_22 ) ) {
if ( F_54 ( V_22 ) != - V_37 )
return F_54 ( V_22 ) ;
V_22 = NULL ;
}
}
if ( V_24 [ V_123 ] ) {
if ( ( V_22 != NULL &&
! ( V_22 -> V_44 & V_81 ) ) ||
V_24 [ V_118 ] == NULL )
return - V_91 ;
V_124 = F_63 ( F_64 ( V_24 [ V_123 ] ) ) ;
switch ( V_124 ) {
case V_142 :
case V_139 :
break;
default:
return - V_36 ;
}
}
if ( V_22 != NULL ) {
struct V_100 * V_101 = NULL ;
struct V_30 * V_33 ;
if ( V_22 -> V_44 & V_128 )
return - V_37 ;
if ( V_18 -> V_74 & V_88 )
return - V_89 ;
if ( V_18 -> V_74 & V_90 )
return - V_91 ;
if ( V_24 [ V_114 ] && V_35 &&
! F_53 ( F_79 ( V_20 , V_24 [ V_115 ] ) ) )
return - V_89 ;
if ( V_24 [ V_109 ] ) {
if ( ! ( V_22 -> V_44 & V_81 ) )
return - V_91 ;
V_101 = F_93 ( V_24 [ V_109 ] ) ;
if ( F_53 ( V_101 ) )
return F_54 ( V_101 ) ;
}
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_33 = F_18 ( & V_14 , V_127 ,
sizeof( struct V_135 ) ) ;
if ( V_33 == NULL )
return - V_80 ;
F_107 ( V_33 ) = V_101 ;
F_108 ( V_33 ) = true ;
if ( V_24 [ V_123 ] )
F_109 ( V_33 ) = V_124 ;
else
F_109 ( V_33 ) = - 1 ;
if ( V_24 [ V_114 ] && V_35 ) {
F_72 ( F_110 ( V_33 ) , V_35 ,
V_143 ) ;
}
F_67 ( & V_33 -> V_6 , & V_1 -> V_7 . V_87 ) ;
return 0 ;
}
if ( V_20 -> V_55 == V_144 )
return - V_145 ;
if ( V_24 [ V_118 ] ) {
const struct V_39 * type ;
struct V_117 * V_82 ;
T_5 * V_146 ;
T_1 V_120 , V_122 ;
type = V_42 [ V_9 ] [ V_147 ] ;
if ( V_24 [ V_125 ] ) {
type = F_28 ( V_3 ,
V_24 [ V_125 ] ,
V_140 ) ;
if ( F_53 ( type ) )
return F_54 ( type ) ;
}
V_56 = F_94 ( V_137 , V_138 , V_24 [ V_118 ] ,
V_148 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_137 [ V_119 ] == NULL ||
V_137 [ V_121 ] == NULL )
return - V_36 ;
V_120 = F_63 ( F_64 ( V_137 [ V_119 ] ) ) ;
if ( V_120 >= V_3 -> V_149 )
return - V_36 ;
V_122 = F_63 ( F_64 ( V_137 [ V_121 ] ) ) ;
if ( ! ( type -> V_150 & ( 1 << V_120 ) ) )
return - V_91 ;
if ( ! F_70 ( type -> V_92 ) )
return - V_37 ;
V_146 = type -> V_151 [ V_120 ] ;
V_116 = F_19 ( sizeof( * V_116 ) , V_34 ) ;
if ( V_116 == NULL )
return - V_80 ;
if ( V_24 [ V_109 ] ) {
V_101 = F_93 ( V_24 [ V_109 ] ) ;
if ( F_53 ( V_101 ) ) {
F_71 ( type -> V_92 ) ;
F_22 ( V_116 ) ;
return F_54 ( V_101 ) ;
}
V_116 -> V_101 = V_101 ;
} else {
V_101 = F_95 ( struct V_100 ) ;
if ( F_53 ( V_101 ) ) {
F_71 ( type -> V_92 ) ;
F_22 ( V_116 ) ;
return F_54 ( V_101 ) ;
}
F_101 ( V_116 -> V_101 , V_101 ) ;
}
V_116 -> type = type ;
V_22 = & V_116 -> V_22 ;
for ( V_40 = 0 ; V_40 < V_3 -> V_83 ; V_40 ++ ) {
V_82 = & V_116 -> V_82 [ V_40 ] ;
V_82 -> V_152 = V_9 ;
V_82 -> V_92 = V_3 -> V_92 ;
V_82 -> V_120 = V_120 ;
V_82 -> V_122 = V_122 ;
V_82 -> V_153 = V_22 ;
V_82 -> V_154 = V_3 -> V_151 [ V_82 -> V_120 ] ;
if ( V_146 )
V_82 -> V_154 = V_146 ;
if ( V_3 -> V_155 )
V_3 -> V_155 ( V_82 , V_40 ) ;
}
V_22 -> V_44 |= V_81 ;
V_116 -> V_124 = V_124 ;
} else {
V_22 = F_19 ( sizeof( * V_22 ) , V_34 ) ;
if ( V_22 == NULL )
return - V_80 ;
}
F_2 ( & V_22 -> V_156 ) ;
V_22 -> V_99 = F_26 ( V_20 ) ;
V_22 -> V_1 = V_1 ;
V_22 -> V_20 = V_20 ;
F_72 ( V_22 -> V_35 , V_35 , V_143 ) ;
if ( ! ( V_20 -> V_44 & V_85 ) &&
V_22 -> V_44 & V_81 ) {
V_56 = F_58 ( F_59 ( V_22 ) -> V_82 , V_3 -> V_83 ) ;
if ( V_56 < 0 )
goto V_157;
}
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_56 = F_104 ( & V_14 , V_127 ) ;
if ( V_56 < 0 )
goto V_158;
V_20 -> V_55 ++ ;
F_4 ( & V_22 -> V_6 , & V_20 -> V_93 ) ;
return 0 ;
V_158:
if ( ! ( V_20 -> V_44 & V_85 ) &&
V_22 -> V_44 & V_81 ) {
F_60 ( F_59 ( V_22 ) -> V_82 ,
V_3 -> V_83 ) ;
}
V_157:
F_105 ( V_22 ) ;
return V_56 ;
}
static int F_111 ( struct V_71 * V_72 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_45 * V_46 = F_33 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_46 -> V_48 ;
struct V_13 V_14 ;
int V_56 ;
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_53 ( V_3 ) )
return F_54 ( V_3 ) ;
V_20 = F_25 ( V_3 , V_24 [ V_113 ] ) ;
if ( F_53 ( V_20 ) )
return F_54 ( V_20 ) ;
if ( V_20 -> V_44 & V_79 )
return - V_37 ;
V_22 = F_79 ( V_20 , V_24 [ V_115 ] ) ;
if ( F_53 ( V_22 ) )
return F_54 ( V_22 ) ;
if ( V_22 -> V_44 & V_128 )
return - V_37 ;
if ( V_22 -> V_55 > 0 )
return - V_95 ;
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_56 = F_104 ( & V_14 , V_159 ) ;
if ( V_56 < 0 )
return V_56 ;
V_20 -> V_55 -- ;
F_7 ( & V_22 -> V_6 ) ;
return 0 ;
}
int F_112 ( struct V_160 * type )
{
F_3 ( V_5 ) ;
if ( type -> V_9 == V_65 )
F_4 ( & type -> V_6 , & V_161 ) ;
else
F_113 ( & type -> V_6 , & V_161 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_114 ( struct V_160 * type )
{
F_3 ( V_5 ) ;
F_7 ( & type -> V_6 ) ;
F_5 ( V_5 ) ;
}
static const struct V_160 * F_115 ( T_4 V_9 ,
struct V_23 * V_24 )
{
const struct V_160 * type ;
F_9 (type, &nf_tables_expressions, list) {
if ( ! F_24 ( V_24 , type -> V_35 ) &&
( ! type -> V_9 || type -> V_9 == V_9 ) )
return type ;
}
return NULL ;
}
static const struct V_160 * F_116 ( T_4 V_9 ,
struct V_23 * V_24 )
{
const struct V_160 * type ;
if ( V_24 == NULL )
return F_13 ( - V_36 ) ;
type = F_115 ( V_9 , V_24 ) ;
if ( type != NULL && F_70 ( type -> V_92 ) )
return type ;
#ifdef F_11
if ( type == NULL ) {
F_5 ( V_5 ) ;
F_12 ( L_3 , V_9 ,
F_29 ( V_24 ) , ( char * ) F_30 ( V_24 ) ) ;
F_3 ( V_5 ) ;
if ( F_115 ( V_9 , V_24 ) )
return F_13 ( - V_11 ) ;
F_5 ( V_5 ) ;
F_12 ( L_4 ,
F_29 ( V_24 ) , ( char * ) F_30 ( V_24 ) ) ;
F_3 ( V_5 ) ;
if ( F_115 ( V_9 , V_24 ) )
return F_13 ( - V_11 ) ;
}
#endif
return F_13 ( - V_37 ) ;
}
static int F_117 ( struct V_15 * V_16 ,
const struct V_162 * V_163 )
{
if ( F_34 ( V_16 , V_164 , V_163 -> V_82 -> type -> V_35 ) )
goto V_47;
if ( V_163 -> V_82 -> V_78 ) {
struct V_23 * V_165 = F_85 ( V_16 , V_166 ) ;
if ( V_165 == NULL )
goto V_47;
if ( V_163 -> V_82 -> V_78 ( V_16 , V_163 ) < 0 )
goto V_47;
F_88 ( V_16 , V_165 ) ;
}
return V_16 -> V_70 ;
V_47:
return - 1 ;
}
static int F_118 ( const struct V_13 * V_14 ,
const struct V_23 * V_24 ,
struct V_167 * V_168 )
{
const struct V_160 * type ;
const struct V_169 * V_82 ;
struct V_23 * V_130 [ V_170 + 1 ] ;
int V_56 ;
V_56 = F_94 ( V_130 , V_170 , V_24 , V_171 ) ;
if ( V_56 < 0 )
return V_56 ;
type = F_116 ( V_14 -> V_3 -> V_9 , V_130 [ V_164 ] ) ;
if ( F_53 ( type ) )
return F_54 ( type ) ;
if ( V_130 [ V_166 ] ) {
V_56 = F_94 ( V_168 -> V_130 , type -> V_172 ,
V_130 [ V_166 ] , type -> V_124 ) ;
if ( V_56 < 0 )
goto V_157;
} else
memset ( V_168 -> V_130 , 0 , sizeof( V_168 -> V_130 [ 0 ] ) * ( type -> V_172 + 1 ) ) ;
if ( type -> V_173 != NULL ) {
V_82 = type -> V_173 ( V_14 ,
( const struct V_23 * const * ) V_168 -> V_130 ) ;
if ( F_53 ( V_82 ) ) {
V_56 = F_54 ( V_82 ) ;
goto V_157;
}
} else
V_82 = type -> V_82 ;
V_168 -> V_82 = V_82 ;
return 0 ;
V_157:
F_71 ( type -> V_92 ) ;
return V_56 ;
}
static int F_119 ( const struct V_13 * V_14 ,
const struct V_167 * V_168 ,
struct V_162 * V_163 )
{
const struct V_169 * V_82 = V_168 -> V_82 ;
int V_56 ;
V_163 -> V_82 = V_82 ;
if ( V_82 -> V_174 ) {
V_56 = V_82 -> V_174 ( V_14 , V_163 , ( const struct V_23 * * ) V_168 -> V_130 ) ;
if ( V_56 < 0 )
goto V_157;
}
return 0 ;
V_157:
V_163 -> V_82 = NULL ;
return V_56 ;
}
static void F_120 ( const struct V_13 * V_14 ,
struct V_162 * V_163 )
{
if ( V_163 -> V_82 -> V_175 )
V_163 -> V_82 -> V_175 ( V_14 , V_163 ) ;
F_71 ( V_163 -> V_82 -> type -> V_92 ) ;
}
static struct V_176 * F_121 ( const struct V_21 * V_22 ,
T_2 V_99 )
{
struct V_176 * V_177 ;
F_9 (rule, &chain->rules, list) {
if ( V_99 == V_177 -> V_99 )
return V_177 ;
}
return F_13 ( - V_37 ) ;
}
static struct V_176 * F_122 ( const struct V_21 * V_22 ,
const struct V_23 * V_24 )
{
if ( V_24 == NULL )
return F_13 ( - V_36 ) ;
return F_121 ( V_22 , F_97 ( F_98 ( V_24 ) ) ) ;
}
static int F_123 ( struct V_15 * V_16 , T_1 V_26 , T_1 V_28 ,
int V_43 , T_1 V_44 , int V_9 ,
const struct V_19 * V_20 ,
const struct V_21 * V_22 ,
const struct V_176 * V_177 )
{
struct V_17 * V_18 ;
struct V_45 * V_46 ;
const struct V_162 * V_163 , * V_178 ;
struct V_23 * V_6 ;
const struct V_176 * V_179 ;
int type = V_43 | V_5 << 8 ;
V_18 = F_32 ( V_16 , V_26 , V_28 , type , sizeof( struct V_45 ) ,
V_44 ) ;
if ( V_18 == NULL )
goto V_47;
V_46 = F_33 ( V_18 ) ;
V_46 -> V_48 = V_9 ;
V_46 -> V_49 = V_50 ;
V_46 -> V_51 = 0 ;
if ( F_34 ( V_16 , V_180 , V_20 -> V_35 ) )
goto V_47;
if ( F_34 ( V_16 , V_181 , V_22 -> V_35 ) )
goto V_47;
if ( F_86 ( V_16 , V_182 , F_87 ( V_177 -> V_99 ) ) )
goto V_47;
if ( ( V_43 != V_183 ) && ( V_177 -> V_6 . V_184 != & V_22 -> V_156 ) ) {
V_179 = F_124 ( V_177 -> V_6 . V_184 , struct V_176 , V_6 ) ;
if ( F_86 ( V_16 , V_185 ,
F_87 ( V_179 -> V_99 ) ) )
goto V_47;
}
V_6 = F_85 ( V_16 , V_186 ) ;
if ( V_6 == NULL )
goto V_47;
F_125 (expr, next, rule) {
struct V_23 * V_187 = F_85 ( V_16 , V_188 ) ;
if ( V_187 == NULL )
goto V_47;
if ( F_117 ( V_16 , V_163 ) < 0 )
goto V_47;
F_88 ( V_16 , V_187 ) ;
}
F_88 ( V_16 , V_6 ) ;
if ( V_177 -> V_189 &&
F_126 ( V_16 , V_190 , V_177 -> V_189 , F_127 ( V_177 ) ) )
goto V_47;
return F_37 ( V_16 , V_18 ) ;
V_47:
F_38 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_128 ( const struct V_13 * V_14 ,
const struct V_176 * V_177 ,
int V_43 )
{
struct V_15 * V_16 ;
int V_56 ;
if ( ! V_14 -> V_27 &&
! F_40 ( V_14 -> V_1 , V_57 ) )
return 0 ;
V_56 = - V_58 ;
V_16 = F_41 ( V_59 , V_34 ) ;
if ( V_16 == NULL )
goto V_56;
V_56 = F_123 ( V_16 , V_14 -> V_26 , V_14 -> V_28 , V_43 , 0 ,
V_14 -> V_3 -> V_9 , V_14 -> V_20 ,
V_14 -> V_22 , V_177 ) ;
if ( V_56 < 0 ) {
F_42 ( V_16 ) ;
goto V_56;
}
V_56 = F_43 ( V_16 , V_14 -> V_1 , V_14 -> V_26 , V_57 ,
V_14 -> V_27 , V_34 ) ;
V_56:
if ( V_56 < 0 ) {
F_44 ( V_14 -> V_1 , V_14 -> V_26 , V_57 ,
V_56 ) ;
}
return V_56 ;
}
static inline bool
F_129 ( struct V_1 * V_1 , const struct V_176 * V_177 )
{
return ( V_177 -> V_191 & ( 1 << V_1 -> V_7 . V_192 ) ) == 0 ;
}
static inline int F_130 ( struct V_1 * V_1 )
{
return V_1 -> V_7 . V_192 + 1 == 1 ? 1 : 0 ;
}
static inline int
F_131 ( struct V_1 * V_1 , const struct V_176 * V_177 )
{
return ( V_177 -> V_191 & ( 1 << F_130 ( V_1 ) ) ) == 0 ;
}
static inline void
F_132 ( struct V_1 * V_1 , struct V_176 * V_177 )
{
V_177 -> V_191 = ( 1 << V_1 -> V_7 . V_192 ) ;
}
static inline void
F_133 ( struct V_1 * V_1 , struct V_176 * V_177 )
{
V_177 -> V_191 = ( 1 << F_130 ( V_1 ) ) ;
}
static inline void F_134 ( struct V_1 * V_1 , struct V_176 * V_177 )
{
V_177 -> V_191 = 0 ;
}
static int F_135 ( struct V_15 * V_16 ,
struct V_60 * V_61 )
{
const struct V_45 * V_46 = F_33 ( V_61 -> V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
const struct V_176 * V_177 ;
unsigned int V_62 = 0 , V_63 = V_61 -> args [ 0 ] ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_46 -> V_48 ;
F_46 () ;
V_61 -> V_28 = V_1 -> V_7 . V_64 ;
F_47 (afi, &net->nft.af_info, list) {
if ( V_9 != V_65 && V_9 != V_3 -> V_9 )
continue;
F_47 (table, &afi->tables, list) {
F_47 (chain, &table->chains, list) {
F_47 (rule, &chain->rules, list) {
if ( ! F_129 ( V_1 , V_177 ) )
goto V_66;
if ( V_62 < V_63 )
goto V_66;
if ( V_62 > V_63 )
memset ( & V_61 -> args [ 1 ] , 0 ,
sizeof( V_61 -> args ) - sizeof( V_61 -> args [ 0 ] ) ) ;
if ( F_123 ( V_16 , F_16 ( V_61 -> V_16 ) . V_26 ,
V_61 -> V_18 -> V_29 ,
V_193 ,
V_68 | V_194 ,
V_3 -> V_9 , V_20 , V_22 , V_177 ) < 0 )
goto V_69;
F_48 ( V_61 , F_49 ( V_16 ) ) ;
V_66:
V_62 ++ ;
}
}
}
}
V_69:
F_50 () ;
V_61 -> args [ 0 ] = V_62 ;
return V_16 -> V_70 ;
}
static int F_136 ( struct V_71 * V_72 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_45 * V_46 = F_33 ( V_18 ) ;
const struct V_2 * V_3 ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
const struct V_176 * V_177 ;
struct V_15 * V_73 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_9 = V_46 -> V_48 ;
int V_56 ;
if ( V_18 -> V_74 & V_75 ) {
struct V_76 V_77 = {
. V_78 = F_135 ,
} ;
return F_52 ( V_72 , V_16 , V_18 , & V_77 ) ;
}
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_53 ( V_3 ) )
return F_54 ( V_3 ) ;
V_20 = F_25 ( V_3 , V_24 [ V_180 ] ) ;
if ( F_53 ( V_20 ) )
return F_54 ( V_20 ) ;
if ( V_20 -> V_44 & V_79 )
return - V_37 ;
V_22 = F_79 ( V_20 , V_24 [ V_181 ] ) ;
if ( F_53 ( V_22 ) )
return F_54 ( V_22 ) ;
if ( V_22 -> V_44 & V_128 )
return - V_37 ;
V_177 = F_122 ( V_22 , V_24 [ V_182 ] ) ;
if ( F_53 ( V_177 ) )
return F_54 ( V_177 ) ;
V_73 = F_55 ( V_59 , V_34 ) ;
if ( ! V_73 )
return - V_80 ;
V_56 = F_123 ( V_73 , F_16 ( V_16 ) . V_26 ,
V_18 -> V_29 , V_193 , 0 ,
V_9 , V_20 , V_22 , V_177 ) ;
if ( V_56 < 0 )
goto V_56;
return F_56 ( V_72 , V_73 , F_16 ( V_16 ) . V_26 ) ;
V_56:
F_42 ( V_73 ) ;
return V_56 ;
}
static void F_137 ( const struct V_13 * V_14 ,
struct V_176 * V_177 )
{
struct V_162 * V_163 ;
V_163 = F_138 ( V_177 ) ;
while ( V_163 -> V_82 && V_163 != F_139 ( V_177 ) ) {
F_120 ( V_14 , V_163 ) ;
V_163 = F_140 ( V_163 ) ;
}
F_22 ( V_177 ) ;
}
static struct V_30 * F_141 ( struct V_13 * V_14 , int V_31 ,
struct V_176 * V_177 )
{
struct V_30 * V_33 ;
V_33 = F_18 ( V_14 , V_31 , sizeof( struct V_195 ) ) ;
if ( V_33 == NULL )
return NULL ;
V_195 ( V_33 ) = V_177 ;
F_67 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_87 ) ;
return V_33 ;
}
static int F_142 ( struct V_71 * V_72 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_45 * V_46 = F_33 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_176 * V_177 , * V_196 = NULL ;
struct V_30 * V_33 = NULL ;
struct V_162 * V_163 ;
struct V_13 V_14 ;
struct V_23 * V_197 ;
unsigned int V_32 , V_40 , V_198 , V_189 = 0 ;
int V_56 , V_199 ;
bool V_140 ;
T_2 V_99 , V_200 ;
V_140 = V_18 -> V_74 & V_141 ? true : false ;
V_3 = F_10 ( V_1 , V_46 -> V_48 , V_140 ) ;
if ( F_53 ( V_3 ) )
return F_54 ( V_3 ) ;
V_20 = F_25 ( V_3 , V_24 [ V_180 ] ) ;
if ( F_53 ( V_20 ) )
return F_54 ( V_20 ) ;
V_22 = F_79 ( V_20 , V_24 [ V_181 ] ) ;
if ( F_53 ( V_22 ) )
return F_54 ( V_22 ) ;
if ( V_24 [ V_182 ] ) {
V_99 = F_97 ( F_98 ( V_24 [ V_182 ] ) ) ;
V_177 = F_121 ( V_22 , V_99 ) ;
if ( F_53 ( V_177 ) )
return F_54 ( V_177 ) ;
if ( V_18 -> V_74 & V_88 )
return - V_89 ;
if ( V_18 -> V_74 & V_90 )
V_196 = V_177 ;
else
return - V_91 ;
} else {
if ( ! V_140 || V_18 -> V_74 & V_90 )
return - V_36 ;
V_99 = F_26 ( V_20 ) ;
if ( V_22 -> V_55 == V_144 )
return - V_145 ;
}
if ( V_24 [ V_185 ] ) {
if ( ! ( V_18 -> V_74 & V_141 ) )
return - V_91 ;
V_200 = F_97 ( F_98 ( V_24 [ V_185 ] ) ) ;
V_196 = F_121 ( V_22 , V_200 ) ;
if ( F_53 ( V_196 ) )
return F_54 ( V_196 ) ;
}
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
V_198 = 0 ;
V_32 = 0 ;
if ( V_24 [ V_186 ] ) {
F_143 (tmp, nla[NFTA_RULE_EXPRESSIONS], rem) {
V_56 = - V_36 ;
if ( F_144 ( V_197 ) != V_188 )
goto V_157;
if ( V_198 == V_201 )
goto V_157;
V_56 = F_118 ( & V_14 , V_197 , & V_168 [ V_198 ] ) ;
if ( V_56 < 0 )
goto V_157;
V_32 += V_168 [ V_198 ] . V_82 -> V_32 ;
V_198 ++ ;
}
}
if ( V_24 [ V_190 ] )
V_189 = F_29 ( V_24 [ V_190 ] ) ;
V_56 = - V_80 ;
V_177 = F_19 ( sizeof( * V_177 ) + V_32 + V_189 , V_34 ) ;
if ( V_177 == NULL )
goto V_157;
F_132 ( V_1 , V_177 ) ;
V_177 -> V_99 = V_99 ;
V_177 -> V_202 = V_32 ;
V_177 -> V_189 = V_189 ;
if ( V_189 )
F_145 ( F_127 ( V_177 ) , V_24 [ V_190 ] , V_189 ) ;
V_163 = F_138 ( V_177 ) ;
for ( V_40 = 0 ; V_40 < V_198 ; V_40 ++ ) {
V_56 = F_119 ( & V_14 , & V_168 [ V_40 ] , V_163 ) ;
if ( V_56 < 0 )
goto V_158;
V_168 [ V_40 ] . V_82 = NULL ;
V_163 = F_140 ( V_163 ) ;
}
if ( V_18 -> V_74 & V_90 ) {
if ( F_131 ( V_1 , V_196 ) ) {
V_33 = F_141 ( & V_14 , V_183 ,
V_196 ) ;
if ( V_33 == NULL ) {
V_56 = - V_80 ;
goto V_158;
}
F_133 ( V_1 , V_196 ) ;
V_22 -> V_55 -- ;
F_4 ( & V_177 -> V_6 , & V_196 -> V_6 ) ;
} else {
V_56 = - V_37 ;
goto V_158;
}
} else if ( V_18 -> V_74 & V_194 )
if ( V_196 )
F_113 ( & V_177 -> V_6 , & V_196 -> V_6 ) ;
else
F_4 ( & V_177 -> V_6 , & V_22 -> V_156 ) ;
else {
if ( V_196 )
F_4 ( & V_177 -> V_6 , & V_196 -> V_6 ) ;
else
F_113 ( & V_177 -> V_6 , & V_22 -> V_156 ) ;
}
if ( F_141 ( & V_14 , V_193 , V_177 ) == NULL ) {
V_56 = - V_80 ;
goto V_203;
}
V_22 -> V_55 ++ ;
return 0 ;
V_203:
F_7 ( & V_177 -> V_6 ) ;
if ( V_33 ) {
F_7 ( & V_195 ( V_33 ) -> V_6 ) ;
F_134 ( V_1 , V_195 ( V_33 ) ) ;
F_20 ( V_33 ) ;
V_22 -> V_55 ++ ;
}
V_158:
F_137 ( & V_14 , V_177 ) ;
V_157:
for ( V_40 = 0 ; V_40 < V_198 ; V_40 ++ ) {
if ( V_168 [ V_40 ] . V_82 != NULL )
F_71 ( V_168 [ V_40 ] . V_82 -> type -> V_92 ) ;
}
return V_56 ;
}
static int
F_146 ( struct V_13 * V_14 , struct V_176 * V_177 )
{
if ( F_131 ( V_14 -> V_1 , V_177 ) ) {
if ( F_141 ( V_14 , V_183 , V_177 ) == NULL )
return - V_80 ;
F_133 ( V_14 -> V_1 , V_177 ) ;
V_14 -> V_22 -> V_55 -- ;
return 0 ;
}
return - V_37 ;
}
static int F_147 ( struct V_13 * V_14 )
{
struct V_176 * V_177 ;
int V_56 ;
F_9 (rule, &ctx->chain->rules, list) {
V_56 = F_146 ( V_14 , V_177 ) ;
if ( V_56 < 0 )
return V_56 ;
}
return 0 ;
}
static int F_148 ( struct V_71 * V_72 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_45 * V_46 = F_33 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
struct V_19 * V_20 ;
struct V_21 * V_22 = NULL ;
struct V_176 * V_177 ;
int V_9 = V_46 -> V_48 , V_56 = 0 ;
struct V_13 V_14 ;
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_53 ( V_3 ) )
return F_54 ( V_3 ) ;
V_20 = F_25 ( V_3 , V_24 [ V_180 ] ) ;
if ( F_53 ( V_20 ) )
return F_54 ( V_20 ) ;
if ( V_20 -> V_44 & V_79 )
return - V_37 ;
if ( V_24 [ V_181 ] ) {
V_22 = F_79 ( V_20 , V_24 [ V_181 ] ) ;
if ( F_53 ( V_22 ) )
return F_54 ( V_22 ) ;
}
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , V_22 , V_24 ) ;
if ( V_22 ) {
if ( V_24 [ V_182 ] ) {
V_177 = F_122 ( V_22 ,
V_24 [ V_182 ] ) ;
if ( F_53 ( V_177 ) )
return F_54 ( V_177 ) ;
V_56 = F_146 ( & V_14 , V_177 ) ;
} else {
V_56 = F_147 ( & V_14 ) ;
}
} else {
F_9 (chain, &table->chains, list) {
V_14 . V_22 = V_22 ;
V_56 = F_147 ( & V_14 ) ;
if ( V_56 < 0 )
break;
}
}
return V_56 ;
}
int F_149 ( struct V_204 * V_82 )
{
F_3 ( V_5 ) ;
F_4 ( & V_82 -> V_6 , & V_205 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_150 ( struct V_204 * V_82 )
{
F_3 ( V_5 ) ;
F_7 ( & V_82 -> V_6 ) ;
F_5 ( V_5 ) ;
}
static const struct V_204 *
F_151 ( const struct V_23 * const V_24 [] ,
const struct V_206 * V_207 ,
enum V_208 V_124 )
{
const struct V_204 * V_82 , * V_209 ;
struct V_210 V_211 , V_212 ;
T_1 V_213 ;
#ifdef F_11
if ( F_152 ( & V_205 ) ) {
F_5 ( V_5 ) ;
F_12 ( L_5 ) ;
F_3 ( V_5 ) ;
if ( ! F_152 ( & V_205 ) )
return F_13 ( - V_11 ) ;
}
#endif
V_213 = 0 ;
if ( V_24 [ V_214 ] != NULL ) {
V_213 = F_63 ( F_64 ( V_24 [ V_214 ] ) ) ;
V_213 &= V_215 | V_216 ;
}
V_209 = NULL ;
V_212 . V_32 = ~ 0 ;
V_212 . V_217 = ~ 0 ;
F_9 (ops, &nf_tables_set_ops, list) {
if ( ( V_82 -> V_213 & V_213 ) != V_213 )
continue;
if ( ! V_82 -> V_218 ( V_207 , V_213 , & V_211 ) )
continue;
switch ( V_124 ) {
case V_219 :
if ( V_211 . V_217 < V_212 . V_217 )
break;
if ( V_211 . V_217 == V_212 . V_217 && V_211 . V_32 < V_212 . V_32 )
break;
continue;
case V_220 :
if ( V_211 . V_32 < V_212 . V_32 )
break;
if ( V_211 . V_32 == V_212 . V_32 && V_211 . V_217 < V_212 . V_217 )
break;
continue;
default:
break;
}
if ( ! F_70 ( V_82 -> V_92 ) )
continue;
if ( V_209 != NULL )
F_71 ( V_209 -> V_92 ) ;
V_209 = V_82 ;
V_212 = V_211 ;
}
if ( V_209 != NULL )
return V_209 ;
return F_13 ( - V_91 ) ;
}
static int F_153 ( struct V_13 * V_14 ,
const struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
const struct V_45 * V_46 = F_33 ( V_18 ) ;
struct V_2 * V_3 = NULL ;
struct V_19 * V_20 = NULL ;
if ( V_46 -> V_48 != V_65 ) {
V_3 = F_10 ( V_1 , V_46 -> V_48 , false ) ;
if ( F_53 ( V_3 ) )
return F_54 ( V_3 ) ;
}
if ( V_24 [ V_221 ] != NULL ) {
if ( V_3 == NULL )
return - V_12 ;
V_20 = F_25 ( V_3 , V_24 [ V_221 ] ) ;
if ( F_53 ( V_20 ) )
return F_54 ( V_20 ) ;
if ( V_20 -> V_44 & V_79 )
return - V_37 ;
}
F_14 ( V_14 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return 0 ;
}
struct V_222 * F_154 ( const struct V_19 * V_20 ,
const struct V_23 * V_24 )
{
struct V_222 * V_223 ;
if ( V_24 == NULL )
return F_13 ( - V_36 ) ;
F_9 (set, &table->sets, list) {
if ( ! F_24 ( V_24 , V_223 -> V_35 ) )
return V_223 ;
}
return F_13 ( - V_37 ) ;
}
struct V_222 * F_155 ( const struct V_1 * V_1 ,
const struct V_23 * V_24 )
{
struct V_30 * V_33 ;
T_1 V_224 = F_63 ( F_64 ( V_24 ) ) ;
F_9 (trans, &net->nft.commit_list, list) {
if ( V_33 -> V_31 == V_225 &&
V_224 == F_156 ( V_33 ) )
return F_157 ( V_33 ) ;
}
return F_13 ( - V_37 ) ;
}
static int F_158 ( struct V_13 * V_14 , struct V_222 * V_223 ,
const char * V_35 )
{
const struct V_222 * V_40 ;
const char * V_226 ;
unsigned long * V_227 ;
unsigned int V_198 = 0 , V_228 = 0 ;
V_226 = F_159 ( V_35 , V_229 , '%' ) ;
if ( V_226 != NULL ) {
if ( V_226 [ 1 ] != 'd' || strchr ( V_226 + 2 , '%' ) )
return - V_36 ;
V_227 = ( unsigned long * ) F_160 ( V_34 ) ;
if ( V_227 == NULL )
return - V_80 ;
V_66:
F_9 (i, &ctx->table->sets, list) {
int V_197 ;
if ( ! sscanf ( V_40 -> V_35 , V_35 , & V_197 ) )
continue;
if ( V_197 < V_228 || V_197 >= V_228 + V_230 * V_231 )
continue;
F_161 ( V_197 - V_228 , V_227 ) ;
}
V_198 = F_162 ( V_227 , V_230 * V_231 ) ;
if ( V_198 >= V_230 * V_231 ) {
V_228 += V_230 * V_231 ;
memset ( V_227 , 0 , V_231 ) ;
goto V_66;
}
F_163 ( ( unsigned long ) V_227 ) ;
}
snprintf ( V_223 -> V_35 , sizeof( V_223 -> V_35 ) , V_35 , V_228 + V_198 ) ;
F_9 (i, &ctx->table->sets, list) {
if ( ! strcmp ( V_223 -> V_35 , V_40 -> V_35 ) )
return - V_232 ;
}
return 0 ;
}
static int F_164 ( struct V_15 * V_16 , const struct V_13 * V_14 ,
const struct V_222 * V_223 , T_6 V_43 , T_6 V_44 )
{
struct V_45 * V_46 ;
struct V_17 * V_18 ;
struct V_23 * V_207 ;
T_1 V_26 = V_14 -> V_26 ;
T_1 V_28 = V_14 -> V_28 ;
V_43 |= V_5 << 8 ;
V_18 = F_32 ( V_16 , V_26 , V_28 , V_43 , sizeof( struct V_45 ) ,
V_44 ) ;
if ( V_18 == NULL )
goto V_47;
V_46 = F_33 ( V_18 ) ;
V_46 -> V_48 = V_14 -> V_3 -> V_9 ;
V_46 -> V_49 = V_50 ;
V_46 -> V_51 = 0 ;
if ( F_34 ( V_16 , V_221 , V_14 -> V_20 -> V_35 ) )
goto V_47;
if ( F_34 ( V_16 , V_233 , V_223 -> V_35 ) )
goto V_47;
if ( V_223 -> V_44 != 0 )
if ( F_35 ( V_16 , V_214 , F_36 ( V_223 -> V_44 ) ) )
goto V_47;
if ( F_35 ( V_16 , V_234 , F_36 ( V_223 -> V_235 ) ) )
goto V_47;
if ( F_35 ( V_16 , V_236 , F_36 ( V_223 -> V_237 ) ) )
goto V_47;
if ( V_223 -> V_44 & V_216 ) {
if ( F_35 ( V_16 , V_238 , F_36 ( V_223 -> V_239 ) ) )
goto V_47;
if ( F_35 ( V_16 , V_240 , F_36 ( V_223 -> V_202 ) ) )
goto V_47;
}
V_207 = F_85 ( V_16 , V_241 ) ;
if ( V_207 == NULL )
goto V_47;
if ( V_223 -> V_32 &&
F_35 ( V_16 , V_242 , F_36 ( V_223 -> V_32 ) ) )
goto V_47;
F_88 ( V_16 , V_207 ) ;
return F_37 ( V_16 , V_18 ) ;
V_47:
F_38 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_165 ( const struct V_13 * V_14 ,
const struct V_222 * V_223 ,
int V_43 , T_7 V_243 )
{
struct V_15 * V_16 ;
T_1 V_26 = V_14 -> V_26 ;
int V_56 ;
if ( ! V_14 -> V_27 &&
! F_40 ( V_14 -> V_1 , V_57 ) )
return 0 ;
V_56 = - V_58 ;
V_16 = F_41 ( V_59 , V_243 ) ;
if ( V_16 == NULL )
goto V_56;
V_56 = F_164 ( V_16 , V_14 , V_223 , V_43 , 0 ) ;
if ( V_56 < 0 ) {
F_42 ( V_16 ) ;
goto V_56;
}
V_56 = F_43 ( V_16 , V_14 -> V_1 , V_26 , V_57 ,
V_14 -> V_27 , V_243 ) ;
V_56:
if ( V_56 < 0 )
F_44 ( V_14 -> V_1 , V_26 , V_57 , V_56 ) ;
return V_56 ;
}
static int F_166 ( struct V_15 * V_16 , struct V_60 * V_61 )
{
const struct V_222 * V_223 ;
unsigned int V_62 , V_63 = V_61 -> args [ 0 ] ;
struct V_2 * V_3 ;
struct V_19 * V_20 , * V_244 = (struct V_19 * ) V_61 -> args [ 2 ] ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
int V_245 = V_61 -> args [ 3 ] ;
struct V_13 * V_14 = V_61 -> V_165 , V_246 ;
if ( V_61 -> args [ 1 ] )
return V_16 -> V_70 ;
F_46 () ;
V_61 -> V_28 = V_1 -> V_7 . V_64 ;
F_47 (afi, &net->nft.af_info, list) {
if ( V_14 -> V_3 && V_14 -> V_3 != V_3 )
continue;
if ( V_245 ) {
if ( V_3 -> V_9 != V_245 )
continue;
V_245 = 0 ;
}
F_47 (table, &afi->tables, list) {
if ( V_14 -> V_20 && V_14 -> V_20 != V_20 )
continue;
if ( V_244 ) {
if ( V_244 != V_20 )
continue;
V_244 = NULL ;
}
V_62 = 0 ;
F_47 (set, &table->sets, list) {
if ( V_62 < V_63 )
goto V_66;
V_246 = * V_14 ;
V_246 . V_20 = V_20 ;
V_246 . V_3 = V_3 ;
if ( F_164 ( V_16 , & V_246 , V_223 ,
V_225 ,
V_68 ) < 0 ) {
V_61 -> args [ 0 ] = V_62 ;
V_61 -> args [ 2 ] = ( unsigned long ) V_20 ;
V_61 -> args [ 3 ] = V_3 -> V_9 ;
goto V_69;
}
F_48 ( V_61 , F_49 ( V_16 ) ) ;
V_66:
V_62 ++ ;
}
if ( V_63 )
V_63 = 0 ;
}
}
V_61 -> args [ 1 ] = 1 ;
V_69:
F_50 () ;
return V_16 -> V_70 ;
}
static int F_167 ( struct V_60 * V_61 )
{
F_22 ( V_61 -> V_165 ) ;
return 0 ;
}
static int F_168 ( struct V_71 * V_72 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_222 * V_223 ;
struct V_13 V_14 ;
struct V_15 * V_73 ;
const struct V_45 * V_46 = F_33 ( V_18 ) ;
int V_56 ;
V_56 = F_153 ( & V_14 , V_16 , V_18 , V_24 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_18 -> V_74 & V_75 ) {
struct V_76 V_77 = {
. V_78 = F_166 ,
. V_69 = F_167 ,
} ;
struct V_13 * V_247 ;
V_247 = F_169 ( sizeof( * V_247 ) , V_34 ) ;
if ( V_247 == NULL )
return - V_80 ;
* V_247 = V_14 ;
V_77 . V_165 = V_247 ;
return F_52 ( V_72 , V_16 , V_18 , & V_77 ) ;
}
if ( V_46 -> V_48 == V_65 )
return - V_12 ;
V_223 = F_154 ( V_14 . V_20 , V_24 [ V_233 ] ) ;
if ( F_53 ( V_223 ) )
return F_54 ( V_223 ) ;
if ( V_223 -> V_44 & V_248 )
return - V_37 ;
V_73 = F_55 ( V_59 , V_34 ) ;
if ( V_73 == NULL )
return - V_80 ;
V_56 = F_164 ( V_73 , & V_14 , V_223 , V_225 , 0 ) ;
if ( V_56 < 0 )
goto V_56;
return F_56 ( V_72 , V_73 , F_16 ( V_16 ) . V_26 ) ;
V_56:
F_42 ( V_73 ) ;
return V_56 ;
}
static int F_170 ( const struct V_13 * V_14 ,
struct V_206 * V_207 ,
const struct V_23 * V_24 )
{
struct V_23 * V_249 [ V_250 + 1 ] ;
int V_56 ;
V_56 = F_94 ( V_249 , V_250 , V_24 , V_251 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_249 [ V_242 ] != NULL )
V_207 -> V_32 = F_63 ( F_64 ( V_249 [ V_242 ] ) ) ;
return 0 ;
}
static int F_171 ( struct V_13 * V_14 , int V_31 ,
struct V_222 * V_223 )
{
struct V_30 * V_33 ;
V_33 = F_18 ( V_14 , V_31 , sizeof( struct F_157 ) ) ;
if ( V_33 == NULL )
return - V_80 ;
if ( V_31 == V_225 && V_14 -> V_24 [ V_252 ] != NULL ) {
F_156 ( V_33 ) =
F_63 ( F_64 ( V_14 -> V_24 [ V_252 ] ) ) ;
V_223 -> V_44 |= V_248 ;
}
F_157 ( V_33 ) = V_223 ;
F_67 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_87 ) ;
return 0 ;
}
static int F_172 ( struct V_71 * V_72 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_45 * V_46 = F_33 ( V_18 ) ;
const struct V_204 * V_82 ;
struct V_2 * V_3 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
struct V_19 * V_20 ;
struct V_222 * V_223 ;
struct V_13 V_14 ;
char V_35 [ V_229 ] ;
unsigned int V_32 ;
bool V_140 ;
T_1 V_235 , V_239 , V_44 , V_124 ;
struct V_206 V_207 ;
int V_56 ;
if ( V_24 [ V_221 ] == NULL ||
V_24 [ V_233 ] == NULL ||
V_24 [ V_236 ] == NULL ||
V_24 [ V_252 ] == NULL )
return - V_36 ;
memset ( & V_207 , 0 , sizeof( V_207 ) ) ;
V_235 = V_253 ;
if ( V_24 [ V_234 ] != NULL ) {
V_235 = F_63 ( F_64 ( V_24 [ V_234 ] ) ) ;
if ( ( V_235 & V_254 ) == V_254 )
return - V_36 ;
}
V_207 . V_237 = F_63 ( F_64 ( V_24 [ V_236 ] ) ) ;
if ( V_207 . V_237 == 0 || V_207 . V_237 > F_173 ( struct V_255 , V_165 ) )
return - V_36 ;
V_44 = 0 ;
if ( V_24 [ V_214 ] != NULL ) {
V_44 = F_63 ( F_64 ( V_24 [ V_214 ] ) ) ;
if ( V_44 & ~ ( V_256 | V_257 |
V_215 | V_216 ) )
return - V_36 ;
}
V_239 = 0 ;
if ( V_24 [ V_238 ] != NULL ) {
if ( ! ( V_44 & V_216 ) )
return - V_36 ;
V_239 = F_63 ( F_64 ( V_24 [ V_238 ] ) ) ;
if ( ( V_239 & V_254 ) == V_254 &&
V_239 != V_258 )
return - V_36 ;
if ( V_239 != V_258 ) {
if ( V_24 [ V_240 ] == NULL )
return - V_36 ;
V_207 . V_202 = F_63 ( F_64 ( V_24 [ V_240 ] ) ) ;
if ( V_207 . V_202 == 0 ||
V_207 . V_202 > F_173 ( struct V_255 , V_165 ) )
return - V_36 ;
} else
V_207 . V_202 = sizeof( struct V_255 ) ;
} else if ( V_44 & V_216 )
return - V_36 ;
V_124 = V_219 ;
if ( V_24 [ V_259 ] != NULL )
V_124 = F_63 ( F_64 ( V_24 [ V_259 ] ) ) ;
if ( V_24 [ V_241 ] != NULL ) {
V_56 = F_170 ( & V_14 , & V_207 , V_24 [ V_241 ] ) ;
if ( V_56 < 0 )
return V_56 ;
}
V_140 = V_18 -> V_74 & V_141 ? true : false ;
V_3 = F_10 ( V_1 , V_46 -> V_48 , V_140 ) ;
if ( F_53 ( V_3 ) )
return F_54 ( V_3 ) ;
V_20 = F_25 ( V_3 , V_24 [ V_221 ] ) ;
if ( F_53 ( V_20 ) )
return F_54 ( V_20 ) ;
F_14 ( & V_14 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
V_223 = F_154 ( V_20 , V_24 [ V_233 ] ) ;
if ( F_53 ( V_223 ) ) {
if ( F_54 ( V_223 ) != - V_37 )
return F_54 ( V_223 ) ;
V_223 = NULL ;
}
if ( V_223 != NULL ) {
if ( V_18 -> V_74 & V_88 )
return - V_89 ;
if ( V_18 -> V_74 & V_90 )
return - V_91 ;
return 0 ;
}
if ( ! ( V_18 -> V_74 & V_141 ) )
return - V_37 ;
V_82 = F_151 ( V_24 , & V_207 , V_124 ) ;
if ( F_53 ( V_82 ) )
return F_54 ( V_82 ) ;
V_32 = 0 ;
if ( V_82 -> V_260 != NULL )
V_32 = V_82 -> V_260 ( V_24 ) ;
V_56 = - V_80 ;
V_223 = F_19 ( sizeof( * V_223 ) + V_32 , V_34 ) ;
if ( V_223 == NULL )
goto V_157;
F_72 ( V_35 , V_24 [ V_233 ] , sizeof( V_223 -> V_35 ) ) ;
V_56 = F_158 ( & V_14 , V_223 , V_35 ) ;
if ( V_56 < 0 )
goto V_158;
F_2 ( & V_223 -> V_261 ) ;
V_223 -> V_82 = V_82 ;
V_223 -> V_235 = V_235 ;
V_223 -> V_237 = V_207 . V_237 ;
V_223 -> V_239 = V_239 ;
V_223 -> V_202 = V_207 . V_202 ;
V_223 -> V_44 = V_44 ;
V_223 -> V_32 = V_207 . V_32 ;
V_56 = V_82 -> V_174 ( V_223 , & V_207 , V_24 ) ;
if ( V_56 < 0 )
goto V_158;
V_56 = F_171 ( & V_14 , V_225 , V_223 ) ;
if ( V_56 < 0 )
goto V_158;
F_4 ( & V_223 -> V_6 , & V_20 -> V_94 ) ;
V_20 -> V_55 ++ ;
return 0 ;
V_158:
F_22 ( V_223 ) ;
V_157:
F_71 ( V_82 -> V_92 ) ;
return V_56 ;
}
static void F_174 ( struct V_222 * V_223 )
{
V_223 -> V_82 -> V_175 ( V_223 ) ;
F_71 ( V_223 -> V_82 -> V_92 ) ;
F_22 ( V_223 ) ;
}
static void F_175 ( const struct V_13 * V_14 , struct V_222 * V_223 )
{
F_7 ( & V_223 -> V_6 ) ;
F_165 ( V_14 , V_223 , V_262 , V_263 ) ;
F_174 ( V_223 ) ;
}
static int F_176 ( struct V_71 * V_72 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_45 * V_46 = F_33 ( V_18 ) ;
struct V_222 * V_223 ;
struct V_13 V_14 ;
int V_56 ;
if ( V_46 -> V_48 == V_65 )
return - V_12 ;
if ( V_24 [ V_221 ] == NULL )
return - V_36 ;
V_56 = F_153 ( & V_14 , V_16 , V_18 , V_24 ) ;
if ( V_56 < 0 )
return V_56 ;
V_223 = F_154 ( V_14 . V_20 , V_24 [ V_233 ] ) ;
if ( F_53 ( V_223 ) )
return F_54 ( V_223 ) ;
if ( V_223 -> V_44 & V_248 )
return - V_37 ;
if ( ! F_152 ( & V_223 -> V_261 ) )
return - V_95 ;
V_56 = F_171 ( & V_14 , V_262 , V_223 ) ;
if ( V_56 < 0 )
return V_56 ;
F_7 ( & V_223 -> V_6 ) ;
V_14 . V_20 -> V_55 -- ;
return 0 ;
}
static int F_177 ( const struct V_13 * V_14 ,
const struct V_222 * V_223 ,
const struct V_264 * V_265 ,
const struct V_266 * V_187 )
{
enum V_267 V_268 ;
V_268 = F_178 ( V_223 -> V_239 ) ;
return F_179 ( V_14 , V_268 , & V_187 -> V_165 ,
V_223 -> V_239 == V_258 ?
V_258 : V_253 ) ;
}
int F_180 ( const struct V_13 * V_14 , struct V_222 * V_223 ,
struct V_269 * V_270 )
{
struct V_269 * V_40 ;
struct V_264 V_265 ;
if ( ! F_152 ( & V_223 -> V_261 ) && V_223 -> V_44 & V_256 )
return - V_95 ;
if ( V_223 -> V_44 & V_216 ) {
F_9 (i, &set->bindings, list) {
if ( V_40 -> V_22 == V_270 -> V_22 )
goto V_271;
}
V_265 . V_272 = 0 ;
V_265 . V_273 = 0 ;
V_265 . V_56 = 0 ;
V_265 . V_274 = F_177 ;
V_223 -> V_82 -> V_275 ( V_14 , V_223 , & V_265 ) ;
if ( V_265 . V_56 < 0 ) {
if ( V_223 -> V_44 & V_256 )
F_175 ( V_14 , V_223 ) ;
return V_265 . V_56 ;
}
}
V_271:
V_270 -> V_22 = V_14 -> V_22 ;
F_4 ( & V_270 -> V_6 , & V_223 -> V_261 ) ;
return 0 ;
}
void F_181 ( const struct V_13 * V_14 , struct V_222 * V_223 ,
struct V_269 * V_270 )
{
F_7 ( & V_270 -> V_6 ) ;
if ( F_152 ( & V_223 -> V_261 ) && V_223 -> V_44 & V_256 &&
! ( V_223 -> V_44 & V_248 ) )
F_175 ( V_14 , V_223 ) ;
}
static int F_182 ( struct V_13 * V_14 ,
const struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] ,
bool V_33 )
{
const struct V_45 * V_46 = F_33 ( V_18 ) ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
V_3 = F_10 ( V_1 , V_46 -> V_48 , false ) ;
if ( F_53 ( V_3 ) )
return F_54 ( V_3 ) ;
V_20 = F_25 ( V_3 , V_24 [ V_276 ] ) ;
if ( F_53 ( V_20 ) )
return F_54 ( V_20 ) ;
if ( ! V_33 && ( V_20 -> V_44 & V_79 ) )
return - V_37 ;
F_14 ( V_14 , V_16 , V_18 , V_3 , V_20 , NULL , V_24 ) ;
return 0 ;
}
static int F_183 ( struct V_15 * V_16 ,
const struct V_222 * V_223 ,
const struct V_266 * V_187 )
{
unsigned char * V_277 = F_184 ( V_16 ) ;
struct V_23 * V_104 ;
V_104 = F_85 ( V_16 , V_188 ) ;
if ( V_104 == NULL )
goto V_47;
if ( F_185 ( V_16 , V_278 , & V_187 -> V_279 , V_253 ,
V_223 -> V_237 ) < 0 )
goto V_47;
if ( V_223 -> V_44 & V_216 &&
! ( V_187 -> V_44 & V_280 ) &&
F_185 ( V_16 , V_281 , & V_187 -> V_165 ,
V_223 -> V_239 == V_258 ? V_258 : V_253 ,
V_223 -> V_202 ) < 0 )
goto V_47;
if ( V_187 -> V_44 != 0 )
if ( F_35 ( V_16 , V_282 , F_36 ( V_187 -> V_44 ) ) )
goto V_47;
F_88 ( V_16 , V_104 ) ;
return 0 ;
V_47:
F_38 ( V_16 , V_277 ) ;
return - V_283 ;
}
static int F_186 ( const struct V_13 * V_14 ,
const struct V_222 * V_223 ,
const struct V_264 * V_265 ,
const struct V_266 * V_187 )
{
struct V_284 * args ;
args = F_187 ( V_265 , struct V_284 , V_265 ) ;
return F_183 ( args -> V_16 , V_223 , V_187 ) ;
}
static int F_188 ( struct V_15 * V_16 , struct V_60 * V_61 )
{
const struct V_222 * V_223 ;
struct V_284 args ;
struct V_13 V_14 ;
struct V_23 * V_24 [ V_285 + 1 ] ;
struct V_45 * V_46 ;
struct V_17 * V_18 ;
struct V_23 * V_104 ;
T_1 V_26 , V_28 ;
int V_43 , V_56 ;
V_56 = F_189 ( V_61 -> V_18 , sizeof( struct V_45 ) , V_24 ,
V_285 , V_286 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_182 ( & V_14 , V_61 -> V_16 , V_61 -> V_18 , ( void * ) V_24 ,
false ) ;
if ( V_56 < 0 )
return V_56 ;
V_223 = F_154 ( V_14 . V_20 , V_24 [ V_287 ] ) ;
if ( F_53 ( V_223 ) )
return F_54 ( V_223 ) ;
if ( V_223 -> V_44 & V_248 )
return - V_37 ;
V_43 = V_288 ;
V_43 |= V_5 << 8 ;
V_26 = F_16 ( V_61 -> V_16 ) . V_26 ;
V_28 = V_61 -> V_18 -> V_29 ;
V_18 = F_32 ( V_16 , V_26 , V_28 , V_43 , sizeof( struct V_45 ) ,
V_68 ) ;
if ( V_18 == NULL )
goto V_47;
V_46 = F_33 ( V_18 ) ;
V_46 -> V_48 = V_14 . V_3 -> V_9 ;
V_46 -> V_49 = V_50 ;
V_46 -> V_51 = 0 ;
if ( F_34 ( V_16 , V_276 , V_14 . V_20 -> V_35 ) )
goto V_47;
if ( F_34 ( V_16 , V_287 , V_223 -> V_35 ) )
goto V_47;
V_104 = F_85 ( V_16 , V_289 ) ;
if ( V_104 == NULL )
goto V_47;
args . V_61 = V_61 ;
args . V_16 = V_16 ;
args . V_265 . V_272 = V_61 -> args [ 0 ] ;
args . V_265 . V_273 = 0 ;
args . V_265 . V_56 = 0 ;
args . V_265 . V_274 = F_186 ;
V_223 -> V_82 -> V_275 ( & V_14 , V_223 , & args . V_265 ) ;
F_88 ( V_16 , V_104 ) ;
F_37 ( V_16 , V_18 ) ;
if ( args . V_265 . V_56 && args . V_265 . V_56 != - V_283 )
return args . V_265 . V_56 ;
if ( args . V_265 . V_273 == V_61 -> args [ 0 ] )
return 0 ;
V_61 -> args [ 0 ] = args . V_265 . V_273 ;
return V_16 -> V_70 ;
V_47:
return - V_112 ;
}
static int F_190 ( struct V_71 * V_72 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_222 * V_223 ;
struct V_13 V_14 ;
int V_56 ;
V_56 = F_182 ( & V_14 , V_16 , V_18 , V_24 , false ) ;
if ( V_56 < 0 )
return V_56 ;
V_223 = F_154 ( V_14 . V_20 , V_24 [ V_287 ] ) ;
if ( F_53 ( V_223 ) )
return F_54 ( V_223 ) ;
if ( V_223 -> V_44 & V_248 )
return - V_37 ;
if ( V_18 -> V_74 & V_75 ) {
struct V_76 V_77 = {
. V_78 = F_188 ,
} ;
return F_52 ( V_72 , V_16 , V_18 , & V_77 ) ;
}
return - V_91 ;
}
static int F_191 ( struct V_15 * V_16 ,
const struct V_13 * V_14 , T_1 V_28 ,
T_1 V_26 , int V_43 , T_6 V_44 ,
const struct V_222 * V_223 ,
const struct V_266 * V_187 )
{
struct V_45 * V_46 ;
struct V_17 * V_18 ;
struct V_23 * V_104 ;
int V_56 ;
V_43 |= V_5 << 8 ;
V_18 = F_32 ( V_16 , V_26 , V_28 , V_43 , sizeof( struct V_45 ) ,
V_44 ) ;
if ( V_18 == NULL )
goto V_47;
V_46 = F_33 ( V_18 ) ;
V_46 -> V_48 = V_14 -> V_3 -> V_9 ;
V_46 -> V_49 = V_50 ;
V_46 -> V_51 = 0 ;
if ( F_34 ( V_16 , V_221 , V_14 -> V_20 -> V_35 ) )
goto V_47;
if ( F_34 ( V_16 , V_233 , V_223 -> V_35 ) )
goto V_47;
V_104 = F_85 ( V_16 , V_289 ) ;
if ( V_104 == NULL )
goto V_47;
V_56 = F_183 ( V_16 , V_223 , V_187 ) ;
if ( V_56 < 0 )
goto V_47;
F_88 ( V_16 , V_104 ) ;
return F_37 ( V_16 , V_18 ) ;
V_47:
F_38 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_192 ( const struct V_13 * V_14 ,
const struct V_222 * V_223 ,
const struct V_266 * V_187 ,
int V_43 , T_6 V_44 )
{
struct V_1 * V_1 = V_14 -> V_1 ;
T_1 V_26 = V_14 -> V_26 ;
struct V_15 * V_16 ;
int V_56 ;
if ( ! V_14 -> V_27 && ! F_40 ( V_1 , V_57 ) )
return 0 ;
V_56 = - V_58 ;
V_16 = F_41 ( V_59 , V_34 ) ;
if ( V_16 == NULL )
goto V_56;
V_56 = F_191 ( V_16 , V_14 , 0 , V_26 , V_43 , V_44 ,
V_223 , V_187 ) ;
if ( V_56 < 0 ) {
F_42 ( V_16 ) ;
goto V_56;
}
V_56 = F_43 ( V_16 , V_1 , V_26 , V_57 , V_14 -> V_27 ,
V_34 ) ;
V_56:
if ( V_56 < 0 )
F_44 ( V_1 , V_26 , V_57 , V_56 ) ;
return V_56 ;
}
static struct V_30 * F_193 ( struct V_13 * V_14 ,
int V_31 ,
struct V_222 * V_223 )
{
struct V_30 * V_33 ;
V_33 = F_18 ( V_14 , V_31 , sizeof( struct V_290 ) ) ;
if ( V_33 == NULL )
return NULL ;
F_194 ( V_33 ) = V_223 ;
return V_33 ;
}
static int F_195 ( struct V_13 * V_14 , struct V_222 * V_223 ,
const struct V_23 * V_129 )
{
struct V_23 * V_24 [ V_291 + 1 ] ;
struct V_292 V_293 , V_294 ;
struct V_266 V_187 ;
struct V_269 * V_270 ;
enum V_267 V_268 ;
struct V_30 * V_33 ;
int V_56 ;
if ( V_223 -> V_32 && V_223 -> V_295 == V_223 -> V_32 )
return - V_232 ;
V_56 = F_94 ( V_24 , V_291 , V_129 ,
V_296 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_24 [ V_278 ] == NULL )
return - V_36 ;
V_187 . V_44 = 0 ;
if ( V_24 [ V_282 ] != NULL ) {
V_187 . V_44 = F_63 ( F_64 ( V_24 [ V_282 ] ) ) ;
if ( V_187 . V_44 & ~ V_280 )
return - V_36 ;
}
if ( V_223 -> V_44 & V_216 ) {
if ( V_24 [ V_281 ] == NULL &&
! ( V_187 . V_44 & V_280 ) )
return - V_36 ;
if ( V_24 [ V_281 ] != NULL &&
V_187 . V_44 & V_280 )
return - V_36 ;
} else {
if ( V_24 [ V_281 ] != NULL )
return - V_36 ;
}
V_56 = F_196 ( V_14 , & V_187 . V_279 , & V_293 , V_24 [ V_278 ] ) ;
if ( V_56 < 0 )
goto V_157;
V_56 = - V_36 ;
if ( V_293 . type != V_253 || V_293 . V_70 != V_223 -> V_237 )
goto V_158;
V_56 = - V_89 ;
if ( V_223 -> V_82 -> V_297 ( V_223 , & V_187 ) == 0 )
goto V_158;
if ( V_24 [ V_281 ] != NULL ) {
V_56 = F_196 ( V_14 , & V_187 . V_165 , & V_294 , V_24 [ V_281 ] ) ;
if ( V_56 < 0 )
goto V_158;
V_56 = - V_36 ;
if ( V_223 -> V_239 != V_258 && V_294 . V_70 != V_223 -> V_202 )
goto V_203;
V_268 = F_178 ( V_223 -> V_239 ) ;
F_9 (binding, &set->bindings, list) {
struct V_13 V_298 = {
. V_3 = V_14 -> V_3 ,
. V_20 = V_14 -> V_20 ,
. V_22 = (struct V_21 * ) V_270 -> V_22 ,
} ;
V_56 = F_179 ( & V_298 , V_268 ,
& V_187 . V_165 , V_294 . type ) ;
if ( V_56 < 0 )
goto V_203;
}
}
V_33 = F_193 ( V_14 , V_288 , V_223 ) ;
if ( V_33 == NULL )
goto V_203;
V_56 = V_223 -> V_82 -> V_299 ( V_223 , & V_187 ) ;
if ( V_56 < 0 )
goto V_300;
V_290 ( V_33 ) = V_187 ;
F_67 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_87 ) ;
return 0 ;
V_300:
F_22 ( V_33 ) ;
V_203:
if ( V_24 [ V_281 ] != NULL )
F_197 ( & V_187 . V_165 , V_294 . type ) ;
V_158:
F_197 ( & V_187 . V_279 , V_293 . type ) ;
V_157:
return V_56 ;
}
static int F_198 ( struct V_71 * V_72 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
const struct V_23 * V_129 ;
struct V_222 * V_223 ;
struct V_13 V_14 ;
int V_199 , V_56 = 0 ;
if ( V_24 [ V_289 ] == NULL )
return - V_36 ;
V_56 = F_182 ( & V_14 , V_16 , V_18 , V_24 , true ) ;
if ( V_56 < 0 )
return V_56 ;
V_223 = F_154 ( V_14 . V_20 , V_24 [ V_287 ] ) ;
if ( F_53 ( V_223 ) ) {
if ( V_24 [ V_301 ] ) {
V_223 = F_155 ( V_1 ,
V_24 [ V_301 ] ) ;
}
if ( F_53 ( V_223 ) )
return F_54 ( V_223 ) ;
}
if ( ! F_152 ( & V_223 -> V_261 ) && V_223 -> V_44 & V_257 )
return - V_95 ;
F_143 (attr, nla[NFTA_SET_ELEM_LIST_ELEMENTS], rem) {
V_56 = F_195 ( & V_14 , V_223 , V_129 ) ;
if ( V_56 < 0 )
break;
V_223 -> V_295 ++ ;
}
return V_56 ;
}
static int F_199 ( struct V_13 * V_14 , struct V_222 * V_223 ,
const struct V_23 * V_129 )
{
struct V_23 * V_24 [ V_291 + 1 ] ;
struct V_292 V_207 ;
struct V_266 V_187 ;
struct V_30 * V_33 ;
int V_56 ;
V_56 = F_94 ( V_24 , V_291 , V_129 ,
V_296 ) ;
if ( V_56 < 0 )
goto V_157;
V_56 = - V_36 ;
if ( V_24 [ V_278 ] == NULL )
goto V_157;
V_56 = F_196 ( V_14 , & V_187 . V_279 , & V_207 , V_24 [ V_278 ] ) ;
if ( V_56 < 0 )
goto V_157;
V_56 = - V_36 ;
if ( V_207 . type != V_253 || V_207 . V_70 != V_223 -> V_237 )
goto V_158;
V_56 = V_223 -> V_82 -> V_297 ( V_223 , & V_187 ) ;
if ( V_56 < 0 )
goto V_158;
V_33 = F_193 ( V_14 , V_302 , V_223 ) ;
if ( V_33 == NULL ) {
V_56 = - V_80 ;
goto V_158;
}
V_290 ( V_33 ) = V_187 ;
F_67 ( & V_33 -> V_6 , & V_14 -> V_1 -> V_7 . V_87 ) ;
return 0 ;
V_158:
F_197 ( & V_187 . V_279 , V_207 . type ) ;
V_157:
return V_56 ;
}
static int F_200 ( struct V_71 * V_72 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_23 * const V_24 [] )
{
const struct V_23 * V_129 ;
struct V_222 * V_223 ;
struct V_13 V_14 ;
int V_199 , V_56 = 0 ;
if ( V_24 [ V_289 ] == NULL )
return - V_36 ;
V_56 = F_182 ( & V_14 , V_16 , V_18 , V_24 , false ) ;
if ( V_56 < 0 )
return V_56 ;
V_223 = F_154 ( V_14 . V_20 , V_24 [ V_287 ] ) ;
if ( F_53 ( V_223 ) )
return F_54 ( V_223 ) ;
if ( ! F_152 ( & V_223 -> V_261 ) && V_223 -> V_44 & V_257 )
return - V_95 ;
F_143 (attr, nla[NFTA_SET_ELEM_LIST_ELEMENTS], rem) {
V_56 = F_199 ( & V_14 , V_223 , V_129 ) ;
if ( V_56 < 0 )
break;
V_223 -> V_295 -- ;
}
return V_56 ;
}
static void F_201 ( struct V_30 * V_33 )
{
struct F_59 * V_116 ;
if ( F_110 ( V_33 ) [ 0 ] )
strcpy ( V_33 -> V_14 . V_22 -> V_35 , F_110 ( V_33 ) ) ;
if ( ! ( V_33 -> V_14 . V_22 -> V_44 & V_81 ) )
return;
V_116 = F_59 ( V_33 -> V_14 . V_22 ) ;
F_99 ( V_116 , F_107 ( V_33 ) ) ;
switch ( F_109 ( V_33 ) ) {
case V_142 :
case V_139 :
V_116 -> V_124 = F_109 ( V_33 ) ;
break;
}
}
static void F_202 ( struct V_303 * V_304 )
{
struct V_30 * V_33 = F_187 ( V_304 , struct V_30 , V_303 ) ;
switch ( V_33 -> V_31 ) {
case V_96 :
F_74 ( & V_33 -> V_14 ) ;
break;
case V_159 :
F_105 ( V_33 -> V_14 . V_22 ) ;
break;
case V_183 :
F_137 ( & V_33 -> V_14 , V_195 ( V_33 ) ) ;
break;
case V_262 :
F_174 ( F_157 ( V_33 ) ) ;
break;
}
F_22 ( V_33 ) ;
}
static int F_203 ( struct V_15 * V_16 )
{
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
struct V_30 * V_33 , * V_178 ;
struct V_290 * V_305 ;
while ( ++ V_1 -> V_7 . V_64 == 0 ) ;
V_1 -> V_7 . V_192 = F_130 ( V_1 ) ;
F_102 () ;
F_204 (trans, next, &net->nft.commit_list, list) {
switch ( V_33 -> V_31 ) {
case V_67 :
if ( F_66 ( V_33 ) ) {
if ( ! F_65 ( V_33 ) ) {
F_61 ( V_33 -> V_14 . V_3 ,
V_33 -> V_14 . V_20 ) ;
V_33 -> V_14 . V_20 -> V_44 |= V_85 ;
}
} else {
V_33 -> V_14 . V_20 -> V_44 &= ~ V_79 ;
}
F_39 ( & V_33 -> V_14 , V_67 ) ;
F_20 ( V_33 ) ;
break;
case V_96 :
F_39 ( & V_33 -> V_14 , V_96 ) ;
break;
case V_127 :
if ( F_108 ( V_33 ) )
F_201 ( V_33 ) ;
else
V_33 -> V_14 . V_22 -> V_44 &= ~ V_128 ;
F_90 ( & V_33 -> V_14 , V_127 ) ;
F_20 ( V_33 ) ;
break;
case V_159 :
F_90 ( & V_33 -> V_14 , V_159 ) ;
if ( ! ( V_33 -> V_14 . V_20 -> V_44 & V_85 ) &&
V_33 -> V_14 . V_22 -> V_44 & V_81 ) {
F_60 ( F_59 ( V_33 -> V_14 . V_22 ) -> V_82 ,
V_33 -> V_14 . V_3 -> V_83 ) ;
}
break;
case V_193 :
F_134 ( V_33 -> V_14 . V_1 , V_195 ( V_33 ) ) ;
F_128 ( & V_33 -> V_14 ,
V_195 ( V_33 ) ,
V_193 ) ;
F_20 ( V_33 ) ;
break;
case V_183 :
F_7 ( & V_195 ( V_33 ) -> V_6 ) ;
F_128 ( & V_33 -> V_14 ,
V_195 ( V_33 ) ,
V_183 ) ;
break;
case V_225 :
F_157 ( V_33 ) -> V_44 &= ~ V_248 ;
if ( F_157 ( V_33 ) -> V_44 & V_256 &&
! F_152 ( & F_157 ( V_33 ) -> V_261 ) )
V_33 -> V_14 . V_20 -> V_55 -- ;
F_165 ( & V_33 -> V_14 , F_157 ( V_33 ) ,
V_225 , V_34 ) ;
F_20 ( V_33 ) ;
break;
case V_262 :
F_165 ( & V_33 -> V_14 , F_157 ( V_33 ) ,
V_262 , V_34 ) ;
break;
case V_288 :
F_192 ( & V_33 -> V_14 ,
F_194 ( V_33 ) ,
& V_290 ( V_33 ) ,
V_288 , 0 ) ;
F_20 ( V_33 ) ;
break;
case V_302 :
V_305 = (struct V_290 * ) V_33 -> V_165 ;
F_192 ( & V_33 -> V_14 , V_305 -> V_223 ,
& V_305 -> V_187 ,
V_302 , 0 ) ;
V_305 -> V_223 -> V_82 -> V_297 ( V_305 -> V_223 , & V_305 -> V_187 ) ;
V_305 -> V_223 -> V_82 -> remove ( V_305 -> V_223 , & V_305 -> V_187 ) ;
F_197 ( & V_305 -> V_187 . V_279 , V_253 ) ;
if ( V_305 -> V_187 . V_44 & V_216 ) {
F_197 ( & V_305 -> V_187 . V_165 ,
V_305 -> V_223 -> V_239 ) ;
}
F_20 ( V_33 ) ;
break;
}
}
F_204 (trans, next, &net->nft.commit_list, list) {
F_21 ( & V_33 -> V_6 ) ;
V_33 -> V_14 . V_24 = NULL ;
F_205 ( & V_33 -> V_303 , F_202 ) ;
}
return 0 ;
}
static void F_206 ( struct V_303 * V_304 )
{
struct V_30 * V_33 = F_187 ( V_304 , struct V_30 , V_303 ) ;
switch ( V_33 -> V_31 ) {
case V_67 :
F_74 ( & V_33 -> V_14 ) ;
break;
case V_127 :
F_105 ( V_33 -> V_14 . V_22 ) ;
break;
case V_193 :
F_137 ( & V_33 -> V_14 , V_195 ( V_33 ) ) ;
break;
case V_225 :
F_174 ( F_157 ( V_33 ) ) ;
break;
}
F_22 ( V_33 ) ;
}
static int F_207 ( struct V_15 * V_16 )
{
struct V_1 * V_1 = F_15 ( V_16 -> V_25 ) ;
struct V_30 * V_33 , * V_178 ;
struct V_222 * V_223 ;
F_204 (trans, next, &net->nft.commit_list, list) {
switch ( V_33 -> V_31 ) {
case V_67 :
if ( F_66 ( V_33 ) ) {
if ( F_65 ( V_33 ) ) {
F_61 ( V_33 -> V_14 . V_3 ,
V_33 -> V_14 . V_20 ) ;
V_33 -> V_14 . V_20 -> V_44 |= V_85 ;
}
F_20 ( V_33 ) ;
} else {
F_7 ( & V_33 -> V_14 . V_20 -> V_6 ) ;
}
break;
case V_96 :
F_4 ( & V_33 -> V_14 . V_20 -> V_6 ,
& V_33 -> V_14 . V_3 -> V_4 ) ;
F_20 ( V_33 ) ;
break;
case V_127 :
if ( F_108 ( V_33 ) ) {
if ( F_107 ( V_33 ) )
F_103 ( F_107 ( V_33 ) ) ;
F_20 ( V_33 ) ;
} else {
V_33 -> V_14 . V_20 -> V_55 -- ;
F_7 ( & V_33 -> V_14 . V_22 -> V_6 ) ;
if ( ! ( V_33 -> V_14 . V_20 -> V_44 & V_85 ) &&
V_33 -> V_14 . V_22 -> V_44 & V_81 ) {
F_60 ( F_59 ( V_33 -> V_14 . V_22 ) -> V_82 ,
V_33 -> V_14 . V_3 -> V_83 ) ;
}
}
break;
case V_159 :
V_33 -> V_14 . V_20 -> V_55 ++ ;
F_4 ( & V_33 -> V_14 . V_22 -> V_6 ,
& V_33 -> V_14 . V_20 -> V_93 ) ;
F_20 ( V_33 ) ;
break;
case V_193 :
V_33 -> V_14 . V_22 -> V_55 -- ;
F_7 ( & V_195 ( V_33 ) -> V_6 ) ;
break;
case V_183 :
V_33 -> V_14 . V_22 -> V_55 ++ ;
F_134 ( V_33 -> V_14 . V_1 , V_195 ( V_33 ) ) ;
F_20 ( V_33 ) ;
break;
case V_225 :
V_33 -> V_14 . V_20 -> V_55 -- ;
F_7 ( & F_157 ( V_33 ) -> V_6 ) ;
break;
case V_262 :
V_33 -> V_14 . V_20 -> V_55 ++ ;
F_4 ( & F_157 ( V_33 ) -> V_6 ,
& V_33 -> V_14 . V_20 -> V_94 ) ;
F_20 ( V_33 ) ;
break;
case V_288 :
F_194 ( V_33 ) -> V_295 -- ;
V_223 = F_194 ( V_33 ) ;
V_223 -> V_82 -> V_297 ( V_223 , & V_290 ( V_33 ) ) ;
V_223 -> V_82 -> remove ( V_223 , & V_290 ( V_33 ) ) ;
F_20 ( V_33 ) ;
break;
case V_302 :
F_194 ( V_33 ) -> V_295 ++ ;
F_20 ( V_33 ) ;
break;
}
}
F_208 (trans, next,
&net->nft.commit_list, list) {
F_21 ( & V_33 -> V_6 ) ;
V_33 -> V_14 . V_24 = NULL ;
F_205 ( & V_33 -> V_303 , F_206 ) ;
}
return 0 ;
}
static int F_209 ( const struct V_13 * V_14 ,
const struct V_222 * V_223 ,
const struct V_264 * V_265 ,
const struct V_266 * V_187 )
{
if ( V_187 -> V_44 & V_280 )
return 0 ;
switch ( V_187 -> V_165 . V_306 ) {
case V_307 :
case V_308 :
return F_210 ( V_14 , V_187 -> V_165 . V_22 ) ;
default:
return 0 ;
}
}
static int F_210 ( const struct V_13 * V_14 ,
const struct V_21 * V_22 )
{
const struct V_176 * V_177 ;
const struct V_162 * V_163 , * V_309 ;
const struct V_222 * V_223 ;
struct V_269 * V_270 ;
struct V_264 V_265 ;
if ( V_14 -> V_22 == V_22 )
return - V_310 ;
F_9 (rule, &chain->rules, list) {
F_125 (expr, last, rule) {
const struct V_255 * V_165 = NULL ;
int V_56 ;
if ( ! V_163 -> V_82 -> V_311 )
continue;
V_56 = V_163 -> V_82 -> V_311 ( V_14 , V_163 , & V_165 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_165 == NULL )
continue;
switch ( V_165 -> V_306 ) {
case V_307 :
case V_308 :
V_56 = F_210 ( V_14 , V_165 -> V_22 ) ;
if ( V_56 < 0 )
return V_56 ;
default:
break;
}
}
}
F_9 (set, &ctx->table->sets, list) {
if ( ! ( V_223 -> V_44 & V_216 ) ||
V_223 -> V_239 != V_258 )
continue;
F_9 (binding, &set->bindings, list) {
if ( V_270 -> V_22 != V_22 )
continue;
V_265 . V_272 = 0 ;
V_265 . V_273 = 0 ;
V_265 . V_56 = 0 ;
V_265 . V_274 = F_209 ;
V_223 -> V_82 -> V_275 ( V_14 , V_223 , & V_265 ) ;
if ( V_265 . V_56 < 0 )
return V_265 . V_56 ;
}
}
return 0 ;
}
int F_211 ( enum V_267 V_312 )
{
if ( V_312 <= V_313 )
return - V_36 ;
if ( V_312 > V_314 )
return - V_315 ;
return 0 ;
}
int F_212 ( enum V_267 V_312 )
{
if ( V_312 < V_313 )
return - V_36 ;
if ( V_312 > V_314 )
return - V_315 ;
return 0 ;
}
int F_179 ( const struct V_13 * V_14 , enum V_267 V_312 ,
const struct V_255 * V_165 ,
enum V_316 type )
{
int V_56 ;
switch ( V_312 ) {
case V_313 :
if ( V_165 == NULL || type != V_258 )
return - V_36 ;
if ( V_165 -> V_306 == V_308 || V_165 -> V_306 == V_307 ) {
V_56 = F_210 ( V_14 , V_165 -> V_22 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_14 -> V_22 -> V_317 + 1 > V_165 -> V_22 -> V_317 ) {
if ( V_14 -> V_22 -> V_317 + 1 == V_318 )
return - V_319 ;
V_165 -> V_22 -> V_317 = V_14 -> V_22 -> V_317 + 1 ;
}
}
return 0 ;
default:
if ( V_165 != NULL && type != V_253 )
return - V_36 ;
return 0 ;
}
}
static int F_213 ( const struct V_13 * V_14 , struct V_255 * V_165 ,
struct V_292 * V_207 , const struct V_23 * V_24 )
{
struct V_23 * V_130 [ V_320 + 1 ] ;
struct V_21 * V_22 ;
int V_56 ;
V_56 = F_94 ( V_130 , V_320 , V_24 , V_321 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( ! V_130 [ V_322 ] )
return - V_36 ;
V_165 -> V_306 = F_63 ( F_64 ( V_130 [ V_322 ] ) ) ;
switch ( V_165 -> V_306 ) {
default:
switch ( V_165 -> V_306 & V_323 ) {
case V_139 :
case V_142 :
case V_324 :
break;
default:
return - V_36 ;
}
case V_325 :
case V_326 :
case V_327 :
V_207 -> V_70 = sizeof( V_165 -> V_306 ) ;
break;
case V_307 :
case V_308 :
if ( ! V_130 [ V_328 ] )
return - V_36 ;
V_22 = F_79 ( V_14 -> V_20 ,
V_130 [ V_328 ] ) ;
if ( F_53 ( V_22 ) )
return F_54 ( V_22 ) ;
if ( V_22 -> V_44 & V_81 )
return - V_91 ;
V_22 -> V_55 ++ ;
V_165 -> V_22 = V_22 ;
V_207 -> V_70 = sizeof( V_165 ) ;
break;
}
V_207 -> type = V_258 ;
return 0 ;
}
static void F_214 ( const struct V_255 * V_165 )
{
switch ( V_165 -> V_306 ) {
case V_307 :
case V_308 :
V_165 -> V_22 -> V_55 -- ;
break;
}
}
static int F_215 ( struct V_15 * V_16 , const struct V_255 * V_165 )
{
struct V_23 * V_104 ;
V_104 = F_85 ( V_16 , V_329 ) ;
if ( ! V_104 )
goto V_47;
if ( F_35 ( V_16 , V_322 , F_36 ( V_165 -> V_306 ) ) )
goto V_47;
switch ( V_165 -> V_306 ) {
case V_307 :
case V_308 :
if ( F_34 ( V_16 , V_328 , V_165 -> V_22 -> V_35 ) )
goto V_47;
}
F_88 ( V_16 , V_104 ) ;
return 0 ;
V_47:
return - 1 ;
}
static int F_216 ( const struct V_13 * V_14 , struct V_255 * V_165 ,
struct V_292 * V_207 , const struct V_23 * V_24 )
{
unsigned int V_70 ;
V_70 = F_29 ( V_24 ) ;
if ( V_70 == 0 )
return - V_36 ;
if ( V_70 > sizeof( V_165 -> V_165 ) )
return - V_145 ;
F_145 ( V_165 -> V_165 , V_24 , sizeof( V_165 -> V_165 ) ) ;
V_207 -> type = V_253 ;
V_207 -> V_70 = V_70 ;
return 0 ;
}
static int F_217 ( struct V_15 * V_16 , const struct V_255 * V_165 ,
unsigned int V_70 )
{
return F_126 ( V_16 , V_330 , V_70 , V_165 -> V_165 ) ;
}
int F_196 ( const struct V_13 * V_14 , struct V_255 * V_165 ,
struct V_292 * V_207 , const struct V_23 * V_24 )
{
struct V_23 * V_130 [ V_331 + 1 ] ;
int V_56 ;
V_56 = F_94 ( V_130 , V_331 , V_24 , V_332 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_130 [ V_330 ] )
return F_216 ( V_14 , V_165 , V_207 , V_130 [ V_330 ] ) ;
if ( V_130 [ V_329 ] && V_14 != NULL )
return F_213 ( V_14 , V_165 , V_207 , V_130 [ V_329 ] ) ;
return - V_36 ;
}
void F_197 ( const struct V_255 * V_165 , enum V_316 type )
{
switch ( type ) {
case V_253 :
return;
case V_258 :
return F_214 ( V_165 ) ;
default:
F_218 ( 1 ) ;
}
}
int F_185 ( struct V_15 * V_16 , int V_129 , const struct V_255 * V_165 ,
enum V_316 type , unsigned int V_70 )
{
struct V_23 * V_104 ;
int V_56 ;
V_104 = F_85 ( V_16 , V_129 ) ;
if ( V_104 == NULL )
return - 1 ;
switch ( type ) {
case V_253 :
V_56 = F_217 ( V_16 , V_165 , V_70 ) ;
break;
case V_258 :
V_56 = F_215 ( V_16 , V_165 ) ;
break;
default:
V_56 = - V_36 ;
F_218 ( 1 ) ;
}
F_88 ( V_16 , V_104 ) ;
return V_56 ;
}
static int F_219 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_7 . V_8 ) ;
F_2 ( & V_1 -> V_7 . V_87 ) ;
V_1 -> V_7 . V_64 = 1 ;
return 0 ;
}
static int T_8 F_220 ( void )
{
int V_56 ;
V_168 = F_169 ( sizeof( struct V_167 ) * V_201 ,
V_34 ) ;
if ( V_168 == NULL ) {
V_56 = - V_80 ;
goto V_157;
}
V_56 = F_221 () ;
if ( V_56 < 0 )
goto V_158;
V_56 = F_222 ( & V_333 ) ;
if ( V_56 < 0 )
goto V_203;
F_223 ( L_6 ) ;
return F_224 ( & V_334 ) ;
V_203:
F_225 () ;
V_158:
F_22 ( V_168 ) ;
V_157:
return V_56 ;
}
static void T_9 F_226 ( void )
{
F_227 ( & V_334 ) ;
F_228 ( & V_333 ) ;
F_225 () ;
F_22 ( V_168 ) ;
}
