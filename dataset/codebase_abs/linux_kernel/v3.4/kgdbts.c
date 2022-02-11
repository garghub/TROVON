static int F_1 ( void * V_1 )
{
while ( ! V_2 )
F_2 ( 1500 ) ;
F_2 ( 1000 ) ;
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
char * V_1 = & V_16 [ 11 ] ;
if ( V_16 [ 1 ] != 'T' || V_16 [ 2 ] != '0' )
return 1 ;
F_20 ( & V_1 , & V_17 ) ;
return 0 ;
}
static int F_21 ( char * V_16 , char * V_5 )
{
unsigned long V_6 = F_6 ( V_5 ) ;
unsigned long V_18 ;
int V_19 = 0 ;
F_22 ( & V_16 [ 1 ] , ( char * ) V_20 ,
V_21 ) ;
F_23 ( V_20 , & V_22 ) ;
V_18 = F_24 ( & V_22 ) ;
F_5 ( L_15 , V_18 ) ;
#ifdef F_25
if ( V_6 + V_13 == V_18 )
V_19 = - V_13 ;
#endif
if ( V_23 && V_24 &&
V_18 + V_19 == V_24 &&
( ( ! strcmp ( V_5 , L_3 ) || ! strcmp ( V_5 , L_4 ) ) ) ) {
F_5 ( L_16 ) ;
V_25 = 1 ;
} else if ( strcmp ( V_5 , L_17 ) && V_18 + V_19 != V_6 ) {
F_26 ( L_18 ,
V_18 + V_19 , V_6 ) ;
return 1 ;
}
V_18 += V_19 ;
V_26 = V_18 ;
#ifdef F_25
F_27 ( & V_22 , V_18 ) ;
#endif
return 0 ;
}
static int F_28 ( char * V_16 , char * V_5 )
{
unsigned long V_6 = F_6 ( V_5 ) ;
static int V_27 ;
F_22 ( & V_16 [ 1 ] , ( char * ) V_20 ,
V_21 ) ;
F_23 ( V_20 , & V_22 ) ;
F_5 ( L_19 ,
F_24 ( & V_22 ) ) ;
if ( V_28 != V_17 ) {
F_5 ( L_20 , V_17 ) ;
if ( V_23 ) {
if ( V_27 &&
F_24 ( & V_22 ) != V_6 )
goto V_29;
V_27 ++ ;
V_30 . V_31 -= 2 ;
V_32 = 0 ;
return 0 ;
}
V_33 = 1 ;
V_30 . V_31 -= 4 ;
return 0 ;
}
V_29:
V_27 = 0 ;
if ( F_24 ( & V_22 ) == V_6 ) {
F_26 ( L_21 ,
F_24 ( & V_22 ) ) ;
return 1 ;
}
return 0 ;
}
static void F_29 ( char * V_5 )
{
memset ( V_12 , 0 , sizeof( V_12 ) ) ;
V_12 [ 0 ] = 'G' ;
F_30 ( V_20 , & V_22 ) ;
F_31 ( ( char * ) V_20 , & V_12 [ 1 ] , V_21 ) ;
F_8 ( V_12 ) ;
}
static void F_32 ( char * V_5 )
{
int V_34 = F_33 ( V_5 , NULL , 10 ) ;
V_35 -- ;
if ( V_35 <= 0 )
V_30 . V_31 ++ ;
else
V_30 . V_31 -= V_34 ;
F_8 ( V_30 . V_36 [ V_30 . V_31 ] . V_37 ) ;
}
static int F_34 ( char * V_16 , char * V_5 )
{
V_38 = 1 ;
if ( ! strncmp ( V_16 + 1 , V_5 , 2 ) ) {
if ( ! strncmp ( V_5 , L_22 , 2 ) )
V_38 = 2 ;
return 0 ;
}
return 1 ;
}
static void F_35 ( char * V_5 )
{
F_8 ( L_23 ) ;
}
static int F_36 ( char * V_16 , char * V_5 )
{
F_5 ( L_24 , V_28 ) ;
V_30 . V_31 -- ;
return 0 ;
}
static int F_37 ( char * V_16 , char * V_5 )
{
if ( strncmp ( V_16 , L_25 , 3 ) )
return 1 ;
if ( V_25 ) {
V_25 = 0 ;
V_30 . V_31 = - 1 ;
}
return 0 ;
}
static void F_38 ( char * V_5 )
{
if ( ! V_23 ) {
if ( V_33 ) {
V_33 = 0 ;
F_8 ( L_26 ) ;
} else {
F_8 ( V_5 ) ;
}
return;
}
switch ( V_32 ) {
case 0 :
F_5 ( L_27 ) ;
F_8 ( L_28 ) ;
break;
case 1 :
F_7 ( L_8 , NULL , V_24 ) ;
break;
case 2 :
F_8 ( L_26 ) ;
break;
case 3 :
F_7 ( L_10 , NULL , V_24 ) ;
break;
default:
F_26 ( L_29 ) ;
}
V_32 ++ ;
}
static int F_39 ( char * V_16 , char * V_5 )
{
if ( ! V_23 ) {
char * V_1 = & V_16 [ 11 ] ;
if ( V_16 [ 1 ] != 'T' || V_16 [ 2 ] != '0' )
return 1 ;
F_20 ( & V_1 , & V_28 ) ;
return 0 ;
}
switch ( V_32 ) {
case 1 :
F_22 ( & V_16 [ 1 ] , ( char * ) V_20 ,
V_21 ) ;
F_23 ( V_20 , & V_22 ) ;
F_5 ( L_15 ,
F_24 ( & V_22 ) ) ;
V_24 = V_26 + V_13 ;
break;
case 2 :
if ( strncmp ( V_16 , L_25 , 3 ) ) {
F_26 ( L_30 ) ;
return 1 ;
}
break;
case 3 :
if ( strncmp ( V_16 , L_31 , 3 ) ) {
F_26 ( L_32 ) ;
return 1 ;
} else {
char * V_1 = & V_16 [ 11 ] ;
F_20 ( & V_1 , & V_28 ) ;
}
break;
case 4 :
if ( strncmp ( V_16 , L_25 , 3 ) ) {
F_26 ( L_33 ) ;
return 1 ;
}
V_32 = 0 ;
return 0 ;
default:
F_26 ( L_34 ) ;
}
V_30 . V_31 -- ;
return 0 ;
}
static int F_40 ( char * V_16 , char * V_5 )
{
if ( strncmp ( V_16 + 1 , V_5 , 2 ) )
return 1 ;
V_2 = 1 ;
return 0 ;
}
static void F_8 ( char * V_39 )
{
unsigned char V_40 = 0 ;
int V_41 = 0 ;
char V_42 ;
strcpy ( V_43 , L_35 ) ;
strcat ( V_43 , V_39 ) ;
while ( ( V_42 = V_39 [ V_41 ] ) ) {
V_40 += V_42 ;
V_41 ++ ;
}
strcat ( V_43 , L_36 ) ;
V_43 [ V_41 + 2 ] = F_41 ( V_40 ) ;
V_43 [ V_41 + 3 ] = F_42 ( V_40 ) ;
V_43 [ V_41 + 4 ] = '\0' ;
F_5 ( L_37 , V_30 . V_31 , V_43 ) ;
}
static int F_43 ( char * V_16 )
{
char * V_44 ;
if ( V_30 . V_36 [ V_30 . V_31 ] . V_45 )
return V_30 . V_36 [ V_30 . V_31 ] . V_45 ( V_16 ,
V_30 . V_36 [ V_30 . V_31 ] . V_46 ) ;
V_44 = V_30 . V_36 [ V_30 . V_31 ] . V_46 ;
if ( * V_16 == '$' )
V_16 ++ ;
while ( * V_44 != '\0' && * V_16 != '\0' ) {
if ( * V_16 == '#' || * V_44 == '*' )
return 0 ;
if ( * V_16 != * V_44 )
return 1 ;
V_44 ++ ;
V_16 ++ ;
}
if ( * V_44 == '\0' && ( * V_16 == '\0' || * V_16 == '#' ) )
return 0 ;
return 1 ;
}
static int F_44 ( int V_47 , int V_48 )
{
int V_49 = 0 ;
if ( V_47 ) {
if ( V_50 ) {
V_50 = 0 ;
return '+' ;
}
if ( V_51 == 0 ) {
if ( V_30 . V_36 [ V_30 . V_31 ] . V_52 )
V_30 . V_36 [ V_30 . V_31 ] . V_52 ( V_30 . V_36 [ V_30 . V_31 ] . V_37 ) ;
else
F_8 ( V_30 . V_36 [ V_30 . V_31 ] . V_37 ) ;
}
if ( V_43 [ V_51 ] == '\0' ) {
F_26 ( L_38 ,
V_30 . V_53 , V_30 . V_31 ) ;
V_51 = 0 ;
F_8 ( L_23 ) ;
}
V_49 = V_43 [ V_51 ] ;
V_51 ++ ;
return V_49 ;
}
if ( V_30 . V_36 [ V_30 . V_31 ] . V_37 [ 0 ] == '\0' && V_30 . V_36 [ V_30 . V_31 ] . V_46 [ 0 ] == '\0' &&
! V_30 . V_36 [ V_30 . V_31 ] . V_52 ) {
F_26 ( L_39
L_40 , V_30 . V_53 , V_30 . V_31 ) ;
return 0 ;
}
if ( V_54 >= V_55 ) {
F_26 ( L_41
L_40 , V_30 . V_53 , V_30 . V_31 ) ;
V_54 = 0 ;
return 0 ;
}
if ( V_54 == 0 && V_48 != '$' )
return 0 ;
V_56 [ V_54 ] = V_48 ;
V_54 ++ ;
if ( V_54 > 3 && V_56 [ V_54 - 3 ] == '#' ) {
if ( V_54 >= V_55 ) {
F_26 ( L_41
L_40 , V_30 . V_53 , V_30 . V_31 ) ;
V_54 = 0 ;
return 0 ;
}
V_56 [ V_54 ] = '\0' ;
F_5 ( L_42 , V_30 . V_31 , V_56 ) ;
if ( V_30 . V_57 && V_30 . V_57 ( V_56 ) ) {
F_26 ( L_43
L_44 ,
V_30 . V_53 , V_30 . V_31 , V_30 . V_36 [ V_30 . V_31 ] . V_46 , V_56 ) ;
}
V_30 . V_31 ++ ;
V_54 = 0 ;
V_51 = 0 ;
V_50 = 1 ;
}
return 0 ;
}
static void F_45 ( void )
{
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
V_30 . V_58 = F_44 ;
V_30 . V_57 = F_43 ;
}
static void F_46 ( int V_59 )
{
char V_60 [ V_13 ] ;
char V_61 [ V_13 ] ;
F_47 ( V_60 , ( char * ) F_4 ,
V_13 ) ;
F_45 () ;
V_30 . V_36 = V_62 ;
V_30 . V_53 = L_45 ;
if ( ! V_59 )
F_48 () ;
F_47 ( V_61 , ( char * ) F_4 ,
V_13 ) ;
if ( memcmp ( V_60 , V_61 , V_13 ) ) {
F_49 ( V_63 L_46 ) ;
F_50 ( L_47 ) ;
}
if ( ! V_59 )
F_4 () ;
}
static void F_51 ( int V_64 )
{
V_38 = 0 ;
F_45 () ;
if ( V_64 ) {
V_30 . V_36 = V_65 ;
V_30 . V_53 = L_48 ;
} else {
V_30 . V_36 = V_66 ;
V_30 . V_53 = L_49 ;
}
F_48 () ;
F_4 () ;
F_48 () ;
if ( V_38 )
return;
F_26 ( L_50 , V_30 . V_53 ) ;
if ( V_64 )
V_67 = 0 ;
}
static void F_52 ( int V_68 )
{
V_38 = 0 ;
F_45 () ;
if ( V_68 ) {
V_30 . V_36 = V_69 ;
V_30 . V_53 = L_51 ;
} else {
V_30 . V_36 = V_70 ;
V_30 . V_53 = L_52 ;
}
F_48 () ;
F_17 () ;
if ( V_68 ) {
if ( V_38 == 2 ) {
F_26 ( L_53 ,
V_30 . V_53 ) ;
V_67 = 0 ;
}
F_18 () ;
}
F_48 () ;
if ( V_38 == 1 )
return;
F_26 ( L_50 , V_30 . V_53 ) ;
V_67 = 0 ;
}
static void F_53 ( int V_71 )
{
unsigned long V_72 ;
F_45 () ;
V_30 . V_36 = V_73 ;
V_30 . V_53 = L_54 ;
F_48 () ;
F_54 ( V_72 ) ;
F_55 ( V_71 * 1000 ) ;
F_56 () ;
F_57 ( V_72 ) ;
if ( V_38 != 2 )
F_26 ( L_55 ) ;
F_48 () ;
if ( V_38 == 1 )
return;
F_26 ( L_50 , V_30 . V_53 ) ;
}
static void F_58 ( void )
{
F_45 () ;
V_30 . V_36 = V_74 ;
V_30 . V_53 = L_56 ;
F_48 () ;
}
static void F_59 ( void )
{
F_45 () ;
V_30 . V_36 = V_75 ;
V_30 . V_53 = L_57 ;
F_48 () ;
}
static void F_60 ( void )
{
F_45 () ;
V_30 . V_36 = V_76 ;
V_30 . V_53 = L_58 ;
F_48 () ;
}
static void F_61 ( void )
{
F_45 () ;
V_30 . V_36 = V_77 ;
V_30 . V_53 = L_59 ;
F_48 () ;
F_4 () ;
F_4 () ;
}
static void F_62 ( void )
{
char * V_1 ;
int V_78 = 0 ;
int V_79 = 0 ;
int V_80 = 1000 ;
int V_71 = 0 ;
int V_81 ;
V_1 = strchr ( V_82 , 'F' ) ;
if ( V_1 )
V_78 = F_33 ( V_1 + 1 , NULL , 10 ) ;
V_1 = strchr ( V_82 , 'S' ) ;
if ( V_1 )
V_79 = F_33 ( V_1 + 1 , NULL , 10 ) ;
V_1 = strchr ( V_82 , 'N' ) ;
if ( V_1 )
V_71 = F_33 ( V_1 + 1 , NULL , 10 ) ;
V_1 = strchr ( V_82 , 'I' ) ;
if ( V_1 )
V_80 = F_33 ( V_1 + 1 , NULL , 10 ) ;
if ( V_83 . V_72 & V_84 ) {
V_67 = 1 ;
F_63 ( L_60 ) ;
F_51 ( 1 ) ;
F_63 ( L_61 ) ;
F_52 ( 1 ) ;
F_63 ( L_62 ) ;
F_52 ( 0 ) ;
}
F_63 ( L_63 ) ;
F_46 ( 0 ) ;
F_63 ( L_64 ) ;
F_51 ( 0 ) ;
F_63 ( L_65 ) ;
F_58 () ;
F_63 ( L_66 , V_80 ) ;
for ( V_81 = 0 ; V_81 < V_80 ; V_81 ++ ) {
F_61 () ;
if ( V_81 % 100 == 0 )
F_63 ( L_67 ,
V_81 , V_80 ) ;
}
if ( V_71 ) {
F_63 ( L_68 , V_71 ) ;
F_53 ( V_71 ) ;
}
if ( V_78 ) {
V_35 = V_78 ;
F_49 ( V_85 L_69 ,
V_35 ) ;
F_64 ( F_1 , NULL , L_70 ) ;
F_59 () ;
return;
}
if ( V_79 ) {
V_35 = V_79 ;
F_49 ( V_85 L_71 ,
V_35 ) ;
F_64 ( F_1 , NULL , L_70 ) ;
F_60 () ;
return;
}
F_3 ( & V_4 ) ;
V_3 = 0 ;
}
static int F_65 ( char * V_86 )
{
if ( strlen ( V_86 ) >= V_87 ) {
F_49 ( V_88 L_72 ) ;
return - V_89 ;
}
strcpy ( V_82 , V_86 ) ;
V_90 = 0 ;
if ( strstr ( V_82 , L_73 ) )
V_90 = 1 ;
if ( strstr ( V_82 , L_74 ) )
V_90 = 2 ;
return 0 ;
}
static int F_66 ( void )
{
int V_91 = 0 ;
if ( ! strlen ( V_82 ) || isspace ( V_82 [ 0 ] ) )
goto V_92;
V_91 = F_65 ( V_82 ) ;
if ( V_91 )
goto V_92;
V_2 = 0 ;
F_46 ( 1 ) ;
V_91 = F_67 ( & V_4 ) ;
if ( V_91 ) {
V_3 = 0 ;
return V_91 ;
}
V_3 = 1 ;
F_62 () ;
return V_91 ;
V_92:
V_82 [ 0 ] = 0 ;
V_3 = 0 ;
return V_91 ;
}
static int T_2 F_68 ( void )
{
if ( V_3 == 1 )
return 0 ;
return F_66 () ;
}
static int F_69 ( void )
{
int V_93 = 0 ;
if ( V_30 . V_58 )
V_93 = V_30 . V_58 ( 1 , 0 ) ;
return V_93 ;
}
static void F_70 ( T_3 V_48 )
{
if ( V_30 . V_58 )
V_30 . V_58 ( 0 , V_48 ) ;
}
static int F_71 ( const char * V_94 , struct V_95 * V_96 )
{
int V_97 = strlen ( V_94 ) ;
if ( V_97 >= V_87 ) {
F_49 ( V_88 L_72 ) ;
return - V_89 ;
}
if ( V_3 < 0 ) {
strcpy ( V_82 , V_94 ) ;
return 0 ;
}
if ( V_3 == 1 ) {
F_49 ( V_88 L_75 ) ;
return - V_98 ;
}
strcpy ( V_82 , V_94 ) ;
if ( V_82 [ V_97 - 1 ] == '\n' )
V_82 [ V_97 - 1 ] = '\0' ;
return F_66 () ;
}
static void F_72 ( void )
{
if ( ! V_99 )
F_73 ( V_100 ) ;
}
static void F_74 ( void )
{
if ( ! V_99 )
F_75 ( V_100 ) ;
}
