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
F_25 ( & V_2 -> V_44 ) ;
F_26 ( & V_2 -> V_28 ) ;
V_36 = V_31 -> V_9 . V_45 ;
F_6 (o, &head->loh_layers, co_lu.lo_linkage) {
if ( V_31 -> V_46 -> V_47 ) {
V_39 = V_31 -> V_46 -> V_47 ( V_13 , V_31 , V_2 ,
V_32 ) ;
if ( V_39 != 0 ) {
F_27 ( V_13 , V_2 ) ;
F_7 ( V_13 , V_2 ) ;
V_2 = F_28 ( V_39 ) ;
break;
}
}
}
} else {
V_2 = F_28 ( - V_48 ) ;
}
return V_2 ;
}
struct V_1 * F_29 ( const struct V_12 * V_13 ,
struct V_14 * V_31 ,
T_1 V_49 , struct V_2 * V_33 ,
enum V_34 type )
{
struct V_1 * V_2 = NULL ;
struct F_20 * V_50 ;
F_2 ( type == V_51 || type == V_52 ) ;
F_30 () ;
V_50 = F_20 ( V_31 ) ;
F_31 ( V_53 , L_2 V_54 L_3 ,
V_49 , F_32 ( & V_50 -> V_55 . V_56 ) , V_33 , V_33 -> V_57 , type ) ;
if ( type == V_51 ) {
F_33 ( F_34 ( V_33 ) ) ;
V_2 = F_35 ( V_33 , V_31 ) ;
if ( V_2 )
return V_2 ;
}
V_2 = F_18 ( V_13 , V_31 , V_49 , V_33 , type ) ;
return V_2 ;
}
static inline int F_36 ( const struct V_1 * V_58 )
{
F_37 ( F_38 ( NULL , V_58 ) ) ;
return F_39 ( V_58 ) ;
}
static void F_40 ( const struct V_12 * V_13 ,
struct V_1 * V_2 , enum V_29 V_30 )
{
enum V_29 V_59 ;
static const int V_60 [ V_61 ] [ V_61 ] = {
[ V_41 ] = {
[ V_41 ] = 0 ,
[ V_62 ] = 1 ,
[ V_63 ] = 0 ,
[ V_64 ] = 1 ,
[ V_21 ] = 1 ,
} ,
[ V_62 ] = {
[ V_41 ] = 1 ,
[ V_62 ] = 0 ,
[ V_63 ] = 1 ,
[ V_64 ] = 1 ,
[ V_21 ] = 1 ,
} ,
[ V_63 ] = {
[ V_41 ] = 1 ,
[ V_62 ] = 0 ,
[ V_63 ] = 0 ,
[ V_64 ] = 0 ,
[ V_21 ] = 0 ,
} ,
[ V_64 ] = {
[ V_41 ] = 1 ,
[ V_62 ] = 0 ,
[ V_63 ] = 0 ,
[ V_64 ] = 0 ,
[ V_21 ] = 0 ,
} ,
[ V_21 ] = {
[ V_41 ] = 0 ,
[ V_62 ] = 0 ,
[ V_63 ] = 0 ,
[ V_64 ] = 0 ,
[ V_21 ] = 0 ,
}
} ;
V_59 = V_2 -> V_20 ;
F_8 ( V_13 , V_2 , V_60 [ V_59 ] [ V_30 ] ) ;
F_41 ( V_65 , V_13 , V_2 , L_4 , V_59 , V_30 ) ;
F_8 ( V_13 , V_2 , V_2 -> V_20 == V_59 ) ;
F_8 ( V_13 , V_2 , F_42 ( V_30 == V_62 , V_2 -> V_18 ) ) ;
F_17 ( V_2 , V_30 ) ;
}
static void F_43 ( const struct V_12 * V_13 ,
struct V_1 * V_2 , enum V_29 V_30 )
{
F_40 ( V_13 , V_2 , V_30 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
}
void F_45 ( const struct V_12 * V_13 , struct V_1 * V_2 )
{
F_41 ( V_65 , V_13 , V_2 , L_5 ,
F_3 ( & V_2 -> V_3 ) ) ;
if ( F_46 ( & V_2 -> V_3 ) ) {
F_2 ( V_2 -> V_20 == V_21 ) ;
F_2 ( F_3 ( & V_2 -> V_3 ) == 0 ) ;
F_8 ( V_13 , V_2 , ! V_2 -> V_18 ) ;
F_8 ( V_13 , V_2 , F_9 ( & V_2 -> V_17 ) ) ;
F_7 ( V_13 , V_2 ) ;
}
}
struct V_1 * F_35 ( struct V_2 * V_33 , struct V_14 * V_15 )
{
struct V_1 * V_2 ;
F_33 ( F_34 ( V_33 ) ) ;
V_2 = (struct V_1 * ) V_33 -> V_57 ;
if ( V_2 ) {
F_1 ( V_2 ) ;
F_2 ( V_2 -> V_42 == V_51 ) ;
}
return V_2 ;
}
const struct V_4 * F_47 ( const struct V_1 * V_2 ,
const struct V_5 * V_6 )
{
return F_5 ( V_2 , V_6 ) ;
}
static int F_48 ( const struct V_12 * V_13 ,
struct V_66 * V_67 , struct V_1 * V_2 , T_2 V_68 )
{
F_49 ( V_13 , V_2 , F_50 ( V_2 -> V_16 , V_67 -> V_69 ) ) ;
return F_51 ( V_13 , V_2 , V_68 ,
( const struct V_12 * ,
const struct V_4 * , struct V_66 * ) ,
V_67 ) ;
}
static void F_52 ( const struct V_12 * V_13 ,
struct V_66 * V_67 , struct V_1 * V_2 , T_2 V_68 )
{
F_49 ( V_13 , V_2 , F_50 ( V_2 -> V_16 , V_67 -> V_69 ) ) ;
F_53 ( V_13 , V_2 , V_68 ,
( const struct V_12 * ,
const struct V_4 * , struct V_66 * ) , V_67 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
if ( V_2 -> V_18 ) {
F_2 ( V_2 -> V_18 -> V_70 > 0 ) ;
V_2 -> V_18 -> V_70 -- ;
V_2 -> V_18 = NULL ;
V_2 -> V_71 = NULL ;
}
}
static void F_55 ( struct V_1 * V_2 )
{
V_2 -> V_18 -> V_70 ++ ;
}
void F_56 ( const struct V_12 * V_13 ,
struct V_66 * V_67 , struct V_1 * V_58 )
{
enum V_29 V_30 ;
V_30 = V_58 -> V_20 ;
F_49 ( V_13 , V_58 , V_30 == V_62 || V_30 == V_21 ) ;
F_49 ( V_13 , V_58 , F_36 ( V_58 ) || V_30 == V_21 ) ;
F_54 ( V_58 ) ;
if ( V_30 == V_62 )
F_43 ( V_13 , V_58 , V_41 ) ;
F_57 ( V_13 , V_58 , F_58 ( V_72 ) ,
( const struct V_12 * ,
const struct V_4 * , struct V_66 * ) ,
V_67 ) ;
}
int F_59 ( const struct V_1 * V_58 , const struct V_66 * V_67 )
{
struct V_66 * V_73 = F_60 ( (struct V_66 * ) V_67 ) ;
F_37 ( F_50 ( V_58 -> V_16 , V_67 -> V_69 ) ) ;
return V_58 -> V_20 == V_62 && V_58 -> V_18 == V_73 ;
}
static int F_61 ( const struct V_12 * V_13 , struct V_66 * V_67 ,
struct V_1 * V_58 , int V_74 )
{
int V_39 ;
F_49 ( V_13 , V_58 , ! F_59 ( V_58 , V_67 ) ) ;
V_67 = F_60 ( V_67 ) ;
if ( V_58 -> V_20 == V_21 ) {
V_39 = - V_75 ;
} else {
V_39 = F_51 ( V_13 , V_58 , F_58 ( V_76 ) ,
( const struct V_12 * ,
const struct V_4 * ,
struct V_66 * , int ) ,
V_67 , V_74 ) ;
if ( V_39 == 0 ) {
F_8 ( V_13 , V_58 , ! V_58 -> V_18 ) ;
F_8 ( V_13 , V_58 , ! V_58 -> V_19 ) ;
V_58 -> V_18 = F_60 ( V_67 ) ;
V_58 -> V_71 = V_77 ;
F_55 ( V_58 ) ;
if ( V_58 -> V_20 != V_21 ) {
F_43 ( V_13 , V_58 , V_62 ) ;
} else {
F_56 ( V_13 , V_67 , V_58 ) ;
V_39 = - V_75 ;
}
}
}
F_49 ( V_13 , V_58 , F_62 ( V_39 == 0 , F_36 ( V_58 ) ) ) ;
return V_39 ;
}
int F_63 ( const struct V_12 * V_13 , struct V_66 * V_67 , struct V_1 * V_58 )
{
return F_61 ( V_13 , V_67 , V_58 , 0 ) ;
}
int F_64 ( const struct V_12 * V_13 , struct V_66 * V_67 ,
struct V_1 * V_58 )
{
return F_61 ( V_13 , V_67 , V_58 , 1 ) ;
}
void F_65 ( const struct V_12 * V_13 ,
struct V_66 * V_67 , struct V_1 * V_58 )
{
F_49 ( V_13 , V_58 , F_50 ( V_58 -> V_16 , V_67 -> V_69 ) ) ;
V_67 = F_60 ( V_67 ) ;
F_52 ( V_13 , V_67 , V_58 , F_58 ( V_78 ) ) ;
F_8 ( V_13 , V_58 , ! V_58 -> V_18 ) ;
V_58 -> V_18 = F_60 ( V_67 ) ;
V_58 -> V_71 = V_77 ;
F_55 ( V_58 ) ;
F_43 ( V_13 , V_58 , V_62 ) ;
}
void F_66 ( const struct V_12 * V_13 ,
struct V_66 * V_67 , struct V_1 * V_58 )
{
F_49 ( V_13 , V_58 , F_59 ( V_58 , V_67 ) ) ;
F_49 ( V_13 , V_58 , F_36 ( V_58 ) ) ;
V_67 = F_60 ( V_67 ) ;
F_54 ( V_58 ) ;
F_43 ( V_13 , V_58 , V_41 ) ;
F_57 ( V_13 , V_58 , F_58 ( V_79 ) ,
( const struct V_12 * ,
const struct V_4 * , struct V_66 * ) ,
V_67 ) ;
}
void F_67 ( const struct V_12 * V_13 ,
struct V_66 * V_67 , struct V_1 * V_58 )
{
F_49 ( V_13 , V_58 , F_59 ( V_58 , V_67 ) ||
V_58 -> V_20 == V_21 ) ;
V_67 = F_60 ( V_67 ) ;
F_56 ( V_13 , V_67 , V_58 ) ;
}
void F_68 ( const struct V_12 * V_13 ,
struct V_66 * V_67 , struct V_1 * V_58 )
{
F_49 ( V_13 , V_58 , F_59 ( V_58 , V_67 ) ) ;
F_49 ( V_13 , V_58 , F_36 ( V_58 ) ) ;
F_52 ( V_13 , V_67 , V_58 , F_58 ( V_80 ) ) ;
}
static void F_27 ( const struct V_12 * V_13 , struct V_1 * V_58 )
{
F_8 ( V_13 , V_58 , V_58 -> V_20 != V_21 ) ;
F_54 ( V_58 ) ;
F_40 ( V_13 , V_58 , V_21 ) ;
F_57 ( V_13 , V_58 , F_58 ( V_81 ) ,
( const struct V_12 * ,
const struct V_4 * ) ) ;
}
void F_69 ( const struct V_12 * V_13 , struct V_1 * V_58 )
{
F_49 ( V_13 , V_58 , F_36 ( V_58 ) ) ;
F_27 ( V_13 , V_58 ) ;
}
void F_70 ( const struct V_12 * V_13 , struct V_1 * V_58 , int V_82 )
{
F_49 ( V_13 , V_58 , F_36 ( V_58 ) ) ;
F_53 ( V_13 , V_58 , F_58 ( V_83 ) ,
( const struct V_12 * ,
const struct V_4 * , int ) , V_82 ) ;
}
int F_38 ( const struct V_12 * V_13 , const struct V_1 * V_58 )
{
int V_39 ;
const struct V_4 * V_7 ;
V_7 = F_71 ( V_58 -> V_22 . V_23 ,
const struct V_4 , V_24 ) ;
F_8 ( V_13 , V_58 , V_7 -> V_25 -> V_84 ) ;
V_39 = V_7 -> V_25 -> V_84 ( V_13 , V_7 ) ;
F_8 ( V_13 , V_58 , V_39 == - V_85 || V_39 == - V_86 ) ;
return V_39 == - V_85 ;
}
static enum V_29 F_72 ( enum V_87 V_88 )
{
return V_88 == V_89 ? V_64 : V_63 ;
}
static void F_73 ( const struct V_12 * V_13 ,
struct V_1 * V_58 , enum V_87 V_88 )
{
F_54 ( V_58 ) ;
F_43 ( V_13 , V_58 , F_72 ( V_88 ) ) ;
}
int F_74 ( const struct V_12 * V_13 , struct V_66 * V_67 ,
struct V_1 * V_58 , enum V_87 V_88 )
{
int V_39 ;
F_49 ( V_13 , V_58 , F_59 ( V_58 , V_67 ) ) ;
F_49 ( V_13 , V_58 , F_36 ( V_58 ) ) ;
F_49 ( V_13 , V_58 , V_88 < V_90 ) ;
if ( V_88 >= V_90 )
return - V_91 ;
V_39 = F_48 ( V_13 , V_67 , V_58 , F_58 ( V_67 [ V_88 ] . V_92 ) ) ;
if ( V_39 == 0 )
F_73 ( V_13 , V_58 , V_88 ) ;
F_41 ( V_65 , V_13 , V_58 , L_6 , V_88 , V_39 ) ;
return V_39 ;
}
void F_75 ( const struct V_12 * V_13 ,
struct V_1 * V_58 , enum V_87 V_88 , int V_93 )
{
struct V_94 * V_95 = V_58 -> V_96 ;
F_8 ( V_13 , V_58 , V_88 < V_90 ) ;
F_8 ( V_13 , V_58 , ! V_58 -> V_19 ) ;
F_8 ( V_13 , V_58 , V_58 -> V_20 == F_72 ( V_88 ) ) ;
F_41 ( V_65 , V_13 , V_58 , L_6 , V_88 , V_93 ) ;
if ( V_88 == V_97 && V_93 == 0 ) {
F_8 ( V_13 , V_58 , ! ( V_58 -> V_98 & V_99 ) ) ;
V_58 -> V_98 |= V_99 ;
}
F_43 ( V_13 , V_58 , V_41 ) ;
if ( V_88 >= V_90 )
return;
F_57 ( V_13 , V_58 , F_58 ( V_67 [ V_88 ] . V_100 ) ,
( const struct V_12 * ,
const struct V_4 * , int ) , V_93 ) ;
if ( V_95 ) {
F_2 ( F_38 ( V_13 , V_58 ) ) ;
F_2 ( V_58 -> V_96 == V_95 ) ;
V_58 -> V_96 = NULL ;
}
F_45 ( V_13 , V_58 ) ;
if ( V_95 )
F_76 ( V_13 , V_95 , V_93 ) ;
}
int F_77 ( const struct V_12 * V_13 , struct V_1 * V_58 ,
enum V_87 V_88 )
{
int V_39 ;
F_49 ( V_13 , V_58 , V_88 < V_90 ) ;
if ( V_88 >= V_90 )
return - V_91 ;
V_39 = F_51 ( V_13 , V_58 , F_58 ( V_67 [ V_88 ] . V_101 ) ,
( const struct V_12 * ,
const struct V_4 * ) ) ;
if ( V_39 == 0 ) {
F_8 ( V_13 , V_58 , V_58 -> V_20 == V_41 ) ;
F_73 ( V_13 , V_58 , V_88 ) ;
}
F_41 ( V_65 , V_13 , V_58 , L_6 , V_88 , V_39 ) ;
return V_39 ;
}
int F_78 ( const struct V_12 * V_13 , struct V_66 * V_67 ,
struct V_1 * V_58 )
{
int V_39 ;
F_49 ( V_13 , V_58 , F_59 ( V_58 , V_67 ) ) ;
F_49 ( V_13 , V_58 , F_36 ( V_58 ) ) ;
V_39 = F_48 ( V_13 , V_67 , V_58 , F_58 ( V_102 ) ) ;
F_41 ( V_65 , V_13 , V_58 , L_5 , V_39 ) ;
return V_39 ;
}
int F_79 ( const struct V_12 * V_13 , struct V_66 * V_67 ,
struct V_1 * V_2 , T_1 * V_103 )
{
int V_104 ;
F_49 ( V_13 , V_2 , F_36 ( V_2 ) ) ;
V_104 = F_80 ( V_13 , V_2 , F_58 ( V_105 ) ,
( const struct V_12 * ,
const struct V_4 * ,
struct V_66 * , T_1 * ) ,
V_67 , V_103 ) ;
return V_104 ;
}
void F_81 ( const struct V_12 * V_13 , struct V_1 * V_58 ,
int V_106 , int V_107 )
{
F_49 ( V_13 , V_58 , F_36 ( V_58 ) ) ;
F_41 ( V_65 , V_13 , V_58 , L_6 , V_106 , V_107 ) ;
F_53 ( V_13 , V_58 , F_58 ( V_108 ) ,
( const struct V_12 * ,
const struct V_4 * , int , int ) ,
V_106 , V_107 ) ;
}
void F_82 ( const struct V_12 * V_13 , void * V_109 ,
T_3 V_110 , const struct V_1 * V_58 )
{
(* V_110)( V_13 , V_109 ,
L_7 ,
V_58 , F_3 ( & V_58 -> V_3 ) , V_58 -> V_16 ,
V_58 -> V_20 , V_58 -> V_111 , V_58 -> V_42 ,
V_58 -> V_18 , V_58 -> V_19 , V_58 -> V_98 ) ;
}
void F_83 ( const struct V_12 * V_13 , void * V_109 ,
T_3 V_110 , const struct V_1 * V_58 )
{
F_82 ( V_13 , V_109 , V_110 , V_58 ) ;
F_51 ( V_13 , (struct V_1 * ) V_58 , F_58 ( V_112 ) ,
( const struct V_12 * V_13 ,
const struct V_4 * V_7 ,
void * V_109 , T_3 V_113 ) , V_109 , V_110 ) ;
(* V_110)( V_13 , V_109 , L_8 , V_58 ) ;
}
int F_84 ( const struct V_12 * V_13 , struct V_1 * V_2 )
{
return F_51 ( V_13 , V_2 , F_58 ( V_114 ) ,
( const struct V_12 * ,
const struct V_4 * ) ) ;
}
T_4 F_85 ( const struct V_14 * V_15 , T_1 V_49 )
{
return ( T_4 ) V_49 << V_115 ;
}
T_1 F_86 ( const struct V_14 * V_15 , T_4 V_116 )
{
return V_116 >> V_115 ;
}
int F_87 ( const struct V_14 * V_15 )
{
return 1 << V_115 ;
}
void F_88 ( struct V_1 * V_2 , struct V_4 * V_7 ,
struct V_14 * V_15 , T_1 V_117 ,
const struct V_118 * V_119 )
{
F_89 ( & V_7 -> V_24 , & V_2 -> V_22 ) ;
V_7 -> V_8 = V_15 ;
V_7 -> V_120 = V_117 ;
V_7 -> V_25 = V_119 ;
V_7 -> V_121 = V_2 ;
}
struct V_122 * F_90 ( unsigned long V_123 )
{
struct V_122 * V_124 = NULL ;
V_124 = F_19 ( sizeof( * V_124 ) , V_125 ) ;
if ( ! V_124 )
return NULL ;
F_21 ( & V_124 -> V_126 , 1 ) ;
V_124 -> V_127 = V_123 ;
F_21 ( & V_124 -> V_128 , V_123 ) ;
F_91 ( & V_124 -> V_129 ) ;
F_24 ( & V_124 -> V_130 ) ;
F_21 ( & V_124 -> V_131 , 0 ) ;
F_92 ( & V_124 -> V_132 ) ;
return V_124 ;
}
void F_93 ( struct V_122 * V_124 )
{
F_4 ( & V_124 -> V_126 ) ;
}
void F_94 ( struct V_122 * V_124 )
{
if ( F_46 ( & V_124 -> V_126 ) )
F_16 ( V_124 ) ;
}
