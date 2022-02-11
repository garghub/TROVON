static int F_1 ( void )
{
return F_2 () || F_3 () ;
}
static void F_4 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_4 )
F_5 ( V_2 -> V_3 -> V_4 , 0 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_4 )
F_5 ( V_2 -> V_3 -> V_4 , 1 ) ;
}
static void F_7 ( struct V_5 * V_6 , int V_7 , unsigned int V_8 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
struct V_1 * V_2 = V_9 -> V_10 ;
if ( V_8 & V_11 ) {
if ( V_8 & V_12 )
F_4 ( V_2 ) ;
else
F_6 ( V_2 ) ;
}
if ( V_7 == V_13 )
return;
if ( V_8 & V_14 )
F_8 ( V_7 , V_2 -> V_15 + ( 1 << V_2 -> V_3 -> V_16 ) ) ;
else
F_8 ( V_7 , V_2 -> V_15 + ( 1 << V_2 -> V_3 -> V_17 ) ) ;
}
static int F_9 ( struct V_5 * V_6 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
struct V_1 * V_2 = V_9 -> V_10 ;
return F_10 ( V_2 -> V_3 -> V_18 ) ^
! ! V_2 -> V_3 -> V_19 ;
}
static void F_11 ( void * V_20 )
{
F_12 ( V_20 ) ;
}
static int F_13 ( struct V_5 * V_6 , void * V_21 , int V_22 ,
int V_23 )
{
struct V_24 * V_25 ;
enum V_26 V_27 ;
T_1 V_28 , V_29 , V_30 ;
struct V_31 * V_32 = NULL ;
T_2 V_33 ;
struct V_9 * V_34 = V_6 -> V_10 ;
struct V_1 * V_2 = V_34 -> V_10 ;
void * V_35 = V_21 ;
int V_36 = - V_37 ;
enum V_38 V_39 = V_23 ? V_40 : V_41 ;
if ( V_21 >= V_42 )
goto V_43;
V_25 = V_2 -> V_44 -> V_45 ;
V_27 = V_46 | V_47 | V_48 |
V_49 ;
V_30 = F_14 ( V_25 -> V_50 , V_35 , V_22 , V_39 ) ;
if ( F_15 ( V_25 -> V_50 , V_30 ) ) {
F_16 ( V_2 -> V_50 , L_1 ) ;
goto V_43;
}
if ( V_23 ) {
V_28 = V_2 -> V_51 ;
V_29 = V_30 ;
} else {
V_28 = V_30 ;
V_29 = V_2 -> V_51 ;
}
V_32 = V_25 -> V_52 ( V_2 -> V_44 , V_29 ,
V_28 , V_22 , V_27 ) ;
if ( ! V_32 ) {
F_16 ( V_2 -> V_50 , L_2 ) ;
goto V_53;
}
F_17 ( & V_2 -> V_54 ) ;
V_32 -> V_55 = F_11 ;
V_32 -> V_56 = & V_2 -> V_54 ;
V_33 = V_32 -> V_57 ( V_32 ) ;
if ( F_18 ( V_33 ) ) {
F_16 ( V_2 -> V_50 , L_3 ) ;
goto V_53;
}
F_19 ( V_2 -> V_44 ) ;
F_20 ( & V_2 -> V_54 ) ;
V_36 = 0 ;
V_53:
F_21 ( V_25 -> V_50 , V_30 , V_22 , V_39 ) ;
V_43:
if ( V_36 != 0 )
F_22 ( V_2 -> V_50 , L_4 ) ;
return V_36 ;
}
static void F_23 ( struct V_5 * V_6 , T_3 * V_21 , int V_22 )
{
struct V_9 * V_34 = V_6 -> V_10 ;
if ( V_58 && V_22 > V_6 -> V_59 )
if ( F_13 ( V_6 , V_21 , V_22 , 1 ) == 0 )
return;
F_24 ( V_21 , V_34 -> V_60 , V_22 ) ;
}
static void F_25 ( struct V_5 * V_6 , const T_3 * V_21 , int V_22 )
{
struct V_9 * V_34 = V_6 -> V_10 ;
if ( V_58 && V_22 > V_6 -> V_59 )
if ( F_13 ( V_6 , ( void * ) V_21 , V_22 , 0 ) == 0 )
return;
F_26 ( V_34 -> V_61 , V_21 , V_22 ) ;
}
static int F_27 ( struct V_5 * V_6 ,
const T_4 * V_62 , unsigned char * V_63 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
struct V_1 * V_2 = V_9 -> V_10 ;
unsigned int V_64 ;
V_64 = F_28 ( V_2 -> V_65 , V_66 ) ;
V_63 [ 0 ] = V_64 & 0xFF ;
V_63 [ 1 ] = ( V_64 >> 8 ) & 0xFF ;
V_64 = F_28 ( V_2 -> V_65 , V_67 ) & V_68 ;
V_63 [ 2 ] = V_64 & 0xFF ;
V_63 [ 3 ] = ( V_64 >> 8 ) & 0xFF ;
return 0 ;
}
static int F_29 ( struct V_5 * V_6 ,
struct V_9 * V_34 , T_5 * V_21 , int V_69 )
{
int V_70 = V_34 -> V_65 . V_71 ;
int V_72 = V_34 -> V_65 . V_73 ;
T_6 * V_74 = V_34 -> V_65 . V_75 -> V_74 ;
T_5 * V_35 = V_21 ;
T_5 * V_76 = V_34 -> V_77 ;
T_5 * V_78 ;
int V_79 ;
if ( F_30 () ) {
struct V_1 * V_2 = V_34 -> V_10 ;
F_31 ( V_2 -> V_65 , V_80 , V_81 ) ;
}
V_34 -> V_82 ( V_6 , V_35 , V_70 ) ;
if ( V_74 [ 0 ] != 0 ) {
V_34 -> V_83 ( V_6 , V_84 ,
V_6 -> V_85 + V_74 [ 0 ] , - 1 ) ;
}
V_78 = V_76 + V_74 [ 0 ] ;
V_34 -> V_82 ( V_6 , V_78 , V_72 ) ;
V_79 = V_34 -> V_65 . V_86 ( V_6 , V_35 , V_76 , NULL ) ;
if ( V_79 < 0 )
V_6 -> V_87 . V_88 ++ ;
else
V_6 -> V_87 . V_89 += V_79 ;
V_34 -> V_83 ( V_6 , V_84 , V_6 -> V_85 , - 1 ) ;
V_34 -> V_82 ( V_6 , V_76 , V_6 -> V_59 ) ;
return 0 ;
}
static int F_32 ( struct V_5 * V_6 , T_4 * V_62 ,
T_4 * V_90 , T_4 * V_91 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
struct V_1 * V_2 = V_9 -> V_10 ;
unsigned int V_92 ;
unsigned int V_93 , V_94 ;
V_92 = F_28 ( V_2 -> V_65 , V_95 ) ;
if ( F_33 ( ! ( V_92 & V_96 ) ) )
return 0 ;
V_94 = F_28 ( V_2 -> V_65 , V_66 ) & V_97 ;
V_93 = F_28 ( V_2 -> V_65 , V_66 ) & V_98 ;
V_93 >>= 4 ;
if ( V_92 & V_99 ) {
if ( ( V_94 == V_97 )
&& ( V_93 == ( V_98 >> 4 ) ) ) {
return 0 ;
}
F_34 ( V_2 -> V_50 , L_5
L_6 ) ;
return - V_37 ;
}
if ( V_92 & V_100 ) {
F_34 ( V_2 -> V_50 , L_7
L_8 ) ;
return 0 ;
}
F_34 ( V_2 -> V_50 , L_9
L_10
L_11 ,
V_93 , V_94 ) ;
if ( V_9 -> V_101 & V_102 ) {
( ( unsigned short * ) V_62 ) [ V_93 ] ^= ( 1 << V_94 ) ;
} else {
V_62 [ V_93 ] ^= ( 1 << V_94 ) ;
}
F_34 ( V_2 -> V_50 , L_12 ) ;
return 1 ;
}
static void F_35 ( struct V_5 * V_6 , int V_103 )
{
if ( F_30 () ) {
struct V_9 * V_9 = V_6 -> V_10 ;
struct V_1 * V_2 = V_9 -> V_10 ;
F_31 ( V_2 -> V_65 , V_80 , V_81 ) ;
}
}
static int T_7 F_36 ( struct V_104 * V_105 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_9 * V_9 ;
struct V_106 * V_107 ;
struct V_106 * V_108 ;
int V_109 ;
V_108 = F_37 ( V_105 , V_110 , 0 ) ;
if ( ! V_108 ) {
F_38 ( V_111 L_13 ) ;
return - V_112 ;
}
V_2 = F_39 ( sizeof( struct V_1 ) , V_113 ) ;
if ( ! V_2 ) {
F_38 ( V_111 L_14 ) ;
return - V_114 ;
}
V_2 -> V_51 = ( T_1 ) V_108 -> V_115 ;
V_2 -> V_15 = F_40 ( V_108 -> V_115 , F_41 ( V_108 ) ) ;
if ( V_2 -> V_15 == NULL ) {
F_38 ( V_111 L_15 ) ;
V_109 = - V_37 ;
goto V_116;
}
V_6 = & V_2 -> V_6 ;
V_9 = & V_2 -> V_9 ;
V_2 -> V_3 = V_105 -> V_50 . V_117 ;
V_2 -> V_50 = & V_105 -> V_50 ;
V_9 -> V_10 = V_2 ;
V_6 -> V_10 = V_9 ;
V_6 -> V_118 = V_119 ;
V_9 -> V_60 = V_2 -> V_15 ;
V_9 -> V_61 = V_2 -> V_15 ;
V_9 -> V_120 = F_7 ;
if ( V_2 -> V_3 -> V_18 )
V_9 -> V_121 = F_9 ;
V_107 = F_37 ( V_105 , V_110 , 1 ) ;
if ( ! V_107 && V_122 ) {
F_38 ( V_111 L_16
L_17 ) ;
}
V_9 -> V_65 . V_103 = V_123 ;
if ( V_124 )
V_9 -> V_65 . V_103 = V_125 ;
if ( V_122 && V_107 ) {
V_2 -> V_65 = F_40 ( V_107 -> V_115 , F_41 ( V_107 ) ) ;
if ( V_2 -> V_65 == NULL ) {
F_38 ( V_111 L_15 ) ;
V_109 = - V_37 ;
goto V_126;
}
V_9 -> V_65 . V_103 = V_127 ;
V_9 -> V_65 . V_128 = F_27 ;
V_9 -> V_65 . V_86 = F_32 ;
V_9 -> V_65 . V_129 = F_35 ;
V_9 -> V_65 . V_130 = F_29 ;
V_9 -> V_65 . V_73 = 4 ;
}
V_9 -> V_131 = 20 ;
if ( V_2 -> V_3 -> V_132 )
V_9 -> V_101 |= V_102 ;
V_9 -> V_82 = F_23 ;
V_9 -> V_133 = F_25 ;
F_42 ( V_105 , V_2 ) ;
F_4 ( V_2 ) ;
if ( V_2 -> V_3 -> V_134 ) {
if ( F_10 ( V_2 -> V_3 -> V_134 ) ) {
F_38 ( V_135 L_18 ) ;
V_109 = - V_112 ;
goto V_136;
}
}
if ( V_137 ) {
F_38 ( V_135 L_19 ) ;
V_9 -> V_138 |= V_139 ;
}
if ( ! F_1 () )
V_58 = 0 ;
if ( V_58 ) {
T_8 V_140 ;
F_43 ( V_140 ) ;
F_44 ( V_141 , V_140 ) ;
V_2 -> V_44 = F_45 ( V_140 , NULL , NULL ) ;
if ( ! V_2 -> V_44 ) {
F_16 ( V_2 -> V_50 , L_20 ) ;
V_58 = 0 ;
}
}
if ( V_58 )
F_46 ( V_2 -> V_50 , L_21 ,
F_47 ( V_2 -> V_44 ) ) ;
else
F_46 ( V_2 -> V_50 , L_22 ) ;
if ( F_48 ( V_6 , 1 , NULL ) ) {
V_109 = - V_112 ;
goto V_142;
}
if ( V_9 -> V_65 . V_103 == V_127 ) {
V_9 -> V_65 . V_71 = V_6 -> V_85 ;
switch ( V_6 -> V_85 ) {
case 512 :
V_9 -> V_65 . V_75 = & V_143 ;
F_31 ( V_2 -> V_65 , V_144 , V_145 ) ;
break;
case 1024 :
V_9 -> V_65 . V_75 = & V_146 ;
F_31 ( V_2 -> V_65 , V_144 , V_147 ) ;
break;
case 2048 :
V_9 -> V_65 . V_75 = & V_146 ;
F_31 ( V_2 -> V_65 , V_144 , V_148 ) ;
break;
case 4096 :
V_9 -> V_65 . V_75 = & V_146 ;
F_31 ( V_2 -> V_65 , V_144 , V_149 ) ;
break;
default:
V_9 -> V_65 . V_103 = V_123 ;
V_9 -> V_65 . V_128 = NULL ;
V_9 -> V_65 . V_86 = NULL ;
V_9 -> V_65 . V_129 = NULL ;
V_9 -> V_65 . V_130 = NULL ;
V_9 -> V_65 . V_150 = 0 ;
V_9 -> V_65 . V_151 = 0 ;
V_9 -> V_65 . V_73 = 0 ;
break;
}
}
if ( F_49 ( V_6 ) ) {
V_109 = - V_112 ;
goto V_152;
}
V_6 -> V_153 = L_23 ;
V_109 = F_50 ( V_6 , NULL , 0 ,
V_2 -> V_3 -> V_154 , V_2 -> V_3 -> V_155 ) ;
if ( ! V_109 )
return V_109 ;
V_152:
V_142:
V_136:
F_6 ( V_2 ) ;
F_42 ( V_105 , NULL ) ;
if ( V_2 -> V_44 )
F_51 ( V_2 -> V_44 ) ;
if ( V_2 -> V_65 )
F_52 ( V_2 -> V_65 ) ;
V_126:
F_52 ( V_2 -> V_15 ) ;
V_116:
F_53 ( V_2 ) ;
return V_109 ;
}
static int T_9 F_54 ( struct V_104 * V_105 )
{
struct V_1 * V_2 = F_55 ( V_105 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_56 ( V_6 ) ;
F_6 ( V_2 ) ;
if ( V_2 -> V_65 )
F_52 ( V_2 -> V_65 ) ;
if ( V_2 -> V_44 )
F_51 ( V_2 -> V_44 ) ;
F_52 ( V_2 -> V_15 ) ;
F_53 ( V_2 ) ;
return 0 ;
}
static int T_7 F_57 ( void )
{
return F_58 ( & V_156 , F_36 ) ;
}
static void T_9 F_59 ( void )
{
F_60 ( & V_156 ) ;
}
