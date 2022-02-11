static void
F_1 ( T_1 V_1 , T_1 T_2 V_2 )
{
F_2 ( ( ( V_3 * ) V_1 ) -> V_4 ) ;
F_3 ( V_3 , V_1 ) ;
}
static void
F_4 ( void * V_1 )
{
T_3 * * V_5 = ( T_3 * * ) V_1 ;
F_5 ( * V_5 , F_1 , NULL ) ;
F_6 ( * V_5 ) ;
* V_5 = NULL ;
}
static void
F_7 ( void * V_1 )
{
struct V_6 * V_7 = (struct V_6 * ) V_1 ;
F_8 ( V_7 -> V_8 ) ;
F_6 ( V_7 -> V_9 ) ;
F_3 ( struct V_6 , V_1 ) ;
}
void
F_9 ( void )
{
V_10 = F_10 ( V_11 , V_12 ,
NULL , F_7 ) ;
V_13 = F_10 ( V_11 , V_12 ,
NULL , NULL ) ;
V_14 = F_10 ( V_11 , V_12 ,
NULL , F_4 ) ;
}
void
F_11 ( void )
{
V_15 = F_12 ( L_1 ) ;
F_13 ( V_15 != NULL ) ;
V_16 = F_12 ( L_2 ) ;
F_13 ( V_16 != NULL ) ;
V_17 = F_12 ( L_3 ) ;
F_13 ( V_17 != NULL ) ;
V_18 = F_14 ( L_4 ) ;
F_13 ( V_18 != - 1 ) ;
}
void
F_15 ( void )
{
F_8 ( V_10 ) ;
F_8 ( V_13 ) ;
F_8 ( V_14 ) ;
}
void
F_16 ( T_4 * V_19 , const T_5 V_20 )
{
if ( V_20 < F_17 ( V_19 ) ) {
F_18 ( V_19 , V_20 ) ;
}
}
void
F_19 ( void (* F_20)( void ) )
{
V_21 = F_21 ( V_21 , ( T_1 ) F_20 ) ;
}
static void
F_22 ( T_1 V_22 , T_1 T_6 V_2 )
{
T_7 F_20 = ( T_7 ) V_22 ;
(* F_20)() ;
}
void
F_23 ( void )
{
F_24 () ;
F_25 () ;
F_26 () ;
F_27 () ;
F_28 () ;
F_5 ( V_21 , & F_22 , NULL ) ;
F_29 () ;
F_30 () ;
}
void
F_31 ( void )
{
F_32 () ;
F_24 () ;
F_33 () ;
F_5 ( V_21 , & F_22 , NULL ) ;
F_34 () ;
F_35 () ;
F_36 () ;
F_37 () ;
}
void
F_38 ( T_7 F_20 )
{
V_23 = F_21 ( V_23 ,
( T_1 ) F_20 ) ;
}
static void
F_39 ( T_1 V_22 , T_1 T_6 V_2 )
{
T_7 F_20 = ( T_7 ) V_22 ;
(* F_20)() ;
}
void
F_40 ( void )
{
F_5 ( V_23 ,
& F_39 , NULL ) ;
}
void
F_41 ( T_8 * V_24 , T_4 * V_19 , const char * V_25 )
{
struct V_26 * V_27 ;
V_27 = F_42 ( struct V_26 ) ;
V_27 -> V_19 = V_19 ;
V_27 -> V_25 = F_43 ( V_25 ) ;
V_24 -> V_28 = F_44 ( V_24 -> V_28 , V_27 ) ;
}
void
F_45 ( T_8 * V_24 )
{
struct V_26 * V_27 ;
T_3 * V_29 ;
V_29 = F_46 ( V_24 -> V_28 ) ;
V_27 = (struct V_26 * ) V_29 -> V_1 ;
V_24 -> V_28 = F_47 ( V_24 -> V_28 , V_29 ) ;
F_2 ( V_27 -> V_25 ) ;
F_3 ( struct V_26 , V_27 ) ;
}
const char *
F_48 ( const struct V_26 * V_27 )
{
T_5 V_30 = F_49 ( V_27 -> V_19 ) ;
return F_50 ( L_5 , V_27 -> V_25 , V_30 ,
F_51 ( V_30 , L_6 , L_7 ) ) ;
}
T_4 *
F_52 ( const struct V_26 * V_27 )
{
return V_27 -> V_19 ;
}
void
F_53 ( T_8 * V_24 )
{
if ( V_24 -> V_28 ) {
T_3 * V_31 ;
for ( V_31 = V_24 -> V_28 ; V_31 ; V_31 = V_31 -> V_32 ) {
struct V_26 * V_27 = (struct V_26 * ) V_31 -> V_1 ;
F_2 ( V_27 -> V_25 ) ;
F_3 ( struct V_26 , V_27 ) ;
}
F_6 ( V_24 -> V_28 ) ;
V_24 -> V_28 = NULL ;
}
}
void
F_54 ( T_8 * V_24 , T_9 V_33 )
{
if ( V_33 != F_55 ( V_24 ) ) {
V_24 -> V_34 = F_21 ( V_24 -> V_34 , F_56 ( V_33 ) ) ;
}
}
void
F_57 ( void (* F_20)( void ) )
{
V_35 = F_21 ( V_35 ,
( T_1 ) F_20 ) ;
}
static void
F_58 ( T_1 V_22 , T_1 T_6 V_2 )
{
T_7 F_20 = ( T_7 ) V_22 ;
(* F_20)() ;
}
void
F_59 ( void )
{
F_5 ( V_35 ,
& F_58 , NULL ) ;
}
void
F_60 ( T_10 * V_36 , int V_37 ,
struct V_38 * V_39 , T_4 * V_19 , T_11 * V_40 , T_12 * V_41 )
{
const char * volatile V_42 ;
switch ( V_39 -> V_43 ) {
case V_44 :
V_42 = L_8 ;
break;
case V_45 :
V_42 = L_9 ;
break;
case V_46 :
V_42 = L_10 ;
break;
default:
F_61 () ;
break;
}
if ( V_41 != NULL )
F_62 ( V_41 , V_36 -> V_47 ) ;
V_36 -> V_48 . V_49 = V_36 -> V_47 ;
V_36 -> V_48 . V_50 = L_11 ;
V_36 -> V_48 . V_41 = V_41 ;
V_36 -> V_48 . V_40 = V_40 ;
V_36 -> V_48 . V_37 = V_37 ;
V_36 -> V_48 . V_39 = V_39 ;
V_36 -> V_48 . V_51 = & V_39 -> V_51 ;
V_36 -> V_48 . V_52 . type = V_53 ;
V_36 -> V_48 . V_54 . type = V_53 ;
V_36 -> V_48 . V_55 . type = V_53 ;
V_36 -> V_48 . V_56 . type = V_53 ;
V_36 -> V_48 . V_27 . type = V_53 ;
V_36 -> V_48 . V_57 . type = V_53 ;
V_36 -> V_48 . V_58 = V_59 ;
V_36 -> V_48 . V_60 = L_6 ;
V_36 -> V_48 . V_61 = V_62 ;
V_36 -> V_48 . V_63 = V_64 ;
V_36 -> V_48 . V_65 = V_66 ;
V_36 -> V_48 . V_67 = V_68 ;
V_36 -> V_48 . V_69 = F_63 ( V_36 -> V_48 . V_70 ) ;
V_36 -> V_19 = V_19 ;
F_64 ( V_36 -> V_47 , V_40 , V_40 -> V_71 , & V_36 -> V_48 . V_72 ) ;
if ( V_40 -> V_73 . V_74 )
V_36 -> V_48 . V_75 = F_65 ( V_36 -> V_47 , V_40 ) ;
else if ( V_40 -> V_73 . V_76 )
V_36 -> V_48 . V_75 = V_39 -> V_77 ;
F_66 ( ( L_12 , V_40 -> V_78 ) ) ;
F_67 {
F_41 ( & V_36 -> V_48 , V_36 -> V_19 , V_42 ) ;
F_68 ( V_15 , V_36 -> V_19 , & V_36 -> V_48 , V_36 -> V_79 ) ;
}
F_69 (BoundsError) {
F_61 () ;
}
F_70 (FragmentBoundsError, ReportedBoundsError) {
F_71 ( V_36 -> V_79 , V_18 , V_36 -> V_19 , 0 , 0 ,
L_13 ,
V_42 ) ;
}
V_80 ;
F_66 ( ( L_14 , V_40 -> V_78 ) ) ;
V_40 -> V_73 . V_81 = 1 ;
}
void
F_72 ( T_10 * V_36 , struct V_38 * V_39 ,
T_4 * V_19 , T_11 * V_40 , T_12 * V_41 )
{
if ( V_41 != NULL )
F_62 ( V_41 , V_36 -> V_47 ) ;
V_36 -> V_48 . V_49 = V_36 -> V_47 ;
V_36 -> V_48 . V_50 = L_15 ;
V_36 -> V_48 . V_41 = V_41 ;
V_36 -> V_48 . V_40 = V_40 ;
V_36 -> V_48 . V_37 = V_82 ;
V_36 -> V_48 . V_39 = V_39 ;
V_36 -> V_48 . V_51 = & V_39 -> V_51 ;
V_36 -> V_48 . V_52 . type = V_53 ;
V_36 -> V_48 . V_54 . type = V_53 ;
V_36 -> V_48 . V_55 . type = V_53 ;
V_36 -> V_48 . V_56 . type = V_53 ;
V_36 -> V_48 . V_27 . type = V_53 ;
V_36 -> V_48 . V_57 . type = V_53 ;
V_36 -> V_48 . V_58 = V_59 ;
V_36 -> V_48 . V_60 = L_6 ;
V_36 -> V_48 . V_61 = V_62 ;
V_36 -> V_48 . V_63 = V_64 ;
V_36 -> V_48 . V_65 = V_66 ;
V_36 -> V_48 . V_67 = V_68 ;
V_36 -> V_48 . V_69 = F_63 ( V_36 -> V_48 . V_70 ) ;
V_36 -> V_19 = V_19 ;
F_64 ( V_36 -> V_47 , V_40 , V_40 -> V_71 , & V_36 -> V_48 . V_72 ) ;
if ( V_40 -> V_73 . V_74 )
V_36 -> V_48 . V_75 = F_65 ( V_36 -> V_47 , V_40 ) ;
else if ( V_40 -> V_73 . V_76 )
V_36 -> V_48 . V_75 = V_39 -> V_77 ;
F_66 ( ( L_16 , V_40 -> V_78 ) ) ;
F_67 {
F_41 ( & V_36 -> V_48 , V_36 -> V_19 , L_17 ) ;
F_68 ( V_16 , V_36 -> V_19 , & V_36 -> V_48 , V_36 -> V_79 ) ;
}
F_69 (BoundsError) {
F_61 () ;
}
F_70 (FragmentBoundsError, ReportedBoundsError) {
F_71 ( V_36 -> V_79 , V_18 , V_36 -> V_19 , 0 , 0 ,
L_18 ) ;
}
V_80 ;
F_66 ( ( L_19 , V_40 -> V_78 ) ) ;
V_40 -> V_73 . V_81 = 1 ;
}
static int
F_73 ( T_13 V_83 , T_4 * V_19 ,
T_8 * V_24 , T_14 * V_79 , void * V_1 )
{
const char * V_84 ;
int V_85 ;
V_84 = V_24 -> V_50 ;
if ( V_83 -> V_86 != NULL ) {
V_24 -> V_50 =
F_74 ( V_83 -> V_86 ) ;
}
if ( V_83 -> V_87 ) {
F_66 ( ( L_20 , V_83 -> V_25 ) ) ;
V_85 = (* V_83 -> V_88 . V_89 )( V_19 , V_24 , V_79 , V_1 ) ;
F_66 ( ( L_21 , V_83 -> V_25 ) ) ;
} else {
F_66 ( ( L_22 , V_83 -> V_25 ) ) ;
(* V_83 -> V_88 . V_90 )( V_19 , V_24 , V_79 ) ;
F_66 ( ( L_23 , V_83 -> V_25 ) ) ;
V_85 = F_49 ( V_19 ) ;
if ( V_85 == 0 ) {
V_85 = 1 ;
}
}
V_24 -> V_50 = V_84 ;
return V_85 ;
}
static int
F_75 ( T_13 V_83 , T_4 * V_19 , T_8 * V_91 ,
T_14 * V_79 , T_15 V_92 , void * V_1 )
{
T_8 * V_24 = V_91 ;
const char * V_84 ;
T_16 V_93 ;
int V_85 ;
T_5 V_94 = 0 ;
if ( V_83 -> V_86 != NULL &&
! F_76 ( V_83 -> V_86 ) ) {
return 0 ;
}
V_84 = V_24 -> V_50 ;
V_93 = V_24 -> V_95 ;
V_94 = F_77 ( V_24 -> V_69 ) ;
V_24 -> V_93 = V_93 ;
V_24 -> V_95 = V_93 - ( V_93 > 0 ) ;
if ( V_83 -> V_86 != NULL ) {
V_24 -> V_50 =
F_74 ( V_83 -> V_86 ) ;
if ( V_92 ) {
V_24 -> V_96 ++ ;
F_78 ( V_24 -> V_69 , F_79 ( F_80 ( V_83 -> V_86 ) ) ) ;
}
}
if ( V_24 -> V_73 . V_97 ) {
V_85 = F_81 ( V_83 , V_19 , V_24 , V_79 , V_1 ) ;
} else {
V_85 = F_73 ( V_83 , V_19 , V_24 , V_79 , V_1 ) ;
}
if ( V_85 == 0 ) {
while ( F_77 ( V_24 -> V_69 ) > V_94 ) {
F_82 ( V_24 -> V_69 , F_83 ( V_24 -> V_69 ) ) ;
}
}
V_24 -> V_50 = V_84 ;
V_24 -> V_95 = V_93 ;
return V_85 ;
}
static int
F_81 ( T_13 V_83 , T_4 * V_19 ,
T_8 * V_91 , T_14 * V_79 , void * V_1 )
{
T_8 * V_24 = V_91 ;
const char * V_84 ;
T_16 V_93 ;
volatile int V_85 = 0 ;
T_15 V_98 ;
T_17 V_99 ;
T_17 V_100 ;
T_17 V_101 ;
T_17 V_102 ;
T_17 V_103 ;
T_17 V_104 ;
V_84 = V_24 -> V_50 ;
V_93 = V_24 -> V_95 ;
V_98 = F_84 ( V_24 -> V_41 ) ;
F_85 ( V_24 -> V_41 , FALSE ) ;
V_99 = V_24 -> V_52 ;
V_100 = V_24 -> V_54 ;
V_101 = V_24 -> V_55 ;
V_102 = V_24 -> V_56 ;
V_103 = V_24 -> V_27 ;
V_104 = V_24 -> V_57 ;
F_67 {
V_85 = F_73 ( V_83 , V_19 , V_24 , V_79 , V_1 ) ;
}
F_69 (BoundsError) {
F_85 ( V_24 -> V_41 , V_98 ) ;
V_24 -> V_52 = V_99 ;
V_24 -> V_54 = V_100 ;
V_24 -> V_55 = V_101 ;
V_24 -> V_56 = V_102 ;
V_24 -> V_27 = V_103 ;
V_24 -> V_57 = V_104 ;
V_24 -> V_50 = V_84 ;
V_24 -> V_95 = V_93 ;
V_105 ;
}
F_70 (FragmentBoundsError, ReportedBoundsError) {
V_85 = F_49 ( V_19 ) ;
}
V_80 ;
F_85 ( V_24 -> V_41 , V_98 ) ;
V_24 -> V_52 = V_99 ;
V_24 -> V_54 = V_100 ;
V_24 -> V_55 = V_101 ;
V_24 -> V_56 = V_102 ;
V_24 -> V_27 = V_103 ;
V_24 -> V_57 = V_104 ;
V_24 -> V_106 = 0 ;
return V_85 ;
}
T_18
F_86 ( const char * V_25 )
{
return ( T_18 ) F_87 ( V_10 , V_25 ) ;
}
static T_19 *
F_88 ( T_18 V_107 , const T_9 V_108 )
{
switch ( V_107 -> type ) {
case V_109 :
case V_110 :
case V_111 :
case V_112 :
break;
default:
F_61 () ;
}
return ( T_19 * ) F_87 ( V_107 -> V_8 ,
F_56 ( V_108 ) ) ;
}
void
F_89 ( const char * V_25 , const T_9 V_108 , T_13 V_83 )
{
T_18 V_107 ;
T_19 * V_113 ;
V_107 = F_86 ( V_25 ) ;
if ( V_107 == NULL ) {
fprintf ( V_114 , L_24 ,
V_25 ) ;
fprintf ( V_114 , L_25 ,
F_90 ( V_83 -> V_86 ) ) ;
if ( getenv ( L_26 ) != NULL )
abort () ;
return;
}
F_13 ( V_83 != NULL ) ;
switch ( V_107 -> type ) {
case V_109 :
case V_110 :
case V_111 :
case V_112 :
break;
default:
F_61 () ;
}
#if 0
dissector_add_uint_sanity_check(name, pattern, handle, sub_dissectors);
#endif
V_113 = ( T_19 * ) F_91 ( sizeof ( T_19 ) ) ;
V_113 -> V_115 = V_83 ;
V_113 -> V_116 = V_113 -> V_115 ;
F_92 ( V_107 -> V_8 ,
F_56 ( V_108 ) , ( T_1 ) V_113 ) ;
F_93 ( V_25 , V_83 ) ;
}
void F_94 ( const char * V_117 , T_20 * V_118 ,
T_13 V_83 )
{
T_9 V_119 , V_120 ;
if ( V_118 ) {
for ( V_119 = 0 ; V_119 < V_118 -> V_121 ; V_119 ++ ) {
for ( V_120 = V_118 -> V_122 [ V_119 ] . V_123 ; V_120 <= V_118 -> V_122 [ V_119 ] . V_124 ; V_120 ++ )
F_89 ( V_117 , V_120 , V_83 ) ;
}
}
}
void
F_95 ( const char * V_25 , const T_9 V_108 ,
T_13 V_83 V_2 )
{
T_18 V_107 = F_86 ( V_25 ) ;
T_19 * V_113 ;
F_13 ( V_107 ) ;
V_113 = F_88 ( V_107 , V_108 ) ;
if ( V_113 != NULL ) {
F_96 ( V_107 -> V_8 ,
F_56 ( V_108 ) ) ;
}
}
void F_97 ( const char * V_117 , T_20 * V_118 ,
T_13 V_83 )
{
T_9 V_119 , V_120 ;
if ( V_118 ) {
for ( V_119 = 0 ; V_119 < V_118 -> V_121 ; V_119 ++ ) {
for ( V_120 = V_118 -> V_122 [ V_119 ] . V_123 ; V_120 <= V_118 -> V_122 [ V_119 ] . V_124 ; V_120 ++ )
F_95 ( V_117 , V_120 , V_83 ) ;
}
}
}
static T_15
F_98 ( T_1 T_21 V_2 , T_1 V_125 , T_1 T_2 )
{
T_19 * V_113 = ( T_19 * ) V_125 ;
T_13 V_83 = ( T_13 ) T_2 ;
return ( F_80 ( V_113 -> V_115 -> V_86 ) == F_80 ( V_83 -> V_86 ) ) ;
}
void F_99 ( const char * V_25 , T_13 V_83 )
{
T_18 V_107 = F_86 ( V_25 ) ;
F_13 ( V_107 ) ;
F_100 ( V_107 -> V_8 , F_98 , V_83 ) ;
}
void
F_101 ( const char * V_25 , const T_9 V_108 , T_13 V_83 )
{
T_18 V_107 = F_86 ( V_25 ) ;
T_19 * V_113 ;
F_13 ( V_107 ) ;
V_113 = F_88 ( V_107 , V_108 ) ;
if ( V_113 != NULL ) {
V_113 -> V_115 = V_83 ;
return;
}
if ( V_83 == NULL )
return;
V_113 = ( T_19 * ) F_91 ( sizeof ( T_19 ) ) ;
V_113 -> V_116 = NULL ;
V_113 -> V_115 = V_83 ;
F_92 ( V_107 -> V_8 ,
F_56 ( V_108 ) , ( T_1 ) V_113 ) ;
}
void
F_102 ( const char * V_25 , const T_9 V_108 )
{
T_18 V_107 = F_86 ( V_25 ) ;
T_19 * V_113 ;
F_13 ( V_107 ) ;
V_113 = F_88 ( V_107 , V_108 ) ;
if ( V_113 == NULL )
return;
if ( V_113 -> V_116 != NULL ) {
V_113 -> V_115 = V_113 -> V_116 ;
} else {
F_96 ( V_107 -> V_8 ,
F_56 ( V_108 ) ) ;
}
}
T_15
F_103 ( T_18 V_107 , const T_9 V_126 ,
T_4 * V_19 , T_8 * V_24 , T_14 * V_79 ,
const T_15 V_92 , void * V_1 )
{
T_19 * V_113 ;
struct V_127 * V_83 ;
T_9 V_128 ;
int V_85 ;
V_113 = F_88 ( V_107 , V_126 ) ;
if ( V_113 != NULL ) {
V_83 = V_113 -> V_115 ;
if ( V_83 == NULL ) {
return FALSE ;
}
V_128 = V_24 -> V_129 ;
V_24 -> V_129 = V_126 ;
V_85 = F_75 ( V_83 , V_19 , V_24 , V_79 , V_92 , V_1 ) ;
V_24 -> V_129 = V_128 ;
return V_85 != 0 ;
}
return FALSE ;
}
T_15
F_104 ( T_18 V_107 , const T_9 V_126 ,
T_4 * V_19 , T_8 * V_24 , T_14 * V_79 )
{
return F_103 ( V_107 , V_126 , V_19 , V_24 , V_79 , TRUE , NULL ) ;
}
T_13
F_105 ( T_18 const V_107 , const T_9 V_126 )
{
T_19 * V_113 ;
V_113 = F_88 ( V_107 , V_126 ) ;
if ( V_113 != NULL )
return V_113 -> V_115 ;
else
return NULL ;
}
T_13
F_106 ( const char * V_25 , const T_9 V_126 )
{
T_18 V_107 = F_86 ( V_25 ) ;
if ( V_107 != NULL ) {
T_19 * V_113 = F_88 ( V_107 , V_126 ) ;
if ( V_113 != NULL )
return V_113 -> V_116 ;
}
return NULL ;
}
static T_19 *
F_107 ( T_18 const V_107 , const T_22 * V_108 )
{
switch ( V_107 -> type ) {
case V_130 :
case V_131 :
case V_132 :
break;
default:
F_61 () ;
}
return ( T_19 * ) F_87 ( V_107 -> V_8 , V_108 ) ;
}
void
F_108 ( const char * V_25 , const T_22 * V_108 ,
T_13 V_83 )
{
T_18 V_107 = F_86 ( V_25 ) ;
T_19 * V_113 ;
if ( V_107 == NULL ) {
fprintf ( V_114 , L_24 ,
V_25 ) ;
fprintf ( V_114 , L_25 ,
F_90 ( V_83 -> V_86 ) ) ;
if ( getenv ( L_26 ) != NULL )
abort () ;
return;
}
F_13 ( V_83 != NULL ) ;
switch ( V_107 -> type ) {
case V_130 :
case V_131 :
case V_132 :
break;
default:
F_61 () ;
}
V_113 = ( T_19 * ) F_91 ( sizeof ( T_19 ) ) ;
V_113 -> V_115 = V_83 ;
V_113 -> V_116 = V_113 -> V_115 ;
F_92 ( V_107 -> V_8 , ( T_1 ) F_43 ( V_108 ) ,
( T_1 ) V_113 ) ;
F_93 ( V_25 , V_83 ) ;
}
void
F_109 ( const char * V_25 , const T_22 * V_108 ,
T_13 V_83 V_2 )
{
T_18 V_107 = F_86 ( V_25 ) ;
T_19 * V_113 ;
F_13 ( V_107 ) ;
V_113 = F_107 ( V_107 , V_108 ) ;
if ( V_113 != NULL ) {
F_96 ( V_107 -> V_8 , V_108 ) ;
}
}
void
F_110 ( const char * V_25 , const T_22 * V_108 ,
T_13 V_83 )
{
T_18 V_107 = F_86 ( V_25 ) ;
T_19 * V_113 ;
F_13 ( V_107 ) ;
V_113 = F_107 ( V_107 , V_108 ) ;
if ( V_113 != NULL ) {
V_113 -> V_115 = V_83 ;
return;
}
if ( V_83 == NULL )
return;
V_113 = ( T_19 * ) F_91 ( sizeof ( T_19 ) ) ;
V_113 -> V_116 = NULL ;
V_113 -> V_115 = V_83 ;
F_92 ( V_107 -> V_8 , ( T_1 ) F_43 ( V_108 ) ,
( T_1 ) V_113 ) ;
}
void
F_111 ( const char * V_25 , const T_22 * V_108 )
{
T_18 V_107 = F_86 ( V_25 ) ;
T_19 * V_113 ;
F_13 ( V_107 ) ;
V_113 = F_107 ( V_107 , V_108 ) ;
if ( V_113 == NULL )
return;
if ( V_113 -> V_116 != NULL ) {
V_113 -> V_115 = V_113 -> V_116 ;
} else {
F_96 ( V_107 -> V_8 , V_108 ) ;
}
}
T_15
F_112 ( T_18 V_107 , const T_22 * string ,
T_4 * V_19 , T_8 * V_24 , T_14 * V_79 , void * V_1 )
{
T_19 * V_113 ;
struct V_127 * V_83 ;
int V_85 ;
const T_22 * V_133 ;
if ( ! string ) return FALSE ;
V_113 = F_107 ( V_107 , string ) ;
if ( V_113 != NULL ) {
V_83 = V_113 -> V_115 ;
if ( V_83 == NULL ) {
return FALSE ;
}
V_133 = V_24 -> V_134 ;
V_24 -> V_134 = string ;
V_85 = F_75 ( V_83 , V_19 , V_24 , V_79 , TRUE , V_1 ) ;
V_24 -> V_134 = V_133 ;
return V_85 != 0 ;
}
return FALSE ;
}
T_13
F_113 ( T_18 V_107 ,
const T_22 * string )
{
T_19 * V_113 ;
V_113 = F_107 ( V_107 , string ) ;
if ( V_113 != NULL )
return V_113 -> V_115 ;
else
return NULL ;
}
T_13
F_114 ( const char * V_25 , const T_22 * string )
{
T_18 V_107 = F_86 ( V_25 ) ;
if ( V_107 != NULL ) {
T_19 * V_113 = F_107 ( V_107 , string ) ;
if ( V_113 != NULL )
return V_113 -> V_116 ;
}
return NULL ;
}
T_13
F_115 ( T_19 * V_113 )
{
return V_113 -> V_115 ;
}
static T_23
F_116 ( T_24 V_135 , T_24 V_136 )
{
const struct V_127 * V_137 = ( const struct V_127 * ) V_135 ;
const struct V_127 * V_138 = ( const struct V_127 * ) V_136 ;
const char * V_139 , * V_140 ;
T_23 V_85 ;
if ( V_137 -> V_86 == NULL )
V_139 = L_6 ;
else
V_139 = F_117 ( F_80 ( V_137 -> V_86 ) ) ;
if ( V_138 -> V_86 == NULL )
V_140 = L_6 ;
else
V_140 = F_117 ( F_80 ( V_138 -> V_86 ) ) ;
V_85 = strcmp ( V_139 , V_140 ) ;
return V_85 ;
}
void
F_93 ( const char * V_25 , T_13 V_83 )
{
T_18 V_107 = F_86 ( V_25 ) ;
T_3 * V_141 ;
if ( V_107 == NULL ) {
fprintf ( V_114 , L_24 ,
V_25 ) ;
fprintf ( V_114 , L_25 ,
F_90 ( V_83 -> V_86 ) ) ;
if ( getenv ( L_26 ) != NULL )
abort () ;
return;
}
V_141 = F_118 ( V_107 -> V_9 , ( T_1 ) V_83 ) ;
if ( V_141 != NULL ) {
return;
}
V_107 -> V_9 =
F_119 ( V_107 -> V_9 , ( T_1 ) V_83 , ( V_142 ) F_116 ) ;
}
T_13
F_120 ( T_19 * V_113 )
{
return V_113 -> V_116 ;
}
T_3 *
F_121 ( T_18 V_6 ) {
if ( ! V_6 ) return NULL ;
return V_6 -> V_9 ;
}
T_25
F_122 ( T_18 V_6 ) {
if ( ! V_6 ) return V_143 ;
return V_6 -> type ;
}
static void
F_123 ( T_1 T_21 , T_1 V_125 , T_1 T_2 )
{
T_26 * V_144 ;
T_19 * V_113 ;
F_13 ( V_125 ) ;
F_13 ( T_2 ) ;
V_113 = ( T_19 * ) V_125 ;
if ( V_113 -> V_115 == NULL ||
V_113 -> V_115 -> V_86 == NULL ) {
return;
}
V_144 = ( T_26 * ) T_2 ;
V_144 -> V_145 ( V_144 -> V_146 , V_144 -> V_147 , T_21 , V_125 ,
V_144 -> V_148 ) ;
}
static void
F_124 ( T_1 T_21 , T_1 V_125 , T_1 T_2 )
{
T_18 V_107 ;
T_26 * V_144 ;
F_13 ( V_125 ) ;
F_13 ( T_2 ) ;
V_107 = ( T_18 ) V_125 ;
V_144 = ( T_26 * ) T_2 ;
V_144 -> V_146 = ( T_22 * ) T_21 ;
V_144 -> V_147 = F_125 ( V_144 -> V_146 ) ;
F_126 ( V_107 -> V_8 , V_144 -> V_149 , V_144 ) ;
}
static void
F_127 ( T_27 F_20 ,
T_1 T_2 )
{
T_26 V_144 ;
V_144 . V_148 = T_2 ;
V_144 . V_145 = F_20 ;
V_144 . V_149 = F_123 ;
F_126 ( V_10 , F_124 , & V_144 ) ;
}
void
F_128 ( const char * V_146 ,
T_27 F_20 ,
T_1 T_2 )
{
T_26 V_144 ;
T_18 V_107 = F_86 ( V_146 ) ;
V_144 . V_146 = V_146 ;
V_144 . V_147 = V_107 -> type ;
V_144 . V_145 = F_20 ;
V_144 . V_148 = T_2 ;
F_126 ( V_107 -> V_8 , F_123 , & V_144 ) ;
}
void
F_129 ( const char * V_146 ,
T_28 F_20 ,
T_1 T_2 )
{
T_18 V_107 = F_86 ( V_146 ) ;
T_3 * V_150 ;
for ( V_150 = V_107 -> V_9 ; V_150 != NULL ;
V_150 = F_130 ( V_150 ) )
F_20 ( V_146 , V_150 -> V_1 , T_2 ) ;
}
static void
F_131 ( T_1 T_21 , T_1 V_125 , T_1 T_2 )
{
T_19 * V_113 ;
T_26 * V_144 ;
F_13 ( V_125 ) ;
F_13 ( T_2 ) ;
V_113 = ( T_19 * ) V_125 ;
if ( V_113 -> V_116 == V_113 -> V_115 ) {
return;
}
V_144 = ( T_26 * ) T_2 ;
V_144 -> V_145 ( V_144 -> V_146 , V_144 -> V_147 , T_21 , V_125 ,
V_144 -> V_148 ) ;
}
void
F_132 ( T_27 F_20 ,
T_1 T_2 )
{
T_26 V_144 ;
V_144 . V_148 = T_2 ;
V_144 . V_145 = F_20 ;
V_144 . V_149 = F_131 ;
F_126 ( V_10 , F_124 , & V_144 ) ;
}
void
F_133 ( const char * V_146 ,
T_27 F_20 ,
T_1 T_2 )
{
T_26 V_144 ;
T_18 V_107 = F_86 ( V_146 ) ;
V_144 . V_146 = V_146 ;
V_144 . V_147 = V_107 -> type ;
V_144 . V_145 = F_20 ;
V_144 . V_148 = T_2 ;
F_126 ( V_107 -> V_8 ,
F_131 , & V_144 ) ;
}
static void
F_134 ( T_1 T_21 , const T_1 V_125 , const T_1 T_2 )
{
T_18 V_7 ;
T_29 * V_144 ;
V_7 = ( T_18 ) V_125 ;
V_144 = ( T_29 * ) T_2 ;
(* V_144 -> V_145 )( ( T_22 * ) T_21 , V_7 -> V_151 , V_144 -> V_148 ) ;
}
static void
F_135 ( T_1 T_21 , T_1 T_2 )
{
T_18 V_7 ;
T_29 * V_144 ;
V_7 = ( T_18 ) F_87 ( V_10 , T_21 ) ;
V_144 = ( T_29 * ) T_2 ;
(* V_144 -> V_145 )( ( T_22 * ) T_21 , V_7 -> V_151 , V_144 -> V_148 ) ;
}
void
F_136 ( T_30 F_20 ,
T_1 T_2 ,
V_142 V_152 )
{
T_29 V_144 ;
T_31 * V_5 ;
V_144 . V_148 = T_2 ;
V_144 . V_145 = F_20 ;
if ( V_152 != NULL )
{
V_5 = F_137 ( V_10 ) ;
V_5 = F_138 ( V_5 , V_152 ) ;
F_139 ( V_5 , F_135 , & V_144 ) ;
F_140 ( V_5 ) ;
}
else
{
F_126 ( V_10 , F_134 , & V_144 ) ;
}
}
T_18
F_141 ( const char * V_25 , const char * V_151 , const T_25 type ,
const int V_153 )
{
T_18 V_107 ;
if( F_87 ( V_10 , V_25 ) ) {
F_142 ( L_27 , V_25 , V_151 ) ;
}
V_107 = F_42 ( struct V_6 ) ;
switch ( type ) {
case V_109 :
case V_110 :
case V_111 :
case V_112 :
V_107 -> V_8 = F_10 ( V_154 ,
V_155 ,
NULL ,
& F_2 ) ;
break;
case V_130 :
case V_131 :
case V_132 :
V_107 -> V_8 = F_10 ( V_11 ,
V_12 ,
& F_2 ,
& F_2 ) ;
break;
default:
F_61 () ;
}
V_107 -> V_9 = NULL ;
V_107 -> V_151 = V_151 ;
V_107 -> type = type ;
V_107 -> V_153 = V_153 ;
F_92 ( V_10 , ( T_1 ) V_25 , ( T_1 ) V_107 ) ;
return V_107 ;
}
const char *
F_143 ( const char * V_25 )
{
T_18 V_107 = F_86 ( V_25 ) ;
if ( ! V_107 ) return NULL ;
return V_107 -> V_151 ;
}
T_25
F_125 ( const char * V_25 )
{
T_18 V_107 = F_86 ( V_25 ) ;
if ( ! V_107 ) return V_143 ;
return V_107 -> type ;
}
int
F_144 ( const char * V_25 )
{
T_18 V_107 = F_86 ( V_25 ) ;
if ( ! V_107 ) return 0 ;
return V_107 -> V_153 ;
}
static T_32 *
F_145 ( const char * V_25 )
{
return ( T_32 * ) F_87 ( V_14 , V_25 ) ;
}
T_15
F_146 ( const T_22 * V_25 ) {
return ( F_145 ( V_25 ) != NULL ) ;
}
void
F_147 ( const char * V_25 , T_33 V_88 , const int V_156 )
{
T_32 * V_107 = F_145 ( V_25 ) ;
const char * V_157 ;
V_3 * V_158 ;
if ( V_107 == NULL ) {
fprintf ( V_114 , L_24 ,
V_25 ) ;
V_157 = F_148 ( V_156 ) ;
if ( V_157 != NULL ) {
fprintf ( V_114 , L_25 ,
V_157 ) ;
}
if ( getenv ( L_26 ) != NULL )
abort () ;
return;
}
V_158 = F_42 ( V_3 ) ;
V_158 -> V_88 = V_88 ;
V_158 -> V_86 = F_149 ( V_156 ) ;
V_158 -> V_4 = F_43 ( V_25 ) ;
V_158 -> V_159 = TRUE ;
* V_107 = F_21 ( * V_107 , ( T_1 ) V_158 ) ;
}
static int
F_150 ( T_24 V_137 , T_24 V_138 ) {
const V_3 * V_160 = ( const V_3 * ) V_137 ;
const V_3 * V_161 = ( const V_3 * ) V_138 ;
return ( V_160 -> V_88 == V_161 -> V_88 ) &&
( V_160 -> V_86 == V_161 -> V_86 ) ? 0 : 1 ;
}
void
F_151 ( const char * V_25 , T_33 V_88 , const int V_156 ) {
T_32 * V_107 = F_145 ( V_25 ) ;
V_3 V_158 ;
T_3 * V_162 ;
F_13 ( V_107 != NULL ) ;
V_158 . V_88 = V_88 ;
V_158 . V_86 = F_149 ( V_156 ) ;
V_162 = F_152 ( * V_107 , ( T_1 ) & V_158 , F_150 ) ;
if ( V_162 ) {
F_2 ( ( ( V_3 * ) ( V_162 -> V_1 ) ) -> V_4 ) ;
F_3 ( V_3 , V_162 -> V_1 ) ;
* V_107 = F_47 ( * V_107 , V_162 ) ;
}
}
void
F_153 ( const char * V_25 , T_33 V_88 , const int V_156 , const T_15 V_159 ) {
T_32 * V_107 = F_145 ( V_25 ) ;
T_3 * V_162 ;
V_3 V_158 ;
F_13 ( V_107 != NULL ) ;
V_158 . V_88 = V_88 ;
V_158 . V_86 = F_149 ( V_156 ) ;
V_162 = F_152 ( * V_107 , ( T_1 ) & V_158 , F_150 ) ;
if ( V_162 ) {
V_3 * V_163 ;
V_163 = ( V_3 * ) V_162 -> V_1 ;
V_163 -> V_159 = V_159 ;
}
}
T_15
F_154 ( T_32 V_107 , T_4 * V_19 ,
T_8 * V_24 , T_14 * V_79 , V_3 * * V_164 , void * V_1 )
{
T_15 V_165 ;
const char * V_166 ;
const char * V_167 ;
T_3 * V_141 ;
T_16 V_93 ;
T_5 V_94 = 0 ;
V_3 * V_158 ;
int V_168 ;
V_93 = V_24 -> V_95 ;
V_24 -> V_93 = V_93 ;
V_24 -> V_95 = V_93 - ( V_93 > 0 ) ;
V_165 = FALSE ;
V_166 = V_24 -> V_50 ;
V_167 = V_24 -> V_169 ;
V_94 = F_77 ( V_24 -> V_69 ) ;
* V_164 = NULL ;
for ( V_141 = V_107 ; V_141 != NULL ; V_141 = F_130 ( V_141 ) ) {
V_24 -> V_95 = V_93 - ( V_93 > 0 ) ;
V_158 = ( V_3 * ) V_141 -> V_1 ;
if ( V_158 -> V_86 != NULL &&
( ! F_76 ( V_158 -> V_86 ) || ( V_158 -> V_159 == FALSE ) ) ) {
continue;
}
V_168 = F_80 ( V_158 -> V_86 ) ;
if ( V_158 -> V_86 != NULL ) {
V_24 -> V_50 =
F_74 ( V_158 -> V_86 ) ;
F_78 ( V_24 -> V_69 , F_79 ( V_168 ) ) ;
}
V_24 -> V_169 = V_158 -> V_4 ;
F_66 ( ( L_28 , F_117 ( V_168 ) ) ) ;
if ( ( V_158 -> V_88 ) ( V_19 , V_24 , V_79 , V_1 ) ) {
F_66 ( ( L_29 , F_117 ( V_168 ) ) ) ;
* V_164 = V_158 ;
V_165 = TRUE ;
break;
} else {
F_66 ( ( L_30 , F_117 ( V_168 ) ) ) ;
while ( F_77 ( V_24 -> V_69 ) > V_94 ) {
F_82 ( V_24 -> V_69 , F_83 ( V_24 -> V_69 ) ) ;
}
}
}
V_24 -> V_50 = V_166 ;
V_24 -> V_169 = V_167 ;
V_24 -> V_95 = V_93 ;
return V_165 ;
}
static void
F_155 ( const T_22 * V_146 , const T_1 V_125 , const T_1 T_2 V_2 )
{
T_32 V_107 = * ( T_32 * ) V_125 ;
T_3 * V_141 ;
V_3 * V_158 ;
for ( V_141 = V_107 ; V_141 != NULL ; V_141 = F_130 ( V_141 ) ) {
V_158 = ( V_3 * ) V_141 -> V_1 ;
if ( V_158 -> V_86 != NULL ) {
printf ( L_31 ,
V_146 ,
F_117 ( F_80 ( V_158 -> V_86 ) ) ,
( F_76 ( V_158 -> V_86 ) && V_158 -> V_159 ) ? 'T' : 'F' ) ;
}
}
}
static void
F_156 ( T_1 T_21 , const T_1 V_125 , const T_1 T_2 )
{
T_34 * V_144 ;
V_144 = ( T_34 * ) T_2 ;
(* V_144 -> V_145 )( ( T_22 * ) T_21 , V_125 , V_144 -> V_148 ) ;
}
void
F_157 ( T_35 F_20 ,
T_1 T_2 )
{
T_34 V_144 ;
V_144 . V_148 = T_2 ;
V_144 . V_145 = F_20 ;
F_126 ( V_14 , F_156 , & V_144 ) ;
}
void
F_158 ( void )
{
F_157 ( F_155 , NULL ) ;
}
void
F_159 ( const char * V_25 , T_32 * V_107 )
{
F_13 ( F_87 ( V_14 , V_25 ) == NULL ) ;
* V_107 = NULL ;
F_92 ( V_14 , ( T_1 ) V_25 ,
( T_1 ) V_107 ) ;
}
const char *
F_160 ( const T_13 V_83 )
{
if ( V_83 == NULL || V_83 -> V_86 == NULL ) {
return NULL ;
}
return F_90 ( V_83 -> V_86 ) ;
}
const char *
F_161 ( const T_13 V_83 )
{
if ( V_83 -> V_86 == NULL ) {
return NULL ;
}
return F_74 ( V_83 -> V_86 ) ;
}
int
F_162 ( const T_13 V_83 )
{
if ( V_83 -> V_86 == NULL ) {
return - 1 ;
}
return F_80 ( V_83 -> V_86 ) ;
}
T_31 *
F_163 ( void )
{
return F_137 ( V_13 ) ;
}
T_13
F_12 ( const char * V_25 )
{
return ( T_13 ) F_87 ( V_13 , V_25 ) ;
}
const char *
F_164 ( const T_13 V_83 )
{
if ( V_83 == NULL ) {
return NULL ;
}
return V_83 -> V_25 ;
}
T_13
F_165 ( T_36 V_88 , const int V_156 )
{
struct V_127 * V_83 ;
V_83 = F_166 ( F_167 () , struct V_127 ) ;
V_83 -> V_25 = NULL ;
V_83 -> V_87 = FALSE ;
V_83 -> V_88 . V_90 = V_88 ;
V_83 -> V_86 = F_149 ( V_156 ) ;
return V_83 ;
}
T_13
F_168 ( T_37 V_88 , const int V_156 )
{
struct V_127 * V_83 ;
V_83 = F_166 ( F_167 () , struct V_127 ) ;
V_83 -> V_25 = NULL ;
V_83 -> V_87 = TRUE ;
V_83 -> V_88 . V_89 = V_88 ;
V_83 -> V_86 = F_149 ( V_156 ) ;
return V_83 ;
}
T_13
F_169 ( const char * V_25 , T_36 V_88 , const int V_156 )
{
struct V_127 * V_83 ;
F_13 ( F_87 ( V_13 , V_25 ) == NULL ) ;
V_83 = F_166 ( F_167 () , struct V_127 ) ;
V_83 -> V_25 = V_25 ;
V_83 -> V_87 = FALSE ;
V_83 -> V_88 . V_90 = V_88 ;
V_83 -> V_86 = F_149 ( V_156 ) ;
F_92 ( V_13 , ( T_1 ) V_25 ,
( T_1 ) V_83 ) ;
return V_83 ;
}
T_13
F_170 ( const char * V_25 , T_37 V_88 , const int V_156 )
{
struct V_127 * V_83 ;
F_13 ( F_87 ( V_13 , V_25 ) == NULL ) ;
V_83 = F_166 ( F_167 () , struct V_127 ) ;
V_83 -> V_25 = V_25 ;
V_83 -> V_87 = TRUE ;
V_83 -> V_88 . V_89 = V_88 ;
V_83 -> V_86 = F_149 ( V_156 ) ;
F_92 ( V_13 , ( T_1 ) V_25 ,
( T_1 ) V_83 ) ;
return V_83 ;
}
int
F_171 ( T_13 V_83 , T_4 * V_19 ,
T_8 * V_24 , T_14 * V_79 , void * V_1 )
{
int V_85 ;
F_13 ( V_83 != NULL ) ;
V_85 = F_75 ( V_83 , V_19 , V_24 , V_79 , TRUE , V_1 ) ;
return V_85 ;
}
int
F_172 ( T_13 V_83 , T_4 * V_19 ,
T_8 * V_24 , T_14 * V_79 , void * V_1 )
{
int V_85 ;
V_85 = F_171 ( V_83 , V_19 , V_24 , V_79 , V_1 ) ;
if ( V_85 == 0 ) {
F_13 ( V_17 -> V_86 != NULL ) ;
F_75 ( V_17 , V_19 , V_24 , V_79 , TRUE , NULL ) ;
return F_49 ( V_19 ) ;
}
return V_85 ;
}
int
F_68 ( T_13 V_83 , T_4 * V_19 ,
T_8 * V_24 , T_14 * V_79 )
{
return F_172 ( V_83 , V_19 , V_24 , V_79 , NULL ) ;
}
void F_173 ( V_3 * V_164 , T_4 * V_19 ,
T_8 * V_24 , T_14 * V_79 , void * V_1 )
{
const char * V_166 ;
const char * V_167 ;
T_16 V_93 ;
int V_168 ;
F_13 ( V_164 ) ;
V_93 = V_24 -> V_95 ;
V_24 -> V_93 = V_93 ;
V_24 -> V_95 = V_93 - ( V_93 > 0 ) ;
V_166 = V_24 -> V_50 ;
V_167 = V_24 -> V_169 ;
V_168 = F_80 ( V_164 -> V_86 ) ;
if ( V_164 -> V_86 != NULL ) {
V_24 -> V_50 = F_74 ( V_164 -> V_86 ) ;
F_78 ( V_24 -> V_69 , F_79 ( V_168 ) ) ;
}
F_66 ( ( L_28 , F_117 ( V_168 ) ) ) ;
if( ! (* V_164 -> V_88 )( V_19 , V_24 , V_79 , V_1 ) )
F_61 () ;
V_24 -> V_95 = V_93 ;
V_24 -> V_50 = V_166 ;
V_24 -> V_169 = V_167 ;
}
static void
F_174 ( const T_22 * V_146 ,
T_25 V_147 V_2 , const T_1 T_21 , const T_1 V_125 ,
T_1 T_2 V_2 )
{
T_9 V_170 = ( T_9 ) ( unsigned long ) T_21 ;
T_18 V_107 = F_86 ( V_146 ) ;
T_19 * V_113 ;
T_13 V_83 ;
T_23 V_168 ;
const T_22 * V_171 ;
F_13 ( V_107 ) ;
switch ( V_107 -> type ) {
case V_109 :
case V_110 :
case V_111 :
case V_112 :
V_113 = ( T_19 * ) V_125 ;
F_13 ( V_113 ) ;
V_83 = V_113 -> V_115 ;
F_13 ( V_83 ) ;
V_168 = F_162 ( V_83 ) ;
if ( V_168 != - 1 ) {
V_171 = F_117 ( V_168 ) ;
F_13 ( V_171 != NULL ) ;
printf ( L_32 , V_146 , V_170 , V_171 ) ;
}
break;
default:
break;
}
}
void
F_175 ( void )
{
F_127 ( F_174 , NULL ) ;
}
void
F_176 ( T_13 V_83 )
{
if ( ! V_172 )
V_172 = F_177 () ;
F_178 ( V_172 , V_83 ) ;
V_173 ++ ;
}
T_15
F_179 ( void )
{
T_5 V_119 ;
T_13 V_83 ;
for( V_119 = 0 ; V_119 < V_173 ; V_119 ++ ) {
V_83 = ( T_13 ) F_180 ( V_172 , V_119 ) ;
if ( V_83 -> V_86 != NULL
&& F_76 ( V_83 -> V_86 ) ) {
return TRUE ;
}
}
return FALSE ;
}
void
F_181 ( T_4 * V_19 , T_8 * V_24 , T_14 * V_79 )
{
T_5 V_119 ;
for( V_119 = 0 ; V_119 < V_173 ; V_119 ++ ) {
F_171 ( ( T_13 ) F_180 ( V_172 , V_119 ) ,
V_19 , V_24 , V_79 , NULL ) ;
}
}
