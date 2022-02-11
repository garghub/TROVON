static struct V_1 * F_1 ( struct V_2 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_2 -> V_8 . V_9 ;
struct V_1 * V_10 = F_2 ( V_2 , NULL , V_3 ) , * V_11 ;
int V_12 ;
if ( V_10 )
return V_10 ;
V_10 = F_3 ( sizeof( struct V_1 ) , V_13 ) ;
if ( ! V_10 )
return F_4 ( - V_14 ) ;
F_5 ( & V_10 -> V_15 ) ;
F_5 ( & V_10 -> V_16 ) ;
F_6 ( & V_10 -> V_17 ) ;
V_10 -> V_18 = V_19 ;
F_7 ( & V_10 -> V_20 ) ;
V_10 -> V_3 = V_3 ;
V_10 -> V_21 = V_5 ;
F_8 ( & V_7 -> V_22 ) ;
F_9 (oldirq, &dist->lpi_list_head, lpi_list) {
if ( V_11 -> V_3 != V_3 )
continue;
F_10 ( V_10 ) ;
V_10 = V_11 ;
F_11 ( V_10 ) ;
goto V_23;
}
F_12 ( & V_10 -> V_15 , & V_7 -> V_24 ) ;
V_7 -> V_25 ++ ;
V_23:
F_13 ( & V_7 -> V_22 ) ;
V_12 = F_14 ( V_2 , V_10 , NULL ) ;
if ( V_12 )
return F_4 ( V_12 ) ;
V_12 = F_15 ( V_2 , V_10 ) ;
if ( V_12 )
return F_4 ( V_12 ) ;
return V_10 ;
}
inline const struct V_26 * F_16 ( struct V_27 * V_28 )
{
return & V_29 [ V_28 -> V_30 ] ;
}
int F_17 ( struct V_27 * V_28 , int V_31 )
{
const struct V_26 * V_32 ;
V_28 -> V_30 = V_31 ;
V_32 = F_16 ( V_28 ) ;
return V_32 -> V_33 ( V_28 ) ;
}
static struct V_34 * F_18 ( struct V_27 * V_28 , T_1 V_35 )
{
struct V_34 * V_36 ;
F_9 (device, &its->device_list, dev_list)
if ( V_35 == V_36 -> V_35 )
return V_36 ;
return NULL ;
}
static struct V_37 * F_19 ( struct V_27 * V_28 , T_1 V_35 ,
T_1 V_38 )
{
struct V_34 * V_36 ;
struct V_37 * V_39 ;
V_36 = F_18 ( V_28 , V_35 ) ;
if ( V_36 == NULL )
return NULL ;
F_9 (ite, &device->itt_head, ite_list)
if ( V_39 -> V_38 == V_38 )
return V_39 ;
return NULL ;
}
static struct V_40 * F_20 ( struct V_27 * V_28 , int V_41 )
{
struct V_40 * V_42 ;
F_9 (collection, &its->collection_list, coll_list) {
if ( V_41 == V_42 -> V_43 )
return V_42 ;
}
return NULL ;
}
static int F_14 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_4 * V_44 )
{
T_2 V_45 = F_21 ( V_2 -> V_8 . V_9 . V_46 ) ;
T_3 V_47 ;
int V_12 ;
V_12 = F_22 ( V_2 , V_45 + V_10 -> V_3 - V_48 ,
& V_47 , 1 ) ;
if ( V_12 )
return V_12 ;
F_8 ( & V_10 -> V_17 ) ;
if ( ! V_44 || V_44 == V_10 -> V_21 ) {
V_10 -> V_49 = F_23 ( V_47 ) ;
V_10 -> V_50 = F_24 ( V_47 ) ;
F_25 ( V_2 , V_10 ) ;
} else {
F_13 ( & V_10 -> V_17 ) ;
}
return 0 ;
}
static int F_26 ( struct V_4 * V_5 , T_1 * * V_51 )
{
struct V_6 * V_7 = & V_5 -> V_2 -> V_8 . V_9 ;
struct V_1 * V_10 ;
T_1 * V_52 ;
int V_53 = V_7 -> V_25 , V_54 = 0 ;
V_52 = F_27 ( V_53 , sizeof( V_52 [ 0 ] ) , V_13 ) ;
if ( ! V_52 )
return - V_14 ;
F_8 ( & V_7 -> V_22 ) ;
F_9 (irq, &dist->lpi_list_head, lpi_list) {
if ( V_10 -> V_21 != V_5 )
continue;
V_52 [ V_54 ++ ] = V_10 -> V_3 ;
}
F_13 ( & V_7 -> V_22 ) ;
* V_51 = V_52 ;
return V_54 ;
}
static void F_28 ( struct V_2 * V_2 , struct V_37 * V_39 )
{
struct V_4 * V_5 ;
if ( ! F_29 ( V_39 -> V_42 ) )
return;
V_5 = F_30 ( V_2 , V_39 -> V_42 -> V_55 ) ;
F_8 ( & V_39 -> V_10 -> V_17 ) ;
V_39 -> V_10 -> V_21 = V_5 ;
F_13 ( & V_39 -> V_10 -> V_17 ) ;
}
static void F_31 ( struct V_2 * V_2 , struct V_27 * V_28 ,
struct V_40 * V_56 )
{
struct V_34 * V_36 ;
struct V_37 * V_39 ;
F_32 (device, ite, its) {
if ( ! V_39 -> V_42 || V_56 != V_39 -> V_42 )
continue;
F_28 ( V_2 , V_39 ) ;
}
}
static T_1 F_33 ( T_2 V_46 )
{
int V_57 = ( V_46 & 0x1f ) + 1 ;
return 1U << F_34 ( V_57 , V_58 ) ;
}
static int F_35 ( struct V_4 * V_5 )
{
T_4 V_59 = F_36 ( V_5 -> V_8 . V_60 . V_61 ) ;
struct V_1 * V_10 ;
int V_62 = - 1 ;
int V_12 = 0 ;
T_1 * V_52 ;
int V_63 , V_54 ;
V_63 = F_26 ( V_5 , & V_52 ) ;
if ( V_63 < 0 )
return V_63 ;
for ( V_54 = 0 ; V_54 < V_63 ; V_54 ++ ) {
int V_64 , V_65 ;
T_3 V_66 ;
V_64 = V_52 [ V_54 ] / V_67 ;
V_65 = V_52 [ V_54 ] % V_67 ;
if ( V_64 != V_62 ) {
V_12 = F_22 ( V_5 -> V_2 , V_59 + V_64 ,
& V_66 , 1 ) ;
if ( V_12 ) {
F_10 ( V_52 ) ;
return V_12 ;
}
V_62 = V_64 ;
}
V_10 = F_2 ( V_5 -> V_2 , NULL , V_52 [ V_54 ] ) ;
F_8 ( & V_10 -> V_17 ) ;
V_10 -> V_68 = V_66 & ( 1U << V_65 ) ;
F_25 ( V_5 -> V_2 , V_10 ) ;
F_37 ( V_5 -> V_2 , V_10 ) ;
}
F_10 ( V_52 ) ;
return V_12 ;
}
static unsigned long F_38 ( struct V_2 * V_2 ,
struct V_27 * V_28 ,
T_4 V_69 , unsigned int V_70 )
{
const struct V_26 * V_32 = F_16 ( V_28 ) ;
T_2 V_71 = V_72 ;
V_71 |= F_39 ( V_73 , 5 ) << V_74 ;
V_71 |= F_39 ( V_75 , 5 ) << V_76 ;
V_71 |= F_39 ( V_32 -> V_77 , 4 ) << V_78 ;
return F_40 ( V_71 , V_69 & 7 , V_70 ) ;
}
static unsigned long F_41 ( struct V_2 * V_2 ,
struct V_27 * V_28 ,
T_4 V_69 , unsigned int V_70 )
{
T_1 V_79 ;
V_79 = ( V_28 -> V_30 << V_80 ) & V_81 ;
V_79 |= ( V_82 << V_83 ) | V_84 ;
return V_79 ;
}
static int F_42 ( struct V_2 * V_2 ,
struct V_27 * V_28 ,
T_4 V_69 , unsigned int V_70 ,
unsigned long V_79 )
{
T_1 V_31 = F_43 ( V_79 ) ;
if ( V_31 >= V_85 )
return - V_86 ;
return F_17 ( V_28 , V_31 ) ;
}
static unsigned long F_44 ( struct V_2 * V_2 ,
struct V_27 * V_28 ,
T_4 V_69 , unsigned int V_70 )
{
switch ( V_69 & 0xffff ) {
case V_87 :
return 0x92 ;
case V_88 :
return 0xb4 ;
case V_89 :
return V_90 | 0x0b ;
case V_91 :
return 0x40 ;
case V_92 :
return 0x0d ;
case V_93 :
return 0xf0 ;
case V_94 :
return 0x05 ;
case V_95 :
return 0xb1 ;
}
return 0 ;
}
static int F_45 ( struct V_2 * V_2 , struct V_27 * V_28 ,
T_1 V_96 , T_1 V_97 )
{
struct V_4 * V_5 ;
struct V_37 * V_39 ;
if ( ! V_28 -> V_50 )
return - V_98 ;
V_39 = F_19 ( V_28 , V_96 , V_97 ) ;
if ( ! V_39 || ! F_29 ( V_39 -> V_42 ) )
return V_99 ;
V_5 = F_30 ( V_2 , V_39 -> V_42 -> V_55 ) ;
if ( ! V_5 )
return V_99 ;
if ( ! V_5 -> V_8 . V_60 . V_100 )
return - V_98 ;
F_8 ( & V_39 -> V_10 -> V_17 ) ;
V_39 -> V_10 -> V_68 = true ;
F_25 ( V_2 , V_39 -> V_10 ) ;
return 0 ;
}
static struct V_101 * F_46 ( struct V_102 * V_103 )
{
struct V_101 * V_104 ;
if ( V_103 -> V_105 != & V_106 )
return NULL ;
V_104 = F_47 ( V_103 , struct V_101 , V_103 ) ;
if ( V_104 -> V_107 != V_108 )
return NULL ;
return V_104 ;
}
int F_48 ( struct V_2 * V_2 , struct V_109 * V_110 )
{
T_2 V_111 ;
struct V_102 * V_112 ;
struct V_101 * V_104 ;
int V_12 ;
if ( ! F_49 ( V_2 ) )
return - V_113 ;
if ( ! ( V_110 -> V_114 & V_115 ) )
return - V_86 ;
V_111 = ( T_2 ) V_110 -> V_116 << 32 | V_110 -> V_117 ;
V_112 = F_50 ( V_2 , V_118 , V_111 ) ;
if ( ! V_112 )
return - V_86 ;
V_104 = F_46 ( V_112 ) ;
if ( ! V_104 )
return - V_86 ;
F_51 ( & V_104 -> V_28 -> V_119 ) ;
V_12 = F_45 ( V_2 , V_104 -> V_28 , V_110 -> V_96 , V_110 -> V_120 ) ;
F_52 ( & V_104 -> V_28 -> V_119 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_12 )
return 0 ;
else
return 1 ;
}
static void F_53 ( struct V_2 * V_2 , struct V_37 * V_39 )
{
F_54 ( & V_39 -> V_121 ) ;
if ( V_39 -> V_10 )
F_37 ( V_2 , V_39 -> V_10 ) ;
F_10 ( V_39 ) ;
}
static T_2 F_55 ( T_2 * V_122 , int V_123 , int V_124 , int V_125 )
{
return ( F_56 ( V_122 [ V_123 ] ) >> V_124 ) & ( F_57 ( V_125 ) - 1 ) ;
}
static int F_58 ( struct V_2 * V_2 , struct V_27 * V_28 ,
T_2 * V_122 )
{
T_1 V_35 = F_59 ( V_122 ) ;
T_1 V_38 = F_60 ( V_122 ) ;
struct V_37 * V_39 ;
V_39 = F_19 ( V_28 , V_35 , V_38 ) ;
if ( V_39 && V_39 -> V_42 ) {
F_53 ( V_2 , V_39 ) ;
return 0 ;
}
return V_126 ;
}
static int F_61 ( struct V_2 * V_2 , struct V_27 * V_28 ,
T_2 * V_122 )
{
T_1 V_35 = F_59 ( V_122 ) ;
T_1 V_38 = F_60 ( V_122 ) ;
T_1 V_41 = F_62 ( V_122 ) ;
struct V_4 * V_5 ;
struct V_37 * V_39 ;
struct V_40 * V_42 ;
V_39 = F_19 ( V_28 , V_35 , V_38 ) ;
if ( ! V_39 )
return V_127 ;
if ( ! F_29 ( V_39 -> V_42 ) )
return V_128 ;
V_42 = F_20 ( V_28 , V_41 ) ;
if ( ! F_29 ( V_42 ) )
return V_128 ;
V_39 -> V_42 = V_42 ;
V_5 = F_30 ( V_2 , V_42 -> V_55 ) ;
F_8 ( & V_39 -> V_10 -> V_17 ) ;
V_39 -> V_10 -> V_21 = V_5 ;
F_13 ( & V_39 -> V_10 -> V_17 ) ;
return 0 ;
}
static bool F_63 ( struct V_27 * V_28 , T_2 V_129 , T_1 V_130 ,
T_4 * V_131 )
{
int V_132 = F_64 ( V_129 ) * V_133 ;
T_2 V_134 , type = F_65 ( V_129 ) ;
int V_135 = F_66 ( V_129 ) ;
int V_136 ;
T_5 V_137 ;
switch ( type ) {
case V_138 :
if ( V_130 >= F_57 ( V_73 ) )
return false ;
break;
case V_139 :
if ( V_130 >= F_57 ( 16 ) )
return false ;
break;
default:
return false ;
}
if ( ! ( V_129 & V_140 ) ) {
T_6 V_69 ;
if ( V_130 >= ( V_132 / V_135 ) )
return false ;
V_69 = F_67 ( V_129 ) + V_130 * V_135 ;
V_137 = V_69 >> V_141 ;
if ( V_131 )
* V_131 = V_69 ;
return F_68 ( V_28 -> V_103 -> V_2 , V_137 ) ;
}
V_136 = V_130 / ( V_133 / V_135 ) ;
if ( V_136 >= ( V_132 / sizeof( T_2 ) ) )
return false ;
if ( F_22 ( V_28 -> V_103 -> V_2 ,
F_67 ( V_129 ) + V_136 * sizeof( V_134 ) ,
& V_134 , sizeof( V_134 ) ) )
return false ;
V_134 = F_56 ( V_134 ) ;
if ( ! ( V_134 & F_57 ( 63 ) ) )
return false ;
V_134 &= F_69 ( 51 , 16 ) ;
V_136 = V_130 % ( V_133 / V_135 ) ;
V_134 += V_136 * V_135 ;
V_137 = V_134 >> V_141 ;
if ( V_131 )
* V_131 = V_134 ;
return F_68 ( V_28 -> V_103 -> V_2 , V_137 ) ;
}
static int F_70 ( struct V_27 * V_28 ,
struct V_40 * * V_142 ,
T_1 V_41 )
{
struct V_40 * V_42 ;
if ( ! F_63 ( V_28 , V_28 -> V_143 , V_41 , NULL ) )
return V_144 ;
V_42 = F_3 ( sizeof( * V_42 ) , V_13 ) ;
V_42 -> V_43 = V_41 ;
V_42 -> V_55 = V_145 ;
F_12 ( & V_42 -> V_146 , & V_28 -> V_147 ) ;
* V_142 = V_42 ;
return 0 ;
}
static void F_71 ( struct V_27 * V_28 , T_1 V_41 )
{
struct V_40 * V_42 ;
struct V_34 * V_36 ;
struct V_37 * V_39 ;
V_42 = F_20 ( V_28 , V_41 ) ;
if ( ! V_42 )
return;
F_32 (device, ite, its)
if ( V_39 -> V_42 &&
V_39 -> V_42 -> V_43 == V_41 )
V_39 -> V_42 = NULL ;
F_54 ( & V_42 -> V_146 ) ;
F_10 ( V_42 ) ;
}
static struct V_37 * F_72 ( struct V_34 * V_36 ,
struct V_40 * V_42 ,
T_1 V_148 , T_1 V_38 )
{
struct V_37 * V_39 ;
V_39 = F_3 ( sizeof( * V_39 ) , V_13 ) ;
if ( ! V_39 )
return F_4 ( - V_14 ) ;
V_39 -> V_38 = V_38 ;
V_39 -> V_42 = V_42 ;
V_39 -> V_149 = V_148 ;
F_12 ( & V_39 -> V_121 , & V_36 -> V_150 ) ;
return V_39 ;
}
static int F_73 ( struct V_2 * V_2 , struct V_27 * V_28 ,
T_2 * V_122 )
{
T_1 V_35 = F_59 ( V_122 ) ;
T_1 V_38 = F_60 ( V_122 ) ;
T_1 V_41 = F_62 ( V_122 ) ;
struct V_37 * V_39 ;
struct V_4 * V_5 = NULL ;
struct V_34 * V_36 ;
struct V_40 * V_42 , * V_151 = NULL ;
struct V_1 * V_10 ;
int V_152 ;
V_36 = F_18 ( V_28 , V_35 ) ;
if ( ! V_36 )
return V_153 ;
if ( V_38 >= F_57 ( V_36 -> V_154 ) )
return V_155 ;
if ( F_74 ( V_122 ) == V_156 )
V_152 = F_75 ( V_122 ) ;
else
V_152 = V_38 ;
if ( V_152 < V_48 ||
V_152 >= F_33 ( V_2 -> V_8 . V_9 . V_46 ) )
return V_157 ;
if ( F_19 ( V_28 , V_35 , V_38 ) )
return 0 ;
V_42 = F_20 ( V_28 , V_41 ) ;
if ( ! V_42 ) {
int V_12 = F_70 ( V_28 , & V_42 , V_41 ) ;
if ( V_12 )
return V_12 ;
V_151 = V_42 ;
}
V_39 = F_72 ( V_36 , V_42 , V_152 , V_38 ) ;
if ( F_76 ( V_39 ) ) {
if ( V_151 )
F_71 ( V_28 , V_41 ) ;
return F_77 ( V_39 ) ;
}
if ( F_29 ( V_42 ) )
V_5 = F_30 ( V_2 , V_42 -> V_55 ) ;
V_10 = F_1 ( V_2 , V_152 , V_5 ) ;
if ( F_76 ( V_10 ) ) {
if ( V_151 )
F_71 ( V_28 , V_41 ) ;
F_53 ( V_2 , V_39 ) ;
return F_77 ( V_10 ) ;
}
V_39 -> V_10 = V_10 ;
return 0 ;
}
static void F_78 ( struct V_2 * V_2 , struct V_34 * V_36 )
{
struct V_37 * V_39 , * V_158 ;
F_79 (ite, temp, &device->itt_head, ite_list)
F_53 ( V_2 , V_39 ) ;
F_54 ( & V_36 -> V_159 ) ;
F_10 ( V_36 ) ;
}
static struct V_34 * F_80 ( struct V_27 * V_28 ,
T_1 V_35 , T_4 V_160 ,
T_3 V_154 )
{
struct V_34 * V_36 ;
V_36 = F_3 ( sizeof( * V_36 ) , V_13 ) ;
if ( ! V_36 )
return F_4 ( - V_14 ) ;
V_36 -> V_35 = V_35 ;
V_36 -> V_160 = V_160 ;
V_36 -> V_154 = V_154 ;
F_5 ( & V_36 -> V_150 ) ;
F_12 ( & V_36 -> V_159 , & V_28 -> V_161 ) ;
return V_36 ;
}
static int F_81 ( struct V_2 * V_2 , struct V_27 * V_28 ,
T_2 * V_122 )
{
T_1 V_35 = F_59 ( V_122 ) ;
bool V_162 = F_82 ( V_122 ) ;
T_3 V_154 = F_83 ( V_122 ) ;
T_4 V_160 = F_84 ( V_122 ) ;
struct V_34 * V_36 ;
if ( ! F_63 ( V_28 , V_28 -> V_163 , V_35 , NULL ) )
return V_164 ;
if ( V_162 && V_154 > V_75 )
return V_165 ;
V_36 = F_18 ( V_28 , V_35 ) ;
if ( V_36 )
F_78 ( V_2 , V_36 ) ;
if ( ! V_162 )
return 0 ;
V_36 = F_80 ( V_28 , V_35 , V_160 ,
V_154 ) ;
if ( F_76 ( V_36 ) )
return F_77 ( V_36 ) ;
return 0 ;
}
static int F_85 ( struct V_2 * V_2 , struct V_27 * V_28 ,
T_2 * V_122 )
{
T_7 V_41 ;
T_1 V_55 ;
struct V_40 * V_42 ;
bool V_162 ;
V_162 = F_82 ( V_122 ) ;
V_41 = F_62 ( V_122 ) ;
V_55 = F_86 ( V_122 ) ;
if ( V_55 >= F_87 ( & V_2 -> V_166 ) )
return V_167 ;
if ( ! V_162 ) {
F_71 ( V_28 , V_41 ) ;
} else {
V_42 = F_20 ( V_28 , V_41 ) ;
if ( ! V_42 ) {
int V_12 ;
V_12 = F_70 ( V_28 , & V_42 ,
V_41 ) ;
if ( V_12 )
return V_12 ;
V_42 -> V_55 = V_55 ;
} else {
V_42 -> V_55 = V_55 ;
F_31 ( V_2 , V_28 , V_42 ) ;
}
}
return 0 ;
}
static int F_88 ( struct V_2 * V_2 , struct V_27 * V_28 ,
T_2 * V_122 )
{
T_1 V_35 = F_59 ( V_122 ) ;
T_1 V_38 = F_60 ( V_122 ) ;
struct V_37 * V_39 ;
V_39 = F_19 ( V_28 , V_35 , V_38 ) ;
if ( ! V_39 )
return V_168 ;
V_39 -> V_10 -> V_68 = false ;
return 0 ;
}
static int F_89 ( struct V_2 * V_2 , struct V_27 * V_28 ,
T_2 * V_122 )
{
T_1 V_35 = F_59 ( V_122 ) ;
T_1 V_38 = F_60 ( V_122 ) ;
struct V_37 * V_39 ;
V_39 = F_19 ( V_28 , V_35 , V_38 ) ;
if ( ! V_39 )
return V_169 ;
return F_14 ( V_2 , V_39 -> V_10 , NULL ) ;
}
static int F_90 ( struct V_2 * V_2 , struct V_27 * V_28 ,
T_2 * V_122 )
{
T_1 V_41 = F_62 ( V_122 ) ;
struct V_40 * V_42 ;
struct V_4 * V_5 ;
struct V_1 * V_10 ;
T_1 * V_52 ;
int V_53 , V_54 ;
V_42 = F_20 ( V_28 , V_41 ) ;
if ( ! F_29 ( V_42 ) )
return V_170 ;
V_5 = F_30 ( V_2 , V_42 -> V_55 ) ;
V_53 = F_26 ( V_5 , & V_52 ) ;
if ( V_53 < 0 )
return V_53 ;
for ( V_54 = 0 ; V_54 < V_53 ; V_54 ++ ) {
V_10 = F_2 ( V_2 , NULL , V_52 [ V_54 ] ) ;
if ( ! V_10 )
continue;
F_14 ( V_2 , V_10 , V_5 ) ;
F_37 ( V_2 , V_10 ) ;
}
F_10 ( V_52 ) ;
return 0 ;
}
static int F_91 ( struct V_2 * V_2 , struct V_27 * V_28 ,
T_2 * V_122 )
{
struct V_6 * V_7 = & V_2 -> V_8 . V_9 ;
T_1 V_171 = F_86 ( V_122 ) ;
T_1 V_172 = F_55 ( V_122 , 3 , 16 , 32 ) ;
struct V_4 * V_173 , * V_174 ;
struct V_1 * V_10 ;
if ( V_171 >= F_87 ( & V_2 -> V_166 ) ||
V_172 >= F_87 ( & V_2 -> V_166 ) )
return V_175 ;
if ( V_171 == V_172 )
return 0 ;
V_173 = F_30 ( V_2 , V_171 ) ;
V_174 = F_30 ( V_2 , V_172 ) ;
F_8 ( & V_7 -> V_22 ) ;
F_9 (irq, &dist->lpi_list_head, lpi_list) {
F_8 ( & V_10 -> V_17 ) ;
if ( V_10 -> V_21 == V_173 )
V_10 -> V_21 = V_174 ;
F_13 ( & V_10 -> V_17 ) ;
}
F_13 ( & V_7 -> V_22 ) ;
return 0 ;
}
static int F_92 ( struct V_2 * V_2 , struct V_27 * V_28 ,
T_2 * V_122 )
{
T_1 V_176 = F_60 ( V_122 ) ;
T_2 V_177 = F_59 ( V_122 ) ;
return F_45 ( V_2 , V_28 , V_177 , V_176 ) ;
}
static int F_93 ( struct V_2 * V_2 , struct V_27 * V_28 ,
T_2 * V_122 )
{
int V_12 = - V_113 ;
F_51 ( & V_28 -> V_119 ) ;
switch ( F_74 ( V_122 ) ) {
case V_178 :
V_12 = F_81 ( V_2 , V_28 , V_122 ) ;
break;
case V_179 :
V_12 = F_85 ( V_2 , V_28 , V_122 ) ;
break;
case V_180 :
V_12 = F_73 ( V_2 , V_28 , V_122 ) ;
break;
case V_156 :
V_12 = F_73 ( V_2 , V_28 , V_122 ) ;
break;
case V_181 :
V_12 = F_61 ( V_2 , V_28 , V_122 ) ;
break;
case V_182 :
V_12 = F_58 ( V_2 , V_28 , V_122 ) ;
break;
case V_183 :
V_12 = F_88 ( V_2 , V_28 , V_122 ) ;
break;
case V_184 :
V_12 = F_91 ( V_2 , V_28 , V_122 ) ;
break;
case V_185 :
V_12 = F_92 ( V_2 , V_28 , V_122 ) ;
break;
case V_186 :
V_12 = F_89 ( V_2 , V_28 , V_122 ) ;
break;
case V_187 :
V_12 = F_90 ( V_2 , V_28 , V_122 ) ;
break;
case V_188 :
V_12 = 0 ;
break;
}
F_52 ( & V_28 -> V_119 ) ;
return V_12 ;
}
static T_2 F_94 ( T_2 V_71 )
{
V_71 = F_95 ( V_71 , V_189 ,
V_190 ,
V_191 ) ;
V_71 = F_95 ( V_71 , V_192 ,
V_193 ,
V_194 ) ;
V_71 = F_95 ( V_71 , V_195 ,
V_196 ,
V_197 ) ;
V_71 &= ~ F_69 ( 15 , 12 ) ;
V_71 = ( V_71 & ~ V_198 ) | V_199 ;
return V_71 ;
}
static T_2 F_96 ( T_2 V_71 )
{
V_71 = F_95 ( V_71 , V_200 ,
V_201 ,
V_191 ) ;
V_71 = F_95 ( V_71 , V_202 ,
V_203 ,
V_194 ) ;
V_71 = F_95 ( V_71 , V_204 ,
V_205 ,
V_197 ) ;
V_71 &= ~ ( F_69 ( 51 , 48 ) | F_69 ( 15 , 12 ) ) ;
return V_71 ;
}
static unsigned long F_97 ( struct V_2 * V_2 ,
struct V_27 * V_28 ,
T_4 V_69 , unsigned int V_70 )
{
return F_40 ( V_28 -> V_206 , V_69 & 7 , V_70 ) ;
}
static void F_98 ( struct V_2 * V_2 , struct V_27 * V_28 ,
T_4 V_69 , unsigned int V_70 ,
unsigned long V_79 )
{
if ( V_28 -> V_50 )
return;
F_51 ( & V_28 -> V_207 ) ;
V_28 -> V_206 = F_99 ( V_28 -> V_206 , V_69 & 7 , V_70 , V_79 ) ;
V_28 -> V_206 = F_96 ( V_28 -> V_206 ) ;
V_28 -> V_208 = 0 ;
V_28 -> V_209 = V_28 -> V_208 ;
F_52 ( & V_28 -> V_207 ) ;
}
static void F_100 ( struct V_2 * V_2 , struct V_27 * V_28 )
{
T_4 V_206 ;
T_2 V_210 [ 4 ] ;
if ( ! V_28 -> V_50 )
return;
V_206 = F_101 ( V_28 -> V_206 ) ;
while ( V_28 -> V_209 != V_28 -> V_208 ) {
int V_12 = F_22 ( V_2 , V_206 + V_28 -> V_208 ,
V_210 , V_211 ) ;
if ( ! V_12 )
F_93 ( V_2 , V_28 , V_210 ) ;
V_28 -> V_208 += V_211 ;
if ( V_28 -> V_208 == F_102 ( V_28 -> V_206 ) )
V_28 -> V_208 = 0 ;
}
}
static void F_103 ( struct V_2 * V_2 , struct V_27 * V_28 ,
T_4 V_69 , unsigned int V_70 ,
unsigned long V_79 )
{
T_2 V_71 ;
if ( ! V_28 )
return;
F_51 ( & V_28 -> V_207 ) ;
V_71 = F_99 ( V_28 -> V_209 , V_69 & 7 , V_70 , V_79 ) ;
V_71 = F_104 ( V_71 ) ;
if ( V_71 >= F_102 ( V_28 -> V_206 ) ) {
F_52 ( & V_28 -> V_207 ) ;
return;
}
V_28 -> V_209 = V_71 ;
F_100 ( V_2 , V_28 ) ;
F_52 ( & V_28 -> V_207 ) ;
}
static unsigned long F_105 ( struct V_2 * V_2 ,
struct V_27 * V_28 ,
T_4 V_69 , unsigned int V_70 )
{
return F_40 ( V_28 -> V_209 , V_69 & 0x7 , V_70 ) ;
}
static unsigned long F_106 ( struct V_2 * V_2 ,
struct V_27 * V_28 ,
T_4 V_69 , unsigned int V_70 )
{
return F_40 ( V_28 -> V_208 , V_69 & 0x7 , V_70 ) ;
}
static int F_107 ( struct V_2 * V_2 ,
struct V_27 * V_28 ,
T_4 V_69 , unsigned int V_70 ,
unsigned long V_79 )
{
T_1 V_212 ;
int V_12 = 0 ;
F_51 ( & V_28 -> V_207 ) ;
if ( V_28 -> V_50 ) {
V_12 = - V_98 ;
goto V_213;
}
V_212 = F_104 ( V_79 ) ;
if ( V_212 >= F_102 ( V_28 -> V_206 ) ) {
V_12 = - V_86 ;
goto V_213;
}
V_28 -> V_208 = V_212 ;
V_213:
F_52 ( & V_28 -> V_207 ) ;
return V_12 ;
}
static unsigned long F_108 ( struct V_2 * V_2 ,
struct V_27 * V_28 ,
T_4 V_69 , unsigned int V_70 )
{
T_2 V_71 ;
switch ( F_109 ( V_69 ) ) {
case 0 :
V_71 = V_28 -> V_163 ;
break;
case 1 :
V_71 = V_28 -> V_143 ;
break;
default:
V_71 = 0 ;
break;
}
return F_40 ( V_71 , V_69 & 7 , V_70 ) ;
}
static void F_110 ( struct V_2 * V_2 ,
struct V_27 * V_28 ,
T_4 V_69 , unsigned int V_70 ,
unsigned long V_79 )
{
const struct V_26 * V_32 = F_16 ( V_28 ) ;
T_2 V_214 , V_215 ;
T_2 V_71 , * V_216 , V_217 = 0 ;
if ( V_28 -> V_50 )
return;
switch ( F_109 ( V_69 ) ) {
case 0 :
V_216 = & V_28 -> V_163 ;
V_214 = V_32 -> V_218 ;
V_215 = V_138 ;
break;
case 1 :
V_216 = & V_28 -> V_143 ;
V_214 = V_32 -> V_219 ;
V_215 = V_139 ;
V_217 = V_140 ;
break;
default:
return;
}
V_71 = F_99 ( * V_216 , V_69 & 7 , V_70 , V_79 ) ;
V_71 &= ~ V_220 ;
V_71 &= ~ V_217 ;
V_71 |= ( V_214 - 1 ) << V_221 ;
V_71 |= V_215 << V_222 ;
V_71 = F_94 ( V_71 ) ;
* V_216 = V_71 ;
}
static unsigned long F_111 ( struct V_2 * V_5 ,
struct V_27 * V_28 ,
T_4 V_69 , unsigned int V_70 )
{
T_1 V_71 = 0 ;
F_51 ( & V_28 -> V_207 ) ;
if ( V_28 -> V_208 == V_28 -> V_209 )
V_71 |= V_223 ;
if ( V_28 -> V_50 )
V_71 |= V_224 ;
F_52 ( & V_28 -> V_207 ) ;
return V_71 ;
}
static void F_112 ( struct V_2 * V_2 , struct V_27 * V_28 ,
T_4 V_69 , unsigned int V_70 ,
unsigned long V_79 )
{
F_51 ( & V_28 -> V_207 ) ;
V_28 -> V_50 = ! ! ( V_79 & V_224 ) ;
F_100 ( V_2 , V_28 ) ;
F_52 ( & V_28 -> V_207 ) ;
}
static void F_113 ( struct V_2 * V_2 , struct V_27 * V_28 ,
T_4 V_69 , unsigned int V_70 , unsigned long V_79 )
{
}
void F_114 ( struct V_4 * V_5 )
{
if ( ! ( V_5 -> V_8 . V_60 . V_61 & V_225 ) )
F_35 ( V_5 ) ;
}
static int F_115 ( struct V_2 * V_2 , struct V_27 * V_28 ,
T_2 V_69 )
{
struct V_101 * V_104 = & V_28 -> V_104 ;
int V_12 ;
F_51 ( & V_2 -> V_226 ) ;
if ( ! F_116 ( V_28 -> V_227 ) ) {
V_12 = - V_98 ;
goto V_213;
}
V_28 -> V_227 = V_69 ;
V_104 -> V_228 = V_229 ;
V_104 -> V_230 = F_117 ( V_229 ) ;
F_118 ( & V_104 -> V_103 , & V_106 ) ;
V_104 -> V_231 = V_28 -> V_227 ;
V_104 -> V_107 = V_108 ;
V_104 -> V_28 = V_28 ;
V_12 = F_119 ( V_2 , V_118 , V_104 -> V_231 ,
V_232 , & V_104 -> V_103 ) ;
V_213:
F_52 ( & V_2 -> V_226 ) ;
return V_12 ;
}
static int F_120 ( struct V_233 * V_103 , T_1 type )
{
struct V_27 * V_28 ;
if ( type != V_234 )
return - V_113 ;
V_28 = F_3 ( sizeof( struct V_27 ) , V_13 ) ;
if ( ! V_28 )
return - V_14 ;
F_121 ( & V_28 -> V_119 ) ;
F_121 ( & V_28 -> V_207 ) ;
V_28 -> V_227 = V_235 ;
F_5 ( & V_28 -> V_161 ) ;
F_5 ( & V_28 -> V_147 ) ;
V_103 -> V_2 -> V_8 . V_9 . V_236 = true ;
V_103 -> V_2 -> V_8 . V_9 . V_237 = true ;
V_28 -> V_50 = false ;
V_28 -> V_103 = V_103 ;
V_28 -> V_163 = V_238 |
( ( T_2 ) V_138 << V_222 ) ;
V_28 -> V_143 = V_238 |
( ( T_2 ) V_139 << V_222 ) ;
V_103 -> V_2 -> V_8 . V_9 . V_46 = V_239 ;
V_103 -> V_240 = V_28 ;
return F_17 ( V_28 , V_85 - 1 ) ;
}
static void F_122 ( struct V_2 * V_2 , struct V_34 * V_103 )
{
struct V_37 * V_39 , * V_241 ;
F_79 (ite, tmp, &dev->itt_head, ite_list)
F_53 ( V_2 , V_39 ) ;
F_54 ( & V_103 -> V_159 ) ;
F_10 ( V_103 ) ;
}
static void F_123 ( struct V_233 * V_242 )
{
struct V_2 * V_2 = V_242 -> V_2 ;
struct V_27 * V_28 = V_242 -> V_240 ;
struct V_243 * V_244 , * V_158 ;
if ( ! V_28 -> V_161 . V_245 )
return;
F_51 ( & V_28 -> V_119 ) ;
F_124 (cur, temp, &its->device_list) {
struct V_34 * V_103 ;
V_103 = F_125 ( V_244 , struct V_34 , V_159 ) ;
F_122 ( V_2 , V_103 ) ;
}
F_124 (cur, temp, &its->collection_list) {
struct V_40 * V_56 ;
V_56 = F_125 ( V_244 , struct V_40 , V_146 ) ;
F_54 ( V_244 ) ;
F_10 ( V_56 ) ;
}
F_52 ( & V_28 -> V_119 ) ;
F_10 ( V_28 ) ;
}
int F_126 ( struct V_233 * V_103 ,
struct V_246 * V_247 )
{
const struct V_248 * V_249 ;
T_4 V_250 = V_247 -> V_247 ;
int V_251 ;
V_251 = ( V_250 < V_252 ) || ( V_250 >= V_91 ) ? 0x3 : 0x7 ;
if ( V_250 & V_251 )
return - V_86 ;
V_249 = F_127 ( V_229 ,
F_117 ( V_229 ) ,
V_250 ) ;
if ( ! V_249 )
return - V_253 ;
return 0 ;
}
int F_128 ( struct V_233 * V_103 ,
struct V_246 * V_247 ,
T_2 * V_71 , bool V_254 )
{
const struct V_248 * V_249 ;
struct V_27 * V_28 ;
T_4 V_69 , V_250 ;
unsigned int V_70 ;
int V_251 , V_12 = 0 ;
V_28 = V_103 -> V_240 ;
V_250 = V_247 -> V_247 ;
if ( ( V_250 < V_252 ) || ( V_250 >= V_91 ) )
V_251 = 0x3 ;
else
V_251 = 0x7 ;
if ( V_250 & V_251 )
return - V_86 ;
F_51 ( & V_103 -> V_2 -> V_255 ) ;
if ( F_116 ( V_28 -> V_227 ) ) {
V_12 = - V_253 ;
goto V_213;
}
V_249 = F_127 ( V_229 ,
F_117 ( V_229 ) ,
V_250 ) ;
if ( ! V_249 ) {
V_12 = - V_253 ;
goto V_213;
}
if ( ! F_129 ( V_103 -> V_2 ) ) {
V_12 = - V_98 ;
goto V_213;
}
V_69 = V_28 -> V_227 + V_250 ;
V_70 = V_249 -> V_256 & V_257 ? 8 : 4 ;
if ( V_254 ) {
if ( V_249 -> V_258 )
V_12 = V_249 -> V_258 ( V_103 -> V_2 , V_28 , V_69 ,
V_70 , * V_71 ) ;
else
V_249 -> V_259 ( V_103 -> V_2 , V_28 , V_69 , V_70 , * V_71 ) ;
} else {
* V_71 = V_249 -> V_260 ( V_103 -> V_2 , V_28 , V_69 , V_70 ) ;
}
F_130 ( V_103 -> V_2 ) ;
V_213:
F_52 ( & V_103 -> V_2 -> V_255 ) ;
return V_12 ;
}
static T_1 F_131 ( struct V_243 * V_261 ,
struct V_34 * V_103 )
{
struct V_34 * V_245 ;
T_1 V_262 ;
if ( F_132 ( & V_103 -> V_159 , V_261 ) )
return 0 ;
V_245 = F_133 ( V_103 , V_159 ) ;
V_262 = V_245 -> V_35 - V_103 -> V_35 ;
return F_134 ( T_1 , V_262 , V_263 ) ;
}
static T_1 F_135 ( struct V_243 * V_261 , struct V_37 * V_39 )
{
struct V_37 * V_245 ;
T_1 V_262 ;
if ( F_132 ( & V_39 -> V_121 , V_261 ) )
return 0 ;
V_245 = F_133 ( V_39 , V_121 ) ;
V_262 = V_245 -> V_38 - V_39 -> V_38 ;
return F_134 ( T_1 , V_262 , V_264 ) ;
}
static int F_136 ( struct V_27 * V_28 , T_4 V_265 , int V_125 , int V_135 ,
int V_266 , T_8 V_267 , void * V_268 )
{
void * V_269 = F_3 ( V_135 , V_13 ) ;
struct V_2 * V_2 = V_28 -> V_103 -> V_2 ;
unsigned long V_70 = V_125 ;
int V_130 = V_266 ;
T_4 V_270 = V_265 ;
int V_12 ;
while ( V_70 > 0 ) {
int V_262 ;
T_9 V_64 ;
V_12 = F_22 ( V_2 , V_270 , V_269 , V_135 ) ;
if ( V_12 )
goto V_213;
V_262 = V_267 ( V_28 , V_130 , V_269 , V_268 ) ;
if ( V_262 <= 0 ) {
V_12 = V_262 ;
goto V_213;
}
V_64 = V_262 * V_135 ;
V_130 += V_262 ;
V_270 += V_64 ;
V_70 -= V_64 ;
}
V_12 = 1 ;
V_213:
F_10 ( V_269 ) ;
return V_12 ;
}
static int F_137 ( struct V_27 * V_28 , struct V_34 * V_103 ,
struct V_37 * V_39 , T_4 V_270 , int V_77 )
{
struct V_2 * V_2 = V_28 -> V_103 -> V_2 ;
T_1 V_262 ;
T_2 V_79 ;
V_262 = F_135 ( & V_103 -> V_150 , V_39 ) ;
V_79 = ( ( T_2 ) V_262 << V_271 ) |
( ( T_2 ) V_39 -> V_149 << V_272 ) |
V_39 -> V_42 -> V_43 ;
V_79 = F_138 ( V_79 ) ;
return F_139 ( V_2 , V_270 , & V_79 , V_77 ) ;
}
static int F_140 ( struct V_27 * V_28 , T_1 V_38 ,
void * V_273 , void * V_268 )
{
struct V_34 * V_103 = (struct V_34 * ) V_268 ;
struct V_40 * V_42 ;
struct V_2 * V_2 = V_28 -> V_103 -> V_2 ;
struct V_4 * V_5 = NULL ;
T_2 V_79 ;
T_2 * V_274 = ( T_2 * ) V_273 ;
struct V_1 * V_10 ;
T_1 V_41 , V_148 ;
struct V_37 * V_39 ;
T_1 V_250 ;
V_79 = * V_274 ;
V_79 = F_56 ( V_79 ) ;
V_41 = V_79 & V_275 ;
V_148 = ( V_79 & V_276 ) >> V_272 ;
if ( ! V_148 )
return 1 ;
if ( V_148 < V_277 )
return - V_86 ;
V_250 = V_79 >> V_271 ;
if ( V_38 + V_250 >= F_57 ( V_103 -> V_154 ) )
return - V_86 ;
V_42 = F_20 ( V_28 , V_41 ) ;
if ( ! V_42 )
return - V_86 ;
V_39 = F_72 ( V_103 , V_42 , V_148 , V_38 ) ;
if ( F_76 ( V_39 ) )
return F_77 ( V_39 ) ;
if ( F_29 ( V_42 ) )
V_5 = F_30 ( V_2 , V_42 -> V_55 ) ;
V_10 = F_1 ( V_2 , V_148 , V_5 ) ;
if ( F_76 ( V_10 ) )
return F_77 ( V_10 ) ;
V_39 -> V_10 = V_10 ;
return V_250 ;
}
static int F_141 ( void * V_278 , struct V_243 * V_279 ,
struct V_243 * V_280 )
{
struct V_37 * V_281 = F_47 ( V_279 , struct V_37 , V_121 ) ;
struct V_37 * V_282 = F_47 ( V_280 , struct V_37 , V_121 ) ;
if ( V_281 -> V_38 < V_282 -> V_38 )
return - 1 ;
else
return 1 ;
}
static int F_142 ( struct V_27 * V_28 , struct V_34 * V_36 )
{
const struct V_26 * V_32 = F_16 ( V_28 ) ;
T_4 V_265 = V_36 -> V_160 ;
struct V_37 * V_39 ;
int V_12 ;
int V_77 = V_32 -> V_77 ;
F_143 ( NULL , & V_36 -> V_150 , F_141 ) ;
F_9 (ite, &device->itt_head, ite_list) {
T_4 V_270 = V_265 + V_39 -> V_38 * V_77 ;
V_12 = F_137 ( V_28 , V_36 , V_39 , V_270 , V_77 ) ;
if ( V_12 )
return V_12 ;
}
return 0 ;
}
static int F_144 ( struct V_27 * V_28 , struct V_34 * V_103 )
{
const struct V_26 * V_32 = F_16 ( V_28 ) ;
T_4 V_265 = V_103 -> V_160 ;
int V_12 ;
int V_77 = V_32 -> V_77 ;
T_9 V_283 = F_57 ( V_103 -> V_154 ) * V_77 ;
V_12 = F_136 ( V_28 , V_265 , V_283 , V_77 , 0 ,
F_140 , V_103 ) ;
return V_12 ;
}
static int F_145 ( struct V_27 * V_28 , struct V_34 * V_103 ,
T_4 V_273 , int V_218 )
{
struct V_2 * V_2 = V_28 -> V_103 -> V_2 ;
T_2 V_79 , V_284 ;
T_1 V_262 ;
V_284 = V_103 -> V_160 >> 8 ;
V_262 = F_131 ( & V_28 -> V_161 , V_103 ) ;
V_79 = ( 1ULL << V_285 |
( ( T_2 ) V_262 << V_286 ) |
( V_284 << V_287 ) |
( V_103 -> V_154 - 1 ) ) ;
V_79 = F_138 ( V_79 ) ;
return F_139 ( V_2 , V_273 , & V_79 , V_218 ) ;
}
static int F_146 ( struct V_27 * V_28 , T_1 V_130 ,
void * V_273 , void * V_268 )
{
struct V_34 * V_103 ;
T_4 V_160 ;
T_3 V_154 ;
T_2 V_269 = * ( T_2 * ) V_273 ;
bool V_162 ;
T_1 V_250 ;
int V_12 ;
V_269 = F_56 ( V_269 ) ;
V_162 = V_269 >> V_285 ;
V_154 = ( V_269 & V_288 ) + 1 ;
V_160 = ( ( V_269 & V_289 )
>> V_287 ) << 8 ;
if ( ! V_162 )
return 1 ;
V_250 = ( V_269 & V_290 ) >> V_286 ;
V_103 = F_80 ( V_28 , V_130 , V_160 , V_154 ) ;
if ( F_76 ( V_103 ) )
return F_77 ( V_103 ) ;
V_12 = F_144 ( V_28 , V_103 ) ;
if ( V_12 ) {
F_122 ( V_28 -> V_103 -> V_2 , V_103 ) ;
return V_12 ;
}
return V_250 ;
}
static int F_147 ( void * V_278 , struct V_243 * V_279 ,
struct V_243 * V_280 )
{
struct V_34 * V_291 = F_47 ( V_279 , struct V_34 , V_159 ) ;
struct V_34 * V_292 = F_47 ( V_280 , struct V_34 , V_159 ) ;
if ( V_291 -> V_35 < V_292 -> V_35 )
return - 1 ;
else
return 1 ;
}
static int F_148 ( struct V_27 * V_28 )
{
const struct V_26 * V_32 = F_16 ( V_28 ) ;
struct V_34 * V_103 ;
int V_218 = V_32 -> V_218 ;
T_2 V_129 ;
V_129 = V_28 -> V_163 ;
F_143 ( NULL , & V_28 -> V_161 , F_147 ) ;
F_9 (dev, &its->device_list, dev_list) {
int V_12 ;
T_4 V_131 ;
if ( ! F_63 ( V_28 , V_129 ,
V_103 -> V_35 , & V_131 ) )
return - V_86 ;
V_12 = F_142 ( V_28 , V_103 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_145 ( V_28 , V_103 , V_131 , V_218 ) ;
if ( V_12 )
return V_12 ;
}
return 0 ;
}
static int F_149 ( struct V_27 * V_28 , T_1 V_130 , void * V_69 ,
void * V_268 )
{
const struct V_26 * V_32 = F_16 ( V_28 ) ;
int V_293 = V_130 * ( V_133 / V_32 -> V_218 ) ;
T_2 V_269 = * ( T_2 * ) V_69 ;
int V_218 = V_32 -> V_218 ;
T_4 V_270 ;
int V_12 ;
V_269 = F_56 ( V_269 ) ;
if ( ! ( V_269 & V_294 ) )
return 1 ;
V_270 = V_269 & V_295 ;
V_12 = F_136 ( V_28 , V_270 , V_133 , V_218 ,
V_293 , F_146 , NULL ) ;
if ( V_12 <= 0 )
return V_12 ;
return 1 ;
}
static int F_150 ( struct V_27 * V_28 )
{
const struct V_26 * V_32 = F_16 ( V_28 ) ;
T_2 V_129 = V_28 -> V_163 ;
int V_296 , V_12 ;
int V_132 = F_64 ( V_129 ) * V_133 ;
T_4 V_297 ;
if ( ! ( V_129 & V_298 ) )
return 0 ;
V_297 = F_67 ( V_129 ) ;
if ( V_129 & V_140 ) {
V_296 = V_299 ;
V_12 = F_136 ( V_28 , V_297 , V_132 , V_296 , 0 ,
F_149 , NULL ) ;
} else {
V_296 = V_32 -> V_218 ;
V_12 = F_136 ( V_28 , V_297 , V_132 , V_296 , 0 ,
F_146 , NULL ) ;
}
if ( V_12 > 0 )
V_12 = - V_86 ;
return V_12 ;
}
static int F_151 ( struct V_27 * V_28 ,
struct V_40 * V_42 ,
T_4 V_270 , int V_135 )
{
T_2 V_79 ;
V_79 = ( 1ULL << V_300 |
( ( T_2 ) V_42 -> V_55 << V_301 ) |
V_42 -> V_43 ) ;
V_79 = F_138 ( V_79 ) ;
return F_139 ( V_28 -> V_103 -> V_2 , V_270 , & V_79 , V_135 ) ;
}
static int F_152 ( struct V_27 * V_28 , T_4 V_270 , int V_135 )
{
struct V_40 * V_42 ;
struct V_2 * V_2 = V_28 -> V_103 -> V_2 ;
T_1 V_55 , V_41 ;
T_2 V_79 ;
int V_12 ;
F_153 ( V_135 > sizeof( V_79 ) ) ;
V_12 = F_22 ( V_2 , V_270 , & V_79 , V_135 ) ;
if ( V_12 )
return V_12 ;
V_79 = F_56 ( V_79 ) ;
if ( ! ( V_79 & V_302 ) )
return 0 ;
V_55 = ( T_1 ) ( V_79 >> V_301 ) ;
V_41 = V_79 & V_303 ;
if ( V_55 >= F_87 ( & V_2 -> V_166 ) )
return - V_86 ;
V_42 = F_20 ( V_28 , V_41 ) ;
if ( V_42 )
return - V_304 ;
V_12 = F_70 ( V_28 , & V_42 , V_41 ) ;
if ( V_12 )
return V_12 ;
V_42 -> V_55 = V_55 ;
return 1 ;
}
static int F_154 ( struct V_27 * V_28 )
{
const struct V_26 * V_32 = F_16 ( V_28 ) ;
struct V_40 * V_42 ;
T_2 V_79 ;
T_4 V_270 ;
T_9 V_283 , V_305 = 0 ;
int V_12 , V_219 = V_32 -> V_219 ;
V_270 = F_67 ( V_28 -> V_143 ) ;
if ( ! V_270 )
return 0 ;
V_283 = F_64 ( V_28 -> V_143 ) * V_133 ;
F_9 (collection, &its->collection_list, coll_list) {
V_12 = F_151 ( V_28 , V_42 , V_270 , V_219 ) ;
if ( V_12 )
return V_12 ;
V_270 += V_219 ;
V_305 += V_219 ;
}
if ( V_305 == V_283 )
return 0 ;
V_79 = 0 ;
F_153 ( V_219 > sizeof( V_79 ) ) ;
V_12 = F_139 ( V_28 -> V_103 -> V_2 , V_270 , & V_79 , V_219 ) ;
return V_12 ;
}
static int F_155 ( struct V_27 * V_28 )
{
const struct V_26 * V_32 = F_16 ( V_28 ) ;
int V_219 = V_32 -> V_219 ;
T_9 V_283 , V_306 = 0 ;
T_4 V_270 ;
int V_12 ;
if ( ! ( V_28 -> V_143 & V_298 ) )
return 0 ;
V_270 = F_67 ( V_28 -> V_143 ) ;
V_283 = F_64 ( V_28 -> V_143 ) * V_133 ;
while ( V_306 < V_283 ) {
V_12 = F_152 ( V_28 , V_270 , V_219 ) ;
if ( V_12 <= 0 )
break;
V_270 += V_219 ;
V_306 += V_219 ;
}
return V_12 ;
}
static int F_156 ( struct V_27 * V_28 )
{
struct V_2 * V_2 = V_28 -> V_103 -> V_2 ;
int V_12 ;
F_51 ( & V_2 -> V_255 ) ;
F_51 ( & V_28 -> V_119 ) ;
if ( ! F_129 ( V_2 ) ) {
F_52 ( & V_28 -> V_119 ) ;
F_52 ( & V_2 -> V_255 ) ;
return - V_98 ;
}
V_12 = F_148 ( V_28 ) ;
if ( V_12 )
goto V_213;
V_12 = F_154 ( V_28 ) ;
V_213:
F_130 ( V_2 ) ;
F_52 ( & V_28 -> V_119 ) ;
F_52 ( & V_2 -> V_255 ) ;
return V_12 ;
}
static int F_157 ( struct V_27 * V_28 )
{
struct V_2 * V_2 = V_28 -> V_103 -> V_2 ;
int V_12 ;
F_51 ( & V_2 -> V_255 ) ;
F_51 ( & V_28 -> V_119 ) ;
if ( ! F_129 ( V_2 ) ) {
F_52 ( & V_28 -> V_119 ) ;
F_52 ( & V_2 -> V_255 ) ;
return - V_98 ;
}
V_12 = F_155 ( V_28 ) ;
if ( V_12 )
goto V_213;
V_12 = F_150 ( V_28 ) ;
V_213:
F_130 ( V_2 ) ;
F_52 ( & V_28 -> V_119 ) ;
F_52 ( & V_2 -> V_255 ) ;
return V_12 ;
}
static int F_158 ( struct V_27 * V_28 )
{
const struct V_26 * V_32 ;
V_32 = F_16 ( V_28 ) ;
V_28 -> V_143 &= ~ V_307 ;
V_28 -> V_163 &= ~ V_307 ;
V_28 -> V_143 |= ( F_39 ( V_32 -> V_219 , 5 )
<< V_221 ) ;
V_28 -> V_163 |= ( F_39 ( V_32 -> V_218 , 5 )
<< V_221 ) ;
return 0 ;
}
static int F_159 ( struct V_233 * V_103 ,
struct V_246 * V_247 )
{
switch ( V_247 -> V_308 ) {
case V_309 :
switch ( V_247 -> V_247 ) {
case V_310 :
return 0 ;
}
break;
case V_311 :
switch ( V_247 -> V_247 ) {
case V_312 :
return 0 ;
case V_313 :
return 0 ;
case V_314 :
return 0 ;
}
break;
case V_315 :
return F_126 ( V_103 , V_247 ) ;
}
return - V_253 ;
}
static int F_160 ( struct V_233 * V_103 ,
struct V_246 * V_247 )
{
struct V_27 * V_28 = V_103 -> V_240 ;
int V_12 ;
switch ( V_247 -> V_308 ) {
case V_309 : {
T_2 T_10 * V_316 = ( T_2 T_10 * ) ( long ) V_247 -> V_69 ;
unsigned long type = ( unsigned long ) V_247 -> V_247 ;
T_2 V_69 ;
if ( type != V_310 )
return - V_113 ;
if ( F_161 ( & V_69 , V_316 , sizeof( V_69 ) ) )
return - V_317 ;
V_12 = F_162 ( V_103 -> V_2 , & V_28 -> V_227 ,
V_69 , V_133 ) ;
if ( V_12 )
return V_12 ;
return F_115 ( V_103 -> V_2 , V_28 , V_69 ) ;
}
case V_311 : {
const struct V_26 * V_32 = F_16 ( V_28 ) ;
switch ( V_247 -> V_247 ) {
case V_312 :
return 0 ;
case V_313 :
return V_32 -> V_318 ( V_28 ) ;
case V_314 :
return V_32 -> V_319 ( V_28 ) ;
}
}
case V_315 : {
T_2 T_10 * V_316 = ( T_2 T_10 * ) ( long ) V_247 -> V_69 ;
T_2 V_71 ;
if ( F_163 ( V_71 , V_316 ) )
return - V_317 ;
return F_128 ( V_103 , V_247 , & V_71 , true ) ;
}
}
return - V_253 ;
}
static int F_164 ( struct V_233 * V_103 ,
struct V_246 * V_247 )
{
switch ( V_247 -> V_308 ) {
case V_309 : {
struct V_27 * V_28 = V_103 -> V_240 ;
T_2 V_69 = V_28 -> V_227 ;
T_2 T_10 * V_316 = ( T_2 T_10 * ) ( long ) V_247 -> V_69 ;
unsigned long type = ( unsigned long ) V_247 -> V_247 ;
if ( type != V_310 )
return - V_113 ;
if ( F_165 ( V_316 , & V_69 , sizeof( V_69 ) ) )
return - V_317 ;
break;
}
case V_315 : {
T_2 T_10 * V_316 = ( T_2 T_10 * ) ( long ) V_247 -> V_69 ;
T_2 V_71 ;
int V_12 ;
V_12 = F_128 ( V_103 , V_247 , & V_71 , false ) ;
if ( V_12 )
return V_12 ;
return F_166 ( V_71 , V_316 ) ;
}
default:
return - V_253 ;
}
return 0 ;
}
int F_167 ( void )
{
return F_168 ( & V_320 ,
V_234 ) ;
}
