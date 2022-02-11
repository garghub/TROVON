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
int V_22 ;
int V_23 = - 1 ;
V_22 = - V_24 ;
if ( ! V_25 )
return V_22 ;
F_6 ( & V_26 ) ;
V_19 = F_1 ( V_2 ) ;
if ( V_19 )
F_7 ( V_19 -> V_27 ) ;
F_8 ( & V_26 ) ;
if ( ! V_19 )
return V_22 ;
V_22 = - V_28 ;
if ( V_2 -> V_29 & V_30 )
goto V_31;
if ( ! ( V_19 -> V_12 & V_32 ) ) {
V_22 = F_9 ( V_2 ) ;
if ( V_22 )
goto V_31;
}
if ( V_19 -> V_12 & V_33 ) {
V_23 = F_10 ( 0 ) ;
if ( V_23 < 0 ) {
V_22 = V_23 ;
goto V_31;
}
F_11 ( V_23 , V_2 -> V_20 ) ;
F_12 ( V_2 , V_2 -> V_20 ) ;
F_13 ( V_2 -> V_20 ) ;
V_2 -> V_20 = NULL ;
V_2 -> V_29 |= V_34 ;
V_2 -> V_35 = V_23 ;
} else {
F_13 ( V_2 -> V_20 ) ;
F_14 ( V_2 -> V_20 ) ;
V_2 -> V_20 = NULL ;
}
V_22 = F_15 ( 1 , & V_2 -> V_4 , V_2 ) ;
if ( V_22 < 0 )
goto error;
V_2 -> V_36 ++ ;
V_22 = F_15 ( 1 , & V_19 -> V_37 , V_2 ) ;
if ( V_22 < 0 )
goto error;
V_2 -> V_36 ++ ;
V_22 = F_16 ( V_19 -> V_37 , V_2 ) ;
if ( V_22 < 0 )
goto error;
if ( V_19 -> V_12 & V_38 ) {
V_21 = F_17 ( V_19 -> V_21 ) ;
if ( ! F_18 ( V_21 ) )
F_19 ( V_21 ) ;
} else {
V_21 = F_20 ( V_19 -> V_37 ) ;
}
V_22 = F_21 ( V_21 ) ;
if ( F_18 ( V_21 ) )
goto error;
V_2 -> V_20 = V_21 ;
if ( V_19 -> V_12 & V_39 ) {
T_2 V_40 = 0 ;
memset ( V_2 -> V_15 , 0 , V_41 ) ;
V_22 = F_22 ( V_2 -> V_20 , V_2 -> V_15 , V_41 ,
& V_40 ) ;
} else
V_22 = F_23 ( V_2 ) ;
if ( V_22 < 0 )
goto error;
V_22 = F_24 ( V_2 ) ;
if ( V_22 < 0 )
goto error;
V_31:
F_25 ( V_19 -> V_27 ) ;
return V_22 ;
error:
if ( V_23 > 0 )
F_26 ( V_23 ) ;
V_2 -> V_29 = 0 ;
V_2 -> V_35 = 0 ;
goto V_31;
}
static char * F_27 ( char * V_9 , char V_42 )
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
static char * F_28 ( char * V_44 , T_1 * V_7 )
{
char * V_3 = V_44 ;
int V_45 = 1 ;
while ( V_45 ) {
switch ( * V_3 ) {
case 'P' :
F_29 ( L_1 ) ;
V_3 ++ ;
V_7 -> V_12 |= V_32 ;
break;
case 'O' :
F_29 ( L_2 ) ;
V_3 ++ ;
V_7 -> V_12 |= V_33 ;
break;
case 'C' :
F_29 ( L_3 ) ;
V_3 ++ ;
V_7 -> V_12 |= ( V_39 |
V_33 ) ;
break;
case 'F' :
F_29 ( L_4 ) ;
V_3 ++ ;
V_7 -> V_12 |= V_38 ;
break;
default:
V_45 = 0 ;
}
}
return V_3 ;
}
static T_1 * F_30 ( const char T_3 * V_46 , T_4 V_47 )
{
T_1 * V_7 ;
int V_48 , V_49 ;
char * V_15 , * V_3 ;
char V_42 ;
F_29 ( L_5 , V_47 ) ;
V_49 = - V_50 ;
if ( ( V_47 < 11 ) || ( V_47 > V_51 ) )
goto V_52;
V_49 = - V_53 ;
V_48 = sizeof( T_1 ) + V_47 + 8 ;
V_7 = F_31 ( V_48 , V_54 ) ;
if ( ! V_7 )
goto V_52;
V_3 = V_15 = ( char * ) V_7 + sizeof( T_1 ) ;
memset ( V_7 , 0 , sizeof( T_1 ) ) ;
if ( F_32 ( V_15 , V_46 , V_47 ) )
goto V_55;
V_42 = * V_3 ++ ;
F_29 ( L_6 , V_42 , V_42 ) ;
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
F_29 ( L_9 , V_7 -> V_56 ) ;
switch ( * V_3 ++ ) {
case 'E' :
F_29 ( L_10 ) ;
V_7 -> V_12 = 1 << V_11 ;
break;
case 'M' :
F_29 ( L_11 ) ;
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
V_7 -> V_16 = F_33 ( V_3 , & V_3 , 10 ) ;
if ( * V_3 ++ )
goto V_57;
F_29 ( L_12 , V_7 -> V_16 ) ;
V_7 -> V_14 = V_3 ;
V_3 = F_27 ( V_3 , V_42 ) ;
if ( ! V_3 )
goto V_57;
if ( ! V_7 -> V_14 [ 0 ] )
goto V_57;
if ( V_58 )
F_34 (
V_59 L_13 ,
V_60 , V_7 -> V_14 , V_3 - V_7 -> V_14 ) ;
V_7 -> V_17 = V_3 ;
V_3 = F_27 ( V_3 , V_42 ) ;
if ( ! V_3 )
goto V_57;
if ( ! V_7 -> V_17 [ 0 ] ) {
V_7 -> V_17 = NULL ;
F_29 ( L_14 ) ;
} else if ( V_58 )
F_34 (
V_59 L_15 ,
V_60 , V_7 -> V_17 , V_3 - V_7 -> V_17 ) ;
V_7 -> V_18 = F_35 ( V_7 -> V_14 , V_61 ) ;
if ( V_7 -> V_17 &&
F_35 ( V_7 -> V_17 , V_61 ) != V_7 -> V_18 )
goto V_57;
if ( V_7 -> V_18 + V_7 -> V_16 > V_41 )
goto V_57;
F_29 ( L_16 , V_7 -> V_18 ) ;
if ( V_58 ) {
F_34 (
V_59 L_17 ,
V_60 , V_7 -> V_14 , V_7 -> V_18 ) ;
if ( V_7 -> V_17 ) {
int V_62 ;
char * V_63 = F_31 ( V_7 -> V_18 , V_54 ) ;
F_34 (
V_59 L_18 ,
V_60 , V_7 -> V_17 , V_7 -> V_18 ) ;
if ( V_63 ) {
for ( V_62 = 0 ; V_62 < V_7 -> V_18 ; ++ V_62 )
V_63 [ V_62 ] = V_7 -> V_14 [ V_62 ] & V_7 -> V_17 [ V_62 ] ;
F_34 (
V_59 L_19 ,
V_60 , V_63 , V_7 -> V_18 ) ;
F_36 ( V_63 ) ;
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
F_29 ( L_20 , V_7 -> V_14 ) ;
V_3 = strchr ( V_3 , V_42 ) ;
if ( ! V_3 )
goto V_57;
* V_3 ++ = '\0' ;
}
V_7 -> V_37 = V_3 ;
V_3 = strchr ( V_3 , V_42 ) ;
if ( ! V_3 )
goto V_57;
* V_3 ++ = '\0' ;
if ( ! V_7 -> V_37 [ 0 ] )
goto V_57;
F_29 ( L_21 , V_7 -> V_37 ) ;
V_3 = F_28 ( V_3 , V_7 ) ;
if ( * V_3 == '\n' )
V_3 ++ ;
if ( V_3 != V_15 + V_47 )
goto V_57;
return V_7 ;
V_52:
return F_37 ( V_49 ) ;
V_55:
F_36 ( V_7 ) ;
return F_37 ( - V_64 ) ;
V_57:
F_36 ( V_7 ) ;
return F_37 ( - V_50 ) ;
}
static int F_38 ( const char T_3 * V_46 , T_4 V_47 )
{
char V_9 [ 4 ] ;
if ( V_47 > 3 )
return - V_50 ;
if ( F_32 ( V_9 , V_46 , V_47 ) )
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
static void F_39 ( T_1 * V_7 , char * V_65 )
{
char * V_66 = V_65 ;
const char * V_67 = L_22 ;
if ( F_4 ( V_11 , & V_7 -> V_12 ) )
V_67 = L_23 ;
if ( ! V_68 ) {
sprintf ( V_65 , L_24 , V_67 ) ;
return;
}
V_66 += sprintf ( V_66 , L_25 , V_67 , V_7 -> V_37 ) ;
V_66 += sprintf ( V_66 , L_26 ) ;
if ( V_7 -> V_12 & V_32 )
* V_66 ++ = 'P' ;
if ( V_7 -> V_12 & V_33 )
* V_66 ++ = 'O' ;
if ( V_7 -> V_12 & V_39 )
* V_66 ++ = 'C' ;
if ( V_7 -> V_12 & V_38 )
* V_66 ++ = 'F' ;
* V_66 ++ = '\n' ;
if ( ! F_4 ( V_13 , & V_7 -> V_12 ) ) {
sprintf ( V_66 , L_27 , V_7 -> V_14 ) ;
} else {
V_66 += sprintf ( V_66 , L_28 , V_7 -> V_16 ) ;
V_66 = F_40 ( V_66 , V_7 -> V_14 , V_7 -> V_18 ) ;
if ( V_7 -> V_17 ) {
V_66 += sprintf ( V_66 , L_29 ) ;
V_66 = F_40 ( V_66 , V_7 -> V_17 , V_7 -> V_18 ) ;
}
* V_66 ++ = '\n' ;
* V_66 = '\0' ;
}
}
static struct V_69 * F_41 ( struct V_70 * V_71 , int V_72 )
{
struct V_69 * V_69 = F_42 ( V_71 ) ;
if ( V_69 ) {
V_69 -> V_73 = F_43 () ;
V_69 -> V_74 = V_72 ;
V_69 -> V_75 = V_69 -> V_76 = V_69 -> V_77 =
F_44 ( V_69 ) ;
}
return V_69 ;
}
static void F_45 ( struct V_69 * V_69 )
{
T_1 * V_7 = V_69 -> V_78 ;
if ( V_7 && V_7 -> V_12 & V_38 )
F_46 ( V_7 -> V_21 , NULL ) ;
F_47 ( V_69 ) ;
F_36 ( V_7 ) ;
}
static void F_48 ( T_1 * V_7 )
{
struct V_27 * V_27 ;
F_49 ( & V_26 ) ;
F_50 ( & V_7 -> V_8 ) ;
F_51 ( & V_26 ) ;
V_27 = V_7 -> V_27 ;
F_52 ( F_53 ( V_27 ) ) ;
F_54 ( V_27 ) ;
F_25 ( V_27 ) ;
F_55 ( & V_79 , & V_80 ) ;
}
static T_5
F_56 ( struct V_20 * V_20 , char T_3 * V_15 , T_4 V_81 , T_2 * V_82 )
{
T_1 * V_7 = F_57 ( V_20 ) -> V_78 ;
T_5 V_83 ;
char * V_65 ;
V_65 = ( char * ) F_58 ( V_54 ) ;
if ( ! V_65 )
return - V_53 ;
F_39 ( V_7 , V_65 ) ;
V_83 = F_59 ( V_15 , V_81 , V_82 , V_65 , strlen ( V_65 ) ) ;
F_60 ( ( unsigned long ) V_65 ) ;
return V_83 ;
}
static T_5 F_61 ( struct V_20 * V_20 , const char T_3 * V_46 ,
T_4 V_47 , T_2 * V_82 )
{
struct V_27 * V_84 ;
T_1 * V_7 = F_57 ( V_20 ) -> V_78 ;
int V_83 = F_38 ( V_46 , V_47 ) ;
switch ( V_83 ) {
case 1 :
F_62 ( V_11 , & V_7 -> V_12 ) ;
break;
case 2 :
F_63 ( V_11 , & V_7 -> V_12 ) ;
break;
case 3 :
V_84 = F_57 ( V_20 ) -> V_85 -> V_86 ;
F_64 ( F_53 ( V_84 ) ) ;
if ( ! F_65 ( & V_7 -> V_8 ) )
F_48 ( V_7 ) ;
F_66 ( F_53 ( V_84 ) ) ;
break;
default:
return V_83 ;
}
return V_47 ;
}
static T_5 F_67 ( struct V_20 * V_20 , const char T_3 * V_46 ,
T_4 V_47 , T_2 * V_82 )
{
T_1 * V_7 ;
struct V_69 * V_69 ;
struct V_70 * V_71 = F_57 ( V_20 ) -> V_85 ;
struct V_27 * V_84 = V_71 -> V_86 , * V_27 ;
int V_49 = 0 ;
V_7 = F_30 ( V_46 , V_47 ) ;
if ( F_18 ( V_7 ) )
return F_21 ( V_7 ) ;
F_64 ( F_53 ( V_84 ) ) ;
V_27 = F_68 ( V_7 -> V_56 , V_84 , strlen ( V_7 -> V_56 ) ) ;
V_49 = F_21 ( V_27 ) ;
if ( F_18 ( V_27 ) )
goto V_52;
V_49 = - V_87 ;
if ( F_69 ( V_27 ) )
goto V_88;
V_69 = F_41 ( V_71 , V_89 | 0644 ) ;
V_49 = - V_53 ;
if ( ! V_69 )
goto V_88;
V_49 = F_70 ( & V_90 , & V_79 , & V_80 ) ;
if ( V_49 ) {
F_71 ( V_69 ) ;
V_69 = NULL ;
goto V_88;
}
if ( V_7 -> V_12 & V_38 ) {
struct V_20 * V_91 ;
V_91 = F_20 ( V_7 -> V_37 ) ;
if ( F_18 ( V_91 ) ) {
V_49 = F_21 ( V_91 ) ;
F_72 ( L_30 , V_7 -> V_37 ) ;
F_55 ( & V_79 , & V_80 ) ;
F_71 ( V_69 ) ;
V_69 = NULL ;
goto V_88;
}
V_7 -> V_21 = V_91 ;
}
V_7 -> V_27 = F_7 ( V_27 ) ;
V_69 -> V_78 = V_7 ;
V_69 -> V_92 = & V_93 ;
F_73 ( V_27 , V_69 ) ;
F_49 ( & V_26 ) ;
F_74 ( & V_7 -> V_8 , & V_94 ) ;
F_51 ( & V_26 ) ;
V_49 = 0 ;
V_88:
F_25 ( V_27 ) ;
V_52:
F_66 ( F_53 ( V_84 ) ) ;
if ( V_49 ) {
F_36 ( V_7 ) ;
return V_49 ;
}
return V_47 ;
}
static T_5
F_75 ( struct V_20 * V_20 , char T_3 * V_15 , T_4 V_81 , T_2 * V_82 )
{
char * V_9 = V_25 ? L_31 : L_32 ;
return F_59 ( V_15 , V_81 , V_82 , V_9 , strlen ( V_9 ) ) ;
}
static T_5 F_76 ( struct V_20 * V_20 , const char T_3 * V_46 ,
T_4 V_47 , T_2 * V_82 )
{
int V_83 = F_38 ( V_46 , V_47 ) ;
struct V_27 * V_84 ;
switch ( V_83 ) {
case 1 :
V_25 = 0 ;
break;
case 2 :
V_25 = 1 ;
break;
case 3 :
V_84 = F_57 ( V_20 ) -> V_85 -> V_86 ;
F_64 ( F_53 ( V_84 ) ) ;
while ( ! F_65 ( & V_94 ) )
F_48 ( F_77 ( & V_94 , T_1 , V_8 ) ) ;
F_66 ( F_53 ( V_84 ) ) ;
break;
default:
return V_83 ;
}
return V_47 ;
}
static int F_78 ( struct V_70 * V_71 , void * V_95 , int V_96 )
{
int V_49 ;
static const struct V_97 V_98 [] = {
[ 2 ] = { L_33 , & V_99 , V_100 | V_101 } ,
[ 3 ] = { L_34 , & V_102 , V_100 } ,
{ L_35 }
} ;
V_49 = F_79 ( V_71 , V_103 , V_98 ) ;
if ( ! V_49 )
V_71 -> V_104 = & V_105 ;
return V_49 ;
}
static struct V_27 * F_80 ( struct V_106 * V_107 ,
int V_12 , const char * V_108 , void * V_95 )
{
return F_81 ( V_107 , V_12 , V_95 , F_78 ) ;
}
static int T_6 F_82 ( void )
{
int V_49 = F_83 ( & V_90 ) ;
if ( ! V_49 )
F_84 ( & V_109 ) ;
return V_49 ;
}
static void T_7 F_85 ( void )
{
F_86 ( & V_109 ) ;
F_87 ( & V_90 ) ;
}
