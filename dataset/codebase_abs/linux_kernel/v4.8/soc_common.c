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
F_9 ( V_2 -> V_34 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_5 ( V_2 , F_11 ( V_2 -> V_29 ) ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_35 = 0 , V_16 ;
F_13 ( V_2 -> V_34 ) ;
if ( V_2 -> V_32 -> V_36 ) {
V_35 = V_2 -> V_32 -> V_36 ( V_2 ) ;
if ( V_35 )
return V_35 ;
}
for ( V_16 = 0 ; V_16 < F_11 ( V_2 -> V_29 ) ; V_16 ++ ) {
if ( F_7 ( V_2 -> V_29 [ V_16 ] . V_31 ) ) {
int V_30 ;
V_35 = F_14 ( V_2 -> V_29 [ V_16 ] . V_31 , V_37 ,
V_2 -> V_29 [ V_16 ] . V_38 ) ;
if ( V_35 ) {
F_5 ( V_2 , V_16 ) ;
return V_35 ;
}
V_30 = F_15 ( V_2 -> V_29 [ V_16 ] . V_31 ) ;
if ( V_16 == V_39 )
V_2 -> V_40 . V_41 = V_30 ;
else
V_2 -> V_29 [ V_16 ] . V_30 = V_30 ;
}
if ( V_2 -> V_29 [ V_16 ] . V_30 ) {
V_35 = F_16 ( V_2 -> V_29 [ V_16 ] . V_30 ,
V_42 ,
V_43 ,
V_2 -> V_29 [ V_16 ] . V_38 , V_2 ) ;
if ( V_35 ) {
if ( F_7 ( V_2 -> V_29 [ V_16 ] . V_31 ) )
F_8 ( V_2 -> V_29 [ V_16 ] . V_31 ) ;
F_5 ( V_2 , V_16 ) ;
return V_35 ;
}
}
}
return V_35 ;
}
static void F_17 ( struct V_1 * V_2 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < F_11 ( V_2 -> V_29 ) ; V_16 ++ )
if ( V_2 -> V_29 [ V_16 ] . V_30 ) {
F_18 ( V_2 -> V_29 [ V_16 ] . V_30 , V_44 ) ;
F_18 ( V_2 -> V_29 [ V_16 ] . V_30 , V_45 ) ;
}
}
static void F_19 ( struct V_1 * V_2 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < F_11 ( V_2 -> V_29 ) ; V_16 ++ )
if ( V_2 -> V_29 [ V_16 ] . V_30 )
F_18 ( V_2 -> V_29 [ V_16 ] . V_30 , V_46 ) ;
}
static unsigned int F_20 ( struct V_1 * V_2 )
{
struct V_47 V_48 ;
unsigned int V_29 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_49 = 1 ;
V_48 . V_50 = 1 ;
if ( F_7 ( V_2 -> V_29 [ V_51 ] . V_31 ) )
V_48 . V_52 = ! F_21 ( V_2 -> V_29 [ V_51 ] . V_31 ) ;
if ( F_7 ( V_2 -> V_29 [ V_39 ] . V_31 ) )
V_48 . V_53 = ! ! F_21 ( V_2 -> V_29 [ V_39 ] . V_31 ) ;
if ( F_7 ( V_2 -> V_29 [ V_54 ] . V_31 ) )
V_48 . V_49 = ! ! F_21 ( V_2 -> V_29 [ V_54 ] . V_31 ) ;
if ( F_7 ( V_2 -> V_29 [ V_55 ] . V_31 ) )
V_48 . V_50 = ! ! F_21 ( V_2 -> V_29 [ V_55 ] . V_31 ) ;
V_2 -> V_32 -> V_56 ( V_2 , & V_48 ) ;
V_29 = V_48 . V_52 ? V_57 : 0 ;
V_29 |= V_48 . V_53 ? V_58 : 0 ;
V_29 |= V_48 . V_59 ? V_60 : 0 ;
V_29 |= V_48 . V_61 ? V_62 : 0 ;
V_29 |= V_48 . V_63 ? V_64 : 0 ;
V_29 |= V_2 -> V_65 . V_66 ? V_67 : 0 ;
if ( V_2 -> V_65 . V_68 & V_69 )
V_29 |= V_48 . V_49 ? 0 : V_70 ;
else {
if ( V_48 . V_49 == 0 )
V_29 |= V_71 ;
else if ( V_48 . V_50 == 0 )
V_29 |= V_72 ;
}
return V_29 ;
}
static int F_22 (
struct V_1 * V_2 , T_2 * V_48 )
{
int V_35 ;
V_35 = V_2 -> V_32 -> V_73 ( V_2 , V_48 ) ;
if ( V_35 == 0 ) {
if ( V_2 -> V_74 != 1 && V_48 -> V_75 ) {
V_2 -> V_74 = 1 ;
F_18 ( V_2 -> V_40 . V_41 ,
V_76 ) ;
} else if ( V_2 -> V_74 == 1 && V_48 -> V_75 == 0 ) {
V_2 -> V_74 = 0 ;
F_18 ( V_2 -> V_40 . V_41 , V_46 ) ;
}
V_2 -> V_65 = * V_48 ;
}
if ( V_35 < 0 )
F_2 ( V_77 L_2
L_3 , V_2 -> V_11 ) ;
return V_35 ;
}
static int F_23 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_24 ( V_79 ) ;
F_25 ( V_2 , 2 , L_4 ) ;
if ( V_2 -> V_32 -> V_80 )
V_2 -> V_32 -> V_80 ( V_2 ) ;
F_17 ( V_2 ) ;
return 0 ;
}
static int F_26 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_24 ( V_79 ) ;
F_25 ( V_2 , 2 , L_5 ) ;
F_19 ( V_2 ) ;
if ( V_2 -> V_32 -> V_81 )
V_2 -> V_32 -> V_81 ( V_2 ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
unsigned int V_82 ;
F_25 ( V_2 , 4 , L_6 ) ;
do {
unsigned int V_83 ;
unsigned long V_68 ;
V_83 = F_20 ( V_2 ) ;
F_28 ( & V_84 , V_68 ) ;
V_82 = ( V_83 ^ V_2 -> V_83 ) & V_2 -> V_65 . V_85 ;
V_2 -> V_83 = V_83 ;
F_29 ( & V_84 , V_68 ) ;
F_25 ( V_2 , 4 , L_7 ,
V_82 == 0 ? L_8 : L_9 ,
V_82 & V_57 ? L_10 : L_9 ,
V_82 & V_58 ? L_11 : L_9 ,
V_82 & V_71 ? L_12 : L_9 ,
V_82 & V_72 ? L_13 : L_9 ,
V_82 & V_70 ? L_14 : L_9 ) ;
if ( V_82 )
F_30 ( & V_2 -> V_40 , V_82 ) ;
} while ( V_82 );
}
static void F_31 ( unsigned long V_86 )
{
struct V_1 * V_2 = (struct V_1 * ) V_86 ;
F_25 ( V_2 , 4 , L_15 ) ;
F_32 ( & V_2 -> V_87 , V_88 + V_89 ) ;
F_27 ( V_2 ) ;
}
static T_3 V_42 ( int V_30 , void * V_90 )
{
struct V_1 * V_2 = V_90 ;
F_25 ( V_2 , 3 , L_16 , V_30 ) ;
F_27 ( V_2 ) ;
return V_91 ;
}
static int
F_33 ( struct V_78 * V_79 , unsigned int * V_83 )
{
struct V_1 * V_2 = F_24 ( V_79 ) ;
V_2 -> V_83 = F_20 ( V_2 ) ;
* V_83 = V_2 -> V_83 ;
return 0 ;
}
static int F_34 (
struct V_78 * V_79 , T_2 * V_48 )
{
struct V_1 * V_2 = F_24 ( V_79 ) ;
F_25 ( V_2 , 2 , L_17 ,
( V_48 -> V_85 == 0 ) ? L_18 : L_9 ,
( V_48 -> V_85 & V_57 ) ? L_10 : L_9 ,
( V_48 -> V_85 & V_58 ) ? L_11 : L_9 ,
( V_48 -> V_85 & V_71 ) ? L_12 : L_9 ,
( V_48 -> V_85 & V_72 ) ? L_13 : L_9 ,
( V_48 -> V_85 & V_70 ) ? L_14 : L_9 ,
( V_48 -> V_68 == 0 ) ? L_18 : L_9 ,
( V_48 -> V_68 & V_92 ) ? L_19 : L_9 ,
( V_48 -> V_68 & V_69 ) ? L_20 : L_9 ,
( V_48 -> V_68 & V_93 ) ? L_21 : L_9 ,
( V_48 -> V_68 & V_94 ) ? L_22 : L_9 ,
( V_48 -> V_68 & V_95 ) ? L_23 : L_9 ,
V_48 -> V_66 , V_48 -> V_96 , V_48 -> V_75 ) ;
return F_22 ( V_2 , V_48 ) ;
}
static int F_35 (
struct V_78 * V_79 , struct V_97 * V_98 )
{
struct V_1 * V_2 = F_24 ( V_79 ) ;
unsigned short V_15 = V_98 -> V_15 ;
F_25 ( V_2 , 2 , L_24 ,
V_98 -> V_98 , V_98 -> V_15 , ( unsigned long long ) V_98 -> V_99 ,
( unsigned long long ) V_98 -> V_100 ) ;
F_25 ( V_2 , 2 , L_25 ,
( V_98 -> V_68 == 0 ) ? L_8 : L_9 ,
( V_98 -> V_68 & V_101 ) ? L_26 : L_9 ,
( V_98 -> V_68 & V_102 ) ? L_27 : L_9 ,
( V_98 -> V_68 & V_103 ) ? L_28 : L_9 ,
( V_98 -> V_68 & V_104 ) ? L_29 : L_9 ,
( V_98 -> V_68 & V_105 ) ? L_30 : L_9 ,
( V_98 -> V_68 & V_106 ) ? L_31 : L_9 ,
( V_98 -> V_68 & V_107 ) ? L_32 : L_9 ) ;
if ( V_98 -> V_98 >= V_21 ) {
F_2 ( V_77 L_33 , V_108 ,
V_98 -> V_98 ) ;
return - 1 ;
}
if ( V_98 -> V_68 & V_101 ) {
if ( V_15 == 0 )
V_15 = V_22 ;
} else {
V_15 = 0 ;
}
V_2 -> V_20 [ V_98 -> V_98 ] = V_15 ;
V_2 -> V_32 -> V_109 ( V_2 ) ;
if ( V_98 -> V_100 == 1 )
V_98 -> V_100 = V_110 - 1 ;
V_98 -> V_100 -= V_98 -> V_99 ;
V_98 -> V_100 += V_2 -> V_40 . V_111 ;
V_98 -> V_99 = V_2 -> V_40 . V_111 ;
return 0 ;
}
static int F_36 (
struct V_78 * V_79 , struct V_112 * V_98 )
{
struct V_1 * V_2 = F_24 ( V_79 ) ;
struct V_113 * V_114 ;
unsigned short V_15 = V_98 -> V_15 ;
F_25 ( V_2 , 2 , L_34 ,
V_98 -> V_98 , V_98 -> V_15 , V_98 -> V_115 ) ;
F_25 ( V_2 , 2 , L_25 ,
( V_98 -> V_68 == 0 ) ? L_8 : L_9 ,
( V_98 -> V_68 & V_101 ) ? L_26 : L_9 ,
( V_98 -> V_68 & V_102 ) ? L_27 : L_9 ,
( V_98 -> V_68 & V_103 ) ? L_28 : L_9 ,
( V_98 -> V_68 & V_104 ) ? L_29 : L_9 ,
( V_98 -> V_68 & V_105 ) ? L_30 : L_9 ,
( V_98 -> V_68 & V_116 ) ? L_35 : L_9 ,
( V_98 -> V_68 & V_106 ) ? L_31 : L_9 ) ;
if ( V_98 -> V_98 >= V_25 )
return - V_117 ;
if ( V_98 -> V_68 & V_101 ) {
if ( V_15 == 0 )
V_15 = 300 ;
} else {
V_15 = 0 ;
}
if ( V_98 -> V_68 & V_116 ) {
V_114 = & V_2 -> V_118 ;
V_2 -> V_28 [ V_98 -> V_98 ] = V_15 ;
V_2 -> V_24 [ V_98 -> V_98 ] = 0 ;
} else {
V_114 = & V_2 -> V_119 ;
V_2 -> V_28 [ V_98 -> V_98 ] = 0 ;
V_2 -> V_24 [ V_98 -> V_98 ] = V_15 ;
}
V_2 -> V_32 -> V_109 ( V_2 ) ;
V_98 -> V_120 = V_114 -> V_99 + V_98 -> V_115 ;
return 0 ;
}
static void F_37 ( char * * V_121 , const char * V_122 ,
unsigned int V_123 , struct V_124 * V_125 , int V_126 )
{
char * V_127 = * V_121 ;
int V_16 ;
V_127 += sprintf ( V_127 , L_36 , V_122 ) ;
for ( V_16 = 0 ; V_16 < V_126 ; V_16 ++ )
if ( V_123 & V_125 [ V_16 ] . V_128 )
V_127 += sprintf ( V_127 , L_37 , V_125 [ V_16 ] . V_38 ) ;
* V_127 ++ = '\n' ;
* V_121 = V_127 ;
}
static T_4 F_38 (
struct V_129 * V_90 , struct V_130 * V_27 , char * V_131 )
{
struct V_1 * V_2 =
F_39 ( V_90 , struct V_1 , V_40 . V_90 ) ;
char * V_121 = V_131 ;
V_121 += sprintf ( V_121 , L_38 , V_2 -> V_11 ) ;
F_37 ( & V_121 , L_39 , V_2 -> V_83 ,
V_132 , F_11 ( V_132 ) ) ;
F_37 ( & V_121 , L_40 , V_2 -> V_65 . V_85 ,
V_132 , F_11 ( V_132 ) ) ;
F_37 ( & V_121 , L_41 , V_2 -> V_65 . V_68 ,
V_133 , F_11 ( V_133 ) ) ;
V_121 += sprintf ( V_121 , L_42 , V_2 -> V_65 . V_66 ) ;
V_121 += sprintf ( V_121 , L_43 , V_2 -> V_65 . V_96 ) ;
V_121 += sprintf ( V_121 , L_44 , V_2 -> V_65 . V_75 ,
V_2 -> V_40 . V_41 ) ;
if ( V_2 -> V_32 -> V_134 )
V_121 += V_2 -> V_32 -> V_134 ( V_2 , V_121 ) ;
return V_121 - V_131 ;
}
static int
F_40 ( struct V_135 * V_136 , unsigned long V_123 , void * V_137 )
{
struct V_1 * V_2 ;
struct V_138 * V_139 = V_137 ;
int V_35 = 0 ;
F_41 ( & V_140 ) ;
F_42 (skt, &soc_pcmcia_sockets, node)
if ( V_2 -> V_32 -> V_141 )
V_35 += V_2 -> V_32 -> V_141 ( V_2 , V_123 , V_139 ) ;
F_43 ( & V_140 ) ;
return V_35 ;
}
static int F_44 ( void )
{
int V_35 ;
V_35 = F_45 ( & V_142 ,
V_143 ) ;
if ( V_35 < 0 )
F_2 ( V_77 L_45
L_46 , V_35 ) ;
return V_35 ;
}
static void F_46 ( void )
{
F_47 ( & V_142 ,
V_143 ) ;
}
void F_48 ( struct V_1 * V_2 ,
struct V_144 * V_32 , struct V_129 * V_90 )
{
int V_16 ;
V_2 -> V_32 = V_32 ;
V_2 -> V_40 . V_145 = V_32 -> V_145 ;
V_2 -> V_40 . V_90 . V_146 = V_90 ;
V_2 -> V_40 . V_41 = V_147 ;
for ( V_16 = 0 ; V_16 < F_11 ( V_2 -> V_29 ) ; V_16 ++ )
V_2 -> V_29 [ V_16 ] . V_31 = - V_117 ;
}
void F_49 ( struct V_1 * V_2 )
{
F_41 ( & V_140 ) ;
F_50 ( & V_2 -> V_87 ) ;
F_51 ( & V_2 -> V_40 ) ;
F_10 ( V_2 ) ;
F_22 ( V_2 , & V_148 ) ;
F_52 ( & V_2 -> V_149 ) ;
F_43 ( & V_140 ) ;
F_53 ( V_2 -> V_150 ) ;
V_2 -> V_150 = NULL ;
F_54 ( & V_2 -> V_118 ) ;
F_54 ( & V_2 -> V_119 ) ;
F_54 ( & V_2 -> V_151 ) ;
F_54 ( & V_2 -> V_152 ) ;
}
int F_55 ( struct V_1 * V_2 )
{
int V_35 ;
F_56 ( & V_2 -> V_87 , F_31 ,
( unsigned long ) V_2 ) ;
V_2 -> V_87 . V_153 = V_88 + V_89 ;
V_35 = F_57 ( & V_154 , & V_2 -> V_152 ) ;
if ( V_35 )
goto V_155;
V_35 = F_57 ( & V_2 -> V_152 , & V_2 -> V_151 ) ;
if ( V_35 )
goto V_156;
V_35 = F_57 ( & V_2 -> V_152 , & V_2 -> V_119 ) ;
if ( V_35 )
goto V_157;
V_35 = F_57 ( & V_2 -> V_152 , & V_2 -> V_118 ) ;
if ( V_35 )
goto V_158;
V_2 -> V_150 = F_58 ( V_2 -> V_151 . V_99 , 0x10000 ) ;
if ( V_2 -> V_150 == NULL ) {
V_35 = - V_159 ;
goto V_160;
}
F_41 ( & V_140 ) ;
F_59 ( & V_2 -> V_149 , & V_161 ) ;
V_2 -> V_32 -> V_109 ( V_2 ) ;
V_35 = F_12 ( V_2 ) ;
if ( V_35 )
goto V_162;
V_2 -> V_40 . V_32 = & V_163 ;
V_2 -> V_40 . V_164 = V_165 | V_166 ;
V_2 -> V_40 . V_167 = & V_168 ;
V_2 -> V_40 . V_169 = 0 ;
V_2 -> V_40 . V_170 = V_110 ;
V_2 -> V_40 . V_111 = ( unsigned long ) V_2 -> V_150 ;
V_2 -> V_83 = F_20 ( V_2 ) ;
V_35 = F_60 ( & V_2 -> V_40 ) ;
if ( V_35 )
goto V_171;
F_61 ( & V_2 -> V_87 ) ;
F_43 ( & V_140 ) ;
V_35 = F_62 ( & V_2 -> V_40 . V_90 , & V_172 ) ;
if ( V_35 )
goto V_173;
return V_35 ;
V_173:
F_41 ( & V_140 ) ;
F_50 ( & V_2 -> V_87 ) ;
F_51 ( & V_2 -> V_40 ) ;
V_171:
F_10 ( V_2 ) ;
V_162:
F_52 ( & V_2 -> V_149 ) ;
F_43 ( & V_140 ) ;
F_53 ( V_2 -> V_150 ) ;
V_160:
F_54 ( & V_2 -> V_118 ) ;
V_158:
F_54 ( & V_2 -> V_119 ) ;
V_157:
F_54 ( & V_2 -> V_151 ) ;
V_156:
F_54 ( & V_2 -> V_152 ) ;
V_155:
return V_35 ;
}
