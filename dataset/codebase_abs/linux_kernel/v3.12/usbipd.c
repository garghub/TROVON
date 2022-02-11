static void F_1 ( void )
{
printf ( L_1 , V_1 ) ;
}
static int F_2 ( int V_2 )
{
struct V_3 V_4 ;
struct V_5 V_6 ;
struct V_7 * V_8 ;
struct V_9 V_10 ;
int V_11 = 0 ;
int error = 0 ;
int V_12 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_12 = F_3 ( V_2 , & V_4 , sizeof( V_4 ) ) ;
if ( V_12 < 0 ) {
F_4 ( L_2 ) ;
return - 1 ;
}
F_5 ( 0 , & V_4 ) ;
F_6 (host_driver->edev_list, edev,
struct usbip_exported_device) {
if ( ! strncmp ( V_4 . V_13 , V_8 -> V_14 . V_13 , V_15 ) ) {
F_7 ( L_3 , V_4 . V_13 ) ;
V_11 = 1 ;
break;
}
}
if ( V_11 ) {
F_8 ( V_2 ) ;
V_12 = F_9 ( V_8 , V_2 ) ;
if ( V_12 < 0 )
error = 1 ;
} else {
F_7 ( L_4 , V_4 . V_13 ) ;
error = 1 ;
}
V_12 = F_10 ( V_2 , V_16 ,
( ! error ? V_17 : V_18 ) ) ;
if ( V_12 < 0 ) {
F_4 ( L_5 , V_16 ) ;
return - 1 ;
}
if ( error ) {
F_4 ( L_6 , V_4 . V_13 ) ;
return - 1 ;
}
memcpy ( & V_10 , & V_8 -> V_14 , sizeof( V_10 ) ) ;
F_11 ( 1 , & V_10 ) ;
V_12 = F_12 ( V_2 , & V_10 , sizeof( V_10 ) ) ;
if ( V_12 < 0 ) {
F_4 ( L_7 ) ;
return - 1 ;
}
F_4 ( L_8 , V_4 . V_13 ) ;
return 0 ;
}
static int F_13 ( int V_19 )
{
struct V_7 * V_8 ;
struct V_9 V_10 ;
struct V_20 V_21 ;
struct V_22 V_6 ;
int V_23 ;
int V_12 ;
V_6 . V_24 = 0 ;
F_6 (host_driver->edev_list, edev,
struct usbip_exported_device) {
V_6 . V_24 += 1 ;
}
F_7 ( L_9 , V_6 . V_24 ) ;
V_12 = F_10 ( V_19 , V_25 , V_17 ) ;
if ( V_12 < 0 ) {
F_4 ( L_5 , V_25 ) ;
return - 1 ;
}
F_14 ( 1 , & V_6 ) ;
V_12 = F_12 ( V_19 , & V_6 , sizeof( V_6 ) ) ;
if ( V_12 < 0 ) {
F_4 ( L_10 , V_25 ) ;
return - 1 ;
}
F_6 (host_driver->edev_list, edev,
struct usbip_exported_device) {
F_15 ( & V_8 -> V_14 ) ;
memcpy ( & V_10 , & V_8 -> V_14 , sizeof( V_10 ) ) ;
F_11 ( 1 , & V_10 ) ;
V_12 = F_12 ( V_19 , & V_10 , sizeof( V_10 ) ) ;
if ( V_12 < 0 ) {
F_4 ( L_11 ) ;
return - 1 ;
}
for ( V_23 = 0 ; V_23 < V_8 -> V_14 . V_26 ; V_23 ++ ) {
F_16 ( & V_8 -> V_27 [ V_23 ] ) ;
memcpy ( & V_21 , & V_8 -> V_27 [ V_23 ] , sizeof( V_21 ) ) ;
F_17 ( 1 , & V_21 ) ;
V_12 = F_12 ( V_19 , & V_21 ,
sizeof( V_21 ) ) ;
if ( V_12 < 0 ) {
F_4 ( L_12 ) ;
return - 1 ;
}
}
}
return 0 ;
}
static int F_18 ( int V_19 )
{
struct V_28 V_4 ;
int V_12 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_12 = F_3 ( V_19 , & V_4 , sizeof( V_4 ) ) ;
if ( V_12 < 0 ) {
F_4 ( L_13 ) ;
return - 1 ;
}
V_12 = F_13 ( V_19 ) ;
if ( V_12 < 0 ) {
F_4 ( L_14 ) ;
return - 1 ;
}
return 0 ;
}
static int F_19 ( int V_19 )
{
T_1 V_29 = V_30 ;
int V_31 ;
V_31 = F_20 ( V_19 , & V_29 ) ;
if ( V_31 < 0 ) {
F_4 ( L_15 , V_29 ) ;
return - 1 ;
}
V_31 = F_21 () ;
if ( V_31 < 0 ) {
F_4 ( L_16 , V_31 ) ;
return - 1 ;
}
F_7 ( L_17 , V_29 , V_19 ) ;
switch ( V_29 ) {
case V_32 :
V_31 = F_18 ( V_19 ) ;
break;
case V_33 :
V_31 = F_2 ( V_19 ) ;
break;
case V_34 :
case V_35 :
default:
F_22 ( L_18 , V_29 ) ;
V_31 = - 1 ;
}
if ( V_31 == 0 )
F_7 ( L_19 , V_29 , V_19 ) ;
else
F_7 ( L_20 , V_29 , V_19 ) ;
return V_31 ;
}
static int F_23 ( int V_19 )
{
struct V_36 V_37 ;
int V_12 ;
F_24 ( & V_37 , V_38 , V_39 , V_40 , V_19 , 0 ) ;
F_25 ( & V_37 ) ;
V_12 = F_26 ( & V_37 ) ;
if ( V_12 == 0 )
return - 1 ;
return 0 ;
}
static int F_27 ( int V_41 )
{
int V_19 ;
struct V_42 V_43 ;
T_2 V_44 = sizeof( V_43 ) ;
char V_45 [ V_46 ] , V_47 [ V_48 ] ;
int V_12 ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_19 = F_28 ( V_41 , (struct V_49 * ) & V_43 , & V_44 ) ;
if ( V_19 < 0 ) {
F_22 ( L_21 ) ;
return - 1 ;
}
V_12 = F_29 ( (struct V_49 * ) & V_43 , V_44 , V_45 , sizeof( V_45 ) ,
V_47 , sizeof( V_47 ) , V_50 | V_51 ) ;
if ( V_12 )
F_22 ( L_22 , F_30 ( V_12 ) ) ;
#ifdef F_31
V_12 = F_23 ( V_19 ) ;
if ( V_12 < 0 ) {
F_7 ( L_23 , V_45 ) ;
F_32 ( V_19 ) ;
return - 1 ;
}
#endif
F_7 ( L_24 , V_45 , V_47 ) ;
return V_19 ;
}
int F_33 ( int V_41 )
{
T_3 V_52 ;
int V_19 ;
V_19 = F_27 ( V_41 ) ;
if ( V_19 < 0 )
return - 1 ;
V_52 = F_34 () ;
if ( V_52 == 0 ) {
F_32 ( V_41 ) ;
F_19 ( V_19 ) ;
exit ( 0 ) ;
}
F_32 ( V_19 ) ;
return 0 ;
}
static void F_35 ( struct V_53 * V_54 , char V_55 [] ,
const T_4 V_56 )
{
char V_57 [ V_46 ] ;
char V_58 [ V_48 ] ;
int V_12 ;
V_55 [ 0 ] = '\0' ;
V_12 = F_29 ( V_54 -> V_59 , V_54 -> V_60 , V_57 , sizeof( V_57 ) ,
V_58 , sizeof( V_58 ) , V_50 | V_51 ) ;
if ( V_12 )
F_22 ( L_22 , F_30 ( V_12 ) ) ;
snprintf ( V_55 , V_56 , L_25 , V_57 , V_58 ) ;
}
static int F_36 ( struct V_53 * V_61 , int V_62 [] )
{
struct V_53 * V_54 ;
int V_31 , V_63 = 0 ;
const T_4 V_64 = V_46 + V_48 + 2 ;
char V_65 [ V_64 ] ;
for ( V_54 = V_61 ; V_54 && V_63 < V_66 ; V_54 = V_54 -> V_67 ) {
int V_68 ;
F_35 ( V_54 , V_65 , V_64 ) ;
F_4 ( L_26 , V_65 ) ;
V_68 = F_37 ( V_54 -> V_69 , V_54 -> V_70 , V_54 -> V_71 ) ;
if ( V_68 < 0 ) {
F_22 ( L_27 ,
V_65 , V_72 , strerror ( V_72 ) ) ;
continue;
}
F_38 ( V_68 ) ;
F_8 ( V_68 ) ;
if ( V_68 >= V_73 ) {
F_22 ( L_28 ,
V_65 , V_68 , V_73 ) ;
F_32 ( V_68 ) ;
continue;
}
V_31 = F_39 ( V_68 , V_54 -> V_59 , V_54 -> V_60 ) ;
if ( V_31 < 0 ) {
F_22 ( L_29 ,
V_65 , V_72 , strerror ( V_72 ) ) ;
F_32 ( V_68 ) ;
continue;
}
V_31 = F_40 ( V_68 , V_74 ) ;
if ( V_31 < 0 ) {
F_22 ( L_30 ,
V_65 , V_72 , strerror ( V_72 ) ) ;
F_32 ( V_68 ) ;
continue;
}
F_7 ( L_31 , V_65 ) ;
V_62 [ V_63 ++ ] = V_68 ;
}
if ( V_63 == 0 )
return - 1 ;
F_4 ( L_32 , V_63 , ( V_63 == 1 ) ? L_33 : L_34 ) ;
return V_63 ;
}
static struct V_53 * F_41 ( char * V_45 , int V_69 )
{
struct V_53 V_75 , * V_61 ;
int V_12 ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_69 = V_69 ;
V_75 . V_70 = V_76 ;
V_75 . V_77 = V_78 ;
V_12 = F_42 ( V_45 , V_79 , & V_75 , & V_61 ) ;
if ( V_12 ) {
F_22 ( L_35 , V_79 ,
F_30 ( V_12 ) ) ;
return NULL ;
}
return V_61 ;
}
static void F_43 ( int V_23 )
{
F_4 ( L_36 , F_44 ( V_23 ) ) ;
}
static void F_45 ( void )
{
struct V_80 V_81 ;
memset ( & V_81 , 0 , sizeof( V_81 ) ) ;
V_81 . V_82 = F_43 ;
F_46 ( & V_81 . V_83 ) ;
V_80 ( V_84 , & V_81 , NULL ) ;
V_80 ( V_85 , & V_81 , NULL ) ;
V_81 . V_82 = V_86 ;
V_80 ( V_87 , & V_81 , NULL ) ;
}
static void F_47 ()
{
if ( V_88 ) {
F_4 ( L_37 , V_88 ) ;
T_5 * V_89 = fopen ( V_88 , L_38 ) ;
if ( ! V_89 ) {
F_22 ( L_39 ,
V_88 , V_72 , strerror ( V_72 ) ) ;
return;
}
fprintf ( V_89 , L_40 , F_48 () ) ;
fclose ( V_89 ) ;
}
}
static void F_49 ()
{
if ( V_88 ) {
F_4 ( L_41 , V_88 ) ;
F_50 ( V_88 ) ;
}
}
static int F_51 ( int V_90 )
{
struct V_53 * V_61 ;
int V_62 [ V_66 ] ;
int V_63 ;
int V_23 , V_91 ;
struct V_92 * V_93 ;
struct V_94 V_95 ;
T_6 V_96 ;
if ( F_52 () ) {
F_22 ( L_42 V_97 L_43
V_98 L_44 ) ;
return - 1 ;
}
if ( V_90 ) {
if ( F_53 ( 0 , 0 ) < 0 ) {
F_22 ( L_45 , strerror ( V_72 ) ) ;
F_54 () ;
return - 1 ;
}
F_55 ( 0 ) ;
V_99 = 1 ;
}
F_45 () ;
F_47 () ;
V_61 = F_41 ( NULL , V_100 ) ;
if ( ! V_61 ) {
F_54 () ;
return - 1 ;
}
F_7 ( L_46 V_39 L_47 , V_101 ) ;
V_63 = F_36 ( V_61 , V_62 ) ;
if ( V_63 <= 0 ) {
F_22 ( L_48 ) ;
F_56 ( V_61 ) ;
F_54 () ;
return - 1 ;
}
V_93 = calloc ( V_63 , sizeof( struct V_92 ) ) ;
for ( V_23 = 0 ; V_23 < V_63 ; V_23 ++ ) {
V_93 [ V_23 ] . V_102 = V_62 [ V_23 ] ;
V_93 [ V_23 ] . V_103 = V_104 ;
}
V_95 . V_105 = V_106 ;
V_95 . V_107 = 0 ;
F_57 ( & V_96 ) ;
F_58 ( & V_96 , V_84 ) ;
F_58 ( & V_96 , V_85 ) ;
V_91 = 0 ;
while ( ! V_91 ) {
int V_108 ;
V_108 = F_59 ( V_93 , V_63 , & V_95 , & V_96 ) ;
if ( V_108 < 0 ) {
F_4 ( L_49 , strerror ( V_72 ) ) ;
V_91 = 1 ;
} else if ( V_108 ) {
for ( V_23 = 0 ; V_23 < V_63 ; V_23 ++ ) {
if ( V_93 [ V_23 ] . V_109 & V_104 ) {
F_4 ( L_50 ,
V_23 , V_62 [ V_23 ] ) ;
F_33 ( V_62 [ V_23 ] ) ;
}
}
} else {
F_4 ( L_51 ) ;
}
}
F_7 ( L_52 V_39 ) ;
free ( V_93 ) ;
F_56 ( V_61 ) ;
F_54 () ;
return 0 ;
}
int main ( int V_110 , char * V_111 [] )
{
static const struct V_112 V_113 [] = {
{ L_53 , V_114 , NULL , 'D' } ,
{ L_54 , V_114 , NULL , 'd' } ,
{ L_55 , V_115 , NULL , 'P' } ,
{ L_56 , V_116 , NULL , 't' } ,
{ L_57 , V_114 , NULL , 'h' } ,
{ L_58 , V_114 , NULL , 'v' } ,
{ NULL , 0 , NULL , 0 }
} ;
enum {
V_117 = 1 ,
V_118 ,
V_119
} V_120 ;
int V_90 = 0 ;
int V_121 , V_12 = - 1 ;
V_88 = NULL ;
V_122 = 1 ;
V_99 = 0 ;
if ( F_60 () != 0 )
F_22 ( L_59 ) ;
V_120 = V_117 ;
for (; ; ) {
V_121 = F_61 ( V_110 , V_111 , L_60 , V_113 , NULL ) ;
if ( V_121 == - 1 )
break;
switch ( V_121 ) {
case 'D' :
V_90 = 1 ;
break;
case 'd' :
V_123 = 1 ;
break;
case 'h' :
V_120 = V_118 ;
break;
case 'P' :
V_88 = V_124 ? V_124 : V_125 ;
break;
case 't' :
F_62 ( V_124 ) ;
break;
case 'v' :
V_120 = V_119 ;
break;
case '?' :
F_1 () ;
default:
goto V_126;
}
}
switch ( V_120 ) {
case V_117 :
V_12 = F_51 ( V_90 ) ;
F_49 () ;
break;
case V_119 :
printf ( V_39 L_61 , V_101 ) ;
V_12 = 0 ;
break;
case V_118 :
F_1 () ;
V_12 = 0 ;
break;
default:
F_1 () ;
goto V_126;
}
V_126:
return ( V_12 > - 1 ? V_127 : V_128 ) ;
}
