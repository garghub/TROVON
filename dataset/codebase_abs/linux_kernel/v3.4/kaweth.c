static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
T_1 V_4 ,
T_1 V_5 ,
T_2 V_6 ,
T_2 V_7 ,
void * V_8 ,
T_2 V_9 ,
int V_10 )
{
struct V_11 * V_12 ;
int V_13 ;
F_2 ( L_1 ) ;
if( F_3 () ) {
F_2 ( L_2 ) ;
return - V_14 ;
}
V_12 = F_4 ( sizeof( struct V_11 ) , V_15 ) ;
if ( ! V_12 ) {
F_2 ( L_3 ) ;
return - V_16 ;
}
V_12 -> V_17 = V_5 ;
V_12 -> V_18 = V_4 ;
V_12 -> V_19 = F_5 ( V_6 ) ;
V_12 -> V_20 = F_5 ( V_7 ) ;
V_12 -> V_21 = F_5 ( V_9 ) ;
V_13 = F_6 ( V_2 -> V_22 ,
V_3 ,
V_12 ,
V_8 ,
V_9 ,
V_10 ) ;
F_7 ( V_12 ) ;
return V_13 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_13 ;
F_2 ( L_4 ) ;
V_13 = F_1 ( V_2 ,
F_9 ( V_2 -> V_22 , 0 ) ,
V_23 ,
V_24 | V_25 | V_26 ,
0 ,
0 ,
( void * ) & V_2 -> V_27 ,
sizeof( V_2 -> V_27 ) ,
V_28 ) ;
return V_13 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_29 )
{
int V_13 ;
F_2 ( L_5 , ( unsigned ) V_29 ) ;
V_13 = F_1 ( V_2 ,
F_11 ( V_2 -> V_22 , 0 ) ,
V_30 ,
V_24 | V_31 | V_26 ,
V_29 ,
0 ,
( void * ) & V_2 -> V_32 ,
0 ,
V_28 ) ;
return V_13 ;
}
static int F_12 ( struct V_1 * V_2 , T_2 V_33 )
{
int V_13 ;
F_2 ( L_6 , ( unsigned ) V_33 ) ;
V_13 = F_1 ( V_2 ,
F_11 ( V_2 -> V_22 , 0 ) ,
V_34 ,
V_24 | V_31 | V_26 ,
V_33 ,
0 ,
( void * ) & V_2 -> V_32 ,
0 ,
V_28 ) ;
return V_13 ;
}
static int F_13 ( struct V_1 * V_2 ,
T_2 V_35 )
{
int V_13 ;
F_2 ( L_7 , ( unsigned ) V_35 ) ;
V_13 = F_1 ( V_2 ,
F_11 ( V_2 -> V_22 , 0 ) ,
V_36 ,
V_24 | V_31 | V_26 ,
V_35 ,
0 ,
( void * ) & V_2 -> V_32 ,
0 ,
V_28 ) ;
return V_13 ;
}
static int F_14 ( struct V_1 * V_2 ,
const char * V_37 ,
T_1 V_38 ,
T_1 type )
{
const struct V_39 * V_40 ;
int V_41 ;
int V_42 ;
V_42 = F_15 ( & V_40 , V_37 , & V_2 -> V_22 -> V_22 ) ;
if ( V_42 ) {
F_16 ( L_8 ) ;
return V_42 ;
}
if ( V_40 -> V_9 > V_43 ) {
F_16 ( L_9 , V_40 -> V_9 ) ;
F_17 ( V_40 ) ;
return - V_44 ;
}
V_41 = V_40 -> V_9 ;
memcpy ( V_2 -> V_45 , V_40 -> V_8 , V_40 -> V_9 ) ;
F_17 ( V_40 ) ;
V_2 -> V_45 [ 2 ] = ( V_41 & 0xFF ) - 7 ;
V_2 -> V_45 [ 3 ] = V_41 >> 8 ;
V_2 -> V_45 [ 4 ] = type ;
V_2 -> V_45 [ 5 ] = V_38 ;
F_2 ( L_10 , V_2 -> V_45 [ 3 ] ,
V_2 -> V_45 [ 2 ] ) ;
F_2 ( L_11 ,
V_40 -> V_8 , V_2 ) ;
F_2 ( L_12 , V_41 ) ;
return F_1 ( V_2 ,
F_11 ( V_2 -> V_22 , 0 ) ,
V_46 ,
V_24 | V_31 | V_26 ,
0 ,
0 ,
( void * ) V_2 -> V_45 ,
V_41 ,
V_28 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
T_1 V_38 )
{
V_2 -> V_45 [ 0 ] = 0xB6 ;
V_2 -> V_45 [ 1 ] = 0xC3 ;
V_2 -> V_45 [ 2 ] = 0x01 ;
V_2 -> V_45 [ 3 ] = 0x00 ;
V_2 -> V_45 [ 4 ] = 0x06 ;
V_2 -> V_45 [ 5 ] = V_38 ;
V_2 -> V_45 [ 6 ] = 0x00 ;
V_2 -> V_45 [ 7 ] = 0x00 ;
F_2 ( L_13 ) ;
return F_1 ( V_2 ,
F_11 ( V_2 -> V_22 , 0 ) ,
V_46 ,
V_24 | V_31 | V_26 ,
0 ,
0 ,
( void * ) V_2 -> V_45 ,
8 ,
V_28 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_47 ;
F_2 ( L_14 , V_2 ) ;
V_47 = F_20 ( V_2 -> V_22 ) ;
F_21 ( 10 ) ;
F_2 ( L_15 , V_47 ) ;
return V_47 ;
}
static void F_22 ( struct V_1 * V_2 , T_3 V_48 )
{
int V_49 ;
V_49 = F_23 ( V_2 -> V_50 , V_48 ) ;
if ( F_24 ( V_49 == - V_16 ) ) {
V_2 -> V_51 = 1 ;
F_25 ( & V_2 -> V_52 , V_53 / 4 ) ;
} else {
V_2 -> V_51 = 0 ;
}
if ( V_49 )
F_16 ( L_16 ,
V_2 -> V_22 -> V_54 -> V_55 ,
V_2 -> V_22 -> V_56 , V_49 ) ;
}
static void F_26 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = V_58 -> V_59 ;
int V_60 ;
int V_49 = V_58 -> V_49 ;
switch ( V_49 ) {
case 0 :
break;
case - V_61 :
case - V_62 :
case - V_63 :
return;
default:
goto V_64;
}
if ( V_2 -> V_65 != ( V_60 = ( V_2 -> V_66 [ V_67 ] | V_68 ) >> V_69 ) ) {
if ( V_60 )
F_27 ( V_2 -> V_70 ) ;
else
F_28 ( V_2 -> V_70 ) ;
V_2 -> V_65 = V_60 ;
}
V_64:
F_22 ( V_2 , V_15 ) ;
}
static void F_29 ( struct V_71 * V_72 )
{
struct V_1 * V_2 =
F_30 ( V_72 , struct V_1 , V_52 . V_72 ) ;
if ( F_31 ( V_2 -> V_49 ) )
return;
if ( V_2 -> V_73 )
F_32 ( V_2 , V_74 ) ;
if ( V_2 -> V_51 )
F_22 ( V_2 , V_74 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
T_3 V_75 )
{
int V_47 ;
F_33 ( V_2 -> V_76 ,
V_2 -> V_22 ,
F_34 ( V_2 -> V_22 , 1 ) ,
V_2 -> V_77 ,
V_78 ,
V_79 ,
V_2 ) ;
V_2 -> V_76 -> V_80 |= V_81 ;
V_2 -> V_76 -> V_82 = V_2 -> V_83 ;
if( ( V_47 = F_23 ( V_2 -> V_76 , V_75 ) ) ) {
if ( V_47 == - V_16 ) {
V_2 -> V_73 = 1 ;
F_25 ( & V_2 -> V_52 , V_53 / 4 ) ;
}
F_16 ( L_17 , V_47 ) ;
} else {
V_2 -> V_73 = 0 ;
}
return V_47 ;
}
static void V_79 ( struct V_57 * V_57 )
{
struct V_1 * V_2 = V_57 -> V_59 ;
struct V_84 * V_70 = V_2 -> V_70 ;
int V_49 = V_57 -> V_49 ;
int V_85 = V_57 -> V_86 ;
int V_87 = V_57 -> V_88 ;
T_2 V_89 = F_35 ( ( V_90 * ) V_2 -> V_77 ) ;
struct V_91 * V_92 ;
if ( F_24 ( V_49 == - V_93 ) ) {
V_2 -> V_94 . V_95 ++ ;
V_2 -> V_96 = 1 ;
F_36 ( & V_2 -> V_97 ) ;
F_2 ( L_18 ) ;
return;
}
if ( F_24 ( V_49 == - V_61 || V_49 == - V_63 ) ) {
V_2 -> V_96 = 1 ;
F_36 ( & V_2 -> V_97 ) ;
F_2 ( L_19 ) ;
return;
}
if ( F_24 ( V_49 == - V_98 || V_49 == - V_99 ||
V_49 == - V_100 ) ) {
V_2 -> V_94 . V_95 ++ ;
F_2 ( L_20 ) ;
return;
}
if ( F_24 ( V_49 == - V_101 ) ) {
V_2 -> V_94 . V_95 ++ ;
F_2 ( L_21 ) ;
}
F_37 ( & V_2 -> V_102 ) ;
if ( F_31 ( V_2 -> V_49 ) ) {
F_38 ( & V_2 -> V_102 ) ;
return;
}
F_38 ( & V_2 -> V_102 ) ;
if( V_49 && V_49 != - V_103 && V_85 != 1 ) {
F_16 ( L_22 ,
V_70 -> V_104 ,
V_49 ,
V_85 ,
( int ) V_89 ) ;
F_32 ( V_2 , V_15 ) ;
return;
}
if( V_2 -> V_70 && ( V_85 > 2 ) ) {
if( V_89 > ( V_85 - 2 ) ) {
F_16 ( L_23 , V_89 , V_85 ) ;
F_16 ( L_24 , V_89 & 2047 ) ;
F_16 ( L_25 , V_87 ) ;
F_32 ( V_2 , V_15 ) ;
return;
}
if( ! ( V_92 = F_39 ( V_89 + 2 ) ) ) {
F_32 ( V_2 , V_15 ) ;
return;
}
F_40 ( V_92 , 2 ) ;
F_41 ( V_92 , V_2 -> V_77 + 2 , V_89 ) ;
F_42 ( V_92 , V_89 ) ;
V_92 -> V_105 = F_43 ( V_92 , V_70 ) ;
F_44 ( V_92 ) ;
V_2 -> V_94 . V_106 ++ ;
V_2 -> V_94 . V_107 += V_89 ;
}
F_32 ( V_2 , V_15 ) ;
}
static int F_45 ( struct V_84 * V_70 )
{
struct V_1 * V_2 = F_46 ( V_70 ) ;
int V_108 ;
F_2 ( L_26 ) ;
V_108 = F_47 ( V_2 -> V_109 ) ;
if ( V_108 ) {
F_16 ( L_27 ) ;
return - V_110 ;
}
V_108 = F_32 ( V_2 , V_111 ) ;
if ( V_108 )
goto V_112;
F_48 (
V_2 -> V_50 ,
V_2 -> V_22 ,
F_49 ( V_2 -> V_22 , 3 ) ,
V_2 -> V_66 ,
V_113 ,
F_26 ,
V_2 ,
250 ) ;
V_2 -> V_50 -> V_82 = V_2 -> V_114 ;
V_2 -> V_50 -> V_80 |= V_81 ;
V_108 = F_23 ( V_2 -> V_50 , V_111 ) ;
if ( V_108 ) {
F_50 ( V_2 -> V_76 ) ;
goto V_112;
}
V_2 -> V_115 = 1 ;
F_51 ( V_70 ) ;
F_52 ( V_2 ) ;
return 0 ;
V_112:
F_53 ( V_2 -> V_109 ) ;
return - V_110 ;
}
static void F_54 ( struct V_1 * V_2 )
{
F_50 ( V_2 -> V_50 ) ;
F_50 ( V_2 -> V_76 ) ;
F_50 ( V_2 -> V_116 ) ;
F_55 ( & V_2 -> V_52 ) ;
F_50 ( V_2 -> V_50 ) ;
F_50 ( V_2 -> V_76 ) ;
}
static int F_56 ( struct V_84 * V_70 )
{
struct V_1 * V_2 = F_46 ( V_70 ) ;
F_57 ( V_70 ) ;
V_2 -> V_115 = 0 ;
V_2 -> V_49 |= V_117 ;
F_54 ( V_2 ) ;
V_2 -> V_49 &= ~ V_117 ;
F_53 ( V_2 -> V_109 ) ;
return 0 ;
}
static T_4 F_58 ( struct V_84 * V_22 )
{
struct V_1 * V_2 = F_46 ( V_22 ) ;
return V_2 -> V_65 ;
}
static void F_59 ( struct V_57 * V_57 )
{
struct V_1 * V_2 = V_57 -> V_59 ;
struct V_91 * V_92 = V_2 -> V_118 ;
int V_49 = V_57 -> V_49 ;
if ( F_24 ( V_49 != 0 ) )
if ( V_49 != - V_62 )
F_2 ( L_28 , V_2 -> V_70 -> V_104 , V_49 ) ;
F_60 ( V_2 -> V_70 ) ;
F_61 ( V_92 ) ;
}
static T_5 F_62 ( struct V_91 * V_92 ,
struct V_84 * V_70 )
{
struct V_1 * V_2 = F_46 ( V_70 ) ;
V_90 * V_119 ;
int V_108 ;
F_63 ( & V_2 -> V_102 ) ;
F_52 ( V_2 ) ;
F_57 ( V_70 ) ;
if ( F_31 ( V_2 -> V_49 ) ) {
goto V_120;
}
if ( F_64 ( V_92 ) || F_65 ( V_92 ) < 2 ) {
struct V_91 * V_121 ;
V_121 = F_66 ( V_92 , 2 , 0 , V_15 ) ;
F_61 ( V_92 ) ;
V_92 = V_121 ;
if ( ! V_121 ) {
V_2 -> V_94 . V_122 ++ ;
F_51 ( V_70 ) ;
F_67 ( & V_2 -> V_102 ) ;
return V_123 ;
}
}
V_119 = ( V_90 * ) F_68 ( V_92 , 2 ) ;
* V_119 = F_5 ( V_92 -> V_124 - 2 ) ;
V_2 -> V_118 = V_92 ;
F_33 ( V_2 -> V_116 ,
V_2 -> V_22 ,
F_69 ( V_2 -> V_22 , 2 ) ,
V_119 ,
V_92 -> V_124 ,
F_59 ,
V_2 ) ;
V_2 -> V_96 = 0 ;
if( ( V_108 = F_23 ( V_2 -> V_116 , V_15 ) ) )
{
F_70 ( & V_70 -> V_22 , L_29 , V_108 ) ;
V_120:
V_2 -> V_94 . V_122 ++ ;
F_51 ( V_70 ) ;
F_61 ( V_92 ) ;
}
else
{
V_2 -> V_94 . V_125 ++ ;
V_2 -> V_94 . V_126 += V_92 -> V_124 ;
}
F_67 ( & V_2 -> V_102 ) ;
return V_123 ;
}
static void F_71 ( struct V_84 * V_70 )
{
struct V_1 * V_2 = F_46 ( V_70 ) ;
T_2 V_127 = V_128 |
V_129 |
V_130 ;
F_2 ( L_30 , V_127 ) ;
F_57 ( V_70 ) ;
if ( V_70 -> V_131 & V_132 ) {
V_127 |= V_133 ;
}
else if ( ! F_72 ( V_70 ) || ( V_70 -> V_131 & V_134 ) ) {
V_127 |= V_135 ;
}
V_2 -> V_127 = V_127 ;
F_60 ( V_70 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
int V_47 ;
T_2 V_127 = V_2 -> V_127 ;
V_2 -> V_127 = 0 ;
if ( V_127 == 0 )
return;
if ( F_3 () )
return;
V_47 = F_1 ( V_2 ,
F_11 ( V_2 -> V_22 , 0 ) ,
V_36 ,
V_24 | V_31 | V_26 ,
V_127 ,
0 ,
( void * ) & V_2 -> V_32 ,
0 ,
V_28 ) ;
if( V_47 < 0 ) {
F_16 ( L_31 , V_47 ) ;
}
else {
F_2 ( L_32 , V_127 ) ;
}
}
static struct V_136 * F_73 ( struct V_84 * V_22 )
{
struct V_1 * V_2 = F_46 ( V_22 ) ;
return & V_2 -> V_94 ;
}
static void F_74 ( struct V_84 * V_70 )
{
struct V_1 * V_2 = F_46 ( V_70 ) ;
F_70 ( & V_70 -> V_22 , L_33 , V_70 -> V_104 ) ;
V_2 -> V_94 . V_122 ++ ;
V_70 -> V_137 = V_138 ;
F_75 ( V_2 -> V_116 ) ;
}
static int F_76 ( struct V_139 * V_109 , T_6 V_140 )
{
struct V_1 * V_2 = F_77 ( V_109 ) ;
unsigned long V_131 ;
F_2 ( L_34 ) ;
F_78 ( & V_2 -> V_102 , V_131 ) ;
V_2 -> V_49 |= V_141 ;
F_79 ( & V_2 -> V_102 , V_131 ) ;
F_54 ( V_2 ) ;
return 0 ;
}
static int F_80 ( struct V_139 * V_109 )
{
struct V_1 * V_2 = F_77 ( V_109 ) ;
unsigned long V_131 ;
F_2 ( L_35 ) ;
F_78 ( & V_2 -> V_102 , V_131 ) ;
V_2 -> V_49 &= ~ V_141 ;
F_79 ( & V_2 -> V_102 , V_131 ) ;
if ( ! V_2 -> V_115 )
return 0 ;
F_32 ( V_2 , V_74 ) ;
F_22 ( V_2 , V_74 ) ;
return 0 ;
}
static int F_81 (
struct V_139 * V_109 ,
const struct V_142 * V_143
)
{
struct V_144 * V_22 = F_82 ( V_109 ) ;
struct V_1 * V_2 ;
struct V_84 * V_145 ;
const T_7 V_146 = { 0xFF , 0xFF , 0xFF , 0xFF , 0xFF , 0xFF } ;
int V_47 = 0 ;
F_2 ( L_36 ,
V_22 -> V_147 ,
F_83 ( V_22 -> V_148 . V_149 ) ,
F_83 ( V_22 -> V_148 . V_150 ) ,
F_83 ( V_22 -> V_148 . V_151 ) ) ;
F_2 ( L_37 , V_22 ) ;
F_2 ( L_38 ,
( int ) V_22 -> V_148 . V_152 ,
( int ) V_22 -> V_148 . V_153 ) ;
V_145 = F_84 ( sizeof( * V_2 ) ) ;
if ( ! V_145 )
return - V_16 ;
V_2 = F_46 ( V_145 ) ;
V_2 -> V_22 = V_22 ;
V_2 -> V_70 = V_145 ;
F_85 ( & V_2 -> V_102 ) ;
F_86 ( & V_2 -> V_97 ) ;
F_2 ( L_39 ) ;
F_19 ( V_2 ) ;
if ( F_83 ( V_22 -> V_148 . V_151 ) >> 8 ) {
F_87 ( & V_109 -> V_22 , L_40 ) ;
} else {
F_87 ( & V_109 -> V_22 , L_41 ) ;
V_2 -> V_45 = ( T_1 * ) F_88 ( V_111 ) ;
if ( ( V_47 = F_14 ( V_2 ,
L_42 ,
100 ,
2 ) ) < 0 ) {
F_16 ( L_43 , V_47 ) ;
goto V_154;
}
if ( ( V_47 = F_14 ( V_2 ,
L_44 ,
100 ,
3 ) ) < 0 ) {
F_16 ( L_45 , V_47 ) ;
goto V_154;
}
if ( ( V_47 = F_14 ( V_2 ,
L_46 ,
126 ,
2 ) ) < 0 ) {
F_16 ( L_47 , V_47 ) ;
goto V_154;
}
if ( ( V_47 = F_14 ( V_2 ,
L_48 ,
126 ,
3 ) ) < 0 ) {
F_16 ( L_49 , V_47 ) ;
goto V_154;
}
if ( ( V_47 = F_18 ( V_2 , 126 ) ) < 0 ) {
F_16 ( L_50 , V_47 ) ;
goto V_154;
}
F_87 ( & V_109 -> V_22 , L_51 ) ;
V_154:
F_89 ( ( unsigned long ) V_2 -> V_45 ) ;
F_90 ( V_145 ) ;
return - V_110 ;
}
V_47 = F_8 ( V_2 ) ;
if( V_47 < 0 ) {
F_16 ( L_52 , V_47 ) ;
goto V_155;
}
F_87 ( & V_109 -> V_22 , L_53 , V_2 -> V_27 . V_156 ) ;
F_87 ( & V_109 -> V_22 , L_54 , V_2 -> V_27 . V_157 & ( ( 1 << 15 ) - 1 ) ) ;
F_87 ( & V_109 -> V_22 , L_55 , F_83 ( V_2 -> V_27 . V_158 ) ) ;
F_87 ( & V_109 -> V_22 , L_56 , V_2 -> V_27 . V_159 ) ;
if( ! memcmp ( & V_2 -> V_27 . V_159 ,
& V_146 ,
sizeof( V_146 ) ) ) {
F_16 ( L_57 ) ;
goto V_155;
}
if( F_10 ( V_2 , V_78 ) < 0 ) {
F_2 ( L_58 ) ;
goto V_155;
}
if( F_12 ( V_2 , V_160 ) < 0 ) {
F_16 ( L_59 ) ;
goto V_155;
}
V_47 = F_13 ( V_2 ,
V_128 |
V_129 |
V_130 ) ;
if( V_47 < 0 ) {
F_16 ( L_60 ) ;
goto V_155;
}
F_2 ( L_61 ) ;
V_2 -> V_109 = V_109 ;
V_2 -> V_116 = F_91 ( 0 , V_111 ) ;
if ( ! V_2 -> V_116 )
goto V_155;
V_2 -> V_76 = F_91 ( 0 , V_111 ) ;
if ( ! V_2 -> V_76 )
goto V_161;
V_2 -> V_50 = F_91 ( 0 , V_111 ) ;
if ( ! V_2 -> V_50 )
goto V_162;
V_2 -> V_66 = F_92 ( V_2 -> V_22 ,
V_113 ,
V_111 ,
& V_2 -> V_114 ) ;
if ( ! V_2 -> V_66 )
goto V_163;
V_2 -> V_77 = F_92 ( V_2 -> V_22 ,
V_78 ,
V_111 ,
& V_2 -> V_83 ) ;
if ( ! V_2 -> V_77 )
goto V_164;
memcpy ( V_145 -> V_165 , & V_146 , sizeof( V_146 ) ) ;
memcpy ( V_145 -> V_166 , & V_2 -> V_27 . V_159 ,
sizeof( V_2 -> V_27 . V_159 ) ) ;
V_145 -> V_167 = & V_168 ;
V_145 -> V_169 = V_170 ;
V_145 -> V_171 = F_83 ( V_2 -> V_27 . V_158 ) ;
F_93 ( V_145 , & V_172 ) ;
F_94 ( & V_2 -> V_52 , F_29 ) ;
F_95 ( V_109 , V_2 ) ;
#if 0
if (dma_supported (&intf->dev, 0xffffffffffffffffULL))
kaweth->net->features |= NETIF_F_HIGHDMA;
#endif
F_96 ( V_145 , & V_109 -> V_22 ) ;
if ( F_97 ( V_145 ) != 0 ) {
F_16 ( L_62 ) ;
goto V_173;
}
F_87 ( & V_109 -> V_22 , L_63 ,
V_2 -> V_70 -> V_104 ) ;
F_2 ( L_64 ) ;
return 0 ;
V_173:
F_95 ( V_109 , NULL ) ;
F_98 ( V_2 -> V_22 , V_78 , ( void * ) V_2 -> V_77 , V_2 -> V_83 ) ;
V_164:
F_98 ( V_2 -> V_22 , V_113 , ( void * ) V_2 -> V_66 , V_2 -> V_114 ) ;
V_163:
F_99 ( V_2 -> V_50 ) ;
V_162:
F_99 ( V_2 -> V_76 ) ;
V_161:
F_99 ( V_2 -> V_116 ) ;
V_155:
F_90 ( V_145 ) ;
return - V_110 ;
}
static void F_100 ( struct V_139 * V_109 )
{
struct V_1 * V_2 = F_77 ( V_109 ) ;
struct V_84 * V_145 ;
F_87 ( & V_109 -> V_22 , L_65 ) ;
F_95 ( V_109 , NULL ) ;
if ( ! V_2 ) {
F_70 ( & V_109 -> V_22 , L_66 ) ;
return;
}
V_145 = V_2 -> V_70 ;
F_2 ( L_67 ) ;
F_101 ( V_145 ) ;
F_99 ( V_2 -> V_76 ) ;
F_99 ( V_2 -> V_116 ) ;
F_99 ( V_2 -> V_50 ) ;
F_98 ( V_2 -> V_22 , V_78 , ( void * ) V_2 -> V_77 , V_2 -> V_83 ) ;
F_98 ( V_2 -> V_22 , V_113 , ( void * ) V_2 -> V_66 , V_2 -> V_114 ) ;
F_90 ( V_145 ) ;
}
static void F_102 ( struct V_57 * V_57 )
{
struct V_174 * V_175 = (struct V_174 * ) V_57 -> V_59 ;
V_175 -> V_176 = 1 ;
F_36 ( & V_175 -> V_177 ) ;
}
static int F_103 ( struct V_57 * V_57 , int V_10 , int * V_86 )
{
struct V_174 V_175 ;
int V_49 ;
F_86 ( & V_175 . V_177 ) ;
V_175 . V_176 = 0 ;
V_57 -> V_59 = & V_175 ;
V_49 = F_23 ( V_57 , V_74 ) ;
if ( V_49 ) {
F_99 ( V_57 ) ;
return V_49 ;
}
if ( ! F_104 ( V_175 . V_177 , V_175 . V_176 , V_10 ) ) {
F_70 ( & V_57 -> V_22 -> V_22 , L_68 ) ;
F_50 ( V_57 ) ;
V_49 = - V_178 ;
}
else {
V_49 = V_57 -> V_49 ;
}
if ( V_86 ) {
* V_86 = V_57 -> V_86 ;
}
F_99 ( V_57 ) ;
return V_49 ;
}
static int F_6 ( struct V_144 * V_179 ,
unsigned int V_3 ,
struct V_11 * V_180 , void * V_8 ,
int V_124 , int V_10 )
{
struct V_57 * V_57 ;
int V_181 ;
int V_182 = 0 ;
V_57 = F_91 ( 0 , V_74 ) ;
if ( ! V_57 )
return - V_16 ;
F_105 ( V_57 , V_179 , V_3 , ( unsigned char * ) V_180 , V_8 ,
V_124 , F_102 , NULL ) ;
V_181 = F_103 ( V_57 , V_10 , & V_182 ) ;
if ( V_181 < 0 ) {
return V_181 ;
}
else {
return V_182 ;
}
}
