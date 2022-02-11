static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
return F_2 ( V_5 , V_2 -> V_8 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
F_4 ( V_5 , V_2 -> V_8 + V_3 , V_9 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_10 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
F_4 ( V_5 , V_2 -> V_8 + V_3 ,
F_2 ( V_5 , V_2 -> V_8 + V_3 ) & ~ V_10 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_11 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
F_4 ( V_5 , V_2 -> V_8 + V_3 ,
F_2 ( V_5 , V_2 -> V_8 + V_3 ) | V_11 ) ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_10 , T_1 V_11 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
T_1 V_12 = F_2 ( V_5 , V_2 -> V_8 + V_3 ) ;
F_4 ( V_5 , V_2 -> V_8 + V_3 , ( V_12 & ~ V_10 ) | V_11 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_13 ;
V_13 = F_9 ( V_2 -> clock ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_9 ( V_2 -> V_14 ) ;
if ( V_13 < 0 )
goto V_15;
V_13 = F_10 ( V_2 -> V_6 ) ;
if ( V_13 < 0 )
goto V_16;
return 0 ;
V_16:
F_11 ( V_2 -> V_14 ) ;
V_15:
F_11 ( V_2 -> clock ) ;
return V_13 ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_13 ( V_2 -> V_6 ) ;
F_11 ( V_2 -> V_14 ) ;
F_11 ( V_2 -> clock ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
const struct V_17 * V_18 = & V_2 -> V_19 . V_18 ;
unsigned long V_20 = V_18 -> clock * 1000 ;
unsigned long V_21 ;
T_1 V_12 ;
T_1 V_22 ;
T_1 div ;
V_21 = F_15 ( V_2 -> clock ) ;
div = F_16 ( V_21 , V_20 ) ;
div = F_17 ( div , 1U , 64U ) - 1 ;
V_22 = div | V_23 ;
if ( V_2 -> V_14 ) {
unsigned long V_24 ;
unsigned long V_25 ;
unsigned long V_26 ;
T_1 V_27 ;
V_24 = F_15 ( V_2 -> V_14 ) ;
V_27 = F_16 ( V_24 , V_20 ) ;
V_27 = F_17 ( V_27 , 1U , 64U ) - 1 ;
V_26 = V_21 / ( div + 1 ) ;
V_25 = V_24 / ( V_27 + 1 ) ;
if ( abs ( ( long ) V_25 - ( long ) V_20 ) <
abs ( ( long ) V_26 - ( long ) V_20 ) ) {
F_18 ( V_2 -> V_6 -> V_7 -> V_7 ,
L_1 , V_2 -> V_28 ) ;
V_22 = V_27 | V_29 ;
}
}
F_19 ( V_2 -> V_6 , V_2 -> V_28 % 2 ? V_30 : V_31 ,
V_22 ) ;
F_19 ( V_2 -> V_6 , V_2 -> V_28 % 2 ? V_32 : V_33 , 0 ) ;
V_12 = ( ( V_18 -> V_34 & V_35 ) ? 0 : V_36 )
| ( ( V_18 -> V_34 & V_37 ) ? 0 : V_38 )
| V_39 | V_40 ;
F_3 ( V_2 , V_41 , V_12 ) ;
F_3 ( V_2 , V_42 , V_18 -> V_43 - V_18 -> V_44 - 19 ) ;
F_3 ( V_2 , V_45 , V_18 -> V_43 - V_18 -> V_44 +
V_18 -> V_46 - 19 ) ;
F_3 ( V_2 , V_47 , V_18 -> V_48 -
V_18 -> V_44 - 1 ) ;
F_3 ( V_2 , V_49 , V_18 -> V_43 - 1 ) ;
F_3 ( V_2 , V_50 , V_18 -> V_51 -
V_18 -> V_52 - 2 ) ;
F_3 ( V_2 , V_53 , V_18 -> V_51 -
V_18 -> V_52 +
V_18 -> V_54 - 2 ) ;
F_3 ( V_2 , V_55 , V_18 -> V_51 -
V_18 -> V_52 +
V_18 -> V_56 - 1 ) ;
F_3 ( V_2 , V_57 , V_18 -> V_51 - 1 ) ;
F_3 ( V_2 , V_58 , V_18 -> V_43 - V_18 -> V_44 ) ;
F_3 ( V_2 , V_59 , V_18 -> V_46 ) ;
}
void F_20 ( struct V_60 * V_19 ,
enum V_61 V_62 )
{
struct V_1 * V_2 = F_21 ( V_19 ) ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
V_2 -> V_63 |= F_22 ( V_62 ) ;
if ( V_62 == V_64 )
V_5 -> V_65 = V_2 -> V_28 ;
}
void F_23 ( struct V_60 * V_19 )
{
struct V_1 * V_2 = F_21 ( V_19 ) ;
struct V_66 * V_67 [ V_68 ] ;
unsigned int V_69 = 0 ;
unsigned int V_70 = 0 ;
unsigned int V_71 ;
T_1 V_72 = 0 ;
T_1 V_73 = 0 ;
for ( V_71 = 0 ; V_71 < F_24 ( V_2 -> V_6 -> V_67 . V_67 ) ; ++ V_71 ) {
struct V_66 * V_74 = & V_2 -> V_6 -> V_67 . V_67 [ V_71 ] ;
unsigned int V_75 ;
if ( V_74 -> V_19 != & V_2 -> V_19 || ! V_74 -> V_76 )
continue;
for ( V_75 = V_69 ++ ; V_75 > 0 ; -- V_75 ) {
if ( V_67 [ V_75 - 1 ] -> V_77 <= V_74 -> V_77 )
break;
V_67 [ V_75 ] = V_67 [ V_75 - 1 ] ;
}
V_67 [ V_75 ] = V_74 ;
V_70 += V_74 -> V_78 -> V_67 * 4 ;
}
for ( V_71 = 0 ; V_71 < V_69 ; ++ V_71 ) {
struct V_66 * V_74 = V_67 [ V_71 ] ;
unsigned int V_28 = V_74 -> V_79 ;
V_70 -= 4 ;
V_73 |= ( V_28 + 1 ) << V_70 ;
V_72 |= F_25 ( V_28 ) | F_26 ( V_28 ) ;
if ( V_74 -> V_78 -> V_67 == 2 ) {
V_28 = ( V_28 + 1 ) % 8 ;
V_70 -= 4 ;
V_73 |= ( V_28 + 1 ) << V_70 ;
V_72 |= F_25 ( V_28 ) | F_26 ( V_28 ) ;
}
}
if ( V_2 -> V_28 % 2 ) {
T_1 V_12 = F_27 ( V_2 -> V_6 , V_80 ) ;
if ( V_12 != V_72 ) {
F_19 ( V_2 -> V_6 , V_80 , V_72 ) ;
if ( V_2 -> V_6 -> V_81 )
F_28 ( V_2 -> V_6 ) ;
}
}
F_19 ( V_2 -> V_6 , V_2 -> V_28 % 2 ? V_82 : V_83 ,
V_73 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_60 * V_19 = & V_2 -> V_19 ;
bool V_84 ;
unsigned int V_71 ;
if ( V_2 -> V_85 )
return;
if ( F_30 ( V_2 -> V_74 -> V_78 == NULL ) )
return;
F_3 ( V_2 , V_86 , F_31 ( 0 , 0 , 0 ) ) ;
F_3 ( V_2 , V_87 , F_32 ( 0 , 0 , 0 ) ) ;
F_14 ( V_2 ) ;
F_33 ( V_2 -> V_6 ) ;
F_34 ( & V_2 -> V_6 -> V_67 . V_88 ) ;
V_2 -> V_74 -> V_76 = true ;
F_23 ( V_19 ) ;
F_35 ( & V_2 -> V_6 -> V_67 . V_88 ) ;
for ( V_71 = 0 ; V_71 < F_24 ( V_2 -> V_6 -> V_67 . V_67 ) ; ++ V_71 ) {
struct V_66 * V_74 = & V_2 -> V_6 -> V_67 . V_67 [ V_71 ] ;
if ( V_74 -> V_19 != V_19 || ! V_74 -> V_76 )
continue;
F_36 ( V_74 ) ;
}
V_84 = V_2 -> V_19 . V_18 . V_34 & V_89 ;
F_7 ( V_2 , V_90 , V_91 | V_92 ,
( V_84 ? V_93 : 0 ) |
V_94 ) ;
F_37 ( V_2 -> V_6 , true ) ;
V_2 -> V_85 = true ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_60 * V_19 = & V_2 -> V_19 ;
if ( ! V_2 -> V_85 )
return;
F_34 ( & V_2 -> V_6 -> V_67 . V_88 ) ;
V_2 -> V_74 -> V_76 = false ;
F_23 ( V_19 ) ;
F_35 ( & V_2 -> V_6 -> V_67 . V_88 ) ;
F_7 ( V_2 , V_90 , V_91 , V_95 ) ;
F_37 ( V_2 -> V_6 , false ) ;
V_2 -> V_85 = false ;
}
void F_39 ( struct V_1 * V_2 )
{
F_38 ( V_2 ) ;
F_12 ( V_2 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
if ( V_2 -> V_96 != V_97 )
return;
F_8 ( V_2 ) ;
F_29 ( V_2 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_60 * V_19 = & V_2 -> V_19 ;
F_42 ( V_2 -> V_74 , V_19 -> V_98 -> V_99 ) ;
F_43 ( V_2 -> V_74 ) ;
}
static void F_44 ( struct V_60 * V_19 , int V_18 )
{
struct V_1 * V_2 = F_21 ( V_19 ) ;
if ( V_18 != V_97 )
V_18 = V_100 ;
if ( V_2 -> V_96 == V_18 )
return;
if ( V_18 == V_97 ) {
F_8 ( V_2 ) ;
F_29 ( V_2 ) ;
} else {
F_38 ( V_2 ) ;
F_12 ( V_2 ) ;
}
V_2 -> V_96 = V_18 ;
}
static bool F_45 ( struct V_60 * V_19 ,
const struct V_17 * V_18 ,
struct V_17 * V_101 )
{
return true ;
}
static void F_46 ( struct V_60 * V_19 )
{
struct V_1 * V_2 = F_21 ( V_19 ) ;
F_8 ( V_2 ) ;
F_38 ( V_2 ) ;
F_47 ( V_2 -> V_74 ) ;
V_2 -> V_96 = V_100 ;
}
static int F_48 ( struct V_60 * V_19 ,
struct V_17 * V_18 ,
struct V_17 * V_101 ,
int V_102 , int V_103 ,
struct V_104 * V_105 )
{
struct V_1 * V_2 = F_21 ( V_19 ) ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
const struct V_106 * V_78 ;
int V_13 ;
V_78 = V_106 ( V_19 -> V_98 -> V_99 -> V_107 ) ;
if ( V_78 == NULL ) {
F_18 ( V_5 -> V_7 , L_2 ,
V_19 -> V_98 -> V_99 -> V_107 ) ;
V_13 = - V_108 ;
goto error;
}
V_13 = F_49 ( V_2 -> V_74 , V_78 ) ;
if ( V_13 < 0 )
goto error;
V_2 -> V_74 -> V_78 = V_78 ;
V_2 -> V_74 -> V_109 = V_102 ;
V_2 -> V_74 -> V_110 = V_103 ;
V_2 -> V_74 -> V_111 = V_18 -> V_46 ;
V_2 -> V_74 -> V_112 = V_18 -> V_113 ;
F_42 ( V_2 -> V_74 , V_19 -> V_98 -> V_99 ) ;
V_2 -> V_63 = 0 ;
return 0 ;
error:
F_12 ( V_2 ) ;
return V_13 ;
}
static void F_50 ( struct V_60 * V_19 )
{
struct V_1 * V_2 = F_21 ( V_19 ) ;
F_29 ( V_2 ) ;
V_2 -> V_96 = V_97 ;
}
static int F_51 ( struct V_60 * V_19 , int V_102 , int V_103 ,
struct V_104 * V_105 )
{
struct V_1 * V_2 = F_21 ( V_19 ) ;
V_2 -> V_74 -> V_109 = V_102 ;
V_2 -> V_74 -> V_110 = V_103 ;
F_41 ( V_2 ) ;
return 0 ;
}
static void F_52 ( struct V_60 * V_19 )
{
struct V_1 * V_2 = F_21 ( V_19 ) ;
F_44 ( V_19 , V_100 ) ;
F_47 ( V_2 -> V_74 ) ;
}
void F_53 ( struct V_1 * V_2 ,
struct V_114 * V_115 )
{
struct V_116 * V_117 ;
struct V_118 * V_7 = V_2 -> V_19 . V_7 ;
unsigned long V_34 ;
F_54 ( & V_7 -> V_119 , V_34 ) ;
V_117 = V_2 -> V_117 ;
if ( V_117 && V_117 -> V_120 . V_121 == V_115 ) {
V_2 -> V_117 = NULL ;
V_117 -> V_120 . V_122 ( & V_117 -> V_120 ) ;
F_55 ( V_7 , V_2 -> V_28 ) ;
}
F_56 ( & V_7 -> V_119 , V_34 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_116 * V_117 ;
struct V_118 * V_7 = V_2 -> V_19 . V_7 ;
unsigned long V_34 ;
F_54 ( & V_7 -> V_119 , V_34 ) ;
V_117 = V_2 -> V_117 ;
V_2 -> V_117 = NULL ;
F_56 ( & V_7 -> V_119 , V_34 ) ;
if ( V_117 == NULL )
return;
F_54 ( & V_7 -> V_119 , V_34 ) ;
F_58 ( V_7 , V_2 -> V_28 , V_117 ) ;
F_56 ( & V_7 -> V_119 , V_34 ) ;
F_55 ( V_7 , V_2 -> V_28 ) ;
}
static T_2 F_59 ( int V_123 , void * V_124 )
{
struct V_1 * V_2 = V_124 ;
T_2 V_13 = V_125 ;
T_1 V_126 ;
V_126 = F_1 ( V_2 , V_127 ) ;
F_3 ( V_2 , V_128 , V_126 & V_129 ) ;
if ( V_126 & V_130 ) {
F_60 ( V_2 -> V_19 . V_7 , V_2 -> V_28 ) ;
F_57 ( V_2 ) ;
V_13 = V_131 ;
}
return V_13 ;
}
static int F_61 ( struct V_60 * V_19 ,
struct V_104 * V_99 ,
struct V_116 * V_117 ,
T_3 V_132 )
{
struct V_1 * V_2 = F_21 ( V_19 ) ;
struct V_118 * V_7 = V_2 -> V_19 . V_7 ;
unsigned long V_34 ;
F_54 ( & V_7 -> V_119 , V_34 ) ;
if ( V_2 -> V_117 != NULL ) {
F_56 ( & V_7 -> V_119 , V_34 ) ;
return - V_133 ;
}
F_56 ( & V_7 -> V_119 , V_34 ) ;
V_19 -> V_98 -> V_99 = V_99 ;
F_41 ( V_2 ) ;
if ( V_117 ) {
V_117 -> V_134 = V_2 -> V_28 ;
F_62 ( V_7 , V_2 -> V_28 ) ;
F_54 ( & V_7 -> V_119 , V_34 ) ;
V_2 -> V_117 = V_117 ;
F_56 ( & V_7 -> V_119 , V_34 ) ;
}
return 0 ;
}
int F_63 ( struct V_135 * V_136 , unsigned int V_28 )
{
static const unsigned int V_137 [] = {
V_138 , V_139 , V_140
} ;
struct V_4 * V_5 = V_136 -> V_7 ;
struct V_141 * V_142 = F_64 ( V_5 -> V_7 ) ;
struct V_1 * V_2 = & V_5 -> V_143 [ V_28 ] ;
struct V_60 * V_19 = & V_2 -> V_19 ;
unsigned int V_144 ;
struct V_21 * V_21 ;
char V_145 [ 9 ] ;
char * V_146 ;
int V_123 ;
int V_13 ;
if ( F_65 ( V_5 , V_147 ) ) {
sprintf ( V_145 , L_3 , V_28 ) ;
V_146 = V_145 ;
} else {
V_146 = NULL ;
}
V_2 -> clock = F_66 ( V_5 -> V_7 , V_146 ) ;
if ( F_67 ( V_2 -> clock ) ) {
F_68 ( V_5 -> V_7 , L_4 , V_28 ) ;
return F_69 ( V_2 -> clock ) ;
}
sprintf ( V_145 , L_5 , V_28 ) ;
V_21 = F_66 ( V_5 -> V_7 , V_145 ) ;
if ( ! F_67 ( V_21 ) ) {
V_2 -> V_14 = V_21 ;
} else if ( F_69 ( V_2 -> clock ) == - V_148 ) {
F_70 ( V_5 -> V_7 , L_6 , V_28 ) ;
return - V_148 ;
}
V_2 -> V_6 = V_136 ;
V_2 -> V_8 = V_137 [ V_28 ] ;
V_2 -> V_28 = V_28 ;
V_2 -> V_96 = V_100 ;
V_2 -> V_74 = & V_136 -> V_67 . V_67 [ V_28 % 2 ] ;
V_2 -> V_74 -> V_19 = V_19 ;
V_13 = F_71 ( V_5 -> V_149 , V_19 , & V_150 ) ;
if ( V_13 < 0 )
return V_13 ;
F_72 ( V_19 , & V_151 ) ;
if ( F_65 ( V_5 , V_147 ) ) {
V_123 = F_73 ( V_142 , V_28 ) ;
V_144 = 0 ;
} else {
V_123 = F_73 ( V_142 , 0 ) ;
V_144 = V_152 ;
}
if ( V_123 < 0 ) {
F_68 ( V_5 -> V_7 , L_7 , V_28 ) ;
return V_123 ;
}
V_13 = F_74 ( V_5 -> V_7 , V_123 , F_59 , V_144 ,
F_75 ( V_5 -> V_7 ) , V_2 ) ;
if ( V_13 < 0 ) {
F_68 ( V_5 -> V_7 ,
L_8 , V_28 ) ;
return V_13 ;
}
return 0 ;
}
void F_76 ( struct V_1 * V_2 , bool V_153 )
{
if ( V_153 ) {
F_3 ( V_2 , V_128 , V_154 ) ;
F_6 ( V_2 , V_155 , V_156 ) ;
} else {
F_5 ( V_2 , V_155 , V_156 ) ;
}
}
