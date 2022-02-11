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
static void F_6 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 -> V_4 + V_6 ) & ~ V_11 ,
V_2 -> V_4 + V_6 ) ;
V_2 -> V_12 = V_14 ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 -> V_4 + V_6 ) | V_11 ,
V_2 -> V_4 + V_6 ) ;
V_2 -> V_12 = V_13 ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 -> V_4 + V_6 ) & ~ V_11 ,
V_2 -> V_4 + V_6 ) ;
V_2 -> V_12 = V_15 ;
}
static int F_9 ( struct V_1 * V_2 )
{
unsigned int V_16 = 0 ;
F_6 ( V_2 ) ;
if ( V_2 -> V_17 == V_18 )
V_16 = V_19 | V_20 ;
else if ( V_2 -> V_17 == V_21 )
V_16 = V_22 | V_23 ;
if ( V_2 -> type == V_24 ) {
V_16 |= V_25 ;
switch ( V_2 -> V_26 ) {
case 4 :
V_16 |= V_27 ;
break;
case 8 :
V_16 |= V_28 ;
break;
case 16 :
V_16 |= V_29 ;
break;
case 32 :
V_16 |= V_30 ;
break;
case 64 :
V_16 |= V_31 ;
break;
case 128 :
V_16 |= V_32 ;
break;
default:
F_10 ( V_2 -> V_33 , L_1 ) ;
return - V_34 ;
}
switch ( V_2 -> V_35 ) {
case V_36 :
V_16 |= V_37 ;
break;
case V_38 :
V_16 |= V_39 ;
break;
case V_40 :
V_16 |= V_41 ;
break;
default:
F_10 ( V_2 -> V_33 , L_2 ) ;
return - V_34 ;
}
} else if ( V_2 -> type == V_42 ) {
V_16 |= V_43 ;
switch ( V_2 -> V_26 ) {
case 1 :
V_16 |= V_44 ;
break;
case 2 :
V_16 |= V_45 ;
break;
case 4 :
V_16 |= V_46 ;
break;
case 8 :
V_16 |= V_47 ;
break;
case 16 :
V_16 |= V_48 ;
break;
case 32 :
V_16 |= V_49 ;
break;
default:
F_10 ( V_2 -> V_33 , L_1 ) ;
return - V_34 ;
}
}
F_2 ( V_16 , V_2 -> V_4 + V_6 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
T_2 V_50 = F_3 ( V_2 -> V_4 + V_51 ) ;
if ( V_50 & V_52 ) {
V_50 &= ~ V_52 ;
F_2 ( V_50 , V_2 -> V_4 + V_51 ) ;
return 0 ;
}
return - V_53 ;
}
static T_3 F_12 ( int V_54 , void * V_55 )
{
struct V_1 * V_2 = V_55 ;
if ( F_11 ( V_2 ) == 0 ) {
V_2 -> V_56 = ( V_2 -> V_56 + V_2 -> V_57 ) % V_2 -> V_58 ;
F_13 ( & V_2 -> V_59 ) ;
return V_60 ;
} else
return V_61 ;
}
static T_3 F_14 ( int V_54 , void * V_55 )
{
struct V_62 * V_63 = V_55 ;
int V_64 , V_65 ;
int V_66 = 0 ;
for ( V_64 = 0 ; V_64 < V_67 ; V_64 ++ ) {
struct V_1 * V_2 = V_63 -> V_2 [ V_64 ] ;
V_65 = F_12 ( V_54 , V_2 ) ;
if ( V_65 == V_60 )
V_66 ++ ;
}
if ( V_66 )
return V_60 ;
else
return V_61 ;
}
static void F_15 ( unsigned long V_68 )
{
struct V_1 * V_2 = (struct V_1 * ) V_68 ;
if ( V_2 -> V_69 . V_70 )
V_2 -> V_69 . V_70 ( V_2 -> V_69 . V_71 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_72 * V_73 ;
int V_74 = V_2 -> V_75 * sizeof( struct V_76 ) ;
V_73 = V_2 -> V_77 ;
if ( V_2 -> V_78 )
F_17 ( V_73 , ( unsigned long ) V_2 -> V_78 ,
V_74 ) ;
V_2 -> V_78 = NULL ;
return;
}
static T_4 F_18 ( struct V_79 * V_80 )
{
struct V_1 * V_2 = F_19 ( V_80 -> V_81 ) ;
F_1 ( V_2 , V_2 -> V_82 ) ;
return 0 ;
}
static int F_20 ( struct V_83 * V_81 )
{
struct V_1 * V_2 = F_19 ( V_81 ) ;
int V_65 ;
F_21 ( & V_2 -> V_69 , V_81 ) ;
V_2 -> V_69 . V_84 = F_18 ;
if ( V_2 -> V_54 ) {
V_65 = F_22 ( V_2 -> V_33 , V_2 -> V_54 ,
F_12 , 0 , L_3 , V_2 ) ;
if ( V_65 )
return V_65 ;
}
return 1 ;
}
static void F_23 ( struct V_83 * V_81 )
{
struct V_1 * V_2 = F_19 ( V_81 ) ;
if ( V_2 -> V_54 )
F_24 ( V_2 -> V_33 , V_2 -> V_54 , V_2 ) ;
F_16 ( V_2 ) ;
return;
}
struct V_76 * F_25 ( struct V_1 * V_2 )
{
struct V_72 * V_73 ;
int V_74 = V_2 -> V_75 * sizeof( struct V_76 ) ;
V_73 = V_2 -> V_77 ;
if ( ! V_73 )
return NULL ;
V_2 -> V_78 = F_26 ( V_73 , V_74 , & V_2 -> V_82 ) ;
return V_2 -> V_78 ;
}
static struct V_79 * F_27 (
struct V_83 * V_81 , T_1 V_85 , T_5 V_58 ,
T_5 V_57 , enum V_86 V_87 ,
unsigned long V_88 )
{
struct V_1 * V_2 = F_19 ( V_81 ) ;
struct V_76 * V_69 ;
int V_89 = V_58 / V_57 ;
int V_64 = 0 , V_90 = 0 ;
if ( V_2 -> V_12 != V_14 )
return NULL ;
if ( V_57 > V_91 ) {
F_10 ( V_2 -> V_33 ,
L_4 ,
V_57 , V_91 ) ;
goto V_92;
}
V_2 -> V_12 = V_13 ;
V_2 -> V_75 = V_89 ;
V_69 = F_25 ( V_2 ) ;
if ( ! V_69 )
goto V_92;
while ( V_90 < V_58 ) {
V_69 = & V_2 -> V_78 [ V_64 ] ;
if ( V_64 + 1 == V_89 )
V_69 -> V_93 = V_2 -> V_82 ;
else
V_69 -> V_93 = V_2 -> V_82 +
sizeof( * V_69 ) * ( V_64 + 1 ) ;
if ( V_87 == V_18 ) {
V_69 -> V_94 = V_85 ;
V_69 -> V_95 = V_2 -> V_96 ;
} else {
V_69 -> V_94 = V_2 -> V_96 ;
V_69 -> V_95 = V_85 ;
}
V_69 -> V_97 = V_57 ;
V_85 += V_57 ;
V_90 += V_57 ;
V_64 ++ ;
}
if ( V_88 & V_98 )
F_4 ( V_2 , true ) ;
V_2 -> V_58 = V_58 ;
V_2 -> V_57 = V_57 ;
V_2 -> V_56 = 0 ;
return & V_2 -> V_69 ;
V_92:
V_2 -> V_12 = V_99 ;
return NULL ;
}
static int F_28 ( struct V_83 * V_81 , enum V_100 V_101 ,
unsigned long V_102 )
{
struct V_1 * V_2 = F_19 ( V_81 ) ;
struct V_103 * V_104 = ( void * ) V_102 ;
int V_65 = 0 ;
switch ( V_101 ) {
case V_105 :
F_6 ( V_2 ) ;
F_4 ( V_2 , false ) ;
break;
case V_106 :
F_8 ( V_2 ) ;
break;
case V_107 :
F_7 ( V_2 ) ;
break;
case V_108 :
if ( V_104 -> V_87 == V_21 ) {
V_2 -> V_96 = V_104 -> V_94 ;
V_2 -> V_26 = V_104 -> V_109 ;
V_2 -> V_35 = V_104 -> V_110 ;
} else {
V_2 -> V_96 = V_104 -> V_95 ;
V_2 -> V_26 = V_104 -> V_111 ;
V_2 -> V_35 = V_104 -> V_112 ;
}
V_2 -> V_17 = V_104 -> V_87 ;
return F_9 ( V_2 ) ;
default:
V_65 = - V_113 ;
}
return V_65 ;
}
static enum V_114 F_29 ( struct V_83 * V_81 ,
T_4 V_115 , struct V_116 * V_117 )
{
struct V_1 * V_2 = F_19 ( V_81 ) ;
F_30 ( V_117 , V_81 -> V_118 , V_81 -> V_115 ,
V_2 -> V_58 - V_2 -> V_56 ) ;
return V_2 -> V_12 ;
}
static void F_31 ( struct V_83 * V_81 )
{
struct V_1 * V_2 = F_19 ( V_81 ) ;
F_5 ( V_2 ) ;
}
static int F_32 ( struct V_119 * V_120 )
{
struct V_62 * V_63 = F_33 ( V_120 ) ;
F_34 ( & V_63 -> V_121 ) ;
return 0 ;
}
static int F_35 ( struct V_62 * V_63 ,
int V_122 , int V_54 ,
int type , struct V_72 * V_77 )
{
struct V_1 * V_2 ;
if ( V_122 >= V_67 ) {
F_10 ( V_63 -> V_33 , L_5 ) ;
return - V_34 ;
}
V_2 = F_36 ( V_63 -> V_33 , sizeof( * V_2 ) , V_123 ) ;
if ( ! V_2 ) {
F_10 ( V_63 -> V_33 , L_6 ) ;
return - V_124 ;
}
if ( V_54 )
V_2 -> V_54 = V_54 ;
V_2 -> V_33 = V_63 -> V_33 ;
V_2 -> V_81 . V_121 = & V_63 -> V_121 ;
V_2 -> V_122 = V_122 ;
V_2 -> type = type ;
V_2 -> V_4 = V_63 -> V_125 + V_122 * 4 ;
V_2 -> V_77 = V_77 ;
V_2 -> V_12 = V_14 ;
V_63 -> V_2 [ V_2 -> V_122 ] = V_2 ;
F_37 ( & V_2 -> V_59 , F_15 , ( unsigned long ) V_2 ) ;
F_38 ( & V_2 -> V_81 . V_126 ,
& V_63 -> V_121 . V_127 ) ;
return 0 ;
}
static bool F_39 ( struct V_83 * V_81 , void * V_128 )
{
struct V_129 * V_130 = V_128 ;
struct V_1 * V_2 = F_19 ( V_81 ) ;
struct V_131 * V_132 = V_2 -> V_81 . V_121 ;
if ( V_132 -> V_33 -> V_133 != V_130 -> V_133 )
return false ;
if ( V_81 -> V_134 != V_130 -> V_134 )
return false ;
return true ;
}
struct V_83 * F_40 ( struct V_135 * V_136 ,
struct V_137 * V_138 )
{
struct V_62 * V_63 = V_138 -> V_139 ;
T_6 V_140 = V_63 -> V_121 . V_141 ;
struct V_129 V_130 ;
if ( V_136 -> V_142 != 1 )
return NULL ;
V_130 . V_133 = V_138 -> V_133 ;
V_130 . V_134 = V_136 -> args [ 0 ] ;
if ( V_130 . V_134 >= V_67 )
return NULL ;
return F_41 ( V_140 , F_39 , & V_130 ) ;
}
static int F_42 ( struct V_119 * V_120 )
{
enum V_143 type ;
const struct V_144 * V_145 ;
struct V_62 * V_63 ;
struct V_146 * V_147 ;
int V_64 , V_65 ;
int V_54 = 0 , V_66 = 0 ;
int V_148 = V_67 ;
struct V_72 * V_77 ;
V_145 = F_43 ( V_149 , & V_120 -> V_33 ) ;
if ( V_145 )
type = (enum V_143 ) V_145 -> V_68 ;
else
type = F_44 ( V_120 ) -> V_150 ;
V_63 = F_36 ( & V_120 -> V_33 , sizeof( * V_63 ) , V_123 ) ;
if ( ! V_63 )
return - V_124 ;
V_63 -> V_33 = & V_120 -> V_33 ;
for ( V_64 = 0 ; V_64 < V_148 ; V_64 ++ ) {
if ( F_45 ( V_120 , V_64 ) > 0 )
V_66 ++ ;
}
V_147 = F_46 ( V_120 , V_151 , 0 ) ;
V_63 -> V_125 = F_47 ( & V_120 -> V_33 , V_147 ) ;
if ( F_48 ( V_63 -> V_125 ) )
return F_49 ( V_63 -> V_125 ) ;
F_50 ( & V_63 -> V_121 . V_127 ) ;
if ( V_120 -> V_33 . V_133 )
V_77 = F_51 ( V_120 -> V_33 . V_133 , L_7 , 0 ) ;
else
V_77 = F_52 ( L_7 ) ;
if ( ! V_77 ) {
F_10 ( & V_120 -> V_33 , L_8 ) ;
return - V_124 ;
}
if ( V_66 != V_148 ) {
V_54 = F_45 ( V_120 , 0 ) ;
V_65 = F_22 ( & V_120 -> V_33 , V_54 ,
F_14 , 0 , L_3 , V_63 ) ;
if ( V_65 )
return V_65 ;
}
for ( V_64 = 0 ; V_64 < V_148 ; V_64 ++ ) {
V_54 = ( V_66 != V_148 ) ? 0 : F_45 ( V_120 , V_64 ) ;
V_65 = F_35 ( V_63 , V_64 , V_54 , type , V_77 ) ;
if ( V_65 )
return V_65 ;
}
F_53 ( V_152 , V_63 -> V_121 . V_141 ) ;
F_53 ( V_153 , V_63 -> V_121 . V_141 ) ;
V_63 -> V_121 . V_33 = & V_120 -> V_33 ;
V_63 -> V_121 . V_154 =
F_20 ;
V_63 -> V_121 . V_155 =
F_23 ;
V_63 -> V_121 . V_156 = F_27 ;
V_63 -> V_121 . V_157 = F_29 ;
V_63 -> V_121 . V_158 = F_31 ;
V_63 -> V_121 . V_159 = F_28 ;
V_63 -> V_121 . V_160 = V_161 ;
F_54 ( & V_120 -> V_33 , F_55 ( 64 ) ) ;
F_56 ( V_120 , V_63 ) ;
V_65 = F_57 ( & V_63 -> V_121 ) ;
if ( V_65 ) {
F_10 ( V_63 -> V_121 . V_33 , L_9 ) ;
return V_65 ;
}
if ( V_120 -> V_33 . V_133 ) {
V_65 = F_58 ( V_120 -> V_33 . V_133 ,
F_40 , V_63 ) ;
if ( V_65 ) {
F_10 ( V_63 -> V_121 . V_33 ,
L_10 ) ;
F_34 ( & V_63 -> V_121 ) ;
}
}
F_59 ( V_63 -> V_121 . V_33 , L_11 ) ;
return 0 ;
}
