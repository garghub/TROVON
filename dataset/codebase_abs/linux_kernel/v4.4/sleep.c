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
static void T_4 F_21 ( void )
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
if ( V_1 > V_46 )
F_51 () ;
F_44 ( V_1 ) ;
return 0 ;
}
static int F_52 ( T_5 V_42 )
{
T_2 V_2 = V_47 ;
T_1 V_1 = V_22 ;
int error ;
F_9 () ;
F_53 ( F_54 ( L_6 ) , V_1 , true ) ;
switch ( V_1 ) {
case V_46 :
F_55 () ;
V_2 = F_56 ( V_1 ) ;
break;
case V_11 :
if ( ! V_48 )
return - V_45 ;
error = V_48 () ;
if ( error )
return error ;
F_57 ( V_49 L_7 ) ;
F_58 () ;
break;
}
F_53 ( F_54 ( L_6 ) , V_1 , false ) ;
F_59 ( V_50 , 1 ) ;
F_60 ( V_1 ) ;
if ( F_14 ( V_2 ) && ( V_1 == V_11 ) ) {
T_6 V_51 = V_52 ;
F_61 ( V_53 , & V_51 ) ;
if ( V_51 & V_54 ) {
F_62 ( V_53 ) ;
V_40 = true ;
}
}
F_25 () ;
F_63 () ;
F_64 () ;
return F_14 ( V_2 ) ? 0 : - V_13 ;
}
static int F_65 ( T_5 V_42 )
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
static int F_66 ( T_5 V_42 )
{
int error = F_48 ( V_42 ) ;
if ( ! error )
error = F_30 () ;
return error ;
}
static int F_67 ( void )
{
F_45 () ;
return 0 ;
}
static int F_68 ( void )
{
F_10 ( V_31 ) ;
F_69 () ;
F_26 () ;
if ( F_70 () )
F_71 ( V_58 ) ;
return 0 ;
}
static void F_72 ( void )
{
F_38 ( V_31 ) ;
if ( F_70 () )
F_73 ( V_58 ) ;
F_74 () ;
}
static void F_75 ( void )
{
F_47 () ;
}
static void F_76 ( void )
{
int V_59 ;
for ( V_59 = V_46 ; V_59 < V_60 ; V_59 ++ )
if ( F_12 ( V_59 ) )
V_44 [ V_59 ] = 1 ;
F_77 ( V_25 ?
& V_61 : & V_62 ) ;
F_78 ( & V_63 ) ;
}
static inline void F_76 ( void ) {}
void T_4 F_79 ( void )
{
V_64 = true ;
}
static int F_80 ( void )
{
int error ;
error = V_23 ? 0 : F_49 () ;
if ( ! error )
F_44 ( V_60 ) ;
return error ;
}
static int F_81 ( void )
{
T_2 V_2 = V_47 ;
F_9 () ;
V_2 = F_56 ( V_60 ) ;
F_60 ( V_60 ) ;
return F_14 ( V_2 ) ? 0 : - V_13 ;
}
static void F_82 ( void )
{
F_83 () ;
F_60 ( V_60 ) ;
if ( V_65 && V_66 != V_65 -> V_67 )
F_84 ( L_8 ) ;
F_64 () ;
F_63 () ;
}
static void F_85 ( void )
{
F_36 () ;
F_74 () ;
}
static int F_86 ( void )
{
int error ;
F_1 ( V_60 ) ;
error = F_6 ( V_60 ) ;
if ( ! error ) {
if ( ! V_23 )
error = F_49 () ;
if ( ! error ) {
V_22 = V_60 ;
F_45 () ;
}
}
return error ;
}
static void F_87 ( void )
{
if ( ! F_12 ( V_60 ) )
return;
F_88 ( V_25 ?
& V_68 : & V_69 ) ;
V_44 [ V_60 ] = 1 ;
if ( V_64 )
return;
F_89 ( V_70 , 1 , (struct V_71 * * ) & V_65 ) ;
if ( V_65 )
V_66 = V_65 -> V_67 ;
}
static inline void F_87 ( void ) {}
static void F_90 ( void )
{
F_6 ( V_9 ) ;
F_25 () ;
F_26 () ;
}
static void F_91 ( void )
{
F_4 ( V_72 L_9 , V_73 ) ;
F_92 () ;
F_56 ( V_9 ) ;
}
int T_4 F_93 ( void )
{
char V_74 [ V_75 * 3 + 1 ] ;
char * V_76 = V_74 ;
int V_59 ;
F_21 () ;
V_44 [ V_31 ] = 1 ;
F_76 () ;
F_87 () ;
if ( F_12 ( V_9 ) ) {
V_44 [ V_9 ] = 1 ;
V_77 = F_90 ;
V_78 = F_91 ;
}
V_74 [ 0 ] = 0 ;
for ( V_59 = 0 ; V_59 < V_75 ; V_59 ++ ) {
if ( V_44 [ V_59 ] )
V_76 += sprintf ( V_76 , L_10 , V_59 ) ;
}
F_57 ( V_49 L_11 , V_74 ) ;
F_94 ( & V_79 ) ;
return 0 ;
}
