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
static int F_36 ( struct V_53 * V_61 , int V_62 [] ,
int V_63 )
{
struct V_53 * V_54 ;
int V_31 , V_64 = 0 ;
const T_4 V_65 = V_46 + V_48 + 2 ;
char V_66 [ V_65 ] ;
for ( V_54 = V_61 ; V_54 && V_64 < V_63 ; V_54 = V_54 -> V_67 ) {
int V_68 ;
F_35 ( V_54 , V_66 , V_65 ) ;
F_4 ( L_26 , V_66 ) ;
V_68 = F_37 ( V_54 -> V_69 , V_54 -> V_70 , V_54 -> V_71 ) ;
if ( V_68 < 0 ) {
F_22 ( L_27 ,
V_66 , V_72 , strerror ( V_72 ) ) ;
continue;
}
F_38 ( V_68 ) ;
F_8 ( V_68 ) ;
F_39 ( V_68 ) ;
if ( V_68 >= V_73 ) {
F_22 ( L_28 ,
V_66 , V_68 , V_73 ) ;
F_32 ( V_68 ) ;
continue;
}
V_31 = F_40 ( V_68 , V_54 -> V_59 , V_54 -> V_60 ) ;
if ( V_31 < 0 ) {
F_22 ( L_29 ,
V_66 , V_72 , strerror ( V_72 ) ) ;
F_32 ( V_68 ) ;
continue;
}
V_31 = F_41 ( V_68 , V_74 ) ;
if ( V_31 < 0 ) {
F_22 ( L_30 ,
V_66 , V_72 , strerror ( V_72 ) ) ;
F_32 ( V_68 ) ;
continue;
}
F_7 ( L_31 , V_66 ) ;
V_62 [ V_64 ++ ] = V_68 ;
}
return V_64 ;
}
static struct V_53 * F_42 ( char * V_45 , int V_69 )
{
struct V_53 V_75 , * V_61 ;
int V_12 ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_69 = V_69 ;
V_75 . V_70 = V_76 ;
V_75 . V_77 = V_78 ;
V_12 = F_43 ( V_45 , V_79 , & V_75 , & V_61 ) ;
if ( V_12 ) {
F_22 ( L_32 , V_79 ,
F_30 ( V_12 ) ) ;
return NULL ;
}
return V_61 ;
}
static void F_44 ( int V_23 )
{
F_4 ( L_33 , F_45 ( V_23 ) ) ;
}
static void F_46 ( void )
{
struct V_80 V_81 ;
memset ( & V_81 , 0 , sizeof( V_81 ) ) ;
V_81 . V_82 = F_44 ;
F_47 ( & V_81 . V_83 ) ;
V_80 ( V_84 , & V_81 , NULL ) ;
V_80 ( V_85 , & V_81 , NULL ) ;
V_81 . V_82 = V_86 ;
V_80 ( V_87 , & V_81 , NULL ) ;
}
static void F_48 ()
{
if ( V_88 ) {
F_4 ( L_34 , V_88 ) ;
T_5 * V_89 = fopen ( V_88 , L_35 ) ;
if ( ! V_89 ) {
F_22 ( L_36 ,
V_88 , V_72 , strerror ( V_72 ) ) ;
return;
}
fprintf ( V_89 , L_37 , F_49 () ) ;
fclose ( V_89 ) ;
}
}
static void F_50 ()
{
if ( V_88 ) {
F_4 ( L_38 , V_88 ) ;
F_51 ( V_88 ) ;
}
}
static int F_52 ( int V_90 , int V_91 , int V_92 )
{
struct V_53 * V_61 ;
int V_62 [ V_93 ] ;
int V_64 , V_94 ;
int V_23 , V_95 ;
struct V_96 * V_97 ;
struct V_98 V_99 ;
T_6 V_100 ;
if ( F_53 () ) {
F_22 ( L_39 V_101 L_40
V_102 L_41 ) ;
return - 1 ;
}
if ( V_90 ) {
if ( F_54 ( 0 , 0 ) < 0 ) {
F_22 ( L_42 , strerror ( V_72 ) ) ;
F_55 () ;
return - 1 ;
}
F_56 ( 0 ) ;
V_103 = 1 ;
}
F_46 () ;
F_48 () ;
F_7 ( L_43 V_39 L_44 , V_104 ) ;
if ( V_91 && V_92 )
V_94 = V_105 ;
else if ( V_91 )
V_94 = V_106 ;
else
V_94 = V_107 ;
V_61 = F_42 ( NULL , V_94 ) ;
if ( ! V_61 ) {
F_55 () ;
return - 1 ;
}
V_64 = F_36 ( V_61 , V_62 ,
sizeof( V_62 ) / sizeof( * V_62 ) ) ;
F_57 ( V_61 ) ;
if ( V_64 <= 0 ) {
F_22 ( L_45 ) ;
F_55 () ;
return - 1 ;
}
F_4 ( L_46 , V_64 , ( V_64 == 1 ) ? L_47 : L_48 ) ;
V_97 = calloc ( V_64 , sizeof( struct V_96 ) ) ;
for ( V_23 = 0 ; V_23 < V_64 ; V_23 ++ ) {
V_97 [ V_23 ] . V_108 = V_62 [ V_23 ] ;
V_97 [ V_23 ] . V_109 = V_110 ;
}
V_99 . V_111 = V_112 ;
V_99 . V_113 = 0 ;
F_58 ( & V_100 ) ;
F_59 ( & V_100 , V_84 ) ;
F_59 ( & V_100 , V_85 ) ;
V_95 = 0 ;
while ( ! V_95 ) {
int V_114 ;
V_114 = F_60 ( V_97 , V_64 , & V_99 , & V_100 ) ;
if ( V_114 < 0 ) {
F_4 ( L_49 , strerror ( V_72 ) ) ;
V_95 = 1 ;
} else if ( V_114 ) {
for ( V_23 = 0 ; V_23 < V_64 ; V_23 ++ ) {
if ( V_97 [ V_23 ] . V_115 & V_110 ) {
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
free ( V_97 ) ;
F_55 () ;
return 0 ;
}
int main ( int V_116 , char * V_117 [] )
{
static const struct V_118 V_119 [] = {
{ L_53 , V_120 , NULL , '4' } ,
{ L_54 , V_120 , NULL , '6' } ,
{ L_55 , V_120 , NULL , 'D' } ,
{ L_55 , V_120 , NULL , 'D' } ,
{ L_56 , V_120 , NULL , 'd' } ,
{ L_57 , V_121 , NULL , 'P' } ,
{ L_58 , V_122 , NULL , 't' } ,
{ L_59 , V_120 , NULL , 'h' } ,
{ L_60 , V_120 , NULL , 'v' } ,
{ NULL , 0 , NULL , 0 }
} ;
enum {
V_123 = 1 ,
V_124 ,
V_125
} V_126 ;
int V_90 = 0 ;
int V_91 = 0 , V_92 = 0 ;
int V_127 , V_12 = - 1 ;
V_88 = NULL ;
V_128 = 1 ;
V_103 = 0 ;
if ( F_61 () != 0 )
F_22 ( L_61 ) ;
V_126 = V_123 ;
for (; ; ) {
V_127 = F_62 ( V_116 , V_117 , L_62 , V_119 , NULL ) ;
if ( V_127 == - 1 )
break;
switch ( V_127 ) {
case '4' :
V_91 = 1 ;
break;
case '6' :
V_92 = 1 ;
break;
case 'D' :
V_90 = 1 ;
break;
case 'd' :
V_129 = 1 ;
break;
case 'h' :
V_126 = V_124 ;
break;
case 'P' :
V_88 = V_130 ? V_130 : V_131 ;
break;
case 't' :
F_63 ( V_130 ) ;
break;
case 'v' :
V_126 = V_125 ;
break;
case '?' :
F_1 () ;
default:
goto V_132;
}
}
if ( ! V_91 && ! V_92 )
V_91 = V_92 = 1 ;
switch ( V_126 ) {
case V_123 :
V_12 = F_52 ( V_90 , V_91 , V_92 ) ;
F_50 () ;
break;
case V_125 :
printf ( V_39 L_63 , V_104 ) ;
V_12 = 0 ;
break;
case V_124 :
F_1 () ;
V_12 = 0 ;
break;
default:
F_1 () ;
goto V_132;
}
V_132:
return ( V_12 > - 1 ? V_133 : V_134 ) ;
}
