int F_1 ( int V_1 , int V_2 , int V_3 )
{
int V_4 = V_1 - V_2 ;
if ( V_4 <= 0 )
V_4 += V_3 ;
return V_4 - V_5 ;
}
void F_2 ( struct V_6 * V_7 )
{
if ( V_7 -> V_8 != - 1 ) {
V_7 -> V_1 = V_7 -> V_8 ;
V_7 -> V_8 = - 1 ;
}
V_7 -> V_4 = F_1 ( V_7 -> V_1 & V_9 ,
V_7 -> V_2 , V_7 -> V_3 ) ;
}
int F_3 ( struct V_6 * V_7 )
{
F_2 ( V_7 ) ;
return V_7 -> V_4 ;
}
bool F_4 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 -> V_15 ;
return V_13 -> V_16 . V_17 & F_5 ( V_11 ) ;
}
static void F_6 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_18 ;
V_7 -> V_2 &= V_7 -> V_3 - 1 ;
if ( F_4 ( V_11 ) )
return;
V_11 -> V_19 ( V_11 , V_7 -> V_2 ) ;
}
static int
F_7 ( struct V_20 * V_21 ,
T_1 V_22 ,
T_1 V_23 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
T_1 V_24 ;
int V_25 ;
V_24 = V_26 ;
if ( ( ( V_22 | V_23 ) & V_27 ) == 0 )
V_24 |= V_28 ;
if ( V_22 & V_29 )
V_24 |= V_30 ;
V_25 = F_8 ( V_21 , 2 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_11 , V_24 ) ;
F_9 ( V_11 , V_31 ) ;
F_10 ( V_11 ) ;
return 0 ;
}
static int
F_11 ( struct V_20 * V_21 ,
T_1 V_22 ,
T_1 V_23 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
struct V_32 * V_14 = V_11 -> V_14 ;
T_1 V_24 ;
int V_25 ;
V_24 = V_26 | V_28 ;
if ( ( V_22 | V_23 ) & V_27 )
V_24 &= ~ V_28 ;
if ( V_22 & V_33 )
V_24 |= V_34 ;
if ( V_22 & V_35 &&
( F_12 ( V_14 ) || F_13 ( V_14 ) ) )
V_24 |= V_36 ;
V_25 = F_8 ( V_21 , 2 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_11 , V_24 ) ;
F_9 ( V_11 , V_31 ) ;
F_10 ( V_11 ) ;
return 0 ;
}
static int
F_14 ( struct V_20 * V_21 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
T_1 V_37 = V_11 -> V_38 . V_39 + 2 * V_40 ;
int V_25 ;
V_25 = F_8 ( V_21 , 6 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_11 , F_15 ( 5 ) ) ;
F_9 ( V_11 , V_41 |
V_42 ) ;
F_9 ( V_11 , V_37 | V_43 ) ;
F_9 ( V_11 , 0 ) ;
F_9 ( V_11 , 0 ) ;
F_9 ( V_11 , V_31 ) ;
F_10 ( V_11 ) ;
V_25 = F_8 ( V_21 , 6 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_11 , F_15 ( 5 ) ) ;
F_9 ( V_11 , V_44 ) ;
F_9 ( V_11 , V_37 | V_43 ) ;
F_9 ( V_11 , 0 ) ;
F_9 ( V_11 , 0 ) ;
F_9 ( V_11 , V_31 ) ;
F_10 ( V_11 ) ;
return 0 ;
}
static int
F_16 ( struct V_20 * V_21 ,
T_1 V_22 , T_1 V_23 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
T_1 V_45 = 0 ;
T_1 V_37 = V_11 -> V_38 . V_39 + 2 * V_40 ;
int V_25 ;
V_25 = F_14 ( V_21 ) ;
if ( V_25 )
return V_25 ;
if ( V_23 ) {
V_45 |= V_46 ;
V_45 |= V_47 ;
V_45 |= V_41 ;
}
if ( V_22 ) {
V_45 |= V_48 ;
V_45 |= V_49 ;
V_45 |= V_50 ;
V_45 |= V_51 ;
V_45 |= V_52 ;
V_45 |= V_53 ;
V_45 |= V_44 | V_41 ;
}
V_25 = F_8 ( V_21 , 4 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_11 , F_15 ( 4 ) ) ;
F_9 ( V_11 , V_45 ) ;
F_9 ( V_11 , V_37 | V_43 ) ;
F_9 ( V_11 , 0 ) ;
F_10 ( V_11 ) ;
return 0 ;
}
static int
F_17 ( struct V_20 * V_21 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
int V_25 ;
V_25 = F_8 ( V_21 , 4 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_11 , F_15 ( 4 ) ) ;
F_9 ( V_11 , V_41 |
V_42 ) ;
F_9 ( V_11 , 0 ) ;
F_9 ( V_11 , 0 ) ;
F_10 ( V_11 ) ;
return 0 ;
}
static int
F_18 ( struct V_20 * V_21 ,
T_1 V_22 , T_1 V_23 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
T_1 V_45 = 0 ;
T_1 V_37 = V_11 -> V_38 . V_39 + 2 * V_40 ;
int V_25 ;
V_45 |= V_41 ;
if ( V_23 ) {
V_45 |= V_46 ;
V_45 |= V_47 ;
V_45 |= V_54 ;
V_45 |= V_55 ;
}
if ( V_22 ) {
V_45 |= V_48 ;
V_45 |= V_49 ;
V_45 |= V_50 ;
V_45 |= V_51 ;
V_45 |= V_52 ;
V_45 |= V_53 ;
V_45 |= V_56 ;
V_45 |= V_44 ;
V_45 |= V_57 ;
V_45 |= V_42 ;
F_17 ( V_21 ) ;
}
V_25 = F_8 ( V_21 , 4 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_11 , F_15 ( 4 ) ) ;
F_9 ( V_11 , V_45 ) ;
F_9 ( V_11 , V_37 ) ;
F_9 ( V_11 , 0 ) ;
F_10 ( V_11 ) ;
return 0 ;
}
static int
F_19 ( struct V_20 * V_21 ,
T_1 V_45 , T_1 V_37 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
int V_25 ;
V_25 = F_8 ( V_21 , 6 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_11 , F_15 ( 6 ) ) ;
F_9 ( V_11 , V_45 ) ;
F_9 ( V_11 , V_37 ) ;
F_9 ( V_11 , 0 ) ;
F_9 ( V_11 , 0 ) ;
F_9 ( V_11 , 0 ) ;
F_10 ( V_11 ) ;
return 0 ;
}
static int
F_20 ( struct V_20 * V_21 ,
T_1 V_22 , T_1 V_23 )
{
T_1 V_45 = 0 ;
T_1 V_37 = V_21 -> V_11 -> V_38 . V_39 + 2 * V_40 ;
int V_25 ;
V_45 |= V_41 ;
if ( V_23 ) {
V_45 |= V_46 ;
V_45 |= V_47 ;
V_45 |= V_54 ;
V_45 |= V_55 ;
}
if ( V_22 ) {
V_45 |= V_48 ;
V_45 |= V_49 ;
V_45 |= V_50 ;
V_45 |= V_51 ;
V_45 |= V_52 ;
V_45 |= V_53 ;
V_45 |= V_44 ;
V_45 |= V_57 ;
V_25 = F_19 ( V_21 ,
V_41 |
V_42 ,
0 ) ;
if ( V_25 )
return V_25 ;
}
return F_19 ( V_21 , V_45 , V_37 ) ;
}
static void F_21 ( struct V_10 * V_11 ,
T_1 V_58 )
{
struct V_12 * V_13 = V_11 -> V_14 -> V_15 ;
F_22 ( V_11 , V_58 ) ;
}
T_2 F_23 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 -> V_15 ;
T_2 V_59 ;
if ( F_24 ( V_11 -> V_14 ) -> V_60 >= 8 )
V_59 = F_25 ( F_26 ( V_11 -> V_61 ) ,
F_27 ( V_11 -> V_61 ) ) ;
else if ( F_24 ( V_11 -> V_14 ) -> V_60 >= 4 )
V_59 = F_28 ( F_26 ( V_11 -> V_61 ) ) ;
else
V_59 = F_28 ( V_62 ) ;
return V_59 ;
}
static void F_29 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 -> V_15 ;
T_1 V_63 ;
V_63 = V_13 -> V_64 -> V_65 ;
if ( F_24 ( V_11 -> V_14 ) -> V_60 >= 4 )
V_63 |= ( V_13 -> V_64 -> V_65 >> 28 ) & 0xf0 ;
F_30 ( V_66 , V_63 ) ;
}
static void F_31 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_11 -> V_14 -> V_15 ;
T_3 V_67 ;
if ( F_32 ( V_14 ) ) {
switch ( V_11 -> V_68 ) {
case V_69 :
V_67 = V_70 ;
break;
case V_71 :
V_67 = V_72 ;
break;
case V_73 :
case V_74 :
V_67 = V_75 ;
break;
case V_76 :
V_67 = V_77 ;
break;
}
} else if ( F_33 ( V_11 -> V_14 ) ) {
V_67 = F_34 ( V_11 -> V_61 ) ;
} else {
V_67 = F_35 ( V_11 -> V_61 ) ;
}
F_30 ( V_67 , ( T_1 ) V_11 -> V_78 . V_79 ) ;
F_36 ( V_67 ) ;
if ( F_24 ( V_14 ) -> V_60 >= 6 && F_24 ( V_14 ) -> V_60 < 8 ) {
T_3 V_80 = F_37 ( V_11 -> V_61 ) ;
F_38 ( ( F_39 ( V_11 ) & V_81 ) == 0 ) ;
F_30 ( V_80 ,
F_40 ( V_82 |
V_83 ) ) ;
if ( F_41 ( ( F_28 ( V_80 ) & V_83 ) == 0 ,
1000 ) )
F_42 ( L_1 ,
V_11 -> V_84 ) ;
}
}
static bool F_43 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_44 ( V_11 -> V_14 ) ;
if ( ! F_45 ( V_11 -> V_14 ) ) {
F_46 ( V_11 , F_40 ( V_85 ) ) ;
if ( F_41 ( ( F_39 ( V_11 ) & V_81 ) != 0 , 1000 ) ) {
F_42 ( L_2 , V_11 -> V_84 ) ;
if ( F_47 ( V_11 ) != F_48 ( V_11 ) )
return false ;
}
}
F_49 ( V_11 , 0 ) ;
F_50 ( V_11 , 0 ) ;
V_11 -> V_19 ( V_11 , 0 ) ;
if ( ! F_45 ( V_11 -> V_14 ) ) {
( void ) F_51 ( V_11 ) ;
F_46 ( V_11 , F_52 ( V_85 ) ) ;
}
return ( F_47 ( V_11 ) & V_9 ) == 0 ;
}
static int F_53 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_6 * V_7 = V_11 -> V_18 ;
struct V_86 * V_87 = V_7 -> V_87 ;
int V_25 = 0 ;
F_54 ( V_13 , V_88 ) ;
if ( ! F_43 ( V_11 ) ) {
F_55 ( L_3
L_4 ,
V_11 -> V_84 ,
F_51 ( V_11 ) ,
F_47 ( V_11 ) ,
F_48 ( V_11 ) ,
F_56 ( V_11 ) ) ;
if ( ! F_43 ( V_11 ) ) {
F_42 ( L_5
L_4 ,
V_11 -> V_84 ,
F_51 ( V_11 ) ,
F_47 ( V_11 ) ,
F_48 ( V_11 ) ,
F_56 ( V_11 ) ) ;
V_25 = - V_89 ;
goto V_90;
}
}
if ( F_57 ( V_14 ) )
F_31 ( V_11 ) ;
else
F_29 ( V_11 ) ;
F_47 ( V_11 ) ;
F_58 ( V_11 , F_59 ( V_87 ) ) ;
if ( F_47 ( V_11 ) )
F_60 ( L_6 ,
V_11 -> V_84 , F_47 ( V_11 ) ) ;
F_50 ( V_11 , 0 ) ;
( void ) F_47 ( V_11 ) ;
F_49 ( V_11 ,
( ( V_7 -> V_3 - V_91 ) & V_92 )
| V_93 ) ;
if ( F_41 ( ( F_51 ( V_11 ) & V_93 ) != 0 &&
F_56 ( V_11 ) == F_59 ( V_87 ) &&
( F_47 ( V_11 ) & V_9 ) == 0 , 50 ) ) {
F_42 ( L_7
L_8 ,
V_11 -> V_84 ,
F_51 ( V_11 ) , F_51 ( V_11 ) & V_93 ,
F_47 ( V_11 ) , F_48 ( V_11 ) ,
F_56 ( V_11 ) , ( unsigned long ) F_59 ( V_87 ) ) ;
V_25 = - V_89 ;
goto V_90;
}
V_7 -> V_8 = - 1 ;
V_7 -> V_1 = F_47 ( V_11 ) ;
V_7 -> V_2 = F_48 ( V_11 ) & V_94 ;
F_2 ( V_7 ) ;
memset ( & V_11 -> V_95 , 0 , sizeof( V_11 -> V_95 ) ) ;
V_90:
F_61 ( V_13 , V_88 ) ;
return V_25 ;
}
void
F_62 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
if ( V_11 -> V_38 . V_87 == NULL )
return;
if ( F_24 ( V_14 ) -> V_60 >= 5 ) {
F_63 ( F_64 ( V_11 -> V_38 . V_87 -> V_96 -> V_97 ) ) ;
F_65 ( V_11 -> V_38 . V_87 ) ;
}
F_66 ( & V_11 -> V_38 . V_87 -> V_98 ) ;
V_11 -> V_38 . V_87 = NULL ;
}
int
F_67 ( struct V_10 * V_11 )
{
int V_25 ;
F_38 ( V_11 -> V_38 . V_87 ) ;
V_11 -> V_38 . V_87 = F_68 ( V_11 -> V_14 , 4096 ) ;
if ( V_11 -> V_38 . V_87 == NULL ) {
F_42 ( L_9 ) ;
V_25 = - V_99 ;
goto V_100;
}
V_25 = F_69 ( V_11 -> V_38 . V_87 , V_101 ) ;
if ( V_25 )
goto V_102;
V_25 = F_70 ( V_11 -> V_38 . V_87 , 4096 , 0 ) ;
if ( V_25 )
goto V_102;
V_11 -> V_38 . V_39 = F_59 ( V_11 -> V_38 . V_87 ) ;
V_11 -> V_38 . V_103 = F_71 ( F_64 ( V_11 -> V_38 . V_87 -> V_96 -> V_97 ) ) ;
if ( V_11 -> V_38 . V_103 == NULL ) {
V_25 = - V_99 ;
goto V_104;
}
F_72 ( L_10 ,
V_11 -> V_84 , V_11 -> V_38 . V_39 ) ;
return 0 ;
V_104:
F_65 ( V_11 -> V_38 . V_87 ) ;
V_102:
F_66 ( & V_11 -> V_38 . V_87 -> V_98 ) ;
V_100:
return V_25 ;
}
static int F_73 ( struct V_20 * V_21 )
{
int V_25 , V_105 ;
struct V_10 * V_11 = V_21 -> V_11 ;
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_106 * V_107 = & V_13 -> V_108 ;
if ( V_107 -> V_109 == 0 )
return 0 ;
V_11 -> V_110 = true ;
V_25 = F_74 ( V_21 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_8 ( V_21 , ( V_107 -> V_109 * 2 + 2 ) ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_11 , F_75 ( V_107 -> V_109 ) ) ;
for ( V_105 = 0 ; V_105 < V_107 -> V_109 ; V_105 ++ ) {
F_76 ( V_11 , V_107 -> V_80 [ V_105 ] . V_63 ) ;
F_9 ( V_11 , V_107 -> V_80 [ V_105 ] . V_58 ) ;
}
F_9 ( V_11 , V_31 ) ;
F_10 ( V_11 ) ;
V_11 -> V_110 = true ;
V_25 = F_74 ( V_21 ) ;
if ( V_25 )
return V_25 ;
F_72 ( L_11 , V_107 -> V_109 ) ;
return 0 ;
}
static int F_77 ( struct V_20 * V_21 )
{
int V_25 ;
V_25 = F_73 ( V_21 ) ;
if ( V_25 != 0 )
return V_25 ;
V_25 = F_78 ( V_21 ) ;
if ( V_25 )
return V_25 ;
return 0 ;
}
static int F_79 ( struct V_12 * V_13 ,
T_3 V_63 ,
const T_1 V_111 , const T_1 V_112 )
{
const T_1 V_113 = V_13 -> V_108 . V_109 ;
if ( F_38 ( V_113 >= V_114 ) )
return - V_115 ;
V_13 -> V_108 . V_80 [ V_113 ] . V_63 = V_63 ;
V_13 -> V_108 . V_80 [ V_113 ] . V_58 = V_112 ;
V_13 -> V_108 . V_80 [ V_113 ] . V_111 = V_111 ;
V_13 -> V_108 . V_109 ++ ;
return 0 ;
}
static int F_80 ( struct V_10 * V_11 , T_3 V_80 )
{
struct V_12 * V_13 = V_11 -> V_14 -> V_15 ;
struct V_106 * V_116 = & V_13 -> V_108 ;
const T_4 V_117 = V_116 -> V_118 [ V_11 -> V_68 ] ;
if ( F_38 ( V_117 >= V_119 ) )
return - V_120 ;
F_81 ( F_82 ( V_11 -> V_61 , V_117 ) ,
F_83 ( V_80 ) ) ;
V_116 -> V_118 [ V_11 -> V_68 ] ++ ;
return 0 ;
}
static int F_84 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
F_85 ( V_121 , V_122 ) ;
F_85 ( V_123 , V_124 ) ;
F_85 ( V_125 ,
V_126 ) ;
F_85 ( V_127 ,
V_128 |
V_129 ) ;
F_86 ( V_130 , V_131 ) ;
F_85 ( V_132 , V_133 ) ;
F_87 ( V_134 ,
V_135 ,
V_136 ) ;
return 0 ;
}
static int F_88 ( struct V_10 * V_11 )
{
int V_25 ;
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
V_25 = F_84 ( V_11 ) ;
if ( V_25 )
return V_25 ;
F_85 ( V_125 , V_137 ) ;
F_85 ( V_138 ,
V_139 ) ;
F_85 ( V_140 ,
V_141 ) ;
F_85 ( V_127 ,
V_142 |
( F_89 ( V_14 ) ? V_143 : 0 ) ) ;
return 0 ;
}
static int F_90 ( struct V_10 * V_11 )
{
int V_25 ;
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
V_25 = F_84 ( V_11 ) ;
if ( V_25 )
return V_25 ;
F_85 ( V_125 , V_137 ) ;
F_85 ( V_144 , V_145 ) ;
return 0 ;
}
static int F_91 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
T_4 V_146 ;
int V_25 ;
F_30 ( V_147 , F_28 ( V_147 ) |
V_148 ) ;
F_30 ( V_149 , F_28 ( V_149 ) |
V_150 ) ;
F_85 ( V_125 ,
V_126 ) ;
F_85 ( V_140 ,
V_151 ) ;
if ( F_92 ( V_14 , 0 , V_152 ) ||
F_93 ( V_14 , 0 , V_153 ) )
F_86 ( V_154 ,
V_155 ) ;
if ( F_92 ( V_14 , 0 , V_152 ) ||
F_93 ( V_14 , 0 , V_153 ) ) {
F_85 ( V_156 ,
V_157 ) ;
}
if ( F_92 ( V_14 , V_158 , V_159 ) || F_94 ( V_14 ) )
F_85 ( V_160 ,
V_161 ) ;
F_85 ( V_132 , ( V_133 |
V_162 ) ) ;
F_86 ( V_154 ,
V_163 ) ;
if ( F_92 ( V_14 , V_158 , V_158 ) ||
F_93 ( V_14 , 0 , V_153 ) )
F_85 ( V_164 ,
V_165 ) ;
V_146 = V_142 ;
if ( F_92 ( V_14 , V_166 , V_159 ) ||
F_93 ( V_14 , V_167 , V_159 ) )
V_146 |= V_168 ;
F_85 ( V_127 , V_146 ) ;
if ( F_95 ( V_14 ) || F_93 ( V_14 , 0 , V_167 ) )
F_85 ( V_140 ,
V_141 ) ;
F_85 ( V_169 , V_170 ) ;
F_30 ( V_171 , ( F_28 ( V_171 ) |
V_172 ) ) ;
V_25 = F_80 ( V_11 , V_173 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_80 ( V_11 , V_174 ) ;
if ( V_25 )
return V_25 ;
return 0 ;
}
static int F_96 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
T_5 V_175 [ 3 ] = { 0 , 0 , 0 } ;
unsigned int V_105 ;
for ( V_105 = 0 ; V_105 < 3 ; V_105 ++ ) {
T_5 V_176 ;
if ( ! F_97 ( V_13 -> V_177 . V_178 [ V_105 ] ) )
continue;
V_176 = F_98 ( V_13 -> V_177 . V_178 [ V_105 ] ) - 1 ;
V_175 [ V_105 ] = 3 - V_176 ;
}
if ( V_175 [ 0 ] == 0 && V_175 [ 1 ] == 0 && V_175 [ 2 ] == 0 )
return 0 ;
F_87 ( V_134 ,
F_99 ( 2 ) |
F_99 ( 1 ) |
F_99 ( 0 ) ,
F_100 ( 2 , V_175 [ 2 ] ) |
F_100 ( 1 , V_175 [ 1 ] ) |
F_100 ( 0 , V_175 [ 0 ] ) ) ;
return 0 ;
}
static int F_101 ( struct V_10 * V_11 )
{
int V_25 ;
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
V_25 = F_91 ( V_11 ) ;
if ( V_25 )
return V_25 ;
if ( F_92 ( V_14 , V_179 , V_159 ) ) {
F_30 ( V_180 ,
F_40 ( V_181 ) ) ;
}
if ( F_92 ( V_14 , 0 , V_182 ) ) {
F_30 ( V_183 ,
F_40 ( V_184 ) ) ;
}
if ( F_92 ( V_14 , 0 , V_179 ) )
F_30 ( V_171 , F_28 ( V_171 ) |
V_185 ) ;
if ( F_92 ( V_14 , V_158 , V_159 ) ) {
F_30 ( V_186 , ( F_28 ( V_186 ) |
V_187 ) ) ;
}
if ( F_92 ( V_14 , V_152 , V_152 ) )
F_85 ( V_144 ,
V_188 ) ;
if ( F_92 ( V_14 , 0 , V_159 ) ) {
F_85 ( V_127 ,
V_129 ) ;
F_30 ( V_149 , F_28 ( V_149 ) |
V_189 ) ;
}
if ( F_92 ( V_14 , V_158 , V_182 ) )
F_85 ( V_127 ,
V_143 |
V_190 ) ;
if ( F_92 ( V_14 , 0 , V_166 ) )
F_85 (
V_191 ,
V_192 ) ;
V_25 = F_80 ( V_11 , V_171 ) ;
if ( V_25 )
return V_25 ;
return F_96 ( V_11 ) ;
}
static int F_102 ( struct V_10 * V_11 )
{
int V_25 ;
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
V_25 = F_91 ( V_11 ) ;
if ( V_25 )
return V_25 ;
if ( F_93 ( V_14 , 0 , V_153 ) )
F_30 ( V_193 , F_28 ( V_193 ) | V_194 ) ;
if ( F_93 ( V_14 , 0 , V_153 ) ) {
F_30 ( V_195 , ( F_28 ( V_195 ) &
~ V_196 ) ) ;
}
F_85 ( V_125 ,
V_137 ) ;
if ( F_93 ( V_14 , 0 , V_167 ) ) {
F_85 (
V_191 ,
V_192 ) ;
}
if ( F_93 ( V_14 , 0 , V_153 ) ) {
V_25 = F_80 ( V_11 , V_197 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_80 ( V_11 , V_171 ) ;
if ( V_25 )
return V_25 ;
}
return 0 ;
}
int F_103 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
F_38 ( V_11 -> V_68 != V_69 ) ;
V_13 -> V_108 . V_109 = 0 ;
V_13 -> V_108 . V_118 [ V_69 ] = 0 ;
if ( F_104 ( V_14 ) )
return F_88 ( V_11 ) ;
if ( F_105 ( V_14 ) )
return F_90 ( V_11 ) ;
if ( F_95 ( V_14 ) )
return F_101 ( V_11 ) ;
if ( F_94 ( V_14 ) )
return F_102 ( V_11 ) ;
return 0 ;
}
static int F_106 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
int V_25 = F_53 ( V_11 ) ;
if ( V_25 )
return V_25 ;
if ( F_24 ( V_14 ) -> V_60 >= 4 && F_24 ( V_14 ) -> V_60 < 7 )
F_30 ( V_123 , F_40 ( V_198 ) ) ;
if ( F_24 ( V_14 ) -> V_60 >= 6 && F_24 ( V_14 ) -> V_60 < 8 )
F_30 ( V_123 , F_40 ( V_124 ) ) ;
if ( F_24 ( V_14 ) -> V_60 == 6 )
F_30 ( V_199 ,
F_40 ( V_200 ) ) ;
if ( F_32 ( V_14 ) )
F_30 ( V_201 ,
F_40 ( V_200 ) |
F_40 ( V_202 ) ) ;
if ( F_33 ( V_14 ) ) {
F_30 ( V_203 ,
F_52 ( V_204 ) ) ;
}
if ( F_24 ( V_14 ) -> V_60 >= 6 && F_24 ( V_14 ) -> V_60 < 8 )
F_30 ( V_121 , F_40 ( V_122 ) ) ;
if ( F_107 ( V_14 ) )
F_108 ( V_11 , ~ F_109 ( V_14 ) ) ;
return F_103 ( V_11 ) ;
}
static void F_110 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
if ( V_13 -> V_205 ) {
F_65 ( V_13 -> V_205 ) ;
F_66 ( & V_13 -> V_205 -> V_98 ) ;
V_13 -> V_205 = NULL ;
}
F_62 ( V_11 ) ;
}
static int F_111 ( struct V_20 * V_206 ,
unsigned int V_207 )
{
#define F_112 8
struct V_10 * V_208 = V_206 -> V_11 ;
struct V_32 * V_14 = V_208 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_10 * V_209 ;
int V_105 , V_25 , V_210 ;
V_210 = F_113 ( F_24 ( V_14 ) -> V_211 ) ;
V_207 += ( V_210 - 1 ) * F_112 ;
#undef F_112
V_25 = F_8 ( V_206 , V_207 ) ;
if ( V_25 )
return V_25 ;
F_114 (waiter, dev_priv, i) {
T_1 V_212 ;
T_2 V_39 = V_208 -> V_213 . V_214 [ V_105 ] ;
if ( V_39 == V_215 )
continue;
V_212 = F_115 ( V_206 ) ;
F_9 ( V_208 , F_15 ( 6 ) ) ;
F_9 ( V_208 , V_57 |
V_44 |
V_55 ) ;
F_9 ( V_208 , F_116 ( V_39 ) ) ;
F_9 ( V_208 , F_117 ( V_39 ) ) ;
F_9 ( V_208 , V_212 ) ;
F_9 ( V_208 , 0 ) ;
F_9 ( V_208 , V_216 |
F_118 ( V_209 -> V_68 ) ) ;
F_9 ( V_208 , 0 ) ;
}
return 0 ;
}
static int F_119 ( struct V_20 * V_206 ,
unsigned int V_207 )
{
#define F_112 6
struct V_10 * V_208 = V_206 -> V_11 ;
struct V_32 * V_14 = V_208 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_10 * V_209 ;
int V_105 , V_25 , V_210 ;
V_210 = F_113 ( F_24 ( V_14 ) -> V_211 ) ;
V_207 += ( V_210 - 1 ) * F_112 ;
#undef F_112
V_25 = F_8 ( V_206 , V_207 ) ;
if ( V_25 )
return V_25 ;
F_114 (waiter, dev_priv, i) {
T_1 V_212 ;
T_2 V_39 = V_208 -> V_213 . V_214 [ V_105 ] ;
if ( V_39 == V_215 )
continue;
V_212 = F_115 ( V_206 ) ;
F_9 ( V_208 , ( V_217 + 1 ) |
V_218 ) ;
F_9 ( V_208 , F_116 ( V_39 ) |
V_219 ) ;
F_9 ( V_208 , F_117 ( V_39 ) ) ;
F_9 ( V_208 , V_212 ) ;
F_9 ( V_208 , V_216 |
F_118 ( V_209 -> V_68 ) ) ;
F_9 ( V_208 , 0 ) ;
}
return 0 ;
}
static int F_120 ( struct V_20 * V_206 ,
unsigned int V_207 )
{
struct V_10 * V_208 = V_206 -> V_11 ;
struct V_32 * V_14 = V_208 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_10 * V_220 ;
int V_105 , V_25 , V_210 ;
#define F_112 3
V_210 = F_113 ( F_24 ( V_14 ) -> V_211 ) ;
V_207 += F_121 ( ( V_210 - 1 ) * F_112 , 2 ) ;
#undef F_112
V_25 = F_8 ( V_206 , V_207 ) ;
if ( V_25 )
return V_25 ;
F_114 (useless, dev_priv, i) {
T_3 V_221 = V_208 -> V_213 . V_222 . signal [ V_105 ] ;
if ( F_122 ( V_221 ) ) {
T_1 V_212 = F_115 ( V_206 ) ;
F_9 ( V_208 , F_75 ( 1 ) ) ;
F_76 ( V_208 , V_221 ) ;
F_9 ( V_208 , V_212 ) ;
}
}
if ( V_210 % 2 == 0 )
F_9 ( V_208 , V_31 ) ;
return 0 ;
}
static int
F_123 ( struct V_20 * V_21 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
int V_25 ;
if ( V_11 -> V_213 . signal )
V_25 = V_11 -> V_213 . signal ( V_21 , 4 ) ;
else
V_25 = F_8 ( V_21 , 4 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_11 , V_223 ) ;
F_9 ( V_11 , V_224 << V_225 ) ;
F_9 ( V_11 , F_115 ( V_21 ) ) ;
F_9 ( V_11 , V_226 ) ;
F_6 ( V_11 ) ;
return 0 ;
}
static inline bool F_124 ( struct V_32 * V_14 ,
T_1 V_212 )
{
struct V_12 * V_13 = V_14 -> V_15 ;
return V_13 -> V_227 < V_212 ;
}
static int
F_125 ( struct V_20 * V_228 ,
struct V_10 * V_208 ,
T_1 V_212 )
{
struct V_10 * V_209 = V_228 -> V_11 ;
struct V_12 * V_13 = V_209 -> V_14 -> V_15 ;
int V_25 ;
V_25 = F_8 ( V_228 , 4 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_209 , V_229 |
V_230 |
V_231 |
V_232 ) ;
F_9 ( V_209 , V_212 ) ;
F_9 ( V_209 ,
F_116 ( F_126 ( V_209 , V_208 -> V_68 ) ) ) ;
F_9 ( V_209 ,
F_117 ( F_126 ( V_209 , V_208 -> V_68 ) ) ) ;
F_10 ( V_209 ) ;
return 0 ;
}
static int
F_127 ( struct V_20 * V_228 ,
struct V_10 * V_208 ,
T_1 V_212 )
{
struct V_10 * V_209 = V_228 -> V_11 ;
T_1 V_233 = V_234 |
V_235 |
V_236 ;
T_1 V_237 = V_208 -> V_213 . V_222 . V_238 [ V_209 -> V_68 ] ;
int V_25 ;
V_212 -= 1 ;
F_38 ( V_237 == V_215 ) ;
V_25 = F_8 ( V_228 , 4 ) ;
if ( V_25 )
return V_25 ;
if ( F_128 ( ! F_124 ( V_209 -> V_14 , V_212 ) ) ) {
F_9 ( V_209 , V_233 | V_237 ) ;
F_9 ( V_209 , V_212 ) ;
F_9 ( V_209 , 0 ) ;
F_9 ( V_209 , V_31 ) ;
} else {
F_9 ( V_209 , V_31 ) ;
F_9 ( V_209 , V_31 ) ;
F_9 ( V_209 , V_31 ) ;
F_9 ( V_209 , V_31 ) ;
}
F_10 ( V_209 ) ;
return 0 ;
}
static int
F_129 ( struct V_20 * V_21 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
T_1 V_37 = V_11 -> V_38 . V_39 + 2 * V_40 ;
int V_25 ;
V_25 = F_8 ( V_21 , 32 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_11 , F_15 ( 4 ) | V_44 |
V_239 |
V_50 ) ;
F_9 ( V_11 , V_11 -> V_38 . V_39 | V_43 ) ;
F_9 ( V_11 , F_115 ( V_21 ) ) ;
F_9 ( V_11 , 0 ) ;
F_130 ( V_11 , V_37 ) ;
V_37 += 2 * V_40 ;
F_130 ( V_11 , V_37 ) ;
V_37 += 2 * V_40 ;
F_130 ( V_11 , V_37 ) ;
V_37 += 2 * V_40 ;
F_130 ( V_11 , V_37 ) ;
V_37 += 2 * V_40 ;
F_130 ( V_11 , V_37 ) ;
V_37 += 2 * V_40 ;
F_130 ( V_11 , V_37 ) ;
F_9 ( V_11 , F_15 ( 4 ) | V_44 |
V_239 |
V_50 |
V_240 ) ;
F_9 ( V_11 , V_11 -> V_38 . V_39 | V_43 ) ;
F_9 ( V_11 , F_115 ( V_21 ) ) ;
F_9 ( V_11 , 0 ) ;
F_6 ( V_11 ) ;
return 0 ;
}
static T_1
F_131 ( struct V_10 * V_11 , bool V_241 )
{
if ( ! V_241 ) {
struct V_12 * V_13 = V_11 -> V_14 -> V_15 ;
F_36 ( F_26 ( V_11 -> V_61 ) ) ;
}
return F_132 ( V_11 , V_224 ) ;
}
static T_1
F_133 ( struct V_10 * V_11 , bool V_241 )
{
return F_132 ( V_11 , V_224 ) ;
}
static void
F_134 ( struct V_10 * V_11 , T_1 V_212 )
{
F_135 ( V_11 , V_224 , V_212 ) ;
}
static T_1
F_136 ( struct V_10 * V_11 , bool V_241 )
{
return V_11 -> V_38 . V_103 [ 0 ] ;
}
static void
F_137 ( struct V_10 * V_11 , T_1 V_212 )
{
V_11 -> V_38 . V_103 [ 0 ] = V_212 ;
}
static bool
F_138 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
if ( F_38 ( ! F_139 ( V_13 ) ) )
return false ;
F_140 ( & V_13 -> V_242 , V_45 ) ;
if ( V_11 -> V_243 ++ == 0 )
F_141 ( V_13 , V_11 -> V_244 ) ;
F_142 ( & V_13 -> V_242 , V_45 ) ;
return true ;
}
static void
F_143 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
F_140 ( & V_13 -> V_242 , V_45 ) ;
if ( -- V_11 -> V_243 == 0 )
F_144 ( V_13 , V_11 -> V_244 ) ;
F_142 ( & V_13 -> V_242 , V_45 ) ;
}
static bool
F_145 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
if ( ! F_139 ( V_13 ) )
return false ;
F_140 ( & V_13 -> V_242 , V_45 ) ;
if ( V_11 -> V_243 ++ == 0 ) {
V_13 -> V_245 &= ~ V_11 -> V_244 ;
F_30 ( V_246 , V_13 -> V_245 ) ;
F_36 ( V_246 ) ;
}
F_142 ( & V_13 -> V_242 , V_45 ) ;
return true ;
}
static void
F_146 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
F_140 ( & V_13 -> V_242 , V_45 ) ;
if ( -- V_11 -> V_243 == 0 ) {
V_13 -> V_245 |= V_11 -> V_244 ;
F_30 ( V_246 , V_13 -> V_245 ) ;
F_36 ( V_246 ) ;
}
F_142 ( & V_13 -> V_242 , V_45 ) ;
}
static bool
F_147 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
if ( ! F_139 ( V_13 ) )
return false ;
F_140 ( & V_13 -> V_242 , V_45 ) ;
if ( V_11 -> V_243 ++ == 0 ) {
V_13 -> V_245 &= ~ V_11 -> V_244 ;
F_148 ( V_246 , V_13 -> V_245 ) ;
F_149 ( V_246 ) ;
}
F_142 ( & V_13 -> V_242 , V_45 ) ;
return true ;
}
static void
F_150 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
F_140 ( & V_13 -> V_242 , V_45 ) ;
if ( -- V_11 -> V_243 == 0 ) {
V_13 -> V_245 |= V_11 -> V_244 ;
F_148 ( V_246 , V_13 -> V_245 ) ;
F_149 ( V_246 ) ;
}
F_142 ( & V_13 -> V_242 , V_45 ) ;
}
static int
F_151 ( struct V_20 * V_21 ,
T_1 V_22 ,
T_1 V_23 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
int V_25 ;
V_25 = F_8 ( V_21 , 2 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_11 , V_26 ) ;
F_9 ( V_11 , V_31 ) ;
F_10 ( V_11 ) ;
return 0 ;
}
static int
F_152 ( struct V_20 * V_21 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
int V_25 ;
V_25 = F_8 ( V_21 , 4 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_11 , V_223 ) ;
F_9 ( V_11 , V_224 << V_225 ) ;
F_9 ( V_11 , F_115 ( V_21 ) ) ;
F_9 ( V_11 , V_226 ) ;
F_6 ( V_11 ) ;
return 0 ;
}
static bool
F_153 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
if ( F_38 ( ! F_139 ( V_13 ) ) )
return false ;
F_140 ( & V_13 -> V_242 , V_45 ) ;
if ( V_11 -> V_243 ++ == 0 ) {
if ( F_107 ( V_14 ) && V_11 -> V_68 == V_69 )
F_108 ( V_11 ,
~ ( V_11 -> V_244 |
F_109 ( V_14 ) ) ) ;
else
F_108 ( V_11 , ~ V_11 -> V_244 ) ;
F_141 ( V_13 , V_11 -> V_244 ) ;
}
F_142 ( & V_13 -> V_242 , V_45 ) ;
return true ;
}
static void
F_154 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
F_140 ( & V_13 -> V_242 , V_45 ) ;
if ( -- V_11 -> V_243 == 0 ) {
if ( F_107 ( V_14 ) && V_11 -> V_68 == V_69 )
F_108 ( V_11 , ~ F_109 ( V_14 ) ) ;
else
F_108 ( V_11 , ~ 0 ) ;
F_144 ( V_13 , V_11 -> V_244 ) ;
}
F_142 ( & V_13 -> V_242 , V_45 ) ;
}
static bool
F_155 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
if ( F_38 ( ! F_139 ( V_13 ) ) )
return false ;
F_140 ( & V_13 -> V_242 , V_45 ) ;
if ( V_11 -> V_243 ++ == 0 ) {
F_108 ( V_11 , ~ V_11 -> V_244 ) ;
F_156 ( V_13 , V_11 -> V_244 ) ;
}
F_142 ( & V_13 -> V_242 , V_45 ) ;
return true ;
}
static void
F_157 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
F_140 ( & V_13 -> V_242 , V_45 ) ;
if ( -- V_11 -> V_243 == 0 ) {
F_108 ( V_11 , ~ 0 ) ;
F_158 ( V_13 , V_11 -> V_244 ) ;
}
F_142 ( & V_13 -> V_242 , V_45 ) ;
}
static bool
F_159 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
if ( F_38 ( ! F_139 ( V_13 ) ) )
return false ;
F_140 ( & V_13 -> V_242 , V_45 ) ;
if ( V_11 -> V_243 ++ == 0 ) {
if ( F_107 ( V_14 ) && V_11 -> V_68 == V_69 ) {
F_108 ( V_11 ,
~ ( V_11 -> V_244 |
V_247 ) ) ;
} else {
F_108 ( V_11 , ~ V_11 -> V_244 ) ;
}
F_36 ( F_160 ( V_11 -> V_61 ) ) ;
}
F_142 ( & V_13 -> V_242 , V_45 ) ;
return true ;
}
static void
F_161 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
F_140 ( & V_13 -> V_242 , V_45 ) ;
if ( -- V_11 -> V_243 == 0 ) {
if ( F_107 ( V_14 ) && V_11 -> V_68 == V_69 ) {
F_108 ( V_11 ,
~ V_247 ) ;
} else {
F_108 ( V_11 , ~ 0 ) ;
}
F_36 ( F_160 ( V_11 -> V_61 ) ) ;
}
F_142 ( & V_13 -> V_242 , V_45 ) ;
}
static int
F_162 ( struct V_20 * V_21 ,
T_2 V_248 , T_1 V_249 ,
unsigned V_250 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
int V_25 ;
V_25 = F_8 ( V_21 , 2 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_11 ,
V_251 |
V_252 |
( V_250 & V_253 ?
0 : V_254 ) ) ;
F_9 ( V_11 , V_248 ) ;
F_10 ( V_11 ) ;
return 0 ;
}
static int
F_163 ( struct V_20 * V_21 ,
T_2 V_248 , T_1 V_255 ,
unsigned V_250 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
T_1 V_256 = V_11 -> V_38 . V_39 ;
int V_25 ;
V_25 = F_8 ( V_21 , 6 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_11 , V_257 | V_258 ) ;
F_9 ( V_11 , V_259 | V_260 | 4096 ) ;
F_9 ( V_11 , V_261 << 16 | 4 ) ;
F_9 ( V_11 , V_256 ) ;
F_9 ( V_11 , 0xdeadbeef ) ;
F_9 ( V_11 , V_31 ) ;
F_10 ( V_11 ) ;
if ( ( V_250 & V_262 ) == 0 ) {
if ( V_255 > V_263 )
return - V_115 ;
V_25 = F_8 ( V_21 , 6 + 2 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_11 , V_264 | V_258 ) ;
F_9 ( V_11 , V_259 | V_265 | 4096 ) ;
F_9 ( V_11 , F_164 ( V_255 , 4096 ) << 16 | 4096 ) ;
F_9 ( V_11 , V_256 ) ;
F_9 ( V_11 , 4096 ) ;
F_9 ( V_11 , V_248 ) ;
F_9 ( V_11 , V_26 ) ;
F_9 ( V_11 , V_31 ) ;
F_10 ( V_11 ) ;
V_248 = V_256 ;
}
V_25 = F_8 ( V_21 , 2 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_11 , V_251 | V_252 ) ;
F_9 ( V_11 , V_248 | ( V_250 & V_253 ?
0 : V_266 ) ) ;
F_10 ( V_11 ) ;
return 0 ;
}
static int
F_165 ( struct V_20 * V_21 ,
T_2 V_248 , T_1 V_255 ,
unsigned V_250 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
int V_25 ;
V_25 = F_8 ( V_21 , 2 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_11 , V_251 | V_252 ) ;
F_9 ( V_11 , V_248 | ( V_250 & V_253 ?
0 : V_266 ) ) ;
F_10 ( V_11 ) ;
return 0 ;
}
static void F_166 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_44 ( V_11 -> V_14 ) ;
if ( ! V_13 -> V_64 )
return;
F_167 ( V_11 -> V_14 , V_13 -> V_64 ) ;
V_11 -> V_78 . V_267 = NULL ;
}
static void F_168 ( struct V_10 * V_11 )
{
struct V_86 * V_87 ;
V_87 = V_11 -> V_78 . V_87 ;
if ( V_87 == NULL )
return;
F_63 ( F_64 ( V_87 -> V_96 -> V_97 ) ) ;
F_65 ( V_87 ) ;
F_66 ( & V_87 -> V_98 ) ;
V_11 -> V_78 . V_87 = NULL ;
}
static int F_169 ( struct V_10 * V_11 )
{
struct V_86 * V_87 = V_11 -> V_78 . V_87 ;
if ( V_87 == NULL ) {
unsigned V_45 ;
int V_25 ;
V_87 = F_68 ( V_11 -> V_14 , 4096 ) ;
if ( V_87 == NULL ) {
F_42 ( L_12 ) ;
return - V_99 ;
}
V_25 = F_69 ( V_87 , V_101 ) ;
if ( V_25 )
goto V_102;
V_45 = 0 ;
if ( ! F_170 ( V_11 -> V_14 ) )
V_45 |= V_268 ;
V_25 = F_70 ( V_87 , 4096 , V_45 ) ;
if ( V_25 ) {
V_102:
F_66 ( & V_87 -> V_98 ) ;
return V_25 ;
}
V_11 -> V_78 . V_87 = V_87 ;
}
V_11 -> V_78 . V_79 = F_59 ( V_87 ) ;
V_11 -> V_78 . V_267 = F_71 ( F_64 ( V_87 -> V_96 -> V_97 ) ) ;
memset ( V_11 -> V_78 . V_267 , 0 , V_91 ) ;
F_72 ( L_13 ,
V_11 -> V_84 , V_11 -> V_78 . V_79 ) ;
return 0 ;
}
static int F_171 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 -> V_15 ;
if ( ! V_13 -> V_64 ) {
V_13 -> V_64 =
F_172 ( V_11 -> V_14 , V_91 , V_91 ) ;
if ( ! V_13 -> V_64 )
return - V_99 ;
}
V_11 -> V_78 . V_267 = V_13 -> V_64 -> V_269 ;
memset ( V_11 -> V_78 . V_267 , 0 , V_91 ) ;
return 0 ;
}
void F_173 ( struct V_6 * V_7 )
{
if ( F_170 ( V_7 -> V_87 -> V_98 . V_14 ) && ! V_7 -> V_87 -> V_270 )
F_174 ( V_7 -> V_271 ) ;
else
F_175 ( V_7 -> V_271 ) ;
V_7 -> V_271 = NULL ;
V_7 -> V_272 = NULL ;
F_65 ( V_7 -> V_87 ) ;
}
static T_1 * F_176 ( struct V_86 * V_87 )
{
struct V_273 V_274 ;
struct V_275 * * V_96 ;
void * V_63 ;
int V_105 ;
V_96 = F_177 ( V_87 -> V_98 . V_3 >> V_276 , sizeof( * V_96 ) ) ;
if ( V_96 == NULL )
return NULL ;
V_105 = 0 ;
F_178 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 )
V_96 [ V_105 ++ ] = F_179 ( & V_274 ) ;
V_63 = F_180 ( V_96 , V_105 , 0 , V_277 ) ;
F_181 ( V_96 ) ;
return V_63 ;
}
int F_182 ( struct V_32 * V_14 ,
struct V_6 * V_7 )
{
struct V_12 * V_13 = F_44 ( V_14 ) ;
struct V_86 * V_87 = V_7 -> V_87 ;
unsigned V_45 = V_278 | 4096 ;
int V_25 ;
if ( F_170 ( V_13 ) && ! V_87 -> V_270 ) {
V_25 = F_70 ( V_87 , V_91 , V_45 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_183 ( V_87 , true ) ;
if ( V_25 ) {
F_65 ( V_87 ) ;
return V_25 ;
}
V_7 -> V_271 = F_176 ( V_87 ) ;
if ( V_7 -> V_271 == NULL ) {
F_65 ( V_87 ) ;
return - V_99 ;
}
} else {
V_25 = F_70 ( V_87 , V_91 ,
V_45 | V_268 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_184 ( V_87 , true ) ;
if ( V_25 ) {
F_65 ( V_87 ) ;
return V_25 ;
}
F_185 ( V_13 ) ;
V_7 -> V_271 = F_186 ( V_13 -> V_279 . V_280 +
F_59 ( V_87 ) , V_7 -> V_3 ) ;
if ( V_7 -> V_271 == NULL ) {
F_65 ( V_87 ) ;
return - V_120 ;
}
}
V_7 -> V_272 = F_187 ( V_87 ) ;
return 0 ;
}
static void F_188 ( struct V_6 * V_7 )
{
F_66 ( & V_7 -> V_87 -> V_98 ) ;
V_7 -> V_87 = NULL ;
}
static int F_189 ( struct V_32 * V_14 ,
struct V_6 * V_7 )
{
struct V_86 * V_87 ;
V_87 = NULL ;
if ( ! F_170 ( V_14 ) )
V_87 = F_190 ( V_14 , V_7 -> V_3 ) ;
if ( V_87 == NULL )
V_87 = F_68 ( V_14 , V_7 -> V_3 ) ;
if ( V_87 == NULL )
return - V_99 ;
V_87 -> V_281 = 1 ;
V_7 -> V_87 = V_87 ;
return 0 ;
}
struct V_6 *
F_191 ( struct V_10 * V_282 , int V_3 )
{
struct V_6 * V_11 ;
int V_25 ;
V_11 = F_192 ( sizeof( * V_11 ) , V_283 ) ;
if ( V_11 == NULL ) {
F_72 ( L_14 ,
V_282 -> V_84 ) ;
return F_193 ( - V_99 ) ;
}
V_11 -> V_11 = V_282 ;
F_194 ( & V_11 -> V_284 , & V_282 -> V_285 ) ;
V_11 -> V_3 = V_3 ;
V_11 -> V_286 = V_3 ;
if ( F_195 ( V_282 -> V_14 ) || F_196 ( V_282 -> V_14 ) )
V_11 -> V_286 -= 2 * V_40 ;
V_11 -> V_8 = - 1 ;
F_2 ( V_11 ) ;
V_25 = F_189 ( V_282 -> V_14 , V_11 ) ;
if ( V_25 ) {
F_72 ( L_15 ,
V_282 -> V_84 , V_25 ) ;
F_197 ( & V_11 -> V_284 ) ;
F_198 ( V_11 ) ;
return F_193 ( V_25 ) ;
}
return V_11 ;
}
void
F_199 ( struct V_6 * V_11 )
{
F_188 ( V_11 ) ;
F_197 ( & V_11 -> V_284 ) ;
F_198 ( V_11 ) ;
}
static int F_200 ( struct V_32 * V_14 ,
struct V_10 * V_11 )
{
struct V_6 * V_7 ;
int V_25 ;
F_38 ( V_11 -> V_18 ) ;
V_11 -> V_14 = V_14 ;
F_201 ( & V_11 -> V_287 ) ;
F_201 ( & V_11 -> V_288 ) ;
F_201 ( & V_11 -> V_289 ) ;
F_201 ( & V_11 -> V_285 ) ;
F_202 ( V_14 , & V_11 -> V_290 ) ;
memset ( V_11 -> V_213 . V_291 , 0 , sizeof( V_11 -> V_213 . V_291 ) ) ;
F_203 ( & V_11 -> V_292 ) ;
V_7 = F_191 ( V_11 , 32 * V_91 ) ;
if ( F_204 ( V_7 ) ) {
V_25 = F_205 ( V_7 ) ;
goto error;
}
V_11 -> V_18 = V_7 ;
if ( F_57 ( V_14 ) ) {
V_25 = F_169 ( V_11 ) ;
if ( V_25 )
goto error;
} else {
F_38 ( V_11 -> V_68 != V_69 ) ;
V_25 = F_171 ( V_11 ) ;
if ( V_25 )
goto error;
}
V_25 = F_182 ( V_14 , V_7 ) ;
if ( V_25 ) {
F_42 ( L_16 ,
V_11 -> V_84 , V_25 ) ;
F_188 ( V_7 ) ;
goto error;
}
V_25 = F_206 ( V_11 ) ;
if ( V_25 )
goto error;
return 0 ;
error:
F_207 ( V_11 ) ;
return V_25 ;
}
void F_207 ( struct V_10 * V_11 )
{
struct V_12 * V_13 ;
if ( ! F_208 ( V_11 ) )
return;
V_13 = F_44 ( V_11 -> V_14 ) ;
if ( V_11 -> V_18 ) {
F_209 ( V_11 ) ;
F_38 ( ! F_45 ( V_11 -> V_14 ) && ( F_39 ( V_11 ) & V_81 ) == 0 ) ;
F_173 ( V_11 -> V_18 ) ;
F_199 ( V_11 -> V_18 ) ;
V_11 -> V_18 = NULL ;
}
if ( V_11 -> V_293 )
V_11 -> V_293 ( V_11 ) ;
if ( F_57 ( V_11 -> V_14 ) ) {
F_168 ( V_11 ) ;
} else {
F_38 ( V_11 -> V_68 != V_69 ) ;
F_166 ( V_11 ) ;
}
F_210 ( V_11 ) ;
F_211 ( & V_11 -> V_290 ) ;
V_11 -> V_14 = NULL ;
}
static int F_212 ( struct V_10 * V_11 , int V_294 )
{
struct V_6 * V_7 = V_11 -> V_18 ;
struct V_20 * V_295 ;
unsigned V_4 ;
int V_25 ;
if ( F_3 ( V_7 ) >= V_294 )
return 0 ;
F_38 ( V_7 -> V_296 ) ;
F_213 (request, &ring->request_list, list) {
V_4 = F_1 ( V_295 -> V_297 , V_7 -> V_2 ,
V_7 -> V_3 ) ;
if ( V_4 >= V_294 )
break;
}
if ( F_38 ( & V_295 -> V_298 == & V_11 -> V_288 ) )
return - V_115 ;
V_25 = F_214 ( V_295 ) ;
if ( V_25 )
return V_25 ;
V_7 -> V_4 = V_4 ;
return 0 ;
}
static void F_215 ( struct V_6 * V_7 )
{
T_4 T_6 * V_299 ;
int V_300 = V_7 -> V_3 - V_7 -> V_2 ;
V_299 = V_7 -> V_271 + V_7 -> V_2 ;
V_300 /= 4 ;
while ( V_300 -- )
F_216 ( V_31 , V_299 ++ ) ;
V_7 -> V_2 = 0 ;
F_2 ( V_7 ) ;
}
int F_217 ( struct V_10 * V_11 )
{
struct V_20 * V_21 ;
if ( F_218 ( & V_11 -> V_288 ) )
return 0 ;
V_21 = F_219 ( V_11 -> V_288 . V_301 ,
struct V_20 ,
V_298 ) ;
return F_220 ( V_21 ,
F_221 ( & F_44 ( V_11 -> V_14 ) -> V_16 . V_302 ) ,
F_44 ( V_11 -> V_14 ) -> V_303 . V_304 ,
NULL , NULL ) ;
}
int F_222 ( struct V_20 * V_295 )
{
V_295 -> V_7 = V_295 -> V_11 -> V_18 ;
return 0 ;
}
int F_223 ( struct V_20 * V_295 )
{
F_224 ( V_295 -> V_7 , V_305 ) ;
return F_8 ( V_295 , 0 ) ;
}
void F_224 ( struct V_6 * V_7 , int V_3 )
{
F_38 ( V_7 -> V_306 ) ;
F_38 ( V_7 -> V_296 ) ;
V_7 -> V_306 = V_3 ;
}
void F_225 ( struct V_6 * V_7 )
{
F_38 ( V_7 -> V_296 ) ;
V_7 -> V_306 = 0 ;
V_7 -> V_296 = false ;
}
void F_226 ( struct V_6 * V_7 )
{
F_38 ( V_7 -> V_296 ) ;
V_7 -> V_296 = true ;
V_7 -> V_307 = V_7 -> V_2 ;
}
void F_227 ( struct V_6 * V_7 )
{
F_38 ( ! V_7 -> V_296 ) ;
if ( V_7 -> V_2 > V_7 -> V_307 ) {
F_228 ( V_7 -> V_2 > V_7 -> V_307 + V_7 -> V_306 ,
L_17 ,
V_7 -> V_2 - V_7 -> V_307 , V_7 -> V_306 ) ;
} else {
}
V_7 -> V_306 = 0 ;
V_7 -> V_296 = false ;
}
static int F_229 ( struct V_10 * V_11 , int V_308 )
{
struct V_6 * V_7 = V_11 -> V_18 ;
int V_309 = V_7 -> V_286 - V_7 -> V_2 ;
int V_310 = V_7 -> V_3 - V_7 -> V_2 ;
int V_25 , V_311 , V_312 = 0 ;
bool V_313 = false ;
if ( V_7 -> V_296 )
V_311 = V_308 ;
else
V_311 = V_308 + V_7 -> V_306 ;
if ( F_230 ( V_308 > V_309 ) ) {
V_312 = V_310 + V_311 ;
V_313 = true ;
} else {
if ( F_230 ( V_311 > V_309 ) ) {
V_312 = V_310 + V_7 -> V_306 ;
} else if ( V_311 > V_7 -> V_4 ) {
V_312 = V_311 ;
}
}
if ( V_312 ) {
V_25 = F_212 ( V_11 , V_312 ) ;
if ( F_230 ( V_25 ) )
return V_25 ;
if ( V_313 )
F_215 ( V_7 ) ;
}
return 0 ;
}
int F_8 ( struct V_20 * V_21 ,
int V_207 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
int V_25 ;
F_38 ( V_21 == NULL ) ;
V_11 = V_21 -> V_11 ;
V_13 = V_11 -> V_14 -> V_15 ;
V_25 = F_231 ( & V_13 -> V_16 ,
V_13 -> V_303 . V_304 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_229 ( V_11 , V_207 * sizeof( T_4 ) ) ;
if ( V_25 )
return V_25 ;
V_11 -> V_18 -> V_4 -= V_207 * sizeof( T_4 ) ;
return 0 ;
}
int F_232 ( struct V_20 * V_21 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
int V_207 = ( V_11 -> V_18 -> V_2 & ( V_40 - 1 ) ) / sizeof( T_4 ) ;
int V_25 ;
if ( V_207 == 0 )
return 0 ;
V_207 = V_40 / sizeof( T_4 ) - V_207 ;
V_25 = F_8 ( V_21 , V_207 ) ;
if ( V_25 )
return V_25 ;
while ( V_207 -- )
F_9 ( V_11 , V_31 ) ;
F_10 ( V_11 ) ;
return 0 ;
}
void F_233 ( struct V_10 * V_11 , T_1 V_212 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
if ( F_24 ( V_14 ) -> V_60 == 6 || F_24 ( V_14 ) -> V_60 == 7 ) {
F_30 ( F_234 ( V_11 -> V_61 ) , 0 ) ;
F_30 ( F_235 ( V_11 -> V_61 ) , 0 ) ;
if ( F_236 ( V_14 ) )
F_30 ( F_237 ( V_11 -> V_61 ) , 0 ) ;
}
V_11 -> V_314 ( V_11 , V_212 ) ;
V_11 -> V_95 . V_212 = V_212 ;
}
static void F_238 ( struct V_10 * V_11 ,
T_1 V_58 )
{
struct V_12 * V_13 = V_11 -> V_14 -> V_15 ;
F_30 ( V_315 ,
F_40 ( V_316 ) ) ;
F_239 ( V_317 , 0x0 ) ;
if ( F_41 ( ( F_28 ( V_315 ) &
V_318 ) == 0 ,
50 ) )
F_42 ( L_18 ) ;
F_22 ( V_11 , V_58 ) ;
F_36 ( F_240 ( V_11 -> V_61 ) ) ;
F_30 ( V_315 ,
F_52 ( V_316 ) ) ;
}
static int F_241 ( struct V_20 * V_21 ,
T_1 V_319 , T_1 V_320 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
T_4 V_24 ;
int V_25 ;
V_25 = F_8 ( V_21 , 4 ) ;
if ( V_25 )
return V_25 ;
V_24 = V_217 ;
if ( F_24 ( V_11 -> V_14 ) -> V_60 >= 8 )
V_24 += 1 ;
V_24 |= V_321 | V_218 ;
if ( V_319 & V_322 )
V_24 |= V_323 | V_324 ;
F_9 ( V_11 , V_24 ) ;
F_9 ( V_11 , V_325 | V_219 ) ;
if ( F_24 ( V_11 -> V_14 ) -> V_60 >= 8 ) {
F_9 ( V_11 , 0 ) ;
F_9 ( V_11 , 0 ) ;
} else {
F_9 ( V_11 , 0 ) ;
F_9 ( V_11 , V_31 ) ;
}
F_10 ( V_11 ) ;
return 0 ;
}
static int
F_242 ( struct V_20 * V_21 ,
T_2 V_248 , T_1 V_255 ,
unsigned V_250 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
bool V_326 = F_243 ( V_11 -> V_14 ) &&
! ( V_250 & V_253 ) ;
int V_25 ;
V_25 = F_8 ( V_21 , 4 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_11 , V_327 | ( V_326 << 8 ) |
( V_250 & V_328 ?
V_329 : 0 ) ) ;
F_9 ( V_11 , F_116 ( V_248 ) ) ;
F_9 ( V_11 , F_117 ( V_248 ) ) ;
F_9 ( V_11 , V_31 ) ;
F_10 ( V_11 ) ;
return 0 ;
}
static int
F_244 ( struct V_20 * V_21 ,
T_2 V_248 , T_1 V_255 ,
unsigned V_250 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
int V_25 ;
V_25 = F_8 ( V_21 , 2 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_11 ,
V_251 |
( V_250 & V_253 ?
0 : V_330 | V_331 ) |
( V_250 & V_328 ?
V_329 : 0 ) ) ;
F_9 ( V_11 , V_248 ) ;
F_10 ( V_11 ) ;
return 0 ;
}
static int
F_245 ( struct V_20 * V_21 ,
T_2 V_248 , T_1 V_255 ,
unsigned V_250 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
int V_25 ;
V_25 = F_8 ( V_21 , 2 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_11 ,
V_251 |
( V_250 & V_253 ?
0 : V_254 ) ) ;
F_9 ( V_11 , V_248 ) ;
F_10 ( V_11 ) ;
return 0 ;
}
static int F_246 ( struct V_20 * V_21 ,
T_1 V_319 , T_1 V_320 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
struct V_32 * V_14 = V_11 -> V_14 ;
T_4 V_24 ;
int V_25 ;
V_25 = F_8 ( V_21 , 4 ) ;
if ( V_25 )
return V_25 ;
V_24 = V_217 ;
if ( F_24 ( V_14 ) -> V_60 >= 8 )
V_24 += 1 ;
V_24 |= V_321 | V_218 ;
if ( V_319 & V_27 )
V_24 |= V_323 ;
F_9 ( V_11 , V_24 ) ;
F_9 ( V_11 , V_325 | V_219 ) ;
if ( F_24 ( V_14 ) -> V_60 >= 8 ) {
F_9 ( V_11 , 0 ) ;
F_9 ( V_11 , 0 ) ;
} else {
F_9 ( V_11 , 0 ) ;
F_9 ( V_11 , V_31 ) ;
}
F_10 ( V_11 ) ;
return 0 ;
}
int F_247 ( struct V_32 * V_14 )
{
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_10 * V_11 = & V_13 -> V_11 [ V_69 ] ;
struct V_86 * V_87 ;
int V_25 ;
V_11 -> V_84 = L_19 ;
V_11 -> V_68 = V_69 ;
V_11 -> V_332 = V_333 ;
V_11 -> V_61 = V_334 ;
if ( F_24 ( V_14 ) -> V_60 >= 8 ) {
if ( F_248 ( V_14 ) ) {
V_87 = F_68 ( V_14 , 4096 ) ;
if ( V_87 == NULL ) {
F_42 ( L_20 ) ;
V_335 . V_336 = 0 ;
} else {
F_69 ( V_87 , V_101 ) ;
V_25 = F_70 ( V_87 , 0 , V_337 ) ;
if ( V_25 != 0 ) {
F_66 ( & V_87 -> V_98 ) ;
F_42 ( L_21 ) ;
V_335 . V_336 = 0 ;
} else
V_13 -> V_205 = V_87 ;
}
}
V_11 -> V_338 = F_77 ;
V_11 -> V_339 = F_123 ;
V_11 -> V_320 = F_20 ;
V_11 -> V_340 = F_159 ;
V_11 -> V_341 = F_161 ;
V_11 -> V_244 = V_342 ;
V_11 -> V_343 = F_131 ;
V_11 -> V_314 = F_134 ;
if ( F_248 ( V_14 ) ) {
F_38 ( ! V_13 -> V_205 ) ;
V_11 -> V_213 . V_344 = F_125 ;
V_11 -> V_213 . signal = F_111 ;
V_345 ;
}
} else if ( F_24 ( V_14 ) -> V_60 >= 6 ) {
V_11 -> V_338 = F_77 ;
V_11 -> V_339 = F_123 ;
V_11 -> V_320 = F_18 ;
if ( F_24 ( V_14 ) -> V_60 == 6 )
V_11 -> V_320 = F_16 ;
V_11 -> V_340 = F_153 ;
V_11 -> V_341 = F_154 ;
V_11 -> V_244 = V_342 ;
V_11 -> V_343 = F_131 ;
V_11 -> V_314 = F_134 ;
if ( F_248 ( V_14 ) ) {
V_11 -> V_213 . V_344 = F_127 ;
V_11 -> V_213 . signal = F_120 ;
V_11 -> V_213 . V_222 . V_238 [ V_69 ] = V_215 ;
V_11 -> V_213 . V_222 . V_238 [ V_74 ] = V_346 ;
V_11 -> V_213 . V_222 . V_238 [ V_71 ] = V_347 ;
V_11 -> V_213 . V_222 . V_238 [ V_76 ] = V_348 ;
V_11 -> V_213 . V_222 . V_238 [ V_73 ] = V_215 ;
V_11 -> V_213 . V_222 . signal [ V_69 ] = V_349 ;
V_11 -> V_213 . V_222 . signal [ V_74 ] = V_350 ;
V_11 -> V_213 . V_222 . signal [ V_71 ] = V_351 ;
V_11 -> V_213 . V_222 . signal [ V_76 ] = V_352 ;
V_11 -> V_213 . V_222 . signal [ V_73 ] = V_349 ;
}
} else if ( F_13 ( V_14 ) ) {
V_11 -> V_339 = F_129 ;
V_11 -> V_320 = F_11 ;
V_11 -> V_343 = F_136 ;
V_11 -> V_314 = F_137 ;
V_11 -> V_340 = F_138 ;
V_11 -> V_341 = F_143 ;
V_11 -> V_244 = V_342 |
V_353 ;
} else {
V_11 -> V_339 = F_152 ;
if ( F_24 ( V_14 ) -> V_60 < 4 )
V_11 -> V_320 = F_7 ;
else
V_11 -> V_320 = F_11 ;
V_11 -> V_343 = F_133 ;
V_11 -> V_314 = F_134 ;
if ( F_45 ( V_14 ) ) {
V_11 -> V_340 = F_147 ;
V_11 -> V_341 = F_150 ;
} else {
V_11 -> V_340 = F_145 ;
V_11 -> V_341 = F_146 ;
}
V_11 -> V_244 = V_354 ;
}
V_11 -> V_19 = F_21 ;
if ( F_249 ( V_14 ) )
V_11 -> V_355 = F_244 ;
else if ( F_250 ( V_14 ) )
V_11 -> V_355 = F_242 ;
else if ( F_24 ( V_14 ) -> V_60 >= 6 )
V_11 -> V_355 = F_245 ;
else if ( F_24 ( V_14 ) -> V_60 >= 4 )
V_11 -> V_355 = F_162 ;
else if ( F_195 ( V_14 ) || F_196 ( V_14 ) )
V_11 -> V_355 = F_163 ;
else
V_11 -> V_355 = F_165 ;
V_11 -> V_356 = F_106 ;
V_11 -> V_293 = F_110 ;
if ( F_251 ( V_14 ) ) {
V_87 = F_68 ( V_14 , V_357 ) ;
if ( V_87 == NULL ) {
F_42 ( L_22 ) ;
return - V_99 ;
}
V_25 = F_70 ( V_87 , 0 , 0 ) ;
if ( V_25 != 0 ) {
F_66 ( & V_87 -> V_98 ) ;
F_42 ( L_23 ) ;
return V_25 ;
}
V_11 -> V_38 . V_87 = V_87 ;
V_11 -> V_38 . V_39 = F_59 ( V_87 ) ;
}
V_25 = F_200 ( V_14 , V_11 ) ;
if ( V_25 )
return V_25 ;
if ( F_24 ( V_14 ) -> V_60 >= 5 ) {
V_25 = F_67 ( V_11 ) ;
if ( V_25 )
return V_25 ;
}
return 0 ;
}
int F_252 ( struct V_32 * V_14 )
{
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_10 * V_11 = & V_13 -> V_11 [ V_74 ] ;
V_11 -> V_84 = L_24 ;
V_11 -> V_68 = V_74 ;
V_11 -> V_332 = V_358 ;
V_11 -> V_19 = F_21 ;
if ( F_24 ( V_14 ) -> V_60 >= 6 ) {
V_11 -> V_61 = V_359 ;
if ( F_33 ( V_14 ) )
V_11 -> V_19 = F_238 ;
V_11 -> V_320 = F_241 ;
V_11 -> V_339 = F_123 ;
V_11 -> V_343 = F_131 ;
V_11 -> V_314 = F_134 ;
if ( F_24 ( V_14 ) -> V_60 >= 8 ) {
V_11 -> V_244 =
V_342 << V_360 ;
V_11 -> V_340 = F_159 ;
V_11 -> V_341 = F_161 ;
V_11 -> V_355 =
F_242 ;
if ( F_248 ( V_14 ) ) {
V_11 -> V_213 . V_344 = F_125 ;
V_11 -> V_213 . signal = F_119 ;
V_345 ;
}
} else {
V_11 -> V_244 = V_361 ;
V_11 -> V_340 = F_153 ;
V_11 -> V_341 = F_154 ;
V_11 -> V_355 =
F_245 ;
if ( F_248 ( V_14 ) ) {
V_11 -> V_213 . V_344 = F_127 ;
V_11 -> V_213 . signal = F_120 ;
V_11 -> V_213 . V_222 . V_238 [ V_69 ] = V_362 ;
V_11 -> V_213 . V_222 . V_238 [ V_74 ] = V_215 ;
V_11 -> V_213 . V_222 . V_238 [ V_71 ] = V_363 ;
V_11 -> V_213 . V_222 . V_238 [ V_76 ] = V_364 ;
V_11 -> V_213 . V_222 . V_238 [ V_73 ] = V_215 ;
V_11 -> V_213 . V_222 . signal [ V_69 ] = V_365 ;
V_11 -> V_213 . V_222 . signal [ V_74 ] = V_349 ;
V_11 -> V_213 . V_222 . signal [ V_71 ] = V_366 ;
V_11 -> V_213 . V_222 . signal [ V_76 ] = V_367 ;
V_11 -> V_213 . V_222 . signal [ V_73 ] = V_349 ;
}
}
} else {
V_11 -> V_61 = V_368 ;
V_11 -> V_320 = F_151 ;
V_11 -> V_339 = F_152 ;
V_11 -> V_343 = F_133 ;
V_11 -> V_314 = F_134 ;
if ( F_13 ( V_14 ) ) {
V_11 -> V_244 = V_369 ;
V_11 -> V_340 = F_138 ;
V_11 -> V_341 = F_143 ;
} else {
V_11 -> V_244 = V_370 ;
V_11 -> V_340 = F_145 ;
V_11 -> V_341 = F_146 ;
}
V_11 -> V_355 = F_162 ;
}
V_11 -> V_356 = F_53 ;
return F_200 ( V_14 , V_11 ) ;
}
int F_253 ( struct V_32 * V_14 )
{
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_10 * V_11 = & V_13 -> V_11 [ V_73 ] ;
V_11 -> V_84 = L_25 ;
V_11 -> V_68 = V_73 ;
V_11 -> V_332 = V_358 ;
V_11 -> V_19 = F_21 ;
V_11 -> V_61 = V_371 ;
V_11 -> V_320 = F_241 ;
V_11 -> V_339 = F_123 ;
V_11 -> V_343 = F_131 ;
V_11 -> V_314 = F_134 ;
V_11 -> V_244 =
V_342 << V_372 ;
V_11 -> V_340 = F_159 ;
V_11 -> V_341 = F_161 ;
V_11 -> V_355 =
F_242 ;
if ( F_248 ( V_14 ) ) {
V_11 -> V_213 . V_344 = F_125 ;
V_11 -> V_213 . signal = F_119 ;
V_345 ;
}
V_11 -> V_356 = F_53 ;
return F_200 ( V_14 , V_11 ) ;
}
int F_254 ( struct V_32 * V_14 )
{
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_10 * V_11 = & V_13 -> V_11 [ V_71 ] ;
V_11 -> V_84 = L_26 ;
V_11 -> V_68 = V_71 ;
V_11 -> V_332 = V_373 ;
V_11 -> V_61 = V_374 ;
V_11 -> V_19 = F_21 ;
V_11 -> V_320 = F_246 ;
V_11 -> V_339 = F_123 ;
V_11 -> V_343 = F_131 ;
V_11 -> V_314 = F_134 ;
if ( F_24 ( V_14 ) -> V_60 >= 8 ) {
V_11 -> V_244 =
V_342 << V_375 ;
V_11 -> V_340 = F_159 ;
V_11 -> V_341 = F_161 ;
V_11 -> V_355 = F_242 ;
if ( F_248 ( V_14 ) ) {
V_11 -> V_213 . V_344 = F_125 ;
V_11 -> V_213 . signal = F_119 ;
V_345 ;
}
} else {
V_11 -> V_244 = V_376 ;
V_11 -> V_340 = F_153 ;
V_11 -> V_341 = F_154 ;
V_11 -> V_355 = F_245 ;
if ( F_248 ( V_14 ) ) {
V_11 -> V_213 . signal = F_120 ;
V_11 -> V_213 . V_344 = F_127 ;
V_11 -> V_213 . V_222 . V_238 [ V_69 ] = V_377 ;
V_11 -> V_213 . V_222 . V_238 [ V_74 ] = V_378 ;
V_11 -> V_213 . V_222 . V_238 [ V_71 ] = V_215 ;
V_11 -> V_213 . V_222 . V_238 [ V_76 ] = V_379 ;
V_11 -> V_213 . V_222 . V_238 [ V_73 ] = V_215 ;
V_11 -> V_213 . V_222 . signal [ V_69 ] = V_380 ;
V_11 -> V_213 . V_222 . signal [ V_74 ] = V_381 ;
V_11 -> V_213 . V_222 . signal [ V_71 ] = V_349 ;
V_11 -> V_213 . V_222 . signal [ V_76 ] = V_382 ;
V_11 -> V_213 . V_222 . signal [ V_73 ] = V_349 ;
}
}
V_11 -> V_356 = F_53 ;
return F_200 ( V_14 , V_11 ) ;
}
int F_255 ( struct V_32 * V_14 )
{
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_10 * V_11 = & V_13 -> V_11 [ V_76 ] ;
V_11 -> V_84 = L_27 ;
V_11 -> V_68 = V_76 ;
V_11 -> V_332 = V_383 ;
V_11 -> V_61 = V_384 ;
V_11 -> V_19 = F_21 ;
V_11 -> V_320 = F_246 ;
V_11 -> V_339 = F_123 ;
V_11 -> V_343 = F_131 ;
V_11 -> V_314 = F_134 ;
if ( F_24 ( V_14 ) -> V_60 >= 8 ) {
V_11 -> V_244 =
V_342 << V_385 ;
V_11 -> V_340 = F_159 ;
V_11 -> V_341 = F_161 ;
V_11 -> V_355 = F_242 ;
if ( F_248 ( V_14 ) ) {
V_11 -> V_213 . V_344 = F_125 ;
V_11 -> V_213 . signal = F_119 ;
V_345 ;
}
} else {
V_11 -> V_244 = V_386 ;
V_11 -> V_340 = F_155 ;
V_11 -> V_341 = F_157 ;
V_11 -> V_355 = F_245 ;
if ( F_248 ( V_14 ) ) {
V_11 -> V_213 . V_344 = F_127 ;
V_11 -> V_213 . signal = F_120 ;
V_11 -> V_213 . V_222 . V_238 [ V_69 ] = V_387 ;
V_11 -> V_213 . V_222 . V_238 [ V_74 ] = V_388 ;
V_11 -> V_213 . V_222 . V_238 [ V_71 ] = V_389 ;
V_11 -> V_213 . V_222 . V_238 [ V_76 ] = V_215 ;
V_11 -> V_213 . V_222 . V_238 [ V_73 ] = V_215 ;
V_11 -> V_213 . V_222 . signal [ V_69 ] = V_390 ;
V_11 -> V_213 . V_222 . signal [ V_74 ] = V_391 ;
V_11 -> V_213 . V_222 . signal [ V_71 ] = V_392 ;
V_11 -> V_213 . V_222 . signal [ V_76 ] = V_349 ;
V_11 -> V_213 . V_222 . signal [ V_73 ] = V_349 ;
}
}
V_11 -> V_356 = F_53 ;
return F_200 ( V_14 , V_11 ) ;
}
int
F_74 ( struct V_20 * V_21 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
int V_25 ;
if ( ! V_11 -> V_110 )
return 0 ;
V_25 = V_11 -> V_320 ( V_21 , 0 , V_322 ) ;
if ( V_25 )
return V_25 ;
F_256 ( V_21 , 0 , V_322 ) ;
V_11 -> V_110 = false ;
return 0 ;
}
int
F_257 ( struct V_20 * V_21 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
T_4 V_23 ;
int V_25 ;
V_23 = 0 ;
if ( V_11 -> V_110 )
V_23 = V_322 ;
V_25 = V_11 -> V_320 ( V_21 , V_322 , V_23 ) ;
if ( V_25 )
return V_25 ;
F_256 ( V_21 , V_322 , V_23 ) ;
V_11 -> V_110 = false ;
return 0 ;
}
void
F_209 ( struct V_10 * V_11 )
{
int V_25 ;
if ( ! F_208 ( V_11 ) )
return;
V_25 = F_217 ( V_11 ) ;
if ( V_25 && ! F_258 ( & F_44 ( V_11 -> V_14 ) -> V_16 ) )
F_42 ( L_28 ,
V_11 -> V_84 , V_25 ) ;
F_43 ( V_11 ) ;
}
