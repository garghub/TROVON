static T_1 *
F_1 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 * V_5 = ( T_1 * ) F_2 ( 16 ) ;
#if ( V_6 V_7 ) && ( V_8 < 1500 )
if ( V_2 -> V_9 > 2000000000 )
V_4 = NULL ;
else
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
} else {
V_5 [ 0 ] = '\0' ;
}
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
} else {
printf ( L_9 ) ;
V_32 = V_31 + 1 ;
V_35 [ V_33 ] . V_36 = 1 ;
V_35 [ V_33 ] . V_37 = atoi ( V_30 ) ;
V_35 [ V_33 ] . V_38 = atoi ( V_32 ) ;
printf ( L_10 , V_35 [ V_33 ] . V_37 ,
V_35 [ V_33 ] . V_38 ) ;
}
return ( TRUE ) ;
}
static int
F_10 ( int V_39 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 <= V_33 ; V_40 ++ ) {
if ( V_35 [ V_40 ] . V_36 ) {
if ( V_35 [ V_40 ] . V_37 <= V_39 && V_35 [ V_40 ] . V_38 >= V_39 )
return 1 ;
} else {
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
while ( * V_47 == ' ' || * V_47 == '\t' )
V_47 ++ ;
if ( * V_47 == '-' ) {
V_52 . V_53 = 1 ;
V_47 ++ ;
}
if ( * V_47 == '.' ) {
V_50 = 0 ;
V_48 = V_47 ;
} else {
V_50 = strtol ( V_47 , & V_48 , 10 ) ;
if ( V_48 == NULL || V_48 == V_47
|| V_50 == V_54 || V_50 == V_55 ) {
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
if ( ( V_49 - & ( V_48 [ 1 ] ) ) > 6 ) {
V_48 [ 7 ] = 't' ;
V_50 = strtol ( & ( V_48 [ 1 ] ) , & V_49 , 10 ) ;
}
if ( * V_48 != '.' || V_49 == NULL || V_49 == V_48 || V_50 < 0
|| V_50 > V_58 || V_50 == V_54 || V_50 == V_55 ) {
fprintf ( V_28 , L_11 ,
V_47 ) ;
exit ( 1 ) ;
}
} else {
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
while ( * V_47 == ' ' || * V_47 == '\t' )
V_47 ++ ;
if ( * V_47 == '-' ) {
V_60 . V_53 = 1 ;
V_47 ++ ;
}
if ( * V_47 == '.' ) {
V_50 = 0 ;
V_48 = V_47 ;
} else {
V_50 = strtol ( V_47 , & V_48 , 10 ) ;
if ( V_48 == NULL || V_48 == V_47
|| V_50 == V_54 || V_50 == V_55 ) {
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
if ( ( V_49 - & ( V_48 [ 1 ] ) ) > 6 ) {
V_48 [ 7 ] = 't' ;
V_50 = strtol ( & ( V_48 [ 1 ] ) , & V_49 , 10 ) ;
}
if ( * V_48 != '.' || V_49 == NULL || V_49 == V_48 || V_50 < 0
|| V_50 > V_58 || V_50 == V_54 || V_50 == V_55 ) {
fprintf ( V_28 , L_11 ,
V_47 ) ;
exit ( 1 ) ;
}
} else {
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
while ( * V_47 == ' ' || * V_47 == '\t' )
V_47 ++ ;
if ( * V_47 == '-' )
V_47 ++ ;
if ( * V_47 == '.' ) {
V_50 = 0 ;
V_48 = V_47 ;
} else {
V_50 = strtol ( V_47 , & V_48 , 10 ) ;
if ( V_48 == NULL || V_48 == V_47
|| V_50 == V_54 || V_50 == V_55 ) {
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
if ( ( V_49 - & ( V_48 [ 1 ] ) ) > 9 ) {
V_48 [ 10 ] = 't' ;
V_50 = strtol ( & ( V_48 [ 1 ] ) , & V_49 , 10 ) ;
}
if ( * V_48 != '.' || V_49 == NULL || V_49 == V_48 || V_50 < 0
|| V_50 > V_62 || V_50 == V_54 || V_50 == V_55 ) {
fprintf ( V_28 , L_14 ,
V_47 ) ;
exit ( 1 ) ;
}
} else {
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
if ( V_69 [ V_40 ] . V_65 == V_69 [ V_67 ] . V_65
&& memcmp ( V_69 [ V_40 ] . V_70 , V_69 [ V_67 ] . V_70 , 16 ) == 0 ) {
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
if ( V_40 < 0 )
V_40 = V_68 - 1 ;
if ( V_40 == V_67 ) {
break;
}
if ( F_21 ( & ( V_69 [ V_40 ] . time ) ) ) {
break;
}
F_22 ( & V_72 , V_71 , & V_69 [ V_40 ] . time ) ;
if ( V_72 . V_9 < 0 || V_72 . V_63 < 0 ) {
continue;
}
V_73 = F_23 ( & V_72 , & V_61 ) ;
if ( V_73 > 0 ) {
break;
} else if ( V_69 [ V_40 ] . V_65 == V_69 [ V_67 ] . V_65
&& memcmp ( V_69 [ V_40 ] . V_70 , V_69 [ V_67 ] . V_70 , 16 ) == 0 ) {
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
fprintf ( V_75 , L_62 ) ;
fprintf ( V_75 , L_63 ) ;
fprintf ( V_75 , L_64 ) ;
fprintf ( V_75 , L_65 ) ;
fprintf ( V_75 , L_66 ) ;
fprintf ( V_75 , L_67 ) ;
fprintf ( V_75 , L_68 ) ;
fprintf ( V_75 , L_19 ) ;
fprintf ( V_75 , L_69 ) ;
fprintf ( V_75 , L_70 ) ;
fprintf ( V_75 , L_71 ) ;
fprintf ( V_75 , L_72 ) ;
fprintf ( V_75 , L_73 ) ;
fprintf ( V_75 , L_74 ) ;
fprintf ( V_75 , L_75 ) ;
fprintf ( V_75 , L_76 ) ;
fprintf ( V_75 , L_77 ) ;
fprintf ( V_75 , L_78 ) ;
fprintf ( V_75 , L_79 ) ;
fprintf ( V_75 , L_80 ) ;
fprintf ( V_75 , L_19 ) ;
fprintf ( V_75 , L_81 ) ;
fprintf ( V_75 , L_82 ) ;
fprintf ( V_75 , L_83 ) ;
fprintf ( V_75 , L_84 ) ;
fprintf ( V_75 , L_85 ) ;
fprintf ( V_75 , L_86 ) ;
fprintf ( V_75 , L_19 ) ;
}
static T_11
F_26 ( T_12 V_80 , T_12 V_81 )
{
return strcmp ( ( ( const struct V_82 * ) V_80 ) -> V_83 ,
( ( const struct V_82 * ) V_81 ) -> V_83 ) ;
}
static T_11
F_27 ( T_12 V_80 , T_12 V_81 )
{
return F_28 ( ( ( const struct V_82 * ) V_80 ) -> V_83 ,
( ( const struct V_82 * ) V_81 ) -> V_83 ) ;
}
static void
F_29 ( T_13 V_84 , T_13 T_14 V_85 )
{
fprintf ( V_28 , L_87 ,
( (struct V_82 * ) V_84 ) -> V_83 ,
( (struct V_82 * ) V_84 ) -> V_86 ) ;
}
static void
F_30 ( void ) {
int V_40 ;
struct V_82 * V_87 ;
T_15 * V_88 = NULL ;
V_87 = F_31 ( struct V_82 , V_89 ) ;
fprintf ( V_28 , L_88 ) ;
for ( V_40 = 0 ; V_40 < V_89 ; V_40 ++ ) {
if ( F_32 ( V_40 ) ) {
V_87 [ V_40 ] . V_83 = F_33 ( V_40 ) ;
V_87 [ V_40 ] . V_86 = F_34 ( V_40 ) ;
V_88 = F_35 ( V_88 , & V_87 [ V_40 ] , F_26 ) ;
}
}
F_36 ( V_88 , F_29 , NULL ) ;
F_37 ( V_88 ) ;
F_6 ( V_87 ) ;
}
static void
F_38 ( void ) {
int V_40 ;
struct V_82 * V_90 ;
T_15 * V_88 = NULL ;
V_90 = (struct V_82 * ) F_2 ( sizeof( struct V_82 ) * V_91 ) ;
fprintf ( V_28 , L_89 ) ;
for ( V_40 = 0 ; V_40 < V_91 ; V_40 ++ ) {
V_90 [ V_40 ] . V_83 = F_39 ( V_40 ) ;
if ( V_90 [ V_40 ] . V_83 != NULL ) {
V_90 [ V_40 ] . V_86 = F_40 ( V_40 ) ;
V_88 = F_35 ( V_88 , & V_90 [ V_40 ] , F_27 ) ;
}
}
F_36 ( V_88 , F_29 , NULL ) ;
F_37 ( V_88 ) ;
F_6 ( V_90 ) ;
}
static void
F_41 ( const char * T_16 V_85 , T_17 T_18 V_85 )
{
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
T_19 V_100 = { 0 , 0 , 0 , 0 , 0 , 0 } ;
T_3 V_101 = FALSE ;
T_20 * V_102 = NULL ;
unsigned int V_103 = 1 ;
unsigned int V_104 = 0 ;
T_21 V_105 ;
struct V_42 V_106 ;
const struct V_42 * V_107 ;
int V_108 ;
T_22 * V_109 ;
T_23 * V_110 ;
T_6 * V_5 ;
T_7 V_111 = 0 ;
int V_112 = 0 ;
int V_113 = 0 ;
char * V_114 = NULL ;
T_3 V_115 = TRUE ;
int V_116 = 0 ;
int V_117 = 0 ;
T_9 V_118 ;
T_1 * V_18 = NULL ;
T_1 * V_19 = NULL ;
char V_119 [ 100 ] ;
#ifdef F_42
char * V_120 ;
#endif
#ifdef V_7
F_43 ( V_92 , V_93 ) ;
F_44 () ;
#endif
F_45 () ;
#ifdef F_42
if ( ( V_120 = F_46 ( V_93 [ 0 ] , main ) ) ) {
F_47 ( L_90 , V_120 ) ;
F_6 ( V_120 ) ;
} else {
F_48 ( F_41 , NULL , NULL , NULL ) ;
F_49 () ;
}
#endif
while ( ( V_97 = F_50 ( V_92 , V_93 , L_91 ) ) != - 1 ) {
switch ( V_97 ) {
case 'A' :
{
struct V_3 V_121 ;
memset ( & V_121 , 0 , sizeof( struct V_3 ) ) ;
if ( ! strptime ( V_122 , L_92 , & V_121 ) ) {
fprintf ( V_28 , L_93 ,
V_122 ) ;
exit ( 1 ) ;
}
V_123 = TRUE ;
V_121 . V_124 = - 1 ;
V_45 = mktime ( & V_121 ) ;
break;
}
case 'B' :
{
struct V_3 V_125 ;
memset ( & V_125 , 0 , sizeof( struct V_3 ) ) ;
if ( ! strptime ( V_122 , L_92 , & V_125 ) ) {
fprintf ( V_28 , L_93 ,
V_122 ) ;
exit ( 1 ) ;
}
V_123 = TRUE ;
V_125 . V_124 = - 1 ;
V_46 = mktime ( & V_125 ) ;
break;
}
case 'c' :
V_112 = ( int ) strtol ( V_122 , & V_98 , 10 ) ;
if ( V_98 == V_122 || * V_98 != '\0' ) {
fprintf ( V_28 , L_94 ,
V_122 ) ;
exit ( 1 ) ;
}
if ( V_112 <= 0 ) {
fprintf ( V_28 , L_95 ,
V_112 ) ;
exit ( 1 ) ;
}
break;
case 'C' :
{
int V_126 = 0 , V_127 = 0 ;
switch ( sscanf ( V_122 , L_96 , & V_127 , & V_126 ) ) {
case 1 :
V_126 = V_127 ;
V_127 = 0 ;
break;
case 2 :
break;
default:
fprintf ( V_28 , L_97 ,
V_122 ) ;
exit ( 1 ) ;
break;
}
if ( V_126 > 0 ) {
V_100 . V_128 += V_126 ;
if ( V_127 > 0 )
V_100 . V_129 += V_127 ;
else
V_100 . V_130 += V_127 ;
} else if ( V_126 < 0 ) {
V_100 . V_131 += V_126 ;
if ( V_127 > 0 )
V_100 . V_132 += V_127 ;
else
V_100 . V_133 += V_127 ;
}
break;
}
case 'd' :
V_134 = TRUE ;
V_135 = FALSE ;
V_68 = V_78 ;
break;
case 'D' :
V_134 = TRUE ;
V_135 = FALSE ;
V_68 = ( int ) strtol ( V_122 , & V_98 , 10 ) ;
if ( V_98 == V_122 || * V_98 != '\0' ) {
fprintf ( V_28 , L_98 ,
V_122 ) ;
exit ( 1 ) ;
}
if ( V_68 < 0 || V_68 > V_79 ) {
fprintf ( V_28 , L_99 ,
V_68 , V_79 ) ;
exit ( 1 ) ;
}
break;
case 'E' :
V_136 = strtod ( V_122 , & V_98 ) ;
if ( V_98 == V_122 || V_136 < 0.0 || V_136 > 1.0 ) {
fprintf ( V_28 , L_100 ,
V_122 ) ;
exit ( 1 ) ;
}
srand ( ( unsigned int ) ( time ( NULL ) + F_51 () ) ) ;
break;
case 'F' :
V_137 = F_52 ( V_122 ) ;
if ( V_137 < 0 ) {
fprintf ( V_28 , L_101 ,
V_122 ) ;
F_30 () ;
exit ( 1 ) ;
}
break;
case 'h' :
F_24 ( FALSE ) ;
exit ( 1 ) ;
break;
case 'i' :
V_116 = atoi ( V_122 ) ;
if ( V_116 <= 0 ) {
fprintf ( V_28 , L_102 ,
V_122 ) ;
exit ( 1 ) ;
}
break;
case 'L' :
V_101 = TRUE ;
break;
case 'r' :
V_138 = ! V_138 ;
break;
case 's' :
V_99 = ( T_7 ) strtol ( V_122 , & V_98 , 10 ) ;
if ( V_98 == V_122 || * V_98 != '\0' ) {
fprintf ( V_28 , L_103 ,
V_122 ) ;
exit ( 1 ) ;
}
break;
case 'S' :
F_14 ( V_122 ) ;
V_139 = TRUE ;
break;
case 't' :
F_13 ( V_122 ) ;
break;
case 'T' :
V_140 = F_53 ( V_122 ) ;
if ( V_140 < 0 ) {
fprintf ( V_28 , L_104 ,
V_122 ) ;
F_38 () ;
exit ( 1 ) ;
}
break;
case 'v' :
V_141 = ! V_141 ;
break;
case 'w' :
V_134 = FALSE ;
V_135 = TRUE ;
V_68 = V_79 ;
F_15 ( V_122 ) ;
break;
case '?' :
switch( V_142 ) {
case 'F' :
F_30 () ;
break;
case 'T' :
F_38 () ;
break;
default:
F_24 ( TRUE ) ;
break;
}
exit ( 1 ) ;
break;
}
}
#ifdef F_54
printf ( L_105 , V_143 , V_92 ) ;
#endif
if ( ( V_92 - V_143 ) < 1 ) {
F_24 ( TRUE ) ;
exit ( 1 ) ;
}
if ( V_123 && ! V_46 ) {
struct V_3 V_125 ;
memset ( & V_125 , 0 , sizeof( struct V_3 ) ) ;
V_125 . V_10 = 135 ;
V_125 . V_12 = 31 ;
V_125 . V_11 = 11 ;
V_46 = mktime ( & V_125 ) ;
}
F_55 ( & V_118 ) ;
if ( V_45 > V_46 ) {
fprintf ( V_28 , L_106 ) ;
exit ( 1 ) ;
}
if ( V_112 > 0 && V_116 > 0 ) {
fprintf ( V_28 , L_107 ) ;
fprintf ( V_28 , L_108 ) ;
exit ( 1 ) ;
}
V_41 = F_56 ( V_93 [ V_143 ] , & V_95 , & V_96 , FALSE ) ;
if ( ! V_41 ) {
fprintf ( V_28 , L_109 , V_93 [ V_143 ] ,
F_57 ( V_95 ) ) ;
switch ( V_95 ) {
case V_144 :
case V_145 :
case V_146 :
fprintf ( V_28 , L_110 , V_96 ) ;
F_6 ( V_96 ) ;
break;
}
exit ( 2 ) ;
}
if ( V_141 ) {
fprintf ( V_28 , L_111 , V_93 [ V_143 ] ,
F_34 ( F_58 ( V_41 ) ) ) ;
}
V_109 = F_59 ( V_41 ) ;
V_110 = F_60 ( V_41 ) ;
if ( ( V_92 - V_143 ) >= 2 ) {
if ( V_140 == - 2 )
V_140 = F_61 ( V_41 ) ;
for ( V_40 = V_143 + 2 ; V_40 < V_92 ; V_40 ++ )
if ( F_9 ( V_93 [ V_40 ] ) == FALSE )
break;
if ( V_134 || V_135 ) {
for ( V_40 = 0 ; V_40 < V_68 ; V_40 ++ ) {
memset ( & V_69 [ V_40 ] . V_70 , 0 , 16 ) ;
V_69 [ V_40 ] . V_65 = 0 ;
F_55 ( & V_69 [ V_40 ] . time ) ;
}
}
while ( F_62 ( V_41 , & V_95 , & V_96 , & V_105 ) ) {
V_111 ++ ;
V_107 = F_12 ( V_41 ) ;
V_5 = F_63 ( V_41 ) ;
if ( F_21 ( & V_118 ) ) {
V_118 . V_9 = V_107 -> V_44 . V_9 ;
V_118 . V_63 = V_107 -> V_44 . V_63 ;
if ( V_112 > 0 || V_116 > 0 ) {
if ( ! F_7 ( V_93 [ V_143 + 1 ] , & V_18 , & V_19 ) )
exit ( 2 ) ;
V_114 = F_4 ( V_117 ++ , & V_107 -> V_44 , V_18 , V_19 ) ;
} else {
V_114 = F_8 ( V_93 [ V_143 + 1 ] ) ;
}
if ( V_109 -> V_147 == NULL ) {
F_3 ( V_119 , sizeof( V_119 ) , L_112 V_77 ) ;
V_109 -> V_147 = V_119 ;
}
V_102 = F_64 ( V_114 , V_137 , V_140 ,
V_99 ? F_65 ( V_99 , F_66 ( V_41 ) ) : F_66 ( V_41 ) ,
FALSE , V_109 , V_110 , & V_95 ) ;
if ( V_102 == NULL ) {
fprintf ( V_28 , L_113 ,
V_114 , F_57 ( V_95 ) ) ;
exit ( 2 ) ;
}
}
F_67 ( V_114 ) ;
if ( V_116 > 0 ) {
while ( ( V_107 -> V_44 . V_9 - V_118 . V_9 > V_116 )
|| ( V_107 -> V_44 . V_9 - V_118 . V_9 == V_116
&& V_107 -> V_44 . V_63 >= V_118 . V_63 ) ) {
if ( ! F_68 ( V_102 , & V_95 ) ) {
fprintf ( V_28 , L_114 ,
V_114 , F_57 ( V_95 ) ) ;
exit ( 2 ) ;
}
V_118 . V_9 = V_118 . V_9 + V_116 ;
F_6 ( V_114 ) ;
V_114 = F_4 ( V_117 ++ , & V_107 -> V_44 , V_18 , V_19 ) ;
F_67 ( V_114 ) ;
if ( V_141 )
fprintf ( V_28 , L_115 , V_114 ) ;
V_102 = F_64 ( V_114 , V_137 , V_140 ,
V_99 ? F_65 ( V_99 , F_66 ( V_41 ) ) : F_66 ( V_41 ) ,
FALSE , V_109 , V_110 , & V_95 ) ;
if ( V_102 == NULL ) {
fprintf ( V_28 , L_113 ,
V_114 , F_57 ( V_95 ) ) ;
exit ( 2 ) ;
}
}
}
if ( V_112 > 0 ) {
if ( V_113 > 0 && V_113 % V_112 == 0 ) {
if ( ! F_68 ( V_102 , & V_95 ) ) {
fprintf ( V_28 , L_114 ,
V_114 , F_57 ( V_95 ) ) ;
exit ( 2 ) ;
}
F_6 ( V_114 ) ;
V_114 = F_4 ( V_117 ++ , & V_107 -> V_44 , V_18 , V_19 ) ;
F_67 ( V_114 ) ;
if ( V_141 )
fprintf ( V_28 , L_115 , V_114 ) ;
V_102 = F_64 ( V_114 , V_137 , V_140 ,
V_99 ? F_65 ( V_99 , F_66 ( V_41 ) ) : F_66 ( V_41 ) ,
FALSE , V_109 , V_110 , & V_95 ) ;
if ( V_102 == NULL ) {
fprintf ( V_28 , L_113 ,
V_114 , F_57 ( V_95 ) ) ;
exit ( 2 ) ;
}
}
}
if ( V_123 )
V_115 = F_11 ( V_41 ) ;
if ( V_115 && ( ( ! F_10 ( V_103 ) && ! V_138 )
|| ( F_10 ( V_103 ) && V_138 ) ) ) {
if ( V_141 && ! V_134 && ! V_135 )
printf ( L_116 , V_103 ) ;
V_107 = F_12 ( V_41 ) ;
if ( V_99 != 0 ) {
if ( V_107 -> V_148 > V_99 ) {
V_106 = * V_107 ;
V_106 . V_148 = V_99 ;
V_107 = & V_106 ;
}
if ( V_101 && V_107 -> V_65 > V_99 ) {
V_106 = * V_107 ;
V_106 . V_65 = V_99 ;
V_107 = & V_106 ;
}
}
V_106 = * V_107 ;
F_69 ( V_100 , & V_106 , V_107 , V_5 , V_101 ) ;
V_107 = & V_106 ;
if ( V_139 ) {
if ( V_149 . V_9 || V_149 . V_63 ) {
if ( ! V_60 . V_53 ) {
T_9 V_71 ;
T_9 V_72 ;
V_71 . V_9 = V_107 -> V_44 . V_9 ;
V_71 . V_63 = V_107 -> V_44 . V_63 ;
F_22 ( & V_72 , & V_71 , & V_149 ) ;
if ( V_72 . V_9 < 0 || V_72 . V_63 < 0 ) {
V_106 = * V_107 ;
V_106 . V_44 . V_9 = V_149 . V_9 + V_60 . V_56 . V_57 ;
V_106 . V_44 . V_63 = V_149 . V_63 ;
if ( V_106 . V_44 . V_63 + V_60 . V_56 . V_59 * 1000 > V_58 * 1000 ) {
V_106 . V_44 . V_9 ++ ;
V_106 . V_44 . V_63 += ( V_60 . V_56 . V_59 - V_58 ) * 1000 ;
} else {
V_106 . V_44 . V_63 += V_60 . V_56 . V_59 * 1000 ;
}
V_107 = & V_106 ;
}
} else {
V_106 = * V_107 ;
V_106 . V_44 . V_9 = V_149 . V_9 + V_60 . V_56 . V_57 ;
V_106 . V_44 . V_63 = V_149 . V_63 ;
if ( V_106 . V_44 . V_63 + V_60 . V_56 . V_59 * 1000 > V_58 * 1000 ) {
V_106 . V_44 . V_9 ++ ;
V_106 . V_44 . V_63 += ( V_60 . V_56 . V_59 - V_58 ) * 1000 ;
} else {
V_106 . V_44 . V_63 += V_60 . V_56 . V_59 * 1000 ;
}
V_107 = & V_106 ;
}
}
V_149 . V_9 = V_107 -> V_44 . V_9 ;
V_149 . V_63 = V_107 -> V_44 . V_63 ;
}
if ( V_107 -> V_44 . V_9 > 0 && V_52 . V_56 . V_57 != 0 ) {
V_106 = * V_107 ;
if ( V_52 . V_53 )
V_106 . V_44 . V_9 -= V_52 . V_56 . V_57 ;
else
V_106 . V_44 . V_9 += V_52 . V_56 . V_57 ;
V_107 = & V_106 ;
}
if ( V_107 -> V_44 . V_9 > 0 && V_52 . V_56 . V_59 != 0 ) {
V_106 = * V_107 ;
if ( V_52 . V_53 ) {
if ( V_106 . V_44 . V_63 / 1000 < V_52 . V_56 . V_59 ) {
V_106 . V_44 . V_9 -- ;
V_106 . V_44 . V_63 += V_58 * 1000 ;
}
V_106 . V_44 . V_63 -= V_52 . V_56 . V_59 * 1000 ;
} else {
if ( V_106 . V_44 . V_63 + V_52 . V_56 . V_59 * 1000 > V_58 * 1000 ) {
V_106 . V_44 . V_9 ++ ;
V_106 . V_44 . V_63 += ( V_52 . V_56 . V_59 - V_58 ) * 1000 ;
} else {
V_106 . V_44 . V_63 += V_52 . V_56 . V_59 * 1000 ;
}
}
V_107 = & V_106 ;
}
if ( V_134 ) {
if ( F_16 ( V_5 , V_107 -> V_148 ) ) {
if ( V_141 ) {
fprintf ( stdout , L_117 ,
V_103 , V_107 -> V_148 ) ;
for ( V_40 = 0 ; V_40 < 16 ; V_40 ++ )
fprintf ( stdout , L_118 ,
( unsigned char ) V_69 [ V_67 ] . V_70 [ V_40 ] ) ;
fprintf ( stdout , L_19 ) ;
}
V_104 ++ ;
V_103 ++ ;
continue;
} else {
if ( V_141 ) {
fprintf ( stdout , L_119 ,
V_103 , V_107 -> V_148 ) ;
for ( V_40 = 0 ; V_40 < 16 ; V_40 ++ )
fprintf ( stdout , L_118 ,
( unsigned char ) V_69 [ V_67 ] . V_70 [ V_40 ] ) ;
fprintf ( stdout , L_19 ) ;
}
}
}
if ( V_135 ) {
T_9 V_71 ;
V_71 . V_9 = V_107 -> V_44 . V_9 ;
V_71 . V_63 = V_107 -> V_44 . V_63 ;
if ( F_20 ( V_5 , V_107 -> V_148 , & V_71 ) ) {
if ( V_141 ) {
fprintf ( stdout , L_117 ,
V_103 , V_107 -> V_148 ) ;
for ( V_40 = 0 ; V_40 < 16 ; V_40 ++ )
fprintf ( stdout , L_118 ,
( unsigned char ) V_69 [ V_67 ] . V_70 [ V_40 ] ) ;
fprintf ( stdout , L_19 ) ;
}
V_104 ++ ;
V_103 ++ ;
continue;
} else {
if ( V_141 ) {
fprintf ( stdout , L_119 ,
V_103 , V_107 -> V_148 ) ;
for ( V_40 = 0 ; V_40 < 16 ; V_40 ++ )
fprintf ( stdout , L_118 ,
( unsigned char ) V_69 [ V_67 ] . V_70 [ V_40 ] ) ;
fprintf ( stdout , L_19 ) ;
}
}
}
if ( V_136 > 0.0 ) {
int V_150 = 0 ;
if ( F_58 ( V_41 ) == V_151 )
V_150 = F_70 ( V_5 ) ;
for ( V_40 = V_150 ; V_40 < ( int ) V_107 -> V_148 ; V_40 ++ ) {
if ( rand () <= V_136 * V_152 ) {
V_108 = rand () / ( V_152 / V_153 + 1 ) ;
if ( V_108 < V_154 ) {
V_5 [ V_40 ] ^= 1 << ( rand () / ( V_152 / 8 + 1 ) ) ;
V_108 = V_153 ;
} else {
V_108 -= V_155 ;
}
if ( V_108 < V_155 ) {
V_5 [ V_40 ] = rand () / ( V_152 / 255 + 1 ) ;
V_108 = V_153 ;
} else {
V_108 -= V_155 ;
}
if ( V_108 < V_156 ) {
V_5 [ V_40 ] = V_157 [ rand () / ( V_152 / V_158 + 1 ) ] ;
V_108 = V_153 ;
} else {
V_108 -= V_156 ;
}
if ( V_108 < V_159 ) {
if ( ( unsigned int ) V_40 < V_107 -> V_148 - 2 )
F_71 ( ( char * ) & V_5 [ V_40 ] , L_120 , 2 ) ;
V_108 = V_153 ;
} else {
V_108 -= V_159 ;
}
if ( V_108 < V_160 ) {
for ( V_94 = V_40 ; V_94 < ( int ) V_107 -> V_148 ; V_94 ++ )
V_5 [ V_94 ] = 0xAA ;
V_40 = V_107 -> V_148 ;
}
}
}
}
if ( ! F_72 ( V_102 , V_107 , V_5 , & V_95 ) ) {
switch ( V_95 ) {
case V_145 :
fprintf ( V_28 ,
L_121 ,
V_111 , V_93 [ V_143 ] ) ;
break;
default:
fprintf ( V_28 , L_114 ,
V_114 , F_57 ( V_95 ) ) ;
break;
}
exit ( 2 ) ;
}
V_113 ++ ;
}
V_103 ++ ;
}
F_6 ( V_18 ) ;
F_6 ( V_19 ) ;
if ( V_95 != 0 ) {
fprintf ( V_28 ,
L_122 ,
V_93 [ V_143 ] , F_57 ( V_95 ) ) ;
switch ( V_95 ) {
case V_144 :
case V_145 :
case V_146 :
fprintf ( V_28 , L_110 , V_96 ) ;
F_6 ( V_96 ) ;
break;
}
}
if ( ! V_102 ) {
F_6 ( V_114 ) ;
V_114 = F_8 ( V_93 [ V_143 + 1 ] ) ;
V_102 = F_64 ( V_114 , V_137 , V_140 ,
V_99 ? F_65 ( V_99 , F_66 ( V_41 ) ) : F_66 ( V_41 ) ,
FALSE , V_109 , V_110 , & V_95 ) ;
if ( V_102 == NULL ) {
fprintf ( V_28 , L_113 ,
V_114 , F_57 ( V_95 ) ) ;
exit ( 2 ) ;
}
}
F_6 ( V_110 ) ;
V_110 = NULL ;
if ( ! F_68 ( V_102 , & V_95 ) ) {
fprintf ( V_28 , L_114 , V_114 ,
F_57 ( V_95 ) ) ;
exit ( 2 ) ;
}
F_6 ( V_109 ) ;
F_6 ( V_114 ) ;
}
if ( V_134 ) {
fprintf ( stdout , L_123 ,
V_103 - 1 , F_73 ( V_103 - 1 , L_124 , L_125 ) , V_104 ,
F_73 ( V_104 , L_124 , L_125 ) , V_68 ) ;
} else if ( V_135 ) {
fprintf ( stdout , L_126 ,
V_103 - 1 , F_73 ( V_103 - 1 , L_124 , L_125 ) , V_104 ,
F_73 ( V_104 , L_124 , L_125 ) ,
( long ) V_61 . V_9 ,
( long int ) V_61 . V_63 ) ;
}
return 0 ;
}
static int
F_70 ( T_6 * V_5 )
{
int V_161 = 0 ;
for ( V_161 = 0 ; V_5 [ V_161 ] != '\0' ; V_161 ++ ) ;
V_161 ++ ;
V_161 ++ ;
for (; V_5 [ V_161 ] != '\0' ; V_161 ++ ) ;
V_161 ++ ;
for (; V_5 [ V_161 ] != '\0' ; V_161 ++ ) ;
V_161 ++ ;
for (; V_5 [ V_161 ] != '\0' ; V_161 ++ ) ;
V_161 ++ ;
for (; V_5 [ V_161 ] != '\0' ; V_161 ++ ) ;
V_161 ++ ;
V_161 += 2 ;
return V_161 ;
}
static void
F_69 ( T_19 V_100 , struct V_42 * V_162 ,
const struct V_42 * V_163 , T_6 * V_5 ,
T_3 V_101 )
{
if ( V_100 . V_128 == 0 )
V_100 . V_129 = V_100 . V_130 = 0 ;
if ( V_100 . V_131 == 0 )
V_100 . V_132 = V_100 . V_133 = 0 ;
if ( V_100 . V_130 < 0 ) {
V_100 . V_129 += V_163 -> V_148 + V_100 . V_130 ;
V_100 . V_130 = 0 ;
}
if ( V_100 . V_132 > 0 ) {
V_100 . V_133 += V_100 . V_132 - V_163 -> V_148 ;
V_100 . V_132 = 0 ;
}
if ( V_100 . V_128 && V_100 . V_131 ) {
if ( V_100 . V_129 > ( ( int ) V_163 -> V_148 + V_100 . V_133 ) ) {
int V_164 , V_165 ;
V_165 = V_163 -> V_148 + V_100 . V_133 + V_100 . V_131 ;
V_164 = - V_100 . V_131 ;
V_100 . V_133 = V_100 . V_128 + V_100 . V_129 - V_163 -> V_148 ;
V_100 . V_131 = - V_100 . V_128 ;
V_100 . V_128 = V_164 ;
V_100 . V_129 = V_165 ;
}
}
if ( V_163 -> V_148 < ( T_7 ) ( V_100 . V_129 - V_100 . V_133 ) ) {
V_100 . V_128 = 0 ;
V_100 . V_131 = 0 ;
}
if ( ( T_7 ) ( V_100 . V_128 - V_100 . V_131 ) >
( V_163 -> V_148 - ( T_7 ) ( V_100 . V_129 - V_100 . V_133 ) ) ) {
V_100 . V_128 = V_163 -> V_148 - ( V_100 . V_129 - V_100 . V_133 ) ;
V_100 . V_131 = 0 ;
}
if ( V_100 . V_128 > 0 ) {
* V_162 = * V_163 ;
if ( V_100 . V_129 > 0 ) {
memmove ( & V_5 [ V_100 . V_129 ] ,
& V_5 [ V_100 . V_129 + V_100 . V_128 ] ,
V_162 -> V_148 - V_100 . V_128 ) ;
} else {
V_5 += V_100 . V_128 ;
}
V_162 -> V_148 -= V_100 . V_128 ;
if ( V_101 ) {
if ( V_163 -> V_65 > ( T_7 ) V_100 . V_128 )
V_162 -> V_65 -= V_100 . V_128 ;
else
V_162 -> V_65 = 0 ;
}
V_163 = V_162 ;
}
if ( V_100 . V_131 < 0 ) {
* V_162 = * V_163 ;
if ( V_100 . V_133 < 0 ) {
memmove ( & V_5 [ ( T_11 ) V_162 -> V_148 + ( V_100 . V_131 + V_100 . V_133 ) ] ,
& V_5 [ ( T_11 ) V_162 -> V_148 + V_100 . V_133 ] ,
- V_100 . V_133 ) ;
}
V_162 -> V_148 += V_100 . V_131 ;
if ( V_101 ) {
if ( ( ( signed int ) V_163 -> V_65 + V_100 . V_131 ) > 0 )
V_162 -> V_65 += V_100 . V_131 ;
else
V_162 -> V_65 = 0 ;
}
}
}
