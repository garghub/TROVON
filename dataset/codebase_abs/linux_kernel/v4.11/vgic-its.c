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
static unsigned long F_35 ( struct V_2 * V_2 ,
struct V_23 * V_24 ,
T_4 V_63 , unsigned int V_64 )
{
T_2 V_65 = V_66 ;
V_65 |= 0x0f << V_67 ;
V_65 |= 0x0f << V_68 ;
return F_36 ( V_65 , V_63 & 7 , V_64 ) ;
}
static unsigned long F_37 ( struct V_2 * V_2 ,
struct V_23 * V_24 ,
T_4 V_63 , unsigned int V_64 )
{
return ( V_69 << 24 ) | ( V_70 << 0 ) ;
}
static unsigned long F_38 ( struct V_2 * V_2 ,
struct V_23 * V_24 ,
T_4 V_63 , unsigned int V_64 )
{
switch ( V_63 & 0xffff ) {
case V_71 :
return 0x92 ;
case V_72 :
return 0xb4 ;
case V_73 :
return V_74 | 0x0b ;
case V_75 :
return 0x40 ;
case V_76 :
return 0x0d ;
case V_77 :
return 0xf0 ;
case V_78 :
return 0x05 ;
case V_79 :
return 0xb1 ;
}
return 0 ;
}
static int F_39 ( struct V_2 * V_2 , struct V_23 * V_24 ,
T_1 V_80 , T_1 V_81 )
{
struct V_34 * V_48 ;
struct V_27 * V_29 ;
if ( ! V_24 -> V_43 )
return - V_82 ;
V_29 = F_15 ( V_24 , V_80 , V_81 ) ;
if ( ! V_29 || ! F_26 ( V_29 -> V_32 ) )
return V_83 ;
V_48 = F_27 ( V_2 , V_29 -> V_32 -> V_49 ) ;
if ( ! V_48 )
return V_83 ;
if ( ! V_48 -> V_6 . V_54 . V_84 )
return - V_82 ;
F_8 ( & V_29 -> V_8 -> V_14 ) ;
V_29 -> V_8 -> V_62 = true ;
F_22 ( V_2 , V_29 -> V_8 ) ;
return 0 ;
}
static struct V_85 * F_40 ( struct V_86 * V_87 )
{
struct V_85 * V_88 ;
if ( V_87 -> V_89 != & V_90 )
return NULL ;
V_88 = F_41 ( V_87 , struct V_85 , V_87 ) ;
if ( V_88 -> V_91 != V_92 )
return NULL ;
return V_88 ;
}
int F_42 ( struct V_2 * V_2 , struct V_93 * V_94 )
{
T_2 V_95 ;
struct V_86 * V_96 ;
struct V_85 * V_88 ;
int V_39 ;
if ( ! F_43 ( V_2 ) )
return - V_97 ;
if ( ! ( V_94 -> V_98 & V_99 ) )
return - V_100 ;
V_95 = ( T_2 ) V_94 -> V_101 << 32 | V_94 -> V_102 ;
V_96 = F_44 ( V_2 , V_103 , V_95 ) ;
if ( ! V_96 )
return - V_100 ;
V_88 = F_40 ( V_96 ) ;
if ( ! V_88 )
return - V_100 ;
F_45 ( & V_88 -> V_24 -> V_104 ) ;
V_39 = F_39 ( V_2 , V_88 -> V_24 , V_94 -> V_80 , V_94 -> V_105 ) ;
F_46 ( & V_88 -> V_24 -> V_104 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_39 )
return 0 ;
else
return 1 ;
}
static void F_47 ( struct V_2 * V_2 , struct V_27 * V_29 )
{
F_48 ( & V_29 -> V_106 ) ;
if ( V_29 -> V_8 )
F_34 ( V_2 , V_29 -> V_8 ) ;
F_10 ( V_29 ) ;
}
static T_2 F_49 ( T_2 * V_107 , int V_108 , int V_109 , int V_110 )
{
return ( F_50 ( V_107 [ V_108 ] ) >> V_109 ) & ( F_51 ( V_110 ) - 1 ) ;
}
static int F_52 ( struct V_2 * V_2 , struct V_23 * V_24 ,
T_2 * V_107 )
{
T_1 V_25 = F_53 ( V_107 ) ;
T_1 V_28 = F_54 ( V_107 ) ;
struct V_27 * V_29 ;
V_29 = F_15 ( V_24 , V_25 , V_28 ) ;
if ( V_29 && V_29 -> V_32 ) {
F_47 ( V_2 , V_29 ) ;
return 0 ;
}
return V_111 ;
}
static int F_55 ( struct V_2 * V_2 , struct V_23 * V_24 ,
T_2 * V_107 )
{
T_1 V_25 = F_53 ( V_107 ) ;
T_1 V_28 = F_54 ( V_107 ) ;
T_1 V_31 = F_56 ( V_107 ) ;
struct V_34 * V_48 ;
struct V_27 * V_29 ;
struct V_30 * V_32 ;
V_29 = F_15 ( V_24 , V_25 , V_28 ) ;
if ( ! V_29 )
return V_112 ;
if ( ! F_26 ( V_29 -> V_32 ) )
return V_113 ;
V_32 = F_16 ( V_24 , V_31 ) ;
if ( ! F_26 ( V_32 ) )
return V_113 ;
V_29 -> V_32 = V_32 ;
V_48 = F_27 ( V_2 , V_32 -> V_49 ) ;
F_8 ( & V_29 -> V_8 -> V_14 ) ;
V_29 -> V_8 -> V_41 = V_48 ;
F_13 ( & V_29 -> V_8 -> V_14 ) ;
return 0 ;
}
static bool F_57 ( struct V_23 * V_24 , T_2 V_114 , int V_115 )
{
int V_116 = F_58 ( V_114 ) * V_117 ;
int V_118 ;
T_2 V_119 ;
T_5 V_120 ;
int V_121 = F_59 ( V_114 ) ;
if ( ! ( V_114 & V_122 ) ) {
T_6 V_63 ;
if ( V_115 >= ( V_116 / V_121 ) )
return false ;
V_63 = F_60 ( V_114 ) + V_115 * V_121 ;
V_120 = V_63 >> V_123 ;
return F_61 ( V_24 -> V_87 -> V_2 , V_120 ) ;
}
V_118 = V_115 / ( V_117 / V_121 ) ;
if ( V_118 >= ( V_116 / sizeof( T_2 ) ) )
return false ;
if ( F_19 ( V_24 -> V_87 -> V_2 ,
F_60 ( V_114 ) + V_118 * sizeof( V_119 ) ,
& V_119 , sizeof( V_119 ) ) )
return false ;
V_119 = F_50 ( V_119 ) ;
if ( ! ( V_119 & F_51 ( 63 ) ) )
return false ;
V_119 &= F_62 ( 51 , 16 ) ;
V_118 = V_115 % ( V_117 / V_121 ) ;
V_119 += V_118 * V_121 ;
V_120 = V_119 >> V_123 ;
return F_61 ( V_24 -> V_87 -> V_2 , V_120 ) ;
}
static int F_63 ( struct V_23 * V_24 ,
struct V_30 * * V_124 ,
T_1 V_31 )
{
struct V_30 * V_32 ;
if ( ! F_57 ( V_24 , V_24 -> V_125 , V_31 ) )
return V_126 ;
V_32 = F_3 ( sizeof( * V_32 ) , V_10 ) ;
V_32 -> V_33 = V_31 ;
V_32 -> V_49 = V_127 ;
F_12 ( & V_32 -> V_128 , & V_24 -> V_129 ) ;
* V_124 = V_32 ;
return 0 ;
}
static void F_64 ( struct V_23 * V_24 , T_1 V_31 )
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
F_48 ( & V_32 -> V_128 ) ;
F_10 ( V_32 ) ;
}
static int F_65 ( struct V_2 * V_2 , struct V_23 * V_24 ,
T_2 * V_107 )
{
T_1 V_25 = F_53 ( V_107 ) ;
T_1 V_28 = F_54 ( V_107 ) ;
T_1 V_31 = F_56 ( V_107 ) ;
struct V_27 * V_29 ;
struct V_22 * V_26 ;
struct V_30 * V_32 , * V_130 = NULL ;
int V_131 ;
struct V_1 * V_8 ;
V_26 = F_14 ( V_24 , V_25 ) ;
if ( ! V_26 )
return V_132 ;
if ( F_66 ( V_107 ) == V_133 )
V_131 = F_67 ( V_107 ) ;
else
V_131 = V_28 ;
if ( V_131 < V_40 ||
V_131 >= F_30 ( V_2 -> V_6 . V_7 . V_37 ) )
return V_134 ;
if ( F_15 ( V_24 , V_25 , V_28 ) )
return 0 ;
V_32 = F_16 ( V_24 , V_31 ) ;
if ( ! V_32 ) {
int V_39 = F_63 ( V_24 , & V_32 , V_31 ) ;
if ( V_39 )
return V_39 ;
V_130 = V_32 ;
}
V_29 = F_3 ( sizeof( struct V_27 ) , V_10 ) ;
if ( ! V_29 ) {
if ( V_130 )
F_64 ( V_24 , V_31 ) ;
return - V_11 ;
}
V_29 -> V_28 = V_28 ;
F_12 ( & V_29 -> V_106 , & V_26 -> V_135 ) ;
V_29 -> V_32 = V_32 ;
V_29 -> V_136 = V_131 ;
V_8 = F_1 ( V_2 , V_131 ) ;
if ( F_68 ( V_8 ) ) {
if ( V_130 )
F_64 ( V_24 , V_31 ) ;
F_47 ( V_2 , V_29 ) ;
return F_69 ( V_8 ) ;
}
V_29 -> V_8 = V_8 ;
F_25 ( V_2 , V_29 ) ;
F_17 ( V_2 , V_29 -> V_8 , NULL ) ;
return 0 ;
}
static void F_70 ( struct V_2 * V_2 , struct V_22 * V_26 )
{
struct V_27 * V_29 , * V_137 ;
F_71 (itte, temp, &device->itt_head, itte_list)
F_47 ( V_2 , V_29 ) ;
F_48 ( & V_26 -> V_138 ) ;
F_10 ( V_26 ) ;
}
static int F_72 ( struct V_2 * V_2 , struct V_23 * V_24 ,
T_2 * V_107 )
{
T_1 V_25 = F_53 ( V_107 ) ;
bool V_139 = F_73 ( V_107 ) ;
struct V_22 * V_26 ;
if ( ! F_57 ( V_24 , V_24 -> V_140 , V_25 ) )
return V_141 ;
V_26 = F_14 ( V_24 , V_25 ) ;
if ( V_26 )
F_70 ( V_2 , V_26 ) ;
if ( ! V_139 )
return 0 ;
V_26 = F_3 ( sizeof( struct V_22 ) , V_10 ) ;
if ( ! V_26 )
return - V_11 ;
V_26 -> V_25 = V_25 ;
F_5 ( & V_26 -> V_135 ) ;
F_12 ( & V_26 -> V_138 , & V_24 -> V_142 ) ;
return 0 ;
}
static int F_74 ( struct V_2 * V_2 , struct V_23 * V_24 ,
T_2 * V_107 )
{
T_7 V_31 ;
T_1 V_49 ;
struct V_30 * V_32 ;
bool V_139 ;
V_139 = F_73 ( V_107 ) ;
V_31 = F_56 ( V_107 ) ;
V_49 = F_75 ( V_107 ) ;
if ( V_49 >= F_76 ( & V_2 -> V_143 ) )
return V_144 ;
if ( ! V_139 ) {
F_64 ( V_24 , V_31 ) ;
} else {
V_32 = F_16 ( V_24 , V_31 ) ;
if ( ! V_32 ) {
int V_39 ;
V_39 = F_63 ( V_24 , & V_32 ,
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
static int F_77 ( struct V_2 * V_2 , struct V_23 * V_24 ,
T_2 * V_107 )
{
T_1 V_25 = F_53 ( V_107 ) ;
T_1 V_28 = F_54 ( V_107 ) ;
struct V_27 * V_29 ;
V_29 = F_15 ( V_24 , V_25 , V_28 ) ;
if ( ! V_29 )
return V_145 ;
V_29 -> V_8 -> V_62 = false ;
return 0 ;
}
static int F_78 ( struct V_2 * V_2 , struct V_23 * V_24 ,
T_2 * V_107 )
{
T_1 V_25 = F_53 ( V_107 ) ;
T_1 V_28 = F_54 ( V_107 ) ;
struct V_27 * V_29 ;
V_29 = F_15 ( V_24 , V_25 , V_28 ) ;
if ( ! V_29 )
return V_146 ;
return F_17 ( V_2 , V_29 -> V_8 , NULL ) ;
}
static int F_79 ( struct V_2 * V_2 , struct V_23 * V_24 ,
T_2 * V_107 )
{
T_1 V_31 = F_56 ( V_107 ) ;
struct V_30 * V_32 ;
struct V_34 * V_48 ;
struct V_1 * V_8 ;
T_1 * V_45 ;
int V_46 , V_47 ;
V_32 = F_16 ( V_24 , V_31 ) ;
if ( ! F_26 ( V_32 ) )
return V_147 ;
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
static int F_80 ( struct V_2 * V_2 , struct V_23 * V_24 ,
T_2 * V_107 )
{
struct V_4 * V_5 = & V_2 -> V_6 . V_7 ;
T_1 V_148 = F_75 ( V_107 ) ;
T_1 V_149 = F_49 ( V_107 , 3 , 16 , 32 ) ;
struct V_34 * V_150 , * V_151 ;
struct V_1 * V_8 ;
if ( V_148 >= F_76 ( & V_2 -> V_143 ) ||
V_149 >= F_76 ( & V_2 -> V_143 ) )
return V_152 ;
if ( V_148 == V_149 )
return 0 ;
V_150 = F_27 ( V_2 , V_148 ) ;
V_151 = F_27 ( V_2 , V_149 ) ;
F_8 ( & V_5 -> V_18 ) ;
F_9 (irq, &dist->lpi_list_head, lpi_list) {
F_8 ( & V_8 -> V_14 ) ;
if ( V_8 -> V_41 == V_150 )
V_8 -> V_41 = V_151 ;
F_13 ( & V_8 -> V_14 ) ;
}
F_13 ( & V_5 -> V_18 ) ;
return 0 ;
}
static int F_81 ( struct V_2 * V_2 , struct V_23 * V_24 ,
T_2 * V_107 )
{
T_1 V_153 = F_54 ( V_107 ) ;
T_2 V_154 = F_53 ( V_107 ) ;
return F_39 ( V_2 , V_24 , V_154 , V_153 ) ;
}
static int F_82 ( struct V_2 * V_2 , struct V_23 * V_24 ,
T_2 * V_107 )
{
int V_39 = - V_97 ;
F_45 ( & V_24 -> V_104 ) ;
switch ( F_66 ( V_107 ) ) {
case V_155 :
V_39 = F_72 ( V_2 , V_24 , V_107 ) ;
break;
case V_156 :
V_39 = F_74 ( V_2 , V_24 , V_107 ) ;
break;
case V_157 :
V_39 = F_65 ( V_2 , V_24 , V_107 ) ;
break;
case V_133 :
V_39 = F_65 ( V_2 , V_24 , V_107 ) ;
break;
case V_158 :
V_39 = F_55 ( V_2 , V_24 , V_107 ) ;
break;
case V_159 :
V_39 = F_52 ( V_2 , V_24 , V_107 ) ;
break;
case V_160 :
V_39 = F_77 ( V_2 , V_24 , V_107 ) ;
break;
case V_161 :
V_39 = F_80 ( V_2 , V_24 , V_107 ) ;
break;
case V_162 :
V_39 = F_81 ( V_2 , V_24 , V_107 ) ;
break;
case V_163 :
V_39 = F_78 ( V_2 , V_24 , V_107 ) ;
break;
case V_164 :
V_39 = F_79 ( V_2 , V_24 , V_107 ) ;
break;
case V_165 :
V_39 = 0 ;
break;
}
F_46 ( & V_24 -> V_104 ) ;
return V_39 ;
}
static T_2 F_83 ( T_2 V_65 )
{
V_65 = F_84 ( V_65 , V_166 ,
V_167 ,
V_168 ) ;
V_65 = F_84 ( V_65 , V_169 ,
V_170 ,
V_171 ) ;
V_65 = F_84 ( V_65 , V_172 ,
V_173 ,
V_174 ) ;
V_65 &= ~ F_62 ( 15 , 12 ) ;
V_65 = ( V_65 & ~ V_175 ) | V_176 ;
return V_65 ;
}
static T_2 F_85 ( T_2 V_65 )
{
V_65 = F_84 ( V_65 , V_177 ,
V_178 ,
V_168 ) ;
V_65 = F_84 ( V_65 , V_179 ,
V_180 ,
V_171 ) ;
V_65 = F_84 ( V_65 , V_181 ,
V_182 ,
V_174 ) ;
V_65 &= ~ ( F_62 ( 51 , 48 ) | F_62 ( 15 , 12 ) ) ;
return V_65 ;
}
static unsigned long F_86 ( struct V_2 * V_2 ,
struct V_23 * V_24 ,
T_4 V_63 , unsigned int V_64 )
{
return F_36 ( V_24 -> V_183 , V_63 & 7 , V_64 ) ;
}
static void F_87 ( struct V_2 * V_2 , struct V_23 * V_24 ,
T_4 V_63 , unsigned int V_64 ,
unsigned long V_184 )
{
if ( V_24 -> V_43 )
return;
F_45 ( & V_24 -> V_185 ) ;
V_24 -> V_183 = F_88 ( V_24 -> V_183 , V_63 & 7 , V_64 , V_184 ) ;
V_24 -> V_183 = F_85 ( V_24 -> V_183 ) ;
V_24 -> V_186 = 0 ;
V_24 -> V_187 = V_24 -> V_186 ;
F_46 ( & V_24 -> V_185 ) ;
}
static void F_89 ( struct V_2 * V_2 , struct V_23 * V_24 )
{
T_4 V_183 ;
T_2 V_188 [ 4 ] ;
if ( ! V_24 -> V_43 )
return;
V_183 = F_90 ( V_24 -> V_183 ) ;
while ( V_24 -> V_187 != V_24 -> V_186 ) {
int V_39 = F_19 ( V_2 , V_183 + V_24 -> V_186 ,
V_188 , V_189 ) ;
if ( ! V_39 )
F_82 ( V_2 , V_24 , V_188 ) ;
V_24 -> V_186 += V_189 ;
if ( V_24 -> V_186 == F_91 ( V_24 -> V_183 ) )
V_24 -> V_186 = 0 ;
}
}
static void F_92 ( struct V_2 * V_2 , struct V_23 * V_24 ,
T_4 V_63 , unsigned int V_64 ,
unsigned long V_184 )
{
T_2 V_65 ;
if ( ! V_24 )
return;
F_45 ( & V_24 -> V_185 ) ;
V_65 = F_88 ( V_24 -> V_187 , V_63 & 7 , V_64 , V_184 ) ;
V_65 = F_93 ( V_65 ) ;
if ( V_65 >= F_91 ( V_24 -> V_183 ) ) {
F_46 ( & V_24 -> V_185 ) ;
return;
}
V_24 -> V_187 = V_65 ;
F_89 ( V_2 , V_24 ) ;
F_46 ( & V_24 -> V_185 ) ;
}
static unsigned long F_94 ( struct V_2 * V_2 ,
struct V_23 * V_24 ,
T_4 V_63 , unsigned int V_64 )
{
return F_36 ( V_24 -> V_187 , V_63 & 0x7 , V_64 ) ;
}
static unsigned long F_95 ( struct V_2 * V_2 ,
struct V_23 * V_24 ,
T_4 V_63 , unsigned int V_64 )
{
return F_36 ( V_24 -> V_186 , V_63 & 0x7 , V_64 ) ;
}
static unsigned long F_96 ( struct V_2 * V_2 ,
struct V_23 * V_24 ,
T_4 V_63 , unsigned int V_64 )
{
T_2 V_65 ;
switch ( F_97 ( V_63 ) ) {
case 0 :
V_65 = V_24 -> V_140 ;
break;
case 1 :
V_65 = V_24 -> V_125 ;
break;
default:
V_65 = 0 ;
break;
}
return F_36 ( V_65 , V_63 & 7 , V_64 ) ;
}
static void F_98 ( struct V_2 * V_2 ,
struct V_23 * V_24 ,
T_4 V_63 , unsigned int V_64 ,
unsigned long V_184 )
{
T_2 V_190 , V_191 ;
T_2 V_65 , * V_192 , V_193 = 0 ;
if ( V_24 -> V_43 )
return;
switch ( F_97 ( V_63 ) ) {
case 0 :
V_192 = & V_24 -> V_140 ;
V_190 = 8 ;
V_191 = V_194 ;
break;
case 1 :
V_192 = & V_24 -> V_125 ;
V_190 = 8 ;
V_191 = V_195 ;
V_193 = V_122 ;
break;
default:
return;
}
V_65 = F_88 ( * V_192 , V_63 & 7 , V_64 , V_184 ) ;
V_65 &= ~ V_196 ;
V_65 &= ~ V_193 ;
V_65 |= ( V_190 - 1 ) << V_197 ;
V_65 |= V_191 << V_198 ;
V_65 = F_83 ( V_65 ) ;
* V_192 = V_65 ;
}
static unsigned long F_99 ( struct V_2 * V_48 ,
struct V_23 * V_24 ,
T_4 V_63 , unsigned int V_64 )
{
T_1 V_65 = 0 ;
F_45 ( & V_24 -> V_185 ) ;
if ( V_24 -> V_186 == V_24 -> V_187 )
V_65 |= V_199 ;
if ( V_24 -> V_43 )
V_65 |= V_200 ;
F_46 ( & V_24 -> V_185 ) ;
return V_65 ;
}
static void F_100 ( struct V_2 * V_2 , struct V_23 * V_24 ,
T_4 V_63 , unsigned int V_64 ,
unsigned long V_184 )
{
F_45 ( & V_24 -> V_185 ) ;
V_24 -> V_43 = ! ! ( V_184 & V_200 ) ;
F_89 ( V_2 , V_24 ) ;
F_46 ( & V_24 -> V_185 ) ;
}
static void F_101 ( struct V_2 * V_2 , struct V_23 * V_24 ,
T_4 V_63 , unsigned int V_64 , unsigned long V_184 )
{
}
void F_102 ( struct V_34 * V_48 )
{
if ( ! ( V_48 -> V_6 . V_54 . V_55 & V_201 ) )
F_32 ( V_48 ) ;
}
static int F_103 ( struct V_2 * V_2 , struct V_23 * V_24 )
{
struct V_85 * V_88 = & V_24 -> V_88 ;
int V_39 ;
if ( ! V_24 -> V_202 )
return - V_82 ;
if ( F_104 ( V_24 -> V_203 ) )
return - V_204 ;
V_88 -> V_205 = V_206 ;
V_88 -> V_207 = F_105 ( V_206 ) ;
F_106 ( & V_88 -> V_87 , & V_90 ) ;
V_88 -> V_208 = V_24 -> V_203 ;
V_88 -> V_91 = V_92 ;
V_88 -> V_24 = V_24 ;
F_45 ( & V_2 -> V_209 ) ;
V_39 = F_107 ( V_2 , V_103 , V_88 -> V_208 ,
V_210 , & V_88 -> V_87 ) ;
F_46 ( & V_2 -> V_209 ) ;
return V_39 ;
}
static int F_108 ( struct V_211 * V_87 , T_1 type )
{
struct V_23 * V_24 ;
if ( type != V_212 )
return - V_97 ;
V_24 = F_3 ( sizeof( struct V_23 ) , V_10 ) ;
if ( ! V_24 )
return - V_11 ;
F_109 ( & V_24 -> V_104 ) ;
F_109 ( & V_24 -> V_185 ) ;
V_24 -> V_203 = V_213 ;
F_5 ( & V_24 -> V_142 ) ;
F_5 ( & V_24 -> V_129 ) ;
V_87 -> V_2 -> V_6 . V_7 . V_214 = true ;
V_24 -> V_202 = false ;
V_24 -> V_43 = false ;
V_24 -> V_87 = V_87 ;
V_24 -> V_140 = V_215 |
( ( T_2 ) V_194 << V_198 ) ;
V_24 -> V_125 = V_215 |
( ( T_2 ) V_195 << V_198 ) ;
V_87 -> V_2 -> V_6 . V_7 . V_37 = V_216 ;
V_87 -> V_217 = V_24 ;
return 0 ;
}
static void F_110 ( struct V_211 * V_218 )
{
struct V_2 * V_2 = V_218 -> V_2 ;
struct V_23 * V_24 = V_218 -> V_217 ;
struct V_22 * V_87 ;
struct V_27 * V_29 ;
struct V_219 * V_220 , * V_221 ;
struct V_219 * V_222 , * V_137 ;
if ( ! V_24 -> V_142 . V_223 )
return;
F_45 ( & V_24 -> V_104 ) ;
F_111 (dev_cur, dev_temp, &its->device_list) {
V_87 = F_41 ( V_220 , struct V_22 , V_138 ) ;
F_111 (cur, temp, &dev->itt_head) {
V_29 = ( F_41 ( V_222 , struct V_27 , V_106 ) ) ;
F_47 ( V_2 , V_29 ) ;
}
F_48 ( V_220 ) ;
F_10 ( V_87 ) ;
}
F_111 (cur, temp, &its->collection_list) {
F_48 ( V_222 ) ;
F_10 ( F_41 ( V_222 , struct V_30 , V_128 ) ) ;
}
F_46 ( & V_24 -> V_104 ) ;
F_10 ( V_24 ) ;
}
static int F_112 ( struct V_211 * V_87 ,
struct V_224 * V_225 )
{
switch ( V_225 -> V_226 ) {
case V_227 :
switch ( V_225 -> V_225 ) {
case V_228 :
return 0 ;
}
break;
case V_229 :
switch ( V_225 -> V_225 ) {
case V_230 :
return 0 ;
}
break;
}
return - V_204 ;
}
static int F_113 ( struct V_211 * V_87 ,
struct V_224 * V_225 )
{
struct V_23 * V_24 = V_87 -> V_217 ;
int V_39 ;
switch ( V_225 -> V_226 ) {
case V_227 : {
T_2 T_8 * V_231 = ( T_2 T_8 * ) ( long ) V_225 -> V_63 ;
unsigned long type = ( unsigned long ) V_225 -> V_225 ;
T_2 V_63 ;
if ( type != V_228 )
return - V_97 ;
if ( F_114 ( & V_63 , V_231 , sizeof( V_63 ) ) )
return - V_232 ;
V_39 = F_115 ( V_87 -> V_2 , & V_24 -> V_203 ,
V_63 , V_117 ) ;
if ( V_39 )
return V_39 ;
V_24 -> V_203 = V_63 ;
return 0 ;
}
case V_229 :
switch ( V_225 -> V_225 ) {
case V_230 :
V_24 -> V_202 = true ;
return 0 ;
}
break;
}
return - V_204 ;
}
static int F_116 ( struct V_211 * V_87 ,
struct V_224 * V_225 )
{
switch ( V_225 -> V_226 ) {
case V_227 : {
struct V_23 * V_24 = V_87 -> V_217 ;
T_2 V_63 = V_24 -> V_203 ;
T_2 T_8 * V_231 = ( T_2 T_8 * ) ( long ) V_225 -> V_63 ;
unsigned long type = ( unsigned long ) V_225 -> V_225 ;
if ( type != V_228 )
return - V_97 ;
if ( F_117 ( V_231 , & V_63 , sizeof( V_63 ) ) )
return - V_232 ;
break;
default:
return - V_204 ;
}
}
return 0 ;
}
int F_118 ( void )
{
return F_119 ( & V_233 ,
V_212 ) ;
}
int F_120 ( struct V_2 * V_2 )
{
struct V_211 * V_87 ;
int V_39 = 0 ;
F_9 (dev, &kvm->devices, vm_node) {
if ( V_87 -> V_89 != & V_233 )
continue;
V_39 = F_103 ( V_2 , V_87 -> V_217 ) ;
if ( V_39 )
return V_39 ;
}
return V_39 ;
}
