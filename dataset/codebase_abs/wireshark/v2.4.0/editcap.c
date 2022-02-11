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
F_9 ( char * V_30 , T_3 * V_31 )
{
char * V_32 ;
char * V_33 ;
if ( V_34 >= V_35 ) {
fprintf ( V_28 , L_5 ) ;
return ( FALSE ) ;
}
if ( V_36 )
fprintf ( V_28 , L_6 , V_30 ) ;
if ( ( V_32 = strchr ( V_30 , '-' ) ) == NULL ) {
if ( V_36 )
fprintf ( V_28 , L_7 ) ;
V_37 [ V_34 ] . V_38 = FALSE ;
V_37 [ V_34 ] . V_39 = F_10 ( V_30 , L_8 ) ;
if ( V_37 [ V_34 ] . V_39 > * V_31 )
* V_31 = V_37 [ V_34 ] . V_39 ;
if ( V_36 )
fprintf ( V_28 , L_9 , V_37 [ V_34 ] . V_39 ) ;
} else {
if ( V_36 )
fprintf ( V_28 , L_10 ) ;
* V_32 = '\0' ;
V_33 = V_32 + 1 ;
V_37 [ V_34 ] . V_38 = TRUE ;
V_37 [ V_34 ] . V_39 = F_10 ( V_30 , L_11 ) ;
V_37 [ V_34 ] . V_40 = F_10 ( V_33 , L_12 ) ;
if ( V_37 [ V_34 ] . V_40 == 0 )
{
V_37 [ V_34 ] . V_40 = * V_31 = V_41 ;
}
else if ( V_37 [ V_34 ] . V_40 > * V_31 )
* V_31 = V_37 [ V_34 ] . V_40 ;
if ( V_36 )
fprintf ( V_28 , L_13 , V_37 [ V_34 ] . V_39 ,
V_37 [ V_34 ] . V_40 ) ;
}
V_34 ++ ;
return ( TRUE ) ;
}
static int
F_11 ( T_3 V_42 )
{
T_3 V_43 ;
for ( V_43 = 0 ; V_43 < V_34 ; V_43 ++ ) {
if ( V_37 [ V_43 ] . V_38 ) {
if ( V_37 [ V_43 ] . V_39 <= V_42 && V_37 [ V_43 ] . V_40 >= V_42 )
return 1 ;
} else {
if ( V_42 == V_37 [ V_43 ] . V_39 )
return 1 ;
}
}
return 0 ;
}
static T_4
F_12 ( char * V_44 )
{
char * V_45 , * V_46 ;
long V_47 ;
T_5 V_48 ;
if ( ! V_44 )
return TRUE ;
while ( * V_44 == ' ' || * V_44 == '\t' )
V_44 ++ ;
if ( * V_44 == '-' ) {
V_49 . V_50 = 1 ;
V_44 ++ ;
}
if ( * V_44 == '.' ) {
V_47 = 0 ;
V_45 = V_44 ;
} else {
V_47 = strtol ( V_44 , & V_45 , 10 ) ;
if ( V_45 == NULL || V_45 == V_44
|| V_47 == V_51 || V_47 == V_52 ) {
fprintf ( V_28 , L_14 ,
V_44 ) ;
return FALSE ;
}
if ( V_47 < 0 ) {
fprintf ( V_28 , L_14 ,
V_44 ) ;
return FALSE ;
}
}
V_49 . V_53 . V_5 = V_47 ;
if ( * V_45 != '\0' ) {
V_47 = strtol ( & ( V_45 [ 1 ] ) , & V_46 , 10 ) ;
if ( ( V_46 - & ( V_45 [ 1 ] ) ) > 9 ) {
V_45 [ 10 ] = 't' ;
V_47 = strtol ( & ( V_45 [ 1 ] ) , & V_46 , 10 ) ;
}
if ( * V_45 != '.' || V_46 == NULL || V_46 == V_45 || V_47 < 0
|| V_47 > V_54 || V_47 == V_51 || V_47 == V_52 ) {
fprintf ( V_28 , L_14 ,
V_44 ) ;
return FALSE ;
}
} else {
return TRUE ;
}
V_48 = V_46 - V_45 - 1 ;
while( V_48 < 9 ) {
V_47 *= 10 ;
V_48 ++ ;
}
V_49 . V_53 . V_55 = ( int ) V_47 ;
return TRUE ;
}
static T_4
F_13 ( char * V_44 )
{
char * V_45 , * V_46 ;
long V_47 ;
T_5 V_48 ;
if ( ! V_44 )
return TRUE ;
while ( * V_44 == ' ' || * V_44 == '\t' )
V_44 ++ ;
if ( * V_44 == '-' ) {
V_56 . V_50 = 1 ;
V_44 ++ ;
}
if ( * V_44 == '.' ) {
V_47 = 0 ;
V_45 = V_44 ;
} else {
V_47 = strtol ( V_44 , & V_45 , 10 ) ;
if ( V_45 == NULL || V_45 == V_44
|| V_47 == V_51 || V_47 == V_52 ) {
fprintf ( V_28 , L_14 ,
V_44 ) ;
return FALSE ;
}
if ( V_47 < 0 ) {
fprintf ( V_28 , L_14 ,
V_44 ) ;
return FALSE ;
}
}
V_56 . V_53 . V_5 = V_47 ;
if ( * V_45 != '\0' ) {
V_47 = strtol ( & ( V_45 [ 1 ] ) , & V_46 , 10 ) ;
if ( ( V_46 - & ( V_45 [ 1 ] ) ) > 9 ) {
V_45 [ 10 ] = 't' ;
V_47 = strtol ( & ( V_45 [ 1 ] ) , & V_46 , 10 ) ;
}
if ( * V_45 != '.' || V_46 == NULL || V_46 == V_45 || V_47 < 0
|| V_47 > V_54 || V_47 == V_51 || V_47 == V_52 ) {
fprintf ( V_28 , L_14 ,
V_44 ) ;
return FALSE ;
}
} else {
return TRUE ;
}
V_48 = V_46 - V_45 - 1 ;
while( V_48 < 9 ) {
V_47 *= 10 ;
V_48 ++ ;
}
V_56 . V_53 . V_55 = ( int ) V_47 ;
return TRUE ;
}
static T_4
F_14 ( char * V_44 )
{
char * V_45 , * V_46 ;
long V_47 ;
T_5 V_48 ;
if ( ! V_44 )
return TRUE ;
while ( * V_44 == ' ' || * V_44 == '\t' )
V_44 ++ ;
if ( * V_44 == '-' )
V_44 ++ ;
if ( * V_44 == '.' ) {
V_47 = 0 ;
V_45 = V_44 ;
} else {
V_47 = strtol ( V_44 , & V_45 , 10 ) ;
if ( V_45 == NULL || V_45 == V_44
|| V_47 == V_51 || V_47 == V_52 ) {
fprintf ( V_28 , L_15 ,
V_44 ) ;
return FALSE ;
}
if ( V_47 < 0 ) {
fprintf ( V_28 , L_16 ,
V_44 ) ;
return FALSE ;
}
}
V_57 . V_5 = V_47 ;
if ( * V_45 != '\0' ) {
V_47 = strtol ( & ( V_45 [ 1 ] ) , & V_46 , 10 ) ;
if ( ( V_46 - & ( V_45 [ 1 ] ) ) > 9 ) {
V_45 [ 10 ] = 't' ;
V_47 = strtol ( & ( V_45 [ 1 ] ) , & V_46 , 10 ) ;
}
if ( * V_45 != '.' || V_46 == NULL || V_46 == V_45 || V_47 < 0
|| V_47 > V_54 || V_47 == V_51 || V_47 == V_52 ) {
fprintf ( V_28 , L_17 ,
V_44 ) ;
return FALSE ;
}
} else {
return TRUE ;
}
V_48 = V_46 - V_45 - 1 ;
while( V_48 < 9 ) {
V_47 *= 10 ;
V_48 ++ ;
}
V_57 . V_55 = ( int ) V_47 ;
return TRUE ;
}
static void
F_15 ( T_6 * V_58 , T_7 * V_59 ) {
if ( F_16 ( V_58 + V_60 ) == V_61 ) {
int V_62 ;
V_58 = V_58 + V_60 ;
V_62 = * V_59 - ( V_60 + V_63 ) ;
memmove ( V_58 , V_58 + V_63 , V_62 ) ;
* V_59 -= 4 ;
}
}
static void
F_17 ( const struct V_13 * V_14 , T_6 * V_58 , T_7 * V_59 ) {
switch ( V_14 -> V_64 ) {
case V_65 :
F_15 ( V_58 , V_59 ) ;
break;
default:
break;
}
}
static T_4
F_18 ( T_6 * V_58 , T_7 V_59 ) {
int V_43 ;
T_7 V_66 = V_67 ;
T_7 V_68 ;
T_6 * V_69 ;
if ( V_59 <= V_67 ) {
V_66 = 0 ;
}
V_69 = & V_58 [ V_66 ] ;
V_68 = V_59 - ( V_66 ) ;
V_70 ++ ;
if ( V_70 >= V_71 )
V_70 = 0 ;
F_19 ( V_72 , V_73 [ V_70 ] . V_74 , V_69 , V_68 ) ;
V_73 [ V_70 ] . V_59 = V_59 ;
for ( V_43 = 0 ; V_43 < V_71 ; V_43 ++ ) {
if ( V_43 == V_70 )
continue;
if ( V_73 [ V_43 ] . V_59 == V_73 [ V_70 ] . V_59
&& memcmp ( V_73 [ V_43 ] . V_74 , V_73 [ V_70 ] . V_74 , 16 ) == 0 ) {
return TRUE ;
}
}
return FALSE ;
}
static T_4
F_20 ( T_6 * V_58 , T_7 V_59 , const T_2 * V_75 ) {
int V_43 ;
T_7 V_66 = V_67 ;
T_7 V_68 ;
T_6 * V_69 ;
if ( V_59 <= V_67 ) {
V_66 = 0 ;
}
V_69 = & V_58 [ V_66 ] ;
V_68 = V_59 - ( V_66 ) ;
V_70 ++ ;
if ( V_70 >= V_71 )
V_70 = 0 ;
F_19 ( V_72 , V_73 [ V_70 ] . V_74 , V_69 , V_68 ) ;
V_73 [ V_70 ] . V_59 = V_59 ;
V_73 [ V_70 ] . V_76 . V_5 = V_75 -> V_5 ;
V_73 [ V_70 ] . V_76 . V_55 = V_75 -> V_55 ;
for ( V_43 = V_70 - 1 ; ; V_43 -- ) {
T_2 V_77 ;
int V_78 ;
if ( V_43 < 0 )
V_43 = V_71 - 1 ;
if ( V_43 == V_70 ) {
break;
}
if ( F_21 ( & ( V_73 [ V_43 ] . V_76 ) ) ) {
break;
}
F_22 ( & V_77 , V_75 , & V_73 [ V_43 ] . V_76 ) ;
if ( V_77 . V_5 < 0 || V_77 . V_55 < 0 ) {
continue;
}
V_78 = F_23 ( & V_77 , & V_57 ) ;
if ( V_78 > 0 ) {
break;
} else if ( V_73 [ V_43 ] . V_59 == V_73 [ V_70 ] . V_59
&& memcmp ( V_73 [ V_43 ] . V_74 , V_73 [ V_70 ] . V_74 , 16 ) == 0 ) {
return TRUE ;
}
}
return FALSE ;
}
static void
F_24 ( T_8 * V_79 )
{
fprintf ( V_79 , L_18 ) ;
fprintf ( V_79 , L_19 ) ;
fprintf ( V_79 , L_18 ) ;
fprintf ( V_79 , L_20 ) ;
fprintf ( V_79 , L_21 ) ;
fprintf ( V_79 , L_18 ) ;
fprintf ( V_79 , L_22 ) ;
fprintf ( V_79 , L_23 ) ;
fprintf ( V_79 , L_24 ) ;
fprintf ( V_79 , L_25 ) ;
fprintf ( V_79 , L_26 ) ;
fprintf ( V_79 , L_27 ) ;
fprintf ( V_79 , L_18 ) ;
fprintf ( V_79 , L_28 ) ;
fprintf ( V_79 , L_29 ) ;
fprintf ( V_79 , L_30 , V_80 ) ;
fprintf ( V_79 , L_31 ) ;
fprintf ( V_79 , L_32 , V_81 ) ;
fprintf ( V_79 , L_33 ) ;
fprintf ( V_79 , L_34 ) ;
fprintf ( V_79 , L_35 ) ;
fprintf ( V_79 , L_36 ) ;
fprintf ( V_79 , L_37 ) ;
fprintf ( V_79 , L_38 ) ;
fprintf ( V_79 , L_39 ) ;
fprintf ( V_79 , L_18 ) ;
fprintf ( V_79 , L_40 ) ;
fprintf ( V_79 , L_41 ) ;
fprintf ( V_79 , L_42 ) ;
fprintf ( V_79 , L_43 ) ;
fprintf ( V_79 , L_44 ) ;
fprintf ( V_79 , L_45 ) ;
fprintf ( V_79 , L_46 ) ;
fprintf ( V_79 , L_47 ) ;
fprintf ( V_79 , L_18 ) ;
fprintf ( V_79 , L_48 ) ;
fprintf ( V_79 , L_49 ) ;
fprintf ( V_79 , L_50 ) ;
fprintf ( V_79 , L_51 ) ;
fprintf ( V_79 , L_18 ) ;
fprintf ( V_79 , L_52 ) ;
fprintf ( V_79 , L_53 ) ;
fprintf ( V_79 , L_54 ) ;
fprintf ( V_79 , L_55 ) ;
fprintf ( V_79 , L_56 ) ;
fprintf ( V_79 , L_57 ) ;
fprintf ( V_79 , L_58 ) ;
fprintf ( V_79 , L_59 ) ;
fprintf ( V_79 , L_60 ) ;
fprintf ( V_79 , L_61 ) ;
fprintf ( V_79 , L_62 ) ;
fprintf ( V_79 , L_63 ) ;
fprintf ( V_79 , L_64 ) ;
fprintf ( V_79 , L_65 ) ;
fprintf ( V_79 , L_66 ) ;
fprintf ( V_79 , L_67 ) ;
fprintf ( V_79 , L_68 ) ;
fprintf ( V_79 , L_69 ) ;
fprintf ( V_79 , L_70 ) ;
fprintf ( V_79 , L_71 ) ;
fprintf ( V_79 , L_72 ) ;
fprintf ( V_79 , L_73 ) ;
fprintf ( V_79 , L_74 ) ;
fprintf ( V_79 , L_75 ) ;
fprintf ( V_79 , L_76 ) ;
fprintf ( V_79 , L_77 ) ;
fprintf ( V_79 , L_78 ) ;
fprintf ( V_79 , L_79 ) ;
fprintf ( V_79 , L_18 ) ;
fprintf ( V_79 , L_80 ) ;
fprintf ( V_79 , L_81 ) ;
fprintf ( V_79 , L_82 ) ;
fprintf ( V_79 , L_83 ) ;
fprintf ( V_79 , L_84 ) ;
fprintf ( V_79 , L_85 ) ;
fprintf ( V_79 , L_86 ) ;
fprintf ( V_79 , L_87 ) ;
fprintf ( V_79 , L_88 ) ;
fprintf ( V_79 , L_89 ) ;
fprintf ( V_79 , L_90 ) ;
fprintf ( V_79 , L_91 ) ;
fprintf ( V_79 , L_18 ) ;
fprintf ( V_79 , L_92 ) ;
fprintf ( V_79 , L_93 ) ;
fprintf ( V_79 , L_94 ) ;
fprintf ( V_79 , L_95 ) ;
fprintf ( V_79 , L_96 ) ;
fprintf ( V_79 , L_97 ) ;
fprintf ( V_79 , L_18 ) ;
}
static T_9
F_25 ( T_10 V_82 , T_10 V_83 )
{
return strcmp ( ( ( const struct V_84 * ) V_82 ) -> V_85 ,
( ( const struct V_84 * ) V_83 ) -> V_85 ) ;
}
static T_9
F_26 ( T_10 V_82 , T_10 V_83 )
{
return F_27 ( ( ( const struct V_84 * ) V_82 ) -> V_85 ,
( ( const struct V_84 * ) V_83 ) -> V_85 ) ;
}
static void
F_28 ( T_11 V_86 , T_11 T_12 V_87 )
{
fprintf ( V_28 , L_98 ,
( (struct V_84 * ) V_86 ) -> V_85 ,
( (struct V_84 * ) V_86 ) -> V_88 ) ;
}
static void
F_29 ( void ) {
int V_43 ;
struct V_84 * V_89 ;
T_13 * V_90 = NULL ;
V_89 = F_30 ( struct V_84 , V_91 ) ;
fprintf ( V_28 , L_99 ) ;
for ( V_43 = 0 ; V_43 < V_91 ; V_43 ++ ) {
if ( F_31 ( V_43 ) ) {
V_89 [ V_43 ] . V_85 = F_32 ( V_43 ) ;
V_89 [ V_43 ] . V_88 = F_33 ( V_43 ) ;
V_90 = F_34 ( V_90 , & V_89 [ V_43 ] , F_25 ) ;
}
}
F_35 ( V_90 , F_28 , NULL ) ;
F_36 ( V_90 ) ;
F_6 ( V_89 ) ;
}
static void
F_37 ( void ) {
int V_43 ;
struct V_84 * V_92 ;
T_13 * V_90 = NULL ;
V_92 = (struct V_84 * ) F_2 ( sizeof( struct V_84 ) * V_93 ) ;
fprintf ( V_28 , L_100 ) ;
for ( V_43 = 0 ; V_43 < V_93 ; V_43 ++ ) {
V_92 [ V_43 ] . V_85 = F_38 ( V_43 ) ;
if ( V_92 [ V_43 ] . V_85 != NULL ) {
V_92 [ V_43 ] . V_88 = F_39 ( V_43 ) ;
V_90 = F_34 ( V_90 , & V_92 [ V_43 ] , F_26 ) ;
}
}
F_35 ( V_90 , F_28 , NULL ) ;
F_36 ( V_90 ) ;
F_6 ( V_92 ) ;
}
static int
F_40 ( T_10 V_82 , T_10 V_83 , T_11 T_14 V_87 )
{
if ( F_41 ( V_82 ) < F_41 ( V_83 ) )
return - 1 ;
if ( F_41 ( V_82 ) > F_41 ( V_83 ) )
return 1 ;
return 0 ;
}
static void
F_42 ( const char * V_94 , T_15 V_95 )
{
fprintf ( V_28 , L_101 ) ;
vfprintf ( V_28 , V_94 , V_95 ) ;
fprintf ( V_28 , L_18 ) ;
}
static void
F_43 ( const char * V_94 , T_15 V_95 )
{
vfprintf ( V_28 , V_94 , V_95 ) ;
fprintf ( V_28 , L_18 ) ;
}
static T_16 *
F_44 ( const char * V_96 , T_7 V_97 ,
T_17 * V_98 ,
T_18 * V_99 ,
T_17 * V_100 , int * V_101 )
{
T_16 * V_102 ;
if ( strcmp ( V_96 , L_102 ) == 0 ) {
V_102 = F_45 ( V_103 , V_104 ,
V_97 , FALSE ,
V_98 , V_99 , V_100 , V_101 ) ;
} else {
V_102 = F_46 ( V_96 , V_103 , V_104 ,
V_97 , FALSE ,
V_98 , V_99 , V_100 , V_101 ) ;
}
return V_102 ;
}
int
main ( int V_105 , char * V_106 [] )
{
T_19 * V_107 ;
T_19 * V_108 ;
char * V_109 ;
T_20 * V_110 = NULL ;
int V_43 , V_111 , V_112 , V_101 ;
T_1 * V_113 , * V_114 ;
int V_115 ;
static const struct V_116 V_117 [] = {
{ L_103 , V_118 , NULL , 0x8100 } ,
{ L_104 , V_118 , NULL , 'h' } ,
{ L_105 , V_118 , NULL , 'V' } ,
{ 0 , 0 , 0 , 0 }
} ;
char * V_119 ;
T_7 V_97 = 0 ;
T_21 V_120 = { 0 , 0 , 0 , 0 , 0 , 0 } ;
T_4 V_121 = FALSE ;
T_16 * V_102 = NULL ;
unsigned int V_122 = 1 ;
unsigned int V_123 = 0 ;
T_22 V_124 ;
int V_125 ;
T_6 * V_4 ;
T_7 V_126 = 0 ;
T_7 V_127 = 0 ;
int V_128 = 0 ;
char * V_96 = NULL ;
T_4 V_129 ;
T_7 V_130 = 0 ;
int V_131 = 0 ;
T_2 V_132 ;
T_1 * V_15 = NULL ;
T_1 * V_16 = NULL ;
T_7 V_133 = 0 ;
T_3 V_134 = 0 ;
const struct V_13 * V_14 ;
struct V_13 V_135 ;
T_18 * V_99 = NULL ;
T_17 * V_98 = NULL ;
T_17 * V_100 = NULL ;
char * V_136 ;
int V_137 = V_138 ;
F_47 ( F_42 , F_43 ) ;
#ifdef F_48
F_49 ( V_105 , V_106 ) ;
F_50 () ;
#endif
V_107 = F_51 ( NULL , NULL ) ;
V_108 = F_52 ( NULL ) ;
F_53 ( L_106
L_18
L_107
L_18
L_107 ,
F_54 () , V_107 -> V_139 , V_108 -> V_139 ) ;
F_55 ( V_107 , TRUE ) ;
F_55 ( V_108 , TRUE ) ;
F_56 () ;
V_109 = F_57 ( V_106 [ 0 ] , main ) ;
if ( V_109 != NULL ) {
fprintf ( V_28 ,
L_108 ,
V_109 ) ;
F_6 ( V_109 ) ;
}
F_58 () ;
#ifdef F_59
F_60 ( F_42 , F_42 ,
NULL , NULL , NULL ) ;
F_61 ( V_140 ) ;
F_62 () ;
#endif
while ( ( V_115 = F_63 ( V_105 , V_106 , L_109 , V_117 , NULL ) ) != - 1 ) {
switch ( V_115 ) {
case 0x8100 :
{
V_141 = TRUE ;
break;
}
case 'a' :
{
T_3 V_142 ;
T_9 V_143 = 0 ;
if ( ( sscanf ( V_144 , L_110 , & V_142 , & V_143 ) < 1 ) || ( V_143 == 0 ) ) {
fprintf ( V_28 , L_111 ,
V_144 ) ;
V_137 = V_145 ;
goto V_146;
}
if ( ! V_147 ) {
V_147 = F_64 ( F_40 , NULL , NULL , F_6 ) ;
}
F_65 ( V_147 , F_66 ( V_142 ) , F_8 ( V_144 + V_143 ) ) ;
break;
}
case 'A' :
{
struct V_2 V_148 ;
memset ( & V_148 , 0 , sizeof( struct V_2 ) ) ;
if ( ! strptime ( V_144 , L_112 , & V_148 ) ) {
fprintf ( V_28 , L_113 ,
V_144 ) ;
V_137 = V_145 ;
goto V_146;
}
V_149 = TRUE ;
V_148 . V_150 = - 1 ;
V_151 = mktime ( & V_148 ) ;
break;
}
case 'B' :
{
struct V_2 V_152 ;
memset ( & V_152 , 0 , sizeof( struct V_2 ) ) ;
if ( ! strptime ( V_144 , L_112 , & V_152 ) ) {
fprintf ( V_28 , L_113 ,
V_144 ) ;
V_137 = V_145 ;
goto V_146;
}
V_149 = TRUE ;
V_152 . V_150 = - 1 ;
V_153 = mktime ( & V_152 ) ;
break;
}
case 'c' :
V_127 = F_67 ( V_144 , L_114 ) ;
break;
case 'C' :
{
int V_154 = 0 , V_155 = 0 ;
switch ( sscanf ( V_144 , L_115 , & V_155 , & V_154 ) ) {
case 1 :
V_154 = V_155 ;
V_155 = 0 ;
break;
case 2 :
break;
default:
fprintf ( V_28 , L_116 ,
V_144 ) ;
V_137 = V_145 ;
goto V_146;
break;
}
if ( V_154 > 0 ) {
V_120 . V_156 += V_154 ;
if ( V_155 > 0 )
V_120 . V_157 += V_155 ;
else
V_120 . V_158 += V_155 ;
} else if ( V_154 < 0 ) {
V_120 . V_159 += V_154 ;
if ( V_155 > 0 )
V_120 . V_160 += V_155 ;
else
V_120 . V_161 += V_155 ;
}
break;
}
case 'd' :
V_162 = TRUE ;
V_163 = FALSE ;
V_71 = V_80 ;
break;
case 'D' :
V_162 = TRUE ;
V_163 = FALSE ;
V_71 = F_10 ( V_144 , L_117 ) ;
if ( V_71 > V_81 ) {
fprintf ( V_28 , L_118 ,
V_71 , V_81 ) ;
V_137 = V_145 ;
goto V_146;
}
break;
case 'E' :
V_164 = F_68 ( V_144 , & V_119 ) ;
if ( V_119 == V_144 || V_164 < 0.0 || V_164 > 1.0 ) {
fprintf ( V_28 , L_119 ,
V_144 ) ;
V_137 = V_145 ;
goto V_146;
}
srand ( ( unsigned int ) ( time ( NULL ) + F_69 () ) ) ;
break;
case 'F' :
V_103 = F_70 ( V_144 ) ;
if ( V_103 < 0 ) {
fprintf ( V_28 , L_120 ,
V_144 ) ;
F_29 () ;
V_137 = V_145 ;
goto V_146;
}
break;
case 'h' :
printf ( L_106
L_121
L_122 ,
F_54 () ) ;
F_24 ( stdout ) ;
goto V_146;
break;
case 'i' :
V_130 = F_67 ( V_144 , L_123 ) ;
break;
case 'I' :
V_67 = F_10 ( V_144 , L_124 ) ;
break;
case 'L' :
V_121 = TRUE ;
break;
case 'o' :
V_133 = F_10 ( V_144 , L_125 ) ;
break;
case 'r' :
V_165 = ! V_165 ;
break;
case 's' :
V_97 = F_67 ( V_144 , L_126 ) ;
break;
case 'S' :
if ( ! F_13 ( V_144 ) ) {
V_137 = V_145 ;
goto V_146;
}
V_166 = TRUE ;
break;
case 't' :
if ( ! F_12 ( V_144 ) ) {
V_137 = V_145 ;
goto V_146;
}
break;
case 'T' :
V_104 = F_71 ( V_144 ) ;
if ( V_104 < 0 ) {
fprintf ( V_28 , L_127 ,
V_144 ) ;
F_37 () ;
V_137 = V_145 ;
goto V_146;
}
break;
case 'v' :
V_36 = ! V_36 ;
break;
case 'V' :
V_107 = F_51 ( NULL , NULL ) ;
V_108 = F_52 ( NULL ) ;
F_72 ( L_128 , V_107 , V_108 ) ;
F_55 ( V_107 , TRUE ) ;
F_55 ( V_108 , TRUE ) ;
goto V_146;
break;
case 'w' :
V_162 = FALSE ;
V_163 = TRUE ;
V_71 = V_81 ;
if ( ! F_14 ( V_144 ) ) {
V_137 = V_145 ;
goto V_146;
}
break;
case '?' :
switch( V_167 ) {
case 'F' :
F_29 () ;
break;
case 'T' :
F_37 () ;
break;
default:
F_24 ( V_28 ) ;
break;
}
V_137 = V_145 ;
goto V_146;
break;
}
}
#ifdef F_73
fprintf ( V_28 , L_129 , V_168 , V_105 ) ;
#endif
if ( ( V_105 - V_168 ) < 1 ) {
F_24 ( V_28 ) ;
V_137 = V_145 ;
goto V_146;
}
if ( V_149 && ! V_153 ) {
struct V_2 V_152 ;
memset ( & V_152 , 0 , sizeof( struct V_2 ) ) ;
V_152 . V_6 = 135 ;
V_152 . V_8 = 31 ;
V_152 . V_7 = 11 ;
V_153 = mktime ( & V_152 ) ;
}
F_74 ( & V_132 ) ;
if ( V_151 > V_153 ) {
fprintf ( V_28 , L_130 ) ;
V_137 = V_145 ;
goto V_146;
}
if ( V_127 != 0 && V_130 != 0 ) {
fprintf ( V_28 , L_131 ) ;
fprintf ( V_28 , L_132 ) ;
V_137 = V_145 ;
goto V_146;
}
V_110 = F_75 ( V_106 [ V_168 ] , V_169 , & V_112 , & V_113 , FALSE ) ;
if ( ! V_110 ) {
F_76 ( L_133 , V_106 [ V_168 ] , V_112 ,
V_113 ) ;
V_137 = V_170 ;
goto V_146;
}
if ( V_36 ) {
fprintf ( V_28 , L_134 , V_106 [ V_168 ] ,
F_33 ( F_77 ( V_110 ) ) ) ;
}
V_98 = F_78 ( V_110 ) ;
V_99 = F_79 ( V_110 ) ;
V_100 = F_80 ( V_110 ) ;
if ( ( V_105 - V_168 ) >= 2 ) {
if ( V_104 == - 2 )
V_104 = F_81 ( V_110 ) ;
for ( V_43 = V_168 + 2 ; V_43 < V_105 ; V_43 ++ )
if ( F_9 ( V_106 [ V_43 ] , & V_134 ) == FALSE )
break;
if ( V_165 == FALSE )
V_134 = V_41 ;
if ( V_162 || V_163 ) {
for ( V_43 = 0 ; V_43 < V_71 ; V_43 ++ ) {
memset ( & V_73 [ V_43 ] . V_74 , 0 , 16 ) ;
V_73 [ V_43 ] . V_59 = 0 ;
F_74 ( & V_73 [ V_43 ] . V_76 ) ;
}
}
while ( F_82 ( V_110 , & V_112 , & V_113 , & V_124 ) ) {
if ( V_134 <= V_126 )
break;
V_126 ++ ;
V_14 = F_83 ( V_110 ) ;
if ( V_126 == 1 ) {
if ( V_127 != 0 || V_130 != 0 ) {
if ( ! F_7 ( V_106 [ V_168 + 1 ] , & V_15 , & V_16 ) ) {
V_137 = V_171 ;
goto V_146;
}
V_96 = F_4 ( V_131 ++ , V_14 , V_15 , V_16 ) ;
} else {
V_96 = F_8 ( V_106 [ V_168 + 1 ] ) ;
}
F_84 ( V_96 ) ;
if ( F_85 ( F_86 ( V_98 , V_172 , 0 ) , V_173 , & V_136 ) != V_174 ) {
F_87 ( F_86 ( V_98 , V_172 , 0 ) , V_173 , L_135 V_175 ) ;
}
V_102 = F_44 ( V_96 ,
V_97 ? F_88 ( V_97 , F_89 ( V_110 ) ) : F_89 ( V_110 ) ,
V_98 , V_99 , V_100 , & V_101 ) ;
if ( V_102 == NULL ) {
F_90 ( L_133 , V_96 ,
V_101 ,
V_103 ) ;
V_137 = V_170 ;
goto V_146;
}
}
V_4 = F_91 ( V_110 ) ;
if ( V_14 -> V_21 & V_22 ) {
if ( F_21 ( & V_132 ) ) {
V_132 = V_14 -> V_23 ;
}
if ( V_130 != 0 ) {
while ( ( ( T_7 ) ( V_14 -> V_23 . V_5 - V_132 . V_5 ) > V_130 )
|| ( ( T_7 ) ( V_14 -> V_23 . V_5 - V_132 . V_5 ) == V_130
&& V_14 -> V_23 . V_55 >= V_132 . V_55 ) ) {
if ( ! F_92 ( V_102 , & V_101 ) ) {
F_93 ( V_96 , V_101 ) ;
V_137 = V_176 ;
goto V_146;
}
V_132 . V_5 = V_132 . V_5 + V_130 ;
F_6 ( V_96 ) ;
V_96 = F_4 ( V_131 ++ , V_14 , V_15 , V_16 ) ;
F_84 ( V_96 ) ;
if ( V_36 )
fprintf ( V_28 , L_136 , V_96 ) ;
V_102 = F_44 ( V_96 ,
V_97 ? F_88 ( V_97 , F_89 ( V_110 ) ) : F_89 ( V_110 ) ,
V_98 , V_99 , V_100 , & V_101 ) ;
if ( V_102 == NULL ) {
F_90 ( L_133 , V_96 ,
V_101 ,
V_103 ) ;
V_137 = V_170 ;
goto V_146;
}
}
}
}
if ( V_127 != 0 ) {
if ( V_128 > 0 && ( V_128 % V_127 ) == 0 ) {
if ( ! F_92 ( V_102 , & V_101 ) ) {
F_93 ( V_96 , V_101 ) ;
V_137 = V_176 ;
goto V_146;
}
F_6 ( V_96 ) ;
V_96 = F_4 ( V_131 ++ , V_14 , V_15 , V_16 ) ;
F_84 ( V_96 ) ;
if ( V_36 )
fprintf ( V_28 , L_136 , V_96 ) ;
V_102 = F_44 ( V_96 ,
V_97 ? F_88 ( V_97 , F_89 ( V_110 ) ) : F_89 ( V_110 ) ,
V_98 , V_99 , V_100 , & V_101 ) ;
if ( V_102 == NULL ) {
F_90 ( L_133 , V_96 ,
V_101 ,
V_103 ) ;
V_137 = V_170 ;
goto V_146;
}
}
}
if ( V_149 ) {
if ( V_14 -> V_21 & V_22 )
V_129 = ( V_14 -> V_23 . V_5 >= V_151 ) && ( V_14 -> V_23 . V_5 < V_153 ) ;
else
V_129 = FALSE ;
} else {
V_129 = TRUE ;
}
if ( V_129 && ( ( ! F_11 ( V_122 ) && ! V_165 )
|| ( F_11 ( V_122 ) && V_165 ) ) ) {
if ( V_36 && ! V_162 && ! V_163 )
fprintf ( V_28 , L_137 , V_122 ) ;
V_14 = F_83 ( V_110 ) ;
if ( V_97 != 0 ) {
if ( V_14 -> V_177 > V_97 ) {
V_135 = * V_14 ;
V_135 . V_177 = V_97 ;
V_14 = & V_135 ;
}
if ( V_121 && V_14 -> V_59 > V_97 ) {
V_135 = * V_14 ;
V_135 . V_59 = V_97 ;
V_14 = & V_135 ;
}
}
V_135 = * V_14 ;
F_94 ( V_120 , & V_135 , V_14 , & V_4 , V_121 ) ;
V_14 = & V_135 ;
if ( V_14 -> V_21 & V_22 ) {
if ( V_166 ) {
if ( V_178 . V_5 || V_178 . V_55 ) {
if ( ! V_56 . V_50 ) {
T_2 V_75 ;
T_2 V_77 ;
V_75 = V_14 -> V_23 ;
F_22 ( & V_77 , & V_75 , & V_178 ) ;
if ( V_77 . V_5 < 0 || V_77 . V_55 < 0 ) {
V_135 = * V_14 ;
V_135 . V_23 . V_5 = V_178 . V_5 + V_56 . V_53 . V_5 ;
V_135 . V_23 . V_55 = V_178 . V_55 ;
if ( V_135 . V_23 . V_55 + V_56 . V_53 . V_55 > V_54 ) {
V_135 . V_23 . V_5 ++ ;
V_135 . V_23 . V_55 += V_56 . V_53 . V_55 - V_54 ;
} else {
V_135 . V_23 . V_55 += V_56 . V_53 . V_55 ;
}
V_14 = & V_135 ;
}
} else {
V_135 = * V_14 ;
V_135 . V_23 . V_5 = V_178 . V_5 + V_56 . V_53 . V_5 ;
V_135 . V_23 . V_55 = V_178 . V_55 ;
if ( V_135 . V_23 . V_55 + V_56 . V_53 . V_55 > V_54 ) {
V_135 . V_23 . V_5 ++ ;
V_135 . V_23 . V_55 += V_56 . V_53 . V_55 - V_54 ;
} else {
V_135 . V_23 . V_55 += V_56 . V_53 . V_55 ;
}
V_14 = & V_135 ;
}
}
V_178 = V_14 -> V_23 ;
}
if ( V_49 . V_53 . V_5 != 0 ) {
V_135 = * V_14 ;
if ( V_49 . V_50 )
V_135 . V_23 . V_5 -= V_49 . V_53 . V_5 ;
else
V_135 . V_23 . V_5 += V_49 . V_53 . V_5 ;
V_14 = & V_135 ;
}
if ( V_49 . V_53 . V_55 != 0 ) {
V_135 = * V_14 ;
if ( V_49 . V_50 ) {
if ( V_135 . V_23 . V_55 < V_49 . V_53 . V_55 ) {
V_135 . V_23 . V_5 -- ;
V_135 . V_23 . V_55 += V_54 ;
}
V_135 . V_23 . V_55 -= V_49 . V_53 . V_55 ;
} else {
if ( V_135 . V_23 . V_55 + V_49 . V_53 . V_55 > V_54 ) {
V_135 . V_23 . V_5 ++ ;
V_135 . V_23 . V_55 += V_49 . V_53 . V_55 - V_54 ;
} else {
V_135 . V_23 . V_55 += V_49 . V_53 . V_55 ;
}
}
V_14 = & V_135 ;
}
}
if ( V_141 ) {
F_17 ( V_14 , V_4 , ( T_7 * ) & V_14 -> V_177 ) ;
}
if ( V_162 ) {
if ( F_18 ( V_4 , V_14 -> V_177 ) ) {
if ( V_36 ) {
fprintf ( V_28 , L_138 ,
V_122 , V_14 -> V_177 ) ;
for ( V_43 = 0 ; V_43 < 16 ; V_43 ++ )
fprintf ( V_28 , L_139 ,
( unsigned char ) V_73 [ V_70 ] . V_74 [ V_43 ] ) ;
fprintf ( V_28 , L_18 ) ;
}
V_123 ++ ;
V_122 ++ ;
continue;
} else {
if ( V_36 ) {
fprintf ( V_28 , L_140 ,
V_122 , V_14 -> V_177 ) ;
for ( V_43 = 0 ; V_43 < 16 ; V_43 ++ )
fprintf ( V_28 , L_139 ,
( unsigned char ) V_73 [ V_70 ] . V_74 [ V_43 ] ) ;
fprintf ( V_28 , L_18 ) ;
}
}
}
if ( V_14 -> V_21 & V_22 ) {
if ( V_163 ) {
T_2 V_75 ;
V_75 . V_5 = V_14 -> V_23 . V_5 ;
V_75 . V_55 = V_14 -> V_23 . V_55 ;
if ( F_20 ( V_4 , V_14 -> V_177 , & V_75 ) ) {
if ( V_36 ) {
fprintf ( V_28 , L_138 ,
V_122 , V_14 -> V_177 ) ;
for ( V_43 = 0 ; V_43 < 16 ; V_43 ++ )
fprintf ( V_28 , L_139 ,
( unsigned char ) V_73 [ V_70 ] . V_74 [ V_43 ] ) ;
fprintf ( V_28 , L_18 ) ;
}
V_123 ++ ;
V_122 ++ ;
continue;
} else {
if ( V_36 ) {
fprintf ( V_28 , L_140 ,
V_122 , V_14 -> V_177 ) ;
for ( V_43 = 0 ; V_43 < 16 ; V_43 ++ )
fprintf ( V_28 , L_139 ,
( unsigned char ) V_73 [ V_70 ] . V_74 [ V_43 ] ) ;
fprintf ( V_28 , L_18 ) ;
}
}
}
}
if ( V_133 > V_14 -> V_177 ) {
fprintf ( V_28 , L_141 ,
V_133 , V_14 -> V_177 , V_122 ) ;
}
if ( V_164 > 0.0 && V_133 <= V_14 -> V_177 ) {
int V_179 = 0 ;
if ( F_77 ( V_110 ) == V_180 )
V_179 = F_95 ( V_4 ) ;
V_179 += V_133 ;
for ( V_43 = V_179 ; V_43 < ( int ) V_14 -> V_177 ; V_43 ++ ) {
if ( rand () <= V_164 * V_181 ) {
V_125 = rand () / ( V_181 / V_182 + 1 ) ;
if ( V_125 < V_183 ) {
V_4 [ V_43 ] ^= 1 << ( rand () / ( V_181 / 8 + 1 ) ) ;
V_125 = V_182 ;
} else {
V_125 -= V_184 ;
}
if ( V_125 < V_184 ) {
V_4 [ V_43 ] = rand () / ( V_181 / 255 + 1 ) ;
V_125 = V_182 ;
} else {
V_125 -= V_184 ;
}
if ( V_125 < V_185 ) {
V_4 [ V_43 ] = V_186 [ rand () / ( V_181 / V_187 + 1 ) ] ;
V_125 = V_182 ;
} else {
V_125 -= V_185 ;
}
if ( V_125 < V_188 ) {
if ( ( unsigned int ) V_43 < V_14 -> V_177 - 2 )
F_96 ( ( char * ) & V_4 [ V_43 ] , L_107 , 2 ) ;
V_125 = V_182 ;
} else {
V_125 -= V_188 ;
}
if ( V_125 < V_189 ) {
for ( V_111 = V_43 ; V_111 < ( int ) V_14 -> V_177 ; V_111 ++ )
V_4 [ V_111 ] = 0xAA ;
V_43 = V_14 -> V_177 ;
}
}
}
}
if ( V_147 ) {
const char * V_190 =
( const char * ) F_97 ( V_147 , F_66 ( V_126 ) ) ;
if ( V_190 != NULL ) {
V_135 = * V_14 ;
V_135 . V_191 = F_8 ( V_190 ) ;
V_135 . V_192 = TRUE ;
V_14 = & V_135 ;
} else {
V_135 = * V_14 ;
V_135 . V_192 = FALSE ;
V_14 = & V_135 ;
}
}
if ( ! F_98 ( V_102 , V_14 , V_4 , & V_101 , & V_114 ) ) {
F_99 ( L_133 , V_106 [ V_168 ] ,
V_96 ,
V_101 , V_114 ,
V_126 ,
V_103 ) ;
V_137 = V_193 ;
goto V_146;
}
V_128 ++ ;
}
V_122 ++ ;
}
F_6 ( V_15 ) ;
F_6 ( V_16 ) ;
if ( V_112 != 0 ) {
F_100 ( L_133 , V_106 [ V_168 ] , V_112 ,
V_113 ) ;
}
if ( ! V_102 ) {
F_6 ( V_96 ) ;
V_96 = F_8 ( V_106 [ V_168 + 1 ] ) ;
V_102 = F_44 ( V_96 ,
V_97 ? F_88 ( V_97 , F_89 ( V_110 ) ) : F_89 ( V_110 ) ,
V_98 , V_99 , V_100 , & V_101 ) ;
if ( V_102 == NULL ) {
F_90 ( L_133 , V_96 ,
V_101 ,
V_103 ) ;
V_137 = V_170 ;
goto V_146;
}
}
if ( ! F_92 ( V_102 , & V_101 ) ) {
F_93 ( V_96 , V_101 ) ;
V_137 = V_176 ;
goto V_146;
}
F_6 ( V_96 ) ;
if ( V_147 ) {
F_101 ( V_147 ) ;
}
}
if ( V_162 ) {
fprintf ( V_28 , L_142 ,
V_122 - 1 , F_102 ( V_122 - 1 , L_143 , L_144 ) , V_123 ,
F_102 ( V_123 , L_143 , L_144 ) , V_71 ) ;
} else if ( V_163 ) {
fprintf ( V_28 , L_145 ,
V_122 - 1 , F_102 ( V_122 - 1 , L_143 , L_144 ) , V_123 ,
F_102 ( V_123 , L_143 , L_144 ) ,
( long ) V_57 . V_5 ,
( long int ) V_57 . V_55 ) ;
}
V_146:
F_103 ( V_98 ) ;
F_103 ( V_100 ) ;
F_6 ( V_99 ) ;
if ( V_110 != NULL )
F_104 ( V_110 ) ;
F_105 () ;
F_106 () ;
#ifdef F_59
F_107 () ;
#endif
return V_137 ;
}
static int
F_95 ( T_6 * V_4 )
{
int V_194 = 0 ;
for ( V_194 = 0 ; V_4 [ V_194 ] != '\0' ; V_194 ++ ) ;
V_194 ++ ;
V_194 ++ ;
for (; V_4 [ V_194 ] != '\0' ; V_194 ++ ) ;
V_194 ++ ;
for (; V_4 [ V_194 ] != '\0' ; V_194 ++ ) ;
V_194 ++ ;
for (; V_4 [ V_194 ] != '\0' ; V_194 ++ ) ;
V_194 ++ ;
for (; V_4 [ V_194 ] != '\0' ; V_194 ++ ) ;
V_194 ++ ;
V_194 += 2 ;
return V_194 ;
}
static void
F_94 ( T_21 V_120 , struct V_13 * V_195 ,
const struct V_13 * V_196 , T_6 * * V_4 ,
T_4 V_121 )
{
if ( V_196 -> V_197 != V_198 )
return;
if ( V_120 . V_156 == 0 )
V_120 . V_157 = V_120 . V_158 = 0 ;
if ( V_120 . V_159 == 0 )
V_120 . V_160 = V_120 . V_161 = 0 ;
if ( V_120 . V_158 < 0 ) {
V_120 . V_157 += V_196 -> V_177 + V_120 . V_158 ;
V_120 . V_158 = 0 ;
}
if ( V_120 . V_160 > 0 ) {
V_120 . V_161 += V_120 . V_160 - V_196 -> V_177 ;
V_120 . V_160 = 0 ;
}
if ( V_120 . V_156 && V_120 . V_159 ) {
if ( V_120 . V_157 > ( ( int ) V_196 -> V_177 + V_120 . V_161 ) ) {
int V_199 , V_200 ;
V_200 = V_196 -> V_177 + V_120 . V_161 + V_120 . V_159 ;
V_199 = - V_120 . V_159 ;
V_120 . V_161 = V_120 . V_156 + V_120 . V_157 - V_196 -> V_177 ;
V_120 . V_159 = - V_120 . V_156 ;
V_120 . V_156 = V_199 ;
V_120 . V_157 = V_200 ;
}
}
if ( V_196 -> V_177 < ( T_7 ) ( V_120 . V_157 - V_120 . V_161 ) ) {
V_120 . V_156 = 0 ;
V_120 . V_159 = 0 ;
}
if ( ( T_7 ) ( V_120 . V_156 - V_120 . V_159 ) >
( V_196 -> V_177 - ( T_7 ) ( V_120 . V_157 - V_120 . V_161 ) ) ) {
V_120 . V_156 = V_196 -> V_177 - ( V_120 . V_157 - V_120 . V_161 ) ;
V_120 . V_159 = 0 ;
}
if ( V_120 . V_156 > 0 ) {
* V_195 = * V_196 ;
if ( V_120 . V_157 > 0 ) {
memmove ( * V_4 + V_120 . V_157 ,
* V_4 + V_120 . V_157 + V_120 . V_156 ,
V_195 -> V_177 - V_120 . V_156 ) ;
} else {
* V_4 += V_120 . V_156 ;
}
V_195 -> V_177 -= V_120 . V_156 ;
if ( V_121 ) {
if ( V_196 -> V_59 > ( T_7 ) V_120 . V_156 )
V_195 -> V_59 -= V_120 . V_156 ;
else
V_195 -> V_59 = 0 ;
}
V_196 = V_195 ;
}
if ( V_120 . V_159 < 0 ) {
* V_195 = * V_196 ;
if ( V_120 . V_161 < 0 ) {
memmove ( * V_4 + ( T_9 ) V_195 -> V_177 + ( V_120 . V_159 + V_120 . V_161 ) ,
* V_4 + ( T_9 ) V_195 -> V_177 + V_120 . V_161 ,
- V_120 . V_161 ) ;
}
V_195 -> V_177 += V_120 . V_159 ;
if ( V_121 ) {
if ( ( ( signed int ) V_196 -> V_59 + V_120 . V_159 ) > 0 )
V_195 -> V_59 += V_120 . V_159 ;
else
V_195 -> V_59 = 0 ;
}
}
}
