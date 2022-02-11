static int F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
int V_3 ;
struct V_4 * V_4 = & V_1 -> V_4 ;
struct V_5 * V_6 = & V_1 -> V_6 ;
struct V_7 * V_8 = & V_6 -> V_9 -> V_8 ;
V_3 = F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_11 ,
V_12 | V_13 | V_14 ,
V_2 ,
V_6 -> V_9 -> V_15 -> V_16 . V_17 ,
NULL , 0 , V_18 ) ;
if ( V_3 < 0 )
F_4 ( V_8 , L_1 ,
V_2 , V_3 ) ;
else
V_4 -> V_2 = V_2 ;
F_5 ( V_8 , L_2 , V_2 ) ;
return V_3 ;
}
static int F_6 ( struct V_4 * V_4 , T_1 V_19 , T_1 V_20 )
{
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_5 * V_6 = & V_1 -> V_6 ;
return F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_21 ,
V_12 | V_13 | V_14 ,
V_19 << 8 | V_20 ,
V_6 -> V_9 -> V_15 -> V_16 . V_17 ,
NULL , 0 , V_18 ) ;
}
static int F_8 ( struct V_22 * V_22 )
{
int V_3 ;
struct V_4 * V_4 = F_9 ( V_22 ) ;
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_7 * V_8 = & V_1 -> V_6 . V_9 -> V_8 ;
F_10 ( & V_4 -> V_23 ) ;
F_11 ( & V_1 -> V_6 ) ;
V_3 = F_12 ( & V_1 -> V_6 , V_24 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_3 , V_3 ) ;
goto V_25;
}
V_3 = F_13 ( & V_1 -> V_6 , V_26 , 0 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_4 , V_3 ) ;
goto V_25;
}
V_25:
F_14 ( & V_4 -> V_23 ) ;
return V_3 ;
}
static int F_15 ( struct V_22 * V_22 )
{
T_1 V_27 ;
int V_3 ;
struct V_4 * V_4 = F_9 ( V_22 ) ;
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
V_3 = - V_28 ;
F_10 ( & V_4 -> V_23 ) ;
V_27 = F_16 () ;
if ( V_27 == 0 )
goto V_29;
V_3 = F_1 ( V_1 , V_27 ) ;
if ( V_3 < 0 )
goto V_30;
V_22 -> V_31 = 1 ;
F_17 ( V_32 , & V_22 -> V_33 ) ;
V_22 -> V_34 = V_35 ;
F_18 ( & V_22 -> V_36 . V_37 -> V_8 ) ;
V_3 = 0 ;
V_38:
F_14 ( & V_4 -> V_23 ) ;
return V_3 ;
V_30:
F_19 ( V_4 -> V_2 ) ;
V_29:
goto V_38;
}
static void F_20 ( struct V_22 * V_22 )
{
struct V_4 * V_4 = F_9 ( V_22 ) ;
F_10 ( & V_4 -> V_23 ) ;
F_19 ( V_4 -> V_2 ) ;
F_14 ( & V_4 -> V_23 ) ;
}
static int F_21 ( struct V_22 * V_22 )
{
struct V_4 * V_4 = F_9 ( V_22 ) ;
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_5 * V_6 = & V_1 -> V_6 ;
return F_22 ( V_6 -> V_10 ) ;
}
static int F_23 ( struct V_22 * V_22 , struct V_39 * V_39 ,
T_2 V_40 )
{
struct V_4 * V_4 = F_9 ( V_22 ) ;
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
return F_24 ( & V_1 -> V_6 , V_39 -> V_41 , V_39 , V_40 ) ;
}
static int F_25 ( struct V_22 * V_22 , struct V_39 * V_39 ,
int V_42 )
{
struct V_4 * V_4 = F_9 ( V_22 ) ;
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
return F_26 ( & V_1 -> V_6 , V_39 , V_42 ) ;
}
static void F_27 ( struct V_22 * V_22 ,
struct V_43 * V_41 )
{
struct V_4 * V_4 = F_9 ( V_22 ) ;
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
F_28 ( & V_1 -> V_6 , V_41 ) ;
}
static int F_29 ( struct V_4 * V_4 )
{
int V_3 ;
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_7 * V_8 = & V_1 -> V_6 . V_9 -> V_8 ;
V_3 = F_12 ( & V_1 -> V_6 , V_44 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_5 , V_3 ) ;
goto V_45;
}
V_3 = F_13 ( & V_1 -> V_6 , V_44 , V_44 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_6 , V_3 ) ;
goto V_45;
}
V_3 = F_30 ( & V_1 -> V_6 , V_46 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_7 , V_3 ) ;
goto V_45;
}
if ( V_1 -> V_6 . V_47 &
V_48 ) {
struct V_49 * V_15 =
V_1 -> V_6 . V_9 -> V_15 ;
V_3 = F_2 ( V_1 -> V_6 . V_10 ,
F_3 ( V_1 -> V_6 . V_10 , 0 ) ,
V_50 ,
V_12 | V_51 |
V_14 ,
V_52 ,
V_15 -> V_16 . V_17 ,
NULL , 0 ,
V_18 ) ;
if ( V_3 == 0 )
V_3 = F_31 ( & V_1 -> V_6 ) ;
else
V_3 = 0 ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_8 , V_3 ) ;
goto V_53;
}
}
return V_3 ;
V_53:
F_11 ( & V_1 -> V_6 ) ;
V_45:
F_32 ( & V_1 -> V_6 , V_44 ) ;
return V_3 ;
}
static void F_33 ( struct V_4 * V_4 , int V_54 )
{
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_5 * V_6 = & V_1 -> V_6 ;
T_1 V_55 = V_6 -> V_9 -> V_15 -> V_16 . V_17 ;
int V_56 ;
V_56 = F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_57 ,
V_12 | V_13 | V_14 ,
V_54 * 1000 ,
V_55 ,
NULL , 0 , V_18 ) ;
if ( V_56 == 0 )
F_34 ( V_54 ) ;
F_11 ( & V_1 -> V_6 ) ;
F_35 ( & V_1 -> V_6 ) ;
}
static int F_36 ( struct V_4 * V_4 , T_3 V_58 ,
const struct V_59 * V_60 )
{
int V_3 ;
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_5 * V_6 = & V_1 -> V_6 ;
struct V_7 * V_8 = & V_6 -> V_9 -> V_8 ;
T_1 V_61 [ V_62 / 8 ] ;
V_3 = F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_63 ,
V_12 | V_13 | V_14 ,
V_58 ,
V_6 -> V_9 -> V_15 -> V_16 . V_17 ,
NULL , 0 , V_18 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_9 , V_3 ) ;
goto V_38;
}
F_37 ( V_61 , V_60 ) ;
V_3 = F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_64 ,
V_12 | V_13 | V_14 ,
0 , V_6 -> V_9 -> V_15 -> V_16 . V_17 ,
V_61 , 32 , V_18 ) ;
if ( V_3 < 0 )
F_4 ( V_8 , L_10 , V_3 ) ;
V_38:
return V_3 ;
}
static int F_38 ( struct V_4 * V_4 , T_1 V_19 ,
T_1 V_65 , T_1 V_66 ,
struct V_67 * V_68 )
{
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_5 * V_6 = & V_1 -> V_6 ;
T_1 V_55 = V_6 -> V_9 -> V_15 -> V_16 . V_17 ;
return F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_69 ,
V_12 | V_13 | V_14 ,
V_19 << 8 | V_65 ,
V_66 << 8 | V_55 ,
V_68 , V_68 -> V_70 , V_18 ) ;
}
static int F_39 ( struct V_4 * V_4 , T_1 V_66 )
{
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_5 * V_6 = & V_1 -> V_6 ;
T_1 V_55 = V_6 -> V_9 -> V_15 -> V_16 . V_17 ;
return F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_71 ,
V_12 | V_13 | V_14 ,
0 , V_66 << 8 | V_55 ,
NULL , 0 , V_18 ) ;
}
static int F_40 ( struct V_4 * V_4 ,
struct V_72 * V_72 )
{
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_5 * V_6 = & V_1 -> V_6 ;
T_1 V_55 = V_6 -> V_9 -> V_15 -> V_16 . V_17 ;
struct V_73 * F_5 ;
int V_56 ;
F_5 = F_41 ( sizeof( struct V_73 ) , V_46 ) ;
if ( ! F_5 )
return - V_74 ;
F_37 ( F_5 -> V_75 ,
& V_72 -> V_76 ) ;
F_5 -> V_77 = V_72 -> V_27 ;
if ( V_72 -> V_78 )
F_5 -> V_79 = V_72 -> V_78 -> V_79 ;
else
F_5 -> V_79 = F_42 ( V_80 ) ;
V_56 = F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_81 ,
V_12 | V_13 | V_14 ,
0 , V_72 -> V_82 << 8 | V_55 ,
F_5 , sizeof( struct V_73 ) ,
V_18 ) ;
F_43 ( F_5 ) ;
return V_56 ;
}
static int F_44 ( struct V_4 * V_4 , T_1 V_82 , T_4 V_83 ,
const void * V_84 , T_5 V_85 ,
T_1 V_86 )
{
int V_3 = - V_74 ;
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_5 * V_6 = & V_1 -> V_6 ;
T_1 V_55 = V_6 -> V_9 -> V_15 -> V_16 . V_17 ;
struct V_87 * V_88 ;
T_5 V_89 ;
V_89 = sizeof( * V_88 ) + V_85 ;
V_88 = F_41 ( V_89 , V_46 ) ;
if ( V_88 == NULL )
return - V_74 ;
V_88 -> V_70 = V_89 ;
V_88 -> V_90 = V_91 ;
V_88 -> V_92 [ 0 ] = ( V_83 >> 0 ) & 0xff ;
V_88 -> V_92 [ 1 ] = ( V_83 >> 8 ) & 0xff ;
V_88 -> V_92 [ 2 ] = ( V_83 >> 16 ) & 0xff ;
memcpy ( V_88 -> V_93 , V_84 , V_85 ) ;
V_3 = F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_94 ,
V_12 | V_13 | V_14 ,
V_91 << 8 | V_86 ,
V_82 << 8 | V_55 ,
V_88 , V_89 , V_18 ) ;
F_45 ( V_88 ) ;
return V_3 ;
}
static int F_46 ( struct V_4 * V_4 , T_1 V_82 , T_4 V_83 ,
const void * V_84 , T_5 V_85 )
{
int V_3 = - V_74 ;
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_5 * V_6 = & V_1 -> V_6 ;
T_1 V_55 = V_6 -> V_9 -> V_15 -> V_16 . V_17 ;
T_1 V_95 ;
if ( V_84 ) {
T_1 V_86 = F_47 ( 0 , V_96 ,
V_97 ) ;
V_3 = F_44 ( V_4 , V_82 , V_83 ,
V_84 , V_85 , V_86 ) ;
if ( V_3 < 0 )
goto V_98;
V_95 = V_4 -> V_99 -> V_100 ;
} else {
V_95 = 0 ;
}
V_3 = F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_101 ,
V_12 | V_13 | V_14 ,
V_95 , V_82 << 8 | V_55 ,
NULL , 0 , V_18 ) ;
if ( V_3 < 0 )
F_4 ( V_4 -> V_8 , L_11
L_12 , V_82 ,
F_48 ( V_4 -> V_99 -> V_102 ) ,
V_4 -> V_99 -> V_100 , V_3 ) ;
V_98:
return V_3 ;
}
static int F_49 ( struct V_4 * V_4 , T_4 V_83 ,
const void * V_84 , T_5 V_85 )
{
T_1 V_86 = F_47 ( 0 , V_103 ,
V_97 ) ;
return F_44 ( V_4 , 0 , V_83 , V_84 , V_85 , V_86 ) ;
}
static int F_50 ( struct V_5 * V_6 )
{
int V_3 ;
struct V_7 * V_8 = & V_6 -> V_9 -> V_8 ;
char * V_104 ;
struct V_105 * V_10 = V_6 -> V_10 ;
struct V_106 * V_107 ;
struct V_108 * V_109 ;
T_5 V_110 , V_111 ;
V_111 = ( V_10 -> V_112 - V_10 -> V_113 ) /
sizeof( V_10 -> V_113 [ 0 ] ) ;
V_104 = V_10 -> V_114 [ V_111 ] ;
V_110 = F_51 ( V_10 -> V_112 -> V_16 . V_115 ) ;
while ( V_110 >= sizeof( * V_107 ) ) {
V_107 = (struct V_106 * ) V_104 ;
F_52 ( V_8 , L_13
L_14 ,
V_107 -> V_90 , V_107 -> V_70 ,
( V_104 - V_10 -> V_114 [ V_111 ] ) ,
V_110 ) ;
if ( V_107 -> V_90 == V_116 )
goto V_117;
V_104 += V_107 -> V_70 ;
V_110 -= V_107 -> V_70 ;
}
F_4 ( V_8 , L_15 ) ;
return - V_118 ;
V_117:
V_3 = - V_119 ;
if ( V_107 -> V_70 > V_110 ) {
F_4 ( V_8 , L_16
L_17 ,
V_110 , V_107 -> V_70 ) ;
goto error;
}
if ( V_107 -> V_70 < sizeof( * V_6 -> V_109 ) ) {
F_4 ( V_8 , L_18 ) ;
goto error;
}
V_6 -> V_109 = V_109 = (struct V_108 * ) V_107 ;
if ( F_51 ( V_109 -> V_120 ) > 0x0100 )
F_53 ( V_8 , L_19 ,
F_51 ( V_109 -> V_120 ) & 0xff00 >> 8 ,
F_51 ( V_109 -> V_120 ) & 0x00ff ) ;
V_3 = 0 ;
error:
return V_3 ;
}
static int F_54 ( struct V_1 * V_1 )
{
int V_3 ;
struct V_4 * V_4 = & V_1 -> V_4 ;
struct V_105 * V_10 = V_1 -> V_6 . V_10 ;
struct V_7 * V_8 = & V_10 -> V_8 ;
struct V_121 * V_122 ;
struct V_123 * V_124 ;
void * V_104 , * V_125 ;
T_5 V_110 , V_126 , V_127 ;
T_1 V_128 ;
char V_129 [ 64 ] ;
V_128 = ( V_10 -> V_112 - V_10 -> V_113 ) /
sizeof( V_10 -> V_113 [ 0 ] ) ;
V_104 = V_10 -> V_114 [ V_128 ] ;
V_110 = F_51 ( V_10 -> V_112 -> V_16 . V_115 ) ;
V_125 = V_104 + V_110 ;
V_3 = F_55 ( V_10 -> V_114 [ V_128 ] ,
F_51 ( V_10 -> V_112 -> V_16 . V_115 ) ,
V_130 , ( void * * ) & V_122 ) ;
if ( V_3 == - 1 ) {
F_53 ( V_8 , L_20 ) ;
return 0 ;
}
V_126 = sizeof( * V_122 ) ;
if ( V_125 - ( void * ) V_122 < V_126 ) {
F_4 ( V_8 , L_21
L_22 ,
V_125 - ( void * ) V_122 , V_126 ) ;
return 0 ;
}
V_126 = F_51 ( V_122 -> V_115 ) ;
if ( V_125 - ( void * ) V_122 < V_126 ) {
F_4 ( V_8 , L_21
L_23 ,
V_125 - ( void * ) V_122 , V_126 ) ;
return 0 ;
}
V_104 = ( void * ) V_122 + sizeof( * V_122 ) ;
V_125 = ( void * ) V_122 + F_51 ( V_122 -> V_115 ) ;
V_128 = 0 ;
V_127 = 0 ;
while ( V_104 < V_125 ) {
V_124 = V_104 ;
if ( V_125 - V_104 < sizeof( * V_124 ) ) {
F_4 ( V_8 , L_24
L_25 ,
V_125 - V_104 , sizeof( * V_124 ) ) ;
break;
}
if ( V_124 -> V_70 < sizeof( * V_124 ) ) {
F_4 ( V_8 , L_26
L_27
L_28 ,
( T_5 ) V_124 -> V_70 , sizeof( * V_124 ) ) ;
break;
}
V_104 += V_124 -> V_70 ;
V_127 += snprintf ( V_129 + V_127 , sizeof( V_129 ) - V_127 ,
L_29 ,
F_48 ( V_124 -> V_102 ) ,
V_124 -> V_100 ) ;
V_4 -> V_99 = V_124 ;
}
F_5 ( V_8 , L_30 , V_129 ) ;
if ( V_4 -> V_99 == NULL ) {
F_4 ( V_8 , L_31 ) ;
return 0 ;
}
return 0 ;
}
static void F_56 ( struct V_1 * V_1 )
{
}
static int F_57 ( struct V_1 * V_1 , struct V_131 * V_132 ,
T_6 V_47 )
{
int V_3 ;
struct V_7 * V_8 = & V_132 -> V_8 ;
struct V_4 * V_4 = & V_1 -> V_4 ;
struct V_5 * V_6 = & V_1 -> V_6 ;
struct V_105 * V_10 = F_58 ( V_132 ) ;
V_6 -> V_10 = F_59 ( V_10 ) ;
V_6 -> V_9 = F_60 ( V_132 ) ;
V_4 -> V_8 = V_8 ;
V_4 -> V_133 = NULL ;
V_3 = F_50 ( V_6 ) ;
if ( V_3 < 0 )
goto V_134;
if ( V_6 -> V_109 -> V_135 > V_136 ) {
F_4 ( V_8 , L_32
L_33 , V_6 -> V_109 -> V_135 ) ;
V_4 -> V_137 = V_136 ;
} else {
V_4 -> V_137 = V_6 -> V_109 -> V_135 ;
}
V_4 -> V_138 = V_6 -> V_109 -> V_139 ;
V_4 -> V_140 = F_29 ;
V_4 -> V_141 = F_33 ;
V_4 -> V_142 = F_38 ;
V_4 -> V_143 = F_39 ;
V_4 -> V_144 = F_40 ;
V_4 -> V_145 = F_36 ;
V_4 -> V_146 = F_6 ;
V_4 -> V_147 = F_46 ;
V_4 -> V_148 = F_49 ;
V_3 = F_54 ( V_1 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_34 , V_3 ) ;
goto V_149;
}
V_6 -> V_150 = V_4 ;
V_3 = F_61 ( & V_1 -> V_4 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_35 , V_3 ) ;
goto V_151;
}
V_3 = F_62 ( & V_1 -> V_6 , V_132 , V_47 ) ;
if ( V_3 < 0 )
goto V_152;
return 0 ;
V_152:
F_63 ( & V_1 -> V_4 ) ;
V_151:
V_149:
V_134:
F_64 ( V_132 ) ;
F_65 ( V_10 ) ;
return V_3 ;
}
static void F_66 ( struct V_1 * V_1 )
{
struct V_4 * V_4 = & V_1 -> V_4 ;
F_10 ( & V_4 -> V_23 ) ;
F_67 ( & V_1 -> V_6 ) ;
F_63 ( & V_1 -> V_4 ) ;
F_56 ( V_1 ) ;
V_1 -> V_4 . V_8 = NULL ;
F_68 ( V_4 -> V_133 ) ;
F_64 ( V_1 -> V_6 . V_9 ) ;
F_65 ( V_1 -> V_6 . V_10 ) ;
F_14 ( & V_4 -> V_23 ) ;
}
static void F_69 ( struct V_1 * V_1 )
{
F_70 ( & V_1 -> V_6 ) ;
}
static int F_71 ( struct V_131 * V_9 ,
const struct V_153 * V_154 )
{
int V_3 ;
struct V_22 * V_22 ;
struct V_4 * V_4 ;
struct V_1 * V_1 ;
struct V_7 * V_8 = & V_9 -> V_8 ;
V_3 = - V_74 ;
V_22 = F_72 ( & V_155 , & V_9 -> V_8 , L_36 ) ;
if ( V_22 == NULL ) {
F_4 ( V_8 , L_37 ) ;
goto V_156;
}
V_22 -> V_157 = 1 ;
V_22 -> V_36 . V_158 = ~ 0 ;
V_4 = F_9 ( V_22 ) ;
V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
F_69 ( V_1 ) ;
V_3 = F_57 ( V_1 , V_9 , V_154 -> V_159 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_38 , V_3 ) ;
goto V_160;
}
V_3 = F_73 ( V_22 , 0 , 0 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_39 , V_3 ) ;
goto V_161;
}
F_74 ( V_22 -> V_36 . V_162 ) ;
V_3 = F_75 ( & V_1 -> V_4 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_40 , V_3 ) ;
goto V_163;
}
return 0 ;
V_163:
F_76 ( V_22 ) ;
V_161:
F_66 ( V_1 ) ;
V_160:
F_77 ( V_22 ) ;
V_156:
return V_3 ;
}
static void F_78 ( struct V_131 * V_9 )
{
struct V_22 * V_22 ;
struct V_4 * V_4 ;
struct V_1 * V_1 ;
V_22 = F_79 ( V_9 ) ;
V_4 = F_9 ( V_22 ) ;
V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
F_80 ( & V_1 -> V_4 ) ;
F_76 ( V_22 ) ;
F_66 ( V_1 ) ;
F_77 ( V_22 ) ;
}
