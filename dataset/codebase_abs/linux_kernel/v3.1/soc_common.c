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
static unsigned int F_5 ( struct V_1 * V_2 )
{
struct V_29 V_30 ;
unsigned int V_31 ;
memset ( & V_30 , 0 , sizeof( struct V_29 ) ) ;
V_2 -> V_32 -> V_33 ( V_2 , & V_30 ) ;
V_31 = V_30 . V_34 ? V_35 : 0 ;
V_31 |= V_30 . V_36 ? V_37 : 0 ;
V_31 |= V_30 . V_38 ? V_39 : 0 ;
V_31 |= V_30 . V_40 ? V_41 : 0 ;
V_31 |= V_30 . V_42 ? V_43 : 0 ;
V_31 |= V_2 -> V_44 . V_45 ? V_46 : 0 ;
if ( V_2 -> V_44 . V_47 & V_48 )
V_31 |= V_30 . V_49 ? V_50 : 0 ;
else {
if ( V_30 . V_49 == 0 )
V_31 |= V_51 ;
else if ( V_30 . V_52 == 0 )
V_31 |= V_53 ;
}
return V_31 ;
}
static int F_6 (
struct V_1 * V_2 , T_2 * V_30 )
{
int V_54 ;
V_54 = V_2 -> V_32 -> V_55 ( V_2 , V_30 ) ;
if ( V_54 == 0 ) {
if ( V_2 -> V_56 != 1 && V_30 -> V_57 ) {
V_2 -> V_56 = 1 ;
F_7 ( V_2 -> V_58 . V_59 ,
V_60 ) ;
} else if ( V_2 -> V_56 == 1 && V_30 -> V_57 == 0 ) {
V_2 -> V_56 = 0 ;
F_7 ( V_2 -> V_58 . V_59 , V_61 ) ;
}
V_2 -> V_44 = * V_30 ;
}
if ( V_54 < 0 )
F_2 ( V_62 L_2
L_3 , V_2 -> V_11 ) ;
return V_54 ;
}
static int F_8 ( struct V_63 * V_64 )
{
struct V_1 * V_2 = F_9 ( V_64 ) ;
F_10 ( V_2 , 2 , L_4 ) ;
if ( V_2 -> V_32 -> V_65 )
V_2 -> V_32 -> V_65 ( V_2 ) ;
return 0 ;
}
static int F_11 ( struct V_63 * V_64 )
{
struct V_1 * V_2 = F_9 ( V_64 ) ;
F_10 ( V_2 , 2 , L_5 ) ;
if ( V_2 -> V_32 -> V_66 )
V_2 -> V_32 -> V_66 ( V_2 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
unsigned int V_67 ;
F_10 ( V_2 , 4 , L_6 ) ;
do {
unsigned int V_68 ;
unsigned long V_47 ;
V_68 = F_5 ( V_2 ) ;
F_13 ( & V_69 , V_47 ) ;
V_67 = ( V_68 ^ V_2 -> V_68 ) & V_2 -> V_44 . V_70 ;
V_2 -> V_68 = V_68 ;
F_14 ( & V_69 , V_47 ) ;
F_10 ( V_2 , 4 , L_7 ,
V_67 == 0 ? L_8 : L_9 ,
V_67 & V_35 ? L_10 : L_9 ,
V_67 & V_37 ? L_11 : L_9 ,
V_67 & V_51 ? L_12 : L_9 ,
V_67 & V_53 ? L_13 : L_9 ,
V_67 & V_50 ? L_14 : L_9 ) ;
if ( V_67 )
F_15 ( & V_2 -> V_58 , V_67 ) ;
} while ( V_67 );
}
static void F_16 ( unsigned long V_71 )
{
struct V_1 * V_2 = (struct V_1 * ) V_71 ;
F_10 ( V_2 , 4 , L_15 ) ;
F_17 ( & V_2 -> V_72 , V_73 + V_74 ) ;
F_12 ( V_2 ) ;
}
static T_3 F_18 ( int V_75 , void * V_76 )
{
struct V_1 * V_2 = V_76 ;
F_10 ( V_2 , 3 , L_16 , V_75 ) ;
F_12 ( V_2 ) ;
return V_77 ;
}
static int
F_19 ( struct V_63 * V_64 , unsigned int * V_68 )
{
struct V_1 * V_2 = F_9 ( V_64 ) ;
V_2 -> V_68 = F_5 ( V_2 ) ;
* V_68 = V_2 -> V_68 ;
return 0 ;
}
static int F_20 (
struct V_63 * V_64 , T_2 * V_30 )
{
struct V_1 * V_2 = F_9 ( V_64 ) ;
F_10 ( V_2 , 2 , L_17 ,
( V_30 -> V_70 == 0 ) ? L_18 : L_9 ,
( V_30 -> V_70 & V_35 ) ? L_10 : L_9 ,
( V_30 -> V_70 & V_37 ) ? L_11 : L_9 ,
( V_30 -> V_70 & V_51 ) ? L_12 : L_9 ,
( V_30 -> V_70 & V_53 ) ? L_13 : L_9 ,
( V_30 -> V_70 & V_50 ) ? L_14 : L_9 ,
( V_30 -> V_47 == 0 ) ? L_18 : L_9 ,
( V_30 -> V_47 & V_78 ) ? L_19 : L_9 ,
( V_30 -> V_47 & V_48 ) ? L_20 : L_9 ,
( V_30 -> V_47 & V_79 ) ? L_21 : L_9 ,
( V_30 -> V_47 & V_80 ) ? L_22 : L_9 ,
( V_30 -> V_47 & V_81 ) ? L_23 : L_9 ,
V_30 -> V_45 , V_30 -> V_82 , V_30 -> V_57 ) ;
return F_6 ( V_2 , V_30 ) ;
}
static int F_21 (
struct V_63 * V_64 , struct V_83 * V_84 )
{
struct V_1 * V_2 = F_9 ( V_64 ) ;
unsigned short V_15 = V_84 -> V_15 ;
F_10 ( V_2 , 2 , L_24 ,
V_84 -> V_84 , V_84 -> V_15 , ( unsigned long long ) V_84 -> V_85 ,
( unsigned long long ) V_84 -> V_86 ) ;
F_10 ( V_2 , 2 , L_25 ,
( V_84 -> V_47 == 0 ) ? L_8 : L_9 ,
( V_84 -> V_47 & V_87 ) ? L_26 : L_9 ,
( V_84 -> V_47 & V_88 ) ? L_27 : L_9 ,
( V_84 -> V_47 & V_89 ) ? L_28 : L_9 ,
( V_84 -> V_47 & V_90 ) ? L_29 : L_9 ,
( V_84 -> V_47 & V_91 ) ? L_30 : L_9 ,
( V_84 -> V_47 & V_92 ) ? L_31 : L_9 ,
( V_84 -> V_47 & V_93 ) ? L_32 : L_9 ) ;
if ( V_84 -> V_84 >= V_21 ) {
F_2 ( V_62 L_33 , V_94 ,
V_84 -> V_84 ) ;
return - 1 ;
}
if ( V_84 -> V_47 & V_87 ) {
if ( V_15 == 0 )
V_15 = V_22 ;
} else {
V_15 = 0 ;
}
V_2 -> V_20 [ V_84 -> V_84 ] = V_15 ;
V_2 -> V_32 -> V_95 ( V_2 ) ;
if ( V_84 -> V_86 == 1 )
V_84 -> V_86 = V_96 - 1 ;
V_84 -> V_86 -= V_84 -> V_85 ;
V_84 -> V_86 += V_2 -> V_58 . V_97 ;
V_84 -> V_85 = V_2 -> V_58 . V_97 ;
return 0 ;
}
static int F_22 (
struct V_63 * V_64 , struct V_98 * V_84 )
{
struct V_1 * V_2 = F_9 ( V_64 ) ;
struct V_99 * V_100 ;
unsigned short V_15 = V_84 -> V_15 ;
F_10 ( V_2 , 2 , L_34 ,
V_84 -> V_84 , V_84 -> V_15 , V_84 -> V_101 ) ;
F_10 ( V_2 , 2 , L_25 ,
( V_84 -> V_47 == 0 ) ? L_8 : L_9 ,
( V_84 -> V_47 & V_87 ) ? L_26 : L_9 ,
( V_84 -> V_47 & V_88 ) ? L_27 : L_9 ,
( V_84 -> V_47 & V_89 ) ? L_28 : L_9 ,
( V_84 -> V_47 & V_90 ) ? L_29 : L_9 ,
( V_84 -> V_47 & V_91 ) ? L_30 : L_9 ,
( V_84 -> V_47 & V_102 ) ? L_35 : L_9 ,
( V_84 -> V_47 & V_92 ) ? L_31 : L_9 ) ;
if ( V_84 -> V_84 >= V_25 )
return - V_103 ;
if ( V_84 -> V_47 & V_87 ) {
if ( V_15 == 0 )
V_15 = 300 ;
} else {
V_15 = 0 ;
}
if ( V_84 -> V_47 & V_102 ) {
V_100 = & V_2 -> V_104 ;
V_2 -> V_28 [ V_84 -> V_84 ] = V_15 ;
V_2 -> V_24 [ V_84 -> V_84 ] = 0 ;
} else {
V_100 = & V_2 -> V_105 ;
V_2 -> V_28 [ V_84 -> V_84 ] = 0 ;
V_2 -> V_24 [ V_84 -> V_84 ] = V_15 ;
}
V_2 -> V_32 -> V_95 ( V_2 ) ;
V_84 -> V_106 = V_100 -> V_85 + V_84 -> V_101 ;
return 0 ;
}
static void F_23 ( char * * V_107 , const char * V_108 ,
unsigned int V_109 , struct V_110 * V_111 , int V_112 )
{
char * V_113 = * V_107 ;
int V_16 ;
V_113 += sprintf ( V_113 , L_36 , V_108 ) ;
for ( V_16 = 0 ; V_16 < V_112 ; V_16 ++ )
if ( V_109 & V_111 [ V_16 ] . V_114 )
V_113 += sprintf ( V_113 , L_37 , V_111 [ V_16 ] . V_115 ) ;
* V_113 ++ = '\n' ;
* V_107 = V_113 ;
}
static T_4 F_24 (
struct V_116 * V_76 , struct V_117 * V_27 , char * V_118 )
{
struct V_1 * V_2 =
F_25 ( V_76 , struct V_1 , V_58 . V_76 ) ;
char * V_107 = V_118 ;
V_107 += sprintf ( V_107 , L_38 , V_2 -> V_11 ) ;
F_23 ( & V_107 , L_39 , V_2 -> V_68 ,
V_119 , F_26 ( V_119 ) ) ;
F_23 ( & V_107 , L_40 , V_2 -> V_44 . V_70 ,
V_119 , F_26 ( V_119 ) ) ;
F_23 ( & V_107 , L_41 , V_2 -> V_44 . V_47 ,
V_120 , F_26 ( V_120 ) ) ;
V_107 += sprintf ( V_107 , L_42 , V_2 -> V_44 . V_45 ) ;
V_107 += sprintf ( V_107 , L_43 , V_2 -> V_44 . V_82 ) ;
V_107 += sprintf ( V_107 , L_44 , V_2 -> V_44 . V_57 ,
V_2 -> V_58 . V_59 ) ;
if ( V_2 -> V_32 -> V_121 )
V_107 += V_2 -> V_32 -> V_121 ( V_2 , V_107 ) ;
return V_107 - V_118 ;
}
int F_27 ( struct V_1 * V_2 ,
struct V_122 * V_123 , int V_11 )
{
int V_16 , V_100 = 0 ;
for ( V_16 = 0 ; V_16 < V_11 ; V_16 ++ ) {
if ( V_123 [ V_16 ] . V_64 != V_2 -> V_11 )
continue;
V_100 = F_28 ( V_123 [ V_16 ] . V_75 , F_18 ,
V_124 , V_123 [ V_16 ] . V_125 , V_2 ) ;
if ( V_100 )
break;
F_7 ( V_123 [ V_16 ] . V_75 , V_61 ) ;
}
if ( V_100 ) {
F_2 ( V_62 L_45 ,
V_123 [ V_16 ] . V_75 , V_100 ) ;
while ( V_16 -- )
if ( V_123 [ V_16 ] . V_64 == V_2 -> V_11 )
F_29 ( V_123 [ V_16 ] . V_75 , V_2 ) ;
}
return V_100 ;
}
void F_30 ( struct V_1 * V_2 ,
struct V_122 * V_123 , int V_11 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_11 ; V_16 ++ )
if ( V_123 [ V_16 ] . V_64 == V_2 -> V_11 )
F_29 ( V_123 [ V_16 ] . V_75 , V_2 ) ;
}
void F_31 ( struct V_1 * V_2 ,
struct V_122 * V_123 , int V_11 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_11 ; V_16 ++ )
if ( V_123 [ V_16 ] . V_64 == V_2 -> V_11 )
F_7 ( V_123 [ V_16 ] . V_75 , V_61 ) ;
}
void F_32 ( struct V_1 * V_2 ,
struct V_122 * V_123 , int V_11 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_11 ; V_16 ++ )
if ( V_123 [ V_16 ] . V_64 == V_2 -> V_11 ) {
F_7 ( V_123 [ V_16 ] . V_75 , V_126 ) ;
F_7 ( V_123 [ V_16 ] . V_75 , V_127 ) ;
}
}
static int
F_33 ( struct V_128 * V_129 , unsigned long V_109 , void * V_130 )
{
struct V_1 * V_2 ;
struct V_131 * V_132 = V_130 ;
int V_54 = 0 ;
F_34 ( & V_133 ) ;
F_35 (skt, &soc_pcmcia_sockets, node)
if ( V_2 -> V_32 -> V_134 )
V_54 += V_2 -> V_32 -> V_134 ( V_2 , V_109 , V_132 ) ;
F_36 ( & V_133 ) ;
return V_54 ;
}
static int F_37 ( void )
{
int V_54 ;
V_54 = F_38 ( & V_135 ,
V_136 ) ;
if ( V_54 < 0 )
F_2 ( V_62 L_46
L_47 , V_54 ) ;
return V_54 ;
}
static void F_39 ( void )
{
F_40 ( & V_135 ,
V_136 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
F_34 ( & V_133 ) ;
F_42 ( & V_2 -> V_72 ) ;
F_43 ( & V_2 -> V_58 ) ;
V_2 -> V_32 -> V_137 ( V_2 ) ;
F_6 ( V_2 , & V_138 ) ;
F_44 ( & V_2 -> V_139 ) ;
F_36 ( & V_133 ) ;
F_45 ( V_2 -> V_140 ) ;
V_2 -> V_140 = NULL ;
F_46 ( & V_2 -> V_104 ) ;
F_46 ( & V_2 -> V_105 ) ;
F_46 ( & V_2 -> V_141 ) ;
F_46 ( & V_2 -> V_142 ) ;
}
int F_47 ( struct V_1 * V_2 )
{
int V_54 ;
F_48 ( & V_2 -> V_72 ) ;
V_2 -> V_72 . V_143 = F_16 ;
V_2 -> V_72 . V_130 = ( unsigned long ) V_2 ;
V_2 -> V_72 . V_144 = V_73 + V_74 ;
V_54 = F_49 ( & V_145 , & V_2 -> V_142 ) ;
if ( V_54 )
goto V_146;
V_54 = F_49 ( & V_2 -> V_142 , & V_2 -> V_141 ) ;
if ( V_54 )
goto V_147;
V_54 = F_49 ( & V_2 -> V_142 , & V_2 -> V_105 ) ;
if ( V_54 )
goto V_148;
V_54 = F_49 ( & V_2 -> V_142 , & V_2 -> V_104 ) ;
if ( V_54 )
goto V_149;
V_2 -> V_140 = F_50 ( V_2 -> V_141 . V_85 , 0x10000 ) ;
if ( V_2 -> V_140 == NULL ) {
V_54 = - V_150 ;
goto V_151;
}
F_34 ( & V_133 ) ;
F_51 ( & V_2 -> V_139 , & V_152 ) ;
V_2 -> V_32 -> V_95 ( V_2 ) ;
V_54 = V_2 -> V_32 -> V_153 ( V_2 ) ;
if ( V_54 )
goto V_154;
V_2 -> V_58 . V_32 = & V_155 ;
V_2 -> V_58 . V_156 = V_157 | V_158 ;
V_2 -> V_58 . V_159 = & V_160 ;
V_2 -> V_58 . V_161 = 0 ;
V_2 -> V_58 . V_162 = V_96 ;
V_2 -> V_58 . V_97 = ( unsigned long ) V_2 -> V_140 ;
V_2 -> V_68 = F_5 ( V_2 ) ;
V_54 = F_52 ( & V_2 -> V_58 ) ;
if ( V_54 )
goto V_163;
F_53 ( & V_2 -> V_72 ) ;
F_36 ( & V_133 ) ;
V_54 = F_54 ( & V_2 -> V_58 . V_76 , & V_164 ) ;
if ( V_54 )
goto V_165;
return V_54 ;
V_165:
F_34 ( & V_133 ) ;
F_42 ( & V_2 -> V_72 ) ;
F_43 ( & V_2 -> V_58 ) ;
V_163:
V_2 -> V_32 -> V_137 ( V_2 ) ;
V_154:
F_44 ( & V_2 -> V_139 ) ;
F_36 ( & V_133 ) ;
F_45 ( V_2 -> V_140 ) ;
V_151:
F_46 ( & V_2 -> V_104 ) ;
V_149:
F_46 ( & V_2 -> V_105 ) ;
V_148:
F_46 ( & V_2 -> V_141 ) ;
V_147:
F_46 ( & V_2 -> V_142 ) ;
V_146:
return V_54 ;
}
