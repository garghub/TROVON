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
void T_3 F_12 ( void )
{
V_21 = true ;
}
void T_3 F_13 ( void )
{
V_22 = true ;
}
static int F_14 ( void )
{
F_15 () ;
F_16 () ;
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
int error = F_6 ( V_23 ) ;
if ( error )
V_23 = V_24 ;
return error ;
}
static int F_21 ( void )
{
int error = F_20 () ;
if ( ! error )
error = F_18 () ;
return error ;
}
static int F_22 ( struct V_25 * V_26 , void * V_27 )
{
struct V_28 * V_25 = F_23 ( V_26 ) ;
const char * V_29 = F_24 ( V_25 ) ;
return ! strcmp ( V_29 , V_30 ) ;
}
static void F_25 ( void )
{
struct V_25 * V_31 ;
T_1 V_1 = V_23 ;
F_26 () ;
F_27 () ;
if ( V_1 == V_24 )
return;
F_4 (KERN_INFO PREFIX L_4 ,
acpi_state) ;
F_28 ( V_1 ) ;
F_29 ( V_1 ) ;
F_8 ( ( V_32 ) 0 ) ;
V_23 = V_24 ;
if ( ! V_33 )
return;
V_33 = false ;
V_31 = F_30 ( & V_34 , NULL , NULL ,
F_22 ) ;
if ( V_31 ) {
F_31 ( V_31 , 0 ) ;
F_32 ( V_31 ) ;
}
}
static void F_33 ( void )
{
V_23 = V_24 ;
F_1 ( V_23 ) ;
}
static int F_34 ( T_4 V_35 )
{
T_1 V_1 = V_36 [ V_35 ] ;
int error = 0 ;
error = V_21 ? 0 : F_35 () ;
if ( error )
return error ;
if ( V_37 [ V_1 ] ) {
V_23 = V_1 ;
F_1 ( V_23 ) ;
} else {
F_4 ( V_38 L_5 ,
V_35 ) ;
error = - V_39 ;
}
return error ;
}
static int F_36 ( T_4 V_35 )
{
T_2 V_7 = V_8 ;
T_1 V_1 = V_23 ;
int error ;
F_9 () ;
switch ( V_1 ) {
case V_40 :
F_37 () ;
V_7 = F_38 ( V_1 ) ;
break;
case V_18 :
error = F_39 () ;
if ( error )
return error ;
F_40 ( V_41 L_6 ) ;
break;
}
F_41 ( V_42 , 1 ) ;
F_42 ( V_1 ) ;
if ( F_43 ( V_7 ) && ( V_1 == V_18 ) ) {
T_5 V_43 ;
F_44 ( V_44 , & V_43 ) ;
if ( V_43 & V_45 ) {
F_45 ( V_44 ) ;
V_33 = true ;
}
}
F_15 () ;
F_46 () ;
F_47 () ;
return F_43 ( V_7 ) ? 0 : - V_20 ;
}
static int F_48 ( T_4 V_35 )
{
T_1 V_1 ;
switch ( V_35 ) {
case V_46 :
case V_47 :
case V_48 :
V_1 = V_36 [ V_35 ] ;
return V_37 [ V_1 ] ;
default:
return 0 ;
}
}
static int F_49 ( T_4 V_35 )
{
int error = F_34 ( V_35 ) ;
if ( ! error )
error = F_20 () ;
return error ;
}
static int T_3 F_50 ( const struct V_49 * V_50 )
{
V_22 = true ;
return 0 ;
}
static int T_3 F_51 ( const struct V_49 * V_50 )
{
F_12 () ;
return 0 ;
}
void T_3 F_52 ( void )
{
V_51 = true ;
}
static int F_53 ( void )
{
int error ;
error = V_21 ? 0 : F_35 () ;
if ( ! error ) {
V_23 = V_52 ;
F_1 ( V_23 ) ;
}
return error ;
}
static int F_54 ( void )
{
T_2 V_7 = V_8 ;
F_9 () ;
V_7 = F_38 ( V_52 ) ;
F_42 ( V_52 ) ;
return F_43 ( V_7 ) ? 0 : - V_20 ;
}
static void F_55 ( void )
{
F_56 () ;
F_42 ( V_52 ) ;
if ( V_53 && V_54 != V_53 -> V_55 ) {
F_4 ( V_56 L_7
L_8 ) ;
F_57 ( L_9 ) ;
}
F_47 () ;
F_46 () ;
}
static void F_58 ( void )
{
F_26 () ;
F_59 () ;
}
static int F_60 ( void )
{
int error ;
F_1 ( V_52 ) ;
error = F_6 ( V_52 ) ;
if ( ! error ) {
if ( ! V_21 )
error = F_35 () ;
if ( ! error )
V_23 = V_52 ;
}
return error ;
}
int F_61 ( T_1 V_1 )
{
T_4 V_57 [] = {
[ 1 ] = V_47 ,
[ 3 ] = V_48 ,
[ 5 ] = V_58
} ;
if ( V_1 < 6 && V_57 [ V_1 ] )
return F_62 ( V_57 [ V_1 ] ) ;
if ( V_1 == 4 )
return F_63 () ;
return - V_59 ;
}
int F_64 ( struct V_25 * V_26 , int * V_60 , int V_61 )
{
T_6 V_62 = F_65 ( V_26 ) ;
struct V_28 * V_63 ;
char V_64 [] = L_10 ;
unsigned long long V_65 , V_66 ;
if ( V_61 < V_67 || V_61 > V_68 )
return - V_59 ;
if ( ! V_62 || F_3 ( F_66 ( V_62 , & V_63 ) ) ) {
F_4 ( V_69 L_11 ) ;
return - V_70 ;
}
V_64 [ 2 ] = '0' + V_23 ;
V_65 = V_67 ;
V_66 = V_68 ;
if ( V_23 > V_24 )
F_67 ( V_62 , V_64 , NULL , & V_65 ) ;
if ( V_23 == V_24 ||
( F_68 ( V_26 ) && V_63 -> V_71 . V_72 . V_73 &&
V_63 -> V_71 . V_74 >= V_23 ) ) {
T_2 V_7 ;
V_64 [ 3 ] = 'W' ;
V_7 = F_67 ( V_62 , V_64 , NULL ,
& V_66 ) ;
if ( F_3 ( V_7 ) ) {
if ( V_23 != V_24 ||
V_7 != V_10 )
V_66 = V_65 ;
} else if ( V_66 < V_65 ) {
F_4 ( V_75 L_12 ,
V_64 ) ;
V_65 = V_66 ;
}
}
if ( V_61 < V_65 )
return - V_59 ;
if ( V_60 )
* V_60 = V_65 ;
if ( V_66 > V_61 ) {
for ( V_66 = V_61 ; V_66 > V_65 ; V_66 -- ) {
if ( V_63 -> V_76 . V_57 [ V_66 ] . V_72 . V_73 )
break;
}
}
return V_66 ;
}
int F_69 ( struct V_25 * V_77 , bool V_78 )
{
struct V_28 * V_26 ;
T_6 V_62 ;
if ( ! F_70 ( V_77 ) )
return - V_59 ;
V_62 = F_65 ( V_77 ) ;
if ( ! V_62 || F_3 ( F_66 ( V_62 , & V_26 ) ) ) {
F_71 ( V_77 , L_13 ,
V_79 ) ;
return - V_70 ;
}
if ( V_78 ) {
F_72 ( V_26 , V_24 ) ;
F_73 ( V_26 -> V_71 . V_80 , V_26 -> V_71 . V_81 ) ;
} else {
F_74 ( V_26 -> V_71 . V_80 , V_26 -> V_71 . V_81 ) ;
F_75 ( V_26 ) ;
}
return 0 ;
}
int F_76 ( struct V_25 * V_26 , bool V_78 )
{
T_6 V_62 ;
struct V_28 * V_63 ;
int error ;
if ( ! F_77 ( V_26 ) )
return - V_59 ;
V_62 = F_65 ( V_26 ) ;
if ( ! V_62 || F_3 ( F_66 ( V_62 , & V_63 ) ) ) {
F_71 ( V_26 , L_13 , V_79 ) ;
return - V_70 ;
}
error = V_78 ?
F_72 ( V_63 , V_23 ) :
F_75 ( V_63 ) ;
if ( ! error )
F_78 ( V_26 , L_14 ,
V_78 ? L_15 : L_16 ) ;
return error ;
}
static void F_79 ( void )
{
F_6 ( V_16 ) ;
F_15 () ;
}
static void F_80 ( void )
{
F_4 ( V_69 L_17 , V_79 ) ;
F_81 () ;
F_38 ( V_16 ) ;
}
int T_3 F_82 ( void )
{
T_2 V_7 ;
T_7 V_82 , V_83 ;
#ifdef F_83
int V_84 = 0 ;
F_84 ( V_85 ) ;
#endif
if ( V_86 )
return 0 ;
V_37 [ V_24 ] = 1 ;
F_4 (KERN_INFO PREFIX L_18 ) ;
#ifdef F_83
for ( V_84 = V_40 ; V_84 < V_52 ; V_84 ++ ) {
V_7 = F_85 ( V_84 , & V_82 , & V_83 ) ;
if ( F_43 ( V_7 ) ) {
V_37 [ V_84 ] = 1 ;
F_4 ( V_87 L_19 , V_84 ) ;
}
}
F_86 ( V_22 ?
& V_88 : & V_89 ) ;
#endif
#ifdef F_87
V_7 = F_85 ( V_52 , & V_82 , & V_83 ) ;
if ( F_43 ( V_7 ) ) {
F_88 ( V_22 ?
& V_90 : & V_91 ) ;
V_37 [ V_52 ] = 1 ;
F_4 ( V_87 L_20 ) ;
if ( ! V_51 ) {
F_89 ( V_92 , 1 ,
(struct V_93 * * ) & V_53 ) ;
if ( V_53 )
V_54 =
V_53 -> V_55 ;
}
}
#endif
V_7 = F_85 ( V_16 , & V_82 , & V_83 ) ;
if ( F_43 ( V_7 ) ) {
V_37 [ V_16 ] = 1 ;
F_4 ( V_87 L_21 ) ;
V_94 = F_79 ;
V_95 = F_80 ;
}
F_4 ( V_87 L_22 ) ;
F_90 ( & V_96 ) ;
return 0 ;
}
