static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_3 ) ;
}
static void F_3 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
T_1 V_9 = 0 ;
V_9 = F_4 ( V_6 -> V_10 + V_11 ) ;
V_9 &= ~ V_12 ;
V_9 |= V_13 ;
F_5 ( V_9 , V_6 -> V_10 + V_11 ) ;
V_9 = 0x1 << V_6 -> V_14 ;
F_5 ( V_9 , V_8 -> V_10 + V_15 ) ;
F_5 ( V_9 , V_8 -> V_10 + V_16 ) ;
F_5 ( V_9 , V_8 -> V_10 + V_17 ) ;
F_5 ( V_9 , V_8 -> V_10 + V_18 ) ;
}
static void F_6 ( struct V_5 * V_6 , struct V_19 * V_20 )
{
F_5 ( V_20 -> V_21 , V_6 -> V_10 + V_22 ) ;
F_5 ( V_20 -> V_23 , V_6 -> V_10 + V_24 ) ;
F_5 ( V_20 -> V_25 , V_6 -> V_10 + V_26 ) ;
F_5 ( 0 , V_6 -> V_10 + V_27 ) ;
F_5 ( 0 , V_6 -> V_10 + V_28 ) ;
F_5 ( 0 , V_6 -> V_10 + V_29 ) ;
F_5 ( V_20 -> V_30 , V_6 -> V_10 + V_31 ) ;
F_5 ( V_20 -> V_32 , V_6 -> V_10 + V_11 ) ;
}
static T_1 F_7 ( struct V_5 * V_6 )
{
return F_4 ( V_6 -> V_10 + V_31 ) ;
}
static T_1 F_8 ( struct V_7 * V_8 )
{
return F_4 ( V_8 -> V_10 + V_33 ) ;
}
static void F_9 ( struct V_7 * V_8 )
{
F_5 ( 0x0 , V_8 -> V_10 + V_34 ) ;
F_5 ( 0xffffffff , V_8 -> V_10 + V_15 ) ;
F_5 ( 0xffffffff , V_8 -> V_10 + V_16 ) ;
F_5 ( 0xffffffff , V_8 -> V_10 + V_17 ) ;
F_5 ( 0xffffffff , V_8 -> V_10 + V_18 ) ;
}
static int F_10 ( struct V_1 * V_35 )
{
struct V_7 * V_8 = F_11 ( V_35 -> V_4 . V_3 . V_36 ) ;
struct V_37 * V_38 = F_12 ( & V_35 -> V_4 ) ;
if ( ! V_35 -> V_6 )
return - V_39 ;
if ( F_13 ( V_35 -> V_6 -> V_14 ) & F_8 ( V_8 ) )
return - V_39 ;
if ( V_38 ) {
struct V_40 * V_41 =
F_2 ( V_38 , struct V_40 , V_38 ) ;
F_14 ( & V_41 -> V_38 . V_42 ) ;
V_35 -> V_6 -> V_43 = V_41 ;
V_35 -> V_6 -> V_44 = NULL ;
F_6 ( V_35 -> V_6 , V_41 -> V_45 ) ;
return 0 ;
}
V_35 -> V_6 -> V_44 = NULL ;
V_35 -> V_6 -> V_43 = NULL ;
return - V_39 ;
}
static void F_15 ( struct V_7 * V_8 )
{
struct V_5 * V_46 ;
struct V_1 * V_35 , * V_47 ;
unsigned V_48 , V_49 = 0 ;
unsigned long V_50 ;
F_16 (c, cn, &d->slave.channels,
vc.chan.device_node) {
F_17 ( & V_35 -> V_4 . V_51 , V_50 ) ;
V_46 = V_35 -> V_6 ;
if ( V_46 && V_46 -> V_44 && F_10 ( V_35 ) ) {
F_18 ( V_8 -> V_52 . V_53 , L_1 , V_46 -> V_14 ) ;
V_35 -> V_6 = NULL ;
V_46 -> V_54 = NULL ;
}
F_19 ( & V_35 -> V_4 . V_51 , V_50 ) ;
}
F_17 ( & V_8 -> V_51 , V_50 ) ;
while ( ! F_20 ( & V_8 -> V_55 ) ) {
V_35 = F_21 ( & V_8 -> V_55 ,
struct V_1 , V_42 ) ;
V_46 = & V_8 -> V_6 [ V_35 -> V_56 ] ;
if ( ! V_46 -> V_54 ) {
F_22 ( & V_35 -> V_42 ) ;
V_49 |= 1 << V_35 -> V_56 ;
V_46 -> V_54 = V_35 ;
V_35 -> V_6 = V_46 ;
} else {
F_18 ( V_8 -> V_52 . V_53 , L_2 , V_35 -> V_56 ) ;
}
}
F_19 ( & V_8 -> V_51 , V_50 ) ;
for ( V_48 = 0 ; V_48 < V_8 -> V_57 ; V_48 ++ ) {
if ( V_49 & ( 1 << V_48 ) ) {
V_46 = & V_8 -> V_6 [ V_48 ] ;
V_35 = V_46 -> V_54 ;
if ( V_35 ) {
F_17 ( & V_35 -> V_4 . V_51 , V_50 ) ;
F_10 ( V_35 ) ;
F_19 ( & V_35 -> V_4 . V_51 , V_50 ) ;
}
}
}
}
static T_2 F_23 ( int V_58 , void * V_59 )
{
struct V_7 * V_8 = (struct V_7 * ) V_59 ;
struct V_5 * V_46 ;
struct V_1 * V_35 ;
T_1 V_60 = F_4 ( V_8 -> V_10 + V_61 ) ;
T_1 V_62 = F_4 ( V_8 -> V_10 + V_63 ) ;
T_1 V_64 = F_4 ( V_8 -> V_10 + V_65 ) ;
T_1 V_66 = F_4 ( V_8 -> V_10 + V_67 ) ;
T_1 V_68 , V_69 = 0 , V_70 = 0 ;
while ( V_60 ) {
V_68 = F_24 ( V_60 ) ;
V_60 &= ~ F_13 ( V_68 ) ;
V_46 = & V_8 -> V_6 [ V_68 ] ;
V_35 = V_46 -> V_54 ;
if ( V_35 ) {
unsigned long V_50 ;
F_17 ( & V_35 -> V_4 . V_51 , V_50 ) ;
if ( V_35 -> V_71 ) {
F_25 ( & V_46 -> V_43 -> V_38 ) ;
} else {
F_26 ( & V_46 -> V_43 -> V_38 ) ;
V_46 -> V_44 = V_46 -> V_43 ;
V_70 = 1 ;
}
F_19 ( & V_35 -> V_4 . V_51 , V_50 ) ;
V_69 |= F_13 ( V_68 ) ;
}
}
if ( V_62 || V_64 || V_66 )
F_27 ( V_8 -> V_52 . V_53 , L_3 ,
V_62 , V_64 , V_66 ) ;
F_5 ( V_69 , V_8 -> V_10 + V_15 ) ;
F_5 ( V_62 , V_8 -> V_10 + V_16 ) ;
F_5 ( V_64 , V_8 -> V_10 + V_17 ) ;
F_5 ( V_66 , V_8 -> V_10 + V_18 ) ;
if ( V_70 )
F_15 ( V_8 ) ;
return V_72 ;
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
struct V_7 * V_8 = F_11 ( V_3 -> V_36 ) ;
unsigned long V_50 ;
F_17 ( & V_8 -> V_51 , V_50 ) ;
F_22 ( & V_35 -> V_42 ) ;
F_19 ( & V_8 -> V_51 , V_50 ) ;
F_29 ( & V_35 -> V_4 ) ;
V_35 -> V_73 = 0 ;
}
static enum V_74 F_30 ( struct V_2 * V_3 ,
T_3 V_75 ,
struct V_76 * V_77 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
struct V_5 * V_46 ;
struct V_37 * V_38 ;
unsigned long V_50 ;
enum V_74 V_78 ;
T_4 V_79 = 0 ;
V_78 = F_31 ( & V_35 -> V_4 . V_3 , V_75 , V_77 ) ;
if ( V_78 == V_80 || ! V_77 )
return V_78 ;
F_17 ( & V_35 -> V_4 . V_51 , V_50 ) ;
V_46 = V_35 -> V_6 ;
V_78 = V_35 -> V_81 ;
V_38 = F_32 ( & V_35 -> V_4 , V_75 ) ;
if ( V_38 ) {
V_79 = F_2 ( V_38 , struct V_40 , V_38 ) -> V_82 ;
} else if ( ( ! V_46 ) || ( ! V_46 -> V_43 ) ) {
V_79 = 0 ;
} else {
struct V_40 * V_41 = V_46 -> V_43 ;
T_1 V_83 = 0 , V_84 = 0 ;
V_79 = 0 ;
V_83 = F_7 ( V_46 ) ;
V_84 = ( V_83 - V_41 -> V_85 ) / sizeof( struct V_19 ) ;
for (; V_84 < V_41 -> V_86 ; V_84 ++ ) {
V_79 += V_41 -> V_45 [ V_84 ] . V_25 ;
if ( ! V_41 -> V_45 [ V_84 ] . V_30 )
break;
}
}
F_19 ( & V_35 -> V_4 . V_51 , V_50 ) ;
F_33 ( V_77 , V_79 ) ;
return V_78 ;
}
static void F_34 ( struct V_2 * V_3 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
struct V_7 * V_8 = F_11 ( V_3 -> V_36 ) ;
unsigned long V_50 ;
int V_87 = 0 ;
F_17 ( & V_35 -> V_4 . V_51 , V_50 ) ;
if ( F_35 ( & V_35 -> V_4 ) ) {
F_36 ( & V_8 -> V_51 ) ;
if ( ! V_35 -> V_6 && F_20 ( & V_35 -> V_42 ) ) {
F_37 ( & V_35 -> V_42 , & V_8 -> V_55 ) ;
V_87 = 1 ;
F_18 ( V_8 -> V_52 . V_53 , L_4 , & V_35 -> V_4 ) ;
}
F_38 ( & V_8 -> V_51 ) ;
} else {
F_18 ( V_8 -> V_52 . V_53 , L_5 , & V_35 -> V_4 ) ;
}
F_19 ( & V_35 -> V_4 . V_51 , V_50 ) ;
if ( V_87 )
F_15 ( V_8 ) ;
}
static void F_39 ( struct V_40 * V_41 , T_5 V_88 ,
T_5 V_89 , T_4 V_90 , T_1 V_91 , T_1 V_73 )
{
if ( ( V_91 + 1 ) < V_41 -> V_86 )
V_41 -> V_45 [ V_91 ] . V_30 = V_41 -> V_85 + ( V_91 + 1 ) *
sizeof( struct V_19 ) ;
V_41 -> V_45 [ V_91 ] . V_21 = V_89 ;
V_41 -> V_45 [ V_91 ] . V_23 = V_88 ;
V_41 -> V_45 [ V_91 ] . V_25 = V_90 ;
V_41 -> V_45 [ V_91 ] . V_32 = V_73 ;
}
static struct V_40 * F_40 ( int V_91 ,
struct V_2 * V_3 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
struct V_40 * V_41 ;
struct V_7 * V_8 = F_11 ( V_3 -> V_36 ) ;
int V_92 = V_93 / sizeof( struct V_19 ) ;
if ( V_91 > V_92 ) {
F_18 ( V_3 -> V_36 -> V_53 , L_6 ,
& V_35 -> V_4 , V_91 , V_92 ) ;
return NULL ;
}
V_41 = F_41 ( sizeof( * V_41 ) , V_94 ) ;
if ( ! V_41 )
return NULL ;
V_41 -> V_45 = F_42 ( V_8 -> V_95 , V_96 , & V_41 -> V_85 ) ;
if ( ! V_41 -> V_45 ) {
F_18 ( V_3 -> V_36 -> V_53 , L_7 , & V_35 -> V_4 ) ;
F_43 ( V_41 ) ;
return NULL ;
}
memset ( V_41 -> V_45 , 0 , sizeof( struct V_19 ) * V_91 ) ;
V_41 -> V_86 = V_91 ;
return V_41 ;
}
static enum V_97 V_97 ( enum V_98 V_99 )
{
switch ( V_99 ) {
case V_100 :
case V_101 :
case V_102 :
case V_103 :
return F_44 ( V_99 ) - 1 ;
default:
return V_104 ;
}
}
static int F_45 ( struct V_1 * V_35 , enum V_105 V_106 )
{
struct V_107 * V_66 = & V_35 -> V_108 ;
enum V_97 V_109 ;
enum V_97 V_110 ;
T_1 V_111 = 0 ;
switch ( V_106 ) {
case V_112 :
V_35 -> V_73 = V_12 | V_113
| F_46 ( V_114 - 1 )
| F_47 ( V_104 )
| F_48 ( V_104 ) ;
break;
case V_115 :
V_35 -> V_116 = V_66 -> V_117 ;
V_110 = V_97 ( V_66 -> V_118 ) ;
V_111 = V_66 -> V_119 ;
V_111 = V_111 < V_114 ?
V_111 : V_114 ;
V_35 -> V_73 = V_120 | V_12
| F_46 ( V_111 - 1 )
| F_47 ( V_110 )
| F_48 ( V_110 ) ;
break;
case V_121 :
V_35 -> V_116 = V_66 -> V_122 ;
V_109 = V_97 ( V_66 -> V_123 ) ;
V_111 = V_66 -> V_124 ;
V_111 = V_111 < V_114 ?
V_111 : V_114 ;
V_35 -> V_73 = V_125 | V_12
| F_46 ( V_111 - 1 )
| F_47 ( V_109 )
| F_48 ( V_109 ) ;
break;
default:
return - V_126 ;
}
return 0 ;
}
static struct V_127 * F_49 (
struct V_2 * V_3 , T_5 V_88 , T_5 V_89 ,
T_4 V_90 , unsigned long V_50 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
struct V_40 * V_41 ;
T_4 V_128 = 0 ;
int V_91 = 0 ;
if ( ! V_90 )
return NULL ;
if ( F_45 ( V_35 , V_112 ) )
return NULL ;
V_91 = F_50 ( V_90 , V_129 ) ;
V_41 = F_40 ( V_91 , V_3 ) ;
if ( ! V_41 )
return NULL ;
V_41 -> V_82 = V_90 ;
V_91 = 0 ;
do {
V_128 = F_51 ( T_4 , V_90 , V_129 ) ;
F_39 ( V_41 , V_88 , V_89 , V_128 , V_91 ++ , V_35 -> V_73 ) ;
V_89 += V_128 ;
V_88 += V_128 ;
V_90 -= V_128 ;
} while ( V_90 );
V_35 -> V_71 = 0 ;
V_41 -> V_45 [ V_91 - 1 ] . V_30 = 0 ;
V_41 -> V_45 [ V_91 - 1 ] . V_32 |= V_130 ;
return F_52 ( & V_35 -> V_4 , & V_41 -> V_38 , V_50 ) ;
}
static struct V_127 * F_53 (
struct V_2 * V_3 , struct V_131 * V_132 , unsigned int V_133 ,
enum V_105 V_106 , unsigned long V_50 , void * V_134 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
struct V_40 * V_41 ;
T_4 V_90 , V_135 , V_136 = 0 ;
struct V_131 * V_137 ;
T_5 V_138 , V_89 = 0 , V_88 = 0 ;
int V_91 = V_133 , V_68 ;
if ( ! V_132 )
return NULL ;
if ( F_45 ( V_35 , V_106 ) )
return NULL ;
F_54 (sgl, sg, sglen, i) {
V_135 = F_55 ( V_137 ) ;
if ( V_135 > V_129 )
V_91 += F_50 ( V_135 , V_129 ) - 1 ;
}
V_41 = F_40 ( V_91 , V_3 ) ;
if ( ! V_41 )
return NULL ;
V_35 -> V_71 = 0 ;
V_91 = 0 ;
F_54 (sgl, sg, sglen, i) {
V_138 = F_56 ( V_137 ) ;
V_135 = F_55 ( V_137 ) ;
V_136 += V_135 ;
do {
V_90 = F_51 ( T_4 , V_135 , V_129 ) ;
if ( V_106 == V_115 ) {
V_89 = V_138 ;
V_88 = V_35 -> V_116 ;
} else if ( V_106 == V_121 ) {
V_89 = V_35 -> V_116 ;
V_88 = V_138 ;
}
F_39 ( V_41 , V_88 , V_89 , V_90 , V_91 ++ , V_35 -> V_73 ) ;
V_138 += V_90 ;
V_135 -= V_90 ;
} while ( V_135 );
}
V_41 -> V_45 [ V_91 - 1 ] . V_30 = 0 ;
V_41 -> V_45 [ V_91 - 1 ] . V_32 |= V_130 ;
V_41 -> V_82 = V_136 ;
return F_52 ( & V_35 -> V_4 , & V_41 -> V_38 , V_50 ) ;
}
static struct V_127 * F_57 (
struct V_2 * V_3 , T_5 V_139 , T_4 V_140 ,
T_4 V_141 , enum V_105 V_106 ,
unsigned long V_50 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
struct V_40 * V_41 ;
T_5 V_89 = 0 , V_88 = 0 ;
int V_142 = V_140 / V_141 ;
int V_143 = 0 , V_91 = 0 ;
if ( V_141 > V_129 ) {
F_58 ( V_3 -> V_36 -> V_53 , L_8 ) ;
return NULL ;
}
if ( F_45 ( V_35 , V_106 ) )
return NULL ;
V_41 = F_40 ( V_142 , V_3 ) ;
if ( ! V_41 )
return NULL ;
V_35 -> V_71 = 1 ;
while ( V_143 < V_140 ) {
if ( V_106 == V_115 ) {
V_89 = V_139 ;
V_88 = V_35 -> V_116 ;
} else if ( V_106 == V_121 ) {
V_89 = V_35 -> V_116 ;
V_88 = V_139 ;
}
F_39 ( V_41 , V_88 , V_89 , V_141 , V_91 ++ ,
V_35 -> V_73 | V_130 ) ;
V_139 += V_141 ;
V_143 += V_141 ;
}
V_41 -> V_45 [ V_91 - 1 ] . V_30 = V_41 -> V_85 ;
V_41 -> V_82 = V_140 ;
return F_52 ( & V_35 -> V_4 , & V_41 -> V_38 , V_50 ) ;
}
static int F_59 ( struct V_2 * V_3 ,
struct V_107 * V_66 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
if ( ! V_66 )
return - V_126 ;
memcpy ( & V_35 -> V_108 , V_66 , sizeof( * V_66 ) ) ;
return 0 ;
}
static int F_60 ( struct V_2 * V_3 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
struct V_7 * V_8 = F_11 ( V_3 -> V_36 ) ;
struct V_5 * V_46 = V_35 -> V_6 ;
unsigned long V_50 ;
F_61 ( V_144 ) ;
F_18 ( V_8 -> V_52 . V_53 , L_9 , & V_35 -> V_4 ) ;
F_36 ( & V_8 -> V_51 ) ;
F_22 ( & V_35 -> V_42 ) ;
F_38 ( & V_8 -> V_51 ) ;
F_17 ( & V_35 -> V_4 . V_51 , V_50 ) ;
F_62 ( & V_35 -> V_4 , & V_144 ) ;
if ( V_46 ) {
F_3 ( V_46 , V_8 ) ;
V_35 -> V_6 = NULL ;
V_46 -> V_54 = NULL ;
V_46 -> V_43 = NULL ;
V_46 -> V_44 = NULL ;
}
F_19 ( & V_35 -> V_4 . V_51 , V_50 ) ;
F_63 ( & V_35 -> V_4 , & V_144 ) ;
return 0 ;
}
static int F_64 ( struct V_2 * V_3 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
T_1 V_9 = 0 ;
V_9 = F_4 ( V_35 -> V_6 -> V_10 + V_11 ) ;
V_9 &= ~ V_12 ;
F_5 ( V_9 , V_35 -> V_6 -> V_10 + V_11 ) ;
return 0 ;
}
static int F_65 ( struct V_2 * V_3 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
T_1 V_9 = 0 ;
V_9 = F_4 ( V_35 -> V_6 -> V_10 + V_11 ) ;
V_9 |= V_12 ;
F_5 ( V_9 , V_35 -> V_6 -> V_10 + V_11 ) ;
return 0 ;
}
static void F_66 ( struct V_37 * V_38 )
{
struct V_40 * V_41 =
F_2 ( V_38 , struct V_40 , V_38 ) ;
struct V_7 * V_8 = F_11 ( V_38 -> V_145 . V_3 -> V_36 ) ;
F_67 ( V_8 -> V_95 , V_41 -> V_45 , V_41 -> V_85 ) ;
F_43 ( V_41 ) ;
}
static struct V_2 * F_68 ( struct V_146 * V_147 ,
struct V_148 * V_149 )
{
struct V_7 * V_8 = V_149 -> V_150 ;
unsigned int V_151 = V_147 -> args [ 0 ] ;
struct V_2 * V_3 ;
struct V_1 * V_35 ;
if ( V_151 >= V_8 -> V_152 )
return NULL ;
V_3 = F_69 ( & V_8 -> V_52 ) ;
if ( ! V_3 ) {
F_58 ( V_8 -> V_52 . V_53 , L_10 , V_153 ) ;
return NULL ;
}
V_35 = F_1 ( V_3 ) ;
V_35 -> V_56 = V_151 ;
F_70 ( V_8 -> V_52 . V_53 , L_11 ,
V_35 -> V_56 , & V_35 -> V_4 ) ;
return V_3 ;
}
static int F_71 ( struct V_154 * V_155 )
{
struct V_7 * V_8 ;
struct V_156 * V_157 ;
int V_68 , V_78 = 0 ;
V_157 = F_72 ( V_155 , V_158 , 0 ) ;
if ( ! V_157 )
return - V_126 ;
V_8 = F_73 ( & V_155 -> V_53 , sizeof( * V_8 ) , V_159 ) ;
if ( ! V_8 )
return - V_160 ;
V_8 -> V_10 = F_74 ( & V_155 -> V_53 , V_157 ) ;
if ( F_75 ( V_8 -> V_10 ) )
return F_76 ( V_8 -> V_10 ) ;
F_77 ( ( & V_155 -> V_53 ) -> V_161 ,
L_12 , & V_8 -> V_57 ) ;
F_77 ( ( & V_155 -> V_53 ) -> V_161 ,
L_13 , & V_8 -> V_152 ) ;
if ( ! V_8 -> V_152 || ! V_8 -> V_57 )
return - V_126 ;
V_8 -> V_162 = F_78 ( & V_155 -> V_53 , NULL ) ;
if ( F_75 ( V_8 -> V_162 ) ) {
F_58 ( & V_155 -> V_53 , L_14 ) ;
return F_76 ( V_8 -> V_162 ) ;
}
V_8 -> V_58 = F_79 ( V_155 , 0 ) ;
V_78 = F_80 ( & V_155 -> V_53 , V_8 -> V_58 , F_23 ,
0 , V_163 , V_8 ) ;
if ( V_78 )
return V_78 ;
V_8 -> V_95 = F_81 ( V_163 , & V_155 -> V_53 ,
V_93 , 32 , 0 ) ;
if ( ! V_8 -> V_95 )
return - V_160 ;
V_8 -> V_6 = F_73 ( & V_155 -> V_53 ,
V_8 -> V_57 * sizeof( struct V_5 ) , V_159 ) ;
if ( ! V_8 -> V_6 )
return - V_160 ;
for ( V_68 = 0 ; V_68 < V_8 -> V_57 ; V_68 ++ ) {
struct V_5 * V_46 = & V_8 -> V_6 [ V_68 ] ;
V_46 -> V_14 = V_68 ;
V_46 -> V_10 = V_8 -> V_10 + V_68 * 0x40 ;
}
F_82 ( & V_8 -> V_52 . V_164 ) ;
F_83 ( V_165 , V_8 -> V_52 . V_166 ) ;
F_83 ( V_167 , V_8 -> V_52 . V_166 ) ;
F_83 ( V_168 , V_8 -> V_52 . V_166 ) ;
V_8 -> V_52 . V_53 = & V_155 -> V_53 ;
V_8 -> V_52 . V_169 = F_28 ;
V_8 -> V_52 . V_170 = F_30 ;
V_8 -> V_52 . V_171 = F_49 ;
V_8 -> V_52 . V_172 = F_53 ;
V_8 -> V_52 . V_173 = F_57 ;
V_8 -> V_52 . V_174 = F_34 ;
V_8 -> V_52 . V_175 = F_59 ;
V_8 -> V_52 . V_176 = F_60 ;
V_8 -> V_52 . V_177 = F_64 ;
V_8 -> V_52 . V_178 = F_65 ;
V_8 -> V_52 . V_179 = V_180 ;
V_8 -> V_52 . V_181 = V_182 ;
V_8 -> V_52 . V_183 = V_182 ;
V_8 -> V_52 . V_184 = F_13 ( V_112 ) | F_13 ( V_115 )
| F_13 ( V_121 ) ;
V_8 -> V_52 . V_185 = V_186 ;
V_8 -> V_187 = F_73 ( & V_155 -> V_53 ,
V_8 -> V_152 * sizeof( struct V_1 ) , V_159 ) ;
if ( ! V_8 -> V_187 )
return - V_160 ;
for ( V_68 = 0 ; V_68 < V_8 -> V_152 ; V_68 ++ ) {
struct V_1 * V_35 = & V_8 -> V_187 [ V_68 ] ;
V_35 -> V_81 = V_188 ;
F_82 ( & V_35 -> V_42 ) ;
V_35 -> V_4 . V_189 = F_66 ;
F_84 ( & V_35 -> V_4 , & V_8 -> V_52 ) ;
}
V_78 = F_85 ( V_8 -> V_162 ) ;
if ( V_78 < 0 ) {
F_58 ( & V_155 -> V_53 , L_15 , V_78 ) ;
goto V_190;
}
F_9 ( V_8 ) ;
F_86 ( & V_8 -> V_51 ) ;
F_82 ( & V_8 -> V_55 ) ;
F_87 ( V_155 , V_8 ) ;
V_78 = F_88 ( & V_8 -> V_52 ) ;
if ( V_78 )
goto V_191;
V_78 = F_89 ( ( & V_155 -> V_53 ) -> V_161 ,
F_68 , V_8 ) ;
if ( V_78 )
goto V_192;
F_70 ( & V_155 -> V_53 , L_16 ) ;
return 0 ;
V_192:
F_90 ( & V_8 -> V_52 ) ;
V_191:
F_91 ( V_8 -> V_162 ) ;
V_190:
return V_78 ;
}
static int F_92 ( struct V_154 * V_155 )
{
struct V_1 * V_35 , * V_47 ;
struct V_7 * V_8 = F_93 ( V_155 ) ;
F_94 ( & V_155 -> V_53 , V_8 -> V_58 , V_8 ) ;
F_90 ( & V_8 -> V_52 ) ;
F_95 ( ( & V_155 -> V_53 ) -> V_161 ) ;
F_16 (c, cn, &d->slave.channels,
vc.chan.device_node) {
F_14 ( & V_35 -> V_4 . V_3 . V_193 ) ;
}
F_91 ( V_8 -> V_162 ) ;
F_96 ( V_8 -> V_95 ) ;
return 0 ;
}
static int F_97 ( struct V_36 * V_53 )
{
struct V_7 * V_8 = F_98 ( V_53 ) ;
T_1 V_194 = 0 ;
V_194 = F_8 ( V_8 ) ;
if ( V_194 ) {
F_27 ( V_8 -> V_52 . V_53 ,
L_17 , V_194 ) ;
return - 1 ;
}
F_91 ( V_8 -> V_162 ) ;
return 0 ;
}
static int F_99 ( struct V_36 * V_53 )
{
struct V_7 * V_8 = F_98 ( V_53 ) ;
int V_78 = 0 ;
V_78 = F_85 ( V_8 -> V_162 ) ;
if ( V_78 < 0 ) {
F_58 ( V_8 -> V_52 . V_53 , L_15 , V_78 ) ;
return V_78 ;
}
F_9 ( V_8 ) ;
return 0 ;
}
