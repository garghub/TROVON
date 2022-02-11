static struct V_1 * F_1 ( struct V_2 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 . V_7 ;
struct V_1 * V_8 = F_2 ( V_2 , NULL , V_3 ) , * V_9 ;
if ( V_8 )
return V_8 ;
V_8 = F_3 ( sizeof( struct V_1 ) , V_10 ) ;
if ( ! V_8 )
return F_4 ( - V_11 ) ;
F_5 ( & V_8 -> V_12 ) ;
F_5 ( & V_8 -> V_13 ) ;
F_6 ( & V_8 -> V_14 ) ;
V_8 -> V_15 = V_16 ;
F_7 ( & V_8 -> V_17 ) ;
V_8 -> V_3 = V_3 ;
F_8 ( & V_5 -> V_18 ) ;
F_9 (oldirq, &dist->lpi_list_head, lpi_list) {
if ( V_9 -> V_3 != V_3 )
continue;
F_10 ( V_8 ) ;
V_8 = V_9 ;
F_11 ( V_8 ) ;
goto V_19;
}
F_12 ( & V_8 -> V_12 , & V_5 -> V_20 ) ;
V_5 -> V_21 ++ ;
V_19:
F_13 ( & V_5 -> V_18 ) ;
return V_8 ;
}
static struct V_22 * F_14 ( struct V_23 * V_24 , T_1 V_25 )
{
struct V_22 * V_26 ;
F_9 (device, &its->device_list, dev_list)
if ( V_25 == V_26 -> V_25 )
return V_26 ;
return NULL ;
}
static struct V_27 * F_15 ( struct V_23 * V_24 , T_1 V_25 ,
T_1 V_28 )
{
struct V_22 * V_26 ;
struct V_27 * V_29 ;
V_26 = F_14 ( V_24 , V_25 ) ;
if ( V_26 == NULL )
return NULL ;
F_9 (itte, &device->itt_head, itte_list)
if ( V_29 -> V_28 == V_28 )
return V_29 ;
return NULL ;
}
static struct V_30 * F_16 ( struct V_23 * V_24 , int V_31 )
{
struct V_30 * V_32 ;
F_9 (collection, &its->collection_list, coll_list) {
if ( V_31 == V_32 -> V_33 )
return V_32 ;
}
return NULL ;
}
static int F_17 ( struct V_2 * V_2 , struct V_1 * V_8 ,
struct V_34 * V_35 )
{
T_2 V_36 = F_18 ( V_2 -> V_6 . V_7 . V_37 ) ;
T_3 V_38 ;
int V_39 ;
V_39 = F_19 ( V_2 , V_36 + V_8 -> V_3 - V_40 ,
& V_38 , 1 ) ;
if ( V_39 )
return V_39 ;
F_8 ( & V_8 -> V_14 ) ;
if ( ! V_35 || V_35 == V_8 -> V_41 ) {
V_8 -> V_42 = F_20 ( V_38 ) ;
V_8 -> V_43 = F_21 ( V_38 ) ;
F_22 ( V_2 , V_8 ) ;
} else {
F_13 ( & V_8 -> V_14 ) ;
}
return 0 ;
}
static int F_23 ( struct V_2 * V_2 , T_1 * * V_44 )
{
struct V_4 * V_5 = & V_2 -> V_6 . V_7 ;
struct V_1 * V_8 ;
T_1 * V_45 ;
int V_46 = V_5 -> V_21 , V_47 = 0 ;
V_45 = F_24 ( V_46 , sizeof( V_45 [ 0 ] ) , V_10 ) ;
if ( ! V_45 )
return - V_11 ;
F_8 ( & V_5 -> V_18 ) ;
F_9 (irq, &dist->lpi_list_head, lpi_list) {
V_45 [ V_47 ] = V_8 -> V_3 ;
if ( ++ V_47 == V_46 )
break;
}
F_13 ( & V_5 -> V_18 ) ;
* V_44 = V_45 ;
return V_46 ;
}
static void F_25 ( struct V_2 * V_2 , struct V_27 * V_29 )
{
struct V_34 * V_48 ;
if ( ! F_26 ( V_29 -> V_32 ) )
return;
V_48 = F_27 ( V_2 , V_29 -> V_32 -> V_49 ) ;
F_8 ( & V_29 -> V_8 -> V_14 ) ;
V_29 -> V_8 -> V_41 = V_48 ;
F_13 ( & V_29 -> V_8 -> V_14 ) ;
}
static void F_28 ( struct V_2 * V_2 , struct V_23 * V_24 ,
struct V_30 * V_50 )
{
struct V_22 * V_26 ;
struct V_27 * V_29 ;
F_29 (device, itte, its) {
if ( ! V_29 -> V_32 || V_50 != V_29 -> V_32 )
continue;
F_25 ( V_2 , V_29 ) ;
}
}
static T_1 F_30 ( T_2 V_37 )
{
int V_51 = ( V_37 & 0x1f ) + 1 ;
return 1U << F_31 ( V_51 , V_52 ) ;
}
static int F_32 ( struct V_34 * V_48 )
{
T_4 V_53 = F_33 ( V_48 -> V_6 . V_54 . V_55 ) ;
struct V_1 * V_8 ;
int V_56 = - 1 ;
int V_39 = 0 ;
T_1 * V_45 ;
int V_57 , V_47 ;
V_57 = F_23 ( V_48 -> V_2 , & V_45 ) ;
if ( V_57 < 0 )
return V_57 ;
for ( V_47 = 0 ; V_47 < V_57 ; V_47 ++ ) {
int V_58 , V_59 ;
T_3 V_60 ;
V_58 = V_45 [ V_47 ] / V_61 ;
V_59 = V_45 [ V_47 ] % V_61 ;
if ( V_58 != V_56 ) {
V_39 = F_19 ( V_48 -> V_2 , V_53 + V_58 ,
& V_60 , 1 ) ;
if ( V_39 ) {
F_10 ( V_45 ) ;
return V_39 ;
}
V_56 = V_58 ;
}
V_8 = F_2 ( V_48 -> V_2 , NULL , V_45 [ V_47 ] ) ;
F_8 ( & V_8 -> V_14 ) ;
V_8 -> V_62 = V_60 & ( 1U << V_59 ) ;
F_22 ( V_48 -> V_2 , V_8 ) ;
F_34 ( V_48 -> V_2 , V_8 ) ;
}
F_10 ( V_45 ) ;
return V_39 ;
}
static unsigned long F_35 ( struct V_2 * V_48 ,
struct V_23 * V_24 ,
T_4 V_63 , unsigned int V_64 )
{
T_1 V_65 = 0 ;
F_36 ( & V_24 -> V_66 ) ;
if ( V_24 -> V_67 == V_24 -> V_68 )
V_65 |= V_69 ;
if ( V_24 -> V_43 )
V_65 |= V_70 ;
F_37 ( & V_24 -> V_66 ) ;
return V_65 ;
}
static void F_38 ( struct V_2 * V_2 , struct V_23 * V_24 ,
T_4 V_63 , unsigned int V_64 ,
unsigned long V_71 )
{
V_24 -> V_43 = ! ! ( V_71 & V_70 ) ;
}
static unsigned long F_39 ( struct V_2 * V_2 ,
struct V_23 * V_24 ,
T_4 V_63 , unsigned int V_64 )
{
T_2 V_65 = V_72 ;
V_65 |= 0x0f << V_73 ;
V_65 |= 0x0f << V_74 ;
return F_40 ( V_65 , V_63 & 7 , V_64 ) ;
}
static unsigned long F_41 ( struct V_2 * V_2 ,
struct V_23 * V_24 ,
T_4 V_63 , unsigned int V_64 )
{
return ( V_75 << 24 ) | ( V_76 << 0 ) ;
}
static unsigned long F_42 ( struct V_2 * V_2 ,
struct V_23 * V_24 ,
T_4 V_63 , unsigned int V_64 )
{
switch ( V_63 & 0xffff ) {
case V_77 :
return 0x92 ;
case V_78 :
return 0xb4 ;
case V_79 :
return V_80 | 0x0b ;
case V_81 :
return 0x40 ;
case V_82 :
return 0x0d ;
case V_83 :
return 0xf0 ;
case V_84 :
return 0x05 ;
case V_85 :
return 0xb1 ;
}
return 0 ;
}
static int F_43 ( struct V_2 * V_2 , struct V_23 * V_24 ,
T_1 V_86 , T_1 V_87 )
{
struct V_34 * V_48 ;
struct V_27 * V_29 ;
if ( ! V_24 -> V_43 )
return - V_88 ;
V_29 = F_15 ( V_24 , V_86 , V_87 ) ;
if ( ! V_29 || ! F_26 ( V_29 -> V_32 ) )
return V_89 ;
V_48 = F_27 ( V_2 , V_29 -> V_32 -> V_49 ) ;
if ( ! V_48 )
return V_89 ;
if ( ! V_48 -> V_6 . V_54 . V_90 )
return - V_88 ;
F_8 ( & V_29 -> V_8 -> V_14 ) ;
V_29 -> V_8 -> V_62 = true ;
F_22 ( V_2 , V_29 -> V_8 ) ;
return 0 ;
}
static struct V_91 * F_44 ( struct V_92 * V_93 )
{
struct V_91 * V_94 ;
if ( V_93 -> V_95 != & V_96 )
return NULL ;
V_94 = F_45 ( V_93 , struct V_91 , V_93 ) ;
if ( V_94 -> V_97 != V_98 )
return NULL ;
return V_94 ;
}
int F_46 ( struct V_2 * V_2 , struct V_99 * V_100 )
{
T_2 V_101 ;
struct V_92 * V_102 ;
struct V_91 * V_94 ;
int V_39 ;
if ( ! F_47 ( V_2 ) )
return - V_103 ;
if ( ! ( V_100 -> V_104 & V_105 ) )
return - V_106 ;
V_101 = ( T_2 ) V_100 -> V_107 << 32 | V_100 -> V_108 ;
V_102 = F_48 ( V_2 , V_109 , V_101 ) ;
if ( ! V_102 )
return - V_106 ;
V_94 = F_44 ( V_102 ) ;
if ( ! V_94 )
return - V_106 ;
F_36 ( & V_94 -> V_24 -> V_110 ) ;
V_39 = F_43 ( V_2 , V_94 -> V_24 , V_100 -> V_86 , V_100 -> V_111 ) ;
F_37 ( & V_94 -> V_24 -> V_110 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_39 )
return 0 ;
else
return 1 ;
}
static void F_49 ( struct V_2 * V_2 , struct V_27 * V_29 )
{
F_50 ( & V_29 -> V_112 ) ;
if ( V_29 -> V_8 )
F_34 ( V_2 , V_29 -> V_8 ) ;
F_10 ( V_29 ) ;
}
static T_2 F_51 ( T_2 * V_113 , int V_114 , int V_115 , int V_116 )
{
return ( F_52 ( V_113 [ V_114 ] ) >> V_115 ) & ( F_53 ( V_116 ) - 1 ) ;
}
static int F_54 ( struct V_2 * V_2 , struct V_23 * V_24 ,
T_2 * V_113 )
{
T_1 V_25 = F_55 ( V_113 ) ;
T_1 V_28 = F_56 ( V_113 ) ;
struct V_27 * V_29 ;
V_29 = F_15 ( V_24 , V_25 , V_28 ) ;
if ( V_29 && V_29 -> V_32 ) {
F_49 ( V_2 , V_29 ) ;
return 0 ;
}
return V_117 ;
}
static int F_57 ( struct V_2 * V_2 , struct V_23 * V_24 ,
T_2 * V_113 )
{
T_1 V_25 = F_55 ( V_113 ) ;
T_1 V_28 = F_56 ( V_113 ) ;
T_1 V_31 = F_58 ( V_113 ) ;
struct V_34 * V_48 ;
struct V_27 * V_29 ;
struct V_30 * V_32 ;
V_29 = F_15 ( V_24 , V_25 , V_28 ) ;
if ( ! V_29 )
return V_118 ;
if ( ! F_26 ( V_29 -> V_32 ) )
return V_119 ;
V_32 = F_16 ( V_24 , V_31 ) ;
if ( ! F_26 ( V_32 ) )
return V_119 ;
V_29 -> V_32 = V_32 ;
V_48 = F_27 ( V_2 , V_32 -> V_49 ) ;
F_8 ( & V_29 -> V_8 -> V_14 ) ;
V_29 -> V_8 -> V_41 = V_48 ;
F_13 ( & V_29 -> V_8 -> V_14 ) ;
return 0 ;
}
static bool F_59 ( struct V_23 * V_24 , T_2 V_120 , int V_121 )
{
int V_122 = F_60 ( V_120 ) * V_123 ;
int V_124 ;
T_2 V_125 ;
T_5 V_126 ;
if ( ! ( V_120 & V_127 ) ) {
T_6 V_63 ;
if ( V_121 >= ( V_122 / F_61 ( V_120 ) ) )
return false ;
V_63 = F_62 ( V_120 ) + V_121 * F_61 ( V_120 ) ;
V_126 = V_63 >> V_128 ;
return F_63 ( V_24 -> V_93 -> V_2 , V_126 ) ;
}
V_124 = V_121 / ( V_123 / F_61 ( V_120 ) ) ;
if ( V_124 >= ( V_122 / sizeof( T_2 ) ) )
return false ;
if ( F_19 ( V_24 -> V_93 -> V_2 ,
F_62 ( V_120 ) + V_124 * sizeof( V_125 ) ,
& V_125 , sizeof( V_125 ) ) )
return false ;
V_125 = F_52 ( V_125 ) ;
if ( ! ( V_125 & F_53 ( 63 ) ) )
return false ;
V_125 &= F_64 ( 51 , 16 ) ;
V_124 = V_121 % ( V_123 / F_61 ( V_120 ) ) ;
V_125 += V_124 * F_61 ( V_120 ) ;
V_126 = V_125 >> V_128 ;
return F_63 ( V_24 -> V_93 -> V_2 , V_126 ) ;
}
static int F_65 ( struct V_23 * V_24 ,
struct V_30 * * V_129 ,
T_1 V_31 )
{
struct V_30 * V_32 ;
if ( ! F_59 ( V_24 , V_24 -> V_130 , V_31 ) )
return V_131 ;
V_32 = F_3 ( sizeof( * V_32 ) , V_10 ) ;
V_32 -> V_33 = V_31 ;
V_32 -> V_49 = V_132 ;
F_12 ( & V_32 -> V_133 , & V_24 -> V_134 ) ;
* V_129 = V_32 ;
return 0 ;
}
static void F_66 ( struct V_23 * V_24 , T_1 V_31 )
{
struct V_30 * V_32 ;
struct V_22 * V_26 ;
struct V_27 * V_29 ;
V_32 = F_16 ( V_24 , V_31 ) ;
if ( ! V_32 )
return;
F_29 (device, itte, its)
if ( V_29 -> V_32 &&
V_29 -> V_32 -> V_33 == V_31 )
V_29 -> V_32 = NULL ;
F_50 ( & V_32 -> V_133 ) ;
F_10 ( V_32 ) ;
}
static int F_67 ( struct V_2 * V_2 , struct V_23 * V_24 ,
T_2 * V_113 )
{
T_1 V_25 = F_55 ( V_113 ) ;
T_1 V_28 = F_56 ( V_113 ) ;
T_1 V_31 = F_58 ( V_113 ) ;
struct V_27 * V_29 ;
struct V_22 * V_26 ;
struct V_30 * V_32 , * V_135 = NULL ;
int V_136 ;
struct V_1 * V_8 ;
V_26 = F_14 ( V_24 , V_25 ) ;
if ( ! V_26 )
return V_137 ;
if ( F_68 ( V_113 ) == V_138 )
V_136 = F_69 ( V_113 ) ;
else
V_136 = V_28 ;
if ( V_136 < V_40 ||
V_136 >= F_30 ( V_2 -> V_6 . V_7 . V_37 ) )
return V_139 ;
if ( F_15 ( V_24 , V_25 , V_28 ) )
return 0 ;
V_32 = F_16 ( V_24 , V_31 ) ;
if ( ! V_32 ) {
int V_39 = F_65 ( V_24 , & V_32 , V_31 ) ;
if ( V_39 )
return V_39 ;
V_135 = V_32 ;
}
V_29 = F_3 ( sizeof( struct V_27 ) , V_10 ) ;
if ( ! V_29 ) {
if ( V_135 )
F_66 ( V_24 , V_31 ) ;
return - V_11 ;
}
V_29 -> V_28 = V_28 ;
F_12 ( & V_29 -> V_112 , & V_26 -> V_140 ) ;
V_29 -> V_32 = V_32 ;
V_29 -> V_141 = V_136 ;
V_8 = F_1 ( V_2 , V_136 ) ;
if ( F_70 ( V_8 ) ) {
if ( V_135 )
F_66 ( V_24 , V_31 ) ;
F_49 ( V_2 , V_29 ) ;
return F_71 ( V_8 ) ;
}
V_29 -> V_8 = V_8 ;
F_25 ( V_2 , V_29 ) ;
F_17 ( V_2 , V_29 -> V_8 , NULL ) ;
return 0 ;
}
static void F_72 ( struct V_2 * V_2 , struct V_22 * V_26 )
{
struct V_27 * V_29 , * V_142 ;
F_73 (itte, temp, &device->itt_head, itte_list)
F_49 ( V_2 , V_29 ) ;
F_50 ( & V_26 -> V_143 ) ;
F_10 ( V_26 ) ;
}
static int F_74 ( struct V_2 * V_2 , struct V_23 * V_24 ,
T_2 * V_113 )
{
T_1 V_25 = F_55 ( V_113 ) ;
bool V_144 = F_75 ( V_113 ) ;
struct V_22 * V_26 ;
if ( ! F_59 ( V_24 , V_24 -> V_145 , V_25 ) )
return V_146 ;
V_26 = F_14 ( V_24 , V_25 ) ;
if ( V_26 )
F_72 ( V_2 , V_26 ) ;
if ( ! V_144 )
return 0 ;
V_26 = F_3 ( sizeof( struct V_22 ) , V_10 ) ;
if ( ! V_26 )
return - V_11 ;
V_26 -> V_25 = V_25 ;
F_5 ( & V_26 -> V_140 ) ;
F_12 ( & V_26 -> V_143 , & V_24 -> V_147 ) ;
return 0 ;
}
static int F_76 ( struct V_2 * V_2 , struct V_23 * V_24 ,
T_2 * V_113 )
{
T_7 V_31 ;
T_1 V_49 ;
struct V_30 * V_32 ;
bool V_144 ;
V_144 = F_75 ( V_113 ) ;
V_31 = F_58 ( V_113 ) ;
V_49 = F_77 ( V_113 ) ;
if ( V_49 >= F_78 ( & V_2 -> V_148 ) )
return V_149 ;
if ( ! V_144 ) {
F_66 ( V_24 , V_31 ) ;
} else {
V_32 = F_16 ( V_24 , V_31 ) ;
if ( ! V_32 ) {
int V_39 ;
V_39 = F_65 ( V_24 , & V_32 ,
V_31 ) ;
if ( V_39 )
return V_39 ;
V_32 -> V_49 = V_49 ;
} else {
V_32 -> V_49 = V_49 ;
F_28 ( V_2 , V_24 , V_32 ) ;
}
}
return 0 ;
}
static int F_79 ( struct V_2 * V_2 , struct V_23 * V_24 ,
T_2 * V_113 )
{
T_1 V_25 = F_55 ( V_113 ) ;
T_1 V_28 = F_56 ( V_113 ) ;
struct V_27 * V_29 ;
V_29 = F_15 ( V_24 , V_25 , V_28 ) ;
if ( ! V_29 )
return V_150 ;
V_29 -> V_8 -> V_62 = false ;
return 0 ;
}
static int F_80 ( struct V_2 * V_2 , struct V_23 * V_24 ,
T_2 * V_113 )
{
T_1 V_25 = F_55 ( V_113 ) ;
T_1 V_28 = F_56 ( V_113 ) ;
struct V_27 * V_29 ;
V_29 = F_15 ( V_24 , V_25 , V_28 ) ;
if ( ! V_29 )
return V_151 ;
return F_17 ( V_2 , V_29 -> V_8 , NULL ) ;
}
static int F_81 ( struct V_2 * V_2 , struct V_23 * V_24 ,
T_2 * V_113 )
{
T_1 V_31 = F_58 ( V_113 ) ;
struct V_30 * V_32 ;
struct V_34 * V_48 ;
struct V_1 * V_8 ;
T_1 * V_45 ;
int V_46 , V_47 ;
V_32 = F_16 ( V_24 , V_31 ) ;
if ( ! F_26 ( V_32 ) )
return V_152 ;
V_48 = F_27 ( V_2 , V_32 -> V_49 ) ;
V_46 = F_23 ( V_2 , & V_45 ) ;
if ( V_46 < 0 )
return V_46 ;
for ( V_47 = 0 ; V_47 < V_46 ; V_47 ++ ) {
V_8 = F_2 ( V_2 , NULL , V_45 [ V_47 ] ) ;
if ( ! V_8 )
continue;
F_17 ( V_2 , V_8 , V_48 ) ;
F_34 ( V_2 , V_8 ) ;
}
F_10 ( V_45 ) ;
return 0 ;
}
static int F_82 ( struct V_2 * V_2 , struct V_23 * V_24 ,
T_2 * V_113 )
{
struct V_4 * V_5 = & V_2 -> V_6 . V_7 ;
T_1 V_153 = F_77 ( V_113 ) ;
T_1 V_154 = F_51 ( V_113 , 3 , 16 , 32 ) ;
struct V_34 * V_155 , * V_156 ;
struct V_1 * V_8 ;
if ( V_153 >= F_78 ( & V_2 -> V_148 ) ||
V_154 >= F_78 ( & V_2 -> V_148 ) )
return V_157 ;
if ( V_153 == V_154 )
return 0 ;
V_155 = F_27 ( V_2 , V_153 ) ;
V_156 = F_27 ( V_2 , V_154 ) ;
F_8 ( & V_5 -> V_18 ) ;
F_9 (irq, &dist->lpi_list_head, lpi_list) {
F_8 ( & V_8 -> V_14 ) ;
if ( V_8 -> V_41 == V_155 )
V_8 -> V_41 = V_156 ;
F_13 ( & V_8 -> V_14 ) ;
}
F_13 ( & V_5 -> V_18 ) ;
return 0 ;
}
static int F_83 ( struct V_2 * V_2 , struct V_23 * V_24 ,
T_2 * V_113 )
{
T_1 V_158 = F_56 ( V_113 ) ;
T_2 V_159 = F_55 ( V_113 ) ;
return F_43 ( V_2 , V_24 , V_159 , V_158 ) ;
}
static int F_84 ( struct V_2 * V_2 , struct V_23 * V_24 ,
T_2 * V_113 )
{
int V_39 = - V_103 ;
F_36 ( & V_24 -> V_110 ) ;
switch ( F_68 ( V_113 ) ) {
case V_160 :
V_39 = F_74 ( V_2 , V_24 , V_113 ) ;
break;
case V_161 :
V_39 = F_76 ( V_2 , V_24 , V_113 ) ;
break;
case V_162 :
V_39 = F_67 ( V_2 , V_24 , V_113 ) ;
break;
case V_138 :
V_39 = F_67 ( V_2 , V_24 , V_113 ) ;
break;
case V_163 :
V_39 = F_57 ( V_2 , V_24 , V_113 ) ;
break;
case V_164 :
V_39 = F_54 ( V_2 , V_24 , V_113 ) ;
break;
case V_165 :
V_39 = F_79 ( V_2 , V_24 , V_113 ) ;
break;
case V_166 :
V_39 = F_82 ( V_2 , V_24 , V_113 ) ;
break;
case V_167 :
V_39 = F_83 ( V_2 , V_24 , V_113 ) ;
break;
case V_168 :
V_39 = F_80 ( V_2 , V_24 , V_113 ) ;
break;
case V_169 :
V_39 = F_81 ( V_2 , V_24 , V_113 ) ;
break;
case V_170 :
V_39 = 0 ;
break;
}
F_37 ( & V_24 -> V_110 ) ;
return V_39 ;
}
static T_2 F_85 ( T_2 V_65 )
{
V_65 = F_86 ( V_65 , V_171 ,
V_172 ,
V_173 ) ;
V_65 = F_86 ( V_65 , V_174 ,
V_175 ,
V_176 ) ;
V_65 = F_86 ( V_65 , V_177 ,
V_178 ,
V_179 ) ;
V_65 &= ~ F_64 ( 15 , 12 ) ;
V_65 = ( V_65 & ~ V_180 ) | V_181 ;
return V_65 ;
}
static T_2 F_87 ( T_2 V_65 )
{
V_65 = F_86 ( V_65 , V_182 ,
V_183 ,
V_173 ) ;
V_65 = F_86 ( V_65 , V_184 ,
V_185 ,
V_176 ) ;
V_65 = F_86 ( V_65 , V_186 ,
V_187 ,
V_179 ) ;
V_65 &= ~ ( F_64 ( 51 , 48 ) | F_64 ( 15 , 12 ) ) ;
return V_65 ;
}
static unsigned long F_88 ( struct V_2 * V_2 ,
struct V_23 * V_24 ,
T_4 V_63 , unsigned int V_64 )
{
return F_40 ( V_24 -> V_188 , V_63 & 7 , V_64 ) ;
}
static void F_89 ( struct V_2 * V_2 , struct V_23 * V_24 ,
T_4 V_63 , unsigned int V_64 ,
unsigned long V_71 )
{
if ( V_24 -> V_43 )
return;
F_36 ( & V_24 -> V_66 ) ;
V_24 -> V_188 = F_90 ( V_24 -> V_188 , V_63 & 7 , V_64 , V_71 ) ;
V_24 -> V_188 = F_87 ( V_24 -> V_188 ) ;
V_24 -> V_67 = 0 ;
V_24 -> V_68 = V_24 -> V_67 ;
F_37 ( & V_24 -> V_66 ) ;
}
static void F_91 ( struct V_2 * V_2 , struct V_23 * V_24 ,
T_4 V_63 , unsigned int V_64 ,
unsigned long V_71 )
{
T_4 V_188 ;
T_2 V_189 [ 4 ] ;
T_1 V_65 ;
if ( ! V_24 )
return;
F_36 ( & V_24 -> V_66 ) ;
V_65 = F_90 ( V_24 -> V_68 , V_63 & 7 , V_64 , V_71 ) ;
V_65 = F_92 ( V_65 ) ;
if ( V_65 >= F_93 ( V_24 -> V_188 ) ) {
F_37 ( & V_24 -> V_66 ) ;
return;
}
V_24 -> V_68 = V_65 ;
V_188 = F_94 ( V_24 -> V_188 ) ;
while ( V_24 -> V_68 != V_24 -> V_67 ) {
int V_39 = F_19 ( V_2 , V_188 + V_24 -> V_67 ,
V_189 , V_190 ) ;
if ( ! V_39 )
F_84 ( V_2 , V_24 , V_189 ) ;
V_24 -> V_67 += V_190 ;
if ( V_24 -> V_67 == F_93 ( V_24 -> V_188 ) )
V_24 -> V_67 = 0 ;
}
F_37 ( & V_24 -> V_66 ) ;
}
static unsigned long F_95 ( struct V_2 * V_2 ,
struct V_23 * V_24 ,
T_4 V_63 , unsigned int V_64 )
{
return F_40 ( V_24 -> V_68 , V_63 & 0x7 , V_64 ) ;
}
static unsigned long F_96 ( struct V_2 * V_2 ,
struct V_23 * V_24 ,
T_4 V_63 , unsigned int V_64 )
{
return F_40 ( V_24 -> V_67 , V_63 & 0x7 , V_64 ) ;
}
static unsigned long F_97 ( struct V_2 * V_2 ,
struct V_23 * V_24 ,
T_4 V_63 , unsigned int V_64 )
{
T_2 V_65 ;
switch ( F_98 ( V_63 ) ) {
case 0 :
V_65 = V_24 -> V_145 ;
break;
case 1 :
V_65 = V_24 -> V_130 ;
break;
default:
V_65 = 0 ;
break;
}
return F_40 ( V_65 , V_63 & 7 , V_64 ) ;
}
static void F_99 ( struct V_2 * V_2 ,
struct V_23 * V_24 ,
T_4 V_63 , unsigned int V_64 ,
unsigned long V_71 )
{
T_2 V_191 , V_192 ;
T_2 V_65 , * V_193 , V_194 = 0 ;
if ( V_24 -> V_43 )
return;
switch ( F_98 ( V_63 ) ) {
case 0 :
V_193 = & V_24 -> V_145 ;
V_191 = 8 ;
V_192 = V_195 ;
break;
case 1 :
V_193 = & V_24 -> V_130 ;
V_191 = 8 ;
V_192 = V_196 ;
V_194 = V_127 ;
break;
default:
return;
}
V_65 = F_90 ( * V_193 , V_63 & 7 , V_64 , V_71 ) ;
V_65 &= ~ V_197 ;
V_65 &= ~ V_194 ;
V_65 |= ( V_191 - 1 ) << V_198 ;
V_65 |= V_192 << V_199 ;
V_65 = F_85 ( V_65 ) ;
* V_193 = V_65 ;
}
static void F_100 ( struct V_2 * V_2 , struct V_23 * V_24 ,
T_4 V_63 , unsigned int V_64 , unsigned long V_71 )
{
}
void F_101 ( struct V_34 * V_48 )
{
if ( ! ( V_48 -> V_6 . V_54 . V_55 & V_200 ) )
F_32 ( V_48 ) ;
}
static int F_102 ( struct V_2 * V_2 , struct V_23 * V_24 )
{
struct V_91 * V_94 = & V_24 -> V_94 ;
int V_39 ;
if ( ! V_24 -> V_201 )
return - V_88 ;
if ( F_103 ( V_24 -> V_202 ) )
return - V_203 ;
V_94 -> V_204 = V_205 ;
V_94 -> V_206 = F_104 ( V_205 ) ;
F_105 ( & V_94 -> V_93 , & V_96 ) ;
V_94 -> V_207 = V_24 -> V_202 ;
V_94 -> V_97 = V_98 ;
V_94 -> V_24 = V_24 ;
F_36 ( & V_2 -> V_208 ) ;
V_39 = F_106 ( V_2 , V_109 , V_94 -> V_207 ,
V_209 , & V_94 -> V_93 ) ;
F_37 ( & V_2 -> V_208 ) ;
return V_39 ;
}
static int F_107 ( struct V_210 * V_93 , T_1 type )
{
struct V_23 * V_24 ;
if ( type != V_211 )
return - V_103 ;
V_24 = F_3 ( sizeof( struct V_23 ) , V_10 ) ;
if ( ! V_24 )
return - V_11 ;
F_108 ( & V_24 -> V_110 ) ;
F_108 ( & V_24 -> V_66 ) ;
V_24 -> V_202 = V_212 ;
F_5 ( & V_24 -> V_147 ) ;
F_5 ( & V_24 -> V_134 ) ;
V_93 -> V_2 -> V_6 . V_7 . V_213 = true ;
V_24 -> V_201 = false ;
V_24 -> V_43 = false ;
V_24 -> V_93 = V_93 ;
V_24 -> V_145 = V_214 |
( ( T_2 ) V_195 << V_199 ) ;
V_24 -> V_130 = V_214 |
( ( T_2 ) V_196 << V_199 ) ;
V_93 -> V_2 -> V_6 . V_7 . V_37 = V_215 ;
V_93 -> V_216 = V_24 ;
return 0 ;
}
static void F_109 ( struct V_210 * V_217 )
{
struct V_2 * V_2 = V_217 -> V_2 ;
struct V_23 * V_24 = V_217 -> V_216 ;
struct V_22 * V_93 ;
struct V_27 * V_29 ;
struct V_218 * V_219 , * V_220 ;
struct V_218 * V_221 , * V_142 ;
if ( ! V_24 -> V_147 . V_222 )
return;
F_36 ( & V_24 -> V_110 ) ;
F_110 (dev_cur, dev_temp, &its->device_list) {
V_93 = F_45 ( V_219 , struct V_22 , V_143 ) ;
F_110 (cur, temp, &dev->itt_head) {
V_29 = ( F_45 ( V_221 , struct V_27 , V_112 ) ) ;
F_49 ( V_2 , V_29 ) ;
}
F_50 ( V_219 ) ;
F_10 ( V_93 ) ;
}
F_110 (cur, temp, &its->collection_list) {
F_50 ( V_221 ) ;
F_10 ( F_45 ( V_221 , struct V_30 , V_133 ) ) ;
}
F_37 ( & V_24 -> V_110 ) ;
F_10 ( V_24 ) ;
}
static int F_111 ( struct V_210 * V_93 ,
struct V_223 * V_224 )
{
switch ( V_224 -> V_225 ) {
case V_226 :
switch ( V_224 -> V_224 ) {
case V_227 :
return 0 ;
}
break;
case V_228 :
switch ( V_224 -> V_224 ) {
case V_229 :
return 0 ;
}
break;
}
return - V_203 ;
}
static int F_112 ( struct V_210 * V_93 ,
struct V_223 * V_224 )
{
struct V_23 * V_24 = V_93 -> V_216 ;
int V_39 ;
switch ( V_224 -> V_225 ) {
case V_226 : {
T_2 T_8 * V_230 = ( T_2 T_8 * ) ( long ) V_224 -> V_63 ;
unsigned long type = ( unsigned long ) V_224 -> V_224 ;
T_2 V_63 ;
if ( type != V_227 )
return - V_103 ;
if ( F_113 ( & V_63 , V_230 , sizeof( V_63 ) ) )
return - V_231 ;
V_39 = F_114 ( V_93 -> V_2 , & V_24 -> V_202 ,
V_63 , V_123 ) ;
if ( V_39 )
return V_39 ;
V_24 -> V_202 = V_63 ;
return 0 ;
}
case V_228 :
switch ( V_224 -> V_224 ) {
case V_229 :
V_24 -> V_201 = true ;
return 0 ;
}
break;
}
return - V_203 ;
}
static int F_115 ( struct V_210 * V_93 ,
struct V_223 * V_224 )
{
switch ( V_224 -> V_225 ) {
case V_226 : {
struct V_23 * V_24 = V_93 -> V_216 ;
T_2 V_63 = V_24 -> V_202 ;
T_2 T_8 * V_230 = ( T_2 T_8 * ) ( long ) V_224 -> V_63 ;
unsigned long type = ( unsigned long ) V_224 -> V_224 ;
if ( type != V_227 )
return - V_103 ;
if ( F_116 ( V_230 , & V_63 , sizeof( V_63 ) ) )
return - V_231 ;
break;
default:
return - V_203 ;
}
}
return 0 ;
}
int F_117 ( void )
{
return F_118 ( & V_232 ,
V_211 ) ;
}
int F_119 ( struct V_2 * V_2 )
{
struct V_210 * V_93 ;
int V_39 = 0 ;
F_9 (dev, &kvm->devices, vm_node) {
if ( V_93 -> V_95 != & V_232 )
continue;
V_39 = F_102 ( V_2 , V_93 -> V_216 ) ;
if ( V_39 )
return V_39 ;
}
return V_39 ;
}
