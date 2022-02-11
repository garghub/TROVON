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
struct V_5 * V_6 = & V_1 -> V_6 ;
return F_22 ( V_6 -> V_10 ) ;
}
static int F_23 ( struct V_21 * V_21 , struct V_38 * V_38 ,
T_2 V_39 )
{
struct V_4 * V_4 = F_9 ( V_21 ) ;
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
return F_24 ( & V_1 -> V_6 , V_38 -> V_40 , V_38 , V_39 ) ;
}
static int F_25 ( struct V_21 * V_21 , struct V_38 * V_38 ,
int V_41 )
{
struct V_4 * V_4 = F_9 ( V_21 ) ;
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
return F_26 ( & V_1 -> V_6 , V_38 ) ;
}
static void F_27 ( struct V_21 * V_21 ,
struct V_42 * V_40 )
{
struct V_4 * V_4 = F_9 ( V_21 ) ;
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
F_28 ( & V_1 -> V_6 , V_40 ) ;
}
static int F_29 ( struct V_4 * V_4 )
{
int V_3 ;
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_7 * V_8 = & V_1 -> V_6 . V_9 -> V_8 ;
V_3 = F_12 ( & V_1 -> V_6 , V_43 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_5 , V_3 ) ;
goto V_44;
}
V_3 = F_13 ( & V_1 -> V_6 , V_43 , V_43 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_6 , V_3 ) ;
goto V_44;
}
V_3 = F_30 ( & V_1 -> V_6 , V_45 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_7 , V_3 ) ;
goto V_44;
}
return V_3 ;
V_44:
F_31 ( & V_1 -> V_6 , V_43 ) ;
return V_3 ;
}
static void F_32 ( struct V_4 * V_4 , int V_46 )
{
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_5 * V_6 = & V_1 -> V_6 ;
T_1 V_47 = V_6 -> V_9 -> V_15 -> V_16 . V_17 ;
int V_48 ;
V_48 = F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_49 ,
V_12 | V_13 | V_14 ,
V_46 * 1000 ,
V_47 ,
NULL , 0 , 1000 ) ;
if ( V_48 == 0 )
F_33 ( V_46 ) ;
F_11 ( & V_1 -> V_6 ) ;
F_34 ( & V_1 -> V_6 ) ;
}
static int F_35 ( struct V_4 * V_4 , T_3 V_50 ,
const struct V_51 * V_52 )
{
int V_3 ;
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_5 * V_6 = & V_1 -> V_6 ;
struct V_7 * V_8 = & V_6 -> V_9 -> V_8 ;
T_1 V_53 [ V_54 / 8 ] ;
V_3 = F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_55 ,
V_12 | V_13 | V_14 ,
V_50 ,
V_6 -> V_9 -> V_15 -> V_16 . V_17 ,
NULL , 0 , 1000 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_8 , V_3 ) ;
goto V_37;
}
F_36 ( V_53 , V_52 ) ;
V_3 = F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_56 ,
V_12 | V_13 | V_14 ,
0 , V_6 -> V_9 -> V_15 -> V_16 . V_17 ,
V_53 , 32 , 1000 ) ;
if ( V_3 < 0 )
F_4 ( V_8 , L_9 , V_3 ) ;
V_37:
return V_3 ;
}
static int F_37 ( struct V_4 * V_4 , T_1 V_18 ,
T_1 V_57 , T_1 V_58 ,
struct V_59 * V_60 )
{
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_5 * V_6 = & V_1 -> V_6 ;
T_1 V_47 = V_6 -> V_9 -> V_15 -> V_16 . V_17 ;
return F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_61 ,
V_12 | V_13 | V_14 ,
V_18 << 8 | V_57 ,
V_58 << 8 | V_47 ,
V_60 , V_60 -> V_62 , 1000 ) ;
}
static int F_38 ( struct V_4 * V_4 , T_1 V_58 )
{
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_5 * V_6 = & V_1 -> V_6 ;
T_1 V_47 = V_6 -> V_9 -> V_15 -> V_16 . V_17 ;
return F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_63 ,
V_12 | V_13 | V_14 ,
0 , V_58 << 8 | V_47 ,
NULL , 0 , 1000 ) ;
}
static int F_39 ( struct V_4 * V_4 ,
struct V_64 * V_64 )
{
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_5 * V_6 = & V_1 -> V_6 ;
T_1 V_47 = V_6 -> V_9 -> V_15 -> V_16 . V_17 ;
struct V_65 * F_5 ;
int V_48 ;
F_5 = F_40 ( sizeof( struct V_65 ) , V_45 ) ;
if ( ! F_5 )
return - V_66 ;
F_36 ( F_5 -> V_67 ,
& V_64 -> V_68 ) ;
F_5 -> V_69 = V_64 -> V_26 ;
if ( V_64 -> V_70 )
F_5 -> V_71 = V_64 -> V_70 -> V_71 ;
else
F_5 -> V_71 = F_41 ( V_72 ) ;
V_48 = F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_73 ,
V_12 | V_13 | V_14 ,
0 , V_64 -> V_74 << 8 | V_47 ,
F_5 , sizeof( struct V_65 ) ,
1000 ) ;
F_42 ( F_5 ) ;
return V_48 ;
}
static int F_43 ( struct V_4 * V_4 , T_1 V_74 , T_4 V_75 ,
const void * V_76 , T_5 V_77 ,
T_1 V_78 )
{
int V_3 = - V_66 ;
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_5 * V_6 = & V_1 -> V_6 ;
T_1 V_47 = V_6 -> V_9 -> V_15 -> V_16 . V_17 ;
struct V_79 * V_80 ;
T_5 V_81 ;
V_81 = sizeof( * V_80 ) + V_77 ;
V_80 = F_40 ( V_81 , V_45 ) ;
if ( V_80 == NULL )
return - V_66 ;
V_80 -> V_62 = V_81 ;
V_80 -> V_82 = V_83 ;
V_80 -> V_84 [ 0 ] = ( V_75 >> 0 ) & 0xff ;
V_80 -> V_84 [ 1 ] = ( V_75 >> 8 ) & 0xff ;
V_80 -> V_84 [ 2 ] = ( V_75 >> 16 ) & 0xff ;
memcpy ( V_80 -> V_85 , V_76 , V_77 ) ;
V_3 = F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_86 ,
V_12 | V_13 | V_14 ,
V_83 << 8 | V_78 ,
V_74 << 8 | V_47 ,
V_80 , V_81 , 1000 ) ;
F_44 ( V_80 ) ;
return V_3 ;
}
static int F_45 ( struct V_4 * V_4 , T_1 V_74 , T_4 V_75 ,
const void * V_76 , T_5 V_77 )
{
int V_3 = - V_66 ;
struct V_1 * V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
struct V_5 * V_6 = & V_1 -> V_6 ;
T_1 V_47 = V_6 -> V_9 -> V_15 -> V_16 . V_17 ;
T_1 V_87 ;
if ( V_76 ) {
T_1 V_78 = F_46 ( 0 , V_88 ,
V_89 ) ;
V_3 = F_43 ( V_4 , V_74 , V_75 ,
V_76 , V_77 , V_78 ) ;
if ( V_3 < 0 )
goto V_90;
V_87 = V_4 -> V_91 -> V_92 ;
} else {
V_87 = 0 ;
}
V_3 = F_2 ( V_6 -> V_10 , F_3 ( V_6 -> V_10 , 0 ) ,
V_93 ,
V_12 | V_13 | V_14 ,
V_87 , V_74 << 8 | V_47 ,
NULL , 0 , 1000 ) ;
if ( V_3 < 0 )
F_4 ( V_4 -> V_8 , L_10
L_11 , V_74 ,
F_47 ( V_4 -> V_91 -> V_94 ) ,
V_4 -> V_91 -> V_92 , V_3 ) ;
V_90:
return V_3 ;
}
static int F_48 ( struct V_4 * V_4 , T_4 V_75 ,
const void * V_76 , T_5 V_77 )
{
T_1 V_78 = F_46 ( 0 , V_95 ,
V_89 ) ;
return F_43 ( V_4 , 0 , V_75 , V_76 , V_77 , V_78 ) ;
}
static int F_49 ( struct V_5 * V_6 )
{
int V_3 ;
struct V_7 * V_8 = & V_6 -> V_9 -> V_8 ;
char * V_96 ;
struct V_97 * V_10 = V_6 -> V_10 ;
struct V_98 * V_99 ;
struct V_100 * V_101 ;
T_5 V_102 , V_103 ;
V_103 = ( V_10 -> V_104 - V_10 -> V_105 ) /
sizeof( V_10 -> V_105 [ 0 ] ) ;
V_96 = V_10 -> V_106 [ V_103 ] ;
V_102 = F_50 ( V_10 -> V_104 -> V_16 . V_107 ) ;
while ( V_102 >= sizeof( * V_99 ) ) {
V_99 = (struct V_98 * ) V_96 ;
F_51 ( V_8 , L_12
L_13 ,
V_99 -> V_82 , V_99 -> V_62 ,
( V_96 - V_10 -> V_106 [ V_103 ] ) ,
V_102 ) ;
if ( V_99 -> V_82 == V_108 )
goto V_109;
V_96 += V_99 -> V_62 ;
V_102 -= V_99 -> V_62 ;
}
F_4 ( V_8 , L_14 ) ;
return - V_110 ;
V_109:
V_3 = - V_111 ;
if ( V_99 -> V_62 > V_102 ) {
F_4 ( V_8 , L_15
L_16 ,
V_102 , V_99 -> V_62 ) ;
goto error;
}
if ( V_99 -> V_62 < sizeof( * V_6 -> V_101 ) ) {
F_4 ( V_8 , L_17 ) ;
goto error;
}
V_6 -> V_101 = V_101 = (struct V_100 * ) V_99 ;
if ( F_50 ( V_101 -> V_112 ) > 0x0100 )
F_52 ( V_8 , L_18 ,
F_50 ( V_101 -> V_112 ) & 0xff00 >> 8 ,
F_50 ( V_101 -> V_112 ) & 0x00ff ) ;
V_3 = 0 ;
error:
return V_3 ;
}
static int F_53 ( struct V_1 * V_1 )
{
int V_3 ;
struct V_4 * V_4 = & V_1 -> V_4 ;
struct V_97 * V_10 = V_1 -> V_6 . V_10 ;
struct V_7 * V_8 = & V_10 -> V_8 ;
struct V_113 * V_114 ;
struct V_115 * V_116 ;
void * V_96 , * V_117 ;
T_5 V_102 , V_118 , V_119 ;
T_1 V_120 ;
char V_121 [ 64 ] ;
V_120 = ( V_10 -> V_104 - V_10 -> V_105 ) /
sizeof( V_10 -> V_105 [ 0 ] ) ;
V_96 = V_10 -> V_106 [ V_120 ] ;
V_102 = F_50 ( V_10 -> V_104 -> V_16 . V_107 ) ;
V_117 = V_96 + V_102 ;
V_3 = F_54 ( V_10 -> V_106 [ V_120 ] ,
F_50 ( V_10 -> V_104 -> V_16 . V_107 ) ,
V_122 , ( void * * ) & V_114 ) ;
if ( V_3 == - 1 ) {
F_52 ( V_8 , L_19 ) ;
return 0 ;
}
V_118 = sizeof( * V_114 ) ;
if ( V_117 - ( void * ) V_114 < V_118 ) {
F_4 ( V_8 , L_20
L_21 ,
V_117 - ( void * ) V_114 , V_118 ) ;
return 0 ;
}
V_118 = F_50 ( V_114 -> V_107 ) ;
if ( V_117 - ( void * ) V_114 < V_118 ) {
F_4 ( V_8 , L_20
L_22 ,
V_117 - ( void * ) V_114 , V_118 ) ;
return 0 ;
}
V_96 = ( void * ) V_114 + sizeof( * V_114 ) ;
V_117 = ( void * ) V_114 + F_50 ( V_114 -> V_107 ) ;
V_120 = 0 ;
V_119 = 0 ;
while ( V_96 < V_117 ) {
V_116 = V_96 ;
if ( V_117 - V_96 < sizeof( * V_116 ) ) {
F_4 ( V_8 , L_23
L_24 ,
V_117 - V_96 , sizeof( * V_116 ) ) ;
break;
}
if ( V_116 -> V_62 < sizeof( * V_116 ) ) {
F_4 ( V_8 , L_25
L_26
L_27 ,
( T_5 ) V_116 -> V_62 , sizeof( * V_116 ) ) ;
break;
}
V_96 += V_116 -> V_62 ;
V_119 += snprintf ( V_121 + V_119 , sizeof( V_121 ) - V_119 ,
L_28 ,
F_47 ( V_116 -> V_94 ) ,
V_116 -> V_92 ) ;
V_4 -> V_91 = V_116 ;
}
F_5 ( V_8 , L_29 , V_121 ) ;
if ( V_4 -> V_91 == NULL ) {
F_4 ( V_8 , L_30 ) ;
return 0 ;
}
return 0 ;
}
static void F_55 ( struct V_1 * V_1 )
{
}
static int F_56 ( struct V_1 * V_1 , struct V_123 * V_124 ,
T_6 V_125 )
{
int V_3 ;
struct V_7 * V_8 = & V_124 -> V_8 ;
struct V_4 * V_4 = & V_1 -> V_4 ;
struct V_5 * V_6 = & V_1 -> V_6 ;
struct V_97 * V_10 = F_57 ( V_124 ) ;
V_6 -> V_10 = F_58 ( V_10 ) ;
V_6 -> V_9 = F_59 ( V_124 ) ;
V_4 -> V_8 = V_8 ;
V_4 -> V_126 = NULL ;
V_3 = F_49 ( V_6 ) ;
if ( V_3 < 0 )
goto V_127;
if ( V_6 -> V_101 -> V_128 > V_129 ) {
F_4 ( V_8 , L_31
L_32 , V_6 -> V_101 -> V_128 ) ;
V_4 -> V_130 = V_129 ;
} else {
V_4 -> V_130 = V_6 -> V_101 -> V_128 ;
}
V_4 -> V_131 = V_6 -> V_101 -> V_132 ;
V_4 -> V_133 = F_29 ;
V_4 -> V_134 = F_32 ;
V_4 -> V_135 = F_37 ;
V_4 -> V_136 = F_38 ;
V_4 -> V_137 = F_39 ;
V_4 -> V_138 = F_35 ;
V_4 -> V_139 = F_6 ;
V_4 -> V_140 = F_45 ;
V_4 -> V_141 = F_48 ;
V_3 = F_53 ( V_1 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_33 , V_3 ) ;
goto V_142;
}
V_6 -> V_143 = V_4 ;
V_3 = F_60 ( & V_1 -> V_4 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_34 , V_3 ) ;
goto V_144;
}
V_3 = F_61 ( & V_1 -> V_6 , V_124 , V_125 ) ;
if ( V_3 < 0 )
goto V_145;
return 0 ;
V_145:
F_62 ( & V_1 -> V_4 ) ;
V_144:
V_142:
V_127:
F_63 ( V_124 ) ;
F_64 ( V_10 ) ;
return V_3 ;
}
static void F_65 ( struct V_1 * V_1 )
{
struct V_4 * V_4 = & V_1 -> V_4 ;
F_10 ( & V_4 -> V_22 ) ;
F_66 ( & V_1 -> V_6 ) ;
F_62 ( & V_1 -> V_4 ) ;
F_55 ( V_1 ) ;
V_1 -> V_4 . V_8 = NULL ;
F_67 ( V_4 -> V_126 ) ;
F_63 ( V_1 -> V_6 . V_9 ) ;
F_64 ( V_1 -> V_6 . V_10 ) ;
F_14 ( & V_4 -> V_22 ) ;
}
static void F_68 ( struct V_1 * V_1 )
{
F_69 ( & V_1 -> V_6 ) ;
}
static int F_70 ( struct V_123 * V_9 ,
const struct V_146 * V_147 )
{
int V_3 ;
struct V_21 * V_21 ;
struct V_4 * V_4 ;
struct V_1 * V_1 ;
struct V_7 * V_8 = & V_9 -> V_8 ;
V_3 = - V_66 ;
V_21 = F_71 ( & V_148 , & V_9 -> V_8 , L_35 ) ;
if ( V_21 == NULL ) {
F_4 ( V_8 , L_36 ) ;
goto V_149;
}
V_21 -> V_150 = 1 ;
V_21 -> V_35 . V_151 = ~ 0 ;
V_4 = F_9 ( V_21 ) ;
V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
F_68 ( V_1 ) ;
V_3 = F_56 ( V_1 , V_9 , V_147 -> V_152 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_37 , V_3 ) ;
goto V_153;
}
V_3 = F_72 ( V_21 , 0 , 0 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_38 , V_3 ) ;
goto V_154;
}
V_3 = F_73 ( & V_1 -> V_4 ) ;
if ( V_3 < 0 ) {
F_4 ( V_8 , L_39 , V_3 ) ;
goto V_155;
}
return 0 ;
V_155:
F_74 ( V_21 ) ;
V_154:
F_65 ( V_1 ) ;
V_153:
F_75 ( V_21 ) ;
V_149:
return V_3 ;
}
static void F_76 ( struct V_123 * V_9 )
{
struct V_21 * V_21 ;
struct V_4 * V_4 ;
struct V_1 * V_1 ;
V_21 = F_77 ( V_9 ) ;
V_4 = F_9 ( V_21 ) ;
V_1 = F_7 ( V_4 , struct V_1 , V_4 ) ;
F_78 ( & V_1 -> V_4 ) ;
F_74 ( V_21 ) ;
F_65 ( V_1 ) ;
F_75 ( V_21 ) ;
}
