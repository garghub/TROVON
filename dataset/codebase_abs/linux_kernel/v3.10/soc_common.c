void F_1 ( struct V_1 * V_2 , const char * V_3 ,
int V_4 , const char * V_5 , ... )
{
struct V_6 V_7 ;
T_1 args ;
if ( V_8 > V_4 ) {
va_start ( args , V_5 ) ;
V_7 . V_5 = V_5 ;
V_7 . V_9 = & args ;
F_2 ( V_10 L_1 , V_2 -> V_11 , V_3 , & V_7 ) ;
va_end ( args ) ;
}
}
static unsigned short
F_3 ( unsigned short * V_12 , int V_13 , unsigned short V_14 )
{
unsigned short V_15 = 0 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_13 ; V_16 ++ )
if ( V_15 < V_12 [ V_16 ] )
V_15 = V_12 [ V_16 ] ;
if ( V_15 == 0 )
V_15 = V_14 ;
return V_15 ;
}
void F_4 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
V_18 -> V_19 =
F_3 ( V_2 -> V_20 , V_21 , V_22 ) ;
V_18 -> V_23 =
F_3 ( V_2 -> V_24 , V_25 , V_26 ) ;
V_18 -> V_27 =
F_3 ( V_2 -> V_28 , V_25 , V_26 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
unsigned int V_11 )
{
unsigned int V_16 ;
for ( V_16 = 0 ; V_16 < V_11 ; V_16 ++ ) {
if ( V_2 -> V_29 [ V_16 ] . V_30 )
F_6 ( V_2 -> V_29 [ V_16 ] . V_30 , V_2 ) ;
if ( F_7 ( V_2 -> V_29 [ V_16 ] . V_31 ) )
F_8 ( V_2 -> V_29 [ V_16 ] . V_31 ) ;
}
if ( V_2 -> V_32 -> V_33 )
V_2 -> V_32 -> V_33 ( V_2 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_5 ( V_2 , F_10 ( V_2 -> V_29 ) ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_34 = 0 , V_16 ;
if ( V_2 -> V_32 -> V_35 ) {
V_34 = V_2 -> V_32 -> V_35 ( V_2 ) ;
if ( V_34 )
return V_34 ;
}
for ( V_16 = 0 ; V_16 < F_10 ( V_2 -> V_29 ) ; V_16 ++ ) {
if ( F_7 ( V_2 -> V_29 [ V_16 ] . V_31 ) ) {
int V_30 ;
V_34 = F_12 ( V_2 -> V_29 [ V_16 ] . V_31 , V_36 ,
V_2 -> V_29 [ V_16 ] . V_37 ) ;
if ( V_34 ) {
F_5 ( V_2 , V_16 ) ;
return V_34 ;
}
V_30 = F_13 ( V_2 -> V_29 [ V_16 ] . V_31 ) ;
if ( V_16 == V_38 )
V_2 -> V_39 . V_40 = V_30 ;
else
V_2 -> V_29 [ V_16 ] . V_30 = V_30 ;
}
if ( V_2 -> V_29 [ V_16 ] . V_30 ) {
V_34 = F_14 ( V_2 -> V_29 [ V_16 ] . V_30 ,
V_41 ,
V_42 ,
V_2 -> V_29 [ V_16 ] . V_37 , V_2 ) ;
if ( V_34 ) {
if ( F_7 ( V_2 -> V_29 [ V_16 ] . V_31 ) )
F_8 ( V_2 -> V_29 [ V_16 ] . V_31 ) ;
F_5 ( V_2 , V_16 ) ;
return V_34 ;
}
}
}
return V_34 ;
}
static void F_15 ( struct V_1 * V_2 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < F_10 ( V_2 -> V_29 ) ; V_16 ++ )
if ( V_2 -> V_29 [ V_16 ] . V_30 ) {
F_16 ( V_2 -> V_29 [ V_16 ] . V_30 , V_43 ) ;
F_16 ( V_2 -> V_29 [ V_16 ] . V_30 , V_44 ) ;
}
}
static void F_17 ( struct V_1 * V_2 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < F_10 ( V_2 -> V_29 ) ; V_16 ++ )
if ( V_2 -> V_29 [ V_16 ] . V_30 )
F_16 ( V_2 -> V_29 [ V_16 ] . V_30 , V_45 ) ;
}
static unsigned int F_18 ( struct V_1 * V_2 )
{
struct V_46 V_47 ;
unsigned int V_29 ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_48 = 1 ;
V_47 . V_49 = 1 ;
if ( F_7 ( V_2 -> V_29 [ V_50 ] . V_31 ) )
V_47 . V_51 = ! F_19 ( V_2 -> V_29 [ V_50 ] . V_31 ) ;
if ( F_7 ( V_2 -> V_29 [ V_38 ] . V_31 ) )
V_47 . V_52 = ! ! F_19 ( V_2 -> V_29 [ V_38 ] . V_31 ) ;
if ( F_7 ( V_2 -> V_29 [ V_53 ] . V_31 ) )
V_47 . V_48 = ! ! F_19 ( V_2 -> V_29 [ V_53 ] . V_31 ) ;
if ( F_7 ( V_2 -> V_29 [ V_54 ] . V_31 ) )
V_47 . V_49 = ! ! F_19 ( V_2 -> V_29 [ V_54 ] . V_31 ) ;
V_2 -> V_32 -> V_55 ( V_2 , & V_47 ) ;
V_29 = V_47 . V_51 ? V_56 : 0 ;
V_29 |= V_47 . V_52 ? V_57 : 0 ;
V_29 |= V_47 . V_58 ? V_59 : 0 ;
V_29 |= V_47 . V_60 ? V_61 : 0 ;
V_29 |= V_47 . V_62 ? V_63 : 0 ;
V_29 |= V_2 -> V_64 . V_65 ? V_66 : 0 ;
if ( V_2 -> V_64 . V_67 & V_68 )
V_29 |= V_47 . V_48 ? V_69 : 0 ;
else {
if ( V_47 . V_48 == 0 )
V_29 |= V_70 ;
else if ( V_47 . V_49 == 0 )
V_29 |= V_71 ;
}
return V_29 ;
}
static int F_20 (
struct V_1 * V_2 , T_2 * V_47 )
{
int V_34 ;
V_34 = V_2 -> V_32 -> V_72 ( V_2 , V_47 ) ;
if ( V_34 == 0 ) {
if ( V_2 -> V_73 != 1 && V_47 -> V_74 ) {
V_2 -> V_73 = 1 ;
F_16 ( V_2 -> V_39 . V_40 ,
V_75 ) ;
} else if ( V_2 -> V_73 == 1 && V_47 -> V_74 == 0 ) {
V_2 -> V_73 = 0 ;
F_16 ( V_2 -> V_39 . V_40 , V_45 ) ;
}
V_2 -> V_64 = * V_47 ;
}
if ( V_34 < 0 )
F_2 ( V_76 L_2
L_3 , V_2 -> V_11 ) ;
return V_34 ;
}
static int F_21 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = F_22 ( V_78 ) ;
F_23 ( V_2 , 2 , L_4 ) ;
if ( V_2 -> V_32 -> V_79 )
V_2 -> V_32 -> V_79 ( V_2 ) ;
F_15 ( V_2 ) ;
return 0 ;
}
static int F_24 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = F_22 ( V_78 ) ;
F_23 ( V_2 , 2 , L_5 ) ;
F_17 ( V_2 ) ;
if ( V_2 -> V_32 -> V_80 )
V_2 -> V_32 -> V_80 ( V_2 ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
unsigned int V_81 ;
F_23 ( V_2 , 4 , L_6 ) ;
do {
unsigned int V_82 ;
unsigned long V_67 ;
V_82 = F_18 ( V_2 ) ;
F_26 ( & V_83 , V_67 ) ;
V_81 = ( V_82 ^ V_2 -> V_82 ) & V_2 -> V_64 . V_84 ;
V_2 -> V_82 = V_82 ;
F_27 ( & V_83 , V_67 ) ;
F_23 ( V_2 , 4 , L_7 ,
V_81 == 0 ? L_8 : L_9 ,
V_81 & V_56 ? L_10 : L_9 ,
V_81 & V_57 ? L_11 : L_9 ,
V_81 & V_70 ? L_12 : L_9 ,
V_81 & V_71 ? L_13 : L_9 ,
V_81 & V_69 ? L_14 : L_9 ) ;
if ( V_81 )
F_28 ( & V_2 -> V_39 , V_81 ) ;
} while ( V_81 );
}
static void F_29 ( unsigned long V_85 )
{
struct V_1 * V_2 = (struct V_1 * ) V_85 ;
F_23 ( V_2 , 4 , L_15 ) ;
F_30 ( & V_2 -> V_86 , V_87 + V_88 ) ;
F_25 ( V_2 ) ;
}
static T_3 V_41 ( int V_30 , void * V_89 )
{
struct V_1 * V_2 = V_89 ;
F_23 ( V_2 , 3 , L_16 , V_30 ) ;
F_25 ( V_2 ) ;
return V_90 ;
}
static int
F_31 ( struct V_77 * V_78 , unsigned int * V_82 )
{
struct V_1 * V_2 = F_22 ( V_78 ) ;
V_2 -> V_82 = F_18 ( V_2 ) ;
* V_82 = V_2 -> V_82 ;
return 0 ;
}
static int F_32 (
struct V_77 * V_78 , T_2 * V_47 )
{
struct V_1 * V_2 = F_22 ( V_78 ) ;
F_23 ( V_2 , 2 , L_17 ,
( V_47 -> V_84 == 0 ) ? L_18 : L_9 ,
( V_47 -> V_84 & V_56 ) ? L_10 : L_9 ,
( V_47 -> V_84 & V_57 ) ? L_11 : L_9 ,
( V_47 -> V_84 & V_70 ) ? L_12 : L_9 ,
( V_47 -> V_84 & V_71 ) ? L_13 : L_9 ,
( V_47 -> V_84 & V_69 ) ? L_14 : L_9 ,
( V_47 -> V_67 == 0 ) ? L_18 : L_9 ,
( V_47 -> V_67 & V_91 ) ? L_19 : L_9 ,
( V_47 -> V_67 & V_68 ) ? L_20 : L_9 ,
( V_47 -> V_67 & V_92 ) ? L_21 : L_9 ,
( V_47 -> V_67 & V_93 ) ? L_22 : L_9 ,
( V_47 -> V_67 & V_94 ) ? L_23 : L_9 ,
V_47 -> V_65 , V_47 -> V_95 , V_47 -> V_74 ) ;
return F_20 ( V_2 , V_47 ) ;
}
static int F_33 (
struct V_77 * V_78 , struct V_96 * V_97 )
{
struct V_1 * V_2 = F_22 ( V_78 ) ;
unsigned short V_15 = V_97 -> V_15 ;
F_23 ( V_2 , 2 , L_24 ,
V_97 -> V_97 , V_97 -> V_15 , ( unsigned long long ) V_97 -> V_98 ,
( unsigned long long ) V_97 -> V_99 ) ;
F_23 ( V_2 , 2 , L_25 ,
( V_97 -> V_67 == 0 ) ? L_8 : L_9 ,
( V_97 -> V_67 & V_100 ) ? L_26 : L_9 ,
( V_97 -> V_67 & V_101 ) ? L_27 : L_9 ,
( V_97 -> V_67 & V_102 ) ? L_28 : L_9 ,
( V_97 -> V_67 & V_103 ) ? L_29 : L_9 ,
( V_97 -> V_67 & V_104 ) ? L_30 : L_9 ,
( V_97 -> V_67 & V_105 ) ? L_31 : L_9 ,
( V_97 -> V_67 & V_106 ) ? L_32 : L_9 ) ;
if ( V_97 -> V_97 >= V_21 ) {
F_2 ( V_76 L_33 , V_107 ,
V_97 -> V_97 ) ;
return - 1 ;
}
if ( V_97 -> V_67 & V_100 ) {
if ( V_15 == 0 )
V_15 = V_22 ;
} else {
V_15 = 0 ;
}
V_2 -> V_20 [ V_97 -> V_97 ] = V_15 ;
V_2 -> V_32 -> V_108 ( V_2 ) ;
if ( V_97 -> V_99 == 1 )
V_97 -> V_99 = V_109 - 1 ;
V_97 -> V_99 -= V_97 -> V_98 ;
V_97 -> V_99 += V_2 -> V_39 . V_110 ;
V_97 -> V_98 = V_2 -> V_39 . V_110 ;
return 0 ;
}
static int F_34 (
struct V_77 * V_78 , struct V_111 * V_97 )
{
struct V_1 * V_2 = F_22 ( V_78 ) ;
struct V_112 * V_113 ;
unsigned short V_15 = V_97 -> V_15 ;
F_23 ( V_2 , 2 , L_34 ,
V_97 -> V_97 , V_97 -> V_15 , V_97 -> V_114 ) ;
F_23 ( V_2 , 2 , L_25 ,
( V_97 -> V_67 == 0 ) ? L_8 : L_9 ,
( V_97 -> V_67 & V_100 ) ? L_26 : L_9 ,
( V_97 -> V_67 & V_101 ) ? L_27 : L_9 ,
( V_97 -> V_67 & V_102 ) ? L_28 : L_9 ,
( V_97 -> V_67 & V_103 ) ? L_29 : L_9 ,
( V_97 -> V_67 & V_104 ) ? L_30 : L_9 ,
( V_97 -> V_67 & V_115 ) ? L_35 : L_9 ,
( V_97 -> V_67 & V_105 ) ? L_31 : L_9 ) ;
if ( V_97 -> V_97 >= V_25 )
return - V_116 ;
if ( V_97 -> V_67 & V_100 ) {
if ( V_15 == 0 )
V_15 = 300 ;
} else {
V_15 = 0 ;
}
if ( V_97 -> V_67 & V_115 ) {
V_113 = & V_2 -> V_117 ;
V_2 -> V_28 [ V_97 -> V_97 ] = V_15 ;
V_2 -> V_24 [ V_97 -> V_97 ] = 0 ;
} else {
V_113 = & V_2 -> V_118 ;
V_2 -> V_28 [ V_97 -> V_97 ] = 0 ;
V_2 -> V_24 [ V_97 -> V_97 ] = V_15 ;
}
V_2 -> V_32 -> V_108 ( V_2 ) ;
V_97 -> V_119 = V_113 -> V_98 + V_97 -> V_114 ;
return 0 ;
}
static void F_35 ( char * * V_120 , const char * V_121 ,
unsigned int V_122 , struct V_123 * V_124 , int V_125 )
{
char * V_126 = * V_120 ;
int V_16 ;
V_126 += sprintf ( V_126 , L_36 , V_121 ) ;
for ( V_16 = 0 ; V_16 < V_125 ; V_16 ++ )
if ( V_122 & V_124 [ V_16 ] . V_127 )
V_126 += sprintf ( V_126 , L_37 , V_124 [ V_16 ] . V_37 ) ;
* V_126 ++ = '\n' ;
* V_120 = V_126 ;
}
static T_4 F_36 (
struct V_128 * V_89 , struct V_129 * V_27 , char * V_130 )
{
struct V_1 * V_2 =
F_37 ( V_89 , struct V_1 , V_39 . V_89 ) ;
char * V_120 = V_130 ;
V_120 += sprintf ( V_120 , L_38 , V_2 -> V_11 ) ;
F_35 ( & V_120 , L_39 , V_2 -> V_82 ,
V_131 , F_10 ( V_131 ) ) ;
F_35 ( & V_120 , L_40 , V_2 -> V_64 . V_84 ,
V_131 , F_10 ( V_131 ) ) ;
F_35 ( & V_120 , L_41 , V_2 -> V_64 . V_67 ,
V_132 , F_10 ( V_132 ) ) ;
V_120 += sprintf ( V_120 , L_42 , V_2 -> V_64 . V_65 ) ;
V_120 += sprintf ( V_120 , L_43 , V_2 -> V_64 . V_95 ) ;
V_120 += sprintf ( V_120 , L_44 , V_2 -> V_64 . V_74 ,
V_2 -> V_39 . V_40 ) ;
if ( V_2 -> V_32 -> V_133 )
V_120 += V_2 -> V_32 -> V_133 ( V_2 , V_120 ) ;
return V_120 - V_130 ;
}
static int
F_38 ( struct V_134 * V_135 , unsigned long V_122 , void * V_136 )
{
struct V_1 * V_2 ;
struct V_137 * V_138 = V_136 ;
int V_34 = 0 ;
F_39 ( & V_139 ) ;
F_40 (skt, &soc_pcmcia_sockets, node)
if ( V_2 -> V_32 -> V_140 )
V_34 += V_2 -> V_32 -> V_140 ( V_2 , V_122 , V_138 ) ;
F_41 ( & V_139 ) ;
return V_34 ;
}
static int F_42 ( void )
{
int V_34 ;
V_34 = F_43 ( & V_141 ,
V_142 ) ;
if ( V_34 < 0 )
F_2 ( V_76 L_45
L_46 , V_34 ) ;
return V_34 ;
}
static void F_44 ( void )
{
F_45 ( & V_141 ,
V_142 ) ;
}
void F_46 ( struct V_1 * V_2 ,
struct V_143 * V_32 , struct V_128 * V_89 )
{
int V_16 ;
V_2 -> V_32 = V_32 ;
V_2 -> V_39 . V_144 = V_32 -> V_144 ;
V_2 -> V_39 . V_89 . V_145 = V_89 ;
V_2 -> V_39 . V_40 = V_146 ;
for ( V_16 = 0 ; V_16 < F_10 ( V_2 -> V_29 ) ; V_16 ++ )
V_2 -> V_29 [ V_16 ] . V_31 = - V_116 ;
}
void F_47 ( struct V_1 * V_2 )
{
F_39 ( & V_139 ) ;
F_48 ( & V_2 -> V_86 ) ;
F_49 ( & V_2 -> V_39 ) ;
F_9 ( V_2 ) ;
F_20 ( V_2 , & V_147 ) ;
F_50 ( & V_2 -> V_148 ) ;
F_41 ( & V_139 ) ;
F_51 ( V_2 -> V_149 ) ;
V_2 -> V_149 = NULL ;
F_52 ( & V_2 -> V_117 ) ;
F_52 ( & V_2 -> V_118 ) ;
F_52 ( & V_2 -> V_150 ) ;
F_52 ( & V_2 -> V_151 ) ;
}
int F_53 ( struct V_1 * V_2 )
{
int V_34 ;
F_54 ( & V_2 -> V_86 ) ;
V_2 -> V_86 . V_152 = F_29 ;
V_2 -> V_86 . V_136 = ( unsigned long ) V_2 ;
V_2 -> V_86 . V_153 = V_87 + V_88 ;
V_34 = F_55 ( & V_154 , & V_2 -> V_151 ) ;
if ( V_34 )
goto V_155;
V_34 = F_55 ( & V_2 -> V_151 , & V_2 -> V_150 ) ;
if ( V_34 )
goto V_156;
V_34 = F_55 ( & V_2 -> V_151 , & V_2 -> V_118 ) ;
if ( V_34 )
goto V_157;
V_34 = F_55 ( & V_2 -> V_151 , & V_2 -> V_117 ) ;
if ( V_34 )
goto V_158;
V_2 -> V_149 = F_56 ( V_2 -> V_150 . V_98 , 0x10000 ) ;
if ( V_2 -> V_149 == NULL ) {
V_34 = - V_159 ;
goto V_160;
}
F_39 ( & V_139 ) ;
F_57 ( & V_2 -> V_148 , & V_161 ) ;
V_2 -> V_32 -> V_108 ( V_2 ) ;
V_34 = F_11 ( V_2 ) ;
if ( V_34 )
goto V_162;
V_2 -> V_39 . V_32 = & V_163 ;
V_2 -> V_39 . V_164 = V_165 | V_166 ;
V_2 -> V_39 . V_167 = & V_168 ;
V_2 -> V_39 . V_169 = 0 ;
V_2 -> V_39 . V_170 = V_109 ;
V_2 -> V_39 . V_110 = ( unsigned long ) V_2 -> V_149 ;
V_2 -> V_82 = F_18 ( V_2 ) ;
V_34 = F_58 ( & V_2 -> V_39 ) ;
if ( V_34 )
goto V_171;
F_59 ( & V_2 -> V_86 ) ;
F_41 ( & V_139 ) ;
V_34 = F_60 ( & V_2 -> V_39 . V_89 , & V_172 ) ;
if ( V_34 )
goto V_173;
return V_34 ;
V_173:
F_39 ( & V_139 ) ;
F_48 ( & V_2 -> V_86 ) ;
F_49 ( & V_2 -> V_39 ) ;
V_171:
F_9 ( V_2 ) ;
V_162:
F_50 ( & V_2 -> V_148 ) ;
F_41 ( & V_139 ) ;
F_51 ( V_2 -> V_149 ) ;
V_160:
F_52 ( & V_2 -> V_117 ) ;
V_158:
F_52 ( & V_2 -> V_118 ) ;
V_157:
F_52 ( & V_2 -> V_150 ) ;
V_156:
F_52 ( & V_2 -> V_151 ) ;
V_155:
return V_34 ;
}
