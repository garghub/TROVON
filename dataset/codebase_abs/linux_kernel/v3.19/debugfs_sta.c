static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_5 [ 121 ] ;
struct V_6 * V_7 = V_1 -> V_8 ;
#define F_2 ( T_5 ) \
test_sta_flag(sta, WLAN_STA_##flg) ? #flg "\n" : ""
int V_9 = F_3 ( V_5 , sizeof( V_5 ) ,
L_1 ,
F_2 ( V_10 ) , F_2 ( V_11 ) , F_2 ( V_12 ) ,
F_2 ( V_13 ) , F_2 ( V_14 ) ,
F_2 ( V_15 ) ,
V_7 -> V_7 . V_16 ? L_2 : L_3 ,
F_2 ( V_17 ) , F_2 ( V_18 ) ,
F_2 ( V_19 ) , F_2 ( V_20 ) , F_2 ( V_21 ) ,
F_2 ( V_22 ) , F_2 ( V_23 ) , F_2 ( V_24 ) ,
F_2 ( V_25 ) , F_2 ( V_26 ) ,
F_2 ( V_27 ) , F_2 ( V_28 ) ,
F_2 ( 4ADDR_EVENT ) , F_2 ( V_29 ) ,
F_2 ( V_30 ) , F_2 ( V_31 ) ,
F_2 ( V_32 ) , F_2 ( V_33 ) ) ;
#undef F_2
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_9 ) ;
}
static T_1 F_5 ( struct V_1 * V_1 ,
char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
char V_5 [ 17 * V_34 ] , * V_35 = V_5 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_34 ; V_36 ++ )
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_4 , V_36 ,
F_6 ( & V_7 -> V_37 [ V_36 ] ) +
F_6 ( & V_7 -> V_38 [ V_36 ] ) ) ;
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_35 - V_5 ) ;
}
static T_1 F_7 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
return F_8 ( V_2 , V_3 , V_4 , L_5 ,
F_9 ( V_39 - V_7 -> V_40 ) ) ;
}
static T_1 F_10 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
struct V_41 V_42 ;
struct V_43 V_44 ;
long V_45 ;
char V_5 [ 100 ] ;
int V_9 ;
F_11 ( & V_42 ) ;
V_45 = V_42 . V_46 - V_7 -> V_47 ;
F_12 ( V_45 , 0 , & V_44 ) ;
V_44 . V_48 -= 70 ;
V_44 . V_49 -= 1 ;
V_9 = F_3 ( V_5 , sizeof( V_5 ) ,
L_6 ,
V_44 . V_48 , V_44 . V_50 , V_44 . V_49 ,
V_44 . V_51 , V_44 . V_52 , V_44 . V_53 ) ;
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_9 ) ;
}
static T_1 F_13 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_5 [ 15 * V_54 ] , * V_35 = V_5 ;
int V_55 ;
struct V_6 * V_7 = V_1 -> V_8 ;
for ( V_55 = 0 ; V_55 < V_54 ; V_55 ++ )
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_7 ,
F_14 ( V_7 -> V_56 [ V_55 ] ) ) ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_8 ) ;
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_35 - V_5 ) ;
}
static T_1 F_15 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_5 [ 71 + V_54 * 40 ] , * V_35 = V_5 ;
int V_55 ;
struct V_6 * V_7 = V_1 -> V_8 ;
struct V_57 * V_58 ;
struct V_59 * V_60 ;
F_16 () ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_9 ,
V_7 -> V_61 . V_62 + 1 ) ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 ,
L_10 ) ;
for ( V_55 = 0 ; V_55 < V_54 ; V_55 ++ ) {
V_58 = F_17 ( V_7 -> V_61 . V_58 [ V_55 ] ) ;
V_60 = F_17 ( V_7 -> V_61 . V_60 [ V_55 ] ) ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_11 , V_55 ) ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_12 , ! ! V_58 ) ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_13 ,
V_58 ? V_58 -> V_63 : 0 ) ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_14 ,
V_58 ? V_58 -> V_64 : 0 ) ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_12 , ! ! V_60 ) ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_13 ,
V_60 ? V_60 -> V_63 : 0 ) ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_15 ,
V_60 ? F_6 ( & V_60 -> V_65 ) : 0 ) ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_8 ) ;
}
F_18 () ;
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_35 - V_5 ) ;
}
static T_1 F_19 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_66 [ 12 ] = {} , * V_5 = V_66 ;
struct V_6 * V_7 = V_1 -> V_8 ;
bool V_67 , V_68 ;
unsigned long V_69 ;
int V_70 ;
if ( V_3 > sizeof( V_66 ) )
return - V_71 ;
if ( F_20 ( V_5 , V_2 , V_3 ) )
return - V_72 ;
V_5 [ sizeof( V_66 ) - 1 ] = '\0' ;
if ( strncmp ( V_5 , L_16 , 3 ) == 0 ) {
V_5 += 3 ;
V_68 = true ;
} else if ( strncmp ( V_5 , L_17 , 3 ) == 0 ) {
V_5 += 3 ;
V_68 = false ;
} else
return - V_71 ;
if ( strncmp ( V_5 , L_18 , 6 ) == 0 ) {
V_5 += 6 ;
V_67 = true ;
if ( ! V_68 )
return - V_71 ;
} else if ( strncmp ( V_5 , L_19 , 5 ) == 0 ) {
V_5 += 5 ;
V_67 = false ;
} else
return - V_71 ;
V_70 = F_21 ( V_5 , 0 , & V_69 ) ;
if ( V_70 )
return V_70 ;
if ( V_69 >= V_54 )
return - V_71 ;
if ( V_68 ) {
if ( V_67 )
V_70 = F_22 ( & V_7 -> V_7 , V_69 , 5000 ) ;
else
V_70 = F_23 ( & V_7 -> V_7 , V_69 ) ;
} else {
F_24 ( V_7 , V_69 , V_73 ,
3 , true ) ;
V_70 = 0 ;
}
return V_70 ? : V_3 ;
}
static T_1 F_25 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
#define F_26 ( T_6 , T_7 ) \
do { \
if (_cond) \
p += scnprintf(p, sizeof(buf)+buf-p, "\t" _str "\n"); \
} while (0)
char V_5 [ 512 ] , * V_35 = V_5 ;
int V_55 ;
struct V_6 * V_7 = V_1 -> V_8 ;
struct V_74 * V_75 = & V_7 -> V_7 . V_76 ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_20 ,
V_75 -> V_77 ? L_3 : L_21 ) ;
if ( V_75 -> V_77 ) {
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_22 , V_75 -> V_78 ) ;
F_26 ( ( V_75 -> V_78 & F_27 ( 0 ) ) , L_23 ) ;
F_26 ( ( V_75 -> V_78 & F_27 ( 1 ) ) , L_24 ) ;
F_26 ( ! ( V_75 -> V_78 & F_27 ( 1 ) ) , L_25 ) ;
F_26 ( ( ( V_75 -> V_78 >> 2 ) & 0x3 ) == 0 , L_26 ) ;
F_26 ( ( ( V_75 -> V_78 >> 2 ) & 0x3 ) == 1 , L_27 ) ;
F_26 ( ( ( V_75 -> V_78 >> 2 ) & 0x3 ) == 3 , L_28 ) ;
F_26 ( ( V_75 -> V_78 & F_27 ( 4 ) ) , L_29 ) ;
F_26 ( ( V_75 -> V_78 & F_27 ( 5 ) ) , L_30 ) ;
F_26 ( ( V_75 -> V_78 & F_27 ( 6 ) ) , L_31 ) ;
F_26 ( ( V_75 -> V_78 & F_27 ( 7 ) ) , L_32 ) ;
F_26 ( ( ( V_75 -> V_78 >> 8 ) & 0x3 ) == 0 , L_33 ) ;
F_26 ( ( ( V_75 -> V_78 >> 8 ) & 0x3 ) == 1 , L_34 ) ;
F_26 ( ( ( V_75 -> V_78 >> 8 ) & 0x3 ) == 2 , L_35 ) ;
F_26 ( ( ( V_75 -> V_78 >> 8 ) & 0x3 ) == 3 , L_36 ) ;
F_26 ( ( V_75 -> V_78 & F_27 ( 10 ) ) , L_37 ) ;
F_26 ( ! ( V_75 -> V_78 & F_27 ( 11 ) ) , L_38
L_39 ) ;
F_26 ( ( V_75 -> V_78 & F_27 ( 11 ) ) , L_38
L_40 ) ;
F_26 ( ( V_75 -> V_78 & F_27 ( 12 ) ) , L_41 ) ;
F_26 ( ! ( V_75 -> V_78 & F_27 ( 12 ) ) , L_42 ) ;
F_26 ( ( V_75 -> V_78 & F_27 ( 14 ) ) , L_43 ) ;
F_26 ( ( V_75 -> V_78 & F_27 ( 15 ) ) , L_44 ) ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_45 ,
V_75 -> V_79 , V_75 -> V_80 ) ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_46 ) ;
for ( V_55 = 0 ; V_55 < V_81 ; V_55 ++ )
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_47 ,
V_75 -> V_82 . V_83 [ V_55 ] ) ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_8 ) ;
if ( F_14 ( V_75 -> V_82 . V_84 ) ) {
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 ,
L_48 ,
F_14 ( V_75 -> V_82 . V_84 ) ) ;
}
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_49 ,
V_75 -> V_82 . V_85 ) ;
}
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_35 - V_5 ) ;
}
static T_1 F_28 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_5 [ 128 ] , * V_35 = V_5 ;
struct V_6 * V_7 = V_1 -> V_8 ;
struct V_86 * V_87 = & V_7 -> V_7 . V_88 ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_50 ,
V_87 -> V_89 ? L_3 : L_21 ) ;
if ( V_87 -> V_89 ) {
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_51 , V_87 -> V_78 ) ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_52 ,
F_14 ( V_87 -> V_90 . V_91 ) ) ;
if ( V_87 -> V_90 . V_84 )
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 ,
L_53 ,
F_14 ( V_87 -> V_90 . V_84 ) ) ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_54 ,
F_14 ( V_87 -> V_90 . V_92 ) ) ;
if ( V_87 -> V_90 . V_93 )
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 ,
L_55 ,
F_14 ( V_87 -> V_90 . V_93 ) ) ;
}
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_35 - V_5 ) ;
}
static T_1 F_29 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
struct V_94 V_95 ;
T_8 V_96 ;
F_30 ( V_7 , & V_7 -> V_97 , & V_95 ) ;
V_96 = F_31 ( & V_95 ) ;
return F_8 ( V_2 , V_3 , V_4 ,
L_56 ,
V_96 / 10 , V_96 % 10 ) ;
}
static T_1 F_32 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
struct V_94 V_95 ;
T_8 V_96 ;
F_33 ( V_7 , & V_95 ) ;
V_96 = F_31 ( & V_95 ) ;
return F_8 ( V_2 , V_3 , V_4 ,
L_56 ,
V_96 / 10 , V_96 % 10 ) ;
}
static int
F_34 ( struct V_98 * V_99 ,
char * V_5 , int V_100 , int V_101 )
{
int V_55 ;
int V_102 = V_99 -> V_103 ;
T_9 * V_104 = V_99 -> V_105 ;
V_100 += F_3 ( V_5 + V_100 , V_101 - V_100 ,
L_57 ) ;
if ( V_102 ) {
V_100 += F_3 ( V_5 + V_100 , V_101 - V_100 ,
L_58 , V_104 [ 0 ] ) ;
for ( V_55 = 0 ; V_55 < V_102 - 1 ; V_55 ++ )
V_100 += F_3 ( V_5 + V_100 , V_101 - V_100 , L_59 ,
V_104 [ V_55 ] , V_104 [ V_55 + 1 ] ) ;
V_100 += F_3 ( V_5 + V_100 , V_101 - V_100 ,
L_60 , V_104 [ V_102 - 1 ] ) ;
}
V_100 += F_3 ( V_5 + V_100 , V_101 - V_100 , L_8 ) ;
return V_100 ;
}
static int
F_35 ( struct V_98 * V_106 ,
struct V_107 * V_108 ,
char * V_5 , int V_100 , int V_101 , int V_69 )
{
T_9 V_109 = 0 ;
int V_110 ;
int V_111 = V_108 -> V_111 ;
V_100 += F_3 ( V_5 + V_100 , V_101 - V_100 , L_61 , V_69 ) ;
if ( V_108 -> V_112 )
V_109 = V_108 -> V_113 / V_108 -> V_112 ;
V_100 += F_3 ( V_5 + V_100 , V_101 - V_100 , L_62 ,
V_108 -> V_114 , V_109 ) ;
if ( V_106 -> V_103 && V_108 -> V_115 )
for ( V_110 = 0 ; V_110 < V_111 ; V_110 ++ )
V_100 += F_3 ( V_5 + V_100 , V_101 - V_100 ,
L_63 , V_108 -> V_115 [ V_110 ] ) ;
V_100 += F_3 ( V_5 + V_100 , V_101 - V_100 , L_8 ) ;
return V_100 ;
}
static T_1 F_36 ( struct V_1 * V_1 ,
char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
struct V_116 * V_117 = V_7 -> V_117 ;
struct V_98 * V_99 ;
char * V_5 ;
int V_101 , V_70 , V_55 ;
int V_100 = 0 ;
V_101 = 20 * V_54 *
sizeof( struct V_107 ) ;
V_5 = F_37 ( V_101 , V_118 ) ;
if ( ! V_5 )
return - V_119 ;
F_16 () ;
V_99 = F_17 ( V_117 -> V_99 ) ;
if ( ! V_7 -> V_108 ) {
V_100 += F_3 ( V_5 + V_100 , V_101 - V_100 ,
L_64 ) ;
goto V_120;
}
V_100 = F_34 ( V_99 , V_5 , V_100 , V_101 ) ;
V_100 += F_3 ( V_5 + V_100 , V_101 - V_100 , L_65 , V_7 -> V_7 . V_121 ) ;
for ( V_55 = 0 ; V_55 < V_54 ; V_55 ++ )
V_100 = F_35 ( V_99 , & V_7 -> V_108 [ V_55 ] ,
V_5 , V_100 , V_101 , V_55 ) ;
V_120:
F_18 () ;
V_70 = F_4 ( V_2 , V_3 , V_4 , V_5 , V_100 ) ;
F_38 ( V_5 ) ;
return V_70 ;
}
static T_1 F_39 ( struct V_1 * V_1 ,
const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
T_9 * V_115 ;
int V_111 ;
struct V_6 * V_7 = V_1 -> V_8 ;
int V_55 ;
if ( ! V_7 -> V_108 )
return - V_71 ;
for ( V_55 = 0 ; V_55 < V_54 ; V_55 ++ ) {
V_115 = V_7 -> V_108 [ V_55 ] . V_115 ;
V_111 = V_7 -> V_108 [ V_55 ] . V_111 ;
V_7 -> V_108 [ V_55 ] . V_114 = 0 ;
V_7 -> V_108 [ V_55 ] . V_113 = 0 ;
V_7 -> V_108 [ V_55 ] . V_112 = 0 ;
if ( V_111 )
memset ( V_115 , 0 , V_111 * sizeof( T_9 ) ) ;
}
return V_3 ;
}
void F_40 ( struct V_6 * V_7 )
{
struct V_116 * V_117 = V_7 -> V_117 ;
struct V_122 * V_123 = V_7 -> V_123 ;
struct V_124 * V_125 = V_7 -> V_123 -> V_126 . V_127 ;
T_10 V_128 [ 3 * V_129 ] ;
V_7 -> V_126 . V_130 = true ;
if ( ! V_125 )
return;
snprintf ( V_128 , sizeof( V_128 ) , L_66 , V_7 -> V_7 . V_121 ) ;
V_7 -> V_126 . V_131 = F_41 ( V_128 , V_125 ) ;
if ( ! V_7 -> V_126 . V_131 )
return;
F_42 ( V_132 ) ;
F_42 ( V_133 ) ;
F_42 ( V_134 ) ;
F_42 ( V_135 ) ;
F_42 ( V_56 ) ;
F_42 ( V_136 ) ;
F_42 ( V_137 ) ;
F_42 ( V_138 ) ;
F_42 ( V_139 ) ;
F_42 ( V_140 ) ;
F_42 ( V_141 ) ;
F_42 ( V_142 ) ;
F_42 ( V_143 ) ;
F_42 ( V_144 ) ;
F_42 ( V_145 ) ;
F_42 ( V_146 ) ;
F_43 ( V_147 , V_147 ) ;
F_43 ( V_148 , V_148 ) ;
F_43 ( V_149 , V_149 ) ;
F_43 ( V_150 , V_150 ) ;
F_43 ( V_151 , V_152 ) ;
F_43 ( V_153 , V_153 ) ;
F_43 ( V_154 , V_154 ) ;
F_43 ( V_155 , V_155 ) ;
F_43 ( V_38 , V_156 ) ;
F_43 ( V_157 , V_157 ) ;
F_43 ( V_158 , V_158 ) ;
if ( sizeof( V_7 -> V_159 ) == sizeof( T_9 ) )
F_44 ( L_67 , 0400 ,
V_7 -> V_126 . V_131 ,
( T_9 * ) & V_7 -> V_159 ) ;
else
F_45 ( L_67 , 0400 ,
V_7 -> V_126 . V_131 ,
( V_160 * ) & V_7 -> V_159 ) ;
F_46 ( V_117 , V_123 , & V_7 -> V_7 , V_7 -> V_126 . V_131 ) ;
}
void F_47 ( struct V_6 * V_7 )
{
struct V_116 * V_117 = V_7 -> V_117 ;
struct V_122 * V_123 = V_7 -> V_123 ;
F_48 ( V_117 , V_123 , & V_7 -> V_7 , V_7 -> V_126 . V_131 ) ;
F_49 ( V_7 -> V_126 . V_131 ) ;
V_7 -> V_126 . V_131 = NULL ;
}
