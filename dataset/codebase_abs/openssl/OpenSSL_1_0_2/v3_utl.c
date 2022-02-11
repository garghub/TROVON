void F_1 ( T_1 * V_1 )
{
if ( ! V_1 )
return;
if ( V_1 -> V_2 )
F_2 ( V_1 -> V_2 ) ;
if ( V_1 -> V_3 )
F_2 ( V_1 -> V_3 ) ;
if ( V_1 -> V_4 )
F_2 ( V_1 -> V_4 ) ;
F_2 ( V_1 ) ;
}
char * F_3 ( T_2 * V_5 , T_3 * V_6 )
{
T_4 * V_7 = NULL ;
char * V_8 = NULL ;
if ( ! V_6 )
return NULL ;
if ( ! ( V_7 = F_4 ( V_6 , NULL ) ) ||
! ( V_8 = F_5 ( V_7 ) ) )
F_6 ( V_9 , V_10 ) ;
F_7 ( V_7 ) ;
return V_8 ;
}
char * F_8 ( T_2 * V_5 , T_5 * V_6 )
{
T_4 * V_7 = NULL ;
char * V_8 = NULL ;
if ( ! V_6 )
return NULL ;
if ( ! ( V_7 = F_9 ( V_6 , NULL ) ) ||
! ( V_8 = F_5 ( V_7 ) ) )
F_6 ( V_11 , V_10 ) ;
F_7 ( V_7 ) ;
return V_8 ;
}
T_5 * F_10 ( T_2 * V_5 , char * V_3 )
{
T_4 * V_12 = NULL ;
T_5 * V_13 ;
int V_14 , V_15 ;
int V_16 ;
if ( ! V_3 ) {
F_6 ( V_17 , V_18 ) ;
return 0 ;
}
V_12 = F_11 () ;
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
return 0 ;
}
if ( V_14 && F_14 ( V_12 ) )
V_14 = 0 ;
V_13 = F_15 ( V_12 , NULL ) ;
F_7 ( V_12 ) ;
if ( ! V_13 ) {
F_6 ( V_17 ,
V_20 ) ;
return 0 ;
}
if ( V_14 )
V_13 -> type |= V_21 ;
return V_13 ;
}
int F_16 ( T_1 * V_3 , int * V_22 )
{
char * V_23 ;
if ( ! ( V_23 = V_3 -> V_3 ) )
goto V_24;
if ( ! strcmp ( V_23 , L_1 ) || ! strcmp ( V_23 , L_2 )
|| ! strcmp ( V_23 , L_3 ) || ! strcmp ( V_23 , L_4 )
|| ! strcmp ( V_23 , L_5 ) || ! strcmp ( V_23 , L_6 ) ) {
* V_22 = 0xff ;
return 1 ;
} else if ( ! strcmp ( V_23 , L_7 ) || ! strcmp ( V_23 , L_8 )
|| ! strcmp ( V_23 , L_9 ) || ! strcmp ( V_23 , L_10 )
|| ! strcmp ( V_23 , L_11 ) || ! strcmp ( V_23 , L_12 ) ) {
* V_22 = 0 ;
return 1 ;
}
V_24:
F_6 ( V_25 ,
V_26 ) ;
F_17 ( V_3 ) ;
return 0 ;
}
int F_18 ( T_1 * V_3 , T_5 * * V_13 )
{
T_5 * V_27 ;
if ( ! ( V_27 = F_10 ( NULL , V_3 -> V_3 ) ) ) {
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
char * F_20 ( const unsigned char * V_30 , long V_31 )
{
char * V_32 , * V_29 ;
const unsigned char * V_28 ;
int V_33 ;
const static char V_34 [] = L_13 ;
if ( ! V_30 || ! V_31 )
return NULL ;
if ( ! ( V_32 = F_21 ( V_31 * 3 + 1 ) ) ) {
F_6 ( V_35 , V_10 ) ;
return NULL ;
}
V_29 = V_32 ;
for ( V_33 = 0 , V_28 = V_30 ; V_33 < V_31 ; V_33 ++ , V_28 ++ ) {
* V_29 ++ = V_34 [ ( * V_28 >> 4 ) & 0xf ] ;
* V_29 ++ = V_34 [ * V_28 & 0xf ] ;
* V_29 ++ = ':' ;
}
V_29 [ - 1 ] = 0 ;
#ifdef F_22
F_23 ( V_32 , V_32 , V_29 - V_32 - 1 ) ;
#endif
return V_32 ;
}
unsigned char * F_24 ( const char * V_36 , long * V_31 )
{
unsigned char * V_37 , * V_29 ;
unsigned char V_38 , V_39 , * V_28 ;
if ( ! V_36 ) {
F_6 ( V_40 , V_41 ) ;
return NULL ;
}
if ( ! ( V_37 = F_21 ( strlen ( V_36 ) >> 1 ) ) )
goto V_24;
for ( V_28 = ( unsigned char * ) V_36 , V_29 = V_37 ; * V_28 ; ) {
V_38 = * V_28 ++ ;
#ifdef F_22
V_38 = V_42 [ V_38 ] ;
#endif
if ( V_38 == ':' )
continue;
V_39 = * V_28 ++ ;
#ifdef F_22
V_39 = V_42 [ V_39 ] ;
#endif
if ( ! V_39 ) {
F_6 ( V_40 , V_43 ) ;
F_2 ( V_37 ) ;
return NULL ;
}
if ( isupper ( V_38 ) )
V_38 = tolower ( V_38 ) ;
if ( isupper ( V_39 ) )
V_39 = tolower ( V_39 ) ;
if ( ( V_38 >= '0' ) && ( V_38 <= '9' ) )
V_38 -= '0' ;
else if ( ( V_38 >= 'a' ) && ( V_38 <= 'f' ) )
V_38 -= 'a' - 10 ;
else
goto V_44;
if ( ( V_39 >= '0' ) && ( V_39 <= '9' ) )
V_39 -= '0' ;
else if ( ( V_39 >= 'a' ) && ( V_39 <= 'f' ) )
V_39 -= 'a' - 10 ;
else
goto V_44;
* V_29 ++ = ( V_38 << 4 ) | V_39 ;
}
if ( V_31 )
* V_31 = V_29 - V_37 ;
return V_37 ;
V_24:
if ( V_37 )
F_2 ( V_37 ) ;
F_6 ( V_40 , V_10 ) ;
return NULL ;
V_44:
F_2 ( V_37 ) ;
F_6 ( V_40 , V_45 ) ;
return NULL ;
}
int F_25 ( const char * V_2 , const char * V_46 )
{
int V_31 , V_16 ;
char V_47 ;
V_31 = strlen ( V_46 ) ;
if ( ( V_16 = strncmp ( V_2 , V_46 , V_31 ) ) )
return V_16 ;
V_47 = V_2 [ V_31 ] ;
if ( ! V_47 || ( V_47 == '.' ) )
return 0 ;
return 1 ;
}
static int F_26 ( const char * const * V_6 , const char * const * V_48 )
{
return strcmp ( * V_6 , * V_48 ) ;
}
void F_27 ( T_6 V_36 )
{
F_2 ( V_36 ) ;
}
static void F_28 ( const unsigned char * * V_28 , T_7 * V_49 ,
const unsigned char * V_50 , T_7 V_51 ,
unsigned int V_52 )
{
const unsigned char * V_53 = * V_28 ;
T_7 V_54 = * V_49 ;
if ( ( V_52 & V_55 ) == 0 )
return;
while ( V_54 > V_51 && * V_53 ) {
if ( ( V_52 & V_56 ) &&
* V_53 == '.' )
break;
++ V_53 ;
-- V_54 ;
}
if ( V_54 == V_51 ) {
* V_28 = V_53 ;
* V_49 = V_54 ;
}
}
static int F_29 ( const unsigned char * V_53 , T_7 V_54 ,
const unsigned char * V_50 , T_7 V_51 ,
unsigned int V_52 )
{
F_28 ( & V_53 , & V_54 , V_50 , V_51 , V_52 ) ;
if ( V_54 != V_51 )
return 0 ;
while ( V_54 ) {
unsigned char V_57 = * V_53 ;
unsigned char V_58 = * V_50 ;
if ( V_57 == 0 )
return 0 ;
if ( V_57 != V_58 ) {
if ( 'A' <= V_57 && V_57 <= 'Z' )
V_57 = ( V_57 - 'A' ) + 'a' ;
if ( 'A' <= V_58 && V_58 <= 'Z' )
V_58 = ( V_58 - 'A' ) + 'a' ;
if ( V_57 != V_58 )
return 0 ;
}
++ V_53 ;
++ V_50 ;
-- V_54 ;
}
return 1 ;
}
static int F_30 ( const unsigned char * V_53 , T_7 V_54 ,
const unsigned char * V_50 , T_7 V_51 ,
unsigned int V_52 )
{
F_28 ( & V_53 , & V_54 , V_50 , V_51 , V_52 ) ;
if ( V_54 != V_51 )
return 0 ;
return ! memcmp ( V_53 , V_50 , V_54 ) ;
}
static int F_31 ( const unsigned char * V_6 , T_7 V_59 ,
const unsigned char * V_48 , T_7 V_60 ,
unsigned int V_61 )
{
T_7 V_33 = V_59 ;
if ( V_59 != V_60 )
return 0 ;
while ( V_33 > 0 ) {
-- V_33 ;
if ( V_6 [ V_33 ] == '@' || V_48 [ V_33 ] == '@' ) {
if ( ! F_29 ( V_6 + V_33 , V_59 - V_33 , V_48 + V_33 , V_59 - V_33 , 0 ) )
return 0 ;
break;
}
}
if ( V_33 == 0 )
V_33 = V_59 ;
return F_30 ( V_6 , V_33 , V_48 , V_33 , 0 ) ;
}
static int F_32 ( const unsigned char * V_62 , T_7 V_63 ,
const unsigned char * V_64 , T_7 V_65 ,
const unsigned char * V_50 , T_7 V_51 ,
unsigned int V_52 )
{
const unsigned char * V_66 ;
const unsigned char * V_67 ;
const unsigned char * V_28 ;
int V_68 = 0 ;
int V_69 = 0 ;
if ( V_51 < V_63 + V_65 )
return 0 ;
if ( ! F_29 ( V_62 , V_63 , V_50 , V_63 , V_52 ) )
return 0 ;
V_66 = V_50 + V_63 ;
V_67 = V_50 + ( V_51 - V_65 ) ;
if ( ! F_29 ( V_67 , V_65 , V_64 , V_65 , V_52 ) )
return 0 ;
if ( V_63 == 0 && * V_64 == '.' ) {
if ( V_66 == V_67 )
return 0 ;
V_69 = 1 ;
if ( V_52 & V_70 )
V_68 = 1 ;
}
if ( ! V_69 &&
V_51 >= 4 && strncasecmp ( ( char * ) V_50 , L_14 , 4 ) == 0 )
return 0 ;
if ( V_67 == V_66 + 1 && * V_66 == '*' )
return 1 ;
for ( V_28 = V_66 ; V_28 != V_67 ; ++ V_28 )
if ( ! ( ( '0' <= * V_28 && * V_28 <= '9' ) ||
( 'A' <= * V_28 && * V_28 <= 'Z' ) ||
( 'a' <= * V_28 && * V_28 <= 'z' ) ||
* V_28 == '-' || ( V_68 && * V_28 == '.' ) ) )
return 0 ;
return 1 ;
}
static const unsigned char * F_33 ( const unsigned char * V_28 , T_7 V_31 ,
unsigned int V_52 )
{
const unsigned char * V_71 = 0 ;
T_7 V_33 ;
int V_72 = V_73 ;
int V_74 = 0 ;
for ( V_33 = 0 ; V_33 < V_31 ; ++ V_33 ) {
if ( V_28 [ V_33 ] == '*' ) {
int V_75 = ( V_72 & V_73 ) ;
int V_76 = ( V_33 == V_31 - 1 || V_28 [ V_33 + V_33 ] == '.' ) ;
if ( V_71 != NULL || ( V_72 & V_77 ) != 0 || V_74 )
return NULL ;
if ( ( V_52 & V_78 )
&& ( ! V_75 || ! V_76 ) )
return NULL ;
if ( ! V_75 && ! V_76 )
return NULL ;
V_71 = & V_28 [ V_33 ] ;
V_72 &= ~ V_73 ;
} else if ( ( 'a' <= V_28 [ V_33 ] && V_28 [ V_33 ] <= 'z' )
|| ( 'A' <= V_28 [ V_33 ] && V_28 [ V_33 ] <= 'Z' )
|| ( '0' <= V_28 [ V_33 ] && V_28 [ V_33 ] <= '9' ) ) {
if ( ( V_72 & V_73 ) != 0
&& V_31 - V_33 >= 4 && strncasecmp ( ( char * ) & V_28 [ V_33 ] , L_14 , 4 ) == 0 )
V_72 |= V_77 ;
V_72 &= ~ ( V_79 | V_73 ) ;
} else if ( V_28 [ V_33 ] == '.' ) {
if ( ( V_72 & ( V_79 | V_73 ) ) != 0 )
return NULL ;
V_72 = V_73 ;
++ V_74 ;
} else if ( V_28 [ V_33 ] == '-' ) {
if ( ( V_72 & V_79 ) != 0 )
return NULL ;
V_72 |= V_79 ;
} else
return NULL ;
}
if ( ( V_72 & ( V_73 | V_79 ) ) != 0 || V_74 < 2 )
return NULL ;
return V_71 ;
}
static int F_34 ( const unsigned char * V_53 , T_7 V_54 ,
const unsigned char * V_50 , T_7 V_51 ,
unsigned int V_52 )
{
const unsigned char * V_71 = NULL ;
if ( ! ( V_51 > 1 && V_50 [ 0 ] == '.' ) )
V_71 = F_33 ( V_53 , V_54 , V_52 ) ;
if ( V_71 == NULL )
return F_29 ( V_53 , V_54 ,
V_50 , V_51 , V_52 ) ;
return F_32 ( V_53 , V_71 - V_53 ,
V_71 + 1 , ( V_53 + V_54 ) - V_71 - 1 ,
V_50 , V_51 , V_52 ) ;
}
static int F_35 ( T_8 * V_6 , int V_80 , T_9 V_81 ,
unsigned int V_52 , const char * V_48 , T_7 V_82 ,
char * * V_83 )
{
int V_84 = 0 ;
if ( ! V_6 -> V_85 || ! V_6 -> V_86 )
return 0 ;
if ( V_80 > 0 ) {
if ( V_80 != V_6 -> type )
return 0 ;
if ( V_80 == V_87 )
V_84 = V_81 ( V_6 -> V_85 , V_6 -> V_86 , ( unsigned char * ) V_48 , V_82 , V_52 ) ;
else if ( V_6 -> V_86 == ( int ) V_82 && ! memcmp ( V_6 -> V_85 , V_48 , V_82 ) )
V_84 = 1 ;
if ( V_84 > 0 && V_83 )
* V_83 = F_36 ( ( char * ) V_6 -> V_85 , V_6 -> V_86 ) ;
} else {
int V_88 ;
unsigned char * V_89 ;
V_88 = F_37 ( & V_89 , V_6 ) ;
if ( V_88 < 0 )
return - 1 ;
V_84 = V_81 ( V_89 , V_88 , ( unsigned char * ) V_48 , V_82 , V_52 ) ;
if ( V_84 > 0 && V_83 )
* V_83 = F_36 ( ( char * ) V_89 , V_88 ) ;
F_2 ( V_89 ) ;
}
return V_84 ;
}
static int F_38 ( T_10 * V_90 , const char * V_91 , T_7 V_92 ,
unsigned int V_52 , int V_93 , char * * V_83 )
{
T_11 * V_94 = NULL ;
T_12 * V_2 = NULL ;
int V_33 ;
int V_95 ;
int V_96 ;
int V_97 = 0 ;
int V_84 = 0 ;
T_9 V_81 ;
V_52 &= ~ V_55 ;
if ( V_93 == V_98 ) {
V_95 = V_99 ;
V_96 = V_87 ;
V_81 = F_31 ;
} else if ( V_93 == V_100 ) {
V_95 = V_101 ;
if ( V_92 > 1 && V_91 [ 0 ] == '.' )
V_52 |= V_55 ;
V_96 = V_87 ;
if ( V_52 & V_102 )
V_81 = F_29 ;
else
V_81 = F_34 ;
} else {
V_95 = 0 ;
V_96 = V_103 ;
V_81 = F_30 ;
}
if ( V_92 == 0 )
V_92 = strlen ( V_91 ) ;
V_94 = F_39 ( V_90 , V_104 , NULL , NULL ) ;
if ( V_94 ) {
for ( V_33 = 0 ; V_33 < F_40 ( V_94 ) ; V_33 ++ ) {
T_13 * V_105 ;
T_8 * V_106 ;
V_105 = F_41 ( V_94 , V_33 ) ;
if ( V_105 -> type != V_93 )
continue;
V_97 = 1 ;
if ( V_93 == V_98 )
V_106 = V_105 -> V_107 . V_108 ;
else if ( V_93 == V_100 )
V_106 = V_105 -> V_107 . V_109 ;
else
V_106 = V_105 -> V_107 . V_110 ;
if ( ( V_84 = F_35 ( V_106 , V_96 , V_81 , V_52 ,
V_91 , V_92 , V_83 ) ) != 0 )
break;
}
F_42 ( V_94 ) ;
if ( V_84 != 0 )
return V_84 ;
if ( ! V_95
|| ( V_97
&& ! ( V_52 & V_111 ) ) )
return 0 ;
}
V_33 = - 1 ;
V_2 = F_43 ( V_90 ) ;
while ( ( V_33 = F_44 ( V_2 , V_95 , V_33 ) ) >= 0 ) {
T_14 * V_112 ;
T_8 * V_36 ;
V_112 = F_45 ( V_2 , V_33 ) ;
V_36 = F_46 ( V_112 ) ;
if ( ( V_84 = F_35 ( V_36 , - 1 , V_81 , V_52 ,
V_91 , V_92 , V_83 ) ) != 0 )
return V_84 ;
}
return 0 ;
}
int F_47 ( T_10 * V_90 , const char * V_91 , T_7 V_92 ,
unsigned int V_52 , char * * V_83 )
{
if ( V_91 == NULL )
return - 2 ;
if ( V_92 == 0 )
V_92 = strlen ( V_91 ) ;
else if ( memchr ( V_91 , '\0' , V_92 > 1 ? V_92 - 1 : V_92 ) )
return - 2 ;
if ( V_92 > 1 && V_91 [ V_92 - 1 ] == '\0' )
-- V_92 ;
return F_38 ( V_90 , V_91 , V_92 , V_52 , V_100 , V_83 ) ;
}
int F_48 ( T_10 * V_90 , const char * V_91 , T_7 V_92 ,
unsigned int V_52 )
{
if ( V_91 == NULL )
return - 2 ;
if ( V_92 == 0 )
V_92 = strlen ( ( char * ) V_91 ) ;
else if ( memchr ( V_91 , '\0' , V_92 > 1 ? V_92 - 1 : V_92 ) )
return - 2 ;
if ( V_92 > 1 && V_91 [ V_92 - 1 ] == '\0' )
-- V_92 ;
return F_38 ( V_90 , V_91 , V_92 , V_52 , V_98 , NULL ) ;
}
int F_49 ( T_10 * V_90 , const unsigned char * V_91 , T_7 V_92 ,
unsigned int V_52 )
{
if ( V_91 == NULL )
return - 2 ;
return F_38 ( V_90 , ( char * ) V_91 , V_92 , V_52 , V_113 , NULL ) ;
}
int F_50 ( T_10 * V_90 , const char * V_114 , unsigned int V_52 )
{
unsigned char V_115 [ 16 ] ;
T_7 V_116 ;
if ( V_114 == NULL )
return - 2 ;
V_116 = ( T_7 ) F_51 ( V_115 , V_114 ) ;
if ( V_116 == 0 )
return - 2 ;
return F_38 ( V_90 , ( char * ) V_115 , V_116 , V_52 , V_113 , NULL ) ;
}
T_15 * F_52 ( const char * V_114 )
{
unsigned char V_115 [ 16 ] ;
T_15 * V_16 ;
int V_116 ;
V_116 = F_51 ( V_115 , V_114 ) ;
if ( ! V_116 )
return NULL ;
V_16 = F_53 () ;
if ( ! V_16 )
return NULL ;
if ( ! F_54 ( V_16 , V_115 , V_116 ) ) {
F_55 ( V_16 ) ;
return NULL ;
}
return V_16 ;
}
T_15 * F_56 ( const char * V_114 )
{
T_15 * V_16 = NULL ;
unsigned char V_115 [ 32 ] ;
char * V_117 = NULL , * V_28 ;
int V_118 , V_119 ;
V_28 = strchr ( V_114 , '/' ) ;
if ( ! V_28 )
return NULL ;
V_117 = F_57 ( V_114 ) ;
if ( ! V_117 )
return NULL ;
V_28 = V_117 + ( V_28 - V_114 ) ;
* V_28 ++ = 0 ;
V_118 = F_51 ( V_115 , V_117 ) ;
if ( ! V_118 )
goto V_24;
V_119 = F_51 ( V_115 + V_118 , V_28 ) ;
F_2 ( V_117 ) ;
V_117 = NULL ;
if ( ! V_119 || ( V_118 != V_119 ) )
goto V_24;
V_16 = F_53 () ;
if ( ! V_16 )
goto V_24;
if ( ! F_54 ( V_16 , V_115 , V_118 + V_119 ) )
goto V_24;
return V_16 ;
V_24:
if ( V_117 )
F_2 ( V_117 ) ;
if ( V_16 )
F_55 ( V_16 ) ;
return NULL ;
}
int F_51 ( unsigned char * V_115 , const char * V_114 )
{
if ( strchr ( V_114 , ':' ) ) {
if ( ! F_58 ( V_115 , V_114 ) )
return 0 ;
return 16 ;
} else {
if ( ! F_59 ( V_115 , V_114 ) )
return 0 ;
return 4 ;
}
}
static int F_59 ( unsigned char * V_120 , const char * V_121 )
{
int V_122 , V_123 , V_124 , V_125 ;
if ( sscanf ( V_121 , L_15 , & V_122 , & V_123 , & V_124 , & V_125 ) != 4 )
return 0 ;
if ( ( V_122 < 0 ) || ( V_122 > 255 ) || ( V_123 < 0 ) || ( V_123 > 255 )
|| ( V_124 < 0 ) || ( V_124 > 255 ) || ( V_125 < 0 ) || ( V_125 > 255 ) )
return 0 ;
V_120 [ 0 ] = V_122 ;
V_120 [ 1 ] = V_123 ;
V_120 [ 2 ] = V_124 ;
V_120 [ 3 ] = V_125 ;
return 1 ;
}
static int F_58 ( unsigned char * V_126 , const char * V_121 )
{
T_16 V_127 ;
V_127 . V_128 = 0 ;
V_127 . V_129 = - 1 ;
V_127 . V_130 = 0 ;
if ( ! F_60 ( V_121 , ':' , 0 , V_131 , & V_127 ) )
return 0 ;
if ( V_127 . V_129 == - 1 ) {
if ( V_127 . V_128 != 16 )
return 0 ;
} else {
if ( V_127 . V_128 == 16 )
return 0 ;
if ( V_127 . V_130 > 3 )
return 0 ;
else if ( V_127 . V_130 == 3 ) {
if ( V_127 . V_128 > 0 )
return 0 ;
}
else if ( V_127 . V_130 == 2 ) {
if ( ( V_127 . V_129 != 0 )
&& ( V_127 . V_129 != V_127 . V_128 ) )
return 0 ;
} else
{
if ( ( V_127 . V_129 == 0 )
|| ( V_127 . V_129 == V_127 . V_128 ) )
return 0 ;
}
}
if ( V_127 . V_129 >= 0 ) {
memcpy ( V_126 , V_127 . V_32 , V_127 . V_129 ) ;
memset ( V_126 + V_127 . V_129 , 0 , 16 - V_127 . V_128 ) ;
if ( V_127 . V_128 != V_127 . V_129 )
memcpy ( V_126 + V_127 . V_129 + 16 - V_127 . V_128 ,
V_127 . V_32 + V_127 . V_129 ,
V_127 . V_128 - V_127 . V_129 ) ;
} else
memcpy ( V_126 , V_127 . V_32 , 16 ) ;
return 1 ;
}
static int V_131 ( const char * V_132 , int V_31 , void * V_133 )
{
T_16 * V_134 = V_133 ;
if ( V_134 -> V_128 == 16 )
return 0 ;
if ( V_31 == 0 ) {
if ( V_134 -> V_129 == - 1 )
V_134 -> V_129 = V_134 -> V_128 ;
else if ( V_134 -> V_129 != V_134 -> V_128 )
return 0 ;
V_134 -> V_130 ++ ;
} else {
if ( V_31 > 4 ) {
if ( V_134 -> V_128 > 12 )
return 0 ;
if ( V_132 [ V_31 ] )
return 0 ;
if ( ! F_59 ( V_134 -> V_32 + V_134 -> V_128 , V_132 ) )
return 0 ;
V_134 -> V_128 += 4 ;
} else {
if ( ! F_61 ( V_134 -> V_32 + V_134 -> V_128 , V_132 , V_31 ) )
return 0 ;
V_134 -> V_128 += 2 ;
}
}
return 1 ;
}
static int F_61 ( unsigned char * V_135 , const char * V_121 , int V_136 )
{
unsigned char V_47 ;
unsigned int V_137 = 0 ;
if ( V_136 > 4 )
return 0 ;
while ( V_136 -- ) {
V_47 = * V_121 ++ ;
V_137 <<= 4 ;
if ( ( V_47 >= '0' ) && ( V_47 <= '9' ) )
V_137 |= V_47 - '0' ;
else if ( ( V_47 >= 'A' ) && ( V_47 <= 'F' ) )
V_137 |= V_47 - 'A' + 10 ;
else if ( ( V_47 >= 'a' ) && ( V_47 <= 'f' ) )
V_137 |= V_47 - 'a' + 10 ;
else
return 0 ;
}
V_135 [ 0 ] = V_137 >> 8 ;
V_135 [ 1 ] = V_137 & 0xff ;
return 1 ;
}
