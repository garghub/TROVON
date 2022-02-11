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
if ( ( V_45 < 11 ) || ( V_45 > V_49 ) )
goto V_50;
V_47 = - V_51 ;
V_46 = sizeof( T_1 ) + V_45 + 8 ;
V_7 = F_27 ( V_46 , V_52 ) ;
if ( ! V_7 )
goto V_50;
V_3 = V_15 = ( char * ) V_7 + sizeof( T_1 ) ;
memset ( V_7 , 0 , sizeof( T_1 ) ) ;
if ( F_28 ( V_15 , V_44 , V_45 ) )
goto V_53;
V_40 = * V_3 ++ ;
memset ( V_15 + V_45 , V_40 , 8 ) ;
V_7 -> V_54 = V_3 ;
V_3 = strchr ( V_3 , V_40 ) ;
if ( ! V_3 )
goto V_55;
* V_3 ++ = '\0' ;
if ( ! V_7 -> V_54 [ 0 ] ||
! strcmp ( V_7 -> V_54 , L_1 ) ||
! strcmp ( V_7 -> V_54 , L_2 ) ||
strchr ( V_7 -> V_54 , '/' ) )
goto V_55;
switch ( * V_3 ++ ) {
case 'E' : V_7 -> V_12 = 1 << V_11 ; break;
case 'M' : V_7 -> V_12 = ( 1 << V_11 ) | ( 1 << V_13 ) ; break;
default: goto V_55;
}
if ( * V_3 ++ != V_40 )
goto V_55;
if ( F_4 ( V_13 , & V_7 -> V_12 ) ) {
char * V_9 = strchr ( V_3 , V_40 ) ;
if ( ! V_9 )
goto V_55;
* V_9 ++ = '\0' ;
V_7 -> V_16 = F_29 ( V_3 , & V_3 , 10 ) ;
if ( * V_3 ++ )
goto V_55;
V_7 -> V_14 = V_3 ;
V_3 = F_24 ( V_3 , V_40 ) ;
if ( ! V_3 )
goto V_55;
V_3 [ - 1 ] = '\0' ;
if ( ! V_7 -> V_14 [ 0 ] )
goto V_55;
V_7 -> V_17 = V_3 ;
V_3 = F_24 ( V_3 , V_40 ) ;
if ( ! V_3 )
goto V_55;
V_3 [ - 1 ] = '\0' ;
if ( ! V_7 -> V_17 [ 0 ] )
V_7 -> V_17 = NULL ;
V_7 -> V_18 = F_30 ( V_7 -> V_14 , V_56 ) ;
if ( V_7 -> V_17 &&
F_30 ( V_7 -> V_17 , V_56 ) != V_7 -> V_18 )
goto V_55;
if ( V_7 -> V_18 + V_7 -> V_16 > V_23 )
goto V_55;
} else {
V_3 = strchr ( V_3 , V_40 ) ;
if ( ! V_3 )
goto V_55;
* V_3 ++ = '\0' ;
V_7 -> V_14 = V_3 ;
V_3 = strchr ( V_3 , V_40 ) ;
if ( ! V_3 )
goto V_55;
* V_3 ++ = '\0' ;
if ( ! V_7 -> V_14 [ 0 ] || strchr ( V_7 -> V_14 , '/' ) )
goto V_55;
V_3 = strchr ( V_3 , V_40 ) ;
if ( ! V_3 )
goto V_55;
* V_3 ++ = '\0' ;
}
V_7 -> V_31 = V_3 ;
V_3 = strchr ( V_3 , V_40 ) ;
if ( ! V_3 )
goto V_55;
* V_3 ++ = '\0' ;
if ( ! V_7 -> V_31 [ 0 ] )
goto V_55;
V_3 = F_25 ( V_3 , V_7 ) ;
if ( * V_3 == '\n' )
V_3 ++ ;
if ( V_3 != V_15 + V_45 )
goto V_55;
return V_7 ;
V_50:
return F_31 ( V_47 ) ;
V_53:
F_32 ( V_7 ) ;
return F_31 ( - V_57 ) ;
V_55:
F_32 ( V_7 ) ;
return F_31 ( - V_48 ) ;
}
static int F_33 ( const char T_2 * V_44 , T_3 V_45 )
{
char V_9 [ 4 ] ;
if ( V_45 > 3 )
return - V_48 ;
if ( F_28 ( V_9 , V_44 , V_45 ) )
return - V_57 ;
if ( ! V_45 )
return 0 ;
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
static void F_34 ( T_1 * V_7 , char * V_58 )
{
char * V_59 ;
char * V_60 = L_3 ;
const char * V_12 = L_4 ;
if ( F_4 ( V_11 , & V_7 -> V_12 ) )
V_60 = L_5 ;
if ( ! V_61 ) {
sprintf ( V_58 , L_6 , V_60 ) ;
return;
}
sprintf ( V_58 , L_7 , V_60 , V_7 -> V_31 ) ;
V_59 = V_58 + strlen ( V_58 ) ;
sprintf ( V_59 , L_8 , V_12 ) ;
V_59 += strlen ( V_12 ) ;
if ( V_7 -> V_12 & V_32 ) {
* V_59 ++ = 'P' ;
}
if ( V_7 -> V_12 & V_33 ) {
* V_59 ++ = 'O' ;
}
if ( V_7 -> V_12 & V_39 ) {
* V_59 ++ = 'C' ;
}
* V_59 ++ = '\n' ;
if ( ! F_4 ( V_13 , & V_7 -> V_12 ) ) {
sprintf ( V_59 , L_9 , V_7 -> V_14 ) ;
} else {
int V_62 ;
sprintf ( V_59 , L_10 , V_7 -> V_16 ) ;
V_59 = V_58 + strlen ( V_58 ) ;
for ( V_62 = 0 ; V_62 < V_7 -> V_18 ; V_62 ++ ) {
sprintf ( V_59 , L_11 , 0xff & ( int ) ( V_7 -> V_14 [ V_62 ] ) ) ;
V_59 += 2 ;
}
if ( V_7 -> V_17 ) {
sprintf ( V_59 , L_12 ) ;
V_59 += 6 ;
for ( V_62 = 0 ; V_62 < V_7 -> V_18 ; V_62 ++ ) {
sprintf ( V_59 , L_11 , 0xff & ( int ) ( V_7 -> V_17 [ V_62 ] ) ) ;
V_59 += 2 ;
}
}
* V_59 ++ = '\n' ;
* V_59 = '\0' ;
}
}
static struct V_63 * F_35 ( struct V_64 * V_65 , int V_66 )
{
struct V_63 * V_63 = F_36 ( V_65 ) ;
if ( V_63 ) {
V_63 -> V_67 = F_37 () ;
V_63 -> V_68 = V_66 ;
V_63 -> V_69 = V_63 -> V_70 = V_63 -> V_71 =
F_38 ( V_63 -> V_72 ) ;
}
return V_63 ;
}
static void F_39 ( struct V_63 * V_63 )
{
F_40 ( V_63 ) ;
F_32 ( V_63 -> V_73 ) ;
}
static void F_41 ( T_1 * V_7 )
{
struct V_74 * V_74 ;
F_42 ( & V_30 ) ;
V_74 = V_7 -> V_74 ;
if ( V_74 ) {
F_43 ( & V_7 -> V_8 ) ;
V_7 -> V_74 = NULL ;
}
F_44 ( & V_30 ) ;
if ( V_74 ) {
F_45 ( V_74 -> V_75 ) ;
F_46 ( V_74 ) ;
F_47 ( V_74 ) ;
F_48 ( & V_76 , & V_77 ) ;
}
}
static T_4
F_49 ( struct V_20 * V_20 , char T_2 * V_15 , T_3 V_78 , T_5 * V_79 )
{
T_1 * V_7 = F_50 ( V_20 ) -> V_73 ;
T_4 V_80 ;
char * V_58 ;
if ( ! ( V_58 = ( char * ) F_51 ( V_81 ) ) )
return - V_51 ;
F_34 ( V_7 , V_58 ) ;
V_80 = F_52 ( V_15 , V_78 , V_79 , V_58 , strlen ( V_58 ) ) ;
F_53 ( ( unsigned long ) V_58 ) ;
return V_80 ;
}
static T_4 F_54 ( struct V_20 * V_20 , const char T_2 * V_44 ,
T_3 V_45 , T_5 * V_79 )
{
struct V_74 * V_82 ;
T_1 * V_7 = F_50 ( V_20 ) -> V_73 ;
int V_80 = F_33 ( V_44 , V_45 ) ;
switch ( V_80 ) {
case 1 : F_55 ( V_11 , & V_7 -> V_12 ) ;
break;
case 2 : F_56 ( V_11 , & V_7 -> V_12 ) ;
break;
case 3 : V_82 = F_57 ( V_20 -> V_83 . V_74 -> V_84 -> V_85 ) ;
F_58 ( & V_82 -> V_75 -> V_86 ) ;
F_41 ( V_7 ) ;
F_59 ( & V_82 -> V_75 -> V_86 ) ;
F_47 ( V_82 ) ;
break;
default: return V_80 ;
}
return V_45 ;
}
static T_4 F_60 ( struct V_20 * V_20 , const char T_2 * V_44 ,
T_3 V_45 , T_5 * V_79 )
{
T_1 * V_7 ;
struct V_63 * V_63 ;
struct V_74 * V_82 , * V_74 ;
struct V_64 * V_65 = V_20 -> V_83 . V_74 -> V_84 ;
int V_47 = 0 ;
V_7 = F_26 ( V_44 , V_45 ) ;
if ( F_19 ( V_7 ) )
return F_18 ( V_7 ) ;
V_82 = F_57 ( V_65 -> V_85 ) ;
F_58 ( & V_82 -> V_75 -> V_86 ) ;
V_74 = F_61 ( V_7 -> V_54 , V_82 , strlen ( V_7 -> V_54 ) ) ;
V_47 = F_18 ( V_74 ) ;
if ( F_19 ( V_74 ) )
goto V_50;
V_47 = - V_87 ;
if ( V_74 -> V_75 )
goto V_88;
V_63 = F_35 ( V_65 , V_89 | 0644 ) ;
V_47 = - V_51 ;
if ( ! V_63 )
goto V_88;
V_47 = F_62 ( & V_90 , & V_76 , & V_77 ) ;
if ( V_47 ) {
F_63 ( V_63 ) ;
V_63 = NULL ;
goto V_88;
}
V_7 -> V_74 = F_57 ( V_74 ) ;
V_63 -> V_73 = V_7 ;
V_63 -> V_91 = & V_92 ;
F_64 ( V_74 , V_63 ) ;
F_42 ( & V_30 ) ;
F_65 ( & V_7 -> V_8 , & V_93 ) ;
F_44 ( & V_30 ) ;
V_47 = 0 ;
V_88:
F_47 ( V_74 ) ;
V_50:
F_59 ( & V_82 -> V_75 -> V_86 ) ;
F_47 ( V_82 ) ;
if ( V_47 ) {
F_32 ( V_7 ) ;
return - V_48 ;
}
return V_45 ;
}
static T_4
F_66 ( struct V_20 * V_20 , char T_2 * V_15 , T_3 V_78 , T_5 * V_79 )
{
char * V_9 = V_28 ? L_13 : L_14 ;
return F_52 ( V_15 , V_78 , V_79 , V_9 , strlen ( V_9 ) ) ;
}
static T_4 F_67 ( struct V_20 * V_20 , const char T_2 * V_44 ,
T_3 V_45 , T_5 * V_79 )
{
int V_80 = F_33 ( V_44 , V_45 ) ;
struct V_74 * V_82 ;
switch ( V_80 ) {
case 1 : V_28 = 0 ; break;
case 2 : V_28 = 1 ; break;
case 3 : V_82 = F_57 ( V_20 -> V_83 . V_74 -> V_84 -> V_85 ) ;
F_58 ( & V_82 -> V_75 -> V_86 ) ;
while ( ! F_68 ( & V_93 ) )
F_41 ( F_3 ( V_93 . V_94 , T_1 , V_8 ) ) ;
F_59 ( & V_82 -> V_75 -> V_86 ) ;
F_47 ( V_82 ) ;
break;
default: return V_80 ;
}
return V_45 ;
}
static int F_69 ( struct V_64 * V_65 , void * V_95 , int V_96 )
{
static struct V_97 V_98 [] = {
[ 2 ] = { L_15 , & V_99 , V_100 | V_101 } ,
[ 3 ] = { L_16 , & V_102 , V_100 } ,
{ L_17 }
} ;
int V_47 = F_70 ( V_65 , V_103 , V_98 ) ;
if ( ! V_47 )
V_65 -> V_104 = & V_105 ;
return V_47 ;
}
static struct V_74 * F_71 ( struct V_106 * V_107 ,
int V_12 , const char * V_108 , void * V_95 )
{
return F_72 ( V_107 , V_12 , V_95 , F_69 ) ;
}
static int T_6 F_73 ( void )
{
int V_47 = F_74 ( & V_90 ) ;
if ( ! V_47 )
F_75 ( & V_109 ) ;
return V_47 ;
}
static void T_7 F_76 ( void )
{
F_77 ( & V_109 ) ;
F_78 ( & V_90 ) ;
}
