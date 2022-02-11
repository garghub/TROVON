static void F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_6 = ( 1 << 31 ) ;
V_5 -> V_7 = 0 ;
V_5 -> V_8 = ( 1 << 31 ) ;
}
static void F_2 ( struct V_1 * V_2 ,
T_1 V_9 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_9 = V_9 ;
}
static void F_3 ( struct V_1 * V_2 ,
T_1 V_10 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_4 ( V_5 -> V_7 ) ;
V_5 -> V_7 = V_10 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_7 = 0 ;
}
static void F_6 ( struct V_1 * V_2 ,
T_2 V_11 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_12 = V_11 ;
}
static int F_7 ( T_3 V_13 )
{
return 1 ;
}
static void F_8 ( struct V_1 * V_2 ,
int V_14 , T_2 V_11 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_15 [ F_9 ( V_14 ) ] = V_11 ;
if ( V_2 -> type == V_16 )
V_5 -> V_8 |= ( 1 << V_14 ) ;
}
static T_1 F_10 ( struct V_17 * V_18 )
{
return F_11 ( F_12 ( V_18 ) ) ;
}
static void F_13 ( struct V_17 * V_18 ,
T_1 V_10 )
{
F_14 ( V_10 , F_15 ( V_18 ) ) ;
}
static void F_16 ( struct V_17 * V_18 )
{
T_1 V_19 = F_11 ( F_17 ( V_18 ) ) ;
V_19 |= V_20 << ( V_18 -> V_21 * 16 ) ;
F_14 ( V_19 , F_17 ( V_18 ) ) ;
}
static T_1 F_18 ( struct V_17 * V_18 )
{
T_1 V_22 = F_11 ( F_19 ( V_18 ) ) ;
V_22 = ( V_22 >> ( V_18 -> V_21 * 16 ) ) & 0xFFFF ;
return V_22 ;
}
static int F_20 ( T_1 V_22 )
{
if ( V_22 & ( ( 1 << 4 ) | ( 1 << 5 ) | ( 1 << 6 ) | ( 1 << 7 ) | ( 1 << 8 ) | ( 1 << 9 ) ) )
return 1 ;
return 0 ;
}
static void F_21 ( struct V_17 * V_18 )
{
T_1 V_19 = ~ ( 1 << ( V_18 -> V_21 * 16 ) ) ;
F_22 ( F_23 ( V_18 ) , L_1 , V_23 , V_19 ) ;
F_14 ( V_19 , F_19 ( V_18 ) ) ;
}
static void F_24 ( struct V_17 * V_18 )
{
T_1 V_19 = 0xFFFF0000 >> ( V_18 -> V_21 * 16 ) ;
F_14 ( V_19 , F_19 ( V_18 ) ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_1 * V_24 = F_26 (
V_2 -> V_25 . V_26 , struct V_1 , V_25 ) ;
if ( V_24 -> type != V_2 -> type )
return 0 ;
return 1 ;
}
static void F_27 ( struct V_17 * V_18 ,
enum V_27 type )
{
T_1 V_28 ;
T_1 V_29 = F_11 ( F_28 ( V_18 ) ) ;
switch ( type ) {
case V_16 :
V_28 = V_30 ;
break;
case V_31 :
V_28 = V_32 ;
break;
default:
F_29 ( F_23 ( V_18 ) ,
L_2 ,
type ) ;
F_30 () ;
return;
}
V_29 &= ~ 0x7 ;
V_29 |= V_28 ;
#if F_31 ( V_33 )
V_29 |= V_34 ;
#else
V_29 &= ~ V_34 ;
#endif
F_14 ( V_29 , F_28 ( V_18 ) ) ;
V_18 -> V_35 = type ;
}
static void F_32 ( struct V_17 * V_18 )
{
F_22 ( F_23 ( V_18 ) , L_3 ) ;
F_33 ( F_34 ( 0 ) , F_35 ( V_18 ) ) ;
}
static char F_36 ( struct V_17 * V_18 )
{
T_1 V_36 = F_11 ( F_35 ( V_18 ) ) ;
V_36 = ( V_36 >> 4 ) & 0x3 ;
return ( V_36 == 1 ) ? 1 : 0 ;
}
static int F_37 ( T_3 V_13 , int V_37 )
{
return 1 ;
}
static void F_38 ( struct V_17 * V_38 ,
struct V_1 * V_39 )
{
F_22 ( F_23 ( V_38 ) , L_4 ,
V_23 , __LINE__ , V_39 ) ;
V_39 -> V_40 = 0 ;
}
static void F_39 ( struct V_17 * V_38 ,
struct V_1 * V_41 )
{
F_22 ( F_23 ( V_38 ) , L_5 ,
V_23 , __LINE__ , V_41 ) ;
if ( V_41 -> type != V_38 -> V_35 )
F_27 ( V_38 , V_41 -> type ) ;
F_13 ( V_38 , V_41 -> V_42 . V_43 ) ;
V_38 -> V_44 += V_41 -> V_45 ;
F_40 ( & V_38 -> V_46 ) ;
}
static T_4
F_41 ( struct V_1 * V_2 ,
struct V_17 * V_38 , T_4 V_47 )
{
F_4 ( V_2 -> V_42 . V_47 < 0 ) ;
if ( V_2 -> V_42 . V_47 > 0 ) {
V_47 = V_2 -> V_42 . V_47 ;
if ( V_2 -> V_42 . V_48 )
V_2 -> V_42 . V_48 (
V_2 -> V_42 . V_49 ) ;
F_42 ( & V_2 -> V_42 ) ;
if ( V_2 -> V_50 )
V_2 -> V_50 = NULL ;
}
F_43 ( & V_2 -> V_42 ) ;
return V_47 ;
}
static int
F_44 ( struct V_17 * V_38 )
{
struct V_1 * V_51 , * V_52 ;
F_22 ( F_23 ( V_38 ) , L_6 , V_23 , __LINE__ ) ;
F_45 (iter, _iter, &mv_chan->completed_slots,
completed_node) {
if ( F_46 ( & V_51 -> V_42 ) ) {
F_47 ( & V_51 -> V_53 ) ;
F_38 ( V_38 , V_51 ) ;
}
}
return 0 ;
}
static int
F_48 ( struct V_1 * V_2 ,
struct V_17 * V_38 )
{
F_22 ( F_23 ( V_38 ) , L_7 ,
V_23 , __LINE__ , V_2 , V_2 -> V_42 . V_3 ) ;
F_47 ( & V_2 -> V_25 ) ;
if ( ! F_46 ( & V_2 -> V_42 ) ) {
F_49 ( & V_2 -> V_53 , & V_38 -> V_54 ) ;
return 0 ;
}
F_38 ( V_38 , V_2 ) ;
return 0 ;
}
static void F_50 ( struct V_17 * V_38 )
{
struct V_1 * V_51 , * V_52 ;
T_4 V_47 = 0 ;
int V_55 = F_36 ( V_38 ) ;
T_1 V_56 = F_10 ( V_38 ) ;
int V_57 = 0 ;
F_22 ( F_23 ( V_38 ) , L_6 , V_23 , __LINE__ ) ;
F_22 ( F_23 ( V_38 ) , L_8 , V_56 ) ;
F_44 ( V_38 ) ;
F_45 (iter, _iter, &mv_chan->chain,
chain_node) {
F_51 ( V_52 ) ;
F_51 ( & V_52 -> V_42 ) ;
if ( V_57 )
break;
if ( V_51 -> V_42 . V_43 == V_56 ) {
V_57 = 1 ;
if ( V_55 )
break;
}
V_47 = F_41 ( V_51 , V_38 , V_47 ) ;
if ( F_48 ( V_51 , V_38 ) )
break;
}
if ( ( V_55 == 0 ) && ! F_52 ( & V_38 -> V_58 ) ) {
struct V_1 * V_59 ;
V_59 = F_26 ( V_38 -> V_58 . V_60 ,
struct V_1 ,
V_25 ) ;
F_39 ( V_38 , V_59 ) ;
}
if ( V_47 > 0 )
V_38 -> V_46 . V_61 = V_47 ;
}
static void
F_53 ( struct V_17 * V_38 )
{
F_54 ( & V_38 -> V_62 ) ;
F_50 ( V_38 ) ;
F_55 ( & V_38 -> V_62 ) ;
}
static void F_56 ( unsigned long V_63 )
{
struct V_17 * V_18 = (struct V_17 * ) V_63 ;
F_53 ( V_18 ) ;
}
static struct V_1 *
F_57 ( struct V_17 * V_38 , int V_64 ,
int V_40 )
{
struct V_1 * V_51 , * V_52 , * V_65 = NULL ;
F_58 ( V_58 ) ;
int V_66 , V_67 = 0 ;
V_67:
V_66 = 0 ;
if ( V_67 == 0 )
V_51 = V_38 -> V_68 ;
else
V_51 = F_26 ( & V_38 -> V_69 ,
struct V_1 ,
V_70 ) ;
F_59 (
iter, _iter, &mv_chan->all_slots, slot_node) {
F_51 ( V_52 ) ;
F_51 ( & V_52 -> V_42 ) ;
if ( V_51 -> V_40 ) {
if ( V_67 )
break;
V_66 = 0 ;
continue;
}
if ( ! V_66 ++ )
V_65 = V_51 ;
if ( V_66 == V_64 ) {
struct V_1 * V_71 = NULL ;
struct V_1 * V_68 = NULL ;
V_51 = V_65 ;
while ( V_64 ) {
int V_72 ;
F_60 ( & V_51 -> V_42 ) ;
F_49 ( & V_51 -> V_25 , & V_58 ) ;
V_71 = V_51 ;
V_51 -> V_42 . V_47 = 0 ;
V_51 -> V_45 = V_64 ;
V_51 -> V_73 = NULL ;
for ( V_72 = 0 ; V_72 < V_40 ; V_72 ++ ) {
V_51 -> V_40 = V_40 - V_72 ;
V_68 = V_51 ;
V_51 = F_26 ( V_51 -> V_70 . V_60 ,
struct V_1 ,
V_70 ) ;
}
V_64 -= V_40 ;
}
V_71 -> V_50 = V_65 ;
V_71 -> V_42 . V_47 = - V_74 ;
F_61 ( & V_58 , & V_71 -> V_75 ) ;
V_38 -> V_68 = V_68 ;
F_5 ( V_65 ) ;
F_5 ( V_71 ) ;
return V_71 ;
}
}
if ( ! V_67 ++ )
goto V_67;
F_62 ( & V_38 -> V_76 ) ;
return NULL ;
}
static T_4
F_63 ( struct V_77 * V_78 )
{
struct V_1 * V_41 = F_64 ( V_78 ) ;
struct V_17 * V_38 = F_65 ( V_78 -> V_18 ) ;
struct V_1 * V_79 , * V_80 ;
T_4 V_47 ;
int V_81 = 1 ;
F_22 ( F_23 ( V_38 ) ,
L_9 ,
V_23 , V_41 , & V_41 -> V_42 ) ;
V_79 = V_41 -> V_50 ;
F_54 ( & V_38 -> V_62 ) ;
V_47 = F_66 ( V_78 ) ;
if ( F_52 ( & V_38 -> V_58 ) )
F_67 ( & V_41 -> V_75 , & V_38 -> V_58 ) ;
else {
V_81 = 0 ;
V_80 = F_26 ( V_38 -> V_58 . V_26 ,
struct V_1 ,
V_25 ) ;
F_67 ( & V_79 -> V_75 ,
& V_80 -> V_25 ) ;
if ( ! F_25 ( V_79 ) )
goto V_82;
F_22 ( F_23 ( V_38 ) , L_10 ,
& V_80 -> V_42 . V_43 ) ;
F_3 ( V_80 , V_79 -> V_42 . V_43 ) ;
if ( ! F_36 ( V_38 ) ) {
T_1 V_56 = F_10 ( V_38 ) ;
if ( V_56 == V_80 -> V_42 . V_43 )
V_81 = 1 ;
}
}
if ( V_81 )
F_39 ( V_38 , V_79 ) ;
V_82:
F_55 ( & V_38 -> V_62 ) ;
return V_47 ;
}
static int F_68 ( struct V_83 * V_18 )
{
void * V_84 ;
T_2 V_85 ;
int V_21 ;
struct V_17 * V_38 = F_65 ( V_18 ) ;
struct V_1 * V_39 = NULL ;
int V_86 = V_87 / V_88 ;
V_21 = V_38 -> V_89 ;
while ( V_21 < V_86 ) {
V_39 = F_69 ( sizeof( * V_39 ) , V_90 ) ;
if ( ! V_39 ) {
F_70 ( V_91 L_11
L_12 , V_21 ) ;
break;
}
V_84 = V_38 -> V_92 ;
V_39 -> V_5 = V_84 + V_21 * V_88 ;
F_71 ( & V_39 -> V_42 , V_18 ) ;
V_39 -> V_42 . V_93 = F_63 ;
F_72 ( & V_39 -> V_25 ) ;
F_72 ( & V_39 -> V_70 ) ;
F_72 ( & V_39 -> V_75 ) ;
V_85 = V_38 -> V_94 ;
V_39 -> V_42 . V_43 = V_85 + V_21 * V_88 ;
V_39 -> V_21 = V_21 ++ ;
F_54 ( & V_38 -> V_62 ) ;
V_38 -> V_89 = V_21 ;
F_49 ( & V_39 -> V_70 , & V_38 -> V_69 ) ;
F_55 ( & V_38 -> V_62 ) ;
}
if ( V_38 -> V_89 && ! V_38 -> V_68 )
V_38 -> V_68 = F_26 ( V_38 -> V_69 . V_60 ,
struct V_1 ,
V_70 ) ;
F_22 ( F_23 ( V_38 ) ,
L_13 ,
V_38 -> V_89 , V_38 -> V_68 ) ;
return V_38 -> V_89 ? : - V_95 ;
}
static struct V_77 *
F_73 ( struct V_83 * V_18 , T_2 V_96 , T_2 V_97 ,
T_3 V_13 , unsigned long V_3 )
{
struct V_17 * V_38 = F_65 ( V_18 ) ;
struct V_1 * V_41 , * V_79 ;
int V_45 ;
F_22 ( F_23 ( V_38 ) ,
L_14 ,
V_23 , & V_96 , & V_97 , V_13 , V_3 ) ;
if ( F_74 ( V_13 < V_98 ) )
return NULL ;
F_4 ( V_13 > V_99 ) ;
F_54 ( & V_38 -> V_62 ) ;
V_45 = F_75 ( V_13 ) ;
V_41 = F_57 ( V_38 , V_45 , 1 ) ;
if ( V_41 ) {
V_41 -> type = V_31 ;
V_41 -> V_42 . V_3 = V_3 ;
V_79 = V_41 -> V_50 ;
F_1 ( V_79 , V_3 ) ;
F_2 ( V_79 , V_13 ) ;
F_6 ( V_41 -> V_50 , V_96 ) ;
F_8 ( V_79 , 0 , V_97 ) ;
V_41 -> V_100 = 1 ;
V_41 -> V_101 = V_13 ;
}
F_55 ( & V_38 -> V_62 ) ;
F_22 ( F_23 ( V_38 ) ,
L_15 ,
V_23 , V_41 , V_41 ? & V_41 -> V_42 : NULL ) ;
return V_41 ? & V_41 -> V_42 : NULL ;
}
static struct V_77 *
F_76 ( struct V_83 * V_18 , T_2 V_96 , T_2 * V_97 ,
unsigned int V_37 , T_3 V_13 , unsigned long V_3 )
{
struct V_17 * V_38 = F_65 ( V_18 ) ;
struct V_1 * V_41 , * V_79 ;
int V_45 ;
if ( F_74 ( V_13 < V_98 ) )
return NULL ;
F_4 ( V_13 > V_99 ) ;
F_22 ( F_23 ( V_38 ) ,
L_16 ,
V_23 , V_37 , V_13 , & V_96 , V_3 ) ;
F_54 ( & V_38 -> V_62 ) ;
V_45 = F_37 ( V_13 , V_37 ) ;
V_41 = F_57 ( V_38 , V_45 , 1 ) ;
if ( V_41 ) {
V_41 -> type = V_16 ;
V_41 -> V_42 . V_3 = V_3 ;
V_79 = V_41 -> V_50 ;
F_1 ( V_79 , V_3 ) ;
F_2 ( V_79 , V_13 ) ;
F_6 ( V_41 -> V_50 , V_96 ) ;
V_41 -> V_100 = V_37 ;
V_41 -> V_101 = V_13 ;
while ( V_37 -- )
F_8 ( V_79 , V_37 , V_97 [ V_37 ] ) ;
}
F_55 ( & V_38 -> V_62 ) ;
F_22 ( F_23 ( V_38 ) ,
L_17 ,
V_23 , V_41 , & V_41 -> V_42 ) ;
return V_41 ? & V_41 -> V_42 : NULL ;
}
static void F_77 ( struct V_83 * V_18 )
{
struct V_17 * V_38 = F_65 ( V_18 ) ;
struct V_1 * V_51 , * V_52 ;
int V_102 = 0 ;
F_53 ( V_38 ) ;
F_54 ( & V_38 -> V_62 ) ;
F_45 (iter, _iter, &mv_chan->chain,
chain_node) {
V_102 ++ ;
F_47 ( & V_51 -> V_25 ) ;
}
F_45 (iter, _iter, &mv_chan->completed_slots,
completed_node) {
V_102 ++ ;
F_47 ( & V_51 -> V_53 ) ;
}
F_78 (
iter, _iter, &mv_chan->all_slots, slot_node) {
F_47 ( & V_51 -> V_70 ) ;
F_79 ( V_51 ) ;
V_38 -> V_89 -- ;
}
V_38 -> V_68 = NULL ;
F_22 ( F_23 ( V_38 ) , L_18 ,
V_23 , V_38 -> V_89 ) ;
F_55 ( & V_38 -> V_62 ) ;
if ( V_102 )
F_29 ( F_23 ( V_38 ) ,
L_19 , V_102 ) ;
}
static enum V_103 F_80 ( struct V_83 * V_18 ,
T_4 V_47 ,
struct V_104 * V_105 )
{
struct V_17 * V_38 = F_65 ( V_18 ) ;
enum V_103 V_106 ;
V_106 = F_81 ( V_18 , V_47 , V_105 ) ;
if ( V_106 == V_107 ) {
F_44 ( V_38 ) ;
return V_106 ;
}
F_53 ( V_38 ) ;
return F_81 ( V_18 , V_47 , V_105 ) ;
}
static void F_82 ( struct V_17 * V_18 )
{
T_1 V_19 ;
V_19 = F_11 ( F_28 ( V_18 ) ) ;
F_29 ( F_23 ( V_18 ) , L_20 , V_19 ) ;
V_19 = F_11 ( F_35 ( V_18 ) ) ;
F_29 ( F_23 ( V_18 ) , L_21 , V_19 ) ;
V_19 = F_11 ( F_19 ( V_18 ) ) ;
F_29 ( F_23 ( V_18 ) , L_22 , V_19 ) ;
V_19 = F_11 ( F_17 ( V_18 ) ) ;
F_29 ( F_23 ( V_18 ) , L_23 , V_19 ) ;
V_19 = F_11 ( F_83 ( V_18 ) ) ;
F_29 ( F_23 ( V_18 ) , L_24 , V_19 ) ;
V_19 = F_11 ( F_84 ( V_18 ) ) ;
F_29 ( F_23 ( V_18 ) , L_25 , V_19 ) ;
}
static void F_85 ( struct V_17 * V_18 ,
T_1 V_22 )
{
if ( V_22 & ( 1 << 4 ) ) {
F_22 ( F_23 ( V_18 ) ,
L_26 ) ;
return;
}
F_29 ( F_23 ( V_18 ) ,
L_27 ,
V_18 -> V_21 , V_22 ) ;
F_82 ( V_18 ) ;
F_30 () ;
}
static T_5 F_86 ( int V_108 , void * V_63 )
{
struct V_17 * V_18 = V_63 ;
T_1 V_22 = F_18 ( V_18 ) ;
F_22 ( F_23 ( V_18 ) , L_28 , V_22 ) ;
if ( F_20 ( V_22 ) )
F_85 ( V_18 , V_22 ) ;
F_62 ( & V_18 -> V_76 ) ;
F_21 ( V_18 ) ;
return V_109 ;
}
static void F_40 ( struct V_83 * V_18 )
{
struct V_17 * V_38 = F_65 ( V_18 ) ;
if ( V_38 -> V_44 >= V_110 ) {
V_38 -> V_44 = 0 ;
F_32 ( V_38 ) ;
}
}
static int F_87 ( struct V_17 * V_38 )
{
int V_72 ;
void * V_97 , * V_96 ;
T_2 V_111 , V_112 ;
struct V_83 * V_83 ;
T_4 V_47 ;
struct V_77 * V_78 ;
struct V_113 * V_114 ;
int V_115 = 0 ;
V_97 = F_88 ( sizeof( V_116 ) * V_117 , V_90 ) ;
if ( ! V_97 )
return - V_95 ;
V_96 = F_69 ( sizeof( V_116 ) * V_117 , V_90 ) ;
if ( ! V_96 ) {
F_79 ( V_97 ) ;
return - V_95 ;
}
for ( V_72 = 0 ; V_72 < V_117 ; V_72 ++ )
( ( V_116 * ) V_97 ) [ V_72 ] = ( V_116 ) V_72 ;
V_83 = & V_38 -> V_46 ;
if ( F_68 ( V_83 ) < 1 ) {
V_115 = - V_118 ;
goto V_119;
}
V_114 = F_89 ( V_83 -> V_120 -> V_121 , 2 , V_90 ) ;
if ( ! V_114 ) {
V_115 = - V_95 ;
goto V_122;
}
V_111 = F_90 ( V_83 -> V_120 -> V_121 , F_91 ( V_97 ) , 0 ,
V_117 , V_123 ) ;
V_114 -> V_124 = 1 ;
V_114 -> V_11 [ 0 ] = V_111 ;
V_112 = F_90 ( V_83 -> V_120 -> V_121 , F_91 ( V_96 ) , 0 ,
V_117 , V_125 ) ;
V_114 -> V_126 = 1 ;
V_114 -> V_11 [ 1 ] = V_112 ;
V_114 -> V_13 = V_117 ;
V_78 = F_73 ( V_83 , V_112 , V_111 ,
V_117 , 0 ) ;
V_47 = F_63 ( V_78 ) ;
F_40 ( V_83 ) ;
F_60 ( V_78 ) ;
F_92 ( 1 ) ;
if ( F_80 ( V_83 , V_47 , NULL ) !=
V_107 ) {
F_29 ( V_83 -> V_120 -> V_121 ,
L_29 ) ;
V_115 = - V_118 ;
goto V_122;
}
F_93 ( V_83 -> V_120 -> V_121 , V_112 ,
V_117 , V_125 ) ;
if ( memcmp ( V_97 , V_96 , V_117 ) ) {
F_29 ( V_83 -> V_120 -> V_121 ,
L_30 ) ;
V_115 = - V_118 ;
goto V_122;
}
V_122:
F_94 ( V_114 ) ;
F_77 ( V_83 ) ;
V_119:
F_79 ( V_97 ) ;
F_79 ( V_96 ) ;
return V_115 ;
}
static int
F_95 ( struct V_17 * V_38 )
{
int V_72 , V_127 ;
struct V_128 * V_96 ;
struct V_128 * V_129 [ V_130 ] ;
T_2 V_131 [ V_130 ] ;
T_2 V_112 ;
struct V_77 * V_78 ;
struct V_113 * V_114 ;
struct V_83 * V_83 ;
T_4 V_47 ;
V_116 V_132 = 0 ;
T_1 V_133 ;
int V_115 = 0 ;
int V_134 = V_130 ;
for ( V_127 = 0 ; V_127 < V_134 ; V_127 ++ ) {
V_129 [ V_127 ] = F_96 ( V_90 ) ;
if ( ! V_129 [ V_127 ] ) {
while ( V_127 -- )
F_97 ( V_129 [ V_127 ] ) ;
return - V_95 ;
}
}
V_96 = F_96 ( V_90 ) ;
if ( ! V_96 ) {
while ( V_127 -- )
F_97 ( V_129 [ V_127 ] ) ;
return - V_95 ;
}
for ( V_127 = 0 ; V_127 < V_134 ; V_127 ++ ) {
V_116 * V_135 = F_98 ( V_129 [ V_127 ] ) ;
for ( V_72 = 0 ; V_72 < V_117 ; V_72 ++ )
V_135 [ V_72 ] = ( 1 << V_127 ) ;
}
for ( V_127 = 0 ; V_127 < V_134 ; V_127 ++ )
V_132 ^= ( V_116 ) ( 1 << V_127 ) ;
V_133 = ( V_132 << 24 ) | ( V_132 << 16 ) |
( V_132 << 8 ) | V_132 ;
memset ( F_98 ( V_96 ) , 0 , V_117 ) ;
V_83 = & V_38 -> V_46 ;
if ( F_68 ( V_83 ) < 1 ) {
V_115 = - V_118 ;
goto V_119;
}
V_114 = F_89 ( V_83 -> V_120 -> V_121 , V_134 + 1 ,
V_90 ) ;
if ( ! V_114 ) {
V_115 = - V_95 ;
goto V_122;
}
for ( V_72 = 0 ; V_72 < V_134 ; V_72 ++ ) {
V_114 -> V_11 [ V_72 ] = F_90 ( V_83 -> V_120 -> V_121 , V_129 [ V_72 ] ,
0 , V_117 , V_123 ) ;
V_131 [ V_72 ] = V_114 -> V_11 [ V_72 ] ;
V_114 -> V_124 ++ ;
}
V_114 -> V_11 [ V_134 ] = F_90 ( V_83 -> V_120 -> V_121 , V_96 , 0 , V_117 ,
V_125 ) ;
V_112 = V_114 -> V_11 [ V_134 ] ;
V_114 -> V_126 = 1 ;
V_114 -> V_13 = V_117 ;
V_78 = F_76 ( V_83 , V_112 , V_131 ,
V_134 , V_117 , 0 ) ;
V_47 = F_63 ( V_78 ) ;
F_40 ( V_83 ) ;
F_60 ( V_78 ) ;
F_92 ( 8 ) ;
if ( F_80 ( V_83 , V_47 , NULL ) !=
V_107 ) {
F_29 ( V_83 -> V_120 -> V_121 ,
L_31 ) ;
V_115 = - V_118 ;
goto V_122;
}
F_93 ( V_83 -> V_120 -> V_121 , V_112 ,
V_117 , V_125 ) ;
for ( V_72 = 0 ; V_72 < ( V_117 / sizeof( T_1 ) ) ; V_72 ++ ) {
T_1 * V_135 = F_98 ( V_96 ) ;
if ( V_135 [ V_72 ] != V_133 ) {
F_29 ( V_83 -> V_120 -> V_121 ,
L_32 ,
V_72 , V_135 [ V_72 ] , V_133 ) ;
V_115 = - V_118 ;
goto V_122;
}
}
V_122:
F_94 ( V_114 ) ;
F_77 ( V_83 ) ;
V_119:
V_127 = V_134 ;
while ( V_127 -- )
F_97 ( V_129 [ V_127 ] ) ;
F_97 ( V_96 ) ;
return V_115 ;
}
static int
F_99 ( struct V_83 * V_18 , enum V_136 V_137 ,
unsigned long V_138 )
{
return - V_139 ;
}
static int F_100 ( struct V_17 * V_38 )
{
struct V_83 * V_18 , * V_140 ;
struct V_120 * V_121 = V_38 -> V_141 . V_121 ;
F_101 ( & V_38 -> V_141 ) ;
F_102 ( V_121 , V_87 ,
V_38 -> V_92 , V_38 -> V_94 ) ;
F_45 (chan, _chan, &mv_chan->dmadev.channels,
device_node) {
F_47 ( & V_18 -> V_142 ) ;
}
F_103 ( V_38 -> V_108 , V_38 ) ;
return 0 ;
}
static struct V_17 *
F_104 ( struct V_143 * V_144 ,
struct V_145 * V_146 ,
int V_21 , T_6 V_147 , int V_108 )
{
int V_106 = 0 ;
struct V_17 * V_38 ;
struct V_148 * V_149 ;
V_38 = F_105 ( & V_146 -> V_121 , sizeof( * V_38 ) , V_90 ) ;
if ( ! V_38 )
return F_106 ( - V_95 ) ;
V_38 -> V_21 = V_21 ;
V_38 -> V_108 = V_108 ;
V_149 = & V_38 -> V_141 ;
V_38 -> V_92 =
F_107 ( & V_146 -> V_121 , V_87 ,
& V_38 -> V_94 , V_90 ) ;
if ( ! V_38 -> V_92 )
return F_106 ( - V_95 ) ;
V_149 -> V_147 = V_147 ;
F_72 ( & V_149 -> V_150 ) ;
V_149 -> V_151 = F_68 ;
V_149 -> V_152 = F_77 ;
V_149 -> V_153 = F_80 ;
V_149 -> V_154 = F_40 ;
V_149 -> V_155 = F_99 ;
V_149 -> V_121 = & V_146 -> V_121 ;
if ( F_108 ( V_31 , V_149 -> V_147 ) )
V_149 -> V_156 = F_73 ;
if ( F_108 ( V_16 , V_149 -> V_147 ) ) {
V_149 -> V_157 = 8 ;
V_149 -> V_158 = F_76 ;
}
V_38 -> V_159 = V_144 -> V_160 ;
V_38 -> V_161 = V_144 -> V_162 ;
F_109 ( & V_38 -> V_76 , F_56 , ( unsigned long )
V_38 ) ;
F_24 ( V_38 ) ;
V_106 = F_110 ( V_38 -> V_108 , F_86 ,
0 , F_111 ( & V_146 -> V_121 ) , V_38 ) ;
if ( V_106 )
goto V_163;
F_16 ( V_38 ) ;
F_27 ( V_38 , V_31 ) ;
F_112 ( & V_38 -> V_62 ) ;
F_72 ( & V_38 -> V_58 ) ;
F_72 ( & V_38 -> V_54 ) ;
F_72 ( & V_38 -> V_69 ) ;
V_38 -> V_46 . V_120 = V_149 ;
F_113 ( & V_38 -> V_46 ) ;
F_49 ( & V_38 -> V_46 . V_142 , & V_149 -> V_150 ) ;
if ( F_108 ( V_31 , V_149 -> V_147 ) ) {
V_106 = F_87 ( V_38 ) ;
F_22 ( & V_146 -> V_121 , L_33 , V_106 ) ;
if ( V_106 )
goto V_164;
}
if ( F_108 ( V_16 , V_149 -> V_147 ) ) {
V_106 = F_95 ( V_38 ) ;
F_22 ( & V_146 -> V_121 , L_34 , V_106 ) ;
if ( V_106 )
goto V_164;
}
F_114 ( & V_146 -> V_121 , L_35 ,
F_108 ( V_16 , V_149 -> V_147 ) ? L_36 : L_37 ,
F_108 ( V_31 , V_149 -> V_147 ) ? L_38 : L_37 ,
F_108 ( V_165 , V_149 -> V_147 ) ? L_39 : L_37 ) ;
F_115 ( V_149 ) ;
return V_38 ;
V_164:
F_103 ( V_38 -> V_108 , V_38 ) ;
V_163:
F_102 ( & V_146 -> V_121 , V_87 ,
V_38 -> V_92 , V_38 -> V_94 ) ;
return F_106 ( V_106 ) ;
}
static void
F_116 ( struct V_143 * V_144 ,
const struct V_166 * V_167 )
{
void T_7 * V_168 = V_144 -> V_162 ;
T_1 V_169 = 0 ;
int V_72 ;
for ( V_72 = 0 ; V_72 < 8 ; V_72 ++ ) {
F_33 ( 0 , V_168 + F_117 ( V_72 ) ) ;
F_33 ( 0 , V_168 + F_118 ( V_72 ) ) ;
if ( V_72 < 4 )
F_33 ( 0 , V_168 + F_119 ( V_72 ) ) ;
}
for ( V_72 = 0 ; V_72 < V_167 -> V_170 ; V_72 ++ ) {
const struct V_171 * V_172 = V_167 -> V_172 + V_72 ;
F_33 ( ( V_172 -> V_168 & 0xffff0000 ) |
( V_172 -> V_173 << 8 ) |
V_167 -> V_174 , V_168 + F_117 ( V_72 ) ) ;
F_33 ( ( V_172 -> V_175 - 1 ) & 0xffff0000 , V_168 + F_118 ( V_72 ) ) ;
V_169 |= ( 1 << V_72 ) ;
V_169 |= 3 << ( 16 + ( 2 * V_72 ) ) ;
}
F_33 ( V_169 , V_168 + F_120 ( 0 ) ) ;
F_33 ( V_169 , V_168 + F_120 ( 1 ) ) ;
F_33 ( 0 , V_168 + F_121 ( 0 ) ) ;
F_33 ( 0 , V_168 + F_121 ( 1 ) ) ;
}
static int F_122 ( struct V_145 * V_146 )
{
const struct V_166 * V_167 ;
struct V_143 * V_144 ;
struct V_176 * V_177 = F_123 ( & V_146 -> V_121 ) ;
struct V_178 * V_179 ;
int V_72 , V_106 ;
F_124 ( & V_146 -> V_121 , L_40 ) ;
V_144 = F_105 ( & V_146 -> V_121 , sizeof( * V_144 ) , V_90 ) ;
if ( ! V_144 )
return - V_95 ;
V_179 = F_125 ( V_146 , V_180 , 0 ) ;
if ( ! V_179 )
return - V_118 ;
V_144 -> V_160 = F_126 ( & V_146 -> V_121 , V_179 -> V_181 ,
F_127 ( V_179 ) ) ;
if ( ! V_144 -> V_160 )
return - V_74 ;
V_179 = F_125 ( V_146 , V_180 , 1 ) ;
if ( ! V_179 )
return - V_118 ;
V_144 -> V_162 = F_126 ( & V_146 -> V_121 , V_179 -> V_181 ,
F_127 ( V_179 ) ) ;
if ( ! V_144 -> V_162 )
return - V_74 ;
F_128 ( V_146 , V_144 ) ;
V_167 = F_129 () ;
if ( V_167 )
F_116 ( V_144 , V_167 ) ;
V_144 -> V_182 = F_130 ( & V_146 -> V_121 , NULL ) ;
if ( ! F_131 ( V_144 -> V_182 ) )
F_132 ( V_144 -> V_182 ) ;
if ( V_146 -> V_121 . V_183 ) {
struct V_142 * V_184 ;
int V_72 = 0 ;
F_133 (pdev->dev.of_node, np) {
struct V_17 * V_18 ;
T_6 V_147 ;
int V_108 ;
F_134 ( V_147 ) ;
if ( F_135 ( V_184 , L_41 ) )
F_136 ( V_31 , V_147 ) ;
if ( F_135 ( V_184 , L_42 ) )
F_136 ( V_16 , V_147 ) ;
if ( F_135 ( V_184 , L_43 ) )
F_136 ( V_165 , V_147 ) ;
V_108 = F_137 ( V_184 , 0 ) ;
if ( ! V_108 ) {
V_106 = - V_118 ;
goto V_185;
}
V_18 = F_104 ( V_144 , V_146 , V_72 ,
V_147 , V_108 ) ;
if ( F_131 ( V_18 ) ) {
V_106 = F_138 ( V_18 ) ;
F_139 ( V_108 ) ;
goto V_185;
}
V_144 -> V_150 [ V_72 ] = V_18 ;
V_72 ++ ;
}
} else if ( V_177 && V_177 -> V_150 ) {
for ( V_72 = 0 ; V_72 < V_186 ; V_72 ++ ) {
struct V_187 * V_188 ;
struct V_17 * V_18 ;
int V_108 ;
V_188 = & V_177 -> V_150 [ V_72 ] ;
if ( ! V_188 ) {
V_106 = - V_118 ;
goto V_185;
}
V_108 = F_140 ( V_146 , V_72 ) ;
if ( V_108 < 0 ) {
V_106 = V_108 ;
goto V_185;
}
V_18 = F_104 ( V_144 , V_146 , V_72 ,
V_188 -> V_147 , V_108 ) ;
if ( F_131 ( V_18 ) ) {
V_106 = F_138 ( V_18 ) ;
goto V_185;
}
V_144 -> V_150 [ V_72 ] = V_18 ;
}
}
return 0 ;
V_185:
for ( V_72 = 0 ; V_72 < V_186 ; V_72 ++ )
if ( V_144 -> V_150 [ V_72 ] ) {
F_100 ( V_144 -> V_150 [ V_72 ] ) ;
if ( V_146 -> V_121 . V_183 )
F_139 ( V_144 -> V_150 [ V_72 ] -> V_108 ) ;
}
if ( ! F_131 ( V_144 -> V_182 ) ) {
F_141 ( V_144 -> V_182 ) ;
F_142 ( V_144 -> V_182 ) ;
}
return V_106 ;
}
static int F_143 ( struct V_145 * V_146 )
{
struct V_143 * V_144 = F_144 ( V_146 ) ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_186 ; V_72 ++ ) {
if ( V_144 -> V_150 [ V_72 ] )
F_100 ( V_144 -> V_150 [ V_72 ] ) ;
}
if ( ! F_131 ( V_144 -> V_182 ) ) {
F_141 ( V_144 -> V_182 ) ;
F_142 ( V_144 -> V_182 ) ;
}
return 0 ;
}
static int T_8 F_145 ( void )
{
return F_146 ( & V_189 ) ;
}
