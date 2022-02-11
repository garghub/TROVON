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
) ;
}
static unsigned long F_3 ( const char * V_5 )
{
T_2 * V_6 = fopen ( V_5 , L_30 ) ;
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
snprintf ( V_1 , 100 , L_31 , V_11 -> V_5 , V_5 ) ;
V_6 = fopen ( V_1 , L_32 ) ;
if ( ! V_6 )
F_1 ( L_33 , V_1 ) ;
fprintf ( V_6 , L_34 , V_12 ) ;
fclose ( V_6 ) ;
}
static unsigned long F_8 ( struct V_10 * V_11 , const char * V_5 )
{
char V_1 [ 100 ] ;
T_2 * V_6 ;
T_3 V_13 ;
snprintf ( V_1 , 100 , L_31 , V_11 -> V_5 , V_5 ) ;
V_6 = fopen ( V_1 , L_30 ) ;
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
V_14 /= V_15 ;
V_12 = sprintf ( V_7 , L_35 , V_14 ) ;
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
static void F_10 ( int * V_17 , char * V_18 )
{
int V_19 ;
int V_20 ;
memset ( V_17 , 0 , V_21 * sizeof( int ) ) ;
if ( ! V_18 )
return;
while ( * V_18 == 'N' ) {
V_18 ++ ;
V_19 = strtoul ( V_18 , & V_18 , 10 ) ;
if ( * V_18 == '=' ) {
V_18 ++ ;
V_20 = strtoul ( V_18 , & V_18 , 10 ) ;
V_17 [ V_19 ] = V_20 ;
if ( V_19 > V_22 )
V_22 = V_19 ;
}
while ( * V_18 == ' ' )
V_18 ++ ;
}
}
static void F_11 ( struct V_10 * V_11 )
{
if ( strcmp ( V_11 -> V_5 , L_36 ) == 0 )
return;
F_7 ( V_11 , L_37 , 1 ) ;
}
static void F_12 ( struct V_10 * V_11 )
{
if ( strcmp ( V_11 -> V_5 , L_36 ) == 0 )
return;
F_7 ( V_11 , L_38 , 1 ) ;
}
static void F_13 ( void )
{
if ( V_23 )
printf ( L_39 ) ;
else
printf ( L_40
L_41 ) ;
}
static struct V_24 * F_14 ( struct V_10 * V_25 )
{
struct V_24 * V_26 ;
struct V_24 * V_27 = NULL ;
for( V_26 = V_24 ; V_26 < V_24 + V_28 ; V_26 ++ ) {
if ( V_26 -> V_29 == V_25 &&
( ! V_27 || strlen ( V_27 -> V_5 ) < strlen ( V_26 -> V_5 ) ) ) {
V_27 = V_26 ;
if ( strncmp ( V_26 -> V_5 , L_42 , 5 ) == 0 )
return V_27 ;
}
}
return V_27 ;
}
static unsigned long F_15 ( struct V_10 * V_11 )
{
return V_11 -> V_30 * ( V_31 << V_11 -> V_32 ) ;
}
static unsigned long F_16 ( struct V_10 * V_11 )
{
return V_11 -> V_33 + V_11 -> V_34 +
V_11 -> V_35 + V_11 -> V_36 ;
}
static void F_17 ( struct V_10 * V_11 , int V_37 )
{
int V_19 ;
if ( strcmp ( V_11 -> V_5 , L_36 ) == 0 )
return;
if ( ! V_22 ) {
printf ( L_43 , V_11 -> V_5 ) ;
return;
}
if ( V_38 && ! V_11 -> V_30 )
return;
if ( ! line ) {
printf ( L_44 , V_37 ? L_45 : L_46 ) ;
for( V_19 = 0 ; V_19 <= V_22 ; V_19 ++ )
printf ( L_47 , V_19 ) ;
printf ( L_48 ) ;
for( V_19 = 0 ; V_19 <= V_22 ; V_19 ++ )
printf ( L_49 ) ;
printf ( L_50 ) ;
}
printf ( L_51 , V_37 ? L_52 : V_11 -> V_5 ) ;
for( V_19 = 0 ; V_19 <= V_22 ; V_19 ++ ) {
char V_39 [ 20 ] ;
F_9 ( V_39 , V_11 -> V_17 [ V_19 ] ) ;
printf ( L_53 , V_39 ) ;
}
printf ( L_50 ) ;
if ( V_37 ) {
printf ( L_51 , L_54 ) ;
for( V_19 = 0 ; V_19 <= V_22 ; V_19 ++ ) {
char V_39 [ 20 ] ;
F_9 ( V_39 , V_11 -> V_40 [ V_19 ] ) ;
printf ( L_53 , V_39 ) ;
}
printf ( L_50 ) ;
}
line ++ ;
}
static void F_18 ( struct V_10 * V_11 )
{
printf ( L_55 , V_11 -> V_5 ) ;
printf ( L_56 ) ;
if ( F_8 ( V_11 , L_57 ) )
printf ( L_58 , V_7 ) ;
else
printf ( L_59 ) ;
printf ( L_60 , V_11 -> V_5 ) ;
printf ( L_61 ) ;
if ( F_8 ( V_11 , L_62 ) )
printf ( L_58 , V_7 ) ;
else
printf ( L_59 ) ;
}
static void F_19 ( struct V_10 * V_11 )
{
if ( strcmp ( V_11 -> V_5 , L_36 ) == 0 )
return;
if ( F_8 ( V_11 , L_63 ) ) {
printf ( L_64 , V_11 -> V_5 ) ;
printf ( L_65 ) ;
printf ( L_58 , V_7 ) ;
} else
printf ( L_66 , V_11 -> V_5 ) ;
}
static const char * F_20 ( int V_1 )
{
if ( V_1 )
return L_67 ;
return L_68 ;
}
static void F_21 ( struct V_10 * V_11 )
{
unsigned long V_41 ;
unsigned long V_42 ;
unsigned long V_43 ;
if ( ! V_11 -> V_44 )
return;
V_41 = V_11 -> V_33 + V_11 -> V_35 ;
V_42 = V_11 -> V_34 + V_11 -> V_36 ;
if ( ! V_41 )
return;
printf ( L_50 ) ;
printf ( L_69 ) ;
printf ( L_70 ) ;
printf ( L_71 ,
V_11 -> V_33 , V_11 -> V_34 ,
V_11 -> V_33 * 100 / V_41 ,
V_11 -> V_34 * 100 / V_42 ) ;
printf ( L_72 ,
V_41 - V_11 -> V_33 , V_11 -> V_36 ,
( V_41 - V_11 -> V_33 ) * 100 / V_41 ,
V_11 -> V_36 * 100 / V_42 ) ;
printf ( L_73 ,
V_11 -> V_44 , V_11 -> V_45 ,
V_11 -> V_44 * 100 / V_41 ,
V_11 -> V_45 * 100 / V_42 ) ;
printf ( L_74 ,
V_11 -> V_46 + V_11 -> V_47 ,
V_11 -> V_48 ,
( V_11 -> V_46 + V_11 -> V_47 ) * 100 / V_41 ,
V_11 -> V_48 * 100 / V_42 ) ;
printf ( L_75 ,
V_11 -> V_49 , V_11 -> V_50 ,
V_11 -> V_49 * 100 / V_41 ,
V_11 -> V_50 * 100 / V_42 ) ;
printf ( L_76 ,
V_11 -> V_51 , V_11 -> V_52 ,
V_11 -> V_51 * 100 / V_41 ,
V_11 -> V_52 * 100 / V_42 ) ;
printf ( L_77 ,
V_11 -> V_53 , V_11 -> V_54 ,
V_11 -> V_53 * 100 / V_41 ,
V_11 -> V_54 * 100 / V_42 ) ;
printf ( L_78 , V_41 , V_42 ) ;
if ( V_11 -> V_55 )
printf ( L_79 , V_11 -> V_55 ) ;
V_43 = V_11 -> V_56 + V_11 -> V_57 +
V_11 -> V_46 + V_11 -> V_47 + V_11 -> V_58 ;
if ( V_43 ) {
printf ( L_80 ) ;
printf ( L_81 ) ;
printf ( L_82 ,
V_11 -> V_56 , ( V_11 -> V_56 * 100 ) / V_43 ) ;
printf ( L_83 ,
V_11 -> V_57 , ( V_11 -> V_57 * 100 ) / V_43 ) ;
printf ( L_84 ,
V_11 -> V_46 , ( V_11 -> V_46 * 100 ) / V_43 ) ;
printf ( L_85 ,
V_11 -> V_47 , ( V_11 -> V_47 * 100 ) / V_43 ) ;
printf ( L_86 ,
V_11 -> V_58 , ( V_11 -> V_58 * 100 ) / V_43 ) ;
printf ( L_87 ,
V_11 -> V_59 , ( V_11 -> V_59 * 100 ) / V_43 ) ;
printf ( L_88 ,
V_11 -> V_60 , ( V_11 -> V_60 * 100 ) / V_43 ) ;
}
if ( V_11 -> V_61 || V_11 -> V_62 )
printf ( L_89 ) ;
printf ( L_90 ,
V_11 -> V_61 , V_11 -> V_62 ) ;
}
static void F_22 ( struct V_10 * V_11 )
{
if ( strcmp ( V_11 -> V_5 , L_36 ) == 0 )
return;
printf ( L_91 ,
V_11 -> V_5 , V_11 -> V_28 , V_11 -> V_32 , V_11 -> V_63 ) ;
if ( V_11 -> V_64 )
printf ( L_92 ) ;
if ( V_11 -> V_65 )
printf ( L_93 ) ;
if ( V_11 -> V_66 )
printf ( L_94 ) ;
if ( V_11 -> V_67 )
printf ( L_95 ) ;
printf ( L_96 ) ;
printf ( L_61 ) ;
printf ( L_97 ,
V_11 -> V_68 , V_11 -> V_30 , F_20 ( V_11 -> V_69 ) ,
V_11 -> V_30 * ( V_31 << V_11 -> V_32 ) ) ;
printf ( L_98 ,
V_11 -> F_15 , V_11 -> V_30 - V_11 -> V_70 - V_11 -> V_71 ,
F_20 ( V_11 -> V_72 ) , V_11 -> V_63 * V_11 -> V_68 ) ;
printf ( L_99 ,
V_31 << V_11 -> V_32 , V_11 -> V_70 , F_20 ( V_11 -> V_73 ) ,
V_11 -> V_30 * ( V_31 << V_11 -> V_32 ) - V_11 -> V_63 * V_11 -> V_68 ) ;
printf ( L_100 ,
V_11 -> F_15 - V_11 -> V_68 , V_11 -> V_71 , F_20 ( V_11 -> V_74 ) ,
( V_11 -> F_15 - V_11 -> V_68 ) * V_11 -> V_63 ) ;
printf ( L_101 ,
V_11 -> V_75 , V_11 -> V_76 , F_20 ( V_11 -> V_77 ) ,
( ( V_31 << V_11 -> V_32 ) - V_11 -> V_76 * V_11 -> F_15 ) *
V_11 -> V_30 ) ;
F_19 ( V_11 ) ;
F_18 ( V_11 ) ;
F_17 ( V_11 , 1 ) ;
F_21 ( V_11 ) ;
}
static void F_23 ( struct V_10 * V_11 )
{
char V_78 [ 20 ] ;
char V_79 [ 40 ] ;
char V_80 [ 20 ] ;
char * V_9 = V_80 ;
if ( strcmp ( V_11 -> V_5 , L_36 ) == 0 )
return;
if ( V_81 == 1 ) {
F_22 ( V_11 ) ;
return;
}
if ( V_38 && ! V_82 && ! V_11 -> V_30 )
return;
if ( V_82 && V_11 -> V_30 )
return;
F_9 ( V_78 , F_15 ( V_11 ) ) ;
snprintf ( V_79 , 40 , L_102 , V_11 -> V_30 - V_11 -> V_71 ,
V_11 -> V_70 , V_11 -> V_71 ) ;
if ( ! line ++ )
F_13 () ;
if ( V_11 -> V_28 )
* V_9 ++ = '*' ;
if ( V_11 -> V_65 )
* V_9 ++ = 'd' ;
if ( V_11 -> V_64 )
* V_9 ++ = 'A' ;
if ( V_11 -> V_73 )
* V_9 ++ = 'P' ;
if ( V_11 -> V_67 )
* V_9 ++ = 'a' ;
if ( V_11 -> V_72 )
* V_9 ++ = 'Z' ;
if ( V_11 -> V_69 )
* V_9 ++ = 'F' ;
if ( V_11 -> V_74 )
* V_9 ++ = 'U' ;
if ( V_11 -> V_77 )
* V_9 ++ = 'T' ;
* V_9 = 0 ;
if ( V_23 ) {
unsigned long V_41 ;
unsigned long V_42 ;
V_41 = V_11 -> V_33 + V_11 -> V_35 ;
V_42 = V_11 -> V_34 + V_11 -> V_36 ;
printf ( L_103 ,
V_11 -> V_5 , V_11 -> V_63 ,
V_41 , V_42 ,
V_41 ? ( V_11 -> V_33 * 100 / V_41 ) : 0 ,
V_42 ? ( V_11 -> V_34 * 100 / V_42 ) : 0 ,
V_11 -> V_83 , V_11 -> V_32 , V_11 -> V_61 ,
V_11 -> V_62 ) ;
}
else
printf ( L_104 ,
V_11 -> V_5 , V_11 -> V_63 , V_11 -> V_68 , V_78 , V_79 ,
V_11 -> V_76 , V_11 -> V_32 ,
V_11 -> V_30 ? ( V_11 -> V_70 * 100 ) / V_11 -> V_30 : 100 ,
V_11 -> V_30 ? ( V_11 -> V_63 * V_11 -> V_68 * 100 ) /
( V_11 -> V_30 * ( V_31 << V_11 -> V_32 ) ) : 100 ,
V_80 ) ;
}
static int F_24 ( char * V_84 )
{
if ( ! V_84 || ! V_84 [ 0 ] || strcmp ( V_84 , L_105 ) == 0 )
return 1 ;
if ( strcasecmp ( V_84 , L_106 ) == 0 ) {
V_85 = 1 ;
V_73 = 1 ;
V_86 = 1 ;
V_87 = 1 ;
return 1 ;
}
for ( ; * V_84 ; V_84 ++ )
switch ( * V_84 ) {
case 'F' : case 'f' :
if ( V_85 )
return 0 ;
V_85 = 1 ;
break;
case 'P' : case 'p' :
if ( V_73 )
return 0 ;
V_73 = 1 ;
break;
case 'Z' : case 'z' :
if ( V_86 )
return 0 ;
V_86 = 1 ;
break;
case 'U' : case 'u' :
if ( V_87 )
return 0 ;
V_87 = 1 ;
break;
case 'T' : case 't' :
if ( V_88 )
return 0 ;
V_88 = 1 ;
break;
default:
return 0 ;
}
return 1 ;
}
static int F_25 ( struct V_10 * V_11 )
{
if ( V_11 -> V_63 > 0 )
return 0 ;
if ( V_11 -> V_30 != 0 )
F_7 ( V_11 , L_38 , 1 ) ;
return 1 ;
}
static void F_26 ( struct V_10 * V_11 )
{
if ( strcmp ( V_11 -> V_5 , L_36 ) == 0 )
return;
if ( V_85 && ! V_11 -> V_69 ) {
F_7 ( V_11 , L_107 , 1 ) ;
}
if ( ! V_85 && V_11 -> V_69 ) {
if ( F_25 ( V_11 ) )
F_7 ( V_11 , L_107 , 0 ) ;
else
fprintf ( V_3 , L_108 , V_11 -> V_5 ) ;
}
if ( V_86 && ! V_11 -> V_72 ) {
if ( F_25 ( V_11 ) )
F_7 ( V_11 , L_109 , 1 ) ;
else
fprintf ( V_3 , L_110 , V_11 -> V_5 ) ;
}
if ( ! V_86 && V_11 -> V_72 ) {
if ( F_25 ( V_11 ) )
F_7 ( V_11 , L_109 , 0 ) ;
else
fprintf ( V_3 , L_111 , V_11 -> V_5 ) ;
}
if ( V_73 && ! V_11 -> V_73 ) {
if ( F_25 ( V_11 ) )
F_7 ( V_11 , L_112 , 1 ) ;
else
fprintf ( V_3 , L_113 , V_11 -> V_5 ) ;
}
if ( ! V_73 && V_11 -> V_73 ) {
if ( F_25 ( V_11 ) )
F_7 ( V_11 , L_112 , 0 ) ;
else
fprintf ( V_3 , L_114 , V_11 -> V_5 ) ;
}
if ( V_87 && ! V_11 -> V_74 ) {
if ( F_25 ( V_11 ) )
F_7 ( V_11 , L_115 , 1 ) ;
else
fprintf ( V_3 , L_116 , V_11 -> V_5 ) ;
}
if ( ! V_87 && V_11 -> V_74 ) {
if ( F_25 ( V_11 ) )
F_7 ( V_11 , L_115 , 0 ) ;
else
fprintf ( V_3 , L_117 , V_11 -> V_5 ) ;
}
if ( V_88 && ! V_11 -> V_77 ) {
if ( V_30 == 1 )
F_7 ( V_11 , L_118 , 1 ) ;
else
fprintf ( V_3 , L_119 , V_11 -> V_5 ) ;
}
if ( ! V_88 && V_11 -> V_77 )
F_7 ( V_11 , L_118 , 1 ) ;
}
static void F_27 ( void )
{
struct V_10 * V_11 ;
int V_89 = 0 ;
char V_90 [ 20 ] , V_91 [ 20 ] , V_92 [ 20 ] , V_93 [ 20 ] ;
unsigned long long V_94 = 1ULL << 63 ;
unsigned long long V_95 = V_94 , V_96 = 0 , V_97 ;
unsigned long long V_98 = V_94 , V_99 = 0 ,
V_100 , V_101 = 0 ;
unsigned long long V_102 = V_94 , V_103 = 0 ,
V_104 , V_105 = 0 ;
unsigned long long V_106 = V_94 , V_107 = 0 ,
V_108 , V_109 = 0 ;
unsigned long long V_110 = V_94 , V_111 = 0 ,
V_112 , V_113 = 0 ;
unsigned long long V_114 = V_94 , V_115 = 0 ,
V_116 , V_117 = 0 ;
unsigned long long V_118 = V_94 , V_119 = 0 ,
V_120 , V_121 = 0 ;
unsigned long long V_122 = V_94 ,
V_123 = 0 , V_124 ,
V_125 = 0 ;
unsigned long long V_126 = V_94 ,
V_127 = 0 , V_128 ,
V_129 = 0 ;
unsigned long V_130 = 100 , V_131 = 0 ,
V_132 , V_133 = 0 ;
unsigned long V_134 = V_94 , V_135 = 0 ,
V_136 , V_137 = 0 ;
unsigned long V_138 = 100 , V_139 = 0 ,
V_140 , V_141 = 0 ;
for ( V_11 = V_10 ; V_11 < V_10 + V_30 ; V_11 ++ ) {
unsigned long long V_142 ;
unsigned long V_143 ;
unsigned long long V_144 ;
unsigned long long V_145 ;
unsigned long V_146 ;
unsigned long V_147 ;
if ( ! V_11 -> V_30 || ! V_11 -> V_63 )
continue;
V_89 ++ ;
V_142 = F_15 ( V_11 ) ;
V_143 = V_11 -> V_63 * V_11 -> V_68 ;
V_144 = V_142 - V_143 ;
V_145 = V_11 -> F_15 - V_11 -> V_68 ;
V_146 = V_11 -> V_70 * 100 / V_11 -> V_30 ;
if ( V_146 > 100 )
V_146 = 100 ;
V_147 = V_11 -> V_148 * 100
/ V_11 -> V_63 ;
if ( V_147 > 100 )
V_147 = 100 ;
if ( V_11 -> V_68 < V_95 )
V_95 = V_11 -> V_68 ;
if ( V_11 -> V_70 < V_98 )
V_98 = V_11 -> V_70 ;
if ( V_11 -> V_30 < V_102 )
V_102 = V_11 -> V_30 ;
if ( V_142 < V_106 )
V_106 = V_142 ;
if ( V_144 < V_114 )
V_114 = V_144 ;
if ( V_145 < V_122 )
V_122 = V_145 ;
if ( V_11 -> V_63 < V_118 )
V_118 = V_11 -> V_63 ;
if ( V_143 < V_110 )
V_110 = V_143 ;
if ( V_11 -> V_148 < V_134 )
V_134 = V_11 -> V_148 ;
if ( V_146 < V_130 )
V_130 = V_146 ;
if ( V_147 < V_138 )
V_138 = V_147 ;
if ( V_11 -> F_15 < V_126 )
V_126 = V_11 -> F_15 ;
if ( V_11 -> V_68 > V_96 )
V_96 = V_11 -> V_68 ;
if ( V_11 -> V_70 > V_99 )
V_99 = V_11 -> V_70 ;
if ( V_11 -> V_30 > V_103 )
V_103 = V_11 -> V_30 ;
if ( V_142 > V_107 )
V_107 = V_142 ;
if ( V_144 > V_115 )
V_115 = V_144 ;
if ( V_145 > V_123 )
V_123 = V_145 ;
if ( V_11 -> V_63 > V_119 )
V_119 = V_11 -> V_63 ;
if ( V_143 > V_111 )
V_111 = V_143 ;
if ( V_11 -> V_148 > V_135 )
V_135 = V_11 -> V_148 ;
if ( V_146 > V_131 )
V_131 = V_146 ;
if ( V_147 > V_139 )
V_139 = V_147 ;
if ( V_11 -> F_15 > V_127 )
V_127 = V_11 -> F_15 ;
V_101 += V_11 -> V_70 ;
V_105 += V_11 -> V_30 ;
V_109 += V_142 ;
V_117 += V_144 ;
V_121 += V_11 -> V_63 ;
V_113 += V_143 ;
V_137 += V_11 -> V_148 ;
V_133 += V_146 ;
V_141 += V_147 ;
V_125 += V_11 -> V_63 * V_145 ;
V_129 += V_11 -> V_63 * V_11 -> F_15 ;
}
if ( ! V_121 ) {
printf ( L_120 ) ;
return;
}
if ( ! V_89 ) {
printf ( L_121 ) ;
return;
}
V_100 = V_101 / V_89 ;
V_104 = V_105 / V_89 ;
V_108 = V_109 / V_89 ;
V_116 = V_117 / V_89 ;
V_120 = V_121 / V_89 ;
V_112 = V_113 / V_89 ;
V_136 = V_137 / V_89 ;
V_132 = V_133 / V_89 ;
V_140 = V_141 / V_89 ;
V_97 = V_113 / V_121 ;
V_124 = V_125 / V_121 ;
V_136 = V_137 * 100 / V_121 ;
V_128 = V_129 / V_121 ;
printf ( L_122 ) ;
printf ( L_123 ) ;
printf ( L_124 ,
V_30 , V_28 , V_149 , V_89 ) ;
F_9 ( V_90 , V_109 ) ; F_9 ( V_91 , V_117 ) ;
F_9 ( V_92 , V_117 * 100 / V_113 ) ;
printf ( L_125 , V_90 , V_91 , V_92 ) ;
F_9 ( V_90 , V_121 ) ; F_9 ( V_91 , V_137 ) ;
F_9 ( V_92 , V_137 * 100 / V_121 ) ;
printf ( L_126 , V_90 , V_91 , V_92 ) ;
printf ( L_50 ) ;
printf ( L_127 ) ;
printf ( L_128 ) ;
F_9 ( V_90 , V_120 ) ; F_9 ( V_91 , V_118 ) ;
F_9 ( V_92 , V_119 ) ; F_9 ( V_93 , V_121 ) ;
printf ( L_129 ,
V_90 , V_91 , V_92 , V_93 ) ;
F_9 ( V_90 , V_104 ) ; F_9 ( V_91 , V_102 ) ;
F_9 ( V_92 , V_103 ) ; F_9 ( V_93 , V_105 ) ;
printf ( L_130 ,
V_90 , V_91 , V_92 , V_93 ) ;
F_9 ( V_90 , V_100 ) ; F_9 ( V_91 , V_98 ) ;
F_9 ( V_92 , V_99 ) ; F_9 ( V_93 , V_101 ) ;
printf ( L_131 ,
V_90 , V_91 , V_92 , V_93 ) ;
F_9 ( V_90 , V_132 ) ; F_9 ( V_91 , V_130 ) ;
F_9 ( V_92 , V_131 ) ;
F_9 ( V_93 , V_101 * 100 / V_105 ) ;
printf ( L_132 ,
V_90 , V_91 , V_92 , V_93 ) ;
F_9 ( V_90 , V_136 ) ; F_9 ( V_91 , V_134 ) ;
F_9 ( V_92 , V_135 ) ;
F_9 ( V_93 , V_137 ) ;
printf ( L_133 ,
V_90 , V_91 , V_92 , V_93 ) ;
F_9 ( V_90 , V_140 ) ; F_9 ( V_91 , V_138 ) ;
F_9 ( V_92 , V_139 ) ;
F_9 ( V_93 , V_137 * 100 / V_121 ) ;
printf ( L_134 ,
V_90 , V_91 , V_92 , V_93 ) ;
F_9 ( V_90 , V_108 ) ; F_9 ( V_91 , V_106 ) ;
F_9 ( V_92 , V_107 ) ; F_9 ( V_93 , V_109 ) ;
printf ( L_135 ,
V_90 , V_91 , V_92 , V_93 ) ;
F_9 ( V_90 , V_112 ) ; F_9 ( V_91 , V_110 ) ;
F_9 ( V_92 , V_111 ) ; F_9 ( V_93 , V_113 ) ;
printf ( L_136 ,
V_90 , V_91 , V_92 , V_93 ) ;
F_9 ( V_90 , V_116 ) ; F_9 ( V_91 , V_114 ) ;
F_9 ( V_92 , V_115 ) ; F_9 ( V_93 , V_117 ) ;
printf ( L_137 ,
V_90 , V_91 , V_92 , V_93 ) ;
printf ( L_50 ) ;
printf ( L_138 ) ;
printf ( L_139 ) ;
F_9 ( V_90 , V_128 ) ; F_9 ( V_91 , V_126 ) ;
F_9 ( V_92 , V_127 ) ;
printf ( L_140 ,
V_90 , V_91 , V_92 ) ;
F_9 ( V_90 , V_97 ) ; F_9 ( V_91 , V_95 ) ;
F_9 ( V_92 , V_96 ) ;
printf ( L_141 ,
V_90 , V_91 , V_92 ) ;
F_9 ( V_90 , V_124 ) ; F_9 ( V_91 , V_122 ) ;
F_9 ( V_92 , V_123 ) ;
printf ( L_142 ,
V_90 , V_91 , V_92 ) ;
}
static void F_28 ( void )
{
struct V_10 * V_150 , * V_151 ;
for ( V_150 = V_10 ; V_150 < V_10 + V_30 ; V_150 ++ ) {
for ( V_151 = V_150 + 1 ; V_151 < V_10 + V_30 ; V_151 ++ ) {
int V_8 ;
if ( V_152 )
V_8 = F_15 ( V_150 ) < F_15 ( V_151 ) ;
else if ( V_153 )
V_8 = F_16 ( V_150 ) < F_16 ( V_151 ) ;
else
V_8 = strcasecmp ( V_150 -> V_5 , V_151 -> V_5 ) ;
if ( V_154 )
V_8 = - V_8 ;
if ( V_8 > 0 ) {
struct V_10 V_18 ;
memcpy ( & V_18 , V_150 , sizeof( struct V_10 ) ) ;
memcpy ( V_150 , V_151 , sizeof( struct V_10 ) ) ;
memcpy ( V_151 , & V_18 , sizeof( struct V_10 ) ) ;
}
}
}
}
static void F_29 ( void )
{
struct V_24 * V_155 , * V_156 ;
for ( V_155 = V_24 ; V_155 < V_24 + V_28 ; V_155 ++ ) {
for ( V_156 = V_155 + 1 ; V_156 < V_24 + V_28 ; V_156 ++ ) {
char * V_157 , * V_158 ;
V_157 = V_155 -> V_5 ;
V_158 = V_156 -> V_5 ;
if ( V_159 && ! V_154 ) {
V_157 = V_155 -> V_160 ;
V_158 = V_156 -> V_160 ;
}
if ( strcasecmp ( V_157 , V_158 ) > 0 ) {
struct V_24 V_18 ;
memcpy ( & V_18 , V_155 , sizeof( struct V_24 ) ) ;
memcpy ( V_155 , V_156 , sizeof( struct V_24 ) ) ;
memcpy ( V_156 , & V_18 , sizeof( struct V_24 ) ) ;
}
}
}
}
static void F_30 ( void )
{
struct V_24 * V_26 ;
struct V_10 * V_11 ;
for ( V_26 = V_24 ; V_26 < V_24 + V_28 ; V_26 ++ ) {
for ( V_11 = V_10 ; V_11 < V_10 + V_30 ; V_11 ++ )
if ( strcmp ( V_26 -> V_160 , V_11 -> V_5 ) == 0 ) {
V_26 -> V_29 = V_11 ;
V_11 -> V_161 ++ ;
break;
}
if ( V_11 == V_10 + V_30 )
F_1 ( L_143 , V_26 -> V_160 ) ;
}
}
static void F_31 ( void )
{
struct V_24 * V_26 ;
char * V_162 = NULL ;
F_29 () ;
F_30 () ;
for( V_26 = V_24 ; V_26 < V_24 + V_28 ; V_26 ++ ) {
if ( ! V_163 && V_26 -> V_29 -> V_161 == 1 )
continue;
if ( ! V_154 ) {
if ( V_162 ) {
if ( strcmp ( V_26 -> V_29 -> V_5 , V_162 ) == 0 ) {
printf ( L_144 , V_26 -> V_5 ) ;
continue;
}
}
printf ( L_145 , V_26 -> V_29 -> V_5 , V_26 -> V_5 ) ;
V_162 = V_26 -> V_29 -> V_5 ;
}
else
printf ( L_146 , V_26 -> V_5 , V_26 -> V_29 -> V_5 ) ;
}
if ( V_162 )
printf ( L_50 ) ;
}
static void F_32 ( void )
{
struct V_10 * V_11 ;
struct V_24 * V_26 ;
for ( V_11 = V_10 ; V_11 < V_10 + V_30 ; V_11 ++ ) {
if ( * V_11 -> V_5 != ':' )
continue;
if ( V_11 -> V_161 > 1 && ! V_164 )
continue;
V_26 = F_14 ( V_11 ) ;
if ( V_26 )
V_11 -> V_5 = V_26 -> V_5 ;
else {
V_11 -> V_5 = L_36 ;
V_81 -- ;
}
}
}
static int F_33 ( char * V_29 )
{
return regexec ( & V_165 , V_29 , 0 , NULL , 0 ) ;
}
static void F_34 ( void )
{
T_4 * V_166 ;
struct V_167 * V_168 ;
struct V_10 * V_29 = V_10 ;
struct V_24 * F_31 = V_24 ;
char * V_9 ;
char * V_18 ;
int V_169 ;
if ( F_35 ( L_147 ) && F_35 ( L_148 ) )
F_1 ( L_149 ) ;
V_166 = F_36 ( L_150 ) ;
while ( ( V_168 = F_37 ( V_166 ) ) ) {
if ( V_168 -> V_170 [ 0 ] == '.' ||
( V_168 -> V_170 [ 0 ] != ':' && F_33 ( V_168 -> V_170 ) ) )
continue;
switch ( V_168 -> V_171 ) {
case V_172 :
F_31 -> V_5 = F_6 ( V_168 -> V_170 ) ;
V_169 = F_38 ( V_168 -> V_170 , V_7 , sizeof( V_7 ) - 1 ) ;
if ( V_169 < 0 )
F_1 ( L_151 , V_168 -> V_170 ) ;
V_7 [ V_169 ] = 0 ;
V_9 = V_7 + V_169 ;
while ( V_9 > V_7 && V_9 [ - 1 ] != '/' )
V_9 -- ;
F_31 -> V_160 = F_6 ( V_9 ) ;
F_31 ++ ;
break;
case V_173 :
if ( F_35 ( V_168 -> V_170 ) )
F_1 ( L_152 , V_29 -> V_5 ) ;
V_29 -> V_5 = F_6 ( V_168 -> V_170 ) ;
V_29 -> F_31 = 0 ;
V_29 -> V_161 = 0 ;
V_29 -> V_28 = F_4 ( L_153 ) ;
V_29 -> V_75 = F_4 ( L_154 ) ;
V_29 -> V_65 = F_4 ( L_155 ) ;
V_29 -> V_71 = F_4 ( L_156 ) ;
V_29 -> V_66 = F_4 ( L_157 ) ;
V_29 -> V_64 = F_4 ( L_158 ) ;
V_29 -> V_68 = F_4 ( L_159 ) ;
V_29 -> V_63 = F_4 ( L_160 ) ;
V_29 -> V_148 = F_4 ( L_161 ) ;
V_29 -> V_174 = F_4 ( L_162 ) ;
V_29 -> V_76 = F_4 ( L_163 ) ;
V_29 -> V_32 = F_4 ( L_164 ) ;
V_29 -> V_70 = F_4 ( L_165 ) ;
V_29 -> V_70 = F_5 ( L_165 , & V_18 ) ;
F_10 ( V_29 -> V_40 , V_18 ) ;
free ( V_18 ) ;
V_29 -> V_73 = F_4 ( L_112 ) ;
V_29 -> V_67 = F_4 ( L_166 ) ;
V_29 -> V_72 = F_4 ( L_109 ) ;
V_29 -> V_69 = F_4 ( L_167 ) ;
V_29 -> F_15 = F_4 ( L_168 ) ;
V_29 -> V_30 = F_5 ( L_169 , & V_18 ) ;
F_10 ( V_29 -> V_17 , V_18 ) ;
free ( V_18 ) ;
V_29 -> V_74 = F_4 ( L_115 ) ;
V_29 -> V_77 = F_4 ( L_118 ) ;
V_29 -> V_33 = F_4 ( L_170 ) ;
V_29 -> V_35 = F_4 ( L_171 ) ;
V_29 -> V_34 = F_4 ( L_172 ) ;
V_29 -> V_36 = F_4 ( L_173 ) ;
V_29 -> V_54 = F_4 ( L_174 ) ;
V_29 -> V_48 = F_4 ( L_175 ) ;
V_29 -> V_50 = F_4 ( L_176 ) ;
V_29 -> V_49 = F_4 ( L_177 ) ;
V_29 -> V_44 = F_4 ( L_178 ) ;
V_29 -> V_59 = F_4 ( L_179 ) ;
V_29 -> V_45 = F_4 ( L_180 ) ;
V_29 -> V_55 = F_4 ( L_181 ) ;
V_29 -> V_56 = F_4 ( L_182 ) ;
V_29 -> V_57 = F_4 ( L_183 ) ;
V_29 -> V_46 = F_4 ( L_184 ) ;
V_29 -> V_47 = F_4 ( L_185 ) ;
V_29 -> V_53 = F_4 ( L_186 ) ;
V_29 -> V_83 = F_4 ( L_187 ) ;
V_29 -> V_62 = F_4 ( L_188 ) ;
V_29 -> V_61 = F_4 ( L_189 ) ;
V_29 -> V_51 = F_4 ( L_190 ) ;
V_29 -> V_52 = F_4 ( L_191 ) ;
V_29 -> V_60 = F_4 ( L_192 ) ;
V_29 -> V_58 = F_4 ( L_193 ) ;
F_35 ( L_194 ) ;
if ( V_29 -> V_5 [ 0 ] == ':' )
V_149 ++ ;
V_29 ++ ;
break;
default :
F_1 ( L_195 , V_168 -> V_171 ) ;
}
}
F_39 ( V_166 ) ;
V_30 = V_29 - V_10 ;
V_81 = V_30 ;
V_28 = F_31 - V_24 ;
if ( V_30 > V_175 )
F_1 ( L_196 ) ;
if ( V_28 > V_176 )
F_1 ( L_197 ) ;
}
static void F_40 ( void )
{
struct V_10 * V_29 ;
for ( V_29 = V_10 ; V_29 < V_10 + V_30 ; V_29 ++ ) {
if ( V_29 -> F_31 )
continue;
if ( V_177 )
F_17 ( V_29 , 0 ) ;
else if ( V_178 )
F_18 ( V_29 ) ;
else if ( V_179 )
F_11 ( V_29 ) ;
else if ( V_180 )
F_12 ( V_29 ) ;
else if ( V_181 )
F_26 ( V_29 ) ;
else if ( V_182 )
F_19 ( V_29 ) ;
else if ( V_183 )
F_23 ( V_29 ) ;
else if ( V_184 )
F_22 ( V_29 ) ;
}
}
int main ( int V_185 , char * V_186 [] )
{
int V_187 ;
int V_188 ;
char * V_189 ;
V_31 = F_41 () ;
while ( ( V_187 = F_42 ( V_185 , V_186 , L_198 ,
V_190 , NULL ) ) != - 1 )
switch ( V_187 ) {
case '1' :
V_163 = 1 ;
break;
case 'a' :
V_159 = 1 ;
break;
case 'A' :
V_153 = 1 ;
break;
case 'd' :
V_181 = 1 ;
if ( ! F_24 ( V_191 ) )
F_1 ( L_199 , V_191 ) ;
break;
case 'D' :
V_23 = 1 ;
break;
case 'e' :
V_82 = 1 ;
break;
case 'f' :
V_164 = 1 ;
break;
case 'h' :
F_2 () ;
return 0 ;
case 'i' :
V_154 = 1 ;
break;
case 'n' :
V_177 = 1 ;
break;
case 'o' :
V_182 = 1 ;
break;
case 'r' :
V_184 = 1 ;
break;
case 's' :
V_180 = 1 ;
break;
case 'l' :
V_183 = 1 ;
break;
case 't' :
V_178 = 1 ;
break;
case 'v' :
V_179 = 1 ;
break;
case 'z' :
V_38 = 0 ;
break;
case 'T' :
V_192 = 1 ;
break;
case 'S' :
V_152 = 1 ;
break;
default:
F_1 ( L_200 , V_186 [ 0 ] , V_193 ) ;
}
if ( ! V_183 && ! V_159 && ! V_178 && ! V_184
&& ! V_179 && ! V_180 && ! V_181 && ! V_182 )
V_183 = 1 ;
if ( V_185 > V_194 )
V_189 = V_186 [ V_194 ] ;
else
V_189 = L_201 ;
V_188 = regcomp ( & V_165 , V_189 , V_195 | V_196 ) ;
if ( V_188 )
F_1 ( L_202 ,
V_186 [ 0 ] , V_189 , V_188 ) ;
F_34 () ;
if ( V_159 )
F_31 () ;
else
if ( V_192 )
F_27 () ;
else {
F_30 () ;
F_32 () ;
F_28 () ;
F_40 () ;
}
return 0 ;
}
