static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_1 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = V_4 -> V_3 . V_7 ;
if ( F_4 ( V_6 ) && F_5 ( V_6 ) )
F_6 ( 1 << ( V_7 + V_8 ) ,
V_6 -> V_9 + V_10 + V_11 ) ;
else
F_6 ( 1 << ( V_7 + V_12 ) ,
V_6 -> V_9 + V_13 + V_11 ) ;
}
static void F_7 ( struct V_1 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = V_4 -> V_3 . V_7 ;
F_6 ( V_4 -> V_14 ,
V_6 -> V_9 + F_8 ( V_6 , V_7 ) ) ;
F_6 ( 1 , V_6 -> V_9 + F_9 ( V_6 , V_7 ) ) ;
}
static void F_10 ( struct V_1 * V_4 )
{
V_4 -> V_15 = V_16 ;
}
static void F_11 ( struct V_1 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = V_4 -> V_3 . V_7 ;
if ( F_4 ( V_6 ) && F_5 ( V_6 ) )
F_6 ( 1 << V_7 ,
V_6 -> V_9 + V_10 + V_11 ) ;
else
F_6 ( 1 << V_7 ,
V_6 -> V_9 + V_13 + V_11 ) ;
V_4 -> V_15 = V_17 ;
}
static void F_12 ( struct V_1 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = V_4 -> V_3 . V_7 ;
if ( F_4 ( V_6 ) && F_5 ( V_6 ) )
F_6 ( 1 << V_7 ,
V_6 -> V_9 + V_10 + V_18 ) ;
else
F_6 ( 1 << V_7 ,
V_6 -> V_9 + V_13 + V_18 ) ;
V_4 -> V_15 = V_19 ;
}
static T_1 F_13 ( struct V_20 * V_21 )
{
return F_14 ( V_21 ) ;
}
static void F_15 ( unsigned long V_22 )
{
struct V_1 * V_4 = (struct V_1 * ) V_22 ;
if ( V_4 -> V_23 . V_24 )
V_4 -> V_23 . V_24 ( V_4 -> V_23 . V_25 ) ;
}
static T_2 F_16 ( int V_26 , void * V_27 )
{
struct V_5 * V_6 = V_27 ;
T_3 V_28 , V_29 ;
V_28 = F_17 ( V_6 -> V_9 + V_30 ) ;
V_28 &= V_31 ;
F_6 ( V_28 , V_6 -> V_9 + V_30 + V_18 ) ;
V_29 = F_17 ( V_6 -> V_9 + V_32 ) ;
F_6 ( V_29 , V_6 -> V_9 + V_32 + V_18 ) ;
V_29 = ( ( V_29 >> V_33 ) & V_29 ) |
( ~ ( V_29 >> V_33 ) & V_29 & ~ V_28 ) ;
V_28 = ( V_29 << V_33 ) | V_28 ;
while ( V_28 ) {
int V_34 = F_18 ( V_28 ) - 1 ;
struct V_1 * V_4 =
& V_6 -> V_35 [ V_34 % V_33 ] ;
if ( V_34 >= V_33 ) {
F_19 ( V_6 -> V_36 . V_37 ,
L_1 , V_38 ,
V_34 - V_33 ) ;
V_4 -> V_15 = V_39 ;
F_3 ( V_4 ) ;
} else {
if ( V_4 -> V_40 & V_41 )
V_4 -> V_15 = V_19 ;
else
V_4 -> V_15 = V_16 ;
}
V_28 &= ~ ( 1 << V_34 ) ;
if ( V_4 -> V_15 == V_16 )
F_20 ( & V_4 -> V_23 ) ;
F_21 ( & V_4 -> V_42 ) ;
}
return V_43 ;
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_44 ;
V_4 -> V_45 = F_23 ( V_6 -> V_36 . V_37 ,
V_46 , & V_4 -> V_14 ,
V_47 ) ;
if ( ! V_4 -> V_45 ) {
V_44 = - V_48 ;
goto V_49;
}
memset ( V_4 -> V_45 , 0 , V_46 ) ;
if ( V_4 -> V_50 != V_51 ) {
V_44 = F_24 ( V_4 -> V_50 , F_16 ,
0 , L_2 , V_6 ) ;
if ( V_44 )
goto V_52;
}
V_44 = F_25 ( V_6 -> V_53 ) ;
if ( V_44 )
goto V_54;
F_3 ( V_4 ) ;
F_26 ( & V_4 -> V_23 , V_3 ) ;
V_4 -> V_23 . V_55 = F_13 ;
F_27 ( & V_4 -> V_23 ) ;
return 0 ;
V_54:
F_28 ( V_4 -> V_50 , V_6 ) ;
V_52:
F_29 ( V_6 -> V_36 . V_37 , V_46 ,
V_4 -> V_45 , V_4 -> V_14 ) ;
V_49:
return V_44 ;
}
static void F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
F_10 ( V_4 ) ;
F_28 ( V_4 -> V_50 , V_6 ) ;
F_29 ( V_6 -> V_36 . V_37 , V_46 ,
V_4 -> V_45 , V_4 -> V_14 ) ;
F_31 ( V_6 -> V_53 ) ;
}
static struct V_20 * F_32 (
struct V_2 * V_3 , struct V_56 * V_57 ,
unsigned int V_58 , enum V_59 V_60 ,
unsigned long V_40 , void * V_61 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_62 * V_45 ;
struct V_56 * V_63 ;
T_3 V_64 , V_65 ;
T_3 * V_66 ;
bool V_67 = V_40 & V_68 ;
int V_69 = V_67 ? V_4 -> V_70 : 0 ;
if ( V_4 -> V_15 == V_19 && ! V_67 )
return NULL ;
if ( V_58 + ( V_67 ? V_69 : 0 ) > V_71 ) {
F_33 ( V_6 -> V_36 . V_37 ,
L_3 ,
V_58 , V_71 ) ;
goto V_72;
}
V_4 -> V_15 = V_19 ;
V_4 -> V_40 = 0 ;
if ( V_67 ) {
F_34 ( V_69 < 1 ) ;
V_45 = & V_4 -> V_45 [ V_69 - 1 ] ;
V_45 -> V_73 = V_4 -> V_14 + sizeof( * V_45 ) * V_69 ;
V_45 -> V_74 |= V_75 ;
V_45 -> V_74 &= ~ V_76 ;
V_45 -> V_74 &= ~ V_77 ;
} else {
V_69 = 0 ;
}
if ( V_60 == V_78 ) {
V_45 = & V_4 -> V_45 [ V_69 ++ ] ;
V_66 = ( T_3 * ) V_57 ;
for ( V_65 = 0 ; V_65 < V_58 ; )
V_45 -> V_79 [ V_65 ++ ] = * V_66 ++ ;
V_45 -> V_74 = 0 ;
V_45 -> V_74 |= V_76 ;
V_45 -> V_74 |= V_77 ;
if ( V_40 & V_80 )
V_45 -> V_74 |= V_81 ;
V_45 -> V_74 |= V_82 ;
V_45 -> V_74 |= V_83 ;
V_45 -> V_74 |= F_35 ( V_58 , V_84 ) ;
V_45 -> V_74 |= F_35 ( V_85 , V_86 ) ;
} else {
F_36 (sgl, sg, sg_len, i) {
if ( F_37 ( V_63 ) > V_87 ) {
F_33 ( V_6 -> V_36 . V_37 , L_4 ,
F_37 ( V_63 ) , V_87 ) ;
goto V_72;
}
V_45 = & V_4 -> V_45 [ V_69 ++ ] ;
V_45 -> V_73 = V_4 -> V_14 + sizeof( * V_45 ) * V_69 ;
V_45 -> V_88 = V_63 -> V_89 ;
V_45 -> V_90 = F_37 ( V_63 ) ;
V_45 -> V_74 = 0 ;
V_45 -> V_74 |= V_75 ;
V_45 -> V_74 |= V_82 ;
V_45 -> V_74 |= V_83 ;
V_45 -> V_74 |= F_35 ( V_60 == V_91 ?
V_92 : V_93 ,
V_86 ) ;
if ( V_64 + 1 == V_58 ) {
V_45 -> V_74 &= ~ V_75 ;
V_45 -> V_74 |= V_76 ;
V_45 -> V_74 |= V_77 ;
if ( V_40 & V_80 )
V_45 -> V_74 |= V_81 ;
}
}
}
V_4 -> V_70 = V_69 ;
return & V_4 -> V_23 ;
V_72:
V_4 -> V_15 = V_39 ;
return NULL ;
}
static struct V_20 * F_38 (
struct V_2 * V_3 , T_4 V_94 , T_5 V_95 ,
T_5 V_96 , enum V_59 V_60 ,
unsigned long V_40 , void * V_61 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_3 V_97 = V_95 / V_96 ;
T_3 V_64 = 0 , V_98 = 0 ;
if ( V_4 -> V_15 == V_19 )
return NULL ;
V_4 -> V_15 = V_19 ;
V_4 -> V_40 |= V_41 ;
if ( V_97 > V_71 ) {
F_33 ( V_6 -> V_36 . V_37 ,
L_3 ,
V_97 , V_71 ) ;
goto V_72;
}
if ( V_96 > V_87 ) {
F_33 ( V_6 -> V_36 . V_37 ,
L_5 ,
V_96 , V_87 ) ;
goto V_72;
}
while ( V_98 < V_95 ) {
struct V_62 * V_45 = & V_4 -> V_45 [ V_64 ] ;
if ( V_64 + 1 == V_97 )
V_45 -> V_73 = V_4 -> V_14 ;
else
V_45 -> V_73 = V_4 -> V_14 + sizeof( * V_45 ) * ( V_64 + 1 ) ;
V_45 -> V_88 = V_94 ;
V_45 -> V_90 = V_96 ;
V_45 -> V_74 = 0 ;
V_45 -> V_74 |= V_75 ;
V_45 -> V_74 |= V_76 ;
V_45 -> V_74 |= V_82 ;
V_45 -> V_74 |= V_83 ;
V_45 -> V_74 |= F_35 ( V_60 == V_91 ?
V_92 : V_93 , V_86 ) ;
V_94 += V_96 ;
V_98 += V_96 ;
V_64 ++ ;
}
V_4 -> V_70 = V_64 ;
return & V_4 -> V_23 ;
V_72:
V_4 -> V_15 = V_39 ;
return NULL ;
}
static int F_39 ( struct V_2 * V_3 , enum V_99 V_100 ,
unsigned long V_101 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_44 = 0 ;
switch ( V_100 ) {
case V_102 :
F_3 ( V_4 ) ;
F_10 ( V_4 ) ;
break;
case V_103 :
F_11 ( V_4 ) ;
break;
case V_104 :
F_12 ( V_4 ) ;
break;
default:
V_44 = - V_105 ;
}
return V_44 ;
}
static enum V_106 F_40 ( struct V_2 * V_3 ,
T_1 V_107 , struct V_108 * V_109 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_41 ( V_109 , V_3 -> V_110 , V_3 -> V_107 , 0 ) ;
return V_4 -> V_15 ;
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_7 ( V_4 ) ;
}
static int T_6 F_43 ( struct V_5 * V_6 )
{
int V_44 ;
V_44 = F_25 ( V_6 -> V_53 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_44 ( V_6 -> V_9 ) ;
if ( V_44 )
goto V_72;
if ( F_4 ( V_6 ) ) {
F_6 ( V_111 ,
V_6 -> V_9 + V_10 + V_11 ) ;
F_6 ( V_112 ,
V_6 -> V_9 + V_10 + V_11 ) ;
}
F_6 ( V_31 << V_33 ,
V_6 -> V_9 + V_30 + V_11 ) ;
V_72:
F_31 ( V_6 -> V_53 ) ;
return V_44 ;
}
static bool F_45 ( struct V_2 * V_3 , void * V_113 )
{
struct V_114 * V_115 = V_113 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_50 ;
if ( V_6 -> V_36 . V_37 -> V_116 != V_115 -> V_116 )
return false ;
if ( V_3 -> V_7 != V_115 -> V_7 )
return false ;
V_50 = F_46 ( V_6 -> V_117 , V_115 -> V_7 ) ;
if ( V_50 < 0 )
return false ;
V_4 -> V_50 = V_50 ;
return true ;
}
static struct V_2 * F_47 ( struct V_118 * V_119 ,
struct V_120 * V_121 )
{
struct V_5 * V_6 = V_121 -> V_122 ;
T_7 V_123 = V_6 -> V_36 . V_124 ;
struct V_114 V_115 ;
if ( V_119 -> V_125 != 1 )
return NULL ;
V_115 . V_116 = V_121 -> V_116 ;
V_115 . V_7 = V_119 -> args [ 0 ] ;
if ( V_115 . V_7 >= V_6 -> V_126 )
return NULL ;
return F_48 ( V_123 , F_45 , & V_115 ) ;
}
static int T_6 F_49 ( struct V_127 * V_117 )
{
struct V_128 * V_129 = V_117 -> V_37 . V_116 ;
const struct V_130 * V_131 ;
const struct V_132 * V_133 ;
const struct V_134 * V_135 ;
struct V_5 * V_6 ;
struct V_136 * V_137 ;
int V_44 , V_64 ;
V_6 = F_50 ( & V_117 -> V_37 , sizeof( * V_6 ) , V_47 ) ;
if ( ! V_6 )
return - V_48 ;
V_44 = F_51 ( V_129 , L_6 , & V_6 -> V_126 ) ;
if ( V_44 ) {
F_33 ( & V_117 -> V_37 , L_7 ) ;
return V_44 ;
}
V_133 = F_52 ( V_138 , & V_117 -> V_37 ) ;
if ( V_133 )
V_131 = V_133 -> V_22 ;
else
V_131 = F_53 ( V_117 ) ;
V_135 = (struct V_134 * ) V_131 -> V_139 ;
V_6 -> type = V_135 -> type ;
V_6 -> V_27 = V_135 -> V_140 ;
V_137 = F_54 ( V_117 , V_141 , 0 ) ;
V_6 -> V_9 = F_55 ( & V_117 -> V_37 , V_137 ) ;
if ( F_56 ( V_6 -> V_9 ) )
return F_57 ( V_6 -> V_9 ) ;
V_6 -> V_53 = F_58 ( & V_117 -> V_37 , NULL ) ;
if ( F_56 ( V_6 -> V_53 ) )
return F_57 ( V_6 -> V_53 ) ;
F_59 ( V_142 , V_6 -> V_36 . V_124 ) ;
F_59 ( V_143 , V_6 -> V_36 . V_124 ) ;
F_60 ( & V_6 -> V_36 . V_144 ) ;
for ( V_64 = 0 ; V_64 < V_33 ; V_64 ++ ) {
struct V_1 * V_4 = & V_6 -> V_35 [ V_64 ] ;
V_4 -> V_6 = V_6 ;
V_4 -> V_3 . V_145 = & V_6 -> V_36 ;
F_61 ( & V_4 -> V_3 ) ;
F_62 ( & V_4 -> V_42 , F_15 ,
( unsigned long ) V_4 ) ;
F_63 ( & V_4 -> V_3 . V_128 ,
& V_6 -> V_36 . V_144 ) ;
}
V_44 = F_43 ( V_6 ) ;
if ( V_44 )
return V_44 ;
V_6 -> V_117 = V_117 ;
V_6 -> V_36 . V_37 = & V_117 -> V_37 ;
V_6 -> V_36 . V_37 -> V_146 = & V_6 -> V_146 ;
F_64 ( V_6 -> V_36 . V_37 , V_87 ) ;
V_6 -> V_36 . V_147 = F_22 ;
V_6 -> V_36 . V_148 = F_30 ;
V_6 -> V_36 . V_149 = F_40 ;
V_6 -> V_36 . V_150 = F_32 ;
V_6 -> V_36 . V_151 = F_38 ;
V_6 -> V_36 . V_152 = F_39 ;
V_6 -> V_36 . V_153 = F_42 ;
V_44 = F_65 ( & V_6 -> V_36 ) ;
if ( V_44 ) {
F_33 ( V_6 -> V_36 . V_37 , L_8 ) ;
return V_44 ;
}
V_44 = F_66 ( V_129 , F_47 , V_6 ) ;
if ( V_44 ) {
F_33 ( V_6 -> V_36 . V_37 ,
L_9 ) ;
F_67 ( & V_6 -> V_36 ) ;
}
F_68 ( V_6 -> V_36 . V_37 , L_10 ) ;
return 0 ;
}
static int T_6 F_69 ( void )
{
return F_70 ( & V_154 , F_49 ) ;
}
