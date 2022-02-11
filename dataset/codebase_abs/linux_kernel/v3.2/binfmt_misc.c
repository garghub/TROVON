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
F_44 ( V_77 -> V_78 ) ;
F_45 ( V_77 ) ;
F_46 ( V_77 ) ;
F_47 ( & V_79 , & V_80 ) ;
}
}
static T_4
F_48 ( struct V_22 * V_22 , char T_2 * V_15 , T_3 V_81 , T_5 * V_82 )
{
T_1 * V_7 = V_22 -> V_83 . V_77 -> V_78 -> V_76 ;
T_4 V_84 ;
char * V_61 ;
if ( ! ( V_61 = ( char * ) F_49 ( V_85 ) ) )
return - V_55 ;
F_33 ( V_7 , V_61 ) ;
V_84 = F_50 ( V_15 , V_81 , V_82 , V_61 , strlen ( V_61 ) ) ;
F_51 ( ( unsigned long ) V_61 ) ;
return V_84 ;
}
static T_4 F_52 ( struct V_22 * V_22 , const char T_2 * V_49 ,
T_3 V_50 , T_5 * V_82 )
{
struct V_77 * V_86 ;
T_1 * V_7 = V_22 -> V_83 . V_77 -> V_78 -> V_76 ;
int V_84 = F_32 ( V_49 , V_50 ) ;
switch ( V_84 ) {
case 1 : F_53 ( V_11 , & V_7 -> V_12 ) ;
break;
case 2 : F_54 ( V_11 , & V_7 -> V_12 ) ;
break;
case 3 : V_86 = F_55 ( V_22 -> V_83 . V_87 -> V_88 -> V_89 ) ;
F_56 ( & V_86 -> V_78 -> V_90 ) ;
F_40 ( V_7 ) ;
F_57 ( & V_86 -> V_78 -> V_90 ) ;
F_46 ( V_86 ) ;
break;
default: return V_84 ;
}
return V_50 ;
}
static T_4 F_58 ( struct V_22 * V_22 , const char T_2 * V_49 ,
T_3 V_50 , T_5 * V_82 )
{
T_1 * V_7 ;
struct V_66 * V_66 ;
struct V_77 * V_86 , * V_77 ;
struct V_67 * V_68 = V_22 -> V_83 . V_87 -> V_88 ;
int V_52 = 0 ;
V_7 = F_26 ( V_49 , V_50 ) ;
if ( F_18 ( V_7 ) )
return F_17 ( V_7 ) ;
V_86 = F_55 ( V_68 -> V_89 ) ;
F_56 ( & V_86 -> V_78 -> V_90 ) ;
V_77 = F_59 ( V_7 -> V_58 , V_86 , strlen ( V_7 -> V_58 ) ) ;
V_52 = F_17 ( V_77 ) ;
if ( F_18 ( V_77 ) )
goto V_54;
V_52 = - V_91 ;
if ( V_77 -> V_78 )
goto V_92;
V_66 = F_34 ( V_68 , V_93 | 0644 ) ;
V_52 = - V_55 ;
if ( ! V_66 )
goto V_92;
V_52 = F_60 ( & V_94 , & V_79 , & V_80 ) ;
if ( V_52 ) {
F_61 ( V_66 ) ;
V_66 = NULL ;
goto V_92;
}
V_7 -> V_77 = F_55 ( V_77 ) ;
V_66 -> V_76 = V_7 ;
V_66 -> V_95 = & V_96 ;
F_62 ( V_77 , V_66 ) ;
F_41 ( & V_34 ) ;
F_63 ( & V_7 -> V_8 , & V_97 ) ;
F_43 ( & V_34 ) ;
V_52 = 0 ;
V_92:
F_46 ( V_77 ) ;
V_54:
F_57 ( & V_86 -> V_78 -> V_90 ) ;
F_46 ( V_86 ) ;
if ( V_52 ) {
F_31 ( V_7 ) ;
return - V_53 ;
}
return V_50 ;
}
static T_4
F_64 ( struct V_22 * V_22 , char T_2 * V_15 , T_3 V_81 , T_5 * V_82 )
{
char * V_9 = V_30 ? L_13 : L_14 ;
return F_50 ( V_15 , V_81 , V_82 , V_9 , strlen ( V_9 ) ) ;
}
static T_4 F_65 ( struct V_22 * V_22 , const char T_2 * V_49 ,
T_3 V_50 , T_5 * V_82 )
{
int V_84 = F_32 ( V_49 , V_50 ) ;
struct V_77 * V_86 ;
switch ( V_84 ) {
case 1 : V_30 = 0 ; break;
case 2 : V_30 = 1 ; break;
case 3 : V_86 = F_55 ( V_22 -> V_83 . V_87 -> V_88 -> V_89 ) ;
F_56 ( & V_86 -> V_78 -> V_90 ) ;
while ( ! F_66 ( & V_97 ) )
F_40 ( F_3 ( V_97 . V_98 , T_1 , V_8 ) ) ;
F_57 ( & V_86 -> V_78 -> V_90 ) ;
F_46 ( V_86 ) ;
default: return V_84 ;
}
return V_50 ;
}
static int F_67 ( struct V_67 * V_68 , void * V_99 , int V_100 )
{
static struct V_101 V_102 [] = {
[ 2 ] = { L_15 , & V_103 , V_104 | V_105 } ,
[ 3 ] = { L_16 , & V_106 , V_104 } ,
{ L_17 }
} ;
int V_52 = F_68 ( V_68 , 0x42494e4d , V_102 ) ;
if ( ! V_52 )
V_68 -> V_107 = & V_108 ;
return V_52 ;
}
static struct V_77 * F_69 ( struct V_109 * V_110 ,
int V_12 , const char * V_111 , void * V_99 )
{
return F_70 ( V_110 , V_12 , V_99 , F_67 ) ;
}
static int T_6 F_71 ( void )
{
int V_52 = F_72 ( & V_94 ) ;
if ( ! V_52 ) {
V_52 = F_73 ( & V_112 ) ;
if ( V_52 )
F_74 ( & V_94 ) ;
}
return V_52 ;
}
static void T_7 F_75 ( void )
{
F_76 ( & V_112 ) ;
F_74 ( & V_94 ) ;
}
