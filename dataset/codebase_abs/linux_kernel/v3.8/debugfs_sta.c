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
F_2 ( V_28 ) ) ;
#undef F_2
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_9 ) ;
}
static T_1 F_5 ( struct V_1 * V_1 ,
char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
char V_5 [ 17 * V_29 ] , * V_30 = V_5 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_29 ; V_31 ++ )
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_2 , V_31 ,
F_6 ( & V_7 -> V_32 [ V_31 ] ) +
F_6 ( & V_7 -> V_33 [ V_31 ] ) ) ;
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_30 - V_5 ) ;
}
static T_1 F_7 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
return F_8 ( V_2 , V_3 , V_4 , L_3 ,
F_9 ( V_34 - V_7 -> V_35 ) ) ;
}
static T_1 F_10 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
struct V_36 V_37 ;
struct V_38 V_39 ;
long V_40 ;
char V_5 [ 100 ] ;
int V_9 ;
F_11 ( & V_37 ) ;
V_40 = V_37 . V_41 - V_7 -> V_42 ;
F_12 ( V_40 , 0 , & V_39 ) ;
V_39 . V_43 -= 70 ;
V_39 . V_44 -= 1 ;
V_9 = F_3 ( V_5 , sizeof( V_5 ) ,
L_4 ,
V_39 . V_43 , V_39 . V_45 , V_39 . V_44 ,
V_39 . V_46 , V_39 . V_47 , V_39 . V_48 ) ;
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_9 ) ;
}
static T_1 F_13 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_5 [ 15 * V_49 ] , * V_30 = V_5 ;
int V_50 ;
struct V_6 * V_7 = V_1 -> V_8 ;
for ( V_50 = 0 ; V_50 < V_49 ; V_50 ++ )
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_5 ,
F_14 ( V_7 -> V_51 [ V_50 ] ) ) ;
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_6 ) ;
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_30 - V_5 ) ;
}
static T_1 F_15 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_5 [ 71 + V_49 * 40 ] , * V_30 = V_5 ;
int V_50 ;
struct V_6 * V_7 = V_1 -> V_8 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
F_16 () ;
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_7 ,
V_7 -> V_56 . V_57 + 1 ) ;
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 ,
L_8 ) ;
for ( V_50 = 0 ; V_50 < V_49 ; V_50 ++ ) {
V_53 = F_17 ( V_7 -> V_56 . V_53 [ V_50 ] ) ;
V_55 = F_17 ( V_7 -> V_56 . V_55 [ V_50 ] ) ;
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_9 , V_50 ) ;
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_10 , ! ! V_53 ) ;
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_11 ,
V_53 ? V_53 -> V_58 : 0 ) ;
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_12 ,
V_53 ? V_53 -> V_59 : 0 ) ;
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_10 , ! ! V_55 ) ;
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_11 ,
V_55 ? V_55 -> V_58 : 0 ) ;
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_13 ,
V_55 ? F_6 ( & V_55 -> V_60 ) : 0 ) ;
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_6 ) ;
}
F_18 () ;
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_30 - V_5 ) ;
}
static T_1 F_19 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_61 [ 12 ] , * V_5 = V_61 ;
struct V_6 * V_7 = V_1 -> V_8 ;
bool V_62 , V_63 ;
unsigned long V_64 ;
int V_65 ;
if ( V_3 > sizeof( V_61 ) )
return - V_66 ;
if ( F_20 ( V_5 , V_2 , V_3 ) )
return - V_67 ;
V_5 [ sizeof( V_61 ) - 1 ] = '\0' ;
if ( strncmp ( V_5 , L_14 , 3 ) == 0 ) {
V_5 += 3 ;
V_63 = true ;
} else if ( strncmp ( V_5 , L_15 , 3 ) == 0 ) {
V_5 += 3 ;
V_63 = false ;
} else
return - V_66 ;
if ( strncmp ( V_5 , L_16 , 6 ) == 0 ) {
V_5 += 6 ;
V_62 = true ;
if ( ! V_63 )
return - V_66 ;
} else if ( strncmp ( V_5 , L_17 , 5 ) == 0 ) {
V_5 += 5 ;
V_62 = false ;
} else
return - V_66 ;
V_65 = F_21 ( V_5 , 0 , & V_64 ) ;
if ( V_65 )
return V_65 ;
if ( V_64 >= V_49 )
return - V_66 ;
if ( V_63 ) {
if ( V_62 )
V_65 = F_22 ( & V_7 -> V_7 , V_64 , 5000 ) ;
else
V_65 = F_23 ( & V_7 -> V_7 , V_64 ) ;
} else {
F_24 ( V_7 , V_64 , V_68 ,
3 , true ) ;
V_65 = 0 ;
}
return V_65 ? : V_3 ;
}
static T_1 F_25 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
#define F_26 ( T_6 , T_7 ) \
do { \
if (_cond) \
p += scnprintf(p, sizeof(buf)+buf-p, "\t" _str "\n"); \
} while (0)
char V_5 [ 512 ] , * V_30 = V_5 ;
int V_50 ;
struct V_6 * V_7 = V_1 -> V_8 ;
struct V_69 * V_70 = & V_7 -> V_7 . V_71 ;
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_18 ,
V_70 -> V_72 ? L_19 : L_20 ) ;
if ( V_70 -> V_72 ) {
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_21 , V_70 -> V_73 ) ;
F_26 ( ( V_70 -> V_73 & F_27 ( 0 ) ) , L_22 ) ;
F_26 ( ( V_70 -> V_73 & F_27 ( 1 ) ) , L_23 ) ;
F_26 ( ! ( V_70 -> V_73 & F_27 ( 1 ) ) , L_24 ) ;
F_26 ( ( ( V_70 -> V_73 >> 2 ) & 0x3 ) == 0 , L_25 ) ;
F_26 ( ( ( V_70 -> V_73 >> 2 ) & 0x3 ) == 1 , L_26 ) ;
F_26 ( ( ( V_70 -> V_73 >> 2 ) & 0x3 ) == 3 , L_27 ) ;
F_26 ( ( V_70 -> V_73 & F_27 ( 4 ) ) , L_28 ) ;
F_26 ( ( V_70 -> V_73 & F_27 ( 5 ) ) , L_29 ) ;
F_26 ( ( V_70 -> V_73 & F_27 ( 6 ) ) , L_30 ) ;
F_26 ( ( V_70 -> V_73 & F_27 ( 7 ) ) , L_31 ) ;
F_26 ( ( ( V_70 -> V_73 >> 8 ) & 0x3 ) == 0 , L_32 ) ;
F_26 ( ( ( V_70 -> V_73 >> 8 ) & 0x3 ) == 1 , L_33 ) ;
F_26 ( ( ( V_70 -> V_73 >> 8 ) & 0x3 ) == 2 , L_34 ) ;
F_26 ( ( ( V_70 -> V_73 >> 8 ) & 0x3 ) == 3 , L_35 ) ;
F_26 ( ( V_70 -> V_73 & F_27 ( 10 ) ) , L_36 ) ;
F_26 ( ! ( V_70 -> V_73 & F_27 ( 11 ) ) , L_37
L_38 ) ;
F_26 ( ( V_70 -> V_73 & F_27 ( 11 ) ) , L_37
L_39 ) ;
F_26 ( ( V_70 -> V_73 & F_27 ( 12 ) ) , L_40 ) ;
F_26 ( ! ( V_70 -> V_73 & F_27 ( 12 ) ) , L_41 ) ;
F_26 ( ( V_70 -> V_73 & F_27 ( 14 ) ) , L_42 ) ;
F_26 ( ( V_70 -> V_73 & F_27 ( 15 ) ) , L_43 ) ;
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_44 ,
V_70 -> V_74 , V_70 -> V_75 ) ;
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_45 ) ;
for ( V_50 = 0 ; V_50 < V_76 ; V_50 ++ )
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_46 ,
V_70 -> V_77 . V_78 [ V_50 ] ) ;
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_6 ) ;
if ( F_14 ( V_70 -> V_77 . V_79 ) ) {
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 ,
L_47 ,
F_14 ( V_70 -> V_77 . V_79 ) ) ;
}
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_48 ,
V_70 -> V_77 . V_80 ) ;
}
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_30 - V_5 ) ;
}
static T_1 F_28 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
struct V_81 V_82 ;
T_8 V_83 ;
F_29 ( V_7 , & V_7 -> V_84 , & V_82 ) ;
V_83 = F_30 ( & V_82 ) ;
return F_8 ( V_2 , V_3 , V_4 ,
L_49 ,
V_83 / 10 , V_83 % 10 ) ;
}
static T_1 F_31 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
struct V_81 V_82 ;
T_8 V_83 ;
F_32 ( V_7 , & V_82 ) ;
V_83 = F_30 ( & V_82 ) ;
return F_8 ( V_2 , V_3 , V_4 ,
L_49 ,
V_83 / 10 , V_83 % 10 ) ;
}
void F_33 ( struct V_6 * V_7 )
{
struct V_85 * V_86 = V_7 -> V_86 ;
struct V_87 * V_88 = V_7 -> V_88 ;
struct V_89 * V_90 = V_7 -> V_88 -> V_91 . V_92 ;
T_9 V_93 [ 3 * V_94 ] ;
V_7 -> V_91 . V_95 = true ;
if ( ! V_90 )
return;
snprintf ( V_93 , sizeof( V_93 ) , L_50 , V_7 -> V_7 . V_96 ) ;
V_7 -> V_91 . V_97 = F_34 ( V_93 , V_90 ) ;
if ( ! V_7 -> V_91 . V_97 )
return;
F_35 ( V_98 ) ;
F_35 ( V_99 ) ;
F_35 ( V_100 ) ;
F_35 ( V_101 ) ;
F_35 ( V_51 ) ;
F_35 ( V_102 ) ;
F_35 ( V_103 ) ;
F_35 ( V_104 ) ;
F_35 ( V_105 ) ;
F_35 ( V_106 ) ;
F_35 ( V_107 ) ;
F_35 ( V_108 ) ;
F_36 ( V_109 , V_109 ) ;
F_36 ( V_110 , V_110 ) ;
F_36 ( V_111 , V_111 ) ;
F_36 ( V_112 , V_112 ) ;
F_36 ( V_113 , V_114 ) ;
F_36 ( V_115 , V_115 ) ;
F_36 ( V_116 , V_116 ) ;
F_36 ( V_117 , V_117 ) ;
F_36 ( V_33 , V_118 ) ;
F_36 ( V_119 , V_119 ) ;
F_36 ( V_120 , V_120 ) ;
F_36 ( V_121 , V_121 ) ;
F_37 ( V_86 , V_88 , & V_7 -> V_7 , V_7 -> V_91 . V_97 ) ;
}
void F_38 ( struct V_6 * V_7 )
{
struct V_85 * V_86 = V_7 -> V_86 ;
struct V_87 * V_88 = V_7 -> V_88 ;
F_39 ( V_86 , V_88 , & V_7 -> V_7 , V_7 -> V_91 . V_97 ) ;
F_40 ( V_7 -> V_91 . V_97 ) ;
V_7 -> V_91 . V_97 = NULL ;
}
