static T_1 *
F_1 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 * V_5 = ( T_1 * ) F_2 ( 16 ) ;
#if ( V_6 V_7 ) && ( V_8 < 1500 )
if( V_2 -> V_9 > 2000000000 ) {
V_4 = NULL ;
} else
#endif
V_4 = localtime ( & V_2 -> V_9 ) ;
if ( V_4 ) {
F_3 ( V_5 , 16 , L_1 ,
V_4 -> V_10 + 1900 ,
V_4 -> V_11 + 1 ,
V_4 -> V_12 ,
V_4 -> V_13 ,
V_4 -> V_14 ,
V_4 -> V_15 ) ;
} else
V_5 [ 0 ] = '\0' ;
return V_5 ;
}
static T_1 *
F_4 ( T_2 V_16 , const struct V_1 * V_17 ,
T_1 * V_18 , T_1 * V_19 )
{
T_1 V_20 [ 5 + 1 ] ;
T_1 * V_21 ;
T_1 * V_22 ;
V_21 = F_1 ( V_17 ) ;
F_3 ( V_20 , sizeof( V_20 ) , L_2 , V_16 % V_23 ) ;
V_22 = F_5 ( V_18 , L_3 , V_20 , L_3 , V_21 , V_19 , NULL ) ;
F_6 ( V_21 ) ;
return V_22 ;
}
static T_3
F_7 ( const char * V_24 , T_1 * * V_18 , T_1 * * V_19 )
{
char * V_25 , * V_26 ;
T_1 * V_27 ;
V_27 = F_8 ( V_24 ) ;
if ( V_27 == NULL ) {
fprintf ( V_28 , L_4 ) ;
return FALSE ;
}
V_26 = strrchr ( V_27 , V_29 ) ;
V_25 = strrchr ( V_27 , '.' ) ;
if ( V_25 != NULL && ( V_26 == NULL || V_25 > V_26 ) ) {
V_25 [ 0 ] = '\0' ;
* V_18 = F_8 ( V_27 ) ;
V_25 [ 0 ] = '.' ;
* V_19 = F_8 ( V_25 ) ;
} else {
* V_18 = F_8 ( V_27 ) ;
* V_19 = NULL ;
}
F_6 ( V_27 ) ;
return TRUE ;
}
static T_3
F_9 ( char * V_30 )
{
char * V_31 ;
char * V_32 ;
if ( ++ V_33 >= V_34 ) {
printf ( L_5 ) ;
return ( FALSE ) ;
}
printf ( L_6 , V_30 ) ;
if ( ( V_31 = strchr ( V_30 , '-' ) ) == NULL ) {
printf ( L_7 ) ;
V_35 [ V_33 ] . V_36 = 0 ;
V_35 [ V_33 ] . V_37 = atoi ( V_30 ) ;
printf ( L_8 , V_35 [ V_33 ] . V_37 ) ;
}
else {
printf ( L_9 ) ;
V_32 = V_31 + 1 ;
V_35 [ V_33 ] . V_36 = 1 ;
V_35 [ V_33 ] . V_37 = atoi ( V_30 ) ;
V_35 [ V_33 ] . V_38 = atoi ( V_32 ) ;
printf ( L_10 , V_35 [ V_33 ] . V_37 , V_35 [ V_33 ] . V_38 ) ;
}
return ( TRUE ) ;
}
static int
F_10 ( int V_39 )
{
int V_40 = 0 ;
for ( V_40 = 0 ; V_40 <= V_33 ; V_40 ++ ) {
if ( V_35 [ V_40 ] . V_36 ) {
if ( V_35 [ V_40 ] . V_37 <= V_39 && V_35 [ V_40 ] . V_38 >= V_39 )
return 1 ;
}
else {
if ( V_39 == V_35 [ V_40 ] . V_37 )
return 1 ;
}
}
return 0 ;
}
static T_3
F_11 ( T_4 * V_41 )
{
struct V_42 * V_43 = F_12 ( V_41 ) ;
return ( V_43 -> V_44 . V_9 >= V_45 ) && ( V_43 -> V_44 . V_9 < V_46 ) ;
}
static void
F_13 ( char * V_47 )
{
char * V_48 , * V_49 ;
long V_50 ;
T_5 V_51 ;
if ( ! V_47 )
return;
while ( * V_47 == ' ' || * V_47 == '\t' ) {
V_47 ++ ;
}
if ( * V_47 == '-' ) {
V_52 . V_53 = 1 ;
V_47 ++ ;
}
if ( * V_47 == '.' ) {
V_50 = 0 ;
V_48 = V_47 ;
} else {
V_50 = strtol ( V_47 , & V_48 , 10 ) ;
if ( V_48 == NULL || V_48 == V_47 || V_50 == V_54 || V_50 == V_55 ) {
fprintf ( V_28 , L_11 ,
V_47 ) ;
exit ( 1 ) ;
}
if ( V_50 < 0 ) {
fprintf ( V_28 , L_11 ,
V_47 ) ;
exit ( 1 ) ;
}
}
V_52 . V_56 . V_57 = V_50 ;
if ( * V_48 != '\0' ) {
V_50 = strtol ( & ( V_48 [ 1 ] ) , & V_49 , 10 ) ;
if( ( V_49 - & ( V_48 [ 1 ] ) ) > 6 ) {
V_48 [ 7 ] = 't' ;
V_50 = strtol ( & ( V_48 [ 1 ] ) , & V_49 , 10 ) ;
}
if ( * V_48 != '.' || V_49 == NULL || V_49 == V_48
|| V_50 < 0 || V_50 > V_58 || V_50 == V_54 || V_50 == V_55 ) {
fprintf ( V_28 , L_11 ,
V_47 ) ;
exit ( 1 ) ;
}
}
else {
return;
}
if ( V_48 && V_49 ) {
V_51 = V_49 - V_48 - 1 ;
while( V_51 < 6 ) {
V_50 *= 10 ;
V_51 ++ ;
}
}
V_52 . V_56 . V_59 = ( int ) V_50 ;
}
static void
F_14 ( char * V_47 )
{
char * V_48 , * V_49 ;
long V_50 ;
T_5 V_51 ;
if ( ! V_47 )
return;
while ( * V_47 == ' ' || * V_47 == '\t' ) {
V_47 ++ ;
}
if ( * V_47 == '-' ) {
V_60 . V_53 = 1 ;
V_47 ++ ;
}
if ( * V_47 == '.' ) {
V_50 = 0 ;
V_48 = V_47 ;
} else {
V_50 = strtol ( V_47 , & V_48 , 10 ) ;
if ( V_48 == NULL || V_48 == V_47 || V_50 == V_54 || V_50 == V_55 ) {
fprintf ( V_28 , L_11 ,
V_47 ) ;
exit ( 1 ) ;
}
if ( V_50 < 0 ) {
fprintf ( V_28 , L_11 ,
V_47 ) ;
exit ( 1 ) ;
}
}
V_60 . V_56 . V_57 = V_50 ;
if ( * V_48 != '\0' ) {
V_50 = strtol ( & ( V_48 [ 1 ] ) , & V_49 , 10 ) ;
if( ( V_49 - & ( V_48 [ 1 ] ) ) > 6 ) {
V_48 [ 7 ] = 't' ;
V_50 = strtol ( & ( V_48 [ 1 ] ) , & V_49 , 10 ) ;
}
if ( * V_48 != '.' || V_49 == NULL || V_49 == V_48
|| V_50 < 0 || V_50 > V_58 || V_50 == V_54 || V_50 == V_55 ) {
fprintf ( V_28 , L_11 ,
V_47 ) ;
exit ( 1 ) ;
}
}
else {
return;
}
if ( V_48 && V_49 ) {
V_51 = V_49 - V_48 - 1 ;
while( V_51 < 6 ) {
V_50 *= 10 ;
V_51 ++ ;
}
}
V_60 . V_56 . V_59 = ( int ) V_50 ;
}
static void
F_15 ( char * V_47 )
{
char * V_48 , * V_49 ;
long V_50 ;
T_5 V_51 ;
if ( ! V_47 )
return;
while ( * V_47 == ' ' || * V_47 == '\t' ) {
V_47 ++ ;
}
if ( * V_47 == '-' ) {
V_47 ++ ;
}
if ( * V_47 == '.' ) {
V_50 = 0 ;
V_48 = V_47 ;
} else {
V_50 = strtol ( V_47 , & V_48 , 10 ) ;
if ( V_48 == NULL || V_48 == V_47 || V_50 == V_54 || V_50 == V_55 ) {
fprintf ( V_28 , L_12 ,
V_47 ) ;
exit ( 1 ) ;
}
if ( V_50 < 0 ) {
fprintf ( V_28 , L_13 ,
V_47 ) ;
exit ( 1 ) ;
}
}
V_61 . V_9 = V_50 ;
if ( * V_48 != '\0' ) {
V_50 = strtol ( & ( V_48 [ 1 ] ) , & V_49 , 10 ) ;
if( ( V_49 - & ( V_48 [ 1 ] ) ) > 9 ) {
V_48 [ 10 ] = 't' ;
V_50 = strtol ( & ( V_48 [ 1 ] ) , & V_49 , 10 ) ;
}
if ( * V_48 != '.' || V_49 == NULL || V_49 == V_48
|| V_50 < 0 || V_50 > V_62 || V_50 == V_54 || V_50 == V_55 ) {
fprintf ( V_28 , L_14 ,
V_47 ) ;
exit ( 1 ) ;
}
}
else {
return;
}
if ( V_48 && V_49 ) {
V_51 = V_49 - V_48 - 1 ;
while( V_51 < 9 ) {
V_50 *= 10 ;
V_51 ++ ;
}
}
V_61 . V_63 = ( int ) V_50 ;
}
static T_3
F_16 ( T_6 * V_64 , T_7 V_65 ) {
int V_40 ;
T_8 V_66 ;
V_67 ++ ;
if ( V_67 >= V_68 )
V_67 = 0 ;
F_17 ( & V_66 ) ;
F_18 ( & V_66 , V_64 , V_65 ) ;
F_19 ( & V_66 , V_69 [ V_67 ] . V_70 ) ;
V_69 [ V_67 ] . V_65 = V_65 ;
for ( V_40 = 0 ; V_40 < V_68 ; V_40 ++ ) {
if ( V_40 == V_67 )
continue;
if ( V_69 [ V_40 ] . V_65 == V_69 [ V_67 ] . V_65 &&
memcmp ( V_69 [ V_40 ] . V_70 , V_69 [ V_67 ] . V_70 , 16 ) == 0 ) {
return TRUE ;
}
}
return FALSE ;
}
static T_3
F_20 ( T_6 * V_64 , T_7 V_65 , const T_9 * V_71 ) {
int V_40 ;
T_8 V_66 ;
V_67 ++ ;
if ( V_67 >= V_68 )
V_67 = 0 ;
F_17 ( & V_66 ) ;
F_18 ( & V_66 , V_64 , V_65 ) ;
F_19 ( & V_66 , V_69 [ V_67 ] . V_70 ) ;
V_69 [ V_67 ] . V_65 = V_65 ;
V_69 [ V_67 ] . time . V_9 = V_71 -> V_9 ;
V_69 [ V_67 ] . time . V_63 = V_71 -> V_63 ;
for ( V_40 = V_67 - 1 ; ; V_40 -- ) {
T_9 V_72 ;
int V_73 ;
if ( V_40 < 0 ) {
V_40 = V_68 - 1 ;
}
if ( V_40 == V_67 ) {
break;
}
if ( F_21 ( & ( V_69 [ V_40 ] . time ) ) ) {
break;
}
F_22 ( & V_72 , V_71 , & V_69 [ V_40 ] . time ) ;
if( V_72 . V_9 < 0 || V_72 . V_63 < 0 )
{
continue;
}
V_73 = F_23 ( & V_72 , & V_61 ) ;
if( V_73 > 0 ) {
break;
} else if ( V_69 [ V_40 ] . V_65 == V_69 [ V_67 ] . V_65 &&
memcmp ( V_69 [ V_40 ] . V_70 , V_69 [ V_67 ] . V_70 , 16 ) == 0 ) {
return TRUE ;
}
}
return FALSE ;
}
static void
F_24 ( T_3 V_74 )
{
T_10 * V_75 ;
if ( ! V_74 )
V_75 = stdout ;
else
V_75 = V_28 ;
fprintf ( V_75 , L_15
#ifdef F_25
L_16 F_25 L_17 V_76 L_18
#endif
L_19 , V_77 ) ;
fprintf ( V_75 , L_20 ) ;
fprintf ( V_75 , L_21 ) ;
fprintf ( V_75 , L_19 ) ;
fprintf ( V_75 , L_22 ) ;
fprintf ( V_75 , L_19 ) ;
fprintf ( V_75 , L_23 ) ;
fprintf ( V_75 , L_24 ) ;
fprintf ( V_75 , L_19 ) ;
fprintf ( V_75 , L_25 ) ;
fprintf ( V_75 , L_26 ) ;
fprintf ( V_75 , L_27 ) ;
fprintf ( V_75 , L_28 ) ;
fprintf ( V_75 , L_29 ) ;
fprintf ( V_75 , L_30 ) ;
fprintf ( V_75 , L_19 ) ;
fprintf ( V_75 , L_31 ) ;
fprintf ( V_75 , L_32 , V_78 ) ;
fprintf ( V_75 , L_33 ) ;
fprintf ( V_75 , L_34 , V_79 ) ;
fprintf ( V_75 , L_35 ) ;
fprintf ( V_75 , L_36 ) ;
fprintf ( V_75 , L_37 ) ;
fprintf ( V_75 , L_38 ) ;
fprintf ( V_75 , L_39 ) ;
fprintf ( V_75 , L_40 ) ;
fprintf ( V_75 , L_19 ) ;
fprintf ( V_75 , L_41 ) ;
fprintf ( V_75 , L_42 ) ;
fprintf ( V_75 , L_43 ) ;
fprintf ( V_75 , L_44 ) ;
fprintf ( V_75 , L_19 ) ;
fprintf ( V_75 , L_45 ) ;
fprintf ( V_75 , L_46 ) ;
fprintf ( V_75 , L_47 ) ;
fprintf ( V_75 , L_48 ) ;
fprintf ( V_75 , L_49 ) ;
fprintf ( V_75 , L_50 ) ;
fprintf ( V_75 , L_51 ) ;
fprintf ( V_75 , L_52 ) ;
fprintf ( V_75 , L_53 ) ;
fprintf ( V_75 , L_54 ) ;
fprintf ( V_75 , L_55 ) ;
fprintf ( V_75 , L_56 ) ;
fprintf ( V_75 , L_57 ) ;
fprintf ( V_75 , L_58 ) ;
fprintf ( V_75 , L_59 ) ;
fprintf ( V_75 , L_60 ) ;
fprintf ( V_75 , L_61 ) ;
fprintf ( V_75 , L_19 ) ;
fprintf ( V_75 , L_62 ) ;
fprintf ( V_75 , L_63 ) ;
fprintf ( V_75 , L_64 ) ;
fprintf ( V_75 , L_65 ) ;
fprintf ( V_75 , L_66 ) ;
fprintf ( V_75 , L_67 ) ;
fprintf ( V_75 , L_68 ) ;
fprintf ( V_75 , L_69 ) ;
fprintf ( V_75 , L_70 ) ;
fprintf ( V_75 , L_71 ) ;
fprintf ( V_75 , L_72 ) ;
fprintf ( V_75 , L_73 ) ;
fprintf ( V_75 , L_19 ) ;
fprintf ( V_75 , L_74 ) ;
fprintf ( V_75 , L_75 ) ;
fprintf ( V_75 , L_76 ) ;
fprintf ( V_75 , L_77 ) ;
fprintf ( V_75 , L_78 ) ;
fprintf ( V_75 , L_79 ) ;
fprintf ( V_75 , L_19 ) ;
}
static T_11
F_26 ( T_12 V_80 , T_12 V_81 )
{
return strcmp ( ( ( const struct V_82 * ) V_80 ) -> V_83 ,
( ( const struct V_82 * ) V_81 ) -> V_83 ) ;
}
static void
F_27 ( T_13 V_84 , T_13 T_14 V_85 )
{
fprintf ( V_28 , L_80 ,
( (struct V_82 * ) V_84 ) -> V_83 ,
( (struct V_82 * ) V_84 ) -> V_86 ) ;
}
static void
F_28 ( void ) {
int V_40 ;
struct V_82 * V_87 ;
T_15 * V_88 = NULL ;
V_87 = F_29 ( struct V_82 , V_89 ) ;
fprintf ( V_28 , L_81 ) ;
for ( V_40 = 0 ; V_40 < V_89 ; V_40 ++ ) {
if ( F_30 ( V_40 ) ) {
V_87 [ V_40 ] . V_83 = F_31 ( V_40 ) ;
V_87 [ V_40 ] . V_86 = F_32 ( V_40 ) ;
V_88 = F_33 ( V_88 , & V_87 [ V_40 ] , F_26 ) ;
}
}
F_34 ( V_88 , F_27 , NULL ) ;
F_35 ( V_88 ) ;
F_6 ( V_87 ) ;
}
static void
F_36 ( void ) {
int V_40 ;
struct V_82 * V_90 ;
T_15 * V_88 = NULL ;
V_90 = (struct V_82 * ) F_2 ( sizeof( struct V_82 ) * V_91 ) ;
fprintf ( V_28 , L_82 ) ;
for ( V_40 = 0 ; V_40 < V_91 ; V_40 ++ ) {
V_90 [ V_40 ] . V_83 = F_37 ( V_40 ) ;
if ( V_90 [ V_40 ] . V_83 != NULL ) {
V_90 [ V_40 ] . V_86 = F_38 ( V_40 ) ;
V_88 = F_33 ( V_88 , & V_90 [ V_40 ] , F_26 ) ;
}
}
F_34 ( V_88 , F_27 , NULL ) ;
F_35 ( V_88 ) ;
F_6 ( V_90 ) ;
}
static void
F_39 ( const char * T_16 V_85 , T_17 T_18 V_85 )
{
return;
}
int
main ( int V_92 , char * V_93 [] )
{
T_4 * V_41 ;
int V_40 , V_94 , V_95 ;
T_1 * V_96 ;
int V_97 ;
char * V_98 ;
T_7 V_99 = 0 ;
int V_100 = 0 ;
T_19 * V_101 = NULL ;
unsigned int V_102 = 1 ;
unsigned int V_103 = 0 ;
T_20 V_104 ;
struct V_42 V_105 ;
const struct V_42 * V_106 ;
int V_107 ;
T_21 * V_108 ;
T_22 * V_109 ;
T_6 * V_5 ;
T_7 V_110 = 0 ;
int V_111 = 0 ;
int V_112 = 0 ;
char * V_113 = NULL ;
T_3 V_114 = TRUE ;
int V_115 = 0 ;
int V_116 = 0 ;
T_9 V_117 ;
T_1 * V_18 = NULL ;
T_1 * V_19 = NULL ;
char V_118 [ 100 ] ;
#ifdef F_40
char * V_119 ;
#endif
#ifdef V_7
F_41 ( V_92 , V_93 ) ;
F_42 () ;
#endif
F_43 () ;
#ifdef F_40
if ( ( V_119 = F_44 ( V_93 [ 0 ] , main ) ) ) {
F_45 ( L_83 , V_119 ) ;
F_6 ( V_119 ) ;
} else {
F_46 ( F_39 , NULL , NULL , NULL ) ;
F_47 () ;
}
#endif
while ( ( V_97 = F_48 ( V_92 , V_93 , L_84 ) ) != - 1 ) {
switch ( V_97 ) {
case 'E' :
V_120 = strtod ( V_121 , & V_98 ) ;
if ( V_98 == V_121 || V_120 < 0.0 || V_120 > 1.0 ) {
fprintf ( V_28 , L_85 ,
V_121 ) ;
exit ( 1 ) ;
}
srand ( ( unsigned int ) ( time ( NULL ) + F_49 () ) ) ;
break;
case 'F' :
V_122 = F_50 ( V_121 ) ;
if ( V_122 < 0 ) {
fprintf ( V_28 , L_86 ,
V_121 ) ;
F_28 () ;
exit ( 1 ) ;
}
break;
case 'c' :
V_111 = ( int ) strtol ( V_121 , & V_98 , 10 ) ;
if ( V_98 == V_121 || * V_98 != '\0' ) {
fprintf ( V_28 , L_87 ,
V_121 ) ;
exit ( 1 ) ;
}
if ( V_111 <= 0 ) {
fprintf ( V_28 , L_88 ,
V_111 ) ;
exit ( 1 ) ;
}
break;
case 'C' :
V_100 = ( int ) strtol ( V_121 , & V_98 , 10 ) ;
if ( V_98 == V_121 || * V_98 != '\0' ) {
fprintf ( V_28 , L_89 ,
V_121 ) ;
exit ( 1 ) ;
}
break;
case 'd' :
V_123 = TRUE ;
V_124 = FALSE ;
V_68 = V_78 ;
break;
case 'D' :
V_123 = TRUE ;
V_124 = FALSE ;
V_68 = ( int ) strtol ( V_121 , & V_98 , 10 ) ;
if ( V_98 == V_121 || * V_98 != '\0' ) {
fprintf ( V_28 , L_90 ,
V_121 ) ;
exit ( 1 ) ;
}
if ( V_68 < 0 || V_68 > V_79 ) {
fprintf ( V_28 , L_91 ,
V_68 , V_79 ) ;
exit ( 1 ) ;
}
break;
case 'w' :
V_123 = FALSE ;
V_124 = TRUE ;
V_68 = V_79 ;
F_15 ( V_121 ) ;
break;
case '?' :
switch( V_125 ) {
case 'F' :
F_28 () ;
break;
case 'T' :
F_36 () ;
break;
default:
F_24 ( TRUE ) ;
}
exit ( 1 ) ;
break;
case 'h' :
F_24 ( FALSE ) ;
exit ( 1 ) ;
break;
case 'r' :
V_126 = ! V_126 ;
break;
case 's' :
V_99 = ( T_7 ) strtol ( V_121 , & V_98 , 10 ) ;
if ( V_98 == V_121 || * V_98 != '\0' ) {
fprintf ( V_28 , L_92 ,
V_121 ) ;
exit ( 1 ) ;
}
break;
case 't' :
F_13 ( V_121 ) ;
break;
case 'S' :
F_14 ( V_121 ) ;
V_127 = TRUE ;
break;
case 'T' :
V_128 = F_51 ( V_121 ) ;
if ( V_128 < 0 ) {
fprintf ( V_28 , L_93 ,
V_121 ) ;
F_36 () ;
exit ( 1 ) ;
}
break;
case 'v' :
V_129 = ! V_129 ;
break;
case 'i' :
V_115 = atoi ( V_121 ) ;
if( V_115 <= 0 ) {
fprintf ( V_28 , L_94 , V_121 ) ;
exit ( 1 ) ;
}
break;
case 'A' :
{
struct V_3 V_130 ;
memset ( & V_130 , 0 , sizeof( struct V_3 ) ) ;
if( ! strptime ( V_121 , L_95 , & V_130 ) ) {
fprintf ( V_28 , L_96 , V_121 ) ;
exit ( 1 ) ;
}
V_131 = TRUE ;
V_130 . V_132 = - 1 ;
V_45 = mktime ( & V_130 ) ;
break;
}
case 'B' :
{
struct V_3 V_133 ;
memset ( & V_133 , 0 , sizeof( struct V_3 ) ) ;
if( ! strptime ( V_121 , L_95 , & V_133 ) ) {
fprintf ( V_28 , L_96 , V_121 ) ;
exit ( 1 ) ;
}
V_131 = TRUE ;
V_133 . V_132 = - 1 ;
V_46 = mktime ( & V_133 ) ;
break;
}
}
}
#ifdef F_52
printf ( L_97 , V_134 , V_92 ) ;
#endif
if ( ( V_92 - V_134 ) < 1 ) {
F_24 ( TRUE ) ;
exit ( 1 ) ;
}
if ( V_131 && ! V_46 ) {
struct V_3 V_133 ;
memset ( & V_133 , 0 , sizeof( struct V_3 ) ) ;
V_133 . V_10 = 135 ;
V_133 . V_12 = 31 ;
V_133 . V_11 = 11 ;
V_46 = mktime ( & V_133 ) ;
}
F_53 ( & V_117 ) ;
if ( V_45 > V_46 ) {
fprintf ( V_28 , L_98 ) ;
exit ( 1 ) ;
}
if ( V_111 > 0 && V_115 > 0 ) {
fprintf ( V_28 , L_99 ) ;
fprintf ( V_28 , L_100 ) ;
exit ( 1 ) ;
}
V_41 = F_54 ( V_93 [ V_134 ] , & V_95 , & V_96 , FALSE ) ;
if ( ! V_41 ) {
fprintf ( V_28 , L_101 , V_93 [ V_134 ] ,
F_55 ( V_95 ) ) ;
switch ( V_95 ) {
case V_135 :
case V_136 :
case V_137 :
fprintf ( V_28 , L_102 , V_96 ) ;
F_6 ( V_96 ) ;
break;
}
exit ( 2 ) ;
}
if ( V_129 ) {
fprintf ( V_28 , L_103 , V_93 [ V_134 ] ,
F_32 ( F_56 ( V_41 ) ) ) ;
}
V_108 = F_57 ( V_41 ) ;
V_109 = F_58 ( V_41 ) ;
if ( ( V_92 - V_134 ) >= 2 ) {
if ( V_128 == - 2 )
V_128 = F_59 ( V_41 ) ;
for ( V_40 = V_134 + 2 ; V_40 < V_92 ; V_40 ++ )
if ( F_9 ( V_93 [ V_40 ] ) == FALSE )
break;
if ( V_123 || V_124 ) {
for ( V_40 = 0 ; V_40 < V_68 ; V_40 ++ ) {
memset ( & V_69 [ V_40 ] . V_70 , 0 , 16 ) ;
V_69 [ V_40 ] . V_65 = 0 ;
F_53 ( & V_69 [ V_40 ] . time ) ;
}
}
while ( F_60 ( V_41 , & V_95 , & V_96 , & V_104 ) ) {
V_110 ++ ;
V_106 = F_12 ( V_41 ) ;
V_5 = F_61 ( V_41 ) ;
if ( F_21 ( & V_117 ) ) {
V_117 . V_9 = V_106 -> V_44 . V_9 ;
V_117 . V_63 = V_106 -> V_44 . V_63 ;
if ( V_111 > 0 || V_115 > 0 ) {
if ( ! F_7 ( V_93 [ V_134 + 1 ] , & V_18 , & V_19 ) )
exit ( 2 ) ;
V_113 = F_4 ( V_116 ++ , & V_106 -> V_44 , V_18 , V_19 ) ;
} else
V_113 = F_8 ( V_93 [ V_134 + 1 ] ) ;
if( V_108 -> V_138 == NULL ) {
F_3 ( V_118 , sizeof( V_118 ) , L_104 V_77 ) ;
V_108 -> V_138 = V_118 ;
}
V_101 = F_62 ( V_113 , V_122 , V_128 ,
V_99 ? F_63 ( V_99 , F_64 ( V_41 ) ) : F_64 ( V_41 ) ,
FALSE , V_108 , V_109 , & V_95 ) ;
if ( V_101 == NULL ) {
fprintf ( V_28 , L_105 , V_113 ,
F_55 ( V_95 ) ) ;
exit ( 2 ) ;
}
}
F_65 ( V_113 ) ;
if ( V_115 > 0 ) {
while ( ( V_106 -> V_44 . V_9 - V_117 . V_9 > V_115 ) ||
( V_106 -> V_44 . V_9 - V_117 . V_9 == V_115 &&
V_106 -> V_44 . V_63 >= V_117 . V_63 ) ) {
if ( ! F_66 ( V_101 , & V_95 ) ) {
fprintf ( V_28 , L_106 , V_113 ,
F_55 ( V_95 ) ) ;
exit ( 2 ) ;
}
V_117 . V_9 = V_117 . V_9 + V_115 ;
F_6 ( V_113 ) ;
V_113 = F_4 ( V_116 ++ , & V_106 -> V_44 , V_18 , V_19 ) ;
F_65 ( V_113 ) ;
if ( V_129 ) {
fprintf ( V_28 , L_107 , V_113 ) ;
}
V_101 = F_62 ( V_113 , V_122 , V_128 ,
V_99 ? F_63 ( V_99 , F_64 ( V_41 ) ) : F_64 ( V_41 ) ,
FALSE , V_108 , V_109 , & V_95 ) ;
if ( V_101 == NULL ) {
fprintf ( V_28 , L_105 , V_113 ,
F_55 ( V_95 ) ) ;
exit ( 2 ) ;
}
}
}
if ( V_111 > 0 ) {
if ( V_112 > 0 &&
V_112 % V_111 == 0 ) {
if ( ! F_66 ( V_101 , & V_95 ) ) {
fprintf ( V_28 , L_106 , V_113 ,
F_55 ( V_95 ) ) ;
exit ( 2 ) ;
}
F_6 ( V_113 ) ;
V_113 = F_4 ( V_116 ++ , & V_106 -> V_44 , V_18 , V_19 ) ;
F_65 ( V_113 ) ;
if ( V_129 ) {
fprintf ( V_28 , L_107 , V_113 ) ;
}
V_101 = F_62 ( V_113 , V_122 , V_128 ,
V_99 ? F_63 ( V_99 , F_64 ( V_41 ) ) : F_64 ( V_41 ) ,
FALSE , V_108 , V_109 , & V_95 ) ;
if ( V_101 == NULL ) {
fprintf ( V_28 , L_105 , V_113 ,
F_55 ( V_95 ) ) ;
exit ( 2 ) ;
}
}
}
if ( V_131 )
V_114 = F_11 ( V_41 ) ;
if ( V_114 && ( ( ! F_10 ( V_102 ) && ! V_126 ) || ( F_10 ( V_102 ) && V_126 ) ) ) {
if ( V_129 && ! V_123 && ! V_124 )
printf ( L_108 , V_102 ) ;
V_106 = F_12 ( V_41 ) ;
if ( V_99 != 0 && V_106 -> V_139 > V_99 ) {
V_105 = * V_106 ;
V_105 . V_139 = V_99 ;
V_106 = & V_105 ;
}
if ( V_100 < 0 ) {
V_105 = * V_106 ;
if ( ( ( signed int ) V_106 -> V_139 + V_100 ) > 0 )
V_105 . V_139 += V_100 ;
else
V_105 . V_139 = 0 ;
V_106 = & V_105 ;
} else if ( V_100 > 0 ) {
V_105 = * V_106 ;
if ( V_106 -> V_139 > ( unsigned int ) V_100 ) {
V_105 . V_139 -= V_100 ;
V_5 += V_100 ;
} else
V_105 . V_139 = 0 ;
V_106 = & V_105 ;
}
if ( V_127 ) {
if ( V_140 . V_9 || V_140 . V_63 ) {
if ( ! V_60 . V_53 ) {
T_9 V_71 ;
T_9 V_72 ;
V_71 . V_9 = V_106 -> V_44 . V_9 ;
V_71 . V_63 = V_106 -> V_44 . V_63 ;
F_22 ( & V_72 , & V_71 , & V_140 ) ;
if ( V_72 . V_9 < 0 || V_72 . V_63 < 0 )
{
V_105 = * V_106 ;
V_105 . V_44 . V_9 = V_140 . V_9 + V_60 . V_56 . V_57 ;
V_105 . V_44 . V_63 = V_140 . V_63 ;
if ( V_105 . V_44 . V_63 + V_60 . V_56 . V_59 * 1000 > V_58 * 1000 ) {
V_105 . V_44 . V_9 ++ ;
V_105 . V_44 . V_63 += ( V_60 . V_56 . V_59 - V_58 ) * 1000 ;
} else {
V_105 . V_44 . V_63 += V_60 . V_56 . V_59 * 1000 ;
}
V_106 = & V_105 ;
}
} else {
V_105 = * V_106 ;
V_105 . V_44 . V_9 = V_140 . V_9 + V_60 . V_56 . V_57 ;
V_105 . V_44 . V_63 = V_140 . V_63 ;
if ( V_105 . V_44 . V_63 + V_60 . V_56 . V_59 * 1000 > V_58 * 1000 ) {
V_105 . V_44 . V_9 ++ ;
V_105 . V_44 . V_63 += ( V_60 . V_56 . V_59 - V_58 ) * 1000 ;
} else {
V_105 . V_44 . V_63 += V_60 . V_56 . V_59 * 1000 ;
}
V_106 = & V_105 ;
}
}
V_140 . V_9 = V_106 -> V_44 . V_9 ;
V_140 . V_63 = V_106 -> V_44 . V_63 ;
}
if ( V_106 -> V_44 . V_9 > 0 && V_52 . V_56 . V_57 != 0 ) {
V_105 = * V_106 ;
if ( V_52 . V_53 )
V_105 . V_44 . V_9 -= V_52 . V_56 . V_57 ;
else
V_105 . V_44 . V_9 += V_52 . V_56 . V_57 ;
V_106 = & V_105 ;
}
if ( V_106 -> V_44 . V_9 > 0 && V_52 . V_56 . V_59 != 0 ) {
V_105 = * V_106 ;
if ( V_52 . V_53 ) {
if ( V_105 . V_44 . V_63 / 1000 < V_52 . V_56 . V_59 ) {
V_105 . V_44 . V_9 -- ;
V_105 . V_44 . V_63 += V_58 * 1000 ;
}
V_105 . V_44 . V_63 -= V_52 . V_56 . V_59 * 1000 ;
} else {
if ( V_105 . V_44 . V_63 + V_52 . V_56 . V_59 * 1000 > V_58 * 1000 ) {
V_105 . V_44 . V_9 ++ ;
V_105 . V_44 . V_63 += ( V_52 . V_56 . V_59 - V_58 ) * 1000 ;
} else {
V_105 . V_44 . V_63 += V_52 . V_56 . V_59 * 1000 ;
}
}
V_106 = & V_105 ;
}
if ( V_123 ) {
if ( F_16 ( V_5 , V_106 -> V_139 ) ) {
if ( V_129 ) {
fprintf ( stdout , L_109 , V_102 , V_106 -> V_139 ) ;
for ( V_40 = 0 ; V_40 < 16 ; V_40 ++ ) {
fprintf ( stdout , L_110 , ( unsigned char ) V_69 [ V_67 ] . V_70 [ V_40 ] ) ;
}
fprintf ( stdout , L_19 ) ;
}
V_103 ++ ;
V_102 ++ ;
continue;
} else {
if ( V_129 ) {
fprintf ( stdout , L_111 , V_102 , V_106 -> V_139 ) ;
for ( V_40 = 0 ; V_40 < 16 ; V_40 ++ ) {
fprintf ( stdout , L_110 , ( unsigned char ) V_69 [ V_67 ] . V_70 [ V_40 ] ) ;
}
fprintf ( stdout , L_19 ) ;
}
}
}
if ( V_124 ) {
T_9 V_71 ;
V_71 . V_9 = V_106 -> V_44 . V_9 ;
V_71 . V_63 = V_106 -> V_44 . V_63 ;
if ( F_20 ( V_5 , V_106 -> V_139 , & V_71 ) ) {
if ( V_129 ) {
fprintf ( stdout , L_109 , V_102 , V_106 -> V_139 ) ;
for ( V_40 = 0 ; V_40 < 16 ; V_40 ++ ) {
fprintf ( stdout , L_110 , ( unsigned char ) V_69 [ V_67 ] . V_70 [ V_40 ] ) ;
}
fprintf ( stdout , L_19 ) ;
}
V_103 ++ ;
V_102 ++ ;
continue;
} else {
if ( V_129 ) {
fprintf ( stdout , L_111 , V_102 , V_106 -> V_139 ) ;
for ( V_40 = 0 ; V_40 < 16 ; V_40 ++ ) {
fprintf ( stdout , L_110 , ( unsigned char ) V_69 [ V_67 ] . V_70 [ V_40 ] ) ;
}
fprintf ( stdout , L_19 ) ;
}
}
}
if ( V_120 > 0.0 ) {
int V_141 = 0 ;
if ( F_56 ( V_41 ) == V_142 ) {
V_141 = F_67 ( V_5 ) ;
}
for ( V_40 = V_141 ; V_40 < ( int ) V_106 -> V_139 ; V_40 ++ ) {
if ( rand () <= V_120 * V_143 ) {
V_107 = rand () / ( V_143 / V_144 + 1 ) ;
if ( V_107 < V_145 ) {
V_5 [ V_40 ] ^= 1 << ( rand () / ( V_143 / 8 + 1 ) ) ;
V_107 = V_144 ;
} else {
V_107 -= V_146 ;
}
if ( V_107 < V_146 ) {
V_5 [ V_40 ] = rand () / ( V_143 / 255 + 1 ) ;
V_107 = V_144 ;
} else {
V_107 -= V_146 ;
}
if ( V_107 < V_147 ) {
V_5 [ V_40 ] = V_148 [ rand () / ( V_143 / V_149 + 1 ) ] ;
V_107 = V_144 ;
} else {
V_107 -= V_147 ;
}
if ( V_107 < V_150 ) {
if ( ( unsigned int ) V_40 < V_106 -> V_139 - 2 )
F_68 ( ( char * ) & V_5 [ V_40 ] , L_112 , 2 ) ;
V_107 = V_144 ;
} else {
V_107 -= V_150 ;
}
if ( V_107 < V_151 ) {
for ( V_94 = V_40 ; V_94 < ( int ) V_106 -> V_139 ; V_94 ++ ) {
V_5 [ V_94 ] = 0xAA ;
}
V_40 = V_106 -> V_139 ;
}
}
}
}
if ( ! F_69 ( V_101 , V_106 , V_5 , & V_95 ) ) {
switch ( V_95 ) {
case V_136 :
fprintf ( V_28 , L_113 ,
V_110 , V_93 [ V_134 ] ) ;
break;
default:
fprintf ( V_28 , L_106 ,
V_113 , F_55 ( V_95 ) ) ;
break;
}
exit ( 2 ) ;
}
V_112 ++ ;
}
V_102 ++ ;
}
F_6 ( V_18 ) ;
F_6 ( V_19 ) ;
if ( V_95 != 0 ) {
fprintf ( V_28 ,
L_114 ,
V_93 [ V_134 ] , F_55 ( V_95 ) ) ;
switch ( V_95 ) {
case V_135 :
case V_136 :
case V_137 :
fprintf ( V_28 , L_102 , V_96 ) ;
F_6 ( V_96 ) ;
break;
}
}
if ( ! V_101 ) {
F_6 ( V_113 ) ;
V_113 = F_8 ( V_93 [ V_134 + 1 ] ) ;
V_101 = F_62 ( V_113 , V_122 , V_128 ,
V_99 ? F_63 ( V_99 , F_64 ( V_41 ) ) : F_64 ( V_41 ) ,
FALSE , V_108 , V_109 , & V_95 ) ;
if ( V_101 == NULL ) {
fprintf ( V_28 , L_105 , V_113 ,
F_55 ( V_95 ) ) ;
exit ( 2 ) ;
}
}
F_6 ( V_109 ) ;
V_109 = NULL ;
if ( ! F_66 ( V_101 , & V_95 ) ) {
fprintf ( V_28 , L_106 , V_113 ,
F_55 ( V_95 ) ) ;
exit ( 2 ) ;
}
F_6 ( V_108 ) ;
F_6 ( V_113 ) ;
}
if ( V_123 ) {
fprintf ( stdout , L_115 ,
V_102 - 1 , F_70 ( V_102 - 1 , L_116 , L_117 ) ,
V_103 , F_70 ( V_103 , L_116 , L_117 ) , V_68 ) ;
} else if ( V_124 ) {
fprintf ( stdout , L_118 ,
V_102 - 1 , F_70 ( V_102 - 1 , L_116 , L_117 ) ,
V_103 , F_70 ( V_103 , L_116 , L_117 ) ,
( long ) V_61 . V_9 , ( long int ) V_61 . V_63 ) ;
}
return 0 ;
}
static int F_67 ( T_6 * V_5 )
{
int V_152 = 0 ;
for ( V_152 = 0 ; V_5 [ V_152 ] != '\0' ; V_152 ++ ) ;
V_152 ++ ;
V_152 ++ ;
for (; V_5 [ V_152 ] != '\0' ; V_152 ++ ) ;
V_152 ++ ;
for (; V_5 [ V_152 ] != '\0' ; V_152 ++ ) ;
V_152 ++ ;
for (; V_5 [ V_152 ] != '\0' ; V_152 ++ ) ;
V_152 ++ ;
for (; V_5 [ V_152 ] != '\0' ; V_152 ++ ) ;
V_152 ++ ;
V_152 += 2 ;
return V_152 ;
}
