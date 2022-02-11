static inline void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = V_2 -> V_7 . V_6 ;
int V_8 = V_3 ? V_9 : V_10 ;
if ( F_2 () ) {
if ( F_3 () )
F_4 ( 1 << ( V_6 + V_11 ) ,
V_5 -> V_12 + V_13 + V_8 ) ;
else
F_4 ( 1 << V_6 ,
V_5 -> V_12 + V_13 + V_8 ) ;
}
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = V_2 -> V_7 . V_6 ;
if ( F_2 () && F_3 () )
F_4 ( 1 << ( V_6 + V_14 ) ,
V_5 -> V_12 + V_13 + V_10 ) ;
else
F_4 ( 1 << ( V_6 + V_15 ) ,
V_5 -> V_12 + V_16 + V_10 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = V_2 -> V_7 . V_6 ;
F_1 ( V_2 , 1 ) ;
F_4 ( V_2 -> V_17 ,
V_5 -> V_12 + F_7 ( V_6 ) ) ;
F_4 ( 1 , V_5 -> V_12 + F_8 ( V_6 ) ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0 ) ;
V_2 -> V_18 = V_19 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = V_2 -> V_7 . V_6 ;
if ( F_2 () && F_3 () )
F_4 ( 1 << V_6 ,
V_5 -> V_12 + V_13 + V_10 ) ;
else
F_4 ( 1 << V_6 ,
V_5 -> V_12 + V_16 + V_10 ) ;
V_2 -> V_18 = V_20 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = V_2 -> V_7 . V_6 ;
if ( F_2 () && F_3 () )
F_4 ( 1 << V_6 ,
V_5 -> V_12 + V_13 + V_9 ) ;
else
F_4 ( 1 << V_6 ,
V_5 -> V_12 + V_16 + V_9 ) ;
V_2 -> V_18 = V_21 ;
}
static T_1 F_12 ( struct V_1 * V_2 )
{
T_1 V_22 = V_2 -> V_7 . V_22 ;
if ( ++ V_22 < 0 )
V_22 = 1 ;
V_2 -> V_7 . V_22 = V_22 ;
V_2 -> V_23 . V_22 = V_22 ;
return V_22 ;
}
static struct V_1 * F_13 ( struct V_24 * V_7 )
{
return F_14 ( V_7 , struct V_1 , V_7 ) ;
}
static T_1 F_15 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_13 ( V_26 -> V_7 ) ;
F_6 ( V_2 ) ;
return F_12 ( V_2 ) ;
}
static void F_16 ( unsigned long V_27 )
{
struct V_1 * V_2 = (struct V_1 * ) V_27 ;
if ( V_2 -> V_23 . V_28 )
V_2 -> V_23 . V_28 ( V_2 -> V_23 . V_29 ) ;
}
static T_2 F_17 ( int V_30 , void * V_31 )
{
struct V_4 * V_5 = V_31 ;
T_3 V_32 , V_33 ;
V_32 = F_18 ( V_5 -> V_12 + V_34 ) ;
V_32 &= V_35 ;
F_4 ( V_32 , V_5 -> V_12 + V_34 + V_9 ) ;
V_33 = F_18 ( V_5 -> V_12 + V_36 ) ;
F_4 ( V_33 , V_5 -> V_12 + V_36 + V_9 ) ;
V_33 = ( ( V_33 >> V_37 ) & V_33 ) |
( ~ ( V_33 >> V_37 ) & V_33 & ~ V_32 ) ;
V_32 = ( V_33 << V_37 ) | V_32 ;
while ( V_32 ) {
int V_38 = F_19 ( V_32 ) - 1 ;
struct V_1 * V_2 =
& V_5 -> V_39 [ V_38 % V_37 ] ;
if ( V_38 >= V_37 ) {
F_20 ( V_5 -> V_40 . V_41 ,
L_1 , V_42 ,
V_38 - V_37 ) ;
V_2 -> V_18 = V_43 ;
F_5 ( V_2 ) ;
} else {
if ( V_2 -> V_44 & V_45 )
V_2 -> V_18 = V_21 ;
else
V_2 -> V_18 = V_19 ;
}
V_32 &= ~ ( 1 << V_38 ) ;
if ( V_2 -> V_18 == V_19 )
V_2 -> V_46 = V_2 -> V_23 . V_22 ;
F_21 ( & V_2 -> V_47 ) ;
}
return V_48 ;
}
static int F_22 ( struct V_24 * V_7 )
{
struct V_1 * V_2 = F_13 ( V_7 ) ;
struct V_49 * V_27 = V_7 -> V_50 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_51 ;
if ( ! V_27 )
return - V_52 ;
V_2 -> V_53 = V_27 -> V_53 ;
V_2 -> V_54 = F_23 ( V_5 -> V_40 . V_41 , V_55 ,
& V_2 -> V_17 , V_56 ) ;
if ( ! V_2 -> V_54 ) {
V_51 = - V_57 ;
goto V_58;
}
memset ( V_2 -> V_54 , 0 , V_55 ) ;
if ( V_2 -> V_53 != V_59 ) {
V_51 = F_24 ( V_2 -> V_53 , F_17 ,
0 , L_2 , V_5 ) ;
if ( V_51 )
goto V_60;
}
V_51 = F_25 ( V_5 -> V_61 ) ;
if ( V_51 )
goto V_62;
F_1 ( V_2 , 1 ) ;
F_5 ( V_2 ) ;
F_1 ( V_2 , 0 ) ;
F_26 ( & V_2 -> V_23 , V_7 ) ;
V_2 -> V_23 . V_63 = F_15 ;
F_27 ( & V_2 -> V_23 ) ;
return 0 ;
V_62:
F_28 ( V_2 -> V_53 , V_5 ) ;
V_60:
F_29 ( V_5 -> V_40 . V_41 , V_55 ,
V_2 -> V_54 , V_2 -> V_17 ) ;
V_58:
return V_51 ;
}
static void F_30 ( struct V_24 * V_7 )
{
struct V_1 * V_2 = F_13 ( V_7 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
F_9 ( V_2 ) ;
F_28 ( V_2 -> V_53 , V_5 ) ;
F_29 ( V_5 -> V_40 . V_41 , V_55 ,
V_2 -> V_54 , V_2 -> V_17 ) ;
F_31 ( V_5 -> V_61 ) ;
}
static struct V_25 * F_32 (
struct V_24 * V_7 , struct V_64 * V_65 ,
unsigned int V_66 , enum V_67 V_68 ,
unsigned long V_69 )
{
struct V_1 * V_2 = F_13 ( V_7 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_70 * V_54 ;
struct V_64 * V_71 ;
int V_72 , V_73 ;
T_3 * V_74 ;
static int V_75 ;
if ( V_2 -> V_18 == V_21 && ! V_69 )
return NULL ;
if ( V_66 + ( V_69 ? V_75 : 0 ) > V_76 ) {
F_33 ( V_5 -> V_40 . V_41 ,
L_3 ,
V_66 , V_76 ) ;
goto V_77;
}
V_2 -> V_18 = V_21 ;
V_2 -> V_44 = 0 ;
if ( V_69 ) {
F_34 ( V_75 < 1 ) ;
V_54 = & V_2 -> V_54 [ V_75 - 1 ] ;
V_54 -> V_78 = V_2 -> V_17 + sizeof( * V_54 ) * V_75 ;
V_54 -> V_79 |= V_80 ;
V_54 -> V_79 &= ~ V_81 ;
V_54 -> V_79 &= ~ V_82 ;
V_54 -> V_79 &= ~ V_83 ;
} else {
V_75 = 0 ;
}
if ( V_68 == V_84 ) {
V_54 = & V_2 -> V_54 [ V_75 ++ ] ;
V_74 = ( T_3 * ) V_65 ;
for ( V_73 = 0 ; V_73 < V_66 ; )
V_54 -> V_85 [ V_73 ++ ] = * V_74 ++ ;
V_54 -> V_79 = 0 ;
V_54 -> V_79 |= V_81 ;
V_54 -> V_79 |= V_82 ;
V_54 -> V_79 |= V_83 ;
V_54 -> V_79 |= V_86 ;
V_54 -> V_79 |= V_87 ;
V_54 -> V_79 |= F_35 ( V_66 , V_88 ) ;
V_54 -> V_79 |= F_35 ( V_89 , V_90 ) ;
} else {
F_36 (sgl, sg, sg_len, i) {
if ( V_71 -> V_91 > V_92 ) {
F_33 ( V_5 -> V_40 . V_41 , L_4 ,
V_71 -> V_91 , V_92 ) ;
goto V_77;
}
V_54 = & V_2 -> V_54 [ V_75 ++ ] ;
V_54 -> V_78 = V_2 -> V_17 + sizeof( * V_54 ) * V_75 ;
V_54 -> V_93 = V_71 -> V_94 ;
V_54 -> V_95 = V_71 -> V_91 ;
V_54 -> V_79 = 0 ;
V_54 -> V_79 |= V_80 ;
V_54 -> V_79 |= V_86 ;
V_54 -> V_79 |= V_87 ;
V_54 -> V_79 |= F_35 ( V_68 == V_96 ?
V_97 : V_98 ,
V_90 ) ;
if ( V_72 + 1 == V_66 ) {
V_54 -> V_79 &= ~ V_80 ;
V_54 -> V_79 |= V_81 ;
V_54 -> V_79 |= V_82 ;
V_54 -> V_79 |= V_83 ;
}
}
}
return & V_2 -> V_23 ;
V_77:
V_2 -> V_18 = V_43 ;
return NULL ;
}
static struct V_25 * F_37 (
struct V_24 * V_7 , T_4 V_99 , T_5 V_100 ,
T_5 V_101 , enum V_67 V_68 )
{
struct V_1 * V_2 = F_13 ( V_7 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_102 = V_100 / V_101 ;
int V_72 = 0 , V_103 = 0 ;
if ( V_2 -> V_18 == V_21 )
return NULL ;
V_2 -> V_18 = V_21 ;
V_2 -> V_44 |= V_45 ;
if ( V_102 > V_76 ) {
F_33 ( V_5 -> V_40 . V_41 ,
L_3 ,
V_102 , V_76 ) ;
goto V_77;
}
if ( V_101 > V_92 ) {
F_33 ( V_5 -> V_40 . V_41 ,
L_5 ,
V_101 , V_92 ) ;
goto V_77;
}
while ( V_103 < V_100 ) {
struct V_70 * V_54 = & V_2 -> V_54 [ V_72 ] ;
if ( V_72 + 1 == V_102 )
V_54 -> V_78 = V_2 -> V_17 ;
else
V_54 -> V_78 = V_2 -> V_17 + sizeof( * V_54 ) * ( V_72 + 1 ) ;
V_54 -> V_93 = V_99 ;
V_54 -> V_95 = V_101 ;
V_54 -> V_79 = 0 ;
V_54 -> V_79 |= V_80 ;
V_54 -> V_79 |= V_81 ;
V_54 -> V_79 |= V_86 ;
V_54 -> V_79 |= V_87 ;
V_54 -> V_79 |= F_35 ( V_68 == V_96 ?
V_97 : V_98 , V_90 ) ;
V_99 += V_101 ;
V_103 += V_101 ;
V_72 ++ ;
}
return & V_2 -> V_23 ;
V_77:
V_2 -> V_18 = V_43 ;
return NULL ;
}
static int F_38 ( struct V_24 * V_7 , enum V_104 V_105 ,
unsigned long V_106 )
{
struct V_1 * V_2 = F_13 ( V_7 ) ;
int V_51 = 0 ;
switch ( V_105 ) {
case V_107 :
F_9 ( V_2 ) ;
F_5 ( V_2 ) ;
break;
case V_108 :
F_10 ( V_2 ) ;
break;
case V_109 :
F_11 ( V_2 ) ;
break;
default:
V_51 = - V_110 ;
}
return V_51 ;
}
static enum V_111 F_39 ( struct V_24 * V_7 ,
T_1 V_22 , struct V_112 * V_113 )
{
struct V_1 * V_2 = F_13 ( V_7 ) ;
T_1 V_114 ;
V_114 = V_7 -> V_22 ;
F_40 ( V_113 , V_2 -> V_46 , V_114 , 0 ) ;
return V_2 -> V_18 ;
}
static void F_41 ( struct V_24 * V_7 )
{
}
static int T_6 F_42 ( struct V_4 * V_5 )
{
int V_51 ;
V_51 = F_25 ( V_5 -> V_61 ) ;
if ( V_51 )
goto V_77;
V_51 = F_43 ( V_5 -> V_12 ) ;
if ( V_51 )
goto V_77;
V_5 -> V_115 = F_18 ( V_5 -> V_12 +
( ( V_5 -> V_31 == V_116 ) ?
V_117 : V_118 ) ) >>
V_119 ;
if ( F_2 () ) {
F_4 ( V_120 ,
V_5 -> V_12 + V_13 + V_10 ) ;
F_4 ( V_121 ,
V_5 -> V_12 + V_13 + V_10 ) ;
}
F_4 ( V_35 << V_37 ,
V_5 -> V_12 + V_34 + V_10 ) ;
F_31 ( V_5 -> V_61 ) ;
return 0 ;
V_77:
return V_51 ;
}
static int T_6 F_44 ( struct V_122 * V_123 )
{
const struct V_124 * V_125 =
F_45 ( V_123 ) ;
struct V_4 * V_5 ;
struct V_126 * V_127 ;
int V_51 , V_72 ;
V_5 = F_46 ( sizeof( * V_5 ) , V_56 ) ;
if ( ! V_5 )
return - V_57 ;
V_5 -> V_31 = V_125 -> V_128 ;
V_127 = F_47 ( V_123 , V_129 , 0 ) ;
if ( ! F_48 ( V_127 -> V_130 , F_49 ( V_127 ) ,
V_123 -> V_131 ) ) {
V_51 = - V_132 ;
goto V_133;
}
V_5 -> V_12 = F_50 ( V_127 -> V_130 , F_49 ( V_127 ) ) ;
if ( ! V_5 -> V_12 ) {
V_51 = - V_57 ;
goto V_134;
}
V_5 -> V_61 = F_51 ( & V_123 -> V_41 , NULL ) ;
if ( F_52 ( V_5 -> V_61 ) ) {
V_51 = F_53 ( V_5 -> V_61 ) ;
goto V_62;
}
F_54 ( V_135 , V_5 -> V_40 . V_136 ) ;
F_54 ( V_137 , V_5 -> V_40 . V_136 ) ;
F_55 ( & V_5 -> V_40 . V_138 ) ;
for ( V_72 = 0 ; V_72 < V_37 ; V_72 ++ ) {
struct V_1 * V_2 = & V_5 -> V_39 [ V_72 ] ;
V_2 -> V_5 = V_5 ;
V_2 -> V_7 . V_139 = & V_5 -> V_40 ;
F_56 ( & V_2 -> V_47 , F_16 ,
( unsigned long ) V_2 ) ;
F_57 ( & V_2 -> V_7 . V_140 ,
& V_5 -> V_40 . V_138 ) ;
}
V_51 = F_42 ( V_5 ) ;
if ( V_51 )
goto V_141;
V_5 -> V_40 . V_41 = & V_123 -> V_41 ;
V_5 -> V_40 . V_41 -> V_142 = & V_5 -> V_142 ;
F_58 ( V_5 -> V_40 . V_41 , V_92 ) ;
V_5 -> V_40 . V_143 = F_22 ;
V_5 -> V_40 . V_144 = F_30 ;
V_5 -> V_40 . V_145 = F_39 ;
V_5 -> V_40 . V_146 = F_32 ;
V_5 -> V_40 . V_147 = F_37 ;
V_5 -> V_40 . V_148 = F_38 ;
V_5 -> V_40 . V_149 = F_41 ;
V_51 = F_59 ( & V_5 -> V_40 ) ;
if ( V_51 ) {
F_33 ( V_5 -> V_40 . V_41 , L_6 ) ;
goto V_141;
}
F_60 ( V_5 -> V_40 . V_41 , L_7 ) ;
return 0 ;
V_141:
F_61 ( V_5 -> V_61 ) ;
V_62:
F_62 ( V_5 -> V_12 ) ;
V_134:
F_63 ( V_127 -> V_130 , F_49 ( V_127 ) ) ;
V_133:
F_64 ( V_5 ) ;
return V_51 ;
}
static int T_6 F_65 ( void )
{
return F_66 ( & V_150 , F_44 ) ;
}
