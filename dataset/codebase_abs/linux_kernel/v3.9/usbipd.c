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
static void F_35 ( struct V_53 * V_54 )
{
char V_55 [ V_46 ] ;
char V_56 [ V_48 ] ;
int V_12 ;
V_12 = F_29 ( V_54 -> V_57 , V_54 -> V_58 , V_55 , sizeof( V_55 ) ,
V_56 , sizeof( V_56 ) , V_50 | V_51 ) ;
if ( V_12 )
F_22 ( L_22 , F_30 ( V_12 ) ) ;
F_7 ( L_25 , V_55 , V_56 ) ;
}
static int F_36 ( struct V_53 * V_59 , int V_60 [] )
{
struct V_53 * V_54 ;
int V_31 , V_61 = 0 ;
for ( V_54 = V_59 ; V_54 && V_61 < V_62 ; V_54 = V_54 -> V_63 ) {
V_60 [ V_61 ] = F_37 ( V_54 -> V_64 , V_54 -> V_65 ,
V_54 -> V_66 ) ;
if ( V_60 [ V_61 ] < 0 )
continue;
F_38 ( V_60 [ V_61 ] ) ;
F_8 ( V_60 [ V_61 ] ) ;
if ( V_60 [ V_61 ] >= V_67 ) {
F_32 ( V_60 [ V_61 ] ) ;
V_60 [ V_61 ] = - 1 ;
continue;
}
V_31 = F_39 ( V_60 [ V_61 ] , V_54 -> V_57 , V_54 -> V_58 ) ;
if ( V_31 < 0 ) {
F_32 ( V_60 [ V_61 ] ) ;
V_60 [ V_61 ] = - 1 ;
continue;
}
V_31 = F_40 ( V_60 [ V_61 ] , V_68 ) ;
if ( V_31 < 0 ) {
F_32 ( V_60 [ V_61 ] ) ;
V_60 [ V_61 ] = - 1 ;
continue;
}
F_35 ( V_54 ) ;
V_61 ++ ;
}
if ( V_61 == 0 )
return - 1 ;
F_4 ( L_26 , V_61 , ( V_61 == 1 ) ? L_27 : L_28 ) ;
return V_61 ;
}
static struct V_53 * F_41 ( char * V_45 , int V_64 )
{
struct V_53 V_69 , * V_59 ;
int V_12 ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
V_69 . V_64 = V_64 ;
V_69 . V_65 = V_70 ;
V_69 . V_71 = V_72 ;
V_12 = F_42 ( V_45 , V_73 , & V_69 , & V_59 ) ;
if ( V_12 ) {
F_22 ( L_29 , V_73 ,
F_30 ( V_12 ) ) ;
return NULL ;
}
return V_59 ;
}
static void F_43 ( int V_23 )
{
F_4 ( L_30 , F_44 ( V_23 ) ) ;
}
static void F_45 ( void )
{
struct V_74 V_75 ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_76 = F_43 ;
F_46 ( & V_75 . V_77 ) ;
V_74 ( V_78 , & V_75 , NULL ) ;
V_74 ( V_79 , & V_75 , NULL ) ;
V_75 . V_76 = V_80 ;
V_74 ( V_81 , & V_75 , NULL ) ;
}
static int F_47 ( int V_82 )
{
struct V_53 * V_59 ;
int V_60 [ V_62 ] ;
int V_61 ;
int V_23 , V_83 ;
struct V_84 * V_85 ;
struct V_86 V_87 ;
T_4 V_88 ;
if ( F_48 ( V_89 ) )
F_22 ( L_31 , V_89 ) ;
if ( F_49 () ) {
F_22 ( L_32 V_90 L_33
V_91 L_34 ) ;
return - 1 ;
}
if ( V_82 ) {
if ( F_50 ( 0 , 0 ) < 0 ) {
F_22 ( L_35 , strerror ( V_92 ) ) ;
return - 1 ;
}
F_51 ( 0 ) ;
V_93 = 1 ;
}
F_45 () ;
V_59 = F_41 ( NULL , V_94 ) ;
if ( ! V_59 )
return - 1 ;
F_7 ( L_36 V_39 L_37 , V_95 ) ;
V_61 = F_36 ( V_59 , V_60 ) ;
if ( V_61 <= 0 ) {
F_22 ( L_38 ) ;
return - 1 ;
}
V_85 = calloc ( V_61 , sizeof( struct V_84 ) ) ;
for ( V_23 = 0 ; V_23 < V_61 ; V_23 ++ ) {
V_85 [ V_23 ] . V_96 = V_60 [ V_23 ] ;
V_85 [ V_23 ] . V_97 = V_98 ;
}
V_87 . V_99 = V_100 ;
V_87 . V_101 = 0 ;
F_52 ( & V_88 ) ;
F_53 ( & V_88 , V_78 ) ;
F_53 ( & V_88 , V_79 ) ;
V_83 = 0 ;
while ( ! V_83 ) {
int V_102 ;
V_102 = F_54 ( V_85 , V_61 , & V_87 , & V_88 ) ;
if ( V_102 < 0 ) {
F_4 ( L_39 , strerror ( V_92 ) ) ;
V_83 = 1 ;
} else if ( V_102 ) {
for ( V_23 = 0 ; V_23 < V_61 ; V_23 ++ ) {
if ( V_85 [ V_23 ] . V_103 & V_98 ) {
F_4 ( L_40 ,
V_23 , V_60 [ V_23 ] ) ;
F_33 ( V_60 [ V_23 ] ) ;
}
}
} else
F_4 ( L_41 ) ;
}
F_7 ( L_42 V_39 ) ;
free ( V_85 ) ;
F_55 ( V_59 ) ;
F_56 () ;
F_57 () ;
return 0 ;
}
int main ( int V_104 , char * V_105 [] )
{
static const struct V_106 V_107 [] = {
{ L_43 , V_108 , NULL , 'D' } ,
{ L_44 , V_108 , NULL , 'd' } ,
{ L_45 , V_108 , NULL , 'h' } ,
{ L_46 , V_108 , NULL , 'v' } ,
{ NULL , 0 , NULL , 0 }
} ;
enum {
V_109 = 1 ,
V_110 ,
V_111
} V_112 ;
int V_82 = 0 ;
int V_113 , V_12 = - 1 ;
V_114 = 1 ;
V_93 = 0 ;
if ( F_58 () != 0 )
F_22 ( L_47 ) ;
V_112 = V_109 ;
for (; ; ) {
V_113 = F_59 ( V_104 , V_105 , L_48 , V_107 , NULL ) ;
if ( V_113 == - 1 )
break;
switch ( V_113 ) {
case 'D' :
V_82 = 1 ;
break;
case 'd' :
V_115 = 1 ;
break;
case 'h' :
V_112 = V_110 ;
break;
case 'v' :
V_112 = V_111 ;
break;
case '?' :
F_1 () ;
default:
goto V_116;
}
}
switch ( V_112 ) {
case V_109 :
V_12 = F_47 ( V_82 ) ;
break;
case V_111 :
printf ( V_39 L_49 , V_95 ) ;
V_12 = 0 ;
break;
case V_110 :
F_1 () ;
V_12 = 0 ;
break;
default:
F_1 () ;
goto V_116;
}
V_116:
return ( V_12 > - 1 ? V_117 : V_118 ) ;
}
