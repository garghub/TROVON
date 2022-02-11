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
static int F_18 ( int V_9 , const struct V_14 * V_15 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
if ( V_23 [ V_9 ] [ V_21 ] != NULL &&
! F_15 ( V_15 , V_23 [ V_9 ] [ V_21 ] -> V_17 ) )
return V_21 ;
}
return - 1 ;
}
static int F_19 ( const struct V_2 * V_3 ,
const struct V_14 * V_15 ,
bool V_10 )
{
int type ;
type = F_18 ( V_3 -> V_9 , V_15 ) ;
#ifdef F_11
if ( type < 0 && V_10 ) {
F_5 ( V_5 ) ;
F_12 ( L_2 , V_3 -> V_9 ,
F_20 ( V_15 ) - 1 , ( const char * ) F_21 ( V_15 ) ) ;
F_3 ( V_5 ) ;
type = F_18 ( V_3 -> V_9 , V_15 ) ;
}
#endif
return type ;
}
static int F_22 ( struct V_24 * V_25 , T_2 V_26 , T_2 V_27 ,
int V_28 , T_2 V_29 , int V_9 ,
const struct V_13 * V_16 )
{
struct V_30 * V_31 ;
struct V_32 * V_33 ;
V_28 |= V_5 << 8 ;
V_31 = F_23 ( V_25 , V_26 , V_27 , V_28 , sizeof( struct V_32 ) , V_29 ) ;
if ( V_31 == NULL )
goto V_34;
V_33 = F_24 ( V_31 ) ;
V_33 -> V_35 = V_9 ;
V_33 -> V_36 = V_37 ;
V_33 -> V_38 = 0 ;
if ( F_25 ( V_25 , V_39 , V_16 -> V_17 ) ||
F_26 ( V_25 , V_40 , F_27 ( V_16 -> V_29 ) ) )
goto V_34;
return F_28 ( V_25 , V_31 ) ;
V_34:
F_29 ( V_25 , V_31 ) ;
return - 1 ;
}
static int F_30 ( const struct V_24 * V_41 ,
const struct V_30 * V_31 ,
const struct V_13 * V_16 ,
int V_28 , int V_9 )
{
struct V_24 * V_25 ;
T_2 V_26 = V_41 ? F_31 ( V_41 ) . V_26 : 0 ;
T_2 V_27 = V_31 ? V_31 -> V_42 : 0 ;
struct V_1 * V_1 = V_41 ? F_32 ( V_41 -> V_43 ) : & V_44 ;
bool V_45 ;
int V_46 ;
V_45 = V_31 ? F_33 ( V_31 ) : false ;
if ( ! V_45 && ! F_34 ( V_1 , V_47 ) )
return 0 ;
V_46 = - V_48 ;
V_25 = F_35 ( V_49 , V_50 ) ;
if ( V_25 == NULL )
goto V_46;
V_46 = F_22 ( V_25 , V_26 , V_27 , V_28 , 0 ,
V_9 , V_16 ) ;
if ( V_46 < 0 ) {
F_36 ( V_25 ) ;
goto V_46;
}
V_46 = F_37 ( V_25 , V_1 , V_26 , V_47 , V_45 ,
V_50 ) ;
V_46:
if ( V_46 < 0 )
F_38 ( V_1 , V_26 , V_47 , V_46 ) ;
return V_46 ;
}
static int F_39 ( struct V_24 * V_25 ,
struct V_51 * V_52 )
{
const struct V_32 * V_33 = F_24 ( V_52 -> V_31 ) ;
const struct V_2 * V_3 ;
const struct V_13 * V_16 ;
unsigned int V_53 = 0 , V_54 = V_52 -> args [ 0 ] ;
struct V_1 * V_1 = F_32 ( V_25 -> V_43 ) ;
int V_9 = V_33 -> V_35 ;
F_9 (afi, &net->nft.af_info, list) {
if ( V_9 != V_55 && V_9 != V_3 -> V_9 )
continue;
F_9 (table, &afi->tables, list) {
if ( V_53 < V_54 )
goto V_56;
if ( V_53 > V_54 )
memset ( & V_52 -> args [ 1 ] , 0 ,
sizeof( V_52 -> args ) - sizeof( V_52 -> args [ 0 ] ) ) ;
if ( F_22 ( V_25 ,
F_31 ( V_52 -> V_25 ) . V_26 ,
V_52 -> V_31 -> V_42 ,
V_57 ,
V_58 ,
V_3 -> V_9 , V_16 ) < 0 )
goto V_59;
V_56:
V_53 ++ ;
}
}
V_59:
V_52 -> args [ 0 ] = V_53 ;
return V_25 -> V_60 ;
}
static int F_40 ( struct V_61 * V_62 , struct V_24 * V_25 ,
const struct V_30 * V_31 ,
const struct V_14 * const V_15 [] )
{
const struct V_32 * V_33 = F_24 ( V_31 ) ;
const struct V_2 * V_3 ;
const struct V_13 * V_16 ;
struct V_24 * V_63 ;
struct V_1 * V_1 = F_32 ( V_25 -> V_43 ) ;
int V_9 = V_33 -> V_35 ;
int V_46 ;
if ( V_31 -> V_64 & V_65 ) {
struct V_66 V_67 = {
. V_68 = F_39 ,
} ;
return F_41 ( V_62 , V_25 , V_31 , & V_67 ) ;
}
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_42 ( V_3 ) )
return F_43 ( V_3 ) ;
V_16 = F_16 ( V_3 , V_15 [ V_39 ] ) ;
if ( F_42 ( V_16 ) )
return F_43 ( V_16 ) ;
V_63 = F_44 ( V_49 , V_50 ) ;
if ( ! V_63 )
return - V_69 ;
V_46 = F_22 ( V_63 , F_31 ( V_25 ) . V_26 ,
V_31 -> V_42 , V_57 , 0 ,
V_9 , V_16 ) ;
if ( V_46 < 0 )
goto V_46;
return F_45 ( V_62 , V_63 , F_31 ( V_25 ) . V_26 ) ;
V_46:
F_36 ( V_63 ) ;
return V_46 ;
}
static int F_46 ( struct V_13 * V_16 )
{
struct V_70 * V_71 ;
int V_46 , V_21 = 0 ;
F_9 (chain, &table->chains, list) {
if ( ! ( V_71 -> V_29 & V_72 ) )
continue;
V_46 = F_47 ( & F_48 ( V_71 ) -> V_73 ) ;
if ( V_46 < 0 )
goto V_46;
V_21 ++ ;
}
return 0 ;
V_46:
F_9 (chain, &table->chains, list) {
if ( ! ( V_71 -> V_29 & V_72 ) )
continue;
if ( V_21 -- <= 0 )
break;
F_49 ( & F_48 ( V_71 ) -> V_73 ) ;
}
return V_46 ;
}
static int F_50 ( struct V_13 * V_16 )
{
struct V_70 * V_71 ;
F_9 (chain, &table->chains, list) {
if ( V_71 -> V_29 & V_72 )
F_49 ( & F_48 ( V_71 ) -> V_73 ) ;
}
return 0 ;
}
static int F_51 ( struct V_61 * V_62 , struct V_24 * V_25 ,
const struct V_30 * V_31 ,
const struct V_14 * const V_15 [] ,
struct V_2 * V_3 , struct V_13 * V_16 )
{
const struct V_32 * V_33 = F_24 ( V_31 ) ;
int V_9 = V_33 -> V_35 , V_74 = 0 ;
if ( V_15 [ V_40 ] ) {
T_3 V_29 ;
V_29 = F_52 ( F_53 ( V_15 [ V_40 ] ) ) ;
if ( V_29 & ~ V_75 )
return - V_18 ;
if ( ( V_29 & V_75 ) &&
! ( V_16 -> V_29 & V_75 ) ) {
V_74 = F_50 ( V_16 ) ;
if ( V_74 >= 0 )
V_16 -> V_29 |= V_75 ;
} else if ( ! ( V_29 & V_75 ) &&
V_16 -> V_29 & V_75 ) {
V_74 = F_46 ( V_16 ) ;
if ( V_74 >= 0 )
V_16 -> V_29 &= ~ V_75 ;
}
if ( V_74 < 0 )
goto V_46;
}
F_30 ( V_25 , V_31 , V_16 , V_57 , V_9 ) ;
V_46:
return V_74 ;
}
static int F_54 ( struct V_61 * V_62 , struct V_24 * V_25 ,
const struct V_30 * V_31 ,
const struct V_14 * const V_15 [] )
{
const struct V_32 * V_33 = F_24 ( V_31 ) ;
const struct V_14 * V_17 ;
struct V_2 * V_3 ;
struct V_13 * V_16 ;
struct V_1 * V_1 = F_32 ( V_25 -> V_43 ) ;
int V_9 = V_33 -> V_35 ;
V_3 = F_10 ( V_1 , V_9 , true ) ;
if ( F_42 ( V_3 ) )
return F_43 ( V_3 ) ;
V_17 = V_15 [ V_39 ] ;
V_16 = F_16 ( V_3 , V_17 ) ;
if ( F_42 ( V_16 ) ) {
if ( F_43 ( V_16 ) != - V_19 )
return F_43 ( V_16 ) ;
V_16 = NULL ;
}
if ( V_16 != NULL ) {
if ( V_31 -> V_64 & V_76 )
return - V_77 ;
if ( V_31 -> V_64 & V_78 )
return - V_79 ;
return F_51 ( V_62 , V_25 , V_31 , V_15 , V_3 , V_16 ) ;
}
V_16 = F_55 ( sizeof( * V_16 ) + F_20 ( V_17 ) , V_50 ) ;
if ( V_16 == NULL )
return - V_69 ;
F_56 ( V_16 -> V_17 , V_17 , F_20 ( V_17 ) ) ;
F_2 ( & V_16 -> V_80 ) ;
F_2 ( & V_16 -> V_81 ) ;
if ( V_15 [ V_40 ] ) {
T_3 V_29 ;
V_29 = F_52 ( F_53 ( V_15 [ V_40 ] ) ) ;
if ( V_29 & ~ V_75 ) {
F_57 ( V_16 ) ;
return - V_18 ;
}
V_16 -> V_29 |= V_29 ;
}
F_4 ( & V_16 -> V_6 , & V_3 -> V_4 ) ;
F_30 ( V_25 , V_31 , V_16 , V_57 , V_9 ) ;
return 0 ;
}
static int F_58 ( struct V_61 * V_62 , struct V_24 * V_25 ,
const struct V_30 * V_31 ,
const struct V_14 * const V_15 [] )
{
const struct V_32 * V_33 = F_24 ( V_31 ) ;
struct V_2 * V_3 ;
struct V_13 * V_16 ;
struct V_1 * V_1 = F_32 ( V_25 -> V_43 ) ;
int V_9 = V_33 -> V_35 ;
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_42 ( V_3 ) )
return F_43 ( V_3 ) ;
V_16 = F_16 ( V_3 , V_15 [ V_39 ] ) ;
if ( F_42 ( V_16 ) )
return F_43 ( V_16 ) ;
if ( V_16 -> V_82 )
return - V_83 ;
F_7 ( & V_16 -> V_6 ) ;
F_30 ( V_25 , V_31 , V_16 , V_84 , V_9 ) ;
F_57 ( V_16 ) ;
return 0 ;
}
int F_59 ( struct V_85 * V_86 )
{
int V_46 = 0 ;
F_3 ( V_5 ) ;
if ( V_23 [ V_86 -> V_9 ] [ V_86 -> type ] != NULL ) {
V_46 = - V_83 ;
goto V_87;
}
if ( ! F_60 ( V_86 -> V_88 ) )
goto V_87;
V_23 [ V_86 -> V_9 ] [ V_86 -> type ] = V_86 ;
V_87:
F_5 ( V_5 ) ;
return V_46 ;
}
void F_61 ( struct V_85 * V_86 )
{
F_3 ( V_5 ) ;
V_23 [ V_86 -> V_9 ] [ V_86 -> type ] = NULL ;
F_62 ( V_86 -> V_88 ) ;
F_5 ( V_5 ) ;
}
static struct V_70 *
F_63 ( const struct V_13 * V_16 , T_1 V_89 )
{
struct V_70 * V_71 ;
F_9 (chain, &table->chains, list) {
if ( V_71 -> V_89 == V_89 )
return V_71 ;
}
return F_13 ( - V_19 ) ;
}
static struct V_70 * F_64 ( const struct V_13 * V_16 ,
const struct V_14 * V_15 )
{
struct V_70 * V_71 ;
if ( V_15 == NULL )
return F_13 ( - V_18 ) ;
F_9 (chain, &table->chains, list) {
if ( ! F_15 ( V_15 , V_71 -> V_17 ) )
return V_71 ;
}
return F_13 ( - V_19 ) ;
}
static int F_65 ( struct V_24 * V_25 , struct V_90 T_4 * V_91 )
{
struct V_90 * V_92 , V_93 ;
struct V_14 * V_94 ;
int V_95 ;
memset ( & V_93 , 0 , sizeof( V_93 ) ) ;
F_66 (cpu) {
V_92 = F_67 ( V_91 , V_95 ) ;
V_93 . V_96 += V_92 -> V_96 ;
V_93 . V_97 += V_92 -> V_97 ;
}
V_94 = F_68 ( V_25 , V_98 ) ;
if ( V_94 == NULL )
goto V_34;
if ( F_69 ( V_25 , V_99 , F_70 ( V_93 . V_96 ) ) ||
F_69 ( V_25 , V_100 , F_70 ( V_93 . V_97 ) ) )
goto V_34;
F_71 ( V_25 , V_94 ) ;
return 0 ;
V_34:
return - V_101 ;
}
static int F_72 ( struct V_24 * V_25 , T_2 V_26 , T_2 V_27 ,
int V_28 , T_2 V_29 , int V_9 ,
const struct V_13 * V_16 ,
const struct V_70 * V_71 )
{
struct V_30 * V_31 ;
struct V_32 * V_33 ;
V_28 |= V_5 << 8 ;
V_31 = F_23 ( V_25 , V_26 , V_27 , V_28 , sizeof( struct V_32 ) , V_29 ) ;
if ( V_31 == NULL )
goto V_34;
V_33 = F_24 ( V_31 ) ;
V_33 -> V_35 = V_9 ;
V_33 -> V_36 = V_37 ;
V_33 -> V_38 = 0 ;
if ( F_25 ( V_25 , V_102 , V_16 -> V_17 ) )
goto V_34;
if ( F_69 ( V_25 , V_103 , F_70 ( V_71 -> V_89 ) ) )
goto V_34;
if ( F_25 ( V_25 , V_104 , V_71 -> V_17 ) )
goto V_34;
if ( V_71 -> V_29 & V_72 ) {
const struct F_48 * V_105 = F_48 ( V_71 ) ;
const struct V_106 * V_73 = & V_105 -> V_73 ;
struct V_14 * V_94 ;
V_94 = F_68 ( V_25 , V_107 ) ;
if ( V_94 == NULL )
goto V_34;
if ( F_26 ( V_25 , V_108 , F_27 ( V_73 -> V_109 ) ) )
goto V_34;
if ( F_26 ( V_25 , V_110 , F_27 ( V_73 -> V_111 ) ) )
goto V_34;
F_71 ( V_25 , V_94 ) ;
if ( F_26 ( V_25 , V_112 ,
F_27 ( V_105 -> V_113 ) ) )
goto V_34;
if ( F_25 ( V_25 , V_114 ,
V_23 [ V_73 -> V_115 ] [ F_48 ( V_71 ) -> type ] -> V_17 ) )
goto V_34;
if ( F_65 ( V_25 , F_48 ( V_71 ) -> V_91 ) )
goto V_34;
}
if ( F_26 ( V_25 , V_116 , F_27 ( V_71 -> V_82 ) ) )
goto V_34;
return F_28 ( V_25 , V_31 ) ;
V_34:
F_29 ( V_25 , V_31 ) ;
return - 1 ;
}
static int F_73 ( const struct V_24 * V_41 ,
const struct V_30 * V_31 ,
const struct V_13 * V_16 ,
const struct V_70 * V_71 ,
int V_28 , int V_9 )
{
struct V_24 * V_25 ;
T_2 V_26 = V_41 ? F_31 ( V_41 ) . V_26 : 0 ;
struct V_1 * V_1 = V_41 ? F_32 ( V_41 -> V_43 ) : & V_44 ;
T_2 V_27 = V_31 ? V_31 -> V_42 : 0 ;
bool V_45 ;
int V_46 ;
V_45 = V_31 ? F_33 ( V_31 ) : false ;
if ( ! V_45 && ! F_34 ( V_1 , V_47 ) )
return 0 ;
V_46 = - V_48 ;
V_25 = F_35 ( V_49 , V_50 ) ;
if ( V_25 == NULL )
goto V_46;
V_46 = F_72 ( V_25 , V_26 , V_27 , V_28 , 0 , V_9 ,
V_16 , V_71 ) ;
if ( V_46 < 0 ) {
F_36 ( V_25 ) ;
goto V_46;
}
V_46 = F_37 ( V_25 , V_1 , V_26 , V_47 , V_45 ,
V_50 ) ;
V_46:
if ( V_46 < 0 )
F_38 ( V_1 , V_26 , V_47 , V_46 ) ;
return V_46 ;
}
static int F_74 ( struct V_24 * V_25 ,
struct V_51 * V_52 )
{
const struct V_32 * V_33 = F_24 ( V_52 -> V_31 ) ;
const struct V_2 * V_3 ;
const struct V_13 * V_16 ;
const struct V_70 * V_71 ;
unsigned int V_53 = 0 , V_54 = V_52 -> args [ 0 ] ;
struct V_1 * V_1 = F_32 ( V_25 -> V_43 ) ;
int V_9 = V_33 -> V_35 ;
F_9 (afi, &net->nft.af_info, list) {
if ( V_9 != V_55 && V_9 != V_3 -> V_9 )
continue;
F_9 (table, &afi->tables, list) {
F_9 (chain, &table->chains, list) {
if ( V_53 < V_54 )
goto V_56;
if ( V_53 > V_54 )
memset ( & V_52 -> args [ 1 ] , 0 ,
sizeof( V_52 -> args ) - sizeof( V_52 -> args [ 0 ] ) ) ;
if ( F_72 ( V_25 , F_31 ( V_52 -> V_25 ) . V_26 ,
V_52 -> V_31 -> V_42 ,
V_117 ,
V_58 ,
V_3 -> V_9 , V_16 , V_71 ) < 0 )
goto V_59;
V_56:
V_53 ++ ;
}
}
}
V_59:
V_52 -> args [ 0 ] = V_53 ;
return V_25 -> V_60 ;
}
static int F_75 ( struct V_61 * V_62 , struct V_24 * V_25 ,
const struct V_30 * V_31 ,
const struct V_14 * const V_15 [] )
{
const struct V_32 * V_33 = F_24 ( V_31 ) ;
const struct V_2 * V_3 ;
const struct V_13 * V_16 ;
const struct V_70 * V_71 ;
struct V_24 * V_63 ;
struct V_1 * V_1 = F_32 ( V_25 -> V_43 ) ;
int V_9 = V_33 -> V_35 ;
int V_46 ;
if ( V_31 -> V_64 & V_65 ) {
struct V_66 V_67 = {
. V_68 = F_74 ,
} ;
return F_41 ( V_62 , V_25 , V_31 , & V_67 ) ;
}
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_42 ( V_3 ) )
return F_43 ( V_3 ) ;
V_16 = F_16 ( V_3 , V_15 [ V_102 ] ) ;
if ( F_42 ( V_16 ) )
return F_43 ( V_16 ) ;
V_71 = F_64 ( V_16 , V_15 [ V_104 ] ) ;
if ( F_42 ( V_71 ) )
return F_43 ( V_71 ) ;
V_63 = F_44 ( V_49 , V_50 ) ;
if ( ! V_63 )
return - V_69 ;
V_46 = F_72 ( V_63 , F_31 ( V_25 ) . V_26 ,
V_31 -> V_42 , V_117 , 0 ,
V_9 , V_16 , V_71 ) ;
if ( V_46 < 0 )
goto V_46;
return F_45 ( V_62 , V_63 , F_31 ( V_25 ) . V_26 ) ;
V_46:
F_36 ( V_63 ) ;
return V_46 ;
}
static int
F_76 ( struct F_48 * V_71 , const struct V_14 * V_118 )
{
switch ( F_52 ( F_53 ( V_118 ) ) ) {
case V_119 :
V_71 -> V_113 = V_119 ;
break;
case V_120 :
V_71 -> V_113 = V_120 ;
break;
default:
return - V_18 ;
}
return 0 ;
}
static int
F_77 ( struct F_48 * V_71 , const struct V_14 * V_118 )
{
struct V_14 * V_121 [ V_122 + 1 ] ;
struct V_90 T_4 * V_123 ;
struct V_90 * V_91 ;
int V_46 ;
V_46 = F_78 ( V_121 , V_122 , V_118 , V_124 ) ;
if ( V_46 < 0 )
return V_46 ;
if ( ! V_121 [ V_100 ] || ! V_121 [ V_99 ] )
return - V_18 ;
V_123 = F_79 ( struct V_90 ) ;
if ( V_123 == NULL )
return - V_69 ;
V_91 = F_80 ( V_123 ) ;
V_91 -> V_97 = F_81 ( F_82 ( V_121 [ V_100 ] ) ) ;
V_91 -> V_96 = F_81 ( F_82 ( V_121 [ V_99 ] ) ) ;
if ( V_71 -> V_91 ) {
struct V_90 T_4 * V_125 =
F_83 ( V_71 -> V_91 , 1 ) ;
F_84 ( V_71 -> V_91 , V_123 ) ;
F_85 () ;
F_86 ( V_125 ) ;
} else
F_84 ( V_71 -> V_91 , V_123 ) ;
return 0 ;
}
static int F_87 ( struct V_61 * V_62 , struct V_24 * V_25 ,
const struct V_30 * V_31 ,
const struct V_14 * const V_15 [] )
{
const struct V_32 * V_33 = F_24 ( V_31 ) ;
const struct V_14 * V_126 ( V_17 ) ;
const struct V_2 * V_3 ;
struct V_13 * V_16 ;
struct V_70 * V_71 ;
struct F_48 * V_105 = NULL ;
struct V_14 * V_127 [ V_128 + 1 ] ;
struct V_1 * V_1 = F_32 ( V_25 -> V_43 ) ;
int V_9 = V_33 -> V_35 ;
T_1 V_89 = 0 ;
int V_46 ;
bool V_129 ;
V_129 = V_31 -> V_64 & V_130 ? true : false ;
V_3 = F_10 ( V_1 , V_9 , true ) ;
if ( F_42 ( V_3 ) )
return F_43 ( V_3 ) ;
V_16 = F_16 ( V_3 , V_15 [ V_102 ] ) ;
if ( F_42 ( V_16 ) )
return F_43 ( V_16 ) ;
if ( V_16 -> V_82 == V_131 )
return - V_132 ;
V_71 = NULL ;
V_17 = V_15 [ V_104 ] ;
if ( V_15 [ V_103 ] ) {
V_89 = F_81 ( F_82 ( V_15 [ V_103 ] ) ) ;
V_71 = F_63 ( V_16 , V_89 ) ;
if ( F_42 ( V_71 ) )
return F_43 ( V_71 ) ;
} else {
V_71 = F_64 ( V_16 , V_17 ) ;
if ( F_42 ( V_71 ) ) {
if ( F_43 ( V_71 ) != - V_19 )
return F_43 ( V_71 ) ;
V_71 = NULL ;
}
}
if ( V_71 != NULL ) {
if ( V_31 -> V_64 & V_76 )
return - V_77 ;
if ( V_31 -> V_64 & V_78 )
return - V_79 ;
if ( V_15 [ V_103 ] && V_17 &&
! F_42 ( F_64 ( V_16 , V_15 [ V_104 ] ) ) )
return - V_77 ;
if ( V_15 [ V_112 ] ) {
if ( ! ( V_71 -> V_29 & V_72 ) )
return - V_79 ;
V_46 = F_76 ( F_48 ( V_71 ) ,
V_15 [ V_112 ] ) ;
if ( V_46 < 0 )
return V_46 ;
}
if ( V_15 [ V_98 ] ) {
if ( ! ( V_71 -> V_29 & V_72 ) )
return - V_79 ;
V_46 = F_77 ( F_48 ( V_71 ) ,
V_15 [ V_98 ] ) ;
if ( V_46 < 0 )
return V_46 ;
}
if ( V_15 [ V_103 ] && V_17 )
F_56 ( V_71 -> V_17 , V_17 , V_133 ) ;
goto V_134;
}
if ( V_15 [ V_107 ] ) {
struct V_106 * V_73 ;
T_5 * V_135 ;
T_2 V_109 ;
int type = V_136 ;
if ( V_15 [ V_114 ] ) {
type = F_19 ( V_3 ,
V_15 [ V_114 ] ,
V_129 ) ;
if ( type < 0 )
return - V_19 ;
}
V_46 = F_78 ( V_127 , V_128 , V_15 [ V_107 ] ,
V_137 ) ;
if ( V_46 < 0 )
return V_46 ;
if ( V_127 [ V_108 ] == NULL ||
V_127 [ V_110 ] == NULL )
return - V_18 ;
V_109 = F_52 ( F_53 ( V_127 [ V_108 ] ) ) ;
if ( V_109 >= V_3 -> V_138 )
return - V_18 ;
V_135 = V_23 [ V_9 ] [ type ] -> V_139 [ V_109 ] ;
if ( V_135 == NULL )
return - V_79 ;
V_105 = F_55 ( sizeof( * V_105 ) , V_50 ) ;
if ( V_105 == NULL )
return - V_69 ;
V_105 -> type = type ;
V_71 = & V_105 -> V_71 ;
V_73 = & V_105 -> V_73 ;
V_73 -> V_115 = V_9 ;
V_73 -> V_140 = V_3 -> V_140 ;
V_73 -> V_109 = F_52 ( F_53 ( V_127 [ V_108 ] ) ) ;
V_73 -> V_111 = F_52 ( F_53 ( V_127 [ V_110 ] ) ) ;
V_73 -> V_141 = V_71 ;
V_73 -> V_142 = V_135 ;
if ( V_3 -> V_143 [ V_73 -> V_109 ] )
V_73 -> V_142 = V_3 -> V_143 [ V_73 -> V_109 ] ;
V_71 -> V_29 |= V_72 ;
if ( V_15 [ V_112 ] ) {
V_46 = F_76 ( V_105 ,
V_15 [ V_112 ] ) ;
if ( V_46 < 0 ) {
F_86 ( V_105 -> V_91 ) ;
F_57 ( V_105 ) ;
return V_46 ;
}
} else
V_105 -> V_113 = V_120 ;
if ( V_15 [ V_98 ] ) {
V_46 = F_77 ( V_105 ,
V_15 [ V_98 ] ) ;
if ( V_46 < 0 ) {
F_86 ( V_105 -> V_91 ) ;
F_57 ( V_105 ) ;
return V_46 ;
}
} else {
struct V_90 T_4 * V_123 ;
V_123 = F_79 ( struct V_90 ) ;
if ( V_123 == NULL )
return - V_69 ;
F_84 ( F_48 ( V_71 ) -> V_91 ,
V_123 ) ;
}
} else {
V_71 = F_55 ( sizeof( * V_71 ) , V_50 ) ;
if ( V_71 == NULL )
return - V_69 ;
}
F_2 ( & V_71 -> V_144 ) ;
V_71 -> V_89 = F_17 ( V_16 ) ;
V_71 -> V_1 = V_1 ;
V_71 -> V_16 = V_16 ;
F_56 ( V_71 -> V_17 , V_17 , V_133 ) ;
if ( ! ( V_16 -> V_29 & V_75 ) &&
V_71 -> V_29 & V_72 ) {
V_46 = F_47 ( & F_48 ( V_71 ) -> V_73 ) ;
if ( V_46 < 0 ) {
F_86 ( V_105 -> V_91 ) ;
F_57 ( V_105 ) ;
return V_46 ;
}
}
F_4 ( & V_71 -> V_6 , & V_16 -> V_80 ) ;
V_16 -> V_82 ++ ;
V_134:
F_73 ( V_25 , V_31 , V_16 , V_71 , V_117 ,
V_9 ) ;
return 0 ;
}
static void F_88 ( struct V_145 * V_146 )
{
struct V_70 * V_71 = F_89 ( V_146 , struct V_70 , V_145 ) ;
F_90 ( V_71 -> V_82 > 0 ) ;
if ( V_71 -> V_29 & V_72 ) {
F_86 ( F_48 ( V_71 ) -> V_91 ) ;
F_57 ( F_48 ( V_71 ) ) ;
} else
F_57 ( V_71 ) ;
}
static int F_91 ( struct V_61 * V_62 , struct V_24 * V_25 ,
const struct V_30 * V_31 ,
const struct V_14 * const V_15 [] )
{
const struct V_32 * V_33 = F_24 ( V_31 ) ;
const struct V_2 * V_3 ;
struct V_13 * V_16 ;
struct V_70 * V_71 ;
struct V_1 * V_1 = F_32 ( V_25 -> V_43 ) ;
int V_9 = V_33 -> V_35 ;
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_42 ( V_3 ) )
return F_43 ( V_3 ) ;
V_16 = F_16 ( V_3 , V_15 [ V_102 ] ) ;
if ( F_42 ( V_16 ) )
return F_43 ( V_16 ) ;
V_71 = F_64 ( V_16 , V_15 [ V_104 ] ) ;
if ( F_42 ( V_71 ) )
return F_43 ( V_71 ) ;
if ( ! F_92 ( & V_71 -> V_144 ) )
return - V_83 ;
F_7 ( & V_71 -> V_6 ) ;
V_16 -> V_82 -- ;
if ( ! ( V_16 -> V_29 & V_75 ) &&
V_71 -> V_29 & V_72 )
F_49 ( & F_48 ( V_71 ) -> V_73 ) ;
F_73 ( V_25 , V_31 , V_16 , V_71 , V_147 ,
V_9 ) ;
F_93 ( & V_71 -> V_145 , F_88 ) ;
return 0 ;
}
static void F_94 ( struct V_148 * V_149 ,
const struct V_24 * V_25 ,
const struct V_30 * V_31 ,
const struct V_2 * V_3 ,
const struct V_13 * V_16 ,
const struct V_70 * V_71 ,
const struct V_14 * const * V_15 )
{
V_149 -> V_1 = F_32 ( V_25 -> V_43 ) ;
V_149 -> V_25 = V_25 ;
V_149 -> V_31 = V_31 ;
V_149 -> V_3 = V_3 ;
V_149 -> V_16 = V_16 ;
V_149 -> V_71 = V_71 ;
V_149 -> V_15 = V_15 ;
}
int F_95 ( struct V_150 * type )
{
F_3 ( V_5 ) ;
F_4 ( & type -> V_6 , & V_151 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_96 ( struct V_150 * type )
{
F_3 ( V_5 ) ;
F_7 ( & type -> V_6 ) ;
F_5 ( V_5 ) ;
}
static const struct V_150 * F_97 ( struct V_14 * V_15 )
{
const struct V_150 * type ;
F_9 (type, &nf_tables_expressions, list) {
if ( ! F_15 ( V_15 , type -> V_17 ) )
return type ;
}
return NULL ;
}
static const struct V_150 * F_98 ( struct V_14 * V_15 )
{
const struct V_150 * type ;
if ( V_15 == NULL )
return F_13 ( - V_18 ) ;
type = F_97 ( V_15 ) ;
if ( type != NULL && F_60 ( type -> V_140 ) )
return type ;
#ifdef F_11
if ( type == NULL ) {
F_5 ( V_5 ) ;
F_12 ( L_3 ,
F_20 ( V_15 ) , ( char * ) F_21 ( V_15 ) ) ;
F_3 ( V_5 ) ;
if ( F_97 ( V_15 ) )
return F_13 ( - V_11 ) ;
}
#endif
return F_13 ( - V_19 ) ;
}
static int F_99 ( struct V_24 * V_25 ,
const struct V_152 * V_153 )
{
if ( F_25 ( V_25 , V_154 , V_153 -> V_73 -> type -> V_17 ) )
goto V_34;
if ( V_153 -> V_73 -> V_68 ) {
struct V_14 * V_155 = F_68 ( V_25 , V_156 ) ;
if ( V_155 == NULL )
goto V_34;
if ( V_153 -> V_73 -> V_68 ( V_25 , V_153 ) < 0 )
goto V_34;
F_71 ( V_25 , V_155 ) ;
}
return V_25 -> V_60 ;
V_34:
return - 1 ;
}
static int F_100 ( const struct V_148 * V_149 ,
const struct V_14 * V_15 ,
struct V_157 * V_158 )
{
const struct V_150 * type ;
const struct V_159 * V_73 ;
struct V_14 * V_121 [ V_160 + 1 ] ;
int V_46 ;
V_46 = F_78 ( V_121 , V_160 , V_15 , V_161 ) ;
if ( V_46 < 0 )
return V_46 ;
type = F_98 ( V_121 [ V_154 ] ) ;
if ( F_42 ( type ) )
return F_43 ( type ) ;
if ( V_121 [ V_156 ] ) {
V_46 = F_78 ( V_158 -> V_121 , type -> V_162 ,
V_121 [ V_156 ] , type -> V_113 ) ;
if ( V_46 < 0 )
goto V_163;
} else
memset ( V_158 -> V_121 , 0 , sizeof( V_158 -> V_121 [ 0 ] ) * ( type -> V_162 + 1 ) ) ;
if ( type -> V_164 != NULL ) {
V_73 = type -> V_164 ( V_149 ,
( const struct V_14 * const * ) V_158 -> V_121 ) ;
if ( F_42 ( V_73 ) ) {
V_46 = F_43 ( V_73 ) ;
goto V_163;
}
} else
V_73 = type -> V_73 ;
V_158 -> V_73 = V_73 ;
return 0 ;
V_163:
F_62 ( type -> V_140 ) ;
return V_46 ;
}
static int F_101 ( const struct V_148 * V_149 ,
const struct V_157 * V_158 ,
struct V_152 * V_153 )
{
const struct V_159 * V_73 = V_158 -> V_73 ;
int V_46 ;
V_153 -> V_73 = V_73 ;
if ( V_73 -> V_165 ) {
V_46 = V_73 -> V_165 ( V_149 , V_153 , ( const struct V_14 * * ) V_158 -> V_121 ) ;
if ( V_46 < 0 )
goto V_163;
}
return 0 ;
V_163:
V_153 -> V_73 = NULL ;
return V_46 ;
}
static void F_102 ( struct V_152 * V_153 )
{
if ( V_153 -> V_73 -> V_166 )
V_153 -> V_73 -> V_166 ( V_153 ) ;
F_62 ( V_153 -> V_73 -> type -> V_140 ) ;
}
static struct V_167 * F_103 ( const struct V_70 * V_71 ,
T_1 V_89 )
{
struct V_167 * V_168 ;
F_9 (rule, &chain->rules, list) {
if ( V_89 == V_168 -> V_89 )
return V_168 ;
}
return F_13 ( - V_19 ) ;
}
static struct V_167 * F_104 ( const struct V_70 * V_71 ,
const struct V_14 * V_15 )
{
if ( V_15 == NULL )
return F_13 ( - V_18 ) ;
return F_103 ( V_71 , F_81 ( F_82 ( V_15 ) ) ) ;
}
static int F_105 ( struct V_24 * V_25 , T_2 V_26 , T_2 V_27 ,
int V_28 , T_2 V_29 , int V_9 ,
const struct V_13 * V_16 ,
const struct V_70 * V_71 ,
const struct V_167 * V_168 )
{
struct V_30 * V_31 ;
struct V_32 * V_33 ;
const struct V_152 * V_153 , * V_169 ;
struct V_14 * V_6 ;
const struct V_167 * V_170 ;
int type = V_28 | V_5 << 8 ;
V_31 = F_23 ( V_25 , V_26 , V_27 , type , sizeof( struct V_32 ) ,
V_29 ) ;
if ( V_31 == NULL )
goto V_34;
V_33 = F_24 ( V_31 ) ;
V_33 -> V_35 = V_9 ;
V_33 -> V_36 = V_37 ;
V_33 -> V_38 = 0 ;
if ( F_25 ( V_25 , V_171 , V_16 -> V_17 ) )
goto V_34;
if ( F_25 ( V_25 , V_172 , V_71 -> V_17 ) )
goto V_34;
if ( F_69 ( V_25 , V_173 , F_70 ( V_168 -> V_89 ) ) )
goto V_34;
if ( ( V_28 != V_174 ) && ( V_168 -> V_6 . V_175 != & V_71 -> V_144 ) ) {
V_170 = F_106 ( V_168 -> V_6 . V_175 , struct V_167 , V_6 ) ;
if ( F_69 ( V_25 , V_176 ,
F_70 ( V_170 -> V_89 ) ) )
goto V_34;
}
V_6 = F_68 ( V_25 , V_177 ) ;
if ( V_6 == NULL )
goto V_34;
F_107 (expr, next, rule) {
struct V_14 * V_178 = F_68 ( V_25 , V_179 ) ;
if ( V_178 == NULL )
goto V_34;
if ( F_99 ( V_25 , V_153 ) < 0 )
goto V_34;
F_71 ( V_25 , V_178 ) ;
}
F_71 ( V_25 , V_6 ) ;
return F_28 ( V_25 , V_31 ) ;
V_34:
F_29 ( V_25 , V_31 ) ;
return - 1 ;
}
static int F_108 ( const struct V_24 * V_41 ,
const struct V_30 * V_31 ,
const struct V_13 * V_16 ,
const struct V_70 * V_71 ,
const struct V_167 * V_168 ,
int V_28 , T_2 V_29 , int V_9 )
{
struct V_24 * V_25 ;
T_2 V_26 = F_31 ( V_41 ) . V_26 ;
struct V_1 * V_1 = V_41 ? F_32 ( V_41 -> V_43 ) : & V_44 ;
T_2 V_27 = V_31 -> V_42 ;
bool V_45 ;
int V_46 ;
V_45 = F_33 ( V_31 ) ;
if ( ! V_45 && ! F_34 ( V_1 , V_47 ) )
return 0 ;
V_46 = - V_48 ;
V_25 = F_35 ( V_49 , V_50 ) ;
if ( V_25 == NULL )
goto V_46;
V_46 = F_105 ( V_25 , V_26 , V_27 , V_28 , V_29 ,
V_9 , V_16 , V_71 , V_168 ) ;
if ( V_46 < 0 ) {
F_36 ( V_25 ) ;
goto V_46;
}
V_46 = F_37 ( V_25 , V_1 , V_26 , V_47 , V_45 ,
V_50 ) ;
V_46:
if ( V_46 < 0 )
F_38 ( V_1 , V_26 , V_47 , V_46 ) ;
return V_46 ;
}
static inline bool
F_109 ( struct V_1 * V_1 , const struct V_167 * V_168 )
{
return ( V_168 -> V_180 & ( 1 << V_1 -> V_7 . V_181 ) ) == 0 ;
}
static inline int F_110 ( struct V_1 * V_1 )
{
return V_1 -> V_7 . V_181 + 1 == 1 ? 1 : 0 ;
}
static inline int
F_111 ( struct V_1 * V_1 , const struct V_167 * V_168 )
{
return ( V_168 -> V_180 & ( 1 << F_110 ( V_1 ) ) ) == 0 ;
}
static inline void
F_112 ( struct V_1 * V_1 , struct V_167 * V_168 )
{
V_168 -> V_180 = ( 1 << V_1 -> V_7 . V_181 ) ;
}
static inline void
F_113 ( struct V_1 * V_1 , struct V_167 * V_168 )
{
V_168 -> V_180 = ( 1 << F_110 ( V_1 ) ) ;
}
static inline void F_114 ( struct V_1 * V_1 , struct V_167 * V_168 )
{
V_168 -> V_180 = 0 ;
}
static int F_115 ( struct V_24 * V_25 ,
struct V_51 * V_52 )
{
const struct V_32 * V_33 = F_24 ( V_52 -> V_31 ) ;
const struct V_2 * V_3 ;
const struct V_13 * V_16 ;
const struct V_70 * V_71 ;
const struct V_167 * V_168 ;
unsigned int V_53 = 0 , V_54 = V_52 -> args [ 0 ] ;
struct V_1 * V_1 = F_32 ( V_25 -> V_43 ) ;
int V_9 = V_33 -> V_35 ;
T_6 V_182 = F_116 ( V_1 -> V_7 . V_182 ) ;
T_6 V_181 = F_116 ( V_1 -> V_7 . V_181 ) ;
F_9 (afi, &net->nft.af_info, list) {
if ( V_9 != V_55 && V_9 != V_3 -> V_9 )
continue;
F_9 (table, &afi->tables, list) {
F_9 (chain, &table->chains, list) {
F_9 (rule, &chain->rules, list) {
if ( ! F_109 ( V_1 , V_168 ) )
goto V_56;
if ( V_53 < V_54 )
goto V_56;
if ( V_53 > V_54 )
memset ( & V_52 -> args [ 1 ] , 0 ,
sizeof( V_52 -> args ) - sizeof( V_52 -> args [ 0 ] ) ) ;
if ( F_105 ( V_25 , F_31 ( V_52 -> V_25 ) . V_26 ,
V_52 -> V_31 -> V_42 ,
V_183 ,
V_58 | V_184 ,
V_3 -> V_9 , V_16 , V_71 , V_168 ) < 0 )
goto V_59;
V_56:
V_53 ++ ;
}
}
}
}
V_59:
if ( V_181 != V_1 -> V_7 . V_181 || V_182 != V_1 -> V_7 . V_182 )
return - V_83 ;
V_52 -> args [ 0 ] = V_53 ;
return V_25 -> V_60 ;
}
static int F_117 ( struct V_61 * V_62 , struct V_24 * V_25 ,
const struct V_30 * V_31 ,
const struct V_14 * const V_15 [] )
{
const struct V_32 * V_33 = F_24 ( V_31 ) ;
const struct V_2 * V_3 ;
const struct V_13 * V_16 ;
const struct V_70 * V_71 ;
const struct V_167 * V_168 ;
struct V_24 * V_63 ;
struct V_1 * V_1 = F_32 ( V_25 -> V_43 ) ;
int V_9 = V_33 -> V_35 ;
int V_46 ;
if ( V_31 -> V_64 & V_65 ) {
struct V_66 V_67 = {
. V_68 = F_115 ,
} ;
return F_41 ( V_62 , V_25 , V_31 , & V_67 ) ;
}
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_42 ( V_3 ) )
return F_43 ( V_3 ) ;
V_16 = F_16 ( V_3 , V_15 [ V_171 ] ) ;
if ( F_42 ( V_16 ) )
return F_43 ( V_16 ) ;
V_71 = F_64 ( V_16 , V_15 [ V_172 ] ) ;
if ( F_42 ( V_71 ) )
return F_43 ( V_71 ) ;
V_168 = F_104 ( V_71 , V_15 [ V_173 ] ) ;
if ( F_42 ( V_168 ) )
return F_43 ( V_168 ) ;
V_63 = F_44 ( V_49 , V_50 ) ;
if ( ! V_63 )
return - V_69 ;
V_46 = F_105 ( V_63 , F_31 ( V_25 ) . V_26 ,
V_31 -> V_42 , V_183 , 0 ,
V_9 , V_16 , V_71 , V_168 ) ;
if ( V_46 < 0 )
goto V_46;
return F_45 ( V_62 , V_63 , F_31 ( V_25 ) . V_26 ) ;
V_46:
F_36 ( V_63 ) ;
return V_46 ;
}
static void F_118 ( struct V_145 * V_146 )
{
struct V_167 * V_168 = F_89 ( V_146 , struct V_167 , V_145 ) ;
struct V_152 * V_153 ;
V_153 = F_119 ( V_168 ) ;
while ( V_153 -> V_73 && V_153 != F_120 ( V_168 ) ) {
F_102 ( V_153 ) ;
V_153 = F_121 ( V_153 ) ;
}
F_57 ( V_168 ) ;
}
static void F_122 ( struct V_167 * V_168 )
{
F_93 ( & V_168 -> V_145 , F_118 ) ;
}
static struct V_185 *
F_123 ( struct V_167 * V_168 , const struct V_148 * V_149 )
{
struct V_185 * V_186 ;
V_186 = F_124 ( sizeof( struct V_185 ) , V_50 ) ;
if ( V_186 == NULL )
return NULL ;
V_186 -> V_71 = V_149 -> V_71 ;
V_186 -> V_16 = V_149 -> V_16 ;
V_186 -> V_168 = V_168 ;
V_186 -> V_9 = V_149 -> V_3 -> V_9 ;
V_186 -> V_31 = V_149 -> V_31 ;
F_4 ( & V_186 -> V_6 , & V_149 -> V_1 -> V_7 . V_187 ) ;
return V_186 ;
}
static int F_125 ( struct V_61 * V_62 , struct V_24 * V_25 ,
const struct V_30 * V_31 ,
const struct V_14 * const V_15 [] )
{
const struct V_32 * V_33 = F_24 ( V_31 ) ;
const struct V_2 * V_3 ;
struct V_1 * V_1 = F_32 ( V_25 -> V_43 ) ;
struct V_13 * V_16 ;
struct V_70 * V_71 ;
struct V_167 * V_168 , * V_188 = NULL ;
struct V_185 * V_189 = NULL ;
struct V_152 * V_153 ;
struct V_148 V_149 ;
struct V_14 * V_190 ;
unsigned int V_191 , V_21 , V_192 ;
int V_46 , V_193 ;
bool V_129 ;
T_1 V_89 , V_194 ;
V_129 = V_31 -> V_64 & V_130 ? true : false ;
V_3 = F_10 ( V_1 , V_33 -> V_35 , V_129 ) ;
if ( F_42 ( V_3 ) )
return F_43 ( V_3 ) ;
V_16 = F_16 ( V_3 , V_15 [ V_171 ] ) ;
if ( F_42 ( V_16 ) )
return F_43 ( V_16 ) ;
V_71 = F_64 ( V_16 , V_15 [ V_172 ] ) ;
if ( F_42 ( V_71 ) )
return F_43 ( V_71 ) ;
if ( V_15 [ V_173 ] ) {
V_89 = F_81 ( F_82 ( V_15 [ V_173 ] ) ) ;
V_168 = F_103 ( V_71 , V_89 ) ;
if ( F_42 ( V_168 ) )
return F_43 ( V_168 ) ;
if ( V_31 -> V_64 & V_76 )
return - V_77 ;
if ( V_31 -> V_64 & V_78 )
V_188 = V_168 ;
else
return - V_79 ;
} else {
if ( ! V_129 || V_31 -> V_64 & V_78 )
return - V_18 ;
V_89 = F_17 ( V_16 ) ;
}
if ( V_15 [ V_176 ] ) {
if ( ! ( V_31 -> V_64 & V_130 ) )
return - V_79 ;
V_194 = F_81 ( F_82 ( V_15 [ V_176 ] ) ) ;
V_188 = F_103 ( V_71 , V_194 ) ;
if ( F_42 ( V_188 ) )
return F_43 ( V_188 ) ;
}
F_94 ( & V_149 , V_25 , V_31 , V_3 , V_16 , V_71 , V_15 ) ;
V_192 = 0 ;
V_191 = 0 ;
if ( V_15 [ V_177 ] ) {
F_126 (tmp, nla[NFTA_RULE_EXPRESSIONS], rem) {
V_46 = - V_18 ;
if ( F_127 ( V_190 ) != V_179 )
goto V_163;
if ( V_192 == V_195 )
goto V_163;
V_46 = F_100 ( & V_149 , V_190 , & V_158 [ V_192 ] ) ;
if ( V_46 < 0 )
goto V_163;
V_191 += V_158 [ V_192 ] . V_73 -> V_191 ;
V_192 ++ ;
}
}
V_46 = - V_69 ;
V_168 = F_55 ( sizeof( * V_168 ) + V_191 , V_50 ) ;
if ( V_168 == NULL )
goto V_163;
F_112 ( V_1 , V_168 ) ;
V_168 -> V_89 = V_89 ;
V_168 -> V_196 = V_191 ;
V_153 = F_119 ( V_168 ) ;
for ( V_21 = 0 ; V_21 < V_192 ; V_21 ++ ) {
V_46 = F_101 ( & V_149 , & V_158 [ V_21 ] , V_153 ) ;
if ( V_46 < 0 )
goto V_197;
V_158 [ V_21 ] . V_73 = NULL ;
V_153 = F_121 ( V_153 ) ;
}
if ( V_31 -> V_64 & V_78 ) {
if ( F_111 ( V_1 , V_188 ) ) {
V_189 = F_123 ( V_188 , & V_149 ) ;
if ( V_189 == NULL ) {
V_46 = - V_69 ;
goto V_197;
}
F_113 ( V_1 , V_188 ) ;
F_4 ( & V_168 -> V_6 , & V_188 -> V_6 ) ;
} else {
V_46 = - V_19 ;
goto V_197;
}
} else if ( V_31 -> V_64 & V_184 )
if ( V_188 )
F_128 ( & V_168 -> V_6 , & V_188 -> V_6 ) ;
else
F_129 ( & V_168 -> V_6 , & V_71 -> V_144 ) ;
else {
if ( V_188 )
F_129 ( & V_168 -> V_6 , & V_188 -> V_6 ) ;
else
F_128 ( & V_168 -> V_6 , & V_71 -> V_144 ) ;
}
if ( F_123 ( V_168 , & V_149 ) == NULL ) {
V_46 = - V_69 ;
goto V_198;
}
return 0 ;
V_198:
F_130 ( & V_168 -> V_6 ) ;
if ( V_189 ) {
F_130 ( & V_189 -> V_168 -> V_6 ) ;
F_7 ( & V_189 -> V_6 ) ;
F_114 ( V_1 , V_189 -> V_168 ) ;
F_57 ( V_189 ) ;
}
V_197:
F_122 ( V_168 ) ;
V_163:
for ( V_21 = 0 ; V_21 < V_192 ; V_21 ++ ) {
if ( V_158 [ V_21 ] . V_73 != NULL )
F_62 ( V_158 [ V_21 ] . V_73 -> type -> V_140 ) ;
}
return V_46 ;
}
static int
F_131 ( struct V_148 * V_149 , struct V_167 * V_168 )
{
if ( F_111 ( V_149 -> V_1 , V_168 ) ) {
if ( F_123 ( V_168 , V_149 ) == NULL )
return - V_69 ;
F_113 ( V_149 -> V_1 , V_168 ) ;
return 0 ;
}
return - V_19 ;
}
static int F_132 ( struct V_148 * V_149 )
{
struct V_167 * V_168 ;
int V_46 ;
F_9 (rule, &ctx->chain->rules, list) {
V_46 = F_131 ( V_149 , V_168 ) ;
if ( V_46 < 0 )
return V_46 ;
}
return 0 ;
}
static int F_133 ( struct V_61 * V_62 , struct V_24 * V_25 ,
const struct V_30 * V_31 ,
const struct V_14 * const V_15 [] )
{
const struct V_32 * V_33 = F_24 ( V_31 ) ;
const struct V_2 * V_3 ;
struct V_1 * V_1 = F_32 ( V_25 -> V_43 ) ;
const struct V_13 * V_16 ;
struct V_70 * V_71 = NULL ;
struct V_167 * V_168 ;
int V_9 = V_33 -> V_35 , V_46 = 0 ;
struct V_148 V_149 ;
V_3 = F_10 ( V_1 , V_9 , false ) ;
if ( F_42 ( V_3 ) )
return F_43 ( V_3 ) ;
V_16 = F_16 ( V_3 , V_15 [ V_171 ] ) ;
if ( F_42 ( V_16 ) )
return F_43 ( V_16 ) ;
if ( V_15 [ V_172 ] ) {
V_71 = F_64 ( V_16 , V_15 [ V_172 ] ) ;
if ( F_42 ( V_71 ) )
return F_43 ( V_71 ) ;
}
F_94 ( & V_149 , V_25 , V_31 , V_3 , V_16 , V_71 , V_15 ) ;
if ( V_71 ) {
if ( V_15 [ V_173 ] ) {
V_168 = F_104 ( V_71 ,
V_15 [ V_173 ] ) ;
if ( F_42 ( V_168 ) )
return F_43 ( V_168 ) ;
V_46 = F_131 ( & V_149 , V_168 ) ;
} else {
V_46 = F_132 ( & V_149 ) ;
}
} else {
F_9 (chain, &table->chains, list) {
V_149 . V_71 = V_71 ;
V_46 = F_132 ( & V_149 ) ;
if ( V_46 < 0 )
break;
}
}
return V_46 ;
}
static int F_134 ( struct V_24 * V_25 )
{
struct V_1 * V_1 = F_32 ( V_25 -> V_43 ) ;
struct V_185 * V_186 , * V_190 ;
V_1 -> V_7 . V_182 ++ ;
V_1 -> V_7 . V_181 = F_110 ( V_1 ) ;
F_85 () ;
F_135 (rupd, tmp, &net->nft.commit_list, list) {
F_7 ( & V_186 -> V_6 ) ;
if ( F_109 ( V_1 , V_186 -> V_168 ) ) {
F_114 ( V_1 , V_186 -> V_168 ) ;
F_108 ( V_25 , V_186 -> V_31 , V_186 -> V_16 ,
V_186 -> V_71 , V_186 -> V_168 ,
V_183 , 0 ,
V_186 -> V_9 ) ;
F_57 ( V_186 ) ;
continue;
}
F_130 ( & V_186 -> V_168 -> V_6 ) ;
F_108 ( V_25 , V_186 -> V_31 , V_186 -> V_16 , V_186 -> V_71 ,
V_186 -> V_168 , V_174 , 0 ,
V_186 -> V_9 ) ;
F_122 ( V_186 -> V_168 ) ;
F_57 ( V_186 ) ;
}
return 0 ;
}
static int F_136 ( struct V_24 * V_25 )
{
struct V_1 * V_1 = F_32 ( V_25 -> V_43 ) ;
struct V_185 * V_186 , * V_190 ;
F_135 (rupd, tmp, &net->nft.commit_list, list) {
F_7 ( & V_186 -> V_6 ) ;
if ( ! F_111 ( V_1 , V_186 -> V_168 ) ) {
F_114 ( V_1 , V_186 -> V_168 ) ;
F_57 ( V_186 ) ;
continue;
}
F_130 ( & V_186 -> V_168 -> V_6 ) ;
F_122 ( V_186 -> V_168 ) ;
F_57 ( V_186 ) ;
}
return 0 ;
}
int F_137 ( struct V_199 * V_73 )
{
F_3 ( V_5 ) ;
F_4 ( & V_73 -> V_6 , & V_200 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_138 ( struct V_199 * V_73 )
{
F_3 ( V_5 ) ;
F_7 ( & V_73 -> V_6 ) ;
F_5 ( V_5 ) ;
}
static const struct V_199 * F_139 ( const struct V_14 * const V_15 [] )
{
const struct V_199 * V_73 ;
T_2 V_201 ;
#ifdef F_11
if ( F_92 ( & V_200 ) ) {
F_5 ( V_5 ) ;
F_12 ( L_4 ) ;
F_3 ( V_5 ) ;
if ( ! F_92 ( & V_200 ) )
return F_13 ( - V_11 ) ;
}
#endif
V_201 = 0 ;
if ( V_15 [ V_202 ] != NULL ) {
V_201 = F_52 ( F_53 ( V_15 [ V_202 ] ) ) ;
V_201 &= V_203 | V_204 ;
}
F_9 (ops, &nf_tables_set_ops, list) {
if ( ( V_73 -> V_201 & V_201 ) != V_201 )
continue;
if ( ! F_60 ( V_73 -> V_140 ) )
continue;
return V_73 ;
}
return F_13 ( - V_79 ) ;
}
static int F_140 ( struct V_148 * V_149 ,
const struct V_24 * V_25 ,
const struct V_30 * V_31 ,
const struct V_14 * const V_15 [] )
{
struct V_1 * V_1 = F_32 ( V_25 -> V_43 ) ;
const struct V_32 * V_33 = F_24 ( V_31 ) ;
const struct V_2 * V_3 ;
const struct V_13 * V_16 = NULL ;
V_3 = F_10 ( V_1 , V_33 -> V_35 , false ) ;
if ( F_42 ( V_3 ) )
return F_43 ( V_3 ) ;
if ( V_15 [ V_205 ] != NULL ) {
V_16 = F_16 ( V_3 , V_15 [ V_205 ] ) ;
if ( F_42 ( V_16 ) )
return F_43 ( V_16 ) ;
}
F_94 ( V_149 , V_25 , V_31 , V_3 , V_16 , NULL , V_15 ) ;
return 0 ;
}
struct V_206 * F_141 ( const struct V_13 * V_16 ,
const struct V_14 * V_15 )
{
struct V_206 * V_207 ;
if ( V_15 == NULL )
return F_13 ( - V_18 ) ;
F_9 (set, &table->sets, list) {
if ( ! F_15 ( V_15 , V_207 -> V_17 ) )
return V_207 ;
}
return F_13 ( - V_19 ) ;
}
static int F_142 ( struct V_148 * V_149 , struct V_206 * V_207 ,
const char * V_17 )
{
const struct V_206 * V_21 ;
const char * V_208 ;
unsigned long * V_209 ;
unsigned int V_192 = 0 ;
V_208 = F_143 ( V_17 , V_210 , '%' ) ;
if ( V_208 != NULL ) {
if ( V_208 [ 1 ] != 'd' || strchr ( V_208 + 2 , '%' ) )
return - V_18 ;
V_209 = ( unsigned long * ) F_144 ( V_50 ) ;
if ( V_209 == NULL )
return - V_69 ;
F_9 (i, &ctx->table->sets, list) {
if ( ! sscanf ( V_21 -> V_17 , V_17 , & V_192 ) )
continue;
if ( V_192 < 0 || V_192 > V_211 * V_212 )
continue;
F_145 ( V_192 , V_209 ) ;
}
V_192 = F_146 ( V_209 , V_211 * V_212 ) ;
F_147 ( ( unsigned long ) V_209 ) ;
}
snprintf ( V_207 -> V_17 , sizeof( V_207 -> V_17 ) , V_17 , V_192 ) ;
F_9 (i, &ctx->table->sets, list) {
if ( ! strcmp ( V_207 -> V_17 , V_21 -> V_17 ) )
return - V_213 ;
}
return 0 ;
}
static int F_148 ( struct V_24 * V_25 , const struct V_148 * V_149 ,
const struct V_206 * V_207 , T_7 V_28 , T_7 V_29 )
{
struct V_32 * V_33 ;
struct V_30 * V_31 ;
T_2 V_26 = F_31 ( V_149 -> V_25 ) . V_26 ;
T_2 V_27 = V_149 -> V_31 -> V_42 ;
V_28 |= V_5 << 8 ;
V_31 = F_23 ( V_25 , V_26 , V_27 , V_28 , sizeof( struct V_32 ) ,
V_29 ) ;
if ( V_31 == NULL )
goto V_34;
V_33 = F_24 ( V_31 ) ;
V_33 -> V_35 = V_149 -> V_3 -> V_9 ;
V_33 -> V_36 = V_37 ;
V_33 -> V_38 = 0 ;
if ( F_25 ( V_25 , V_205 , V_149 -> V_16 -> V_17 ) )
goto V_34;
if ( F_25 ( V_25 , V_214 , V_207 -> V_17 ) )
goto V_34;
if ( V_207 -> V_29 != 0 )
if ( F_26 ( V_25 , V_202 , F_27 ( V_207 -> V_29 ) ) )
goto V_34;
if ( F_26 ( V_25 , V_215 , F_27 ( V_207 -> V_216 ) ) )
goto V_34;
if ( F_26 ( V_25 , V_217 , F_27 ( V_207 -> V_218 ) ) )
goto V_34;
if ( V_207 -> V_29 & V_204 ) {
if ( F_26 ( V_25 , V_219 , F_27 ( V_207 -> V_220 ) ) )
goto V_34;
if ( F_26 ( V_25 , V_221 , F_27 ( V_207 -> V_196 ) ) )
goto V_34;
}
return F_28 ( V_25 , V_31 ) ;
V_34:
F_29 ( V_25 , V_31 ) ;
return - 1 ;
}
static int F_149 ( const struct V_148 * V_149 ,
const struct V_206 * V_207 ,
int V_28 )
{
struct V_24 * V_25 ;
T_2 V_26 = F_31 ( V_149 -> V_25 ) . V_26 ;
bool V_45 ;
int V_46 ;
V_45 = F_33 ( V_149 -> V_31 ) ;
if ( ! V_45 && ! F_34 ( V_149 -> V_1 , V_47 ) )
return 0 ;
V_46 = - V_48 ;
V_25 = F_35 ( V_49 , V_50 ) ;
if ( V_25 == NULL )
goto V_46;
V_46 = F_148 ( V_25 , V_149 , V_207 , V_28 , 0 ) ;
if ( V_46 < 0 ) {
F_36 ( V_25 ) ;
goto V_46;
}
V_46 = F_37 ( V_25 , V_149 -> V_1 , V_26 , V_47 , V_45 ,
V_50 ) ;
V_46:
if ( V_46 < 0 )
F_38 ( V_149 -> V_1 , V_26 , V_47 , V_46 ) ;
return V_46 ;
}
static int F_150 ( struct V_148 * V_149 , struct V_24 * V_25 ,
struct V_51 * V_52 )
{
const struct V_206 * V_207 ;
unsigned int V_53 = 0 , V_54 = V_52 -> args [ 0 ] ;
if ( V_52 -> args [ 1 ] )
return V_25 -> V_60 ;
F_9 (set, &ctx->table->sets, list) {
if ( V_53 < V_54 )
goto V_56;
if ( F_148 ( V_25 , V_149 , V_207 , V_222 ,
V_58 ) < 0 ) {
V_52 -> args [ 0 ] = V_53 ;
goto V_59;
}
V_56:
V_53 ++ ;
}
V_52 -> args [ 1 ] = 1 ;
V_59:
return V_25 -> V_60 ;
}
static int F_151 ( struct V_148 * V_149 , struct V_24 * V_25 ,
struct V_51 * V_52 )
{
const struct V_206 * V_207 ;
unsigned int V_53 , V_54 = V_52 -> args [ 0 ] ;
struct V_13 * V_16 , * V_223 = (struct V_13 * ) V_52 -> args [ 2 ] ;
if ( V_52 -> args [ 1 ] )
return V_25 -> V_60 ;
F_9 (table, &ctx->afi->tables, list) {
if ( V_223 ) {
if ( V_223 != V_16 )
continue;
V_223 = NULL ;
}
V_149 -> V_16 = V_16 ;
V_53 = 0 ;
F_9 (set, &ctx->table->sets, list) {
if ( V_53 < V_54 )
goto V_56;
if ( F_148 ( V_25 , V_149 , V_207 , V_222 ,
V_58 ) < 0 ) {
V_52 -> args [ 0 ] = V_53 ;
V_52 -> args [ 2 ] = ( unsigned long ) V_16 ;
goto V_59;
}
V_56:
V_53 ++ ;
}
}
V_52 -> args [ 1 ] = 1 ;
V_59:
return V_25 -> V_60 ;
}
static int F_152 ( struct V_24 * V_25 , struct V_51 * V_52 )
{
const struct V_32 * V_33 = F_24 ( V_52 -> V_31 ) ;
struct V_14 * V_15 [ V_224 + 1 ] ;
struct V_148 V_149 ;
int V_46 , V_74 ;
V_46 = F_153 ( V_52 -> V_31 , sizeof( * V_33 ) , V_15 , V_224 ,
V_225 ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_140 ( & V_149 , V_52 -> V_25 , V_52 -> V_31 , ( void * ) V_15 ) ;
if ( V_46 < 0 )
return V_46 ;
if ( V_149 . V_16 == NULL )
V_74 = F_151 ( & V_149 , V_25 , V_52 ) ;
else
V_74 = F_150 ( & V_149 , V_25 , V_52 ) ;
return V_74 ;
}
static int F_154 ( struct V_61 * V_62 , struct V_24 * V_25 ,
const struct V_30 * V_31 ,
const struct V_14 * const V_15 [] )
{
const struct V_206 * V_207 ;
struct V_148 V_149 ;
struct V_24 * V_63 ;
int V_46 ;
V_46 = F_140 ( & V_149 , V_25 , V_31 , V_15 ) ;
if ( V_46 < 0 )
return V_46 ;
if ( V_31 -> V_64 & V_65 ) {
struct V_66 V_67 = {
. V_68 = F_152 ,
} ;
return F_41 ( V_62 , V_25 , V_31 , & V_67 ) ;
}
V_207 = F_141 ( V_149 . V_16 , V_15 [ V_214 ] ) ;
if ( F_42 ( V_207 ) )
return F_43 ( V_207 ) ;
V_63 = F_44 ( V_49 , V_50 ) ;
if ( V_63 == NULL )
return - V_69 ;
V_46 = F_148 ( V_63 , & V_149 , V_207 , V_222 , 0 ) ;
if ( V_46 < 0 )
goto V_46;
return F_45 ( V_62 , V_63 , F_31 ( V_25 ) . V_26 ) ;
V_46:
F_36 ( V_63 ) ;
return V_46 ;
}
static int F_155 ( struct V_61 * V_62 , struct V_24 * V_25 ,
const struct V_30 * V_31 ,
const struct V_14 * const V_15 [] )
{
const struct V_32 * V_33 = F_24 ( V_31 ) ;
const struct V_199 * V_73 ;
const struct V_2 * V_3 ;
struct V_1 * V_1 = F_32 ( V_25 -> V_43 ) ;
struct V_13 * V_16 ;
struct V_206 * V_207 ;
struct V_148 V_149 ;
char V_17 [ V_210 ] ;
unsigned int V_191 ;
bool V_129 ;
T_2 V_216 , V_218 , V_196 , V_220 , V_29 ;
int V_46 ;
if ( V_15 [ V_205 ] == NULL ||
V_15 [ V_214 ] == NULL ||
V_15 [ V_217 ] == NULL )
return - V_18 ;
V_216 = V_226 ;
if ( V_15 [ V_215 ] != NULL ) {
V_216 = F_52 ( F_53 ( V_15 [ V_215 ] ) ) ;
if ( ( V_216 & V_227 ) == V_227 )
return - V_18 ;
}
V_218 = F_52 ( F_53 ( V_15 [ V_217 ] ) ) ;
if ( V_218 == 0 || V_218 > F_156 ( struct V_228 , V_155 ) )
return - V_18 ;
V_29 = 0 ;
if ( V_15 [ V_202 ] != NULL ) {
V_29 = F_52 ( F_53 ( V_15 [ V_202 ] ) ) ;
if ( V_29 & ~ ( V_229 | V_230 |
V_203 | V_204 ) )
return - V_18 ;
}
V_220 = 0 ;
V_196 = 0 ;
if ( V_15 [ V_219 ] != NULL ) {
if ( ! ( V_29 & V_204 ) )
return - V_18 ;
V_220 = F_52 ( F_53 ( V_15 [ V_219 ] ) ) ;
if ( ( V_220 & V_227 ) == V_227 &&
V_220 != V_231 )
return - V_18 ;
if ( V_220 != V_231 ) {
if ( V_15 [ V_221 ] == NULL )
return - V_18 ;
V_196 = F_52 ( F_53 ( V_15 [ V_221 ] ) ) ;
if ( V_196 == 0 ||
V_196 > F_156 ( struct V_228 , V_155 ) )
return - V_18 ;
} else
V_196 = sizeof( struct V_228 ) ;
} else if ( V_29 & V_204 )
return - V_18 ;
V_129 = V_31 -> V_64 & V_130 ? true : false ;
V_3 = F_10 ( V_1 , V_33 -> V_35 , V_129 ) ;
if ( F_42 ( V_3 ) )
return F_43 ( V_3 ) ;
V_16 = F_16 ( V_3 , V_15 [ V_205 ] ) ;
if ( F_42 ( V_16 ) )
return F_43 ( V_16 ) ;
F_94 ( & V_149 , V_25 , V_31 , V_3 , V_16 , NULL , V_15 ) ;
V_207 = F_141 ( V_16 , V_15 [ V_214 ] ) ;
if ( F_42 ( V_207 ) ) {
if ( F_43 ( V_207 ) != - V_19 )
return F_43 ( V_207 ) ;
V_207 = NULL ;
}
if ( V_207 != NULL ) {
if ( V_31 -> V_64 & V_76 )
return - V_77 ;
if ( V_31 -> V_64 & V_78 )
return - V_79 ;
return 0 ;
}
if ( ! ( V_31 -> V_64 & V_130 ) )
return - V_19 ;
V_73 = F_139 ( V_15 ) ;
if ( F_42 ( V_73 ) )
return F_43 ( V_73 ) ;
V_191 = 0 ;
if ( V_73 -> V_232 != NULL )
V_191 = V_73 -> V_232 ( V_15 ) ;
V_46 = - V_69 ;
V_207 = F_55 ( sizeof( * V_207 ) + V_191 , V_50 ) ;
if ( V_207 == NULL )
goto V_163;
F_56 ( V_17 , V_15 [ V_214 ] , sizeof( V_207 -> V_17 ) ) ;
V_46 = F_142 ( & V_149 , V_207 , V_17 ) ;
if ( V_46 < 0 )
goto V_197;
F_2 ( & V_207 -> V_233 ) ;
V_207 -> V_73 = V_73 ;
V_207 -> V_216 = V_216 ;
V_207 -> V_218 = V_218 ;
V_207 -> V_220 = V_220 ;
V_207 -> V_196 = V_196 ;
V_207 -> V_29 = V_29 ;
V_46 = V_73 -> V_165 ( V_207 , V_15 ) ;
if ( V_46 < 0 )
goto V_197;
F_4 ( & V_207 -> V_6 , & V_16 -> V_81 ) ;
F_149 ( & V_149 , V_207 , V_222 ) ;
return 0 ;
V_197:
F_57 ( V_207 ) ;
V_163:
F_62 ( V_73 -> V_140 ) ;
return V_46 ;
}
static void F_157 ( const struct V_148 * V_149 , struct V_206 * V_207 )
{
F_7 ( & V_207 -> V_6 ) ;
if ( ! ( V_207 -> V_29 & V_229 ) )
F_149 ( V_149 , V_207 , V_234 ) ;
V_207 -> V_73 -> V_166 ( V_207 ) ;
F_62 ( V_207 -> V_73 -> V_140 ) ;
F_57 ( V_207 ) ;
}
static int F_158 ( struct V_61 * V_62 , struct V_24 * V_25 ,
const struct V_30 * V_31 ,
const struct V_14 * const V_15 [] )
{
struct V_206 * V_207 ;
struct V_148 V_149 ;
int V_46 ;
if ( V_15 [ V_205 ] == NULL )
return - V_18 ;
V_46 = F_140 ( & V_149 , V_25 , V_31 , V_15 ) ;
if ( V_46 < 0 )
return V_46 ;
V_207 = F_141 ( V_149 . V_16 , V_15 [ V_214 ] ) ;
if ( F_42 ( V_207 ) )
return F_43 ( V_207 ) ;
if ( ! F_92 ( & V_207 -> V_233 ) )
return - V_83 ;
F_157 ( & V_149 , V_207 ) ;
return 0 ;
}
static int F_159 ( const struct V_148 * V_149 ,
const struct V_206 * V_207 ,
const struct V_235 * V_236 ,
const struct V_237 * V_178 )
{
enum V_238 V_239 ;
V_239 = F_160 ( V_207 -> V_220 ) ;
return F_161 ( V_149 , V_239 , & V_178 -> V_155 ,
V_207 -> V_220 == V_231 ?
V_231 : V_226 ) ;
}
int F_162 ( const struct V_148 * V_149 , struct V_206 * V_207 ,
struct V_240 * V_241 )
{
struct V_240 * V_21 ;
struct V_235 V_236 ;
if ( ! F_92 ( & V_207 -> V_233 ) && V_207 -> V_29 & V_229 )
return - V_83 ;
if ( V_207 -> V_29 & V_204 ) {
F_9 (i, &set->bindings, list) {
if ( V_21 -> V_71 == V_241 -> V_71 )
goto V_242;
}
V_236 . V_243 = 0 ;
V_236 . V_244 = 0 ;
V_236 . V_46 = 0 ;
V_236 . V_139 = F_159 ;
V_207 -> V_73 -> V_245 ( V_149 , V_207 , & V_236 ) ;
if ( V_236 . V_46 < 0 ) {
if ( V_207 -> V_29 & V_229 )
F_157 ( V_149 , V_207 ) ;
return V_236 . V_46 ;
}
}
V_242:
V_241 -> V_71 = V_149 -> V_71 ;
F_4 ( & V_241 -> V_6 , & V_207 -> V_233 ) ;
return 0 ;
}
void F_163 ( const struct V_148 * V_149 , struct V_206 * V_207 ,
struct V_240 * V_241 )
{
F_7 ( & V_241 -> V_6 ) ;
if ( F_92 ( & V_207 -> V_233 ) && V_207 -> V_29 & V_229 )
F_157 ( V_149 , V_207 ) ;
}
static int F_164 ( struct V_148 * V_149 ,
const struct V_24 * V_25 ,
const struct V_30 * V_31 ,
const struct V_14 * const V_15 [] )
{
const struct V_32 * V_33 = F_24 ( V_31 ) ;
const struct V_2 * V_3 ;
const struct V_13 * V_16 ;
struct V_1 * V_1 = F_32 ( V_25 -> V_43 ) ;
V_3 = F_10 ( V_1 , V_33 -> V_35 , false ) ;
if ( F_42 ( V_3 ) )
return F_43 ( V_3 ) ;
V_16 = F_16 ( V_3 , V_15 [ V_246 ] ) ;
if ( F_42 ( V_16 ) )
return F_43 ( V_16 ) ;
F_94 ( V_149 , V_25 , V_31 , V_3 , V_16 , NULL , V_15 ) ;
return 0 ;
}
static int F_165 ( struct V_24 * V_25 ,
const struct V_206 * V_207 ,
const struct V_237 * V_178 )
{
unsigned char * V_247 = F_166 ( V_25 ) ;
struct V_14 * V_94 ;
V_94 = F_68 ( V_25 , V_179 ) ;
if ( V_94 == NULL )
goto V_34;
if ( F_167 ( V_25 , V_248 , & V_178 -> V_249 , V_226 ,
V_207 -> V_218 ) < 0 )
goto V_34;
if ( V_207 -> V_29 & V_204 &&
! ( V_178 -> V_29 & V_250 ) &&
F_167 ( V_25 , V_251 , & V_178 -> V_155 ,
V_207 -> V_220 == V_231 ? V_231 : V_226 ,
V_207 -> V_196 ) < 0 )
goto V_34;
if ( V_178 -> V_29 != 0 )
if ( F_26 ( V_25 , V_252 , F_27 ( V_178 -> V_29 ) ) )
goto V_34;
F_71 ( V_25 , V_94 ) ;
return 0 ;
V_34:
F_29 ( V_25 , V_247 ) ;
return - V_253 ;
}
static int F_168 ( const struct V_148 * V_149 ,
const struct V_206 * V_207 ,
const struct V_235 * V_236 ,
const struct V_237 * V_178 )
{
struct V_254 * args ;
args = F_89 ( V_236 , struct V_254 , V_236 ) ;
return F_165 ( args -> V_25 , V_207 , V_178 ) ;
}
static int F_169 ( struct V_24 * V_25 , struct V_51 * V_52 )
{
const struct V_206 * V_207 ;
struct V_254 args ;
struct V_148 V_149 ;
struct V_14 * V_15 [ V_255 + 1 ] ;
struct V_32 * V_33 ;
struct V_30 * V_31 ;
struct V_14 * V_94 ;
T_2 V_26 , V_27 ;
int V_28 , V_46 ;
V_33 = F_24 ( V_52 -> V_31 ) ;
V_46 = F_153 ( V_52 -> V_31 , sizeof( * V_33 ) , V_15 , V_255 ,
V_256 ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_164 ( & V_149 , V_52 -> V_25 , V_52 -> V_31 , ( void * ) V_15 ) ;
if ( V_46 < 0 )
return V_46 ;
V_207 = F_141 ( V_149 . V_16 , V_15 [ V_257 ] ) ;
if ( F_42 ( V_207 ) )
return F_43 ( V_207 ) ;
V_28 = V_258 ;
V_28 |= V_5 << 8 ;
V_26 = F_31 ( V_52 -> V_25 ) . V_26 ;
V_27 = V_52 -> V_31 -> V_42 ;
V_31 = F_23 ( V_25 , V_26 , V_27 , V_28 , sizeof( struct V_32 ) ,
V_58 ) ;
if ( V_31 == NULL )
goto V_34;
V_33 = F_24 ( V_31 ) ;
V_33 -> V_35 = V_55 ;
V_33 -> V_36 = V_37 ;
V_33 -> V_38 = 0 ;
if ( F_25 ( V_25 , V_246 , V_149 . V_16 -> V_17 ) )
goto V_34;
if ( F_25 ( V_25 , V_257 , V_207 -> V_17 ) )
goto V_34;
V_94 = F_68 ( V_25 , V_259 ) ;
if ( V_94 == NULL )
goto V_34;
args . V_52 = V_52 ;
args . V_25 = V_25 ;
args . V_236 . V_243 = V_52 -> args [ 0 ] ;
args . V_236 . V_244 = 0 ;
args . V_236 . V_46 = 0 ;
args . V_236 . V_139 = F_168 ;
V_207 -> V_73 -> V_245 ( & V_149 , V_207 , & args . V_236 ) ;
F_71 ( V_25 , V_94 ) ;
F_28 ( V_25 , V_31 ) ;
if ( args . V_236 . V_46 && args . V_236 . V_46 != - V_253 )
return args . V_236 . V_46 ;
if ( args . V_236 . V_244 == V_52 -> args [ 0 ] )
return 0 ;
V_52 -> args [ 0 ] = args . V_236 . V_244 ;
return V_25 -> V_60 ;
V_34:
return - V_101 ;
}
static int F_170 ( struct V_61 * V_62 , struct V_24 * V_25 ,
const struct V_30 * V_31 ,
const struct V_14 * const V_15 [] )
{
const struct V_206 * V_207 ;
struct V_148 V_149 ;
int V_46 ;
V_46 = F_164 ( & V_149 , V_25 , V_31 , V_15 ) ;
if ( V_46 < 0 )
return V_46 ;
V_207 = F_141 ( V_149 . V_16 , V_15 [ V_257 ] ) ;
if ( F_42 ( V_207 ) )
return F_43 ( V_207 ) ;
if ( V_31 -> V_64 & V_65 ) {
struct V_66 V_67 = {
. V_68 = F_169 ,
} ;
return F_41 ( V_62 , V_25 , V_31 , & V_67 ) ;
}
return - V_79 ;
}
static int F_171 ( const struct V_148 * V_149 , struct V_206 * V_207 ,
const struct V_14 * V_118 )
{
struct V_14 * V_15 [ V_260 + 1 ] ;
struct V_261 V_262 , V_263 ;
struct V_237 V_178 ;
struct V_240 * V_241 ;
enum V_238 V_239 ;
int V_46 ;
V_46 = F_78 ( V_15 , V_260 , V_118 ,
V_264 ) ;
if ( V_46 < 0 )
return V_46 ;
if ( V_15 [ V_248 ] == NULL )
return - V_18 ;
V_178 . V_29 = 0 ;
if ( V_15 [ V_252 ] != NULL ) {
V_178 . V_29 = F_52 ( F_53 ( V_15 [ V_252 ] ) ) ;
if ( V_178 . V_29 & ~ V_250 )
return - V_18 ;
}
if ( V_207 -> V_29 & V_204 ) {
if ( V_15 [ V_251 ] == NULL &&
! ( V_178 . V_29 & V_250 ) )
return - V_18 ;
} else {
if ( V_15 [ V_251 ] != NULL )
return - V_18 ;
}
V_46 = F_172 ( V_149 , & V_178 . V_249 , & V_262 , V_15 [ V_248 ] ) ;
if ( V_46 < 0 )
goto V_163;
V_46 = - V_18 ;
if ( V_262 . type != V_226 || V_262 . V_60 != V_207 -> V_218 )
goto V_197;
V_46 = - V_77 ;
if ( V_207 -> V_73 -> V_265 ( V_207 , & V_178 ) == 0 )
goto V_197;
if ( V_15 [ V_251 ] != NULL ) {
V_46 = F_172 ( V_149 , & V_178 . V_155 , & V_263 , V_15 [ V_251 ] ) ;
if ( V_46 < 0 )
goto V_197;
V_46 = - V_18 ;
if ( V_207 -> V_220 != V_231 && V_263 . V_60 != V_207 -> V_196 )
goto V_198;
V_239 = F_160 ( V_207 -> V_220 ) ;
F_9 (binding, &set->bindings, list) {
struct V_148 V_266 = {
. V_3 = V_149 -> V_3 ,
. V_16 = V_149 -> V_16 ,
. V_71 = V_241 -> V_71 ,
} ;
V_46 = F_161 ( & V_266 , V_239 ,
& V_178 . V_155 , V_263 . type ) ;
if ( V_46 < 0 )
goto V_198;
}
}
V_46 = V_207 -> V_73 -> V_267 ( V_207 , & V_178 ) ;
if ( V_46 < 0 )
goto V_198;
return 0 ;
V_198:
if ( V_15 [ V_251 ] != NULL )
F_173 ( & V_178 . V_155 , V_263 . type ) ;
V_197:
F_173 ( & V_178 . V_249 , V_262 . type ) ;
V_163:
return V_46 ;
}
static int F_174 ( struct V_61 * V_62 , struct V_24 * V_25 ,
const struct V_30 * V_31 ,
const struct V_14 * const V_15 [] )
{
const struct V_14 * V_118 ;
struct V_206 * V_207 ;
struct V_148 V_149 ;
int V_193 , V_46 ;
V_46 = F_164 ( & V_149 , V_25 , V_31 , V_15 ) ;
if ( V_46 < 0 )
return V_46 ;
V_207 = F_141 ( V_149 . V_16 , V_15 [ V_257 ] ) ;
if ( F_42 ( V_207 ) )
return F_43 ( V_207 ) ;
if ( ! F_92 ( & V_207 -> V_233 ) && V_207 -> V_29 & V_230 )
return - V_83 ;
F_126 (attr, nla[NFTA_SET_ELEM_LIST_ELEMENTS], rem) {
V_46 = F_171 ( & V_149 , V_207 , V_118 ) ;
if ( V_46 < 0 )
return V_46 ;
}
return 0 ;
}
static int F_175 ( const struct V_148 * V_149 , struct V_206 * V_207 ,
const struct V_14 * V_118 )
{
struct V_14 * V_15 [ V_260 + 1 ] ;
struct V_261 V_268 ;
struct V_237 V_178 ;
int V_46 ;
V_46 = F_78 ( V_15 , V_260 , V_118 ,
V_264 ) ;
if ( V_46 < 0 )
goto V_163;
V_46 = - V_18 ;
if ( V_15 [ V_248 ] == NULL )
goto V_163;
V_46 = F_172 ( V_149 , & V_178 . V_249 , & V_268 , V_15 [ V_248 ] ) ;
if ( V_46 < 0 )
goto V_163;
V_46 = - V_18 ;
if ( V_268 . type != V_226 || V_268 . V_60 != V_207 -> V_218 )
goto V_197;
V_46 = V_207 -> V_73 -> V_265 ( V_207 , & V_178 ) ;
if ( V_46 < 0 )
goto V_197;
V_207 -> V_73 -> remove ( V_207 , & V_178 ) ;
F_173 ( & V_178 . V_249 , V_226 ) ;
if ( V_207 -> V_29 & V_204 )
F_173 ( & V_178 . V_155 , V_207 -> V_220 ) ;
V_197:
F_173 ( & V_178 . V_249 , V_268 . type ) ;
V_163:
return V_46 ;
}
static int F_176 ( struct V_61 * V_62 , struct V_24 * V_25 ,
const struct V_30 * V_31 ,
const struct V_14 * const V_15 [] )
{
const struct V_14 * V_118 ;
struct V_206 * V_207 ;
struct V_148 V_149 ;
int V_193 , V_46 ;
V_46 = F_164 ( & V_149 , V_25 , V_31 , V_15 ) ;
if ( V_46 < 0 )
return V_46 ;
V_207 = F_141 ( V_149 . V_16 , V_15 [ V_257 ] ) ;
if ( F_42 ( V_207 ) )
return F_43 ( V_207 ) ;
if ( ! F_92 ( & V_207 -> V_233 ) && V_207 -> V_29 & V_230 )
return - V_83 ;
F_126 (attr, nla[NFTA_SET_ELEM_LIST_ELEMENTS], rem) {
V_46 = F_175 ( & V_149 , V_207 , V_118 ) ;
if ( V_46 < 0 )
return V_46 ;
}
return 0 ;
}
static int F_177 ( const struct V_148 * V_149 ,
const struct V_206 * V_207 ,
const struct V_235 * V_236 ,
const struct V_237 * V_178 )
{
switch ( V_178 -> V_155 . V_269 ) {
case V_270 :
case V_271 :
return F_178 ( V_149 , V_178 -> V_155 . V_71 ) ;
default:
return 0 ;
}
}
static int F_178 ( const struct V_148 * V_149 ,
const struct V_70 * V_71 )
{
const struct V_167 * V_168 ;
const struct V_152 * V_153 , * V_272 ;
const struct V_206 * V_207 ;
struct V_240 * V_241 ;
struct V_235 V_236 ;
if ( V_149 -> V_71 == V_71 )
return - V_273 ;
F_9 (rule, &chain->rules, list) {
F_107 (expr, last, rule) {
const struct V_228 * V_155 = NULL ;
int V_46 ;
if ( ! V_153 -> V_73 -> V_274 )
continue;
V_46 = V_153 -> V_73 -> V_274 ( V_149 , V_153 , & V_155 ) ;
if ( V_46 < 0 )
return V_46 ;
if ( V_155 == NULL )
continue;
switch ( V_155 -> V_269 ) {
case V_270 :
case V_271 :
V_46 = F_178 ( V_149 , V_155 -> V_71 ) ;
if ( V_46 < 0 )
return V_46 ;
default:
break;
}
}
}
F_9 (set, &ctx->table->sets, list) {
if ( ! ( V_207 -> V_29 & V_204 ) ||
V_207 -> V_220 != V_231 )
continue;
F_9 (binding, &set->bindings, list) {
if ( V_241 -> V_71 != V_71 )
continue;
V_236 . V_243 = 0 ;
V_236 . V_244 = 0 ;
V_236 . V_46 = 0 ;
V_236 . V_139 = F_177 ;
V_207 -> V_73 -> V_245 ( V_149 , V_207 , & V_236 ) ;
if ( V_236 . V_46 < 0 )
return V_236 . V_46 ;
}
}
return 0 ;
}
int F_179 ( enum V_238 V_275 )
{
if ( V_275 <= V_276 )
return - V_18 ;
if ( V_275 > V_277 )
return - V_278 ;
return 0 ;
}
int F_180 ( enum V_238 V_275 )
{
if ( V_275 < V_276 )
return - V_18 ;
if ( V_275 > V_277 )
return - V_278 ;
return 0 ;
}
int F_161 ( const struct V_148 * V_149 , enum V_238 V_275 ,
const struct V_228 * V_155 ,
enum V_279 type )
{
int V_46 ;
switch ( V_275 ) {
case V_276 :
if ( V_155 == NULL || type != V_231 )
return - V_18 ;
if ( V_155 -> V_269 == V_271 || V_155 -> V_269 == V_270 ) {
V_46 = F_178 ( V_149 , V_155 -> V_71 ) ;
if ( V_46 < 0 )
return V_46 ;
if ( V_149 -> V_71 -> V_280 + 1 > V_155 -> V_71 -> V_280 ) {
if ( V_149 -> V_71 -> V_280 + 1 == V_281 )
return - V_282 ;
V_155 -> V_71 -> V_280 = V_149 -> V_71 -> V_280 + 1 ;
}
}
return 0 ;
default:
if ( V_155 != NULL && type != V_226 )
return - V_18 ;
return 0 ;
}
}
static int F_181 ( const struct V_148 * V_149 , struct V_228 * V_155 ,
struct V_261 * V_268 , const struct V_14 * V_15 )
{
struct V_14 * V_121 [ V_283 + 1 ] ;
struct V_70 * V_71 ;
int V_46 ;
V_46 = F_78 ( V_121 , V_283 , V_15 , V_284 ) ;
if ( V_46 < 0 )
return V_46 ;
if ( ! V_121 [ V_285 ] )
return - V_18 ;
V_155 -> V_269 = F_52 ( F_53 ( V_121 [ V_285 ] ) ) ;
switch ( V_155 -> V_269 ) {
case V_120 :
case V_119 :
case V_286 :
case V_287 :
case V_288 :
case V_289 :
V_268 -> V_60 = sizeof( V_155 -> V_269 ) ;
break;
case V_270 :
case V_271 :
if ( ! V_121 [ V_290 ] )
return - V_18 ;
V_71 = F_64 ( V_149 -> V_16 ,
V_121 [ V_290 ] ) ;
if ( F_42 ( V_71 ) )
return F_43 ( V_71 ) ;
if ( V_71 -> V_29 & V_72 )
return - V_79 ;
V_71 -> V_82 ++ ;
V_155 -> V_71 = V_71 ;
V_268 -> V_60 = sizeof( V_155 ) ;
break;
default:
return - V_18 ;
}
V_268 -> type = V_231 ;
return 0 ;
}
static void F_182 ( const struct V_228 * V_155 )
{
switch ( V_155 -> V_269 ) {
case V_270 :
case V_271 :
V_155 -> V_71 -> V_82 -- ;
break;
}
}
static int F_183 ( struct V_24 * V_25 , const struct V_228 * V_155 )
{
struct V_14 * V_94 ;
V_94 = F_68 ( V_25 , V_291 ) ;
if ( ! V_94 )
goto V_34;
if ( F_26 ( V_25 , V_285 , F_27 ( V_155 -> V_269 ) ) )
goto V_34;
switch ( V_155 -> V_269 ) {
case V_270 :
case V_271 :
if ( F_25 ( V_25 , V_290 , V_155 -> V_71 -> V_17 ) )
goto V_34;
}
F_71 ( V_25 , V_94 ) ;
return 0 ;
V_34:
return - 1 ;
}
static int F_184 ( const struct V_148 * V_149 , struct V_228 * V_155 ,
struct V_261 * V_268 , const struct V_14 * V_15 )
{
unsigned int V_60 ;
V_60 = F_20 ( V_15 ) ;
if ( V_60 == 0 )
return - V_18 ;
if ( V_60 > sizeof( V_155 -> V_155 ) )
return - V_132 ;
F_185 ( V_155 -> V_155 , V_15 , sizeof( V_155 -> V_155 ) ) ;
V_268 -> type = V_226 ;
V_268 -> V_60 = V_60 ;
return 0 ;
}
static int F_186 ( struct V_24 * V_25 , const struct V_228 * V_155 ,
unsigned int V_60 )
{
return F_187 ( V_25 , V_292 , V_60 , V_155 -> V_155 ) ;
}
int F_172 ( const struct V_148 * V_149 , struct V_228 * V_155 ,
struct V_261 * V_268 , const struct V_14 * V_15 )
{
struct V_14 * V_121 [ V_293 + 1 ] ;
int V_46 ;
V_46 = F_78 ( V_121 , V_293 , V_15 , V_294 ) ;
if ( V_46 < 0 )
return V_46 ;
if ( V_121 [ V_292 ] )
return F_184 ( V_149 , V_155 , V_268 , V_121 [ V_292 ] ) ;
if ( V_121 [ V_291 ] && V_149 != NULL )
return F_181 ( V_149 , V_155 , V_268 , V_121 [ V_291 ] ) ;
return - V_18 ;
}
void F_173 ( const struct V_228 * V_155 , enum V_279 type )
{
switch ( type ) {
case V_226 :
return;
case V_231 :
return F_182 ( V_155 ) ;
default:
F_188 ( 1 ) ;
}
}
int F_167 ( struct V_24 * V_25 , int V_118 , const struct V_228 * V_155 ,
enum V_279 type , unsigned int V_60 )
{
struct V_14 * V_94 ;
int V_46 ;
V_94 = F_68 ( V_25 , V_118 ) ;
if ( V_94 == NULL )
return - 1 ;
switch ( type ) {
case V_226 :
V_46 = F_186 ( V_25 , V_155 , V_60 ) ;
break;
case V_231 :
V_46 = F_183 ( V_25 , V_155 ) ;
break;
default:
V_46 = - V_18 ;
F_188 ( 1 ) ;
}
F_71 ( V_25 , V_94 ) ;
return V_46 ;
}
static int F_189 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_7 . V_8 ) ;
F_2 ( & V_1 -> V_7 . V_187 ) ;
return 0 ;
}
static int T_8 F_190 ( void )
{
int V_46 ;
V_158 = F_124 ( sizeof( struct V_157 ) * V_195 ,
V_50 ) ;
if ( V_158 == NULL ) {
V_46 = - V_69 ;
goto V_163;
}
V_46 = F_191 () ;
if ( V_46 < 0 )
goto V_197;
V_46 = F_192 ( & V_295 ) ;
if ( V_46 < 0 )
goto V_198;
F_193 ( L_5 ) ;
return F_194 ( & V_296 ) ;
V_198:
F_195 () ;
V_197:
F_57 ( V_158 ) ;
V_163:
return V_46 ;
}
static void T_9 F_196 ( void )
{
F_197 ( & V_296 ) ;
F_198 ( & V_295 ) ;
F_195 () ;
F_57 ( V_158 ) ;
}
