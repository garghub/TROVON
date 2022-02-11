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
T_3 V_140 ;
F_82 ( V_119 ,
V_120 ) ;
F_82 ( V_124 ,
V_141 ) ;
if ( ( F_88 ( V_4 ) && ( F_89 ( V_4 ) == V_142 ||
F_89 ( V_4 ) == V_143 ) ) ||
( F_90 ( V_4 ) && F_89 ( V_4 ) < V_144 ) ) {
F_84 ( V_145 ,
V_146 ) ;
}
if ( ( F_88 ( V_4 ) && F_89 ( V_4 ) <= V_143 ) ||
( F_90 ( V_4 ) && F_89 ( V_4 ) < V_144 ) ) {
F_82 ( V_147 ,
V_148 ) ;
F_82 ( V_149 ,
V_150 ) ;
}
if ( ( F_88 ( V_4 ) && F_89 ( V_4 ) >= V_151 ) ||
F_90 ( V_4 ) ) {
F_82 ( V_152 ,
V_153 ) ;
}
F_82 ( V_133 , V_134 ) ;
F_82 ( V_133 , V_154 ) ;
F_84 ( V_145 ,
V_155 ) ;
if ( ( F_88 ( V_4 ) && F_89 ( V_4 ) == V_151 ) ||
( F_90 ( V_4 ) && F_89 ( V_4 ) < V_144 ) )
F_82 ( V_156 ,
V_157 ) ;
V_140 = V_128 ;
if ( ( F_88 ( V_4 ) && F_89 ( V_4 ) == V_158 ) ||
( F_90 ( V_4 ) && F_89 ( V_4 ) >= V_144 ) )
V_140 |= V_159 ;
F_82 ( V_126 , V_140 ) ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
T_4 V_160 [ 3 ] = { 0 , 0 , 0 } ;
unsigned int V_108 ;
for ( V_108 = 0 ; V_108 < 3 ; V_108 ++ ) {
T_4 V_161 ;
if ( F_92 ( V_24 -> V_162 . V_163 [ V_108 ] ) != 1 )
continue;
V_161 = F_93 ( V_24 -> V_162 . V_163 [ V_108 ] ) - 1 ;
V_160 [ V_108 ] = 3 - V_161 ;
}
if ( V_160 [ 0 ] == 0 && V_160 [ 1 ] == 0 && V_160 [ 2 ] == 0 )
return 0 ;
F_85 ( V_135 ,
F_94 ( 2 ) |
F_94 ( 1 ) |
F_94 ( 0 ) ,
F_95 ( 2 , V_160 [ 2 ] ) |
F_95 ( 1 , V_160 [ 1 ] ) |
F_95 ( 0 , V_160 [ 0 ] ) ) ;
return 0 ;
}
static int F_96 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
F_87 ( V_2 ) ;
if ( F_89 ( V_4 ) == V_143 )
F_82 ( V_138 ,
V_164 ) ;
if ( F_89 ( V_4 ) == V_151 ||
F_89 ( V_4 ) == V_165 )
F_82 ( V_126 ,
V_130 |
V_166 ) ;
if ( F_89 ( V_4 ) <= V_165 ) {
F_82 ( V_126 ,
V_127 ) ;
}
return F_91 ( V_2 ) ;
}
static int F_97 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
F_87 ( V_2 ) ;
F_82 ( V_119 ,
V_121 ) ;
if ( F_89 ( V_4 ) <= V_144 ) {
F_82 (
V_167 ,
V_168 ) ;
}
return 0 ;
}
int F_98 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
F_39 ( V_2 -> V_13 != V_72 ) ;
V_24 -> V_111 . V_112 = 0 ;
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
int V_32 = F_54 ( V_2 ) ;
if ( V_32 )
return V_32 ;
if ( F_25 ( V_4 ) -> V_64 >= 4 && F_25 ( V_4 ) -> V_64 < 7 )
F_31 ( V_169 , F_41 ( V_170 ) ) ;
if ( F_25 ( V_4 ) -> V_64 >= 6 && F_25 ( V_4 ) -> V_64 < 9 )
F_31 ( V_169 , F_41 ( V_171 ) ) ;
if ( F_25 ( V_4 ) -> V_64 == 6 )
F_31 ( V_172 ,
F_41 ( V_173 ) ) ;
if ( F_33 ( V_4 ) )
F_31 ( V_174 ,
F_41 ( V_173 ) |
F_41 ( V_175 ) ) ;
if ( F_34 ( V_4 ) ) {
F_31 ( V_176 ,
F_53 ( V_177 ) ) ;
}
if ( F_25 ( V_4 ) -> V_64 >= 6 )
F_31 ( V_178 , F_41 ( V_179 ) ) ;
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
F_67 ( & V_24 -> V_180 -> V_100 ) ;
V_24 -> V_180 = NULL ;
}
F_63 ( V_2 ) ;
}
static int F_106 ( struct V_1 * V_181 ,
unsigned int V_182 )
{
#define F_107 8
struct V_3 * V_4 = V_181 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_183 ;
int V_108 , V_32 , V_184 ;
V_184 = F_108 ( F_25 ( V_4 ) -> V_185 ) ;
V_182 += ( V_184 - 1 ) * F_107 ;
#undef F_107
V_32 = F_9 ( V_181 , V_182 ) ;
if ( V_32 )
return V_32 ;
F_109 (waiter, dev_priv, i) {
T_1 V_186 ;
T_2 V_45 = V_181 -> V_187 . V_188 [ V_108 ] ;
if ( V_45 == V_189 )
continue;
V_186 = F_110 (
V_181 -> V_190 ) ;
F_10 ( V_181 , F_16 ( 6 ) ) ;
F_10 ( V_181 , V_61 |
V_50 |
V_191 ) ;
F_10 ( V_181 , F_111 ( V_45 ) ) ;
F_10 ( V_181 , F_112 ( V_45 ) ) ;
F_10 ( V_181 , V_186 ) ;
F_10 ( V_181 , 0 ) ;
F_10 ( V_181 , V_192 |
F_113 ( V_183 -> V_13 ) ) ;
F_10 ( V_181 , 0 ) ;
}
return 0 ;
}
static int F_114 ( struct V_1 * V_181 ,
unsigned int V_182 )
{
#define F_107 6
struct V_3 * V_4 = V_181 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_183 ;
int V_108 , V_32 , V_184 ;
V_184 = F_108 ( F_25 ( V_4 ) -> V_185 ) ;
V_182 += ( V_184 - 1 ) * F_107 ;
#undef F_107
V_32 = F_9 ( V_181 , V_182 ) ;
if ( V_32 )
return V_32 ;
F_109 (waiter, dev_priv, i) {
T_1 V_186 ;
T_2 V_45 = V_181 -> V_187 . V_188 [ V_108 ] ;
if ( V_45 == V_189 )
continue;
V_186 = F_110 (
V_181 -> V_190 ) ;
F_10 ( V_181 , ( V_193 + 1 ) |
V_194 ) ;
F_10 ( V_181 , F_111 ( V_45 ) |
V_195 ) ;
F_10 ( V_181 , F_112 ( V_45 ) ) ;
F_10 ( V_181 , V_186 ) ;
F_10 ( V_181 , V_192 |
F_113 ( V_183 -> V_13 ) ) ;
F_10 ( V_181 , 0 ) ;
}
return 0 ;
}
static int F_115 ( struct V_1 * V_181 ,
unsigned int V_182 )
{
struct V_3 * V_4 = V_181 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_196 ;
int V_108 , V_32 , V_184 ;
#define F_107 3
V_184 = F_108 ( F_25 ( V_4 ) -> V_185 ) ;
V_182 += F_116 ( ( V_184 - 1 ) * F_107 , 2 ) ;
#undef F_107
V_32 = F_9 ( V_181 , V_182 ) ;
if ( V_32 )
return V_32 ;
F_109 (useless, dev_priv, i) {
T_1 V_197 = V_181 -> V_187 . V_198 . signal [ V_108 ] ;
if ( V_197 != V_199 ) {
T_1 V_186 = F_110 (
V_181 -> V_190 ) ;
F_10 ( V_181 , F_77 ( 1 ) ) ;
F_10 ( V_181 , V_197 ) ;
F_10 ( V_181 , V_186 ) ;
}
}
if ( V_184 % 2 == 0 )
F_10 ( V_181 , V_38 ) ;
return 0 ;
}
static int
F_117 ( struct V_1 * V_2 )
{
int V_32 ;
if ( V_2 -> V_187 . signal )
V_32 = V_2 -> V_187 . signal ( V_2 , 4 ) ;
else
V_32 = F_9 ( V_2 , 4 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , V_200 ) ;
F_10 ( V_2 , V_201 << V_202 ) ;
F_10 ( V_2 ,
F_110 ( V_2 -> V_190 ) ) ;
F_10 ( V_2 , V_203 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static inline bool F_118 ( struct V_3 * V_4 ,
T_1 V_186 )
{
struct V_23 * V_24 = V_4 -> V_25 ;
return V_24 -> V_204 < V_186 ;
}
static int
F_119 ( struct V_1 * V_183 ,
struct V_1 * V_181 ,
T_1 V_186 )
{
struct V_23 * V_24 = V_183 -> V_4 -> V_25 ;
int V_32 ;
V_32 = F_9 ( V_183 , 4 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_183 , V_205 |
V_206 |
V_207 |
V_208 ) ;
F_10 ( V_183 , V_186 ) ;
F_10 ( V_183 ,
F_111 ( F_120 ( V_183 , V_181 -> V_13 ) ) ) ;
F_10 ( V_183 ,
F_112 ( F_120 ( V_183 , V_181 -> V_13 ) ) ) ;
F_11 ( V_183 ) ;
return 0 ;
}
static int
F_121 ( struct V_1 * V_183 ,
struct V_1 * V_181 ,
T_1 V_186 )
{
T_1 V_209 = V_210 |
V_211 |
V_212 ;
T_1 V_213 = V_181 -> V_187 . V_198 . V_214 [ V_183 -> V_13 ] ;
int V_32 ;
V_186 -= 1 ;
F_39 ( V_213 == V_189 ) ;
V_32 = F_9 ( V_183 , 4 ) ;
if ( V_32 )
return V_32 ;
if ( F_122 ( ! F_118 ( V_183 -> V_4 , V_186 ) ) ) {
F_10 ( V_183 , V_209 | V_213 ) ;
F_10 ( V_183 , V_186 ) ;
F_10 ( V_183 , 0 ) ;
F_10 ( V_183 , V_38 ) ;
} else {
F_10 ( V_183 , V_38 ) ;
F_10 ( V_183 , V_38 ) ;
F_10 ( V_183 , V_38 ) ;
F_10 ( V_183 , V_38 ) ;
}
F_11 ( V_183 ) ;
return 0 ;
}
static int
F_123 ( struct V_1 * V_2 )
{
T_1 V_43 = V_2 -> V_44 . V_45 + 2 * V_46 ;
int V_32 ;
V_32 = F_9 ( V_2 , 32 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , F_16 ( 4 ) | V_50 |
V_215 |
V_56 ) ;
F_10 ( V_2 , V_2 -> V_44 . V_45 | V_49 ) ;
F_10 ( V_2 ,
F_110 ( V_2 -> V_190 ) ) ;
F_10 ( V_2 , 0 ) ;
F_124 ( V_2 , V_43 ) ;
V_43 += 2 * V_46 ;
F_124 ( V_2 , V_43 ) ;
V_43 += 2 * V_46 ;
F_124 ( V_2 , V_43 ) ;
V_43 += 2 * V_46 ;
F_124 ( V_2 , V_43 ) ;
V_43 += 2 * V_46 ;
F_124 ( V_2 , V_43 ) ;
V_43 += 2 * V_46 ;
F_124 ( V_2 , V_43 ) ;
F_10 ( V_2 , F_16 ( 4 ) | V_50 |
V_215 |
V_56 |
V_216 ) ;
F_10 ( V_2 , V_2 -> V_44 . V_45 | V_49 ) ;
F_10 ( V_2 ,
F_110 ( V_2 -> V_190 ) ) ;
F_10 ( V_2 , 0 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static T_1
F_125 ( struct V_1 * V_2 , bool V_217 )
{
if ( ! V_217 ) {
struct V_23 * V_24 = V_2 -> V_4 -> V_25 ;
F_37 ( F_27 ( V_2 -> V_65 ) ) ;
}
return F_126 ( V_2 , V_201 ) ;
}
static T_1
F_127 ( struct V_1 * V_2 , bool V_217 )
{
return F_126 ( V_2 , V_201 ) ;
}
static void
F_128 ( struct V_1 * V_2 , T_1 V_186 )
{
F_129 ( V_2 , V_201 , V_186 ) ;
}
static T_1
F_130 ( struct V_1 * V_2 , bool V_217 )
{
return V_2 -> V_44 . V_105 [ 0 ] ;
}
static void
F_131 ( struct V_1 * V_2 , T_1 V_186 )
{
V_2 -> V_44 . V_105 [ 0 ] = V_186 ;
}
static bool
F_132 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
if ( F_39 ( ! F_133 ( V_24 ) ) )
return false ;
F_134 ( & V_24 -> V_218 , V_51 ) ;
if ( V_2 -> V_219 ++ == 0 )
F_135 ( V_24 , V_2 -> V_220 ) ;
F_136 ( & V_24 -> V_218 , V_51 ) ;
return true ;
}
static void
F_137 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
F_134 ( & V_24 -> V_218 , V_51 ) ;
if ( -- V_2 -> V_219 == 0 )
F_138 ( V_24 , V_2 -> V_220 ) ;
F_136 ( & V_24 -> V_218 , V_51 ) ;
}
static bool
F_139 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
if ( ! F_133 ( V_24 ) )
return false ;
F_134 ( & V_24 -> V_218 , V_51 ) ;
if ( V_2 -> V_219 ++ == 0 ) {
V_24 -> V_221 &= ~ V_2 -> V_220 ;
F_31 ( V_222 , V_24 -> V_221 ) ;
F_37 ( V_222 ) ;
}
F_136 ( & V_24 -> V_218 , V_51 ) ;
return true ;
}
static void
F_140 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
F_134 ( & V_24 -> V_218 , V_51 ) ;
if ( -- V_2 -> V_219 == 0 ) {
V_24 -> V_221 |= V_2 -> V_220 ;
F_31 ( V_222 , V_24 -> V_221 ) ;
F_37 ( V_222 ) ;
}
F_136 ( & V_24 -> V_218 , V_51 ) ;
}
static bool
F_141 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
if ( ! F_133 ( V_24 ) )
return false ;
F_134 ( & V_24 -> V_218 , V_51 ) ;
if ( V_2 -> V_219 ++ == 0 ) {
V_24 -> V_221 &= ~ V_2 -> V_220 ;
F_142 ( V_222 , V_24 -> V_221 ) ;
F_143 ( V_222 ) ;
}
F_136 ( & V_24 -> V_218 , V_51 ) ;
return true ;
}
static void
F_144 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
F_134 ( & V_24 -> V_218 , V_51 ) ;
if ( -- V_2 -> V_219 == 0 ) {
V_24 -> V_221 |= V_2 -> V_220 ;
F_142 ( V_222 , V_24 -> V_221 ) ;
F_143 ( V_222 ) ;
}
F_136 ( & V_24 -> V_218 , V_51 ) ;
}
static int
F_145 ( struct V_1 * V_2 ,
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
F_146 ( struct V_1 * V_2 )
{
int V_32 ;
V_32 = F_9 ( V_2 , 4 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , V_200 ) ;
F_10 ( V_2 , V_201 << V_202 ) ;
F_10 ( V_2 ,
F_110 ( V_2 -> V_190 ) ) ;
F_10 ( V_2 , V_203 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static bool
F_147 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
if ( F_39 ( ! F_133 ( V_24 ) ) )
return false ;
F_134 ( & V_24 -> V_218 , V_51 ) ;
if ( V_2 -> V_219 ++ == 0 ) {
if ( F_102 ( V_4 ) && V_2 -> V_13 == V_72 )
F_103 ( V_2 ,
~ ( V_2 -> V_220 |
F_104 ( V_4 ) ) ) ;
else
F_103 ( V_2 , ~ V_2 -> V_220 ) ;
F_135 ( V_24 , V_2 -> V_220 ) ;
}
F_136 ( & V_24 -> V_218 , V_51 ) ;
return true ;
}
static void
F_148 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
F_134 ( & V_24 -> V_218 , V_51 ) ;
if ( -- V_2 -> V_219 == 0 ) {
if ( F_102 ( V_4 ) && V_2 -> V_13 == V_72 )
F_103 ( V_2 , ~ F_104 ( V_4 ) ) ;
else
F_103 ( V_2 , ~ 0 ) ;
F_138 ( V_24 , V_2 -> V_220 ) ;
}
F_136 ( & V_24 -> V_218 , V_51 ) ;
}
static bool
F_149 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
if ( F_39 ( ! F_133 ( V_24 ) ) )
return false ;
F_134 ( & V_24 -> V_218 , V_51 ) ;
if ( V_2 -> V_219 ++ == 0 ) {
F_103 ( V_2 , ~ V_2 -> V_220 ) ;
F_150 ( V_24 , V_2 -> V_220 ) ;
}
F_136 ( & V_24 -> V_218 , V_51 ) ;
return true ;
}
static void
F_151 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
F_134 ( & V_24 -> V_218 , V_51 ) ;
if ( -- V_2 -> V_219 == 0 ) {
F_103 ( V_2 , ~ 0 ) ;
F_152 ( V_24 , V_2 -> V_220 ) ;
}
F_136 ( & V_24 -> V_218 , V_51 ) ;
}
static bool
F_153 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
if ( F_39 ( ! F_133 ( V_24 ) ) )
return false ;
F_134 ( & V_24 -> V_218 , V_51 ) ;
if ( V_2 -> V_219 ++ == 0 ) {
if ( F_102 ( V_4 ) && V_2 -> V_13 == V_72 ) {
F_103 ( V_2 ,
~ ( V_2 -> V_220 |
V_223 ) ) ;
} else {
F_103 ( V_2 , ~ V_2 -> V_220 ) ;
}
F_37 ( F_154 ( V_2 -> V_65 ) ) ;
}
F_136 ( & V_24 -> V_218 , V_51 ) ;
return true ;
}
static void
F_155 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
F_134 ( & V_24 -> V_218 , V_51 ) ;
if ( -- V_2 -> V_219 == 0 ) {
if ( F_102 ( V_4 ) && V_2 -> V_13 == V_72 ) {
F_103 ( V_2 ,
~ V_223 ) ;
} else {
F_103 ( V_2 , ~ 0 ) ;
}
F_37 ( F_154 ( V_2 -> V_65 ) ) ;
}
F_136 ( & V_24 -> V_218 , V_51 ) ;
}
static int
F_156 ( struct V_1 * V_2 ,
T_2 V_224 , T_1 V_225 ,
unsigned V_226 )
{
int V_32 ;
V_32 = F_9 ( V_2 , 2 ) ;
if ( V_32 )
return V_32 ;
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
F_157 ( struct V_1 * V_2 ,
T_2 V_224 , T_1 V_231 ,
unsigned V_226 )
{
T_1 V_232 = V_2 -> V_44 . V_45 ;
int V_32 ;
V_32 = F_9 ( V_2 , 6 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , V_233 | V_234 ) ;
F_10 ( V_2 , V_235 | V_236 | 4096 ) ;
F_10 ( V_2 , V_237 << 16 | 4 ) ;
F_10 ( V_2 , V_232 ) ;
F_10 ( V_2 , 0xdeadbeef ) ;
F_10 ( V_2 , V_38 ) ;
F_11 ( V_2 ) ;
if ( ( V_226 & V_238 ) == 0 ) {
if ( V_231 > V_239 )
return - V_118 ;
V_32 = F_9 ( V_2 , 6 + 2 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , V_240 | V_234 ) ;
F_10 ( V_2 , V_235 | V_241 | 4096 ) ;
F_10 ( V_2 , F_158 ( V_231 , 4096 ) << 16 | 4096 ) ;
F_10 ( V_2 , V_232 ) ;
F_10 ( V_2 , 4096 ) ;
F_10 ( V_2 , V_224 ) ;
F_10 ( V_2 , V_33 ) ;
F_10 ( V_2 , V_38 ) ;
F_11 ( V_2 ) ;
V_224 = V_232 ;
}
V_32 = F_9 ( V_2 , 4 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , V_242 ) ;
F_10 ( V_2 , V_224 | ( V_226 & V_229 ?
0 : V_243 ) ) ;
F_10 ( V_2 , V_224 + V_231 - 8 ) ;
F_10 ( V_2 , V_38 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_159 ( struct V_1 * V_2 ,
T_2 V_224 , T_1 V_231 ,
unsigned V_226 )
{
int V_32 ;
V_32 = F_9 ( V_2 , 2 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , V_227 | V_228 ) ;
F_10 ( V_2 , V_224 | ( V_226 & V_229 ?
0 : V_243 ) ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static void F_160 ( struct V_1 * V_2 )
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
static int F_161 ( struct V_1 * V_2 )
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
if ( ! F_162 ( V_2 -> V_4 ) )
V_51 |= V_244 ;
V_32 = F_71 ( V_14 , 4096 , V_51 ) ;
if ( V_32 ) {
V_104:
F_67 ( & V_14 -> V_100 ) ;
return V_32 ;
}
V_2 -> V_81 . V_14 = V_14 ;
}
V_2 -> V_81 . V_82 = F_60 ( V_14 ) ;
V_2 -> V_81 . V_245 = F_72 ( F_65 ( V_14 -> V_98 -> V_99 ) ) ;
memset ( V_2 -> V_81 . V_245 , 0 , V_93 ) ;
F_73 ( L_14 ,
V_2 -> V_87 , V_2 -> V_81 . V_82 ) ;
return 0 ;
}
static int F_163 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_4 -> V_25 ;
if ( ! V_24 -> V_68 ) {
V_24 -> V_68 =
F_164 ( V_2 -> V_4 , V_93 , V_93 ) ;
if ( ! V_24 -> V_68 )
return - V_101 ;
}
V_2 -> V_81 . V_245 = V_24 -> V_68 -> V_246 ;
memset ( V_2 -> V_81 . V_245 , 0 , V_93 ) ;
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
struct V_89 * V_14 = V_11 -> V_14 ;
int V_32 ;
V_32 = F_71 ( V_14 , V_93 , V_244 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_168 ( V_14 , true ) ;
if ( V_32 ) {
F_66 ( V_14 ) ;
return V_32 ;
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
F_67 ( & V_11 -> V_14 -> V_100 ) ;
V_11 -> V_14 = NULL ;
}
int F_171 ( struct V_3 * V_4 ,
struct V_10 * V_11 )
{
struct V_89 * V_14 ;
V_14 = NULL ;
if ( ! F_162 ( V_4 ) )
V_14 = F_172 ( V_4 , V_11 -> V_18 ) ;
if ( V_14 == NULL )
V_14 = F_69 ( V_4 , V_11 -> V_18 ) ;
if ( V_14 == NULL )
return - V_101 ;
V_14 -> V_251 = 1 ;
V_11 -> V_14 = V_14 ;
return 0 ;
}
static int F_173 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_32 ;
F_39 ( V_2 -> V_15 ) ;
V_11 = F_174 ( sizeof( * V_11 ) , V_252 ) ;
if ( ! V_11 )
return - V_101 ;
V_2 -> V_15 = V_11 ;
V_2 -> V_4 = V_4 ;
F_175 ( & V_2 -> V_253 ) ;
F_175 ( & V_2 -> V_254 ) ;
F_175 ( & V_2 -> V_255 ) ;
F_176 ( V_4 , & V_2 -> V_256 ) ;
V_11 -> V_18 = 32 * V_93 ;
V_11 -> V_2 = V_2 ;
memset ( V_2 -> V_187 . V_257 , 0 , sizeof( V_2 -> V_187 . V_257 ) ) ;
F_177 ( & V_2 -> V_258 ) ;
if ( F_58 ( V_4 ) ) {
V_32 = F_161 ( V_2 ) ;
if ( V_32 )
goto error;
} else {
F_178 ( V_2 -> V_13 != V_72 ) ;
V_32 = F_163 ( V_2 ) ;
if ( V_32 )
goto error;
}
F_39 ( V_11 -> V_14 ) ;
V_32 = F_171 ( V_4 , V_11 ) ;
if ( V_32 ) {
F_43 ( L_15 ,
V_2 -> V_87 , V_32 ) ;
goto error;
}
V_32 = F_167 ( V_4 , V_11 ) ;
if ( V_32 ) {
F_43 ( L_16 ,
V_2 -> V_87 , V_32 ) ;
F_170 ( V_11 ) ;
goto error;
}
V_11 -> V_259 = V_11 -> V_18 ;
if ( F_179 ( V_4 ) || F_180 ( V_4 ) )
V_11 -> V_259 -= 2 * V_46 ;
V_32 = F_181 ( V_2 ) ;
if ( V_32 )
goto error;
return 0 ;
error:
F_182 ( V_11 ) ;
V_2 -> V_15 = NULL ;
return V_32 ;
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
F_39 ( ! F_46 ( V_2 -> V_4 ) && ( F_40 ( V_2 ) & V_84 ) == 0 ) ;
F_165 ( V_11 ) ;
F_170 ( V_11 ) ;
F_185 ( & V_2 -> V_190 , NULL ) ;
if ( V_2 -> V_260 )
V_2 -> V_260 ( V_2 ) ;
F_160 ( V_2 ) ;
F_186 ( V_2 ) ;
F_187 ( & V_2 -> V_256 ) ;
F_182 ( V_11 ) ;
V_2 -> V_15 = NULL ;
}
static int F_188 ( struct V_1 * V_2 , int V_261 )
{
struct V_10 * V_11 = V_2 -> V_15 ;
struct V_262 * V_263 ;
unsigned V_19 ;
int V_32 ;
if ( F_4 ( V_11 ) >= V_261 )
return 0 ;
F_189 (request, &ring->request_list, list) {
V_19 = F_2 ( V_263 -> V_264 , V_11 -> V_17 ,
V_11 -> V_18 ) ;
if ( V_19 >= V_261 )
break;
}
if ( F_39 ( & V_263 -> V_265 == & V_2 -> V_254 ) )
return - V_118 ;
V_32 = F_190 ( V_263 ) ;
if ( V_32 )
return V_32 ;
V_11 -> V_19 = V_19 ;
return 0 ;
}
static int F_191 ( struct V_1 * V_2 )
{
T_3 T_5 * V_266 ;
struct V_10 * V_11 = V_2 -> V_15 ;
int V_267 = V_11 -> V_18 - V_11 -> V_17 ;
if ( V_11 -> V_19 < V_267 ) {
int V_32 = F_188 ( V_2 , V_267 ) ;
if ( V_32 )
return V_32 ;
}
V_266 = V_11 -> V_247 + V_11 -> V_17 ;
V_267 /= 4 ;
while ( V_267 -- )
F_192 ( V_38 , V_266 ++ ) ;
V_11 -> V_17 = 0 ;
F_3 ( V_11 ) ;
return 0 ;
}
int F_193 ( struct V_1 * V_2 )
{
struct V_262 * V_268 ;
int V_32 ;
if ( V_2 -> V_190 ) {
V_32 = F_194 ( V_2 ) ;
if ( V_32 )
return V_32 ;
}
if ( F_195 ( & V_2 -> V_254 ) )
return 0 ;
V_268 = F_196 ( V_2 -> V_254 . V_269 ,
struct V_262 ,
V_265 ) ;
return F_197 ( V_268 ,
F_198 ( & F_45 ( V_2 -> V_4 ) -> V_26 . V_270 ) ,
F_45 ( V_2 -> V_4 ) -> V_271 . V_272 ,
NULL , NULL ) ;
}
int F_199 ( struct V_262 * V_263 )
{
V_263 -> V_11 = V_263 -> V_2 -> V_15 ;
return 0 ;
}
static int F_200 ( struct V_1 * V_2 ,
int V_273 )
{
struct V_10 * V_11 = V_2 -> V_15 ;
int V_32 ;
if ( F_201 ( V_11 -> V_17 + V_273 > V_11 -> V_259 ) ) {
V_32 = F_191 ( V_2 ) ;
if ( F_201 ( V_32 ) )
return V_32 ;
}
if ( F_201 ( V_11 -> V_19 < V_273 ) ) {
V_32 = F_188 ( V_2 , V_273 ) ;
if ( F_201 ( V_32 ) )
return V_32 ;
}
return 0 ;
}
int F_9 ( struct V_1 * V_2 ,
int V_182 )
{
struct V_23 * V_24 = V_2 -> V_4 -> V_25 ;
int V_32 ;
V_32 = F_202 ( & V_24 -> V_26 ,
V_24 -> V_271 . V_272 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_200 ( V_2 , V_182 * sizeof( T_3 ) ) ;
if ( V_32 )
return V_32 ;
V_32 = F_203 ( V_2 , V_2 -> V_9 ) ;
if ( V_32 )
return V_32 ;
V_2 -> V_15 -> V_19 -= V_182 * sizeof( T_3 ) ;
return 0 ;
}
int F_204 ( struct V_1 * V_2 )
{
int V_182 = ( V_2 -> V_15 -> V_17 & ( V_46 - 1 ) ) / sizeof( T_3 ) ;
int V_32 ;
if ( V_182 == 0 )
return 0 ;
V_182 = V_46 / sizeof( T_3 ) - V_182 ;
V_32 = F_9 ( V_2 , V_182 ) ;
if ( V_32 )
return V_32 ;
while ( V_182 -- )
F_10 ( V_2 , V_38 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
void F_205 ( struct V_1 * V_2 , T_1 V_186 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
F_178 ( V_2 -> V_190 ) ;
if ( F_25 ( V_4 ) -> V_64 == 6 || F_25 ( V_4 ) -> V_64 == 7 ) {
F_31 ( F_206 ( V_2 -> V_65 ) , 0 ) ;
F_31 ( F_207 ( V_2 -> V_65 ) , 0 ) ;
if ( F_208 ( V_4 ) )
F_31 ( F_209 ( V_2 -> V_65 ) , 0 ) ;
}
V_2 -> V_274 ( V_2 , V_186 ) ;
V_2 -> V_97 . V_186 = V_186 ;
}
static void F_210 ( struct V_1 * V_2 ,
T_1 V_62 )
{
struct V_23 * V_24 = V_2 -> V_4 -> V_25 ;
F_31 ( V_275 ,
F_41 ( V_276 ) ) ;
F_211 ( V_277 , 0x0 ) ;
if ( F_42 ( ( F_29 ( V_275 ) &
V_278 ) == 0 ,
50 ) )
F_43 ( L_17 ) ;
F_23 ( V_2 , V_62 ) ;
F_37 ( F_212 ( V_2 -> V_65 ) ) ;
F_31 ( V_275 ,
F_53 ( V_276 ) ) ;
}
static int F_213 ( struct V_1 * V_2 ,
T_1 V_279 , T_1 V_280 )
{
T_3 V_31 ;
int V_32 ;
V_32 = F_9 ( V_2 , 4 ) ;
if ( V_32 )
return V_32 ;
V_31 = V_193 ;
if ( F_25 ( V_2 -> V_4 ) -> V_64 >= 8 )
V_31 += 1 ;
V_31 |= V_281 | V_194 ;
if ( V_279 & V_282 )
V_31 |= V_283 | V_284 ;
F_10 ( V_2 , V_31 ) ;
F_10 ( V_2 , V_285 | V_195 ) ;
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
F_214 ( struct V_1 * V_2 ,
T_2 V_224 , T_1 V_231 ,
unsigned V_226 )
{
bool V_286 = F_215 ( V_2 -> V_4 ) &&
! ( V_226 & V_229 ) ;
int V_32 ;
V_32 = F_9 ( V_2 , 4 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , V_287 | ( V_286 << 8 ) ) ;
F_10 ( V_2 , F_111 ( V_224 ) ) ;
F_10 ( V_2 , F_112 ( V_224 ) ) ;
F_10 ( V_2 , V_38 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_216 ( struct V_1 * V_2 ,
T_2 V_224 , T_1 V_231 ,
unsigned V_226 )
{
int V_32 ;
V_32 = F_9 ( V_2 , 2 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 ,
V_227 |
( V_226 & V_229 ?
0 : V_288 | V_289 ) ) ;
F_10 ( V_2 , V_224 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_217 ( struct V_1 * V_2 ,
T_2 V_224 , T_1 V_231 ,
unsigned V_226 )
{
int V_32 ;
V_32 = F_9 ( V_2 , 2 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 ,
V_227 |
( V_226 & V_229 ?
0 : V_230 ) ) ;
F_10 ( V_2 , V_224 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int F_218 ( struct V_1 * V_2 ,
T_1 V_279 , T_1 V_280 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_31 ;
int V_32 ;
V_32 = F_9 ( V_2 , 4 ) ;
if ( V_32 )
return V_32 ;
V_31 = V_193 ;
if ( F_25 ( V_4 ) -> V_64 >= 8 )
V_31 += 1 ;
V_31 |= V_281 | V_194 ;
if ( V_279 & V_34 )
V_31 |= V_283 ;
F_10 ( V_2 , V_31 ) ;
F_10 ( V_2 , V_285 | V_195 ) ;
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
int F_219 ( struct V_3 * V_4 )
{
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_2 = & V_24 -> V_2 [ V_72 ] ;
struct V_89 * V_14 ;
int V_32 ;
V_2 -> V_87 = L_18 ;
V_2 -> V_13 = V_72 ;
V_2 -> V_65 = V_290 ;
if ( F_25 ( V_4 ) -> V_64 >= 8 ) {
if ( F_220 ( V_4 ) ) {
V_14 = F_69 ( V_4 , 4096 ) ;
if ( V_14 == NULL ) {
F_43 ( L_19 ) ;
V_5 . V_291 = 0 ;
} else {
F_70 ( V_14 , V_103 ) ;
V_32 = F_71 ( V_14 , 0 , V_292 ) ;
if ( V_32 != 0 ) {
F_67 ( & V_14 -> V_100 ) ;
F_43 ( L_20 ) ;
V_5 . V_291 = 0 ;
} else
V_24 -> V_180 = V_14 ;
}
}
V_2 -> V_293 = F_78 ;
V_2 -> V_294 = F_117 ;
V_2 -> V_280 = F_21 ;
V_2 -> V_295 = F_153 ;
V_2 -> V_296 = F_155 ;
V_2 -> V_220 = V_297 ;
V_2 -> V_298 = F_125 ;
V_2 -> V_274 = F_128 ;
if ( F_220 ( V_4 ) ) {
F_39 ( ! V_24 -> V_180 ) ;
V_2 -> V_187 . V_299 = F_119 ;
V_2 -> V_187 . signal = F_106 ;
V_300 ;
}
} else if ( F_25 ( V_4 ) -> V_64 >= 6 ) {
V_2 -> V_294 = F_117 ;
V_2 -> V_280 = F_19 ;
if ( F_25 ( V_4 ) -> V_64 == 6 )
V_2 -> V_280 = F_17 ;
V_2 -> V_295 = F_147 ;
V_2 -> V_296 = F_148 ;
V_2 -> V_220 = V_297 ;
V_2 -> V_298 = F_125 ;
V_2 -> V_274 = F_128 ;
if ( F_220 ( V_4 ) ) {
V_2 -> V_187 . V_299 = F_121 ;
V_2 -> V_187 . signal = F_115 ;
V_2 -> V_187 . V_198 . V_214 [ V_72 ] = V_189 ;
V_2 -> V_187 . V_198 . V_214 [ V_77 ] = V_301 ;
V_2 -> V_187 . V_198 . V_214 [ V_74 ] = V_302 ;
V_2 -> V_187 . V_198 . V_214 [ V_79 ] = V_303 ;
V_2 -> V_187 . V_198 . V_214 [ V_76 ] = V_189 ;
V_2 -> V_187 . V_198 . signal [ V_72 ] = V_199 ;
V_2 -> V_187 . V_198 . signal [ V_77 ] = V_304 ;
V_2 -> V_187 . V_198 . signal [ V_74 ] = V_305 ;
V_2 -> V_187 . V_198 . signal [ V_79 ] = V_306 ;
V_2 -> V_187 . V_198 . signal [ V_76 ] = V_199 ;
}
} else if ( F_14 ( V_4 ) ) {
V_2 -> V_294 = F_123 ;
V_2 -> V_280 = F_12 ;
V_2 -> V_298 = F_130 ;
V_2 -> V_274 = F_131 ;
V_2 -> V_295 = F_132 ;
V_2 -> V_296 = F_137 ;
V_2 -> V_220 = V_297 |
V_307 ;
} else {
V_2 -> V_294 = F_146 ;
if ( F_25 ( V_4 ) -> V_64 < 4 )
V_2 -> V_280 = F_8 ;
else
V_2 -> V_280 = F_12 ;
V_2 -> V_298 = F_127 ;
V_2 -> V_274 = F_128 ;
if ( F_46 ( V_4 ) ) {
V_2 -> V_295 = F_141 ;
V_2 -> V_296 = F_144 ;
} else {
V_2 -> V_295 = F_139 ;
V_2 -> V_296 = F_140 ;
}
V_2 -> V_220 = V_308 ;
}
V_2 -> V_28 = F_22 ;
if ( F_221 ( V_4 ) )
V_2 -> V_309 = F_216 ;
else if ( F_222 ( V_4 ) )
V_2 -> V_309 = F_214 ;
else if ( F_25 ( V_4 ) -> V_64 >= 6 )
V_2 -> V_309 = F_217 ;
else if ( F_25 ( V_4 ) -> V_64 >= 4 )
V_2 -> V_309 = F_156 ;
else if ( F_179 ( V_4 ) || F_180 ( V_4 ) )
V_2 -> V_309 = F_157 ;
else
V_2 -> V_309 = F_159 ;
V_2 -> V_310 = F_101 ;
V_2 -> V_260 = F_105 ;
if ( F_223 ( V_4 ) ) {
V_14 = F_69 ( V_4 , V_311 ) ;
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
V_32 = F_173 ( V_4 , V_2 ) ;
if ( V_32 )
return V_32 ;
if ( F_25 ( V_4 ) -> V_64 >= 5 ) {
V_32 = F_68 ( V_2 ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
int F_224 ( struct V_3 * V_4 )
{
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_2 = & V_24 -> V_2 [ V_77 ] ;
V_2 -> V_87 = L_23 ;
V_2 -> V_13 = V_77 ;
V_2 -> V_28 = F_22 ;
if ( F_25 ( V_4 ) -> V_64 >= 6 ) {
V_2 -> V_65 = V_312 ;
if ( F_34 ( V_4 ) )
V_2 -> V_28 = F_210 ;
V_2 -> V_280 = F_213 ;
V_2 -> V_294 = F_117 ;
V_2 -> V_298 = F_125 ;
V_2 -> V_274 = F_128 ;
if ( F_25 ( V_4 ) -> V_64 >= 8 ) {
V_2 -> V_220 =
V_297 << V_313 ;
V_2 -> V_295 = F_153 ;
V_2 -> V_296 = F_155 ;
V_2 -> V_309 =
F_214 ;
if ( F_220 ( V_4 ) ) {
V_2 -> V_187 . V_299 = F_119 ;
V_2 -> V_187 . signal = F_114 ;
V_300 ;
}
} else {
V_2 -> V_220 = V_314 ;
V_2 -> V_295 = F_147 ;
V_2 -> V_296 = F_148 ;
V_2 -> V_309 =
F_217 ;
if ( F_220 ( V_4 ) ) {
V_2 -> V_187 . V_299 = F_121 ;
V_2 -> V_187 . signal = F_115 ;
V_2 -> V_187 . V_198 . V_214 [ V_72 ] = V_315 ;
V_2 -> V_187 . V_198 . V_214 [ V_77 ] = V_189 ;
V_2 -> V_187 . V_198 . V_214 [ V_74 ] = V_316 ;
V_2 -> V_187 . V_198 . V_214 [ V_79 ] = V_317 ;
V_2 -> V_187 . V_198 . V_214 [ V_76 ] = V_189 ;
V_2 -> V_187 . V_198 . signal [ V_72 ] = V_318 ;
V_2 -> V_187 . V_198 . signal [ V_77 ] = V_199 ;
V_2 -> V_187 . V_198 . signal [ V_74 ] = V_319 ;
V_2 -> V_187 . V_198 . signal [ V_79 ] = V_320 ;
V_2 -> V_187 . V_198 . signal [ V_76 ] = V_199 ;
}
}
} else {
V_2 -> V_65 = V_321 ;
V_2 -> V_280 = F_145 ;
V_2 -> V_294 = F_146 ;
V_2 -> V_298 = F_127 ;
V_2 -> V_274 = F_128 ;
if ( F_14 ( V_4 ) ) {
V_2 -> V_220 = V_322 ;
V_2 -> V_295 = F_132 ;
V_2 -> V_296 = F_137 ;
} else {
V_2 -> V_220 = V_323 ;
V_2 -> V_295 = F_139 ;
V_2 -> V_296 = F_140 ;
}
V_2 -> V_309 = F_156 ;
}
V_2 -> V_310 = F_54 ;
return F_173 ( V_4 , V_2 ) ;
}
int F_225 ( struct V_3 * V_4 )
{
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_2 = & V_24 -> V_2 [ V_76 ] ;
V_2 -> V_87 = L_24 ;
V_2 -> V_13 = V_76 ;
V_2 -> V_28 = F_22 ;
V_2 -> V_65 = V_324 ;
V_2 -> V_280 = F_213 ;
V_2 -> V_294 = F_117 ;
V_2 -> V_298 = F_125 ;
V_2 -> V_274 = F_128 ;
V_2 -> V_220 =
V_297 << V_325 ;
V_2 -> V_295 = F_153 ;
V_2 -> V_296 = F_155 ;
V_2 -> V_309 =
F_214 ;
if ( F_220 ( V_4 ) ) {
V_2 -> V_187 . V_299 = F_119 ;
V_2 -> V_187 . signal = F_114 ;
V_300 ;
}
V_2 -> V_310 = F_54 ;
return F_173 ( V_4 , V_2 ) ;
}
int F_226 ( struct V_3 * V_4 )
{
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_2 = & V_24 -> V_2 [ V_74 ] ;
V_2 -> V_87 = L_25 ;
V_2 -> V_13 = V_74 ;
V_2 -> V_65 = V_326 ;
V_2 -> V_28 = F_22 ;
V_2 -> V_280 = F_218 ;
V_2 -> V_294 = F_117 ;
V_2 -> V_298 = F_125 ;
V_2 -> V_274 = F_128 ;
if ( F_25 ( V_4 ) -> V_64 >= 8 ) {
V_2 -> V_220 =
V_297 << V_327 ;
V_2 -> V_295 = F_153 ;
V_2 -> V_296 = F_155 ;
V_2 -> V_309 = F_214 ;
if ( F_220 ( V_4 ) ) {
V_2 -> V_187 . V_299 = F_119 ;
V_2 -> V_187 . signal = F_114 ;
V_300 ;
}
} else {
V_2 -> V_220 = V_328 ;
V_2 -> V_295 = F_147 ;
V_2 -> V_296 = F_148 ;
V_2 -> V_309 = F_217 ;
if ( F_220 ( V_4 ) ) {
V_2 -> V_187 . signal = F_115 ;
V_2 -> V_187 . V_299 = F_121 ;
V_2 -> V_187 . V_198 . V_214 [ V_72 ] = V_329 ;
V_2 -> V_187 . V_198 . V_214 [ V_77 ] = V_330 ;
V_2 -> V_187 . V_198 . V_214 [ V_74 ] = V_189 ;
V_2 -> V_187 . V_198 . V_214 [ V_79 ] = V_331 ;
V_2 -> V_187 . V_198 . V_214 [ V_76 ] = V_189 ;
V_2 -> V_187 . V_198 . signal [ V_72 ] = V_332 ;
V_2 -> V_187 . V_198 . signal [ V_77 ] = V_333 ;
V_2 -> V_187 . V_198 . signal [ V_74 ] = V_199 ;
V_2 -> V_187 . V_198 . signal [ V_79 ] = V_334 ;
V_2 -> V_187 . V_198 . signal [ V_76 ] = V_199 ;
}
}
V_2 -> V_310 = F_54 ;
return F_173 ( V_4 , V_2 ) ;
}
int F_227 ( struct V_3 * V_4 )
{
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_2 = & V_24 -> V_2 [ V_79 ] ;
V_2 -> V_87 = L_26 ;
V_2 -> V_13 = V_79 ;
V_2 -> V_65 = V_335 ;
V_2 -> V_28 = F_22 ;
V_2 -> V_280 = F_218 ;
V_2 -> V_294 = F_117 ;
V_2 -> V_298 = F_125 ;
V_2 -> V_274 = F_128 ;
if ( F_25 ( V_4 ) -> V_64 >= 8 ) {
V_2 -> V_220 =
V_297 << V_336 ;
V_2 -> V_295 = F_153 ;
V_2 -> V_296 = F_155 ;
V_2 -> V_309 = F_214 ;
if ( F_220 ( V_4 ) ) {
V_2 -> V_187 . V_299 = F_119 ;
V_2 -> V_187 . signal = F_114 ;
V_300 ;
}
} else {
V_2 -> V_220 = V_337 ;
V_2 -> V_295 = F_149 ;
V_2 -> V_296 = F_151 ;
V_2 -> V_309 = F_217 ;
if ( F_220 ( V_4 ) ) {
V_2 -> V_187 . V_299 = F_121 ;
V_2 -> V_187 . signal = F_115 ;
V_2 -> V_187 . V_198 . V_214 [ V_72 ] = V_338 ;
V_2 -> V_187 . V_198 . V_214 [ V_77 ] = V_339 ;
V_2 -> V_187 . V_198 . V_214 [ V_74 ] = V_340 ;
V_2 -> V_187 . V_198 . V_214 [ V_79 ] = V_189 ;
V_2 -> V_187 . V_198 . V_214 [ V_76 ] = V_189 ;
V_2 -> V_187 . V_198 . signal [ V_72 ] = V_341 ;
V_2 -> V_187 . V_198 . signal [ V_77 ] = V_342 ;
V_2 -> V_187 . V_198 . signal [ V_74 ] = V_343 ;
V_2 -> V_187 . V_198 . signal [ V_79 ] = V_199 ;
V_2 -> V_187 . V_198 . signal [ V_76 ] = V_199 ;
}
}
V_2 -> V_310 = F_54 ;
return F_173 ( V_4 , V_2 ) ;
}
int
F_76 ( struct V_1 * V_2 )
{
int V_32 ;
if ( ! V_2 -> V_113 )
return 0 ;
V_32 = V_2 -> V_280 ( V_2 , 0 , V_282 ) ;
if ( V_32 )
return V_32 ;
F_228 ( V_2 , 0 , V_282 ) ;
V_2 -> V_113 = false ;
return 0 ;
}
int
F_229 ( struct V_1 * V_2 )
{
T_3 V_30 ;
int V_32 ;
V_30 = 0 ;
if ( V_2 -> V_113 )
V_30 = V_282 ;
V_32 = V_2 -> V_280 ( V_2 , V_282 , V_30 ) ;
if ( V_32 )
return V_32 ;
F_228 ( V_2 , V_282 , V_30 ) ;
V_2 -> V_113 = false ;
return 0 ;
}
void
F_184 ( struct V_1 * V_2 )
{
int V_32 ;
if ( ! F_1 ( V_2 ) )
return;
V_32 = F_193 ( V_2 ) ;
if ( V_32 && ! F_230 ( & F_45 ( V_2 -> V_4 ) -> V_26 ) )
F_43 ( L_27 ,
V_2 -> V_87 , V_32 ) ;
F_44 ( V_2 ) ;
}
