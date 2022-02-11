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
F_49 () ;
V_22 = V_31 ;
F_1 ( V_22 ) ;
}
static inline void F_22 ( void ) {}
static int F_50 ( T_5 V_41 )
{
T_1 V_1 = V_42 [ V_41 ] ;
int error ;
error = ( V_23 || V_24 ) ? 0 : F_51 () ;
if ( error )
return error ;
if ( ! V_43 [ V_1 ] ) {
F_52 ( L_5 , V_1 ) ;
return - V_44 ;
}
if ( V_1 > V_45 )
F_53 () ;
F_45 ( V_1 ) ;
return 0 ;
}
static int F_54 ( T_5 V_41 )
{
T_2 V_2 = V_46 ;
T_1 V_1 = V_22 ;
int error ;
F_9 () ;
F_55 ( F_56 ( L_6 ) , V_1 , true ) ;
switch ( V_1 ) {
case V_45 :
F_57 () ;
V_2 = F_58 ( V_1 ) ;
break;
case V_11 :
if ( ! V_47 )
return - V_44 ;
error = V_47 () ;
if ( error )
return error ;
F_59 ( V_48 L_7 ) ;
F_60 () ;
break;
}
F_55 ( F_56 ( L_6 ) , V_1 , false ) ;
F_61 ( V_49 , 1 ) ;
F_62 ( V_1 ) ;
if ( F_14 ( V_2 ) && ( V_1 == V_11 ) ) {
T_6 V_50 = V_51 ;
F_63 ( V_52 , & V_50 ) ;
if ( V_50 & V_53 ) {
F_64 ( V_52 ) ;
V_39 = true ;
}
}
F_26 () ;
F_37 () ;
F_65 () ;
return F_14 ( V_2 ) ? 0 : - V_13 ;
}
static int F_66 ( T_5 V_41 )
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
static int F_67 ( T_5 V_41 )
{
int error = F_50 ( V_41 ) ;
if ( ! error )
error = F_31 () ;
return error ;
}
static void F_68 ( unsigned int V_57 )
{
union V_58 * V_59 ;
if ( ! ( V_60 & ( 1 << V_57 ) ) )
return;
V_59 = F_69 ( V_61 , & V_62 , 1 , V_57 , NULL ) ;
F_70 ( V_59 ) ;
F_71 ( V_61 , L_8 ,
V_57 , V_59 ? L_9 : L_10 ) ;
}
static int F_72 ( struct V_35 * V_63 ,
const struct V_64 * V_65 )
{
union V_58 * V_59 ;
if ( V_61 )
return 0 ;
if ( ! ( V_18 . V_66 & V_67 ) )
return 0 ;
F_73 ( V_68 , & V_62 ) ;
V_59 = F_69 ( V_63 -> V_69 , & V_62 , 1 , 0 , NULL ) ;
if ( V_59 && V_59 -> type == V_70 ) {
char V_71 = * ( char * ) V_59 -> V_72 . V_73 ;
if ( ( V_71 & V_74 ) == V_74 ) {
V_60 = V_71 ;
V_61 = V_63 -> V_69 ;
}
F_71 ( V_63 -> V_69 , L_11 ,
V_71 ) ;
} else {
F_71 ( V_63 -> V_69 ,
L_12 ) ;
}
F_70 ( V_59 ) ;
return 0 ;
}
static int F_74 ( void )
{
F_46 () ;
V_75 = true ;
return 0 ;
}
static int F_75 ( void )
{
if ( V_61 ) {
F_68 ( V_76 ) ;
F_68 ( V_77 ) ;
} else {
F_76 () ;
F_27 () ;
}
if ( F_77 () )
F_78 ( V_78 ) ;
return 0 ;
}
static void F_79 ( void )
{
if ( F_77 () &&
! F_80 ( F_81 ( V_78 ) ) ) {
F_82 () ;
V_79 = true ;
}
}
static void F_83 ( void )
{
F_84 () ;
F_27 () ;
V_79 = false ;
}
static void F_85 ( void )
{
if ( F_77 () )
F_86 ( V_78 ) ;
if ( V_61 ) {
F_68 ( V_80 ) ;
F_68 ( V_81 ) ;
} else {
F_87 () ;
}
}
static void F_88 ( void )
{
V_75 = false ;
F_49 () ;
}
static void F_89 ( void )
{
int V_82 ;
for ( V_82 = V_45 ; V_82 < V_83 ; V_82 ++ )
if ( F_12 ( V_82 ) )
V_43 [ V_82 ] = 1 ;
F_90 ( V_27 ?
& V_84 : & V_85 ) ;
F_91 ( & V_86 ) ;
F_92 ( & V_87 ) ;
}
static inline void F_89 ( void ) {}
bool F_93 ( void )
{
return V_79 ;
}
bool F_94 ( void )
{
return ! V_75 || ! V_61 ;
}
static int F_95 ( void )
{
F_96 ( V_88 , & V_89 ) ;
return 0 ;
}
static void F_97 ( void )
{
T_1 V_90 = 0 ;
F_96 ( V_88 , & V_90 ) ;
if ( V_90 == V_89 )
return;
F_61 ( V_88 , V_89 ) ;
}
void F_98 ( void )
{
F_99 ( & V_91 ) ;
}
static inline void F_98 ( void ) {}
void T_4 F_100 ( void )
{
V_92 = true ;
}
static int F_101 ( void )
{
int error ;
error = V_23 ? 0 : F_51 () ;
if ( ! error )
F_45 ( V_83 ) ;
return error ;
}
static int F_102 ( void )
{
T_2 V_2 = V_46 ;
F_9 () ;
V_2 = F_58 ( V_83 ) ;
F_62 ( V_83 ) ;
return F_14 ( V_2 ) ? 0 : - V_13 ;
}
static void F_103 ( void )
{
F_60 () ;
F_104 () ;
F_62 ( V_83 ) ;
if ( V_93 && V_94 != V_93 -> V_95 )
F_105 ( L_13 ) ;
F_65 () ;
F_37 () ;
}
static void F_106 ( void )
{
F_37 () ;
F_87 () ;
}
static int F_107 ( void )
{
int error ;
F_1 ( V_83 ) ;
error = F_6 ( V_83 ) ;
if ( ! error ) {
if ( ! V_23 )
error = F_51 () ;
if ( ! error ) {
V_22 = V_83 ;
F_46 () ;
}
}
return error ;
}
static void F_108 ( void )
{
if ( ! F_12 ( V_83 ) )
return;
F_109 ( V_27 ?
& V_96 : & V_97 ) ;
V_43 [ V_83 ] = 1 ;
if ( V_92 )
return;
F_110 ( V_98 , 1 , (struct V_99 * * ) & V_93 ) ;
if ( V_93 )
V_94 = V_93 -> V_95 ;
}
static inline void F_108 ( void ) {}
static void F_111 ( void )
{
F_6 ( V_9 ) ;
F_26 () ;
F_27 () ;
}
static void F_112 ( void )
{
F_4 ( V_100 L_14 , V_101 ) ;
F_113 () ;
F_58 ( V_9 ) ;
}
int T_4 F_114 ( void )
{
char V_102 [ V_103 * 3 + 1 ] ;
char * V_104 = V_102 ;
int V_82 ;
F_22 () ;
V_43 [ V_31 ] = 1 ;
F_98 () ;
F_89 () ;
F_108 () ;
if ( F_12 ( V_9 ) ) {
V_43 [ V_9 ] = 1 ;
V_105 = F_111 ;
V_106 = F_112 ;
} else {
V_107 = true ;
}
V_102 [ 0 ] = 0 ;
for ( V_82 = 0 ; V_82 < V_103 ; V_82 ++ ) {
if ( V_43 [ V_82 ] )
V_104 += sprintf ( V_104 , L_15 , V_82 ) ;
}
F_59 ( V_48 L_16 , V_102 ) ;
F_115 ( & V_108 ) ;
return 0 ;
}
