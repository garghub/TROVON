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
NULL , 0 , 1000 ) ;
if ( V_3 < 0 )
F_4 ( V_8 , L_1 ,
V_2 , V_3 ) ;
else
V_4 -> V_2 = V_2 ;
F_5 ( V_8 , L_2 , V_2 ) ;
return V_3 ;
}
static int F_6 ( struct V_4 * V_4 , T_1 V_18 , T_1 V_19 )
{
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_5 * V_6 = & V_1 -> V_6 ;
return F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_20 ,
V_12 | V_13 | V_14 ,
V_18 << 8 | V_19 ,
V_6 -> V_9 -> V_15 -> V_16 . V_17 ,
NULL , 0 , 1000 ) ;
}
static int F_8 ( struct V_21 * V_21 )
{
int V_3 ;
struct V_4 * V_4 = F_9 ( V_21 ) ;
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_7 * V_8 = & V_1 -> V_6 . V_9 -> V_8 ;
F_10 ( & V_4 -> V_22 ) ;
F_11 ( & V_1 -> V_6 ) ;
V_3 = F_12 ( & V_1 -> V_6 , V_23 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_3 , V_3 ) ;
goto V_24;
}
V_3 = F_13 ( & V_1 -> V_6 , V_25 , 0 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_4 , V_3 ) ;
goto V_24;
}
V_24:
F_14 ( & V_4 -> V_22 ) ;
return V_3 ;
}
static int F_15 ( struct V_21 * V_21 )
{
T_1 V_26 ;
int V_3 ;
struct V_4 * V_4 = F_9 ( V_21 ) ;
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
V_3 = - V_27 ;
F_10 ( & V_4 -> V_22 ) ;
V_26 = F_16 () ;
if ( V_26 == 0 )
goto V_28;
V_3 = F_1 ( V_1 , V_26 ) ;
if ( V_3 < 0 )
goto V_29;
V_21 -> V_30 = 1 ;
F_17 ( V_31 , & V_21 -> V_32 ) ;
V_21 -> V_33 = V_34 ;
F_18 ( & V_21 -> V_35 . V_36 -> V_8 ) ;
V_3 = 0 ;
V_37:
F_14 ( & V_4 -> V_22 ) ;
return V_3 ;
V_29:
F_19 ( V_4 -> V_2 ) ;
V_28:
goto V_37;
}
static void F_20 ( struct V_21 * V_21 )
{
struct V_4 * V_4 = F_9 ( V_21 ) ;
F_10 ( & V_4 -> V_22 ) ;
F_19 ( V_4 -> V_2 ) ;
F_14 ( & V_4 -> V_22 ) ;
}
static int F_21 ( struct V_21 * V_21 )
{
struct V_4 * V_4 = F_9 ( V_21 ) ;
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
F_4 ( V_4 -> V_8 , L_5 , V_38 ,
V_21 , V_1 ) ;
return - V_39 ;
}
static int F_22 ( struct V_21 * V_21 , struct V_40 * V_40 ,
T_2 V_41 )
{
struct V_4 * V_4 = F_9 ( V_21 ) ;
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
return F_23 ( & V_1 -> V_6 , V_40 -> V_42 , V_40 , V_41 ) ;
}
static int F_24 ( struct V_21 * V_21 , struct V_40 * V_40 ,
int V_43 )
{
struct V_4 * V_4 = F_9 ( V_21 ) ;
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
return F_25 ( & V_1 -> V_6 , V_40 ) ;
}
static void F_26 ( struct V_21 * V_21 ,
struct V_44 * V_42 )
{
struct V_4 * V_4 = F_9 ( V_21 ) ;
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
F_27 ( & V_1 -> V_6 , V_42 ) ;
}
static int F_28 ( struct V_4 * V_4 )
{
int V_3 ;
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_7 * V_8 = & V_1 -> V_6 . V_9 -> V_8 ;
V_3 = F_12 ( & V_1 -> V_6 , V_45 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_6 , V_3 ) ;
goto V_46;
}
V_3 = F_13 ( & V_1 -> V_6 , V_45 , V_45 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_7 , V_3 ) ;
goto V_46;
}
V_3 = F_29 ( & V_1 -> V_6 , V_47 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_8 , V_3 ) ;
goto V_46;
}
return V_3 ;
V_46:
F_30 ( & V_1 -> V_6 , V_45 ) ;
return V_3 ;
}
static void F_31 ( struct V_4 * V_4 , int V_48 )
{
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_5 * V_6 = & V_1 -> V_6 ;
T_1 V_49 = V_6 -> V_9 -> V_15 -> V_16 . V_17 ;
int V_50 ;
V_50 = F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_51 ,
V_12 | V_13 | V_14 ,
V_48 * 1000 ,
V_49 ,
NULL , 0 , 1000 ) ;
if ( V_50 == 0 )
F_32 ( V_48 ) ;
F_11 ( & V_1 -> V_6 ) ;
F_33 ( & V_1 -> V_6 ) ;
}
static int F_34 ( struct V_4 * V_4 , T_3 V_52 ,
const struct V_53 * V_54 )
{
int V_3 ;
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_5 * V_6 = & V_1 -> V_6 ;
struct V_7 * V_8 = & V_6 -> V_9 -> V_8 ;
T_1 V_55 [ V_56 / 8 ] ;
V_3 = F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_57 ,
V_12 | V_13 | V_14 ,
V_52 ,
V_6 -> V_9 -> V_15 -> V_16 . V_17 ,
NULL , 0 , 1000 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_9 , V_3 ) ;
goto V_37;
}
F_35 ( V_55 , V_54 ) ;
V_3 = F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_58 ,
V_12 | V_13 | V_14 ,
0 , V_6 -> V_9 -> V_15 -> V_16 . V_17 ,
V_55 , 32 , 1000 ) ;
if ( V_3 < 0 )
F_4 ( V_8 , L_10 , V_3 ) ;
V_37:
return V_3 ;
}
static int F_36 ( struct V_4 * V_4 , T_1 V_18 ,
T_1 V_59 , T_1 V_60 ,
struct V_61 * V_62 )
{
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_5 * V_6 = & V_1 -> V_6 ;
T_1 V_49 = V_6 -> V_9 -> V_15 -> V_16 . V_17 ;
return F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_63 ,
V_12 | V_13 | V_14 ,
V_18 << 8 | V_59 ,
V_60 << 8 | V_49 ,
V_62 , V_62 -> V_64 , 1000 ) ;
}
static int F_37 ( struct V_4 * V_4 , T_1 V_60 )
{
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_5 * V_6 = & V_1 -> V_6 ;
T_1 V_49 = V_6 -> V_9 -> V_15 -> V_16 . V_17 ;
return F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_65 ,
V_12 | V_13 | V_14 ,
0 , V_60 << 8 | V_49 ,
NULL , 0 , 1000 ) ;
}
static int F_38 ( struct V_4 * V_4 ,
struct V_66 * V_66 )
{
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_5 * V_6 = & V_1 -> V_6 ;
T_1 V_49 = V_6 -> V_9 -> V_15 -> V_16 . V_17 ;
struct V_67 * F_5 ;
int V_50 ;
F_5 = F_39 ( sizeof( struct V_67 ) , V_47 ) ;
if ( ! F_5 )
return - V_68 ;
F_35 ( F_5 -> V_69 ,
& V_66 -> V_70 ) ;
F_5 -> V_71 = V_66 -> V_26 ;
if ( V_66 -> V_72 )
F_5 -> V_73 = V_66 -> V_72 -> V_73 ;
else
F_5 -> V_73 = F_40 ( V_74 ) ;
V_50 = F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_75 ,
V_12 | V_13 | V_14 ,
0 , V_66 -> V_76 << 8 | V_49 ,
F_5 , sizeof( struct V_67 ) ,
1000 ) ;
F_41 ( F_5 ) ;
return V_50 ;
}
static int F_42 ( struct V_4 * V_4 , T_1 V_76 , T_4 V_77 ,
const void * V_78 , T_5 V_79 ,
T_1 V_80 )
{
int V_3 = - V_68 ;
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_5 * V_6 = & V_1 -> V_6 ;
T_1 V_49 = V_6 -> V_9 -> V_15 -> V_16 . V_17 ;
struct V_81 * V_82 ;
T_5 V_83 ;
V_83 = sizeof( * V_82 ) + V_79 ;
V_82 = F_39 ( V_83 , V_47 ) ;
if ( V_82 == NULL )
return - V_68 ;
V_82 -> V_64 = V_83 ;
V_82 -> V_84 = V_85 ;
V_82 -> V_86 [ 0 ] = ( V_77 >> 0 ) & 0xff ;
V_82 -> V_86 [ 1 ] = ( V_77 >> 8 ) & 0xff ;
V_82 -> V_86 [ 2 ] = ( V_77 >> 16 ) & 0xff ;
memcpy ( V_82 -> V_87 , V_78 , V_79 ) ;
V_3 = F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_88 ,
V_12 | V_13 | V_14 ,
V_85 << 8 | V_80 ,
V_76 << 8 | V_49 ,
V_82 , V_83 , 1000 ) ;
F_43 ( V_82 ) ;
return V_3 ;
}
static int F_44 ( struct V_4 * V_4 , T_1 V_76 , T_4 V_77 ,
const void * V_78 , T_5 V_79 )
{
int V_3 = - V_68 ;
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_5 * V_6 = & V_1 -> V_6 ;
T_1 V_49 = V_6 -> V_9 -> V_15 -> V_16 . V_17 ;
T_1 V_89 ;
if ( V_78 ) {
T_1 V_80 = F_45 ( 0 , V_90 ,
V_91 ) ;
V_3 = F_42 ( V_4 , V_76 , V_77 ,
V_78 , V_79 , V_80 ) ;
if ( V_3 < 0 )
goto V_92;
V_89 = V_4 -> V_93 -> V_94 ;
} else {
V_89 = 0 ;
}
V_3 = F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_95 ,
V_12 | V_13 | V_14 ,
V_89 , V_76 << 8 | V_49 ,
NULL , 0 , 1000 ) ;
if ( V_3 < 0 )
F_4 ( V_4 -> V_8 , L_11
L_12 , V_76 ,
F_46 ( V_4 -> V_93 -> V_96 ) ,
V_4 -> V_93 -> V_94 , V_3 ) ;
V_92:
return V_3 ;
}
static int F_47 ( struct V_4 * V_4 , T_4 V_77 ,
const void * V_78 , T_5 V_79 )
{
T_1 V_80 = F_45 ( 0 , V_97 ,
V_91 ) ;
return F_42 ( V_4 , 0 , V_77 , V_78 , V_79 , V_80 ) ;
}
static int F_48 ( struct V_5 * V_6 )
{
int V_3 ;
struct V_7 * V_8 = & V_6 -> V_9 -> V_8 ;
char * V_98 ;
struct V_99 * V_10 = V_6 -> V_10 ;
struct V_100 * V_101 ;
struct V_102 * V_103 ;
T_5 V_104 , V_105 ;
V_105 = ( V_10 -> V_106 - V_10 -> V_107 ) /
sizeof( V_10 -> V_107 [ 0 ] ) ;
V_98 = V_10 -> V_108 [ V_105 ] ;
V_104 = F_49 ( V_10 -> V_106 -> V_16 . V_109 ) ;
while ( V_104 >= sizeof( * V_101 ) ) {
V_101 = (struct V_100 * ) V_98 ;
F_50 ( V_8 , L_13
L_14 ,
V_101 -> V_84 , V_101 -> V_64 ,
( V_98 - V_10 -> V_108 [ V_105 ] ) ,
V_104 ) ;
if ( V_101 -> V_84 == V_110 )
goto V_111;
V_98 += V_101 -> V_64 ;
V_104 -= V_101 -> V_64 ;
}
F_4 ( V_8 , L_15 ) ;
return - V_112 ;
V_111:
V_3 = - V_113 ;
if ( V_101 -> V_64 > V_104 ) {
F_4 ( V_8 , L_16
L_17 ,
V_104 , V_101 -> V_64 ) ;
goto error;
}
if ( V_101 -> V_64 < sizeof( * V_6 -> V_103 ) ) {
F_4 ( V_8 , L_18 ) ;
goto error;
}
V_6 -> V_103 = V_103 = (struct V_102 * ) V_101 ;
V_103 -> V_114 = F_49 ( V_103 -> V_114 ) ;
V_103 -> V_115 = F_49 ( V_103 -> V_115 ) ;
V_103 -> V_116 = F_49 ( V_103 -> V_116 ) ;
if ( V_103 -> V_114 > 0x0100 )
F_51 ( V_8 , L_19 ,
V_103 -> V_114 & 0xff00 >> 8 ,
V_103 -> V_114 & 0x00ff ) ;
V_3 = 0 ;
error:
return V_3 ;
}
static int F_52 ( struct V_1 * V_1 )
{
int V_3 ;
struct V_4 * V_4 = & V_1 -> V_4 ;
struct V_99 * V_10 = V_1 -> V_6 . V_10 ;
struct V_7 * V_8 = & V_10 -> V_8 ;
struct V_117 * V_118 ;
struct V_119 * V_120 ;
void * V_98 , * V_121 ;
T_5 V_104 , V_122 , V_123 ;
T_1 V_124 ;
char V_125 [ 64 ] ;
V_124 = ( V_10 -> V_106 - V_10 -> V_107 ) /
sizeof( V_10 -> V_107 [ 0 ] ) ;
V_98 = V_10 -> V_108 [ V_124 ] ;
V_104 = F_49 ( V_10 -> V_106 -> V_16 . V_109 ) ;
V_121 = V_98 + V_104 ;
V_3 = F_53 ( V_10 -> V_108 [ V_124 ] ,
F_49 ( V_10 -> V_106 -> V_16 . V_109 ) ,
V_126 , ( void * * ) & V_118 ) ;
if ( V_3 == - 1 ) {
F_51 ( V_8 , L_20 ) ;
return 0 ;
}
V_122 = sizeof( * V_118 ) ;
if ( V_121 - ( void * ) V_118 < V_122 ) {
F_4 ( V_8 , L_21
L_22 ,
V_121 - ( void * ) V_118 , V_122 ) ;
return 0 ;
}
V_122 = F_49 ( V_118 -> V_109 ) ;
if ( V_121 - ( void * ) V_118 < V_122 ) {
F_4 ( V_8 , L_21
L_23 ,
V_121 - ( void * ) V_118 , V_122 ) ;
return 0 ;
}
V_98 = ( void * ) V_118 + sizeof( * V_118 ) ;
V_121 = ( void * ) V_118 + F_49 ( V_118 -> V_109 ) ;
V_124 = 0 ;
V_123 = 0 ;
while ( V_98 < V_121 ) {
V_120 = V_98 ;
if ( V_121 - V_98 < sizeof( * V_120 ) ) {
F_4 ( V_8 , L_24
L_25 ,
V_121 - V_98 , sizeof( * V_120 ) ) ;
break;
}
if ( V_120 -> V_64 < sizeof( * V_120 ) ) {
F_4 ( V_8 , L_26
L_27
L_28 ,
( T_5 ) V_120 -> V_64 , sizeof( * V_120 ) ) ;
break;
}
V_98 += V_120 -> V_64 ;
V_123 += snprintf ( V_125 + V_123 , sizeof( V_125 ) - V_123 ,
L_29 ,
F_46 ( V_120 -> V_96 ) ,
V_120 -> V_94 ) ;
V_4 -> V_93 = V_120 ;
}
F_5 ( V_8 , L_30 , V_125 ) ;
if ( V_4 -> V_93 == NULL ) {
F_4 ( V_8 , L_31 ) ;
return 0 ;
}
return 0 ;
}
static void F_54 ( struct V_1 * V_1 )
{
}
static int F_55 ( struct V_1 * V_1 , struct V_127 * V_128 )
{
int V_3 ;
struct V_7 * V_8 = & V_128 -> V_8 ;
struct V_4 * V_4 = & V_1 -> V_4 ;
struct V_5 * V_6 = & V_1 -> V_6 ;
struct V_99 * V_10 = F_56 ( V_128 ) ;
V_6 -> V_10 = F_57 ( V_10 ) ;
V_6 -> V_9 = F_58 ( V_128 ) ;
V_4 -> V_8 = V_8 ;
V_4 -> V_129 = NULL ;
V_3 = F_48 ( V_6 ) ;
if ( V_3 < 0 )
goto V_130;
if ( V_6 -> V_103 -> V_131 > V_132 ) {
F_4 ( V_8 , L_32
L_33 , V_6 -> V_103 -> V_131 ) ;
V_4 -> V_133 = V_132 ;
} else {
V_4 -> V_133 = V_6 -> V_103 -> V_131 ;
}
V_4 -> V_134 = V_6 -> V_103 -> V_135 ;
V_4 -> V_136 = F_28 ;
V_4 -> V_137 = F_31 ;
V_4 -> V_138 = F_36 ;
V_4 -> V_139 = F_37 ;
V_4 -> V_140 = F_38 ;
V_4 -> V_141 = F_34 ;
V_4 -> V_142 = F_6 ;
V_4 -> V_143 = F_44 ;
V_4 -> V_144 = F_47 ;
V_3 = F_52 ( V_1 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_34 , V_3 ) ;
goto V_145;
}
V_6 -> V_146 = V_4 ;
V_3 = F_59 ( & V_1 -> V_4 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_35 , V_3 ) ;
goto V_147;
}
V_3 = F_60 ( & V_1 -> V_6 , V_128 ) ;
if ( V_3 < 0 )
goto V_148;
return 0 ;
V_148:
F_61 ( & V_1 -> V_4 ) ;
V_147:
V_145:
V_130:
F_62 ( V_128 ) ;
F_63 ( V_10 ) ;
return V_3 ;
}
static void F_64 ( struct V_1 * V_1 )
{
struct V_4 * V_4 = & V_1 -> V_4 ;
F_10 ( & V_4 -> V_22 ) ;
F_65 ( & V_1 -> V_6 ) ;
F_61 ( & V_1 -> V_4 ) ;
F_54 ( V_1 ) ;
V_1 -> V_4 . V_8 = NULL ;
F_66 ( V_4 -> V_129 ) ;
F_62 ( V_1 -> V_6 . V_9 ) ;
F_63 ( V_1 -> V_6 . V_10 ) ;
F_14 ( & V_4 -> V_22 ) ;
}
static void F_67 ( struct V_1 * V_1 )
{
F_68 ( & V_1 -> V_6 ) ;
}
static int F_69 ( struct V_127 * V_9 ,
const struct V_149 * V_150 )
{
int V_3 ;
struct V_21 * V_21 ;
struct V_4 * V_4 ;
struct V_1 * V_1 ;
struct V_7 * V_8 = & V_9 -> V_8 ;
V_3 = - V_68 ;
V_21 = F_70 ( & V_151 , & V_9 -> V_8 , L_36 ) ;
if ( V_21 == NULL ) {
F_4 ( V_8 , L_37 ) ;
goto V_152;
}
V_21 -> V_153 = 1 ;
V_21 -> V_35 . V_154 = ~ 0 ;
V_4 = F_9 ( V_21 ) ;
V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
F_67 ( V_1 ) ;
V_3 = F_55 ( V_1 , V_9 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_38 , V_3 ) ;
goto V_155;
}
V_3 = F_71 ( V_21 , 0 , 0 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_39 , V_3 ) ;
goto V_156;
}
V_3 = F_72 ( & V_1 -> V_4 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_40 , V_3 ) ;
goto V_157;
}
return 0 ;
V_157:
F_73 ( V_21 ) ;
V_156:
F_64 ( V_1 ) ;
V_155:
F_74 ( V_21 ) ;
V_152:
return V_3 ;
}
static void F_75 ( struct V_127 * V_9 )
{
struct V_21 * V_21 ;
struct V_4 * V_4 ;
struct V_1 * V_1 ;
V_21 = F_76 ( V_9 ) ;
V_4 = F_9 ( V_21 ) ;
V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
F_77 ( & V_1 -> V_4 ) ;
F_73 ( V_21 ) ;
F_64 ( V_1 ) ;
F_74 ( V_21 ) ;
}
