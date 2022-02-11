static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_5 [ 16 * V_6 ] , * V_7 = V_5 ;
char * V_8 = V_5 + sizeof( V_5 ) - 1 ;
struct V_9 * V_10 = V_1 -> V_11 ;
unsigned int V_12 ;
F_2 ( F_3 ( V_13 ) != V_6 ) ;
for ( V_12 = 0 ; V_12 < V_6 ; V_12 ++ ) {
if ( F_4 ( V_10 , V_12 ) )
V_7 += F_5 ( V_7 , V_8 - V_7 , L_1 ,
V_13 [ V_12 ] ) ;
}
return F_6 ( V_2 , V_3 , V_4 , V_5 , strlen ( V_5 ) ) ;
}
static T_1 F_7 ( struct V_1 * V_1 ,
char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
char V_5 [ 17 * V_14 ] , * V_15 = V_5 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_14 ; V_16 ++ )
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_2 , V_16 ,
F_8 ( & V_10 -> V_17 [ V_16 ] ) +
F_8 ( & V_10 -> V_18 [ V_16 ] ) ) ;
return F_6 ( V_2 , V_3 , V_4 , V_5 , V_15 - V_5 ) ;
}
static T_1 F_9 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_5 [ 15 * V_19 ] , * V_15 = V_5 ;
int V_20 ;
struct V_9 * V_10 = V_1 -> V_11 ;
for ( V_20 = 0 ; V_20 < V_19 ; V_20 ++ )
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_3 ,
F_10 ( V_10 -> V_21 [ V_20 ] ) ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_4 ) ;
return F_6 ( V_2 , V_3 , V_4 , V_5 , V_15 - V_5 ) ;
}
static T_1 F_11 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_5 [ 71 + V_19 * 40 ] , * V_15 = V_5 ;
int V_20 ;
struct V_9 * V_10 = V_1 -> V_11 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
F_12 () ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_5 ,
V_10 -> V_26 . V_27 + 1 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_6 ) ;
for ( V_20 = 0 ; V_20 < V_19 ; V_20 ++ ) {
V_23 = F_13 ( V_10 -> V_26 . V_23 [ V_20 ] ) ;
V_25 = F_13 ( V_10 -> V_26 . V_25 [ V_20 ] ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_7 , V_20 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_8 , ! ! V_23 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_9 ,
V_23 ? V_23 -> V_28 : 0 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_10 ,
V_23 ? V_23 -> V_29 : 0 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_8 , ! ! V_25 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_9 ,
V_25 ? V_25 -> V_28 : 0 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_11 ,
V_25 ? F_8 ( & V_25 -> V_30 ) : 0 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_4 ) ;
}
F_14 () ;
return F_6 ( V_2 , V_3 , V_4 , V_5 , V_15 - V_5 ) ;
}
static T_1 F_15 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_31 [ 25 ] = {} , * V_5 = V_31 ;
struct V_9 * V_10 = V_1 -> V_11 ;
bool V_32 , V_33 ;
unsigned long V_34 ;
char * V_7 ;
int V_35 , V_36 = 5000 ;
if ( V_3 > sizeof( V_31 ) )
return - V_37 ;
if ( F_16 ( V_5 , V_2 , V_3 ) )
return - V_38 ;
V_5 [ sizeof( V_31 ) - 1 ] = '\0' ;
V_7 = V_5 ;
V_5 = F_17 ( & V_7 , L_12 ) ;
if ( ! V_5 )
return - V_37 ;
if ( ! strcmp ( V_5 , L_13 ) )
V_33 = true ;
else if ( ! strcmp ( V_5 , L_14 ) )
V_33 = false ;
else
return - V_37 ;
V_5 = F_17 ( & V_7 , L_12 ) ;
if ( ! V_5 )
return - V_37 ;
if ( ! strcmp ( V_5 , L_15 ) ) {
V_32 = true ;
if ( ! V_33 )
return - V_37 ;
} else if ( ! strcmp ( V_5 , L_16 ) ) {
V_32 = false ;
} else {
return - V_37 ;
}
V_5 = F_17 ( & V_7 , L_12 ) ;
if ( ! V_5 )
return - V_37 ;
if ( sscanf ( V_5 , L_17 , & V_36 ) == 1 ) {
V_5 = F_17 ( & V_7 , L_12 ) ;
if ( ! V_5 || ! V_33 || ! V_32 )
return - V_37 ;
}
V_35 = F_18 ( V_5 , 0 , & V_34 ) ;
if ( V_35 || V_34 >= V_19 )
return - V_37 ;
if ( V_33 ) {
if ( V_32 )
V_35 = F_19 ( & V_10 -> V_10 , V_34 ,
V_36 ) ;
else
V_35 = F_20 ( & V_10 -> V_10 , V_34 ) ;
} else {
F_21 ( V_10 , V_34 , V_39 ,
3 , true ) ;
V_35 = 0 ;
}
return V_35 ? : V_3 ;
}
static T_1 F_22 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
#define F_23 ( T_5 , T_6 ) \
do { \
if (_cond) \
p += scnprintf(p, sizeof(buf)+buf-p, "\t" _str "\n"); \
} while (0)
char V_5 [ 512 ] , * V_15 = V_5 ;
int V_20 ;
struct V_9 * V_10 = V_1 -> V_11 ;
struct V_40 * V_41 = & V_10 -> V_10 . V_42 ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_18 ,
V_41 -> V_43 ? L_19 : L_20 ) ;
if ( V_41 -> V_43 ) {
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_21 , V_41 -> V_44 ) ;
F_23 ( ( V_41 -> V_44 & F_24 ( 0 ) ) , L_22 ) ;
F_23 ( ( V_41 -> V_44 & F_24 ( 1 ) ) , L_23 ) ;
F_23 ( ! ( V_41 -> V_44 & F_24 ( 1 ) ) , L_24 ) ;
F_23 ( ( ( V_41 -> V_44 >> 2 ) & 0x3 ) == 0 , L_25 ) ;
F_23 ( ( ( V_41 -> V_44 >> 2 ) & 0x3 ) == 1 , L_26 ) ;
F_23 ( ( ( V_41 -> V_44 >> 2 ) & 0x3 ) == 3 , L_27 ) ;
F_23 ( ( V_41 -> V_44 & F_24 ( 4 ) ) , L_28 ) ;
F_23 ( ( V_41 -> V_44 & F_24 ( 5 ) ) , L_29 ) ;
F_23 ( ( V_41 -> V_44 & F_24 ( 6 ) ) , L_30 ) ;
F_23 ( ( V_41 -> V_44 & F_24 ( 7 ) ) , L_31 ) ;
F_23 ( ( ( V_41 -> V_44 >> 8 ) & 0x3 ) == 0 , L_32 ) ;
F_23 ( ( ( V_41 -> V_44 >> 8 ) & 0x3 ) == 1 , L_33 ) ;
F_23 ( ( ( V_41 -> V_44 >> 8 ) & 0x3 ) == 2 , L_34 ) ;
F_23 ( ( ( V_41 -> V_44 >> 8 ) & 0x3 ) == 3 , L_35 ) ;
F_23 ( ( V_41 -> V_44 & F_24 ( 10 ) ) , L_36 ) ;
F_23 ( ! ( V_41 -> V_44 & F_24 ( 11 ) ) , L_37
L_38 ) ;
F_23 ( ( V_41 -> V_44 & F_24 ( 11 ) ) , L_37
L_39 ) ;
F_23 ( ( V_41 -> V_44 & F_24 ( 12 ) ) , L_40 ) ;
F_23 ( ! ( V_41 -> V_44 & F_24 ( 12 ) ) , L_41 ) ;
F_23 ( ( V_41 -> V_44 & F_24 ( 14 ) ) , L_42 ) ;
F_23 ( ( V_41 -> V_44 & F_24 ( 15 ) ) , L_43 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_44 ,
V_41 -> V_45 , V_41 -> V_46 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_45 ) ;
for ( V_20 = 0 ; V_20 < V_47 ; V_20 ++ )
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_46 ,
V_41 -> V_48 . V_49 [ V_20 ] ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_4 ) ;
if ( F_10 ( V_41 -> V_48 . V_50 ) ) {
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_47 ,
F_10 ( V_41 -> V_48 . V_50 ) ) ;
}
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_48 ,
V_41 -> V_48 . V_51 ) ;
}
return F_6 ( V_2 , V_3 , V_4 , V_5 , V_15 - V_5 ) ;
}
static T_1 F_25 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_5 [ 512 ] , * V_15 = V_5 ;
struct V_9 * V_10 = V_1 -> V_11 ;
struct V_52 * V_53 = & V_10 -> V_10 . V_54 ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_49 ,
V_53 -> V_55 ? L_19 : L_20 ) ;
if ( V_53 -> V_55 ) {
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_50 ,
V_53 -> V_44 ) ;
#define F_26 ( T_7 , T_8 ) \
do { \
if (vhtc->cap & IEEE80211_VHT_CAP_ ## a) \
p += scnprintf(p, sizeof(buf) + buf - p, \
"\t\t%s\n", b); \
} while (0)
switch ( V_53 -> V_44 & 0x3 ) {
case V_56 :
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_51 ) ;
break;
case V_57 :
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_52 ) ;
break;
case V_58 :
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_53 ) ;
break;
default:
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_54 ) ;
} ;
switch ( V_53 -> V_44 & V_59 ) {
case 0 :
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_55 ) ;
break;
case V_60 :
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_56 ) ;
break;
case V_61 :
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_57 ) ;
break;
default:
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_58 ,
( V_53 -> V_44 >> 2 ) & 0x3 ) ;
} ;
F_26 ( V_62 , L_59 ) ;
F_26 ( V_63 , L_60 ) ;
F_26 ( V_64 , L_61 ) ;
F_26 ( V_65 , L_62 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_63 , ( V_53 -> V_44 >> 8 ) & 0x7 ) ;
F_26 ( V_66 , L_64 ) ;
F_26 ( V_67 , L_65 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_66 ,
( V_53 -> V_44 & V_68 ) >>
V_69 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_67 ,
( V_53 -> V_44 & V_70 )
>> V_71 ) ;
F_26 ( V_72 , L_68 ) ;
F_26 ( V_73 , L_69 ) ;
F_26 ( V_74 , L_70 ) ;
F_26 ( V_75 , L_71 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_72 ,
( V_53 -> V_44 & V_76 ) >>
V_77 ) ;
F_26 ( V_78 ,
L_73 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_74 ,
( V_53 -> V_44 & V_79 ) >> 26 ) ;
F_26 ( V_80 , L_75 ) ;
F_26 ( V_81 , L_76 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_77 ,
F_10 ( V_53 -> V_82 . V_83 ) ) ;
if ( V_53 -> V_82 . V_50 )
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_78 ,
F_10 ( V_53 -> V_82 . V_50 ) ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_79 ,
F_10 ( V_53 -> V_82 . V_84 ) ) ;
if ( V_53 -> V_82 . V_85 )
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_80 ,
F_10 ( V_53 -> V_82 . V_85 ) ) ;
}
return F_6 ( V_2 , V_3 , V_4 , V_5 , V_15 - V_5 ) ;
}
void F_27 ( struct V_9 * V_10 )
{
struct V_86 * V_87 = V_10 -> V_87 ;
struct V_88 * V_89 = V_10 -> V_89 ;
struct V_90 * V_91 = V_10 -> V_89 -> V_92 . V_93 ;
T_9 V_94 [ 3 * V_95 ] ;
if ( ! V_91 )
return;
snprintf ( V_94 , sizeof( V_94 ) , L_81 , V_10 -> V_10 . V_96 ) ;
V_10 -> V_97 = F_28 ( V_94 , V_91 ) ;
if ( ! V_10 -> V_97 )
return;
F_29 ( V_98 ) ;
F_29 ( V_99 ) ;
F_29 ( V_21 ) ;
F_29 ( V_100 ) ;
F_29 ( V_101 ) ;
F_29 ( V_102 ) ;
F_30 ( V_103 , V_104 . V_105 ) ;
F_30 ( V_106 , V_104 . V_107 ) ;
F_30 ( V_18 , V_108 . V_109 ) ;
if ( sizeof( V_10 -> V_110 ) == sizeof( V_111 ) )
F_31 ( L_82 , 0400 ,
V_10 -> V_97 ,
( V_111 * ) & V_10 -> V_110 ) ;
else
F_32 ( L_82 , 0400 ,
V_10 -> V_97 ,
( V_112 * ) & V_10 -> V_110 ) ;
F_33 ( V_87 , V_89 , & V_10 -> V_10 , V_10 -> V_97 ) ;
}
void F_34 ( struct V_9 * V_10 )
{
struct V_86 * V_87 = V_10 -> V_87 ;
struct V_88 * V_89 = V_10 -> V_89 ;
F_35 ( V_87 , V_89 , & V_10 -> V_10 , V_10 -> V_97 ) ;
F_36 ( V_10 -> V_97 ) ;
V_10 -> V_97 = NULL ;
}
