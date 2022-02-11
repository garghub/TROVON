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
V_37 = F_43 ( struct V_36 ) ;
V_37 -> V_28 = V_28 ;
V_37 -> V_35 = F_44 ( V_35 ) ;
V_34 -> V_38 = F_45 ( V_34 -> V_38 , V_37 ) ;
}
void
F_46 ( T_10 * V_34 )
{
struct V_36 * V_37 ;
T_2 * V_39 ;
V_39 = F_47 ( V_34 -> V_38 ) ;
V_37 = (struct V_36 * ) V_39 -> V_1 ;
V_34 -> V_38 = F_48 ( V_34 -> V_38 , V_39 ) ;
V_6 ( V_37 -> V_35 ) ;
F_4 ( struct V_36 , V_37 ) ;
}
char *
F_49 ( const struct V_36 * V_37 )
{
T_7 V_40 = F_50 ( V_37 -> V_28 ) ;
return F_51 ( NULL , L_5 , V_37 -> V_35 , V_40 ,
F_52 ( V_40 , L_6 , L_7 ) ) ;
}
T_6 *
F_53 ( const struct V_36 * V_37 )
{
return V_37 -> V_28 ;
}
void
F_54 ( T_10 * V_34 )
{
if ( V_34 -> V_38 ) {
T_2 * V_41 ;
for ( V_41 = V_34 -> V_38 ; V_41 ; V_41 = V_41 -> V_42 ) {
struct V_36 * V_37 = (struct V_36 * ) V_41 -> V_1 ;
V_6 ( V_37 -> V_35 ) ;
F_4 ( struct V_36 , V_37 ) ;
}
F_3 ( V_34 -> V_38 ) ;
V_34 -> V_38 = NULL ;
}
}
void
F_55 ( T_10 * V_34 , T_11 V_43 )
{
if ( V_43 != V_34 -> V_44 ) {
V_34 -> V_45 = F_22 ( V_34 -> V_45 , F_56 ( V_43 ) ) ;
}
}
void
F_57 ( void (* F_21)( void ) )
{
V_46 = F_22 ( V_46 ,
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
F_2 ( V_46 ,
& F_58 , NULL ) ;
}
void
F_60 ( T_12 * V_47 , int V_48 ,
struct V_49 * V_50 , T_6 * V_28 , T_13 * V_51 , T_14 * V_52 )
{
const char * volatile V_53 ;
T_15 V_54 ;
switch ( V_50 -> V_55 ) {
case V_56 :
V_53 = L_8 ;
break;
case V_57 :
V_53 = L_9 ;
break;
case V_58 :
V_53 = L_10 ;
break;
default:
F_61 () ;
break;
}
if ( V_52 != NULL )
F_62 ( V_52 , V_47 -> V_59 ) ;
V_47 -> V_60 . V_61 = V_47 -> V_59 ;
V_47 -> V_60 . V_62 = L_11 ;
V_47 -> V_60 . V_52 = V_52 ;
V_47 -> V_60 . V_63 = 0 ;
V_47 -> V_60 . V_44 = V_51 -> V_44 ;
if ( V_51 -> V_64 . V_65 ) {
V_47 -> V_60 . V_63 |= V_66 ;
V_47 -> V_60 . V_67 = V_51 -> V_67 ;
}
V_47 -> V_60 . V_68 = V_50 -> V_68 ;
V_47 -> V_60 . V_51 = V_51 ;
V_47 -> V_60 . V_50 = V_50 ;
V_47 -> V_60 . V_69 = & V_50 -> V_69 ;
F_63 ( & V_47 -> V_60 . V_70 ) ;
F_63 ( & V_47 -> V_60 . V_71 ) ;
F_63 ( & V_47 -> V_60 . V_72 ) ;
F_63 ( & V_47 -> V_60 . V_73 ) ;
F_63 ( & V_47 -> V_60 . V_37 ) ;
F_63 ( & V_47 -> V_60 . V_74 ) ;
V_47 -> V_60 . V_75 = V_76 ;
V_47 -> V_60 . V_77 = L_6 ;
V_47 -> V_60 . V_78 = V_79 ;
V_47 -> V_60 . V_80 = V_81 ;
V_47 -> V_60 . V_82 = V_83 ;
V_47 -> V_60 . V_84 = F_64 ( V_47 -> V_60 . V_85 ) ;
V_47 -> V_28 = V_28 ;
F_65 ( V_47 -> V_59 , V_51 , V_51 -> V_86 , & V_47 -> V_60 . V_87 ) ;
if ( V_51 -> V_64 . V_88 )
V_54 . V_89 = F_66 ( V_47 -> V_59 , V_51 ) ;
else if ( V_51 -> V_64 . V_90 )
V_54 . V_89 = V_50 -> V_91 ;
else
V_54 . V_89 = NULL ;
V_54 . V_48 = V_48 ;
V_54 . V_92 = V_47 ;
F_67 {
F_42 ( & V_47 -> V_60 , V_47 -> V_28 , V_53 ) ;
F_68 ( V_24 , V_47 -> V_28 , & V_47 -> V_60 , V_47 -> V_93 , & V_54 ) ;
}
F_69 (BoundsError) {
F_61 () ;
}
F_70 (FragmentBoundsError, ReportedBoundsError) {
F_71 ( V_47 -> V_93 , V_27 , V_47 -> V_28 , 0 , 0 ,
L_12 ,
V_53 ) ;
}
V_94 ;
V_51 -> V_64 . V_95 = 1 ;
}
void
F_72 ( T_12 * V_47 , struct V_49 * V_50 ,
T_6 * V_28 , T_13 * V_51 , T_14 * V_52 )
{
T_16 V_96 ;
if ( V_52 != NULL )
F_62 ( V_52 , V_47 -> V_59 ) ;
V_47 -> V_60 . V_61 = V_47 -> V_59 ;
V_47 -> V_60 . V_62 = L_13 ;
V_47 -> V_60 . V_52 = V_52 ;
V_47 -> V_60 . V_51 = V_51 ;
V_47 -> V_60 . V_50 = V_50 ;
V_47 -> V_60 . V_69 = & V_50 -> V_69 ;
F_63 ( & V_47 -> V_60 . V_70 ) ;
F_63 ( & V_47 -> V_60 . V_71 ) ;
F_63 ( & V_47 -> V_60 . V_72 ) ;
F_63 ( & V_47 -> V_60 . V_73 ) ;
F_63 ( & V_47 -> V_60 . V_37 ) ;
F_63 ( & V_47 -> V_60 . V_74 ) ;
V_47 -> V_60 . V_75 = V_76 ;
V_47 -> V_60 . V_77 = L_6 ;
V_47 -> V_60 . V_78 = V_79 ;
V_47 -> V_60 . V_80 = V_81 ;
V_47 -> V_60 . V_82 = V_83 ;
V_47 -> V_60 . V_84 = F_64 ( V_47 -> V_60 . V_85 ) ;
V_47 -> V_28 = V_28 ;
F_65 ( V_47 -> V_59 , V_51 , V_51 -> V_86 , & V_47 -> V_60 . V_87 ) ;
F_67 {
if ( V_51 -> V_64 . V_88 )
V_96 . V_89 = F_66 ( V_47 -> V_59 , V_51 ) ;
else if ( V_51 -> V_64 . V_90 )
V_96 . V_89 = V_50 -> V_91 ;
else
V_96 . V_89 = NULL ;
V_96 . V_92 = V_47 ;
F_42 ( & V_47 -> V_60 , V_47 -> V_28 , L_14 ) ;
F_68 ( V_25 , V_47 -> V_28 , & V_47 -> V_60 , V_47 -> V_93 , & V_96 ) ;
}
F_69 (BoundsError) {
F_61 () ;
}
F_70 (FragmentBoundsError, ReportedBoundsError) {
F_71 ( V_47 -> V_93 , V_27 , V_47 -> V_28 , 0 , 0 ,
L_15 ) ;
}
V_94 ;
V_51 -> V_64 . V_95 = 1 ;
}
static int
F_73 ( T_17 V_97 , T_6 * V_28 ,
T_10 * V_34 , T_18 * V_93 , void * V_1 )
{
const char * V_98 ;
int V_99 ;
V_98 = V_34 -> V_62 ;
if ( V_97 -> V_100 != NULL ) {
V_34 -> V_62 =
F_74 ( V_97 -> V_100 ) ;
}
V_99 = (* V_97 -> V_101 )( V_28 , V_34 , V_93 , V_1 ) ;
V_34 -> V_62 = V_98 ;
return V_99 ;
}
static int
F_75 ( T_17 V_97 , T_6 * V_28 , T_10 * V_102 ,
T_18 * V_93 , T_19 V_103 , void * V_1 )
{
T_10 * V_34 = V_102 ;
const char * V_98 ;
T_20 V_104 ;
int V_99 ;
T_7 V_105 = 0 ;
if ( V_97 -> V_100 != NULL &&
! F_76 ( V_97 -> V_100 ) ) {
return 0 ;
}
V_98 = V_34 -> V_62 ;
V_104 = V_34 -> V_106 ;
V_105 = F_77 ( V_34 -> V_84 ) ;
V_34 -> V_104 = V_104 ;
V_34 -> V_106 = V_104 - ( V_104 > 0 ) ;
if ( V_97 -> V_100 != NULL ) {
V_34 -> V_62 =
F_74 ( V_97 -> V_100 ) ;
if ( V_103 ) {
V_34 -> V_107 ++ ;
F_78 ( V_34 -> V_84 , F_79 ( F_80 ( V_97 -> V_100 ) ) ) ;
}
}
if ( V_34 -> V_64 . V_108 ) {
V_99 = F_81 ( V_97 , V_28 , V_34 , V_93 , V_1 ) ;
} else {
V_99 = F_73 ( V_97 , V_28 , V_34 , V_93 , V_1 ) ;
}
if ( V_99 == 0 ) {
while ( F_77 ( V_34 -> V_84 ) > V_105 ) {
F_82 ( V_34 -> V_84 , F_83 ( V_34 -> V_84 ) ) ;
}
}
V_34 -> V_62 = V_98 ;
V_34 -> V_106 = V_104 ;
return V_99 ;
}
static int
F_81 ( T_17 V_97 , T_6 * V_28 ,
T_10 * V_102 , T_18 * V_93 , void * V_1 )
{
T_10 * V_34 = V_102 ;
const char * V_98 ;
T_20 V_104 ;
volatile int V_99 = 0 ;
T_19 V_109 ;
T_21 V_110 ;
T_21 V_111 ;
T_21 V_112 ;
T_21 V_113 ;
T_21 V_114 ;
T_21 V_115 ;
V_98 = V_34 -> V_62 ;
V_104 = V_34 -> V_106 ;
V_109 = F_84 ( V_34 -> V_52 ) ;
F_85 ( V_34 -> V_52 , FALSE ) ;
F_86 ( & V_110 , & V_34 -> V_70 ) ;
F_86 ( & V_111 , & V_34 -> V_71 ) ;
F_86 ( & V_112 , & V_34 -> V_72 ) ;
F_86 ( & V_113 , & V_34 -> V_73 ) ;
F_86 ( & V_114 , & V_34 -> V_37 ) ;
F_86 ( & V_115 , & V_34 -> V_74 ) ;
F_67 {
V_99 = F_73 ( V_97 , V_28 , V_34 , V_93 , V_1 ) ;
}
F_69 (BoundsError) {
F_85 ( V_34 -> V_52 , V_109 ) ;
F_86 ( & V_34 -> V_70 , & V_110 ) ;
F_86 ( & V_34 -> V_71 , & V_111 ) ;
F_86 ( & V_34 -> V_72 , & V_112 ) ;
F_86 ( & V_34 -> V_73 , & V_113 ) ;
F_86 ( & V_34 -> V_37 , & V_114 ) ;
F_86 ( & V_34 -> V_74 , & V_115 ) ;
V_34 -> V_62 = V_98 ;
V_34 -> V_106 = V_104 ;
V_116 ;
}
F_70 (FragmentBoundsError, ReportedBoundsError) {
V_99 = F_50 ( V_28 ) ;
}
V_94 ;
F_85 ( V_34 -> V_52 , V_109 ) ;
F_86 ( & V_34 -> V_70 , & V_110 ) ;
F_86 ( & V_34 -> V_71 , & V_111 ) ;
F_86 ( & V_34 -> V_72 , & V_112 ) ;
F_86 ( & V_34 -> V_73 , & V_113 ) ;
F_86 ( & V_34 -> V_37 , & V_114 ) ;
F_86 ( & V_34 -> V_74 , & V_115 ) ;
V_34 -> V_117 = 0 ;
return V_99 ;
}
T_22
F_87 ( const char * V_35 )
{
return ( T_22 ) F_88 ( V_16 , V_35 ) ;
}
static T_23 *
F_89 ( T_22 V_118 , const T_11 V_119 )
{
switch ( V_118 -> type ) {
case V_120 :
case V_121 :
case V_122 :
case V_123 :
break;
default:
F_61 () ;
}
return ( T_23 * ) F_88 ( V_118 -> V_14 ,
F_56 ( V_119 ) ) ;
}
void
F_90 ( const char * V_35 , const T_11 V_119 , T_17 V_97 )
{
T_22 V_118 ;
T_23 * V_124 ;
V_118 = F_87 ( V_35 ) ;
if ( V_118 == NULL ) {
fprintf ( V_125 , L_16 ,
V_35 ) ;
fprintf ( V_125 , L_17 ,
F_91 ( V_97 -> V_100 ) ) ;
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
F_14 ( V_97 != NULL ) ;
switch ( V_118 -> type ) {
case V_120 :
case V_121 :
case V_122 :
case V_123 :
break;
default:
F_61 () ;
}
#if 0
dissector_add_uint_sanity_check(name, pattern, handle, sub_dissectors);
#endif
V_124 = ( T_23 * ) F_92 ( sizeof ( T_23 ) ) ;
V_124 -> V_126 = V_97 ;
V_124 -> V_127 = V_124 -> V_126 ;
F_93 ( V_118 -> V_14 ,
F_56 ( V_119 ) , ( T_3 ) V_124 ) ;
F_94 ( V_35 , V_97 ) ;
}
void F_95 ( const char * V_128 , T_24 * V_129 ,
T_17 V_97 )
{
T_11 V_130 , V_131 ;
if ( V_129 ) {
for ( V_130 = 0 ; V_130 < V_129 -> V_132 ; V_130 ++ ) {
for ( V_131 = V_129 -> V_133 [ V_130 ] . V_134 ; V_131 < V_129 -> V_133 [ V_130 ] . V_135 ; V_131 ++ )
F_90 ( V_128 , V_131 , V_97 ) ;
F_90 ( V_128 , V_129 -> V_133 [ V_130 ] . V_135 , V_97 ) ;
}
}
}
void
F_96 ( const char * V_35 , const T_11 V_119 ,
T_17 V_97 V_8 )
{
T_22 V_118 = F_87 ( V_35 ) ;
T_23 * V_124 ;
F_14 ( V_118 ) ;
V_124 = F_89 ( V_118 , V_119 ) ;
if ( V_124 != NULL ) {
F_97 ( V_118 -> V_14 ,
F_56 ( V_119 ) ) ;
}
}
void F_98 ( const char * V_128 , T_24 * V_129 ,
T_17 V_97 )
{
T_11 V_130 , V_131 ;
if ( V_129 ) {
for ( V_130 = 0 ; V_130 < V_129 -> V_132 ; V_130 ++ ) {
for ( V_131 = V_129 -> V_133 [ V_130 ] . V_134 ; V_131 < V_129 -> V_133 [ V_130 ] . V_135 ; V_131 ++ )
F_96 ( V_128 , V_131 , V_97 ) ;
F_96 ( V_128 , V_129 -> V_133 [ V_130 ] . V_135 , V_97 ) ;
}
}
}
static T_19
F_99 ( T_3 T_25 V_8 , T_3 V_136 , T_3 T_4 )
{
T_23 * V_124 = ( T_23 * ) V_136 ;
T_17 V_97 = ( T_17 ) T_4 ;
if ( ! V_124 -> V_126 -> V_100 ) {
return FALSE ;
}
return ( F_80 ( V_124 -> V_126 -> V_100 ) == F_80 ( V_97 -> V_100 ) ) ;
}
void F_100 ( const char * V_35 , T_17 V_97 )
{
T_22 V_118 = F_87 ( V_35 ) ;
F_14 ( V_118 ) ;
F_101 ( V_118 -> V_14 , F_99 , V_97 ) ;
}
static void
F_102 ( T_3 T_25 V_8 , T_3 V_136 , T_3 T_4 )
{
T_22 V_118 = ( T_22 ) V_136 ;
F_14 ( V_118 ) ;
F_101 ( V_118 -> V_14 , F_99 , T_4 ) ;
V_118 -> V_15 = F_103 ( V_118 -> V_15 , T_4 ) ;
}
static void
F_104 ( T_17 V_97 )
{
F_105 ( V_16 , F_102 , V_97 ) ;
}
void
F_106 ( const char * V_35 , const T_11 V_119 , T_17 V_97 )
{
T_22 V_118 = F_87 ( V_35 ) ;
T_23 * V_124 ;
F_14 ( V_118 ) ;
V_124 = F_89 ( V_118 , V_119 ) ;
if ( V_124 != NULL ) {
V_124 -> V_126 = V_97 ;
return;
}
if ( V_97 == NULL )
return;
V_124 = ( T_23 * ) F_92 ( sizeof ( T_23 ) ) ;
V_124 -> V_127 = NULL ;
V_124 -> V_126 = V_97 ;
F_93 ( V_118 -> V_14 ,
F_56 ( V_119 ) , ( T_3 ) V_124 ) ;
}
void
F_107 ( const char * V_35 , const T_11 V_119 )
{
T_22 V_118 = F_87 ( V_35 ) ;
T_23 * V_124 ;
F_14 ( V_118 ) ;
V_124 = F_89 ( V_118 , V_119 ) ;
if ( V_124 == NULL )
return;
if ( V_124 -> V_127 != NULL ) {
V_124 -> V_126 = V_124 -> V_127 ;
} else {
F_97 ( V_118 -> V_14 ,
F_56 ( V_119 ) ) ;
}
}
int
F_108 ( T_22 V_118 , const T_11 V_137 ,
T_6 * V_28 , T_10 * V_34 , T_18 * V_93 ,
const T_19 V_103 , void * V_1 )
{
T_23 * V_124 ;
struct V_138 * V_97 ;
T_11 V_139 ;
int V_99 ;
V_124 = F_89 ( V_118 , V_137 ) ;
if ( V_124 != NULL ) {
V_97 = V_124 -> V_126 ;
if ( V_97 == NULL ) {
return 0 ;
}
V_139 = V_34 -> V_140 ;
V_34 -> V_140 = V_137 ;
V_99 = F_75 ( V_97 , V_28 , V_34 , V_93 , V_103 , V_1 ) ;
V_34 -> V_140 = V_139 ;
return V_99 ;
}
return 0 ;
}
int
F_109 ( T_22 V_118 , const T_11 V_137 ,
T_6 * V_28 , T_10 * V_34 , T_18 * V_93 )
{
return F_108 ( V_118 , V_137 , V_28 , V_34 , V_93 , TRUE , NULL ) ;
}
T_17
F_110 ( T_22 const V_118 , const T_11 V_137 )
{
T_23 * V_124 ;
V_124 = F_89 ( V_118 , V_137 ) ;
if ( V_124 != NULL )
return V_124 -> V_126 ;
else
return NULL ;
}
T_17
F_111 ( const char * V_35 , const T_11 V_137 )
{
T_22 V_118 = F_87 ( V_35 ) ;
if ( V_118 != NULL ) {
T_23 * V_124 = F_89 ( V_118 , V_137 ) ;
if ( V_124 != NULL )
return V_124 -> V_127 ;
}
return NULL ;
}
static T_23 *
F_112 ( T_22 const V_118 , const T_26 * V_119 )
{
T_23 * V_141 ;
char * T_25 ;
switch ( V_118 -> type ) {
case V_142 :
case V_143 :
case V_144 :
break;
default:
F_61 () ;
}
if ( V_118 -> V_145 == TRUE ) {
T_25 = F_113 ( V_119 , - 1 ) ;
} else {
T_25 = F_44 ( V_119 ) ;
}
V_141 = ( T_23 * ) F_88 ( V_118 -> V_14 , T_25 ) ;
V_6 ( T_25 ) ;
return V_141 ;
}
void
F_114 ( const char * V_35 , const T_26 * V_119 ,
T_17 V_97 )
{
T_22 V_118 = F_87 ( V_35 ) ;
T_23 * V_124 ;
char * T_25 ;
if ( V_118 == NULL ) {
fprintf ( V_125 , L_16 ,
V_35 ) ;
fprintf ( V_125 , L_17 ,
F_91 ( V_97 -> V_100 ) ) ;
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
F_14 ( V_97 != NULL ) ;
switch ( V_118 -> type ) {
case V_142 :
case V_143 :
case V_144 :
break;
default:
F_61 () ;
}
V_124 = ( T_23 * ) F_92 ( sizeof ( T_23 ) ) ;
V_124 -> V_126 = V_97 ;
V_124 -> V_127 = V_124 -> V_126 ;
if ( V_118 -> V_145 == TRUE ) {
T_25 = F_113 ( V_119 , - 1 ) ;
} else {
T_25 = F_44 ( V_119 ) ;
}
F_93 ( V_118 -> V_14 , ( T_3 ) T_25 ,
( T_3 ) V_124 ) ;
F_94 ( V_35 , V_97 ) ;
}
void
F_115 ( const char * V_35 , const T_26 * V_119 ,
T_17 V_97 V_8 )
{
T_22 V_118 = F_87 ( V_35 ) ;
T_23 * V_124 ;
F_14 ( V_118 ) ;
V_124 = F_112 ( V_118 , V_119 ) ;
if ( V_124 != NULL ) {
F_97 ( V_118 -> V_14 , V_119 ) ;
}
}
void
F_116 ( const char * V_35 , const T_26 * V_119 ,
T_17 V_97 )
{
T_22 V_118 = F_87 ( V_35 ) ;
T_23 * V_124 ;
F_14 ( V_118 ) ;
V_124 = F_112 ( V_118 , V_119 ) ;
if ( V_124 != NULL ) {
V_124 -> V_126 = V_97 ;
return;
}
if ( V_97 == NULL )
return;
V_124 = ( T_23 * ) F_92 ( sizeof ( T_23 ) ) ;
V_124 -> V_127 = NULL ;
V_124 -> V_126 = V_97 ;
F_93 ( V_118 -> V_14 , ( T_3 ) F_44 ( V_119 ) ,
( T_3 ) V_124 ) ;
}
void
F_117 ( const char * V_35 , const T_26 * V_119 )
{
T_22 V_118 = F_87 ( V_35 ) ;
T_23 * V_124 ;
F_14 ( V_118 ) ;
V_124 = F_112 ( V_118 , V_119 ) ;
if ( V_124 == NULL )
return;
if ( V_124 -> V_127 != NULL ) {
V_124 -> V_126 = V_124 -> V_127 ;
} else {
F_97 ( V_118 -> V_14 , V_119 ) ;
}
}
int
F_118 ( T_22 V_118 , const T_26 * string ,
T_6 * V_28 , T_10 * V_34 , T_18 * V_93 , void * V_1 )
{
T_23 * V_124 ;
struct V_138 * V_97 ;
int V_99 ;
const T_26 * V_146 ;
if ( ! string ) return 0 ;
V_124 = F_112 ( V_118 , string ) ;
if ( V_124 != NULL ) {
V_97 = V_124 -> V_126 ;
if ( V_97 == NULL ) {
return 0 ;
}
V_146 = V_34 -> V_147 ;
V_34 -> V_147 = string ;
V_99 = F_75 ( V_97 , V_28 , V_34 , V_93 , TRUE , V_1 ) ;
V_34 -> V_147 = V_146 ;
return V_99 ;
}
return 0 ;
}
T_17
F_119 ( T_22 V_118 ,
const T_26 * string )
{
T_23 * V_124 ;
if ( ! string ) return NULL ;
V_124 = F_112 ( V_118 , string ) ;
if ( V_124 != NULL )
return V_124 -> V_126 ;
else
return NULL ;
}
T_17
F_120 ( const char * V_35 , const T_26 * string )
{
T_22 V_118 ;
if ( ! string ) return NULL ;
V_118 = F_87 ( V_35 ) ;
if ( V_118 != NULL ) {
T_23 * V_124 = F_112 ( V_118 , string ) ;
if ( V_124 != NULL )
return V_124 -> V_127 ;
}
return NULL ;
}
void F_121 ( const char * V_35 , void * V_119 , T_17 V_97 )
{
T_22 V_118 = F_87 ( V_35 ) ;
T_23 * V_124 ;
if ( V_118 == NULL ) {
fprintf ( V_125 , L_16 ,
V_35 ) ;
fprintf ( V_125 , L_17 ,
F_91 ( V_97 -> V_100 ) ) ;
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
F_14 ( V_118 -> type == V_148 ) ;
V_124 = ( T_23 * ) F_92 ( sizeof ( T_23 ) ) ;
V_124 -> V_126 = V_97 ;
V_124 -> V_127 = V_124 -> V_126 ;
F_93 ( V_118 -> V_14 , ( T_3 ) V_119 ,
( T_3 ) V_124 ) ;
F_94 ( V_35 , V_97 ) ;
}
T_17 F_122 ( T_22 V_118 , void * T_25 )
{
T_23 * V_124 = ( T_23 * ) F_88 ( V_118 -> V_14 , T_25 ) ;
if ( V_124 != NULL )
return V_124 -> V_126 ;
return NULL ;
}
void F_123 ( const char * V_35 , T_27 * V_149 , T_17 V_97 )
{
T_22 V_118 ;
T_23 * V_124 ;
V_118 = F_87 ( V_35 ) ;
if ( V_118 == NULL ) {
fprintf ( V_125 , L_16 ,
V_35 ) ;
fprintf ( V_125 , L_17 ,
F_91 ( V_97 -> V_100 ) ) ;
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
F_14 ( V_97 != NULL ) ;
if ( V_118 -> type != V_150 ) {
F_61 () ;
}
V_124 = ( T_23 * ) F_92 ( sizeof ( T_23 ) ) ;
V_124 -> V_126 = V_97 ;
V_124 -> V_127 = V_124 -> V_126 ;
F_93 ( V_118 -> V_14 ,
V_149 , ( T_3 ) V_124 ) ;
F_94 ( V_35 , V_97 ) ;
}
int F_124 ( T_22 V_118 ,
T_27 * V_149 , T_6 * V_28 , T_10 * V_34 , T_18 * V_93 , const T_19 V_103 , void * V_1 )
{
T_23 * V_124 ;
struct V_138 * V_97 ;
int V_99 ;
V_124 = ( T_23 * ) F_88 ( V_118 -> V_14 , V_149 ) ;
if ( V_124 != NULL ) {
V_97 = V_124 -> V_126 ;
if ( V_97 == NULL ) {
return 0 ;
}
V_99 = F_75 ( V_97 , V_28 , V_34 , V_93 , V_103 , V_1 ) ;
return V_99 ;
}
return 0 ;
}
int F_125 ( T_22 V_118 ,
T_27 * V_149 , T_6 * V_28 , T_10 * V_34 , T_18 * V_93 )
{
return F_124 ( V_118 , V_149 , V_28 , V_34 , V_93 , TRUE , NULL ) ;
}
T_17 F_126 (
T_22 const V_118 , T_27 * V_149 )
{
T_23 * V_124 ;
V_124 = ( T_23 * ) F_88 ( V_118 -> V_14 , V_149 ) ;
if ( V_124 != NULL )
return V_124 -> V_126 ;
else
return NULL ;
}
T_17
F_127 ( T_23 * V_124 )
{
return V_124 -> V_126 ;
}
static T_28
F_128 ( T_29 V_151 , T_29 V_152 )
{
const struct V_138 * V_153 = ( const struct V_138 * ) V_151 ;
const struct V_138 * V_154 = ( const struct V_138 * ) V_152 ;
const char * V_155 , * V_156 ;
T_28 V_141 ;
if ( V_153 -> V_100 == NULL )
V_155 = L_6 ;
else
V_155 = F_129 ( F_80 ( V_153 -> V_100 ) ) ;
if ( V_154 -> V_100 == NULL )
V_156 = L_6 ;
else
V_156 = F_129 ( F_80 ( V_154 -> V_100 ) ) ;
V_141 = strcmp ( V_155 , V_156 ) ;
return V_141 ;
}
void
F_94 ( const char * V_35 , T_17 V_97 )
{
T_22 V_118 = F_87 ( V_35 ) ;
T_2 * V_157 ;
T_17 V_158 ;
if ( V_118 == NULL ) {
fprintf ( V_125 , L_16 ,
V_35 ) ;
fprintf ( V_125 , L_17 ,
F_91 ( V_97 -> V_100 ) ) ;
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
if ( V_118 -> V_100 != NULL )
F_130 ( F_74 ( V_118 -> V_100 ) , F_74 ( V_97 -> V_100 ) ) ;
V_157 = F_131 ( V_118 -> V_15 , ( T_3 ) V_97 ) ;
if ( V_157 != NULL ) {
return;
}
if ( V_118 -> V_159 == V_160 )
{
for ( V_157 = V_118 -> V_15 ; V_157 != NULL ; V_157 = F_132 ( V_157 ) )
{
V_158 = ( T_17 ) V_157 -> V_1 ;
if ( V_158 -> V_100 == V_97 -> V_100 )
{
fprintf ( V_125 , L_19 ,
F_133 ( V_97 ) ,
F_133 ( V_158 ) ,
F_74 ( V_97 -> V_100 ) ,
V_35 ) ;
if ( getenv ( L_18 ) != NULL )
abort () ;
}
}
}
V_118 -> V_15 =
F_134 ( V_118 -> V_15 , ( T_3 ) V_97 , ( V_161 ) F_128 ) ;
}
T_17
F_135 ( T_23 * V_124 )
{
return V_124 -> V_127 ;
}
T_2 *
F_136 ( T_22 V_12 ) {
if ( ! V_12 ) return NULL ;
return V_12 -> V_15 ;
}
T_30
F_137 ( T_22 V_12 ) {
if ( ! V_12 ) return V_162 ;
return V_12 -> type ;
}
T_31
F_138 ( T_22 V_12 )
{
if ( ! V_12 ) return V_160 ;
return V_12 -> V_159 ;
}
static T_28
F_139 ( T_29 V_163 , T_29 V_164 )
{
const T_27 * V_165 = ( const T_27 * ) V_163 ;
const T_27 * V_166 = ( const T_27 * ) V_164 ;
return ( ( memcmp ( & V_165 -> V_167 , & V_166 -> V_167 , sizeof ( V_168 ) ) == 0 )
&& ( V_165 -> V_169 == V_166 -> V_169 ) ) ;
}
static T_7
F_140 ( T_29 V_170 )
{
const T_27 * T_25 = ( const T_27 * ) V_170 ;
return T_25 -> V_167 . V_171 ;
}
static void
F_141 ( T_3 T_25 , T_3 V_136 , T_3 T_4 )
{
T_32 * V_172 ;
T_23 * V_124 ;
F_14 ( V_136 ) ;
F_14 ( T_4 ) ;
V_124 = ( T_23 * ) V_136 ;
if ( V_124 -> V_126 == NULL ||
V_124 -> V_126 -> V_100 == NULL ) {
return;
}
V_172 = ( T_32 * ) T_4 ;
V_172 -> V_173 ( V_172 -> V_174 , V_172 -> V_175 , T_25 , V_136 ,
V_172 -> V_176 ) ;
}
static void
F_142 ( T_3 T_25 , T_3 V_136 , T_3 T_4 )
{
T_22 V_118 ;
T_32 * V_172 ;
F_14 ( V_136 ) ;
F_14 ( T_4 ) ;
V_118 = ( T_22 ) V_136 ;
V_172 = ( T_32 * ) T_4 ;
V_172 -> V_174 = ( T_26 * ) T_25 ;
V_172 -> V_175 = F_143 ( V_172 -> V_174 ) ;
F_105 ( V_118 -> V_14 , V_172 -> V_177 , V_172 ) ;
}
static void
F_144 ( T_33 F_21 ,
T_3 T_4 )
{
T_32 V_172 ;
V_172 . V_176 = T_4 ;
V_172 . V_173 = F_21 ;
V_172 . V_177 = F_141 ;
F_105 ( V_16 , F_142 , & V_172 ) ;
}
void
F_145 ( const char * V_174 ,
T_33 F_21 ,
T_3 T_4 )
{
T_32 V_172 ;
T_22 V_118 = F_87 ( V_174 ) ;
V_172 . V_174 = V_174 ;
V_172 . V_175 = V_118 -> type ;
V_172 . V_173 = F_21 ;
V_172 . V_176 = T_4 ;
F_105 ( V_118 -> V_14 , F_141 , & V_172 ) ;
}
void
F_146 ( const char * V_174 ,
T_34 F_21 ,
T_3 T_4 )
{
T_22 V_118 = F_87 ( V_174 ) ;
T_2 * V_178 ;
for ( V_178 = V_118 -> V_15 ; V_178 != NULL ;
V_178 = F_132 ( V_178 ) )
F_21 ( V_174 , V_178 -> V_1 , T_4 ) ;
}
static void
F_147 ( T_3 T_25 , T_3 V_136 , T_3 T_4 )
{
T_23 * V_124 ;
T_32 * V_172 ;
F_14 ( V_136 ) ;
F_14 ( T_4 ) ;
V_124 = ( T_23 * ) V_136 ;
if ( V_124 -> V_127 == V_124 -> V_126 ) {
return;
}
V_172 = ( T_32 * ) T_4 ;
V_172 -> V_173 ( V_172 -> V_174 , V_172 -> V_175 , T_25 , V_136 ,
V_172 -> V_176 ) ;
}
void
F_148 ( T_33 F_21 ,
T_3 T_4 )
{
T_32 V_172 ;
V_172 . V_176 = T_4 ;
V_172 . V_173 = F_21 ;
V_172 . V_177 = F_147 ;
F_105 ( V_16 , F_142 , & V_172 ) ;
}
void
F_149 ( const char * V_174 ,
T_33 F_21 ,
T_3 T_4 )
{
T_32 V_172 ;
T_22 V_118 = F_87 ( V_174 ) ;
V_172 . V_174 = V_174 ;
V_172 . V_175 = V_118 -> type ;
V_172 . V_173 = F_21 ;
V_172 . V_176 = T_4 ;
F_105 ( V_118 -> V_14 ,
F_147 , & V_172 ) ;
}
static void
F_150 ( T_3 T_25 , T_3 V_136 , T_3 T_4 )
{
T_22 V_13 ;
T_35 * V_172 ;
V_13 = ( T_22 ) V_136 ;
V_172 = ( T_35 * ) T_4 ;
(* V_172 -> V_173 )( ( T_26 * ) T_25 , V_13 -> V_179 , V_172 -> V_176 ) ;
}
static void
F_151 ( T_3 T_25 , T_3 T_4 )
{
T_22 V_13 ;
T_35 * V_172 ;
V_13 = ( T_22 ) F_88 ( V_16 , T_25 ) ;
V_172 = ( T_35 * ) T_4 ;
(* V_172 -> V_173 )( ( T_26 * ) T_25 , V_13 -> V_179 , V_172 -> V_176 ) ;
}
void
F_152 ( T_36 F_21 ,
T_3 T_4 ,
V_161 V_180 )
{
T_35 V_172 ;
T_37 * V_3 ;
V_172 . V_176 = T_4 ;
V_172 . V_173 = F_21 ;
if ( V_180 != NULL )
{
V_3 = F_153 ( V_16 ) ;
V_3 = F_154 ( V_3 , V_180 ) ;
F_155 ( V_3 , F_151 , & V_172 ) ;
F_156 ( V_3 ) ;
}
else
{
F_105 ( V_16 , F_150 , & V_172 ) ;
}
}
T_22
F_157 ( const char * V_35 , const char * V_179 , const int V_181 , const T_30 type ,
const int V_145 , T_31 V_182 )
{
T_22 V_118 ;
if( F_88 ( V_16 , V_35 ) ) {
F_158 ( L_20 , V_35 , V_179 ) ;
}
V_118 = F_43 ( struct V_12 ) ;
switch ( type ) {
case V_120 :
case V_121 :
case V_122 :
case V_123 :
V_118 -> V_183 = V_184 ;
V_118 -> V_14 = F_10 ( V_184 ,
V_185 ,
NULL ,
& V_6 ) ;
break;
case V_142 :
case V_143 :
case V_144 :
V_118 -> V_183 = V_17 ;
V_118 -> V_14 = F_10 ( V_17 ,
V_18 ,
& V_6 ,
& V_6 ) ;
break;
case V_150 :
V_118 -> V_14 = F_10 ( F_140 ,
F_139 ,
NULL ,
& V_6 ) ;
break;
default:
F_158 ( L_21 , V_35 , V_179 ) ;
F_61 () ;
}
V_118 -> V_15 = NULL ;
V_118 -> V_179 = V_179 ;
V_118 -> type = type ;
V_118 -> V_145 = V_145 ;
V_118 -> V_100 = F_159 ( V_181 ) ;
V_118 -> V_159 = V_182 ;
F_93 ( V_16 , ( T_3 ) V_35 , ( T_3 ) V_118 ) ;
return V_118 ;
}
T_22 F_160 ( const char * V_35 ,
const char * V_179 , const int V_181 , T_38 V_183 , T_39 V_186 , T_31 V_182 )
{
T_22 V_118 ;
if( F_88 ( V_16 , V_35 ) ) {
F_158 ( L_20 , V_35 , V_179 ) ;
}
V_118 = F_43 ( struct V_12 ) ;
V_118 -> V_183 = V_183 ;
V_118 -> V_14 = F_10 ( V_183 ,
V_186 ,
& V_6 ,
& V_6 ) ;
V_118 -> V_15 = NULL ;
V_118 -> V_179 = V_179 ;
V_118 -> type = V_148 ;
V_118 -> V_145 = V_187 ;
V_118 -> V_100 = F_159 ( V_181 ) ;
V_118 -> V_159 = V_182 ;
F_93 ( V_16 , ( T_3 ) V_35 , ( T_3 ) V_118 ) ;
return V_118 ;
}
void
F_161 ( const char * V_35 )
{
T_22 V_118 = F_87 ( V_35 ) ;
if ( ! V_118 ) return;
F_97 ( V_16 , ( T_3 ) V_35 ) ;
}
const char *
F_162 ( const char * V_35 )
{
T_22 V_118 = F_87 ( V_35 ) ;
if ( ! V_118 ) return NULL ;
return V_118 -> V_179 ;
}
T_30
F_143 ( const char * V_35 )
{
T_22 V_118 = F_87 ( V_35 ) ;
if ( ! V_118 ) return V_162 ;
return V_118 -> type ;
}
int
F_163 ( const char * V_35 )
{
T_22 V_118 = F_87 ( V_35 ) ;
if ( ! V_118 ) return 0 ;
return V_118 -> V_145 ;
}
T_5
F_164 ( const char * V_35 )
{
return ( T_5 ) F_88 ( V_21 , V_35 ) ;
}
T_19
F_165 ( const T_26 * V_35 ) {
return ( F_164 ( V_35 ) != NULL ) ;
}
V_9 * F_166 ( const char * V_188 )
{
return ( V_9 * ) F_88 ( V_22 , V_188 ) ;
}
void
F_167 ( const char * V_35 , T_40 V_101 , const char * V_189 , const char * V_188 , const int V_181 , T_41 V_190 )
{
T_5 V_118 = F_164 ( V_35 ) ;
const char * V_191 ;
V_9 * V_192 ;
T_7 V_130 , V_193 ;
T_2 * V_194 ;
if ( V_118 == NULL ) {
fprintf ( V_125 , L_16 ,
V_35 ) ;
V_191 = F_168 ( V_181 ) ;
if ( V_191 != NULL ) {
fprintf ( V_125 , L_17 ,
V_191 ) ;
}
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
V_193 = F_169 ( V_118 -> V_4 ) ;
for ( V_130 = 0 ; V_130 < V_193 ; V_130 ++ )
{
V_194 = F_170 ( V_118 -> V_4 , V_130 ) ;
V_192 = ( V_9 * ) V_194 -> V_1 ;
if ( ( V_192 -> V_101 == V_101 ) &&
( V_192 -> V_100 == F_159 ( V_181 ) ) )
{
V_191 = F_168 ( V_181 ) ;
if ( V_191 != NULL ) {
fprintf ( V_125 , L_22 ,
V_191 , V_35 ) ;
}
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
}
if ( F_88 ( V_22 , V_188 ) != NULL ) {
F_158 ( L_23
L_24 , V_188 ) ;
}
V_192 = F_43 ( V_9 ) ;
V_192 -> V_101 = V_101 ;
V_192 -> V_100 = F_159 ( V_181 ) ;
V_192 -> V_189 = V_189 ;
V_192 -> V_188 = V_188 ;
V_192 -> V_10 = F_44 ( V_35 ) ;
V_192 -> V_195 = ( V_190 == V_196 ) ;
F_93 ( V_22 , ( T_3 ) V_188 , V_192 ) ;
V_118 -> V_4 = F_22 ( V_118 -> V_4 ,
( T_3 ) V_192 ) ;
F_171 ( V_192 -> V_100 , V_188 ) ;
if ( V_118 -> V_100 != NULL )
F_130 ( F_74 ( V_118 -> V_100 ) , F_74 ( V_192 -> V_100 ) ) ;
}
static int
F_172 ( T_29 V_153 , T_29 V_154 ) {
const V_9 * V_197 = ( const V_9 * ) V_153 ;
const V_9 * V_198 = ( const V_9 * ) V_154 ;
return ( V_197 -> V_101 == V_198 -> V_101 ) &&
( V_197 -> V_100 == V_198 -> V_100 ) ? 0 : 1 ;
}
void
F_173 ( const char * V_35 , T_40 V_101 , const int V_181 ) {
T_5 V_118 = F_164 ( V_35 ) ;
V_9 V_192 ;
T_2 * V_199 ;
F_14 ( V_118 != NULL ) ;
V_192 . V_101 = V_101 ;
V_192 . V_100 = F_159 ( V_181 ) ;
V_199 = F_174 ( V_118 -> V_4 ,
( T_3 ) & V_192 , F_172 ) ;
if ( V_199 ) {
V_9 * V_200 = ( V_9 * ) ( V_199 -> V_1 ) ;
V_6 ( V_200 -> V_10 ) ;
F_97 ( V_22 , ( T_3 ) V_200 -> V_188 ) ;
F_4 ( V_9 , V_199 -> V_1 ) ;
V_118 -> V_4 = F_48 ( V_118 -> V_4 ,
V_199 ) ;
}
}
T_19
F_175 ( T_5 V_118 , T_6 * V_28 ,
T_10 * V_34 , T_18 * V_93 , V_9 * * V_201 , void * V_1 )
{
T_19 V_202 ;
const char * V_203 ;
const char * V_204 ;
T_2 * V_157 ;
T_20 V_104 ;
T_7 V_105 = 0 ;
V_9 * V_192 ;
int V_205 ;
V_104 = V_34 -> V_106 ;
V_34 -> V_104 = V_104 ;
V_34 -> V_106 = V_104 - ( V_104 > 0 ) ;
V_202 = FALSE ;
V_203 = V_34 -> V_62 ;
V_204 = V_34 -> V_206 ;
V_105 = F_77 ( V_34 -> V_84 ) ;
* V_201 = NULL ;
for ( V_157 = V_118 -> V_4 ; V_157 != NULL ;
V_157 = F_132 ( V_157 ) ) {
V_34 -> V_106 = V_104 - ( V_104 > 0 ) ;
V_192 = ( V_9 * ) V_157 -> V_1 ;
if ( V_192 -> V_100 != NULL &&
( ! F_76 ( V_192 -> V_100 ) || ( V_192 -> V_195 == FALSE ) ) ) {
continue;
}
if ( V_192 -> V_100 != NULL ) {
V_205 = F_80 ( V_192 -> V_100 ) ;
V_34 -> V_62 =
F_74 ( V_192 -> V_100 ) ;
F_78 ( V_34 -> V_84 , F_79 ( V_205 ) ) ;
}
V_34 -> V_206 = V_192 -> V_10 ;
if ( ( V_192 -> V_101 ) ( V_28 , V_34 , V_93 , V_1 ) ) {
* V_201 = V_192 ;
V_202 = TRUE ;
break;
} else {
while ( F_77 ( V_34 -> V_84 ) > V_105 ) {
F_82 ( V_34 -> V_84 , F_83 ( V_34 -> V_84 ) ) ;
}
}
}
V_34 -> V_62 = V_203 ;
V_34 -> V_206 = V_204 ;
V_34 -> V_106 = V_104 ;
return V_202 ;
}
static void
F_176 ( T_3 V_1 , T_3 T_4 )
{
T_42 * V_172 ;
F_14 ( V_1 ) ;
F_14 ( T_4 ) ;
V_172 = ( T_42 * ) T_4 ;
V_172 -> V_173 ( V_172 -> V_174 , ( V_9 * ) V_1 ,
V_172 -> V_176 ) ;
}
void
F_177 ( const char * V_174 ,
T_43 F_21 ,
T_3 T_4 )
{
T_42 V_172 ;
T_5 V_118 = F_164 ( V_174 ) ;
V_172 . V_174 = V_174 ;
V_172 . V_173 = F_21 ;
V_172 . V_176 = T_4 ;
F_2 ( V_118 -> V_4 ,
F_176 , & V_172 ) ;
}
static void
F_178 ( T_3 T_25 , T_3 V_136 , T_3 T_4 )
{
T_44 * V_172 ;
V_172 = ( T_44 * ) T_4 ;
(* V_172 -> V_173 )( ( T_26 * ) T_25 , (struct V_11 * ) V_136 , V_172 -> V_176 ) ;
}
static void
F_179 ( T_3 T_25 , T_3 T_4 )
{
struct V_11 * V_3 ;
T_44 * V_172 ;
V_3 = (struct V_11 * ) F_88 ( V_21 , T_25 ) ;
V_172 = ( T_44 * ) T_4 ;
(* V_172 -> V_173 )( ( T_26 * ) T_25 , V_3 , V_172 -> V_176 ) ;
}
void
F_180 ( T_45 F_21 ,
T_3 T_4 ,
V_161 V_180 )
{
T_44 V_172 ;
T_37 * V_3 ;
V_172 . V_176 = T_4 ;
V_172 . V_173 = F_21 ;
if ( V_180 != NULL )
{
V_3 = F_153 ( V_16 ) ;
V_3 = F_154 ( V_3 , V_180 ) ;
F_155 ( V_3 , F_179 , & V_172 ) ;
F_156 ( V_3 ) ;
}
else
{
F_105 ( V_21 , F_178 , & V_172 ) ;
}
}
static void
F_181 ( const char * V_174 ,
V_9 * V_192 , T_3 T_4 V_8 )
{
if ( V_192 -> V_100 != NULL ) {
printf ( L_25 ,
V_174 ,
F_129 ( F_80 ( V_192 -> V_100 ) ) ,
( F_76 ( V_192 -> V_100 ) && V_192 -> V_195 ) ? 'T' : 'F' ) ;
}
}
static void
F_182 ( const T_26 * V_174 , struct V_11 * T_46 V_8 , T_3 T_4 V_8 )
{
F_177 ( V_174 , F_181 , NULL ) ;
}
void
F_183 ( void )
{
F_180 ( F_182 , NULL , NULL ) ;
}
T_5
F_184 ( const char * V_35 , const int V_181 )
{
T_5 V_118 ;
if ( F_88 ( V_21 , V_35 ) != NULL ) {
F_158 ( L_26 , V_35 ) ;
}
V_118 = F_43 ( struct V_11 ) ;
V_118 -> V_100 = F_159 ( V_181 ) ;
V_118 -> V_4 = NULL ;
F_93 ( V_21 , ( T_3 ) V_35 ,
( T_3 ) V_118 ) ;
return V_118 ;
}
const char *
F_185 ( const T_17 V_97 )
{
if ( V_97 == NULL || V_97 -> V_100 == NULL ) {
return NULL ;
}
return F_91 ( V_97 -> V_100 ) ;
}
const char *
F_186 ( const T_17 V_97 )
{
if ( V_97 -> V_100 == NULL ) {
return NULL ;
}
return F_74 ( V_97 -> V_100 ) ;
}
int
F_187 ( const T_17 V_97 )
{
if ( V_97 -> V_100 == NULL ) {
return - 1 ;
}
return F_80 ( V_97 -> V_100 ) ;
}
T_37 *
F_188 ( void )
{
return F_153 ( V_19 ) ;
}
T_17
F_13 ( const char * V_35 )
{
return ( T_17 ) F_88 ( V_19 , V_35 ) ;
}
T_17 F_189 ( const char * V_35 , const int V_207 )
{
T_17 V_97 = ( T_17 ) F_88 ( V_19 , V_35 ) ;
if ( ( V_97 != NULL ) && ( V_207 > 0 ) )
{
F_130 ( F_74 ( F_159 ( V_207 ) ) , F_186 ( V_97 ) ) ;
}
return V_97 ;
}
const char *
F_133 ( const T_17 V_97 )
{
if ( V_97 == NULL ) {
return NULL ;
}
return V_97 -> V_35 ;
}
T_17
F_190 ( T_47 V_101 , const int V_181 )
{
struct V_138 * V_97 ;
V_97 = F_191 ( F_192 () , struct V_138 ) ;
V_97 -> V_35 = NULL ;
V_97 -> V_101 = V_101 ;
V_97 -> V_100 = F_159 ( V_181 ) ;
return V_97 ;
}
T_17 F_193 ( T_47 V_101 ,
const int V_181 , const char * V_35 )
{
struct V_138 * V_97 ;
V_97 = F_191 ( F_192 () , struct V_138 ) ;
V_97 -> V_35 = V_35 ;
V_97 -> V_101 = V_101 ;
V_97 -> V_100 = F_159 ( V_181 ) ;
return V_97 ;
}
static void
F_194 ( T_17 V_97 )
{
if ( V_97 == NULL ) return;
F_104 ( V_97 ) ;
F_195 ( V_97 ) ;
F_196 ( F_192 () , V_97 ) ;
}
T_17
F_197 ( const char * V_35 , T_47 V_101 , const int V_181 )
{
struct V_138 * V_97 ;
F_14 ( F_88 ( V_19 , V_35 ) == NULL ) ;
V_97 = F_191 ( F_192 () , struct V_138 ) ;
V_97 -> V_35 = V_35 ;
V_97 -> V_101 = V_101 ;
V_97 -> V_100 = F_159 ( V_181 ) ;
F_93 ( V_19 , ( T_3 ) V_35 ,
( T_3 ) V_97 ) ;
return V_97 ;
}
static T_19
F_198 ( T_1 V_118 , const char * V_208 )
{
T_2 * V_199 ;
V_199 = F_174 ( V_118 -> V_4 ,
( T_3 ) V_208 , ( V_161 ) strcmp ) ;
if ( V_199 ) {
V_6 ( V_199 -> V_1 ) ;
V_118 -> V_4 = F_48 ( V_118 -> V_4 , V_199 ) ;
return TRUE ;
}
return FALSE ;
}
static void
F_199 ( T_3 T_25 V_8 , T_3 V_136 , T_3 T_4 )
{
T_1 V_118 = ( T_1 ) V_136 ;
const char * V_208 = ( const char * ) T_4 ;
F_198 ( V_118 , V_208 ) ;
}
void
F_200 ( const char * V_35 )
{
T_17 V_97 = F_13 ( V_35 ) ;
if ( V_97 == NULL ) return;
F_97 ( V_19 , ( T_3 ) V_35 ) ;
F_97 ( V_20 , ( T_3 ) V_35 ) ;
F_105 ( V_20 , F_199 , ( T_3 ) V_35 ) ;
F_97 ( V_21 , ( T_3 ) V_35 ) ;
F_194 ( V_97 ) ;
}
int
F_201 ( T_17 V_97 , T_6 * V_28 ,
T_10 * V_34 , T_18 * V_93 , void * V_1 )
{
int V_141 ;
F_14 ( V_97 != NULL ) ;
V_141 = F_75 ( V_97 , V_28 , V_34 , V_93 , TRUE , V_1 ) ;
return V_141 ;
}
int
F_68 ( T_17 V_97 , T_6 * V_28 ,
T_10 * V_34 , T_18 * V_93 , void * V_1 )
{
int V_141 ;
V_141 = F_201 ( V_97 , V_28 , V_34 , V_93 , V_1 ) ;
if ( V_141 == 0 ) {
F_14 ( V_26 -> V_100 != NULL ) ;
F_75 ( V_26 , V_28 , V_34 , V_93 , TRUE , NULL ) ;
return F_50 ( V_28 ) ;
}
return V_141 ;
}
int
F_202 ( T_17 V_97 , T_6 * V_28 ,
T_10 * V_34 , T_18 * V_93 )
{
return F_68 ( V_97 , V_28 , V_34 , V_93 , NULL ) ;
}
int
F_203 ( T_6 * V_28 , T_10 * V_34 , T_18 * V_93 )
{
return F_75 ( V_26 , V_28 , V_34 , V_93 , TRUE , NULL ) ;
}
void F_204 ( V_9 * V_201 , T_6 * V_28 ,
T_10 * V_34 , T_18 * V_93 , void * V_1 )
{
const char * V_203 ;
const char * V_204 ;
T_20 V_104 ;
F_14 ( V_201 ) ;
V_104 = V_34 -> V_106 ;
V_34 -> V_104 = V_104 ;
V_34 -> V_106 = V_104 - ( V_104 > 0 ) ;
V_203 = V_34 -> V_62 ;
V_204 = V_34 -> V_206 ;
if ( ! V_201 -> V_195 ||
( V_201 -> V_100 != NULL && ! F_76 ( V_201 -> V_100 ) ) ) {
F_14 ( V_26 -> V_100 != NULL ) ;
F_75 ( V_26 , V_28 , V_34 , V_93 , TRUE , NULL ) ;
return;
}
if ( V_201 -> V_100 != NULL ) {
V_34 -> V_62 = F_74 ( V_201 -> V_100 ) ;
F_78 ( V_34 -> V_84 , F_79 ( F_80 ( V_201 -> V_100 ) ) ) ;
}
V_34 -> V_206 = V_201 -> V_10 ;
if( ! (* V_201 -> V_101 )( V_28 , V_34 , V_93 , V_1 ) )
F_61 () ;
V_34 -> V_106 = V_104 ;
V_34 -> V_62 = V_203 ;
V_34 -> V_206 = V_204 ;
}
T_19 F_130 ( const char * V_209 , const char * V_208 )
{
T_7 V_130 , V_193 ;
T_2 * V_194 ;
const char * V_210 ;
T_1 V_118 ;
if ( ( V_209 == NULL ) || ( V_208 == NULL ) )
{
return FALSE ;
}
V_118 = F_205 ( V_209 ) ;
if ( V_118 == NULL ) {
V_118 = F_43 ( struct V_7 ) ;
V_118 -> V_4 = NULL ;
F_93 ( V_20 , ( T_3 ) F_44 ( V_209 ) , ( T_3 ) V_118 ) ;
}
V_193 = F_169 ( V_118 -> V_4 ) ;
for ( V_130 = 0 ; V_130 < V_193 ; V_130 ++ )
{
V_194 = F_170 ( V_118 -> V_4 , V_130 ) ;
V_210 = ( const char * ) V_194 -> V_1 ;
if ( strcmp ( V_208 , V_210 ) == 0 )
return TRUE ;
}
V_118 -> V_4 = F_22 ( V_118 -> V_4 , ( T_3 ) F_44 ( V_208 ) ) ;
return TRUE ;
}
T_19 F_206 ( const char * V_209 , const char * V_208 )
{
T_1 V_118 = F_205 ( V_209 ) ;
F_14 ( V_118 != NULL ) ;
return F_198 ( V_118 , V_208 ) ;
}
T_1 F_205 ( const char * V_35 )
{
return ( T_1 ) F_88 ( V_20 , V_35 ) ;
}
static void
F_207 ( const T_26 * V_174 ,
T_30 V_175 V_8 , T_3 T_25 , T_3 V_136 ,
T_3 T_4 V_8 )
{
T_11 V_211 = F_208 ( T_25 ) ;
T_22 V_118 = F_87 ( V_174 ) ;
T_23 * V_124 ;
T_17 V_97 ;
T_28 V_205 ;
const T_26 * V_212 ;
F_14 ( V_118 ) ;
switch ( V_118 -> type ) {
case V_120 :
case V_121 :
case V_122 :
case V_123 :
V_124 = ( T_23 * ) V_136 ;
F_14 ( V_124 ) ;
V_97 = V_124 -> V_126 ;
F_14 ( V_97 ) ;
V_205 = F_187 ( V_97 ) ;
if ( V_205 != - 1 ) {
V_212 = F_129 ( V_205 ) ;
F_14 ( V_212 != NULL ) ;
printf ( L_27 , V_174 , V_211 , V_212 ) ;
}
break;
default:
break;
}
}
void
F_209 ( void )
{
F_144 ( F_207 , NULL ) ;
}
static void
F_210 ( T_3 T_25 , T_3 T_4 V_8 )
{
const char * V_174 = ( const char * ) T_25 ;
T_22 V_13 ;
V_13 = ( T_22 ) F_88 ( V_16 , T_25 ) ;
printf ( L_28 , V_174 , V_13 -> V_179 , F_211 ( V_13 -> type ) ) ;
switch ( V_13 -> type ) {
case V_120 :
case V_121 :
case V_122 :
case V_123 :
switch( V_13 -> V_145 ) {
case V_187 :
printf ( L_29 ) ;
break;
case V_213 :
printf ( L_30 ) ;
break;
case V_214 :
printf ( L_31 ) ;
break;
case V_215 :
printf ( L_32 ) ;
break;
case V_216 :
printf ( L_33 ) ;
break;
default:
printf ( L_34 , V_13 -> V_145 ) ;
break;
}
break;
default:
break;
}
printf ( L_35 ) ;
}
static T_28
F_212 ( T_29 V_151 , T_29 V_152 )
{
return strcmp ( ( const char * ) V_151 , ( const char * ) V_152 ) ;
}
void
F_213 ( void )
{
T_37 * V_3 ;
V_3 = F_153 ( V_16 ) ;
V_3 = F_154 ( V_3 , F_212 ) ;
F_155 ( V_3 , F_210 , NULL ) ;
F_156 ( V_3 ) ;
}
void
F_214 ( T_17 V_97 )
{
if ( ! V_217 )
V_217 = F_215 () ;
F_216 ( V_217 , V_97 ) ;
V_218 ++ ;
}
void
F_195 ( T_17 V_97 )
{
if ( ! V_217 ) return;
if ( F_217 ( V_217 , V_97 ) ) {
V_218 -- ;
}
}
T_19
F_218 ( void )
{
T_7 V_130 ;
T_17 V_97 ;
for( V_130 = 0 ; V_130 < V_218 ; V_130 ++ ) {
V_97 = ( T_17 ) F_219 ( V_217 , V_130 ) ;
if ( V_97 -> V_100 != NULL
&& F_76 ( V_97 -> V_100 ) ) {
return TRUE ;
}
}
return FALSE ;
}
void
F_220 ( T_6 * V_28 , T_10 * V_34 , T_18 * V_93 )
{
T_7 V_130 ;
for( V_130 = 0 ; V_130 < V_218 ; V_130 ++ ) {
F_201 ( ( T_17 ) F_219 ( V_217 , V_130 ) ,
V_28 , V_34 , V_93 , NULL ) ;
}
}
