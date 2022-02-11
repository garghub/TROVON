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
F_2 ( V_16 ) , F_2 ( V_17 ) , F_2 ( V_18 ) ,
F_2 ( V_19 ) , F_2 ( V_20 ) , F_2 ( V_21 ) ,
F_2 ( V_22 ) , F_2 ( V_23 ) , F_2 ( V_24 ) ,
F_2 ( V_25 ) , F_2 ( 4ADDR_EVENT ) ,
F_2 ( V_26 ) , F_2 ( V_27 ) ,
F_2 ( V_28 ) , F_2 ( V_29 ) ,
F_2 ( V_30 ) ) ;
#undef F_2
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_9 ) ;
}
static T_1 F_5 ( struct V_1 * V_1 ,
char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
char V_5 [ 17 * V_31 ] , * V_32 = V_5 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_31 ; V_33 ++ )
V_32 += F_3 ( V_32 , sizeof( V_5 ) + V_5 - V_32 , L_2 , V_33 ,
F_6 ( & V_7 -> V_34 [ V_33 ] ) +
F_6 ( & V_7 -> V_35 [ V_33 ] ) ) ;
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_32 - V_5 ) ;
}
static T_1 F_7 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
return F_8 ( V_2 , V_3 , V_4 , L_3 ,
F_9 ( V_36 - V_7 -> V_37 ) ) ;
}
static T_1 F_10 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
struct V_38 V_39 ;
struct V_40 V_41 ;
long V_42 ;
char V_5 [ 100 ] ;
int V_9 ;
F_11 ( & V_39 ) ;
V_42 = V_39 . V_43 - V_7 -> V_44 ;
F_12 ( V_42 , 0 , & V_41 ) ;
V_41 . V_45 -= 70 ;
V_41 . V_46 -= 1 ;
V_9 = F_3 ( V_5 , sizeof( V_5 ) ,
L_4 ,
V_41 . V_45 , V_41 . V_47 , V_41 . V_46 ,
V_41 . V_48 , V_41 . V_49 , V_41 . V_50 ) ;
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_9 ) ;
}
static T_1 F_13 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_5 [ 15 * V_51 ] , * V_32 = V_5 ;
int V_52 ;
struct V_6 * V_7 = V_1 -> V_8 ;
for ( V_52 = 0 ; V_52 < V_51 ; V_52 ++ )
V_32 += F_3 ( V_32 , sizeof( V_5 ) + V_5 - V_32 , L_5 ,
F_14 ( V_7 -> V_53 [ V_52 ] ) ) ;
V_32 += F_3 ( V_32 , sizeof( V_5 ) + V_5 - V_32 , L_6 ) ;
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_32 - V_5 ) ;
}
static T_1 F_15 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_5 [ 71 + V_51 * 40 ] , * V_32 = V_5 ;
int V_52 ;
struct V_6 * V_7 = V_1 -> V_8 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
F_16 () ;
V_32 += F_3 ( V_32 , sizeof( V_5 ) + V_5 - V_32 , L_7 ,
V_7 -> V_58 . V_59 + 1 ) ;
V_32 += F_3 ( V_32 , sizeof( V_5 ) + V_5 - V_32 ,
L_8 ) ;
for ( V_52 = 0 ; V_52 < V_51 ; V_52 ++ ) {
V_55 = F_17 ( V_7 -> V_58 . V_55 [ V_52 ] ) ;
V_57 = F_17 ( V_7 -> V_58 . V_57 [ V_52 ] ) ;
V_32 += F_3 ( V_32 , sizeof( V_5 ) + V_5 - V_32 , L_9 , V_52 ) ;
V_32 += F_3 ( V_32 , sizeof( V_5 ) + V_5 - V_32 , L_10 , ! ! V_55 ) ;
V_32 += F_3 ( V_32 , sizeof( V_5 ) + V_5 - V_32 , L_11 ,
V_55 ? V_55 -> V_60 : 0 ) ;
V_32 += F_3 ( V_32 , sizeof( V_5 ) + V_5 - V_32 , L_12 ,
V_55 ? V_55 -> V_61 : 0 ) ;
V_32 += F_3 ( V_32 , sizeof( V_5 ) + V_5 - V_32 , L_10 , ! ! V_57 ) ;
V_32 += F_3 ( V_32 , sizeof( V_5 ) + V_5 - V_32 , L_11 ,
V_57 ? V_57 -> V_60 : 0 ) ;
V_32 += F_3 ( V_32 , sizeof( V_5 ) + V_5 - V_32 , L_13 ,
V_57 ? F_6 ( & V_57 -> V_62 ) : 0 ) ;
V_32 += F_3 ( V_32 , sizeof( V_5 ) + V_5 - V_32 , L_6 ) ;
}
F_18 () ;
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_32 - V_5 ) ;
}
static T_1 F_19 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_63 [ 12 ] , * V_5 = V_63 ;
struct V_6 * V_7 = V_1 -> V_8 ;
bool V_64 , V_65 ;
unsigned long V_66 ;
int V_67 ;
if ( V_3 > sizeof( V_63 ) )
return - V_68 ;
if ( F_20 ( V_5 , V_2 , V_3 ) )
return - V_69 ;
V_5 [ sizeof( V_63 ) - 1 ] = '\0' ;
if ( strncmp ( V_5 , L_14 , 3 ) == 0 ) {
V_5 += 3 ;
V_65 = true ;
} else if ( strncmp ( V_5 , L_15 , 3 ) == 0 ) {
V_5 += 3 ;
V_65 = false ;
} else
return - V_68 ;
if ( strncmp ( V_5 , L_16 , 6 ) == 0 ) {
V_5 += 6 ;
V_64 = true ;
if ( ! V_65 )
return - V_68 ;
} else if ( strncmp ( V_5 , L_17 , 5 ) == 0 ) {
V_5 += 5 ;
V_64 = false ;
} else
return - V_68 ;
V_67 = F_21 ( V_5 , 0 , & V_66 ) ;
if ( V_67 )
return V_67 ;
if ( V_66 >= V_51 )
return - V_68 ;
if ( V_65 ) {
if ( V_64 )
V_67 = F_22 ( & V_7 -> V_7 , V_66 , 5000 ) ;
else
V_67 = F_23 ( & V_7 -> V_7 , V_66 ) ;
} else {
F_24 ( V_7 , V_66 , V_70 ,
3 , true ) ;
V_67 = 0 ;
}
return V_67 ? : V_3 ;
}
static T_1 F_25 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
#define F_26 ( T_6 , T_7 ) \
do { \
if (_cond) \
p += scnprintf(p, sizeof(buf)+buf-p, "\t" _str "\n"); \
} while (0)
char V_5 [ 512 ] , * V_32 = V_5 ;
int V_52 ;
struct V_6 * V_7 = V_1 -> V_8 ;
struct V_71 * V_72 = & V_7 -> V_7 . V_73 ;
V_32 += F_3 ( V_32 , sizeof( V_5 ) + V_5 - V_32 , L_18 ,
V_72 -> V_74 ? L_19 : L_20 ) ;
if ( V_72 -> V_74 ) {
V_32 += F_3 ( V_32 , sizeof( V_5 ) + V_5 - V_32 , L_21 , V_72 -> V_75 ) ;
F_26 ( ( V_72 -> V_75 & F_27 ( 0 ) ) , L_22 ) ;
F_26 ( ( V_72 -> V_75 & F_27 ( 1 ) ) , L_23 ) ;
F_26 ( ! ( V_72 -> V_75 & F_27 ( 1 ) ) , L_24 ) ;
F_26 ( ( ( V_72 -> V_75 >> 2 ) & 0x3 ) == 0 , L_25 ) ;
F_26 ( ( ( V_72 -> V_75 >> 2 ) & 0x3 ) == 1 , L_26 ) ;
F_26 ( ( ( V_72 -> V_75 >> 2 ) & 0x3 ) == 3 , L_27 ) ;
F_26 ( ( V_72 -> V_75 & F_27 ( 4 ) ) , L_28 ) ;
F_26 ( ( V_72 -> V_75 & F_27 ( 5 ) ) , L_29 ) ;
F_26 ( ( V_72 -> V_75 & F_27 ( 6 ) ) , L_30 ) ;
F_26 ( ( V_72 -> V_75 & F_27 ( 7 ) ) , L_31 ) ;
F_26 ( ( ( V_72 -> V_75 >> 8 ) & 0x3 ) == 0 , L_32 ) ;
F_26 ( ( ( V_72 -> V_75 >> 8 ) & 0x3 ) == 1 , L_33 ) ;
F_26 ( ( ( V_72 -> V_75 >> 8 ) & 0x3 ) == 2 , L_34 ) ;
F_26 ( ( ( V_72 -> V_75 >> 8 ) & 0x3 ) == 3 , L_35 ) ;
F_26 ( ( V_72 -> V_75 & F_27 ( 10 ) ) , L_36 ) ;
F_26 ( ! ( V_72 -> V_75 & F_27 ( 11 ) ) , L_37
L_38 ) ;
F_26 ( ( V_72 -> V_75 & F_27 ( 11 ) ) , L_37
L_39 ) ;
F_26 ( ( V_72 -> V_75 & F_27 ( 12 ) ) , L_40 ) ;
F_26 ( ! ( V_72 -> V_75 & F_27 ( 12 ) ) , L_41 ) ;
F_26 ( ( V_72 -> V_75 & F_27 ( 14 ) ) , L_42 ) ;
F_26 ( ( V_72 -> V_75 & F_27 ( 15 ) ) , L_43 ) ;
V_32 += F_3 ( V_32 , sizeof( V_5 ) + V_5 - V_32 , L_44 ,
V_72 -> V_76 , V_72 -> V_77 ) ;
V_32 += F_3 ( V_32 , sizeof( V_5 ) + V_5 - V_32 , L_45 ) ;
for ( V_52 = 0 ; V_52 < V_78 ; V_52 ++ )
V_32 += F_3 ( V_32 , sizeof( V_5 ) + V_5 - V_32 , L_46 ,
V_72 -> V_79 . V_80 [ V_52 ] ) ;
V_32 += F_3 ( V_32 , sizeof( V_5 ) + V_5 - V_32 , L_6 ) ;
if ( F_14 ( V_72 -> V_79 . V_81 ) ) {
V_32 += F_3 ( V_32 , sizeof( V_5 ) + V_5 - V_32 ,
L_47 ,
F_14 ( V_72 -> V_79 . V_81 ) ) ;
}
V_32 += F_3 ( V_32 , sizeof( V_5 ) + V_5 - V_32 , L_48 ,
V_72 -> V_79 . V_82 ) ;
}
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_32 - V_5 ) ;
}
static T_1 F_28 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_5 [ 128 ] , * V_32 = V_5 ;
struct V_6 * V_7 = V_1 -> V_8 ;
struct V_83 * V_84 = & V_7 -> V_7 . V_85 ;
V_32 += F_3 ( V_32 , sizeof( V_5 ) + V_5 - V_32 , L_49 ,
V_84 -> V_86 ? L_19 : L_20 ) ;
if ( V_84 -> V_86 ) {
V_32 += F_3 ( V_32 , sizeof( V_5 ) + V_5 - V_32 , L_50 , V_84 -> V_75 ) ;
V_32 += F_3 ( V_32 , sizeof( V_5 ) + V_5 - V_32 , L_51 ,
F_14 ( V_84 -> V_87 . V_88 ) ) ;
if ( V_84 -> V_87 . V_81 )
V_32 += F_3 ( V_32 , sizeof( V_5 ) + V_5 - V_32 ,
L_52 ,
F_14 ( V_84 -> V_87 . V_81 ) ) ;
V_32 += F_3 ( V_32 , sizeof( V_5 ) + V_5 - V_32 , L_53 ,
F_14 ( V_84 -> V_87 . V_89 ) ) ;
if ( V_84 -> V_87 . V_90 )
V_32 += F_3 ( V_32 , sizeof( V_5 ) + V_5 - V_32 ,
L_54 ,
F_14 ( V_84 -> V_87 . V_90 ) ) ;
}
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_32 - V_5 ) ;
}
static T_1 F_29 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
struct V_91 V_92 ;
T_8 V_93 ;
F_30 ( V_7 , & V_7 -> V_94 , & V_92 ) ;
V_93 = F_31 ( & V_92 ) ;
return F_8 ( V_2 , V_3 , V_4 ,
L_55 ,
V_93 / 10 , V_93 % 10 ) ;
}
static T_1 F_32 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
struct V_91 V_92 ;
T_8 V_93 ;
F_33 ( V_7 , & V_92 ) ;
V_93 = F_31 ( & V_92 ) ;
return F_8 ( V_2 , V_3 , V_4 ,
L_55 ,
V_93 / 10 , V_93 % 10 ) ;
}
void F_34 ( struct V_6 * V_7 )
{
struct V_95 * V_96 = V_7 -> V_96 ;
struct V_97 * V_98 = V_7 -> V_98 ;
struct V_99 * V_100 = V_7 -> V_98 -> V_101 . V_102 ;
T_9 V_103 [ 3 * V_104 ] ;
V_7 -> V_101 . V_105 = true ;
if ( ! V_100 )
return;
snprintf ( V_103 , sizeof( V_103 ) , L_56 , V_7 -> V_7 . V_106 ) ;
V_7 -> V_101 . V_107 = F_35 ( V_103 , V_100 ) ;
if ( ! V_7 -> V_101 . V_107 )
return;
F_36 ( V_108 ) ;
F_36 ( V_109 ) ;
F_36 ( V_110 ) ;
F_36 ( V_111 ) ;
F_36 ( V_53 ) ;
F_36 ( V_112 ) ;
F_36 ( V_113 ) ;
F_36 ( V_114 ) ;
F_36 ( V_115 ) ;
F_36 ( V_116 ) ;
F_36 ( V_117 ) ;
F_36 ( V_118 ) ;
F_36 ( V_119 ) ;
F_36 ( V_120 ) ;
F_37 ( V_121 , V_121 ) ;
F_37 ( V_122 , V_122 ) ;
F_37 ( V_123 , V_123 ) ;
F_37 ( V_124 , V_124 ) ;
F_37 ( V_125 , V_126 ) ;
F_37 ( V_127 , V_127 ) ;
F_37 ( V_128 , V_128 ) ;
F_37 ( V_129 , V_129 ) ;
F_37 ( V_35 , V_130 ) ;
F_37 ( V_131 , V_131 ) ;
F_37 ( V_132 , V_132 ) ;
F_37 ( V_133 , V_133 ) ;
F_38 ( V_96 , V_98 , & V_7 -> V_7 , V_7 -> V_101 . V_107 ) ;
}
void F_39 ( struct V_6 * V_7 )
{
struct V_95 * V_96 = V_7 -> V_96 ;
struct V_97 * V_98 = V_7 -> V_98 ;
F_40 ( V_96 , V_98 , & V_7 -> V_7 , V_7 -> V_101 . V_107 ) ;
F_41 ( V_7 -> V_101 . V_107 ) ;
V_7 -> V_101 . V_107 = NULL ;
}
