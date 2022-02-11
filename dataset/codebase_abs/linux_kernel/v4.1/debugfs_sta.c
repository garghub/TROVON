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
void F_34 ( struct V_6 * V_7 )
{
struct V_98 * V_99 = V_7 -> V_99 ;
struct V_100 * V_101 = V_7 -> V_101 ;
struct V_102 * V_103 = V_7 -> V_101 -> V_104 . V_105 ;
T_9 V_106 [ 3 * V_107 ] ;
V_7 -> V_104 . V_108 = true ;
if ( ! V_103 )
return;
snprintf ( V_106 , sizeof( V_106 ) , L_57 , V_7 -> V_7 . V_109 ) ;
V_7 -> V_104 . V_110 = F_35 ( V_106 , V_103 ) ;
if ( ! V_7 -> V_104 . V_110 )
return;
F_36 ( V_111 ) ;
F_36 ( V_112 ) ;
F_36 ( V_113 ) ;
F_36 ( V_114 ) ;
F_36 ( V_56 ) ;
F_36 ( V_115 ) ;
F_36 ( V_116 ) ;
F_36 ( V_117 ) ;
F_36 ( V_118 ) ;
F_36 ( V_119 ) ;
F_36 ( V_120 ) ;
F_36 ( V_121 ) ;
F_36 ( V_122 ) ;
F_36 ( V_123 ) ;
F_37 ( V_124 , V_124 ) ;
F_37 ( V_125 , V_125 ) ;
F_37 ( V_126 , V_126 ) ;
F_37 ( V_127 , V_127 ) ;
F_37 ( V_128 , V_129 ) ;
F_37 ( V_130 , V_130 ) ;
F_37 ( V_131 , V_131 ) ;
F_37 ( V_132 , V_132 ) ;
F_37 ( V_38 , V_133 ) ;
F_37 ( V_134 , V_134 ) ;
F_37 ( V_135 , V_135 ) ;
if ( sizeof( V_7 -> V_136 ) == sizeof( V_137 ) )
F_38 ( L_58 , 0400 ,
V_7 -> V_104 . V_110 ,
( V_137 * ) & V_7 -> V_136 ) ;
else
F_39 ( L_58 , 0400 ,
V_7 -> V_104 . V_110 ,
( V_138 * ) & V_7 -> V_136 ) ;
F_40 ( V_99 , V_101 , & V_7 -> V_7 , V_7 -> V_104 . V_110 ) ;
}
void F_41 ( struct V_6 * V_7 )
{
struct V_98 * V_99 = V_7 -> V_99 ;
struct V_100 * V_101 = V_7 -> V_101 ;
F_42 ( V_99 , V_101 , & V_7 -> V_7 , V_7 -> V_104 . V_110 ) ;
F_43 ( V_7 -> V_104 . V_110 ) ;
V_7 -> V_104 . V_110 = NULL ;
}
