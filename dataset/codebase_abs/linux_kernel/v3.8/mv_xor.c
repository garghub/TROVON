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
static void F_8 ( struct V_1 * V_2 , T_1 V_14 )
{
V_2 -> V_15 = V_14 ;
}
static void F_9 ( struct V_1 * V_2 ,
T_2 V_16 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_9 = V_16 ;
}
static int F_10 ( T_3 V_17 )
{
return 1 ;
}
static void F_11 ( struct V_1 * V_2 ,
int V_18 , T_2 V_16 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_11 [ V_18 ] = V_16 ;
if ( V_2 -> type == V_19 )
V_5 -> V_8 |= ( 1 << V_18 ) ;
}
static T_1 F_12 ( struct V_20 * V_21 )
{
return F_13 ( F_14 ( V_21 ) ) ;
}
static void F_15 ( struct V_20 * V_21 ,
T_1 V_13 )
{
F_16 ( V_13 , F_17 ( V_21 ) ) ;
}
static void F_18 ( struct V_20 * V_21 , T_1 V_22 )
{
F_16 ( V_22 , F_19 ( V_21 ) ) ;
}
static void F_20 ( struct V_20 * V_21 , T_1 V_23 )
{
F_16 ( V_23 , F_21 ( V_21 ) ) ;
}
static void F_22 ( struct V_20 * V_21 , T_1 V_15 )
{
F_16 ( V_15 , F_23 ( V_21 ) ) ;
F_16 ( V_15 , F_24 ( V_21 ) ) ;
}
static void F_25 ( struct V_20 * V_21 )
{
T_1 V_14 = F_13 ( F_26 ( V_21 ) ) ;
V_14 |= V_24 << ( V_21 -> V_25 * 16 ) ;
F_16 ( V_14 , F_26 ( V_21 ) ) ;
}
static T_1 F_27 ( struct V_20 * V_21 )
{
T_1 V_26 = F_13 ( F_28 ( V_21 ) ) ;
V_26 = ( V_26 >> ( V_21 -> V_25 * 16 ) ) & 0xFFFF ;
return V_26 ;
}
static int F_29 ( T_1 V_26 )
{
if ( V_26 & ( ( 1 << 4 ) | ( 1 << 5 ) | ( 1 << 6 ) | ( 1 << 7 ) | ( 1 << 8 ) | ( 1 << 9 ) ) )
return 1 ;
return 0 ;
}
static void F_30 ( struct V_20 * V_21 )
{
T_1 V_14 = ~ ( 1 << ( V_21 -> V_25 * 16 ) ) ;
F_31 ( F_32 ( V_21 ) , L_1 , V_27 , V_14 ) ;
F_16 ( V_14 , F_28 ( V_21 ) ) ;
}
static void F_33 ( struct V_20 * V_21 )
{
T_1 V_14 = 0xFFFF0000 >> ( V_21 -> V_25 * 16 ) ;
F_16 ( V_14 , F_28 ( V_21 ) ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_1 * V_28 = F_35 (
V_2 -> V_29 . V_30 , struct V_1 , V_29 ) ;
if ( V_28 -> type != V_2 -> type )
return 0 ;
if ( V_2 -> type == V_31 )
return 0 ;
return 1 ;
}
static void F_36 ( struct V_20 * V_21 ,
enum V_32 type )
{
T_1 V_33 ;
T_1 V_34 = F_13 ( F_37 ( V_21 ) ) ;
switch ( type ) {
case V_19 :
V_33 = V_35 ;
break;
case V_36 :
V_33 = V_37 ;
break;
case V_31 :
V_33 = V_38 ;
break;
default:
F_38 ( F_32 ( V_21 ) ,
L_2 ,
type ) ;
F_39 () ;
return;
}
V_34 &= ~ 0x7 ;
V_34 |= V_33 ;
F_16 ( V_34 , F_37 ( V_21 ) ) ;
V_21 -> V_39 = type ;
}
static void F_40 ( struct V_20 * V_21 )
{
T_1 V_40 ;
F_31 ( F_32 ( V_21 ) , L_3 ) ;
V_40 = F_13 ( F_41 ( V_21 ) ) ;
V_40 |= 0x1 ;
F_16 ( V_40 , F_41 ( V_21 ) ) ;
}
static char F_42 ( struct V_20 * V_21 )
{
T_1 V_41 = F_13 ( F_41 ( V_21 ) ) ;
V_41 = ( V_41 >> 4 ) & 0x3 ;
return ( V_41 == 1 ) ? 1 : 0 ;
}
static int F_43 ( T_3 V_17 , int V_42 )
{
return 1 ;
}
static void F_44 ( struct V_20 * V_43 ,
struct V_1 * V_44 )
{
F_31 ( F_32 ( V_43 ) , L_4 ,
V_27 , __LINE__ , V_44 ) ;
V_44 -> V_45 = 0 ;
}
static void F_45 ( struct V_20 * V_43 ,
struct V_1 * V_46 )
{
F_31 ( F_32 ( V_43 ) , L_5 ,
V_27 , __LINE__ , V_46 ) ;
if ( V_46 -> type != V_43 -> V_39 )
F_36 ( V_43 , V_46 -> type ) ;
if ( V_46 -> type == V_31 ) {
struct V_4 * V_5 = V_46 -> V_5 ;
F_18 ( V_43 , V_5 -> V_9 ) ;
F_20 ( V_43 , V_46 -> V_47 ) ;
F_22 ( V_43 , V_46 -> V_15 ) ;
} else {
F_15 ( V_43 , V_46 -> V_48 . V_49 ) ;
}
V_43 -> V_50 += V_46 -> V_51 ;
F_46 ( & V_43 -> V_52 ) ;
}
static T_4
F_47 ( struct V_1 * V_2 ,
struct V_20 * V_43 , T_4 V_53 )
{
F_6 ( V_2 -> V_48 . V_53 < 0 ) ;
if ( V_2 -> V_48 . V_53 > 0 ) {
V_53 = V_2 -> V_48 . V_53 ;
if ( V_2 -> V_48 . V_54 )
V_2 -> V_48 . V_54 (
V_2 -> V_48 . V_55 ) ;
if ( V_2 -> V_56 && V_2 -> V_47 ) {
struct V_1 * V_57 = V_2 -> V_56 ;
struct V_58 * V_59 = F_32 ( V_43 ) ;
T_1 V_17 = V_57 -> V_47 ;
enum V_60 V_3 = V_2 -> V_48 . V_3 ;
T_1 V_42 ;
T_2 V_16 ;
T_2 V_61 ;
V_42 = V_57 -> V_62 ;
V_61 = F_2 ( V_57 ) ;
if ( ! ( V_3 & V_63 ) ) {
enum V_64 V_65 ;
if ( V_42 > 1 )
V_65 = V_66 ;
else
V_65 = V_67 ;
F_48 ( V_59 , V_61 , V_17 , V_65 ) ;
}
if ( ! ( V_3 & V_68 ) ) {
while ( V_42 -- ) {
V_16 = F_3 ( V_57 ,
V_42 ) ;
if ( V_16 == V_61 )
continue;
F_48 ( V_59 , V_16 , V_17 ,
V_69 ) ;
}
}
V_2 -> V_56 = NULL ;
}
}
F_49 ( & V_2 -> V_48 ) ;
return V_53 ;
}
static int
F_50 ( struct V_20 * V_43 )
{
struct V_1 * V_70 , * V_71 ;
F_31 ( F_32 ( V_43 ) , L_6 , V_27 , __LINE__ ) ;
F_51 (iter, _iter, &mv_chan->completed_slots,
completed_node) {
if ( F_52 ( & V_70 -> V_48 ) ) {
F_53 ( & V_70 -> V_72 ) ;
F_44 ( V_43 , V_70 ) ;
}
}
return 0 ;
}
static int
F_54 ( struct V_1 * V_2 ,
struct V_20 * V_43 )
{
F_31 ( F_32 ( V_43 ) , L_7 ,
V_27 , __LINE__ , V_2 , V_2 -> V_48 . V_3 ) ;
F_53 ( & V_2 -> V_29 ) ;
if ( ! F_52 ( & V_2 -> V_48 ) ) {
F_55 ( & V_2 -> V_72 , & V_43 -> V_73 ) ;
return 0 ;
}
F_44 ( V_43 , V_2 ) ;
return 0 ;
}
static void F_56 ( struct V_20 * V_43 )
{
struct V_1 * V_70 , * V_71 ;
T_4 V_53 = 0 ;
int V_74 = F_42 ( V_43 ) ;
T_1 V_75 = F_12 ( V_43 ) ;
int V_76 = 0 ;
F_31 ( F_32 ( V_43 ) , L_6 , V_27 , __LINE__ ) ;
F_31 ( F_32 ( V_43 ) , L_8 , V_75 ) ;
F_50 ( V_43 ) ;
F_51 (iter, _iter, &mv_chan->chain,
chain_node) {
F_57 ( V_71 ) ;
F_57 ( & V_71 -> V_48 ) ;
if ( V_76 )
break;
if ( V_70 -> V_48 . V_49 == V_75 ) {
V_76 = 1 ;
if ( V_74 )
break;
}
V_53 = F_47 ( V_70 , V_43 , V_53 ) ;
if ( F_54 ( V_70 , V_43 ) )
break;
}
if ( ( V_74 == 0 ) && ! F_58 ( & V_43 -> V_77 ) ) {
struct V_1 * V_78 ;
V_78 = F_35 ( V_43 -> V_77 . V_79 ,
struct V_1 ,
V_29 ) ;
F_45 ( V_43 , V_78 ) ;
}
if ( V_53 > 0 )
V_43 -> V_52 . V_80 = V_53 ;
}
static void
F_59 ( struct V_20 * V_43 )
{
F_60 ( & V_43 -> V_81 ) ;
F_56 ( V_43 ) ;
F_61 ( & V_43 -> V_81 ) ;
}
static void F_62 ( unsigned long V_82 )
{
struct V_20 * V_21 = (struct V_20 * ) V_82 ;
F_59 ( V_21 ) ;
}
static struct V_1 *
F_63 ( struct V_20 * V_43 , int V_83 ,
int V_45 )
{
struct V_1 * V_70 , * V_71 , * V_84 = NULL ;
F_64 ( V_77 ) ;
int V_85 , V_86 = 0 ;
V_86:
V_85 = 0 ;
if ( V_86 == 0 )
V_70 = V_43 -> V_87 ;
else
V_70 = F_35 ( & V_43 -> V_88 ,
struct V_1 ,
V_89 ) ;
F_65 (
iter, _iter, &mv_chan->all_slots, slot_node) {
F_57 ( V_71 ) ;
F_57 ( & V_71 -> V_48 ) ;
if ( V_70 -> V_45 ) {
if ( V_86 )
break;
V_85 = 0 ;
continue;
}
if ( ! V_85 ++ )
V_84 = V_70 ;
if ( V_85 == V_83 ) {
struct V_1 * V_90 = NULL ;
struct V_1 * V_87 = NULL ;
V_70 = V_84 ;
while ( V_83 ) {
int V_91 ;
F_66 ( & V_70 -> V_48 ) ;
F_55 ( & V_70 -> V_29 , & V_77 ) ;
V_90 = V_70 ;
V_70 -> V_48 . V_53 = 0 ;
V_70 -> V_51 = V_83 ;
V_70 -> V_92 = NULL ;
for ( V_91 = 0 ; V_91 < V_45 ; V_91 ++ ) {
V_70 -> V_45 = V_45 - V_91 ;
V_87 = V_70 ;
V_70 = F_35 ( V_70 -> V_89 . V_79 ,
struct V_1 ,
V_89 ) ;
}
V_83 -= V_45 ;
}
V_90 -> V_56 = V_84 ;
V_90 -> V_48 . V_53 = - V_93 ;
F_67 ( & V_77 , & V_90 -> V_94 ) ;
V_43 -> V_87 = V_87 ;
F_7 ( V_84 ) ;
F_7 ( V_90 ) ;
return V_90 ;
}
}
if ( ! V_86 ++ )
goto V_86;
F_68 ( & V_43 -> V_95 ) ;
return NULL ;
}
static T_4
F_69 ( struct V_96 * V_97 )
{
struct V_1 * V_46 = F_70 ( V_97 ) ;
struct V_20 * V_43 = F_71 ( V_97 -> V_21 ) ;
struct V_1 * V_98 , * V_99 ;
T_4 V_53 ;
int V_100 = 1 ;
F_31 ( F_32 ( V_43 ) ,
L_9 ,
V_27 , V_46 , & V_46 -> V_48 ) ;
V_98 = V_46 -> V_56 ;
F_60 ( & V_43 -> V_81 ) ;
V_53 = F_72 ( V_97 ) ;
if ( F_58 ( & V_43 -> V_77 ) )
F_73 ( & V_46 -> V_94 , & V_43 -> V_77 ) ;
else {
V_100 = 0 ;
V_99 = F_35 ( V_43 -> V_77 . V_30 ,
struct V_1 ,
V_29 ) ;
F_73 ( & V_98 -> V_94 ,
& V_99 -> V_29 ) ;
if ( ! F_34 ( V_98 ) )
goto V_101;
F_31 ( F_32 ( V_43 ) , L_10 ,
V_99 -> V_48 . V_49 ) ;
F_5 ( V_99 , V_98 -> V_48 . V_49 ) ;
if ( ! F_42 ( V_43 ) ) {
T_1 V_75 = F_12 ( V_43 ) ;
if ( V_75 == V_99 -> V_48 . V_49 )
V_100 = 1 ;
}
}
if ( V_100 )
F_45 ( V_43 , V_98 ) ;
V_101:
F_61 ( & V_43 -> V_81 ) ;
return V_53 ;
}
static int F_74 ( struct V_102 * V_21 )
{
char * V_5 ;
int V_25 ;
struct V_20 * V_43 = F_71 ( V_21 ) ;
struct V_1 * V_44 = NULL ;
int V_103 = V_104 / V_105 ;
V_25 = V_43 -> V_106 ;
while ( V_25 < V_103 ) {
V_44 = F_75 ( sizeof( * V_44 ) , V_107 ) ;
if ( ! V_44 ) {
F_76 ( V_108 L_11
L_12 , V_25 ) ;
break;
}
V_5 = ( char * ) V_43 -> V_109 ;
V_44 -> V_5 = ( void * ) & V_5 [ V_25 * V_105 ] ;
F_77 ( & V_44 -> V_48 , V_21 ) ;
V_44 -> V_48 . V_110 = F_69 ;
F_78 ( & V_44 -> V_29 ) ;
F_78 ( & V_44 -> V_89 ) ;
F_78 ( & V_44 -> V_94 ) ;
V_5 = ( char * ) V_43 -> V_111 ;
V_44 -> V_48 . V_49 =
( T_2 ) & V_5 [ V_25 * V_105 ] ;
V_44 -> V_25 = V_25 ++ ;
F_60 ( & V_43 -> V_81 ) ;
V_43 -> V_106 = V_25 ;
F_55 ( & V_44 -> V_89 , & V_43 -> V_88 ) ;
F_61 ( & V_43 -> V_81 ) ;
}
if ( V_43 -> V_106 && ! V_43 -> V_87 )
V_43 -> V_87 = F_35 ( V_43 -> V_88 . V_79 ,
struct V_1 ,
V_89 ) ;
F_31 ( F_32 ( V_43 ) ,
L_13 ,
V_43 -> V_106 , V_43 -> V_87 ) ;
return V_43 -> V_106 ? : - V_112 ;
}
static struct V_96 *
F_79 ( struct V_102 * V_21 , T_2 V_61 , T_2 V_113 ,
T_3 V_17 , unsigned long V_3 )
{
struct V_20 * V_43 = F_71 ( V_21 ) ;
struct V_1 * V_46 , * V_98 ;
int V_51 ;
F_31 ( F_32 ( V_43 ) ,
L_14 ,
V_27 , V_61 , V_113 , V_17 , V_3 ) ;
if ( F_80 ( V_17 < V_114 ) )
return NULL ;
F_6 ( V_17 > V_115 ) ;
F_60 ( & V_43 -> V_81 ) ;
V_51 = F_81 ( V_17 ) ;
V_46 = F_63 ( V_43 , V_51 , 1 ) ;
if ( V_46 ) {
V_46 -> type = V_36 ;
V_46 -> V_48 . V_3 = V_3 ;
V_98 = V_46 -> V_56 ;
F_1 ( V_98 , V_3 ) ;
F_4 ( V_98 , V_17 ) ;
F_9 ( V_46 -> V_56 , V_61 ) ;
F_11 ( V_98 , 0 , V_113 ) ;
V_46 -> V_62 = 1 ;
V_46 -> V_47 = V_17 ;
}
F_61 ( & V_43 -> V_81 ) ;
F_31 ( F_32 ( V_43 ) ,
L_15 ,
V_27 , V_46 , V_46 ? & V_46 -> V_48 : 0 ) ;
return V_46 ? & V_46 -> V_48 : NULL ;
}
static struct V_96 *
F_82 ( struct V_102 * V_21 , T_2 V_61 , int V_15 ,
T_3 V_17 , unsigned long V_3 )
{
struct V_20 * V_43 = F_71 ( V_21 ) ;
struct V_1 * V_46 , * V_98 ;
int V_51 ;
F_31 ( F_32 ( V_43 ) ,
L_16 ,
V_27 , V_61 , V_17 , V_3 ) ;
if ( F_80 ( V_17 < V_114 ) )
return NULL ;
F_6 ( V_17 > V_115 ) ;
F_60 ( & V_43 -> V_81 ) ;
V_51 = F_10 ( V_17 ) ;
V_46 = F_63 ( V_43 , V_51 , 1 ) ;
if ( V_46 ) {
V_46 -> type = V_31 ;
V_46 -> V_48 . V_3 = V_3 ;
V_98 = V_46 -> V_56 ;
F_1 ( V_98 , V_3 ) ;
F_4 ( V_98 , V_17 ) ;
F_9 ( V_46 -> V_56 , V_61 ) ;
F_8 ( V_98 , V_15 ) ;
V_46 -> V_62 = 1 ;
V_46 -> V_47 = V_17 ;
}
F_61 ( & V_43 -> V_81 ) ;
F_31 ( F_32 ( V_43 ) ,
L_17 ,
V_27 , V_46 , & V_46 -> V_48 ) ;
return V_46 ? & V_46 -> V_48 : NULL ;
}
static struct V_96 *
F_83 ( struct V_102 * V_21 , T_2 V_61 , T_2 * V_113 ,
unsigned int V_42 , T_3 V_17 , unsigned long V_3 )
{
struct V_20 * V_43 = F_71 ( V_21 ) ;
struct V_1 * V_46 , * V_98 ;
int V_51 ;
if ( F_80 ( V_17 < V_114 ) )
return NULL ;
F_6 ( V_17 > V_115 ) ;
F_31 ( F_32 ( V_43 ) ,
L_18 ,
V_27 , V_42 , V_17 , V_61 , V_3 ) ;
F_60 ( & V_43 -> V_81 ) ;
V_51 = F_43 ( V_17 , V_42 ) ;
V_46 = F_63 ( V_43 , V_51 , 1 ) ;
if ( V_46 ) {
V_46 -> type = V_19 ;
V_46 -> V_48 . V_3 = V_3 ;
V_98 = V_46 -> V_56 ;
F_1 ( V_98 , V_3 ) ;
F_4 ( V_98 , V_17 ) ;
F_9 ( V_46 -> V_56 , V_61 ) ;
V_46 -> V_62 = V_42 ;
V_46 -> V_47 = V_17 ;
while ( V_42 -- )
F_11 ( V_98 , V_42 , V_113 [ V_42 ] ) ;
}
F_61 ( & V_43 -> V_81 ) ;
F_31 ( F_32 ( V_43 ) ,
L_17 ,
V_27 , V_46 , & V_46 -> V_48 ) ;
return V_46 ? & V_46 -> V_48 : NULL ;
}
static void F_84 ( struct V_102 * V_21 )
{
struct V_20 * V_43 = F_71 ( V_21 ) ;
struct V_1 * V_70 , * V_71 ;
int V_116 = 0 ;
F_59 ( V_43 ) ;
F_60 ( & V_43 -> V_81 ) ;
F_51 (iter, _iter, &mv_chan->chain,
chain_node) {
V_116 ++ ;
F_53 ( & V_70 -> V_29 ) ;
}
F_51 (iter, _iter, &mv_chan->completed_slots,
completed_node) {
V_116 ++ ;
F_53 ( & V_70 -> V_72 ) ;
}
F_85 (
iter, _iter, &mv_chan->all_slots, slot_node) {
F_53 ( & V_70 -> V_89 ) ;
F_86 ( V_70 ) ;
V_43 -> V_106 -- ;
}
V_43 -> V_87 = NULL ;
F_31 ( F_32 ( V_43 ) , L_19 ,
V_27 , V_43 -> V_106 ) ;
F_61 ( & V_43 -> V_81 ) ;
if ( V_116 )
F_38 ( F_32 ( V_43 ) ,
L_20 , V_116 ) ;
}
static enum V_117 F_87 ( struct V_102 * V_21 ,
T_4 V_53 ,
struct V_118 * V_119 )
{
struct V_20 * V_43 = F_71 ( V_21 ) ;
enum V_117 V_120 ;
V_120 = F_88 ( V_21 , V_53 , V_119 ) ;
if ( V_120 == V_121 ) {
F_50 ( V_43 ) ;
return V_120 ;
}
F_59 ( V_43 ) ;
return F_88 ( V_21 , V_53 , V_119 ) ;
}
static void F_89 ( struct V_20 * V_21 )
{
T_1 V_14 ;
V_14 = F_13 ( F_37 ( V_21 ) ) ;
F_38 ( F_32 ( V_21 ) ,
L_21 , V_14 ) ;
V_14 = F_13 ( F_41 ( V_21 ) ) ;
F_38 ( F_32 ( V_21 ) ,
L_22 , V_14 ) ;
V_14 = F_13 ( F_28 ( V_21 ) ) ;
F_38 ( F_32 ( V_21 ) ,
L_23 , V_14 ) ;
V_14 = F_13 ( F_26 ( V_21 ) ) ;
F_38 ( F_32 ( V_21 ) ,
L_24 , V_14 ) ;
V_14 = F_13 ( F_90 ( V_21 ) ) ;
F_38 ( F_32 ( V_21 ) ,
L_25 , V_14 ) ;
V_14 = F_13 ( F_91 ( V_21 ) ) ;
F_38 ( F_32 ( V_21 ) ,
L_26 , V_14 ) ;
}
static void F_92 ( struct V_20 * V_21 ,
T_1 V_26 )
{
if ( V_26 & ( 1 << 4 ) ) {
F_31 ( F_32 ( V_21 ) ,
L_27 ) ;
return;
}
F_38 ( F_32 ( V_21 ) ,
L_28 ,
V_21 -> V_25 , V_26 ) ;
F_89 ( V_21 ) ;
F_39 () ;
}
static T_5 F_93 ( int V_122 , void * V_82 )
{
struct V_20 * V_21 = V_82 ;
T_1 V_26 = F_27 ( V_21 ) ;
F_31 ( F_32 ( V_21 ) , L_29 , V_26 ) ;
if ( F_29 ( V_26 ) )
F_92 ( V_21 , V_26 ) ;
F_68 ( & V_21 -> V_95 ) ;
F_30 ( V_21 ) ;
return V_123 ;
}
static void F_46 ( struct V_102 * V_21 )
{
struct V_20 * V_43 = F_71 ( V_21 ) ;
if ( V_43 -> V_50 >= V_124 ) {
V_43 -> V_50 = 0 ;
F_40 ( V_43 ) ;
}
}
static int F_94 ( struct V_20 * V_43 )
{
int V_91 ;
void * V_113 , * V_61 ;
T_2 V_125 , V_126 ;
struct V_102 * V_102 ;
T_4 V_53 ;
struct V_96 * V_97 ;
int V_127 = 0 ;
V_113 = F_95 ( sizeof( V_128 ) * V_129 , V_107 ) ;
if ( ! V_113 )
return - V_112 ;
V_61 = F_75 ( sizeof( V_128 ) * V_129 , V_107 ) ;
if ( ! V_61 ) {
F_86 ( V_113 ) ;
return - V_112 ;
}
for ( V_91 = 0 ; V_91 < V_129 ; V_91 ++ )
( ( V_128 * ) V_113 ) [ V_91 ] = ( V_128 ) V_91 ;
V_102 = & V_43 -> V_52 ;
if ( F_74 ( V_102 ) < 1 ) {
V_127 = - V_130 ;
goto V_131;
}
V_126 = F_96 ( V_102 -> V_58 -> V_59 , V_61 ,
V_129 , V_67 ) ;
V_125 = F_96 ( V_102 -> V_58 -> V_59 , V_113 ,
V_129 , V_69 ) ;
V_97 = F_79 ( V_102 , V_126 , V_125 ,
V_129 , 0 ) ;
V_53 = F_69 ( V_97 ) ;
F_46 ( V_102 ) ;
F_66 ( V_97 ) ;
F_97 ( 1 ) ;
if ( F_87 ( V_102 , V_53 , NULL ) !=
V_121 ) {
F_38 ( V_102 -> V_58 -> V_59 ,
L_30 ) ;
V_127 = - V_130 ;
goto V_132;
}
F_98 ( V_102 -> V_58 -> V_59 , V_126 ,
V_129 , V_67 ) ;
if ( memcmp ( V_113 , V_61 , V_129 ) ) {
F_38 ( V_102 -> V_58 -> V_59 ,
L_31 ) ;
V_127 = - V_130 ;
goto V_132;
}
V_132:
F_84 ( V_102 ) ;
V_131:
F_86 ( V_113 ) ;
F_86 ( V_61 ) ;
return V_127 ;
}
static int
F_99 ( struct V_20 * V_43 )
{
int V_91 , V_10 ;
struct V_133 * V_61 ;
struct V_133 * V_134 [ V_135 ] ;
T_2 V_136 [ V_135 ] ;
T_2 V_126 ;
struct V_96 * V_97 ;
struct V_102 * V_102 ;
T_4 V_53 ;
V_128 V_137 = 0 ;
T_1 V_138 ;
int V_127 = 0 ;
for ( V_10 = 0 ; V_10 < V_135 ; V_10 ++ ) {
V_134 [ V_10 ] = F_100 ( V_107 ) ;
if ( ! V_134 [ V_10 ] ) {
while ( V_10 -- )
F_101 ( V_134 [ V_10 ] ) ;
return - V_112 ;
}
}
V_61 = F_100 ( V_107 ) ;
if ( ! V_61 ) {
while ( V_10 -- )
F_101 ( V_134 [ V_10 ] ) ;
return - V_112 ;
}
for ( V_10 = 0 ; V_10 < V_135 ; V_10 ++ ) {
V_128 * V_139 = F_102 ( V_134 [ V_10 ] ) ;
for ( V_91 = 0 ; V_91 < V_140 ; V_91 ++ )
V_139 [ V_91 ] = ( 1 << V_10 ) ;
}
for ( V_10 = 0 ; V_10 < V_135 ; V_10 ++ )
V_137 ^= ( V_128 ) ( 1 << V_10 ) ;
V_138 = ( V_137 << 24 ) | ( V_137 << 16 ) |
( V_137 << 8 ) | V_137 ;
memset ( F_102 ( V_61 ) , 0 , V_140 ) ;
V_102 = & V_43 -> V_52 ;
if ( F_74 ( V_102 ) < 1 ) {
V_127 = - V_130 ;
goto V_131;
}
V_126 = F_103 ( V_102 -> V_58 -> V_59 , V_61 , 0 , V_140 ,
V_67 ) ;
for ( V_91 = 0 ; V_91 < V_135 ; V_91 ++ )
V_136 [ V_91 ] = F_103 ( V_102 -> V_58 -> V_59 , V_134 [ V_91 ] ,
0 , V_140 , V_69 ) ;
V_97 = F_83 ( V_102 , V_126 , V_136 ,
V_135 , V_140 , 0 ) ;
V_53 = F_69 ( V_97 ) ;
F_46 ( V_102 ) ;
F_66 ( V_97 ) ;
F_97 ( 8 ) ;
if ( F_87 ( V_102 , V_53 , NULL ) !=
V_121 ) {
F_38 ( V_102 -> V_58 -> V_59 ,
L_32 ) ;
V_127 = - V_130 ;
goto V_132;
}
F_98 ( V_102 -> V_58 -> V_59 , V_126 ,
V_140 , V_67 ) ;
for ( V_91 = 0 ; V_91 < ( V_140 / sizeof( T_1 ) ) ; V_91 ++ ) {
T_1 * V_139 = F_102 ( V_61 ) ;
if ( V_139 [ V_91 ] != V_138 ) {
F_38 ( V_102 -> V_58 -> V_59 ,
L_33
L_34 , V_91 ,
V_139 [ V_91 ] , V_138 ) ;
V_127 = - V_130 ;
goto V_132;
}
}
V_132:
F_84 ( V_102 ) ;
V_131:
V_10 = V_135 ;
while ( V_10 -- )
F_101 ( V_134 [ V_10 ] ) ;
F_101 ( V_61 ) ;
return V_127 ;
}
static int
F_104 ( struct V_102 * V_21 , enum V_141 V_142 ,
unsigned long V_143 )
{
return - V_144 ;
}
static int F_105 ( struct V_20 * V_43 )
{
struct V_102 * V_21 , * V_145 ;
struct V_58 * V_59 = V_43 -> V_146 . V_59 ;
F_106 ( & V_43 -> V_146 ) ;
F_107 ( V_59 , V_104 ,
V_43 -> V_109 , V_43 -> V_111 ) ;
F_51 (chan, _chan, &mv_chan->dmadev.channels,
device_node) {
F_53 ( & V_21 -> V_147 ) ;
}
F_108 ( V_43 -> V_122 , V_43 ) ;
return 0 ;
}
static struct V_20 *
F_109 ( struct V_148 * V_149 ,
struct V_150 * V_151 ,
int V_25 , T_6 V_152 , int V_122 )
{
int V_120 = 0 ;
struct V_20 * V_43 ;
struct V_153 * V_154 ;
V_43 = F_110 ( & V_151 -> V_59 , sizeof( * V_43 ) , V_107 ) ;
if ( ! V_43 ) {
V_120 = - V_112 ;
goto V_155;
}
V_43 -> V_25 = V_25 ;
V_43 -> V_122 = V_122 ;
V_154 = & V_43 -> V_146 ;
V_43 -> V_109 =
F_111 ( & V_151 -> V_59 , V_104 ,
& V_43 -> V_111 , V_107 ) ;
if ( ! V_43 -> V_109 )
return F_112 ( - V_112 ) ;
V_154 -> V_152 = V_152 ;
F_78 ( & V_154 -> V_156 ) ;
V_154 -> V_157 = F_74 ;
V_154 -> V_158 = F_84 ;
V_154 -> V_159 = F_87 ;
V_154 -> V_160 = F_46 ;
V_154 -> V_161 = F_104 ;
V_154 -> V_59 = & V_151 -> V_59 ;
if ( F_113 ( V_36 , V_154 -> V_152 ) )
V_154 -> V_162 = F_79 ;
if ( F_113 ( V_31 , V_154 -> V_152 ) )
V_154 -> V_163 = F_82 ;
if ( F_113 ( V_19 , V_154 -> V_152 ) ) {
V_154 -> V_164 = 8 ;
V_154 -> V_165 = F_83 ;
}
V_43 -> V_166 = V_149 -> V_167 ;
if ( ! V_43 -> V_166 ) {
V_120 = - V_112 ;
goto V_155;
}
F_114 ( & V_43 -> V_95 , F_62 , ( unsigned long )
V_43 ) ;
F_33 ( V_43 ) ;
V_120 = F_115 ( V_43 -> V_122 , F_93 ,
0 , F_116 ( & V_151 -> V_59 ) , V_43 ) ;
if ( V_120 )
goto V_155;
F_25 ( V_43 ) ;
F_36 ( V_43 , V_36 ) ;
F_117 ( & V_43 -> V_81 ) ;
F_78 ( & V_43 -> V_77 ) ;
F_78 ( & V_43 -> V_73 ) ;
F_78 ( & V_43 -> V_88 ) ;
V_43 -> V_52 . V_58 = V_154 ;
F_118 ( & V_43 -> V_52 ) ;
F_55 ( & V_43 -> V_52 . V_147 , & V_154 -> V_156 ) ;
if ( F_113 ( V_36 , V_154 -> V_152 ) ) {
V_120 = F_94 ( V_43 ) ;
F_31 ( & V_151 -> V_59 , L_35 , V_120 ) ;
if ( V_120 )
goto V_168;
}
if ( F_113 ( V_19 , V_154 -> V_152 ) ) {
V_120 = F_99 ( V_43 ) ;
F_31 ( & V_151 -> V_59 , L_36 , V_120 ) ;
if ( V_120 )
goto V_168;
}
F_119 ( & V_151 -> V_59 , L_37
L_38 ,
F_113 ( V_19 , V_154 -> V_152 ) ? L_39 : L_40 ,
F_113 ( V_31 , V_154 -> V_152 ) ? L_41 : L_40 ,
F_113 ( V_36 , V_154 -> V_152 ) ? L_42 : L_40 ,
F_113 ( V_169 , V_154 -> V_152 ) ? L_43 : L_40 ) ;
F_120 ( V_154 ) ;
return V_43 ;
V_168:
F_108 ( V_43 -> V_122 , V_43 ) ;
V_155:
F_107 ( & V_151 -> V_59 , V_104 ,
V_43 -> V_109 , V_43 -> V_111 ) ;
return F_112 ( V_120 ) ;
}
static void
F_121 ( struct V_148 * V_149 ,
const struct V_170 * V_171 )
{
void T_7 * V_172 = V_149 -> V_167 ;
T_1 V_173 = 0 ;
int V_91 ;
for ( V_91 = 0 ; V_91 < 8 ; V_91 ++ ) {
F_122 ( 0 , V_172 + F_123 ( V_91 ) ) ;
F_122 ( 0 , V_172 + F_124 ( V_91 ) ) ;
if ( V_91 < 4 )
F_122 ( 0 , V_172 + F_125 ( V_91 ) ) ;
}
for ( V_91 = 0 ; V_91 < V_171 -> V_174 ; V_91 ++ ) {
const struct V_175 * V_176 = V_171 -> V_176 + V_91 ;
F_122 ( ( V_176 -> V_172 & 0xffff0000 ) |
( V_176 -> V_177 << 8 ) |
V_171 -> V_178 , V_172 + F_123 ( V_91 ) ) ;
F_122 ( ( V_176 -> V_179 - 1 ) & 0xffff0000 , V_172 + F_124 ( V_91 ) ) ;
V_173 |= ( 1 << V_91 ) ;
V_173 |= 3 << ( 16 + ( 2 * V_91 ) ) ;
}
F_122 ( V_173 , V_172 + F_126 ( 0 ) ) ;
F_122 ( V_173 , V_172 + F_126 ( 1 ) ) ;
F_122 ( 0 , V_172 + F_127 ( 0 ) ) ;
F_122 ( 0 , V_172 + F_127 ( 1 ) ) ;
}
static int F_128 ( struct V_150 * V_151 )
{
const struct V_170 * V_171 ;
struct V_148 * V_149 ;
struct V_180 * V_181 = V_151 -> V_59 . V_182 ;
struct V_183 * V_184 ;
int V_91 , V_120 ;
F_129 ( & V_151 -> V_59 , L_44 ) ;
V_149 = F_110 ( & V_151 -> V_59 , sizeof( * V_149 ) , V_107 ) ;
if ( ! V_149 )
return - V_112 ;
V_184 = F_130 ( V_151 , V_185 , 0 ) ;
if ( ! V_184 )
return - V_130 ;
V_149 -> V_167 = F_131 ( & V_151 -> V_59 , V_184 -> V_186 ,
F_132 ( V_184 ) ) ;
if ( ! V_149 -> V_167 )
return - V_93 ;
V_184 = F_130 ( V_151 , V_185 , 1 ) ;
if ( ! V_184 )
return - V_130 ;
V_149 -> V_187 = F_131 ( & V_151 -> V_59 , V_184 -> V_186 ,
F_132 ( V_184 ) ) ;
if ( ! V_149 -> V_187 )
return - V_93 ;
F_133 ( V_151 , V_149 ) ;
V_171 = F_134 () ;
if ( V_171 )
F_121 ( V_149 , V_171 ) ;
V_149 -> V_188 = F_135 ( & V_151 -> V_59 , NULL ) ;
if ( ! F_136 ( V_149 -> V_188 ) )
F_137 ( V_149 -> V_188 ) ;
if ( V_151 -> V_59 . V_189 ) {
struct V_147 * V_190 ;
int V_91 = 0 ;
F_138 (pdev->dev.of_node, np) {
T_6 V_152 ;
int V_122 ;
F_139 ( V_152 ) ;
if ( F_140 ( V_190 , L_45 ) )
F_141 ( V_36 , V_152 ) ;
if ( F_140 ( V_190 , L_46 ) )
F_141 ( V_19 , V_152 ) ;
if ( F_140 ( V_190 , L_47 ) )
F_141 ( V_31 , V_152 ) ;
if ( F_140 ( V_190 , L_48 ) )
F_141 ( V_169 , V_152 ) ;
V_122 = F_142 ( V_190 , 0 ) ;
if ( ! V_122 ) {
V_120 = - V_130 ;
goto V_191;
}
V_149 -> V_156 [ V_91 ] =
F_109 ( V_149 , V_151 , V_91 ,
V_152 , V_122 ) ;
if ( F_136 ( V_149 -> V_156 [ V_91 ] ) ) {
V_120 = F_143 ( V_149 -> V_156 [ V_91 ] ) ;
V_149 -> V_156 [ V_91 ] = NULL ;
F_144 ( V_122 ) ;
goto V_191;
}
V_91 ++ ;
}
} else if ( V_181 && V_181 -> V_156 ) {
for ( V_91 = 0 ; V_91 < V_192 ; V_91 ++ ) {
struct V_193 * V_194 ;
int V_122 ;
V_194 = & V_181 -> V_156 [ V_91 ] ;
if ( ! V_194 ) {
V_120 = - V_130 ;
goto V_191;
}
V_122 = F_145 ( V_151 , V_91 ) ;
if ( V_122 < 0 ) {
V_120 = V_122 ;
goto V_191;
}
V_149 -> V_156 [ V_91 ] =
F_109 ( V_149 , V_151 , V_91 ,
V_194 -> V_152 , V_122 ) ;
if ( F_136 ( V_149 -> V_156 [ V_91 ] ) ) {
V_120 = F_143 ( V_149 -> V_156 [ V_91 ] ) ;
goto V_191;
}
}
}
return 0 ;
V_191:
for ( V_91 = 0 ; V_91 < V_192 ; V_91 ++ )
if ( V_149 -> V_156 [ V_91 ] ) {
F_105 ( V_149 -> V_156 [ V_91 ] ) ;
if ( V_151 -> V_59 . V_189 )
F_144 ( V_149 -> V_156 [ V_91 ] -> V_122 ) ;
}
if ( ! F_136 ( V_149 -> V_188 ) ) {
F_146 ( V_149 -> V_188 ) ;
F_147 ( V_149 -> V_188 ) ;
}
return V_120 ;
}
static int F_148 ( struct V_150 * V_151 )
{
struct V_148 * V_149 = F_149 ( V_151 ) ;
int V_91 ;
for ( V_91 = 0 ; V_91 < V_192 ; V_91 ++ ) {
if ( V_149 -> V_156 [ V_91 ] )
F_105 ( V_149 -> V_156 [ V_91 ] ) ;
}
if ( ! F_136 ( V_149 -> V_188 ) ) {
F_146 ( V_149 -> V_188 ) ;
F_147 ( V_149 -> V_188 ) ;
}
return 0 ;
}
static int T_8 F_150 ( void )
{
return F_151 ( & V_195 ) ;
}
