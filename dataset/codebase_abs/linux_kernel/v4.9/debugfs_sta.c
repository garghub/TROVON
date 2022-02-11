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
struct V_9 * V_10 = V_1 -> V_11 ;
struct V_22 * V_23 = V_10 -> V_23 ;
T_3 V_24 = V_25 * ( V_19 + 1 ) ;
char * V_5 = F_12 ( V_24 , V_26 ) , * V_15 = V_5 ;
struct V_27 * V_28 ;
T_1 V_29 ;
int V_20 ;
if ( ! V_5 )
return - V_30 ;
F_13 ( & V_23 -> V_31 . V_32 ) ;
F_14 () ;
V_15 += F_5 ( V_15 ,
V_24 + V_5 - V_15 ,
L_5 ) ;
for ( V_20 = 0 ; V_20 < V_19 ; V_20 ++ ) {
V_28 = F_15 ( V_10 -> V_10 . V_33 [ V_20 ] ) ;
V_15 += F_5 ( V_15 , V_24 + V_5 - V_15 ,
L_6 ,
V_28 -> V_33 . V_34 ,
V_28 -> V_33 . V_16 ,
V_28 -> V_35 . V_36 ,
V_28 -> V_35 . V_37 ,
V_28 -> V_35 . V_38 ,
V_28 -> V_39 . V_40 ,
V_28 -> V_39 . V_41 ,
V_28 -> V_35 . V_42 ,
V_28 -> V_35 . V_43 ,
V_28 -> V_35 . V_44 ,
V_28 -> V_35 . V_45 ) ;
}
F_16 () ;
F_17 ( & V_23 -> V_31 . V_32 ) ;
V_29 = F_6 ( V_2 , V_3 , V_4 , V_5 , V_15 - V_5 ) ;
F_18 ( V_5 ) ;
return V_29 ;
}
static T_1 F_19 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_5 [ 71 + V_19 * 40 ] , * V_15 = V_5 ;
int V_20 ;
struct V_9 * V_10 = V_1 -> V_11 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
F_14 () ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_7 ,
V_10 -> V_50 . V_51 + 1 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_8 ) ;
for ( V_20 = 0 ; V_20 < V_19 ; V_20 ++ ) {
V_47 = F_20 ( V_10 -> V_50 . V_47 [ V_20 ] ) ;
V_49 = F_20 ( V_10 -> V_50 . V_49 [ V_20 ] ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_9 , V_20 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_10 , ! ! V_47 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_11 ,
V_47 ? V_47 -> V_52 : 0 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_12 ,
V_47 ? V_47 -> V_53 : 0 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_10 , ! ! V_49 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_11 ,
V_49 ? V_49 -> V_52 : 0 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_13 ,
V_49 ? F_8 ( & V_49 -> V_54 ) : 0 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_4 ) ;
}
F_16 () ;
return F_6 ( V_2 , V_3 , V_4 , V_5 , V_15 - V_5 ) ;
}
static T_1 F_21 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_55 [ 25 ] = {} , * V_5 = V_55 ;
struct V_9 * V_10 = V_1 -> V_11 ;
bool V_56 , V_57 ;
unsigned long V_34 ;
char * V_7 ;
int V_58 , V_59 = 5000 ;
if ( V_3 > sizeof( V_55 ) )
return - V_60 ;
if ( F_22 ( V_5 , V_2 , V_3 ) )
return - V_61 ;
V_5 [ sizeof( V_55 ) - 1 ] = '\0' ;
V_7 = V_5 ;
V_5 = F_23 ( & V_7 , L_14 ) ;
if ( ! V_5 )
return - V_60 ;
if ( ! strcmp ( V_5 , L_15 ) )
V_57 = true ;
else if ( ! strcmp ( V_5 , L_16 ) )
V_57 = false ;
else
return - V_60 ;
V_5 = F_23 ( & V_7 , L_14 ) ;
if ( ! V_5 )
return - V_60 ;
if ( ! strcmp ( V_5 , L_17 ) ) {
V_56 = true ;
if ( ! V_57 )
return - V_60 ;
} else if ( ! strcmp ( V_5 , L_18 ) ) {
V_56 = false ;
} else {
return - V_60 ;
}
V_5 = F_23 ( & V_7 , L_14 ) ;
if ( ! V_5 )
return - V_60 ;
if ( sscanf ( V_5 , L_19 , & V_59 ) == 1 ) {
V_5 = F_23 ( & V_7 , L_14 ) ;
if ( ! V_5 || ! V_57 || ! V_56 )
return - V_60 ;
}
V_58 = F_24 ( V_5 , 0 , & V_34 ) ;
if ( V_58 || V_34 >= V_19 )
return - V_60 ;
if ( V_57 ) {
if ( V_56 )
V_58 = F_25 ( & V_10 -> V_10 , V_34 ,
V_59 ) ;
else
V_58 = F_26 ( & V_10 -> V_10 , V_34 ) ;
} else {
F_27 ( V_10 , V_34 , V_62 ,
3 , true ) ;
V_58 = 0 ;
}
return V_58 ? : V_3 ;
}
static T_1 F_28 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
#define F_29 ( T_5 , T_6 ) \
do { \
if (_cond) \
p += scnprintf(p, sizeof(buf)+buf-p, "\t" _str "\n"); \
} while (0)
char V_5 [ 512 ] , * V_15 = V_5 ;
int V_20 ;
struct V_9 * V_10 = V_1 -> V_11 ;
struct V_63 * V_64 = & V_10 -> V_10 . V_65 ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_20 ,
V_64 -> V_66 ? L_21 : L_22 ) ;
if ( V_64 -> V_66 ) {
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_23 , V_64 -> V_67 ) ;
F_29 ( ( V_64 -> V_67 & F_30 ( 0 ) ) , L_24 ) ;
F_29 ( ( V_64 -> V_67 & F_30 ( 1 ) ) , L_25 ) ;
F_29 ( ! ( V_64 -> V_67 & F_30 ( 1 ) ) , L_26 ) ;
F_29 ( ( ( V_64 -> V_67 >> 2 ) & 0x3 ) == 0 , L_27 ) ;
F_29 ( ( ( V_64 -> V_67 >> 2 ) & 0x3 ) == 1 , L_28 ) ;
F_29 ( ( ( V_64 -> V_67 >> 2 ) & 0x3 ) == 3 , L_29 ) ;
F_29 ( ( V_64 -> V_67 & F_30 ( 4 ) ) , L_30 ) ;
F_29 ( ( V_64 -> V_67 & F_30 ( 5 ) ) , L_31 ) ;
F_29 ( ( V_64 -> V_67 & F_30 ( 6 ) ) , L_32 ) ;
F_29 ( ( V_64 -> V_67 & F_30 ( 7 ) ) , L_33 ) ;
F_29 ( ( ( V_64 -> V_67 >> 8 ) & 0x3 ) == 0 , L_34 ) ;
F_29 ( ( ( V_64 -> V_67 >> 8 ) & 0x3 ) == 1 , L_35 ) ;
F_29 ( ( ( V_64 -> V_67 >> 8 ) & 0x3 ) == 2 , L_36 ) ;
F_29 ( ( ( V_64 -> V_67 >> 8 ) & 0x3 ) == 3 , L_37 ) ;
F_29 ( ( V_64 -> V_67 & F_30 ( 10 ) ) , L_38 ) ;
F_29 ( ! ( V_64 -> V_67 & F_30 ( 11 ) ) , L_39
L_40 ) ;
F_29 ( ( V_64 -> V_67 & F_30 ( 11 ) ) , L_39
L_41 ) ;
F_29 ( ( V_64 -> V_67 & F_30 ( 12 ) ) , L_42 ) ;
F_29 ( ! ( V_64 -> V_67 & F_30 ( 12 ) ) , L_43 ) ;
F_29 ( ( V_64 -> V_67 & F_30 ( 14 ) ) , L_44 ) ;
F_29 ( ( V_64 -> V_67 & F_30 ( 15 ) ) , L_45 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_46 ,
V_64 -> V_68 , V_64 -> V_69 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_47 ) ;
for ( V_20 = 0 ; V_20 < V_70 ; V_20 ++ )
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_48 ,
V_64 -> V_71 . V_72 [ V_20 ] ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_4 ) ;
if ( F_10 ( V_64 -> V_71 . V_73 ) ) {
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_49 ,
F_10 ( V_64 -> V_71 . V_73 ) ) ;
}
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_50 ,
V_64 -> V_71 . V_74 ) ;
}
return F_6 ( V_2 , V_3 , V_4 , V_5 , V_15 - V_5 ) ;
}
static T_1 F_31 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_5 [ 512 ] , * V_15 = V_5 ;
struct V_9 * V_10 = V_1 -> V_11 ;
struct V_75 * V_76 = & V_10 -> V_10 . V_77 ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_51 ,
V_76 -> V_78 ? L_21 : L_22 ) ;
if ( V_76 -> V_78 ) {
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_52 ,
V_76 -> V_67 ) ;
#define F_32 ( T_7 , T_8 ) \
do { \
if (vhtc->cap & IEEE80211_VHT_CAP_ ## a) \
p += scnprintf(p, sizeof(buf) + buf - p, \
"\t\t%s\n", b); \
} while (0)
switch ( V_76 -> V_67 & 0x3 ) {
case V_79 :
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_53 ) ;
break;
case V_80 :
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_54 ) ;
break;
case V_81 :
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_55 ) ;
break;
default:
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_56 ) ;
} ;
switch ( V_76 -> V_67 & V_82 ) {
case 0 :
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_57 ) ;
break;
case V_83 :
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_58 ) ;
break;
case V_84 :
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_59 ) ;
break;
default:
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_60 ,
( V_76 -> V_67 >> 2 ) & 0x3 ) ;
} ;
F_32 ( V_85 , L_61 ) ;
F_32 ( V_86 , L_62 ) ;
F_32 ( V_87 , L_63 ) ;
F_32 ( V_88 , L_64 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_65 , ( V_76 -> V_67 >> 8 ) & 0x7 ) ;
F_32 ( V_89 , L_66 ) ;
F_32 ( V_90 , L_67 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_68 ,
( V_76 -> V_67 & V_91 ) >>
V_92 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_69 ,
( V_76 -> V_67 & V_93 )
>> V_94 ) ;
F_32 ( V_95 , L_70 ) ;
F_32 ( V_96 , L_71 ) ;
F_32 ( V_97 , L_72 ) ;
F_32 ( V_98 , L_73 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_74 ,
( V_76 -> V_67 & V_99 ) >>
V_100 ) ;
F_32 ( V_101 ,
L_75 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_76 ,
( V_76 -> V_67 & V_102 ) >> 26 ) ;
F_32 ( V_103 , L_77 ) ;
F_32 ( V_104 , L_78 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_79 ,
F_10 ( V_76 -> V_105 . V_106 ) ) ;
if ( V_76 -> V_105 . V_73 )
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_80 ,
F_10 ( V_76 -> V_105 . V_73 ) ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_81 ,
F_10 ( V_76 -> V_105 . V_107 ) ) ;
if ( V_76 -> V_105 . V_108 )
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_82 ,
F_10 ( V_76 -> V_105 . V_108 ) ) ;
}
return F_6 ( V_2 , V_3 , V_4 , V_5 , V_15 - V_5 ) ;
}
void F_33 ( struct V_9 * V_10 )
{
struct V_22 * V_23 = V_10 -> V_23 ;
struct V_109 * V_110 = V_10 -> V_110 ;
struct V_111 * V_112 = V_10 -> V_110 -> V_113 . V_114 ;
T_9 V_115 [ 3 * V_116 ] ;
if ( ! V_112 )
return;
snprintf ( V_115 , sizeof( V_115 ) , L_83 , V_10 -> V_10 . V_117 ) ;
V_10 -> V_118 = F_34 ( V_115 , V_112 ) ;
if ( ! V_10 -> V_118 )
return;
F_35 ( V_119 ) ;
F_35 ( V_120 ) ;
F_35 ( V_21 ) ;
F_35 ( V_121 ) ;
F_35 ( V_122 ) ;
F_35 ( V_123 ) ;
F_36 ( V_124 , V_125 . V_126 ) ;
F_36 ( V_127 , V_125 . V_128 ) ;
F_36 ( V_18 , V_129 . V_130 ) ;
if ( V_23 -> V_131 -> V_132 )
F_35 ( V_133 ) ;
if ( sizeof( V_10 -> V_134 ) == sizeof( V_135 ) )
F_37 ( L_84 , 0400 ,
V_10 -> V_118 ,
( V_135 * ) & V_10 -> V_134 ) ;
else
F_38 ( L_84 , 0400 ,
V_10 -> V_118 ,
( V_136 * ) & V_10 -> V_134 ) ;
F_39 ( V_23 , V_110 , & V_10 -> V_10 , V_10 -> V_118 ) ;
}
void F_40 ( struct V_9 * V_10 )
{
F_41 ( V_10 -> V_118 ) ;
V_10 -> V_118 = NULL ;
}
