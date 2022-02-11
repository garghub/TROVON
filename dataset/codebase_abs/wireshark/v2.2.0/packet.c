static void
F_1 ( void * V_1 )
{
T_1 V_2 = ( T_1 ) V_1 ;
T_2 * * V_3 = & ( V_2 -> V_4 ) ;
F_2 ( * V_3 , ( V_5 ) V_6 , NULL ) ;
F_3 ( * V_3 ) ;
F_4 ( struct V_7 , V_2 ) ;
}
static void
F_5 ( T_3 V_1 , T_3 T_4 V_8 )
{
V_6 ( ( ( V_9 * ) V_1 ) -> V_10 ) ;
F_4 ( V_9 , V_1 ) ;
}
static void
F_6 ( void * V_1 )
{
T_5 V_2 = ( T_5 ) V_1 ;
T_2 * * V_3 = & ( V_2 -> V_4 ) ;
F_2 ( * V_3 , F_5 , NULL ) ;
F_3 ( * V_3 ) ;
F_4 ( struct V_11 , V_2 ) ;
}
static void
F_7 ( void * V_1 )
{
struct V_12 * V_13 = (struct V_12 * ) V_1 ;
F_8 ( V_13 -> V_14 ) ;
F_3 ( V_13 -> V_15 ) ;
F_4 ( struct V_12 , V_1 ) ;
}
void
F_9 ( void )
{
V_16 = F_10 ( V_17 , V_18 ,
NULL , F_7 ) ;
V_19 = F_10 ( V_17 , V_18 ,
NULL , NULL ) ;
V_20 = F_10 ( V_17 , V_18 ,
V_6 , F_1 ) ;
V_21 = F_10 ( V_17 , V_18 ,
NULL , F_6 ) ;
V_22 = F_11 ( V_23 , V_18 ) ;
}
void
F_12 ( void )
{
V_24 = F_13 ( L_1 ) ;
F_14 ( V_24 != NULL ) ;
V_25 = F_13 ( L_2 ) ;
F_14 ( V_25 != NULL ) ;
V_26 = F_13 ( L_3 ) ;
F_14 ( V_26 != NULL ) ;
V_27 = F_15 ( L_4 ) ;
F_14 ( V_27 != - 1 ) ;
}
void
F_16 ( void )
{
F_8 ( V_16 ) ;
F_8 ( V_19 ) ;
F_8 ( V_20 ) ;
F_8 ( V_21 ) ;
F_8 ( V_22 ) ;
}
void
F_17 ( T_6 * V_28 , const T_7 V_29 )
{
if ( V_29 < F_18 ( V_28 ) ) {
F_19 ( V_28 , V_29 ) ;
}
}
void
F_20 ( void (* F_21)( void ) )
{
V_30 = F_22 ( V_30 , ( T_3 ) F_21 ) ;
}
void
F_23 ( void (* F_21)( void ) )
{
V_31 = F_22 ( V_31 , ( T_3 ) F_21 ) ;
}
static void
F_24 ( T_3 V_32 , T_3 T_8 V_8 )
{
T_9 F_21 = ( T_9 ) V_32 ;
(* F_21)() ;
}
void
F_25 ( void )
{
F_26 () ;
F_27 () ;
F_28 () ;
F_29 () ;
F_2 ( V_30 , & F_24 , NULL ) ;
F_30 () ;
F_31 () ;
}
void
F_32 ( void )
{
F_33 () ;
F_34 () ;
F_2 ( V_31 , & F_24 , NULL ) ;
F_35 () ;
F_36 () ;
F_37 () ;
F_38 () ;
}
void
F_39 ( T_9 F_21 )
{
V_33 = F_22 ( V_33 ,
( T_3 ) F_21 ) ;
}
static void
F_40 ( T_3 V_32 , T_3 T_8 V_8 )
{
T_9 F_21 = ( T_9 ) V_32 ;
(* F_21)() ;
}
void
F_41 ( void )
{
F_2 ( V_33 ,
& F_40 , NULL ) ;
}
void
F_42 ( T_10 * V_34 , T_6 * V_28 , const char * V_35 )
{
struct V_36 * V_37 ;
V_37 = F_43 ( V_34 -> V_38 , struct V_36 ) ;
V_37 -> V_28 = V_28 ;
V_37 -> V_35 = F_44 ( V_34 -> V_38 , V_35 ) ;
V_34 -> V_39 = F_45 ( V_34 -> V_39 , V_37 ) ;
}
void
F_46 ( T_10 * V_34 )
{
T_2 * V_40 ;
V_40 = F_47 ( V_34 -> V_39 ) ;
V_34 -> V_39 = F_48 ( V_34 -> V_39 , V_40 ) ;
}
char *
F_49 ( const struct V_36 * V_37 )
{
T_7 V_41 = F_50 ( V_37 -> V_28 ) ;
return F_51 ( NULL , L_5 , V_37 -> V_35 , V_41 ,
F_52 ( V_41 , L_6 , L_7 ) ) ;
}
T_6 *
F_53 ( const struct V_36 * V_37 )
{
return V_37 -> V_28 ;
}
void
F_54 ( T_10 * V_34 )
{
if ( V_34 -> V_39 ) {
F_3 ( V_34 -> V_39 ) ;
V_34 -> V_39 = NULL ;
}
}
void
F_55 ( T_10 * V_34 , T_11 V_42 )
{
if ( V_42 != V_34 -> V_43 ) {
V_34 -> V_44 = F_22 ( V_34 -> V_44 , F_56 ( V_42 ) ) ;
}
}
void
F_57 ( void (* F_21)( void ) )
{
V_45 = F_22 ( V_45 ,
( T_3 ) F_21 ) ;
}
static void
F_58 ( T_3 V_32 , T_3 T_8 V_8 )
{
T_9 F_21 = ( T_9 ) V_32 ;
(* F_21)() ;
}
void
F_59 ( void )
{
F_2 ( V_45 ,
& F_58 , NULL ) ;
}
void
F_60 ( T_12 * V_46 , int V_47 ,
struct V_48 * V_49 , T_6 * V_28 , T_13 * V_50 , T_14 * V_51 )
{
const char * volatile V_52 ;
T_15 V_53 ;
switch ( V_49 -> V_54 ) {
case V_55 :
V_52 = L_8 ;
break;
case V_56 :
V_52 = L_9 ;
break;
case V_57 :
V_52 = L_10 ;
break;
case V_58 :
V_52 = L_11 ;
break;
default:
F_61 () ;
break;
}
if ( V_51 != NULL )
F_62 ( V_51 , V_46 -> V_59 ) ;
V_46 -> V_60 . V_61 = V_46 -> V_59 ;
V_46 -> V_60 . V_62 = L_12 ;
V_46 -> V_60 . V_51 = V_51 ;
V_46 -> V_60 . V_63 = 0 ;
V_46 -> V_60 . V_43 = V_50 -> V_43 ;
if ( V_50 -> V_64 . V_65 ) {
V_46 -> V_60 . V_63 |= V_66 ;
V_46 -> V_60 . V_67 = V_50 -> V_67 ;
}
V_46 -> V_60 . V_68 = V_49 -> V_68 ;
V_46 -> V_60 . V_50 = V_50 ;
V_46 -> V_60 . V_49 = V_49 ;
V_46 -> V_60 . V_69 = & V_49 -> V_69 ;
F_63 ( & V_46 -> V_60 . V_70 ) ;
F_63 ( & V_46 -> V_60 . V_71 ) ;
F_63 ( & V_46 -> V_60 . V_72 ) ;
F_63 ( & V_46 -> V_60 . V_73 ) ;
F_63 ( & V_46 -> V_60 . V_37 ) ;
F_63 ( & V_46 -> V_60 . V_74 ) ;
V_46 -> V_60 . V_75 = V_76 ;
V_46 -> V_60 . V_77 = L_6 ;
V_46 -> V_60 . V_78 = V_79 ;
V_46 -> V_60 . V_80 = V_81 ;
V_46 -> V_60 . V_82 = V_83 ;
V_46 -> V_60 . V_84 = F_64 ( V_46 -> V_60 . V_38 ) ;
V_46 -> V_28 = V_28 ;
F_65 ( V_46 -> V_59 , V_50 , V_50 -> V_85 , & V_46 -> V_60 . V_86 ) ;
if ( V_50 -> V_64 . V_87 )
V_53 . V_88 = F_66 ( V_46 -> V_59 , V_50 ) ;
else if ( V_50 -> V_64 . V_89 )
V_53 . V_88 = V_49 -> V_90 ;
else
V_53 . V_88 = NULL ;
V_53 . V_47 = V_47 ;
V_53 . V_91 = V_46 ;
F_67 {
F_42 ( & V_46 -> V_60 , V_46 -> V_28 , V_52 ) ;
F_68 ( V_24 , V_46 -> V_28 , & V_46 -> V_60 , V_46 -> V_92 , & V_53 ) ;
}
F_69 (BoundsError) {
F_61 () ;
}
F_70 (FragmentBoundsError, ReportedBoundsError) {
F_71 ( V_46 -> V_92 , V_27 , V_46 -> V_28 , 0 , 0 ,
L_13 ,
V_52 ) ;
}
V_93 ;
V_50 -> V_64 . V_94 = 1 ;
}
void
F_72 ( T_12 * V_46 , struct V_48 * V_49 ,
T_6 * V_28 , T_13 * V_50 , T_14 * V_51 )
{
T_16 V_95 ;
if ( V_51 != NULL )
F_62 ( V_51 , V_46 -> V_59 ) ;
V_46 -> V_60 . V_61 = V_46 -> V_59 ;
V_46 -> V_60 . V_62 = L_14 ;
V_46 -> V_60 . V_51 = V_51 ;
V_46 -> V_60 . V_50 = V_50 ;
V_46 -> V_60 . V_49 = V_49 ;
V_46 -> V_60 . V_69 = & V_49 -> V_69 ;
F_63 ( & V_46 -> V_60 . V_70 ) ;
F_63 ( & V_46 -> V_60 . V_71 ) ;
F_63 ( & V_46 -> V_60 . V_72 ) ;
F_63 ( & V_46 -> V_60 . V_73 ) ;
F_63 ( & V_46 -> V_60 . V_37 ) ;
F_63 ( & V_46 -> V_60 . V_74 ) ;
V_46 -> V_60 . V_75 = V_76 ;
V_46 -> V_60 . V_77 = L_6 ;
V_46 -> V_60 . V_78 = V_79 ;
V_46 -> V_60 . V_80 = V_81 ;
V_46 -> V_60 . V_82 = V_83 ;
V_46 -> V_60 . V_84 = F_64 ( V_46 -> V_60 . V_38 ) ;
V_46 -> V_28 = V_28 ;
F_65 ( V_46 -> V_59 , V_50 , V_50 -> V_85 , & V_46 -> V_60 . V_86 ) ;
F_67 {
if ( V_50 -> V_64 . V_87 )
V_95 . V_88 = F_66 ( V_46 -> V_59 , V_50 ) ;
else if ( V_50 -> V_64 . V_89 )
V_95 . V_88 = V_49 -> V_90 ;
else
V_95 . V_88 = NULL ;
V_95 . V_91 = V_46 ;
F_42 ( & V_46 -> V_60 , V_46 -> V_28 , L_15 ) ;
F_68 ( V_25 , V_46 -> V_28 , & V_46 -> V_60 , V_46 -> V_92 , & V_95 ) ;
}
F_69 (BoundsError) {
F_61 () ;
}
F_70 (FragmentBoundsError, ReportedBoundsError) {
F_71 ( V_46 -> V_92 , V_27 , V_46 -> V_28 , 0 , 0 ,
L_16 ) ;
}
V_93 ;
V_50 -> V_64 . V_94 = 1 ;
}
static int
F_73 ( T_17 V_96 , T_6 * V_28 ,
T_10 * V_34 , T_18 * V_92 , void * V_1 )
{
const char * V_97 ;
int V_98 ;
V_97 = V_34 -> V_62 ;
if ( V_96 -> V_99 != NULL ) {
V_34 -> V_62 =
F_74 ( V_96 -> V_99 ) ;
}
V_98 = (* V_96 -> V_100 )( V_28 , V_34 , V_92 , V_1 ) ;
V_34 -> V_62 = V_97 ;
return V_98 ;
}
static int
F_75 ( T_17 V_96 , T_6 * V_28 , T_10 * V_101 ,
T_18 * V_92 , T_19 V_102 , void * V_1 )
{
T_10 * V_34 = V_101 ;
const char * V_97 ;
T_20 V_103 ;
int V_98 ;
T_7 V_104 = 0 ;
if ( V_96 -> V_99 != NULL &&
! F_76 ( V_96 -> V_99 ) ) {
return 0 ;
}
V_97 = V_34 -> V_62 ;
V_103 = V_34 -> V_105 ;
V_104 = F_77 ( V_34 -> V_84 ) ;
V_34 -> V_103 = V_103 ;
V_34 -> V_105 = V_103 - ( V_103 > 0 ) ;
if ( V_96 -> V_99 != NULL ) {
V_34 -> V_62 =
F_74 ( V_96 -> V_99 ) ;
if ( V_102 ) {
V_34 -> V_106 ++ ;
F_78 ( V_34 -> V_84 , F_79 ( F_80 ( V_96 -> V_99 ) ) ) ;
}
}
if ( V_34 -> V_64 . V_107 ) {
V_98 = F_81 ( V_96 , V_28 , V_34 , V_92 , V_1 ) ;
} else {
V_98 = F_73 ( V_96 , V_28 , V_34 , V_92 , V_1 ) ;
}
if ( V_98 == 0 ) {
while ( F_77 ( V_34 -> V_84 ) > V_104 ) {
F_82 ( V_34 -> V_84 , F_83 ( V_34 -> V_84 ) ) ;
}
}
V_34 -> V_62 = V_97 ;
V_34 -> V_105 = V_103 ;
return V_98 ;
}
static int
F_81 ( T_17 V_96 , T_6 * V_28 ,
T_10 * V_101 , T_18 * V_92 , void * V_1 )
{
T_10 * V_34 = V_101 ;
const char * V_97 ;
T_20 V_103 ;
volatile int V_98 = 0 ;
T_19 V_108 ;
T_21 V_109 ;
T_21 V_110 ;
T_21 V_111 ;
T_21 V_112 ;
T_21 V_113 ;
T_21 V_114 ;
V_97 = V_34 -> V_62 ;
V_103 = V_34 -> V_105 ;
V_108 = F_84 ( V_34 -> V_51 , - 1 ) ;
F_85 ( V_34 -> V_51 , - 1 , FALSE ) ;
F_86 ( & V_109 , & V_34 -> V_70 ) ;
F_86 ( & V_110 , & V_34 -> V_71 ) ;
F_86 ( & V_111 , & V_34 -> V_72 ) ;
F_86 ( & V_112 , & V_34 -> V_73 ) ;
F_86 ( & V_113 , & V_34 -> V_37 ) ;
F_86 ( & V_114 , & V_34 -> V_74 ) ;
F_67 {
V_98 = F_73 ( V_96 , V_28 , V_34 , V_92 , V_1 ) ;
}
F_69 (BoundsError) {
F_85 ( V_34 -> V_51 , - 1 , V_108 ) ;
F_86 ( & V_34 -> V_70 , & V_109 ) ;
F_86 ( & V_34 -> V_71 , & V_110 ) ;
F_86 ( & V_34 -> V_72 , & V_111 ) ;
F_86 ( & V_34 -> V_73 , & V_112 ) ;
F_86 ( & V_34 -> V_37 , & V_113 ) ;
F_86 ( & V_34 -> V_74 , & V_114 ) ;
V_34 -> V_62 = V_97 ;
V_34 -> V_105 = V_103 ;
V_115 ;
}
F_70 (FragmentBoundsError, ReportedBoundsError) {
V_98 = F_50 ( V_28 ) ;
}
V_93 ;
F_85 ( V_34 -> V_51 , - 1 , V_108 ) ;
F_86 ( & V_34 -> V_70 , & V_109 ) ;
F_86 ( & V_34 -> V_71 , & V_110 ) ;
F_86 ( & V_34 -> V_72 , & V_111 ) ;
F_86 ( & V_34 -> V_73 , & V_112 ) ;
F_86 ( & V_34 -> V_37 , & V_113 ) ;
F_86 ( & V_34 -> V_74 , & V_114 ) ;
V_34 -> V_116 = 0 ;
return V_98 ;
}
T_22
F_87 ( const char * V_35 )
{
return ( T_22 ) F_88 ( V_16 , V_35 ) ;
}
static T_23 *
F_89 ( T_22 V_117 , const T_11 V_118 )
{
switch ( V_117 -> type ) {
case V_119 :
case V_120 :
case V_121 :
case V_122 :
break;
default:
F_61 () ;
}
return ( T_23 * ) F_88 ( V_117 -> V_14 ,
F_56 ( V_118 ) ) ;
}
void
F_90 ( const char * V_35 , const T_11 V_118 , T_17 V_96 )
{
T_22 V_117 ;
T_23 * V_123 ;
V_117 = F_87 ( V_35 ) ;
if ( V_96 == NULL ) {
fprintf ( V_124 , L_17 ,
V_35 ) ;
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
if ( V_117 == NULL ) {
fprintf ( V_124 , L_19 ,
V_35 ) ;
fprintf ( V_124 , L_20 ,
F_91 ( V_96 -> V_99 ) ) ;
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
switch ( V_117 -> type ) {
case V_119 :
case V_120 :
case V_121 :
case V_122 :
break;
default:
F_61 () ;
}
#if 0
dissector_add_uint_sanity_check(name, pattern, handle, sub_dissectors);
#endif
V_123 = ( T_23 * ) F_92 ( sizeof ( T_23 ) ) ;
V_123 -> V_125 = V_96 ;
V_123 -> V_126 = V_123 -> V_125 ;
F_93 ( V_117 -> V_14 ,
F_56 ( V_118 ) , ( T_3 ) V_123 ) ;
if ( V_117 -> V_127 )
F_94 ( V_35 , V_96 ) ;
}
void F_95 ( const char * V_128 , T_24 * V_129 ,
T_17 V_96 )
{
T_11 V_130 , V_131 ;
if ( V_129 ) {
for ( V_130 = 0 ; V_130 < V_129 -> V_132 ; V_130 ++ ) {
for ( V_131 = V_129 -> V_133 [ V_130 ] . V_134 ; V_131 < V_129 -> V_133 [ V_130 ] . V_135 ; V_131 ++ )
F_90 ( V_128 , V_131 , V_96 ) ;
F_90 ( V_128 , V_129 -> V_133 [ V_130 ] . V_135 , V_96 ) ;
}
}
}
void
F_96 ( const char * V_35 , const T_11 V_118 ,
T_17 V_96 V_8 )
{
T_22 V_117 = F_87 ( V_35 ) ;
T_23 * V_123 ;
F_14 ( V_117 ) ;
V_123 = F_89 ( V_117 , V_118 ) ;
if ( V_123 != NULL ) {
F_97 ( V_117 -> V_14 ,
F_56 ( V_118 ) ) ;
}
}
void F_98 ( const char * V_128 , T_24 * V_129 ,
T_17 V_96 )
{
T_11 V_130 , V_131 ;
if ( V_129 ) {
for ( V_130 = 0 ; V_130 < V_129 -> V_132 ; V_130 ++ ) {
for ( V_131 = V_129 -> V_133 [ V_130 ] . V_134 ; V_131 < V_129 -> V_133 [ V_130 ] . V_135 ; V_131 ++ )
F_96 ( V_128 , V_131 , V_96 ) ;
F_96 ( V_128 , V_129 -> V_133 [ V_130 ] . V_135 , V_96 ) ;
}
}
}
static T_19
F_99 ( T_3 T_25 V_8 , T_3 V_136 , T_3 T_4 )
{
T_23 * V_123 = ( T_23 * ) V_136 ;
T_17 V_96 = ( T_17 ) T_4 ;
if ( ! V_123 -> V_125 -> V_99 ) {
return FALSE ;
}
return ( F_80 ( V_123 -> V_125 -> V_99 ) == F_80 ( V_96 -> V_99 ) ) ;
}
void F_100 ( const char * V_35 , T_17 V_96 )
{
T_22 V_117 = F_87 ( V_35 ) ;
F_14 ( V_117 ) ;
F_101 ( V_117 -> V_14 , F_99 , V_96 ) ;
}
static void
F_102 ( T_3 T_25 V_8 , T_3 V_136 , T_3 T_4 )
{
T_22 V_117 = ( T_22 ) V_136 ;
F_14 ( V_117 ) ;
F_101 ( V_117 -> V_14 , F_99 , T_4 ) ;
V_117 -> V_15 = F_103 ( V_117 -> V_15 , T_4 ) ;
}
static void
F_104 ( T_17 V_96 )
{
F_105 ( V_16 , F_102 , V_96 ) ;
}
void
F_106 ( const char * V_35 , const T_11 V_118 , T_17 V_96 )
{
T_22 V_117 = F_87 ( V_35 ) ;
T_23 * V_123 ;
F_14 ( V_117 ) ;
V_123 = F_89 ( V_117 , V_118 ) ;
if ( V_123 != NULL ) {
V_123 -> V_125 = V_96 ;
return;
}
if ( V_96 == NULL )
return;
V_123 = ( T_23 * ) F_92 ( sizeof ( T_23 ) ) ;
V_123 -> V_126 = NULL ;
V_123 -> V_125 = V_96 ;
F_93 ( V_117 -> V_14 ,
F_56 ( V_118 ) , ( T_3 ) V_123 ) ;
}
void
F_107 ( const char * V_35 , const T_11 V_118 )
{
T_22 V_117 = F_87 ( V_35 ) ;
T_23 * V_123 ;
F_14 ( V_117 ) ;
V_123 = F_89 ( V_117 , V_118 ) ;
if ( V_123 == NULL )
return;
if ( V_123 -> V_126 != NULL ) {
V_123 -> V_125 = V_123 -> V_126 ;
} else {
F_97 ( V_117 -> V_14 ,
F_56 ( V_118 ) ) ;
}
}
int
F_108 ( T_22 V_117 , const T_11 V_137 ,
T_6 * V_28 , T_10 * V_34 , T_18 * V_92 ,
const T_19 V_102 , void * V_1 )
{
T_23 * V_123 ;
struct V_138 * V_96 ;
T_11 V_139 ;
int V_98 ;
V_123 = F_89 ( V_117 , V_137 ) ;
if ( V_123 != NULL ) {
V_96 = V_123 -> V_125 ;
if ( V_96 == NULL ) {
return 0 ;
}
V_139 = V_34 -> V_140 ;
V_34 -> V_140 = V_137 ;
V_98 = F_75 ( V_96 , V_28 , V_34 , V_92 , V_102 , V_1 ) ;
V_34 -> V_140 = V_139 ;
return V_98 ;
}
return 0 ;
}
int
F_109 ( T_22 V_117 , const T_11 V_137 ,
T_6 * V_28 , T_10 * V_34 , T_18 * V_92 )
{
return F_108 ( V_117 , V_137 , V_28 , V_34 , V_92 , TRUE , NULL ) ;
}
T_17
F_110 ( T_22 const V_117 , const T_11 V_137 )
{
T_23 * V_123 ;
V_123 = F_89 ( V_117 , V_137 ) ;
if ( V_123 != NULL )
return V_123 -> V_125 ;
else
return NULL ;
}
T_17
F_111 ( const char * V_35 , const T_11 V_137 )
{
T_22 V_117 = F_87 ( V_35 ) ;
if ( V_117 != NULL ) {
T_23 * V_123 = F_89 ( V_117 , V_137 ) ;
if ( V_123 != NULL )
return V_123 -> V_126 ;
}
return NULL ;
}
static T_23 *
F_112 ( T_22 const V_117 , const T_26 * V_118 )
{
T_23 * V_141 ;
char * T_25 ;
switch ( V_117 -> type ) {
case V_142 :
case V_143 :
case V_144 :
break;
default:
F_61 () ;
}
if ( V_117 -> V_145 == TRUE ) {
T_25 = F_113 ( V_118 , - 1 ) ;
} else {
T_25 = F_114 ( V_118 ) ;
}
V_141 = ( T_23 * ) F_88 ( V_117 -> V_14 , T_25 ) ;
V_6 ( T_25 ) ;
return V_141 ;
}
void
F_115 ( const char * V_35 , const T_26 * V_118 ,
T_17 V_96 )
{
T_22 V_117 = F_87 ( V_35 ) ;
T_23 * V_123 ;
char * T_25 ;
if ( V_96 == NULL ) {
fprintf ( V_124 , L_17 ,
V_35 ) ;
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
if ( V_117 == NULL ) {
fprintf ( V_124 , L_19 ,
V_35 ) ;
fprintf ( V_124 , L_20 ,
F_91 ( V_96 -> V_99 ) ) ;
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
switch ( V_117 -> type ) {
case V_142 :
case V_143 :
case V_144 :
break;
default:
F_61 () ;
}
V_123 = ( T_23 * ) F_92 ( sizeof ( T_23 ) ) ;
V_123 -> V_125 = V_96 ;
V_123 -> V_126 = V_123 -> V_125 ;
if ( V_117 -> V_145 == TRUE ) {
T_25 = F_113 ( V_118 , - 1 ) ;
} else {
T_25 = F_114 ( V_118 ) ;
}
F_93 ( V_117 -> V_14 , ( T_3 ) T_25 ,
( T_3 ) V_123 ) ;
if ( V_117 -> V_127 )
F_94 ( V_35 , V_96 ) ;
}
void
F_116 ( const char * V_35 , const T_26 * V_118 ,
T_17 V_96 V_8 )
{
T_22 V_117 = F_87 ( V_35 ) ;
T_23 * V_123 ;
F_14 ( V_117 ) ;
V_123 = F_112 ( V_117 , V_118 ) ;
if ( V_123 != NULL ) {
F_97 ( V_117 -> V_14 , V_118 ) ;
}
}
void
F_117 ( const char * V_35 , const T_26 * V_118 ,
T_17 V_96 )
{
T_22 V_117 = F_87 ( V_35 ) ;
T_23 * V_123 ;
F_14 ( V_117 ) ;
V_123 = F_112 ( V_117 , V_118 ) ;
if ( V_123 != NULL ) {
V_123 -> V_125 = V_96 ;
return;
}
if ( V_96 == NULL )
return;
V_123 = ( T_23 * ) F_92 ( sizeof ( T_23 ) ) ;
V_123 -> V_126 = NULL ;
V_123 -> V_125 = V_96 ;
F_93 ( V_117 -> V_14 , ( T_3 ) F_114 ( V_118 ) ,
( T_3 ) V_123 ) ;
}
void
F_118 ( const char * V_35 , const T_26 * V_118 )
{
T_22 V_117 = F_87 ( V_35 ) ;
T_23 * V_123 ;
F_14 ( V_117 ) ;
V_123 = F_112 ( V_117 , V_118 ) ;
if ( V_123 == NULL )
return;
if ( V_123 -> V_126 != NULL ) {
V_123 -> V_125 = V_123 -> V_126 ;
} else {
F_97 ( V_117 -> V_14 , V_118 ) ;
}
}
int
F_119 ( T_22 V_117 , const T_26 * string ,
T_6 * V_28 , T_10 * V_34 , T_18 * V_92 , void * V_1 )
{
T_23 * V_123 ;
struct V_138 * V_96 ;
int V_98 ;
const T_26 * V_146 ;
if ( ! string ) return 0 ;
V_123 = F_112 ( V_117 , string ) ;
if ( V_123 != NULL ) {
V_96 = V_123 -> V_125 ;
if ( V_96 == NULL ) {
return 0 ;
}
V_146 = V_34 -> V_147 ;
V_34 -> V_147 = string ;
V_98 = F_75 ( V_96 , V_28 , V_34 , V_92 , TRUE , V_1 ) ;
V_34 -> V_147 = V_146 ;
return V_98 ;
}
return 0 ;
}
T_17
F_120 ( T_22 V_117 ,
const T_26 * string )
{
T_23 * V_123 ;
if ( ! string ) return NULL ;
V_123 = F_112 ( V_117 , string ) ;
if ( V_123 != NULL )
return V_123 -> V_125 ;
else
return NULL ;
}
T_17
F_121 ( const char * V_35 , const T_26 * string )
{
T_22 V_117 ;
if ( ! string ) return NULL ;
V_117 = F_87 ( V_35 ) ;
if ( V_117 != NULL ) {
T_23 * V_123 = F_112 ( V_117 , string ) ;
if ( V_123 != NULL )
return V_123 -> V_126 ;
}
return NULL ;
}
void F_122 ( const char * V_35 , void * V_118 , T_17 V_96 )
{
T_22 V_117 = F_87 ( V_35 ) ;
T_23 * V_123 ;
if ( V_117 == NULL ) {
fprintf ( V_124 , L_19 ,
V_35 ) ;
fprintf ( V_124 , L_20 ,
F_91 ( V_96 -> V_99 ) ) ;
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
F_14 ( V_117 -> type == V_148 ) ;
V_123 = ( T_23 * ) F_92 ( sizeof ( T_23 ) ) ;
V_123 -> V_125 = V_96 ;
V_123 -> V_126 = V_123 -> V_125 ;
F_93 ( V_117 -> V_14 , ( T_3 ) V_118 ,
( T_3 ) V_123 ) ;
if ( V_117 -> V_127 )
F_94 ( V_35 , V_96 ) ;
}
T_17 F_123 ( T_22 V_117 , void * T_25 )
{
T_23 * V_123 = ( T_23 * ) F_88 ( V_117 -> V_14 , T_25 ) ;
if ( V_123 != NULL )
return V_123 -> V_125 ;
return NULL ;
}
void F_124 ( const char * V_35 , T_27 * V_149 , T_17 V_96 )
{
T_22 V_117 ;
T_23 * V_123 ;
V_117 = F_87 ( V_35 ) ;
if ( V_96 == NULL ) {
fprintf ( V_124 , L_17 ,
V_35 ) ;
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
if ( V_117 == NULL ) {
fprintf ( V_124 , L_19 ,
V_35 ) ;
fprintf ( V_124 , L_20 ,
F_91 ( V_96 -> V_99 ) ) ;
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
if ( V_117 -> type != V_150 ) {
F_61 () ;
}
V_123 = ( T_23 * ) F_92 ( sizeof ( T_23 ) ) ;
V_123 -> V_125 = V_96 ;
V_123 -> V_126 = V_123 -> V_125 ;
F_93 ( V_117 -> V_14 ,
V_149 , ( T_3 ) V_123 ) ;
if ( V_117 -> V_127 )
F_94 ( V_35 , V_96 ) ;
}
int F_125 ( T_22 V_117 ,
T_27 * V_149 , T_6 * V_28 , T_10 * V_34 , T_18 * V_92 , const T_19 V_102 , void * V_1 )
{
T_23 * V_123 ;
struct V_138 * V_96 ;
int V_98 ;
V_123 = ( T_23 * ) F_88 ( V_117 -> V_14 , V_149 ) ;
if ( V_123 != NULL ) {
V_96 = V_123 -> V_125 ;
if ( V_96 == NULL ) {
return 0 ;
}
V_98 = F_75 ( V_96 , V_28 , V_34 , V_92 , V_102 , V_1 ) ;
return V_98 ;
}
return 0 ;
}
int F_126 ( T_22 V_117 ,
T_27 * V_149 , T_6 * V_28 , T_10 * V_34 , T_18 * V_92 )
{
return F_125 ( V_117 , V_149 , V_28 , V_34 , V_92 , TRUE , NULL ) ;
}
T_17 F_127 (
T_22 const V_117 , T_27 * V_149 )
{
T_23 * V_123 ;
V_123 = ( T_23 * ) F_88 ( V_117 -> V_14 , V_149 ) ;
if ( V_123 != NULL )
return V_123 -> V_125 ;
else
return NULL ;
}
T_17
F_128 ( T_23 * V_123 )
{
return V_123 -> V_125 ;
}
static T_28
F_129 ( T_29 V_151 , T_29 V_152 )
{
const struct V_138 * V_153 = ( const struct V_138 * ) V_151 ;
const struct V_138 * V_154 = ( const struct V_138 * ) V_152 ;
const char * V_155 , * V_156 ;
T_28 V_141 ;
if ( V_153 -> V_99 == NULL )
V_155 = L_6 ;
else
V_155 = F_130 ( F_80 ( V_153 -> V_99 ) ) ;
if ( V_154 -> V_99 == NULL )
V_156 = L_6 ;
else
V_156 = F_130 ( F_80 ( V_154 -> V_99 ) ) ;
V_141 = strcmp ( V_155 , V_156 ) ;
return V_141 ;
}
void
F_94 ( const char * V_35 , T_17 V_96 )
{
T_22 V_117 = F_87 ( V_35 ) ;
T_2 * V_157 ;
T_17 V_158 ;
if ( V_117 == NULL ) {
fprintf ( V_124 , L_19 ,
V_35 ) ;
fprintf ( V_124 , L_20 ,
F_91 ( V_96 -> V_99 ) ) ;
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
if ( ! V_117 -> V_127 ) {
const char * V_159 ;
V_159 = F_131 ( V_96 ) ;
if ( V_159 == NULL )
V_159 = L_21 ;
fprintf ( V_124 , L_22 ,
V_159 ,
F_74 ( V_96 -> V_99 ) ,
V_35 ) ;
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
if ( V_117 -> V_99 != NULL )
F_132 ( F_74 ( V_117 -> V_99 ) , F_74 ( V_96 -> V_99 ) ) ;
V_157 = F_133 ( V_117 -> V_15 , ( T_3 ) V_96 ) ;
if ( V_157 != NULL ) {
return;
}
if ( V_117 -> type != V_142 )
{
for ( V_157 = V_117 -> V_15 ; V_157 != NULL ; V_157 = F_134 ( V_157 ) )
{
V_158 = ( T_17 ) V_157 -> V_1 ;
if ( V_158 -> V_99 == V_96 -> V_99 )
{
const char * V_159 , * V_160 ;
V_159 = F_131 ( V_96 ) ;
if ( V_159 == NULL )
V_159 = L_21 ;
V_160 = F_131 ( V_158 ) ;
if ( V_160 == NULL )
V_160 = L_21 ;
fprintf ( V_124 , L_23 ,
V_159 , V_160 ,
F_74 ( V_96 -> V_99 ) ,
V_35 ) ;
if ( getenv ( L_18 ) != NULL )
abort () ;
}
}
}
V_117 -> V_15 =
F_135 ( V_117 -> V_15 , ( T_3 ) V_96 , ( V_161 ) F_129 ) ;
}
T_17
F_136 ( T_23 * V_123 )
{
return V_123 -> V_126 ;
}
T_2 *
F_137 ( T_22 V_12 ) {
if ( ! V_12 ) return NULL ;
return V_12 -> V_15 ;
}
T_30
F_138 ( T_22 V_12 ) {
if ( ! V_12 ) return V_162 ;
return V_12 -> type ;
}
void
F_139 ( T_22 V_12 )
{
V_12 -> V_127 = TRUE ;
}
static T_28
F_140 ( T_29 V_163 , T_29 V_164 )
{
const T_27 * V_165 = ( const T_27 * ) V_163 ;
const T_27 * V_166 = ( const T_27 * ) V_164 ;
return ( ( memcmp ( & V_165 -> V_167 , & V_166 -> V_167 , sizeof ( V_168 ) ) == 0 )
&& ( V_165 -> V_169 == V_166 -> V_169 ) ) ;
}
static T_7
F_141 ( T_29 V_170 )
{
const T_27 * T_25 = ( const T_27 * ) V_170 ;
return T_25 -> V_167 . V_171 ;
}
static void
F_142 ( T_3 T_25 , T_3 V_136 , T_3 T_4 )
{
T_31 * V_172 ;
T_23 * V_123 ;
F_14 ( V_136 ) ;
F_14 ( T_4 ) ;
V_123 = ( T_23 * ) V_136 ;
if ( V_123 -> V_125 == NULL ||
V_123 -> V_125 -> V_99 == NULL ) {
return;
}
V_172 = ( T_31 * ) T_4 ;
V_172 -> V_173 ( V_172 -> V_174 , V_172 -> V_175 , T_25 , V_136 ,
V_172 -> V_176 ) ;
}
static void
F_143 ( T_3 T_25 , T_3 V_136 , T_3 T_4 )
{
T_22 V_117 ;
T_31 * V_172 ;
F_14 ( V_136 ) ;
F_14 ( T_4 ) ;
V_117 = ( T_22 ) V_136 ;
V_172 = ( T_31 * ) T_4 ;
V_172 -> V_174 = ( T_26 * ) T_25 ;
V_172 -> V_175 = F_144 ( V_172 -> V_174 ) ;
F_105 ( V_117 -> V_14 , V_172 -> V_177 , V_172 ) ;
}
static void
F_145 ( T_32 F_21 ,
T_3 T_4 )
{
T_31 V_172 ;
V_172 . V_176 = T_4 ;
V_172 . V_173 = F_21 ;
V_172 . V_177 = F_142 ;
F_105 ( V_16 , F_143 , & V_172 ) ;
}
void
F_146 ( const char * V_174 ,
T_32 F_21 ,
T_3 T_4 )
{
T_31 V_172 ;
T_22 V_117 = F_87 ( V_174 ) ;
V_172 . V_174 = V_174 ;
V_172 . V_175 = V_117 -> type ;
V_172 . V_173 = F_21 ;
V_172 . V_176 = T_4 ;
F_105 ( V_117 -> V_14 , F_142 , & V_172 ) ;
}
void
F_147 ( const char * V_174 ,
T_33 F_21 ,
T_3 T_4 )
{
T_22 V_117 = F_87 ( V_174 ) ;
T_2 * V_178 ;
for ( V_178 = V_117 -> V_15 ; V_178 != NULL ;
V_178 = F_134 ( V_178 ) )
F_21 ( V_174 , V_178 -> V_1 , T_4 ) ;
}
static void
F_148 ( T_3 T_25 , T_3 V_136 , T_3 T_4 )
{
T_23 * V_123 ;
T_31 * V_172 ;
F_14 ( V_136 ) ;
F_14 ( T_4 ) ;
V_123 = ( T_23 * ) V_136 ;
if ( V_123 -> V_126 == V_123 -> V_125 ) {
return;
}
V_172 = ( T_31 * ) T_4 ;
V_172 -> V_173 ( V_172 -> V_174 , V_172 -> V_175 , T_25 , V_136 ,
V_172 -> V_176 ) ;
}
void
F_149 ( T_32 F_21 ,
T_3 T_4 )
{
T_31 V_172 ;
V_172 . V_176 = T_4 ;
V_172 . V_173 = F_21 ;
V_172 . V_177 = F_148 ;
F_105 ( V_16 , F_143 , & V_172 ) ;
}
void
F_150 ( const char * V_174 ,
T_32 F_21 ,
T_3 T_4 )
{
T_31 V_172 ;
T_22 V_117 = F_87 ( V_174 ) ;
V_172 . V_174 = V_174 ;
V_172 . V_175 = V_117 -> type ;
V_172 . V_173 = F_21 ;
V_172 . V_176 = T_4 ;
F_105 ( V_117 -> V_14 ,
F_148 , & V_172 ) ;
}
static void
F_151 ( T_3 T_25 , T_3 V_136 , T_3 T_4 )
{
T_22 V_13 ;
T_34 * V_172 ;
V_13 = ( T_22 ) V_136 ;
V_172 = ( T_34 * ) T_4 ;
(* V_172 -> V_173 )( ( T_26 * ) T_25 , V_13 -> V_179 , V_172 -> V_176 ) ;
}
static void
F_152 ( T_3 T_25 , T_3 T_4 )
{
T_22 V_13 ;
T_34 * V_172 ;
V_13 = ( T_22 ) F_88 ( V_16 , T_25 ) ;
V_172 = ( T_34 * ) T_4 ;
(* V_172 -> V_173 )( ( T_26 * ) T_25 , V_13 -> V_179 , V_172 -> V_176 ) ;
}
void
F_153 ( T_35 F_21 ,
T_3 T_4 ,
V_161 V_180 )
{
T_34 V_172 ;
T_36 * V_3 ;
V_172 . V_176 = T_4 ;
V_172 . V_173 = F_21 ;
if ( V_180 != NULL )
{
V_3 = F_154 ( V_16 ) ;
V_3 = F_155 ( V_3 , V_180 ) ;
F_156 ( V_3 , F_152 , & V_172 ) ;
F_157 ( V_3 ) ;
}
else
{
F_105 ( V_16 , F_151 , & V_172 ) ;
}
}
T_22
F_158 ( const char * V_35 , const char * V_179 , const int V_181 , const T_30 type ,
const int V_145 )
{
T_22 V_117 ;
if( F_88 ( V_16 , V_35 ) ) {
F_159 ( L_24 , V_35 , V_179 ) ;
}
V_117 = F_160 ( struct V_12 ) ;
switch ( type ) {
case V_119 :
case V_120 :
case V_121 :
case V_122 :
V_117 -> V_182 = V_183 ;
V_117 -> V_14 = F_10 ( V_183 ,
V_184 ,
NULL ,
& V_6 ) ;
break;
case V_142 :
case V_143 :
case V_144 :
V_117 -> V_182 = V_17 ;
V_117 -> V_14 = F_10 ( V_17 ,
V_18 ,
& V_6 ,
& V_6 ) ;
break;
case V_150 :
V_117 -> V_14 = F_10 ( F_141 ,
F_140 ,
NULL ,
& V_6 ) ;
break;
default:
F_159 ( L_25 , V_35 , V_179 ) ;
F_61 () ;
}
V_117 -> V_15 = NULL ;
V_117 -> V_179 = V_179 ;
V_117 -> type = type ;
V_117 -> V_145 = V_145 ;
V_117 -> V_99 = F_161 ( V_181 ) ;
V_117 -> V_127 = FALSE ;
F_93 ( V_16 , ( T_3 ) V_35 , ( T_3 ) V_117 ) ;
return V_117 ;
}
T_22 F_162 ( const char * V_35 ,
const char * V_179 , const int V_181 , T_37 V_182 , T_38 V_185 )
{
T_22 V_117 ;
if( F_88 ( V_16 , V_35 ) ) {
F_159 ( L_24 , V_35 , V_179 ) ;
}
V_117 = F_160 ( struct V_12 ) ;
V_117 -> V_182 = V_182 ;
V_117 -> V_14 = F_10 ( V_182 ,
V_185 ,
& V_6 ,
& V_6 ) ;
V_117 -> V_15 = NULL ;
V_117 -> V_179 = V_179 ;
V_117 -> type = V_148 ;
V_117 -> V_145 = V_186 ;
V_117 -> V_99 = F_161 ( V_181 ) ;
V_117 -> V_127 = FALSE ;
F_93 ( V_16 , ( T_3 ) V_35 , ( T_3 ) V_117 ) ;
return V_117 ;
}
void
F_163 ( const char * V_35 )
{
T_22 V_117 = F_87 ( V_35 ) ;
if ( ! V_117 ) return;
F_97 ( V_16 , V_35 ) ;
}
const char *
F_164 ( const char * V_35 )
{
T_22 V_117 = F_87 ( V_35 ) ;
if ( ! V_117 ) return NULL ;
return V_117 -> V_179 ;
}
T_30
F_144 ( const char * V_35 )
{
T_22 V_117 = F_87 ( V_35 ) ;
if ( ! V_117 ) return V_162 ;
return V_117 -> type ;
}
int
F_165 ( const char * V_35 )
{
T_22 V_117 = F_87 ( V_35 ) ;
if ( ! V_117 ) return 0 ;
return V_117 -> V_145 ;
}
T_5
F_166 ( const char * V_35 )
{
return ( T_5 ) F_88 ( V_21 , V_35 ) ;
}
T_19
F_167 ( const T_26 * V_35 ) {
return ( F_166 ( V_35 ) != NULL ) ;
}
V_9 * F_168 ( const char * V_187 )
{
return ( V_9 * ) F_88 ( V_22 , V_187 ) ;
}
void
F_169 ( const char * V_35 , T_39 V_100 , const char * V_188 , const char * V_187 , const int V_181 , T_40 V_189 )
{
T_5 V_117 = F_166 ( V_35 ) ;
const char * V_190 ;
V_9 * V_191 ;
T_7 V_130 , V_192 ;
T_2 * V_193 ;
if ( V_117 == NULL ) {
fprintf ( V_124 , L_19 ,
V_35 ) ;
V_190 = F_170 ( V_181 ) ;
if ( V_190 != NULL ) {
fprintf ( V_124 , L_20 ,
V_190 ) ;
}
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
V_192 = F_171 ( V_117 -> V_4 ) ;
for ( V_130 = 0 ; V_130 < V_192 ; V_130 ++ )
{
V_193 = F_172 ( V_117 -> V_4 , V_130 ) ;
V_191 = ( V_9 * ) V_193 -> V_1 ;
if ( ( V_191 -> V_100 == V_100 ) &&
( V_191 -> V_99 == F_161 ( V_181 ) ) )
{
V_190 = F_170 ( V_181 ) ;
if ( V_190 != NULL ) {
fprintf ( V_124 , L_26 ,
V_190 , V_35 ) ;
}
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
}
if ( F_88 ( V_22 , V_187 ) != NULL ) {
F_159 ( L_27
L_28 , V_187 ) ;
}
V_191 = F_160 ( V_9 ) ;
V_191 -> V_100 = V_100 ;
V_191 -> V_99 = F_161 ( V_181 ) ;
V_191 -> V_188 = V_188 ;
V_191 -> V_187 = V_187 ;
V_191 -> V_10 = F_114 ( V_35 ) ;
V_191 -> V_194 = ( V_189 == V_195 ) ;
F_93 ( V_22 , ( T_3 ) V_187 , V_191 ) ;
V_117 -> V_4 = F_22 ( V_117 -> V_4 ,
( T_3 ) V_191 ) ;
F_173 ( V_191 -> V_99 , V_187 ) ;
if ( V_117 -> V_99 != NULL )
F_132 ( F_74 ( V_117 -> V_99 ) , F_74 ( V_191 -> V_99 ) ) ;
}
static int
F_174 ( T_29 V_153 , T_29 V_154 ) {
const V_9 * V_196 = ( const V_9 * ) V_153 ;
const V_9 * V_197 = ( const V_9 * ) V_154 ;
return ( V_196 -> V_100 == V_197 -> V_100 ) &&
( V_196 -> V_99 == V_197 -> V_99 ) ? 0 : 1 ;
}
void
F_175 ( const char * V_35 , T_39 V_100 , const int V_181 ) {
T_5 V_117 = F_166 ( V_35 ) ;
V_9 V_191 ;
T_2 * V_198 ;
F_14 ( V_117 != NULL ) ;
V_191 . V_100 = V_100 ;
V_191 . V_99 = F_161 ( V_181 ) ;
V_198 = F_176 ( V_117 -> V_4 ,
( T_3 ) & V_191 , F_174 ) ;
if ( V_198 ) {
V_9 * V_199 = ( V_9 * ) ( V_198 -> V_1 ) ;
V_6 ( V_199 -> V_10 ) ;
F_97 ( V_22 , V_199 -> V_187 ) ;
F_4 ( V_9 , V_198 -> V_1 ) ;
V_117 -> V_4 = F_48 ( V_117 -> V_4 ,
V_198 ) ;
}
}
T_19
F_177 ( T_5 V_117 , T_6 * V_28 ,
T_10 * V_34 , T_18 * V_92 , V_9 * * V_200 , void * V_1 )
{
T_19 V_201 ;
const char * V_202 ;
const char * V_203 ;
T_2 * V_157 ;
T_20 V_103 ;
T_7 V_104 = 0 ;
V_9 * V_191 ;
int V_204 ;
V_103 = V_34 -> V_105 ;
V_34 -> V_103 = V_103 ;
V_34 -> V_105 = V_103 - ( V_103 > 0 ) ;
V_201 = FALSE ;
V_202 = V_34 -> V_62 ;
V_203 = V_34 -> V_205 ;
V_104 = F_77 ( V_34 -> V_84 ) ;
* V_200 = NULL ;
for ( V_157 = V_117 -> V_4 ; V_157 != NULL ;
V_157 = F_134 ( V_157 ) ) {
V_34 -> V_105 = V_103 - ( V_103 > 0 ) ;
V_191 = ( V_9 * ) V_157 -> V_1 ;
if ( V_191 -> V_99 != NULL &&
( ! F_76 ( V_191 -> V_99 ) || ( V_191 -> V_194 == FALSE ) ) ) {
continue;
}
if ( V_191 -> V_99 != NULL ) {
V_204 = F_80 ( V_191 -> V_99 ) ;
V_34 -> V_62 =
F_74 ( V_191 -> V_99 ) ;
F_78 ( V_34 -> V_84 , F_79 ( V_204 ) ) ;
}
V_34 -> V_205 = V_191 -> V_10 ;
if ( ( V_191 -> V_100 ) ( V_28 , V_34 , V_92 , V_1 ) ) {
* V_200 = V_191 ;
V_201 = TRUE ;
break;
} else {
while ( F_77 ( V_34 -> V_84 ) > V_104 ) {
F_82 ( V_34 -> V_84 , F_83 ( V_34 -> V_84 ) ) ;
}
}
}
V_34 -> V_62 = V_202 ;
V_34 -> V_205 = V_203 ;
V_34 -> V_105 = V_103 ;
return V_201 ;
}
static void
F_178 ( T_3 V_1 , T_3 T_4 )
{
T_41 * V_172 ;
F_14 ( V_1 ) ;
F_14 ( T_4 ) ;
V_172 = ( T_41 * ) T_4 ;
V_172 -> V_173 ( V_172 -> V_174 , ( V_9 * ) V_1 ,
V_172 -> V_176 ) ;
}
void
F_179 ( const char * V_174 ,
T_42 F_21 ,
T_3 T_4 )
{
T_41 V_172 ;
T_5 V_117 = F_166 ( V_174 ) ;
V_172 . V_174 = V_174 ;
V_172 . V_173 = F_21 ;
V_172 . V_176 = T_4 ;
F_2 ( V_117 -> V_4 ,
F_178 , & V_172 ) ;
}
static void
F_180 ( T_3 T_25 , T_3 V_136 , T_3 T_4 )
{
T_43 * V_172 ;
V_172 = ( T_43 * ) T_4 ;
(* V_172 -> V_173 )( ( T_26 * ) T_25 , (struct V_11 * ) V_136 , V_172 -> V_176 ) ;
}
static void
F_181 ( T_3 T_25 , T_3 T_4 )
{
struct V_11 * V_3 ;
T_43 * V_172 ;
V_3 = (struct V_11 * ) F_88 ( V_21 , T_25 ) ;
V_172 = ( T_43 * ) T_4 ;
(* V_172 -> V_173 )( ( T_26 * ) T_25 , V_3 , V_172 -> V_176 ) ;
}
void
F_182 ( T_44 F_21 ,
T_3 T_4 ,
V_161 V_180 )
{
T_43 V_172 ;
T_36 * V_3 ;
V_172 . V_176 = T_4 ;
V_172 . V_173 = F_21 ;
if ( V_180 != NULL )
{
V_3 = F_154 ( V_16 ) ;
V_3 = F_155 ( V_3 , V_180 ) ;
F_156 ( V_3 , F_181 , & V_172 ) ;
F_157 ( V_3 ) ;
}
else
{
F_105 ( V_21 , F_180 , & V_172 ) ;
}
}
static void
F_183 ( const char * V_174 ,
V_9 * V_191 , T_3 T_4 V_8 )
{
if ( V_191 -> V_99 != NULL ) {
printf ( L_29 ,
V_174 ,
F_130 ( F_80 ( V_191 -> V_99 ) ) ,
( F_76 ( V_191 -> V_99 ) && V_191 -> V_194 ) ? 'T' : 'F' ) ;
}
}
static void
F_184 ( const T_26 * V_174 , struct V_11 * T_45 V_8 , T_3 T_4 V_8 )
{
F_179 ( V_174 , F_183 , NULL ) ;
}
void
F_185 ( void )
{
F_182 ( F_184 , NULL , NULL ) ;
}
T_5
F_186 ( const char * V_35 , const int V_181 )
{
T_5 V_117 ;
if ( F_88 ( V_21 , V_35 ) != NULL ) {
F_159 ( L_30 , V_35 ) ;
}
V_117 = F_160 ( struct V_11 ) ;
V_117 -> V_99 = F_161 ( V_181 ) ;
V_117 -> V_4 = NULL ;
F_93 ( V_21 , ( T_3 ) V_35 ,
( T_3 ) V_117 ) ;
return V_117 ;
}
const char *
F_187 ( const T_17 V_96 )
{
if ( V_96 == NULL || V_96 -> V_99 == NULL ) {
return NULL ;
}
return F_91 ( V_96 -> V_99 ) ;
}
const char *
F_188 ( const T_17 V_96 )
{
if ( V_96 -> V_99 == NULL ) {
return NULL ;
}
return F_74 ( V_96 -> V_99 ) ;
}
int
F_189 ( const T_17 V_96 )
{
if ( V_96 -> V_99 == NULL ) {
return - 1 ;
}
return F_80 ( V_96 -> V_99 ) ;
}
T_36 *
F_190 ( void )
{
return F_154 ( V_19 ) ;
}
T_17
F_13 ( const char * V_35 )
{
return ( T_17 ) F_88 ( V_19 , V_35 ) ;
}
T_17 F_191 ( const char * V_35 , const int V_206 )
{
T_17 V_96 = ( T_17 ) F_88 ( V_19 , V_35 ) ;
if ( ( V_96 != NULL ) && ( V_206 > 0 ) )
{
F_132 ( F_74 ( F_161 ( V_206 ) ) , F_188 ( V_96 ) ) ;
}
return V_96 ;
}
const char *
F_131 ( const T_17 V_96 )
{
if ( V_96 == NULL ) {
return NULL ;
}
return V_96 -> V_35 ;
}
T_17
F_192 ( T_46 V_100 , const int V_181 )
{
struct V_138 * V_96 ;
V_96 = F_43 ( F_193 () , struct V_138 ) ;
V_96 -> V_35 = NULL ;
V_96 -> V_100 = V_100 ;
V_96 -> V_99 = F_161 ( V_181 ) ;
return V_96 ;
}
T_17 F_194 ( T_46 V_100 ,
const int V_181 , const char * V_35 )
{
struct V_138 * V_96 ;
V_96 = F_43 ( F_193 () , struct V_138 ) ;
V_96 -> V_35 = V_35 ;
V_96 -> V_100 = V_100 ;
V_96 -> V_99 = F_161 ( V_181 ) ;
return V_96 ;
}
static void
F_195 ( T_17 V_96 )
{
if ( V_96 == NULL ) return;
F_104 ( V_96 ) ;
F_196 ( V_96 ) ;
F_197 ( F_193 () , V_96 ) ;
}
T_17
F_198 ( const char * V_35 , T_46 V_100 , const int V_181 )
{
struct V_138 * V_96 ;
F_14 ( F_88 ( V_19 , V_35 ) == NULL ) ;
V_96 = F_43 ( F_193 () , struct V_138 ) ;
V_96 -> V_35 = V_35 ;
V_96 -> V_100 = V_100 ;
V_96 -> V_99 = F_161 ( V_181 ) ;
F_93 ( V_19 , ( T_3 ) V_35 ,
( T_3 ) V_96 ) ;
return V_96 ;
}
static T_19
F_199 ( T_1 V_117 , const char * V_207 )
{
T_2 * V_198 ;
V_198 = F_176 ( V_117 -> V_4 ,
V_207 , ( V_161 ) strcmp ) ;
if ( V_198 ) {
V_6 ( V_198 -> V_1 ) ;
V_117 -> V_4 = F_48 ( V_117 -> V_4 , V_198 ) ;
return TRUE ;
}
return FALSE ;
}
static void
F_200 ( T_3 T_25 V_8 , T_3 V_136 , T_3 T_4 )
{
T_1 V_117 = ( T_1 ) V_136 ;
const char * V_207 = ( const char * ) T_4 ;
F_199 ( V_117 , V_207 ) ;
}
void
F_201 ( const char * V_35 )
{
T_17 V_96 = F_13 ( V_35 ) ;
if ( V_96 == NULL ) return;
F_97 ( V_19 , V_35 ) ;
F_97 ( V_20 , V_35 ) ;
F_105 ( V_20 , F_200 , ( T_3 ) V_35 ) ;
F_97 ( V_21 , V_35 ) ;
F_195 ( V_96 ) ;
}
int
F_202 ( T_17 V_96 , T_6 * V_28 ,
T_10 * V_34 , T_18 * V_92 , void * V_1 )
{
int V_141 ;
F_14 ( V_96 != NULL ) ;
V_141 = F_75 ( V_96 , V_28 , V_34 , V_92 , TRUE , V_1 ) ;
return V_141 ;
}
int
F_68 ( T_17 V_96 , T_6 * V_28 ,
T_10 * V_34 , T_18 * V_92 , void * V_1 )
{
int V_141 ;
V_141 = F_202 ( V_96 , V_28 , V_34 , V_92 , V_1 ) ;
if ( V_141 == 0 ) {
F_14 ( V_26 -> V_99 != NULL ) ;
F_75 ( V_26 , V_28 , V_34 , V_92 , TRUE , NULL ) ;
return F_50 ( V_28 ) ;
}
return V_141 ;
}
int
F_203 ( T_17 V_96 , T_6 * V_28 ,
T_10 * V_34 , T_18 * V_92 )
{
return F_68 ( V_96 , V_28 , V_34 , V_92 , NULL ) ;
}
int
F_204 ( T_6 * V_28 , T_10 * V_34 , T_18 * V_92 )
{
return F_75 ( V_26 , V_28 , V_34 , V_92 , TRUE , NULL ) ;
}
void F_205 ( V_9 * V_200 , T_6 * V_28 ,
T_10 * V_34 , T_18 * V_92 , void * V_1 )
{
const char * V_202 ;
const char * V_203 ;
T_20 V_103 ;
F_14 ( V_200 ) ;
V_103 = V_34 -> V_105 ;
V_34 -> V_103 = V_103 ;
V_34 -> V_105 = V_103 - ( V_103 > 0 ) ;
V_202 = V_34 -> V_62 ;
V_203 = V_34 -> V_205 ;
if ( ! V_200 -> V_194 ||
( V_200 -> V_99 != NULL && ! F_76 ( V_200 -> V_99 ) ) ) {
F_14 ( V_26 -> V_99 != NULL ) ;
F_75 ( V_26 , V_28 , V_34 , V_92 , TRUE , NULL ) ;
return;
}
if ( V_200 -> V_99 != NULL ) {
V_34 -> V_62 = F_74 ( V_200 -> V_99 ) ;
F_78 ( V_34 -> V_84 , F_79 ( F_80 ( V_200 -> V_99 ) ) ) ;
}
V_34 -> V_205 = V_200 -> V_10 ;
if( ! (* V_200 -> V_100 )( V_28 , V_34 , V_92 , V_1 ) )
F_75 ( V_26 , V_28 , V_34 , V_92 , TRUE , NULL ) ;
V_34 -> V_105 = V_103 ;
V_34 -> V_62 = V_202 ;
V_34 -> V_205 = V_203 ;
}
T_19 F_132 ( const char * V_208 , const char * V_207 )
{
T_7 V_130 , V_192 ;
T_2 * V_193 ;
const char * V_209 ;
T_1 V_117 ;
if ( ( V_208 == NULL ) || ( V_207 == NULL ) )
{
return FALSE ;
}
V_117 = F_206 ( V_208 ) ;
if ( V_117 == NULL ) {
V_117 = F_160 ( struct V_7 ) ;
V_117 -> V_4 = NULL ;
F_93 ( V_20 , ( T_3 ) F_114 ( V_208 ) , ( T_3 ) V_117 ) ;
}
V_192 = F_171 ( V_117 -> V_4 ) ;
for ( V_130 = 0 ; V_130 < V_192 ; V_130 ++ )
{
V_193 = F_172 ( V_117 -> V_4 , V_130 ) ;
V_209 = ( const char * ) V_193 -> V_1 ;
if ( strcmp ( V_207 , V_209 ) == 0 )
return TRUE ;
}
V_117 -> V_4 = F_22 ( V_117 -> V_4 , ( T_3 ) F_114 ( V_207 ) ) ;
return TRUE ;
}
T_19 F_207 ( const char * V_208 , const char * V_207 )
{
T_1 V_117 = F_206 ( V_208 ) ;
F_14 ( V_117 != NULL ) ;
return F_199 ( V_117 , V_207 ) ;
}
T_1 F_206 ( const char * V_35 )
{
return ( T_1 ) F_88 ( V_20 , V_35 ) ;
}
static void
F_208 ( const T_26 * V_174 ,
T_30 V_175 V_8 , T_3 T_25 , T_3 V_136 ,
T_3 T_4 V_8 )
{
T_11 V_210 = F_209 ( T_25 ) ;
T_22 V_117 = F_87 ( V_174 ) ;
T_23 * V_123 ;
T_17 V_96 ;
T_28 V_204 ;
const T_26 * V_211 ;
F_14 ( V_117 ) ;
switch ( V_117 -> type ) {
case V_119 :
case V_120 :
case V_121 :
case V_122 :
V_123 = ( T_23 * ) V_136 ;
F_14 ( V_123 ) ;
V_96 = V_123 -> V_125 ;
F_14 ( V_96 ) ;
V_204 = F_189 ( V_96 ) ;
if ( V_204 != - 1 ) {
V_211 = F_130 ( V_204 ) ;
F_14 ( V_211 != NULL ) ;
printf ( L_31 , V_174 , V_210 , V_211 ) ;
}
break;
default:
break;
}
}
void
F_210 ( void )
{
F_145 ( F_208 , NULL ) ;
}
static void
F_211 ( T_3 T_25 , T_3 T_4 V_8 )
{
const char * V_174 = ( const char * ) T_25 ;
T_22 V_13 ;
V_13 = ( T_22 ) F_88 ( V_16 , T_25 ) ;
printf ( L_32 , V_174 , V_13 -> V_179 , F_212 ( V_13 -> type ) ) ;
switch ( V_13 -> type ) {
case V_119 :
case V_120 :
case V_121 :
case V_122 :
switch( V_13 -> V_145 ) {
case V_186 :
printf ( L_33 ) ;
break;
case V_212 :
printf ( L_34 ) ;
break;
case V_213 :
printf ( L_35 ) ;
break;
case V_214 :
printf ( L_36 ) ;
break;
case V_215 :
printf ( L_37 ) ;
break;
default:
printf ( L_38 , V_13 -> V_145 ) ;
break;
}
break;
default:
break;
}
printf ( L_39 ) ;
}
static T_28
F_213 ( T_29 V_151 , T_29 V_152 )
{
return strcmp ( ( const char * ) V_151 , ( const char * ) V_152 ) ;
}
void
F_214 ( void )
{
T_36 * V_3 ;
V_3 = F_154 ( V_16 ) ;
V_3 = F_155 ( V_3 , F_213 ) ;
F_156 ( V_3 , F_211 , NULL ) ;
F_157 ( V_3 ) ;
}
void
F_215 ( T_17 V_96 )
{
if ( ! V_216 )
V_216 = F_216 () ;
F_217 ( V_216 , V_96 ) ;
V_217 ++ ;
}
void
F_196 ( T_17 V_96 )
{
if ( ! V_216 ) return;
if ( F_218 ( V_216 , V_96 ) ) {
V_217 -- ;
}
}
T_19
F_219 ( void )
{
T_7 V_130 ;
T_17 V_96 ;
for( V_130 = 0 ; V_130 < V_217 ; V_130 ++ ) {
V_96 = ( T_17 ) F_220 ( V_216 , V_130 ) ;
if ( V_96 -> V_99 != NULL
&& F_76 ( V_96 -> V_99 ) ) {
return TRUE ;
}
}
return FALSE ;
}
void
F_221 ( T_6 * V_28 , T_10 * V_34 , T_18 * V_92 )
{
T_7 V_130 ;
for( V_130 = 0 ; V_130 < V_217 ; V_130 ++ ) {
F_202 ( ( T_17 ) F_220 ( V_216 , V_130 ) ,
V_28 , V_34 , V_92 , NULL ) ;
}
}
