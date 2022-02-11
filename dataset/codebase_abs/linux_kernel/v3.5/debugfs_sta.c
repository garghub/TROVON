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
char V_5 [ 71 + V_52 * 40 ] , * V_30 = V_5 ;
int V_50 ;
struct V_6 * V_7 = V_1 -> V_8 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
F_16 () ;
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_7 ,
V_7 -> V_57 . V_58 + 1 ) ;
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 ,
L_8 ) ;
for ( V_50 = 0 ; V_50 < V_52 ; V_50 ++ ) {
V_54 = F_17 ( V_7 -> V_57 . V_54 [ V_50 ] ) ;
V_56 = F_17 ( V_7 -> V_57 . V_56 [ V_50 ] ) ;
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_9 , V_50 ) ;
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_10 , ! ! V_54 ) ;
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_11 ,
V_54 ? V_54 -> V_59 : 0 ) ;
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_12 ,
V_54 ? V_54 -> V_60 : 0 ) ;
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_10 , ! ! V_56 ) ;
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_11 ,
V_56 ? V_56 -> V_59 : 0 ) ;
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_13 ,
V_56 ? F_6 ( & V_56 -> V_61 ) : 0 ) ;
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_6 ) ;
}
F_18 () ;
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_30 - V_5 ) ;
}
static T_1 F_19 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_62 [ 12 ] , * V_5 = V_62 ;
struct V_6 * V_7 = V_1 -> V_8 ;
bool V_63 , V_64 ;
unsigned long V_65 ;
int V_66 ;
if ( V_3 > sizeof( V_62 ) )
return - V_67 ;
if ( F_20 ( V_5 , V_2 , V_3 ) )
return - V_68 ;
V_5 [ sizeof( V_62 ) - 1 ] = '\0' ;
if ( strncmp ( V_5 , L_14 , 3 ) == 0 ) {
V_5 += 3 ;
V_64 = true ;
} else if ( strncmp ( V_5 , L_15 , 3 ) == 0 ) {
V_5 += 3 ;
V_64 = false ;
} else
return - V_67 ;
if ( strncmp ( V_5 , L_16 , 6 ) == 0 ) {
V_5 += 6 ;
V_63 = true ;
if ( ! V_64 )
return - V_67 ;
} else if ( strncmp ( V_5 , L_17 , 5 ) == 0 ) {
V_5 += 5 ;
V_63 = false ;
} else
return - V_67 ;
V_65 = F_21 ( V_5 , NULL , 0 ) ;
if ( V_65 >= V_52 )
return - V_67 ;
if ( V_64 ) {
if ( V_63 )
V_66 = F_22 ( & V_7 -> V_7 , V_65 , 5000 ) ;
else
V_66 = F_23 ( & V_7 -> V_7 , V_65 ) ;
} else {
F_24 ( V_7 , V_65 , V_69 ,
3 , true ) ;
V_66 = 0 ;
}
return V_66 ? : V_3 ;
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
struct V_70 * V_71 = & V_7 -> V_7 . V_72 ;
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_18 ,
V_71 -> V_73 ? L_19 : L_20 ) ;
if ( V_71 -> V_73 ) {
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_21 , V_71 -> V_74 ) ;
F_26 ( ( V_71 -> V_74 & F_27 ( 0 ) ) , L_22 ) ;
F_26 ( ( V_71 -> V_74 & F_27 ( 1 ) ) , L_23 ) ;
F_26 ( ! ( V_71 -> V_74 & F_27 ( 1 ) ) , L_24 ) ;
F_26 ( ( ( V_71 -> V_74 >> 2 ) & 0x3 ) == 0 , L_25 ) ;
F_26 ( ( ( V_71 -> V_74 >> 2 ) & 0x3 ) == 1 , L_26 ) ;
F_26 ( ( ( V_71 -> V_74 >> 2 ) & 0x3 ) == 3 , L_27 ) ;
F_26 ( ( V_71 -> V_74 & F_27 ( 4 ) ) , L_28 ) ;
F_26 ( ( V_71 -> V_74 & F_27 ( 5 ) ) , L_29 ) ;
F_26 ( ( V_71 -> V_74 & F_27 ( 6 ) ) , L_30 ) ;
F_26 ( ( V_71 -> V_74 & F_27 ( 7 ) ) , L_31 ) ;
F_26 ( ( ( V_71 -> V_74 >> 8 ) & 0x3 ) == 0 , L_32 ) ;
F_26 ( ( ( V_71 -> V_74 >> 8 ) & 0x3 ) == 1 , L_33 ) ;
F_26 ( ( ( V_71 -> V_74 >> 8 ) & 0x3 ) == 2 , L_34 ) ;
F_26 ( ( ( V_71 -> V_74 >> 8 ) & 0x3 ) == 3 , L_35 ) ;
F_26 ( ( V_71 -> V_74 & F_27 ( 10 ) ) , L_36 ) ;
F_26 ( ! ( V_71 -> V_74 & F_27 ( 11 ) ) , L_37
L_38 ) ;
F_26 ( ( V_71 -> V_74 & F_27 ( 11 ) ) , L_37
L_39 ) ;
F_26 ( ( V_71 -> V_74 & F_27 ( 12 ) ) , L_40 ) ;
F_26 ( ! ( V_71 -> V_74 & F_27 ( 12 ) ) , L_41 ) ;
F_26 ( ( V_71 -> V_74 & F_27 ( 14 ) ) , L_42 ) ;
F_26 ( ( V_71 -> V_74 & F_27 ( 15 ) ) , L_43 ) ;
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_44 ,
V_71 -> V_75 , V_71 -> V_76 ) ;
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_45 ) ;
for ( V_50 = 0 ; V_50 < V_77 ; V_50 ++ )
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_46 ,
V_71 -> V_78 . V_79 [ V_50 ] ) ;
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_6 ) ;
if ( F_14 ( V_71 -> V_78 . V_80 ) ) {
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 ,
L_47 ,
F_14 ( V_71 -> V_78 . V_80 ) ) ;
}
V_30 += F_3 ( V_30 , sizeof( V_5 ) + V_5 - V_30 , L_48 ,
V_71 -> V_78 . V_81 ) ;
}
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_30 - V_5 ) ;
}
void F_28 ( struct V_6 * V_7 )
{
struct V_82 * V_83 = V_7 -> V_84 -> V_85 . V_86 ;
T_8 V_87 [ 3 * V_88 ] ;
V_7 -> V_85 . V_89 = true ;
if ( ! V_83 )
return;
snprintf ( V_87 , sizeof( V_87 ) , L_49 , V_7 -> V_7 . V_90 ) ;
V_7 -> V_85 . V_91 = F_29 ( V_87 , V_83 ) ;
if ( ! V_7 -> V_85 . V_91 )
return;
F_30 ( V_92 ) ;
F_30 ( V_93 ) ;
F_30 ( V_94 ) ;
F_30 ( V_95 ) ;
F_30 ( V_51 ) ;
F_30 ( V_96 ) ;
F_30 ( V_97 ) ;
F_30 ( V_98 ) ;
F_30 ( V_99 ) ;
F_31 ( V_100 , V_100 ) ;
F_31 ( V_101 , V_101 ) ;
F_31 ( V_102 , V_102 ) ;
F_31 ( V_103 , V_103 ) ;
F_31 ( V_104 , V_105 ) ;
F_31 ( V_106 , V_106 ) ;
F_31 ( V_107 , V_107 ) ;
F_31 ( V_108 , V_108 ) ;
F_31 ( V_33 , V_109 ) ;
F_31 ( V_110 , V_110 ) ;
F_31 ( V_111 , V_111 ) ;
F_31 ( V_112 , V_112 ) ;
}
void F_32 ( struct V_6 * V_7 )
{
F_33 ( V_7 -> V_85 . V_91 ) ;
V_7 -> V_85 . V_91 = NULL ;
}
