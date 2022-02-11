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
F_16 () ;
F_17 () ;
F_18 () ;
F_19 ( V_6 , & F_11 , NULL ) ;
F_20 () ;
F_21 () ;
}
void
F_22 ( void )
{
F_23 () ;
F_13 () ;
F_24 () ;
F_19 ( V_6 , & F_11 , NULL ) ;
F_25 () ;
F_26 () ;
F_27 () ;
F_15 () ;
F_16 () ;
}
void
F_28 ( T_4 F_9 )
{
V_10 = F_10 ( V_10 ,
( V_7 ) F_9 ) ;
}
static void
F_29 ( V_7 V_8 , V_7 T_3 V_9 )
{
T_4 F_9 = ( T_4 ) V_8 ;
(* F_9)() ;
}
void
F_30 ( void )
{
F_19 ( V_10 ,
& F_29 , NULL ) ;
}
void
F_31 ( T_5 * V_11 , T_1 * V_4 , const char * V_12 )
{
struct V_13 * V_14 ;
V_14 = (struct V_13 * ) F_32 ( sizeof( struct V_13 ) ) ;
V_14 -> V_4 = V_4 ;
V_14 -> V_12 = F_33 ( V_12 ) ;
V_11 -> V_15 = F_10 ( V_11 -> V_15 , V_14 ) ;
}
const char *
F_34 ( const struct V_13 * V_14 )
{
T_2 V_16 = F_35 ( V_14 -> V_4 ) ;
return F_36 ( L_4 , V_14 -> V_12 , V_16 ,
F_37 ( V_16 , L_5 , L_6 ) ) ;
}
T_1 *
F_38 ( const struct V_13 * V_14 )
{
return V_14 -> V_4 ;
}
void
F_39 ( T_5 * V_11 )
{
if ( V_11 -> V_15 ) {
T_6 * V_17 ;
for ( V_17 = V_11 -> V_15 ; V_17 ; V_17 = V_17 -> V_18 ) {
struct V_13 * V_14 = (struct V_13 * ) V_17 -> V_19 ;
F_40 ( V_14 -> V_12 ) ;
F_40 ( V_14 ) ;
}
F_41 ( V_11 -> V_15 ) ;
V_11 -> V_15 = NULL ;
}
}
void
F_42 ( T_5 * V_11 , T_7 V_20 )
{
if ( V_20 != F_43 ( V_11 ) ) {
V_11 -> V_21 = F_44 ( V_11 -> V_21 , F_45 ( V_20 ) ) ;
}
}
void
F_46 ( void (* F_9)( void ) )
{
V_22 = F_10 ( V_22 ,
( V_7 ) F_9 ) ;
}
static void
F_47 ( V_7 V_8 , V_7 T_3 V_9 )
{
T_4 F_9 = ( T_4 ) V_8 ;
(* F_9)() ;
}
void
F_48 ( void )
{
F_19 ( V_22 ,
& F_47 , NULL ) ;
}
void
F_49 ( T_8 * V_23 , struct V_24 * V_25 ,
const T_9 * V_26 , T_10 * V_27 , T_11 * V_28 )
{
T_12 * V_29 = V_23 -> V_30 . V_31 ;
if ( V_28 != NULL )
F_50 ( V_28 ) ;
memset ( & V_23 -> V_30 , 0 , sizeof( V_23 -> V_30 ) ) ;
V_23 -> V_30 . V_31 = V_29 ;
V_23 -> V_30 . V_32 = L_7 ;
V_23 -> V_30 . V_28 = V_28 ;
V_23 -> V_30 . V_27 = V_27 ;
V_23 -> V_30 . V_25 = V_25 ;
V_23 -> V_30 . V_33 = & V_25 -> V_33 ;
V_23 -> V_30 . V_34 . type = V_35 ;
V_23 -> V_30 . V_36 . type = V_35 ;
V_23 -> V_30 . V_37 . type = V_35 ;
V_23 -> V_30 . V_38 . type = V_35 ;
V_23 -> V_30 . V_14 . type = V_35 ;
V_23 -> V_30 . V_39 . type = V_35 ;
V_23 -> V_30 . V_40 = V_41 ;
V_23 -> V_30 . V_42 = L_5 ;
V_23 -> V_30 . V_43 = V_44 ;
V_23 -> V_30 . V_45 = V_46 ;
V_23 -> V_30 . V_47 = - 1 ;
V_23 -> V_30 . V_48 = V_49 ;
V_23 -> V_30 . V_50 = L_5 ;
V_23 -> V_30 . V_51 = V_52 ;
V_23 -> V_4 = NULL ;
V_23 -> V_30 . V_53 = V_54 ;
F_51 ( ( L_8 , V_27 -> V_55 ) ) ;
F_52 {
V_23 -> V_4 = F_53 ( V_26 , V_27 -> V_56 ,
V_27 -> V_57 > V_54 ? V_54 : V_27 -> V_57 ) ;
F_31 ( & V_23 -> V_30 , V_23 -> V_4 , L_9 ) ;
if( V_1 != NULL )
F_54 ( V_1 , V_23 -> V_4 , & V_23 -> V_30 , V_23 -> V_58 ) ;
}
F_55 (BoundsError) {
F_56 () ;
}
F_57 (FragmentBoundsError, ReportedBoundsError) {
if( V_3 != - 1 ) {
F_58 ( V_23 -> V_58 , V_3 , V_23 -> V_4 , 0 , 0 ,
L_10 ) ;
} else {
F_56 () ;
}
}
V_59 ;
F_51 ( ( L_11 , V_27 -> V_55 ) ) ;
V_27 -> V_60 . V_61 = 1 ;
}
static int
F_59 ( T_13 V_62 , T_1 * V_4 ,
T_5 * V_11 , T_14 * V_58 , void * V_19 )
{
const char * V_63 ;
int V_64 ;
V_63 = V_11 -> V_32 ;
if ( V_62 -> V_65 != NULL ) {
V_11 -> V_32 =
F_60 ( V_62 -> V_65 ) ;
}
if ( V_62 -> V_66 ) {
F_51 ( ( L_12 , V_62 -> V_12 ) ) ;
V_64 = (* V_62 -> V_67 . V_68 )( V_4 , V_11 , V_58 , V_19 ) ;
F_51 ( ( L_13 , V_62 -> V_12 ) ) ;
} else {
F_51 ( ( L_14 , V_62 -> V_12 ) ) ;
(* V_62 -> V_67 . V_69 )( V_4 , V_11 , V_58 ) ;
F_51 ( ( L_15 , V_62 -> V_12 ) ) ;
V_64 = F_35 ( V_4 ) ;
if ( V_64 == 0 ) {
V_64 = 1 ;
}
}
V_11 -> V_32 = V_63 ;
return V_64 ;
}
static int
F_61 ( T_13 V_62 , T_1 * V_4 , T_5 * V_70 ,
T_14 * V_58 , T_15 V_71 , void * V_19 )
{
T_5 * V_11 = V_70 ;
const char * V_63 ;
T_16 V_72 ;
int V_64 ;
T_17 V_73 = 0 ;
if ( V_62 -> V_65 != NULL &&
! F_62 ( V_62 -> V_65 ) ) {
return 0 ;
}
V_63 = V_11 -> V_32 ;
V_72 = V_11 -> V_74 ;
if ( V_11 -> V_75 != NULL )
V_73 = ( T_17 ) V_11 -> V_75 -> V_76 ;
V_11 -> V_72 = V_72 ;
V_11 -> V_74 = V_72 - ( V_72 > 0 ) ;
if ( V_62 -> V_65 != NULL ) {
V_11 -> V_32 =
F_60 ( V_62 -> V_65 ) ;
if ( ( V_11 -> V_75 ) && ( V_71 ) ) {
if ( V_11 -> V_75 -> V_76 > 0 )
F_63 ( V_11 -> V_75 , L_16 ) ;
F_63 ( V_11 -> V_75 ,
F_64 ( F_65 ( V_62 -> V_65 ) ) ) ;
}
}
if ( V_11 -> V_60 . V_77 ) {
V_64 = F_66 ( V_62 , V_4 , V_11 , V_58 , V_19 ) ;
} else {
V_64 = F_59 ( V_62 , V_4 , V_11 , V_58 , V_19 ) ;
}
if ( V_64 == 0 ) {
if ( ( V_11 -> V_75 != NULL ) && ( V_71 ) ) {
F_67 ( V_11 -> V_75 , V_73 ) ;
}
}
V_11 -> V_32 = V_63 ;
V_11 -> V_74 = V_72 ;
return V_64 ;
}
static int
F_66 ( T_13 V_62 , T_1 * V_4 ,
T_5 * V_70 , T_14 * V_58 , void * V_19 )
{
T_5 * V_11 = V_70 ;
const char * V_63 ;
T_16 V_72 ;
volatile int V_64 = 0 ;
T_15 V_78 ;
T_18 V_79 ;
T_18 V_80 ;
T_18 V_81 ;
T_18 V_82 ;
T_18 V_83 ;
T_18 V_84 ;
V_63 = V_11 -> V_32 ;
V_72 = V_11 -> V_74 ;
V_78 = F_68 ( V_11 -> V_28 ) ;
F_69 ( V_11 -> V_28 , FALSE ) ;
V_79 = V_11 -> V_34 ;
V_80 = V_11 -> V_36 ;
V_81 = V_11 -> V_37 ;
V_82 = V_11 -> V_38 ;
V_83 = V_11 -> V_14 ;
V_84 = V_11 -> V_39 ;
F_52 {
V_64 = F_59 ( V_62 , V_4 , V_11 , V_58 , V_19 ) ;
}
F_55 (BoundsError) {
F_69 ( V_11 -> V_28 , V_78 ) ;
V_11 -> V_34 = V_79 ;
V_11 -> V_36 = V_80 ;
V_11 -> V_37 = V_81 ;
V_11 -> V_38 = V_82 ;
V_11 -> V_14 = V_83 ;
V_11 -> V_39 = V_84 ;
V_11 -> V_32 = V_63 ;
V_11 -> V_74 = V_72 ;
V_85 ;
}
F_57 (FragmentBoundsError, ReportedBoundsError) {
V_64 = F_35 ( V_4 ) ;
}
V_59 ;
F_69 ( V_11 -> V_28 , V_78 ) ;
V_11 -> V_34 = V_79 ;
V_11 -> V_36 = V_80 ;
V_11 -> V_37 = V_81 ;
V_11 -> V_38 = V_82 ;
V_11 -> V_14 = V_83 ;
V_11 -> V_39 = V_84 ;
V_11 -> V_86 = 0 ;
return V_64 ;
}
T_19
F_70 ( const char * V_12 )
{
F_71 ( V_87 ) ;
return ( T_19 ) F_72 ( V_87 , V_12 ) ;
}
static T_20 *
F_73 ( T_19 V_88 , const T_7 V_89 )
{
switch ( V_88 -> type ) {
case V_90 :
case V_91 :
case V_92 :
case V_93 :
break;
default:
F_56 () ;
}
return ( T_20 * ) F_72 ( V_88 -> V_94 ,
F_45 ( V_89 ) ) ;
}
void
F_74 ( const char * V_12 , const T_7 V_89 , T_13 V_62 )
{
T_19 V_88 ;
T_20 * V_95 ;
V_88 = F_70 ( V_12 ) ;
if ( V_88 == NULL ) {
fprintf ( V_96 , L_17 ,
V_12 ) ;
fprintf ( V_96 , L_18 ,
F_75 ( V_62 -> V_65 ) ) ;
if ( getenv ( L_19 ) != NULL )
abort () ;
return;
}
F_71 ( V_62 != NULL ) ;
switch ( V_88 -> type ) {
case V_90 :
case V_91 :
case V_92 :
case V_93 :
break;
default:
F_56 () ;
}
#if 0
dissector_add_uint_sanity_check(name, pattern, handle, sub_dissectors);
#endif
V_95 = ( T_20 * ) F_32 ( sizeof ( T_20 ) ) ;
V_95 -> V_97 = V_62 ;
V_95 -> V_98 = V_95 -> V_97 ;
F_76 ( V_88 -> V_94 ,
F_45 ( V_89 ) , ( V_7 ) V_95 ) ;
F_77 ( V_12 , V_62 ) ;
}
void
F_78 ( const char * V_12 , const T_7 V_89 ,
T_13 V_62 V_9 )
{
T_19 V_88 = F_70 ( V_12 ) ;
T_20 * V_95 ;
F_71 ( V_88 ) ;
V_95 = F_73 ( V_88 , V_89 ) ;
if ( V_95 != NULL ) {
F_79 ( V_88 -> V_94 ,
F_45 ( V_89 ) ) ;
}
}
void
F_80 ( const char * V_12 , const T_7 V_89 , T_13 V_62 )
{
T_19 V_88 = F_70 ( V_12 ) ;
T_20 * V_95 ;
F_71 ( V_88 ) ;
V_95 = F_73 ( V_88 , V_89 ) ;
if ( V_95 != NULL ) {
V_95 -> V_97 = V_62 ;
return;
}
if ( V_62 == NULL )
return;
V_95 = ( T_20 * ) F_32 ( sizeof ( T_20 ) ) ;
V_95 -> V_98 = NULL ;
V_95 -> V_97 = V_62 ;
F_76 ( V_88 -> V_94 ,
F_45 ( V_89 ) , ( V_7 ) V_95 ) ;
}
void
F_81 ( const char * V_12 , const T_7 V_89 )
{
T_19 V_88 = F_70 ( V_12 ) ;
T_20 * V_95 ;
F_71 ( V_88 ) ;
V_95 = F_73 ( V_88 , V_89 ) ;
if ( V_95 == NULL )
return;
if ( V_95 -> V_98 != NULL ) {
V_95 -> V_97 = V_95 -> V_98 ;
} else {
F_79 ( V_88 -> V_94 ,
F_45 ( V_89 ) ) ;
}
}
T_15
F_82 ( T_19 V_88 , const T_7 V_99 ,
T_1 * V_4 , T_5 * V_11 , T_14 * V_58 ,
const T_15 V_71 , void * V_19 )
{
T_20 * V_95 ;
struct V_100 * V_62 ;
T_7 V_101 ;
int V_64 ;
V_95 = F_73 ( V_88 , V_99 ) ;
if ( V_95 != NULL ) {
V_62 = V_95 -> V_97 ;
if ( V_62 == NULL ) {
return FALSE ;
}
V_101 = V_11 -> V_102 ;
V_11 -> V_102 = V_99 ;
V_64 = F_61 ( V_62 , V_4 , V_11 , V_58 , V_71 , V_19 ) ;
V_11 -> V_102 = V_101 ;
return V_64 != 0 ;
}
return FALSE ;
}
T_15
F_83 ( T_19 V_88 , const T_7 V_99 ,
T_1 * V_4 , T_5 * V_11 , T_14 * V_58 )
{
return F_82 ( V_88 , V_99 , V_4 , V_11 , V_58 , TRUE , NULL ) ;
}
T_13
F_84 ( T_19 const V_88 , const T_7 V_99 )
{
T_20 * V_95 ;
V_95 = F_73 ( V_88 , V_99 ) ;
if ( V_95 != NULL )
return V_95 -> V_97 ;
else
return NULL ;
}
static T_20 *
F_85 ( T_19 const V_88 , const T_21 * V_89 )
{
switch ( V_88 -> type ) {
case V_103 :
case V_104 :
break;
default:
F_56 () ;
}
return ( T_20 * ) F_72 ( V_88 -> V_94 , V_89 ) ;
}
void
F_86 ( const char * V_12 , const T_21 * V_89 ,
T_13 V_62 )
{
T_19 V_88 = F_70 ( V_12 ) ;
T_20 * V_95 ;
if ( V_88 == NULL ) {
fprintf ( V_96 , L_17 ,
V_12 ) ;
fprintf ( V_96 , L_18 ,
F_75 ( V_62 -> V_65 ) ) ;
if ( getenv ( L_19 ) != NULL )
abort () ;
return;
}
F_71 ( V_62 != NULL ) ;
switch ( V_88 -> type ) {
case V_103 :
case V_104 :
break;
default:
F_56 () ;
}
V_95 = ( T_20 * ) F_32 ( sizeof ( T_20 ) ) ;
V_95 -> V_97 = V_62 ;
V_95 -> V_98 = V_95 -> V_97 ;
F_76 ( V_88 -> V_94 , ( V_7 ) V_89 ,
( V_7 ) V_95 ) ;
F_77 ( V_12 , V_62 ) ;
}
void
F_87 ( const char * V_12 , const T_21 * V_89 ,
T_13 V_62 V_9 )
{
T_19 V_88 = F_70 ( V_12 ) ;
T_20 * V_95 ;
F_71 ( V_88 ) ;
V_95 = F_85 ( V_88 , V_89 ) ;
if ( V_95 != NULL ) {
F_79 ( V_88 -> V_94 , V_89 ) ;
}
}
void
F_88 ( const char * V_12 , const T_21 * V_89 ,
T_13 V_62 )
{
T_19 V_88 = F_70 ( V_12 ) ;
T_20 * V_95 ;
F_71 ( V_88 ) ;
V_95 = F_85 ( V_88 , V_89 ) ;
if ( V_95 != NULL ) {
V_95 -> V_97 = V_62 ;
return;
}
if ( V_62 == NULL )
return;
V_95 = ( T_20 * ) F_32 ( sizeof ( T_20 ) ) ;
V_95 -> V_98 = NULL ;
V_95 -> V_97 = V_62 ;
F_76 ( V_88 -> V_94 , ( V_7 ) V_89 ,
( V_7 ) V_95 ) ;
}
void
F_89 ( const char * V_12 , const T_21 * V_89 )
{
T_19 V_88 = F_70 ( V_12 ) ;
T_20 * V_95 ;
F_71 ( V_88 ) ;
V_95 = F_85 ( V_88 , V_89 ) ;
if ( V_95 == NULL )
return;
if ( V_95 -> V_98 != NULL ) {
V_95 -> V_97 = V_95 -> V_98 ;
} else {
F_79 ( V_88 -> V_94 , V_89 ) ;
}
}
T_15
F_90 ( T_19 V_88 , const T_21 * string ,
T_1 * V_4 , T_5 * V_11 , T_14 * V_58 )
{
T_20 * V_95 ;
struct V_100 * V_62 ;
int V_64 ;
const T_21 * V_105 ;
if ( ! string ) return FALSE ;
V_95 = F_85 ( V_88 , string ) ;
if ( V_95 != NULL ) {
V_62 = V_95 -> V_97 ;
if ( V_62 == NULL ) {
return FALSE ;
}
V_105 = V_11 -> V_106 ;
V_11 -> V_106 = string ;
V_64 = F_61 ( V_62 , V_4 , V_11 , V_58 , TRUE , NULL ) ;
V_11 -> V_106 = V_105 ;
return V_64 != 0 ;
}
return FALSE ;
}
T_13
F_91 ( T_19 V_88 ,
const T_21 * string )
{
T_20 * V_95 ;
V_95 = F_85 ( V_88 , string ) ;
if ( V_95 != NULL )
return V_95 -> V_97 ;
else
return NULL ;
}
T_13
F_92 ( T_20 * V_95 )
{
return V_95 -> V_97 ;
}
static T_17
F_93 ( T_22 V_107 , T_22 V_108 )
{
const T_13 V_109 = ( const T_13 ) V_107 ;
const T_13 V_110 = ( const T_13 ) V_108 ;
const char * V_111 , * V_112 ;
T_17 V_64 ;
if ( V_109 -> V_65 == NULL )
V_111 = L_5 ;
else
V_111 = F_64 ( F_65 ( V_109 -> V_65 ) ) ;
if ( V_110 -> V_65 == NULL )
V_112 = L_5 ;
else
V_112 = F_64 ( F_65 ( V_110 -> V_65 ) ) ;
V_64 = strcmp ( V_111 , V_112 ) ;
return V_64 ;
}
void
F_77 ( const char * V_12 , T_13 V_62 )
{
T_19 V_88 = F_70 ( V_12 ) ;
T_6 * V_113 ;
if ( V_88 == NULL ) {
fprintf ( V_96 , L_17 ,
V_12 ) ;
fprintf ( V_96 , L_18 ,
F_75 ( V_62 -> V_65 ) ) ;
if ( getenv ( L_19 ) != NULL )
abort () ;
return;
}
V_113 = F_94 ( V_88 -> V_114 , ( V_7 ) V_62 ) ;
if ( V_113 != NULL ) {
return;
}
V_88 -> V_114 =
F_95 ( V_88 -> V_114 , ( V_7 ) V_62 , ( V_115 ) F_93 ) ;
}
T_13
F_96 ( T_20 * V_95 )
{
return V_95 -> V_98 ;
}
static void
F_97 ( V_7 V_116 , V_7 V_117 , V_7 V_118 )
{
T_23 * V_119 ;
T_20 * V_95 ;
F_71 ( V_117 ) ;
F_71 ( V_118 ) ;
V_95 = ( T_20 * ) V_117 ;
if ( V_95 -> V_97 == NULL ||
V_95 -> V_97 -> V_65 == NULL ) {
return;
}
V_119 = ( T_23 * ) V_118 ;
V_119 -> V_120 ( V_119 -> V_121 , V_119 -> V_122 , V_116 , V_117 ,
V_119 -> V_123 ) ;
}
static void
F_98 ( V_7 V_116 , V_7 V_117 , V_7 V_118 )
{
T_19 V_88 ;
T_23 * V_119 ;
F_71 ( V_117 ) ;
F_71 ( V_118 ) ;
V_88 = ( T_19 ) V_117 ;
V_119 = ( T_23 * ) V_118 ;
V_119 -> V_121 = ( T_21 * ) V_116 ;
V_119 -> V_122 = F_99 ( V_119 -> V_121 ) ;
F_100 ( V_88 -> V_94 , V_119 -> V_124 , V_119 ) ;
}
static void
F_101 ( T_24 F_9 ,
V_7 V_118 )
{
T_23 V_119 ;
V_119 . V_123 = V_118 ;
V_119 . V_120 = F_9 ;
V_119 . V_124 = F_97 ;
F_100 ( V_87 , F_98 , & V_119 ) ;
}
void
F_102 ( const char * V_12 ,
T_24 F_9 ,
V_7 V_118 )
{
T_23 V_119 ;
T_19 V_88 = F_70 ( V_12 ) ;
V_119 . V_121 = V_12 ;
V_119 . V_122 = V_88 -> type ;
V_119 . V_120 = F_9 ;
V_119 . V_123 = V_118 ;
F_100 ( V_88 -> V_94 , F_97 , & V_119 ) ;
}
void
F_103 ( const char * V_12 ,
T_25 F_9 ,
V_7 V_118 )
{
T_19 V_88 = F_70 ( V_12 ) ;
T_6 * V_29 ;
for ( V_29 = V_88 -> V_114 ; V_29 != NULL ;
V_29 = F_104 ( V_29 ) )
F_9 ( V_12 , V_29 -> V_19 , V_118 ) ;
}
static void
F_105 ( V_7 V_116 , V_7 V_117 , V_7 V_118 )
{
T_20 * V_95 ;
T_23 * V_119 ;
F_71 ( V_117 ) ;
F_71 ( V_118 ) ;
V_95 = ( T_20 * ) V_117 ;
if ( V_95 -> V_98 == V_95 -> V_97 ) {
return;
}
V_119 = ( T_23 * ) V_118 ;
V_119 -> V_120 ( V_119 -> V_121 , V_119 -> V_122 , V_116 , V_117 ,
V_119 -> V_123 ) ;
}
void
F_106 ( T_24 F_9 ,
V_7 V_118 )
{
T_23 V_119 ;
V_119 . V_123 = V_118 ;
V_119 . V_120 = F_9 ;
V_119 . V_124 = F_105 ;
F_100 ( V_87 , F_98 , & V_119 ) ;
}
void
F_107 ( const char * V_12 ,
T_24 F_9 ,
V_7 V_118 )
{
T_23 V_119 ;
T_19 V_88 = F_70 ( V_12 ) ;
V_119 . V_121 = V_12 ;
V_119 . V_122 = V_88 -> type ;
V_119 . V_120 = F_9 ;
V_119 . V_123 = V_118 ;
F_100 ( V_88 -> V_94 ,
F_105 , & V_119 ) ;
}
static void
F_108 ( V_7 V_116 , const V_7 V_117 , const V_7 V_118 )
{
T_19 V_125 ;
T_26 * V_119 ;
V_125 = ( T_19 ) V_117 ;
V_119 = ( T_26 * ) V_118 ;
(* V_119 -> V_120 )( ( T_21 * ) V_116 , V_125 -> V_126 , V_119 -> V_123 ) ;
}
static void
F_109 ( V_7 V_116 , V_7 V_118 )
{
T_19 V_125 ;
T_26 * V_119 ;
V_125 = ( T_19 ) F_72 ( V_87 , V_116 ) ;
V_119 = ( T_26 * ) V_118 ;
(* V_119 -> V_120 )( ( T_21 * ) V_116 , V_125 -> V_126 , V_119 -> V_123 ) ;
}
void
F_110 ( T_27 F_9 ,
V_7 V_118 ,
V_115 V_127 )
{
T_26 V_119 ;
T_28 * V_128 ;
V_119 . V_123 = V_118 ;
V_119 . V_120 = F_9 ;
if ( V_127 != NULL )
{
V_128 = F_111 ( V_87 ) ;
V_128 = F_112 ( V_128 , V_127 ) ;
F_113 ( V_128 , F_109 , & V_119 ) ;
F_114 ( V_128 ) ;
}
else
{
F_100 ( V_87 , F_108 , & V_119 ) ;
}
}
T_19
F_115 ( const char * V_12 , const char * V_126 , const T_29 type ,
const int V_129 )
{
T_19 V_88 ;
if ( ! V_87 ) {
V_87 = F_116 ( V_130 , V_131 ) ;
F_71 ( V_87 ) ;
}
if( F_72 ( V_87 , V_12 ) ) {
F_117 ( L_20 , V_12 , V_126 ) ;
}
V_88 = (struct V_132 * ) F_32 ( sizeof ( struct V_132 ) ) ;
switch ( type ) {
case V_90 :
case V_91 :
case V_92 :
case V_93 :
V_88 -> V_94 = F_118 ( V_133 ,
V_134 ,
NULL ,
& F_40 ) ;
break;
case V_103 :
case V_104 :
V_88 -> V_94 = F_118 ( V_130 ,
V_131 ,
NULL ,
& F_40 ) ;
break;
default:
F_56 () ;
}
V_88 -> V_114 = NULL ;
V_88 -> V_126 = V_126 ;
V_88 -> type = type ;
V_88 -> V_129 = V_129 ;
F_76 ( V_87 , ( V_7 ) V_12 , ( V_7 ) V_88 ) ;
return V_88 ;
}
const char *
F_119 ( const char * V_12 )
{
T_19 V_88 = F_70 ( V_12 ) ;
return V_88 -> V_126 ;
}
T_29
F_99 ( const char * V_12 )
{
T_19 V_88 = F_70 ( V_12 ) ;
return V_88 -> type ;
}
int
F_120 ( const char * V_12 )
{
T_19 V_88 = F_70 ( V_12 ) ;
return V_88 -> V_129 ;
}
static T_30 *
F_121 ( const char * V_12 )
{
F_71 ( V_135 != NULL ) ;
return ( T_30 * ) F_72 ( V_135 , V_12 ) ;
}
void
F_122 ( const char * V_12 , T_31 V_67 , const int V_136 )
{
T_30 * V_88 = F_121 ( V_12 ) ;
const char * V_137 ;
T_32 * V_138 ;
if ( V_88 == NULL ) {
fprintf ( V_96 , L_17 ,
V_12 ) ;
V_137 = F_123 ( V_136 ) ;
if ( V_137 != NULL ) {
fprintf ( V_96 , L_18 ,
V_137 ) ;
}
if ( getenv ( L_19 ) != NULL )
abort () ;
return;
}
V_138 = ( T_32 * ) F_32 ( sizeof ( T_32 ) ) ;
V_138 -> V_67 = V_67 ;
V_138 -> V_65 = F_124 ( V_136 ) ;
V_138 -> V_139 = TRUE ;
* V_88 = F_10 ( * V_88 , ( V_7 ) V_138 ) ;
}
static int
F_125 ( T_22 V_109 , T_22 V_110 ) {
const T_32 * V_140 = ( const T_32 * ) V_109 ;
const T_32 * V_141 = ( const T_32 * ) V_110 ;
return ( V_140 -> V_67 == V_141 -> V_67 ) &&
( V_140 -> V_65 == V_141 -> V_65 ) ? 0 : 1 ;
}
void
F_126 ( const char * V_12 , T_31 V_67 , const int V_136 ) {
T_30 * V_88 = F_121 ( V_12 ) ;
T_32 V_138 ;
T_6 * V_142 ;
F_71 ( V_88 != NULL ) ;
V_138 . V_67 = V_67 ;
V_138 . V_65 = F_124 ( V_136 ) ;
V_142 = F_127 ( * V_88 , ( V_7 ) & V_138 , F_125 ) ;
if ( V_142 ) {
* V_88 = F_128 ( * V_88 , V_142 ) ;
F_40 ( F_129 ( V_142 , 1 ) ) ;
F_130 ( V_142 ) ;
}
}
void
F_131 ( const char * V_12 , T_31 V_67 , const int V_136 , const T_15 V_139 ) {
T_30 * V_88 = F_121 ( V_12 ) ;
T_6 * V_142 ;
T_32 V_138 ;
F_71 ( V_88 != NULL ) ;
V_138 . V_67 = V_67 ;
V_138 . V_65 = F_124 ( V_136 ) ;
V_142 = F_127 ( * V_88 , ( V_7 ) & V_138 , F_125 ) ;
if ( V_142 ) {
T_32 * V_143 ;
V_143 = ( T_32 * ) V_142 -> V_19 ;
V_143 -> V_139 = V_139 ;
}
}
T_15
F_132 ( T_30 V_88 , T_1 * V_4 ,
T_5 * V_11 , T_14 * V_58 , void * V_19 )
{
T_15 V_144 ;
const char * V_63 ;
T_6 * V_113 ;
T_32 * V_138 ;
T_16 V_72 ;
T_17 V_73 = 0 ;
V_72 = V_11 -> V_74 ;
V_11 -> V_72 = V_72 ;
V_11 -> V_74 = V_72 - ( V_72 > 0 ) ;
V_144 = FALSE ;
V_63 = V_11 -> V_32 ;
if ( V_11 -> V_75 != NULL )
V_73 = ( T_17 ) V_11 -> V_75 -> V_76 ;
for ( V_113 = V_88 ; V_113 != NULL ; V_113 = F_104 ( V_113 ) ) {
V_11 -> V_74 = V_72 - ( V_72 > 0 ) ;
V_138 = ( T_32 * ) V_113 -> V_19 ;
if ( V_138 -> V_65 != NULL &&
( ! F_62 ( V_138 -> V_65 ) || ( V_138 -> V_139 == FALSE ) ) ) {
continue;
}
if ( V_138 -> V_65 != NULL ) {
V_11 -> V_32 =
F_60 ( V_138 -> V_65 ) ;
if ( V_11 -> V_75 ) {
if ( V_11 -> V_75 -> V_76 > 0 )
F_63 ( V_11 -> V_75 , L_16 ) ;
F_63 ( V_11 -> V_75 ,
F_64 ( F_65 ( V_138 -> V_65 ) ) ) ;
}
}
F_51 ( ( L_21 ,
F_64 ( F_65 ( V_138 -> V_65 ) ) ) ) ;
if ( (* V_138 -> V_67 )( V_4 , V_11 , V_58 , V_19 ) ) {
F_51 ( ( L_22 ,
F_64 ( F_65 ( V_138 -> V_65 ) ) ) ) ;
V_144 = TRUE ;
break;
} else {
F_51 ( ( L_23 ,
F_64 ( F_65 ( V_138 -> V_65 ) ) ) ) ;
if ( V_11 -> V_75 != NULL ) {
F_67 ( V_11 -> V_75 , V_73 ) ;
}
}
}
V_11 -> V_32 = V_63 ;
V_11 -> V_74 = V_72 ;
return V_144 ;
}
static void
F_133 ( const T_21 * V_121 , const V_7 V_117 , const V_7 V_118 V_9 )
{
T_30 V_88 = * ( T_30 * ) V_117 ;
T_6 * V_113 ;
T_32 * V_138 ;
for ( V_113 = V_88 ; V_113 != NULL ; V_113 = F_104 ( V_113 ) ) {
V_138 = ( T_32 * ) V_113 -> V_19 ;
if ( V_138 -> V_65 != NULL ) {
printf ( L_24 ,
V_121 ,
F_64 ( F_65 ( V_138 -> V_65 ) ) ,
( F_62 ( V_138 -> V_65 ) && V_138 -> V_139 ) ? 'T' : 'F' ) ;
}
}
}
static void
F_134 ( V_7 V_116 , const V_7 V_117 , const V_7 V_118 )
{
T_33 * V_119 ;
V_119 = ( T_33 * ) V_118 ;
(* V_119 -> V_120 )( ( T_21 * ) V_116 , V_117 , V_119 -> V_123 ) ;
}
void
F_135 ( T_34 F_9 ,
V_7 V_118 )
{
T_33 V_119 ;
V_119 . V_123 = V_118 ;
V_119 . V_120 = F_9 ;
F_100 ( V_135 , F_134 , & V_119 ) ;
}
void
F_136 ( void )
{
F_135 ( F_133 , NULL ) ;
}
void
F_137 ( const char * V_12 , T_30 * V_88 )
{
if ( V_135 == NULL ) {
V_135 = F_116 ( V_130 , V_131 ) ;
F_71 ( V_135 != NULL ) ;
}
F_71 ( F_72 ( V_135 , V_12 ) == NULL ) ;
* V_88 = NULL ;
F_76 ( V_135 , ( V_7 ) V_12 ,
( V_7 ) V_88 ) ;
}
const char *
F_138 ( const T_13 V_62 )
{
if ( V_62 == NULL || V_62 -> V_65 == NULL ) {
return NULL ;
}
return F_75 ( V_62 -> V_65 ) ;
}
const char *
F_139 ( const T_13 V_62 )
{
if ( V_62 -> V_65 == NULL ) {
return NULL ;
}
return F_60 ( V_62 -> V_65 ) ;
}
int
F_140 ( const T_13 V_62 )
{
if ( V_62 -> V_65 == NULL ) {
return - 1 ;
}
return F_65 ( V_62 -> V_65 ) ;
}
T_13
F_2 ( const char * V_12 )
{
F_71 ( V_145 != NULL ) ;
return ( T_13 ) F_72 ( V_145 , V_12 ) ;
}
T_13
F_141 ( T_35 V_67 , const int V_136 )
{
struct V_100 * V_62 ;
V_62 = (struct V_100 * ) F_32 ( sizeof ( struct V_100 ) ) ;
V_62 -> V_12 = NULL ;
V_62 -> V_66 = FALSE ;
V_62 -> V_67 . V_69 = V_67 ;
V_62 -> V_65 = F_124 ( V_136 ) ;
return V_62 ;
}
T_13
F_142 ( T_36 V_67 , const int V_136 )
{
struct V_100 * V_62 ;
V_62 = (struct V_100 * ) F_32 ( sizeof ( struct V_100 ) ) ;
V_62 -> V_12 = NULL ;
V_62 -> V_66 = TRUE ;
V_62 -> V_67 . V_68 = V_67 ;
V_62 -> V_65 = F_124 ( V_136 ) ;
return V_62 ;
}
void
F_143 ( const char * V_12 , T_35 V_67 , const int V_136 )
{
struct V_100 * V_62 ;
if ( V_145 == NULL ) {
V_145 = F_116 ( V_130 , V_131 ) ;
F_71 ( V_145 != NULL ) ;
}
F_71 ( F_72 ( V_145 , V_12 ) == NULL ) ;
V_62 = (struct V_100 * ) F_32 ( sizeof ( struct V_100 ) ) ;
V_62 -> V_12 = V_12 ;
V_62 -> V_66 = FALSE ;
V_62 -> V_67 . V_69 = V_67 ;
V_62 -> V_65 = F_124 ( V_136 ) ;
F_76 ( V_145 , ( V_7 ) V_12 ,
( V_7 ) V_62 ) ;
}
void
F_144 ( const char * V_12 , T_36 V_67 , const int V_136 )
{
struct V_100 * V_62 ;
if ( V_145 == NULL ) {
V_145 = F_116 ( V_130 , V_131 ) ;
F_71 ( V_145 != NULL ) ;
}
F_71 ( F_72 ( V_145 , V_12 ) == NULL ) ;
V_62 = (struct V_100 * ) F_32 ( sizeof ( struct V_100 ) ) ;
V_62 -> V_12 = V_12 ;
V_62 -> V_66 = TRUE ;
V_62 -> V_67 . V_68 = V_67 ;
V_62 -> V_65 = F_124 ( V_136 ) ;
F_76 ( V_145 , ( V_7 ) V_12 ,
( V_7 ) V_62 ) ;
}
int
F_145 ( T_13 V_62 , T_1 * V_4 ,
T_5 * V_11 , T_14 * V_58 , void * V_19 )
{
int V_64 ;
F_71 ( V_62 != NULL ) ;
V_64 = F_61 ( V_62 , V_4 , V_11 , V_58 , TRUE , V_19 ) ;
return V_64 ;
}
int
F_146 ( T_13 V_62 , T_1 * V_4 ,
T_5 * V_11 , T_14 * V_58 , void * V_19 )
{
int V_64 ;
V_64 = F_145 ( V_62 , V_4 , V_11 , V_58 , V_19 ) ;
if ( V_64 == 0 ) {
F_71 ( V_2 != NULL ) ;
F_71 ( V_2 -> V_65 != NULL ) ;
F_61 ( V_2 , V_4 , V_11 , V_58 , TRUE , NULL ) ;
return F_35 ( V_4 ) ;
}
return V_64 ;
}
int
F_54 ( T_13 V_62 , T_1 * V_4 ,
T_5 * V_11 , T_14 * V_58 )
{
return F_146 ( V_62 , V_4 , V_11 , V_58 , NULL ) ;
}
static void
F_147 ( const T_21 * V_121 ,
T_29 V_122 V_9 , const V_7 V_116 , const V_7 V_117 ,
V_7 V_118 V_9 )
{
T_7 V_146 = ( T_7 ) ( unsigned long ) V_116 ;
T_19 V_88 = F_70 ( V_121 ) ;
T_20 * V_95 ;
T_13 V_62 ;
T_17 V_147 ;
const T_21 * V_148 ;
F_71 ( V_88 ) ;
switch ( V_88 -> type ) {
case V_90 :
case V_91 :
case V_92 :
case V_93 :
V_95 = ( T_20 * ) V_117 ;
F_71 ( V_95 ) ;
V_62 = V_95 -> V_97 ;
F_71 ( V_62 ) ;
V_147 = F_140 ( V_62 ) ;
if ( V_147 != - 1 ) {
V_148 = F_64 ( V_147 ) ;
F_71 ( V_148 != NULL ) ;
printf ( L_25 , V_121 , V_146 , V_148 ) ;
}
break;
default:
break;
}
}
void
F_148 ( void )
{
F_101 ( F_147 , NULL ) ;
}
void
F_149 ( T_13 V_62 )
{
if ( ! V_149 )
V_149 = F_150 () ;
F_151 ( V_149 , V_62 ) ;
V_150 ++ ;
}
T_15
F_152 ( void )
{
T_2 V_151 ;
T_13 V_62 ;
for( V_151 = 0 ; V_151 < V_150 ; V_151 ++ ) {
V_62 = ( T_13 ) F_153 ( V_149 , V_151 ) ;
if ( V_62 -> V_65 != NULL
&& F_62 ( V_62 -> V_65 ) ) {
return TRUE ;
}
}
return FALSE ;
}
void
F_154 ( T_1 * V_4 , T_5 * V_11 , T_14 * V_58 )
{
T_2 V_151 ;
for( V_151 = 0 ; V_151 < V_150 ; V_151 ++ ) {
F_145 ( ( T_13 ) F_153 ( V_149 , V_151 ) ,
V_4 , V_11 , V_58 , NULL ) ;
}
}
