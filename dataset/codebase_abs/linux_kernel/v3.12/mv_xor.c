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
return V_5 -> V_11 [ F_4 ( V_10 ) ] ;
}
static void F_5 ( struct V_1 * V_2 ,
T_1 V_12 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_12 = V_12 ;
}
static void F_6 ( struct V_1 * V_2 ,
T_1 V_13 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_7 ( V_5 -> V_7 ) ;
V_5 -> V_7 = V_13 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_7 = 0 ;
}
static void F_9 ( struct V_1 * V_2 ,
T_2 V_14 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_9 = V_14 ;
}
static int F_10 ( T_3 V_15 )
{
return 1 ;
}
static void F_11 ( struct V_1 * V_2 ,
int V_16 , T_2 V_14 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_11 [ F_4 ( V_16 ) ] = V_14 ;
if ( V_2 -> type == V_17 )
V_5 -> V_8 |= ( 1 << V_16 ) ;
}
static T_1 F_12 ( struct V_18 * V_19 )
{
return F_13 ( F_14 ( V_19 ) ) ;
}
static void F_15 ( struct V_18 * V_19 ,
T_1 V_13 )
{
F_16 ( V_13 , F_17 ( V_19 ) ) ;
}
static void F_18 ( struct V_18 * V_19 )
{
T_1 V_20 = F_13 ( F_19 ( V_19 ) ) ;
V_20 |= V_21 << ( V_19 -> V_22 * 16 ) ;
F_16 ( V_20 , F_19 ( V_19 ) ) ;
}
static T_1 F_20 ( struct V_18 * V_19 )
{
T_1 V_23 = F_13 ( F_21 ( V_19 ) ) ;
V_23 = ( V_23 >> ( V_19 -> V_22 * 16 ) ) & 0xFFFF ;
return V_23 ;
}
static int F_22 ( T_1 V_23 )
{
if ( V_23 & ( ( 1 << 4 ) | ( 1 << 5 ) | ( 1 << 6 ) | ( 1 << 7 ) | ( 1 << 8 ) | ( 1 << 9 ) ) )
return 1 ;
return 0 ;
}
static void F_23 ( struct V_18 * V_19 )
{
T_1 V_20 = ~ ( 1 << ( V_19 -> V_22 * 16 ) ) ;
F_24 ( F_25 ( V_19 ) , L_1 , V_24 , V_20 ) ;
F_16 ( V_20 , F_21 ( V_19 ) ) ;
}
static void F_26 ( struct V_18 * V_19 )
{
T_1 V_20 = 0xFFFF0000 >> ( V_19 -> V_22 * 16 ) ;
F_16 ( V_20 , F_21 ( V_19 ) ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_1 * V_25 = F_28 (
V_2 -> V_26 . V_27 , struct V_1 , V_26 ) ;
if ( V_25 -> type != V_2 -> type )
return 0 ;
return 1 ;
}
static void F_29 ( struct V_18 * V_19 ,
enum V_28 type )
{
T_1 V_29 ;
T_1 V_30 = F_13 ( F_30 ( V_19 ) ) ;
switch ( type ) {
case V_17 :
V_29 = V_31 ;
break;
case V_32 :
V_29 = V_33 ;
break;
default:
F_31 ( F_25 ( V_19 ) ,
L_2 ,
type ) ;
F_32 () ;
return;
}
V_30 &= ~ 0x7 ;
V_30 |= V_29 ;
#if F_33 ( V_34 )
V_30 |= V_35 ;
#else
V_30 &= ~ V_35 ;
#endif
F_16 ( V_30 , F_30 ( V_19 ) ) ;
V_19 -> V_36 = type ;
}
static void F_34 ( struct V_18 * V_19 )
{
T_1 V_37 ;
F_24 ( F_25 ( V_19 ) , L_3 ) ;
V_37 = F_13 ( F_35 ( V_19 ) ) ;
V_37 |= 0x1 ;
F_16 ( V_37 , F_35 ( V_19 ) ) ;
}
static char F_36 ( struct V_18 * V_19 )
{
T_1 V_38 = F_13 ( F_35 ( V_19 ) ) ;
V_38 = ( V_38 >> 4 ) & 0x3 ;
return ( V_38 == 1 ) ? 1 : 0 ;
}
static int F_37 ( T_3 V_15 , int V_39 )
{
return 1 ;
}
static void F_38 ( struct V_18 * V_40 ,
struct V_1 * V_41 )
{
F_24 ( F_25 ( V_40 ) , L_4 ,
V_24 , __LINE__ , V_41 ) ;
V_41 -> V_42 = 0 ;
}
static void F_39 ( struct V_18 * V_40 ,
struct V_1 * V_43 )
{
F_24 ( F_25 ( V_40 ) , L_5 ,
V_24 , __LINE__ , V_43 ) ;
if ( V_43 -> type != V_40 -> V_36 )
F_29 ( V_40 , V_43 -> type ) ;
F_15 ( V_40 , V_43 -> V_44 . V_45 ) ;
V_40 -> V_46 += V_43 -> V_47 ;
F_40 ( & V_40 -> V_48 ) ;
}
static T_4
F_41 ( struct V_1 * V_2 ,
struct V_18 * V_40 , T_4 V_49 )
{
F_7 ( V_2 -> V_44 . V_49 < 0 ) ;
if ( V_2 -> V_44 . V_49 > 0 ) {
V_49 = V_2 -> V_44 . V_49 ;
if ( V_2 -> V_44 . V_50 )
V_2 -> V_44 . V_50 (
V_2 -> V_44 . V_51 ) ;
if ( V_2 -> V_52 && V_2 -> V_53 ) {
struct V_1 * V_54 = V_2 -> V_52 ;
struct V_55 * V_56 = F_25 ( V_40 ) ;
T_1 V_15 = V_54 -> V_53 ;
enum V_57 V_3 = V_2 -> V_44 . V_3 ;
T_1 V_39 ;
T_2 V_14 ;
T_2 V_58 ;
V_39 = V_54 -> V_59 ;
V_58 = F_2 ( V_54 ) ;
if ( ! ( V_3 & V_60 ) ) {
enum V_61 V_62 ;
if ( V_39 > 1 )
V_62 = V_63 ;
else
V_62 = V_64 ;
F_42 ( V_56 , V_58 , V_15 , V_62 ) ;
}
if ( ! ( V_3 & V_65 ) ) {
while ( V_39 -- ) {
V_14 = F_3 ( V_54 ,
V_39 ) ;
if ( V_14 == V_58 )
continue;
F_42 ( V_56 , V_14 , V_15 ,
V_66 ) ;
}
}
V_2 -> V_52 = NULL ;
}
}
F_43 ( & V_2 -> V_44 ) ;
return V_49 ;
}
static int
F_44 ( struct V_18 * V_40 )
{
struct V_1 * V_67 , * V_68 ;
F_24 ( F_25 ( V_40 ) , L_6 , V_24 , __LINE__ ) ;
F_45 (iter, _iter, &mv_chan->completed_slots,
completed_node) {
if ( F_46 ( & V_67 -> V_44 ) ) {
F_47 ( & V_67 -> V_69 ) ;
F_38 ( V_40 , V_67 ) ;
}
}
return 0 ;
}
static int
F_48 ( struct V_1 * V_2 ,
struct V_18 * V_40 )
{
F_24 ( F_25 ( V_40 ) , L_7 ,
V_24 , __LINE__ , V_2 , V_2 -> V_44 . V_3 ) ;
F_47 ( & V_2 -> V_26 ) ;
if ( ! F_46 ( & V_2 -> V_44 ) ) {
F_49 ( & V_2 -> V_69 , & V_40 -> V_70 ) ;
return 0 ;
}
F_38 ( V_40 , V_2 ) ;
return 0 ;
}
static void F_50 ( struct V_18 * V_40 )
{
struct V_1 * V_67 , * V_68 ;
T_4 V_49 = 0 ;
int V_71 = F_36 ( V_40 ) ;
T_1 V_72 = F_12 ( V_40 ) ;
int V_73 = 0 ;
F_24 ( F_25 ( V_40 ) , L_6 , V_24 , __LINE__ ) ;
F_24 ( F_25 ( V_40 ) , L_8 , V_72 ) ;
F_44 ( V_40 ) ;
F_45 (iter, _iter, &mv_chan->chain,
chain_node) {
F_51 ( V_68 ) ;
F_51 ( & V_68 -> V_44 ) ;
if ( V_73 )
break;
if ( V_67 -> V_44 . V_45 == V_72 ) {
V_73 = 1 ;
if ( V_71 )
break;
}
V_49 = F_41 ( V_67 , V_40 , V_49 ) ;
if ( F_48 ( V_67 , V_40 ) )
break;
}
if ( ( V_71 == 0 ) && ! F_52 ( & V_40 -> V_74 ) ) {
struct V_1 * V_75 ;
V_75 = F_28 ( V_40 -> V_74 . V_76 ,
struct V_1 ,
V_26 ) ;
F_39 ( V_40 , V_75 ) ;
}
if ( V_49 > 0 )
V_40 -> V_48 . V_77 = V_49 ;
}
static void
F_53 ( struct V_18 * V_40 )
{
F_54 ( & V_40 -> V_78 ) ;
F_50 ( V_40 ) ;
F_55 ( & V_40 -> V_78 ) ;
}
static void F_56 ( unsigned long V_79 )
{
struct V_18 * V_19 = (struct V_18 * ) V_79 ;
F_53 ( V_19 ) ;
}
static struct V_1 *
F_57 ( struct V_18 * V_40 , int V_80 ,
int V_42 )
{
struct V_1 * V_67 , * V_68 , * V_81 = NULL ;
F_58 ( V_74 ) ;
int V_82 , V_83 = 0 ;
V_83:
V_82 = 0 ;
if ( V_83 == 0 )
V_67 = V_40 -> V_84 ;
else
V_67 = F_28 ( & V_40 -> V_85 ,
struct V_1 ,
V_86 ) ;
F_59 (
iter, _iter, &mv_chan->all_slots, slot_node) {
F_51 ( V_68 ) ;
F_51 ( & V_68 -> V_44 ) ;
if ( V_67 -> V_42 ) {
if ( V_83 )
break;
V_82 = 0 ;
continue;
}
if ( ! V_82 ++ )
V_81 = V_67 ;
if ( V_82 == V_80 ) {
struct V_1 * V_87 = NULL ;
struct V_1 * V_84 = NULL ;
V_67 = V_81 ;
while ( V_80 ) {
int V_88 ;
F_60 ( & V_67 -> V_44 ) ;
F_49 ( & V_67 -> V_26 , & V_74 ) ;
V_87 = V_67 ;
V_67 -> V_44 . V_49 = 0 ;
V_67 -> V_47 = V_80 ;
V_67 -> V_89 = NULL ;
for ( V_88 = 0 ; V_88 < V_42 ; V_88 ++ ) {
V_67 -> V_42 = V_42 - V_88 ;
V_84 = V_67 ;
V_67 = F_28 ( V_67 -> V_86 . V_76 ,
struct V_1 ,
V_86 ) ;
}
V_80 -= V_42 ;
}
V_87 -> V_52 = V_81 ;
V_87 -> V_44 . V_49 = - V_90 ;
F_61 ( & V_74 , & V_87 -> V_91 ) ;
V_40 -> V_84 = V_84 ;
F_8 ( V_81 ) ;
F_8 ( V_87 ) ;
return V_87 ;
}
}
if ( ! V_83 ++ )
goto V_83;
F_62 ( & V_40 -> V_92 ) ;
return NULL ;
}
static T_4
F_63 ( struct V_93 * V_94 )
{
struct V_1 * V_43 = F_64 ( V_94 ) ;
struct V_18 * V_40 = F_65 ( V_94 -> V_19 ) ;
struct V_1 * V_95 , * V_96 ;
T_4 V_49 ;
int V_97 = 1 ;
F_24 ( F_25 ( V_40 ) ,
L_9 ,
V_24 , V_43 , & V_43 -> V_44 ) ;
V_95 = V_43 -> V_52 ;
F_54 ( & V_40 -> V_78 ) ;
V_49 = F_66 ( V_94 ) ;
if ( F_52 ( & V_40 -> V_74 ) )
F_67 ( & V_43 -> V_91 , & V_40 -> V_74 ) ;
else {
V_97 = 0 ;
V_96 = F_28 ( V_40 -> V_74 . V_27 ,
struct V_1 ,
V_26 ) ;
F_67 ( & V_95 -> V_91 ,
& V_96 -> V_26 ) ;
if ( ! F_27 ( V_95 ) )
goto V_98;
F_24 ( F_25 ( V_40 ) , L_10 ,
V_96 -> V_44 . V_45 ) ;
F_6 ( V_96 , V_95 -> V_44 . V_45 ) ;
if ( ! F_36 ( V_40 ) ) {
T_1 V_72 = F_12 ( V_40 ) ;
if ( V_72 == V_96 -> V_44 . V_45 )
V_97 = 1 ;
}
}
if ( V_97 )
F_39 ( V_40 , V_95 ) ;
V_98:
F_55 ( & V_40 -> V_78 ) ;
return V_49 ;
}
static int F_68 ( struct V_99 * V_19 )
{
char * V_5 ;
int V_22 ;
struct V_18 * V_40 = F_65 ( V_19 ) ;
struct V_1 * V_41 = NULL ;
int V_100 = V_101 / V_102 ;
V_22 = V_40 -> V_103 ;
while ( V_22 < V_100 ) {
V_41 = F_69 ( sizeof( * V_41 ) , V_104 ) ;
if ( ! V_41 ) {
F_70 ( V_105 L_11
L_12 , V_22 ) ;
break;
}
V_5 = ( char * ) V_40 -> V_106 ;
V_41 -> V_5 = ( void * ) & V_5 [ V_22 * V_102 ] ;
F_71 ( & V_41 -> V_44 , V_19 ) ;
V_41 -> V_44 . V_107 = F_63 ;
F_72 ( & V_41 -> V_26 ) ;
F_72 ( & V_41 -> V_86 ) ;
F_72 ( & V_41 -> V_91 ) ;
V_5 = ( char * ) V_40 -> V_108 ;
V_41 -> V_44 . V_45 =
( T_2 ) & V_5 [ V_22 * V_102 ] ;
V_41 -> V_22 = V_22 ++ ;
F_54 ( & V_40 -> V_78 ) ;
V_40 -> V_103 = V_22 ;
F_49 ( & V_41 -> V_86 , & V_40 -> V_85 ) ;
F_55 ( & V_40 -> V_78 ) ;
}
if ( V_40 -> V_103 && ! V_40 -> V_84 )
V_40 -> V_84 = F_28 ( V_40 -> V_85 . V_76 ,
struct V_1 ,
V_86 ) ;
F_24 ( F_25 ( V_40 ) ,
L_13 ,
V_40 -> V_103 , V_40 -> V_84 ) ;
return V_40 -> V_103 ? : - V_109 ;
}
static struct V_93 *
F_73 ( struct V_99 * V_19 , T_2 V_58 , T_2 V_110 ,
T_3 V_15 , unsigned long V_3 )
{
struct V_18 * V_40 = F_65 ( V_19 ) ;
struct V_1 * V_43 , * V_95 ;
int V_47 ;
F_24 ( F_25 ( V_40 ) ,
L_14 ,
V_24 , V_58 , V_110 , V_15 , V_3 ) ;
if ( F_74 ( V_15 < V_111 ) )
return NULL ;
F_7 ( V_15 > V_112 ) ;
F_54 ( & V_40 -> V_78 ) ;
V_47 = F_75 ( V_15 ) ;
V_43 = F_57 ( V_40 , V_47 , 1 ) ;
if ( V_43 ) {
V_43 -> type = V_32 ;
V_43 -> V_44 . V_3 = V_3 ;
V_95 = V_43 -> V_52 ;
F_1 ( V_95 , V_3 ) ;
F_5 ( V_95 , V_15 ) ;
F_9 ( V_43 -> V_52 , V_58 ) ;
F_11 ( V_95 , 0 , V_110 ) ;
V_43 -> V_59 = 1 ;
V_43 -> V_53 = V_15 ;
}
F_55 ( & V_40 -> V_78 ) ;
F_24 ( F_25 ( V_40 ) ,
L_15 ,
V_24 , V_43 , V_43 ? & V_43 -> V_44 : NULL ) ;
return V_43 ? & V_43 -> V_44 : NULL ;
}
static struct V_93 *
F_76 ( struct V_99 * V_19 , T_2 V_58 , T_2 * V_110 ,
unsigned int V_39 , T_3 V_15 , unsigned long V_3 )
{
struct V_18 * V_40 = F_65 ( V_19 ) ;
struct V_1 * V_43 , * V_95 ;
int V_47 ;
if ( F_74 ( V_15 < V_111 ) )
return NULL ;
F_7 ( V_15 > V_112 ) ;
F_24 ( F_25 ( V_40 ) ,
L_16 ,
V_24 , V_39 , V_15 , V_58 , V_3 ) ;
F_54 ( & V_40 -> V_78 ) ;
V_47 = F_37 ( V_15 , V_39 ) ;
V_43 = F_57 ( V_40 , V_47 , 1 ) ;
if ( V_43 ) {
V_43 -> type = V_17 ;
V_43 -> V_44 . V_3 = V_3 ;
V_95 = V_43 -> V_52 ;
F_1 ( V_95 , V_3 ) ;
F_5 ( V_95 , V_15 ) ;
F_9 ( V_43 -> V_52 , V_58 ) ;
V_43 -> V_59 = V_39 ;
V_43 -> V_53 = V_15 ;
while ( V_39 -- )
F_11 ( V_95 , V_39 , V_110 [ V_39 ] ) ;
}
F_55 ( & V_40 -> V_78 ) ;
F_24 ( F_25 ( V_40 ) ,
L_17 ,
V_24 , V_43 , & V_43 -> V_44 ) ;
return V_43 ? & V_43 -> V_44 : NULL ;
}
static void F_77 ( struct V_99 * V_19 )
{
struct V_18 * V_40 = F_65 ( V_19 ) ;
struct V_1 * V_67 , * V_68 ;
int V_113 = 0 ;
F_53 ( V_40 ) ;
F_54 ( & V_40 -> V_78 ) ;
F_45 (iter, _iter, &mv_chan->chain,
chain_node) {
V_113 ++ ;
F_47 ( & V_67 -> V_26 ) ;
}
F_45 (iter, _iter, &mv_chan->completed_slots,
completed_node) {
V_113 ++ ;
F_47 ( & V_67 -> V_69 ) ;
}
F_78 (
iter, _iter, &mv_chan->all_slots, slot_node) {
F_47 ( & V_67 -> V_86 ) ;
F_79 ( V_67 ) ;
V_40 -> V_103 -- ;
}
V_40 -> V_84 = NULL ;
F_24 ( F_25 ( V_40 ) , L_18 ,
V_24 , V_40 -> V_103 ) ;
F_55 ( & V_40 -> V_78 ) ;
if ( V_113 )
F_31 ( F_25 ( V_40 ) ,
L_19 , V_113 ) ;
}
static enum V_114 F_80 ( struct V_99 * V_19 ,
T_4 V_49 ,
struct V_115 * V_116 )
{
struct V_18 * V_40 = F_65 ( V_19 ) ;
enum V_114 V_117 ;
V_117 = F_81 ( V_19 , V_49 , V_116 ) ;
if ( V_117 == V_118 ) {
F_44 ( V_40 ) ;
return V_117 ;
}
F_53 ( V_40 ) ;
return F_81 ( V_19 , V_49 , V_116 ) ;
}
static void F_82 ( struct V_18 * V_19 )
{
T_1 V_20 ;
V_20 = F_13 ( F_30 ( V_19 ) ) ;
F_31 ( F_25 ( V_19 ) , L_20 , V_20 ) ;
V_20 = F_13 ( F_35 ( V_19 ) ) ;
F_31 ( F_25 ( V_19 ) , L_21 , V_20 ) ;
V_20 = F_13 ( F_21 ( V_19 ) ) ;
F_31 ( F_25 ( V_19 ) , L_22 , V_20 ) ;
V_20 = F_13 ( F_19 ( V_19 ) ) ;
F_31 ( F_25 ( V_19 ) , L_23 , V_20 ) ;
V_20 = F_13 ( F_83 ( V_19 ) ) ;
F_31 ( F_25 ( V_19 ) , L_24 , V_20 ) ;
V_20 = F_13 ( F_84 ( V_19 ) ) ;
F_31 ( F_25 ( V_19 ) , L_25 , V_20 ) ;
}
static void F_85 ( struct V_18 * V_19 ,
T_1 V_23 )
{
if ( V_23 & ( 1 << 4 ) ) {
F_24 ( F_25 ( V_19 ) ,
L_26 ) ;
return;
}
F_31 ( F_25 ( V_19 ) ,
L_27 ,
V_19 -> V_22 , V_23 ) ;
F_82 ( V_19 ) ;
F_32 () ;
}
static T_5 F_86 ( int V_119 , void * V_79 )
{
struct V_18 * V_19 = V_79 ;
T_1 V_23 = F_20 ( V_19 ) ;
F_24 ( F_25 ( V_19 ) , L_28 , V_23 ) ;
if ( F_22 ( V_23 ) )
F_85 ( V_19 , V_23 ) ;
F_62 ( & V_19 -> V_92 ) ;
F_23 ( V_19 ) ;
return V_120 ;
}
static void F_40 ( struct V_99 * V_19 )
{
struct V_18 * V_40 = F_65 ( V_19 ) ;
if ( V_40 -> V_46 >= V_121 ) {
V_40 -> V_46 = 0 ;
F_34 ( V_40 ) ;
}
}
static int F_87 ( struct V_18 * V_40 )
{
int V_88 ;
void * V_110 , * V_58 ;
T_2 V_122 , V_123 ;
struct V_99 * V_99 ;
T_4 V_49 ;
struct V_93 * V_94 ;
int V_124 = 0 ;
V_110 = F_88 ( sizeof( V_125 ) * V_126 , V_104 ) ;
if ( ! V_110 )
return - V_109 ;
V_58 = F_69 ( sizeof( V_125 ) * V_126 , V_104 ) ;
if ( ! V_58 ) {
F_79 ( V_110 ) ;
return - V_109 ;
}
for ( V_88 = 0 ; V_88 < V_126 ; V_88 ++ )
( ( V_125 * ) V_110 ) [ V_88 ] = ( V_125 ) V_88 ;
V_99 = & V_40 -> V_48 ;
if ( F_68 ( V_99 ) < 1 ) {
V_124 = - V_127 ;
goto V_128;
}
V_123 = F_89 ( V_99 -> V_55 -> V_56 , V_58 ,
V_126 , V_64 ) ;
V_122 = F_89 ( V_99 -> V_55 -> V_56 , V_110 ,
V_126 , V_66 ) ;
V_94 = F_73 ( V_99 , V_123 , V_122 ,
V_126 , 0 ) ;
V_49 = F_63 ( V_94 ) ;
F_40 ( V_99 ) ;
F_60 ( V_94 ) ;
F_90 ( 1 ) ;
if ( F_80 ( V_99 , V_49 , NULL ) !=
V_118 ) {
F_31 ( V_99 -> V_55 -> V_56 ,
L_29 ) ;
V_124 = - V_127 ;
goto V_129;
}
F_91 ( V_99 -> V_55 -> V_56 , V_123 ,
V_126 , V_64 ) ;
if ( memcmp ( V_110 , V_58 , V_126 ) ) {
F_31 ( V_99 -> V_55 -> V_56 ,
L_30 ) ;
V_124 = - V_127 ;
goto V_129;
}
V_129:
F_77 ( V_99 ) ;
V_128:
F_79 ( V_110 ) ;
F_79 ( V_58 ) ;
return V_124 ;
}
static int
F_92 ( struct V_18 * V_40 )
{
int V_88 , V_10 ;
struct V_130 * V_58 ;
struct V_130 * V_131 [ V_132 ] ;
T_2 V_133 [ V_132 ] ;
T_2 V_123 ;
struct V_93 * V_94 ;
struct V_99 * V_99 ;
T_4 V_49 ;
V_125 V_134 = 0 ;
T_1 V_135 ;
int V_124 = 0 ;
for ( V_10 = 0 ; V_10 < V_132 ; V_10 ++ ) {
V_131 [ V_10 ] = F_93 ( V_104 ) ;
if ( ! V_131 [ V_10 ] ) {
while ( V_10 -- )
F_94 ( V_131 [ V_10 ] ) ;
return - V_109 ;
}
}
V_58 = F_93 ( V_104 ) ;
if ( ! V_58 ) {
while ( V_10 -- )
F_94 ( V_131 [ V_10 ] ) ;
return - V_109 ;
}
for ( V_10 = 0 ; V_10 < V_132 ; V_10 ++ ) {
V_125 * V_136 = F_95 ( V_131 [ V_10 ] ) ;
for ( V_88 = 0 ; V_88 < V_137 ; V_88 ++ )
V_136 [ V_88 ] = ( 1 << V_10 ) ;
}
for ( V_10 = 0 ; V_10 < V_132 ; V_10 ++ )
V_134 ^= ( V_125 ) ( 1 << V_10 ) ;
V_135 = ( V_134 << 24 ) | ( V_134 << 16 ) |
( V_134 << 8 ) | V_134 ;
memset ( F_95 ( V_58 ) , 0 , V_137 ) ;
V_99 = & V_40 -> V_48 ;
if ( F_68 ( V_99 ) < 1 ) {
V_124 = - V_127 ;
goto V_128;
}
V_123 = F_96 ( V_99 -> V_55 -> V_56 , V_58 , 0 , V_137 ,
V_64 ) ;
for ( V_88 = 0 ; V_88 < V_132 ; V_88 ++ )
V_133 [ V_88 ] = F_96 ( V_99 -> V_55 -> V_56 , V_131 [ V_88 ] ,
0 , V_137 , V_66 ) ;
V_94 = F_76 ( V_99 , V_123 , V_133 ,
V_132 , V_137 , 0 ) ;
V_49 = F_63 ( V_94 ) ;
F_40 ( V_99 ) ;
F_60 ( V_94 ) ;
F_90 ( 8 ) ;
if ( F_80 ( V_99 , V_49 , NULL ) !=
V_118 ) {
F_31 ( V_99 -> V_55 -> V_56 ,
L_31 ) ;
V_124 = - V_127 ;
goto V_129;
}
F_91 ( V_99 -> V_55 -> V_56 , V_123 ,
V_137 , V_64 ) ;
for ( V_88 = 0 ; V_88 < ( V_137 / sizeof( T_1 ) ) ; V_88 ++ ) {
T_1 * V_136 = F_95 ( V_58 ) ;
if ( V_136 [ V_88 ] != V_135 ) {
F_31 ( V_99 -> V_55 -> V_56 ,
L_32 ,
V_88 , V_136 [ V_88 ] , V_135 ) ;
V_124 = - V_127 ;
goto V_129;
}
}
V_129:
F_77 ( V_99 ) ;
V_128:
V_10 = V_132 ;
while ( V_10 -- )
F_94 ( V_131 [ V_10 ] ) ;
F_94 ( V_58 ) ;
return V_124 ;
}
static int
F_97 ( struct V_99 * V_19 , enum V_138 V_139 ,
unsigned long V_140 )
{
return - V_141 ;
}
static int F_98 ( struct V_18 * V_40 )
{
struct V_99 * V_19 , * V_142 ;
struct V_55 * V_56 = V_40 -> V_143 . V_56 ;
F_99 ( & V_40 -> V_143 ) ;
F_100 ( V_56 , V_101 ,
V_40 -> V_106 , V_40 -> V_108 ) ;
F_45 (chan, _chan, &mv_chan->dmadev.channels,
device_node) {
F_47 ( & V_19 -> V_144 ) ;
}
F_101 ( V_40 -> V_119 , V_40 ) ;
return 0 ;
}
static struct V_18 *
F_102 ( struct V_145 * V_146 ,
struct V_147 * V_148 ,
int V_22 , T_6 V_149 , int V_119 )
{
int V_117 = 0 ;
struct V_18 * V_40 ;
struct V_150 * V_151 ;
V_40 = F_103 ( & V_148 -> V_56 , sizeof( * V_40 ) , V_104 ) ;
if ( ! V_40 )
return F_104 ( - V_109 ) ;
V_40 -> V_22 = V_22 ;
V_40 -> V_119 = V_119 ;
V_151 = & V_40 -> V_143 ;
V_40 -> V_106 =
F_105 ( & V_148 -> V_56 , V_101 ,
& V_40 -> V_108 , V_104 ) ;
if ( ! V_40 -> V_106 )
return F_104 ( - V_109 ) ;
V_151 -> V_149 = V_149 ;
F_72 ( & V_151 -> V_152 ) ;
V_151 -> V_153 = F_68 ;
V_151 -> V_154 = F_77 ;
V_151 -> V_155 = F_80 ;
V_151 -> V_156 = F_40 ;
V_151 -> V_157 = F_97 ;
V_151 -> V_56 = & V_148 -> V_56 ;
if ( F_106 ( V_32 , V_151 -> V_149 ) )
V_151 -> V_158 = F_73 ;
if ( F_106 ( V_17 , V_151 -> V_149 ) ) {
V_151 -> V_159 = 8 ;
V_151 -> V_160 = F_76 ;
}
V_40 -> V_161 = V_146 -> V_162 ;
if ( ! V_40 -> V_161 ) {
V_117 = - V_109 ;
goto V_163;
}
F_107 ( & V_40 -> V_92 , F_56 , ( unsigned long )
V_40 ) ;
F_26 ( V_40 ) ;
V_117 = F_108 ( V_40 -> V_119 , F_86 ,
0 , F_109 ( & V_148 -> V_56 ) , V_40 ) ;
if ( V_117 )
goto V_163;
F_18 ( V_40 ) ;
F_29 ( V_40 , V_32 ) ;
F_110 ( & V_40 -> V_78 ) ;
F_72 ( & V_40 -> V_74 ) ;
F_72 ( & V_40 -> V_70 ) ;
F_72 ( & V_40 -> V_85 ) ;
V_40 -> V_48 . V_55 = V_151 ;
F_111 ( & V_40 -> V_48 ) ;
F_49 ( & V_40 -> V_48 . V_144 , & V_151 -> V_152 ) ;
if ( F_106 ( V_32 , V_151 -> V_149 ) ) {
V_117 = F_87 ( V_40 ) ;
F_24 ( & V_148 -> V_56 , L_33 , V_117 ) ;
if ( V_117 )
goto V_164;
}
if ( F_106 ( V_17 , V_151 -> V_149 ) ) {
V_117 = F_92 ( V_40 ) ;
F_24 ( & V_148 -> V_56 , L_34 , V_117 ) ;
if ( V_117 )
goto V_164;
}
F_112 ( & V_148 -> V_56 , L_35 ,
F_106 ( V_17 , V_151 -> V_149 ) ? L_36 : L_37 ,
F_106 ( V_32 , V_151 -> V_149 ) ? L_38 : L_37 ,
F_106 ( V_165 , V_151 -> V_149 ) ? L_39 : L_37 ) ;
F_113 ( V_151 ) ;
return V_40 ;
V_164:
F_101 ( V_40 -> V_119 , V_40 ) ;
V_163:
F_100 ( & V_148 -> V_56 , V_101 ,
V_40 -> V_106 , V_40 -> V_108 ) ;
return F_104 ( V_117 ) ;
}
static void
F_114 ( struct V_145 * V_146 ,
const struct V_166 * V_167 )
{
void T_7 * V_168 = V_146 -> V_162 ;
T_1 V_169 = 0 ;
int V_88 ;
for ( V_88 = 0 ; V_88 < 8 ; V_88 ++ ) {
F_115 ( 0 , V_168 + F_116 ( V_88 ) ) ;
F_115 ( 0 , V_168 + F_117 ( V_88 ) ) ;
if ( V_88 < 4 )
F_115 ( 0 , V_168 + F_118 ( V_88 ) ) ;
}
for ( V_88 = 0 ; V_88 < V_167 -> V_170 ; V_88 ++ ) {
const struct V_171 * V_172 = V_167 -> V_172 + V_88 ;
F_115 ( ( V_172 -> V_168 & 0xffff0000 ) |
( V_172 -> V_173 << 8 ) |
V_167 -> V_174 , V_168 + F_116 ( V_88 ) ) ;
F_115 ( ( V_172 -> V_175 - 1 ) & 0xffff0000 , V_168 + F_117 ( V_88 ) ) ;
V_169 |= ( 1 << V_88 ) ;
V_169 |= 3 << ( 16 + ( 2 * V_88 ) ) ;
}
F_115 ( V_169 , V_168 + F_119 ( 0 ) ) ;
F_115 ( V_169 , V_168 + F_119 ( 1 ) ) ;
F_115 ( 0 , V_168 + F_120 ( 0 ) ) ;
F_115 ( 0 , V_168 + F_120 ( 1 ) ) ;
}
static int F_121 ( struct V_147 * V_148 )
{
const struct V_166 * V_167 ;
struct V_145 * V_146 ;
struct V_176 * V_177 = F_122 ( & V_148 -> V_56 ) ;
struct V_178 * V_179 ;
int V_88 , V_117 ;
F_123 ( & V_148 -> V_56 , L_40 ) ;
V_146 = F_103 ( & V_148 -> V_56 , sizeof( * V_146 ) , V_104 ) ;
if ( ! V_146 )
return - V_109 ;
V_179 = F_124 ( V_148 , V_180 , 0 ) ;
if ( ! V_179 )
return - V_127 ;
V_146 -> V_162 = F_125 ( & V_148 -> V_56 , V_179 -> V_181 ,
F_126 ( V_179 ) ) ;
if ( ! V_146 -> V_162 )
return - V_90 ;
V_179 = F_124 ( V_148 , V_180 , 1 ) ;
if ( ! V_179 )
return - V_127 ;
V_146 -> V_182 = F_125 ( & V_148 -> V_56 , V_179 -> V_181 ,
F_126 ( V_179 ) ) ;
if ( ! V_146 -> V_182 )
return - V_90 ;
F_127 ( V_148 , V_146 ) ;
V_167 = F_128 () ;
if ( V_167 )
F_114 ( V_146 , V_167 ) ;
V_146 -> V_183 = F_129 ( & V_148 -> V_56 , NULL ) ;
if ( ! F_130 ( V_146 -> V_183 ) )
F_131 ( V_146 -> V_183 ) ;
if ( V_148 -> V_56 . V_184 ) {
struct V_144 * V_185 ;
int V_88 = 0 ;
F_132 (pdev->dev.of_node, np) {
T_6 V_149 ;
int V_119 ;
F_133 ( V_149 ) ;
if ( F_134 ( V_185 , L_41 ) )
F_135 ( V_32 , V_149 ) ;
if ( F_134 ( V_185 , L_42 ) )
F_135 ( V_17 , V_149 ) ;
if ( F_134 ( V_185 , L_43 ) )
F_135 ( V_165 , V_149 ) ;
V_119 = F_136 ( V_185 , 0 ) ;
if ( ! V_119 ) {
V_117 = - V_127 ;
goto V_186;
}
V_146 -> V_152 [ V_88 ] =
F_102 ( V_146 , V_148 , V_88 ,
V_149 , V_119 ) ;
if ( F_130 ( V_146 -> V_152 [ V_88 ] ) ) {
V_117 = F_137 ( V_146 -> V_152 [ V_88 ] ) ;
V_146 -> V_152 [ V_88 ] = NULL ;
F_138 ( V_119 ) ;
goto V_186;
}
V_88 ++ ;
}
} else if ( V_177 && V_177 -> V_152 ) {
for ( V_88 = 0 ; V_88 < V_187 ; V_88 ++ ) {
struct V_188 * V_189 ;
int V_119 ;
V_189 = & V_177 -> V_152 [ V_88 ] ;
if ( ! V_189 ) {
V_117 = - V_127 ;
goto V_186;
}
V_119 = F_139 ( V_148 , V_88 ) ;
if ( V_119 < 0 ) {
V_117 = V_119 ;
goto V_186;
}
V_146 -> V_152 [ V_88 ] =
F_102 ( V_146 , V_148 , V_88 ,
V_189 -> V_149 , V_119 ) ;
if ( F_130 ( V_146 -> V_152 [ V_88 ] ) ) {
V_117 = F_137 ( V_146 -> V_152 [ V_88 ] ) ;
goto V_186;
}
}
}
return 0 ;
V_186:
for ( V_88 = 0 ; V_88 < V_187 ; V_88 ++ )
if ( V_146 -> V_152 [ V_88 ] ) {
F_98 ( V_146 -> V_152 [ V_88 ] ) ;
if ( V_148 -> V_56 . V_184 )
F_138 ( V_146 -> V_152 [ V_88 ] -> V_119 ) ;
}
if ( ! F_130 ( V_146 -> V_183 ) ) {
F_140 ( V_146 -> V_183 ) ;
F_141 ( V_146 -> V_183 ) ;
}
return V_117 ;
}
static int F_142 ( struct V_147 * V_148 )
{
struct V_145 * V_146 = F_143 ( V_148 ) ;
int V_88 ;
for ( V_88 = 0 ; V_88 < V_187 ; V_88 ++ ) {
if ( V_146 -> V_152 [ V_88 ] )
F_98 ( V_146 -> V_152 [ V_88 ] ) ;
}
if ( ! F_130 ( V_146 -> V_183 ) ) {
F_140 ( V_146 -> V_183 ) ;
F_141 ( V_146 -> V_183 ) ;
}
return 0 ;
}
static int T_8 F_144 ( void )
{
return F_145 ( & V_190 ) ;
}
