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
F_31 ( V_21 -> V_27 -> V_28 . V_29 , L_1 , V_30 , V_14 ) ;
F_16 ( V_14 , F_28 ( V_21 ) ) ;
}
static void F_32 ( struct V_20 * V_21 )
{
T_1 V_14 = 0xFFFF0000 >> ( V_21 -> V_25 * 16 ) ;
F_16 ( V_14 , F_28 ( V_21 ) ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_1 * V_31 = F_34 (
V_2 -> V_32 . V_33 , struct V_1 , V_32 ) ;
if ( V_31 -> type != V_2 -> type )
return 0 ;
if ( V_2 -> type == V_34 )
return 0 ;
return 1 ;
}
static void F_35 ( struct V_20 * V_21 ,
enum V_35 type )
{
T_1 V_36 ;
T_1 V_37 = F_13 ( F_36 ( V_21 ) ) ;
switch ( type ) {
case V_19 :
V_36 = V_38 ;
break;
case V_39 :
V_36 = V_40 ;
break;
case V_34 :
V_36 = V_41 ;
break;
default:
F_37 ( V_42 , V_21 -> V_27 -> V_28 . V_29 ,
L_2 ,
type ) ;
F_38 () ;
return;
}
V_37 &= ~ 0x7 ;
V_37 |= V_36 ;
F_16 ( V_37 , F_36 ( V_21 ) ) ;
V_21 -> V_43 = type ;
}
static void F_39 ( struct V_20 * V_21 )
{
T_1 V_44 ;
F_31 ( V_21 -> V_27 -> V_28 . V_29 , L_3 ) ;
V_44 = F_13 ( F_40 ( V_21 ) ) ;
V_44 |= 0x1 ;
F_16 ( V_44 , F_40 ( V_21 ) ) ;
}
static char F_41 ( struct V_20 * V_21 )
{
T_1 V_45 = F_13 ( F_40 ( V_21 ) ) ;
V_45 = ( V_45 >> 4 ) & 0x3 ;
return ( V_45 == 1 ) ? 1 : 0 ;
}
static int F_42 ( T_3 V_17 , int V_46 )
{
return 1 ;
}
static void F_43 ( struct V_20 * V_47 ,
struct V_1 * V_48 )
{
F_31 ( V_47 -> V_27 -> V_28 . V_29 , L_4 ,
V_30 , __LINE__ , V_48 ) ;
V_48 -> V_49 = 0 ;
}
static void F_44 ( struct V_20 * V_47 ,
struct V_1 * V_50 )
{
F_31 ( V_47 -> V_27 -> V_28 . V_29 , L_5 ,
V_30 , __LINE__ , V_50 ) ;
if ( V_50 -> type != V_47 -> V_43 )
F_35 ( V_47 , V_50 -> type ) ;
if ( V_50 -> type == V_34 ) {
struct V_4 * V_5 = V_50 -> V_5 ;
F_18 ( V_47 , V_5 -> V_9 ) ;
F_20 ( V_47 , V_50 -> V_51 ) ;
F_22 ( V_47 , V_50 -> V_15 ) ;
} else {
F_15 ( V_47 , V_50 -> V_52 . V_53 ) ;
}
V_47 -> V_54 += V_50 -> V_55 ;
F_45 ( & V_47 -> V_28 ) ;
}
static T_4
F_46 ( struct V_1 * V_2 ,
struct V_20 * V_47 , T_4 V_56 )
{
F_6 ( V_2 -> V_52 . V_56 < 0 ) ;
if ( V_2 -> V_52 . V_56 > 0 ) {
V_56 = V_2 -> V_52 . V_56 ;
if ( V_2 -> V_52 . V_57 )
V_2 -> V_52 . V_57 (
V_2 -> V_52 . V_58 ) ;
if ( V_2 -> V_59 && V_2 -> V_51 ) {
struct V_1 * V_60 = V_2 -> V_59 ;
struct V_27 * V_29 =
& V_47 -> V_27 -> V_61 -> V_29 ;
T_1 V_17 = V_60 -> V_51 ;
enum V_62 V_3 = V_2 -> V_52 . V_3 ;
T_1 V_46 ;
T_2 V_16 ;
T_2 V_63 ;
V_46 = V_60 -> V_64 ;
V_63 = F_2 ( V_60 ) ;
if ( ! ( V_3 & V_65 ) ) {
enum V_66 V_67 ;
if ( V_46 > 1 )
V_67 = V_68 ;
else
V_67 = V_69 ;
F_47 ( V_29 , V_63 , V_17 , V_67 ) ;
}
if ( ! ( V_3 & V_70 ) ) {
while ( V_46 -- ) {
V_16 = F_3 ( V_60 ,
V_46 ) ;
if ( V_16 == V_63 )
continue;
F_47 ( V_29 , V_16 , V_17 ,
V_71 ) ;
}
}
V_2 -> V_59 = NULL ;
}
}
F_48 ( & V_2 -> V_52 ) ;
return V_56 ;
}
static int
F_49 ( struct V_20 * V_47 )
{
struct V_1 * V_72 , * V_73 ;
F_31 ( V_47 -> V_27 -> V_28 . V_29 , L_6 , V_30 , __LINE__ ) ;
F_50 (iter, _iter, &mv_chan->completed_slots,
completed_node) {
if ( F_51 ( & V_72 -> V_52 ) ) {
F_52 ( & V_72 -> V_74 ) ;
F_43 ( V_47 , V_72 ) ;
}
}
return 0 ;
}
static int
F_53 ( struct V_1 * V_2 ,
struct V_20 * V_47 )
{
F_31 ( V_47 -> V_27 -> V_28 . V_29 , L_7 ,
V_30 , __LINE__ , V_2 , V_2 -> V_52 . V_3 ) ;
F_52 ( & V_2 -> V_32 ) ;
if ( ! F_51 ( & V_2 -> V_52 ) ) {
F_54 ( & V_2 -> V_74 , & V_47 -> V_75 ) ;
return 0 ;
}
F_43 ( V_47 , V_2 ) ;
return 0 ;
}
static void F_55 ( struct V_20 * V_47 )
{
struct V_1 * V_72 , * V_73 ;
T_4 V_56 = 0 ;
int V_76 = F_41 ( V_47 ) ;
T_1 V_77 = F_12 ( V_47 ) ;
int V_78 = 0 ;
F_31 ( V_47 -> V_27 -> V_28 . V_29 , L_6 , V_30 , __LINE__ ) ;
F_31 ( V_47 -> V_27 -> V_28 . V_29 , L_8 , V_77 ) ;
F_49 ( V_47 ) ;
F_50 (iter, _iter, &mv_chan->chain,
chain_node) {
F_56 ( V_73 ) ;
F_56 ( & V_73 -> V_52 ) ;
if ( V_78 )
break;
if ( V_72 -> V_52 . V_53 == V_77 ) {
V_78 = 1 ;
if ( V_76 )
break;
}
V_56 = F_46 ( V_72 , V_47 , V_56 ) ;
if ( F_53 ( V_72 , V_47 ) )
break;
}
if ( ( V_76 == 0 ) && ! F_57 ( & V_47 -> V_79 ) ) {
struct V_1 * V_80 ;
V_80 = F_34 ( V_47 -> V_79 . V_81 ,
struct V_1 ,
V_32 ) ;
F_44 ( V_47 , V_80 ) ;
}
if ( V_56 > 0 )
V_47 -> V_28 . V_82 = V_56 ;
}
static void
F_58 ( struct V_20 * V_47 )
{
F_59 ( & V_47 -> V_83 ) ;
F_55 ( V_47 ) ;
F_60 ( & V_47 -> V_83 ) ;
}
static void F_61 ( unsigned long V_84 )
{
struct V_20 * V_21 = (struct V_20 * ) V_84 ;
F_58 ( V_21 ) ;
}
static struct V_1 *
F_62 ( struct V_20 * V_47 , int V_85 ,
int V_49 )
{
struct V_1 * V_72 , * V_73 , * V_86 = NULL ;
F_63 ( V_79 ) ;
int V_87 , V_88 = 0 ;
V_88:
V_87 = 0 ;
if ( V_88 == 0 )
V_72 = V_47 -> V_89 ;
else
V_72 = F_34 ( & V_47 -> V_90 ,
struct V_1 ,
V_91 ) ;
F_64 (
iter, _iter, &mv_chan->all_slots, slot_node) {
F_56 ( V_73 ) ;
F_56 ( & V_73 -> V_52 ) ;
if ( V_72 -> V_49 ) {
if ( V_88 )
break;
V_87 = 0 ;
continue;
}
if ( ! V_87 ++ )
V_86 = V_72 ;
if ( V_87 == V_85 ) {
struct V_1 * V_92 = NULL ;
struct V_1 * V_89 = NULL ;
V_72 = V_86 ;
while ( V_85 ) {
int V_93 ;
F_65 ( & V_72 -> V_52 ) ;
F_54 ( & V_72 -> V_32 , & V_79 ) ;
V_92 = V_72 ;
V_72 -> V_52 . V_56 = 0 ;
V_72 -> V_55 = V_85 ;
V_72 -> V_94 = NULL ;
for ( V_93 = 0 ; V_93 < V_49 ; V_93 ++ ) {
V_72 -> V_49 = V_49 - V_93 ;
V_89 = V_72 ;
V_72 = F_34 ( V_72 -> V_91 . V_81 ,
struct V_1 ,
V_91 ) ;
}
V_85 -= V_49 ;
}
V_92 -> V_59 = V_86 ;
V_92 -> V_52 . V_56 = - V_95 ;
F_66 ( & V_79 , & V_92 -> V_96 ) ;
V_47 -> V_89 = V_89 ;
F_7 ( V_86 ) ;
F_7 ( V_92 ) ;
return V_92 ;
}
}
if ( ! V_88 ++ )
goto V_88;
F_67 ( & V_47 -> V_97 ) ;
return NULL ;
}
static T_4
F_68 ( struct V_98 * V_99 )
{
struct V_1 * V_50 = F_69 ( V_99 ) ;
struct V_20 * V_47 = F_70 ( V_99 -> V_21 ) ;
struct V_1 * V_100 , * V_101 ;
T_4 V_56 ;
int V_102 = 1 ;
F_31 ( V_47 -> V_27 -> V_28 . V_29 ,
L_9 ,
V_30 , V_50 , & V_50 -> V_52 ) ;
V_100 = V_50 -> V_59 ;
F_59 ( & V_47 -> V_83 ) ;
V_56 = F_71 ( V_99 ) ;
if ( F_57 ( & V_47 -> V_79 ) )
F_72 ( & V_50 -> V_96 , & V_47 -> V_79 ) ;
else {
V_102 = 0 ;
V_101 = F_34 ( V_47 -> V_79 . V_33 ,
struct V_1 ,
V_32 ) ;
F_72 ( & V_100 -> V_96 ,
& V_101 -> V_32 ) ;
if ( ! F_33 ( V_100 ) )
goto V_103;
F_31 ( V_47 -> V_27 -> V_28 . V_29 , L_10 ,
V_101 -> V_52 . V_53 ) ;
F_5 ( V_101 , V_100 -> V_52 . V_53 ) ;
if ( ! F_41 ( V_47 ) ) {
T_1 V_77 = F_12 ( V_47 ) ;
if ( V_77 == V_101 -> V_52 . V_53 )
V_102 = 1 ;
}
}
if ( V_102 )
F_44 ( V_47 , V_100 ) ;
V_103:
F_60 ( & V_47 -> V_83 ) ;
return V_56 ;
}
static int F_73 ( struct V_104 * V_21 )
{
char * V_5 ;
int V_25 ;
struct V_20 * V_47 = F_70 ( V_21 ) ;
struct V_1 * V_48 = NULL ;
struct V_105 * V_106 =
V_47 -> V_27 -> V_61 -> V_29 . V_107 ;
int V_108 = V_106 -> V_109 / V_110 ;
V_25 = V_47 -> V_111 ;
while ( V_25 < V_108 ) {
V_48 = F_74 ( sizeof( * V_48 ) , V_112 ) ;
if ( ! V_48 ) {
F_75 ( V_113 L_11
L_12 , V_25 ) ;
break;
}
V_5 = ( char * ) V_47 -> V_27 -> V_114 ;
V_48 -> V_5 = ( void * ) & V_5 [ V_25 * V_110 ] ;
F_76 ( & V_48 -> V_52 , V_21 ) ;
V_48 -> V_52 . V_115 = F_68 ;
F_77 ( & V_48 -> V_32 ) ;
F_77 ( & V_48 -> V_91 ) ;
F_77 ( & V_48 -> V_96 ) ;
V_5 = ( char * ) V_47 -> V_27 -> V_116 ;
V_48 -> V_52 . V_53 =
( T_2 ) & V_5 [ V_25 * V_110 ] ;
V_48 -> V_25 = V_25 ++ ;
F_59 ( & V_47 -> V_83 ) ;
V_47 -> V_111 = V_25 ;
F_54 ( & V_48 -> V_91 , & V_47 -> V_90 ) ;
F_60 ( & V_47 -> V_83 ) ;
}
if ( V_47 -> V_111 && ! V_47 -> V_89 )
V_47 -> V_89 = F_34 ( V_47 -> V_90 . V_81 ,
struct V_1 ,
V_91 ) ;
F_31 ( V_47 -> V_27 -> V_28 . V_29 ,
L_13 ,
V_47 -> V_111 , V_47 -> V_89 ) ;
return V_47 -> V_111 ? : - V_117 ;
}
static struct V_98 *
F_78 ( struct V_104 * V_21 , T_2 V_63 , T_2 V_118 ,
T_3 V_17 , unsigned long V_3 )
{
struct V_20 * V_47 = F_70 ( V_21 ) ;
struct V_1 * V_50 , * V_100 ;
int V_55 ;
F_31 ( V_47 -> V_27 -> V_28 . V_29 ,
L_14 ,
V_30 , V_63 , V_118 , V_17 , V_3 ) ;
if ( F_79 ( V_17 < V_119 ) )
return NULL ;
F_6 ( V_17 > V_120 ) ;
F_59 ( & V_47 -> V_83 ) ;
V_55 = F_80 ( V_17 ) ;
V_50 = F_62 ( V_47 , V_55 , 1 ) ;
if ( V_50 ) {
V_50 -> type = V_39 ;
V_50 -> V_52 . V_3 = V_3 ;
V_100 = V_50 -> V_59 ;
F_1 ( V_100 , V_3 ) ;
F_4 ( V_100 , V_17 ) ;
F_9 ( V_50 -> V_59 , V_63 ) ;
F_11 ( V_100 , 0 , V_118 ) ;
V_50 -> V_64 = 1 ;
V_50 -> V_51 = V_17 ;
}
F_60 ( & V_47 -> V_83 ) ;
F_31 ( V_47 -> V_27 -> V_28 . V_29 ,
L_15 ,
V_30 , V_50 , V_50 ? & V_50 -> V_52 : 0 ) ;
return V_50 ? & V_50 -> V_52 : NULL ;
}
static struct V_98 *
F_81 ( struct V_104 * V_21 , T_2 V_63 , int V_15 ,
T_3 V_17 , unsigned long V_3 )
{
struct V_20 * V_47 = F_70 ( V_21 ) ;
struct V_1 * V_50 , * V_100 ;
int V_55 ;
F_31 ( V_47 -> V_27 -> V_28 . V_29 ,
L_16 ,
V_30 , V_63 , V_17 , V_3 ) ;
if ( F_79 ( V_17 < V_119 ) )
return NULL ;
F_6 ( V_17 > V_120 ) ;
F_59 ( & V_47 -> V_83 ) ;
V_55 = F_10 ( V_17 ) ;
V_50 = F_62 ( V_47 , V_55 , 1 ) ;
if ( V_50 ) {
V_50 -> type = V_34 ;
V_50 -> V_52 . V_3 = V_3 ;
V_100 = V_50 -> V_59 ;
F_1 ( V_100 , V_3 ) ;
F_4 ( V_100 , V_17 ) ;
F_9 ( V_50 -> V_59 , V_63 ) ;
F_8 ( V_100 , V_15 ) ;
V_50 -> V_64 = 1 ;
V_50 -> V_51 = V_17 ;
}
F_60 ( & V_47 -> V_83 ) ;
F_31 ( V_47 -> V_27 -> V_28 . V_29 ,
L_17 ,
V_30 , V_50 , & V_50 -> V_52 ) ;
return V_50 ? & V_50 -> V_52 : NULL ;
}
static struct V_98 *
F_82 ( struct V_104 * V_21 , T_2 V_63 , T_2 * V_118 ,
unsigned int V_46 , T_3 V_17 , unsigned long V_3 )
{
struct V_20 * V_47 = F_70 ( V_21 ) ;
struct V_1 * V_50 , * V_100 ;
int V_55 ;
if ( F_79 ( V_17 < V_119 ) )
return NULL ;
F_6 ( V_17 > V_120 ) ;
F_31 ( V_47 -> V_27 -> V_28 . V_29 ,
L_18 ,
V_30 , V_46 , V_17 , V_63 , V_3 ) ;
F_59 ( & V_47 -> V_83 ) ;
V_55 = F_42 ( V_17 , V_46 ) ;
V_50 = F_62 ( V_47 , V_55 , 1 ) ;
if ( V_50 ) {
V_50 -> type = V_19 ;
V_50 -> V_52 . V_3 = V_3 ;
V_100 = V_50 -> V_59 ;
F_1 ( V_100 , V_3 ) ;
F_4 ( V_100 , V_17 ) ;
F_9 ( V_50 -> V_59 , V_63 ) ;
V_50 -> V_64 = V_46 ;
V_50 -> V_51 = V_17 ;
while ( V_46 -- )
F_11 ( V_100 , V_46 , V_118 [ V_46 ] ) ;
}
F_60 ( & V_47 -> V_83 ) ;
F_31 ( V_47 -> V_27 -> V_28 . V_29 ,
L_17 ,
V_30 , V_50 , & V_50 -> V_52 ) ;
return V_50 ? & V_50 -> V_52 : NULL ;
}
static void F_83 ( struct V_104 * V_21 )
{
struct V_20 * V_47 = F_70 ( V_21 ) ;
struct V_1 * V_72 , * V_73 ;
int V_121 = 0 ;
F_58 ( V_47 ) ;
F_59 ( & V_47 -> V_83 ) ;
F_50 (iter, _iter, &mv_chan->chain,
chain_node) {
V_121 ++ ;
F_52 ( & V_72 -> V_32 ) ;
}
F_50 (iter, _iter, &mv_chan->completed_slots,
completed_node) {
V_121 ++ ;
F_52 ( & V_72 -> V_74 ) ;
}
F_84 (
iter, _iter, &mv_chan->all_slots, slot_node) {
F_52 ( & V_72 -> V_91 ) ;
F_85 ( V_72 ) ;
V_47 -> V_111 -- ;
}
V_47 -> V_89 = NULL ;
F_31 ( V_47 -> V_27 -> V_28 . V_29 , L_19 ,
V_30 , V_47 -> V_111 ) ;
F_60 ( & V_47 -> V_83 ) ;
if ( V_121 )
F_86 ( V_47 -> V_27 -> V_28 . V_29 ,
L_20 , V_121 ) ;
}
static enum V_122 F_87 ( struct V_104 * V_21 ,
T_4 V_56 ,
struct V_123 * V_124 )
{
struct V_20 * V_47 = F_70 ( V_21 ) ;
enum V_122 V_125 ;
V_125 = F_88 ( V_21 , V_56 , V_124 ) ;
if ( V_125 == V_126 ) {
F_49 ( V_47 ) ;
return V_125 ;
}
F_58 ( V_47 ) ;
return F_88 ( V_21 , V_56 , V_124 ) ;
}
static void F_89 ( struct V_20 * V_21 )
{
T_1 V_14 ;
V_14 = F_13 ( F_36 ( V_21 ) ) ;
F_37 ( V_42 , V_21 -> V_27 -> V_28 . V_29 ,
L_21 , V_14 ) ;
V_14 = F_13 ( F_40 ( V_21 ) ) ;
F_37 ( V_42 , V_21 -> V_27 -> V_28 . V_29 ,
L_22 , V_14 ) ;
V_14 = F_13 ( F_28 ( V_21 ) ) ;
F_37 ( V_42 , V_21 -> V_27 -> V_28 . V_29 ,
L_23 , V_14 ) ;
V_14 = F_13 ( F_26 ( V_21 ) ) ;
F_37 ( V_42 , V_21 -> V_27 -> V_28 . V_29 ,
L_24 , V_14 ) ;
V_14 = F_13 ( F_90 ( V_21 ) ) ;
F_37 ( V_42 , V_21 -> V_27 -> V_28 . V_29 ,
L_25 , V_14 ) ;
V_14 = F_13 ( F_91 ( V_21 ) ) ;
F_37 ( V_42 , V_21 -> V_27 -> V_28 . V_29 ,
L_26 , V_14 ) ;
}
static void F_92 ( struct V_20 * V_21 ,
T_1 V_26 )
{
if ( V_26 & ( 1 << 4 ) ) {
F_31 ( V_21 -> V_27 -> V_28 . V_29 ,
L_27 ) ;
return;
}
F_37 ( V_42 , V_21 -> V_27 -> V_28 . V_29 ,
L_28 ,
V_21 -> V_25 , V_26 ) ;
F_89 ( V_21 ) ;
F_38 () ;
}
static T_5 F_93 ( int V_127 , void * V_84 )
{
struct V_20 * V_21 = V_84 ;
T_1 V_26 = F_27 ( V_21 ) ;
F_31 ( V_21 -> V_27 -> V_28 . V_29 , L_29 , V_26 ) ;
if ( F_29 ( V_26 ) )
F_92 ( V_21 , V_26 ) ;
F_67 ( & V_21 -> V_97 ) ;
F_30 ( V_21 ) ;
return V_128 ;
}
static void F_45 ( struct V_104 * V_21 )
{
struct V_20 * V_47 = F_70 ( V_21 ) ;
if ( V_47 -> V_54 >= V_129 ) {
V_47 -> V_54 = 0 ;
F_39 ( V_47 ) ;
}
}
static int T_6 F_94 ( struct V_130 * V_27 )
{
int V_93 ;
void * V_118 , * V_63 ;
T_2 V_131 , V_132 ;
struct V_104 * V_104 ;
T_4 V_56 ;
struct V_98 * V_99 ;
int V_133 = 0 ;
struct V_20 * V_47 ;
V_118 = F_95 ( sizeof( V_134 ) * V_135 , V_112 ) ;
if ( ! V_118 )
return - V_117 ;
V_63 = F_74 ( sizeof( V_134 ) * V_135 , V_112 ) ;
if ( ! V_63 ) {
F_85 ( V_118 ) ;
return - V_117 ;
}
for ( V_93 = 0 ; V_93 < V_135 ; V_93 ++ )
( ( V_134 * ) V_118 ) [ V_93 ] = ( V_134 ) V_93 ;
V_104 = F_96 ( V_27 -> V_28 . V_136 . V_81 ,
struct V_104 ,
V_137 ) ;
if ( F_73 ( V_104 ) < 1 ) {
V_133 = - V_138 ;
goto V_139;
}
V_132 = F_97 ( V_104 -> V_27 -> V_29 , V_63 ,
V_135 , V_69 ) ;
V_131 = F_97 ( V_104 -> V_27 -> V_29 , V_118 ,
V_135 , V_71 ) ;
V_99 = F_78 ( V_104 , V_132 , V_131 ,
V_135 , 0 ) ;
V_56 = F_68 ( V_99 ) ;
F_45 ( V_104 ) ;
F_65 ( V_99 ) ;
F_98 ( 1 ) ;
if ( F_87 ( V_104 , V_56 , NULL ) !=
V_126 ) {
F_37 ( V_42 , V_104 -> V_27 -> V_29 ,
L_30 ) ;
V_133 = - V_138 ;
goto V_140;
}
V_47 = F_70 ( V_104 ) ;
F_99 ( & V_47 -> V_27 -> V_61 -> V_29 , V_132 ,
V_135 , V_69 ) ;
if ( memcmp ( V_118 , V_63 , V_135 ) ) {
F_37 ( V_42 , V_104 -> V_27 -> V_29 ,
L_31 ) ;
V_133 = - V_138 ;
goto V_140;
}
V_140:
F_83 ( V_104 ) ;
V_139:
F_85 ( V_118 ) ;
F_85 ( V_63 ) ;
return V_133 ;
}
static int T_6
F_100 ( struct V_130 * V_27 )
{
int V_93 , V_10 ;
struct V_141 * V_63 ;
struct V_141 * V_142 [ V_143 ] ;
T_2 V_144 [ V_143 ] ;
T_2 V_132 ;
struct V_98 * V_99 ;
struct V_104 * V_104 ;
T_4 V_56 ;
V_134 V_145 = 0 ;
T_1 V_146 ;
int V_133 = 0 ;
struct V_20 * V_47 ;
for ( V_10 = 0 ; V_10 < V_143 ; V_10 ++ ) {
V_142 [ V_10 ] = F_101 ( V_112 ) ;
if ( ! V_142 [ V_10 ] ) {
while ( V_10 -- )
F_102 ( V_142 [ V_10 ] ) ;
return - V_117 ;
}
}
V_63 = F_101 ( V_112 ) ;
if ( ! V_63 ) {
while ( V_10 -- )
F_102 ( V_142 [ V_10 ] ) ;
return - V_117 ;
}
for ( V_10 = 0 ; V_10 < V_143 ; V_10 ++ ) {
V_134 * V_147 = F_103 ( V_142 [ V_10 ] ) ;
for ( V_93 = 0 ; V_93 < V_148 ; V_93 ++ )
V_147 [ V_93 ] = ( 1 << V_10 ) ;
}
for ( V_10 = 0 ; V_10 < V_143 ; V_10 ++ )
V_145 ^= ( V_134 ) ( 1 << V_10 ) ;
V_146 = ( V_145 << 24 ) | ( V_145 << 16 ) |
( V_145 << 8 ) | V_145 ;
memset ( F_103 ( V_63 ) , 0 , V_148 ) ;
V_104 = F_96 ( V_27 -> V_28 . V_136 . V_81 ,
struct V_104 ,
V_137 ) ;
if ( F_73 ( V_104 ) < 1 ) {
V_133 = - V_138 ;
goto V_139;
}
V_132 = F_104 ( V_104 -> V_27 -> V_29 , V_63 , 0 , V_148 ,
V_69 ) ;
for ( V_93 = 0 ; V_93 < V_143 ; V_93 ++ )
V_144 [ V_93 ] = F_104 ( V_104 -> V_27 -> V_29 , V_142 [ V_93 ] ,
0 , V_148 , V_71 ) ;
V_99 = F_82 ( V_104 , V_132 , V_144 ,
V_143 , V_148 , 0 ) ;
V_56 = F_68 ( V_99 ) ;
F_45 ( V_104 ) ;
F_65 ( V_99 ) ;
F_98 ( 8 ) ;
if ( F_87 ( V_104 , V_56 , NULL ) !=
V_126 ) {
F_37 ( V_42 , V_104 -> V_27 -> V_29 ,
L_32 ) ;
V_133 = - V_138 ;
goto V_140;
}
V_47 = F_70 ( V_104 ) ;
F_99 ( & V_47 -> V_27 -> V_61 -> V_29 , V_132 ,
V_148 , V_69 ) ;
for ( V_93 = 0 ; V_93 < ( V_148 / sizeof( T_1 ) ) ; V_93 ++ ) {
T_1 * V_147 = F_103 ( V_63 ) ;
if ( V_147 [ V_93 ] != V_146 ) {
F_37 ( V_42 , V_104 -> V_27 -> V_29 ,
L_33
L_34 , V_93 ,
V_147 [ V_93 ] , V_146 ) ;
V_133 = - V_138 ;
goto V_140;
}
}
V_140:
F_83 ( V_104 ) ;
V_139:
V_10 = V_143 ;
while ( V_10 -- )
F_102 ( V_142 [ V_10 ] ) ;
F_102 ( V_63 ) ;
return V_133 ;
}
static int T_7 F_105 ( struct V_149 * V_29 )
{
struct V_130 * V_27 = F_106 ( V_29 ) ;
struct V_104 * V_21 , * V_150 ;
struct V_20 * V_47 ;
struct V_105 * V_106 = V_29 -> V_29 . V_107 ;
F_107 ( & V_27 -> V_28 ) ;
F_108 ( & V_29 -> V_29 , V_106 -> V_109 ,
V_27 -> V_114 , V_27 -> V_116 ) ;
F_50 (chan, _chan, &device->common.channels,
device_node) {
V_47 = F_70 ( V_21 ) ;
F_52 ( & V_21 -> V_137 ) ;
}
return 0 ;
}
static int T_6 F_109 ( struct V_149 * V_61 )
{
int V_125 = 0 ;
int V_127 ;
struct V_130 * V_151 ;
struct V_20 * V_47 ;
struct V_152 * V_153 ;
struct V_105 * V_106 = V_61 -> V_29 . V_107 ;
V_151 = F_110 ( & V_61 -> V_29 , sizeof( * V_151 ) , V_112 ) ;
if ( ! V_151 )
return - V_117 ;
V_153 = & V_151 -> V_28 ;
V_151 -> V_114 = F_111 ( & V_61 -> V_29 ,
V_106 -> V_109 ,
& V_151 -> V_116 ,
V_112 ) ;
if ( ! V_151 -> V_114 )
return - V_117 ;
V_151 -> V_154 = V_106 -> V_155 ;
V_153 -> V_156 = V_106 -> V_156 ;
V_151 -> V_61 = V_61 ;
F_112 ( V_61 , V_151 ) ;
V_151 -> V_157 = F_106 ( V_106 -> V_157 ) ;
F_77 ( & V_153 -> V_136 ) ;
V_153 -> V_158 = F_73 ;
V_153 -> V_159 = F_83 ;
V_153 -> V_160 = F_87 ;
V_153 -> V_161 = F_45 ;
V_153 -> V_29 = & V_61 -> V_29 ;
if ( F_113 ( V_39 , V_153 -> V_156 ) )
V_153 -> V_162 = F_78 ;
if ( F_113 ( V_34 , V_153 -> V_156 ) )
V_153 -> V_163 = F_81 ;
if ( F_113 ( V_19 , V_153 -> V_156 ) ) {
V_153 -> V_164 = 8 ;
V_153 -> V_165 = F_82 ;
}
V_47 = F_110 ( & V_61 -> V_29 , sizeof( * V_47 ) , V_112 ) ;
if ( ! V_47 ) {
V_125 = - V_117 ;
goto V_166;
}
V_47 -> V_27 = V_151 ;
V_47 -> V_25 = V_106 -> V_155 ;
V_47 -> V_167 = V_151 -> V_157 -> V_168 ;
if ( ! V_47 -> V_167 ) {
V_125 = - V_117 ;
goto V_166;
}
F_114 ( & V_47 -> V_97 , F_61 , ( unsigned long )
V_47 ) ;
F_32 ( V_47 ) ;
V_127 = F_115 ( V_61 , 0 ) ;
if ( V_127 < 0 ) {
V_125 = V_127 ;
goto V_166;
}
V_125 = F_116 ( & V_61 -> V_29 , V_127 ,
F_93 ,
0 , F_117 ( & V_61 -> V_29 ) , V_47 ) ;
if ( V_125 )
goto V_166;
F_25 ( V_47 ) ;
F_35 ( V_47 , V_39 ) ;
F_118 ( & V_47 -> V_83 ) ;
F_77 ( & V_47 -> V_79 ) ;
F_77 ( & V_47 -> V_75 ) ;
F_77 ( & V_47 -> V_90 ) ;
V_47 -> V_28 . V_27 = V_153 ;
F_119 ( & V_47 -> V_28 ) ;
F_54 ( & V_47 -> V_28 . V_137 , & V_153 -> V_136 ) ;
if ( F_113 ( V_39 , V_153 -> V_156 ) ) {
V_125 = F_94 ( V_151 ) ;
F_31 ( & V_61 -> V_29 , L_35 , V_125 ) ;
if ( V_125 )
goto V_166;
}
if ( F_113 ( V_19 , V_153 -> V_156 ) ) {
V_125 = F_100 ( V_151 ) ;
F_31 ( & V_61 -> V_29 , L_36 , V_125 ) ;
if ( V_125 )
goto V_166;
}
F_37 ( V_113 , & V_61 -> V_29 , L_37
L_38 ,
F_113 ( V_19 , V_153 -> V_156 ) ? L_39 : L_40 ,
F_113 ( V_34 , V_153 -> V_156 ) ? L_41 : L_40 ,
F_113 ( V_39 , V_153 -> V_156 ) ? L_42 : L_40 ,
F_113 ( V_169 , V_153 -> V_156 ) ? L_43 : L_40 ) ;
F_120 ( V_153 ) ;
goto V_139;
V_166:
F_108 ( & V_151 -> V_61 -> V_29 , V_106 -> V_109 ,
V_151 -> V_114 , V_151 -> V_116 ) ;
V_139:
return V_125 ;
}
static void
F_121 ( struct V_170 * V_171 ,
const struct V_172 * V_173 )
{
void T_8 * V_174 = V_171 -> V_168 ;
T_1 V_175 = 0 ;
int V_93 ;
for ( V_93 = 0 ; V_93 < 8 ; V_93 ++ ) {
F_122 ( 0 , V_174 + F_123 ( V_93 ) ) ;
F_122 ( 0 , V_174 + F_124 ( V_93 ) ) ;
if ( V_93 < 4 )
F_122 ( 0 , V_174 + F_125 ( V_93 ) ) ;
}
for ( V_93 = 0 ; V_93 < V_173 -> V_176 ; V_93 ++ ) {
const struct V_177 * V_178 = V_173 -> V_178 + V_93 ;
F_122 ( ( V_178 -> V_174 & 0xffff0000 ) |
( V_178 -> V_179 << 8 ) |
V_173 -> V_180 , V_174 + F_123 ( V_93 ) ) ;
F_122 ( ( V_178 -> V_181 - 1 ) & 0xffff0000 , V_174 + F_124 ( V_93 ) ) ;
V_175 |= ( 1 << V_93 ) ;
V_175 |= 3 << ( 16 + ( 2 * V_93 ) ) ;
}
F_122 ( V_175 , V_174 + F_126 ( 0 ) ) ;
F_122 ( V_175 , V_174 + F_126 ( 1 ) ) ;
}
static int F_127 ( struct V_149 * V_61 )
{
const struct V_172 * V_173 ;
struct V_170 * V_171 ;
struct V_182 * V_183 ;
F_37 ( V_184 , & V_61 -> V_29 , L_44 ) ;
V_171 = F_110 ( & V_61 -> V_29 , sizeof( * V_171 ) , V_112 ) ;
if ( ! V_171 )
return - V_117 ;
V_183 = F_128 ( V_61 , V_185 , 0 ) ;
if ( ! V_183 )
return - V_138 ;
V_171 -> V_168 = F_129 ( & V_61 -> V_29 , V_183 -> V_186 ,
F_130 ( V_183 ) ) ;
if ( ! V_171 -> V_168 )
return - V_95 ;
V_183 = F_128 ( V_61 , V_185 , 1 ) ;
if ( ! V_183 )
return - V_138 ;
V_171 -> V_187 = F_129 ( & V_61 -> V_29 , V_183 -> V_186 ,
F_130 ( V_183 ) ) ;
if ( ! V_171 -> V_187 )
return - V_95 ;
F_112 ( V_61 , V_171 ) ;
V_173 = F_131 () ;
if ( V_173 )
F_121 ( V_171 , V_173 ) ;
V_171 -> V_188 = F_132 ( & V_61 -> V_29 , NULL ) ;
if ( ! F_133 ( V_171 -> V_188 ) )
F_134 ( V_171 -> V_188 ) ;
return 0 ;
}
static int F_135 ( struct V_149 * V_61 )
{
struct V_170 * V_171 = F_106 ( V_61 ) ;
if ( ! F_133 ( V_171 -> V_188 ) ) {
F_136 ( V_171 -> V_188 ) ;
F_137 ( V_171 -> V_188 ) ;
}
return 0 ;
}
static int T_9 F_138 ( void )
{
int V_189 ;
V_189 = F_139 ( & V_190 ) ;
if ( ! V_189 ) {
V_189 = F_139 ( & V_191 ) ;
if ( V_189 )
F_140 ( & V_190 ) ;
}
return V_189 ;
}
