bool
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! V_4 )
return false ;
if ( V_5 . V_6 ) {
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = V_8 -> V_12 [ V_2 -> V_13 ] . V_11 ;
return V_11 -> V_14 ;
} else
return V_2 -> V_15 && V_2 -> V_15 -> V_14 ;
}
int F_2 ( int V_16 , int V_17 , int V_18 )
{
int V_19 = V_16 - V_17 ;
if ( V_19 <= 0 )
V_19 += V_18 ;
return V_19 - V_20 ;
}
void F_3 ( struct V_10 * V_11 )
{
if ( V_11 -> V_21 != - 1 ) {
V_11 -> V_16 = V_11 -> V_21 ;
V_11 -> V_21 = - 1 ;
}
V_11 -> V_19 = F_2 ( V_11 -> V_16 & V_22 ,
V_11 -> V_17 , V_11 -> V_18 ) ;
}
int F_4 ( struct V_10 * V_11 )
{
F_3 ( V_11 ) ;
return V_11 -> V_19 ;
}
bool F_5 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_4 -> V_25 ;
return V_24 -> V_26 . V_27 & F_6 ( V_2 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_15 ;
V_11 -> V_17 &= V_11 -> V_18 - 1 ;
if ( F_5 ( V_2 ) )
return;
V_2 -> V_28 ( V_2 , V_11 -> V_17 ) ;
}
static int
F_8 ( struct V_1 * V_2 ,
T_1 V_29 ,
T_1 V_30 )
{
T_1 V_31 ;
int V_32 ;
V_31 = V_33 ;
if ( ( ( V_29 | V_30 ) & V_34 ) == 0 )
V_31 |= V_35 ;
if ( V_29 & V_36 )
V_31 |= V_37 ;
V_32 = F_9 ( V_2 , 2 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , V_31 ) ;
F_10 ( V_2 , V_38 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_12 ( struct V_1 * V_2 ,
T_1 V_29 ,
T_1 V_30 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_31 ;
int V_32 ;
V_31 = V_33 | V_35 ;
if ( ( V_29 | V_30 ) & V_34 )
V_31 &= ~ V_35 ;
if ( V_29 & V_39 )
V_31 |= V_40 ;
if ( V_29 & V_41 &&
( F_13 ( V_4 ) || F_14 ( V_4 ) ) )
V_31 |= V_42 ;
V_32 = F_9 ( V_2 , 2 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , V_31 ) ;
F_10 ( V_2 , V_38 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_15 ( struct V_1 * V_2 )
{
T_1 V_43 = V_2 -> V_44 . V_45 + 2 * V_46 ;
int V_32 ;
V_32 = F_9 ( V_2 , 6 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , F_16 ( 5 ) ) ;
F_10 ( V_2 , V_47 |
V_48 ) ;
F_10 ( V_2 , V_43 | V_49 ) ;
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , V_38 ) ;
F_11 ( V_2 ) ;
V_32 = F_9 ( V_2 , 6 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , F_16 ( 5 ) ) ;
F_10 ( V_2 , V_50 ) ;
F_10 ( V_2 , V_43 | V_49 ) ;
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , V_38 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_17 ( struct V_1 * V_2 ,
T_1 V_29 , T_1 V_30 )
{
T_1 V_51 = 0 ;
T_1 V_43 = V_2 -> V_44 . V_45 + 2 * V_46 ;
int V_32 ;
V_32 = F_15 ( V_2 ) ;
if ( V_32 )
return V_32 ;
if ( V_30 ) {
V_51 |= V_52 ;
V_51 |= V_53 ;
V_51 |= V_47 ;
}
if ( V_29 ) {
V_51 |= V_54 ;
V_51 |= V_55 ;
V_51 |= V_56 ;
V_51 |= V_57 ;
V_51 |= V_58 ;
V_51 |= V_59 ;
V_51 |= V_50 | V_47 ;
}
V_32 = F_9 ( V_2 , 4 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , F_16 ( 4 ) ) ;
F_10 ( V_2 , V_51 ) ;
F_10 ( V_2 , V_43 | V_49 ) ;
F_10 ( V_2 , 0 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_18 ( struct V_1 * V_2 )
{
int V_32 ;
V_32 = F_9 ( V_2 , 4 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , F_16 ( 4 ) ) ;
F_10 ( V_2 , V_47 |
V_48 ) ;
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_19 ( struct V_1 * V_2 ,
T_1 V_29 , T_1 V_30 )
{
T_1 V_51 = 0 ;
T_1 V_43 = V_2 -> V_44 . V_45 + 2 * V_46 ;
int V_32 ;
V_51 |= V_47 ;
if ( V_30 ) {
V_51 |= V_52 ;
V_51 |= V_53 ;
}
if ( V_29 ) {
V_51 |= V_54 ;
V_51 |= V_55 ;
V_51 |= V_56 ;
V_51 |= V_57 ;
V_51 |= V_58 ;
V_51 |= V_59 ;
V_51 |= V_60 ;
V_51 |= V_50 ;
V_51 |= V_61 ;
V_51 |= V_48 ;
F_18 ( V_2 ) ;
}
V_32 = F_9 ( V_2 , 4 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , F_16 ( 4 ) ) ;
F_10 ( V_2 , V_51 ) ;
F_10 ( V_2 , V_43 ) ;
F_10 ( V_2 , 0 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_20 ( struct V_1 * V_2 ,
T_1 V_51 , T_1 V_43 )
{
int V_32 ;
V_32 = F_9 ( V_2 , 6 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , F_16 ( 6 ) ) ;
F_10 ( V_2 , V_51 ) ;
F_10 ( V_2 , V_43 ) ;
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_21 ( struct V_1 * V_2 ,
T_1 V_29 , T_1 V_30 )
{
T_1 V_51 = 0 ;
T_1 V_43 = V_2 -> V_44 . V_45 + 2 * V_46 ;
int V_32 ;
V_51 |= V_47 ;
if ( V_30 ) {
V_51 |= V_52 ;
V_51 |= V_53 ;
}
if ( V_29 ) {
V_51 |= V_54 ;
V_51 |= V_55 ;
V_51 |= V_56 ;
V_51 |= V_57 ;
V_51 |= V_58 ;
V_51 |= V_59 ;
V_51 |= V_50 ;
V_51 |= V_61 ;
V_32 = F_20 ( V_2 ,
V_47 |
V_48 ,
0 ) ;
if ( V_32 )
return V_32 ;
}
return F_20 ( V_2 , V_51 , V_43 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
T_1 V_62 )
{
struct V_23 * V_24 = V_2 -> V_4 -> V_25 ;
F_23 ( V_2 , V_62 ) ;
}
T_2 F_24 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_4 -> V_25 ;
T_2 V_63 ;
if ( F_25 ( V_2 -> V_4 ) -> V_64 >= 8 )
V_63 = F_26 ( F_27 ( V_2 -> V_65 ) ,
F_28 ( V_2 -> V_65 ) ) ;
else if ( F_25 ( V_2 -> V_4 ) -> V_64 >= 4 )
V_63 = F_29 ( F_27 ( V_2 -> V_65 ) ) ;
else
V_63 = F_29 ( V_66 ) ;
return V_63 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_4 -> V_25 ;
T_1 V_67 ;
V_67 = V_24 -> V_68 -> V_69 ;
if ( F_25 ( V_2 -> V_4 ) -> V_64 >= 4 )
V_67 |= ( V_24 -> V_68 -> V_69 >> 28 ) & 0xf0 ;
F_31 ( V_70 , V_67 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_2 -> V_4 -> V_25 ;
T_1 V_71 = 0 ;
if ( F_33 ( V_4 ) ) {
switch ( V_2 -> V_13 ) {
case V_72 :
V_71 = V_73 ;
break;
case V_74 :
V_71 = V_75 ;
break;
case V_76 :
case V_77 :
V_71 = V_78 ;
break;
case V_79 :
V_71 = V_80 ;
break;
}
} else if ( F_34 ( V_2 -> V_4 ) ) {
V_71 = F_35 ( V_2 -> V_65 ) ;
} else {
V_71 = F_36 ( V_2 -> V_65 ) ;
}
F_31 ( V_71 , ( T_1 ) V_2 -> V_81 . V_82 ) ;
F_37 ( V_71 ) ;
if ( F_25 ( V_4 ) -> V_64 >= 6 && F_25 ( V_4 ) -> V_64 < 8 ) {
T_1 V_83 = F_38 ( V_2 -> V_65 ) ;
F_39 ( ( F_40 ( V_2 ) & V_84 ) == 0 ) ;
F_31 ( V_83 ,
F_41 ( V_85 |
V_86 ) ) ;
if ( F_42 ( ( F_29 ( V_83 ) & V_86 ) == 0 ,
1000 ) )
F_43 ( L_1 ,
V_2 -> V_87 ) ;
}
}
static bool F_44 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_45 ( V_2 -> V_4 ) ;
if ( ! F_46 ( V_2 -> V_4 ) ) {
F_47 ( V_2 , F_41 ( V_88 ) ) ;
if ( F_42 ( ( F_40 ( V_2 ) & V_84 ) != 0 , 1000 ) ) {
F_43 ( L_2 , V_2 -> V_87 ) ;
if ( F_48 ( V_2 ) != F_49 ( V_2 ) )
return false ;
}
}
F_50 ( V_2 , 0 ) ;
F_51 ( V_2 , 0 ) ;
V_2 -> V_28 ( V_2 , 0 ) ;
if ( ! F_46 ( V_2 -> V_4 ) ) {
( void ) F_52 ( V_2 ) ;
F_47 ( V_2 , F_53 ( V_88 ) ) ;
}
return ( F_48 ( V_2 ) & V_22 ) == 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_10 * V_11 = V_2 -> V_15 ;
struct V_89 * V_14 = V_11 -> V_14 ;
int V_32 = 0 ;
F_55 ( V_24 , V_90 ) ;
if ( ! F_44 ( V_2 ) ) {
F_56 ( L_3
L_4 ,
V_2 -> V_87 ,
F_52 ( V_2 ) ,
F_48 ( V_2 ) ,
F_49 ( V_2 ) ,
F_57 ( V_2 ) ) ;
if ( ! F_44 ( V_2 ) ) {
F_43 ( L_5
L_4 ,
V_2 -> V_87 ,
F_52 ( V_2 ) ,
F_48 ( V_2 ) ,
F_49 ( V_2 ) ,
F_57 ( V_2 ) ) ;
V_32 = - V_91 ;
goto V_92;
}
}
if ( F_58 ( V_4 ) )
F_32 ( V_2 ) ;
else
F_30 ( V_2 ) ;
F_48 ( V_2 ) ;
F_59 ( V_2 , F_60 ( V_14 ) ) ;
if ( F_48 ( V_2 ) )
F_61 ( L_6 ,
V_2 -> V_87 , F_48 ( V_2 ) ) ;
F_51 ( V_2 , 0 ) ;
( void ) F_48 ( V_2 ) ;
F_50 ( V_2 ,
( ( V_11 -> V_18 - V_93 ) & V_94 )
| V_95 ) ;
if ( F_42 ( ( F_52 ( V_2 ) & V_95 ) != 0 &&
F_57 ( V_2 ) == F_60 ( V_14 ) &&
( F_48 ( V_2 ) & V_22 ) == 0 , 50 ) ) {
F_43 ( L_7
L_8 ,
V_2 -> V_87 ,
F_52 ( V_2 ) , F_52 ( V_2 ) & V_95 ,
F_48 ( V_2 ) , F_49 ( V_2 ) ,
F_57 ( V_2 ) , ( unsigned long ) F_60 ( V_14 ) ) ;
V_32 = - V_91 ;
goto V_92;
}
V_11 -> V_21 = - 1 ;
V_11 -> V_16 = F_48 ( V_2 ) ;
V_11 -> V_17 = F_49 ( V_2 ) & V_96 ;
F_3 ( V_11 ) ;
memset ( & V_2 -> V_97 , 0 , sizeof( V_2 -> V_97 ) ) ;
V_92:
F_62 ( V_24 , V_90 ) ;
return V_32 ;
}
void
F_63 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 -> V_44 . V_14 == NULL )
return;
if ( F_25 ( V_4 ) -> V_64 >= 5 ) {
F_64 ( F_65 ( V_2 -> V_44 . V_14 -> V_98 -> V_99 ) ) ;
F_66 ( V_2 -> V_44 . V_14 ) ;
}
F_67 ( & V_2 -> V_44 . V_14 -> V_100 ) ;
V_2 -> V_44 . V_14 = NULL ;
}
int
F_68 ( struct V_1 * V_2 )
{
int V_32 ;
F_39 ( V_2 -> V_44 . V_14 ) ;
V_2 -> V_44 . V_14 = F_69 ( V_2 -> V_4 , 4096 ) ;
if ( V_2 -> V_44 . V_14 == NULL ) {
F_43 ( L_9 ) ;
V_32 = - V_101 ;
goto V_102;
}
V_32 = F_70 ( V_2 -> V_44 . V_14 , V_103 ) ;
if ( V_32 )
goto V_104;
V_32 = F_71 ( V_2 -> V_44 . V_14 , 4096 , 0 ) ;
if ( V_32 )
goto V_104;
V_2 -> V_44 . V_45 = F_60 ( V_2 -> V_44 . V_14 ) ;
V_2 -> V_44 . V_105 = F_72 ( F_65 ( V_2 -> V_44 . V_14 -> V_98 -> V_99 ) ) ;
if ( V_2 -> V_44 . V_105 == NULL ) {
V_32 = - V_101 ;
goto V_106;
}
F_73 ( L_10 ,
V_2 -> V_87 , V_2 -> V_44 . V_45 ) ;
return 0 ;
V_106:
F_66 ( V_2 -> V_44 . V_14 ) ;
V_104:
F_67 ( & V_2 -> V_44 . V_14 -> V_100 ) ;
V_102:
return V_32 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_7 * V_107 )
{
int V_32 , V_108 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_109 * V_110 = & V_24 -> V_111 ;
if ( F_75 ( V_110 -> V_112 == 0 ) )
return 0 ;
V_2 -> V_113 = true ;
V_32 = F_76 ( V_2 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_9 ( V_2 , ( V_110 -> V_112 * 2 + 2 ) ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , F_77 ( V_110 -> V_112 ) ) ;
for ( V_108 = 0 ; V_108 < V_110 -> V_112 ; V_108 ++ ) {
F_10 ( V_2 , V_110 -> V_83 [ V_108 ] . V_67 ) ;
F_10 ( V_2 , V_110 -> V_83 [ V_108 ] . V_62 ) ;
}
F_10 ( V_2 , V_38 ) ;
F_11 ( V_2 ) ;
V_2 -> V_113 = true ;
V_32 = F_76 ( V_2 ) ;
if ( V_32 )
return V_32 ;
F_73 ( L_11 , V_110 -> V_112 ) ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_7 * V_107 )
{
int V_32 ;
V_32 = F_74 ( V_2 , V_107 ) ;
if ( V_32 != 0 )
return V_32 ;
V_32 = F_79 ( V_2 ) ;
if ( V_32 )
F_43 ( L_12 , V_32 ) ;
return V_32 ;
}
static int F_80 ( struct V_23 * V_24 ,
const T_1 V_67 , const T_1 V_114 , const T_1 V_115 )
{
const T_1 V_116 = V_24 -> V_111 . V_112 ;
if ( F_39 ( V_116 >= V_117 ) )
return - V_118 ;
V_24 -> V_111 . V_83 [ V_116 ] . V_67 = V_67 ;
V_24 -> V_111 . V_83 [ V_116 ] . V_62 = V_115 ;
V_24 -> V_111 . V_83 [ V_116 ] . V_114 = V_114 ;
V_24 -> V_111 . V_112 ++ ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
F_82 ( V_119 ,
V_120 |
V_121 ) ;
F_82 ( V_122 ,
V_123 ) ;
F_82 ( V_124 ,
V_125 ) ;
F_82 ( V_126 ,
V_127 |
V_128 |
V_129 |
( F_83 ( V_4 ) ? V_130 : 0 ) ) ;
F_84 ( V_131 , V_132 ) ;
F_82 ( V_133 ,
V_134 ) ;
F_85 ( V_135 ,
V_136 ,
V_137 ) ;
return 0 ;
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
F_82 ( V_119 ,
V_120 |
V_121 ) ;
F_82 ( V_126 ,
V_127 |
V_129 ) ;
F_84 ( V_131 , V_132 ) ;
F_82 ( V_133 ,
V_134 ) ;
F_82 ( V_138 , V_139 ) ;
F_85 ( V_135 ,
V_136 ,
V_137 ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
F_82 ( V_119 ,
V_120 ) ;
F_82 ( V_124 ,
V_140 ) ;
if ( F_88 ( V_4 ) == V_141 ||
F_88 ( V_4 ) == V_142 ) {
F_84 ( V_143 ,
V_144 ) ;
}
if ( F_89 ( V_4 ) && F_88 ( V_4 ) <= V_142 ) {
F_82 ( V_145 ,
V_146 ) ;
F_82 ( V_147 ,
V_148 ) ;
}
if ( F_88 ( V_4 ) >= V_149 ) {
F_82 ( V_150 ,
V_151 ) ;
}
if ( F_88 ( V_4 ) <= V_152 ) {
F_82 ( V_126 ,
V_127 ) ;
}
F_82 ( V_133 , V_134 ) ;
F_82 ( V_133 , V_153 ) ;
F_84 ( V_143 ,
V_154 ) ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
T_3 V_155 [ 3 ] = { 0 , 0 , 0 } ;
unsigned int V_108 ;
for ( V_108 = 0 ; V_108 < 3 ; V_108 ++ ) {
T_3 V_156 ;
if ( F_91 ( V_24 -> V_157 . V_158 [ V_108 ] ) != 1 )
continue;
V_156 = F_92 ( V_24 -> V_157 . V_158 [ V_108 ] ) - 1 ;
V_155 [ V_108 ] = 3 - V_156 ;
}
if ( V_155 [ 0 ] == 0 && V_155 [ 1 ] == 0 && V_155 [ 2 ] == 0 )
return 0 ;
F_85 ( V_135 ,
F_93 ( 2 ) |
F_93 ( 1 ) |
F_93 ( 0 ) ,
F_94 ( 2 , V_155 [ 2 ] ) |
F_94 ( 1 , V_155 [ 1 ] ) |
F_94 ( 0 , V_155 [ 0 ] ) ) ;
return 0 ;
}
static int F_95 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
F_87 ( V_2 ) ;
if ( F_88 ( V_4 ) == V_142 )
F_82 ( V_138 ,
V_159 ) ;
if ( F_88 ( V_4 ) == V_149 ||
F_88 ( V_4 ) == V_152 )
F_82 ( V_126 ,
V_130 |
V_160 ) ;
return F_90 ( V_2 ) ;
}
int F_96 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
F_39 ( V_2 -> V_13 != V_72 ) ;
V_24 -> V_111 . V_112 = 0 ;
if ( F_97 ( V_4 ) )
return F_81 ( V_2 ) ;
if ( F_98 ( V_4 ) )
return F_86 ( V_2 ) ;
if ( F_89 ( V_4 ) )
return F_95 ( V_2 ) ;
else if ( F_99 ( V_4 ) )
return F_87 ( V_2 ) ;
return 0 ;
}
static int F_100 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
int V_32 = F_54 ( V_2 ) ;
if ( V_32 )
return V_32 ;
if ( F_25 ( V_4 ) -> V_64 >= 4 && F_25 ( V_4 ) -> V_64 < 7 )
F_31 ( V_161 , F_41 ( V_162 ) ) ;
if ( F_25 ( V_4 ) -> V_64 >= 6 && F_25 ( V_4 ) -> V_64 < 9 )
F_31 ( V_161 , F_41 ( V_163 ) ) ;
if ( F_25 ( V_4 ) -> V_64 == 6 )
F_31 ( V_164 ,
F_41 ( V_165 ) ) ;
if ( F_33 ( V_4 ) )
F_31 ( V_166 ,
F_41 ( V_165 ) |
F_41 ( V_167 ) ) ;
if ( F_34 ( V_4 ) ) {
F_31 ( V_168 ,
F_53 ( V_169 ) ) ;
}
if ( F_25 ( V_4 ) -> V_64 >= 6 )
F_31 ( V_170 , F_41 ( V_171 ) ) ;
if ( F_101 ( V_4 ) )
F_102 ( V_2 , ~ F_103 ( V_4 ) ) ;
return F_96 ( V_2 ) ;
}
static void F_104 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
if ( V_24 -> V_172 ) {
F_66 ( V_24 -> V_172 ) ;
F_67 ( & V_24 -> V_172 -> V_100 ) ;
V_24 -> V_172 = NULL ;
}
F_63 ( V_2 ) ;
}
static int F_105 ( struct V_1 * V_173 ,
unsigned int V_174 )
{
#define F_106 8
struct V_3 * V_4 = V_173 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_175 ;
int V_108 , V_32 , V_176 ;
V_176 = F_107 ( F_25 ( V_4 ) -> V_177 ) ;
V_174 += ( V_176 - 1 ) * F_106 ;
#undef F_106
V_32 = F_9 ( V_173 , V_174 ) ;
if ( V_32 )
return V_32 ;
F_108 (waiter, dev_priv, i) {
T_1 V_178 ;
T_2 V_45 = V_173 -> V_179 . V_180 [ V_108 ] ;
if ( V_45 == V_181 )
continue;
V_178 = F_109 (
V_173 -> V_182 ) ;
F_10 ( V_173 , F_16 ( 6 ) ) ;
F_10 ( V_173 , V_61 |
V_50 |
V_183 ) ;
F_10 ( V_173 , F_110 ( V_45 ) ) ;
F_10 ( V_173 , F_111 ( V_45 ) ) ;
F_10 ( V_173 , V_178 ) ;
F_10 ( V_173 , 0 ) ;
F_10 ( V_173 , V_184 |
F_112 ( V_175 -> V_13 ) ) ;
F_10 ( V_173 , 0 ) ;
}
return 0 ;
}
static int F_113 ( struct V_1 * V_173 ,
unsigned int V_174 )
{
#define F_106 6
struct V_3 * V_4 = V_173 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_175 ;
int V_108 , V_32 , V_176 ;
V_176 = F_107 ( F_25 ( V_4 ) -> V_177 ) ;
V_174 += ( V_176 - 1 ) * F_106 ;
#undef F_106
V_32 = F_9 ( V_173 , V_174 ) ;
if ( V_32 )
return V_32 ;
F_108 (waiter, dev_priv, i) {
T_1 V_178 ;
T_2 V_45 = V_173 -> V_179 . V_180 [ V_108 ] ;
if ( V_45 == V_181 )
continue;
V_178 = F_109 (
V_173 -> V_182 ) ;
F_10 ( V_173 , ( V_185 + 1 ) |
V_186 ) ;
F_10 ( V_173 , F_110 ( V_45 ) |
V_187 ) ;
F_10 ( V_173 , F_111 ( V_45 ) ) ;
F_10 ( V_173 , V_178 ) ;
F_10 ( V_173 , V_184 |
F_112 ( V_175 -> V_13 ) ) ;
F_10 ( V_173 , 0 ) ;
}
return 0 ;
}
static int F_114 ( struct V_1 * V_173 ,
unsigned int V_174 )
{
struct V_3 * V_4 = V_173 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_188 ;
int V_108 , V_32 , V_176 ;
#define F_106 3
V_176 = F_107 ( F_25 ( V_4 ) -> V_177 ) ;
V_174 += F_115 ( ( V_176 - 1 ) * F_106 , 2 ) ;
#undef F_106
V_32 = F_9 ( V_173 , V_174 ) ;
if ( V_32 )
return V_32 ;
F_108 (useless, dev_priv, i) {
T_1 V_189 = V_173 -> V_179 . V_190 . signal [ V_108 ] ;
if ( V_189 != V_191 ) {
T_1 V_178 = F_109 (
V_173 -> V_182 ) ;
F_10 ( V_173 , F_77 ( 1 ) ) ;
F_10 ( V_173 , V_189 ) ;
F_10 ( V_173 , V_178 ) ;
}
}
if ( V_176 % 2 == 0 )
F_10 ( V_173 , V_38 ) ;
return 0 ;
}
static int
F_116 ( struct V_1 * V_2 )
{
int V_32 ;
if ( V_2 -> V_179 . signal )
V_32 = V_2 -> V_179 . signal ( V_2 , 4 ) ;
else
V_32 = F_9 ( V_2 , 4 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , V_192 ) ;
F_10 ( V_2 , V_193 << V_194 ) ;
F_10 ( V_2 ,
F_109 ( V_2 -> V_182 ) ) ;
F_10 ( V_2 , V_195 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static inline bool F_117 ( struct V_3 * V_4 ,
T_1 V_178 )
{
struct V_23 * V_24 = V_4 -> V_25 ;
return V_24 -> V_196 < V_178 ;
}
static int
F_118 ( struct V_1 * V_175 ,
struct V_1 * V_173 ,
T_1 V_178 )
{
struct V_23 * V_24 = V_175 -> V_4 -> V_25 ;
int V_32 ;
V_32 = F_9 ( V_175 , 4 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_175 , V_197 |
V_198 |
V_199 |
V_200 ) ;
F_10 ( V_175 , V_178 ) ;
F_10 ( V_175 ,
F_110 ( F_119 ( V_175 , V_173 -> V_13 ) ) ) ;
F_10 ( V_175 ,
F_111 ( F_119 ( V_175 , V_173 -> V_13 ) ) ) ;
F_11 ( V_175 ) ;
return 0 ;
}
static int
F_120 ( struct V_1 * V_175 ,
struct V_1 * V_173 ,
T_1 V_178 )
{
T_1 V_201 = V_202 |
V_203 |
V_204 ;
T_1 V_205 = V_173 -> V_179 . V_190 . V_206 [ V_175 -> V_13 ] ;
int V_32 ;
V_178 -= 1 ;
F_39 ( V_205 == V_181 ) ;
V_32 = F_9 ( V_175 , 4 ) ;
if ( V_32 )
return V_32 ;
if ( F_121 ( ! F_117 ( V_175 -> V_4 , V_178 ) ) ) {
F_10 ( V_175 , V_201 | V_205 ) ;
F_10 ( V_175 , V_178 ) ;
F_10 ( V_175 , 0 ) ;
F_10 ( V_175 , V_38 ) ;
} else {
F_10 ( V_175 , V_38 ) ;
F_10 ( V_175 , V_38 ) ;
F_10 ( V_175 , V_38 ) ;
F_10 ( V_175 , V_38 ) ;
}
F_11 ( V_175 ) ;
return 0 ;
}
static int
F_122 ( struct V_1 * V_2 )
{
T_1 V_43 = V_2 -> V_44 . V_45 + 2 * V_46 ;
int V_32 ;
V_32 = F_9 ( V_2 , 32 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , F_16 ( 4 ) | V_50 |
V_207 |
V_56 ) ;
F_10 ( V_2 , V_2 -> V_44 . V_45 | V_49 ) ;
F_10 ( V_2 ,
F_109 ( V_2 -> V_182 ) ) ;
F_10 ( V_2 , 0 ) ;
F_123 ( V_2 , V_43 ) ;
V_43 += 2 * V_46 ;
F_123 ( V_2 , V_43 ) ;
V_43 += 2 * V_46 ;
F_123 ( V_2 , V_43 ) ;
V_43 += 2 * V_46 ;
F_123 ( V_2 , V_43 ) ;
V_43 += 2 * V_46 ;
F_123 ( V_2 , V_43 ) ;
V_43 += 2 * V_46 ;
F_123 ( V_2 , V_43 ) ;
F_10 ( V_2 , F_16 ( 4 ) | V_50 |
V_207 |
V_56 |
V_208 ) ;
F_10 ( V_2 , V_2 -> V_44 . V_45 | V_49 ) ;
F_10 ( V_2 ,
F_109 ( V_2 -> V_182 ) ) ;
F_10 ( V_2 , 0 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static T_1
F_124 ( struct V_1 * V_2 , bool V_209 )
{
if ( ! V_209 ) {
struct V_23 * V_24 = V_2 -> V_4 -> V_25 ;
F_37 ( F_27 ( V_2 -> V_65 ) ) ;
}
return F_125 ( V_2 , V_193 ) ;
}
static T_1
F_126 ( struct V_1 * V_2 , bool V_209 )
{
return F_125 ( V_2 , V_193 ) ;
}
static void
F_127 ( struct V_1 * V_2 , T_1 V_178 )
{
F_128 ( V_2 , V_193 , V_178 ) ;
}
static T_1
F_129 ( struct V_1 * V_2 , bool V_209 )
{
return V_2 -> V_44 . V_105 [ 0 ] ;
}
static void
F_130 ( struct V_1 * V_2 , T_1 V_178 )
{
V_2 -> V_44 . V_105 [ 0 ] = V_178 ;
}
static bool
F_131 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
if ( F_39 ( ! F_132 ( V_24 ) ) )
return false ;
F_133 ( & V_24 -> V_210 , V_51 ) ;
if ( V_2 -> V_211 ++ == 0 )
F_134 ( V_24 , V_2 -> V_212 ) ;
F_135 ( & V_24 -> V_210 , V_51 ) ;
return true ;
}
static void
F_136 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
F_133 ( & V_24 -> V_210 , V_51 ) ;
if ( -- V_2 -> V_211 == 0 )
F_137 ( V_24 , V_2 -> V_212 ) ;
F_135 ( & V_24 -> V_210 , V_51 ) ;
}
static bool
F_138 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
if ( ! F_132 ( V_24 ) )
return false ;
F_133 ( & V_24 -> V_210 , V_51 ) ;
if ( V_2 -> V_211 ++ == 0 ) {
V_24 -> V_213 &= ~ V_2 -> V_212 ;
F_31 ( V_214 , V_24 -> V_213 ) ;
F_37 ( V_214 ) ;
}
F_135 ( & V_24 -> V_210 , V_51 ) ;
return true ;
}
static void
F_139 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
F_133 ( & V_24 -> V_210 , V_51 ) ;
if ( -- V_2 -> V_211 == 0 ) {
V_24 -> V_213 |= V_2 -> V_212 ;
F_31 ( V_214 , V_24 -> V_213 ) ;
F_37 ( V_214 ) ;
}
F_135 ( & V_24 -> V_210 , V_51 ) ;
}
static bool
F_140 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
if ( ! F_132 ( V_24 ) )
return false ;
F_133 ( & V_24 -> V_210 , V_51 ) ;
if ( V_2 -> V_211 ++ == 0 ) {
V_24 -> V_213 &= ~ V_2 -> V_212 ;
F_141 ( V_214 , V_24 -> V_213 ) ;
F_142 ( V_214 ) ;
}
F_135 ( & V_24 -> V_210 , V_51 ) ;
return true ;
}
static void
F_143 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
F_133 ( & V_24 -> V_210 , V_51 ) ;
if ( -- V_2 -> V_211 == 0 ) {
V_24 -> V_213 |= V_2 -> V_212 ;
F_141 ( V_214 , V_24 -> V_213 ) ;
F_142 ( V_214 ) ;
}
F_135 ( & V_24 -> V_210 , V_51 ) ;
}
static int
F_144 ( struct V_1 * V_2 ,
T_1 V_29 ,
T_1 V_30 )
{
int V_32 ;
V_32 = F_9 ( V_2 , 2 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , V_33 ) ;
F_10 ( V_2 , V_38 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_145 ( struct V_1 * V_2 )
{
int V_32 ;
V_32 = F_9 ( V_2 , 4 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , V_192 ) ;
F_10 ( V_2 , V_193 << V_194 ) ;
F_10 ( V_2 ,
F_109 ( V_2 -> V_182 ) ) ;
F_10 ( V_2 , V_195 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static bool
F_146 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
if ( F_39 ( ! F_132 ( V_24 ) ) )
return false ;
F_133 ( & V_24 -> V_210 , V_51 ) ;
if ( V_2 -> V_211 ++ == 0 ) {
if ( F_101 ( V_4 ) && V_2 -> V_13 == V_72 )
F_102 ( V_2 ,
~ ( V_2 -> V_212 |
F_103 ( V_4 ) ) ) ;
else
F_102 ( V_2 , ~ V_2 -> V_212 ) ;
F_134 ( V_24 , V_2 -> V_212 ) ;
}
F_135 ( & V_24 -> V_210 , V_51 ) ;
return true ;
}
static void
F_147 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
F_133 ( & V_24 -> V_210 , V_51 ) ;
if ( -- V_2 -> V_211 == 0 ) {
if ( F_101 ( V_4 ) && V_2 -> V_13 == V_72 )
F_102 ( V_2 , ~ F_103 ( V_4 ) ) ;
else
F_102 ( V_2 , ~ 0 ) ;
F_137 ( V_24 , V_2 -> V_212 ) ;
}
F_135 ( & V_24 -> V_210 , V_51 ) ;
}
static bool
F_148 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
if ( F_39 ( ! F_132 ( V_24 ) ) )
return false ;
F_133 ( & V_24 -> V_210 , V_51 ) ;
if ( V_2 -> V_211 ++ == 0 ) {
F_102 ( V_2 , ~ V_2 -> V_212 ) ;
F_149 ( V_24 , V_2 -> V_212 ) ;
}
F_135 ( & V_24 -> V_210 , V_51 ) ;
return true ;
}
static void
F_150 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
F_133 ( & V_24 -> V_210 , V_51 ) ;
if ( -- V_2 -> V_211 == 0 ) {
F_102 ( V_2 , ~ 0 ) ;
F_151 ( V_24 , V_2 -> V_212 ) ;
}
F_135 ( & V_24 -> V_210 , V_51 ) ;
}
static bool
F_152 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
if ( F_39 ( ! F_132 ( V_24 ) ) )
return false ;
F_133 ( & V_24 -> V_210 , V_51 ) ;
if ( V_2 -> V_211 ++ == 0 ) {
if ( F_101 ( V_4 ) && V_2 -> V_13 == V_72 ) {
F_102 ( V_2 ,
~ ( V_2 -> V_212 |
V_215 ) ) ;
} else {
F_102 ( V_2 , ~ V_2 -> V_212 ) ;
}
F_37 ( F_153 ( V_2 -> V_65 ) ) ;
}
F_135 ( & V_24 -> V_210 , V_51 ) ;
return true ;
}
static void
F_154 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
F_133 ( & V_24 -> V_210 , V_51 ) ;
if ( -- V_2 -> V_211 == 0 ) {
if ( F_101 ( V_4 ) && V_2 -> V_13 == V_72 ) {
F_102 ( V_2 ,
~ V_215 ) ;
} else {
F_102 ( V_2 , ~ 0 ) ;
}
F_37 ( F_153 ( V_2 -> V_65 ) ) ;
}
F_135 ( & V_24 -> V_210 , V_51 ) ;
}
static int
F_155 ( struct V_1 * V_2 ,
T_2 V_216 , T_1 V_217 ,
unsigned V_218 )
{
int V_32 ;
V_32 = F_9 ( V_2 , 2 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 ,
V_219 |
V_220 |
( V_218 & V_221 ?
0 : V_222 ) ) ;
F_10 ( V_2 , V_216 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_156 ( struct V_1 * V_2 ,
T_2 V_216 , T_1 V_223 ,
unsigned V_218 )
{
T_1 V_224 = V_2 -> V_44 . V_45 ;
int V_32 ;
V_32 = F_9 ( V_2 , 6 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , V_225 | V_226 ) ;
F_10 ( V_2 , V_227 | V_228 | 4096 ) ;
F_10 ( V_2 , V_229 << 16 | 4 ) ;
F_10 ( V_2 , V_224 ) ;
F_10 ( V_2 , 0xdeadbeef ) ;
F_10 ( V_2 , V_38 ) ;
F_11 ( V_2 ) ;
if ( ( V_218 & V_230 ) == 0 ) {
if ( V_223 > V_231 )
return - V_118 ;
V_32 = F_9 ( V_2 , 6 + 2 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , V_232 | V_226 ) ;
F_10 ( V_2 , V_227 | V_233 | 4096 ) ;
F_10 ( V_2 , F_157 ( V_223 , 4096 ) << 16 | 4096 ) ;
F_10 ( V_2 , V_224 ) ;
F_10 ( V_2 , 4096 ) ;
F_10 ( V_2 , V_216 ) ;
F_10 ( V_2 , V_33 ) ;
F_10 ( V_2 , V_38 ) ;
F_11 ( V_2 ) ;
V_216 = V_224 ;
}
V_32 = F_9 ( V_2 , 4 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , V_234 ) ;
F_10 ( V_2 , V_216 | ( V_218 & V_221 ?
0 : V_235 ) ) ;
F_10 ( V_2 , V_216 + V_223 - 8 ) ;
F_10 ( V_2 , V_38 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_158 ( struct V_1 * V_2 ,
T_2 V_216 , T_1 V_223 ,
unsigned V_218 )
{
int V_32 ;
V_32 = F_9 ( V_2 , 2 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , V_219 | V_220 ) ;
F_10 ( V_2 , V_216 | ( V_218 & V_221 ?
0 : V_235 ) ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static void F_159 ( struct V_1 * V_2 )
{
struct V_89 * V_14 ;
V_14 = V_2 -> V_81 . V_14 ;
if ( V_14 == NULL )
return;
F_64 ( F_65 ( V_14 -> V_98 -> V_99 ) ) ;
F_66 ( V_14 ) ;
F_67 ( & V_14 -> V_100 ) ;
V_2 -> V_81 . V_14 = NULL ;
}
static int F_160 ( struct V_1 * V_2 )
{
struct V_89 * V_14 ;
if ( ( V_14 = V_2 -> V_81 . V_14 ) == NULL ) {
unsigned V_51 ;
int V_32 ;
V_14 = F_69 ( V_2 -> V_4 , 4096 ) ;
if ( V_14 == NULL ) {
F_43 ( L_13 ) ;
return - V_101 ;
}
V_32 = F_70 ( V_14 , V_103 ) ;
if ( V_32 )
goto V_104;
V_51 = 0 ;
if ( ! F_161 ( V_2 -> V_4 ) )
V_51 |= V_236 ;
V_32 = F_71 ( V_14 , 4096 , V_51 ) ;
if ( V_32 ) {
V_104:
F_67 ( & V_14 -> V_100 ) ;
return V_32 ;
}
V_2 -> V_81 . V_14 = V_14 ;
}
V_2 -> V_81 . V_82 = F_60 ( V_14 ) ;
V_2 -> V_81 . V_237 = F_72 ( F_65 ( V_14 -> V_98 -> V_99 ) ) ;
memset ( V_2 -> V_81 . V_237 , 0 , V_93 ) ;
F_73 ( L_14 ,
V_2 -> V_87 , V_2 -> V_81 . V_82 ) ;
return 0 ;
}
static int F_162 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_4 -> V_25 ;
if ( ! V_24 -> V_68 ) {
V_24 -> V_68 =
F_163 ( V_2 -> V_4 , V_93 , V_93 ) ;
if ( ! V_24 -> V_68 )
return - V_101 ;
}
V_2 -> V_81 . V_237 = V_24 -> V_68 -> V_238 ;
memset ( V_2 -> V_81 . V_237 , 0 , V_93 ) ;
return 0 ;
}
void F_164 ( struct V_10 * V_11 )
{
F_165 ( V_11 -> V_239 ) ;
V_11 -> V_239 = NULL ;
F_66 ( V_11 -> V_14 ) ;
}
int F_166 ( struct V_3 * V_4 ,
struct V_10 * V_11 )
{
struct V_23 * V_24 = F_45 ( V_4 ) ;
struct V_89 * V_14 = V_11 -> V_14 ;
int V_32 ;
V_32 = F_71 ( V_14 , V_93 , V_236 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_167 ( V_14 , true ) ;
if ( V_32 ) {
F_66 ( V_14 ) ;
return V_32 ;
}
V_11 -> V_239 = F_168 ( V_24 -> V_240 . V_241 +
F_60 ( V_14 ) , V_11 -> V_18 ) ;
if ( V_11 -> V_239 == NULL ) {
F_66 ( V_14 ) ;
return - V_242 ;
}
return 0 ;
}
void F_169 ( struct V_10 * V_11 )
{
F_67 ( & V_11 -> V_14 -> V_100 ) ;
V_11 -> V_14 = NULL ;
}
int F_170 ( struct V_3 * V_4 ,
struct V_10 * V_11 )
{
struct V_89 * V_14 ;
V_14 = NULL ;
if ( ! F_161 ( V_4 ) )
V_14 = F_171 ( V_4 , V_11 -> V_18 ) ;
if ( V_14 == NULL )
V_14 = F_69 ( V_4 , V_11 -> V_18 ) ;
if ( V_14 == NULL )
return - V_101 ;
V_14 -> V_243 = 1 ;
V_11 -> V_14 = V_14 ;
return 0 ;
}
static int F_172 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_32 ;
F_39 ( V_2 -> V_15 ) ;
V_11 = F_173 ( sizeof( * V_11 ) , V_244 ) ;
if ( ! V_11 )
return - V_101 ;
V_2 -> V_15 = V_11 ;
V_2 -> V_4 = V_4 ;
F_174 ( & V_2 -> V_245 ) ;
F_174 ( & V_2 -> V_246 ) ;
F_174 ( & V_2 -> V_247 ) ;
V_11 -> V_18 = 32 * V_93 ;
V_11 -> V_2 = V_2 ;
memset ( V_2 -> V_179 . V_248 , 0 , sizeof( V_2 -> V_179 . V_248 ) ) ;
F_175 ( & V_2 -> V_249 ) ;
if ( F_58 ( V_4 ) ) {
V_32 = F_160 ( V_2 ) ;
if ( V_32 )
goto error;
} else {
F_176 ( V_2 -> V_13 != V_72 ) ;
V_32 = F_162 ( V_2 ) ;
if ( V_32 )
goto error;
}
F_39 ( V_11 -> V_14 ) ;
V_32 = F_170 ( V_4 , V_11 ) ;
if ( V_32 ) {
F_43 ( L_15 ,
V_2 -> V_87 , V_32 ) ;
goto error;
}
V_32 = F_166 ( V_4 , V_11 ) ;
if ( V_32 ) {
F_43 ( L_16 ,
V_2 -> V_87 , V_32 ) ;
F_169 ( V_11 ) ;
goto error;
}
V_11 -> V_250 = V_11 -> V_18 ;
if ( F_177 ( V_4 ) || F_178 ( V_4 ) )
V_11 -> V_250 -= 2 * V_46 ;
V_32 = F_179 ( V_2 ) ;
if ( V_32 )
goto error;
return 0 ;
error:
F_180 ( V_11 ) ;
V_2 -> V_15 = NULL ;
return V_32 ;
}
void F_181 ( struct V_1 * V_2 )
{
struct V_23 * V_24 ;
struct V_10 * V_11 ;
if ( ! F_1 ( V_2 ) )
return;
V_24 = F_45 ( V_2 -> V_4 ) ;
V_11 = V_2 -> V_15 ;
F_182 ( V_2 ) ;
F_39 ( ! F_46 ( V_2 -> V_4 ) && ( F_40 ( V_2 ) & V_84 ) == 0 ) ;
F_164 ( V_11 ) ;
F_169 ( V_11 ) ;
F_183 ( & V_2 -> V_182 , NULL ) ;
if ( V_2 -> V_251 )
V_2 -> V_251 ( V_2 ) ;
F_159 ( V_2 ) ;
F_184 ( V_2 ) ;
F_180 ( V_11 ) ;
V_2 -> V_15 = NULL ;
}
static int F_185 ( struct V_1 * V_2 , int V_252 )
{
struct V_10 * V_11 = V_2 -> V_15 ;
struct V_253 * V_254 ;
int V_32 ;
if ( F_4 ( V_11 ) >= V_252 )
return 0 ;
F_186 (request, &ring->request_list, list) {
if ( F_2 ( V_254 -> V_255 , V_11 -> V_17 ,
V_11 -> V_18 ) >= V_252 ) {
break;
}
}
if ( & V_254 -> V_256 == & V_2 -> V_246 )
return - V_118 ;
V_32 = F_187 ( V_254 ) ;
if ( V_32 )
return V_32 ;
F_188 ( V_2 ) ;
return 0 ;
}
static int F_189 ( struct V_1 * V_2 , int V_252 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_10 * V_11 = V_2 -> V_15 ;
unsigned long V_257 ;
int V_32 ;
V_32 = F_185 ( V_2 , V_252 ) ;
if ( V_32 != - V_118 )
return V_32 ;
F_7 ( V_2 ) ;
V_257 = V_258 + 60 * V_259 ;
V_32 = 0 ;
F_190 ( V_2 ) ;
do {
if ( F_4 ( V_11 ) >= V_252 )
break;
V_11 -> V_16 = F_48 ( V_2 ) ;
if ( F_4 ( V_11 ) >= V_252 )
break;
F_191 ( 1 ) ;
if ( V_24 -> V_260 . V_261 && F_192 ( V_262 ) ) {
V_32 = - V_263 ;
break;
}
V_32 = F_193 ( & V_24 -> V_26 ,
V_24 -> V_260 . V_261 ) ;
if ( V_32 )
break;
if ( F_194 ( V_258 , V_257 ) ) {
V_32 = - V_264 ;
break;
}
} while ( 1 );
F_195 ( V_2 ) ;
return V_32 ;
}
static int F_196 ( struct V_1 * V_2 )
{
T_4 T_5 * V_265 ;
struct V_10 * V_11 = V_2 -> V_15 ;
int V_266 = V_11 -> V_18 - V_11 -> V_17 ;
if ( V_11 -> V_19 < V_266 ) {
int V_32 = F_189 ( V_2 , V_266 ) ;
if ( V_32 )
return V_32 ;
}
V_265 = V_11 -> V_239 + V_11 -> V_17 ;
V_266 /= 4 ;
while ( V_266 -- )
F_197 ( V_38 , V_265 ++ ) ;
V_11 -> V_17 = 0 ;
F_3 ( V_11 ) ;
return 0 ;
}
int F_198 ( struct V_1 * V_2 )
{
struct V_253 * V_267 ;
int V_32 ;
if ( V_2 -> V_182 ) {
V_32 = F_199 ( V_2 ) ;
if ( V_32 )
return V_32 ;
}
if ( F_200 ( & V_2 -> V_246 ) )
return 0 ;
V_267 = F_201 ( V_2 -> V_246 . V_268 ,
struct V_253 ,
V_256 ) ;
return F_187 ( V_267 ) ;
}
static int
F_202 ( struct V_1 * V_2 )
{
int V_32 ;
struct V_253 * V_254 ;
struct V_23 * V_25 = V_2 -> V_4 -> V_25 ;
if ( V_2 -> V_182 )
return 0 ;
V_254 = F_173 ( sizeof( * V_254 ) , V_244 ) ;
if ( V_254 == NULL )
return - V_101 ;
F_203 ( & V_254 -> V_269 ) ;
V_254 -> V_2 = V_2 ;
V_254 -> V_11 = V_2 -> V_15 ;
V_254 -> V_270 = V_25 -> V_271 ++ ;
V_32 = F_204 ( V_2 -> V_4 , & V_254 -> V_178 ) ;
if ( V_32 ) {
F_180 ( V_254 ) ;
return V_32 ;
}
V_2 -> V_182 = V_254 ;
return 0 ;
}
static int F_205 ( struct V_1 * V_2 ,
int V_272 )
{
struct V_10 * V_11 = V_2 -> V_15 ;
int V_32 ;
if ( F_206 ( V_11 -> V_17 + V_272 > V_11 -> V_250 ) ) {
V_32 = F_196 ( V_2 ) ;
if ( F_206 ( V_32 ) )
return V_32 ;
}
if ( F_206 ( V_11 -> V_19 < V_272 ) ) {
V_32 = F_189 ( V_2 , V_272 ) ;
if ( F_206 ( V_32 ) )
return V_32 ;
}
return 0 ;
}
int F_9 ( struct V_1 * V_2 ,
int V_174 )
{
struct V_23 * V_24 = V_2 -> V_4 -> V_25 ;
int V_32 ;
V_32 = F_193 ( & V_24 -> V_26 ,
V_24 -> V_260 . V_261 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_205 ( V_2 , V_174 * sizeof( T_4 ) ) ;
if ( V_32 )
return V_32 ;
V_32 = F_202 ( V_2 ) ;
if ( V_32 )
return V_32 ;
V_2 -> V_15 -> V_19 -= V_174 * sizeof( T_4 ) ;
return 0 ;
}
int F_207 ( struct V_1 * V_2 )
{
int V_174 = ( V_2 -> V_15 -> V_17 & ( V_46 - 1 ) ) / sizeof( T_4 ) ;
int V_32 ;
if ( V_174 == 0 )
return 0 ;
V_174 = V_46 / sizeof( T_4 ) - V_174 ;
V_32 = F_9 ( V_2 , V_174 ) ;
if ( V_32 )
return V_32 ;
while ( V_174 -- )
F_10 ( V_2 , V_38 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
void F_208 ( struct V_1 * V_2 , T_1 V_178 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
F_176 ( V_2 -> V_182 ) ;
if ( F_25 ( V_4 ) -> V_64 == 6 || F_25 ( V_4 ) -> V_64 == 7 ) {
F_31 ( F_209 ( V_2 -> V_65 ) , 0 ) ;
F_31 ( F_210 ( V_2 -> V_65 ) , 0 ) ;
if ( F_211 ( V_4 ) )
F_31 ( F_212 ( V_2 -> V_65 ) , 0 ) ;
}
V_2 -> V_273 ( V_2 , V_178 ) ;
V_2 -> V_97 . V_178 = V_178 ;
}
static void F_213 ( struct V_1 * V_2 ,
T_1 V_62 )
{
struct V_23 * V_24 = V_2 -> V_4 -> V_25 ;
F_31 ( V_274 ,
F_41 ( V_275 ) ) ;
F_214 ( V_276 , 0x0 ) ;
if ( F_42 ( ( F_29 ( V_274 ) &
V_277 ) == 0 ,
50 ) )
F_43 ( L_17 ) ;
F_23 ( V_2 , V_62 ) ;
F_37 ( F_215 ( V_2 -> V_65 ) ) ;
F_31 ( V_274 ,
F_53 ( V_275 ) ) ;
}
static int F_216 ( struct V_1 * V_2 ,
T_1 V_278 , T_1 V_279 )
{
T_4 V_31 ;
int V_32 ;
V_32 = F_9 ( V_2 , 4 ) ;
if ( V_32 )
return V_32 ;
V_31 = V_185 ;
if ( F_25 ( V_2 -> V_4 ) -> V_64 >= 8 )
V_31 += 1 ;
V_31 |= V_280 | V_186 ;
if ( V_278 & V_281 )
V_31 |= V_282 | V_283 ;
F_10 ( V_2 , V_31 ) ;
F_10 ( V_2 , V_284 | V_187 ) ;
if ( F_25 ( V_2 -> V_4 ) -> V_64 >= 8 ) {
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 ) ;
} else {
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , V_38 ) ;
}
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_217 ( struct V_1 * V_2 ,
T_2 V_216 , T_1 V_223 ,
unsigned V_218 )
{
bool V_285 = F_218 ( V_2 -> V_4 ) &&
! ( V_218 & V_221 ) ;
int V_32 ;
V_32 = F_9 ( V_2 , 4 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , V_286 | ( V_285 << 8 ) ) ;
F_10 ( V_2 , F_110 ( V_216 ) ) ;
F_10 ( V_2 , F_111 ( V_216 ) ) ;
F_10 ( V_2 , V_38 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_219 ( struct V_1 * V_2 ,
T_2 V_216 , T_1 V_223 ,
unsigned V_218 )
{
int V_32 ;
V_32 = F_9 ( V_2 , 2 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 ,
V_219 |
( V_218 & V_221 ?
0 : V_287 | V_288 ) ) ;
F_10 ( V_2 , V_216 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_220 ( struct V_1 * V_2 ,
T_2 V_216 , T_1 V_223 ,
unsigned V_218 )
{
int V_32 ;
V_32 = F_9 ( V_2 , 2 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 ,
V_219 |
( V_218 & V_221 ?
0 : V_222 ) ) ;
F_10 ( V_2 , V_216 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int F_221 ( struct V_1 * V_2 ,
T_1 V_278 , T_1 V_279 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_4 V_31 ;
int V_32 ;
V_32 = F_9 ( V_2 , 4 ) ;
if ( V_32 )
return V_32 ;
V_31 = V_185 ;
if ( F_25 ( V_4 ) -> V_64 >= 8 )
V_31 += 1 ;
V_31 |= V_280 | V_186 ;
if ( V_278 & V_34 )
V_31 |= V_282 ;
F_10 ( V_2 , V_31 ) ;
F_10 ( V_2 , V_284 | V_187 ) ;
if ( F_25 ( V_4 ) -> V_64 >= 8 ) {
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 ) ;
} else {
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , V_38 ) ;
}
F_11 ( V_2 ) ;
return 0 ;
}
int F_222 ( struct V_3 * V_4 )
{
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_2 = & V_24 -> V_2 [ V_72 ] ;
struct V_89 * V_14 ;
int V_32 ;
V_2 -> V_87 = L_18 ;
V_2 -> V_13 = V_72 ;
V_2 -> V_65 = V_289 ;
if ( F_25 ( V_4 ) -> V_64 >= 8 ) {
if ( F_223 ( V_4 ) ) {
V_14 = F_69 ( V_4 , 4096 ) ;
if ( V_14 == NULL ) {
F_43 ( L_19 ) ;
V_5 . V_290 = 0 ;
} else {
F_70 ( V_14 , V_103 ) ;
V_32 = F_71 ( V_14 , 0 , V_291 ) ;
if ( V_32 != 0 ) {
F_67 ( & V_14 -> V_100 ) ;
F_43 ( L_20 ) ;
V_5 . V_290 = 0 ;
} else
V_24 -> V_172 = V_14 ;
}
}
V_2 -> V_292 = F_78 ;
V_2 -> V_293 = F_116 ;
V_2 -> V_279 = F_21 ;
V_2 -> V_294 = F_152 ;
V_2 -> V_295 = F_154 ;
V_2 -> V_212 = V_296 ;
V_2 -> V_297 = F_124 ;
V_2 -> V_273 = F_127 ;
if ( F_223 ( V_4 ) ) {
F_39 ( ! V_24 -> V_172 ) ;
V_2 -> V_179 . V_298 = F_118 ;
V_2 -> V_179 . signal = F_105 ;
V_299 ;
}
} else if ( F_25 ( V_4 ) -> V_64 >= 6 ) {
V_2 -> V_293 = F_116 ;
V_2 -> V_279 = F_19 ;
if ( F_25 ( V_4 ) -> V_64 == 6 )
V_2 -> V_279 = F_17 ;
V_2 -> V_294 = F_146 ;
V_2 -> V_295 = F_147 ;
V_2 -> V_212 = V_296 ;
V_2 -> V_297 = F_124 ;
V_2 -> V_273 = F_127 ;
if ( F_223 ( V_4 ) ) {
V_2 -> V_179 . V_298 = F_120 ;
V_2 -> V_179 . signal = F_114 ;
V_2 -> V_179 . V_190 . V_206 [ V_72 ] = V_181 ;
V_2 -> V_179 . V_190 . V_206 [ V_77 ] = V_300 ;
V_2 -> V_179 . V_190 . V_206 [ V_74 ] = V_301 ;
V_2 -> V_179 . V_190 . V_206 [ V_79 ] = V_302 ;
V_2 -> V_179 . V_190 . V_206 [ V_76 ] = V_181 ;
V_2 -> V_179 . V_190 . signal [ V_72 ] = V_191 ;
V_2 -> V_179 . V_190 . signal [ V_77 ] = V_303 ;
V_2 -> V_179 . V_190 . signal [ V_74 ] = V_304 ;
V_2 -> V_179 . V_190 . signal [ V_79 ] = V_305 ;
V_2 -> V_179 . V_190 . signal [ V_76 ] = V_191 ;
}
} else if ( F_14 ( V_4 ) ) {
V_2 -> V_293 = F_122 ;
V_2 -> V_279 = F_12 ;
V_2 -> V_297 = F_129 ;
V_2 -> V_273 = F_130 ;
V_2 -> V_294 = F_131 ;
V_2 -> V_295 = F_136 ;
V_2 -> V_212 = V_296 |
V_306 ;
} else {
V_2 -> V_293 = F_145 ;
if ( F_25 ( V_4 ) -> V_64 < 4 )
V_2 -> V_279 = F_8 ;
else
V_2 -> V_279 = F_12 ;
V_2 -> V_297 = F_126 ;
V_2 -> V_273 = F_127 ;
if ( F_46 ( V_4 ) ) {
V_2 -> V_294 = F_140 ;
V_2 -> V_295 = F_143 ;
} else {
V_2 -> V_294 = F_138 ;
V_2 -> V_295 = F_139 ;
}
V_2 -> V_212 = V_307 ;
}
V_2 -> V_28 = F_22 ;
if ( F_224 ( V_4 ) )
V_2 -> V_308 = F_219 ;
else if ( F_225 ( V_4 ) )
V_2 -> V_308 = F_217 ;
else if ( F_25 ( V_4 ) -> V_64 >= 6 )
V_2 -> V_308 = F_220 ;
else if ( F_25 ( V_4 ) -> V_64 >= 4 )
V_2 -> V_308 = F_155 ;
else if ( F_177 ( V_4 ) || F_178 ( V_4 ) )
V_2 -> V_308 = F_156 ;
else
V_2 -> V_308 = F_158 ;
V_2 -> V_309 = F_100 ;
V_2 -> V_251 = F_104 ;
if ( F_226 ( V_4 ) ) {
V_14 = F_69 ( V_4 , V_310 ) ;
if ( V_14 == NULL ) {
F_43 ( L_21 ) ;
return - V_101 ;
}
V_32 = F_71 ( V_14 , 0 , 0 ) ;
if ( V_32 != 0 ) {
F_67 ( & V_14 -> V_100 ) ;
F_43 ( L_22 ) ;
return V_32 ;
}
V_2 -> V_44 . V_14 = V_14 ;
V_2 -> V_44 . V_45 = F_60 ( V_14 ) ;
}
V_32 = F_172 ( V_4 , V_2 ) ;
if ( V_32 )
return V_32 ;
if ( F_25 ( V_4 ) -> V_64 >= 5 ) {
V_32 = F_68 ( V_2 ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
int F_227 ( struct V_3 * V_4 )
{
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_2 = & V_24 -> V_2 [ V_77 ] ;
V_2 -> V_87 = L_23 ;
V_2 -> V_13 = V_77 ;
V_2 -> V_28 = F_22 ;
if ( F_25 ( V_4 ) -> V_64 >= 6 ) {
V_2 -> V_65 = V_311 ;
if ( F_34 ( V_4 ) )
V_2 -> V_28 = F_213 ;
V_2 -> V_279 = F_216 ;
V_2 -> V_293 = F_116 ;
V_2 -> V_297 = F_124 ;
V_2 -> V_273 = F_127 ;
if ( F_25 ( V_4 ) -> V_64 >= 8 ) {
V_2 -> V_212 =
V_296 << V_312 ;
V_2 -> V_294 = F_152 ;
V_2 -> V_295 = F_154 ;
V_2 -> V_308 =
F_217 ;
if ( F_223 ( V_4 ) ) {
V_2 -> V_179 . V_298 = F_118 ;
V_2 -> V_179 . signal = F_113 ;
V_299 ;
}
} else {
V_2 -> V_212 = V_313 ;
V_2 -> V_294 = F_146 ;
V_2 -> V_295 = F_147 ;
V_2 -> V_308 =
F_220 ;
if ( F_223 ( V_4 ) ) {
V_2 -> V_179 . V_298 = F_120 ;
V_2 -> V_179 . signal = F_114 ;
V_2 -> V_179 . V_190 . V_206 [ V_72 ] = V_314 ;
V_2 -> V_179 . V_190 . V_206 [ V_77 ] = V_181 ;
V_2 -> V_179 . V_190 . V_206 [ V_74 ] = V_315 ;
V_2 -> V_179 . V_190 . V_206 [ V_79 ] = V_316 ;
V_2 -> V_179 . V_190 . V_206 [ V_76 ] = V_181 ;
V_2 -> V_179 . V_190 . signal [ V_72 ] = V_317 ;
V_2 -> V_179 . V_190 . signal [ V_77 ] = V_191 ;
V_2 -> V_179 . V_190 . signal [ V_74 ] = V_318 ;
V_2 -> V_179 . V_190 . signal [ V_79 ] = V_319 ;
V_2 -> V_179 . V_190 . signal [ V_76 ] = V_191 ;
}
}
} else {
V_2 -> V_65 = V_320 ;
V_2 -> V_279 = F_144 ;
V_2 -> V_293 = F_145 ;
V_2 -> V_297 = F_126 ;
V_2 -> V_273 = F_127 ;
if ( F_14 ( V_4 ) ) {
V_2 -> V_212 = V_321 ;
V_2 -> V_294 = F_131 ;
V_2 -> V_295 = F_136 ;
} else {
V_2 -> V_212 = V_322 ;
V_2 -> V_294 = F_138 ;
V_2 -> V_295 = F_139 ;
}
V_2 -> V_308 = F_155 ;
}
V_2 -> V_309 = F_54 ;
return F_172 ( V_4 , V_2 ) ;
}
int F_228 ( struct V_3 * V_4 )
{
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_2 = & V_24 -> V_2 [ V_76 ] ;
V_2 -> V_87 = L_24 ;
V_2 -> V_13 = V_76 ;
V_2 -> V_28 = F_22 ;
V_2 -> V_65 = V_323 ;
V_2 -> V_279 = F_216 ;
V_2 -> V_293 = F_116 ;
V_2 -> V_297 = F_124 ;
V_2 -> V_273 = F_127 ;
V_2 -> V_212 =
V_296 << V_324 ;
V_2 -> V_294 = F_152 ;
V_2 -> V_295 = F_154 ;
V_2 -> V_308 =
F_217 ;
if ( F_223 ( V_4 ) ) {
V_2 -> V_179 . V_298 = F_118 ;
V_2 -> V_179 . signal = F_113 ;
V_299 ;
}
V_2 -> V_309 = F_54 ;
return F_172 ( V_4 , V_2 ) ;
}
int F_229 ( struct V_3 * V_4 )
{
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_2 = & V_24 -> V_2 [ V_74 ] ;
V_2 -> V_87 = L_25 ;
V_2 -> V_13 = V_74 ;
V_2 -> V_65 = V_325 ;
V_2 -> V_28 = F_22 ;
V_2 -> V_279 = F_221 ;
V_2 -> V_293 = F_116 ;
V_2 -> V_297 = F_124 ;
V_2 -> V_273 = F_127 ;
if ( F_25 ( V_4 ) -> V_64 >= 8 ) {
V_2 -> V_212 =
V_296 << V_326 ;
V_2 -> V_294 = F_152 ;
V_2 -> V_295 = F_154 ;
V_2 -> V_308 = F_217 ;
if ( F_223 ( V_4 ) ) {
V_2 -> V_179 . V_298 = F_118 ;
V_2 -> V_179 . signal = F_113 ;
V_299 ;
}
} else {
V_2 -> V_212 = V_327 ;
V_2 -> V_294 = F_146 ;
V_2 -> V_295 = F_147 ;
V_2 -> V_308 = F_220 ;
if ( F_223 ( V_4 ) ) {
V_2 -> V_179 . signal = F_114 ;
V_2 -> V_179 . V_298 = F_120 ;
V_2 -> V_179 . V_190 . V_206 [ V_72 ] = V_328 ;
V_2 -> V_179 . V_190 . V_206 [ V_77 ] = V_329 ;
V_2 -> V_179 . V_190 . V_206 [ V_74 ] = V_181 ;
V_2 -> V_179 . V_190 . V_206 [ V_79 ] = V_330 ;
V_2 -> V_179 . V_190 . V_206 [ V_76 ] = V_181 ;
V_2 -> V_179 . V_190 . signal [ V_72 ] = V_331 ;
V_2 -> V_179 . V_190 . signal [ V_77 ] = V_332 ;
V_2 -> V_179 . V_190 . signal [ V_74 ] = V_191 ;
V_2 -> V_179 . V_190 . signal [ V_79 ] = V_333 ;
V_2 -> V_179 . V_190 . signal [ V_76 ] = V_191 ;
}
}
V_2 -> V_309 = F_54 ;
return F_172 ( V_4 , V_2 ) ;
}
int F_230 ( struct V_3 * V_4 )
{
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_2 = & V_24 -> V_2 [ V_79 ] ;
V_2 -> V_87 = L_26 ;
V_2 -> V_13 = V_79 ;
V_2 -> V_65 = V_334 ;
V_2 -> V_28 = F_22 ;
V_2 -> V_279 = F_221 ;
V_2 -> V_293 = F_116 ;
V_2 -> V_297 = F_124 ;
V_2 -> V_273 = F_127 ;
if ( F_25 ( V_4 ) -> V_64 >= 8 ) {
V_2 -> V_212 =
V_296 << V_335 ;
V_2 -> V_294 = F_152 ;
V_2 -> V_295 = F_154 ;
V_2 -> V_308 = F_217 ;
if ( F_223 ( V_4 ) ) {
V_2 -> V_179 . V_298 = F_118 ;
V_2 -> V_179 . signal = F_113 ;
V_299 ;
}
} else {
V_2 -> V_212 = V_336 ;
V_2 -> V_294 = F_148 ;
V_2 -> V_295 = F_150 ;
V_2 -> V_308 = F_220 ;
if ( F_223 ( V_4 ) ) {
V_2 -> V_179 . V_298 = F_120 ;
V_2 -> V_179 . signal = F_114 ;
V_2 -> V_179 . V_190 . V_206 [ V_72 ] = V_337 ;
V_2 -> V_179 . V_190 . V_206 [ V_77 ] = V_338 ;
V_2 -> V_179 . V_190 . V_206 [ V_74 ] = V_339 ;
V_2 -> V_179 . V_190 . V_206 [ V_79 ] = V_181 ;
V_2 -> V_179 . V_190 . V_206 [ V_76 ] = V_181 ;
V_2 -> V_179 . V_190 . signal [ V_72 ] = V_340 ;
V_2 -> V_179 . V_190 . signal [ V_77 ] = V_341 ;
V_2 -> V_179 . V_190 . signal [ V_74 ] = V_342 ;
V_2 -> V_179 . V_190 . signal [ V_79 ] = V_191 ;
V_2 -> V_179 . V_190 . signal [ V_76 ] = V_191 ;
}
}
V_2 -> V_309 = F_54 ;
return F_172 ( V_4 , V_2 ) ;
}
int
F_76 ( struct V_1 * V_2 )
{
int V_32 ;
if ( ! V_2 -> V_113 )
return 0 ;
V_32 = V_2 -> V_279 ( V_2 , 0 , V_281 ) ;
if ( V_32 )
return V_32 ;
F_231 ( V_2 , 0 , V_281 ) ;
V_2 -> V_113 = false ;
return 0 ;
}
int
F_232 ( struct V_1 * V_2 )
{
T_4 V_30 ;
int V_32 ;
V_30 = 0 ;
if ( V_2 -> V_113 )
V_30 = V_281 ;
V_32 = V_2 -> V_279 ( V_2 , V_281 , V_30 ) ;
if ( V_32 )
return V_32 ;
F_231 ( V_2 , V_281 , V_30 ) ;
V_2 -> V_113 = false ;
return 0 ;
}
void
F_182 ( struct V_1 * V_2 )
{
int V_32 ;
if ( ! F_1 ( V_2 ) )
return;
V_32 = F_198 ( V_2 ) ;
if ( V_32 && ! F_233 ( & F_45 ( V_2 -> V_4 ) -> V_26 ) )
F_43 ( L_27 ,
V_2 -> V_87 , V_32 ) ;
F_44 ( V_2 ) ;
}
