static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_3 ) ;
}
static void F_3 ( struct V_5 * V_6 , bool V_7 )
{
T_1 V_8 = 0 ;
if ( V_7 ) {
V_8 = F_4 ( V_6 -> V_9 + V_10 ) ;
V_8 |= V_11 ;
F_5 ( V_8 , V_6 -> V_9 + V_10 ) ;
} else {
V_8 = F_4 ( V_6 -> V_9 + V_10 ) ;
V_8 &= ~ V_11 ;
F_5 ( V_8 , V_6 -> V_9 + V_10 ) ;
}
}
static void F_6 ( struct V_5 * V_6 , struct V_12 * V_13 )
{
T_1 V_8 = 0 ;
F_3 ( V_6 , false ) ;
V_8 = 0x1 << V_6 -> V_14 ;
F_5 ( V_8 , V_13 -> V_9 + V_15 ) ;
F_5 ( V_8 , V_13 -> V_9 + V_16 ) ;
F_5 ( V_8 , V_13 -> V_9 + V_17 ) ;
F_5 ( V_8 , V_13 -> V_9 + V_18 ) ;
}
static void F_7 ( struct V_5 * V_6 , struct V_19 * V_20 )
{
F_5 ( V_20 -> V_21 , V_6 -> V_9 + V_22 ) ;
F_5 ( V_20 -> V_23 , V_6 -> V_9 + V_24 ) ;
F_5 ( V_20 -> V_25 , V_6 -> V_9 + V_26 ) ;
F_5 ( V_20 -> V_27 , V_6 -> V_9 + V_28 ) ;
F_5 ( V_29 , V_6 -> V_9 + V_30 ) ;
F_5 ( V_20 -> V_31 , V_6 -> V_9 + V_10 ) ;
}
static T_1 F_8 ( struct V_12 * V_13 , struct V_5 * V_6 )
{
T_1 V_32 = 0 ;
V_32 = F_4 ( V_13 -> V_9 + V_33 + V_6 -> V_14 * 0x10 ) ;
V_32 &= 0xffff ;
return V_32 ;
}
static T_1 F_9 ( struct V_5 * V_6 )
{
return F_4 ( V_6 -> V_9 + V_22 ) ;
}
static T_1 F_10 ( struct V_12 * V_13 )
{
return F_4 ( V_13 -> V_9 + V_34 ) ;
}
static void F_11 ( struct V_12 * V_13 , bool V_7 )
{
if ( V_7 ) {
F_5 ( 0x0 , V_13 -> V_9 + V_35 ) ;
F_5 ( 0xffff , V_13 -> V_9 + V_36 ) ;
F_5 ( 0xffff , V_13 -> V_9 + V_37 ) ;
F_5 ( 0xffff , V_13 -> V_9 + V_38 ) ;
F_5 ( 0xffff , V_13 -> V_9 + V_39 ) ;
} else {
F_5 ( 0x0 , V_13 -> V_9 + V_36 ) ;
F_5 ( 0x0 , V_13 -> V_9 + V_37 ) ;
F_5 ( 0x0 , V_13 -> V_9 + V_38 ) ;
F_5 ( 0x0 , V_13 -> V_9 + V_39 ) ;
}
}
static T_2 F_12 ( int V_40 , void * V_41 )
{
struct V_12 * V_13 = (struct V_12 * ) V_41 ;
struct V_5 * V_42 ;
struct V_1 * V_43 ;
T_1 V_44 = F_4 ( V_13 -> V_9 + V_45 ) ;
T_1 V_46 = F_4 ( V_13 -> V_9 + V_47 ) ;
T_1 V_48 = F_4 ( V_13 -> V_9 + V_49 ) ;
T_1 V_50 = F_4 ( V_13 -> V_9 + V_51 ) ;
T_1 V_52 = F_4 ( V_13 -> V_9 + V_53 ) ;
T_1 V_54 , V_55 = 0 ;
while ( V_44 ) {
V_54 = F_13 ( V_44 ) ;
V_44 &= ~ F_14 ( V_54 ) ;
if ( F_15 ( V_46 & F_14 ( V_54 ) ) || ( V_48 & F_14 ( V_54 ) ) ) {
unsigned long V_56 ;
V_42 = & V_13 -> V_6 [ V_54 ] ;
V_43 = V_42 -> V_57 ;
if ( V_43 && ( V_46 & F_14 ( V_54 ) ) ) {
F_16 ( & V_43 -> V_4 . V_58 , V_56 ) ;
F_17 ( & V_42 -> V_59 -> V_60 ) ;
F_18 ( V_42 -> V_61 ) ;
V_42 -> V_61 = V_42 -> V_59 ;
V_42 -> V_59 = NULL ;
F_19 ( & V_43 -> V_4 . V_58 , V_56 ) ;
}
if ( V_43 && ( V_48 & F_14 ( V_54 ) ) ) {
F_16 ( & V_43 -> V_4 . V_58 , V_56 ) ;
if ( V_42 -> V_59 != NULL )
F_20 ( & V_42 -> V_59 -> V_60 ) ;
F_19 ( & V_43 -> V_4 . V_58 , V_56 ) ;
}
V_55 |= F_14 ( V_54 ) ;
}
if ( F_21 ( ( V_50 & F_14 ( V_54 ) ) || ( V_52 & F_14 ( V_54 ) ) ) )
F_22 ( V_13 -> V_62 . V_63 , L_1 ) ;
}
F_5 ( V_55 , V_13 -> V_9 + V_15 ) ;
F_5 ( V_55 , V_13 -> V_9 + V_16 ) ;
F_5 ( V_50 , V_13 -> V_9 + V_17 ) ;
F_5 ( V_52 , V_13 -> V_9 + V_18 ) ;
if ( V_55 )
F_23 ( & V_13 -> V_64 ) ;
if ( V_55 || V_50 || V_52 )
return V_65 ;
return V_66 ;
}
static int F_24 ( struct V_1 * V_43 )
{
struct V_12 * V_13 = F_25 ( V_43 -> V_4 . V_3 . V_67 ) ;
struct V_68 * V_60 = F_26 ( & V_43 -> V_4 ) ;
if ( ! V_43 -> V_6 )
return - V_69 ;
if ( F_14 ( V_43 -> V_6 -> V_14 ) & F_10 ( V_13 ) )
return - V_69 ;
if ( V_60 ) {
struct V_70 * V_71 =
F_2 ( V_60 , struct V_70 , V_60 ) ;
F_27 ( & V_71 -> V_60 . V_72 ) ;
F_18 ( V_43 -> V_6 -> V_59 ) ;
F_18 ( V_43 -> V_6 -> V_61 ) ;
V_43 -> V_6 -> V_59 = V_71 ;
F_7 ( V_43 -> V_6 , & V_71 -> V_73 [ 0 ] ) ;
return 0 ;
}
return - V_69 ;
}
static void F_28 ( unsigned long V_74 )
{
struct V_12 * V_13 = (struct V_12 * ) V_74 ;
struct V_5 * V_42 ;
struct V_1 * V_43 , * V_75 ;
unsigned V_76 , V_77 = 0 ;
F_29 (c, cn, &d->slave.channels, vc.chan.device_node) {
F_30 ( & V_43 -> V_4 . V_58 ) ;
V_42 = V_43 -> V_6 ;
if ( V_42 && V_42 -> V_61 ) {
if ( F_24 ( V_43 ) ) {
F_31 ( V_13 -> V_62 . V_63 , L_2 , V_42 -> V_14 ) ;
V_43 -> V_6 = NULL ;
V_42 -> V_57 = NULL ;
}
}
F_32 ( & V_43 -> V_4 . V_58 ) ;
}
F_30 ( & V_13 -> V_58 ) ;
for ( V_76 = 0 ; V_76 < V_13 -> V_78 ; V_76 ++ ) {
V_42 = & V_13 -> V_6 [ V_76 ] ;
if ( V_42 -> V_57 == NULL && ! F_33 ( & V_13 -> V_79 ) ) {
V_43 = F_34 ( & V_13 -> V_79 ,
struct V_1 , V_72 ) ;
F_35 ( & V_43 -> V_72 ) ;
V_77 |= 1 << V_76 ;
V_42 -> V_57 = V_43 ;
V_43 -> V_6 = V_42 ;
F_31 ( V_13 -> V_62 . V_63 , L_3 , V_76 , & V_43 -> V_4 ) ;
}
}
F_32 ( & V_13 -> V_58 ) ;
for ( V_76 = 0 ; V_76 < V_13 -> V_78 ; V_76 ++ ) {
if ( V_77 & ( 1 << V_76 ) ) {
V_42 = & V_13 -> V_6 [ V_76 ] ;
V_43 = V_42 -> V_57 ;
if ( V_43 ) {
F_30 ( & V_43 -> V_4 . V_58 ) ;
F_24 ( V_43 ) ;
F_32 ( & V_43 -> V_4 . V_58 ) ;
}
}
}
}
static void F_36 ( struct V_2 * V_3 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_12 * V_13 = F_25 ( V_3 -> V_67 ) ;
unsigned long V_56 ;
F_16 ( & V_13 -> V_58 , V_56 ) ;
F_35 ( & V_43 -> V_72 ) ;
F_19 ( & V_13 -> V_58 , V_56 ) ;
F_37 ( & V_43 -> V_4 ) ;
V_43 -> V_80 = 0 ;
}
static enum V_81 F_38 ( struct V_2 * V_3 ,
T_3 V_82 , struct V_83 * V_84 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_12 * V_13 = F_25 ( V_3 -> V_67 ) ;
struct V_5 * V_42 ;
struct V_68 * V_60 ;
unsigned long V_56 ;
enum V_81 V_85 ;
T_4 V_86 = 0 ;
V_85 = F_39 ( & V_43 -> V_4 . V_3 , V_82 , V_84 ) ;
if ( V_85 == V_87 )
return V_85 ;
F_16 ( & V_43 -> V_4 . V_58 , V_56 ) ;
V_42 = V_43 -> V_6 ;
V_85 = V_43 -> V_88 ;
V_60 = F_40 ( & V_43 -> V_4 , V_82 ) ;
if ( V_60 && ! V_43 -> V_89 ) {
V_86 = F_2 ( V_60 , struct V_70 , V_60 ) -> V_90 ;
} else if ( ( ! V_42 ) || ( ! V_42 -> V_59 ) ) {
V_86 = 0 ;
} else {
struct V_70 * V_71 = V_42 -> V_59 ;
T_1 V_91 = 0 , V_92 = 0 ;
V_86 = F_8 ( V_13 , V_42 ) ;
V_91 = F_9 ( V_42 ) ;
V_92 = ( ( V_91 - V_71 -> V_93 ) /
sizeof( struct V_19 ) ) + 1 ;
for (; V_92 < V_71 -> V_94 ; V_92 ++ ) {
V_86 += V_71 -> V_73 [ V_92 ] . V_23 ;
if ( ! V_71 -> V_73 [ V_92 ] . V_21 )
break;
}
}
F_19 ( & V_43 -> V_4 . V_58 , V_56 ) ;
F_41 ( V_84 , V_86 ) ;
return V_85 ;
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_12 * V_13 = F_25 ( V_3 -> V_67 ) ;
unsigned long V_56 ;
F_16 ( & V_43 -> V_4 . V_58 , V_56 ) ;
if ( F_43 ( & V_43 -> V_4 ) ) {
F_44 ( & V_13 -> V_58 ) ;
if ( ! V_43 -> V_6 ) {
if ( F_33 ( & V_43 -> V_72 ) ) {
F_45 ( & V_43 -> V_72 , & V_13 -> V_79 ) ;
F_23 ( & V_13 -> V_64 ) ;
F_31 ( V_13 -> V_62 . V_63 , L_4 , & V_43 -> V_4 ) ;
}
}
F_46 ( & V_13 -> V_58 ) ;
} else
F_31 ( V_13 -> V_62 . V_63 , L_5 , & V_43 -> V_4 ) ;
F_19 ( & V_43 -> V_4 . V_58 , V_56 ) ;
}
static void F_47 ( struct V_70 * V_71 , T_5 V_95 ,
T_5 V_96 , T_4 V_97 , T_1 V_98 , T_1 V_80 )
{
if ( V_98 != V_71 -> V_94 - 1 )
V_71 -> V_73 [ V_98 ] . V_21 = V_71 -> V_93 + ( V_98 + 1 ) *
sizeof( struct V_19 ) ;
V_71 -> V_73 [ V_98 ] . V_21 |= V_99 ;
V_71 -> V_73 [ V_98 ] . V_23 = V_97 ;
V_71 -> V_73 [ V_98 ] . V_25 = V_96 ;
V_71 -> V_73 [ V_98 ] . V_27 = V_95 ;
V_71 -> V_73 [ V_98 ] . V_31 = V_80 ;
}
static struct V_70 * F_48 ( int V_98 ,
struct V_2 * V_3 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_70 * V_71 ;
struct V_12 * V_13 = F_25 ( V_3 -> V_67 ) ;
int V_100 = V_101 / sizeof( struct V_19 ) ;
if ( V_98 > V_100 ) {
F_31 ( V_3 -> V_67 -> V_63 , L_6 ,
& V_43 -> V_4 , V_98 , V_100 ) ;
return NULL ;
}
V_71 = F_49 ( sizeof( * V_71 ) , V_102 ) ;
if ( ! V_71 )
return NULL ;
V_71 -> V_73 = F_50 ( V_13 -> V_103 , V_102 , & V_71 -> V_93 ) ;
if ( ! V_71 -> V_73 ) {
F_31 ( V_3 -> V_67 -> V_63 , L_7 , & V_43 -> V_4 ) ;
F_51 ( V_71 ) ;
return NULL ;
}
memset ( V_71 -> V_73 , 0 , sizeof( struct V_19 ) * V_98 ) ;
V_71 -> V_94 = V_98 ;
return V_71 ;
}
static struct V_104 * F_52 (
struct V_2 * V_3 , T_5 V_95 , T_5 V_96 ,
T_4 V_97 , unsigned long V_56 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_70 * V_71 ;
T_4 V_105 = 0 ;
int V_98 = 0 ;
if ( ! V_97 )
return NULL ;
V_98 = F_53 ( V_97 , V_106 ) ;
V_71 = F_48 ( V_98 , V_3 ) ;
if ( ! V_71 )
return NULL ;
V_43 -> V_89 = 0 ;
V_71 -> V_90 = V_97 ;
V_98 = 0 ;
if ( ! V_43 -> V_80 ) {
V_43 -> V_80 = V_107 | V_108 | V_11 ;
V_43 -> V_80 |= ( 0xf << 20 ) | ( 0xf << 24 ) ;
V_43 -> V_80 |= ( 0x3 << 12 ) | ( 0x3 << 16 ) ;
}
do {
V_105 = F_54 ( T_4 , V_97 , V_106 ) ;
F_47 ( V_71 , V_95 , V_96 , V_105 , V_98 ++ , V_43 -> V_80 ) ;
if ( V_43 -> V_109 == V_110 ) {
V_96 += V_105 ;
} else if ( V_43 -> V_109 == V_111 ) {
V_95 += V_105 ;
} else {
V_96 += V_105 ;
V_95 += V_105 ;
}
V_97 -= V_105 ;
} while ( V_97 );
V_71 -> V_73 [ V_98 - 1 ] . V_21 = 0 ;
return F_55 ( & V_43 -> V_4 , & V_71 -> V_60 , V_56 ) ;
}
static struct V_104 * F_56 (
struct V_2 * V_3 , struct V_112 * V_113 , unsigned int V_114 ,
enum V_115 V_109 , unsigned long V_56 , void * V_116 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_70 * V_71 ;
T_4 V_97 , V_117 , V_118 = 0 ;
struct V_112 * V_119 ;
T_5 V_120 , V_96 = 0 , V_95 = 0 ;
int V_98 = V_114 , V_54 ;
if ( V_113 == NULL )
return NULL ;
V_43 -> V_89 = 0 ;
F_57 (sgl, sg, sglen, i) {
V_117 = F_58 ( V_119 ) ;
if ( V_117 > V_106 )
V_98 += F_53 ( V_117 , V_106 ) - 1 ;
}
V_71 = F_48 ( V_98 , V_3 ) ;
if ( ! V_71 )
return NULL ;
V_98 = 0 ;
F_57 (sgl, sg, sglen, i) {
V_120 = F_59 ( V_119 ) ;
V_117 = F_58 ( V_119 ) ;
V_118 += V_117 ;
do {
V_97 = F_54 ( T_4 , V_117 , V_106 ) ;
if ( V_109 == V_110 ) {
V_96 = V_120 ;
V_95 = V_43 -> V_121 ;
} else if ( V_109 == V_111 ) {
V_96 = V_43 -> V_121 ;
V_95 = V_120 ;
}
F_47 ( V_71 , V_95 , V_96 , V_97 , V_98 ++ , V_43 -> V_80 ) ;
V_120 += V_97 ;
V_117 -= V_97 ;
} while ( V_117 );
}
V_71 -> V_73 [ V_98 - 1 ] . V_21 = 0 ;
V_71 -> V_90 = V_118 ;
return F_55 ( & V_43 -> V_4 , & V_71 -> V_60 , V_56 ) ;
}
static struct V_104 *
F_60 ( struct V_2 * V_3 , T_5 V_122 ,
T_4 V_123 , T_4 V_124 ,
enum V_115 V_109 ,
unsigned long V_56 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_70 * V_71 ;
T_4 V_97 , V_117 , V_118 = 0 ;
T_5 V_120 , V_96 = 0 , V_95 = 0 ;
int V_98 = 1 , V_125 = 0 ;
T_4 V_126 = V_127 ;
T_1 V_128 = 0 ;
F_31 ( V_3 -> V_67 -> V_63 , L_8 ,
V_129 , & V_122 , & F_1 ( V_3 ) -> V_121 ,
V_123 , V_124 , ( int ) V_109 ) ;
V_117 = V_123 ;
if ( V_117 > V_126 )
V_98 += F_53 ( V_117 , V_126 ) - 1 ;
V_71 = F_48 ( V_98 , V_3 ) ;
if ( ! V_71 )
return NULL ;
V_43 -> V_89 = 1 ;
V_120 = V_122 ;
V_117 = V_123 ;
V_118 = V_117 ;
V_98 = 0 ;
if ( V_124 < V_126 )
V_126 = V_124 ;
do {
V_97 = F_54 ( T_4 , V_117 , V_126 ) ;
if ( V_109 == V_110 ) {
V_96 = V_120 ;
V_95 = V_43 -> V_121 ;
} else if ( V_109 == V_111 ) {
V_96 = V_43 -> V_121 ;
V_95 = V_120 ;
}
V_125 += V_97 ;
if ( V_125 >= V_124 ) {
V_128 = V_130 ;
V_125 -= V_124 ;
} else
V_128 = 0 ;
F_47 ( V_71 , V_95 , V_96 , V_97 , V_98 ++ , V_43 -> V_80 | V_128 ) ;
V_120 += V_97 ;
V_117 -= V_97 ;
} while ( V_117 );
V_71 -> V_73 [ V_98 - 1 ] . V_21 |= V_71 -> V_93 ;
V_71 -> V_90 = V_118 ;
return F_55 ( & V_43 -> V_4 , & V_71 -> V_60 , V_56 ) ;
}
static int F_61 ( struct V_2 * V_3 ,
struct V_131 * V_132 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
T_1 V_133 = 0 , V_8 = 0 ;
enum V_134 V_135 = V_136 ;
if ( V_132 == NULL )
return - V_137 ;
V_43 -> V_109 = V_132 -> V_138 ;
if ( V_43 -> V_109 == V_111 ) {
V_43 -> V_80 = V_108 ;
V_43 -> V_121 = V_132 -> V_139 ;
V_133 = V_132 -> V_140 ;
V_135 = V_132 -> V_141 ;
} else if ( V_43 -> V_109 == V_110 ) {
V_43 -> V_80 = V_107 ;
V_43 -> V_121 = V_132 -> V_142 ;
V_133 = V_132 -> V_143 ;
V_135 = V_132 -> V_144 ;
}
switch ( V_135 ) {
case V_145 :
case V_146 :
case V_147 :
case V_148 :
V_8 = F_13 ( V_135 ) ;
break;
default:
V_8 = 3 ;
break;
}
V_43 -> V_80 |= ( V_8 << 12 ) | ( V_8 << 16 ) ;
if ( ( V_133 == 0 ) || ( V_133 > 16 ) )
V_8 = 15 ;
else
V_8 = V_133 - 1 ;
V_43 -> V_80 |= ( V_8 << 20 ) | ( V_8 << 24 ) ;
V_43 -> V_80 |= V_149 | V_11 ;
V_43 -> V_80 |= V_43 -> V_4 . V_3 . V_150 << 4 ;
return 0 ;
}
static void F_62 ( struct V_68 * V_60 )
{
struct V_70 * V_71 =
F_2 ( V_60 , struct V_70 , V_60 ) ;
struct V_12 * V_13 = F_25 ( V_60 -> V_151 . V_3 -> V_67 ) ;
F_63 ( V_13 -> V_103 , V_71 -> V_73 , V_71 -> V_93 ) ;
F_51 ( V_71 ) ;
}
static int F_64 ( struct V_2 * V_3 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_12 * V_13 = F_25 ( V_3 -> V_67 ) ;
struct V_5 * V_42 = V_43 -> V_6 ;
unsigned long V_56 ;
F_65 ( V_152 ) ;
F_31 ( V_13 -> V_62 . V_63 , L_9 , & V_43 -> V_4 ) ;
F_44 ( & V_13 -> V_58 ) ;
F_35 ( & V_43 -> V_72 ) ;
F_46 ( & V_13 -> V_58 ) ;
F_16 ( & V_43 -> V_4 . V_58 , V_56 ) ;
F_66 ( & V_43 -> V_4 , & V_152 ) ;
if ( V_42 ) {
F_6 ( V_42 , V_13 ) ;
V_43 -> V_6 = NULL ;
V_42 -> V_57 = NULL ;
if ( V_42 -> V_59 ) {
F_62 ( & V_42 -> V_59 -> V_60 ) ;
V_42 -> V_59 = NULL ;
}
if ( V_42 -> V_61 ) {
F_62 ( & V_42 -> V_61 -> V_60 ) ;
V_42 -> V_61 = NULL ;
}
}
F_19 ( & V_43 -> V_4 . V_58 , V_56 ) ;
F_67 ( & V_43 -> V_4 , & V_152 ) ;
return 0 ;
}
static int F_68 ( struct V_2 * V_3 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_12 * V_13 = F_25 ( V_3 -> V_67 ) ;
struct V_5 * V_42 = V_43 -> V_6 ;
F_31 ( V_13 -> V_62 . V_63 , L_10 , & V_43 -> V_4 ) ;
if ( V_43 -> V_88 == V_153 ) {
V_43 -> V_88 = V_154 ;
if ( V_42 ) {
F_3 ( V_42 , false ) ;
} else {
F_44 ( & V_13 -> V_58 ) ;
F_35 ( & V_43 -> V_72 ) ;
F_46 ( & V_13 -> V_58 ) ;
}
}
return 0 ;
}
static int F_69 ( struct V_2 * V_3 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_12 * V_13 = F_25 ( V_3 -> V_67 ) ;
struct V_5 * V_42 = V_43 -> V_6 ;
unsigned long V_56 ;
F_31 ( V_13 -> V_62 . V_63 , L_11 , & V_43 -> V_4 ) ;
F_16 ( & V_43 -> V_4 . V_58 , V_56 ) ;
if ( V_43 -> V_88 == V_154 ) {
V_43 -> V_88 = V_153 ;
if ( V_42 ) {
F_3 ( V_42 , true ) ;
} else if ( ! F_33 ( & V_43 -> V_4 . V_155 ) ) {
F_44 ( & V_13 -> V_58 ) ;
F_45 ( & V_43 -> V_72 , & V_13 -> V_79 ) ;
F_46 ( & V_13 -> V_58 ) ;
}
}
F_19 ( & V_43 -> V_4 . V_58 , V_56 ) ;
return 0 ;
}
static struct V_2 * F_70 ( struct V_156 * V_157 ,
struct V_158 * V_159 )
{
struct V_12 * V_13 = V_159 -> V_160 ;
unsigned int V_161 = V_157 -> args [ 0 ] ;
if ( V_161 > V_13 -> V_162 )
return NULL ;
return F_71 ( & ( V_13 -> V_163 [ V_161 ] . V_4 . V_3 ) ) ;
}
static int F_72 ( struct V_164 * V_165 )
{
struct V_12 * V_13 ;
const struct V_166 * V_167 ;
struct V_168 * V_169 ;
int V_54 , V_85 , V_40 = 0 ;
V_169 = F_73 ( V_165 , V_170 , 0 ) ;
if ( ! V_169 )
return - V_137 ;
V_13 = F_74 ( & V_165 -> V_63 , sizeof( * V_13 ) , V_171 ) ;
if ( ! V_13 )
return - V_172 ;
V_13 -> V_9 = F_75 ( & V_165 -> V_63 , V_169 ) ;
if ( F_76 ( V_13 -> V_9 ) )
return F_77 ( V_13 -> V_9 ) ;
V_167 = F_78 ( V_173 , & V_165 -> V_63 ) ;
if ( V_167 ) {
F_79 ( ( & V_165 -> V_63 ) -> V_174 ,
L_12 , & V_13 -> V_78 ) ;
F_79 ( ( & V_165 -> V_63 ) -> V_174 ,
L_13 , & V_13 -> V_162 ) ;
}
V_13 -> V_175 = F_80 ( & V_165 -> V_63 , NULL ) ;
if ( F_76 ( V_13 -> V_175 ) ) {
F_81 ( & V_165 -> V_63 , L_14 ) ;
return F_77 ( V_13 -> V_175 ) ;
}
V_40 = F_82 ( V_165 , 0 ) ;
V_85 = F_83 ( & V_165 -> V_63 , V_40 ,
F_12 , 0 , V_176 , V_13 ) ;
if ( V_85 )
return V_85 ;
V_13 -> V_40 = V_40 ;
V_13 -> V_103 = F_84 ( V_176 , & V_165 -> V_63 ,
V_101 , 32 , 0 ) ;
if ( ! V_13 -> V_103 )
return - V_172 ;
V_13 -> V_6 = F_74 ( & V_165 -> V_63 ,
V_13 -> V_78 * sizeof( struct V_5 ) , V_171 ) ;
if ( V_13 -> V_6 == NULL )
return - V_172 ;
for ( V_54 = 0 ; V_54 < V_13 -> V_78 ; V_54 ++ ) {
struct V_5 * V_42 = & V_13 -> V_6 [ V_54 ] ;
V_42 -> V_14 = V_54 ;
V_42 -> V_9 = V_13 -> V_9 + V_54 * 0x40 ;
}
F_85 ( & V_13 -> V_62 . V_177 ) ;
F_86 ( V_178 , V_13 -> V_62 . V_179 ) ;
F_86 ( V_180 , V_13 -> V_62 . V_179 ) ;
F_86 ( V_181 , V_13 -> V_62 . V_179 ) ;
V_13 -> V_62 . V_63 = & V_165 -> V_63 ;
V_13 -> V_62 . V_182 = F_36 ;
V_13 -> V_62 . V_183 = F_38 ;
V_13 -> V_62 . V_184 = F_52 ;
V_13 -> V_62 . V_185 = F_56 ;
V_13 -> V_62 . V_186 = F_60 ;
V_13 -> V_62 . V_187 = F_42 ;
V_13 -> V_62 . V_188 = F_61 ;
V_13 -> V_62 . V_189 = F_68 ;
V_13 -> V_62 . V_190 = F_69 ;
V_13 -> V_62 . V_191 = F_64 ;
V_13 -> V_62 . V_192 = V_193 ;
V_13 -> V_163 = F_74 ( & V_165 -> V_63 ,
V_13 -> V_162 * sizeof( struct V_1 ) , V_171 ) ;
if ( V_13 -> V_163 == NULL )
return - V_172 ;
for ( V_54 = 0 ; V_54 < V_13 -> V_162 ; V_54 ++ ) {
struct V_1 * V_43 = & V_13 -> V_163 [ V_54 ] ;
V_43 -> V_88 = V_153 ;
F_85 ( & V_43 -> V_72 ) ;
V_43 -> V_4 . V_194 = F_62 ;
F_87 ( & V_43 -> V_4 , & V_13 -> V_62 ) ;
}
V_85 = F_88 ( V_13 -> V_175 ) ;
if ( V_85 < 0 ) {
F_81 ( & V_165 -> V_63 , L_15 , V_85 ) ;
return V_85 ;
}
F_11 ( V_13 , true ) ;
V_85 = F_89 ( & V_13 -> V_62 ) ;
if ( V_85 )
goto V_195;
V_85 = F_90 ( ( & V_165 -> V_63 ) -> V_174 ,
F_70 , V_13 ) ;
if ( V_85 )
goto V_196;
F_91 ( & V_13 -> V_58 ) ;
F_85 ( & V_13 -> V_79 ) ;
F_92 ( & V_13 -> V_64 , F_28 , ( unsigned long ) V_13 ) ;
F_93 ( V_165 , V_13 ) ;
F_94 ( & V_165 -> V_63 , L_16 ) ;
return 0 ;
V_196:
F_95 ( & V_13 -> V_62 ) ;
V_195:
F_96 ( V_13 -> V_175 ) ;
return V_85 ;
}
static int F_97 ( struct V_164 * V_165 )
{
struct V_1 * V_43 , * V_75 ;
struct V_12 * V_13 = F_98 ( V_165 ) ;
F_95 ( & V_13 -> V_62 ) ;
F_99 ( ( & V_165 -> V_63 ) -> V_174 ) ;
F_100 ( & V_165 -> V_63 , V_13 -> V_40 , V_13 ) ;
F_29 (c, cn, &d->slave.channels, vc.chan.device_node) {
F_27 ( & V_43 -> V_4 . V_3 . V_197 ) ;
F_101 ( & V_43 -> V_4 . V_64 ) ;
}
F_101 ( & V_13 -> V_64 ) ;
F_96 ( V_13 -> V_175 ) ;
return 0 ;
}
static int F_102 ( struct V_67 * V_63 )
{
struct V_12 * V_13 = F_103 ( V_63 ) ;
T_1 V_44 = 0 ;
V_44 = F_10 ( V_13 ) ;
if ( V_44 ) {
F_22 ( V_13 -> V_62 . V_63 ,
L_17 , V_44 ) ;
return - 1 ;
}
F_11 ( V_13 , false ) ;
F_96 ( V_13 -> V_175 ) ;
return 0 ;
}
static int F_104 ( struct V_67 * V_63 )
{
struct V_12 * V_13 = F_103 ( V_63 ) ;
int V_85 = 0 ;
V_85 = F_88 ( V_13 -> V_175 ) ;
if ( V_85 < 0 ) {
F_81 ( V_13 -> V_62 . V_63 , L_15 , V_85 ) ;
return V_85 ;
}
F_11 ( V_13 , true ) ;
return 0 ;
}
