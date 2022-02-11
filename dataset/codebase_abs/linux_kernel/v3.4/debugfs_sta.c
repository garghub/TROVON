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
F_2 ( V_26 ) , F_2 ( V_27 ) ) ;
#undef F_2
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_9 ) ;
}
static T_1 F_5 ( struct V_1 * V_1 ,
char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
char V_5 [ 17 * V_28 ] , * V_29 = V_5 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_28 ; V_30 ++ )
V_29 += F_3 ( V_29 , sizeof( V_5 ) + V_5 - V_29 , L_2 , V_30 ,
F_6 ( & V_7 -> V_31 [ V_30 ] ) +
F_6 ( & V_7 -> V_32 [ V_30 ] ) ) ;
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_29 - V_5 ) ;
}
static T_1 F_7 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
return F_8 ( V_2 , V_3 , V_4 , L_3 ,
F_9 ( V_33 - V_7 -> V_34 ) ) ;
}
static T_1 F_10 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
struct V_35 V_36 ;
struct V_37 V_38 ;
long V_39 ;
char V_5 [ 100 ] ;
int V_9 ;
F_11 ( & V_36 ) ;
V_39 = V_36 . V_40 - V_7 -> V_41 ;
F_12 ( V_39 , 0 , & V_38 ) ;
V_38 . V_42 -= 70 ;
V_38 . V_43 -= 1 ;
V_9 = F_3 ( V_5 , sizeof( V_5 ) ,
L_4 ,
V_38 . V_42 , V_38 . V_44 , V_38 . V_43 ,
V_38 . V_45 , V_38 . V_46 , V_38 . V_47 ) ;
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_9 ) ;
}
static T_1 F_13 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_5 [ 15 * V_48 ] , * V_29 = V_5 ;
int V_49 ;
struct V_6 * V_7 = V_1 -> V_8 ;
for ( V_49 = 0 ; V_49 < V_48 ; V_49 ++ )
V_29 += F_3 ( V_29 , sizeof( V_5 ) + V_5 - V_29 , L_5 ,
F_14 ( V_7 -> V_50 [ V_49 ] ) ) ;
V_29 += F_3 ( V_29 , sizeof( V_5 ) + V_5 - V_29 , L_6 ) ;
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_29 - V_5 ) ;
}
static T_1 F_15 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_5 [ 71 + V_51 * 40 ] , * V_29 = V_5 ;
int V_49 ;
struct V_6 * V_7 = V_1 -> V_8 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
F_16 () ;
V_29 += F_3 ( V_29 , sizeof( V_5 ) + V_5 - V_29 , L_7 ,
V_7 -> V_56 . V_57 + 1 ) ;
V_29 += F_3 ( V_29 , sizeof( V_5 ) + V_5 - V_29 ,
L_8 ) ;
for ( V_49 = 0 ; V_49 < V_51 ; V_49 ++ ) {
V_53 = F_17 ( V_7 -> V_56 . V_53 [ V_49 ] ) ;
V_55 = F_17 ( V_7 -> V_56 . V_55 [ V_49 ] ) ;
V_29 += F_3 ( V_29 , sizeof( V_5 ) + V_5 - V_29 , L_9 , V_49 ) ;
V_29 += F_3 ( V_29 , sizeof( V_5 ) + V_5 - V_29 , L_10 , ! ! V_53 ) ;
V_29 += F_3 ( V_29 , sizeof( V_5 ) + V_5 - V_29 , L_11 ,
V_53 ? V_53 -> V_58 : 0 ) ;
V_29 += F_3 ( V_29 , sizeof( V_5 ) + V_5 - V_29 , L_12 ,
V_53 ? V_53 -> V_59 : 0 ) ;
V_29 += F_3 ( V_29 , sizeof( V_5 ) + V_5 - V_29 , L_10 , ! ! V_55 ) ;
V_29 += F_3 ( V_29 , sizeof( V_5 ) + V_5 - V_29 , L_11 ,
V_55 ? V_55 -> V_58 : 0 ) ;
V_29 += F_3 ( V_29 , sizeof( V_5 ) + V_5 - V_29 , L_13 ,
V_55 ? F_6 ( & V_55 -> V_60 ) : 0 ) ;
V_29 += F_3 ( V_29 , sizeof( V_5 ) + V_5 - V_29 , L_6 ) ;
}
F_18 () ;
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_29 - V_5 ) ;
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
V_64 = F_21 ( V_5 , NULL , 0 ) ;
if ( V_64 >= V_51 )
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
char V_5 [ 512 ] , * V_29 = V_5 ;
int V_49 ;
struct V_6 * V_7 = V_1 -> V_8 ;
struct V_69 * V_70 = & V_7 -> V_7 . V_71 ;
V_29 += F_3 ( V_29 , sizeof( V_5 ) + V_5 - V_29 , L_18 ,
V_70 -> V_72 ? L_19 : L_20 ) ;
if ( V_70 -> V_72 ) {
V_29 += F_3 ( V_29 , sizeof( V_5 ) + V_5 - V_29 , L_21 , V_70 -> V_73 ) ;
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
V_29 += F_3 ( V_29 , sizeof( V_5 ) + V_5 - V_29 , L_44 ,
V_70 -> V_74 , V_70 -> V_75 ) ;
V_29 += F_3 ( V_29 , sizeof( V_5 ) + V_5 - V_29 , L_45 ) ;
for ( V_49 = 0 ; V_49 < V_76 ; V_49 ++ )
V_29 += F_3 ( V_29 , sizeof( V_5 ) + V_5 - V_29 , L_46 ,
V_70 -> V_77 . V_78 [ V_49 ] ) ;
V_29 += F_3 ( V_29 , sizeof( V_5 ) + V_5 - V_29 , L_6 ) ;
if ( F_14 ( V_70 -> V_77 . V_79 ) ) {
V_29 += F_3 ( V_29 , sizeof( V_5 ) + V_5 - V_29 ,
L_47 ,
F_14 ( V_70 -> V_77 . V_79 ) ) ;
}
V_29 += F_3 ( V_29 , sizeof( V_5 ) + V_5 - V_29 , L_48 ,
V_70 -> V_77 . V_80 ) ;
}
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_29 - V_5 ) ;
}
void F_28 ( struct V_6 * V_7 )
{
struct V_81 * V_82 = V_7 -> V_83 -> V_84 . V_85 ;
T_8 V_86 [ 3 * V_87 ] ;
V_7 -> V_84 . V_88 = true ;
if ( ! V_82 )
return;
snprintf ( V_86 , sizeof( V_86 ) , L_49 , V_7 -> V_7 . V_89 ) ;
V_7 -> V_84 . V_90 = F_29 ( V_86 , V_82 ) ;
if ( ! V_7 -> V_84 . V_90 )
return;
F_30 ( V_91 ) ;
F_30 ( V_92 ) ;
F_30 ( V_93 ) ;
F_30 ( V_94 ) ;
F_30 ( V_50 ) ;
F_30 ( V_95 ) ;
F_30 ( V_96 ) ;
F_30 ( V_97 ) ;
F_30 ( V_98 ) ;
F_31 ( V_99 , V_99 ) ;
F_31 ( V_100 , V_100 ) ;
F_31 ( V_101 , V_101 ) ;
F_31 ( V_102 , V_102 ) ;
F_31 ( V_103 , V_104 ) ;
F_31 ( V_105 , V_105 ) ;
F_31 ( V_106 , V_106 ) ;
F_31 ( V_107 , V_107 ) ;
F_31 ( V_32 , V_108 ) ;
F_31 ( V_109 , V_109 ) ;
F_31 ( V_110 , V_110 ) ;
F_31 ( V_111 , V_111 ) ;
}
void F_32 ( struct V_6 * V_7 )
{
F_33 ( V_7 -> V_84 . V_90 ) ;
V_7 -> V_84 . V_90 = NULL ;
}
