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
if ( V_19 < 0 )
return V_1 ;
return F_5 ( V_19 , V_18 , V_11 , V_12 , V_1 ) ;
}
static unsigned long F_9 ( T_2 * V_11 ,
unsigned long V_12 ,
unsigned long V_1 )
{
return F_5 ( V_20 , L_3 , V_11 , V_12 , V_1 ) ;
}
static unsigned long F_10 ( T_2 V_21 )
{
unsigned long V_22 ;
if ( V_21 & V_23 )
V_22 = F_11 ( V_21 ) ;
else
V_22 = 0 ;
return V_22 ;
}
static unsigned long F_12 ( T_2 V_21 )
{
return V_21 & V_24 ? F_13 ( V_21 ) : 0 ;
}
static char * F_14 ( T_2 V_8 )
{
static char V_11 [ 65 ] ;
int V_25 ;
T_3 V_26 , V_27 ;
for ( V_26 = 0 , V_27 = 0 ; V_26 < F_15 ( V_28 ) ; V_26 ++ ) {
V_25 = ( V_8 >> V_26 ) & 1 ;
if ( ! V_28 [ V_26 ] ) {
if ( V_25 )
F_2 ( L_4 , V_26 ) ;
continue;
}
V_11 [ V_27 ++ ] = V_25 ? V_28 [ V_26 ] [ 0 ] : '_' ;
}
return V_11 ;
}
static char * F_16 ( T_2 V_8 )
{
static char V_11 [ 1024 ] ;
T_3 V_26 , V_29 ;
for ( V_26 = 0 , V_29 = 0 ; V_26 < F_15 ( V_28 ) ; V_26 ++ ) {
if ( ! V_28 [ V_26 ] )
continue;
if ( ( V_8 >> V_26 ) & 1 )
V_29 += snprintf ( V_11 + V_29 , sizeof( V_11 ) - V_29 , L_5 ,
V_28 [ V_26 ] + 2 ) ;
}
if ( V_29 )
V_29 -- ;
V_11 [ V_29 ] = '\0' ;
return V_11 ;
}
static void F_17 ( unsigned long V_30 , unsigned long V_31 ,
unsigned long V_32 , T_2 V_8 , T_2 V_33 )
{
static T_2 V_34 ;
static T_2 V_35 ;
static unsigned long V_36 ;
static unsigned long V_12 ;
static unsigned long V_13 ;
if ( V_8 == V_34 && V_33 == V_35 && V_31 == V_12 + V_13 &&
V_32 && V_30 == V_36 + V_13 ) {
V_13 += V_32 ;
return;
}
if ( V_13 ) {
if ( V_37 )
printf ( L_6 , V_36 ) ;
if ( V_38 )
printf ( L_7 , V_36 ) ;
if ( V_39 )
printf ( L_8 , ( unsigned long long ) V_35 ) ;
printf ( L_9 ,
V_12 , V_13 , F_14 ( V_34 ) ) ;
}
V_34 = V_8 ;
V_35 = V_33 ;
V_12 = V_31 ;
V_36 = V_30 ;
V_13 = V_32 ;
}
static void F_18 ( void )
{
F_17 ( 0 , 0 , 0 , 0 , 0 ) ;
}
static void F_19 ( unsigned long V_30 , unsigned long V_31 ,
T_2 V_8 , T_2 V_33 )
{
if ( V_37 )
printf ( L_6 , V_30 ) ;
if ( V_38 )
printf ( L_7 , V_30 ) ;
if ( V_39 )
printf ( L_8 , ( unsigned long long ) V_33 ) ;
printf ( L_10 , V_31 , F_14 ( V_8 ) ) ;
}
static void F_20 ( void )
{
T_3 V_26 ;
printf ( L_11
L_12 ) ;
for ( V_26 = 0 ; V_26 < F_15 ( V_40 ) ; V_26 ++ ) {
if ( V_40 [ V_26 ] )
printf ( L_13 ,
( unsigned long long ) V_41 [ V_26 ] ,
V_40 [ V_26 ] ,
F_1 ( V_40 [ V_26 ] ) ,
F_14 ( V_41 [ V_26 ] ) ,
F_16 ( V_41 [ V_26 ] ) ) ;
}
printf ( L_14 ,
V_42 , F_1 ( V_42 ) ) ;
}
static int F_21 ( T_2 V_8 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_43 ; V_26 ++ ) {
if ( V_44 [ V_26 ] == V_45 ) {
if ( ( V_8 & V_46 [ V_26 ] ) == 0 )
return 0 ;
} else {
if ( ( V_8 & V_46 [ V_26 ] ) != V_44 [ V_26 ] )
return 0 ;
}
}
return 1 ;
}
static T_2 F_22 ( T_2 V_8 , T_2 V_47 )
{
if ( V_8 & F_23 ( V_48 ) ) {
if ( V_8 & F_23 ( V_49 ) )
V_8 ^= F_23 ( V_49 ) | F_23 ( V_50 ) ;
if ( V_8 & F_23 ( V_51 ) )
V_8 ^= F_23 ( V_51 ) | F_23 ( V_52 ) ;
if ( V_8 & F_23 ( ERROR ) )
V_8 ^= F_23 ( ERROR ) | F_23 ( V_53 ) ;
}
if ( ( V_8 & ( F_23 ( V_54 ) | F_23 ( V_55 ) ) ) == F_23 ( V_54 ) )
V_8 ^= F_23 ( V_54 ) | F_23 ( V_56 ) ;
if ( V_47 & V_57 )
V_8 |= F_23 ( V_58 ) ;
if ( V_47 & V_59 )
V_8 |= F_23 ( V_60 ) ;
if ( V_47 & V_24 )
V_8 |= F_23 ( V_61 ) ;
if ( V_47 & V_62 )
V_8 |= F_23 ( V_63 ) ;
return V_8 ;
}
static T_2 F_24 ( T_2 V_8 )
{
V_8 &= ~ V_64 ;
if ( ( V_8 & V_65 ) && ! ( V_8 & F_23 ( V_66 ) ) )
V_8 &= ~ V_65 ;
return V_8 ;
}
static T_2 F_25 ( T_2 V_8 , T_2 V_47 )
{
if ( V_67 )
V_8 = F_22 ( V_8 , V_47 ) ;
else
V_8 = F_24 ( V_8 ) ;
return V_8 ;
}
static void F_26 ( void )
{
char V_11 [ V_68 + 1 ] ;
V_69 = F_27 () ;
if ( ! V_69 ) {
perror ( L_15 ) ;
exit ( V_6 ) ;
}
if ( V_70 && ! V_71 ) {
snprintf ( V_11 , V_68 , L_16 ,
V_69 ) ;
V_71 = F_3 ( V_11 , V_72 ) ;
}
if ( V_73 && ! V_74 ) {
snprintf ( V_11 , V_68 , L_17 ,
V_69 ) ;
V_74 = F_3 ( V_11 , V_72 ) ;
}
}
static int F_28 ( unsigned long V_31 )
{
char V_11 [ 100 ] ;
int V_75 ;
V_75 = sprintf ( V_11 , L_18 , V_31 ) ;
V_75 = F_29 ( V_71 , V_11 , V_75 ) ;
if ( V_75 < 0 ) {
perror ( L_19 ) ;
return V_75 ;
}
return 0 ;
}
static int F_30 ( unsigned long V_31 )
{
char V_11 [ 100 ] ;
int V_75 ;
V_75 = sprintf ( V_11 , L_18 , V_31 ) ;
V_75 = F_29 ( V_74 , V_11 , V_75 ) ;
if ( V_75 < 0 ) {
perror ( L_20 ) ;
return V_75 ;
}
return 0 ;
}
static T_3 F_31 ( T_2 V_8 )
{
T_3 V_76 = F_32 ( V_8 ) ;
T_3 V_26 ;
if ( V_8 == 0 )
return 0 ;
for ( V_26 = 1 ; V_26 < F_15 ( V_41 ) ; V_26 ++ , V_76 ++ ) {
if ( ! V_76 || V_76 >= F_15 ( V_41 ) )
V_76 = 1 ;
if ( V_41 [ V_76 ] == 0 ) {
V_41 [ V_76 ] = V_8 ;
return V_76 ;
}
if ( V_41 [ V_76 ] == V_8 )
return V_76 ;
}
F_2 ( L_21 ) ;
exit ( V_6 ) ;
}
static void F_33 ( unsigned long V_30 , unsigned long V_31 ,
T_2 V_8 , T_2 V_33 , T_2 V_47 )
{
V_8 = F_25 ( V_8 , V_47 ) ;
if ( ! F_21 ( V_8 ) )
return;
if ( V_77 && V_33 != ( T_2 ) V_77 )
return;
if ( V_70 )
F_28 ( V_31 ) ;
if ( V_73 )
F_30 ( V_31 ) ;
if ( V_78 == 1 )
F_17 ( V_30 , V_31 , 1 , V_8 , V_33 ) ;
else if ( V_78 == 2 )
F_19 ( V_30 , V_31 , V_8 , V_33 ) ;
V_40 [ F_31 ( V_8 ) ] ++ ;
V_42 ++ ;
}
static void F_34 ( unsigned long V_30 ,
unsigned long V_12 ,
unsigned long V_13 ,
T_2 V_47 )
{
T_2 V_11 [ V_79 ] ;
T_2 V_80 [ V_79 ] ;
unsigned long V_81 ;
unsigned long V_1 ;
unsigned long V_26 ;
if ( V_13 == 1 )
V_80 [ 0 ] = 0 ;
else
memset ( V_80 , 0 , sizeof V_80 ) ;
while ( V_13 ) {
V_81 = F_35 (unsigned long, count, KPAGEFLAGS_BATCH) ;
V_1 = F_7 ( V_11 , V_12 , V_81 ) ;
if ( V_1 == 0 )
break;
if ( F_8 ( V_80 , V_12 , V_1 ) != V_1 )
F_2 ( L_22 ) ;
for ( V_26 = 0 ; V_26 < V_1 ; V_26 ++ )
F_33 ( V_30 + V_26 , V_12 + V_26 , V_11 [ V_26 ] , V_80 [ V_26 ] , V_47 ) ;
V_12 += V_1 ;
V_13 -= V_1 ;
}
}
static void F_36 ( unsigned long V_30 , T_2 V_47 )
{
T_2 V_8 = F_25 ( 0 , V_47 ) ;
if ( ! F_21 ( V_8 ) )
return;
if ( V_77 )
return;
if ( V_78 == 1 )
F_17 ( V_30 , F_12 ( V_47 ) , 1 , V_8 , 0 ) ;
else if ( V_78 == 2 )
F_19 ( V_30 , F_12 ( V_47 ) , V_8 , 0 ) ;
V_40 [ F_31 ( V_8 ) ] ++ ;
V_42 ++ ;
}
static void F_37 ( unsigned long V_12 , unsigned long V_13 )
{
T_2 V_11 [ V_82 ] ;
unsigned long V_81 ;
unsigned long V_1 ;
unsigned long V_22 ;
unsigned long V_26 ;
while ( V_13 ) {
V_81 = F_35 (unsigned long, count, PAGEMAP_BATCH) ;
V_1 = F_9 ( V_11 , V_12 , V_81 ) ;
if ( V_1 == 0 )
break;
for ( V_26 = 0 ; V_26 < V_1 ; V_26 ++ ) {
V_22 = F_10 ( V_11 [ V_26 ] ) ;
if ( V_22 )
F_34 ( V_12 + V_26 , V_22 , 1 , V_11 [ V_26 ] ) ;
if ( V_11 [ V_26 ] & V_24 )
F_36 ( V_12 + V_26 , V_11 [ V_26 ] ) ;
}
V_12 += V_1 ;
V_13 -= V_1 ;
}
}
static void F_38 ( unsigned long V_12 , unsigned long V_13 )
{
const unsigned long V_83 = V_12 + V_13 ;
unsigned long V_84 ;
int V_26 = 0 ;
while ( V_12 < V_83 ) {
while ( V_85 [ V_26 ] <= V_12 )
if ( ++ V_26 >= V_86 )
return;
if ( V_87 [ V_26 ] >= V_83 )
return;
V_84 = F_39 (unsigned long, pg_start[i], index) ;
V_12 = F_35 (unsigned long, pg_end[i], end) ;
assert ( V_84 < V_12 ) ;
F_37 ( V_84 , V_12 - V_84 ) ;
}
}
static void F_40 ( unsigned long V_31 , unsigned long V_32 )
{
if ( V_88 >= V_89 )
F_2 ( L_23 ) ;
V_90 [ V_88 ] = V_31 ;
V_91 [ V_88 ] = F_35 (unsigned long, size, ULONG_MAX-offset) ;
V_88 ++ ;
}
static void F_41 ( void )
{
int V_26 ;
V_17 = F_3 ( V_18 , V_92 ) ;
if ( ! V_88 )
F_40 ( 0 , V_15 ) ;
for ( V_26 = 0 ; V_26 < V_88 ; V_26 ++ )
if ( ! V_37 )
F_34 ( V_90 [ V_26 ] , V_90 [ V_26 ] , V_91 [ V_26 ] , 0 ) ;
else
F_38 ( V_90 [ V_26 ] , V_91 [ V_26 ] ) ;
F_42 ( V_17 ) ;
}
static const char * F_43 ( T_2 V_93 )
{
if ( V_93 & V_64 )
return L_24 ;
if ( V_93 & V_94 )
return L_25 ;
return L_26 ;
}
static void F_44 ( void )
{
T_3 V_26 , V_27 ;
printf (
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
L_54
L_55
L_56
L_57
) ;
for ( V_26 = 0 , V_27 = 0 ; V_26 < F_15 ( V_28 ) ; V_26 ++ ) {
if ( ! V_28 [ V_26 ] )
continue;
printf ( L_58 , V_28 [ V_26 ] + 2 ,
F_43 ( 1ULL << V_26 ) ) ;
if ( ++ V_27 > 3 ) {
V_27 = 0 ;
putchar ( '\n' ) ;
}
}
printf ( L_59
L_60 ) ;
}
static unsigned long long F_45 ( const char * V_95 )
{
unsigned long long V_29 ;
V_29 = strtoll ( V_95 , NULL , 0 ) ;
if ( V_29 == 0 && V_95 [ 0 ] != '0' )
F_2 ( L_61 , V_95 ) ;
return V_29 ;
}
static void F_46 ( const char * V_95 )
{
V_60 * V_96 ;
char V_11 [ 5000 ] ;
V_37 = F_45 ( V_95 ) ;
sprintf ( V_11 , L_62 , V_37 ) ;
V_20 = F_3 ( V_11 , V_92 ) ;
sprintf ( V_11 , L_63 , V_37 ) ;
V_96 = fopen ( V_11 , L_64 ) ;
if ( ! V_96 ) {
perror ( V_11 ) ;
exit ( V_6 ) ;
}
while ( fgets ( V_11 , sizeof( V_11 ) , V_96 ) != NULL ) {
unsigned long V_97 ;
unsigned long V_98 ;
unsigned long long V_99 ;
int V_100 , V_101 ;
char V_102 , V_103 , V_3 , V_104 ;
unsigned long V_105 ;
int V_29 ;
V_29 = sscanf ( V_11 , L_65 ,
& V_97 ,
& V_98 ,
& V_102 , & V_103 , & V_3 , & V_104 ,
& V_99 ,
& V_100 , & V_101 ,
& V_105 ) ;
if ( V_29 < 10 ) {
fprintf ( V_5 , L_66 , V_11 ) ;
continue;
}
V_87 [ V_86 ] = V_97 / V_2 ;
V_85 [ V_86 ] = V_98 / V_2 ;
if ( ++ V_86 >= V_106 ) {
fprintf ( V_5 , L_67 ) ;
break;
}
}
fclose ( V_96 ) ;
}
static void F_47 ( const char * V_10 , const struct V_107 * V_108 )
{
unsigned long long V_32 = V_108 -> V_109 ;
char V_110 [ 64 ] , V_111 [ 64 ] ;
long V_112 = time ( NULL ) ;
printf ( L_68 ,
V_10 , ( unsigned ) V_108 -> V_113 ,
V_32 , ( V_32 + V_2 - 1 ) / V_2 ) ;
strftime ( V_110 , sizeof( V_110 ) , L_69 , localtime ( & V_108 -> V_114 ) ) ;
strftime ( V_111 , sizeof( V_111 ) , L_69 , localtime ( & V_108 -> V_115 ) ) ;
printf ( L_70 ,
V_111 , V_112 - V_108 -> V_115 ,
V_110 , V_112 - V_108 -> V_114 ) ;
}
static void F_48 ( int V_116 , T_4 * V_117 , void * V_118 )
{
( void ) V_116 ;
( void ) V_118 ;
V_119 = V_117 ? V_117 -> V_120 : NULL ;
F_49 ( V_121 , 1 ) ;
}
static void F_50 ( const char * V_10 , const struct V_107 * V_108 )
{
T_5 V_122 [ V_82 ] ;
T_2 V_11 [ V_82 ] , V_8 ;
T_2 V_33 = 0 ;
unsigned long V_40 , V_22 , V_26 ;
V_16 V_123 , V_83 = V_108 -> V_109 ;
int V_9 ;
T_6 V_75 ;
void * V_124 ;
int V_125 = 1 ;
V_9 = F_3 ( V_10 , V_92 | V_126 | V_127 ) ;
for ( V_123 = 0 ; V_123 < V_83 ; V_123 += V_75 ) {
V_40 = ( V_83 - V_123 + V_2 - 1 ) / V_2 ;
if ( V_40 > V_82 )
V_40 = V_82 ;
V_75 = V_40 * V_2 ;
V_124 = F_51 ( NULL , V_75 , V_128 , V_129 , V_9 , V_123 ) ;
if ( V_124 == V_130 )
F_2 ( L_71 , V_10 ) ;
if ( F_52 ( V_124 , V_75 , V_122 ) )
F_2 ( L_72 , V_10 ) ;
if ( F_53 ( V_124 , V_75 , V_131 ) )
F_2 ( L_73 , V_10 ) ;
if ( F_54 ( V_121 , 1 ) ) {
V_83 = V_123 + V_119 ? V_119 - V_124 : 0 ;
fprintf ( V_5 , L_74 ,
( long long ) V_83 , V_10 ) ;
goto V_132;
}
for ( V_26 = 0 ; V_26 < V_40 ; V_26 ++ ) {
if ( V_122 [ V_26 ] & 1 )
( void ) * ( volatile int * ) ( V_124 + V_26 * V_2 ) ;
}
V_132:
if ( F_53 ( V_124 , V_75 , V_133 ) )
F_2 ( L_73 , V_10 ) ;
if ( F_9 ( V_11 , ( unsigned long ) V_124 / V_2 ,
V_40 ) != V_40 )
F_2 ( L_75 ) ;
F_55 ( V_124 , V_75 ) ;
for ( V_26 = 0 ; V_26 < V_40 ; V_26 ++ ) {
V_22 = F_10 ( V_11 [ V_26 ] ) ;
if ( ! V_22 )
continue;
if ( ! F_7 ( & V_8 , V_22 , 1 ) )
continue;
if ( ! F_8 ( & V_33 , V_22 , 1 ) )
F_2 ( L_76 ) ;
if ( V_125 && V_78 ) {
V_125 = 0 ;
F_18 () ;
F_47 ( V_10 , V_108 ) ;
}
F_33 ( V_123 / V_2 + V_26 , V_22 ,
V_8 , V_33 , V_11 [ V_26 ] ) ;
}
}
F_42 ( V_9 ) ;
}
int F_56 ( const char * V_10 , const struct V_107 * V_108 , int type , struct V_134 * V_135 )
{
( void ) V_135 ;
switch ( type ) {
case V_136 :
if ( F_57 ( V_108 -> V_137 ) )
F_50 ( V_10 , V_108 ) ;
break;
case V_138 :
fprintf ( V_5 , L_77 , V_10 ) ;
break;
}
return 0 ;
}
static void F_58 ( void )
{
struct V_107 V_108 ;
V_17 = F_3 ( V_18 , V_92 ) ;
V_20 = F_3 ( L_78 , V_92 ) ;
F_59 ( V_139 , & V_140 , NULL ) ;
if ( V_107 ( V_38 , & V_108 ) )
F_2 ( L_79 , V_38 ) ;
if ( F_57 ( V_108 . V_137 ) ) {
F_50 ( V_38 , & V_108 ) ;
} else if ( F_60 ( V_108 . V_137 ) ) {
if ( F_61 ( V_38 , F_56 , 64 , V_141 | V_142 ) < 0 )
F_2 ( L_80 , V_38 ) ;
} else
F_2 ( L_81 , V_38 ) ;
F_42 ( V_17 ) ;
F_42 ( V_20 ) ;
signal ( V_139 , V_143 ) ;
}
static void F_62 ( const char * V_10 )
{
V_38 = V_10 ;
}
static void F_63 ( const char * V_144 )
{
if ( V_144 [ 0 ] == '@' ) {
V_77 = F_45 ( V_144 + 1 ) ;
return;
}
struct V_107 V_108 ;
if ( V_107 ( V_144 , & V_108 ) )
F_2 ( L_82 , V_144 ) ;
if ( ! F_60 ( V_108 . V_137 ) )
F_2 ( L_83 , V_144 ) ;
V_77 = V_108 . V_113 ;
}
static void F_64 ( const char * V_145 )
{
unsigned long V_31 ;
unsigned long V_32 ;
char * V_146 ;
V_146 = strchr ( V_145 , ',' ) ;
if ( ! V_146 )
V_146 = strchr ( V_145 , '+' ) ;
if ( V_146 == V_145 ) {
V_31 = 0 ;
V_32 = F_45 ( V_146 + 1 ) ;
} else if ( V_146 ) {
V_31 = F_45 ( V_145 ) ;
if ( V_146 [ 1 ] == '\0' )
V_32 = V_15 ;
else {
V_32 = F_45 ( V_146 + 1 ) ;
if ( * V_146 == ',' ) {
if ( V_32 < V_31 )
F_2 ( L_84 ,
V_31 , V_32 ) ;
V_32 -= V_31 ;
}
}
} else {
V_31 = F_45 ( V_145 ) ;
V_32 = 1 ;
}
F_40 ( V_31 , V_32 ) ;
}
static void F_65 ( T_2 V_147 , T_2 V_148 )
{
if ( V_43 >= V_149 )
F_2 ( L_85 ) ;
V_46 [ V_43 ] = V_147 ;
V_44 [ V_43 ] = V_148 ;
V_43 ++ ;
}
static T_2 F_66 ( const char * V_95 , int V_75 )
{
T_3 V_26 ;
if ( ! * V_95 || ! V_75 )
return 0 ;
if ( V_75 <= 8 && ! strncmp ( V_95 , L_86 , V_75 ) )
return V_65 ;
for ( V_26 = 0 ; V_26 < F_15 ( V_28 ) ; V_26 ++ ) {
if ( ! V_28 [ V_26 ] )
continue;
if ( ! strncmp ( V_95 , V_28 [ V_26 ] + 2 , V_75 ) )
return 1ULL << V_26 ;
}
return F_45 ( V_95 ) ;
}
static T_2 F_67 ( const char * V_95 , int V_150 )
{
const char * V_146 = V_95 ;
T_2 V_8 = 0 ;
while ( 1 ) {
if ( * V_146 == ',' || * V_146 == '=' || * V_146 == '\0' ) {
if ( ( * V_95 != '~' ) || ( * V_95 == '~' && V_150 && * ++ V_95 ) )
V_8 |= F_66 ( V_95 , V_146 - V_95 ) ;
if ( * V_146 != ',' )
break;
V_95 = V_146 + 1 ;
}
V_146 ++ ;
}
return V_8 ;
}
static void F_68 ( const char * V_145 )
{
T_2 V_147 ;
T_2 V_148 ;
const char * V_146 ;
V_146 = strchr ( V_145 , '=' ) ;
if ( V_146 == V_145 ) {
V_147 = V_45 ;
V_148 = F_67 ( V_146 + 1 , 0 ) ;
} else if ( V_146 ) {
V_147 = F_67 ( V_145 , 0 ) ;
V_148 = F_67 ( V_146 + 1 , 0 ) ;
} else if ( strchr ( V_145 , '~' ) ) {
V_147 = F_67 ( V_145 , 1 ) ;
V_148 = F_67 ( V_145 , 0 ) ;
} else {
V_147 = F_67 ( V_145 , 0 ) ;
V_148 = V_45 ;
}
F_65 ( V_147 , V_148 ) ;
}
static void F_69 ( const char * V_145 )
{
T_2 V_8 = F_67 ( V_145 , 0 ) ;
printf ( L_87 ,
( unsigned long long ) V_8 ,
F_14 ( V_8 ) ,
F_16 ( V_8 ) ) ;
}
int main ( int V_151 , char * V_152 [] )
{
int V_153 ;
V_2 = F_70 () ;
while ( ( V_153 = F_71 ( V_151 , V_152 ,
L_88 , V_154 , NULL ) ) != - 1 ) {
switch ( V_153 ) {
case 'r' :
V_67 = 1 ;
break;
case 'p' :
F_46 ( V_145 ) ;
break;
case 'f' :
F_62 ( V_145 ) ;
break;
case 'a' :
F_64 ( V_145 ) ;
break;
case 'b' :
F_68 ( V_145 ) ;
break;
case 'c' :
F_63 ( V_145 ) ;
break;
case 'C' :
V_39 = 1 ;
break;
case 'd' :
F_69 ( V_145 ) ;
exit ( 0 ) ;
case 'l' :
V_78 = 1 ;
break;
case 'L' :
V_78 = 2 ;
break;
case 'N' :
V_155 = 1 ;
break;
case 'X' :
V_70 = 1 ;
F_26 () ;
break;
case 'x' :
V_73 = 1 ;
F_26 () ;
break;
case 'h' :
F_44 () ;
exit ( 0 ) ;
default:
F_44 () ;
exit ( 1 ) ;
}
}
if ( V_77 || V_39 )
V_19 = F_3 ( V_156 , V_92 ) ;
if ( V_78 && V_37 )
printf ( L_89 ) ;
if ( V_78 && V_38 )
printf ( L_90 ) ;
if ( V_78 && V_39 )
printf ( L_91 ) ;
if ( V_78 == 1 )
printf ( L_92 ) ;
if ( V_78 == 2 )
printf ( L_93 ) ;
if ( V_38 )
F_58 () ;
else
F_41 () ;
if ( V_78 == 1 )
F_18 () ;
if ( V_155 )
return 0 ;
if ( V_78 )
printf ( L_94 ) ;
F_20 () ;
return 0 ;
}
