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
static bool F_12 ( T_3 V_14 )
{
T_2 V_2 ;
T_3 V_15 , V_16 ;
V_2 = F_13 ( V_14 , & V_15 , & V_16 ) ;
return F_14 ( V_2 ) && ( ! V_17
|| ( V_18 . V_19 . V_20
&& V_18 . V_21 . V_20 ) ) ;
}
T_1 F_15 ( void )
{
return V_22 ;
}
void T_4 F_16 ( void )
{
V_23 = true ;
}
void T_4 F_17 ( void )
{
V_24 = true ;
}
void T_4 F_18 ( void )
{
V_25 = true ;
}
static int T_4 F_19 ( const struct V_26 * V_27 )
{
F_18 () ;
return 0 ;
}
static int T_4 F_20 ( const struct V_26 * V_27 )
{
F_16 () ;
return 0 ;
}
static void F_21 ( void )
{
F_22 ( V_28 ) ;
}
static int F_23 ( void )
{
F_24 () ;
F_25 () ;
F_26 () ;
return 0 ;
}
static int F_27 ( void )
{
F_23 () ;
return F_28 () ;
}
static int F_29 ( void )
{
int error = F_6 ( V_22 ) ;
if ( error )
V_22 = V_29 ;
return error ;
}
static int F_30 ( void )
{
int error = F_29 () ;
if ( ! error )
error = F_27 () ;
return error ;
}
static int F_31 ( struct V_30 * V_31 , void * V_32 )
{
struct V_33 * V_30 = F_32 ( V_31 ) ;
const char * V_34 = F_33 ( V_30 ) ;
return ! strcmp ( V_34 , V_35 ) ;
}
static void F_34 ( void )
{
struct V_30 * V_36 ;
T_1 V_1 = V_22 ;
F_35 () ;
F_36 () ;
if ( V_1 == V_29 )
return;
F_4 (KERN_INFO PREFIX L_4 ,
acpi_state) ;
F_37 ( V_1 ) ;
F_38 ( V_1 ) ;
F_8 ( ( V_37 ) 0 ) ;
V_22 = V_29 ;
F_39 () ;
if ( ! V_38 )
return;
V_38 = false ;
V_36 = F_40 ( & V_39 , NULL , NULL ,
F_31 ) ;
if ( V_36 ) {
F_41 ( V_36 , 0 ) ;
F_42 ( V_36 ) ;
}
}
static void F_43 ( T_1 V_1 )
{
V_22 = V_1 ;
F_1 ( V_22 ) ;
F_44 () ;
}
static void F_45 ( void )
{
F_46 () ;
V_22 = V_29 ;
F_1 ( V_22 ) ;
}
static inline void F_21 ( void ) {}
static int F_47 ( T_5 V_40 )
{
T_1 V_1 = V_41 [ V_40 ] ;
int error ;
error = ( V_23 || V_24 ) ? 0 : F_48 () ;
if ( error )
return error ;
if ( ! V_42 [ V_1 ] ) {
F_49 ( L_5 , V_1 ) ;
return - V_43 ;
}
F_43 ( V_1 ) ;
return 0 ;
}
static int F_50 ( T_5 V_40 )
{
T_2 V_2 = V_44 ;
T_1 V_1 = V_22 ;
int error ;
F_9 () ;
switch ( V_1 ) {
case V_45 :
F_51 () ;
V_2 = F_52 ( V_1 ) ;
break;
case V_11 :
if ( ! V_46 )
return - V_43 ;
error = V_46 () ;
if ( error )
return error ;
F_53 ( V_47 L_6 ) ;
break;
}
F_54 ( V_48 , 1 ) ;
F_55 ( V_1 ) ;
if ( F_14 ( V_2 ) && ( V_1 == V_11 ) ) {
T_6 V_49 = V_50 ;
F_56 ( V_51 , & V_49 ) ;
if ( V_49 & V_52 ) {
F_57 ( V_51 ) ;
V_38 = true ;
}
}
F_24 () ;
F_58 () ;
F_59 () ;
return F_14 ( V_2 ) ? 0 : - V_13 ;
}
static int F_60 ( T_5 V_40 )
{
T_1 V_1 ;
switch ( V_40 ) {
case V_53 :
case V_54 :
case V_55 :
V_1 = V_41 [ V_40 ] ;
return V_42 [ V_1 ] ;
default:
return 0 ;
}
}
static int F_61 ( T_5 V_40 )
{
int error = F_47 ( V_40 ) ;
if ( ! error )
error = F_29 () ;
return error ;
}
static void F_62 ( void )
{
int V_56 ;
for ( V_56 = V_45 ; V_56 < V_57 ; V_56 ++ )
if ( F_12 ( V_56 ) )
V_42 [ V_56 ] = 1 ;
F_63 ( V_25 ?
& V_58 : & V_59 ) ;
}
static inline void F_62 ( void ) {}
void T_4 F_64 ( void )
{
V_60 = true ;
}
static int F_65 ( void )
{
int error ;
error = V_23 ? 0 : F_48 () ;
if ( ! error )
F_43 ( V_57 ) ;
return error ;
}
static int F_66 ( void )
{
T_2 V_2 = V_44 ;
F_9 () ;
V_2 = F_52 ( V_57 ) ;
F_55 ( V_57 ) ;
return F_14 ( V_2 ) ? 0 : - V_13 ;
}
static void F_67 ( void )
{
F_68 () ;
F_55 ( V_57 ) ;
if ( V_61 && V_62 != V_61 -> V_63 )
F_69 ( L_7 ) ;
F_59 () ;
F_58 () ;
}
static void F_70 ( void )
{
F_35 () ;
F_71 () ;
}
static int F_72 ( void )
{
int error ;
F_1 ( V_57 ) ;
error = F_6 ( V_57 ) ;
if ( ! error ) {
if ( ! V_23 )
error = F_48 () ;
if ( ! error ) {
V_22 = V_57 ;
F_44 () ;
}
}
return error ;
}
static void F_73 ( void )
{
if ( ! F_12 ( V_57 ) )
return;
F_74 ( V_25 ?
& V_64 : & V_65 ) ;
V_42 [ V_57 ] = 1 ;
if ( V_60 )
return;
F_75 ( V_66 , 1 , (struct V_67 * * ) & V_61 ) ;
if ( V_61 )
V_62 = V_61 -> V_63 ;
}
static inline void F_73 ( void ) {}
int F_76 ( T_1 V_1 )
{
T_5 V_68 [] = {
[ 1 ] = V_54 ,
[ 3 ] = V_55 ,
[ 5 ] = V_69
} ;
if ( V_1 < 6 && V_68 [ V_1 ] )
return F_77 ( V_68 [ V_1 ] ) ;
if ( V_1 == 4 )
return F_78 () ;
return - V_70 ;
}
static void F_79 ( void )
{
F_6 ( V_9 ) ;
F_24 () ;
}
static void F_80 ( void )
{
F_4 ( V_71 L_8 , V_72 ) ;
F_81 () ;
F_52 ( V_9 ) ;
}
int T_4 F_82 ( void )
{
char V_73 [ V_74 * 3 + 1 ] ;
char * V_75 = V_73 ;
int V_56 ;
F_21 () ;
V_42 [ V_29 ] = 1 ;
F_62 () ;
F_73 () ;
if ( F_12 ( V_9 ) ) {
V_42 [ V_9 ] = 1 ;
V_76 = F_79 ;
V_77 = F_80 ;
}
V_73 [ 0 ] = 0 ;
for ( V_56 = 0 ; V_56 < V_74 ; V_56 ++ ) {
if ( V_42 [ V_56 ] )
V_75 += sprintf ( V_75 , L_9 , V_56 ) ;
}
F_53 ( V_47 L_10 , V_73 ) ;
F_83 ( & V_78 ) ;
return 0 ;
}
