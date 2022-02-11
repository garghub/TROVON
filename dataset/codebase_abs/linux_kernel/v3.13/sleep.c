static void F_1 ( T_1 V_1 )
{
T_2 V_2 ;
V_2 = F_2 ( NULL , L_1 , V_1 ) ;
if ( F_3 ( V_2 ) && V_2 != V_3 ) {
F_4 ( V_4 L_2 ) ;
}
}
static int F_5 ( struct V_5 * V_6 ,
unsigned long V_7 , void * V_8 )
{
F_1 ( V_9 ) ;
return V_10 ;
}
static int F_6 ( T_1 V_1 )
{
#ifdef F_7
if ( V_1 == V_11 ) {
if ( ! V_12 )
return - V_13 ;
F_8 ( V_12 ) ;
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
return V_14 ;
}
void T_3 F_13 ( void )
{
V_15 = true ;
}
void T_3 F_14 ( void )
{
V_16 = true ;
}
void T_3 F_15 ( void )
{
V_17 = true ;
}
static int T_3 F_16 ( const struct V_18 * V_19 )
{
F_15 () ;
return 0 ;
}
static int T_3 F_17 ( const struct V_18 * V_19 )
{
F_13 () ;
return 0 ;
}
static void F_18 ( void )
{
F_19 ( V_20 ) ;
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
int error = F_6 ( V_14 ) ;
if ( error )
V_14 = V_21 ;
return error ;
}
static int F_27 ( void )
{
int error = F_26 () ;
if ( ! error )
error = F_24 () ;
return error ;
}
static int F_28 ( struct V_22 * V_23 , void * V_24 )
{
struct V_25 * V_22 = F_29 ( V_23 ) ;
const char * V_26 = F_30 ( V_22 ) ;
return ! strcmp ( V_26 , V_27 ) ;
}
static void F_31 ( void )
{
struct V_22 * V_28 ;
T_1 V_1 = V_14 ;
F_32 () ;
F_33 () ;
if ( V_1 == V_21 )
return;
F_4 (KERN_INFO PREFIX L_4 ,
acpi_state) ;
F_34 ( V_1 ) ;
F_35 ( V_1 ) ;
F_8 ( ( V_29 ) 0 ) ;
V_14 = V_21 ;
F_36 () ;
if ( ! V_30 )
return;
V_30 = false ;
V_28 = F_37 ( & V_31 , NULL , NULL ,
F_28 ) ;
if ( V_28 ) {
F_38 ( V_28 , 0 ) ;
F_39 ( V_28 ) ;
}
}
static void F_40 ( T_1 V_1 )
{
V_14 = V_1 ;
F_1 ( V_14 ) ;
F_41 () ;
}
static void F_42 ( void )
{
F_43 () ;
V_14 = V_21 ;
F_1 ( V_14 ) ;
}
static inline void F_18 ( void ) {}
static int F_44 ( T_4 V_32 )
{
T_1 V_1 = V_33 [ V_32 ] ;
int error ;
error = ( V_15 || V_16 ) ? 0 : F_45 () ;
if ( error )
return error ;
if ( ! V_34 [ V_1 ] ) {
F_46 ( L_5 , V_1 ) ;
return - V_35 ;
}
F_40 ( V_1 ) ;
return 0 ;
}
static int F_47 ( T_4 V_32 )
{
T_2 V_2 = V_36 ;
T_1 V_1 = V_14 ;
int error ;
F_9 () ;
switch ( V_1 ) {
case V_37 :
F_48 () ;
V_2 = F_49 ( V_1 ) ;
break;
case V_11 :
if ( ! V_38 )
return - V_35 ;
error = V_38 () ;
if ( error )
return error ;
F_50 ( V_39 L_6 ) ;
break;
}
F_51 ( V_40 , 1 ) ;
F_52 ( V_1 ) ;
if ( F_53 ( V_2 ) && ( V_1 == V_11 ) ) {
T_5 V_41 = V_42 ;
F_54 ( V_43 , & V_41 ) ;
if ( V_41 & V_44 ) {
F_55 ( V_43 ) ;
V_30 = true ;
}
}
F_21 () ;
F_56 () ;
F_57 () ;
return F_53 ( V_2 ) ? 0 : - V_13 ;
}
static int F_58 ( T_4 V_32 )
{
T_1 V_1 ;
switch ( V_32 ) {
case V_45 :
case V_46 :
case V_47 :
V_1 = V_33 [ V_32 ] ;
return V_34 [ V_1 ] ;
default:
return 0 ;
}
}
static int F_59 ( T_4 V_32 )
{
int error = F_44 ( V_32 ) ;
if ( ! error )
error = F_26 () ;
return error ;
}
static void F_60 ( void )
{
int V_48 ;
for ( V_48 = V_37 ; V_48 < V_49 ; V_48 ++ ) {
T_2 V_2 ;
T_6 V_50 , V_51 ;
V_2 = F_61 ( V_48 , & V_50 , & V_51 ) ;
if ( F_53 ( V_2 ) ) {
V_34 [ V_48 ] = 1 ;
}
}
F_62 ( V_17 ?
& V_52 : & V_53 ) ;
}
static inline void F_60 ( void ) {}
void T_3 F_63 ( void )
{
V_54 = true ;
}
static int F_64 ( void )
{
int error ;
error = V_15 ? 0 : F_45 () ;
if ( ! error )
F_40 ( V_49 ) ;
return error ;
}
static int F_65 ( void )
{
T_2 V_2 = V_36 ;
F_9 () ;
V_2 = F_49 ( V_49 ) ;
F_52 ( V_49 ) ;
return F_53 ( V_2 ) ? 0 : - V_13 ;
}
static void F_66 ( void )
{
F_67 () ;
F_52 ( V_49 ) ;
if ( V_55 && V_56 != V_55 -> V_57 ) {
F_4 ( V_58 L_7
L_8 ) ;
F_68 ( L_9 ) ;
}
F_57 () ;
F_56 () ;
}
static void F_69 ( void )
{
F_32 () ;
F_70 () ;
}
static int F_71 ( void )
{
int error ;
F_1 ( V_49 ) ;
error = F_6 ( V_49 ) ;
if ( ! error ) {
if ( ! V_15 )
error = F_45 () ;
if ( ! error ) {
V_14 = V_49 ;
F_41 () ;
}
}
return error ;
}
static void F_72 ( void )
{
T_2 V_2 ;
T_6 V_50 , V_51 ;
V_2 = F_61 ( V_49 , & V_50 , & V_51 ) ;
if ( F_3 ( V_2 ) )
return;
F_73 ( V_17 ?
& V_59 : & V_60 ) ;
V_34 [ V_49 ] = 1 ;
if ( V_54 )
return;
F_74 ( V_61 , 1 , (struct V_62 * * ) & V_55 ) ;
if ( V_55 )
V_56 = V_55 -> V_57 ;
}
static inline void F_72 ( void ) {}
int F_75 ( T_1 V_1 )
{
T_4 V_63 [] = {
[ 1 ] = V_46 ,
[ 3 ] = V_47 ,
[ 5 ] = V_64
} ;
if ( V_1 < 6 && V_63 [ V_1 ] )
return F_76 ( V_63 [ V_1 ] ) ;
if ( V_1 == 4 )
return F_77 () ;
return - V_65 ;
}
static void F_78 ( void )
{
F_6 ( V_9 ) ;
F_21 () ;
}
static void F_79 ( void )
{
F_4 ( V_66 L_10 , V_67 ) ;
F_80 () ;
F_49 ( V_9 ) ;
}
int T_3 F_81 ( void )
{
T_2 V_2 ;
T_6 V_50 , V_51 ;
char V_68 [ V_69 * 3 + 1 ] ;
char * V_70 = V_68 ;
int V_48 ;
if ( V_71 )
return 0 ;
F_18 () ;
V_34 [ V_21 ] = 1 ;
F_60 () ;
F_72 () ;
V_2 = F_61 ( V_9 , & V_50 , & V_51 ) ;
if ( F_53 ( V_2 ) ) {
V_34 [ V_9 ] = 1 ;
V_72 = F_78 ;
V_73 = F_79 ;
}
V_68 [ 0 ] = 0 ;
for ( V_48 = 0 ; V_48 < V_69 ; V_48 ++ ) {
if ( V_34 [ V_48 ] )
V_70 += sprintf ( V_70 , L_11 , V_48 ) ;
}
F_50 ( V_39 L_12 , V_68 ) ;
F_82 ( & V_74 ) ;
return 0 ;
}
