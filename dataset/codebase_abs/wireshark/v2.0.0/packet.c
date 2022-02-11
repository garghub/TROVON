static void
F_1 ( T_1 V_1 , T_1 T_2 V_2 )
{
F_2 ( ( ( V_3 * ) V_1 ) -> V_4 ) ;
F_3 ( V_3 , V_1 ) ;
}
static void
F_4 ( void * V_1 )
{
T_3 V_5 = ( T_3 ) V_1 ;
T_4 * * V_6 = & ( V_5 -> V_7 ) ;
F_5 ( * V_6 , F_1 , NULL ) ;
F_6 ( * V_6 ) ;
F_3 ( struct V_8 , V_5 ) ;
}
static void
F_7 ( void * V_1 )
{
struct V_9 * V_10 = (struct V_9 * ) V_1 ;
F_8 ( V_10 -> V_11 ) ;
F_6 ( V_10 -> V_12 ) ;
F_3 ( struct V_9 , V_1 ) ;
}
void
F_9 ( void )
{
V_13 = F_10 ( V_14 , V_15 ,
NULL , F_7 ) ;
V_16 = F_10 ( V_14 , V_15 ,
NULL , NULL ) ;
V_17 = F_10 ( V_14 , V_15 ,
NULL , F_4 ) ;
V_18 = F_11 ( V_19 , V_15 ) ;
}
void
F_12 ( void )
{
V_20 = F_13 ( L_1 ) ;
F_14 ( V_20 != NULL ) ;
V_21 = F_13 ( L_2 ) ;
F_14 ( V_21 != NULL ) ;
V_22 = F_13 ( L_3 ) ;
F_14 ( V_22 != NULL ) ;
V_23 = F_15 ( L_4 ) ;
F_14 ( V_23 != - 1 ) ;
}
void
F_16 ( void )
{
F_8 ( V_13 ) ;
F_8 ( V_16 ) ;
F_8 ( V_17 ) ;
F_8 ( V_18 ) ;
}
void
F_17 ( T_5 * V_24 , const T_6 V_25 )
{
if ( V_25 < F_18 ( V_24 ) ) {
F_19 ( V_24 , V_25 ) ;
}
}
void
F_20 ( void (* F_21)( void ) )
{
V_26 = F_22 ( V_26 , ( T_1 ) F_21 ) ;
}
void
F_23 ( void (* F_21)( void ) )
{
V_27 = F_22 ( V_27 , ( T_1 ) F_21 ) ;
}
static void
F_24 ( T_1 V_28 , T_1 T_7 V_2 )
{
T_8 F_21 = ( T_8 ) V_28 ;
(* F_21)() ;
}
void
F_25 ( void )
{
F_26 () ;
F_27 () ;
F_28 () ;
F_29 () ;
F_5 ( V_26 , & F_24 , NULL ) ;
F_30 () ;
F_31 () ;
}
void
F_32 ( void )
{
F_33 () ;
F_34 () ;
F_5 ( V_27 , & F_24 , NULL ) ;
F_35 () ;
F_36 () ;
F_37 () ;
F_38 () ;
}
void
F_39 ( T_8 F_21 )
{
V_29 = F_22 ( V_29 ,
( T_1 ) F_21 ) ;
}
static void
F_40 ( T_1 V_28 , T_1 T_7 V_2 )
{
T_8 F_21 = ( T_8 ) V_28 ;
(* F_21)() ;
}
void
F_41 ( void )
{
F_5 ( V_29 ,
& F_40 , NULL ) ;
}
void
F_42 ( T_9 * V_30 , T_5 * V_24 , const char * V_31 )
{
struct V_32 * V_33 ;
V_33 = F_43 ( struct V_32 ) ;
V_33 -> V_24 = V_24 ;
V_33 -> V_31 = F_44 ( V_31 ) ;
V_30 -> V_34 = F_45 ( V_30 -> V_34 , V_33 ) ;
}
void
F_46 ( T_9 * V_30 )
{
struct V_32 * V_33 ;
T_4 * V_35 ;
V_35 = F_47 ( V_30 -> V_34 ) ;
V_33 = (struct V_32 * ) V_35 -> V_1 ;
V_30 -> V_34 = F_48 ( V_30 -> V_34 , V_35 ) ;
F_2 ( V_33 -> V_31 ) ;
F_3 ( struct V_32 , V_33 ) ;
}
char *
F_49 ( const struct V_32 * V_33 )
{
T_6 V_36 = F_50 ( V_33 -> V_24 ) ;
return F_51 ( NULL , L_5 , V_33 -> V_31 , V_36 ,
F_52 ( V_36 , L_6 , L_7 ) ) ;
}
T_5 *
F_53 ( const struct V_32 * V_33 )
{
return V_33 -> V_24 ;
}
void
F_54 ( T_9 * V_30 )
{
if ( V_30 -> V_34 ) {
T_4 * V_37 ;
for ( V_37 = V_30 -> V_34 ; V_37 ; V_37 = V_37 -> V_38 ) {
struct V_32 * V_33 = (struct V_32 * ) V_37 -> V_1 ;
F_2 ( V_33 -> V_31 ) ;
F_3 ( struct V_32 , V_33 ) ;
}
F_6 ( V_30 -> V_34 ) ;
V_30 -> V_34 = NULL ;
}
}
void
F_55 ( T_9 * V_30 , T_10 V_39 )
{
if ( V_39 != F_56 ( V_30 ) ) {
V_30 -> V_40 = F_22 ( V_30 -> V_40 , F_57 ( V_39 ) ) ;
}
}
void
F_58 ( void (* F_21)( void ) )
{
V_41 = F_22 ( V_41 ,
( T_1 ) F_21 ) ;
}
static void
F_59 ( T_1 V_28 , T_1 T_7 V_2 )
{
T_8 F_21 = ( T_8 ) V_28 ;
(* F_21)() ;
}
void
F_60 ( void )
{
F_5 ( V_41 ,
& F_59 , NULL ) ;
}
void
F_61 ( T_11 * V_42 , int V_43 ,
struct V_44 * V_45 , T_5 * V_24 , T_12 * V_46 , T_13 * V_47 )
{
const char * volatile V_48 ;
T_14 V_49 ;
switch ( V_45 -> V_50 ) {
case V_51 :
V_48 = L_8 ;
break;
case V_52 :
V_48 = L_9 ;
break;
case V_53 :
V_48 = L_10 ;
break;
default:
F_62 () ;
break;
}
if ( V_47 != NULL )
F_63 ( V_47 , V_42 -> V_54 ) ;
V_42 -> V_55 . V_56 = V_42 -> V_54 ;
V_42 -> V_55 . V_57 = L_11 ;
V_42 -> V_55 . V_47 = V_47 ;
V_42 -> V_55 . V_46 = V_46 ;
V_42 -> V_55 . V_45 = V_45 ;
V_42 -> V_55 . V_58 = & V_45 -> V_58 ;
V_42 -> V_55 . V_59 . type = V_60 ;
V_42 -> V_55 . V_61 . type = V_60 ;
V_42 -> V_55 . V_62 . type = V_60 ;
V_42 -> V_55 . V_63 . type = V_60 ;
V_42 -> V_55 . V_33 . type = V_60 ;
V_42 -> V_55 . V_64 . type = V_60 ;
V_42 -> V_55 . V_65 = V_66 ;
V_42 -> V_55 . V_67 = L_6 ;
V_42 -> V_55 . V_68 = V_69 ;
V_42 -> V_55 . V_70 = V_71 ;
V_42 -> V_55 . V_72 = V_73 ;
V_42 -> V_55 . V_74 = F_64 ( V_42 -> V_55 . V_75 ) ;
V_42 -> V_24 = V_24 ;
F_65 ( V_42 -> V_54 , V_46 , V_46 -> V_76 , & V_42 -> V_55 . V_77 ) ;
if ( V_46 -> V_78 . V_79 )
V_49 . V_80 = F_66 ( V_42 -> V_54 , V_46 ) ;
else if ( V_46 -> V_78 . V_81 )
V_49 . V_80 = V_45 -> V_82 ;
else
V_49 . V_80 = NULL ;
V_49 . V_43 = V_43 ;
F_67 {
F_42 ( & V_42 -> V_55 , V_42 -> V_24 , V_48 ) ;
F_68 ( V_20 , V_42 -> V_24 , & V_42 -> V_55 , V_42 -> V_83 , & V_49 ) ;
}
F_69 (BoundsError) {
F_62 () ;
}
F_70 (FragmentBoundsError, ReportedBoundsError) {
F_71 ( V_42 -> V_83 , V_23 , V_42 -> V_24 , 0 , 0 ,
L_12 ,
V_48 ) ;
}
V_84 ;
V_46 -> V_78 . V_85 = 1 ;
}
void
F_72 ( T_11 * V_42 , struct V_44 * V_45 ,
T_5 * V_24 , T_12 * V_46 , T_13 * V_47 )
{
if ( V_47 != NULL )
F_63 ( V_47 , V_42 -> V_54 ) ;
V_42 -> V_55 . V_56 = V_42 -> V_54 ;
V_42 -> V_55 . V_57 = L_13 ;
V_42 -> V_55 . V_47 = V_47 ;
V_42 -> V_55 . V_46 = V_46 ;
V_42 -> V_55 . V_45 = V_45 ;
V_42 -> V_55 . V_58 = & V_45 -> V_58 ;
V_42 -> V_55 . V_59 . type = V_60 ;
V_42 -> V_55 . V_61 . type = V_60 ;
V_42 -> V_55 . V_62 . type = V_60 ;
V_42 -> V_55 . V_63 . type = V_60 ;
V_42 -> V_55 . V_33 . type = V_60 ;
V_42 -> V_55 . V_64 . type = V_60 ;
V_42 -> V_55 . V_65 = V_66 ;
V_42 -> V_55 . V_67 = L_6 ;
V_42 -> V_55 . V_68 = V_69 ;
V_42 -> V_55 . V_70 = V_71 ;
V_42 -> V_55 . V_72 = V_73 ;
V_42 -> V_55 . V_74 = F_64 ( V_42 -> V_55 . V_75 ) ;
V_42 -> V_24 = V_24 ;
F_65 ( V_42 -> V_54 , V_46 , V_46 -> V_76 , & V_42 -> V_55 . V_77 ) ;
F_67 {
const T_15 * V_80 ;
if ( V_46 -> V_78 . V_79 )
V_80 = F_66 ( V_42 -> V_54 , V_46 ) ;
else if ( V_46 -> V_78 . V_81 )
V_80 = V_45 -> V_82 ;
else
V_80 = NULL ;
F_42 ( & V_42 -> V_55 , V_42 -> V_24 , L_14 ) ;
F_68 ( V_21 , V_42 -> V_24 , & V_42 -> V_55 , V_42 -> V_83 , ( void * ) V_80 ) ;
}
F_69 (BoundsError) {
F_62 () ;
}
F_70 (FragmentBoundsError, ReportedBoundsError) {
F_71 ( V_42 -> V_83 , V_23 , V_42 -> V_24 , 0 , 0 ,
L_15 ) ;
}
V_84 ;
V_46 -> V_78 . V_85 = 1 ;
}
static int
F_73 ( T_16 V_86 , T_5 * V_24 ,
T_9 * V_30 , T_17 * V_83 , void * V_1 )
{
const char * V_87 ;
int V_88 ;
V_87 = V_30 -> V_57 ;
if ( V_86 -> V_89 != NULL ) {
V_30 -> V_57 =
F_74 ( V_86 -> V_89 ) ;
}
if ( V_86 -> V_90 ) {
V_88 = (* V_86 -> V_91 . V_92 )( V_24 , V_30 , V_83 , V_1 ) ;
} else {
(* V_86 -> V_91 . V_93 )( V_24 , V_30 , V_83 ) ;
V_88 = F_50 ( V_24 ) ;
if ( V_88 == 0 ) {
V_88 = 1 ;
}
}
V_30 -> V_57 = V_87 ;
return V_88 ;
}
static int
F_75 ( T_16 V_86 , T_5 * V_24 , T_9 * V_94 ,
T_17 * V_83 , T_18 V_95 , void * V_1 )
{
T_9 * V_30 = V_94 ;
const char * V_87 ;
T_19 V_96 ;
int V_88 ;
T_6 V_97 = 0 ;
if ( V_86 -> V_89 != NULL &&
! F_76 ( V_86 -> V_89 ) ) {
return 0 ;
}
V_87 = V_30 -> V_57 ;
V_96 = V_30 -> V_98 ;
V_97 = F_77 ( V_30 -> V_74 ) ;
V_30 -> V_96 = V_96 ;
V_30 -> V_98 = V_96 - ( V_96 > 0 ) ;
if ( V_86 -> V_89 != NULL ) {
V_30 -> V_57 =
F_74 ( V_86 -> V_89 ) ;
if ( V_95 ) {
V_30 -> V_99 ++ ;
F_78 ( V_30 -> V_74 , F_79 ( F_80 ( V_86 -> V_89 ) ) ) ;
}
}
if ( V_30 -> V_78 . V_100 ) {
V_88 = F_81 ( V_86 , V_24 , V_30 , V_83 , V_1 ) ;
} else {
V_88 = F_73 ( V_86 , V_24 , V_30 , V_83 , V_1 ) ;
}
if ( V_88 == 0 ) {
while ( F_77 ( V_30 -> V_74 ) > V_97 ) {
F_82 ( V_30 -> V_74 , F_83 ( V_30 -> V_74 ) ) ;
}
}
V_30 -> V_57 = V_87 ;
V_30 -> V_98 = V_96 ;
return V_88 ;
}
static int
F_81 ( T_16 V_86 , T_5 * V_24 ,
T_9 * V_94 , T_17 * V_83 , void * V_1 )
{
T_9 * V_30 = V_94 ;
const char * V_87 ;
T_19 V_96 ;
volatile int V_88 = 0 ;
T_18 V_101 ;
T_20 V_102 ;
T_20 V_103 ;
T_20 V_104 ;
T_20 V_105 ;
T_20 V_106 ;
T_20 V_107 ;
V_87 = V_30 -> V_57 ;
V_96 = V_30 -> V_98 ;
V_101 = F_84 ( V_30 -> V_47 ) ;
F_85 ( V_30 -> V_47 , FALSE ) ;
V_102 = V_30 -> V_59 ;
V_103 = V_30 -> V_61 ;
V_104 = V_30 -> V_62 ;
V_105 = V_30 -> V_63 ;
V_106 = V_30 -> V_33 ;
V_107 = V_30 -> V_64 ;
F_67 {
V_88 = F_73 ( V_86 , V_24 , V_30 , V_83 , V_1 ) ;
}
F_69 (BoundsError) {
F_85 ( V_30 -> V_47 , V_101 ) ;
V_30 -> V_59 = V_102 ;
V_30 -> V_61 = V_103 ;
V_30 -> V_62 = V_104 ;
V_30 -> V_63 = V_105 ;
V_30 -> V_33 = V_106 ;
V_30 -> V_64 = V_107 ;
V_30 -> V_57 = V_87 ;
V_30 -> V_98 = V_96 ;
V_108 ;
}
F_70 (FragmentBoundsError, ReportedBoundsError) {
V_88 = F_50 ( V_24 ) ;
}
V_84 ;
F_85 ( V_30 -> V_47 , V_101 ) ;
V_30 -> V_59 = V_102 ;
V_30 -> V_61 = V_103 ;
V_30 -> V_62 = V_104 ;
V_30 -> V_63 = V_105 ;
V_30 -> V_33 = V_106 ;
V_30 -> V_64 = V_107 ;
V_30 -> V_109 = 0 ;
return V_88 ;
}
T_21
F_86 ( const char * V_31 )
{
return ( T_21 ) F_87 ( V_13 , V_31 ) ;
}
static T_22 *
F_88 ( T_21 V_110 , const T_10 V_111 )
{
switch ( V_110 -> type ) {
case V_112 :
case V_113 :
case V_114 :
case V_115 :
break;
default:
F_62 () ;
}
return ( T_22 * ) F_87 ( V_110 -> V_11 ,
F_57 ( V_111 ) ) ;
}
void
F_89 ( const char * V_31 , const T_10 V_111 , T_16 V_86 )
{
T_21 V_110 ;
T_22 * V_116 ;
V_110 = F_86 ( V_31 ) ;
if ( V_110 == NULL ) {
fprintf ( V_117 , L_16 ,
V_31 ) ;
fprintf ( V_117 , L_17 ,
F_90 ( V_86 -> V_89 ) ) ;
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
F_14 ( V_86 != NULL ) ;
switch ( V_110 -> type ) {
case V_112 :
case V_113 :
case V_114 :
case V_115 :
break;
default:
F_62 () ;
}
#if 0
dissector_add_uint_sanity_check(name, pattern, handle, sub_dissectors);
#endif
V_116 = ( T_22 * ) F_91 ( sizeof ( T_22 ) ) ;
V_116 -> V_118 = V_86 ;
V_116 -> V_119 = V_116 -> V_118 ;
F_92 ( V_110 -> V_11 ,
F_57 ( V_111 ) , ( T_1 ) V_116 ) ;
F_93 ( V_31 , V_86 ) ;
}
void F_94 ( const char * V_120 , T_23 * V_121 ,
T_16 V_86 )
{
T_10 V_122 , V_123 ;
if ( V_121 ) {
for ( V_122 = 0 ; V_122 < V_121 -> V_124 ; V_122 ++ ) {
for ( V_123 = V_121 -> V_125 [ V_122 ] . V_126 ; V_123 <= V_121 -> V_125 [ V_122 ] . V_127 ; V_123 ++ )
F_89 ( V_120 , V_123 , V_86 ) ;
}
}
}
void
F_95 ( const char * V_31 , const T_10 V_111 ,
T_16 V_86 V_2 )
{
T_21 V_110 = F_86 ( V_31 ) ;
T_22 * V_116 ;
F_14 ( V_110 ) ;
V_116 = F_88 ( V_110 , V_111 ) ;
if ( V_116 != NULL ) {
F_96 ( V_110 -> V_11 ,
F_57 ( V_111 ) ) ;
}
}
void F_97 ( const char * V_120 , T_23 * V_121 ,
T_16 V_86 )
{
T_10 V_122 , V_123 ;
if ( V_121 ) {
for ( V_122 = 0 ; V_122 < V_121 -> V_124 ; V_122 ++ ) {
for ( V_123 = V_121 -> V_125 [ V_122 ] . V_126 ; V_123 <= V_121 -> V_125 [ V_122 ] . V_127 ; V_123 ++ )
F_95 ( V_120 , V_123 , V_86 ) ;
}
}
}
static T_18
F_98 ( T_1 T_24 V_2 , T_1 V_128 , T_1 T_2 )
{
T_22 * V_116 = ( T_22 * ) V_128 ;
T_16 V_86 = ( T_16 ) T_2 ;
if ( ! V_116 -> V_118 -> V_89 ) {
return FALSE ;
}
return ( F_80 ( V_116 -> V_118 -> V_89 ) == F_80 ( V_86 -> V_89 ) ) ;
}
void F_99 ( const char * V_31 , T_16 V_86 )
{
T_21 V_110 = F_86 ( V_31 ) ;
F_14 ( V_110 ) ;
F_100 ( V_110 -> V_11 , F_98 , V_86 ) ;
}
static void
F_101 ( T_1 T_24 V_2 , T_1 V_128 , T_1 T_2 )
{
T_21 V_110 = ( T_21 ) V_128 ;
F_14 ( V_110 ) ;
F_100 ( V_110 -> V_11 , F_98 , T_2 ) ;
V_110 -> V_12 = F_102 ( V_110 -> V_12 , T_2 ) ;
}
static void
F_103 ( T_16 V_86 )
{
F_104 ( V_13 , F_101 , V_86 ) ;
}
void
F_105 ( const char * V_31 , const T_10 V_111 , T_16 V_86 )
{
T_21 V_110 = F_86 ( V_31 ) ;
T_22 * V_116 ;
F_14 ( V_110 ) ;
V_116 = F_88 ( V_110 , V_111 ) ;
if ( V_116 != NULL ) {
V_116 -> V_118 = V_86 ;
return;
}
if ( V_86 == NULL )
return;
V_116 = ( T_22 * ) F_91 ( sizeof ( T_22 ) ) ;
V_116 -> V_119 = NULL ;
V_116 -> V_118 = V_86 ;
F_92 ( V_110 -> V_11 ,
F_57 ( V_111 ) , ( T_1 ) V_116 ) ;
}
void
F_106 ( const char * V_31 , const T_10 V_111 )
{
T_21 V_110 = F_86 ( V_31 ) ;
T_22 * V_116 ;
F_14 ( V_110 ) ;
V_116 = F_88 ( V_110 , V_111 ) ;
if ( V_116 == NULL )
return;
if ( V_116 -> V_119 != NULL ) {
V_116 -> V_118 = V_116 -> V_119 ;
} else {
F_96 ( V_110 -> V_11 ,
F_57 ( V_111 ) ) ;
}
}
int
F_107 ( T_21 V_110 , const T_10 V_129 ,
T_5 * V_24 , T_9 * V_30 , T_17 * V_83 ,
const T_18 V_95 , void * V_1 )
{
T_22 * V_116 ;
struct V_130 * V_86 ;
T_10 V_131 ;
int V_88 ;
V_116 = F_88 ( V_110 , V_129 ) ;
if ( V_116 != NULL ) {
V_86 = V_116 -> V_118 ;
if ( V_86 == NULL ) {
return 0 ;
}
V_131 = V_30 -> V_132 ;
V_30 -> V_132 = V_129 ;
V_88 = F_75 ( V_86 , V_24 , V_30 , V_83 , V_95 , V_1 ) ;
V_30 -> V_132 = V_131 ;
return V_88 ;
}
return 0 ;
}
int
F_108 ( T_21 V_110 , const T_10 V_129 ,
T_5 * V_24 , T_9 * V_30 , T_17 * V_83 )
{
return F_107 ( V_110 , V_129 , V_24 , V_30 , V_83 , TRUE , NULL ) ;
}
T_16
F_109 ( T_21 const V_110 , const T_10 V_129 )
{
T_22 * V_116 ;
V_116 = F_88 ( V_110 , V_129 ) ;
if ( V_116 != NULL )
return V_116 -> V_118 ;
else
return NULL ;
}
T_16
F_110 ( const char * V_31 , const T_10 V_129 )
{
T_21 V_110 = F_86 ( V_31 ) ;
if ( V_110 != NULL ) {
T_22 * V_116 = F_88 ( V_110 , V_129 ) ;
if ( V_116 != NULL )
return V_116 -> V_119 ;
}
return NULL ;
}
static T_22 *
F_111 ( T_21 const V_110 , const T_15 * V_111 )
{
T_22 * V_133 ;
char * T_24 ;
switch ( V_110 -> type ) {
case V_134 :
case V_135 :
case V_136 :
break;
default:
F_62 () ;
}
if ( V_110 -> V_137 == TRUE ) {
T_24 = F_112 ( V_111 , - 1 ) ;
} else {
T_24 = F_44 ( V_111 ) ;
}
V_133 = ( T_22 * ) F_87 ( V_110 -> V_11 , T_24 ) ;
F_2 ( T_24 ) ;
return V_133 ;
}
void
F_113 ( const char * V_31 , const T_15 * V_111 ,
T_16 V_86 )
{
T_21 V_110 = F_86 ( V_31 ) ;
T_22 * V_116 ;
char * T_24 ;
if ( V_110 == NULL ) {
fprintf ( V_117 , L_16 ,
V_31 ) ;
fprintf ( V_117 , L_17 ,
F_90 ( V_86 -> V_89 ) ) ;
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
F_14 ( V_86 != NULL ) ;
switch ( V_110 -> type ) {
case V_134 :
case V_135 :
case V_136 :
break;
default:
F_62 () ;
}
V_116 = ( T_22 * ) F_91 ( sizeof ( T_22 ) ) ;
V_116 -> V_118 = V_86 ;
V_116 -> V_119 = V_116 -> V_118 ;
if ( V_110 -> V_137 == TRUE ) {
T_24 = F_112 ( V_111 , - 1 ) ;
} else {
T_24 = F_44 ( V_111 ) ;
}
F_92 ( V_110 -> V_11 , ( T_1 ) T_24 ,
( T_1 ) V_116 ) ;
F_93 ( V_31 , V_86 ) ;
}
void
F_114 ( const char * V_31 , const T_15 * V_111 ,
T_16 V_86 V_2 )
{
T_21 V_110 = F_86 ( V_31 ) ;
T_22 * V_116 ;
F_14 ( V_110 ) ;
V_116 = F_111 ( V_110 , V_111 ) ;
if ( V_116 != NULL ) {
F_96 ( V_110 -> V_11 , V_111 ) ;
}
}
void
F_115 ( const char * V_31 , const T_15 * V_111 ,
T_16 V_86 )
{
T_21 V_110 = F_86 ( V_31 ) ;
T_22 * V_116 ;
F_14 ( V_110 ) ;
V_116 = F_111 ( V_110 , V_111 ) ;
if ( V_116 != NULL ) {
V_116 -> V_118 = V_86 ;
return;
}
if ( V_86 == NULL )
return;
V_116 = ( T_22 * ) F_91 ( sizeof ( T_22 ) ) ;
V_116 -> V_119 = NULL ;
V_116 -> V_118 = V_86 ;
F_92 ( V_110 -> V_11 , ( T_1 ) F_44 ( V_111 ) ,
( T_1 ) V_116 ) ;
}
void
F_116 ( const char * V_31 , const T_15 * V_111 )
{
T_21 V_110 = F_86 ( V_31 ) ;
T_22 * V_116 ;
F_14 ( V_110 ) ;
V_116 = F_111 ( V_110 , V_111 ) ;
if ( V_116 == NULL )
return;
if ( V_116 -> V_119 != NULL ) {
V_116 -> V_118 = V_116 -> V_119 ;
} else {
F_96 ( V_110 -> V_11 , V_111 ) ;
}
}
int
F_117 ( T_21 V_110 , const T_15 * string ,
T_5 * V_24 , T_9 * V_30 , T_17 * V_83 , void * V_1 )
{
T_22 * V_116 ;
struct V_130 * V_86 ;
int V_88 ;
const T_15 * V_138 ;
if ( ! string ) return 0 ;
V_116 = F_111 ( V_110 , string ) ;
if ( V_116 != NULL ) {
V_86 = V_116 -> V_118 ;
if ( V_86 == NULL ) {
return 0 ;
}
V_138 = V_30 -> V_139 ;
V_30 -> V_139 = string ;
V_88 = F_75 ( V_86 , V_24 , V_30 , V_83 , TRUE , V_1 ) ;
V_30 -> V_139 = V_138 ;
return V_88 ;
}
return 0 ;
}
T_16
F_118 ( T_21 V_110 ,
const T_15 * string )
{
T_22 * V_116 ;
if ( ! string ) return NULL ;
V_116 = F_111 ( V_110 , string ) ;
if ( V_116 != NULL )
return V_116 -> V_118 ;
else
return NULL ;
}
T_16
F_119 ( const char * V_31 , const T_15 * string )
{
T_21 V_110 ;
if ( ! string ) return NULL ;
V_110 = F_86 ( V_31 ) ;
if ( V_110 != NULL ) {
T_22 * V_116 = F_111 ( V_110 , string ) ;
if ( V_116 != NULL )
return V_116 -> V_119 ;
}
return NULL ;
}
void F_120 ( const char * V_31 , void * V_111 , T_16 V_86 )
{
T_21 V_110 = F_86 ( V_31 ) ;
T_22 * V_116 ;
if ( V_110 == NULL ) {
fprintf ( V_117 , L_16 ,
V_31 ) ;
fprintf ( V_117 , L_17 ,
F_90 ( V_86 -> V_89 ) ) ;
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
F_14 ( V_110 -> type == V_140 ) ;
V_116 = ( T_22 * ) F_91 ( sizeof ( T_22 ) ) ;
V_116 -> V_118 = V_86 ;
V_116 -> V_119 = V_116 -> V_118 ;
F_92 ( V_110 -> V_11 , ( T_1 ) V_111 ,
( T_1 ) V_116 ) ;
F_93 ( V_31 , V_86 ) ;
}
T_16 F_121 ( T_21 V_110 , void * T_24 )
{
T_22 * V_116 = ( T_22 * ) F_87 ( V_110 -> V_11 , T_24 ) ;
if ( V_116 != NULL )
return V_116 -> V_118 ;
return NULL ;
}
T_16
F_122 ( T_22 * V_116 )
{
return V_116 -> V_118 ;
}
static T_25
F_123 ( T_26 V_141 , T_26 V_142 )
{
const struct V_130 * V_143 = ( const struct V_130 * ) V_141 ;
const struct V_130 * V_144 = ( const struct V_130 * ) V_142 ;
const char * V_145 , * V_146 ;
T_25 V_133 ;
if ( V_143 -> V_89 == NULL )
V_145 = L_6 ;
else
V_145 = F_124 ( F_80 ( V_143 -> V_89 ) ) ;
if ( V_144 -> V_89 == NULL )
V_146 = L_6 ;
else
V_146 = F_124 ( F_80 ( V_144 -> V_89 ) ) ;
V_133 = strcmp ( V_145 , V_146 ) ;
return V_133 ;
}
void
F_93 ( const char * V_31 , T_16 V_86 )
{
T_21 V_110 = F_86 ( V_31 ) ;
T_4 * V_147 ;
if ( V_110 == NULL ) {
fprintf ( V_117 , L_16 ,
V_31 ) ;
fprintf ( V_117 , L_17 ,
F_90 ( V_86 -> V_89 ) ) ;
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
V_147 = F_125 ( V_110 -> V_12 , ( T_1 ) V_86 ) ;
if ( V_147 != NULL ) {
return;
}
V_110 -> V_12 =
F_126 ( V_110 -> V_12 , ( T_1 ) V_86 , ( V_148 ) F_123 ) ;
}
T_16
F_127 ( T_22 * V_116 )
{
return V_116 -> V_119 ;
}
T_4 *
F_128 ( T_21 V_9 ) {
if ( ! V_9 ) return NULL ;
return V_9 -> V_12 ;
}
T_27
F_129 ( T_21 V_9 ) {
if ( ! V_9 ) return V_149 ;
return V_9 -> type ;
}
static void
F_130 ( T_1 T_24 , T_1 V_128 , T_1 T_2 )
{
T_28 * V_150 ;
T_22 * V_116 ;
F_14 ( V_128 ) ;
F_14 ( T_2 ) ;
V_116 = ( T_22 * ) V_128 ;
if ( V_116 -> V_118 == NULL ||
V_116 -> V_118 -> V_89 == NULL ) {
return;
}
V_150 = ( T_28 * ) T_2 ;
V_150 -> V_151 ( V_150 -> V_152 , V_150 -> V_153 , T_24 , V_128 ,
V_150 -> V_154 ) ;
}
static void
F_131 ( T_1 T_24 , T_1 V_128 , T_1 T_2 )
{
T_21 V_110 ;
T_28 * V_150 ;
F_14 ( V_128 ) ;
F_14 ( T_2 ) ;
V_110 = ( T_21 ) V_128 ;
V_150 = ( T_28 * ) T_2 ;
V_150 -> V_152 = ( T_15 * ) T_24 ;
V_150 -> V_153 = F_132 ( V_150 -> V_152 ) ;
F_104 ( V_110 -> V_11 , V_150 -> V_155 , V_150 ) ;
}
static void
F_133 ( T_29 F_21 ,
T_1 T_2 )
{
T_28 V_150 ;
V_150 . V_154 = T_2 ;
V_150 . V_151 = F_21 ;
V_150 . V_155 = F_130 ;
F_104 ( V_13 , F_131 , & V_150 ) ;
}
void
F_134 ( const char * V_152 ,
T_29 F_21 ,
T_1 T_2 )
{
T_28 V_150 ;
T_21 V_110 = F_86 ( V_152 ) ;
V_150 . V_152 = V_152 ;
V_150 . V_153 = V_110 -> type ;
V_150 . V_151 = F_21 ;
V_150 . V_154 = T_2 ;
F_104 ( V_110 -> V_11 , F_130 , & V_150 ) ;
}
void
F_135 ( const char * V_152 ,
T_30 F_21 ,
T_1 T_2 )
{
T_21 V_110 = F_86 ( V_152 ) ;
T_4 * V_156 ;
for ( V_156 = V_110 -> V_12 ; V_156 != NULL ;
V_156 = F_136 ( V_156 ) )
F_21 ( V_152 , V_156 -> V_1 , T_2 ) ;
}
static void
F_137 ( T_1 T_24 , T_1 V_128 , T_1 T_2 )
{
T_22 * V_116 ;
T_28 * V_150 ;
F_14 ( V_128 ) ;
F_14 ( T_2 ) ;
V_116 = ( T_22 * ) V_128 ;
if ( V_116 -> V_119 == V_116 -> V_118 ) {
return;
}
V_150 = ( T_28 * ) T_2 ;
V_150 -> V_151 ( V_150 -> V_152 , V_150 -> V_153 , T_24 , V_128 ,
V_150 -> V_154 ) ;
}
void
F_138 ( T_29 F_21 ,
T_1 T_2 )
{
T_28 V_150 ;
V_150 . V_154 = T_2 ;
V_150 . V_151 = F_21 ;
V_150 . V_155 = F_137 ;
F_104 ( V_13 , F_131 , & V_150 ) ;
}
void
F_139 ( const char * V_152 ,
T_29 F_21 ,
T_1 T_2 )
{
T_28 V_150 ;
T_21 V_110 = F_86 ( V_152 ) ;
V_150 . V_152 = V_152 ;
V_150 . V_153 = V_110 -> type ;
V_150 . V_151 = F_21 ;
V_150 . V_154 = T_2 ;
F_104 ( V_110 -> V_11 ,
F_137 , & V_150 ) ;
}
static void
F_140 ( T_1 T_24 , const T_1 V_128 , const T_1 T_2 )
{
T_21 V_10 ;
T_31 * V_150 ;
V_10 = ( T_21 ) V_128 ;
V_150 = ( T_31 * ) T_2 ;
(* V_150 -> V_151 )( ( T_15 * ) T_24 , V_10 -> V_157 , V_150 -> V_154 ) ;
}
static void
F_141 ( T_1 T_24 , T_1 T_2 )
{
T_21 V_10 ;
T_31 * V_150 ;
V_10 = ( T_21 ) F_87 ( V_13 , T_24 ) ;
V_150 = ( T_31 * ) T_2 ;
(* V_150 -> V_151 )( ( T_15 * ) T_24 , V_10 -> V_157 , V_150 -> V_154 ) ;
}
void
F_142 ( T_32 F_21 ,
T_1 T_2 ,
V_148 V_158 )
{
T_31 V_150 ;
T_33 * V_6 ;
V_150 . V_154 = T_2 ;
V_150 . V_151 = F_21 ;
if ( V_158 != NULL )
{
V_6 = F_143 ( V_13 ) ;
V_6 = F_144 ( V_6 , V_158 ) ;
F_145 ( V_6 , F_141 , & V_150 ) ;
F_146 ( V_6 ) ;
}
else
{
F_104 ( V_13 , F_140 , & V_150 ) ;
}
}
T_21
F_147 ( const char * V_31 , const char * V_157 , const T_27 type ,
const int V_137 )
{
T_21 V_110 ;
if( F_87 ( V_13 , V_31 ) ) {
F_148 ( L_19 , V_31 , V_157 ) ;
}
V_110 = F_43 ( struct V_9 ) ;
switch ( type ) {
case V_112 :
case V_113 :
case V_114 :
case V_115 :
V_110 -> V_159 = V_160 ;
V_110 -> V_11 = F_10 ( V_160 ,
V_161 ,
NULL ,
& F_2 ) ;
break;
case V_134 :
case V_135 :
case V_136 :
V_110 -> V_159 = V_14 ;
V_110 -> V_11 = F_10 ( V_14 ,
V_15 ,
& F_2 ,
& F_2 ) ;
break;
default:
F_62 () ;
}
V_110 -> V_12 = NULL ;
V_110 -> V_157 = V_157 ;
V_110 -> type = type ;
V_110 -> V_137 = V_137 ;
F_92 ( V_13 , ( T_1 ) V_31 , ( T_1 ) V_110 ) ;
return V_110 ;
}
T_21 F_149 ( const char * V_31 ,
const char * V_157 , T_34 V_159 , T_35 V_162 )
{
T_21 V_110 ;
if( F_87 ( V_13 , V_31 ) ) {
F_148 ( L_19 , V_31 , V_157 ) ;
}
V_110 = F_43 ( struct V_9 ) ;
V_110 -> V_159 = V_159 ;
V_110 -> V_11 = F_10 ( V_159 ,
V_162 ,
& F_2 ,
& F_2 ) ;
V_110 -> V_12 = NULL ;
V_110 -> V_157 = V_157 ;
V_110 -> type = V_140 ;
V_110 -> V_137 = V_163 ;
F_92 ( V_13 , ( T_1 ) V_31 , ( T_1 ) V_110 ) ;
return V_110 ;
}
void
F_150 ( const char * V_31 )
{
T_21 V_110 = F_86 ( V_31 ) ;
if ( ! V_110 ) return;
F_96 ( V_13 , ( T_1 ) V_31 ) ;
}
const char *
F_151 ( const char * V_31 )
{
T_21 V_110 = F_86 ( V_31 ) ;
if ( ! V_110 ) return NULL ;
return V_110 -> V_157 ;
}
T_27
F_132 ( const char * V_31 )
{
T_21 V_110 = F_86 ( V_31 ) ;
if ( ! V_110 ) return V_149 ;
return V_110 -> type ;
}
int
F_152 ( const char * V_31 )
{
T_21 V_110 = F_86 ( V_31 ) ;
if ( ! V_110 ) return 0 ;
return V_110 -> V_137 ;
}
T_3
F_153 ( const char * V_31 )
{
return ( T_3 ) F_87 ( V_17 , V_31 ) ;
}
T_18
F_154 ( const T_15 * V_31 ) {
return ( F_153 ( V_31 ) != NULL ) ;
}
V_3 * F_155 ( const char * V_164 )
{
return ( V_3 * ) F_87 ( V_18 , ( T_1 ) V_164 ) ;
}
void
F_156 ( const char * V_31 , T_36 V_91 , const char * V_165 , const char * V_164 , const int V_166 , T_37 V_167 )
{
T_3 V_110 = F_153 ( V_31 ) ;
const char * V_168 ;
V_3 * V_169 ;
T_6 V_122 , V_170 ;
T_4 * V_171 ;
if ( V_110 == NULL ) {
fprintf ( V_117 , L_16 ,
V_31 ) ;
V_168 = F_157 ( V_166 ) ;
if ( V_168 != NULL ) {
fprintf ( V_117 , L_17 ,
V_168 ) ;
}
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
V_170 = F_158 ( V_110 -> V_7 ) ;
for ( V_122 = 0 ; V_122 < V_170 ; V_122 ++ )
{
V_171 = F_159 ( V_110 -> V_7 , V_122 ) ;
V_169 = ( V_3 * ) V_171 -> V_1 ;
if ( ( V_169 -> V_91 == V_91 ) &&
( V_169 -> V_89 == F_160 ( V_166 ) ) )
{
V_168 = F_157 ( V_166 ) ;
if ( V_168 != NULL ) {
fprintf ( V_117 , L_20 ,
V_168 , V_31 ) ;
}
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
}
if ( F_87 ( V_18 , ( T_1 ) V_164 ) != NULL ) {
F_148 ( L_21
L_22 , V_164 ) ;
}
V_169 = F_43 ( V_3 ) ;
V_169 -> V_91 = V_91 ;
V_169 -> V_89 = F_160 ( V_166 ) ;
V_169 -> V_165 = V_165 ;
V_169 -> V_164 = V_164 ;
V_169 -> V_4 = F_44 ( V_31 ) ;
V_169 -> V_172 = ( V_167 == V_173 ) ;
F_92 ( V_18 , ( T_1 ) V_164 , V_169 ) ;
V_110 -> V_7 = F_22 ( V_110 -> V_7 ,
( T_1 ) V_169 ) ;
F_161 ( V_169 -> V_89 , V_164 ) ;
}
static int
F_162 ( T_26 V_143 , T_26 V_144 ) {
const V_3 * V_174 = ( const V_3 * ) V_143 ;
const V_3 * V_175 = ( const V_3 * ) V_144 ;
return ( V_174 -> V_91 == V_175 -> V_91 ) &&
( V_174 -> V_89 == V_175 -> V_89 ) ? 0 : 1 ;
}
void
F_163 ( const char * V_31 , T_36 V_91 , const int V_166 ) {
T_3 V_110 = F_153 ( V_31 ) ;
V_3 V_169 ;
T_4 * V_176 ;
F_14 ( V_110 != NULL ) ;
V_169 . V_91 = V_91 ;
V_169 . V_89 = F_160 ( V_166 ) ;
V_176 = F_164 ( V_110 -> V_7 ,
( T_1 ) & V_169 , F_162 ) ;
if ( V_176 ) {
F_2 ( ( ( V_3 * ) ( V_176 -> V_1 ) ) -> V_4 ) ;
F_3 ( V_3 , V_176 -> V_1 ) ;
V_110 -> V_7 = F_48 ( V_110 -> V_7 ,
V_176 ) ;
}
}
T_18
F_165 ( T_3 V_110 , T_5 * V_24 ,
T_9 * V_30 , T_17 * V_83 , V_3 * * V_177 , void * V_1 )
{
T_18 V_178 ;
const char * V_179 ;
const char * V_180 ;
T_4 * V_147 ;
T_19 V_96 ;
T_6 V_97 = 0 ;
V_3 * V_169 ;
int V_181 ;
V_96 = V_30 -> V_98 ;
V_30 -> V_96 = V_96 ;
V_30 -> V_98 = V_96 - ( V_96 > 0 ) ;
V_178 = FALSE ;
V_179 = V_30 -> V_57 ;
V_180 = V_30 -> V_182 ;
V_97 = F_77 ( V_30 -> V_74 ) ;
* V_177 = NULL ;
for ( V_147 = V_110 -> V_7 ; V_147 != NULL ;
V_147 = F_136 ( V_147 ) ) {
V_30 -> V_98 = V_96 - ( V_96 > 0 ) ;
V_169 = ( V_3 * ) V_147 -> V_1 ;
if ( V_169 -> V_89 != NULL &&
( ! F_76 ( V_169 -> V_89 ) || ( V_169 -> V_172 == FALSE ) ) ) {
continue;
}
V_181 = F_80 ( V_169 -> V_89 ) ;
if ( V_169 -> V_89 != NULL ) {
V_30 -> V_57 =
F_74 ( V_169 -> V_89 ) ;
F_78 ( V_30 -> V_74 , F_79 ( V_181 ) ) ;
}
V_30 -> V_182 = V_169 -> V_4 ;
if ( ( V_169 -> V_91 ) ( V_24 , V_30 , V_83 , V_1 ) ) {
* V_177 = V_169 ;
V_178 = TRUE ;
break;
} else {
while ( F_77 ( V_30 -> V_74 ) > V_97 ) {
F_82 ( V_30 -> V_74 , F_83 ( V_30 -> V_74 ) ) ;
}
}
}
V_30 -> V_57 = V_179 ;
V_30 -> V_182 = V_180 ;
V_30 -> V_98 = V_96 ;
return V_178 ;
}
static void
F_166 ( T_1 V_1 , T_1 T_2 )
{
T_38 * V_150 ;
F_14 ( V_1 ) ;
F_14 ( T_2 ) ;
V_150 = ( T_38 * ) T_2 ;
V_150 -> V_151 ( V_150 -> V_152 , ( V_3 * ) V_1 ,
V_150 -> V_154 ) ;
}
void
F_167 ( const char * V_152 ,
T_39 F_21 ,
T_1 T_2 )
{
T_38 V_150 ;
T_3 V_110 = F_153 ( V_152 ) ;
V_150 . V_152 = V_152 ;
V_150 . V_151 = F_21 ;
V_150 . V_154 = T_2 ;
F_5 ( V_110 -> V_7 ,
F_166 , & V_150 ) ;
}
static void
F_168 ( T_1 T_24 , const T_1 V_128 , const T_1 T_2 )
{
T_40 * V_150 ;
V_150 = ( T_40 * ) T_2 ;
(* V_150 -> V_151 )( ( T_15 * ) T_24 , (struct V_8 * ) V_128 , V_150 -> V_154 ) ;
}
static void
F_169 ( T_1 T_24 , T_1 T_2 )
{
struct V_8 * V_6 ;
T_40 * V_150 ;
V_6 = (struct V_8 * ) F_87 ( V_17 , T_24 ) ;
V_150 = ( T_40 * ) T_2 ;
(* V_150 -> V_151 )( ( T_15 * ) T_24 , V_6 , V_150 -> V_154 ) ;
}
void
F_170 ( T_41 F_21 ,
T_1 T_2 ,
V_148 V_158 )
{
T_40 V_150 ;
T_33 * V_6 ;
V_150 . V_154 = T_2 ;
V_150 . V_151 = F_21 ;
if ( V_158 != NULL )
{
V_6 = F_143 ( V_13 ) ;
V_6 = F_144 ( V_6 , V_158 ) ;
F_145 ( V_6 , F_169 , & V_150 ) ;
F_146 ( V_6 ) ;
}
else
{
F_104 ( V_17 , F_168 , & V_150 ) ;
}
}
static void
F_171 ( const char * V_152 ,
V_3 * V_169 , T_1 T_2 V_2 )
{
if ( V_169 -> V_89 != NULL ) {
printf ( L_23 ,
V_152 ,
F_124 ( F_80 ( V_169 -> V_89 ) ) ,
( F_76 ( V_169 -> V_89 ) && V_169 -> V_172 ) ? 'T' : 'F' ) ;
}
}
static void
F_172 ( const T_15 * V_152 , struct V_8 * T_42 V_2 , const T_1 T_2 V_2 )
{
F_167 ( V_152 , F_171 , NULL ) ;
}
void
F_173 ( void )
{
F_170 ( F_172 , NULL , NULL ) ;
}
T_3
F_174 ( const char * V_31 )
{
T_3 V_110 ;
if ( F_87 ( V_17 , V_31 ) != NULL ) {
F_148 ( L_24 , V_31 ) ;
}
V_110 = F_43 ( struct V_8 ) ;
V_110 -> V_7 = NULL ;
F_92 ( V_17 , ( T_1 ) V_31 ,
( T_1 ) V_110 ) ;
return V_110 ;
}
const char *
F_175 ( const T_16 V_86 )
{
if ( V_86 == NULL || V_86 -> V_89 == NULL ) {
return NULL ;
}
return F_90 ( V_86 -> V_89 ) ;
}
const char *
F_176 ( const T_16 V_86 )
{
if ( V_86 -> V_89 == NULL ) {
return NULL ;
}
return F_74 ( V_86 -> V_89 ) ;
}
int
F_177 ( const T_16 V_86 )
{
if ( V_86 -> V_89 == NULL ) {
return - 1 ;
}
return F_80 ( V_86 -> V_89 ) ;
}
T_33 *
F_178 ( void )
{
return F_143 ( V_16 ) ;
}
T_16
F_13 ( const char * V_31 )
{
return ( T_16 ) F_87 ( V_16 , V_31 ) ;
}
const char *
F_179 ( const T_16 V_86 )
{
if ( V_86 == NULL ) {
return NULL ;
}
return V_86 -> V_31 ;
}
T_16
F_180 ( T_43 V_91 , const int V_166 )
{
struct V_130 * V_86 ;
V_86 = F_181 ( F_182 () , struct V_130 ) ;
V_86 -> V_31 = NULL ;
V_86 -> V_90 = FALSE ;
V_86 -> V_91 . V_93 = V_91 ;
V_86 -> V_89 = F_160 ( V_166 ) ;
return V_86 ;
}
T_16
F_183 ( T_44 V_91 , const int V_166 )
{
struct V_130 * V_86 ;
V_86 = F_181 ( F_182 () , struct V_130 ) ;
V_86 -> V_31 = NULL ;
V_86 -> V_90 = TRUE ;
V_86 -> V_91 . V_92 = V_91 ;
V_86 -> V_89 = F_160 ( V_166 ) ;
return V_86 ;
}
T_16 F_184 ( T_44 V_91 ,
const int V_166 , const char * V_31 )
{
struct V_130 * V_86 ;
V_86 = F_181 ( F_182 () , struct V_130 ) ;
V_86 -> V_31 = V_31 ;
V_86 -> V_90 = TRUE ;
V_86 -> V_91 . V_92 = V_91 ;
V_86 -> V_89 = F_160 ( V_166 ) ;
return V_86 ;
}
void
F_185 ( T_16 V_86 )
{
if ( V_86 == NULL ) return;
F_103 ( V_86 ) ;
F_186 ( V_86 ) ;
F_187 ( F_182 () , V_86 ) ;
}
T_16
F_188 ( const char * V_31 , T_43 V_91 , const int V_166 )
{
struct V_130 * V_86 ;
F_14 ( F_87 ( V_16 , V_31 ) == NULL ) ;
V_86 = F_181 ( F_182 () , struct V_130 ) ;
V_86 -> V_31 = V_31 ;
V_86 -> V_90 = FALSE ;
V_86 -> V_91 . V_93 = V_91 ;
V_86 -> V_89 = F_160 ( V_166 ) ;
F_92 ( V_16 , ( T_1 ) V_31 ,
( T_1 ) V_86 ) ;
return V_86 ;
}
T_16
F_189 ( const char * V_31 , T_44 V_91 , const int V_166 )
{
struct V_130 * V_86 ;
F_14 ( F_87 ( V_16 , V_31 ) == NULL ) ;
V_86 = F_181 ( F_182 () , struct V_130 ) ;
V_86 -> V_31 = V_31 ;
V_86 -> V_90 = TRUE ;
V_86 -> V_91 . V_92 = V_91 ;
V_86 -> V_89 = F_160 ( V_166 ) ;
F_92 ( V_16 , ( T_1 ) V_31 ,
( T_1 ) V_86 ) ;
return V_86 ;
}
void
F_190 ( const char * V_31 )
{
T_16 V_86 = F_13 ( V_31 ) ;
if ( V_86 == NULL ) return;
F_96 ( V_16 , ( T_1 ) V_31 ) ;
F_96 ( V_17 , ( T_1 ) V_31 ) ;
F_185 ( V_86 ) ;
}
int
F_191 ( T_16 V_86 , T_5 * V_24 ,
T_9 * V_30 , T_17 * V_83 , void * V_1 )
{
int V_133 ;
F_14 ( V_86 != NULL ) ;
V_133 = F_75 ( V_86 , V_24 , V_30 , V_83 , TRUE , V_1 ) ;
return V_133 ;
}
int
F_68 ( T_16 V_86 , T_5 * V_24 ,
T_9 * V_30 , T_17 * V_83 , void * V_1 )
{
int V_133 ;
V_133 = F_191 ( V_86 , V_24 , V_30 , V_83 , V_1 ) ;
if ( V_133 == 0 ) {
F_14 ( V_22 -> V_89 != NULL ) ;
F_75 ( V_22 , V_24 , V_30 , V_83 , TRUE , NULL ) ;
return F_50 ( V_24 ) ;
}
return V_133 ;
}
int
F_192 ( T_16 V_86 , T_5 * V_24 ,
T_9 * V_30 , T_17 * V_83 )
{
return F_68 ( V_86 , V_24 , V_30 , V_83 , NULL ) ;
}
void F_193 ( V_3 * V_177 , T_5 * V_24 ,
T_9 * V_30 , T_17 * V_83 , void * V_1 )
{
const char * V_179 ;
const char * V_180 ;
T_19 V_96 ;
F_14 ( V_177 ) ;
V_96 = V_30 -> V_98 ;
V_30 -> V_96 = V_96 ;
V_30 -> V_98 = V_96 - ( V_96 > 0 ) ;
V_179 = V_30 -> V_57 ;
V_180 = V_30 -> V_182 ;
if ( ! V_177 -> V_172 ||
( V_177 -> V_89 != NULL && ! F_76 ( V_177 -> V_89 ) ) ) {
F_14 ( V_22 -> V_89 != NULL ) ;
F_75 ( V_22 , V_24 , V_30 , V_83 , TRUE , NULL ) ;
return;
}
if ( V_177 -> V_89 != NULL ) {
V_30 -> V_57 = F_74 ( V_177 -> V_89 ) ;
F_78 ( V_30 -> V_74 , F_79 ( F_80 ( V_177 -> V_89 ) ) ) ;
}
V_30 -> V_182 = V_177 -> V_4 ;
if( ! (* V_177 -> V_91 )( V_24 , V_30 , V_83 , V_1 ) )
F_62 () ;
V_30 -> V_98 = V_96 ;
V_30 -> V_57 = V_179 ;
V_30 -> V_182 = V_180 ;
}
static void
F_194 ( const T_15 * V_152 ,
T_27 V_153 V_2 , const T_1 T_24 , const T_1 V_128 ,
T_1 T_2 V_2 )
{
T_10 V_183 = F_195 ( T_24 ) ;
T_21 V_110 = F_86 ( V_152 ) ;
T_22 * V_116 ;
T_16 V_86 ;
T_25 V_181 ;
const T_15 * V_184 ;
F_14 ( V_110 ) ;
switch ( V_110 -> type ) {
case V_112 :
case V_113 :
case V_114 :
case V_115 :
V_116 = ( T_22 * ) V_128 ;
F_14 ( V_116 ) ;
V_86 = V_116 -> V_118 ;
F_14 ( V_86 ) ;
V_181 = F_177 ( V_86 ) ;
if ( V_181 != - 1 ) {
V_184 = F_124 ( V_181 ) ;
F_14 ( V_184 != NULL ) ;
printf ( L_25 , V_152 , V_183 , V_184 ) ;
}
break;
default:
break;
}
}
void
F_196 ( void )
{
F_133 ( F_194 , NULL ) ;
}
static void
F_197 ( T_1 T_24 , T_1 T_2 V_2 )
{
const char * V_152 = ( const char * ) T_24 ;
T_21 V_10 ;
V_10 = ( T_21 ) F_87 ( V_13 , T_24 ) ;
printf ( L_26 , V_152 , V_10 -> V_157 , F_198 ( V_10 -> type ) ) ;
switch ( V_10 -> type ) {
case V_112 :
case V_113 :
case V_114 :
case V_115 :
switch( V_10 -> V_137 ) {
case V_163 :
printf ( L_27 ) ;
break;
case V_185 :
printf ( L_28 ) ;
break;
case V_186 :
printf ( L_29 ) ;
break;
case V_187 :
printf ( L_30 ) ;
break;
case V_188 :
printf ( L_31 ) ;
break;
default:
printf ( L_32 , V_10 -> V_137 ) ;
break;
}
break;
default:
break;
}
printf ( L_33 ) ;
}
static T_25
F_199 ( T_26 V_141 , T_26 V_142 )
{
return strcmp ( ( const char * ) V_141 , ( const char * ) V_142 ) ;
}
void
F_200 ( void )
{
T_33 * V_6 ;
V_6 = F_143 ( V_13 ) ;
V_6 = F_144 ( V_6 , F_199 ) ;
F_145 ( V_6 , F_197 , NULL ) ;
F_146 ( V_6 ) ;
}
void
F_201 ( T_16 V_86 )
{
if ( ! V_189 )
V_189 = F_202 () ;
F_203 ( V_189 , V_86 ) ;
V_190 ++ ;
}
void
F_186 ( T_16 V_86 )
{
if ( ! V_189 ) return;
if ( F_204 ( V_189 , V_86 ) ) {
V_190 -- ;
}
}
T_18
F_205 ( void )
{
T_6 V_122 ;
T_16 V_86 ;
for( V_122 = 0 ; V_122 < V_190 ; V_122 ++ ) {
V_86 = ( T_16 ) F_206 ( V_189 , V_122 ) ;
if ( V_86 -> V_89 != NULL
&& F_76 ( V_86 -> V_89 ) ) {
return TRUE ;
}
}
return FALSE ;
}
void
F_207 ( T_5 * V_24 , T_9 * V_30 , T_17 * V_83 )
{
T_6 V_122 ;
for( V_122 = 0 ; V_122 < V_190 ; V_122 ++ ) {
F_191 ( ( T_16 ) F_206 ( V_189 , V_122 ) ,
V_24 , V_30 , V_83 , NULL ) ;
}
}
