static void
F_1 ( T_1 V_1 , T_1 T_2 V_2 )
{
F_2 ( V_3 , V_1 ) ;
}
static void
F_3 ( void * V_1 )
{
T_3 * * V_4 = ( T_3 * * ) V_1 ;
F_4 ( * V_4 , F_1 , NULL ) ;
F_5 ( * V_4 ) ;
* V_4 = NULL ;
}
static void
F_6 ( void * V_1 )
{
struct V_5 * V_6 = (struct V_5 * ) V_1 ;
F_7 ( V_6 -> V_7 ) ;
F_5 ( V_6 -> V_8 ) ;
F_2 ( struct V_5 , V_1 ) ;
}
void
F_8 ( void )
{
V_9 = F_9 ( V_10 , V_11 ,
NULL , F_6 ) ;
V_12 = F_9 ( V_10 , V_11 ,
NULL , NULL ) ;
V_13 = F_9 ( V_10 , V_11 ,
NULL , F_3 ) ;
}
void
F_10 ( void )
{
V_14 = F_11 ( L_1 ) ;
F_12 ( V_14 != NULL ) ;
V_15 = F_11 ( L_2 ) ;
F_12 ( V_15 != NULL ) ;
V_16 = F_13 ( L_3 ) ;
F_12 ( V_16 != - 1 ) ;
}
void
F_14 ( void )
{
F_7 ( V_9 ) ;
F_7 ( V_12 ) ;
F_7 ( V_13 ) ;
}
void
F_15 ( T_4 * V_17 , const T_5 V_18 )
{
if ( V_18 < F_16 ( V_17 ) ) {
F_17 ( V_17 , V_18 ) ;
}
}
void
F_18 ( void (* F_19)( void ) )
{
V_19 = F_20 ( V_19 , ( T_1 ) F_19 ) ;
}
static void
F_21 ( T_1 V_20 , T_1 T_6 V_2 )
{
T_7 F_19 = ( T_7 ) V_20 ;
(* F_19)() ;
}
void
F_22 ( void )
{
F_23 () ;
F_24 () ;
F_25 () ;
F_26 () ;
F_27 () ;
F_4 ( V_19 , & F_21 , NULL ) ;
F_28 () ;
F_29 () ;
}
void
F_30 ( void )
{
F_31 () ;
F_23 () ;
F_32 () ;
F_4 ( V_19 , & F_21 , NULL ) ;
F_33 () ;
F_34 () ;
F_35 () ;
F_36 () ;
}
void
F_37 ( T_7 F_19 )
{
V_21 = F_20 ( V_21 ,
( T_1 ) F_19 ) ;
}
static void
F_38 ( T_1 V_20 , T_1 T_6 V_2 )
{
T_7 F_19 = ( T_7 ) V_20 ;
(* F_19)() ;
}
void
F_39 ( void )
{
F_4 ( V_21 ,
& F_38 , NULL ) ;
}
void
F_40 ( T_8 * V_22 , T_4 * V_17 , const char * V_23 )
{
struct V_24 * V_25 ;
V_25 = F_41 ( struct V_24 ) ;
V_25 -> V_17 = V_17 ;
V_25 -> V_23 = F_42 ( V_23 ) ;
V_22 -> V_26 = F_43 ( V_22 -> V_26 , V_25 ) ;
}
const char *
F_44 ( const struct V_24 * V_25 )
{
T_5 V_27 = F_45 ( V_25 -> V_17 ) ;
return F_46 ( L_4 , V_25 -> V_23 , V_27 ,
F_47 ( V_27 , L_5 , L_6 ) ) ;
}
T_4 *
F_48 ( const struct V_24 * V_25 )
{
return V_25 -> V_17 ;
}
void
F_49 ( T_8 * V_22 )
{
if ( V_22 -> V_26 ) {
T_3 * V_28 ;
for ( V_28 = V_22 -> V_26 ; V_28 ; V_28 = V_28 -> V_29 ) {
struct V_24 * V_25 = (struct V_24 * ) V_28 -> V_1 ;
F_50 ( V_25 -> V_23 ) ;
F_2 ( struct V_24 , V_25 ) ;
}
F_5 ( V_22 -> V_26 ) ;
V_22 -> V_26 = NULL ;
}
}
void
F_51 ( T_8 * V_22 , T_9 V_30 )
{
if ( V_30 != F_52 ( V_22 ) ) {
V_22 -> V_31 = F_20 ( V_22 -> V_31 , F_53 ( V_30 ) ) ;
}
}
void
F_54 ( void (* F_19)( void ) )
{
V_32 = F_20 ( V_32 ,
( T_1 ) F_19 ) ;
}
static void
F_55 ( T_1 V_20 , T_1 T_6 V_2 )
{
T_7 F_19 = ( T_7 ) V_20 ;
(* F_19)() ;
}
void
F_56 ( void )
{
F_4 ( V_32 ,
& F_55 , NULL ) ;
}
void
F_57 ( T_10 * V_33 , struct V_34 * V_35 ,
T_4 * V_17 , T_11 * V_36 , T_12 * V_37 )
{
T_13 * V_38 = V_33 -> V_39 . V_40 ;
if ( V_37 != NULL )
F_58 ( V_37 , V_33 -> V_41 ) ;
memset ( & V_33 -> V_39 , 0 , sizeof( V_33 -> V_39 ) ) ;
V_33 -> V_39 . V_42 = V_33 -> V_41 ;
V_33 -> V_39 . V_40 = V_38 ;
V_33 -> V_39 . V_43 = L_7 ;
V_33 -> V_39 . V_37 = V_37 ;
V_33 -> V_39 . V_36 = V_36 ;
V_33 -> V_39 . V_35 = V_35 ;
V_33 -> V_39 . V_44 = & V_35 -> V_44 ;
V_33 -> V_39 . V_45 . type = V_46 ;
V_33 -> V_39 . V_47 . type = V_46 ;
V_33 -> V_39 . V_48 . type = V_46 ;
V_33 -> V_39 . V_49 . type = V_46 ;
V_33 -> V_39 . V_25 . type = V_46 ;
V_33 -> V_39 . V_50 . type = V_46 ;
V_33 -> V_39 . V_51 = V_52 ;
V_33 -> V_39 . V_53 = L_5 ;
V_33 -> V_39 . V_54 = V_55 ;
V_33 -> V_39 . V_56 = V_57 ;
V_33 -> V_39 . V_58 = - 1 ;
V_33 -> V_39 . V_59 = V_60 ;
V_33 -> V_39 . V_61 = L_5 ;
V_33 -> V_39 . V_62 = V_63 ;
V_33 -> V_17 = V_17 ;
F_59 ( V_33 -> V_41 , V_36 , V_36 -> V_64 , & V_33 -> V_39 . V_65 ) ;
if ( V_36 -> V_66 . V_67 )
V_33 -> V_39 . V_68 = F_60 ( V_33 -> V_41 , V_36 ) ;
else if ( V_36 -> V_66 . V_69 )
V_33 -> V_39 . V_68 = V_35 -> V_70 ;
V_33 -> V_39 . V_71 = V_72 ;
F_61 ( ( L_8 , V_36 -> V_73 ) ) ;
F_62 {
F_40 ( & V_33 -> V_39 , V_33 -> V_17 , L_9 ) ;
F_63 ( V_14 , V_33 -> V_17 , & V_33 -> V_39 , V_33 -> V_74 ) ;
}
F_64 (BoundsError) {
F_65 () ;
}
F_66 (FragmentBoundsError, ReportedBoundsError) {
F_67 ( V_33 -> V_74 , V_16 , V_33 -> V_17 , 0 , 0 ,
L_10 ) ;
}
V_75 ;
F_61 ( ( L_11 , V_36 -> V_73 ) ) ;
V_36 -> V_66 . V_76 = 1 ;
}
static int
F_68 ( T_14 V_77 , T_4 * V_17 ,
T_8 * V_22 , T_15 * V_74 , void * V_1 )
{
const char * V_78 ;
int V_79 ;
V_78 = V_22 -> V_43 ;
if ( V_77 -> V_80 != NULL ) {
V_22 -> V_43 =
F_69 ( V_77 -> V_80 ) ;
}
if ( V_77 -> V_81 ) {
F_61 ( ( L_12 , V_77 -> V_23 ) ) ;
V_79 = (* V_77 -> V_82 . V_83 )( V_17 , V_22 , V_74 , V_1 ) ;
F_61 ( ( L_13 , V_77 -> V_23 ) ) ;
} else {
F_61 ( ( L_14 , V_77 -> V_23 ) ) ;
(* V_77 -> V_82 . V_84 )( V_17 , V_22 , V_74 ) ;
F_61 ( ( L_15 , V_77 -> V_23 ) ) ;
V_79 = F_45 ( V_17 ) ;
if ( V_79 == 0 ) {
V_79 = 1 ;
}
}
V_22 -> V_43 = V_78 ;
return V_79 ;
}
static int
F_70 ( T_14 V_77 , T_4 * V_17 , T_8 * V_85 ,
T_15 * V_74 , T_16 V_86 , void * V_1 )
{
T_8 * V_22 = V_85 ;
const char * V_78 ;
T_17 V_87 ;
int V_79 ;
T_18 V_88 = 0 ;
if ( V_77 -> V_80 != NULL &&
! F_71 ( V_77 -> V_80 ) ) {
return 0 ;
}
V_78 = V_22 -> V_43 ;
V_87 = V_22 -> V_89 ;
if ( V_22 -> V_90 != NULL )
V_88 = ( T_18 ) V_22 -> V_90 -> V_91 ;
V_22 -> V_87 = V_87 ;
V_22 -> V_89 = V_87 - ( V_87 > 0 ) ;
if ( V_77 -> V_80 != NULL ) {
V_22 -> V_43 =
F_69 ( V_77 -> V_80 ) ;
if ( V_86 ) {
V_22 -> V_92 ++ ;
if ( V_22 -> V_90 ) {
if ( V_22 -> V_90 -> V_91 > 0 )
F_72 ( V_22 -> V_90 , L_16 ) ;
F_72 ( V_22 -> V_90 ,
F_73 ( F_74 ( V_77 -> V_80 ) ) ) ;
}
}
}
if ( V_22 -> V_66 . V_93 ) {
V_79 = F_75 ( V_77 , V_17 , V_22 , V_74 , V_1 ) ;
} else {
V_79 = F_68 ( V_77 , V_17 , V_22 , V_74 , V_1 ) ;
}
if ( V_79 == 0 ) {
if ( ( V_22 -> V_90 != NULL ) && ( V_86 ) ) {
F_76 ( V_22 -> V_90 , V_88 ) ;
}
}
V_22 -> V_43 = V_78 ;
V_22 -> V_89 = V_87 ;
return V_79 ;
}
static int
F_75 ( T_14 V_77 , T_4 * V_17 ,
T_8 * V_85 , T_15 * V_74 , void * V_1 )
{
T_8 * V_22 = V_85 ;
const char * V_78 ;
T_17 V_87 ;
volatile int V_79 = 0 ;
T_16 V_94 ;
T_19 V_95 ;
T_19 V_96 ;
T_19 V_97 ;
T_19 V_98 ;
T_19 V_99 ;
T_19 V_100 ;
V_78 = V_22 -> V_43 ;
V_87 = V_22 -> V_89 ;
V_94 = F_77 ( V_22 -> V_37 ) ;
F_78 ( V_22 -> V_37 , FALSE ) ;
V_95 = V_22 -> V_45 ;
V_96 = V_22 -> V_47 ;
V_97 = V_22 -> V_48 ;
V_98 = V_22 -> V_49 ;
V_99 = V_22 -> V_25 ;
V_100 = V_22 -> V_50 ;
F_62 {
V_79 = F_68 ( V_77 , V_17 , V_22 , V_74 , V_1 ) ;
}
F_64 (BoundsError) {
F_78 ( V_22 -> V_37 , V_94 ) ;
V_22 -> V_45 = V_95 ;
V_22 -> V_47 = V_96 ;
V_22 -> V_48 = V_97 ;
V_22 -> V_49 = V_98 ;
V_22 -> V_25 = V_99 ;
V_22 -> V_50 = V_100 ;
V_22 -> V_43 = V_78 ;
V_22 -> V_89 = V_87 ;
V_101 ;
}
F_66 (FragmentBoundsError, ReportedBoundsError) {
V_79 = F_45 ( V_17 ) ;
}
V_75 ;
F_78 ( V_22 -> V_37 , V_94 ) ;
V_22 -> V_45 = V_95 ;
V_22 -> V_47 = V_96 ;
V_22 -> V_48 = V_97 ;
V_22 -> V_49 = V_98 ;
V_22 -> V_25 = V_99 ;
V_22 -> V_50 = V_100 ;
V_22 -> V_102 = 0 ;
return V_79 ;
}
T_20
F_79 ( const char * V_23 )
{
return ( T_20 ) F_80 ( V_9 , V_23 ) ;
}
static T_21 *
F_81 ( T_20 V_103 , const T_9 V_104 )
{
switch ( V_103 -> type ) {
case V_105 :
case V_106 :
case V_107 :
case V_108 :
break;
default:
F_65 () ;
}
return ( T_21 * ) F_80 ( V_103 -> V_7 ,
F_53 ( V_104 ) ) ;
}
void
F_82 ( const char * V_23 , const T_9 V_104 , T_14 V_77 )
{
T_20 V_103 ;
T_21 * V_109 ;
V_103 = F_79 ( V_23 ) ;
if ( V_103 == NULL ) {
fprintf ( V_110 , L_17 ,
V_23 ) ;
fprintf ( V_110 , L_18 ,
F_83 ( V_77 -> V_80 ) ) ;
if ( getenv ( L_19 ) != NULL )
abort () ;
return;
}
F_12 ( V_77 != NULL ) ;
switch ( V_103 -> type ) {
case V_105 :
case V_106 :
case V_107 :
case V_108 :
break;
default:
F_65 () ;
}
#if 0
dissector_add_uint_sanity_check(name, pattern, handle, sub_dissectors);
#endif
V_109 = ( T_21 * ) F_84 ( sizeof ( T_21 ) ) ;
V_109 -> V_111 = V_77 ;
V_109 -> V_112 = V_109 -> V_111 ;
F_85 ( V_103 -> V_7 ,
F_53 ( V_104 ) , ( T_1 ) V_109 ) ;
F_86 ( V_23 , V_77 ) ;
}
void F_87 ( const char * V_113 , T_22 * V_114 ,
T_14 V_77 )
{
T_9 V_115 , V_116 ;
if ( V_114 ) {
for ( V_115 = 0 ; V_115 < V_114 -> V_117 ; V_115 ++ ) {
for ( V_116 = V_114 -> V_118 [ V_115 ] . V_119 ; V_116 <= V_114 -> V_118 [ V_115 ] . V_120 ; V_116 ++ )
F_82 ( V_113 , V_116 , V_77 ) ;
}
}
}
void
F_88 ( const char * V_23 , const T_9 V_104 ,
T_14 V_77 V_2 )
{
T_20 V_103 = F_79 ( V_23 ) ;
T_21 * V_109 ;
F_12 ( V_103 ) ;
V_109 = F_81 ( V_103 , V_104 ) ;
if ( V_109 != NULL ) {
F_89 ( V_103 -> V_7 ,
F_53 ( V_104 ) ) ;
}
}
void F_90 ( const char * V_113 , T_22 * V_114 ,
T_14 V_77 )
{
T_9 V_115 , V_116 ;
if ( V_114 ) {
for ( V_115 = 0 ; V_115 < V_114 -> V_117 ; V_115 ++ ) {
for ( V_116 = V_114 -> V_118 [ V_115 ] . V_119 ; V_116 <= V_114 -> V_118 [ V_115 ] . V_120 ; V_116 ++ )
F_88 ( V_113 , V_116 , V_77 ) ;
}
}
}
static T_16
F_91 ( T_1 T_23 V_2 , T_1 V_121 , T_1 T_2 )
{
T_21 * V_109 = ( T_21 * ) V_121 ;
T_14 V_77 = ( T_14 ) T_2 ;
return ( F_74 ( V_109 -> V_111 -> V_80 ) == F_74 ( V_77 -> V_80 ) ) ;
}
void F_92 ( const char * V_23 , T_14 V_77 )
{
T_20 V_103 = F_79 ( V_23 ) ;
F_12 ( V_103 ) ;
F_93 ( V_103 -> V_7 , F_91 , V_77 ) ;
}
void
F_94 ( const char * V_23 , const T_9 V_104 , T_14 V_77 )
{
T_20 V_103 = F_79 ( V_23 ) ;
T_21 * V_109 ;
F_12 ( V_103 ) ;
V_109 = F_81 ( V_103 , V_104 ) ;
if ( V_109 != NULL ) {
V_109 -> V_111 = V_77 ;
return;
}
if ( V_77 == NULL )
return;
V_109 = ( T_21 * ) F_84 ( sizeof ( T_21 ) ) ;
V_109 -> V_112 = NULL ;
V_109 -> V_111 = V_77 ;
F_85 ( V_103 -> V_7 ,
F_53 ( V_104 ) , ( T_1 ) V_109 ) ;
}
void
F_95 ( const char * V_23 , const T_9 V_104 )
{
T_20 V_103 = F_79 ( V_23 ) ;
T_21 * V_109 ;
F_12 ( V_103 ) ;
V_109 = F_81 ( V_103 , V_104 ) ;
if ( V_109 == NULL )
return;
if ( V_109 -> V_112 != NULL ) {
V_109 -> V_111 = V_109 -> V_112 ;
} else {
F_89 ( V_103 -> V_7 ,
F_53 ( V_104 ) ) ;
}
}
T_16
F_96 ( T_20 V_103 , const T_9 V_122 ,
T_4 * V_17 , T_8 * V_22 , T_15 * V_74 ,
const T_16 V_86 , void * V_1 )
{
T_21 * V_109 ;
struct V_123 * V_77 ;
T_9 V_124 ;
int V_79 ;
V_109 = F_81 ( V_103 , V_122 ) ;
if ( V_109 != NULL ) {
V_77 = V_109 -> V_111 ;
if ( V_77 == NULL ) {
return FALSE ;
}
V_124 = V_22 -> V_125 ;
V_22 -> V_125 = V_122 ;
V_79 = F_70 ( V_77 , V_17 , V_22 , V_74 , V_86 , V_1 ) ;
V_22 -> V_125 = V_124 ;
return V_79 != 0 ;
}
return FALSE ;
}
T_16
F_97 ( T_20 V_103 , const T_9 V_122 ,
T_4 * V_17 , T_8 * V_22 , T_15 * V_74 )
{
return F_96 ( V_103 , V_122 , V_17 , V_22 , V_74 , TRUE , NULL ) ;
}
T_14
F_98 ( T_20 const V_103 , const T_9 V_122 )
{
T_21 * V_109 ;
V_109 = F_81 ( V_103 , V_122 ) ;
if ( V_109 != NULL )
return V_109 -> V_111 ;
else
return NULL ;
}
static T_21 *
F_99 ( T_20 const V_103 , const T_24 * V_104 )
{
switch ( V_103 -> type ) {
case V_126 :
case V_127 :
break;
default:
F_65 () ;
}
return ( T_21 * ) F_80 ( V_103 -> V_7 , V_104 ) ;
}
void
F_100 ( const char * V_23 , const T_24 * V_104 ,
T_14 V_77 )
{
T_20 V_103 = F_79 ( V_23 ) ;
T_21 * V_109 ;
if ( V_103 == NULL ) {
fprintf ( V_110 , L_17 ,
V_23 ) ;
fprintf ( V_110 , L_18 ,
F_83 ( V_77 -> V_80 ) ) ;
if ( getenv ( L_19 ) != NULL )
abort () ;
return;
}
F_12 ( V_77 != NULL ) ;
switch ( V_103 -> type ) {
case V_126 :
case V_127 :
break;
default:
F_65 () ;
}
V_109 = ( T_21 * ) F_84 ( sizeof ( T_21 ) ) ;
V_109 -> V_111 = V_77 ;
V_109 -> V_112 = V_109 -> V_111 ;
F_85 ( V_103 -> V_7 , ( T_1 ) V_104 ,
( T_1 ) V_109 ) ;
F_86 ( V_23 , V_77 ) ;
}
void
F_101 ( const char * V_23 , const T_24 * V_104 ,
T_14 V_77 V_2 )
{
T_20 V_103 = F_79 ( V_23 ) ;
T_21 * V_109 ;
F_12 ( V_103 ) ;
V_109 = F_99 ( V_103 , V_104 ) ;
if ( V_109 != NULL ) {
F_89 ( V_103 -> V_7 , V_104 ) ;
}
}
void
F_102 ( const char * V_23 , const T_24 * V_104 ,
T_14 V_77 )
{
T_20 V_103 = F_79 ( V_23 ) ;
T_21 * V_109 ;
F_12 ( V_103 ) ;
V_109 = F_99 ( V_103 , V_104 ) ;
if ( V_109 != NULL ) {
V_109 -> V_111 = V_77 ;
return;
}
if ( V_77 == NULL )
return;
V_109 = ( T_21 * ) F_84 ( sizeof ( T_21 ) ) ;
V_109 -> V_112 = NULL ;
V_109 -> V_111 = V_77 ;
F_85 ( V_103 -> V_7 , ( T_1 ) V_104 ,
( T_1 ) V_109 ) ;
}
void
F_103 ( const char * V_23 , const T_24 * V_104 )
{
T_20 V_103 = F_79 ( V_23 ) ;
T_21 * V_109 ;
F_12 ( V_103 ) ;
V_109 = F_99 ( V_103 , V_104 ) ;
if ( V_109 == NULL )
return;
if ( V_109 -> V_112 != NULL ) {
V_109 -> V_111 = V_109 -> V_112 ;
} else {
F_89 ( V_103 -> V_7 , V_104 ) ;
}
}
T_16
F_104 ( T_20 V_103 , const T_24 * string ,
T_4 * V_17 , T_8 * V_22 , T_15 * V_74 )
{
T_21 * V_109 ;
struct V_123 * V_77 ;
int V_79 ;
const T_24 * V_128 ;
if ( ! string ) return FALSE ;
V_109 = F_99 ( V_103 , string ) ;
if ( V_109 != NULL ) {
V_77 = V_109 -> V_111 ;
if ( V_77 == NULL ) {
return FALSE ;
}
V_128 = V_22 -> V_129 ;
V_22 -> V_129 = string ;
V_79 = F_70 ( V_77 , V_17 , V_22 , V_74 , TRUE , NULL ) ;
V_22 -> V_129 = V_128 ;
return V_79 != 0 ;
}
return FALSE ;
}
T_14
F_105 ( T_20 V_103 ,
const T_24 * string )
{
T_21 * V_109 ;
V_109 = F_99 ( V_103 , string ) ;
if ( V_109 != NULL )
return V_109 -> V_111 ;
else
return NULL ;
}
T_14
F_106 ( T_21 * V_109 )
{
return V_109 -> V_111 ;
}
static T_18
F_107 ( T_25 V_130 , T_25 V_131 )
{
const T_14 V_132 = ( const T_14 ) V_130 ;
const T_14 V_133 = ( const T_14 ) V_131 ;
const char * V_134 , * V_135 ;
T_18 V_79 ;
if ( V_132 -> V_80 == NULL )
V_134 = L_5 ;
else
V_134 = F_73 ( F_74 ( V_132 -> V_80 ) ) ;
if ( V_133 -> V_80 == NULL )
V_135 = L_5 ;
else
V_135 = F_73 ( F_74 ( V_133 -> V_80 ) ) ;
V_79 = strcmp ( V_134 , V_135 ) ;
return V_79 ;
}
void
F_86 ( const char * V_23 , T_14 V_77 )
{
T_20 V_103 = F_79 ( V_23 ) ;
T_3 * V_136 ;
if ( V_103 == NULL ) {
fprintf ( V_110 , L_17 ,
V_23 ) ;
fprintf ( V_110 , L_18 ,
F_83 ( V_77 -> V_80 ) ) ;
if ( getenv ( L_19 ) != NULL )
abort () ;
return;
}
V_136 = F_108 ( V_103 -> V_8 , ( T_1 ) V_77 ) ;
if ( V_136 != NULL ) {
return;
}
V_103 -> V_8 =
F_109 ( V_103 -> V_8 , ( T_1 ) V_77 , ( V_137 ) F_107 ) ;
}
T_14
F_110 ( T_21 * V_109 )
{
return V_109 -> V_112 ;
}
static void
F_111 ( T_1 T_23 , T_1 V_121 , T_1 T_2 )
{
T_26 * V_138 ;
T_21 * V_109 ;
F_12 ( V_121 ) ;
F_12 ( T_2 ) ;
V_109 = ( T_21 * ) V_121 ;
if ( V_109 -> V_111 == NULL ||
V_109 -> V_111 -> V_80 == NULL ) {
return;
}
V_138 = ( T_26 * ) T_2 ;
V_138 -> V_139 ( V_138 -> V_140 , V_138 -> V_141 , T_23 , V_121 ,
V_138 -> V_142 ) ;
}
static void
F_112 ( T_1 T_23 , T_1 V_121 , T_1 T_2 )
{
T_20 V_103 ;
T_26 * V_138 ;
F_12 ( V_121 ) ;
F_12 ( T_2 ) ;
V_103 = ( T_20 ) V_121 ;
V_138 = ( T_26 * ) T_2 ;
V_138 -> V_140 = ( T_24 * ) T_23 ;
V_138 -> V_141 = F_113 ( V_138 -> V_140 ) ;
F_114 ( V_103 -> V_7 , V_138 -> V_143 , V_138 ) ;
}
static void
F_115 ( T_27 F_19 ,
T_1 T_2 )
{
T_26 V_138 ;
V_138 . V_142 = T_2 ;
V_138 . V_139 = F_19 ;
V_138 . V_143 = F_111 ;
F_114 ( V_9 , F_112 , & V_138 ) ;
}
void
F_116 ( const char * V_23 ,
T_27 F_19 ,
T_1 T_2 )
{
T_26 V_138 ;
T_20 V_103 = F_79 ( V_23 ) ;
V_138 . V_140 = V_23 ;
V_138 . V_141 = V_103 -> type ;
V_138 . V_139 = F_19 ;
V_138 . V_142 = T_2 ;
F_114 ( V_103 -> V_7 , F_111 , & V_138 ) ;
}
void
F_117 ( const char * V_23 ,
T_28 F_19 ,
T_1 T_2 )
{
T_20 V_103 = F_79 ( V_23 ) ;
T_3 * V_38 ;
for ( V_38 = V_103 -> V_8 ; V_38 != NULL ;
V_38 = F_118 ( V_38 ) )
F_19 ( V_23 , V_38 -> V_1 , T_2 ) ;
}
static void
F_119 ( T_1 T_23 , T_1 V_121 , T_1 T_2 )
{
T_21 * V_109 ;
T_26 * V_138 ;
F_12 ( V_121 ) ;
F_12 ( T_2 ) ;
V_109 = ( T_21 * ) V_121 ;
if ( V_109 -> V_112 == V_109 -> V_111 ) {
return;
}
V_138 = ( T_26 * ) T_2 ;
V_138 -> V_139 ( V_138 -> V_140 , V_138 -> V_141 , T_23 , V_121 ,
V_138 -> V_142 ) ;
}
void
F_120 ( T_27 F_19 ,
T_1 T_2 )
{
T_26 V_138 ;
V_138 . V_142 = T_2 ;
V_138 . V_139 = F_19 ;
V_138 . V_143 = F_119 ;
F_114 ( V_9 , F_112 , & V_138 ) ;
}
void
F_121 ( const char * V_23 ,
T_27 F_19 ,
T_1 T_2 )
{
T_26 V_138 ;
T_20 V_103 = F_79 ( V_23 ) ;
V_138 . V_140 = V_23 ;
V_138 . V_141 = V_103 -> type ;
V_138 . V_139 = F_19 ;
V_138 . V_142 = T_2 ;
F_114 ( V_103 -> V_7 ,
F_119 , & V_138 ) ;
}
static void
F_122 ( T_1 T_23 , const T_1 V_121 , const T_1 T_2 )
{
T_20 V_6 ;
T_29 * V_138 ;
V_6 = ( T_20 ) V_121 ;
V_138 = ( T_29 * ) T_2 ;
(* V_138 -> V_139 )( ( T_24 * ) T_23 , V_6 -> V_144 , V_138 -> V_142 ) ;
}
static void
F_123 ( T_1 T_23 , T_1 T_2 )
{
T_20 V_6 ;
T_29 * V_138 ;
V_6 = ( T_20 ) F_80 ( V_9 , T_23 ) ;
V_138 = ( T_29 * ) T_2 ;
(* V_138 -> V_139 )( ( T_24 * ) T_23 , V_6 -> V_144 , V_138 -> V_142 ) ;
}
void
F_124 ( T_30 F_19 ,
T_1 T_2 ,
V_137 V_145 )
{
T_29 V_138 ;
T_31 * V_4 ;
V_138 . V_142 = T_2 ;
V_138 . V_139 = F_19 ;
if ( V_145 != NULL )
{
V_4 = F_125 ( V_9 ) ;
V_4 = F_126 ( V_4 , V_145 ) ;
F_127 ( V_4 , F_123 , & V_138 ) ;
F_128 ( V_4 ) ;
}
else
{
F_114 ( V_9 , F_122 , & V_138 ) ;
}
}
T_20
F_129 ( const char * V_23 , const char * V_144 , const T_32 type ,
const int V_146 )
{
T_20 V_103 ;
if( F_80 ( V_9 , V_23 ) ) {
F_130 ( L_20 , V_23 , V_144 ) ;
}
V_103 = F_41 ( struct V_5 ) ;
switch ( type ) {
case V_105 :
case V_106 :
case V_107 :
case V_108 :
V_103 -> V_7 = F_9 ( V_147 ,
V_148 ,
NULL ,
& F_50 ) ;
break;
case V_126 :
case V_127 :
V_103 -> V_7 = F_9 ( V_10 ,
V_11 ,
NULL ,
& F_50 ) ;
break;
default:
F_65 () ;
}
V_103 -> V_8 = NULL ;
V_103 -> V_144 = V_144 ;
V_103 -> type = type ;
V_103 -> V_146 = V_146 ;
F_85 ( V_9 , ( T_1 ) V_23 , ( T_1 ) V_103 ) ;
return V_103 ;
}
const char *
F_131 ( const char * V_23 )
{
T_20 V_103 = F_79 ( V_23 ) ;
return V_103 -> V_144 ;
}
T_32
F_113 ( const char * V_23 )
{
T_20 V_103 = F_79 ( V_23 ) ;
return V_103 -> type ;
}
int
F_132 ( const char * V_23 )
{
T_20 V_103 = F_79 ( V_23 ) ;
return V_103 -> V_146 ;
}
static T_33 *
F_133 ( const char * V_23 )
{
return ( T_33 * ) F_80 ( V_13 , V_23 ) ;
}
void
F_134 ( const char * V_23 , T_34 V_82 , const int V_149 )
{
T_33 * V_103 = F_133 ( V_23 ) ;
const char * V_150 ;
V_3 * V_151 ;
if ( V_103 == NULL ) {
fprintf ( V_110 , L_17 ,
V_23 ) ;
V_150 = F_135 ( V_149 ) ;
if ( V_150 != NULL ) {
fprintf ( V_110 , L_18 ,
V_150 ) ;
}
if ( getenv ( L_19 ) != NULL )
abort () ;
return;
}
V_151 = F_41 ( V_3 ) ;
V_151 -> V_82 = V_82 ;
V_151 -> V_80 = F_136 ( V_149 ) ;
V_151 -> V_152 = TRUE ;
* V_103 = F_20 ( * V_103 , ( T_1 ) V_151 ) ;
}
static int
F_137 ( T_25 V_132 , T_25 V_133 ) {
const V_3 * V_153 = ( const V_3 * ) V_132 ;
const V_3 * V_154 = ( const V_3 * ) V_133 ;
return ( V_153 -> V_82 == V_154 -> V_82 ) &&
( V_153 -> V_80 == V_154 -> V_80 ) ? 0 : 1 ;
}
void
F_138 ( const char * V_23 , T_34 V_82 , const int V_149 ) {
T_33 * V_103 = F_133 ( V_23 ) ;
V_3 V_151 ;
T_3 * V_155 ;
F_12 ( V_103 != NULL ) ;
V_151 . V_82 = V_82 ;
V_151 . V_80 = F_136 ( V_149 ) ;
V_155 = F_139 ( * V_103 , ( T_1 ) & V_151 , F_137 ) ;
if ( V_155 ) {
F_2 ( V_3 , V_155 -> V_1 ) ;
* V_103 = F_140 ( * V_103 , V_155 ) ;
}
}
void
F_141 ( const char * V_23 , T_34 V_82 , const int V_149 , const T_16 V_152 ) {
T_33 * V_103 = F_133 ( V_23 ) ;
T_3 * V_155 ;
V_3 V_151 ;
F_12 ( V_103 != NULL ) ;
V_151 . V_82 = V_82 ;
V_151 . V_80 = F_136 ( V_149 ) ;
V_155 = F_139 ( * V_103 , ( T_1 ) & V_151 , F_137 ) ;
if ( V_155 ) {
V_3 * V_156 ;
V_156 = ( V_3 * ) V_155 -> V_1 ;
V_156 -> V_152 = V_152 ;
}
}
T_16
F_142 ( T_33 V_103 , T_4 * V_17 ,
T_8 * V_22 , T_15 * V_74 , void * V_1 )
{
T_16 V_157 ;
const char * V_78 ;
T_3 * V_136 ;
V_3 * V_151 ;
T_17 V_87 ;
T_18 V_88 = 0 ;
V_87 = V_22 -> V_89 ;
V_22 -> V_87 = V_87 ;
V_22 -> V_89 = V_87 - ( V_87 > 0 ) ;
V_157 = FALSE ;
V_78 = V_22 -> V_43 ;
if ( V_22 -> V_90 != NULL )
V_88 = ( T_18 ) V_22 -> V_90 -> V_91 ;
for ( V_136 = V_103 ; V_136 != NULL ; V_136 = F_118 ( V_136 ) ) {
V_22 -> V_89 = V_87 - ( V_87 > 0 ) ;
V_151 = ( V_3 * ) V_136 -> V_1 ;
if ( V_151 -> V_80 != NULL &&
( ! F_71 ( V_151 -> V_80 ) || ( V_151 -> V_152 == FALSE ) ) ) {
continue;
}
if ( V_151 -> V_80 != NULL ) {
V_22 -> V_43 =
F_69 ( V_151 -> V_80 ) ;
if ( V_22 -> V_90 ) {
if ( V_22 -> V_90 -> V_91 > 0 )
F_72 ( V_22 -> V_90 , L_16 ) ;
F_72 ( V_22 -> V_90 ,
F_73 ( F_74 ( V_151 -> V_80 ) ) ) ;
}
}
F_61 ( ( L_21 ,
F_73 ( F_74 ( V_151 -> V_80 ) ) ) ) ;
if ( (* V_151 -> V_82 )( V_17 , V_22 , V_74 , V_1 ) ) {
F_61 ( ( L_22 ,
F_73 ( F_74 ( V_151 -> V_80 ) ) ) ) ;
V_157 = TRUE ;
break;
} else {
F_61 ( ( L_23 ,
F_73 ( F_74 ( V_151 -> V_80 ) ) ) ) ;
if ( V_22 -> V_90 != NULL ) {
F_76 ( V_22 -> V_90 , V_88 ) ;
}
}
}
V_22 -> V_43 = V_78 ;
V_22 -> V_89 = V_87 ;
return V_157 ;
}
static void
F_143 ( const T_24 * V_140 , const T_1 V_121 , const T_1 T_2 V_2 )
{
T_33 V_103 = * ( T_33 * ) V_121 ;
T_3 * V_136 ;
V_3 * V_151 ;
for ( V_136 = V_103 ; V_136 != NULL ; V_136 = F_118 ( V_136 ) ) {
V_151 = ( V_3 * ) V_136 -> V_1 ;
if ( V_151 -> V_80 != NULL ) {
printf ( L_24 ,
V_140 ,
F_73 ( F_74 ( V_151 -> V_80 ) ) ,
( F_71 ( V_151 -> V_80 ) && V_151 -> V_152 ) ? 'T' : 'F' ) ;
}
}
}
static void
F_144 ( T_1 T_23 , const T_1 V_121 , const T_1 T_2 )
{
T_35 * V_138 ;
V_138 = ( T_35 * ) T_2 ;
(* V_138 -> V_139 )( ( T_24 * ) T_23 , V_121 , V_138 -> V_142 ) ;
}
void
F_145 ( T_36 F_19 ,
T_1 T_2 )
{
T_35 V_138 ;
V_138 . V_142 = T_2 ;
V_138 . V_139 = F_19 ;
F_114 ( V_13 , F_144 , & V_138 ) ;
}
void
F_146 ( void )
{
F_145 ( F_143 , NULL ) ;
}
void
F_147 ( const char * V_23 , T_33 * V_103 )
{
F_12 ( F_80 ( V_13 , V_23 ) == NULL ) ;
* V_103 = NULL ;
F_85 ( V_13 , ( T_1 ) V_23 ,
( T_1 ) V_103 ) ;
}
const char *
F_148 ( const T_14 V_77 )
{
if ( V_77 == NULL || V_77 -> V_80 == NULL ) {
return NULL ;
}
return F_83 ( V_77 -> V_80 ) ;
}
const char *
F_149 ( const T_14 V_77 )
{
if ( V_77 -> V_80 == NULL ) {
return NULL ;
}
return F_69 ( V_77 -> V_80 ) ;
}
int
F_150 ( const T_14 V_77 )
{
if ( V_77 -> V_80 == NULL ) {
return - 1 ;
}
return F_74 ( V_77 -> V_80 ) ;
}
T_14
F_11 ( const char * V_23 )
{
return ( T_14 ) F_80 ( V_12 , V_23 ) ;
}
const char *
F_151 ( const T_14 V_77 )
{
if ( V_77 == NULL ) {
return NULL ;
}
return V_77 -> V_23 ;
}
T_14
F_152 ( T_37 V_82 , const int V_149 )
{
struct V_123 * V_77 ;
V_77 = F_153 ( F_154 () , struct V_123 ) ;
V_77 -> V_23 = NULL ;
V_77 -> V_81 = FALSE ;
V_77 -> V_82 . V_84 = V_82 ;
V_77 -> V_80 = F_136 ( V_149 ) ;
return V_77 ;
}
T_14
F_155 ( T_38 V_82 , const int V_149 )
{
struct V_123 * V_77 ;
V_77 = F_153 ( F_154 () , struct V_123 ) ;
V_77 -> V_23 = NULL ;
V_77 -> V_81 = TRUE ;
V_77 -> V_82 . V_83 = V_82 ;
V_77 -> V_80 = F_136 ( V_149 ) ;
return V_77 ;
}
T_14
F_156 ( const char * V_23 , T_37 V_82 , const int V_149 )
{
struct V_123 * V_77 ;
F_12 ( F_80 ( V_12 , V_23 ) == NULL ) ;
V_77 = F_153 ( F_154 () , struct V_123 ) ;
V_77 -> V_23 = V_23 ;
V_77 -> V_81 = FALSE ;
V_77 -> V_82 . V_84 = V_82 ;
V_77 -> V_80 = F_136 ( V_149 ) ;
F_85 ( V_12 , ( T_1 ) V_23 ,
( T_1 ) V_77 ) ;
return V_77 ;
}
T_14
F_157 ( const char * V_23 , T_38 V_82 , const int V_149 )
{
struct V_123 * V_77 ;
F_12 ( F_80 ( V_12 , V_23 ) == NULL ) ;
V_77 = F_153 ( F_154 () , struct V_123 ) ;
V_77 -> V_23 = V_23 ;
V_77 -> V_81 = TRUE ;
V_77 -> V_82 . V_83 = V_82 ;
V_77 -> V_80 = F_136 ( V_149 ) ;
F_85 ( V_12 , ( T_1 ) V_23 ,
( T_1 ) V_77 ) ;
return V_77 ;
}
int
F_158 ( T_14 V_77 , T_4 * V_17 ,
T_8 * V_22 , T_15 * V_74 , void * V_1 )
{
int V_79 ;
F_12 ( V_77 != NULL ) ;
V_79 = F_70 ( V_77 , V_17 , V_22 , V_74 , TRUE , V_1 ) ;
return V_79 ;
}
int
F_159 ( T_14 V_77 , T_4 * V_17 ,
T_8 * V_22 , T_15 * V_74 , void * V_1 )
{
int V_79 ;
V_79 = F_158 ( V_77 , V_17 , V_22 , V_74 , V_1 ) ;
if ( V_79 == 0 ) {
F_12 ( V_15 -> V_80 != NULL ) ;
F_70 ( V_15 , V_17 , V_22 , V_74 , TRUE , NULL ) ;
return F_45 ( V_17 ) ;
}
return V_79 ;
}
int
F_63 ( T_14 V_77 , T_4 * V_17 ,
T_8 * V_22 , T_15 * V_74 )
{
return F_159 ( V_77 , V_17 , V_22 , V_74 , NULL ) ;
}
static void
F_160 ( const T_24 * V_140 ,
T_32 V_141 V_2 , const T_1 T_23 , const T_1 V_121 ,
T_1 T_2 V_2 )
{
T_9 V_158 = ( T_9 ) ( unsigned long ) T_23 ;
T_20 V_103 = F_79 ( V_140 ) ;
T_21 * V_109 ;
T_14 V_77 ;
T_18 V_159 ;
const T_24 * V_160 ;
F_12 ( V_103 ) ;
switch ( V_103 -> type ) {
case V_105 :
case V_106 :
case V_107 :
case V_108 :
V_109 = ( T_21 * ) V_121 ;
F_12 ( V_109 ) ;
V_77 = V_109 -> V_111 ;
F_12 ( V_77 ) ;
V_159 = F_150 ( V_77 ) ;
if ( V_159 != - 1 ) {
V_160 = F_73 ( V_159 ) ;
F_12 ( V_160 != NULL ) ;
printf ( L_25 , V_140 , V_158 , V_160 ) ;
}
break;
default:
break;
}
}
void
F_161 ( void )
{
F_115 ( F_160 , NULL ) ;
}
void
F_162 ( T_14 V_77 )
{
if ( ! V_161 )
V_161 = F_163 () ;
F_164 ( V_161 , V_77 ) ;
V_162 ++ ;
}
T_16
F_165 ( void )
{
T_5 V_115 ;
T_14 V_77 ;
for( V_115 = 0 ; V_115 < V_162 ; V_115 ++ ) {
V_77 = ( T_14 ) F_166 ( V_161 , V_115 ) ;
if ( V_77 -> V_80 != NULL
&& F_71 ( V_77 -> V_80 ) ) {
return TRUE ;
}
}
return FALSE ;
}
void
F_167 ( T_4 * V_17 , T_8 * V_22 , T_15 * V_74 )
{
T_5 V_115 ;
for( V_115 = 0 ; V_115 < V_162 ; V_115 ++ ) {
F_158 ( ( T_14 ) F_166 ( V_161 , V_115 ) ,
V_17 , V_22 , V_74 , NULL ) ;
}
}
