static unsigned long F_1 ( unsigned long V_1 )
{
return ( V_1 * V_2 ) >> 20 ;
}
static void F_2 ( const char * V_3 , ... )
{
T_1 V_4 ;
va_start ( V_4 , V_3 ) ;
vfprintf ( V_5 , V_3 , V_4 ) ;
va_end ( V_4 ) ;
exit ( V_6 ) ;
}
static int F_3 ( const char * V_7 , int V_8 )
{
int V_9 = F_4 ( V_7 , V_8 ) ;
if ( V_9 < 0 ) {
perror ( V_7 ) ;
exit ( V_6 ) ;
}
return V_9 ;
}
static unsigned long F_5 ( int V_9 , char * V_10 ,
T_2 * V_11 ,
unsigned long V_12 ,
unsigned long V_13 )
{
long V_14 ;
if ( V_12 > V_15 / 8 )
F_2 ( L_1 , V_12 ) ;
V_14 = F_6 ( V_9 , V_11 , V_13 * 8 , ( V_16 ) V_12 * 8 ) ;
if ( V_14 < 0 ) {
perror ( V_10 ) ;
exit ( V_6 ) ;
}
if ( V_14 % 8 )
F_2 ( L_2 , V_14 ) ;
return V_14 / 8 ;
}
static unsigned long F_7 ( T_2 * V_11 ,
unsigned long V_12 ,
unsigned long V_1 )
{
return F_5 ( V_17 , V_18 , V_11 , V_12 , V_1 ) ;
}
static unsigned long F_8 ( T_2 * V_11 ,
unsigned long V_12 ,
unsigned long V_1 )
{
return F_5 ( V_19 , L_3 , V_11 , V_12 , V_1 ) ;
}
static unsigned long F_9 ( T_2 V_20 )
{
unsigned long V_21 ;
if ( V_20 & V_22 )
V_21 = F_10 ( V_20 ) ;
else
V_21 = 0 ;
return V_21 ;
}
static char * F_11 ( T_2 V_8 )
{
static char V_11 [ 65 ] ;
int V_23 ;
T_3 V_24 , V_25 ;
for ( V_24 = 0 , V_25 = 0 ; V_24 < F_12 ( V_26 ) ; V_24 ++ ) {
V_23 = ( V_8 >> V_24 ) & 1 ;
if ( ! V_26 [ V_24 ] ) {
if ( V_23 )
F_2 ( L_4 , V_24 ) ;
continue;
}
V_11 [ V_25 ++ ] = V_23 ? V_26 [ V_24 ] [ 0 ] : '_' ;
}
return V_11 ;
}
static char * F_13 ( T_2 V_8 )
{
static char V_11 [ 1024 ] ;
T_3 V_24 , V_27 ;
for ( V_24 = 0 , V_27 = 0 ; V_24 < F_12 ( V_26 ) ; V_24 ++ ) {
if ( ! V_26 [ V_24 ] )
continue;
if ( ( V_8 >> V_24 ) & 1 )
V_27 += snprintf ( V_11 + V_27 , sizeof( V_11 ) - V_27 , L_5 ,
V_26 [ V_24 ] + 2 ) ;
}
if ( V_27 )
V_27 -- ;
V_11 [ V_27 ] = '\0' ;
return V_11 ;
}
static void F_14 ( unsigned long V_28 , unsigned long V_29 ,
unsigned long V_30 , T_2 V_8 )
{
static T_2 V_31 ;
static unsigned long V_32 ;
static unsigned long V_12 ;
static unsigned long V_13 ;
if ( V_8 == V_31 && V_29 == V_12 + V_13 &&
V_30 && V_28 == V_32 + V_13 ) {
V_13 += V_30 ;
return;
}
if ( V_13 ) {
if ( V_33 )
printf ( L_6 , V_32 ) ;
if ( V_34 )
printf ( L_7 , V_32 ) ;
printf ( L_8 ,
V_12 , V_13 , F_11 ( V_31 ) ) ;
}
V_31 = V_8 ;
V_12 = V_29 ;
V_32 = V_28 ;
V_13 = V_30 ;
}
static void F_15 ( void )
{
F_14 ( 0 , 0 , 0 , 0 ) ;
}
static void F_16 ( unsigned long V_28 ,
unsigned long V_29 , T_2 V_8 )
{
if ( V_33 )
printf ( L_6 , V_28 ) ;
if ( V_34 )
printf ( L_7 , V_28 ) ;
printf ( L_9 , V_29 , F_11 ( V_8 ) ) ;
}
static void F_17 ( void )
{
T_3 V_24 ;
printf ( L_10
L_11 ) ;
for ( V_24 = 0 ; V_24 < F_12 ( V_35 ) ; V_24 ++ ) {
if ( V_35 [ V_24 ] )
printf ( L_12 ,
( unsigned long long ) V_36 [ V_24 ] ,
V_35 [ V_24 ] ,
F_1 ( V_35 [ V_24 ] ) ,
F_11 ( V_36 [ V_24 ] ) ,
F_13 ( V_36 [ V_24 ] ) ) ;
}
printf ( L_13 ,
V_37 , F_1 ( V_37 ) ) ;
}
static int F_18 ( T_2 V_8 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_38 ; V_24 ++ ) {
if ( V_39 [ V_24 ] == V_40 ) {
if ( ( V_8 & V_41 [ V_24 ] ) == 0 )
return 0 ;
} else {
if ( ( V_8 & V_41 [ V_24 ] ) != V_39 [ V_24 ] )
return 0 ;
}
}
return 1 ;
}
static T_2 F_19 ( T_2 V_8 , T_2 V_42 )
{
if ( V_8 & F_20 ( V_43 ) ) {
if ( V_8 & F_20 ( V_44 ) )
V_8 ^= F_20 ( V_44 ) | F_20 ( V_45 ) ;
if ( V_8 & F_20 ( V_46 ) )
V_8 ^= F_20 ( V_46 ) | F_20 ( V_47 ) ;
if ( V_8 & F_20 ( ERROR ) )
V_8 ^= F_20 ( ERROR ) | F_20 ( V_48 ) ;
}
if ( ( V_8 & ( F_20 ( V_49 ) | F_20 ( V_50 ) ) ) == F_20 ( V_49 ) )
V_8 ^= F_20 ( V_49 ) | F_20 ( V_51 ) ;
if ( V_42 & V_52 )
V_8 |= F_20 ( V_53 ) ;
return V_8 ;
}
static T_2 F_21 ( T_2 V_8 )
{
V_8 &= ~ V_54 ;
if ( ( V_8 & V_55 ) && ! ( V_8 & F_20 ( V_56 ) ) )
V_8 &= ~ V_55 ;
return V_8 ;
}
static T_2 F_22 ( T_2 V_8 , T_2 V_42 )
{
if ( V_57 )
V_8 = F_19 ( V_8 , V_42 ) ;
else
V_8 = F_21 ( V_8 ) ;
return V_8 ;
}
static void F_23 ( void )
{
char V_11 [ V_58 + 1 ] ;
V_59 = F_24 ( NULL ) ;
if ( ! V_59 ) {
perror ( L_14 ) ;
exit ( V_6 ) ;
}
if ( V_60 && ! V_61 ) {
snprintf ( V_11 , V_58 , L_15 ,
V_59 ) ;
V_61 = F_3 ( V_11 , V_62 ) ;
}
if ( V_63 && ! V_64 ) {
snprintf ( V_11 , V_58 , L_16 ,
V_59 ) ;
V_64 = F_3 ( V_11 , V_62 ) ;
}
}
static int F_25 ( unsigned long V_29 )
{
char V_11 [ 100 ] ;
int V_65 ;
V_65 = sprintf ( V_11 , L_17 , V_29 ) ;
V_65 = F_26 ( V_61 , V_11 , V_65 ) ;
if ( V_65 < 0 ) {
perror ( L_18 ) ;
return V_65 ;
}
return 0 ;
}
static int F_27 ( unsigned long V_29 )
{
char V_11 [ 100 ] ;
int V_65 ;
V_65 = sprintf ( V_11 , L_17 , V_29 ) ;
V_65 = F_26 ( V_64 , V_11 , V_65 ) ;
if ( V_65 < 0 ) {
perror ( L_19 ) ;
return V_65 ;
}
return 0 ;
}
static T_3 F_28 ( T_2 V_8 )
{
T_3 V_66 = F_29 ( V_8 ) ;
T_3 V_24 ;
if ( V_8 == 0 )
return 0 ;
for ( V_24 = 1 ; V_24 < F_12 ( V_36 ) ; V_24 ++ , V_66 ++ ) {
if ( ! V_66 || V_66 >= F_12 ( V_36 ) )
V_66 = 1 ;
if ( V_36 [ V_66 ] == 0 ) {
V_36 [ V_66 ] = V_8 ;
return V_66 ;
}
if ( V_36 [ V_66 ] == V_8 )
return V_66 ;
}
F_2 ( L_20 ) ;
exit ( V_6 ) ;
}
static void F_30 ( unsigned long V_28 ,
unsigned long V_29 , T_2 V_8 , T_2 V_42 )
{
V_8 = F_22 ( V_8 , V_42 ) ;
if ( ! F_18 ( V_8 ) )
return;
if ( V_60 )
F_25 ( V_29 ) ;
if ( V_63 )
F_27 ( V_29 ) ;
if ( V_67 == 1 )
F_14 ( V_28 , V_29 , 1 , V_8 ) ;
else if ( V_67 == 2 )
F_16 ( V_28 , V_29 , V_8 ) ;
V_35 [ F_28 ( V_8 ) ] ++ ;
V_37 ++ ;
}
static void F_31 ( unsigned long V_28 ,
unsigned long V_12 ,
unsigned long V_13 ,
T_2 V_42 )
{
T_2 V_11 [ V_68 ] ;
unsigned long V_69 ;
unsigned long V_1 ;
unsigned long V_24 ;
while ( V_13 ) {
V_69 = F_32 (unsigned long, count, KPAGEFLAGS_BATCH) ;
V_1 = F_7 ( V_11 , V_12 , V_69 ) ;
if ( V_1 == 0 )
break;
for ( V_24 = 0 ; V_24 < V_1 ; V_24 ++ )
F_30 ( V_28 + V_24 , V_12 + V_24 , V_11 [ V_24 ] , V_42 ) ;
V_12 += V_1 ;
V_13 -= V_1 ;
}
}
static void F_33 ( unsigned long V_12 , unsigned long V_13 )
{
T_2 V_11 [ V_70 ] ;
unsigned long V_69 ;
unsigned long V_1 ;
unsigned long V_21 ;
unsigned long V_24 ;
while ( V_13 ) {
V_69 = F_32 (unsigned long, count, PAGEMAP_BATCH) ;
V_1 = F_8 ( V_11 , V_12 , V_69 ) ;
if ( V_1 == 0 )
break;
for ( V_24 = 0 ; V_24 < V_1 ; V_24 ++ ) {
V_21 = F_9 ( V_11 [ V_24 ] ) ;
if ( V_21 )
F_31 ( V_12 + V_24 , V_21 , 1 , V_11 [ V_24 ] ) ;
}
V_12 += V_1 ;
V_13 -= V_1 ;
}
}
static void F_34 ( unsigned long V_12 , unsigned long V_13 )
{
const unsigned long V_71 = V_12 + V_13 ;
unsigned long V_72 ;
int V_24 = 0 ;
while ( V_12 < V_71 ) {
while ( V_73 [ V_24 ] <= V_12 )
if ( ++ V_24 >= V_74 )
return;
if ( V_75 [ V_24 ] >= V_71 )
return;
V_72 = F_35 (unsigned long, pg_start[i], index) ;
V_12 = F_32 (unsigned long, pg_end[i], end) ;
assert ( V_72 < V_12 ) ;
F_33 ( V_72 , V_12 - V_72 ) ;
}
}
static void F_36 ( unsigned long V_29 , unsigned long V_30 )
{
if ( V_76 >= V_77 )
F_2 ( L_21 ) ;
V_78 [ V_76 ] = V_29 ;
V_79 [ V_76 ] = F_32 (unsigned long, size, ULONG_MAX-offset) ;
V_76 ++ ;
}
static void F_37 ( void )
{
int V_24 ;
V_17 = F_3 ( V_18 , V_80 ) ;
if ( ! V_76 )
F_36 ( 0 , V_15 ) ;
for ( V_24 = 0 ; V_24 < V_76 ; V_24 ++ )
if ( ! V_33 )
F_31 ( V_78 [ V_24 ] , V_78 [ V_24 ] , V_79 [ V_24 ] , 0 ) ;
else
F_34 ( V_78 [ V_24 ] , V_79 [ V_24 ] ) ;
F_38 ( V_17 ) ;
}
static const char * F_39 ( T_2 V_81 )
{
if ( V_81 & V_54 )
return L_22 ;
if ( V_81 & V_82 )
return L_23 ;
return L_24 ;
}
static void F_40 ( void )
{
T_3 V_24 , V_25 ;
printf (
L_25
L_26
L_27
L_28
L_29
L_30
L_31
L_32
L_33
L_34
L_35
L_36
L_37
L_38
L_39
L_40
L_41
L_42
L_43
L_44
L_45
L_46
L_47
L_48
L_49
L_50
L_51
L_52
L_53
) ;
for ( V_24 = 0 , V_25 = 0 ; V_24 < F_12 ( V_26 ) ; V_24 ++ ) {
if ( ! V_26 [ V_24 ] )
continue;
printf ( L_54 , V_26 [ V_24 ] + 2 ,
F_39 ( 1ULL << V_24 ) ) ;
if ( ++ V_25 > 3 ) {
V_25 = 0 ;
putchar ( '\n' ) ;
}
}
printf ( L_55
L_56 ) ;
}
static unsigned long long F_41 ( const char * V_83 )
{
unsigned long long V_27 ;
V_27 = strtoll ( V_83 , NULL , 0 ) ;
if ( V_27 == 0 && V_83 [ 0 ] != '0' )
F_2 ( L_57 , V_83 ) ;
return V_27 ;
}
static void F_42 ( const char * V_83 )
{
T_4 * V_84 ;
char V_11 [ 5000 ] ;
V_33 = F_41 ( V_83 ) ;
sprintf ( V_11 , L_58 , V_33 ) ;
V_19 = F_3 ( V_11 , V_80 ) ;
sprintf ( V_11 , L_59 , V_33 ) ;
V_84 = fopen ( V_11 , L_60 ) ;
if ( ! V_84 ) {
perror ( V_11 ) ;
exit ( V_6 ) ;
}
while ( fgets ( V_11 , sizeof( V_11 ) , V_84 ) != NULL ) {
unsigned long V_85 ;
unsigned long V_86 ;
unsigned long long V_87 ;
int V_88 , V_89 ;
char V_90 , V_91 , V_3 , V_92 ;
unsigned long V_93 ;
int V_27 ;
V_27 = sscanf ( V_11 , L_61 ,
& V_85 ,
& V_86 ,
& V_90 , & V_91 , & V_3 , & V_92 ,
& V_87 ,
& V_88 , & V_89 ,
& V_93 ) ;
if ( V_27 < 10 ) {
fprintf ( V_5 , L_62 , V_11 ) ;
continue;
}
V_75 [ V_74 ] = V_85 / V_2 ;
V_73 [ V_74 ] = V_86 / V_2 ;
if ( ++ V_74 >= V_94 ) {
fprintf ( V_5 , L_63 ) ;
break;
}
}
fclose ( V_84 ) ;
}
static void F_43 ( const char * V_10 , const struct V_95 * V_96 )
{
unsigned long long V_30 = V_96 -> V_97 ;
char V_98 [ 64 ] , V_99 [ 64 ] ;
long V_100 = time ( NULL ) ;
printf ( L_64 ,
V_10 , ( unsigned ) V_96 -> V_101 ,
V_30 , ( V_30 + V_2 - 1 ) / V_2 ) ;
strftime ( V_98 , sizeof( V_98 ) , L_65 , localtime ( & V_96 -> V_102 ) ) ;
strftime ( V_99 , sizeof( V_99 ) , L_65 , localtime ( & V_96 -> V_103 ) ) ;
printf ( L_66 ,
V_99 , V_100 - V_96 -> V_103 ,
V_98 , V_100 - V_96 -> V_102 ) ;
}
static void F_44 ( const char * V_10 , const struct V_95 * V_96 )
{
T_5 V_104 [ V_70 ] ;
T_2 V_11 [ V_70 ] , V_8 ;
unsigned long V_35 , V_21 , V_24 ;
int V_9 ;
V_16 V_105 ;
T_6 V_65 ;
void * V_106 ;
int V_107 = 1 ;
V_9 = F_3 ( V_10 , V_80 | V_108 | V_109 ) ;
for ( V_105 = 0 ; V_105 < V_96 -> V_97 ; V_105 += V_65 ) {
V_35 = ( V_96 -> V_97 - V_105 + V_2 - 1 ) / V_2 ;
if ( V_35 > V_70 )
V_35 = V_70 ;
V_65 = V_35 * V_2 ;
V_106 = F_45 ( NULL , V_65 , V_110 , V_111 , V_9 , V_105 ) ;
if ( V_106 == V_112 )
F_2 ( L_67 , V_10 ) ;
if ( F_46 ( V_106 , V_65 , V_104 ) )
F_2 ( L_68 , V_10 ) ;
if ( F_47 ( V_106 , V_65 , V_113 ) )
F_2 ( L_69 , V_10 ) ;
for ( V_24 = 0 ; V_24 < V_35 ; V_24 ++ ) {
if ( V_104 [ V_24 ] & 1 )
( void ) * ( volatile int * ) ( V_106 + V_24 * V_2 ) ;
}
if ( F_47 ( V_106 , V_65 , V_114 ) )
F_2 ( L_69 , V_10 ) ;
if ( F_8 ( V_11 , ( unsigned long ) V_106 / V_2 ,
V_35 ) != V_35 )
F_2 ( L_70 ) ;
F_48 ( V_106 , V_65 ) ;
for ( V_24 = 0 ; V_24 < V_35 ; V_24 ++ ) {
V_21 = F_9 ( V_11 [ V_24 ] ) ;
if ( ! V_21 )
continue;
if ( ! F_7 ( & V_8 , V_21 , 1 ) )
continue;
if ( V_107 && V_67 ) {
V_107 = 0 ;
F_15 () ;
F_43 ( V_10 , V_96 ) ;
}
F_30 ( V_105 / V_2 + V_24 , V_21 , V_8 , V_11 [ V_24 ] ) ;
}
}
F_38 ( V_9 ) ;
}
int F_49 ( const char * V_10 , const struct V_95 * V_96 , int type , struct V_115 * V_116 )
{
( void ) V_116 ;
switch ( type ) {
case V_117 :
if ( F_50 ( V_96 -> V_118 ) )
F_44 ( V_10 , V_96 ) ;
break;
case V_119 :
fprintf ( V_5 , L_71 , V_10 ) ;
break;
}
return 0 ;
}
static void F_51 ( void )
{
struct V_95 V_96 ;
V_17 = F_3 ( V_18 , V_80 ) ;
V_19 = F_3 ( L_72 , V_80 ) ;
if ( V_95 ( V_34 , & V_96 ) )
F_2 ( L_73 , V_34 ) ;
if ( F_50 ( V_96 . V_118 ) ) {
F_44 ( V_34 , & V_96 ) ;
} else if ( F_52 ( V_96 . V_118 ) ) {
if ( F_53 ( V_34 , F_49 , 64 , V_120 | V_121 ) < 0 )
F_2 ( L_74 , V_34 ) ;
} else
F_2 ( L_75 , V_34 ) ;
F_38 ( V_17 ) ;
F_38 ( V_19 ) ;
}
static void F_54 ( const char * V_10 )
{
V_34 = V_10 ;
}
static void F_55 ( const char * V_122 )
{
unsigned long V_29 ;
unsigned long V_30 ;
char * V_123 ;
V_123 = strchr ( V_122 , ',' ) ;
if ( ! V_123 )
V_123 = strchr ( V_122 , '+' ) ;
if ( V_123 == V_122 ) {
V_29 = 0 ;
V_30 = F_41 ( V_123 + 1 ) ;
} else if ( V_123 ) {
V_29 = F_41 ( V_122 ) ;
if ( V_123 [ 1 ] == '\0' )
V_30 = V_15 ;
else {
V_30 = F_41 ( V_123 + 1 ) ;
if ( * V_123 == ',' ) {
if ( V_30 < V_29 )
F_2 ( L_76 ,
V_29 , V_30 ) ;
V_30 -= V_29 ;
}
}
} else {
V_29 = F_41 ( V_122 ) ;
V_30 = 1 ;
}
F_36 ( V_29 , V_30 ) ;
}
static void F_56 ( T_2 V_124 , T_2 V_125 )
{
if ( V_38 >= V_126 )
F_2 ( L_77 ) ;
V_41 [ V_38 ] = V_124 ;
V_39 [ V_38 ] = V_125 ;
V_38 ++ ;
}
static T_2 F_57 ( const char * V_83 , int V_65 )
{
T_3 V_24 ;
if ( ! * V_83 || ! V_65 )
return 0 ;
if ( V_65 <= 8 && ! strncmp ( V_83 , L_78 , V_65 ) )
return V_55 ;
for ( V_24 = 0 ; V_24 < F_12 ( V_26 ) ; V_24 ++ ) {
if ( ! V_26 [ V_24 ] )
continue;
if ( ! strncmp ( V_83 , V_26 [ V_24 ] + 2 , V_65 ) )
return 1ULL << V_24 ;
}
return F_41 ( V_83 ) ;
}
static T_2 F_58 ( const char * V_83 , int V_127 )
{
const char * V_123 = V_83 ;
T_2 V_8 = 0 ;
while ( 1 ) {
if ( * V_123 == ',' || * V_123 == '=' || * V_123 == '\0' ) {
if ( ( * V_83 != '~' ) || ( * V_83 == '~' && V_127 && * ++ V_83 ) )
V_8 |= F_57 ( V_83 , V_123 - V_83 ) ;
if ( * V_123 != ',' )
break;
V_83 = V_123 + 1 ;
}
V_123 ++ ;
}
return V_8 ;
}
static void F_59 ( const char * V_122 )
{
T_2 V_124 ;
T_2 V_125 ;
const char * V_123 ;
V_123 = strchr ( V_122 , '=' ) ;
if ( V_123 == V_122 ) {
V_124 = V_40 ;
V_125 = F_58 ( V_123 + 1 , 0 ) ;
} else if ( V_123 ) {
V_124 = F_58 ( V_122 , 0 ) ;
V_125 = F_58 ( V_123 + 1 , 0 ) ;
} else if ( strchr ( V_122 , '~' ) ) {
V_124 = F_58 ( V_122 , 1 ) ;
V_125 = F_58 ( V_122 , 0 ) ;
} else {
V_124 = F_58 ( V_122 , 0 ) ;
V_125 = V_40 ;
}
F_56 ( V_124 , V_125 ) ;
}
static void F_60 ( const char * V_122 )
{
T_2 V_8 = F_58 ( V_122 , 0 ) ;
printf ( L_79 ,
( unsigned long long ) V_8 ,
F_11 ( V_8 ) ,
F_13 ( V_8 ) ) ;
}
int main ( int V_128 , char * V_129 [] )
{
int V_130 ;
V_2 = F_61 () ;
while ( ( V_130 = F_62 ( V_128 , V_129 ,
L_80 , V_131 , NULL ) ) != - 1 ) {
switch ( V_130 ) {
case 'r' :
V_57 = 1 ;
break;
case 'p' :
F_42 ( V_122 ) ;
break;
case 'f' :
F_54 ( V_122 ) ;
break;
case 'a' :
F_55 ( V_122 ) ;
break;
case 'b' :
F_59 ( V_122 ) ;
break;
case 'd' :
F_60 ( V_122 ) ;
exit ( 0 ) ;
case 'l' :
V_67 = 1 ;
break;
case 'L' :
V_67 = 2 ;
break;
case 'N' :
V_132 = 1 ;
break;
case 'X' :
V_60 = 1 ;
F_23 () ;
break;
case 'x' :
V_63 = 1 ;
F_23 () ;
break;
case 'h' :
F_40 () ;
exit ( 0 ) ;
default:
F_40 () ;
exit ( 1 ) ;
}
}
if ( V_67 && V_33 )
printf ( L_81 ) ;
if ( V_67 && V_34 )
printf ( L_82 ) ;
if ( V_67 == 1 )
printf ( L_83 ) ;
if ( V_67 == 2 )
printf ( L_84 ) ;
if ( V_34 )
F_51 () ;
else
F_37 () ;
if ( V_67 == 1 )
F_15 () ;
if ( V_132 )
return 0 ;
if ( V_67 )
printf ( L_85 ) ;
F_17 () ;
return 0 ;
}
