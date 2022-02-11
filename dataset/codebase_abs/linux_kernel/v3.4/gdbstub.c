static int F_1 ( void )
{
int V_1 = - 1 ;
int V_2 ;
if ( F_2 ( V_3 ) ) {
if ( V_4 < V_3 )
return V_5 [ V_4 ++ ] ;
else
V_3 = 0 ;
}
while ( V_1 < 0 )
for ( V_2 = 0 ; V_6 [ V_2 ] != NULL ; V_2 ++ ) {
V_1 = V_6 [ V_2 ] ( ) ;
if ( V_1 > 0 )
break;
}
return V_1 ;
}
static int F_1 ( void )
{
int V_1 = V_7 -> V_8 () ;
while ( V_1 == V_9 )
V_1 = V_7 -> V_8 () ;
return V_1 ;
}
static void F_3 ( char * V_10 )
{
unsigned char V_11 ;
unsigned char V_12 ;
int V_13 ;
char V_14 ;
do {
while ( ( V_14 = ( F_1 () ) ) != '$' )
;
V_15 = 1 ;
V_11 = 0 ;
V_12 = - 1 ;
V_13 = 0 ;
while ( V_13 < ( V_16 - 1 ) ) {
V_14 = F_1 () ;
if ( V_14 == '#' )
break;
V_11 = V_11 + V_14 ;
V_10 [ V_13 ] = V_14 ;
V_13 = V_13 + 1 ;
}
if ( V_14 == '#' ) {
V_12 = F_4 ( F_1 () ) << 4 ;
V_12 += F_4 ( F_1 () ) ;
if ( V_11 != V_12 )
V_7 -> V_17 ( '-' ) ;
else
V_7 -> V_17 ( '+' ) ;
if ( V_7 -> V_18 )
V_7 -> V_18 () ;
}
V_10 [ V_13 ] = 0 ;
} while ( V_11 != V_12 );
}
static void F_5 ( char * V_10 )
{
unsigned char V_11 ;
int V_13 ;
char V_14 ;
while ( 1 ) {
V_7 -> V_17 ( '$' ) ;
V_11 = 0 ;
V_13 = 0 ;
while ( ( V_14 = V_10 [ V_13 ] ) ) {
V_7 -> V_17 ( V_14 ) ;
V_11 += V_14 ;
V_13 ++ ;
}
V_7 -> V_17 ( '#' ) ;
V_7 -> V_17 ( F_6 ( V_11 ) ) ;
V_7 -> V_17 ( F_7 ( V_11 ) ) ;
if ( V_7 -> V_18 )
V_7 -> V_18 () ;
V_14 = F_1 () ;
if ( V_14 == 3 )
V_14 = F_1 () ;
if ( V_14 == '+' )
return;
if ( V_14 == '$' ) {
V_7 -> V_17 ( '-' ) ;
if ( V_7 -> V_18 )
V_7 -> V_18 () ;
return;
}
}
}
void F_8 ( const char * V_19 , int V_20 )
{
char * V_21 ;
int V_22 ;
int V_2 ;
if ( V_20 == 0 )
V_20 = strlen ( V_19 ) ;
V_23 [ 0 ] = 'O' ;
while ( V_20 > 0 ) {
V_21 = V_23 + 1 ;
if ( ( V_20 << 1 ) > ( V_16 - 2 ) )
V_22 = ( V_16 - 2 ) >> 1 ;
else
V_22 = V_20 ;
for ( V_2 = 0 ; V_2 < V_22 ; V_2 ++ )
V_21 = F_9 ( V_21 , V_19 [ V_2 ] ) ;
* V_21 = '\0' ;
V_19 += V_22 ;
V_20 -= V_22 ;
F_5 ( V_23 ) ;
}
}
char * F_10 ( char * V_24 , char * V_25 , int V_13 )
{
char * V_26 ;
int V_27 ;
V_26 = V_25 + V_13 ;
V_27 = F_11 ( V_26 , V_24 , V_13 ) ;
if ( V_27 )
return NULL ;
while ( V_13 > 0 ) {
V_25 = F_9 ( V_25 , * V_26 ) ;
V_26 ++ ;
V_13 -- ;
}
* V_25 = 0 ;
return V_25 ;
}
int F_12 ( char * V_25 , char * V_24 , int V_13 )
{
char * V_28 ;
char * V_29 ;
V_28 = V_25 + V_13 * 2 ;
V_29 = V_28 - 1 ;
while ( V_29 >= V_25 ) {
V_28 -- ;
* V_28 = F_4 ( * V_29 -- ) ;
* V_28 |= F_4 ( * V_29 -- ) << 4 ;
}
return F_13 ( V_24 , V_28 , V_13 ) ;
}
int F_14 ( char * * V_30 , unsigned long * V_31 )
{
int V_32 ;
int V_33 = 0 ;
int V_34 = 0 ;
* V_31 = 0 ;
if ( * * V_30 == '-' ) {
V_34 = 1 ;
( * V_30 ) ++ ;
}
while ( * * V_30 ) {
V_32 = F_4 ( * * V_30 ) ;
if ( V_32 < 0 )
break;
* V_31 = ( * V_31 << 4 ) | V_32 ;
V_33 ++ ;
( * V_30 ) ++ ;
}
if ( V_34 )
* V_31 = - * V_31 ;
return V_33 ;
}
static int F_15 ( char * V_25 , char * V_24 , int V_13 )
{
int V_35 = 0 ;
char * V_36 = V_25 ;
while ( V_13 -- > 0 ) {
V_36 [ V_35 ] = * V_25 ++ ;
if ( V_36 [ V_35 ] == 0x7d )
V_36 [ V_35 ] = * V_25 ++ ^ 0x20 ;
V_35 ++ ;
}
return F_13 ( V_24 , V_36 , V_35 ) ;
}
void F_16 ( unsigned long * V_37 , struct V_38 * V_39 )
{
int V_2 ;
int V_40 = 0 ;
char * V_30 = ( char * ) V_37 ;
for ( V_2 = 0 ; V_2 < V_41 ; V_2 ++ ) {
F_17 ( V_2 , V_30 + V_40 , V_39 ) ;
V_40 += V_42 [ V_2 ] . V_35 ;
}
}
void F_18 ( unsigned long * V_37 , struct V_38 * V_39 )
{
int V_2 ;
int V_40 = 0 ;
char * V_30 = ( char * ) V_37 ;
for ( V_2 = 0 ; V_2 < V_41 ; V_2 ++ ) {
F_19 ( V_2 , V_30 + V_40 , V_39 ) ;
V_40 += V_42 [ V_2 ] . V_35 ;
}
}
static int F_20 ( int V_43 )
{
char * V_30 = & V_5 [ 1 ] ;
unsigned long V_44 ;
unsigned long V_45 ;
int V_27 ;
if ( F_14 ( & V_30 , & V_44 ) > 0 && * ( V_30 ++ ) == ',' &&
F_14 ( & V_30 , & V_45 ) > 0 && * ( V_30 ++ ) == ':' ) {
if ( V_43 )
V_27 = F_15 ( V_30 , ( char * ) V_44 , V_45 ) ;
else
V_27 = F_12 ( V_30 , ( char * ) V_44 , V_45 ) ;
if ( V_27 )
return V_27 ;
if ( V_46 )
F_21 ( V_44 , V_44 + V_45 ) ;
return 0 ;
}
return - V_47 ;
}
static void F_22 ( char * V_48 , int error )
{
error = - error ;
V_48 [ 0 ] = 'E' ;
V_48 [ 1 ] = V_49 [ ( error / 10 ) ] ;
V_48 [ 2 ] = V_49 [ ( error % 10 ) ] ;
V_48 [ 3 ] = '\0' ;
}
static char * F_23 ( char * V_48 , unsigned char * V_50 )
{
unsigned char * V_51 ;
int V_52 = 1 ;
V_51 = V_50 + ( V_53 / 2 ) ;
while ( V_50 < V_51 ) {
if ( ! V_52 || * V_50 != 0 ) {
V_48 = F_9 ( V_48 , * V_50 ) ;
V_52 = 0 ;
}
V_50 ++ ;
}
if ( V_52 )
V_48 = F_9 ( V_48 , 0 ) ;
return V_48 ;
}
static void F_24 ( unsigned char * V_50 , int V_54 )
{
F_25 ( V_54 , V_50 ) ;
}
static struct V_55 * F_26 ( struct V_38 * V_39 , int V_56 )
{
if ( V_56 == 0 || V_56 == - 1 )
V_56 = - F_27 ( & V_57 ) - 2 ;
if ( V_56 < - 1 && V_56 > - V_58 - 2 ) {
if ( V_59 [ - V_56 - 2 ] . V_60 )
return V_59 [ - V_56 - 2 ] . V_60 ;
else
return F_28 ( - V_56 - 2 ) ;
}
if ( V_56 <= 0 ) {
F_29 ( V_61 L_1 ) ;
F_30 () ;
return NULL ;
}
return F_31 ( V_56 , & V_62 ) ;
}
static inline int F_32 ( int V_63 )
{
if ( V_63 )
return V_63 ;
return - F_33 () - 2 ;
}
static void F_34 ( struct V_64 * V_65 )
{
F_35 () ;
V_66 [ 0 ] = 'S' ;
F_9 ( & V_66 [ 1 ] , V_65 -> V_67 ) ;
}
static void F_36 ( struct V_64 * V_65 )
{
struct V_55 * V_68 ;
void * V_69 ;
int V_2 ;
V_68 = V_70 ;
if ( ! V_68 ) {
V_68 = V_59 [ V_65 -> V_71 ] . V_60 ;
V_69 = V_59 [ V_65 -> V_71 ] . V_72 ;
} else {
V_69 = NULL ;
F_37 (i) {
if ( V_68 == V_59 [ V_2 ] . V_60 )
V_69 = V_59 [ V_2 ] . V_72 ;
}
}
if ( V_69 ) {
F_16 ( V_37 , V_69 ) ;
} else {
F_38 ( V_37 , V_68 ) ;
}
}
static void F_39 ( struct V_64 * V_65 )
{
F_36 ( V_65 ) ;
F_10 ( ( char * ) V_37 , V_66 , V_73 ) ;
}
static void F_40 ( struct V_64 * V_65 )
{
F_12 ( & V_5 [ 1 ] , ( char * ) V_37 , V_73 ) ;
if ( V_70 && V_70 != V_74 ) {
F_22 ( V_66 , - V_47 ) ;
} else {
F_18 ( V_37 , V_65 -> V_75 ) ;
strcpy ( V_66 , L_2 ) ;
}
}
static void F_41 ( struct V_64 * V_65 )
{
char * V_30 = & V_5 [ 1 ] ;
unsigned long V_45 ;
unsigned long V_44 ;
char * V_27 ;
if ( F_14 ( & V_30 , & V_44 ) > 0 && * V_30 ++ == ',' &&
F_14 ( & V_30 , & V_45 ) > 0 ) {
V_27 = F_10 ( ( char * ) V_44 , V_66 , V_45 ) ;
if ( ! V_27 )
F_22 ( V_66 , - V_47 ) ;
} else {
F_22 ( V_66 , - V_47 ) ;
}
}
static void F_42 ( struct V_64 * V_65 )
{
int V_27 = F_20 ( 0 ) ;
if ( V_27 )
F_22 ( V_66 , V_27 ) ;
else
strcpy ( V_66 , L_2 ) ;
}
static char * F_43 ( int V_76 , char * V_77 )
{
int V_2 ;
int V_78 = 0 ;
for ( V_2 = 0 ; V_2 < V_76 ; V_2 ++ )
V_78 += V_42 [ V_2 ] . V_35 ;
return F_10 ( ( char * ) V_37 + V_78 , V_77 ,
V_42 [ V_2 ] . V_35 ) ;
}
static void F_44 ( struct V_64 * V_65 )
{
unsigned long V_76 ;
char * V_30 = & V_5 [ 1 ] ;
F_14 ( & V_30 , & V_76 ) ;
if ( V_76 >= V_41 ) {
F_22 ( V_66 , - V_47 ) ;
return;
}
F_36 ( V_65 ) ;
F_43 ( V_76 , V_66 ) ;
}
static void F_45 ( struct V_64 * V_65 )
{
unsigned long V_76 ;
char * V_30 = & V_5 [ 1 ] ;
int V_2 = 0 ;
F_14 ( & V_30 , & V_76 ) ;
if ( * V_30 ++ != '=' ||
! ( ! V_70 || V_70 == V_74 ) ||
! F_17 ( V_76 , V_37 , V_65 -> V_75 ) ) {
F_22 ( V_66 , - V_47 ) ;
return;
}
memset ( V_37 , 0 , sizeof( V_37 ) ) ;
while ( V_2 < sizeof( V_37 ) * 2 )
if ( F_4 ( V_30 [ V_2 ] ) >= 0 )
V_2 ++ ;
else
break;
V_2 = V_2 / 2 ;
F_12 ( V_30 , ( char * ) V_37 , V_2 ) ;
F_19 ( V_76 , V_37 , V_65 -> V_75 ) ;
strcpy ( V_66 , L_2 ) ;
}
static void F_46 ( struct V_64 * V_65 )
{
int V_27 = F_20 ( 1 ) ;
if ( V_27 )
F_22 ( V_66 , V_27 ) ;
else
strcpy ( V_66 , L_2 ) ;
}
static void F_47 ( struct V_64 * V_65 )
{
int error ;
if ( V_5 [ 0 ] == 'D' ) {
error = F_35 () ;
if ( error < 0 ) {
F_22 ( V_66 , error ) ;
} else {
strcpy ( V_66 , L_2 ) ;
V_15 = 0 ;
}
F_5 ( V_66 ) ;
} else {
F_35 () ;
V_15 = 0 ;
}
}
static int F_48 ( struct V_64 * V_65 )
{
if ( strcmp ( V_5 , L_3 ) == 0 ) {
F_29 ( V_79 L_4 ) ;
strcpy ( V_66 , L_2 ) ;
F_5 ( V_66 ) ;
F_49 () ;
V_15 = 0 ;
return 1 ;
}
return 0 ;
}
static void F_50 ( struct V_64 * V_65 )
{
struct V_55 * V_80 ;
struct V_55 * V_81 ;
unsigned char V_82 [ V_53 ] ;
char * V_30 ;
int V_2 ;
int V_71 ;
int V_83 = 0 ;
switch ( V_5 [ 1 ] ) {
case 's' :
case 'f' :
if ( memcmp ( V_5 + 2 , L_5 , 10 ) )
break;
V_2 = 0 ;
V_66 [ 0 ] = 'm' ;
V_30 = V_66 + 1 ;
if ( V_5 [ 1 ] == 'f' ) {
F_37 (cpu) {
V_65 -> V_84 = 0 ;
F_24 ( V_82 , - V_71 - 2 ) ;
V_30 = F_23 ( V_30 , V_82 ) ;
* ( V_30 ++ ) = ',' ;
V_2 ++ ;
}
}
F_51 (g, p) {
if ( V_2 >= V_65 -> V_84 && ! V_83 ) {
F_24 ( V_82 , V_81 -> V_85 ) ;
V_30 = F_23 ( V_30 , V_82 ) ;
* ( V_30 ++ ) = ',' ;
V_65 -> V_84 ++ ;
if ( V_65 -> V_84 % V_86 == 0 )
V_83 = 1 ;
}
V_2 ++ ;
} F_52 ( V_80 , V_81 ) ;
* ( -- V_30 ) = '\0' ;
break;
case 'C' :
strcpy ( V_66 , L_6 ) ;
V_65 -> V_87 = F_32 ( V_74 -> V_85 ) ;
F_24 ( V_82 , V_65 -> V_87 ) ;
F_23 ( V_66 + 2 , V_82 ) ;
break;
case 'T' :
if ( memcmp ( V_5 + 1 , L_7 , 16 ) )
break;
V_65 -> V_87 = 0 ;
V_30 = V_5 + 17 ;
F_14 ( & V_30 , & V_65 -> V_87 ) ;
if ( ! F_26 ( V_65 -> V_75 , V_65 -> V_87 ) ) {
F_22 ( V_66 , - V_47 ) ;
break;
}
if ( ( int ) V_65 -> V_87 > 0 ) {
F_10 ( F_26 ( V_65 -> V_75 ,
V_65 -> V_87 ) -> V_88 ,
V_66 , 16 ) ;
} else {
static char V_89 [ 23 + V_53 ] ;
sprintf ( V_89 , L_8 ,
( int ) ( - V_65 -> V_87 - 2 ) ) ;
F_10 ( V_89 , V_66 , strlen ( V_89 ) ) ;
}
break;
#ifdef F_53
case 'R' :
if ( strncmp ( V_5 , L_9 , 6 ) == 0 ) {
int V_20 = strlen ( V_5 + 6 ) ;
if ( ( V_20 % 2 ) != 0 ) {
strcpy ( V_66 , L_10 ) ;
break;
}
F_12 ( V_5 + 6 ,
V_66 , V_20 ) ;
V_20 = V_20 / 2 ;
V_66 [ V_20 ++ ] = 0 ;
F_54 ( V_66 ) ;
strcpy ( V_66 , L_2 ) ;
}
break;
#endif
}
}
static void F_55 ( struct V_64 * V_65 )
{
struct V_55 * V_68 ;
char * V_30 ;
switch ( V_5 [ 1 ] ) {
case 'g' :
V_30 = & V_5 [ 2 ] ;
F_14 ( & V_30 , & V_65 -> V_87 ) ;
V_68 = F_26 ( V_65 -> V_75 , V_65 -> V_87 ) ;
if ( ! V_68 && V_65 -> V_87 > 0 ) {
F_22 ( V_66 , - V_47 ) ;
break;
}
V_70 = V_68 ;
V_65 -> V_90 = V_65 -> V_87 ;
strcpy ( V_66 , L_2 ) ;
break;
case 'c' :
V_30 = & V_5 [ 2 ] ;
F_14 ( & V_30 , & V_65 -> V_87 ) ;
if ( ! V_65 -> V_87 ) {
V_91 = NULL ;
} else {
V_68 = F_26 ( V_65 -> V_75 , V_65 -> V_87 ) ;
if ( ! V_68 && V_65 -> V_87 > 0 ) {
F_22 ( V_66 , - V_47 ) ;
break;
}
V_91 = V_68 ;
}
strcpy ( V_66 , L_2 ) ;
break;
}
}
static void F_56 ( struct V_64 * V_65 )
{
char * V_30 = & V_5 [ 1 ] ;
struct V_55 * V_68 ;
F_14 ( & V_30 , & V_65 -> V_87 ) ;
V_68 = F_26 ( V_65 -> V_75 , V_65 -> V_87 ) ;
if ( V_68 )
strcpy ( V_66 , L_2 ) ;
else
F_22 ( V_66 , - V_47 ) ;
}
static void F_57 ( struct V_64 * V_65 )
{
char * V_92 = & V_5 [ 1 ] ;
char * V_30 = & V_5 [ 2 ] ;
unsigned long V_44 ;
unsigned long V_45 ;
int error = 0 ;
if ( V_93 . V_94 && * V_92 >= '1' ) {
if ( * V_92 > '4' )
return;
} else {
if ( * V_92 != '0' && * V_92 != '1' )
return;
}
if ( * V_92 == '1' && ! ( V_93 . V_95 & V_96 ) )
return;
if ( * ( V_30 ++ ) != ',' ) {
F_22 ( V_66 , - V_47 ) ;
return;
}
if ( ! F_14 ( & V_30 , & V_44 ) ) {
F_22 ( V_66 , - V_47 ) ;
return;
}
if ( * ( V_30 ++ ) != ',' ||
! F_14 ( & V_30 , & V_45 ) ) {
F_22 ( V_66 , - V_47 ) ;
return;
}
if ( V_5 [ 0 ] == 'Z' && * V_92 == '0' )
error = F_58 ( V_44 ) ;
else if ( V_5 [ 0 ] == 'z' && * V_92 == '0' )
error = F_59 ( V_44 ) ;
else if ( V_5 [ 0 ] == 'Z' )
error = V_93 . V_94 ( V_44 ,
( int ) V_45 , * V_92 - '0' ) ;
else if ( V_5 [ 0 ] == 'z' )
error = V_93 . V_97 ( V_44 ,
( int ) V_45 , * V_92 - '0' ) ;
if ( error == 0 )
strcpy ( V_66 , L_2 ) ;
else
F_22 ( V_66 , error ) ;
}
static int F_60 ( struct V_64 * V_65 )
{
if ( V_5 [ 1 ] == '0' && V_5 [ 2 ] == '9' ) {
V_65 -> V_98 = 1 ;
V_5 [ 0 ] = 'c' ;
} else if ( V_5 [ 1 ] == '1' && V_5 [ 2 ] == '5' ) {
V_65 -> V_98 = 1 ;
V_5 [ 0 ] = 'D' ;
F_35 () ;
V_15 = 0 ;
return 1 ;
} else {
F_8 ( L_11
L_12
L_13 , 0 ) ;
V_5 [ 0 ] = 'c' ;
}
return - 1 ;
}
int F_61 ( struct V_64 * V_65 )
{
int error = 0 ;
int V_26 ;
memset ( V_66 , 0 , sizeof( V_66 ) ) ;
V_70 = V_59 [ V_65 -> V_71 ] . V_60 ;
V_65 -> V_90 = F_32 ( V_59 [ V_65 -> V_71 ] . V_60 -> V_85 ) ;
V_65 -> V_98 = 0 ;
if ( V_15 ) {
unsigned char V_82 [ V_53 ] ;
char * V_30 ;
V_30 = V_66 ;
* V_30 ++ = 'T' ;
V_30 = F_9 ( V_30 , V_65 -> V_67 ) ;
V_30 += strlen ( strcpy ( V_30 , L_14 ) ) ;
F_24 ( V_82 , F_32 ( V_74 -> V_85 ) ) ;
V_30 = F_23 ( V_30 , V_82 ) ;
* V_30 ++ = ';' ;
F_5 ( V_66 ) ;
}
while ( 1 ) {
error = 0 ;
memset ( V_66 , 0 , sizeof( V_66 ) ) ;
F_3 ( V_5 ) ;
switch ( V_5 [ 0 ] ) {
case '?' :
F_34 ( V_65 ) ;
break;
case 'g' :
F_39 ( V_65 ) ;
break;
case 'G' :
F_40 ( V_65 ) ;
break;
case 'm' :
F_41 ( V_65 ) ;
break;
case 'M' :
F_42 ( V_65 ) ;
break;
#if V_41 > 0
case 'p' :
F_44 ( V_65 ) ;
break;
case 'P' :
F_45 ( V_65 ) ;
break;
#endif
case 'X' :
F_46 ( V_65 ) ;
break;
case 'D' :
case 'k' :
F_47 ( V_65 ) ;
goto V_99;
case 'R' :
if ( F_48 ( V_65 ) )
goto V_99;
break;
case 'q' :
F_50 ( V_65 ) ;
break;
case 'H' :
F_55 ( V_65 ) ;
break;
case 'T' :
F_56 ( V_65 ) ;
break;
case 'z' :
case 'Z' :
F_57 ( V_65 ) ;
break;
#ifdef F_53
case '3' :
if ( V_5 [ 1 ] == '\0' ) {
F_47 ( V_65 ) ;
return V_100 ;
}
#endif
case 'C' :
V_26 = F_60 ( V_65 ) ;
if ( V_26 > 0 )
goto V_99;
if ( V_26 == 0 )
break;
case 'c' :
case 's' :
if ( V_91 && V_91 != V_74 ) {
F_22 ( V_66 , - V_47 ) ;
break;
}
F_62 () ;
default:
V_99:
error = F_63 ( V_65 -> V_101 ,
V_65 -> V_67 ,
V_65 -> V_102 ,
V_5 ,
V_66 ,
V_65 -> V_75 ) ;
if ( error >= 0 || V_5 [ 0 ] == 'D' ||
V_5 [ 0 ] == 'k' ) {
error = 0 ;
goto V_103;
}
}
F_5 ( V_66 ) ;
}
V_103:
if ( V_65 -> V_98 )
error = 1 ;
return error ;
}
int F_64 ( struct V_64 * V_65 , char * V_104 )
{
int error ;
switch ( V_104 [ 0 ] ) {
case 'e' :
error = F_63 ( V_65 -> V_101 ,
V_65 -> V_67 ,
V_65 -> V_102 ,
V_5 ,
V_66 ,
V_65 -> V_75 ) ;
return error ;
case 's' :
case 'c' :
strcpy ( V_5 , V_104 ) ;
return 0 ;
case '$' :
strcpy ( V_5 , V_104 ) ;
V_3 = strlen ( V_5 ) ;
V_4 = 0 ;
return 0 ;
}
V_7 -> V_17 ( '+' ) ;
F_5 ( V_66 ) ;
return 0 ;
}
void F_65 ( int V_105 )
{
unsigned char V_11 , V_14 , V_10 [ 3 ] ;
int V_106 ;
if ( ! V_15 )
return;
V_15 = 0 ;
if ( ! V_7 || V_107 )
return;
V_10 [ 0 ] = 'W' ;
V_10 [ 1 ] = F_6 ( V_105 ) ;
V_10 [ 2 ] = F_7 ( V_105 ) ;
V_7 -> V_17 ( '$' ) ;
V_11 = 0 ;
for ( V_106 = 0 ; V_106 < 3 ; V_106 ++ ) {
V_14 = V_10 [ V_106 ] ;
V_11 += V_14 ;
V_7 -> V_17 ( V_14 ) ;
}
V_7 -> V_17 ( '#' ) ;
V_7 -> V_17 ( F_6 ( V_11 ) ) ;
V_7 -> V_17 ( F_7 ( V_11 ) ) ;
if ( V_7 -> V_18 )
V_7 -> V_18 () ;
}
