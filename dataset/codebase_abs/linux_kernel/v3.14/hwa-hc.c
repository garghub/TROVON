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
return V_3 ;
V_45:
F_31 ( & V_1 -> V_6 , V_44 ) ;
return V_3 ;
}
static void F_32 ( struct V_4 * V_4 , int V_47 )
{
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_5 * V_6 = & V_1 -> V_6 ;
T_1 V_48 = V_6 -> V_9 -> V_15 -> V_16 . V_17 ;
int V_49 ;
V_49 = F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_50 ,
V_12 | V_13 | V_14 ,
V_47 * 1000 ,
V_48 ,
NULL , 0 , V_18 ) ;
if ( V_49 == 0 )
F_33 ( V_47 ) ;
F_11 ( & V_1 -> V_6 ) ;
F_34 ( & V_1 -> V_6 ) ;
}
static int F_35 ( struct V_4 * V_4 , T_3 V_51 ,
const struct V_52 * V_53 )
{
int V_3 ;
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_5 * V_6 = & V_1 -> V_6 ;
struct V_7 * V_8 = & V_6 -> V_9 -> V_8 ;
T_1 V_54 [ V_55 / 8 ] ;
V_3 = F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_56 ,
V_12 | V_13 | V_14 ,
V_51 ,
V_6 -> V_9 -> V_15 -> V_16 . V_17 ,
NULL , 0 , V_18 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_8 , V_3 ) ;
goto V_38;
}
F_36 ( V_54 , V_53 ) ;
V_3 = F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_57 ,
V_12 | V_13 | V_14 ,
0 , V_6 -> V_9 -> V_15 -> V_16 . V_17 ,
V_54 , 32 , V_18 ) ;
if ( V_3 < 0 )
F_4 ( V_8 , L_9 , V_3 ) ;
V_38:
return V_3 ;
}
static int F_37 ( struct V_4 * V_4 , T_1 V_19 ,
T_1 V_58 , T_1 V_59 ,
struct V_60 * V_61 )
{
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_5 * V_6 = & V_1 -> V_6 ;
T_1 V_48 = V_6 -> V_9 -> V_15 -> V_16 . V_17 ;
return F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_62 ,
V_12 | V_13 | V_14 ,
V_19 << 8 | V_58 ,
V_59 << 8 | V_48 ,
V_61 , V_61 -> V_63 , V_18 ) ;
}
static int F_38 ( struct V_4 * V_4 , T_1 V_59 )
{
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_5 * V_6 = & V_1 -> V_6 ;
T_1 V_48 = V_6 -> V_9 -> V_15 -> V_16 . V_17 ;
return F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_64 ,
V_12 | V_13 | V_14 ,
0 , V_59 << 8 | V_48 ,
NULL , 0 , V_18 ) ;
}
static int F_39 ( struct V_4 * V_4 ,
struct V_65 * V_65 )
{
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_5 * V_6 = & V_1 -> V_6 ;
T_1 V_48 = V_6 -> V_9 -> V_15 -> V_16 . V_17 ;
struct V_66 * F_5 ;
int V_49 ;
F_5 = F_40 ( sizeof( struct V_66 ) , V_46 ) ;
if ( ! F_5 )
return - V_67 ;
F_36 ( F_5 -> V_68 ,
& V_65 -> V_69 ) ;
F_5 -> V_70 = V_65 -> V_27 ;
if ( V_65 -> V_71 )
F_5 -> V_72 = V_65 -> V_71 -> V_72 ;
else
F_5 -> V_72 = F_41 ( V_73 ) ;
V_49 = F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_74 ,
V_12 | V_13 | V_14 ,
0 , V_65 -> V_75 << 8 | V_48 ,
F_5 , sizeof( struct V_66 ) ,
V_18 ) ;
F_42 ( F_5 ) ;
return V_49 ;
}
static int F_43 ( struct V_4 * V_4 , T_1 V_75 , T_4 V_76 ,
const void * V_77 , T_5 V_78 ,
T_1 V_79 )
{
int V_3 = - V_67 ;
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_5 * V_6 = & V_1 -> V_6 ;
T_1 V_48 = V_6 -> V_9 -> V_15 -> V_16 . V_17 ;
struct V_80 * V_81 ;
T_5 V_82 ;
V_82 = sizeof( * V_81 ) + V_78 ;
V_81 = F_40 ( V_82 , V_46 ) ;
if ( V_81 == NULL )
return - V_67 ;
V_81 -> V_63 = V_82 ;
V_81 -> V_83 = V_84 ;
V_81 -> V_85 [ 0 ] = ( V_76 >> 0 ) & 0xff ;
V_81 -> V_85 [ 1 ] = ( V_76 >> 8 ) & 0xff ;
V_81 -> V_85 [ 2 ] = ( V_76 >> 16 ) & 0xff ;
memcpy ( V_81 -> V_86 , V_77 , V_78 ) ;
V_3 = F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_87 ,
V_12 | V_13 | V_14 ,
V_84 << 8 | V_79 ,
V_75 << 8 | V_48 ,
V_81 , V_82 , V_18 ) ;
F_44 ( V_81 ) ;
return V_3 ;
}
static int F_45 ( struct V_4 * V_4 , T_1 V_75 , T_4 V_76 ,
const void * V_77 , T_5 V_78 )
{
int V_3 = - V_67 ;
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_5 * V_6 = & V_1 -> V_6 ;
T_1 V_48 = V_6 -> V_9 -> V_15 -> V_16 . V_17 ;
T_1 V_88 ;
if ( V_77 ) {
T_1 V_79 = F_46 ( 0 , V_89 ,
V_90 ) ;
V_3 = F_43 ( V_4 , V_75 , V_76 ,
V_77 , V_78 , V_79 ) ;
if ( V_3 < 0 )
goto V_91;
V_88 = V_4 -> V_92 -> V_93 ;
} else {
V_88 = 0 ;
}
V_3 = F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_94 ,
V_12 | V_13 | V_14 ,
V_88 , V_75 << 8 | V_48 ,
NULL , 0 , V_18 ) ;
if ( V_3 < 0 )
F_4 ( V_4 -> V_8 , L_10
L_11 , V_75 ,
F_47 ( V_4 -> V_92 -> V_95 ) ,
V_4 -> V_92 -> V_93 , V_3 ) ;
V_91:
return V_3 ;
}
static int F_48 ( struct V_4 * V_4 , T_4 V_76 ,
const void * V_77 , T_5 V_78 )
{
T_1 V_79 = F_46 ( 0 , V_96 ,
V_90 ) ;
return F_43 ( V_4 , 0 , V_76 , V_77 , V_78 , V_79 ) ;
}
static int F_49 ( struct V_5 * V_6 )
{
int V_3 ;
struct V_7 * V_8 = & V_6 -> V_9 -> V_8 ;
char * V_97 ;
struct V_98 * V_10 = V_6 -> V_10 ;
struct V_99 * V_100 ;
struct V_101 * V_102 ;
T_5 V_103 , V_104 ;
V_104 = ( V_10 -> V_105 - V_10 -> V_106 ) /
sizeof( V_10 -> V_106 [ 0 ] ) ;
V_97 = V_10 -> V_107 [ V_104 ] ;
V_103 = F_50 ( V_10 -> V_105 -> V_16 . V_108 ) ;
while ( V_103 >= sizeof( * V_100 ) ) {
V_100 = (struct V_99 * ) V_97 ;
F_51 ( V_8 , L_12
L_13 ,
V_100 -> V_83 , V_100 -> V_63 ,
( V_97 - V_10 -> V_107 [ V_104 ] ) ,
V_103 ) ;
if ( V_100 -> V_83 == V_109 )
goto V_110;
V_97 += V_100 -> V_63 ;
V_103 -= V_100 -> V_63 ;
}
F_4 ( V_8 , L_14 ) ;
return - V_111 ;
V_110:
V_3 = - V_112 ;
if ( V_100 -> V_63 > V_103 ) {
F_4 ( V_8 , L_15
L_16 ,
V_103 , V_100 -> V_63 ) ;
goto error;
}
if ( V_100 -> V_63 < sizeof( * V_6 -> V_102 ) ) {
F_4 ( V_8 , L_17 ) ;
goto error;
}
V_6 -> V_102 = V_102 = (struct V_101 * ) V_100 ;
if ( F_50 ( V_102 -> V_113 ) > 0x0100 )
F_52 ( V_8 , L_18 ,
F_50 ( V_102 -> V_113 ) & 0xff00 >> 8 ,
F_50 ( V_102 -> V_113 ) & 0x00ff ) ;
V_3 = 0 ;
error:
return V_3 ;
}
static int F_53 ( struct V_1 * V_1 )
{
int V_3 ;
struct V_4 * V_4 = & V_1 -> V_4 ;
struct V_98 * V_10 = V_1 -> V_6 . V_10 ;
struct V_7 * V_8 = & V_10 -> V_8 ;
struct V_114 * V_115 ;
struct V_116 * V_117 ;
void * V_97 , * V_118 ;
T_5 V_103 , V_119 , V_120 ;
T_1 V_121 ;
char V_122 [ 64 ] ;
V_121 = ( V_10 -> V_105 - V_10 -> V_106 ) /
sizeof( V_10 -> V_106 [ 0 ] ) ;
V_97 = V_10 -> V_107 [ V_121 ] ;
V_103 = F_50 ( V_10 -> V_105 -> V_16 . V_108 ) ;
V_118 = V_97 + V_103 ;
V_3 = F_54 ( V_10 -> V_107 [ V_121 ] ,
F_50 ( V_10 -> V_105 -> V_16 . V_108 ) ,
V_123 , ( void * * ) & V_115 ) ;
if ( V_3 == - 1 ) {
F_52 ( V_8 , L_19 ) ;
return 0 ;
}
V_119 = sizeof( * V_115 ) ;
if ( V_118 - ( void * ) V_115 < V_119 ) {
F_4 ( V_8 , L_20
L_21 ,
V_118 - ( void * ) V_115 , V_119 ) ;
return 0 ;
}
V_119 = F_50 ( V_115 -> V_108 ) ;
if ( V_118 - ( void * ) V_115 < V_119 ) {
F_4 ( V_8 , L_20
L_22 ,
V_118 - ( void * ) V_115 , V_119 ) ;
return 0 ;
}
V_97 = ( void * ) V_115 + sizeof( * V_115 ) ;
V_118 = ( void * ) V_115 + F_50 ( V_115 -> V_108 ) ;
V_121 = 0 ;
V_120 = 0 ;
while ( V_97 < V_118 ) {
V_117 = V_97 ;
if ( V_118 - V_97 < sizeof( * V_117 ) ) {
F_4 ( V_8 , L_23
L_24 ,
V_118 - V_97 , sizeof( * V_117 ) ) ;
break;
}
if ( V_117 -> V_63 < sizeof( * V_117 ) ) {
F_4 ( V_8 , L_25
L_26
L_27 ,
( T_5 ) V_117 -> V_63 , sizeof( * V_117 ) ) ;
break;
}
V_97 += V_117 -> V_63 ;
V_120 += snprintf ( V_122 + V_120 , sizeof( V_122 ) - V_120 ,
L_28 ,
F_47 ( V_117 -> V_95 ) ,
V_117 -> V_93 ) ;
V_4 -> V_92 = V_117 ;
}
F_5 ( V_8 , L_29 , V_122 ) ;
if ( V_4 -> V_92 == NULL ) {
F_4 ( V_8 , L_30 ) ;
return 0 ;
}
return 0 ;
}
static void F_55 ( struct V_1 * V_1 )
{
}
static int F_56 ( struct V_1 * V_1 , struct V_124 * V_125 ,
T_6 V_126 )
{
int V_3 ;
struct V_7 * V_8 = & V_125 -> V_8 ;
struct V_4 * V_4 = & V_1 -> V_4 ;
struct V_5 * V_6 = & V_1 -> V_6 ;
struct V_98 * V_10 = F_57 ( V_125 ) ;
V_6 -> V_10 = F_58 ( V_10 ) ;
V_6 -> V_9 = F_59 ( V_125 ) ;
V_4 -> V_8 = V_8 ;
V_4 -> V_127 = NULL ;
V_3 = F_49 ( V_6 ) ;
if ( V_3 < 0 )
goto V_128;
if ( V_6 -> V_102 -> V_129 > V_130 ) {
F_4 ( V_8 , L_31
L_32 , V_6 -> V_102 -> V_129 ) ;
V_4 -> V_131 = V_130 ;
} else {
V_4 -> V_131 = V_6 -> V_102 -> V_129 ;
}
V_4 -> V_132 = V_6 -> V_102 -> V_133 ;
V_4 -> V_134 = F_29 ;
V_4 -> V_135 = F_32 ;
V_4 -> V_136 = F_37 ;
V_4 -> V_137 = F_38 ;
V_4 -> V_138 = F_39 ;
V_4 -> V_139 = F_35 ;
V_4 -> V_140 = F_6 ;
V_4 -> V_141 = F_45 ;
V_4 -> V_142 = F_48 ;
V_3 = F_53 ( V_1 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_33 , V_3 ) ;
goto V_143;
}
V_6 -> V_144 = V_4 ;
V_3 = F_60 ( & V_1 -> V_4 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_34 , V_3 ) ;
goto V_145;
}
V_3 = F_61 ( & V_1 -> V_6 , V_125 , V_126 ) ;
if ( V_3 < 0 )
goto V_146;
return 0 ;
V_146:
F_62 ( & V_1 -> V_4 ) ;
V_145:
V_143:
V_128:
F_63 ( V_125 ) ;
F_64 ( V_10 ) ;
return V_3 ;
}
static void F_65 ( struct V_1 * V_1 )
{
struct V_4 * V_4 = & V_1 -> V_4 ;
F_10 ( & V_4 -> V_23 ) ;
F_66 ( & V_1 -> V_6 ) ;
F_62 ( & V_1 -> V_4 ) ;
F_55 ( V_1 ) ;
V_1 -> V_4 . V_8 = NULL ;
F_67 ( V_4 -> V_127 ) ;
F_63 ( V_1 -> V_6 . V_9 ) ;
F_64 ( V_1 -> V_6 . V_10 ) ;
F_14 ( & V_4 -> V_23 ) ;
}
static void F_68 ( struct V_1 * V_1 )
{
F_69 ( & V_1 -> V_6 ) ;
}
static int F_70 ( struct V_124 * V_9 ,
const struct V_147 * V_148 )
{
int V_3 ;
struct V_22 * V_22 ;
struct V_4 * V_4 ;
struct V_1 * V_1 ;
struct V_7 * V_8 = & V_9 -> V_8 ;
V_3 = - V_67 ;
V_22 = F_71 ( & V_149 , & V_9 -> V_8 , L_35 ) ;
if ( V_22 == NULL ) {
F_4 ( V_8 , L_36 ) ;
goto V_150;
}
V_22 -> V_151 = 1 ;
V_22 -> V_36 . V_152 = ~ 0 ;
V_4 = F_9 ( V_22 ) ;
V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
F_68 ( V_1 ) ;
V_3 = F_56 ( V_1 , V_9 , V_148 -> V_153 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_37 , V_3 ) ;
goto V_154;
}
V_3 = F_72 ( V_22 , 0 , 0 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_38 , V_3 ) ;
goto V_155;
}
F_73 ( V_22 -> V_36 . V_156 ) ;
V_3 = F_74 ( & V_1 -> V_4 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_39 , V_3 ) ;
goto V_157;
}
return 0 ;
V_157:
F_75 ( V_22 ) ;
V_155:
F_65 ( V_1 ) ;
V_154:
F_76 ( V_22 ) ;
V_150:
return V_3 ;
}
static void F_77 ( struct V_124 * V_9 )
{
struct V_22 * V_22 ;
struct V_4 * V_4 ;
struct V_1 * V_1 ;
V_22 = F_78 ( V_9 ) ;
V_4 = F_9 ( V_22 ) ;
V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
F_79 ( & V_1 -> V_4 ) ;
F_75 ( V_22 ) ;
F_65 ( V_1 ) ;
F_76 ( V_22 ) ;
}
