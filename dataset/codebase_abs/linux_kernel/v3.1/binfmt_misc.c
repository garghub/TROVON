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
F_12 ( V_2 , V_2 -> V_22 ) ;
F_13 ( V_2 -> V_22 ) ;
V_2 -> V_22 = NULL ;
V_2 -> V_38 |= V_39 ;
V_2 -> V_40 = V_28 ;
} else {
F_13 ( V_2 -> V_22 ) ;
F_14 ( V_2 -> V_22 ) ;
V_2 -> V_22 = NULL ;
}
V_27 = F_15 ( 1 , & V_2 -> V_4 , V_2 ) ;
if ( V_27 < 0 )
goto V_41;
V_2 -> V_42 ++ ;
V_27 = F_15 ( 1 , & V_26 , V_2 ) ;
if ( V_27 < 0 )
goto V_41;
V_2 -> V_42 ++ ;
V_2 -> V_4 = V_24 ;
V_23 = F_16 ( V_24 ) ;
V_27 = F_17 ( V_23 ) ;
if ( F_18 ( V_23 ) )
goto V_41;
V_2 -> V_22 = V_23 ;
if ( V_21 -> V_12 & V_43 ) {
memset ( V_2 -> V_15 , 0 , V_25 ) ;
V_27 = F_19 ( V_2 -> V_22 , 0 , V_2 -> V_15 , V_25 ) ;
} else
V_27 = F_20 ( V_2 ) ;
if ( V_27 < 0 )
goto V_41;
V_2 -> V_32 ++ ;
V_27 = F_21 ( V_2 , V_20 ) ;
if ( V_27 < 0 )
goto V_41;
V_31:
return V_27 ;
V_41:
if ( V_28 > 0 )
F_22 ( V_28 ) ;
V_2 -> V_38 = 0 ;
V_2 -> V_40 = 0 ;
goto V_31;
}
static char * F_23 ( char * V_9 , char V_44 )
{
char V_45 ;
while ( ( V_45 = * V_9 ++ ) != V_44 ) {
if ( V_45 == '\\' && * V_9 == 'x' ) {
V_9 ++ ;
if ( ! isxdigit ( * V_9 ++ ) )
return NULL ;
if ( ! isxdigit ( * V_9 ++ ) )
return NULL ;
}
}
return V_9 ;
}
static int F_24 ( char * V_46 )
{
char V_45 = 0 , * V_9 = V_46 , * V_3 = V_46 ;
while ( ( V_45 = * V_9 ++ ) != '\0' ) {
if ( V_45 == '\\' && * V_9 == 'x' ) {
V_9 ++ ;
V_45 = toupper ( * V_9 ++ ) ;
* V_3 = ( V_45 - ( isdigit ( V_45 ) ? '0' : 'A' - 10 ) ) << 4 ;
V_45 = toupper ( * V_9 ++ ) ;
* V_3 ++ |= V_45 - ( isdigit ( V_45 ) ? '0' : 'A' - 10 ) ;
continue;
}
* V_3 ++ = V_45 ;
}
return V_3 - V_46 ;
}
static char * F_25 ( char * V_47 , T_1 * V_7 )
{
char * V_3 = V_47 ;
int V_48 = 1 ;
while ( V_48 ) {
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
V_7 -> V_12 |= ( V_43 |
V_37 ) ;
break;
default:
V_48 = 0 ;
}
}
return V_3 ;
}
static T_1 * F_26 ( const char T_2 * V_49 , T_3 V_50 )
{
T_1 * V_7 ;
int V_51 , V_52 ;
char * V_15 , * V_3 ;
char V_44 ;
V_52 = - V_53 ;
if ( ( V_50 < 11 ) || ( V_50 > 256 ) )
goto V_54;
V_52 = - V_55 ;
V_51 = sizeof( T_1 ) + V_50 + 8 ;
V_7 = F_27 ( V_51 , V_56 ) ;
if ( ! V_7 )
goto V_54;
V_3 = V_15 = ( char * ) V_7 + sizeof( T_1 ) ;
memset ( V_7 , 0 , sizeof( T_1 ) ) ;
if ( F_28 ( V_15 , V_49 , V_50 ) )
goto V_57;
V_44 = * V_3 ++ ;
memset ( V_15 + V_50 , V_44 , 8 ) ;
V_7 -> V_58 = V_3 ;
V_3 = strchr ( V_3 , V_44 ) ;
if ( ! V_3 )
goto V_59;
* V_3 ++ = '\0' ;
if ( ! V_7 -> V_58 [ 0 ] ||
! strcmp ( V_7 -> V_58 , L_1 ) ||
! strcmp ( V_7 -> V_58 , L_2 ) ||
strchr ( V_7 -> V_58 , '/' ) )
goto V_59;
switch ( * V_3 ++ ) {
case 'E' : V_7 -> V_12 = 1 << V_11 ; break;
case 'M' : V_7 -> V_12 = ( 1 << V_11 ) | ( 1 << V_13 ) ; break;
default: goto V_59;
}
if ( * V_3 ++ != V_44 )
goto V_59;
if ( F_4 ( V_13 , & V_7 -> V_12 ) ) {
char * V_9 = strchr ( V_3 , V_44 ) ;
if ( ! V_9 )
goto V_59;
* V_9 ++ = '\0' ;
V_7 -> V_16 = F_29 ( V_3 , & V_3 , 10 ) ;
if ( * V_3 ++ )
goto V_59;
V_7 -> V_14 = V_3 ;
V_3 = F_23 ( V_3 , V_44 ) ;
if ( ! V_3 )
goto V_59;
V_3 [ - 1 ] = '\0' ;
if ( ! V_7 -> V_14 [ 0 ] )
goto V_59;
V_7 -> V_17 = V_3 ;
V_3 = F_23 ( V_3 , V_44 ) ;
if ( ! V_3 )
goto V_59;
V_3 [ - 1 ] = '\0' ;
if ( ! V_7 -> V_17 [ 0 ] )
V_7 -> V_17 = NULL ;
V_7 -> V_18 = F_24 ( V_7 -> V_14 ) ;
if ( V_7 -> V_17 && F_24 ( V_7 -> V_17 ) != V_7 -> V_18 )
goto V_59;
if ( V_7 -> V_18 + V_7 -> V_16 > V_25 )
goto V_59;
} else {
V_3 = strchr ( V_3 , V_44 ) ;
if ( ! V_3 )
goto V_59;
* V_3 ++ = '\0' ;
V_7 -> V_14 = V_3 ;
V_3 = strchr ( V_3 , V_44 ) ;
if ( ! V_3 )
goto V_59;
* V_3 ++ = '\0' ;
if ( ! V_7 -> V_14 [ 0 ] || strchr ( V_7 -> V_14 , '/' ) )
goto V_59;
V_3 = strchr ( V_3 , V_44 ) ;
if ( ! V_3 )
goto V_59;
* V_3 ++ = '\0' ;
}
V_7 -> V_35 = V_3 ;
V_3 = strchr ( V_3 , V_44 ) ;
if ( ! V_3 )
goto V_59;
* V_3 ++ = '\0' ;
if ( ! V_7 -> V_35 [ 0 ] )
goto V_59;
V_3 = F_25 ( V_3 , V_7 ) ;
if ( * V_3 == '\n' )
V_3 ++ ;
if ( V_3 != V_15 + V_50 )
goto V_59;
return V_7 ;
V_54:
return F_30 ( V_52 ) ;
V_57:
F_31 ( V_7 ) ;
return F_30 ( - V_60 ) ;
V_59:
F_31 ( V_7 ) ;
return F_30 ( - V_53 ) ;
}
static int F_32 ( const char T_2 * V_49 , T_3 V_50 )
{
char V_9 [ 4 ] ;
if ( ! V_50 )
return 0 ;
if ( V_50 > 3 )
return - V_53 ;
if ( F_28 ( V_9 , V_49 , V_50 ) )
return - V_60 ;
if ( V_9 [ V_50 - 1 ] == '\n' )
V_50 -- ;
if ( V_50 == 1 && V_9 [ 0 ] == '0' )
return 1 ;
if ( V_50 == 1 && V_9 [ 0 ] == '1' )
return 2 ;
if ( V_50 == 2 && V_9 [ 0 ] == '-' && V_9 [ 1 ] == '1' )
return 3 ;
return - V_53 ;
}
static void F_33 ( T_1 * V_7 , char * V_61 )
{
char * V_62 ;
char * V_63 = L_3 ;
const char * V_12 = L_4 ;
if ( F_4 ( V_11 , & V_7 -> V_12 ) )
V_63 = L_5 ;
if ( ! V_64 ) {
sprintf ( V_61 , L_6 , V_63 ) ;
return;
}
sprintf ( V_61 , L_7 , V_63 , V_7 -> V_35 ) ;
V_62 = V_61 + strlen ( V_61 ) ;
sprintf ( V_62 , L_8 , V_12 ) ;
V_62 += strlen ( V_12 ) ;
if ( V_7 -> V_12 & V_36 ) {
* V_62 ++ = 'P' ;
}
if ( V_7 -> V_12 & V_37 ) {
* V_62 ++ = 'O' ;
}
if ( V_7 -> V_12 & V_43 ) {
* V_62 ++ = 'C' ;
}
* V_62 ++ = '\n' ;
if ( ! F_4 ( V_13 , & V_7 -> V_12 ) ) {
sprintf ( V_62 , L_9 , V_7 -> V_14 ) ;
} else {
int V_65 ;
sprintf ( V_62 , L_10 , V_7 -> V_16 ) ;
V_62 = V_61 + strlen ( V_61 ) ;
for ( V_65 = 0 ; V_65 < V_7 -> V_18 ; V_65 ++ ) {
sprintf ( V_62 , L_11 , 0xff & ( int ) ( V_7 -> V_14 [ V_65 ] ) ) ;
V_62 += 2 ;
}
if ( V_7 -> V_17 ) {
sprintf ( V_62 , L_12 ) ;
V_62 += 6 ;
for ( V_65 = 0 ; V_65 < V_7 -> V_18 ; V_65 ++ ) {
sprintf ( V_62 , L_11 , 0xff & ( int ) ( V_7 -> V_17 [ V_65 ] ) ) ;
V_62 += 2 ;
}
}
* V_62 ++ = '\n' ;
* V_62 = '\0' ;
}
}
static struct V_66 * F_34 ( struct V_67 * V_68 , int V_69 )
{
struct V_66 * V_66 = F_35 ( V_68 ) ;
if ( V_66 ) {
V_66 -> V_70 = F_36 () ;
V_66 -> V_71 = V_69 ;
V_66 -> V_72 = V_66 -> V_73 = V_66 -> V_74 =
F_37 ( V_66 -> V_75 ) ;
}
return V_66 ;
}
static void F_38 ( struct V_66 * V_66 )
{
F_39 ( V_66 ) ;
F_31 ( V_66 -> V_76 ) ;
}
static void F_40 ( T_1 * V_7 )
{
struct V_77 * V_77 ;
F_41 ( & V_34 ) ;
V_77 = V_7 -> V_77 ;
if ( V_77 ) {
F_42 ( & V_7 -> V_8 ) ;
V_7 -> V_77 = NULL ;
}
F_43 ( & V_34 ) ;
if ( V_77 ) {
V_77 -> V_78 -> V_79 -- ;
F_44 ( V_77 ) ;
F_45 ( V_77 ) ;
F_46 ( & V_80 , & V_81 ) ;
}
}
static T_4
F_47 ( struct V_22 * V_22 , char T_2 * V_15 , T_3 V_82 , T_5 * V_83 )
{
T_1 * V_7 = V_22 -> V_84 . V_77 -> V_78 -> V_76 ;
T_4 V_85 ;
char * V_61 ;
if ( ! ( V_61 = ( char * ) F_48 ( V_86 ) ) )
return - V_55 ;
F_33 ( V_7 , V_61 ) ;
V_85 = F_49 ( V_15 , V_82 , V_83 , V_61 , strlen ( V_61 ) ) ;
F_50 ( ( unsigned long ) V_61 ) ;
return V_85 ;
}
static T_4 F_51 ( struct V_22 * V_22 , const char T_2 * V_49 ,
T_3 V_50 , T_5 * V_83 )
{
struct V_77 * V_87 ;
T_1 * V_7 = V_22 -> V_84 . V_77 -> V_78 -> V_76 ;
int V_85 = F_32 ( V_49 , V_50 ) ;
switch ( V_85 ) {
case 1 : F_52 ( V_11 , & V_7 -> V_12 ) ;
break;
case 2 : F_53 ( V_11 , & V_7 -> V_12 ) ;
break;
case 3 : V_87 = F_54 ( V_22 -> V_84 . V_88 -> V_89 -> V_90 ) ;
F_55 ( & V_87 -> V_78 -> V_91 ) ;
F_40 ( V_7 ) ;
F_56 ( & V_87 -> V_78 -> V_91 ) ;
F_45 ( V_87 ) ;
break;
default: return V_85 ;
}
return V_50 ;
}
static T_4 F_57 ( struct V_22 * V_22 , const char T_2 * V_49 ,
T_3 V_50 , T_5 * V_83 )
{
T_1 * V_7 ;
struct V_66 * V_66 ;
struct V_77 * V_87 , * V_77 ;
struct V_67 * V_68 = V_22 -> V_84 . V_88 -> V_89 ;
int V_52 = 0 ;
V_7 = F_26 ( V_49 , V_50 ) ;
if ( F_18 ( V_7 ) )
return F_17 ( V_7 ) ;
V_87 = F_54 ( V_68 -> V_90 ) ;
F_55 ( & V_87 -> V_78 -> V_91 ) ;
V_77 = F_58 ( V_7 -> V_58 , V_87 , strlen ( V_7 -> V_58 ) ) ;
V_52 = F_17 ( V_77 ) ;
if ( F_18 ( V_77 ) )
goto V_54;
V_52 = - V_92 ;
if ( V_77 -> V_78 )
goto V_93;
V_66 = F_34 ( V_68 , V_94 | 0644 ) ;
V_52 = - V_55 ;
if ( ! V_66 )
goto V_93;
V_52 = F_59 ( & V_95 , & V_80 , & V_81 ) ;
if ( V_52 ) {
F_60 ( V_66 ) ;
V_66 = NULL ;
goto V_93;
}
V_7 -> V_77 = F_54 ( V_77 ) ;
V_66 -> V_76 = V_7 ;
V_66 -> V_96 = & V_97 ;
F_61 ( V_77 , V_66 ) ;
F_41 ( & V_34 ) ;
F_62 ( & V_7 -> V_8 , & V_98 ) ;
F_43 ( & V_34 ) ;
V_52 = 0 ;
V_93:
F_45 ( V_77 ) ;
V_54:
F_56 ( & V_87 -> V_78 -> V_91 ) ;
F_45 ( V_87 ) ;
if ( V_52 ) {
F_31 ( V_7 ) ;
return - V_53 ;
}
return V_50 ;
}
static T_4
F_63 ( struct V_22 * V_22 , char T_2 * V_15 , T_3 V_82 , T_5 * V_83 )
{
char * V_9 = V_30 ? L_13 : L_14 ;
return F_49 ( V_15 , V_82 , V_83 , V_9 , strlen ( V_9 ) ) ;
}
static T_4 F_64 ( struct V_22 * V_22 , const char T_2 * V_49 ,
T_3 V_50 , T_5 * V_83 )
{
int V_85 = F_32 ( V_49 , V_50 ) ;
struct V_77 * V_87 ;
switch ( V_85 ) {
case 1 : V_30 = 0 ; break;
case 2 : V_30 = 1 ; break;
case 3 : V_87 = F_54 ( V_22 -> V_84 . V_88 -> V_89 -> V_90 ) ;
F_55 ( & V_87 -> V_78 -> V_91 ) ;
while ( ! F_65 ( & V_98 ) )
F_40 ( F_3 ( V_98 . V_99 , T_1 , V_8 ) ) ;
F_56 ( & V_87 -> V_78 -> V_91 ) ;
F_45 ( V_87 ) ;
default: return V_85 ;
}
return V_50 ;
}
static int F_66 ( struct V_67 * V_68 , void * V_100 , int V_101 )
{
static struct V_102 V_103 [] = {
[ 2 ] = { L_15 , & V_104 , V_105 | V_106 } ,
[ 3 ] = { L_16 , & V_107 , V_105 } ,
{ L_17 }
} ;
int V_52 = F_67 ( V_68 , 0x42494e4d , V_103 ) ;
if ( ! V_52 )
V_68 -> V_108 = & V_109 ;
return V_52 ;
}
static struct V_77 * F_68 ( struct V_110 * V_111 ,
int V_12 , const char * V_112 , void * V_100 )
{
return F_69 ( V_111 , V_12 , V_100 , F_66 ) ;
}
static int T_6 F_70 ( void )
{
int V_52 = F_71 ( & V_95 ) ;
if ( ! V_52 ) {
V_52 = F_72 ( & V_113 ) ;
if ( V_52 )
F_73 ( & V_95 ) ;
}
return V_52 ;
}
static void T_7 F_74 ( void )
{
F_75 ( & V_113 ) ;
F_73 ( & V_95 ) ;
}
