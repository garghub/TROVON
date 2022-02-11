static T_1 * F_1 ( struct V_1 * V_2 )
{
char * V_3 = strrchr ( V_2 -> V_4 , '.' ) ;
struct V_5 * V_6 ;
F_2 (l, &entries) {
T_1 * V_7 = F_3 ( V_6 , T_1 , V_8 ) ;
char * V_9 ;
int V_10 ;
if ( ! F_4 ( V_11 , & V_7 -> V_12 ) )
continue;
if ( ! F_4 ( V_13 , & V_7 -> V_12 ) ) {
if ( V_3 && ! strcmp ( V_7 -> V_14 , V_3 + 1 ) )
return V_7 ;
continue;
}
V_9 = V_2 -> V_15 + V_7 -> V_16 ;
if ( V_7 -> V_17 ) {
for ( V_10 = 0 ; V_10 < V_7 -> V_18 ; V_10 ++ )
if ( ( * V_9 ++ ^ V_7 -> V_14 [ V_10 ] ) & V_7 -> V_17 [ V_10 ] )
break;
} else {
for ( V_10 = 0 ; V_10 < V_7 -> V_18 ; V_10 ++ )
if ( ( * V_9 ++ ^ V_7 -> V_14 [ V_10 ] ) )
break;
}
if ( V_10 == V_7 -> V_18 )
return V_7 ;
}
return NULL ;
}
static int F_5 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
T_1 * V_21 ;
struct V_22 * V_23 = NULL ;
char V_24 [ V_25 ] ;
const char * V_26 = V_24 ;
int V_27 ;
int V_28 = - 1 ;
V_27 = - V_29 ;
if ( ! V_30 )
goto V_31;
V_27 = - V_29 ;
if ( V_2 -> V_32 > V_33 )
goto V_31;
F_6 ( & V_34 ) ;
V_21 = F_1 ( V_2 ) ;
if ( V_21 )
F_7 ( V_24 , V_21 -> V_35 , V_25 ) ;
F_8 ( & V_34 ) ;
if ( ! V_21 )
goto V_31;
if ( ! ( V_21 -> V_12 & V_36 ) ) {
V_27 = F_9 ( V_2 ) ;
if ( V_27 )
goto V_31;
}
if ( V_21 -> V_12 & V_37 ) {
V_28 = F_10 () ;
if ( V_28 < 0 ) {
V_27 = V_28 ;
goto V_31;
}
F_11 ( V_28 , V_2 -> V_22 ) ;
if ( F_12 ( V_2 -> V_22 , V_38 ) )
V_2 -> V_39 |= V_40 ;
F_13 ( V_2 -> V_22 ) ;
V_2 -> V_22 = NULL ;
V_2 -> V_39 |= V_41 ;
V_2 -> V_42 = V_28 ;
} else {
F_13 ( V_2 -> V_22 ) ;
F_14 ( V_2 -> V_22 ) ;
V_2 -> V_22 = NULL ;
}
V_27 = F_15 ( 1 , & V_2 -> V_4 , V_2 ) ;
if ( V_27 < 0 )
goto V_43;
V_2 -> V_44 ++ ;
V_27 = F_15 ( 1 , & V_26 , V_2 ) ;
if ( V_27 < 0 )
goto V_43;
V_2 -> V_44 ++ ;
V_2 -> V_4 = V_24 ;
V_23 = F_16 ( V_24 ) ;
V_27 = F_17 ( V_23 ) ;
if ( F_18 ( V_23 ) )
goto V_43;
V_2 -> V_22 = V_23 ;
if ( V_21 -> V_12 & V_45 ) {
memset ( V_2 -> V_15 , 0 , V_25 ) ;
V_27 = F_19 ( V_2 -> V_22 , 0 , V_2 -> V_15 , V_25 ) ;
} else
V_27 = F_20 ( V_2 ) ;
if ( V_27 < 0 )
goto V_43;
V_2 -> V_32 ++ ;
V_27 = F_21 ( V_2 , V_20 ) ;
if ( V_27 < 0 )
goto V_43;
V_31:
return V_27 ;
V_43:
if ( V_28 > 0 )
F_22 ( V_28 ) ;
V_2 -> V_39 = 0 ;
V_2 -> V_42 = 0 ;
goto V_31;
}
static char * F_23 ( char * V_9 , char V_46 )
{
char V_47 ;
while ( ( V_47 = * V_9 ++ ) != V_46 ) {
if ( V_47 == '\\' && * V_9 == 'x' ) {
V_9 ++ ;
if ( ! isxdigit ( * V_9 ++ ) )
return NULL ;
if ( ! isxdigit ( * V_9 ++ ) )
return NULL ;
}
}
return V_9 ;
}
static int F_24 ( char * V_48 )
{
char V_47 = 0 , * V_9 = V_48 , * V_3 = V_48 ;
while ( ( V_47 = * V_9 ++ ) != '\0' ) {
if ( V_47 == '\\' && * V_9 == 'x' ) {
V_9 ++ ;
V_47 = toupper ( * V_9 ++ ) ;
* V_3 = ( V_47 - ( isdigit ( V_47 ) ? '0' : 'A' - 10 ) ) << 4 ;
V_47 = toupper ( * V_9 ++ ) ;
* V_3 ++ |= V_47 - ( isdigit ( V_47 ) ? '0' : 'A' - 10 ) ;
continue;
}
* V_3 ++ = V_47 ;
}
return V_3 - V_48 ;
}
static char * F_25 ( char * V_49 , T_1 * V_7 )
{
char * V_3 = V_49 ;
int V_50 = 1 ;
while ( V_50 ) {
switch ( * V_3 ) {
case 'P' :
V_3 ++ ;
V_7 -> V_12 |= V_36 ;
break;
case 'O' :
V_3 ++ ;
V_7 -> V_12 |= V_37 ;
break;
case 'C' :
V_3 ++ ;
V_7 -> V_12 |= ( V_45 |
V_37 ) ;
break;
default:
V_50 = 0 ;
}
}
return V_3 ;
}
static T_1 * F_26 ( const char T_2 * V_51 , T_3 V_52 )
{
T_1 * V_7 ;
int V_53 , V_54 ;
char * V_15 , * V_3 ;
char V_46 ;
V_54 = - V_55 ;
if ( ( V_52 < 11 ) || ( V_52 > 256 ) )
goto V_56;
V_54 = - V_57 ;
V_53 = sizeof( T_1 ) + V_52 + 8 ;
V_7 = F_27 ( V_53 , V_58 ) ;
if ( ! V_7 )
goto V_56;
V_3 = V_15 = ( char * ) V_7 + sizeof( T_1 ) ;
memset ( V_7 , 0 , sizeof( T_1 ) ) ;
if ( F_28 ( V_15 , V_51 , V_52 ) )
goto V_59;
V_46 = * V_3 ++ ;
memset ( V_15 + V_52 , V_46 , 8 ) ;
V_7 -> V_60 = V_3 ;
V_3 = strchr ( V_3 , V_46 ) ;
if ( ! V_3 )
goto V_61;
* V_3 ++ = '\0' ;
if ( ! V_7 -> V_60 [ 0 ] ||
! strcmp ( V_7 -> V_60 , L_1 ) ||
! strcmp ( V_7 -> V_60 , L_2 ) ||
strchr ( V_7 -> V_60 , '/' ) )
goto V_61;
switch ( * V_3 ++ ) {
case 'E' : V_7 -> V_12 = 1 << V_11 ; break;
case 'M' : V_7 -> V_12 = ( 1 << V_11 ) | ( 1 << V_13 ) ; break;
default: goto V_61;
}
if ( * V_3 ++ != V_46 )
goto V_61;
if ( F_4 ( V_13 , & V_7 -> V_12 ) ) {
char * V_9 = strchr ( V_3 , V_46 ) ;
if ( ! V_9 )
goto V_61;
* V_9 ++ = '\0' ;
V_7 -> V_16 = F_29 ( V_3 , & V_3 , 10 ) ;
if ( * V_3 ++ )
goto V_61;
V_7 -> V_14 = V_3 ;
V_3 = F_23 ( V_3 , V_46 ) ;
if ( ! V_3 )
goto V_61;
V_3 [ - 1 ] = '\0' ;
if ( ! V_7 -> V_14 [ 0 ] )
goto V_61;
V_7 -> V_17 = V_3 ;
V_3 = F_23 ( V_3 , V_46 ) ;
if ( ! V_3 )
goto V_61;
V_3 [ - 1 ] = '\0' ;
if ( ! V_7 -> V_17 [ 0 ] )
V_7 -> V_17 = NULL ;
V_7 -> V_18 = F_24 ( V_7 -> V_14 ) ;
if ( V_7 -> V_17 && F_24 ( V_7 -> V_17 ) != V_7 -> V_18 )
goto V_61;
if ( V_7 -> V_18 + V_7 -> V_16 > V_25 )
goto V_61;
} else {
V_3 = strchr ( V_3 , V_46 ) ;
if ( ! V_3 )
goto V_61;
* V_3 ++ = '\0' ;
V_7 -> V_14 = V_3 ;
V_3 = strchr ( V_3 , V_46 ) ;
if ( ! V_3 )
goto V_61;
* V_3 ++ = '\0' ;
if ( ! V_7 -> V_14 [ 0 ] || strchr ( V_7 -> V_14 , '/' ) )
goto V_61;
V_3 = strchr ( V_3 , V_46 ) ;
if ( ! V_3 )
goto V_61;
* V_3 ++ = '\0' ;
}
V_7 -> V_35 = V_3 ;
V_3 = strchr ( V_3 , V_46 ) ;
if ( ! V_3 )
goto V_61;
* V_3 ++ = '\0' ;
if ( ! V_7 -> V_35 [ 0 ] )
goto V_61;
V_3 = F_25 ( V_3 , V_7 ) ;
if ( * V_3 == '\n' )
V_3 ++ ;
if ( V_3 != V_15 + V_52 )
goto V_61;
return V_7 ;
V_56:
return F_30 ( V_54 ) ;
V_59:
F_31 ( V_7 ) ;
return F_30 ( - V_62 ) ;
V_61:
F_31 ( V_7 ) ;
return F_30 ( - V_55 ) ;
}
static int F_32 ( const char T_2 * V_51 , T_3 V_52 )
{
char V_9 [ 4 ] ;
if ( ! V_52 )
return 0 ;
if ( V_52 > 3 )
return - V_55 ;
if ( F_28 ( V_9 , V_51 , V_52 ) )
return - V_62 ;
if ( V_9 [ V_52 - 1 ] == '\n' )
V_52 -- ;
if ( V_52 == 1 && V_9 [ 0 ] == '0' )
return 1 ;
if ( V_52 == 1 && V_9 [ 0 ] == '1' )
return 2 ;
if ( V_52 == 2 && V_9 [ 0 ] == '-' && V_9 [ 1 ] == '1' )
return 3 ;
return - V_55 ;
}
static void F_33 ( T_1 * V_7 , char * V_63 )
{
char * V_64 ;
char * V_65 = L_3 ;
const char * V_12 = L_4 ;
if ( F_4 ( V_11 , & V_7 -> V_12 ) )
V_65 = L_5 ;
if ( ! V_66 ) {
sprintf ( V_63 , L_6 , V_65 ) ;
return;
}
sprintf ( V_63 , L_7 , V_65 , V_7 -> V_35 ) ;
V_64 = V_63 + strlen ( V_63 ) ;
sprintf ( V_64 , L_8 , V_12 ) ;
V_64 += strlen ( V_12 ) ;
if ( V_7 -> V_12 & V_36 ) {
* V_64 ++ = 'P' ;
}
if ( V_7 -> V_12 & V_37 ) {
* V_64 ++ = 'O' ;
}
if ( V_7 -> V_12 & V_45 ) {
* V_64 ++ = 'C' ;
}
* V_64 ++ = '\n' ;
if ( ! F_4 ( V_13 , & V_7 -> V_12 ) ) {
sprintf ( V_64 , L_9 , V_7 -> V_14 ) ;
} else {
int V_67 ;
sprintf ( V_64 , L_10 , V_7 -> V_16 ) ;
V_64 = V_63 + strlen ( V_63 ) ;
for ( V_67 = 0 ; V_67 < V_7 -> V_18 ; V_67 ++ ) {
sprintf ( V_64 , L_11 , 0xff & ( int ) ( V_7 -> V_14 [ V_67 ] ) ) ;
V_64 += 2 ;
}
if ( V_7 -> V_17 ) {
sprintf ( V_64 , L_12 ) ;
V_64 += 6 ;
for ( V_67 = 0 ; V_67 < V_7 -> V_18 ; V_67 ++ ) {
sprintf ( V_64 , L_11 , 0xff & ( int ) ( V_7 -> V_17 [ V_67 ] ) ) ;
V_64 += 2 ;
}
}
* V_64 ++ = '\n' ;
* V_64 = '\0' ;
}
}
static struct V_68 * F_34 ( struct V_69 * V_70 , int V_71 )
{
struct V_68 * V_68 = F_35 ( V_70 ) ;
if ( V_68 ) {
V_68 -> V_72 = F_36 () ;
V_68 -> V_73 = V_71 ;
V_68 -> V_74 = V_68 -> V_75 = V_68 -> V_76 =
F_37 ( V_68 -> V_77 ) ;
}
return V_68 ;
}
static void F_38 ( struct V_68 * V_68 )
{
F_39 ( V_68 ) ;
F_31 ( V_68 -> V_78 ) ;
}
static void F_40 ( T_1 * V_7 )
{
struct V_79 * V_79 ;
F_41 ( & V_34 ) ;
V_79 = V_7 -> V_79 ;
if ( V_79 ) {
F_42 ( & V_7 -> V_8 ) ;
V_7 -> V_79 = NULL ;
}
F_43 ( & V_34 ) ;
if ( V_79 ) {
V_79 -> V_80 -> V_81 -- ;
F_44 ( V_79 ) ;
F_45 ( V_79 ) ;
F_46 ( & V_82 , & V_83 ) ;
}
}
static T_4
F_47 ( struct V_22 * V_22 , char T_2 * V_15 , T_3 V_84 , T_5 * V_85 )
{
T_1 * V_7 = V_22 -> V_86 . V_79 -> V_80 -> V_78 ;
T_4 V_87 ;
char * V_63 ;
if ( ! ( V_63 = ( char * ) F_48 ( V_88 ) ) )
return - V_57 ;
F_33 ( V_7 , V_63 ) ;
V_87 = F_49 ( V_15 , V_84 , V_85 , V_63 , strlen ( V_63 ) ) ;
F_50 ( ( unsigned long ) V_63 ) ;
return V_87 ;
}
static T_4 F_51 ( struct V_22 * V_22 , const char T_2 * V_51 ,
T_3 V_52 , T_5 * V_85 )
{
struct V_79 * V_89 ;
T_1 * V_7 = V_22 -> V_86 . V_79 -> V_80 -> V_78 ;
int V_87 = F_32 ( V_51 , V_52 ) ;
switch ( V_87 ) {
case 1 : F_52 ( V_11 , & V_7 -> V_12 ) ;
break;
case 2 : F_53 ( V_11 , & V_7 -> V_12 ) ;
break;
case 3 : V_89 = F_54 ( V_22 -> V_86 . V_90 -> V_91 -> V_92 ) ;
F_55 ( & V_89 -> V_80 -> V_93 ) ;
F_40 ( V_7 ) ;
F_56 ( & V_89 -> V_80 -> V_93 ) ;
F_45 ( V_89 ) ;
break;
default: return V_87 ;
}
return V_52 ;
}
static T_4 F_57 ( struct V_22 * V_22 , const char T_2 * V_51 ,
T_3 V_52 , T_5 * V_85 )
{
T_1 * V_7 ;
struct V_68 * V_68 ;
struct V_79 * V_89 , * V_79 ;
struct V_69 * V_70 = V_22 -> V_86 . V_90 -> V_91 ;
int V_54 = 0 ;
V_7 = F_26 ( V_51 , V_52 ) ;
if ( F_18 ( V_7 ) )
return F_17 ( V_7 ) ;
V_89 = F_54 ( V_70 -> V_92 ) ;
F_55 ( & V_89 -> V_80 -> V_93 ) ;
V_79 = F_58 ( V_7 -> V_60 , V_89 , strlen ( V_7 -> V_60 ) ) ;
V_54 = F_17 ( V_79 ) ;
if ( F_18 ( V_79 ) )
goto V_56;
V_54 = - V_94 ;
if ( V_79 -> V_80 )
goto V_95;
V_68 = F_34 ( V_70 , V_96 | 0644 ) ;
V_54 = - V_57 ;
if ( ! V_68 )
goto V_95;
V_54 = F_59 ( & V_97 , & V_82 , & V_83 ) ;
if ( V_54 ) {
F_60 ( V_68 ) ;
V_68 = NULL ;
goto V_95;
}
V_7 -> V_79 = F_54 ( V_79 ) ;
V_68 -> V_78 = V_7 ;
V_68 -> V_98 = & V_99 ;
F_61 ( V_79 , V_68 ) ;
F_41 ( & V_34 ) ;
F_62 ( & V_7 -> V_8 , & V_100 ) ;
F_43 ( & V_34 ) ;
V_54 = 0 ;
V_95:
F_45 ( V_79 ) ;
V_56:
F_56 ( & V_89 -> V_80 -> V_93 ) ;
F_45 ( V_89 ) ;
if ( V_54 ) {
F_31 ( V_7 ) ;
return - V_55 ;
}
return V_52 ;
}
static T_4
F_63 ( struct V_22 * V_22 , char T_2 * V_15 , T_3 V_84 , T_5 * V_85 )
{
char * V_9 = V_30 ? L_13 : L_14 ;
return F_49 ( V_15 , V_84 , V_85 , V_9 , strlen ( V_9 ) ) ;
}
static T_4 F_64 ( struct V_22 * V_22 , const char T_2 * V_51 ,
T_3 V_52 , T_5 * V_85 )
{
int V_87 = F_32 ( V_51 , V_52 ) ;
struct V_79 * V_89 ;
switch ( V_87 ) {
case 1 : V_30 = 0 ; break;
case 2 : V_30 = 1 ; break;
case 3 : V_89 = F_54 ( V_22 -> V_86 . V_90 -> V_91 -> V_92 ) ;
F_55 ( & V_89 -> V_80 -> V_93 ) ;
while ( ! F_65 ( & V_100 ) )
F_40 ( F_3 ( V_100 . V_101 , T_1 , V_8 ) ) ;
F_56 ( & V_89 -> V_80 -> V_93 ) ;
F_45 ( V_89 ) ;
default: return V_87 ;
}
return V_52 ;
}
static int F_66 ( struct V_69 * V_70 , void * V_102 , int V_103 )
{
static struct V_104 V_105 [] = {
[ 2 ] = { L_15 , & V_106 , V_107 | V_108 } ,
[ 3 ] = { L_16 , & V_109 , V_107 } ,
{ L_17 }
} ;
int V_54 = F_67 ( V_70 , 0x42494e4d , V_105 ) ;
if ( ! V_54 )
V_70 -> V_110 = & V_111 ;
return V_54 ;
}
static struct V_79 * F_68 ( struct V_112 * V_113 ,
int V_12 , const char * V_114 , void * V_102 )
{
return F_69 ( V_113 , V_12 , V_102 , F_66 ) ;
}
static int T_6 F_70 ( void )
{
int V_54 = F_71 ( & V_97 ) ;
if ( ! V_54 ) {
V_54 = F_72 ( & V_115 ) ;
if ( V_54 )
F_73 ( & V_97 ) ;
}
return V_54 ;
}
static void T_7 F_74 ( void )
{
F_75 ( & V_115 ) ;
F_73 ( & V_97 ) ;
}
