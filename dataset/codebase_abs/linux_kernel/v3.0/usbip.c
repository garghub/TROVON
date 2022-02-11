static int F_1 ( char * V_1 )
{
char * V_2 ;
V_2 = strstr ( V_1 , V_3 -> V_4 -> V_5 ) ;
if ( ! V_2 )
return - 1 ;
V_2 ++ ;
V_2 = strchr ( V_2 , '/' ) ;
if ( ! V_2 )
return - 1 ;
V_2 ++ ;
V_2 = strchr ( V_2 , '/' ) ;
if ( ! V_2 )
return - 1 ;
V_2 ++ ;
V_2 = strchr ( V_2 , ':' ) ;
if ( ! V_2 )
return - 1 ;
V_2 ++ ;
V_2 = strchr ( V_2 , '.' ) ;
if ( ! V_2 )
return - 1 ;
V_2 ++ ;
return atoi ( V_2 ) ;
}
static struct V_6 * F_2 ( struct V_7 * V_8 , int V_9 )
{
struct V_6 * V_10 ;
char V_11 [ V_12 ] ;
snprintf ( V_11 , V_12 , L_1 ,
V_8 -> V_11 , V_8 -> V_13 , V_9 ) ;
V_10 = F_3 ( L_2 , V_11 ) ;
if ( ! V_10 )
F_4 ( L_3 , V_11 ) ;
return V_10 ;
}
static int F_5 ( char * V_14 , char * V_15 , char * V_11 , int V_16 )
{
int V_17 ;
char V_1 [ V_18 + 1 ] ;
char V_19 [ V_20 + 1 ] ;
int V_21 ;
F_6 ( V_22 , 0700 ) ;
snprintf ( V_1 , V_18 , V_22 L_4 , V_16 ) ;
V_17 = F_7 ( V_1 , V_23 | V_24 | V_25 , V_26 ) ;
if ( V_17 < 0 )
return - 1 ;
snprintf ( V_19 , V_20 , L_5 ,
V_14 , V_15 , V_11 ) ;
V_21 = F_8 ( V_17 , V_19 , strlen ( V_19 ) ) ;
if ( V_21 != ( V_27 ) strlen ( V_19 ) ) {
F_9 ( V_17 ) ;
return - 1 ;
}
F_9 ( V_17 ) ;
return 0 ;
}
static int F_10 ( int V_16 , char * V_14 , char * V_15 , char * V_11 )
{
T_1 * V_28 ;
char V_1 [ V_18 + 1 ] ;
snprintf ( V_1 , V_18 , V_22 L_4 , V_16 ) ;
V_28 = fopen ( V_1 , L_6 ) ;
if ( ! V_28 ) {
F_4 ( L_7 ) ;
return - 1 ;
}
if ( fscanf ( V_28 , L_5 , V_14 , V_15 , V_11 ) != 3 ) {
F_4 ( L_8 ) ;
fclose ( V_28 ) ;
return - 1 ;
}
fclose ( V_28 ) ;
return 0 ;
}
int F_11 ( struct V_29 * V_30 )
{
char V_31 [ 100 ] ;
char V_14 [ V_32 ] = L_9 ;
char V_33 [ V_34 ] = L_10 ;
char V_35 [ V_12 ] ;
int V_21 ;
if ( V_30 -> V_36 == V_37 || V_30 -> V_36 == V_38 ) {
F_12 ( L_11 , V_30 -> V_15 , F_13 ( V_30 -> V_36 ) ) ;
return 0 ;
}
V_21 = F_10 ( V_30 -> V_15 , V_14 , V_33 , V_35 ) ;
if ( V_21 ) {
F_4 ( L_12 ) ;
return - 1 ;
}
F_12 ( L_13 , V_30 -> V_15 ,
F_13 ( V_30 -> V_36 ) , F_14 ( V_30 -> V_8 . V_39 ) ) ;
F_15 ( V_31 , sizeof( V_31 ) ,
V_30 -> V_8 . V_40 , V_30 -> V_8 . V_41 ) ;
F_12 ( L_14 , V_31 ) ;
F_12 ( L_15 ,
V_30 -> V_8 . V_11 , V_14 , V_33 , V_35 ,
V_30 -> V_42 ,
V_30 -> V_43 , V_30 -> V_44 ) ;
for ( int V_9 = 0 ; V_9 < V_30 -> V_8 . V_45 ; V_9 ++ ) {
struct V_6 * V_10 ;
V_10 = F_2 ( & V_30 -> V_8 , V_9 ) ;
if ( ! V_10 )
continue;
F_12 ( L_16 , V_10 -> V_5 , V_10 -> V_46 ) ;
F_16 ( V_10 ) ;
struct V_47 * V_48 ;
F_17 (idev->cdev_list, cdev, struct class_device) {
int V_49 = F_1 ( V_48 -> V_50 ) ;
if ( V_49 == V_9 ) {
F_12 ( L_17 , V_48 -> V_51 ) ;
}
}
}
return 0 ;
}
static int F_18 ( int V_52 )
{
int V_21 ;
struct V_53 V_54 ;
T_2 V_55 = V_56 ;
F_19 ( & V_54 , sizeof( V_54 ) ) ;
V_21 = F_20 ( V_52 , V_57 , 0 ) ;
if ( V_21 < 0 ) {
F_4 ( L_18 ) ;
return - 1 ;
}
V_21 = F_21 ( V_52 , & V_55 ) ;
if ( V_21 < 0 ) {
F_4 ( L_19 ) ;
return - 1 ;
}
V_21 = F_22 ( V_52 , ( void * ) & V_54 , sizeof( V_54 ) ) ;
if ( V_21 < 0 ) {
F_4 ( L_20 ) ;
return - 1 ;
}
F_23 ( 0 , & V_54 ) ;
F_24 ( L_21 , V_54 . V_58 ) ;
for ( unsigned int V_9 = 0 ; V_9 < V_54 . V_58 ; V_9 ++ ) {
char V_31 [ 100 ] ;
char V_59 [ 100 ] ;
struct V_7 V_8 ;
F_19 ( & V_8 , sizeof( V_8 ) ) ;
V_21 = F_22 ( V_52 , ( void * ) & V_8 , sizeof( V_8 ) ) ;
if ( V_21 < 0 ) {
F_4 ( L_22 , V_9 ) ;
return - 1 ;
}
F_25 ( 0 , & V_8 ) ;
F_15 ( V_31 , sizeof( V_31 ) ,
V_8 . V_40 , V_8 . V_41 ) ;
F_26 ( V_59 , sizeof( V_59 ) , V_8 . V_60 ,
V_8 . V_61 , V_8 . V_62 ) ;
F_12 ( L_23 , V_8 . V_11 , V_31 ) ;
F_12 ( L_23 , L_24 , V_8 . V_1 ) ;
F_12 ( L_23 , L_24 , V_59 ) ;
for ( int V_63 = 0 ; V_63 < V_8 . V_45 ; V_63 ++ ) {
struct V_64 V_65 ;
V_21 = F_22 ( V_52 , ( void * ) & V_65 , sizeof( V_65 ) ) ;
if ( V_21 < 0 ) {
F_4 ( L_25 , V_63 ) ;
return - 1 ;
}
F_27 ( 0 , & V_65 ) ;
F_26 ( V_59 , sizeof( V_59 ) , V_65 . V_66 ,
V_65 . V_67 , V_65 . V_68 ) ;
F_12 ( L_26 , L_24 , V_63 , V_59 ) ;
}
F_12 ( L_24 ) ;
}
return V_54 . V_58 ;
}
static int F_28 ( int V_52 , struct V_7 * V_8 )
{
int V_21 ;
int V_15 ;
V_21 = F_29 () ;
if ( V_21 < 0 ) {
F_4 ( L_27 ) ;
return - 1 ;
}
V_15 = F_30 () ;
if ( V_15 < 0 ) {
F_4 ( L_28 ) ;
F_31 () ;
return - 1 ;
}
V_21 = F_32 ( V_15 , V_52 , V_8 -> V_43 ,
V_8 -> V_44 , V_8 -> V_39 ) ;
if ( V_21 < 0 ) {
F_4 ( L_29 ) ;
F_31 () ;
return - 1 ;
}
F_31 () ;
return V_15 ;
}
static int F_33 ( int V_52 , char * V_11 )
{
int V_21 ;
struct V_69 V_70 ;
struct V_71 V_72 ;
T_2 V_55 = V_73 ;
F_19 ( & V_70 , sizeof( V_70 ) ) ;
F_19 ( & V_72 , sizeof( V_72 ) ) ;
V_21 = F_20 ( V_52 , V_74 , 0 ) ;
if ( V_21 < 0 ) {
F_4 ( L_18 ) ;
return - 1 ;
}
strncpy ( V_70 . V_11 , V_11 , V_12 - 1 ) ;
F_34 ( 0 , & V_70 ) ;
V_21 = F_35 ( V_52 , ( void * ) & V_70 , sizeof( V_70 ) ) ;
if ( V_21 < 0 ) {
F_4 ( L_30 ) ;
return - 1 ;
}
V_21 = F_21 ( V_52 , & V_55 ) ;
if ( V_21 < 0 ) {
F_4 ( L_19 ) ;
return - 1 ;
}
V_21 = F_22 ( V_52 , ( void * ) & V_72 , sizeof( V_72 ) ) ;
if ( V_21 < 0 ) {
F_4 ( L_31 ) ;
return - 1 ;
}
F_36 ( 0 , & V_72 ) ;
if ( strncmp ( V_72 . V_8 . V_11 , V_11 , V_12 ) ) {
F_4 ( L_32 , V_72 . V_8 . V_11 ) ;
return - 1 ;
}
return F_28 ( V_52 , & V_72 . V_8 ) ;
}
static int F_37 ( char * V_14 , char * V_11 )
{
int V_52 ;
int V_21 ;
int V_16 ;
V_52 = F_38 ( V_14 , V_75 ) ;
if ( V_52 < 0 ) {
F_4 ( L_33 ) ;
return - 1 ;
}
V_16 = F_33 ( V_52 , V_11 ) ;
if ( V_16 < 0 ) {
F_4 ( L_34 ) ;
return - 1 ;
}
F_9 ( V_52 ) ;
V_21 = F_5 ( V_14 , V_75 ,
V_11 , V_16 ) ;
if ( V_21 < 0 ) {
F_4 ( L_35 ) ;
return - 1 ;
}
return 0 ;
}
static int F_39 ( char * V_15 )
{
int V_21 ;
T_3 V_76 ;
for ( unsigned int V_9 = 0 ; V_9 < strlen ( V_15 ) ; V_9 ++ )
if ( ! isdigit ( V_15 [ V_9 ] ) ) {
F_4 ( L_36 , V_15 ) ;
return - 1 ;
}
V_76 = atoi ( V_15 ) ;
V_21 = F_29 () ;
if ( V_21 < 0 ) {
F_4 ( L_27 ) ;
return - 1 ;
}
V_21 = F_40 ( V_76 ) ;
if ( V_21 < 0 )
return - 1 ;
F_31 () ;
return V_21 ;
}
static int F_41 ( char * V_14 )
{
int V_21 ;
int V_52 ;
V_52 = F_38 ( V_14 , V_75 ) ;
if ( V_52 < 0 ) {
F_4 ( L_37 , V_14 ) ;
return - 1 ;
}
F_12 ( L_38 , V_14 ) ;
V_21 = F_18 ( V_52 ) ;
if ( V_21 < 0 ) {
F_4 ( L_34 ) ;
return - 1 ;
}
F_9 ( V_52 ) ;
return 0 ;
}
static int F_42 ( char * V_14 , int V_52 )
{
int V_21 ;
struct V_53 V_54 ;
T_2 V_55 = V_56 ;
F_19 ( & V_54 , sizeof( V_54 ) ) ;
V_21 = F_20 ( V_52 , V_57 , 0 ) ;
if( V_21 < 0 ) {
F_4 ( L_18 ) ;
return - 1 ;
}
V_21 = F_21 ( V_52 , & V_55 ) ;
if( V_21 < 0 ) {
F_4 ( L_19 ) ;
return - 1 ;
}
V_21 = F_22 ( V_52 , ( void * ) & V_54 , sizeof( V_54 ) ) ;
if( V_21 < 0 ) {
F_4 ( L_20 ) ;
return - 1 ;
}
F_23 ( 0 , & V_54 ) ;
F_24 ( L_21 , V_54 . V_58 ) ;
for( unsigned int V_9 = 0 ; V_9 < V_54 . V_58 ; V_9 ++ ) {
char V_31 [ 100 ] ;
char V_59 [ 100 ] ;
struct V_7 V_8 ;
F_19 ( & V_8 , sizeof( V_8 ) ) ;
V_21 = F_22 ( V_52 , ( void * ) & V_8 , sizeof( V_8 ) ) ;
if( V_21 < 0 ) {
F_4 ( L_22 , V_9 ) ;
return - 1 ;
}
F_25 ( 0 , & V_8 ) ;
F_15 ( V_31 , sizeof( V_31 ) ,
V_8 . V_40 , V_8 . V_41 ) ;
F_26 ( V_59 , sizeof( V_59 ) , V_8 . V_60 ,
V_8 . V_61 , V_8 . V_62 ) ;
F_24 ( L_39 , V_8 . V_11 , V_14 , V_31 ) ;
for ( int V_63 = 0 ; V_63 < V_8 . V_45 ; V_63 ++ ) {
struct V_64 V_65 ;
V_21 = F_22 ( V_52 , ( void * ) & V_65 , sizeof( V_65 ) ) ;
if ( V_21 < 0 ) {
F_4 ( L_25 , V_63 ) ;
return - 1 ;
}
F_27 ( 0 , & V_65 ) ;
F_26 ( V_59 , sizeof( V_59 ) , V_65 . V_66 ,
V_65 . V_67 , V_65 . V_68 ) ;
F_24 ( L_40 , V_63 , V_59 ) ;
}
F_37 ( V_14 , V_8 . V_11 ) ;
}
return V_54 . V_58 ;
}
static int F_43 ( char * V_14 )
{
int V_21 ;
int V_52 ;
V_52 = F_38 ( V_14 , V_75 ) ;
if( V_52 < 0 ) {
F_4 ( L_37 , V_14 ) ;
return - 1 ;
}
F_12 ( L_38 , V_14 ) ;
V_21 = F_42 ( V_14 , V_52 ) ;
if( V_21 < 0 ) {
F_4 ( L_34 ) ;
return - 1 ;
}
F_9 ( V_52 ) ;
return 0 ;
}
static void F_44 ( void )
{
printf ( L_41 , V_77 ) ;
}
static int F_45 ( void )
{
int V_21 ;
struct V_29 * V_30 ;
V_21 = F_29 () ;
if ( V_21 < 0 )
return V_21 ;
for ( int V_9 = 0 ; V_9 < V_3 -> V_78 ; V_9 ++ ) {
V_30 = & V_3 -> V_30 [ V_9 ] ;
if ( F_11 ( V_30 ) < 0 )
V_21 = - 1 ;
}
F_31 () ;
return V_21 ;
}
int main ( int V_79 , char * V_80 [] )
{
int V_21 ;
enum {
V_81 = 1 ,
V_82 ,
V_83 ,
V_84 ,
V_85 ,
V_86 ,
V_87
} V_88 = 0 ;
V_89 = 1 ;
if ( F_46 () != 0 )
F_47 ( L_42 ) ;
V_21 = F_48 ( V_90 ) ;
if ( V_21 )
F_49 ( L_43 , V_90 ) ;
for (; ; ) {
int V_2 ;
int V_91 = 0 ;
V_2 = F_50 ( V_79 , V_80 , L_44 , V_92 , & V_91 ) ;
if ( V_2 == - 1 )
break;
switch( V_2 ) {
case 'a' :
if ( ! V_88 )
V_88 = V_81 ;
else
V_88 = V_86 ;
break;
case 'd' :
if ( ! V_88 )
V_88 = V_83 ;
else
V_88 = V_86 ;
break;
case 'p' :
if ( ! V_88 )
V_88 = V_84 ;
else V_88 = V_86 ;
break;
case 'l' :
if ( ! V_88 )
V_88 = V_85 ;
else
V_88 = V_86 ;
break;
case 'v' :
if ( ! V_88 )
V_88 = V_87 ;
else
V_88 = V_86 ;
break;
case 'x' :
if( ! V_88 )
V_88 = V_82 ;
else
V_88 = V_86 ;
break;
case 'h' :
V_88 = V_86 ;
break;
case 'D' :
V_93 = 1 ;
break;
case 'S' :
V_94 = 1 ;
break;
case '?' :
break;
default:
F_4 ( L_45 ) ;
}
}
V_21 = 0 ;
switch( V_88 ) {
case V_81 :
if ( V_95 == V_79 - 2 )
V_21 = F_37 ( V_80 [ V_95 ] , V_80 [ V_95 + 1 ] ) ;
else
F_44 () ;
break;
case V_83 :
while ( V_95 < V_79 )
V_21 = F_39 ( V_80 [ V_95 ++ ] ) ;
break;
case V_84 :
V_21 = F_45 () ;
break;
case V_85 :
while ( V_95 < V_79 )
V_21 = F_41 ( V_80 [ V_95 ++ ] ) ;
break;
case V_82 :
while( V_95 < V_79 )
V_21 = F_43 ( V_80 [ V_95 ++ ] ) ;
break;
case V_87 :
printf ( L_46 , V_96 ) ;
break;
case V_86 :
F_44 () ;
break;
default:
F_44 () ;
}
F_51 () ;
exit ( ( V_21 == 0 ) ? V_97 : V_98 ) ;
}
