static struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_4 * * V_5 )
{
struct V_6 * V_7 ;
struct V_1 * V_8 = NULL ;
bool V_9 = V_5 [ V_10 ] ;
bool V_11 = V_5 [ V_12 ] ;
T_1 V_13 ;
int V_14 = - 1 ;
int V_15 = - 1 ;
F_2 () ;
if ( ! V_9 && ! V_11 )
return F_3 ( - V_16 ) ;
if ( V_9 )
V_15 = F_4 ( V_5 [ V_10 ] ) ;
if ( V_11 ) {
V_13 = F_5 ( V_5 [ V_12 ] ) ;
V_14 = V_13 >> 32 ;
}
F_6 (rdev, &cfg802154_rdev_list, list) {
struct V_1 * V_1 ;
if ( V_11 && V_7 -> V_14 != V_14 )
continue;
F_6 (wpan_dev, &rdev->wpan_dev_list, list) {
if ( V_9 && V_1 -> V_17 &&
V_1 -> V_17 -> V_18 == V_15 ) {
V_8 = V_1 ;
break;
}
if ( V_11 &&
V_1 -> V_19 == ( V_20 ) V_13 ) {
V_8 = V_1 ;
break;
}
}
if ( V_8 )
break;
}
if ( V_8 )
return V_8 ;
return F_3 ( - V_21 ) ;
}
static struct V_6 *
F_7 ( struct V_2 * V_3 , struct V_4 * * V_5 )
{
struct V_6 * V_7 = NULL , * V_22 ;
struct V_23 * V_17 ;
F_2 () ;
if ( ! V_5 [ V_24 ] &&
! V_5 [ V_10 ] &&
! V_5 [ V_12 ] )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_24 ] )
V_7 = F_8 (
F_4 ( V_5 [ V_24 ] ) ) ;
if ( V_5 [ V_12 ] ) {
T_1 V_13 = F_5 ( V_5 [ V_12 ] ) ;
struct V_1 * V_1 ;
bool V_25 = false ;
V_22 = F_8 ( V_13 >> 32 ) ;
if ( V_22 ) {
F_6 (wpan_dev, &tmp->wpan_dev_list, list) {
if ( V_1 -> V_19 != ( V_20 ) V_13 )
continue;
V_25 = true ;
break;
}
if ( ! V_25 )
V_22 = NULL ;
if ( V_7 && V_22 != V_7 )
return F_3 ( - V_16 ) ;
V_7 = V_22 ;
}
}
if ( V_5 [ V_10 ] ) {
int V_18 = F_4 ( V_5 [ V_10 ] ) ;
V_17 = F_9 ( V_3 , V_18 ) ;
if ( V_17 ) {
if ( V_17 -> V_26 )
V_22 = F_10 (
V_17 -> V_26 -> V_27 ) ;
else
V_22 = NULL ;
if ( ! V_22 )
return F_3 ( - V_16 ) ;
if ( V_7 && V_22 != V_7 )
return F_3 ( - V_16 ) ;
V_7 = V_22 ;
}
}
if ( ! V_7 )
return F_3 ( - V_21 ) ;
return V_7 ;
}
static struct V_6 *
F_11 ( struct V_2 * V_3 , struct V_28 * V_29 )
{
return F_7 ( V_3 , V_29 -> V_5 ) ;
}
static inline void * F_12 ( struct V_30 * V_31 , V_20 V_32 , V_20 V_33 ,
int V_34 , T_2 V_35 )
{
return F_13 ( V_31 , V_32 , V_33 , & V_36 , V_34 , V_35 ) ;
}
static int
F_14 ( struct V_6 * V_7 ,
struct V_30 * V_37 )
{
struct V_4 * V_38 ;
unsigned long V_39 ;
V_38 = F_15 ( V_37 , V_40 ) ;
if ( ! V_38 )
return - V_41 ;
for ( V_39 = 0 ; V_39 <= V_42 ; V_39 ++ ) {
if ( F_16 ( V_37 , V_43 ,
V_7 -> V_27 . V_44 [ V_39 ] ) )
return - V_41 ;
}
F_17 ( V_37 , V_38 ) ;
return 0 ;
}
static int F_18 ( struct V_6 * V_7 ,
enum V_45 V_35 ,
struct V_30 * V_37 , V_20 V_32 , V_20 V_33 ,
int V_34 )
{
void * V_46 ;
V_46 = F_12 ( V_37 , V_32 , V_33 , V_34 , V_35 ) ;
if ( ! V_46 )
return - V_41 ;
if ( F_16 ( V_37 , V_24 , V_7 -> V_14 ) ||
F_19 ( V_37 , V_47 ,
F_20 ( & V_7 -> V_27 ) ) ||
F_16 ( V_37 , V_48 ,
V_49 ) )
goto V_50;
if ( V_35 != V_51 )
goto V_52;
if ( F_21 ( V_37 , V_53 ,
V_7 -> V_27 . V_54 ) ||
F_21 ( V_37 , V_55 ,
V_7 -> V_27 . V_56 ) )
goto V_50;
if ( F_14 ( V_7 , V_37 ) )
goto V_50;
if ( F_21 ( V_37 , V_57 ,
V_7 -> V_27 . V_58 ) )
goto V_50;
if ( F_22 ( V_37 , V_59 ,
V_7 -> V_27 . V_60 ) )
goto V_50;
V_52:
return F_23 ( V_37 , V_46 ) ;
V_50:
F_24 ( V_37 , V_46 ) ;
return - V_61 ;
}
static int F_25 ( struct V_30 * V_31 ,
struct V_62 * V_63 ,
struct V_64 * V_65 )
{
struct V_4 * * V_66 = V_36 . V_67 ;
int V_68 = F_26 ( V_63 -> V_69 , V_70 + V_36 . V_71 ,
V_66 , V_36 . V_72 , V_73 ) ;
if ( V_68 )
return 0 ;
if ( V_66 [ V_24 ] )
V_65 -> V_74 = F_4 ( V_66 [ V_24 ] ) ;
if ( V_66 [ V_12 ] )
V_65 -> V_74 = F_5 ( V_66 [ V_12 ] ) >> 32 ;
if ( V_66 [ V_10 ] ) {
struct V_23 * V_17 ;
struct V_6 * V_7 ;
int V_15 = F_4 ( V_66 [ V_10 ] ) ;
V_17 = F_9 ( & V_75 , V_15 ) ;
if ( ! V_17 )
return - V_21 ;
if ( V_17 -> V_26 ) {
V_7 = F_10 (
V_17 -> V_26 -> V_27 ) ;
V_65 -> V_74 = V_7 -> V_14 ;
}
}
return 0 ;
}
static int
F_27 ( struct V_30 * V_31 , struct V_62 * V_63 )
{
int V_76 = 0 , V_68 ;
struct V_64 * V_65 = ( void * ) V_63 -> args [ 0 ] ;
struct V_6 * V_7 ;
F_28 () ;
if ( ! V_65 ) {
V_65 = F_29 ( sizeof( * V_65 ) , V_77 ) ;
if ( ! V_65 ) {
F_30 () ;
return - V_78 ;
}
V_65 -> V_74 = - 1 ;
V_68 = F_25 ( V_31 , V_63 , V_65 ) ;
if ( V_68 ) {
F_31 ( V_65 ) ;
F_30 () ;
return V_68 ;
}
V_63 -> args [ 0 ] = ( long ) V_65 ;
}
F_6 (rdev, &cfg802154_rdev_list, list) {
if ( ++ V_76 <= V_65 -> V_79 )
continue;
if ( V_65 -> V_74 != - 1 &&
V_65 -> V_74 != V_7 -> V_14 )
continue;
V_68 = F_18 ( V_7 ,
V_51 ,
V_31 ,
F_32 ( V_63 -> V_31 ) . V_32 ,
V_63 -> V_69 -> V_80 , V_81 ) ;
if ( V_68 < 0 ) {
if ( ( V_68 == - V_41 || V_68 == - V_61 ) &&
! V_31 -> V_82 && V_63 -> V_83 < 4096 ) {
V_63 -> V_83 = 4096 ;
F_30 () ;
return 1 ;
}
V_76 -- ;
break;
}
break;
}
F_30 () ;
V_65 -> V_79 = V_76 ;
return V_31 -> V_82 ;
}
static int F_33 ( struct V_62 * V_63 )
{
F_31 ( ( void * ) V_63 -> args [ 0 ] ) ;
return 0 ;
}
static int F_34 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_30 * V_37 ;
struct V_6 * V_7 = V_29 -> V_84 [ 0 ] ;
V_37 = F_35 ( V_85 , V_77 ) ;
if ( ! V_37 )
return - V_78 ;
if ( F_18 ( V_7 , V_51 , V_37 ,
V_29 -> V_86 , V_29 -> V_87 , 0 ) < 0 ) {
F_36 ( V_37 ) ;
return - V_41 ;
}
return F_37 ( V_37 , V_29 ) ;
}
static inline T_1 V_13 ( struct V_1 * V_1 )
{
return ( T_1 ) V_1 -> V_19 |
( ( T_1 ) F_10 ( V_1 -> V_27 ) -> V_14 << 32 ) ;
}
static int
F_38 ( struct V_30 * V_37 , V_20 V_32 , V_20 V_33 , int V_34 ,
struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_23 * V_88 = V_1 -> V_17 ;
void * V_46 ;
V_46 = F_12 ( V_37 , V_32 , V_33 , V_34 ,
V_89 ) ;
if ( ! V_46 )
return - 1 ;
if ( V_88 &&
( F_16 ( V_37 , V_10 , V_88 -> V_18 ) ||
F_19 ( V_37 , V_90 , V_88 -> V_91 ) ) )
goto V_50;
if ( F_16 ( V_37 , V_24 , V_7 -> V_14 ) ||
F_16 ( V_37 , V_92 , V_1 -> V_93 ) ||
F_39 ( V_37 , V_12 , V_13 ( V_1 ) ) ||
F_16 ( V_37 , V_48 ,
V_7 -> V_94 ^
( V_49 << 2 ) ) )
goto V_50;
if ( F_40 ( V_37 , V_95 ,
V_1 -> V_96 ) ||
F_41 ( V_37 , V_97 ,
V_1 -> V_98 ) ||
F_41 ( V_37 , V_99 , V_1 -> V_100 ) )
goto V_50;
if ( F_22 ( V_37 , V_101 ,
V_1 -> V_102 ) ||
F_21 ( V_37 , V_103 , V_1 -> V_104 ) ||
F_21 ( V_37 , V_105 ,
V_1 -> V_106 ) ||
F_21 ( V_37 , V_107 , V_1 -> V_108 ) )
goto V_50;
if ( F_21 ( V_37 , V_109 , V_1 -> V_110 ) )
goto V_50;
return F_23 ( V_37 , V_46 ) ;
V_50:
F_24 ( V_37 , V_46 ) ;
return - V_61 ;
}
static int
F_42 ( struct V_30 * V_31 , struct V_62 * V_63 )
{
int V_111 = 0 ;
int V_112 = 0 ;
int V_113 = V_63 -> args [ 0 ] ;
int V_114 = V_63 -> args [ 1 ] ;
struct V_6 * V_7 ;
struct V_1 * V_1 ;
F_28 () ;
F_6 (rdev, &cfg802154_rdev_list, list) {
if ( V_111 < V_113 ) {
V_111 ++ ;
continue;
}
V_112 = 0 ;
F_6 (wpan_dev, &rdev->wpan_dev_list, list) {
if ( V_112 < V_114 ) {
V_112 ++ ;
continue;
}
if ( F_38 ( V_31 , F_32 ( V_63 -> V_31 ) . V_32 ,
V_63 -> V_69 -> V_80 , V_81 ,
V_7 , V_1 ) < 0 ) {
goto V_115;
}
V_112 ++ ;
}
V_111 ++ ;
}
V_115:
F_30 () ;
V_63 -> args [ 0 ] = V_111 ;
V_63 -> args [ 1 ] = V_112 ;
return V_31 -> V_82 ;
}
static int F_43 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_30 * V_37 ;
struct V_6 * V_7 = V_29 -> V_84 [ 0 ] ;
struct V_1 * V_116 = V_29 -> V_84 [ 1 ] ;
V_37 = F_35 ( V_85 , V_77 ) ;
if ( ! V_37 )
return - V_78 ;
if ( F_38 ( V_37 , V_29 -> V_86 , V_29 -> V_87 , 0 ,
V_7 , V_116 ) < 0 ) {
F_36 ( V_37 ) ;
return - V_41 ;
}
return F_37 ( V_37 , V_29 ) ;
}
static int F_44 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_84 [ 0 ] ;
enum V_117 type = V_118 ;
T_3 V_96 = F_45 ( 0x0000000000000000ULL ) ;
if ( ! V_29 -> V_5 [ V_90 ] )
return - V_16 ;
if ( V_29 -> V_5 [ V_92 ] ) {
type = F_4 ( V_29 -> V_5 [ V_92 ] ) ;
if ( type > V_119 )
return - V_16 ;
}
if ( V_29 -> V_5 [ V_95 ] )
V_96 = ( V_120 T_3 ) F_5 (
V_29 -> V_5 [ V_95 ] ) ;
if ( ! V_7 -> V_121 -> V_122 )
return - V_123 ;
return F_46 ( V_7 ,
F_47 ( V_29 -> V_5 [ V_90 ] ) ,
type , V_96 ) ;
}
static int F_48 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_84 [ 0 ] ;
struct V_1 * V_1 = V_29 -> V_84 [ 1 ] ;
if ( ! V_7 -> V_121 -> V_124 )
return - V_123 ;
if ( ! V_1 -> V_17 )
V_29 -> V_84 [ 1 ] = NULL ;
return F_49 ( V_7 , V_1 ) ;
}
static int F_50 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_84 [ 0 ] ;
T_2 V_125 , V_39 ;
if ( ! V_29 -> V_5 [ V_53 ] ||
! V_29 -> V_5 [ V_55 ] )
return - V_16 ;
V_39 = F_51 ( V_29 -> V_5 [ V_53 ] ) ;
V_125 = F_51 ( V_29 -> V_5 [ V_55 ] ) ;
if ( V_39 > V_42 || V_125 > V_126 )
return - V_16 ;
return F_52 ( V_7 , V_39 , V_125 ) ;
}
static int F_53 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_84 [ 0 ] ;
struct V_23 * V_88 = V_29 -> V_84 [ 1 ] ;
struct V_1 * V_1 = V_88 -> V_26 ;
T_4 V_100 ;
if ( F_54 ( V_88 ) )
return - V_127 ;
if ( V_1 -> V_93 == V_128 )
return - V_16 ;
if ( ! V_29 -> V_5 [ V_99 ] )
return - V_16 ;
V_100 = F_55 ( V_29 -> V_5 [ V_99 ] ) ;
return F_56 ( V_7 , V_1 , V_100 ) ;
}
static int F_57 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_84 [ 0 ] ;
struct V_23 * V_88 = V_29 -> V_84 [ 1 ] ;
struct V_1 * V_1 = V_88 -> V_26 ;
T_4 V_98 ;
if ( F_54 ( V_88 ) )
return - V_127 ;
if ( V_1 -> V_93 == V_128 )
return - V_16 ;
if ( ! V_29 -> V_5 [ V_97 ] )
return - V_16 ;
V_98 = F_55 ( V_29 -> V_5 [ V_97 ] ) ;
return F_58 ( V_7 , V_1 , V_98 ) ;
}
static int
F_59 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_84 [ 0 ] ;
struct V_23 * V_88 = V_29 -> V_84 [ 1 ] ;
struct V_1 * V_1 = V_88 -> V_26 ;
T_2 V_108 , V_104 ;
if ( F_54 ( V_88 ) )
return - V_127 ;
if ( ! V_29 -> V_5 [ V_107 ] ||
! V_29 -> V_5 [ V_103 ] )
return - V_16 ;
V_108 = F_51 ( V_29 -> V_5 [ V_107 ] ) ;
V_104 = F_51 ( V_29 -> V_5 [ V_103 ] ) ;
if ( V_104 < 3 || V_104 > 8 || V_108 > V_104 )
return - V_16 ;
return F_60 ( V_7 , V_1 , V_108 , V_104 ) ;
}
static int
F_61 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_84 [ 0 ] ;
struct V_23 * V_88 = V_29 -> V_84 [ 1 ] ;
struct V_1 * V_1 = V_88 -> V_26 ;
T_2 V_129 ;
if ( F_54 ( V_88 ) )
return - V_127 ;
if ( ! V_29 -> V_5 [ V_105 ] )
return - V_16 ;
V_129 = F_51 (
V_29 -> V_5 [ V_105 ] ) ;
if ( V_129 > 5 )
return - V_16 ;
return F_62 ( V_7 , V_1 , V_129 ) ;
}
static int
F_63 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_84 [ 0 ] ;
struct V_23 * V_88 = V_29 -> V_84 [ 1 ] ;
struct V_1 * V_1 = V_88 -> V_26 ;
T_5 V_130 ;
if ( F_54 ( V_88 ) )
return - V_127 ;
if ( ! V_29 -> V_5 [ V_101 ] )
return - V_16 ;
V_130 = F_64 (
V_29 -> V_5 [ V_101 ] ) ;
if ( V_130 < - 1 || V_130 > 7 )
return - V_16 ;
return F_65 ( V_7 , V_1 , V_130 ) ;
}
static int F_66 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_84 [ 0 ] ;
struct V_23 * V_88 = V_29 -> V_84 [ 1 ] ;
struct V_1 * V_1 = V_88 -> V_26 ;
bool V_131 ;
if ( F_54 ( V_88 ) )
return - V_127 ;
if ( ! V_29 -> V_5 [ V_109 ] )
return - V_16 ;
V_131 = ! ! F_51 ( V_29 -> V_5 [ V_109 ] ) ;
return F_67 ( V_7 , V_1 , V_131 ) ;
}
static int F_68 ( const struct V_132 * V_121 , struct V_30 * V_31 ,
struct V_28 * V_29 )
{
struct V_6 * V_7 ;
struct V_1 * V_1 ;
struct V_23 * V_88 ;
bool V_133 = V_121 -> V_134 & V_135 ;
if ( V_133 )
F_28 () ;
if ( V_121 -> V_134 & V_136 ) {
V_7 = F_11 ( F_69 ( V_29 ) , V_29 ) ;
if ( F_70 ( V_7 ) ) {
if ( V_133 )
F_30 () ;
return F_71 ( V_7 ) ;
}
V_29 -> V_84 [ 0 ] = V_7 ;
} else if ( V_121 -> V_134 & V_137 ||
V_121 -> V_134 & V_138 ) {
F_2 () ;
V_1 = F_1 ( F_69 ( V_29 ) ,
V_29 -> V_5 ) ;
if ( F_70 ( V_1 ) ) {
if ( V_133 )
F_30 () ;
return F_71 ( V_1 ) ;
}
V_88 = V_1 -> V_17 ;
V_7 = F_10 ( V_1 -> V_27 ) ;
if ( V_121 -> V_134 & V_137 ) {
if ( ! V_88 ) {
if ( V_133 )
F_30 () ;
return - V_16 ;
}
V_29 -> V_84 [ 1 ] = V_88 ;
} else {
V_29 -> V_84 [ 1 ] = V_1 ;
}
if ( V_88 ) {
if ( V_121 -> V_134 & V_139 &&
! F_54 ( V_88 ) ) {
if ( V_133 )
F_30 () ;
return - V_140 ;
}
F_72 ( V_88 ) ;
}
V_29 -> V_84 [ 0 ] = V_7 ;
}
return 0 ;
}
static void F_73 ( const struct V_132 * V_121 , struct V_30 * V_31 ,
struct V_28 * V_29 )
{
if ( V_29 -> V_84 [ 1 ] ) {
if ( V_121 -> V_134 & V_138 ) {
struct V_1 * V_1 = V_29 -> V_84 [ 1 ] ;
if ( V_1 -> V_17 )
F_74 ( V_1 -> V_17 ) ;
} else {
F_74 ( V_29 -> V_84 [ 1 ] ) ;
}
}
if ( V_121 -> V_134 & V_135 )
F_30 () ;
}
int F_75 ( void )
{
return F_76 ( & V_36 , V_141 ,
V_142 ) ;
}
void F_77 ( void )
{
F_78 ( & V_36 ) ;
}
