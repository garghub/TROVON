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
if ( F_6 ( V_9 , V_12 * 8 , V_16 ) < 0 ) {
perror ( V_10 ) ;
exit ( V_6 ) ;
}
V_14 = F_7 ( V_9 , V_11 , V_13 * 8 ) ;
if ( V_14 < 0 ) {
perror ( V_10 ) ;
exit ( V_6 ) ;
}
if ( V_14 % 8 )
F_2 ( L_2 , V_14 ) ;
return V_14 / 8 ;
}
static unsigned long F_8 ( T_2 * V_11 ,
unsigned long V_12 ,
unsigned long V_1 )
{
return F_5 ( V_17 , V_18 , V_11 , V_12 , V_1 ) ;
}
static unsigned long F_9 ( T_2 * V_11 ,
unsigned long V_12 ,
unsigned long V_1 )
{
return F_5 ( V_19 , L_3 , V_11 , V_12 , V_1 ) ;
}
static unsigned long F_10 ( T_2 V_20 )
{
unsigned long V_21 ;
if ( V_20 & V_22 )
V_21 = F_11 ( V_20 ) ;
else
V_21 = 0 ;
return V_21 ;
}
static char * F_12 ( T_2 V_8 )
{
static char V_11 [ 65 ] ;
int V_23 ;
T_3 V_24 , V_25 ;
for ( V_24 = 0 , V_25 = 0 ; V_24 < F_13 ( V_26 ) ; V_24 ++ ) {
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
static char * F_14 ( T_2 V_8 )
{
static char V_11 [ 1024 ] ;
T_3 V_24 , V_27 ;
for ( V_24 = 0 , V_27 = 0 ; V_24 < F_13 ( V_26 ) ; V_24 ++ ) {
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
static void F_15 ( unsigned long V_28 ,
unsigned long V_29 , T_2 V_8 )
{
static T_2 V_30 ;
static unsigned long V_31 ;
static unsigned long V_12 ;
static unsigned long V_13 ;
if ( V_8 == V_30 && V_29 == V_12 + V_13 &&
( ! V_32 || V_28 == V_31 + V_13 ) ) {
V_13 ++ ;
return;
}
if ( V_13 ) {
if ( V_32 )
printf ( L_6 , V_31 ) ;
printf ( L_7 ,
V_12 , V_13 , F_12 ( V_30 ) ) ;
}
V_30 = V_8 ;
V_12 = V_29 ;
V_31 = V_28 ;
V_13 = 1 ;
}
static void F_16 ( unsigned long V_28 ,
unsigned long V_29 , T_2 V_8 )
{
if ( V_32 )
printf ( L_6 , V_28 ) ;
printf ( L_8 , V_29 , F_12 ( V_8 ) ) ;
}
static void F_17 ( void )
{
T_3 V_24 ;
printf ( L_9
L_10 ) ;
for ( V_24 = 0 ; V_24 < F_13 ( V_33 ) ; V_24 ++ ) {
if ( V_33 [ V_24 ] )
printf ( L_11 ,
( unsigned long long ) V_34 [ V_24 ] ,
V_33 [ V_24 ] ,
F_1 ( V_33 [ V_24 ] ) ,
F_12 ( V_34 [ V_24 ] ) ,
F_14 ( V_34 [ V_24 ] ) ) ;
}
printf ( L_12 ,
V_35 , F_1 ( V_35 ) ) ;
}
static int F_18 ( T_2 V_8 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_36 ; V_24 ++ ) {
if ( V_37 [ V_24 ] == V_38 ) {
if ( ( V_8 & V_39 [ V_24 ] ) == 0 )
return 0 ;
} else {
if ( ( V_8 & V_39 [ V_24 ] ) != V_37 [ V_24 ] )
return 0 ;
}
}
return 1 ;
}
static T_2 F_19 ( T_2 V_8 )
{
if ( V_8 & F_20 ( V_40 ) ) {
if ( V_8 & F_20 ( V_41 ) )
V_8 ^= F_20 ( V_41 ) | F_20 ( V_42 ) ;
if ( V_8 & F_20 ( V_43 ) )
V_8 ^= F_20 ( V_43 ) | F_20 ( V_44 ) ;
if ( V_8 & F_20 ( ERROR ) )
V_8 ^= F_20 ( ERROR ) | F_20 ( V_45 ) ;
}
if ( ( V_8 & ( F_20 ( V_46 ) | F_20 ( V_47 ) ) ) == F_20 ( V_46 ) )
V_8 ^= F_20 ( V_46 ) | F_20 ( V_48 ) ;
return V_8 ;
}
static T_2 F_21 ( T_2 V_8 )
{
V_8 &= ~ V_49 ;
if ( ( V_8 & V_50 ) && ! ( V_8 & F_20 ( V_51 ) ) )
V_8 &= ~ V_50 ;
return V_8 ;
}
static T_2 F_22 ( T_2 V_8 )
{
V_8 = F_19 ( V_8 ) ;
if ( ! V_52 )
V_8 = F_21 ( V_8 ) ;
return V_8 ;
}
static int F_23 ( const char * V_53 )
{
struct V_54 V_55 ;
if ( V_54 ( V_53 , & V_55 ) < 0 )
return - V_56 ;
else if ( V_55 . V_57 != ( long ) V_58 )
return - V_56 ;
return 0 ;
}
static const char * F_24 ( void )
{
const char * const * V_59 ;
char type [ 100 ] ;
T_4 * V_60 ;
V_59 = V_61 ;
while ( * V_59 ) {
if ( F_23 ( * V_59 ) == 0 ) {
strcpy ( V_62 , * V_59 ) ;
return V_62 ;
}
V_59 ++ ;
}
V_60 = fopen ( L_13 , L_14 ) ;
if ( V_60 == NULL )
perror ( L_15 ) ;
while ( fscanf ( V_60 , L_16
F_25 ( V_63 )
L_17 ,
V_62 , type ) == 2 ) {
if ( strcmp ( type , L_18 ) == 0 )
break;
}
fclose ( V_60 ) ;
if ( strcmp ( type , L_18 ) != 0 )
return NULL ;
return V_62 ;
}
static void F_26 ( void )
{
const char * const * V_59 ;
if ( F_24 () )
return;
V_59 = V_61 ;
while ( * V_59 ) {
if ( F_27 ( NULL , * V_59 , L_18 , 0 , NULL ) == 0 ) {
strcpy ( V_62 , * V_59 ) ;
break;
}
V_59 ++ ;
}
if ( * V_59 == NULL ) {
perror ( L_19 ) ;
exit ( V_6 ) ;
}
}
static void F_28 ( void )
{
char V_11 [ V_63 + 1 ] ;
F_26 () ;
if ( V_64 && ! V_65 ) {
snprintf ( V_11 , V_63 , L_20 ,
V_62 ) ;
V_65 = F_3 ( V_11 , V_66 ) ;
}
if ( V_67 && ! V_68 ) {
snprintf ( V_11 , V_63 , L_21 ,
V_62 ) ;
V_68 = F_3 ( V_11 , V_66 ) ;
}
}
static int F_29 ( unsigned long V_29 )
{
char V_11 [ 100 ] ;
int V_69 ;
V_69 = sprintf ( V_11 , L_22 , V_29 ) ;
V_69 = F_30 ( V_65 , V_11 , V_69 ) ;
if ( V_69 < 0 ) {
perror ( L_23 ) ;
return V_69 ;
}
return 0 ;
}
static int F_31 ( unsigned long V_29 )
{
char V_11 [ 100 ] ;
int V_69 ;
V_69 = sprintf ( V_11 , L_22 , V_29 ) ;
V_69 = F_30 ( V_68 , V_11 , V_69 ) ;
if ( V_69 < 0 ) {
perror ( L_24 ) ;
return V_69 ;
}
return 0 ;
}
static T_3 F_32 ( T_2 V_8 )
{
T_3 V_70 = F_33 ( V_8 ) ;
T_3 V_24 ;
if ( V_8 == 0 )
return 0 ;
for ( V_24 = 1 ; V_24 < F_13 ( V_34 ) ; V_24 ++ , V_70 ++ ) {
if ( ! V_70 || V_70 >= F_13 ( V_34 ) )
V_70 = 1 ;
if ( V_34 [ V_70 ] == 0 ) {
V_34 [ V_70 ] = V_8 ;
return V_70 ;
}
if ( V_34 [ V_70 ] == V_8 )
return V_70 ;
}
F_2 ( L_25 ) ;
exit ( V_6 ) ;
}
static void F_34 ( unsigned long V_28 ,
unsigned long V_29 , T_2 V_8 )
{
V_8 = F_22 ( V_8 ) ;
if ( ! F_18 ( V_8 ) )
return;
if ( V_64 )
F_29 ( V_29 ) ;
if ( V_67 )
F_31 ( V_29 ) ;
if ( V_71 == 1 )
F_15 ( V_28 , V_29 , V_8 ) ;
else if ( V_71 == 2 )
F_16 ( V_28 , V_29 , V_8 ) ;
V_33 [ F_32 ( V_8 ) ] ++ ;
V_35 ++ ;
}
static void F_35 ( unsigned long V_28 ,
unsigned long V_12 ,
unsigned long V_13 )
{
T_2 V_11 [ V_72 ] ;
unsigned long V_73 ;
unsigned long V_1 ;
unsigned long V_24 ;
while ( V_13 ) {
V_73 = F_36 (unsigned long, count, KPAGEFLAGS_BATCH) ;
V_1 = F_8 ( V_11 , V_12 , V_73 ) ;
if ( V_1 == 0 )
break;
for ( V_24 = 0 ; V_24 < V_1 ; V_24 ++ )
F_34 ( V_28 + V_24 , V_12 + V_24 , V_11 [ V_24 ] ) ;
V_12 += V_1 ;
V_13 -= V_1 ;
}
}
static void F_37 ( unsigned long V_12 , unsigned long V_13 )
{
T_2 V_11 [ V_74 ] ;
unsigned long V_73 ;
unsigned long V_1 ;
unsigned long V_21 ;
unsigned long V_24 ;
while ( V_13 ) {
V_73 = F_36 (unsigned long, count, PAGEMAP_BATCH) ;
V_1 = F_9 ( V_11 , V_12 , V_73 ) ;
if ( V_1 == 0 )
break;
for ( V_24 = 0 ; V_24 < V_1 ; V_24 ++ ) {
V_21 = F_10 ( V_11 [ V_24 ] ) ;
if ( V_21 )
F_35 ( V_12 + V_24 , V_21 , 1 ) ;
}
V_12 += V_1 ;
V_13 -= V_1 ;
}
}
static void F_38 ( unsigned long V_12 , unsigned long V_13 )
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
V_76 = F_39 (unsigned long, pg_start[i], index) ;
V_12 = F_36 (unsigned long, pg_end[i], end) ;
assert ( V_76 < V_12 ) ;
F_37 ( V_76 , V_12 - V_76 ) ;
}
}
static void F_40 ( unsigned long V_29 , unsigned long V_80 )
{
if ( V_81 >= V_82 )
F_2 ( L_26 ) ;
V_83 [ V_81 ] = V_29 ;
V_84 [ V_81 ] = F_36 (unsigned long, size, ULONG_MAX-offset) ;
V_81 ++ ;
}
static void F_41 ( void )
{
int V_24 ;
V_17 = F_3 ( V_18 , V_85 ) ;
if ( ! V_81 )
F_40 ( 0 , V_15 ) ;
for ( V_24 = 0 ; V_24 < V_81 ; V_24 ++ )
if ( ! V_32 )
F_35 ( 0 , V_83 [ V_24 ] , V_84 [ V_24 ] ) ;
else
F_38 ( V_83 [ V_24 ] , V_84 [ V_24 ] ) ;
F_42 ( V_17 ) ;
}
static const char * F_43 ( T_2 V_86 )
{
if ( V_86 & V_49 )
return L_27 ;
if ( V_86 & V_87 )
return L_28 ;
return L_29 ;
}
static void F_44 ( void )
{
T_3 V_24 , V_25 ;
printf (
L_30
L_31
L_32
L_33
L_34
L_35
#if 0
" -f|--file filename Walk file address space\n"
#endif
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
for ( V_24 = 0 , V_25 = 0 ; V_24 < F_13 ( V_26 ) ; V_24 ++ ) {
if ( ! V_26 [ V_24 ] )
continue;
printf ( L_58 , V_26 [ V_24 ] + 2 ,
F_43 ( 1ULL << V_24 ) ) ;
if ( ++ V_25 > 3 ) {
V_25 = 0 ;
putchar ( '\n' ) ;
}
}
printf ( L_59
L_60 ) ;
}
static unsigned long long F_45 ( const char * V_88 )
{
unsigned long long V_27 ;
V_27 = strtoll ( V_88 , NULL , 0 ) ;
if ( V_27 == 0 && V_88 [ 0 ] != '0' )
F_2 ( L_61 , V_88 ) ;
return V_27 ;
}
static void F_46 ( const char * V_88 )
{
T_4 * V_89 ;
char V_11 [ 5000 ] ;
V_32 = F_45 ( V_88 ) ;
sprintf ( V_11 , L_62 , V_32 ) ;
V_19 = F_3 ( V_11 , V_85 ) ;
sprintf ( V_11 , L_63 , V_32 ) ;
V_89 = fopen ( V_11 , L_14 ) ;
if ( ! V_89 ) {
perror ( V_11 ) ;
exit ( V_6 ) ;
}
while ( fgets ( V_11 , sizeof( V_11 ) , V_89 ) != NULL ) {
unsigned long V_90 ;
unsigned long V_91 ;
unsigned long long V_92 ;
int V_93 , V_94 ;
char V_95 , V_96 , V_3 , V_97 ;
unsigned long V_98 ;
int V_27 ;
V_27 = sscanf ( V_11 , L_64 ,
& V_90 ,
& V_91 ,
& V_95 , & V_96 , & V_3 , & V_97 ,
& V_92 ,
& V_93 , & V_94 ,
& V_98 ) ;
if ( V_27 < 10 ) {
fprintf ( V_5 , L_65 , V_11 ) ;
continue;
}
V_79 [ V_78 ] = V_90 / V_2 ;
V_77 [ V_78 ] = V_91 / V_2 ;
if ( ++ V_78 >= V_99 ) {
fprintf ( V_5 , L_66 ) ;
break;
}
}
fclose ( V_89 ) ;
}
static void F_47 ( const char * V_10 )
{
}
static void F_48 ( const char * V_100 )
{
unsigned long V_29 ;
unsigned long V_80 ;
char * V_101 ;
V_101 = strchr ( V_100 , ',' ) ;
if ( ! V_101 )
V_101 = strchr ( V_100 , '+' ) ;
if ( V_101 == V_100 ) {
V_29 = 0 ;
V_80 = F_45 ( V_101 + 1 ) ;
} else if ( V_101 ) {
V_29 = F_45 ( V_100 ) ;
if ( V_101 [ 1 ] == '\0' )
V_80 = V_15 ;
else {
V_80 = F_45 ( V_101 + 1 ) ;
if ( * V_101 == ',' ) {
if ( V_80 < V_29 )
F_2 ( L_67 ,
V_29 , V_80 ) ;
V_80 -= V_29 ;
}
}
} else {
V_29 = F_45 ( V_100 ) ;
V_80 = 1 ;
}
F_40 ( V_29 , V_80 ) ;
}
static void F_49 ( T_2 V_102 , T_2 V_103 )
{
if ( V_36 >= V_104 )
F_2 ( L_68 ) ;
V_39 [ V_36 ] = V_102 ;
V_37 [ V_36 ] = V_103 ;
V_36 ++ ;
}
static T_2 F_50 ( const char * V_88 , int V_69 )
{
T_3 V_24 ;
if ( ! * V_88 || ! V_69 )
return 0 ;
if ( V_69 <= 8 && ! strncmp ( V_88 , L_69 , V_69 ) )
return V_50 ;
for ( V_24 = 0 ; V_24 < F_13 ( V_26 ) ; V_24 ++ ) {
if ( ! V_26 [ V_24 ] )
continue;
if ( ! strncmp ( V_88 , V_26 [ V_24 ] + 2 , V_69 ) )
return 1ULL << V_24 ;
}
return F_45 ( V_88 ) ;
}
static T_2 F_51 ( const char * V_88 , int V_105 )
{
const char * V_101 = V_88 ;
T_2 V_8 = 0 ;
while ( 1 ) {
if ( * V_101 == ',' || * V_101 == '=' || * V_101 == '\0' ) {
if ( ( * V_88 != '~' ) || ( * V_88 == '~' && V_105 && * ++ V_88 ) )
V_8 |= F_50 ( V_88 , V_101 - V_88 ) ;
if ( * V_101 != ',' )
break;
V_88 = V_101 + 1 ;
}
V_101 ++ ;
}
return V_8 ;
}
static void F_52 ( const char * V_100 )
{
T_2 V_102 ;
T_2 V_103 ;
const char * V_101 ;
V_101 = strchr ( V_100 , '=' ) ;
if ( V_101 == V_100 ) {
V_102 = V_38 ;
V_103 = F_51 ( V_101 + 1 , 0 ) ;
} else if ( V_101 ) {
V_102 = F_51 ( V_100 , 0 ) ;
V_103 = F_51 ( V_101 + 1 , 0 ) ;
} else if ( strchr ( V_100 , '~' ) ) {
V_102 = F_51 ( V_100 , 1 ) ;
V_103 = F_51 ( V_100 , 0 ) ;
} else {
V_102 = F_51 ( V_100 , 0 ) ;
V_103 = V_38 ;
}
F_49 ( V_102 , V_103 ) ;
}
static void F_53 ( const char * V_100 )
{
T_2 V_8 = F_51 ( V_100 , 0 ) ;
printf ( L_70 ,
( unsigned long long ) V_8 ,
F_12 ( V_8 ) ,
F_14 ( V_8 ) ) ;
}
int main ( int V_106 , char * V_107 [] )
{
int V_108 ;
V_2 = F_54 () ;
while ( ( V_108 = F_55 ( V_106 , V_107 ,
L_71 , V_109 , NULL ) ) != - 1 ) {
switch ( V_108 ) {
case 'r' :
V_52 = 1 ;
break;
case 'p' :
F_46 ( V_100 ) ;
break;
case 'f' :
F_47 ( V_100 ) ;
break;
case 'a' :
F_48 ( V_100 ) ;
break;
case 'b' :
F_52 ( V_100 ) ;
break;
case 'd' :
F_53 ( V_100 ) ;
exit ( 0 ) ;
case 'l' :
V_71 = 1 ;
break;
case 'L' :
V_71 = 2 ;
break;
case 'N' :
V_110 = 1 ;
break;
case 'X' :
V_64 = 1 ;
F_28 () ;
break;
case 'x' :
V_67 = 1 ;
F_28 () ;
break;
case 'h' :
F_44 () ;
exit ( 0 ) ;
default:
F_44 () ;
exit ( 1 ) ;
}
}
if ( V_71 && V_32 )
printf ( L_72 ) ;
if ( V_71 == 1 )
printf ( L_73 ) ;
if ( V_71 == 2 )
printf ( L_74 ) ;
F_41 () ;
if ( V_71 == 1 )
F_15 ( 0 , 0 , 0 ) ;
if ( V_110 )
return 0 ;
if ( V_71 )
printf ( L_75 ) ;
F_17 () ;
return 0 ;
}
