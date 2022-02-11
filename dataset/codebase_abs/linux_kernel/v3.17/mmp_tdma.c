static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_3 , V_2 -> V_4 + V_5 ) ;
F_2 ( F_3 ( V_2 -> V_4 + V_6 ) | V_7 ,
V_2 -> V_4 + V_6 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_2 ( V_8 , V_2 -> V_4 + V_9 ) ;
F_2 ( F_3 ( V_2 -> V_4 + V_6 ) | V_10 ,
V_2 -> V_4 + V_6 ) ;
V_2 -> V_11 = V_12 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 -> V_4 + V_6 ) & ~ V_10 ,
V_2 -> V_4 + V_6 ) ;
F_2 ( 0 , V_2 -> V_4 + V_9 ) ;
V_2 -> V_11 = V_13 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 -> V_4 + V_6 ) | V_10 ,
V_2 -> V_4 + V_6 ) ;
V_2 -> V_11 = V_12 ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 -> V_4 + V_6 ) & ~ V_10 ,
V_2 -> V_4 + V_6 ) ;
V_2 -> V_11 = V_14 ;
}
static int F_8 ( struct V_1 * V_2 )
{
unsigned int V_15 = 0 ;
F_5 ( V_2 ) ;
if ( V_2 -> V_16 == V_17 )
V_15 = V_18 | V_19 ;
else if ( V_2 -> V_16 == V_20 )
V_15 = V_21 | V_22 ;
if ( V_2 -> type == V_23 ) {
V_15 |= V_24 ;
switch ( V_2 -> V_25 ) {
case 4 :
V_15 |= V_26 ;
break;
case 8 :
V_15 |= V_27 ;
break;
case 16 :
V_15 |= V_28 ;
break;
case 32 :
V_15 |= V_29 ;
break;
case 64 :
V_15 |= V_30 ;
break;
case 128 :
V_15 |= V_31 ;
break;
default:
F_9 ( V_2 -> V_32 , L_1 ) ;
return - V_33 ;
}
switch ( V_2 -> V_34 ) {
case V_35 :
V_15 |= V_36 ;
break;
case V_37 :
V_15 |= V_38 ;
break;
case V_39 :
V_15 |= V_40 ;
break;
default:
F_9 ( V_2 -> V_32 , L_2 ) ;
return - V_33 ;
}
} else if ( V_2 -> type == V_41 ) {
V_15 |= V_42 ;
switch ( V_2 -> V_25 ) {
case 1 :
V_15 |= V_43 ;
break;
case 2 :
V_15 |= V_44 ;
break;
case 4 :
V_15 |= V_45 ;
break;
case 8 :
V_15 |= V_46 ;
break;
case 16 :
V_15 |= V_47 ;
break;
case 32 :
V_15 |= V_48 ;
break;
default:
F_9 ( V_2 -> V_32 , L_1 ) ;
return - V_33 ;
}
}
F_2 ( V_15 , V_2 -> V_4 + V_6 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
T_2 V_49 = F_3 ( V_2 -> V_4 + V_50 ) ;
if ( V_49 & V_51 ) {
V_49 &= ~ V_51 ;
F_2 ( V_49 , V_2 -> V_4 + V_50 ) ;
return 0 ;
}
return - V_52 ;
}
static T_3 F_11 ( int V_53 , void * V_54 )
{
struct V_1 * V_2 = V_54 ;
if ( F_10 ( V_2 ) == 0 ) {
V_2 -> V_55 = ( V_2 -> V_55 + V_2 -> V_56 ) % V_2 -> V_57 ;
F_12 ( & V_2 -> V_58 ) ;
return V_59 ;
} else
return V_60 ;
}
static T_3 F_13 ( int V_53 , void * V_54 )
{
struct V_61 * V_62 = V_54 ;
int V_63 , V_64 ;
int V_65 = 0 ;
for ( V_63 = 0 ; V_63 < V_66 ; V_63 ++ ) {
struct V_1 * V_2 = V_62 -> V_2 [ V_63 ] ;
V_64 = F_11 ( V_53 , V_2 ) ;
if ( V_64 == V_59 )
V_65 ++ ;
}
if ( V_65 )
return V_59 ;
else
return V_60 ;
}
static void F_14 ( unsigned long V_67 )
{
struct V_1 * V_2 = (struct V_1 * ) V_67 ;
if ( V_2 -> V_68 . V_69 )
V_2 -> V_68 . V_69 ( V_2 -> V_68 . V_70 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_71 * V_72 ;
int V_73 = V_2 -> V_74 * sizeof( struct V_75 ) ;
V_72 = V_2 -> V_76 ;
if ( V_2 -> V_77 )
F_16 ( V_72 , ( unsigned long ) V_2 -> V_77 ,
V_73 ) ;
V_2 -> V_77 = NULL ;
return;
}
static T_4 F_17 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_18 ( V_79 -> V_80 ) ;
F_1 ( V_2 , V_2 -> V_81 ) ;
return 0 ;
}
static int F_19 ( struct V_82 * V_80 )
{
struct V_1 * V_2 = F_18 ( V_80 ) ;
int V_64 ;
F_20 ( & V_2 -> V_68 , V_80 ) ;
V_2 -> V_68 . V_83 = F_17 ;
if ( V_2 -> V_53 ) {
V_64 = F_21 ( V_2 -> V_32 , V_2 -> V_53 ,
F_11 , 0 , L_3 , V_2 ) ;
if ( V_64 )
return V_64 ;
}
return 1 ;
}
static void F_22 ( struct V_82 * V_80 )
{
struct V_1 * V_2 = F_18 ( V_80 ) ;
if ( V_2 -> V_53 )
F_23 ( V_2 -> V_32 , V_2 -> V_53 , V_2 ) ;
F_15 ( V_2 ) ;
return;
}
struct V_75 * F_24 ( struct V_1 * V_2 )
{
struct V_71 * V_72 ;
int V_73 = V_2 -> V_74 * sizeof( struct V_75 ) ;
V_72 = V_2 -> V_76 ;
if ( ! V_72 )
return NULL ;
V_2 -> V_77 = F_25 ( V_72 , V_73 , & V_2 -> V_81 ) ;
return V_2 -> V_77 ;
}
static struct V_78 * F_26 (
struct V_82 * V_80 , T_1 V_84 , T_5 V_57 ,
T_5 V_56 , enum V_85 V_86 ,
unsigned long V_87 )
{
struct V_1 * V_2 = F_18 ( V_80 ) ;
struct V_75 * V_68 ;
int V_88 = V_57 / V_56 ;
int V_63 = 0 , V_89 = 0 ;
if ( V_2 -> V_11 != V_13 )
return NULL ;
if ( V_56 > V_90 ) {
F_9 ( V_2 -> V_32 ,
L_4 ,
V_56 , V_90 ) ;
goto V_91;
}
V_2 -> V_11 = V_12 ;
V_2 -> V_74 = V_88 ;
V_68 = F_24 ( V_2 ) ;
if ( ! V_68 )
goto V_91;
while ( V_89 < V_57 ) {
V_68 = & V_2 -> V_77 [ V_63 ] ;
if ( V_63 + 1 == V_88 )
V_68 -> V_92 = V_2 -> V_81 ;
else
V_68 -> V_92 = V_2 -> V_81 +
sizeof( * V_68 ) * ( V_63 + 1 ) ;
if ( V_86 == V_17 ) {
V_68 -> V_93 = V_84 ;
V_68 -> V_94 = V_2 -> V_95 ;
} else {
V_68 -> V_93 = V_2 -> V_95 ;
V_68 -> V_94 = V_84 ;
}
V_68 -> V_96 = V_56 ;
V_84 += V_56 ;
V_89 += V_56 ;
V_63 ++ ;
}
V_2 -> V_57 = V_57 ;
V_2 -> V_56 = V_56 ;
V_2 -> V_55 = 0 ;
return & V_2 -> V_68 ;
V_91:
V_2 -> V_11 = V_97 ;
return NULL ;
}
static int F_27 ( struct V_82 * V_80 , enum V_98 V_99 ,
unsigned long V_100 )
{
struct V_1 * V_2 = F_18 ( V_80 ) ;
struct V_101 * V_102 = ( void * ) V_100 ;
int V_64 = 0 ;
switch ( V_99 ) {
case V_103 :
F_5 ( V_2 ) ;
break;
case V_104 :
F_7 ( V_2 ) ;
break;
case V_105 :
F_6 ( V_2 ) ;
break;
case V_106 :
if ( V_102 -> V_86 == V_20 ) {
V_2 -> V_95 = V_102 -> V_93 ;
V_2 -> V_25 = V_102 -> V_107 ;
V_2 -> V_34 = V_102 -> V_108 ;
} else {
V_2 -> V_95 = V_102 -> V_94 ;
V_2 -> V_25 = V_102 -> V_109 ;
V_2 -> V_34 = V_102 -> V_110 ;
}
V_2 -> V_16 = V_102 -> V_86 ;
return F_8 ( V_2 ) ;
default:
V_64 = - V_111 ;
}
return V_64 ;
}
static enum V_112 F_28 ( struct V_82 * V_80 ,
T_4 V_113 , struct V_114 * V_115 )
{
struct V_1 * V_2 = F_18 ( V_80 ) ;
F_29 ( V_115 , V_80 -> V_116 , V_80 -> V_113 ,
V_2 -> V_57 - V_2 -> V_55 ) ;
return V_2 -> V_11 ;
}
static void F_30 ( struct V_82 * V_80 )
{
struct V_1 * V_2 = F_18 ( V_80 ) ;
F_4 ( V_2 ) ;
}
static int F_31 ( struct V_117 * V_118 )
{
struct V_61 * V_62 = F_32 ( V_118 ) ;
F_33 ( & V_62 -> V_119 ) ;
return 0 ;
}
static int F_34 ( struct V_61 * V_62 ,
int V_120 , int V_53 ,
int type , struct V_71 * V_76 )
{
struct V_1 * V_2 ;
if ( V_120 >= V_66 ) {
F_9 ( V_62 -> V_32 , L_5 ) ;
return - V_33 ;
}
V_2 = F_35 ( V_62 -> V_32 , sizeof( * V_2 ) , V_121 ) ;
if ( ! V_2 ) {
F_9 ( V_62 -> V_32 , L_6 ) ;
return - V_122 ;
}
if ( V_53 )
V_2 -> V_53 = V_53 ;
V_2 -> V_32 = V_62 -> V_32 ;
V_2 -> V_80 . V_119 = & V_62 -> V_119 ;
V_2 -> V_120 = V_120 ;
V_2 -> type = type ;
V_2 -> V_4 = V_62 -> V_123 + V_120 * 4 ;
V_2 -> V_76 = V_76 ;
V_2 -> V_11 = V_13 ;
V_62 -> V_2 [ V_2 -> V_120 ] = V_2 ;
F_36 ( & V_2 -> V_58 , F_14 , ( unsigned long ) V_2 ) ;
F_37 ( & V_2 -> V_80 . V_124 ,
& V_62 -> V_119 . V_125 ) ;
return 0 ;
}
static bool F_38 ( struct V_82 * V_80 , void * V_126 )
{
struct V_127 * V_128 = V_126 ;
struct V_1 * V_2 = F_18 ( V_80 ) ;
struct V_129 * V_130 = V_2 -> V_80 . V_119 ;
if ( V_130 -> V_32 -> V_131 != V_128 -> V_131 )
return false ;
if ( V_80 -> V_132 != V_128 -> V_132 )
return false ;
return true ;
}
struct V_82 * F_39 ( struct V_133 * V_134 ,
struct V_135 * V_136 )
{
struct V_61 * V_62 = V_136 -> V_137 ;
T_6 V_138 = V_62 -> V_119 . V_139 ;
struct V_127 V_128 ;
if ( V_134 -> V_140 != 1 )
return NULL ;
V_128 . V_131 = V_136 -> V_131 ;
V_128 . V_132 = V_134 -> args [ 0 ] ;
if ( V_128 . V_132 >= V_66 )
return NULL ;
return F_40 ( V_138 , F_38 , & V_128 ) ;
}
static int F_41 ( struct V_117 * V_118 )
{
enum V_141 type ;
const struct V_142 * V_143 ;
struct V_61 * V_62 ;
struct V_144 * V_145 ;
int V_63 , V_64 ;
int V_53 = 0 , V_65 = 0 ;
int V_146 = V_66 ;
struct V_71 * V_76 ;
V_143 = F_42 ( V_147 , & V_118 -> V_32 ) ;
if ( V_143 )
type = (enum V_141 ) V_143 -> V_67 ;
else
type = F_43 ( V_118 ) -> V_148 ;
V_62 = F_35 ( & V_118 -> V_32 , sizeof( * V_62 ) , V_121 ) ;
if ( ! V_62 )
return - V_122 ;
V_62 -> V_32 = & V_118 -> V_32 ;
for ( V_63 = 0 ; V_63 < V_146 ; V_63 ++ ) {
if ( F_44 ( V_118 , V_63 ) > 0 )
V_65 ++ ;
}
V_145 = F_45 ( V_118 , V_149 , 0 ) ;
V_62 -> V_123 = F_46 ( & V_118 -> V_32 , V_145 ) ;
if ( F_47 ( V_62 -> V_123 ) )
return F_48 ( V_62 -> V_123 ) ;
F_49 ( & V_62 -> V_119 . V_125 ) ;
if ( V_118 -> V_32 . V_131 )
V_76 = F_50 ( V_118 -> V_32 . V_131 , L_7 , 0 ) ;
else
V_76 = F_51 ( L_7 ) ;
if ( ! V_76 ) {
F_9 ( & V_118 -> V_32 , L_8 ) ;
return - V_122 ;
}
if ( V_65 != V_146 ) {
V_53 = F_44 ( V_118 , 0 ) ;
V_64 = F_21 ( & V_118 -> V_32 , V_53 ,
F_13 , 0 , L_3 , V_62 ) ;
if ( V_64 )
return V_64 ;
}
for ( V_63 = 0 ; V_63 < V_146 ; V_63 ++ ) {
V_53 = ( V_65 != V_146 ) ? 0 : F_44 ( V_118 , V_63 ) ;
V_64 = F_34 ( V_62 , V_63 , V_53 , type , V_76 ) ;
if ( V_64 )
return V_64 ;
}
F_52 ( V_150 , V_62 -> V_119 . V_139 ) ;
F_52 ( V_151 , V_62 -> V_119 . V_139 ) ;
V_62 -> V_119 . V_32 = & V_118 -> V_32 ;
V_62 -> V_119 . V_152 =
F_19 ;
V_62 -> V_119 . V_153 =
F_22 ;
V_62 -> V_119 . V_154 = F_26 ;
V_62 -> V_119 . V_155 = F_28 ;
V_62 -> V_119 . V_156 = F_30 ;
V_62 -> V_119 . V_157 = F_27 ;
V_62 -> V_119 . V_158 = V_159 ;
F_53 ( & V_118 -> V_32 , F_54 ( 64 ) ) ;
F_55 ( V_118 , V_62 ) ;
V_64 = F_56 ( & V_62 -> V_119 ) ;
if ( V_64 ) {
F_9 ( V_62 -> V_119 . V_32 , L_9 ) ;
return V_64 ;
}
if ( V_118 -> V_32 . V_131 ) {
V_64 = F_57 ( V_118 -> V_32 . V_131 ,
F_39 , V_62 ) ;
if ( V_64 ) {
F_9 ( V_62 -> V_119 . V_32 ,
L_10 ) ;
F_33 ( & V_62 -> V_119 ) ;
}
}
F_58 ( V_62 -> V_119 . V_32 , L_11 ) ;
return 0 ;
}
