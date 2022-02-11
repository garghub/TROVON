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
if ( F_2 () ) {
if ( F_3 () )
F_4 ( 1 << ( V_5 + V_14 ) ,
V_4 -> V_8 + V_9 + V_15 ) ;
else
F_4 ( 1 << V_5 ,
V_4 -> V_8 + V_9 + V_15 ) ;
}
F_4 ( 1 , V_4 -> V_8 + F_7 ( V_5 ) ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 = V_2 -> V_6 . V_5 ;
if ( F_2 () ) {
if ( F_3 () )
F_4 ( 1 << ( V_5 + V_14 ) ,
V_4 -> V_8 + V_9 + V_10 ) ;
else
F_4 ( 1 << V_5 ,
V_4 -> V_8 + V_9 + V_10 ) ;
}
V_2 -> V_16 = V_17 ;
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
V_2 -> V_16 = V_18 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 = V_2 -> V_6 . V_5 ;
if ( F_2 () && F_3 () )
F_4 ( 1 << V_5 ,
V_4 -> V_8 + V_9 + V_15 ) ;
else
F_4 ( 1 << V_5 ,
V_4 -> V_8 + V_12 + V_15 ) ;
V_2 -> V_16 = V_19 ;
}
static T_1 F_11 ( struct V_1 * V_2 )
{
T_1 V_20 = V_2 -> V_6 . V_20 ;
if ( ++ V_20 < 0 )
V_20 = 1 ;
V_2 -> V_6 . V_20 = V_20 ;
V_2 -> V_21 . V_20 = V_20 ;
return V_20 ;
}
static struct V_1 * F_12 ( struct V_22 * V_6 )
{
return F_13 ( V_6 , struct V_1 , V_6 ) ;
}
static T_1 F_14 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_12 ( V_24 -> V_6 ) ;
F_5 ( V_2 ) ;
return F_11 ( V_2 ) ;
}
static void F_15 ( unsigned long V_25 )
{
struct V_1 * V_2 = (struct V_1 * ) V_25 ;
if ( V_2 -> V_21 . V_26 )
V_2 -> V_21 . V_26 ( V_2 -> V_21 . V_27 ) ;
}
static T_2 F_16 ( int V_28 , void * V_29 )
{
struct V_3 * V_4 = V_29 ;
T_3 V_30 , V_31 ;
V_30 = F_17 ( V_4 -> V_8 + V_32 ) ;
V_30 &= V_33 ;
F_4 ( V_30 , V_4 -> V_8 + V_32 + V_15 ) ;
V_31 = F_17 ( V_4 -> V_8 + V_34 ) ;
F_4 ( V_31 , V_4 -> V_8 + V_34 + V_15 ) ;
V_31 = ( ( V_31 >> V_35 ) & V_31 ) |
( ~ ( V_31 >> V_35 ) & V_31 & ~ V_30 ) ;
V_30 = ( V_31 << V_35 ) | V_30 ;
while ( V_30 ) {
int V_36 = F_18 ( V_30 ) - 1 ;
struct V_1 * V_2 =
& V_4 -> V_37 [ V_36 % V_35 ] ;
if ( V_36 >= V_35 ) {
F_19 ( V_4 -> V_38 . V_39 ,
L_1 , V_40 ,
V_36 - V_35 ) ;
V_2 -> V_16 = V_41 ;
F_1 ( V_2 ) ;
} else {
if ( V_2 -> V_42 & V_43 )
V_2 -> V_16 = V_19 ;
else
V_2 -> V_16 = V_17 ;
}
V_30 &= ~ ( 1 << V_36 ) ;
if ( V_2 -> V_16 == V_17 )
V_2 -> V_44 = V_2 -> V_21 . V_20 ;
F_20 ( & V_2 -> V_45 ) ;
}
return V_46 ;
}
static int F_21 ( struct V_22 * V_6 )
{
struct V_1 * V_2 = F_12 ( V_6 ) ;
struct V_47 * V_25 = V_6 -> V_48 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_49 ;
if ( ! V_25 )
return - V_50 ;
V_2 -> V_51 = V_25 -> V_51 ;
V_2 -> V_52 = F_22 ( V_4 -> V_38 . V_39 , V_53 ,
& V_2 -> V_13 , V_54 ) ;
if ( ! V_2 -> V_52 ) {
V_49 = - V_55 ;
goto V_56;
}
memset ( V_2 -> V_52 , 0 , V_53 ) ;
V_49 = F_23 ( V_2 -> V_51 , F_16 ,
0 , L_2 , V_4 ) ;
if ( V_49 )
goto V_57;
V_49 = F_24 ( V_4 -> V_58 ) ;
if ( V_49 )
goto V_59;
F_1 ( V_2 ) ;
F_25 ( & V_2 -> V_21 , V_6 ) ;
V_2 -> V_21 . V_60 = F_14 ;
F_26 ( & V_2 -> V_21 ) ;
return 0 ;
V_59:
F_27 ( V_2 -> V_51 , V_4 ) ;
V_57:
F_28 ( V_4 -> V_38 . V_39 , V_53 ,
V_2 -> V_52 , V_2 -> V_13 ) ;
V_56:
return V_49 ;
}
static void F_29 ( struct V_22 * V_6 )
{
struct V_1 * V_2 = F_12 ( V_6 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_8 ( V_2 ) ;
F_27 ( V_2 -> V_51 , V_4 ) ;
F_28 ( V_4 -> V_38 . V_39 , V_53 ,
V_2 -> V_52 , V_2 -> V_13 ) ;
F_30 ( V_4 -> V_58 ) ;
}
static struct V_23 * F_31 (
struct V_22 * V_6 , struct V_61 * V_62 ,
unsigned int V_63 , enum V_64 V_65 ,
unsigned long V_66 )
{
struct V_1 * V_2 = F_12 ( V_6 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_67 * V_52 ;
struct V_61 * V_68 ;
int V_69 , V_70 ;
T_3 * V_71 ;
static int V_72 ;
if ( V_2 -> V_16 == V_19 && ! V_66 )
return NULL ;
if ( V_63 + ( V_66 ? V_72 : 0 ) > V_73 ) {
F_32 ( V_4 -> V_38 . V_39 ,
L_3 ,
V_63 , V_73 ) ;
goto V_74;
}
V_2 -> V_16 = V_19 ;
V_2 -> V_42 = 0 ;
if ( V_66 ) {
F_33 ( V_72 < 1 ) ;
V_52 = & V_2 -> V_52 [ V_72 - 1 ] ;
V_52 -> V_75 = V_2 -> V_13 + sizeof( * V_52 ) * V_72 ;
V_52 -> V_76 |= V_77 ;
V_52 -> V_76 &= ~ V_78 ;
V_52 -> V_76 &= ~ V_79 ;
V_52 -> V_76 &= ~ V_80 ;
} else {
V_72 = 0 ;
}
if ( V_65 == V_81 ) {
V_52 = & V_2 -> V_52 [ V_72 ++ ] ;
V_71 = ( T_3 * ) V_62 ;
for ( V_70 = 0 ; V_70 < V_63 ; )
V_52 -> V_82 [ V_70 ++ ] = * V_71 ++ ;
V_52 -> V_76 = 0 ;
V_52 -> V_76 |= V_78 ;
V_52 -> V_76 |= V_79 ;
V_52 -> V_76 |= V_80 ;
V_52 -> V_76 |= V_83 ;
V_52 -> V_76 |= V_84 ;
V_52 -> V_76 |= F_34 ( V_63 , V_85 ) ;
V_52 -> V_76 |= F_34 ( V_86 , V_87 ) ;
} else {
F_35 (sgl, sg, sg_len, i) {
if ( V_68 -> V_88 > V_89 ) {
F_32 ( V_4 -> V_38 . V_39 , L_4 ,
V_68 -> V_88 , V_89 ) ;
goto V_74;
}
V_52 = & V_2 -> V_52 [ V_72 ++ ] ;
V_52 -> V_75 = V_2 -> V_13 + sizeof( * V_52 ) * V_72 ;
V_52 -> V_90 = V_68 -> V_91 ;
V_52 -> V_92 = V_68 -> V_88 ;
V_52 -> V_76 = 0 ;
V_52 -> V_76 |= V_77 ;
V_52 -> V_76 |= V_83 ;
V_52 -> V_76 |= V_84 ;
V_52 -> V_76 |= F_34 ( V_65 == V_93 ?
V_94 : V_95 ,
V_87 ) ;
if ( V_69 + 1 == V_63 ) {
V_52 -> V_76 &= ~ V_77 ;
V_52 -> V_76 |= V_78 ;
V_52 -> V_76 |= V_79 ;
V_52 -> V_76 |= V_80 ;
}
}
}
return & V_2 -> V_21 ;
V_74:
V_2 -> V_16 = V_41 ;
return NULL ;
}
static struct V_23 * F_36 (
struct V_22 * V_6 , T_4 V_96 , T_5 V_97 ,
T_5 V_98 , enum V_64 V_65 )
{
struct V_1 * V_2 = F_12 ( V_6 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_99 = V_97 / V_98 ;
int V_69 = 0 , V_100 = 0 ;
if ( V_2 -> V_16 == V_19 )
return NULL ;
V_2 -> V_16 = V_19 ;
V_2 -> V_42 |= V_43 ;
if ( V_99 > V_73 ) {
F_32 ( V_4 -> V_38 . V_39 ,
L_3 ,
V_99 , V_73 ) ;
goto V_74;
}
if ( V_98 > V_89 ) {
F_32 ( V_4 -> V_38 . V_39 ,
L_5 ,
V_98 , V_89 ) ;
goto V_74;
}
while ( V_100 < V_97 ) {
struct V_67 * V_52 = & V_2 -> V_52 [ V_69 ] ;
if ( V_69 + 1 == V_99 )
V_52 -> V_75 = V_2 -> V_13 ;
else
V_52 -> V_75 = V_2 -> V_13 + sizeof( * V_52 ) * ( V_69 + 1 ) ;
V_52 -> V_90 = V_96 ;
V_52 -> V_92 = V_98 ;
V_52 -> V_76 = 0 ;
V_52 -> V_76 |= V_77 ;
V_52 -> V_76 |= V_78 ;
V_52 -> V_76 |= V_83 ;
V_52 -> V_76 |= V_84 ;
V_52 -> V_76 |= F_34 ( V_65 == V_93 ?
V_94 : V_95 , V_87 ) ;
V_96 += V_98 ;
V_100 += V_98 ;
V_69 ++ ;
}
return & V_2 -> V_21 ;
V_74:
V_2 -> V_16 = V_41 ;
return NULL ;
}
static int F_37 ( struct V_22 * V_6 , enum V_101 V_102 ,
unsigned long V_103 )
{
struct V_1 * V_2 = F_12 ( V_6 ) ;
int V_49 = 0 ;
switch ( V_102 ) {
case V_104 :
F_8 ( V_2 ) ;
break;
case V_105 :
F_9 ( V_2 ) ;
break;
case V_106 :
F_10 ( V_2 ) ;
break;
default:
V_49 = - V_107 ;
}
return V_49 ;
}
static enum V_108 F_38 ( struct V_22 * V_6 ,
T_1 V_20 , struct V_109 * V_110 )
{
struct V_1 * V_2 = F_12 ( V_6 ) ;
T_1 V_111 ;
V_111 = V_6 -> V_20 ;
F_39 ( V_110 , V_2 -> V_44 , V_111 , 0 ) ;
return V_2 -> V_16 ;
}
static void F_40 ( struct V_22 * V_6 )
{
}
static int T_6 F_41 ( struct V_3 * V_4 )
{
int V_49 ;
V_49 = F_24 ( V_4 -> V_58 ) ;
if ( V_49 )
goto V_74;
V_49 = F_42 ( V_4 -> V_8 ) ;
if ( V_49 )
goto V_74;
V_4 -> V_112 = F_17 ( V_4 -> V_8 +
( ( V_4 -> V_29 == V_113 ) ?
V_114 : V_115 ) ) >>
V_116 ;
if ( F_2 () ) {
F_4 ( V_117 ,
V_4 -> V_8 + V_9 + V_10 ) ;
F_4 ( V_118 ,
V_4 -> V_8 + V_9 + V_10 ) ;
}
F_4 ( V_33 << V_35 ,
V_4 -> V_8 + V_32 + V_10 ) ;
F_30 ( V_4 -> V_58 ) ;
return 0 ;
V_74:
return V_49 ;
}
static int T_6 F_43 ( struct V_119 * V_120 )
{
const struct V_121 * V_122 =
F_44 ( V_120 ) ;
struct V_3 * V_4 ;
struct V_123 * V_124 ;
int V_49 , V_69 ;
V_4 = F_45 ( sizeof( * V_4 ) , V_54 ) ;
if ( ! V_4 )
return - V_55 ;
V_4 -> V_29 = V_122 -> V_125 ;
V_124 = F_46 ( V_120 , V_126 , 0 ) ;
if ( ! F_47 ( V_124 -> V_127 , F_48 ( V_124 ) ,
V_120 -> V_128 ) ) {
V_49 = - V_129 ;
goto V_130;
}
V_4 -> V_8 = F_49 ( V_124 -> V_127 , F_48 ( V_124 ) ) ;
if ( ! V_4 -> V_8 ) {
V_49 = - V_55 ;
goto V_131;
}
V_4 -> V_58 = F_50 ( & V_120 -> V_39 , NULL ) ;
if ( F_51 ( V_4 -> V_58 ) ) {
V_49 = F_52 ( V_4 -> V_58 ) ;
goto V_59;
}
F_53 ( V_132 , V_4 -> V_38 . V_133 ) ;
F_53 ( V_134 , V_4 -> V_38 . V_133 ) ;
F_54 ( & V_4 -> V_38 . V_135 ) ;
for ( V_69 = 0 ; V_69 < V_35 ; V_69 ++ ) {
struct V_1 * V_2 = & V_4 -> V_37 [ V_69 ] ;
V_2 -> V_4 = V_4 ;
V_2 -> V_6 . V_136 = & V_4 -> V_38 ;
F_55 ( & V_2 -> V_45 , F_15 ,
( unsigned long ) V_2 ) ;
F_56 ( & V_2 -> V_6 . V_137 ,
& V_4 -> V_38 . V_135 ) ;
}
V_49 = F_41 ( V_4 ) ;
if ( V_49 )
goto V_138;
V_4 -> V_38 . V_39 = & V_120 -> V_39 ;
V_4 -> V_38 . V_39 -> V_139 = & V_4 -> V_139 ;
F_57 ( V_4 -> V_38 . V_39 , V_89 ) ;
V_4 -> V_38 . V_140 = F_21 ;
V_4 -> V_38 . V_141 = F_29 ;
V_4 -> V_38 . V_142 = F_38 ;
V_4 -> V_38 . V_143 = F_31 ;
V_4 -> V_38 . V_144 = F_36 ;
V_4 -> V_38 . V_145 = F_37 ;
V_4 -> V_38 . V_146 = F_40 ;
V_49 = F_58 ( & V_4 -> V_38 ) ;
if ( V_49 ) {
F_32 ( V_4 -> V_38 . V_39 , L_6 ) ;
goto V_138;
}
F_59 ( V_4 -> V_38 . V_39 , L_7 ) ;
return 0 ;
V_138:
F_60 ( V_4 -> V_58 ) ;
V_59:
F_61 ( V_4 -> V_8 ) ;
V_131:
F_62 ( V_124 -> V_127 , F_48 ( V_124 ) ) ;
V_130:
F_63 ( V_4 ) ;
return V_49 ;
}
static int T_6 F_64 ( void )
{
return F_65 ( & V_147 , F_43 ) ;
}
