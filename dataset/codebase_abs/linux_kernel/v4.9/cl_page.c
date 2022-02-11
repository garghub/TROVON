static void F_1 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( & V_2 -> V_3 ) > 0 ) ;
F_4 ( & V_2 -> V_3 ) ;
}
static const struct V_4 *
F_5 ( const struct V_1 * V_2 ,
const struct V_5 * V_6 )
{
const struct V_4 * V_7 ;
F_6 (slice, &page->cp_layers, cpl_linkage) {
if ( V_7 -> V_8 -> V_9 . V_10 -> V_11 == V_6 )
return V_7 ;
}
return NULL ;
}
static void F_7 ( const struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
F_8 ( V_13 , V_2 , F_9 ( & V_2 -> V_17 ) ) ;
F_8 ( V_13 , V_2 , ! V_2 -> V_18 ) ;
F_8 ( V_13 , V_2 , ! V_2 -> V_19 ) ;
F_8 ( V_13 , V_2 , V_2 -> V_20 == V_21 ) ;
while ( ! F_9 ( & V_2 -> V_22 ) ) {
struct V_4 * V_7 ;
V_7 = F_10 ( V_2 -> V_22 . V_23 ,
struct V_4 , V_24 ) ;
F_11 ( V_2 -> V_22 . V_23 ) ;
if ( F_12 ( V_7 -> V_25 -> V_26 ) )
V_7 -> V_25 -> V_26 ( V_13 , V_7 ) ;
}
F_13 ( & V_15 -> V_9 , & V_2 -> V_27 , L_1 , V_2 ) ;
F_14 ( V_13 , V_15 ) ;
F_15 ( & V_2 -> V_28 ) ;
F_16 ( V_2 ) ;
}
static inline void F_17 ( struct V_1 * V_2 ,
enum V_29 V_30 )
{
* (enum V_29 * ) & V_2 -> V_20 = V_30 ;
}
struct V_1 * F_18 ( const struct V_12 * V_13 ,
struct V_14 * V_31 , T_1 V_32 ,
struct V_2 * V_33 ,
enum V_34 type )
{
struct V_1 * V_2 ;
struct V_35 * V_36 ;
V_2 = F_19 ( F_20 ( V_31 ) -> V_37 , V_38 ) ;
if ( V_2 ) {
int V_39 = 0 ;
F_21 ( & V_2 -> V_3 , 1 ) ;
V_2 -> V_16 = V_31 ;
F_22 ( V_31 ) ;
F_23 ( & V_31 -> V_9 , & V_2 -> V_27 , L_1 ,
V_2 ) ;
V_2 -> V_40 = V_33 ;
F_17 ( V_2 , V_41 ) ;
V_2 -> V_42 = type ;
F_24 ( & V_2 -> V_22 ) ;
F_24 ( & V_2 -> V_17 ) ;
F_24 ( & V_2 -> V_43 ) ;
F_25 ( & V_2 -> V_28 ) ;
V_36 = V_31 -> V_9 . V_44 ;
F_6 (o, &head->loh_layers, co_lu.lo_linkage) {
if ( V_31 -> V_45 -> V_46 ) {
V_39 = V_31 -> V_45 -> V_46 ( V_13 , V_31 , V_2 ,
V_32 ) ;
if ( V_39 != 0 ) {
F_26 ( V_13 , V_2 ) ;
F_7 ( V_13 , V_2 ) ;
V_2 = F_27 ( V_39 ) ;
break;
}
}
}
} else {
V_2 = F_27 ( - V_47 ) ;
}
return V_2 ;
}
struct V_1 * F_28 ( const struct V_12 * V_13 ,
struct V_14 * V_31 ,
T_1 V_48 , struct V_2 * V_33 ,
enum V_34 type )
{
struct V_1 * V_2 = NULL ;
struct F_20 * V_49 ;
F_2 ( type == V_50 || type == V_51 ) ;
F_29 () ;
V_49 = F_20 ( V_31 ) ;
F_30 ( V_52 , L_2 V_53 L_3 ,
V_48 , F_31 ( & V_49 -> V_54 . V_55 ) , V_33 , V_33 -> V_56 , type ) ;
if ( type == V_50 ) {
F_32 ( F_33 ( V_33 ) ) ;
V_2 = F_34 ( V_33 , V_31 ) ;
if ( V_2 )
return V_2 ;
}
V_2 = F_18 ( V_13 , V_31 , V_48 , V_33 , type ) ;
return V_2 ;
}
static inline int F_35 ( const struct V_1 * V_57 )
{
return F_36 ( V_57 ) ;
}
static void F_37 ( const struct V_12 * V_13 ,
struct V_1 * V_2 , enum V_29 V_30 )
{
enum V_29 V_58 ;
static const int V_59 [ V_60 ] [ V_60 ] = {
[ V_41 ] = {
[ V_41 ] = 0 ,
[ V_61 ] = 1 ,
[ V_62 ] = 0 ,
[ V_63 ] = 1 ,
[ V_21 ] = 1 ,
} ,
[ V_61 ] = {
[ V_41 ] = 1 ,
[ V_61 ] = 0 ,
[ V_62 ] = 1 ,
[ V_63 ] = 1 ,
[ V_21 ] = 1 ,
} ,
[ V_62 ] = {
[ V_41 ] = 1 ,
[ V_61 ] = 0 ,
[ V_62 ] = 0 ,
[ V_63 ] = 0 ,
[ V_21 ] = 0 ,
} ,
[ V_63 ] = {
[ V_41 ] = 1 ,
[ V_61 ] = 0 ,
[ V_62 ] = 0 ,
[ V_63 ] = 0 ,
[ V_21 ] = 0 ,
} ,
[ V_21 ] = {
[ V_41 ] = 0 ,
[ V_61 ] = 0 ,
[ V_62 ] = 0 ,
[ V_63 ] = 0 ,
[ V_21 ] = 0 ,
}
} ;
V_58 = V_2 -> V_20 ;
F_8 ( V_13 , V_2 , V_59 [ V_58 ] [ V_30 ] ) ;
F_38 ( V_64 , V_13 , V_2 , L_4 , V_58 , V_30 ) ;
F_8 ( V_13 , V_2 , V_2 -> V_20 == V_58 ) ;
F_8 ( V_13 , V_2 , F_39 ( V_30 == V_61 , V_2 -> V_18 ) ) ;
F_17 ( V_2 , V_30 ) ;
}
static void F_40 ( const struct V_12 * V_13 ,
struct V_1 * V_2 , enum V_29 V_30 )
{
F_37 ( V_13 , V_2 , V_30 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
}
void F_42 ( const struct V_12 * V_13 , struct V_1 * V_2 )
{
F_38 ( V_64 , V_13 , V_2 , L_5 ,
F_3 ( & V_2 -> V_3 ) ) ;
if ( F_43 ( & V_2 -> V_3 ) ) {
F_2 ( V_2 -> V_20 == V_21 ) ;
F_2 ( F_3 ( & V_2 -> V_3 ) == 0 ) ;
F_8 ( V_13 , V_2 , ! V_2 -> V_18 ) ;
F_8 ( V_13 , V_2 , F_9 ( & V_2 -> V_17 ) ) ;
F_7 ( V_13 , V_2 ) ;
}
}
struct V_1 * F_34 ( struct V_2 * V_33 , struct V_14 * V_15 )
{
struct V_1 * V_2 ;
F_32 ( F_33 ( V_33 ) ) ;
V_2 = (struct V_1 * ) V_33 -> V_56 ;
if ( V_2 ) {
F_1 ( V_2 ) ;
F_2 ( V_2 -> V_42 == V_50 ) ;
}
return V_2 ;
}
const struct V_4 * F_44 ( const struct V_1 * V_2 ,
const struct V_5 * V_6 )
{
return F_5 ( V_2 , V_6 ) ;
}
static int F_45 ( const struct V_12 * V_13 ,
struct V_65 * V_66 , struct V_1 * V_2 , T_2 V_67 )
{
F_46 ( V_13 , V_2 , F_47 ( V_2 -> V_16 , V_66 -> V_68 ) ) ;
return F_48 ( V_13 , V_2 , V_67 ,
( const struct V_12 * ,
const struct V_4 * , struct V_65 * ) ,
V_66 ) ;
}
static void F_49 ( const struct V_12 * V_13 ,
struct V_65 * V_66 , struct V_1 * V_2 , T_2 V_67 )
{
F_46 ( V_13 , V_2 , F_47 ( V_2 -> V_16 , V_66 -> V_68 ) ) ;
F_50 ( V_13 , V_2 , V_67 ,
( const struct V_12 * ,
const struct V_4 * , struct V_65 * ) , V_66 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
if ( V_2 -> V_18 ) {
F_2 ( V_2 -> V_18 -> V_69 > 0 ) ;
V_2 -> V_18 -> V_69 -- ;
V_2 -> V_18 = NULL ;
}
}
static void F_52 ( struct V_1 * V_2 )
{
V_2 -> V_18 -> V_69 ++ ;
}
void F_53 ( const struct V_12 * V_13 ,
struct V_65 * V_66 , struct V_1 * V_57 )
{
enum V_29 V_30 ;
V_30 = V_57 -> V_20 ;
F_46 ( V_13 , V_57 , V_30 == V_61 || V_30 == V_21 ) ;
F_46 ( V_13 , V_57 , F_35 ( V_57 ) || V_30 == V_21 ) ;
F_51 ( V_57 ) ;
if ( V_30 == V_61 )
F_40 ( V_13 , V_57 , V_41 ) ;
F_54 ( V_13 , V_57 , F_55 ( V_70 ) ,
( const struct V_12 * ,
const struct V_4 * , struct V_65 * ) ,
V_66 ) ;
}
int F_56 ( const struct V_1 * V_57 , const struct V_65 * V_66 )
{
struct V_65 * V_71 = F_57 ( (struct V_65 * ) V_66 ) ;
F_58 ( F_47 ( V_57 -> V_16 , V_66 -> V_68 ) ) ;
return V_57 -> V_20 == V_61 && V_57 -> V_18 == V_71 ;
}
static int F_59 ( const struct V_12 * V_13 , struct V_65 * V_66 ,
struct V_1 * V_57 , int V_72 )
{
int V_39 ;
F_46 ( V_13 , V_57 , ! F_56 ( V_57 , V_66 ) ) ;
V_66 = F_57 ( V_66 ) ;
if ( V_57 -> V_20 == V_21 ) {
V_39 = - V_73 ;
} else {
V_39 = F_48 ( V_13 , V_57 , F_55 ( V_74 ) ,
( const struct V_12 * ,
const struct V_4 * ,
struct V_65 * , int ) ,
V_66 , V_72 ) ;
if ( V_39 == 0 ) {
F_8 ( V_13 , V_57 , ! V_57 -> V_18 ) ;
F_8 ( V_13 , V_57 , ! V_57 -> V_19 ) ;
V_57 -> V_18 = F_57 ( V_66 ) ;
F_52 ( V_57 ) ;
if ( V_57 -> V_20 != V_21 ) {
F_40 ( V_13 , V_57 , V_61 ) ;
} else {
F_53 ( V_13 , V_66 , V_57 ) ;
V_39 = - V_73 ;
}
}
}
F_46 ( V_13 , V_57 , F_60 ( V_39 == 0 , F_35 ( V_57 ) ) ) ;
return V_39 ;
}
int F_61 ( const struct V_12 * V_13 , struct V_65 * V_66 , struct V_1 * V_57 )
{
return F_59 ( V_13 , V_66 , V_57 , 0 ) ;
}
int F_62 ( const struct V_12 * V_13 , struct V_65 * V_66 ,
struct V_1 * V_57 )
{
return F_59 ( V_13 , V_66 , V_57 , 1 ) ;
}
void F_63 ( const struct V_12 * V_13 ,
struct V_65 * V_66 , struct V_1 * V_57 )
{
F_46 ( V_13 , V_57 , F_47 ( V_57 -> V_16 , V_66 -> V_68 ) ) ;
V_66 = F_57 ( V_66 ) ;
F_49 ( V_13 , V_66 , V_57 , F_55 ( V_75 ) ) ;
F_8 ( V_13 , V_57 , ! V_57 -> V_18 ) ;
V_57 -> V_18 = F_57 ( V_66 ) ;
F_52 ( V_57 ) ;
F_40 ( V_13 , V_57 , V_61 ) ;
}
void F_64 ( const struct V_12 * V_13 ,
struct V_65 * V_66 , struct V_1 * V_57 )
{
F_46 ( V_13 , V_57 , F_56 ( V_57 , V_66 ) ) ;
F_46 ( V_13 , V_57 , F_35 ( V_57 ) ) ;
V_66 = F_57 ( V_66 ) ;
F_51 ( V_57 ) ;
F_40 ( V_13 , V_57 , V_41 ) ;
F_54 ( V_13 , V_57 , F_55 ( V_76 ) ,
( const struct V_12 * ,
const struct V_4 * , struct V_65 * ) ,
V_66 ) ;
}
void F_65 ( const struct V_12 * V_13 ,
struct V_65 * V_66 , struct V_1 * V_57 )
{
F_46 ( V_13 , V_57 , F_56 ( V_57 , V_66 ) ||
V_57 -> V_20 == V_21 ) ;
V_66 = F_57 ( V_66 ) ;
F_53 ( V_13 , V_66 , V_57 ) ;
}
void F_66 ( const struct V_12 * V_13 ,
struct V_65 * V_66 , struct V_1 * V_57 )
{
F_46 ( V_13 , V_57 , F_56 ( V_57 , V_66 ) ) ;
F_46 ( V_13 , V_57 , F_35 ( V_57 ) ) ;
F_49 ( V_13 , V_66 , V_57 , F_55 ( V_77 ) ) ;
}
static void F_26 ( const struct V_12 * V_13 , struct V_1 * V_57 )
{
F_8 ( V_13 , V_57 , V_57 -> V_20 != V_21 ) ;
F_51 ( V_57 ) ;
F_37 ( V_13 , V_57 , V_21 ) ;
F_54 ( V_13 , V_57 , F_55 ( V_78 ) ,
( const struct V_12 * ,
const struct V_4 * ) ) ;
}
void F_67 ( const struct V_12 * V_13 , struct V_1 * V_57 )
{
F_46 ( V_13 , V_57 , F_35 ( V_57 ) ) ;
F_26 ( V_13 , V_57 ) ;
}
void F_68 ( const struct V_12 * V_13 , struct V_1 * V_57 , int V_79 )
{
F_46 ( V_13 , V_57 , F_35 ( V_57 ) ) ;
F_50 ( V_13 , V_57 , F_55 ( V_80 ) ,
( const struct V_12 * ,
const struct V_4 * , int ) , V_79 ) ;
}
int F_69 ( const struct V_12 * V_13 , const struct V_1 * V_57 )
{
int V_39 ;
const struct V_4 * V_7 ;
V_7 = F_70 ( V_57 -> V_22 . V_23 ,
const struct V_4 , V_24 ) ;
F_8 ( V_13 , V_57 , V_7 -> V_25 -> V_81 ) ;
V_39 = V_7 -> V_25 -> V_81 ( V_13 , V_7 ) ;
F_8 ( V_13 , V_57 , V_39 == - V_82 || V_39 == - V_83 ) ;
return V_39 == - V_82 ;
}
static enum V_29 F_71 ( enum V_84 V_85 )
{
return V_85 == V_86 ? V_63 : V_62 ;
}
static void F_72 ( const struct V_12 * V_13 ,
struct V_1 * V_57 , enum V_84 V_85 )
{
F_51 ( V_57 ) ;
F_40 ( V_13 , V_57 , F_71 ( V_85 ) ) ;
}
int F_73 ( const struct V_12 * V_13 , struct V_65 * V_66 ,
struct V_1 * V_57 , enum V_84 V_85 )
{
int V_39 ;
F_46 ( V_13 , V_57 , F_56 ( V_57 , V_66 ) ) ;
F_46 ( V_13 , V_57 , F_35 ( V_57 ) ) ;
F_46 ( V_13 , V_57 , V_85 < V_87 ) ;
if ( V_85 >= V_87 )
return - V_88 ;
V_39 = F_45 ( V_13 , V_66 , V_57 , F_55 ( V_66 [ V_85 ] . V_89 ) ) ;
if ( V_39 == 0 )
F_72 ( V_13 , V_57 , V_85 ) ;
F_38 ( V_64 , V_13 , V_57 , L_6 , V_85 , V_39 ) ;
return V_39 ;
}
void F_74 ( const struct V_12 * V_13 ,
struct V_1 * V_57 , enum V_84 V_85 , int V_90 )
{
struct V_91 * V_92 = V_57 -> V_93 ;
F_8 ( V_13 , V_57 , V_85 < V_87 ) ;
F_8 ( V_13 , V_57 , ! V_57 -> V_19 ) ;
F_8 ( V_13 , V_57 , V_57 -> V_20 == F_71 ( V_85 ) ) ;
F_38 ( V_64 , V_13 , V_57 , L_6 , V_85 , V_90 ) ;
F_40 ( V_13 , V_57 , V_41 ) ;
if ( V_85 >= V_87 )
return;
F_54 ( V_13 , V_57 , F_55 ( V_66 [ V_85 ] . V_94 ) ,
( const struct V_12 * ,
const struct V_4 * , int ) , V_90 ) ;
if ( V_92 ) {
F_2 ( V_57 -> V_93 == V_92 ) ;
V_57 -> V_93 = NULL ;
}
F_42 ( V_13 , V_57 ) ;
if ( V_92 )
F_75 ( V_13 , V_92 , V_90 ) ;
}
int F_76 ( const struct V_12 * V_13 , struct V_1 * V_57 ,
enum V_84 V_85 )
{
int V_39 ;
F_46 ( V_13 , V_57 , V_85 < V_87 ) ;
if ( V_85 >= V_87 )
return - V_88 ;
V_39 = F_48 ( V_13 , V_57 , F_55 ( V_66 [ V_85 ] . V_95 ) ,
( const struct V_12 * ,
const struct V_4 * ) ) ;
if ( V_39 == 0 ) {
F_8 ( V_13 , V_57 , V_57 -> V_20 == V_41 ) ;
F_72 ( V_13 , V_57 , V_85 ) ;
}
F_38 ( V_64 , V_13 , V_57 , L_6 , V_85 , V_39 ) ;
return V_39 ;
}
int F_77 ( const struct V_12 * V_13 , struct V_65 * V_66 ,
struct V_1 * V_57 )
{
int V_39 ;
F_46 ( V_13 , V_57 , F_56 ( V_57 , V_66 ) ) ;
F_46 ( V_13 , V_57 , F_35 ( V_57 ) ) ;
V_39 = F_45 ( V_13 , V_66 , V_57 , F_55 ( V_96 ) ) ;
F_38 ( V_64 , V_13 , V_57 , L_5 , V_39 ) ;
return V_39 ;
}
int F_78 ( const struct V_12 * V_13 , struct V_65 * V_66 ,
struct V_1 * V_2 , T_1 * V_97 )
{
int V_98 ;
F_46 ( V_13 , V_2 , F_35 ( V_2 ) ) ;
V_98 = F_79 ( V_13 , V_2 , F_55 ( V_99 ) ,
( const struct V_12 * ,
const struct V_4 * ,
struct V_65 * , T_1 * ) ,
V_66 , V_97 ) ;
return V_98 ;
}
void F_80 ( const struct V_12 * V_13 , struct V_1 * V_57 ,
int V_100 , int V_101 )
{
F_46 ( V_13 , V_57 , F_35 ( V_57 ) ) ;
F_38 ( V_64 , V_13 , V_57 , L_6 , V_100 , V_101 ) ;
F_50 ( V_13 , V_57 , F_55 ( V_102 ) ,
( const struct V_12 * ,
const struct V_4 * , int , int ) ,
V_100 , V_101 ) ;
}
void F_81 ( const struct V_12 * V_13 , void * V_103 ,
T_3 V_104 , const struct V_1 * V_57 )
{
(* V_104)( V_13 , V_103 ,
L_7 ,
V_57 , F_3 ( & V_57 -> V_3 ) , V_57 -> V_16 ,
V_57 -> V_20 , V_57 -> V_42 ,
V_57 -> V_18 , V_57 -> V_19 ) ;
}
void F_82 ( const struct V_12 * V_13 , void * V_103 ,
T_3 V_104 , const struct V_1 * V_57 )
{
F_81 ( V_13 , V_103 , V_104 , V_57 ) ;
F_48 ( V_13 , (struct V_1 * ) V_57 , F_55 ( V_105 ) ,
( const struct V_12 * V_13 ,
const struct V_4 * V_7 ,
void * V_103 , T_3 V_106 ) , V_103 , V_104 ) ;
(* V_104)( V_13 , V_103 , L_8 , V_57 ) ;
}
int F_83 ( const struct V_12 * V_13 , struct V_1 * V_2 )
{
return F_48 ( V_13 , V_2 , F_55 ( V_107 ) ,
( const struct V_12 * ,
const struct V_4 * ) ) ;
}
T_4 F_84 ( const struct V_14 * V_15 , T_1 V_48 )
{
return ( T_4 ) V_48 << V_108 ;
}
T_1 F_85 ( const struct V_14 * V_15 , T_4 V_109 )
{
return V_109 >> V_108 ;
}
T_5 F_86 ( const struct V_14 * V_15 )
{
return 1UL << V_108 ;
}
void F_87 ( struct V_1 * V_2 , struct V_4 * V_7 ,
struct V_14 * V_15 , T_1 V_110 ,
const struct V_111 * V_112 )
{
F_88 ( & V_7 -> V_24 , & V_2 -> V_22 ) ;
V_7 -> V_8 = V_15 ;
V_7 -> V_113 = V_110 ;
V_7 -> V_25 = V_112 ;
V_7 -> V_114 = V_2 ;
}
struct V_115 * F_89 ( unsigned long V_116 )
{
struct V_115 * V_117 = NULL ;
V_117 = F_19 ( sizeof( * V_117 ) , V_118 ) ;
if ( ! V_117 )
return NULL ;
F_21 ( & V_117 -> V_119 , 1 ) ;
V_117 -> V_120 = V_116 ;
F_90 ( & V_117 -> V_121 , V_116 ) ;
F_91 ( & V_117 -> V_122 ) ;
F_24 ( & V_117 -> V_123 ) ;
F_90 ( & V_117 -> V_124 , 0 ) ;
F_92 ( & V_117 -> V_125 ) ;
return V_117 ;
}
void F_93 ( struct V_115 * V_117 )
{
F_4 ( & V_117 -> V_119 ) ;
}
void F_94 ( struct V_115 * V_117 )
{
if ( F_43 ( & V_117 -> V_119 ) )
F_16 ( V_117 ) ;
}
