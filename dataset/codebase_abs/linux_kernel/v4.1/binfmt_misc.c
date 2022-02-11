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
if ( V_2 -> V_32 & V_33 )
return - V_34 ;
if ( ! ( V_19 -> V_12 & V_35 ) ) {
V_25 = F_9 ( V_2 ) ;
if ( V_25 )
goto V_29;
}
if ( V_19 -> V_12 & V_36 ) {
V_26 = F_10 ( 0 ) ;
if ( V_26 < 0 ) {
V_25 = V_26 ;
goto V_29;
}
F_11 ( V_26 , V_2 -> V_20 ) ;
F_12 ( V_2 , V_2 -> V_20 ) ;
F_13 ( V_2 -> V_20 ) ;
V_2 -> V_20 = NULL ;
V_2 -> V_32 |= V_37 ;
V_2 -> V_38 = V_26 ;
} else {
F_13 ( V_2 -> V_20 ) ;
F_14 ( V_2 -> V_20 ) ;
V_2 -> V_20 = NULL ;
}
V_25 = F_15 ( 1 , & V_2 -> V_4 , V_2 ) ;
if ( V_25 < 0 )
goto error;
V_2 -> V_39 ++ ;
V_25 = F_15 ( 1 , & V_24 , V_2 ) ;
if ( V_25 < 0 )
goto error;
V_2 -> V_39 ++ ;
V_25 = F_16 ( V_22 , V_2 ) ;
if ( V_25 < 0 )
goto error;
V_21 = F_17 ( V_22 ) ;
V_25 = F_18 ( V_21 ) ;
if ( F_19 ( V_21 ) )
goto error;
V_2 -> V_20 = V_21 ;
if ( V_19 -> V_12 & V_40 ) {
memset ( V_2 -> V_15 , 0 , V_23 ) ;
V_25 = F_20 ( V_2 -> V_20 , 0 , V_2 -> V_15 , V_23 ) ;
} else
V_25 = F_21 ( V_2 ) ;
if ( V_25 < 0 )
goto error;
V_25 = F_22 ( V_2 ) ;
if ( V_25 < 0 )
goto error;
V_29:
return V_25 ;
error:
if ( V_26 > 0 )
F_23 ( V_26 ) ;
V_2 -> V_32 = 0 ;
V_2 -> V_38 = 0 ;
goto V_29;
}
static char * F_24 ( char * V_9 , char V_41 )
{
char V_42 ;
while ( ( V_42 = * V_9 ++ ) != V_41 ) {
if ( V_42 == '\\' && * V_9 == 'x' ) {
V_9 ++ ;
if ( ! isxdigit ( * V_9 ++ ) )
return NULL ;
if ( ! isxdigit ( * V_9 ++ ) )
return NULL ;
}
}
V_9 [ - 1 ] = '\0' ;
return V_9 ;
}
static char * F_25 ( char * V_43 , T_1 * V_7 )
{
char * V_3 = V_43 ;
int V_44 = 1 ;
while ( V_44 ) {
switch ( * V_3 ) {
case 'P' :
F_26 ( L_1 ) ;
V_3 ++ ;
V_7 -> V_12 |= V_35 ;
break;
case 'O' :
F_26 ( L_2 ) ;
V_3 ++ ;
V_7 -> V_12 |= V_36 ;
break;
case 'C' :
F_26 ( L_3 ) ;
V_3 ++ ;
V_7 -> V_12 |= ( V_40 |
V_36 ) ;
break;
default:
V_44 = 0 ;
}
}
return V_3 ;
}
static T_1 * F_27 ( const char T_2 * V_45 , T_3 V_46 )
{
T_1 * V_7 ;
int V_47 , V_48 ;
char * V_15 , * V_3 ;
char V_41 ;
F_26 ( L_4 , V_46 ) ;
V_48 = - V_49 ;
if ( ( V_46 < 11 ) || ( V_46 > V_50 ) )
goto V_51;
V_48 = - V_52 ;
V_47 = sizeof( T_1 ) + V_46 + 8 ;
V_7 = F_28 ( V_47 , V_53 ) ;
if ( ! V_7 )
goto V_51;
V_3 = V_15 = ( char * ) V_7 + sizeof( T_1 ) ;
memset ( V_7 , 0 , sizeof( T_1 ) ) ;
if ( F_29 ( V_15 , V_45 , V_46 ) )
goto V_54;
V_41 = * V_3 ++ ;
F_26 ( L_5 , V_41 , V_41 ) ;
memset ( V_15 + V_46 , V_41 , 8 ) ;
V_7 -> V_55 = V_3 ;
V_3 = strchr ( V_3 , V_41 ) ;
if ( ! V_3 )
goto V_56;
* V_3 ++ = '\0' ;
if ( ! V_7 -> V_55 [ 0 ] ||
! strcmp ( V_7 -> V_55 , L_6 ) ||
! strcmp ( V_7 -> V_55 , L_7 ) ||
strchr ( V_7 -> V_55 , '/' ) )
goto V_56;
F_26 ( L_8 , V_7 -> V_55 ) ;
switch ( * V_3 ++ ) {
case 'E' :
F_26 ( L_9 ) ;
V_7 -> V_12 = 1 << V_11 ;
break;
case 'M' :
F_26 ( L_10 ) ;
V_7 -> V_12 = ( 1 << V_11 ) | ( 1 << V_13 ) ;
break;
default:
goto V_56;
}
if ( * V_3 ++ != V_41 )
goto V_56;
if ( F_4 ( V_13 , & V_7 -> V_12 ) ) {
char * V_9 ;
V_9 = strchr ( V_3 , V_41 ) ;
if ( ! V_9 )
goto V_56;
* V_9 ++ = '\0' ;
V_7 -> V_16 = F_30 ( V_3 , & V_3 , 10 ) ;
if ( * V_3 ++ )
goto V_56;
F_26 ( L_11 , V_7 -> V_16 ) ;
V_7 -> V_14 = V_3 ;
V_3 = F_24 ( V_3 , V_41 ) ;
if ( ! V_3 )
goto V_56;
if ( ! V_7 -> V_14 [ 0 ] )
goto V_56;
if ( V_57 )
F_31 (
V_58 L_12 ,
V_59 , V_7 -> V_14 , V_3 - V_7 -> V_14 ) ;
V_7 -> V_17 = V_3 ;
V_3 = F_24 ( V_3 , V_41 ) ;
if ( ! V_3 )
goto V_56;
if ( ! V_7 -> V_17 [ 0 ] ) {
V_7 -> V_17 = NULL ;
F_26 ( L_13 ) ;
} else if ( V_57 )
F_31 (
V_58 L_14 ,
V_59 , V_7 -> V_17 , V_3 - V_7 -> V_17 ) ;
V_7 -> V_18 = F_32 ( V_7 -> V_14 , V_60 ) ;
if ( V_7 -> V_17 &&
F_32 ( V_7 -> V_17 , V_60 ) != V_7 -> V_18 )
goto V_56;
if ( V_7 -> V_18 + V_7 -> V_16 > V_23 )
goto V_56;
F_26 ( L_15 , V_7 -> V_18 ) ;
if ( V_57 ) {
F_31 (
V_58 L_16 ,
V_59 , V_7 -> V_14 , V_7 -> V_18 ) ;
if ( V_7 -> V_17 ) {
int V_61 ;
char * V_62 = F_28 ( V_7 -> V_18 , V_53 ) ;
F_31 (
V_58 L_17 ,
V_59 , V_7 -> V_17 , V_7 -> V_18 ) ;
if ( V_62 ) {
for ( V_61 = 0 ; V_61 < V_7 -> V_18 ; ++ V_61 )
V_62 [ V_61 ] = V_7 -> V_14 [ V_61 ] & V_7 -> V_17 [ V_61 ] ;
F_31 (
V_58 L_18 ,
V_59 , V_62 , V_7 -> V_18 ) ;
F_33 ( V_62 ) ;
}
}
}
} else {
V_3 = strchr ( V_3 , V_41 ) ;
if ( ! V_3 )
goto V_56;
* V_3 ++ = '\0' ;
V_7 -> V_14 = V_3 ;
V_3 = strchr ( V_3 , V_41 ) ;
if ( ! V_3 )
goto V_56;
* V_3 ++ = '\0' ;
if ( ! V_7 -> V_14 [ 0 ] || strchr ( V_7 -> V_14 , '/' ) )
goto V_56;
F_26 ( L_19 , V_7 -> V_14 ) ;
V_3 = strchr ( V_3 , V_41 ) ;
if ( ! V_3 )
goto V_56;
* V_3 ++ = '\0' ;
}
V_7 -> V_31 = V_3 ;
V_3 = strchr ( V_3 , V_41 ) ;
if ( ! V_3 )
goto V_56;
* V_3 ++ = '\0' ;
if ( ! V_7 -> V_31 [ 0 ] )
goto V_56;
F_26 ( L_20 , V_7 -> V_31 ) ;
V_3 = F_25 ( V_3 , V_7 ) ;
if ( * V_3 == '\n' )
V_3 ++ ;
if ( V_3 != V_15 + V_46 )
goto V_56;
return V_7 ;
V_51:
return F_34 ( V_48 ) ;
V_54:
F_33 ( V_7 ) ;
return F_34 ( - V_63 ) ;
V_56:
F_33 ( V_7 ) ;
return F_34 ( - V_49 ) ;
}
static int F_35 ( const char T_2 * V_45 , T_3 V_46 )
{
char V_9 [ 4 ] ;
if ( V_46 > 3 )
return - V_49 ;
if ( F_29 ( V_9 , V_45 , V_46 ) )
return - V_63 ;
if ( ! V_46 )
return 0 ;
if ( V_9 [ V_46 - 1 ] == '\n' )
V_46 -- ;
if ( V_46 == 1 && V_9 [ 0 ] == '0' )
return 1 ;
if ( V_46 == 1 && V_9 [ 0 ] == '1' )
return 2 ;
if ( V_46 == 2 && V_9 [ 0 ] == '-' && V_9 [ 1 ] == '1' )
return 3 ;
return - V_49 ;
}
static void F_36 ( T_1 * V_7 , char * V_64 )
{
char * V_65 = V_64 ;
const char * V_66 = L_21 ;
if ( F_4 ( V_11 , & V_7 -> V_12 ) )
V_66 = L_22 ;
if ( ! V_67 ) {
sprintf ( V_64 , L_23 , V_66 ) ;
return;
}
V_65 += sprintf ( V_65 , L_24 , V_66 , V_7 -> V_31 ) ;
V_65 += sprintf ( V_65 , L_25 ) ;
if ( V_7 -> V_12 & V_35 )
* V_65 ++ = 'P' ;
if ( V_7 -> V_12 & V_36 )
* V_65 ++ = 'O' ;
if ( V_7 -> V_12 & V_40 )
* V_65 ++ = 'C' ;
* V_65 ++ = '\n' ;
if ( ! F_4 ( V_13 , & V_7 -> V_12 ) ) {
sprintf ( V_65 , L_26 , V_7 -> V_14 ) ;
} else {
V_65 += sprintf ( V_65 , L_27 , V_7 -> V_16 ) ;
V_65 = F_37 ( V_65 , V_7 -> V_14 , V_7 -> V_18 ) ;
if ( V_7 -> V_17 ) {
V_65 += sprintf ( V_65 , L_28 ) ;
V_65 = F_37 ( V_65 , V_7 -> V_17 , V_7 -> V_18 ) ;
}
* V_65 ++ = '\n' ;
* V_65 = '\0' ;
}
}
static struct V_68 * F_38 ( struct V_69 * V_70 , int V_71 )
{
struct V_68 * V_68 = F_39 ( V_70 ) ;
if ( V_68 ) {
V_68 -> V_72 = F_40 () ;
V_68 -> V_73 = V_71 ;
V_68 -> V_74 = V_68 -> V_75 = V_68 -> V_76 =
F_41 ( V_68 -> V_77 ) ;
}
return V_68 ;
}
static void F_42 ( struct V_68 * V_68 )
{
F_43 ( V_68 ) ;
F_33 ( V_68 -> V_78 ) ;
}
static void F_44 ( T_1 * V_7 )
{
struct V_79 * V_79 ;
F_45 ( & V_30 ) ;
V_79 = V_7 -> V_79 ;
if ( V_79 ) {
F_46 ( & V_7 -> V_8 ) ;
V_7 -> V_79 = NULL ;
}
F_47 ( & V_30 ) ;
if ( V_79 ) {
F_48 ( F_49 ( V_79 ) ) ;
F_50 ( V_79 ) ;
F_51 ( V_79 ) ;
F_52 ( & V_80 , & V_81 ) ;
}
}
static T_4
F_53 ( struct V_20 * V_20 , char T_2 * V_15 , T_3 V_82 , T_5 * V_83 )
{
T_1 * V_7 = F_54 ( V_20 ) -> V_78 ;
T_4 V_84 ;
char * V_64 ;
V_64 = ( char * ) F_55 ( V_53 ) ;
if ( ! V_64 )
return - V_52 ;
F_36 ( V_7 , V_64 ) ;
V_84 = F_56 ( V_15 , V_82 , V_83 , V_64 , strlen ( V_64 ) ) ;
F_57 ( ( unsigned long ) V_64 ) ;
return V_84 ;
}
static T_4 F_58 ( struct V_20 * V_20 , const char T_2 * V_45 ,
T_3 V_46 , T_5 * V_83 )
{
struct V_79 * V_85 ;
T_1 * V_7 = F_54 ( V_20 ) -> V_78 ;
int V_84 = F_35 ( V_45 , V_46 ) ;
switch ( V_84 ) {
case 1 :
F_59 ( V_11 , & V_7 -> V_12 ) ;
break;
case 2 :
F_60 ( V_11 , & V_7 -> V_12 ) ;
break;
case 3 :
V_85 = F_61 ( V_20 -> V_86 . V_79 -> V_87 -> V_88 ) ;
F_62 ( & F_49 ( V_85 ) -> V_89 ) ;
F_44 ( V_7 ) ;
F_63 ( & F_49 ( V_85 ) -> V_89 ) ;
F_51 ( V_85 ) ;
break;
default:
return V_84 ;
}
return V_46 ;
}
static T_4 F_64 ( struct V_20 * V_20 , const char T_2 * V_45 ,
T_3 V_46 , T_5 * V_83 )
{
T_1 * V_7 ;
struct V_68 * V_68 ;
struct V_79 * V_85 , * V_79 ;
struct V_69 * V_70 = V_20 -> V_86 . V_79 -> V_87 ;
int V_48 = 0 ;
V_7 = F_27 ( V_45 , V_46 ) ;
if ( F_19 ( V_7 ) )
return F_18 ( V_7 ) ;
V_85 = F_61 ( V_70 -> V_88 ) ;
F_62 ( & F_49 ( V_85 ) -> V_89 ) ;
V_79 = F_65 ( V_7 -> V_55 , V_85 , strlen ( V_7 -> V_55 ) ) ;
V_48 = F_18 ( V_79 ) ;
if ( F_19 ( V_79 ) )
goto V_51;
V_48 = - V_90 ;
if ( F_66 ( V_79 ) )
goto V_91;
V_68 = F_38 ( V_70 , V_92 | 0644 ) ;
V_48 = - V_52 ;
if ( ! V_68 )
goto V_91;
V_48 = F_67 ( & V_93 , & V_80 , & V_81 ) ;
if ( V_48 ) {
F_68 ( V_68 ) ;
V_68 = NULL ;
goto V_91;
}
V_7 -> V_79 = F_61 ( V_79 ) ;
V_68 -> V_78 = V_7 ;
V_68 -> V_94 = & V_95 ;
F_69 ( V_79 , V_68 ) ;
F_45 ( & V_30 ) ;
F_70 ( & V_7 -> V_8 , & V_96 ) ;
F_47 ( & V_30 ) ;
V_48 = 0 ;
V_91:
F_51 ( V_79 ) ;
V_51:
F_63 ( & F_49 ( V_85 ) -> V_89 ) ;
F_51 ( V_85 ) ;
if ( V_48 ) {
F_33 ( V_7 ) ;
return - V_49 ;
}
return V_46 ;
}
static T_4
F_71 ( struct V_20 * V_20 , char T_2 * V_15 , T_3 V_82 , T_5 * V_83 )
{
char * V_9 = V_28 ? L_29 : L_30 ;
return F_56 ( V_15 , V_82 , V_83 , V_9 , strlen ( V_9 ) ) ;
}
static T_4 F_72 ( struct V_20 * V_20 , const char T_2 * V_45 ,
T_3 V_46 , T_5 * V_83 )
{
int V_84 = F_35 ( V_45 , V_46 ) ;
struct V_79 * V_85 ;
switch ( V_84 ) {
case 1 :
V_28 = 0 ;
break;
case 2 :
V_28 = 1 ;
break;
case 3 :
V_85 = F_61 ( V_20 -> V_86 . V_79 -> V_87 -> V_88 ) ;
F_62 ( & F_49 ( V_85 ) -> V_89 ) ;
while ( ! F_73 ( & V_96 ) )
F_44 ( F_3 ( V_96 . V_97 , T_1 , V_8 ) ) ;
F_63 ( & F_49 ( V_85 ) -> V_89 ) ;
F_51 ( V_85 ) ;
break;
default:
return V_84 ;
}
return V_46 ;
}
static int F_74 ( struct V_69 * V_70 , void * V_98 , int V_99 )
{
int V_48 ;
static struct V_100 V_101 [] = {
[ 2 ] = { L_31 , & V_102 , V_103 | V_104 } ,
[ 3 ] = { L_32 , & V_105 , V_103 } ,
{ L_33 }
} ;
V_48 = F_75 ( V_70 , V_106 , V_101 ) ;
if ( ! V_48 )
V_70 -> V_107 = & V_108 ;
return V_48 ;
}
static struct V_79 * F_76 ( struct V_109 * V_110 ,
int V_12 , const char * V_111 , void * V_98 )
{
return F_77 ( V_110 , V_12 , V_98 , F_74 ) ;
}
static int T_6 F_78 ( void )
{
int V_48 = F_79 ( & V_93 ) ;
if ( ! V_48 )
F_80 ( & V_112 ) ;
return V_48 ;
}
static void T_7 F_81 ( void )
{
F_82 ( & V_112 ) ;
F_83 ( & V_93 ) ;
}
