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
printf ( V_7 ) ;
else
printf ( L_58 ) ;
printf ( L_59 , V_11 -> V_5 ) ;
printf ( L_60 ) ;
if ( F_8 ( V_11 , L_61 ) )
printf ( V_7 ) ;
else
printf ( L_58 ) ;
}
static void F_19 ( struct V_10 * V_11 )
{
if ( strcmp ( V_11 -> V_5 , L_36 ) == 0 )
return;
if ( F_8 ( V_11 , L_62 ) ) {
printf ( L_63 , V_11 -> V_5 ) ;
printf ( L_64 ) ;
printf ( V_7 ) ;
} else
printf ( L_65 , V_11 -> V_5 ) ;
}
static const char * F_20 ( int V_1 )
{
if ( V_1 )
return L_66 ;
return L_67 ;
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
printf ( L_68 ) ;
printf ( L_69 ) ;
printf ( L_70 ,
V_11 -> V_33 , V_11 -> V_34 ,
V_11 -> V_33 * 100 / V_41 ,
V_11 -> V_34 * 100 / V_42 ) ;
printf ( L_71 ,
V_41 - V_11 -> V_33 , V_11 -> V_36 ,
( V_41 - V_11 -> V_33 ) * 100 / V_41 ,
V_11 -> V_36 * 100 / V_42 ) ;
printf ( L_72 ,
V_11 -> V_44 , V_11 -> V_45 ,
V_11 -> V_44 * 100 / V_41 ,
V_11 -> V_45 * 100 / V_42 ) ;
printf ( L_73 ,
V_11 -> V_46 + V_11 -> V_47 ,
V_11 -> V_48 ,
( V_11 -> V_46 + V_11 -> V_47 ) * 100 / V_41 ,
V_11 -> V_48 * 100 / V_42 ) ;
printf ( L_74 ,
V_11 -> V_49 , V_11 -> V_50 ,
V_11 -> V_49 * 100 / V_41 ,
V_11 -> V_50 * 100 / V_42 ) ;
printf ( L_75 ,
V_11 -> V_51 , V_11 -> V_52 ,
V_11 -> V_51 * 100 / V_41 ,
V_11 -> V_52 * 100 / V_42 ) ;
printf ( L_76 , V_41 , V_42 ) ;
if ( V_11 -> V_53 )
printf ( L_77 , V_11 -> V_53 ) ;
if ( V_11 -> V_54 )
printf ( L_78 , V_11 -> V_54 ) ;
V_43 = V_11 -> V_55 + V_11 -> V_56 +
V_11 -> V_46 + V_11 -> V_47 ;
if ( V_43 )
printf ( L_79
L_80 ,
V_11 -> V_55 , ( V_11 -> V_55 * 100 ) / V_43 ,
V_11 -> V_56 , ( V_11 -> V_56 * 100 ) / V_43 ,
V_11 -> V_46 , ( V_11 -> V_46 * 100 ) / V_43 ,
V_11 -> V_47 , ( V_11 -> V_47 * 100 ) / V_43 ) ;
}
static void F_22 ( struct V_10 * V_11 )
{
if ( strcmp ( V_11 -> V_5 , L_36 ) == 0 )
return;
printf ( L_81 ,
V_11 -> V_5 , V_11 -> V_28 , V_11 -> V_32 , V_11 -> V_57 ) ;
if ( V_11 -> V_58 )
printf ( L_82 ) ;
if ( V_11 -> V_59 )
printf ( L_83 ) ;
if ( V_11 -> V_60 )
printf ( L_84 ) ;
if ( V_11 -> V_61 )
printf ( L_85 ) ;
printf ( L_86 ) ;
printf ( L_60 ) ;
printf ( L_87 ,
V_11 -> V_62 , V_11 -> V_30 , F_20 ( V_11 -> V_63 ) ,
V_11 -> V_30 * ( V_31 << V_11 -> V_32 ) ) ;
printf ( L_88 ,
V_11 -> F_15 , V_11 -> V_30 - V_11 -> V_64 - V_11 -> V_65 ,
F_20 ( V_11 -> V_66 ) , V_11 -> V_57 * V_11 -> V_62 ) ;
printf ( L_89 ,
V_31 << V_11 -> V_32 , V_11 -> V_64 , F_20 ( V_11 -> V_67 ) ,
V_11 -> V_30 * ( V_31 << V_11 -> V_32 ) - V_11 -> V_57 * V_11 -> V_62 ) ;
printf ( L_90 ,
V_11 -> F_15 - V_11 -> V_62 , V_11 -> V_65 , F_20 ( V_11 -> V_68 ) ,
( V_11 -> F_15 - V_11 -> V_62 ) * V_11 -> V_57 ) ;
printf ( L_91 ,
V_11 -> V_69 , V_11 -> V_70 , F_20 ( V_11 -> V_71 ) ,
( ( V_31 << V_11 -> V_32 ) - V_11 -> V_70 * V_11 -> F_15 ) *
V_11 -> V_30 ) ;
F_19 ( V_11 ) ;
F_18 ( V_11 ) ;
F_17 ( V_11 , 1 ) ;
F_21 ( V_11 ) ;
}
static void F_23 ( struct V_10 * V_11 )
{
char V_72 [ 20 ] ;
char V_73 [ 40 ] ;
char V_74 [ 20 ] ;
char * V_9 = V_74 ;
if ( strcmp ( V_11 -> V_5 , L_36 ) == 0 )
return;
if ( V_75 == 1 ) {
F_22 ( V_11 ) ;
return;
}
if ( V_38 && ! V_76 && ! V_11 -> V_30 )
return;
if ( V_76 && V_11 -> V_30 )
return;
F_9 ( V_72 , F_15 ( V_11 ) ) ;
snprintf ( V_73 , 40 , L_92 , V_11 -> V_30 - V_11 -> V_65 ,
V_11 -> V_64 , V_11 -> V_65 ) ;
if ( ! line ++ )
F_13 () ;
if ( V_11 -> V_28 )
* V_9 ++ = '*' ;
if ( V_11 -> V_59 )
* V_9 ++ = 'd' ;
if ( V_11 -> V_58 )
* V_9 ++ = 'A' ;
if ( V_11 -> V_67 )
* V_9 ++ = 'P' ;
if ( V_11 -> V_61 )
* V_9 ++ = 'a' ;
if ( V_11 -> V_66 )
* V_9 ++ = 'Z' ;
if ( V_11 -> V_63 )
* V_9 ++ = 'F' ;
if ( V_11 -> V_68 )
* V_9 ++ = 'U' ;
if ( V_11 -> V_71 )
* V_9 ++ = 'T' ;
* V_9 = 0 ;
if ( V_23 ) {
unsigned long V_41 ;
unsigned long V_42 ;
V_41 = V_11 -> V_33 + V_11 -> V_35 ;
V_42 = V_11 -> V_34 + V_11 -> V_36 ;
printf ( L_93 ,
V_11 -> V_5 , V_11 -> V_57 ,
V_41 , V_42 ,
V_41 ? ( V_11 -> V_33 * 100 / V_41 ) : 0 ,
V_42 ? ( V_11 -> V_34 * 100 / V_42 ) : 0 ,
V_11 -> V_77 , V_11 -> V_32 ) ;
}
else
printf ( L_94 ,
V_11 -> V_5 , V_11 -> V_57 , V_11 -> V_62 , V_72 , V_73 ,
V_11 -> V_70 , V_11 -> V_32 ,
V_11 -> V_30 ? ( V_11 -> V_64 * 100 ) / V_11 -> V_30 : 100 ,
V_11 -> V_30 ? ( V_11 -> V_57 * V_11 -> V_62 * 100 ) /
( V_11 -> V_30 * ( V_31 << V_11 -> V_32 ) ) : 100 ,
V_74 ) ;
}
static int F_24 ( char * V_78 )
{
if ( ! V_78 || ! V_78 [ 0 ] || strcmp ( V_78 , L_95 ) == 0 )
return 1 ;
if ( strcasecmp ( V_78 , L_96 ) == 0 ) {
V_79 = 1 ;
V_67 = 1 ;
V_80 = 1 ;
V_81 = 1 ;
return 1 ;
}
for ( ; * V_78 ; V_78 ++ )
switch ( * V_78 ) {
case 'F' : case 'f' :
if ( V_79 )
return 0 ;
V_79 = 1 ;
break;
case 'P' : case 'p' :
if ( V_67 )
return 0 ;
V_67 = 1 ;
break;
case 'Z' : case 'z' :
if ( V_80 )
return 0 ;
V_80 = 1 ;
break;
case 'U' : case 'u' :
if ( V_81 )
return 0 ;
V_81 = 1 ;
break;
case 'T' : case 't' :
if ( V_82 )
return 0 ;
V_82 = 1 ;
break;
default:
return 0 ;
}
return 1 ;
}
static int F_25 ( struct V_10 * V_11 )
{
if ( V_11 -> V_57 > 0 )
return 0 ;
if ( V_11 -> V_30 != 0 )
F_7 ( V_11 , L_38 , 1 ) ;
return 1 ;
}
static void F_26 ( struct V_10 * V_11 )
{
if ( strcmp ( V_11 -> V_5 , L_36 ) == 0 )
return;
if ( V_79 && ! V_11 -> V_63 ) {
F_7 ( V_11 , L_97 , 1 ) ;
}
if ( ! V_79 && V_11 -> V_63 ) {
if ( F_25 ( V_11 ) )
F_7 ( V_11 , L_97 , 0 ) ;
else
fprintf ( V_3 , L_98 , V_11 -> V_5 ) ;
}
if ( V_80 && ! V_11 -> V_66 ) {
if ( F_25 ( V_11 ) )
F_7 ( V_11 , L_99 , 1 ) ;
else
fprintf ( V_3 , L_100 , V_11 -> V_5 ) ;
}
if ( ! V_80 && V_11 -> V_66 ) {
if ( F_25 ( V_11 ) )
F_7 ( V_11 , L_99 , 0 ) ;
else
fprintf ( V_3 , L_101 , V_11 -> V_5 ) ;
}
if ( V_67 && ! V_11 -> V_67 ) {
if ( F_25 ( V_11 ) )
F_7 ( V_11 , L_102 , 1 ) ;
else
fprintf ( V_3 , L_103 , V_11 -> V_5 ) ;
}
if ( ! V_67 && V_11 -> V_67 ) {
if ( F_25 ( V_11 ) )
F_7 ( V_11 , L_102 , 0 ) ;
else
fprintf ( V_3 , L_104 , V_11 -> V_5 ) ;
}
if ( V_81 && ! V_11 -> V_68 ) {
if ( F_25 ( V_11 ) )
F_7 ( V_11 , L_105 , 1 ) ;
else
fprintf ( V_3 , L_106 , V_11 -> V_5 ) ;
}
if ( ! V_81 && V_11 -> V_68 ) {
if ( F_25 ( V_11 ) )
F_7 ( V_11 , L_105 , 0 ) ;
else
fprintf ( V_3 , L_107 , V_11 -> V_5 ) ;
}
if ( V_82 && ! V_11 -> V_71 ) {
if ( V_30 == 1 )
F_7 ( V_11 , L_108 , 1 ) ;
else
fprintf ( V_3 , L_109 , V_11 -> V_5 ) ;
}
if ( ! V_82 && V_11 -> V_71 )
F_7 ( V_11 , L_108 , 1 ) ;
}
static void F_27 ( void )
{
struct V_10 * V_11 ;
int V_83 = 0 ;
char V_84 [ 20 ] , V_85 [ 20 ] , V_86 [ 20 ] , V_87 [ 20 ] ;
unsigned long long V_88 = 1ULL << 63 ;
unsigned long long V_89 = V_88 , V_90 = 0 , V_91 ;
unsigned long long V_92 = V_88 , V_93 = 0 ,
V_94 , V_95 = 0 ;
unsigned long long V_96 = V_88 , V_97 = 0 ,
V_98 , V_99 = 0 ;
unsigned long long V_100 = V_88 , V_101 = 0 ,
V_102 , V_103 = 0 ;
unsigned long long V_104 = V_88 , V_105 = 0 ,
V_106 , V_107 = 0 ;
unsigned long long V_108 = V_88 , V_109 = 0 ,
V_110 , V_111 = 0 ;
unsigned long long V_112 = V_88 , V_113 = 0 ,
V_114 , V_115 = 0 ;
unsigned long long V_116 = V_88 ,
V_117 = 0 , V_118 ,
V_119 = 0 ;
unsigned long long V_120 = V_88 ,
V_121 = 0 , V_122 ,
V_123 = 0 ;
unsigned long V_124 = 100 , V_125 = 0 ,
V_126 , V_127 = 0 ;
unsigned long V_128 = V_88 , V_129 = 0 ,
V_130 , V_131 = 0 ;
unsigned long V_132 = 100 , V_133 = 0 ,
V_134 , V_135 = 0 ;
for ( V_11 = V_10 ; V_11 < V_10 + V_30 ; V_11 ++ ) {
unsigned long long V_136 ;
unsigned long V_137 ;
unsigned long long V_138 ;
unsigned long long V_139 ;
unsigned long V_140 ;
unsigned long V_141 ;
if ( ! V_11 -> V_30 || ! V_11 -> V_57 )
continue;
V_83 ++ ;
V_136 = F_15 ( V_11 ) ;
V_137 = V_11 -> V_57 * V_11 -> V_62 ;
V_138 = V_136 - V_137 ;
V_139 = V_11 -> F_15 - V_11 -> V_62 ;
V_140 = V_11 -> V_64 * 100 / V_11 -> V_30 ;
if ( V_140 > 100 )
V_140 = 100 ;
V_141 = V_11 -> V_142 * 100
/ V_11 -> V_57 ;
if ( V_141 > 100 )
V_141 = 100 ;
if ( V_11 -> V_62 < V_89 )
V_89 = V_11 -> V_62 ;
if ( V_11 -> V_64 < V_92 )
V_92 = V_11 -> V_64 ;
if ( V_11 -> V_30 < V_96 )
V_96 = V_11 -> V_30 ;
if ( V_136 < V_100 )
V_100 = V_136 ;
if ( V_138 < V_108 )
V_108 = V_138 ;
if ( V_139 < V_116 )
V_116 = V_139 ;
if ( V_11 -> V_57 < V_112 )
V_112 = V_11 -> V_57 ;
if ( V_137 < V_104 )
V_104 = V_137 ;
if ( V_11 -> V_142 < V_128 )
V_128 = V_11 -> V_142 ;
if ( V_140 < V_124 )
V_124 = V_140 ;
if ( V_141 < V_132 )
V_132 = V_141 ;
if ( V_11 -> F_15 < V_120 )
V_120 = V_11 -> F_15 ;
if ( V_11 -> V_62 > V_90 )
V_90 = V_11 -> V_62 ;
if ( V_11 -> V_64 > V_93 )
V_93 = V_11 -> V_64 ;
if ( V_11 -> V_30 > V_97 )
V_97 = V_11 -> V_30 ;
if ( V_136 > V_101 )
V_101 = V_136 ;
if ( V_138 > V_109 )
V_109 = V_138 ;
if ( V_139 > V_117 )
V_117 = V_139 ;
if ( V_11 -> V_57 > V_113 )
V_113 = V_11 -> V_57 ;
if ( V_137 > V_105 )
V_105 = V_137 ;
if ( V_11 -> V_142 > V_129 )
V_129 = V_11 -> V_142 ;
if ( V_140 > V_125 )
V_125 = V_140 ;
if ( V_141 > V_133 )
V_133 = V_141 ;
if ( V_11 -> F_15 > V_121 )
V_121 = V_11 -> F_15 ;
V_95 += V_11 -> V_64 ;
V_99 += V_11 -> V_30 ;
V_103 += V_136 ;
V_111 += V_138 ;
V_115 += V_11 -> V_57 ;
V_107 += V_137 ;
V_131 += V_11 -> V_142 ;
V_127 += V_140 ;
V_135 += V_141 ;
V_119 += V_11 -> V_57 * V_139 ;
V_123 += V_11 -> V_57 * V_11 -> F_15 ;
}
if ( ! V_115 ) {
printf ( L_110 ) ;
return;
}
if ( ! V_83 ) {
printf ( L_111 ) ;
return;
}
V_94 = V_95 / V_83 ;
V_98 = V_99 / V_83 ;
V_102 = V_103 / V_83 ;
V_110 = V_111 / V_83 ;
V_114 = V_115 / V_83 ;
V_106 = V_107 / V_83 ;
V_130 = V_131 / V_83 ;
V_126 = V_127 / V_83 ;
V_134 = V_135 / V_83 ;
V_91 = V_107 / V_115 ;
V_118 = V_119 / V_115 ;
V_130 = V_131 * 100 / V_115 ;
V_122 = V_123 / V_115 ;
printf ( L_112 ) ;
printf ( L_113 ) ;
printf ( L_114 ,
V_30 , V_28 , V_143 , V_83 ) ;
F_9 ( V_84 , V_103 ) ; F_9 ( V_85 , V_111 ) ;
F_9 ( V_86 , V_111 * 100 / V_107 ) ;
printf ( L_115 , V_84 , V_85 , V_86 ) ;
F_9 ( V_84 , V_115 ) ; F_9 ( V_85 , V_131 ) ;
F_9 ( V_86 , V_131 * 100 / V_115 ) ;
printf ( L_116 , V_84 , V_85 , V_86 ) ;
printf ( L_50 ) ;
printf ( L_117 ) ;
printf ( L_118 ) ;
F_9 ( V_84 , V_114 ) ; F_9 ( V_85 , V_112 ) ;
F_9 ( V_86 , V_113 ) ; F_9 ( V_87 , V_115 ) ;
printf ( L_119 ,
V_84 , V_85 , V_86 , V_87 ) ;
F_9 ( V_84 , V_98 ) ; F_9 ( V_85 , V_96 ) ;
F_9 ( V_86 , V_97 ) ; F_9 ( V_87 , V_99 ) ;
printf ( L_120 ,
V_84 , V_85 , V_86 , V_87 ) ;
F_9 ( V_84 , V_94 ) ; F_9 ( V_85 , V_92 ) ;
F_9 ( V_86 , V_93 ) ; F_9 ( V_87 , V_95 ) ;
printf ( L_121 ,
V_84 , V_85 , V_86 , V_87 ) ;
F_9 ( V_84 , V_126 ) ; F_9 ( V_85 , V_124 ) ;
F_9 ( V_86 , V_125 ) ;
F_9 ( V_87 , V_95 * 100 / V_99 ) ;
printf ( L_122 ,
V_84 , V_85 , V_86 , V_87 ) ;
F_9 ( V_84 , V_130 ) ; F_9 ( V_85 , V_128 ) ;
F_9 ( V_86 , V_129 ) ;
F_9 ( V_87 , V_131 ) ;
printf ( L_123 ,
V_84 , V_85 , V_86 , V_87 ) ;
F_9 ( V_84 , V_134 ) ; F_9 ( V_85 , V_132 ) ;
F_9 ( V_86 , V_133 ) ;
F_9 ( V_87 , V_131 * 100 / V_115 ) ;
printf ( L_124 ,
V_84 , V_85 , V_86 , V_87 ) ;
F_9 ( V_84 , V_102 ) ; F_9 ( V_85 , V_100 ) ;
F_9 ( V_86 , V_101 ) ; F_9 ( V_87 , V_103 ) ;
printf ( L_125 ,
V_84 , V_85 , V_86 , V_87 ) ;
F_9 ( V_84 , V_106 ) ; F_9 ( V_85 , V_104 ) ;
F_9 ( V_86 , V_105 ) ; F_9 ( V_87 , V_107 ) ;
printf ( L_126 ,
V_84 , V_85 , V_86 , V_87 ) ;
F_9 ( V_84 , V_110 ) ; F_9 ( V_85 , V_108 ) ;
F_9 ( V_86 , V_109 ) ; F_9 ( V_87 , V_111 ) ;
printf ( L_127 ,
V_84 , V_85 , V_86 , V_87 ) ;
printf ( L_50 ) ;
printf ( L_128 ) ;
printf ( L_129 ) ;
F_9 ( V_84 , V_122 ) ; F_9 ( V_85 , V_120 ) ;
F_9 ( V_86 , V_121 ) ;
printf ( L_130 ,
V_84 , V_85 , V_86 ) ;
F_9 ( V_84 , V_91 ) ; F_9 ( V_85 , V_89 ) ;
F_9 ( V_86 , V_90 ) ;
printf ( L_131 ,
V_84 , V_85 , V_86 ) ;
F_9 ( V_84 , V_118 ) ; F_9 ( V_85 , V_116 ) ;
F_9 ( V_86 , V_117 ) ;
printf ( L_132 ,
V_84 , V_85 , V_86 ) ;
}
static void F_28 ( void )
{
struct V_10 * V_144 , * V_145 ;
for ( V_144 = V_10 ; V_144 < V_10 + V_30 ; V_144 ++ ) {
for ( V_145 = V_144 + 1 ; V_145 < V_10 + V_30 ; V_145 ++ ) {
int V_8 ;
if ( V_146 )
V_8 = F_15 ( V_144 ) < F_15 ( V_145 ) ;
else if ( V_147 )
V_8 = F_16 ( V_144 ) < F_16 ( V_145 ) ;
else
V_8 = strcasecmp ( V_144 -> V_5 , V_145 -> V_5 ) ;
if ( V_148 )
V_8 = - V_8 ;
if ( V_8 > 0 ) {
struct V_10 V_18 ;
memcpy ( & V_18 , V_144 , sizeof( struct V_10 ) ) ;
memcpy ( V_144 , V_145 , sizeof( struct V_10 ) ) ;
memcpy ( V_145 , & V_18 , sizeof( struct V_10 ) ) ;
}
}
}
}
static void F_29 ( void )
{
struct V_24 * V_149 , * V_150 ;
for ( V_149 = V_24 ; V_149 < V_24 + V_28 ; V_149 ++ ) {
for ( V_150 = V_149 + 1 ; V_150 < V_24 + V_28 ; V_150 ++ ) {
char * V_151 , * V_152 ;
V_151 = V_149 -> V_5 ;
V_152 = V_150 -> V_5 ;
if ( V_153 && ! V_148 ) {
V_151 = V_149 -> V_154 ;
V_152 = V_150 -> V_154 ;
}
if ( strcasecmp ( V_151 , V_152 ) > 0 ) {
struct V_24 V_18 ;
memcpy ( & V_18 , V_149 , sizeof( struct V_24 ) ) ;
memcpy ( V_149 , V_150 , sizeof( struct V_24 ) ) ;
memcpy ( V_150 , & V_18 , sizeof( struct V_24 ) ) ;
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
if ( strcmp ( V_26 -> V_154 , V_11 -> V_5 ) == 0 ) {
V_26 -> V_29 = V_11 ;
V_11 -> V_155 ++ ;
break;
}
if ( V_11 == V_10 + V_30 )
F_1 ( L_133 , V_26 -> V_154 ) ;
}
}
static void F_31 ( void )
{
struct V_24 * V_26 ;
char * V_156 = NULL ;
F_29 () ;
F_30 () ;
for( V_26 = V_24 ; V_26 < V_24 + V_28 ; V_26 ++ ) {
if ( ! V_157 && V_26 -> V_29 -> V_155 == 1 )
continue;
if ( ! V_148 ) {
if ( V_156 ) {
if ( strcmp ( V_26 -> V_29 -> V_5 , V_156 ) == 0 ) {
printf ( L_134 , V_26 -> V_5 ) ;
continue;
}
}
printf ( L_135 , V_26 -> V_29 -> V_5 , V_26 -> V_5 ) ;
V_156 = V_26 -> V_29 -> V_5 ;
}
else
printf ( L_136 , V_26 -> V_5 , V_26 -> V_29 -> V_5 ) ;
}
if ( V_156 )
printf ( L_50 ) ;
}
static void F_32 ( void )
{
struct V_10 * V_11 ;
struct V_24 * V_26 ;
for ( V_11 = V_10 ; V_11 < V_10 + V_30 ; V_11 ++ ) {
if ( * V_11 -> V_5 != ':' )
continue;
if ( V_11 -> V_155 > 1 && ! V_158 )
continue;
V_26 = F_14 ( V_11 ) ;
if ( V_26 )
V_11 -> V_5 = V_26 -> V_5 ;
else {
V_11 -> V_5 = L_36 ;
V_75 -- ;
}
}
}
static int F_33 ( char * V_29 )
{
return regexec ( & V_159 , V_29 , 0 , NULL , 0 ) ;
}
static void F_34 ( void )
{
T_4 * V_160 ;
struct V_161 * V_162 ;
struct V_10 * V_29 = V_10 ;
struct V_24 * F_31 = V_24 ;
char * V_9 ;
char * V_18 ;
int V_163 ;
if ( F_35 ( L_137 ) && F_35 ( L_138 ) )
F_1 ( L_139 ) ;
V_160 = F_36 ( L_140 ) ;
while ( ( V_162 = F_37 ( V_160 ) ) ) {
if ( V_162 -> V_164 [ 0 ] == '.' ||
( V_162 -> V_164 [ 0 ] != ':' && F_33 ( V_162 -> V_164 ) ) )
continue;
switch ( V_162 -> V_165 ) {
case V_166 :
F_31 -> V_5 = F_6 ( V_162 -> V_164 ) ;
V_163 = F_38 ( V_162 -> V_164 , V_7 , sizeof( V_7 ) ) ;
if ( V_163 < 0 )
F_1 ( L_141 , V_162 -> V_164 ) ;
V_7 [ V_163 ] = 0 ;
V_9 = V_7 + V_163 ;
while ( V_9 > V_7 && V_9 [ - 1 ] != '/' )
V_9 -- ;
F_31 -> V_154 = F_6 ( V_9 ) ;
F_31 ++ ;
break;
case V_167 :
if ( F_35 ( V_162 -> V_164 ) )
F_1 ( L_142 , V_29 -> V_5 ) ;
V_29 -> V_5 = F_6 ( V_162 -> V_164 ) ;
V_29 -> F_31 = 0 ;
V_29 -> V_155 = 0 ;
V_29 -> V_28 = F_4 ( L_143 ) ;
V_29 -> V_69 = F_4 ( L_144 ) ;
V_29 -> V_59 = F_4 ( L_145 ) ;
V_29 -> V_65 = F_4 ( L_146 ) ;
V_29 -> V_60 = F_4 ( L_147 ) ;
V_29 -> V_58 = F_4 ( L_148 ) ;
V_29 -> V_62 = F_4 ( L_149 ) ;
V_29 -> V_57 = F_4 ( L_150 ) ;
V_29 -> V_142 = F_4 ( L_151 ) ;
V_29 -> V_168 = F_4 ( L_152 ) ;
V_29 -> V_70 = F_4 ( L_153 ) ;
V_29 -> V_32 = F_4 ( L_154 ) ;
V_29 -> V_64 = F_4 ( L_155 ) ;
V_29 -> V_64 = F_5 ( L_155 , & V_18 ) ;
F_10 ( V_29 -> V_40 , V_18 ) ;
free ( V_18 ) ;
V_29 -> V_67 = F_4 ( L_102 ) ;
V_29 -> V_61 = F_4 ( L_156 ) ;
V_29 -> V_66 = F_4 ( L_99 ) ;
V_29 -> V_63 = F_4 ( L_157 ) ;
V_29 -> F_15 = F_4 ( L_158 ) ;
V_29 -> V_30 = F_5 ( L_159 , & V_18 ) ;
F_10 ( V_29 -> V_17 , V_18 ) ;
free ( V_18 ) ;
V_29 -> V_68 = F_4 ( L_105 ) ;
V_29 -> V_71 = F_4 ( L_108 ) ;
V_29 -> V_33 = F_4 ( L_160 ) ;
V_29 -> V_35 = F_4 ( L_161 ) ;
V_29 -> V_34 = F_4 ( L_162 ) ;
V_29 -> V_36 = F_4 ( L_163 ) ;
V_29 -> V_52 = F_4 ( L_164 ) ;
V_29 -> V_48 = F_4 ( L_165 ) ;
V_29 -> V_50 = F_4 ( L_166 ) ;
V_29 -> V_49 = F_4 ( L_167 ) ;
V_29 -> V_44 = F_4 ( L_168 ) ;
V_29 -> V_54 = F_4 ( L_169 ) ;
V_29 -> V_45 = F_4 ( L_170 ) ;
V_29 -> V_53 = F_4 ( L_171 ) ;
V_29 -> V_55 = F_4 ( L_172 ) ;
V_29 -> V_56 = F_4 ( L_173 ) ;
V_29 -> V_46 = F_4 ( L_174 ) ;
V_29 -> V_47 = F_4 ( L_175 ) ;
V_29 -> V_51 = F_4 ( L_176 ) ;
V_29 -> V_77 = F_4 ( L_177 ) ;
F_35 ( L_178 ) ;
if ( V_29 -> V_5 [ 0 ] == ':' )
V_143 ++ ;
V_29 ++ ;
break;
default :
F_1 ( L_179 , V_162 -> V_165 ) ;
}
}
F_39 ( V_160 ) ;
V_30 = V_29 - V_10 ;
V_75 = V_30 ;
V_28 = F_31 - V_24 ;
if ( V_30 > V_169 )
F_1 ( L_180 ) ;
if ( V_28 > V_170 )
F_1 ( L_181 ) ;
}
static void F_40 ( void )
{
struct V_10 * V_29 ;
for ( V_29 = V_10 ; V_29 < V_10 + V_30 ; V_29 ++ ) {
if ( V_29 -> F_31 )
continue;
if ( V_171 )
F_17 ( V_29 , 0 ) ;
else if ( V_172 )
F_18 ( V_29 ) ;
else if ( V_173 )
F_11 ( V_29 ) ;
else if ( V_174 )
F_12 ( V_29 ) ;
else if ( V_175 )
F_26 ( V_29 ) ;
else if ( V_176 )
F_19 ( V_29 ) ;
else if ( V_177 )
F_23 ( V_29 ) ;
else if ( V_178 )
F_22 ( V_29 ) ;
}
}
int main ( int V_179 , char * V_180 [] )
{
int V_181 ;
int V_182 ;
char * V_183 ;
V_31 = F_41 () ;
while ( ( V_181 = F_42 ( V_179 , V_180 , L_182 ,
V_184 , NULL ) ) != - 1 )
switch ( V_181 ) {
case '1' :
V_157 = 1 ;
break;
case 'a' :
V_153 = 1 ;
break;
case 'A' :
V_147 = 1 ;
break;
case 'd' :
V_175 = 1 ;
if ( ! F_24 ( V_185 ) )
F_1 ( L_183 , V_185 ) ;
break;
case 'D' :
V_23 = 1 ;
break;
case 'e' :
V_76 = 1 ;
break;
case 'f' :
V_158 = 1 ;
break;
case 'h' :
F_2 () ;
return 0 ;
case 'i' :
V_148 = 1 ;
break;
case 'n' :
V_171 = 1 ;
break;
case 'o' :
V_176 = 1 ;
break;
case 'r' :
V_178 = 1 ;
break;
case 's' :
V_174 = 1 ;
break;
case 'l' :
V_177 = 1 ;
break;
case 't' :
V_172 = 1 ;
break;
case 'v' :
V_173 = 1 ;
break;
case 'z' :
V_38 = 0 ;
break;
case 'T' :
V_186 = 1 ;
break;
case 'S' :
V_146 = 1 ;
break;
default:
F_1 ( L_184 , V_180 [ 0 ] , V_187 ) ;
}
if ( ! V_177 && ! V_153 && ! V_172 && ! V_178
&& ! V_173 && ! V_174 && ! V_175 && ! V_176 )
V_177 = 1 ;
if ( V_179 > V_188 )
V_183 = V_180 [ V_188 ] ;
else
V_183 = L_185 ;
V_182 = regcomp ( & V_159 , V_183 , V_189 | V_190 ) ;
if ( V_182 )
F_1 ( L_186 ,
V_180 [ 0 ] , V_183 , V_182 ) ;
F_34 () ;
if ( V_153 )
F_31 () ;
else
if ( V_186 )
F_27 () ;
else {
F_30 () ;
F_32 () ;
F_28 () ;
F_40 () ;
}
return 0 ;
}
