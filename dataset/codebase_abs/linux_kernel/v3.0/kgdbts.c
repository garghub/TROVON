static int F_1 ( void * V_1 )
{
while ( ! V_2 )
F_2 ( 1500 ) ;
if ( V_3 )
F_3 ( & V_4 ) ;
V_3 = 0 ;
return 0 ;
}
static T_1 void F_4 ( void )
{
F_5 ( L_1 ) ;
}
static unsigned long F_6 ( char * V_5 )
{
unsigned long V_6 = 0 ;
if ( ! strcmp ( V_5 , L_2 ) )
V_6 = ( unsigned long ) F_4 ;
else if ( ! strcmp ( V_5 , L_3 ) )
V_6 = ( unsigned long ) V_7 ;
else if ( ! strcmp ( V_5 , L_4 ) )
V_6 = ( unsigned long ) V_8 ;
else if ( ! strcmp ( V_5 , L_5 ) )
V_6 = ( unsigned long ) & V_9 ;
return V_6 ;
}
static void F_7 ( char * V_10 , char * V_5 , unsigned long V_11 )
{
unsigned long V_6 ;
if ( V_5 )
V_6 = F_6 ( V_5 ) ;
else
V_6 = V_11 ;
sprintf ( V_12 , L_6 , V_10 , V_6 ,
V_13 ) ;
F_8 ( V_12 ) ;
}
static void F_9 ( char * V_5 )
{
F_7 ( V_14 ? L_7 : L_8 , V_5 , 0 ) ;
}
static void F_10 ( char * V_5 )
{
F_7 ( V_14 ? L_9 : L_10 , V_5 , 0 ) ;
}
static void F_11 ( char * V_5 )
{
F_7 ( L_7 , V_5 , 0 ) ;
}
static void F_12 ( char * V_5 )
{
F_7 ( L_9 , V_5 , 0 ) ;
}
static void F_13 ( char * V_5 )
{
F_7 ( L_11 , V_5 , 0 ) ;
}
static void F_14 ( char * V_5 )
{
F_7 ( L_12 , V_5 , 0 ) ;
}
static void F_15 ( char * V_5 )
{
F_7 ( L_13 , V_5 , 0 ) ;
}
static void F_16 ( char * V_5 )
{
F_7 ( L_14 , V_5 , 0 ) ;
}
static void F_17 ( void )
{
V_15 = V_9 ;
}
static void F_18 ( void )
{
V_9 ++ ;
}
static int F_19 ( char * V_16 , char * V_5 )
{
unsigned long V_6 = F_6 ( V_5 ) ;
unsigned long V_17 ;
int V_18 = 0 ;
F_20 ( & V_16 [ 1 ] , ( char * ) V_19 ,
V_20 ) ;
F_21 ( V_19 , & V_21 ) ;
V_17 = F_22 ( & V_21 ) ;
F_5 ( L_15 , V_17 ) ;
#ifdef F_23
if ( V_6 + V_13 == V_17 )
V_18 = - V_13 ;
#endif
if ( strcmp ( V_5 , L_16 ) && V_17 + V_18 != V_6 ) {
F_24 ( L_17 ,
V_17 + V_18 , V_6 ) ;
return 1 ;
}
V_17 += V_18 ;
#ifdef F_23
F_25 ( & V_21 , V_17 ) ;
#endif
return 0 ;
}
static int F_26 ( char * V_16 , char * V_5 )
{
unsigned long V_6 = F_6 ( V_5 ) ;
F_20 ( & V_16 [ 1 ] , ( char * ) V_19 ,
V_20 ) ;
F_21 ( V_19 , & V_21 ) ;
F_5 ( L_18 ,
F_22 ( & V_21 ) ) ;
if ( F_22 ( & V_21 ) == V_6 ) {
F_24 ( L_19 ,
F_22 ( & V_21 ) ) ;
return 1 ;
}
return 0 ;
}
static void F_27 ( char * V_5 )
{
memset ( V_12 , 0 , sizeof( V_12 ) ) ;
V_12 [ 0 ] = 'G' ;
F_28 ( V_19 , & V_21 ) ;
F_29 ( ( char * ) V_19 , & V_12 [ 1 ] , V_20 ) ;
F_8 ( V_12 ) ;
}
static void F_30 ( char * V_5 )
{
int V_22 = F_31 ( V_5 , NULL , 10 ) ;
V_23 -- ;
if ( V_23 <= 0 )
V_24 . V_25 ++ ;
else
V_24 . V_25 -= V_22 ;
F_8 ( V_24 . V_26 [ V_24 . V_25 ] . V_27 ) ;
}
static int F_32 ( char * V_16 , char * V_5 )
{
V_28 = 1 ;
if ( ! strncmp ( V_16 + 1 , V_5 , 2 ) ) {
if ( ! strncmp ( V_5 , L_20 , 2 ) )
V_28 = 2 ;
return 0 ;
}
return 1 ;
}
static void F_33 ( char * V_5 )
{
if ( ! V_29 ) {
F_8 ( V_5 ) ;
return;
}
switch ( V_30 ) {
case 0 :
F_5 ( L_21 ) ;
F_8 ( L_22 ) ;
break;
case 1 :
F_7 ( L_8 , NULL , V_31 ) ;
break;
case 2 :
F_8 ( L_23 ) ;
break;
case 3 :
F_7 ( L_10 , NULL , V_31 ) ;
break;
default:
F_24 ( L_24 ) ;
}
V_30 ++ ;
}
static int F_34 ( char * V_16 , char * V_5 )
{
if ( ! V_29 ) {
if ( ! strncmp ( V_16 + 1 , V_5 , 2 ) )
return 0 ;
return 1 ;
}
switch ( V_30 ) {
case 1 :
F_20 ( & V_16 [ 1 ] , ( char * ) V_19 ,
V_20 ) ;
F_21 ( V_19 , & V_21 ) ;
F_5 ( L_15 ,
F_22 ( & V_21 ) ) ;
V_31 = F_22 ( & V_21 ) +
V_13 ;
break;
case 2 :
if ( strncmp ( V_16 , L_25 , 3 ) ) {
F_24 ( L_26 ) ;
return 1 ;
}
break;
case 3 :
if ( strncmp ( V_16 , L_27 , 3 ) ) {
F_24 ( L_28 ) ;
return 1 ;
}
break;
case 4 :
if ( strncmp ( V_16 , L_25 , 3 ) ) {
F_24 ( L_29 ) ;
return 1 ;
}
V_30 = 0 ;
return 0 ;
default:
F_24 ( L_30 ) ;
}
V_24 . V_25 -- ;
return 0 ;
}
static int F_35 ( char * V_16 , char * V_5 )
{
if ( strncmp ( V_16 + 1 , V_5 , 2 ) )
return 1 ;
V_2 = 1 ;
return 0 ;
}
static void F_8 ( char * V_32 )
{
unsigned char V_33 = 0 ;
int V_34 = 0 ;
char V_35 ;
strcpy ( V_36 , L_31 ) ;
strcat ( V_36 , V_32 ) ;
while ( ( V_35 = V_32 [ V_34 ] ) ) {
V_33 += V_35 ;
V_34 ++ ;
}
strcat ( V_36 , L_32 ) ;
V_36 [ V_34 + 2 ] = F_36 ( V_33 ) ;
V_36 [ V_34 + 3 ] = F_37 ( V_33 ) ;
V_36 [ V_34 + 4 ] = '\0' ;
F_5 ( L_33 , V_24 . V_25 , V_36 ) ;
}
static int F_38 ( char * V_16 )
{
char * V_37 ;
if ( V_24 . V_26 [ V_24 . V_25 ] . V_38 )
return V_24 . V_26 [ V_24 . V_25 ] . V_38 ( V_16 ,
V_24 . V_26 [ V_24 . V_25 ] . V_39 ) ;
V_37 = V_24 . V_26 [ V_24 . V_25 ] . V_39 ;
if ( * V_16 == '$' )
V_16 ++ ;
while ( * V_37 != '\0' && * V_16 != '\0' ) {
if ( * V_16 == '#' || * V_37 == '*' )
return 0 ;
if ( * V_16 != * V_37 )
return 1 ;
V_37 ++ ;
V_16 ++ ;
}
if ( * V_37 == '\0' && ( * V_16 == '\0' || * V_16 == '#' ) )
return 0 ;
return 1 ;
}
static int F_39 ( int V_40 , int V_41 )
{
int V_42 = 0 ;
if ( V_40 ) {
if ( V_43 ) {
V_43 = 0 ;
return '+' ;
}
if ( V_44 == 0 ) {
if ( V_24 . V_26 [ V_24 . V_25 ] . V_45 )
V_24 . V_26 [ V_24 . V_25 ] . V_45 ( V_24 . V_26 [ V_24 . V_25 ] . V_27 ) ;
else
F_8 ( V_24 . V_26 [ V_24 . V_25 ] . V_27 ) ;
}
if ( V_36 [ V_44 ] == '\0' ) {
F_24 ( L_34 ,
V_24 . V_46 , V_24 . V_25 ) ;
V_44 = 0 ;
F_8 ( L_35 ) ;
}
V_42 = V_36 [ V_44 ] ;
V_44 ++ ;
return V_42 ;
}
if ( V_24 . V_26 [ V_24 . V_25 ] . V_27 [ 0 ] == '\0' &&
V_24 . V_26 [ V_24 . V_25 ] . V_39 [ 0 ] == '\0' ) {
F_24 ( L_36
L_37 , V_24 . V_46 , V_24 . V_25 ) ;
return 0 ;
}
if ( V_47 >= V_48 ) {
F_24 ( L_38
L_37 , V_24 . V_46 , V_24 . V_25 ) ;
V_47 = 0 ;
return 0 ;
}
if ( V_47 == 0 && V_41 != '$' )
return 0 ;
V_49 [ V_47 ] = V_41 ;
V_47 ++ ;
if ( V_47 > 3 && V_49 [ V_47 - 3 ] == '#' ) {
if ( V_47 >= V_48 ) {
F_24 ( L_38
L_37 , V_24 . V_46 , V_24 . V_25 ) ;
V_47 = 0 ;
return 0 ;
}
V_49 [ V_47 ] = '\0' ;
F_5 ( L_39 , V_24 . V_25 , V_49 ) ;
if ( V_24 . V_50 && V_24 . V_50 ( V_49 ) ) {
F_24 ( L_40
L_41 ,
V_24 . V_46 , V_24 . V_25 , V_24 . V_26 [ V_24 . V_25 ] . V_39 , V_49 ) ;
}
V_24 . V_25 ++ ;
V_47 = 0 ;
V_44 = 0 ;
V_43 = 1 ;
}
return 0 ;
}
static void F_40 ( void )
{
memset ( & V_24 , 0 , sizeof( V_24 ) ) ;
V_24 . V_51 = F_39 ;
V_24 . V_50 = F_38 ;
}
static void F_41 ( int V_52 )
{
char V_53 [ V_13 ] ;
char V_54 [ V_13 ] ;
F_42 ( V_53 , ( char * ) F_4 ,
V_13 ) ;
F_40 () ;
V_24 . V_26 = V_55 ;
V_24 . V_46 = L_42 ;
if ( ! V_52 )
F_43 () ;
F_42 ( V_54 , ( char * ) F_4 ,
V_13 ) ;
if ( memcmp ( V_53 , V_54 , V_13 ) ) {
F_44 ( V_56 L_43 ) ;
F_45 ( L_44 ) ;
}
if ( ! V_52 )
F_4 () ;
}
static void F_46 ( int V_57 )
{
V_28 = 0 ;
F_40 () ;
if ( V_57 ) {
V_24 . V_26 = V_58 ;
V_24 . V_46 = L_45 ;
} else {
V_24 . V_26 = V_59 ;
V_24 . V_46 = L_46 ;
}
F_43 () ;
F_4 () ;
F_43 () ;
if ( V_28 )
return;
F_24 ( L_47 , V_24 . V_46 ) ;
if ( V_57 )
V_60 = 0 ;
}
static void F_47 ( int V_61 )
{
V_28 = 0 ;
F_40 () ;
if ( V_61 ) {
V_24 . V_26 = V_62 ;
V_24 . V_46 = L_48 ;
} else {
V_24 . V_26 = V_63 ;
V_24 . V_46 = L_49 ;
}
F_43 () ;
F_17 () ;
if ( V_61 ) {
if ( V_28 == 2 ) {
F_24 ( L_50 ,
V_24 . V_46 ) ;
V_60 = 0 ;
}
F_18 () ;
}
F_43 () ;
if ( V_28 == 1 )
return;
F_24 ( L_47 , V_24 . V_46 ) ;
V_60 = 0 ;
}
static void F_48 ( int V_64 )
{
unsigned long V_65 ;
F_40 () ;
V_24 . V_26 = V_66 ;
V_24 . V_46 = L_51 ;
F_43 () ;
F_49 ( V_65 ) ;
F_50 ( V_64 * 1000 ) ;
F_51 () ;
F_52 ( V_65 ) ;
if ( V_28 != 2 )
F_24 ( L_52 ) ;
F_43 () ;
if ( V_28 == 1 )
return;
F_24 ( L_47 , V_24 . V_46 ) ;
}
static void F_53 ( void )
{
F_40 () ;
V_24 . V_26 = V_67 ;
V_24 . V_46 = L_53 ;
F_43 () ;
}
static void F_54 ( void )
{
F_40 () ;
V_24 . V_26 = V_68 ;
V_24 . V_46 = L_54 ;
F_43 () ;
}
static void F_55 ( void )
{
F_40 () ;
V_24 . V_26 = V_69 ;
V_24 . V_46 = L_55 ;
F_43 () ;
}
static void F_56 ( void )
{
F_40 () ;
V_24 . V_26 = V_70 ;
V_24 . V_46 = L_56 ;
F_43 () ;
F_4 () ;
F_4 () ;
}
static void F_57 ( void )
{
char * V_1 ;
int V_71 = 0 ;
int V_72 = 0 ;
int V_73 = 1000 ;
int V_64 = 0 ;
int V_74 ;
V_1 = strchr ( V_75 , 'F' ) ;
if ( V_1 )
V_71 = F_31 ( V_1 + 1 , NULL , 10 ) ;
V_1 = strchr ( V_75 , 'S' ) ;
if ( V_1 )
V_72 = F_31 ( V_1 + 1 , NULL , 10 ) ;
V_1 = strchr ( V_75 , 'N' ) ;
if ( V_1 )
V_64 = F_31 ( V_1 + 1 , NULL , 10 ) ;
V_1 = strchr ( V_75 , 'I' ) ;
if ( V_1 )
V_73 = F_31 ( V_1 + 1 , NULL , 10 ) ;
F_58 ( L_57 ) ;
F_41 ( 0 ) ;
F_58 ( L_58 ) ;
F_46 ( 0 ) ;
F_58 ( L_59 ) ;
F_53 () ;
F_58 ( L_60 , V_73 ) ;
for ( V_74 = 0 ; V_74 < V_73 ; V_74 ++ ) {
F_56 () ;
if ( V_74 % 100 == 0 )
F_58 ( L_61 ,
V_74 , V_73 ) ;
}
if ( V_76 . V_65 & V_77 ) {
V_60 = 1 ;
F_58 ( L_62 ) ;
F_46 ( 1 ) ;
F_58 ( L_63 ) ;
F_47 ( 1 ) ;
F_58 ( L_64 ) ;
F_47 ( 0 ) ;
}
if ( V_64 ) {
F_58 ( L_65 , V_64 ) ;
F_48 ( V_64 ) ;
}
#ifdef F_59
if ( ! ( V_76 . V_65 & V_77 && V_60 ) ) {
F_24 ( L_66
L_67 ) ;
return;
}
V_14 = 1 ;
#endif
if ( V_71 ) {
V_23 = V_71 ;
F_44 ( V_78 L_68 ,
V_23 ) ;
F_60 ( F_1 , NULL , L_69 ) ;
F_54 () ;
return;
}
if ( V_72 ) {
V_23 = V_72 ;
F_44 ( V_78 L_70 ,
V_23 ) ;
F_60 ( F_1 , NULL , L_69 ) ;
F_55 () ;
return;
}
F_3 ( & V_4 ) ;
V_3 = 0 ;
}
static int F_61 ( char * V_79 )
{
if ( strlen ( V_79 ) >= V_80 ) {
F_44 ( V_81 L_71 ) ;
return - V_82 ;
}
strcpy ( V_75 , V_79 ) ;
V_83 = 0 ;
if ( strstr ( V_75 , L_72 ) )
V_83 = 1 ;
if ( strstr ( V_75 , L_73 ) )
V_83 = 2 ;
return 0 ;
}
static int F_62 ( void )
{
int V_84 = 0 ;
if ( ! strlen ( V_75 ) || isspace ( V_75 [ 0 ] ) )
goto V_85;
V_84 = F_61 ( V_75 ) ;
if ( V_84 )
goto V_85;
V_2 = 0 ;
F_41 ( 1 ) ;
V_84 = F_63 ( & V_4 ) ;
if ( V_84 ) {
V_3 = 0 ;
return V_84 ;
}
V_3 = 1 ;
F_57 () ;
return V_84 ;
V_85:
V_75 [ 0 ] = 0 ;
V_3 = 0 ;
return V_84 ;
}
static int T_2 F_64 ( void )
{
if ( V_3 == 1 )
return 0 ;
return F_62 () ;
}
static int F_65 ( void )
{
int V_86 = 0 ;
if ( V_24 . V_51 )
V_86 = V_24 . V_51 ( 1 , 0 ) ;
return V_86 ;
}
static void F_66 ( T_3 V_41 )
{
if ( V_24 . V_51 )
V_24 . V_51 ( 0 , V_41 ) ;
}
static int F_67 ( const char * V_87 , struct V_88 * V_89 )
{
int V_90 = strlen ( V_87 ) ;
if ( V_90 >= V_80 ) {
F_44 ( V_81 L_71 ) ;
return - V_82 ;
}
if ( V_3 < 0 ) {
strcpy ( V_75 , V_87 ) ;
return 0 ;
}
if ( V_3 == 1 ) {
F_44 ( V_81 L_74 ) ;
return - V_91 ;
}
strcpy ( V_75 , V_87 ) ;
if ( V_75 [ V_90 - 1 ] == '\n' )
V_75 [ V_90 - 1 ] = '\0' ;
return F_62 () ;
}
static void F_68 ( void )
{
if ( ! V_92 )
F_69 ( V_93 ) ;
}
static void F_70 ( void )
{
if ( ! V_92 )
F_71 ( V_93 ) ;
}
