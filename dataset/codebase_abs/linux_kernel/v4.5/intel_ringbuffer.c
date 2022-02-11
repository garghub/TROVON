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
F_42 ( L_12 , V_25 ) ;
return V_25 ;
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
static int F_80 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
F_81 ( V_116 , V_117 ) ;
F_81 ( V_118 , V_119 ) ;
F_81 ( V_120 ,
V_121 ) ;
F_81 ( V_122 ,
V_123 |
V_124 ) ;
F_82 ( V_125 , V_126 ) ;
F_81 ( V_127 , V_128 ) ;
F_83 ( V_129 ,
V_130 ,
V_131 ) ;
return 0 ;
}
static int F_84 ( struct V_10 * V_11 )
{
int V_25 ;
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
V_25 = F_80 ( V_11 ) ;
if ( V_25 )
return V_25 ;
F_81 ( V_120 , V_132 ) ;
F_81 ( V_133 ,
V_134 ) ;
F_81 ( V_135 ,
V_136 ) ;
F_81 ( V_122 ,
V_137 |
( F_85 ( V_14 ) ? V_138 : 0 ) ) ;
return 0 ;
}
static int F_86 ( struct V_10 * V_11 )
{
int V_25 ;
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
V_25 = F_80 ( V_11 ) ;
if ( V_25 )
return V_25 ;
F_81 ( V_120 , V_132 ) ;
F_81 ( V_139 , V_140 ) ;
return 0 ;
}
static int F_87 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
T_4 V_141 ;
F_30 ( V_142 , F_28 ( V_142 ) |
V_143 ) ;
F_30 ( V_144 , F_28 ( V_144 ) |
V_145 ) ;
F_81 ( V_120 ,
V_121 ) ;
F_81 ( V_135 ,
V_146 ) ;
if ( F_88 ( V_14 , 0 , V_147 ) ||
F_89 ( V_14 , 0 , V_148 ) )
F_82 ( V_149 ,
V_150 ) ;
if ( F_88 ( V_14 , 0 , V_147 ) ||
F_89 ( V_14 , 0 , V_148 ) ) {
F_81 ( V_151 ,
V_152 ) ;
}
if ( F_88 ( V_14 , V_153 , V_154 ) || F_90 ( V_14 ) )
F_81 ( V_155 ,
V_156 ) ;
F_81 ( V_127 , ( V_128 |
V_157 ) ) ;
F_82 ( V_149 ,
V_158 ) ;
if ( F_88 ( V_14 , V_153 , V_153 ) ||
F_89 ( V_14 , 0 , V_148 ) )
F_81 ( V_159 ,
V_160 ) ;
V_141 = V_137 ;
if ( F_88 ( V_14 , V_161 , V_161 ) ||
F_89 ( V_14 , V_162 , V_154 ) )
V_141 |= V_163 ;
F_81 ( V_122 , V_141 ) ;
if ( F_91 ( V_14 ) || F_89 ( V_14 , 0 , V_162 ) )
F_81 ( V_135 ,
V_136 ) ;
F_81 ( V_164 , V_165 ) ;
return 0 ;
}
static int F_92 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
T_5 V_166 [ 3 ] = { 0 , 0 , 0 } ;
unsigned int V_105 ;
for ( V_105 = 0 ; V_105 < 3 ; V_105 ++ ) {
T_5 V_167 ;
if ( ! F_93 ( V_13 -> V_168 . V_169 [ V_105 ] ) )
continue;
V_167 = F_94 ( V_13 -> V_168 . V_169 [ V_105 ] ) - 1 ;
V_166 [ V_105 ] = 3 - V_167 ;
}
if ( V_166 [ 0 ] == 0 && V_166 [ 1 ] == 0 && V_166 [ 2 ] == 0 )
return 0 ;
F_83 ( V_129 ,
F_95 ( 2 ) |
F_95 ( 1 ) |
F_95 ( 0 ) ,
F_96 ( 2 , V_166 [ 2 ] ) |
F_96 ( 1 , V_166 [ 1 ] ) |
F_96 ( 0 , V_166 [ 0 ] ) ) ;
return 0 ;
}
static int F_97 ( struct V_10 * V_11 )
{
int V_25 ;
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
V_25 = F_87 ( V_11 ) ;
if ( V_25 )
return V_25 ;
if ( F_88 ( V_14 , 0 , V_170 ) ) {
F_30 ( V_171 ,
F_40 ( V_172 ) ) ;
}
if ( F_88 ( V_14 , 0 , V_173 ) )
F_30 ( V_174 , F_28 ( V_174 ) |
V_175 ) ;
if ( F_88 ( V_14 , V_153 , V_154 ) ) {
F_30 ( V_176 , ( F_28 ( V_176 ) |
V_177 ) ) ;
}
if ( F_88 ( V_14 , V_147 , V_147 ) )
F_81 ( V_139 ,
V_178 ) ;
if ( F_88 ( V_14 , 0 , V_161 ) ) {
F_81 ( V_122 ,
V_124 ) ;
F_30 ( V_144 , F_28 ( V_144 ) |
V_179 ) ;
}
if ( F_88 ( V_14 , V_153 , V_170 ) )
F_81 ( V_122 ,
V_138 |
V_180 ) ;
if ( F_88 ( V_14 , 0 , V_161 ) )
F_81 (
V_181 ,
V_182 ) ;
return F_92 ( V_11 ) ;
}
static int F_98 ( struct V_10 * V_11 )
{
int V_25 ;
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
V_25 = F_87 ( V_11 ) ;
if ( V_25 )
return V_25 ;
if ( F_89 ( V_14 , 0 , V_148 ) )
F_30 ( V_183 , F_28 ( V_183 ) | V_184 ) ;
if ( F_89 ( V_14 , 0 , V_148 ) ) {
F_30 ( V_185 , ( F_28 ( V_185 ) &
~ V_186 ) ) ;
}
F_81 ( V_120 ,
V_132 ) ;
if ( F_89 ( V_14 , 0 , V_162 ) ) {
F_81 (
V_181 ,
V_182 ) ;
}
return 0 ;
}
int F_99 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
F_38 ( V_11 -> V_68 != V_69 ) ;
V_13 -> V_108 . V_109 = 0 ;
if ( F_100 ( V_14 ) )
return F_84 ( V_11 ) ;
if ( F_101 ( V_14 ) )
return F_86 ( V_11 ) ;
if ( F_91 ( V_14 ) )
return F_97 ( V_11 ) ;
if ( F_90 ( V_14 ) )
return F_98 ( V_11 ) ;
return 0 ;
}
static int F_102 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
int V_25 = F_53 ( V_11 ) ;
if ( V_25 )
return V_25 ;
if ( F_24 ( V_14 ) -> V_60 >= 4 && F_24 ( V_14 ) -> V_60 < 7 )
F_30 ( V_118 , F_40 ( V_187 ) ) ;
if ( F_24 ( V_14 ) -> V_60 >= 6 && F_24 ( V_14 ) -> V_60 < 8 )
F_30 ( V_118 , F_40 ( V_119 ) ) ;
if ( F_24 ( V_14 ) -> V_60 == 6 )
F_30 ( V_188 ,
F_40 ( V_189 ) ) ;
if ( F_32 ( V_14 ) )
F_30 ( V_190 ,
F_40 ( V_189 ) |
F_40 ( V_191 ) ) ;
if ( F_33 ( V_14 ) ) {
F_30 ( V_192 ,
F_52 ( V_193 ) ) ;
}
if ( F_24 ( V_14 ) -> V_60 >= 6 && F_24 ( V_14 ) -> V_60 < 8 )
F_30 ( V_116 , F_40 ( V_117 ) ) ;
if ( F_103 ( V_14 ) )
F_104 ( V_11 , ~ F_105 ( V_14 ) ) ;
return F_99 ( V_11 ) ;
}
static void F_106 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
if ( V_13 -> V_194 ) {
F_65 ( V_13 -> V_194 ) ;
F_66 ( & V_13 -> V_194 -> V_98 ) ;
V_13 -> V_194 = NULL ;
}
F_62 ( V_11 ) ;
}
static int F_107 ( struct V_20 * V_195 ,
unsigned int V_196 )
{
#define F_108 8
struct V_10 * V_197 = V_195 -> V_11 ;
struct V_32 * V_14 = V_197 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_10 * V_198 ;
int V_105 , V_25 , V_199 ;
V_199 = F_109 ( F_24 ( V_14 ) -> V_200 ) ;
V_196 += ( V_199 - 1 ) * F_108 ;
#undef F_108
V_25 = F_8 ( V_195 , V_196 ) ;
if ( V_25 )
return V_25 ;
F_110 (waiter, dev_priv, i) {
T_1 V_201 ;
T_2 V_39 = V_197 -> V_202 . V_203 [ V_105 ] ;
if ( V_39 == V_204 )
continue;
V_201 = F_111 ( V_195 ) ;
F_9 ( V_197 , F_15 ( 6 ) ) ;
F_9 ( V_197 , V_57 |
V_44 |
V_55 ) ;
F_9 ( V_197 , F_112 ( V_39 ) ) ;
F_9 ( V_197 , F_113 ( V_39 ) ) ;
F_9 ( V_197 , V_201 ) ;
F_9 ( V_197 , 0 ) ;
F_9 ( V_197 , V_205 |
F_114 ( V_198 -> V_68 ) ) ;
F_9 ( V_197 , 0 ) ;
}
return 0 ;
}
static int F_115 ( struct V_20 * V_195 ,
unsigned int V_196 )
{
#define F_108 6
struct V_10 * V_197 = V_195 -> V_11 ;
struct V_32 * V_14 = V_197 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_10 * V_198 ;
int V_105 , V_25 , V_199 ;
V_199 = F_109 ( F_24 ( V_14 ) -> V_200 ) ;
V_196 += ( V_199 - 1 ) * F_108 ;
#undef F_108
V_25 = F_8 ( V_195 , V_196 ) ;
if ( V_25 )
return V_25 ;
F_110 (waiter, dev_priv, i) {
T_1 V_201 ;
T_2 V_39 = V_197 -> V_202 . V_203 [ V_105 ] ;
if ( V_39 == V_204 )
continue;
V_201 = F_111 ( V_195 ) ;
F_9 ( V_197 , ( V_206 + 1 ) |
V_207 ) ;
F_9 ( V_197 , F_112 ( V_39 ) |
V_208 ) ;
F_9 ( V_197 , F_113 ( V_39 ) ) ;
F_9 ( V_197 , V_201 ) ;
F_9 ( V_197 , V_205 |
F_114 ( V_198 -> V_68 ) ) ;
F_9 ( V_197 , 0 ) ;
}
return 0 ;
}
static int F_116 ( struct V_20 * V_195 ,
unsigned int V_196 )
{
struct V_10 * V_197 = V_195 -> V_11 ;
struct V_32 * V_14 = V_197 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_10 * V_209 ;
int V_105 , V_25 , V_199 ;
#define F_108 3
V_199 = F_109 ( F_24 ( V_14 ) -> V_200 ) ;
V_196 += F_117 ( ( V_199 - 1 ) * F_108 , 2 ) ;
#undef F_108
V_25 = F_8 ( V_195 , V_196 ) ;
if ( V_25 )
return V_25 ;
F_110 (useless, dev_priv, i) {
T_3 V_210 = V_197 -> V_202 . V_211 . signal [ V_105 ] ;
if ( F_118 ( V_210 ) ) {
T_1 V_201 = F_111 ( V_195 ) ;
F_9 ( V_197 , F_75 ( 1 ) ) ;
F_76 ( V_197 , V_210 ) ;
F_9 ( V_197 , V_201 ) ;
}
}
if ( V_199 % 2 == 0 )
F_9 ( V_197 , V_31 ) ;
return 0 ;
}
static int
F_119 ( struct V_20 * V_21 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
int V_25 ;
if ( V_11 -> V_202 . signal )
V_25 = V_11 -> V_202 . signal ( V_21 , 4 ) ;
else
V_25 = F_8 ( V_21 , 4 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_11 , V_212 ) ;
F_9 ( V_11 , V_213 << V_214 ) ;
F_9 ( V_11 , F_111 ( V_21 ) ) ;
F_9 ( V_11 , V_215 ) ;
F_6 ( V_11 ) ;
return 0 ;
}
static inline bool F_120 ( struct V_32 * V_14 ,
T_1 V_201 )
{
struct V_12 * V_13 = V_14 -> V_15 ;
return V_13 -> V_216 < V_201 ;
}
static int
F_121 ( struct V_20 * V_217 ,
struct V_10 * V_197 ,
T_1 V_201 )
{
struct V_10 * V_198 = V_217 -> V_11 ;
struct V_12 * V_13 = V_198 -> V_14 -> V_15 ;
int V_25 ;
V_25 = F_8 ( V_217 , 4 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_198 , V_218 |
V_219 |
V_220 |
V_221 ) ;
F_9 ( V_198 , V_201 ) ;
F_9 ( V_198 ,
F_112 ( F_122 ( V_198 , V_197 -> V_68 ) ) ) ;
F_9 ( V_198 ,
F_113 ( F_122 ( V_198 , V_197 -> V_68 ) ) ) ;
F_10 ( V_198 ) ;
return 0 ;
}
static int
F_123 ( struct V_20 * V_217 ,
struct V_10 * V_197 ,
T_1 V_201 )
{
struct V_10 * V_198 = V_217 -> V_11 ;
T_1 V_222 = V_223 |
V_224 |
V_225 ;
T_1 V_226 = V_197 -> V_202 . V_211 . V_227 [ V_198 -> V_68 ] ;
int V_25 ;
V_201 -= 1 ;
F_38 ( V_226 == V_204 ) ;
V_25 = F_8 ( V_217 , 4 ) ;
if ( V_25 )
return V_25 ;
if ( F_124 ( ! F_120 ( V_198 -> V_14 , V_201 ) ) ) {
F_9 ( V_198 , V_222 | V_226 ) ;
F_9 ( V_198 , V_201 ) ;
F_9 ( V_198 , 0 ) ;
F_9 ( V_198 , V_31 ) ;
} else {
F_9 ( V_198 , V_31 ) ;
F_9 ( V_198 , V_31 ) ;
F_9 ( V_198 , V_31 ) ;
F_9 ( V_198 , V_31 ) ;
}
F_10 ( V_198 ) ;
return 0 ;
}
static int
F_125 ( struct V_20 * V_21 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
T_1 V_37 = V_11 -> V_38 . V_39 + 2 * V_40 ;
int V_25 ;
V_25 = F_8 ( V_21 , 32 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_11 , F_15 ( 4 ) | V_44 |
V_228 |
V_50 ) ;
F_9 ( V_11 , V_11 -> V_38 . V_39 | V_43 ) ;
F_9 ( V_11 , F_111 ( V_21 ) ) ;
F_9 ( V_11 , 0 ) ;
F_126 ( V_11 , V_37 ) ;
V_37 += 2 * V_40 ;
F_126 ( V_11 , V_37 ) ;
V_37 += 2 * V_40 ;
F_126 ( V_11 , V_37 ) ;
V_37 += 2 * V_40 ;
F_126 ( V_11 , V_37 ) ;
V_37 += 2 * V_40 ;
F_126 ( V_11 , V_37 ) ;
V_37 += 2 * V_40 ;
F_126 ( V_11 , V_37 ) ;
F_9 ( V_11 , F_15 ( 4 ) | V_44 |
V_228 |
V_50 |
V_229 ) ;
F_9 ( V_11 , V_11 -> V_38 . V_39 | V_43 ) ;
F_9 ( V_11 , F_111 ( V_21 ) ) ;
F_9 ( V_11 , 0 ) ;
F_6 ( V_11 ) ;
return 0 ;
}
static T_1
F_127 ( struct V_10 * V_11 , bool V_230 )
{
if ( ! V_230 ) {
struct V_12 * V_13 = V_11 -> V_14 -> V_15 ;
F_36 ( F_26 ( V_11 -> V_61 ) ) ;
}
return F_128 ( V_11 , V_213 ) ;
}
static T_1
F_129 ( struct V_10 * V_11 , bool V_230 )
{
return F_128 ( V_11 , V_213 ) ;
}
static void
F_130 ( struct V_10 * V_11 , T_1 V_201 )
{
F_131 ( V_11 , V_213 , V_201 ) ;
}
static T_1
F_132 ( struct V_10 * V_11 , bool V_230 )
{
return V_11 -> V_38 . V_103 [ 0 ] ;
}
static void
F_133 ( struct V_10 * V_11 , T_1 V_201 )
{
V_11 -> V_38 . V_103 [ 0 ] = V_201 ;
}
static bool
F_134 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
if ( F_38 ( ! F_135 ( V_13 ) ) )
return false ;
F_136 ( & V_13 -> V_231 , V_45 ) ;
if ( V_11 -> V_232 ++ == 0 )
F_137 ( V_13 , V_11 -> V_233 ) ;
F_138 ( & V_13 -> V_231 , V_45 ) ;
return true ;
}
static void
F_139 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
F_136 ( & V_13 -> V_231 , V_45 ) ;
if ( -- V_11 -> V_232 == 0 )
F_140 ( V_13 , V_11 -> V_233 ) ;
F_138 ( & V_13 -> V_231 , V_45 ) ;
}
static bool
F_141 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
if ( ! F_135 ( V_13 ) )
return false ;
F_136 ( & V_13 -> V_231 , V_45 ) ;
if ( V_11 -> V_232 ++ == 0 ) {
V_13 -> V_234 &= ~ V_11 -> V_233 ;
F_30 ( V_235 , V_13 -> V_234 ) ;
F_36 ( V_235 ) ;
}
F_138 ( & V_13 -> V_231 , V_45 ) ;
return true ;
}
static void
F_142 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
F_136 ( & V_13 -> V_231 , V_45 ) ;
if ( -- V_11 -> V_232 == 0 ) {
V_13 -> V_234 |= V_11 -> V_233 ;
F_30 ( V_235 , V_13 -> V_234 ) ;
F_36 ( V_235 ) ;
}
F_138 ( & V_13 -> V_231 , V_45 ) ;
}
static bool
F_143 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
if ( ! F_135 ( V_13 ) )
return false ;
F_136 ( & V_13 -> V_231 , V_45 ) ;
if ( V_11 -> V_232 ++ == 0 ) {
V_13 -> V_234 &= ~ V_11 -> V_233 ;
F_144 ( V_235 , V_13 -> V_234 ) ;
F_145 ( V_235 ) ;
}
F_138 ( & V_13 -> V_231 , V_45 ) ;
return true ;
}
static void
F_146 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
F_136 ( & V_13 -> V_231 , V_45 ) ;
if ( -- V_11 -> V_232 == 0 ) {
V_13 -> V_234 |= V_11 -> V_233 ;
F_144 ( V_235 , V_13 -> V_234 ) ;
F_145 ( V_235 ) ;
}
F_138 ( & V_13 -> V_231 , V_45 ) ;
}
static int
F_147 ( struct V_20 * V_21 ,
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
F_148 ( struct V_20 * V_21 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
int V_25 ;
V_25 = F_8 ( V_21 , 4 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_11 , V_212 ) ;
F_9 ( V_11 , V_213 << V_214 ) ;
F_9 ( V_11 , F_111 ( V_21 ) ) ;
F_9 ( V_11 , V_215 ) ;
F_6 ( V_11 ) ;
return 0 ;
}
static bool
F_149 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
if ( F_38 ( ! F_135 ( V_13 ) ) )
return false ;
F_136 ( & V_13 -> V_231 , V_45 ) ;
if ( V_11 -> V_232 ++ == 0 ) {
if ( F_103 ( V_14 ) && V_11 -> V_68 == V_69 )
F_104 ( V_11 ,
~ ( V_11 -> V_233 |
F_105 ( V_14 ) ) ) ;
else
F_104 ( V_11 , ~ V_11 -> V_233 ) ;
F_137 ( V_13 , V_11 -> V_233 ) ;
}
F_138 ( & V_13 -> V_231 , V_45 ) ;
return true ;
}
static void
F_150 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
F_136 ( & V_13 -> V_231 , V_45 ) ;
if ( -- V_11 -> V_232 == 0 ) {
if ( F_103 ( V_14 ) && V_11 -> V_68 == V_69 )
F_104 ( V_11 , ~ F_105 ( V_14 ) ) ;
else
F_104 ( V_11 , ~ 0 ) ;
F_140 ( V_13 , V_11 -> V_233 ) ;
}
F_138 ( & V_13 -> V_231 , V_45 ) ;
}
static bool
F_151 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
if ( F_38 ( ! F_135 ( V_13 ) ) )
return false ;
F_136 ( & V_13 -> V_231 , V_45 ) ;
if ( V_11 -> V_232 ++ == 0 ) {
F_104 ( V_11 , ~ V_11 -> V_233 ) ;
F_152 ( V_13 , V_11 -> V_233 ) ;
}
F_138 ( & V_13 -> V_231 , V_45 ) ;
return true ;
}
static void
F_153 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
F_136 ( & V_13 -> V_231 , V_45 ) ;
if ( -- V_11 -> V_232 == 0 ) {
F_104 ( V_11 , ~ 0 ) ;
F_154 ( V_13 , V_11 -> V_233 ) ;
}
F_138 ( & V_13 -> V_231 , V_45 ) ;
}
static bool
F_155 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
if ( F_38 ( ! F_135 ( V_13 ) ) )
return false ;
F_136 ( & V_13 -> V_231 , V_45 ) ;
if ( V_11 -> V_232 ++ == 0 ) {
if ( F_103 ( V_14 ) && V_11 -> V_68 == V_69 ) {
F_104 ( V_11 ,
~ ( V_11 -> V_233 |
V_236 ) ) ;
} else {
F_104 ( V_11 , ~ V_11 -> V_233 ) ;
}
F_36 ( F_156 ( V_11 -> V_61 ) ) ;
}
F_138 ( & V_13 -> V_231 , V_45 ) ;
return true ;
}
static void
F_157 ( struct V_10 * V_11 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_45 ;
F_136 ( & V_13 -> V_231 , V_45 ) ;
if ( -- V_11 -> V_232 == 0 ) {
if ( F_103 ( V_14 ) && V_11 -> V_68 == V_69 ) {
F_104 ( V_11 ,
~ V_236 ) ;
} else {
F_104 ( V_11 , ~ 0 ) ;
}
F_36 ( F_156 ( V_11 -> V_61 ) ) ;
}
F_138 ( & V_13 -> V_231 , V_45 ) ;
}
static int
F_158 ( struct V_20 * V_21 ,
T_2 V_237 , T_1 V_238 ,
unsigned V_239 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
int V_25 ;
V_25 = F_8 ( V_21 , 2 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_11 ,
V_240 |
V_241 |
( V_239 & V_242 ?
0 : V_243 ) ) ;
F_9 ( V_11 , V_237 ) ;
F_10 ( V_11 ) ;
return 0 ;
}
static int
F_159 ( struct V_20 * V_21 ,
T_2 V_237 , T_1 V_244 ,
unsigned V_239 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
T_1 V_245 = V_11 -> V_38 . V_39 ;
int V_25 ;
V_25 = F_8 ( V_21 , 6 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_11 , V_246 | V_247 ) ;
F_9 ( V_11 , V_248 | V_249 | 4096 ) ;
F_9 ( V_11 , V_250 << 16 | 4 ) ;
F_9 ( V_11 , V_245 ) ;
F_9 ( V_11 , 0xdeadbeef ) ;
F_9 ( V_11 , V_31 ) ;
F_10 ( V_11 ) ;
if ( ( V_239 & V_251 ) == 0 ) {
if ( V_244 > V_252 )
return - V_115 ;
V_25 = F_8 ( V_21 , 6 + 2 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_11 , V_253 | V_247 ) ;
F_9 ( V_11 , V_248 | V_254 | 4096 ) ;
F_9 ( V_11 , F_160 ( V_244 , 4096 ) << 16 | 4096 ) ;
F_9 ( V_11 , V_245 ) ;
F_9 ( V_11 , 4096 ) ;
F_9 ( V_11 , V_237 ) ;
F_9 ( V_11 , V_26 ) ;
F_9 ( V_11 , V_31 ) ;
F_10 ( V_11 ) ;
V_237 = V_245 ;
}
V_25 = F_8 ( V_21 , 4 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_11 , V_255 ) ;
F_9 ( V_11 , V_237 | ( V_239 & V_242 ?
0 : V_256 ) ) ;
F_9 ( V_11 , V_237 + V_244 - 8 ) ;
F_9 ( V_11 , V_31 ) ;
F_10 ( V_11 ) ;
return 0 ;
}
static int
F_161 ( struct V_20 * V_21 ,
T_2 V_237 , T_1 V_244 ,
unsigned V_239 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
int V_25 ;
V_25 = F_8 ( V_21 , 2 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_11 , V_240 | V_241 ) ;
F_9 ( V_11 , V_237 | ( V_239 & V_242 ?
0 : V_256 ) ) ;
F_10 ( V_11 ) ;
return 0 ;
}
static void F_162 ( struct V_10 * V_11 )
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
static int F_163 ( struct V_10 * V_11 )
{
struct V_86 * V_87 ;
if ( ( V_87 = V_11 -> V_78 . V_87 ) == NULL ) {
unsigned V_45 ;
int V_25 ;
V_87 = F_68 ( V_11 -> V_14 , 4096 ) ;
if ( V_87 == NULL ) {
F_42 ( L_13 ) ;
return - V_99 ;
}
V_25 = F_69 ( V_87 , V_101 ) ;
if ( V_25 )
goto V_102;
V_45 = 0 ;
if ( ! F_164 ( V_11 -> V_14 ) )
V_45 |= V_257 ;
V_25 = F_70 ( V_87 , 4096 , V_45 ) ;
if ( V_25 ) {
V_102:
F_66 ( & V_87 -> V_98 ) ;
return V_25 ;
}
V_11 -> V_78 . V_87 = V_87 ;
}
V_11 -> V_78 . V_79 = F_59 ( V_87 ) ;
V_11 -> V_78 . V_258 = F_71 ( F_64 ( V_87 -> V_96 -> V_97 ) ) ;
memset ( V_11 -> V_78 . V_258 , 0 , V_91 ) ;
F_72 ( L_14 ,
V_11 -> V_84 , V_11 -> V_78 . V_79 ) ;
return 0 ;
}
static int F_165 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 -> V_15 ;
if ( ! V_13 -> V_64 ) {
V_13 -> V_64 =
F_166 ( V_11 -> V_14 , V_91 , V_91 ) ;
if ( ! V_13 -> V_64 )
return - V_99 ;
}
V_11 -> V_78 . V_258 = V_13 -> V_64 -> V_259 ;
memset ( V_11 -> V_78 . V_258 , 0 , V_91 ) ;
return 0 ;
}
void F_167 ( struct V_6 * V_7 )
{
if ( F_164 ( V_7 -> V_87 -> V_98 . V_14 ) && ! V_7 -> V_87 -> V_260 )
F_168 ( V_7 -> V_261 ) ;
else
F_169 ( V_7 -> V_261 ) ;
V_7 -> V_261 = NULL ;
F_65 ( V_7 -> V_87 ) ;
}
static T_1 * F_170 ( struct V_86 * V_87 )
{
struct V_262 V_263 ;
struct V_264 * * V_96 ;
void * V_63 ;
int V_105 ;
V_96 = F_171 ( V_87 -> V_98 . V_3 >> V_265 , sizeof( * V_96 ) ) ;
if ( V_96 == NULL )
return NULL ;
V_105 = 0 ;
F_172 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 )
V_96 [ V_105 ++ ] = F_173 ( & V_263 ) ;
V_63 = F_174 ( V_96 , V_105 , 0 , V_266 ) ;
F_175 ( V_96 ) ;
return V_63 ;
}
int F_176 ( struct V_32 * V_14 ,
struct V_6 * V_7 )
{
struct V_12 * V_13 = F_44 ( V_14 ) ;
struct V_86 * V_87 = V_7 -> V_87 ;
int V_25 ;
if ( F_164 ( V_13 ) && ! V_87 -> V_260 ) {
V_25 = F_70 ( V_87 , V_91 , 0 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_177 ( V_87 , true ) ;
if ( V_25 ) {
F_65 ( V_87 ) ;
return V_25 ;
}
V_7 -> V_261 = F_170 ( V_87 ) ;
if ( V_7 -> V_261 == NULL ) {
F_65 ( V_87 ) ;
return - V_99 ;
}
} else {
V_25 = F_70 ( V_87 , V_91 , V_257 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_178 ( V_87 , true ) ;
if ( V_25 ) {
F_65 ( V_87 ) ;
return V_25 ;
}
V_7 -> V_261 = F_179 ( V_13 -> V_267 . V_268 +
F_59 ( V_87 ) , V_7 -> V_3 ) ;
if ( V_7 -> V_261 == NULL ) {
F_65 ( V_87 ) ;
return - V_269 ;
}
}
return 0 ;
}
static void F_180 ( struct V_6 * V_7 )
{
F_66 ( & V_7 -> V_87 -> V_98 ) ;
V_7 -> V_87 = NULL ;
}
static int F_181 ( struct V_32 * V_14 ,
struct V_6 * V_7 )
{
struct V_86 * V_87 ;
V_87 = NULL ;
if ( ! F_164 ( V_14 ) )
V_87 = F_182 ( V_14 , V_7 -> V_3 ) ;
if ( V_87 == NULL )
V_87 = F_68 ( V_14 , V_7 -> V_3 ) ;
if ( V_87 == NULL )
return - V_99 ;
V_87 -> V_270 = 1 ;
V_7 -> V_87 = V_87 ;
return 0 ;
}
struct V_6 *
F_183 ( struct V_10 * V_271 , int V_3 )
{
struct V_6 * V_11 ;
int V_25 ;
V_11 = F_184 ( sizeof( * V_11 ) , V_272 ) ;
if ( V_11 == NULL ) {
F_72 ( L_15 ,
V_271 -> V_84 ) ;
return F_185 ( - V_99 ) ;
}
V_11 -> V_11 = V_271 ;
F_186 ( & V_11 -> V_273 , & V_271 -> V_274 ) ;
V_11 -> V_3 = V_3 ;
V_11 -> V_275 = V_3 ;
if ( F_187 ( V_271 -> V_14 ) || F_188 ( V_271 -> V_14 ) )
V_11 -> V_275 -= 2 * V_40 ;
V_11 -> V_8 = - 1 ;
F_2 ( V_11 ) ;
V_25 = F_181 ( V_271 -> V_14 , V_11 ) ;
if ( V_25 ) {
F_72 ( L_16 ,
V_271 -> V_84 , V_25 ) ;
F_189 ( & V_11 -> V_273 ) ;
F_190 ( V_11 ) ;
return F_185 ( V_25 ) ;
}
return V_11 ;
}
void
F_191 ( struct V_6 * V_11 )
{
F_180 ( V_11 ) ;
F_189 ( & V_11 -> V_273 ) ;
F_190 ( V_11 ) ;
}
static int F_192 ( struct V_32 * V_14 ,
struct V_10 * V_11 )
{
struct V_6 * V_7 ;
int V_25 ;
F_38 ( V_11 -> V_18 ) ;
V_11 -> V_14 = V_14 ;
F_193 ( & V_11 -> V_276 ) ;
F_193 ( & V_11 -> V_277 ) ;
F_193 ( & V_11 -> V_278 ) ;
F_193 ( & V_11 -> V_274 ) ;
F_194 ( V_14 , & V_11 -> V_279 ) ;
memset ( V_11 -> V_202 . V_280 , 0 , sizeof( V_11 -> V_202 . V_280 ) ) ;
F_195 ( & V_11 -> V_281 ) ;
V_7 = F_183 ( V_11 , 32 * V_91 ) ;
if ( F_196 ( V_7 ) ) {
V_25 = F_197 ( V_7 ) ;
goto error;
}
V_11 -> V_18 = V_7 ;
if ( F_57 ( V_14 ) ) {
V_25 = F_163 ( V_11 ) ;
if ( V_25 )
goto error;
} else {
F_198 ( V_11 -> V_68 != V_69 ) ;
V_25 = F_165 ( V_11 ) ;
if ( V_25 )
goto error;
}
V_25 = F_176 ( V_14 , V_7 ) ;
if ( V_25 ) {
F_42 ( L_17 ,
V_11 -> V_84 , V_25 ) ;
F_180 ( V_7 ) ;
goto error;
}
V_25 = F_199 ( V_11 ) ;
if ( V_25 )
goto error;
return 0 ;
error:
F_200 ( V_11 ) ;
return V_25 ;
}
void F_200 ( struct V_10 * V_11 )
{
struct V_12 * V_13 ;
if ( ! F_201 ( V_11 ) )
return;
V_13 = F_44 ( V_11 -> V_14 ) ;
if ( V_11 -> V_18 ) {
F_202 ( V_11 ) ;
F_38 ( ! F_45 ( V_11 -> V_14 ) && ( F_39 ( V_11 ) & V_81 ) == 0 ) ;
F_167 ( V_11 -> V_18 ) ;
F_191 ( V_11 -> V_18 ) ;
V_11 -> V_18 = NULL ;
}
if ( V_11 -> V_282 )
V_11 -> V_282 ( V_11 ) ;
F_162 ( V_11 ) ;
F_203 ( V_11 ) ;
F_204 ( & V_11 -> V_279 ) ;
V_11 -> V_14 = NULL ;
}
static int F_205 ( struct V_10 * V_11 , int V_283 )
{
struct V_6 * V_7 = V_11 -> V_18 ;
struct V_20 * V_284 ;
unsigned V_4 ;
int V_25 ;
if ( F_3 ( V_7 ) >= V_283 )
return 0 ;
F_38 ( V_7 -> V_285 ) ;
F_206 (request, &ring->request_list, list) {
V_4 = F_1 ( V_284 -> V_286 , V_7 -> V_2 ,
V_7 -> V_3 ) ;
if ( V_4 >= V_283 )
break;
}
if ( F_38 ( & V_284 -> V_287 == & V_11 -> V_277 ) )
return - V_115 ;
V_25 = F_207 ( V_284 ) ;
if ( V_25 )
return V_25 ;
V_7 -> V_4 = V_4 ;
return 0 ;
}
static void F_208 ( struct V_6 * V_7 )
{
T_4 T_6 * V_288 ;
int V_289 = V_7 -> V_3 - V_7 -> V_2 ;
V_288 = V_7 -> V_261 + V_7 -> V_2 ;
V_289 /= 4 ;
while ( V_289 -- )
F_209 ( V_31 , V_288 ++ ) ;
V_7 -> V_2 = 0 ;
F_2 ( V_7 ) ;
}
int F_210 ( struct V_10 * V_11 )
{
struct V_20 * V_21 ;
if ( F_211 ( & V_11 -> V_277 ) )
return 0 ;
V_21 = F_212 ( V_11 -> V_277 . V_290 ,
struct V_20 ,
V_287 ) ;
return F_213 ( V_21 ,
F_214 ( & F_44 ( V_11 -> V_14 ) -> V_16 . V_291 ) ,
F_44 ( V_11 -> V_14 ) -> V_292 . V_293 ,
NULL , NULL ) ;
}
int F_215 ( struct V_20 * V_284 )
{
V_284 -> V_7 = V_284 -> V_11 -> V_18 ;
return 0 ;
}
int F_216 ( struct V_20 * V_284 )
{
F_217 ( V_284 -> V_7 , V_294 ) ;
return F_8 ( V_284 , 0 ) ;
}
void F_217 ( struct V_6 * V_7 , int V_3 )
{
F_38 ( V_7 -> V_295 ) ;
F_38 ( V_7 -> V_285 ) ;
V_7 -> V_295 = V_3 ;
}
void F_218 ( struct V_6 * V_7 )
{
F_38 ( V_7 -> V_285 ) ;
V_7 -> V_295 = 0 ;
V_7 -> V_285 = false ;
}
void F_219 ( struct V_6 * V_7 )
{
F_38 ( V_7 -> V_285 ) ;
V_7 -> V_285 = true ;
V_7 -> V_296 = V_7 -> V_2 ;
}
void F_220 ( struct V_6 * V_7 )
{
F_38 ( ! V_7 -> V_285 ) ;
if ( V_7 -> V_2 > V_7 -> V_296 ) {
F_221 ( V_7 -> V_2 > V_7 -> V_296 + V_7 -> V_295 ,
L_18 ,
V_7 -> V_2 - V_7 -> V_296 , V_7 -> V_295 ) ;
} else {
}
V_7 -> V_295 = 0 ;
V_7 -> V_285 = false ;
}
static int F_222 ( struct V_10 * V_11 , int V_297 )
{
struct V_6 * V_7 = V_11 -> V_18 ;
int V_298 = V_7 -> V_275 - V_7 -> V_2 ;
int V_299 = V_7 -> V_3 - V_7 -> V_2 ;
int V_25 , V_300 , V_301 = 0 ;
bool V_302 = false ;
if ( V_7 -> V_285 )
V_300 = V_297 ;
else
V_300 = V_297 + V_7 -> V_295 ;
if ( F_223 ( V_297 > V_298 ) ) {
V_301 = V_299 + V_300 ;
V_302 = true ;
} else {
if ( F_223 ( V_300 > V_298 ) ) {
V_301 = V_299 + V_7 -> V_295 ;
V_302 = true ;
} else if ( V_300 > V_7 -> V_4 ) {
V_301 = V_300 ;
}
}
if ( V_301 ) {
V_25 = F_205 ( V_11 , V_301 ) ;
if ( F_223 ( V_25 ) )
return V_25 ;
if ( V_302 )
F_208 ( V_7 ) ;
}
return 0 ;
}
int F_8 ( struct V_20 * V_21 ,
int V_196 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
int V_25 ;
F_38 ( V_21 == NULL ) ;
V_11 = V_21 -> V_11 ;
V_13 = V_11 -> V_14 -> V_15 ;
V_25 = F_224 ( & V_13 -> V_16 ,
V_13 -> V_292 . V_293 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_222 ( V_11 , V_196 * sizeof( T_4 ) ) ;
if ( V_25 )
return V_25 ;
V_11 -> V_18 -> V_4 -= V_196 * sizeof( T_4 ) ;
return 0 ;
}
int F_225 ( struct V_20 * V_21 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
int V_196 = ( V_11 -> V_18 -> V_2 & ( V_40 - 1 ) ) / sizeof( T_4 ) ;
int V_25 ;
if ( V_196 == 0 )
return 0 ;
V_196 = V_40 / sizeof( T_4 ) - V_196 ;
V_25 = F_8 ( V_21 , V_196 ) ;
if ( V_25 )
return V_25 ;
while ( V_196 -- )
F_9 ( V_11 , V_31 ) ;
F_10 ( V_11 ) ;
return 0 ;
}
void F_226 ( struct V_10 * V_11 , T_1 V_201 )
{
struct V_32 * V_14 = V_11 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
if ( F_24 ( V_14 ) -> V_60 == 6 || F_24 ( V_14 ) -> V_60 == 7 ) {
F_30 ( F_227 ( V_11 -> V_61 ) , 0 ) ;
F_30 ( F_228 ( V_11 -> V_61 ) , 0 ) ;
if ( F_229 ( V_14 ) )
F_30 ( F_230 ( V_11 -> V_61 ) , 0 ) ;
}
V_11 -> V_303 ( V_11 , V_201 ) ;
V_11 -> V_95 . V_201 = V_201 ;
}
static void F_231 ( struct V_10 * V_11 ,
T_1 V_58 )
{
struct V_12 * V_13 = V_11 -> V_14 -> V_15 ;
F_30 ( V_304 ,
F_40 ( V_305 ) ) ;
F_232 ( V_306 , 0x0 ) ;
if ( F_41 ( ( F_28 ( V_304 ) &
V_307 ) == 0 ,
50 ) )
F_42 ( L_19 ) ;
F_22 ( V_11 , V_58 ) ;
F_36 ( F_233 ( V_11 -> V_61 ) ) ;
F_30 ( V_304 ,
F_52 ( V_305 ) ) ;
}
static int F_234 ( struct V_20 * V_21 ,
T_1 V_308 , T_1 V_309 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
T_4 V_24 ;
int V_25 ;
V_25 = F_8 ( V_21 , 4 ) ;
if ( V_25 )
return V_25 ;
V_24 = V_206 ;
if ( F_24 ( V_11 -> V_14 ) -> V_60 >= 8 )
V_24 += 1 ;
V_24 |= V_310 | V_207 ;
if ( V_308 & V_311 )
V_24 |= V_312 | V_313 ;
F_9 ( V_11 , V_24 ) ;
F_9 ( V_11 , V_314 | V_208 ) ;
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
F_235 ( struct V_20 * V_21 ,
T_2 V_237 , T_1 V_244 ,
unsigned V_239 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
bool V_315 = F_236 ( V_11 -> V_14 ) &&
! ( V_239 & V_242 ) ;
int V_25 ;
V_25 = F_8 ( V_21 , 4 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_11 , V_316 | ( V_315 << 8 ) |
( V_239 & V_317 ?
V_318 : 0 ) ) ;
F_9 ( V_11 , F_112 ( V_237 ) ) ;
F_9 ( V_11 , F_113 ( V_237 ) ) ;
F_9 ( V_11 , V_31 ) ;
F_10 ( V_11 ) ;
return 0 ;
}
static int
F_237 ( struct V_20 * V_21 ,
T_2 V_237 , T_1 V_244 ,
unsigned V_239 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
int V_25 ;
V_25 = F_8 ( V_21 , 2 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_11 ,
V_240 |
( V_239 & V_242 ?
0 : V_319 | V_320 ) |
( V_239 & V_317 ?
V_318 : 0 ) ) ;
F_9 ( V_11 , V_237 ) ;
F_10 ( V_11 ) ;
return 0 ;
}
static int
F_238 ( struct V_20 * V_21 ,
T_2 V_237 , T_1 V_244 ,
unsigned V_239 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
int V_25 ;
V_25 = F_8 ( V_21 , 2 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_11 ,
V_240 |
( V_239 & V_242 ?
0 : V_243 ) ) ;
F_9 ( V_11 , V_237 ) ;
F_10 ( V_11 ) ;
return 0 ;
}
static int F_239 ( struct V_20 * V_21 ,
T_1 V_308 , T_1 V_309 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
struct V_32 * V_14 = V_11 -> V_14 ;
T_4 V_24 ;
int V_25 ;
V_25 = F_8 ( V_21 , 4 ) ;
if ( V_25 )
return V_25 ;
V_24 = V_206 ;
if ( F_24 ( V_14 ) -> V_60 >= 8 )
V_24 += 1 ;
V_24 |= V_310 | V_207 ;
if ( V_308 & V_27 )
V_24 |= V_312 ;
F_9 ( V_11 , V_24 ) ;
F_9 ( V_11 , V_314 | V_208 ) ;
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
int F_240 ( struct V_32 * V_14 )
{
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_10 * V_11 = & V_13 -> V_11 [ V_69 ] ;
struct V_86 * V_87 ;
int V_25 ;
V_11 -> V_84 = L_20 ;
V_11 -> V_68 = V_69 ;
V_11 -> V_61 = V_321 ;
if ( F_24 ( V_14 ) -> V_60 >= 8 ) {
if ( F_241 ( V_14 ) ) {
V_87 = F_68 ( V_14 , 4096 ) ;
if ( V_87 == NULL ) {
F_42 ( L_21 ) ;
V_322 . V_323 = 0 ;
} else {
F_69 ( V_87 , V_101 ) ;
V_25 = F_70 ( V_87 , 0 , V_324 ) ;
if ( V_25 != 0 ) {
F_66 ( & V_87 -> V_98 ) ;
F_42 ( L_22 ) ;
V_322 . V_323 = 0 ;
} else
V_13 -> V_194 = V_87 ;
}
}
V_11 -> V_325 = F_77 ;
V_11 -> V_326 = F_119 ;
V_11 -> V_309 = F_20 ;
V_11 -> V_327 = F_155 ;
V_11 -> V_328 = F_157 ;
V_11 -> V_233 = V_329 ;
V_11 -> V_330 = F_127 ;
V_11 -> V_303 = F_130 ;
if ( F_241 ( V_14 ) ) {
F_38 ( ! V_13 -> V_194 ) ;
V_11 -> V_202 . V_331 = F_121 ;
V_11 -> V_202 . signal = F_107 ;
V_332 ;
}
} else if ( F_24 ( V_14 ) -> V_60 >= 6 ) {
V_11 -> V_325 = F_77 ;
V_11 -> V_326 = F_119 ;
V_11 -> V_309 = F_18 ;
if ( F_24 ( V_14 ) -> V_60 == 6 )
V_11 -> V_309 = F_16 ;
V_11 -> V_327 = F_149 ;
V_11 -> V_328 = F_150 ;
V_11 -> V_233 = V_329 ;
V_11 -> V_330 = F_127 ;
V_11 -> V_303 = F_130 ;
if ( F_241 ( V_14 ) ) {
V_11 -> V_202 . V_331 = F_123 ;
V_11 -> V_202 . signal = F_116 ;
V_11 -> V_202 . V_211 . V_227 [ V_69 ] = V_204 ;
V_11 -> V_202 . V_211 . V_227 [ V_74 ] = V_333 ;
V_11 -> V_202 . V_211 . V_227 [ V_71 ] = V_334 ;
V_11 -> V_202 . V_211 . V_227 [ V_76 ] = V_335 ;
V_11 -> V_202 . V_211 . V_227 [ V_73 ] = V_204 ;
V_11 -> V_202 . V_211 . signal [ V_69 ] = V_336 ;
V_11 -> V_202 . V_211 . signal [ V_74 ] = V_337 ;
V_11 -> V_202 . V_211 . signal [ V_71 ] = V_338 ;
V_11 -> V_202 . V_211 . signal [ V_76 ] = V_339 ;
V_11 -> V_202 . V_211 . signal [ V_73 ] = V_336 ;
}
} else if ( F_13 ( V_14 ) ) {
V_11 -> V_326 = F_125 ;
V_11 -> V_309 = F_11 ;
V_11 -> V_330 = F_132 ;
V_11 -> V_303 = F_133 ;
V_11 -> V_327 = F_134 ;
V_11 -> V_328 = F_139 ;
V_11 -> V_233 = V_329 |
V_340 ;
} else {
V_11 -> V_326 = F_148 ;
if ( F_24 ( V_14 ) -> V_60 < 4 )
V_11 -> V_309 = F_7 ;
else
V_11 -> V_309 = F_11 ;
V_11 -> V_330 = F_129 ;
V_11 -> V_303 = F_130 ;
if ( F_45 ( V_14 ) ) {
V_11 -> V_327 = F_143 ;
V_11 -> V_328 = F_146 ;
} else {
V_11 -> V_327 = F_141 ;
V_11 -> V_328 = F_142 ;
}
V_11 -> V_233 = V_341 ;
}
V_11 -> V_19 = F_21 ;
if ( F_242 ( V_14 ) )
V_11 -> V_342 = F_237 ;
else if ( F_243 ( V_14 ) )
V_11 -> V_342 = F_235 ;
else if ( F_24 ( V_14 ) -> V_60 >= 6 )
V_11 -> V_342 = F_238 ;
else if ( F_24 ( V_14 ) -> V_60 >= 4 )
V_11 -> V_342 = F_158 ;
else if ( F_187 ( V_14 ) || F_188 ( V_14 ) )
V_11 -> V_342 = F_159 ;
else
V_11 -> V_342 = F_161 ;
V_11 -> V_343 = F_102 ;
V_11 -> V_282 = F_106 ;
if ( F_244 ( V_14 ) ) {
V_87 = F_68 ( V_14 , V_344 ) ;
if ( V_87 == NULL ) {
F_42 ( L_23 ) ;
return - V_99 ;
}
V_25 = F_70 ( V_87 , 0 , 0 ) ;
if ( V_25 != 0 ) {
F_66 ( & V_87 -> V_98 ) ;
F_42 ( L_24 ) ;
return V_25 ;
}
V_11 -> V_38 . V_87 = V_87 ;
V_11 -> V_38 . V_39 = F_59 ( V_87 ) ;
}
V_25 = F_192 ( V_14 , V_11 ) ;
if ( V_25 )
return V_25 ;
if ( F_24 ( V_14 ) -> V_60 >= 5 ) {
V_25 = F_67 ( V_11 ) ;
if ( V_25 )
return V_25 ;
}
return 0 ;
}
int F_245 ( struct V_32 * V_14 )
{
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_10 * V_11 = & V_13 -> V_11 [ V_74 ] ;
V_11 -> V_84 = L_25 ;
V_11 -> V_68 = V_74 ;
V_11 -> V_19 = F_21 ;
if ( F_24 ( V_14 ) -> V_60 >= 6 ) {
V_11 -> V_61 = V_345 ;
if ( F_33 ( V_14 ) )
V_11 -> V_19 = F_231 ;
V_11 -> V_309 = F_234 ;
V_11 -> V_326 = F_119 ;
V_11 -> V_330 = F_127 ;
V_11 -> V_303 = F_130 ;
if ( F_24 ( V_14 ) -> V_60 >= 8 ) {
V_11 -> V_233 =
V_329 << V_346 ;
V_11 -> V_327 = F_155 ;
V_11 -> V_328 = F_157 ;
V_11 -> V_342 =
F_235 ;
if ( F_241 ( V_14 ) ) {
V_11 -> V_202 . V_331 = F_121 ;
V_11 -> V_202 . signal = F_115 ;
V_332 ;
}
} else {
V_11 -> V_233 = V_347 ;
V_11 -> V_327 = F_149 ;
V_11 -> V_328 = F_150 ;
V_11 -> V_342 =
F_238 ;
if ( F_241 ( V_14 ) ) {
V_11 -> V_202 . V_331 = F_123 ;
V_11 -> V_202 . signal = F_116 ;
V_11 -> V_202 . V_211 . V_227 [ V_69 ] = V_348 ;
V_11 -> V_202 . V_211 . V_227 [ V_74 ] = V_204 ;
V_11 -> V_202 . V_211 . V_227 [ V_71 ] = V_349 ;
V_11 -> V_202 . V_211 . V_227 [ V_76 ] = V_350 ;
V_11 -> V_202 . V_211 . V_227 [ V_73 ] = V_204 ;
V_11 -> V_202 . V_211 . signal [ V_69 ] = V_351 ;
V_11 -> V_202 . V_211 . signal [ V_74 ] = V_336 ;
V_11 -> V_202 . V_211 . signal [ V_71 ] = V_352 ;
V_11 -> V_202 . V_211 . signal [ V_76 ] = V_353 ;
V_11 -> V_202 . V_211 . signal [ V_73 ] = V_336 ;
}
}
} else {
V_11 -> V_61 = V_354 ;
V_11 -> V_309 = F_147 ;
V_11 -> V_326 = F_148 ;
V_11 -> V_330 = F_129 ;
V_11 -> V_303 = F_130 ;
if ( F_13 ( V_14 ) ) {
V_11 -> V_233 = V_355 ;
V_11 -> V_327 = F_134 ;
V_11 -> V_328 = F_139 ;
} else {
V_11 -> V_233 = V_356 ;
V_11 -> V_327 = F_141 ;
V_11 -> V_328 = F_142 ;
}
V_11 -> V_342 = F_158 ;
}
V_11 -> V_343 = F_53 ;
return F_192 ( V_14 , V_11 ) ;
}
int F_246 ( struct V_32 * V_14 )
{
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_10 * V_11 = & V_13 -> V_11 [ V_73 ] ;
V_11 -> V_84 = L_26 ;
V_11 -> V_68 = V_73 ;
V_11 -> V_19 = F_21 ;
V_11 -> V_61 = V_357 ;
V_11 -> V_309 = F_234 ;
V_11 -> V_326 = F_119 ;
V_11 -> V_330 = F_127 ;
V_11 -> V_303 = F_130 ;
V_11 -> V_233 =
V_329 << V_358 ;
V_11 -> V_327 = F_155 ;
V_11 -> V_328 = F_157 ;
V_11 -> V_342 =
F_235 ;
if ( F_241 ( V_14 ) ) {
V_11 -> V_202 . V_331 = F_121 ;
V_11 -> V_202 . signal = F_115 ;
V_332 ;
}
V_11 -> V_343 = F_53 ;
return F_192 ( V_14 , V_11 ) ;
}
int F_247 ( struct V_32 * V_14 )
{
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_10 * V_11 = & V_13 -> V_11 [ V_71 ] ;
V_11 -> V_84 = L_27 ;
V_11 -> V_68 = V_71 ;
V_11 -> V_61 = V_359 ;
V_11 -> V_19 = F_21 ;
V_11 -> V_309 = F_239 ;
V_11 -> V_326 = F_119 ;
V_11 -> V_330 = F_127 ;
V_11 -> V_303 = F_130 ;
if ( F_24 ( V_14 ) -> V_60 >= 8 ) {
V_11 -> V_233 =
V_329 << V_360 ;
V_11 -> V_327 = F_155 ;
V_11 -> V_328 = F_157 ;
V_11 -> V_342 = F_235 ;
if ( F_241 ( V_14 ) ) {
V_11 -> V_202 . V_331 = F_121 ;
V_11 -> V_202 . signal = F_115 ;
V_332 ;
}
} else {
V_11 -> V_233 = V_361 ;
V_11 -> V_327 = F_149 ;
V_11 -> V_328 = F_150 ;
V_11 -> V_342 = F_238 ;
if ( F_241 ( V_14 ) ) {
V_11 -> V_202 . signal = F_116 ;
V_11 -> V_202 . V_331 = F_123 ;
V_11 -> V_202 . V_211 . V_227 [ V_69 ] = V_362 ;
V_11 -> V_202 . V_211 . V_227 [ V_74 ] = V_363 ;
V_11 -> V_202 . V_211 . V_227 [ V_71 ] = V_204 ;
V_11 -> V_202 . V_211 . V_227 [ V_76 ] = V_364 ;
V_11 -> V_202 . V_211 . V_227 [ V_73 ] = V_204 ;
V_11 -> V_202 . V_211 . signal [ V_69 ] = V_365 ;
V_11 -> V_202 . V_211 . signal [ V_74 ] = V_366 ;
V_11 -> V_202 . V_211 . signal [ V_71 ] = V_336 ;
V_11 -> V_202 . V_211 . signal [ V_76 ] = V_367 ;
V_11 -> V_202 . V_211 . signal [ V_73 ] = V_336 ;
}
}
V_11 -> V_343 = F_53 ;
return F_192 ( V_14 , V_11 ) ;
}
int F_248 ( struct V_32 * V_14 )
{
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_10 * V_11 = & V_13 -> V_11 [ V_76 ] ;
V_11 -> V_84 = L_28 ;
V_11 -> V_68 = V_76 ;
V_11 -> V_61 = V_368 ;
V_11 -> V_19 = F_21 ;
V_11 -> V_309 = F_239 ;
V_11 -> V_326 = F_119 ;
V_11 -> V_330 = F_127 ;
V_11 -> V_303 = F_130 ;
if ( F_24 ( V_14 ) -> V_60 >= 8 ) {
V_11 -> V_233 =
V_329 << V_369 ;
V_11 -> V_327 = F_155 ;
V_11 -> V_328 = F_157 ;
V_11 -> V_342 = F_235 ;
if ( F_241 ( V_14 ) ) {
V_11 -> V_202 . V_331 = F_121 ;
V_11 -> V_202 . signal = F_115 ;
V_332 ;
}
} else {
V_11 -> V_233 = V_370 ;
V_11 -> V_327 = F_151 ;
V_11 -> V_328 = F_153 ;
V_11 -> V_342 = F_238 ;
if ( F_241 ( V_14 ) ) {
V_11 -> V_202 . V_331 = F_123 ;
V_11 -> V_202 . signal = F_116 ;
V_11 -> V_202 . V_211 . V_227 [ V_69 ] = V_371 ;
V_11 -> V_202 . V_211 . V_227 [ V_74 ] = V_372 ;
V_11 -> V_202 . V_211 . V_227 [ V_71 ] = V_373 ;
V_11 -> V_202 . V_211 . V_227 [ V_76 ] = V_204 ;
V_11 -> V_202 . V_211 . V_227 [ V_73 ] = V_204 ;
V_11 -> V_202 . V_211 . signal [ V_69 ] = V_374 ;
V_11 -> V_202 . V_211 . signal [ V_74 ] = V_375 ;
V_11 -> V_202 . V_211 . signal [ V_71 ] = V_376 ;
V_11 -> V_202 . V_211 . signal [ V_76 ] = V_336 ;
V_11 -> V_202 . V_211 . signal [ V_73 ] = V_336 ;
}
}
V_11 -> V_343 = F_53 ;
return F_192 ( V_14 , V_11 ) ;
}
int
F_74 ( struct V_20 * V_21 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
int V_25 ;
if ( ! V_11 -> V_110 )
return 0 ;
V_25 = V_11 -> V_309 ( V_21 , 0 , V_311 ) ;
if ( V_25 )
return V_25 ;
F_249 ( V_21 , 0 , V_311 ) ;
V_11 -> V_110 = false ;
return 0 ;
}
int
F_250 ( struct V_20 * V_21 )
{
struct V_10 * V_11 = V_21 -> V_11 ;
T_4 V_23 ;
int V_25 ;
V_23 = 0 ;
if ( V_11 -> V_110 )
V_23 = V_311 ;
V_25 = V_11 -> V_309 ( V_21 , V_311 , V_23 ) ;
if ( V_25 )
return V_25 ;
F_249 ( V_21 , V_311 , V_23 ) ;
V_11 -> V_110 = false ;
return 0 ;
}
void
F_202 ( struct V_10 * V_11 )
{
int V_25 ;
if ( ! F_201 ( V_11 ) )
return;
V_25 = F_210 ( V_11 ) ;
if ( V_25 && ! F_251 ( & F_44 ( V_11 -> V_14 ) -> V_16 ) )
F_42 ( L_29 ,
V_11 -> V_84 , V_25 ) ;
F_43 ( V_11 ) ;
}
