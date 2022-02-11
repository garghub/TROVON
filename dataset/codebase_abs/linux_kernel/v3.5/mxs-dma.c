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
if ( ! V_22 )
return - V_47 ;
V_4 -> V_48 = V_22 -> V_48 ;
V_4 -> V_49 = F_25 ( V_6 -> V_36 . V_37 , V_50 ,
& V_4 -> V_14 , V_51 ) ;
if ( ! V_4 -> V_49 ) {
V_46 = - V_52 ;
goto V_53;
}
memset ( V_4 -> V_49 , 0 , V_50 ) ;
if ( V_4 -> V_48 != V_54 ) {
V_46 = F_26 ( V_4 -> V_48 , F_18 ,
0 , L_2 , V_6 ) ;
if ( V_46 )
goto V_55;
}
V_46 = F_27 ( V_6 -> V_56 ) ;
if ( V_46 )
goto V_57;
F_6 ( V_4 ) ;
F_28 ( & V_4 -> V_23 , V_3 ) ;
V_4 -> V_23 . V_58 = F_15 ;
F_29 ( & V_4 -> V_23 ) ;
return 0 ;
V_57:
F_30 ( V_4 -> V_48 , V_6 ) ;
V_55:
F_31 ( V_6 -> V_36 . V_37 , V_50 ,
V_4 -> V_49 , V_4 -> V_14 ) ;
V_53:
return V_46 ;
}
static void F_32 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
F_12 ( V_4 ) ;
F_30 ( V_4 -> V_48 , V_6 ) ;
F_31 ( V_6 -> V_36 . V_37 , V_50 ,
V_4 -> V_49 , V_4 -> V_14 ) ;
F_33 ( V_6 -> V_56 ) ;
}
static struct V_20 * F_34 (
struct V_2 * V_3 , struct V_59 * V_60 ,
unsigned int V_61 , enum V_62 V_63 ,
unsigned long V_40 , void * V_64 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_65 * V_49 ;
struct V_59 * V_66 ;
int V_67 , V_68 ;
T_3 * V_69 ;
bool V_70 = V_40 & V_71 ;
int V_72 = V_70 ? V_4 -> V_73 : 0 ;
if ( V_4 -> V_15 == V_19 && ! V_70 )
return NULL ;
if ( V_61 + ( V_70 ? V_72 : 0 ) > V_74 ) {
F_35 ( V_6 -> V_36 . V_37 ,
L_3 ,
V_61 , V_74 ) ;
goto V_75;
}
V_4 -> V_15 = V_19 ;
V_4 -> V_40 = 0 ;
if ( V_70 ) {
F_36 ( V_72 < 1 ) ;
V_49 = & V_4 -> V_49 [ V_72 - 1 ] ;
V_49 -> V_76 = V_4 -> V_14 + sizeof( * V_49 ) * V_72 ;
V_49 -> V_77 |= V_78 ;
V_49 -> V_77 &= ~ V_79 ;
V_49 -> V_77 &= ~ V_80 ;
} else {
V_72 = 0 ;
}
if ( V_63 == V_81 ) {
V_49 = & V_4 -> V_49 [ V_72 ++ ] ;
V_69 = ( T_3 * ) V_60 ;
for ( V_68 = 0 ; V_68 < V_61 ; )
V_49 -> V_82 [ V_68 ++ ] = * V_69 ++ ;
V_49 -> V_77 = 0 ;
V_49 -> V_77 |= V_79 ;
V_49 -> V_77 |= V_80 ;
if ( V_40 & V_83 )
V_49 -> V_77 |= V_84 ;
V_49 -> V_77 |= V_85 ;
V_49 -> V_77 |= V_86 ;
V_49 -> V_77 |= F_37 ( V_61 , V_87 ) ;
V_49 -> V_77 |= F_37 ( V_88 , V_89 ) ;
} else {
F_38 (sgl, sg, sg_len, i) {
if ( F_39 ( V_66 ) > V_90 ) {
F_35 ( V_6 -> V_36 . V_37 , L_4 ,
F_39 ( V_66 ) , V_90 ) ;
goto V_75;
}
V_49 = & V_4 -> V_49 [ V_72 ++ ] ;
V_49 -> V_76 = V_4 -> V_14 + sizeof( * V_49 ) * V_72 ;
V_49 -> V_91 = V_66 -> V_92 ;
V_49 -> V_93 = F_39 ( V_66 ) ;
V_49 -> V_77 = 0 ;
V_49 -> V_77 |= V_78 ;
V_49 -> V_77 |= V_85 ;
V_49 -> V_77 |= V_86 ;
V_49 -> V_77 |= F_37 ( V_63 == V_94 ?
V_95 : V_96 ,
V_89 ) ;
if ( V_67 + 1 == V_61 ) {
V_49 -> V_77 &= ~ V_78 ;
V_49 -> V_77 |= V_79 ;
V_49 -> V_77 |= V_80 ;
if ( V_40 & V_83 )
V_49 -> V_77 |= V_84 ;
}
}
}
V_4 -> V_73 = V_72 ;
return & V_4 -> V_23 ;
V_75:
V_4 -> V_15 = V_39 ;
return NULL ;
}
static struct V_20 * F_40 (
struct V_2 * V_3 , T_4 V_97 , T_5 V_98 ,
T_5 V_99 , enum V_62 V_63 ,
void * V_64 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_100 = V_98 / V_99 ;
int V_67 = 0 , V_101 = 0 ;
if ( V_4 -> V_15 == V_19 )
return NULL ;
V_4 -> V_15 = V_19 ;
V_4 -> V_40 |= V_41 ;
if ( V_100 > V_74 ) {
F_35 ( V_6 -> V_36 . V_37 ,
L_3 ,
V_100 , V_74 ) ;
goto V_75;
}
if ( V_99 > V_90 ) {
F_35 ( V_6 -> V_36 . V_37 ,
L_5 ,
V_99 , V_90 ) ;
goto V_75;
}
while ( V_101 < V_98 ) {
struct V_65 * V_49 = & V_4 -> V_49 [ V_67 ] ;
if ( V_67 + 1 == V_100 )
V_49 -> V_76 = V_4 -> V_14 ;
else
V_49 -> V_76 = V_4 -> V_14 + sizeof( * V_49 ) * ( V_67 + 1 ) ;
V_49 -> V_91 = V_97 ;
V_49 -> V_93 = V_99 ;
V_49 -> V_77 = 0 ;
V_49 -> V_77 |= V_78 ;
V_49 -> V_77 |= V_79 ;
V_49 -> V_77 |= V_85 ;
V_49 -> V_77 |= V_86 ;
V_49 -> V_77 |= F_37 ( V_63 == V_94 ?
V_95 : V_96 , V_89 ) ;
V_97 += V_99 ;
V_101 += V_99 ;
V_67 ++ ;
}
V_4 -> V_73 = V_67 ;
return & V_4 -> V_23 ;
V_75:
V_4 -> V_15 = V_39 ;
return NULL ;
}
static int F_41 ( struct V_2 * V_3 , enum V_102 V_103 ,
unsigned long V_104 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_46 = 0 ;
switch ( V_103 ) {
case V_105 :
F_6 ( V_4 ) ;
F_12 ( V_4 ) ;
break;
case V_106 :
F_13 ( V_4 ) ;
break;
case V_107 :
F_14 ( V_4 ) ;
break;
default:
V_46 = - V_108 ;
}
return V_46 ;
}
static enum V_109 F_42 ( struct V_2 * V_3 ,
T_1 V_110 , struct V_111 * V_112 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_113 ;
V_113 = V_3 -> V_110 ;
F_43 ( V_112 , V_3 -> V_114 , V_113 , 0 ) ;
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
V_46 = F_27 ( V_6 -> V_56 ) ;
if ( V_46 )
return V_46 ;
V_46 = F_46 ( V_6 -> V_9 ) ;
if ( V_46 )
goto V_75;
if ( F_4 ( V_6 ) ) {
F_8 ( V_115 ,
V_6 -> V_9 + V_10 + V_11 ) ;
F_8 ( V_116 ,
V_6 -> V_9 + V_10 + V_11 ) ;
}
F_8 ( V_31 << V_33 ,
V_6 -> V_9 + V_30 + V_11 ) ;
V_75:
F_33 ( V_6 -> V_56 ) ;
return V_46 ;
}
static int T_6 F_47 ( struct V_117 * V_118 )
{
const struct V_119 * V_120 ;
const struct V_121 * V_122 ;
const struct V_123 * V_124 ;
struct V_5 * V_6 ;
struct V_125 * V_126 ;
int V_46 , V_67 ;
V_6 = F_48 ( sizeof( * V_6 ) , V_51 ) ;
if ( ! V_6 )
return - V_52 ;
V_122 = F_49 ( V_127 , & V_118 -> V_37 ) ;
if ( V_122 )
V_120 = V_122 -> V_22 ;
else
V_120 = F_50 ( V_118 ) ;
V_124 = (struct V_123 * ) V_120 -> V_128 ;
V_6 -> type = V_124 -> type ;
V_6 -> V_27 = V_124 -> V_129 ;
V_126 = F_51 ( V_118 , V_130 , 0 ) ;
if ( ! F_52 ( V_126 -> V_131 , F_53 ( V_126 ) ,
V_118 -> V_132 ) ) {
V_46 = - V_133 ;
goto V_134;
}
V_6 -> V_9 = F_54 ( V_126 -> V_131 , F_53 ( V_126 ) ) ;
if ( ! V_6 -> V_9 ) {
V_46 = - V_52 ;
goto V_135;
}
V_6 -> V_56 = F_55 ( & V_118 -> V_37 , NULL ) ;
if ( F_56 ( V_6 -> V_56 ) ) {
V_46 = F_57 ( V_6 -> V_56 ) ;
goto V_57;
}
F_58 ( V_136 , V_6 -> V_36 . V_137 ) ;
F_58 ( V_138 , V_6 -> V_36 . V_137 ) ;
F_59 ( & V_6 -> V_36 . V_139 ) ;
for ( V_67 = 0 ; V_67 < V_33 ; V_67 ++ ) {
struct V_1 * V_4 = & V_6 -> V_35 [ V_67 ] ;
V_4 -> V_6 = V_6 ;
V_4 -> V_3 . V_140 = & V_6 -> V_36 ;
F_60 ( & V_4 -> V_3 ) ;
F_61 ( & V_4 -> V_42 , F_17 ,
( unsigned long ) V_4 ) ;
F_62 ( & V_4 -> V_3 . V_141 ,
& V_6 -> V_36 . V_139 ) ;
}
V_46 = F_45 ( V_6 ) ;
if ( V_46 )
goto V_142;
V_6 -> V_36 . V_37 = & V_118 -> V_37 ;
V_6 -> V_36 . V_37 -> V_143 = & V_6 -> V_143 ;
F_63 ( V_6 -> V_36 . V_37 , V_90 ) ;
V_6 -> V_36 . V_144 = F_24 ;
V_6 -> V_36 . V_145 = F_32 ;
V_6 -> V_36 . V_146 = F_42 ;
V_6 -> V_36 . V_147 = F_34 ;
V_6 -> V_36 . V_148 = F_40 ;
V_6 -> V_36 . V_149 = F_41 ;
V_6 -> V_36 . V_150 = F_44 ;
V_46 = F_64 ( & V_6 -> V_36 ) ;
if ( V_46 ) {
F_35 ( V_6 -> V_36 . V_37 , L_6 ) ;
goto V_142;
}
F_65 ( V_6 -> V_36 . V_37 , L_7 ) ;
return 0 ;
V_142:
F_66 ( V_6 -> V_56 ) ;
V_57:
F_67 ( V_6 -> V_9 ) ;
V_135:
F_68 ( V_126 -> V_131 , F_53 ( V_126 ) ) ;
V_134:
F_69 ( V_6 ) ;
return V_46 ;
}
static int T_6 F_70 ( void )
{
return F_71 ( & V_151 , F_47 ) ;
}
