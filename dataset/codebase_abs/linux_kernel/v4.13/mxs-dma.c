static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
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
static void F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
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
static void F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_23 = V_24 ;
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = V_4 -> V_3 . V_7 ;
if ( F_4 ( V_6 ) && F_5 ( V_6 ) )
F_6 ( 1 << V_7 ,
V_6 -> V_13 + V_14 + V_15 ) ;
else
F_6 ( 1 << V_7 ,
V_6 -> V_13 + V_22 + V_15 ) ;
V_4 -> V_23 = V_26 ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = V_4 -> V_3 . V_7 ;
if ( F_4 ( V_6 ) && F_5 ( V_6 ) )
F_6 ( 1 << V_7 ,
V_6 -> V_13 + V_14 + V_27 ) ;
else
F_6 ( 1 << V_7 ,
V_6 -> V_13 + V_22 + V_27 ) ;
V_4 -> V_23 = V_28 ;
return 0 ;
}
static T_2 F_17 ( struct V_29 * V_30 )
{
return F_18 ( V_30 ) ;
}
static void F_19 ( unsigned long V_31 )
{
struct V_1 * V_4 = (struct V_1 * ) V_31 ;
F_20 ( & V_4 -> V_32 , NULL ) ;
}
static int F_21 ( struct V_5 * V_6 , int V_33 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 != V_6 -> V_35 ; ++ V_34 )
if ( V_6 -> V_36 [ V_34 ] . V_37 == V_33 )
return V_34 ;
return - V_38 ;
}
static T_3 F_22 ( int V_33 , void * V_39 )
{
struct V_5 * V_6 = V_39 ;
struct V_1 * V_4 ;
T_4 V_40 ;
T_4 V_41 ;
int V_3 = F_21 ( V_6 , V_33 ) ;
if ( V_3 < 0 )
return V_42 ;
V_40 = F_8 ( V_6 -> V_13 + V_43 ) ;
V_40 = ( V_40 >> V_3 ) & 0x1 ;
F_6 ( ( 1 << V_3 ) ,
V_6 -> V_13 + V_43 + V_27 ) ;
V_41 = F_8 ( V_6 -> V_13 + V_44 ) ;
V_41 &= ( 1 << ( V_45 + V_3 ) ) | ( 1 << V_3 ) ;
V_41 = ( V_41 >> ( V_45 + V_3 ) ) + ( V_41 >> V_3 ) ;
F_6 ( ( 1 << V_3 ) ,
V_6 -> V_13 + V_44 + V_27 ) ;
V_41 -= V_41 & V_40 ;
V_4 = & V_6 -> V_36 [ V_3 ] ;
if ( V_41 ) {
F_23 ( V_6 -> V_46 . V_20 ,
L_2 , V_47 ,
V_3 ) ;
V_4 -> V_23 = V_48 ;
F_3 ( & V_4 -> V_3 ) ;
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
return V_49 ;
F_24 ( & V_4 -> V_32 ) ;
}
F_25 ( & V_4 -> V_50 ) ;
return V_49 ;
}
static int F_26 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_51 ;
V_4 -> V_52 = F_27 ( V_6 -> V_46 . V_20 ,
V_53 ,
& V_4 -> V_25 , V_54 ) ;
if ( ! V_4 -> V_52 ) {
V_51 = - V_55 ;
goto V_56;
}
V_51 = F_28 ( V_4 -> V_37 , F_22 ,
0 , L_3 , V_6 ) ;
if ( V_51 )
goto V_57;
V_51 = F_29 ( V_6 -> V_58 ) ;
if ( V_51 )
goto V_59;
F_3 ( V_3 ) ;
F_30 ( & V_4 -> V_32 , V_3 ) ;
V_4 -> V_32 . V_60 = F_17 ;
F_31 ( & V_4 -> V_32 ) ;
return 0 ;
V_59:
F_32 ( V_4 -> V_37 , V_6 ) ;
V_57:
F_33 ( V_6 -> V_46 . V_20 , V_53 ,
V_4 -> V_52 , V_4 -> V_25 ) ;
V_56:
return V_51 ;
}
static void F_34 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
F_14 ( V_3 ) ;
F_32 ( V_4 -> V_37 , V_6 ) ;
F_33 ( V_6 -> V_46 . V_20 , V_53 ,
V_4 -> V_52 , V_4 -> V_25 ) ;
F_35 ( V_6 -> V_58 ) ;
}
static struct V_29 * F_36 (
struct V_2 * V_3 , struct V_61 * V_62 ,
unsigned int V_63 , enum V_64 V_65 ,
unsigned long V_8 , void * V_66 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_67 * V_52 ;
struct V_61 * V_68 ;
T_4 V_34 , V_69 ;
T_4 * V_70 ;
bool V_71 = V_8 & V_72 ;
int V_73 = V_71 ? V_4 -> V_74 : 0 ;
if ( V_4 -> V_23 == V_28 && ! V_71 )
return NULL ;
if ( V_63 + ( V_71 ? V_73 : 0 ) > V_75 ) {
F_10 ( V_6 -> V_46 . V_20 ,
L_4 ,
V_63 , V_75 ) ;
goto V_76;
}
V_4 -> V_23 = V_28 ;
V_4 -> V_8 = 0 ;
if ( V_71 ) {
F_37 ( V_73 < 1 ) ;
V_52 = & V_4 -> V_52 [ V_73 - 1 ] ;
V_52 -> V_77 = V_4 -> V_25 + sizeof( * V_52 ) * V_73 ;
V_52 -> V_78 |= V_79 ;
V_52 -> V_78 &= ~ V_80 ;
V_52 -> V_78 &= ~ V_81 ;
} else {
V_73 = 0 ;
}
if ( V_65 == V_82 ) {
V_52 = & V_4 -> V_52 [ V_73 ++ ] ;
V_70 = ( T_4 * ) V_62 ;
for ( V_69 = 0 ; V_69 < V_63 ; )
V_52 -> V_83 [ V_69 ++ ] = * V_70 ++ ;
V_52 -> V_78 = 0 ;
V_52 -> V_78 |= V_80 ;
V_52 -> V_78 |= V_81 ;
if ( V_8 & V_84 )
V_52 -> V_78 |= V_85 ;
V_52 -> V_78 |= V_86 ;
V_52 -> V_78 |= V_87 ;
V_52 -> V_78 |= F_38 ( V_63 , V_88 ) ;
V_52 -> V_78 |= F_38 ( V_89 , V_90 ) ;
} else {
F_39 (sgl, sg, sg_len, i) {
if ( F_40 ( V_68 ) > V_91 ) {
F_10 ( V_6 -> V_46 . V_20 , L_5 ,
F_40 ( V_68 ) , V_91 ) ;
goto V_76;
}
V_52 = & V_4 -> V_52 [ V_73 ++ ] ;
V_52 -> V_77 = V_4 -> V_25 + sizeof( * V_52 ) * V_73 ;
V_52 -> V_92 = V_68 -> V_93 ;
V_52 -> V_94 = F_40 ( V_68 ) ;
V_52 -> V_78 = 0 ;
V_52 -> V_78 |= V_79 ;
V_52 -> V_78 |= V_86 ;
V_52 -> V_78 |= V_87 ;
V_52 -> V_78 |= F_38 ( V_65 == V_95 ?
V_96 : V_97 ,
V_90 ) ;
if ( V_34 + 1 == V_63 ) {
V_52 -> V_78 &= ~ V_79 ;
V_52 -> V_78 |= V_80 ;
V_52 -> V_78 |= V_81 ;
if ( V_8 & V_84 )
V_52 -> V_78 |= V_85 ;
}
}
}
V_4 -> V_74 = V_73 ;
return & V_4 -> V_32 ;
V_76:
V_4 -> V_23 = V_48 ;
return NULL ;
}
static struct V_29 * F_41 (
struct V_2 * V_3 , T_5 V_98 , T_6 V_99 ,
T_6 V_100 , enum V_64 V_65 ,
unsigned long V_8 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_4 V_101 = V_99 / V_100 ;
T_4 V_34 = 0 , V_102 = 0 ;
if ( V_4 -> V_23 == V_28 )
return NULL ;
V_4 -> V_23 = V_28 ;
V_4 -> V_8 |= V_10 ;
V_4 -> V_8 |= V_9 ;
if ( V_101 > V_75 ) {
F_10 ( V_6 -> V_46 . V_20 ,
L_4 ,
V_101 , V_75 ) ;
goto V_76;
}
if ( V_100 > V_91 ) {
F_10 ( V_6 -> V_46 . V_20 ,
L_6 ,
V_100 , V_91 ) ;
goto V_76;
}
while ( V_102 < V_99 ) {
struct V_67 * V_52 = & V_4 -> V_52 [ V_34 ] ;
if ( V_34 + 1 == V_101 )
V_52 -> V_77 = V_4 -> V_25 ;
else
V_52 -> V_77 = V_4 -> V_25 + sizeof( * V_52 ) * ( V_34 + 1 ) ;
V_52 -> V_92 = V_98 ;
V_52 -> V_94 = V_100 ;
V_52 -> V_78 = 0 ;
V_52 -> V_78 |= V_79 ;
V_52 -> V_78 |= V_80 ;
V_52 -> V_78 |= V_86 ;
V_52 -> V_78 |= V_87 ;
V_52 -> V_78 |= V_81 ;
V_52 -> V_78 |= F_38 ( V_65 == V_95 ?
V_96 : V_97 , V_90 ) ;
V_98 += V_100 ;
V_102 += V_100 ;
V_34 ++ ;
}
V_4 -> V_74 = V_34 ;
return & V_4 -> V_32 ;
V_76:
V_4 -> V_23 = V_48 ;
return NULL ;
}
static int F_42 ( struct V_2 * V_3 )
{
F_3 ( V_3 ) ;
F_14 ( V_3 ) ;
return 0 ;
}
static enum V_103 F_43 ( struct V_2 * V_3 ,
T_2 V_104 , struct V_105 * V_106 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_4 V_107 = 0 ;
if ( V_4 -> V_23 == V_28 &&
V_4 -> V_8 & V_10 ) {
struct V_67 * V_108 ;
T_4 V_109 ;
V_108 = & V_4 -> V_52 [ V_4 -> V_74 - 1 ] ;
V_107 = V_108 -> V_94 + V_108 -> V_92 ;
V_109 = F_8 ( V_6 -> V_13 +
F_44 ( V_6 , V_3 -> V_7 ) ) ;
V_107 -= V_109 ;
}
F_45 ( V_106 , V_3 -> V_110 , V_3 -> V_104 ,
V_107 ) ;
return V_4 -> V_23 ;
}
static int T_7 F_46 ( struct V_5 * V_6 )
{
int V_51 ;
V_51 = F_29 ( V_6 -> V_58 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_47 ( V_6 -> V_13 ) ;
if ( V_51 )
goto V_76;
if ( F_4 ( V_6 ) ) {
F_6 ( V_111 ,
V_6 -> V_13 + V_14 + V_15 ) ;
F_6 ( V_112 ,
V_6 -> V_13 + V_14 + V_15 ) ;
}
F_6 ( V_113 << V_45 ,
V_6 -> V_13 + V_43 + V_15 ) ;
V_76:
F_35 ( V_6 -> V_58 ) ;
return V_51 ;
}
static bool F_48 ( struct V_2 * V_3 , void * V_114 )
{
struct V_115 * V_116 = V_114 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_37 ;
if ( V_6 -> V_46 . V_20 -> V_117 != V_116 -> V_117 )
return false ;
if ( V_3 -> V_7 != V_116 -> V_7 )
return false ;
V_37 = F_49 ( V_6 -> V_19 , V_116 -> V_7 ) ;
if ( V_37 < 0 )
return false ;
V_4 -> V_37 = V_37 ;
return true ;
}
static struct V_2 * F_50 ( struct V_118 * V_119 ,
struct V_120 * V_121 )
{
struct V_5 * V_6 = V_121 -> V_122 ;
T_8 V_123 = V_6 -> V_46 . V_124 ;
struct V_115 V_116 ;
if ( V_119 -> V_125 != 1 )
return NULL ;
V_116 . V_117 = V_121 -> V_117 ;
V_116 . V_7 = V_119 -> args [ 0 ] ;
if ( V_116 . V_7 >= V_6 -> V_35 )
return NULL ;
return F_51 ( V_123 , F_48 , & V_116 ) ;
}
static int T_7 F_52 ( struct V_126 * V_19 )
{
struct V_127 * V_128 = V_19 -> V_20 . V_117 ;
const struct V_129 * V_130 ;
const struct V_131 * V_132 ;
const struct V_133 * V_134 ;
struct V_5 * V_6 ;
struct V_135 * V_136 ;
int V_51 , V_34 ;
V_6 = F_53 ( & V_19 -> V_20 , sizeof( * V_6 ) , V_54 ) ;
if ( ! V_6 )
return - V_55 ;
V_51 = F_54 ( V_128 , L_7 , & V_6 -> V_35 ) ;
if ( V_51 ) {
F_10 ( & V_19 -> V_20 , L_8 ) ;
return V_51 ;
}
V_132 = F_55 ( V_137 , & V_19 -> V_20 ) ;
if ( V_132 )
V_130 = V_132 -> V_31 ;
else
V_130 = F_56 ( V_19 ) ;
V_134 = (struct V_133 * ) V_130 -> V_138 ;
V_6 -> type = V_134 -> type ;
V_6 -> V_39 = V_134 -> V_139 ;
V_136 = F_57 ( V_19 , V_140 , 0 ) ;
V_6 -> V_13 = F_58 ( & V_19 -> V_20 , V_136 ) ;
if ( F_59 ( V_6 -> V_13 ) )
return F_60 ( V_6 -> V_13 ) ;
V_6 -> V_58 = F_61 ( & V_19 -> V_20 , NULL ) ;
if ( F_59 ( V_6 -> V_58 ) )
return F_60 ( V_6 -> V_58 ) ;
F_62 ( V_141 , V_6 -> V_46 . V_124 ) ;
F_62 ( V_142 , V_6 -> V_46 . V_124 ) ;
F_63 ( & V_6 -> V_46 . V_143 ) ;
for ( V_34 = 0 ; V_34 < V_45 ; V_34 ++ ) {
struct V_1 * V_4 = & V_6 -> V_36 [ V_34 ] ;
V_4 -> V_6 = V_6 ;
V_4 -> V_3 . V_144 = & V_6 -> V_46 ;
F_64 ( & V_4 -> V_3 ) ;
F_65 ( & V_4 -> V_50 , F_19 ,
( unsigned long ) V_4 ) ;
F_66 ( & V_4 -> V_3 . V_127 ,
& V_6 -> V_46 . V_143 ) ;
}
V_51 = F_46 ( V_6 ) ;
if ( V_51 )
return V_51 ;
V_6 -> V_19 = V_19 ;
V_6 -> V_46 . V_20 = & V_19 -> V_20 ;
V_6 -> V_46 . V_20 -> V_145 = & V_6 -> V_145 ;
F_67 ( V_6 -> V_46 . V_20 , V_91 ) ;
V_6 -> V_46 . V_146 = F_26 ;
V_6 -> V_46 . V_147 = F_34 ;
V_6 -> V_46 . V_148 = F_43 ;
V_6 -> V_46 . V_149 = F_36 ;
V_6 -> V_46 . V_150 = F_41 ;
V_6 -> V_46 . V_151 = F_15 ;
V_6 -> V_46 . V_152 = F_16 ;
V_6 -> V_46 . V_153 = F_42 ;
V_6 -> V_46 . V_154 = F_68 ( V_155 ) ;
V_6 -> V_46 . V_156 = F_68 ( V_155 ) ;
V_6 -> V_46 . V_157 = F_68 ( V_95 ) | F_68 ( V_158 ) ;
V_6 -> V_46 . V_159 = V_160 ;
V_6 -> V_46 . V_161 = F_11 ;
V_51 = F_69 ( & V_6 -> V_46 ) ;
if ( V_51 ) {
F_10 ( V_6 -> V_46 . V_20 , L_9 ) ;
return V_51 ;
}
V_51 = F_70 ( V_128 , F_50 , V_6 ) ;
if ( V_51 ) {
F_10 ( V_6 -> V_46 . V_20 ,
L_10 ) ;
F_71 ( & V_6 -> V_46 ) ;
}
F_72 ( V_6 -> V_46 . V_20 , L_11 ) ;
return 0 ;
}
static int T_7 F_73 ( void )
{
return F_74 ( & V_162 , F_52 ) ;
}
