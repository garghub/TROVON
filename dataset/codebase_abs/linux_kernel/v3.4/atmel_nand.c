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
static int F_36 ( struct V_5 * V_6 ,
struct V_9 * V_36 , T_5 * V_20 , int V_70 )
{
int V_71 = V_36 -> V_66 . V_72 ;
int V_73 = V_36 -> V_66 . V_74 ;
T_6 * V_75 = V_36 -> V_66 . V_76 -> V_75 ;
T_5 * V_37 = V_20 ;
T_5 * V_77 = V_36 -> V_78 ;
T_5 * V_79 ;
int V_80 ;
if ( F_37 () ) {
struct V_1 * V_2 = V_36 -> V_10 ;
F_38 ( V_2 -> V_66 , V_81 , V_82 ) ;
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
static int F_39 ( struct V_5 * V_6 , T_4 * V_63 ,
T_4 * V_91 , T_4 * V_92 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
struct V_1 * V_2 = V_9 -> V_10 ;
unsigned int V_93 ;
unsigned int V_94 , V_95 ;
V_93 = F_35 ( V_2 -> V_66 , V_96 ) ;
if ( F_40 ( ! ( V_93 & V_97 ) ) )
return 0 ;
V_95 = F_35 ( V_2 -> V_66 , V_67 ) & V_98 ;
V_94 = F_35 ( V_2 -> V_66 , V_67 ) & V_99 ;
V_94 >>= 4 ;
if ( V_93 & V_100 ) {
if ( ( V_95 == V_98 )
&& ( V_94 == ( V_99 >> 4 ) ) ) {
return 0 ;
}
F_41 ( V_2 -> V_52 , L_5
L_6 ) ;
return - V_39 ;
}
if ( V_93 & V_101 ) {
F_41 ( V_2 -> V_52 , L_7
L_8 ) ;
return 0 ;
}
F_41 ( V_2 -> V_52 , L_9
L_10
L_11 ,
V_94 , V_95 ) ;
if ( V_9 -> V_102 & V_103 ) {
( ( unsigned short * ) V_63 ) [ V_94 ] ^= ( 1 << V_95 ) ;
} else {
V_63 [ V_94 ] ^= ( 1 << V_95 ) ;
}
F_41 ( V_2 -> V_52 , L_12 ) ;
return 1 ;
}
static void F_42 ( struct V_5 * V_6 , int V_104 )
{
if ( F_37 () ) {
struct V_9 * V_9 = V_6 -> V_10 ;
struct V_1 * V_2 = V_9 -> V_10 ;
F_38 ( V_2 -> V_66 , V_81 , V_82 ) ;
}
}
static int T_7 F_43 ( struct V_1 * V_2 ,
struct V_105 * V_106 )
{
T_8 V_107 ;
int V_108 ;
struct V_109 * V_3 = & V_2 -> V_3 ;
enum V_110 V_29 ;
if ( F_44 ( V_106 , L_13 , & V_107 ) == 0 ) {
if ( V_107 >= 32 ) {
F_25 ( V_2 -> V_52 , L_14 , V_107 ) ;
return - V_111 ;
}
V_3 -> V_17 = V_107 ;
}
if ( F_44 ( V_106 , L_15 , & V_107 ) == 0 ) {
if ( V_107 >= 32 ) {
F_25 ( V_2 -> V_52 , L_16 , V_107 ) ;
return - V_111 ;
}
V_3 -> V_16 = V_107 ;
}
V_108 = F_45 ( V_106 ) ;
V_3 -> V_108 = V_108 < 0 ? V_112 : V_108 ;
V_3 -> V_113 = F_46 ( V_106 ) ;
if ( F_47 ( V_106 ) == 16 )
V_3 -> V_62 = 1 ;
V_3 -> V_18 = F_48 ( V_106 , 0 , & V_29 ) ;
V_3 -> V_19 = ( V_29 == V_114 ) ;
V_3 -> V_4 = F_49 ( V_106 , 1 ) ;
V_3 -> V_115 = F_49 ( V_106 , 2 ) ;
return 0 ;
}
static int T_7 F_43 ( struct V_1 * V_2 ,
struct V_105 * V_106 )
{
return - V_111 ;
}
static int T_9 F_50 ( struct V_116 * V_117 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_9 * V_9 ;
struct V_118 * V_119 ;
struct V_118 * V_120 ;
struct V_121 V_122 = {} ;
int V_123 ;
V_120 = F_51 ( V_117 , V_124 , 0 ) ;
if ( ! V_120 ) {
F_52 ( V_125 L_17 ) ;
return - V_126 ;
}
V_2 = F_53 ( sizeof( struct V_1 ) , V_127 ) ;
if ( ! V_2 ) {
F_52 ( V_125 L_18 ) ;
return - V_128 ;
}
V_2 -> V_53 = ( T_2 ) V_120 -> V_129 ;
V_2 -> V_15 = F_54 ( V_120 -> V_129 , F_55 ( V_120 ) ) ;
if ( V_2 -> V_15 == NULL ) {
F_52 ( V_125 L_19 ) ;
V_123 = - V_39 ;
goto V_130;
}
V_6 = & V_2 -> V_6 ;
V_9 = & V_2 -> V_9 ;
V_2 -> V_52 = & V_117 -> V_52 ;
if ( V_117 -> V_52 . V_131 ) {
V_123 = F_43 ( V_2 , V_117 -> V_52 . V_131 ) ;
if ( V_123 )
goto V_130;
} else {
memcpy ( & V_2 -> V_3 , V_117 -> V_52 . V_132 ,
sizeof( struct V_109 ) ) ;
}
V_9 -> V_10 = V_2 ;
V_6 -> V_10 = V_9 ;
V_6 -> V_133 = V_134 ;
V_9 -> V_22 = V_2 -> V_15 ;
V_9 -> V_23 = V_2 -> V_15 ;
V_9 -> V_135 = F_8 ;
if ( F_5 ( V_2 -> V_3 . V_18 ) )
V_9 -> V_136 = F_10 ;
V_9 -> V_66 . V_104 = V_2 -> V_3 . V_108 ;
V_119 = F_51 ( V_117 , V_124 , 1 ) ;
if ( ! V_119 && V_9 -> V_66 . V_104 == V_137 ) {
F_52 ( V_125 L_20
L_21 ) ;
V_9 -> V_66 . V_104 = V_112 ;
}
if ( V_9 -> V_66 . V_104 == V_137 ) {
V_2 -> V_66 = F_54 ( V_119 -> V_129 , F_55 ( V_119 ) ) ;
if ( V_2 -> V_66 == NULL ) {
F_52 ( V_125 L_19 ) ;
V_123 = - V_39 ;
goto V_138;
}
V_9 -> V_66 . V_139 = F_34 ;
V_9 -> V_66 . V_87 = F_39 ;
V_9 -> V_66 . V_140 = F_42 ;
V_9 -> V_66 . V_141 = F_36 ;
V_9 -> V_66 . V_74 = 4 ;
V_9 -> V_66 . V_142 = 1 ;
}
V_9 -> V_143 = 20 ;
if ( V_2 -> V_3 . V_62 )
V_9 -> V_102 |= V_103 ;
V_9 -> V_83 = F_32 ;
V_9 -> V_144 = F_33 ;
F_56 ( V_117 , V_2 ) ;
F_4 ( V_2 ) ;
if ( F_5 ( V_2 -> V_3 . V_115 ) ) {
if ( F_11 ( V_2 -> V_3 . V_115 ) ) {
F_52 ( V_145 L_22 ) ;
V_123 = - V_126 ;
goto V_146;
}
}
if ( V_2 -> V_3 . V_113 || V_113 ) {
F_52 ( V_145 L_23 ) ;
V_9 -> V_147 |= V_148 ;
}
if ( ! F_1 () )
V_60 = 0 ;
if ( V_60 ) {
T_10 V_149 ;
F_57 ( V_149 ) ;
F_58 ( V_150 , V_149 ) ;
V_2 -> V_46 = F_59 ( V_149 , NULL , NULL ) ;
if ( ! V_2 -> V_46 ) {
F_25 ( V_2 -> V_52 , L_24 ) ;
V_60 = 0 ;
}
}
if ( V_60 )
F_60 ( V_2 -> V_52 , L_25 ,
F_61 ( V_2 -> V_46 ) ) ;
else
F_60 ( V_2 -> V_52 , L_26 ) ;
if ( F_62 ( V_6 , 1 , NULL ) ) {
V_123 = - V_126 ;
goto V_151;
}
if ( V_9 -> V_66 . V_104 == V_137 ) {
V_9 -> V_66 . V_72 = V_6 -> V_86 ;
switch ( V_6 -> V_86 ) {
case 512 :
V_9 -> V_66 . V_76 = & V_152 ;
F_38 ( V_2 -> V_66 , V_153 , V_154 ) ;
break;
case 1024 :
V_9 -> V_66 . V_76 = & V_155 ;
F_38 ( V_2 -> V_66 , V_153 , V_156 ) ;
break;
case 2048 :
V_9 -> V_66 . V_76 = & V_155 ;
F_38 ( V_2 -> V_66 , V_153 , V_157 ) ;
break;
case 4096 :
V_9 -> V_66 . V_76 = & V_155 ;
F_38 ( V_2 -> V_66 , V_153 , V_158 ) ;
break;
default:
V_9 -> V_66 . V_104 = V_112 ;
V_9 -> V_66 . V_139 = NULL ;
V_9 -> V_66 . V_87 = NULL ;
V_9 -> V_66 . V_140 = NULL ;
V_9 -> V_66 . V_141 = NULL ;
V_9 -> V_66 . V_159 = 0 ;
V_9 -> V_66 . V_160 = 0 ;
V_9 -> V_66 . V_74 = 0 ;
break;
}
}
if ( F_63 ( V_6 ) ) {
V_123 = - V_126 ;
goto V_161;
}
V_6 -> V_162 = L_27 ;
V_122 . V_131 = V_117 -> V_52 . V_131 ;
V_123 = F_64 ( V_6 , NULL , & V_122 ,
V_2 -> V_3 . V_163 , V_2 -> V_3 . V_164 ) ;
if ( ! V_123 )
return V_123 ;
V_161:
V_151:
V_146:
F_7 ( V_2 ) ;
F_56 ( V_117 , NULL ) ;
if ( V_2 -> V_46 )
F_65 ( V_2 -> V_46 ) ;
if ( V_2 -> V_66 )
F_66 ( V_2 -> V_66 ) ;
V_138:
F_66 ( V_2 -> V_15 ) ;
V_130:
F_67 ( V_2 ) ;
return V_123 ;
}
static int T_11 F_68 ( struct V_116 * V_117 )
{
struct V_1 * V_2 = F_69 ( V_117 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_70 ( V_6 ) ;
F_7 ( V_2 ) ;
if ( V_2 -> V_66 )
F_66 ( V_2 -> V_66 ) ;
if ( V_2 -> V_46 )
F_65 ( V_2 -> V_46 ) ;
F_66 ( V_2 -> V_15 ) ;
F_67 ( V_2 ) ;
return 0 ;
}
static int T_9 F_71 ( void )
{
return F_72 ( & V_165 , F_50 ) ;
}
static void T_11 F_73 ( void )
{
F_74 ( & V_165 ) ;
}
