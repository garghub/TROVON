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
static T_2 F_19 ( T_2 V_8 , T_2 V_40 )
{
if ( V_8 & F_20 ( V_41 ) ) {
if ( V_8 & F_20 ( V_42 ) )
V_8 ^= F_20 ( V_42 ) | F_20 ( V_43 ) ;
if ( V_8 & F_20 ( V_44 ) )
V_8 ^= F_20 ( V_44 ) | F_20 ( V_45 ) ;
if ( V_8 & F_20 ( ERROR ) )
V_8 ^= F_20 ( ERROR ) | F_20 ( V_46 ) ;
}
if ( ( V_8 & ( F_20 ( V_47 ) | F_20 ( V_48 ) ) ) == F_20 ( V_47 ) )
V_8 ^= F_20 ( V_47 ) | F_20 ( V_49 ) ;
if ( V_40 & V_50 )
V_8 |= F_20 ( V_51 ) ;
return V_8 ;
}
static T_2 F_21 ( T_2 V_8 )
{
V_8 &= ~ V_52 ;
if ( ( V_8 & V_53 ) && ! ( V_8 & F_20 ( V_54 ) ) )
V_8 &= ~ V_53 ;
return V_8 ;
}
static T_2 F_22 ( T_2 V_8 , T_2 V_40 )
{
if ( V_55 )
V_8 = F_19 ( V_8 , V_40 ) ;
else
V_8 = F_21 ( V_8 ) ;
return V_8 ;
}
static void F_23 ( void )
{
char V_11 [ V_56 + 1 ] ;
V_57 = F_24 ( NULL ) ;
if ( ! V_57 ) {
perror ( L_13 ) ;
exit ( V_6 ) ;
}
if ( V_58 && ! V_59 ) {
snprintf ( V_11 , V_56 , L_14 ,
V_57 ) ;
V_59 = F_3 ( V_11 , V_60 ) ;
}
if ( V_61 && ! V_62 ) {
snprintf ( V_11 , V_56 , L_15 ,
V_57 ) ;
V_62 = F_3 ( V_11 , V_60 ) ;
}
}
static int F_25 ( unsigned long V_29 )
{
char V_11 [ 100 ] ;
int V_63 ;
V_63 = sprintf ( V_11 , L_16 , V_29 ) ;
V_63 = F_26 ( V_59 , V_11 , V_63 ) ;
if ( V_63 < 0 ) {
perror ( L_17 ) ;
return V_63 ;
}
return 0 ;
}
static int F_27 ( unsigned long V_29 )
{
char V_11 [ 100 ] ;
int V_63 ;
V_63 = sprintf ( V_11 , L_16 , V_29 ) ;
V_63 = F_26 ( V_62 , V_11 , V_63 ) ;
if ( V_63 < 0 ) {
perror ( L_18 ) ;
return V_63 ;
}
return 0 ;
}
static T_3 F_28 ( T_2 V_8 )
{
T_3 V_64 = F_29 ( V_8 ) ;
T_3 V_24 ;
if ( V_8 == 0 )
return 0 ;
for ( V_24 = 1 ; V_24 < F_13 ( V_34 ) ; V_24 ++ , V_64 ++ ) {
if ( ! V_64 || V_64 >= F_13 ( V_34 ) )
V_64 = 1 ;
if ( V_34 [ V_64 ] == 0 ) {
V_34 [ V_64 ] = V_8 ;
return V_64 ;
}
if ( V_34 [ V_64 ] == V_8 )
return V_64 ;
}
F_2 ( L_19 ) ;
exit ( V_6 ) ;
}
static void F_30 ( unsigned long V_28 ,
unsigned long V_29 , T_2 V_8 , T_2 V_40 )
{
V_8 = F_22 ( V_8 , V_40 ) ;
if ( ! F_18 ( V_8 ) )
return;
if ( V_58 )
F_25 ( V_29 ) ;
if ( V_61 )
F_27 ( V_29 ) ;
if ( V_65 == 1 )
F_15 ( V_28 , V_29 , V_8 ) ;
else if ( V_65 == 2 )
F_16 ( V_28 , V_29 , V_8 ) ;
V_33 [ F_28 ( V_8 ) ] ++ ;
V_35 ++ ;
}
static void F_31 ( unsigned long V_28 ,
unsigned long V_12 ,
unsigned long V_13 ,
T_2 V_40 )
{
T_2 V_11 [ V_66 ] ;
unsigned long V_67 ;
unsigned long V_1 ;
unsigned long V_24 ;
while ( V_13 ) {
V_67 = F_32 (unsigned long, count, KPAGEFLAGS_BATCH) ;
V_1 = F_8 ( V_11 , V_12 , V_67 ) ;
if ( V_1 == 0 )
break;
for ( V_24 = 0 ; V_24 < V_1 ; V_24 ++ )
F_30 ( V_28 + V_24 , V_12 + V_24 , V_11 [ V_24 ] , V_40 ) ;
V_12 += V_1 ;
V_13 -= V_1 ;
}
}
static void F_33 ( unsigned long V_12 , unsigned long V_13 )
{
T_2 V_11 [ V_68 ] ;
unsigned long V_67 ;
unsigned long V_1 ;
unsigned long V_21 ;
unsigned long V_24 ;
while ( V_13 ) {
V_67 = F_32 (unsigned long, count, PAGEMAP_BATCH) ;
V_1 = F_9 ( V_11 , V_12 , V_67 ) ;
if ( V_1 == 0 )
break;
for ( V_24 = 0 ; V_24 < V_1 ; V_24 ++ ) {
V_21 = F_10 ( V_11 [ V_24 ] ) ;
if ( V_21 )
F_31 ( V_12 + V_24 , V_21 , 1 , V_11 [ V_24 ] ) ;
}
V_12 += V_1 ;
V_13 -= V_1 ;
}
}
static void F_34 ( unsigned long V_12 , unsigned long V_13 )
{
const unsigned long V_69 = V_12 + V_13 ;
unsigned long V_70 ;
int V_24 = 0 ;
while ( V_12 < V_69 ) {
while ( V_71 [ V_24 ] <= V_12 )
if ( ++ V_24 >= V_72 )
return;
if ( V_73 [ V_24 ] >= V_69 )
return;
V_70 = F_35 (unsigned long, pg_start[i], index) ;
V_12 = F_32 (unsigned long, pg_end[i], end) ;
assert ( V_70 < V_12 ) ;
F_33 ( V_70 , V_12 - V_70 ) ;
}
}
static void F_36 ( unsigned long V_29 , unsigned long V_74 )
{
if ( V_75 >= V_76 )
F_2 ( L_20 ) ;
V_77 [ V_75 ] = V_29 ;
V_78 [ V_75 ] = F_32 (unsigned long, size, ULONG_MAX-offset) ;
V_75 ++ ;
}
static void F_37 ( void )
{
int V_24 ;
V_17 = F_3 ( V_18 , V_79 ) ;
if ( ! V_75 )
F_36 ( 0 , V_15 ) ;
for ( V_24 = 0 ; V_24 < V_75 ; V_24 ++ )
if ( ! V_32 )
F_31 ( 0 , V_77 [ V_24 ] , V_78 [ V_24 ] , 0 ) ;
else
F_34 ( V_77 [ V_24 ] , V_78 [ V_24 ] ) ;
F_38 ( V_17 ) ;
}
static const char * F_39 ( T_2 V_80 )
{
if ( V_80 & V_52 )
return L_21 ;
if ( V_80 & V_81 )
return L_22 ;
return L_23 ;
}
static void F_40 ( void )
{
T_3 V_24 , V_25 ;
printf (
L_24
L_25
L_26
L_27
L_28
L_29
#if 0
" -f|--file filename Walk file address space\n"
#endif
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
) ;
for ( V_24 = 0 , V_25 = 0 ; V_24 < F_13 ( V_26 ) ; V_24 ++ ) {
if ( ! V_26 [ V_24 ] )
continue;
printf ( L_52 , V_26 [ V_24 ] + 2 ,
F_39 ( 1ULL << V_24 ) ) ;
if ( ++ V_25 > 3 ) {
V_25 = 0 ;
putchar ( '\n' ) ;
}
}
printf ( L_53
L_54 ) ;
}
static unsigned long long F_41 ( const char * V_82 )
{
unsigned long long V_27 ;
V_27 = strtoll ( V_82 , NULL , 0 ) ;
if ( V_27 == 0 && V_82 [ 0 ] != '0' )
F_2 ( L_55 , V_82 ) ;
return V_27 ;
}
static void F_42 ( const char * V_82 )
{
T_4 * V_83 ;
char V_11 [ 5000 ] ;
V_32 = F_41 ( V_82 ) ;
sprintf ( V_11 , L_56 , V_32 ) ;
V_19 = F_3 ( V_11 , V_79 ) ;
sprintf ( V_11 , L_57 , V_32 ) ;
V_83 = fopen ( V_11 , L_58 ) ;
if ( ! V_83 ) {
perror ( V_11 ) ;
exit ( V_6 ) ;
}
while ( fgets ( V_11 , sizeof( V_11 ) , V_83 ) != NULL ) {
unsigned long V_84 ;
unsigned long V_85 ;
unsigned long long V_86 ;
int V_87 , V_88 ;
char V_89 , V_90 , V_3 , V_91 ;
unsigned long V_92 ;
int V_27 ;
V_27 = sscanf ( V_11 , L_59 ,
& V_84 ,
& V_85 ,
& V_89 , & V_90 , & V_3 , & V_91 ,
& V_86 ,
& V_87 , & V_88 ,
& V_92 ) ;
if ( V_27 < 10 ) {
fprintf ( V_5 , L_60 , V_11 ) ;
continue;
}
V_73 [ V_72 ] = V_84 / V_2 ;
V_71 [ V_72 ] = V_85 / V_2 ;
if ( ++ V_72 >= V_93 ) {
fprintf ( V_5 , L_61 ) ;
break;
}
}
fclose ( V_83 ) ;
}
static void F_43 ( const char * V_10 )
{
}
static void F_44 ( const char * V_94 )
{
unsigned long V_29 ;
unsigned long V_74 ;
char * V_95 ;
V_95 = strchr ( V_94 , ',' ) ;
if ( ! V_95 )
V_95 = strchr ( V_94 , '+' ) ;
if ( V_95 == V_94 ) {
V_29 = 0 ;
V_74 = F_41 ( V_95 + 1 ) ;
} else if ( V_95 ) {
V_29 = F_41 ( V_94 ) ;
if ( V_95 [ 1 ] == '\0' )
V_74 = V_15 ;
else {
V_74 = F_41 ( V_95 + 1 ) ;
if ( * V_95 == ',' ) {
if ( V_74 < V_29 )
F_2 ( L_62 ,
V_29 , V_74 ) ;
V_74 -= V_29 ;
}
}
} else {
V_29 = F_41 ( V_94 ) ;
V_74 = 1 ;
}
F_36 ( V_29 , V_74 ) ;
}
static void F_45 ( T_2 V_96 , T_2 V_97 )
{
if ( V_36 >= V_98 )
F_2 ( L_63 ) ;
V_39 [ V_36 ] = V_96 ;
V_37 [ V_36 ] = V_97 ;
V_36 ++ ;
}
static T_2 F_46 ( const char * V_82 , int V_63 )
{
T_3 V_24 ;
if ( ! * V_82 || ! V_63 )
return 0 ;
if ( V_63 <= 8 && ! strncmp ( V_82 , L_64 , V_63 ) )
return V_53 ;
for ( V_24 = 0 ; V_24 < F_13 ( V_26 ) ; V_24 ++ ) {
if ( ! V_26 [ V_24 ] )
continue;
if ( ! strncmp ( V_82 , V_26 [ V_24 ] + 2 , V_63 ) )
return 1ULL << V_24 ;
}
return F_41 ( V_82 ) ;
}
static T_2 F_47 ( const char * V_82 , int V_99 )
{
const char * V_95 = V_82 ;
T_2 V_8 = 0 ;
while ( 1 ) {
if ( * V_95 == ',' || * V_95 == '=' || * V_95 == '\0' ) {
if ( ( * V_82 != '~' ) || ( * V_82 == '~' && V_99 && * ++ V_82 ) )
V_8 |= F_46 ( V_82 , V_95 - V_82 ) ;
if ( * V_95 != ',' )
break;
V_82 = V_95 + 1 ;
}
V_95 ++ ;
}
return V_8 ;
}
static void F_48 ( const char * V_94 )
{
T_2 V_96 ;
T_2 V_97 ;
const char * V_95 ;
V_95 = strchr ( V_94 , '=' ) ;
if ( V_95 == V_94 ) {
V_96 = V_38 ;
V_97 = F_47 ( V_95 + 1 , 0 ) ;
} else if ( V_95 ) {
V_96 = F_47 ( V_94 , 0 ) ;
V_97 = F_47 ( V_95 + 1 , 0 ) ;
} else if ( strchr ( V_94 , '~' ) ) {
V_96 = F_47 ( V_94 , 1 ) ;
V_97 = F_47 ( V_94 , 0 ) ;
} else {
V_96 = F_47 ( V_94 , 0 ) ;
V_97 = V_38 ;
}
F_45 ( V_96 , V_97 ) ;
}
static void F_49 ( const char * V_94 )
{
T_2 V_8 = F_47 ( V_94 , 0 ) ;
printf ( L_65 ,
( unsigned long long ) V_8 ,
F_12 ( V_8 ) ,
F_14 ( V_8 ) ) ;
}
int main ( int V_100 , char * V_101 [] )
{
int V_102 ;
V_2 = F_50 () ;
while ( ( V_102 = F_51 ( V_100 , V_101 ,
L_66 , V_103 , NULL ) ) != - 1 ) {
switch ( V_102 ) {
case 'r' :
V_55 = 1 ;
break;
case 'p' :
F_42 ( V_94 ) ;
break;
case 'f' :
F_43 ( V_94 ) ;
break;
case 'a' :
F_44 ( V_94 ) ;
break;
case 'b' :
F_48 ( V_94 ) ;
break;
case 'd' :
F_49 ( V_94 ) ;
exit ( 0 ) ;
case 'l' :
V_65 = 1 ;
break;
case 'L' :
V_65 = 2 ;
break;
case 'N' :
V_104 = 1 ;
break;
case 'X' :
V_58 = 1 ;
F_23 () ;
break;
case 'x' :
V_61 = 1 ;
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
if ( V_65 && V_32 )
printf ( L_67 ) ;
if ( V_65 == 1 )
printf ( L_68 ) ;
if ( V_65 == 2 )
printf ( L_69 ) ;
F_37 () ;
if ( V_65 == 1 )
F_15 ( 0 , 0 , 0 ) ;
if ( V_104 )
return 0 ;
if ( V_65 )
printf ( L_70 ) ;
F_17 () ;
return 0 ;
}
