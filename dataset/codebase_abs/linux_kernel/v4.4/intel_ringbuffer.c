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
if ( V_112 -> V_114 == 0 )
return 0 ;
V_2 -> V_115 = true ;
V_34 = F_75 ( V_30 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_9 ( V_30 , ( V_112 -> V_114 * 2 + 2 ) ) ;
if ( V_34 )
return V_34 ;
F_10 ( V_2 , F_76 ( V_112 -> V_114 ) ) ;
for ( V_110 = 0 ; V_110 < V_112 -> V_114 ; V_110 ++ ) {
F_10 ( V_2 , V_112 -> V_86 [ V_110 ] . V_70 ) ;
F_10 ( V_2 , V_112 -> V_86 [ V_110 ] . V_65 ) ;
}
F_10 ( V_2 , V_40 ) ;
F_11 ( V_2 ) ;
V_2 -> V_115 = true ;
V_34 = F_75 ( V_30 ) ;
if ( V_34 )
return V_34 ;
F_73 ( L_11 , V_112 -> V_114 ) ;
return 0 ;
}
static int F_77 ( struct V_29 * V_30 )
{
int V_34 ;
V_34 = F_74 ( V_30 ) ;
if ( V_34 != 0 )
return V_34 ;
V_34 = F_78 ( V_30 ) ;
if ( V_34 )
F_43 ( L_12 , V_34 ) ;
return V_34 ;
}
static int F_79 ( struct V_23 * V_24 ,
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
static int F_80 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
F_81 ( V_121 , V_122 ) ;
F_81 ( V_123 , V_124 ) ;
F_81 ( V_125 ,
V_126 ) ;
F_81 ( V_127 ,
V_128 |
V_129 ) ;
F_82 ( V_130 , V_131 ) ;
F_81 ( V_132 , V_133 ) ;
F_83 ( V_134 ,
V_135 ,
V_136 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 )
{
int V_34 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
V_34 = F_80 ( V_2 ) ;
if ( V_34 )
return V_34 ;
F_81 ( V_125 , V_137 ) ;
F_81 ( V_138 ,
V_139 ) ;
F_81 ( V_140 ,
V_141 ) ;
F_81 ( V_127 ,
V_142 |
( F_85 ( V_4 ) ? V_143 : 0 ) ) ;
return 0 ;
}
static int F_86 ( struct V_1 * V_2 )
{
int V_34 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
V_34 = F_80 ( V_2 ) ;
if ( V_34 )
return V_34 ;
F_81 ( V_125 , V_137 ) ;
F_81 ( V_144 , V_145 ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
T_3 V_146 ;
F_31 ( V_147 , F_29 ( V_147 ) |
V_148 ) ;
F_31 ( V_149 , F_29 ( V_149 ) |
V_150 ) ;
F_81 ( V_125 ,
V_126 ) ;
F_81 ( V_140 ,
V_151 ) ;
if ( ( F_88 ( V_4 ) && ( F_89 ( V_4 ) == V_152 ||
F_89 ( V_4 ) == V_153 ) ) ||
( F_90 ( V_4 ) && F_89 ( V_4 ) < V_154 ) ) {
F_82 ( V_155 ,
V_156 ) ;
}
if ( ( F_88 ( V_4 ) && F_89 ( V_4 ) <= V_153 ) ||
( F_90 ( V_4 ) && F_89 ( V_4 ) < V_154 ) ) {
F_81 ( V_157 ,
V_158 ) ;
}
if ( ( F_88 ( V_4 ) && F_89 ( V_4 ) >= V_159 ) ||
F_90 ( V_4 ) ) {
F_81 ( V_160 ,
V_161 ) ;
}
F_81 ( V_132 , ( V_133 |
V_162 ) ) ;
F_82 ( V_155 ,
V_163 ) ;
if ( ( F_88 ( V_4 ) && F_89 ( V_4 ) == V_159 ) ||
( F_90 ( V_4 ) && F_89 ( V_4 ) < V_154 ) )
F_81 ( V_164 ,
V_165 ) ;
V_146 = V_142 ;
if ( ( F_88 ( V_4 ) && F_89 ( V_4 ) == V_166 ) ||
( F_90 ( V_4 ) && F_89 ( V_4 ) >= V_154 ) )
V_146 |= V_167 ;
F_81 ( V_127 , V_146 ) ;
if ( F_88 ( V_4 ) ||
( F_90 ( V_4 ) && F_89 ( V_4 ) <= V_154 ) ) {
F_81 ( V_140 ,
V_141 ) ;
}
F_81 ( V_168 , V_169 ) ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
T_4 V_170 [ 3 ] = { 0 , 0 , 0 } ;
unsigned int V_110 ;
for ( V_110 = 0 ; V_110 < 3 ; V_110 ++ ) {
T_4 V_171 ;
if ( F_92 ( V_24 -> V_172 . V_173 [ V_110 ] ) != 1 )
continue;
V_171 = F_93 ( V_24 -> V_172 . V_173 [ V_110 ] ) - 1 ;
V_170 [ V_110 ] = 3 - V_171 ;
}
if ( V_170 [ 0 ] == 0 && V_170 [ 1 ] == 0 && V_170 [ 2 ] == 0 )
return 0 ;
F_83 ( V_134 ,
F_94 ( 2 ) |
F_94 ( 1 ) |
F_94 ( 0 ) ,
F_95 ( 2 , V_170 [ 2 ] ) |
F_95 ( 1 , V_170 [ 1 ] ) |
F_95 ( 0 , V_170 [ 0 ] ) ) ;
return 0 ;
}
static int F_96 ( struct V_1 * V_2 )
{
int V_34 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
V_34 = F_87 ( V_2 ) ;
if ( V_34 )
return V_34 ;
if ( F_89 ( V_4 ) <= V_174 ) {
F_31 ( V_149 , F_29 ( V_149 ) |
V_175 ) ;
F_31 ( V_176 ,
F_41 ( V_177 ) ) ;
}
if ( F_89 ( V_4 ) <= V_178 )
F_31 ( V_179 , F_29 ( V_179 ) |
V_180 ) ;
if ( F_88 ( V_4 ) && ( F_89 ( V_4 ) >= V_159 ) ) {
F_31 ( V_181 , ( F_29 ( V_181 ) |
V_182 ) ) ;
}
if ( F_89 ( V_4 ) == V_153 )
F_81 ( V_144 ,
V_183 ) ;
if ( F_89 ( V_4 ) <= V_174 ) {
F_81 ( V_127 ,
V_129 ) ;
}
if ( F_89 ( V_4 ) == V_159 ||
F_89 ( V_4 ) == V_174 )
F_81 ( V_127 ,
V_143 |
V_184 ) ;
if ( F_89 ( V_4 ) <= V_166 ) {
F_81 (
V_185 ,
V_186 ) ;
}
return F_91 ( V_2 ) ;
}
static int F_97 ( struct V_1 * V_2 )
{
int V_34 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
V_34 = F_87 ( V_2 ) ;
if ( V_34 )
return V_34 ;
if ( F_89 ( V_4 ) == V_187 )
F_31 ( V_188 , F_29 ( V_188 ) | V_189 ) ;
if ( F_89 ( V_4 ) == V_187 ) {
F_31 ( V_190 , ( F_29 ( V_190 ) &
~ V_191 ) ) ;
}
F_81 ( V_125 ,
V_137 ) ;
if ( F_89 ( V_4 ) <= V_154 ) {
F_81 (
V_185 ,
V_186 ) ;
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
return F_84 ( V_2 ) ;
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
F_31 ( V_123 , F_41 ( V_192 ) ) ;
if ( F_25 ( V_4 ) -> V_67 >= 6 && F_25 ( V_4 ) -> V_67 < 8 )
F_31 ( V_123 , F_41 ( V_124 ) ) ;
if ( F_25 ( V_4 ) -> V_67 == 6 )
F_31 ( V_193 ,
F_41 ( V_194 ) ) ;
if ( F_33 ( V_4 ) )
F_31 ( V_195 ,
F_41 ( V_194 ) |
F_41 ( V_196 ) ) ;
if ( F_34 ( V_4 ) ) {
F_31 ( V_197 ,
F_53 ( V_198 ) ) ;
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
if ( V_24 -> V_199 ) {
F_66 ( V_24 -> V_199 ) ;
F_67 ( & V_24 -> V_199 -> V_103 ) ;
V_24 -> V_199 = NULL ;
}
F_63 ( V_2 ) ;
}
static int F_106 ( struct V_29 * V_200 ,
unsigned int V_201 )
{
#define F_107 8
struct V_1 * V_202 = V_200 -> V_2 ;
struct V_3 * V_4 = V_202 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_203 ;
int V_110 , V_34 , V_204 ;
V_204 = F_108 ( F_25 ( V_4 ) -> V_205 ) ;
V_201 += ( V_204 - 1 ) * F_107 ;
#undef F_107
V_34 = F_9 ( V_200 , V_201 ) ;
if ( V_34 )
return V_34 ;
F_109 (waiter, dev_priv, i) {
T_1 V_206 ;
T_2 V_47 = V_202 -> V_207 . V_208 [ V_110 ] ;
if ( V_47 == V_209 )
continue;
V_206 = F_110 ( V_200 ) ;
F_10 ( V_202 , F_16 ( 6 ) ) ;
F_10 ( V_202 , V_64 |
V_52 |
V_62 ) ;
F_10 ( V_202 , F_111 ( V_47 ) ) ;
F_10 ( V_202 , F_112 ( V_47 ) ) ;
F_10 ( V_202 , V_206 ) ;
F_10 ( V_202 , 0 ) ;
F_10 ( V_202 , V_210 |
F_113 ( V_203 -> V_13 ) ) ;
F_10 ( V_202 , 0 ) ;
}
return 0 ;
}
static int F_114 ( struct V_29 * V_200 ,
unsigned int V_201 )
{
#define F_107 6
struct V_1 * V_202 = V_200 -> V_2 ;
struct V_3 * V_4 = V_202 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_203 ;
int V_110 , V_34 , V_204 ;
V_204 = F_108 ( F_25 ( V_4 ) -> V_205 ) ;
V_201 += ( V_204 - 1 ) * F_107 ;
#undef F_107
V_34 = F_9 ( V_200 , V_201 ) ;
if ( V_34 )
return V_34 ;
F_109 (waiter, dev_priv, i) {
T_1 V_206 ;
T_2 V_47 = V_202 -> V_207 . V_208 [ V_110 ] ;
if ( V_47 == V_209 )
continue;
V_206 = F_110 ( V_200 ) ;
F_10 ( V_202 , ( V_211 + 1 ) |
V_212 ) ;
F_10 ( V_202 , F_111 ( V_47 ) |
V_213 ) ;
F_10 ( V_202 , F_112 ( V_47 ) ) ;
F_10 ( V_202 , V_206 ) ;
F_10 ( V_202 , V_210 |
F_113 ( V_203 -> V_13 ) ) ;
F_10 ( V_202 , 0 ) ;
}
return 0 ;
}
static int F_115 ( struct V_29 * V_200 ,
unsigned int V_201 )
{
struct V_1 * V_202 = V_200 -> V_2 ;
struct V_3 * V_4 = V_202 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_214 ;
int V_110 , V_34 , V_204 ;
#define F_107 3
V_204 = F_108 ( F_25 ( V_4 ) -> V_205 ) ;
V_201 += F_116 ( ( V_204 - 1 ) * F_107 , 2 ) ;
#undef F_107
V_34 = F_9 ( V_200 , V_201 ) ;
if ( V_34 )
return V_34 ;
F_109 (useless, dev_priv, i) {
T_1 V_215 = V_202 -> V_207 . V_216 . signal [ V_110 ] ;
if ( V_215 != V_217 ) {
T_1 V_206 = F_110 ( V_200 ) ;
F_10 ( V_202 , F_76 ( 1 ) ) ;
F_10 ( V_202 , V_215 ) ;
F_10 ( V_202 , V_206 ) ;
}
}
if ( V_204 % 2 == 0 )
F_10 ( V_202 , V_40 ) ;
return 0 ;
}
static int
F_117 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
int V_34 ;
if ( V_2 -> V_207 . signal )
V_34 = V_2 -> V_207 . signal ( V_30 , 4 ) ;
else
V_34 = F_9 ( V_30 , 4 ) ;
if ( V_34 )
return V_34 ;
F_10 ( V_2 , V_218 ) ;
F_10 ( V_2 , V_219 << V_220 ) ;
F_10 ( V_2 , F_110 ( V_30 ) ) ;
F_10 ( V_2 , V_221 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static inline bool F_118 ( struct V_3 * V_4 ,
T_1 V_206 )
{
struct V_23 * V_24 = V_4 -> V_25 ;
return V_24 -> V_222 < V_206 ;
}
static int
F_119 ( struct V_29 * V_223 ,
struct V_1 * V_202 ,
T_1 V_206 )
{
struct V_1 * V_203 = V_223 -> V_2 ;
struct V_23 * V_24 = V_203 -> V_4 -> V_25 ;
int V_34 ;
V_34 = F_9 ( V_223 , 4 ) ;
if ( V_34 )
return V_34 ;
F_10 ( V_203 , V_224 |
V_225 |
V_226 |
V_227 ) ;
F_10 ( V_203 , V_206 ) ;
F_10 ( V_203 ,
F_111 ( F_120 ( V_203 , V_202 -> V_13 ) ) ) ;
F_10 ( V_203 ,
F_112 ( F_120 ( V_203 , V_202 -> V_13 ) ) ) ;
F_11 ( V_203 ) ;
return 0 ;
}
static int
F_121 ( struct V_29 * V_223 ,
struct V_1 * V_202 ,
T_1 V_206 )
{
struct V_1 * V_203 = V_223 -> V_2 ;
T_1 V_228 = V_229 |
V_230 |
V_231 ;
T_1 V_232 = V_202 -> V_207 . V_216 . V_233 [ V_203 -> V_13 ] ;
int V_34 ;
V_206 -= 1 ;
F_39 ( V_232 == V_209 ) ;
V_34 = F_9 ( V_223 , 4 ) ;
if ( V_34 )
return V_34 ;
if ( F_122 ( ! F_118 ( V_203 -> V_4 , V_206 ) ) ) {
F_10 ( V_203 , V_228 | V_232 ) ;
F_10 ( V_203 , V_206 ) ;
F_10 ( V_203 , 0 ) ;
F_10 ( V_203 , V_40 ) ;
} else {
F_10 ( V_203 , V_40 ) ;
F_10 ( V_203 , V_40 ) ;
F_10 ( V_203 , V_40 ) ;
F_10 ( V_203 , V_40 ) ;
}
F_11 ( V_203 ) ;
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
V_234 |
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
V_234 |
V_58 |
V_235 ) ;
F_10 ( V_2 , V_2 -> V_46 . V_47 | V_51 ) ;
F_10 ( V_2 , F_110 ( V_30 ) ) ;
F_10 ( V_2 , 0 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static T_1
F_125 ( struct V_1 * V_2 , bool V_236 )
{
if ( ! V_236 ) {
struct V_23 * V_24 = V_2 -> V_4 -> V_25 ;
F_37 ( F_27 ( V_2 -> V_68 ) ) ;
}
return F_126 ( V_2 , V_219 ) ;
}
static T_1
F_127 ( struct V_1 * V_2 , bool V_236 )
{
return F_126 ( V_2 , V_219 ) ;
}
static void
F_128 ( struct V_1 * V_2 , T_1 V_206 )
{
F_129 ( V_2 , V_219 , V_206 ) ;
}
static T_1
F_130 ( struct V_1 * V_2 , bool V_236 )
{
return V_2 -> V_46 . V_108 [ 0 ] ;
}
static void
F_131 ( struct V_1 * V_2 , T_1 V_206 )
{
V_2 -> V_46 . V_108 [ 0 ] = V_206 ;
}
static bool
F_132 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_53 ;
if ( F_39 ( ! F_133 ( V_24 ) ) )
return false ;
F_134 ( & V_24 -> V_237 , V_53 ) ;
if ( V_2 -> V_238 ++ == 0 )
F_135 ( V_24 , V_2 -> V_239 ) ;
F_136 ( & V_24 -> V_237 , V_53 ) ;
return true ;
}
static void
F_137 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_53 ;
F_134 ( & V_24 -> V_237 , V_53 ) ;
if ( -- V_2 -> V_238 == 0 )
F_138 ( V_24 , V_2 -> V_239 ) ;
F_136 ( & V_24 -> V_237 , V_53 ) ;
}
static bool
F_139 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_53 ;
if ( ! F_133 ( V_24 ) )
return false ;
F_134 ( & V_24 -> V_237 , V_53 ) ;
if ( V_2 -> V_238 ++ == 0 ) {
V_24 -> V_240 &= ~ V_2 -> V_239 ;
F_31 ( V_241 , V_24 -> V_240 ) ;
F_37 ( V_241 ) ;
}
F_136 ( & V_24 -> V_237 , V_53 ) ;
return true ;
}
static void
F_140 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_53 ;
F_134 ( & V_24 -> V_237 , V_53 ) ;
if ( -- V_2 -> V_238 == 0 ) {
V_24 -> V_240 |= V_2 -> V_239 ;
F_31 ( V_241 , V_24 -> V_240 ) ;
F_37 ( V_241 ) ;
}
F_136 ( & V_24 -> V_237 , V_53 ) ;
}
static bool
F_141 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_53 ;
if ( ! F_133 ( V_24 ) )
return false ;
F_134 ( & V_24 -> V_237 , V_53 ) ;
if ( V_2 -> V_238 ++ == 0 ) {
V_24 -> V_240 &= ~ V_2 -> V_239 ;
F_142 ( V_241 , V_24 -> V_240 ) ;
F_143 ( V_241 ) ;
}
F_136 ( & V_24 -> V_237 , V_53 ) ;
return true ;
}
static void
F_144 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_53 ;
F_134 ( & V_24 -> V_237 , V_53 ) ;
if ( -- V_2 -> V_238 == 0 ) {
V_24 -> V_240 |= V_2 -> V_239 ;
F_142 ( V_241 , V_24 -> V_240 ) ;
F_143 ( V_241 ) ;
}
F_136 ( & V_24 -> V_237 , V_53 ) ;
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
F_10 ( V_2 , V_218 ) ;
F_10 ( V_2 , V_219 << V_220 ) ;
F_10 ( V_2 , F_110 ( V_30 ) ) ;
F_10 ( V_2 , V_221 ) ;
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
F_134 ( & V_24 -> V_237 , V_53 ) ;
if ( V_2 -> V_238 ++ == 0 ) {
if ( F_102 ( V_4 ) && V_2 -> V_13 == V_75 )
F_103 ( V_2 ,
~ ( V_2 -> V_239 |
F_104 ( V_4 ) ) ) ;
else
F_103 ( V_2 , ~ V_2 -> V_239 ) ;
F_135 ( V_24 , V_2 -> V_239 ) ;
}
F_136 ( & V_24 -> V_237 , V_53 ) ;
return true ;
}
static void
F_148 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_53 ;
F_134 ( & V_24 -> V_237 , V_53 ) ;
if ( -- V_2 -> V_238 == 0 ) {
if ( F_102 ( V_4 ) && V_2 -> V_13 == V_75 )
F_103 ( V_2 , ~ F_104 ( V_4 ) ) ;
else
F_103 ( V_2 , ~ 0 ) ;
F_138 ( V_24 , V_2 -> V_239 ) ;
}
F_136 ( & V_24 -> V_237 , V_53 ) ;
}
static bool
F_149 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_53 ;
if ( F_39 ( ! F_133 ( V_24 ) ) )
return false ;
F_134 ( & V_24 -> V_237 , V_53 ) ;
if ( V_2 -> V_238 ++ == 0 ) {
F_103 ( V_2 , ~ V_2 -> V_239 ) ;
F_150 ( V_24 , V_2 -> V_239 ) ;
}
F_136 ( & V_24 -> V_237 , V_53 ) ;
return true ;
}
static void
F_151 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_53 ;
F_134 ( & V_24 -> V_237 , V_53 ) ;
if ( -- V_2 -> V_238 == 0 ) {
F_103 ( V_2 , ~ 0 ) ;
F_152 ( V_24 , V_2 -> V_239 ) ;
}
F_136 ( & V_24 -> V_237 , V_53 ) ;
}
static bool
F_153 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_53 ;
if ( F_39 ( ! F_133 ( V_24 ) ) )
return false ;
F_134 ( & V_24 -> V_237 , V_53 ) ;
if ( V_2 -> V_238 ++ == 0 ) {
if ( F_102 ( V_4 ) && V_2 -> V_13 == V_75 ) {
F_103 ( V_2 ,
~ ( V_2 -> V_239 |
V_242 ) ) ;
} else {
F_103 ( V_2 , ~ V_2 -> V_239 ) ;
}
F_37 ( F_154 ( V_2 -> V_68 ) ) ;
}
F_136 ( & V_24 -> V_237 , V_53 ) ;
return true ;
}
static void
F_155 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_53 ;
F_134 ( & V_24 -> V_237 , V_53 ) ;
if ( -- V_2 -> V_238 == 0 ) {
if ( F_102 ( V_4 ) && V_2 -> V_13 == V_75 ) {
F_103 ( V_2 ,
~ V_242 ) ;
} else {
F_103 ( V_2 , ~ 0 ) ;
}
F_37 ( F_154 ( V_2 -> V_68 ) ) ;
}
F_136 ( & V_24 -> V_237 , V_53 ) ;
}
static int
F_156 ( struct V_29 * V_30 ,
T_2 V_243 , T_1 V_244 ,
unsigned V_245 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
int V_34 ;
V_34 = F_9 ( V_30 , 2 ) ;
if ( V_34 )
return V_34 ;
F_10 ( V_2 ,
V_246 |
V_247 |
( V_245 & V_248 ?
0 : V_249 ) ) ;
F_10 ( V_2 , V_243 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_157 ( struct V_29 * V_30 ,
T_2 V_243 , T_1 V_250 ,
unsigned V_245 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
T_1 V_251 = V_2 -> V_46 . V_47 ;
int V_34 ;
V_34 = F_9 ( V_30 , 6 ) ;
if ( V_34 )
return V_34 ;
F_10 ( V_2 , V_252 | V_253 ) ;
F_10 ( V_2 , V_254 | V_255 | 4096 ) ;
F_10 ( V_2 , V_256 << 16 | 4 ) ;
F_10 ( V_2 , V_251 ) ;
F_10 ( V_2 , 0xdeadbeef ) ;
F_10 ( V_2 , V_40 ) ;
F_11 ( V_2 ) ;
if ( ( V_245 & V_257 ) == 0 ) {
if ( V_250 > V_258 )
return - V_120 ;
V_34 = F_9 ( V_30 , 6 + 2 ) ;
if ( V_34 )
return V_34 ;
F_10 ( V_2 , V_259 | V_253 ) ;
F_10 ( V_2 , V_254 | V_260 | 4096 ) ;
F_10 ( V_2 , F_158 ( V_250 , 4096 ) << 16 | 4096 ) ;
F_10 ( V_2 , V_251 ) ;
F_10 ( V_2 , 4096 ) ;
F_10 ( V_2 , V_243 ) ;
F_10 ( V_2 , V_35 ) ;
F_10 ( V_2 , V_40 ) ;
F_11 ( V_2 ) ;
V_243 = V_251 ;
}
V_34 = F_9 ( V_30 , 4 ) ;
if ( V_34 )
return V_34 ;
F_10 ( V_2 , V_261 ) ;
F_10 ( V_2 , V_243 | ( V_245 & V_248 ?
0 : V_262 ) ) ;
F_10 ( V_2 , V_243 + V_250 - 8 ) ;
F_10 ( V_2 , V_40 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_159 ( struct V_29 * V_30 ,
T_2 V_243 , T_1 V_250 ,
unsigned V_245 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
int V_34 ;
V_34 = F_9 ( V_30 , 2 ) ;
if ( V_34 )
return V_34 ;
F_10 ( V_2 , V_246 | V_247 ) ;
F_10 ( V_2 , V_243 | ( V_245 & V_248 ?
0 : V_262 ) ) ;
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
V_53 |= V_263 ;
V_34 = F_71 ( V_14 , 4096 , V_53 ) ;
if ( V_34 ) {
V_107:
F_67 ( & V_14 -> V_103 ) ;
return V_34 ;
}
V_2 -> V_84 . V_14 = V_14 ;
}
V_2 -> V_84 . V_85 = F_60 ( V_14 ) ;
V_2 -> V_84 . V_264 = F_72 ( F_65 ( V_14 -> V_101 -> V_102 ) ) ;
memset ( V_2 -> V_84 . V_264 , 0 , V_96 ) ;
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
V_2 -> V_84 . V_264 = V_24 -> V_71 -> V_265 ;
memset ( V_2 -> V_84 . V_264 , 0 , V_96 ) ;
return 0 ;
}
void F_165 ( struct V_10 * V_11 )
{
F_166 ( V_11 -> V_266 ) ;
V_11 -> V_266 = NULL ;
F_66 ( V_11 -> V_14 ) ;
}
int F_167 ( struct V_3 * V_4 ,
struct V_10 * V_11 )
{
struct V_23 * V_24 = F_45 ( V_4 ) ;
struct V_92 * V_14 = V_11 -> V_14 ;
int V_34 ;
V_34 = F_71 ( V_14 , V_96 , V_263 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_168 ( V_14 , true ) ;
if ( V_34 ) {
F_66 ( V_14 ) ;
return V_34 ;
}
V_11 -> V_266 = F_169 ( V_24 -> V_267 . V_268 +
F_60 ( V_14 ) , V_11 -> V_18 ) ;
if ( V_11 -> V_266 == NULL ) {
F_66 ( V_14 ) ;
return - V_269 ;
}
return 0 ;
}
static void F_170 ( struct V_10 * V_11 )
{
F_67 ( & V_11 -> V_14 -> V_103 ) ;
V_11 -> V_14 = NULL ;
}
static int F_171 ( struct V_3 * V_4 ,
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
V_14 -> V_270 = 1 ;
V_11 -> V_14 = V_14 ;
return 0 ;
}
struct V_10 *
F_173 ( struct V_1 * V_12 , int V_18 )
{
struct V_10 * V_2 ;
int V_34 ;
V_2 = F_174 ( sizeof( * V_2 ) , V_271 ) ;
if ( V_2 == NULL )
return F_175 ( - V_104 ) ;
V_2 -> V_2 = V_12 ;
V_2 -> V_18 = V_18 ;
V_2 -> V_272 = V_18 ;
if ( F_176 ( V_12 -> V_4 ) || F_177 ( V_12 -> V_4 ) )
V_2 -> V_272 -= 2 * V_48 ;
V_2 -> V_21 = - 1 ;
F_3 ( V_2 ) ;
V_34 = F_171 ( V_12 -> V_4 , V_2 ) ;
if ( V_34 ) {
F_43 ( L_15 ,
V_12 -> V_90 , V_34 ) ;
F_178 ( V_2 ) ;
return F_175 ( V_34 ) ;
}
return V_2 ;
}
void
F_179 ( struct V_10 * V_2 )
{
F_170 ( V_2 ) ;
F_178 ( V_2 ) ;
}
static int F_180 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_34 ;
F_39 ( V_2 -> V_15 ) ;
V_2 -> V_4 = V_4 ;
F_181 ( & V_2 -> V_273 ) ;
F_181 ( & V_2 -> V_274 ) ;
F_181 ( & V_2 -> V_275 ) ;
F_182 ( V_4 , & V_2 -> V_276 ) ;
memset ( V_2 -> V_207 . V_277 , 0 , sizeof( V_2 -> V_207 . V_277 ) ) ;
F_183 ( & V_2 -> V_278 ) ;
V_11 = F_173 ( V_2 , 32 * V_96 ) ;
if ( F_184 ( V_11 ) )
return F_185 ( V_11 ) ;
V_2 -> V_15 = V_11 ;
if ( F_58 ( V_4 ) ) {
V_34 = F_161 ( V_2 ) ;
if ( V_34 )
goto error;
} else {
F_186 ( V_2 -> V_13 != V_75 ) ;
V_34 = F_163 ( V_2 ) ;
if ( V_34 )
goto error;
}
V_34 = F_167 ( V_4 , V_11 ) ;
if ( V_34 ) {
F_43 ( L_16 ,
V_2 -> V_90 , V_34 ) ;
F_170 ( V_11 ) ;
goto error;
}
V_34 = F_187 ( V_2 ) ;
if ( V_34 )
goto error;
return 0 ;
error:
F_179 ( V_11 ) ;
V_2 -> V_15 = NULL ;
return V_34 ;
}
void F_188 ( struct V_1 * V_2 )
{
struct V_23 * V_24 ;
if ( ! F_1 ( V_2 ) )
return;
V_24 = F_45 ( V_2 -> V_4 ) ;
F_189 ( V_2 ) ;
F_39 ( ! F_46 ( V_2 -> V_4 ) && ( F_40 ( V_2 ) & V_87 ) == 0 ) ;
F_165 ( V_2 -> V_15 ) ;
F_179 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
if ( V_2 -> V_279 )
V_2 -> V_279 ( V_2 ) ;
F_160 ( V_2 ) ;
F_190 ( V_2 ) ;
F_191 ( & V_2 -> V_276 ) ;
}
static int F_192 ( struct V_1 * V_2 , int V_280 )
{
struct V_10 * V_11 = V_2 -> V_15 ;
struct V_29 * V_281 ;
unsigned V_19 ;
int V_34 ;
if ( F_4 ( V_11 ) >= V_280 )
return 0 ;
F_39 ( V_11 -> V_282 ) ;
F_193 (request, &ring->request_list, list) {
V_19 = F_2 ( V_281 -> V_283 , V_11 -> V_17 ,
V_11 -> V_18 ) ;
if ( V_19 >= V_280 )
break;
}
if ( F_39 ( & V_281 -> V_284 == & V_2 -> V_274 ) )
return - V_120 ;
V_34 = F_194 ( V_281 ) ;
if ( V_34 )
return V_34 ;
V_11 -> V_19 = V_19 ;
return 0 ;
}
static void F_195 ( struct V_10 * V_11 )
{
T_3 T_5 * V_285 ;
int V_286 = V_11 -> V_18 - V_11 -> V_17 ;
V_285 = V_11 -> V_266 + V_11 -> V_17 ;
V_286 /= 4 ;
while ( V_286 -- )
F_196 ( V_40 , V_285 ++ ) ;
V_11 -> V_17 = 0 ;
F_3 ( V_11 ) ;
}
int F_197 ( struct V_1 * V_2 )
{
struct V_29 * V_30 ;
if ( F_198 ( & V_2 -> V_274 ) )
return 0 ;
V_30 = F_199 ( V_2 -> V_274 . V_287 ,
struct V_29 ,
V_284 ) ;
return F_200 ( V_30 ,
F_201 ( & F_45 ( V_2 -> V_4 ) -> V_26 . V_288 ) ,
F_45 ( V_2 -> V_4 ) -> V_289 . V_290 ,
NULL , NULL ) ;
}
int F_202 ( struct V_29 * V_281 )
{
V_281 -> V_11 = V_281 -> V_2 -> V_15 ;
return 0 ;
}
int F_203 ( struct V_29 * V_281 )
{
F_204 ( V_281 -> V_11 , V_291 ) ;
return F_9 ( V_281 , 0 ) ;
}
void F_204 ( struct V_10 * V_11 , int V_18 )
{
F_39 ( V_11 -> V_292 ) ;
F_39 ( V_11 -> V_282 ) ;
V_11 -> V_292 = V_18 ;
}
void F_205 ( struct V_10 * V_11 )
{
F_39 ( V_11 -> V_282 ) ;
V_11 -> V_292 = 0 ;
V_11 -> V_282 = false ;
}
void F_206 ( struct V_10 * V_11 )
{
F_39 ( V_11 -> V_282 ) ;
V_11 -> V_282 = true ;
V_11 -> V_293 = V_11 -> V_17 ;
}
void F_207 ( struct V_10 * V_11 )
{
F_39 ( ! V_11 -> V_282 ) ;
if ( V_11 -> V_17 > V_11 -> V_293 ) {
F_208 ( V_11 -> V_17 > V_11 -> V_293 + V_11 -> V_292 ,
L_17 ,
V_11 -> V_17 - V_11 -> V_293 , V_11 -> V_292 ) ;
} else {
}
V_11 -> V_292 = 0 ;
V_11 -> V_282 = false ;
}
static int F_209 ( struct V_1 * V_2 , int V_294 )
{
struct V_10 * V_11 = V_2 -> V_15 ;
int V_295 = V_11 -> V_272 - V_11 -> V_17 ;
int V_296 = V_11 -> V_18 - V_11 -> V_17 ;
int V_34 , V_297 , V_298 = 0 ;
bool V_299 = false ;
if ( V_11 -> V_282 )
V_297 = V_294 ;
else
V_297 = V_294 + V_11 -> V_292 ;
if ( F_210 ( V_294 > V_295 ) ) {
V_298 = V_296 + V_297 ;
V_299 = true ;
} else {
if ( F_210 ( V_297 > V_295 ) ) {
V_298 = V_296 + V_11 -> V_292 ;
V_299 = true ;
} else if ( V_297 > V_11 -> V_19 ) {
V_298 = V_297 ;
}
}
if ( V_298 ) {
V_34 = F_192 ( V_2 , V_298 ) ;
if ( F_210 ( V_34 ) )
return V_34 ;
if ( V_299 )
F_195 ( V_11 ) ;
}
return 0 ;
}
int F_9 ( struct V_29 * V_30 ,
int V_201 )
{
struct V_1 * V_2 ;
struct V_23 * V_24 ;
int V_34 ;
F_39 ( V_30 == NULL ) ;
V_2 = V_30 -> V_2 ;
V_24 = V_2 -> V_4 -> V_25 ;
V_34 = F_211 ( & V_24 -> V_26 ,
V_24 -> V_289 . V_290 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_209 ( V_2 , V_201 * sizeof( T_3 ) ) ;
if ( V_34 )
return V_34 ;
V_2 -> V_15 -> V_19 -= V_201 * sizeof( T_3 ) ;
return 0 ;
}
int F_212 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
int V_201 = ( V_2 -> V_15 -> V_17 & ( V_48 - 1 ) ) / sizeof( T_3 ) ;
int V_34 ;
if ( V_201 == 0 )
return 0 ;
V_201 = V_48 / sizeof( T_3 ) - V_201 ;
V_34 = F_9 ( V_30 , V_201 ) ;
if ( V_34 )
return V_34 ;
while ( V_201 -- )
F_10 ( V_2 , V_40 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
void F_213 ( struct V_1 * V_2 , T_1 V_206 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
if ( F_25 ( V_4 ) -> V_67 == 6 || F_25 ( V_4 ) -> V_67 == 7 ) {
F_31 ( F_214 ( V_2 -> V_68 ) , 0 ) ;
F_31 ( F_215 ( V_2 -> V_68 ) , 0 ) ;
if ( F_216 ( V_4 ) )
F_31 ( F_217 ( V_2 -> V_68 ) , 0 ) ;
}
V_2 -> V_300 ( V_2 , V_206 ) ;
V_2 -> V_100 . V_206 = V_206 ;
}
static void F_218 ( struct V_1 * V_2 ,
T_1 V_65 )
{
struct V_23 * V_24 = V_2 -> V_4 -> V_25 ;
F_31 ( V_301 ,
F_41 ( V_302 ) ) ;
F_219 ( V_303 , 0x0 ) ;
if ( F_42 ( ( F_29 ( V_301 ) &
V_304 ) == 0 ,
50 ) )
F_43 ( L_18 ) ;
F_23 ( V_2 , V_65 ) ;
F_37 ( F_220 ( V_2 -> V_68 ) ) ;
F_31 ( V_301 ,
F_53 ( V_302 ) ) ;
}
static int F_221 ( struct V_29 * V_30 ,
T_1 V_305 , T_1 V_306 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
T_3 V_33 ;
int V_34 ;
V_34 = F_9 ( V_30 , 4 ) ;
if ( V_34 )
return V_34 ;
V_33 = V_211 ;
if ( F_25 ( V_2 -> V_4 ) -> V_67 >= 8 )
V_33 += 1 ;
V_33 |= V_307 | V_212 ;
if ( V_305 & V_308 )
V_33 |= V_309 | V_310 ;
F_10 ( V_2 , V_33 ) ;
F_10 ( V_2 , V_311 | V_213 ) ;
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
F_222 ( struct V_29 * V_30 ,
T_2 V_243 , T_1 V_250 ,
unsigned V_245 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
bool V_312 = F_223 ( V_2 -> V_4 ) &&
! ( V_245 & V_248 ) ;
int V_34 ;
V_34 = F_9 ( V_30 , 4 ) ;
if ( V_34 )
return V_34 ;
F_10 ( V_2 , V_313 | ( V_312 << 8 ) |
( V_245 & V_314 ?
V_315 : 0 ) ) ;
F_10 ( V_2 , F_111 ( V_243 ) ) ;
F_10 ( V_2 , F_112 ( V_243 ) ) ;
F_10 ( V_2 , V_40 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_224 ( struct V_29 * V_30 ,
T_2 V_243 , T_1 V_250 ,
unsigned V_245 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
int V_34 ;
V_34 = F_9 ( V_30 , 2 ) ;
if ( V_34 )
return V_34 ;
F_10 ( V_2 ,
V_246 |
( V_245 & V_248 ?
0 : V_316 | V_317 ) |
( V_245 & V_314 ?
V_315 : 0 ) ) ;
F_10 ( V_2 , V_243 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_225 ( struct V_29 * V_30 ,
T_2 V_243 , T_1 V_250 ,
unsigned V_245 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
int V_34 ;
V_34 = F_9 ( V_30 , 2 ) ;
if ( V_34 )
return V_34 ;
F_10 ( V_2 ,
V_246 |
( V_245 & V_248 ?
0 : V_249 ) ) ;
F_10 ( V_2 , V_243 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int F_226 ( struct V_29 * V_30 ,
T_1 V_305 , T_1 V_306 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_33 ;
int V_34 ;
V_34 = F_9 ( V_30 , 4 ) ;
if ( V_34 )
return V_34 ;
V_33 = V_211 ;
if ( F_25 ( V_4 ) -> V_67 >= 8 )
V_33 += 1 ;
V_33 |= V_307 | V_212 ;
if ( V_305 & V_36 )
V_33 |= V_309 ;
F_10 ( V_2 , V_33 ) ;
F_10 ( V_2 , V_311 | V_213 ) ;
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
int F_227 ( struct V_3 * V_4 )
{
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_2 = & V_24 -> V_2 [ V_75 ] ;
struct V_92 * V_14 ;
int V_34 ;
V_2 -> V_90 = L_19 ;
V_2 -> V_13 = V_75 ;
V_2 -> V_68 = V_318 ;
if ( F_25 ( V_4 ) -> V_67 >= 8 ) {
if ( F_228 ( V_4 ) ) {
V_14 = F_69 ( V_4 , 4096 ) ;
if ( V_14 == NULL ) {
F_43 ( L_20 ) ;
V_5 . V_319 = 0 ;
} else {
F_70 ( V_14 , V_106 ) ;
V_34 = F_71 ( V_14 , 0 , V_320 ) ;
if ( V_34 != 0 ) {
F_67 ( & V_14 -> V_103 ) ;
F_43 ( L_21 ) ;
V_5 . V_319 = 0 ;
} else
V_24 -> V_199 = V_14 ;
}
}
V_2 -> V_321 = F_77 ;
V_2 -> V_322 = F_117 ;
V_2 -> V_306 = F_21 ;
V_2 -> V_323 = F_153 ;
V_2 -> V_324 = F_155 ;
V_2 -> V_239 = V_325 ;
V_2 -> V_326 = F_125 ;
V_2 -> V_300 = F_128 ;
if ( F_228 ( V_4 ) ) {
F_39 ( ! V_24 -> V_199 ) ;
V_2 -> V_207 . V_327 = F_119 ;
V_2 -> V_207 . signal = F_106 ;
V_328 ;
}
} else if ( F_25 ( V_4 ) -> V_67 >= 6 ) {
V_2 -> V_321 = F_77 ;
V_2 -> V_322 = F_117 ;
V_2 -> V_306 = F_19 ;
if ( F_25 ( V_4 ) -> V_67 == 6 )
V_2 -> V_306 = F_17 ;
V_2 -> V_323 = F_147 ;
V_2 -> V_324 = F_148 ;
V_2 -> V_239 = V_325 ;
V_2 -> V_326 = F_125 ;
V_2 -> V_300 = F_128 ;
if ( F_228 ( V_4 ) ) {
V_2 -> V_207 . V_327 = F_121 ;
V_2 -> V_207 . signal = F_115 ;
V_2 -> V_207 . V_216 . V_233 [ V_75 ] = V_209 ;
V_2 -> V_207 . V_216 . V_233 [ V_80 ] = V_329 ;
V_2 -> V_207 . V_216 . V_233 [ V_77 ] = V_330 ;
V_2 -> V_207 . V_216 . V_233 [ V_82 ] = V_331 ;
V_2 -> V_207 . V_216 . V_233 [ V_79 ] = V_209 ;
V_2 -> V_207 . V_216 . signal [ V_75 ] = V_217 ;
V_2 -> V_207 . V_216 . signal [ V_80 ] = V_332 ;
V_2 -> V_207 . V_216 . signal [ V_77 ] = V_333 ;
V_2 -> V_207 . V_216 . signal [ V_82 ] = V_334 ;
V_2 -> V_207 . V_216 . signal [ V_79 ] = V_217 ;
}
} else if ( F_14 ( V_4 ) ) {
V_2 -> V_322 = F_123 ;
V_2 -> V_306 = F_12 ;
V_2 -> V_326 = F_130 ;
V_2 -> V_300 = F_131 ;
V_2 -> V_323 = F_132 ;
V_2 -> V_324 = F_137 ;
V_2 -> V_239 = V_325 |
V_335 ;
} else {
V_2 -> V_322 = F_146 ;
if ( F_25 ( V_4 ) -> V_67 < 4 )
V_2 -> V_306 = F_8 ;
else
V_2 -> V_306 = F_12 ;
V_2 -> V_326 = F_127 ;
V_2 -> V_300 = F_128 ;
if ( F_46 ( V_4 ) ) {
V_2 -> V_323 = F_141 ;
V_2 -> V_324 = F_144 ;
} else {
V_2 -> V_323 = F_139 ;
V_2 -> V_324 = F_140 ;
}
V_2 -> V_239 = V_336 ;
}
V_2 -> V_28 = F_22 ;
if ( F_229 ( V_4 ) )
V_2 -> V_337 = F_224 ;
else if ( F_230 ( V_4 ) )
V_2 -> V_337 = F_222 ;
else if ( F_25 ( V_4 ) -> V_67 >= 6 )
V_2 -> V_337 = F_225 ;
else if ( F_25 ( V_4 ) -> V_67 >= 4 )
V_2 -> V_337 = F_156 ;
else if ( F_176 ( V_4 ) || F_177 ( V_4 ) )
V_2 -> V_337 = F_157 ;
else
V_2 -> V_337 = F_159 ;
V_2 -> V_338 = F_101 ;
V_2 -> V_279 = F_105 ;
if ( F_231 ( V_4 ) ) {
V_14 = F_69 ( V_4 , V_339 ) ;
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
V_34 = F_180 ( V_4 , V_2 ) ;
if ( V_34 )
return V_34 ;
if ( F_25 ( V_4 ) -> V_67 >= 5 ) {
V_34 = F_68 ( V_2 ) ;
if ( V_34 )
return V_34 ;
}
return 0 ;
}
int F_232 ( struct V_3 * V_4 )
{
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_2 = & V_24 -> V_2 [ V_80 ] ;
V_2 -> V_90 = L_24 ;
V_2 -> V_13 = V_80 ;
V_2 -> V_28 = F_22 ;
if ( F_25 ( V_4 ) -> V_67 >= 6 ) {
V_2 -> V_68 = V_340 ;
if ( F_34 ( V_4 ) )
V_2 -> V_28 = F_218 ;
V_2 -> V_306 = F_221 ;
V_2 -> V_322 = F_117 ;
V_2 -> V_326 = F_125 ;
V_2 -> V_300 = F_128 ;
if ( F_25 ( V_4 ) -> V_67 >= 8 ) {
V_2 -> V_239 =
V_325 << V_341 ;
V_2 -> V_323 = F_153 ;
V_2 -> V_324 = F_155 ;
V_2 -> V_337 =
F_222 ;
if ( F_228 ( V_4 ) ) {
V_2 -> V_207 . V_327 = F_119 ;
V_2 -> V_207 . signal = F_114 ;
V_328 ;
}
} else {
V_2 -> V_239 = V_342 ;
V_2 -> V_323 = F_147 ;
V_2 -> V_324 = F_148 ;
V_2 -> V_337 =
F_225 ;
if ( F_228 ( V_4 ) ) {
V_2 -> V_207 . V_327 = F_121 ;
V_2 -> V_207 . signal = F_115 ;
V_2 -> V_207 . V_216 . V_233 [ V_75 ] = V_343 ;
V_2 -> V_207 . V_216 . V_233 [ V_80 ] = V_209 ;
V_2 -> V_207 . V_216 . V_233 [ V_77 ] = V_344 ;
V_2 -> V_207 . V_216 . V_233 [ V_82 ] = V_345 ;
V_2 -> V_207 . V_216 . V_233 [ V_79 ] = V_209 ;
V_2 -> V_207 . V_216 . signal [ V_75 ] = V_346 ;
V_2 -> V_207 . V_216 . signal [ V_80 ] = V_217 ;
V_2 -> V_207 . V_216 . signal [ V_77 ] = V_347 ;
V_2 -> V_207 . V_216 . signal [ V_82 ] = V_348 ;
V_2 -> V_207 . V_216 . signal [ V_79 ] = V_217 ;
}
}
} else {
V_2 -> V_68 = V_349 ;
V_2 -> V_306 = F_145 ;
V_2 -> V_322 = F_146 ;
V_2 -> V_326 = F_127 ;
V_2 -> V_300 = F_128 ;
if ( F_14 ( V_4 ) ) {
V_2 -> V_239 = V_350 ;
V_2 -> V_323 = F_132 ;
V_2 -> V_324 = F_137 ;
} else {
V_2 -> V_239 = V_351 ;
V_2 -> V_323 = F_139 ;
V_2 -> V_324 = F_140 ;
}
V_2 -> V_337 = F_156 ;
}
V_2 -> V_338 = F_54 ;
return F_180 ( V_4 , V_2 ) ;
}
int F_233 ( struct V_3 * V_4 )
{
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_2 = & V_24 -> V_2 [ V_79 ] ;
V_2 -> V_90 = L_25 ;
V_2 -> V_13 = V_79 ;
V_2 -> V_28 = F_22 ;
V_2 -> V_68 = V_352 ;
V_2 -> V_306 = F_221 ;
V_2 -> V_322 = F_117 ;
V_2 -> V_326 = F_125 ;
V_2 -> V_300 = F_128 ;
V_2 -> V_239 =
V_325 << V_353 ;
V_2 -> V_323 = F_153 ;
V_2 -> V_324 = F_155 ;
V_2 -> V_337 =
F_222 ;
if ( F_228 ( V_4 ) ) {
V_2 -> V_207 . V_327 = F_119 ;
V_2 -> V_207 . signal = F_114 ;
V_328 ;
}
V_2 -> V_338 = F_54 ;
return F_180 ( V_4 , V_2 ) ;
}
int F_234 ( struct V_3 * V_4 )
{
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_2 = & V_24 -> V_2 [ V_77 ] ;
V_2 -> V_90 = L_26 ;
V_2 -> V_13 = V_77 ;
V_2 -> V_68 = V_354 ;
V_2 -> V_28 = F_22 ;
V_2 -> V_306 = F_226 ;
V_2 -> V_322 = F_117 ;
V_2 -> V_326 = F_125 ;
V_2 -> V_300 = F_128 ;
if ( F_25 ( V_4 ) -> V_67 >= 8 ) {
V_2 -> V_239 =
V_325 << V_355 ;
V_2 -> V_323 = F_153 ;
V_2 -> V_324 = F_155 ;
V_2 -> V_337 = F_222 ;
if ( F_228 ( V_4 ) ) {
V_2 -> V_207 . V_327 = F_119 ;
V_2 -> V_207 . signal = F_114 ;
V_328 ;
}
} else {
V_2 -> V_239 = V_356 ;
V_2 -> V_323 = F_147 ;
V_2 -> V_324 = F_148 ;
V_2 -> V_337 = F_225 ;
if ( F_228 ( V_4 ) ) {
V_2 -> V_207 . signal = F_115 ;
V_2 -> V_207 . V_327 = F_121 ;
V_2 -> V_207 . V_216 . V_233 [ V_75 ] = V_357 ;
V_2 -> V_207 . V_216 . V_233 [ V_80 ] = V_358 ;
V_2 -> V_207 . V_216 . V_233 [ V_77 ] = V_209 ;
V_2 -> V_207 . V_216 . V_233 [ V_82 ] = V_359 ;
V_2 -> V_207 . V_216 . V_233 [ V_79 ] = V_209 ;
V_2 -> V_207 . V_216 . signal [ V_75 ] = V_360 ;
V_2 -> V_207 . V_216 . signal [ V_80 ] = V_361 ;
V_2 -> V_207 . V_216 . signal [ V_77 ] = V_217 ;
V_2 -> V_207 . V_216 . signal [ V_82 ] = V_362 ;
V_2 -> V_207 . V_216 . signal [ V_79 ] = V_217 ;
}
}
V_2 -> V_338 = F_54 ;
return F_180 ( V_4 , V_2 ) ;
}
int F_235 ( struct V_3 * V_4 )
{
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_2 = & V_24 -> V_2 [ V_82 ] ;
V_2 -> V_90 = L_27 ;
V_2 -> V_13 = V_82 ;
V_2 -> V_68 = V_363 ;
V_2 -> V_28 = F_22 ;
V_2 -> V_306 = F_226 ;
V_2 -> V_322 = F_117 ;
V_2 -> V_326 = F_125 ;
V_2 -> V_300 = F_128 ;
if ( F_25 ( V_4 ) -> V_67 >= 8 ) {
V_2 -> V_239 =
V_325 << V_364 ;
V_2 -> V_323 = F_153 ;
V_2 -> V_324 = F_155 ;
V_2 -> V_337 = F_222 ;
if ( F_228 ( V_4 ) ) {
V_2 -> V_207 . V_327 = F_119 ;
V_2 -> V_207 . signal = F_114 ;
V_328 ;
}
} else {
V_2 -> V_239 = V_365 ;
V_2 -> V_323 = F_149 ;
V_2 -> V_324 = F_151 ;
V_2 -> V_337 = F_225 ;
if ( F_228 ( V_4 ) ) {
V_2 -> V_207 . V_327 = F_121 ;
V_2 -> V_207 . signal = F_115 ;
V_2 -> V_207 . V_216 . V_233 [ V_75 ] = V_366 ;
V_2 -> V_207 . V_216 . V_233 [ V_80 ] = V_367 ;
V_2 -> V_207 . V_216 . V_233 [ V_77 ] = V_368 ;
V_2 -> V_207 . V_216 . V_233 [ V_82 ] = V_209 ;
V_2 -> V_207 . V_216 . V_233 [ V_79 ] = V_209 ;
V_2 -> V_207 . V_216 . signal [ V_75 ] = V_369 ;
V_2 -> V_207 . V_216 . signal [ V_80 ] = V_370 ;
V_2 -> V_207 . V_216 . signal [ V_77 ] = V_371 ;
V_2 -> V_207 . V_216 . signal [ V_82 ] = V_217 ;
V_2 -> V_207 . V_216 . signal [ V_79 ] = V_217 ;
}
}
V_2 -> V_338 = F_54 ;
return F_180 ( V_4 , V_2 ) ;
}
int
F_75 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
int V_34 ;
if ( ! V_2 -> V_115 )
return 0 ;
V_34 = V_2 -> V_306 ( V_30 , 0 , V_308 ) ;
if ( V_34 )
return V_34 ;
F_236 ( V_30 , 0 , V_308 ) ;
V_2 -> V_115 = false ;
return 0 ;
}
int
F_237 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
T_3 V_32 ;
int V_34 ;
V_32 = 0 ;
if ( V_2 -> V_115 )
V_32 = V_308 ;
V_34 = V_2 -> V_306 ( V_30 , V_308 , V_32 ) ;
if ( V_34 )
return V_34 ;
F_236 ( V_30 , V_308 , V_32 ) ;
V_2 -> V_115 = false ;
return 0 ;
}
void
F_189 ( struct V_1 * V_2 )
{
int V_34 ;
if ( ! F_1 ( V_2 ) )
return;
V_34 = F_197 ( V_2 ) ;
if ( V_34 && ! F_238 ( & F_45 ( V_2 -> V_4 ) -> V_26 ) )
F_43 ( L_28 ,
V_2 -> V_90 , V_34 ) ;
F_44 ( V_2 ) ;
}
