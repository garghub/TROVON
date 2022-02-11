int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 = 0 ;
int V_7 ;
if ( V_3 != V_5 -> V_8 ) {
V_6 = F_3 ( V_2 , V_9 , V_3 ) ;
V_7 = F_4 ( V_2 , V_9 ) ;
if ( V_7 != V_3 )
V_6 = - V_10 ;
else
V_5 -> V_8 = V_3 ;
}
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_11 )
{
int V_6 ;
V_6 = F_1 ( V_2 , V_3 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_6 ( V_2 , V_11 ) ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_12 ,
T_2 V_13 )
{
int V_6 ;
V_6 = F_1 ( V_2 , V_3 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_8 ( V_2 , V_12 , V_13 ) ;
}
int F_9 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_12 )
{
int V_6 ;
V_6 = F_1 ( V_2 , V_3 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_10 ( V_2 , V_12 ) ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_12 )
{
int V_6 ;
V_6 = F_1 ( V_2 , V_3 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_4 ( V_2 , V_12 ) ;
}
static void F_12 ( struct V_1 * V_2 , int V_3 )
{
F_5 ( V_2 , V_3 , V_14 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_5 -> V_16 -> V_17 ; V_15 ++ )
F_12 ( V_2 , V_15 ) ;
}
static int F_14 ( struct V_1 * V_2 , int V_3 )
{
int V_18 , V_19 ;
V_18 = F_11 ( V_2 , V_3 , V_20 ) ;
if ( V_18 < 0 || ( V_18 & V_21 ) ) {
V_19 = F_11 ( V_2 , V_3 , V_22 ) ;
if ( V_19 < 0 || ( V_19 & V_23 ) )
return - V_10 ;
}
return 0 ;
}
bool F_15 ( struct V_1 * V_2 , int V_3 , int V_12 )
{
int V_6 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_6 = F_11 ( V_2 , V_3 , V_12 ) ;
if ( V_6 >= 0 && ! ( V_5 -> V_24 & V_25 ) )
V_6 = F_14 ( V_2 , V_3 ) ;
F_12 ( V_2 , V_3 ) ;
return V_6 >= 0 ;
}
bool F_16 ( struct V_1 * V_2 , int V_3 , int V_12 )
{
int V_6 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_6 = F_9 ( V_2 , V_3 , V_12 ) ;
if ( V_6 >= 0 && ! ( V_5 -> V_24 & V_25 ) )
V_6 = F_14 ( V_2 , V_3 ) ;
F_12 ( V_2 , V_3 ) ;
return V_6 >= 0 ;
}
const struct V_26 * F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_16 ;
}
static int F_18 ( struct V_1 * V_2 , int V_3 , int V_12 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_26 * V_16 = V_5 -> V_16 ;
int V_18 ;
if ( V_16 -> V_27 ) {
V_18 = V_16 -> V_27 ( V_2 , V_3 , V_12 ) ;
if ( V_18 != - V_28 )
return V_18 ;
}
return F_11 ( V_2 , V_3 , V_12 ) ;
}
static struct V_4 * F_19 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_20 ( V_30 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_26 * V_16 = V_5 -> V_16 ;
F_21 ( & V_5 -> V_31 ) ;
if ( F_22 ( V_32 , V_5 -> V_33 + V_34 ) || ! V_5 -> V_35 ) {
int V_15 ;
for ( V_15 = 0 ; V_15 < V_16 -> V_17 ; V_15 ++ )
V_5 -> V_18 [ V_36 + V_15 ]
= F_11 ( V_2 , V_15 ,
V_20 ) ;
for ( V_15 = 0 ; V_15 < V_16 -> V_17 ; V_15 ++ ) {
if ( ! ( V_16 -> V_37 [ V_15 ] & V_38 ) )
continue;
V_5 -> V_18 [ V_39 + V_15 ]
= F_18 ( V_2 , V_15 , V_40 ) ;
}
for ( V_15 = 0 ; V_15 < V_16 -> V_17 ; V_15 ++ ) {
if ( ! ( V_16 -> V_37 [ V_15 ] & V_41 ) )
continue;
V_5 -> V_18 [ V_42 + V_15 ]
= F_18 ( V_2 , V_15 , V_43 ) ;
}
for ( V_15 = 0 ; V_15 < V_16 -> V_17 ; V_15 ++ ) {
if ( ! ( V_16 -> V_37 [ V_15 ] & V_44 ) )
continue;
V_5 -> V_18 [ V_45 + V_15 ]
= F_18 ( V_2 , V_15 ,
V_46 ) ;
}
for ( V_15 = 0 ; V_15 < V_16 -> V_17 ; V_15 ++ ) {
if ( ! ( V_16 -> V_37 [ V_15 ] & V_47 ) )
continue;
V_5 -> V_18 [ V_48 + V_15 ]
= F_18 ( V_2 , V_15 ,
V_49 ) ;
}
for ( V_15 = 0 ; V_15 < V_16 -> V_17 ; V_15 ++ ) {
if ( ! ( V_16 -> V_37 [ V_15 ] & V_50 ) )
continue;
V_5 -> V_18 [ V_51 + V_15 ]
= F_18 ( V_2 , V_15 ,
V_52 ) ;
}
if ( V_16 -> V_37 [ 0 ] & V_53 )
V_5 -> V_18 [ V_54 ]
= F_18 ( V_2 , 0 ,
V_55 ) ;
for ( V_15 = 0 ; V_15 < V_5 -> V_56 ; V_15 ++ ) {
struct V_57 * V_58 = & V_5 -> V_59 [ V_15 ] ;
if ( ! V_5 -> V_35 || V_58 -> V_60 )
V_58 -> V_5
= F_9 ( V_2 , V_58 -> V_3 ,
V_58 -> V_12 ) ;
}
F_13 ( V_2 ) ;
V_5 -> V_33 = V_32 ;
V_5 -> V_35 = 1 ;
}
F_23 ( & V_5 -> V_31 ) ;
return V_5 ;
}
static long F_24 ( struct V_4 * V_5 ,
struct V_57 * V_58 )
{
T_3 V_61 ;
T_4 V_62 ;
long V_63 ;
if ( V_58 -> V_64 == V_65 ) {
V_61 = V_5 -> V_61 ;
V_62 = ( T_2 ) V_58 -> V_5 ;
} else {
V_61 = ( V_58 -> V_5 >> 11 ) & 0x001f ;
V_62 = V_58 -> V_5 & 0x07ff ;
if ( V_61 > 0x0f )
V_61 |= 0xffe0 ;
if ( V_62 > 0x03ff )
V_62 |= 0xfffff800 ;
}
V_63 = V_62 ;
if ( V_58 -> V_64 != V_66 )
V_63 = V_63 * 1000L ;
if ( V_58 -> V_64 == V_67 )
V_63 = V_63 * 1000L ;
if ( V_61 >= 0 )
V_63 <<= V_61 ;
else
V_63 >>= - V_61 ;
return V_63 ;
}
static long F_25 ( struct V_4 * V_5 ,
struct V_57 * V_58 )
{
long V_63 = ( T_3 ) V_58 -> V_5 ;
long V_68 , V_69 , V_70 ;
V_68 = V_5 -> V_16 -> V_68 [ V_58 -> V_64 ] ;
V_69 = V_5 -> V_16 -> V_69 [ V_58 -> V_64 ] ;
V_70 = V_5 -> V_16 -> V_70 [ V_58 -> V_64 ] ;
if ( V_68 == 0 )
return 0 ;
V_70 = - V_70 ;
if ( V_58 -> V_64 != V_66 ) {
V_70 += 3 ;
V_69 *= 1000 ;
}
if ( V_58 -> V_64 == V_67 ) {
V_70 += 3 ;
V_69 *= 1000 ;
}
while ( V_70 > 0 ) {
V_63 *= 10 ;
V_70 -- ;
}
while ( V_70 < 0 ) {
V_63 = F_26 ( V_63 , 10 ) ;
V_70 ++ ;
}
return ( V_63 - V_69 ) / V_68 ;
}
static long F_27 ( struct V_4 * V_5 , struct V_57 * V_58 )
{
long V_63 ;
if ( V_5 -> V_16 -> V_71 [ V_58 -> V_64 ] )
V_63 = F_25 ( V_5 , V_58 ) ;
else
V_63 = F_24 ( V_5 , V_58 ) ;
return V_63 ;
}
static T_2 F_28 ( struct V_4 * V_5 ,
enum V_72 V_64 , long V_63 )
{
T_3 V_61 = 0 , V_62 ;
bool V_73 = false ;
if ( V_63 == 0 )
return 0 ;
if ( V_64 == V_65 ) {
if ( V_63 < 0 )
return 0 ;
if ( V_5 -> V_61 < 0 )
V_63 <<= - V_5 -> V_61 ;
else
V_63 >>= V_5 -> V_61 ;
V_63 = F_26 ( V_63 , 1000 ) ;
return V_63 & 0xffff ;
}
if ( V_63 < 0 ) {
V_73 = true ;
V_63 = - V_63 ;
}
if ( V_64 == V_67 )
V_63 = F_26 ( V_63 , 1000L ) ;
if ( V_64 == V_66 )
V_63 = V_63 * 1000 ;
while ( V_63 >= V_74 && V_61 < 15 ) {
V_61 ++ ;
V_63 >>= 1 ;
}
while ( V_63 < V_75 && V_61 > - 15 ) {
V_61 -- ;
V_63 <<= 1 ;
}
V_62 = F_26 ( V_63 , 1000 ) ;
if ( V_62 > 0x3ff )
V_62 = 0x3ff ;
if ( V_73 )
V_62 = - V_62 ;
return ( V_62 & 0x7ff ) | ( ( V_61 << 11 ) & 0xf800 ) ;
}
static T_2 F_29 ( struct V_4 * V_5 ,
enum V_72 V_64 , long V_63 )
{
long V_68 , V_69 , V_70 ;
V_68 = V_5 -> V_16 -> V_68 [ V_64 ] ;
V_69 = V_5 -> V_16 -> V_69 [ V_64 ] ;
V_70 = V_5 -> V_16 -> V_70 [ V_64 ] ;
if ( V_64 == V_67 ) {
V_70 -= 3 ;
V_69 *= 1000 ;
}
if ( V_64 != V_66 ) {
V_70 -= 3 ;
V_69 *= 1000 ;
}
V_63 = V_63 * V_68 + V_69 ;
while ( V_70 > 0 ) {
V_63 *= 10 ;
V_70 -- ;
}
while ( V_70 < 0 ) {
V_63 = F_26 ( V_63 , 10 ) ;
V_70 ++ ;
}
return V_63 ;
}
static T_2 F_30 ( struct V_4 * V_5 ,
enum V_72 V_64 , long V_63 )
{
T_2 V_76 ;
if ( V_5 -> V_16 -> V_71 [ V_64 ] )
V_76 = F_29 ( V_5 , V_64 , V_63 ) ;
else
V_76 = F_28 ( V_5 , V_64 , V_63 ) ;
return V_76 ;
}
static int F_31 ( struct V_4 * V_5 , int V_77 , int * V_63 )
{
T_1 V_78 = ( V_77 >> 24 ) & 0xff ;
T_1 V_79 = ( V_77 >> 16 ) & 0xff ;
T_1 V_12 = ( V_77 >> 8 ) & 0xff ;
T_1 V_80 = V_77 & 0xff ;
int V_18 ;
T_1 V_76 ;
V_18 = V_5 -> V_18 [ V_12 ] ;
if ( V_18 < 0 )
return V_18 ;
V_76 = V_18 & V_80 ;
if ( ! V_78 && ! V_79 )
* V_63 = ! ! V_76 ;
else {
long V_81 , V_82 ;
struct V_57 * V_83 , * V_84 ;
V_83 = & V_5 -> V_59 [ V_78 ] ;
if ( V_83 -> V_5 < 0 )
return V_83 -> V_5 ;
V_84 = & V_5 -> V_59 [ V_79 ] ;
if ( V_84 -> V_5 < 0 )
return V_84 -> V_5 ;
V_81 = F_27 ( V_5 , V_83 ) ;
V_82 = F_27 ( V_5 , V_84 ) ;
* V_63 = ! ! ( V_76 && V_81 >= V_82 ) ;
}
return 0 ;
}
static T_5 F_32 ( struct V_29 * V_30 ,
struct V_85 * V_86 , char * V_87 )
{
struct V_88 * V_89 = F_33 ( V_86 ) ;
struct V_4 * V_5 = F_19 ( V_30 ) ;
int V_63 ;
int V_90 ;
V_90 = F_31 ( V_5 , V_89 -> V_77 , & V_63 ) ;
if ( V_90 )
return V_90 ;
return snprintf ( V_87 , V_91 , L_1 , V_63 ) ;
}
static T_5 F_34 ( struct V_29 * V_30 ,
struct V_85 * V_86 , char * V_87 )
{
struct V_88 * V_89 = F_33 ( V_86 ) ;
struct V_4 * V_5 = F_19 ( V_30 ) ;
struct V_57 * V_58 ;
V_58 = & V_5 -> V_59 [ V_89 -> V_77 ] ;
if ( V_58 -> V_5 < 0 )
return V_58 -> V_5 ;
return snprintf ( V_87 , V_91 , L_2 , F_27 ( V_5 , V_58 ) ) ;
}
static T_5 F_35 ( struct V_29 * V_30 ,
struct V_85 * V_92 ,
const char * V_87 , T_6 V_93 )
{
struct V_88 * V_89 = F_33 ( V_92 ) ;
struct V_1 * V_2 = F_20 ( V_30 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_57 * V_58 = & V_5 -> V_59 [ V_89 -> V_77 ] ;
T_5 V_6 = V_93 ;
long V_63 = 0 ;
int V_94 ;
T_2 V_76 ;
if ( F_36 ( V_87 , 10 , & V_63 ) < 0 )
return - V_10 ;
F_21 ( & V_5 -> V_31 ) ;
V_76 = F_30 ( V_5 , V_58 -> V_64 , V_63 ) ;
V_94 = F_7 ( V_2 , V_58 -> V_3 , V_58 -> V_12 , V_76 ) ;
if ( V_94 < 0 )
V_6 = V_94 ;
else
V_5 -> V_59 [ V_89 -> V_77 ] . V_5 = V_76 ;
F_23 ( & V_5 -> V_31 ) ;
return V_6 ;
}
static T_5 F_37 ( struct V_29 * V_30 ,
struct V_85 * V_86 , char * V_87 )
{
struct V_1 * V_2 = F_20 ( V_30 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_88 * V_89 = F_33 ( V_86 ) ;
return snprintf ( V_87 , V_91 , L_3 ,
V_5 -> V_95 [ V_89 -> V_77 ] . V_96 ) ;
}
static void F_38 ( struct V_4 * V_5 ,
const char * V_97 , const char * type , int V_98 ,
int V_99 )
{
struct V_100 * boolean ;
F_39 ( V_5 -> V_101 >= V_5 -> V_102 ) ;
boolean = & V_5 -> V_103 [ V_5 -> V_101 ] ;
snprintf ( boolean -> V_97 , sizeof( boolean -> V_97 ) , L_4 ,
V_97 , V_98 , type ) ;
F_40 ( V_5 , boolean -> V_97 , boolean , V_99 ) ;
V_5 -> V_101 ++ ;
}
static void F_41 ( struct V_4 * V_5 ,
const char * V_97 , const char * type ,
int V_98 , int V_12 , int V_104 )
{
F_38 ( V_5 , V_97 , type , V_98 , ( V_12 << 8 ) | V_104 ) ;
}
static void F_42 ( struct V_4 * V_5 ,
const char * V_97 , const char * type ,
int V_98 , int V_105 , int V_106 , int V_12 , int V_80 )
{
F_38 ( V_5 , V_97 , type , V_98 ,
( V_105 << 24 ) | ( V_106 << 16 ) | ( V_12 << 8 ) | V_80 ) ;
}
static void F_43 ( struct V_4 * V_5 ,
const char * V_97 , const char * type , int V_98 ,
int V_3 , int V_12 , enum V_72 V_64 ,
bool V_60 , bool V_107 )
{
struct V_57 * V_58 ;
F_39 ( V_5 -> V_56 >= V_5 -> V_108 ) ;
V_58 = & V_5 -> V_59 [ V_5 -> V_56 ] ;
snprintf ( V_58 -> V_97 , sizeof( V_58 -> V_97 ) , L_4 ,
V_97 , V_98 , type ) ;
V_58 -> V_3 = V_3 ;
V_58 -> V_12 = V_12 ;
V_58 -> V_64 = V_64 ;
V_58 -> V_60 = V_60 ;
if ( V_107 )
F_40 ( V_5 , V_58 -> V_97 , V_58 ,
V_5 -> V_56 ) ;
else
F_44 ( V_5 , V_58 -> V_97 , V_58 ,
V_5 -> V_56 ) ;
V_5 -> V_56 ++ ;
}
static void F_45 ( struct V_4 * V_5 ,
const char * V_97 , int V_98 ,
const char * V_109 , int V_77 )
{
struct V_110 * V_96 ;
F_39 ( V_5 -> V_111 >= V_5 -> V_112 ) ;
V_96 = & V_5 -> V_95 [ V_5 -> V_111 ] ;
snprintf ( V_96 -> V_97 , sizeof( V_96 -> V_97 ) , L_5 , V_97 , V_98 ) ;
if ( ! V_77 )
strncpy ( V_96 -> V_96 , V_109 , sizeof( V_96 -> V_96 ) - 1 ) ;
else
snprintf ( V_96 -> V_96 , sizeof( V_96 -> V_96 ) , L_6 , V_109 ,
V_77 ) ;
F_40 ( V_5 , V_96 -> V_97 , V_96 , V_5 -> V_111 ) ;
V_5 -> V_111 ++ ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
const struct V_26 * V_16 = V_5 -> V_16 ;
int V_3 , V_108 , V_102 , V_112 ;
V_108 = V_113 ;
V_102 = V_114 ;
V_112 = V_115 ;
for ( V_3 = 0 ; V_3 < V_16 -> V_17 ; V_3 ++ ) {
if ( V_16 -> V_37 [ V_3 ] & V_116 ) {
V_108 += V_117 ;
V_102 += V_118 ;
V_112 ++ ;
}
if ( V_16 -> V_37 [ V_3 ] & V_119 ) {
V_108 += V_120 ;
V_102 += V_121 ;
V_112 ++ ;
}
if ( V_16 -> V_37 [ V_3 ] & V_122 ) {
V_108 += V_123 ;
V_102 += V_124 ;
V_112 ++ ;
}
if ( V_16 -> V_37 [ V_3 ] & V_125 ) {
V_108 += 2 * V_126 ;
V_102 += 2 * V_127 ;
}
if ( V_16 -> V_37 [ V_3 ] & V_128 ) {
V_108 += 2 * V_126 ;
V_102 += 2 * V_127 ;
}
if ( V_16 -> V_37 [ V_3 ] & V_129 ) {
V_108 += V_130 ;
V_102 += V_131 ;
}
if ( V_16 -> V_37 [ V_3 ] & V_132 ) {
V_108 += V_130 ;
V_102 += V_131 ;
}
if ( V_16 -> V_37 [ V_3 ] & V_133 ) {
V_108 += V_130 ;
V_102 += V_131 ;
}
}
V_5 -> V_108 = V_108 ;
V_5 -> V_102 = V_102 ;
V_5 -> V_112 = V_112 ;
V_5 -> V_134 = V_108 + V_102 + V_112 ;
}
static bool F_47 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
const struct V_26 * V_16 ,
const char * V_97 , int V_77 , int V_3 ,
int V_135 ,
const struct V_136 * V_89 )
{
const struct V_137 * V_138 = V_89 -> V_139 ;
int V_140 = V_89 -> V_140 ;
bool V_141 = false ;
int V_15 , V_142 ;
for ( V_15 = 0 ; V_15 < V_140 ; V_15 ++ ) {
if ( F_16 ( V_2 , V_3 , V_138 -> V_12 ) ) {
V_142 = V_5 -> V_56 ;
F_43 ( V_5 , V_97 , V_138 -> V_89 , V_77 , V_3 ,
V_138 -> V_12 , V_89 -> V_64 , V_89 -> V_60 ,
false ) ;
if ( V_16 -> V_37 [ V_3 ] & V_89 -> V_143 ) {
if ( V_89 -> V_144 ) {
F_42 ( V_5 , V_97 ,
V_138 -> V_145 , V_77 ,
V_135 , V_142 ,
V_89 -> V_146 + V_3 , V_138 -> V_147 ) ;
} else {
F_41 ( V_5 , V_97 ,
V_138 -> V_145 , V_77 ,
V_89 -> V_146 + V_3 , V_138 -> V_147 ) ;
}
V_141 = true ;
}
}
V_138 ++ ;
}
return V_141 ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
const struct V_26 * V_16 ,
const char * V_97 ,
int V_77 , int V_3 ,
const struct V_136 * V_89 )
{
bool V_141 ;
int V_135 = V_5 -> V_56 ;
if ( V_89 -> V_96 )
F_45 ( V_5 , V_97 , V_77 , V_89 -> V_96 ,
V_89 -> V_148 ? V_3 + 1 : 0 ) ;
F_43 ( V_5 , V_97 , L_7 , V_77 , V_3 , V_89 -> V_12 ,
V_89 -> V_64 , true , true ) ;
if ( V_89 -> V_143 ) {
V_141 = F_47 ( V_2 , V_5 , V_16 , V_97 ,
V_77 , V_3 , V_135 , V_89 ) ;
if ( ! V_141 && V_89 -> V_149 )
F_41 ( V_5 , V_97 , L_8 , V_77 ,
V_36 + V_3 ,
V_89 -> V_149 ) ;
}
}
static void F_49 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
const char * V_97 ,
const struct V_136 * V_150 ,
int V_151 )
{
const struct V_26 * V_16 = V_5 -> V_16 ;
int V_77 , V_15 ;
V_77 = 1 ;
for ( V_15 = 0 ; V_15 < V_151 ; V_15 ++ ) {
int V_3 , V_17 ;
V_17 = V_150 -> V_148 ? V_16 -> V_17 : 1 ;
for ( V_3 = 0 ; V_3 < V_17 ; V_3 ++ ) {
if ( ! ( V_16 -> V_37 [ V_3 ] & V_150 -> V_37 ) )
continue;
F_48 ( V_2 , V_5 , V_16 , V_97 ,
V_77 , V_3 , V_150 ) ;
V_77 ++ ;
}
V_150 ++ ;
}
}
static void F_50 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
const struct V_26 * V_16 = V_5 -> V_16 ;
int V_77 = 1 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_16 -> V_17 ; V_3 ++ ) {
int V_152 ;
for ( V_152 = 0 ; V_152 < F_51 ( V_153 ) ; V_152 ++ ) {
int V_76 ;
if ( ! ( V_16 -> V_37 [ V_3 ] & V_154 [ V_152 ] ) )
break;
if ( ! F_16 ( V_2 , V_3 ,
V_153 [ V_152 ] ) )
break;
V_76 = F_18 ( V_2 , V_3 ,
V_155 [ V_152 ] ) ;
if ( V_76 < 0 ||
( ! ( V_76 & ( V_156 >> ( ( V_152 & 1 ) * 4 ) ) ) ) )
continue;
F_43 ( V_5 , L_9 , L_7 , V_77 , V_3 ,
V_153 [ V_152 ] , V_66 , true ,
true ) ;
if ( ( V_16 -> V_37 [ V_3 ] & V_157 [ V_152 ] ) &&
F_15 ( V_2 ,
V_3 , V_158 [ V_152 ] ) ) {
int V_159 ;
if ( V_152 > 1 )
V_159 = V_51 + V_3 ;
else
V_159 = V_48 + V_3 ;
F_41 ( V_5 , L_9 , L_8 ,
V_77 , V_159 ,
V_160 >> ( V_152 & 1 ) ) ;
F_41 ( V_5 , L_9 , L_10 ,
V_77 , V_159 ,
V_161 >> ( V_152 & 1 ) ) ;
}
V_77 ++ ;
}
}
}
static void F_52 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
F_49 ( V_2 , V_5 , L_11 , V_162 ,
F_51 ( V_162 ) ) ;
F_49 ( V_2 , V_5 , L_12 , V_163 ,
F_51 ( V_163 ) ) ;
F_49 ( V_2 , V_5 , L_13 , V_164 ,
F_51 ( V_164 ) ) ;
F_49 ( V_2 , V_5 , L_14 , V_165 ,
F_51 ( V_165 ) ) ;
F_50 ( V_2 , V_5 ) ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
int V_166 = - 1 , V_61 ;
if ( F_15 ( V_2 , 0 , V_167 ) )
V_166 = F_11 ( V_2 , 0 , V_167 ) ;
if ( V_166 >= 0 && V_166 != 0xff ) {
switch ( V_166 >> 5 ) {
case 0 :
if ( V_5 -> V_16 -> V_71 [ V_65 ] )
return - V_168 ;
V_61 = V_166 & 0x1f ;
if ( V_61 & 0x10 )
V_61 |= ~ 0x1f ;
V_5 -> V_61 = V_61 ;
break;
case 2 :
if ( ! V_5 -> V_16 -> V_71 [ V_65 ] )
return - V_168 ;
break;
default:
return - V_168 ;
}
}
F_46 ( V_2 , V_5 ) ;
F_12 ( V_2 , 0 ) ;
return 0 ;
}
int F_54 ( struct V_1 * V_2 , const struct V_169 * V_170 ,
struct V_26 * V_16 )
{
const struct V_171 * V_172 = V_2 -> V_30 . V_173 ;
struct V_4 * V_5 ;
int V_94 ;
if ( ! V_16 ) {
F_55 ( & V_2 -> V_30 , L_15 ) ;
return - V_168 ;
}
if ( ! F_56 ( V_2 -> V_174 , V_175
| V_176
| V_177 ) )
return - V_168 ;
V_5 = F_57 ( sizeof( * V_5 ) , V_178 ) ;
if ( ! V_5 ) {
F_55 ( & V_2 -> V_30 , L_16 ) ;
return - V_179 ;
}
F_58 ( V_2 , V_5 ) ;
F_59 ( & V_5 -> V_31 ) ;
if ( F_4 ( V_2 , V_20 ) < 0 ) {
F_55 ( & V_2 -> V_30 , L_17 ) ;
V_94 = - V_168 ;
goto V_180;
}
if ( V_172 )
V_5 -> V_24 = V_172 -> V_24 ;
V_5 -> V_16 = V_16 ;
F_13 ( V_2 ) ;
if ( V_16 -> V_181 ) {
V_94 = (* V_16 -> V_181 )( V_2 , V_16 ) ;
if ( V_94 < 0 ) {
F_55 ( & V_2 -> V_30 , L_18 ) ;
goto V_180;
}
}
if ( V_16 -> V_17 <= 0 || V_16 -> V_17 > V_182 ) {
F_55 ( & V_2 -> V_30 , L_19 ,
V_16 -> V_17 ) ;
V_94 = - V_10 ;
goto V_180;
}
if ( V_16 -> V_17 > 1 && F_1 ( V_2 , V_16 -> V_17 - 1 ) < 0 ) {
F_55 ( & V_2 -> V_30 , L_20 ,
V_16 -> V_17 - 1 ) ;
V_94 = - V_10 ;
goto V_180;
}
V_94 = F_53 ( V_2 , V_5 ) ;
if ( V_94 < 0 ) {
F_55 ( & V_2 -> V_30 , L_21 ) ;
goto V_180;
}
V_94 = - V_179 ;
V_5 -> V_59 = F_57 ( sizeof( struct V_57 ) * V_5 -> V_108 ,
V_178 ) ;
if ( ! V_5 -> V_59 ) {
F_55 ( & V_2 -> V_30 , L_22 ) ;
goto V_180;
}
V_5 -> V_103 = F_57 ( sizeof( struct V_100 )
* V_5 -> V_102 , V_178 ) ;
if ( ! V_5 -> V_103 ) {
F_55 ( & V_2 -> V_30 , L_23 ) ;
goto V_183;
}
V_5 -> V_95 = F_57 ( sizeof( struct V_110 ) * V_5 -> V_112 ,
V_178 ) ;
if ( ! V_5 -> V_95 ) {
F_55 ( & V_2 -> V_30 , L_24 ) ;
goto V_184;
}
V_5 -> V_185 = F_57 ( sizeof( struct V_186 * )
* V_5 -> V_134 , V_178 ) ;
if ( ! V_5 -> V_185 ) {
F_55 ( & V_2 -> V_30 , L_25 ) ;
goto V_187;
}
F_52 ( V_2 , V_5 ) ;
if ( ! V_5 -> V_188 ) {
F_55 ( & V_2 -> V_30 , L_26 ) ;
V_94 = - V_168 ;
goto V_189;
}
V_5 -> V_190 . V_150 = V_5 -> V_185 ;
V_94 = F_60 ( & V_2 -> V_30 . V_191 , & V_5 -> V_190 ) ;
if ( V_94 ) {
F_55 ( & V_2 -> V_30 , L_27 ) ;
goto V_189;
}
V_5 -> V_192 = F_61 ( & V_2 -> V_30 ) ;
if ( F_62 ( V_5 -> V_192 ) ) {
V_94 = F_63 ( V_5 -> V_192 ) ;
F_55 ( & V_2 -> V_30 , L_28 ) ;
goto V_193;
}
return 0 ;
V_193:
F_64 ( & V_2 -> V_30 . V_191 , & V_5 -> V_190 ) ;
V_189:
F_65 ( V_5 -> V_185 ) ;
V_187:
F_65 ( V_5 -> V_95 ) ;
V_184:
F_65 ( V_5 -> V_103 ) ;
V_183:
F_65 ( V_5 -> V_59 ) ;
V_180:
F_65 ( V_5 ) ;
return V_94 ;
}
int F_66 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_67 ( V_5 -> V_192 ) ;
F_64 ( & V_2 -> V_30 . V_191 , & V_5 -> V_190 ) ;
F_65 ( V_5 -> V_185 ) ;
F_65 ( V_5 -> V_95 ) ;
F_65 ( V_5 -> V_103 ) ;
F_65 ( V_5 -> V_59 ) ;
F_65 ( V_5 ) ;
return 0 ;
}
