static int F_1 ( const char * V_1 , struct V_2 * V_3 )
{
int V_4 = F_2 ( V_1 , V_3 ) ;
if ( V_4 )
return V_4 ;
if ( V_3 -> V_5 == ( const char * ) & V_6 ) {
if ( V_6 )
V_7 |= V_8 ;
else
V_7 &= ~ V_8 ;
}
if ( V_3 -> V_5 == ( const char * ) & V_9 ) {
if ( V_9 )
V_7 |= V_10 ;
else
V_7 &= ~ V_10 ;
}
return V_4 ;
}
static void F_3 ( T_1 V_11 )
{
union V_12 V_13 = { V_14 } ;
struct V_15 V_16 = { 1 , & V_13 } ;
T_2 V_17 = V_18 ;
V_13 . integer . V_19 = V_11 ;
V_17 = F_4 ( NULL , L_1 , & V_16 , NULL ) ;
if ( F_5 ( V_17 ) && V_17 != V_20 ) {
F_6 ( V_21 L_2 ) ;
}
}
static int F_7 ( struct V_22 * V_23 ,
unsigned long V_24 , void * V_25 )
{
F_3 ( V_26 ) ;
return V_27 ;
}
static int F_8 ( T_1 V_11 )
{
#ifdef F_9
if ( V_11 == V_28 ) {
if ( ! V_29 ) {
return - V_30 ;
}
F_10 (
( V_31 ) V_29 ) ;
}
F_11 () ;
#endif
F_6 (KERN_INFO PREFIX L_3 ,
acpi_state) ;
F_12 ( V_11 ) ;
F_13 ( V_11 ) ;
return 0 ;
}
void T_3 F_14 ( void )
{
V_32 = true ;
}
void T_3 F_15 ( void )
{
V_33 = true ;
}
static int F_16 ( void )
{
F_17 () ;
F_18 ( NULL ) ;
F_19 () ;
return 0 ;
}
static int F_20 ( void )
{
F_16 () ;
return F_21 () ;
}
static int F_22 ( void )
{
int error = F_8 ( V_34 ) ;
if ( error )
V_34 = V_35 ;
return error ;
}
static int F_23 ( void )
{
int error = F_22 () ;
if ( ! error )
error = F_20 () ;
return error ;
}
static void F_24 ( void )
{
T_1 V_11 = V_34 ;
F_25 () ;
F_26 () ;
if ( V_11 == V_35 )
return;
F_6 (KERN_INFO PREFIX L_4 ,
acpi_state) ;
F_27 ( V_11 ) ;
F_28 ( V_11 ) ;
F_10 ( ( V_31 ) 0 ) ;
V_34 = V_35 ;
}
static void F_29 ( void )
{
V_34 = V_35 ;
F_3 ( V_34 ) ;
}
static int F_30 ( T_4 V_36 )
{
T_1 V_11 = V_37 [ V_36 ] ;
int error = 0 ;
error = V_32 ? 0 : F_31 () ;
if ( error )
return error ;
if ( V_38 [ V_11 ] ) {
V_34 = V_11 ;
F_3 ( V_34 ) ;
} else {
F_6 ( V_39 L_5 ,
V_36 ) ;
error = - V_40 ;
}
return error ;
}
static int F_32 ( T_4 V_36 )
{
T_2 V_17 = V_18 ;
T_1 V_11 = V_34 ;
int error ;
F_11 () ;
switch ( V_11 ) {
case V_41 :
F_33 () ;
V_17 = F_34 ( V_11 , V_7 ) ;
break;
case V_28 :
error = F_35 () ;
if ( error )
return error ;
F_36 ( V_42 L_6 ) ;
break;
}
F_37 ( V_43 , 1 ) ;
F_38 ( V_11 , V_7 ) ;
if ( F_39 ( V_17 ) && ( V_11 == V_28 ) )
F_40 ( V_44 ) ;
F_17 () ;
F_41 () ;
F_42 () ;
return F_39 ( V_17 ) ? 0 : - V_30 ;
}
static int F_43 ( T_4 V_36 )
{
T_1 V_11 ;
switch ( V_36 ) {
case V_45 :
case V_46 :
case V_47 :
V_11 = V_37 [ V_36 ] ;
return V_38 [ V_11 ] ;
default:
return 0 ;
}
}
static int F_44 ( T_4 V_36 )
{
int error = F_30 ( V_36 ) ;
if ( ! error )
error = F_22 () ;
return error ;
}
static int T_3 F_45 ( const struct V_48 * V_49 )
{
V_33 = true ;
return 0 ;
}
static int T_3 F_46 ( const struct V_48 * V_49 )
{
F_14 () ;
return 0 ;
}
void T_3 F_47 ( void )
{
V_50 = true ;
}
static int F_48 ( void )
{
int error ;
error = V_32 ? 0 : F_31 () ;
if ( ! error ) {
V_34 = V_51 ;
F_3 ( V_34 ) ;
}
return error ;
}
static int F_49 ( void )
{
T_2 V_17 = V_18 ;
F_11 () ;
V_17 = F_34 ( V_51 , V_7 ) ;
F_38 ( V_51 , V_7 ) ;
return F_39 ( V_17 ) ? 0 : - V_30 ;
}
static void F_50 ( void )
{
F_51 () ;
F_38 ( V_51 , V_7 ) ;
if ( V_52 && V_53 != V_52 -> V_54 ) {
F_6 ( V_55 L_7
L_8 ) ;
F_52 ( L_9 ) ;
}
F_42 () ;
F_41 () ;
}
static void F_53 ( void )
{
F_25 () ;
F_54 () ;
}
static int F_55 ( void )
{
int error ;
F_3 ( V_51 ) ;
error = F_8 ( V_51 ) ;
if ( ! error ) {
if ( ! V_32 )
error = F_31 () ;
if ( ! error )
V_34 = V_51 ;
}
return error ;
}
int F_56 ( T_1 V_11 )
{
T_4 V_56 [] = {
[ 1 ] = V_46 ,
[ 3 ] = V_47 ,
[ 5 ] = V_57
} ;
if ( V_11 < 6 && V_56 [ V_11 ] )
return F_57 ( V_56 [ V_11 ] ) ;
if ( V_11 == 4 )
return F_58 () ;
return - V_58 ;
}
int F_59 ( struct V_59 * V_60 , int * V_61 )
{
T_5 V_62 = F_60 ( V_60 ) ;
struct V_63 * V_64 ;
char V_65 [] = L_10 ;
unsigned long long V_66 , V_67 ;
if ( ! V_62 || F_5 ( F_61 ( V_62 , & V_64 ) ) ) {
F_6 ( V_68 L_11 ) ;
return - V_69 ;
}
V_65 [ 2 ] = '0' + V_34 ;
V_66 = V_70 ;
V_67 = V_71 ;
if ( V_34 > V_35 )
F_62 ( V_62 , V_65 , NULL , & V_66 ) ;
if ( V_34 == V_35 ||
( F_63 ( V_60 ) &&
V_64 -> V_72 . V_73 <= V_34 ) ) {
T_2 V_17 ;
V_65 [ 3 ] = 'W' ;
V_17 = F_62 ( V_62 , V_65 , NULL ,
& V_67 ) ;
if ( F_5 ( V_17 ) ) {
if ( V_34 != V_35 ||
V_17 != V_20 )
V_67 = V_66 ;
} else if ( V_67 < V_66 ) {
F_6 ( V_74 L_12 ,
V_65 ) ;
V_66 = V_67 ;
}
}
if ( V_61 )
* V_61 = V_66 ;
return V_67 ;
}
int F_64 ( struct V_59 * V_75 , bool V_76 )
{
struct V_63 * V_60 ;
T_5 V_62 ;
if ( ! F_65 ( V_75 ) )
return - V_58 ;
V_62 = F_60 ( V_75 ) ;
if ( ! V_62 || F_5 ( F_61 ( V_62 , & V_60 ) ) ) {
F_66 ( V_75 , L_13 ,
V_77 ) ;
return - V_69 ;
}
if ( V_76 ) {
F_67 ( V_60 , V_35 ) ;
F_68 ( V_60 -> V_72 . V_78 , V_60 -> V_72 . V_79 ) ;
} else {
F_69 ( V_60 -> V_72 . V_78 , V_60 -> V_72 . V_79 ) ;
F_70 ( V_60 ) ;
}
return 0 ;
}
int F_71 ( struct V_59 * V_60 , bool V_76 )
{
T_5 V_62 ;
struct V_63 * V_64 ;
int error ;
if ( ! F_72 ( V_60 ) )
return - V_58 ;
V_62 = F_60 ( V_60 ) ;
if ( ! V_62 || F_5 ( F_61 ( V_62 , & V_64 ) ) ) {
F_66 ( V_60 , L_13 , V_77 ) ;
return - V_69 ;
}
error = V_76 ?
F_67 ( V_64 , V_34 ) :
F_70 ( V_64 ) ;
if ( ! error )
F_73 ( V_60 , L_14 ,
V_76 ? L_15 : L_16 ) ;
return error ;
}
static void F_74 ( void )
{
F_8 ( V_26 ) ;
F_17 () ;
}
static void F_75 ( void )
{
F_6 ( V_68 L_17 , V_77 ) ;
F_76 () ;
F_34 ( V_26 , V_7 ) ;
}
static void T_3 F_77 ( void )
{
T_5 V_80 ;
if ( F_39 ( F_78 ( V_81 , V_82 , & V_80 ) ) )
{
F_6 (KERN_NOTICE PREFIX L_18 ) ;
F_6 (KERN_NOTICE PREFIX L_19
L_20 ) ;
}
if ( F_39 ( F_78 ( V_81 , V_83 , & V_80 ) ) )
{
F_6 (KERN_NOTICE PREFIX L_21 ) ;
F_6 (KERN_NOTICE PREFIX L_22
L_20 ) ;
}
}
int T_3 F_79 ( void )
{
T_2 V_17 ;
T_6 V_84 , V_85 ;
#ifdef F_80
int V_86 = 0 ;
F_81 ( V_87 ) ;
#endif
if ( V_88 )
return 0 ;
V_38 [ V_35 ] = 1 ;
F_6 (KERN_INFO PREFIX L_23 ) ;
#ifdef F_80
for ( V_86 = V_41 ; V_86 < V_51 ; V_86 ++ ) {
V_17 = F_82 ( V_86 , & V_84 , & V_85 ) ;
if ( F_39 ( V_17 ) ) {
V_38 [ V_86 ] = 1 ;
F_6 ( L_24 , V_86 ) ;
}
}
F_83 ( V_33 ?
& V_89 : & V_90 ) ;
#endif
#ifdef F_84
V_17 = F_82 ( V_51 , & V_84 , & V_85 ) ;
if ( F_39 ( V_17 ) ) {
F_85 ( V_33 ?
& V_91 : & V_92 ) ;
V_38 [ V_51 ] = 1 ;
F_6 ( L_25 ) ;
if ( ! V_50 ) {
F_86 ( V_93 , 1 ,
(struct V_94 * * ) & V_52 ) ;
if ( V_52 )
V_53 =
V_52 -> V_54 ;
}
}
#endif
V_17 = F_82 ( V_26 , & V_84 , & V_85 ) ;
if ( F_39 ( V_17 ) ) {
V_38 [ V_26 ] = 1 ;
F_6 ( L_26 ) ;
V_95 = F_74 ;
V_96 = F_75 ;
}
F_6 ( L_27 ) ;
F_87 ( & V_97 ) ;
F_77 () ;
return 0 ;
}
