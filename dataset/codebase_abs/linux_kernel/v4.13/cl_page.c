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
F_8 ( V_13 , V_2 , V_2 -> V_19 == V_20 ) ;
while ( ! F_9 ( & V_2 -> V_21 ) ) {
struct V_4 * V_7 ;
V_7 = F_10 ( V_2 -> V_21 . V_22 ,
struct V_4 , V_23 ) ;
F_11 ( V_2 -> V_21 . V_22 ) ;
if ( F_12 ( V_7 -> V_24 -> V_25 ) )
V_7 -> V_24 -> V_25 ( V_13 , V_7 ) ;
}
F_13 ( & V_15 -> V_9 , & V_2 -> V_26 , L_1 , V_2 ) ;
F_14 ( V_13 , V_15 ) ;
F_15 ( & V_2 -> V_27 ) ;
F_16 ( V_2 ) ;
}
static inline void F_17 ( struct V_1 * V_2 ,
enum V_28 V_29 )
{
* (enum V_28 * ) & V_2 -> V_19 = V_29 ;
}
struct V_1 * F_18 ( const struct V_12 * V_13 ,
struct V_14 * V_30 , T_1 V_31 ,
struct V_2 * V_32 ,
enum V_33 type )
{
struct V_1 * V_2 ;
struct V_34 * V_35 ;
V_2 = F_19 ( F_20 ( V_30 ) -> V_36 , V_37 ) ;
if ( V_2 ) {
int V_38 = 0 ;
F_21 ( & V_2 -> V_3 , 1 ) ;
V_2 -> V_16 = V_30 ;
F_22 ( V_30 ) ;
F_23 ( & V_30 -> V_9 , & V_2 -> V_26 , L_1 ,
V_2 ) ;
V_2 -> V_39 = V_32 ;
F_17 ( V_2 , V_40 ) ;
V_2 -> V_41 = type ;
F_24 ( & V_2 -> V_21 ) ;
F_24 ( & V_2 -> V_17 ) ;
F_25 ( & V_2 -> V_27 ) ;
V_35 = V_30 -> V_9 . V_42 ;
F_6 (o, &head->loh_layers, co_lu.lo_linkage) {
if ( V_30 -> V_43 -> V_44 ) {
V_38 = V_30 -> V_43 -> V_44 ( V_13 , V_30 , V_2 ,
V_31 ) ;
if ( V_38 != 0 ) {
F_26 ( V_13 , V_2 ) ;
F_7 ( V_13 , V_2 ) ;
V_2 = F_27 ( V_38 ) ;
break;
}
}
}
} else {
V_2 = F_27 ( - V_45 ) ;
}
return V_2 ;
}
struct V_1 * F_28 ( const struct V_12 * V_13 ,
struct V_14 * V_30 ,
T_1 V_46 , struct V_2 * V_32 ,
enum V_33 type )
{
struct V_1 * V_2 = NULL ;
struct F_20 * V_47 ;
F_2 ( type == V_48 || type == V_49 ) ;
F_29 () ;
V_47 = F_20 ( V_30 ) ;
F_30 ( V_50 , L_2 V_51 L_3 ,
V_46 , F_31 ( & V_47 -> V_52 . V_53 ) , V_32 , V_32 -> V_54 , type ) ;
if ( type == V_48 ) {
F_32 ( F_33 ( V_32 ) ) ;
V_2 = F_34 ( V_32 , V_30 ) ;
if ( V_2 )
return V_2 ;
}
V_2 = F_18 ( V_13 , V_30 , V_46 , V_32 , type ) ;
return V_2 ;
}
static inline int F_35 ( const struct V_1 * V_55 )
{
return F_36 ( V_55 ) ;
}
static void F_37 ( const struct V_12 * V_13 ,
struct V_1 * V_2 , enum V_28 V_29 )
{
enum V_28 V_56 ;
static const int V_57 [ V_58 ] [ V_58 ] = {
[ V_40 ] = {
[ V_40 ] = 0 ,
[ V_59 ] = 1 ,
[ V_60 ] = 0 ,
[ V_61 ] = 1 ,
[ V_20 ] = 1 ,
} ,
[ V_59 ] = {
[ V_40 ] = 1 ,
[ V_59 ] = 0 ,
[ V_60 ] = 1 ,
[ V_61 ] = 1 ,
[ V_20 ] = 1 ,
} ,
[ V_60 ] = {
[ V_40 ] = 1 ,
[ V_59 ] = 0 ,
[ V_60 ] = 0 ,
[ V_61 ] = 0 ,
[ V_20 ] = 0 ,
} ,
[ V_61 ] = {
[ V_40 ] = 1 ,
[ V_59 ] = 0 ,
[ V_60 ] = 0 ,
[ V_61 ] = 0 ,
[ V_20 ] = 0 ,
} ,
[ V_20 ] = {
[ V_40 ] = 0 ,
[ V_59 ] = 0 ,
[ V_60 ] = 0 ,
[ V_61 ] = 0 ,
[ V_20 ] = 0 ,
}
} ;
V_56 = V_2 -> V_19 ;
F_8 ( V_13 , V_2 , V_57 [ V_56 ] [ V_29 ] ) ;
F_38 ( V_62 , V_13 , V_2 , L_4 , V_56 , V_29 ) ;
F_8 ( V_13 , V_2 , V_2 -> V_19 == V_56 ) ;
F_8 ( V_13 , V_2 , F_39 ( V_29 == V_59 , V_2 -> V_18 ) ) ;
F_17 ( V_2 , V_29 ) ;
}
static void F_40 ( const struct V_12 * V_13 ,
struct V_1 * V_2 , enum V_28 V_29 )
{
F_37 ( V_13 , V_2 , V_29 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
}
void F_42 ( const struct V_12 * V_13 , struct V_1 * V_2 )
{
F_38 ( V_62 , V_13 , V_2 , L_5 ,
F_3 ( & V_2 -> V_3 ) ) ;
if ( F_43 ( & V_2 -> V_3 ) ) {
F_2 ( V_2 -> V_19 == V_20 ) ;
F_2 ( F_3 ( & V_2 -> V_3 ) == 0 ) ;
F_8 ( V_13 , V_2 , ! V_2 -> V_18 ) ;
F_8 ( V_13 , V_2 , F_9 ( & V_2 -> V_17 ) ) ;
F_7 ( V_13 , V_2 ) ;
}
}
struct V_1 * F_34 ( struct V_2 * V_32 , struct V_14 * V_15 )
{
struct V_1 * V_2 ;
F_32 ( F_33 ( V_32 ) ) ;
V_2 = (struct V_1 * ) V_32 -> V_54 ;
if ( V_2 ) {
F_1 ( V_2 ) ;
F_2 ( V_2 -> V_41 == V_48 ) ;
}
return V_2 ;
}
const struct V_4 * F_44 ( const struct V_1 * V_2 ,
const struct V_5 * V_6 )
{
return F_5 ( V_2 , V_6 ) ;
}
static int F_45 ( const struct V_12 * V_13 ,
struct V_63 * V_64 , struct V_1 * V_2 , T_2 V_65 )
{
F_46 ( V_13 , V_2 , F_47 ( V_2 -> V_16 , V_64 -> V_66 ) ) ;
return F_48 ( V_13 , V_2 , V_65 ,
( const struct V_12 * ,
const struct V_4 * , struct V_63 * ) ,
V_64 ) ;
}
static void F_49 ( const struct V_12 * V_13 ,
struct V_63 * V_64 , struct V_1 * V_2 , T_2 V_65 )
{
F_46 ( V_13 , V_2 , F_47 ( V_2 -> V_16 , V_64 -> V_66 ) ) ;
F_50 ( V_13 , V_2 , V_65 ,
( const struct V_12 * ,
const struct V_4 * , struct V_63 * ) , V_64 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
if ( V_2 -> V_18 ) {
F_2 ( V_2 -> V_18 -> V_67 > 0 ) ;
V_2 -> V_18 -> V_67 -- ;
V_2 -> V_18 = NULL ;
}
}
static void F_52 ( struct V_1 * V_2 )
{
V_2 -> V_18 -> V_67 ++ ;
}
void F_53 ( const struct V_12 * V_13 ,
struct V_63 * V_64 , struct V_1 * V_55 )
{
enum V_28 V_29 ;
V_29 = V_55 -> V_19 ;
F_46 ( V_13 , V_55 , V_29 == V_59 || V_29 == V_20 ) ;
F_46 ( V_13 , V_55 , F_35 ( V_55 ) || V_29 == V_20 ) ;
F_51 ( V_55 ) ;
if ( V_29 == V_59 )
F_40 ( V_13 , V_55 , V_40 ) ;
F_54 ( V_13 , V_55 , F_55 ( V_68 ) ,
( const struct V_12 * ,
const struct V_4 * , struct V_63 * ) ,
V_64 ) ;
}
int F_56 ( const struct V_1 * V_55 , const struct V_63 * V_64 )
{
struct V_63 * V_69 = F_57 ( (struct V_63 * ) V_64 ) ;
F_58 ( F_47 ( V_55 -> V_16 , V_64 -> V_66 ) ) ;
return V_55 -> V_19 == V_59 && V_55 -> V_18 == V_69 ;
}
static int F_59 ( const struct V_12 * V_13 , struct V_63 * V_64 ,
struct V_1 * V_55 , int V_70 )
{
int V_38 ;
F_46 ( V_13 , V_55 , ! F_56 ( V_55 , V_64 ) ) ;
V_64 = F_57 ( V_64 ) ;
if ( V_55 -> V_19 == V_20 ) {
V_38 = - V_71 ;
} else {
V_38 = F_48 ( V_13 , V_55 , F_55 ( V_72 ) ,
( const struct V_12 * ,
const struct V_4 * ,
struct V_63 * , int ) ,
V_64 , V_70 ) ;
if ( V_38 == 0 ) {
F_8 ( V_13 , V_55 , ! V_55 -> V_18 ) ;
V_55 -> V_18 = F_57 ( V_64 ) ;
F_52 ( V_55 ) ;
if ( V_55 -> V_19 != V_20 ) {
F_40 ( V_13 , V_55 , V_59 ) ;
} else {
F_53 ( V_13 , V_64 , V_55 ) ;
V_38 = - V_71 ;
}
}
}
F_46 ( V_13 , V_55 , F_60 ( V_38 == 0 , F_35 ( V_55 ) ) ) ;
return V_38 ;
}
int F_61 ( const struct V_12 * V_13 , struct V_63 * V_64 , struct V_1 * V_55 )
{
return F_59 ( V_13 , V_64 , V_55 , 0 ) ;
}
int F_62 ( const struct V_12 * V_13 , struct V_63 * V_64 ,
struct V_1 * V_55 )
{
return F_59 ( V_13 , V_64 , V_55 , 1 ) ;
}
void F_63 ( const struct V_12 * V_13 ,
struct V_63 * V_64 , struct V_1 * V_55 )
{
F_46 ( V_13 , V_55 , F_47 ( V_55 -> V_16 , V_64 -> V_66 ) ) ;
V_64 = F_57 ( V_64 ) ;
F_49 ( V_13 , V_64 , V_55 , F_55 ( V_73 ) ) ;
F_8 ( V_13 , V_55 , ! V_55 -> V_18 ) ;
V_55 -> V_18 = F_57 ( V_64 ) ;
F_52 ( V_55 ) ;
F_40 ( V_13 , V_55 , V_59 ) ;
}
void F_64 ( const struct V_12 * V_13 ,
struct V_63 * V_64 , struct V_1 * V_55 )
{
F_46 ( V_13 , V_55 , F_56 ( V_55 , V_64 ) ) ;
F_46 ( V_13 , V_55 , F_35 ( V_55 ) ) ;
V_64 = F_57 ( V_64 ) ;
F_51 ( V_55 ) ;
F_40 ( V_13 , V_55 , V_40 ) ;
F_54 ( V_13 , V_55 , F_55 ( V_74 ) ,
( const struct V_12 * ,
const struct V_4 * , struct V_63 * ) ,
V_64 ) ;
}
void F_65 ( const struct V_12 * V_13 ,
struct V_63 * V_64 , struct V_1 * V_55 )
{
F_46 ( V_13 , V_55 , F_56 ( V_55 , V_64 ) ||
V_55 -> V_19 == V_20 ) ;
V_64 = F_57 ( V_64 ) ;
F_53 ( V_13 , V_64 , V_55 ) ;
}
void F_66 ( const struct V_12 * V_13 ,
struct V_63 * V_64 , struct V_1 * V_55 )
{
F_46 ( V_13 , V_55 , F_56 ( V_55 , V_64 ) ) ;
F_46 ( V_13 , V_55 , F_35 ( V_55 ) ) ;
F_49 ( V_13 , V_64 , V_55 , F_55 ( V_75 ) ) ;
}
static void F_26 ( const struct V_12 * V_13 , struct V_1 * V_55 )
{
F_8 ( V_13 , V_55 , V_55 -> V_19 != V_20 ) ;
F_51 ( V_55 ) ;
F_37 ( V_13 , V_55 , V_20 ) ;
F_54 ( V_13 , V_55 , F_55 ( V_76 ) ,
( const struct V_12 * ,
const struct V_4 * ) ) ;
}
void F_67 ( const struct V_12 * V_13 , struct V_1 * V_55 )
{
F_46 ( V_13 , V_55 , F_35 ( V_55 ) ) ;
F_26 ( V_13 , V_55 ) ;
}
void F_68 ( const struct V_12 * V_13 , struct V_1 * V_55 , int V_77 )
{
F_46 ( V_13 , V_55 , F_35 ( V_55 ) ) ;
F_50 ( V_13 , V_55 , F_55 ( V_78 ) ,
( const struct V_12 * ,
const struct V_4 * , int ) , V_77 ) ;
}
int F_69 ( const struct V_12 * V_13 , const struct V_1 * V_55 )
{
int V_38 ;
const struct V_4 * V_7 ;
V_7 = F_70 ( V_55 -> V_21 . V_22 ,
const struct V_4 , V_23 ) ;
F_8 ( V_13 , V_55 , V_7 -> V_24 -> V_79 ) ;
V_38 = V_7 -> V_24 -> V_79 ( V_13 , V_7 ) ;
F_8 ( V_13 , V_55 , V_38 == - V_80 || V_38 == - V_81 ) ;
return V_38 == - V_80 ;
}
static enum V_28 F_71 ( enum V_82 V_83 )
{
return V_83 == V_84 ? V_61 : V_60 ;
}
static void F_72 ( const struct V_12 * V_13 ,
struct V_1 * V_55 , enum V_82 V_83 )
{
F_51 ( V_55 ) ;
F_40 ( V_13 , V_55 , F_71 ( V_83 ) ) ;
}
int F_73 ( const struct V_12 * V_13 , struct V_63 * V_64 ,
struct V_1 * V_55 , enum V_82 V_83 )
{
int V_38 ;
F_46 ( V_13 , V_55 , F_56 ( V_55 , V_64 ) ) ;
F_46 ( V_13 , V_55 , F_35 ( V_55 ) ) ;
F_46 ( V_13 , V_55 , V_83 < V_85 ) ;
if ( V_83 >= V_85 )
return - V_86 ;
V_38 = F_45 ( V_13 , V_64 , V_55 , F_55 ( V_64 [ V_83 ] . V_87 ) ) ;
if ( V_38 == 0 )
F_72 ( V_13 , V_55 , V_83 ) ;
F_38 ( V_62 , V_13 , V_55 , L_6 , V_83 , V_38 ) ;
return V_38 ;
}
void F_74 ( const struct V_12 * V_13 ,
struct V_1 * V_55 , enum V_82 V_83 , int V_88 )
{
struct V_89 * V_90 = V_55 -> V_91 ;
F_8 ( V_13 , V_55 , V_83 < V_85 ) ;
F_8 ( V_13 , V_55 , V_55 -> V_19 == F_71 ( V_83 ) ) ;
F_38 ( V_62 , V_13 , V_55 , L_6 , V_83 , V_88 ) ;
F_40 ( V_13 , V_55 , V_40 ) ;
if ( V_83 >= V_85 )
return;
F_54 ( V_13 , V_55 , F_55 ( V_64 [ V_83 ] . V_92 ) ,
( const struct V_12 * ,
const struct V_4 * , int ) , V_88 ) ;
if ( V_90 ) {
F_2 ( V_55 -> V_91 == V_90 ) ;
V_55 -> V_91 = NULL ;
F_75 ( V_13 , V_90 , V_88 ) ;
}
}
int F_76 ( const struct V_12 * V_13 , struct V_1 * V_55 ,
enum V_82 V_83 )
{
int V_38 ;
F_46 ( V_13 , V_55 , V_83 < V_85 ) ;
if ( V_83 >= V_85 )
return - V_86 ;
V_38 = F_48 ( V_13 , V_55 , F_55 ( V_64 [ V_83 ] . V_93 ) ,
( const struct V_12 * ,
const struct V_4 * ) ) ;
if ( V_38 == 0 ) {
F_8 ( V_13 , V_55 , V_55 -> V_19 == V_40 ) ;
F_72 ( V_13 , V_55 , V_83 ) ;
}
F_38 ( V_62 , V_13 , V_55 , L_6 , V_83 , V_38 ) ;
return V_38 ;
}
int F_77 ( const struct V_12 * V_13 , struct V_63 * V_64 ,
struct V_1 * V_55 )
{
int V_38 ;
F_46 ( V_13 , V_55 , F_56 ( V_55 , V_64 ) ) ;
F_46 ( V_13 , V_55 , F_35 ( V_55 ) ) ;
V_38 = F_45 ( V_13 , V_64 , V_55 , F_55 ( V_94 ) ) ;
F_38 ( V_62 , V_13 , V_55 , L_5 , V_38 ) ;
return V_38 ;
}
void F_78 ( const struct V_12 * V_13 , struct V_1 * V_55 ,
int V_95 , int V_96 )
{
F_46 ( V_13 , V_55 , F_35 ( V_55 ) ) ;
F_38 ( V_62 , V_13 , V_55 , L_6 , V_95 , V_96 ) ;
F_50 ( V_13 , V_55 , F_55 ( V_97 ) ,
( const struct V_12 * ,
const struct V_4 * , int , int ) ,
V_95 , V_96 ) ;
}
void F_79 ( const struct V_12 * V_13 , void * V_98 ,
T_3 V_99 , const struct V_1 * V_55 )
{
(* V_99)( V_13 , V_98 ,
L_7 ,
V_55 , F_3 ( & V_55 -> V_3 ) , V_55 -> V_16 ,
V_55 -> V_19 , V_55 -> V_41 ,
V_55 -> V_18 ) ;
}
void F_80 ( const struct V_12 * V_13 , void * V_98 ,
T_3 V_99 , const struct V_1 * V_55 )
{
F_79 ( V_13 , V_98 , V_99 , V_55 ) ;
F_48 ( V_13 , (struct V_1 * ) V_55 , F_55 ( V_100 ) ,
( const struct V_12 * V_13 ,
const struct V_4 * V_7 ,
void * V_98 , T_3 V_101 ) , V_98 , V_99 ) ;
(* V_99)( V_13 , V_98 , L_8 , V_55 ) ;
}
int F_81 ( const struct V_12 * V_13 , struct V_1 * V_2 )
{
return F_48 ( V_13 , V_2 , F_55 ( V_102 ) ,
( const struct V_12 * ,
const struct V_4 * ) ) ;
}
T_4 F_82 ( const struct V_14 * V_15 , T_1 V_46 )
{
return ( T_4 ) V_46 << V_103 ;
}
T_1 F_83 ( const struct V_14 * V_15 , T_4 V_104 )
{
return V_104 >> V_103 ;
}
T_5 F_84 ( const struct V_14 * V_15 )
{
return 1UL << V_103 ;
}
void F_85 ( struct V_1 * V_2 , struct V_4 * V_7 ,
struct V_14 * V_15 , T_1 V_105 ,
const struct V_106 * V_107 )
{
F_86 ( & V_7 -> V_23 , & V_2 -> V_21 ) ;
V_7 -> V_8 = V_15 ;
V_7 -> V_108 = V_105 ;
V_7 -> V_24 = V_107 ;
V_7 -> V_109 = V_2 ;
}
struct V_110 * F_87 ( unsigned long V_111 )
{
struct V_110 * V_112 = NULL ;
V_112 = F_19 ( sizeof( * V_112 ) , V_113 ) ;
if ( ! V_112 )
return NULL ;
F_21 ( & V_112 -> V_114 , 1 ) ;
V_112 -> V_115 = V_111 ;
F_88 ( & V_112 -> V_116 , V_111 ) ;
F_89 ( & V_112 -> V_117 ) ;
F_24 ( & V_112 -> V_118 ) ;
F_88 ( & V_112 -> V_119 , 0 ) ;
F_90 ( & V_112 -> V_120 ) ;
return V_112 ;
}
void F_91 ( struct V_110 * V_112 )
{
F_4 ( & V_112 -> V_114 ) ;
}
void F_92 ( struct V_110 * V_112 )
{
if ( F_43 ( & V_112 -> V_114 ) )
F_16 ( V_112 ) ;
}
