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
static int T_4 F_18 ( const struct V_25 * V_26 )
{
V_24 = false ;
return 0 ;
}
void T_4 F_19 ( void )
{
V_27 = true ;
}
static int T_4 F_20 ( const struct V_25 * V_26 )
{
F_19 () ;
return 0 ;
}
static int T_4 F_21 ( const struct V_25 * V_26 )
{
F_16 () ;
return 0 ;
}
static void T_4 F_22 ( void )
{
int V_28 ;
if ( F_23 ( V_29 , & V_28 , NULL , NULL ) && V_28 >= 2012 )
F_17 () ;
F_24 ( V_30 ) ;
}
static int F_25 ( void )
{
F_26 () ;
F_27 () ;
F_28 () ;
return 0 ;
}
static int F_29 ( void )
{
F_25 () ;
return F_30 () ;
}
static int F_31 ( void )
{
int error = F_6 ( V_22 ) ;
if ( error )
V_22 = V_31 ;
return error ;
}
static int F_32 ( void )
{
int error = F_31 () ;
if ( ! error )
error = F_29 () ;
return error ;
}
static int F_33 ( struct V_32 * V_33 , void * V_34 )
{
struct V_35 * V_32 = F_34 ( V_33 ) ;
const char * V_36 = F_35 ( V_32 ) ;
return ! strcmp ( V_36 , V_37 ) ;
}
static void F_36 ( void )
{
struct V_32 * V_38 ;
T_1 V_1 = V_22 ;
F_37 () ;
F_38 () ;
if ( V_1 == V_31 )
return;
F_4 (KERN_INFO PREFIX L_4 ,
acpi_state) ;
F_39 ( V_1 ) ;
F_40 ( V_1 ) ;
F_8 ( 0 ) ;
V_22 = V_31 ;
F_41 () ;
if ( ! V_39 )
return;
V_39 = false ;
V_38 = F_42 ( & V_40 , NULL , NULL ,
F_33 ) ;
if ( V_38 ) {
F_43 ( V_38 , 0 ) ;
F_44 ( V_38 ) ;
}
}
static void F_45 ( T_1 V_1 )
{
V_22 = V_1 ;
F_1 ( V_22 ) ;
F_46 () ;
}
static void F_47 ( void )
{
F_48 () ;
V_22 = V_31 ;
F_1 ( V_22 ) ;
}
static inline void F_22 ( void ) {}
static int F_49 ( T_5 V_41 )
{
T_1 V_1 = V_42 [ V_41 ] ;
int error ;
error = ( V_23 || V_24 ) ? 0 : F_50 () ;
if ( error )
return error ;
if ( ! V_43 [ V_1 ] ) {
F_51 ( L_5 , V_1 ) ;
return - V_44 ;
}
if ( V_1 > V_45 )
F_52 () ;
F_45 ( V_1 ) ;
return 0 ;
}
static int F_53 ( T_5 V_41 )
{
T_2 V_2 = V_46 ;
T_1 V_1 = V_22 ;
int error ;
F_9 () ;
F_54 ( F_55 ( L_6 ) , V_1 , true ) ;
switch ( V_1 ) {
case V_45 :
F_56 () ;
V_2 = F_57 ( V_1 ) ;
break;
case V_11 :
if ( ! V_47 )
return - V_44 ;
error = V_47 () ;
if ( error )
return error ;
F_58 ( V_48 L_7 ) ;
F_59 () ;
break;
}
F_54 ( F_55 ( L_6 ) , V_1 , false ) ;
F_60 ( V_49 , 1 ) ;
F_61 ( V_1 ) ;
if ( F_14 ( V_2 ) && ( V_1 == V_11 ) ) {
T_6 V_50 = V_51 ;
F_62 ( V_52 , & V_50 ) ;
if ( V_50 & V_53 ) {
F_63 ( V_52 ) ;
V_39 = true ;
}
}
F_26 () ;
F_37 () ;
F_64 () ;
return F_14 ( V_2 ) ? 0 : - V_13 ;
}
static int F_65 ( T_5 V_41 )
{
T_1 V_1 ;
switch ( V_41 ) {
case V_54 :
case V_55 :
case V_56 :
V_1 = V_42 [ V_41 ] ;
return V_43 [ V_1 ] ;
default:
return 0 ;
}
}
static int F_66 ( T_5 V_41 )
{
int error = F_49 ( V_41 ) ;
if ( ! error )
error = F_31 () ;
return error ;
}
static int F_67 ( void )
{
F_46 () ;
return 0 ;
}
static int F_68 ( void )
{
F_10 ( V_31 ) ;
F_69 () ;
F_27 () ;
if ( F_70 () )
F_71 ( V_57 ) ;
return 0 ;
}
static void F_72 ( void )
{
F_39 ( V_31 ) ;
if ( F_70 () )
F_73 ( V_57 ) ;
F_74 () ;
}
static void F_75 ( void )
{
F_48 () ;
}
static void F_76 ( void )
{
int V_58 ;
for ( V_58 = V_45 ; V_58 < V_59 ; V_58 ++ )
if ( F_12 ( V_58 ) )
V_43 [ V_58 ] = 1 ;
F_77 ( V_27 ?
& V_60 : & V_61 ) ;
F_78 ( & V_62 ) ;
}
static inline void F_76 ( void ) {}
static int F_79 ( void )
{
F_80 ( V_63 , & V_64 ) ;
return 0 ;
}
static void F_81 ( void )
{
T_1 V_65 = 0 ;
F_80 ( V_63 , & V_65 ) ;
if ( V_65 == V_64 )
return;
F_60 ( V_63 , V_64 ) ;
}
void F_82 ( void )
{
F_83 ( & V_66 ) ;
}
static inline void F_82 ( void ) {}
void T_4 F_84 ( void )
{
V_67 = true ;
}
static int F_85 ( void )
{
int error ;
error = V_23 ? 0 : F_50 () ;
if ( ! error )
F_45 ( V_59 ) ;
return error ;
}
static int F_86 ( void )
{
T_2 V_2 = V_46 ;
F_9 () ;
V_2 = F_57 ( V_59 ) ;
F_61 ( V_59 ) ;
return F_14 ( V_2 ) ? 0 : - V_13 ;
}
static void F_87 ( void )
{
F_59 () ;
F_88 () ;
F_61 ( V_59 ) ;
if ( V_68 && V_69 != V_68 -> V_70 )
F_89 ( L_8 ) ;
F_64 () ;
F_37 () ;
}
static void F_90 ( void )
{
F_37 () ;
F_74 () ;
}
static int F_91 ( void )
{
int error ;
F_1 ( V_59 ) ;
error = F_6 ( V_59 ) ;
if ( ! error ) {
if ( ! V_23 )
error = F_50 () ;
if ( ! error ) {
V_22 = V_59 ;
F_46 () ;
}
}
return error ;
}
static void F_92 ( void )
{
if ( ! F_12 ( V_59 ) )
return;
F_93 ( V_27 ?
& V_71 : & V_72 ) ;
V_43 [ V_59 ] = 1 ;
if ( V_67 )
return;
F_94 ( V_73 , 1 , (struct V_74 * * ) & V_68 ) ;
if ( V_68 )
V_69 = V_68 -> V_70 ;
}
static inline void F_92 ( void ) {}
static void F_95 ( void )
{
F_6 ( V_9 ) ;
F_26 () ;
F_27 () ;
}
static void F_96 ( void )
{
F_4 ( V_75 L_9 , V_76 ) ;
F_97 () ;
F_57 ( V_9 ) ;
}
int T_4 F_98 ( void )
{
char V_77 [ V_78 * 3 + 1 ] ;
char * V_79 = V_77 ;
int V_58 ;
F_22 () ;
V_43 [ V_31 ] = 1 ;
F_82 () ;
F_76 () ;
F_92 () ;
if ( F_12 ( V_9 ) ) {
V_43 [ V_9 ] = 1 ;
V_80 = F_95 ;
V_81 = F_96 ;
} else {
V_82 = true ;
}
V_77 [ 0 ] = 0 ;
for ( V_58 = 0 ; V_58 < V_78 ; V_58 ++ ) {
if ( V_43 [ V_58 ] )
V_79 += sprintf ( V_79 , L_10 , V_58 ) ;
}
F_58 ( V_48 L_11 , V_77 ) ;
F_99 ( & V_83 ) ;
return 0 ;
}
