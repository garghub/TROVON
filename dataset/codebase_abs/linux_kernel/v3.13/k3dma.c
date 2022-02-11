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
}
static void F_7 ( struct V_5 * V_6 , struct V_18 * V_19 )
{
F_5 ( V_19 -> V_20 , V_6 -> V_9 + V_21 ) ;
F_5 ( V_19 -> V_22 , V_6 -> V_9 + V_23 ) ;
F_5 ( V_19 -> V_24 , V_6 -> V_9 + V_25 ) ;
F_5 ( V_19 -> V_26 , V_6 -> V_9 + V_27 ) ;
F_5 ( V_28 , V_6 -> V_9 + V_29 ) ;
F_5 ( V_19 -> V_30 , V_6 -> V_9 + V_10 ) ;
}
static T_1 F_8 ( struct V_12 * V_13 , struct V_5 * V_6 )
{
T_1 V_31 = 0 ;
V_31 = F_4 ( V_13 -> V_9 + V_32 + V_6 -> V_14 * 0x10 ) ;
V_31 &= 0xffff ;
return V_31 ;
}
static T_1 F_9 ( struct V_5 * V_6 )
{
return F_4 ( V_6 -> V_9 + V_21 ) ;
}
static T_1 F_10 ( struct V_12 * V_13 )
{
return F_4 ( V_13 -> V_9 + V_33 ) ;
}
static void F_11 ( struct V_12 * V_13 , bool V_7 )
{
if ( V_7 ) {
F_5 ( 0x0 , V_13 -> V_9 + V_34 ) ;
F_5 ( 0xffff , V_13 -> V_9 + V_35 ) ;
F_5 ( 0xffff , V_13 -> V_9 + V_36 ) ;
F_5 ( 0xffff , V_13 -> V_9 + V_37 ) ;
} else {
F_5 ( 0x0 , V_13 -> V_9 + V_35 ) ;
F_5 ( 0x0 , V_13 -> V_9 + V_36 ) ;
F_5 ( 0x0 , V_13 -> V_9 + V_37 ) ;
}
}
static T_2 F_12 ( int V_38 , void * V_39 )
{
struct V_12 * V_13 = (struct V_12 * ) V_39 ;
struct V_5 * V_40 ;
struct V_1 * V_41 ;
T_1 V_42 = F_4 ( V_13 -> V_9 + V_43 ) ;
T_1 V_44 = F_4 ( V_13 -> V_9 + V_45 ) ;
T_1 V_46 = F_4 ( V_13 -> V_9 + V_47 ) ;
T_1 V_48 = F_4 ( V_13 -> V_9 + V_49 ) ;
T_1 V_50 , V_51 = 0 ;
while ( V_42 ) {
V_50 = F_13 ( V_42 ) ;
V_42 &= ( V_42 - 1 ) ;
if ( F_14 ( V_44 & F_15 ( V_50 ) ) ) {
V_40 = & V_13 -> V_6 [ V_50 ] ;
V_41 = V_40 -> V_52 ;
if ( V_41 ) {
unsigned long V_53 ;
F_16 ( & V_41 -> V_4 . V_54 , V_53 ) ;
F_17 ( & V_40 -> V_55 -> V_56 ) ;
V_40 -> V_57 = V_40 -> V_55 ;
F_18 ( & V_41 -> V_4 . V_54 , V_53 ) ;
}
V_51 |= F_15 ( V_50 ) ;
}
if ( F_19 ( ( V_46 & F_15 ( V_50 ) ) || ( V_48 & F_15 ( V_50 ) ) ) )
F_20 ( V_13 -> V_58 . V_59 , L_1 ) ;
}
F_5 ( V_51 , V_13 -> V_9 + V_15 ) ;
F_5 ( V_46 , V_13 -> V_9 + V_16 ) ;
F_5 ( V_48 , V_13 -> V_9 + V_17 ) ;
if ( V_51 ) {
F_21 ( & V_13 -> V_60 ) ;
return V_61 ;
} else
return V_62 ;
}
static int F_22 ( struct V_1 * V_41 )
{
struct V_12 * V_13 = F_23 ( V_41 -> V_4 . V_3 . V_63 ) ;
struct V_64 * V_56 = F_24 ( & V_41 -> V_4 ) ;
if ( ! V_41 -> V_6 )
return - V_65 ;
if ( F_15 ( V_41 -> V_6 -> V_14 ) & F_10 ( V_13 ) )
return - V_65 ;
if ( V_56 ) {
struct V_66 * V_67 =
F_2 ( V_56 , struct V_66 , V_56 ) ;
F_25 ( & V_67 -> V_56 . V_68 ) ;
V_41 -> V_6 -> V_55 = V_67 ;
V_41 -> V_6 -> V_57 = NULL ;
F_7 ( V_41 -> V_6 , & V_67 -> V_69 [ 0 ] ) ;
return 0 ;
}
V_41 -> V_6 -> V_57 = NULL ;
V_41 -> V_6 -> V_55 = NULL ;
return - V_65 ;
}
static void F_26 ( unsigned long V_70 )
{
struct V_12 * V_13 = (struct V_12 * ) V_70 ;
struct V_5 * V_40 ;
struct V_1 * V_41 , * V_71 ;
unsigned V_72 , V_73 = 0 ;
F_27 (c, cn, &d->slave.channels, vc.chan.device_node) {
F_28 ( & V_41 -> V_4 . V_54 ) ;
V_40 = V_41 -> V_6 ;
if ( V_40 && V_40 -> V_57 ) {
if ( F_22 ( V_41 ) ) {
F_29 ( V_13 -> V_58 . V_59 , L_2 , V_40 -> V_14 ) ;
V_41 -> V_6 = NULL ;
V_40 -> V_52 = NULL ;
}
}
F_30 ( & V_41 -> V_4 . V_54 ) ;
}
F_28 ( & V_13 -> V_54 ) ;
for ( V_72 = 0 ; V_72 < V_13 -> V_74 ; V_72 ++ ) {
V_40 = & V_13 -> V_6 [ V_72 ] ;
if ( V_40 -> V_52 == NULL && ! F_31 ( & V_13 -> V_75 ) ) {
V_41 = F_32 ( & V_13 -> V_75 ,
struct V_1 , V_68 ) ;
F_33 ( & V_41 -> V_68 ) ;
V_73 |= 1 << V_72 ;
V_40 -> V_52 = V_41 ;
V_41 -> V_6 = V_40 ;
F_29 ( V_13 -> V_58 . V_59 , L_3 , V_72 , & V_41 -> V_4 ) ;
}
}
F_30 ( & V_13 -> V_54 ) ;
for ( V_72 = 0 ; V_72 < V_13 -> V_74 ; V_72 ++ ) {
if ( V_73 & ( 1 << V_72 ) ) {
V_40 = & V_13 -> V_6 [ V_72 ] ;
V_41 = V_40 -> V_52 ;
if ( V_41 ) {
F_28 ( & V_41 -> V_4 . V_54 ) ;
F_22 ( V_41 ) ;
F_30 ( & V_41 -> V_4 . V_54 ) ;
}
}
}
}
static int F_34 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_35 ( struct V_2 * V_3 )
{
struct V_1 * V_41 = F_1 ( V_3 ) ;
struct V_12 * V_13 = F_23 ( V_3 -> V_63 ) ;
unsigned long V_53 ;
F_16 ( & V_13 -> V_54 , V_53 ) ;
F_33 ( & V_41 -> V_68 ) ;
F_18 ( & V_13 -> V_54 , V_53 ) ;
F_36 ( & V_41 -> V_4 ) ;
V_41 -> V_76 = 0 ;
}
static enum V_77 F_37 ( struct V_2 * V_3 ,
T_3 V_78 , struct V_79 * V_80 )
{
struct V_1 * V_41 = F_1 ( V_3 ) ;
struct V_12 * V_13 = F_23 ( V_3 -> V_63 ) ;
struct V_5 * V_40 ;
struct V_64 * V_56 ;
unsigned long V_53 ;
enum V_77 V_81 ;
T_4 V_82 = 0 ;
V_81 = F_38 ( & V_41 -> V_4 . V_3 , V_78 , V_80 ) ;
if ( V_81 == V_83 )
return V_81 ;
F_16 ( & V_41 -> V_4 . V_54 , V_53 ) ;
V_40 = V_41 -> V_6 ;
V_81 = V_41 -> V_84 ;
V_56 = F_39 ( & V_41 -> V_4 , V_78 ) ;
if ( V_56 ) {
V_82 = F_2 ( V_56 , struct V_66 , V_56 ) -> V_85 ;
} else if ( ( ! V_40 ) || ( ! V_40 -> V_55 ) ) {
V_82 = 0 ;
} else {
struct V_66 * V_67 = V_40 -> V_55 ;
T_1 V_86 = 0 , V_87 = 0 ;
V_82 = F_8 ( V_13 , V_40 ) ;
V_86 = F_9 ( V_40 ) ;
V_87 = ( V_86 - V_67 -> V_88 ) / sizeof( struct V_18 ) ;
for (; V_87 < V_67 -> V_89 ; V_87 ++ ) {
V_82 += V_67 -> V_69 [ V_87 ] . V_22 ;
if ( ! V_67 -> V_69 [ V_87 ] . V_20 )
break;
}
}
F_18 ( & V_41 -> V_4 . V_54 , V_53 ) ;
F_40 ( V_80 , V_82 ) ;
return V_81 ;
}
static void F_41 ( struct V_2 * V_3 )
{
struct V_1 * V_41 = F_1 ( V_3 ) ;
struct V_12 * V_13 = F_23 ( V_3 -> V_63 ) ;
unsigned long V_53 ;
F_16 ( & V_41 -> V_4 . V_54 , V_53 ) ;
if ( F_42 ( & V_41 -> V_4 ) ) {
F_43 ( & V_13 -> V_54 ) ;
if ( ! V_41 -> V_6 ) {
if ( F_31 ( & V_41 -> V_68 ) ) {
F_44 ( & V_41 -> V_68 , & V_13 -> V_75 ) ;
F_21 ( & V_13 -> V_60 ) ;
F_29 ( V_13 -> V_58 . V_59 , L_4 , & V_41 -> V_4 ) ;
}
}
F_45 ( & V_13 -> V_54 ) ;
} else
F_29 ( V_13 -> V_58 . V_59 , L_5 , & V_41 -> V_4 ) ;
F_18 ( & V_41 -> V_4 . V_54 , V_53 ) ;
}
static void F_46 ( struct V_66 * V_67 , T_5 V_90 ,
T_5 V_91 , T_4 V_92 , T_1 V_93 , T_1 V_76 )
{
if ( ( V_93 + 1 ) < V_67 -> V_89 )
V_67 -> V_69 [ V_93 ] . V_20 = V_67 -> V_88 + ( V_93 + 1 ) *
sizeof( struct V_18 ) ;
V_67 -> V_69 [ V_93 ] . V_20 |= V_94 ;
V_67 -> V_69 [ V_93 ] . V_22 = V_92 ;
V_67 -> V_69 [ V_93 ] . V_24 = V_91 ;
V_67 -> V_69 [ V_93 ] . V_26 = V_90 ;
V_67 -> V_69 [ V_93 ] . V_30 = V_76 ;
}
static struct V_95 * F_47 (
struct V_2 * V_3 , T_5 V_90 , T_5 V_91 ,
T_4 V_92 , unsigned long V_53 )
{
struct V_1 * V_41 = F_1 ( V_3 ) ;
struct V_66 * V_67 ;
T_4 V_96 = 0 ;
int V_93 = 0 ;
if ( ! V_92 )
return NULL ;
V_93 = F_48 ( V_92 , V_97 ) ;
V_67 = F_49 ( sizeof( * V_67 ) + V_93 * sizeof( V_67 -> V_69 [ 0 ] ) , V_98 ) ;
if ( ! V_67 ) {
F_29 ( V_3 -> V_63 -> V_59 , L_6 , & V_41 -> V_4 ) ;
return NULL ;
}
V_67 -> V_88 = F_50 ( ( unsigned long ) & V_67 -> V_69 [ 0 ] ) ;
V_67 -> V_85 = V_92 ;
V_67 -> V_89 = V_93 ;
V_93 = 0 ;
if ( ! V_41 -> V_76 ) {
V_41 -> V_76 = V_99 | V_100 | V_11 ;
V_41 -> V_76 |= ( 0xf << 20 ) | ( 0xf << 24 ) ;
V_41 -> V_76 |= ( 0x3 << 12 ) | ( 0x3 << 16 ) ;
}
do {
V_96 = F_51 ( T_4 , V_92 , V_97 ) ;
F_46 ( V_67 , V_90 , V_91 , V_96 , V_93 ++ , V_41 -> V_76 ) ;
if ( V_41 -> V_101 == V_102 ) {
V_91 += V_96 ;
} else if ( V_41 -> V_101 == V_103 ) {
V_90 += V_96 ;
} else {
V_91 += V_96 ;
V_90 += V_96 ;
}
V_92 -= V_96 ;
} while ( V_92 );
V_67 -> V_69 [ V_93 - 1 ] . V_20 = 0 ;
return F_52 ( & V_41 -> V_4 , & V_67 -> V_56 , V_53 ) ;
}
static struct V_95 * F_53 (
struct V_2 * V_3 , struct V_104 * V_105 , unsigned int V_106 ,
enum V_107 V_101 , unsigned long V_53 , void * V_108 )
{
struct V_1 * V_41 = F_1 ( V_3 ) ;
struct V_66 * V_67 ;
T_4 V_92 , V_109 , V_110 = 0 ;
struct V_104 * V_111 ;
T_5 V_112 , V_91 = 0 , V_90 = 0 ;
int V_93 = V_106 , V_50 ;
if ( V_105 == 0 )
return NULL ;
F_54 (sgl, sg, sglen, i) {
V_109 = F_55 ( V_111 ) ;
if ( V_109 > V_97 )
V_93 += F_48 ( V_109 , V_97 ) - 1 ;
}
V_67 = F_49 ( sizeof( * V_67 ) + V_93 * sizeof( V_67 -> V_69 [ 0 ] ) , V_98 ) ;
if ( ! V_67 ) {
F_29 ( V_3 -> V_63 -> V_59 , L_6 , & V_41 -> V_4 ) ;
return NULL ;
}
V_67 -> V_88 = F_50 ( ( unsigned long ) & V_67 -> V_69 [ 0 ] ) ;
V_67 -> V_89 = V_93 ;
V_93 = 0 ;
F_54 (sgl, sg, sglen, i) {
V_112 = F_56 ( V_111 ) ;
V_109 = F_55 ( V_111 ) ;
V_110 += V_109 ;
do {
V_92 = F_51 ( T_4 , V_109 , V_97 ) ;
if ( V_101 == V_102 ) {
V_91 = V_112 ;
V_90 = V_41 -> V_113 ;
} else if ( V_101 == V_103 ) {
V_91 = V_41 -> V_113 ;
V_90 = V_112 ;
}
F_46 ( V_67 , V_90 , V_91 , V_92 , V_93 ++ , V_41 -> V_76 ) ;
V_112 += V_92 ;
V_109 -= V_92 ;
} while ( V_109 );
}
V_67 -> V_69 [ V_93 - 1 ] . V_20 = 0 ;
V_67 -> V_85 = V_110 ;
return F_52 ( & V_41 -> V_4 , & V_67 -> V_56 , V_53 ) ;
}
static int F_57 ( struct V_2 * V_3 , enum V_114 V_115 ,
unsigned long V_70 )
{
struct V_1 * V_41 = F_1 ( V_3 ) ;
struct V_12 * V_13 = F_23 ( V_3 -> V_63 ) ;
struct V_116 * V_117 = ( void * ) V_70 ;
struct V_5 * V_40 = V_41 -> V_6 ;
unsigned long V_53 ;
T_1 V_118 = 0 , V_8 = 0 ;
enum V_119 V_120 = V_121 ;
F_58 ( V_122 ) ;
switch ( V_115 ) {
case V_123 :
if ( V_117 == NULL )
return - V_124 ;
V_41 -> V_101 = V_117 -> V_125 ;
if ( V_41 -> V_101 == V_103 ) {
V_41 -> V_76 = V_100 ;
V_41 -> V_113 = V_117 -> V_126 ;
V_118 = V_117 -> V_127 ;
V_120 = V_117 -> V_128 ;
} else if ( V_41 -> V_101 == V_102 ) {
V_41 -> V_76 = V_99 ;
V_41 -> V_113 = V_117 -> V_129 ;
V_118 = V_117 -> V_130 ;
V_120 = V_117 -> V_131 ;
}
switch ( V_120 ) {
case V_132 :
case V_133 :
case V_134 :
case V_135 :
V_8 = F_13 ( V_120 ) ;
break;
default:
V_8 = 3 ;
break;
}
V_41 -> V_76 |= ( V_8 << 12 ) | ( V_8 << 16 ) ;
if ( ( V_118 == 0 ) || ( V_118 > 16 ) )
V_8 = 16 ;
else
V_8 = V_118 - 1 ;
V_41 -> V_76 |= ( V_8 << 20 ) | ( V_8 << 24 ) ;
V_41 -> V_76 |= V_136 | V_11 ;
V_41 -> V_76 |= V_41 -> V_4 . V_3 . V_137 << 4 ;
break;
case V_138 :
F_29 ( V_13 -> V_58 . V_59 , L_7 , & V_41 -> V_4 ) ;
F_43 ( & V_13 -> V_54 ) ;
F_33 ( & V_41 -> V_68 ) ;
F_45 ( & V_13 -> V_54 ) ;
F_16 ( & V_41 -> V_4 . V_54 , V_53 ) ;
F_59 ( & V_41 -> V_4 , & V_122 ) ;
if ( V_40 ) {
F_6 ( V_40 , V_13 ) ;
V_41 -> V_6 = NULL ;
V_40 -> V_52 = NULL ;
V_40 -> V_55 = V_40 -> V_57 = NULL ;
}
F_18 ( & V_41 -> V_4 . V_54 , V_53 ) ;
F_60 ( & V_41 -> V_4 , & V_122 ) ;
break;
case V_139 :
F_29 ( V_13 -> V_58 . V_59 , L_8 , & V_41 -> V_4 ) ;
if ( V_41 -> V_84 == V_140 ) {
V_41 -> V_84 = V_141 ;
if ( V_40 ) {
F_3 ( V_40 , false ) ;
} else {
F_43 ( & V_13 -> V_54 ) ;
F_33 ( & V_41 -> V_68 ) ;
F_45 ( & V_13 -> V_54 ) ;
}
}
break;
case V_142 :
F_29 ( V_13 -> V_58 . V_59 , L_9 , & V_41 -> V_4 ) ;
F_16 ( & V_41 -> V_4 . V_54 , V_53 ) ;
if ( V_41 -> V_84 == V_141 ) {
V_41 -> V_84 = V_140 ;
if ( V_40 ) {
F_3 ( V_40 , true ) ;
} else if ( ! F_31 ( & V_41 -> V_4 . V_143 ) ) {
F_43 ( & V_13 -> V_54 ) ;
F_44 ( & V_41 -> V_68 , & V_13 -> V_75 ) ;
F_45 ( & V_13 -> V_54 ) ;
}
}
F_18 ( & V_41 -> V_4 . V_54 , V_53 ) ;
break;
default:
return - V_144 ;
}
return 0 ;
}
static void F_61 ( struct V_64 * V_56 )
{
struct V_66 * V_67 =
F_2 ( V_56 , struct V_66 , V_56 ) ;
F_62 ( V_67 ) ;
}
static struct V_2 * F_63 ( struct V_145 * V_146 ,
struct V_147 * V_148 )
{
struct V_12 * V_13 = V_148 -> V_149 ;
unsigned int V_150 = V_146 -> args [ 0 ] ;
if ( V_150 > V_13 -> V_151 )
return NULL ;
return F_64 ( & ( V_13 -> V_152 [ V_150 ] . V_4 . V_3 ) ) ;
}
static int F_65 ( struct V_153 * V_154 )
{
struct V_12 * V_13 ;
const struct V_155 * V_156 ;
struct V_157 * V_158 ;
int V_50 , V_81 , V_38 = 0 ;
V_158 = F_66 ( V_154 , V_159 , 0 ) ;
if ( ! V_158 )
return - V_124 ;
V_13 = F_67 ( & V_154 -> V_59 , sizeof( * V_13 ) , V_160 ) ;
if ( ! V_13 )
return - V_161 ;
V_13 -> V_9 = F_68 ( & V_154 -> V_59 , V_158 ) ;
if ( F_69 ( V_13 -> V_9 ) )
return F_70 ( V_13 -> V_9 ) ;
V_156 = F_71 ( V_162 , & V_154 -> V_59 ) ;
if ( V_156 ) {
F_72 ( ( & V_154 -> V_59 ) -> V_163 ,
L_10 , & V_13 -> V_74 ) ;
F_72 ( ( & V_154 -> V_59 ) -> V_163 ,
L_11 , & V_13 -> V_151 ) ;
}
V_13 -> V_164 = F_73 ( & V_154 -> V_59 , NULL ) ;
if ( F_69 ( V_13 -> V_164 ) ) {
F_74 ( & V_154 -> V_59 , L_12 ) ;
return F_70 ( V_13 -> V_164 ) ;
}
V_38 = F_75 ( V_154 , 0 ) ;
V_81 = F_76 ( & V_154 -> V_59 , V_38 ,
F_12 , 0 , V_165 , V_13 ) ;
if ( V_81 )
return V_81 ;
V_13 -> V_6 = F_67 ( & V_154 -> V_59 ,
V_13 -> V_74 * sizeof( struct V_5 ) , V_160 ) ;
if ( V_13 -> V_6 == NULL )
return - V_161 ;
for ( V_50 = 0 ; V_50 < V_13 -> V_74 ; V_50 ++ ) {
struct V_5 * V_40 = & V_13 -> V_6 [ V_50 ] ;
V_40 -> V_14 = V_50 ;
V_40 -> V_9 = V_13 -> V_9 + V_50 * 0x40 ;
}
F_77 ( & V_13 -> V_58 . V_166 ) ;
F_78 ( V_167 , V_13 -> V_58 . V_168 ) ;
F_78 ( V_169 , V_13 -> V_58 . V_168 ) ;
V_13 -> V_58 . V_59 = & V_154 -> V_59 ;
V_13 -> V_58 . V_170 = F_34 ;
V_13 -> V_58 . V_171 = F_35 ;
V_13 -> V_58 . V_172 = F_37 ;
V_13 -> V_58 . V_173 = F_47 ;
V_13 -> V_58 . V_174 = F_53 ;
V_13 -> V_58 . V_175 = F_41 ;
V_13 -> V_58 . V_176 = F_57 ;
V_13 -> V_58 . V_177 = V_178 ;
V_13 -> V_58 . V_179 = V_13 -> V_151 ;
V_13 -> V_152 = F_67 ( & V_154 -> V_59 ,
V_13 -> V_151 * sizeof( struct V_1 ) , V_160 ) ;
if ( V_13 -> V_152 == NULL )
return - V_161 ;
for ( V_50 = 0 ; V_50 < V_13 -> V_151 ; V_50 ++ ) {
struct V_1 * V_41 = & V_13 -> V_152 [ V_50 ] ;
V_41 -> V_84 = V_140 ;
F_77 ( & V_41 -> V_68 ) ;
V_41 -> V_4 . V_180 = F_61 ;
F_79 ( & V_41 -> V_4 , & V_13 -> V_58 ) ;
}
V_81 = F_80 ( V_13 -> V_164 ) ;
if ( V_81 < 0 ) {
F_74 ( & V_154 -> V_59 , L_13 , V_81 ) ;
return V_81 ;
}
F_11 ( V_13 , true ) ;
V_81 = F_81 ( & V_13 -> V_58 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_82 ( ( & V_154 -> V_59 ) -> V_163 ,
F_63 , V_13 ) ;
if ( V_81 )
goto V_181;
F_83 ( & V_13 -> V_54 ) ;
F_77 ( & V_13 -> V_75 ) ;
F_84 ( & V_13 -> V_60 , F_26 , ( unsigned long ) V_13 ) ;
F_85 ( V_154 , V_13 ) ;
F_86 ( & V_154 -> V_59 , L_14 ) ;
return 0 ;
V_181:
F_87 ( & V_13 -> V_58 ) ;
return V_81 ;
}
static int F_88 ( struct V_153 * V_154 )
{
struct V_1 * V_41 , * V_71 ;
struct V_12 * V_13 = F_89 ( V_154 ) ;
F_87 ( & V_13 -> V_58 ) ;
F_90 ( ( & V_154 -> V_59 ) -> V_163 ) ;
F_27 (c, cn, &d->slave.channels, vc.chan.device_node) {
F_25 ( & V_41 -> V_4 . V_3 . V_182 ) ;
F_91 ( & V_41 -> V_4 . V_60 ) ;
}
F_91 ( & V_13 -> V_60 ) ;
F_92 ( V_13 -> V_164 ) ;
return 0 ;
}
static int F_93 ( struct V_63 * V_59 )
{
struct V_12 * V_13 = F_94 ( V_59 ) ;
T_1 V_42 = 0 ;
V_42 = F_10 ( V_13 ) ;
if ( V_42 ) {
F_20 ( V_13 -> V_58 . V_59 ,
L_15 , V_42 ) ;
return - 1 ;
}
F_11 ( V_13 , false ) ;
F_92 ( V_13 -> V_164 ) ;
return 0 ;
}
static int F_95 ( struct V_63 * V_59 )
{
struct V_12 * V_13 = F_94 ( V_59 ) ;
int V_81 = 0 ;
V_81 = F_80 ( V_13 -> V_164 ) ;
if ( V_81 < 0 ) {
F_74 ( V_13 -> V_58 . V_59 , L_13 , V_81 ) ;
return V_81 ;
}
F_11 ( V_13 , true ) ;
return 0 ;
}
