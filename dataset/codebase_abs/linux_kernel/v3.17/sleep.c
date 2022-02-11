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
int V_28 ;
if ( F_22 ( V_29 , & V_28 , NULL , NULL ) && V_28 >= 2012 )
F_17 () ;
F_23 ( V_30 ) ;
}
static int F_24 ( void )
{
F_25 () ;
F_26 () ;
F_27 () ;
return 0 ;
}
static int F_28 ( void )
{
F_24 () ;
return F_29 () ;
}
static int F_30 ( void )
{
int error = F_6 ( V_22 ) ;
if ( error )
V_22 = V_31 ;
return error ;
}
static int F_31 ( void )
{
int error = F_30 () ;
if ( ! error )
error = F_28 () ;
return error ;
}
static int F_32 ( struct V_32 * V_33 , void * V_34 )
{
struct V_35 * V_32 = F_33 ( V_33 ) ;
const char * V_36 = F_34 ( V_32 ) ;
return ! strcmp ( V_36 , V_37 ) ;
}
static void F_35 ( void )
{
struct V_32 * V_38 ;
T_1 V_1 = V_22 ;
F_36 () ;
F_37 () ;
if ( V_1 == V_31 )
return;
F_4 (KERN_INFO PREFIX L_4 ,
acpi_state) ;
F_38 ( V_1 ) ;
F_39 ( V_1 ) ;
F_8 ( ( V_39 ) 0 ) ;
V_22 = V_31 ;
F_40 () ;
if ( ! V_40 )
return;
V_40 = false ;
V_38 = F_41 ( & V_41 , NULL , NULL ,
F_32 ) ;
if ( V_38 ) {
F_42 ( V_38 , 0 ) ;
F_43 ( V_38 ) ;
}
}
static void F_44 ( T_1 V_1 )
{
V_22 = V_1 ;
F_1 ( V_22 ) ;
F_45 () ;
}
static void F_46 ( void )
{
F_47 () ;
V_22 = V_31 ;
F_1 ( V_22 ) ;
}
static inline void F_21 ( void ) {}
static int F_48 ( T_5 V_42 )
{
T_1 V_1 = V_43 [ V_42 ] ;
int error ;
error = ( V_23 || V_24 ) ? 0 : F_49 () ;
if ( error )
return error ;
if ( ! V_44 [ V_1 ] ) {
F_50 ( L_5 , V_1 ) ;
return - V_45 ;
}
F_44 ( V_1 ) ;
return 0 ;
}
static int F_51 ( T_5 V_42 )
{
T_2 V_2 = V_46 ;
T_1 V_1 = V_22 ;
int error ;
F_9 () ;
F_52 ( F_53 ( L_6 ) , V_1 , true ) ;
switch ( V_1 ) {
case V_47 :
F_54 () ;
V_2 = F_55 ( V_1 ) ;
break;
case V_11 :
if ( ! V_48 )
return - V_45 ;
error = V_48 () ;
if ( error )
return error ;
F_56 ( V_49 L_7 ) ;
break;
}
F_52 ( F_53 ( L_6 ) , V_1 , false ) ;
F_57 ( V_50 , 1 ) ;
F_58 ( V_1 ) ;
if ( F_14 ( V_2 ) && ( V_1 == V_11 ) ) {
T_6 V_51 = V_52 ;
F_59 ( V_53 , & V_51 ) ;
if ( V_51 & V_54 ) {
F_60 ( V_53 ) ;
V_40 = true ;
}
}
F_25 () ;
F_61 () ;
F_62 () ;
return F_14 ( V_2 ) ? 0 : - V_13 ;
}
static int F_63 ( T_5 V_42 )
{
T_1 V_1 ;
switch ( V_42 ) {
case V_55 :
case V_56 :
case V_57 :
V_1 = V_43 [ V_42 ] ;
return V_44 [ V_1 ] ;
default:
return 0 ;
}
}
static int F_64 ( T_5 V_42 )
{
int error = F_48 ( V_42 ) ;
if ( ! error )
error = F_30 () ;
return error ;
}
static int F_65 ( void )
{
F_45 () ;
return 0 ;
}
static void F_66 ( void )
{
F_47 () ;
}
static void F_67 ( void )
{
int V_58 ;
for ( V_58 = V_47 ; V_58 < V_59 ; V_58 ++ )
if ( F_12 ( V_58 ) )
V_44 [ V_58 ] = 1 ;
F_68 ( V_25 ?
& V_60 : & V_61 ) ;
F_69 ( & V_62 ) ;
}
static inline void F_67 ( void ) {}
void T_4 F_70 ( void )
{
V_63 = true ;
}
static int F_71 ( void )
{
int error ;
error = V_23 ? 0 : F_49 () ;
if ( ! error )
F_44 ( V_59 ) ;
return error ;
}
static int F_72 ( void )
{
T_2 V_2 = V_46 ;
F_9 () ;
V_2 = F_55 ( V_59 ) ;
F_58 ( V_59 ) ;
return F_14 ( V_2 ) ? 0 : - V_13 ;
}
static void F_73 ( void )
{
F_74 () ;
F_58 ( V_59 ) ;
if ( V_64 && V_65 != V_64 -> V_66 )
F_75 ( L_8 ) ;
F_62 () ;
F_61 () ;
}
static void F_76 ( void )
{
F_36 () ;
F_77 () ;
}
static int F_78 ( void )
{
int error ;
F_1 ( V_59 ) ;
error = F_6 ( V_59 ) ;
if ( ! error ) {
if ( ! V_23 )
error = F_49 () ;
if ( ! error ) {
V_22 = V_59 ;
F_45 () ;
}
}
return error ;
}
static void F_79 ( void )
{
if ( ! F_12 ( V_59 ) )
return;
F_80 ( V_25 ?
& V_67 : & V_68 ) ;
V_44 [ V_59 ] = 1 ;
if ( V_63 )
return;
F_81 ( V_69 , 1 , (struct V_70 * * ) & V_64 ) ;
if ( V_64 )
V_65 = V_64 -> V_66 ;
}
static inline void F_79 ( void ) {}
int F_82 ( T_1 V_1 )
{
T_5 V_71 [] = {
[ 1 ] = V_56 ,
[ 3 ] = V_57 ,
[ 5 ] = V_72
} ;
if ( V_1 < 6 && V_71 [ V_1 ] )
return F_83 ( V_71 [ V_1 ] ) ;
if ( V_1 == 4 )
return F_84 () ;
return - V_73 ;
}
static void F_85 ( void )
{
F_6 ( V_9 ) ;
F_25 () ;
}
static void F_86 ( void )
{
F_4 ( V_74 L_9 , V_75 ) ;
F_87 () ;
F_55 ( V_9 ) ;
}
int T_4 F_88 ( void )
{
char V_76 [ V_77 * 3 + 1 ] ;
char * V_78 = V_76 ;
int V_58 ;
F_21 () ;
V_44 [ V_31 ] = 1 ;
F_67 () ;
F_79 () ;
if ( F_12 ( V_9 ) ) {
V_44 [ V_9 ] = 1 ;
V_79 = F_85 ;
V_80 = F_86 ;
}
V_76 [ 0 ] = 0 ;
for ( V_58 = 0 ; V_58 < V_77 ; V_58 ++ ) {
if ( V_44 [ V_58 ] )
V_78 += sprintf ( V_78 , L_10 , V_58 ) ;
}
F_56 ( V_49 L_11 , V_76 ) ;
F_89 ( & V_81 ) ;
return 0 ;
}
