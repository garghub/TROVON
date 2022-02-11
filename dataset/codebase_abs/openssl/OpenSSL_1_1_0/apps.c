int F_1 ( ARGS * V_1 , char * V_2 )
{
int V_3 ;
char V_4 = '\0' , * V_5 = NULL ;
V_1 -> V_6 = 0 ;
if ( V_1 -> V_7 == 0 ) {
V_1 -> V_7 = 20 ;
V_1 -> V_8 = F_2 ( sizeof( * V_1 -> V_8 ) * V_1 -> V_7 , L_1 ) ;
}
for ( V_5 = V_2 ; ; ) {
while ( * V_5 && isspace ( F_3 ( * V_5 ) ) )
V_5 ++ ;
if ( ! * V_5 )
break;
if ( V_1 -> V_6 >= V_1 -> V_7 ) {
char * * V_9 ;
V_1 -> V_7 += 20 ;
V_9 = F_4 ( V_1 -> V_8 , sizeof( * V_1 -> V_8 ) * V_1 -> V_7 ) ;
if ( V_9 == NULL )
return 0 ;
V_1 -> V_8 = V_9 ;
}
V_3 = * V_5 == '\'' || * V_5 == '"' ;
if ( V_3 )
V_4 = * V_5 ++ ;
V_1 -> V_8 [ V_1 -> V_6 ++ ] = V_5 ;
if ( V_3 ) {
while ( * V_5 && * V_5 != V_4 )
V_5 ++ ;
* V_5 ++ = '\0' ;
} else {
while ( * V_5 && ! isspace ( F_3 ( * V_5 ) ) )
V_5 ++ ;
if ( * V_5 )
* V_5 ++ = '\0' ;
}
}
V_1 -> V_8 [ V_1 -> V_6 ] = NULL ;
return ( 1 ) ;
}
int F_5 ( long V_10 )
{
return ( 1 ) ;
}
int F_6 ( T_1 * V_11 , const char * V_12 ,
const char * V_13 , int V_14 , int V_15 )
{
if ( V_12 == NULL && V_13 == NULL ) {
if ( ! V_14 && F_7 ( V_11 ) <= 0 )
return 0 ;
if ( ! V_15 && F_8 ( V_11 ) <= 0 )
return 0 ;
return 1 ;
}
return F_9 ( V_11 , V_12 , V_13 ) ;
}
int F_10 ( T_1 * V_11 , const char * V_16 )
{
if ( V_16 == NULL ) {
return F_11 ( V_11 ) ;
}
return F_12 ( V_11 , V_16 ) ;
}
int F_13 ( T_2 * V_17 , T_3 * V_18 )
{
char * V_5 ;
V_5 = F_14 ( F_15 ( V_18 ) , NULL , 0 ) ;
F_16 ( V_17 , L_2 ) ;
F_16 ( V_17 , V_5 ) ;
F_17 ( V_5 ) ;
V_5 = F_14 ( F_18 ( V_18 ) , NULL , 0 ) ;
F_16 ( V_17 , L_3 ) ;
F_16 ( V_17 , V_5 ) ;
F_16 ( V_17 , L_4 ) ;
F_17 ( V_5 ) ;
return 0 ;
}
static int F_19 ( T_4 * V_19 )
{
return F_20 ( F_21 () ) ( V_19 ) ;
}
static int F_22 ( T_4 * V_19 , T_5 * V_20 )
{
if ( F_23 ( V_20 ) & V_21
&& F_24 ( V_19 ) ) {
switch ( F_25 ( V_20 ) ) {
case V_22 :
case V_23 :
{
const char * V_24 =
( ( V_25 * ) F_24 ( V_19 ) ) -> V_24 ;
if ( V_24 && V_24 [ 0 ] != '\0' ) {
F_26 ( V_19 , V_20 , V_24 ) ;
return 1 ;
}
}
default:
break;
}
}
return F_27 ( F_21 () ) ( V_19 , V_20 ) ;
}
static int F_28 ( T_4 * V_19 , T_5 * V_20 )
{
if ( F_23 ( V_20 ) & V_21
&& F_24 ( V_19 ) ) {
switch ( F_25 ( V_20 ) ) {
case V_22 :
case V_23 :
{
const char * V_24 =
( ( V_25 * ) F_24 ( V_19 ) ) -> V_24 ;
if ( V_24 && V_24 [ 0 ] != '\0' )
return 1 ;
}
default:
break;
}
}
return F_29 ( F_21 () ) ( V_19 , V_20 ) ;
}
static int F_30 ( T_4 * V_19 )
{
return F_31 ( F_21 () ) ( V_19 ) ;
}
int F_32 ( void )
{
V_26 = F_33 ( L_5 ) ;
F_34 ( V_26 , F_19 ) ;
F_35 ( V_26 , F_22 ) ;
F_36 ( V_26 , F_28 ) ;
F_37 ( V_26 , F_30 ) ;
return 0 ;
}
void F_38 ( void )
{
if ( V_26 ) {
F_39 ( V_26 ) ;
V_26 = NULL ;
}
}
int F_40 ( char * V_2 , int V_27 , int V_28 , V_25 * V_29 )
{
int V_30 = 0 ;
#ifndef F_41
T_4 * V_19 = NULL ;
const char * V_31 = NULL ;
#endif
const char * V_24 = NULL ;
V_25 * V_32 = ( V_25 * ) V_29 ;
if ( V_32 ) {
if ( V_32 -> V_24 )
V_24 = V_32 -> V_24 ;
#ifndef F_41
if ( V_32 -> V_31 )
V_31 = V_32 -> V_31 ;
#endif
}
if ( V_24 ) {
V_30 = strlen ( V_24 ) ;
if ( V_30 > V_27 )
V_30 = V_27 ;
memcpy ( V_2 , V_24 , V_30 ) ;
return V_30 ;
}
#ifndef F_41
V_19 = F_42 ( V_26 ) ;
if ( V_19 ) {
int V_33 = 0 ;
char * V_34 = NULL ;
int V_35 = 0 ;
char * V_36 ;
V_36 = F_43 ( V_19 , L_6 , V_31 ) ;
if ( ! V_36 ) {
F_44 ( V_37 , L_7 ) ;
F_45 ( V_19 ) ;
return 0 ;
}
V_35 |= V_21 ;
F_46 ( V_19 , V_38 , 1 , 0 , 0 ) ;
if ( V_33 >= 0 )
V_33 = F_47 ( V_19 , V_36 , V_35 , V_2 ,
V_39 , V_27 - 1 ) ;
if ( V_33 >= 0 && V_28 ) {
V_34 = F_2 ( V_27 , L_8 ) ;
V_33 = F_48 ( V_19 , V_36 , V_35 , V_34 ,
V_39 , V_27 - 1 , V_2 ) ;
}
if ( V_33 >= 0 )
do {
V_33 = F_49 ( V_19 ) ;
}
while ( V_33 < 0 && F_46 ( V_19 , V_40 , 0 , 0 , 0 ) );
F_50 ( V_34 , ( unsigned int ) V_27 ) ;
if ( V_33 >= 0 )
V_30 = strlen ( V_2 ) ;
if ( V_33 == - 1 ) {
F_44 ( V_37 , L_9 ) ;
F_51 ( V_37 ) ;
F_52 ( V_2 , ( unsigned int ) V_27 ) ;
V_30 = 0 ;
}
if ( V_33 == - 2 ) {
F_44 ( V_37 , L_10 ) ;
F_52 ( V_2 , ( unsigned int ) V_27 ) ;
V_30 = 0 ;
}
F_45 ( V_19 ) ;
F_17 ( V_36 ) ;
}
#endif
return V_30 ;
}
int F_53 ( const char * V_41 , const char * V_42 , char * * V_43 , char * * V_44 )
{
int V_45 ;
if ( ! V_42 || ! V_41 || strcmp ( V_41 , V_42 ) )
V_45 = 0 ;
else
V_45 = 1 ;
if ( V_41 ) {
* V_43 = F_54 ( V_41 , V_45 ) ;
if ( ! * V_43 )
return 0 ;
} else if ( V_43 )
* V_43 = NULL ;
if ( V_42 ) {
* V_44 = F_54 ( V_42 , V_45 ? 2 : 0 ) ;
if ( ! * V_44 )
return 0 ;
} else if ( V_44 )
* V_44 = NULL ;
return 1 ;
}
static char * F_54 ( const char * V_1 , int V_46 )
{
char * V_9 , V_47 [ V_48 ] ;
static T_2 * V_49 = NULL ;
int V_50 ;
if ( strncmp ( V_1 , L_11 , 5 ) == 0 )
return F_55 ( V_1 + 5 ) ;
if ( strncmp ( V_1 , L_12 , 4 ) == 0 ) {
V_9 = getenv ( V_1 + 4 ) ;
if ( ! V_9 ) {
F_44 ( V_37 , L_13 , V_1 + 4 ) ;
return NULL ;
}
return F_55 ( V_9 ) ;
}
if ( ! V_46 || ! V_49 ) {
if ( strncmp ( V_1 , L_14 , 5 ) == 0 ) {
V_49 = F_56 ( V_1 + 5 , L_15 ) ;
if ( ! V_49 ) {
F_44 ( V_37 , L_16 , V_1 + 5 ) ;
return NULL ;
}
#if ! F_57 ( V_51 )
} else if ( strncmp ( V_1 , L_17 , 3 ) == 0 ) {
T_2 * V_52 ;
V_50 = atoi ( V_1 + 3 ) ;
if ( V_50 >= 0 )
V_49 = F_58 ( V_50 , V_53 ) ;
if ( ( V_50 < 0 ) || ! V_49 ) {
F_44 ( V_37 , L_18 , V_1 + 3 ) ;
return NULL ;
}
V_52 = F_59 ( F_60 () ) ;
V_49 = F_61 ( V_52 , V_49 ) ;
#endif
} else if ( strcmp ( V_1 , L_19 ) == 0 ) {
V_49 = F_62 ( V_54 ) ;
if ( ! V_49 ) {
F_44 ( V_37 , L_20 ) ;
return NULL ;
}
} else {
F_44 ( V_37 , L_21 , V_1 ) ;
return NULL ;
}
}
V_50 = F_63 ( V_49 , V_47 , V_48 ) ;
if ( V_46 != 1 ) {
F_64 ( V_49 ) ;
V_49 = NULL ;
}
if ( V_50 <= 0 ) {
F_44 ( V_37 , L_22 ) ;
return NULL ;
}
V_9 = strchr ( V_47 , '\n' ) ;
if ( V_9 )
* V_9 = 0 ;
return F_55 ( V_47 ) ;
}
static T_6 * F_65 ( T_2 * V_55 , const char * V_56 )
{
long V_57 = - 1 ;
T_6 * V_58 ;
int V_50 ;
V_58 = F_66 ( NULL ) ;
V_50 = F_67 ( V_58 , V_55 , & V_57 ) ;
if ( V_50 > 0 )
return V_58 ;
if ( V_57 <= 0 )
F_44 ( V_37 , L_23 ,
F_68 () , V_56 ) ;
else
F_44 ( V_37 , L_24 ,
F_68 () , V_57 , V_56 ) ;
F_69 ( V_58 ) ;
return NULL ;
}
T_6 * F_70 ( const char * V_56 )
{
T_2 * V_55 ;
T_6 * V_58 ;
V_55 = F_71 ( V_56 , 'r' , V_54 ) ;
if ( V_55 == NULL )
return NULL ;
V_58 = F_65 ( V_55 , V_56 ) ;
F_72 ( V_55 ) ;
return V_58 ;
}
T_6 * F_73 ( const char * V_56 )
{
T_2 * V_55 ;
T_6 * V_58 ;
V_55 = F_74 ( V_56 , 'r' , V_54 ) ;
if ( V_55 == NULL )
return NULL ;
V_58 = F_65 ( V_55 , V_56 ) ;
F_72 ( V_55 ) ;
return V_58 ;
}
int F_75 ( const T_6 * V_59 )
{
T_6 * V_60 = NULL ;
if ( V_59 == NULL )
V_59 = V_60 = F_73 ( V_61 ) ;
if ( V_59 == NULL )
return 1 ;
if ( F_76 ( V_59 , NULL , 0 ) <= 0 ) {
F_44 ( V_37 , L_25 ) ;
F_51 ( V_37 ) ;
F_69 ( V_60 ) ;
return 0 ;
}
F_69 ( V_60 ) ;
return 1 ;
}
int F_77 ( T_6 * V_58 )
{
char * V_5 ;
F_78 ( V_62 ) * V_63 ;
V_62 * V_64 ;
int V_50 ;
if ( ( V_5 = F_79 ( V_58 , NULL , L_26 ) ) == NULL ) {
F_80 () ;
return 1 ;
}
if ( ( V_63 = F_81 ( V_58 , V_5 ) ) == NULL ) {
F_44 ( V_37 , L_27 , V_5 ) ;
return 0 ;
}
for ( V_50 = 0 ; V_50 < F_82 ( V_63 ) ; V_50 ++ ) {
V_64 = F_83 ( V_63 , V_50 ) ;
if ( F_84 ( V_64 -> V_65 , V_64 -> V_66 , V_64 -> V_66 ) == V_67 ) {
F_44 ( V_37 , L_28 ,
V_64 -> V_66 , V_64 -> V_65 ) ;
return 0 ;
}
}
return 1 ;
}
static int F_85 ( const char * V_68 , T_3 * * V_69 , T_7 * * V_70 )
{
char * V_71 = NULL , * V_72 = NULL , * V_16 = NULL ;
T_2 * V_73 = NULL ;
T_8 * V_74 = NULL ;
int V_75 , V_76 = 0 ;
if ( ! F_86 ( V_68 , & V_71 , & V_72 , & V_16 , & V_75 ) )
goto V_77;
if ( V_75 ) {
F_16 ( V_37 , L_29 ) ;
goto V_77;
}
V_73 = F_87 ( V_71 ) ;
if ( ! V_73 || ! F_88 ( V_73 , V_72 ) )
goto V_77;
V_74 = F_89 ( V_73 , 1024 ) ;
if ( V_74 == NULL )
goto V_77;
if ( ! F_90 ( V_74 , L_30 , V_16 ) )
goto V_77;
if ( ! F_91 ( V_74 , L_31 , V_71 ) )
goto V_77;
if ( V_69 ) {
do {
V_76 = F_92 ( V_74 , V_69 ) ;
} while ( V_76 == - 1 );
} else {
do {
V_76 = F_93 ( V_74 , V_70 ) ;
} while ( V_76 == - 1 );
}
V_77:
F_17 ( V_71 ) ;
F_17 ( V_16 ) ;
F_17 ( V_72 ) ;
if ( V_73 )
F_64 ( V_73 ) ;
F_94 ( V_74 ) ;
if ( V_76 != 1 ) {
F_44 ( V_37 , L_32 ,
V_69 ? L_33 : L_34 , V_68 ) ;
F_51 ( V_37 ) ;
}
return V_76 ;
}
T_3 * F_95 ( const char * V_78 , int V_79 , const char * V_80 )
{
T_3 * V_18 = NULL ;
T_2 * V_81 ;
if ( V_79 == V_82 ) {
#if ! F_57 ( V_83 ) && ! F_57 ( V_84 )
F_85 ( V_78 , & V_18 , NULL ) ;
#endif
return V_18 ;
}
if ( V_78 == NULL ) {
F_96 ( V_85 ) ;
V_81 = F_62 ( V_79 ) ;
} else
V_81 = F_71 ( V_78 , 'r' , V_79 ) ;
if ( V_81 == NULL )
goto V_86;
if ( V_79 == V_87 )
V_18 = F_97 ( V_81 , NULL ) ;
else if ( V_79 == V_88 )
V_18 = F_98 ( V_81 , NULL ,
( V_89 * ) F_40 , NULL ) ;
else if ( V_79 == V_90 ) {
if ( ! F_99 ( V_81 , V_80 , NULL , NULL , NULL , & V_18 , NULL ) )
goto V_86;
} else {
F_44 ( V_37 , L_35 , V_80 ) ;
goto V_86;
}
V_86:
if ( V_18 == NULL ) {
F_44 ( V_37 , L_36 ) ;
F_51 ( V_37 ) ;
}
F_72 ( V_81 ) ;
return ( V_18 ) ;
}
T_7 * F_100 ( const char * V_91 , int V_79 )
{
T_7 * V_18 = NULL ;
T_2 * V_55 = NULL ;
if ( V_79 == V_82 ) {
#if ! F_57 ( V_83 ) && ! F_57 ( V_84 )
F_85 ( V_91 , NULL , & V_18 ) ;
#endif
return V_18 ;
}
V_55 = F_71 ( V_91 , 'r' , V_79 ) ;
if ( V_55 == NULL )
goto V_86;
if ( V_79 == V_87 )
V_18 = F_101 ( V_55 , NULL ) ;
else if ( V_79 == V_88 )
V_18 = F_102 ( V_55 , NULL , NULL , NULL ) ;
else {
F_44 ( V_37 , L_37 ) ;
goto V_86;
}
if ( V_18 == NULL ) {
F_44 ( V_37 , L_38 ) ;
F_51 ( V_37 ) ;
goto V_86;
}
V_86:
F_72 ( V_55 ) ;
return ( V_18 ) ;
}
T_9 * F_103 ( const char * V_78 , int V_79 , int V_92 ,
const char * V_93 , T_10 * V_94 , const char * V_95 )
{
T_2 * V_96 = NULL ;
T_9 * V_97 = NULL ;
V_25 V_32 ;
V_32 . V_24 = V_93 ;
V_32 . V_31 = V_78 ;
if ( V_78 == NULL && ( ! V_92 || V_79 == V_98 ) ) {
F_44 ( V_37 , L_39 ) ;
goto V_86;
}
if ( V_79 == V_98 ) {
if ( V_94 == NULL )
F_44 ( V_37 , L_40 ) ;
else {
#ifndef F_104
V_97 = F_105 ( V_94 , V_78 , V_26 , & V_32 ) ;
if ( V_97 == NULL ) {
F_44 ( V_37 , L_41 , V_95 ) ;
F_51 ( V_37 ) ;
}
#else
F_44 ( V_37 , L_42 ) ;
#endif
}
goto V_86;
}
if ( V_78 == NULL && V_92 ) {
F_96 ( V_85 ) ;
V_96 = F_62 ( V_79 ) ;
} else
V_96 = F_71 ( V_78 , 'r' , V_79 ) ;
if ( V_96 == NULL )
goto V_86;
if ( V_79 == V_87 ) {
V_97 = F_106 ( V_96 , NULL ) ;
} else if ( V_79 == V_88 ) {
V_97 = F_107 ( V_96 , NULL ,
( V_89 * ) F_40 ,
& V_32 ) ;
}
else if ( V_79 == V_90 ) {
if ( ! F_99 ( V_96 , V_95 ,
( V_89 * ) F_40 , & V_32 ,
& V_97 , NULL , NULL ) )
goto V_86;
}
#if ! F_57 ( V_99 ) && ! F_57 ( V_100 ) && ! F_57 ( V_101 )
else if ( V_79 == V_102 )
V_97 = F_108 ( V_96 ) ;
else if ( V_79 == V_103 )
V_97 = F_109 ( V_96 , ( V_89 * ) F_40 ,
& V_32 ) ;
#endif
else {
F_44 ( V_37 , L_43 ) ;
goto V_86;
}
V_86:
F_72 ( V_96 ) ;
if ( V_97 == NULL ) {
F_44 ( V_37 , L_44 , V_95 ) ;
F_51 ( V_37 ) ;
}
return ( V_97 ) ;
}
T_9 * F_110 ( const char * V_78 , int V_79 , int V_92 ,
const char * V_93 , T_10 * V_94 , const char * V_95 )
{
T_2 * V_96 = NULL ;
T_9 * V_97 = NULL ;
V_25 V_32 ;
V_32 . V_24 = V_93 ;
V_32 . V_31 = V_78 ;
if ( V_78 == NULL && ( ! V_92 || V_79 == V_98 ) ) {
F_44 ( V_37 , L_39 ) ;
goto V_86;
}
if ( V_79 == V_98 ) {
if ( V_94 == NULL )
F_44 ( V_37 , L_40 ) ;
else {
#ifndef F_104
V_97 = F_111 ( V_94 , V_78 , V_26 , & V_32 ) ;
if ( V_97 == NULL ) {
F_44 ( V_37 , L_41 , V_95 ) ;
F_51 ( V_37 ) ;
}
#else
F_44 ( V_37 , L_42 ) ;
#endif
}
goto V_86;
}
if ( V_78 == NULL && V_92 ) {
F_96 ( V_85 ) ;
V_96 = F_62 ( V_79 ) ;
} else
V_96 = F_71 ( V_78 , 'r' , V_79 ) ;
if ( V_96 == NULL )
goto V_86;
if ( V_79 == V_87 ) {
V_97 = F_112 ( V_96 , NULL ) ;
}
else if ( V_79 == V_104 ) {
#ifndef V_99
T_11 * V_105 ;
V_105 = F_113 ( V_96 , NULL ) ;
if ( V_105 ) {
V_97 = F_114 () ;
if ( V_97 != NULL )
F_115 ( V_97 , V_105 ) ;
F_116 ( V_105 ) ;
} else
#else
F_44 ( V_37 , L_45 ) ;
#endif
V_97 = NULL ;
} else if ( V_79 == V_106 ) {
#ifndef V_99
T_11 * V_105 ;
V_105 = F_117 ( V_96 , NULL ,
( V_89 * ) F_40 ,
& V_32 ) ;
if ( V_105 != NULL ) {
V_97 = F_114 () ;
if ( V_97 != NULL )
F_115 ( V_97 , V_105 ) ;
F_116 ( V_105 ) ;
} else
#else
F_44 ( V_37 , L_45 ) ;
#endif
V_97 = NULL ;
}
else if ( V_79 == V_88 ) {
V_97 = F_118 ( V_96 , NULL ,
( V_89 * ) F_40 ,
& V_32 ) ;
}
#if ! F_57 ( V_99 ) && ! F_57 ( V_100 )
else if ( V_79 == V_102 )
V_97 = F_119 ( V_96 ) ;
#endif
V_86:
F_72 ( V_96 ) ;
if ( V_97 == NULL )
F_44 ( V_37 , L_44 , V_95 ) ;
return ( V_97 ) ;
}
void * F_2 ( int V_107 , const char * V_108 )
{
void * V_109 = F_120 ( V_107 ) ;
if ( V_109 == NULL ) {
F_44 ( V_37 , L_46 ,
F_68 () , V_107 , V_108 ) ;
F_51 ( V_37 ) ;
exit ( 1 ) ;
}
return V_109 ;
}
int F_121 ( unsigned long * V_110 , const char * V_1 )
{
static const T_12 V_111 [] = {
{ L_47 , V_112 , 0xffffffffl } ,
{ L_48 , V_113 , 0xffffffffl } ,
{ L_49 , V_114 , 0 } ,
{ L_50 , V_115 , 0 } ,
{ L_51 , V_116 , 0 } ,
{ L_52 , V_117 , 0 } ,
{ L_53 , V_118 , 0 } ,
{ L_54 , V_119 , 0 } ,
{ L_55 , V_120 , 0 } ,
{ L_56 , V_121 , 0 } ,
{ L_57 , V_122 , 0 } ,
{ L_58 , V_123 , 0 } ,
{ L_59 , V_124 , 0 } ,
{ L_60 , V_125 , 0 } ,
{ L_61 , V_126 , V_127 } ,
{ L_62 , V_128 , V_127 } ,
{ L_63 , V_129 , V_127 } ,
{ L_64 , V_130 , V_127 } ,
{ NULL , 0 , 0 }
} ;
return F_122 ( V_110 , V_1 , V_111 ) ;
}
int F_123 ( unsigned long * V_110 , const char * V_1 )
{
static const T_12 V_131 [] = {
{ L_65 , V_132 , 0 } ,
{ L_66 , V_133 , 0 } ,
{ L_67 , V_134 , 0 } ,
{ L_68 , V_135 , 0 } ,
{ L_69 , V_136 , 0 } ,
{ L_70 , V_137 , 0 } ,
{ L_71 , V_138 , 0 } ,
{ L_72 , V_139 , 0 } ,
{ L_73 , V_140 , 0 } ,
{ L_74 , V_141 , 0 } ,
{ L_75 , V_142 , 0 } ,
{ L_76 , V_143 , 0xffffffffL } ,
{ L_77 , V_144 , V_145 } ,
{ L_78 , V_146 , V_145 } ,
{ L_79 , V_147 , V_145 } ,
{ L_80 , V_148 , V_145 } ,
{ L_81 , V_149 , 0 } ,
{ L_82 , V_150 , V_151 } ,
{ L_83 , V_152 , V_151 } ,
{ L_84 , V_153 , V_151 } ,
{ L_85 , V_154 , 0 } ,
{ L_86 , V_155 , V_151 } ,
{ L_87 , V_156 , 0 } ,
{ L_88 , V_157 , 0 } ,
{ L_89 , V_158 , 0xffffffffL } ,
{ L_90 , V_159 , 0xffffffffL } ,
{ L_91 , V_160 , 0xffffffffL } ,
{ L_48 , V_160 , 0xffffffffL } ,
{ NULL , 0 , 0 }
} ;
if ( F_122 ( V_110 , V_1 , V_131 ) == 0 )
return 0 ;
if ( ( * V_110 & V_145 ) == 0 )
* V_110 |= V_146 ;
return 1 ;
}
int F_124 ( int * V_161 , const char * V_1 )
{
if ( strcasecmp ( V_1 , L_92 ) == 0 )
* V_161 = V_162 ;
else if ( strcasecmp ( V_1 , L_93 ) == 0 )
* V_161 = V_163 ;
else if ( strcasecmp ( V_1 , L_94 ) == 0 )
* V_161 = V_164 ;
else
return 0 ;
return 1 ;
}
int F_125 ( T_3 * V_18 , T_13 * V_165 , int V_161 )
{
F_78 ( V_166 ) * V_167 = NULL ;
V_166 * V_168 , * V_169 ;
T_14 * V_170 ;
int V_50 , V_171 , V_172 = 0 ;
if ( ! V_18 || ! V_165 || ( V_161 == V_162 ) )
return 1 ;
V_167 = F_126 ( V_165 ) ;
for ( V_50 = 0 ; V_50 < F_127 ( V_167 ) ; V_50 ++ ) {
V_168 = F_128 ( V_167 , V_50 ) ;
V_170 = F_129 ( V_168 ) ;
V_171 = F_130 ( V_18 , V_170 , - 1 ) ;
if ( V_171 != - 1 ) {
if ( V_161 == V_163 )
continue;
do {
V_169 = F_131 ( V_18 , V_171 ) ;
F_132 ( V_18 , V_171 ) ;
F_133 ( V_169 ) ;
V_171 = F_130 ( V_18 , V_170 , - 1 ) ;
} while ( V_171 != - 1 );
}
if ( ! F_134 ( V_18 , V_168 , - 1 ) )
goto V_86;
}
V_172 = 1 ;
V_86:
F_135 ( V_167 , F_133 ) ;
return V_172 ;
}
static int F_122 ( unsigned long * V_110 , const char * V_1 ,
const T_12 * V_173 )
{
F_78 ( V_62 ) * V_174 ;
V_62 * V_175 ;
int V_50 , V_172 = 1 ;
if ( ! V_1 )
return 0 ;
V_174 = F_136 ( V_1 ) ;
for ( V_50 = 0 ; V_50 < F_82 ( V_174 ) ; V_50 ++ ) {
V_175 = F_83 ( V_174 , V_50 ) ;
if ( ! F_137 ( V_110 , V_175 -> V_66 , V_173 ) )
V_172 = 0 ;
}
F_138 ( V_174 , V_176 ) ;
return V_172 ;
}
static int F_137 ( unsigned long * V_110 , const char * V_1 ,
const T_12 * V_173 )
{
char V_4 ;
const T_12 * V_177 ;
V_4 = V_1 [ 0 ] ;
if ( V_4 == '-' ) {
V_4 = 0 ;
V_1 ++ ;
} else if ( V_4 == '+' ) {
V_4 = 1 ;
V_1 ++ ;
} else
V_4 = 1 ;
for ( V_177 = V_173 ; V_177 -> V_66 ; V_177 ++ ) {
if ( strcasecmp ( V_1 , V_177 -> V_66 ) == 0 ) {
* V_110 &= ~ V_177 -> V_178 ;
if ( V_4 )
* V_110 |= V_177 -> V_179 ;
else
* V_110 &= ~ V_177 -> V_179 ;
return 1 ;
}
}
return 0 ;
}
void F_139 ( T_2 * V_17 , const char * V_180 , T_15 * V_181 ,
unsigned long V_182 )
{
char * V_2 ;
char V_183 = 0 ;
int V_184 = 0 ;
if ( V_180 )
F_16 ( V_17 , V_180 ) ;
if ( ( V_182 & V_145 ) == V_148 ) {
V_183 = 1 ;
V_184 = 4 ;
}
if ( V_182 == V_143 ) {
V_2 = F_14 ( V_181 , 0 , 0 ) ;
F_16 ( V_17 , V_2 ) ;
F_16 ( V_17 , L_4 ) ;
F_17 ( V_2 ) ;
} else {
if ( V_183 )
F_16 ( V_17 , L_4 ) ;
F_140 ( V_17 , V_181 , V_184 , V_182 ) ;
F_16 ( V_17 , L_4 ) ;
}
}
void F_141 ( T_2 * V_17 , const T_16 * V_55 , const char * V_185 ,
int V_186 , unsigned char * V_187 )
{
F_44 ( V_17 , L_95 , V_185 , V_186 ) ;
if ( F_142 ( V_55 ) )
F_44 ( V_17 , L_96 ) ;
else {
int V_50 , V_188 ;
V_188 = F_143 ( V_55 , V_187 ) ;
for ( V_50 = 0 ; V_50 < V_188 ; V_50 ++ ) {
if ( ( V_50 % 10 ) == 0 )
F_44 ( V_17 , L_97 ) ;
if ( V_50 < V_188 - 1 )
F_44 ( V_17 , L_98 , V_187 [ V_50 ] ) ;
else
F_44 ( V_17 , L_99 , V_187 [ V_50 ] ) ;
}
}
F_44 ( V_17 , L_100 ) ;
}
void F_144 ( T_2 * V_17 , const char * V_180 , int V_186 , const unsigned char * V_189 )
{
int V_50 ;
F_44 ( V_17 , L_101 , V_180 , V_186 ) ;
for ( V_50 = 0 ; V_50 < V_186 ; V_50 ++ ) {
if ( ( V_50 % 10 ) == 0 )
F_44 ( V_17 , L_102 ) ;
if ( V_50 < V_186 - 1 )
F_44 ( V_17 , L_98 , V_189 [ V_50 ] ) ;
else
F_44 ( V_17 , L_99 , V_189 [ V_50 ] ) ;
}
F_44 ( V_17 , L_103 ) ;
}
T_17 * F_145 ( const char * V_12 , const char * V_13 , int V_14 , int V_15 )
{
T_17 * V_190 = F_146 () ;
T_18 * V_191 ;
if ( V_190 == NULL )
goto V_86;
if ( V_12 != NULL || ! V_14 ) {
V_191 = F_147 ( V_190 , F_148 () ) ;
if ( V_191 == NULL )
goto V_86;
if ( V_12 ) {
if ( ! F_149 ( V_191 , V_12 , V_192 ) ) {
F_44 ( V_37 , L_104 , V_12 ) ;
goto V_86;
}
} else
F_149 ( V_191 , NULL , V_193 ) ;
}
if ( V_13 != NULL || ! V_15 ) {
V_191 = F_147 ( V_190 , F_150 () ) ;
if ( V_191 == NULL )
goto V_86;
if ( V_13 ) {
if ( ! F_151 ( V_191 , V_13 , V_192 ) ) {
F_44 ( V_37 , L_105 , V_13 ) ;
goto V_86;
}
} else
F_151 ( V_191 , NULL , V_193 ) ;
}
F_80 () ;
return V_190 ;
V_86:
F_152 ( V_190 ) ;
return NULL ;
}
static T_10 * F_153 ( const char * V_194 )
{
T_10 * V_94 = F_154 ( L_106 ) ;
if ( V_94 ) {
if ( ! F_155 ( V_94 , L_107 , V_194 , 0 )
|| ! F_155 ( V_94 , L_108 , NULL , 0 ) ) {
F_156 ( V_94 ) ;
V_94 = NULL ;
}
}
return V_94 ;
}
T_10 * F_157 ( const char * V_194 , int V_195 )
{
T_10 * V_94 = NULL ;
if ( V_194 ) {
if ( strcmp ( V_194 , L_109 ) == 0 ) {
F_44 ( V_37 , L_110 ) ;
F_158 () ;
return NULL ;
}
if ( ( V_94 = F_154 ( V_194 ) ) == NULL
&& ( V_94 = F_153 ( V_194 ) ) == NULL ) {
F_44 ( V_37 , L_111 , V_194 ) ;
F_51 ( V_37 ) ;
return NULL ;
}
if ( V_195 ) {
F_159 ( V_94 , V_196 , 0 , V_37 , 0 ) ;
}
F_160 ( V_94 , L_112 , 0 , V_26 , 0 , 1 ) ;
if ( ! F_161 ( V_94 , V_197 ) ) {
F_44 ( V_37 , L_113 ) ;
F_51 ( V_37 ) ;
F_156 ( V_94 ) ;
return NULL ;
}
F_44 ( V_37 , L_114 , F_162 ( V_94 ) ) ;
F_156 ( V_94 ) ;
}
return V_94 ;
}
static unsigned long F_163 ( const T_19 * V_198 )
{
const char * V_199 ;
V_199 = V_198 [ V_200 ] ;
while ( * V_199 == '0' )
V_199 ++ ;
return F_164 ( V_199 ) ;
}
static int F_165 ( const T_19 * V_198 ,
const T_19 * V_201 )
{
const char * V_202 , * V_203 ;
for ( V_202 = V_198 [ V_200 ] ; * V_202 == '0' ; V_202 ++ ) ;
for ( V_203 = V_201 [ V_200 ] ; * V_203 == '0' ; V_203 ++ ) ;
return ( strcmp ( V_202 , V_203 ) ) ;
}
static int F_166 ( char * * V_198 )
{
return ( V_198 [ 0 ] [ 0 ] == 'V' ) ;
}
static unsigned long F_167 ( const T_19 * V_198 )
{
return F_164 ( V_198 [ V_204 ] ) ;
}
int F_168 ( const T_19 * V_198 , const T_19 * V_201 )
{
return ( strcmp ( V_198 [ V_204 ] , V_201 [ V_204 ] ) ) ;
}
int F_169 ( const char * V_205 , const char * V_206 ,
const char * V_207 )
{
char V_2 [ 2 ] [ V_208 ] ;
int V_50 , V_209 ;
V_50 = strlen ( V_205 ) + strlen ( V_207 ) ;
V_209 = strlen ( V_205 ) + strlen ( V_206 ) ;
if ( V_50 > V_209 )
V_209 = V_50 ;
if ( V_209 + 1 >= V_208 ) {
F_44 ( V_37 , L_115 ) ;
goto V_77;
}
#ifndef F_170
V_209 = F_171 ( V_2 [ 0 ] , sizeof V_2 [ 0 ] , L_116 , V_205 , V_206 ) ;
V_209 = F_171 ( V_2 [ 1 ] , sizeof V_2 [ 1 ] , L_116 , V_205 , V_207 ) ;
#else
V_209 = F_171 ( V_2 [ 0 ] , sizeof V_2 [ 0 ] , L_117 , V_205 , V_206 ) ;
V_209 = F_171 ( V_2 [ 1 ] , sizeof V_2 [ 1 ] , L_117 , V_205 , V_207 ) ;
#endif
if ( rename ( V_205 , V_2 [ 1 ] ) < 0 && V_210 != V_211
#ifdef F_172
&& V_210 != F_172
#endif
) {
F_44 ( V_37 ,
L_118 , V_205 , V_2 [ 1 ] ) ;
perror ( L_119 ) ;
goto V_77;
}
if ( rename ( V_2 [ 0 ] , V_205 ) < 0 ) {
F_44 ( V_37 ,
L_118 , V_2 [ 0 ] , V_205 ) ;
perror ( L_119 ) ;
rename ( V_2 [ 1 ] , V_205 ) ;
goto V_77;
}
return 1 ;
V_77:
return 0 ;
}
int F_173 ( T_16 * V_201 , T_20 * V_212 )
{
T_16 * V_52 ;
int V_172 = 0 ;
if ( V_201 )
V_52 = V_201 ;
else
V_52 = F_174 () ;
if ( V_52 == NULL )
return 0 ;
if ( ! F_175 ( V_52 , V_213 , 0 , 0 ) )
goto error;
if ( V_212 && ! F_176 ( V_52 , V_212 ) )
goto error;
V_172 = 1 ;
error:
if ( V_52 != V_201 )
F_177 ( V_52 ) ;
return V_172 ;
}
T_21 * F_178 ( const char * V_214 , T_22 * V_215 )
{
T_21 * V_216 = NULL ;
T_23 * V_217 = NULL ;
T_2 * V_55 ;
T_6 * V_218 = NULL ;
char V_2 [ V_208 ] ;
V_55 = F_56 ( V_214 , L_15 ) ;
if ( V_55 == NULL ) {
F_51 ( V_37 ) ;
goto V_77;
}
if ( ( V_217 = F_179 ( V_55 , V_219 ) ) == NULL )
goto V_77;
#ifndef F_170
F_171 ( V_2 , sizeof V_2 , L_120 , V_214 ) ;
#else
F_171 ( V_2 , sizeof V_2 , L_121 , V_214 ) ;
#endif
V_218 = F_70 ( V_2 ) ;
V_216 = F_2 ( sizeof( * V_216 ) , L_122 ) ;
V_216 -> V_220 = V_217 ;
V_217 = NULL ;
if ( V_215 )
V_216 -> V_221 = * V_215 ;
else {
V_216 -> V_221 . V_222 = 1 ;
}
if ( V_218 ) {
char * V_5 = F_79 ( V_218 , NULL , L_123 ) ;
if ( V_5 ) {
V_216 -> V_221 . V_222 = F_180 ( V_5 , 1 ) ;
}
}
V_77:
F_69 ( V_218 ) ;
F_181 ( V_217 ) ;
F_64 ( V_55 ) ;
return V_216 ;
}
int F_182 ( T_21 * V_220 )
{
if ( ! F_183 ( V_220 -> V_220 , V_200 , NULL ,
F_184 ( V_223 ) ,
F_185 ( V_223 ) ) ) {
F_44 ( V_37 ,
L_124 ,
V_220 -> V_220 -> error , V_220 -> V_220 -> V_41 , V_220 -> V_220 -> V_42 ) ;
return 0 ;
}
if ( V_220 -> V_221 . V_222
&& ! F_183 ( V_220 -> V_220 , V_204 , F_166 ,
F_184 ( V_224 ) ,
F_185 ( V_224 ) ) ) {
F_44 ( V_37 , L_125 ,
V_220 -> V_220 -> error , V_220 -> V_220 -> V_41 , V_220 -> V_220 -> V_42 ) ;
return 0 ;
}
return 1 ;
}
int F_186 ( const char * V_214 , const char * V_225 , T_21 * V_220 )
{
char V_2 [ 3 ] [ V_208 ] ;
T_2 * V_17 ;
int V_209 ;
V_209 = strlen ( V_214 ) + strlen ( V_225 ) ;
if ( V_209 + 6 >= V_208 ) {
F_44 ( V_37 , L_115 ) ;
goto V_77;
}
#ifndef F_170
V_209 = F_171 ( V_2 [ 2 ] , sizeof V_2 [ 2 ] , L_120 , V_214 ) ;
V_209 = F_171 ( V_2 [ 1 ] , sizeof V_2 [ 1 ] , L_126 , V_214 , V_225 ) ;
V_209 = F_171 ( V_2 [ 0 ] , sizeof V_2 [ 0 ] , L_116 , V_214 , V_225 ) ;
#else
V_209 = F_171 ( V_2 [ 2 ] , sizeof V_2 [ 2 ] , L_121 , V_214 ) ;
V_209 = F_171 ( V_2 [ 1 ] , sizeof V_2 [ 1 ] , L_127 , V_214 , V_225 ) ;
V_209 = F_171 ( V_2 [ 0 ] , sizeof V_2 [ 0 ] , L_117 , V_214 , V_225 ) ;
#endif
V_17 = F_56 ( V_2 [ 0 ] , L_128 ) ;
if ( V_17 == NULL ) {
perror ( V_214 ) ;
F_44 ( V_37 , L_129 , V_214 ) ;
goto V_77;
}
V_209 = F_187 ( V_17 , V_220 -> V_220 ) ;
F_72 ( V_17 ) ;
if ( V_209 <= 0 )
goto V_77;
V_17 = F_56 ( V_2 [ 1 ] , L_128 ) ;
if ( V_17 == NULL ) {
perror ( V_2 [ 2 ] ) ;
F_44 ( V_37 , L_129 , V_2 [ 2 ] ) ;
goto V_77;
}
F_44 ( V_17 , L_130 ,
V_220 -> V_221 . V_222 ? L_131 : L_132 ) ;
F_72 ( V_17 ) ;
return 1 ;
V_77:
return 0 ;
}
int F_188 ( const char * V_214 , const char * V_206 ,
const char * V_207 )
{
char V_2 [ 5 ] [ V_208 ] ;
int V_50 , V_209 ;
V_50 = strlen ( V_214 ) + strlen ( V_207 ) ;
V_209 = strlen ( V_214 ) + strlen ( V_206 ) ;
if ( V_50 > V_209 )
V_209 = V_50 ;
if ( V_209 + 6 >= V_208 ) {
F_44 ( V_37 , L_115 ) ;
goto V_77;
}
#ifndef F_170
V_209 = F_171 ( V_2 [ 4 ] , sizeof V_2 [ 4 ] , L_120 , V_214 ) ;
V_209 = F_171 ( V_2 [ 3 ] , sizeof V_2 [ 3 ] , L_126 , V_214 , V_207 ) ;
V_209 = F_171 ( V_2 [ 2 ] , sizeof V_2 [ 2 ] , L_126 , V_214 , V_206 ) ;
V_209 = F_171 ( V_2 [ 1 ] , sizeof V_2 [ 1 ] , L_116 , V_214 , V_207 ) ;
V_209 = F_171 ( V_2 [ 0 ] , sizeof V_2 [ 0 ] , L_116 , V_214 , V_206 ) ;
#else
V_209 = F_171 ( V_2 [ 4 ] , sizeof V_2 [ 4 ] , L_121 , V_214 ) ;
V_209 = F_171 ( V_2 [ 3 ] , sizeof V_2 [ 3 ] , L_127 , V_214 , V_207 ) ;
V_209 = F_171 ( V_2 [ 2 ] , sizeof V_2 [ 2 ] , L_127 , V_214 , V_206 ) ;
V_209 = F_171 ( V_2 [ 1 ] , sizeof V_2 [ 1 ] , L_117 , V_214 , V_207 ) ;
V_209 = F_171 ( V_2 [ 0 ] , sizeof V_2 [ 0 ] , L_117 , V_214 , V_206 ) ;
#endif
if ( rename ( V_214 , V_2 [ 1 ] ) < 0 && V_210 != V_211
#ifdef F_172
&& V_210 != F_172
#endif
) {
F_44 ( V_37 , L_118 , V_214 , V_2 [ 1 ] ) ;
perror ( L_119 ) ;
goto V_77;
}
if ( rename ( V_2 [ 0 ] , V_214 ) < 0 ) {
F_44 ( V_37 , L_118 , V_2 [ 0 ] , V_214 ) ;
perror ( L_119 ) ;
rename ( V_2 [ 1 ] , V_214 ) ;
goto V_77;
}
if ( rename ( V_2 [ 4 ] , V_2 [ 3 ] ) < 0 && V_210 != V_211
#ifdef F_172
&& V_210 != F_172
#endif
) {
F_44 ( V_37 , L_118 , V_2 [ 4 ] , V_2 [ 3 ] ) ;
perror ( L_119 ) ;
rename ( V_214 , V_2 [ 0 ] ) ;
rename ( V_2 [ 1 ] , V_214 ) ;
goto V_77;
}
if ( rename ( V_2 [ 2 ] , V_2 [ 4 ] ) < 0 ) {
F_44 ( V_37 , L_118 , V_2 [ 2 ] , V_2 [ 4 ] ) ;
perror ( L_119 ) ;
rename ( V_2 [ 3 ] , V_2 [ 4 ] ) ;
rename ( V_214 , V_2 [ 0 ] ) ;
rename ( V_2 [ 1 ] , V_214 ) ;
goto V_77;
}
return 1 ;
V_77:
return 0 ;
}
void F_189 ( T_21 * V_220 )
{
if ( V_220 ) {
F_181 ( V_220 -> V_220 ) ;
F_17 ( V_220 ) ;
}
}
int F_180 ( const char * V_226 , int V_227 )
{
if ( V_226 ) {
switch ( * V_226 ) {
case 'f' :
case 'F' :
case 'n' :
case 'N' :
case '0' :
return 0 ;
case 't' :
case 'T' :
case 'y' :
case 'Y' :
case '1' :
return 1 ;
}
}
return V_227 ;
}
T_15 * F_190 ( const char * V_228 , long V_229 , int V_230 )
{
int V_231 = 0 ;
char * V_232 ;
T_15 * V_199 ;
if ( * V_228 ++ != '/' )
return NULL ;
V_199 = F_191 () ;
if ( V_199 == NULL )
return NULL ;
V_232 = F_55 ( V_228 ) ;
if ( V_232 == NULL )
goto V_77;
while ( * V_228 ) {
char * V_233 = V_232 ;
char * V_234 = V_233 ;
unsigned char * V_235 ;
int V_236 ;
int V_237 = V_231 ;
V_231 = 0 ;
while ( * V_228 && * V_228 != '=' )
* V_233 ++ = * V_228 ++ ;
if ( * V_228 == '\0' ) {
F_44 ( V_37 ,
L_133 ,
F_68 () ) ;
goto V_77;
}
* V_233 ++ = '\0' ;
++ V_228 ;
V_235 = ( unsigned char * ) V_233 ;
for (; * V_228 && * V_228 != '/' ; * V_233 ++ = * V_228 ++ ) {
if ( V_230 && * V_228 == '+' ) {
V_231 = 1 ;
break;
}
if ( * V_228 == '\\' && * ++ V_228 == '\0' ) {
F_44 ( V_37 ,
L_134 ,
F_68 () ) ;
goto V_77;
}
}
* V_233 ++ = '\0' ;
if ( * V_228 )
++ V_228 ;
V_236 = F_192 ( V_234 ) ;
if ( V_236 == V_67 ) {
F_44 ( V_37 , L_135 ,
F_68 () , V_234 ) ;
continue;
}
if ( ! F_193 ( V_199 , V_236 , V_229 ,
V_235 , strlen ( ( char * ) V_235 ) ,
- 1 , V_237 ? - 1 : 0 ) )
goto V_77;
}
F_17 ( V_232 ) ;
return V_199 ;
V_77:
F_194 ( V_199 ) ;
F_17 ( V_232 ) ;
return NULL ;
}
int F_195 ( unsigned char * * V_17 , int V_238 , T_2 * V_55 )
{
T_2 * V_239 ;
int V_186 , V_172 ;
unsigned char V_240 [ 1024 ] ;
V_239 = F_59 ( F_196 () ) ;
if ( V_239 == NULL )
return - 1 ;
for (; ; ) {
if ( ( V_238 != - 1 ) && V_238 < 1024 )
V_186 = V_238 ;
else
V_186 = 1024 ;
V_186 = F_197 ( V_55 , V_240 , V_186 ) ;
if ( V_186 < 0 ) {
F_72 ( V_239 ) ;
return - 1 ;
}
if ( V_186 == 0 )
break;
if ( F_198 ( V_239 , V_240 , V_186 ) != V_186 ) {
F_72 ( V_239 ) ;
return - 1 ;
}
V_238 -= V_186 ;
if ( V_238 == 0 )
break;
}
V_172 = F_199 ( V_239 , ( char * * ) V_17 ) ;
F_200 ( V_239 , V_241 ) ;
F_72 ( V_239 ) ;
return V_172 ;
}
int F_201 ( T_24 * V_11 , const char * V_65 )
{
int V_76 ;
char * V_242 , * V_243 = NULL ;
V_242 = F_55 ( V_65 ) ;
if ( ! V_242 )
return - 1 ;
V_243 = strchr ( V_242 , ':' ) ;
if ( V_243 ) {
* V_243 = 0 ;
V_243 ++ ;
}
V_76 = F_202 ( V_11 , V_242 , V_243 ) ;
F_17 ( V_242 ) ;
return V_76 ;
}
void F_203 ( T_25 * V_11 )
{
T_26 * V_244 ;
int V_245 ;
V_244 = F_204 ( V_11 ) ;
V_245 = F_205 ( V_11 ) ;
F_44 ( V_37 , L_136 ,
V_245 ? L_137 : L_138 ) ;
F_206 ( L_139 , F_207 ( V_244 ) ) ;
F_206 ( L_140 , F_208 ( V_244 ) ) ;
}
unsigned char * F_209 ( T_27 * V_246 , const char * V_55 )
{
T_27 V_186 ;
unsigned char * V_17 ;
T_27 V_50 , V_247 = 0 ;
V_186 = strlen ( V_55 ) ;
if ( V_186 >= 65535 )
return NULL ;
V_17 = F_2 ( strlen ( V_55 ) + 1 , L_141 ) ;
for ( V_50 = 0 ; V_50 <= V_186 ; ++ V_50 ) {
if ( V_50 == V_186 || V_55 [ V_50 ] == ',' ) {
if ( V_50 - V_247 > 255 ) {
F_17 ( V_17 ) ;
return NULL ;
}
V_17 [ V_247 ] = V_50 - V_247 ;
V_247 = V_50 + 1 ;
} else
V_17 [ V_50 + 1 ] = V_55 [ V_50 ] ;
}
* V_246 = V_186 + 1 ;
return V_17 ;
}
void F_210 ( T_2 * V_73 , T_3 * V_18 ,
const char * V_248 ,
const char * V_249 , const char * V_250 )
{
if ( V_18 == NULL )
return;
if ( V_248 ) {
F_44 ( V_73 , L_142 ,
V_248 ,
F_211 ( V_18 , V_248 , 0 , 0 , NULL ) == 1
? L_143 : L_144 ) ;
}
if ( V_249 ) {
F_44 ( V_73 , L_145 ,
V_249 , F_212 ( V_18 , V_249 , 0 , 0 )
? L_143 : L_144 ) ;
}
if ( V_250 ) {
F_44 ( V_73 , L_146 ,
V_250 , F_213 ( V_18 , V_250 , 0 ) ? L_143 : L_144 ) ;
}
}
static const char * F_214 ( T_28 * V_251 )
{
T_29 * V_252 ;
T_30 * V_253 ;
int V_50 , V_254 ;
T_31 * V_255 ;
if ( ! V_251 -> V_256 || V_251 -> V_256 -> type != 0 )
return NULL ;
V_252 = V_251 -> V_256 -> V_66 . V_257 ;
for ( V_50 = 0 ; V_50 < F_215 ( V_252 ) ; V_50 ++ ) {
V_253 = F_216 ( V_252 , V_50 ) ;
V_255 = F_217 ( V_253 , & V_254 ) ;
if ( V_254 == V_258 && F_218 ( V_255 ) > 6 ) {
const char * V_259 = ( const char * ) F_219 ( V_255 ) ;
if ( strncmp ( V_259 , L_147 , 7 ) == 0 )
return V_259 ;
}
}
return NULL ;
}
static int F_220 ( const char * V_260 , const char * V_261 )
{
T_32 * V_262 = NULL , * V_263 ;
T_33 V_77 ;
int V_172 = 0 ;
if ( sizeof( T_32 ) == 1 ) {
V_262 = ( T_32 * ) V_260 ;
V_263 = ( T_32 * ) V_261 ;
} else {
T_27 V_50 , V_264 = strlen ( V_260 ) + 1 , V_265 = strlen ( V_261 ) + 1 ;
V_262 = malloc ( sizeof( * V_262 ) * ( V_264 + V_265 ) ) ;
if ( V_262 == NULL )
goto V_77;
V_263 = V_262 + V_264 ;
# if ! F_57 ( V_266 ) || V_266 >= 101
if ( ! F_221 ( V_267 , 0 , V_260 , V_264 , ( V_268 * ) V_262 , V_264 ) )
# endif
for ( V_50 = 0 ; V_50 < V_264 ; V_50 ++ )
V_262 [ V_50 ] = ( T_32 ) V_260 [ V_50 ] ;
# if ! F_57 ( V_266 ) || V_266 >= 101
if ( ! F_221 ( V_267 , 0 , V_261 , V_265 , ( V_268 * ) V_263 , V_265 ) )
# endif
for ( V_50 = 0 ; V_50 < V_265 ; V_50 ++ )
V_263 [ V_50 ] = ( T_32 ) V_261 [ V_50 ] ;
}
if ( F_222 ( V_262 , V_263 ) )
goto V_33;
V_77 = F_223 () ;
if ( V_77 == V_269 || V_77 == V_270 ) {
if ( F_224 ( V_263 ) && F_222 ( V_262 , V_263 ) )
goto V_33;
V_77 = F_223 () ;
}
if ( V_77 == V_271 || V_77 == V_272 )
V_210 = V_211 ;
else if ( V_77 == V_273 )
V_210 = V_274 ;
else
V_210 = V_275 ;
V_77:
V_172 = - 1 ;
V_33:
if ( V_262 != NULL && V_262 != ( T_32 * ) V_260 )
free ( V_262 ) ;
return V_172 ;
}
double F_225 ( int V_276 , int V_277 )
{
T_34 V_278 ;
double V_172 = 0 ;
static T_35 V_279 ;
static int V_280 = 1 ;
# ifdef F_226
static T_36 V_281 = NULL ;
if ( V_281 == NULL ) {
if ( F_227 () )
V_281 = F_228 ( V_282 , FALSE ,
F_229 () ) ;
if ( V_281 == NULL )
V_281 = ( T_36 ) - 1 ;
}
if ( V_277 && V_281 != ( T_36 ) - 1 ) {
T_34 V_283 ;
F_230 ( V_281 , & V_283 , & V_283 , & V_283 , & V_278 ) ;
} else
# endif
{
T_37 V_284 ;
if ( V_277 && V_280 ) {
F_44 ( V_37 , L_148
L_149 ) ;
V_280 = 0 ;
}
F_231 ( & V_284 ) ;
F_232 ( & V_284 , & V_278 ) ;
}
if ( V_276 == V_285 ) {
V_279 . V_286 . V_287 = V_278 . V_288 ;
V_279 . V_286 . V_289 = V_278 . V_290 ;
} else {
T_35 V_291 ;
V_291 . V_286 . V_287 = V_278 . V_288 ;
V_291 . V_286 . V_289 = V_278 . V_290 ;
V_172 = ( V_292 ) ( V_291 . V_293 - V_279 . V_293 ) * 1e-7 ;
}
return ( V_172 ) ;
}
double F_225 ( int V_276 , int V_277 )
{
double V_172 = 0 ;
# ifdef F_233
static struct V_294 V_279 ;
struct V_294 V_278 ;
# else
static unsigned long V_279 ;
unsigned long V_278 ;
# endif
static int V_280 = 1 ;
if ( V_277 && V_280 ) {
F_44 ( V_37 , L_148
L_149 ) ;
V_280 = 0 ;
}
# ifdef F_233
F_234 ( F_233 , & V_278 ) ;
if ( V_276 == V_285 )
V_279 = V_278 ;
else
V_172 = ( ( V_278 . V_295 + V_278 . V_296 * 1e-9 )
- ( V_279 . V_295 + V_279 . V_296 * 1e-9 ) ) ;
# else
V_278 = F_235 () ;
if ( V_276 == V_285 )
V_279 = V_278 ;
else
V_172 = ( V_278 - V_279 ) / ( double ) F_236 () ;
# endif
return ( V_172 ) ;
}
double F_225 ( int V_276 , int V_277 )
{
static T_38 V_279 ;
double V_172 = 0 ;
T_38 V_278 ;
# ifdef F_237
struct V_297 V_298 ;
V_278 = F_238 ( & V_298 ) ;
if ( V_277 )
V_278 = V_298 . V_299 ;
# else
if ( V_277 )
V_278 = clock () ;
else {
struct V_300 V_301 ;
F_239 ( & V_301 , NULL ) ;
V_278 = ( T_38 ) ( ( unsigned long long ) V_301 . V_295 * V_302 +
( unsigned long long ) V_301 . V_303 * ( 1000000 / V_302 )
) ;
}
# endif
if ( V_276 == V_285 )
V_279 = V_278 ;
else
V_172 = ( V_278 - V_279 ) / ( double ) ( V_302 ) ;
return ( V_172 ) ;
}
double F_225 ( int V_276 , int V_277 )
{
double V_172 = 0 ;
struct V_297 V_298 ;
T_38 V_278 = F_238 ( & V_298 ) ;
static T_38 V_279 ;
if ( V_277 )
V_278 = V_298 . V_299 ;
if ( V_276 == V_285 )
V_279 = V_278 ;
else {
long int V_304 = F_240 ( V_305 ) ;
V_172 = ( V_278 - V_279 ) / ( double ) V_304 ;
}
return ( V_172 ) ;
}
double F_225 ( int V_276 , int V_277 )
{
double V_172 = 0 ;
struct V_306 V_298 ;
struct V_300 V_278 ;
static struct V_300 V_279 ;
if ( V_277 )
F_241 ( V_307 , & V_298 ) , V_278 = V_298 . V_308 ;
else
F_239 ( & V_278 , NULL ) ;
if ( V_276 == V_285 )
V_279 = V_278 ;
else
V_172 = ( ( V_278 . V_295 + V_278 . V_303 * 1e-6 )
- ( V_279 . V_295 + V_279 . V_303 * 1e-6 ) ) ;
return V_172 ;
}
int F_242 ( const char * V_66 , int V_179 )
{
#ifdef V_51
return F_243 ( V_66 , V_179 ) ;
#else
return F_244 ( V_66 , V_179 ) ;
#endif
}
int F_245 ( const char * V_66 )
{
T_36 V_309 ;
T_39 V_310 ;
# if F_57 ( V_311 ) || F_57 ( V_312 )
T_27 V_50 , V_313 = strlen ( V_66 ) + 1 ;
if ( V_313 > F_246 ( V_310 . V_314 ) )
return - 1 ;
# if ! F_57 ( V_266 ) || V_266 >= 101
if ( ! F_221
( V_267 , 0 , V_66 , V_313 , V_310 . V_314 , V_313 ) )
# endif
for ( V_50 = 0 ; V_50 < V_313 ; V_50 ++ )
V_310 . V_314 [ V_50 ] = ( V_268 ) V_66 [ V_50 ] ;
V_309 = F_247 ( V_310 . V_314 , & V_310 ) ;
# else
V_309 = F_247 ( V_66 , & V_310 ) ;
# endif
if ( V_309 == V_315 )
return - 1 ;
F_248 ( V_309 ) ;
return ( ( V_310 . V_316 & V_317 ) != 0 ) ;
}
int F_245 ( const char * V_66 )
{
# if F_57 ( V_318 )
struct V_319 V_320 ;
if ( V_319 ( V_66 , & V_320 ) == 0 )
return V_318 ( V_320 . V_321 ) ;
else
return - 1 ;
# else
return - 1 ;
# endif
}
int F_249 ( void * V_2 , int V_322 )
{
T_33 V_199 ;
if ( F_250 ( F_251 ( V_323 ) , V_2 , V_322 , & V_199 , NULL ) )
return ( V_199 ) ;
else
return ( - 1 ) ;
}
int F_249 ( void * V_2 , int V_322 )
{
return F_252 ( fileno ( V_85 ) , V_2 , V_322 ) ;
}
int F_253 ( const void * V_2 , int V_322 )
{
T_33 V_199 ;
if ( F_254 ( F_251 ( V_324 ) , V_2 , V_322 , & V_199 , NULL ) )
return ( V_199 ) ;
else
return ( - 1 ) ;
}
int F_253 ( const void * V_2 , int V_322 )
{
return F_255 ( fileno ( stdout ) , V_2 , V_322 ) ;
}
static int F_256 ( int V_79 )
{
return ( V_79 & V_325 ) == V_325 ;
}
T_2 * F_62 ( int V_79 )
{
return F_257 ( V_85 ,
V_53 | ( F_256 ( V_79 ) ? V_326 : 0 ) ) ;
}
T_2 * F_258 ( int V_79 )
{
T_2 * V_201 = F_257 ( stdout ,
V_53 | ( F_256 ( V_79 ) ? V_326 : 0 ) ) ;
#ifdef F_170
if ( F_256 ( V_79 ) )
V_201 = F_61 ( F_59 ( F_259 () ) , V_201 ) ;
#endif
return V_201 ;
}
T_2 * F_260 ( int V_79 )
{
T_2 * V_201 = F_257 ( V_327 ,
V_53 | ( F_256 ( V_79 ) ? V_326 : 0 ) ) ;
#ifdef F_170
if ( F_256 ( V_79 ) )
V_201 = F_61 ( F_59 ( F_259 () ) , V_201 ) ;
#endif
return V_201 ;
}
void F_96 ( T_40 * V_328 )
{
#if F_57 ( F_170 ) && F_57 ( V_329 )
# pragma V_330 V_331
# pragma V_332 V_333 V_334
#endif
setbuf ( V_328 , NULL ) ;
#if F_57 ( F_170 ) && F_57 ( V_329 )
# pragma V_330 V_335
#endif
}
static const char * F_261 ( char V_336 , int V_79 )
{
F_262 ( V_336 == 'a' || V_336 == 'r' || V_336 == 'w' ) ;
switch ( V_336 ) {
case 'a' :
return F_256 ( V_79 ) ? L_150 : L_151 ;
case 'r' :
return F_256 ( V_79 ) ? L_15 : L_152 ;
case 'w' :
return F_256 ( V_79 ) ? L_128 : L_153 ;
}
return NULL ;
}
static const char * F_263 ( char V_336 )
{
switch ( V_336 ) {
case 'a' :
return L_154 ;
case 'r' :
return L_155 ;
case 'w' :
return L_156 ;
}
return L_157 ;
}
T_2 * F_264 ( const char * V_56 , int V_79 , int V_337 )
{
T_40 * V_328 = NULL ;
T_2 * V_201 = NULL ;
int V_338 = - 1 , V_339 , V_336 , V_340 ;
if ( ! V_337 || V_56 == NULL || strcmp ( V_56 , L_158 ) == 0 )
return F_71 ( V_56 , 'w' , V_79 ) ;
V_336 = V_341 ;
#ifdef F_265
V_336 |= F_265 ;
#endif
#ifdef F_266
V_336 |= F_266 ;
#endif
V_340 = F_256 ( V_79 ) ;
if ( ! V_340 ) {
#ifdef F_267
V_336 |= F_267 ;
#elif F_57 ( V_342 )
V_336 |= V_342 ;
#endif
}
#ifdef F_170
if ( ! V_340 )
V_338 = F_268 ( V_56 , V_336 , 0600 , L_159 ) ;
else
#endif
V_338 = F_268 ( V_56 , V_336 , 0600 ) ;
if ( V_338 < 0 )
goto V_77;
V_328 = fdopen ( V_338 , F_261 ( 'w' , V_79 ) ) ;
if ( V_328 == NULL )
goto V_77;
V_339 = V_343 ;
if ( V_340 )
V_339 |= V_326 ;
V_201 = F_257 ( V_328 , V_339 ) ;
if ( V_201 )
return V_201 ;
V_77:
F_44 ( V_37 , L_160 ,
F_68 () , V_56 , strerror ( V_210 ) ) ;
F_51 ( V_37 ) ;
if ( V_328 )
fclose ( V_328 ) ;
else if ( V_338 >= 0 )
F_269 ( V_338 ) ;
return NULL ;
}
static T_2 * F_270 ( const char * V_56 , char V_336 , int V_79 ,
int V_344 )
{
T_2 * V_172 ;
if ( V_56 == NULL || strcmp ( V_56 , L_158 ) == 0 ) {
V_172 = V_336 == 'r' ? F_62 ( V_79 ) : F_258 ( V_79 ) ;
if ( V_344 ) {
F_80 () ;
return V_172 ;
}
if ( V_172 != NULL )
return V_172 ;
F_44 ( V_37 ,
L_161 ,
V_336 == 'r' ? L_19 : L_162 , strerror ( V_210 ) ) ;
} else {
V_172 = F_56 ( V_56 , F_261 ( V_336 , V_79 ) ) ;
if ( V_344 ) {
F_80 () ;
return V_172 ;
}
if ( V_172 != NULL )
return V_172 ;
F_44 ( V_37 ,
L_163 ,
V_56 , F_263 ( V_336 ) , strerror ( V_210 ) ) ;
}
F_51 ( V_37 ) ;
return NULL ;
}
T_2 * F_71 ( const char * V_56 , char V_336 , int V_79 )
{
return F_270 ( V_56 , V_336 , V_79 , 0 ) ;
}
T_2 * F_74 ( const char * V_56 , char V_336 , int V_79 )
{
return F_270 ( V_56 , V_336 , V_79 , 1 ) ;
}
void F_271 ( T_41 * V_345 )
{
#ifndef F_272
int V_346 = 0 ;
T_42 V_347 ;
T_43 * V_348 ;
T_27 V_349 ;
if ( ! F_273 ( V_345 , NULL , & V_349 ) )
return;
if ( V_349 == 0 )
return;
V_348 = F_2 ( sizeof( T_43 ) * V_349 , L_164 ) ;
if ( ! F_273 ( V_345 , V_348 , & V_349 ) ) {
F_17 ( V_348 ) ;
}
F_274 ( & V_347 ) ;
while ( V_349 > 0 ) {
if ( V_346 <= ( int ) * V_348 )
V_346 = ( int ) * V_348 + 1 ;
F_275 ( ( int ) * V_348 , & V_347 ) ;
V_349 -- ;
V_348 ++ ;
}
F_276 ( V_346 , ( void * ) & V_347 , NULL , NULL , NULL ) ;
#endif
}
int F_277 ( void )
{
# if F_57 ( F_272 )
T_36 V_350 = F_251 ( V_323 ) ;
T_33 V_351 = 0 ;
T_44 V_352 ;
T_33 V_353 = 1 ;
BOOL V_354 ;
if ( V_350 == V_315 ) {
return 0 ;
}
V_354 = F_278 ( V_350 , & V_352 , V_353 , & V_351 ) ;
if ( ! V_354 ) {
if ( ! feof ( V_85 ) ) {
return 1 ;
}
return 0 ;
}
# endif
return F_279 () ;
}
void F_280 ( const T_31 * V_355 )
{
unsigned char * V_345 = V_355 -> V_356 ;
V_345 [ V_355 -> V_357 - 1 ] ^= 0x1 ;
}
int F_281 ( T_3 * V_18 , const char * V_358 , const char * V_359 ,
int V_360 )
{
if ( V_358 == NULL || strcmp ( V_358 , L_165 ) == 0 ) {
if ( F_282 ( F_283 ( V_18 ) , 0 ) == NULL )
return 0 ;
} else {
if ( ! F_284 ( F_283 ( V_18 ) , V_358 ) )
return 0 ;
}
if ( V_359 == NULL ) {
if ( F_285 ( F_286 ( V_18 ) , V_360 , 0 , NULL )
== NULL )
return 0 ;
} else if ( ! F_284 ( F_286 ( V_18 ) , V_359 ) ) {
return 0 ;
}
return 1 ;
}
