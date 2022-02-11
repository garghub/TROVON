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
bool F_3 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 -> V_15 ;
return V_13 -> V_16 . V_17 & F_4 ( V_11 ) ;
}
static void F_5 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_18 ;
V_7 -> V_2 &= V_7 -> V_3 - 1 ;
if ( F_3 ( V_11 ) )
return;
V_11 -> V_19 ( V_11 , V_7 -> V_2 ) ;
}
static int
F_6 ( struct V_20 * V_21 ,
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
V_25 = F_7 ( V_21 , 2 ) ;
if ( V_25 )
return V_25 ;
F_8 ( V_11 , V_24 ) ;
F_8 ( V_11 , V_31 ) ;
F_9 ( V_11 ) ;
return 0 ;
}
static int
F_10 ( struct V_20 * V_21 ,
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
( F_11 ( V_14 ) || F_12 ( V_14 ) ) )
V_24 |= V_36 ;
V_25 = F_7 ( V_21 , 2 ) ;
if ( V_25 )
return V_25 ;
F_8 ( V_11 , V_24 ) ;
F_8 ( V_11 , V_31 ) ;
F_9 ( V_11 ) ;
return 0 ;
}
static int
F_13 ( struct V_20 * V_21 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
T_1 V_37 = V_11 -> V_38 . V_39 + 2 * V_40 ;
int V_25 ;
V_25 = F_7 ( V_21 , 6 ) ;
if ( V_25 )
return V_25 ;
F_8 ( V_11 , F_14 ( 5 ) ) ;
F_8 ( V_11 , V_41 |
V_42 ) ;
F_8 ( V_11 , V_37 | V_43 ) ;
F_8 ( V_11 , 0 ) ;
F_8 ( V_11 , 0 ) ;
F_8 ( V_11 , V_31 ) ;
F_9 ( V_11 ) ;
V_25 = F_7 ( V_21 , 6 ) ;
if ( V_25 )
return V_25 ;
F_8 ( V_11 , F_14 ( 5 ) ) ;
F_8 ( V_11 , V_44 ) ;
F_8 ( V_11 , V_37 | V_43 ) ;
F_8 ( V_11 , 0 ) ;
F_8 ( V_11 , 0 ) ;
F_8 ( V_11 , V_31 ) ;
F_9 ( V_11 ) ;
return 0 ;
}
static int
F_15 ( struct V_20 * V_21 ,
T_1 V_22 , T_1 V_23 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
T_1 V_45 = 0 ;
T_1 V_37 = V_11 -> V_38 . V_39 + 2 * V_40 ;
int V_25 ;
V_25 = F_13 ( V_21 ) ;
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
V_25 = F_7 ( V_21 , 4 ) ;
if ( V_25 )
return V_25 ;
F_8 ( V_11 , F_14 ( 4 ) ) ;
F_8 ( V_11 , V_45 ) ;
F_8 ( V_11 , V_37 | V_43 ) ;
F_8 ( V_11 , 0 ) ;
F_9 ( V_11 ) ;
return 0 ;
}
static int
F_16 ( struct V_20 * V_21 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
int V_25 ;
V_25 = F_7 ( V_21 , 4 ) ;
if ( V_25 )
return V_25 ;
F_8 ( V_11 , F_14 ( 4 ) ) ;
F_8 ( V_11 , V_41 |
V_42 ) ;
F_8 ( V_11 , 0 ) ;
F_8 ( V_11 , 0 ) ;
F_9 ( V_11 ) ;
return 0 ;
}
static int
F_17 ( struct V_20 * V_21 ,
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
F_16 ( V_21 ) ;
}
V_25 = F_7 ( V_21 , 4 ) ;
if ( V_25 )
return V_25 ;
F_8 ( V_11 , F_14 ( 4 ) ) ;
F_8 ( V_11 , V_45 ) ;
F_8 ( V_11 , V_37 ) ;
F_8 ( V_11 , 0 ) ;
F_9 ( V_11 ) ;
return 0 ;
}
static int
F_18 ( struct V_20 * V_21 ,
T_1 V_45 , T_1 V_37 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
int V_25 ;
V_25 = F_7 ( V_21 , 6 ) ;
if ( V_25 )
return V_25 ;
F_8 ( V_11 , F_14 ( 6 ) ) ;
F_8 ( V_11 , V_45 ) ;
F_8 ( V_11 , V_37 ) ;
F_8 ( V_11 , 0 ) ;
F_8 ( V_11 , 0 ) ;
F_8 ( V_11 , 0 ) ;
F_9 ( V_11 ) ;
return 0 ;
}
static int
F_19 ( struct V_20 * V_21 ,
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
V_25 = F_18 ( V_21 ,
V_41 |
V_42 ,
0 ) ;
if ( V_25 )
return V_25 ;
}
return F_18 ( V_21 , V_45 , V_37 ) ;
}
static void F_20 ( struct V_10 * V_11 ,
T_1 V_58 )
{
struct V_12 * V_13 = V_11 -> V_14 -> V_15 ;
F_21 ( V_11 , V_58 ) ;
}
T_2 F_22 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 -> V_15 ;
T_2 V_59 ;
if ( F_23 ( V_11 -> V_14 ) -> V_60 >= 8 )
V_59 = F_24 ( F_25 ( V_11 -> V_61 ) ,
F_26 ( V_11 -> V_61 ) ) ;
else if ( F_23 ( V_11 -> V_14 ) -> V_60 >= 4 )
V_59 = F_27 ( F_25 ( V_11 -> V_61 ) ) ;
else
V_59 = F_27 ( V_62 ) ;
return V_59 ;
}
static void F_28 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 -> V_15 ;
T_1 V_63 ;
V_63 = V_13 -> V_64 -> V_65 ;
if ( F_23 ( V_11 -> V_14 ) -> V_60 >= 4 )
V_63 |= ( V_13 -> V_64 -> V_65 >> 28 ) & 0xf0 ;
F_29 ( V_66 , V_63 ) ;
}
static void F_30 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_11 -> V_14 -> V_15 ;
T_3 V_67 ;
if ( F_31 ( V_14 ) ) {
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
} else if ( F_32 ( V_11 -> V_14 ) ) {
V_67 = F_33 ( V_11 -> V_61 ) ;
} else {
V_67 = F_34 ( V_11 -> V_61 ) ;
}
F_29 ( V_67 , ( T_1 ) V_11 -> V_78 . V_79 ) ;
F_35 ( V_67 ) ;
if ( F_23 ( V_14 ) -> V_60 >= 6 && F_23 ( V_14 ) -> V_60 < 8 ) {
T_3 V_80 = F_36 ( V_11 -> V_61 ) ;
F_37 ( ( F_38 ( V_11 ) & V_81 ) == 0 ) ;
F_29 ( V_80 ,
F_39 ( V_82 |
V_83 ) ) ;
if ( F_40 ( ( F_27 ( V_80 ) & V_83 ) == 0 ,
1000 ) )
F_41 ( L_1 ,
V_11 -> V_84 ) ;
}
}
static bool F_42 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_43 ( V_11 -> V_14 ) ;
if ( ! F_44 ( V_11 -> V_14 ) ) {
F_45 ( V_11 , F_39 ( V_85 ) ) ;
if ( F_40 ( ( F_38 ( V_11 ) & V_81 ) != 0 , 1000 ) ) {
F_41 ( L_2 ,
V_11 -> V_84 ) ;
if ( F_46 ( V_11 ) != F_47 ( V_11 ) )
return false ;
}
}
F_48 ( V_11 , 0 ) ;
F_49 ( V_11 , 0 ) ;
V_11 -> V_19 ( V_11 , 0 ) ;
if ( ! F_44 ( V_11 -> V_14 ) ) {
( void ) F_50 ( V_11 ) ;
F_45 ( V_11 , F_51 ( V_85 ) ) ;
}
return ( F_46 ( V_11 ) & V_9 ) == 0 ;
}
void F_52 ( struct V_10 * V_11 )
{
memset ( & V_11 -> V_86 , 0 , sizeof( V_11 -> V_86 ) ) ;
}
static int F_53 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_6 * V_7 = V_11 -> V_18 ;
struct V_87 * V_88 = V_7 -> V_88 ;
int V_25 = 0 ;
F_54 ( V_13 , V_89 ) ;
if ( ! F_42 ( V_11 ) ) {
F_55 ( L_3
L_4 ,
V_11 -> V_84 ,
F_50 ( V_11 ) ,
F_46 ( V_11 ) ,
F_47 ( V_11 ) ,
F_56 ( V_11 ) ) ;
if ( ! F_42 ( V_11 ) ) {
F_41 ( L_5
L_4 ,
V_11 -> V_84 ,
F_50 ( V_11 ) ,
F_46 ( V_11 ) ,
F_47 ( V_11 ) ,
F_56 ( V_11 ) ) ;
V_25 = - V_90 ;
goto V_91;
}
}
if ( F_57 ( V_14 ) )
F_30 ( V_11 ) ;
else
F_28 ( V_11 ) ;
F_46 ( V_11 ) ;
F_58 ( V_11 , F_59 ( V_88 ) ) ;
if ( F_46 ( V_11 ) )
F_60 ( L_6 ,
V_11 -> V_84 , F_46 ( V_11 ) ) ;
F_49 ( V_11 , 0 ) ;
( void ) F_46 ( V_11 ) ;
F_48 ( V_11 ,
( ( V_7 -> V_3 - V_92 ) & V_93 )
| V_94 ) ;
if ( F_40 ( ( F_50 ( V_11 ) & V_94 ) != 0 &&
F_56 ( V_11 ) == F_59 ( V_88 ) &&
( F_46 ( V_11 ) & V_9 ) == 0 , 50 ) ) {
F_41 ( L_7
L_8 ,
V_11 -> V_84 ,
F_50 ( V_11 ) ,
F_50 ( V_11 ) & V_94 ,
F_46 ( V_11 ) , F_47 ( V_11 ) ,
F_56 ( V_11 ) ,
( unsigned long ) F_59 ( V_88 ) ) ;
V_25 = - V_90 ;
goto V_91;
}
V_7 -> V_8 = - 1 ;
V_7 -> V_1 = F_46 ( V_11 ) ;
V_7 -> V_2 = F_47 ( V_11 ) & V_95 ;
F_2 ( V_7 ) ;
F_52 ( V_11 ) ;
V_91:
F_61 ( V_13 , V_89 ) ;
return V_25 ;
}
void
F_62 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
if ( V_11 -> V_38 . V_88 == NULL )
return;
if ( F_23 ( V_14 ) -> V_60 >= 5 ) {
F_63 ( F_64 ( V_11 -> V_38 . V_88 -> V_96 -> V_97 ) ) ;
F_65 ( V_11 -> V_38 . V_88 ) ;
}
F_66 ( & V_11 -> V_38 . V_88 -> V_98 ) ;
V_11 -> V_38 . V_88 = NULL ;
}
int
F_67 ( struct V_10 * V_11 )
{
int V_25 ;
F_37 ( V_11 -> V_38 . V_88 ) ;
V_11 -> V_38 . V_88 = F_68 ( V_11 -> V_14 , 4096 ) ;
if ( V_11 -> V_38 . V_88 == NULL ) {
F_41 ( L_9 ) ;
V_25 = - V_99 ;
goto V_100;
}
V_25 = F_69 ( V_11 -> V_38 . V_88 ,
V_101 ) ;
if ( V_25 )
goto V_102;
V_25 = F_70 ( V_11 -> V_38 . V_88 , 4096 , 0 ) ;
if ( V_25 )
goto V_102;
V_11 -> V_38 . V_39 = F_59 ( V_11 -> V_38 . V_88 ) ;
V_11 -> V_38 . V_103 = F_71 ( F_64 ( V_11 -> V_38 . V_88 -> V_96 -> V_97 ) ) ;
if ( V_11 -> V_38 . V_103 == NULL ) {
V_25 = - V_99 ;
goto V_104;
}
F_72 ( L_10 ,
V_11 -> V_84 , V_11 -> V_38 . V_39 ) ;
return 0 ;
V_104:
F_65 ( V_11 -> V_38 . V_88 ) ;
V_102:
F_66 ( & V_11 -> V_38 . V_88 -> V_98 ) ;
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
V_25 = F_7 ( V_21 , ( V_107 -> V_109 * 2 + 2 ) ) ;
if ( V_25 )
return V_25 ;
F_8 ( V_11 , F_75 ( V_107 -> V_109 ) ) ;
for ( V_105 = 0 ; V_105 < V_107 -> V_109 ; V_105 ++ ) {
F_76 ( V_11 , V_107 -> V_80 [ V_105 ] . V_63 ) ;
F_8 ( V_11 , V_107 -> V_80 [ V_105 ] . V_58 ) ;
}
F_8 ( V_11 , V_31 ) ;
F_9 ( V_11 ) ;
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
if ( F_37 ( V_113 >= V_114 ) )
return - V_115 ;
V_13 -> V_108 . V_80 [ V_113 ] . V_63 = V_63 ;
V_13 -> V_108 . V_80 [ V_113 ] . V_58 = V_112 ;
V_13 -> V_108 . V_80 [ V_113 ] . V_111 = V_111 ;
V_13 -> V_108 . V_109 ++ ;
return 0 ;
}
static int F_80 ( struct V_10 * V_11 ,
T_3 V_80 )
{
struct V_12 * V_13 = V_11 -> V_14 -> V_15 ;
struct V_106 * V_116 = & V_13 -> V_108 ;
const T_4 V_117 = V_116 -> V_118 [ V_11 -> V_68 ] ;
if ( F_37 ( V_117 >= V_119 ) )
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
int V_25 ;
F_29 ( V_146 , F_39 ( V_147 ) ) ;
F_29 ( V_148 , F_27 ( V_148 ) |
V_149 ) ;
F_29 ( V_150 , F_27 ( V_150 ) |
V_151 ) ;
F_85 ( V_125 ,
V_152 |
V_126 ) ;
F_85 ( V_140 ,
V_153 ) ;
if ( F_92 ( V_14 , 0 , V_154 ) ||
F_93 ( V_14 , 0 , V_155 ) )
F_86 ( V_156 ,
V_157 ) ;
if ( F_92 ( V_14 , 0 , V_154 ) ||
F_93 ( V_14 , 0 , V_155 ) ) {
F_85 ( V_158 ,
V_159 ) ;
}
F_85 ( V_160 ,
V_161 |
V_162 ) ;
F_85 ( V_132 , ( V_133 |
V_163 ) ) ;
F_86 ( V_156 ,
V_164 ) ;
if ( F_92 ( V_14 , V_165 , V_165 ) ||
F_93 ( V_14 , 0 , V_155 ) )
F_85 ( V_166 ,
V_167 ) ;
F_85 ( V_127 ,
V_142 |
V_168 ) ;
F_85 ( V_127 ,
V_129 ) ;
F_29 ( V_150 , F_27 ( V_150 ) |
V_169 ) ;
if ( F_94 ( V_13 ) ||
F_95 ( V_13 ) ||
F_93 ( V_13 , 0 , V_170 ) )
F_85 ( V_140 ,
V_141 ) ;
F_85 ( V_171 , V_172 ) ;
F_29 ( V_173 , ( F_27 ( V_173 ) |
V_174 ) ) ;
V_25 = F_80 ( V_11 , V_175 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_80 ( V_11 , V_176 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_80 ( V_11 , V_177 ) ;
if ( V_25 )
return V_25 ;
return 0 ;
}
static int F_96 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
T_5 V_178 [ 3 ] = { 0 , 0 , 0 } ;
unsigned int V_105 ;
for ( V_105 = 0 ; V_105 < 3 ; V_105 ++ ) {
T_5 V_179 ;
if ( ! F_97 ( V_13 -> V_180 . V_181 [ V_105 ] ) )
continue;
V_179 = F_98 ( V_13 -> V_180 . V_181 [ V_105 ] ) - 1 ;
V_178 [ V_105 ] = 3 - V_179 ;
}
if ( V_178 [ 0 ] == 0 && V_178 [ 1 ] == 0 && V_178 [ 2 ] == 0 )
return 0 ;
F_87 ( V_134 ,
F_99 ( 2 ) |
F_99 ( 1 ) |
F_99 ( 0 ) ,
F_100 ( 2 , V_178 [ 2 ] ) |
F_100 ( 1 , V_178 [ 1 ] ) |
F_100 ( 0 , V_178 [ 0 ] ) ) ;
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
if ( F_92 ( V_14 , V_182 , V_183 ) ) {
F_29 ( V_184 ,
F_39 ( V_185 ) ) ;
}
if ( F_92 ( V_14 , 0 , V_186 ) ) {
F_29 ( V_187 ,
F_39 ( V_188 ) ) ;
}
if ( F_92 ( V_14 , 0 , V_182 ) )
F_29 ( V_173 , F_27 ( V_173 ) |
V_189 ) ;
if ( F_92 ( V_14 , V_165 , V_183 ) ) {
F_29 ( V_190 , ( F_27 ( V_190 ) |
V_191 ) ) ;
}
if ( F_92 ( V_14 , V_154 , V_154 ) )
F_85 ( V_144 ,
V_192 ) ;
if ( F_92 ( V_14 , V_165 , V_186 ) )
F_85 ( V_127 ,
V_143 |
V_193 ) ;
if ( F_92 ( V_14 , 0 , V_194 ) )
F_85 (
V_195 ,
V_196 ) ;
F_102 ( V_197 , V_198 ) ;
V_25 = F_80 ( V_11 , V_173 ) ;
if ( V_25 )
return V_25 ;
return F_96 ( V_11 ) ;
}
static int F_103 ( struct V_10 * V_11 )
{
int V_25 ;
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
V_25 = F_91 ( V_11 ) ;
if ( V_25 )
return V_25 ;
if ( F_93 ( V_14 , 0 , V_155 ) )
F_29 ( V_199 , F_27 ( V_199 ) | V_200 ) ;
if ( F_93 ( V_14 , 0 , V_155 ) ) {
F_29 ( V_201 , ( F_27 ( V_201 ) &
~ V_202 ) ) ;
}
F_85 ( V_125 ,
V_137 ) ;
if ( F_93 ( V_14 , 0 , V_170 ) ) {
F_85 (
V_195 ,
V_196 ) ;
}
if ( F_93 ( V_14 , 0 , V_155 ) ) {
V_25 = F_80 ( V_11 , V_203 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_80 ( V_11 , V_173 ) ;
if ( V_25 )
return V_25 ;
}
if ( F_93 ( V_13 , 0 , V_170 ) )
F_85 ( V_204 ,
V_205 ) ;
return 0 ;
}
static int F_104 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 -> V_15 ;
int V_25 ;
V_25 = F_91 ( V_11 ) ;
if ( V_25 )
return V_25 ;
F_29 ( V_190 , ( F_27 ( V_190 ) |
V_191 ) ) ;
if ( F_105 ( V_13 , 0 , V_206 ) )
F_102 ( V_207 ,
V_208 ) ;
if ( F_105 ( V_13 , V_209 , V_209 ) )
F_85 ( V_127 ,
V_143 ) ;
if ( F_105 ( V_13 , 0 , V_210 ) )
F_29 ( V_173 , F_27 ( V_173 ) |
V_189 ) ;
if ( F_105 ( V_13 , 0 , V_206 ) )
F_85 ( V_204 ,
V_205 ) ;
F_102 ( V_197 , V_198 ) ;
F_85 (
V_195 ,
V_196 ) ;
V_25 = F_80 ( V_11 , V_173 ) ;
if ( V_25 )
return V_25 ;
return 0 ;
}
int F_106 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
F_37 ( V_11 -> V_68 != V_69 ) ;
V_13 -> V_108 . V_109 = 0 ;
V_13 -> V_108 . V_118 [ V_69 ] = 0 ;
if ( F_107 ( V_14 ) )
return F_88 ( V_11 ) ;
if ( F_108 ( V_14 ) )
return F_90 ( V_11 ) ;
if ( F_94 ( V_14 ) )
return F_101 ( V_11 ) ;
if ( F_109 ( V_14 ) )
return F_103 ( V_11 ) ;
if ( F_95 ( V_13 ) )
return F_104 ( V_11 ) ;
return 0 ;
}
static int F_110 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
int V_25 = F_53 ( V_11 ) ;
if ( V_25 )
return V_25 ;
if ( F_23 ( V_14 ) -> V_60 >= 4 && F_23 ( V_14 ) -> V_60 < 7 )
F_29 ( V_123 , F_39 ( V_211 ) ) ;
if ( F_23 ( V_14 ) -> V_60 >= 6 && F_23 ( V_14 ) -> V_60 < 8 )
F_29 ( V_123 , F_39 ( V_124 ) ) ;
if ( F_23 ( V_14 ) -> V_60 == 6 )
F_29 ( V_212 ,
F_39 ( V_213 ) ) ;
if ( F_31 ( V_14 ) )
F_29 ( V_214 ,
F_39 ( V_213 ) |
F_39 ( V_215 ) ) ;
if ( F_32 ( V_14 ) ) {
F_29 ( V_216 ,
F_51 ( V_217 ) ) ;
}
if ( F_23 ( V_14 ) -> V_60 >= 6 && F_23 ( V_14 ) -> V_60 < 8 )
F_29 ( V_121 , F_39 ( V_122 ) ) ;
if ( F_111 ( V_14 ) )
F_112 ( V_11 , ~ F_113 ( V_14 ) ) ;
return F_106 ( V_11 ) ;
}
static void F_114 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
if ( V_13 -> V_218 ) {
F_65 ( V_13 -> V_218 ) ;
F_66 ( & V_13 -> V_218 -> V_98 ) ;
V_13 -> V_218 = NULL ;
}
F_62 ( V_11 ) ;
}
static int F_115 ( struct V_20 * V_219 ,
unsigned int V_220 )
{
#define F_116 8
struct V_10 * V_221 = V_219 -> V_11 ;
struct V_32 * V_14 = V_221 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_10 * V_222 ;
enum V_223 V_68 ;
int V_25 , V_224 ;
V_224 = F_117 ( F_23 ( V_14 ) -> V_225 ) ;
V_220 += ( V_224 - 1 ) * F_116 ;
#undef F_116
V_25 = F_7 ( V_219 , V_220 ) ;
if ( V_25 )
return V_25 ;
F_118 (waiter, dev_priv, id) {
T_1 V_226 ;
T_2 V_39 = V_221 -> V_227 . V_228 [ V_68 ] ;
if ( V_39 == V_229 )
continue;
V_226 = F_119 ( V_219 ) ;
F_8 ( V_221 , F_14 ( 6 ) ) ;
F_8 ( V_221 , V_57 |
V_44 |
V_55 ) ;
F_8 ( V_221 , F_120 ( V_39 ) ) ;
F_8 ( V_221 , F_121 ( V_39 ) ) ;
F_8 ( V_221 , V_226 ) ;
F_8 ( V_221 , 0 ) ;
F_8 ( V_221 , V_230 |
F_122 ( V_222 -> V_231 ) ) ;
F_8 ( V_221 , 0 ) ;
}
return 0 ;
}
static int F_123 ( struct V_20 * V_219 ,
unsigned int V_220 )
{
#define F_116 6
struct V_10 * V_221 = V_219 -> V_11 ;
struct V_32 * V_14 = V_221 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_10 * V_222 ;
enum V_223 V_68 ;
int V_25 , V_224 ;
V_224 = F_117 ( F_23 ( V_14 ) -> V_225 ) ;
V_220 += ( V_224 - 1 ) * F_116 ;
#undef F_116
V_25 = F_7 ( V_219 , V_220 ) ;
if ( V_25 )
return V_25 ;
F_118 (waiter, dev_priv, id) {
T_1 V_226 ;
T_2 V_39 = V_221 -> V_227 . V_228 [ V_68 ] ;
if ( V_39 == V_229 )
continue;
V_226 = F_119 ( V_219 ) ;
F_8 ( V_221 , ( V_232 + 1 ) |
V_233 ) ;
F_8 ( V_221 , F_120 ( V_39 ) |
V_234 ) ;
F_8 ( V_221 , F_121 ( V_39 ) ) ;
F_8 ( V_221 , V_226 ) ;
F_8 ( V_221 , V_230 |
F_122 ( V_222 -> V_231 ) ) ;
F_8 ( V_221 , 0 ) ;
}
return 0 ;
}
static int F_124 ( struct V_20 * V_219 ,
unsigned int V_220 )
{
struct V_10 * V_221 = V_219 -> V_11 ;
struct V_32 * V_14 = V_221 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_10 * V_235 ;
enum V_223 V_68 ;
int V_25 , V_224 ;
#define F_116 3
V_224 = F_117 ( F_23 ( V_14 ) -> V_225 ) ;
V_220 += F_125 ( ( V_224 - 1 ) * F_116 , 2 ) ;
#undef F_116
V_25 = F_7 ( V_219 , V_220 ) ;
if ( V_25 )
return V_25 ;
F_118 (useless, dev_priv, id) {
T_3 V_236 = V_221 -> V_227 . V_237 . signal [ V_68 ] ;
if ( F_126 ( V_236 ) ) {
T_1 V_226 = F_119 ( V_219 ) ;
F_8 ( V_221 , F_75 ( 1 ) ) ;
F_76 ( V_221 , V_236 ) ;
F_8 ( V_221 , V_226 ) ;
}
}
if ( V_224 % 2 == 0 )
F_8 ( V_221 , V_31 ) ;
return 0 ;
}
static int
F_127 ( struct V_20 * V_21 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
int V_25 ;
if ( V_11 -> V_227 . signal )
V_25 = V_11 -> V_227 . signal ( V_21 , 4 ) ;
else
V_25 = F_7 ( V_21 , 4 ) ;
if ( V_25 )
return V_25 ;
F_8 ( V_11 , V_238 ) ;
F_8 ( V_11 ,
V_239 << V_240 ) ;
F_8 ( V_11 , F_119 ( V_21 ) ) ;
F_8 ( V_11 , V_241 ) ;
F_5 ( V_11 ) ;
return 0 ;
}
static inline bool F_128 ( struct V_32 * V_14 ,
T_1 V_226 )
{
struct V_12 * V_13 = V_14 -> V_15 ;
return V_13 -> V_242 < V_226 ;
}
static int
F_129 ( struct V_20 * V_243 ,
struct V_10 * V_221 ,
T_1 V_226 )
{
struct V_10 * V_222 = V_243 -> V_11 ;
struct V_12 * V_13 = V_222 -> V_14 -> V_15 ;
int V_25 ;
V_25 = F_7 ( V_243 , 4 ) ;
if ( V_25 )
return V_25 ;
F_8 ( V_222 , V_244 |
V_245 |
V_246 |
V_247 ) ;
F_8 ( V_222 , V_226 ) ;
F_8 ( V_222 ,
F_120 ( F_130 ( V_222 , V_221 -> V_68 ) ) ) ;
F_8 ( V_222 ,
F_121 ( F_130 ( V_222 , V_221 -> V_68 ) ) ) ;
F_9 ( V_222 ) ;
return 0 ;
}
static int
F_131 ( struct V_20 * V_243 ,
struct V_10 * V_221 ,
T_1 V_226 )
{
struct V_10 * V_222 = V_243 -> V_11 ;
T_1 V_248 = V_249 |
V_250 |
V_251 ;
T_1 V_252 = V_221 -> V_227 . V_237 . V_253 [ V_222 -> V_68 ] ;
int V_25 ;
V_226 -= 1 ;
F_37 ( V_252 == V_229 ) ;
V_25 = F_7 ( V_243 , 4 ) ;
if ( V_25 )
return V_25 ;
if ( F_132 ( ! F_128 ( V_222 -> V_14 , V_226 ) ) ) {
F_8 ( V_222 , V_248 | V_252 ) ;
F_8 ( V_222 , V_226 ) ;
F_8 ( V_222 , 0 ) ;
F_8 ( V_222 , V_31 ) ;
} else {
F_8 ( V_222 , V_31 ) ;
F_8 ( V_222 , V_31 ) ;
F_8 ( V_222 , V_31 ) ;
F_8 ( V_222 , V_31 ) ;
}
F_9 ( V_222 ) ;
return 0 ;
}
static int
F_133 ( struct V_20 * V_21 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
T_1 V_37 = V_11 -> V_38 . V_39 + 2 * V_40 ;
int V_25 ;
V_25 = F_7 ( V_21 , 32 ) ;
if ( V_25 )
return V_25 ;
F_8 ( V_11 ,
F_14 ( 4 ) | V_44 |
V_254 |
V_50 ) ;
F_8 ( V_11 ,
V_11 -> V_38 . V_39 | V_43 ) ;
F_8 ( V_11 , F_119 ( V_21 ) ) ;
F_8 ( V_11 , 0 ) ;
F_134 ( V_11 , V_37 ) ;
V_37 += 2 * V_40 ;
F_134 ( V_11 , V_37 ) ;
V_37 += 2 * V_40 ;
F_134 ( V_11 , V_37 ) ;
V_37 += 2 * V_40 ;
F_134 ( V_11 , V_37 ) ;
V_37 += 2 * V_40 ;
F_134 ( V_11 , V_37 ) ;
V_37 += 2 * V_40 ;
F_134 ( V_11 , V_37 ) ;
F_8 ( V_11 ,
F_14 ( 4 ) | V_44 |
V_254 |
V_50 |
V_255 ) ;
F_8 ( V_11 ,
V_11 -> V_38 . V_39 | V_43 ) ;
F_8 ( V_11 , F_119 ( V_21 ) ) ;
F_8 ( V_11 , 0 ) ;
F_5 ( V_11 ) ;
return 0 ;
}
static void
F_135 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 -> V_15 ;
F_136 ( & V_13 -> V_256 . V_257 ) ;
F_137 ( F_25 ( V_11 -> V_61 ) ) ;
F_138 ( & V_13 -> V_256 . V_257 ) ;
}
static T_1
F_139 ( struct V_10 * V_11 )
{
return F_140 ( V_11 , V_239 ) ;
}
static void
F_141 ( struct V_10 * V_11 , T_1 V_226 )
{
F_142 ( V_11 , V_239 , V_226 ) ;
}
static T_1
F_143 ( struct V_10 * V_11 )
{
return V_11 -> V_38 . V_103 [ 0 ] ;
}
static void
F_144 ( struct V_10 * V_11 , T_1 V_226 )
{
V_11 -> V_38 . V_103 [ 0 ] = V_226 ;
}
static bool
F_145 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
if ( F_37 ( ! F_146 ( V_13 ) ) )
return false ;
F_147 ( & V_13 -> V_258 , V_45 ) ;
if ( V_11 -> V_259 ++ == 0 )
F_148 ( V_13 , V_11 -> V_260 ) ;
F_149 ( & V_13 -> V_258 , V_45 ) ;
return true ;
}
static void
F_150 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
F_147 ( & V_13 -> V_258 , V_45 ) ;
if ( -- V_11 -> V_259 == 0 )
F_151 ( V_13 , V_11 -> V_260 ) ;
F_149 ( & V_13 -> V_258 , V_45 ) ;
}
static bool
F_152 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
if ( ! F_146 ( V_13 ) )
return false ;
F_147 ( & V_13 -> V_258 , V_45 ) ;
if ( V_11 -> V_259 ++ == 0 ) {
V_13 -> V_261 &= ~ V_11 -> V_260 ;
F_29 ( V_262 , V_13 -> V_261 ) ;
F_35 ( V_262 ) ;
}
F_149 ( & V_13 -> V_258 , V_45 ) ;
return true ;
}
static void
F_153 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
F_147 ( & V_13 -> V_258 , V_45 ) ;
if ( -- V_11 -> V_259 == 0 ) {
V_13 -> V_261 |= V_11 -> V_260 ;
F_29 ( V_262 , V_13 -> V_261 ) ;
F_35 ( V_262 ) ;
}
F_149 ( & V_13 -> V_258 , V_45 ) ;
}
static bool
F_154 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
if ( ! F_146 ( V_13 ) )
return false ;
F_147 ( & V_13 -> V_258 , V_45 ) ;
if ( V_11 -> V_259 ++ == 0 ) {
V_13 -> V_261 &= ~ V_11 -> V_260 ;
F_155 ( V_262 , V_13 -> V_261 ) ;
F_156 ( V_262 ) ;
}
F_149 ( & V_13 -> V_258 , V_45 ) ;
return true ;
}
static void
F_157 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
F_147 ( & V_13 -> V_258 , V_45 ) ;
if ( -- V_11 -> V_259 == 0 ) {
V_13 -> V_261 |= V_11 -> V_260 ;
F_155 ( V_262 , V_13 -> V_261 ) ;
F_156 ( V_262 ) ;
}
F_149 ( & V_13 -> V_258 , V_45 ) ;
}
static int
F_158 ( struct V_20 * V_21 ,
T_1 V_22 ,
T_1 V_23 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
int V_25 ;
V_25 = F_7 ( V_21 , 2 ) ;
if ( V_25 )
return V_25 ;
F_8 ( V_11 , V_26 ) ;
F_8 ( V_11 , V_31 ) ;
F_9 ( V_11 ) ;
return 0 ;
}
static int
F_159 ( struct V_20 * V_21 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
int V_25 ;
V_25 = F_7 ( V_21 , 4 ) ;
if ( V_25 )
return V_25 ;
F_8 ( V_11 , V_238 ) ;
F_8 ( V_11 ,
V_239 << V_240 ) ;
F_8 ( V_11 , F_119 ( V_21 ) ) ;
F_8 ( V_11 , V_241 ) ;
F_5 ( V_11 ) ;
return 0 ;
}
static bool
F_160 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
if ( F_37 ( ! F_146 ( V_13 ) ) )
return false ;
F_147 ( & V_13 -> V_258 , V_45 ) ;
if ( V_11 -> V_259 ++ == 0 ) {
if ( F_111 ( V_14 ) && V_11 -> V_68 == V_69 )
F_112 ( V_11 ,
~ ( V_11 -> V_260 |
F_113 ( V_14 ) ) ) ;
else
F_112 ( V_11 , ~ V_11 -> V_260 ) ;
F_148 ( V_13 , V_11 -> V_260 ) ;
}
F_149 ( & V_13 -> V_258 , V_45 ) ;
return true ;
}
static void
F_161 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
F_147 ( & V_13 -> V_258 , V_45 ) ;
if ( -- V_11 -> V_259 == 0 ) {
if ( F_111 ( V_14 ) && V_11 -> V_68 == V_69 )
F_112 ( V_11 , ~ F_113 ( V_14 ) ) ;
else
F_112 ( V_11 , ~ 0 ) ;
F_151 ( V_13 , V_11 -> V_260 ) ;
}
F_149 ( & V_13 -> V_258 , V_45 ) ;
}
static bool
F_162 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
if ( F_37 ( ! F_146 ( V_13 ) ) )
return false ;
F_147 ( & V_13 -> V_258 , V_45 ) ;
if ( V_11 -> V_259 ++ == 0 ) {
F_112 ( V_11 , ~ V_11 -> V_260 ) ;
F_163 ( V_13 , V_11 -> V_260 ) ;
}
F_149 ( & V_13 -> V_258 , V_45 ) ;
return true ;
}
static void
F_164 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
F_147 ( & V_13 -> V_258 , V_45 ) ;
if ( -- V_11 -> V_259 == 0 ) {
F_112 ( V_11 , ~ 0 ) ;
F_165 ( V_13 , V_11 -> V_260 ) ;
}
F_149 ( & V_13 -> V_258 , V_45 ) ;
}
static bool
F_166 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
if ( F_37 ( ! F_146 ( V_13 ) ) )
return false ;
F_147 ( & V_13 -> V_258 , V_45 ) ;
if ( V_11 -> V_259 ++ == 0 ) {
if ( F_111 ( V_14 ) && V_11 -> V_68 == V_69 ) {
F_112 ( V_11 ,
~ ( V_11 -> V_260 |
V_263 ) ) ;
} else {
F_112 ( V_11 , ~ V_11 -> V_260 ) ;
}
F_35 ( F_167 ( V_11 -> V_61 ) ) ;
}
F_149 ( & V_13 -> V_258 , V_45 ) ;
return true ;
}
static void
F_168 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
F_147 ( & V_13 -> V_258 , V_45 ) ;
if ( -- V_11 -> V_259 == 0 ) {
if ( F_111 ( V_14 ) && V_11 -> V_68 == V_69 ) {
F_112 ( V_11 ,
~ V_263 ) ;
} else {
F_112 ( V_11 , ~ 0 ) ;
}
F_35 ( F_167 ( V_11 -> V_61 ) ) ;
}
F_149 ( & V_13 -> V_258 , V_45 ) ;
}
static int
F_169 ( struct V_20 * V_21 ,
T_2 V_264 , T_1 V_265 ,
unsigned V_266 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
int V_25 ;
V_25 = F_7 ( V_21 , 2 ) ;
if ( V_25 )
return V_25 ;
F_8 ( V_11 ,
V_267 |
V_268 |
( V_266 & V_269 ?
0 : V_270 ) ) ;
F_8 ( V_11 , V_264 ) ;
F_9 ( V_11 ) ;
return 0 ;
}
static int
F_170 ( struct V_20 * V_21 ,
T_2 V_264 , T_1 V_271 ,
unsigned V_266 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
T_1 V_272 = V_11 -> V_38 . V_39 ;
int V_25 ;
V_25 = F_7 ( V_21 , 6 ) ;
if ( V_25 )
return V_25 ;
F_8 ( V_11 , V_273 | V_274 ) ;
F_8 ( V_11 , V_275 | V_276 | 4096 ) ;
F_8 ( V_11 , V_277 << 16 | 4 ) ;
F_8 ( V_11 , V_272 ) ;
F_8 ( V_11 , 0xdeadbeef ) ;
F_8 ( V_11 , V_31 ) ;
F_9 ( V_11 ) ;
if ( ( V_266 & V_278 ) == 0 ) {
if ( V_271 > V_279 )
return - V_115 ;
V_25 = F_7 ( V_21 , 6 + 2 ) ;
if ( V_25 )
return V_25 ;
F_8 ( V_11 , V_280 | V_274 ) ;
F_8 ( V_11 ,
V_275 | V_281 | 4096 ) ;
F_8 ( V_11 , F_171 ( V_271 , 4096 ) << 16 | 4096 ) ;
F_8 ( V_11 , V_272 ) ;
F_8 ( V_11 , 4096 ) ;
F_8 ( V_11 , V_264 ) ;
F_8 ( V_11 , V_26 ) ;
F_8 ( V_11 , V_31 ) ;
F_9 ( V_11 ) ;
V_264 = V_272 ;
}
V_25 = F_7 ( V_21 , 2 ) ;
if ( V_25 )
return V_25 ;
F_8 ( V_11 , V_267 | V_268 ) ;
F_8 ( V_11 , V_264 | ( V_266 & V_269 ?
0 : V_282 ) ) ;
F_9 ( V_11 ) ;
return 0 ;
}
static int
F_172 ( struct V_20 * V_21 ,
T_2 V_264 , T_1 V_271 ,
unsigned V_266 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
int V_25 ;
V_25 = F_7 ( V_21 , 2 ) ;
if ( V_25 )
return V_25 ;
F_8 ( V_11 , V_267 | V_268 ) ;
F_8 ( V_11 , V_264 | ( V_266 & V_269 ?
0 : V_282 ) ) ;
F_9 ( V_11 ) ;
return 0 ;
}
static void F_173 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_43 ( V_11 -> V_14 ) ;
if ( ! V_13 -> V_64 )
return;
F_174 ( V_11 -> V_14 , V_13 -> V_64 ) ;
V_11 -> V_78 . V_283 = NULL ;
}
static void F_175 ( struct V_10 * V_11 )
{
struct V_87 * V_88 ;
V_88 = V_11 -> V_78 . V_88 ;
if ( V_88 == NULL )
return;
F_63 ( F_64 ( V_88 -> V_96 -> V_97 ) ) ;
F_65 ( V_88 ) ;
F_66 ( & V_88 -> V_98 ) ;
V_11 -> V_78 . V_88 = NULL ;
}
static int F_176 ( struct V_10 * V_11 )
{
struct V_87 * V_88 = V_11 -> V_78 . V_88 ;
if ( V_88 == NULL ) {
unsigned V_45 ;
int V_25 ;
V_88 = F_68 ( V_11 -> V_14 , 4096 ) ;
if ( V_88 == NULL ) {
F_41 ( L_12 ) ;
return - V_99 ;
}
V_25 = F_69 ( V_88 , V_101 ) ;
if ( V_25 )
goto V_102;
V_45 = 0 ;
if ( ! F_177 ( V_11 -> V_14 ) )
V_45 |= V_284 ;
V_25 = F_70 ( V_88 , 4096 , V_45 ) ;
if ( V_25 ) {
V_102:
F_66 ( & V_88 -> V_98 ) ;
return V_25 ;
}
V_11 -> V_78 . V_88 = V_88 ;
}
V_11 -> V_78 . V_79 = F_59 ( V_88 ) ;
V_11 -> V_78 . V_283 = F_71 ( F_64 ( V_88 -> V_96 -> V_97 ) ) ;
memset ( V_11 -> V_78 . V_283 , 0 , V_92 ) ;
F_72 ( L_13 ,
V_11 -> V_84 , V_11 -> V_78 . V_79 ) ;
return 0 ;
}
static int F_178 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 -> V_15 ;
if ( ! V_13 -> V_64 ) {
V_13 -> V_64 =
F_179 ( V_11 -> V_14 , V_92 , V_92 ) ;
if ( ! V_13 -> V_64 )
return - V_99 ;
}
V_11 -> V_78 . V_283 = V_13 -> V_64 -> V_285 ;
memset ( V_11 -> V_78 . V_283 , 0 , V_92 ) ;
return 0 ;
}
void F_180 ( struct V_6 * V_7 )
{
if ( F_177 ( V_7 -> V_88 -> V_98 . V_14 ) && ! V_7 -> V_88 -> V_286 )
F_181 ( V_7 -> V_88 ) ;
else
F_182 ( V_7 -> V_287 ) ;
V_7 -> V_287 = NULL ;
V_7 -> V_288 = NULL ;
F_65 ( V_7 -> V_88 ) ;
}
int F_183 ( struct V_32 * V_14 ,
struct V_6 * V_7 )
{
struct V_12 * V_13 = F_43 ( V_14 ) ;
struct V_289 * V_290 = & V_13 -> V_290 ;
struct V_87 * V_88 = V_7 -> V_88 ;
unsigned V_45 = V_291 | 4096 ;
void * V_63 ;
int V_25 ;
if ( F_177 ( V_13 ) && ! V_88 -> V_286 ) {
V_25 = F_70 ( V_88 , V_92 , V_45 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_184 ( V_88 , true ) ;
if ( V_25 )
goto V_104;
V_63 = F_185 ( V_88 ) ;
if ( F_186 ( V_63 ) ) {
V_25 = F_187 ( V_63 ) ;
goto V_104;
}
} else {
V_25 = F_70 ( V_88 , V_92 ,
V_45 | V_284 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_188 ( V_88 , true ) ;
if ( V_25 )
goto V_104;
F_189 ( V_13 ) ;
V_63 = F_190 ( V_290 -> V_292 +
F_59 ( V_88 ) , V_7 -> V_3 ) ;
if ( V_63 == NULL ) {
V_25 = - V_99 ;
goto V_104;
}
}
V_7 -> V_287 = V_63 ;
V_7 -> V_288 = F_191 ( V_88 ) ;
return 0 ;
V_104:
F_65 ( V_88 ) ;
return V_25 ;
}
static void F_192 ( struct V_6 * V_7 )
{
F_66 ( & V_7 -> V_88 -> V_98 ) ;
V_7 -> V_88 = NULL ;
}
static int F_193 ( struct V_32 * V_14 ,
struct V_6 * V_7 )
{
struct V_87 * V_88 ;
V_88 = NULL ;
if ( ! F_177 ( V_14 ) )
V_88 = F_194 ( V_14 , V_7 -> V_3 ) ;
if ( V_88 == NULL )
V_88 = F_68 ( V_14 , V_7 -> V_3 ) ;
if ( V_88 == NULL )
return - V_99 ;
V_88 -> V_293 = 1 ;
V_7 -> V_88 = V_88 ;
return 0 ;
}
struct V_6 *
F_195 ( struct V_10 * V_11 , int V_3 )
{
struct V_6 * V_294 ;
int V_25 ;
V_294 = F_196 ( sizeof( * V_294 ) , V_295 ) ;
if ( V_294 == NULL ) {
F_72 ( L_14 ,
V_11 -> V_84 ) ;
return F_197 ( - V_99 ) ;
}
V_294 -> V_11 = V_11 ;
F_198 ( & V_294 -> V_296 , & V_11 -> V_297 ) ;
V_294 -> V_3 = V_3 ;
V_294 -> V_298 = V_3 ;
if ( F_199 ( V_11 -> V_14 ) || F_200 ( V_11 -> V_14 ) )
V_294 -> V_298 -= 2 * V_40 ;
V_294 -> V_8 = - 1 ;
F_2 ( V_294 ) ;
V_25 = F_193 ( V_11 -> V_14 , V_294 ) ;
if ( V_25 ) {
F_72 ( L_15 ,
V_11 -> V_84 , V_25 ) ;
F_201 ( & V_294 -> V_296 ) ;
F_202 ( V_294 ) ;
return F_197 ( V_25 ) ;
}
return V_294 ;
}
void
F_203 ( struct V_6 * V_294 )
{
F_192 ( V_294 ) ;
F_201 ( & V_294 -> V_296 ) ;
F_202 ( V_294 ) ;
}
static int F_204 ( struct V_32 * V_14 ,
struct V_10 * V_11 )
{
struct V_6 * V_7 ;
int V_25 ;
F_37 ( V_11 -> V_18 ) ;
V_11 -> V_14 = V_14 ;
F_205 ( & V_11 -> V_299 ) ;
F_205 ( & V_11 -> V_300 ) ;
F_205 ( & V_11 -> V_301 ) ;
F_205 ( & V_11 -> V_297 ) ;
F_206 ( V_14 , & V_11 -> V_302 ) ;
memset ( V_11 -> V_227 . V_303 , 0 ,
sizeof( V_11 -> V_227 . V_303 ) ) ;
F_207 ( & V_11 -> V_304 ) ;
V_7 = F_195 ( V_11 , 32 * V_92 ) ;
if ( F_186 ( V_7 ) ) {
V_25 = F_187 ( V_7 ) ;
goto error;
}
V_11 -> V_18 = V_7 ;
if ( F_57 ( V_14 ) ) {
V_25 = F_176 ( V_11 ) ;
if ( V_25 )
goto error;
} else {
F_37 ( V_11 -> V_68 != V_69 ) ;
V_25 = F_178 ( V_11 ) ;
if ( V_25 )
goto error;
}
V_25 = F_183 ( V_14 , V_7 ) ;
if ( V_25 ) {
F_41 ( L_16 ,
V_11 -> V_84 , V_25 ) ;
F_192 ( V_7 ) ;
goto error;
}
V_25 = F_208 ( V_11 ) ;
if ( V_25 )
goto error;
return 0 ;
error:
F_209 ( V_11 ) ;
return V_25 ;
}
void F_209 ( struct V_10 * V_11 )
{
struct V_12 * V_13 ;
if ( ! F_210 ( V_11 ) )
return;
V_13 = F_43 ( V_11 -> V_14 ) ;
if ( V_11 -> V_18 ) {
F_211 ( V_11 ) ;
F_37 ( ! F_44 ( V_11 -> V_14 ) && ( F_38 ( V_11 ) & V_81 ) == 0 ) ;
F_180 ( V_11 -> V_18 ) ;
F_203 ( V_11 -> V_18 ) ;
V_11 -> V_18 = NULL ;
}
if ( V_11 -> V_305 )
V_11 -> V_305 ( V_11 ) ;
if ( F_57 ( V_11 -> V_14 ) ) {
F_175 ( V_11 ) ;
} else {
F_37 ( V_11 -> V_68 != V_69 ) ;
F_173 ( V_11 ) ;
}
F_212 ( V_11 ) ;
F_213 ( & V_11 -> V_302 ) ;
V_11 -> V_14 = NULL ;
}
int F_214 ( struct V_10 * V_11 )
{
struct V_20 * V_21 ;
if ( F_215 ( & V_11 -> V_300 ) )
return 0 ;
V_21 = F_216 ( V_11 -> V_300 . V_306 ,
struct V_20 ,
V_307 ) ;
return F_217 ( V_21 ,
V_21 -> V_308 -> V_309 . V_310 ,
NULL , NULL ) ;
}
int F_218 ( struct V_20 * V_311 )
{
V_311 -> V_7 = V_311 -> V_11 -> V_18 ;
return 0 ;
}
int F_219 ( struct V_20 * V_311 )
{
F_220 ( V_311 -> V_7 , V_312 ) ;
return F_7 ( V_311 , 0 ) ;
}
void F_220 ( struct V_6 * V_7 , int V_3 )
{
F_221 ( V_7 -> V_313 ) ;
V_7 -> V_313 = V_3 ;
}
void F_222 ( struct V_6 * V_7 )
{
F_221 ( ! V_7 -> V_313 ) ;
V_7 -> V_313 = 0 ;
}
void F_223 ( struct V_6 * V_7 )
{
F_221 ( ! V_7 -> V_313 ) ;
V_7 -> V_313 = 0 ;
}
void F_224 ( struct V_6 * V_7 )
{
F_221 ( V_7 -> V_313 ) ;
}
static int F_225 ( struct V_20 * V_21 , int V_314 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_10 * V_11 = V_21 -> V_11 ;
struct V_20 * V_315 ;
F_2 ( V_7 ) ;
if ( V_7 -> V_4 >= V_314 )
return 0 ;
F_221 ( ! V_7 -> V_313 ) ;
F_226 (target, &engine->request_list, list) {
unsigned V_4 ;
if ( V_315 -> V_7 != V_7 )
continue;
V_4 = F_1 ( V_315 -> V_316 , V_7 -> V_2 ,
V_7 -> V_3 ) ;
if ( V_4 >= V_314 )
break;
}
if ( F_37 ( & V_315 -> V_307 == & V_11 -> V_300 ) )
return - V_115 ;
return F_227 ( V_315 ) ;
}
int F_7 ( struct V_20 * V_21 , int V_220 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
int V_317 = V_7 -> V_3 - V_7 -> V_2 ;
int V_318 = V_7 -> V_298 - V_7 -> V_2 ;
int V_314 = V_220 * sizeof( T_1 ) ;
int V_319 , V_320 ;
bool V_321 = false ;
V_319 = V_314 + V_7 -> V_313 ;
if ( F_228 ( V_314 > V_318 ) ) {
V_320 = V_317 + V_319 ;
V_321 = true ;
} else if ( F_228 ( V_319 > V_318 ) ) {
V_320 = V_317 + V_7 -> V_313 ;
} else {
V_320 = V_319 ;
}
if ( V_320 > V_7 -> V_4 ) {
int V_25 = F_225 ( V_21 , V_320 ) ;
if ( F_228 ( V_25 ) )
return V_25 ;
F_2 ( V_7 ) ;
if ( F_228 ( V_7 -> V_4 < V_320 ) )
return - V_322 ;
}
if ( F_228 ( V_321 ) ) {
F_221 ( V_317 > V_7 -> V_4 ) ;
F_221 ( V_7 -> V_2 + V_317 > V_7 -> V_3 ) ;
memset ( V_7 -> V_287 + V_7 -> V_2 ,
0 , V_317 ) ;
V_7 -> V_2 = 0 ;
V_7 -> V_4 -= V_317 ;
}
V_7 -> V_4 -= V_314 ;
F_221 ( V_7 -> V_4 < 0 ) ;
return 0 ;
}
int F_229 ( struct V_20 * V_21 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
int V_220 = ( V_11 -> V_18 -> V_2 & ( V_40 - 1 ) ) / sizeof( T_4 ) ;
int V_25 ;
if ( V_220 == 0 )
return 0 ;
V_220 = V_40 / sizeof( T_4 ) - V_220 ;
V_25 = F_7 ( V_21 , V_220 ) ;
if ( V_25 )
return V_25 ;
while ( V_220 -- )
F_8 ( V_11 , V_31 ) ;
F_9 ( V_11 ) ;
return 0 ;
}
void F_230 ( struct V_10 * V_11 , T_1 V_226 )
{
struct V_12 * V_13 = F_43 ( V_11 -> V_14 ) ;
if ( F_23 ( V_13 ) -> V_60 == 6 || F_23 ( V_13 ) -> V_60 == 7 ) {
F_29 ( F_231 ( V_11 -> V_61 ) , 0 ) ;
F_29 ( F_232 ( V_11 -> V_61 ) , 0 ) ;
if ( F_233 ( V_13 ) )
F_29 ( F_234 ( V_11 -> V_61 ) , 0 ) ;
}
if ( V_13 -> V_218 ) {
struct V_87 * V_88 = V_13 -> V_218 ;
struct V_323 * V_323 = F_235 ( V_88 , 0 ) ;
void * V_324 = F_71 ( V_323 ) ;
memset ( V_324 + F_236 ( V_11 -> V_68 , 0 ) ,
0 , V_325 * V_326 ) ;
F_63 ( V_323 ) ;
}
memset ( V_11 -> V_227 . V_303 , 0 ,
sizeof( V_11 -> V_227 . V_303 ) ) ;
V_11 -> V_327 ( V_11 , V_226 ) ;
V_11 -> V_328 = V_226 ;
V_11 -> V_86 . V_226 = V_226 ;
}
static void F_237 ( struct V_10 * V_11 ,
T_1 V_58 )
{
struct V_12 * V_13 = V_11 -> V_14 -> V_15 ;
F_29 ( V_329 ,
F_39 ( V_330 ) ) ;
F_238 ( V_331 , 0x0 ) ;
if ( F_40 ( ( F_27 ( V_329 ) &
V_332 ) == 0 ,
50 ) )
F_41 ( L_17 ) ;
F_21 ( V_11 , V_58 ) ;
F_35 ( F_239 ( V_11 -> V_61 ) ) ;
F_29 ( V_329 ,
F_51 ( V_330 ) ) ;
}
static int F_240 ( struct V_20 * V_21 ,
T_1 V_333 , T_1 V_334 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
T_4 V_24 ;
int V_25 ;
V_25 = F_7 ( V_21 , 4 ) ;
if ( V_25 )
return V_25 ;
V_24 = V_232 ;
if ( F_23 ( V_11 -> V_14 ) -> V_60 >= 8 )
V_24 += 1 ;
V_24 |= V_335 | V_233 ;
if ( V_333 & V_336 )
V_24 |= V_337 | V_338 ;
F_8 ( V_11 , V_24 ) ;
F_8 ( V_11 ,
V_339 | V_234 ) ;
if ( F_23 ( V_11 -> V_14 ) -> V_60 >= 8 ) {
F_8 ( V_11 , 0 ) ;
F_8 ( V_11 , 0 ) ;
} else {
F_8 ( V_11 , 0 ) ;
F_8 ( V_11 , V_31 ) ;
}
F_9 ( V_11 ) ;
return 0 ;
}
static int
F_241 ( struct V_20 * V_21 ,
T_2 V_264 , T_1 V_271 ,
unsigned V_266 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
bool V_340 = F_242 ( V_11 -> V_14 ) &&
! ( V_266 & V_269 ) ;
int V_25 ;
V_25 = F_7 ( V_21 , 4 ) ;
if ( V_25 )
return V_25 ;
F_8 ( V_11 , V_341 | ( V_340 << 8 ) |
( V_266 & V_342 ?
V_343 : 0 ) ) ;
F_8 ( V_11 , F_120 ( V_264 ) ) ;
F_8 ( V_11 , F_121 ( V_264 ) ) ;
F_8 ( V_11 , V_31 ) ;
F_9 ( V_11 ) ;
return 0 ;
}
static int
F_243 ( struct V_20 * V_21 ,
T_2 V_264 , T_1 V_271 ,
unsigned V_266 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
int V_25 ;
V_25 = F_7 ( V_21 , 2 ) ;
if ( V_25 )
return V_25 ;
F_8 ( V_11 ,
V_267 |
( V_266 & V_269 ?
0 : V_344 | V_345 ) |
( V_266 & V_342 ?
V_343 : 0 ) ) ;
F_8 ( V_11 , V_264 ) ;
F_9 ( V_11 ) ;
return 0 ;
}
static int
F_244 ( struct V_20 * V_21 ,
T_2 V_264 , T_1 V_271 ,
unsigned V_266 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
int V_25 ;
V_25 = F_7 ( V_21 , 2 ) ;
if ( V_25 )
return V_25 ;
F_8 ( V_11 ,
V_267 |
( V_266 & V_269 ?
0 : V_270 ) ) ;
F_8 ( V_11 , V_264 ) ;
F_9 ( V_11 ) ;
return 0 ;
}
static int F_245 ( struct V_20 * V_21 ,
T_1 V_333 , T_1 V_334 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
struct V_32 * V_14 = V_11 -> V_14 ;
T_4 V_24 ;
int V_25 ;
V_25 = F_7 ( V_21 , 4 ) ;
if ( V_25 )
return V_25 ;
V_24 = V_232 ;
if ( F_23 ( V_14 ) -> V_60 >= 8 )
V_24 += 1 ;
V_24 |= V_335 | V_233 ;
if ( V_333 & V_27 )
V_24 |= V_337 ;
F_8 ( V_11 , V_24 ) ;
F_8 ( V_11 ,
V_339 | V_234 ) ;
if ( F_23 ( V_14 ) -> V_60 >= 8 ) {
F_8 ( V_11 , 0 ) ;
F_8 ( V_11 , 0 ) ;
} else {
F_8 ( V_11 , 0 ) ;
F_8 ( V_11 , V_31 ) ;
}
F_9 ( V_11 ) ;
return 0 ;
}
int F_246 ( struct V_32 * V_14 )
{
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_10 * V_11 = & V_13 -> V_11 [ V_69 ] ;
struct V_87 * V_88 ;
int V_25 ;
V_11 -> V_84 = L_18 ;
V_11 -> V_68 = V_69 ;
V_11 -> V_346 = V_347 ;
V_11 -> V_231 = 0 ;
V_11 -> V_61 = V_348 ;
if ( F_23 ( V_14 ) -> V_60 >= 8 ) {
if ( F_247 ( V_14 ) ) {
V_88 = F_68 ( V_14 , 4096 ) ;
if ( V_88 == NULL ) {
F_41 ( L_19 ) ;
V_308 . V_324 = 0 ;
} else {
F_69 ( V_88 , V_101 ) ;
V_25 = F_70 ( V_88 , 0 , V_349 ) ;
if ( V_25 != 0 ) {
F_66 ( & V_88 -> V_98 ) ;
F_41 ( L_20 ) ;
V_308 . V_324 = 0 ;
} else
V_13 -> V_218 = V_88 ;
}
}
V_11 -> V_350 = F_77 ;
V_11 -> V_351 = F_127 ;
V_11 -> V_334 = F_19 ;
V_11 -> V_352 = F_166 ;
V_11 -> V_353 = F_168 ;
V_11 -> V_260 = V_354 ;
V_11 -> V_355 = F_135 ;
V_11 -> V_356 = F_139 ;
V_11 -> V_327 = F_141 ;
if ( F_247 ( V_14 ) ) {
F_37 ( ! V_13 -> V_218 ) ;
V_11 -> V_227 . V_357 = F_129 ;
V_11 -> V_227 . signal = F_115 ;
F_248 ( V_11 ) ;
}
} else if ( F_23 ( V_14 ) -> V_60 >= 6 ) {
V_11 -> V_350 = F_77 ;
V_11 -> V_351 = F_127 ;
V_11 -> V_334 = F_17 ;
if ( F_23 ( V_14 ) -> V_60 == 6 )
V_11 -> V_334 = F_15 ;
V_11 -> V_352 = F_160 ;
V_11 -> V_353 = F_161 ;
V_11 -> V_260 = V_354 ;
V_11 -> V_355 = F_135 ;
V_11 -> V_356 = F_139 ;
V_11 -> V_327 = F_141 ;
if ( F_247 ( V_14 ) ) {
V_11 -> V_227 . V_357 = F_131 ;
V_11 -> V_227 . signal = F_124 ;
V_11 -> V_227 . V_237 . V_253 [ V_69 ] = V_229 ;
V_11 -> V_227 . V_237 . V_253 [ V_74 ] = V_358 ;
V_11 -> V_227 . V_237 . V_253 [ V_71 ] = V_359 ;
V_11 -> V_227 . V_237 . V_253 [ V_76 ] = V_360 ;
V_11 -> V_227 . V_237 . V_253 [ V_73 ] = V_229 ;
V_11 -> V_227 . V_237 . signal [ V_69 ] = V_361 ;
V_11 -> V_227 . V_237 . signal [ V_74 ] = V_362 ;
V_11 -> V_227 . V_237 . signal [ V_71 ] = V_363 ;
V_11 -> V_227 . V_237 . signal [ V_76 ] = V_364 ;
V_11 -> V_227 . V_237 . signal [ V_73 ] = V_361 ;
}
} else if ( F_12 ( V_14 ) ) {
V_11 -> V_351 = F_133 ;
V_11 -> V_334 = F_10 ;
V_11 -> V_356 = F_143 ;
V_11 -> V_327 = F_144 ;
V_11 -> V_352 = F_145 ;
V_11 -> V_353 = F_150 ;
V_11 -> V_260 = V_354 |
V_365 ;
} else {
V_11 -> V_351 = F_159 ;
if ( F_23 ( V_14 ) -> V_60 < 4 )
V_11 -> V_334 = F_6 ;
else
V_11 -> V_334 = F_10 ;
V_11 -> V_356 = F_139 ;
V_11 -> V_327 = F_141 ;
if ( F_44 ( V_14 ) ) {
V_11 -> V_352 = F_154 ;
V_11 -> V_353 = F_157 ;
} else {
V_11 -> V_352 = F_152 ;
V_11 -> V_353 = F_153 ;
}
V_11 -> V_260 = V_366 ;
}
V_11 -> V_19 = F_20 ;
if ( F_249 ( V_14 ) )
V_11 -> V_367 = F_243 ;
else if ( F_250 ( V_14 ) )
V_11 -> V_367 = F_241 ;
else if ( F_23 ( V_14 ) -> V_60 >= 6 )
V_11 -> V_367 = F_244 ;
else if ( F_23 ( V_14 ) -> V_60 >= 4 )
V_11 -> V_367 = F_169 ;
else if ( F_199 ( V_14 ) || F_200 ( V_14 ) )
V_11 -> V_367 = F_170 ;
else
V_11 -> V_367 = F_172 ;
V_11 -> V_368 = F_110 ;
V_11 -> V_305 = F_114 ;
if ( F_251 ( V_14 ) ) {
V_88 = F_68 ( V_14 , V_369 ) ;
if ( V_88 == NULL ) {
F_41 ( L_21 ) ;
return - V_99 ;
}
V_25 = F_70 ( V_88 , 0 , 0 ) ;
if ( V_25 != 0 ) {
F_66 ( & V_88 -> V_98 ) ;
F_41 ( L_22 ) ;
return V_25 ;
}
V_11 -> V_38 . V_88 = V_88 ;
V_11 -> V_38 . V_39 = F_59 ( V_88 ) ;
}
V_25 = F_204 ( V_14 , V_11 ) ;
if ( V_25 )
return V_25 ;
if ( F_23 ( V_14 ) -> V_60 >= 5 ) {
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
V_11 -> V_84 = L_23 ;
V_11 -> V_68 = V_74 ;
V_11 -> V_346 = V_370 ;
V_11 -> V_231 = 1 ;
V_11 -> V_19 = F_20 ;
if ( F_23 ( V_14 ) -> V_60 >= 6 ) {
V_11 -> V_61 = V_371 ;
if ( F_32 ( V_14 ) )
V_11 -> V_19 = F_237 ;
V_11 -> V_334 = F_240 ;
V_11 -> V_351 = F_127 ;
V_11 -> V_355 = F_135 ;
V_11 -> V_356 = F_139 ;
V_11 -> V_327 = F_141 ;
if ( F_23 ( V_14 ) -> V_60 >= 8 ) {
V_11 -> V_260 =
V_354 << V_372 ;
V_11 -> V_352 = F_166 ;
V_11 -> V_353 = F_168 ;
V_11 -> V_367 =
F_241 ;
if ( F_247 ( V_14 ) ) {
V_11 -> V_227 . V_357 = F_129 ;
V_11 -> V_227 . signal = F_123 ;
F_248 ( V_11 ) ;
}
} else {
V_11 -> V_260 = V_373 ;
V_11 -> V_352 = F_160 ;
V_11 -> V_353 = F_161 ;
V_11 -> V_367 =
F_244 ;
if ( F_247 ( V_14 ) ) {
V_11 -> V_227 . V_357 = F_131 ;
V_11 -> V_227 . signal = F_124 ;
V_11 -> V_227 . V_237 . V_253 [ V_69 ] = V_374 ;
V_11 -> V_227 . V_237 . V_253 [ V_74 ] = V_229 ;
V_11 -> V_227 . V_237 . V_253 [ V_71 ] = V_375 ;
V_11 -> V_227 . V_237 . V_253 [ V_76 ] = V_376 ;
V_11 -> V_227 . V_237 . V_253 [ V_73 ] = V_229 ;
V_11 -> V_227 . V_237 . signal [ V_69 ] = V_377 ;
V_11 -> V_227 . V_237 . signal [ V_74 ] = V_361 ;
V_11 -> V_227 . V_237 . signal [ V_71 ] = V_378 ;
V_11 -> V_227 . V_237 . signal [ V_76 ] = V_379 ;
V_11 -> V_227 . V_237 . signal [ V_73 ] = V_361 ;
}
}
} else {
V_11 -> V_61 = V_380 ;
V_11 -> V_334 = F_158 ;
V_11 -> V_351 = F_159 ;
V_11 -> V_356 = F_139 ;
V_11 -> V_327 = F_141 ;
if ( F_12 ( V_14 ) ) {
V_11 -> V_260 = V_381 ;
V_11 -> V_352 = F_145 ;
V_11 -> V_353 = F_150 ;
} else {
V_11 -> V_260 = V_382 ;
V_11 -> V_352 = F_152 ;
V_11 -> V_353 = F_153 ;
}
V_11 -> V_367 = F_169 ;
}
V_11 -> V_368 = F_53 ;
return F_204 ( V_14 , V_11 ) ;
}
int F_253 ( struct V_32 * V_14 )
{
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_10 * V_11 = & V_13 -> V_11 [ V_73 ] ;
V_11 -> V_84 = L_24 ;
V_11 -> V_68 = V_73 ;
V_11 -> V_346 = V_370 ;
V_11 -> V_231 = 4 ;
V_11 -> V_19 = F_20 ;
V_11 -> V_61 = V_383 ;
V_11 -> V_334 = F_240 ;
V_11 -> V_351 = F_127 ;
V_11 -> V_355 = F_135 ;
V_11 -> V_356 = F_139 ;
V_11 -> V_327 = F_141 ;
V_11 -> V_260 =
V_354 << V_384 ;
V_11 -> V_352 = F_166 ;
V_11 -> V_353 = F_168 ;
V_11 -> V_367 =
F_241 ;
if ( F_247 ( V_14 ) ) {
V_11 -> V_227 . V_357 = F_129 ;
V_11 -> V_227 . signal = F_123 ;
F_248 ( V_11 ) ;
}
V_11 -> V_368 = F_53 ;
return F_204 ( V_14 , V_11 ) ;
}
int F_254 ( struct V_32 * V_14 )
{
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_10 * V_11 = & V_13 -> V_11 [ V_71 ] ;
V_11 -> V_84 = L_25 ;
V_11 -> V_68 = V_71 ;
V_11 -> V_346 = V_385 ;
V_11 -> V_231 = 2 ;
V_11 -> V_61 = V_386 ;
V_11 -> V_19 = F_20 ;
V_11 -> V_334 = F_245 ;
V_11 -> V_351 = F_127 ;
V_11 -> V_355 = F_135 ;
V_11 -> V_356 = F_139 ;
V_11 -> V_327 = F_141 ;
if ( F_23 ( V_14 ) -> V_60 >= 8 ) {
V_11 -> V_260 =
V_354 << V_387 ;
V_11 -> V_352 = F_166 ;
V_11 -> V_353 = F_168 ;
V_11 -> V_367 = F_241 ;
if ( F_247 ( V_14 ) ) {
V_11 -> V_227 . V_357 = F_129 ;
V_11 -> V_227 . signal = F_123 ;
F_248 ( V_11 ) ;
}
} else {
V_11 -> V_260 = V_388 ;
V_11 -> V_352 = F_160 ;
V_11 -> V_353 = F_161 ;
V_11 -> V_367 = F_244 ;
if ( F_247 ( V_14 ) ) {
V_11 -> V_227 . signal = F_124 ;
V_11 -> V_227 . V_357 = F_131 ;
V_11 -> V_227 . V_237 . V_253 [ V_69 ] = V_389 ;
V_11 -> V_227 . V_237 . V_253 [ V_74 ] = V_390 ;
V_11 -> V_227 . V_237 . V_253 [ V_71 ] = V_229 ;
V_11 -> V_227 . V_237 . V_253 [ V_76 ] = V_391 ;
V_11 -> V_227 . V_237 . V_253 [ V_73 ] = V_229 ;
V_11 -> V_227 . V_237 . signal [ V_69 ] = V_392 ;
V_11 -> V_227 . V_237 . signal [ V_74 ] = V_393 ;
V_11 -> V_227 . V_237 . signal [ V_71 ] = V_361 ;
V_11 -> V_227 . V_237 . signal [ V_76 ] = V_394 ;
V_11 -> V_227 . V_237 . signal [ V_73 ] = V_361 ;
}
}
V_11 -> V_368 = F_53 ;
return F_204 ( V_14 , V_11 ) ;
}
int F_255 ( struct V_32 * V_14 )
{
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_10 * V_11 = & V_13 -> V_11 [ V_76 ] ;
V_11 -> V_84 = L_26 ;
V_11 -> V_68 = V_76 ;
V_11 -> V_346 = V_395 ;
V_11 -> V_231 = 3 ;
V_11 -> V_61 = V_396 ;
V_11 -> V_19 = F_20 ;
V_11 -> V_334 = F_245 ;
V_11 -> V_351 = F_127 ;
V_11 -> V_355 = F_135 ;
V_11 -> V_356 = F_139 ;
V_11 -> V_327 = F_141 ;
if ( F_23 ( V_14 ) -> V_60 >= 8 ) {
V_11 -> V_260 =
V_354 << V_397 ;
V_11 -> V_352 = F_166 ;
V_11 -> V_353 = F_168 ;
V_11 -> V_367 = F_241 ;
if ( F_247 ( V_14 ) ) {
V_11 -> V_227 . V_357 = F_129 ;
V_11 -> V_227 . signal = F_123 ;
F_248 ( V_11 ) ;
}
} else {
V_11 -> V_260 = V_398 ;
V_11 -> V_352 = F_162 ;
V_11 -> V_353 = F_164 ;
V_11 -> V_367 = F_244 ;
if ( F_247 ( V_14 ) ) {
V_11 -> V_227 . V_357 = F_131 ;
V_11 -> V_227 . signal = F_124 ;
V_11 -> V_227 . V_237 . V_253 [ V_69 ] = V_399 ;
V_11 -> V_227 . V_237 . V_253 [ V_74 ] = V_400 ;
V_11 -> V_227 . V_237 . V_253 [ V_71 ] = V_401 ;
V_11 -> V_227 . V_237 . V_253 [ V_76 ] = V_229 ;
V_11 -> V_227 . V_237 . V_253 [ V_73 ] = V_229 ;
V_11 -> V_227 . V_237 . signal [ V_69 ] = V_402 ;
V_11 -> V_227 . V_237 . signal [ V_74 ] = V_403 ;
V_11 -> V_227 . V_237 . signal [ V_71 ] = V_404 ;
V_11 -> V_227 . V_237 . signal [ V_76 ] = V_361 ;
V_11 -> V_227 . V_237 . signal [ V_73 ] = V_361 ;
}
}
V_11 -> V_368 = F_53 ;
return F_204 ( V_14 , V_11 ) ;
}
int
F_74 ( struct V_20 * V_21 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
int V_25 ;
if ( ! V_11 -> V_110 )
return 0 ;
V_25 = V_11 -> V_334 ( V_21 , 0 , V_336 ) ;
if ( V_25 )
return V_25 ;
F_256 ( V_21 , 0 , V_336 ) ;
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
V_23 = V_336 ;
V_25 = V_11 -> V_334 ( V_21 , V_336 , V_23 ) ;
if ( V_25 )
return V_25 ;
F_256 ( V_21 , V_336 , V_23 ) ;
V_11 -> V_110 = false ;
return 0 ;
}
void
F_211 ( struct V_10 * V_11 )
{
int V_25 ;
if ( ! F_210 ( V_11 ) )
return;
V_25 = F_214 ( V_11 ) ;
if ( V_25 )
F_41 ( L_27 ,
V_11 -> V_84 , V_25 ) ;
F_42 ( V_11 ) ;
}
