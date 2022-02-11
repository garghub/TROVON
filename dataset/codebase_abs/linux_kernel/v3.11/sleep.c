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
F_36 () ;
if ( ! V_37 )
return;
V_37 = false ;
V_35 = F_37 ( & V_38 , NULL , NULL ,
F_28 ) ;
if ( V_35 ) {
F_38 ( V_35 , 0 ) ;
F_39 ( V_35 ) ;
}
}
static void F_40 ( void )
{
V_21 = V_28 ;
F_1 ( V_21 ) ;
}
static inline void F_18 ( void ) {}
static int F_41 ( T_4 V_39 )
{
T_1 V_1 = V_40 [ V_39 ] ;
int error = 0 ;
error = ( V_22 || V_23 ) ? 0 : F_42 () ;
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
static int F_43 ( T_4 V_39 )
{
T_2 V_7 = V_8 ;
T_1 V_1 = V_21 ;
int error ;
F_9 () ;
switch ( V_1 ) {
case V_44 :
F_44 () ;
V_7 = F_45 ( V_1 ) ;
break;
case V_18 :
if ( ! V_45 )
return - V_43 ;
error = V_45 () ;
if ( error )
return error ;
F_46 ( V_46 L_6 ) ;
break;
}
F_47 ( V_47 , 1 ) ;
F_48 ( V_1 ) ;
if ( F_49 ( V_7 ) && ( V_1 == V_18 ) ) {
T_5 V_48 ;
F_50 ( V_49 , & V_48 ) ;
if ( V_48 & V_50 ) {
F_51 ( V_49 ) ;
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
case V_51 :
case V_52 :
case V_53 :
V_1 = V_40 [ V_39 ] ;
return V_41 [ V_1 ] ;
default:
return 0 ;
}
}
static int F_55 ( T_4 V_39 )
{
int error = F_41 ( V_39 ) ;
if ( ! error )
error = F_26 () ;
return error ;
}
static void F_56 ( void )
{
int V_54 ;
for ( V_54 = V_44 ; V_54 < V_55 ; V_54 ++ ) {
T_2 V_7 ;
T_6 V_56 , V_57 ;
V_7 = F_57 ( V_54 , & V_56 , & V_57 ) ;
if ( F_49 ( V_7 ) ) {
V_41 [ V_54 ] = 1 ;
}
}
F_58 ( V_24 ?
& V_58 : & V_59 ) ;
}
static inline void F_56 ( void ) {}
void T_3 F_59 ( void )
{
V_60 = true ;
}
static int F_60 ( void )
{
int error ;
error = V_22 ? 0 : F_42 () ;
if ( ! error ) {
V_21 = V_55 ;
F_1 ( V_21 ) ;
}
return error ;
}
static int F_61 ( void )
{
T_2 V_7 = V_8 ;
F_9 () ;
V_7 = F_45 ( V_55 ) ;
F_48 ( V_55 ) ;
return F_49 ( V_7 ) ? 0 : - V_20 ;
}
static void F_62 ( void )
{
F_63 () ;
F_48 ( V_55 ) ;
if ( V_61 && V_62 != V_61 -> V_63 ) {
F_4 ( V_64 L_7
L_8 ) ;
F_64 ( L_9 ) ;
}
F_53 () ;
F_52 () ;
}
static void F_65 ( void )
{
F_32 () ;
F_66 () ;
}
static int F_67 ( void )
{
int error ;
F_1 ( V_55 ) ;
error = F_6 ( V_55 ) ;
if ( ! error ) {
if ( ! V_22 )
error = F_42 () ;
if ( ! error )
V_21 = V_55 ;
}
return error ;
}
static void F_68 ( void )
{
T_2 V_7 ;
T_6 V_56 , V_57 ;
V_7 = F_57 ( V_55 , & V_56 , & V_57 ) ;
if ( F_3 ( V_7 ) )
return;
F_69 ( V_24 ?
& V_65 : & V_66 ) ;
V_41 [ V_55 ] = 1 ;
if ( V_60 )
return;
F_70 ( V_67 , 1 , (struct V_68 * * ) & V_61 ) ;
if ( V_61 )
V_62 = V_61 -> V_63 ;
}
static inline void F_68 ( void ) {}
int F_71 ( T_1 V_1 )
{
T_4 V_69 [] = {
[ 1 ] = V_52 ,
[ 3 ] = V_53 ,
[ 5 ] = V_70
} ;
if ( V_1 < 6 && V_69 [ V_1 ] )
return F_72 ( V_69 [ V_1 ] ) ;
if ( V_1 == 4 )
return F_73 () ;
return - V_71 ;
}
static void F_74 ( void )
{
F_6 ( V_16 ) ;
F_21 () ;
}
static void F_75 ( void )
{
F_4 ( V_72 L_10 , V_73 ) ;
F_76 () ;
F_45 ( V_16 ) ;
}
int T_3 F_77 ( void )
{
T_2 V_7 ;
T_6 V_56 , V_57 ;
char V_74 [ V_75 * 3 + 1 ] ;
char * V_76 = V_74 ;
int V_54 ;
if ( V_77 )
return 0 ;
F_18 () ;
V_41 [ V_28 ] = 1 ;
F_56 () ;
F_68 () ;
V_7 = F_57 ( V_16 , & V_56 , & V_57 ) ;
if ( F_49 ( V_7 ) ) {
V_41 [ V_16 ] = 1 ;
V_78 = F_74 ;
V_79 = F_75 ;
}
V_74 [ 0 ] = 0 ;
for ( V_54 = 0 ; V_54 < V_75 ; V_54 ++ ) {
if ( V_41 [ V_54 ] )
V_76 += sprintf ( V_76 , L_11 , V_54 ) ;
}
F_46 ( V_46 L_12 , V_74 ) ;
F_78 ( & V_80 ) ;
return 0 ;
}
