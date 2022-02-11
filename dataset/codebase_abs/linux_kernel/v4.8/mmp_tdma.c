static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_3 , V_2 -> V_4 + V_5 ) ;
F_2 ( F_3 ( V_2 -> V_4 + V_6 ) | V_7 ,
V_2 -> V_4 + V_6 ) ;
}
static void F_4 ( struct V_1 * V_2 , bool V_8 )
{
if ( V_8 )
F_2 ( V_9 , V_2 -> V_4 + V_10 ) ;
else
F_2 ( 0 , V_2 -> V_4 + V_10 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 -> V_4 + V_6 ) | V_11 ,
V_2 -> V_4 + V_6 ) ;
V_2 -> V_12 = V_13 ;
}
static int F_6 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
T_2 V_16 ;
V_16 = F_3 ( V_2 -> V_4 + V_6 ) ;
V_16 |= V_17 ;
V_16 &= ~ V_11 ;
F_2 ( V_16 , V_2 -> V_4 + V_6 ) ;
V_2 -> V_12 = V_18 ;
return 0 ;
}
static int F_8 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
F_2 ( F_3 ( V_2 -> V_4 + V_6 ) | V_11 ,
V_2 -> V_4 + V_6 ) ;
V_2 -> V_12 = V_13 ;
return 0 ;
}
static int F_9 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
F_2 ( F_3 ( V_2 -> V_4 + V_6 ) & ~ V_11 ,
V_2 -> V_4 + V_6 ) ;
V_2 -> V_12 = V_19 ;
return 0 ;
}
static int F_10 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
unsigned int V_16 = 0 ;
F_6 ( V_15 ) ;
if ( V_2 -> V_20 == V_21 )
V_16 = V_22 | V_23 ;
else if ( V_2 -> V_20 == V_24 )
V_16 = V_25 | V_26 ;
if ( V_2 -> type == V_27 ) {
V_16 |= V_28 ;
switch ( V_2 -> V_29 ) {
case 4 :
V_16 |= V_30 ;
break;
case 8 :
V_16 |= V_31 ;
break;
case 16 :
V_16 |= V_32 ;
break;
case 32 :
V_16 |= V_33 ;
break;
case 64 :
V_16 |= V_34 ;
break;
case 128 :
V_16 |= V_35 ;
break;
default:
F_11 ( V_2 -> V_36 , L_1 ) ;
return - V_37 ;
}
switch ( V_2 -> V_38 ) {
case V_39 :
V_16 |= V_40 ;
break;
case V_41 :
V_16 |= V_42 ;
break;
case V_43 :
V_16 |= V_44 ;
break;
default:
F_11 ( V_2 -> V_36 , L_2 ) ;
return - V_37 ;
}
} else if ( V_2 -> type == V_45 ) {
V_16 |= V_46 ;
switch ( V_2 -> V_29 ) {
case 1 :
V_16 |= V_47 ;
break;
case 2 :
V_16 |= V_48 ;
break;
case 4 :
V_16 |= V_49 ;
break;
case 8 :
V_16 |= V_50 ;
break;
case 16 :
V_16 |= V_51 ;
break;
case 32 :
V_16 |= V_52 ;
break;
default:
F_11 ( V_2 -> V_36 , L_1 ) ;
return - V_37 ;
}
}
F_2 ( V_16 , V_2 -> V_4 + V_6 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
T_2 V_53 = F_3 ( V_2 -> V_4 + V_54 ) ;
if ( V_53 & V_55 ) {
V_53 &= ~ V_55 ;
F_2 ( V_53 , V_2 -> V_4 + V_54 ) ;
return 0 ;
}
return - V_56 ;
}
static T_3 F_13 ( struct V_1 * V_2 )
{
T_3 V_53 ;
if ( V_2 -> V_57 == 0 ) {
V_53 = F_14 ( V_2 -> V_4 + V_58 ) ;
V_53 -= V_2 -> V_59 [ 0 ] . V_60 ;
} else if ( V_2 -> V_57 == 1 ) {
V_53 = F_14 ( V_2 -> V_4 + V_61 ) ;
V_53 -= V_2 -> V_59 [ 0 ] . V_62 ;
} else
return - V_37 ;
return V_53 ;
}
static T_4 F_15 ( int V_63 , void * V_64 )
{
struct V_1 * V_2 = V_64 ;
if ( F_12 ( V_2 ) == 0 ) {
F_16 ( & V_2 -> V_65 ) ;
return V_66 ;
} else
return V_67 ;
}
static T_4 F_17 ( int V_63 , void * V_64 )
{
struct V_68 * V_69 = V_64 ;
int V_70 , V_71 ;
int V_72 = 0 ;
for ( V_70 = 0 ; V_70 < V_73 ; V_70 ++ ) {
struct V_1 * V_2 = V_69 -> V_2 [ V_70 ] ;
V_71 = F_15 ( V_63 , V_2 ) ;
if ( V_71 == V_66 )
V_72 ++ ;
}
if ( V_72 )
return V_66 ;
else
return V_67 ;
}
static void F_18 ( unsigned long V_74 )
{
struct V_1 * V_2 = (struct V_1 * ) V_74 ;
if ( V_2 -> V_75 . V_76 )
V_2 -> V_75 . V_76 ( V_2 -> V_75 . V_77 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_78 * V_79 ;
int V_80 = V_2 -> V_81 * sizeof( struct V_82 ) ;
V_79 = V_2 -> V_83 ;
if ( V_79 && V_2 -> V_59 )
F_20 ( V_79 , ( unsigned long ) V_2 -> V_59 ,
V_80 ) ;
V_2 -> V_59 = NULL ;
return;
}
static T_5 F_21 ( struct V_84 * V_85 )
{
struct V_1 * V_2 = F_7 ( V_85 -> V_15 ) ;
F_1 ( V_2 , V_2 -> V_86 ) ;
return 0 ;
}
static int F_22 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
int V_71 ;
F_23 ( & V_2 -> V_75 , V_15 ) ;
V_2 -> V_75 . V_87 = F_21 ;
if ( V_2 -> V_63 ) {
V_71 = F_24 ( V_2 -> V_36 , V_2 -> V_63 ,
F_15 , 0 , L_3 , V_2 ) ;
if ( V_71 )
return V_71 ;
}
return 1 ;
}
static void F_25 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
if ( V_2 -> V_63 )
F_26 ( V_2 -> V_36 , V_2 -> V_63 , V_2 ) ;
F_19 ( V_2 ) ;
return;
}
static struct V_82 * F_27 ( struct V_1 * V_2 )
{
struct V_78 * V_79 ;
int V_80 = V_2 -> V_81 * sizeof( struct V_82 ) ;
V_79 = V_2 -> V_83 ;
if ( ! V_79 )
return NULL ;
V_2 -> V_59 = F_28 ( V_79 , V_80 , & V_2 -> V_86 ) ;
return V_2 -> V_59 ;
}
static struct V_84 * F_29 (
struct V_14 * V_15 , T_1 V_88 , T_3 V_89 ,
T_3 V_90 , enum V_91 V_92 ,
unsigned long V_93 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
struct V_82 * V_75 ;
int V_94 = V_89 / V_90 ;
int V_70 = 0 , V_95 = 0 ;
if ( V_2 -> V_12 != V_18 )
return NULL ;
if ( V_90 > V_96 ) {
F_11 ( V_2 -> V_36 ,
L_4 ,
V_90 , V_96 ) ;
goto V_97;
}
V_2 -> V_12 = V_13 ;
V_2 -> V_81 = V_94 ;
V_75 = F_27 ( V_2 ) ;
if ( ! V_75 )
goto V_97;
while ( V_95 < V_89 ) {
V_75 = & V_2 -> V_59 [ V_70 ] ;
if ( V_70 + 1 == V_94 )
V_75 -> V_98 = V_2 -> V_86 ;
else
V_75 -> V_98 = V_2 -> V_86 +
sizeof( * V_75 ) * ( V_70 + 1 ) ;
if ( V_92 == V_21 ) {
V_75 -> V_60 = V_88 ;
V_75 -> V_62 = V_2 -> V_99 ;
} else {
V_75 -> V_60 = V_2 -> V_99 ;
V_75 -> V_62 = V_88 ;
}
V_75 -> V_100 = V_90 ;
V_88 += V_90 ;
V_95 += V_90 ;
V_70 ++ ;
}
if ( V_93 & V_101 )
F_4 ( V_2 , true ) ;
V_2 -> V_89 = V_89 ;
V_2 -> V_90 = V_90 ;
V_2 -> V_102 = 0 ;
return & V_2 -> V_75 ;
V_97:
V_2 -> V_12 = V_103 ;
return NULL ;
}
static int F_30 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
F_6 ( V_15 ) ;
F_4 ( V_2 , false ) ;
return 0 ;
}
static int F_31 ( struct V_14 * V_15 ,
struct V_104 * V_105 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
if ( V_105 -> V_92 == V_24 ) {
V_2 -> V_99 = V_105 -> V_60 ;
V_2 -> V_29 = V_105 -> V_106 ;
V_2 -> V_38 = V_105 -> V_107 ;
} else {
V_2 -> V_99 = V_105 -> V_62 ;
V_2 -> V_29 = V_105 -> V_108 ;
V_2 -> V_38 = V_105 -> V_109 ;
}
V_2 -> V_20 = V_105 -> V_92 ;
return F_10 ( V_15 ) ;
}
static enum V_110 F_32 ( struct V_14 * V_15 ,
T_5 V_111 , struct V_112 * V_113 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
V_2 -> V_102 = F_13 ( V_2 ) ;
F_33 ( V_113 , V_15 -> V_114 , V_15 -> V_111 ,
V_2 -> V_89 - V_2 -> V_102 ) ;
return V_2 -> V_12 ;
}
static void F_34 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
F_5 ( V_2 ) ;
}
static int F_35 ( struct V_115 * V_116 )
{
struct V_68 * V_69 = F_36 ( V_116 ) ;
F_37 ( & V_69 -> V_117 ) ;
return 0 ;
}
static int F_38 ( struct V_68 * V_69 ,
int V_57 , int V_63 ,
int type , struct V_78 * V_83 )
{
struct V_1 * V_2 ;
if ( V_57 >= V_73 ) {
F_11 ( V_69 -> V_36 , L_5 ) ;
return - V_37 ;
}
V_2 = F_39 ( V_69 -> V_36 , sizeof( * V_2 ) , V_118 ) ;
if ( ! V_2 )
return - V_119 ;
if ( V_63 )
V_2 -> V_63 = V_63 ;
V_2 -> V_36 = V_69 -> V_36 ;
V_2 -> V_15 . V_117 = & V_69 -> V_117 ;
V_2 -> V_57 = V_57 ;
V_2 -> type = type ;
V_2 -> V_4 = V_69 -> V_120 + V_57 * 4 ;
V_2 -> V_83 = V_83 ;
V_2 -> V_12 = V_18 ;
V_69 -> V_2 [ V_2 -> V_57 ] = V_2 ;
F_40 ( & V_2 -> V_65 , F_18 , ( unsigned long ) V_2 ) ;
F_41 ( & V_2 -> V_15 . V_121 ,
& V_69 -> V_117 . V_122 ) ;
return 0 ;
}
static bool F_42 ( struct V_14 * V_15 , void * V_123 )
{
struct V_124 * V_125 = V_123 ;
struct V_1 * V_2 = F_7 ( V_15 ) ;
struct V_126 * V_127 = V_2 -> V_15 . V_117 ;
if ( V_127 -> V_36 -> V_128 != V_125 -> V_128 )
return false ;
if ( V_15 -> V_129 != V_125 -> V_129 )
return false ;
return true ;
}
static struct V_14 * F_43 ( struct V_130 * V_131 ,
struct V_132 * V_133 )
{
struct V_68 * V_69 = V_133 -> V_134 ;
T_6 V_135 = V_69 -> V_117 . V_136 ;
struct V_124 V_125 ;
if ( V_131 -> V_137 != 1 )
return NULL ;
V_125 . V_128 = V_133 -> V_128 ;
V_125 . V_129 = V_131 -> args [ 0 ] ;
if ( V_125 . V_129 >= V_73 )
return NULL ;
return F_44 ( V_135 , F_42 , & V_125 ) ;
}
static int F_45 ( struct V_115 * V_116 )
{
enum V_138 type ;
const struct V_139 * V_140 ;
struct V_68 * V_69 ;
struct V_141 * V_142 ;
int V_70 , V_71 ;
int V_63 = 0 , V_72 = 0 ;
int V_143 = V_73 ;
struct V_78 * V_83 = NULL ;
V_140 = F_46 ( V_144 , & V_116 -> V_36 ) ;
if ( V_140 )
type = (enum V_138 ) V_140 -> V_74 ;
else
type = F_47 ( V_116 ) -> V_145 ;
V_69 = F_39 ( & V_116 -> V_36 , sizeof( * V_69 ) , V_118 ) ;
if ( ! V_69 )
return - V_119 ;
V_69 -> V_36 = & V_116 -> V_36 ;
for ( V_70 = 0 ; V_70 < V_143 ; V_70 ++ ) {
if ( F_48 ( V_116 , V_70 ) > 0 )
V_72 ++ ;
}
V_142 = F_49 ( V_116 , V_146 , 0 ) ;
V_69 -> V_120 = F_50 ( & V_116 -> V_36 , V_142 ) ;
if ( F_51 ( V_69 -> V_120 ) )
return F_52 ( V_69 -> V_120 ) ;
F_53 ( & V_69 -> V_117 . V_122 ) ;
if ( V_116 -> V_36 . V_128 )
V_83 = F_54 ( V_116 -> V_36 . V_128 , L_6 , 0 ) ;
else
V_83 = F_55 ( L_6 ) ;
if ( ! V_83 ) {
F_11 ( & V_116 -> V_36 , L_7 ) ;
return - V_119 ;
}
if ( V_72 != V_143 ) {
V_63 = F_48 ( V_116 , 0 ) ;
V_71 = F_24 ( & V_116 -> V_36 , V_63 ,
F_17 , 0 , L_3 , V_69 ) ;
if ( V_71 )
return V_71 ;
}
for ( V_70 = 0 ; V_70 < V_143 ; V_70 ++ ) {
V_63 = ( V_72 != V_143 ) ? 0 : F_48 ( V_116 , V_70 ) ;
V_71 = F_38 ( V_69 , V_70 , V_63 , type , V_83 ) ;
if ( V_71 )
return V_71 ;
}
F_56 ( V_147 , V_69 -> V_117 . V_136 ) ;
F_56 ( V_148 , V_69 -> V_117 . V_136 ) ;
V_69 -> V_117 . V_36 = & V_116 -> V_36 ;
V_69 -> V_117 . V_149 =
F_22 ;
V_69 -> V_117 . V_150 =
F_25 ;
V_69 -> V_117 . V_151 = F_29 ;
V_69 -> V_117 . V_152 = F_32 ;
V_69 -> V_117 . V_153 = F_34 ;
V_69 -> V_117 . V_154 = F_31 ;
V_69 -> V_117 . V_155 = F_9 ;
V_69 -> V_117 . V_156 = F_8 ;
V_69 -> V_117 . V_157 = F_30 ;
V_69 -> V_117 . V_158 = V_159 ;
F_57 ( & V_116 -> V_36 , F_58 ( 64 ) ) ;
F_59 ( V_116 , V_69 ) ;
V_71 = F_60 ( & V_69 -> V_117 ) ;
if ( V_71 ) {
F_11 ( V_69 -> V_117 . V_36 , L_8 ) ;
return V_71 ;
}
if ( V_116 -> V_36 . V_128 ) {
V_71 = F_61 ( V_116 -> V_36 . V_128 ,
F_43 , V_69 ) ;
if ( V_71 ) {
F_11 ( V_69 -> V_117 . V_36 ,
L_9 ) ;
F_37 ( & V_69 -> V_117 ) ;
}
}
F_62 ( V_69 -> V_117 . V_36 , L_10 ) ;
return 0 ;
}
