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
static void F_7 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_15 ;
V_11 -> V_17 &= V_11 -> V_18 - 1 ;
if ( F_5 ( V_2 ) )
return;
V_2 -> V_28 ( V_2 , V_11 -> V_17 ) ;
}
static int
F_8 ( struct V_29 * V_30 ,
T_1 V_31 ,
T_1 V_32 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
T_1 V_33 ;
int V_34 ;
V_33 = V_35 ;
if ( ( ( V_31 | V_32 ) & V_36 ) == 0 )
V_33 |= V_37 ;
if ( V_31 & V_38 )
V_33 |= V_39 ;
V_34 = F_9 ( V_30 , 2 ) ;
if ( V_34 )
return V_34 ;
F_10 ( V_2 , V_33 ) ;
F_10 ( V_2 , V_40 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_12 ( struct V_29 * V_30 ,
T_1 V_31 ,
T_1 V_32 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_33 ;
int V_34 ;
V_33 = V_35 | V_37 ;
if ( ( V_31 | V_32 ) & V_36 )
V_33 &= ~ V_37 ;
if ( V_31 & V_41 )
V_33 |= V_42 ;
if ( V_31 & V_43 &&
( F_13 ( V_4 ) || F_14 ( V_4 ) ) )
V_33 |= V_44 ;
V_34 = F_9 ( V_30 , 2 ) ;
if ( V_34 )
return V_34 ;
F_10 ( V_2 , V_33 ) ;
F_10 ( V_2 , V_40 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_15 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
T_1 V_45 = V_2 -> V_46 . V_47 + 2 * V_48 ;
int V_34 ;
V_34 = F_9 ( V_30 , 6 ) ;
if ( V_34 )
return V_34 ;
F_10 ( V_2 , F_16 ( 5 ) ) ;
F_10 ( V_2 , V_49 |
V_50 ) ;
F_10 ( V_2 , V_45 | V_51 ) ;
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , V_40 ) ;
F_11 ( V_2 ) ;
V_34 = F_9 ( V_30 , 6 ) ;
if ( V_34 )
return V_34 ;
F_10 ( V_2 , F_16 ( 5 ) ) ;
F_10 ( V_2 , V_52 ) ;
F_10 ( V_2 , V_45 | V_51 ) ;
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , V_40 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_17 ( struct V_29 * V_30 ,
T_1 V_31 , T_1 V_32 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
T_1 V_53 = 0 ;
T_1 V_45 = V_2 -> V_46 . V_47 + 2 * V_48 ;
int V_34 ;
V_34 = F_15 ( V_30 ) ;
if ( V_34 )
return V_34 ;
if ( V_32 ) {
V_53 |= V_54 ;
V_53 |= V_55 ;
V_53 |= V_49 ;
}
if ( V_31 ) {
V_53 |= V_56 ;
V_53 |= V_57 ;
V_53 |= V_58 ;
V_53 |= V_59 ;
V_53 |= V_60 ;
V_53 |= V_61 ;
V_53 |= V_52 | V_49 ;
}
V_34 = F_9 ( V_30 , 4 ) ;
if ( V_34 )
return V_34 ;
F_10 ( V_2 , F_16 ( 4 ) ) ;
F_10 ( V_2 , V_53 ) ;
F_10 ( V_2 , V_45 | V_51 ) ;
F_10 ( V_2 , 0 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_18 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
int V_34 ;
V_34 = F_9 ( V_30 , 4 ) ;
if ( V_34 )
return V_34 ;
F_10 ( V_2 , F_16 ( 4 ) ) ;
F_10 ( V_2 , V_49 |
V_50 ) ;
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_19 ( struct V_29 * V_30 ,
T_1 V_31 , T_1 V_32 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
T_1 V_53 = 0 ;
T_1 V_45 = V_2 -> V_46 . V_47 + 2 * V_48 ;
int V_34 ;
V_53 |= V_49 ;
if ( V_32 ) {
V_53 |= V_54 ;
V_53 |= V_55 ;
V_53 |= V_62 ;
}
if ( V_31 ) {
V_53 |= V_56 ;
V_53 |= V_57 ;
V_53 |= V_58 ;
V_53 |= V_59 ;
V_53 |= V_60 ;
V_53 |= V_61 ;
V_53 |= V_63 ;
V_53 |= V_52 ;
V_53 |= V_64 ;
V_53 |= V_50 ;
F_18 ( V_30 ) ;
}
V_34 = F_9 ( V_30 , 4 ) ;
if ( V_34 )
return V_34 ;
F_10 ( V_2 , F_16 ( 4 ) ) ;
F_10 ( V_2 , V_53 ) ;
F_10 ( V_2 , V_45 ) ;
F_10 ( V_2 , 0 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_20 ( struct V_29 * V_30 ,
T_1 V_53 , T_1 V_45 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
int V_34 ;
V_34 = F_9 ( V_30 , 6 ) ;
if ( V_34 )
return V_34 ;
F_10 ( V_2 , F_16 ( 6 ) ) ;
F_10 ( V_2 , V_53 ) ;
F_10 ( V_2 , V_45 ) ;
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_21 ( struct V_29 * V_30 ,
T_1 V_31 , T_1 V_32 )
{
T_1 V_53 = 0 ;
T_1 V_45 = V_30 -> V_2 -> V_46 . V_47 + 2 * V_48 ;
int V_34 ;
V_53 |= V_49 ;
if ( V_32 ) {
V_53 |= V_54 ;
V_53 |= V_55 ;
V_53 |= V_62 ;
}
if ( V_31 ) {
V_53 |= V_56 ;
V_53 |= V_57 ;
V_53 |= V_58 ;
V_53 |= V_59 ;
V_53 |= V_60 ;
V_53 |= V_61 ;
V_53 |= V_52 ;
V_53 |= V_64 ;
V_34 = F_20 ( V_30 ,
V_49 |
V_50 ,
0 ) ;
if ( V_34 )
return V_34 ;
}
return F_20 ( V_30 , V_53 , V_45 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
T_1 V_65 )
{
struct V_23 * V_24 = V_2 -> V_4 -> V_25 ;
F_23 ( V_2 , V_65 ) ;
}
T_2 F_24 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_4 -> V_25 ;
T_2 V_66 ;
if ( F_25 ( V_2 -> V_4 ) -> V_67 >= 8 )
V_66 = F_26 ( F_27 ( V_2 -> V_68 ) ,
F_28 ( V_2 -> V_68 ) ) ;
else if ( F_25 ( V_2 -> V_4 ) -> V_67 >= 4 )
V_66 = F_29 ( F_27 ( V_2 -> V_68 ) ) ;
else
V_66 = F_29 ( V_69 ) ;
return V_66 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_4 -> V_25 ;
T_1 V_70 ;
V_70 = V_24 -> V_71 -> V_72 ;
if ( F_25 ( V_2 -> V_4 ) -> V_67 >= 4 )
V_70 |= ( V_24 -> V_71 -> V_72 >> 28 ) & 0xf0 ;
F_31 ( V_73 , V_70 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_2 -> V_4 -> V_25 ;
T_1 V_74 = 0 ;
if ( F_33 ( V_4 ) ) {
switch ( V_2 -> V_13 ) {
case V_75 :
V_74 = V_76 ;
break;
case V_77 :
V_74 = V_78 ;
break;
case V_79 :
case V_80 :
V_74 = V_81 ;
break;
case V_82 :
V_74 = V_83 ;
break;
}
} else if ( F_34 ( V_2 -> V_4 ) ) {
V_74 = F_35 ( V_2 -> V_68 ) ;
} else {
V_74 = F_36 ( V_2 -> V_68 ) ;
}
F_31 ( V_74 , ( T_1 ) V_2 -> V_84 . V_85 ) ;
F_37 ( V_74 ) ;
if ( F_25 ( V_4 ) -> V_67 >= 6 && F_25 ( V_4 ) -> V_67 < 8 ) {
T_1 V_86 = F_38 ( V_2 -> V_68 ) ;
F_39 ( ( F_40 ( V_2 ) & V_87 ) == 0 ) ;
F_31 ( V_86 ,
F_41 ( V_88 |
V_89 ) ) ;
if ( F_42 ( ( F_29 ( V_86 ) & V_89 ) == 0 ,
1000 ) )
F_43 ( L_1 ,
V_2 -> V_90 ) ;
}
}
static bool F_44 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_45 ( V_2 -> V_4 ) ;
if ( ! F_46 ( V_2 -> V_4 ) ) {
F_47 ( V_2 , F_41 ( V_91 ) ) ;
if ( F_42 ( ( F_40 ( V_2 ) & V_87 ) != 0 , 1000 ) ) {
F_43 ( L_2 , V_2 -> V_90 ) ;
if ( F_48 ( V_2 ) != F_49 ( V_2 ) )
return false ;
}
}
F_50 ( V_2 , 0 ) ;
F_51 ( V_2 , 0 ) ;
V_2 -> V_28 ( V_2 , 0 ) ;
if ( ! F_46 ( V_2 -> V_4 ) ) {
( void ) F_52 ( V_2 ) ;
F_47 ( V_2 , F_53 ( V_91 ) ) ;
}
return ( F_48 ( V_2 ) & V_22 ) == 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_10 * V_11 = V_2 -> V_15 ;
struct V_92 * V_14 = V_11 -> V_14 ;
int V_34 = 0 ;
F_55 ( V_24 , V_93 ) ;
if ( ! F_44 ( V_2 ) ) {
F_56 ( L_3
L_4 ,
V_2 -> V_90 ,
F_52 ( V_2 ) ,
F_48 ( V_2 ) ,
F_49 ( V_2 ) ,
F_57 ( V_2 ) ) ;
if ( ! F_44 ( V_2 ) ) {
F_43 ( L_5
L_4 ,
V_2 -> V_90 ,
F_52 ( V_2 ) ,
F_48 ( V_2 ) ,
F_49 ( V_2 ) ,
F_57 ( V_2 ) ) ;
V_34 = - V_94 ;
goto V_95;
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
V_2 -> V_90 , F_48 ( V_2 ) ) ;
F_51 ( V_2 , 0 ) ;
( void ) F_48 ( V_2 ) ;
F_50 ( V_2 ,
( ( V_11 -> V_18 - V_96 ) & V_97 )
| V_98 ) ;
if ( F_42 ( ( F_52 ( V_2 ) & V_98 ) != 0 &&
F_57 ( V_2 ) == F_60 ( V_14 ) &&
( F_48 ( V_2 ) & V_22 ) == 0 , 50 ) ) {
F_43 ( L_7
L_8 ,
V_2 -> V_90 ,
F_52 ( V_2 ) , F_52 ( V_2 ) & V_98 ,
F_48 ( V_2 ) , F_49 ( V_2 ) ,
F_57 ( V_2 ) , ( unsigned long ) F_60 ( V_14 ) ) ;
V_34 = - V_94 ;
goto V_95;
}
V_11 -> V_21 = - 1 ;
V_11 -> V_16 = F_48 ( V_2 ) ;
V_11 -> V_17 = F_49 ( V_2 ) & V_99 ;
F_3 ( V_11 ) ;
memset ( & V_2 -> V_100 , 0 , sizeof( V_2 -> V_100 ) ) ;
V_95:
F_62 ( V_24 , V_93 ) ;
return V_34 ;
}
void
F_63 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 -> V_46 . V_14 == NULL )
return;
if ( F_25 ( V_4 ) -> V_67 >= 5 ) {
F_64 ( F_65 ( V_2 -> V_46 . V_14 -> V_101 -> V_102 ) ) ;
F_66 ( V_2 -> V_46 . V_14 ) ;
}
F_67 ( & V_2 -> V_46 . V_14 -> V_103 ) ;
V_2 -> V_46 . V_14 = NULL ;
}
int
F_68 ( struct V_1 * V_2 )
{
int V_34 ;
F_39 ( V_2 -> V_46 . V_14 ) ;
V_2 -> V_46 . V_14 = F_69 ( V_2 -> V_4 , 4096 ) ;
if ( V_2 -> V_46 . V_14 == NULL ) {
F_43 ( L_9 ) ;
V_34 = - V_104 ;
goto V_105;
}
V_34 = F_70 ( V_2 -> V_46 . V_14 , V_106 ) ;
if ( V_34 )
goto V_107;
V_34 = F_71 ( V_2 -> V_46 . V_14 , 4096 , 0 ) ;
if ( V_34 )
goto V_107;
V_2 -> V_46 . V_47 = F_60 ( V_2 -> V_46 . V_14 ) ;
V_2 -> V_46 . V_108 = F_72 ( F_65 ( V_2 -> V_46 . V_14 -> V_101 -> V_102 ) ) ;
if ( V_2 -> V_46 . V_108 == NULL ) {
V_34 = - V_104 ;
goto V_109;
}
F_73 ( L_10 ,
V_2 -> V_90 , V_2 -> V_46 . V_47 ) ;
return 0 ;
V_109:
F_66 ( V_2 -> V_46 . V_14 ) ;
V_107:
F_67 ( & V_2 -> V_46 . V_14 -> V_103 ) ;
V_105:
return V_34 ;
}
static int F_74 ( struct V_29 * V_30 )
{
int V_34 , V_110 ;
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_111 * V_112 = & V_24 -> V_113 ;
if ( F_75 ( V_112 -> V_114 == 0 ) )
return 0 ;
V_2 -> V_115 = true ;
V_34 = F_76 ( V_30 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_9 ( V_30 , ( V_112 -> V_114 * 2 + 2 ) ) ;
if ( V_34 )
return V_34 ;
F_10 ( V_2 , F_77 ( V_112 -> V_114 ) ) ;
for ( V_110 = 0 ; V_110 < V_112 -> V_114 ; V_110 ++ ) {
F_10 ( V_2 , V_112 -> V_86 [ V_110 ] . V_70 ) ;
F_10 ( V_2 , V_112 -> V_86 [ V_110 ] . V_65 ) ;
}
F_10 ( V_2 , V_40 ) ;
F_11 ( V_2 ) ;
V_2 -> V_115 = true ;
V_34 = F_76 ( V_30 ) ;
if ( V_34 )
return V_34 ;
F_73 ( L_11 , V_112 -> V_114 ) ;
return 0 ;
}
static int F_78 ( struct V_29 * V_30 )
{
int V_34 ;
V_34 = F_74 ( V_30 ) ;
if ( V_34 != 0 )
return V_34 ;
V_34 = F_79 ( V_30 ) ;
if ( V_34 )
F_43 ( L_12 , V_34 ) ;
return V_34 ;
}
static int F_80 ( struct V_23 * V_24 ,
const T_1 V_70 , const T_1 V_116 , const T_1 V_117 )
{
const T_1 V_118 = V_24 -> V_113 . V_114 ;
if ( F_39 ( V_118 >= V_119 ) )
return - V_120 ;
V_24 -> V_113 . V_86 [ V_118 ] . V_70 = V_70 ;
V_24 -> V_113 . V_86 [ V_118 ] . V_65 = V_117 ;
V_24 -> V_113 . V_86 [ V_118 ] . V_116 = V_116 ;
V_24 -> V_113 . V_114 ++ ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
F_82 ( V_121 , V_122 ) ;
F_82 ( V_123 , V_124 ) ;
F_82 ( V_125 ,
V_126 |
V_127 ) ;
F_82 ( V_128 ,
V_129 ) ;
F_82 ( V_130 ,
V_131 ) ;
F_82 ( V_132 ,
V_133 |
V_134 |
V_135 |
( F_83 ( V_4 ) ? V_136 : 0 ) ) ;
F_84 ( V_137 , V_138 ) ;
F_82 ( V_139 ,
V_140 ) ;
F_85 ( V_141 ,
V_142 ,
V_143 ) ;
return 0 ;
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
F_82 ( V_121 , V_122 ) ;
F_82 ( V_123 , V_124 ) ;
F_82 ( V_125 ,
V_126 |
V_127 ) ;
F_82 ( V_132 ,
V_133 |
V_135 ) ;
F_84 ( V_137 , V_138 ) ;
F_82 ( V_139 ,
V_140 ) ;
F_82 ( V_144 , V_145 ) ;
F_85 ( V_141 ,
V_142 ,
V_143 ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
T_3 V_146 ;
F_82 ( V_125 ,
V_126 ) ;
F_82 ( V_130 ,
V_147 ) ;
if ( ( F_88 ( V_4 ) && ( F_89 ( V_4 ) == V_148 ||
F_89 ( V_4 ) == V_149 ) ) ||
( F_90 ( V_4 ) && F_89 ( V_4 ) < V_150 ) ) {
F_84 ( V_151 ,
V_152 ) ;
}
if ( ( F_88 ( V_4 ) && F_89 ( V_4 ) <= V_149 ) ||
( F_90 ( V_4 ) && F_89 ( V_4 ) < V_150 ) ) {
F_82 ( V_153 ,
V_154 ) ;
}
if ( ( F_88 ( V_4 ) && F_89 ( V_4 ) >= V_155 ) ||
F_90 ( V_4 ) ) {
F_82 ( V_156 ,
V_157 ) ;
}
F_82 ( V_139 , V_140 ) ;
F_82 ( V_139 , V_158 ) ;
F_84 ( V_151 ,
V_159 ) ;
if ( ( F_88 ( V_4 ) && F_89 ( V_4 ) == V_155 ) ||
( F_90 ( V_4 ) && F_89 ( V_4 ) < V_150 ) )
F_82 ( V_160 ,
V_161 ) ;
V_146 = V_134 ;
if ( ( F_88 ( V_4 ) && F_89 ( V_4 ) == V_162 ) ||
( F_90 ( V_4 ) && F_89 ( V_4 ) >= V_150 ) )
V_146 |= V_163 ;
F_82 ( V_132 , V_146 ) ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
T_4 V_164 [ 3 ] = { 0 , 0 , 0 } ;
unsigned int V_110 ;
for ( V_110 = 0 ; V_110 < 3 ; V_110 ++ ) {
T_4 V_165 ;
if ( F_92 ( V_24 -> V_166 . V_167 [ V_110 ] ) != 1 )
continue;
V_165 = F_93 ( V_24 -> V_166 . V_167 [ V_110 ] ) - 1 ;
V_164 [ V_110 ] = 3 - V_165 ;
}
if ( V_164 [ 0 ] == 0 && V_164 [ 1 ] == 0 && V_164 [ 2 ] == 0 )
return 0 ;
F_85 ( V_141 ,
F_94 ( 2 ) |
F_94 ( 1 ) |
F_94 ( 0 ) ,
F_95 ( 2 , V_164 [ 2 ] ) |
F_95 ( 1 , V_164 [ 1 ] ) |
F_95 ( 0 , V_164 [ 0 ] ) ) ;
return 0 ;
}
static int F_96 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
F_87 ( V_2 ) ;
if ( F_89 ( V_4 ) == V_149 )
F_82 ( V_144 ,
V_168 ) ;
if ( F_89 ( V_4 ) <= V_169 ) {
F_82 ( V_132 ,
V_133 ) ;
}
if ( F_89 ( V_4 ) == V_155 ||
F_89 ( V_4 ) == V_169 )
F_82 ( V_132 ,
V_136 |
V_170 ) ;
if ( F_89 ( V_4 ) <= V_162 ) {
F_82 (
V_171 ,
V_172 ) ;
}
return F_91 ( V_2 ) ;
}
static int F_97 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
F_87 ( V_2 ) ;
F_82 ( V_125 ,
V_127 ) ;
if ( F_89 ( V_4 ) <= V_150 ) {
F_82 (
V_171 ,
V_172 ) ;
}
return 0 ;
}
int F_98 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
F_39 ( V_2 -> V_13 != V_75 ) ;
V_24 -> V_113 . V_114 = 0 ;
if ( F_99 ( V_4 ) )
return F_81 ( V_2 ) ;
if ( F_100 ( V_4 ) )
return F_86 ( V_2 ) ;
if ( F_88 ( V_4 ) )
return F_96 ( V_2 ) ;
if ( F_90 ( V_4 ) )
return F_97 ( V_2 ) ;
return 0 ;
}
static int F_101 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
int V_34 = F_54 ( V_2 ) ;
if ( V_34 )
return V_34 ;
if ( F_25 ( V_4 ) -> V_67 >= 4 && F_25 ( V_4 ) -> V_67 < 7 )
F_31 ( V_123 , F_41 ( V_173 ) ) ;
if ( F_25 ( V_4 ) -> V_67 >= 6 && F_25 ( V_4 ) -> V_67 < 8 )
F_31 ( V_123 , F_41 ( V_124 ) ) ;
if ( F_25 ( V_4 ) -> V_67 == 6 )
F_31 ( V_174 ,
F_41 ( V_175 ) ) ;
if ( F_33 ( V_4 ) )
F_31 ( V_176 ,
F_41 ( V_175 ) |
F_41 ( V_177 ) ) ;
if ( F_34 ( V_4 ) ) {
F_31 ( V_178 ,
F_53 ( V_179 ) ) ;
}
if ( F_25 ( V_4 ) -> V_67 >= 6 && F_25 ( V_4 ) -> V_67 < 8 )
F_31 ( V_121 , F_41 ( V_122 ) ) ;
if ( F_102 ( V_4 ) )
F_103 ( V_2 , ~ F_104 ( V_4 ) ) ;
return F_98 ( V_2 ) ;
}
static void F_105 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
if ( V_24 -> V_180 ) {
F_66 ( V_24 -> V_180 ) ;
F_67 ( & V_24 -> V_180 -> V_103 ) ;
V_24 -> V_180 = NULL ;
}
F_63 ( V_2 ) ;
}
static int F_106 ( struct V_29 * V_181 ,
unsigned int V_182 )
{
#define F_107 8
struct V_1 * V_183 = V_181 -> V_2 ;
struct V_3 * V_4 = V_183 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_184 ;
int V_110 , V_34 , V_185 ;
V_185 = F_108 ( F_25 ( V_4 ) -> V_186 ) ;
V_182 += ( V_185 - 1 ) * F_107 ;
#undef F_107
V_34 = F_9 ( V_181 , V_182 ) ;
if ( V_34 )
return V_34 ;
F_109 (waiter, dev_priv, i) {
T_1 V_187 ;
T_2 V_47 = V_183 -> V_188 . V_189 [ V_110 ] ;
if ( V_47 == V_190 )
continue;
V_187 = F_110 ( V_181 ) ;
F_10 ( V_183 , F_16 ( 6 ) ) ;
F_10 ( V_183 , V_64 |
V_52 |
V_62 ) ;
F_10 ( V_183 , F_111 ( V_47 ) ) ;
F_10 ( V_183 , F_112 ( V_47 ) ) ;
F_10 ( V_183 , V_187 ) ;
F_10 ( V_183 , 0 ) ;
F_10 ( V_183 , V_191 |
F_113 ( V_184 -> V_13 ) ) ;
F_10 ( V_183 , 0 ) ;
}
return 0 ;
}
static int F_114 ( struct V_29 * V_181 ,
unsigned int V_182 )
{
#define F_107 6
struct V_1 * V_183 = V_181 -> V_2 ;
struct V_3 * V_4 = V_183 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_184 ;
int V_110 , V_34 , V_185 ;
V_185 = F_108 ( F_25 ( V_4 ) -> V_186 ) ;
V_182 += ( V_185 - 1 ) * F_107 ;
#undef F_107
V_34 = F_9 ( V_181 , V_182 ) ;
if ( V_34 )
return V_34 ;
F_109 (waiter, dev_priv, i) {
T_1 V_187 ;
T_2 V_47 = V_183 -> V_188 . V_189 [ V_110 ] ;
if ( V_47 == V_190 )
continue;
V_187 = F_110 ( V_181 ) ;
F_10 ( V_183 , ( V_192 + 1 ) |
V_193 ) ;
F_10 ( V_183 , F_111 ( V_47 ) |
V_194 ) ;
F_10 ( V_183 , F_112 ( V_47 ) ) ;
F_10 ( V_183 , V_187 ) ;
F_10 ( V_183 , V_191 |
F_113 ( V_184 -> V_13 ) ) ;
F_10 ( V_183 , 0 ) ;
}
return 0 ;
}
static int F_115 ( struct V_29 * V_181 ,
unsigned int V_182 )
{
struct V_1 * V_183 = V_181 -> V_2 ;
struct V_3 * V_4 = V_183 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_195 ;
int V_110 , V_34 , V_185 ;
#define F_107 3
V_185 = F_108 ( F_25 ( V_4 ) -> V_186 ) ;
V_182 += F_116 ( ( V_185 - 1 ) * F_107 , 2 ) ;
#undef F_107
V_34 = F_9 ( V_181 , V_182 ) ;
if ( V_34 )
return V_34 ;
F_109 (useless, dev_priv, i) {
T_1 V_196 = V_183 -> V_188 . V_197 . signal [ V_110 ] ;
if ( V_196 != V_198 ) {
T_1 V_187 = F_110 ( V_181 ) ;
F_10 ( V_183 , F_77 ( 1 ) ) ;
F_10 ( V_183 , V_196 ) ;
F_10 ( V_183 , V_187 ) ;
}
}
if ( V_185 % 2 == 0 )
F_10 ( V_183 , V_40 ) ;
return 0 ;
}
static int
F_117 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
int V_34 ;
if ( V_2 -> V_188 . signal )
V_34 = V_2 -> V_188 . signal ( V_30 , 4 ) ;
else
V_34 = F_9 ( V_30 , 4 ) ;
if ( V_34 )
return V_34 ;
F_10 ( V_2 , V_199 ) ;
F_10 ( V_2 , V_200 << V_201 ) ;
F_10 ( V_2 , F_110 ( V_30 ) ) ;
F_10 ( V_2 , V_202 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static inline bool F_118 ( struct V_3 * V_4 ,
T_1 V_187 )
{
struct V_23 * V_24 = V_4 -> V_25 ;
return V_24 -> V_203 < V_187 ;
}
static int
F_119 ( struct V_29 * V_204 ,
struct V_1 * V_183 ,
T_1 V_187 )
{
struct V_1 * V_184 = V_204 -> V_2 ;
struct V_23 * V_24 = V_184 -> V_4 -> V_25 ;
int V_34 ;
V_34 = F_9 ( V_204 , 4 ) ;
if ( V_34 )
return V_34 ;
F_10 ( V_184 , V_205 |
V_206 |
V_207 |
V_208 ) ;
F_10 ( V_184 , V_187 ) ;
F_10 ( V_184 ,
F_111 ( F_120 ( V_184 , V_183 -> V_13 ) ) ) ;
F_10 ( V_184 ,
F_112 ( F_120 ( V_184 , V_183 -> V_13 ) ) ) ;
F_11 ( V_184 ) ;
return 0 ;
}
static int
F_121 ( struct V_29 * V_204 ,
struct V_1 * V_183 ,
T_1 V_187 )
{
struct V_1 * V_184 = V_204 -> V_2 ;
T_1 V_209 = V_210 |
V_211 |
V_212 ;
T_1 V_213 = V_183 -> V_188 . V_197 . V_214 [ V_184 -> V_13 ] ;
int V_34 ;
V_187 -= 1 ;
F_39 ( V_213 == V_190 ) ;
V_34 = F_9 ( V_204 , 4 ) ;
if ( V_34 )
return V_34 ;
if ( F_122 ( ! F_118 ( V_184 -> V_4 , V_187 ) ) ) {
F_10 ( V_184 , V_209 | V_213 ) ;
F_10 ( V_184 , V_187 ) ;
F_10 ( V_184 , 0 ) ;
F_10 ( V_184 , V_40 ) ;
} else {
F_10 ( V_184 , V_40 ) ;
F_10 ( V_184 , V_40 ) ;
F_10 ( V_184 , V_40 ) ;
F_10 ( V_184 , V_40 ) ;
}
F_11 ( V_184 ) ;
return 0 ;
}
static int
F_123 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
T_1 V_45 = V_2 -> V_46 . V_47 + 2 * V_48 ;
int V_34 ;
V_34 = F_9 ( V_30 , 32 ) ;
if ( V_34 )
return V_34 ;
F_10 ( V_2 , F_16 ( 4 ) | V_52 |
V_215 |
V_58 ) ;
F_10 ( V_2 , V_2 -> V_46 . V_47 | V_51 ) ;
F_10 ( V_2 , F_110 ( V_30 ) ) ;
F_10 ( V_2 , 0 ) ;
F_124 ( V_2 , V_45 ) ;
V_45 += 2 * V_48 ;
F_124 ( V_2 , V_45 ) ;
V_45 += 2 * V_48 ;
F_124 ( V_2 , V_45 ) ;
V_45 += 2 * V_48 ;
F_124 ( V_2 , V_45 ) ;
V_45 += 2 * V_48 ;
F_124 ( V_2 , V_45 ) ;
V_45 += 2 * V_48 ;
F_124 ( V_2 , V_45 ) ;
F_10 ( V_2 , F_16 ( 4 ) | V_52 |
V_215 |
V_58 |
V_216 ) ;
F_10 ( V_2 , V_2 -> V_46 . V_47 | V_51 ) ;
F_10 ( V_2 , F_110 ( V_30 ) ) ;
F_10 ( V_2 , 0 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static T_1
F_125 ( struct V_1 * V_2 , bool V_217 )
{
if ( ! V_217 ) {
struct V_23 * V_24 = V_2 -> V_4 -> V_25 ;
F_37 ( F_27 ( V_2 -> V_68 ) ) ;
}
return F_126 ( V_2 , V_200 ) ;
}
static T_1
F_127 ( struct V_1 * V_2 , bool V_217 )
{
return F_126 ( V_2 , V_200 ) ;
}
static void
F_128 ( struct V_1 * V_2 , T_1 V_187 )
{
F_129 ( V_2 , V_200 , V_187 ) ;
}
static T_1
F_130 ( struct V_1 * V_2 , bool V_217 )
{
return V_2 -> V_46 . V_108 [ 0 ] ;
}
static void
F_131 ( struct V_1 * V_2 , T_1 V_187 )
{
V_2 -> V_46 . V_108 [ 0 ] = V_187 ;
}
static bool
F_132 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_53 ;
if ( F_39 ( ! F_133 ( V_24 ) ) )
return false ;
F_134 ( & V_24 -> V_218 , V_53 ) ;
if ( V_2 -> V_219 ++ == 0 )
F_135 ( V_24 , V_2 -> V_220 ) ;
F_136 ( & V_24 -> V_218 , V_53 ) ;
return true ;
}
static void
F_137 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_53 ;
F_134 ( & V_24 -> V_218 , V_53 ) ;
if ( -- V_2 -> V_219 == 0 )
F_138 ( V_24 , V_2 -> V_220 ) ;
F_136 ( & V_24 -> V_218 , V_53 ) ;
}
static bool
F_139 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_53 ;
if ( ! F_133 ( V_24 ) )
return false ;
F_134 ( & V_24 -> V_218 , V_53 ) ;
if ( V_2 -> V_219 ++ == 0 ) {
V_24 -> V_221 &= ~ V_2 -> V_220 ;
F_31 ( V_222 , V_24 -> V_221 ) ;
F_37 ( V_222 ) ;
}
F_136 ( & V_24 -> V_218 , V_53 ) ;
return true ;
}
static void
F_140 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_53 ;
F_134 ( & V_24 -> V_218 , V_53 ) ;
if ( -- V_2 -> V_219 == 0 ) {
V_24 -> V_221 |= V_2 -> V_220 ;
F_31 ( V_222 , V_24 -> V_221 ) ;
F_37 ( V_222 ) ;
}
F_136 ( & V_24 -> V_218 , V_53 ) ;
}
static bool
F_141 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_53 ;
if ( ! F_133 ( V_24 ) )
return false ;
F_134 ( & V_24 -> V_218 , V_53 ) ;
if ( V_2 -> V_219 ++ == 0 ) {
V_24 -> V_221 &= ~ V_2 -> V_220 ;
F_142 ( V_222 , V_24 -> V_221 ) ;
F_143 ( V_222 ) ;
}
F_136 ( & V_24 -> V_218 , V_53 ) ;
return true ;
}
static void
F_144 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_53 ;
F_134 ( & V_24 -> V_218 , V_53 ) ;
if ( -- V_2 -> V_219 == 0 ) {
V_24 -> V_221 |= V_2 -> V_220 ;
F_142 ( V_222 , V_24 -> V_221 ) ;
F_143 ( V_222 ) ;
}
F_136 ( & V_24 -> V_218 , V_53 ) ;
}
static int
F_145 ( struct V_29 * V_30 ,
T_1 V_31 ,
T_1 V_32 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
int V_34 ;
V_34 = F_9 ( V_30 , 2 ) ;
if ( V_34 )
return V_34 ;
F_10 ( V_2 , V_35 ) ;
F_10 ( V_2 , V_40 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_146 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
int V_34 ;
V_34 = F_9 ( V_30 , 4 ) ;
if ( V_34 )
return V_34 ;
F_10 ( V_2 , V_199 ) ;
F_10 ( V_2 , V_200 << V_201 ) ;
F_10 ( V_2 , F_110 ( V_30 ) ) ;
F_10 ( V_2 , V_202 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static bool
F_147 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_53 ;
if ( F_39 ( ! F_133 ( V_24 ) ) )
return false ;
F_134 ( & V_24 -> V_218 , V_53 ) ;
if ( V_2 -> V_219 ++ == 0 ) {
if ( F_102 ( V_4 ) && V_2 -> V_13 == V_75 )
F_103 ( V_2 ,
~ ( V_2 -> V_220 |
F_104 ( V_4 ) ) ) ;
else
F_103 ( V_2 , ~ V_2 -> V_220 ) ;
F_135 ( V_24 , V_2 -> V_220 ) ;
}
F_136 ( & V_24 -> V_218 , V_53 ) ;
return true ;
}
static void
F_148 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_53 ;
F_134 ( & V_24 -> V_218 , V_53 ) ;
if ( -- V_2 -> V_219 == 0 ) {
if ( F_102 ( V_4 ) && V_2 -> V_13 == V_75 )
F_103 ( V_2 , ~ F_104 ( V_4 ) ) ;
else
F_103 ( V_2 , ~ 0 ) ;
F_138 ( V_24 , V_2 -> V_220 ) ;
}
F_136 ( & V_24 -> V_218 , V_53 ) ;
}
static bool
F_149 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_53 ;
if ( F_39 ( ! F_133 ( V_24 ) ) )
return false ;
F_134 ( & V_24 -> V_218 , V_53 ) ;
if ( V_2 -> V_219 ++ == 0 ) {
F_103 ( V_2 , ~ V_2 -> V_220 ) ;
F_150 ( V_24 , V_2 -> V_220 ) ;
}
F_136 ( & V_24 -> V_218 , V_53 ) ;
return true ;
}
static void
F_151 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_53 ;
F_134 ( & V_24 -> V_218 , V_53 ) ;
if ( -- V_2 -> V_219 == 0 ) {
F_103 ( V_2 , ~ 0 ) ;
F_152 ( V_24 , V_2 -> V_220 ) ;
}
F_136 ( & V_24 -> V_218 , V_53 ) ;
}
static bool
F_153 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_53 ;
if ( F_39 ( ! F_133 ( V_24 ) ) )
return false ;
F_134 ( & V_24 -> V_218 , V_53 ) ;
if ( V_2 -> V_219 ++ == 0 ) {
if ( F_102 ( V_4 ) && V_2 -> V_13 == V_75 ) {
F_103 ( V_2 ,
~ ( V_2 -> V_220 |
V_223 ) ) ;
} else {
F_103 ( V_2 , ~ V_2 -> V_220 ) ;
}
F_37 ( F_154 ( V_2 -> V_68 ) ) ;
}
F_136 ( & V_24 -> V_218 , V_53 ) ;
return true ;
}
static void
F_155 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_53 ;
F_134 ( & V_24 -> V_218 , V_53 ) ;
if ( -- V_2 -> V_219 == 0 ) {
if ( F_102 ( V_4 ) && V_2 -> V_13 == V_75 ) {
F_103 ( V_2 ,
~ V_223 ) ;
} else {
F_103 ( V_2 , ~ 0 ) ;
}
F_37 ( F_154 ( V_2 -> V_68 ) ) ;
}
F_136 ( & V_24 -> V_218 , V_53 ) ;
}
static int
F_156 ( struct V_29 * V_30 ,
T_2 V_224 , T_1 V_225 ,
unsigned V_226 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
int V_34 ;
V_34 = F_9 ( V_30 , 2 ) ;
if ( V_34 )
return V_34 ;
F_10 ( V_2 ,
V_227 |
V_228 |
( V_226 & V_229 ?
0 : V_230 ) ) ;
F_10 ( V_2 , V_224 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_157 ( struct V_29 * V_30 ,
T_2 V_224 , T_1 V_231 ,
unsigned V_226 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
T_1 V_232 = V_2 -> V_46 . V_47 ;
int V_34 ;
V_34 = F_9 ( V_30 , 6 ) ;
if ( V_34 )
return V_34 ;
F_10 ( V_2 , V_233 | V_234 ) ;
F_10 ( V_2 , V_235 | V_236 | 4096 ) ;
F_10 ( V_2 , V_237 << 16 | 4 ) ;
F_10 ( V_2 , V_232 ) ;
F_10 ( V_2 , 0xdeadbeef ) ;
F_10 ( V_2 , V_40 ) ;
F_11 ( V_2 ) ;
if ( ( V_226 & V_238 ) == 0 ) {
if ( V_231 > V_239 )
return - V_120 ;
V_34 = F_9 ( V_30 , 6 + 2 ) ;
if ( V_34 )
return V_34 ;
F_10 ( V_2 , V_240 | V_234 ) ;
F_10 ( V_2 , V_235 | V_241 | 4096 ) ;
F_10 ( V_2 , F_158 ( V_231 , 4096 ) << 16 | 4096 ) ;
F_10 ( V_2 , V_232 ) ;
F_10 ( V_2 , 4096 ) ;
F_10 ( V_2 , V_224 ) ;
F_10 ( V_2 , V_35 ) ;
F_10 ( V_2 , V_40 ) ;
F_11 ( V_2 ) ;
V_224 = V_232 ;
}
V_34 = F_9 ( V_30 , 4 ) ;
if ( V_34 )
return V_34 ;
F_10 ( V_2 , V_242 ) ;
F_10 ( V_2 , V_224 | ( V_226 & V_229 ?
0 : V_243 ) ) ;
F_10 ( V_2 , V_224 + V_231 - 8 ) ;
F_10 ( V_2 , V_40 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_159 ( struct V_29 * V_30 ,
T_2 V_224 , T_1 V_231 ,
unsigned V_226 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
int V_34 ;
V_34 = F_9 ( V_30 , 2 ) ;
if ( V_34 )
return V_34 ;
F_10 ( V_2 , V_227 | V_228 ) ;
F_10 ( V_2 , V_224 | ( V_226 & V_229 ?
0 : V_243 ) ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static void F_160 ( struct V_1 * V_2 )
{
struct V_92 * V_14 ;
V_14 = V_2 -> V_84 . V_14 ;
if ( V_14 == NULL )
return;
F_64 ( F_65 ( V_14 -> V_101 -> V_102 ) ) ;
F_66 ( V_14 ) ;
F_67 ( & V_14 -> V_103 ) ;
V_2 -> V_84 . V_14 = NULL ;
}
static int F_161 ( struct V_1 * V_2 )
{
struct V_92 * V_14 ;
if ( ( V_14 = V_2 -> V_84 . V_14 ) == NULL ) {
unsigned V_53 ;
int V_34 ;
V_14 = F_69 ( V_2 -> V_4 , 4096 ) ;
if ( V_14 == NULL ) {
F_43 ( L_13 ) ;
return - V_104 ;
}
V_34 = F_70 ( V_14 , V_106 ) ;
if ( V_34 )
goto V_107;
V_53 = 0 ;
if ( ! F_162 ( V_2 -> V_4 ) )
V_53 |= V_244 ;
V_34 = F_71 ( V_14 , 4096 , V_53 ) ;
if ( V_34 ) {
V_107:
F_67 ( & V_14 -> V_103 ) ;
return V_34 ;
}
V_2 -> V_84 . V_14 = V_14 ;
}
V_2 -> V_84 . V_85 = F_60 ( V_14 ) ;
V_2 -> V_84 . V_245 = F_72 ( F_65 ( V_14 -> V_101 -> V_102 ) ) ;
memset ( V_2 -> V_84 . V_245 , 0 , V_96 ) ;
F_73 ( L_14 ,
V_2 -> V_90 , V_2 -> V_84 . V_85 ) ;
return 0 ;
}
static int F_163 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_4 -> V_25 ;
if ( ! V_24 -> V_71 ) {
V_24 -> V_71 =
F_164 ( V_2 -> V_4 , V_96 , V_96 ) ;
if ( ! V_24 -> V_71 )
return - V_104 ;
}
V_2 -> V_84 . V_245 = V_24 -> V_71 -> V_246 ;
memset ( V_2 -> V_84 . V_245 , 0 , V_96 ) ;
return 0 ;
}
void F_165 ( struct V_10 * V_11 )
{
F_166 ( V_11 -> V_247 ) ;
V_11 -> V_247 = NULL ;
F_66 ( V_11 -> V_14 ) ;
}
int F_167 ( struct V_3 * V_4 ,
struct V_10 * V_11 )
{
struct V_23 * V_24 = F_45 ( V_4 ) ;
struct V_92 * V_14 = V_11 -> V_14 ;
int V_34 ;
V_34 = F_71 ( V_14 , V_96 , V_244 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_168 ( V_14 , true ) ;
if ( V_34 ) {
F_66 ( V_14 ) ;
return V_34 ;
}
V_11 -> V_247 = F_169 ( V_24 -> V_248 . V_249 +
F_60 ( V_14 ) , V_11 -> V_18 ) ;
if ( V_11 -> V_247 == NULL ) {
F_66 ( V_14 ) ;
return - V_250 ;
}
return 0 ;
}
void F_170 ( struct V_10 * V_11 )
{
F_67 ( & V_11 -> V_14 -> V_103 ) ;
V_11 -> V_14 = NULL ;
}
int F_171 ( struct V_3 * V_4 ,
struct V_10 * V_11 )
{
struct V_92 * V_14 ;
V_14 = NULL ;
if ( ! F_162 ( V_4 ) )
V_14 = F_172 ( V_4 , V_11 -> V_18 ) ;
if ( V_14 == NULL )
V_14 = F_69 ( V_4 , V_11 -> V_18 ) ;
if ( V_14 == NULL )
return - V_104 ;
V_14 -> V_251 = 1 ;
V_11 -> V_14 = V_14 ;
return 0 ;
}
static int F_173 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_34 ;
F_39 ( V_2 -> V_15 ) ;
V_11 = F_174 ( sizeof( * V_11 ) , V_252 ) ;
if ( ! V_11 )
return - V_104 ;
V_2 -> V_15 = V_11 ;
V_2 -> V_4 = V_4 ;
F_175 ( & V_2 -> V_253 ) ;
F_175 ( & V_2 -> V_254 ) ;
F_175 ( & V_2 -> V_255 ) ;
F_176 ( V_4 , & V_2 -> V_256 ) ;
V_11 -> V_18 = 32 * V_96 ;
V_11 -> V_2 = V_2 ;
memset ( V_2 -> V_188 . V_257 , 0 , sizeof( V_2 -> V_188 . V_257 ) ) ;
F_177 ( & V_2 -> V_258 ) ;
if ( F_58 ( V_4 ) ) {
V_34 = F_161 ( V_2 ) ;
if ( V_34 )
goto error;
} else {
F_178 ( V_2 -> V_13 != V_75 ) ;
V_34 = F_163 ( V_2 ) ;
if ( V_34 )
goto error;
}
F_39 ( V_11 -> V_14 ) ;
V_34 = F_171 ( V_4 , V_11 ) ;
if ( V_34 ) {
F_43 ( L_15 ,
V_2 -> V_90 , V_34 ) ;
goto error;
}
V_34 = F_167 ( V_4 , V_11 ) ;
if ( V_34 ) {
F_43 ( L_16 ,
V_2 -> V_90 , V_34 ) ;
F_170 ( V_11 ) ;
goto error;
}
V_11 -> V_259 = V_11 -> V_18 ;
if ( F_179 ( V_4 ) || F_180 ( V_4 ) )
V_11 -> V_259 -= 2 * V_48 ;
V_34 = F_181 ( V_2 ) ;
if ( V_34 )
goto error;
return 0 ;
error:
F_182 ( V_11 ) ;
V_2 -> V_15 = NULL ;
return V_34 ;
}
void F_183 ( struct V_1 * V_2 )
{
struct V_23 * V_24 ;
struct V_10 * V_11 ;
if ( ! F_1 ( V_2 ) )
return;
V_24 = F_45 ( V_2 -> V_4 ) ;
V_11 = V_2 -> V_15 ;
F_184 ( V_2 ) ;
F_39 ( ! F_46 ( V_2 -> V_4 ) && ( F_40 ( V_2 ) & V_87 ) == 0 ) ;
F_165 ( V_11 ) ;
F_170 ( V_11 ) ;
if ( V_2 -> V_260 )
V_2 -> V_260 ( V_2 ) ;
F_160 ( V_2 ) ;
F_185 ( V_2 ) ;
F_186 ( & V_2 -> V_256 ) ;
F_182 ( V_11 ) ;
V_2 -> V_15 = NULL ;
}
static int F_187 ( struct V_1 * V_2 , int V_261 )
{
struct V_10 * V_11 = V_2 -> V_15 ;
struct V_29 * V_262 ;
unsigned V_19 ;
int V_34 ;
if ( F_4 ( V_11 ) >= V_261 )
return 0 ;
F_39 ( V_11 -> V_263 ) ;
F_188 (request, &ring->request_list, list) {
V_19 = F_2 ( V_262 -> V_264 , V_11 -> V_17 ,
V_11 -> V_18 ) ;
if ( V_19 >= V_261 )
break;
}
if ( F_39 ( & V_262 -> V_265 == & V_2 -> V_254 ) )
return - V_120 ;
V_34 = F_189 ( V_262 ) ;
if ( V_34 )
return V_34 ;
V_11 -> V_19 = V_19 ;
return 0 ;
}
static void F_190 ( struct V_10 * V_11 )
{
T_3 T_5 * V_266 ;
int V_267 = V_11 -> V_18 - V_11 -> V_17 ;
V_266 = V_11 -> V_247 + V_11 -> V_17 ;
V_267 /= 4 ;
while ( V_267 -- )
F_191 ( V_40 , V_266 ++ ) ;
V_11 -> V_17 = 0 ;
F_3 ( V_11 ) ;
}
int F_192 ( struct V_1 * V_2 )
{
struct V_29 * V_30 ;
if ( F_193 ( & V_2 -> V_254 ) )
return 0 ;
V_30 = F_194 ( V_2 -> V_254 . V_268 ,
struct V_29 ,
V_265 ) ;
return F_195 ( V_30 ,
F_196 ( & F_45 ( V_2 -> V_4 ) -> V_26 . V_269 ) ,
F_45 ( V_2 -> V_4 ) -> V_270 . V_271 ,
NULL , NULL ) ;
}
int F_197 ( struct V_29 * V_262 )
{
V_262 -> V_11 = V_262 -> V_2 -> V_15 ;
return 0 ;
}
int F_198 ( struct V_29 * V_262 )
{
F_199 ( V_262 -> V_11 , V_272 ) ;
return F_9 ( V_262 , 0 ) ;
}
void F_199 ( struct V_10 * V_11 , int V_18 )
{
F_39 ( V_11 -> V_273 ) ;
F_39 ( V_11 -> V_263 ) ;
V_11 -> V_273 = V_18 ;
}
void F_200 ( struct V_10 * V_11 )
{
F_39 ( V_11 -> V_263 ) ;
V_11 -> V_273 = 0 ;
V_11 -> V_263 = false ;
}
void F_201 ( struct V_10 * V_11 )
{
F_39 ( V_11 -> V_263 ) ;
V_11 -> V_263 = true ;
V_11 -> V_274 = V_11 -> V_17 ;
}
void F_202 ( struct V_10 * V_11 )
{
F_39 ( ! V_11 -> V_263 ) ;
if ( V_11 -> V_17 > V_11 -> V_274 ) {
F_203 ( V_11 -> V_17 > V_11 -> V_274 + V_11 -> V_273 ,
L_17 ,
V_11 -> V_17 - V_11 -> V_274 , V_11 -> V_273 ) ;
} else {
}
V_11 -> V_273 = 0 ;
V_11 -> V_263 = false ;
}
static int F_204 ( struct V_1 * V_2 , int V_275 )
{
struct V_10 * V_11 = V_2 -> V_15 ;
int V_276 = V_11 -> V_259 - V_11 -> V_17 ;
int V_277 = V_11 -> V_18 - V_11 -> V_17 ;
int V_34 , V_278 , V_279 = 0 ;
bool V_280 = false ;
if ( V_11 -> V_263 )
V_278 = V_275 ;
else
V_278 = V_275 + V_11 -> V_273 ;
if ( F_205 ( V_275 > V_276 ) ) {
V_279 = V_277 + V_278 ;
V_280 = true ;
} else {
if ( F_205 ( V_278 > V_276 ) ) {
V_279 = V_277 + V_11 -> V_273 ;
V_280 = true ;
} else if ( V_278 > V_11 -> V_19 ) {
V_279 = V_278 ;
}
}
if ( V_279 ) {
V_34 = F_187 ( V_2 , V_279 ) ;
if ( F_205 ( V_34 ) )
return V_34 ;
if ( V_280 )
F_190 ( V_11 ) ;
}
return 0 ;
}
int F_9 ( struct V_29 * V_30 ,
int V_182 )
{
struct V_1 * V_2 ;
struct V_23 * V_24 ;
int V_34 ;
F_39 ( V_30 == NULL ) ;
V_2 = V_30 -> V_2 ;
V_24 = V_2 -> V_4 -> V_25 ;
V_34 = F_206 ( & V_24 -> V_26 ,
V_24 -> V_270 . V_271 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_204 ( V_2 , V_182 * sizeof( T_3 ) ) ;
if ( V_34 )
return V_34 ;
V_2 -> V_15 -> V_19 -= V_182 * sizeof( T_3 ) ;
return 0 ;
}
int F_207 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
int V_182 = ( V_2 -> V_15 -> V_17 & ( V_48 - 1 ) ) / sizeof( T_3 ) ;
int V_34 ;
if ( V_182 == 0 )
return 0 ;
V_182 = V_48 / sizeof( T_3 ) - V_182 ;
V_34 = F_9 ( V_30 , V_182 ) ;
if ( V_34 )
return V_34 ;
while ( V_182 -- )
F_10 ( V_2 , V_40 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
void F_208 ( struct V_1 * V_2 , T_1 V_187 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
if ( F_25 ( V_4 ) -> V_67 == 6 || F_25 ( V_4 ) -> V_67 == 7 ) {
F_31 ( F_209 ( V_2 -> V_68 ) , 0 ) ;
F_31 ( F_210 ( V_2 -> V_68 ) , 0 ) ;
if ( F_211 ( V_4 ) )
F_31 ( F_212 ( V_2 -> V_68 ) , 0 ) ;
}
V_2 -> V_281 ( V_2 , V_187 ) ;
V_2 -> V_100 . V_187 = V_187 ;
}
static void F_213 ( struct V_1 * V_2 ,
T_1 V_65 )
{
struct V_23 * V_24 = V_2 -> V_4 -> V_25 ;
F_31 ( V_282 ,
F_41 ( V_283 ) ) ;
F_214 ( V_284 , 0x0 ) ;
if ( F_42 ( ( F_29 ( V_282 ) &
V_285 ) == 0 ,
50 ) )
F_43 ( L_18 ) ;
F_23 ( V_2 , V_65 ) ;
F_37 ( F_215 ( V_2 -> V_68 ) ) ;
F_31 ( V_282 ,
F_53 ( V_283 ) ) ;
}
static int F_216 ( struct V_29 * V_30 ,
T_1 V_286 , T_1 V_287 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
T_3 V_33 ;
int V_34 ;
V_34 = F_9 ( V_30 , 4 ) ;
if ( V_34 )
return V_34 ;
V_33 = V_192 ;
if ( F_25 ( V_2 -> V_4 ) -> V_67 >= 8 )
V_33 += 1 ;
V_33 |= V_288 | V_193 ;
if ( V_286 & V_289 )
V_33 |= V_290 | V_291 ;
F_10 ( V_2 , V_33 ) ;
F_10 ( V_2 , V_292 | V_194 ) ;
if ( F_25 ( V_2 -> V_4 ) -> V_67 >= 8 ) {
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 ) ;
} else {
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , V_40 ) ;
}
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_217 ( struct V_29 * V_30 ,
T_2 V_224 , T_1 V_231 ,
unsigned V_226 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
bool V_293 = F_218 ( V_2 -> V_4 ) &&
! ( V_226 & V_229 ) ;
int V_34 ;
V_34 = F_9 ( V_30 , 4 ) ;
if ( V_34 )
return V_34 ;
F_10 ( V_2 , V_294 | ( V_293 << 8 ) |
( V_226 & V_295 ?
V_296 : 0 ) ) ;
F_10 ( V_2 , F_111 ( V_224 ) ) ;
F_10 ( V_2 , F_112 ( V_224 ) ) ;
F_10 ( V_2 , V_40 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_219 ( struct V_29 * V_30 ,
T_2 V_224 , T_1 V_231 ,
unsigned V_226 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
int V_34 ;
V_34 = F_9 ( V_30 , 2 ) ;
if ( V_34 )
return V_34 ;
F_10 ( V_2 ,
V_227 |
( V_226 & V_229 ?
0 : V_297 | V_298 ) |
( V_226 & V_295 ?
V_296 : 0 ) ) ;
F_10 ( V_2 , V_224 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_220 ( struct V_29 * V_30 ,
T_2 V_224 , T_1 V_231 ,
unsigned V_226 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
int V_34 ;
V_34 = F_9 ( V_30 , 2 ) ;
if ( V_34 )
return V_34 ;
F_10 ( V_2 ,
V_227 |
( V_226 & V_229 ?
0 : V_230 ) ) ;
F_10 ( V_2 , V_224 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int F_221 ( struct V_29 * V_30 ,
T_1 V_286 , T_1 V_287 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_33 ;
int V_34 ;
V_34 = F_9 ( V_30 , 4 ) ;
if ( V_34 )
return V_34 ;
V_33 = V_192 ;
if ( F_25 ( V_4 ) -> V_67 >= 8 )
V_33 += 1 ;
V_33 |= V_288 | V_193 ;
if ( V_286 & V_36 )
V_33 |= V_290 ;
F_10 ( V_2 , V_33 ) ;
F_10 ( V_2 , V_292 | V_194 ) ;
if ( F_25 ( V_4 ) -> V_67 >= 8 ) {
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 ) ;
} else {
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , V_40 ) ;
}
F_11 ( V_2 ) ;
return 0 ;
}
int F_222 ( struct V_3 * V_4 )
{
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_2 = & V_24 -> V_2 [ V_75 ] ;
struct V_92 * V_14 ;
int V_34 ;
V_2 -> V_90 = L_19 ;
V_2 -> V_13 = V_75 ;
V_2 -> V_68 = V_299 ;
if ( F_25 ( V_4 ) -> V_67 >= 8 ) {
if ( F_223 ( V_4 ) ) {
V_14 = F_69 ( V_4 , 4096 ) ;
if ( V_14 == NULL ) {
F_43 ( L_20 ) ;
V_5 . V_300 = 0 ;
} else {
F_70 ( V_14 , V_106 ) ;
V_34 = F_71 ( V_14 , 0 , V_301 ) ;
if ( V_34 != 0 ) {
F_67 ( & V_14 -> V_103 ) ;
F_43 ( L_21 ) ;
V_5 . V_300 = 0 ;
} else
V_24 -> V_180 = V_14 ;
}
}
V_2 -> V_302 = F_78 ;
V_2 -> V_303 = F_117 ;
V_2 -> V_287 = F_21 ;
V_2 -> V_304 = F_153 ;
V_2 -> V_305 = F_155 ;
V_2 -> V_220 = V_306 ;
V_2 -> V_307 = F_125 ;
V_2 -> V_281 = F_128 ;
if ( F_223 ( V_4 ) ) {
F_39 ( ! V_24 -> V_180 ) ;
V_2 -> V_188 . V_308 = F_119 ;
V_2 -> V_188 . signal = F_106 ;
V_309 ;
}
} else if ( F_25 ( V_4 ) -> V_67 >= 6 ) {
V_2 -> V_303 = F_117 ;
V_2 -> V_287 = F_19 ;
if ( F_25 ( V_4 ) -> V_67 == 6 )
V_2 -> V_287 = F_17 ;
V_2 -> V_304 = F_147 ;
V_2 -> V_305 = F_148 ;
V_2 -> V_220 = V_306 ;
V_2 -> V_307 = F_125 ;
V_2 -> V_281 = F_128 ;
if ( F_223 ( V_4 ) ) {
V_2 -> V_188 . V_308 = F_121 ;
V_2 -> V_188 . signal = F_115 ;
V_2 -> V_188 . V_197 . V_214 [ V_75 ] = V_190 ;
V_2 -> V_188 . V_197 . V_214 [ V_80 ] = V_310 ;
V_2 -> V_188 . V_197 . V_214 [ V_77 ] = V_311 ;
V_2 -> V_188 . V_197 . V_214 [ V_82 ] = V_312 ;
V_2 -> V_188 . V_197 . V_214 [ V_79 ] = V_190 ;
V_2 -> V_188 . V_197 . signal [ V_75 ] = V_198 ;
V_2 -> V_188 . V_197 . signal [ V_80 ] = V_313 ;
V_2 -> V_188 . V_197 . signal [ V_77 ] = V_314 ;
V_2 -> V_188 . V_197 . signal [ V_82 ] = V_315 ;
V_2 -> V_188 . V_197 . signal [ V_79 ] = V_198 ;
}
} else if ( F_14 ( V_4 ) ) {
V_2 -> V_303 = F_123 ;
V_2 -> V_287 = F_12 ;
V_2 -> V_307 = F_130 ;
V_2 -> V_281 = F_131 ;
V_2 -> V_304 = F_132 ;
V_2 -> V_305 = F_137 ;
V_2 -> V_220 = V_306 |
V_316 ;
} else {
V_2 -> V_303 = F_146 ;
if ( F_25 ( V_4 ) -> V_67 < 4 )
V_2 -> V_287 = F_8 ;
else
V_2 -> V_287 = F_12 ;
V_2 -> V_307 = F_127 ;
V_2 -> V_281 = F_128 ;
if ( F_46 ( V_4 ) ) {
V_2 -> V_304 = F_141 ;
V_2 -> V_305 = F_144 ;
} else {
V_2 -> V_304 = F_139 ;
V_2 -> V_305 = F_140 ;
}
V_2 -> V_220 = V_317 ;
}
V_2 -> V_28 = F_22 ;
if ( F_224 ( V_4 ) )
V_2 -> V_318 = F_219 ;
else if ( F_225 ( V_4 ) )
V_2 -> V_318 = F_217 ;
else if ( F_25 ( V_4 ) -> V_67 >= 6 )
V_2 -> V_318 = F_220 ;
else if ( F_25 ( V_4 ) -> V_67 >= 4 )
V_2 -> V_318 = F_156 ;
else if ( F_179 ( V_4 ) || F_180 ( V_4 ) )
V_2 -> V_318 = F_157 ;
else
V_2 -> V_318 = F_159 ;
V_2 -> V_319 = F_101 ;
V_2 -> V_260 = F_105 ;
if ( F_226 ( V_4 ) ) {
V_14 = F_69 ( V_4 , V_320 ) ;
if ( V_14 == NULL ) {
F_43 ( L_22 ) ;
return - V_104 ;
}
V_34 = F_71 ( V_14 , 0 , 0 ) ;
if ( V_34 != 0 ) {
F_67 ( & V_14 -> V_103 ) ;
F_43 ( L_23 ) ;
return V_34 ;
}
V_2 -> V_46 . V_14 = V_14 ;
V_2 -> V_46 . V_47 = F_60 ( V_14 ) ;
}
V_34 = F_173 ( V_4 , V_2 ) ;
if ( V_34 )
return V_34 ;
if ( F_25 ( V_4 ) -> V_67 >= 5 ) {
V_34 = F_68 ( V_2 ) ;
if ( V_34 )
return V_34 ;
}
return 0 ;
}
int F_227 ( struct V_3 * V_4 )
{
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_2 = & V_24 -> V_2 [ V_80 ] ;
V_2 -> V_90 = L_24 ;
V_2 -> V_13 = V_80 ;
V_2 -> V_28 = F_22 ;
if ( F_25 ( V_4 ) -> V_67 >= 6 ) {
V_2 -> V_68 = V_321 ;
if ( F_34 ( V_4 ) )
V_2 -> V_28 = F_213 ;
V_2 -> V_287 = F_216 ;
V_2 -> V_303 = F_117 ;
V_2 -> V_307 = F_125 ;
V_2 -> V_281 = F_128 ;
if ( F_25 ( V_4 ) -> V_67 >= 8 ) {
V_2 -> V_220 =
V_306 << V_322 ;
V_2 -> V_304 = F_153 ;
V_2 -> V_305 = F_155 ;
V_2 -> V_318 =
F_217 ;
if ( F_223 ( V_4 ) ) {
V_2 -> V_188 . V_308 = F_119 ;
V_2 -> V_188 . signal = F_114 ;
V_309 ;
}
} else {
V_2 -> V_220 = V_323 ;
V_2 -> V_304 = F_147 ;
V_2 -> V_305 = F_148 ;
V_2 -> V_318 =
F_220 ;
if ( F_223 ( V_4 ) ) {
V_2 -> V_188 . V_308 = F_121 ;
V_2 -> V_188 . signal = F_115 ;
V_2 -> V_188 . V_197 . V_214 [ V_75 ] = V_324 ;
V_2 -> V_188 . V_197 . V_214 [ V_80 ] = V_190 ;
V_2 -> V_188 . V_197 . V_214 [ V_77 ] = V_325 ;
V_2 -> V_188 . V_197 . V_214 [ V_82 ] = V_326 ;
V_2 -> V_188 . V_197 . V_214 [ V_79 ] = V_190 ;
V_2 -> V_188 . V_197 . signal [ V_75 ] = V_327 ;
V_2 -> V_188 . V_197 . signal [ V_80 ] = V_198 ;
V_2 -> V_188 . V_197 . signal [ V_77 ] = V_328 ;
V_2 -> V_188 . V_197 . signal [ V_82 ] = V_329 ;
V_2 -> V_188 . V_197 . signal [ V_79 ] = V_198 ;
}
}
} else {
V_2 -> V_68 = V_330 ;
V_2 -> V_287 = F_145 ;
V_2 -> V_303 = F_146 ;
V_2 -> V_307 = F_127 ;
V_2 -> V_281 = F_128 ;
if ( F_14 ( V_4 ) ) {
V_2 -> V_220 = V_331 ;
V_2 -> V_304 = F_132 ;
V_2 -> V_305 = F_137 ;
} else {
V_2 -> V_220 = V_332 ;
V_2 -> V_304 = F_139 ;
V_2 -> V_305 = F_140 ;
}
V_2 -> V_318 = F_156 ;
}
V_2 -> V_319 = F_54 ;
return F_173 ( V_4 , V_2 ) ;
}
int F_228 ( struct V_3 * V_4 )
{
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_2 = & V_24 -> V_2 [ V_79 ] ;
V_2 -> V_90 = L_25 ;
V_2 -> V_13 = V_79 ;
V_2 -> V_28 = F_22 ;
V_2 -> V_68 = V_333 ;
V_2 -> V_287 = F_216 ;
V_2 -> V_303 = F_117 ;
V_2 -> V_307 = F_125 ;
V_2 -> V_281 = F_128 ;
V_2 -> V_220 =
V_306 << V_334 ;
V_2 -> V_304 = F_153 ;
V_2 -> V_305 = F_155 ;
V_2 -> V_318 =
F_217 ;
if ( F_223 ( V_4 ) ) {
V_2 -> V_188 . V_308 = F_119 ;
V_2 -> V_188 . signal = F_114 ;
V_309 ;
}
V_2 -> V_319 = F_54 ;
return F_173 ( V_4 , V_2 ) ;
}
int F_229 ( struct V_3 * V_4 )
{
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_2 = & V_24 -> V_2 [ V_77 ] ;
V_2 -> V_90 = L_26 ;
V_2 -> V_13 = V_77 ;
V_2 -> V_68 = V_335 ;
V_2 -> V_28 = F_22 ;
V_2 -> V_287 = F_221 ;
V_2 -> V_303 = F_117 ;
V_2 -> V_307 = F_125 ;
V_2 -> V_281 = F_128 ;
if ( F_25 ( V_4 ) -> V_67 >= 8 ) {
V_2 -> V_220 =
V_306 << V_336 ;
V_2 -> V_304 = F_153 ;
V_2 -> V_305 = F_155 ;
V_2 -> V_318 = F_217 ;
if ( F_223 ( V_4 ) ) {
V_2 -> V_188 . V_308 = F_119 ;
V_2 -> V_188 . signal = F_114 ;
V_309 ;
}
} else {
V_2 -> V_220 = V_337 ;
V_2 -> V_304 = F_147 ;
V_2 -> V_305 = F_148 ;
V_2 -> V_318 = F_220 ;
if ( F_223 ( V_4 ) ) {
V_2 -> V_188 . signal = F_115 ;
V_2 -> V_188 . V_308 = F_121 ;
V_2 -> V_188 . V_197 . V_214 [ V_75 ] = V_338 ;
V_2 -> V_188 . V_197 . V_214 [ V_80 ] = V_339 ;
V_2 -> V_188 . V_197 . V_214 [ V_77 ] = V_190 ;
V_2 -> V_188 . V_197 . V_214 [ V_82 ] = V_340 ;
V_2 -> V_188 . V_197 . V_214 [ V_79 ] = V_190 ;
V_2 -> V_188 . V_197 . signal [ V_75 ] = V_341 ;
V_2 -> V_188 . V_197 . signal [ V_80 ] = V_342 ;
V_2 -> V_188 . V_197 . signal [ V_77 ] = V_198 ;
V_2 -> V_188 . V_197 . signal [ V_82 ] = V_343 ;
V_2 -> V_188 . V_197 . signal [ V_79 ] = V_198 ;
}
}
V_2 -> V_319 = F_54 ;
return F_173 ( V_4 , V_2 ) ;
}
int F_230 ( struct V_3 * V_4 )
{
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_2 = & V_24 -> V_2 [ V_82 ] ;
V_2 -> V_90 = L_27 ;
V_2 -> V_13 = V_82 ;
V_2 -> V_68 = V_344 ;
V_2 -> V_28 = F_22 ;
V_2 -> V_287 = F_221 ;
V_2 -> V_303 = F_117 ;
V_2 -> V_307 = F_125 ;
V_2 -> V_281 = F_128 ;
if ( F_25 ( V_4 ) -> V_67 >= 8 ) {
V_2 -> V_220 =
V_306 << V_345 ;
V_2 -> V_304 = F_153 ;
V_2 -> V_305 = F_155 ;
V_2 -> V_318 = F_217 ;
if ( F_223 ( V_4 ) ) {
V_2 -> V_188 . V_308 = F_119 ;
V_2 -> V_188 . signal = F_114 ;
V_309 ;
}
} else {
V_2 -> V_220 = V_346 ;
V_2 -> V_304 = F_149 ;
V_2 -> V_305 = F_151 ;
V_2 -> V_318 = F_220 ;
if ( F_223 ( V_4 ) ) {
V_2 -> V_188 . V_308 = F_121 ;
V_2 -> V_188 . signal = F_115 ;
V_2 -> V_188 . V_197 . V_214 [ V_75 ] = V_347 ;
V_2 -> V_188 . V_197 . V_214 [ V_80 ] = V_348 ;
V_2 -> V_188 . V_197 . V_214 [ V_77 ] = V_349 ;
V_2 -> V_188 . V_197 . V_214 [ V_82 ] = V_190 ;
V_2 -> V_188 . V_197 . V_214 [ V_79 ] = V_190 ;
V_2 -> V_188 . V_197 . signal [ V_75 ] = V_350 ;
V_2 -> V_188 . V_197 . signal [ V_80 ] = V_351 ;
V_2 -> V_188 . V_197 . signal [ V_77 ] = V_352 ;
V_2 -> V_188 . V_197 . signal [ V_82 ] = V_198 ;
V_2 -> V_188 . V_197 . signal [ V_79 ] = V_198 ;
}
}
V_2 -> V_319 = F_54 ;
return F_173 ( V_4 , V_2 ) ;
}
int
F_76 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
int V_34 ;
if ( ! V_2 -> V_115 )
return 0 ;
V_34 = V_2 -> V_287 ( V_30 , 0 , V_289 ) ;
if ( V_34 )
return V_34 ;
F_231 ( V_30 , 0 , V_289 ) ;
V_2 -> V_115 = false ;
return 0 ;
}
int
F_232 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
T_3 V_32 ;
int V_34 ;
V_32 = 0 ;
if ( V_2 -> V_115 )
V_32 = V_289 ;
V_34 = V_2 -> V_287 ( V_30 , V_289 , V_32 ) ;
if ( V_34 )
return V_34 ;
F_231 ( V_30 , V_289 , V_32 ) ;
V_2 -> V_115 = false ;
return 0 ;
}
void
F_184 ( struct V_1 * V_2 )
{
int V_34 ;
if ( ! F_1 ( V_2 ) )
return;
V_34 = F_192 ( V_2 ) ;
if ( V_34 && ! F_233 ( & F_45 ( V_2 -> V_4 ) -> V_26 ) )
F_43 ( L_28 ,
V_2 -> V_90 , V_34 ) ;
F_44 ( V_2 ) ;
}
