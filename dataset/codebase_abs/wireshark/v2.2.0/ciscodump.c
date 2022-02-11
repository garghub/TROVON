static char * F_1 ( T_1 * V_1 , unsigned int V_2 )
{
T_2 * V_3 = F_2 ( NULL ) ;
T_1 * V_4 ;
if ( V_1 ) {
F_3 ( V_3 , L_1 ,
( char * ) V_1 -> V_5 , V_2 , V_2 , ( char * ) V_1 -> V_5 ) ;
V_4 = F_4 ( V_1 ) ;
while ( V_4 ) {
F_3 ( V_3 , L_2 ,
( char * ) V_4 -> V_5 , V_2 , V_2 , ( char * ) V_4 -> V_5 ) ;
V_4 = F_4 ( V_4 ) ;
}
F_3 ( V_3 , L_3 ) ;
}
return F_5 ( V_3 , FALSE ) ;
}
static char * F_6 ( const unsigned int V_2 )
{
T_1 * V_1 = F_7 () ;
char * V_3 = F_1 ( V_1 , V_2 ) ;
F_8 ( V_1 , V_6 ) ;
return V_3 ;
}
static int F_9 ( T_3 V_7 , int V_8 , char * V_9 )
{
char V_10 ;
int V_11 ;
int V_12 ;
V_11 = ( V_8 > 0 ? V_8 : V_13 ) ;
V_12 = 0 ;
while( F_10 ( V_7 , & V_10 , 1 , 0 , 2000 ) > 0 && V_12 < V_11 ) {
F_11 ( L_4 , V_10 ) ;
if ( V_10 == '^' )
return V_14 ;
if ( V_9 )
V_9 [ V_12 ] = V_10 ;
V_12 ++ ;
}
return V_15 ;
}
static void F_12 ( T_4 V_16 , T_3 V_7 , const char * V_17 , const char * V_18 )
{
if ( V_7 ) {
if ( F_9 ( V_7 , - 1 , NULL ) == V_15 ) {
F_13 ( V_7 , L_5 , V_19 ) ;
F_13 ( V_7 , L_6 , V_19 , V_17 ) ;
F_13 ( V_7 , L_7 , V_20 ) ;
if ( V_18 ) {
F_13 ( V_7 , L_8 ) ;
F_13 ( V_7 , L_9 , V_21 ) ;
}
F_9 ( V_7 , - 1 , NULL ) ;
}
}
F_14 ( & V_16 , & V_7 ) ;
}
static int F_15 ( T_3 V_7 , const long unsigned V_22 )
{
long unsigned V_23 = 0 ;
char V_24 [ V_25 ] ;
char * V_26 ;
T_5 V_27 = 100 ;
while ( V_23 < V_22 && V_27 -- ) {
if ( F_13 ( V_7 , L_10 , V_20 ) == V_14 ) {
F_16 ( L_11 ) ;
return V_14 ;
}
if ( F_9 ( V_7 , V_25 , V_24 ) == V_14 )
return V_14 ;
V_26 = F_17 ( V_24 , strlen ( V_24 ) , L_12 ) ;
if ( ! V_26 ) {
F_16 ( L_13 ) ;
return V_14 ;
} else {
if ( sscanf ( V_26 , L_14 , & V_23 ) != 1 )
return V_14 ;
}
}
F_11 ( L_15 ) ;
return V_15 ;
}
static int F_18 ( char * T_6 V_28 , unsigned * V_29 , char * line , int V_30 )
{
char * * V_31 ;
char * * V_32 ;
T_7 V_33 ;
T_8 V_34 ;
if ( strlen ( line ) <= 1 ) {
if ( V_30 == V_35 )
return V_36 ;
else
return V_30 ;
}
if ( F_19 ( L_16 , line , V_37 , V_38 ) ) {
return V_39 ;
}
V_31 = F_20 (
L_17 ,
line , V_37 , V_38 ) ;
V_32 = V_31 ;
while( * V_32 ) {
if ( strlen ( * V_32 ) > 1 ) {
V_33 = ( T_7 ) strtoul ( * V_32 , NULL , 16 ) ;
V_33 = F_21 ( V_33 ) ;
V_34 = strlen ( * V_32 ) / 2 ;
memcpy ( T_6 + * V_29 , & V_33 , V_34 ) ;
* V_29 += ( T_7 ) V_34 ;
}
V_32 ++ ;
}
return V_35 ;
}
static void F_22 ( T_3 V_7 , T_9 * V_40 , const long unsigned V_22 )
{
char line [ V_25 ] ;
char V_10 ;
unsigned V_29 = 0 ;
unsigned V_41 = 0 ;
char * T_6 ;
T_10 V_42 = time ( NULL ) ;
int V_43 ;
T_11 V_44 ;
long unsigned V_45 = 0 ;
int V_30 = V_46 ;
T_6 = ( char * ) F_23 ( V_47 ) ;
do {
if ( F_10 ( V_7 , & V_10 , 1 , FALSE , V_48 ) == V_49 ) {
F_16 ( L_18 ) ;
V_6 ( T_6 ) ;
return;
}
if ( V_10 != '\n' ) {
line [ V_29 ] = V_10 ;
V_29 ++ ;
} else {
line [ V_29 ] = '\0' ;
V_30 = F_18 ( T_6 , & V_41 , line , V_30 ) ;
if ( V_30 == V_36 ) {
F_24 ( V_40 , V_42 , ( T_7 ) ( V_42 / 1000 ) , V_41 , V_41 , T_6 , & V_44 , & V_43 ) ;
F_11 ( L_19 , V_45 , V_41 ) ;
V_41 = 0 ;
V_30 = V_46 ;
V_45 ++ ;
}
V_29 = 0 ;
}
} while( V_45 < V_22 );
V_6 ( T_6 ) ;
}
static int F_25 ( T_3 V_7 )
{
T_12 * V_50 = L_20 ;
T_12 V_51 [ 255 ] ;
T_5 V_52 = 0 ;
T_5 V_53 = 0 ;
T_12 * V_4 ;
memset ( V_51 , 0x0 , 255 ) ;
if ( F_26 ( V_7 , V_50 , ( T_7 ) strlen ( V_50 ) ) == V_49 )
return FALSE ;
if ( F_9 ( V_7 , ( int ) strlen ( V_50 ) , NULL ) == V_14 )
return FALSE ;
if ( F_9 ( V_7 , 255 , V_51 ) == V_14 )
return FALSE ;
V_4 = F_17 ( V_51 , strlen ( V_51 ) , L_21 ) ;
if ( V_4 ) {
V_4 += strlen ( L_22 ) ;
if ( sscanf ( V_4 , L_23 , & V_52 , & V_53 ) != 2 )
return FALSE ;
if ( ( V_52 > V_54 ) || ( V_52 == V_54 && V_53 >= V_55 ) ) {
F_11 ( L_24 , V_52 , V_53 ) ;
if ( F_9 ( V_7 , - 1 , NULL ) == V_14 )
return FALSE ;
return TRUE ;
}
}
F_16 ( L_25 , V_52 , V_53 ) ;
return FALSE ;
}
static T_3 F_27 ( T_4 V_16 , const char * V_17 , const char * V_18 , const unsigned long int V_22 )
{
char * V_50 = NULL ;
T_3 V_7 ;
int V_56 = 0 ;
V_7 = F_28 ( V_16 ) ;
if ( ! V_7 )
return NULL ;
if ( F_29 ( V_7 ) != V_57 )
goto error;
if ( F_30 ( V_7 ) != V_57 )
goto error;
if ( F_31 ( V_7 , 80 , 24 ) != V_57 )
goto error;
if ( F_32 ( V_7 ) != V_57 )
goto error;
if ( ! F_25 ( V_7 ) )
goto error;
if ( F_13 ( V_7 , L_26 ) == V_14 )
goto error;
if ( F_13 ( V_7 , L_27 , V_20 ) == V_14 )
goto error;
if ( F_13 ( V_7 , L_28 , V_20 , V_22 ) == V_14 )
goto error;
if ( V_18 ) {
T_12 * V_58 ;
T_12 * V_10 ;
if ( F_13 ( V_7 , L_8 ) == V_14 )
goto error;
if ( F_13 ( V_7 , L_29 , V_21 ) == V_14 )
goto error;
V_58 = F_33 ( V_18 ) ;
V_10 = V_58 ;
while( ( V_10 = F_17 ( V_10 , strlen ( V_10 ) , L_30 ) ) != NULL ) {
V_10 [ 0 ] = '\n' ;
F_11 ( L_31 ) ;
}
V_56 = F_26 ( V_7 , V_58 , ( V_59 ) strlen ( V_58 ) ) ;
V_6 ( V_58 ) ;
if ( V_56 == V_49 )
goto error;
if ( F_13 ( V_7 , L_32 ) == V_14 )
goto error;
if ( F_13 ( V_7 , L_33 ,
V_20 , V_21 ) == V_14 )
goto error;
}
if ( F_13 ( V_7 , L_34 , V_19 ,
V_17 ) == V_14 )
goto error;
if ( F_13 ( V_7 , L_35 , V_19 ,
V_20 ) == V_14 )
goto error;
if ( F_13 ( V_7 , L_36 , V_19 ) == V_14 )
goto error;
if ( F_9 ( V_7 , - 1 , NULL ) == V_14 )
goto error;
if ( F_15 ( V_7 , V_22 ) == V_14 )
goto error;
if ( F_9 ( V_7 , - 1 , NULL ) == V_14 )
goto error;
V_50 = F_34 ( L_37 , V_20 ) ;
if ( F_13 ( V_7 , V_50 ) == V_14 )
goto error;
if ( F_9 ( V_7 , ( int ) strlen ( V_50 ) , NULL ) == V_14 )
goto error;
V_6 ( V_50 ) ;
return V_7 ;
error:
V_6 ( V_50 ) ;
F_16 ( L_38 ) ;
F_9 ( V_7 , - 1 , NULL ) ;
F_35 ( V_7 ) ;
F_36 ( V_7 ) ;
return NULL ;
}
static int F_37 ( const char * V_60 , const unsigned int V_61 , const char * V_62 , const char * V_63 ,
const char * V_64 , const char * V_65 , const char * V_17 , const char * V_18 ,
const unsigned long int V_22 , const char * V_66 )
{
T_4 V_16 ;
T_3 V_7 ;
T_9 * V_40 = stdout ;
T_11 V_44 = 0 ;
int V_43 ;
int V_56 = V_14 ;
char * V_67 = NULL ;
if ( F_38 ( V_66 , L_39 ) ) {
V_40 = fopen ( V_66 , L_40 ) ;
if ( ! V_40 ) {
F_16 ( L_41 , F_39 ( V_68 ) ) ;
return V_14 ;
}
}
V_16 = F_40 ( V_60 , V_61 , V_62 , V_63 , V_64 , V_65 , & V_67 ) ;
if ( ! V_16 ) {
F_16 ( L_42 , V_67 ) ;
goto V_69;
}
if ( ! F_41 ( V_40 , 1 , V_70 , FALSE , & V_44 , & V_43 ) ) {
F_16 ( L_43 ) ;
goto V_69;
}
V_7 = F_27 ( V_16 , V_17 , V_18 , V_22 ) ;
if ( ! V_7 ) {
V_56 = V_14 ;
goto V_69;
}
F_11 ( L_44 ) ;
F_22 ( V_7 , V_40 , V_22 ) ;
F_12 ( V_16 , V_7 , V_17 , V_18 ) ;
V_56 = V_15 ;
V_69:
if ( V_40 != stdout )
fclose ( V_40 ) ;
F_11 ( L_45 ) ;
return V_56 ;
}
static void F_42 ( const char * V_71 )
{
printf ( L_46 ) ;
printf ( L_47 ) ;
printf ( L_48 , V_71 ) ;
printf ( L_49 , V_71 ) ;
printf ( L_50 , V_71 ) ;
printf ( L_51
L_52
L_53 , V_71 ) ;
printf ( L_45 ) ;
printf ( L_54 ) ;
printf ( L_55 ) ;
printf ( L_56 ) ;
printf ( L_57 ) ;
printf ( L_58 ) ;
printf ( L_59 ) ;
printf ( L_60 ) ;
printf ( L_61 ) ;
printf ( L_62 ) ;
printf ( L_63 ) ;
printf ( L_64 ) ;
printf ( L_65 ) ;
printf ( L_66 ) ;
printf ( L_67 ) ;
printf ( L_68 ) ;
printf ( L_69 ) ;
printf ( L_70 ) ;
printf ( L_71 ) ;
}
static int F_43 ( char * V_72 , unsigned int V_2 )
{
unsigned V_73 = 0 ;
char * V_74 ;
if ( ! V_72 ) {
F_44 ( V_75 , L_72 ) ;
return V_14 ;
}
if ( F_38 ( V_72 , V_76 ) ) {
F_16 ( L_73 , V_76 ) ;
return V_14 ;
}
V_74 = F_6 ( V_2 ) ;
printf ( L_74
L_75
L_76 , V_73 ++ ) ;
printf ( L_77
L_78
L_79 , V_73 ++ ) ;
printf ( L_80
L_81
L_82 , V_73 ++ , F_45 () ) ;
printf ( L_83
L_84
L_85 , V_73 ++ ) ;
printf ( L_86
L_87 ,
V_73 ++ ) ;
printf ( L_88
L_89 ,
V_73 ++ ) ;
printf ( L_90
L_91
L_92 , V_73 ++ ) ;
printf ( L_93
L_94 , V_73 ++ ) ;
if ( V_74 )
printf ( L_95 , V_74 ) ;
printf ( L_44 ) ;
printf ( L_96
L_97 ,
V_73 ++ ) ;
V_6 ( V_74 ) ;
return V_15 ;
}
int main ( int V_77 , char * * V_78 )
{
int V_79 ;
int V_80 = 0 ;
int V_81 ;
char * V_82 = NULL ;
unsigned int V_2 = 22 ;
char * V_83 = NULL ;
char * V_84 = NULL ;
char * V_85 = NULL ;
char * V_64 = NULL ;
char * V_65 = NULL ;
char * V_86 = NULL ;
unsigned long int V_22 = 0 ;
int V_56 = V_14 ;
T_13 * V_87 = F_46 ( T_13 , 1 ) ;
#ifdef F_47
T_14 V_88 ;
F_48 () ;
#endif
F_49 ( V_87 , V_89 , V_90 , V_91 , NULL ) ;
F_50 ( V_87 , V_76 , L_98 , 147 , L_99 ) ;
V_92 = 0 ;
V_93 = 0 ;
if ( V_77 == 1 ) {
F_42 ( V_78 [ 0 ] ) ;
goto V_94;
}
for ( V_81 = 0 ; V_81 < V_77 ; V_81 ++ ) {
F_11 ( L_100 , V_78 [ V_81 ] ) ;
}
F_11 ( L_44 ) ;
while ( ( V_79 = F_51 ( V_77 , V_78 , L_101 , V_95 , & V_80 ) ) != - 1 ) {
switch ( V_79 ) {
case V_96 :
F_42 ( V_78 [ 0 ] ) ;
V_56 = V_15 ;
goto V_94;
case V_97 :
V_98 = TRUE ;
break;
case V_99 :
printf ( L_102 , V_89 , V_90 , V_91 ) ;
goto V_94;
case V_100 :
V_6 ( V_82 ) ;
V_82 = F_33 ( V_101 ) ;
break;
case V_102 :
V_2 = ( unsigned int ) strtoul ( V_101 , NULL , 10 ) ;
if ( V_2 > 65535 || V_2 == 0 ) {
printf ( L_103 , V_101 ) ;
goto V_94;
}
break;
case V_103 :
V_6 ( V_83 ) ;
V_83 = F_33 ( V_101 ) ;
break;
case V_104 :
V_6 ( V_84 ) ;
V_84 = F_33 ( V_101 ) ;
memset ( V_101 , 'X' , strlen ( V_101 ) ) ;
break;
case V_105 :
V_6 ( V_64 ) ;
V_64 = F_33 ( V_101 ) ;
break;
case V_106 :
V_6 ( V_65 ) ;
V_65 = F_33 ( V_101 ) ;
memset ( V_101 , 'X' , strlen ( V_101 ) ) ;
break;
case V_107 :
V_6 ( V_85 ) ;
V_85 = F_33 ( V_101 ) ;
break;
case V_108 :
V_6 ( V_86 ) ;
V_86 = F_33 ( V_101 ) ;
break;
case V_109 :
V_22 = strtoul ( V_101 , NULL , 10 ) ;
break;
case ':' :
F_16 ( L_104 , V_78 [ V_93 - 1 ] ) ;
break;
default:
if ( ! F_52 ( V_87 , V_79 - V_110 , V_101 ) ) {
F_16 ( L_105 , V_78 [ V_93 - 1 ] ) ;
goto V_94;
}
}
}
if ( V_93 != V_77 ) {
F_16 ( L_106 , V_78 [ V_93 ] ) ;
goto V_94;
}
if ( F_53 ( V_87 ) ) {
V_56 = V_15 ;
goto V_94;
}
if ( V_87 -> V_111 ) {
V_56 = F_43 ( V_87 -> V_72 , V_2 ) ;
goto V_94;
}
#ifdef F_47
V_79 = F_54 ( F_55 ( 1 , 1 ) , & V_88 ) ;
if ( V_79 != 0 ) {
if ( V_98 )
F_16 ( L_107 , V_79 ) ;
goto V_94;
}
#endif
if ( V_87 -> V_112 ) {
if ( ! V_82 ) {
F_16 ( L_108 ) ;
goto V_94;
}
if ( ! V_85 ) {
F_16 ( L_109 ) ;
goto V_94;
}
if ( V_22 == 0 ) {
F_16 ( L_110 ) ;
goto V_94;
}
V_56 = F_37 ( V_82 , V_2 , V_83 ,
V_84 , V_64 , V_65 , V_85 ,
V_86 , V_22 , V_87 -> V_66 ) ;
} else {
F_11 ( L_111 ) ;
V_56 = V_14 ;
}
V_94:
V_6 ( V_82 ) ;
V_6 ( V_83 ) ;
V_6 ( V_84 ) ;
V_6 ( V_85 ) ;
V_6 ( V_64 ) ;
V_6 ( V_65 ) ;
V_6 ( V_86 ) ;
F_56 ( & V_87 ) ;
return V_56 ;
}
int T_15
F_57 ( struct V_113 * V_114 ,
struct V_113 * V_115 ,
char * V_116 ,
int V_117 )
{
return main ( V_118 , V_119 ) ;
}
