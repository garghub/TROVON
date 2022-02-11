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
if ( V_19 -> V_12 & V_40 && V_19 -> V_21 ) {
V_21 = F_17 ( V_19 -> V_21 ) ;
if ( ! F_18 ( V_21 ) )
F_19 ( V_21 ) ;
} else {
V_21 = F_20 ( V_22 ) ;
}
V_25 = F_21 ( V_21 ) ;
if ( F_18 ( V_21 ) )
goto error;
V_2 -> V_20 = V_21 ;
if ( V_19 -> V_12 & V_41 ) {
memset ( V_2 -> V_15 , 0 , V_23 ) ;
V_25 = F_22 ( V_2 -> V_20 , 0 , V_2 -> V_15 , V_23 ) ;
} else
V_25 = F_23 ( V_2 ) ;
if ( V_25 < 0 )
goto error;
V_25 = F_24 ( V_2 ) ;
if ( V_25 < 0 )
goto error;
V_29:
return V_25 ;
error:
if ( V_26 > 0 )
F_25 ( V_26 ) ;
V_2 -> V_32 = 0 ;
V_2 -> V_38 = 0 ;
goto V_29;
}
static char * F_26 ( char * V_9 , char V_42 )
{
char V_43 ;
while ( ( V_43 = * V_9 ++ ) != V_42 ) {
if ( V_43 == '\\' && * V_9 == 'x' ) {
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
static char * F_27 ( char * V_44 , T_1 * V_7 )
{
char * V_3 = V_44 ;
int V_45 = 1 ;
while ( V_45 ) {
switch ( * V_3 ) {
case 'P' :
F_28 ( L_1 ) ;
V_3 ++ ;
V_7 -> V_12 |= V_35 ;
break;
case 'O' :
F_28 ( L_2 ) ;
V_3 ++ ;
V_7 -> V_12 |= V_36 ;
break;
case 'C' :
F_28 ( L_3 ) ;
V_3 ++ ;
V_7 -> V_12 |= ( V_41 |
V_36 ) ;
break;
case 'F' :
F_28 ( L_4 ) ;
V_3 ++ ;
V_7 -> V_12 |= V_40 ;
break;
default:
V_45 = 0 ;
}
}
return V_3 ;
}
static T_1 * F_29 ( const char T_2 * V_46 , T_3 V_47 )
{
T_1 * V_7 ;
int V_48 , V_49 ;
char * V_15 , * V_3 ;
char V_42 ;
F_28 ( L_5 , V_47 ) ;
V_49 = - V_50 ;
if ( ( V_47 < 11 ) || ( V_47 > V_51 ) )
goto V_52;
V_49 = - V_53 ;
V_48 = sizeof( T_1 ) + V_47 + 8 ;
V_7 = F_30 ( V_48 , V_54 ) ;
if ( ! V_7 )
goto V_52;
V_3 = V_15 = ( char * ) V_7 + sizeof( T_1 ) ;
memset ( V_7 , 0 , sizeof( T_1 ) ) ;
if ( F_31 ( V_15 , V_46 , V_47 ) )
goto V_55;
V_42 = * V_3 ++ ;
F_28 ( L_6 , V_42 , V_42 ) ;
memset ( V_15 + V_47 , V_42 , 8 ) ;
V_7 -> V_56 = V_3 ;
V_3 = strchr ( V_3 , V_42 ) ;
if ( ! V_3 )
goto V_57;
* V_3 ++ = '\0' ;
if ( ! V_7 -> V_56 [ 0 ] ||
! strcmp ( V_7 -> V_56 , L_7 ) ||
! strcmp ( V_7 -> V_56 , L_8 ) ||
strchr ( V_7 -> V_56 , '/' ) )
goto V_57;
F_28 ( L_9 , V_7 -> V_56 ) ;
switch ( * V_3 ++ ) {
case 'E' :
F_28 ( L_10 ) ;
V_7 -> V_12 = 1 << V_11 ;
break;
case 'M' :
F_28 ( L_11 ) ;
V_7 -> V_12 = ( 1 << V_11 ) | ( 1 << V_13 ) ;
break;
default:
goto V_57;
}
if ( * V_3 ++ != V_42 )
goto V_57;
if ( F_4 ( V_13 , & V_7 -> V_12 ) ) {
char * V_9 ;
V_9 = strchr ( V_3 , V_42 ) ;
if ( ! V_9 )
goto V_57;
* V_9 ++ = '\0' ;
V_7 -> V_16 = F_32 ( V_3 , & V_3 , 10 ) ;
if ( * V_3 ++ )
goto V_57;
F_28 ( L_12 , V_7 -> V_16 ) ;
V_7 -> V_14 = V_3 ;
V_3 = F_26 ( V_3 , V_42 ) ;
if ( ! V_3 )
goto V_57;
if ( ! V_7 -> V_14 [ 0 ] )
goto V_57;
if ( V_58 )
F_33 (
V_59 L_13 ,
V_60 , V_7 -> V_14 , V_3 - V_7 -> V_14 ) ;
V_7 -> V_17 = V_3 ;
V_3 = F_26 ( V_3 , V_42 ) ;
if ( ! V_3 )
goto V_57;
if ( ! V_7 -> V_17 [ 0 ] ) {
V_7 -> V_17 = NULL ;
F_28 ( L_14 ) ;
} else if ( V_58 )
F_33 (
V_59 L_15 ,
V_60 , V_7 -> V_17 , V_3 - V_7 -> V_17 ) ;
V_7 -> V_18 = F_34 ( V_7 -> V_14 , V_61 ) ;
if ( V_7 -> V_17 &&
F_34 ( V_7 -> V_17 , V_61 ) != V_7 -> V_18 )
goto V_57;
if ( V_7 -> V_18 + V_7 -> V_16 > V_23 )
goto V_57;
F_28 ( L_16 , V_7 -> V_18 ) ;
if ( V_58 ) {
F_33 (
V_59 L_17 ,
V_60 , V_7 -> V_14 , V_7 -> V_18 ) ;
if ( V_7 -> V_17 ) {
int V_62 ;
char * V_63 = F_30 ( V_7 -> V_18 , V_54 ) ;
F_33 (
V_59 L_18 ,
V_60 , V_7 -> V_17 , V_7 -> V_18 ) ;
if ( V_63 ) {
for ( V_62 = 0 ; V_62 < V_7 -> V_18 ; ++ V_62 )
V_63 [ V_62 ] = V_7 -> V_14 [ V_62 ] & V_7 -> V_17 [ V_62 ] ;
F_33 (
V_59 L_19 ,
V_60 , V_63 , V_7 -> V_18 ) ;
F_35 ( V_63 ) ;
}
}
}
} else {
V_3 = strchr ( V_3 , V_42 ) ;
if ( ! V_3 )
goto V_57;
* V_3 ++ = '\0' ;
V_7 -> V_14 = V_3 ;
V_3 = strchr ( V_3 , V_42 ) ;
if ( ! V_3 )
goto V_57;
* V_3 ++ = '\0' ;
if ( ! V_7 -> V_14 [ 0 ] || strchr ( V_7 -> V_14 , '/' ) )
goto V_57;
F_28 ( L_20 , V_7 -> V_14 ) ;
V_3 = strchr ( V_3 , V_42 ) ;
if ( ! V_3 )
goto V_57;
* V_3 ++ = '\0' ;
}
V_7 -> V_31 = V_3 ;
V_3 = strchr ( V_3 , V_42 ) ;
if ( ! V_3 )
goto V_57;
* V_3 ++ = '\0' ;
if ( ! V_7 -> V_31 [ 0 ] )
goto V_57;
F_28 ( L_21 , V_7 -> V_31 ) ;
V_3 = F_27 ( V_3 , V_7 ) ;
if ( * V_3 == '\n' )
V_3 ++ ;
if ( V_3 != V_15 + V_47 )
goto V_57;
return V_7 ;
V_52:
return F_36 ( V_49 ) ;
V_55:
F_35 ( V_7 ) ;
return F_36 ( - V_64 ) ;
V_57:
F_35 ( V_7 ) ;
return F_36 ( - V_50 ) ;
}
static int F_37 ( const char T_2 * V_46 , T_3 V_47 )
{
char V_9 [ 4 ] ;
if ( V_47 > 3 )
return - V_50 ;
if ( F_31 ( V_9 , V_46 , V_47 ) )
return - V_64 ;
if ( ! V_47 )
return 0 ;
if ( V_9 [ V_47 - 1 ] == '\n' )
V_47 -- ;
if ( V_47 == 1 && V_9 [ 0 ] == '0' )
return 1 ;
if ( V_47 == 1 && V_9 [ 0 ] == '1' )
return 2 ;
if ( V_47 == 2 && V_9 [ 0 ] == '-' && V_9 [ 1 ] == '1' )
return 3 ;
return - V_50 ;
}
static void F_38 ( T_1 * V_7 , char * V_65 )
{
char * V_66 = V_65 ;
const char * V_67 = L_22 ;
if ( F_4 ( V_11 , & V_7 -> V_12 ) )
V_67 = L_23 ;
if ( ! V_68 ) {
sprintf ( V_65 , L_24 , V_67 ) ;
return;
}
V_66 += sprintf ( V_66 , L_25 , V_67 , V_7 -> V_31 ) ;
V_66 += sprintf ( V_66 , L_26 ) ;
if ( V_7 -> V_12 & V_35 )
* V_66 ++ = 'P' ;
if ( V_7 -> V_12 & V_36 )
* V_66 ++ = 'O' ;
if ( V_7 -> V_12 & V_41 )
* V_66 ++ = 'C' ;
if ( V_7 -> V_12 & V_40 )
* V_66 ++ = 'F' ;
* V_66 ++ = '\n' ;
if ( ! F_4 ( V_13 , & V_7 -> V_12 ) ) {
sprintf ( V_66 , L_27 , V_7 -> V_14 ) ;
} else {
V_66 += sprintf ( V_66 , L_28 , V_7 -> V_16 ) ;
V_66 = F_39 ( V_66 , V_7 -> V_14 , V_7 -> V_18 ) ;
if ( V_7 -> V_17 ) {
V_66 += sprintf ( V_66 , L_29 ) ;
V_66 = F_39 ( V_66 , V_7 -> V_17 , V_7 -> V_18 ) ;
}
* V_66 ++ = '\n' ;
* V_66 = '\0' ;
}
}
static struct V_69 * F_40 ( struct V_70 * V_71 , int V_72 )
{
struct V_69 * V_69 = F_41 ( V_71 ) ;
if ( V_69 ) {
V_69 -> V_73 = F_42 () ;
V_69 -> V_74 = V_72 ;
V_69 -> V_75 = V_69 -> V_76 = V_69 -> V_77 =
F_43 ( V_69 ) ;
}
return V_69 ;
}
static void F_44 ( struct V_69 * V_69 )
{
F_45 ( V_69 ) ;
F_35 ( V_69 -> V_78 ) ;
}
static void F_46 ( T_1 * V_7 )
{
struct V_79 * V_79 ;
F_47 ( & V_30 ) ;
V_79 = V_7 -> V_79 ;
if ( V_79 ) {
F_48 ( & V_7 -> V_8 ) ;
V_7 -> V_79 = NULL ;
}
F_49 ( & V_30 ) ;
if ( ( V_7 -> V_12 & V_40 ) && V_7 -> V_21 ) {
F_50 ( V_7 -> V_21 , NULL ) ;
V_7 -> V_21 = NULL ;
}
if ( V_79 ) {
F_51 ( F_52 ( V_79 ) ) ;
F_53 ( V_79 ) ;
F_54 ( V_79 ) ;
F_55 ( & V_80 , & V_81 ) ;
}
}
static T_4
F_56 ( struct V_20 * V_20 , char T_2 * V_15 , T_3 V_82 , T_5 * V_83 )
{
T_1 * V_7 = F_57 ( V_20 ) -> V_78 ;
T_4 V_84 ;
char * V_65 ;
V_65 = ( char * ) F_58 ( V_54 ) ;
if ( ! V_65 )
return - V_53 ;
F_38 ( V_7 , V_65 ) ;
V_84 = F_59 ( V_15 , V_82 , V_83 , V_65 , strlen ( V_65 ) ) ;
F_60 ( ( unsigned long ) V_65 ) ;
return V_84 ;
}
static T_4 F_61 ( struct V_20 * V_20 , const char T_2 * V_46 ,
T_3 V_47 , T_5 * V_83 )
{
struct V_79 * V_85 ;
T_1 * V_7 = F_57 ( V_20 ) -> V_78 ;
int V_84 = F_37 ( V_46 , V_47 ) ;
switch ( V_84 ) {
case 1 :
F_62 ( V_11 , & V_7 -> V_12 ) ;
break;
case 2 :
F_63 ( V_11 , & V_7 -> V_12 ) ;
break;
case 3 :
V_85 = F_57 ( V_20 ) -> V_86 -> V_87 ;
F_64 ( F_52 ( V_85 ) ) ;
F_46 ( V_7 ) ;
F_65 ( F_52 ( V_85 ) ) ;
break;
default:
return V_84 ;
}
return V_47 ;
}
static T_4 F_66 ( struct V_20 * V_20 , const char T_2 * V_46 ,
T_3 V_47 , T_5 * V_83 )
{
T_1 * V_7 ;
struct V_69 * V_69 ;
struct V_70 * V_71 = F_57 ( V_20 ) -> V_86 ;
struct V_79 * V_85 = V_71 -> V_87 , * V_79 ;
int V_49 = 0 ;
V_7 = F_29 ( V_46 , V_47 ) ;
if ( F_18 ( V_7 ) )
return F_21 ( V_7 ) ;
F_64 ( F_52 ( V_85 ) ) ;
V_79 = F_67 ( V_7 -> V_56 , V_85 , strlen ( V_7 -> V_56 ) ) ;
V_49 = F_21 ( V_79 ) ;
if ( F_18 ( V_79 ) )
goto V_52;
V_49 = - V_88 ;
if ( F_68 ( V_79 ) )
goto V_89;
V_69 = F_40 ( V_71 , V_90 | 0644 ) ;
V_49 = - V_53 ;
if ( ! V_69 )
goto V_89;
V_49 = F_69 ( & V_91 , & V_80 , & V_81 ) ;
if ( V_49 ) {
F_70 ( V_69 ) ;
V_69 = NULL ;
goto V_89;
}
if ( V_7 -> V_12 & V_40 ) {
struct V_20 * V_92 ;
V_92 = F_20 ( V_7 -> V_31 ) ;
if ( F_18 ( V_92 ) ) {
V_49 = F_21 ( V_92 ) ;
F_71 ( L_30 , V_7 -> V_31 ) ;
F_55 ( & V_80 , & V_81 ) ;
F_70 ( V_69 ) ;
V_69 = NULL ;
goto V_89;
}
V_7 -> V_21 = V_92 ;
}
V_7 -> V_79 = F_72 ( V_79 ) ;
V_69 -> V_78 = V_7 ;
V_69 -> V_93 = & V_94 ;
F_73 ( V_79 , V_69 ) ;
F_47 ( & V_30 ) ;
F_74 ( & V_7 -> V_8 , & V_95 ) ;
F_49 ( & V_30 ) ;
V_49 = 0 ;
V_89:
F_54 ( V_79 ) ;
V_52:
F_65 ( F_52 ( V_85 ) ) ;
if ( V_49 ) {
F_35 ( V_7 ) ;
return V_49 ;
}
return V_47 ;
}
static T_4
F_75 ( struct V_20 * V_20 , char T_2 * V_15 , T_3 V_82 , T_5 * V_83 )
{
char * V_9 = V_28 ? L_31 : L_32 ;
return F_59 ( V_15 , V_82 , V_83 , V_9 , strlen ( V_9 ) ) ;
}
static T_4 F_76 ( struct V_20 * V_20 , const char T_2 * V_46 ,
T_3 V_47 , T_5 * V_83 )
{
int V_84 = F_37 ( V_46 , V_47 ) ;
struct V_79 * V_85 ;
switch ( V_84 ) {
case 1 :
V_28 = 0 ;
break;
case 2 :
V_28 = 1 ;
break;
case 3 :
V_85 = F_57 ( V_20 ) -> V_86 -> V_87 ;
F_64 ( F_52 ( V_85 ) ) ;
while ( ! F_77 ( & V_95 ) )
F_46 ( F_3 ( V_95 . V_96 , T_1 , V_8 ) ) ;
F_65 ( F_52 ( V_85 ) ) ;
break;
default:
return V_84 ;
}
return V_47 ;
}
static int F_78 ( struct V_70 * V_71 , void * V_97 , int V_98 )
{
int V_49 ;
static struct V_99 V_100 [] = {
[ 2 ] = { L_33 , & V_101 , V_102 | V_103 } ,
[ 3 ] = { L_34 , & V_104 , V_102 } ,
{ L_35 }
} ;
V_49 = F_79 ( V_71 , V_105 , V_100 ) ;
if ( ! V_49 )
V_71 -> V_106 = & V_107 ;
return V_49 ;
}
static struct V_79 * F_80 ( struct V_108 * V_109 ,
int V_12 , const char * V_110 , void * V_97 )
{
return F_81 ( V_109 , V_12 , V_97 , F_78 ) ;
}
static int T_6 F_82 ( void )
{
int V_49 = F_83 ( & V_91 ) ;
if ( ! V_49 )
F_84 ( & V_111 ) ;
return V_49 ;
}
static void T_7 F_85 ( void )
{
F_86 ( & V_111 ) ;
F_87 ( & V_91 ) ;
}
