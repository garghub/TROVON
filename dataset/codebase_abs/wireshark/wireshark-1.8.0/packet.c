void
F_1 ( void )
{
V_1 = F_2 ( L_1 ) ;
V_2 = F_2 ( L_2 ) ;
V_3 = F_3 ( L_3 ) ;
}
void
F_4 ( void )
{
}
void
F_5 ( T_1 * V_4 , const T_2 V_5 )
{
if ( V_5 < F_6 ( V_4 ) ) {
F_7 ( V_4 , V_5 ) ;
}
}
void
F_8 ( void (* F_9)( void ) )
{
V_6 = F_10 ( V_6 , ( V_7 ) F_9 ) ;
}
static void
F_11 ( V_7 V_8 , V_7 T_3 V_9 )
{
T_4 F_9 = ( T_4 ) V_8 ;
(* F_9)() ;
}
void
F_12 ( void )
{
F_13 () ;
F_14 () ;
F_15 () ;
F_16 ( V_6 , & F_11 , NULL ) ;
F_17 () ;
F_18 () ;
}
void
F_19 ( void )
{
F_20 () ;
F_13 () ;
F_21 () ;
F_16 ( V_6 , & F_11 , NULL ) ;
F_22 () ;
F_23 () ;
}
void
F_24 ( T_4 F_9 )
{
V_10 = F_10 ( V_10 ,
( V_7 ) F_9 ) ;
}
static void
F_25 ( V_7 V_8 , V_7 T_3 V_9 )
{
T_4 F_9 = ( T_4 ) V_8 ;
(* F_9)() ;
}
void
F_26 ( void )
{
F_16 ( V_10 ,
& F_25 , NULL ) ;
}
void
F_27 ( T_5 * V_11 , T_1 * V_4 , const char * V_12 )
{
T_6 * V_13 ;
V_13 = F_28 ( sizeof ( T_6 ) ) ;
V_13 -> V_4 = V_4 ;
V_13 -> V_14 = FALSE ;
V_13 -> V_12 = V_12 ;
V_11 -> V_15 = F_10 ( V_11 -> V_15 , V_13 ) ;
}
const char *
F_29 ( T_6 * V_13 )
{
if ( ! V_13 -> V_14 ) {
V_13 -> V_12 = F_30 ( L_4 , V_13 -> V_12 , F_31 ( V_13 -> V_4 ) ) ;
V_13 -> V_14 = TRUE ;
}
return V_13 -> V_12 ;
}
void
F_32 ( T_5 * V_11 )
{
if ( V_11 -> V_15 ) {
F_33 ( V_11 -> V_15 ) ;
V_11 -> V_15 = NULL ;
}
}
void
F_34 ( T_5 * V_11 , T_7 V_16 )
{
if ( V_16 != F_35 ( V_11 ) ) {
V_11 -> V_17 = F_36 ( V_11 -> V_17 , F_37 ( V_16 ) ) ;
}
}
void
F_38 ( void (* F_9)( void ) )
{
V_18 = F_10 ( V_18 ,
( V_7 ) F_9 ) ;
}
static void
F_39 ( V_7 V_8 , V_7 T_3 V_9 )
{
T_4 F_9 = ( T_4 ) V_8 ;
(* F_9)() ;
}
void
F_40 ( void )
{
F_16 ( V_18 ,
& F_39 , NULL ) ;
}
void
F_41 ( T_8 * V_19 , union V_20 * V_21 ,
const T_9 * V_22 , T_10 * V_23 , T_11 * V_24 )
{
if ( V_24 != NULL )
F_42 ( V_24 ) ;
memset ( & V_19 -> V_25 , 0 , sizeof( V_19 -> V_25 ) ) ;
V_19 -> V_25 . V_26 = L_5 ;
V_19 -> V_25 . V_24 = V_24 ;
V_19 -> V_25 . V_23 = V_23 ;
V_19 -> V_25 . V_21 = V_21 ;
V_19 -> V_25 . V_27 . type = V_28 ;
V_19 -> V_25 . V_29 . type = V_28 ;
V_19 -> V_25 . V_30 . type = V_28 ;
V_19 -> V_25 . V_31 . type = V_28 ;
V_19 -> V_25 . V_13 . type = V_28 ;
V_19 -> V_25 . V_32 . type = V_28 ;
V_19 -> V_25 . V_33 = V_34 ;
V_19 -> V_25 . V_35 = L_6 ;
V_19 -> V_25 . V_36 = V_37 ;
V_19 -> V_25 . V_38 = V_39 ;
V_19 -> V_25 . V_40 = - 1 ;
V_19 -> V_25 . V_41 = V_42 ;
V_19 -> V_25 . V_43 = L_6 ;
V_19 -> V_25 . V_44 = V_45 ;
V_19 -> V_4 = NULL ;
V_19 -> V_25 . V_46 = V_47 ;
F_43 ( ( L_7 , V_23 -> V_48 ) ) ;
F_44 {
V_19 -> V_4 = F_45 ( V_22 , V_23 -> V_49 ,
V_23 -> V_50 > V_47 ? V_47 : V_23 -> V_50 ) ;
F_27 ( & V_19 -> V_25 , V_19 -> V_4 , L_8 ) ;
if( V_1 != NULL )
F_46 ( V_1 , V_19 -> V_4 , & V_19 -> V_25 , V_19 -> V_51 ) ;
}
F_47 (BoundsError) {
F_48 () ;
}
F_47 (ReportedBoundsError) {
if( V_3 != - 1 ) {
F_49 ( V_19 -> V_51 , V_3 , V_19 -> V_4 , 0 , 0 ,
L_9 ) ;
} else {
F_48 () ;
}
}
F_47 (OutOfMemoryError) {
V_52 ;
}
V_53 ;
F_43 ( ( L_10 , V_23 -> V_48 ) ) ;
V_23 -> V_54 . V_55 = 1 ;
}
static int
F_50 ( T_12 V_56 , T_1 * V_4 ,
T_5 * V_11 , T_13 * V_51 )
{
const char * V_57 ;
int V_58 ;
V_57 = V_11 -> V_26 ;
if ( V_56 -> V_59 != NULL ) {
V_11 -> V_26 =
F_51 ( V_56 -> V_59 ) ;
}
if ( V_56 -> V_60 ) {
F_43 ( ( L_11 , V_56 -> V_12 ) ) ;
V_58 = (* V_56 -> V_61 . V_62 )( V_4 , V_11 , V_51 ) ;
F_43 ( ( L_12 , V_56 -> V_12 ) ) ;
} else {
F_43 ( ( L_13 , V_56 -> V_12 ) ) ;
(* V_56 -> V_61 . V_63 )( V_4 , V_11 , V_51 ) ;
F_43 ( ( L_14 , V_56 -> V_12 ) ) ;
V_58 = F_31 ( V_4 ) ;
if ( V_58 == 0 ) {
V_58 = 1 ;
}
}
V_11 -> V_26 = V_57 ;
return V_58 ;
}
static int
F_52 ( T_12 V_56 , T_1 * V_4 ,
T_5 * V_64 , T_13 * V_51 , T_14 V_65 )
{
T_5 * V_11 = V_64 ;
const char * V_57 ;
T_15 V_66 ;
int V_58 ;
T_16 V_67 = 0 ;
if ( V_56 -> V_59 != NULL &&
! F_53 ( V_56 -> V_59 ) ) {
return 0 ;
}
V_57 = V_11 -> V_26 ;
V_66 = V_11 -> V_68 ;
if ( V_11 -> V_69 != NULL )
V_67 = ( T_16 ) V_11 -> V_69 -> V_70 ;
V_11 -> V_66 = V_66 ;
V_11 -> V_68 = V_66 - ( V_66 > 0 ) ;
if ( V_56 -> V_59 != NULL ) {
V_11 -> V_26 =
F_51 ( V_56 -> V_59 ) ;
if ( ( V_11 -> V_69 ) && ( V_65 ) ) {
if ( V_11 -> V_69 -> V_70 > 0 )
F_54 ( V_11 -> V_69 , L_15 ) ;
F_54 ( V_11 -> V_69 ,
F_55 ( F_56 ( V_56 -> V_59 ) ) ) ;
}
}
if ( V_11 -> V_54 . V_71 ) {
V_58 = F_57 ( V_56 , V_4 , V_11 , V_51 ) ;
} else {
V_58 = F_50 ( V_56 , V_4 , V_11 , V_51 ) ;
}
if ( V_58 == 0 ) {
if ( ( V_11 -> V_69 != NULL ) && ( V_65 ) ) {
F_58 ( V_11 -> V_69 , V_67 ) ;
}
}
V_11 -> V_26 = V_57 ;
V_11 -> V_68 = V_66 ;
return V_58 ;
}
static int
F_57 ( T_12 V_56 , T_1 * V_4 ,
T_5 * V_64 , T_13 * V_51 )
{
T_5 * V_11 = V_64 ;
const char * V_57 ;
T_15 V_66 ;
volatile int V_58 = 0 ;
T_14 V_72 ;
T_17 V_73 ;
T_17 V_74 ;
T_17 V_75 ;
T_17 V_76 ;
T_17 V_77 ;
T_17 V_78 ;
V_57 = V_11 -> V_26 ;
V_66 = V_11 -> V_68 ;
V_72 = F_59 ( V_11 -> V_24 ) ;
F_60 ( V_11 -> V_24 , FALSE ) ;
V_73 = V_11 -> V_27 ;
V_74 = V_11 -> V_29 ;
V_75 = V_11 -> V_30 ;
V_76 = V_11 -> V_31 ;
V_77 = V_11 -> V_13 ;
V_78 = V_11 -> V_32 ;
F_44 {
V_58 = F_50 ( V_56 , V_4 , V_11 , V_51 ) ;
}
F_47 (BoundsError) {
F_60 ( V_11 -> V_24 , V_72 ) ;
V_11 -> V_27 = V_73 ;
V_11 -> V_29 = V_74 ;
V_11 -> V_30 = V_75 ;
V_11 -> V_31 = V_76 ;
V_11 -> V_13 = V_77 ;
V_11 -> V_32 = V_78 ;
V_11 -> V_26 = V_57 ;
V_11 -> V_68 = V_66 ;
V_52 ;
}
F_47 (ReportedBoundsError) {
V_58 = F_31 ( V_4 ) ;
}
F_47 (OutOfMemoryError) {
V_52 ;
}
V_53 ;
F_60 ( V_11 -> V_24 , V_72 ) ;
V_11 -> V_27 = V_73 ;
V_11 -> V_29 = V_74 ;
V_11 -> V_30 = V_75 ;
V_11 -> V_31 = V_76 ;
V_11 -> V_13 = V_77 ;
V_11 -> V_32 = V_78 ;
V_11 -> V_79 = 0 ;
return V_58 ;
}
T_18
F_61 ( const char * V_12 )
{
F_62 ( V_80 ) ;
return F_63 ( V_80 , V_12 ) ;
}
static T_19 *
F_64 ( T_18 V_81 , const T_7 V_82 )
{
switch ( V_81 -> type ) {
case V_83 :
case V_84 :
case V_85 :
case V_86 :
break;
default:
F_48 () ;
}
return F_63 ( V_81 -> V_87 ,
F_37 ( V_82 ) ) ;
}
void
F_65 ( const char * V_12 , const T_7 V_82 , T_12 V_56 )
{
T_18 V_81 ;
T_19 * V_88 ;
V_81 = F_61 ( V_12 ) ;
if ( V_81 == NULL ) {
fprintf ( V_89 , L_16 ,
V_12 ) ;
fprintf ( V_89 , L_17 ,
F_66 ( V_56 -> V_59 ) ) ;
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
F_62 ( V_56 != NULL ) ;
switch ( V_81 -> type ) {
case V_83 :
case V_84 :
case V_85 :
case V_86 :
break;
default:
F_48 () ;
}
#if 0
dissector_add_uint_sanity_check(name, pattern, handle, sub_dissectors);
#endif
V_88 = F_67 ( sizeof ( T_19 ) ) ;
V_88 -> V_90 = V_56 ;
V_88 -> V_91 = V_88 -> V_90 ;
F_68 ( V_81 -> V_87 ,
F_37 ( V_82 ) , ( V_7 ) V_88 ) ;
F_69 ( V_12 , V_56 ) ;
}
void
F_70 ( const char * V_12 , const T_7 V_82 ,
T_12 V_56 V_9 )
{
T_18 V_81 = F_61 ( V_12 ) ;
T_19 * V_88 ;
F_62 ( V_81 ) ;
V_88 = F_64 ( V_81 , V_82 ) ;
if ( V_88 != NULL ) {
F_71 ( V_81 -> V_87 ,
F_37 ( V_82 ) ) ;
F_72 ( V_88 ) ;
}
}
void
F_73 ( const char * V_12 , const T_7 V_82 , T_12 V_56 )
{
T_18 V_81 = F_61 ( V_12 ) ;
T_19 * V_88 ;
F_62 ( V_81 ) ;
V_88 = F_64 ( V_81 , V_82 ) ;
if ( V_88 != NULL ) {
V_88 -> V_90 = V_56 ;
return;
}
if ( V_56 == NULL )
return;
V_88 = F_67 ( sizeof ( T_19 ) ) ;
V_88 -> V_91 = NULL ;
V_88 -> V_90 = V_56 ;
F_68 ( V_81 -> V_87 ,
F_37 ( V_82 ) , ( V_7 ) V_88 ) ;
}
void
F_74 ( const char * V_12 , const T_7 V_82 )
{
T_18 V_81 = F_61 ( V_12 ) ;
T_19 * V_88 ;
F_62 ( V_81 ) ;
V_88 = F_64 ( V_81 , V_82 ) ;
if ( V_88 == NULL )
return;
if ( V_88 -> V_91 != NULL ) {
V_88 -> V_90 = V_88 -> V_91 ;
} else {
F_71 ( V_81 -> V_87 ,
F_37 ( V_82 ) ) ;
F_72 ( V_88 ) ;
}
}
T_14
F_75 ( T_18 V_81 , const T_7 V_92 ,
T_1 * V_4 , T_5 * V_11 , T_13 * V_51 , const T_14 V_65 )
{
T_19 * V_88 ;
struct V_93 * V_56 ;
T_7 V_94 ;
int V_58 ;
V_88 = F_64 ( V_81 , V_92 ) ;
if ( V_88 != NULL ) {
V_56 = V_88 -> V_90 ;
if ( V_56 == NULL ) {
return FALSE ;
}
V_94 = V_11 -> V_95 ;
V_11 -> V_95 = V_92 ;
V_58 = F_52 ( V_56 , V_4 , V_11 , V_51 , V_65 ) ;
V_11 -> V_95 = V_94 ;
return V_58 != 0 ;
}
return FALSE ;
}
T_14
F_76 ( T_18 V_81 , const T_7 V_92 ,
T_1 * V_4 , T_5 * V_11 , T_13 * V_51 )
{
return F_75 ( V_81 , V_92 , V_4 , V_11 , V_51 , TRUE ) ;
}
T_12
F_77 ( T_18 const V_81 , const T_7 V_92 )
{
T_19 * V_88 ;
V_88 = F_64 ( V_81 , V_92 ) ;
if ( V_88 != NULL )
return V_88 -> V_90 ;
else
return NULL ;
}
static T_19 *
F_78 ( T_18 const V_81 , const T_20 * V_82 )
{
switch ( V_81 -> type ) {
case V_96 :
case V_97 :
break;
default:
F_48 () ;
}
return F_63 ( V_81 -> V_87 , V_82 ) ;
}
void
F_79 ( const char * V_12 , const T_20 * V_82 ,
T_12 V_56 )
{
T_18 V_81 = F_61 ( V_12 ) ;
T_19 * V_88 ;
if ( V_81 == NULL ) {
fprintf ( V_89 , L_16 ,
V_12 ) ;
fprintf ( V_89 , L_17 ,
F_66 ( V_56 -> V_59 ) ) ;
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
F_62 ( V_56 != NULL ) ;
switch ( V_81 -> type ) {
case V_96 :
case V_97 :
break;
default:
F_48 () ;
}
V_88 = F_67 ( sizeof ( T_19 ) ) ;
V_88 -> V_90 = V_56 ;
V_88 -> V_91 = V_88 -> V_90 ;
F_68 ( V_81 -> V_87 , ( V_7 ) V_82 ,
( V_7 ) V_88 ) ;
F_69 ( V_12 , V_56 ) ;
}
void
F_80 ( const char * V_12 , const T_20 * V_82 ,
T_12 V_56 V_9 )
{
T_18 V_81 = F_61 ( V_12 ) ;
T_19 * V_88 ;
F_62 ( V_81 ) ;
V_88 = F_78 ( V_81 , V_82 ) ;
if ( V_88 != NULL ) {
F_71 ( V_81 -> V_87 , V_82 ) ;
F_72 ( V_88 ) ;
}
}
void
F_81 ( const char * V_12 , const T_20 * V_82 ,
T_12 V_56 )
{
T_18 V_81 = F_61 ( V_12 ) ;
T_19 * V_88 ;
F_62 ( V_81 ) ;
V_88 = F_78 ( V_81 , V_82 ) ;
if ( V_88 != NULL ) {
V_88 -> V_90 = V_56 ;
return;
}
if ( V_56 == NULL )
return;
V_88 = F_67 ( sizeof ( T_19 ) ) ;
V_88 -> V_91 = NULL ;
V_88 -> V_90 = V_56 ;
F_68 ( V_81 -> V_87 , ( V_7 ) V_82 ,
( V_7 ) V_88 ) ;
}
void
F_82 ( const char * V_12 , const T_20 * V_82 )
{
T_18 V_81 = F_61 ( V_12 ) ;
T_19 * V_88 ;
F_62 ( V_81 ) ;
V_88 = F_78 ( V_81 , V_82 ) ;
if ( V_88 == NULL )
return;
if ( V_88 -> V_91 != NULL ) {
V_88 -> V_90 = V_88 -> V_91 ;
} else {
F_71 ( V_81 -> V_87 , V_82 ) ;
F_72 ( V_88 ) ;
}
}
T_14
F_83 ( T_18 V_81 , const T_20 * string ,
T_1 * V_4 , T_5 * V_11 , T_13 * V_51 )
{
T_19 * V_88 ;
struct V_93 * V_56 ;
int V_58 ;
const T_20 * V_98 ;
if ( ! string ) return FALSE ;
V_88 = F_78 ( V_81 , string ) ;
if ( V_88 != NULL ) {
V_56 = V_88 -> V_90 ;
if ( V_56 == NULL ) {
return FALSE ;
}
V_98 = V_11 -> V_99 ;
V_11 -> V_99 = string ;
V_58 = F_52 ( V_56 , V_4 , V_11 , V_51 , TRUE ) ;
V_11 -> V_99 = V_98 ;
return V_58 != 0 ;
}
return FALSE ;
}
T_12
F_84 ( T_18 V_81 ,
const T_20 * string )
{
T_19 * V_88 ;
V_88 = F_78 ( V_81 , string ) ;
if ( V_88 != NULL )
return V_88 -> V_90 ;
else
return NULL ;
}
T_12
F_85 ( T_19 * V_88 )
{
return V_88 -> V_90 ;
}
void
F_69 ( const char * V_12 , T_12 V_56 )
{
T_18 V_81 = F_61 ( V_12 ) ;
T_21 * V_100 ;
if ( V_81 == NULL ) {
fprintf ( V_89 , L_16 ,
V_12 ) ;
fprintf ( V_89 , L_17 ,
F_66 ( V_56 -> V_59 ) ) ;
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
V_100 = F_86 ( V_81 -> V_101 , ( V_7 ) V_56 ) ;
if ( V_100 != NULL ) {
return;
}
V_81 -> V_101 =
F_10 ( V_81 -> V_101 , ( V_7 ) V_56 ) ;
}
T_12
F_87 ( T_19 * V_88 )
{
return V_88 -> V_91 ;
}
static void
F_88 ( V_7 V_102 , V_7 V_103 , V_7 V_104 )
{
T_22 * V_105 ;
T_19 * V_88 ;
F_62 ( V_103 ) ;
F_62 ( V_104 ) ;
V_88 = V_103 ;
if ( V_88 -> V_90 == NULL ||
V_88 -> V_90 -> V_59 == NULL ) {
return;
}
V_105 = V_104 ;
V_105 -> V_106 ( V_105 -> V_107 , V_105 -> V_108 , V_102 , V_103 ,
V_105 -> V_109 ) ;
}
static void
F_89 ( V_7 V_102 , V_7 V_103 , V_7 V_104 )
{
T_18 V_81 ;
T_22 * V_105 ;
F_62 ( V_103 ) ;
F_62 ( V_104 ) ;
V_81 = V_103 ;
V_105 = V_104 ;
V_105 -> V_107 = ( T_20 * ) V_102 ;
V_105 -> V_108 = F_90 ( V_105 -> V_107 ) ;
F_91 ( V_81 -> V_87 , V_105 -> V_110 , V_105 ) ;
}
static void
F_92 ( T_23 F_9 ,
V_7 V_104 )
{
T_22 V_105 ;
V_105 . V_109 = V_104 ;
V_105 . V_106 = F_9 ;
V_105 . V_110 = F_88 ;
F_91 ( V_80 , F_89 , & V_105 ) ;
}
void
F_93 ( const char * V_12 ,
T_23 F_9 ,
V_7 V_104 )
{
T_22 V_105 ;
T_18 V_81 = F_61 ( V_12 ) ;
V_105 . V_107 = V_12 ;
V_105 . V_108 = V_81 -> type ;
V_105 . V_106 = F_9 ;
V_105 . V_109 = V_104 ;
F_91 ( V_81 -> V_87 , F_88 , & V_105 ) ;
}
void
F_94 ( const char * V_12 ,
T_24 F_9 ,
V_7 V_104 )
{
T_18 V_81 = F_61 ( V_12 ) ;
T_21 * V_111 ;
for ( V_111 = V_81 -> V_101 ; V_111 != NULL ;
V_111 = F_95 ( V_111 ) )
F_9 ( V_12 , V_111 -> V_112 , V_104 ) ;
}
static void
F_96 ( V_7 V_102 , V_7 V_103 , V_7 V_104 )
{
T_19 * V_88 ;
T_22 * V_105 ;
F_62 ( V_103 ) ;
F_62 ( V_104 ) ;
V_88 = V_103 ;
if ( V_88 -> V_91 == V_88 -> V_90 ) {
return;
}
V_105 = V_104 ;
V_105 -> V_106 ( V_105 -> V_107 , V_105 -> V_108 , V_102 , V_103 ,
V_105 -> V_109 ) ;
}
void
F_97 ( T_23 F_9 ,
V_7 V_104 )
{
T_22 V_105 ;
V_105 . V_109 = V_104 ;
V_105 . V_106 = F_9 ;
V_105 . V_110 = F_96 ;
F_91 ( V_80 , F_89 , & V_105 ) ;
}
void
F_98 ( const char * V_12 ,
T_23 F_9 ,
V_7 V_104 )
{
T_22 V_105 ;
T_18 V_81 = F_61 ( V_12 ) ;
V_105 . V_107 = V_12 ;
V_105 . V_108 = V_81 -> type ;
V_105 . V_106 = F_9 ;
V_105 . V_109 = V_104 ;
F_91 ( V_81 -> V_87 ,
F_96 , & V_105 ) ;
}
static void
F_99 ( V_7 V_102 , const V_7 V_103 , const V_7 V_104 )
{
T_18 V_113 ;
T_25 * V_105 ;
V_113 = V_103 ;
V_105 = V_104 ;
(* V_105 -> V_106 )( ( T_20 * ) V_102 , V_113 -> V_114 , V_105 -> V_109 ) ;
}
void
F_100 ( T_26 F_9 ,
V_7 V_104 )
{
T_25 V_105 ;
V_105 . V_109 = V_104 ;
V_105 . V_106 = F_9 ;
F_91 ( V_80 , F_99 , & V_105 ) ;
}
T_18
F_101 ( const char * V_12 , const char * V_114 , const T_27 type ,
const int V_115 )
{
T_18 V_81 ;
if ( ! V_80 ) {
V_80 = F_102 ( V_116 , V_117 ) ;
F_62 ( V_80 ) ;
}
if( F_63 ( V_80 , V_12 ) ) {
F_103 ( L_19 , V_12 , V_114 ) ;
}
V_81 = F_67 ( sizeof ( struct V_118 ) ) ;
switch ( type ) {
case V_83 :
case V_84 :
case V_85 :
case V_86 :
V_81 -> V_87 = F_102 ( V_119 ,
V_120 ) ;
break;
case V_96 :
case V_97 :
V_81 -> V_87 = F_102 ( V_116 ,
V_117 ) ;
break;
default:
F_48 () ;
}
V_81 -> V_101 = NULL ;
V_81 -> V_114 = V_114 ;
V_81 -> type = type ;
V_81 -> V_115 = V_115 ;
F_68 ( V_80 , ( V_7 ) V_12 , ( V_7 ) V_81 ) ;
return V_81 ;
}
const char *
F_104 ( const char * V_12 )
{
T_18 V_81 = F_61 ( V_12 ) ;
return V_81 -> V_114 ;
}
T_27
F_90 ( const char * V_12 )
{
T_18 V_81 = F_61 ( V_12 ) ;
return V_81 -> type ;
}
int
F_105 ( const char * V_12 )
{
T_18 V_81 = F_61 ( V_12 ) ;
return V_81 -> V_115 ;
}
static T_28 *
F_106 ( const char * V_12 )
{
F_62 ( V_121 != NULL ) ;
return F_63 ( V_121 , V_12 ) ;
}
void
F_107 ( const char * V_12 , T_29 V_61 , const int V_122 )
{
T_28 * V_81 = F_106 ( V_12 ) ;
const char * V_123 ;
T_30 * V_124 ;
if ( V_81 == NULL ) {
fprintf ( V_89 , L_16 ,
V_12 ) ;
V_123 = F_108 ( V_122 ) ;
if ( V_123 != NULL ) {
fprintf ( V_89 , L_17 ,
V_123 ) ;
}
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
V_124 = F_67 ( sizeof ( T_30 ) ) ;
V_124 -> V_61 = V_61 ;
V_124 -> V_59 = F_109 ( V_122 ) ;
V_124 -> V_125 = TRUE ;
* V_81 = F_10 ( * V_81 , ( V_7 ) V_124 ) ;
}
static int
F_110 ( T_31 V_126 , T_31 V_127 ) {
const T_30 * V_128 = ( const T_30 * ) V_126 ;
const T_30 * V_129 = ( const T_30 * ) V_127 ;
return ( V_128 -> V_61 == V_129 -> V_61 ) &&
( V_128 -> V_59 == V_129 -> V_59 ) ? 0 : 1 ;
}
void
F_111 ( const char * V_12 , T_29 V_61 , const int V_122 ) {
T_28 * V_81 = F_106 ( V_12 ) ;
T_30 V_124 ;
T_21 * V_130 ;
F_62 ( V_81 != NULL ) ;
V_124 . V_61 = V_61 ;
V_124 . V_59 = F_109 ( V_122 ) ;
V_130 = F_112 ( * V_81 , ( V_7 ) & V_124 , F_110 ) ;
if ( V_130 ) {
* V_81 = F_113 ( * V_81 , V_130 ) ;
F_72 ( F_114 ( V_130 , 1 ) ) ;
F_115 ( V_130 ) ;
}
}
void
F_116 ( const char * V_12 , T_29 V_61 , const int V_122 , const T_14 V_125 ) {
T_28 * V_81 = F_106 ( V_12 ) ;
T_21 * V_130 ;
T_30 V_124 ;
F_62 ( V_81 != NULL ) ;
V_124 . V_61 = V_61 ;
V_124 . V_59 = F_109 ( V_122 ) ;
V_130 = F_112 ( * V_81 , ( V_7 ) & V_124 , F_110 ) ;
if ( V_130 ) {
T_30 * V_131 ;
V_131 = ( T_30 * ) V_130 -> V_112 ;
V_131 -> V_125 = V_125 ;
}
}
T_14
F_117 ( T_28 V_81 ,
T_1 * V_4 , T_5 * V_11 , T_13 * V_51 )
{
T_14 V_132 ;
const char * V_57 ;
T_21 * V_100 ;
T_30 * V_124 ;
T_15 V_66 ;
T_16 V_67 = 0 ;
V_66 = V_11 -> V_68 ;
V_11 -> V_66 = V_66 ;
V_11 -> V_68 = V_66 - ( V_66 > 0 ) ;
V_132 = FALSE ;
V_57 = V_11 -> V_26 ;
if ( V_11 -> V_69 != NULL )
V_67 = ( T_16 ) V_11 -> V_69 -> V_70 ;
for ( V_100 = V_81 ; V_100 != NULL ; V_100 = F_95 ( V_100 ) ) {
V_11 -> V_68 = V_66 - ( V_66 > 0 ) ;
V_124 = ( T_30 * ) V_100 -> V_112 ;
if ( V_124 -> V_59 != NULL &&
( ! F_53 ( V_124 -> V_59 ) || ( V_124 -> V_125 == FALSE ) ) ) {
continue;
}
if ( V_124 -> V_59 != NULL ) {
V_11 -> V_26 =
F_51 ( V_124 -> V_59 ) ;
if ( V_11 -> V_69 ) {
if ( V_11 -> V_69 -> V_70 > 0 )
F_54 ( V_11 -> V_69 , L_15 ) ;
F_54 ( V_11 -> V_69 ,
F_55 ( F_56 ( V_124 -> V_59 ) ) ) ;
}
}
F_43 ( ( L_20 ,
F_55 ( F_56 ( V_124 -> V_59 ) ) ) ) ;
if ( (* V_124 -> V_61 )( V_4 , V_11 , V_51 ) ) {
F_43 ( ( L_21 ,
F_55 ( F_56 ( V_124 -> V_59 ) ) ) ) ;
V_132 = TRUE ;
break;
} else {
F_43 ( ( L_22 ,
F_55 ( F_56 ( V_124 -> V_59 ) ) ) ) ;
if ( V_11 -> V_69 != NULL ) {
F_58 ( V_11 -> V_69 , V_67 ) ;
}
}
}
V_11 -> V_26 = V_57 ;
V_11 -> V_68 = V_66 ;
return V_132 ;
}
static void
F_118 ( const T_20 * V_107 , const V_7 V_103 , const V_7 V_104 V_9 )
{
T_28 V_81 = * ( T_28 * ) V_103 ;
T_21 * V_100 ;
T_30 * V_124 ;
for ( V_100 = V_81 ; V_100 != NULL ; V_100 = F_95 ( V_100 ) ) {
V_124 = ( T_30 * ) V_100 -> V_112 ;
if ( V_124 -> V_59 != NULL ) {
printf ( L_23 ,
V_107 ,
F_55 ( F_56 ( V_124 -> V_59 ) ) ,
( F_53 ( V_124 -> V_59 ) && V_124 -> V_125 ) ? 'T' : 'F' ) ;
}
}
}
static void
F_119 ( V_7 V_102 , const V_7 V_103 , const V_7 V_104 )
{
T_32 * V_105 ;
V_105 = V_104 ;
(* V_105 -> V_106 )( ( T_20 * ) V_102 , V_103 , V_105 -> V_109 ) ;
}
void
F_120 ( T_33 F_9 ,
V_7 V_104 )
{
T_32 V_105 ;
V_105 . V_109 = V_104 ;
V_105 . V_106 = F_9 ;
F_91 ( V_121 , F_119 , & V_105 ) ;
}
void
F_121 ( void )
{
F_120 ( F_118 , NULL ) ;
}
void
F_122 ( const char * V_12 , T_28 * V_81 )
{
if ( V_121 == NULL ) {
V_121 = F_102 ( V_116 , V_117 ) ;
F_62 ( V_121 != NULL ) ;
}
F_62 ( F_63 ( V_121 , V_12 ) == NULL ) ;
* V_81 = NULL ;
F_68 ( V_121 , ( V_7 ) V_12 ,
( V_7 ) V_81 ) ;
}
const char *
F_123 ( const T_12 V_56 )
{
if ( V_56 == NULL || V_56 -> V_59 == NULL ) {
return NULL ;
}
return F_66 ( V_56 -> V_59 ) ;
}
const char *
F_124 ( const T_12 V_56 )
{
if ( V_56 -> V_59 == NULL ) {
return NULL ;
}
return F_51 ( V_56 -> V_59 ) ;
}
int
F_125 ( const T_12 V_56 )
{
if ( V_56 -> V_59 == NULL ) {
return - 1 ;
}
return F_56 ( V_56 -> V_59 ) ;
}
T_12
F_2 ( const char * V_12 )
{
F_62 ( V_133 != NULL ) ;
return F_63 ( V_133 , V_12 ) ;
}
T_12
F_126 ( T_34 V_61 , const int V_122 )
{
struct V_93 * V_56 ;
V_56 = F_67 ( sizeof ( struct V_93 ) ) ;
V_56 -> V_12 = NULL ;
V_56 -> V_60 = FALSE ;
V_56 -> V_61 . V_63 = V_61 ;
V_56 -> V_59 = F_109 ( V_122 ) ;
return V_56 ;
}
T_12
F_127 ( T_35 V_61 , const int V_122 )
{
struct V_93 * V_56 ;
V_56 = F_67 ( sizeof ( struct V_93 ) ) ;
V_56 -> V_12 = NULL ;
V_56 -> V_60 = TRUE ;
V_56 -> V_61 . V_62 = V_61 ;
V_56 -> V_59 = F_109 ( V_122 ) ;
return V_56 ;
}
void
F_128 ( const char * V_12 , T_34 V_61 , const int V_122 )
{
struct V_93 * V_56 ;
if ( V_133 == NULL ) {
V_133 = F_102 ( V_116 , V_117 ) ;
F_62 ( V_133 != NULL ) ;
}
F_62 ( F_63 ( V_133 , V_12 ) == NULL ) ;
V_56 = F_67 ( sizeof ( struct V_93 ) ) ;
V_56 -> V_12 = V_12 ;
V_56 -> V_60 = FALSE ;
V_56 -> V_61 . V_63 = V_61 ;
V_56 -> V_59 = F_109 ( V_122 ) ;
F_68 ( V_133 , ( V_7 ) V_12 ,
( V_7 ) V_56 ) ;
}
void
F_129 ( const char * V_12 , T_35 V_61 , const int V_122 )
{
struct V_93 * V_56 ;
if ( V_133 == NULL ) {
V_133 = F_102 ( V_116 , V_117 ) ;
F_62 ( V_133 != NULL ) ;
}
F_62 ( F_63 ( V_133 , V_12 ) == NULL ) ;
V_56 = F_67 ( sizeof ( struct V_93 ) ) ;
V_56 -> V_12 = V_12 ;
V_56 -> V_60 = TRUE ;
V_56 -> V_61 . V_62 = V_61 ;
V_56 -> V_59 = F_109 ( V_122 ) ;
F_68 ( V_133 , ( V_7 ) V_12 ,
( V_7 ) V_56 ) ;
}
int
F_130 ( T_12 V_56 , T_1 * V_4 ,
T_5 * V_11 , T_13 * V_51 )
{
int V_58 ;
F_62 ( V_56 != NULL ) ;
V_58 = F_52 ( V_56 , V_4 , V_11 , V_51 , TRUE ) ;
return V_58 ;
}
int
F_46 ( T_12 V_56 , T_1 * V_4 ,
T_5 * V_11 , T_13 * V_51 )
{
int V_58 ;
V_58 = F_130 ( V_56 , V_4 , V_11 , V_51 ) ;
if ( V_58 == 0 ) {
F_62 ( V_2 != NULL ) ;
F_62 ( V_2 -> V_59 != NULL ) ;
F_52 ( V_2 , V_4 , V_11 , V_51 , TRUE ) ;
return F_31 ( V_4 ) ;
}
return V_58 ;
}
static void
F_131 ( const T_20 * V_107 ,
T_27 V_108 V_9 , const V_7 V_102 , const V_7 V_103 ,
V_7 V_104 V_9 )
{
T_7 V_134 = ( T_7 ) ( unsigned long ) V_102 ;
T_18 V_81 = F_61 ( V_107 ) ;
T_19 * V_88 ;
T_12 V_56 ;
T_16 V_135 ;
const T_20 * V_136 ;
F_62 ( V_81 ) ;
switch ( V_81 -> type ) {
case V_83 :
case V_84 :
case V_85 :
case V_86 :
V_88 = V_103 ;
F_62 ( V_88 ) ;
V_56 = V_88 -> V_90 ;
F_62 ( V_56 ) ;
V_135 = F_125 ( V_56 ) ;
if ( V_135 != - 1 ) {
V_136 = F_55 ( V_135 ) ;
F_62 ( V_136 != NULL ) ;
printf ( L_24 , V_107 , V_134 , V_136 ) ;
}
break;
default:
break;
}
}
void
F_132 ( void )
{
F_92 ( F_131 , NULL ) ;
}
void
F_133 ( T_12 V_56 )
{
if ( ! V_137 )
V_137 = F_134 () ;
F_135 ( V_137 , V_56 ) ;
V_138 ++ ;
}
T_14
F_136 ( void )
{
T_2 V_139 ;
T_12 V_56 ;
for( V_139 = 0 ; V_139 < V_138 ; V_139 ++ ) {
V_56 = ( T_12 ) F_137 ( V_137 , V_139 ) ;
if ( V_56 -> V_59 != NULL
&& F_53 ( V_56 -> V_59 ) ) {
return TRUE ;
}
}
return FALSE ;
}
void
F_138 ( T_1 * V_4 , T_5 * V_11 , T_13 * V_51 )
{
T_2 V_139 ;
for( V_139 = 0 ; V_139 < V_138 ; V_139 ++ ) {
F_130 ( ( T_12 ) F_137 ( V_137 , V_139 ) ,
V_4 , V_11 , V_51 ) ;
}
}
