static void F_1 ( const char * V_1 , ... )
{
T_1 V_2 ;
va_start ( V_2 , V_1 ) ;
vfprintf ( V_3 , V_1 , V_2 ) ;
va_end ( V_2 ) ;
exit ( V_4 ) ;
}
static void F_2 ( void )
{
printf ( L_1
L_2
L_3
L_4
L_5
L_6
L_7
L_8
L_9
L_10
L_11
L_12
L_13
L_14
L_15
L_16
L_17
L_18
L_19
L_20
L_21
L_22
L_23
L_24
L_25
L_26
L_27
L_28
L_29
L_30
L_31
L_32
L_33
) ;
}
static unsigned long F_3 ( const char * V_5 )
{
T_2 * V_6 = fopen ( V_5 , L_34 ) ;
if ( ! V_6 )
V_7 [ 0 ] = 0 ;
else {
if ( ! fgets ( V_7 , sizeof( V_7 ) , V_6 ) )
V_7 [ 0 ] = 0 ;
fclose ( V_6 ) ;
if ( V_7 [ strlen ( V_7 ) ] == '\n' )
V_7 [ strlen ( V_7 ) ] = 0 ;
}
return strlen ( V_7 ) ;
}
static unsigned long F_4 ( const char * V_5 )
{
if ( ! F_3 ( V_5 ) )
return 0 ;
return atol ( V_7 ) ;
}
static unsigned long F_5 ( const char * V_5 , char * * V_1 )
{
unsigned long V_8 = 0 ;
char * V_9 ;
* V_1 = NULL ;
if ( ! F_3 ( V_5 ) ) {
V_1 = NULL ;
return 0 ;
}
V_8 = strtoul ( V_7 , & V_9 , 10 ) ;
while ( * V_9 == ' ' )
V_9 ++ ;
if ( * V_9 )
* V_1 = F_6 ( V_9 ) ;
return V_8 ;
}
static void F_7 ( struct V_10 * V_11 , const char * V_5 , int V_12 )
{
char V_1 [ 100 ] ;
T_2 * V_6 ;
snprintf ( V_1 , 100 , L_35 , V_11 -> V_5 , V_5 ) ;
V_6 = fopen ( V_1 , L_36 ) ;
if ( ! V_6 )
F_1 ( L_37 , V_1 ) ;
fprintf ( V_6 , L_38 , V_12 ) ;
fclose ( V_6 ) ;
}
static unsigned long F_8 ( struct V_10 * V_11 , const char * V_5 )
{
char V_1 [ 100 ] ;
T_2 * V_6 ;
T_3 V_13 ;
snprintf ( V_1 , 100 , L_35 , V_11 -> V_5 , V_5 ) ;
V_6 = fopen ( V_1 , L_34 ) ;
if ( ! V_6 ) {
V_7 [ 0 ] = 0 ;
V_13 = 0 ;
} else {
V_13 = fread ( V_7 , 1 , sizeof( V_7 ) , V_6 ) ;
V_7 [ V_13 ] = 0 ;
fclose ( V_6 ) ;
}
return V_13 ;
}
static int F_9 ( char * V_7 , unsigned long V_14 )
{
unsigned long V_15 = 1 ;
char V_16 = 0 ;
int V_12 ;
if ( ! V_17 ) {
if ( V_14 > 1000000000UL ) {
V_15 = 100000000UL ;
V_16 = 'G' ;
} else if ( V_14 > 1000000UL ) {
V_15 = 100000UL ;
V_16 = 'M' ;
} else if ( V_14 > 1000UL ) {
V_15 = 100 ;
V_16 = 'K' ;
}
}
V_14 /= V_15 ;
V_12 = sprintf ( V_7 , L_39 , V_14 ) ;
if ( V_16 ) {
V_7 [ V_12 ] = V_16 ;
V_12 ++ ;
V_7 [ V_12 ] = 0 ;
}
if ( V_15 != 1 ) {
memmove ( V_7 + V_12 - 2 , V_7 + V_12 - 3 , 4 ) ;
V_7 [ V_12 - 2 ] = '.' ;
V_12 ++ ;
}
return V_12 ;
}
static void F_10 ( int * V_18 , char * V_19 )
{
int V_20 ;
int V_21 ;
memset ( V_18 , 0 , V_22 * sizeof( int ) ) ;
if ( ! V_19 )
return;
while ( * V_19 == 'N' ) {
V_19 ++ ;
V_20 = strtoul ( V_19 , & V_19 , 10 ) ;
if ( * V_19 == '=' ) {
V_19 ++ ;
V_21 = strtoul ( V_19 , & V_19 , 10 ) ;
V_18 [ V_20 ] = V_21 ;
if ( V_20 > V_23 )
V_23 = V_20 ;
}
while ( * V_19 == ' ' )
V_19 ++ ;
}
}
static void F_11 ( struct V_10 * V_11 )
{
if ( strcmp ( V_11 -> V_5 , L_40 ) == 0 )
return;
F_7 ( V_11 , L_41 , 1 ) ;
}
static void F_12 ( struct V_10 * V_11 )
{
if ( strcmp ( V_11 -> V_5 , L_40 ) == 0 )
return;
F_7 ( V_11 , L_42 , 1 ) ;
}
static void F_13 ( void )
{
if ( V_24 )
printf ( L_43
L_44 ) ;
else
printf ( L_45
L_46 ,
V_25 ? L_47 : L_48 ) ;
}
static struct V_26 * F_14 ( struct V_10 * V_27 )
{
struct V_26 * V_28 ;
struct V_26 * V_29 = NULL ;
for( V_28 = V_26 ; V_28 < V_26 + V_30 ; V_28 ++ ) {
if ( V_28 -> V_31 == V_27 &&
( ! V_29 || strlen ( V_29 -> V_5 ) < strlen ( V_28 -> V_5 ) ) ) {
V_29 = V_28 ;
if ( strncmp ( V_28 -> V_5 , L_49 , 5 ) == 0 )
return V_29 ;
}
}
return V_29 ;
}
static unsigned long F_15 ( struct V_10 * V_11 )
{
return V_11 -> V_32 * ( V_33 << V_11 -> V_34 ) ;
}
static unsigned long F_16 ( struct V_10 * V_11 )
{
return V_11 -> V_35 + V_11 -> V_36 +
V_11 -> V_37 + V_11 -> V_38 ;
}
static unsigned long F_17 ( struct V_10 * V_11 )
{
return F_15 ( V_11 ) - V_11 -> V_39 * V_11 -> V_40 ;
}
static void F_18 ( struct V_10 * V_11 , int V_41 )
{
int V_20 ;
if ( strcmp ( V_11 -> V_5 , L_40 ) == 0 )
return;
if ( ! V_23 ) {
printf ( L_50 , V_11 -> V_5 ) ;
return;
}
if ( V_42 && ! V_11 -> V_32 )
return;
if ( ! line ) {
printf ( L_51 , V_41 ? L_52 : L_53 ) ;
for( V_20 = 0 ; V_20 <= V_23 ; V_20 ++ )
printf ( L_54 , V_20 ) ;
printf ( L_55 ) ;
for( V_20 = 0 ; V_20 <= V_23 ; V_20 ++ )
printf ( L_56 ) ;
printf ( L_57 ) ;
}
printf ( L_58 , V_41 ? L_59 : V_11 -> V_5 ) ;
for( V_20 = 0 ; V_20 <= V_23 ; V_20 ++ ) {
char V_43 [ 20 ] ;
F_9 ( V_43 , V_11 -> V_18 [ V_20 ] ) ;
printf ( L_60 , V_43 ) ;
}
printf ( L_57 ) ;
if ( V_41 ) {
printf ( L_58 , L_61 ) ;
for( V_20 = 0 ; V_20 <= V_23 ; V_20 ++ ) {
char V_43 [ 20 ] ;
F_9 ( V_43 , V_11 -> V_44 [ V_20 ] ) ;
printf ( L_60 , V_43 ) ;
}
printf ( L_57 ) ;
}
line ++ ;
}
static void F_19 ( struct V_10 * V_11 )
{
printf ( L_62 , V_11 -> V_5 ) ;
printf ( L_63 ) ;
if ( F_8 ( V_11 , L_64 ) )
printf ( L_65 , V_7 ) ;
else
printf ( L_66 ) ;
printf ( L_67 , V_11 -> V_5 ) ;
printf ( L_68 ) ;
if ( F_8 ( V_11 , L_69 ) )
printf ( L_65 , V_7 ) ;
else
printf ( L_66 ) ;
}
static void F_20 ( struct V_10 * V_11 )
{
if ( strcmp ( V_11 -> V_5 , L_40 ) == 0 )
return;
if ( F_8 ( V_11 , L_70 ) ) {
printf ( L_71 , V_11 -> V_5 ) ;
printf ( L_72 ) ;
printf ( L_65 , V_7 ) ;
} else
printf ( L_73 , V_11 -> V_5 ) ;
}
static const char * F_21 ( int V_1 )
{
if ( V_1 )
return L_74 ;
return L_75 ;
}
static void F_22 ( struct V_10 * V_11 )
{
unsigned long V_45 ;
unsigned long V_46 ;
unsigned long V_47 ;
if ( ! V_11 -> V_48 )
return;
V_45 = V_11 -> V_35 + V_11 -> V_37 ;
V_46 = V_11 -> V_36 + V_11 -> V_38 ;
if ( ! V_45 )
return;
printf ( L_57 ) ;
printf ( L_76 ) ;
printf ( L_77 ) ;
printf ( L_78 ,
V_11 -> V_35 , V_11 -> V_36 ,
V_11 -> V_35 * 100 / V_45 ,
V_46 ? V_11 -> V_36 * 100 / V_46 : 0 ) ;
printf ( L_79 ,
V_45 - V_11 -> V_35 , V_11 -> V_38 ,
( V_45 - V_11 -> V_35 ) * 100 / V_45 ,
V_46 ? V_11 -> V_38 * 100 / V_46 : 0 ) ;
printf ( L_80 ,
V_11 -> V_48 , V_11 -> V_49 ,
V_11 -> V_48 * 100 / V_45 ,
V_46 ? V_11 -> V_49 * 100 / V_46 : 0 ) ;
printf ( L_81 ,
V_11 -> V_50 + V_11 -> V_51 ,
V_11 -> V_52 ,
( V_11 -> V_50 + V_11 -> V_51 ) * 100 / V_45 ,
V_46 ? V_11 -> V_52 * 100 / V_46 : 0 ) ;
printf ( L_82 ,
V_11 -> V_53 , V_11 -> V_54 ,
V_11 -> V_53 * 100 / V_45 ,
V_46 ? V_11 -> V_54 * 100 / V_46 : 0 ) ;
printf ( L_83 ,
V_11 -> V_55 , V_11 -> V_56 ,
V_11 -> V_55 * 100 / V_45 ,
V_46 ? V_11 -> V_56 * 100 / V_46 : 0 ) ;
printf ( L_84 ,
V_11 -> V_57 , V_11 -> V_58 ,
V_11 -> V_57 * 100 / V_45 ,
V_46 ? V_11 -> V_58 * 100 / V_46 : 0 ) ;
printf ( L_85 , V_45 , V_46 ) ;
if ( V_11 -> V_59 )
printf ( L_86 , V_11 -> V_59 ) ;
V_47 = V_11 -> V_60 + V_11 -> V_61 +
V_11 -> V_50 + V_11 -> V_51 + V_11 -> V_62 ;
if ( V_47 ) {
printf ( L_87 ) ;
printf ( L_88 ) ;
printf ( L_89 ,
V_11 -> V_60 , ( V_11 -> V_60 * 100 ) / V_47 ) ;
printf ( L_90 ,
V_11 -> V_61 , ( V_11 -> V_61 * 100 ) / V_47 ) ;
printf ( L_91 ,
V_11 -> V_50 , ( V_11 -> V_50 * 100 ) / V_47 ) ;
printf ( L_92 ,
V_11 -> V_51 , ( V_11 -> V_51 * 100 ) / V_47 ) ;
printf ( L_93 ,
V_11 -> V_62 , ( V_11 -> V_62 * 100 ) / V_47 ) ;
printf ( L_94 ,
V_11 -> V_63 , ( V_11 -> V_63 * 100 ) / V_47 ) ;
printf ( L_95 ,
V_11 -> V_64 , ( V_11 -> V_64 * 100 ) / V_47 ) ;
}
if ( V_11 -> V_65 || V_11 -> V_66 )
printf ( L_96 ) ;
printf ( L_97 ,
V_11 -> V_65 , V_11 -> V_66 ) ;
}
static void F_23 ( struct V_10 * V_11 )
{
if ( strcmp ( V_11 -> V_5 , L_40 ) == 0 )
return;
printf ( L_98 ,
V_11 -> V_5 , V_11 -> V_30 , V_11 -> V_34 , V_11 -> V_39 ) ;
if ( V_11 -> V_67 )
printf ( L_99 ) ;
if ( V_11 -> V_68 )
printf ( L_100 ) ;
if ( V_11 -> V_69 )
printf ( L_101 ) ;
if ( V_11 -> V_70 )
printf ( L_102 ) ;
printf ( L_103 ) ;
printf ( L_68 ) ;
printf ( L_104 ,
V_11 -> V_40 , V_11 -> V_32 , F_21 ( V_11 -> V_71 ) ,
V_11 -> V_32 * ( V_33 << V_11 -> V_34 ) ) ;
printf ( L_105 ,
V_11 -> F_15 , V_11 -> V_32 - V_11 -> V_72 - V_11 -> V_73 ,
F_21 ( V_11 -> V_74 ) , V_11 -> V_39 * V_11 -> V_40 ) ;
printf ( L_106 ,
V_33 << V_11 -> V_34 , V_11 -> V_72 , F_21 ( V_11 -> V_75 ) ,
V_11 -> V_32 * ( V_33 << V_11 -> V_34 ) - V_11 -> V_39 * V_11 -> V_40 ) ;
printf ( L_107 ,
V_11 -> F_15 - V_11 -> V_40 , V_11 -> V_73 , F_21 ( V_11 -> V_76 ) ,
( V_11 -> F_15 - V_11 -> V_40 ) * V_11 -> V_39 ) ;
printf ( L_108 ,
V_11 -> V_77 , V_11 -> V_78 , F_21 ( V_11 -> V_79 ) ,
( ( V_33 << V_11 -> V_34 ) - V_11 -> V_78 * V_11 -> F_15 ) *
V_11 -> V_32 ) ;
F_20 ( V_11 ) ;
F_19 ( V_11 ) ;
F_18 ( V_11 , 1 ) ;
F_22 ( V_11 ) ;
}
static void F_24 ( struct V_10 * V_11 )
{
char V_80 [ 20 ] ;
char V_81 [ 40 ] ;
char V_82 [ 20 ] ;
char * V_9 = V_82 ;
if ( strcmp ( V_11 -> V_5 , L_40 ) == 0 )
return;
if ( V_83 == 1 ) {
F_23 ( V_11 ) ;
return;
}
if ( V_42 && ! V_84 && ! V_11 -> V_32 )
return;
if ( V_84 && V_11 -> V_32 )
return;
if ( V_25 == 0 )
F_9 ( V_80 , F_15 ( V_11 ) ) ;
else
F_9 ( V_80 , F_17 ( V_11 ) ) ;
snprintf ( V_81 , 40 , L_109 , V_11 -> V_32 - V_11 -> V_73 ,
V_11 -> V_72 , V_11 -> V_73 ) ;
if ( ! line ++ )
F_13 () ;
if ( V_11 -> V_30 )
* V_9 ++ = '*' ;
if ( V_11 -> V_68 )
* V_9 ++ = 'd' ;
if ( V_11 -> V_67 )
* V_9 ++ = 'A' ;
if ( V_11 -> V_75 )
* V_9 ++ = 'P' ;
if ( V_11 -> V_70 )
* V_9 ++ = 'a' ;
if ( V_11 -> V_74 )
* V_9 ++ = 'Z' ;
if ( V_11 -> V_71 )
* V_9 ++ = 'F' ;
if ( V_11 -> V_76 )
* V_9 ++ = 'U' ;
if ( V_11 -> V_79 )
* V_9 ++ = 'T' ;
* V_9 = 0 ;
if ( V_24 ) {
unsigned long V_45 ;
unsigned long V_46 ;
V_45 = V_11 -> V_35 + V_11 -> V_37 ;
V_46 = V_11 -> V_36 + V_11 -> V_38 ;
printf ( L_110 ,
V_11 -> V_5 , V_11 -> V_39 ,
V_45 , V_46 ,
V_45 ? ( V_11 -> V_35 * 100 / V_45 ) : 0 ,
V_46 ? ( V_11 -> V_36 * 100 / V_46 ) : 0 ,
V_11 -> V_85 , V_11 -> V_34 , V_11 -> V_65 ,
V_11 -> V_66 ) ;
} else {
printf ( L_111 ,
V_11 -> V_5 , V_11 -> V_39 , V_11 -> V_40 , V_80 , V_81 ,
V_11 -> V_78 , V_11 -> V_34 ,
V_11 -> V_32 ? ( V_11 -> V_72 * 100 ) / V_11 -> V_32 : 100 ,
V_11 -> V_32 ? ( V_11 -> V_39 * V_11 -> V_40 * 100 ) /
( V_11 -> V_32 * ( V_33 << V_11 -> V_34 ) ) : 100 ,
V_82 ) ;
}
}
static int F_25 ( char * V_86 )
{
if ( ! V_86 || ! V_86 [ 0 ] || strcmp ( V_86 , L_112 ) == 0 )
return 1 ;
if ( strcasecmp ( V_86 , L_113 ) == 0 ) {
V_87 = 1 ;
V_75 = 1 ;
V_88 = 1 ;
V_89 = 1 ;
return 1 ;
}
for ( ; * V_86 ; V_86 ++ )
switch ( * V_86 ) {
case 'F' : case 'f' :
if ( V_87 )
return 0 ;
V_87 = 1 ;
break;
case 'P' : case 'p' :
if ( V_75 )
return 0 ;
V_75 = 1 ;
break;
case 'Z' : case 'z' :
if ( V_88 )
return 0 ;
V_88 = 1 ;
break;
case 'U' : case 'u' :
if ( V_89 )
return 0 ;
V_89 = 1 ;
break;
case 'T' : case 't' :
if ( V_90 )
return 0 ;
V_90 = 1 ;
break;
default:
return 0 ;
}
return 1 ;
}
static int F_26 ( struct V_10 * V_11 )
{
if ( V_11 -> V_39 > 0 )
return 0 ;
if ( V_11 -> V_32 != 0 )
F_7 ( V_11 , L_42 , 1 ) ;
return 1 ;
}
static void F_27 ( struct V_10 * V_11 )
{
if ( strcmp ( V_11 -> V_5 , L_40 ) == 0 )
return;
if ( V_87 && ! V_11 -> V_71 ) {
F_7 ( V_11 , L_114 , 1 ) ;
}
if ( ! V_87 && V_11 -> V_71 ) {
if ( F_26 ( V_11 ) )
F_7 ( V_11 , L_114 , 0 ) ;
else
fprintf ( V_3 , L_115 , V_11 -> V_5 ) ;
}
if ( V_88 && ! V_11 -> V_74 ) {
if ( F_26 ( V_11 ) )
F_7 ( V_11 , L_116 , 1 ) ;
else
fprintf ( V_3 , L_117 , V_11 -> V_5 ) ;
}
if ( ! V_88 && V_11 -> V_74 ) {
if ( F_26 ( V_11 ) )
F_7 ( V_11 , L_116 , 0 ) ;
else
fprintf ( V_3 , L_118 , V_11 -> V_5 ) ;
}
if ( V_75 && ! V_11 -> V_75 ) {
if ( F_26 ( V_11 ) )
F_7 ( V_11 , L_119 , 1 ) ;
else
fprintf ( V_3 , L_120 , V_11 -> V_5 ) ;
}
if ( ! V_75 && V_11 -> V_75 ) {
if ( F_26 ( V_11 ) )
F_7 ( V_11 , L_119 , 0 ) ;
else
fprintf ( V_3 , L_121 , V_11 -> V_5 ) ;
}
if ( V_89 && ! V_11 -> V_76 ) {
if ( F_26 ( V_11 ) )
F_7 ( V_11 , L_122 , 1 ) ;
else
fprintf ( V_3 , L_123 , V_11 -> V_5 ) ;
}
if ( ! V_89 && V_11 -> V_76 ) {
if ( F_26 ( V_11 ) )
F_7 ( V_11 , L_122 , 0 ) ;
else
fprintf ( V_3 , L_124 , V_11 -> V_5 ) ;
}
if ( V_90 && ! V_11 -> V_79 ) {
if ( V_32 == 1 )
F_7 ( V_11 , L_125 , 1 ) ;
else
fprintf ( V_3 , L_126 , V_11 -> V_5 ) ;
}
if ( ! V_90 && V_11 -> V_79 )
F_7 ( V_11 , L_125 , 1 ) ;
}
static void F_28 ( void )
{
struct V_10 * V_11 ;
int V_91 = 0 ;
char V_92 [ 20 ] , V_93 [ 20 ] , V_94 [ 20 ] , V_95 [ 20 ] ;
unsigned long long V_96 = 1ULL << 63 ;
unsigned long long V_97 = V_96 , V_98 = 0 , V_99 ;
unsigned long long V_100 = V_96 , V_101 = 0 ,
V_102 , V_103 = 0 ;
unsigned long long V_104 = V_96 , V_105 = 0 ,
V_106 , V_107 = 0 ;
unsigned long long V_108 = V_96 , V_109 = 0 ,
V_110 , V_111 = 0 ;
unsigned long long V_112 = V_96 , V_113 = 0 ,
V_114 , V_115 = 0 ;
unsigned long long V_116 = V_96 , V_117 = 0 ,
V_118 , V_119 = 0 ;
unsigned long long V_120 = V_96 , V_121 = 0 ,
V_122 , V_123 = 0 ;
unsigned long long V_124 = V_96 ,
V_125 = 0 , V_126 ,
V_127 = 0 ;
unsigned long long V_128 = V_96 ,
V_129 = 0 , V_130 ,
V_131 = 0 ;
unsigned long V_132 = 100 , V_133 = 0 ,
V_134 , V_135 = 0 ;
unsigned long V_136 = V_96 , V_137 = 0 ,
V_138 , V_139 = 0 ;
unsigned long V_140 = 100 , V_141 = 0 ,
V_142 , V_143 = 0 ;
for ( V_11 = V_10 ; V_11 < V_10 + V_32 ; V_11 ++ ) {
unsigned long long V_144 ;
unsigned long V_145 ;
unsigned long long V_146 ;
unsigned long long V_147 ;
unsigned long V_148 ;
unsigned long V_149 ;
if ( ! V_11 -> V_32 || ! V_11 -> V_39 )
continue;
V_91 ++ ;
V_144 = F_15 ( V_11 ) ;
V_145 = V_11 -> V_39 * V_11 -> V_40 ;
V_146 = V_144 - V_145 ;
V_147 = V_11 -> F_15 - V_11 -> V_40 ;
V_148 = V_11 -> V_72 * 100 / V_11 -> V_32 ;
if ( V_148 > 100 )
V_148 = 100 ;
V_149 = V_11 -> V_150 * 100
/ V_11 -> V_39 ;
if ( V_149 > 100 )
V_149 = 100 ;
if ( V_11 -> V_40 < V_97 )
V_97 = V_11 -> V_40 ;
if ( V_11 -> V_72 < V_100 )
V_100 = V_11 -> V_72 ;
if ( V_11 -> V_32 < V_104 )
V_104 = V_11 -> V_32 ;
if ( V_144 < V_108 )
V_108 = V_144 ;
if ( V_146 < V_116 )
V_116 = V_146 ;
if ( V_147 < V_124 )
V_124 = V_147 ;
if ( V_11 -> V_39 < V_120 )
V_120 = V_11 -> V_39 ;
if ( V_145 < V_112 )
V_112 = V_145 ;
if ( V_11 -> V_150 < V_136 )
V_136 = V_11 -> V_150 ;
if ( V_148 < V_132 )
V_132 = V_148 ;
if ( V_149 < V_140 )
V_140 = V_149 ;
if ( V_11 -> F_15 < V_128 )
V_128 = V_11 -> F_15 ;
if ( V_11 -> V_40 > V_98 )
V_98 = V_11 -> V_40 ;
if ( V_11 -> V_72 > V_101 )
V_101 = V_11 -> V_72 ;
if ( V_11 -> V_32 > V_105 )
V_105 = V_11 -> V_32 ;
if ( V_144 > V_109 )
V_109 = V_144 ;
if ( V_146 > V_117 )
V_117 = V_146 ;
if ( V_147 > V_125 )
V_125 = V_147 ;
if ( V_11 -> V_39 > V_121 )
V_121 = V_11 -> V_39 ;
if ( V_145 > V_113 )
V_113 = V_145 ;
if ( V_11 -> V_150 > V_137 )
V_137 = V_11 -> V_150 ;
if ( V_148 > V_133 )
V_133 = V_148 ;
if ( V_149 > V_141 )
V_141 = V_149 ;
if ( V_11 -> F_15 > V_129 )
V_129 = V_11 -> F_15 ;
V_103 += V_11 -> V_72 ;
V_107 += V_11 -> V_32 ;
V_111 += V_144 ;
V_119 += V_146 ;
V_123 += V_11 -> V_39 ;
V_115 += V_145 ;
V_139 += V_11 -> V_150 ;
V_135 += V_148 ;
V_143 += V_149 ;
V_127 += V_11 -> V_39 * V_147 ;
V_131 += V_11 -> V_39 * V_11 -> F_15 ;
}
if ( ! V_123 ) {
printf ( L_127 ) ;
return;
}
if ( ! V_91 ) {
printf ( L_128 ) ;
return;
}
V_102 = V_103 / V_91 ;
V_106 = V_107 / V_91 ;
V_110 = V_111 / V_91 ;
V_118 = V_119 / V_91 ;
V_122 = V_123 / V_91 ;
V_114 = V_115 / V_91 ;
V_138 = V_139 / V_91 ;
V_134 = V_135 / V_91 ;
V_142 = V_143 / V_91 ;
V_99 = V_115 / V_123 ;
V_126 = V_127 / V_123 ;
V_138 = V_139 * 100 / V_123 ;
V_130 = V_131 / V_123 ;
printf ( L_129 ) ;
printf ( L_130 ) ;
printf ( L_131 ,
V_32 , V_30 , V_151 , V_91 ) ;
F_9 ( V_92 , V_111 ) ; F_9 ( V_93 , V_119 ) ;
F_9 ( V_94 , V_119 * 100 / V_115 ) ;
printf ( L_132 , V_92 , V_93 , V_94 ) ;
F_9 ( V_92 , V_123 ) ; F_9 ( V_93 , V_139 ) ;
F_9 ( V_94 , V_139 * 100 / V_123 ) ;
printf ( L_133 , V_92 , V_93 , V_94 ) ;
printf ( L_57 ) ;
printf ( L_134
L_135 ) ;
printf ( L_136
L_137 ) ;
F_9 ( V_92 , V_122 ) ; F_9 ( V_93 , V_120 ) ;
F_9 ( V_94 , V_121 ) ; F_9 ( V_95 , V_123 ) ;
printf ( L_138 ,
V_92 , V_93 , V_94 , V_95 ) ;
F_9 ( V_92 , V_106 ) ; F_9 ( V_93 , V_104 ) ;
F_9 ( V_94 , V_105 ) ; F_9 ( V_95 , V_107 ) ;
printf ( L_139 ,
V_92 , V_93 , V_94 , V_95 ) ;
F_9 ( V_92 , V_102 ) ; F_9 ( V_93 , V_100 ) ;
F_9 ( V_94 , V_101 ) ; F_9 ( V_95 , V_103 ) ;
printf ( L_140 ,
V_92 , V_93 , V_94 , V_95 ) ;
F_9 ( V_92 , V_134 ) ; F_9 ( V_93 , V_132 ) ;
F_9 ( V_94 , V_133 ) ;
F_9 ( V_95 , V_103 * 100 / V_107 ) ;
printf ( L_141 ,
V_92 , V_93 , V_94 , V_95 ) ;
F_9 ( V_92 , V_138 ) ; F_9 ( V_93 , V_136 ) ;
F_9 ( V_94 , V_137 ) ;
F_9 ( V_95 , V_139 ) ;
printf ( L_142 ,
V_92 , V_93 , V_94 , V_95 ) ;
F_9 ( V_92 , V_142 ) ; F_9 ( V_93 , V_140 ) ;
F_9 ( V_94 , V_141 ) ;
F_9 ( V_95 , V_139 * 100 / V_123 ) ;
printf ( L_143 ,
V_92 , V_93 , V_94 , V_95 ) ;
F_9 ( V_92 , V_110 ) ; F_9 ( V_93 , V_108 ) ;
F_9 ( V_94 , V_109 ) ; F_9 ( V_95 , V_111 ) ;
printf ( L_144 ,
V_92 , V_93 , V_94 , V_95 ) ;
F_9 ( V_92 , V_114 ) ; F_9 ( V_93 , V_112 ) ;
F_9 ( V_94 , V_113 ) ; F_9 ( V_95 , V_115 ) ;
printf ( L_145 ,
V_92 , V_93 , V_94 , V_95 ) ;
F_9 ( V_92 , V_118 ) ; F_9 ( V_93 , V_116 ) ;
F_9 ( V_94 , V_117 ) ; F_9 ( V_95 , V_119 ) ;
printf ( L_146 ,
V_92 , V_93 , V_94 , V_95 ) ;
printf ( L_57 ) ;
printf ( L_147
L_148 ) ;
printf ( L_136
L_149 ) ;
F_9 ( V_92 , V_130 ) ; F_9 ( V_93 , V_128 ) ;
F_9 ( V_94 , V_129 ) ;
printf ( L_150 ,
V_92 , V_93 , V_94 ) ;
F_9 ( V_92 , V_99 ) ; F_9 ( V_93 , V_97 ) ;
F_9 ( V_94 , V_98 ) ;
printf ( L_151 ,
V_92 , V_93 , V_94 ) ;
F_9 ( V_92 , V_126 ) ; F_9 ( V_93 , V_124 ) ;
F_9 ( V_94 , V_125 ) ;
printf ( L_152 ,
V_92 , V_93 , V_94 ) ;
}
static void F_29 ( void )
{
struct V_10 * V_152 , * V_153 ;
for ( V_152 = V_10 ; V_152 < V_10 + V_32 ; V_152 ++ ) {
for ( V_153 = V_152 + 1 ; V_153 < V_10 + V_32 ; V_153 ++ ) {
int V_8 ;
if ( V_154 )
V_8 = F_15 ( V_152 ) < F_15 ( V_153 ) ;
else if ( V_155 )
V_8 = F_16 ( V_152 ) < F_16 ( V_153 ) ;
else if ( V_25 )
V_8 = F_17 ( V_152 ) < F_17 ( V_153 ) ;
else
V_8 = strcasecmp ( V_152 -> V_5 , V_153 -> V_5 ) ;
if ( V_156 )
V_8 = - V_8 ;
if ( V_8 > 0 ) {
struct V_10 V_19 ;
memcpy ( & V_19 , V_152 , sizeof( struct V_10 ) ) ;
memcpy ( V_152 , V_153 , sizeof( struct V_10 ) ) ;
memcpy ( V_153 , & V_19 , sizeof( struct V_10 ) ) ;
}
}
}
}
static void F_30 ( void )
{
struct V_26 * V_157 , * V_158 ;
for ( V_157 = V_26 ; V_157 < V_26 + V_30 ; V_157 ++ ) {
for ( V_158 = V_157 + 1 ; V_158 < V_26 + V_30 ; V_158 ++ ) {
char * V_159 , * V_160 ;
V_159 = V_157 -> V_5 ;
V_160 = V_158 -> V_5 ;
if ( V_161 && ! V_156 ) {
V_159 = V_157 -> V_162 ;
V_160 = V_158 -> V_162 ;
}
if ( strcasecmp ( V_159 , V_160 ) > 0 ) {
struct V_26 V_19 ;
memcpy ( & V_19 , V_157 , sizeof( struct V_26 ) ) ;
memcpy ( V_157 , V_158 , sizeof( struct V_26 ) ) ;
memcpy ( V_158 , & V_19 , sizeof( struct V_26 ) ) ;
}
}
}
}
static void F_31 ( void )
{
struct V_26 * V_28 ;
struct V_10 * V_11 ;
for ( V_28 = V_26 ; V_28 < V_26 + V_30 ; V_28 ++ ) {
for ( V_11 = V_10 ; V_11 < V_10 + V_32 ; V_11 ++ )
if ( strcmp ( V_28 -> V_162 , V_11 -> V_5 ) == 0 ) {
V_28 -> V_31 = V_11 ;
V_11 -> V_163 ++ ;
break;
}
if ( V_11 == V_10 + V_32 )
F_1 ( L_153 , V_28 -> V_162 ) ;
}
}
static void F_32 ( void )
{
struct V_26 * V_28 ;
char * V_164 = NULL ;
F_30 () ;
F_31 () ;
for( V_28 = V_26 ; V_28 < V_26 + V_30 ; V_28 ++ ) {
if ( ! V_165 && V_28 -> V_31 -> V_163 == 1 )
continue;
if ( ! V_156 ) {
if ( V_164 ) {
if ( strcmp ( V_28 -> V_31 -> V_5 , V_164 ) == 0 ) {
printf ( L_154 , V_28 -> V_5 ) ;
continue;
}
}
printf ( L_155 , V_28 -> V_31 -> V_5 , V_28 -> V_5 ) ;
V_164 = V_28 -> V_31 -> V_5 ;
}
else
printf ( L_156 , V_28 -> V_5 , V_28 -> V_31 -> V_5 ) ;
}
if ( V_164 )
printf ( L_57 ) ;
}
static void F_33 ( void )
{
struct V_10 * V_11 ;
struct V_26 * V_28 ;
for ( V_11 = V_10 ; V_11 < V_10 + V_32 ; V_11 ++ ) {
if ( * V_11 -> V_5 != ':' )
continue;
if ( V_11 -> V_163 > 1 && ! V_166 )
continue;
V_28 = F_14 ( V_11 ) ;
if ( V_28 )
V_11 -> V_5 = V_28 -> V_5 ;
else {
V_11 -> V_5 = L_40 ;
V_83 -- ;
}
}
}
static int F_34 ( char * V_31 )
{
return regexec ( & V_167 , V_31 , 0 , NULL , 0 ) ;
}
static void F_35 ( void )
{
T_4 * V_168 ;
struct V_169 * V_170 ;
struct V_10 * V_31 = V_10 ;
struct V_26 * F_32 = V_26 ;
char * V_9 ;
char * V_19 ;
int V_171 ;
if ( F_36 ( L_157 ) && F_36 ( L_158 ) )
F_1 ( L_159 ) ;
V_168 = F_37 ( L_160 ) ;
while ( ( V_170 = F_38 ( V_168 ) ) ) {
if ( V_170 -> V_172 [ 0 ] == '.' ||
( V_170 -> V_172 [ 0 ] != ':' && F_34 ( V_170 -> V_172 ) ) )
continue;
switch ( V_170 -> V_173 ) {
case V_174 :
F_32 -> V_5 = F_6 ( V_170 -> V_172 ) ;
V_171 = F_39 ( V_170 -> V_172 , V_7 , sizeof( V_7 ) - 1 ) ;
if ( V_171 < 0 )
F_1 ( L_161 , V_170 -> V_172 ) ;
V_7 [ V_171 ] = 0 ;
V_9 = V_7 + V_171 ;
while ( V_9 > V_7 && V_9 [ - 1 ] != '/' )
V_9 -- ;
F_32 -> V_162 = F_6 ( V_9 ) ;
F_32 ++ ;
break;
case V_175 :
if ( F_36 ( V_170 -> V_172 ) )
F_1 ( L_162 , V_31 -> V_5 ) ;
V_31 -> V_5 = F_6 ( V_170 -> V_172 ) ;
V_31 -> F_32 = 0 ;
V_31 -> V_163 = 0 ;
V_31 -> V_30 = F_4 ( L_163 ) ;
V_31 -> V_77 = F_4 ( L_164 ) ;
V_31 -> V_68 = F_4 ( L_165 ) ;
V_31 -> V_73 = F_4 ( L_166 ) ;
V_31 -> V_69 = F_4 ( L_167 ) ;
V_31 -> V_67 = F_4 ( L_168 ) ;
V_31 -> V_40 = F_4 ( L_169 ) ;
V_31 -> V_39 = F_4 ( L_170 ) ;
V_31 -> V_150 = F_4 ( L_171 ) ;
V_31 -> V_176 = F_4 ( L_172 ) ;
V_31 -> V_78 = F_4 ( L_173 ) ;
V_31 -> V_34 = F_4 ( L_174 ) ;
V_31 -> V_72 = F_4 ( L_175 ) ;
V_31 -> V_72 = F_5 ( L_175 , & V_19 ) ;
F_10 ( V_31 -> V_44 , V_19 ) ;
free ( V_19 ) ;
V_31 -> V_75 = F_4 ( L_119 ) ;
V_31 -> V_70 = F_4 ( L_176 ) ;
V_31 -> V_74 = F_4 ( L_116 ) ;
V_31 -> V_71 = F_4 ( L_177 ) ;
V_31 -> F_15 = F_4 ( L_178 ) ;
V_31 -> V_32 = F_5 ( L_179 , & V_19 ) ;
F_10 ( V_31 -> V_18 , V_19 ) ;
free ( V_19 ) ;
V_31 -> V_76 = F_4 ( L_122 ) ;
V_31 -> V_79 = F_4 ( L_125 ) ;
V_31 -> V_35 = F_4 ( L_180 ) ;
V_31 -> V_37 = F_4 ( L_181 ) ;
V_31 -> V_36 = F_4 ( L_182 ) ;
V_31 -> V_38 = F_4 ( L_183 ) ;
V_31 -> V_58 = F_4 ( L_184 ) ;
V_31 -> V_52 = F_4 ( L_185 ) ;
V_31 -> V_54 = F_4 ( L_186 ) ;
V_31 -> V_53 = F_4 ( L_187 ) ;
V_31 -> V_48 = F_4 ( L_188 ) ;
V_31 -> V_63 = F_4 ( L_189 ) ;
V_31 -> V_49 = F_4 ( L_190 ) ;
V_31 -> V_59 = F_4 ( L_191 ) ;
V_31 -> V_60 = F_4 ( L_192 ) ;
V_31 -> V_61 = F_4 ( L_193 ) ;
V_31 -> V_50 = F_4 ( L_194 ) ;
V_31 -> V_51 = F_4 ( L_195 ) ;
V_31 -> V_57 = F_4 ( L_196 ) ;
V_31 -> V_85 = F_4 ( L_197 ) ;
V_31 -> V_66 = F_4 ( L_198 ) ;
V_31 -> V_65 = F_4 ( L_199 ) ;
V_31 -> V_55 = F_4 ( L_200 ) ;
V_31 -> V_56 = F_4 ( L_201 ) ;
V_31 -> V_64 = F_4 ( L_202 ) ;
V_31 -> V_62 = F_4 ( L_203 ) ;
F_36 ( L_204 ) ;
if ( V_31 -> V_5 [ 0 ] == ':' )
V_151 ++ ;
V_31 ++ ;
break;
default :
F_1 ( L_205 , V_170 -> V_173 ) ;
}
}
F_40 ( V_168 ) ;
V_32 = V_31 - V_10 ;
V_83 = V_32 ;
V_30 = F_32 - V_26 ;
if ( V_32 > V_177 )
F_1 ( L_206 ) ;
if ( V_30 > V_178 )
F_1 ( L_207 ) ;
}
static void F_41 ( void )
{
struct V_10 * V_31 ;
int V_179 = V_180 ;
for ( V_31 = V_10 ; ( V_31 < V_10 + V_32 ) &&
V_179 != 0 ; V_31 ++ ) {
if ( V_31 -> F_32 )
continue;
if ( V_179 != - 1 )
V_179 -- ;
if ( V_181 )
F_18 ( V_31 , 0 ) ;
else if ( V_182 )
F_19 ( V_31 ) ;
else if ( V_183 )
F_11 ( V_31 ) ;
else if ( V_184 )
F_12 ( V_31 ) ;
else if ( V_185 )
F_27 ( V_31 ) ;
else if ( V_186 )
F_20 ( V_31 ) ;
else if ( V_187 )
F_24 ( V_31 ) ;
else if ( V_188 )
F_23 ( V_31 ) ;
}
}
static void F_42 ( void )
{
F_28 () ;
F_31 () ;
F_33 () ;
printf ( L_208 ) ;
printf ( L_149 ) ;
V_25 = 0 ;
V_154 = 1 ;
F_29 () ;
F_41 () ;
printf ( L_209 ) ;
printf ( L_149 ) ;
line = 0 ;
V_25 = 1 ;
V_154 = 0 ;
F_29 () ;
F_41 () ;
printf ( L_57 ) ;
}
int main ( int V_189 , char * V_190 [] )
{
int V_191 ;
int V_192 ;
char * V_193 ;
V_33 = F_43 () ;
while ( ( V_191 = F_44 ( V_189 , V_190 , L_210 ,
V_194 , NULL ) ) != - 1 )
switch ( V_191 ) {
case '1' :
V_165 = 1 ;
break;
case 'a' :
V_161 = 1 ;
break;
case 'A' :
V_155 = 1 ;
break;
case 'd' :
V_185 = 1 ;
if ( ! F_25 ( V_195 ) )
F_1 ( L_211 , V_195 ) ;
break;
case 'D' :
V_24 = 1 ;
break;
case 'e' :
V_84 = 1 ;
break;
case 'f' :
V_166 = 1 ;
break;
case 'h' :
F_2 () ;
return 0 ;
case 'i' :
V_156 = 1 ;
break;
case 'n' :
V_181 = 1 ;
break;
case 'o' :
V_186 = 1 ;
break;
case 'r' :
V_188 = 1 ;
break;
case 's' :
V_184 = 1 ;
break;
case 'l' :
V_187 = 1 ;
break;
case 't' :
V_182 = 1 ;
break;
case 'v' :
V_183 = 1 ;
break;
case 'z' :
V_42 = 0 ;
break;
case 'T' :
V_196 = 1 ;
break;
case 'S' :
V_154 = 1 ;
break;
case 'N' :
if ( V_195 ) {
V_180 = atoi ( V_195 ) ;
if ( V_180 < 1 )
V_180 = 1 ;
}
break;
case 'L' :
V_25 = 1 ;
break;
case 'X' :
if ( V_180 == - 1 )
V_180 = 1 ;
V_197 = 1 ;
V_17 = 1 ;
break;
case 'B' :
V_17 = 1 ;
break;
default:
F_1 ( L_212 , V_190 [ 0 ] , V_198 ) ;
}
if ( ! V_187 && ! V_161 && ! V_182 && ! V_188
&& ! V_183 && ! V_184 && ! V_185 && ! V_186 )
V_187 = 1 ;
if ( V_189 > V_199 )
V_193 = V_190 [ V_199 ] ;
else
V_193 = L_213 ;
V_192 = regcomp ( & V_167 , V_193 , V_200 | V_201 ) ;
if ( V_192 )
F_1 ( L_214 ,
V_190 [ 0 ] , V_193 , V_192 ) ;
F_35 () ;
if ( V_161 ) {
F_32 () ;
} else if ( V_197 ) {
F_42 () ;
} else if ( V_196 ) {
F_28 () ;
} else {
F_31 () ;
F_33 () ;
F_29 () ;
F_41 () ;
}
return 0 ;
}
