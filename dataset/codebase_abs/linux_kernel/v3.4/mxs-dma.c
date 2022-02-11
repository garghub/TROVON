static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 = V_2 -> V_6 . V_5 ;
if ( F_2 () && F_3 () )
F_4 ( 1 << ( V_5 + V_7 ) ,
V_4 -> V_8 + V_9 + V_10 ) ;
else
F_4 ( 1 << ( V_5 + V_11 ) ,
V_4 -> V_8 + V_12 + V_10 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 = V_2 -> V_6 . V_5 ;
F_4 ( V_2 -> V_13 ,
V_4 -> V_8 + F_6 ( V_5 ) ) ;
F_4 ( 1 , V_4 -> V_8 + F_7 ( V_5 ) ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
V_2 -> V_14 = V_15 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 = V_2 -> V_6 . V_5 ;
if ( F_2 () && F_3 () )
F_4 ( 1 << V_5 ,
V_4 -> V_8 + V_9 + V_10 ) ;
else
F_4 ( 1 << V_5 ,
V_4 -> V_8 + V_12 + V_10 ) ;
V_2 -> V_14 = V_16 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 = V_2 -> V_6 . V_5 ;
if ( F_2 () && F_3 () )
F_4 ( 1 << V_5 ,
V_4 -> V_8 + V_9 + V_17 ) ;
else
F_4 ( 1 << V_5 ,
V_4 -> V_8 + V_12 + V_17 ) ;
V_2 -> V_14 = V_18 ;
}
static struct V_1 * F_11 ( struct V_19 * V_6 )
{
return F_12 ( V_6 , struct V_1 , V_6 ) ;
}
static T_1 F_13 ( struct V_20 * V_21 )
{
return F_14 ( V_21 ) ;
}
static void F_15 ( unsigned long V_22 )
{
struct V_1 * V_2 = (struct V_1 * ) V_22 ;
if ( V_2 -> V_23 . V_24 )
V_2 -> V_23 . V_24 ( V_2 -> V_23 . V_25 ) ;
}
static T_2 F_16 ( int V_26 , void * V_27 )
{
struct V_3 * V_4 = V_27 ;
T_3 V_28 , V_29 ;
V_28 = F_17 ( V_4 -> V_8 + V_30 ) ;
V_28 &= V_31 ;
F_4 ( V_28 , V_4 -> V_8 + V_30 + V_17 ) ;
V_29 = F_17 ( V_4 -> V_8 + V_32 ) ;
F_4 ( V_29 , V_4 -> V_8 + V_32 + V_17 ) ;
V_29 = ( ( V_29 >> V_33 ) & V_29 ) |
( ~ ( V_29 >> V_33 ) & V_29 & ~ V_28 ) ;
V_28 = ( V_29 << V_33 ) | V_28 ;
while ( V_28 ) {
int V_34 = F_18 ( V_28 ) - 1 ;
struct V_1 * V_2 =
& V_4 -> V_35 [ V_34 % V_33 ] ;
if ( V_34 >= V_33 ) {
F_19 ( V_4 -> V_36 . V_37 ,
L_1 , V_38 ,
V_34 - V_33 ) ;
V_2 -> V_14 = V_39 ;
F_1 ( V_2 ) ;
} else {
if ( V_2 -> V_40 & V_41 )
V_2 -> V_14 = V_18 ;
else
V_2 -> V_14 = V_15 ;
}
V_28 &= ~ ( 1 << V_34 ) ;
if ( V_2 -> V_14 == V_15 )
F_20 ( & V_2 -> V_23 ) ;
F_21 ( & V_2 -> V_42 ) ;
}
return V_43 ;
}
static int F_22 ( struct V_19 * V_6 )
{
struct V_1 * V_2 = F_11 ( V_6 ) ;
struct V_44 * V_22 = V_6 -> V_45 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_46 ;
if ( ! V_22 )
return - V_47 ;
V_2 -> V_48 = V_22 -> V_48 ;
V_2 -> V_49 = F_23 ( V_4 -> V_36 . V_37 , V_50 ,
& V_2 -> V_13 , V_51 ) ;
if ( ! V_2 -> V_49 ) {
V_46 = - V_52 ;
goto V_53;
}
memset ( V_2 -> V_49 , 0 , V_50 ) ;
if ( V_2 -> V_48 != V_54 ) {
V_46 = F_24 ( V_2 -> V_48 , F_16 ,
0 , L_2 , V_4 ) ;
if ( V_46 )
goto V_55;
}
V_46 = F_25 ( V_4 -> V_56 ) ;
if ( V_46 )
goto V_57;
F_1 ( V_2 ) ;
F_26 ( & V_2 -> V_23 , V_6 ) ;
V_2 -> V_23 . V_58 = F_13 ;
F_27 ( & V_2 -> V_23 ) ;
return 0 ;
V_57:
F_28 ( V_2 -> V_48 , V_4 ) ;
V_55:
F_29 ( V_4 -> V_36 . V_37 , V_50 ,
V_2 -> V_49 , V_2 -> V_13 ) ;
V_53:
return V_46 ;
}
static void F_30 ( struct V_19 * V_6 )
{
struct V_1 * V_2 = F_11 ( V_6 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_8 ( V_2 ) ;
F_28 ( V_2 -> V_48 , V_4 ) ;
F_29 ( V_4 -> V_36 . V_37 , V_50 ,
V_2 -> V_49 , V_2 -> V_13 ) ;
F_31 ( V_4 -> V_56 ) ;
}
static struct V_20 * F_32 (
struct V_19 * V_6 , struct V_59 * V_60 ,
unsigned int V_61 , enum V_62 V_63 ,
unsigned long V_40 , void * V_64 )
{
struct V_1 * V_2 = F_11 ( V_6 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_65 * V_49 ;
struct V_59 * V_66 ;
int V_67 , V_68 ;
T_3 * V_69 ;
bool V_70 = V_40 & V_71 ;
int V_72 = V_70 ? V_2 -> V_73 : 0 ;
if ( V_2 -> V_14 == V_18 && ! V_70 )
return NULL ;
if ( V_61 + ( V_70 ? V_72 : 0 ) > V_74 ) {
F_33 ( V_4 -> V_36 . V_37 ,
L_3 ,
V_61 , V_74 ) ;
goto V_75;
}
V_2 -> V_14 = V_18 ;
V_2 -> V_40 = 0 ;
if ( V_70 ) {
F_34 ( V_72 < 1 ) ;
V_49 = & V_2 -> V_49 [ V_72 - 1 ] ;
V_49 -> V_76 = V_2 -> V_13 + sizeof( * V_49 ) * V_72 ;
V_49 -> V_77 |= V_78 ;
V_49 -> V_77 &= ~ V_79 ;
V_49 -> V_77 &= ~ V_80 ;
} else {
V_72 = 0 ;
}
if ( V_63 == V_81 ) {
V_49 = & V_2 -> V_49 [ V_72 ++ ] ;
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
V_49 -> V_77 |= F_35 ( V_61 , V_87 ) ;
V_49 -> V_77 |= F_35 ( V_88 , V_89 ) ;
} else {
F_36 (sgl, sg, sg_len, i) {
if ( V_66 -> V_90 > V_91 ) {
F_33 ( V_4 -> V_36 . V_37 , L_4 ,
V_66 -> V_90 , V_91 ) ;
goto V_75;
}
V_49 = & V_2 -> V_49 [ V_72 ++ ] ;
V_49 -> V_76 = V_2 -> V_13 + sizeof( * V_49 ) * V_72 ;
V_49 -> V_92 = V_66 -> V_93 ;
V_49 -> V_94 = V_66 -> V_90 ;
V_49 -> V_77 = 0 ;
V_49 -> V_77 |= V_78 ;
V_49 -> V_77 |= V_85 ;
V_49 -> V_77 |= V_86 ;
V_49 -> V_77 |= F_35 ( V_63 == V_95 ?
V_96 : V_97 ,
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
V_2 -> V_73 = V_72 ;
return & V_2 -> V_23 ;
V_75:
V_2 -> V_14 = V_39 ;
return NULL ;
}
static struct V_20 * F_37 (
struct V_19 * V_6 , T_4 V_98 , T_5 V_99 ,
T_5 V_100 , enum V_62 V_63 ,
void * V_64 )
{
struct V_1 * V_2 = F_11 ( V_6 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_101 = V_99 / V_100 ;
int V_67 = 0 , V_102 = 0 ;
if ( V_2 -> V_14 == V_18 )
return NULL ;
V_2 -> V_14 = V_18 ;
V_2 -> V_40 |= V_41 ;
if ( V_101 > V_74 ) {
F_33 ( V_4 -> V_36 . V_37 ,
L_3 ,
V_101 , V_74 ) ;
goto V_75;
}
if ( V_100 > V_91 ) {
F_33 ( V_4 -> V_36 . V_37 ,
L_5 ,
V_100 , V_91 ) ;
goto V_75;
}
while ( V_102 < V_99 ) {
struct V_65 * V_49 = & V_2 -> V_49 [ V_67 ] ;
if ( V_67 + 1 == V_101 )
V_49 -> V_76 = V_2 -> V_13 ;
else
V_49 -> V_76 = V_2 -> V_13 + sizeof( * V_49 ) * ( V_67 + 1 ) ;
V_49 -> V_92 = V_98 ;
V_49 -> V_94 = V_100 ;
V_49 -> V_77 = 0 ;
V_49 -> V_77 |= V_78 ;
V_49 -> V_77 |= V_79 ;
V_49 -> V_77 |= V_85 ;
V_49 -> V_77 |= V_86 ;
V_49 -> V_77 |= F_35 ( V_63 == V_95 ?
V_96 : V_97 , V_89 ) ;
V_98 += V_100 ;
V_102 += V_100 ;
V_67 ++ ;
}
V_2 -> V_73 = V_67 ;
return & V_2 -> V_23 ;
V_75:
V_2 -> V_14 = V_39 ;
return NULL ;
}
static int F_38 ( struct V_19 * V_6 , enum V_103 V_104 ,
unsigned long V_105 )
{
struct V_1 * V_2 = F_11 ( V_6 ) ;
int V_46 = 0 ;
switch ( V_104 ) {
case V_106 :
F_1 ( V_2 ) ;
F_8 ( V_2 ) ;
break;
case V_107 :
F_9 ( V_2 ) ;
break;
case V_108 :
F_10 ( V_2 ) ;
break;
default:
V_46 = - V_109 ;
}
return V_46 ;
}
static enum V_110 F_39 ( struct V_19 * V_6 ,
T_1 V_111 , struct V_112 * V_113 )
{
struct V_1 * V_2 = F_11 ( V_6 ) ;
T_1 V_114 ;
V_114 = V_6 -> V_111 ;
F_40 ( V_113 , V_6 -> V_115 , V_114 , 0 ) ;
return V_2 -> V_14 ;
}
static void F_41 ( struct V_19 * V_6 )
{
struct V_1 * V_2 = F_11 ( V_6 ) ;
F_5 ( V_2 ) ;
}
static int T_6 F_42 ( struct V_3 * V_4 )
{
int V_46 ;
V_46 = F_25 ( V_4 -> V_56 ) ;
if ( V_46 )
return V_46 ;
V_46 = F_43 ( V_4 -> V_8 ) ;
if ( V_46 )
goto V_75;
V_4 -> V_116 = F_17 ( V_4 -> V_8 +
( ( V_4 -> V_27 == V_117 ) ?
V_118 : V_119 ) ) >>
V_120 ;
if ( F_2 () ) {
F_4 ( V_121 ,
V_4 -> V_8 + V_9 + V_10 ) ;
F_4 ( V_122 ,
V_4 -> V_8 + V_9 + V_10 ) ;
}
F_4 ( V_31 << V_33 ,
V_4 -> V_8 + V_30 + V_10 ) ;
V_75:
F_31 ( V_4 -> V_56 ) ;
return V_46 ;
}
static int T_6 F_44 ( struct V_123 * V_124 )
{
const struct V_125 * V_126 =
F_45 ( V_124 ) ;
struct V_3 * V_4 ;
struct V_127 * V_128 ;
int V_46 , V_67 ;
V_4 = F_46 ( sizeof( * V_4 ) , V_51 ) ;
if ( ! V_4 )
return - V_52 ;
V_4 -> V_27 = V_126 -> V_129 ;
V_128 = F_47 ( V_124 , V_130 , 0 ) ;
if ( ! F_48 ( V_128 -> V_131 , F_49 ( V_128 ) ,
V_124 -> V_132 ) ) {
V_46 = - V_133 ;
goto V_134;
}
V_4 -> V_8 = F_50 ( V_128 -> V_131 , F_49 ( V_128 ) ) ;
if ( ! V_4 -> V_8 ) {
V_46 = - V_52 ;
goto V_135;
}
V_4 -> V_56 = F_51 ( & V_124 -> V_37 , NULL ) ;
if ( F_52 ( V_4 -> V_56 ) ) {
V_46 = F_53 ( V_4 -> V_56 ) ;
goto V_57;
}
F_54 ( V_136 , V_4 -> V_36 . V_137 ) ;
F_54 ( V_138 , V_4 -> V_36 . V_137 ) ;
F_55 ( & V_4 -> V_36 . V_139 ) ;
for ( V_67 = 0 ; V_67 < V_33 ; V_67 ++ ) {
struct V_1 * V_2 = & V_4 -> V_35 [ V_67 ] ;
V_2 -> V_4 = V_4 ;
V_2 -> V_6 . V_140 = & V_4 -> V_36 ;
F_56 ( & V_2 -> V_6 ) ;
F_57 ( & V_2 -> V_42 , F_15 ,
( unsigned long ) V_2 ) ;
F_58 ( & V_2 -> V_6 . V_141 ,
& V_4 -> V_36 . V_139 ) ;
}
V_46 = F_42 ( V_4 ) ;
if ( V_46 )
goto V_142;
V_4 -> V_36 . V_37 = & V_124 -> V_37 ;
V_4 -> V_36 . V_37 -> V_143 = & V_4 -> V_143 ;
F_59 ( V_4 -> V_36 . V_37 , V_91 ) ;
V_4 -> V_36 . V_144 = F_22 ;
V_4 -> V_36 . V_145 = F_30 ;
V_4 -> V_36 . V_146 = F_39 ;
V_4 -> V_36 . V_147 = F_32 ;
V_4 -> V_36 . V_148 = F_37 ;
V_4 -> V_36 . V_149 = F_38 ;
V_4 -> V_36 . V_150 = F_41 ;
V_46 = F_60 ( & V_4 -> V_36 ) ;
if ( V_46 ) {
F_33 ( V_4 -> V_36 . V_37 , L_6 ) ;
goto V_142;
}
F_61 ( V_4 -> V_36 . V_37 , L_7 ) ;
return 0 ;
V_142:
F_62 ( V_4 -> V_56 ) ;
V_57:
F_63 ( V_4 -> V_8 ) ;
V_135:
F_64 ( V_128 -> V_131 , F_49 ( V_128 ) ) ;
V_134:
F_65 ( V_4 ) ;
return V_46 ;
}
static int T_6 F_66 ( void )
{
return F_67 ( & V_151 , F_44 ) ;
}
