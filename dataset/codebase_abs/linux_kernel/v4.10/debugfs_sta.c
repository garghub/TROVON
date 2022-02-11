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
bool V_52 ;
V_47 = F_20 ( V_10 -> V_50 . V_47 [ V_20 ] ) ;
V_49 = F_20 ( V_10 -> V_50 . V_49 [ V_20 ] ) ;
V_52 = F_21 ( V_20 , V_10 -> V_50 . V_53 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_9 , V_20 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_10 ,
V_52 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_11 ,
V_52 ?
V_10 -> V_50 . V_54 [ V_20 ] : 0 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_12 ,
V_47 ? V_47 -> V_55 : 0 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_10 , ! ! V_49 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_11 ,
V_49 ? V_49 -> V_56 : 0 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_13 ,
V_49 ? F_8 ( & V_49 -> V_57 ) : 0 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_4 ) ;
}
F_16 () ;
return F_6 ( V_2 , V_3 , V_4 , V_5 , V_15 - V_5 ) ;
}
static T_1 F_22 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_58 [ 25 ] = {} , * V_5 = V_58 ;
struct V_9 * V_10 = V_1 -> V_11 ;
bool V_59 , V_60 ;
unsigned long V_34 ;
char * V_7 ;
int V_61 , V_62 = 5000 ;
if ( V_3 > sizeof( V_58 ) )
return - V_63 ;
if ( F_23 ( V_5 , V_2 , V_3 ) )
return - V_64 ;
V_5 [ sizeof( V_58 ) - 1 ] = '\0' ;
V_7 = V_5 ;
V_5 = F_24 ( & V_7 , L_14 ) ;
if ( ! V_5 )
return - V_63 ;
if ( ! strcmp ( V_5 , L_15 ) )
V_60 = true ;
else if ( ! strcmp ( V_5 , L_16 ) )
V_60 = false ;
else
return - V_63 ;
V_5 = F_24 ( & V_7 , L_14 ) ;
if ( ! V_5 )
return - V_63 ;
if ( ! strcmp ( V_5 , L_17 ) ) {
V_59 = true ;
if ( ! V_60 )
return - V_63 ;
} else if ( ! strcmp ( V_5 , L_18 ) ) {
V_59 = false ;
} else {
return - V_63 ;
}
V_5 = F_24 ( & V_7 , L_14 ) ;
if ( ! V_5 )
return - V_63 ;
if ( sscanf ( V_5 , L_19 , & V_62 ) == 1 ) {
V_5 = F_24 ( & V_7 , L_14 ) ;
if ( ! V_5 || ! V_60 || ! V_59 )
return - V_63 ;
}
V_61 = F_25 ( V_5 , 0 , & V_34 ) ;
if ( V_61 || V_34 >= V_19 )
return - V_63 ;
if ( V_60 ) {
if ( V_59 )
V_61 = F_26 ( & V_10 -> V_10 , V_34 ,
V_62 ) ;
else
V_61 = F_27 ( & V_10 -> V_10 , V_34 ) ;
} else {
F_28 ( V_10 , V_34 , V_65 ,
3 , true ) ;
V_61 = 0 ;
}
return V_61 ? : V_3 ;
}
static T_1 F_29 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
#define F_30 ( T_5 , T_6 ) \
do { \
if (_cond) \
p += scnprintf(p, sizeof(buf)+buf-p, "\t" _str "\n"); \
} while (0)
char V_5 [ 512 ] , * V_15 = V_5 ;
int V_20 ;
struct V_9 * V_10 = V_1 -> V_11 ;
struct V_66 * V_67 = & V_10 -> V_10 . V_68 ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_20 ,
V_67 -> V_69 ? L_21 : L_22 ) ;
if ( V_67 -> V_69 ) {
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_23 , V_67 -> V_70 ) ;
F_30 ( ( V_67 -> V_70 & F_31 ( 0 ) ) , L_24 ) ;
F_30 ( ( V_67 -> V_70 & F_31 ( 1 ) ) , L_25 ) ;
F_30 ( ! ( V_67 -> V_70 & F_31 ( 1 ) ) , L_26 ) ;
F_30 ( ( ( V_67 -> V_70 >> 2 ) & 0x3 ) == 0 , L_27 ) ;
F_30 ( ( ( V_67 -> V_70 >> 2 ) & 0x3 ) == 1 , L_28 ) ;
F_30 ( ( ( V_67 -> V_70 >> 2 ) & 0x3 ) == 3 , L_29 ) ;
F_30 ( ( V_67 -> V_70 & F_31 ( 4 ) ) , L_30 ) ;
F_30 ( ( V_67 -> V_70 & F_31 ( 5 ) ) , L_31 ) ;
F_30 ( ( V_67 -> V_70 & F_31 ( 6 ) ) , L_32 ) ;
F_30 ( ( V_67 -> V_70 & F_31 ( 7 ) ) , L_33 ) ;
F_30 ( ( ( V_67 -> V_70 >> 8 ) & 0x3 ) == 0 , L_34 ) ;
F_30 ( ( ( V_67 -> V_70 >> 8 ) & 0x3 ) == 1 , L_35 ) ;
F_30 ( ( ( V_67 -> V_70 >> 8 ) & 0x3 ) == 2 , L_36 ) ;
F_30 ( ( ( V_67 -> V_70 >> 8 ) & 0x3 ) == 3 , L_37 ) ;
F_30 ( ( V_67 -> V_70 & F_31 ( 10 ) ) , L_38 ) ;
F_30 ( ! ( V_67 -> V_70 & F_31 ( 11 ) ) , L_39
L_40 ) ;
F_30 ( ( V_67 -> V_70 & F_31 ( 11 ) ) , L_39
L_41 ) ;
F_30 ( ( V_67 -> V_70 & F_31 ( 12 ) ) , L_42 ) ;
F_30 ( ! ( V_67 -> V_70 & F_31 ( 12 ) ) , L_43 ) ;
F_30 ( ( V_67 -> V_70 & F_31 ( 14 ) ) , L_44 ) ;
F_30 ( ( V_67 -> V_70 & F_31 ( 15 ) ) , L_45 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_46 ,
V_67 -> V_71 , V_67 -> V_72 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_47 ) ;
for ( V_20 = 0 ; V_20 < V_73 ; V_20 ++ )
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_48 ,
V_67 -> V_74 . V_75 [ V_20 ] ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_4 ) ;
if ( F_10 ( V_67 -> V_74 . V_76 ) ) {
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_49 ,
F_10 ( V_67 -> V_74 . V_76 ) ) ;
}
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_50 ,
V_67 -> V_74 . V_77 ) ;
}
return F_6 ( V_2 , V_3 , V_4 , V_5 , V_15 - V_5 ) ;
}
static T_1 F_32 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_5 [ 512 ] , * V_15 = V_5 ;
struct V_9 * V_10 = V_1 -> V_11 ;
struct V_78 * V_79 = & V_10 -> V_10 . V_80 ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_51 ,
V_79 -> V_81 ? L_21 : L_22 ) ;
if ( V_79 -> V_81 ) {
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_52 ,
V_79 -> V_70 ) ;
#define F_33 ( T_7 , T_8 ) \
do { \
if (vhtc->cap & IEEE80211_VHT_CAP_ ## a) \
p += scnprintf(p, sizeof(buf) + buf - p, \
"\t\t%s\n", b); \
} while (0)
switch ( V_79 -> V_70 & 0x3 ) {
case V_82 :
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_53 ) ;
break;
case V_83 :
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_54 ) ;
break;
case V_84 :
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_55 ) ;
break;
default:
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_56 ) ;
} ;
switch ( V_79 -> V_70 & V_85 ) {
case 0 :
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_57 ) ;
break;
case V_86 :
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_58 ) ;
break;
case V_87 :
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_59 ) ;
break;
default:
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_60 ,
( V_79 -> V_70 >> 2 ) & 0x3 ) ;
} ;
F_33 ( V_88 , L_61 ) ;
F_33 ( V_89 , L_62 ) ;
F_33 ( V_90 , L_63 ) ;
F_33 ( V_91 , L_64 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_65 , ( V_79 -> V_70 >> 8 ) & 0x7 ) ;
F_33 ( V_92 , L_66 ) ;
F_33 ( V_93 , L_67 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_68 ,
( V_79 -> V_70 & V_94 ) >>
V_95 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_69 ,
( V_79 -> V_70 & V_96 )
>> V_97 ) ;
F_33 ( V_98 , L_70 ) ;
F_33 ( V_99 , L_71 ) ;
F_33 ( V_100 , L_72 ) ;
F_33 ( V_101 , L_73 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_74 ,
( V_79 -> V_70 & V_102 ) >>
V_103 ) ;
F_33 ( V_104 ,
L_75 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_76 ,
( V_79 -> V_70 & V_105 ) >> 26 ) ;
F_33 ( V_106 , L_77 ) ;
F_33 ( V_107 , L_78 ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_79 ,
F_10 ( V_79 -> V_108 . V_109 ) ) ;
if ( V_79 -> V_108 . V_76 )
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_80 ,
F_10 ( V_79 -> V_108 . V_76 ) ) ;
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 , L_81 ,
F_10 ( V_79 -> V_108 . V_110 ) ) ;
if ( V_79 -> V_108 . V_111 )
V_15 += F_5 ( V_15 , sizeof( V_5 ) + V_5 - V_15 ,
L_82 ,
F_10 ( V_79 -> V_108 . V_111 ) ) ;
}
return F_6 ( V_2 , V_3 , V_4 , V_5 , V_15 - V_5 ) ;
}
void F_34 ( struct V_9 * V_10 )
{
struct V_22 * V_23 = V_10 -> V_23 ;
struct V_112 * V_113 = V_10 -> V_113 ;
struct V_114 * V_115 = V_10 -> V_113 -> V_116 . V_117 ;
T_9 V_118 [ 3 * V_119 ] ;
if ( ! V_115 )
return;
snprintf ( V_118 , sizeof( V_118 ) , L_83 , V_10 -> V_10 . V_120 ) ;
V_10 -> V_121 = F_35 ( V_118 , V_115 ) ;
if ( ! V_10 -> V_121 )
return;
F_36 ( V_122 ) ;
F_36 ( V_123 ) ;
F_36 ( V_21 ) ;
F_36 ( V_124 ) ;
F_36 ( V_125 ) ;
F_36 ( V_126 ) ;
F_37 ( V_127 , V_128 . V_129 ) ;
F_37 ( V_130 , V_128 . V_131 ) ;
F_37 ( V_18 , V_132 . V_133 ) ;
if ( V_23 -> V_134 -> V_135 )
F_36 ( V_136 ) ;
if ( sizeof( V_10 -> V_137 ) == sizeof( V_138 ) )
F_38 ( L_84 , 0400 ,
V_10 -> V_121 ,
( V_138 * ) & V_10 -> V_137 ) ;
else
F_39 ( L_84 , 0400 ,
V_10 -> V_121 ,
( V_139 * ) & V_10 -> V_137 ) ;
F_40 ( V_23 , V_113 , & V_10 -> V_10 , V_10 -> V_121 ) ;
}
void F_41 ( struct V_9 * V_10 )
{
F_42 ( V_10 -> V_121 ) ;
V_10 -> V_121 = NULL ;
}
