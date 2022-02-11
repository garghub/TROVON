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
static T_1 F_11 ( struct V_1 * V_2 )
{
T_1 V_19 = V_2 -> V_6 . V_19 ;
if ( ++ V_19 < 0 )
V_19 = 1 ;
V_2 -> V_6 . V_19 = V_19 ;
V_2 -> V_20 . V_19 = V_19 ;
return V_19 ;
}
static struct V_1 * F_12 ( struct V_21 * V_6 )
{
return F_13 ( V_6 , struct V_1 , V_6 ) ;
}
static T_1 F_14 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_12 ( V_23 -> V_6 ) ;
F_5 ( V_2 ) ;
return F_11 ( V_2 ) ;
}
static void F_15 ( unsigned long V_24 )
{
struct V_1 * V_2 = (struct V_1 * ) V_24 ;
if ( V_2 -> V_20 . V_25 )
V_2 -> V_20 . V_25 ( V_2 -> V_20 . V_26 ) ;
}
static T_2 F_16 ( int V_27 , void * V_28 )
{
struct V_3 * V_4 = V_28 ;
T_3 V_29 , V_30 ;
V_29 = F_17 ( V_4 -> V_8 + V_31 ) ;
V_29 &= V_32 ;
F_4 ( V_29 , V_4 -> V_8 + V_31 + V_17 ) ;
V_30 = F_17 ( V_4 -> V_8 + V_33 ) ;
F_4 ( V_30 , V_4 -> V_8 + V_33 + V_17 ) ;
V_30 = ( ( V_30 >> V_34 ) & V_30 ) |
( ~ ( V_30 >> V_34 ) & V_30 & ~ V_29 ) ;
V_29 = ( V_30 << V_34 ) | V_29 ;
while ( V_29 ) {
int V_35 = F_18 ( V_29 ) - 1 ;
struct V_1 * V_2 =
& V_4 -> V_36 [ V_35 % V_34 ] ;
if ( V_35 >= V_34 ) {
F_19 ( V_4 -> V_37 . V_38 ,
L_1 , V_39 ,
V_35 - V_34 ) ;
V_2 -> V_14 = V_40 ;
F_1 ( V_2 ) ;
} else {
if ( V_2 -> V_41 & V_42 )
V_2 -> V_14 = V_18 ;
else
V_2 -> V_14 = V_15 ;
}
V_29 &= ~ ( 1 << V_35 ) ;
if ( V_2 -> V_14 == V_15 )
V_2 -> V_43 = V_2 -> V_20 . V_19 ;
F_20 ( & V_2 -> V_44 ) ;
}
return V_45 ;
}
static int F_21 ( struct V_21 * V_6 )
{
struct V_1 * V_2 = F_12 ( V_6 ) ;
struct V_46 * V_24 = V_6 -> V_47 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_48 ;
if ( ! V_24 )
return - V_49 ;
V_2 -> V_50 = V_24 -> V_50 ;
V_2 -> V_51 = F_22 ( V_4 -> V_37 . V_38 , V_52 ,
& V_2 -> V_13 , V_53 ) ;
if ( ! V_2 -> V_51 ) {
V_48 = - V_54 ;
goto V_55;
}
memset ( V_2 -> V_51 , 0 , V_52 ) ;
if ( V_2 -> V_50 != V_56 ) {
V_48 = F_23 ( V_2 -> V_50 , F_16 ,
0 , L_2 , V_4 ) ;
if ( V_48 )
goto V_57;
}
V_48 = F_24 ( V_4 -> V_58 ) ;
if ( V_48 )
goto V_59;
F_1 ( V_2 ) ;
F_25 ( & V_2 -> V_20 , V_6 ) ;
V_2 -> V_20 . V_60 = F_14 ;
F_26 ( & V_2 -> V_20 ) ;
return 0 ;
V_59:
F_27 ( V_2 -> V_50 , V_4 ) ;
V_57:
F_28 ( V_4 -> V_37 . V_38 , V_52 ,
V_2 -> V_51 , V_2 -> V_13 ) ;
V_55:
return V_48 ;
}
static void F_29 ( struct V_21 * V_6 )
{
struct V_1 * V_2 = F_12 ( V_6 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_8 ( V_2 ) ;
F_27 ( V_2 -> V_50 , V_4 ) ;
F_28 ( V_4 -> V_37 . V_38 , V_52 ,
V_2 -> V_51 , V_2 -> V_13 ) ;
F_30 ( V_4 -> V_58 ) ;
}
static struct V_22 * F_31 (
struct V_21 * V_6 , struct V_61 * V_62 ,
unsigned int V_63 , enum V_64 V_65 ,
unsigned long V_66 )
{
struct V_1 * V_2 = F_12 ( V_6 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_67 * V_51 ;
struct V_61 * V_68 ;
int V_69 , V_70 ;
T_3 * V_71 ;
int V_72 = V_66 ? V_2 -> V_73 : 0 ;
if ( V_2 -> V_14 == V_18 && ! V_66 )
return NULL ;
if ( V_63 + ( V_66 ? V_72 : 0 ) > V_74 ) {
F_32 ( V_4 -> V_37 . V_38 ,
L_3 ,
V_63 , V_74 ) ;
goto V_75;
}
V_2 -> V_14 = V_18 ;
V_2 -> V_41 = 0 ;
if ( V_66 ) {
F_33 ( V_72 < 1 ) ;
V_51 = & V_2 -> V_51 [ V_72 - 1 ] ;
V_51 -> V_76 = V_2 -> V_13 + sizeof( * V_51 ) * V_72 ;
V_51 -> V_77 |= V_78 ;
V_51 -> V_77 &= ~ V_79 ;
V_51 -> V_77 &= ~ V_80 ;
V_51 -> V_77 &= ~ V_81 ;
} else {
V_72 = 0 ;
}
if ( V_65 == V_82 ) {
V_51 = & V_2 -> V_51 [ V_72 ++ ] ;
V_71 = ( T_3 * ) V_62 ;
for ( V_70 = 0 ; V_70 < V_63 ; )
V_51 -> V_83 [ V_70 ++ ] = * V_71 ++ ;
V_51 -> V_77 = 0 ;
V_51 -> V_77 |= V_79 ;
V_51 -> V_77 |= V_80 ;
V_51 -> V_77 |= V_81 ;
V_51 -> V_77 |= V_84 ;
V_51 -> V_77 |= V_85 ;
V_51 -> V_77 |= F_34 ( V_63 , V_86 ) ;
V_51 -> V_77 |= F_34 ( V_87 , V_88 ) ;
} else {
F_35 (sgl, sg, sg_len, i) {
if ( V_68 -> V_89 > V_90 ) {
F_32 ( V_4 -> V_37 . V_38 , L_4 ,
V_68 -> V_89 , V_90 ) ;
goto V_75;
}
V_51 = & V_2 -> V_51 [ V_72 ++ ] ;
V_51 -> V_76 = V_2 -> V_13 + sizeof( * V_51 ) * V_72 ;
V_51 -> V_91 = V_68 -> V_92 ;
V_51 -> V_93 = V_68 -> V_89 ;
V_51 -> V_77 = 0 ;
V_51 -> V_77 |= V_78 ;
V_51 -> V_77 |= V_84 ;
V_51 -> V_77 |= V_85 ;
V_51 -> V_77 |= F_34 ( V_65 == V_94 ?
V_95 : V_96 ,
V_88 ) ;
if ( V_69 + 1 == V_63 ) {
V_51 -> V_77 &= ~ V_78 ;
V_51 -> V_77 |= V_79 ;
V_51 -> V_77 |= V_80 ;
V_51 -> V_77 |= V_81 ;
}
}
}
V_2 -> V_73 = V_72 ;
return & V_2 -> V_20 ;
V_75:
V_2 -> V_14 = V_40 ;
return NULL ;
}
static struct V_22 * F_36 (
struct V_21 * V_6 , T_4 V_97 , T_5 V_98 ,
T_5 V_99 , enum V_64 V_65 )
{
struct V_1 * V_2 = F_12 ( V_6 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_100 = V_98 / V_99 ;
int V_69 = 0 , V_101 = 0 ;
if ( V_2 -> V_14 == V_18 )
return NULL ;
V_2 -> V_14 = V_18 ;
V_2 -> V_41 |= V_42 ;
if ( V_100 > V_74 ) {
F_32 ( V_4 -> V_37 . V_38 ,
L_3 ,
V_100 , V_74 ) ;
goto V_75;
}
if ( V_99 > V_90 ) {
F_32 ( V_4 -> V_37 . V_38 ,
L_5 ,
V_99 , V_90 ) ;
goto V_75;
}
while ( V_101 < V_98 ) {
struct V_67 * V_51 = & V_2 -> V_51 [ V_69 ] ;
if ( V_69 + 1 == V_100 )
V_51 -> V_76 = V_2 -> V_13 ;
else
V_51 -> V_76 = V_2 -> V_13 + sizeof( * V_51 ) * ( V_69 + 1 ) ;
V_51 -> V_91 = V_97 ;
V_51 -> V_93 = V_99 ;
V_51 -> V_77 = 0 ;
V_51 -> V_77 |= V_78 ;
V_51 -> V_77 |= V_79 ;
V_51 -> V_77 |= V_84 ;
V_51 -> V_77 |= V_85 ;
V_51 -> V_77 |= F_34 ( V_65 == V_94 ?
V_95 : V_96 , V_88 ) ;
V_97 += V_99 ;
V_101 += V_99 ;
V_69 ++ ;
}
V_2 -> V_73 = V_69 ;
return & V_2 -> V_20 ;
V_75:
V_2 -> V_14 = V_40 ;
return NULL ;
}
static int F_37 ( struct V_21 * V_6 , enum V_102 V_103 ,
unsigned long V_104 )
{
struct V_1 * V_2 = F_12 ( V_6 ) ;
int V_48 = 0 ;
switch ( V_103 ) {
case V_105 :
F_1 ( V_2 ) ;
F_8 ( V_2 ) ;
break;
case V_106 :
F_9 ( V_2 ) ;
break;
case V_107 :
F_10 ( V_2 ) ;
break;
default:
V_48 = - V_108 ;
}
return V_48 ;
}
static enum V_109 F_38 ( struct V_21 * V_6 ,
T_1 V_19 , struct V_110 * V_111 )
{
struct V_1 * V_2 = F_12 ( V_6 ) ;
T_1 V_112 ;
V_112 = V_6 -> V_19 ;
F_39 ( V_111 , V_2 -> V_43 , V_112 , 0 ) ;
return V_2 -> V_14 ;
}
static void F_40 ( struct V_21 * V_6 )
{
}
static int T_6 F_41 ( struct V_3 * V_4 )
{
int V_48 ;
V_48 = F_24 ( V_4 -> V_58 ) ;
if ( V_48 )
return V_48 ;
V_48 = F_42 ( V_4 -> V_8 ) ;
if ( V_48 )
goto V_75;
V_4 -> V_113 = F_17 ( V_4 -> V_8 +
( ( V_4 -> V_28 == V_114 ) ?
V_115 : V_116 ) ) >>
V_117 ;
if ( F_2 () ) {
F_4 ( V_118 ,
V_4 -> V_8 + V_9 + V_10 ) ;
F_4 ( V_119 ,
V_4 -> V_8 + V_9 + V_10 ) ;
}
F_4 ( V_32 << V_34 ,
V_4 -> V_8 + V_31 + V_10 ) ;
V_75:
F_30 ( V_4 -> V_58 ) ;
return V_48 ;
}
static int T_6 F_43 ( struct V_120 * V_121 )
{
const struct V_122 * V_123 =
F_44 ( V_121 ) ;
struct V_3 * V_4 ;
struct V_124 * V_125 ;
int V_48 , V_69 ;
V_4 = F_45 ( sizeof( * V_4 ) , V_53 ) ;
if ( ! V_4 )
return - V_54 ;
V_4 -> V_28 = V_123 -> V_126 ;
V_125 = F_46 ( V_121 , V_127 , 0 ) ;
if ( ! F_47 ( V_125 -> V_128 , F_48 ( V_125 ) ,
V_121 -> V_129 ) ) {
V_48 = - V_130 ;
goto V_131;
}
V_4 -> V_8 = F_49 ( V_125 -> V_128 , F_48 ( V_125 ) ) ;
if ( ! V_4 -> V_8 ) {
V_48 = - V_54 ;
goto V_132;
}
V_4 -> V_58 = F_50 ( & V_121 -> V_38 , NULL ) ;
if ( F_51 ( V_4 -> V_58 ) ) {
V_48 = F_52 ( V_4 -> V_58 ) ;
goto V_59;
}
F_53 ( V_133 , V_4 -> V_37 . V_134 ) ;
F_53 ( V_135 , V_4 -> V_37 . V_134 ) ;
F_54 ( & V_4 -> V_37 . V_136 ) ;
for ( V_69 = 0 ; V_69 < V_34 ; V_69 ++ ) {
struct V_1 * V_2 = & V_4 -> V_36 [ V_69 ] ;
V_2 -> V_4 = V_4 ;
V_2 -> V_6 . V_137 = & V_4 -> V_37 ;
F_55 ( & V_2 -> V_44 , F_15 ,
( unsigned long ) V_2 ) ;
F_56 ( & V_2 -> V_6 . V_138 ,
& V_4 -> V_37 . V_136 ) ;
}
V_48 = F_41 ( V_4 ) ;
if ( V_48 )
goto V_139;
V_4 -> V_37 . V_38 = & V_121 -> V_38 ;
V_4 -> V_37 . V_38 -> V_140 = & V_4 -> V_140 ;
F_57 ( V_4 -> V_37 . V_38 , V_90 ) ;
V_4 -> V_37 . V_141 = F_21 ;
V_4 -> V_37 . V_142 = F_29 ;
V_4 -> V_37 . V_143 = F_38 ;
V_4 -> V_37 . V_144 = F_31 ;
V_4 -> V_37 . V_145 = F_36 ;
V_4 -> V_37 . V_146 = F_37 ;
V_4 -> V_37 . V_147 = F_40 ;
V_48 = F_58 ( & V_4 -> V_37 ) ;
if ( V_48 ) {
F_32 ( V_4 -> V_37 . V_38 , L_6 ) ;
goto V_139;
}
F_59 ( V_4 -> V_37 . V_38 , L_7 ) ;
return 0 ;
V_139:
F_60 ( V_4 -> V_58 ) ;
V_59:
F_61 ( V_4 -> V_8 ) ;
V_132:
F_62 ( V_125 -> V_128 , F_48 ( V_125 ) ) ;
V_131:
F_63 ( V_4 ) ;
return V_48 ;
}
static int T_6 F_64 ( void )
{
return F_65 ( & V_148 , F_43 ) ;
}
