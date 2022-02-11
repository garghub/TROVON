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
if ( ! V_19 )
return - V_20 ;
F_8 ( V_19 ) ;
}
F_9 () ;
#endif
F_4 (KERN_INFO PREFIX L_3 ,
acpi_state) ;
F_10 ( V_1 ) ;
F_11 ( V_1 ) ;
return 0 ;
}
T_1 F_12 ( void )
{
return V_21 ;
}
void T_3 F_13 ( void )
{
V_22 = true ;
}
void T_3 F_14 ( void )
{
V_23 = true ;
}
void T_3 F_15 ( void )
{
V_24 = true ;
}
static int T_3 F_16 ( const struct V_25 * V_26 )
{
F_15 () ;
return 0 ;
}
static int T_3 F_17 ( const struct V_25 * V_26 )
{
F_13 () ;
return 0 ;
}
static void F_18 ( void )
{
F_19 ( V_27 ) ;
}
static int F_20 ( void )
{
F_21 () ;
F_22 () ;
F_23 () ;
return 0 ;
}
static int F_24 ( void )
{
F_20 () ;
return F_25 () ;
}
static int F_26 ( void )
{
int error = F_6 ( V_21 ) ;
if ( error )
V_21 = V_28 ;
return error ;
}
static int F_27 ( void )
{
int error = F_26 () ;
if ( ! error )
error = F_24 () ;
return error ;
}
static int F_28 ( struct V_29 * V_30 , void * V_31 )
{
struct V_32 * V_29 = F_29 ( V_30 ) ;
const char * V_33 = F_30 ( V_29 ) ;
return ! strcmp ( V_33 , V_34 ) ;
}
static void F_31 ( void )
{
struct V_29 * V_35 ;
T_1 V_1 = V_21 ;
F_32 () ;
F_33 () ;
if ( V_1 == V_28 )
return;
F_4 (KERN_INFO PREFIX L_4 ,
acpi_state) ;
F_34 ( V_1 ) ;
F_35 ( V_1 ) ;
F_8 ( ( V_36 ) 0 ) ;
V_21 = V_28 ;
if ( ! V_37 )
return;
V_37 = false ;
V_35 = F_36 ( & V_38 , NULL , NULL ,
F_28 ) ;
if ( V_35 ) {
F_37 ( V_35 , 0 ) ;
F_38 ( V_35 ) ;
}
}
static void F_39 ( void )
{
V_21 = V_28 ;
F_1 ( V_21 ) ;
}
static inline void F_18 ( void ) {}
static int F_40 ( T_4 V_39 )
{
T_1 V_1 = V_40 [ V_39 ] ;
int error = 0 ;
error = ( V_22 || V_23 ) ? 0 : F_41 () ;
if ( error )
return error ;
if ( V_41 [ V_1 ] ) {
V_21 = V_1 ;
F_1 ( V_21 ) ;
} else {
F_4 ( V_42 L_5 ,
V_39 ) ;
error = - V_43 ;
}
return error ;
}
static int F_42 ( T_4 V_39 )
{
T_2 V_7 = V_8 ;
T_1 V_1 = V_21 ;
int error ;
F_9 () ;
switch ( V_1 ) {
case V_44 :
F_43 () ;
V_7 = F_44 ( V_1 ) ;
break;
case V_18 :
error = F_45 () ;
if ( error )
return error ;
F_46 ( V_45 L_6 ) ;
break;
}
F_47 ( V_46 , 1 ) ;
F_48 ( V_1 ) ;
if ( F_49 ( V_7 ) && ( V_1 == V_18 ) ) {
T_5 V_47 ;
F_50 ( V_48 , & V_47 ) ;
if ( V_47 & V_49 ) {
F_51 ( V_48 ) ;
V_37 = true ;
}
}
F_21 () ;
F_52 () ;
F_53 () ;
return F_49 ( V_7 ) ? 0 : - V_20 ;
}
static int F_54 ( T_4 V_39 )
{
T_1 V_1 ;
switch ( V_39 ) {
case V_50 :
case V_51 :
case V_52 :
V_1 = V_40 [ V_39 ] ;
return V_41 [ V_1 ] ;
default:
return 0 ;
}
}
static int F_55 ( T_4 V_39 )
{
int error = F_40 ( V_39 ) ;
if ( ! error )
error = F_26 () ;
return error ;
}
void T_3 F_56 ( void )
{
V_53 = true ;
}
static int F_57 ( void )
{
int error ;
error = V_22 ? 0 : F_41 () ;
if ( ! error ) {
V_21 = V_54 ;
F_1 ( V_21 ) ;
}
return error ;
}
static int F_58 ( void )
{
T_2 V_7 = V_8 ;
F_9 () ;
V_7 = F_44 ( V_54 ) ;
F_48 ( V_54 ) ;
return F_49 ( V_7 ) ? 0 : - V_20 ;
}
static void F_59 ( void )
{
F_60 () ;
F_48 ( V_54 ) ;
if ( V_55 && V_56 != V_55 -> V_57 ) {
F_4 ( V_58 L_7
L_8 ) ;
F_61 ( L_9 ) ;
}
F_53 () ;
F_52 () ;
}
static void F_62 ( void )
{
F_32 () ;
F_63 () ;
}
static int F_64 ( void )
{
int error ;
F_1 ( V_54 ) ;
error = F_6 ( V_54 ) ;
if ( ! error ) {
if ( ! V_22 )
error = F_41 () ;
if ( ! error )
V_21 = V_54 ;
}
return error ;
}
int F_65 ( T_1 V_1 )
{
T_4 V_59 [] = {
[ 1 ] = V_51 ,
[ 3 ] = V_52 ,
[ 5 ] = V_60
} ;
if ( V_1 < 6 && V_59 [ V_1 ] )
return F_66 ( V_59 [ V_1 ] ) ;
if ( V_1 == 4 )
return F_67 () ;
return - V_61 ;
}
static void F_68 ( void )
{
F_6 ( V_16 ) ;
F_21 () ;
}
static void F_69 ( void )
{
F_4 ( V_62 L_10 , V_63 ) ;
F_70 () ;
F_44 ( V_16 ) ;
}
int T_3 F_71 ( void )
{
T_2 V_7 ;
T_6 V_64 , V_65 ;
#ifdef F_72
int V_66 = 0 ;
#endif
if ( V_67 )
return 0 ;
F_18 () ;
V_41 [ V_28 ] = 1 ;
F_4 (KERN_INFO PREFIX L_11 ) ;
#ifdef F_72
for ( V_66 = V_44 ; V_66 < V_54 ; V_66 ++ ) {
V_7 = F_73 ( V_66 , & V_64 , & V_65 ) ;
if ( F_49 ( V_7 ) ) {
V_41 [ V_66 ] = 1 ;
F_4 ( V_68 L_12 , V_66 ) ;
}
}
F_74 ( V_24 ?
& V_69 : & V_70 ) ;
#endif
#ifdef F_75
V_7 = F_73 ( V_54 , & V_64 , & V_65 ) ;
if ( F_49 ( V_7 ) ) {
F_76 ( V_24 ?
& V_71 : & V_72 ) ;
V_41 [ V_54 ] = 1 ;
F_4 ( V_68 L_13 ) ;
if ( ! V_53 ) {
F_77 ( V_73 , 1 ,
(struct V_74 * * ) & V_55 ) ;
if ( V_55 )
V_56 =
V_55 -> V_57 ;
}
}
#endif
V_7 = F_73 ( V_16 , & V_64 , & V_65 ) ;
if ( F_49 ( V_7 ) ) {
V_41 [ V_16 ] = 1 ;
F_4 ( V_68 L_14 ) ;
V_75 = F_68 ;
V_76 = F_69 ;
}
F_4 ( V_68 L_15 ) ;
F_78 ( & V_77 ) ;
return 0 ;
}
