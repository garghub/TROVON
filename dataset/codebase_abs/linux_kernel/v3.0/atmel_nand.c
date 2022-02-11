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
static void F_11 ( struct V_5 * V_6 , T_1 * V_20 , int V_21 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
F_12 ( V_9 -> V_22 , V_20 , V_21 ) ;
}
static void F_13 ( struct V_5 * V_6 , T_1 * V_20 , int V_21 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
F_14 ( V_9 -> V_22 , V_20 , V_21 / 2 ) ;
}
static void F_15 ( struct V_5 * V_6 , const T_1 * V_20 , int V_21 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
F_16 ( V_9 -> V_23 , V_20 , V_21 ) ;
}
static void F_17 ( struct V_5 * V_6 , const T_1 * V_20 , int V_21 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
F_18 ( V_9 -> V_23 , V_20 , V_21 / 2 ) ;
}
static void F_19 ( void * V_24 )
{
F_20 ( V_24 ) ;
}
static int F_21 ( struct V_5 * V_6 , void * V_20 , int V_21 ,
int V_25 )
{
struct V_26 * V_27 ;
enum V_28 V_29 ;
T_2 V_30 , V_31 , V_32 ;
struct V_33 * V_34 = NULL ;
T_3 V_35 ;
struct V_9 * V_36 = V_6 -> V_10 ;
struct V_1 * V_2 = V_36 -> V_10 ;
void * V_37 = V_20 ;
int V_38 = - V_39 ;
enum V_40 V_41 = V_25 ? V_42 : V_43 ;
if ( V_20 >= V_44 )
goto V_45;
V_27 = V_2 -> V_46 -> V_47 ;
V_29 = V_48 | V_49 | V_50 |
V_51 ;
V_32 = F_22 ( V_27 -> V_52 , V_37 , V_21 , V_41 ) ;
if ( F_23 ( V_27 -> V_52 , V_32 ) ) {
F_24 ( V_2 -> V_52 , L_1 ) ;
goto V_45;
}
if ( V_25 ) {
V_30 = V_2 -> V_53 ;
V_31 = V_32 ;
} else {
V_30 = V_32 ;
V_31 = V_2 -> V_53 ;
}
V_34 = V_27 -> V_54 ( V_2 -> V_46 , V_31 ,
V_30 , V_21 , V_29 ) ;
if ( ! V_34 ) {
F_24 ( V_2 -> V_52 , L_2 ) ;
goto V_55;
}
F_25 ( & V_2 -> V_56 ) ;
V_34 -> V_57 = F_19 ;
V_34 -> V_58 = & V_2 -> V_56 ;
V_35 = V_34 -> V_59 ( V_34 ) ;
if ( F_26 ( V_35 ) ) {
F_24 ( V_2 -> V_52 , L_3 ) ;
goto V_55;
}
F_27 ( V_2 -> V_46 ) ;
F_28 ( & V_2 -> V_56 ) ;
V_38 = 0 ;
V_55:
F_29 ( V_27 -> V_52 , V_32 , V_21 , V_41 ) ;
V_45:
if ( V_38 != 0 )
F_30 ( V_2 -> V_52 , L_4 ) ;
return V_38 ;
}
static void F_31 ( struct V_5 * V_6 , T_1 * V_20 , int V_21 )
{
struct V_9 * V_36 = V_6 -> V_10 ;
struct V_1 * V_2 = V_36 -> V_10 ;
if ( V_60 && V_21 > V_6 -> V_61 )
if ( F_21 ( V_6 , V_20 , V_21 , 1 ) == 0 )
return;
if ( V_2 -> V_3 -> V_62 )
F_13 ( V_6 , V_20 , V_21 ) ;
else
F_11 ( V_6 , V_20 , V_21 ) ;
}
static void F_32 ( struct V_5 * V_6 , const T_1 * V_20 , int V_21 )
{
struct V_9 * V_36 = V_6 -> V_10 ;
struct V_1 * V_2 = V_36 -> V_10 ;
if ( V_60 && V_21 > V_6 -> V_61 )
if ( F_21 ( V_6 , ( void * ) V_20 , V_21 , 0 ) == 0 )
return;
if ( V_2 -> V_3 -> V_62 )
F_17 ( V_6 , V_20 , V_21 ) ;
else
F_15 ( V_6 , V_20 , V_21 ) ;
}
static int F_33 ( struct V_5 * V_6 ,
const T_4 * V_63 , unsigned char * V_64 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
struct V_1 * V_2 = V_9 -> V_10 ;
unsigned int V_65 ;
V_65 = F_34 ( V_2 -> V_66 , V_67 ) ;
V_64 [ 0 ] = V_65 & 0xFF ;
V_64 [ 1 ] = ( V_65 >> 8 ) & 0xFF ;
V_65 = F_34 ( V_2 -> V_66 , V_68 ) & V_69 ;
V_64 [ 2 ] = V_65 & 0xFF ;
V_64 [ 3 ] = ( V_65 >> 8 ) & 0xFF ;
return 0 ;
}
static int F_35 ( struct V_5 * V_6 ,
struct V_9 * V_36 , T_5 * V_20 , int V_70 )
{
int V_71 = V_36 -> V_66 . V_72 ;
int V_73 = V_36 -> V_66 . V_74 ;
T_6 * V_75 = V_36 -> V_66 . V_76 -> V_75 ;
T_5 * V_37 = V_20 ;
T_5 * V_77 = V_36 -> V_78 ;
T_5 * V_79 ;
int V_80 ;
if ( F_36 () ) {
struct V_1 * V_2 = V_36 -> V_10 ;
F_37 ( V_2 -> V_66 , V_81 , V_82 ) ;
}
V_36 -> V_83 ( V_6 , V_37 , V_71 ) ;
if ( V_75 [ 0 ] != 0 ) {
V_36 -> V_84 ( V_6 , V_85 ,
V_6 -> V_86 + V_75 [ 0 ] , - 1 ) ;
}
V_79 = V_77 + V_75 [ 0 ] ;
V_36 -> V_83 ( V_6 , V_79 , V_73 ) ;
V_80 = V_36 -> V_66 . V_87 ( V_6 , V_37 , V_77 , NULL ) ;
if ( V_80 < 0 )
V_6 -> V_88 . V_89 ++ ;
else
V_6 -> V_88 . V_90 += V_80 ;
V_36 -> V_84 ( V_6 , V_85 , V_6 -> V_86 , - 1 ) ;
V_36 -> V_83 ( V_6 , V_77 , V_6 -> V_61 ) ;
return 0 ;
}
static int F_38 ( struct V_5 * V_6 , T_4 * V_63 ,
T_4 * V_91 , T_4 * V_92 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
struct V_1 * V_2 = V_9 -> V_10 ;
unsigned int V_93 ;
unsigned int V_94 , V_95 ;
V_93 = F_34 ( V_2 -> V_66 , V_96 ) ;
if ( F_39 ( ! ( V_93 & V_97 ) ) )
return 0 ;
V_95 = F_34 ( V_2 -> V_66 , V_67 ) & V_98 ;
V_94 = F_34 ( V_2 -> V_66 , V_67 ) & V_99 ;
V_94 >>= 4 ;
if ( V_93 & V_100 ) {
if ( ( V_95 == V_98 )
&& ( V_94 == ( V_99 >> 4 ) ) ) {
return 0 ;
}
F_40 ( V_2 -> V_52 , L_5
L_6 ) ;
return - V_39 ;
}
if ( V_93 & V_101 ) {
F_40 ( V_2 -> V_52 , L_7
L_8 ) ;
return 0 ;
}
F_40 ( V_2 -> V_52 , L_9
L_10
L_11 ,
V_94 , V_95 ) ;
if ( V_9 -> V_102 & V_103 ) {
( ( unsigned short * ) V_63 ) [ V_94 ] ^= ( 1 << V_95 ) ;
} else {
V_63 [ V_94 ] ^= ( 1 << V_95 ) ;
}
F_40 ( V_2 -> V_52 , L_12 ) ;
return 1 ;
}
static void F_41 ( struct V_5 * V_6 , int V_104 )
{
if ( F_36 () ) {
struct V_9 * V_9 = V_6 -> V_10 ;
struct V_1 * V_2 = V_9 -> V_10 ;
F_37 ( V_2 -> V_66 , V_81 , V_82 ) ;
}
}
static int T_7 F_42 ( struct V_105 * V_106 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_9 * V_9 ;
struct V_107 * V_108 ;
struct V_107 * V_109 ;
int V_110 ;
struct V_111 * V_112 = NULL ;
int V_113 = 0 ;
V_109 = F_43 ( V_106 , V_114 , 0 ) ;
if ( ! V_109 ) {
F_44 ( V_115 L_13 ) ;
return - V_116 ;
}
V_2 = F_45 ( sizeof( struct V_1 ) , V_117 ) ;
if ( ! V_2 ) {
F_44 ( V_115 L_14 ) ;
return - V_118 ;
}
V_2 -> V_53 = ( T_2 ) V_109 -> V_119 ;
V_2 -> V_15 = F_46 ( V_109 -> V_119 , V_109 -> V_120 - V_109 -> V_119 + 1 ) ;
if ( V_2 -> V_15 == NULL ) {
F_44 ( V_115 L_15 ) ;
V_110 = - V_39 ;
goto V_121;
}
V_6 = & V_2 -> V_6 ;
V_9 = & V_2 -> V_9 ;
V_2 -> V_3 = V_106 -> V_52 . V_122 ;
V_2 -> V_52 = & V_106 -> V_52 ;
V_9 -> V_10 = V_2 ;
V_6 -> V_10 = V_9 ;
V_6 -> V_123 = V_124 ;
V_9 -> V_22 = V_2 -> V_15 ;
V_9 -> V_23 = V_2 -> V_15 ;
V_9 -> V_125 = F_7 ;
if ( V_2 -> V_3 -> V_18 )
V_9 -> V_126 = F_9 ;
V_108 = F_43 ( V_106 , V_114 , 1 ) ;
if ( ! V_108 && V_127 ) {
F_44 ( V_115 L_16
L_17 ) ;
}
V_9 -> V_66 . V_104 = V_128 ;
if ( V_129 )
V_9 -> V_66 . V_104 = V_130 ;
if ( V_127 && V_108 ) {
V_2 -> V_66 = F_46 ( V_108 -> V_119 , V_108 -> V_120 - V_108 -> V_119 + 1 ) ;
if ( V_2 -> V_66 == NULL ) {
F_44 ( V_115 L_15 ) ;
V_110 = - V_39 ;
goto V_131;
}
V_9 -> V_66 . V_104 = V_132 ;
V_9 -> V_66 . V_133 = F_33 ;
V_9 -> V_66 . V_87 = F_38 ;
V_9 -> V_66 . V_134 = F_41 ;
V_9 -> V_66 . V_135 = F_35 ;
V_9 -> V_66 . V_74 = 4 ;
}
V_9 -> V_136 = 20 ;
if ( V_2 -> V_3 -> V_62 )
V_9 -> V_102 |= V_103 ;
V_9 -> V_83 = F_31 ;
V_9 -> V_137 = F_32 ;
F_47 ( V_106 , V_2 ) ;
F_4 ( V_2 ) ;
if ( V_2 -> V_3 -> V_138 ) {
if ( F_10 ( V_2 -> V_3 -> V_138 ) ) {
F_44 ( V_139 L_18 ) ;
V_110 = - V_116 ;
goto V_140;
}
}
if ( V_141 ) {
F_44 ( V_139 L_19 ) ;
V_9 -> V_102 |= V_142 ;
}
if ( ! F_1 () )
V_60 = 0 ;
if ( V_60 ) {
T_8 V_143 ;
F_48 ( V_143 ) ;
F_49 ( V_144 , V_143 ) ;
V_2 -> V_46 = F_50 ( V_143 , 0 , NULL ) ;
if ( ! V_2 -> V_46 ) {
F_24 ( V_2 -> V_52 , L_20 ) ;
V_60 = 0 ;
}
}
if ( V_60 )
F_51 ( V_2 -> V_52 , L_21 ,
F_52 ( V_2 -> V_46 ) ) ;
else
F_51 ( V_2 -> V_52 , L_22 ) ;
if ( F_53 ( V_6 , 1 , NULL ) ) {
V_110 = - V_116 ;
goto V_145;
}
if ( V_9 -> V_66 . V_104 == V_132 ) {
V_9 -> V_66 . V_72 = V_6 -> V_86 ;
switch ( V_6 -> V_86 ) {
case 512 :
V_9 -> V_66 . V_76 = & V_146 ;
F_37 ( V_2 -> V_66 , V_147 , V_148 ) ;
break;
case 1024 :
V_9 -> V_66 . V_76 = & V_149 ;
F_37 ( V_2 -> V_66 , V_147 , V_150 ) ;
break;
case 2048 :
V_9 -> V_66 . V_76 = & V_149 ;
F_37 ( V_2 -> V_66 , V_147 , V_151 ) ;
break;
case 4096 :
V_9 -> V_66 . V_76 = & V_149 ;
F_37 ( V_2 -> V_66 , V_147 , V_152 ) ;
break;
default:
V_9 -> V_66 . V_104 = V_128 ;
V_9 -> V_66 . V_133 = NULL ;
V_9 -> V_66 . V_87 = NULL ;
V_9 -> V_66 . V_134 = NULL ;
V_9 -> V_66 . V_135 = NULL ;
V_9 -> V_66 . V_153 = 0 ;
V_9 -> V_66 . V_154 = 0 ;
V_9 -> V_66 . V_74 = 0 ;
break;
}
}
if ( F_54 ( V_6 ) ) {
V_110 = - V_116 ;
goto V_155;
}
#ifdef F_55
V_6 -> V_156 = L_23 ;
V_113 = F_56 ( V_6 , V_157 ,
& V_112 , 0 ) ;
#endif
if ( V_113 <= 0 && V_2 -> V_3 -> V_158 )
V_112 = V_2 -> V_3 -> V_158 ( V_6 -> V_72 ,
& V_113 ) ;
if ( ( ! V_112 ) || ( V_113 == 0 ) ) {
F_44 ( V_115 L_24 ) ;
V_110 = - V_116 ;
goto V_159;
}
V_110 = F_57 ( V_6 , V_112 , V_113 ) ;
if ( ! V_110 )
return V_110 ;
V_159:
F_58 ( V_6 ) ;
V_155:
V_145:
V_140:
F_6 ( V_2 ) ;
F_47 ( V_106 , NULL ) ;
if ( V_2 -> V_46 )
F_59 ( V_2 -> V_46 ) ;
if ( V_2 -> V_66 )
F_60 ( V_2 -> V_66 ) ;
V_131:
F_60 ( V_2 -> V_15 ) ;
V_121:
F_61 ( V_2 ) ;
return V_110 ;
}
static int T_9 F_62 ( struct V_105 * V_106 )
{
struct V_1 * V_2 = F_63 ( V_106 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_58 ( V_6 ) ;
F_6 ( V_2 ) ;
if ( V_2 -> V_66 )
F_60 ( V_2 -> V_66 ) ;
if ( V_2 -> V_46 )
F_59 ( V_2 -> V_46 ) ;
F_60 ( V_2 -> V_15 ) ;
F_61 ( V_2 ) ;
return 0 ;
}
static int T_7 F_64 ( void )
{
return F_65 ( & V_160 , F_42 ) ;
}
static void T_9 F_66 ( void )
{
F_67 ( & V_160 ) ;
}
