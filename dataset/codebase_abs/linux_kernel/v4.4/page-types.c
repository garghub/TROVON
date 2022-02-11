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
if ( V_42 & V_54 )
V_8 |= F_20 ( V_55 ) ;
if ( V_42 & V_56 )
V_8 |= F_20 ( V_57 ) ;
return V_8 ;
}
static T_2 F_21 ( T_2 V_8 )
{
V_8 &= ~ V_58 ;
if ( ( V_8 & V_59 ) && ! ( V_8 & F_20 ( V_60 ) ) )
V_8 &= ~ V_59 ;
return V_8 ;
}
static T_2 F_22 ( T_2 V_8 , T_2 V_42 )
{
if ( V_61 )
V_8 = F_19 ( V_8 , V_42 ) ;
else
V_8 = F_21 ( V_8 ) ;
return V_8 ;
}
static void F_23 ( void )
{
char V_11 [ V_62 + 1 ] ;
V_63 = F_24 () ;
if ( ! V_63 ) {
perror ( L_14 ) ;
exit ( V_6 ) ;
}
if ( V_64 && ! V_65 ) {
snprintf ( V_11 , V_62 , L_15 ,
V_63 ) ;
V_65 = F_3 ( V_11 , V_66 ) ;
}
if ( V_67 && ! V_68 ) {
snprintf ( V_11 , V_62 , L_16 ,
V_63 ) ;
V_68 = F_3 ( V_11 , V_66 ) ;
}
}
static int F_25 ( unsigned long V_29 )
{
char V_11 [ 100 ] ;
int V_69 ;
V_69 = sprintf ( V_11 , L_17 , V_29 ) ;
V_69 = F_26 ( V_65 , V_11 , V_69 ) ;
if ( V_69 < 0 ) {
perror ( L_18 ) ;
return V_69 ;
}
return 0 ;
}
static int F_27 ( unsigned long V_29 )
{
char V_11 [ 100 ] ;
int V_69 ;
V_69 = sprintf ( V_11 , L_17 , V_29 ) ;
V_69 = F_26 ( V_68 , V_11 , V_69 ) ;
if ( V_69 < 0 ) {
perror ( L_19 ) ;
return V_69 ;
}
return 0 ;
}
static T_3 F_28 ( T_2 V_8 )
{
T_3 V_70 = F_29 ( V_8 ) ;
T_3 V_24 ;
if ( V_8 == 0 )
return 0 ;
for ( V_24 = 1 ; V_24 < F_12 ( V_36 ) ; V_24 ++ , V_70 ++ ) {
if ( ! V_70 || V_70 >= F_12 ( V_36 ) )
V_70 = 1 ;
if ( V_36 [ V_70 ] == 0 ) {
V_36 [ V_70 ] = V_8 ;
return V_70 ;
}
if ( V_36 [ V_70 ] == V_8 )
return V_70 ;
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
if ( V_64 )
F_25 ( V_29 ) ;
if ( V_67 )
F_27 ( V_29 ) ;
if ( V_71 == 1 )
F_14 ( V_28 , V_29 , 1 , V_8 ) ;
else if ( V_71 == 2 )
F_16 ( V_28 , V_29 , V_8 ) ;
V_35 [ F_28 ( V_8 ) ] ++ ;
V_37 ++ ;
}
static void F_31 ( unsigned long V_28 ,
unsigned long V_12 ,
unsigned long V_13 ,
T_2 V_42 )
{
T_2 V_11 [ V_72 ] ;
unsigned long V_73 ;
unsigned long V_1 ;
unsigned long V_24 ;
while ( V_13 ) {
V_73 = F_32 (unsigned long, count, KPAGEFLAGS_BATCH) ;
V_1 = F_7 ( V_11 , V_12 , V_73 ) ;
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
T_2 V_11 [ V_74 ] ;
unsigned long V_73 ;
unsigned long V_1 ;
unsigned long V_21 ;
unsigned long V_24 ;
while ( V_13 ) {
V_73 = F_32 (unsigned long, count, PAGEMAP_BATCH) ;
V_1 = F_8 ( V_11 , V_12 , V_73 ) ;
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
const unsigned long V_75 = V_12 + V_13 ;
unsigned long V_76 ;
int V_24 = 0 ;
while ( V_12 < V_75 ) {
while ( V_77 [ V_24 ] <= V_12 )
if ( ++ V_24 >= V_78 )
return;
if ( V_79 [ V_24 ] >= V_75 )
return;
V_76 = F_35 (unsigned long, pg_start[i], index) ;
V_12 = F_32 (unsigned long, pg_end[i], end) ;
assert ( V_76 < V_12 ) ;
F_33 ( V_76 , V_12 - V_76 ) ;
}
}
static void F_36 ( unsigned long V_29 , unsigned long V_30 )
{
if ( V_80 >= V_81 )
F_2 ( L_21 ) ;
V_82 [ V_80 ] = V_29 ;
V_83 [ V_80 ] = F_32 (unsigned long, size, ULONG_MAX-offset) ;
V_80 ++ ;
}
static void F_37 ( void )
{
int V_24 ;
V_17 = F_3 ( V_18 , V_84 ) ;
if ( ! V_80 )
F_36 ( 0 , V_15 ) ;
for ( V_24 = 0 ; V_24 < V_80 ; V_24 ++ )
if ( ! V_33 )
F_31 ( V_82 [ V_24 ] , V_82 [ V_24 ] , V_83 [ V_24 ] , 0 ) ;
else
F_34 ( V_82 [ V_24 ] , V_83 [ V_24 ] ) ;
F_38 ( V_17 ) ;
}
static const char * F_39 ( T_2 V_85 )
{
if ( V_85 & V_58 )
return L_22 ;
if ( V_85 & V_86 )
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
static unsigned long long F_41 ( const char * V_87 )
{
unsigned long long V_27 ;
V_27 = strtoll ( V_87 , NULL , 0 ) ;
if ( V_27 == 0 && V_87 [ 0 ] != '0' )
F_2 ( L_57 , V_87 ) ;
return V_27 ;
}
static void F_42 ( const char * V_87 )
{
V_55 * V_88 ;
char V_11 [ 5000 ] ;
V_33 = F_41 ( V_87 ) ;
sprintf ( V_11 , L_58 , V_33 ) ;
V_19 = F_3 ( V_11 , V_84 ) ;
sprintf ( V_11 , L_59 , V_33 ) ;
V_88 = fopen ( V_11 , L_60 ) ;
if ( ! V_88 ) {
perror ( V_11 ) ;
exit ( V_6 ) ;
}
while ( fgets ( V_11 , sizeof( V_11 ) , V_88 ) != NULL ) {
unsigned long V_89 ;
unsigned long V_90 ;
unsigned long long V_91 ;
int V_92 , V_93 ;
char V_94 , V_95 , V_3 , V_96 ;
unsigned long V_97 ;
int V_27 ;
V_27 = sscanf ( V_11 , L_61 ,
& V_89 ,
& V_90 ,
& V_94 , & V_95 , & V_3 , & V_96 ,
& V_91 ,
& V_92 , & V_93 ,
& V_97 ) ;
if ( V_27 < 10 ) {
fprintf ( V_5 , L_62 , V_11 ) ;
continue;
}
V_79 [ V_78 ] = V_89 / V_2 ;
V_77 [ V_78 ] = V_90 / V_2 ;
if ( ++ V_78 >= V_98 ) {
fprintf ( V_5 , L_63 ) ;
break;
}
}
fclose ( V_88 ) ;
}
static void F_43 ( const char * V_10 , const struct V_99 * V_100 )
{
unsigned long long V_30 = V_100 -> V_101 ;
char V_102 [ 64 ] , V_103 [ 64 ] ;
long V_104 = time ( NULL ) ;
printf ( L_64 ,
V_10 , ( unsigned ) V_100 -> V_105 ,
V_30 , ( V_30 + V_2 - 1 ) / V_2 ) ;
strftime ( V_102 , sizeof( V_102 ) , L_65 , localtime ( & V_100 -> V_106 ) ) ;
strftime ( V_103 , sizeof( V_103 ) , L_65 , localtime ( & V_100 -> V_107 ) ) ;
printf ( L_66 ,
V_103 , V_104 - V_100 -> V_107 ,
V_102 , V_104 - V_100 -> V_106 ) ;
}
static void F_44 ( int V_108 , T_4 * V_109 , void * V_110 )
{
( void ) V_108 ;
( void ) V_110 ;
V_111 = V_109 ? V_109 -> V_112 : NULL ;
F_45 ( V_113 , 1 ) ;
}
static void F_46 ( const char * V_10 , const struct V_99 * V_100 )
{
T_5 V_114 [ V_74 ] ;
T_2 V_11 [ V_74 ] , V_8 ;
unsigned long V_35 , V_21 , V_24 ;
V_16 V_115 , V_75 = V_100 -> V_101 ;
int V_9 ;
T_6 V_69 ;
void * V_116 ;
int V_117 = 1 ;
V_9 = F_3 ( V_10 , V_84 | V_118 | V_119 ) ;
for ( V_115 = 0 ; V_115 < V_75 ; V_115 += V_69 ) {
V_35 = ( V_75 - V_115 + V_2 - 1 ) / V_2 ;
if ( V_35 > V_74 )
V_35 = V_74 ;
V_69 = V_35 * V_2 ;
V_116 = F_47 ( NULL , V_69 , V_120 , V_121 , V_9 , V_115 ) ;
if ( V_116 == V_122 )
F_2 ( L_67 , V_10 ) ;
if ( F_48 ( V_116 , V_69 , V_114 ) )
F_2 ( L_68 , V_10 ) ;
if ( F_49 ( V_116 , V_69 , V_123 ) )
F_2 ( L_69 , V_10 ) ;
if ( F_50 ( V_113 , 1 ) ) {
V_75 = V_115 + V_111 ? V_111 - V_116 : 0 ;
fprintf ( V_5 , L_70 ,
( long long ) V_75 , V_10 ) ;
goto V_124;
}
for ( V_24 = 0 ; V_24 < V_35 ; V_24 ++ ) {
if ( V_114 [ V_24 ] & 1 )
( void ) * ( volatile int * ) ( V_116 + V_24 * V_2 ) ;
}
V_124:
if ( F_49 ( V_116 , V_69 , V_125 ) )
F_2 ( L_69 , V_10 ) ;
if ( F_8 ( V_11 , ( unsigned long ) V_116 / V_2 ,
V_35 ) != V_35 )
F_2 ( L_71 ) ;
F_51 ( V_116 , V_69 ) ;
for ( V_24 = 0 ; V_24 < V_35 ; V_24 ++ ) {
V_21 = F_9 ( V_11 [ V_24 ] ) ;
if ( ! V_21 )
continue;
if ( ! F_7 ( & V_8 , V_21 , 1 ) )
continue;
if ( V_117 && V_71 ) {
V_117 = 0 ;
F_15 () ;
F_43 ( V_10 , V_100 ) ;
}
F_30 ( V_115 / V_2 + V_24 , V_21 , V_8 , V_11 [ V_24 ] ) ;
}
}
F_38 ( V_9 ) ;
}
int F_52 ( const char * V_10 , const struct V_99 * V_100 , int type , struct V_126 * V_127 )
{
( void ) V_127 ;
switch ( type ) {
case V_128 :
if ( F_53 ( V_100 -> V_129 ) )
F_46 ( V_10 , V_100 ) ;
break;
case V_130 :
fprintf ( V_5 , L_72 , V_10 ) ;
break;
}
return 0 ;
}
static void F_54 ( void )
{
struct V_99 V_100 ;
V_17 = F_3 ( V_18 , V_84 ) ;
V_19 = F_3 ( L_73 , V_84 ) ;
F_55 ( V_131 , & V_132 , NULL ) ;
if ( V_99 ( V_34 , & V_100 ) )
F_2 ( L_74 , V_34 ) ;
if ( F_53 ( V_100 . V_129 ) ) {
F_46 ( V_34 , & V_100 ) ;
} else if ( F_56 ( V_100 . V_129 ) ) {
if ( F_57 ( V_34 , F_52 , 64 , V_133 | V_134 ) < 0 )
F_2 ( L_75 , V_34 ) ;
} else
F_2 ( L_76 , V_34 ) ;
F_38 ( V_17 ) ;
F_38 ( V_19 ) ;
signal ( V_131 , V_135 ) ;
}
static void F_58 ( const char * V_10 )
{
V_34 = V_10 ;
}
static void F_59 ( const char * V_136 )
{
unsigned long V_29 ;
unsigned long V_30 ;
char * V_137 ;
V_137 = strchr ( V_136 , ',' ) ;
if ( ! V_137 )
V_137 = strchr ( V_136 , '+' ) ;
if ( V_137 == V_136 ) {
V_29 = 0 ;
V_30 = F_41 ( V_137 + 1 ) ;
} else if ( V_137 ) {
V_29 = F_41 ( V_136 ) ;
if ( V_137 [ 1 ] == '\0' )
V_30 = V_15 ;
else {
V_30 = F_41 ( V_137 + 1 ) ;
if ( * V_137 == ',' ) {
if ( V_30 < V_29 )
F_2 ( L_77 ,
V_29 , V_30 ) ;
V_30 -= V_29 ;
}
}
} else {
V_29 = F_41 ( V_136 ) ;
V_30 = 1 ;
}
F_36 ( V_29 , V_30 ) ;
}
static void F_60 ( T_2 V_138 , T_2 V_139 )
{
if ( V_38 >= V_140 )
F_2 ( L_78 ) ;
V_41 [ V_38 ] = V_138 ;
V_39 [ V_38 ] = V_139 ;
V_38 ++ ;
}
static T_2 F_61 ( const char * V_87 , int V_69 )
{
T_3 V_24 ;
if ( ! * V_87 || ! V_69 )
return 0 ;
if ( V_69 <= 8 && ! strncmp ( V_87 , L_79 , V_69 ) )
return V_59 ;
for ( V_24 = 0 ; V_24 < F_12 ( V_26 ) ; V_24 ++ ) {
if ( ! V_26 [ V_24 ] )
continue;
if ( ! strncmp ( V_87 , V_26 [ V_24 ] + 2 , V_69 ) )
return 1ULL << V_24 ;
}
return F_41 ( V_87 ) ;
}
static T_2 F_62 ( const char * V_87 , int V_141 )
{
const char * V_137 = V_87 ;
T_2 V_8 = 0 ;
while ( 1 ) {
if ( * V_137 == ',' || * V_137 == '=' || * V_137 == '\0' ) {
if ( ( * V_87 != '~' ) || ( * V_87 == '~' && V_141 && * ++ V_87 ) )
V_8 |= F_61 ( V_87 , V_137 - V_87 ) ;
if ( * V_137 != ',' )
break;
V_87 = V_137 + 1 ;
}
V_137 ++ ;
}
return V_8 ;
}
static void F_63 ( const char * V_136 )
{
T_2 V_138 ;
T_2 V_139 ;
const char * V_137 ;
V_137 = strchr ( V_136 , '=' ) ;
if ( V_137 == V_136 ) {
V_138 = V_40 ;
V_139 = F_62 ( V_137 + 1 , 0 ) ;
} else if ( V_137 ) {
V_138 = F_62 ( V_136 , 0 ) ;
V_139 = F_62 ( V_137 + 1 , 0 ) ;
} else if ( strchr ( V_136 , '~' ) ) {
V_138 = F_62 ( V_136 , 1 ) ;
V_139 = F_62 ( V_136 , 0 ) ;
} else {
V_138 = F_62 ( V_136 , 0 ) ;
V_139 = V_40 ;
}
F_60 ( V_138 , V_139 ) ;
}
static void F_64 ( const char * V_136 )
{
T_2 V_8 = F_62 ( V_136 , 0 ) ;
printf ( L_80 ,
( unsigned long long ) V_8 ,
F_11 ( V_8 ) ,
F_13 ( V_8 ) ) ;
}
int main ( int V_142 , char * V_143 [] )
{
int V_144 ;
V_2 = F_65 () ;
while ( ( V_144 = F_66 ( V_142 , V_143 ,
L_81 , V_145 , NULL ) ) != - 1 ) {
switch ( V_144 ) {
case 'r' :
V_61 = 1 ;
break;
case 'p' :
F_42 ( V_136 ) ;
break;
case 'f' :
F_58 ( V_136 ) ;
break;
case 'a' :
F_59 ( V_136 ) ;
break;
case 'b' :
F_63 ( V_136 ) ;
break;
case 'd' :
F_64 ( V_136 ) ;
exit ( 0 ) ;
case 'l' :
V_71 = 1 ;
break;
case 'L' :
V_71 = 2 ;
break;
case 'N' :
V_146 = 1 ;
break;
case 'X' :
V_64 = 1 ;
F_23 () ;
break;
case 'x' :
V_67 = 1 ;
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
if ( V_71 && V_33 )
printf ( L_82 ) ;
if ( V_71 && V_34 )
printf ( L_83 ) ;
if ( V_71 == 1 )
printf ( L_84 ) ;
if ( V_71 == 2 )
printf ( L_85 ) ;
if ( V_34 )
F_54 () ;
else
F_37 () ;
if ( V_71 == 1 )
F_15 () ;
if ( V_146 )
return 0 ;
if ( V_71 )
printf ( L_86 ) ;
F_17 () ;
return 0 ;
}
