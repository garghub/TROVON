static void F_1 ( T_1 V_1 )
{
union V_2 V_3 = { V_4 } ;
struct V_5 V_6 = { 1 , & V_3 } ;
T_2 V_7 = V_8 ;
V_3 . integer . V_9 = V_1 ;
V_7 = F_2 ( NULL , L_1 , & V_6 , NULL ) ;
if ( F_3 ( V_7 ) && V_7 != V_10 ) {
F_4 ( V_11 L_2 ) ;
}
}
static int F_5 ( struct V_12 * V_13 ,
unsigned long V_14 , void * V_15 )
{
F_1 ( V_16 ) ;
return V_17 ;
}
static int F_6 ( T_1 V_1 )
{
#ifdef F_7
if ( V_1 == V_18 ) {
if ( ! V_19 ) {
return - V_20 ;
}
F_8 (
( V_21 ) V_19 ) ;
}
F_9 () ;
#endif
F_4 (KERN_INFO PREFIX L_3 ,
acpi_state) ;
F_10 ( V_1 ) ;
F_11 ( V_1 ) ;
return 0 ;
}
void T_3 F_12 ( void )
{
V_22 = true ;
}
void T_3 F_13 ( void )
{
V_23 = true ;
}
static int F_14 ( void )
{
F_15 () ;
F_16 ( NULL ) ;
F_17 () ;
return 0 ;
}
static int F_18 ( void )
{
F_14 () ;
return F_19 () ;
}
static int F_20 ( void )
{
int error = F_6 ( V_24 ) ;
if ( error )
V_24 = V_25 ;
return error ;
}
static int F_21 ( void )
{
int error = F_20 () ;
if ( ! error )
error = F_18 () ;
return error ;
}
static void F_22 ( void )
{
T_1 V_1 = V_24 ;
F_23 () ;
F_24 () ;
if ( V_1 == V_25 )
return;
F_4 (KERN_INFO PREFIX L_4 ,
acpi_state) ;
F_25 ( V_1 ) ;
F_26 ( V_1 ) ;
F_8 ( ( V_21 ) 0 ) ;
V_24 = V_25 ;
}
static void F_27 ( void )
{
V_24 = V_25 ;
F_1 ( V_24 ) ;
}
static int F_28 ( T_4 V_26 )
{
T_1 V_1 = V_27 [ V_26 ] ;
int error = 0 ;
error = V_22 ? 0 : F_29 () ;
if ( error )
return error ;
if ( V_28 [ V_1 ] ) {
V_24 = V_1 ;
F_1 ( V_24 ) ;
} else {
F_4 ( V_29 L_5 ,
V_26 ) ;
error = - V_30 ;
}
return error ;
}
static int F_30 ( T_4 V_26 )
{
T_2 V_7 = V_8 ;
T_1 V_1 = V_24 ;
int error ;
F_9 () ;
switch ( V_1 ) {
case V_31 :
F_31 () ;
V_7 = F_32 ( V_1 ) ;
break;
case V_18 :
error = F_33 () ;
if ( error )
return error ;
F_34 ( V_32 L_6 ) ;
break;
}
F_35 ( V_33 , 1 ) ;
F_36 ( V_1 ) ;
if ( F_37 ( V_7 ) && ( V_1 == V_18 ) )
F_38 ( V_34 ) ;
F_15 () ;
F_39 () ;
F_40 () ;
return F_37 ( V_7 ) ? 0 : - V_20 ;
}
static int F_41 ( T_4 V_26 )
{
T_1 V_1 ;
switch ( V_26 ) {
case V_35 :
case V_36 :
case V_37 :
V_1 = V_27 [ V_26 ] ;
return V_28 [ V_1 ] ;
default:
return 0 ;
}
}
static int F_42 ( T_4 V_26 )
{
int error = F_28 ( V_26 ) ;
if ( ! error )
error = F_20 () ;
return error ;
}
static int T_3 F_43 ( const struct V_38 * V_39 )
{
V_23 = true ;
return 0 ;
}
static int T_3 F_44 ( const struct V_38 * V_39 )
{
F_12 () ;
return 0 ;
}
void T_3 F_45 ( void )
{
V_40 = true ;
}
static int F_46 ( void )
{
int error ;
error = V_22 ? 0 : F_29 () ;
if ( ! error ) {
V_24 = V_41 ;
F_1 ( V_24 ) ;
}
return error ;
}
static int F_47 ( void )
{
T_2 V_7 = V_8 ;
F_9 () ;
V_7 = F_32 ( V_41 ) ;
F_36 ( V_41 ) ;
return F_37 ( V_7 ) ? 0 : - V_20 ;
}
static void F_48 ( void )
{
F_49 () ;
F_36 ( V_41 ) ;
if ( V_42 && V_43 != V_42 -> V_44 ) {
F_4 ( V_45 L_7
L_8 ) ;
F_50 ( L_9 ) ;
}
F_40 () ;
F_39 () ;
}
static void F_51 ( void )
{
F_23 () ;
F_52 () ;
}
static int F_53 ( void )
{
int error ;
F_1 ( V_41 ) ;
error = F_6 ( V_41 ) ;
if ( ! error ) {
if ( ! V_22 )
error = F_29 () ;
if ( ! error )
V_24 = V_41 ;
}
return error ;
}
int F_54 ( T_1 V_1 )
{
T_4 V_46 [] = {
[ 1 ] = V_36 ,
[ 3 ] = V_37 ,
[ 5 ] = V_47
} ;
if ( V_1 < 6 && V_46 [ V_1 ] )
return F_55 ( V_46 [ V_1 ] ) ;
if ( V_1 == 4 )
return F_56 () ;
return - V_48 ;
}
int F_57 ( struct V_49 * V_50 , int * V_51 )
{
T_5 V_52 = F_58 ( V_50 ) ;
struct V_53 * V_54 ;
char V_55 [] = L_10 ;
unsigned long long V_56 , V_57 ;
if ( ! V_52 || F_3 ( F_59 ( V_52 , & V_54 ) ) ) {
F_4 ( V_58 L_11 ) ;
return - V_59 ;
}
V_55 [ 2 ] = '0' + V_24 ;
V_56 = V_60 ;
V_57 = V_61 ;
if ( V_24 > V_25 )
F_60 ( V_52 , V_55 , NULL , & V_56 ) ;
if ( V_24 == V_25 ||
( F_61 ( V_50 ) &&
V_54 -> V_62 . V_63 <= V_24 ) ) {
T_2 V_7 ;
V_55 [ 3 ] = 'W' ;
V_7 = F_60 ( V_52 , V_55 , NULL ,
& V_57 ) ;
if ( F_3 ( V_7 ) ) {
if ( V_24 != V_25 ||
V_7 != V_10 )
V_57 = V_56 ;
} else if ( V_57 < V_56 ) {
F_4 ( V_64 L_12 ,
V_55 ) ;
V_56 = V_57 ;
}
}
if ( V_51 )
* V_51 = V_56 ;
return V_57 ;
}
int F_62 ( struct V_49 * V_50 , bool V_65 )
{
T_5 V_52 ;
struct V_53 * V_54 ;
int error ;
if ( ! F_63 ( V_50 ) )
return - V_48 ;
V_52 = F_58 ( V_50 ) ;
if ( ! V_52 || F_3 ( F_59 ( V_52 , & V_54 ) ) ) {
F_64 ( V_50 , L_13 , V_66 ) ;
return - V_59 ;
}
error = V_65 ?
F_65 ( V_54 , V_24 ) :
F_66 ( V_54 ) ;
if ( ! error )
F_67 ( V_50 , L_14 ,
V_65 ? L_15 : L_16 ) ;
return error ;
}
static void F_68 ( void )
{
F_6 ( V_16 ) ;
F_15 () ;
}
static void F_69 ( void )
{
F_4 ( V_58 L_17 , V_66 ) ;
F_70 () ;
F_32 ( V_16 ) ;
}
static void T_3 F_71 ( void )
{
T_5 V_67 ;
if ( F_37 ( F_72 ( V_68 , V_69 , & V_67 ) ) )
{
F_4 (KERN_NOTICE PREFIX L_18 ) ;
F_4 (KERN_NOTICE PREFIX L_19
L_20 ) ;
}
if ( F_37 ( F_72 ( V_68 , V_70 , & V_67 ) ) )
{
F_4 (KERN_NOTICE PREFIX L_21 ) ;
F_4 (KERN_NOTICE PREFIX L_22
L_20 ) ;
}
}
int T_3 F_73 ( void )
{
T_2 V_7 ;
T_6 V_71 , V_72 ;
#ifdef F_74
int V_73 = 0 ;
F_75 ( V_74 ) ;
#endif
if ( V_75 )
return 0 ;
V_28 [ V_25 ] = 1 ;
F_4 (KERN_INFO PREFIX L_23 ) ;
#ifdef F_74
for ( V_73 = V_31 ; V_73 < V_41 ; V_73 ++ ) {
V_7 = F_76 ( V_73 , & V_71 , & V_72 ) ;
if ( F_37 ( V_7 ) ) {
V_28 [ V_73 ] = 1 ;
F_4 ( L_24 , V_73 ) ;
}
}
F_77 ( V_23 ?
& V_76 : & V_77 ) ;
#endif
#ifdef F_78
V_7 = F_76 ( V_41 , & V_71 , & V_72 ) ;
if ( F_37 ( V_7 ) ) {
F_79 ( V_23 ?
& V_78 : & V_79 ) ;
V_28 [ V_41 ] = 1 ;
F_4 ( L_25 ) ;
if ( ! V_40 ) {
F_80 ( V_80 , 1 ,
(struct V_81 * * ) & V_42 ) ;
if ( V_42 )
V_43 =
V_42 -> V_44 ;
}
}
#endif
V_7 = F_76 ( V_16 , & V_71 , & V_72 ) ;
if ( F_37 ( V_7 ) ) {
V_28 [ V_16 ] = 1 ;
F_4 ( L_26 ) ;
V_82 = F_68 ;
V_83 = F_69 ;
}
F_4 ( L_27 ) ;
F_81 ( & V_84 ) ;
F_71 () ;
return 0 ;
}
