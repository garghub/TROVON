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
static int F_5 ( struct V_1 * V_2 )
{
T_1 * V_19 ;
struct V_20 * V_21 = NULL ;
char V_22 [ V_23 ] ;
const char * V_24 = V_22 ;
int V_25 ;
int V_26 = - 1 ;
V_25 = - V_27 ;
if ( ! V_28 )
goto V_29;
F_6 ( & V_30 ) ;
V_19 = F_1 ( V_2 ) ;
if ( V_19 )
F_7 ( V_22 , V_19 -> V_31 , V_23 ) ;
F_8 ( & V_30 ) ;
if ( ! V_19 )
goto V_29;
if ( ! ( V_19 -> V_12 & V_32 ) ) {
V_25 = F_9 ( V_2 ) ;
if ( V_25 )
goto V_29;
}
if ( V_19 -> V_12 & V_33 ) {
V_26 = F_10 () ;
if ( V_26 < 0 ) {
V_25 = V_26 ;
goto V_29;
}
F_11 ( V_26 , V_2 -> V_20 ) ;
F_12 ( V_2 , V_2 -> V_20 ) ;
F_13 ( V_2 -> V_20 ) ;
V_2 -> V_20 = NULL ;
V_2 -> V_34 |= V_35 ;
V_2 -> V_36 = V_26 ;
} else {
F_13 ( V_2 -> V_20 ) ;
F_14 ( V_2 -> V_20 ) ;
V_2 -> V_20 = NULL ;
}
V_25 = F_15 ( 1 , & V_2 -> V_4 , V_2 ) ;
if ( V_25 < 0 )
goto V_37;
V_2 -> V_38 ++ ;
V_25 = F_15 ( 1 , & V_24 , V_2 ) ;
if ( V_25 < 0 )
goto V_37;
V_2 -> V_38 ++ ;
V_25 = F_16 ( V_22 , V_2 ) ;
if ( V_25 < 0 )
goto V_37;
V_21 = F_17 ( V_22 ) ;
V_25 = F_18 ( V_21 ) ;
if ( F_19 ( V_21 ) )
goto V_37;
V_2 -> V_20 = V_21 ;
if ( V_19 -> V_12 & V_39 ) {
memset ( V_2 -> V_15 , 0 , V_23 ) ;
V_25 = F_20 ( V_2 -> V_20 , 0 , V_2 -> V_15 , V_23 ) ;
} else
V_25 = F_21 ( V_2 ) ;
if ( V_25 < 0 )
goto V_37;
V_25 = F_22 ( V_2 ) ;
if ( V_25 < 0 )
goto V_37;
V_29:
return V_25 ;
V_37:
if ( V_26 > 0 )
F_23 ( V_26 ) ;
V_2 -> V_34 = 0 ;
V_2 -> V_36 = 0 ;
goto V_29;
}
static char * F_24 ( char * V_9 , char V_40 )
{
char V_41 ;
while ( ( V_41 = * V_9 ++ ) != V_40 ) {
if ( V_41 == '\\' && * V_9 == 'x' ) {
V_9 ++ ;
if ( ! isxdigit ( * V_9 ++ ) )
return NULL ;
if ( ! isxdigit ( * V_9 ++ ) )
return NULL ;
}
}
return V_9 ;
}
static char * F_25 ( char * V_42 , T_1 * V_7 )
{
char * V_3 = V_42 ;
int V_43 = 1 ;
while ( V_43 ) {
switch ( * V_3 ) {
case 'P' :
V_3 ++ ;
V_7 -> V_12 |= V_32 ;
break;
case 'O' :
V_3 ++ ;
V_7 -> V_12 |= V_33 ;
break;
case 'C' :
V_3 ++ ;
V_7 -> V_12 |= ( V_39 |
V_33 ) ;
break;
default:
V_43 = 0 ;
}
}
return V_3 ;
}
static T_1 * F_26 ( const char T_2 * V_44 , T_3 V_45 )
{
T_1 * V_7 ;
int V_46 , V_47 ;
char * V_15 , * V_3 ;
char V_40 ;
V_47 = - V_48 ;
if ( ( V_45 < 11 ) || ( V_45 > 256 ) )
goto V_49;
V_47 = - V_50 ;
V_46 = sizeof( T_1 ) + V_45 + 8 ;
V_7 = F_27 ( V_46 , V_51 ) ;
if ( ! V_7 )
goto V_49;
V_3 = V_15 = ( char * ) V_7 + sizeof( T_1 ) ;
memset ( V_7 , 0 , sizeof( T_1 ) ) ;
if ( F_28 ( V_15 , V_44 , V_45 ) )
goto V_52;
V_40 = * V_3 ++ ;
memset ( V_15 + V_45 , V_40 , 8 ) ;
V_7 -> V_53 = V_3 ;
V_3 = strchr ( V_3 , V_40 ) ;
if ( ! V_3 )
goto V_54;
* V_3 ++ = '\0' ;
if ( ! V_7 -> V_53 [ 0 ] ||
! strcmp ( V_7 -> V_53 , L_1 ) ||
! strcmp ( V_7 -> V_53 , L_2 ) ||
strchr ( V_7 -> V_53 , '/' ) )
goto V_54;
switch ( * V_3 ++ ) {
case 'E' : V_7 -> V_12 = 1 << V_11 ; break;
case 'M' : V_7 -> V_12 = ( 1 << V_11 ) | ( 1 << V_13 ) ; break;
default: goto V_54;
}
if ( * V_3 ++ != V_40 )
goto V_54;
if ( F_4 ( V_13 , & V_7 -> V_12 ) ) {
char * V_9 = strchr ( V_3 , V_40 ) ;
if ( ! V_9 )
goto V_54;
* V_9 ++ = '\0' ;
V_7 -> V_16 = F_29 ( V_3 , & V_3 , 10 ) ;
if ( * V_3 ++ )
goto V_54;
V_7 -> V_14 = V_3 ;
V_3 = F_24 ( V_3 , V_40 ) ;
if ( ! V_3 )
goto V_54;
V_3 [ - 1 ] = '\0' ;
if ( ! V_7 -> V_14 [ 0 ] )
goto V_54;
V_7 -> V_17 = V_3 ;
V_3 = F_24 ( V_3 , V_40 ) ;
if ( ! V_3 )
goto V_54;
V_3 [ - 1 ] = '\0' ;
if ( ! V_7 -> V_17 [ 0 ] )
V_7 -> V_17 = NULL ;
V_7 -> V_18 = F_30 ( V_7 -> V_14 , V_55 ) ;
if ( V_7 -> V_17 &&
F_30 ( V_7 -> V_17 , V_55 ) != V_7 -> V_18 )
goto V_54;
if ( V_7 -> V_18 + V_7 -> V_16 > V_23 )
goto V_54;
} else {
V_3 = strchr ( V_3 , V_40 ) ;
if ( ! V_3 )
goto V_54;
* V_3 ++ = '\0' ;
V_7 -> V_14 = V_3 ;
V_3 = strchr ( V_3 , V_40 ) ;
if ( ! V_3 )
goto V_54;
* V_3 ++ = '\0' ;
if ( ! V_7 -> V_14 [ 0 ] || strchr ( V_7 -> V_14 , '/' ) )
goto V_54;
V_3 = strchr ( V_3 , V_40 ) ;
if ( ! V_3 )
goto V_54;
* V_3 ++ = '\0' ;
}
V_7 -> V_31 = V_3 ;
V_3 = strchr ( V_3 , V_40 ) ;
if ( ! V_3 )
goto V_54;
* V_3 ++ = '\0' ;
if ( ! V_7 -> V_31 [ 0 ] )
goto V_54;
V_3 = F_25 ( V_3 , V_7 ) ;
if ( * V_3 == '\n' )
V_3 ++ ;
if ( V_3 != V_15 + V_45 )
goto V_54;
return V_7 ;
V_49:
return F_31 ( V_47 ) ;
V_52:
F_32 ( V_7 ) ;
return F_31 ( - V_56 ) ;
V_54:
F_32 ( V_7 ) ;
return F_31 ( - V_48 ) ;
}
static int F_33 ( const char T_2 * V_44 , T_3 V_45 )
{
char V_9 [ 4 ] ;
if ( ! V_45 )
return 0 ;
if ( V_45 > 3 )
return - V_48 ;
if ( F_28 ( V_9 , V_44 , V_45 ) )
return - V_56 ;
if ( V_9 [ V_45 - 1 ] == '\n' )
V_45 -- ;
if ( V_45 == 1 && V_9 [ 0 ] == '0' )
return 1 ;
if ( V_45 == 1 && V_9 [ 0 ] == '1' )
return 2 ;
if ( V_45 == 2 && V_9 [ 0 ] == '-' && V_9 [ 1 ] == '1' )
return 3 ;
return - V_48 ;
}
static void F_34 ( T_1 * V_7 , char * V_57 )
{
char * V_58 ;
char * V_59 = L_3 ;
const char * V_12 = L_4 ;
if ( F_4 ( V_11 , & V_7 -> V_12 ) )
V_59 = L_5 ;
if ( ! V_60 ) {
sprintf ( V_57 , L_6 , V_59 ) ;
return;
}
sprintf ( V_57 , L_7 , V_59 , V_7 -> V_31 ) ;
V_58 = V_57 + strlen ( V_57 ) ;
sprintf ( V_58 , L_8 , V_12 ) ;
V_58 += strlen ( V_12 ) ;
if ( V_7 -> V_12 & V_32 ) {
* V_58 ++ = 'P' ;
}
if ( V_7 -> V_12 & V_33 ) {
* V_58 ++ = 'O' ;
}
if ( V_7 -> V_12 & V_39 ) {
* V_58 ++ = 'C' ;
}
* V_58 ++ = '\n' ;
if ( ! F_4 ( V_13 , & V_7 -> V_12 ) ) {
sprintf ( V_58 , L_9 , V_7 -> V_14 ) ;
} else {
int V_61 ;
sprintf ( V_58 , L_10 , V_7 -> V_16 ) ;
V_58 = V_57 + strlen ( V_57 ) ;
for ( V_61 = 0 ; V_61 < V_7 -> V_18 ; V_61 ++ ) {
sprintf ( V_58 , L_11 , 0xff & ( int ) ( V_7 -> V_14 [ V_61 ] ) ) ;
V_58 += 2 ;
}
if ( V_7 -> V_17 ) {
sprintf ( V_58 , L_12 ) ;
V_58 += 6 ;
for ( V_61 = 0 ; V_61 < V_7 -> V_18 ; V_61 ++ ) {
sprintf ( V_58 , L_11 , 0xff & ( int ) ( V_7 -> V_17 [ V_61 ] ) ) ;
V_58 += 2 ;
}
}
* V_58 ++ = '\n' ;
* V_58 = '\0' ;
}
}
static struct V_62 * F_35 ( struct V_63 * V_64 , int V_65 )
{
struct V_62 * V_62 = F_36 ( V_64 ) ;
if ( V_62 ) {
V_62 -> V_66 = F_37 () ;
V_62 -> V_67 = V_65 ;
V_62 -> V_68 = V_62 -> V_69 = V_62 -> V_70 =
F_38 ( V_62 -> V_71 ) ;
}
return V_62 ;
}
static void F_39 ( struct V_62 * V_62 )
{
F_40 ( V_62 ) ;
F_32 ( V_62 -> V_72 ) ;
}
static void F_41 ( T_1 * V_7 )
{
struct V_73 * V_73 ;
F_42 ( & V_30 ) ;
V_73 = V_7 -> V_73 ;
if ( V_73 ) {
F_43 ( & V_7 -> V_8 ) ;
V_7 -> V_73 = NULL ;
}
F_44 ( & V_30 ) ;
if ( V_73 ) {
F_45 ( V_73 -> V_74 ) ;
F_46 ( V_73 ) ;
F_47 ( V_73 ) ;
F_48 ( & V_75 , & V_76 ) ;
}
}
static T_4
F_49 ( struct V_20 * V_20 , char T_2 * V_15 , T_3 V_77 , T_5 * V_78 )
{
T_1 * V_7 = F_50 ( V_20 ) -> V_72 ;
T_4 V_79 ;
char * V_57 ;
if ( ! ( V_57 = ( char * ) F_51 ( V_80 ) ) )
return - V_50 ;
F_34 ( V_7 , V_57 ) ;
V_79 = F_52 ( V_15 , V_77 , V_78 , V_57 , strlen ( V_57 ) ) ;
F_53 ( ( unsigned long ) V_57 ) ;
return V_79 ;
}
static T_4 F_54 ( struct V_20 * V_20 , const char T_2 * V_44 ,
T_3 V_45 , T_5 * V_78 )
{
struct V_73 * V_81 ;
T_1 * V_7 = F_50 ( V_20 ) -> V_72 ;
int V_79 = F_33 ( V_44 , V_45 ) ;
switch ( V_79 ) {
case 1 : F_55 ( V_11 , & V_7 -> V_12 ) ;
break;
case 2 : F_56 ( V_11 , & V_7 -> V_12 ) ;
break;
case 3 : V_81 = F_57 ( V_20 -> V_82 . V_73 -> V_83 -> V_84 ) ;
F_58 ( & V_81 -> V_74 -> V_85 ) ;
F_41 ( V_7 ) ;
F_59 ( & V_81 -> V_74 -> V_85 ) ;
F_47 ( V_81 ) ;
break;
default: return V_79 ;
}
return V_45 ;
}
static T_4 F_60 ( struct V_20 * V_20 , const char T_2 * V_44 ,
T_3 V_45 , T_5 * V_78 )
{
T_1 * V_7 ;
struct V_62 * V_62 ;
struct V_73 * V_81 , * V_73 ;
struct V_63 * V_64 = V_20 -> V_82 . V_73 -> V_83 ;
int V_47 = 0 ;
V_7 = F_26 ( V_44 , V_45 ) ;
if ( F_19 ( V_7 ) )
return F_18 ( V_7 ) ;
V_81 = F_57 ( V_64 -> V_84 ) ;
F_58 ( & V_81 -> V_74 -> V_85 ) ;
V_73 = F_61 ( V_7 -> V_53 , V_81 , strlen ( V_7 -> V_53 ) ) ;
V_47 = F_18 ( V_73 ) ;
if ( F_19 ( V_73 ) )
goto V_49;
V_47 = - V_86 ;
if ( V_73 -> V_74 )
goto V_87;
V_62 = F_35 ( V_64 , V_88 | 0644 ) ;
V_47 = - V_50 ;
if ( ! V_62 )
goto V_87;
V_47 = F_62 ( & V_89 , & V_75 , & V_76 ) ;
if ( V_47 ) {
F_63 ( V_62 ) ;
V_62 = NULL ;
goto V_87;
}
V_7 -> V_73 = F_57 ( V_73 ) ;
V_62 -> V_72 = V_7 ;
V_62 -> V_90 = & V_91 ;
F_64 ( V_73 , V_62 ) ;
F_42 ( & V_30 ) ;
F_65 ( & V_7 -> V_8 , & V_92 ) ;
F_44 ( & V_30 ) ;
V_47 = 0 ;
V_87:
F_47 ( V_73 ) ;
V_49:
F_59 ( & V_81 -> V_74 -> V_85 ) ;
F_47 ( V_81 ) ;
if ( V_47 ) {
F_32 ( V_7 ) ;
return - V_48 ;
}
return V_45 ;
}
static T_4
F_66 ( struct V_20 * V_20 , char T_2 * V_15 , T_3 V_77 , T_5 * V_78 )
{
char * V_9 = V_28 ? L_13 : L_14 ;
return F_52 ( V_15 , V_77 , V_78 , V_9 , strlen ( V_9 ) ) ;
}
static T_4 F_67 ( struct V_20 * V_20 , const char T_2 * V_44 ,
T_3 V_45 , T_5 * V_78 )
{
int V_79 = F_33 ( V_44 , V_45 ) ;
struct V_73 * V_81 ;
switch ( V_79 ) {
case 1 : V_28 = 0 ; break;
case 2 : V_28 = 1 ; break;
case 3 : V_81 = F_57 ( V_20 -> V_82 . V_73 -> V_83 -> V_84 ) ;
F_58 ( & V_81 -> V_74 -> V_85 ) ;
while ( ! F_68 ( & V_92 ) )
F_41 ( F_3 ( V_92 . V_93 , T_1 , V_8 ) ) ;
F_59 ( & V_81 -> V_74 -> V_85 ) ;
F_47 ( V_81 ) ;
break;
default: return V_79 ;
}
return V_45 ;
}
static int F_69 ( struct V_63 * V_64 , void * V_94 , int V_95 )
{
static struct V_96 V_97 [] = {
[ 2 ] = { L_15 , & V_98 , V_99 | V_100 } ,
[ 3 ] = { L_16 , & V_101 , V_99 } ,
{ L_17 }
} ;
int V_47 = F_70 ( V_64 , V_102 , V_97 ) ;
if ( ! V_47 )
V_64 -> V_103 = & V_104 ;
return V_47 ;
}
static struct V_73 * F_71 ( struct V_105 * V_106 ,
int V_12 , const char * V_107 , void * V_94 )
{
return F_72 ( V_106 , V_12 , V_94 , F_69 ) ;
}
static int T_6 F_73 ( void )
{
int V_47 = F_74 ( & V_89 ) ;
if ( ! V_47 )
F_75 ( & V_108 ) ;
return V_47 ;
}
static void T_7 F_76 ( void )
{
F_77 ( & V_108 ) ;
F_78 ( & V_89 ) ;
}
