static void F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_6 = ( 1 << 31 ) ;
V_5 -> V_7 = 0 ;
V_5 -> V_8 = ( 1 << 31 ) ;
}
static T_1 F_2 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
return V_5 -> V_9 ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
int V_10 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
return V_5 -> V_11 [ V_10 ] ;
}
static void F_4 ( struct V_1 * V_2 ,
T_1 V_12 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_12 = V_12 ;
}
static void F_5 ( struct V_1 * V_2 ,
T_1 V_13 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_6 ( V_5 -> V_7 ) ;
V_5 -> V_7 = V_13 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_7 = 0 ;
}
static void F_8 ( struct V_1 * V_2 ,
T_2 V_14 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_9 = V_14 ;
}
static int F_9 ( T_3 V_15 )
{
return 1 ;
}
static void F_10 ( struct V_1 * V_2 ,
int V_16 , T_2 V_14 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_11 [ V_16 ] = V_14 ;
if ( V_2 -> type == V_17 )
V_5 -> V_8 |= ( 1 << V_16 ) ;
}
static T_1 F_11 ( struct V_18 * V_19 )
{
return F_12 ( F_13 ( V_19 ) ) ;
}
static void F_14 ( struct V_18 * V_19 ,
T_1 V_13 )
{
F_15 ( V_13 , F_16 ( V_19 ) ) ;
}
static void F_17 ( struct V_18 * V_19 )
{
T_1 V_20 = F_12 ( F_18 ( V_19 ) ) ;
V_20 |= V_21 << ( V_19 -> V_22 * 16 ) ;
F_15 ( V_20 , F_18 ( V_19 ) ) ;
}
static T_1 F_19 ( struct V_18 * V_19 )
{
T_1 V_23 = F_12 ( F_20 ( V_19 ) ) ;
V_23 = ( V_23 >> ( V_19 -> V_22 * 16 ) ) & 0xFFFF ;
return V_23 ;
}
static int F_21 ( T_1 V_23 )
{
if ( V_23 & ( ( 1 << 4 ) | ( 1 << 5 ) | ( 1 << 6 ) | ( 1 << 7 ) | ( 1 << 8 ) | ( 1 << 9 ) ) )
return 1 ;
return 0 ;
}
static void F_22 ( struct V_18 * V_19 )
{
T_1 V_20 = ~ ( 1 << ( V_19 -> V_22 * 16 ) ) ;
F_23 ( F_24 ( V_19 ) , L_1 , V_24 , V_20 ) ;
F_15 ( V_20 , F_20 ( V_19 ) ) ;
}
static void F_25 ( struct V_18 * V_19 )
{
T_1 V_20 = 0xFFFF0000 >> ( V_19 -> V_22 * 16 ) ;
F_15 ( V_20 , F_20 ( V_19 ) ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_1 * V_25 = F_27 (
V_2 -> V_26 . V_27 , struct V_1 , V_26 ) ;
if ( V_25 -> type != V_2 -> type )
return 0 ;
return 1 ;
}
static void F_28 ( struct V_18 * V_19 ,
enum V_28 type )
{
T_1 V_29 ;
T_1 V_30 = F_12 ( F_29 ( V_19 ) ) ;
switch ( type ) {
case V_17 :
V_29 = V_31 ;
break;
case V_32 :
V_29 = V_33 ;
break;
default:
F_30 ( F_24 ( V_19 ) ,
L_2 ,
type ) ;
F_31 () ;
return;
}
V_30 &= ~ 0x7 ;
V_30 |= V_29 ;
F_15 ( V_30 , F_29 ( V_19 ) ) ;
V_19 -> V_34 = type ;
}
static void F_32 ( struct V_18 * V_19 )
{
T_1 V_35 ;
F_23 ( F_24 ( V_19 ) , L_3 ) ;
V_35 = F_12 ( F_33 ( V_19 ) ) ;
V_35 |= 0x1 ;
F_15 ( V_35 , F_33 ( V_19 ) ) ;
}
static char F_34 ( struct V_18 * V_19 )
{
T_1 V_36 = F_12 ( F_33 ( V_19 ) ) ;
V_36 = ( V_36 >> 4 ) & 0x3 ;
return ( V_36 == 1 ) ? 1 : 0 ;
}
static int F_35 ( T_3 V_15 , int V_37 )
{
return 1 ;
}
static void F_36 ( struct V_18 * V_38 ,
struct V_1 * V_39 )
{
F_23 ( F_24 ( V_38 ) , L_4 ,
V_24 , __LINE__ , V_39 ) ;
V_39 -> V_40 = 0 ;
}
static void F_37 ( struct V_18 * V_38 ,
struct V_1 * V_41 )
{
F_23 ( F_24 ( V_38 ) , L_5 ,
V_24 , __LINE__ , V_41 ) ;
if ( V_41 -> type != V_38 -> V_34 )
F_28 ( V_38 , V_41 -> type ) ;
F_14 ( V_38 , V_41 -> V_42 . V_43 ) ;
V_38 -> V_44 += V_41 -> V_45 ;
F_38 ( & V_38 -> V_46 ) ;
}
static T_4
F_39 ( struct V_1 * V_2 ,
struct V_18 * V_38 , T_4 V_47 )
{
F_6 ( V_2 -> V_42 . V_47 < 0 ) ;
if ( V_2 -> V_42 . V_47 > 0 ) {
V_47 = V_2 -> V_42 . V_47 ;
if ( V_2 -> V_42 . V_48 )
V_2 -> V_42 . V_48 (
V_2 -> V_42 . V_49 ) ;
if ( V_2 -> V_50 && V_2 -> V_51 ) {
struct V_1 * V_52 = V_2 -> V_50 ;
struct V_53 * V_54 = F_24 ( V_38 ) ;
T_1 V_15 = V_52 -> V_51 ;
enum V_55 V_3 = V_2 -> V_42 . V_3 ;
T_1 V_37 ;
T_2 V_14 ;
T_2 V_56 ;
V_37 = V_52 -> V_57 ;
V_56 = F_2 ( V_52 ) ;
if ( ! ( V_3 & V_58 ) ) {
enum V_59 V_60 ;
if ( V_37 > 1 )
V_60 = V_61 ;
else
V_60 = V_62 ;
F_40 ( V_54 , V_56 , V_15 , V_60 ) ;
}
if ( ! ( V_3 & V_63 ) ) {
while ( V_37 -- ) {
V_14 = F_3 ( V_52 ,
V_37 ) ;
if ( V_14 == V_56 )
continue;
F_40 ( V_54 , V_14 , V_15 ,
V_64 ) ;
}
}
V_2 -> V_50 = NULL ;
}
}
F_41 ( & V_2 -> V_42 ) ;
return V_47 ;
}
static int
F_42 ( struct V_18 * V_38 )
{
struct V_1 * V_65 , * V_66 ;
F_23 ( F_24 ( V_38 ) , L_6 , V_24 , __LINE__ ) ;
F_43 (iter, _iter, &mv_chan->completed_slots,
completed_node) {
if ( F_44 ( & V_65 -> V_42 ) ) {
F_45 ( & V_65 -> V_67 ) ;
F_36 ( V_38 , V_65 ) ;
}
}
return 0 ;
}
static int
F_46 ( struct V_1 * V_2 ,
struct V_18 * V_38 )
{
F_23 ( F_24 ( V_38 ) , L_7 ,
V_24 , __LINE__ , V_2 , V_2 -> V_42 . V_3 ) ;
F_45 ( & V_2 -> V_26 ) ;
if ( ! F_44 ( & V_2 -> V_42 ) ) {
F_47 ( & V_2 -> V_67 , & V_38 -> V_68 ) ;
return 0 ;
}
F_36 ( V_38 , V_2 ) ;
return 0 ;
}
static void F_48 ( struct V_18 * V_38 )
{
struct V_1 * V_65 , * V_66 ;
T_4 V_47 = 0 ;
int V_69 = F_34 ( V_38 ) ;
T_1 V_70 = F_11 ( V_38 ) ;
int V_71 = 0 ;
F_23 ( F_24 ( V_38 ) , L_6 , V_24 , __LINE__ ) ;
F_23 ( F_24 ( V_38 ) , L_8 , V_70 ) ;
F_42 ( V_38 ) ;
F_43 (iter, _iter, &mv_chan->chain,
chain_node) {
F_49 ( V_66 ) ;
F_49 ( & V_66 -> V_42 ) ;
if ( V_71 )
break;
if ( V_65 -> V_42 . V_43 == V_70 ) {
V_71 = 1 ;
if ( V_69 )
break;
}
V_47 = F_39 ( V_65 , V_38 , V_47 ) ;
if ( F_46 ( V_65 , V_38 ) )
break;
}
if ( ( V_69 == 0 ) && ! F_50 ( & V_38 -> V_72 ) ) {
struct V_1 * V_73 ;
V_73 = F_27 ( V_38 -> V_72 . V_74 ,
struct V_1 ,
V_26 ) ;
F_37 ( V_38 , V_73 ) ;
}
if ( V_47 > 0 )
V_38 -> V_46 . V_75 = V_47 ;
}
static void
F_51 ( struct V_18 * V_38 )
{
F_52 ( & V_38 -> V_76 ) ;
F_48 ( V_38 ) ;
F_53 ( & V_38 -> V_76 ) ;
}
static void F_54 ( unsigned long V_77 )
{
struct V_18 * V_19 = (struct V_18 * ) V_77 ;
F_51 ( V_19 ) ;
}
static struct V_1 *
F_55 ( struct V_18 * V_38 , int V_78 ,
int V_40 )
{
struct V_1 * V_65 , * V_66 , * V_79 = NULL ;
F_56 ( V_72 ) ;
int V_80 , V_81 = 0 ;
V_81:
V_80 = 0 ;
if ( V_81 == 0 )
V_65 = V_38 -> V_82 ;
else
V_65 = F_27 ( & V_38 -> V_83 ,
struct V_1 ,
V_84 ) ;
F_57 (
iter, _iter, &mv_chan->all_slots, slot_node) {
F_49 ( V_66 ) ;
F_49 ( & V_66 -> V_42 ) ;
if ( V_65 -> V_40 ) {
if ( V_81 )
break;
V_80 = 0 ;
continue;
}
if ( ! V_80 ++ )
V_79 = V_65 ;
if ( V_80 == V_78 ) {
struct V_1 * V_85 = NULL ;
struct V_1 * V_82 = NULL ;
V_65 = V_79 ;
while ( V_78 ) {
int V_86 ;
F_58 ( & V_65 -> V_42 ) ;
F_47 ( & V_65 -> V_26 , & V_72 ) ;
V_85 = V_65 ;
V_65 -> V_42 . V_47 = 0 ;
V_65 -> V_45 = V_78 ;
V_65 -> V_87 = NULL ;
for ( V_86 = 0 ; V_86 < V_40 ; V_86 ++ ) {
V_65 -> V_40 = V_40 - V_86 ;
V_82 = V_65 ;
V_65 = F_27 ( V_65 -> V_84 . V_74 ,
struct V_1 ,
V_84 ) ;
}
V_78 -= V_40 ;
}
V_85 -> V_50 = V_79 ;
V_85 -> V_42 . V_47 = - V_88 ;
F_59 ( & V_72 , & V_85 -> V_89 ) ;
V_38 -> V_82 = V_82 ;
F_7 ( V_79 ) ;
F_7 ( V_85 ) ;
return V_85 ;
}
}
if ( ! V_81 ++ )
goto V_81;
F_60 ( & V_38 -> V_90 ) ;
return NULL ;
}
static T_4
F_61 ( struct V_91 * V_92 )
{
struct V_1 * V_41 = F_62 ( V_92 ) ;
struct V_18 * V_38 = F_63 ( V_92 -> V_19 ) ;
struct V_1 * V_93 , * V_94 ;
T_4 V_47 ;
int V_95 = 1 ;
F_23 ( F_24 ( V_38 ) ,
L_9 ,
V_24 , V_41 , & V_41 -> V_42 ) ;
V_93 = V_41 -> V_50 ;
F_52 ( & V_38 -> V_76 ) ;
V_47 = F_64 ( V_92 ) ;
if ( F_50 ( & V_38 -> V_72 ) )
F_65 ( & V_41 -> V_89 , & V_38 -> V_72 ) ;
else {
V_95 = 0 ;
V_94 = F_27 ( V_38 -> V_72 . V_27 ,
struct V_1 ,
V_26 ) ;
F_65 ( & V_93 -> V_89 ,
& V_94 -> V_26 ) ;
if ( ! F_26 ( V_93 ) )
goto V_96;
F_23 ( F_24 ( V_38 ) , L_10 ,
V_94 -> V_42 . V_43 ) ;
F_5 ( V_94 , V_93 -> V_42 . V_43 ) ;
if ( ! F_34 ( V_38 ) ) {
T_1 V_70 = F_11 ( V_38 ) ;
if ( V_70 == V_94 -> V_42 . V_43 )
V_95 = 1 ;
}
}
if ( V_95 )
F_37 ( V_38 , V_93 ) ;
V_96:
F_53 ( & V_38 -> V_76 ) ;
return V_47 ;
}
static int F_66 ( struct V_97 * V_19 )
{
char * V_5 ;
int V_22 ;
struct V_18 * V_38 = F_63 ( V_19 ) ;
struct V_1 * V_39 = NULL ;
int V_98 = V_99 / V_100 ;
V_22 = V_38 -> V_101 ;
while ( V_22 < V_98 ) {
V_39 = F_67 ( sizeof( * V_39 ) , V_102 ) ;
if ( ! V_39 ) {
F_68 ( V_103 L_11
L_12 , V_22 ) ;
break;
}
V_5 = ( char * ) V_38 -> V_104 ;
V_39 -> V_5 = ( void * ) & V_5 [ V_22 * V_100 ] ;
F_69 ( & V_39 -> V_42 , V_19 ) ;
V_39 -> V_42 . V_105 = F_61 ;
F_70 ( & V_39 -> V_26 ) ;
F_70 ( & V_39 -> V_84 ) ;
F_70 ( & V_39 -> V_89 ) ;
V_5 = ( char * ) V_38 -> V_106 ;
V_39 -> V_42 . V_43 =
( T_2 ) & V_5 [ V_22 * V_100 ] ;
V_39 -> V_22 = V_22 ++ ;
F_52 ( & V_38 -> V_76 ) ;
V_38 -> V_101 = V_22 ;
F_47 ( & V_39 -> V_84 , & V_38 -> V_83 ) ;
F_53 ( & V_38 -> V_76 ) ;
}
if ( V_38 -> V_101 && ! V_38 -> V_82 )
V_38 -> V_82 = F_27 ( V_38 -> V_83 . V_74 ,
struct V_1 ,
V_84 ) ;
F_23 ( F_24 ( V_38 ) ,
L_13 ,
V_38 -> V_101 , V_38 -> V_82 ) ;
return V_38 -> V_101 ? : - V_107 ;
}
static struct V_91 *
F_71 ( struct V_97 * V_19 , T_2 V_56 , T_2 V_108 ,
T_3 V_15 , unsigned long V_3 )
{
struct V_18 * V_38 = F_63 ( V_19 ) ;
struct V_1 * V_41 , * V_93 ;
int V_45 ;
F_23 ( F_24 ( V_38 ) ,
L_14 ,
V_24 , V_56 , V_108 , V_15 , V_3 ) ;
if ( F_72 ( V_15 < V_109 ) )
return NULL ;
F_6 ( V_15 > V_110 ) ;
F_52 ( & V_38 -> V_76 ) ;
V_45 = F_73 ( V_15 ) ;
V_41 = F_55 ( V_38 , V_45 , 1 ) ;
if ( V_41 ) {
V_41 -> type = V_32 ;
V_41 -> V_42 . V_3 = V_3 ;
V_93 = V_41 -> V_50 ;
F_1 ( V_93 , V_3 ) ;
F_4 ( V_93 , V_15 ) ;
F_8 ( V_41 -> V_50 , V_56 ) ;
F_10 ( V_93 , 0 , V_108 ) ;
V_41 -> V_57 = 1 ;
V_41 -> V_51 = V_15 ;
}
F_53 ( & V_38 -> V_76 ) ;
F_23 ( F_24 ( V_38 ) ,
L_15 ,
V_24 , V_41 , V_41 ? & V_41 -> V_42 : 0 ) ;
return V_41 ? & V_41 -> V_42 : NULL ;
}
static struct V_91 *
F_74 ( struct V_97 * V_19 , T_2 V_56 , T_2 * V_108 ,
unsigned int V_37 , T_3 V_15 , unsigned long V_3 )
{
struct V_18 * V_38 = F_63 ( V_19 ) ;
struct V_1 * V_41 , * V_93 ;
int V_45 ;
if ( F_72 ( V_15 < V_109 ) )
return NULL ;
F_6 ( V_15 > V_110 ) ;
F_23 ( F_24 ( V_38 ) ,
L_16 ,
V_24 , V_37 , V_15 , V_56 , V_3 ) ;
F_52 ( & V_38 -> V_76 ) ;
V_45 = F_35 ( V_15 , V_37 ) ;
V_41 = F_55 ( V_38 , V_45 , 1 ) ;
if ( V_41 ) {
V_41 -> type = V_17 ;
V_41 -> V_42 . V_3 = V_3 ;
V_93 = V_41 -> V_50 ;
F_1 ( V_93 , V_3 ) ;
F_4 ( V_93 , V_15 ) ;
F_8 ( V_41 -> V_50 , V_56 ) ;
V_41 -> V_57 = V_37 ;
V_41 -> V_51 = V_15 ;
while ( V_37 -- )
F_10 ( V_93 , V_37 , V_108 [ V_37 ] ) ;
}
F_53 ( & V_38 -> V_76 ) ;
F_23 ( F_24 ( V_38 ) ,
L_17 ,
V_24 , V_41 , & V_41 -> V_42 ) ;
return V_41 ? & V_41 -> V_42 : NULL ;
}
static void F_75 ( struct V_97 * V_19 )
{
struct V_18 * V_38 = F_63 ( V_19 ) ;
struct V_1 * V_65 , * V_66 ;
int V_111 = 0 ;
F_51 ( V_38 ) ;
F_52 ( & V_38 -> V_76 ) ;
F_43 (iter, _iter, &mv_chan->chain,
chain_node) {
V_111 ++ ;
F_45 ( & V_65 -> V_26 ) ;
}
F_43 (iter, _iter, &mv_chan->completed_slots,
completed_node) {
V_111 ++ ;
F_45 ( & V_65 -> V_67 ) ;
}
F_76 (
iter, _iter, &mv_chan->all_slots, slot_node) {
F_45 ( & V_65 -> V_84 ) ;
F_77 ( V_65 ) ;
V_38 -> V_101 -- ;
}
V_38 -> V_82 = NULL ;
F_23 ( F_24 ( V_38 ) , L_18 ,
V_24 , V_38 -> V_101 ) ;
F_53 ( & V_38 -> V_76 ) ;
if ( V_111 )
F_30 ( F_24 ( V_38 ) ,
L_19 , V_111 ) ;
}
static enum V_112 F_78 ( struct V_97 * V_19 ,
T_4 V_47 ,
struct V_113 * V_114 )
{
struct V_18 * V_38 = F_63 ( V_19 ) ;
enum V_112 V_115 ;
V_115 = F_79 ( V_19 , V_47 , V_114 ) ;
if ( V_115 == V_116 ) {
F_42 ( V_38 ) ;
return V_115 ;
}
F_51 ( V_38 ) ;
return F_79 ( V_19 , V_47 , V_114 ) ;
}
static void F_80 ( struct V_18 * V_19 )
{
T_1 V_20 ;
V_20 = F_12 ( F_29 ( V_19 ) ) ;
F_30 ( F_24 ( V_19 ) , L_20 , V_20 ) ;
V_20 = F_12 ( F_33 ( V_19 ) ) ;
F_30 ( F_24 ( V_19 ) , L_21 , V_20 ) ;
V_20 = F_12 ( F_20 ( V_19 ) ) ;
F_30 ( F_24 ( V_19 ) , L_22 , V_20 ) ;
V_20 = F_12 ( F_18 ( V_19 ) ) ;
F_30 ( F_24 ( V_19 ) , L_23 , V_20 ) ;
V_20 = F_12 ( F_81 ( V_19 ) ) ;
F_30 ( F_24 ( V_19 ) , L_24 , V_20 ) ;
V_20 = F_12 ( F_82 ( V_19 ) ) ;
F_30 ( F_24 ( V_19 ) , L_25 , V_20 ) ;
}
static void F_83 ( struct V_18 * V_19 ,
T_1 V_23 )
{
if ( V_23 & ( 1 << 4 ) ) {
F_23 ( F_24 ( V_19 ) ,
L_26 ) ;
return;
}
F_30 ( F_24 ( V_19 ) ,
L_27 ,
V_19 -> V_22 , V_23 ) ;
F_80 ( V_19 ) ;
F_31 () ;
}
static T_5 F_84 ( int V_117 , void * V_77 )
{
struct V_18 * V_19 = V_77 ;
T_1 V_23 = F_19 ( V_19 ) ;
F_23 ( F_24 ( V_19 ) , L_28 , V_23 ) ;
if ( F_21 ( V_23 ) )
F_83 ( V_19 , V_23 ) ;
F_60 ( & V_19 -> V_90 ) ;
F_22 ( V_19 ) ;
return V_118 ;
}
static void F_38 ( struct V_97 * V_19 )
{
struct V_18 * V_38 = F_63 ( V_19 ) ;
if ( V_38 -> V_44 >= V_119 ) {
V_38 -> V_44 = 0 ;
F_32 ( V_38 ) ;
}
}
static int F_85 ( struct V_18 * V_38 )
{
int V_86 ;
void * V_108 , * V_56 ;
T_2 V_120 , V_121 ;
struct V_97 * V_97 ;
T_4 V_47 ;
struct V_91 * V_92 ;
int V_122 = 0 ;
V_108 = F_86 ( sizeof( V_123 ) * V_124 , V_102 ) ;
if ( ! V_108 )
return - V_107 ;
V_56 = F_67 ( sizeof( V_123 ) * V_124 , V_102 ) ;
if ( ! V_56 ) {
F_77 ( V_108 ) ;
return - V_107 ;
}
for ( V_86 = 0 ; V_86 < V_124 ; V_86 ++ )
( ( V_123 * ) V_108 ) [ V_86 ] = ( V_123 ) V_86 ;
V_97 = & V_38 -> V_46 ;
if ( F_66 ( V_97 ) < 1 ) {
V_122 = - V_125 ;
goto V_126;
}
V_121 = F_87 ( V_97 -> V_53 -> V_54 , V_56 ,
V_124 , V_62 ) ;
V_120 = F_87 ( V_97 -> V_53 -> V_54 , V_108 ,
V_124 , V_64 ) ;
V_92 = F_71 ( V_97 , V_121 , V_120 ,
V_124 , 0 ) ;
V_47 = F_61 ( V_92 ) ;
F_38 ( V_97 ) ;
F_58 ( V_92 ) ;
F_88 ( 1 ) ;
if ( F_78 ( V_97 , V_47 , NULL ) !=
V_116 ) {
F_30 ( V_97 -> V_53 -> V_54 ,
L_29 ) ;
V_122 = - V_125 ;
goto V_127;
}
F_89 ( V_97 -> V_53 -> V_54 , V_121 ,
V_124 , V_62 ) ;
if ( memcmp ( V_108 , V_56 , V_124 ) ) {
F_30 ( V_97 -> V_53 -> V_54 ,
L_30 ) ;
V_122 = - V_125 ;
goto V_127;
}
V_127:
F_75 ( V_97 ) ;
V_126:
F_77 ( V_108 ) ;
F_77 ( V_56 ) ;
return V_122 ;
}
static int
F_90 ( struct V_18 * V_38 )
{
int V_86 , V_10 ;
struct V_128 * V_56 ;
struct V_128 * V_129 [ V_130 ] ;
T_2 V_131 [ V_130 ] ;
T_2 V_121 ;
struct V_91 * V_92 ;
struct V_97 * V_97 ;
T_4 V_47 ;
V_123 V_132 = 0 ;
T_1 V_133 ;
int V_122 = 0 ;
for ( V_10 = 0 ; V_10 < V_130 ; V_10 ++ ) {
V_129 [ V_10 ] = F_91 ( V_102 ) ;
if ( ! V_129 [ V_10 ] ) {
while ( V_10 -- )
F_92 ( V_129 [ V_10 ] ) ;
return - V_107 ;
}
}
V_56 = F_91 ( V_102 ) ;
if ( ! V_56 ) {
while ( V_10 -- )
F_92 ( V_129 [ V_10 ] ) ;
return - V_107 ;
}
for ( V_10 = 0 ; V_10 < V_130 ; V_10 ++ ) {
V_123 * V_134 = F_93 ( V_129 [ V_10 ] ) ;
for ( V_86 = 0 ; V_86 < V_135 ; V_86 ++ )
V_134 [ V_86 ] = ( 1 << V_10 ) ;
}
for ( V_10 = 0 ; V_10 < V_130 ; V_10 ++ )
V_132 ^= ( V_123 ) ( 1 << V_10 ) ;
V_133 = ( V_132 << 24 ) | ( V_132 << 16 ) |
( V_132 << 8 ) | V_132 ;
memset ( F_93 ( V_56 ) , 0 , V_135 ) ;
V_97 = & V_38 -> V_46 ;
if ( F_66 ( V_97 ) < 1 ) {
V_122 = - V_125 ;
goto V_126;
}
V_121 = F_94 ( V_97 -> V_53 -> V_54 , V_56 , 0 , V_135 ,
V_62 ) ;
for ( V_86 = 0 ; V_86 < V_130 ; V_86 ++ )
V_131 [ V_86 ] = F_94 ( V_97 -> V_53 -> V_54 , V_129 [ V_86 ] ,
0 , V_135 , V_64 ) ;
V_92 = F_74 ( V_97 , V_121 , V_131 ,
V_130 , V_135 , 0 ) ;
V_47 = F_61 ( V_92 ) ;
F_38 ( V_97 ) ;
F_58 ( V_92 ) ;
F_88 ( 8 ) ;
if ( F_78 ( V_97 , V_47 , NULL ) !=
V_116 ) {
F_30 ( V_97 -> V_53 -> V_54 ,
L_31 ) ;
V_122 = - V_125 ;
goto V_127;
}
F_89 ( V_97 -> V_53 -> V_54 , V_121 ,
V_135 , V_62 ) ;
for ( V_86 = 0 ; V_86 < ( V_135 / sizeof( T_1 ) ) ; V_86 ++ ) {
T_1 * V_134 = F_93 ( V_56 ) ;
if ( V_134 [ V_86 ] != V_133 ) {
F_30 ( V_97 -> V_53 -> V_54 ,
L_32 ,
V_86 , V_134 [ V_86 ] , V_133 ) ;
V_122 = - V_125 ;
goto V_127;
}
}
V_127:
F_75 ( V_97 ) ;
V_126:
V_10 = V_130 ;
while ( V_10 -- )
F_92 ( V_129 [ V_10 ] ) ;
F_92 ( V_56 ) ;
return V_122 ;
}
static int
F_95 ( struct V_97 * V_19 , enum V_136 V_137 ,
unsigned long V_138 )
{
return - V_139 ;
}
static int F_96 ( struct V_18 * V_38 )
{
struct V_97 * V_19 , * V_140 ;
struct V_53 * V_54 = V_38 -> V_141 . V_54 ;
F_97 ( & V_38 -> V_141 ) ;
F_98 ( V_54 , V_99 ,
V_38 -> V_104 , V_38 -> V_106 ) ;
F_43 (chan, _chan, &mv_chan->dmadev.channels,
device_node) {
F_45 ( & V_19 -> V_142 ) ;
}
F_99 ( V_38 -> V_117 , V_38 ) ;
return 0 ;
}
static struct V_18 *
F_100 ( struct V_143 * V_144 ,
struct V_145 * V_146 ,
int V_22 , T_6 V_147 , int V_117 )
{
int V_115 = 0 ;
struct V_18 * V_38 ;
struct V_148 * V_149 ;
V_38 = F_101 ( & V_146 -> V_54 , sizeof( * V_38 ) , V_102 ) ;
if ( ! V_38 ) {
V_115 = - V_107 ;
goto V_150;
}
V_38 -> V_22 = V_22 ;
V_38 -> V_117 = V_117 ;
V_149 = & V_38 -> V_141 ;
V_38 -> V_104 =
F_102 ( & V_146 -> V_54 , V_99 ,
& V_38 -> V_106 , V_102 ) ;
if ( ! V_38 -> V_104 )
return F_103 ( - V_107 ) ;
V_149 -> V_147 = V_147 ;
F_70 ( & V_149 -> V_151 ) ;
V_149 -> V_152 = F_66 ;
V_149 -> V_153 = F_75 ;
V_149 -> V_154 = F_78 ;
V_149 -> V_155 = F_38 ;
V_149 -> V_156 = F_95 ;
V_149 -> V_54 = & V_146 -> V_54 ;
if ( F_104 ( V_32 , V_149 -> V_147 ) )
V_149 -> V_157 = F_71 ;
if ( F_104 ( V_17 , V_149 -> V_147 ) ) {
V_149 -> V_158 = 8 ;
V_149 -> V_159 = F_74 ;
}
V_38 -> V_160 = V_144 -> V_161 ;
if ( ! V_38 -> V_160 ) {
V_115 = - V_107 ;
goto V_150;
}
F_105 ( & V_38 -> V_90 , F_54 , ( unsigned long )
V_38 ) ;
F_25 ( V_38 ) ;
V_115 = F_106 ( V_38 -> V_117 , F_84 ,
0 , F_107 ( & V_146 -> V_54 ) , V_38 ) ;
if ( V_115 )
goto V_150;
F_17 ( V_38 ) ;
F_28 ( V_38 , V_32 ) ;
F_108 ( & V_38 -> V_76 ) ;
F_70 ( & V_38 -> V_72 ) ;
F_70 ( & V_38 -> V_68 ) ;
F_70 ( & V_38 -> V_83 ) ;
V_38 -> V_46 . V_53 = V_149 ;
F_109 ( & V_38 -> V_46 ) ;
F_47 ( & V_38 -> V_46 . V_142 , & V_149 -> V_151 ) ;
if ( F_104 ( V_32 , V_149 -> V_147 ) ) {
V_115 = F_85 ( V_38 ) ;
F_23 ( & V_146 -> V_54 , L_33 , V_115 ) ;
if ( V_115 )
goto V_162;
}
if ( F_104 ( V_17 , V_149 -> V_147 ) ) {
V_115 = F_90 ( V_38 ) ;
F_23 ( & V_146 -> V_54 , L_34 , V_115 ) ;
if ( V_115 )
goto V_162;
}
F_110 ( & V_146 -> V_54 , L_35 ,
F_104 ( V_17 , V_149 -> V_147 ) ? L_36 : L_37 ,
F_104 ( V_32 , V_149 -> V_147 ) ? L_38 : L_37 ,
F_104 ( V_163 , V_149 -> V_147 ) ? L_39 : L_37 ) ;
F_111 ( V_149 ) ;
return V_38 ;
V_162:
F_99 ( V_38 -> V_117 , V_38 ) ;
V_150:
F_98 ( & V_146 -> V_54 , V_99 ,
V_38 -> V_104 , V_38 -> V_106 ) ;
return F_103 ( V_115 ) ;
}
static void
F_112 ( struct V_143 * V_144 ,
const struct V_164 * V_165 )
{
void T_7 * V_166 = V_144 -> V_161 ;
T_1 V_167 = 0 ;
int V_86 ;
for ( V_86 = 0 ; V_86 < 8 ; V_86 ++ ) {
F_113 ( 0 , V_166 + F_114 ( V_86 ) ) ;
F_113 ( 0 , V_166 + F_115 ( V_86 ) ) ;
if ( V_86 < 4 )
F_113 ( 0 , V_166 + F_116 ( V_86 ) ) ;
}
for ( V_86 = 0 ; V_86 < V_165 -> V_168 ; V_86 ++ ) {
const struct V_169 * V_170 = V_165 -> V_170 + V_86 ;
F_113 ( ( V_170 -> V_166 & 0xffff0000 ) |
( V_170 -> V_171 << 8 ) |
V_165 -> V_172 , V_166 + F_114 ( V_86 ) ) ;
F_113 ( ( V_170 -> V_173 - 1 ) & 0xffff0000 , V_166 + F_115 ( V_86 ) ) ;
V_167 |= ( 1 << V_86 ) ;
V_167 |= 3 << ( 16 + ( 2 * V_86 ) ) ;
}
F_113 ( V_167 , V_166 + F_117 ( 0 ) ) ;
F_113 ( V_167 , V_166 + F_117 ( 1 ) ) ;
F_113 ( 0 , V_166 + F_118 ( 0 ) ) ;
F_113 ( 0 , V_166 + F_118 ( 1 ) ) ;
}
static int F_119 ( struct V_145 * V_146 )
{
const struct V_164 * V_165 ;
struct V_143 * V_144 ;
struct V_174 * V_175 = V_146 -> V_54 . V_176 ;
struct V_177 * V_178 ;
int V_86 , V_115 ;
F_120 ( & V_146 -> V_54 , L_40 ) ;
V_144 = F_101 ( & V_146 -> V_54 , sizeof( * V_144 ) , V_102 ) ;
if ( ! V_144 )
return - V_107 ;
V_178 = F_121 ( V_146 , V_179 , 0 ) ;
if ( ! V_178 )
return - V_125 ;
V_144 -> V_161 = F_122 ( & V_146 -> V_54 , V_178 -> V_180 ,
F_123 ( V_178 ) ) ;
if ( ! V_144 -> V_161 )
return - V_88 ;
V_178 = F_121 ( V_146 , V_179 , 1 ) ;
if ( ! V_178 )
return - V_125 ;
V_144 -> V_181 = F_122 ( & V_146 -> V_54 , V_178 -> V_180 ,
F_123 ( V_178 ) ) ;
if ( ! V_144 -> V_181 )
return - V_88 ;
F_124 ( V_146 , V_144 ) ;
V_165 = F_125 () ;
if ( V_165 )
F_112 ( V_144 , V_165 ) ;
V_144 -> V_182 = F_126 ( & V_146 -> V_54 , NULL ) ;
if ( ! F_127 ( V_144 -> V_182 ) )
F_128 ( V_144 -> V_182 ) ;
if ( V_146 -> V_54 . V_183 ) {
struct V_142 * V_184 ;
int V_86 = 0 ;
F_129 (pdev->dev.of_node, np) {
T_6 V_147 ;
int V_117 ;
F_130 ( V_147 ) ;
if ( F_131 ( V_184 , L_41 ) )
F_132 ( V_32 , V_147 ) ;
if ( F_131 ( V_184 , L_42 ) )
F_132 ( V_17 , V_147 ) ;
if ( F_131 ( V_184 , L_43 ) )
F_132 ( V_163 , V_147 ) ;
V_117 = F_133 ( V_184 , 0 ) ;
if ( ! V_117 ) {
V_115 = - V_125 ;
goto V_185;
}
V_144 -> V_151 [ V_86 ] =
F_100 ( V_144 , V_146 , V_86 ,
V_147 , V_117 ) ;
if ( F_127 ( V_144 -> V_151 [ V_86 ] ) ) {
V_115 = F_134 ( V_144 -> V_151 [ V_86 ] ) ;
V_144 -> V_151 [ V_86 ] = NULL ;
F_135 ( V_117 ) ;
goto V_185;
}
V_86 ++ ;
}
} else if ( V_175 && V_175 -> V_151 ) {
for ( V_86 = 0 ; V_86 < V_186 ; V_86 ++ ) {
struct V_187 * V_188 ;
int V_117 ;
V_188 = & V_175 -> V_151 [ V_86 ] ;
if ( ! V_188 ) {
V_115 = - V_125 ;
goto V_185;
}
V_117 = F_136 ( V_146 , V_86 ) ;
if ( V_117 < 0 ) {
V_115 = V_117 ;
goto V_185;
}
V_144 -> V_151 [ V_86 ] =
F_100 ( V_144 , V_146 , V_86 ,
V_188 -> V_147 , V_117 ) ;
if ( F_127 ( V_144 -> V_151 [ V_86 ] ) ) {
V_115 = F_134 ( V_144 -> V_151 [ V_86 ] ) ;
goto V_185;
}
}
}
return 0 ;
V_185:
for ( V_86 = 0 ; V_86 < V_186 ; V_86 ++ )
if ( V_144 -> V_151 [ V_86 ] ) {
F_96 ( V_144 -> V_151 [ V_86 ] ) ;
if ( V_146 -> V_54 . V_183 )
F_135 ( V_144 -> V_151 [ V_86 ] -> V_117 ) ;
}
if ( ! F_127 ( V_144 -> V_182 ) ) {
F_137 ( V_144 -> V_182 ) ;
F_138 ( V_144 -> V_182 ) ;
}
return V_115 ;
}
static int F_139 ( struct V_145 * V_146 )
{
struct V_143 * V_144 = F_140 ( V_146 ) ;
int V_86 ;
for ( V_86 = 0 ; V_86 < V_186 ; V_86 ++ ) {
if ( V_144 -> V_151 [ V_86 ] )
F_96 ( V_144 -> V_151 [ V_86 ] ) ;
}
if ( ! F_127 ( V_144 -> V_182 ) ) {
F_137 ( V_144 -> V_182 ) ;
F_138 ( V_144 -> V_182 ) ;
}
return 0 ;
}
static int T_8 F_141 ( void )
{
return F_142 ( & V_189 ) ;
}
