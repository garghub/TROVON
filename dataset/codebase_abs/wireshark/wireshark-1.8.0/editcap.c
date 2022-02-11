static T_1 *
F_1 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 * V_5 = F_2 ( 16 ) ;
#ifdef F_3
if( V_2 -> V_6 > 2000000000 ) {
V_4 = NULL ;
} else
#endif
V_4 = localtime ( & V_2 -> V_6 ) ;
if ( V_4 ) {
F_4 ( V_5 , 16 , L_1 ,
V_4 -> V_7 + 1900 ,
V_4 -> V_8 + 1 ,
V_4 -> V_9 ,
V_4 -> V_10 ,
V_4 -> V_11 ,
V_4 -> V_12 ) ;
} else
V_5 [ 0 ] = '\0' ;
return V_5 ;
}
static T_1 *
F_5 ( T_2 V_13 , const struct V_1 * V_14 ,
T_1 * V_15 , T_1 * V_16 )
{
T_1 V_17 [ 5 + 1 ] ;
T_1 * V_18 ;
T_1 * V_19 ;
V_18 = F_1 ( V_14 ) ;
F_4 ( V_17 , sizeof( V_17 ) , L_2 , V_13 ) ;
V_19 = F_6 ( V_15 , L_3 , V_17 , L_3 , V_18 , V_16 , NULL ) ;
F_7 ( V_18 ) ;
return V_19 ;
}
static T_3
F_8 ( const char * V_20 , T_1 * * V_15 , T_1 * * V_16 )
{
char * V_21 , * V_22 ;
T_1 * V_23 ;
V_23 = F_9 ( V_20 ) ;
if ( V_23 == NULL ) {
fprintf ( V_24 , L_4 ) ;
return FALSE ;
}
V_22 = strrchr ( V_23 , V_25 ) ;
V_21 = strrchr ( V_23 , '.' ) ;
if ( V_21 != NULL && ( V_22 == NULL || V_21 > V_22 ) ) {
V_21 [ 0 ] = '\0' ;
* V_15 = F_9 ( V_23 ) ;
V_21 [ 0 ] = '.' ;
* V_16 = F_9 ( V_21 ) ;
} else {
* V_15 = F_9 ( V_23 ) ;
* V_16 = NULL ;
}
F_7 ( V_23 ) ;
return TRUE ;
}
static T_3
F_10 ( char * V_26 )
{
char * V_27 ;
char * V_28 ;
if ( ++ V_29 >= V_30 ) {
printf ( L_5 ) ;
return ( FALSE ) ;
}
printf ( L_6 , V_26 ) ;
if ( ( V_27 = strchr ( V_26 , '-' ) ) == NULL ) {
printf ( L_7 ) ;
V_31 [ V_29 ] . V_32 = 0 ;
V_31 [ V_29 ] . V_33 = atoi ( V_26 ) ;
printf ( L_8 , V_31 [ V_29 ] . V_33 ) ;
}
else {
printf ( L_9 ) ;
V_28 = V_27 + 1 ;
V_31 [ V_29 ] . V_32 = 1 ;
V_31 [ V_29 ] . V_33 = atoi ( V_26 ) ;
V_31 [ V_29 ] . V_34 = atoi ( V_28 ) ;
printf ( L_10 , V_31 [ V_29 ] . V_33 , V_31 [ V_29 ] . V_34 ) ;
}
return ( TRUE ) ;
}
static int
F_11 ( int V_35 )
{
int V_36 = 0 ;
for ( V_36 = 0 ; V_36 <= V_29 ; V_36 ++ ) {
if ( V_31 [ V_36 ] . V_32 ) {
if ( V_31 [ V_36 ] . V_33 <= V_35 && V_31 [ V_36 ] . V_34 >= V_35 )
return 1 ;
}
else {
if ( V_35 == V_31 [ V_36 ] . V_33 )
return 1 ;
}
}
return 0 ;
}
static T_3
F_12 ( T_4 * V_37 )
{
struct V_38 * V_39 = F_13 ( V_37 ) ;
return ( V_39 -> V_40 . V_6 >= V_41 ) && ( V_39 -> V_40 . V_6 < V_42 ) ;
}
static void
F_14 ( char * V_43 )
{
char * V_44 , * V_45 ;
long V_46 ;
T_5 V_47 ;
if ( ! V_43 )
return;
while ( * V_43 == ' ' || * V_43 == '\t' ) {
V_43 ++ ;
}
if ( * V_43 == '-' ) {
V_48 . V_49 = 1 ;
V_43 ++ ;
}
if ( * V_43 == '.' ) {
V_46 = 0 ;
V_44 = V_43 ;
} else {
V_46 = strtol ( V_43 , & V_44 , 10 ) ;
if ( V_44 == NULL || V_44 == V_43 || V_46 == V_50 || V_46 == V_51 ) {
fprintf ( V_24 , L_11 ,
V_43 ) ;
exit ( 1 ) ;
}
if ( V_46 < 0 ) {
fprintf ( V_24 , L_11 ,
V_43 ) ;
exit ( 1 ) ;
}
}
V_48 . V_52 . V_53 = V_46 ;
if ( * V_44 != '\0' ) {
V_46 = strtol ( & ( V_44 [ 1 ] ) , & V_45 , 10 ) ;
if( ( V_45 - & ( V_44 [ 1 ] ) ) > 6 ) {
V_44 [ 7 ] = 't' ;
V_46 = strtol ( & ( V_44 [ 1 ] ) , & V_45 , 10 ) ;
}
if ( * V_44 != '.' || V_45 == NULL || V_45 == V_44
|| V_46 < 0 || V_46 > V_54 || V_46 == V_50 || V_46 == V_51 ) {
fprintf ( V_24 , L_11 ,
V_43 ) ;
exit ( 1 ) ;
}
}
else {
return;
}
if ( V_44 && V_45 ) {
V_47 = V_45 - V_44 - 1 ;
while( V_47 < 6 ) {
V_46 *= 10 ;
V_47 ++ ;
}
}
V_48 . V_52 . V_55 = V_46 ;
}
static void
F_15 ( char * V_43 )
{
char * V_44 , * V_45 ;
long V_46 ;
T_5 V_47 ;
if ( ! V_43 )
return;
while ( * V_43 == ' ' || * V_43 == '\t' ) {
V_43 ++ ;
}
if ( * V_43 == '-' ) {
V_56 . V_49 = 1 ;
V_43 ++ ;
}
if ( * V_43 == '.' ) {
V_46 = 0 ;
V_44 = V_43 ;
} else {
V_46 = strtol ( V_43 , & V_44 , 10 ) ;
if ( V_44 == NULL || V_44 == V_43 || V_46 == V_50 || V_46 == V_51 ) {
fprintf ( V_24 , L_11 ,
V_43 ) ;
exit ( 1 ) ;
}
if ( V_46 < 0 ) {
fprintf ( V_24 , L_11 ,
V_43 ) ;
exit ( 1 ) ;
}
}
V_56 . V_52 . V_53 = V_46 ;
if ( * V_44 != '\0' ) {
V_46 = strtol ( & ( V_44 [ 1 ] ) , & V_45 , 10 ) ;
if( ( V_45 - & ( V_44 [ 1 ] ) ) > 6 ) {
V_44 [ 7 ] = 't' ;
V_46 = strtol ( & ( V_44 [ 1 ] ) , & V_45 , 10 ) ;
}
if ( * V_44 != '.' || V_45 == NULL || V_45 == V_44
|| V_46 < 0 || V_46 > V_54 || V_46 == V_50 || V_46 == V_51 ) {
fprintf ( V_24 , L_11 ,
V_43 ) ;
exit ( 1 ) ;
}
}
else {
return;
}
if ( V_44 && V_45 ) {
V_47 = V_45 - V_44 - 1 ;
while( V_47 < 6 ) {
V_46 *= 10 ;
V_47 ++ ;
}
}
V_56 . V_52 . V_55 = V_46 ;
}
static void
F_16 ( char * V_43 )
{
char * V_44 , * V_45 ;
long V_46 ;
T_5 V_47 ;
if ( ! V_43 )
return;
while ( * V_43 == ' ' || * V_43 == '\t' ) {
V_43 ++ ;
}
if ( * V_43 == '-' ) {
V_43 ++ ;
}
if ( * V_43 == '.' ) {
V_46 = 0 ;
V_44 = V_43 ;
} else {
V_46 = strtol ( V_43 , & V_44 , 10 ) ;
if ( V_44 == NULL || V_44 == V_43 || V_46 == V_50 || V_46 == V_51 ) {
fprintf ( V_24 , L_12 ,
V_43 ) ;
exit ( 1 ) ;
}
if ( V_46 < 0 ) {
fprintf ( V_24 , L_13 ,
V_43 ) ;
exit ( 1 ) ;
}
}
V_57 . V_6 = V_46 ;
if ( * V_44 != '\0' ) {
V_46 = strtol ( & ( V_44 [ 1 ] ) , & V_45 , 10 ) ;
if( ( V_45 - & ( V_44 [ 1 ] ) ) > 9 ) {
V_44 [ 10 ] = 't' ;
V_46 = strtol ( & ( V_44 [ 1 ] ) , & V_45 , 10 ) ;
}
if ( * V_44 != '.' || V_45 == NULL || V_45 == V_44
|| V_46 < 0 || V_46 > V_58 || V_46 == V_50 || V_46 == V_51 ) {
fprintf ( V_24 , L_14 ,
V_43 ) ;
exit ( 1 ) ;
}
}
else {
return;
}
if ( V_44 && V_45 ) {
V_47 = V_45 - V_44 - 1 ;
while( V_47 < 9 ) {
V_46 *= 10 ;
V_47 ++ ;
}
}
V_57 . V_59 = V_46 ;
}
static T_3
F_17 ( T_6 * V_60 , T_7 V_61 ) {
int V_36 ;
T_8 V_62 ;
V_63 ++ ;
if ( V_63 >= V_64 )
V_63 = 0 ;
F_18 ( & V_62 ) ;
F_19 ( & V_62 , V_60 , V_61 ) ;
F_20 ( & V_62 , V_65 [ V_63 ] . V_66 ) ;
V_65 [ V_63 ] . V_61 = V_61 ;
for ( V_36 = 0 ; V_36 < V_64 ; V_36 ++ ) {
if ( V_36 == V_63 )
continue;
if ( V_65 [ V_36 ] . V_61 == V_65 [ V_63 ] . V_61 &&
memcmp ( V_65 [ V_36 ] . V_66 , V_65 [ V_63 ] . V_66 , 16 ) == 0 ) {
return TRUE ;
}
}
return FALSE ;
}
static T_3
F_21 ( T_6 * V_60 , T_7 V_61 , const T_9 * V_67 ) {
int V_36 ;
T_8 V_62 ;
V_63 ++ ;
if ( V_63 >= V_64 )
V_63 = 0 ;
F_18 ( & V_62 ) ;
F_19 ( & V_62 , V_60 , V_61 ) ;
F_20 ( & V_62 , V_65 [ V_63 ] . V_66 ) ;
V_65 [ V_63 ] . V_61 = V_61 ;
V_65 [ V_63 ] . time . V_6 = V_67 -> V_6 ;
V_65 [ V_63 ] . time . V_59 = V_67 -> V_59 ;
for ( V_36 = V_63 - 1 ; ; V_36 -- ) {
T_9 V_68 ;
int V_69 ;
if ( V_36 < 0 ) {
V_36 = V_64 - 1 ;
}
if ( V_36 == V_63 ) {
break;
}
if ( F_22 ( & ( V_65 [ V_36 ] . time ) ) ) {
break;
}
F_23 ( & V_68 , V_67 , & V_65 [ V_36 ] . time ) ;
if( V_68 . V_6 < 0 || V_68 . V_59 < 0 )
{
continue;
}
V_69 = F_24 ( & V_68 , & V_57 ) ;
if( V_69 > 0 ) {
break;
} else if ( V_65 [ V_36 ] . V_61 == V_65 [ V_63 ] . V_61 &&
memcmp ( V_65 [ V_36 ] . V_66 , V_65 [ V_63 ] . V_66 , 16 ) == 0 ) {
return TRUE ;
}
}
return FALSE ;
}
static void
F_25 ( T_3 V_70 )
{
T_10 * V_71 ;
if ( ! V_70 )
V_71 = stdout ;
else
V_71 = V_24 ;
fprintf ( V_71 , L_15
#ifdef F_26
L_16 F_26 L_17 V_72 L_18
#endif
L_19 , V_73 ) ;
fprintf ( V_71 , L_20 ) ;
fprintf ( V_71 , L_21 ) ;
fprintf ( V_71 , L_19 ) ;
fprintf ( V_71 , L_22 ) ;
fprintf ( V_71 , L_19 ) ;
fprintf ( V_71 , L_23 ) ;
fprintf ( V_71 , L_24 ) ;
fprintf ( V_71 , L_19 ) ;
fprintf ( V_71 , L_25 ) ;
fprintf ( V_71 , L_26 ) ;
fprintf ( V_71 , L_27 ) ;
fprintf ( V_71 , L_28 ) ;
fprintf ( V_71 , L_29 ) ;
fprintf ( V_71 , L_30 ) ;
fprintf ( V_71 , L_19 ) ;
fprintf ( V_71 , L_31 ) ;
fprintf ( V_71 , L_32 , V_74 ) ;
fprintf ( V_71 , L_33 ) ;
fprintf ( V_71 , L_34 , V_75 ) ;
fprintf ( V_71 , L_35 ) ;
fprintf ( V_71 , L_36 ) ;
fprintf ( V_71 , L_37 ) ;
fprintf ( V_71 , L_38 ) ;
fprintf ( V_71 , L_39 ) ;
fprintf ( V_71 , L_40 ) ;
fprintf ( V_71 , L_19 ) ;
fprintf ( V_71 , L_41 ) ;
fprintf ( V_71 , L_42 ) ;
fprintf ( V_71 , L_43 ) ;
fprintf ( V_71 , L_44 ) ;
fprintf ( V_71 , L_19 ) ;
fprintf ( V_71 , L_45 ) ;
fprintf ( V_71 , L_46 ) ;
fprintf ( V_71 , L_47 ) ;
fprintf ( V_71 , L_48 ) ;
fprintf ( V_71 , L_49 ) ;
fprintf ( V_71 , L_50 ) ;
fprintf ( V_71 , L_51 ) ;
fprintf ( V_71 , L_52 ) ;
fprintf ( V_71 , L_53 ) ;
fprintf ( V_71 , L_54 ) ;
fprintf ( V_71 , L_55 ) ;
fprintf ( V_71 , L_56 ) ;
fprintf ( V_71 , L_57 ) ;
fprintf ( V_71 , L_58 ) ;
fprintf ( V_71 , L_59 ) ;
fprintf ( V_71 , L_60 ) ;
fprintf ( V_71 , L_61 ) ;
fprintf ( V_71 , L_19 ) ;
fprintf ( V_71 , L_62 ) ;
fprintf ( V_71 , L_63 ) ;
fprintf ( V_71 , L_64 ) ;
fprintf ( V_71 , L_65 ) ;
fprintf ( V_71 , L_66 ) ;
fprintf ( V_71 , L_67 ) ;
fprintf ( V_71 , L_68 ) ;
fprintf ( V_71 , L_69 ) ;
fprintf ( V_71 , L_70 ) ;
fprintf ( V_71 , L_71 ) ;
fprintf ( V_71 , L_72 ) ;
fprintf ( V_71 , L_73 ) ;
fprintf ( V_71 , L_19 ) ;
fprintf ( V_71 , L_74 ) ;
fprintf ( V_71 , L_75 ) ;
fprintf ( V_71 , L_76 ) ;
fprintf ( V_71 , L_77 ) ;
fprintf ( V_71 , L_78 ) ;
fprintf ( V_71 , L_79 ) ;
fprintf ( V_71 , L_19 ) ;
}
static T_11
F_27 ( T_12 V_76 , T_12 V_77 )
{
return strcmp ( ( ( const struct V_78 * ) V_76 ) -> V_79 ,
( ( const struct V_78 * ) V_77 ) -> V_79 ) ;
}
static void
F_28 ( T_13 V_80 , T_13 T_14 V_81 )
{
fprintf ( V_24 , L_80 ,
( (struct V_78 * ) V_80 ) -> V_79 ,
( (struct V_78 * ) V_80 ) -> V_82 ) ;
}
static void
F_29 ( void ) {
int V_36 ;
struct V_78 * V_83 ;
T_15 * V_84 = NULL ;
V_83 = F_2 ( sizeof( struct V_78 ) * V_85 ) ;
fprintf ( V_24 , L_81 ) ;
for ( V_36 = 0 ; V_36 < V_85 ; V_36 ++ ) {
if ( F_30 ( V_36 ) ) {
V_83 [ V_36 ] . V_79 = F_31 ( V_36 ) ;
V_83 [ V_36 ] . V_82 = F_32 ( V_36 ) ;
V_84 = F_33 ( V_84 , & V_83 [ V_36 ] , F_27 ) ;
}
}
F_34 ( V_84 , F_28 , NULL ) ;
F_35 ( V_84 ) ;
F_7 ( V_83 ) ;
}
static void
F_36 ( void ) {
int V_36 ;
struct V_78 * V_86 ;
T_15 * V_84 = NULL ;
V_86 = F_2 ( sizeof( struct V_78 ) * V_87 ) ;
fprintf ( V_24 , L_82 ) ;
for ( V_36 = 0 ; V_36 < V_87 ; V_36 ++ ) {
V_86 [ V_36 ] . V_79 = F_37 ( V_36 ) ;
if ( V_86 [ V_36 ] . V_79 != NULL ) {
V_86 [ V_36 ] . V_82 = F_38 ( V_36 ) ;
V_84 = F_33 ( V_84 , & V_86 [ V_36 ] , F_27 ) ;
}
}
F_34 ( V_84 , F_28 , NULL ) ;
F_35 ( V_84 ) ;
F_7 ( V_86 ) ;
}
static void
F_39 ( const char * T_16 V_81 , T_17 T_18 V_81 )
{
return;
}
int
main ( int V_88 , char * V_89 [] )
{
T_4 * V_37 ;
int V_36 , V_90 , V_91 ;
T_1 * V_92 ;
int V_93 ;
char * V_94 ;
T_7 V_95 = 0 ;
int V_96 = 0 ;
T_19 * V_97 = NULL ;
int V_98 = 1 ;
unsigned V_99 = 0 ;
T_20 V_100 ;
struct V_38 V_101 ;
const struct V_38 * V_102 ;
int V_103 ;
T_21 * V_104 ;
T_22 * V_105 ;
T_6 * V_5 ;
T_7 V_106 = 0 ;
int V_107 = 0 ;
int V_108 = 0 ;
char * V_109 = NULL ;
T_3 V_110 = TRUE ;
int V_111 = 0 ;
int V_112 = 0 ;
T_9 V_113 ;
T_1 * V_15 = NULL ;
T_1 * V_16 = NULL ;
char V_114 [ 100 ] ;
#ifdef F_40
char * V_115 ;
#endif
#ifdef F_41
F_42 ( V_88 , V_89 ) ;
#endif
F_43 () ;
#ifdef F_40
if ( ( V_115 = F_44 ( V_89 [ 0 ] , main ) ) ) {
F_45 ( L_83 , V_115 ) ;
F_7 ( V_115 ) ;
} else {
F_46 ( F_39 , NULL , NULL , NULL ) ;
F_47 () ;
}
#endif
while ( ( V_93 = F_48 ( V_88 , V_89 , L_84 ) ) != - 1 ) {
switch ( V_93 ) {
case 'E' :
V_116 = strtod ( V_117 , & V_94 ) ;
if ( V_94 == V_117 || V_116 < 0.0 || V_116 > 1.0 ) {
fprintf ( V_24 , L_85 ,
V_117 ) ;
exit ( 1 ) ;
}
srand ( ( unsigned int ) ( time ( NULL ) + F_49 () ) ) ;
break;
case 'F' :
V_118 = F_50 ( V_117 ) ;
if ( V_118 < 0 ) {
fprintf ( V_24 , L_86 ,
V_117 ) ;
F_29 () ;
exit ( 1 ) ;
}
break;
case 'c' :
V_107 = strtol ( V_117 , & V_94 , 10 ) ;
if ( V_94 == V_117 || * V_94 != '\0' ) {
fprintf ( V_24 , L_87 ,
V_117 ) ;
exit ( 1 ) ;
}
if ( V_107 <= 0 ) {
fprintf ( V_24 , L_88 ,
V_107 ) ;
exit ( 1 ) ;
}
break;
case 'C' :
V_96 = strtol ( V_117 , & V_94 , 10 ) ;
if ( V_94 == V_117 || * V_94 != '\0' ) {
fprintf ( V_24 , L_89 ,
V_117 ) ;
exit ( 1 ) ;
}
break;
case 'd' :
V_119 = TRUE ;
V_120 = FALSE ;
V_64 = V_74 ;
break;
case 'D' :
V_119 = TRUE ;
V_120 = FALSE ;
V_64 = strtol ( V_117 , & V_94 , 10 ) ;
if ( V_94 == V_117 || * V_94 != '\0' ) {
fprintf ( V_24 , L_90 ,
V_117 ) ;
exit ( 1 ) ;
}
if ( V_64 < 0 || V_64 > V_75 ) {
fprintf ( V_24 , L_91 ,
V_64 , V_75 ) ;
exit ( 1 ) ;
}
break;
case 'w' :
V_119 = FALSE ;
V_120 = TRUE ;
V_64 = V_75 ;
F_16 ( V_117 ) ;
break;
case '?' :
switch( V_121 ) {
case 'F' :
F_29 () ;
break;
case 'T' :
F_36 () ;
break;
default:
F_25 ( TRUE ) ;
}
exit ( 1 ) ;
break;
case 'h' :
F_25 ( FALSE ) ;
exit ( 1 ) ;
break;
case 'r' :
V_122 = ! V_122 ;
break;
case 's' :
V_95 = strtol ( V_117 , & V_94 , 10 ) ;
if ( V_94 == V_117 || * V_94 != '\0' ) {
fprintf ( V_24 , L_92 ,
V_117 ) ;
exit ( 1 ) ;
}
break;
case 't' :
F_14 ( V_117 ) ;
break;
case 'S' :
F_15 ( V_117 ) ;
V_123 = TRUE ;
break;
case 'T' :
V_124 = F_51 ( V_117 ) ;
if ( V_124 < 0 ) {
fprintf ( V_24 , L_93 ,
V_117 ) ;
F_36 () ;
exit ( 1 ) ;
}
break;
case 'v' :
V_125 = ! V_125 ;
break;
case 'i' :
V_111 = atoi ( V_117 ) ;
if( V_111 <= 0 ) {
fprintf ( V_24 , L_94 , V_117 ) ;
exit ( 1 ) ;
}
break;
case 'A' :
{
struct V_3 V_126 ;
memset ( & V_126 , 0 , sizeof( struct V_3 ) ) ;
if( ! strptime ( V_117 , L_95 , & V_126 ) ) {
fprintf ( V_24 , L_96 , V_117 ) ;
exit ( 1 ) ;
}
V_127 = TRUE ;
V_126 . V_128 = - 1 ;
V_41 = mktime ( & V_126 ) ;
break;
}
case 'B' :
{
struct V_3 V_129 ;
memset ( & V_129 , 0 , sizeof( struct V_3 ) ) ;
if( ! strptime ( V_117 , L_95 , & V_129 ) ) {
fprintf ( V_24 , L_96 , V_117 ) ;
exit ( 1 ) ;
}
V_127 = TRUE ;
V_129 . V_128 = - 1 ;
V_42 = mktime ( & V_129 ) ;
break;
}
}
}
#ifdef F_52
printf ( L_97 , V_130 , V_88 ) ;
#endif
if ( ( V_88 - V_130 ) < 1 ) {
F_25 ( TRUE ) ;
exit ( 1 ) ;
}
if ( V_127 && ! V_42 ) {
struct V_3 V_129 ;
memset ( & V_129 , 0 , sizeof( struct V_3 ) ) ;
V_129 . V_7 = 135 ;
V_129 . V_9 = 31 ;
V_129 . V_8 = 11 ;
V_42 = mktime ( & V_129 ) ;
}
F_53 ( & V_113 ) ;
if ( V_41 > V_42 ) {
fprintf ( V_24 , L_98 ) ;
exit ( 1 ) ;
}
if ( V_107 > 0 && V_111 > 0 ) {
fprintf ( V_24 , L_99 ) ;
fprintf ( V_24 , L_100 ) ;
exit ( 1 ) ;
}
V_37 = F_54 ( V_89 [ V_130 ] , & V_91 , & V_92 , FALSE ) ;
if ( ! V_37 ) {
fprintf ( V_24 , L_101 , V_89 [ V_130 ] ,
F_55 ( V_91 ) ) ;
switch ( V_91 ) {
case V_131 :
case V_132 :
case V_133 :
fprintf ( V_24 , L_102 , V_92 ) ;
F_7 ( V_92 ) ;
break;
}
exit ( 2 ) ;
}
if ( V_125 ) {
fprintf ( V_24 , L_103 , V_89 [ V_130 ] ,
F_32 ( F_56 ( V_37 ) ) ) ;
}
V_104 = F_57 ( V_37 ) ;
V_105 = F_58 ( V_37 ) ;
if ( ( V_88 - V_130 ) >= 2 ) {
if ( V_124 == - 2 )
V_124 = F_59 ( V_37 ) ;
for ( V_36 = V_130 + 2 ; V_36 < V_88 ; V_36 ++ )
if ( F_10 ( V_89 [ V_36 ] ) == FALSE )
break;
if ( V_119 || V_120 ) {
for ( V_36 = 0 ; V_36 < V_64 ; V_36 ++ ) {
memset ( & V_65 [ V_36 ] . V_66 , 0 , 16 ) ;
V_65 [ V_36 ] . V_61 = 0 ;
F_53 ( & V_65 [ V_36 ] . time ) ;
}
}
while ( F_60 ( V_37 , & V_91 , & V_92 , & V_100 ) ) {
V_106 ++ ;
V_102 = F_13 ( V_37 ) ;
V_5 = F_61 ( V_37 ) ;
if ( F_22 ( & V_113 ) ) {
V_113 . V_6 = V_102 -> V_40 . V_6 ;
V_113 . V_59 = V_102 -> V_40 . V_59 ;
if ( V_107 > 0 || V_111 > 0 ) {
if ( ! F_8 ( V_89 [ V_130 + 1 ] , & V_15 , & V_16 ) )
exit ( 2 ) ;
V_109 = F_5 ( V_112 ++ , & V_102 -> V_40 , V_15 , V_16 ) ;
} else
V_109 = F_9 ( V_89 [ V_130 + 1 ] ) ;
if( V_104 -> V_134 == NULL ) {
F_4 ( V_114 , sizeof( V_114 ) , L_104 V_73 ) ;
V_104 -> V_134 = V_114 ;
}
V_97 = F_62 ( V_109 , V_118 , V_124 ,
V_95 ? F_63 ( V_95 , F_64 ( V_37 ) ) : F_64 ( V_37 ) ,
FALSE , V_104 , V_105 , & V_91 ) ;
if ( V_97 == NULL ) {
fprintf ( V_24 , L_105 , V_109 ,
F_55 ( V_91 ) ) ;
exit ( 2 ) ;
}
}
F_65 ( V_109 ) ;
if ( V_111 > 0 ) {
while ( ( V_102 -> V_40 . V_6 - V_113 . V_6 > V_111 ) ||
( V_102 -> V_40 . V_6 - V_113 . V_6 == V_111 &&
V_102 -> V_40 . V_59 >= V_113 . V_59 ) ) {
if ( ! F_66 ( V_97 , & V_91 ) ) {
fprintf ( V_24 , L_106 , V_109 ,
F_55 ( V_91 ) ) ;
exit ( 2 ) ;
}
V_113 . V_6 = V_113 . V_6 + V_111 ;
F_7 ( V_109 ) ;
V_109 = F_5 ( V_112 ++ , & V_102 -> V_40 , V_15 , V_16 ) ;
F_65 ( V_109 ) ;
if ( V_125 ) {
fprintf ( V_24 , L_107 , V_109 ) ;
}
V_97 = F_62 ( V_109 , V_118 , V_124 ,
V_95 ? F_63 ( V_95 , F_64 ( V_37 ) ) : F_64 ( V_37 ) ,
FALSE , V_104 , V_105 , & V_91 ) ;
if ( V_97 == NULL ) {
fprintf ( V_24 , L_105 , V_109 ,
F_55 ( V_91 ) ) ;
exit ( 2 ) ;
}
}
}
if ( V_107 > 0 ) {
if ( V_108 > 0 &&
V_108 % V_107 == 0 ) {
if ( ! F_66 ( V_97 , & V_91 ) ) {
fprintf ( V_24 , L_106 , V_109 ,
F_55 ( V_91 ) ) ;
exit ( 2 ) ;
}
F_7 ( V_109 ) ;
V_109 = F_5 ( V_112 ++ , & V_102 -> V_40 , V_15 , V_16 ) ;
F_65 ( V_109 ) ;
if ( V_125 ) {
fprintf ( V_24 , L_107 , V_109 ) ;
}
V_97 = F_62 ( V_109 , V_118 , V_124 ,
V_95 ? F_63 ( V_95 , F_64 ( V_37 ) ) : F_64 ( V_37 ) ,
FALSE , V_104 , V_105 , & V_91 ) ;
if ( V_97 == NULL ) {
fprintf ( V_24 , L_105 , V_109 ,
F_55 ( V_91 ) ) ;
exit ( 2 ) ;
}
}
}
if ( V_127 )
V_110 = F_12 ( V_37 ) ;
if ( V_110 && ( ( ! F_11 ( V_98 ) && ! V_122 ) || ( F_11 ( V_98 ) && V_122 ) ) ) {
if ( V_125 && ! V_119 && ! V_120 )
printf ( L_108 , V_98 ) ;
V_102 = F_13 ( V_37 ) ;
if ( V_95 != 0 && V_102 -> V_135 > V_95 ) {
V_101 = * V_102 ;
V_101 . V_135 = V_95 ;
V_102 = & V_101 ;
}
if ( V_96 < 0 ) {
V_101 = * V_102 ;
if ( ( ( signed int ) V_102 -> V_135 + V_96 ) > 0 )
V_101 . V_135 += V_96 ;
else
V_101 . V_135 = 0 ;
V_102 = & V_101 ;
} else if ( V_96 > 0 ) {
V_101 = * V_102 ;
if ( V_102 -> V_135 > ( unsigned int ) V_96 ) {
V_101 . V_135 -= V_96 ;
V_5 += V_96 ;
} else
V_101 . V_135 = 0 ;
V_102 = & V_101 ;
}
if ( V_123 ) {
if ( V_136 . V_6 || V_136 . V_59 ) {
if ( ! V_56 . V_49 ) {
T_9 V_67 ;
T_9 V_68 ;
V_67 . V_6 = V_102 -> V_40 . V_6 ;
V_67 . V_59 = V_102 -> V_40 . V_59 ;
F_23 ( & V_68 , & V_67 , & V_136 ) ;
if ( V_68 . V_6 < 0 || V_68 . V_59 < 0 )
{
V_101 = * V_102 ;
V_101 . V_40 . V_6 = V_136 . V_6 + V_56 . V_52 . V_53 ;
V_101 . V_40 . V_59 = V_136 . V_59 ;
if ( V_101 . V_40 . V_59 + V_56 . V_52 . V_55 * 1000 > V_54 * 1000 ) {
V_101 . V_40 . V_6 ++ ;
V_101 . V_40 . V_59 += ( V_56 . V_52 . V_55 - V_54 ) * 1000 ;
} else {
V_101 . V_40 . V_59 += V_56 . V_52 . V_55 * 1000 ;
}
V_102 = & V_101 ;
}
} else {
V_101 = * V_102 ;
V_101 . V_40 . V_6 = V_136 . V_6 + V_56 . V_52 . V_53 ;
V_101 . V_40 . V_59 = V_136 . V_59 ;
if ( V_101 . V_40 . V_59 + V_56 . V_52 . V_55 * 1000 > V_54 * 1000 ) {
V_101 . V_40 . V_6 ++ ;
V_101 . V_40 . V_59 += ( V_56 . V_52 . V_55 - V_54 ) * 1000 ;
} else {
V_101 . V_40 . V_59 += V_56 . V_52 . V_55 * 1000 ;
}
V_102 = & V_101 ;
}
}
V_136 . V_6 = V_102 -> V_40 . V_6 ;
V_136 . V_59 = V_102 -> V_40 . V_59 ;
}
if ( V_102 -> V_40 . V_6 > 0 && V_48 . V_52 . V_53 != 0 ) {
V_101 = * V_102 ;
if ( V_48 . V_49 )
V_101 . V_40 . V_6 -= V_48 . V_52 . V_53 ;
else
V_101 . V_40 . V_6 += V_48 . V_52 . V_53 ;
V_102 = & V_101 ;
}
if ( V_102 -> V_40 . V_6 > 0 && V_48 . V_52 . V_55 != 0 ) {
V_101 = * V_102 ;
if ( V_48 . V_49 ) {
if ( V_101 . V_40 . V_59 / 1000 < V_48 . V_52 . V_55 ) {
V_101 . V_40 . V_6 -- ;
V_101 . V_40 . V_59 += V_54 * 1000 ;
}
V_101 . V_40 . V_59 -= V_48 . V_52 . V_55 * 1000 ;
} else {
if ( V_101 . V_40 . V_59 + V_48 . V_52 . V_55 * 1000 > V_54 * 1000 ) {
V_101 . V_40 . V_6 ++ ;
V_101 . V_40 . V_59 += ( V_48 . V_52 . V_55 - V_54 ) * 1000 ;
} else {
V_101 . V_40 . V_59 += V_48 . V_52 . V_55 * 1000 ;
}
}
V_102 = & V_101 ;
}
if ( V_119 ) {
if ( F_17 ( V_5 , V_102 -> V_135 ) ) {
if ( V_125 ) {
fprintf ( stdout , L_109 , V_98 , V_102 -> V_135 ) ;
for ( V_36 = 0 ; V_36 < 16 ; V_36 ++ ) {
fprintf ( stdout , L_110 , ( unsigned char ) V_65 [ V_63 ] . V_66 [ V_36 ] ) ;
}
fprintf ( stdout , L_19 ) ;
}
V_99 ++ ;
V_98 ++ ;
continue;
} else {
if ( V_125 ) {
fprintf ( stdout , L_111 , V_98 , V_102 -> V_135 ) ;
for ( V_36 = 0 ; V_36 < 16 ; V_36 ++ ) {
fprintf ( stdout , L_110 , ( unsigned char ) V_65 [ V_63 ] . V_66 [ V_36 ] ) ;
}
fprintf ( stdout , L_19 ) ;
}
}
}
if ( V_120 ) {
T_9 V_67 ;
V_67 . V_6 = V_102 -> V_40 . V_6 ;
V_67 . V_59 = V_102 -> V_40 . V_59 ;
if ( F_21 ( V_5 , V_102 -> V_135 , & V_67 ) ) {
if ( V_125 ) {
fprintf ( stdout , L_109 , V_98 , V_102 -> V_135 ) ;
for ( V_36 = 0 ; V_36 < 16 ; V_36 ++ ) {
fprintf ( stdout , L_110 , ( unsigned char ) V_65 [ V_63 ] . V_66 [ V_36 ] ) ;
}
fprintf ( stdout , L_19 ) ;
}
V_99 ++ ;
V_98 ++ ;
continue;
} else {
if ( V_125 ) {
fprintf ( stdout , L_111 , V_98 , V_102 -> V_135 ) ;
for ( V_36 = 0 ; V_36 < 16 ; V_36 ++ ) {
fprintf ( stdout , L_110 , ( unsigned char ) V_65 [ V_63 ] . V_66 [ V_36 ] ) ;
}
fprintf ( stdout , L_19 ) ;
}
}
}
if ( V_116 > 0.0 ) {
int V_137 = 0 ;
if ( F_56 ( V_37 ) == V_138 ) {
V_137 = F_67 ( V_5 ) ;
}
for ( V_36 = V_137 ; V_36 < ( int ) V_102 -> V_135 ; V_36 ++ ) {
if ( rand () <= V_116 * V_139 ) {
V_103 = rand () / ( V_139 / V_140 + 1 ) ;
if ( V_103 < V_141 ) {
V_5 [ V_36 ] ^= 1 << ( rand () / ( V_139 / 8 + 1 ) ) ;
V_103 = V_140 ;
} else {
V_103 -= V_142 ;
}
if ( V_103 < V_142 ) {
V_5 [ V_36 ] = rand () / ( V_139 / 255 + 1 ) ;
V_103 = V_140 ;
} else {
V_103 -= V_142 ;
}
if ( V_103 < V_143 ) {
V_5 [ V_36 ] = V_144 [ rand () / ( V_139 / V_145 + 1 ) ] ;
V_103 = V_140 ;
} else {
V_103 -= V_143 ;
}
if ( V_103 < V_146 ) {
if ( ( unsigned int ) V_36 < V_102 -> V_135 - 2 )
F_68 ( ( char * ) & V_5 [ V_36 ] , L_112 , 2 ) ;
V_103 = V_140 ;
} else {
V_103 -= V_146 ;
}
if ( V_103 < V_147 ) {
for ( V_90 = V_36 ; V_90 < ( int ) V_102 -> V_135 ; V_90 ++ ) {
V_5 [ V_90 ] = 0xAA ;
}
V_36 = V_102 -> V_135 ;
}
}
}
}
if ( ! F_69 ( V_97 , V_102 , F_70 ( V_37 ) , V_5 , & V_91 ) ) {
switch ( V_91 ) {
case V_132 :
fprintf ( V_24 , L_113 ,
V_106 , V_89 [ V_130 ] ) ;
break;
default:
fprintf ( V_24 , L_106 ,
V_109 , F_55 ( V_91 ) ) ;
break;
}
exit ( 2 ) ;
}
V_108 ++ ;
}
V_98 ++ ;
}
F_7 ( V_15 ) ;
F_7 ( V_16 ) ;
if ( V_91 != 0 ) {
fprintf ( V_24 ,
L_114 ,
V_89 [ V_130 ] , F_55 ( V_91 ) ) ;
switch ( V_91 ) {
case V_131 :
case V_132 :
case V_133 :
fprintf ( V_24 , L_102 , V_92 ) ;
F_7 ( V_92 ) ;
break;
}
}
if ( ! V_97 ) {
F_7 ( V_109 ) ;
V_109 = F_9 ( V_89 [ V_130 + 1 ] ) ;
V_97 = F_62 ( V_109 , V_118 , V_124 ,
V_95 ? F_63 ( V_95 , F_64 ( V_37 ) ) : F_64 ( V_37 ) ,
FALSE , V_104 , V_105 , & V_91 ) ;
if ( V_97 == NULL ) {
fprintf ( V_24 , L_105 , V_109 ,
F_55 ( V_91 ) ) ;
exit ( 2 ) ;
}
}
F_7 ( V_105 ) ;
V_105 = NULL ;
if ( ! F_66 ( V_97 , & V_91 ) ) {
fprintf ( V_24 , L_106 , V_109 ,
F_55 ( V_91 ) ) ;
exit ( 2 ) ;
}
F_7 ( V_104 ) ;
F_7 ( V_109 ) ;
}
if ( V_119 ) {
fprintf ( stdout , L_115 ,
V_98 - 1 , F_71 ( V_98 - 1 , L_116 , L_117 ) ,
V_99 , F_71 ( V_99 , L_116 , L_117 ) , V_64 ) ;
} else if ( V_120 ) {
fprintf ( stdout , L_118 ,
V_98 - 1 , F_71 ( V_98 - 1 , L_116 , L_117 ) ,
V_99 , F_71 ( V_99 , L_116 , L_117 ) ,
( long ) V_57 . V_6 , ( long int ) V_57 . V_59 ) ;
}
return 0 ;
}
static int F_67 ( T_6 * V_5 )
{
int V_148 = 0 ;
for ( V_148 = 0 ; V_5 [ V_148 ] != '\0' ; V_148 ++ ) ;
V_148 ++ ;
V_148 ++ ;
for (; V_5 [ V_148 ] != '\0' ; V_148 ++ ) ;
V_148 ++ ;
for (; V_5 [ V_148 ] != '\0' ; V_148 ++ ) ;
V_148 ++ ;
for (; V_5 [ V_148 ] != '\0' ; V_148 ++ ) ;
V_148 ++ ;
for (; V_5 [ V_148 ] != '\0' ; V_148 ++ ) ;
V_148 ++ ;
V_148 += 2 ;
return V_148 ;
}
