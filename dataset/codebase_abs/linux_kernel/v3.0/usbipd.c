static int F_1 ( int V_1 )
{
int V_2 ;
struct V_3 * V_4 ;
struct V_5 V_6 ;
V_6 . V_7 = 0 ;
F_2 (stub_driver->edev_list, edev, struct usbip_exported_device) {
V_6 . V_7 += 1 ;
}
F_3 ( L_1 , V_6 . V_7 ) ;
V_2 = F_4 ( V_1 , V_8 , V_9 ) ;
if ( V_2 < 0 ) {
F_5 ( L_2 ) ;
return V_2 ;
}
F_6 ( 1 , & V_6 ) ;
V_2 = F_7 ( V_1 , ( void * ) & V_6 , sizeof( V_6 ) ) ;
if ( V_2 < 0 ) {
F_5 ( L_3 ) ;
return V_2 ;
}
F_2 (stub_driver->edev_list, edev, struct usbip_exported_device) {
struct V_10 V_11 ;
F_8 ( & V_4 -> V_12 ) ;
memcpy ( & V_11 , & V_4 -> V_12 , sizeof( V_11 ) ) ;
F_9 ( 1 , & V_11 ) ;
V_2 = F_7 ( V_1 , ( void * ) & V_11 , sizeof( V_11 ) ) ;
if ( V_2 < 0 ) {
F_5 ( L_4 ) ;
return V_2 ;
}
for ( int V_13 = 0 ; V_13 < V_4 -> V_12 . V_14 ; V_13 ++ ) {
struct V_15 V_16 ;
F_10 ( & V_4 -> V_17 [ V_13 ] ) ;
memcpy ( & V_16 , & V_4 -> V_17 [ V_13 ] , sizeof( V_16 ) ) ;
F_11 ( 1 , & V_16 ) ;
V_2 = F_7 ( V_1 , ( void * ) & V_16 , sizeof( V_16 ) ) ;
if ( V_2 < 0 ) {
F_5 ( L_5 ) ;
return V_2 ;
}
}
}
return 0 ;
}
static int F_12 ( int V_1 )
{
int V_2 ;
struct V_18 V_19 ;
F_13 ( & V_19 , sizeof( V_19 ) ) ;
V_2 = F_14 ( V_1 , ( void * ) & V_19 , sizeof( V_19 ) ) ;
if ( V_2 < 0 ) {
F_5 ( L_6 ) ;
return - 1 ;
}
V_2 = F_1 ( V_1 ) ;
if ( V_2 < 0 ) {
F_5 ( L_7 ) ;
return - 1 ;
}
return 0 ;
}
static int F_15 ( int V_1 )
{
int V_2 ;
struct V_20 V_19 ;
struct V_21 V_6 ;
struct V_3 * V_4 ;
int V_22 = 0 ;
int error = 0 ;
F_13 ( & V_19 , sizeof( V_19 ) ) ;
F_13 ( & V_6 , sizeof( V_6 ) ) ;
V_2 = F_14 ( V_1 , ( void * ) & V_19 , sizeof( V_19 ) ) ;
if ( V_2 < 0 ) {
F_5 ( L_8 ) ;
return - 1 ;
}
F_16 ( 0 , & V_19 ) ;
F_2 (stub_driver->edev_list, edev, struct usbip_exported_device) {
if ( ! strncmp ( V_19 . V_23 , V_4 -> V_12 . V_23 , V_24 ) ) {
F_3 ( L_9 , V_19 . V_23 ) ;
V_22 = 1 ;
break;
}
}
if ( V_22 ) {
F_17 ( V_1 ) ;
V_2 = F_18 ( V_4 , V_1 ) ;
if ( V_2 < 0 )
error = 1 ;
} else {
F_19 ( L_10 , V_19 . V_23 ) ;
error = 1 ;
}
V_2 = F_4 ( V_1 , V_25 , ( ! error ? V_9 : V_26 ) ) ;
if ( V_2 < 0 ) {
F_5 ( L_11 ) ;
return - 1 ;
}
if ( ! error ) {
struct V_10 V_11 ;
memcpy ( & V_11 , & V_4 -> V_12 , sizeof( V_11 ) ) ;
F_9 ( 1 , & V_11 ) ;
V_2 = F_7 ( V_1 , ( void * ) & V_11 , sizeof( V_11 ) ) ;
if ( V_2 < 0 ) {
F_5 ( L_12 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_20 ( int V_1 )
{
int V_2 ;
T_1 V_27 = V_28 ;
V_2 = F_21 ( V_1 , & V_27 ) ;
if ( V_2 < 0 ) {
F_5 ( L_13 , V_2 ) ;
return V_2 ;
}
V_2 = F_22 () ;
if ( V_2 < 0 )
return - 1 ;
switch( V_27 ) {
case V_29 :
V_2 = F_12 ( V_1 ) ;
break;
case V_30 :
V_2 = F_15 ( V_1 ) ;
break;
case V_31 :
case V_32 :
default:
F_5 ( L_14 , V_27 ) ;
V_2 = - 1 ;
}
return V_2 ;
}
static void F_23 ( struct V_33 * V_34 )
{
int V_2 ;
char V_35 [ V_36 ] ;
char V_37 [ V_38 ] ;
V_2 = F_24 ( V_34 -> V_39 , V_34 -> V_40 , V_35 , sizeof( V_35 ) ,
V_37 , sizeof( V_37 ) , V_41 | V_42 ) ;
if ( V_2 )
F_5 ( L_15 , F_25 ( V_2 ) ) ;
F_19 ( L_16 , V_35 , V_37 ) ;
}
static struct V_33 * F_26 ( char * V_43 , int V_44 )
{
int V_2 ;
struct V_33 V_45 , * V_46 ;
F_13 ( & V_45 , sizeof( V_45 ) ) ;
V_45 . V_44 = V_44 ;
V_45 . V_47 = V_48 ;
V_45 . V_49 = V_50 ;
V_2 = F_27 ( V_43 , V_51 , & V_45 , & V_46 ) ;
if ( V_2 ) {
F_5 ( L_17 , V_51 , F_25 ( V_2 ) ) ;
return NULL ;
}
return V_46 ;
}
static int F_28 ( struct V_33 * V_46 , int V_52 [] )
{
struct V_33 * V_34 ;
int V_53 = 0 ;
for ( V_34 = V_46 ; V_34 && V_53 < V_54 ; V_34 = V_34 -> V_55 ) {
int V_2 ;
V_52 [ V_53 ] = F_29 ( V_34 -> V_44 , V_34 -> V_47 , V_34 -> V_56 ) ;
if ( V_52 [ V_53 ] < 0 )
continue;
F_30 ( V_52 [ V_53 ] ) ;
F_17 ( V_52 [ V_53 ] ) ;
if ( V_52 [ V_53 ] >= V_57 ) {
F_31 ( V_52 [ V_53 ] ) ;
V_52 [ V_53 ] = - 1 ;
continue;
}
V_2 = F_32 ( V_52 [ V_53 ] , V_34 -> V_39 , V_34 -> V_40 ) ;
if ( V_2 < 0 ) {
F_31 ( V_52 [ V_53 ] ) ;
V_52 [ V_53 ] = - 1 ;
continue;
}
V_2 = F_33 ( V_52 [ V_53 ] , V_58 ) ;
if ( V_2 < 0 ) {
F_31 ( V_52 [ V_53 ] ) ;
V_52 [ V_53 ] = - 1 ;
continue;
}
F_23 ( V_34 ) ;
V_53 ++ ;
}
if ( V_53 == 0 ) {
F_5 ( L_18 ) ;
return - 1 ;
}
F_3 ( L_19 , V_53 , ( V_53 == 1 ) ? L_20 : L_21 ) ;
return V_53 ;
}
static int F_34 ( int V_59 )
{
int V_2 ;
struct V_60 V_61 ;
F_35 ( & V_61 , V_62 , L_22 , V_63 , V_59 , 0 ) ;
F_36 ( & V_61 ) ;
V_2 = F_37 ( & V_61 ) ;
if ( ! V_2 )
return - 1 ;
return 0 ;
}
static int F_38 ( int V_52 )
{
int V_59 ;
struct V_64 V_65 ;
T_2 V_66 = sizeof( V_65 ) ;
char V_43 [ V_36 ] , V_67 [ V_38 ] ;
int V_2 ;
F_13 ( & V_65 , sizeof( V_65 ) ) ;
V_59 = F_39 ( V_52 , (struct V_68 * ) & V_65 , & V_66 ) ;
if ( V_59 < 0 ) {
F_5 ( L_23 ) ;
return - 1 ;
}
V_2 = F_24 ( (struct V_68 * ) & V_65 , V_66 ,
V_43 , sizeof( V_43 ) , V_67 , sizeof( V_67 ) ,
( V_41 | V_42 ) ) ;
if ( V_2 )
F_5 ( L_15 , F_25 ( V_2 ) ) ;
#ifdef F_40
V_2 = F_34 ( V_59 ) ;
if ( V_2 < 0 ) {
F_19 ( L_24 , V_43 ) ;
F_31 ( V_59 ) ;
return - 1 ;
}
#endif
F_19 ( L_25 , V_43 , V_67 ) ;
return V_59 ;
}
static void F_41 ( int V_13 )
{
F_3 ( L_26 , V_13 ) ;
if ( V_69 )
F_42 ( V_69 ) ;
}
static void F_43 ( void )
{
struct V_70 V_71 ;
F_13 ( & V_71 , sizeof( V_71 ) ) ;
V_71 . V_72 = F_41 ;
F_44 ( & V_71 . V_73 ) ;
V_70 ( V_74 , & V_71 , NULL ) ;
V_70 ( V_75 , & V_71 , NULL ) ;
}
static void F_45 ( T_3 V_76 )
{
int V_2 ;
int V_52 [ V_54 ] ;
struct V_33 * V_46 ;
int V_53 ;
V_2 = F_46 ( V_77 ) ;
if ( V_2 )
F_5 ( L_27 ) ;
V_2 = F_47 () ;
if ( V_2 < 0 )
F_48 ( L_28 ) ;
if ( V_76 ) {
if ( F_49 ( 0 , 0 ) < 0 )
F_48 ( L_29 , F_50 ( V_78 ) ) ;
V_79 = 1 ;
}
F_43 () ;
V_46 = F_26 ( NULL , V_80 ) ;
if ( ! V_46 )
return;
V_53 = F_28 ( V_46 , V_52 ) ;
if ( V_53 <= 0 )
F_48 ( L_18 ) ;
for ( int V_13 = 0 ; V_13 < V_53 ; V_13 ++ ) {
T_4 * V_81 ;
V_81 = F_51 ( V_52 [ V_13 ] ) ;
F_52 ( V_81 , ( V_82 | V_83 | V_84 | V_85 ) ,
V_86 , NULL ) ;
}
F_19 ( L_30 , V_87 ) ;
V_69 = F_53 ( FALSE , FALSE ) ;
F_54 ( V_69 ) ;
F_19 ( L_31 ) ;
F_55 ( V_46 ) ;
F_56 () ;
F_57 () ;
return;
}
static void F_58 ( void )
{
printf ( L_32 , V_88 ) ;
}
int main ( int V_89 , char * V_90 [] )
{
T_3 V_76 = FALSE ;
enum {
V_91 = 1 ,
V_92 ,
V_93
} V_94 = V_91 ;
V_95 = 1 ;
V_79 = 0 ;
if ( F_59 () != 0 )
F_60 ( L_33 ) ;
for (; ; ) {
int V_96 ;
int V_97 = 0 ;
V_96 = F_61 ( V_89 , V_90 , L_34 , V_98 , & V_97 ) ;
if ( V_96 == - 1 )
break;
switch ( V_96 ) {
case 'd' :
V_99 = 1 ;
continue;
case 'v' :
V_94 = V_93 ;
break;
case 'h' :
V_94 = V_92 ;
break;
case 'D' :
V_76 = TRUE ;
break;
case '?' :
F_58 () ;
exit ( V_100 ) ;
default:
F_5 ( L_35 ) ;
}
}
switch ( V_94 ) {
case V_91 :
F_45 ( V_76 ) ;
break;
case V_93 :
printf ( L_36 , V_87 ) ;
break;
case V_92 :
F_58 () ;
break;
default:
F_19 ( L_37 ) ;
F_58 () ;
}
return 0 ;
}
