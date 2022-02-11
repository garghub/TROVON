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
V_47 . V_51 . V_5 = V_45 ;
if ( * V_43 != '\0' ) {
V_45 = strtol ( & ( V_43 [ 1 ] ) , & V_44 , 10 ) ;
if ( ( V_44 - & ( V_43 [ 1 ] ) ) > 9 ) {
V_43 [ 10 ] = 't' ;
V_45 = strtol ( & ( V_43 [ 1 ] ) , & V_44 , 10 ) ;
}
if ( * V_43 != '.' || V_44 == NULL || V_44 == V_43 || V_45 < 0
|| V_45 > V_52 || V_45 == V_49 || V_45 == V_50 ) {
fprintf ( V_28 , L_11 ,
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
V_47 . V_51 . V_53 = ( int ) V_45 ;
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
V_54 . V_48 = 1 ;
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
V_54 . V_51 . V_5 = V_45 ;
if ( * V_43 != '\0' ) {
V_45 = strtol ( & ( V_43 [ 1 ] ) , & V_44 , 10 ) ;
if ( ( V_44 - & ( V_43 [ 1 ] ) ) > 9 ) {
V_43 [ 10 ] = 't' ;
V_45 = strtol ( & ( V_43 [ 1 ] ) , & V_44 , 10 ) ;
}
if ( * V_43 != '.' || V_44 == NULL || V_44 == V_43 || V_45 < 0
|| V_45 > V_52 || V_45 == V_49 || V_45 == V_50 ) {
fprintf ( V_28 , L_11 ,
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
V_54 . V_51 . V_53 = ( int ) V_45 ;
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
V_55 . V_5 = V_45 ;
if ( * V_43 != '\0' ) {
V_45 = strtol ( & ( V_43 [ 1 ] ) , & V_44 , 10 ) ;
if ( ( V_44 - & ( V_43 [ 1 ] ) ) > 9 ) {
V_43 [ 10 ] = 't' ;
V_45 = strtol ( & ( V_43 [ 1 ] ) , & V_44 , 10 ) ;
}
if ( * V_43 != '.' || V_44 == NULL || V_44 == V_43 || V_45 < 0
|| V_45 > V_52 || V_45 == V_49 || V_45 == V_50 ) {
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
V_55 . V_53 = ( int ) V_45 ;
}
static T_4
F_14 ( T_6 * V_56 , T_7 V_57 ) {
int V_41 ;
T_8 V_58 ;
T_7 V_59 ;
T_6 * V_60 ;
V_60 = & V_56 [ V_61 ] ;
V_59 = V_57 - ( V_61 ) ;
V_62 ++ ;
if ( V_62 >= V_63 )
V_62 = 0 ;
F_15 ( & V_58 ) ;
F_16 ( & V_58 , V_60 , V_59 ) ;
F_17 ( & V_58 , V_64 [ V_62 ] . V_65 ) ;
V_64 [ V_62 ] . V_57 = V_57 ;
for ( V_41 = 0 ; V_41 < V_63 ; V_41 ++ ) {
if ( V_41 == V_62 )
continue;
if ( V_64 [ V_41 ] . V_57 == V_64 [ V_62 ] . V_57
&& memcmp ( V_64 [ V_41 ] . V_65 , V_64 [ V_62 ] . V_65 , 16 ) == 0 ) {
return TRUE ;
}
}
return FALSE ;
}
static T_4
F_18 ( T_6 * V_56 , T_7 V_57 , const T_2 * V_66 ) {
int V_41 ;
T_8 V_58 ;
T_7 V_59 ;
T_6 * V_60 ;
V_60 = & V_56 [ V_61 ] ;
V_59 = V_57 - ( V_61 ) ;
V_62 ++ ;
if ( V_62 >= V_63 )
V_62 = 0 ;
F_15 ( & V_58 ) ;
F_16 ( & V_58 , V_60 , V_59 ) ;
F_17 ( & V_58 , V_64 [ V_62 ] . V_65 ) ;
V_64 [ V_62 ] . V_57 = V_57 ;
V_64 [ V_62 ] . time . V_5 = V_66 -> V_5 ;
V_64 [ V_62 ] . time . V_53 = V_66 -> V_53 ;
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
if ( V_67 . V_5 < 0 || V_67 . V_53 < 0 ) {
continue;
}
V_68 = F_21 ( & V_67 , & V_55 ) ;
if ( V_68 > 0 ) {
break;
} else if ( V_64 [ V_41 ] . V_57 == V_64 [ V_62 ] . V_57
&& memcmp ( V_64 [ V_41 ] . V_65 , V_64 [ V_62 ] . V_65 , 16 ) == 0 ) {
return TRUE ;
}
}
return FALSE ;
}
static void
F_22 ( T_9 * V_69 , T_9 * V_70 )
{
printf ( L_15
L_16
L_17
L_16
L_17
L_16
L_17 ,
F_23 () , F_24 () ,
V_69 -> V_71 , V_70 -> V_71 ) ;
}
static void
F_25 ( T_10 * V_72 )
{
fprintf ( V_72 , L_16 ) ;
fprintf ( V_72 , L_18 ) ;
fprintf ( V_72 , L_16 ) ;
fprintf ( V_72 , L_19 ) ;
fprintf ( V_72 , L_20 ) ;
fprintf ( V_72 , L_16 ) ;
fprintf ( V_72 , L_21 ) ;
fprintf ( V_72 , L_22 ) ;
fprintf ( V_72 , L_23 ) ;
fprintf ( V_72 , L_24 ) ;
fprintf ( V_72 , L_25 ) ;
fprintf ( V_72 , L_26 ) ;
fprintf ( V_72 , L_16 ) ;
fprintf ( V_72 , L_27 ) ;
fprintf ( V_72 , L_28 , V_73 ) ;
fprintf ( V_72 , L_29 ) ;
fprintf ( V_72 , L_30 , V_74 ) ;
fprintf ( V_72 , L_31 ) ;
fprintf ( V_72 , L_32 ) ;
fprintf ( V_72 , L_33 ) ;
fprintf ( V_72 , L_34 ) ;
fprintf ( V_72 , L_35 ) ;
fprintf ( V_72 , L_36 ) ;
fprintf ( V_72 , L_16 ) ;
fprintf ( V_72 , L_37 ) ;
fprintf ( V_72 , L_38 ) ;
fprintf ( V_72 , L_39 ) ;
fprintf ( V_72 , L_40 ) ;
fprintf ( V_72 , L_41 ) ;
fprintf ( V_72 , L_42 ) ;
fprintf ( V_72 , L_43 ) ;
fprintf ( V_72 , L_16 ) ;
fprintf ( V_72 , L_44 ) ;
fprintf ( V_72 , L_45 ) ;
fprintf ( V_72 , L_46 ) ;
fprintf ( V_72 , L_47 ) ;
fprintf ( V_72 , L_16 ) ;
fprintf ( V_72 , L_48 ) ;
fprintf ( V_72 , L_49 ) ;
fprintf ( V_72 , L_50 ) ;
fprintf ( V_72 , L_51 ) ;
fprintf ( V_72 , L_52 ) ;
fprintf ( V_72 , L_53 ) ;
fprintf ( V_72 , L_54 ) ;
fprintf ( V_72 , L_55 ) ;
fprintf ( V_72 , L_56 ) ;
fprintf ( V_72 , L_57 ) ;
fprintf ( V_72 , L_58 ) ;
fprintf ( V_72 , L_59 ) ;
fprintf ( V_72 , L_60 ) ;
fprintf ( V_72 , L_61 ) ;
fprintf ( V_72 , L_62 ) ;
fprintf ( V_72 , L_63 ) ;
fprintf ( V_72 , L_64 ) ;
fprintf ( V_72 , L_65 ) ;
fprintf ( V_72 , L_66 ) ;
fprintf ( V_72 , L_67 ) ;
fprintf ( V_72 , L_68 ) ;
fprintf ( V_72 , L_69 ) ;
fprintf ( V_72 , L_70 ) ;
fprintf ( V_72 , L_71 ) ;
fprintf ( V_72 , L_16 ) ;
fprintf ( V_72 , L_72 ) ;
fprintf ( V_72 , L_73 ) ;
fprintf ( V_72 , L_74 ) ;
fprintf ( V_72 , L_75 ) ;
fprintf ( V_72 , L_76 ) ;
fprintf ( V_72 , L_77 ) ;
fprintf ( V_72 , L_78 ) ;
fprintf ( V_72 , L_79 ) ;
fprintf ( V_72 , L_80 ) ;
fprintf ( V_72 , L_81 ) ;
fprintf ( V_72 , L_82 ) ;
fprintf ( V_72 , L_83 ) ;
fprintf ( V_72 , L_16 ) ;
fprintf ( V_72 , L_84 ) ;
fprintf ( V_72 , L_85 ) ;
fprintf ( V_72 , L_86 ) ;
fprintf ( V_72 , L_87 ) ;
fprintf ( V_72 , L_88 ) ;
fprintf ( V_72 , L_89 ) ;
fprintf ( V_72 , L_16 ) ;
}
static T_11
F_26 ( T_12 V_75 , T_12 V_76 )
{
return strcmp ( ( ( const struct V_77 * ) V_75 ) -> V_78 ,
( ( const struct V_77 * ) V_76 ) -> V_78 ) ;
}
static T_11
F_27 ( T_12 V_75 , T_12 V_76 )
{
return F_28 ( ( ( const struct V_77 * ) V_75 ) -> V_78 ,
( ( const struct V_77 * ) V_76 ) -> V_78 ) ;
}
static void
F_29 ( T_13 V_79 , T_13 T_14 V_80 )
{
fprintf ( V_28 , L_90 ,
( (struct V_77 * ) V_79 ) -> V_78 ,
( (struct V_77 * ) V_79 ) -> V_81 ) ;
}
static void
F_30 ( void ) {
int V_41 ;
struct V_77 * V_82 ;
T_15 * V_83 = NULL ;
V_82 = F_31 ( struct V_77 , V_84 ) ;
fprintf ( V_28 , L_91 ) ;
for ( V_41 = 0 ; V_41 < V_84 ; V_41 ++ ) {
if ( F_32 ( V_41 ) ) {
V_82 [ V_41 ] . V_78 = F_33 ( V_41 ) ;
V_82 [ V_41 ] . V_81 = F_34 ( V_41 ) ;
V_83 = F_35 ( V_83 , & V_82 [ V_41 ] , F_26 ) ;
}
}
F_36 ( V_83 , F_29 , NULL ) ;
F_37 ( V_83 ) ;
F_6 ( V_82 ) ;
}
static void
F_38 ( void ) {
int V_41 ;
struct V_77 * V_85 ;
T_15 * V_83 = NULL ;
V_85 = (struct V_77 * ) F_2 ( sizeof( struct V_77 ) * V_86 ) ;
fprintf ( V_28 , L_92 ) ;
for ( V_41 = 0 ; V_41 < V_86 ; V_41 ++ ) {
V_85 [ V_41 ] . V_78 = F_39 ( V_41 ) ;
if ( V_85 [ V_41 ] . V_78 != NULL ) {
V_85 [ V_41 ] . V_81 = F_40 ( V_41 ) ;
V_83 = F_35 ( V_83 , & V_85 [ V_41 ] , F_27 ) ;
}
}
F_36 ( V_83 , F_29 , NULL ) ;
F_37 ( V_83 ) ;
F_6 ( V_85 ) ;
}
static void
F_41 ( const char * T_16 V_80 , T_17 T_18 V_80 )
{
}
static void
F_42 ( T_9 * V_71 )
{
F_43 ( V_71 , L_93 ) ;
#ifdef F_44
F_43 ( V_71 , L_94 ) ;
#ifdef F_45
F_43 ( V_71 , F_45 ) ;
#else
F_43 ( V_71 , L_95 ) ;
#endif
#else
F_43 ( V_71 , L_96 ) ;
#endif
}
static void
F_46 ( T_9 * V_71 )
{
#if F_47 ( F_44 ) && ! F_47 ( V_87 )
F_48 ( V_71 , L_97 , F_49 () ) ;
#endif
}
int
main ( int V_88 , char * V_89 [] )
{
T_9 * V_69 ;
T_9 * V_70 ;
T_19 * V_90 ;
int V_41 , V_91 , V_92 ;
T_1 * V_93 ;
int V_94 ;
static const struct V_95 V_96 [] = {
{ ( char * ) L_98 , V_97 , NULL , 'h' } ,
{ ( char * ) L_99 , V_97 , NULL , 'V' } ,
{ 0 , 0 , 0 , 0 }
} ;
char * V_98 ;
T_7 V_99 = 0 ;
T_20 V_100 = { 0 , 0 , 0 , 0 , 0 , 0 } ;
T_4 V_101 = FALSE ;
T_21 * V_102 = NULL ;
unsigned int V_103 = 1 ;
unsigned int V_104 = 0 ;
T_22 V_105 ;
int V_106 ;
T_6 * V_4 ;
T_7 V_107 = 0 ;
int V_108 = 0 ;
int V_109 = 0 ;
char * V_110 = NULL ;
T_4 V_111 ;
int V_112 = 0 ;
int V_113 = 0 ;
T_2 V_114 ;
T_1 * V_15 = NULL ;
T_1 * V_16 = NULL ;
const struct V_13 * V_14 ;
struct V_13 V_115 ;
T_23 * V_116 ;
T_24 * V_117 ;
#ifdef F_50
char * V_118 ;
#endif
#ifdef V_87
F_51 ( V_88 , V_89 ) ;
F_52 () ;
#endif
V_69 = F_53 ( L_100 ) ;
F_54 ( V_69 , NULL , F_42 ) ;
V_70 = F_53 ( L_101 ) ;
F_55 ( V_70 , F_46 ) ;
F_56 ( L_15
L_16
L_17
L_16
L_17 ,
F_23 () , V_69 -> V_71 , V_70 -> V_71 ) ;
F_57 () ;
F_58 () ;
#ifdef F_50
if ( ( V_118 = F_59 ( V_89 [ 0 ] , main ) ) ) {
F_60 ( L_102 , V_118 ) ;
F_6 ( V_118 ) ;
} else {
F_61 () ;
F_62 ( F_41 , NULL , NULL , NULL ) ;
F_63 () ;
F_64 () ;
}
#endif
while ( ( V_94 = F_65 ( V_88 , V_89 , L_103 , V_96 , NULL ) ) != - 1 ) {
switch ( V_94 ) {
case 'A' :
{
struct V_2 V_119 ;
memset ( & V_119 , 0 , sizeof( struct V_2 ) ) ;
if ( ! strptime ( V_120 , L_104 , & V_119 ) ) {
fprintf ( V_28 , L_105 ,
V_120 ) ;
exit ( 1 ) ;
}
V_121 = TRUE ;
V_119 . V_122 = - 1 ;
V_123 = mktime ( & V_119 ) ;
break;
}
case 'B' :
{
struct V_2 V_124 ;
memset ( & V_124 , 0 , sizeof( struct V_2 ) ) ;
if ( ! strptime ( V_120 , L_104 , & V_124 ) ) {
fprintf ( V_28 , L_105 ,
V_120 ) ;
exit ( 1 ) ;
}
V_121 = TRUE ;
V_124 . V_122 = - 1 ;
V_125 = mktime ( & V_124 ) ;
break;
}
case 'c' :
V_108 = ( int ) strtol ( V_120 , & V_98 , 10 ) ;
if ( V_98 == V_120 || * V_98 != '\0' ) {
fprintf ( V_28 , L_106 ,
V_120 ) ;
exit ( 1 ) ;
}
if ( V_108 <= 0 ) {
fprintf ( V_28 , L_107 ,
V_108 ) ;
exit ( 1 ) ;
}
break;
case 'C' :
{
int V_126 = 0 , V_127 = 0 ;
switch ( sscanf ( V_120 , L_108 , & V_127 , & V_126 ) ) {
case 1 :
V_126 = V_127 ;
V_127 = 0 ;
break;
case 2 :
break;
default:
fprintf ( V_28 , L_109 ,
V_120 ) ;
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
V_63 = V_73 ;
break;
case 'D' :
V_134 = TRUE ;
V_135 = FALSE ;
V_63 = ( int ) strtol ( V_120 , & V_98 , 10 ) ;
if ( V_98 == V_120 || * V_98 != '\0' ) {
fprintf ( V_28 , L_110 ,
V_120 ) ;
exit ( 1 ) ;
}
if ( V_63 < 0 || V_63 > V_74 ) {
fprintf ( V_28 , L_111 ,
V_63 , V_74 ) ;
exit ( 1 ) ;
}
break;
case 'E' :
V_136 = strtod ( V_120 , & V_98 ) ;
if ( V_98 == V_120 || V_136 < 0.0 || V_136 > 1.0 ) {
fprintf ( V_28 , L_112 ,
V_120 ) ;
exit ( 1 ) ;
}
srand ( ( unsigned int ) ( time ( NULL ) + F_66 () ) ) ;
break;
case 'F' :
V_137 = F_67 ( V_120 ) ;
if ( V_137 < 0 ) {
fprintf ( V_28 , L_113 ,
V_120 ) ;
F_30 () ;
exit ( 1 ) ;
}
break;
case 'h' :
printf ( L_15
L_114
L_115 ,
F_23 () ) ;
F_25 ( stdout ) ;
exit ( 0 ) ;
break;
case 'i' :
V_112 = atoi ( V_120 ) ;
if ( V_112 <= 0 ) {
fprintf ( V_28 , L_116 ,
V_120 ) ;
exit ( 1 ) ;
}
break;
case 'I' :
V_61 = atoi ( V_120 ) ;
if( V_61 <= 0 ) {
fprintf ( V_28 , L_117 , V_120 ) ;
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
V_99 = ( T_7 ) strtol ( V_120 , & V_98 , 10 ) ;
if ( V_98 == V_120 || * V_98 != '\0' ) {
fprintf ( V_28 , L_118 ,
V_120 ) ;
exit ( 1 ) ;
}
break;
case 'S' :
F_12 ( V_120 ) ;
V_139 = TRUE ;
break;
case 't' :
F_11 ( V_120 ) ;
break;
case 'T' :
V_140 = F_68 ( V_120 ) ;
if ( V_140 < 0 ) {
fprintf ( V_28 , L_119 ,
V_120 ) ;
F_38 () ;
exit ( 1 ) ;
}
break;
case 'v' :
V_35 = ! V_35 ;
break;
case 'V' :
F_22 ( V_69 , V_70 ) ;
F_69 ( V_69 , TRUE ) ;
F_69 ( V_70 , TRUE ) ;
exit ( 0 ) ;
break;
case 'w' :
V_134 = FALSE ;
V_135 = TRUE ;
V_63 = V_74 ;
F_13 ( V_120 ) ;
break;
case '?' :
switch( V_141 ) {
case 'F' :
F_30 () ;
break;
case 'T' :
F_38 () ;
break;
default:
F_25 ( V_28 ) ;
break;
}
exit ( 1 ) ;
break;
}
}
#ifdef F_70
fprintf ( V_28 , L_120 , V_142 , V_88 ) ;
#endif
if ( ( V_88 - V_142 ) < 1 ) {
F_25 ( V_28 ) ;
exit ( 1 ) ;
}
if ( V_121 && ! V_125 ) {
struct V_2 V_124 ;
memset ( & V_124 , 0 , sizeof( struct V_2 ) ) ;
V_124 . V_6 = 135 ;
V_124 . V_8 = 31 ;
V_124 . V_7 = 11 ;
V_125 = mktime ( & V_124 ) ;
}
F_71 ( & V_114 ) ;
if ( V_123 > V_125 ) {
fprintf ( V_28 , L_121 ) ;
exit ( 1 ) ;
}
if ( V_108 > 0 && V_112 > 0 ) {
fprintf ( V_28 , L_122 ) ;
fprintf ( V_28 , L_123 ) ;
exit ( 1 ) ;
}
V_90 = F_72 ( V_89 [ V_142 ] , V_143 , & V_92 , & V_93 , FALSE ) ;
if ( ! V_90 ) {
fprintf ( V_28 , L_124 , V_89 [ V_142 ] ,
F_73 ( V_92 ) ) ;
switch ( V_92 ) {
case V_144 :
case V_145 :
case V_146 :
fprintf ( V_28 , L_125 , V_93 ) ;
F_6 ( V_93 ) ;
break;
}
exit ( 2 ) ;
}
if ( V_35 ) {
fprintf ( V_28 , L_126 , V_89 [ V_142 ] ,
F_34 ( F_74 ( V_90 ) ) ) ;
}
V_117 = F_75 ( V_90 ) ;
V_116 = F_76 ( V_90 ) ;
if ( ( V_88 - V_142 ) >= 2 ) {
if ( V_140 == - 2 )
V_140 = F_77 ( V_90 ) ;
for ( V_41 = V_142 + 2 ; V_41 < V_88 ; V_41 ++ )
if ( F_9 ( V_89 [ V_41 ] ) == FALSE )
break;
if ( V_134 || V_135 ) {
for ( V_41 = 0 ; V_41 < V_63 ; V_41 ++ ) {
memset ( & V_64 [ V_41 ] . V_65 , 0 , 16 ) ;
V_64 [ V_41 ] . V_57 = 0 ;
F_71 ( & V_64 [ V_41 ] . time ) ;
}
}
while ( F_78 ( V_90 , & V_92 , & V_93 , & V_105 ) ) {
V_107 ++ ;
V_14 = F_79 ( V_90 ) ;
if ( V_107 == 1 ) {
if ( V_108 > 0 || V_112 > 0 ) {
if ( ! F_7 ( V_89 [ V_142 + 1 ] , & V_15 , & V_16 ) )
exit ( 2 ) ;
V_110 = F_4 ( V_113 ++ , V_14 , V_15 , V_16 ) ;
} else {
V_110 = F_8 ( V_89 [ V_142 + 1 ] ) ;
}
F_80 ( V_110 ) ;
if ( V_117 -> V_147 == NULL ) {
V_117 -> V_147 = F_8 ( L_127 V_148 ) ;
}
V_102 = F_81 ( V_110 , V_137 , V_140 ,
V_99 ? F_82 ( V_99 , F_83 ( V_90 ) ) : F_83 ( V_90 ) ,
FALSE , V_117 , V_116 , & V_92 ) ;
if ( V_102 == NULL ) {
fprintf ( V_28 , L_128 ,
V_110 , F_73 ( V_92 ) ) ;
exit ( 2 ) ;
}
}
V_4 = F_84 ( V_90 ) ;
if ( V_14 -> V_21 & V_22 ) {
if ( F_19 ( & V_114 ) ) {
V_114 . V_5 = V_14 -> V_23 . V_5 ;
V_114 . V_53 = V_14 -> V_23 . V_53 ;
}
if ( V_112 > 0 ) {
while ( ( V_14 -> V_23 . V_5 - V_114 . V_5 > V_112 )
|| ( V_14 -> V_23 . V_5 - V_114 . V_5 == V_112
&& V_14 -> V_23 . V_53 >= V_114 . V_53 ) ) {
if ( ! F_85 ( V_102 , & V_92 ) ) {
fprintf ( V_28 , L_129 ,
V_110 , F_73 ( V_92 ) ) ;
exit ( 2 ) ;
}
V_114 . V_5 = V_114 . V_5 + V_112 ;
F_6 ( V_110 ) ;
V_110 = F_4 ( V_113 ++ , V_14 , V_15 , V_16 ) ;
F_80 ( V_110 ) ;
if ( V_35 )
fprintf ( V_28 , L_130 , V_110 ) ;
V_102 = F_81 ( V_110 , V_137 , V_140 ,
V_99 ? F_82 ( V_99 , F_83 ( V_90 ) ) : F_83 ( V_90 ) ,
FALSE , V_117 , V_116 , & V_92 ) ;
if ( V_102 == NULL ) {
fprintf ( V_28 , L_128 ,
V_110 , F_73 ( V_92 ) ) ;
exit ( 2 ) ;
}
}
}
}
if ( V_108 > 0 ) {
if ( V_109 > 0 && V_109 % V_108 == 0 ) {
if ( ! F_85 ( V_102 , & V_92 ) ) {
fprintf ( V_28 , L_129 ,
V_110 , F_73 ( V_92 ) ) ;
exit ( 2 ) ;
}
F_6 ( V_110 ) ;
V_110 = F_4 ( V_113 ++ , V_14 , V_15 , V_16 ) ;
F_80 ( V_110 ) ;
if ( V_35 )
fprintf ( V_28 , L_130 , V_110 ) ;
V_102 = F_81 ( V_110 , V_137 , V_140 ,
V_99 ? F_82 ( V_99 , F_83 ( V_90 ) ) : F_83 ( V_90 ) ,
FALSE , V_117 , V_116 , & V_92 ) ;
if ( V_102 == NULL ) {
fprintf ( V_28 , L_128 ,
V_110 , F_73 ( V_92 ) ) ;
exit ( 2 ) ;
}
}
}
if ( V_121 ) {
if ( V_14 -> V_21 & V_22 )
V_111 = ( V_14 -> V_23 . V_5 >= V_123 ) && ( V_14 -> V_23 . V_5 < V_125 ) ;
else
V_111 = FALSE ;
} else {
V_111 = TRUE ;
}
if ( V_111 && ( ( ! F_10 ( V_103 ) && ! V_138 )
|| ( F_10 ( V_103 ) && V_138 ) ) ) {
if ( V_35 && ! V_134 && ! V_135 )
fprintf ( V_28 , L_131 , V_103 ) ;
V_14 = F_79 ( V_90 ) ;
if ( V_99 != 0 ) {
if ( V_14 -> V_149 > V_99 ) {
V_115 = * V_14 ;
V_115 . V_149 = V_99 ;
V_14 = & V_115 ;
}
if ( V_101 && V_14 -> V_57 > V_99 ) {
V_115 = * V_14 ;
V_115 . V_57 = V_99 ;
V_14 = & V_115 ;
}
}
V_115 = * V_14 ;
F_86 ( V_100 , & V_115 , V_14 , & V_4 , V_101 ) ;
V_14 = & V_115 ;
if ( V_14 -> V_21 & V_22 ) {
if ( V_139 ) {
if ( V_150 . V_5 || V_150 . V_53 ) {
if ( ! V_54 . V_48 ) {
T_2 V_66 ;
T_2 V_67 ;
V_66 . V_5 = V_14 -> V_23 . V_5 ;
V_66 . V_53 = V_14 -> V_23 . V_53 ;
F_20 ( & V_67 , & V_66 , & V_150 ) ;
if ( V_67 . V_5 < 0 || V_67 . V_53 < 0 ) {
V_115 = * V_14 ;
V_115 . V_23 . V_5 = V_150 . V_5 + V_54 . V_51 . V_5 ;
V_115 . V_23 . V_53 = V_150 . V_53 ;
if ( V_115 . V_23 . V_53 + V_54 . V_51 . V_53 > V_52 ) {
V_115 . V_23 . V_5 ++ ;
V_115 . V_23 . V_53 += V_54 . V_51 . V_53 - V_52 ;
} else {
V_115 . V_23 . V_53 += V_54 . V_51 . V_53 ;
}
V_14 = & V_115 ;
}
} else {
V_115 = * V_14 ;
V_115 . V_23 . V_5 = V_150 . V_5 + V_54 . V_51 . V_5 ;
V_115 . V_23 . V_53 = V_150 . V_53 ;
if ( V_115 . V_23 . V_53 + V_54 . V_51 . V_53 > V_52 ) {
V_115 . V_23 . V_5 ++ ;
V_115 . V_23 . V_53 += V_54 . V_51 . V_53 - V_52 ;
} else {
V_115 . V_23 . V_53 += V_54 . V_51 . V_53 ;
}
V_14 = & V_115 ;
}
}
V_150 . V_5 = V_14 -> V_23 . V_5 ;
V_150 . V_53 = V_14 -> V_23 . V_53 ;
}
if ( V_14 -> V_23 . V_5 > 0 && V_47 . V_51 . V_5 != 0 ) {
V_115 = * V_14 ;
if ( V_47 . V_48 )
V_115 . V_23 . V_5 -= V_47 . V_51 . V_5 ;
else
V_115 . V_23 . V_5 += V_47 . V_51 . V_5 ;
V_14 = & V_115 ;
}
if ( V_14 -> V_23 . V_5 > 0 && V_47 . V_51 . V_53 != 0 ) {
V_115 = * V_14 ;
if ( V_47 . V_48 ) {
if ( V_115 . V_23 . V_53 < V_47 . V_51 . V_53 ) {
V_115 . V_23 . V_5 -- ;
V_115 . V_23 . V_53 += V_52 ;
}
V_115 . V_23 . V_53 -= V_47 . V_51 . V_53 ;
} else {
if ( V_115 . V_23 . V_53 + V_47 . V_51 . V_53 > V_52 ) {
V_115 . V_23 . V_5 ++ ;
V_115 . V_23 . V_53 += V_47 . V_51 . V_53 - V_52 ;
} else {
V_115 . V_23 . V_53 += V_47 . V_51 . V_53 ;
}
}
V_14 = & V_115 ;
}
}
if ( V_134 ) {
if ( F_14 ( V_4 , V_14 -> V_149 ) ) {
if ( V_35 ) {
fprintf ( V_28 , L_132 ,
V_103 , V_14 -> V_149 ) ;
for ( V_41 = 0 ; V_41 < 16 ; V_41 ++ )
fprintf ( V_28 , L_133 ,
( unsigned char ) V_64 [ V_62 ] . V_65 [ V_41 ] ) ;
fprintf ( V_28 , L_16 ) ;
}
V_104 ++ ;
V_103 ++ ;
continue;
} else {
if ( V_35 ) {
fprintf ( V_28 , L_134 ,
V_103 , V_14 -> V_149 ) ;
for ( V_41 = 0 ; V_41 < 16 ; V_41 ++ )
fprintf ( V_28 , L_133 ,
( unsigned char ) V_64 [ V_62 ] . V_65 [ V_41 ] ) ;
fprintf ( V_28 , L_16 ) ;
}
}
}
if ( V_14 -> V_21 & V_22 ) {
if ( V_135 ) {
T_2 V_66 ;
V_66 . V_5 = V_14 -> V_23 . V_5 ;
V_66 . V_53 = V_14 -> V_23 . V_53 ;
if ( F_18 ( V_4 , V_14 -> V_149 , & V_66 ) ) {
if ( V_35 ) {
fprintf ( V_28 , L_132 ,
V_103 , V_14 -> V_149 ) ;
for ( V_41 = 0 ; V_41 < 16 ; V_41 ++ )
fprintf ( V_28 , L_133 ,
( unsigned char ) V_64 [ V_62 ] . V_65 [ V_41 ] ) ;
fprintf ( V_28 , L_16 ) ;
}
V_104 ++ ;
V_103 ++ ;
continue;
} else {
if ( V_35 ) {
fprintf ( V_28 , L_134 ,
V_103 , V_14 -> V_149 ) ;
for ( V_41 = 0 ; V_41 < 16 ; V_41 ++ )
fprintf ( V_28 , L_133 ,
( unsigned char ) V_64 [ V_62 ] . V_65 [ V_41 ] ) ;
fprintf ( V_28 , L_16 ) ;
}
}
}
}
if ( V_136 > 0.0 ) {
int V_151 = 0 ;
if ( F_74 ( V_90 ) == V_152 )
V_151 = F_87 ( V_4 ) ;
for ( V_41 = V_151 ; V_41 < ( int ) V_14 -> V_149 ; V_41 ++ ) {
if ( rand () <= V_136 * V_153 ) {
V_106 = rand () / ( V_153 / V_154 + 1 ) ;
if ( V_106 < V_155 ) {
V_4 [ V_41 ] ^= 1 << ( rand () / ( V_153 / 8 + 1 ) ) ;
V_106 = V_154 ;
} else {
V_106 -= V_156 ;
}
if ( V_106 < V_156 ) {
V_4 [ V_41 ] = rand () / ( V_153 / 255 + 1 ) ;
V_106 = V_154 ;
} else {
V_106 -= V_156 ;
}
if ( V_106 < V_157 ) {
V_4 [ V_41 ] = V_158 [ rand () / ( V_153 / V_159 + 1 ) ] ;
V_106 = V_154 ;
} else {
V_106 -= V_157 ;
}
if ( V_106 < V_160 ) {
if ( ( unsigned int ) V_41 < V_14 -> V_149 - 2 )
F_88 ( ( char * ) & V_4 [ V_41 ] , L_17 , 2 ) ;
V_106 = V_154 ;
} else {
V_106 -= V_160 ;
}
if ( V_106 < V_161 ) {
for ( V_91 = V_41 ; V_91 < ( int ) V_14 -> V_149 ; V_91 ++ )
V_4 [ V_91 ] = 0xAA ;
V_41 = V_14 -> V_149 ;
}
}
}
}
if ( ! F_89 ( V_102 , V_14 , V_4 , & V_92 ) ) {
switch ( V_92 ) {
case V_145 :
fprintf ( V_28 ,
L_135 ,
V_107 , V_89 [ V_142 ] ,
F_34 ( V_137 ) ) ;
break;
case V_162 :
fprintf ( V_28 ,
L_136 ,
V_107 , V_89 [ V_142 ] ,
F_34 ( V_137 ) ) ;
break;
default:
fprintf ( V_28 , L_129 ,
V_110 , F_73 ( V_92 ) ) ;
break;
}
exit ( 2 ) ;
}
V_109 ++ ;
}
V_103 ++ ;
}
F_6 ( V_15 ) ;
F_6 ( V_16 ) ;
if ( V_92 != 0 ) {
fprintf ( V_28 ,
L_137 ,
V_89 [ V_142 ] , F_73 ( V_92 ) ) ;
switch ( V_92 ) {
case V_144 :
case V_145 :
case V_146 :
fprintf ( V_28 , L_125 , V_93 ) ;
F_6 ( V_93 ) ;
break;
}
}
if ( ! V_102 ) {
F_6 ( V_110 ) ;
V_110 = F_8 ( V_89 [ V_142 + 1 ] ) ;
V_102 = F_81 ( V_110 , V_137 , V_140 ,
V_99 ? F_82 ( V_99 , F_83 ( V_90 ) ) : F_83 ( V_90 ) ,
FALSE , V_117 , V_116 , & V_92 ) ;
if ( V_102 == NULL ) {
fprintf ( V_28 , L_128 ,
V_110 , F_73 ( V_92 ) ) ;
exit ( 2 ) ;
}
}
F_6 ( V_116 ) ;
V_116 = NULL ;
if ( ! F_85 ( V_102 , & V_92 ) ) {
fprintf ( V_28 , L_129 , V_110 ,
F_73 ( V_92 ) ) ;
exit ( 2 ) ;
}
F_6 ( V_117 ) ;
F_6 ( V_110 ) ;
}
if ( V_134 ) {
fprintf ( V_28 , L_138 ,
V_103 - 1 , F_90 ( V_103 - 1 , L_139 , L_140 ) , V_104 ,
F_90 ( V_104 , L_139 , L_140 ) , V_63 ) ;
} else if ( V_135 ) {
fprintf ( V_28 , L_141 ,
V_103 - 1 , F_90 ( V_103 - 1 , L_139 , L_140 ) , V_104 ,
F_90 ( V_104 , L_139 , L_140 ) ,
( long ) V_55 . V_5 ,
( long int ) V_55 . V_53 ) ;
}
return 0 ;
}
static int
F_87 ( T_6 * V_4 )
{
int V_163 = 0 ;
for ( V_163 = 0 ; V_4 [ V_163 ] != '\0' ; V_163 ++ ) ;
V_163 ++ ;
V_163 ++ ;
for (; V_4 [ V_163 ] != '\0' ; V_163 ++ ) ;
V_163 ++ ;
for (; V_4 [ V_163 ] != '\0' ; V_163 ++ ) ;
V_163 ++ ;
for (; V_4 [ V_163 ] != '\0' ; V_163 ++ ) ;
V_163 ++ ;
for (; V_4 [ V_163 ] != '\0' ; V_163 ++ ) ;
V_163 ++ ;
V_163 += 2 ;
return V_163 ;
}
static void
F_86 ( T_20 V_100 , struct V_13 * V_164 ,
const struct V_13 * V_165 , T_6 * * V_4 ,
T_4 V_101 )
{
if ( V_165 -> V_166 != V_167 )
return;
if ( V_100 . V_128 == 0 )
V_100 . V_129 = V_100 . V_130 = 0 ;
if ( V_100 . V_131 == 0 )
V_100 . V_132 = V_100 . V_133 = 0 ;
if ( V_100 . V_130 < 0 ) {
V_100 . V_129 += V_165 -> V_149 + V_100 . V_130 ;
V_100 . V_130 = 0 ;
}
if ( V_100 . V_132 > 0 ) {
V_100 . V_133 += V_100 . V_132 - V_165 -> V_149 ;
V_100 . V_132 = 0 ;
}
if ( V_100 . V_128 && V_100 . V_131 ) {
if ( V_100 . V_129 > ( ( int ) V_165 -> V_149 + V_100 . V_133 ) ) {
int V_168 , V_169 ;
V_169 = V_165 -> V_149 + V_100 . V_133 + V_100 . V_131 ;
V_168 = - V_100 . V_131 ;
V_100 . V_133 = V_100 . V_128 + V_100 . V_129 - V_165 -> V_149 ;
V_100 . V_131 = - V_100 . V_128 ;
V_100 . V_128 = V_168 ;
V_100 . V_129 = V_169 ;
}
}
if ( V_165 -> V_149 < ( T_7 ) ( V_100 . V_129 - V_100 . V_133 ) ) {
V_100 . V_128 = 0 ;
V_100 . V_131 = 0 ;
}
if ( ( T_7 ) ( V_100 . V_128 - V_100 . V_131 ) >
( V_165 -> V_149 - ( T_7 ) ( V_100 . V_129 - V_100 . V_133 ) ) ) {
V_100 . V_128 = V_165 -> V_149 - ( V_100 . V_129 - V_100 . V_133 ) ;
V_100 . V_131 = 0 ;
}
if ( V_100 . V_128 > 0 ) {
* V_164 = * V_165 ;
if ( V_100 . V_129 > 0 ) {
memmove ( * V_4 + V_100 . V_129 ,
* V_4 + V_100 . V_129 + V_100 . V_128 ,
V_164 -> V_149 - V_100 . V_128 ) ;
} else {
* V_4 += V_100 . V_128 ;
}
V_164 -> V_149 -= V_100 . V_128 ;
if ( V_101 ) {
if ( V_165 -> V_57 > ( T_7 ) V_100 . V_128 )
V_164 -> V_57 -= V_100 . V_128 ;
else
V_164 -> V_57 = 0 ;
}
V_165 = V_164 ;
}
if ( V_100 . V_131 < 0 ) {
* V_164 = * V_165 ;
if ( V_100 . V_133 < 0 ) {
memmove ( * V_4 + ( T_11 ) V_164 -> V_149 + ( V_100 . V_131 + V_100 . V_133 ) ,
* V_4 + ( T_11 ) V_164 -> V_149 + V_100 . V_133 ,
- V_100 . V_133 ) ;
}
V_164 -> V_149 += V_100 . V_131 ;
if ( V_101 ) {
if ( ( ( signed int ) V_165 -> V_57 + V_100 . V_131 ) > 0 )
V_164 -> V_57 += V_100 . V_131 ;
else
V_164 -> V_57 = 0 ;
}
}
}
