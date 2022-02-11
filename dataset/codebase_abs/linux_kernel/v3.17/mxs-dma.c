static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_1 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = V_4 -> V_3 . V_7 ;
if ( V_4 -> V_8 & V_9 &&
V_4 -> V_8 & V_10 ) {
V_4 -> V_11 = true ;
} else if ( F_4 ( V_6 ) && F_5 ( V_6 ) ) {
F_6 ( 1 << ( V_7 + V_12 ) ,
V_6 -> V_13 + V_14 + V_15 ) ;
} else {
unsigned long V_16 = 0 ;
const unsigned long V_17 = 50000 ;
void T_1 * V_18 = V_6 -> V_13 +
F_7 ( V_6 , V_7 ) ;
while ( ( F_8 ( V_18 ) & 0xf ) == 0x8 && V_16 < V_17 ) {
F_9 ( 100 ) ;
V_16 += 100 ;
}
if ( V_16 >= V_17 )
F_10 ( & V_4 -> V_6 -> V_19 -> V_20 ,
L_1 ,
V_7 ) ;
F_6 ( 1 << ( V_7 + V_21 ) ,
V_6 -> V_13 + V_22 + V_15 ) ;
}
V_4 -> V_23 = V_24 ;
}
static void F_11 ( struct V_1 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = V_4 -> V_3 . V_7 ;
F_6 ( V_4 -> V_25 ,
V_6 -> V_13 + F_12 ( V_6 , V_7 ) ) ;
if ( V_4 -> V_8 & V_9 &&
V_4 -> V_8 & V_10 ) {
F_6 ( 2 , V_6 -> V_13 + F_13 ( V_6 , V_7 ) ) ;
} else {
F_6 ( 1 , V_6 -> V_13 + F_13 ( V_6 , V_7 ) ) ;
}
V_4 -> V_11 = false ;
}
static void F_14 ( struct V_1 * V_4 )
{
V_4 -> V_23 = V_24 ;
}
static void F_15 ( struct V_1 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = V_4 -> V_3 . V_7 ;
if ( F_4 ( V_6 ) && F_5 ( V_6 ) )
F_6 ( 1 << V_7 ,
V_6 -> V_13 + V_14 + V_15 ) ;
else
F_6 ( 1 << V_7 ,
V_6 -> V_13 + V_22 + V_15 ) ;
V_4 -> V_23 = V_26 ;
}
static void F_16 ( struct V_1 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = V_4 -> V_3 . V_7 ;
if ( F_4 ( V_6 ) && F_5 ( V_6 ) )
F_6 ( 1 << V_7 ,
V_6 -> V_13 + V_14 + V_27 ) ;
else
F_6 ( 1 << V_7 ,
V_6 -> V_13 + V_22 + V_27 ) ;
V_4 -> V_23 = V_28 ;
}
static T_2 F_17 ( struct V_29 * V_30 )
{
return F_18 ( V_30 ) ;
}
static void F_19 ( unsigned long V_31 )
{
struct V_1 * V_4 = (struct V_1 * ) V_31 ;
if ( V_4 -> V_32 . V_33 )
V_4 -> V_32 . V_33 ( V_4 -> V_32 . V_34 ) ;
}
static int F_20 ( struct V_5 * V_6 , int V_35 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 != V_6 -> V_37 ; ++ V_36 )
if ( V_6 -> V_38 [ V_36 ] . V_39 == V_35 )
return V_36 ;
return - V_40 ;
}
static T_3 F_21 ( int V_35 , void * V_41 )
{
struct V_5 * V_6 = V_41 ;
struct V_1 * V_4 ;
T_4 V_42 ;
T_4 V_43 ;
int V_3 = F_20 ( V_6 , V_35 ) ;
if ( V_3 < 0 )
return V_44 ;
V_42 = F_8 ( V_6 -> V_13 + V_45 ) ;
V_42 = ( V_42 >> V_3 ) & 0x1 ;
F_6 ( ( 1 << V_3 ) ,
V_6 -> V_13 + V_45 + V_27 ) ;
V_43 = F_8 ( V_6 -> V_13 + V_46 ) ;
V_43 &= ( 1 << ( V_47 + V_3 ) ) | ( 1 << V_3 ) ;
V_43 = ( V_43 >> ( V_47 + V_3 ) ) + ( V_43 >> V_3 ) ;
F_6 ( ( 1 << V_3 ) ,
V_6 -> V_13 + V_46 + V_27 ) ;
V_43 -= V_43 & V_42 ;
V_4 = & V_6 -> V_38 [ V_3 ] ;
if ( V_43 ) {
F_22 ( V_6 -> V_48 . V_20 ,
L_2 , V_49 ,
V_3 ) ;
V_4 -> V_23 = V_50 ;
F_3 ( V_4 ) ;
} else if ( V_4 -> V_23 != V_24 ) {
if ( V_4 -> V_8 & V_10 ) {
V_4 -> V_23 = V_28 ;
if ( V_4 -> V_8 & V_9 )
F_6 ( 1 , V_6 -> V_13 +
F_13 ( V_6 , V_3 ) ) ;
} else {
V_4 -> V_23 = V_24 ;
}
}
if ( V_4 -> V_23 == V_24 ) {
if ( V_4 -> V_11 )
return V_51 ;
F_23 ( & V_4 -> V_32 ) ;
}
F_24 ( & V_4 -> V_52 ) ;
return V_51 ;
}
static int F_25 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_53 ;
V_4 -> V_54 = F_26 ( V_6 -> V_48 . V_20 ,
V_55 ,
& V_4 -> V_25 , V_56 ) ;
if ( ! V_4 -> V_54 ) {
V_53 = - V_57 ;
goto V_58;
}
if ( V_4 -> V_39 != V_59 ) {
V_53 = F_27 ( V_4 -> V_39 , F_21 ,
0 , L_3 , V_6 ) ;
if ( V_53 )
goto V_60;
}
V_53 = F_28 ( V_6 -> V_61 ) ;
if ( V_53 )
goto V_62;
F_3 ( V_4 ) ;
F_29 ( & V_4 -> V_32 , V_3 ) ;
V_4 -> V_32 . V_63 = F_17 ;
F_30 ( & V_4 -> V_32 ) ;
return 0 ;
V_62:
F_31 ( V_4 -> V_39 , V_6 ) ;
V_60:
F_32 ( V_6 -> V_48 . V_20 , V_55 ,
V_4 -> V_54 , V_4 -> V_25 ) ;
V_58:
return V_53 ;
}
static void F_33 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
F_14 ( V_4 ) ;
F_31 ( V_4 -> V_39 , V_6 ) ;
F_32 ( V_6 -> V_48 . V_20 , V_55 ,
V_4 -> V_54 , V_4 -> V_25 ) ;
F_34 ( V_6 -> V_61 ) ;
}
static struct V_29 * F_35 (
struct V_2 * V_3 , struct V_64 * V_65 ,
unsigned int V_66 , enum V_67 V_68 ,
unsigned long V_8 , void * V_69 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_70 * V_54 ;
struct V_64 * V_71 ;
T_4 V_36 , V_72 ;
T_4 * V_73 ;
bool V_74 = V_8 & V_75 ;
int V_76 = V_74 ? V_4 -> V_77 : 0 ;
if ( V_4 -> V_23 == V_28 && ! V_74 )
return NULL ;
if ( V_66 + ( V_74 ? V_76 : 0 ) > V_78 ) {
F_10 ( V_6 -> V_48 . V_20 ,
L_4 ,
V_66 , V_78 ) ;
goto V_79;
}
V_4 -> V_23 = V_28 ;
V_4 -> V_8 = 0 ;
if ( V_74 ) {
F_36 ( V_76 < 1 ) ;
V_54 = & V_4 -> V_54 [ V_76 - 1 ] ;
V_54 -> V_80 = V_4 -> V_25 + sizeof( * V_54 ) * V_76 ;
V_54 -> V_81 |= V_82 ;
V_54 -> V_81 &= ~ V_83 ;
V_54 -> V_81 &= ~ V_84 ;
} else {
V_76 = 0 ;
}
if ( V_68 == V_85 ) {
V_54 = & V_4 -> V_54 [ V_76 ++ ] ;
V_73 = ( T_4 * ) V_65 ;
for ( V_72 = 0 ; V_72 < V_66 ; )
V_54 -> V_86 [ V_72 ++ ] = * V_73 ++ ;
V_54 -> V_81 = 0 ;
V_54 -> V_81 |= V_83 ;
V_54 -> V_81 |= V_84 ;
if ( V_8 & V_87 )
V_54 -> V_81 |= V_88 ;
V_54 -> V_81 |= V_89 ;
V_54 -> V_81 |= V_90 ;
V_54 -> V_81 |= F_37 ( V_66 , V_91 ) ;
V_54 -> V_81 |= F_37 ( V_92 , V_93 ) ;
} else {
F_38 (sgl, sg, sg_len, i) {
if ( F_39 ( V_71 ) > V_94 ) {
F_10 ( V_6 -> V_48 . V_20 , L_5 ,
F_39 ( V_71 ) , V_94 ) ;
goto V_79;
}
V_54 = & V_4 -> V_54 [ V_76 ++ ] ;
V_54 -> V_80 = V_4 -> V_25 + sizeof( * V_54 ) * V_76 ;
V_54 -> V_95 = V_71 -> V_96 ;
V_54 -> V_97 = F_39 ( V_71 ) ;
V_54 -> V_81 = 0 ;
V_54 -> V_81 |= V_82 ;
V_54 -> V_81 |= V_89 ;
V_54 -> V_81 |= V_90 ;
V_54 -> V_81 |= F_37 ( V_68 == V_98 ?
V_99 : V_100 ,
V_93 ) ;
if ( V_36 + 1 == V_66 ) {
V_54 -> V_81 &= ~ V_82 ;
V_54 -> V_81 |= V_83 ;
V_54 -> V_81 |= V_84 ;
if ( V_8 & V_87 )
V_54 -> V_81 |= V_88 ;
}
}
}
V_4 -> V_77 = V_76 ;
return & V_4 -> V_32 ;
V_79:
V_4 -> V_23 = V_50 ;
return NULL ;
}
static struct V_29 * F_40 (
struct V_2 * V_3 , T_5 V_101 , T_6 V_102 ,
T_6 V_103 , enum V_67 V_68 ,
unsigned long V_8 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_4 V_104 = V_102 / V_103 ;
T_4 V_36 = 0 , V_105 = 0 ;
if ( V_4 -> V_23 == V_28 )
return NULL ;
V_4 -> V_23 = V_28 ;
V_4 -> V_8 |= V_10 ;
V_4 -> V_8 |= V_9 ;
if ( V_104 > V_78 ) {
F_10 ( V_6 -> V_48 . V_20 ,
L_4 ,
V_104 , V_78 ) ;
goto V_79;
}
if ( V_103 > V_94 ) {
F_10 ( V_6 -> V_48 . V_20 ,
L_6 ,
V_103 , V_94 ) ;
goto V_79;
}
while ( V_105 < V_102 ) {
struct V_70 * V_54 = & V_4 -> V_54 [ V_36 ] ;
if ( V_36 + 1 == V_104 )
V_54 -> V_80 = V_4 -> V_25 ;
else
V_54 -> V_80 = V_4 -> V_25 + sizeof( * V_54 ) * ( V_36 + 1 ) ;
V_54 -> V_95 = V_101 ;
V_54 -> V_97 = V_103 ;
V_54 -> V_81 = 0 ;
V_54 -> V_81 |= V_82 ;
V_54 -> V_81 |= V_83 ;
V_54 -> V_81 |= V_89 ;
V_54 -> V_81 |= V_90 ;
V_54 -> V_81 |= V_84 ;
V_54 -> V_81 |= F_37 ( V_68 == V_98 ?
V_99 : V_100 , V_93 ) ;
V_101 += V_103 ;
V_105 += V_103 ;
V_36 ++ ;
}
V_4 -> V_77 = V_36 ;
return & V_4 -> V_32 ;
V_79:
V_4 -> V_23 = V_50 ;
return NULL ;
}
static int F_41 ( struct V_2 * V_3 , enum V_106 V_107 ,
unsigned long V_108 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_53 = 0 ;
switch ( V_107 ) {
case V_109 :
F_3 ( V_4 ) ;
F_14 ( V_4 ) ;
break;
case V_110 :
F_15 ( V_4 ) ;
break;
case V_111 :
F_16 ( V_4 ) ;
break;
default:
V_53 = - V_112 ;
}
return V_53 ;
}
static enum V_113 F_42 ( struct V_2 * V_3 ,
T_2 V_114 , struct V_115 * V_116 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_4 V_117 = 0 ;
if ( V_4 -> V_23 == V_28 &&
V_4 -> V_8 & V_10 ) {
struct V_70 * V_118 ;
T_4 V_119 ;
V_118 = & V_4 -> V_54 [ V_4 -> V_77 - 1 ] ;
V_117 = V_118 -> V_97 + V_118 -> V_95 ;
V_119 = F_8 ( V_6 -> V_13 +
F_43 ( V_6 , V_3 -> V_7 ) ) ;
V_117 -= V_119 ;
}
F_44 ( V_116 , V_3 -> V_120 , V_3 -> V_114 ,
V_117 ) ;
return V_4 -> V_23 ;
}
static void F_45 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_11 ( V_4 ) ;
}
static int T_7 F_46 ( struct V_5 * V_6 )
{
int V_53 ;
V_53 = F_28 ( V_6 -> V_61 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_47 ( V_6 -> V_13 ) ;
if ( V_53 )
goto V_79;
if ( F_4 ( V_6 ) ) {
F_6 ( V_121 ,
V_6 -> V_13 + V_14 + V_15 ) ;
F_6 ( V_122 ,
V_6 -> V_13 + V_14 + V_15 ) ;
}
F_6 ( V_123 << V_47 ,
V_6 -> V_13 + V_45 + V_15 ) ;
V_79:
F_34 ( V_6 -> V_61 ) ;
return V_53 ;
}
static bool F_48 ( struct V_2 * V_3 , void * V_124 )
{
struct V_125 * V_126 = V_124 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_39 ;
if ( V_6 -> V_48 . V_20 -> V_127 != V_126 -> V_127 )
return false ;
if ( V_3 -> V_7 != V_126 -> V_7 )
return false ;
V_39 = F_49 ( V_6 -> V_19 , V_126 -> V_7 ) ;
if ( V_39 < 0 )
return false ;
V_4 -> V_39 = V_39 ;
return true ;
}
static struct V_2 * F_50 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_5 * V_6 = V_131 -> V_132 ;
T_8 V_133 = V_6 -> V_48 . V_134 ;
struct V_125 V_126 ;
if ( V_129 -> V_135 != 1 )
return NULL ;
V_126 . V_127 = V_131 -> V_127 ;
V_126 . V_7 = V_129 -> args [ 0 ] ;
if ( V_126 . V_7 >= V_6 -> V_37 )
return NULL ;
return F_51 ( V_133 , F_48 , & V_126 ) ;
}
static int T_7 F_52 ( struct V_136 * V_19 )
{
struct V_137 * V_138 = V_19 -> V_20 . V_127 ;
const struct V_139 * V_140 ;
const struct V_141 * V_142 ;
const struct V_143 * V_144 ;
struct V_5 * V_6 ;
struct V_145 * V_146 ;
int V_53 , V_36 ;
V_6 = F_53 ( & V_19 -> V_20 , sizeof( * V_6 ) , V_56 ) ;
if ( ! V_6 )
return - V_57 ;
V_53 = F_54 ( V_138 , L_7 , & V_6 -> V_37 ) ;
if ( V_53 ) {
F_10 ( & V_19 -> V_20 , L_8 ) ;
return V_53 ;
}
V_142 = F_55 ( V_147 , & V_19 -> V_20 ) ;
if ( V_142 )
V_140 = V_142 -> V_31 ;
else
V_140 = F_56 ( V_19 ) ;
V_144 = (struct V_143 * ) V_140 -> V_148 ;
V_6 -> type = V_144 -> type ;
V_6 -> V_41 = V_144 -> V_149 ;
V_146 = F_57 ( V_19 , V_150 , 0 ) ;
V_6 -> V_13 = F_58 ( & V_19 -> V_20 , V_146 ) ;
if ( F_59 ( V_6 -> V_13 ) )
return F_60 ( V_6 -> V_13 ) ;
V_6 -> V_61 = F_61 ( & V_19 -> V_20 , NULL ) ;
if ( F_59 ( V_6 -> V_61 ) )
return F_60 ( V_6 -> V_61 ) ;
F_62 ( V_151 , V_6 -> V_48 . V_134 ) ;
F_62 ( V_152 , V_6 -> V_48 . V_134 ) ;
F_63 ( & V_6 -> V_48 . V_153 ) ;
for ( V_36 = 0 ; V_36 < V_47 ; V_36 ++ ) {
struct V_1 * V_4 = & V_6 -> V_38 [ V_36 ] ;
V_4 -> V_6 = V_6 ;
V_4 -> V_3 . V_154 = & V_6 -> V_48 ;
F_64 ( & V_4 -> V_3 ) ;
F_65 ( & V_4 -> V_52 , F_19 ,
( unsigned long ) V_4 ) ;
F_66 ( & V_4 -> V_3 . V_137 ,
& V_6 -> V_48 . V_153 ) ;
}
V_53 = F_46 ( V_6 ) ;
if ( V_53 )
return V_53 ;
V_6 -> V_19 = V_19 ;
V_6 -> V_48 . V_20 = & V_19 -> V_20 ;
V_6 -> V_48 . V_20 -> V_155 = & V_6 -> V_155 ;
F_67 ( V_6 -> V_48 . V_20 , V_94 ) ;
V_6 -> V_48 . V_156 = F_25 ;
V_6 -> V_48 . V_157 = F_33 ;
V_6 -> V_48 . V_158 = F_42 ;
V_6 -> V_48 . V_159 = F_35 ;
V_6 -> V_48 . V_160 = F_40 ;
V_6 -> V_48 . V_161 = F_41 ;
V_6 -> V_48 . V_162 = F_45 ;
V_53 = F_68 ( & V_6 -> V_48 ) ;
if ( V_53 ) {
F_10 ( V_6 -> V_48 . V_20 , L_9 ) ;
return V_53 ;
}
V_53 = F_69 ( V_138 , F_50 , V_6 ) ;
if ( V_53 ) {
F_10 ( V_6 -> V_48 . V_20 ,
L_10 ) ;
F_70 ( & V_6 -> V_48 ) ;
}
F_71 ( V_6 -> V_48 . V_20 , L_11 ) ;
return 0 ;
}
static int T_7 F_72 ( void )
{
return F_73 ( & V_163 , F_52 ) ;
}
