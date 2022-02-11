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
if ( F_16 ( V_37 , V_57 ,
V_7 -> V_27 . V_58 . V_59 ) )
goto V_50;
if ( V_7 -> V_27 . V_58 . V_59 == V_60 ) {
if ( F_16 ( V_37 , V_61 ,
V_7 -> V_27 . V_58 . V_62 ) )
goto V_50;
}
if ( F_22 ( V_37 , V_63 ,
V_7 -> V_27 . V_64 ) )
goto V_50;
V_52:
F_23 ( V_37 , V_46 ) ;
return 0 ;
V_50:
F_24 ( V_37 , V_46 ) ;
return - V_65 ;
}
static int F_25 ( struct V_30 * V_31 ,
struct V_66 * V_67 ,
struct V_68 * V_69 )
{
struct V_4 * * V_70 = V_36 . V_71 ;
int V_72 = F_26 ( V_67 -> V_73 , V_74 + V_36 . V_75 ,
V_70 , V_36 . V_76 , V_77 ) ;
if ( V_72 )
return 0 ;
if ( V_70 [ V_24 ] )
V_69 -> V_78 = F_4 ( V_70 [ V_24 ] ) ;
if ( V_70 [ V_12 ] )
V_69 -> V_78 = F_5 ( V_70 [ V_12 ] ) >> 32 ;
if ( V_70 [ V_10 ] ) {
struct V_23 * V_17 ;
struct V_6 * V_7 ;
int V_15 = F_4 ( V_70 [ V_10 ] ) ;
V_17 = F_9 ( & V_79 , V_15 ) ;
if ( ! V_17 )
return - V_21 ;
if ( V_17 -> V_26 ) {
V_7 = F_10 (
V_17 -> V_26 -> V_27 ) ;
V_69 -> V_78 = V_7 -> V_14 ;
}
}
return 0 ;
}
static int
F_27 ( struct V_30 * V_31 , struct V_66 * V_67 )
{
int V_80 = 0 , V_72 ;
struct V_68 * V_69 = ( void * ) V_67 -> args [ 0 ] ;
struct V_6 * V_7 ;
F_28 () ;
if ( ! V_69 ) {
V_69 = F_29 ( sizeof( * V_69 ) , V_81 ) ;
if ( ! V_69 ) {
F_30 () ;
return - V_82 ;
}
V_69 -> V_78 = - 1 ;
V_72 = F_25 ( V_31 , V_67 , V_69 ) ;
if ( V_72 ) {
F_31 ( V_69 ) ;
F_30 () ;
return V_72 ;
}
V_67 -> args [ 0 ] = ( long ) V_69 ;
}
F_6 (rdev, &cfg802154_rdev_list, list) {
if ( ++ V_80 <= V_69 -> V_83 )
continue;
if ( V_69 -> V_78 != - 1 &&
V_69 -> V_78 != V_7 -> V_14 )
continue;
V_72 = F_18 ( V_7 ,
V_51 ,
V_31 ,
F_32 ( V_67 -> V_31 ) . V_32 ,
V_67 -> V_73 -> V_84 , V_85 ) ;
if ( V_72 < 0 ) {
if ( ( V_72 == - V_41 || V_72 == - V_65 ) &&
! V_31 -> V_86 && V_67 -> V_87 < 4096 ) {
V_67 -> V_87 = 4096 ;
F_30 () ;
return 1 ;
}
V_80 -- ;
break;
}
break;
}
F_30 () ;
V_69 -> V_83 = V_80 ;
return V_31 -> V_86 ;
}
static int F_33 ( struct V_66 * V_67 )
{
F_31 ( ( void * ) V_67 -> args [ 0 ] ) ;
return 0 ;
}
static int F_34 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_30 * V_37 ;
struct V_6 * V_7 = V_29 -> V_88 [ 0 ] ;
V_37 = F_35 ( V_89 , V_81 ) ;
if ( ! V_37 )
return - V_82 ;
if ( F_18 ( V_7 , V_51 , V_37 ,
V_29 -> V_90 , V_29 -> V_91 , 0 ) < 0 ) {
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
struct V_23 * V_92 = V_1 -> V_17 ;
void * V_46 ;
V_46 = F_12 ( V_37 , V_32 , V_33 , V_34 ,
V_93 ) ;
if ( ! V_46 )
return - 1 ;
if ( V_92 &&
( F_16 ( V_37 , V_10 , V_92 -> V_18 ) ||
F_19 ( V_37 , V_94 , V_92 -> V_95 ) ) )
goto V_50;
if ( F_16 ( V_37 , V_24 , V_7 -> V_14 ) ||
F_16 ( V_37 , V_96 , V_1 -> V_97 ) ||
F_39 ( V_37 , V_12 , V_13 ( V_1 ) ) ||
F_16 ( V_37 , V_48 ,
V_7 -> V_98 ^
( V_49 << 2 ) ) )
goto V_50;
if ( F_40 ( V_37 , V_99 ,
V_1 -> V_100 ) ||
F_41 ( V_37 , V_101 ,
V_1 -> V_102 ) ||
F_41 ( V_37 , V_103 , V_1 -> V_104 ) )
goto V_50;
if ( F_22 ( V_37 , V_105 ,
V_1 -> V_106 ) ||
F_21 ( V_37 , V_107 , V_1 -> V_108 ) ||
F_21 ( V_37 , V_109 ,
V_1 -> V_110 ) ||
F_21 ( V_37 , V_111 , V_1 -> V_112 ) )
goto V_50;
if ( F_21 ( V_37 , V_113 , V_1 -> V_114 ) )
goto V_50;
F_23 ( V_37 , V_46 ) ;
return 0 ;
V_50:
F_24 ( V_37 , V_46 ) ;
return - V_65 ;
}
static int
F_42 ( struct V_30 * V_31 , struct V_66 * V_67 )
{
int V_115 = 0 ;
int V_116 = 0 ;
int V_117 = V_67 -> args [ 0 ] ;
int V_118 = V_67 -> args [ 1 ] ;
struct V_6 * V_7 ;
struct V_1 * V_1 ;
F_28 () ;
F_6 (rdev, &cfg802154_rdev_list, list) {
if ( V_115 < V_117 ) {
V_115 ++ ;
continue;
}
V_116 = 0 ;
F_6 (wpan_dev, &rdev->wpan_dev_list, list) {
if ( V_116 < V_118 ) {
V_116 ++ ;
continue;
}
if ( F_38 ( V_31 , F_32 ( V_67 -> V_31 ) . V_32 ,
V_67 -> V_73 -> V_84 , V_85 ,
V_7 , V_1 ) < 0 ) {
goto V_119;
}
V_116 ++ ;
}
V_115 ++ ;
}
V_119:
F_30 () ;
V_67 -> args [ 0 ] = V_115 ;
V_67 -> args [ 1 ] = V_116 ;
return V_31 -> V_86 ;
}
static int F_43 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_30 * V_37 ;
struct V_6 * V_7 = V_29 -> V_88 [ 0 ] ;
struct V_1 * V_120 = V_29 -> V_88 [ 1 ] ;
V_37 = F_35 ( V_89 , V_81 ) ;
if ( ! V_37 )
return - V_82 ;
if ( F_38 ( V_37 , V_29 -> V_90 , V_29 -> V_91 , 0 ,
V_7 , V_120 ) < 0 ) {
F_36 ( V_37 ) ;
return - V_41 ;
}
return F_37 ( V_37 , V_29 ) ;
}
static int F_44 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_88 [ 0 ] ;
enum V_121 type = V_122 ;
T_3 V_100 = F_45 ( 0x0000000000000000ULL ) ;
if ( ! V_29 -> V_5 [ V_94 ] )
return - V_16 ;
if ( V_29 -> V_5 [ V_96 ] ) {
type = F_4 ( V_29 -> V_5 [ V_96 ] ) ;
if ( type > V_123 )
return - V_16 ;
}
if ( V_29 -> V_5 [ V_99 ] )
V_100 = ( V_124 T_3 ) F_5 (
V_29 -> V_5 [ V_99 ] ) ;
if ( ! V_7 -> V_125 -> V_126 )
return - V_127 ;
return F_46 ( V_7 ,
F_47 ( V_29 -> V_5 [ V_94 ] ) ,
V_128 , type , V_100 ) ;
}
static int F_48 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_88 [ 0 ] ;
struct V_1 * V_1 = V_29 -> V_88 [ 1 ] ;
if ( ! V_7 -> V_125 -> V_129 )
return - V_127 ;
if ( ! V_1 -> V_17 )
V_29 -> V_88 [ 1 ] = NULL ;
return F_49 ( V_7 , V_1 ) ;
}
static int F_50 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_88 [ 0 ] ;
T_2 V_130 , V_39 ;
if ( ! V_29 -> V_5 [ V_53 ] ||
! V_29 -> V_5 [ V_55 ] )
return - V_16 ;
V_39 = F_51 ( V_29 -> V_5 [ V_53 ] ) ;
V_130 = F_51 ( V_29 -> V_5 [ V_55 ] ) ;
if ( V_39 > V_42 || V_130 > V_131 )
return - V_16 ;
return F_52 ( V_7 , V_39 , V_130 ) ;
}
static int F_53 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_88 [ 0 ] ;
struct V_132 V_58 ;
if ( ! V_29 -> V_5 [ V_57 ] )
return - V_16 ;
V_58 . V_59 = F_4 ( V_29 -> V_5 [ V_57 ] ) ;
if ( V_58 . V_59 < V_133 || V_58 . V_59 > V_134 )
return - V_16 ;
if ( V_58 . V_59 == V_60 ) {
if ( ! V_29 -> V_5 [ V_61 ] )
return - V_16 ;
V_58 . V_62 = F_4 ( V_29 -> V_5 [ V_61 ] ) ;
if ( V_58 . V_62 > V_135 )
return - V_16 ;
}
return F_54 ( V_7 , & V_58 ) ;
}
static int F_55 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_88 [ 0 ] ;
struct V_23 * V_92 = V_29 -> V_88 [ 1 ] ;
struct V_1 * V_1 = V_92 -> V_26 ;
T_4 V_104 ;
if ( F_56 ( V_92 ) )
return - V_136 ;
if ( V_1 -> V_97 == V_137 )
return - V_16 ;
if ( ! V_29 -> V_5 [ V_103 ] )
return - V_16 ;
V_104 = F_57 ( V_29 -> V_5 [ V_103 ] ) ;
return F_58 ( V_7 , V_1 , V_104 ) ;
}
static int F_59 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_88 [ 0 ] ;
struct V_23 * V_92 = V_29 -> V_88 [ 1 ] ;
struct V_1 * V_1 = V_92 -> V_26 ;
T_4 V_102 ;
if ( F_56 ( V_92 ) )
return - V_136 ;
if ( V_1 -> V_97 == V_137 )
return - V_16 ;
if ( ! V_29 -> V_5 [ V_101 ] )
return - V_16 ;
V_102 = F_57 ( V_29 -> V_5 [ V_101 ] ) ;
return F_60 ( V_7 , V_1 , V_102 ) ;
}
static int
F_61 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_88 [ 0 ] ;
struct V_23 * V_92 = V_29 -> V_88 [ 1 ] ;
struct V_1 * V_1 = V_92 -> V_26 ;
T_2 V_112 , V_108 ;
if ( F_56 ( V_92 ) )
return - V_136 ;
if ( ! V_29 -> V_5 [ V_111 ] ||
! V_29 -> V_5 [ V_107 ] )
return - V_16 ;
V_112 = F_51 ( V_29 -> V_5 [ V_111 ] ) ;
V_108 = F_51 ( V_29 -> V_5 [ V_107 ] ) ;
if ( V_108 < 3 || V_108 > 8 || V_112 > V_108 )
return - V_16 ;
return F_62 ( V_7 , V_1 , V_112 , V_108 ) ;
}
static int
F_63 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_88 [ 0 ] ;
struct V_23 * V_92 = V_29 -> V_88 [ 1 ] ;
struct V_1 * V_1 = V_92 -> V_26 ;
T_2 V_138 ;
if ( F_56 ( V_92 ) )
return - V_136 ;
if ( ! V_29 -> V_5 [ V_109 ] )
return - V_16 ;
V_138 = F_51 (
V_29 -> V_5 [ V_109 ] ) ;
if ( V_138 > 5 )
return - V_16 ;
return F_64 ( V_7 , V_1 , V_138 ) ;
}
static int
F_65 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_88 [ 0 ] ;
struct V_23 * V_92 = V_29 -> V_88 [ 1 ] ;
struct V_1 * V_1 = V_92 -> V_26 ;
T_5 V_139 ;
if ( F_56 ( V_92 ) )
return - V_136 ;
if ( ! V_29 -> V_5 [ V_105 ] )
return - V_16 ;
V_139 = F_66 (
V_29 -> V_5 [ V_105 ] ) ;
if ( V_139 < - 1 || V_139 > 7 )
return - V_16 ;
return F_67 ( V_7 , V_1 , V_139 ) ;
}
static int F_68 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_88 [ 0 ] ;
struct V_23 * V_92 = V_29 -> V_88 [ 1 ] ;
struct V_1 * V_1 = V_92 -> V_26 ;
bool V_59 ;
if ( F_56 ( V_92 ) )
return - V_136 ;
if ( ! V_29 -> V_5 [ V_113 ] )
return - V_16 ;
V_59 = ! ! F_51 ( V_29 -> V_5 [ V_113 ] ) ;
return F_69 ( V_7 , V_1 , V_59 ) ;
}
static int F_70 ( const struct V_140 * V_125 , struct V_30 * V_31 ,
struct V_28 * V_29 )
{
struct V_6 * V_7 ;
struct V_1 * V_1 ;
struct V_23 * V_92 ;
bool V_141 = V_125 -> V_142 & V_143 ;
if ( V_141 )
F_28 () ;
if ( V_125 -> V_142 & V_144 ) {
V_7 = F_11 ( F_71 ( V_29 ) , V_29 ) ;
if ( F_72 ( V_7 ) ) {
if ( V_141 )
F_30 () ;
return F_73 ( V_7 ) ;
}
V_29 -> V_88 [ 0 ] = V_7 ;
} else if ( V_125 -> V_142 & V_145 ||
V_125 -> V_142 & V_146 ) {
F_2 () ;
V_1 = F_1 ( F_71 ( V_29 ) ,
V_29 -> V_5 ) ;
if ( F_72 ( V_1 ) ) {
if ( V_141 )
F_30 () ;
return F_73 ( V_1 ) ;
}
V_92 = V_1 -> V_17 ;
V_7 = F_10 ( V_1 -> V_27 ) ;
if ( V_125 -> V_142 & V_145 ) {
if ( ! V_92 ) {
if ( V_141 )
F_30 () ;
return - V_16 ;
}
V_29 -> V_88 [ 1 ] = V_92 ;
} else {
V_29 -> V_88 [ 1 ] = V_1 ;
}
if ( V_92 ) {
if ( V_125 -> V_142 & V_147 &&
! F_56 ( V_92 ) ) {
if ( V_141 )
F_30 () ;
return - V_148 ;
}
F_74 ( V_92 ) ;
}
V_29 -> V_88 [ 0 ] = V_7 ;
}
return 0 ;
}
static void F_75 ( const struct V_140 * V_125 , struct V_30 * V_31 ,
struct V_28 * V_29 )
{
if ( V_29 -> V_88 [ 1 ] ) {
if ( V_125 -> V_142 & V_146 ) {
struct V_1 * V_1 = V_29 -> V_88 [ 1 ] ;
if ( V_1 -> V_17 )
F_76 ( V_1 -> V_17 ) ;
} else {
F_76 ( V_29 -> V_88 [ 1 ] ) ;
}
}
if ( V_125 -> V_142 & V_143 )
F_30 () ;
}
int F_77 ( void )
{
return F_78 ( & V_36 , V_149 ,
V_150 ) ;
}
void F_79 ( void )
{
F_80 ( & V_36 ) ;
}
