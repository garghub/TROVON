void F_1 ( T_1 * V_1 )
{
if ( ! V_1 )
return;
F_2 ( V_1 -> V_2 ) ;
F_2 ( V_1 -> V_3 ) ;
F_2 ( V_1 -> V_4 ) ;
F_2 ( V_1 ) ;
}
char * F_3 ( T_2 * V_5 , const T_3 * V_6 )
{
T_4 * V_7 = NULL ;
char * V_8 = NULL ;
if ( ! V_6 )
return NULL ;
if ( ( V_7 = F_4 ( V_6 , NULL ) ) == NULL
|| ( V_8 = F_5 ( V_7 ) ) == NULL )
F_6 ( V_9 , V_10 ) ;
F_7 ( V_7 ) ;
return V_8 ;
}
char * F_8 ( T_2 * V_5 , const T_5 * V_6 )
{
T_4 * V_7 = NULL ;
char * V_8 = NULL ;
if ( ! V_6 )
return NULL ;
if ( ( V_7 = F_9 ( V_6 , NULL ) ) == NULL
|| ( V_8 = F_5 ( V_7 ) ) == NULL )
F_6 ( V_11 , V_10 ) ;
F_7 ( V_7 ) ;
return V_8 ;
}
T_5 * F_10 ( T_2 * V_5 , const char * V_3 )
{
T_4 * V_12 = NULL ;
T_5 * V_13 ;
int V_14 , V_15 ;
int V_16 ;
if ( V_3 == NULL ) {
F_6 ( V_17 , V_18 ) ;
return NULL ;
}
V_12 = F_11 () ;
if ( V_12 == NULL ) {
F_6 ( V_17 , V_10 ) ;
return NULL ;
}
if ( V_3 [ 0 ] == '-' ) {
V_3 ++ ;
V_14 = 1 ;
} else
V_14 = 0 ;
if ( V_3 [ 0 ] == '0' && ( ( V_3 [ 1 ] == 'x' ) || ( V_3 [ 1 ] == 'X' ) ) ) {
V_3 += 2 ;
V_15 = 1 ;
} else
V_15 = 0 ;
if ( V_15 )
V_16 = F_12 ( & V_12 , V_3 ) ;
else
V_16 = F_13 ( & V_12 , V_3 ) ;
if ( ! V_16 || V_3 [ V_16 ] ) {
F_7 ( V_12 ) ;
F_6 ( V_17 , V_19 ) ;
return NULL ;
}
if ( V_14 && F_14 ( V_12 ) )
V_14 = 0 ;
V_13 = F_15 ( V_12 , NULL ) ;
F_7 ( V_12 ) ;
if ( ! V_13 ) {
F_6 ( V_17 ,
V_20 ) ;
return NULL ;
}
if ( V_14 )
V_13 -> type |= V_21 ;
return V_13 ;
}
int F_16 ( const T_1 * V_3 , int * V_22 )
{
const char * V_23 ;
if ( ( V_23 = V_3 -> V_3 ) == NULL )
goto V_24;
if ( strcmp ( V_23 , L_1 ) == 0
|| strcmp ( V_23 , L_2 ) == 0
|| strcmp ( V_23 , L_3 ) == 0
|| strcmp ( V_23 , L_4 ) == 0
|| strcmp ( V_23 , L_5 ) == 0
|| strcmp ( V_23 , L_6 ) == 0 ) {
* V_22 = 0xff ;
return 1 ;
}
if ( strcmp ( V_23 , L_7 ) == 0
|| strcmp ( V_23 , L_8 ) == 0
|| strcmp ( V_23 , L_9 ) == 0
|| strcmp ( V_23 , L_10 ) == 0
|| strcmp ( V_23 , L_11 ) == 0
|| strcmp ( V_23 , L_12 ) == 0 ) {
* V_22 = 0 ;
return 1 ;
}
V_24:
F_6 ( V_25 ,
V_26 ) ;
F_17 ( V_3 ) ;
return 0 ;
}
int F_18 ( const T_1 * V_3 , T_5 * * V_13 )
{
T_5 * V_27 ;
if ( ( V_27 = F_10 ( NULL , V_3 -> V_3 ) ) == NULL ) {
F_17 ( V_3 ) ;
return 0 ;
}
* V_13 = V_27 ;
return 1 ;
}
char * F_19 ( char * V_2 )
{
char * V_28 , * V_29 ;
V_28 = V_2 ;
while ( * V_28 && isspace ( ( unsigned char ) * V_28 ) )
V_28 ++ ;
if ( ! * V_28 )
return NULL ;
V_29 = V_28 + strlen ( V_28 ) - 1 ;
while ( ( V_29 != V_28 ) && isspace ( ( unsigned char ) * V_29 ) )
V_29 -- ;
if ( V_28 != V_29 )
V_29 [ 1 ] = 0 ;
if ( ! * V_28 )
return NULL ;
return V_28 ;
}
int F_20 ( const char * V_2 , const char * V_30 )
{
int V_31 , V_16 ;
char V_32 ;
V_31 = strlen ( V_30 ) ;
if ( ( V_16 = strncmp ( V_2 , V_30 , V_31 ) ) )
return V_16 ;
V_32 = V_2 [ V_31 ] ;
if ( ! V_32 || ( V_32 == '.' ) )
return 0 ;
return 1 ;
}
static int F_21 ( const char * const * V_6 , const char * const * V_33 )
{
return strcmp ( * V_6 , * V_33 ) ;
}
void F_22 ( T_6 V_34 )
{
F_2 ( V_34 ) ;
}
static void F_23 ( const unsigned char * * V_28 , T_7 * V_35 ,
T_7 V_36 ,
unsigned int V_37 )
{
const unsigned char * V_38 = * V_28 ;
T_7 V_39 = * V_35 ;
if ( ( V_37 & V_40 ) == 0 )
return;
while ( V_39 > V_36 && * V_38 ) {
if ( ( V_37 & V_41 ) &&
* V_38 == '.' )
break;
++ V_38 ;
-- V_39 ;
}
if ( V_39 == V_36 ) {
* V_28 = V_38 ;
* V_35 = V_39 ;
}
}
static int F_24 ( const unsigned char * V_38 , T_7 V_39 ,
const unsigned char * V_42 , T_7 V_36 ,
unsigned int V_37 )
{
F_23 ( & V_38 , & V_39 , V_36 , V_37 ) ;
if ( V_39 != V_36 )
return 0 ;
while ( V_39 ) {
unsigned char V_43 = * V_38 ;
unsigned char V_44 = * V_42 ;
if ( V_43 == 0 )
return 0 ;
if ( V_43 != V_44 ) {
if ( 'A' <= V_43 && V_43 <= 'Z' )
V_43 = ( V_43 - 'A' ) + 'a' ;
if ( 'A' <= V_44 && V_44 <= 'Z' )
V_44 = ( V_44 - 'A' ) + 'a' ;
if ( V_43 != V_44 )
return 0 ;
}
++ V_38 ;
++ V_42 ;
-- V_39 ;
}
return 1 ;
}
static int F_25 ( const unsigned char * V_38 , T_7 V_39 ,
const unsigned char * V_42 , T_7 V_36 ,
unsigned int V_37 )
{
F_23 ( & V_38 , & V_39 , V_36 , V_37 ) ;
if ( V_39 != V_36 )
return 0 ;
return ! memcmp ( V_38 , V_42 , V_39 ) ;
}
static int F_26 ( const unsigned char * V_6 , T_7 V_45 ,
const unsigned char * V_33 , T_7 V_46 ,
unsigned int V_47 )
{
T_7 V_48 = V_45 ;
if ( V_45 != V_46 )
return 0 ;
while ( V_48 > 0 ) {
-- V_48 ;
if ( V_6 [ V_48 ] == '@' || V_33 [ V_48 ] == '@' ) {
if ( ! F_24 ( V_6 + V_48 , V_45 - V_48 , V_33 + V_48 , V_45 - V_48 , 0 ) )
return 0 ;
break;
}
}
if ( V_48 == 0 )
V_48 = V_45 ;
return F_25 ( V_6 , V_48 , V_33 , V_48 , 0 ) ;
}
static int F_27 ( const unsigned char * V_49 , T_7 V_50 ,
const unsigned char * V_51 , T_7 V_52 ,
const unsigned char * V_42 , T_7 V_36 ,
unsigned int V_37 )
{
const unsigned char * V_53 ;
const unsigned char * V_54 ;
const unsigned char * V_28 ;
int V_55 = 0 ;
int V_56 = 0 ;
if ( V_36 < V_50 + V_52 )
return 0 ;
if ( ! F_24 ( V_49 , V_50 , V_42 , V_50 , V_37 ) )
return 0 ;
V_53 = V_42 + V_50 ;
V_54 = V_42 + ( V_36 - V_52 ) ;
if ( ! F_24 ( V_54 , V_52 , V_51 , V_52 , V_37 ) )
return 0 ;
if ( V_50 == 0 && * V_51 == '.' ) {
if ( V_53 == V_54 )
return 0 ;
V_56 = 1 ;
if ( V_37 & V_57 )
V_55 = 1 ;
}
if ( ! V_56 &&
V_36 >= 4 && strncasecmp ( ( char * ) V_42 , L_13 , 4 ) == 0 )
return 0 ;
if ( V_54 == V_53 + 1 && * V_53 == '*' )
return 1 ;
for ( V_28 = V_53 ; V_28 != V_54 ; ++ V_28 )
if ( ! ( ( '0' <= * V_28 && * V_28 <= '9' ) ||
( 'A' <= * V_28 && * V_28 <= 'Z' ) ||
( 'a' <= * V_28 && * V_28 <= 'z' ) ||
* V_28 == '-' || ( V_55 && * V_28 == '.' ) ) )
return 0 ;
return 1 ;
}
static const unsigned char * F_28 ( const unsigned char * V_28 , T_7 V_31 ,
unsigned int V_37 )
{
const unsigned char * V_58 = 0 ;
T_7 V_48 ;
int V_59 = V_60 ;
int V_61 = 0 ;
for ( V_48 = 0 ; V_48 < V_31 ; ++ V_48 ) {
if ( V_28 [ V_48 ] == '*' ) {
int V_62 = ( V_59 & V_60 ) ;
int V_63 = ( V_48 == V_31 - 1 || V_28 [ V_48 + 1 ] == '.' ) ;
if ( V_58 != NULL || ( V_59 & V_64 ) != 0 || V_61 )
return NULL ;
if ( ( V_37 & V_65 )
&& ( ! V_62 || ! V_63 ) )
return NULL ;
if ( ! V_62 && ! V_63 )
return NULL ;
V_58 = & V_28 [ V_48 ] ;
V_59 &= ~ V_60 ;
} else if ( ( 'a' <= V_28 [ V_48 ] && V_28 [ V_48 ] <= 'z' )
|| ( 'A' <= V_28 [ V_48 ] && V_28 [ V_48 ] <= 'Z' )
|| ( '0' <= V_28 [ V_48 ] && V_28 [ V_48 ] <= '9' ) ) {
if ( ( V_59 & V_60 ) != 0
&& V_31 - V_48 >= 4 && strncasecmp ( ( char * ) & V_28 [ V_48 ] , L_13 , 4 ) == 0 )
V_59 |= V_64 ;
V_59 &= ~ ( V_66 | V_60 ) ;
} else if ( V_28 [ V_48 ] == '.' ) {
if ( ( V_59 & ( V_66 | V_60 ) ) != 0 )
return NULL ;
V_59 = V_60 ;
++ V_61 ;
} else if ( V_28 [ V_48 ] == '-' ) {
if ( ( V_59 & V_60 ) != 0 )
return NULL ;
V_59 |= V_66 ;
} else
return NULL ;
}
if ( ( V_59 & ( V_60 | V_66 ) ) != 0 || V_61 < 2 )
return NULL ;
return V_58 ;
}
static int F_29 ( const unsigned char * V_38 , T_7 V_39 ,
const unsigned char * V_42 , T_7 V_36 ,
unsigned int V_37 )
{
const unsigned char * V_58 = NULL ;
if ( ! ( V_36 > 1 && V_42 [ 0 ] == '.' ) )
V_58 = F_28 ( V_38 , V_39 , V_37 ) ;
if ( V_58 == NULL )
return F_24 ( V_38 , V_39 ,
V_42 , V_36 , V_37 ) ;
return F_27 ( V_38 , V_58 - V_38 ,
V_58 + 1 , ( V_38 + V_39 ) - V_58 - 1 ,
V_42 , V_36 , V_37 ) ;
}
static int F_30 ( const T_8 * V_6 , int V_67 , T_9 V_68 ,
unsigned int V_37 , const char * V_33 , T_7 V_69 ,
char * * V_70 )
{
int V_71 = 0 ;
if ( ! V_6 -> V_72 || ! V_6 -> V_73 )
return 0 ;
if ( V_67 > 0 ) {
if ( V_67 != V_6 -> type )
return 0 ;
if ( V_67 == V_74 )
V_71 = V_68 ( V_6 -> V_72 , V_6 -> V_73 , ( unsigned char * ) V_33 , V_69 , V_37 ) ;
else if ( V_6 -> V_73 == ( int ) V_69 && ! memcmp ( V_6 -> V_72 , V_33 , V_69 ) )
V_71 = 1 ;
if ( V_71 > 0 && V_70 )
* V_70 = F_31 ( ( char * ) V_6 -> V_72 , V_6 -> V_73 ) ;
} else {
int V_75 ;
unsigned char * V_76 ;
V_75 = F_32 ( & V_76 , V_6 ) ;
if ( V_75 < 0 ) {
return - 1 ;
}
V_71 = V_68 ( V_76 , V_75 , ( unsigned char * ) V_33 , V_69 , V_37 ) ;
if ( V_71 > 0 && V_70 )
* V_70 = F_31 ( ( char * ) V_76 , V_75 ) ;
F_2 ( V_76 ) ;
}
return V_71 ;
}
static int F_33 ( T_10 * V_77 , const char * V_78 , T_7 V_79 ,
unsigned int V_37 , int V_80 , char * * V_70 )
{
T_11 * V_81 = NULL ;
T_12 * V_2 = NULL ;
int V_48 ;
int V_82 = V_83 ;
int V_84 ;
int V_85 = 0 ;
int V_71 = 0 ;
T_9 V_68 ;
V_37 &= ~ V_40 ;
if ( V_80 == V_86 ) {
V_82 = V_87 ;
V_84 = V_74 ;
V_68 = F_26 ;
} else if ( V_80 == V_88 ) {
V_82 = V_89 ;
if ( V_79 > 1 && V_78 [ 0 ] == '.' )
V_37 |= V_40 ;
V_84 = V_74 ;
if ( V_37 & V_90 )
V_68 = F_24 ;
else
V_68 = F_29 ;
} else {
V_84 = V_91 ;
V_68 = F_25 ;
}
if ( V_79 == 0 )
V_79 = strlen ( V_78 ) ;
V_81 = F_34 ( V_77 , V_92 , NULL , NULL ) ;
if ( V_81 ) {
for ( V_48 = 0 ; V_48 < F_35 ( V_81 ) ; V_48 ++ ) {
T_13 * V_93 ;
T_8 * V_94 ;
V_93 = F_36 ( V_81 , V_48 ) ;
if ( V_93 -> type != V_80 )
continue;
V_85 = 1 ;
if ( V_80 == V_86 )
V_94 = V_93 -> V_95 . V_96 ;
else if ( V_80 == V_88 )
V_94 = V_93 -> V_95 . V_97 ;
else
V_94 = V_93 -> V_95 . V_98 ;
if ( ( V_71 = F_30 ( V_94 , V_84 , V_68 , V_37 ,
V_78 , V_79 , V_70 ) ) != 0 )
break;
}
F_37 ( V_81 ) ;
if ( V_71 != 0 )
return V_71 ;
if ( V_85 && ! ( V_37 & V_99 ) )
return 0 ;
}
if ( V_82 == V_83 || ( V_37 & V_100 ) )
return 0 ;
V_48 = - 1 ;
V_2 = F_38 ( V_77 ) ;
while ( ( V_48 = F_39 ( V_2 , V_82 , V_48 ) ) >= 0 ) {
const T_14 * V_101 = F_40 ( V_2 , V_48 ) ;
const T_8 * V_34 = F_41 ( V_101 ) ;
if ( ( V_71 = F_30 ( V_34 , - 1 , V_68 , V_37 ,
V_78 , V_79 , V_70 ) ) != 0 )
return V_71 ;
}
return 0 ;
}
int F_42 ( T_10 * V_77 , const char * V_78 , T_7 V_79 ,
unsigned int V_37 , char * * V_70 )
{
if ( V_78 == NULL )
return - 2 ;
if ( V_79 == 0 )
V_79 = strlen ( V_78 ) ;
else if ( memchr ( V_78 , '\0' , V_79 > 1 ? V_79 - 1 : V_79 ) )
return - 2 ;
if ( V_79 > 1 && V_78 [ V_79 - 1 ] == '\0' )
-- V_79 ;
return F_33 ( V_77 , V_78 , V_79 , V_37 , V_88 , V_70 ) ;
}
int F_43 ( T_10 * V_77 , const char * V_78 , T_7 V_79 ,
unsigned int V_37 )
{
if ( V_78 == NULL )
return - 2 ;
if ( V_79 == 0 )
V_79 = strlen ( ( char * ) V_78 ) ;
else if ( memchr ( V_78 , '\0' , V_79 > 1 ? V_79 - 1 : V_79 ) )
return - 2 ;
if ( V_79 > 1 && V_78 [ V_79 - 1 ] == '\0' )
-- V_79 ;
return F_33 ( V_77 , V_78 , V_79 , V_37 , V_86 , NULL ) ;
}
int F_44 ( T_10 * V_77 , const unsigned char * V_78 , T_7 V_79 ,
unsigned int V_37 )
{
if ( V_78 == NULL )
return - 2 ;
return F_33 ( V_77 , ( char * ) V_78 , V_79 , V_37 , V_102 , NULL ) ;
}
int F_45 ( T_10 * V_77 , const char * V_103 , unsigned int V_37 )
{
unsigned char V_104 [ 16 ] ;
T_7 V_105 ;
if ( V_103 == NULL )
return - 2 ;
V_105 = ( T_7 ) F_46 ( V_104 , V_103 ) ;
if ( V_105 == 0 )
return - 2 ;
return F_33 ( V_77 , ( char * ) V_104 , V_105 , V_37 , V_102 , NULL ) ;
}
T_15 * F_47 ( const char * V_103 )
{
unsigned char V_104 [ 16 ] ;
T_15 * V_16 ;
int V_105 ;
V_105 = F_46 ( V_104 , V_103 ) ;
if ( ! V_105 )
return NULL ;
V_16 = F_48 () ;
if ( V_16 == NULL )
return NULL ;
if ( ! F_49 ( V_16 , V_104 , V_105 ) ) {
F_50 ( V_16 ) ;
return NULL ;
}
return V_16 ;
}
T_15 * F_51 ( const char * V_103 )
{
T_15 * V_16 = NULL ;
unsigned char V_104 [ 32 ] ;
char * V_106 = NULL , * V_28 ;
int V_107 , V_108 ;
V_28 = strchr ( V_103 , '/' ) ;
if ( ! V_28 )
return NULL ;
V_106 = F_52 ( V_103 ) ;
if ( ! V_106 )
return NULL ;
V_28 = V_106 + ( V_28 - V_103 ) ;
* V_28 ++ = 0 ;
V_107 = F_46 ( V_104 , V_106 ) ;
if ( ! V_107 )
goto V_24;
V_108 = F_46 ( V_104 + V_107 , V_28 ) ;
F_2 ( V_106 ) ;
V_106 = NULL ;
if ( ! V_108 || ( V_107 != V_108 ) )
goto V_24;
V_16 = F_48 () ;
if ( V_16 == NULL )
goto V_24;
if ( ! F_49 ( V_16 , V_104 , V_107 + V_108 ) )
goto V_24;
return V_16 ;
V_24:
F_2 ( V_106 ) ;
F_50 ( V_16 ) ;
return NULL ;
}
int F_46 ( unsigned char * V_104 , const char * V_103 )
{
if ( strchr ( V_103 , ':' ) ) {
if ( ! F_53 ( V_104 , V_103 ) )
return 0 ;
return 16 ;
} else {
if ( ! F_54 ( V_104 , V_103 ) )
return 0 ;
return 4 ;
}
}
static int F_54 ( unsigned char * V_109 , const char * V_110 )
{
int V_111 , V_112 , V_113 , V_114 ;
if ( sscanf ( V_110 , L_14 , & V_111 , & V_112 , & V_113 , & V_114 ) != 4 )
return 0 ;
if ( ( V_111 < 0 ) || ( V_111 > 255 ) || ( V_112 < 0 ) || ( V_112 > 255 )
|| ( V_113 < 0 ) || ( V_113 > 255 ) || ( V_114 < 0 ) || ( V_114 > 255 ) )
return 0 ;
V_109 [ 0 ] = V_111 ;
V_109 [ 1 ] = V_112 ;
V_109 [ 2 ] = V_113 ;
V_109 [ 3 ] = V_114 ;
return 1 ;
}
static int F_53 ( unsigned char * V_115 , const char * V_110 )
{
T_16 V_116 ;
V_116 . V_117 = 0 ;
V_116 . V_118 = - 1 ;
V_116 . V_119 = 0 ;
if ( ! F_55 ( V_110 , ':' , 0 , V_120 , & V_116 ) )
return 0 ;
if ( V_116 . V_118 == - 1 ) {
if ( V_116 . V_117 != 16 )
return 0 ;
} else {
if ( V_116 . V_117 == 16 )
return 0 ;
if ( V_116 . V_119 > 3 )
return 0 ;
else if ( V_116 . V_119 == 3 ) {
if ( V_116 . V_117 > 0 )
return 0 ;
}
else if ( V_116 . V_119 == 2 ) {
if ( ( V_116 . V_118 != 0 )
&& ( V_116 . V_118 != V_116 . V_117 ) )
return 0 ;
} else
{
if ( ( V_116 . V_118 == 0 )
|| ( V_116 . V_118 == V_116 . V_117 ) )
return 0 ;
}
}
if ( V_116 . V_118 >= 0 ) {
memcpy ( V_115 , V_116 . V_121 , V_116 . V_118 ) ;
memset ( V_115 + V_116 . V_118 , 0 , 16 - V_116 . V_117 ) ;
if ( V_116 . V_117 != V_116 . V_118 )
memcpy ( V_115 + V_116 . V_118 + 16 - V_116 . V_117 ,
V_116 . V_121 + V_116 . V_118 ,
V_116 . V_117 - V_116 . V_118 ) ;
} else
memcpy ( V_115 , V_116 . V_121 , 16 ) ;
return 1 ;
}
static int V_120 ( const char * V_122 , int V_31 , void * V_123 )
{
T_16 * V_124 = V_123 ;
if ( V_124 -> V_117 == 16 )
return 0 ;
if ( V_31 == 0 ) {
if ( V_124 -> V_118 == - 1 )
V_124 -> V_118 = V_124 -> V_117 ;
else if ( V_124 -> V_118 != V_124 -> V_117 )
return 0 ;
V_124 -> V_119 ++ ;
} else {
if ( V_31 > 4 ) {
if ( V_124 -> V_117 > 12 )
return 0 ;
if ( V_122 [ V_31 ] )
return 0 ;
if ( ! F_54 ( V_124 -> V_121 + V_124 -> V_117 , V_122 ) )
return 0 ;
V_124 -> V_117 += 4 ;
} else {
if ( ! F_56 ( V_124 -> V_121 + V_124 -> V_117 , V_122 , V_31 ) )
return 0 ;
V_124 -> V_117 += 2 ;
}
}
return 1 ;
}
static int F_56 ( unsigned char * V_125 , const char * V_110 , int V_126 )
{
unsigned char V_32 ;
unsigned int V_127 = 0 ;
int V_77 ;
if ( V_126 > 4 )
return 0 ;
while ( V_126 -- ) {
V_32 = * V_110 ++ ;
V_127 <<= 4 ;
V_77 = F_57 ( V_32 ) ;
if ( V_77 < 0 )
return 0 ;
V_127 |= ( char ) V_77 ;
}
V_125 [ 0 ] = V_127 >> 8 ;
V_125 [ 1 ] = V_127 & 0xff ;
return 1 ;
}
