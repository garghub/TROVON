static int F_1 ( void )
{
return F_2 () || F_3 () ;
}
static void F_4 ( struct V_1 * V_2 )
{
if ( F_5 ( V_2 -> V_3 . V_4 ) )
F_6 ( V_2 -> V_3 . V_4 , 0 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
if ( F_5 ( V_2 -> V_3 . V_4 ) )
F_6 ( V_2 -> V_3 . V_4 , 1 ) ;
}
static void F_8 ( struct V_5 * V_6 , int V_7 , unsigned int V_8 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
struct V_1 * V_2 = V_9 -> V_10 ;
if ( V_8 & V_11 ) {
if ( V_8 & V_12 )
F_4 ( V_2 ) ;
else
F_7 ( V_2 ) ;
}
if ( V_7 == V_13 )
return;
if ( V_8 & V_14 )
F_9 ( V_7 , V_2 -> V_15 + ( 1 << V_2 -> V_3 . V_16 ) ) ;
else
F_9 ( V_7 , V_2 -> V_15 + ( 1 << V_2 -> V_3 . V_17 ) ) ;
}
static int F_10 ( struct V_5 * V_6 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
struct V_1 * V_2 = V_9 -> V_10 ;
return F_11 ( V_2 -> V_3 . V_18 ) ^
! ! V_2 -> V_3 . V_19 ;
}
static void F_12 ( struct V_5 * V_6 , T_1 * V_20 , int V_21 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
F_13 ( V_9 -> V_22 , V_20 , V_21 ) ;
}
static void F_14 ( struct V_5 * V_6 , T_1 * V_20 , int V_21 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
F_15 ( V_9 -> V_22 , V_20 , V_21 / 2 ) ;
}
static void F_16 ( struct V_5 * V_6 , const T_1 * V_20 , int V_21 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
F_17 ( V_9 -> V_23 , V_20 , V_21 ) ;
}
static void F_18 ( struct V_5 * V_6 , const T_1 * V_20 , int V_21 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
F_19 ( V_9 -> V_23 , V_20 , V_21 / 2 ) ;
}
static void F_20 ( void * V_24 )
{
F_21 ( V_24 ) ;
}
static int F_22 ( struct V_5 * V_6 , void * V_20 , int V_21 ,
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
V_32 = F_23 ( V_27 -> V_52 , V_37 , V_21 , V_41 ) ;
if ( F_24 ( V_27 -> V_52 , V_32 ) ) {
F_25 ( V_2 -> V_52 , L_1 ) ;
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
F_25 ( V_2 -> V_52 , L_2 ) ;
goto V_55;
}
F_26 ( & V_2 -> V_56 ) ;
V_34 -> V_57 = F_20 ;
V_34 -> V_58 = & V_2 -> V_56 ;
V_35 = V_34 -> V_59 ( V_34 ) ;
if ( F_27 ( V_35 ) ) {
F_25 ( V_2 -> V_52 , L_3 ) ;
goto V_55;
}
F_28 ( V_2 -> V_46 ) ;
F_29 ( & V_2 -> V_56 ) ;
V_38 = 0 ;
V_55:
F_30 ( V_27 -> V_52 , V_32 , V_21 , V_41 ) ;
V_45:
if ( V_38 != 0 )
F_31 ( V_2 -> V_52 , L_4 ) ;
return V_38 ;
}
static void F_32 ( struct V_5 * V_6 , T_1 * V_20 , int V_21 )
{
struct V_9 * V_36 = V_6 -> V_10 ;
struct V_1 * V_2 = V_36 -> V_10 ;
if ( V_60 && V_21 > V_6 -> V_61 )
if ( F_22 ( V_6 , V_20 , V_21 , 1 ) == 0 )
return;
if ( V_2 -> V_3 . V_62 )
F_14 ( V_6 , V_20 , V_21 ) ;
else
F_12 ( V_6 , V_20 , V_21 ) ;
}
static void F_33 ( struct V_5 * V_6 , const T_1 * V_20 , int V_21 )
{
struct V_9 * V_36 = V_6 -> V_10 ;
struct V_1 * V_2 = V_36 -> V_10 ;
if ( V_60 && V_21 > V_6 -> V_61 )
if ( F_22 ( V_6 , ( void * ) V_20 , V_21 , 0 ) == 0 )
return;
if ( V_2 -> V_3 . V_62 )
F_18 ( V_6 , V_20 , V_21 ) ;
else
F_16 ( V_6 , V_20 , V_21 ) ;
}
static int F_34 ( struct V_5 * V_6 ,
const T_4 * V_63 , unsigned char * V_64 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
struct V_1 * V_2 = V_9 -> V_10 ;
unsigned int V_65 ;
V_65 = F_35 ( V_2 -> V_66 , V_67 ) ;
V_64 [ 0 ] = V_65 & 0xFF ;
V_64 [ 1 ] = ( V_65 >> 8 ) & 0xFF ;
V_65 = F_35 ( V_2 -> V_66 , V_68 ) & V_69 ;
V_64 [ 2 ] = V_65 & 0xFF ;
V_64 [ 3 ] = ( V_65 >> 8 ) & 0xFF ;
return 0 ;
}
static int F_36 ( struct V_5 * V_6 , struct V_9 * V_36 ,
T_5 * V_20 , int V_70 , int V_71 )
{
int V_72 = V_36 -> V_66 . V_73 ;
int V_74 = V_36 -> V_66 . V_75 ;
T_6 * V_76 = V_36 -> V_66 . V_77 -> V_76 ;
T_5 * V_37 = V_20 ;
T_5 * V_78 = V_36 -> V_79 ;
T_5 * V_80 ;
int V_81 ;
unsigned int V_82 = 0 ;
if ( F_37 () ) {
struct V_1 * V_2 = V_36 -> V_10 ;
F_38 ( V_2 -> V_66 , V_83 , V_84 ) ;
}
V_36 -> V_85 ( V_6 , V_37 , V_72 ) ;
if ( V_76 [ 0 ] != 0 ) {
V_36 -> V_86 ( V_6 , V_87 ,
V_6 -> V_88 + V_76 [ 0 ] , - 1 ) ;
}
V_80 = V_78 + V_76 [ 0 ] ;
V_36 -> V_85 ( V_6 , V_80 , V_74 ) ;
V_81 = V_36 -> V_66 . V_89 ( V_6 , V_37 , V_78 , NULL ) ;
if ( V_81 < 0 ) {
V_6 -> V_90 . V_91 ++ ;
} else {
V_6 -> V_90 . V_92 += V_81 ;
V_82 = F_39 (unsigned int, max_bitflips, stat) ;
}
V_36 -> V_86 ( V_6 , V_87 , V_6 -> V_88 , - 1 ) ;
V_36 -> V_85 ( V_6 , V_78 , V_6 -> V_61 ) ;
return V_82 ;
}
static int F_40 ( struct V_5 * V_6 , T_4 * V_63 ,
T_4 * V_93 , T_4 * V_94 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
struct V_1 * V_2 = V_9 -> V_10 ;
unsigned int V_95 ;
unsigned int V_96 , V_97 ;
V_95 = F_35 ( V_2 -> V_66 , V_98 ) ;
if ( F_41 ( ! ( V_95 & V_99 ) ) )
return 0 ;
V_97 = F_35 ( V_2 -> V_66 , V_67 ) & V_100 ;
V_96 = F_35 ( V_2 -> V_66 , V_67 ) & V_101 ;
V_96 >>= 4 ;
if ( V_95 & V_102 ) {
if ( ( V_97 == V_100 )
&& ( V_96 == ( V_101 >> 4 ) ) ) {
return 0 ;
}
F_42 ( V_2 -> V_52 , L_5
L_6 ) ;
return - V_39 ;
}
if ( V_95 & V_103 ) {
F_42 ( V_2 -> V_52 , L_7
L_8 ) ;
return 0 ;
}
F_42 ( V_2 -> V_52 , L_9
L_10
L_11 ,
V_96 , V_97 ) ;
if ( V_9 -> V_104 & V_105 ) {
( ( unsigned short * ) V_63 ) [ V_96 ] ^= ( 1 << V_97 ) ;
} else {
V_63 [ V_96 ] ^= ( 1 << V_97 ) ;
}
F_42 ( V_2 -> V_52 , L_12 ) ;
return 1 ;
}
static void F_43 ( struct V_5 * V_6 , int V_106 )
{
if ( F_37 () ) {
struct V_9 * V_9 = V_6 -> V_10 ;
struct V_1 * V_2 = V_9 -> V_10 ;
F_38 ( V_2 -> V_66 , V_83 , V_84 ) ;
}
}
static int T_7 F_44 ( struct V_1 * V_2 ,
struct V_107 * V_108 )
{
T_8 V_109 ;
int V_110 ;
struct V_111 * V_3 = & V_2 -> V_3 ;
enum V_112 V_29 ;
if ( F_45 ( V_108 , L_13 , & V_109 ) == 0 ) {
if ( V_109 >= 32 ) {
F_25 ( V_2 -> V_52 , L_14 , V_109 ) ;
return - V_113 ;
}
V_3 -> V_17 = V_109 ;
}
if ( F_45 ( V_108 , L_15 , & V_109 ) == 0 ) {
if ( V_109 >= 32 ) {
F_25 ( V_2 -> V_52 , L_16 , V_109 ) ;
return - V_113 ;
}
V_3 -> V_16 = V_109 ;
}
V_110 = F_46 ( V_108 ) ;
V_3 -> V_110 = V_110 < 0 ? V_114 : V_110 ;
V_3 -> V_115 = F_47 ( V_108 ) ;
if ( F_48 ( V_108 ) == 16 )
V_3 -> V_62 = 1 ;
V_3 -> V_18 = F_49 ( V_108 , 0 , & V_29 ) ;
V_3 -> V_19 = ( V_29 == V_116 ) ;
V_3 -> V_4 = F_50 ( V_108 , 1 ) ;
V_3 -> V_117 = F_50 ( V_108 , 2 ) ;
return 0 ;
}
static int T_7 F_44 ( struct V_1 * V_2 ,
struct V_107 * V_108 )
{
return - V_113 ;
}
static int T_9 F_51 ( struct V_118 * V_119 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_9 * V_9 ;
struct V_120 * V_121 ;
struct V_120 * V_122 ;
struct V_123 V_124 = {} ;
int V_125 ;
V_122 = F_52 ( V_119 , V_126 , 0 ) ;
if ( ! V_122 ) {
F_53 ( V_127 L_17 ) ;
return - V_128 ;
}
V_2 = F_54 ( sizeof( struct V_1 ) , V_129 ) ;
if ( ! V_2 ) {
F_53 ( V_127 L_18 ) ;
return - V_130 ;
}
V_2 -> V_53 = ( T_2 ) V_122 -> V_131 ;
V_2 -> V_15 = F_55 ( V_122 -> V_131 , F_56 ( V_122 ) ) ;
if ( V_2 -> V_15 == NULL ) {
F_53 ( V_127 L_19 ) ;
V_125 = - V_39 ;
goto V_132;
}
V_6 = & V_2 -> V_6 ;
V_9 = & V_2 -> V_9 ;
V_2 -> V_52 = & V_119 -> V_52 ;
if ( V_119 -> V_52 . V_133 ) {
V_125 = F_44 ( V_2 , V_119 -> V_52 . V_133 ) ;
if ( V_125 )
goto V_132;
} else {
memcpy ( & V_2 -> V_3 , V_119 -> V_52 . V_134 ,
sizeof( struct V_111 ) ) ;
}
V_9 -> V_10 = V_2 ;
V_6 -> V_10 = V_9 ;
V_6 -> V_135 = V_136 ;
V_9 -> V_22 = V_2 -> V_15 ;
V_9 -> V_23 = V_2 -> V_15 ;
V_9 -> V_137 = F_8 ;
if ( F_5 ( V_2 -> V_3 . V_18 ) )
V_9 -> V_138 = F_10 ;
V_9 -> V_66 . V_106 = V_2 -> V_3 . V_110 ;
V_121 = F_52 ( V_119 , V_126 , 1 ) ;
if ( ! V_121 && V_9 -> V_66 . V_106 == V_139 ) {
F_53 ( V_127 L_20
L_21 ) ;
V_9 -> V_66 . V_106 = V_114 ;
}
if ( V_9 -> V_66 . V_106 == V_139 ) {
V_2 -> V_66 = F_55 ( V_121 -> V_131 , F_56 ( V_121 ) ) ;
if ( V_2 -> V_66 == NULL ) {
F_53 ( V_127 L_19 ) ;
V_125 = - V_39 ;
goto V_140;
}
V_9 -> V_66 . V_141 = F_34 ;
V_9 -> V_66 . V_89 = F_40 ;
V_9 -> V_66 . V_142 = F_43 ;
V_9 -> V_66 . V_143 = F_36 ;
V_9 -> V_66 . V_75 = 4 ;
V_9 -> V_66 . V_144 = 1 ;
}
V_9 -> V_145 = 20 ;
if ( V_2 -> V_3 . V_62 )
V_9 -> V_104 |= V_105 ;
V_9 -> V_85 = F_32 ;
V_9 -> V_146 = F_33 ;
F_57 ( V_119 , V_2 ) ;
F_4 ( V_2 ) ;
if ( F_5 ( V_2 -> V_3 . V_117 ) ) {
if ( F_11 ( V_2 -> V_3 . V_117 ) ) {
F_53 ( V_147 L_22 ) ;
V_125 = - V_128 ;
goto V_148;
}
}
if ( V_2 -> V_3 . V_115 || V_115 ) {
F_53 ( V_147 L_23 ) ;
V_9 -> V_149 |= V_150 ;
}
if ( ! F_1 () )
V_60 = 0 ;
if ( V_60 ) {
T_10 V_151 ;
F_58 ( V_151 ) ;
F_59 ( V_152 , V_151 ) ;
V_2 -> V_46 = F_60 ( V_151 , NULL , NULL ) ;
if ( ! V_2 -> V_46 ) {
F_25 ( V_2 -> V_52 , L_24 ) ;
V_60 = 0 ;
}
}
if ( V_60 )
F_61 ( V_2 -> V_52 , L_25 ,
F_62 ( V_2 -> V_46 ) ) ;
else
F_61 ( V_2 -> V_52 , L_26 ) ;
if ( F_63 ( V_6 , 1 , NULL ) ) {
V_125 = - V_128 ;
goto V_153;
}
if ( V_9 -> V_66 . V_106 == V_139 ) {
V_9 -> V_66 . V_73 = V_6 -> V_88 ;
switch ( V_6 -> V_88 ) {
case 512 :
V_9 -> V_66 . V_77 = & V_154 ;
F_38 ( V_2 -> V_66 , V_155 , V_156 ) ;
break;
case 1024 :
V_9 -> V_66 . V_77 = & V_157 ;
F_38 ( V_2 -> V_66 , V_155 , V_158 ) ;
break;
case 2048 :
V_9 -> V_66 . V_77 = & V_157 ;
F_38 ( V_2 -> V_66 , V_155 , V_159 ) ;
break;
case 4096 :
V_9 -> V_66 . V_77 = & V_157 ;
F_38 ( V_2 -> V_66 , V_155 , V_160 ) ;
break;
default:
V_9 -> V_66 . V_106 = V_114 ;
V_9 -> V_66 . V_141 = NULL ;
V_9 -> V_66 . V_89 = NULL ;
V_9 -> V_66 . V_142 = NULL ;
V_9 -> V_66 . V_143 = NULL ;
V_9 -> V_66 . V_161 = 0 ;
V_9 -> V_66 . V_162 = 0 ;
V_9 -> V_66 . V_75 = 0 ;
break;
}
}
if ( F_64 ( V_6 ) ) {
V_125 = - V_128 ;
goto V_163;
}
V_6 -> V_164 = L_27 ;
V_124 . V_133 = V_119 -> V_52 . V_133 ;
V_125 = F_65 ( V_6 , NULL , & V_124 ,
V_2 -> V_3 . V_165 , V_2 -> V_3 . V_166 ) ;
if ( ! V_125 )
return V_125 ;
V_163:
V_153:
V_148:
F_7 ( V_2 ) ;
F_57 ( V_119 , NULL ) ;
if ( V_2 -> V_46 )
F_66 ( V_2 -> V_46 ) ;
if ( V_2 -> V_66 )
F_67 ( V_2 -> V_66 ) ;
V_140:
F_67 ( V_2 -> V_15 ) ;
V_132:
F_68 ( V_2 ) ;
return V_125 ;
}
static int T_11 F_69 ( struct V_118 * V_119 )
{
struct V_1 * V_2 = F_70 ( V_119 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_71 ( V_6 ) ;
F_7 ( V_2 ) ;
if ( V_2 -> V_66 )
F_67 ( V_2 -> V_66 ) ;
if ( V_2 -> V_46 )
F_66 ( V_2 -> V_46 ) ;
F_67 ( V_2 -> V_15 ) ;
F_68 ( V_2 ) ;
return 0 ;
}
static int T_9 F_72 ( void )
{
return F_73 ( & V_167 , F_51 ) ;
}
static void T_11 F_74 ( void )
{
F_75 ( & V_167 ) ;
}
