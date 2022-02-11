static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
int F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
return F_4 ( V_6 ) ;
}
int F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
return ! F_4 ( V_6 ) ;
}
static void F_6 ( struct V_1 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = V_4 -> V_3 . V_7 ;
if ( F_4 ( V_6 ) && F_7 ( V_6 ) )
F_8 ( 1 << ( V_7 + V_8 ) ,
V_6 -> V_9 + V_10 + V_11 ) ;
else
F_8 ( 1 << ( V_7 + V_12 ) ,
V_6 -> V_9 + V_13 + V_11 ) ;
}
static void F_9 ( struct V_1 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = V_4 -> V_3 . V_7 ;
F_8 ( V_4 -> V_14 ,
V_6 -> V_9 + F_10 ( V_6 , V_7 ) ) ;
F_8 ( 1 , V_6 -> V_9 + F_11 ( V_6 , V_7 ) ) ;
}
static void F_12 ( struct V_1 * V_4 )
{
V_4 -> V_15 = V_16 ;
}
static void F_13 ( struct V_1 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = V_4 -> V_3 . V_7 ;
if ( F_4 ( V_6 ) && F_7 ( V_6 ) )
F_8 ( 1 << V_7 ,
V_6 -> V_9 + V_10 + V_11 ) ;
else
F_8 ( 1 << V_7 ,
V_6 -> V_9 + V_13 + V_11 ) ;
V_4 -> V_15 = V_17 ;
}
static void F_14 ( struct V_1 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = V_4 -> V_3 . V_7 ;
if ( F_4 ( V_6 ) && F_7 ( V_6 ) )
F_8 ( 1 << V_7 ,
V_6 -> V_9 + V_10 + V_18 ) ;
else
F_8 ( 1 << V_7 ,
V_6 -> V_9 + V_13 + V_18 ) ;
V_4 -> V_15 = V_19 ;
}
static T_1 F_15 ( struct V_20 * V_21 )
{
return F_16 ( V_21 ) ;
}
static void F_17 ( unsigned long V_22 )
{
struct V_1 * V_4 = (struct V_1 * ) V_22 ;
if ( V_4 -> V_23 . V_24 )
V_4 -> V_23 . V_24 ( V_4 -> V_23 . V_25 ) ;
}
static T_2 F_18 ( int V_26 , void * V_27 )
{
struct V_5 * V_6 = V_27 ;
T_3 V_28 , V_29 ;
V_28 = F_19 ( V_6 -> V_9 + V_30 ) ;
V_28 &= V_31 ;
F_8 ( V_28 , V_6 -> V_9 + V_30 + V_18 ) ;
V_29 = F_19 ( V_6 -> V_9 + V_32 ) ;
F_8 ( V_29 , V_6 -> V_9 + V_32 + V_18 ) ;
V_29 = ( ( V_29 >> V_33 ) & V_29 ) |
( ~ ( V_29 >> V_33 ) & V_29 & ~ V_28 ) ;
V_28 = ( V_29 << V_33 ) | V_28 ;
while ( V_28 ) {
int V_34 = F_20 ( V_28 ) - 1 ;
struct V_1 * V_4 =
& V_6 -> V_35 [ V_34 % V_33 ] ;
if ( V_34 >= V_33 ) {
F_21 ( V_6 -> V_36 . V_37 ,
L_1 , V_38 ,
V_34 - V_33 ) ;
V_4 -> V_15 = V_39 ;
F_6 ( V_4 ) ;
} else {
if ( V_4 -> V_40 & V_41 )
V_4 -> V_15 = V_19 ;
else
V_4 -> V_15 = V_16 ;
}
V_28 &= ~ ( 1 << V_34 ) ;
if ( V_4 -> V_15 == V_16 )
F_22 ( & V_4 -> V_23 ) ;
F_23 ( & V_4 -> V_42 ) ;
}
return V_43 ;
}
static int F_24 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_44 * V_22 = V_3 -> V_45 ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_46 ;
if ( V_22 )
V_4 -> V_47 = V_22 -> V_47 ;
V_4 -> V_48 = F_25 ( V_6 -> V_36 . V_37 ,
V_49 , & V_4 -> V_14 ,
V_50 ) ;
if ( ! V_4 -> V_48 ) {
V_46 = - V_51 ;
goto V_52;
}
memset ( V_4 -> V_48 , 0 , V_49 ) ;
if ( V_4 -> V_47 != V_53 ) {
V_46 = F_26 ( V_4 -> V_47 , F_18 ,
0 , L_2 , V_6 ) ;
if ( V_46 )
goto V_54;
}
V_46 = F_27 ( V_6 -> V_55 ) ;
if ( V_46 )
goto V_56;
F_6 ( V_4 ) ;
F_28 ( & V_4 -> V_23 , V_3 ) ;
V_4 -> V_23 . V_57 = F_15 ;
F_29 ( & V_4 -> V_23 ) ;
return 0 ;
V_56:
F_30 ( V_4 -> V_47 , V_6 ) ;
V_54:
F_31 ( V_6 -> V_36 . V_37 , V_49 ,
V_4 -> V_48 , V_4 -> V_14 ) ;
V_52:
return V_46 ;
}
static void F_32 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
F_12 ( V_4 ) ;
F_30 ( V_4 -> V_47 , V_6 ) ;
F_31 ( V_6 -> V_36 . V_37 , V_49 ,
V_4 -> V_48 , V_4 -> V_14 ) ;
F_33 ( V_6 -> V_55 ) ;
}
static struct V_20 * F_34 (
struct V_2 * V_3 , struct V_58 * V_59 ,
unsigned int V_60 , enum V_61 V_62 ,
unsigned long V_40 , void * V_63 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_64 * V_48 ;
struct V_58 * V_65 ;
T_3 V_66 , V_67 ;
T_3 * V_68 ;
bool V_69 = V_40 & V_70 ;
int V_71 = V_69 ? V_4 -> V_72 : 0 ;
if ( V_4 -> V_15 == V_19 && ! V_69 )
return NULL ;
if ( V_60 + ( V_69 ? V_71 : 0 ) > V_73 ) {
F_35 ( V_6 -> V_36 . V_37 ,
L_3 ,
V_60 , V_73 ) ;
goto V_74;
}
V_4 -> V_15 = V_19 ;
V_4 -> V_40 = 0 ;
if ( V_69 ) {
F_36 ( V_71 < 1 ) ;
V_48 = & V_4 -> V_48 [ V_71 - 1 ] ;
V_48 -> V_75 = V_4 -> V_14 + sizeof( * V_48 ) * V_71 ;
V_48 -> V_76 |= V_77 ;
V_48 -> V_76 &= ~ V_78 ;
V_48 -> V_76 &= ~ V_79 ;
} else {
V_71 = 0 ;
}
if ( V_62 == V_80 ) {
V_48 = & V_4 -> V_48 [ V_71 ++ ] ;
V_68 = ( T_3 * ) V_59 ;
for ( V_67 = 0 ; V_67 < V_60 ; )
V_48 -> V_81 [ V_67 ++ ] = * V_68 ++ ;
V_48 -> V_76 = 0 ;
V_48 -> V_76 |= V_78 ;
V_48 -> V_76 |= V_79 ;
if ( V_40 & V_82 )
V_48 -> V_76 |= V_83 ;
V_48 -> V_76 |= V_84 ;
V_48 -> V_76 |= V_85 ;
V_48 -> V_76 |= F_37 ( V_60 , V_86 ) ;
V_48 -> V_76 |= F_37 ( V_87 , V_88 ) ;
} else {
F_38 (sgl, sg, sg_len, i) {
if ( F_39 ( V_65 ) > V_89 ) {
F_35 ( V_6 -> V_36 . V_37 , L_4 ,
F_39 ( V_65 ) , V_89 ) ;
goto V_74;
}
V_48 = & V_4 -> V_48 [ V_71 ++ ] ;
V_48 -> V_75 = V_4 -> V_14 + sizeof( * V_48 ) * V_71 ;
V_48 -> V_90 = V_65 -> V_91 ;
V_48 -> V_92 = F_39 ( V_65 ) ;
V_48 -> V_76 = 0 ;
V_48 -> V_76 |= V_77 ;
V_48 -> V_76 |= V_84 ;
V_48 -> V_76 |= V_85 ;
V_48 -> V_76 |= F_37 ( V_62 == V_93 ?
V_94 : V_95 ,
V_88 ) ;
if ( V_66 + 1 == V_60 ) {
V_48 -> V_76 &= ~ V_77 ;
V_48 -> V_76 |= V_78 ;
V_48 -> V_76 |= V_79 ;
if ( V_40 & V_82 )
V_48 -> V_76 |= V_83 ;
}
}
}
V_4 -> V_72 = V_71 ;
return & V_4 -> V_23 ;
V_74:
V_4 -> V_15 = V_39 ;
return NULL ;
}
static struct V_20 * F_40 (
struct V_2 * V_3 , T_4 V_96 , T_5 V_97 ,
T_5 V_98 , enum V_61 V_62 ,
unsigned long V_40 , void * V_63 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_3 V_99 = V_97 / V_98 ;
T_3 V_66 = 0 , V_100 = 0 ;
if ( V_4 -> V_15 == V_19 )
return NULL ;
V_4 -> V_15 = V_19 ;
V_4 -> V_40 |= V_41 ;
if ( V_99 > V_73 ) {
F_35 ( V_6 -> V_36 . V_37 ,
L_3 ,
V_99 , V_73 ) ;
goto V_74;
}
if ( V_98 > V_89 ) {
F_35 ( V_6 -> V_36 . V_37 ,
L_5 ,
V_98 , V_89 ) ;
goto V_74;
}
while ( V_100 < V_97 ) {
struct V_64 * V_48 = & V_4 -> V_48 [ V_66 ] ;
if ( V_66 + 1 == V_99 )
V_48 -> V_75 = V_4 -> V_14 ;
else
V_48 -> V_75 = V_4 -> V_14 + sizeof( * V_48 ) * ( V_66 + 1 ) ;
V_48 -> V_90 = V_96 ;
V_48 -> V_92 = V_98 ;
V_48 -> V_76 = 0 ;
V_48 -> V_76 |= V_77 ;
V_48 -> V_76 |= V_78 ;
V_48 -> V_76 |= V_84 ;
V_48 -> V_76 |= V_85 ;
V_48 -> V_76 |= F_37 ( V_62 == V_93 ?
V_94 : V_95 , V_88 ) ;
V_96 += V_98 ;
V_100 += V_98 ;
V_66 ++ ;
}
V_4 -> V_72 = V_66 ;
return & V_4 -> V_23 ;
V_74:
V_4 -> V_15 = V_39 ;
return NULL ;
}
static int F_41 ( struct V_2 * V_3 , enum V_101 V_102 ,
unsigned long V_103 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_46 = 0 ;
switch ( V_102 ) {
case V_104 :
F_6 ( V_4 ) ;
F_12 ( V_4 ) ;
break;
case V_105 :
F_13 ( V_4 ) ;
break;
case V_106 :
F_14 ( V_4 ) ;
break;
default:
V_46 = - V_107 ;
}
return V_46 ;
}
static enum V_108 F_42 ( struct V_2 * V_3 ,
T_1 V_109 , struct V_110 * V_111 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_112 ;
V_112 = V_3 -> V_109 ;
F_43 ( V_111 , V_3 -> V_113 , V_112 , 0 ) ;
return V_4 -> V_15 ;
}
static void F_44 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_9 ( V_4 ) ;
}
static int T_6 F_45 ( struct V_5 * V_6 )
{
int V_46 ;
V_46 = F_27 ( V_6 -> V_55 ) ;
if ( V_46 )
return V_46 ;
V_46 = F_46 ( V_6 -> V_9 ) ;
if ( V_46 )
goto V_74;
if ( F_4 ( V_6 ) ) {
F_8 ( V_114 ,
V_6 -> V_9 + V_10 + V_11 ) ;
F_8 ( V_115 ,
V_6 -> V_9 + V_10 + V_11 ) ;
}
F_8 ( V_31 << V_33 ,
V_6 -> V_9 + V_30 + V_11 ) ;
V_74:
F_33 ( V_6 -> V_55 ) ;
return V_46 ;
}
static bool F_47 ( struct V_2 * V_3 , void * V_116 )
{
struct V_117 * V_118 = V_116 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_47 ;
if ( V_6 -> V_36 . V_37 -> V_119 != V_118 -> V_119 )
return false ;
if ( V_3 -> V_7 != V_118 -> V_7 )
return false ;
V_47 = F_48 ( V_6 -> V_120 , V_118 -> V_7 ) ;
if ( V_47 < 0 )
return false ;
V_4 -> V_47 = V_47 ;
return true ;
}
static struct V_2 * F_49 ( struct V_121 * V_122 ,
struct V_123 * V_124 )
{
struct V_5 * V_6 = V_124 -> V_125 ;
T_7 V_126 = V_6 -> V_36 . V_127 ;
struct V_117 V_118 ;
if ( V_122 -> V_128 != 1 )
return NULL ;
V_118 . V_119 = V_124 -> V_119 ;
V_118 . V_7 = V_122 -> args [ 0 ] ;
if ( V_118 . V_7 >= V_6 -> V_129 )
return NULL ;
return F_50 ( V_126 , F_47 , & V_118 ) ;
}
static int T_6 F_51 ( struct V_130 * V_120 )
{
struct V_131 * V_132 = V_120 -> V_37 . V_119 ;
const struct V_133 * V_134 ;
const struct V_135 * V_136 ;
const struct V_137 * V_138 ;
struct V_5 * V_6 ;
struct V_139 * V_140 ;
int V_46 , V_66 ;
V_6 = F_52 ( & V_120 -> V_37 , sizeof( * V_6 ) , V_50 ) ;
if ( ! V_6 )
return - V_51 ;
V_46 = F_53 ( V_132 , L_6 , & V_6 -> V_129 ) ;
if ( V_46 ) {
F_35 ( & V_120 -> V_37 , L_7 ) ;
return V_46 ;
}
V_136 = F_54 ( V_141 , & V_120 -> V_37 ) ;
if ( V_136 )
V_134 = V_136 -> V_22 ;
else
V_134 = F_55 ( V_120 ) ;
V_138 = (struct V_137 * ) V_134 -> V_142 ;
V_6 -> type = V_138 -> type ;
V_6 -> V_27 = V_138 -> V_143 ;
V_140 = F_56 ( V_120 , V_144 , 0 ) ;
V_6 -> V_9 = F_57 ( & V_120 -> V_37 , V_140 ) ;
if ( F_58 ( V_6 -> V_9 ) )
return F_59 ( V_6 -> V_9 ) ;
V_6 -> V_55 = F_60 ( & V_120 -> V_37 , NULL ) ;
if ( F_58 ( V_6 -> V_55 ) )
return F_59 ( V_6 -> V_55 ) ;
F_61 ( V_145 , V_6 -> V_36 . V_127 ) ;
F_61 ( V_146 , V_6 -> V_36 . V_127 ) ;
F_62 ( & V_6 -> V_36 . V_147 ) ;
for ( V_66 = 0 ; V_66 < V_33 ; V_66 ++ ) {
struct V_1 * V_4 = & V_6 -> V_35 [ V_66 ] ;
V_4 -> V_6 = V_6 ;
V_4 -> V_3 . V_148 = & V_6 -> V_36 ;
F_63 ( & V_4 -> V_3 ) ;
F_64 ( & V_4 -> V_42 , F_17 ,
( unsigned long ) V_4 ) ;
F_65 ( & V_4 -> V_3 . V_131 ,
& V_6 -> V_36 . V_147 ) ;
}
V_46 = F_45 ( V_6 ) ;
if ( V_46 )
return V_46 ;
V_6 -> V_120 = V_120 ;
V_6 -> V_36 . V_37 = & V_120 -> V_37 ;
V_6 -> V_36 . V_37 -> V_149 = & V_6 -> V_149 ;
F_66 ( V_6 -> V_36 . V_37 , V_89 ) ;
V_6 -> V_36 . V_150 = F_24 ;
V_6 -> V_36 . V_151 = F_32 ;
V_6 -> V_36 . V_152 = F_42 ;
V_6 -> V_36 . V_153 = F_34 ;
V_6 -> V_36 . V_154 = F_40 ;
V_6 -> V_36 . V_155 = F_41 ;
V_6 -> V_36 . V_156 = F_44 ;
V_46 = F_67 ( & V_6 -> V_36 ) ;
if ( V_46 ) {
F_35 ( V_6 -> V_36 . V_37 , L_8 ) ;
return V_46 ;
}
V_46 = F_68 ( V_132 , F_49 , V_6 ) ;
if ( V_46 ) {
F_35 ( V_6 -> V_36 . V_37 ,
L_9 ) ;
F_69 ( & V_6 -> V_36 ) ;
}
F_70 ( V_6 -> V_36 . V_37 , L_10 ) ;
return 0 ;
}
static int T_6 F_71 ( void )
{
return F_72 ( & V_157 , F_51 ) ;
}
