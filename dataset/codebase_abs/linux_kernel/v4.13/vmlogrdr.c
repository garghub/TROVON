static void F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( & V_5 -> V_7 ) ;
V_5 -> V_8 = 1 ;
F_3 ( & V_5 -> V_7 ) ;
F_4 ( & V_9 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_10 = ( T_1 ) V_3 [ 8 ] ;
F_6 ( L_1 , V_10 ) ;
F_7 ( V_2 , NULL ) ;
F_8 ( V_2 ) ;
V_5 -> V_2 = NULL ;
F_2 ( & V_5 -> V_7 ) ;
V_5 -> V_8 = 0 ;
V_5 -> V_11 = 1 ;
F_3 ( & V_5 -> V_7 ) ;
F_4 ( & V_9 ) ;
F_9 ( & V_12 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( & V_5 -> V_7 ) ;
memcpy ( & V_5 -> V_15 , V_14 , sizeof( * V_14 ) ) ;
F_11 ( & V_5 -> V_16 ) ;
F_3 ( & V_5 -> V_7 ) ;
F_9 ( & V_12 ) ;
}
static int F_12 ( void )
{
static const char V_17 [] = L_2 ;
char V_18 [ 80 ] ;
char * V_19 ;
int V_20 , V_21 ;
F_13 ( V_17 , V_18 , sizeof( V_18 ) , NULL ) ;
V_20 = F_14 ( V_18 , sizeof( V_18 ) ) ;
V_19 = F_15 ( V_18 , V_20 , '=' ) ;
if ( ! V_19 )
return 0 ;
V_19 ++ ;
if ( ! strncmp ( L_3 , V_19 , 3 ) )
return 1 ;
if ( ! strncmp ( L_4 , V_19 , 4 ) )
return 0 ;
for ( V_21 = V_19 - V_18 ; V_21 < V_20 ; V_21 ++ )
if ( V_18 [ V_21 ] == 'A' || V_18 [ V_21 ] == 'B' )
return 1 ;
return 0 ;
}
static int F_16 ( struct V_4 * V_5 ,
int V_22 , int V_23 )
{
char V_17 [ 80 ] ;
char V_18 [ 160 ] ;
char * V_24 , * V_25 ;
int V_26 ;
V_24 = ( ( V_22 == 1 ) ? L_5 : L_6 ) ;
V_25 = ( ( V_27 == 1 ) ? L_7 : L_8 ) ;
if ( V_23 && ( V_22 == 1 ) ) {
memset ( V_17 , 0x00 , sizeof( V_17 ) ) ;
memset ( V_18 , 0x00 , sizeof( V_18 ) ) ;
snprintf ( V_17 , sizeof( V_17 ) ,
L_9 ,
V_5 -> V_28 ,
V_25 ) ;
F_13 ( V_17 , V_18 , sizeof( V_18 ) , NULL ) ;
}
memset ( V_17 , 0x00 , sizeof( V_17 ) ) ;
memset ( V_18 , 0x00 , sizeof( V_18 ) ) ;
snprintf ( V_17 , sizeof( V_17 ) , L_10 ,
V_5 -> V_28 ,
V_24 ,
V_25 ) ;
F_13 ( V_17 , V_18 , sizeof( V_18 ) , NULL ) ;
if ( strstr ( V_18 , L_11 ) )
V_26 = 0 ;
else
V_26 = - V_29 ;
if ( V_23 && ( V_22 == 0 ) ) {
memset ( V_17 , 0x00 , sizeof( V_17 ) ) ;
memset ( V_18 , 0x00 , sizeof( V_18 ) ) ;
snprintf ( V_17 , sizeof( V_17 ) ,
L_9 ,
V_5 -> V_28 ,
V_25 ) ;
F_13 ( V_17 , V_18 , sizeof( V_18 ) , NULL ) ;
}
return V_26 ;
}
static int F_17 ( struct V_30 * V_30 , struct V_31 * V_32 )
{
int V_33 = 0 ;
struct V_4 * V_5 = NULL ;
int V_34 = 0 ;
int V_35 ;
V_33 = F_18 ( V_30 ) ;
if ( V_33 >= V_36 )
return - V_37 ;
V_5 = & V_38 [ V_33 ] ;
if ( V_32 -> V_39 & V_40 )
return - V_41 ;
F_19 ( & V_5 -> V_7 ) ;
if ( V_5 -> V_42 ) {
F_20 ( & V_5 -> V_7 ) ;
return - V_43 ;
}
V_5 -> V_42 = 1 ;
V_5 -> V_8 = 0 ;
V_5 -> V_11 = 0 ;
F_21 ( & V_5 -> V_16 , 0 ) ;
V_5 -> V_44 = 1 ;
F_20 ( & V_5 -> V_7 ) ;
V_32 -> V_45 = V_5 ;
if ( V_5 -> V_46 ) {
V_35 = F_16 ( V_5 , 1 , V_5 -> V_47 ) ;
if ( V_35 )
F_22 ( L_12 ) ;
}
V_5 -> V_2 = F_23 ( 10 , 0 , V_48 ) ;
if ( ! V_5 -> V_2 )
goto V_49;
V_34 = F_24 ( V_5 -> V_2 , & V_50 ,
V_5 -> V_51 , NULL , NULL ,
V_5 ) ;
if ( V_34 ) {
F_6 ( L_13
L_14 ,
V_5 -> V_51 , V_34 ) ;
goto V_52;
}
F_25 ( V_9 , ( V_5 -> V_8 )
|| ( V_5 -> V_11 ) ) ;
if ( V_5 -> V_11 )
goto V_53;
F_26 ( V_30 , V_32 ) ;
return 0 ;
V_53:
if ( V_5 -> V_46 )
F_16 ( V_5 , 0 , V_5 -> V_47 ) ;
V_52:
F_8 ( V_5 -> V_2 ) ;
V_5 -> V_2 = NULL ;
V_49:
V_5 -> V_42 = 0 ;
return - V_29 ;
}
static int F_27 ( struct V_30 * V_30 , struct V_31 * V_32 )
{
int V_35 ;
struct V_4 * V_5 = V_32 -> V_45 ;
F_7 ( V_5 -> V_2 , NULL ) ;
F_8 ( V_5 -> V_2 ) ;
V_5 -> V_2 = NULL ;
if ( V_5 -> V_46 ) {
V_35 = F_16 ( V_5 , 0 , V_5 -> V_47 ) ;
if ( V_35 )
F_22 ( L_15 ) ;
}
V_5 -> V_42 = 0 ;
return 0 ;
}
static int F_28 ( struct V_4 * V_54 )
{
int V_26 , * V_55 ;
int V_56 , V_57 ;
char * V_58 ;
if ( F_29 ( & V_54 -> V_16 ) ) {
F_19 ( & V_54 -> V_7 ) ;
if ( V_54 -> V_59 ) {
V_57 = V_54 -> V_59 ;
V_56 = 0 ;
V_58 = V_54 -> V_58 ;
} else {
V_57 = V_54 -> V_15 . V_60 ;
V_56 = sizeof( int ) ;
V_55 = ( int * ) V_54 -> V_58 ;
* V_55 = V_57 + sizeof( V_61 ) ;
V_58 = V_54 -> V_58 + sizeof( int ) ;
}
if ( V_57 > V_62 )
V_57 = V_62 ;
V_26 = F_30 ( V_54 -> V_2 ,
& V_54 -> V_15 ,
0 , V_58 , V_57 ,
& V_54 -> V_59 ) ;
F_20 ( & V_54 -> V_7 ) ;
if ( V_26 == 5 )
V_26 = 0 ;
if ( V_26 == 9 )
F_21 ( & V_54 -> V_16 , 0 ) ;
} else {
V_26 = 1 ;
}
if ( ! V_26 ) {
V_54 -> V_44 = 0 ;
V_56 += V_57 ;
V_54 -> V_63 = V_54 -> V_58 ;
if ( V_54 -> V_59 == 0 ) {
F_31 ( & V_54 -> V_16 ) ;
V_58 = V_54 -> V_58 + V_56 ;
memcpy ( V_58 , V_61 , sizeof( V_61 ) ) ;
V_56 += sizeof( V_61 ) ;
}
V_54 -> V_64 = V_56 ;
}
return V_26 ;
}
static T_2 F_32 ( struct V_31 * V_32 , char T_3 * V_65 ,
T_4 V_66 , T_5 * V_67 )
{
int V_26 ;
struct V_4 * V_54 = V_32 -> V_45 ;
while ( V_54 -> V_44 ) {
V_26 = F_28 ( V_54 ) ;
if ( V_26 ) {
V_26 = F_33 ( V_12 ,
F_29 ( & V_54 -> V_16 ) ) ;
if ( V_26 )
return V_26 ;
}
}
if ( V_66 > V_54 -> V_64 )
V_66 = V_54 -> V_64 ;
if ( F_34 ( V_65 , V_54 -> V_63 , V_66 ) )
return - V_68 ;
* V_67 += V_66 ;
V_54 -> V_63 += V_66 ;
V_54 -> V_64 -= V_66 ;
if ( V_54 -> V_64 == 0 )
V_54 -> V_44 = 1 ;
return V_66 ;
}
static T_2 F_35 ( struct V_69 * V_70 ,
struct V_71 * V_72 ,
const char * V_73 , T_4 V_66 )
{
struct V_4 * V_54 = F_36 ( V_70 ) ;
T_2 V_35 = V_66 ;
switch ( V_73 [ 0 ] ) {
case '0' :
V_54 -> V_47 = 0 ;
break;
case '1' :
V_54 -> V_47 = 1 ;
break;
default:
V_35 = - V_74 ;
}
return V_35 ;
}
static T_2 F_37 ( struct V_69 * V_70 ,
struct V_71 * V_72 ,
char * V_73 )
{
struct V_4 * V_54 = F_36 ( V_70 ) ;
return sprintf ( V_73 , L_16 , V_54 -> V_47 ) ;
}
static T_2 F_38 ( struct V_69 * V_70 ,
struct V_71 * V_72 ,
const char * V_73 , T_4 V_66 )
{
char V_17 [ 80 ] ;
char V_18 [ 80 ] ;
struct V_4 * V_54 = F_36 ( V_70 ) ;
if ( V_73 [ 0 ] != '1' )
return - V_74 ;
memset ( V_17 , 0x00 , sizeof( V_17 ) ) ;
memset ( V_18 , 0x00 , sizeof( V_18 ) ) ;
if ( V_27 )
snprintf ( V_17 , sizeof( V_17 ) ,
L_17 ,
V_54 -> V_28 ) ;
else
snprintf ( V_17 , sizeof( V_17 ) ,
L_18 ,
V_54 -> V_28 ) ;
F_13 ( V_17 , V_18 , sizeof( V_18 ) , NULL ) ;
return V_66 ;
}
static T_2 F_39 ( struct V_69 * V_70 ,
struct V_71 * V_72 ,
const char * V_73 , T_4 V_66 )
{
struct V_4 * V_54 = F_36 ( V_70 ) ;
T_2 V_35 = V_66 ;
switch ( V_73 [ 0 ] ) {
case '0' :
V_54 -> V_46 = 0 ;
break;
case '1' :
V_54 -> V_46 = 1 ;
break;
default:
V_35 = - V_74 ;
}
return V_35 ;
}
static T_2 F_40 ( struct V_69 * V_70 ,
struct V_71 * V_72 ,
char * V_73 )
{
struct V_4 * V_54 = F_36 ( V_70 ) ;
return sprintf ( V_73 , L_16 , V_54 -> V_46 ) ;
}
static T_2 F_41 ( struct V_69 * V_70 ,
struct V_71 * V_72 ,
const char * V_73 , T_4 V_66 )
{
struct V_4 * V_54 = F_36 ( V_70 ) ;
T_2 V_35 ;
switch ( V_73 [ 0 ] ) {
case '0' :
V_35 = F_16 ( V_54 , 0 , 0 ) ;
break;
case '1' :
V_35 = F_16 ( V_54 , 1 , 0 ) ;
break;
default:
V_35 = - V_74 ;
}
if ( V_35 )
return V_35 ;
else
return V_66 ;
}
static T_2 F_42 ( struct V_75 * V_76 , char * V_73 )
{
static const char V_17 [] = L_19 ;
int V_20 ;
F_13 ( V_17 , V_73 , 4096 , NULL ) ;
V_20 = strlen ( V_73 ) ;
return V_20 ;
}
static int F_43 ( struct V_69 * V_70 )
{
int V_26 ;
struct V_4 * V_54 = F_36 ( V_70 ) ;
V_26 = 0 ;
if ( V_54 ) {
F_19 ( & V_54 -> V_7 ) ;
if ( V_54 -> V_42 )
V_26 = - V_43 ;
F_20 ( & V_54 -> V_7 ) ;
}
if ( V_26 )
F_6 ( L_20 ,
F_44 ( V_70 ) ) ;
return V_26 ;
}
static int F_45 ( void )
{
int V_35 ;
V_35 = F_46 ( & V_50 , 1 ) ;
if ( V_35 )
goto V_77;
V_35 = F_47 ( & V_78 ) ;
if ( V_35 )
goto V_79;
V_80 = F_48 ( V_81 , L_21 ) ;
if ( F_49 ( V_80 ) ) {
V_35 = F_50 ( V_80 ) ;
V_80 = NULL ;
goto V_82;
}
return 0 ;
V_82:
F_51 ( & V_78 ) ;
V_79:
F_52 ( & V_50 , 1 ) ;
V_77:
return V_35 ;
}
static void F_53 ( void )
{
F_54 ( V_80 ) ;
V_80 = NULL ;
F_51 ( & V_78 ) ;
F_52 ( & V_50 , 1 ) ;
}
static int F_55 ( struct V_4 * V_54 )
{
struct V_69 * V_70 ;
int V_35 ;
V_70 = F_56 ( sizeof( struct V_69 ) , V_48 ) ;
if ( V_70 ) {
F_57 ( V_70 , L_22 , V_54 -> V_83 ) ;
V_70 -> V_84 = & V_85 ;
V_70 -> V_86 = V_87 ;
V_70 -> V_76 = & V_78 ;
V_70 -> V_88 = V_89 ;
F_58 ( V_70 , V_54 ) ;
V_70 -> V_90 = ( void ( * ) ( struct V_69 * ) ) F_8 ;
} else
return - V_91 ;
V_35 = F_59 ( V_70 ) ;
if ( V_35 ) {
F_60 ( V_70 ) ;
return V_35 ;
}
V_54 -> V_92 = F_61 ( V_80 , V_70 ,
F_62 ( V_93 ,
V_54 -> V_94 ) ,
V_54 , L_22 , F_44 ( V_70 ) ) ;
if ( F_49 ( V_54 -> V_92 ) ) {
V_35 = F_50 ( V_54 -> V_92 ) ;
V_54 -> V_92 = NULL ;
F_63 ( V_70 ) ;
return V_35 ;
}
V_54 -> V_69 = V_70 ;
return 0 ;
}
static int F_64 ( struct V_4 * V_54 )
{
F_65 ( V_80 , F_62 ( V_93 , V_54 -> V_94 ) ) ;
if ( V_54 -> V_69 != NULL ) {
F_63 ( V_54 -> V_69 ) ;
V_54 -> V_69 = NULL ;
}
return 0 ;
}
static int F_66 ( T_6 V_70 )
{
int V_26 = 0 ;
V_95 = F_67 () ;
if ( ! V_95 ) {
return - V_91 ;
}
V_95 -> V_96 = V_81 ;
V_95 -> V_97 = & V_98 ;
V_95 -> V_70 = V_70 ;
V_26 = F_68 ( V_95 , V_95 -> V_70 , V_36 ) ;
if ( ! V_26 )
return 0 ;
F_69 ( & V_95 -> V_99 ) ;
V_95 = NULL ;
return V_26 ;
}
static void F_70 ( void )
{
int V_21 ;
if ( V_95 ) {
F_71 ( V_95 ) ;
V_95 = NULL ;
}
for ( V_21 = 0 ; V_21 < V_36 ; ++ V_21 ) {
F_64 ( & V_38 [ V_21 ] ) ;
F_72 ( ( unsigned long ) V_38 [ V_21 ] . V_58 ) ;
}
F_53 () ;
if ( V_93 ) {
F_73 ( F_62 ( V_93 , 0 ) , V_36 ) ;
V_93 = 0 ;
}
}
static int T_7 F_74 ( void )
{
int V_26 ;
int V_21 ;
T_6 V_70 ;
if ( ! V_100 ) {
F_6 ( L_23 ) ;
return - V_37 ;
}
V_27 = F_12 () ;
V_26 = F_75 ( & V_70 , 0 , V_36 , L_21 ) ;
if ( V_26 )
return V_26 ;
V_93 = F_76 ( V_70 ) ;
V_26 = F_45 () ;
if ( V_26 )
goto V_101;
for ( V_21 = 0 ; V_21 < V_36 ; ++ V_21 ) {
V_38 [ V_21 ] . V_58 = ( char * ) F_77 ( V_48 | V_102 ) ;
if ( ! V_38 [ V_21 ] . V_58 ) {
V_26 = - V_91 ;
break;
}
V_38 [ V_21 ] . V_63 = V_38 [ V_21 ] . V_58 ;
V_26 = F_55 ( & V_38 [ V_21 ] ) ;
if ( V_26 )
break;
}
if ( V_26 )
goto V_101;
V_26 = F_66 ( V_70 ) ;
if ( V_26 )
goto V_101;
return 0 ;
V_101:
F_70 () ;
return V_26 ;
}
static void T_8 F_78 ( void )
{
F_70 () ;
return;
}
