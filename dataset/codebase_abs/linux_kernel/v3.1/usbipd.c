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
T_3 F_33 ( T_4 * V_52 , T_5 V_53 ,
T_6 V_54 )
{
int V_41 ;
int V_19 ;
( void ) V_54 ;
if ( V_53 & ( V_55 | V_56 | V_57 ) ) {
F_22 ( L_25 ) ;
F_34 () ;
}
if ( V_53 & V_58 ) {
V_41 = F_35 ( V_52 ) ;
V_19 = F_27 ( V_41 ) ;
if ( V_19 < 0 )
return TRUE ;
F_19 ( V_19 ) ;
F_32 ( V_19 ) ;
}
return TRUE ;
}
static void F_36 ( struct V_59 * V_60 )
{
char V_61 [ V_46 ] ;
char V_62 [ V_48 ] ;
int V_12 ;
V_12 = F_29 ( V_60 -> V_63 , V_60 -> V_64 , V_61 , sizeof( V_61 ) ,
V_62 , sizeof( V_62 ) , V_50 | V_51 ) ;
if ( V_12 )
F_22 ( L_22 , F_30 ( V_12 ) ) ;
F_7 ( L_26 , V_61 , V_62 ) ;
}
static int F_37 ( struct V_59 * V_65 , int V_66 [] )
{
struct V_59 * V_60 ;
int V_31 , V_67 = 0 ;
for ( V_60 = V_65 ; V_60 && V_67 < V_68 ; V_60 = V_60 -> V_69 ) {
V_66 [ V_67 ] = F_38 ( V_60 -> V_70 , V_60 -> V_71 ,
V_60 -> V_72 ) ;
if ( V_66 [ V_67 ] < 0 )
continue;
F_39 ( V_66 [ V_67 ] ) ;
F_8 ( V_66 [ V_67 ] ) ;
if ( V_66 [ V_67 ] >= V_73 ) {
F_32 ( V_66 [ V_67 ] ) ;
V_66 [ V_67 ] = - 1 ;
continue;
}
V_31 = F_40 ( V_66 [ V_67 ] , V_60 -> V_63 , V_60 -> V_64 ) ;
if ( V_31 < 0 ) {
F_32 ( V_66 [ V_67 ] ) ;
V_66 [ V_67 ] = - 1 ;
continue;
}
V_31 = F_41 ( V_66 [ V_67 ] , V_74 ) ;
if ( V_31 < 0 ) {
F_32 ( V_66 [ V_67 ] ) ;
V_66 [ V_67 ] = - 1 ;
continue;
}
F_36 ( V_60 ) ;
V_67 ++ ;
}
if ( V_67 == 0 )
return - 1 ;
F_4 ( L_27 , V_67 , ( V_67 == 1 ) ? L_28 : L_29 ) ;
return V_67 ;
}
static struct V_59 * F_42 ( char * V_45 , int V_70 )
{
struct V_59 V_75 , * V_65 ;
int V_12 ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_70 = V_70 ;
V_75 . V_71 = V_76 ;
V_75 . V_77 = V_78 ;
V_12 = F_43 ( V_45 , V_79 , & V_75 , & V_65 ) ;
if ( V_12 ) {
F_22 ( L_30 , V_79 ,
F_30 ( V_12 ) ) ;
return NULL ;
}
return V_65 ;
}
static void F_44 ( int V_23 )
{
F_4 ( L_31 , V_23 ) ;
if ( V_80 )
F_45 ( V_80 ) ;
}
static void F_46 ( void )
{
struct V_81 V_82 ;
memset ( & V_82 , 0 , sizeof( V_82 ) ) ;
V_82 . V_83 = F_44 ;
F_47 ( & V_82 . V_84 ) ;
V_81 ( V_85 , & V_82 , NULL ) ;
V_81 ( V_86 , & V_82 , NULL ) ;
}
static int F_48 ( T_3 V_87 )
{
struct V_59 * V_65 ;
int V_66 [ V_68 ] ;
int V_67 ;
int V_23 ;
if ( F_49 ( V_88 ) )
F_22 ( L_32 , V_88 ) ;
if ( F_50 () ) {
F_22 ( L_33 V_89 L_34
V_90 L_35 ) ;
return - 1 ;
}
if ( V_87 ) {
if ( F_51 ( 0 , 0 ) < 0 ) {
F_22 ( L_36 , strerror ( V_91 ) ) ;
return - 1 ;
}
V_92 = 1 ;
}
F_46 () ;
V_65 = F_42 ( NULL , V_93 ) ;
if ( ! V_65 )
return - 1 ;
F_7 ( L_37 V_39 L_38 , V_94 ) ;
V_67 = F_37 ( V_65 , V_66 ) ;
if ( V_67 <= 0 ) {
F_22 ( L_39 ) ;
return - 1 ;
}
for ( V_23 = 0 ; V_23 < V_67 ; V_23 ++ ) {
T_4 * V_52 ;
V_52 = F_52 ( V_66 [ V_23 ] ) ;
F_53 ( V_52 , ( V_58 | V_55 | V_56 | V_57 ) ,
F_33 , NULL ) ;
}
V_80 = F_54 ( FALSE , FALSE ) ;
F_55 ( V_80 ) ;
F_7 ( L_40 V_39 ) ;
F_56 ( V_65 ) ;
F_57 () ;
F_58 () ;
return 0 ;
}
int main ( int V_95 , char * V_96 [] )
{
static const struct V_97 V_98 [] = {
{ L_41 , V_99 , NULL , 'D' } ,
{ L_42 , V_99 , NULL , 'd' } ,
{ L_43 , V_99 , NULL , 'h' } ,
{ L_44 , V_99 , NULL , 'v' } ,
{ NULL , 0 , NULL , 0 }
} ;
enum {
V_100 = 1 ,
V_101 ,
V_102
} V_103 ;
T_3 V_87 = FALSE ;
int V_104 , V_12 = - 1 ;
V_105 = 1 ;
V_92 = 0 ;
if ( F_59 () != 0 )
F_22 ( L_45 ) ;
V_103 = V_100 ;
for (; ; ) {
V_104 = F_60 ( V_95 , V_96 , L_46 , V_98 , NULL ) ;
if ( V_104 == - 1 )
break;
switch ( V_104 ) {
case 'D' :
V_87 = TRUE ;
break;
case 'd' :
V_106 = 1 ;
break;
case 'h' :
V_103 = V_101 ;
break;
case 'v' :
V_103 = V_102 ;
break;
case '?' :
F_1 () ;
default:
goto V_107;
}
}
switch ( V_103 ) {
case V_100 :
V_12 = F_48 ( V_87 ) ;
break;
case V_102 :
printf ( V_39 L_47 , V_94 ) ;
V_12 = 0 ;
break;
case V_101 :
F_1 () ;
V_12 = 0 ;
break;
default:
F_1 () ;
goto V_107;
}
V_107:
return ( V_12 > - 1 ? V_108 : V_109 ) ;
}
