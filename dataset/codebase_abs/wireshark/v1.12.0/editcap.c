static T_1 *
F_1 ( const T_2 * V_1 )
{
struct V_2 * V_3 ;
T_1 * V_4 = ( T_1 * ) F_2 ( 16 ) ;
V_3 = localtime ( & V_1 -> V_5 ) ;
if ( V_3 ) {
F_3 ( V_4 , 16 , L_1 ,
V_3 -> V_6 + 1900 ,
V_3 -> V_7 + 1 ,
V_3 -> V_8 ,
V_3 -> V_9 ,
V_3 -> V_10 ,
V_3 -> V_11 ) ;
} else {
V_4 [ 0 ] = '\0' ;
}
return V_4 ;
}
static T_1 *
F_4 ( T_3 V_12 , const struct V_13 * V_14 ,
T_1 * V_15 , T_1 * V_16 )
{
T_1 V_17 [ 5 + 1 ] ;
T_1 * V_18 ;
T_1 * V_19 ;
F_3 ( V_17 , sizeof( V_17 ) , L_2 , V_12 % V_20 ) ;
if ( V_14 -> V_21 & V_22 ) {
V_18 = F_1 ( & V_14 -> V_23 ) ;
V_19 = F_5 ( V_15 , L_3 , V_17 , L_3 , V_18 , V_16 , NULL ) ;
F_6 ( V_18 ) ;
} else
V_19 = F_5 ( V_15 , L_3 , V_17 , V_16 , NULL ) ;
return V_19 ;
}
static T_4
F_7 ( const char * V_24 , T_1 * * V_15 , T_1 * * V_16 )
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
* V_15 = F_8 ( V_27 ) ;
V_25 [ 0 ] = '.' ;
* V_16 = F_8 ( V_25 ) ;
} else {
* V_15 = F_8 ( V_27 ) ;
* V_16 = NULL ;
}
F_6 ( V_27 ) ;
return TRUE ;
}
static T_4
F_9 ( char * V_30 )
{
char * V_31 ;
char * V_32 ;
if ( ++ V_33 >= V_34 ) {
fprintf ( V_28 , L_5 ) ;
return ( FALSE ) ;
}
if ( V_35 )
fprintf ( V_28 , L_6 , V_30 ) ;
if ( ( V_31 = strchr ( V_30 , '-' ) ) == NULL ) {
if ( V_35 )
fprintf ( V_28 , L_7 ) ;
V_36 [ V_33 ] . V_37 = 0 ;
V_36 [ V_33 ] . V_38 = atoi ( V_30 ) ;
if ( V_35 )
fprintf ( V_28 , L_8 , V_36 [ V_33 ] . V_38 ) ;
} else {
if ( V_35 )
fprintf ( V_28 , L_9 ) ;
V_32 = V_31 + 1 ;
V_36 [ V_33 ] . V_37 = 1 ;
V_36 [ V_33 ] . V_38 = atoi ( V_30 ) ;
V_36 [ V_33 ] . V_39 = atoi ( V_32 ) ;
if ( V_35 )
fprintf ( V_28 , L_10 , V_36 [ V_33 ] . V_38 ,
V_36 [ V_33 ] . V_39 ) ;
}
return ( TRUE ) ;
}
static int
F_10 ( int V_40 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 <= V_33 ; V_41 ++ ) {
if ( V_36 [ V_41 ] . V_37 ) {
if ( V_36 [ V_41 ] . V_38 <= V_40 && V_36 [ V_41 ] . V_39 >= V_40 )
return 1 ;
} else {
if ( V_40 == V_36 [ V_41 ] . V_38 )
return 1 ;
}
}
return 0 ;
}
static void
F_11 ( char * V_42 )
{
char * V_43 , * V_44 ;
long V_45 ;
T_5 V_46 ;
if ( ! V_42 )
return;
while ( * V_42 == ' ' || * V_42 == '\t' )
V_42 ++ ;
if ( * V_42 == '-' ) {
V_47 . V_48 = 1 ;
V_42 ++ ;
}
if ( * V_42 == '.' ) {
V_45 = 0 ;
V_43 = V_42 ;
} else {
V_45 = strtol ( V_42 , & V_43 , 10 ) ;
if ( V_43 == NULL || V_43 == V_42
|| V_45 == V_49 || V_45 == V_50 ) {
fprintf ( V_28 , L_11 ,
V_42 ) ;
exit ( 1 ) ;
}
if ( V_45 < 0 ) {
fprintf ( V_28 , L_11 ,
V_42 ) ;
exit ( 1 ) ;
}
}
V_47 . V_51 . V_52 = V_45 ;
if ( * V_43 != '\0' ) {
V_45 = strtol ( & ( V_43 [ 1 ] ) , & V_44 , 10 ) ;
if ( ( V_44 - & ( V_43 [ 1 ] ) ) > 6 ) {
V_43 [ 7 ] = 't' ;
V_45 = strtol ( & ( V_43 [ 1 ] ) , & V_44 , 10 ) ;
}
if ( * V_43 != '.' || V_44 == NULL || V_44 == V_43 || V_45 < 0
|| V_45 > V_53 || V_45 == V_49 || V_45 == V_50 ) {
fprintf ( V_28 , L_11 ,
V_42 ) ;
exit ( 1 ) ;
}
} else {
return;
}
if ( V_43 && V_44 ) {
V_46 = V_44 - V_43 - 1 ;
while( V_46 < 6 ) {
V_45 *= 10 ;
V_46 ++ ;
}
}
V_47 . V_51 . V_54 = ( int ) V_45 ;
}
static void
F_12 ( char * V_42 )
{
char * V_43 , * V_44 ;
long V_45 ;
T_5 V_46 ;
if ( ! V_42 )
return;
while ( * V_42 == ' ' || * V_42 == '\t' )
V_42 ++ ;
if ( * V_42 == '-' ) {
V_55 . V_48 = 1 ;
V_42 ++ ;
}
if ( * V_42 == '.' ) {
V_45 = 0 ;
V_43 = V_42 ;
} else {
V_45 = strtol ( V_42 , & V_43 , 10 ) ;
if ( V_43 == NULL || V_43 == V_42
|| V_45 == V_49 || V_45 == V_50 ) {
fprintf ( V_28 , L_11 ,
V_42 ) ;
exit ( 1 ) ;
}
if ( V_45 < 0 ) {
fprintf ( V_28 , L_11 ,
V_42 ) ;
exit ( 1 ) ;
}
}
V_55 . V_51 . V_52 = V_45 ;
if ( * V_43 != '\0' ) {
V_45 = strtol ( & ( V_43 [ 1 ] ) , & V_44 , 10 ) ;
if ( ( V_44 - & ( V_43 [ 1 ] ) ) > 6 ) {
V_43 [ 7 ] = 't' ;
V_45 = strtol ( & ( V_43 [ 1 ] ) , & V_44 , 10 ) ;
}
if ( * V_43 != '.' || V_44 == NULL || V_44 == V_43 || V_45 < 0
|| V_45 > V_53 || V_45 == V_49 || V_45 == V_50 ) {
fprintf ( V_28 , L_11 ,
V_42 ) ;
exit ( 1 ) ;
}
} else {
return;
}
if ( V_43 && V_44 ) {
V_46 = V_44 - V_43 - 1 ;
while( V_46 < 6 ) {
V_45 *= 10 ;
V_46 ++ ;
}
}
V_55 . V_51 . V_54 = ( int ) V_45 ;
}
static void
F_13 ( char * V_42 )
{
char * V_43 , * V_44 ;
long V_45 ;
T_5 V_46 ;
if ( ! V_42 )
return;
while ( * V_42 == ' ' || * V_42 == '\t' )
V_42 ++ ;
if ( * V_42 == '-' )
V_42 ++ ;
if ( * V_42 == '.' ) {
V_45 = 0 ;
V_43 = V_42 ;
} else {
V_45 = strtol ( V_42 , & V_43 , 10 ) ;
if ( V_43 == NULL || V_43 == V_42
|| V_45 == V_49 || V_45 == V_50 ) {
fprintf ( V_28 , L_12 ,
V_42 ) ;
exit ( 1 ) ;
}
if ( V_45 < 0 ) {
fprintf ( V_28 , L_13 ,
V_42 ) ;
exit ( 1 ) ;
}
}
V_56 . V_5 = V_45 ;
if ( * V_43 != '\0' ) {
V_45 = strtol ( & ( V_43 [ 1 ] ) , & V_44 , 10 ) ;
if ( ( V_44 - & ( V_43 [ 1 ] ) ) > 9 ) {
V_43 [ 10 ] = 't' ;
V_45 = strtol ( & ( V_43 [ 1 ] ) , & V_44 , 10 ) ;
}
if ( * V_43 != '.' || V_44 == NULL || V_44 == V_43 || V_45 < 0
|| V_45 > V_57 || V_45 == V_49 || V_45 == V_50 ) {
fprintf ( V_28 , L_14 ,
V_42 ) ;
exit ( 1 ) ;
}
} else {
return;
}
if ( V_43 && V_44 ) {
V_46 = V_44 - V_43 - 1 ;
while( V_46 < 9 ) {
V_45 *= 10 ;
V_46 ++ ;
}
}
V_56 . V_58 = ( int ) V_45 ;
}
static T_4
F_14 ( T_6 * V_59 , T_7 V_60 ) {
int V_41 ;
T_8 V_61 ;
V_62 ++ ;
if ( V_62 >= V_63 )
V_62 = 0 ;
F_15 ( & V_61 ) ;
F_16 ( & V_61 , V_59 , V_60 ) ;
F_17 ( & V_61 , V_64 [ V_62 ] . V_65 ) ;
V_64 [ V_62 ] . V_60 = V_60 ;
for ( V_41 = 0 ; V_41 < V_63 ; V_41 ++ ) {
if ( V_41 == V_62 )
continue;
if ( V_64 [ V_41 ] . V_60 == V_64 [ V_62 ] . V_60
&& memcmp ( V_64 [ V_41 ] . V_65 , V_64 [ V_62 ] . V_65 , 16 ) == 0 ) {
return TRUE ;
}
}
return FALSE ;
}
static T_4
F_18 ( T_6 * V_59 , T_7 V_60 , const T_2 * V_66 ) {
int V_41 ;
T_8 V_61 ;
V_62 ++ ;
if ( V_62 >= V_63 )
V_62 = 0 ;
F_15 ( & V_61 ) ;
F_16 ( & V_61 , V_59 , V_60 ) ;
F_17 ( & V_61 , V_64 [ V_62 ] . V_65 ) ;
V_64 [ V_62 ] . V_60 = V_60 ;
V_64 [ V_62 ] . time . V_5 = V_66 -> V_5 ;
V_64 [ V_62 ] . time . V_58 = V_66 -> V_58 ;
for ( V_41 = V_62 - 1 ; ; V_41 -- ) {
T_2 V_67 ;
int V_68 ;
if ( V_41 < 0 )
V_41 = V_63 - 1 ;
if ( V_41 == V_62 ) {
break;
}
if ( F_19 ( & ( V_64 [ V_41 ] . time ) ) ) {
break;
}
F_20 ( & V_67 , V_66 , & V_64 [ V_41 ] . time ) ;
if ( V_67 . V_5 < 0 || V_67 . V_58 < 0 ) {
continue;
}
V_68 = F_21 ( & V_67 , & V_56 ) ;
if ( V_68 > 0 ) {
break;
} else if ( V_64 [ V_41 ] . V_60 == V_64 [ V_62 ] . V_60
&& memcmp ( V_64 [ V_41 ] . V_65 , V_64 [ V_62 ] . V_65 , 16 ) == 0 ) {
return TRUE ;
}
}
return FALSE ;
}
static void
F_22 ( T_4 V_69 )
{
T_9 * V_70 ;
if ( ! V_69 )
V_70 = stdout ;
else
V_70 = V_28 ;
fprintf ( V_70 , L_15
#ifdef F_23
L_16 F_23 L_17 V_71 L_18
#endif
L_19 , V_72 ) ;
fprintf ( V_70 , L_20 ) ;
fprintf ( V_70 , L_21 ) ;
fprintf ( V_70 , L_19 ) ;
fprintf ( V_70 , L_22 ) ;
fprintf ( V_70 , L_19 ) ;
fprintf ( V_70 , L_23 ) ;
fprintf ( V_70 , L_24 ) ;
fprintf ( V_70 , L_19 ) ;
fprintf ( V_70 , L_25 ) ;
fprintf ( V_70 , L_26 ) ;
fprintf ( V_70 , L_27 ) ;
fprintf ( V_70 , L_28 ) ;
fprintf ( V_70 , L_29 ) ;
fprintf ( V_70 , L_30 ) ;
fprintf ( V_70 , L_19 ) ;
fprintf ( V_70 , L_31 ) ;
fprintf ( V_70 , L_32 , V_73 ) ;
fprintf ( V_70 , L_33 ) ;
fprintf ( V_70 , L_34 , V_74 ) ;
fprintf ( V_70 , L_35 ) ;
fprintf ( V_70 , L_36 ) ;
fprintf ( V_70 , L_37 ) ;
fprintf ( V_70 , L_38 ) ;
fprintf ( V_70 , L_39 ) ;
fprintf ( V_70 , L_40 ) ;
fprintf ( V_70 , L_19 ) ;
fprintf ( V_70 , L_41 ) ;
fprintf ( V_70 , L_42 ) ;
fprintf ( V_70 , L_43 ) ;
fprintf ( V_70 , L_44 ) ;
fprintf ( V_70 , L_19 ) ;
fprintf ( V_70 , L_45 ) ;
fprintf ( V_70 , L_46 ) ;
fprintf ( V_70 , L_47 ) ;
fprintf ( V_70 , L_48 ) ;
fprintf ( V_70 , L_49 ) ;
fprintf ( V_70 , L_50 ) ;
fprintf ( V_70 , L_51 ) ;
fprintf ( V_70 , L_52 ) ;
fprintf ( V_70 , L_53 ) ;
fprintf ( V_70 , L_54 ) ;
fprintf ( V_70 , L_55 ) ;
fprintf ( V_70 , L_56 ) ;
fprintf ( V_70 , L_57 ) ;
fprintf ( V_70 , L_58 ) ;
fprintf ( V_70 , L_59 ) ;
fprintf ( V_70 , L_60 ) ;
fprintf ( V_70 , L_61 ) ;
fprintf ( V_70 , L_62 ) ;
fprintf ( V_70 , L_63 ) ;
fprintf ( V_70 , L_64 ) ;
fprintf ( V_70 , L_65 ) ;
fprintf ( V_70 , L_66 ) ;
fprintf ( V_70 , L_67 ) ;
fprintf ( V_70 , L_68 ) ;
fprintf ( V_70 , L_19 ) ;
fprintf ( V_70 , L_69 ) ;
fprintf ( V_70 , L_70 ) ;
fprintf ( V_70 , L_71 ) ;
fprintf ( V_70 , L_72 ) ;
fprintf ( V_70 , L_73 ) ;
fprintf ( V_70 , L_74 ) ;
fprintf ( V_70 , L_75 ) ;
fprintf ( V_70 , L_76 ) ;
fprintf ( V_70 , L_77 ) ;
fprintf ( V_70 , L_78 ) ;
fprintf ( V_70 , L_79 ) ;
fprintf ( V_70 , L_80 ) ;
fprintf ( V_70 , L_19 ) ;
fprintf ( V_70 , L_81 ) ;
fprintf ( V_70 , L_82 ) ;
fprintf ( V_70 , L_83 ) ;
fprintf ( V_70 , L_84 ) ;
fprintf ( V_70 , L_85 ) ;
fprintf ( V_70 , L_86 ) ;
fprintf ( V_70 , L_19 ) ;
}
static T_10
F_24 ( T_11 V_75 , T_11 V_76 )
{
return strcmp ( ( ( const struct V_77 * ) V_75 ) -> V_78 ,
( ( const struct V_77 * ) V_76 ) -> V_78 ) ;
}
static T_10
F_25 ( T_11 V_75 , T_11 V_76 )
{
return F_26 ( ( ( const struct V_77 * ) V_75 ) -> V_78 ,
( ( const struct V_77 * ) V_76 ) -> V_78 ) ;
}
static void
F_27 ( T_12 V_79 , T_12 T_13 V_80 )
{
fprintf ( V_28 , L_87 ,
( (struct V_77 * ) V_79 ) -> V_78 ,
( (struct V_77 * ) V_79 ) -> V_81 ) ;
}
static void
F_28 ( void ) {
int V_41 ;
struct V_77 * V_82 ;
T_14 * V_83 = NULL ;
V_82 = F_29 ( struct V_77 , V_84 ) ;
fprintf ( V_28 , L_88 ) ;
for ( V_41 = 0 ; V_41 < V_84 ; V_41 ++ ) {
if ( F_30 ( V_41 ) ) {
V_82 [ V_41 ] . V_78 = F_31 ( V_41 ) ;
V_82 [ V_41 ] . V_81 = F_32 ( V_41 ) ;
V_83 = F_33 ( V_83 , & V_82 [ V_41 ] , F_24 ) ;
}
}
F_34 ( V_83 , F_27 , NULL ) ;
F_35 ( V_83 ) ;
F_6 ( V_82 ) ;
}
static void
F_36 ( void ) {
int V_41 ;
struct V_77 * V_85 ;
T_14 * V_83 = NULL ;
V_85 = (struct V_77 * ) F_2 ( sizeof( struct V_77 ) * V_86 ) ;
fprintf ( V_28 , L_89 ) ;
for ( V_41 = 0 ; V_41 < V_86 ; V_41 ++ ) {
V_85 [ V_41 ] . V_78 = F_37 ( V_41 ) ;
if ( V_85 [ V_41 ] . V_78 != NULL ) {
V_85 [ V_41 ] . V_81 = F_38 ( V_41 ) ;
V_83 = F_33 ( V_83 , & V_85 [ V_41 ] , F_25 ) ;
}
}
F_34 ( V_83 , F_27 , NULL ) ;
F_35 ( V_83 ) ;
F_6 ( V_85 ) ;
}
static void
F_39 ( const char * T_15 V_80 , T_16 T_17 V_80 )
{
}
int
main ( int V_87 , char * V_88 [] )
{
T_18 * V_89 ;
int V_41 , V_90 , V_91 ;
T_1 * V_92 ;
int V_93 ;
char * V_94 ;
T_7 V_95 = 0 ;
T_19 V_96 = { 0 , 0 , 0 , 0 , 0 , 0 } ;
T_4 V_97 = FALSE ;
T_20 * V_98 = NULL ;
unsigned int V_99 = 1 ;
unsigned int V_100 = 0 ;
T_21 V_101 ;
int V_102 ;
T_6 * V_4 ;
T_7 V_103 = 0 ;
int V_104 = 0 ;
int V_105 = 0 ;
char * V_106 = NULL ;
T_4 V_107 ;
int V_108 = 0 ;
int V_109 = 0 ;
T_2 V_110 ;
T_1 * V_15 = NULL ;
T_1 * V_16 = NULL ;
const struct V_13 * V_14 ;
struct V_13 V_111 ;
T_22 * V_112 ;
T_23 * V_113 ;
#ifdef F_40
char * V_114 ;
#endif
#ifdef F_41
F_42 ( V_87 , V_88 ) ;
F_43 () ;
#endif
F_44 () ;
F_45 () ;
#ifdef F_40
if ( ( V_114 = F_46 ( V_88 [ 0 ] , main ) ) ) {
F_47 ( L_90 , V_114 ) ;
F_6 ( V_114 ) ;
} else {
F_48 () ;
F_49 ( F_39 , NULL , NULL , NULL ) ;
F_50 () ;
F_51 () ;
}
#endif
while ( ( V_93 = F_52 ( V_87 , V_88 , L_91 ) ) != - 1 ) {
switch ( V_93 ) {
case 'A' :
{
struct V_2 V_115 ;
memset ( & V_115 , 0 , sizeof( struct V_2 ) ) ;
if ( ! strptime ( V_116 , L_92 , & V_115 ) ) {
fprintf ( V_28 , L_93 ,
V_116 ) ;
exit ( 1 ) ;
}
V_117 = TRUE ;
V_115 . V_118 = - 1 ;
V_119 = mktime ( & V_115 ) ;
break;
}
case 'B' :
{
struct V_2 V_120 ;
memset ( & V_120 , 0 , sizeof( struct V_2 ) ) ;
if ( ! strptime ( V_116 , L_92 , & V_120 ) ) {
fprintf ( V_28 , L_93 ,
V_116 ) ;
exit ( 1 ) ;
}
V_117 = TRUE ;
V_120 . V_118 = - 1 ;
V_121 = mktime ( & V_120 ) ;
break;
}
case 'c' :
V_104 = ( int ) strtol ( V_116 , & V_94 , 10 ) ;
if ( V_94 == V_116 || * V_94 != '\0' ) {
fprintf ( V_28 , L_94 ,
V_116 ) ;
exit ( 1 ) ;
}
if ( V_104 <= 0 ) {
fprintf ( V_28 , L_95 ,
V_104 ) ;
exit ( 1 ) ;
}
break;
case 'C' :
{
int V_122 = 0 , V_123 = 0 ;
switch ( sscanf ( V_116 , L_96 , & V_123 , & V_122 ) ) {
case 1 :
V_122 = V_123 ;
V_123 = 0 ;
break;
case 2 :
break;
default:
fprintf ( V_28 , L_97 ,
V_116 ) ;
exit ( 1 ) ;
break;
}
if ( V_122 > 0 ) {
V_96 . V_124 += V_122 ;
if ( V_123 > 0 )
V_96 . V_125 += V_123 ;
else
V_96 . V_126 += V_123 ;
} else if ( V_122 < 0 ) {
V_96 . V_127 += V_122 ;
if ( V_123 > 0 )
V_96 . V_128 += V_123 ;
else
V_96 . V_129 += V_123 ;
}
break;
}
case 'd' :
V_130 = TRUE ;
V_131 = FALSE ;
V_63 = V_73 ;
break;
case 'D' :
V_130 = TRUE ;
V_131 = FALSE ;
V_63 = ( int ) strtol ( V_116 , & V_94 , 10 ) ;
if ( V_94 == V_116 || * V_94 != '\0' ) {
fprintf ( V_28 , L_98 ,
V_116 ) ;
exit ( 1 ) ;
}
if ( V_63 < 0 || V_63 > V_74 ) {
fprintf ( V_28 , L_99 ,
V_63 , V_74 ) ;
exit ( 1 ) ;
}
break;
case 'E' :
V_132 = strtod ( V_116 , & V_94 ) ;
if ( V_94 == V_116 || V_132 < 0.0 || V_132 > 1.0 ) {
fprintf ( V_28 , L_100 ,
V_116 ) ;
exit ( 1 ) ;
}
srand ( ( unsigned int ) ( time ( NULL ) + F_53 () ) ) ;
break;
case 'F' :
V_133 = F_54 ( V_116 ) ;
if ( V_133 < 0 ) {
fprintf ( V_28 , L_101 ,
V_116 ) ;
F_28 () ;
exit ( 1 ) ;
}
break;
case 'h' :
F_22 ( FALSE ) ;
exit ( 0 ) ;
break;
case 'i' :
V_108 = atoi ( V_116 ) ;
if ( V_108 <= 0 ) {
fprintf ( V_28 , L_102 ,
V_116 ) ;
exit ( 1 ) ;
}
break;
case 'L' :
V_97 = TRUE ;
break;
case 'r' :
V_134 = ! V_134 ;
break;
case 's' :
V_95 = ( T_7 ) strtol ( V_116 , & V_94 , 10 ) ;
if ( V_94 == V_116 || * V_94 != '\0' ) {
fprintf ( V_28 , L_103 ,
V_116 ) ;
exit ( 1 ) ;
}
break;
case 'S' :
F_12 ( V_116 ) ;
V_135 = TRUE ;
break;
case 't' :
F_11 ( V_116 ) ;
break;
case 'T' :
V_136 = F_55 ( V_116 ) ;
if ( V_136 < 0 ) {
fprintf ( V_28 , L_104 ,
V_116 ) ;
F_36 () ;
exit ( 1 ) ;
}
break;
case 'v' :
V_35 = ! V_35 ;
break;
case 'w' :
V_130 = FALSE ;
V_131 = TRUE ;
V_63 = V_74 ;
F_13 ( V_116 ) ;
break;
case '?' :
switch( V_137 ) {
case 'F' :
F_28 () ;
break;
case 'T' :
F_36 () ;
break;
default:
F_22 ( TRUE ) ;
break;
}
exit ( 1 ) ;
break;
}
}
#ifdef F_56
fprintf ( V_28 , L_105 , V_138 , V_87 ) ;
#endif
if ( ( V_87 - V_138 ) < 1 ) {
F_22 ( TRUE ) ;
exit ( 1 ) ;
}
if ( V_117 && ! V_121 ) {
struct V_2 V_120 ;
memset ( & V_120 , 0 , sizeof( struct V_2 ) ) ;
V_120 . V_6 = 135 ;
V_120 . V_8 = 31 ;
V_120 . V_7 = 11 ;
V_121 = mktime ( & V_120 ) ;
}
F_57 ( & V_110 ) ;
if ( V_119 > V_121 ) {
fprintf ( V_28 , L_106 ) ;
exit ( 1 ) ;
}
if ( V_104 > 0 && V_108 > 0 ) {
fprintf ( V_28 , L_107 ) ;
fprintf ( V_28 , L_108 ) ;
exit ( 1 ) ;
}
V_89 = F_58 ( V_88 [ V_138 ] , V_139 , & V_91 , & V_92 , FALSE ) ;
if ( ! V_89 ) {
fprintf ( V_28 , L_109 , V_88 [ V_138 ] ,
F_59 ( V_91 ) ) ;
switch ( V_91 ) {
case V_140 :
case V_141 :
case V_142 :
fprintf ( V_28 , L_110 , V_92 ) ;
F_6 ( V_92 ) ;
break;
}
exit ( 2 ) ;
}
if ( V_35 ) {
fprintf ( V_28 , L_111 , V_88 [ V_138 ] ,
F_32 ( F_60 ( V_89 ) ) ) ;
}
V_113 = F_61 ( V_89 ) ;
V_112 = F_62 ( V_89 ) ;
if ( ( V_87 - V_138 ) >= 2 ) {
if ( V_136 == - 2 )
V_136 = F_63 ( V_89 ) ;
for ( V_41 = V_138 + 2 ; V_41 < V_87 ; V_41 ++ )
if ( F_9 ( V_88 [ V_41 ] ) == FALSE )
break;
if ( V_130 || V_131 ) {
for ( V_41 = 0 ; V_41 < V_63 ; V_41 ++ ) {
memset ( & V_64 [ V_41 ] . V_65 , 0 , 16 ) ;
V_64 [ V_41 ] . V_60 = 0 ;
F_57 ( & V_64 [ V_41 ] . time ) ;
}
}
while ( F_64 ( V_89 , & V_91 , & V_92 , & V_101 ) ) {
V_103 ++ ;
V_14 = F_65 ( V_89 ) ;
if ( V_103 == 1 ) {
if ( V_104 > 0 || V_108 > 0 ) {
if ( ! F_7 ( V_88 [ V_138 + 1 ] , & V_15 , & V_16 ) )
exit ( 2 ) ;
V_106 = F_4 ( V_109 ++ , V_14 , V_15 , V_16 ) ;
} else {
V_106 = F_8 ( V_88 [ V_138 + 1 ] ) ;
}
F_66 ( V_106 ) ;
if ( V_113 -> V_143 == NULL ) {
V_113 -> V_143 = L_112 V_72 ;
}
V_98 = F_67 ( V_106 , V_133 , V_136 ,
V_95 ? F_68 ( V_95 , F_69 ( V_89 ) ) : F_69 ( V_89 ) ,
FALSE , V_113 , V_112 , & V_91 ) ;
if ( V_98 == NULL ) {
fprintf ( V_28 , L_113 ,
V_106 , F_59 ( V_91 ) ) ;
exit ( 2 ) ;
}
}
V_4 = F_70 ( V_89 ) ;
if ( V_14 -> V_21 & V_22 ) {
if ( F_19 ( & V_110 ) ) {
V_110 . V_5 = V_14 -> V_23 . V_5 ;
V_110 . V_58 = V_14 -> V_23 . V_58 ;
}
if ( V_108 > 0 ) {
while ( ( V_14 -> V_23 . V_5 - V_110 . V_5 > V_108 )
|| ( V_14 -> V_23 . V_5 - V_110 . V_5 == V_108
&& V_14 -> V_23 . V_58 >= V_110 . V_58 ) ) {
if ( ! F_71 ( V_98 , & V_91 ) ) {
fprintf ( V_28 , L_114 ,
V_106 , F_59 ( V_91 ) ) ;
exit ( 2 ) ;
}
V_110 . V_5 = V_110 . V_5 + V_108 ;
F_6 ( V_106 ) ;
V_106 = F_4 ( V_109 ++ , V_14 , V_15 , V_16 ) ;
F_66 ( V_106 ) ;
if ( V_35 )
fprintf ( V_28 , L_115 , V_106 ) ;
V_98 = F_67 ( V_106 , V_133 , V_136 ,
V_95 ? F_68 ( V_95 , F_69 ( V_89 ) ) : F_69 ( V_89 ) ,
FALSE , V_113 , V_112 , & V_91 ) ;
if ( V_98 == NULL ) {
fprintf ( V_28 , L_113 ,
V_106 , F_59 ( V_91 ) ) ;
exit ( 2 ) ;
}
}
}
}
if ( V_104 > 0 ) {
if ( V_105 > 0 && V_105 % V_104 == 0 ) {
if ( ! F_71 ( V_98 , & V_91 ) ) {
fprintf ( V_28 , L_114 ,
V_106 , F_59 ( V_91 ) ) ;
exit ( 2 ) ;
}
F_6 ( V_106 ) ;
V_106 = F_4 ( V_109 ++ , V_14 , V_15 , V_16 ) ;
F_66 ( V_106 ) ;
if ( V_35 )
fprintf ( V_28 , L_115 , V_106 ) ;
V_98 = F_67 ( V_106 , V_133 , V_136 ,
V_95 ? F_68 ( V_95 , F_69 ( V_89 ) ) : F_69 ( V_89 ) ,
FALSE , V_113 , V_112 , & V_91 ) ;
if ( V_98 == NULL ) {
fprintf ( V_28 , L_113 ,
V_106 , F_59 ( V_91 ) ) ;
exit ( 2 ) ;
}
}
}
if ( V_117 ) {
if ( V_14 -> V_21 & V_22 )
V_107 = ( V_14 -> V_23 . V_5 >= V_119 ) && ( V_14 -> V_23 . V_5 < V_121 ) ;
else
V_107 = FALSE ;
} else {
V_107 = TRUE ;
}
if ( V_107 && ( ( ! F_10 ( V_99 ) && ! V_134 )
|| ( F_10 ( V_99 ) && V_134 ) ) ) {
if ( V_35 && ! V_130 && ! V_131 )
fprintf ( V_28 , L_116 , V_99 ) ;
V_14 = F_65 ( V_89 ) ;
if ( V_95 != 0 ) {
if ( V_14 -> V_144 > V_95 ) {
V_111 = * V_14 ;
V_111 . V_144 = V_95 ;
V_14 = & V_111 ;
}
if ( V_97 && V_14 -> V_60 > V_95 ) {
V_111 = * V_14 ;
V_111 . V_60 = V_95 ;
V_14 = & V_111 ;
}
}
V_111 = * V_14 ;
F_72 ( V_96 , & V_111 , V_14 , & V_4 , V_97 ) ;
V_14 = & V_111 ;
if ( V_14 -> V_21 & V_22 ) {
if ( V_135 ) {
if ( V_145 . V_5 || V_145 . V_58 ) {
if ( ! V_55 . V_48 ) {
T_2 V_66 ;
T_2 V_67 ;
V_66 . V_5 = V_14 -> V_23 . V_5 ;
V_66 . V_58 = V_14 -> V_23 . V_58 ;
F_20 ( & V_67 , & V_66 , & V_145 ) ;
if ( V_67 . V_5 < 0 || V_67 . V_58 < 0 ) {
V_111 = * V_14 ;
V_111 . V_23 . V_5 = V_145 . V_5 + V_55 . V_51 . V_52 ;
V_111 . V_23 . V_58 = V_145 . V_58 ;
if ( V_111 . V_23 . V_58 + V_55 . V_51 . V_54 * 1000 > V_53 * 1000 ) {
V_111 . V_23 . V_5 ++ ;
V_111 . V_23 . V_58 += ( V_55 . V_51 . V_54 - V_53 ) * 1000 ;
} else {
V_111 . V_23 . V_58 += V_55 . V_51 . V_54 * 1000 ;
}
V_14 = & V_111 ;
}
} else {
V_111 = * V_14 ;
V_111 . V_23 . V_5 = V_145 . V_5 + V_55 . V_51 . V_52 ;
V_111 . V_23 . V_58 = V_145 . V_58 ;
if ( V_111 . V_23 . V_58 + V_55 . V_51 . V_54 * 1000 > V_53 * 1000 ) {
V_111 . V_23 . V_5 ++ ;
V_111 . V_23 . V_58 += ( V_55 . V_51 . V_54 - V_53 ) * 1000 ;
} else {
V_111 . V_23 . V_58 += V_55 . V_51 . V_54 * 1000 ;
}
V_14 = & V_111 ;
}
}
V_145 . V_5 = V_14 -> V_23 . V_5 ;
V_145 . V_58 = V_14 -> V_23 . V_58 ;
}
if ( V_14 -> V_23 . V_5 > 0 && V_47 . V_51 . V_52 != 0 ) {
V_111 = * V_14 ;
if ( V_47 . V_48 )
V_111 . V_23 . V_5 -= V_47 . V_51 . V_52 ;
else
V_111 . V_23 . V_5 += V_47 . V_51 . V_52 ;
V_14 = & V_111 ;
}
if ( V_14 -> V_23 . V_5 > 0 && V_47 . V_51 . V_54 != 0 ) {
V_111 = * V_14 ;
if ( V_47 . V_48 ) {
if ( V_111 . V_23 . V_58 / 1000 < V_47 . V_51 . V_54 ) {
V_111 . V_23 . V_5 -- ;
V_111 . V_23 . V_58 += V_53 * 1000 ;
}
V_111 . V_23 . V_58 -= V_47 . V_51 . V_54 * 1000 ;
} else {
if ( V_111 . V_23 . V_58 + V_47 . V_51 . V_54 * 1000 > V_53 * 1000 ) {
V_111 . V_23 . V_5 ++ ;
V_111 . V_23 . V_58 += ( V_47 . V_51 . V_54 - V_53 ) * 1000 ;
} else {
V_111 . V_23 . V_58 += V_47 . V_51 . V_54 * 1000 ;
}
}
V_14 = & V_111 ;
}
}
if ( V_130 ) {
if ( F_14 ( V_4 , V_14 -> V_144 ) ) {
if ( V_35 ) {
fprintf ( V_28 , L_117 ,
V_99 , V_14 -> V_144 ) ;
for ( V_41 = 0 ; V_41 < 16 ; V_41 ++ )
fprintf ( V_28 , L_118 ,
( unsigned char ) V_64 [ V_62 ] . V_65 [ V_41 ] ) ;
fprintf ( V_28 , L_19 ) ;
}
V_100 ++ ;
V_99 ++ ;
continue;
} else {
if ( V_35 ) {
fprintf ( V_28 , L_119 ,
V_99 , V_14 -> V_144 ) ;
for ( V_41 = 0 ; V_41 < 16 ; V_41 ++ )
fprintf ( V_28 , L_118 ,
( unsigned char ) V_64 [ V_62 ] . V_65 [ V_41 ] ) ;
fprintf ( V_28 , L_19 ) ;
}
}
}
if ( V_14 -> V_21 & V_22 ) {
if ( V_131 ) {
T_2 V_66 ;
V_66 . V_5 = V_14 -> V_23 . V_5 ;
V_66 . V_58 = V_14 -> V_23 . V_58 ;
if ( F_18 ( V_4 , V_14 -> V_144 , & V_66 ) ) {
if ( V_35 ) {
fprintf ( V_28 , L_117 ,
V_99 , V_14 -> V_144 ) ;
for ( V_41 = 0 ; V_41 < 16 ; V_41 ++ )
fprintf ( V_28 , L_118 ,
( unsigned char ) V_64 [ V_62 ] . V_65 [ V_41 ] ) ;
fprintf ( V_28 , L_19 ) ;
}
V_100 ++ ;
V_99 ++ ;
continue;
} else {
if ( V_35 ) {
fprintf ( V_28 , L_119 ,
V_99 , V_14 -> V_144 ) ;
for ( V_41 = 0 ; V_41 < 16 ; V_41 ++ )
fprintf ( V_28 , L_118 ,
( unsigned char ) V_64 [ V_62 ] . V_65 [ V_41 ] ) ;
fprintf ( V_28 , L_19 ) ;
}
}
}
}
if ( V_132 > 0.0 ) {
int V_146 = 0 ;
if ( F_60 ( V_89 ) == V_147 )
V_146 = F_73 ( V_4 ) ;
for ( V_41 = V_146 ; V_41 < ( int ) V_14 -> V_144 ; V_41 ++ ) {
if ( rand () <= V_132 * V_148 ) {
V_102 = rand () / ( V_148 / V_149 + 1 ) ;
if ( V_102 < V_150 ) {
V_4 [ V_41 ] ^= 1 << ( rand () / ( V_148 / 8 + 1 ) ) ;
V_102 = V_149 ;
} else {
V_102 -= V_151 ;
}
if ( V_102 < V_151 ) {
V_4 [ V_41 ] = rand () / ( V_148 / 255 + 1 ) ;
V_102 = V_149 ;
} else {
V_102 -= V_151 ;
}
if ( V_102 < V_152 ) {
V_4 [ V_41 ] = V_153 [ rand () / ( V_148 / V_154 + 1 ) ] ;
V_102 = V_149 ;
} else {
V_102 -= V_152 ;
}
if ( V_102 < V_155 ) {
if ( ( unsigned int ) V_41 < V_14 -> V_144 - 2 )
F_74 ( ( char * ) & V_4 [ V_41 ] , L_120 , 2 ) ;
V_102 = V_149 ;
} else {
V_102 -= V_155 ;
}
if ( V_102 < V_156 ) {
for ( V_90 = V_41 ; V_90 < ( int ) V_14 -> V_144 ; V_90 ++ )
V_4 [ V_90 ] = 0xAA ;
V_41 = V_14 -> V_144 ;
}
}
}
}
if ( ! F_75 ( V_98 , V_14 , V_4 , & V_91 ) ) {
switch ( V_91 ) {
case V_141 :
fprintf ( V_28 ,
L_121 ,
V_103 , V_88 [ V_138 ] ,
F_32 ( V_133 ) ) ;
break;
case V_157 :
fprintf ( V_28 ,
L_122 ,
V_103 , V_88 [ V_138 ] ,
F_32 ( V_133 ) ) ;
break;
default:
fprintf ( V_28 , L_114 ,
V_106 , F_59 ( V_91 ) ) ;
break;
}
exit ( 2 ) ;
}
V_105 ++ ;
}
V_99 ++ ;
}
F_6 ( V_15 ) ;
F_6 ( V_16 ) ;
if ( V_91 != 0 ) {
fprintf ( V_28 ,
L_123 ,
V_88 [ V_138 ] , F_59 ( V_91 ) ) ;
switch ( V_91 ) {
case V_140 :
case V_141 :
case V_142 :
fprintf ( V_28 , L_110 , V_92 ) ;
F_6 ( V_92 ) ;
break;
}
}
if ( ! V_98 ) {
F_6 ( V_106 ) ;
V_106 = F_8 ( V_88 [ V_138 + 1 ] ) ;
V_98 = F_67 ( V_106 , V_133 , V_136 ,
V_95 ? F_68 ( V_95 , F_69 ( V_89 ) ) : F_69 ( V_89 ) ,
FALSE , V_113 , V_112 , & V_91 ) ;
if ( V_98 == NULL ) {
fprintf ( V_28 , L_113 ,
V_106 , F_59 ( V_91 ) ) ;
exit ( 2 ) ;
}
}
F_6 ( V_112 ) ;
V_112 = NULL ;
if ( ! F_71 ( V_98 , & V_91 ) ) {
fprintf ( V_28 , L_114 , V_106 ,
F_59 ( V_91 ) ) ;
exit ( 2 ) ;
}
F_6 ( V_113 ) ;
F_6 ( V_106 ) ;
}
if ( V_130 ) {
fprintf ( V_28 , L_124 ,
V_99 - 1 , F_76 ( V_99 - 1 , L_125 , L_126 ) , V_100 ,
F_76 ( V_100 , L_125 , L_126 ) , V_63 ) ;
} else if ( V_131 ) {
fprintf ( V_28 , L_127 ,
V_99 - 1 , F_76 ( V_99 - 1 , L_125 , L_126 ) , V_100 ,
F_76 ( V_100 , L_125 , L_126 ) ,
( long ) V_56 . V_5 ,
( long int ) V_56 . V_58 ) ;
}
return 0 ;
}
static int
F_73 ( T_6 * V_4 )
{
int V_158 = 0 ;
for ( V_158 = 0 ; V_4 [ V_158 ] != '\0' ; V_158 ++ ) ;
V_158 ++ ;
V_158 ++ ;
for (; V_4 [ V_158 ] != '\0' ; V_158 ++ ) ;
V_158 ++ ;
for (; V_4 [ V_158 ] != '\0' ; V_158 ++ ) ;
V_158 ++ ;
for (; V_4 [ V_158 ] != '\0' ; V_158 ++ ) ;
V_158 ++ ;
for (; V_4 [ V_158 ] != '\0' ; V_158 ++ ) ;
V_158 ++ ;
V_158 += 2 ;
return V_158 ;
}
static void
F_72 ( T_19 V_96 , struct V_13 * V_159 ,
const struct V_13 * V_160 , T_6 * * V_4 ,
T_4 V_97 )
{
if ( V_160 -> V_161 != V_162 )
return;
if ( V_96 . V_124 == 0 )
V_96 . V_125 = V_96 . V_126 = 0 ;
if ( V_96 . V_127 == 0 )
V_96 . V_128 = V_96 . V_129 = 0 ;
if ( V_96 . V_126 < 0 ) {
V_96 . V_125 += V_160 -> V_144 + V_96 . V_126 ;
V_96 . V_126 = 0 ;
}
if ( V_96 . V_128 > 0 ) {
V_96 . V_129 += V_96 . V_128 - V_160 -> V_144 ;
V_96 . V_128 = 0 ;
}
if ( V_96 . V_124 && V_96 . V_127 ) {
if ( V_96 . V_125 > ( ( int ) V_160 -> V_144 + V_96 . V_129 ) ) {
int V_163 , V_164 ;
V_164 = V_160 -> V_144 + V_96 . V_129 + V_96 . V_127 ;
V_163 = - V_96 . V_127 ;
V_96 . V_129 = V_96 . V_124 + V_96 . V_125 - V_160 -> V_144 ;
V_96 . V_127 = - V_96 . V_124 ;
V_96 . V_124 = V_163 ;
V_96 . V_125 = V_164 ;
}
}
if ( V_160 -> V_144 < ( T_7 ) ( V_96 . V_125 - V_96 . V_129 ) ) {
V_96 . V_124 = 0 ;
V_96 . V_127 = 0 ;
}
if ( ( T_7 ) ( V_96 . V_124 - V_96 . V_127 ) >
( V_160 -> V_144 - ( T_7 ) ( V_96 . V_125 - V_96 . V_129 ) ) ) {
V_96 . V_124 = V_160 -> V_144 - ( V_96 . V_125 - V_96 . V_129 ) ;
V_96 . V_127 = 0 ;
}
if ( V_96 . V_124 > 0 ) {
* V_159 = * V_160 ;
if ( V_96 . V_125 > 0 ) {
memmove ( * V_4 + V_96 . V_125 ,
* V_4 + V_96 . V_125 + V_96 . V_124 ,
V_159 -> V_144 - V_96 . V_124 ) ;
} else {
* V_4 += V_96 . V_124 ;
}
V_159 -> V_144 -= V_96 . V_124 ;
if ( V_97 ) {
if ( V_160 -> V_60 > ( T_7 ) V_96 . V_124 )
V_159 -> V_60 -= V_96 . V_124 ;
else
V_159 -> V_60 = 0 ;
}
V_160 = V_159 ;
}
if ( V_96 . V_127 < 0 ) {
* V_159 = * V_160 ;
if ( V_96 . V_129 < 0 ) {
memmove ( * V_4 + ( T_10 ) V_159 -> V_144 + ( V_96 . V_127 + V_96 . V_129 ) ,
* V_4 + ( T_10 ) V_159 -> V_144 + V_96 . V_129 ,
- V_96 . V_129 ) ;
}
V_159 -> V_144 += V_96 . V_127 ;
if ( V_97 ) {
if ( ( ( signed int ) V_160 -> V_60 + V_96 . V_127 ) > 0 )
V_159 -> V_60 += V_96 . V_127 ;
else
V_159 -> V_60 = 0 ;
}
}
}
