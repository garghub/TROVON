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
V_64 [ V_62 ] . V_67 . V_5 = V_66 -> V_5 ;
V_64 [ V_62 ] . V_67 . V_53 = V_66 -> V_53 ;
for ( V_41 = V_62 - 1 ; ; V_41 -- ) {
T_2 V_68 ;
int V_69 ;
if ( V_41 < 0 )
V_41 = V_63 - 1 ;
if ( V_41 == V_62 ) {
break;
}
if ( F_19 ( & ( V_64 [ V_41 ] . V_67 ) ) ) {
break;
}
F_20 ( & V_68 , V_66 , & V_64 [ V_41 ] . V_67 ) ;
if ( V_68 . V_5 < 0 || V_68 . V_53 < 0 ) {
continue;
}
V_69 = F_21 ( & V_68 , & V_55 ) ;
if ( V_69 > 0 ) {
break;
} else if ( V_64 [ V_41 ] . V_57 == V_64 [ V_62 ] . V_57
&& memcmp ( V_64 [ V_41 ] . V_65 , V_64 [ V_62 ] . V_65 , 16 ) == 0 ) {
return TRUE ;
}
}
return FALSE ;
}
static void
F_22 ( T_9 * V_70 )
{
fprintf ( V_70 , L_15 ) ;
fprintf ( V_70 , L_16 ) ;
fprintf ( V_70 , L_15 ) ;
fprintf ( V_70 , L_17 ) ;
fprintf ( V_70 , L_18 ) ;
fprintf ( V_70 , L_15 ) ;
fprintf ( V_70 , L_19 ) ;
fprintf ( V_70 , L_20 ) ;
fprintf ( V_70 , L_21 ) ;
fprintf ( V_70 , L_22 ) ;
fprintf ( V_70 , L_23 ) ;
fprintf ( V_70 , L_24 ) ;
fprintf ( V_70 , L_15 ) ;
fprintf ( V_70 , L_25 ) ;
fprintf ( V_70 , L_26 , V_71 ) ;
fprintf ( V_70 , L_27 ) ;
fprintf ( V_70 , L_28 , V_72 ) ;
fprintf ( V_70 , L_29 ) ;
fprintf ( V_70 , L_30 ) ;
fprintf ( V_70 , L_31 ) ;
fprintf ( V_70 , L_32 ) ;
fprintf ( V_70 , L_33 ) ;
fprintf ( V_70 , L_34 ) ;
fprintf ( V_70 , L_35 ) ;
fprintf ( V_70 , L_15 ) ;
fprintf ( V_70 , L_36 ) ;
fprintf ( V_70 , L_37 ) ;
fprintf ( V_70 , L_38 ) ;
fprintf ( V_70 , L_39 ) ;
fprintf ( V_70 , L_40 ) ;
fprintf ( V_70 , L_41 ) ;
fprintf ( V_70 , L_42 ) ;
fprintf ( V_70 , L_15 ) ;
fprintf ( V_70 , L_43 ) ;
fprintf ( V_70 , L_44 ) ;
fprintf ( V_70 , L_45 ) ;
fprintf ( V_70 , L_46 ) ;
fprintf ( V_70 , L_15 ) ;
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
fprintf ( V_70 , L_69 ) ;
fprintf ( V_70 , L_70 ) ;
fprintf ( V_70 , L_71 ) ;
fprintf ( V_70 , L_72 ) ;
fprintf ( V_70 , L_73 ) ;
fprintf ( V_70 , L_74 ) ;
fprintf ( V_70 , L_15 ) ;
fprintf ( V_70 , L_75 ) ;
fprintf ( V_70 , L_76 ) ;
fprintf ( V_70 , L_77 ) ;
fprintf ( V_70 , L_78 ) ;
fprintf ( V_70 , L_79 ) ;
fprintf ( V_70 , L_80 ) ;
fprintf ( V_70 , L_81 ) ;
fprintf ( V_70 , L_82 ) ;
fprintf ( V_70 , L_83 ) ;
fprintf ( V_70 , L_84 ) ;
fprintf ( V_70 , L_85 ) ;
fprintf ( V_70 , L_86 ) ;
fprintf ( V_70 , L_15 ) ;
fprintf ( V_70 , L_87 ) ;
fprintf ( V_70 , L_88 ) ;
fprintf ( V_70 , L_89 ) ;
fprintf ( V_70 , L_90 ) ;
fprintf ( V_70 , L_91 ) ;
fprintf ( V_70 , L_92 ) ;
fprintf ( V_70 , L_15 ) ;
}
static T_10
F_23 ( T_11 V_73 , T_11 V_74 )
{
return strcmp ( ( ( const struct V_75 * ) V_73 ) -> V_76 ,
( ( const struct V_75 * ) V_74 ) -> V_76 ) ;
}
static T_10
F_24 ( T_11 V_73 , T_11 V_74 )
{
return F_25 ( ( ( const struct V_75 * ) V_73 ) -> V_76 ,
( ( const struct V_75 * ) V_74 ) -> V_76 ) ;
}
static void
F_26 ( T_12 V_77 , T_12 T_13 V_78 )
{
fprintf ( V_28 , L_93 ,
( (struct V_75 * ) V_77 ) -> V_76 ,
( (struct V_75 * ) V_77 ) -> V_79 ) ;
}
static void
F_27 ( void ) {
int V_41 ;
struct V_75 * V_80 ;
T_14 * V_81 = NULL ;
V_80 = F_28 ( struct V_75 , V_82 ) ;
fprintf ( V_28 , L_94 ) ;
for ( V_41 = 0 ; V_41 < V_82 ; V_41 ++ ) {
if ( F_29 ( V_41 ) ) {
V_80 [ V_41 ] . V_76 = F_30 ( V_41 ) ;
V_80 [ V_41 ] . V_79 = F_31 ( V_41 ) ;
V_81 = F_32 ( V_81 , & V_80 [ V_41 ] , F_23 ) ;
}
}
F_33 ( V_81 , F_26 , NULL ) ;
F_34 ( V_81 ) ;
F_6 ( V_80 ) ;
}
static void
F_35 ( void ) {
int V_41 ;
struct V_75 * V_83 ;
T_14 * V_81 = NULL ;
V_83 = (struct V_75 * ) F_2 ( sizeof( struct V_75 ) * V_84 ) ;
fprintf ( V_28 , L_95 ) ;
for ( V_41 = 0 ; V_41 < V_84 ; V_41 ++ ) {
V_83 [ V_41 ] . V_76 = F_36 ( V_41 ) ;
if ( V_83 [ V_41 ] . V_76 != NULL ) {
V_83 [ V_41 ] . V_79 = F_37 ( V_41 ) ;
V_81 = F_32 ( V_81 , & V_83 [ V_41 ] , F_24 ) ;
}
}
F_33 ( V_81 , F_26 , NULL ) ;
F_34 ( V_81 ) ;
F_6 ( V_83 ) ;
}
static int
F_38 ( T_11 V_73 , T_11 V_74 , T_12 T_15 V_78 )
{
return ( V_73 != V_74 ) ;
}
static void
F_39 ( const char * T_16 V_78 , T_17 T_18 V_78 )
{
}
static void
F_40 ( T_19 * V_85 )
{
F_41 ( V_85 , L_96 ) ;
#ifdef F_42
F_41 ( V_85 , L_97 ) ;
#ifdef F_43
F_41 ( V_85 , F_43 ) ;
#else
F_41 ( V_85 , L_98 ) ;
#endif
#else
F_41 ( V_85 , L_99 ) ;
#endif
}
static void
F_44 ( T_19 * V_85 )
{
#if F_45 ( F_42 ) && ! F_45 ( V_86 )
F_46 ( V_85 , L_100 , F_47 () ) ;
#endif
}
static T_20 *
F_48 ( const char * V_87 , T_7 V_88 ,
T_21 * V_89 ,
T_22 * V_90 ,
T_23 * V_91 , int * V_92 )
{
T_20 * V_93 ;
if ( strcmp ( V_87 , L_101 ) == 0 ) {
V_93 = F_49 ( V_94 , V_95 ,
V_88 , FALSE ,
V_89 , V_90 , V_91 ,
V_92 ) ;
} else {
V_93 = F_50 ( V_87 , V_94 , V_95 ,
V_88 , FALSE ,
V_89 , V_90 , V_91 ,
V_92 ) ;
}
return V_93 ;
}
int
main ( int V_96 , char * V_97 [] )
{
T_19 * V_98 ;
T_19 * V_99 ;
T_24 * V_100 ;
int V_41 , V_101 , V_102 , V_92 ;
T_1 * V_103 , * V_104 ;
int V_105 ;
F_51 (cast-qual)
static const struct V_106 V_107 [] = {
{ ( char * ) L_102 , V_108 , NULL , 'h' } ,
{ ( char * ) L_103 , V_108 , NULL , 'V' } ,
{ 0 , 0 , 0 , 0 }
} ;
F_52 (cast-qual)
char * V_109 ;
T_7 V_88 = 0 ;
T_25 V_110 = { 0 , 0 , 0 , 0 , 0 , 0 } ;
T_4 V_111 = FALSE ;
T_20 * V_93 = NULL ;
unsigned int V_112 = 1 ;
unsigned int V_113 = 0 ;
T_26 V_114 ;
int V_115 ;
T_6 * V_4 ;
T_7 V_116 = 0 ;
int V_117 = 0 ;
int V_118 = 0 ;
char * V_87 = NULL ;
T_4 V_119 ;
int V_120 = 0 ;
int V_121 = 0 ;
T_2 V_122 ;
T_1 * V_15 = NULL ;
T_1 * V_16 = NULL ;
T_7 V_123 = 0 ;
const struct V_13 * V_14 ;
struct V_13 V_124 ;
T_22 * V_90 = NULL ;
T_21 * V_89 = NULL ;
T_23 * V_91 = NULL ;
#ifdef F_53
char * V_125 ;
#endif
#ifdef V_86
F_54 ( V_96 , V_97 ) ;
F_55 () ;
#endif
V_98 = F_56 ( NULL , F_40 ) ;
V_99 = F_57 ( F_44 ) ;
F_58 ( L_104
L_15
L_105
L_15
L_105 ,
F_59 () , V_98 -> V_85 , V_99 -> V_85 ) ;
F_60 () ;
F_61 () ;
#ifdef F_53
if ( ( V_125 = F_62 ( V_97 [ 0 ] , ( void * )main ) ) ) {
F_63 ( L_106 , V_125 ) ;
F_6 ( V_125 ) ;
} else {
F_64 () ;
F_65 ( F_39 , NULL , NULL , NULL ) ;
F_66 () ;
F_67 () ;
}
#endif
while ( ( V_105 = F_68 ( V_96 , V_97 , L_107 , V_107 , NULL ) ) != - 1 ) {
switch ( V_105 ) {
case 'a' :
{
T_3 V_126 ;
T_10 V_127 = 0 ;
if ( ( sscanf ( V_128 , L_108 , & V_126 , & V_127 ) < 1 ) || ( V_127 == 0 ) ) {
fprintf ( V_28 , L_109 ,
V_128 ) ;
exit ( 1 ) ;
}
if ( ! V_129 ) {
V_129 = F_69 ( F_38 , NULL , NULL , F_6 ) ;
}
F_70 ( V_129 , F_71 ( V_126 ) , F_8 ( V_128 + V_127 ) ) ;
break;
}
case 'A' :
{
struct V_2 V_130 ;
memset ( & V_130 , 0 , sizeof( struct V_2 ) ) ;
if ( ! strptime ( V_128 , L_110 , & V_130 ) ) {
fprintf ( V_28 , L_111 ,
V_128 ) ;
exit ( 1 ) ;
}
V_131 = TRUE ;
V_130 . V_132 = - 1 ;
V_133 = mktime ( & V_130 ) ;
break;
}
case 'B' :
{
struct V_2 V_134 ;
memset ( & V_134 , 0 , sizeof( struct V_2 ) ) ;
if ( ! strptime ( V_128 , L_110 , & V_134 ) ) {
fprintf ( V_28 , L_111 ,
V_128 ) ;
exit ( 1 ) ;
}
V_131 = TRUE ;
V_134 . V_132 = - 1 ;
V_135 = mktime ( & V_134 ) ;
break;
}
case 'c' :
V_117 = ( int ) strtol ( V_128 , & V_109 , 10 ) ;
if ( V_109 == V_128 || * V_109 != '\0' ) {
fprintf ( V_28 , L_112 ,
V_128 ) ;
exit ( 1 ) ;
}
if ( V_117 <= 0 ) {
fprintf ( V_28 , L_113 ,
V_117 ) ;
exit ( 1 ) ;
}
break;
case 'C' :
{
int V_136 = 0 , V_137 = 0 ;
switch ( sscanf ( V_128 , L_114 , & V_137 , & V_136 ) ) {
case 1 :
V_136 = V_137 ;
V_137 = 0 ;
break;
case 2 :
break;
default:
fprintf ( V_28 , L_115 ,
V_128 ) ;
exit ( 1 ) ;
break;
}
if ( V_136 > 0 ) {
V_110 . V_138 += V_136 ;
if ( V_137 > 0 )
V_110 . V_139 += V_137 ;
else
V_110 . V_140 += V_137 ;
} else if ( V_136 < 0 ) {
V_110 . V_141 += V_136 ;
if ( V_137 > 0 )
V_110 . V_142 += V_137 ;
else
V_110 . V_143 += V_137 ;
}
break;
}
case 'd' :
V_144 = TRUE ;
V_145 = FALSE ;
V_63 = V_71 ;
break;
case 'D' :
V_144 = TRUE ;
V_145 = FALSE ;
V_63 = ( int ) strtol ( V_128 , & V_109 , 10 ) ;
if ( V_109 == V_128 || * V_109 != '\0' ) {
fprintf ( V_28 , L_116 ,
V_128 ) ;
exit ( 1 ) ;
}
if ( V_63 < 0 || V_63 > V_72 ) {
fprintf ( V_28 , L_117 ,
V_63 , V_72 ) ;
exit ( 1 ) ;
}
break;
case 'E' :
V_146 = F_72 ( V_128 , & V_109 ) ;
if ( V_109 == V_128 || V_146 < 0.0 || V_146 > 1.0 ) {
fprintf ( V_28 , L_118 ,
V_128 ) ;
exit ( 1 ) ;
}
srand ( ( unsigned int ) ( time ( NULL ) + F_73 () ) ) ;
break;
case 'F' :
V_94 = F_74 ( V_128 ) ;
if ( V_94 < 0 ) {
fprintf ( V_28 , L_119 ,
V_128 ) ;
F_27 () ;
exit ( 1 ) ;
}
break;
case 'h' :
printf ( L_104
L_120
L_121 ,
F_59 () ) ;
F_22 ( stdout ) ;
exit ( 0 ) ;
break;
case 'i' :
V_120 = atoi ( V_128 ) ;
if ( V_120 <= 0 ) {
fprintf ( V_28 , L_122 ,
V_128 ) ;
exit ( 1 ) ;
}
break;
case 'I' :
V_61 = atoi ( V_128 ) ;
if( V_61 <= 0 ) {
fprintf ( V_28 , L_123 , V_128 ) ;
exit ( 1 ) ;
}
break;
case 'L' :
V_111 = TRUE ;
break;
case 'o' :
V_123 = ( T_7 ) strtol ( V_128 , & V_109 , 10 ) ;
break;
case 'r' :
V_147 = ! V_147 ;
break;
case 's' :
V_88 = ( T_7 ) strtol ( V_128 , & V_109 , 10 ) ;
if ( V_109 == V_128 || * V_109 != '\0' ) {
fprintf ( V_28 , L_124 ,
V_128 ) ;
exit ( 1 ) ;
}
break;
case 'S' :
F_12 ( V_128 ) ;
V_148 = TRUE ;
break;
case 't' :
F_11 ( V_128 ) ;
break;
case 'T' :
V_95 = F_75 ( V_128 ) ;
if ( V_95 < 0 ) {
fprintf ( V_28 , L_125 ,
V_128 ) ;
F_35 () ;
exit ( 1 ) ;
}
break;
case 'v' :
V_35 = ! V_35 ;
break;
case 'V' :
F_76 ( L_126 , V_98 , V_99 ) ;
F_77 ( V_98 , TRUE ) ;
F_77 ( V_99 , TRUE ) ;
exit ( 0 ) ;
break;
case 'w' :
V_144 = FALSE ;
V_145 = TRUE ;
V_63 = V_72 ;
F_13 ( V_128 ) ;
break;
case '?' :
switch( V_149 ) {
case 'F' :
F_27 () ;
break;
case 'T' :
F_35 () ;
break;
default:
F_22 ( V_28 ) ;
break;
}
exit ( 1 ) ;
break;
}
}
#ifdef F_78
fprintf ( V_28 , L_127 , V_150 , V_96 ) ;
#endif
if ( ( V_96 - V_150 ) < 1 ) {
F_22 ( V_28 ) ;
exit ( 1 ) ;
}
if ( V_131 && ! V_135 ) {
struct V_2 V_134 ;
memset ( & V_134 , 0 , sizeof( struct V_2 ) ) ;
V_134 . V_6 = 135 ;
V_134 . V_8 = 31 ;
V_134 . V_7 = 11 ;
V_135 = mktime ( & V_134 ) ;
}
F_79 ( & V_122 ) ;
if ( V_133 > V_135 ) {
fprintf ( V_28 , L_128 ) ;
exit ( 1 ) ;
}
if ( V_117 > 0 && V_120 > 0 ) {
fprintf ( V_28 , L_129 ) ;
fprintf ( V_28 , L_130 ) ;
exit ( 1 ) ;
}
V_100 = F_80 ( V_97 [ V_150 ] , V_151 , & V_102 , & V_103 , FALSE ) ;
if ( ! V_100 ) {
fprintf ( V_28 , L_131 , V_97 [ V_150 ] ,
F_81 ( V_102 ) ) ;
if ( V_103 != NULL ) {
fprintf ( V_28 , L_132 , V_103 ) ;
F_6 ( V_103 ) ;
}
exit ( 2 ) ;
}
if ( V_35 ) {
fprintf ( V_28 , L_133 , V_97 [ V_150 ] ,
F_31 ( F_82 ( V_100 ) ) ) ;
}
V_89 = F_83 ( V_100 ) ;
V_90 = F_84 ( V_100 ) ;
V_91 = F_85 ( V_100 ) ;
if ( ( V_96 - V_150 ) >= 2 ) {
if ( V_95 == - 2 )
V_95 = F_86 ( V_100 ) ;
for ( V_41 = V_150 + 2 ; V_41 < V_96 ; V_41 ++ )
if ( F_9 ( V_97 [ V_41 ] ) == FALSE )
break;
if ( V_144 || V_145 ) {
for ( V_41 = 0 ; V_41 < V_63 ; V_41 ++ ) {
memset ( & V_64 [ V_41 ] . V_65 , 0 , 16 ) ;
V_64 [ V_41 ] . V_57 = 0 ;
F_79 ( & V_64 [ V_41 ] . V_67 ) ;
}
}
while ( F_87 ( V_100 , & V_102 , & V_103 , & V_114 ) ) {
V_116 ++ ;
V_14 = F_88 ( V_100 ) ;
if ( V_116 == 1 ) {
if ( V_117 > 0 || V_120 > 0 ) {
if ( ! F_7 ( V_97 [ V_150 + 1 ] , & V_15 , & V_16 ) )
goto V_152;
V_87 = F_4 ( V_121 ++ , V_14 , V_15 , V_16 ) ;
} else {
V_87 = F_8 ( V_97 [ V_150 + 1 ] ) ;
}
F_89 ( V_87 ) ;
if ( V_89 -> V_153 == NULL ) {
V_89 -> V_153 = F_8 ( L_134 V_154 ) ;
}
V_93 = F_48 ( V_87 ,
V_88 ? F_90 ( V_88 , F_91 ( V_100 ) ) : F_91 ( V_100 ) ,
V_89 , V_90 , V_91 , & V_92 ) ;
if ( V_93 == NULL ) {
fprintf ( V_28 , L_135 ,
V_87 , F_81 ( V_92 ) ) ;
goto V_152;
}
}
V_4 = F_92 ( V_100 ) ;
if ( V_14 -> V_21 & V_22 ) {
if ( F_19 ( & V_122 ) ) {
V_122 . V_5 = V_14 -> V_23 . V_5 ;
V_122 . V_53 = V_14 -> V_23 . V_53 ;
}
if ( V_120 > 0 ) {
while ( ( V_14 -> V_23 . V_5 - V_122 . V_5 > V_120 )
|| ( V_14 -> V_23 . V_5 - V_122 . V_5 == V_120
&& V_14 -> V_23 . V_53 >= V_122 . V_53 ) ) {
if ( ! F_93 ( V_93 , & V_92 ) ) {
fprintf ( V_28 , L_136 ,
V_87 , F_81 ( V_92 ) ) ;
goto V_152;
}
V_122 . V_5 = V_122 . V_5 + V_120 ;
F_6 ( V_87 ) ;
V_87 = F_4 ( V_121 ++ , V_14 , V_15 , V_16 ) ;
F_89 ( V_87 ) ;
if ( V_35 )
fprintf ( V_28 , L_137 , V_87 ) ;
V_93 = F_48 ( V_87 ,
V_88 ? F_90 ( V_88 , F_91 ( V_100 ) ) : F_91 ( V_100 ) ,
V_89 , V_90 , V_91 , & V_92 ) ;
if ( V_93 == NULL ) {
fprintf ( V_28 , L_135 ,
V_87 , F_81 ( V_92 ) ) ;
goto V_152;
}
}
}
}
if ( V_117 > 0 ) {
if ( V_118 > 0 && V_118 % V_117 == 0 ) {
if ( ! F_93 ( V_93 , & V_92 ) ) {
fprintf ( V_28 , L_136 ,
V_87 , F_81 ( V_92 ) ) ;
goto V_152;
}
F_6 ( V_87 ) ;
V_87 = F_4 ( V_121 ++ , V_14 , V_15 , V_16 ) ;
F_89 ( V_87 ) ;
if ( V_35 )
fprintf ( V_28 , L_137 , V_87 ) ;
V_93 = F_48 ( V_87 ,
V_88 ? F_90 ( V_88 , F_91 ( V_100 ) ) : F_91 ( V_100 ) ,
V_89 , V_90 , V_91 , & V_92 ) ;
if ( V_93 == NULL ) {
fprintf ( V_28 , L_135 ,
V_87 , F_81 ( V_92 ) ) ;
goto V_152;
}
}
}
if ( V_131 ) {
if ( V_14 -> V_21 & V_22 )
V_119 = ( V_14 -> V_23 . V_5 >= V_133 ) && ( V_14 -> V_23 . V_5 < V_135 ) ;
else
V_119 = FALSE ;
} else {
V_119 = TRUE ;
}
if ( V_119 && ( ( ! F_10 ( V_112 ) && ! V_147 )
|| ( F_10 ( V_112 ) && V_147 ) ) ) {
if ( V_35 && ! V_144 && ! V_145 )
fprintf ( V_28 , L_138 , V_112 ) ;
V_14 = F_88 ( V_100 ) ;
if ( V_88 != 0 ) {
if ( V_14 -> V_155 > V_88 ) {
V_124 = * V_14 ;
V_124 . V_155 = V_88 ;
V_14 = & V_124 ;
}
if ( V_111 && V_14 -> V_57 > V_88 ) {
V_124 = * V_14 ;
V_124 . V_57 = V_88 ;
V_14 = & V_124 ;
}
}
V_124 = * V_14 ;
F_94 ( V_110 , & V_124 , V_14 , & V_4 , V_111 ) ;
V_14 = & V_124 ;
if ( V_14 -> V_21 & V_22 ) {
if ( V_148 ) {
if ( V_156 . V_5 || V_156 . V_53 ) {
if ( ! V_54 . V_48 ) {
T_2 V_66 ;
T_2 V_68 ;
V_66 . V_5 = V_14 -> V_23 . V_5 ;
V_66 . V_53 = V_14 -> V_23 . V_53 ;
F_20 ( & V_68 , & V_66 , & V_156 ) ;
if ( V_68 . V_5 < 0 || V_68 . V_53 < 0 ) {
V_124 = * V_14 ;
V_124 . V_23 . V_5 = V_156 . V_5 + V_54 . V_51 . V_5 ;
V_124 . V_23 . V_53 = V_156 . V_53 ;
if ( V_124 . V_23 . V_53 + V_54 . V_51 . V_53 > V_52 ) {
V_124 . V_23 . V_5 ++ ;
V_124 . V_23 . V_53 += V_54 . V_51 . V_53 - V_52 ;
} else {
V_124 . V_23 . V_53 += V_54 . V_51 . V_53 ;
}
V_14 = & V_124 ;
}
} else {
V_124 = * V_14 ;
V_124 . V_23 . V_5 = V_156 . V_5 + V_54 . V_51 . V_5 ;
V_124 . V_23 . V_53 = V_156 . V_53 ;
if ( V_124 . V_23 . V_53 + V_54 . V_51 . V_53 > V_52 ) {
V_124 . V_23 . V_5 ++ ;
V_124 . V_23 . V_53 += V_54 . V_51 . V_53 - V_52 ;
} else {
V_124 . V_23 . V_53 += V_54 . V_51 . V_53 ;
}
V_14 = & V_124 ;
}
}
V_156 . V_5 = V_14 -> V_23 . V_5 ;
V_156 . V_53 = V_14 -> V_23 . V_53 ;
}
if ( V_14 -> V_23 . V_5 > 0 && V_47 . V_51 . V_5 != 0 ) {
V_124 = * V_14 ;
if ( V_47 . V_48 )
V_124 . V_23 . V_5 -= V_47 . V_51 . V_5 ;
else
V_124 . V_23 . V_5 += V_47 . V_51 . V_5 ;
V_14 = & V_124 ;
}
if ( V_14 -> V_23 . V_5 > 0 && V_47 . V_51 . V_53 != 0 ) {
V_124 = * V_14 ;
if ( V_47 . V_48 ) {
if ( V_124 . V_23 . V_53 < V_47 . V_51 . V_53 ) {
V_124 . V_23 . V_5 -- ;
V_124 . V_23 . V_53 += V_52 ;
}
V_124 . V_23 . V_53 -= V_47 . V_51 . V_53 ;
} else {
if ( V_124 . V_23 . V_53 + V_47 . V_51 . V_53 > V_52 ) {
V_124 . V_23 . V_5 ++ ;
V_124 . V_23 . V_53 += V_47 . V_51 . V_53 - V_52 ;
} else {
V_124 . V_23 . V_53 += V_47 . V_51 . V_53 ;
}
}
V_14 = & V_124 ;
}
}
if ( V_144 ) {
if ( F_14 ( V_4 , V_14 -> V_155 ) ) {
if ( V_35 ) {
fprintf ( V_28 , L_139 ,
V_112 , V_14 -> V_155 ) ;
for ( V_41 = 0 ; V_41 < 16 ; V_41 ++ )
fprintf ( V_28 , L_140 ,
( unsigned char ) V_64 [ V_62 ] . V_65 [ V_41 ] ) ;
fprintf ( V_28 , L_15 ) ;
}
V_113 ++ ;
V_112 ++ ;
continue;
} else {
if ( V_35 ) {
fprintf ( V_28 , L_141 ,
V_112 , V_14 -> V_155 ) ;
for ( V_41 = 0 ; V_41 < 16 ; V_41 ++ )
fprintf ( V_28 , L_140 ,
( unsigned char ) V_64 [ V_62 ] . V_65 [ V_41 ] ) ;
fprintf ( V_28 , L_15 ) ;
}
}
}
if ( V_14 -> V_21 & V_22 ) {
if ( V_145 ) {
T_2 V_66 ;
V_66 . V_5 = V_14 -> V_23 . V_5 ;
V_66 . V_53 = V_14 -> V_23 . V_53 ;
if ( F_18 ( V_4 , V_14 -> V_155 , & V_66 ) ) {
if ( V_35 ) {
fprintf ( V_28 , L_139 ,
V_112 , V_14 -> V_155 ) ;
for ( V_41 = 0 ; V_41 < 16 ; V_41 ++ )
fprintf ( V_28 , L_140 ,
( unsigned char ) V_64 [ V_62 ] . V_65 [ V_41 ] ) ;
fprintf ( V_28 , L_15 ) ;
}
V_113 ++ ;
V_112 ++ ;
continue;
} else {
if ( V_35 ) {
fprintf ( V_28 , L_141 ,
V_112 , V_14 -> V_155 ) ;
for ( V_41 = 0 ; V_41 < 16 ; V_41 ++ )
fprintf ( V_28 , L_140 ,
( unsigned char ) V_64 [ V_62 ] . V_65 [ V_41 ] ) ;
fprintf ( V_28 , L_15 ) ;
}
}
}
}
if ( V_123 > V_14 -> V_155 ) {
fprintf ( V_28 , L_142 ,
V_123 , V_14 -> V_155 , V_112 ) ;
}
if ( V_146 > 0.0 && V_123 <= V_14 -> V_155 ) {
int V_157 = 0 ;
if ( F_82 ( V_100 ) == V_158 )
V_157 = F_95 ( V_4 ) ;
V_157 += V_123 ;
for ( V_41 = V_157 ; V_41 < ( int ) V_14 -> V_155 ; V_41 ++ ) {
if ( rand () <= V_146 * V_159 ) {
V_115 = rand () / ( V_159 / V_160 + 1 ) ;
if ( V_115 < V_161 ) {
V_4 [ V_41 ] ^= 1 << ( rand () / ( V_159 / 8 + 1 ) ) ;
V_115 = V_160 ;
} else {
V_115 -= V_162 ;
}
if ( V_115 < V_162 ) {
V_4 [ V_41 ] = rand () / ( V_159 / 255 + 1 ) ;
V_115 = V_160 ;
} else {
V_115 -= V_162 ;
}
if ( V_115 < V_163 ) {
V_4 [ V_41 ] = V_164 [ rand () / ( V_159 / V_165 + 1 ) ] ;
V_115 = V_160 ;
} else {
V_115 -= V_163 ;
}
if ( V_115 < V_166 ) {
if ( ( unsigned int ) V_41 < V_14 -> V_155 - 2 )
F_96 ( ( char * ) & V_4 [ V_41 ] , L_105 , 2 ) ;
V_115 = V_160 ;
} else {
V_115 -= V_166 ;
}
if ( V_115 < V_167 ) {
for ( V_101 = V_41 ; V_101 < ( int ) V_14 -> V_155 ; V_101 ++ )
V_4 [ V_101 ] = 0xAA ;
V_41 = V_14 -> V_155 ;
}
}
}
}
if ( V_129 ) {
const char * V_168 =
( const char * ) F_97 ( V_129 , F_71 ( V_116 ) ) ;
if ( V_168 != NULL ) {
V_124 = * V_14 ;
V_124 . V_169 = F_8 ( V_168 ) ;
V_14 = & V_124 ;
}
}
if ( ! F_98 ( V_93 , V_14 , V_4 , & V_92 , & V_104 ) ) {
switch ( V_92 ) {
case V_170 :
fprintf ( V_28 ,
L_143 ,
V_116 , V_97 [ V_150 ] ,
F_31 ( V_94 ) ) ;
break;
case V_171 :
fprintf ( V_28 ,
L_144 ,
V_116 , V_97 [ V_150 ] ,
F_31 ( V_94 ) ) ;
break;
case V_172 :
fprintf ( V_28 ,
L_145 ,
V_116 , V_97 [ V_150 ] ,
F_31 ( V_94 ) ) ;
break;
case V_173 :
fprintf ( V_28 ,
L_146 ,
V_116 , V_97 [ V_150 ] ,
F_31 ( V_94 ) ,
V_104 != NULL ? V_104 : L_147 ) ;
F_6 ( V_104 ) ;
break;
default:
fprintf ( V_28 , L_136 ,
V_87 , F_81 ( V_92 ) ) ;
break;
}
goto V_152;
}
V_118 ++ ;
}
V_112 ++ ;
}
F_6 ( V_15 ) ;
F_6 ( V_16 ) ;
if ( V_102 != 0 ) {
fprintf ( V_28 ,
L_148 ,
V_97 [ V_150 ] , F_81 ( V_102 ) ) ;
if ( V_103 != NULL ) {
fprintf ( V_28 , L_132 , V_103 ) ;
F_6 ( V_103 ) ;
}
}
if ( ! V_93 ) {
F_6 ( V_87 ) ;
V_87 = F_8 ( V_97 [ V_150 + 1 ] ) ;
V_93 = F_48 ( V_87 ,
V_88 ? F_90 ( V_88 , F_91 ( V_100 ) ) : F_91 ( V_100 ) ,
V_89 , V_90 , V_91 , & V_92 ) ;
if ( V_93 == NULL ) {
fprintf ( V_28 , L_135 ,
V_87 , F_81 ( V_92 ) ) ;
goto V_152;
}
}
F_6 ( V_90 ) ;
V_90 = NULL ;
if ( ! F_93 ( V_93 , & V_92 ) ) {
fprintf ( V_28 , L_136 , V_87 ,
F_81 ( V_92 ) ) ;
goto V_152;
}
F_99 ( V_89 ) ;
V_89 = NULL ;
F_100 ( V_91 ) ;
V_91 = NULL ;
F_6 ( V_87 ) ;
if ( V_129 ) {
F_101 ( V_129 ) ;
}
}
if ( V_144 ) {
fprintf ( V_28 , L_149 ,
V_112 - 1 , F_102 ( V_112 - 1 , L_150 , L_151 ) , V_113 ,
F_102 ( V_113 , L_150 , L_151 ) , V_63 ) ;
} else if ( V_145 ) {
fprintf ( V_28 , L_152 ,
V_112 - 1 , F_102 ( V_112 - 1 , L_150 , L_151 ) , V_113 ,
F_102 ( V_113 , L_150 , L_151 ) ,
( long ) V_55 . V_5 ,
( long int ) V_55 . V_53 ) ;
}
return 0 ;
V_152:
F_99 ( V_89 ) ;
F_100 ( V_91 ) ;
F_6 ( V_90 ) ;
exit ( 2 ) ;
}
static int
F_95 ( T_6 * V_4 )
{
int V_174 = 0 ;
for ( V_174 = 0 ; V_4 [ V_174 ] != '\0' ; V_174 ++ ) ;
V_174 ++ ;
V_174 ++ ;
for (; V_4 [ V_174 ] != '\0' ; V_174 ++ ) ;
V_174 ++ ;
for (; V_4 [ V_174 ] != '\0' ; V_174 ++ ) ;
V_174 ++ ;
for (; V_4 [ V_174 ] != '\0' ; V_174 ++ ) ;
V_174 ++ ;
for (; V_4 [ V_174 ] != '\0' ; V_174 ++ ) ;
V_174 ++ ;
V_174 += 2 ;
return V_174 ;
}
static void
F_94 ( T_25 V_110 , struct V_13 * V_175 ,
const struct V_13 * V_176 , T_6 * * V_4 ,
T_4 V_111 )
{
if ( V_176 -> V_177 != V_178 )
return;
if ( V_110 . V_138 == 0 )
V_110 . V_139 = V_110 . V_140 = 0 ;
if ( V_110 . V_141 == 0 )
V_110 . V_142 = V_110 . V_143 = 0 ;
if ( V_110 . V_140 < 0 ) {
V_110 . V_139 += V_176 -> V_155 + V_110 . V_140 ;
V_110 . V_140 = 0 ;
}
if ( V_110 . V_142 > 0 ) {
V_110 . V_143 += V_110 . V_142 - V_176 -> V_155 ;
V_110 . V_142 = 0 ;
}
if ( V_110 . V_138 && V_110 . V_141 ) {
if ( V_110 . V_139 > ( ( int ) V_176 -> V_155 + V_110 . V_143 ) ) {
int V_179 , V_180 ;
V_180 = V_176 -> V_155 + V_110 . V_143 + V_110 . V_141 ;
V_179 = - V_110 . V_141 ;
V_110 . V_143 = V_110 . V_138 + V_110 . V_139 - V_176 -> V_155 ;
V_110 . V_141 = - V_110 . V_138 ;
V_110 . V_138 = V_179 ;
V_110 . V_139 = V_180 ;
}
}
if ( V_176 -> V_155 < ( T_7 ) ( V_110 . V_139 - V_110 . V_143 ) ) {
V_110 . V_138 = 0 ;
V_110 . V_141 = 0 ;
}
if ( ( T_7 ) ( V_110 . V_138 - V_110 . V_141 ) >
( V_176 -> V_155 - ( T_7 ) ( V_110 . V_139 - V_110 . V_143 ) ) ) {
V_110 . V_138 = V_176 -> V_155 - ( V_110 . V_139 - V_110 . V_143 ) ;
V_110 . V_141 = 0 ;
}
if ( V_110 . V_138 > 0 ) {
* V_175 = * V_176 ;
if ( V_110 . V_139 > 0 ) {
memmove ( * V_4 + V_110 . V_139 ,
* V_4 + V_110 . V_139 + V_110 . V_138 ,
V_175 -> V_155 - V_110 . V_138 ) ;
} else {
* V_4 += V_110 . V_138 ;
}
V_175 -> V_155 -= V_110 . V_138 ;
if ( V_111 ) {
if ( V_176 -> V_57 > ( T_7 ) V_110 . V_138 )
V_175 -> V_57 -= V_110 . V_138 ;
else
V_175 -> V_57 = 0 ;
}
V_176 = V_175 ;
}
if ( V_110 . V_141 < 0 ) {
* V_175 = * V_176 ;
if ( V_110 . V_143 < 0 ) {
memmove ( * V_4 + ( T_10 ) V_175 -> V_155 + ( V_110 . V_141 + V_110 . V_143 ) ,
* V_4 + ( T_10 ) V_175 -> V_155 + V_110 . V_143 ,
- V_110 . V_143 ) ;
}
V_175 -> V_155 += V_110 . V_141 ;
if ( V_111 ) {
if ( ( ( signed int ) V_176 -> V_57 + V_110 . V_141 ) > 0 )
V_175 -> V_57 += V_110 . V_141 ;
else
V_175 -> V_57 = 0 ;
}
}
}
