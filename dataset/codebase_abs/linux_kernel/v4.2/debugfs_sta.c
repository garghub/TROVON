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
char V_5 [ 15 * V_39 ] , * V_35 = V_5 ;
int V_40 ;
struct V_6 * V_7 = V_1 -> V_8 ;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ )
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_5 ,
F_8 ( V_7 -> V_41 [ V_40 ] ) ) ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_6 ) ;
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_35 - V_5 ) ;
}
static T_1 F_9 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_5 [ 71 + V_39 * 40 ] , * V_35 = V_5 ;
int V_40 ;
struct V_6 * V_7 = V_1 -> V_8 ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
F_10 () ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_7 ,
V_7 -> V_46 . V_47 + 1 ) ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 ,
L_8 ) ;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ ) {
V_43 = F_11 ( V_7 -> V_46 . V_43 [ V_40 ] ) ;
V_45 = F_11 ( V_7 -> V_46 . V_45 [ V_40 ] ) ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_9 , V_40 ) ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_10 , ! ! V_43 ) ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_11 ,
V_43 ? V_43 -> V_48 : 0 ) ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_12 ,
V_43 ? V_43 -> V_49 : 0 ) ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_10 , ! ! V_45 ) ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_11 ,
V_45 ? V_45 -> V_48 : 0 ) ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_13 ,
V_45 ? F_6 ( & V_45 -> V_50 ) : 0 ) ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_6 ) ;
}
F_12 () ;
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_35 - V_5 ) ;
}
static T_1 F_13 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_51 [ 12 ] = {} , * V_5 = V_51 ;
struct V_6 * V_7 = V_1 -> V_8 ;
bool V_52 , V_53 ;
unsigned long V_54 ;
int V_55 ;
if ( V_3 > sizeof( V_51 ) )
return - V_56 ;
if ( F_14 ( V_5 , V_2 , V_3 ) )
return - V_57 ;
V_5 [ sizeof( V_51 ) - 1 ] = '\0' ;
if ( strncmp ( V_5 , L_14 , 3 ) == 0 ) {
V_5 += 3 ;
V_53 = true ;
} else if ( strncmp ( V_5 , L_15 , 3 ) == 0 ) {
V_5 += 3 ;
V_53 = false ;
} else
return - V_56 ;
if ( strncmp ( V_5 , L_16 , 6 ) == 0 ) {
V_5 += 6 ;
V_52 = true ;
if ( ! V_53 )
return - V_56 ;
} else if ( strncmp ( V_5 , L_17 , 5 ) == 0 ) {
V_5 += 5 ;
V_52 = false ;
} else
return - V_56 ;
V_55 = F_15 ( V_5 , 0 , & V_54 ) ;
if ( V_55 )
return V_55 ;
if ( V_54 >= V_39 )
return - V_56 ;
if ( V_53 ) {
if ( V_52 )
V_55 = F_16 ( & V_7 -> V_7 , V_54 , 5000 ) ;
else
V_55 = F_17 ( & V_7 -> V_7 , V_54 ) ;
} else {
F_18 ( V_7 , V_54 , V_58 ,
3 , true ) ;
V_55 = 0 ;
}
return V_55 ? : V_3 ;
}
static T_1 F_19 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
#define F_20 ( T_6 , T_7 ) \
do { \
if (_cond) \
p += scnprintf(p, sizeof(buf)+buf-p, "\t" _str "\n"); \
} while (0)
char V_5 [ 512 ] , * V_35 = V_5 ;
int V_40 ;
struct V_6 * V_7 = V_1 -> V_8 ;
struct V_59 * V_60 = & V_7 -> V_7 . V_61 ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_18 ,
V_60 -> V_62 ? L_3 : L_19 ) ;
if ( V_60 -> V_62 ) {
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_20 , V_60 -> V_63 ) ;
F_20 ( ( V_60 -> V_63 & F_21 ( 0 ) ) , L_21 ) ;
F_20 ( ( V_60 -> V_63 & F_21 ( 1 ) ) , L_22 ) ;
F_20 ( ! ( V_60 -> V_63 & F_21 ( 1 ) ) , L_23 ) ;
F_20 ( ( ( V_60 -> V_63 >> 2 ) & 0x3 ) == 0 , L_24 ) ;
F_20 ( ( ( V_60 -> V_63 >> 2 ) & 0x3 ) == 1 , L_25 ) ;
F_20 ( ( ( V_60 -> V_63 >> 2 ) & 0x3 ) == 3 , L_26 ) ;
F_20 ( ( V_60 -> V_63 & F_21 ( 4 ) ) , L_27 ) ;
F_20 ( ( V_60 -> V_63 & F_21 ( 5 ) ) , L_28 ) ;
F_20 ( ( V_60 -> V_63 & F_21 ( 6 ) ) , L_29 ) ;
F_20 ( ( V_60 -> V_63 & F_21 ( 7 ) ) , L_30 ) ;
F_20 ( ( ( V_60 -> V_63 >> 8 ) & 0x3 ) == 0 , L_31 ) ;
F_20 ( ( ( V_60 -> V_63 >> 8 ) & 0x3 ) == 1 , L_32 ) ;
F_20 ( ( ( V_60 -> V_63 >> 8 ) & 0x3 ) == 2 , L_33 ) ;
F_20 ( ( ( V_60 -> V_63 >> 8 ) & 0x3 ) == 3 , L_34 ) ;
F_20 ( ( V_60 -> V_63 & F_21 ( 10 ) ) , L_35 ) ;
F_20 ( ! ( V_60 -> V_63 & F_21 ( 11 ) ) , L_36
L_37 ) ;
F_20 ( ( V_60 -> V_63 & F_21 ( 11 ) ) , L_36
L_38 ) ;
F_20 ( ( V_60 -> V_63 & F_21 ( 12 ) ) , L_39 ) ;
F_20 ( ! ( V_60 -> V_63 & F_21 ( 12 ) ) , L_40 ) ;
F_20 ( ( V_60 -> V_63 & F_21 ( 14 ) ) , L_41 ) ;
F_20 ( ( V_60 -> V_63 & F_21 ( 15 ) ) , L_42 ) ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_43 ,
V_60 -> V_64 , V_60 -> V_65 ) ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_44 ) ;
for ( V_40 = 0 ; V_40 < V_66 ; V_40 ++ )
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_45 ,
V_60 -> V_67 . V_68 [ V_40 ] ) ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_6 ) ;
if ( F_8 ( V_60 -> V_67 . V_69 ) ) {
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 ,
L_46 ,
F_8 ( V_60 -> V_67 . V_69 ) ) ;
}
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_47 ,
V_60 -> V_67 . V_70 ) ;
}
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_35 - V_5 ) ;
}
static T_1 F_22 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_5 [ 128 ] , * V_35 = V_5 ;
struct V_6 * V_7 = V_1 -> V_8 ;
struct V_71 * V_72 = & V_7 -> V_7 . V_73 ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_48 ,
V_72 -> V_74 ? L_3 : L_19 ) ;
if ( V_72 -> V_74 ) {
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_49 , V_72 -> V_63 ) ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_50 ,
F_8 ( V_72 -> V_75 . V_76 ) ) ;
if ( V_72 -> V_75 . V_69 )
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 ,
L_51 ,
F_8 ( V_72 -> V_75 . V_69 ) ) ;
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 , L_52 ,
F_8 ( V_72 -> V_75 . V_77 ) ) ;
if ( V_72 -> V_75 . V_78 )
V_35 += F_3 ( V_35 , sizeof( V_5 ) + V_5 - V_35 ,
L_53 ,
F_8 ( V_72 -> V_75 . V_78 ) ) ;
}
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_35 - V_5 ) ;
}
void F_23 ( struct V_6 * V_7 )
{
struct V_79 * V_80 = V_7 -> V_80 ;
struct V_81 * V_82 = V_7 -> V_82 ;
struct V_83 * V_84 = V_7 -> V_82 -> V_85 . V_86 ;
T_8 V_87 [ 3 * V_88 ] ;
V_7 -> V_85 . V_89 = true ;
if ( ! V_84 )
return;
snprintf ( V_87 , sizeof( V_87 ) , L_54 , V_7 -> V_7 . V_90 ) ;
V_7 -> V_85 . V_91 = F_24 ( V_87 , V_84 ) ;
if ( ! V_7 -> V_85 . V_91 )
return;
F_25 ( V_92 ) ;
F_25 ( V_93 ) ;
F_25 ( V_41 ) ;
F_25 ( V_94 ) ;
F_25 ( V_95 ) ;
F_25 ( V_96 ) ;
F_25 ( V_97 ) ;
F_26 ( V_98 , V_99 ) ;
F_26 ( V_100 , V_100 ) ;
F_26 ( V_38 , V_101 ) ;
if ( sizeof( V_7 -> V_102 ) == sizeof( V_103 ) )
F_27 ( L_55 , 0400 ,
V_7 -> V_85 . V_91 ,
( V_103 * ) & V_7 -> V_102 ) ;
else
F_28 ( L_55 , 0400 ,
V_7 -> V_85 . V_91 ,
( V_104 * ) & V_7 -> V_102 ) ;
F_29 ( V_80 , V_82 , & V_7 -> V_7 , V_7 -> V_85 . V_91 ) ;
}
void F_30 ( struct V_6 * V_7 )
{
struct V_79 * V_80 = V_7 -> V_80 ;
struct V_81 * V_82 = V_7 -> V_82 ;
F_31 ( V_80 , V_82 , & V_7 -> V_7 , V_7 -> V_85 . V_91 ) ;
F_32 ( V_7 -> V_85 . V_91 ) ;
V_7 -> V_85 . V_91 = NULL ;
}
