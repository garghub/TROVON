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
T_1 V_36 ;
F_22 ( F_23 ( V_18 ) , L_3 ) ;
V_36 = F_11 ( F_33 ( V_18 ) ) ;
V_36 |= 0x1 ;
F_14 ( V_36 , F_33 ( V_18 ) ) ;
}
static char F_34 ( struct V_17 * V_18 )
{
T_1 V_37 = F_11 ( F_33 ( V_18 ) ) ;
V_37 = ( V_37 >> 4 ) & 0x3 ;
return ( V_37 == 1 ) ? 1 : 0 ;
}
static int F_35 ( T_3 V_13 , int V_38 )
{
return 1 ;
}
static void F_36 ( struct V_17 * V_39 ,
struct V_1 * V_40 )
{
F_22 ( F_23 ( V_39 ) , L_4 ,
V_23 , __LINE__ , V_40 ) ;
V_40 -> V_41 = 0 ;
}
static void F_37 ( struct V_17 * V_39 ,
struct V_1 * V_42 )
{
F_22 ( F_23 ( V_39 ) , L_5 ,
V_23 , __LINE__ , V_42 ) ;
if ( V_42 -> type != V_39 -> V_35 )
F_27 ( V_39 , V_42 -> type ) ;
F_13 ( V_39 , V_42 -> V_43 . V_44 ) ;
V_39 -> V_45 += V_42 -> V_46 ;
F_38 ( & V_39 -> V_47 ) ;
}
static T_4
F_39 ( struct V_1 * V_2 ,
struct V_17 * V_39 , T_4 V_48 )
{
F_4 ( V_2 -> V_43 . V_48 < 0 ) ;
if ( V_2 -> V_43 . V_48 > 0 ) {
V_48 = V_2 -> V_43 . V_48 ;
if ( V_2 -> V_43 . V_49 )
V_2 -> V_43 . V_49 (
V_2 -> V_43 . V_50 ) ;
F_40 ( & V_2 -> V_43 ) ;
if ( V_2 -> V_51 )
V_2 -> V_51 = NULL ;
}
F_41 ( & V_2 -> V_43 ) ;
return V_48 ;
}
static int
F_42 ( struct V_17 * V_39 )
{
struct V_1 * V_52 , * V_53 ;
F_22 ( F_23 ( V_39 ) , L_6 , V_23 , __LINE__ ) ;
F_43 (iter, _iter, &mv_chan->completed_slots,
completed_node) {
if ( F_44 ( & V_52 -> V_43 ) ) {
F_45 ( & V_52 -> V_54 ) ;
F_36 ( V_39 , V_52 ) ;
}
}
return 0 ;
}
static int
F_46 ( struct V_1 * V_2 ,
struct V_17 * V_39 )
{
F_22 ( F_23 ( V_39 ) , L_7 ,
V_23 , __LINE__ , V_2 , V_2 -> V_43 . V_3 ) ;
F_45 ( & V_2 -> V_25 ) ;
if ( ! F_44 ( & V_2 -> V_43 ) ) {
F_47 ( & V_2 -> V_54 , & V_39 -> V_55 ) ;
return 0 ;
}
F_36 ( V_39 , V_2 ) ;
return 0 ;
}
static void F_48 ( struct V_17 * V_39 )
{
struct V_1 * V_52 , * V_53 ;
T_4 V_48 = 0 ;
int V_56 = F_34 ( V_39 ) ;
T_1 V_57 = F_10 ( V_39 ) ;
int V_58 = 0 ;
F_22 ( F_23 ( V_39 ) , L_6 , V_23 , __LINE__ ) ;
F_22 ( F_23 ( V_39 ) , L_8 , V_57 ) ;
F_42 ( V_39 ) ;
F_43 (iter, _iter, &mv_chan->chain,
chain_node) {
F_49 ( V_53 ) ;
F_49 ( & V_53 -> V_43 ) ;
if ( V_58 )
break;
if ( V_52 -> V_43 . V_44 == V_57 ) {
V_58 = 1 ;
if ( V_56 )
break;
}
V_48 = F_39 ( V_52 , V_39 , V_48 ) ;
if ( F_46 ( V_52 , V_39 ) )
break;
}
if ( ( V_56 == 0 ) && ! F_50 ( & V_39 -> V_59 ) ) {
struct V_1 * V_60 ;
V_60 = F_26 ( V_39 -> V_59 . V_61 ,
struct V_1 ,
V_25 ) ;
F_37 ( V_39 , V_60 ) ;
}
if ( V_48 > 0 )
V_39 -> V_47 . V_62 = V_48 ;
}
static void
F_51 ( struct V_17 * V_39 )
{
F_52 ( & V_39 -> V_63 ) ;
F_48 ( V_39 ) ;
F_53 ( & V_39 -> V_63 ) ;
}
static void F_54 ( unsigned long V_64 )
{
struct V_17 * V_18 = (struct V_17 * ) V_64 ;
F_51 ( V_18 ) ;
}
static struct V_1 *
F_55 ( struct V_17 * V_39 , int V_65 ,
int V_41 )
{
struct V_1 * V_52 , * V_53 , * V_66 = NULL ;
F_56 ( V_59 ) ;
int V_67 , V_68 = 0 ;
V_68:
V_67 = 0 ;
if ( V_68 == 0 )
V_52 = V_39 -> V_69 ;
else
V_52 = F_26 ( & V_39 -> V_70 ,
struct V_1 ,
V_71 ) ;
F_57 (
iter, _iter, &mv_chan->all_slots, slot_node) {
F_49 ( V_53 ) ;
F_49 ( & V_53 -> V_43 ) ;
if ( V_52 -> V_41 ) {
if ( V_68 )
break;
V_67 = 0 ;
continue;
}
if ( ! V_67 ++ )
V_66 = V_52 ;
if ( V_67 == V_65 ) {
struct V_1 * V_72 = NULL ;
struct V_1 * V_69 = NULL ;
V_52 = V_66 ;
while ( V_65 ) {
int V_73 ;
F_58 ( & V_52 -> V_43 ) ;
F_47 ( & V_52 -> V_25 , & V_59 ) ;
V_72 = V_52 ;
V_52 -> V_43 . V_48 = 0 ;
V_52 -> V_46 = V_65 ;
V_52 -> V_74 = NULL ;
for ( V_73 = 0 ; V_73 < V_41 ; V_73 ++ ) {
V_52 -> V_41 = V_41 - V_73 ;
V_69 = V_52 ;
V_52 = F_26 ( V_52 -> V_71 . V_61 ,
struct V_1 ,
V_71 ) ;
}
V_65 -= V_41 ;
}
V_72 -> V_51 = V_66 ;
V_72 -> V_43 . V_48 = - V_75 ;
F_59 ( & V_59 , & V_72 -> V_76 ) ;
V_39 -> V_69 = V_69 ;
F_5 ( V_66 ) ;
F_5 ( V_72 ) ;
return V_72 ;
}
}
if ( ! V_68 ++ )
goto V_68;
F_60 ( & V_39 -> V_77 ) ;
return NULL ;
}
static T_4
F_61 ( struct V_78 * V_79 )
{
struct V_1 * V_42 = F_62 ( V_79 ) ;
struct V_17 * V_39 = F_63 ( V_79 -> V_18 ) ;
struct V_1 * V_80 , * V_81 ;
T_4 V_48 ;
int V_82 = 1 ;
F_22 ( F_23 ( V_39 ) ,
L_9 ,
V_23 , V_42 , & V_42 -> V_43 ) ;
V_80 = V_42 -> V_51 ;
F_52 ( & V_39 -> V_63 ) ;
V_48 = F_64 ( V_79 ) ;
if ( F_50 ( & V_39 -> V_59 ) )
F_65 ( & V_42 -> V_76 , & V_39 -> V_59 ) ;
else {
V_82 = 0 ;
V_81 = F_26 ( V_39 -> V_59 . V_26 ,
struct V_1 ,
V_25 ) ;
F_65 ( & V_80 -> V_76 ,
& V_81 -> V_25 ) ;
if ( ! F_25 ( V_80 ) )
goto V_83;
F_22 ( F_23 ( V_39 ) , L_10 ,
V_81 -> V_43 . V_44 ) ;
F_3 ( V_81 , V_80 -> V_43 . V_44 ) ;
if ( ! F_34 ( V_39 ) ) {
T_1 V_57 = F_10 ( V_39 ) ;
if ( V_57 == V_81 -> V_43 . V_44 )
V_82 = 1 ;
}
}
if ( V_82 )
F_37 ( V_39 , V_80 ) ;
V_83:
F_53 ( & V_39 -> V_63 ) ;
return V_48 ;
}
static int F_66 ( struct V_84 * V_18 )
{
char * V_5 ;
int V_21 ;
struct V_17 * V_39 = F_63 ( V_18 ) ;
struct V_1 * V_40 = NULL ;
int V_85 = V_86 / V_87 ;
V_21 = V_39 -> V_88 ;
while ( V_21 < V_85 ) {
V_40 = F_67 ( sizeof( * V_40 ) , V_89 ) ;
if ( ! V_40 ) {
F_68 ( V_90 L_11
L_12 , V_21 ) ;
break;
}
V_5 = ( char * ) V_39 -> V_91 ;
V_40 -> V_5 = ( void * ) & V_5 [ V_21 * V_87 ] ;
F_69 ( & V_40 -> V_43 , V_18 ) ;
V_40 -> V_43 . V_92 = F_61 ;
F_70 ( & V_40 -> V_25 ) ;
F_70 ( & V_40 -> V_71 ) ;
F_70 ( & V_40 -> V_76 ) ;
V_5 = ( char * ) V_39 -> V_93 ;
V_40 -> V_43 . V_44 =
( T_2 ) & V_5 [ V_21 * V_87 ] ;
V_40 -> V_21 = V_21 ++ ;
F_52 ( & V_39 -> V_63 ) ;
V_39 -> V_88 = V_21 ;
F_47 ( & V_40 -> V_71 , & V_39 -> V_70 ) ;
F_53 ( & V_39 -> V_63 ) ;
}
if ( V_39 -> V_88 && ! V_39 -> V_69 )
V_39 -> V_69 = F_26 ( V_39 -> V_70 . V_61 ,
struct V_1 ,
V_71 ) ;
F_22 ( F_23 ( V_39 ) ,
L_13 ,
V_39 -> V_88 , V_39 -> V_69 ) ;
return V_39 -> V_88 ? : - V_94 ;
}
static struct V_78 *
F_71 ( struct V_84 * V_18 , T_2 V_95 , T_2 V_96 ,
T_3 V_13 , unsigned long V_3 )
{
struct V_17 * V_39 = F_63 ( V_18 ) ;
struct V_1 * V_42 , * V_80 ;
int V_46 ;
F_22 ( F_23 ( V_39 ) ,
L_14 ,
V_23 , V_95 , V_96 , V_13 , V_3 ) ;
if ( F_72 ( V_13 < V_97 ) )
return NULL ;
F_4 ( V_13 > V_98 ) ;
F_52 ( & V_39 -> V_63 ) ;
V_46 = F_73 ( V_13 ) ;
V_42 = F_55 ( V_39 , V_46 , 1 ) ;
if ( V_42 ) {
V_42 -> type = V_31 ;
V_42 -> V_43 . V_3 = V_3 ;
V_80 = V_42 -> V_51 ;
F_1 ( V_80 , V_3 ) ;
F_2 ( V_80 , V_13 ) ;
F_6 ( V_42 -> V_51 , V_95 ) ;
F_8 ( V_80 , 0 , V_96 ) ;
V_42 -> V_99 = 1 ;
V_42 -> V_100 = V_13 ;
}
F_53 ( & V_39 -> V_63 ) ;
F_22 ( F_23 ( V_39 ) ,
L_15 ,
V_23 , V_42 , V_42 ? & V_42 -> V_43 : NULL ) ;
return V_42 ? & V_42 -> V_43 : NULL ;
}
static struct V_78 *
F_74 ( struct V_84 * V_18 , T_2 V_95 , T_2 * V_96 ,
unsigned int V_38 , T_3 V_13 , unsigned long V_3 )
{
struct V_17 * V_39 = F_63 ( V_18 ) ;
struct V_1 * V_42 , * V_80 ;
int V_46 ;
if ( F_72 ( V_13 < V_97 ) )
return NULL ;
F_4 ( V_13 > V_98 ) ;
F_22 ( F_23 ( V_39 ) ,
L_16 ,
V_23 , V_38 , V_13 , V_95 , V_3 ) ;
F_52 ( & V_39 -> V_63 ) ;
V_46 = F_35 ( V_13 , V_38 ) ;
V_42 = F_55 ( V_39 , V_46 , 1 ) ;
if ( V_42 ) {
V_42 -> type = V_16 ;
V_42 -> V_43 . V_3 = V_3 ;
V_80 = V_42 -> V_51 ;
F_1 ( V_80 , V_3 ) ;
F_2 ( V_80 , V_13 ) ;
F_6 ( V_42 -> V_51 , V_95 ) ;
V_42 -> V_99 = V_38 ;
V_42 -> V_100 = V_13 ;
while ( V_38 -- )
F_8 ( V_80 , V_38 , V_96 [ V_38 ] ) ;
}
F_53 ( & V_39 -> V_63 ) ;
F_22 ( F_23 ( V_39 ) ,
L_17 ,
V_23 , V_42 , & V_42 -> V_43 ) ;
return V_42 ? & V_42 -> V_43 : NULL ;
}
static void F_75 ( struct V_84 * V_18 )
{
struct V_17 * V_39 = F_63 ( V_18 ) ;
struct V_1 * V_52 , * V_53 ;
int V_101 = 0 ;
F_51 ( V_39 ) ;
F_52 ( & V_39 -> V_63 ) ;
F_43 (iter, _iter, &mv_chan->chain,
chain_node) {
V_101 ++ ;
F_45 ( & V_52 -> V_25 ) ;
}
F_43 (iter, _iter, &mv_chan->completed_slots,
completed_node) {
V_101 ++ ;
F_45 ( & V_52 -> V_54 ) ;
}
F_76 (
iter, _iter, &mv_chan->all_slots, slot_node) {
F_45 ( & V_52 -> V_71 ) ;
F_77 ( V_52 ) ;
V_39 -> V_88 -- ;
}
V_39 -> V_69 = NULL ;
F_22 ( F_23 ( V_39 ) , L_18 ,
V_23 , V_39 -> V_88 ) ;
F_53 ( & V_39 -> V_63 ) ;
if ( V_101 )
F_29 ( F_23 ( V_39 ) ,
L_19 , V_101 ) ;
}
static enum V_102 F_78 ( struct V_84 * V_18 ,
T_4 V_48 ,
struct V_103 * V_104 )
{
struct V_17 * V_39 = F_63 ( V_18 ) ;
enum V_102 V_105 ;
V_105 = F_79 ( V_18 , V_48 , V_104 ) ;
if ( V_105 == V_106 ) {
F_42 ( V_39 ) ;
return V_105 ;
}
F_51 ( V_39 ) ;
return F_79 ( V_18 , V_48 , V_104 ) ;
}
static void F_80 ( struct V_17 * V_18 )
{
T_1 V_19 ;
V_19 = F_11 ( F_28 ( V_18 ) ) ;
F_29 ( F_23 ( V_18 ) , L_20 , V_19 ) ;
V_19 = F_11 ( F_33 ( V_18 ) ) ;
F_29 ( F_23 ( V_18 ) , L_21 , V_19 ) ;
V_19 = F_11 ( F_19 ( V_18 ) ) ;
F_29 ( F_23 ( V_18 ) , L_22 , V_19 ) ;
V_19 = F_11 ( F_17 ( V_18 ) ) ;
F_29 ( F_23 ( V_18 ) , L_23 , V_19 ) ;
V_19 = F_11 ( F_81 ( V_18 ) ) ;
F_29 ( F_23 ( V_18 ) , L_24 , V_19 ) ;
V_19 = F_11 ( F_82 ( V_18 ) ) ;
F_29 ( F_23 ( V_18 ) , L_25 , V_19 ) ;
}
static void F_83 ( struct V_17 * V_18 ,
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
F_80 ( V_18 ) ;
F_30 () ;
}
static T_5 F_84 ( int V_107 , void * V_64 )
{
struct V_17 * V_18 = V_64 ;
T_1 V_22 = F_18 ( V_18 ) ;
F_22 ( F_23 ( V_18 ) , L_28 , V_22 ) ;
if ( F_20 ( V_22 ) )
F_83 ( V_18 , V_22 ) ;
F_60 ( & V_18 -> V_77 ) ;
F_21 ( V_18 ) ;
return V_108 ;
}
static void F_38 ( struct V_84 * V_18 )
{
struct V_17 * V_39 = F_63 ( V_18 ) ;
if ( V_39 -> V_45 >= V_109 ) {
V_39 -> V_45 = 0 ;
F_32 ( V_39 ) ;
}
}
static int F_85 ( struct V_17 * V_39 )
{
int V_73 ;
void * V_96 , * V_95 ;
T_2 V_110 , V_111 ;
struct V_84 * V_84 ;
T_4 V_48 ;
struct V_78 * V_79 ;
struct V_112 * V_113 ;
int V_114 = 0 ;
V_96 = F_86 ( sizeof( V_115 ) * V_116 , V_89 ) ;
if ( ! V_96 )
return - V_94 ;
V_95 = F_67 ( sizeof( V_115 ) * V_116 , V_89 ) ;
if ( ! V_95 ) {
F_77 ( V_96 ) ;
return - V_94 ;
}
for ( V_73 = 0 ; V_73 < V_116 ; V_73 ++ )
( ( V_115 * ) V_96 ) [ V_73 ] = ( V_115 ) V_73 ;
V_84 = & V_39 -> V_47 ;
if ( F_66 ( V_84 ) < 1 ) {
V_114 = - V_117 ;
goto V_118;
}
V_113 = F_87 ( V_84 -> V_119 -> V_120 , 2 , V_89 ) ;
if ( ! V_113 ) {
V_114 = - V_94 ;
goto V_121;
}
V_110 = F_88 ( V_84 -> V_119 -> V_120 , F_89 ( V_96 ) , 0 ,
V_116 , V_122 ) ;
V_113 -> V_123 = 1 ;
V_113 -> V_11 [ 0 ] = V_110 ;
V_111 = F_88 ( V_84 -> V_119 -> V_120 , F_89 ( V_95 ) , 0 ,
V_116 , V_124 ) ;
V_113 -> V_125 = 1 ;
V_113 -> V_11 [ 1 ] = V_111 ;
V_113 -> V_13 = V_116 ;
V_79 = F_71 ( V_84 , V_111 , V_110 ,
V_116 , 0 ) ;
V_48 = F_61 ( V_79 ) ;
F_38 ( V_84 ) ;
F_58 ( V_79 ) ;
F_90 ( 1 ) ;
if ( F_78 ( V_84 , V_48 , NULL ) !=
V_106 ) {
F_29 ( V_84 -> V_119 -> V_120 ,
L_29 ) ;
V_114 = - V_117 ;
goto V_121;
}
F_91 ( V_84 -> V_119 -> V_120 , V_111 ,
V_116 , V_124 ) ;
if ( memcmp ( V_96 , V_95 , V_116 ) ) {
F_29 ( V_84 -> V_119 -> V_120 ,
L_30 ) ;
V_114 = - V_117 ;
goto V_121;
}
V_121:
F_92 ( V_113 ) ;
F_75 ( V_84 ) ;
V_118:
F_77 ( V_96 ) ;
F_77 ( V_95 ) ;
return V_114 ;
}
static int
F_93 ( struct V_17 * V_39 )
{
int V_73 , V_126 ;
struct V_127 * V_95 ;
struct V_127 * V_128 [ V_129 ] ;
T_2 V_130 [ V_129 ] ;
T_2 V_111 ;
struct V_78 * V_79 ;
struct V_112 * V_113 ;
struct V_84 * V_84 ;
T_4 V_48 ;
V_115 V_131 = 0 ;
T_1 V_132 ;
int V_114 = 0 ;
int V_133 = V_129 ;
for ( V_126 = 0 ; V_126 < V_133 ; V_126 ++ ) {
V_128 [ V_126 ] = F_94 ( V_89 ) ;
if ( ! V_128 [ V_126 ] ) {
while ( V_126 -- )
F_95 ( V_128 [ V_126 ] ) ;
return - V_94 ;
}
}
V_95 = F_94 ( V_89 ) ;
if ( ! V_95 ) {
while ( V_126 -- )
F_95 ( V_128 [ V_126 ] ) ;
return - V_94 ;
}
for ( V_126 = 0 ; V_126 < V_133 ; V_126 ++ ) {
V_115 * V_134 = F_96 ( V_128 [ V_126 ] ) ;
for ( V_73 = 0 ; V_73 < V_116 ; V_73 ++ )
V_134 [ V_73 ] = ( 1 << V_126 ) ;
}
for ( V_126 = 0 ; V_126 < V_133 ; V_126 ++ )
V_131 ^= ( V_115 ) ( 1 << V_126 ) ;
V_132 = ( V_131 << 24 ) | ( V_131 << 16 ) |
( V_131 << 8 ) | V_131 ;
memset ( F_96 ( V_95 ) , 0 , V_116 ) ;
V_84 = & V_39 -> V_47 ;
if ( F_66 ( V_84 ) < 1 ) {
V_114 = - V_117 ;
goto V_118;
}
V_113 = F_87 ( V_84 -> V_119 -> V_120 , V_133 + 1 ,
V_89 ) ;
if ( ! V_113 ) {
V_114 = - V_94 ;
goto V_121;
}
for ( V_73 = 0 ; V_73 < V_133 ; V_73 ++ ) {
V_113 -> V_11 [ V_73 ] = F_88 ( V_84 -> V_119 -> V_120 , V_128 [ V_73 ] ,
0 , V_116 , V_122 ) ;
V_130 [ V_73 ] = V_113 -> V_11 [ V_73 ] ;
V_113 -> V_123 ++ ;
}
V_113 -> V_11 [ V_133 ] = F_88 ( V_84 -> V_119 -> V_120 , V_95 , 0 , V_116 ,
V_124 ) ;
V_111 = V_113 -> V_11 [ V_133 ] ;
V_113 -> V_125 = 1 ;
V_113 -> V_13 = V_116 ;
V_79 = F_74 ( V_84 , V_111 , V_130 ,
V_133 , V_116 , 0 ) ;
V_48 = F_61 ( V_79 ) ;
F_38 ( V_84 ) ;
F_58 ( V_79 ) ;
F_90 ( 8 ) ;
if ( F_78 ( V_84 , V_48 , NULL ) !=
V_106 ) {
F_29 ( V_84 -> V_119 -> V_120 ,
L_31 ) ;
V_114 = - V_117 ;
goto V_121;
}
F_91 ( V_84 -> V_119 -> V_120 , V_111 ,
V_116 , V_124 ) ;
for ( V_73 = 0 ; V_73 < ( V_116 / sizeof( T_1 ) ) ; V_73 ++ ) {
T_1 * V_134 = F_96 ( V_95 ) ;
if ( V_134 [ V_73 ] != V_132 ) {
F_29 ( V_84 -> V_119 -> V_120 ,
L_32 ,
V_73 , V_134 [ V_73 ] , V_132 ) ;
V_114 = - V_117 ;
goto V_121;
}
}
V_121:
F_92 ( V_113 ) ;
F_75 ( V_84 ) ;
V_118:
V_126 = V_133 ;
while ( V_126 -- )
F_95 ( V_128 [ V_126 ] ) ;
F_95 ( V_95 ) ;
return V_114 ;
}
static int
F_97 ( struct V_84 * V_18 , enum V_135 V_136 ,
unsigned long V_137 )
{
return - V_138 ;
}
static int F_98 ( struct V_17 * V_39 )
{
struct V_84 * V_18 , * V_139 ;
struct V_119 * V_120 = V_39 -> V_140 . V_120 ;
F_99 ( & V_39 -> V_140 ) ;
F_100 ( V_120 , V_86 ,
V_39 -> V_91 , V_39 -> V_93 ) ;
F_43 (chan, _chan, &mv_chan->dmadev.channels,
device_node) {
F_45 ( & V_18 -> V_141 ) ;
}
F_101 ( V_39 -> V_107 , V_39 ) ;
return 0 ;
}
static struct V_17 *
F_102 ( struct V_142 * V_143 ,
struct V_144 * V_145 ,
int V_21 , T_6 V_146 , int V_107 )
{
int V_105 = 0 ;
struct V_17 * V_39 ;
struct V_147 * V_148 ;
V_39 = F_103 ( & V_145 -> V_120 , sizeof( * V_39 ) , V_89 ) ;
if ( ! V_39 )
return F_104 ( - V_94 ) ;
V_39 -> V_21 = V_21 ;
V_39 -> V_107 = V_107 ;
V_148 = & V_39 -> V_140 ;
V_39 -> V_91 =
F_105 ( & V_145 -> V_120 , V_86 ,
& V_39 -> V_93 , V_89 ) ;
if ( ! V_39 -> V_91 )
return F_104 ( - V_94 ) ;
V_148 -> V_146 = V_146 ;
F_70 ( & V_148 -> V_149 ) ;
V_148 -> V_150 = F_66 ;
V_148 -> V_151 = F_75 ;
V_148 -> V_152 = F_78 ;
V_148 -> V_153 = F_38 ;
V_148 -> V_154 = F_97 ;
V_148 -> V_120 = & V_145 -> V_120 ;
if ( F_106 ( V_31 , V_148 -> V_146 ) )
V_148 -> V_155 = F_71 ;
if ( F_106 ( V_16 , V_148 -> V_146 ) ) {
V_148 -> V_156 = 8 ;
V_148 -> V_157 = F_74 ;
}
V_39 -> V_158 = V_143 -> V_159 ;
V_39 -> V_160 = V_143 -> V_161 ;
F_107 ( & V_39 -> V_77 , F_54 , ( unsigned long )
V_39 ) ;
F_24 ( V_39 ) ;
V_105 = F_108 ( V_39 -> V_107 , F_84 ,
0 , F_109 ( & V_145 -> V_120 ) , V_39 ) ;
if ( V_105 )
goto V_162;
F_16 ( V_39 ) ;
F_27 ( V_39 , V_31 ) ;
F_110 ( & V_39 -> V_63 ) ;
F_70 ( & V_39 -> V_59 ) ;
F_70 ( & V_39 -> V_55 ) ;
F_70 ( & V_39 -> V_70 ) ;
V_39 -> V_47 . V_119 = V_148 ;
F_111 ( & V_39 -> V_47 ) ;
F_47 ( & V_39 -> V_47 . V_141 , & V_148 -> V_149 ) ;
if ( F_106 ( V_31 , V_148 -> V_146 ) ) {
V_105 = F_85 ( V_39 ) ;
F_22 ( & V_145 -> V_120 , L_33 , V_105 ) ;
if ( V_105 )
goto V_163;
}
if ( F_106 ( V_16 , V_148 -> V_146 ) ) {
V_105 = F_93 ( V_39 ) ;
F_22 ( & V_145 -> V_120 , L_34 , V_105 ) ;
if ( V_105 )
goto V_163;
}
F_112 ( & V_145 -> V_120 , L_35 ,
F_106 ( V_16 , V_148 -> V_146 ) ? L_36 : L_37 ,
F_106 ( V_31 , V_148 -> V_146 ) ? L_38 : L_37 ,
F_106 ( V_164 , V_148 -> V_146 ) ? L_39 : L_37 ) ;
F_113 ( V_148 ) ;
return V_39 ;
V_163:
F_101 ( V_39 -> V_107 , V_39 ) ;
V_162:
F_100 ( & V_145 -> V_120 , V_86 ,
V_39 -> V_91 , V_39 -> V_93 ) ;
return F_104 ( V_105 ) ;
}
static void
F_114 ( struct V_142 * V_143 ,
const struct V_165 * V_166 )
{
void T_7 * V_167 = V_143 -> V_161 ;
T_1 V_168 = 0 ;
int V_73 ;
for ( V_73 = 0 ; V_73 < 8 ; V_73 ++ ) {
F_115 ( 0 , V_167 + F_116 ( V_73 ) ) ;
F_115 ( 0 , V_167 + F_117 ( V_73 ) ) ;
if ( V_73 < 4 )
F_115 ( 0 , V_167 + F_118 ( V_73 ) ) ;
}
for ( V_73 = 0 ; V_73 < V_166 -> V_169 ; V_73 ++ ) {
const struct V_170 * V_171 = V_166 -> V_171 + V_73 ;
F_115 ( ( V_171 -> V_167 & 0xffff0000 ) |
( V_171 -> V_172 << 8 ) |
V_166 -> V_173 , V_167 + F_116 ( V_73 ) ) ;
F_115 ( ( V_171 -> V_174 - 1 ) & 0xffff0000 , V_167 + F_117 ( V_73 ) ) ;
V_168 |= ( 1 << V_73 ) ;
V_168 |= 3 << ( 16 + ( 2 * V_73 ) ) ;
}
F_115 ( V_168 , V_167 + F_119 ( 0 ) ) ;
F_115 ( V_168 , V_167 + F_119 ( 1 ) ) ;
F_115 ( 0 , V_167 + F_120 ( 0 ) ) ;
F_115 ( 0 , V_167 + F_120 ( 1 ) ) ;
}
static int F_121 ( struct V_144 * V_145 )
{
const struct V_165 * V_166 ;
struct V_142 * V_143 ;
struct V_175 * V_176 = F_122 ( & V_145 -> V_120 ) ;
struct V_177 * V_178 ;
int V_73 , V_105 ;
F_123 ( & V_145 -> V_120 , L_40 ) ;
V_143 = F_103 ( & V_145 -> V_120 , sizeof( * V_143 ) , V_89 ) ;
if ( ! V_143 )
return - V_94 ;
V_178 = F_124 ( V_145 , V_179 , 0 ) ;
if ( ! V_178 )
return - V_117 ;
V_143 -> V_159 = F_125 ( & V_145 -> V_120 , V_178 -> V_180 ,
F_126 ( V_178 ) ) ;
if ( ! V_143 -> V_159 )
return - V_75 ;
V_178 = F_124 ( V_145 , V_179 , 1 ) ;
if ( ! V_178 )
return - V_117 ;
V_143 -> V_161 = F_125 ( & V_145 -> V_120 , V_178 -> V_180 ,
F_126 ( V_178 ) ) ;
if ( ! V_143 -> V_161 )
return - V_75 ;
F_127 ( V_145 , V_143 ) ;
V_166 = F_128 () ;
if ( V_166 )
F_114 ( V_143 , V_166 ) ;
V_143 -> V_181 = F_129 ( & V_145 -> V_120 , NULL ) ;
if ( ! F_130 ( V_143 -> V_181 ) )
F_131 ( V_143 -> V_181 ) ;
if ( V_145 -> V_120 . V_182 ) {
struct V_141 * V_183 ;
int V_73 = 0 ;
F_132 (pdev->dev.of_node, np) {
struct V_17 * V_18 ;
T_6 V_146 ;
int V_107 ;
F_133 ( V_146 ) ;
if ( F_134 ( V_183 , L_41 ) )
F_135 ( V_31 , V_146 ) ;
if ( F_134 ( V_183 , L_42 ) )
F_135 ( V_16 , V_146 ) ;
if ( F_134 ( V_183 , L_43 ) )
F_135 ( V_164 , V_146 ) ;
V_107 = F_136 ( V_183 , 0 ) ;
if ( ! V_107 ) {
V_105 = - V_117 ;
goto V_184;
}
V_18 = F_102 ( V_143 , V_145 , V_73 ,
V_146 , V_107 ) ;
if ( F_130 ( V_18 ) ) {
V_105 = F_137 ( V_18 ) ;
F_138 ( V_107 ) ;
goto V_184;
}
V_143 -> V_149 [ V_73 ] = V_18 ;
V_73 ++ ;
}
} else if ( V_176 && V_176 -> V_149 ) {
for ( V_73 = 0 ; V_73 < V_185 ; V_73 ++ ) {
struct V_186 * V_187 ;
struct V_17 * V_18 ;
int V_107 ;
V_187 = & V_176 -> V_149 [ V_73 ] ;
if ( ! V_187 ) {
V_105 = - V_117 ;
goto V_184;
}
V_107 = F_139 ( V_145 , V_73 ) ;
if ( V_107 < 0 ) {
V_105 = V_107 ;
goto V_184;
}
V_18 = F_102 ( V_143 , V_145 , V_73 ,
V_187 -> V_146 , V_107 ) ;
if ( F_130 ( V_18 ) ) {
V_105 = F_137 ( V_18 ) ;
goto V_184;
}
V_143 -> V_149 [ V_73 ] = V_18 ;
}
}
return 0 ;
V_184:
for ( V_73 = 0 ; V_73 < V_185 ; V_73 ++ )
if ( V_143 -> V_149 [ V_73 ] ) {
F_98 ( V_143 -> V_149 [ V_73 ] ) ;
if ( V_145 -> V_120 . V_182 )
F_138 ( V_143 -> V_149 [ V_73 ] -> V_107 ) ;
}
if ( ! F_130 ( V_143 -> V_181 ) ) {
F_140 ( V_143 -> V_181 ) ;
F_141 ( V_143 -> V_181 ) ;
}
return V_105 ;
}
static int F_142 ( struct V_144 * V_145 )
{
struct V_142 * V_143 = F_143 ( V_145 ) ;
int V_73 ;
for ( V_73 = 0 ; V_73 < V_185 ; V_73 ++ ) {
if ( V_143 -> V_149 [ V_73 ] )
F_98 ( V_143 -> V_149 [ V_73 ] ) ;
}
if ( ! F_130 ( V_143 -> V_181 ) ) {
F_140 ( V_143 -> V_181 ) ;
F_141 ( V_143 -> V_181 ) ;
}
return 0 ;
}
static int T_8 F_144 ( void )
{
return F_145 ( & V_188 ) ;
}
