static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_5 [ 100 ] ;
struct V_6 * V_7 = V_1 -> V_8 ;
T_5 V_9 = F_2 ( V_7 ) ;
int V_10 = F_3 ( V_5 , sizeof( V_5 ) , L_1 ,
V_9 & V_11 ? L_2 : L_3 ,
V_9 & V_12 ? L_4 : L_3 ,
V_9 & V_13 ? L_5 : L_3 ,
V_9 & V_14 ? L_6 : L_3 ,
V_9 & V_15 ? L_7 : L_3 ,
V_9 & V_16 ? L_8 : L_3 ,
V_9 & V_17 ? L_9 : L_3 ,
V_9 & V_18 ? L_10 : L_3 ,
V_9 & V_19 ? L_11 : L_3 ) ;
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_10 ) ;
}
static T_1 F_5 ( struct V_1 * V_1 ,
char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
return F_6 ( V_2 , V_3 , V_4 , L_12 ,
F_7 ( & V_7 -> V_20 ) ) ;
}
static T_1 F_8 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
return F_6 ( V_2 , V_3 , V_4 , L_13 ,
F_9 ( V_21 - V_7 -> V_22 ) ) ;
}
static T_1 F_10 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
struct V_23 V_24 ;
struct V_25 V_26 ;
long V_27 ;
char V_5 [ 100 ] ;
int V_10 ;
F_11 ( & V_24 ) ;
V_27 = V_24 . V_28 - V_7 -> V_29 ;
F_12 ( V_27 , 0 , & V_26 ) ;
V_26 . V_30 -= 70 ;
V_26 . V_31 -= 1 ;
V_10 = F_3 ( V_5 , sizeof( V_5 ) ,
L_14 ,
V_26 . V_30 , V_26 . V_32 , V_26 . V_31 ,
V_26 . V_33 , V_26 . V_34 , V_26 . V_35 ) ;
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_10 ) ;
}
static T_1 F_13 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_5 [ 15 * V_36 ] , * V_37 = V_5 ;
int V_38 ;
struct V_6 * V_7 = V_1 -> V_8 ;
for ( V_38 = 0 ; V_38 < V_36 ; V_38 ++ )
V_37 += F_3 ( V_37 , sizeof( V_5 ) + V_5 - V_37 , L_15 ,
F_14 ( V_7 -> V_39 [ V_38 ] ) ) ;
V_37 += F_3 ( V_37 , sizeof( V_5 ) + V_5 - V_37 , L_16 ) ;
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_37 - V_5 ) ;
}
static T_1 F_15 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_5 [ 71 + V_40 * 40 ] , * V_37 = V_5 ;
int V_38 ;
struct V_6 * V_7 = V_1 -> V_8 ;
struct V_41 * V_42 ;
struct V_43 * V_44 ;
F_16 () ;
V_37 += F_3 ( V_37 , sizeof( V_5 ) + V_5 - V_37 , L_17 ,
V_7 -> V_45 . V_46 + 1 ) ;
V_37 += F_3 ( V_37 , sizeof( V_5 ) + V_5 - V_37 ,
L_18 ) ;
for ( V_38 = 0 ; V_38 < V_40 ; V_38 ++ ) {
V_42 = F_17 ( V_7 -> V_45 . V_42 [ V_38 ] ) ;
V_44 = F_17 ( V_7 -> V_45 . V_44 [ V_38 ] ) ;
V_37 += F_3 ( V_37 , sizeof( V_5 ) + V_5 - V_37 , L_19 , V_38 ) ;
V_37 += F_3 ( V_37 , sizeof( V_5 ) + V_5 - V_37 , L_20 , ! ! V_42 ) ;
V_37 += F_3 ( V_37 , sizeof( V_5 ) + V_5 - V_37 , L_21 ,
V_42 ? V_42 -> V_47 : 0 ) ;
V_37 += F_3 ( V_37 , sizeof( V_5 ) + V_5 - V_37 , L_22 ,
V_42 ? V_42 -> V_48 : 0 ) ;
V_37 += F_3 ( V_37 , sizeof( V_5 ) + V_5 - V_37 , L_20 , ! ! V_44 ) ;
V_37 += F_3 ( V_37 , sizeof( V_5 ) + V_5 - V_37 , L_21 ,
V_44 ? V_44 -> V_47 : 0 ) ;
V_37 += F_3 ( V_37 , sizeof( V_5 ) + V_5 - V_37 , L_23 ,
V_44 ? F_7 ( & V_44 -> V_49 ) : 0 ) ;
V_37 += F_3 ( V_37 , sizeof( V_5 ) + V_5 - V_37 , L_16 ) ;
}
F_18 () ;
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_37 - V_5 ) ;
}
static T_1 F_19 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_50 [ 12 ] , * V_5 = V_50 ;
struct V_6 * V_7 = V_1 -> V_8 ;
bool V_51 , V_52 ;
unsigned long V_53 ;
int V_54 ;
if ( V_3 > sizeof( V_50 ) )
return - V_55 ;
if ( F_20 ( V_5 , V_2 , V_3 ) )
return - V_56 ;
V_5 [ sizeof( V_50 ) - 1 ] = '\0' ;
if ( strncmp ( V_5 , L_24 , 3 ) == 0 ) {
V_5 += 3 ;
V_52 = true ;
} else if ( strncmp ( V_5 , L_25 , 3 ) == 0 ) {
V_5 += 3 ;
V_52 = false ;
} else
return - V_55 ;
if ( strncmp ( V_5 , L_26 , 6 ) == 0 ) {
V_5 += 6 ;
V_51 = true ;
if ( ! V_52 )
return - V_55 ;
} else if ( strncmp ( V_5 , L_27 , 5 ) == 0 ) {
V_5 += 5 ;
V_51 = false ;
} else
return - V_55 ;
V_53 = F_21 ( V_5 , NULL , 0 ) ;
if ( V_53 >= V_40 )
return - V_55 ;
if ( V_52 ) {
if ( V_51 )
V_54 = F_22 ( & V_7 -> V_7 , V_53 , 5000 ) ;
else
V_54 = F_23 ( & V_7 -> V_7 , V_53 ) ;
} else {
F_24 ( V_7 , V_53 , V_57 ,
3 , true ) ;
V_54 = 0 ;
}
return V_54 ? : V_3 ;
}
static T_1 F_25 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
#define F_26 ( T_6 , T_7 ) \
do { \
if (_cond) \
p += scnprintf(p, sizeof(buf)+buf-p, "\t" _str "\n"); \
} while (0)
char V_5 [ 512 ] , * V_37 = V_5 ;
int V_38 ;
struct V_6 * V_7 = V_1 -> V_8 ;
struct V_58 * V_59 = & V_7 -> V_7 . V_60 ;
V_37 += F_3 ( V_37 , sizeof( V_5 ) + V_5 - V_37 , L_28 ,
V_59 -> V_61 ? L_3 : L_29 ) ;
if ( V_59 -> V_61 ) {
V_37 += F_3 ( V_37 , sizeof( V_5 ) + V_5 - V_37 , L_30 , V_59 -> V_62 ) ;
F_26 ( ( V_59 -> V_62 & F_27 ( 0 ) ) , L_31 ) ;
F_26 ( ( V_59 -> V_62 & F_27 ( 1 ) ) , L_32 ) ;
F_26 ( ! ( V_59 -> V_62 & F_27 ( 1 ) ) , L_33 ) ;
F_26 ( ( ( V_59 -> V_62 >> 2 ) & 0x3 ) == 0 , L_34 ) ;
F_26 ( ( ( V_59 -> V_62 >> 2 ) & 0x3 ) == 1 , L_35 ) ;
F_26 ( ( ( V_59 -> V_62 >> 2 ) & 0x3 ) == 3 , L_36 ) ;
F_26 ( ( V_59 -> V_62 & F_27 ( 4 ) ) , L_37 ) ;
F_26 ( ( V_59 -> V_62 & F_27 ( 5 ) ) , L_38 ) ;
F_26 ( ( V_59 -> V_62 & F_27 ( 6 ) ) , L_39 ) ;
F_26 ( ( V_59 -> V_62 & F_27 ( 7 ) ) , L_40 ) ;
F_26 ( ( ( V_59 -> V_62 >> 8 ) & 0x3 ) == 0 , L_41 ) ;
F_26 ( ( ( V_59 -> V_62 >> 8 ) & 0x3 ) == 1 , L_42 ) ;
F_26 ( ( ( V_59 -> V_62 >> 8 ) & 0x3 ) == 2 , L_43 ) ;
F_26 ( ( ( V_59 -> V_62 >> 8 ) & 0x3 ) == 3 , L_44 ) ;
F_26 ( ( V_59 -> V_62 & F_27 ( 10 ) ) , L_45 ) ;
F_26 ( ( V_59 -> V_62 & F_27 ( 11 ) ) , L_46
L_47 ) ;
F_26 ( ! ( V_59 -> V_62 & F_27 ( 11 ) ) , L_46
L_48 ) ;
F_26 ( ( V_59 -> V_62 & F_27 ( 12 ) ) , L_49 ) ;
F_26 ( ! ( V_59 -> V_62 & F_27 ( 12 ) ) , L_50 ) ;
F_26 ( ( V_59 -> V_62 & F_27 ( 14 ) ) , L_51 ) ;
F_26 ( ( V_59 -> V_62 & F_27 ( 15 ) ) , L_52 ) ;
V_37 += F_3 ( V_37 , sizeof( V_5 ) + V_5 - V_37 , L_53 ,
V_59 -> V_63 , V_59 -> V_64 ) ;
V_37 += F_3 ( V_37 , sizeof( V_5 ) + V_5 - V_37 , L_54 ) ;
for ( V_38 = 0 ; V_38 < V_65 ; V_38 ++ )
V_37 += F_3 ( V_37 , sizeof( V_5 ) + V_5 - V_37 , L_55 ,
V_59 -> V_66 . V_67 [ V_38 ] ) ;
V_37 += F_3 ( V_37 , sizeof( V_5 ) + V_5 - V_37 , L_16 ) ;
if ( F_14 ( V_59 -> V_66 . V_68 ) ) {
V_37 += F_3 ( V_37 , sizeof( V_5 ) + V_5 - V_37 ,
L_56 ,
F_14 ( V_59 -> V_66 . V_68 ) ) ;
}
V_37 += F_3 ( V_37 , sizeof( V_5 ) + V_5 - V_37 , L_57 ,
V_59 -> V_66 . V_69 ) ;
}
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_37 - V_5 ) ;
}
void F_28 ( struct V_6 * V_7 )
{
struct V_70 * V_71 = V_7 -> V_72 -> V_73 . V_74 ;
T_8 V_75 [ 3 * V_76 ] ;
V_7 -> V_73 . V_77 = true ;
if ( ! V_71 )
return;
snprintf ( V_75 , sizeof( V_75 ) , L_58 , V_7 -> V_7 . V_78 ) ;
V_7 -> V_73 . V_79 = F_29 ( V_75 , V_71 ) ;
if ( ! V_7 -> V_73 . V_79 )
return;
F_30 ( V_80 ) ;
F_30 ( V_81 ) ;
F_30 ( V_82 ) ;
F_30 ( V_83 ) ;
F_30 ( V_39 ) ;
F_30 ( V_84 ) ;
F_30 ( V_85 ) ;
F_30 ( V_86 ) ;
F_30 ( V_87 ) ;
F_31 ( V_88 , V_88 ) ;
F_31 ( V_89 , V_89 ) ;
F_31 ( V_90 , V_90 ) ;
F_31 ( V_91 , V_91 ) ;
F_31 ( V_92 , V_93 ) ;
F_31 ( V_94 , V_94 ) ;
F_31 ( V_95 , V_95 ) ;
F_31 ( V_96 , V_96 ) ;
F_31 ( V_97 , V_98 ) ;
F_31 ( V_99 , V_99 ) ;
F_31 ( V_100 , V_100 ) ;
F_31 ( V_101 , V_101 ) ;
}
void F_32 ( struct V_6 * V_7 )
{
F_33 ( V_7 -> V_73 . V_79 ) ;
V_7 -> V_73 . V_79 = NULL ;
}
