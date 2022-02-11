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
T_5 * V_9 = ( T_5 * ) V_1 ;
V_6 ( V_9 -> V_10 ) ;
V_6 ( V_9 -> V_11 ) ;
F_4 ( T_5 , V_1 ) ;
}
static void
F_6 ( void * V_1 )
{
T_6 V_2 = ( T_6 ) V_1 ;
T_2 * * V_3 = & ( V_2 -> V_4 ) ;
F_2 ( * V_3 , F_5 , NULL ) ;
F_3 ( * V_3 ) ;
F_4 ( struct V_12 , V_2 ) ;
}
static void
F_7 ( void * V_1 )
{
struct V_13 * V_14 = (struct V_13 * ) V_1 ;
F_8 ( V_14 -> V_15 ) ;
F_3 ( V_14 -> V_16 ) ;
F_4 ( struct V_13 , V_1 ) ;
}
void
F_9 ( void )
{
V_17 = F_10 ( V_18 , V_19 ,
NULL , F_7 ) ;
V_20 = F_10 ( V_18 , V_19 ,
NULL , NULL ) ;
V_21 = F_10 ( V_18 , V_19 ,
V_6 , F_1 ) ;
V_22 = F_10 ( V_18 , V_19 ,
NULL , F_6 ) ;
V_23 = F_11 ( V_24 , V_19 ) ;
}
void
F_12 ( void )
{
V_25 = F_13 ( L_1 ) ;
F_14 ( V_25 != NULL ) ;
V_26 = F_13 ( L_2 ) ;
F_14 ( V_26 != NULL ) ;
V_27 = F_13 ( L_3 ) ;
F_14 ( V_27 != NULL ) ;
V_28 = F_15 ( L_4 ) ;
F_14 ( V_28 != - 1 ) ;
}
static void
F_16 ( T_3 V_29 , T_3 T_7 V_8 )
{
T_8 V_30 = ( T_8 ) V_29 ;
(* V_30)() ;
}
void
F_17 ( void )
{
F_3 ( V_31 ) ;
F_3 ( V_32 ) ;
F_3 ( V_33 ) ;
F_8 ( V_17 ) ;
F_8 ( V_20 ) ;
F_8 ( V_21 ) ;
F_8 ( V_22 ) ;
F_8 ( V_23 ) ;
F_2 ( V_34 , & F_16 , NULL ) ;
F_3 ( V_34 ) ;
if ( V_35 )
F_18 ( V_35 , TRUE ) ;
}
void
F_19 ( T_9 * V_36 , const T_10 V_37 )
{
if ( V_37 < F_20 ( V_36 ) ) {
F_21 ( V_36 , V_37 ) ;
}
}
void
F_22 ( void (* V_30)( void ) )
{
V_31 = F_23 ( V_31 , ( T_3 ) V_30 ) ;
}
void
F_24 ( void (* V_30)( void ) )
{
V_32 = F_23 ( V_32 , ( T_3 ) V_30 ) ;
}
void
F_25 ( void (* V_30)( void ) )
{
V_34 = F_23 ( V_34 , ( T_3 ) V_30 ) ;
}
void
F_26 ( void )
{
F_27 () ;
F_28 () ;
F_29 () ;
F_30 () ;
F_2 ( V_31 , & F_16 , NULL ) ;
F_31 () ;
F_32 () ;
}
void
F_33 ( void )
{
F_34 () ;
F_2 ( V_32 , & F_16 , NULL ) ;
F_35 () ;
F_36 () ;
F_37 () ;
F_38 () ;
}
void
F_39 ( T_8 V_30 )
{
V_33 = F_23 ( V_33 ,
( T_3 ) V_30 ) ;
}
void
F_40 ( void )
{
F_2 ( V_33 ,
& F_16 , NULL ) ;
}
void
F_41 ( T_11 * V_38 , T_9 * V_36 , const char * V_39 )
{
struct V_40 * V_41 ;
V_41 = F_42 ( V_38 -> V_42 , struct V_40 ) ;
V_41 -> V_36 = V_36 ;
V_41 -> V_39 = F_43 ( V_38 -> V_42 , V_39 ) ;
V_38 -> V_43 = F_44 ( V_38 -> V_43 , V_41 ) ;
}
void
F_45 ( T_11 * V_38 )
{
T_2 * V_44 ;
V_44 = F_46 ( V_38 -> V_43 ) ;
V_38 -> V_43 = F_47 ( V_38 -> V_43 , V_44 ) ;
}
char *
F_48 ( const struct V_40 * V_41 )
{
T_10 V_45 = F_49 ( V_41 -> V_36 ) ;
return F_50 ( NULL , L_5 , V_41 -> V_39 , V_45 ,
F_51 ( V_45 , L_6 , L_7 ) ) ;
}
T_9 *
F_52 ( const struct V_40 * V_41 )
{
return V_41 -> V_36 ;
}
T_9 *
F_53 ( T_11 * V_38 , const char * V_39 )
{
T_2 * V_46 ;
for ( V_46 = V_38 -> V_43 ; V_46 ; V_46 = V_46 -> V_47 ) {
struct V_40 * V_48 = (struct V_40 * ) V_46 ;
if ( V_48 -> V_39 && strcmp ( V_48 -> V_39 , V_39 ) == 0 ) {
return V_48 -> V_36 ;
}
}
return NULL ;
}
void
F_54 ( T_11 * V_38 )
{
if ( V_38 -> V_43 ) {
F_3 ( V_38 -> V_43 ) ;
V_38 -> V_43 = NULL ;
}
}
void
F_55 ( T_11 * V_38 , T_12 V_49 )
{
if ( V_49 != V_38 -> V_50 ) {
V_38 -> V_51 = F_23 ( V_38 -> V_51 , F_56 ( V_49 ) ) ;
}
}
void
F_57 ( void (* V_30)( void ) )
{
V_52 = F_23 ( V_52 ,
( T_3 ) V_30 ) ;
}
void
F_58 ( void )
{
F_2 ( V_52 ,
& F_16 , NULL ) ;
}
void
F_59 ( T_13 * V_53 , int V_54 ,
struct V_55 * V_56 , T_9 * V_36 , T_14 * V_57 , T_15 * V_58 )
{
const char * volatile V_59 ;
T_16 V_60 ;
switch ( V_56 -> V_61 ) {
case V_62 :
V_59 = L_8 ;
break;
case V_63 :
V_59 = L_9 ;
break;
case V_64 :
V_59 = L_10 ;
break;
case V_65 :
V_59 = L_11 ;
break;
default:
F_60 () ;
break;
}
if ( V_58 != NULL )
F_61 ( V_58 , V_53 -> V_66 ) ;
V_53 -> V_67 . V_68 = V_53 -> V_66 ;
V_53 -> V_67 . V_69 = L_12 ;
V_53 -> V_67 . V_58 = V_58 ;
V_53 -> V_67 . V_70 = 0 ;
V_53 -> V_67 . V_50 = V_57 -> V_50 ;
if ( V_57 -> V_71 . V_72 ) {
V_53 -> V_67 . V_70 |= V_73 ;
V_53 -> V_67 . V_74 = V_57 -> V_74 ;
}
V_53 -> V_67 . V_75 = V_56 -> V_75 ;
V_53 -> V_67 . V_57 = V_57 ;
V_53 -> V_67 . V_56 = V_56 ;
V_53 -> V_67 . V_76 = & V_56 -> V_76 ;
F_62 ( & V_53 -> V_67 . V_77 ) ;
F_62 ( & V_53 -> V_67 . V_78 ) ;
F_62 ( & V_53 -> V_67 . V_79 ) ;
F_62 ( & V_53 -> V_67 . V_80 ) ;
F_62 ( & V_53 -> V_67 . V_41 ) ;
F_62 ( & V_53 -> V_67 . V_81 ) ;
V_53 -> V_67 . V_82 = V_83 ;
V_53 -> V_67 . V_84 = L_6 ;
V_53 -> V_67 . V_85 = V_86 ;
V_53 -> V_67 . V_87 = V_88 ;
V_53 -> V_67 . V_89 = V_90 ;
V_53 -> V_67 . V_91 = F_63 ( V_53 -> V_67 . V_42 ) ;
V_53 -> V_36 = V_36 ;
F_64 ( V_53 -> V_66 , V_57 , V_57 -> V_92 , & V_53 -> V_67 . V_93 ) ;
if ( V_57 -> V_71 . V_94 )
V_60 . V_95 = F_65 ( V_53 -> V_66 , V_57 ) ;
else if ( V_57 -> V_71 . V_96 )
V_60 . V_95 = V_56 -> V_97 ;
else
V_60 . V_95 = NULL ;
V_60 . V_54 = V_54 ;
V_60 . V_98 = V_53 ;
F_66 {
F_41 ( & V_53 -> V_67 , V_53 -> V_36 , V_59 ) ;
F_67 ( V_25 , V_53 -> V_36 , & V_53 -> V_67 , V_53 -> V_99 , & V_60 ) ;
}
F_68 (BoundsError) {
F_60 () ;
}
F_69 (FragmentBoundsError, ReportedBoundsError) {
F_70 ( V_53 -> V_99 , V_28 , V_53 -> V_36 , 0 , 0 ,
L_13 ,
V_59 ) ;
}
V_100 ;
V_57 -> V_71 . V_101 = 1 ;
}
void
F_71 ( T_13 * V_53 , struct V_55 * V_56 ,
T_9 * V_36 , T_14 * V_57 , T_15 * V_58 )
{
T_17 V_102 ;
if ( V_58 != NULL )
F_61 ( V_58 , V_53 -> V_66 ) ;
V_53 -> V_67 . V_68 = V_53 -> V_66 ;
V_53 -> V_67 . V_69 = L_14 ;
V_53 -> V_67 . V_58 = V_58 ;
V_53 -> V_67 . V_57 = V_57 ;
V_53 -> V_67 . V_56 = V_56 ;
V_53 -> V_67 . V_76 = & V_56 -> V_76 ;
F_62 ( & V_53 -> V_67 . V_77 ) ;
F_62 ( & V_53 -> V_67 . V_78 ) ;
F_62 ( & V_53 -> V_67 . V_79 ) ;
F_62 ( & V_53 -> V_67 . V_80 ) ;
F_62 ( & V_53 -> V_67 . V_41 ) ;
F_62 ( & V_53 -> V_67 . V_81 ) ;
V_53 -> V_67 . V_82 = V_83 ;
V_53 -> V_67 . V_84 = L_6 ;
V_53 -> V_67 . V_85 = V_86 ;
V_53 -> V_67 . V_87 = V_88 ;
V_53 -> V_67 . V_89 = V_90 ;
V_53 -> V_67 . V_91 = F_63 ( V_53 -> V_67 . V_42 ) ;
V_53 -> V_36 = V_36 ;
F_64 ( V_53 -> V_66 , V_57 , V_57 -> V_92 , & V_53 -> V_67 . V_93 ) ;
F_66 {
if ( V_57 -> V_71 . V_94 )
V_102 . V_95 = F_65 ( V_53 -> V_66 , V_57 ) ;
else if ( V_57 -> V_71 . V_96 )
V_102 . V_95 = V_56 -> V_97 ;
else
V_102 . V_95 = NULL ;
V_102 . V_98 = V_53 ;
F_41 ( & V_53 -> V_67 , V_53 -> V_36 , L_15 ) ;
F_67 ( V_26 , V_53 -> V_36 , & V_53 -> V_67 , V_53 -> V_99 , & V_102 ) ;
}
F_68 (BoundsError) {
F_60 () ;
}
F_69 (FragmentBoundsError, ReportedBoundsError) {
F_70 ( V_53 -> V_99 , V_28 , V_53 -> V_36 , 0 , 0 ,
L_16 ) ;
}
V_100 ;
V_57 -> V_71 . V_101 = 1 ;
}
static int
F_72 ( T_18 V_103 , T_9 * V_36 ,
T_11 * V_38 , T_19 * V_99 , void * V_1 )
{
const char * V_104 ;
int V_105 ;
V_104 = V_38 -> V_69 ;
if ( ( V_103 -> V_106 != NULL ) && ( ! F_73 ( V_103 -> V_106 ) ) ) {
V_38 -> V_69 =
F_74 ( V_103 -> V_106 ) ;
}
V_105 = (* V_103 -> V_107 )( V_36 , V_38 , V_99 , V_1 ) ;
V_38 -> V_69 = V_104 ;
return V_105 ;
}
static int
F_75 ( T_18 V_103 , T_9 * V_36 , T_11 * V_108 ,
T_19 * V_99 , T_20 V_109 , void * V_1 )
{
T_11 * V_38 = V_108 ;
const char * V_104 ;
T_21 V_110 ;
int V_105 ;
T_10 V_111 = 0 ;
if ( V_103 -> V_106 != NULL &&
! F_76 ( V_103 -> V_106 ) ) {
return 0 ;
}
V_104 = V_38 -> V_69 ;
V_110 = V_38 -> V_112 ;
V_111 = F_77 ( V_38 -> V_91 ) ;
V_38 -> V_110 = V_110 ;
V_38 -> V_112 = V_110 - ( V_110 > 0 ) ;
if ( ( V_103 -> V_106 != NULL ) && ( ! F_73 ( V_103 -> V_106 ) ) ) {
V_38 -> V_69 =
F_74 ( V_103 -> V_106 ) ;
if ( V_109 ) {
V_38 -> V_113 ++ ;
F_78 ( V_38 -> V_91 , F_79 ( F_80 ( V_103 -> V_106 ) ) ) ;
}
}
if ( V_38 -> V_71 . V_114 ) {
V_105 = F_81 ( V_103 , V_36 , V_38 , V_99 , V_1 ) ;
} else {
V_105 = F_72 ( V_103 , V_36 , V_38 , V_99 , V_1 ) ;
}
if ( V_105 == 0 ) {
while ( F_77 ( V_38 -> V_91 ) > V_111 ) {
F_82 ( V_38 -> V_91 , F_83 ( V_38 -> V_91 ) ) ;
}
}
V_38 -> V_69 = V_104 ;
V_38 -> V_112 = V_110 ;
return V_105 ;
}
static int
F_81 ( T_18 V_103 , T_9 * V_36 ,
T_11 * V_108 , T_19 * V_99 , void * V_1 )
{
T_11 * V_38 = V_108 ;
const char * V_104 ;
T_21 V_110 ;
volatile int V_105 = 0 ;
T_20 V_115 ;
T_22 V_116 ;
T_22 V_117 ;
T_22 V_118 ;
T_22 V_119 ;
T_22 V_120 ;
T_22 V_121 ;
V_104 = V_38 -> V_69 ;
V_110 = V_38 -> V_112 ;
V_115 = F_84 ( V_38 -> V_58 , - 1 ) ;
F_85 ( V_38 -> V_58 , - 1 , FALSE ) ;
F_86 ( & V_116 , & V_38 -> V_77 ) ;
F_86 ( & V_117 , & V_38 -> V_78 ) ;
F_86 ( & V_118 , & V_38 -> V_79 ) ;
F_86 ( & V_119 , & V_38 -> V_80 ) ;
F_86 ( & V_120 , & V_38 -> V_41 ) ;
F_86 ( & V_121 , & V_38 -> V_81 ) ;
F_66 {
V_105 = F_72 ( V_103 , V_36 , V_38 , V_99 , V_1 ) ;
}
F_68 (BoundsError) {
F_85 ( V_38 -> V_58 , - 1 , V_115 ) ;
F_86 ( & V_38 -> V_77 , & V_116 ) ;
F_86 ( & V_38 -> V_78 , & V_117 ) ;
F_86 ( & V_38 -> V_79 , & V_118 ) ;
F_86 ( & V_38 -> V_80 , & V_119 ) ;
F_86 ( & V_38 -> V_41 , & V_120 ) ;
F_86 ( & V_38 -> V_81 , & V_121 ) ;
V_38 -> V_69 = V_104 ;
V_38 -> V_112 = V_110 ;
V_122 ;
}
F_69 (FragmentBoundsError, ReportedBoundsError) {
V_105 = F_49 ( V_36 ) ;
}
V_100 ;
F_85 ( V_38 -> V_58 , - 1 , V_115 ) ;
F_86 ( & V_38 -> V_77 , & V_116 ) ;
F_86 ( & V_38 -> V_78 , & V_117 ) ;
F_86 ( & V_38 -> V_79 , & V_118 ) ;
F_86 ( & V_38 -> V_80 , & V_119 ) ;
F_86 ( & V_38 -> V_41 , & V_120 ) ;
F_86 ( & V_38 -> V_81 , & V_121 ) ;
V_38 -> V_123 = 0 ;
return V_105 ;
}
T_23
F_87 ( const char * V_39 )
{
return ( T_23 ) F_88 ( V_17 , V_39 ) ;
}
static T_24 *
F_89 ( T_23 V_124 , const T_12 V_125 )
{
switch ( V_124 -> type ) {
case V_126 :
case V_127 :
case V_128 :
case V_129 :
break;
default:
F_60 () ;
}
return ( T_24 * ) F_88 ( V_124 -> V_15 ,
F_56 ( V_125 ) ) ;
}
void
F_90 ( const char * V_39 , const T_12 V_125 , T_18 V_103 )
{
T_23 V_124 ;
T_24 * V_130 ;
V_124 = F_87 ( V_39 ) ;
if ( V_103 == NULL ) {
fprintf ( V_131 , L_17 ,
V_39 ) ;
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
if ( V_124 == NULL ) {
fprintf ( V_131 , L_19 ,
V_39 ) ;
fprintf ( V_131 , L_20 ,
F_91 ( V_103 -> V_106 ) ) ;
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
switch ( V_124 -> type ) {
case V_126 :
case V_127 :
case V_128 :
case V_129 :
break;
default:
F_60 () ;
}
#if 0
dissector_add_uint_sanity_check(name, pattern, handle, sub_dissectors);
#endif
V_130 = ( T_24 * ) F_92 ( sizeof ( T_24 ) ) ;
V_130 -> V_132 = V_103 ;
V_130 -> V_133 = V_130 -> V_132 ;
F_93 ( V_124 -> V_15 ,
F_56 ( V_125 ) , ( T_3 ) V_130 ) ;
if ( V_124 -> V_134 )
F_94 ( V_39 , V_103 ) ;
}
void F_95 ( const char * V_135 , T_25 * V_136 ,
T_18 V_103 )
{
T_12 V_137 , V_138 ;
if ( V_136 ) {
if ( V_136 -> V_139 == 0 ) {
F_94 ( V_135 , V_103 ) ;
}
else {
for ( V_137 = 0 ; V_137 < V_136 -> V_139 ; V_137 ++ ) {
for ( V_138 = V_136 -> V_140 [ V_137 ] . V_141 ; V_138 < V_136 -> V_140 [ V_137 ] . V_142 ; V_138 ++ )
F_90 ( V_135 , V_138 , V_103 ) ;
F_90 ( V_135 , V_136 -> V_140 [ V_137 ] . V_142 , V_103 ) ;
}
}
}
}
static void
F_96 ( const char * V_39 , T_18 V_103 , T_10 V_143 )
{
T_10 * V_144 ;
T_26 * V_145 ;
T_27 * V_146 , * V_147 ;
T_23 V_148 = F_87 ( V_39 ) ;
int V_149 = F_80 ( V_103 -> V_106 ) ;
V_144 = F_42 ( F_97 () , T_10 ) ;
* V_144 = V_143 ;
V_145 = F_98 ( F_99 ( V_149 ) ) ;
if ( V_145 == NULL )
{
V_145 = F_100 ( V_149 , NULL ) ;
}
V_146 = F_50 ( F_97 () , L_21 ,
V_148 -> V_150 , F_74 ( V_103 -> V_106 ) , * V_144 ) ;
V_147 = F_50 ( F_97 () , L_22 , F_74 ( V_103 -> V_106 ) ,
V_148 -> V_150 ) ;
F_101 ( V_145 , V_39 , V_147 , V_146 , V_144 ) ;
}
void F_102 ( const char * V_39 , const T_12 V_125 ,
T_18 V_103 )
{
F_96 ( V_39 , V_103 , V_125 ) ;
F_90 ( V_39 , V_125 , V_103 ) ;
}
void F_103 ( const char * V_135 , const char * V_151 ,
T_18 V_103 )
{
T_25 * * V_136 ;
T_26 * V_145 ;
T_27 * V_146 , * V_147 ;
T_23 V_148 = F_87 ( V_135 ) ;
int V_149 = F_80 ( V_103 -> V_106 ) ;
T_12 V_152 = 0 ;
V_136 = F_104 ( F_97 () , T_25 * ) ;
V_145 = F_98 ( F_99 ( V_149 ) ) ;
if ( V_145 == NULL ) {
V_145 = F_100 ( V_149 , NULL ) ;
}
if ( F_105 ( V_145 , V_135 ) == NULL ) {
V_146 = F_50 ( F_97 () , L_23 ,
F_74 ( V_103 -> V_106 ) , V_148 -> V_150 ) ;
V_147 = F_50 ( F_97 () , L_24 , V_148 -> V_150 ) ;
switch ( V_148 -> type ) {
case V_126 :
V_152 = 0xFF ;
break;
case V_127 :
V_152 = 0xFFFF ;
break;
case V_128 :
V_152 = 0xFFFFFF ;
break;
case V_129 :
V_152 = 0xFFFFFFFF ;
break;
default:
F_106 ( L_25 , V_135 , V_148 -> V_150 ) ;
F_60 () ;
}
F_107 ( F_97 () , V_136 , V_151 , V_152 ) ;
F_108 ( V_145 , V_135 , V_147 , V_146 , V_136 , V_152 ) ;
}
F_95 ( V_135 , * V_136 , V_103 ) ;
}
void
F_109 ( const char * V_39 , const T_12 V_125 ,
T_18 V_103 V_8 )
{
T_23 V_124 = F_87 ( V_39 ) ;
T_24 * V_130 ;
F_14 ( V_124 ) ;
V_130 = F_89 ( V_124 , V_125 ) ;
if ( V_130 != NULL ) {
F_110 ( V_124 -> V_15 ,
F_56 ( V_125 ) ) ;
}
}
void F_111 ( const char * V_135 , T_25 * V_136 ,
T_18 V_103 )
{
T_12 V_137 , V_138 ;
if ( V_136 ) {
for ( V_137 = 0 ; V_137 < V_136 -> V_139 ; V_137 ++ ) {
for ( V_138 = V_136 -> V_140 [ V_137 ] . V_141 ; V_138 < V_136 -> V_140 [ V_137 ] . V_142 ; V_138 ++ )
F_109 ( V_135 , V_138 , V_103 ) ;
F_109 ( V_135 , V_136 -> V_140 [ V_137 ] . V_142 , V_103 ) ;
}
}
}
static T_20
F_112 ( T_3 T_28 V_8 , T_3 V_153 , T_3 T_4 )
{
T_24 * V_130 = ( T_24 * ) V_153 ;
T_18 V_103 = ( T_18 ) T_4 ;
if ( ! V_130 -> V_132 -> V_106 ) {
return FALSE ;
}
return ( F_80 ( V_130 -> V_132 -> V_106 ) == F_80 ( V_103 -> V_106 ) ) ;
}
void F_113 ( const char * V_39 , T_18 V_103 )
{
T_23 V_124 = F_87 ( V_39 ) ;
F_14 ( V_124 ) ;
F_114 ( V_124 -> V_15 , F_112 , V_103 ) ;
}
static void
F_115 ( T_3 T_28 V_8 , T_3 V_153 , T_3 T_4 )
{
T_23 V_124 = ( T_23 ) V_153 ;
F_14 ( V_124 ) ;
F_114 ( V_124 -> V_15 , F_112 , T_4 ) ;
V_124 -> V_16 = F_116 ( V_124 -> V_16 , T_4 ) ;
}
static void
F_117 ( T_18 V_103 )
{
F_118 ( V_17 , F_115 , V_103 ) ;
}
void
F_119 ( const char * V_39 , const T_12 V_125 , T_18 V_103 )
{
T_23 V_124 = F_87 ( V_39 ) ;
T_24 * V_130 ;
F_14 ( V_124 ) ;
V_130 = F_89 ( V_124 , V_125 ) ;
if ( V_130 != NULL ) {
V_130 -> V_132 = V_103 ;
return;
}
if ( V_103 == NULL )
return;
V_130 = ( T_24 * ) F_92 ( sizeof ( T_24 ) ) ;
V_130 -> V_133 = NULL ;
V_130 -> V_132 = V_103 ;
F_93 ( V_124 -> V_15 ,
F_56 ( V_125 ) , ( T_3 ) V_130 ) ;
}
void
F_120 ( const char * V_39 , const T_12 V_125 )
{
T_23 V_124 = F_87 ( V_39 ) ;
T_24 * V_130 ;
F_14 ( V_124 ) ;
V_130 = F_89 ( V_124 , V_125 ) ;
if ( V_130 == NULL )
return;
if ( V_130 -> V_133 != NULL ) {
V_130 -> V_132 = V_130 -> V_133 ;
} else {
F_110 ( V_124 -> V_15 ,
F_56 ( V_125 ) ) ;
}
}
int
F_121 ( T_23 V_124 , const T_12 V_154 ,
T_9 * V_36 , T_11 * V_38 , T_19 * V_99 ,
const T_20 V_109 , void * V_1 )
{
T_24 * V_130 ;
struct V_155 * V_103 ;
T_12 V_156 ;
int V_105 ;
V_130 = F_89 ( V_124 , V_154 ) ;
if ( V_130 == NULL ) {
return 0 ;
}
V_103 = V_130 -> V_132 ;
if ( V_103 == NULL ) {
return 0 ;
}
V_156 = V_38 -> V_157 ;
V_38 -> V_157 = V_154 ;
V_105 = F_75 ( V_103 , V_36 , V_38 , V_99 , V_109 , V_1 ) ;
V_38 -> V_157 = V_156 ;
return V_105 ;
}
int
F_122 ( T_23 V_124 , const T_12 V_154 ,
T_9 * V_36 , T_11 * V_38 , T_19 * V_99 )
{
return F_121 ( V_124 , V_154 , V_36 , V_38 , V_99 , TRUE , NULL ) ;
}
T_18
F_123 ( T_23 const V_124 , const T_12 V_154 )
{
T_24 * V_130 ;
V_130 = F_89 ( V_124 , V_154 ) ;
if ( V_130 != NULL )
return V_130 -> V_132 ;
else
return NULL ;
}
T_18
F_124 ( const char * V_39 , const T_12 V_154 )
{
T_23 V_124 = F_87 ( V_39 ) ;
if ( V_124 != NULL ) {
T_24 * V_130 = F_89 ( V_124 , V_154 ) ;
if ( V_130 != NULL )
return V_130 -> V_133 ;
}
return NULL ;
}
static T_24 *
F_125 ( T_23 const V_124 , const T_27 * V_125 )
{
T_24 * V_158 ;
char * T_28 ;
switch ( V_124 -> type ) {
case V_159 :
case V_160 :
case V_161 :
break;
default:
F_60 () ;
}
if ( V_124 -> V_162 == TRUE ) {
T_28 = F_126 ( V_125 , - 1 ) ;
} else {
T_28 = F_127 ( V_125 ) ;
}
V_158 = ( T_24 * ) F_88 ( V_124 -> V_15 , T_28 ) ;
V_6 ( T_28 ) ;
return V_158 ;
}
void
F_128 ( const char * V_39 , const T_27 * V_125 ,
T_18 V_103 )
{
T_23 V_124 = F_87 ( V_39 ) ;
T_24 * V_130 ;
char * T_28 ;
if ( V_103 == NULL ) {
fprintf ( V_131 , L_17 ,
V_39 ) ;
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
if ( V_124 == NULL ) {
fprintf ( V_131 , L_19 ,
V_39 ) ;
fprintf ( V_131 , L_20 ,
F_91 ( V_103 -> V_106 ) ) ;
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
switch ( V_124 -> type ) {
case V_159 :
case V_160 :
case V_161 :
break;
default:
F_60 () ;
}
V_130 = ( T_24 * ) F_92 ( sizeof ( T_24 ) ) ;
V_130 -> V_132 = V_103 ;
V_130 -> V_133 = V_130 -> V_132 ;
if ( V_124 -> V_162 == TRUE ) {
T_28 = F_126 ( V_125 , - 1 ) ;
} else {
T_28 = F_127 ( V_125 ) ;
}
F_93 ( V_124 -> V_15 , ( T_3 ) T_28 ,
( T_3 ) V_130 ) ;
if ( V_124 -> V_134 )
F_94 ( V_39 , V_103 ) ;
}
void
F_129 ( const char * V_39 , const T_27 * V_125 ,
T_18 V_103 V_8 )
{
T_23 V_124 = F_87 ( V_39 ) ;
T_24 * V_130 ;
F_14 ( V_124 ) ;
V_130 = F_125 ( V_124 , V_125 ) ;
if ( V_130 != NULL ) {
F_110 ( V_124 -> V_15 , V_125 ) ;
}
}
void
F_130 ( const char * V_39 , const T_27 * V_125 ,
T_18 V_103 )
{
T_23 V_124 = F_87 ( V_39 ) ;
T_24 * V_130 ;
F_14 ( V_124 ) ;
V_130 = F_125 ( V_124 , V_125 ) ;
if ( V_130 != NULL ) {
V_130 -> V_132 = V_103 ;
return;
}
if ( V_103 == NULL )
return;
V_130 = ( T_24 * ) F_92 ( sizeof ( T_24 ) ) ;
V_130 -> V_133 = NULL ;
V_130 -> V_132 = V_103 ;
F_93 ( V_124 -> V_15 , ( T_3 ) F_127 ( V_125 ) ,
( T_3 ) V_130 ) ;
}
void
F_131 ( const char * V_39 , const T_27 * V_125 )
{
T_23 V_124 = F_87 ( V_39 ) ;
T_24 * V_130 ;
F_14 ( V_124 ) ;
V_130 = F_125 ( V_124 , V_125 ) ;
if ( V_130 == NULL )
return;
if ( V_130 -> V_133 != NULL ) {
V_130 -> V_132 = V_130 -> V_133 ;
} else {
F_110 ( V_124 -> V_15 , V_125 ) ;
}
}
int
F_132 ( T_23 V_124 , const T_27 * string ,
T_9 * V_36 , T_11 * V_38 , T_19 * V_99 , void * V_1 )
{
T_24 * V_130 ;
struct V_155 * V_103 ;
int V_105 ;
const T_27 * V_163 ;
if ( ! string ) return 0 ;
V_130 = F_125 ( V_124 , string ) ;
if ( V_130 != NULL ) {
V_103 = V_130 -> V_132 ;
if ( V_103 == NULL ) {
return 0 ;
}
V_163 = V_38 -> V_164 ;
V_38 -> V_164 = string ;
V_105 = F_75 ( V_103 , V_36 , V_38 , V_99 , TRUE , V_1 ) ;
V_38 -> V_164 = V_163 ;
return V_105 ;
}
return 0 ;
}
T_18
F_133 ( T_23 V_124 ,
const T_27 * string )
{
T_24 * V_130 ;
if ( ! string ) return NULL ;
V_130 = F_125 ( V_124 , string ) ;
if ( V_130 != NULL )
return V_130 -> V_132 ;
else
return NULL ;
}
T_18
F_134 ( const char * V_39 , const T_27 * string )
{
T_23 V_124 ;
if ( ! string ) return NULL ;
V_124 = F_87 ( V_39 ) ;
if ( V_124 != NULL ) {
T_24 * V_130 = F_125 ( V_124 , string ) ;
if ( V_130 != NULL )
return V_130 -> V_133 ;
}
return NULL ;
}
void F_135 ( const char * V_39 , void * V_125 , T_18 V_103 )
{
T_23 V_124 = F_87 ( V_39 ) ;
T_24 * V_130 ;
if ( V_124 == NULL ) {
fprintf ( V_131 , L_19 ,
V_39 ) ;
fprintf ( V_131 , L_20 ,
F_91 ( V_103 -> V_106 ) ) ;
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
F_14 ( V_124 -> type == V_165 ) ;
V_130 = ( T_24 * ) F_92 ( sizeof ( T_24 ) ) ;
V_130 -> V_132 = V_103 ;
V_130 -> V_133 = V_130 -> V_132 ;
F_93 ( V_124 -> V_15 , ( T_3 ) V_125 ,
( T_3 ) V_130 ) ;
if ( V_124 -> V_134 )
F_94 ( V_39 , V_103 ) ;
}
T_18 F_136 ( T_23 V_124 , void * T_28 )
{
T_24 * V_130 = ( T_24 * ) F_88 ( V_124 -> V_15 , T_28 ) ;
if ( V_130 != NULL )
return V_130 -> V_132 ;
return NULL ;
}
void F_137 ( const char * V_39 , T_29 * V_166 , T_18 V_103 )
{
T_23 V_124 ;
T_24 * V_130 ;
V_124 = F_87 ( V_39 ) ;
if ( V_103 == NULL ) {
fprintf ( V_131 , L_17 ,
V_39 ) ;
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
if ( V_124 == NULL ) {
fprintf ( V_131 , L_19 ,
V_39 ) ;
fprintf ( V_131 , L_20 ,
F_91 ( V_103 -> V_106 ) ) ;
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
if ( V_124 -> type != V_167 ) {
F_60 () ;
}
V_130 = ( T_24 * ) F_92 ( sizeof ( T_24 ) ) ;
V_130 -> V_132 = V_103 ;
V_130 -> V_133 = V_130 -> V_132 ;
F_93 ( V_124 -> V_15 ,
V_166 , ( T_3 ) V_130 ) ;
if ( V_124 -> V_134 )
F_94 ( V_39 , V_103 ) ;
}
int F_138 ( T_23 V_124 ,
T_29 * V_166 , T_9 * V_36 , T_11 * V_38 , T_19 * V_99 , const T_20 V_109 , void * V_1 )
{
T_24 * V_130 ;
struct V_155 * V_103 ;
int V_105 ;
V_130 = ( T_24 * ) F_88 ( V_124 -> V_15 , V_166 ) ;
if ( V_130 != NULL ) {
V_103 = V_130 -> V_132 ;
if ( V_103 == NULL ) {
return 0 ;
}
V_105 = F_75 ( V_103 , V_36 , V_38 , V_99 , V_109 , V_1 ) ;
return V_105 ;
}
return 0 ;
}
int F_139 ( T_23 V_124 ,
T_29 * V_166 , T_9 * V_36 , T_11 * V_38 , T_19 * V_99 )
{
return F_138 ( V_124 , V_166 , V_36 , V_38 , V_99 , TRUE , NULL ) ;
}
T_18 F_140 (
T_23 const V_124 , T_29 * V_166 )
{
T_24 * V_130 ;
V_130 = ( T_24 * ) F_88 ( V_124 -> V_15 , V_166 ) ;
if ( V_130 != NULL )
return V_130 -> V_132 ;
else
return NULL ;
}
T_18
F_141 ( T_24 * V_130 )
{
return V_130 -> V_132 ;
}
static T_30
F_142 ( T_31 V_168 , T_31 V_169 )
{
const struct V_155 * V_170 = ( const struct V_155 * ) V_168 ;
const struct V_155 * V_171 = ( const struct V_155 * ) V_169 ;
const char * V_172 , * V_173 ;
T_30 V_158 ;
if ( V_170 -> V_106 == NULL )
V_172 = L_6 ;
else
V_172 = F_99 ( F_80 ( V_170 -> V_106 ) ) ;
if ( V_171 -> V_106 == NULL )
V_173 = L_6 ;
else
V_173 = F_99 ( F_80 ( V_171 -> V_106 ) ) ;
V_158 = strcmp ( V_172 , V_173 ) ;
return V_158 ;
}
void
F_94 ( const char * V_39 , T_18 V_103 )
{
T_23 V_124 = F_87 ( V_39 ) ;
T_2 * V_174 ;
T_18 V_175 ;
if ( V_124 == NULL ) {
fprintf ( V_131 , L_19 ,
V_39 ) ;
fprintf ( V_131 , L_20 ,
F_91 ( V_103 -> V_106 ) ) ;
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
if ( ! V_124 -> V_134 ) {
const char * V_176 ;
V_176 = F_143 ( V_103 ) ;
if ( V_176 == NULL )
V_176 = L_26 ;
fprintf ( V_131 , L_27 ,
V_176 ,
F_74 ( V_103 -> V_106 ) ,
V_39 ) ;
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
if ( V_124 -> V_106 != NULL )
F_144 ( F_74 ( V_124 -> V_106 ) , F_74 ( V_103 -> V_106 ) ) ;
V_174 = F_145 ( V_124 -> V_16 , ( T_3 ) V_103 ) ;
if ( V_174 != NULL ) {
return;
}
if ( V_124 -> type != V_159 )
{
for ( V_174 = V_124 -> V_16 ; V_174 != NULL ; V_174 = F_146 ( V_174 ) )
{
V_175 = ( T_18 ) V_174 -> V_1 ;
if ( V_175 -> V_106 == V_103 -> V_106 )
{
const char * V_176 , * V_177 ;
V_176 = F_143 ( V_103 ) ;
if ( V_176 == NULL )
V_176 = L_26 ;
V_177 = F_143 ( V_175 ) ;
if ( V_177 == NULL )
V_177 = L_26 ;
fprintf ( V_131 , L_28 ,
V_176 , V_177 ,
F_74 ( V_103 -> V_106 ) ,
V_39 ) ;
if ( getenv ( L_18 ) != NULL )
abort () ;
}
}
}
V_124 -> V_16 =
F_147 ( V_124 -> V_16 , ( T_3 ) V_103 , ( V_178 ) F_142 ) ;
}
void F_148 ( const char * V_39 ,
T_18 V_103 )
{
F_96 ( V_39 , V_103 , 0 ) ;
F_94 ( V_39 , V_103 ) ;
}
T_18
F_149 ( T_24 * V_130 )
{
return V_130 -> V_133 ;
}
T_2 *
F_150 ( T_23 V_13 ) {
if ( ! V_13 )
return NULL ;
return V_13 -> V_16 ;
}
static void
F_151 ( T_3 V_179 , T_3 T_4 )
{
T_18 V_103 = ( T_18 ) V_179 ;
T_32 * V_180 = ( T_32 * ) T_4 ;
const T_27 * V_181 = F_152 ( V_103 ) ;
if ( V_181 && strcmp ( V_180 -> V_182 , V_181 ) == 0 ) {
V_180 -> V_103 = V_103 ;
}
}
T_18 F_153 ( T_23 V_13 , T_27 * V_11 )
{
T_32 V_180 ;
V_180 . V_182 = V_11 ;
V_180 . V_103 = NULL ;
F_2 ( V_13 -> V_16 , F_151 , & V_180 ) ;
return V_180 . V_103 ;
}
T_33
F_154 ( T_23 V_13 ) {
if ( ! V_13 ) return V_183 ;
return V_13 -> type ;
}
void
F_155 ( T_23 V_13 )
{
V_13 -> V_134 = TRUE ;
}
static T_30
F_156 ( T_31 V_184 , T_31 V_185 )
{
const T_29 * V_186 = ( const T_29 * ) V_184 ;
const T_29 * V_187 = ( const T_29 * ) V_185 ;
return ( ( memcmp ( & V_186 -> V_188 , & V_187 -> V_188 , sizeof ( V_189 ) ) == 0 )
&& ( V_186 -> V_190 == V_187 -> V_190 ) ) ;
}
static T_10
F_157 ( T_31 V_191 )
{
const T_29 * T_28 = ( const T_29 * ) V_191 ;
return T_28 -> V_188 . V_192 ;
}
static void
F_158 ( T_3 T_28 , T_3 V_153 , T_3 T_4 )
{
T_34 * V_193 ;
T_24 * V_130 ;
F_14 ( V_153 ) ;
F_14 ( T_4 ) ;
V_130 = ( T_24 * ) V_153 ;
if ( V_130 -> V_132 == NULL ||
V_130 -> V_132 -> V_106 == NULL ) {
return;
}
V_193 = ( T_34 * ) T_4 ;
V_193 -> V_194 ( V_193 -> V_195 , V_193 -> V_196 , T_28 , V_153 ,
V_193 -> V_197 ) ;
}
static void
F_159 ( T_3 T_28 , T_3 V_153 , T_3 T_4 )
{
T_23 V_124 ;
T_34 * V_193 ;
F_14 ( V_153 ) ;
F_14 ( T_4 ) ;
V_124 = ( T_23 ) V_153 ;
V_193 = ( T_34 * ) T_4 ;
V_193 -> V_195 = ( T_27 * ) T_28 ;
V_193 -> V_196 = F_160 ( V_193 -> V_195 ) ;
F_118 ( V_124 -> V_15 , V_193 -> V_198 , V_193 ) ;
}
static void
F_161 ( T_35 V_30 ,
T_3 T_4 )
{
T_34 V_193 ;
V_193 . V_197 = T_4 ;
V_193 . V_194 = V_30 ;
V_193 . V_198 = F_158 ;
F_118 ( V_17 , F_159 , & V_193 ) ;
}
void
F_162 ( const char * V_195 ,
T_35 V_30 ,
T_3 T_4 )
{
T_34 V_193 ;
T_23 V_124 = F_87 ( V_195 ) ;
V_193 . V_195 = V_195 ;
V_193 . V_196 = V_124 -> type ;
V_193 . V_194 = V_30 ;
V_193 . V_197 = T_4 ;
F_118 ( V_124 -> V_15 , F_158 , & V_193 ) ;
}
void
F_163 ( const char * V_195 ,
T_36 V_30 ,
T_3 T_4 )
{
T_23 V_124 = F_87 ( V_195 ) ;
T_2 * V_199 ;
for ( V_199 = V_124 -> V_16 ; V_199 != NULL ;
V_199 = F_146 ( V_199 ) )
V_30 ( V_195 , V_199 -> V_1 , T_4 ) ;
}
static void
F_164 ( T_3 T_28 , T_3 V_153 , T_3 T_4 )
{
T_24 * V_130 ;
T_34 * V_193 ;
F_14 ( V_153 ) ;
F_14 ( T_4 ) ;
V_130 = ( T_24 * ) V_153 ;
if ( V_130 -> V_133 == V_130 -> V_132 ) {
return;
}
V_193 = ( T_34 * ) T_4 ;
V_193 -> V_194 ( V_193 -> V_195 , V_193 -> V_196 , T_28 , V_153 ,
V_193 -> V_197 ) ;
}
void
F_165 ( T_35 V_30 ,
T_3 T_4 )
{
T_34 V_193 ;
V_193 . V_197 = T_4 ;
V_193 . V_194 = V_30 ;
V_193 . V_198 = F_164 ;
F_118 ( V_17 , F_159 , & V_193 ) ;
}
void
F_166 ( const char * V_195 ,
T_35 V_30 ,
T_3 T_4 )
{
T_34 V_193 ;
T_23 V_124 = F_87 ( V_195 ) ;
V_193 . V_195 = V_195 ;
V_193 . V_196 = V_124 -> type ;
V_193 . V_194 = V_30 ;
V_193 . V_197 = T_4 ;
F_118 ( V_124 -> V_15 ,
F_164 , & V_193 ) ;
}
static void
F_167 ( T_3 T_28 , T_3 V_153 , T_3 T_4 )
{
T_23 V_14 ;
T_37 * V_193 ;
V_14 = ( T_23 ) V_153 ;
V_193 = ( T_37 * ) T_4 ;
(* V_193 -> V_194 )( ( T_27 * ) T_28 , V_14 -> V_150 , V_193 -> V_197 ) ;
}
static void
F_168 ( T_3 T_28 , T_3 T_4 )
{
T_23 V_14 ;
T_37 * V_193 ;
V_14 = ( T_23 ) F_88 ( V_17 , T_28 ) ;
V_193 = ( T_37 * ) T_4 ;
(* V_193 -> V_194 )( ( T_27 * ) T_28 , V_14 -> V_150 , V_193 -> V_197 ) ;
}
void
F_169 ( T_38 V_30 ,
T_3 T_4 ,
V_178 V_200 )
{
T_37 V_193 ;
T_39 * V_3 ;
V_193 . V_197 = T_4 ;
V_193 . V_194 = V_30 ;
if ( V_200 != NULL )
{
V_3 = F_170 ( V_17 ) ;
V_3 = F_171 ( V_3 , V_200 ) ;
F_172 ( V_3 , F_168 , & V_193 ) ;
F_173 ( V_3 ) ;
}
else
{
F_118 ( V_17 , F_167 , & V_193 ) ;
}
}
T_23
F_174 ( const char * V_39 , const char * V_150 , const int V_201 , const T_33 type ,
const int V_162 )
{
T_23 V_124 ;
if( F_88 ( V_17 , V_39 ) ) {
F_106 ( L_29 , V_39 , V_150 ) ;
}
V_124 = F_175 ( struct V_13 ) ;
switch ( type ) {
case V_126 :
case V_127 :
case V_128 :
case V_129 :
V_124 -> V_202 = V_203 ;
V_124 -> V_15 = F_10 ( V_203 ,
V_204 ,
NULL ,
& V_6 ) ;
break;
case V_159 :
case V_160 :
case V_161 :
V_124 -> V_202 = V_18 ;
V_124 -> V_15 = F_10 ( V_18 ,
V_19 ,
& V_6 ,
& V_6 ) ;
break;
case V_167 :
V_124 -> V_15 = F_10 ( F_157 ,
F_156 ,
NULL ,
& V_6 ) ;
break;
default:
F_106 ( L_30 , V_39 , V_150 ) ;
F_60 () ;
}
V_124 -> V_16 = NULL ;
V_124 -> V_150 = V_150 ;
V_124 -> type = type ;
V_124 -> V_162 = V_162 ;
V_124 -> V_106 = F_176 ( V_201 ) ;
V_124 -> V_134 = FALSE ;
F_93 ( V_17 , ( T_3 ) V_39 , ( T_3 ) V_124 ) ;
return V_124 ;
}
T_23 F_177 ( const char * V_39 ,
const char * V_150 , const int V_201 , T_40 V_202 , T_41 V_205 )
{
T_23 V_124 ;
if( F_88 ( V_17 , V_39 ) ) {
F_106 ( L_29 , V_39 , V_150 ) ;
}
V_124 = F_175 ( struct V_13 ) ;
V_124 -> V_202 = V_202 ;
V_124 -> V_15 = F_10 ( V_202 ,
V_205 ,
& V_6 ,
& V_6 ) ;
V_124 -> V_16 = NULL ;
V_124 -> V_150 = V_150 ;
V_124 -> type = V_165 ;
V_124 -> V_162 = V_206 ;
V_124 -> V_106 = F_176 ( V_201 ) ;
V_124 -> V_134 = FALSE ;
F_93 ( V_17 , ( T_3 ) V_39 , ( T_3 ) V_124 ) ;
return V_124 ;
}
void
F_178 ( const char * V_39 )
{
T_23 V_124 = F_87 ( V_39 ) ;
if ( ! V_124 ) return;
F_110 ( V_17 , V_39 ) ;
}
const char *
F_179 ( const char * V_39 )
{
T_23 V_124 = F_87 ( V_39 ) ;
if ( ! V_124 ) return NULL ;
return V_124 -> V_150 ;
}
T_33
F_160 ( const char * V_39 )
{
T_23 V_124 = F_87 ( V_39 ) ;
if ( ! V_124 ) return V_183 ;
return V_124 -> type ;
}
int
F_180 ( const char * V_39 )
{
T_23 V_124 = F_87 ( V_39 ) ;
if ( ! V_124 ) return 0 ;
return V_124 -> V_162 ;
}
T_6
F_181 ( const char * V_39 )
{
return ( T_6 ) F_88 ( V_22 , V_39 ) ;
}
T_20
F_182 ( const T_27 * V_39 ) {
return ( F_181 ( V_39 ) != NULL ) ;
}
T_5 * F_183 ( const char * V_11 )
{
return ( T_5 * ) F_88 ( V_23 , V_11 ) ;
}
void
F_184 ( const char * V_39 , T_42 V_107 , const char * V_207 , const char * V_11 , const int V_201 , T_43 V_208 )
{
T_6 V_124 = F_181 ( V_39 ) ;
const char * V_209 ;
T_5 * V_9 ;
T_10 V_137 , V_210 ;
T_2 * V_211 ;
if ( V_124 == NULL ) {
fprintf ( V_131 , L_19 ,
V_39 ) ;
V_209 = F_185 ( V_201 ) ;
if ( V_209 != NULL ) {
fprintf ( V_131 , L_20 ,
V_209 ) ;
}
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
V_210 = F_186 ( V_124 -> V_4 ) ;
for ( V_137 = 0 ; V_137 < V_210 ; V_137 ++ )
{
V_211 = F_187 ( V_124 -> V_4 , V_137 ) ;
V_9 = ( T_5 * ) V_211 -> V_1 ;
if ( ( V_9 -> V_107 == V_107 ) &&
( V_9 -> V_106 == F_176 ( V_201 ) ) )
{
V_209 = F_185 ( V_201 ) ;
if ( V_209 != NULL ) {
fprintf ( V_131 , L_31 ,
V_209 , V_39 ) ;
}
if ( getenv ( L_18 ) != NULL )
abort () ;
return;
}
}
if ( F_88 ( V_23 , V_11 ) != NULL ) {
F_106 ( L_32
L_33 , V_11 ) ;
}
V_9 = F_175 ( T_5 ) ;
V_9 -> V_107 = V_107 ;
V_9 -> V_106 = F_176 ( V_201 ) ;
V_9 -> V_207 = V_207 ;
V_9 -> V_11 = F_127 ( V_11 ) ;
V_9 -> V_10 = F_127 ( V_39 ) ;
V_9 -> V_212 = ( V_208 == V_213 ) ;
F_93 ( V_23 , ( T_3 ) V_9 -> V_11 , V_9 ) ;
V_124 -> V_4 = F_23 ( V_124 -> V_4 ,
( T_3 ) V_9 ) ;
F_188 ( V_9 -> V_106 , V_9 -> V_11 ) ;
if ( V_124 -> V_106 != NULL )
F_144 ( F_74 ( V_124 -> V_106 ) , F_74 ( V_9 -> V_106 ) ) ;
}
static int
F_189 ( T_31 V_170 , T_31 V_171 ) {
const T_5 * V_214 = ( const T_5 * ) V_170 ;
const T_5 * V_215 = ( const T_5 * ) V_171 ;
return ( V_214 -> V_107 == V_215 -> V_107 ) &&
( V_214 -> V_106 == V_215 -> V_106 ) ? 0 : 1 ;
}
void
F_190 ( const char * V_39 , T_42 V_107 , const int V_201 ) {
T_6 V_124 = F_181 ( V_39 ) ;
T_5 V_9 ;
T_2 * V_216 ;
F_14 ( V_124 != NULL ) ;
V_9 . V_107 = V_107 ;
V_9 . V_106 = F_176 ( V_201 ) ;
V_216 = F_191 ( V_124 -> V_4 ,
( T_3 ) & V_9 , F_189 ) ;
if ( V_216 ) {
T_5 * V_217 = ( T_5 * ) ( V_216 -> V_1 ) ;
V_6 ( V_217 -> V_10 ) ;
F_110 ( V_23 , V_217 -> V_11 ) ;
V_6 ( V_217 -> V_11 ) ;
F_4 ( T_5 , V_216 -> V_1 ) ;
V_124 -> V_4 = F_47 ( V_124 -> V_4 ,
V_216 ) ;
}
}
T_20
F_192 ( T_6 V_124 , T_9 * V_36 ,
T_11 * V_38 , T_19 * V_99 , T_5 * * V_218 , void * V_1 )
{
T_20 V_219 ;
const char * V_220 ;
const char * V_221 ;
T_2 * V_174 ;
T_21 V_110 ;
T_10 V_111 = 0 ;
T_5 * V_9 ;
int V_149 ;
V_110 = V_38 -> V_112 ;
V_38 -> V_110 = V_110 ;
V_38 -> V_112 = V_110 - ( V_110 > 0 ) ;
V_219 = FALSE ;
V_220 = V_38 -> V_69 ;
V_221 = V_38 -> V_222 ;
V_111 = F_77 ( V_38 -> V_91 ) ;
* V_218 = NULL ;
for ( V_174 = V_124 -> V_4 ; V_174 != NULL ;
V_174 = F_146 ( V_174 ) ) {
V_38 -> V_112 = V_110 - ( V_110 > 0 ) ;
V_9 = ( T_5 * ) V_174 -> V_1 ;
if ( V_9 -> V_106 != NULL &&
( ! F_76 ( V_9 -> V_106 ) || ( V_9 -> V_212 == FALSE ) ) ) {
continue;
}
if ( V_9 -> V_106 != NULL ) {
V_149 = F_80 ( V_9 -> V_106 ) ;
V_38 -> V_69 =
F_74 ( V_9 -> V_106 ) ;
F_78 ( V_38 -> V_91 , F_79 ( V_149 ) ) ;
}
V_38 -> V_222 = V_9 -> V_10 ;
if ( ( V_9 -> V_107 ) ( V_36 , V_38 , V_99 , V_1 ) ) {
* V_218 = V_9 ;
V_219 = TRUE ;
break;
} else {
while ( F_77 ( V_38 -> V_91 ) > V_111 ) {
F_82 ( V_38 -> V_91 , F_83 ( V_38 -> V_91 ) ) ;
}
}
}
V_38 -> V_69 = V_220 ;
V_38 -> V_222 = V_221 ;
V_38 -> V_112 = V_110 ;
return V_219 ;
}
static void
F_193 ( T_3 V_1 , T_3 T_4 )
{
T_44 * V_193 ;
F_14 ( V_1 ) ;
F_14 ( T_4 ) ;
V_193 = ( T_44 * ) T_4 ;
V_193 -> V_194 ( V_193 -> V_195 , ( T_5 * ) V_1 ,
V_193 -> V_197 ) ;
}
void
F_194 ( const char * V_195 ,
T_45 V_30 ,
T_3 T_4 )
{
T_44 V_193 ;
T_6 V_124 = F_181 ( V_195 ) ;
V_193 . V_195 = V_195 ;
V_193 . V_194 = V_30 ;
V_193 . V_197 = T_4 ;
F_2 ( V_124 -> V_4 ,
F_193 , & V_193 ) ;
}
static void
F_195 ( T_3 T_28 , T_3 V_153 , T_3 T_4 )
{
T_46 * V_193 ;
V_193 = ( T_46 * ) T_4 ;
(* V_193 -> V_194 )( ( T_27 * ) T_28 , (struct V_12 * ) V_153 , V_193 -> V_197 ) ;
}
static void
F_196 ( T_3 T_28 , T_3 T_4 )
{
struct V_12 * V_3 ;
T_46 * V_193 ;
V_3 = (struct V_12 * ) F_88 ( V_22 , T_28 ) ;
V_193 = ( T_46 * ) T_4 ;
(* V_193 -> V_194 )( ( T_27 * ) T_28 , V_3 , V_193 -> V_197 ) ;
}
void
F_197 ( T_47 V_30 ,
T_3 T_4 ,
V_178 V_200 )
{
T_46 V_193 ;
T_39 * V_3 ;
V_193 . V_197 = T_4 ;
V_193 . V_194 = V_30 ;
if ( V_200 != NULL )
{
V_3 = F_170 ( V_17 ) ;
V_3 = F_171 ( V_3 , V_200 ) ;
F_172 ( V_3 , F_196 , & V_193 ) ;
F_173 ( V_3 ) ;
}
else
{
F_118 ( V_22 , F_195 , & V_193 ) ;
}
}
static void
F_198 ( const char * V_195 ,
T_5 * V_9 , T_3 T_4 V_8 )
{
if ( V_9 -> V_106 != NULL ) {
F_199 ( L_34 ,
V_195 ,
F_99 ( F_80 ( V_9 -> V_106 ) ) ,
( F_76 ( V_9 -> V_106 ) && V_9 -> V_212 ) ? 'T' : 'F' ) ;
}
}
static void
F_200 ( const T_27 * V_195 , struct V_12 * T_48 V_8 , T_3 T_4 V_8 )
{
F_194 ( V_195 , F_198 , NULL ) ;
}
void
F_201 ( void )
{
F_197 ( F_200 , NULL , NULL ) ;
}
T_6
F_202 ( const char * V_39 , const int V_201 )
{
T_6 V_124 ;
if ( F_88 ( V_22 , V_39 ) != NULL ) {
F_106 ( L_35 , V_39 ) ;
}
V_124 = F_175 ( struct V_12 ) ;
V_124 -> V_106 = F_176 ( V_201 ) ;
V_124 -> V_4 = NULL ;
F_93 ( V_22 , ( T_3 ) V_39 ,
( T_3 ) V_124 ) ;
return V_124 ;
}
const char *
F_203 ( const T_18 V_103 )
{
if ( V_103 == NULL || V_103 -> V_106 == NULL ) {
return NULL ;
}
return F_91 ( V_103 -> V_106 ) ;
}
const char *
F_152 ( const T_18 V_103 )
{
if ( V_103 -> V_106 == NULL ) {
return NULL ;
}
return F_74 ( V_103 -> V_106 ) ;
}
int
F_204 ( const T_18 V_103 )
{
if ( V_103 -> V_106 == NULL ) {
return - 1 ;
}
return F_80 ( V_103 -> V_106 ) ;
}
T_39 *
F_205 ( void )
{
return F_170 ( V_20 ) ;
}
T_18
F_13 ( const char * V_39 )
{
return ( T_18 ) F_88 ( V_20 , V_39 ) ;
}
T_18 F_206 ( const char * V_39 , const int V_223 )
{
T_18 V_103 = ( T_18 ) F_88 ( V_20 , V_39 ) ;
if ( ( V_103 != NULL ) && ( V_223 > 0 ) )
{
F_144 ( F_74 ( F_176 ( V_223 ) ) , F_152 ( V_103 ) ) ;
}
return V_103 ;
}
const char *
F_143 ( const T_18 V_103 )
{
if ( V_103 == NULL ) {
return NULL ;
}
return V_103 -> V_39 ;
}
static T_18
F_207 ( T_49 V_107 , int V_201 , const char * V_39 )
{
struct V_155 * V_103 ;
V_103 = F_42 ( F_97 () , struct V_155 ) ;
V_103 -> V_39 = V_39 ;
V_103 -> V_107 = V_107 ;
V_103 -> V_106 = F_176 ( V_201 ) ;
return V_103 ;
}
T_18
F_208 ( T_49 V_107 , const int V_201 )
{
return F_207 ( V_107 , V_201 , NULL ) ;
}
T_18
F_209 ( T_49 V_107 ,
const int V_201 , const char * V_39 )
{
return F_207 ( V_107 , V_201 , V_39 ) ;
}
static void
F_210 ( T_18 V_103 )
{
if ( V_103 == NULL ) return;
F_117 ( V_103 ) ;
F_211 ( V_103 ) ;
F_212 ( F_97 () , V_103 ) ;
}
static T_18
F_213 ( const char * V_39 , T_18 V_103 )
{
F_14 ( F_88 ( V_20 , V_39 ) == NULL ) ;
F_93 ( V_20 , ( T_3 ) V_39 , V_103 ) ;
return V_103 ;
}
T_18
F_214 ( const char * V_39 , T_49 V_107 , const int V_201 )
{
struct V_155 * V_103 ;
V_103 = F_207 ( V_107 , V_201 , V_39 ) ;
return F_213 ( V_39 , V_103 ) ;
}
static T_20
F_215 ( T_1 V_124 , const char * V_224 )
{
T_2 * V_216 ;
V_216 = F_191 ( V_124 -> V_4 ,
V_224 , ( V_178 ) strcmp ) ;
if ( V_216 ) {
V_6 ( V_216 -> V_1 ) ;
V_124 -> V_4 = F_47 ( V_124 -> V_4 , V_216 ) ;
return TRUE ;
}
return FALSE ;
}
static void
F_216 ( T_3 T_28 V_8 , T_3 V_153 , T_3 T_4 )
{
T_1 V_124 = ( T_1 ) V_153 ;
const char * V_224 = ( const char * ) T_4 ;
F_215 ( V_124 , V_224 ) ;
}
void
F_217 ( const char * V_39 )
{
T_18 V_103 = F_13 ( V_39 ) ;
if ( V_103 == NULL ) return;
F_110 ( V_20 , V_39 ) ;
F_110 ( V_21 , V_39 ) ;
F_118 ( V_21 , F_216 , ( T_3 ) V_39 ) ;
F_110 ( V_22 , V_39 ) ;
F_210 ( V_103 ) ;
}
int
F_218 ( T_18 V_103 , T_9 * V_36 ,
T_11 * V_38 , T_19 * V_99 , void * V_1 )
{
int V_158 ;
F_14 ( V_103 != NULL ) ;
V_158 = F_75 ( V_103 , V_36 , V_38 , V_99 , TRUE , V_1 ) ;
return V_158 ;
}
int
F_67 ( T_18 V_103 , T_9 * V_36 ,
T_11 * V_38 , T_19 * V_99 , void * V_1 )
{
int V_158 ;
V_158 = F_218 ( V_103 , V_36 , V_38 , V_99 , V_1 ) ;
if ( V_158 == 0 ) {
F_14 ( V_27 -> V_106 != NULL ) ;
F_75 ( V_27 , V_36 , V_38 , V_99 , TRUE , NULL ) ;
return F_49 ( V_36 ) ;
}
return V_158 ;
}
int
F_219 ( T_18 V_103 , T_9 * V_36 ,
T_11 * V_38 , T_19 * V_99 )
{
return F_67 ( V_103 , V_36 , V_38 , V_99 , NULL ) ;
}
int
F_220 ( T_9 * V_36 , T_11 * V_38 , T_19 * V_99 )
{
return F_75 ( V_27 , V_36 , V_38 , V_99 , TRUE , NULL ) ;
}
void F_221 ( T_5 * V_218 , T_9 * V_36 ,
T_11 * V_38 , T_19 * V_99 , void * V_1 )
{
const char * V_220 ;
const char * V_221 ;
T_21 V_110 ;
F_14 ( V_218 ) ;
V_110 = V_38 -> V_112 ;
V_38 -> V_110 = V_110 ;
V_38 -> V_112 = V_110 - ( V_110 > 0 ) ;
V_220 = V_38 -> V_69 ;
V_221 = V_38 -> V_222 ;
if ( ! V_218 -> V_212 ||
( V_218 -> V_106 != NULL && ! F_76 ( V_218 -> V_106 ) ) ) {
F_14 ( V_27 -> V_106 != NULL ) ;
F_75 ( V_27 , V_36 , V_38 , V_99 , TRUE , NULL ) ;
return;
}
if ( V_218 -> V_106 != NULL ) {
V_38 -> V_69 = F_74 ( V_218 -> V_106 ) ;
F_78 ( V_38 -> V_91 , F_79 ( F_80 ( V_218 -> V_106 ) ) ) ;
}
V_38 -> V_222 = V_218 -> V_10 ;
if( ! (* V_218 -> V_107 )( V_36 , V_38 , V_99 , V_1 ) )
F_75 ( V_27 , V_36 , V_38 , V_99 , TRUE , NULL ) ;
V_38 -> V_112 = V_110 ;
V_38 -> V_69 = V_220 ;
V_38 -> V_222 = V_221 ;
}
static T_30
F_222 ( T_31 V_225 , T_31 V_226 )
{
const char * V_227 = ( const char * ) V_225 ;
const T_27 * V_39 = ( const T_27 * ) V_226 ;
return strcmp ( V_227 , V_39 ) ;
}
T_20 F_144 ( const char * V_228 , const char * V_224 )
{
T_2 * V_211 ;
T_1 V_124 ;
if ( ( V_228 == NULL ) || ( V_224 == NULL ) )
{
return FALSE ;
}
V_124 = F_223 ( V_228 ) ;
if ( V_124 == NULL ) {
V_124 = F_175 ( struct V_7 ) ;
V_124 -> V_4 = NULL ;
F_93 ( V_21 , ( T_3 ) F_127 ( V_228 ) , ( T_3 ) V_124 ) ;
}
V_211 = F_191 ( V_124 -> V_4 , ( T_3 ) V_224 , F_222 ) ;
if ( V_211 != NULL )
return TRUE ;
V_124 -> V_4 = F_23 ( V_124 -> V_4 , ( T_3 ) F_127 ( V_224 ) ) ;
return TRUE ;
}
T_20 F_224 ( const char * V_228 , const char * V_224 )
{
T_1 V_124 = F_223 ( V_228 ) ;
F_14 ( V_124 != NULL ) ;
return F_215 ( V_124 , V_224 ) ;
}
T_1 F_223 ( const char * V_39 )
{
return ( T_1 ) F_88 ( V_21 , V_39 ) ;
}
static void
F_225 ( const T_27 * V_195 ,
T_33 V_196 V_8 , T_3 T_28 , T_3 V_153 ,
T_3 T_4 V_8 )
{
T_12 V_229 = F_226 ( T_28 ) ;
T_23 V_124 = F_87 ( V_195 ) ;
T_24 * V_130 ;
T_18 V_103 ;
T_30 V_149 ;
const T_27 * V_230 ;
F_14 ( V_124 ) ;
switch ( V_124 -> type ) {
case V_126 :
case V_127 :
case V_128 :
case V_129 :
V_130 = ( T_24 * ) V_153 ;
F_14 ( V_130 ) ;
V_103 = V_130 -> V_132 ;
F_14 ( V_103 ) ;
V_149 = F_204 ( V_103 ) ;
if ( V_149 != - 1 ) {
V_230 = F_99 ( V_149 ) ;
F_14 ( V_230 != NULL ) ;
F_199 ( L_36 , V_195 , V_229 , V_230 ) ;
}
break;
default:
break;
}
}
void
F_227 ( void )
{
F_161 ( F_225 , NULL ) ;
}
static void
F_228 ( T_3 T_28 , T_3 T_4 V_8 )
{
const char * V_195 = ( const char * ) T_28 ;
T_23 V_14 ;
V_14 = ( T_23 ) F_88 ( V_17 , T_28 ) ;
F_199 ( L_37 , V_195 , V_14 -> V_150 , F_229 ( V_14 -> type ) ) ;
switch ( V_14 -> type ) {
case V_126 :
case V_127 :
case V_128 :
case V_129 :
switch( V_14 -> V_162 ) {
case V_206 :
F_199 ( L_38 ) ;
break;
case V_231 :
F_199 ( L_39 ) ;
break;
case V_232 :
F_199 ( L_40 ) ;
break;
case V_233 :
F_199 ( L_41 ) ;
break;
case V_234 :
F_199 ( L_42 ) ;
break;
default:
F_199 ( L_43 , V_14 -> V_162 ) ;
break;
}
break;
default:
break;
}
F_199 ( L_44 ) ;
}
static T_30
F_230 ( T_31 V_168 , T_31 V_169 )
{
return strcmp ( ( const char * ) V_168 , ( const char * ) V_169 ) ;
}
void
F_231 ( void )
{
T_39 * V_3 ;
V_3 = F_170 ( V_17 ) ;
V_3 = F_171 ( V_3 , F_230 ) ;
F_172 ( V_3 , F_228 , NULL ) ;
F_173 ( V_3 ) ;
}
void
F_232 ( T_18 V_103 )
{
T_50 V_235 ;
if ( ! V_35 )
V_35 = F_233 ( FALSE , FALSE , ( T_10 ) sizeof( T_50 ) , 1 ) ;
V_235 . V_103 = V_103 ;
V_235 . V_236 = NULL ;
V_35 = F_234 ( V_35 , V_235 ) ;
}
void
F_235 ( T_18 V_103 , T_51 * V_236 )
{
T_10 V_137 ;
if ( ! V_35 ) return;
for ( V_137 = 0 ; V_137 < V_35 -> V_105 ; V_137 ++ ) {
if ( F_236 ( V_137 ) . V_103 == V_103 ) {
F_236 ( V_137 ) . V_236 = V_236 ;
break;
}
}
}
void
F_211 ( T_18 V_103 )
{
T_10 V_137 ;
if ( ! V_35 ) return;
for ( V_137 = 0 ; V_137 < V_35 -> V_105 ; V_137 ++ ) {
if ( F_236 ( V_137 ) . V_103 == V_103 ) {
V_35 = F_237 ( V_35 , V_137 ) ;
break;
}
}
}
T_20
F_238 ( void )
{
T_10 V_137 ;
T_18 V_103 ;
for ( V_137 = 0 ; V_137 < V_35 -> V_105 ; V_137 ++ ) {
V_103 = F_236 ( V_137 ) . V_103 ;
if ( V_103 -> V_106 != NULL
&& F_76 ( V_103 -> V_106 ) ) {
return TRUE ;
}
}
return FALSE ;
}
void
F_239 ( T_9 * V_36 , T_11 * V_38 , T_19 * V_99 )
{
T_10 V_137 ;
for ( V_137 = 0 ; V_137 < V_35 -> V_105 ; V_137 ++ ) {
F_218 ( F_236 ( V_137 ) . V_103 ,
V_36 , V_38 , V_99 , NULL ) ;
}
}
T_20
F_240 ( void )
{
T_10 V_137 ;
for ( V_137 = 0 ; V_137 < V_35 -> V_105 ; V_137 ++ ) {
if ( F_236 ( V_137 ) . V_236 != NULL &&
F_236 ( V_137 ) . V_236 -> V_105 != 0 )
return TRUE ;
}
return FALSE ;
}
void
F_241 ( T_13 * V_53 )
{
T_10 V_137 ;
if ( V_35 == NULL ) {
return;
}
for ( V_137 = 0 ; V_137 < V_35 -> V_105 ; V_137 ++ ) {
if ( F_236 ( V_137 ) . V_236 != NULL &&
F_236 ( V_137 ) . V_236 -> V_105 != 0 )
F_242 ( V_53 ,
F_236 ( V_137 ) . V_236 ) ;
}
}
