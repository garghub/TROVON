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
V_37 [ V_34 ] . V_39 = ( T_3 ) strtoul ( V_30 , NULL , 10 ) ;
if ( V_37 [ V_34 ] . V_39 < * V_31 )
* V_31 = V_37 [ V_34 ] . V_39 ;
if ( V_36 )
fprintf ( V_28 , L_8 , V_37 [ V_34 ] . V_39 ) ;
} else {
if ( V_36 )
fprintf ( V_28 , L_9 ) ;
V_33 = V_32 + 1 ;
V_37 [ V_34 ] . V_38 = TRUE ;
V_37 [ V_34 ] . V_39 = ( T_3 ) strtoul ( V_30 , NULL , 10 ) ;
V_37 [ V_34 ] . V_40 = ( T_3 ) strtoul ( V_33 , NULL , 10 ) ;
if ( V_37 [ V_34 ] . V_40 == 0 )
{
V_37 [ V_34 ] . V_40 = * V_31 = V_41 ;
}
else if ( V_37 [ V_34 ] . V_40 < * V_31 )
* V_31 = V_37 [ V_34 ] . V_40 ;
if ( V_36 )
fprintf ( V_28 , L_10 , V_37 [ V_34 ] . V_39 ,
V_37 [ V_34 ] . V_40 ) ;
}
V_34 ++ ;
return ( TRUE ) ;
}
static int
F_10 ( T_3 V_42 )
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
static void
F_11 ( char * V_44 )
{
char * V_45 , * V_46 ;
long V_47 ;
T_5 V_48 ;
if ( ! V_44 )
return;
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
fprintf ( V_28 , L_11 ,
V_44 ) ;
exit ( 1 ) ;
}
if ( V_47 < 0 ) {
fprintf ( V_28 , L_11 ,
V_44 ) ;
exit ( 1 ) ;
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
fprintf ( V_28 , L_11 ,
V_44 ) ;
exit ( 1 ) ;
}
} else {
return;
}
V_48 = V_46 - V_45 - 1 ;
while( V_48 < 9 ) {
V_47 *= 10 ;
V_48 ++ ;
}
V_49 . V_53 . V_55 = ( int ) V_47 ;
}
static void
F_12 ( char * V_44 )
{
char * V_45 , * V_46 ;
long V_47 ;
T_5 V_48 ;
if ( ! V_44 )
return;
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
fprintf ( V_28 , L_11 ,
V_44 ) ;
exit ( 1 ) ;
}
if ( V_47 < 0 ) {
fprintf ( V_28 , L_11 ,
V_44 ) ;
exit ( 1 ) ;
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
fprintf ( V_28 , L_11 ,
V_44 ) ;
exit ( 1 ) ;
}
} else {
return;
}
V_48 = V_46 - V_45 - 1 ;
while( V_48 < 9 ) {
V_47 *= 10 ;
V_48 ++ ;
}
V_56 . V_53 . V_55 = ( int ) V_47 ;
}
static void
F_13 ( char * V_44 )
{
char * V_45 , * V_46 ;
long V_47 ;
T_5 V_48 ;
if ( ! V_44 )
return;
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
fprintf ( V_28 , L_12 ,
V_44 ) ;
exit ( 1 ) ;
}
if ( V_47 < 0 ) {
fprintf ( V_28 , L_13 ,
V_44 ) ;
exit ( 1 ) ;
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
fprintf ( V_28 , L_14 ,
V_44 ) ;
exit ( 1 ) ;
}
} else {
return;
}
V_48 = V_46 - V_45 - 1 ;
while( V_48 < 9 ) {
V_47 *= 10 ;
V_48 ++ ;
}
V_57 . V_55 = ( int ) V_47 ;
}
static void
F_14 ( T_6 * V_58 , T_7 * V_59 ) {
if ( F_15 ( V_58 + V_60 ) == V_61 ) {
int V_62 ;
V_58 = V_58 + V_60 ;
V_62 = * V_59 - ( V_60 + V_63 ) ;
memmove ( V_58 , V_58 + V_63 , V_62 ) ;
* V_59 -= 4 ;
}
}
static void
F_16 ( const struct V_13 * V_14 , T_6 * V_58 , T_7 * V_59 ) {
switch ( V_14 -> V_64 ) {
case V_65 :
F_14 ( V_58 , V_59 ) ;
break;
default:
break;
}
}
static T_4
F_17 ( T_6 * V_58 , T_7 V_59 ) {
int V_43 ;
T_8 V_66 ;
T_7 V_67 ;
T_6 * V_68 ;
V_68 = & V_58 [ V_69 ] ;
V_67 = V_59 - ( V_69 ) ;
V_70 ++ ;
if ( V_70 >= V_71 )
V_70 = 0 ;
F_18 ( & V_66 ) ;
F_19 ( & V_66 , V_68 , V_67 ) ;
F_20 ( & V_66 , V_72 [ V_70 ] . V_73 ) ;
V_72 [ V_70 ] . V_59 = V_59 ;
for ( V_43 = 0 ; V_43 < V_71 ; V_43 ++ ) {
if ( V_43 == V_70 )
continue;
if ( V_72 [ V_43 ] . V_59 == V_72 [ V_70 ] . V_59
&& memcmp ( V_72 [ V_43 ] . V_73 , V_72 [ V_70 ] . V_73 , 16 ) == 0 ) {
return TRUE ;
}
}
return FALSE ;
}
static T_4
F_21 ( T_6 * V_58 , T_7 V_59 , const T_2 * V_74 ) {
int V_43 ;
T_8 V_66 ;
T_7 V_67 ;
T_6 * V_68 ;
V_68 = & V_58 [ V_69 ] ;
V_67 = V_59 - ( V_69 ) ;
V_70 ++ ;
if ( V_70 >= V_71 )
V_70 = 0 ;
F_18 ( & V_66 ) ;
F_19 ( & V_66 , V_68 , V_67 ) ;
F_20 ( & V_66 , V_72 [ V_70 ] . V_73 ) ;
V_72 [ V_70 ] . V_59 = V_59 ;
V_72 [ V_70 ] . V_75 . V_5 = V_74 -> V_5 ;
V_72 [ V_70 ] . V_75 . V_55 = V_74 -> V_55 ;
for ( V_43 = V_70 - 1 ; ; V_43 -- ) {
T_2 V_76 ;
int V_77 ;
if ( V_43 < 0 )
V_43 = V_71 - 1 ;
if ( V_43 == V_70 ) {
break;
}
if ( F_22 ( & ( V_72 [ V_43 ] . V_75 ) ) ) {
break;
}
F_23 ( & V_76 , V_74 , & V_72 [ V_43 ] . V_75 ) ;
if ( V_76 . V_5 < 0 || V_76 . V_55 < 0 ) {
continue;
}
V_77 = F_24 ( & V_76 , & V_57 ) ;
if ( V_77 > 0 ) {
break;
} else if ( V_72 [ V_43 ] . V_59 == V_72 [ V_70 ] . V_59
&& memcmp ( V_72 [ V_43 ] . V_73 , V_72 [ V_70 ] . V_73 , 16 ) == 0 ) {
return TRUE ;
}
}
return FALSE ;
}
static void
F_25 ( T_9 * V_78 )
{
fprintf ( V_78 , L_15 ) ;
fprintf ( V_78 , L_16 ) ;
fprintf ( V_78 , L_15 ) ;
fprintf ( V_78 , L_17 ) ;
fprintf ( V_78 , L_18 ) ;
fprintf ( V_78 , L_15 ) ;
fprintf ( V_78 , L_19 ) ;
fprintf ( V_78 , L_20 ) ;
fprintf ( V_78 , L_21 ) ;
fprintf ( V_78 , L_22 ) ;
fprintf ( V_78 , L_23 ) ;
fprintf ( V_78 , L_24 ) ;
fprintf ( V_78 , L_15 ) ;
fprintf ( V_78 , L_25 ) ;
fprintf ( V_78 , L_26 ) ;
fprintf ( V_78 , L_27 , V_79 ) ;
fprintf ( V_78 , L_28 ) ;
fprintf ( V_78 , L_29 , V_80 ) ;
fprintf ( V_78 , L_30 ) ;
fprintf ( V_78 , L_31 ) ;
fprintf ( V_78 , L_32 ) ;
fprintf ( V_78 , L_33 ) ;
fprintf ( V_78 , L_34 ) ;
fprintf ( V_78 , L_35 ) ;
fprintf ( V_78 , L_36 ) ;
fprintf ( V_78 , L_15 ) ;
fprintf ( V_78 , L_37 ) ;
fprintf ( V_78 , L_38 ) ;
fprintf ( V_78 , L_39 ) ;
fprintf ( V_78 , L_40 ) ;
fprintf ( V_78 , L_41 ) ;
fprintf ( V_78 , L_42 ) ;
fprintf ( V_78 , L_43 ) ;
fprintf ( V_78 , L_15 ) ;
fprintf ( V_78 , L_44 ) ;
fprintf ( V_78 , L_45 ) ;
fprintf ( V_78 , L_46 ) ;
fprintf ( V_78 , L_47 ) ;
fprintf ( V_78 , L_15 ) ;
fprintf ( V_78 , L_48 ) ;
fprintf ( V_78 , L_49 ) ;
fprintf ( V_78 , L_50 ) ;
fprintf ( V_78 , L_51 ) ;
fprintf ( V_78 , L_52 ) ;
fprintf ( V_78 , L_53 ) ;
fprintf ( V_78 , L_54 ) ;
fprintf ( V_78 , L_55 ) ;
fprintf ( V_78 , L_56 ) ;
fprintf ( V_78 , L_57 ) ;
fprintf ( V_78 , L_58 ) ;
fprintf ( V_78 , L_59 ) ;
fprintf ( V_78 , L_60 ) ;
fprintf ( V_78 , L_61 ) ;
fprintf ( V_78 , L_62 ) ;
fprintf ( V_78 , L_63 ) ;
fprintf ( V_78 , L_64 ) ;
fprintf ( V_78 , L_65 ) ;
fprintf ( V_78 , L_66 ) ;
fprintf ( V_78 , L_67 ) ;
fprintf ( V_78 , L_68 ) ;
fprintf ( V_78 , L_69 ) ;
fprintf ( V_78 , L_70 ) ;
fprintf ( V_78 , L_71 ) ;
fprintf ( V_78 , L_72 ) ;
fprintf ( V_78 , L_73 ) ;
fprintf ( V_78 , L_74 ) ;
fprintf ( V_78 , L_75 ) ;
fprintf ( V_78 , L_15 ) ;
fprintf ( V_78 , L_76 ) ;
fprintf ( V_78 , L_77 ) ;
fprintf ( V_78 , L_78 ) ;
fprintf ( V_78 , L_79 ) ;
fprintf ( V_78 , L_80 ) ;
fprintf ( V_78 , L_81 ) ;
fprintf ( V_78 , L_82 ) ;
fprintf ( V_78 , L_83 ) ;
fprintf ( V_78 , L_84 ) ;
fprintf ( V_78 , L_85 ) ;
fprintf ( V_78 , L_86 ) ;
fprintf ( V_78 , L_87 ) ;
fprintf ( V_78 , L_15 ) ;
fprintf ( V_78 , L_88 ) ;
fprintf ( V_78 , L_89 ) ;
fprintf ( V_78 , L_90 ) ;
fprintf ( V_78 , L_91 ) ;
fprintf ( V_78 , L_92 ) ;
fprintf ( V_78 , L_93 ) ;
fprintf ( V_78 , L_15 ) ;
}
static T_10
F_26 ( T_11 V_81 , T_11 V_82 )
{
return strcmp ( ( ( const struct V_83 * ) V_81 ) -> V_84 ,
( ( const struct V_83 * ) V_82 ) -> V_84 ) ;
}
static T_10
F_27 ( T_11 V_81 , T_11 V_82 )
{
return F_28 ( ( ( const struct V_83 * ) V_81 ) -> V_84 ,
( ( const struct V_83 * ) V_82 ) -> V_84 ) ;
}
static void
F_29 ( T_12 V_85 , T_12 T_13 V_86 )
{
fprintf ( V_28 , L_94 ,
( (struct V_83 * ) V_85 ) -> V_84 ,
( (struct V_83 * ) V_85 ) -> V_87 ) ;
}
static void
F_30 ( void ) {
int V_43 ;
struct V_83 * V_88 ;
T_14 * V_89 = NULL ;
V_88 = F_31 ( struct V_83 , V_90 ) ;
fprintf ( V_28 , L_95 ) ;
for ( V_43 = 0 ; V_43 < V_90 ; V_43 ++ ) {
if ( F_32 ( V_43 ) ) {
V_88 [ V_43 ] . V_84 = F_33 ( V_43 ) ;
V_88 [ V_43 ] . V_87 = F_34 ( V_43 ) ;
V_89 = F_35 ( V_89 , & V_88 [ V_43 ] , F_26 ) ;
}
}
F_36 ( V_89 , F_29 , NULL ) ;
F_37 ( V_89 ) ;
F_6 ( V_88 ) ;
}
static void
F_38 ( void ) {
int V_43 ;
struct V_83 * V_91 ;
T_14 * V_89 = NULL ;
V_91 = (struct V_83 * ) F_2 ( sizeof( struct V_83 ) * V_92 ) ;
fprintf ( V_28 , L_96 ) ;
for ( V_43 = 0 ; V_43 < V_92 ; V_43 ++ ) {
V_91 [ V_43 ] . V_84 = F_39 ( V_43 ) ;
if ( V_91 [ V_43 ] . V_84 != NULL ) {
V_91 [ V_43 ] . V_87 = F_40 ( V_43 ) ;
V_89 = F_35 ( V_89 , & V_91 [ V_43 ] , F_27 ) ;
}
}
F_36 ( V_89 , F_29 , NULL ) ;
F_37 ( V_89 ) ;
F_6 ( V_91 ) ;
}
static int
F_41 ( T_11 V_81 , T_11 V_82 , T_12 T_15 V_86 )
{
if ( F_42 ( V_81 ) < F_42 ( V_82 ) )
return - 1 ;
if ( F_42 ( V_81 ) > F_42 ( V_82 ) )
return 1 ;
return 0 ;
}
static void
F_43 ( const char * T_16 V_86 , T_17 T_18 V_86 )
{
}
static T_19 *
F_44 ( const char * V_93 , T_7 V_94 ,
T_20 * V_95 ,
T_21 * V_96 ,
T_20 * V_97 , int * V_98 )
{
T_19 * V_99 ;
if ( strcmp ( V_93 , L_97 ) == 0 ) {
V_99 = F_45 ( V_100 , V_101 ,
V_94 , FALSE ,
V_95 , V_96 , V_97 , V_98 ) ;
} else {
V_99 = F_46 ( V_93 , V_100 , V_101 ,
V_94 , FALSE ,
V_95 , V_96 , V_97 , V_98 ) ;
}
return V_99 ;
}
int
main ( int V_102 , char * V_103 [] )
{
T_22 * V_104 ;
T_22 * V_105 ;
T_23 * V_106 ;
int V_43 , V_107 , V_108 , V_98 ;
T_1 * V_109 , * V_110 ;
int V_111 ;
static const struct V_112 V_113 [] = {
{ L_98 , V_114 , NULL , 0x8100 } ,
{ L_99 , V_114 , NULL , 'h' } ,
{ L_100 , V_114 , NULL , 'V' } ,
{ 0 , 0 , 0 , 0 }
} ;
char * V_115 ;
T_7 V_94 = 0 ;
T_24 V_116 = { 0 , 0 , 0 , 0 , 0 , 0 } ;
T_4 V_117 = FALSE ;
T_19 * V_99 = NULL ;
unsigned int V_118 = 1 ;
unsigned int V_119 = 0 ;
T_25 V_120 ;
int V_121 ;
T_6 * V_4 ;
T_7 V_122 = 0 ;
int V_123 = 0 ;
int V_124 = 0 ;
char * V_93 = NULL ;
T_4 V_125 ;
int V_126 = 0 ;
int V_127 = 0 ;
T_2 V_128 ;
T_1 * V_15 = NULL ;
T_1 * V_16 = NULL ;
T_7 V_129 = 0 ;
T_3 V_130 = V_41 ;
const struct V_13 * V_14 ;
struct V_13 V_131 ;
T_21 * V_96 = NULL ;
T_20 * V_95 = NULL ;
T_20 * V_97 = NULL ;
char * V_132 ;
#ifdef F_47
char * V_133 ;
#endif
#ifdef F_48
F_49 ( V_102 , V_103 ) ;
F_50 () ;
#endif
V_104 = F_51 ( NULL , NULL ) ;
V_105 = F_52 ( NULL ) ;
F_53 ( L_101
L_15
L_102
L_15
L_102 ,
F_54 () , V_104 -> V_134 , V_105 -> V_134 ) ;
F_55 () ;
F_56 () ;
#ifdef F_47
if ( ( V_133 = F_57 ( V_103 [ 0 ] , main ) ) ) {
F_58 ( L_103 , V_133 ) ;
F_6 ( V_133 ) ;
} else {
F_59 () ;
F_60 ( F_43 , NULL , NULL , NULL ) ;
F_61 () ;
F_62 () ;
}
#endif
while ( ( V_111 = F_63 ( V_102 , V_103 , L_104 , V_113 , NULL ) ) != - 1 ) {
switch ( V_111 ) {
case 0x8100 :
{
V_135 = TRUE ;
break;
}
case 'a' :
{
T_3 V_136 ;
T_10 V_137 = 0 ;
if ( ( sscanf ( V_138 , L_105 , & V_136 , & V_137 ) < 1 ) || ( V_137 == 0 ) ) {
fprintf ( V_28 , L_106 ,
V_138 ) ;
exit ( 1 ) ;
}
if ( ! V_139 ) {
V_139 = F_64 ( F_41 , NULL , NULL , F_6 ) ;
}
F_65 ( V_139 , F_66 ( V_136 ) , F_8 ( V_138 + V_137 ) ) ;
break;
}
case 'A' :
{
struct V_2 V_140 ;
memset ( & V_140 , 0 , sizeof( struct V_2 ) ) ;
if ( ! strptime ( V_138 , L_107 , & V_140 ) ) {
fprintf ( V_28 , L_108 ,
V_138 ) ;
exit ( 1 ) ;
}
V_141 = TRUE ;
V_140 . V_142 = - 1 ;
V_143 = mktime ( & V_140 ) ;
break;
}
case 'B' :
{
struct V_2 V_144 ;
memset ( & V_144 , 0 , sizeof( struct V_2 ) ) ;
if ( ! strptime ( V_138 , L_107 , & V_144 ) ) {
fprintf ( V_28 , L_108 ,
V_138 ) ;
exit ( 1 ) ;
}
V_141 = TRUE ;
V_144 . V_142 = - 1 ;
V_145 = mktime ( & V_144 ) ;
break;
}
case 'c' :
V_123 = ( int ) strtol ( V_138 , & V_115 , 10 ) ;
if ( V_115 == V_138 || * V_115 != '\0' ) {
fprintf ( V_28 , L_109 ,
V_138 ) ;
exit ( 1 ) ;
}
if ( V_123 <= 0 ) {
fprintf ( V_28 , L_110 ,
V_123 ) ;
exit ( 1 ) ;
}
break;
case 'C' :
{
int V_146 = 0 , V_147 = 0 ;
switch ( sscanf ( V_138 , L_111 , & V_147 , & V_146 ) ) {
case 1 :
V_146 = V_147 ;
V_147 = 0 ;
break;
case 2 :
break;
default:
fprintf ( V_28 , L_112 ,
V_138 ) ;
exit ( 1 ) ;
break;
}
if ( V_146 > 0 ) {
V_116 . V_148 += V_146 ;
if ( V_147 > 0 )
V_116 . V_149 += V_147 ;
else
V_116 . V_150 += V_147 ;
} else if ( V_146 < 0 ) {
V_116 . V_151 += V_146 ;
if ( V_147 > 0 )
V_116 . V_152 += V_147 ;
else
V_116 . V_153 += V_147 ;
}
break;
}
case 'd' :
V_154 = TRUE ;
V_155 = FALSE ;
V_71 = V_79 ;
break;
case 'D' :
V_154 = TRUE ;
V_155 = FALSE ;
V_71 = ( int ) strtol ( V_138 , & V_115 , 10 ) ;
if ( V_115 == V_138 || * V_115 != '\0' ) {
fprintf ( V_28 , L_113 ,
V_138 ) ;
exit ( 1 ) ;
}
if ( V_71 < 0 || V_71 > V_80 ) {
fprintf ( V_28 , L_114 ,
V_71 , V_80 ) ;
exit ( 1 ) ;
}
break;
case 'E' :
V_156 = F_67 ( V_138 , & V_115 ) ;
if ( V_115 == V_138 || V_156 < 0.0 || V_156 > 1.0 ) {
fprintf ( V_28 , L_115 ,
V_138 ) ;
exit ( 1 ) ;
}
srand ( ( unsigned int ) ( time ( NULL ) + F_68 () ) ) ;
break;
case 'F' :
V_100 = F_69 ( V_138 ) ;
if ( V_100 < 0 ) {
fprintf ( V_28 , L_116 ,
V_138 ) ;
F_30 () ;
exit ( 1 ) ;
}
break;
case 'h' :
printf ( L_101
L_117
L_118 ,
F_54 () ) ;
F_25 ( stdout ) ;
exit ( 0 ) ;
break;
case 'i' :
V_126 = atoi ( V_138 ) ;
if ( V_126 <= 0 ) {
fprintf ( V_28 , L_119 ,
V_138 ) ;
exit ( 1 ) ;
}
break;
case 'I' :
V_69 = atoi ( V_138 ) ;
if( V_69 <= 0 ) {
fprintf ( V_28 , L_120 , V_138 ) ;
exit ( 1 ) ;
}
break;
case 'L' :
V_117 = TRUE ;
break;
case 'o' :
V_129 = ( T_7 ) strtol ( V_138 , & V_115 , 10 ) ;
break;
case 'r' :
V_157 = ! V_157 ;
break;
case 's' :
V_94 = ( T_7 ) strtol ( V_138 , & V_115 , 10 ) ;
if ( V_115 == V_138 || * V_115 != '\0' ) {
fprintf ( V_28 , L_121 ,
V_138 ) ;
exit ( 1 ) ;
}
break;
case 'S' :
F_12 ( V_138 ) ;
V_158 = TRUE ;
break;
case 't' :
F_11 ( V_138 ) ;
break;
case 'T' :
V_101 = F_70 ( V_138 ) ;
if ( V_101 < 0 ) {
fprintf ( V_28 , L_122 ,
V_138 ) ;
F_38 () ;
exit ( 1 ) ;
}
break;
case 'v' :
V_36 = ! V_36 ;
break;
case 'V' :
F_71 ( L_123 , V_104 , V_105 ) ;
F_72 ( V_104 , TRUE ) ;
F_72 ( V_105 , TRUE ) ;
exit ( 0 ) ;
break;
case 'w' :
V_154 = FALSE ;
V_155 = TRUE ;
V_71 = V_80 ;
F_13 ( V_138 ) ;
break;
case '?' :
switch( V_159 ) {
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
#ifdef F_73
fprintf ( V_28 , L_124 , V_160 , V_102 ) ;
#endif
if ( ( V_102 - V_160 ) < 1 ) {
F_25 ( V_28 ) ;
exit ( 1 ) ;
}
if ( V_141 && ! V_145 ) {
struct V_2 V_144 ;
memset ( & V_144 , 0 , sizeof( struct V_2 ) ) ;
V_144 . V_6 = 135 ;
V_144 . V_8 = 31 ;
V_144 . V_7 = 11 ;
V_145 = mktime ( & V_144 ) ;
}
F_74 ( & V_128 ) ;
if ( V_143 > V_145 ) {
fprintf ( V_28 , L_125 ) ;
exit ( 1 ) ;
}
if ( V_123 > 0 && V_126 > 0 ) {
fprintf ( V_28 , L_126 ) ;
fprintf ( V_28 , L_127 ) ;
exit ( 1 ) ;
}
V_106 = F_75 ( V_103 [ V_160 ] , V_161 , & V_108 , & V_109 , FALSE ) ;
if ( ! V_106 ) {
fprintf ( V_28 , L_128 , V_103 [ V_160 ] ,
F_76 ( V_108 ) ) ;
if ( V_109 != NULL ) {
fprintf ( V_28 , L_129 , V_109 ) ;
F_6 ( V_109 ) ;
}
exit ( 2 ) ;
}
if ( V_36 ) {
fprintf ( V_28 , L_130 , V_103 [ V_160 ] ,
F_34 ( F_77 ( V_106 ) ) ) ;
}
V_95 = F_78 ( V_106 ) ;
V_96 = F_79 ( V_106 ) ;
V_97 = F_80 ( V_106 ) ;
if ( ( V_102 - V_160 ) >= 2 ) {
if ( V_101 == - 2 )
V_101 = F_81 ( V_106 ) ;
for ( V_43 = V_160 + 2 ; V_43 < V_102 ; V_43 ++ )
if ( F_9 ( V_103 [ V_43 ] , & V_130 ) == FALSE )
break;
if ( V_157 == FALSE )
V_130 = V_41 ;
if ( V_154 || V_155 ) {
for ( V_43 = 0 ; V_43 < V_71 ; V_43 ++ ) {
memset ( & V_72 [ V_43 ] . V_73 , 0 , 16 ) ;
V_72 [ V_43 ] . V_59 = 0 ;
F_74 ( & V_72 [ V_43 ] . V_75 ) ;
}
}
while ( F_82 ( V_106 , & V_108 , & V_109 , & V_120 ) ) {
if ( V_130 <= V_122 )
break;
V_122 ++ ;
V_14 = F_83 ( V_106 ) ;
if ( V_122 == 1 ) {
if ( V_123 > 0 || V_126 > 0 ) {
if ( ! F_7 ( V_103 [ V_160 + 1 ] , & V_15 , & V_16 ) )
goto V_162;
V_93 = F_4 ( V_127 ++ , V_14 , V_15 , V_16 ) ;
} else {
V_93 = F_8 ( V_103 [ V_160 + 1 ] ) ;
}
F_84 ( V_93 ) ;
F_85 ( F_86 ( V_95 , V_163 , 0 ) , V_164 , & V_132 ) ;
if ( V_132 == NULL ) {
F_87 ( F_86 ( V_95 , V_163 , 0 ) , V_164 , L_131 V_165 ) ;
}
V_99 = F_44 ( V_93 ,
V_94 ? F_88 ( V_94 , F_89 ( V_106 ) ) : F_89 ( V_106 ) ,
V_95 , V_96 , V_97 , & V_98 ) ;
if ( V_99 == NULL ) {
fprintf ( V_28 , L_132 ,
V_93 , F_76 ( V_98 ) ) ;
goto V_162;
}
}
V_4 = F_90 ( V_106 ) ;
if ( V_14 -> V_21 & V_22 ) {
if ( F_22 ( & V_128 ) ) {
V_128 = V_14 -> V_23 ;
}
if ( V_126 > 0 ) {
while ( ( V_14 -> V_23 . V_5 - V_128 . V_5 > V_126 )
|| ( V_14 -> V_23 . V_5 - V_128 . V_5 == V_126
&& V_14 -> V_23 . V_55 >= V_128 . V_55 ) ) {
if ( ! F_91 ( V_99 , & V_98 ) ) {
fprintf ( V_28 , L_133 ,
V_93 , F_76 ( V_98 ) ) ;
goto V_162;
}
V_128 . V_5 = V_128 . V_5 + V_126 ;
F_6 ( V_93 ) ;
V_93 = F_4 ( V_127 ++ , V_14 , V_15 , V_16 ) ;
F_84 ( V_93 ) ;
if ( V_36 )
fprintf ( V_28 , L_134 , V_93 ) ;
V_99 = F_44 ( V_93 ,
V_94 ? F_88 ( V_94 , F_89 ( V_106 ) ) : F_89 ( V_106 ) ,
V_95 , V_96 , V_97 , & V_98 ) ;
if ( V_99 == NULL ) {
fprintf ( V_28 , L_132 ,
V_93 , F_76 ( V_98 ) ) ;
goto V_162;
}
}
}
}
if ( V_123 > 0 ) {
if ( V_124 > 0 && V_124 % V_123 == 0 ) {
if ( ! F_91 ( V_99 , & V_98 ) ) {
fprintf ( V_28 , L_133 ,
V_93 , F_76 ( V_98 ) ) ;
goto V_162;
}
F_6 ( V_93 ) ;
V_93 = F_4 ( V_127 ++ , V_14 , V_15 , V_16 ) ;
F_84 ( V_93 ) ;
if ( V_36 )
fprintf ( V_28 , L_134 , V_93 ) ;
V_99 = F_44 ( V_93 ,
V_94 ? F_88 ( V_94 , F_89 ( V_106 ) ) : F_89 ( V_106 ) ,
V_95 , V_96 , V_97 , & V_98 ) ;
if ( V_99 == NULL ) {
fprintf ( V_28 , L_132 ,
V_93 , F_76 ( V_98 ) ) ;
goto V_162;
}
}
}
if ( V_141 ) {
if ( V_14 -> V_21 & V_22 )
V_125 = ( V_14 -> V_23 . V_5 >= V_143 ) && ( V_14 -> V_23 . V_5 < V_145 ) ;
else
V_125 = FALSE ;
} else {
V_125 = TRUE ;
}
if ( V_125 && ( ( ! F_10 ( V_118 ) && ! V_157 )
|| ( F_10 ( V_118 ) && V_157 ) ) ) {
if ( V_36 && ! V_154 && ! V_155 )
fprintf ( V_28 , L_135 , V_118 ) ;
V_14 = F_83 ( V_106 ) ;
if ( V_94 != 0 ) {
if ( V_14 -> V_166 > V_94 ) {
V_131 = * V_14 ;
V_131 . V_166 = V_94 ;
V_14 = & V_131 ;
}
if ( V_117 && V_14 -> V_59 > V_94 ) {
V_131 = * V_14 ;
V_131 . V_59 = V_94 ;
V_14 = & V_131 ;
}
}
V_131 = * V_14 ;
F_92 ( V_116 , & V_131 , V_14 , & V_4 , V_117 ) ;
V_14 = & V_131 ;
if ( V_14 -> V_21 & V_22 ) {
if ( V_158 ) {
if ( V_167 . V_5 || V_167 . V_55 ) {
if ( ! V_56 . V_50 ) {
T_2 V_74 ;
T_2 V_76 ;
V_74 = V_14 -> V_23 ;
F_23 ( & V_76 , & V_74 , & V_167 ) ;
if ( V_76 . V_5 < 0 || V_76 . V_55 < 0 ) {
V_131 = * V_14 ;
V_131 . V_23 . V_5 = V_167 . V_5 + V_56 . V_53 . V_5 ;
V_131 . V_23 . V_55 = V_167 . V_55 ;
if ( V_131 . V_23 . V_55 + V_56 . V_53 . V_55 > V_54 ) {
V_131 . V_23 . V_5 ++ ;
V_131 . V_23 . V_55 += V_56 . V_53 . V_55 - V_54 ;
} else {
V_131 . V_23 . V_55 += V_56 . V_53 . V_55 ;
}
V_14 = & V_131 ;
}
} else {
V_131 = * V_14 ;
V_131 . V_23 . V_5 = V_167 . V_5 + V_56 . V_53 . V_5 ;
V_131 . V_23 . V_55 = V_167 . V_55 ;
if ( V_131 . V_23 . V_55 + V_56 . V_53 . V_55 > V_54 ) {
V_131 . V_23 . V_5 ++ ;
V_131 . V_23 . V_55 += V_56 . V_53 . V_55 - V_54 ;
} else {
V_131 . V_23 . V_55 += V_56 . V_53 . V_55 ;
}
V_14 = & V_131 ;
}
}
V_167 = V_14 -> V_23 ;
}
if ( V_49 . V_53 . V_5 != 0 ) {
V_131 = * V_14 ;
if ( V_49 . V_50 )
V_131 . V_23 . V_5 -= V_49 . V_53 . V_5 ;
else
V_131 . V_23 . V_5 += V_49 . V_53 . V_5 ;
V_14 = & V_131 ;
}
if ( V_49 . V_53 . V_55 != 0 ) {
V_131 = * V_14 ;
if ( V_49 . V_50 ) {
if ( V_131 . V_23 . V_55 < V_49 . V_53 . V_55 ) {
V_131 . V_23 . V_5 -- ;
V_131 . V_23 . V_55 += V_54 ;
}
V_131 . V_23 . V_55 -= V_49 . V_53 . V_55 ;
} else {
if ( V_131 . V_23 . V_55 + V_49 . V_53 . V_55 > V_54 ) {
V_131 . V_23 . V_5 ++ ;
V_131 . V_23 . V_55 += V_49 . V_53 . V_55 - V_54 ;
} else {
V_131 . V_23 . V_55 += V_49 . V_53 . V_55 ;
}
}
V_14 = & V_131 ;
}
}
if ( V_135 ) {
F_16 ( V_14 , V_4 , ( T_7 * ) & V_14 -> V_166 ) ;
}
if ( V_154 ) {
if ( F_17 ( V_4 , V_14 -> V_166 ) ) {
if ( V_36 ) {
fprintf ( V_28 , L_136 ,
V_118 , V_14 -> V_166 ) ;
for ( V_43 = 0 ; V_43 < 16 ; V_43 ++ )
fprintf ( V_28 , L_137 ,
( unsigned char ) V_72 [ V_70 ] . V_73 [ V_43 ] ) ;
fprintf ( V_28 , L_15 ) ;
}
V_119 ++ ;
V_118 ++ ;
continue;
} else {
if ( V_36 ) {
fprintf ( V_28 , L_138 ,
V_118 , V_14 -> V_166 ) ;
for ( V_43 = 0 ; V_43 < 16 ; V_43 ++ )
fprintf ( V_28 , L_137 ,
( unsigned char ) V_72 [ V_70 ] . V_73 [ V_43 ] ) ;
fprintf ( V_28 , L_15 ) ;
}
}
}
if ( V_14 -> V_21 & V_22 ) {
if ( V_155 ) {
T_2 V_74 ;
V_74 . V_5 = V_14 -> V_23 . V_5 ;
V_74 . V_55 = V_14 -> V_23 . V_55 ;
if ( F_21 ( V_4 , V_14 -> V_166 , & V_74 ) ) {
if ( V_36 ) {
fprintf ( V_28 , L_136 ,
V_118 , V_14 -> V_166 ) ;
for ( V_43 = 0 ; V_43 < 16 ; V_43 ++ )
fprintf ( V_28 , L_137 ,
( unsigned char ) V_72 [ V_70 ] . V_73 [ V_43 ] ) ;
fprintf ( V_28 , L_15 ) ;
}
V_119 ++ ;
V_118 ++ ;
continue;
} else {
if ( V_36 ) {
fprintf ( V_28 , L_138 ,
V_118 , V_14 -> V_166 ) ;
for ( V_43 = 0 ; V_43 < 16 ; V_43 ++ )
fprintf ( V_28 , L_137 ,
( unsigned char ) V_72 [ V_70 ] . V_73 [ V_43 ] ) ;
fprintf ( V_28 , L_15 ) ;
}
}
}
}
if ( V_129 > V_14 -> V_166 ) {
fprintf ( V_28 , L_139 ,
V_129 , V_14 -> V_166 , V_118 ) ;
}
if ( V_156 > 0.0 && V_129 <= V_14 -> V_166 ) {
int V_168 = 0 ;
if ( F_77 ( V_106 ) == V_169 )
V_168 = F_93 ( V_4 ) ;
V_168 += V_129 ;
for ( V_43 = V_168 ; V_43 < ( int ) V_14 -> V_166 ; V_43 ++ ) {
if ( rand () <= V_156 * V_170 ) {
V_121 = rand () / ( V_170 / V_171 + 1 ) ;
if ( V_121 < V_172 ) {
V_4 [ V_43 ] ^= 1 << ( rand () / ( V_170 / 8 + 1 ) ) ;
V_121 = V_171 ;
} else {
V_121 -= V_173 ;
}
if ( V_121 < V_173 ) {
V_4 [ V_43 ] = rand () / ( V_170 / 255 + 1 ) ;
V_121 = V_171 ;
} else {
V_121 -= V_173 ;
}
if ( V_121 < V_174 ) {
V_4 [ V_43 ] = V_175 [ rand () / ( V_170 / V_176 + 1 ) ] ;
V_121 = V_171 ;
} else {
V_121 -= V_174 ;
}
if ( V_121 < V_177 ) {
if ( ( unsigned int ) V_43 < V_14 -> V_166 - 2 )
F_94 ( ( char * ) & V_4 [ V_43 ] , L_102 , 2 ) ;
V_121 = V_171 ;
} else {
V_121 -= V_177 ;
}
if ( V_121 < V_178 ) {
for ( V_107 = V_43 ; V_107 < ( int ) V_14 -> V_166 ; V_107 ++ )
V_4 [ V_107 ] = 0xAA ;
V_43 = V_14 -> V_166 ;
}
}
}
}
if ( V_139 ) {
const char * V_179 =
( const char * ) F_95 ( V_139 , F_66 ( V_122 ) ) ;
if ( V_179 != NULL ) {
V_131 = * V_14 ;
V_131 . V_180 = F_8 ( V_179 ) ;
V_14 = & V_131 ;
}
}
if ( ! F_96 ( V_99 , V_14 , V_4 , & V_98 , & V_110 ) ) {
switch ( V_98 ) {
case V_181 :
fprintf ( V_28 ,
L_140 ,
V_122 , V_103 [ V_160 ] ,
F_34 ( V_100 ) ) ;
break;
case V_182 :
fprintf ( V_28 ,
L_141 ,
V_122 , V_103 [ V_160 ] ,
F_34 ( V_100 ) ) ;
break;
case V_183 :
fprintf ( V_28 ,
L_142 ,
V_122 , V_103 [ V_160 ] ,
F_34 ( V_100 ) ) ;
break;
case V_184 :
fprintf ( V_28 ,
L_143 ,
V_122 , V_103 [ V_160 ] ,
F_34 ( V_100 ) ,
V_110 != NULL ? V_110 : L_144 ) ;
F_6 ( V_110 ) ;
break;
default:
fprintf ( V_28 , L_133 ,
V_93 , F_76 ( V_98 ) ) ;
break;
}
goto V_162;
}
V_124 ++ ;
}
V_118 ++ ;
}
F_6 ( V_15 ) ;
F_6 ( V_16 ) ;
if ( V_108 != 0 ) {
fprintf ( V_28 ,
L_145 ,
V_103 [ V_160 ] , F_76 ( V_108 ) ) ;
if ( V_109 != NULL ) {
fprintf ( V_28 , L_129 , V_109 ) ;
F_6 ( V_109 ) ;
}
}
if ( ! V_99 ) {
F_6 ( V_93 ) ;
V_93 = F_8 ( V_103 [ V_160 + 1 ] ) ;
V_99 = F_44 ( V_93 ,
V_94 ? F_88 ( V_94 , F_89 ( V_106 ) ) : F_89 ( V_106 ) ,
V_95 , V_96 , V_97 , & V_98 ) ;
if ( V_99 == NULL ) {
fprintf ( V_28 , L_132 ,
V_93 , F_76 ( V_98 ) ) ;
goto V_162;
}
}
F_6 ( V_96 ) ;
V_96 = NULL ;
if ( ! F_91 ( V_99 , & V_98 ) ) {
fprintf ( V_28 , L_133 , V_93 ,
F_76 ( V_98 ) ) ;
goto V_162;
}
F_97 ( V_95 ) ;
V_95 = NULL ;
F_97 ( V_97 ) ;
V_97 = NULL ;
F_6 ( V_93 ) ;
if ( V_139 ) {
F_98 ( V_139 ) ;
}
}
if ( V_154 ) {
fprintf ( V_28 , L_146 ,
V_118 - 1 , F_99 ( V_118 - 1 , L_147 , L_148 ) , V_119 ,
F_99 ( V_119 , L_147 , L_148 ) , V_71 ) ;
} else if ( V_155 ) {
fprintf ( V_28 , L_149 ,
V_118 - 1 , F_99 ( V_118 - 1 , L_147 , L_148 ) , V_119 ,
F_99 ( V_119 , L_147 , L_148 ) ,
( long ) V_57 . V_5 ,
( long int ) V_57 . V_55 ) ;
}
return 0 ;
V_162:
F_97 ( V_95 ) ;
F_97 ( V_97 ) ;
F_6 ( V_96 ) ;
exit ( 2 ) ;
}
static int
F_93 ( T_6 * V_4 )
{
int V_185 = 0 ;
for ( V_185 = 0 ; V_4 [ V_185 ] != '\0' ; V_185 ++ ) ;
V_185 ++ ;
V_185 ++ ;
for (; V_4 [ V_185 ] != '\0' ; V_185 ++ ) ;
V_185 ++ ;
for (; V_4 [ V_185 ] != '\0' ; V_185 ++ ) ;
V_185 ++ ;
for (; V_4 [ V_185 ] != '\0' ; V_185 ++ ) ;
V_185 ++ ;
for (; V_4 [ V_185 ] != '\0' ; V_185 ++ ) ;
V_185 ++ ;
V_185 += 2 ;
return V_185 ;
}
static void
F_92 ( T_24 V_116 , struct V_13 * V_186 ,
const struct V_13 * V_187 , T_6 * * V_4 ,
T_4 V_117 )
{
if ( V_187 -> V_188 != V_189 )
return;
if ( V_116 . V_148 == 0 )
V_116 . V_149 = V_116 . V_150 = 0 ;
if ( V_116 . V_151 == 0 )
V_116 . V_152 = V_116 . V_153 = 0 ;
if ( V_116 . V_150 < 0 ) {
V_116 . V_149 += V_187 -> V_166 + V_116 . V_150 ;
V_116 . V_150 = 0 ;
}
if ( V_116 . V_152 > 0 ) {
V_116 . V_153 += V_116 . V_152 - V_187 -> V_166 ;
V_116 . V_152 = 0 ;
}
if ( V_116 . V_148 && V_116 . V_151 ) {
if ( V_116 . V_149 > ( ( int ) V_187 -> V_166 + V_116 . V_153 ) ) {
int V_190 , V_191 ;
V_191 = V_187 -> V_166 + V_116 . V_153 + V_116 . V_151 ;
V_190 = - V_116 . V_151 ;
V_116 . V_153 = V_116 . V_148 + V_116 . V_149 - V_187 -> V_166 ;
V_116 . V_151 = - V_116 . V_148 ;
V_116 . V_148 = V_190 ;
V_116 . V_149 = V_191 ;
}
}
if ( V_187 -> V_166 < ( T_7 ) ( V_116 . V_149 - V_116 . V_153 ) ) {
V_116 . V_148 = 0 ;
V_116 . V_151 = 0 ;
}
if ( ( T_7 ) ( V_116 . V_148 - V_116 . V_151 ) >
( V_187 -> V_166 - ( T_7 ) ( V_116 . V_149 - V_116 . V_153 ) ) ) {
V_116 . V_148 = V_187 -> V_166 - ( V_116 . V_149 - V_116 . V_153 ) ;
V_116 . V_151 = 0 ;
}
if ( V_116 . V_148 > 0 ) {
* V_186 = * V_187 ;
if ( V_116 . V_149 > 0 ) {
memmove ( * V_4 + V_116 . V_149 ,
* V_4 + V_116 . V_149 + V_116 . V_148 ,
V_186 -> V_166 - V_116 . V_148 ) ;
} else {
* V_4 += V_116 . V_148 ;
}
V_186 -> V_166 -= V_116 . V_148 ;
if ( V_117 ) {
if ( V_187 -> V_59 > ( T_7 ) V_116 . V_148 )
V_186 -> V_59 -= V_116 . V_148 ;
else
V_186 -> V_59 = 0 ;
}
V_187 = V_186 ;
}
if ( V_116 . V_151 < 0 ) {
* V_186 = * V_187 ;
if ( V_116 . V_153 < 0 ) {
memmove ( * V_4 + ( T_10 ) V_186 -> V_166 + ( V_116 . V_151 + V_116 . V_153 ) ,
* V_4 + ( T_10 ) V_186 -> V_166 + V_116 . V_153 ,
- V_116 . V_153 ) ;
}
V_186 -> V_166 += V_116 . V_151 ;
if ( V_117 ) {
if ( ( ( signed int ) V_187 -> V_59 + V_116 . V_151 ) > 0 )
V_186 -> V_59 += V_116 . V_151 ;
else
V_186 -> V_59 = 0 ;
}
}
}
