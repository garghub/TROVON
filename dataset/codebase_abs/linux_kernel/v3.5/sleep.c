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
if ( ! V_29 )
return - V_30 ;
F_10 ( V_29 ) ;
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
V_31 = true ;
}
void T_3 F_15 ( void )
{
V_32 = true ;
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
int error = F_8 ( V_33 ) ;
if ( error )
V_33 = V_34 ;
return error ;
}
static int F_23 ( void )
{
int error = F_22 () ;
if ( ! error )
error = F_20 () ;
return error ;
}
static int F_24 ( struct V_35 * V_36 , void * V_37 )
{
struct V_38 * V_35 = F_25 ( V_36 ) ;
const char * V_39 = F_26 ( V_35 ) ;
return ! strcmp ( V_39 , V_40 ) ;
}
static void F_27 ( void )
{
struct V_35 * V_41 ;
T_1 V_11 = V_33 ;
F_28 () ;
F_29 () ;
if ( V_11 == V_34 )
return;
F_6 (KERN_INFO PREFIX L_4 ,
acpi_state) ;
F_30 ( V_11 ) ;
F_31 ( V_11 ) ;
F_10 ( ( V_42 ) 0 ) ;
V_33 = V_34 ;
if ( ! V_43 )
return;
V_43 = false ;
V_41 = F_32 ( & V_44 , NULL , NULL ,
F_24 ) ;
if ( V_41 ) {
F_33 ( V_41 , 0 ) ;
F_34 ( V_41 ) ;
}
}
static void F_35 ( void )
{
V_33 = V_34 ;
F_3 ( V_33 ) ;
}
static int F_36 ( T_4 V_45 )
{
T_1 V_11 = V_46 [ V_45 ] ;
int error = 0 ;
error = V_31 ? 0 : F_37 () ;
if ( error )
return error ;
if ( V_47 [ V_11 ] ) {
V_33 = V_11 ;
F_3 ( V_33 ) ;
} else {
F_6 ( V_48 L_5 ,
V_45 ) ;
error = - V_49 ;
}
return error ;
}
static int F_38 ( T_4 V_45 )
{
T_2 V_17 = V_18 ;
T_1 V_11 = V_33 ;
int error ;
F_11 () ;
switch ( V_11 ) {
case V_50 :
F_39 () ;
V_17 = F_40 ( V_11 , V_7 ) ;
break;
case V_28 :
error = F_41 () ;
if ( error )
return error ;
F_42 ( V_51 L_6 ) ;
break;
}
F_43 ( V_52 , 1 ) ;
F_44 ( V_11 , V_7 ) ;
if ( F_45 ( V_17 ) && ( V_11 == V_28 ) ) {
T_5 V_53 ;
F_46 ( V_54 , & V_53 ) ;
if ( V_53 & V_55 ) {
F_47 ( V_54 ) ;
V_43 = true ;
}
}
F_17 () ;
F_48 () ;
F_49 () ;
return F_45 ( V_17 ) ? 0 : - V_30 ;
}
static int F_50 ( T_4 V_45 )
{
T_1 V_11 ;
switch ( V_45 ) {
case V_56 :
case V_57 :
case V_58 :
V_11 = V_46 [ V_45 ] ;
return V_47 [ V_11 ] ;
default:
return 0 ;
}
}
static int F_51 ( T_4 V_45 )
{
int error = F_36 ( V_45 ) ;
if ( ! error )
error = F_22 () ;
return error ;
}
static int T_3 F_52 ( const struct V_59 * V_60 )
{
V_32 = true ;
return 0 ;
}
static int T_3 F_53 ( const struct V_59 * V_60 )
{
F_14 () ;
return 0 ;
}
void T_3 F_54 ( void )
{
V_61 = true ;
}
static int F_55 ( void )
{
int error ;
error = V_31 ? 0 : F_37 () ;
if ( ! error ) {
V_33 = V_62 ;
F_3 ( V_33 ) ;
}
return error ;
}
static int F_56 ( void )
{
T_2 V_17 = V_18 ;
F_11 () ;
V_17 = F_40 ( V_62 , V_7 ) ;
F_44 ( V_62 , V_7 ) ;
return F_45 ( V_17 ) ? 0 : - V_30 ;
}
static void F_57 ( void )
{
F_58 () ;
F_44 ( V_62 , V_7 ) ;
if ( V_63 && V_64 != V_63 -> V_65 ) {
F_6 ( V_66 L_7
L_8 ) ;
F_59 ( L_9 ) ;
}
F_49 () ;
F_48 () ;
}
static void F_60 ( void )
{
F_28 () ;
F_61 () ;
}
static int F_62 ( void )
{
int error ;
F_3 ( V_62 ) ;
error = F_8 ( V_62 ) ;
if ( ! error ) {
if ( ! V_31 )
error = F_37 () ;
if ( ! error )
V_33 = V_62 ;
}
return error ;
}
int F_63 ( T_1 V_11 )
{
T_4 V_67 [] = {
[ 1 ] = V_57 ,
[ 3 ] = V_58 ,
[ 5 ] = V_68
} ;
if ( V_11 < 6 && V_67 [ V_11 ] )
return F_64 ( V_67 [ V_11 ] ) ;
if ( V_11 == 4 )
return F_65 () ;
return - V_69 ;
}
int F_66 ( struct V_35 * V_36 , int * V_70 )
{
T_6 V_71 = F_67 ( V_36 ) ;
struct V_38 * V_72 ;
char V_73 [] = L_10 ;
unsigned long long V_74 , V_75 ;
if ( ! V_71 || F_5 ( F_68 ( V_71 , & V_72 ) ) ) {
F_6 ( V_76 L_11 ) ;
return - V_77 ;
}
V_73 [ 2 ] = '0' + V_33 ;
V_74 = V_78 ;
V_75 = V_79 ;
if ( V_33 > V_34 )
F_69 ( V_71 , V_73 , NULL , & V_74 ) ;
if ( V_33 == V_34 ||
( F_70 ( V_36 ) && V_72 -> V_80 . V_81 . V_82 &&
V_72 -> V_80 . V_83 >= V_33 ) ) {
T_2 V_17 ;
V_73 [ 3 ] = 'W' ;
V_17 = F_69 ( V_71 , V_73 , NULL ,
& V_75 ) ;
if ( F_5 ( V_17 ) ) {
if ( V_33 != V_34 ||
V_17 != V_20 )
V_75 = V_74 ;
} else if ( V_75 < V_74 ) {
F_6 ( V_84 L_12 ,
V_73 ) ;
V_74 = V_75 ;
}
}
if ( V_70 )
* V_70 = V_74 ;
return V_75 ;
}
int F_71 ( struct V_35 * V_85 , bool V_86 )
{
struct V_38 * V_36 ;
T_6 V_71 ;
if ( ! F_72 ( V_85 ) )
return - V_69 ;
V_71 = F_67 ( V_85 ) ;
if ( ! V_71 || F_5 ( F_68 ( V_71 , & V_36 ) ) ) {
F_73 ( V_85 , L_13 ,
V_87 ) ;
return - V_77 ;
}
if ( V_86 ) {
F_74 ( V_36 , V_34 ) ;
F_75 ( V_36 -> V_80 . V_88 , V_36 -> V_80 . V_89 ) ;
} else {
F_76 ( V_36 -> V_80 . V_88 , V_36 -> V_80 . V_89 ) ;
F_77 ( V_36 ) ;
}
return 0 ;
}
int F_78 ( struct V_35 * V_36 , bool V_86 )
{
T_6 V_71 ;
struct V_38 * V_72 ;
int error ;
if ( ! F_79 ( V_36 ) )
return - V_69 ;
V_71 = F_67 ( V_36 ) ;
if ( ! V_71 || F_5 ( F_68 ( V_71 , & V_72 ) ) ) {
F_73 ( V_36 , L_13 , V_87 ) ;
return - V_77 ;
}
error = V_86 ?
F_74 ( V_72 , V_33 ) :
F_77 ( V_72 ) ;
if ( ! error )
F_80 ( V_36 , L_14 ,
V_86 ? L_15 : L_16 ) ;
return error ;
}
static void F_81 ( void )
{
F_8 ( V_26 ) ;
F_17 () ;
}
static void F_82 ( void )
{
F_6 ( V_76 L_17 , V_87 ) ;
F_83 () ;
F_40 ( V_26 , V_7 ) ;
}
static void T_3 F_84 ( void )
{
T_6 V_90 ;
if ( F_45 ( F_85 ( V_91 , V_92 , & V_90 ) ) )
{
F_6 (KERN_NOTICE PREFIX L_18 ) ;
F_6 (KERN_NOTICE PREFIX L_19
L_20 ) ;
}
if ( F_45 ( F_85 ( V_91 , V_93 , & V_90 ) ) )
{
F_6 (KERN_NOTICE PREFIX L_21 ) ;
F_6 (KERN_NOTICE PREFIX L_22
L_20 ) ;
}
}
int T_3 F_86 ( void )
{
T_2 V_17 ;
T_7 V_94 , V_95 ;
#ifdef F_87
int V_96 = 0 ;
F_88 ( V_97 ) ;
#endif
if ( V_98 )
return 0 ;
V_47 [ V_34 ] = 1 ;
F_6 (KERN_INFO PREFIX L_23 ) ;
#ifdef F_87
for ( V_96 = V_50 ; V_96 < V_62 ; V_96 ++ ) {
V_17 = F_89 ( V_96 , & V_94 , & V_95 ) ;
if ( F_45 ( V_17 ) ) {
V_47 [ V_96 ] = 1 ;
F_6 ( V_99 L_24 , V_96 ) ;
}
}
F_90 ( V_32 ?
& V_100 : & V_101 ) ;
#endif
#ifdef F_91
V_17 = F_89 ( V_62 , & V_94 , & V_95 ) ;
if ( F_45 ( V_17 ) ) {
F_92 ( V_32 ?
& V_102 : & V_103 ) ;
V_47 [ V_62 ] = 1 ;
F_6 ( V_99 L_25 ) ;
if ( ! V_61 ) {
F_93 ( V_104 , 1 ,
(struct V_105 * * ) & V_63 ) ;
if ( V_63 )
V_64 =
V_63 -> V_65 ;
}
}
#endif
V_17 = F_89 ( V_26 , & V_94 , & V_95 ) ;
if ( F_45 ( V_17 ) ) {
V_47 [ V_26 ] = 1 ;
F_6 ( V_99 L_26 ) ;
V_106 = F_81 ;
V_107 = F_82 ;
}
F_6 ( V_99 L_27 ) ;
F_94 ( & V_108 ) ;
F_84 () ;
return 0 ;
}
